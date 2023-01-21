#include <cmath>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    double a, b, c, x1, y1, x2, y2;
    std::cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;

    double xa = x1, ya = y1;
    double eps = 1e-9;
    if (std::abs(a * xa + b * ya + c) > eps)
    {
        double grad_x = 2 * a * (a * xa + b * ya + c);
        double grad_y = 2 * b * (a * xa + b * ya + c);
        while (std::abs(grad_x) > eps || std::abs(grad_y) > eps)
        {
            xa -= grad_x;
            ya -= grad_y;
            grad_x = 2 * a * (a * xa + b * ya + c);
            grad_y = 2 * b * (a * xa + b * ya + c);
        }
    }

    double xb = x2, yb = y2;
    if (std::abs(a * xb + b * yb + c) > eps)
    {
        double grad_x = 2 * a * (a * xb + b * yb + c);
        double grad_y = 2 * b * (a * xb + b * yb + c);
        while (std::abs(grad_x) > eps || std::abs(grad_y) > eps)
        {
            xb -= grad_x;
            yb -= grad_y;
            grad_x = 2 * a * (a * xb + b * yb + c);
            grad_y = 2 * b * (a * xb + b * yb + c);
        }
    }

    // Find the distance between A and the closest point on the avenue
    double d1 = std::sqrt((xa - x1) * (xa - x1) + (ya - y1) * (ya - y1));

    // Find the distance between B and the closest point on the avenue
    double d2 = std::sqrt((xb - x2) * (xb - x2) + (yb - y2) * (yb - y2));

    // Find the distance between the twoclosest points on the avenue
    double d3 = std::sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    // Return the minimum distance
    std::cout << d1 + d2 + d3 << std::endl;

    return 0;
}