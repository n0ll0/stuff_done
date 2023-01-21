#include <cmath>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    double a, b, c, x1, y1, x2, y2;
    std::cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;

    // Find the closest point on the avenue to A
    double xa = (b * b * x1 - a * b * y1 - a * c) / (a * a + b * b);
    double ya = (a * a * y1 - a * b * x1 - b * c) / (a * a + b * b);

    // Find the closest point on the avenue to B
    double xb = (b * b * x2 - a * b * y2 - a * c) / (a * a + b * b);
    double yb = (a * a * y2 - a * b * x2 - b * c) / (a * a + b * b);

    // Find the distance between A and the closest point on the avenue
    double d1 = std::sqrt((xa - x1) * (xa - x1) + (ya - y1) * (ya - y1));

    // Find the distance between B and the closest point on the avenue
    double d2 = std::sqrt((xb - x2) * (xb - x2) + (yb - y2) * (yb - y2));

    // Find the distance between the two closest points on the avenue
    double d3 = std::sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));

    // Return the minimum distance
    std::cout << d1 + d2 + d3 << std::endl;

    return 0;
}
