class Polar
{
public:
	Polar() = default;
	Polar(float radius, float angle);
public:
	Polar operator+(const Polar& rhs);
private:
	float m_radius{};
	float m_angle{};
};
