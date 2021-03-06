#include <collision/EPAMinkowskiPenetrationSolver.h>
#include <collision/ExpandingSimplex.h>
#include <collision/MinkowskiSum.h>
#include <collision/Penetration.h>

using std::unique_ptr;

const int MAX_ITERATIONS = 100;

EPAMinkowskiPenetrationSolver::EPAMinkowskiPenetrationSolver()
{
}

void EPAMinkowskiPenetrationSolver::findPenetration(
        const vector<fvec2>& simplex,
        const MinkowskiSum& minkowskiSum,
        Penetration& penetration) const
{
    ExpandingSimplex expandingSimplex(simplex);
    shared_ptr<ExpandingSimplexEdge> edge;
    fvec2 point;

    for (int i = 0; i < MAX_ITERATIONS; i++)
    {
        edge = expandingSimplex.findClosestEdge();
        point = minkowskiSum.getSupportPoint(edge->getNormal());

        float projection = glm::dot(point, edge->getNormal());
        if ((projection - edge->getDistance()) < std::numeric_limits<float>::epsilon())
        {
            penetration.normal = edge->getNormal();
            penetration.depth = projection;
            return;
        }

        expandingSimplex.expand(point);
    }

    penetration.normal = edge->getNormal();
    penetration.depth = glm::dot(point, edge->getNormal());
}