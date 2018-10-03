// PX2Random.inl

//----------------------------------------------------------------------------
inline uint32_t Random::Next(uint32_t n)
{
	return Next() % n;
}
//----------------------------------------------------------------------------
inline char Random::NextChar()
{
	return char((Next() >> 3) & 0xFF);
}
//----------------------------------------------------------------------------
inline bool Random::NextBool()
{
	return (Next() & 0x1000) != 0;
}
//----------------------------------------------------------------------------
inline float Random::NextFloat()
{
	return float(Next()) / 0x7FFFFFFF;
}
//----------------------------------------------------------------------------
inline double Random::NextDouble()
{
	return double(Next()) / 0x7FFFFFFF;
}
//----------------------------------------------------------------------------