#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Ñòðóêòóðà äëÿ õðàíåíèÿ êîîðäèíàò òî÷êè
struct Point {
    double x, y;
};

// Ôóíêöèÿ äëÿ ïðîâåðêè ïðèíàäëåæíîñòè òî÷êè ãèïåðáîëå
bool isPointOnHyperbola(double a, double b, const Point& point) {
    double x = point.x;
    double y = point.y;
    return (x * x) / (a * a) - (y * y) / (b * b) == 1;
}

// Ôóíêöèÿ äëÿ ãåíåðàöèè ñëó÷àéíîãî ÷èñëà â äèàïàçîíå [min, max]
double randomDouble(double min, double max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // Ïàðàìåòðû ãèïåðáîëû
    double a = randomDouble(1.0, 10.0); // Äëèíà äåéñòâèòåëüíîé ïîëóîñè
    double b = randomDouble(1.0, 10.0); // Äëèíà ìíèìîé ïîëóîñè

    // Ñëó÷àéíàÿ òî÷êà
    Point point = {randomDouble(-20.0, 20.0), randomDouble(-20.0, 20.0)};

    std::cout << "Óðàâíåíèå ãèïåðáîëû: (x^2 / " << a << "^2) - (y^2 / " << b << "^2) = 1" << std::endl;
    std::cout << "Ñëó÷àéíàÿ òî÷êà: (" << point.x << ", " << point.y << ")" << std::endl;

    // Ïðîâåðêà ïðèíàäëåæíîñòè òî÷êè ãèïåðáîëå
    bool onHyperbola = isPointOnHyperbola(a, b, point);
    std::cout << "Ïðèíàäëåæèò ëè òî÷êà ïàðàáîëëå? " << (onHyperbola ? "Yes" : "No") << std::endl;

    // Êîîðäèíàòû ôîêóñîâ ãèïåðáîëû
    double c = sqrt(a * a + b * b);
    std::cout << "Ôîêóñ ãèïåðáîëû: (" << c << ", 0) and (" << -c << ", 0)" << std::endl;

    
    // Äëèíû äåéñòâèòåëüíîé è ìíèìîé ïîëóîñåé
    std::cout << "Äëèíà äåéñòâèòåëüíîé ïîëóîñè: " << a << std::endl;
    std::cout << "Äëèíà ìíèìîé ïîëóîñè: " << b << std::endl;

    // Ýêñöåíòðèñèòåò ãèïåðáîëû
    double eccentricity = c / a;
    std::cout << "Ýêñöåíòðèñèòåò ãèïåðáîëû: " << eccentricity << std::endl;

    // Ðàññòîÿíèå ìåæäó äèðåêòðèñàìè ãèïåðáîëû
    double distanceBetweenDirectrices = 2 * a / sqrt(a * a + b * b);
    std::cout << "Ðàññòîÿíèå ìåæäó äèðåêòðèñàìè ãèïåðáîëû: " << distanceBetweenDirectrices << std::endl;

    return 0;
}
