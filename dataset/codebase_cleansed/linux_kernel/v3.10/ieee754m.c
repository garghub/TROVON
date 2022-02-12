ieee754dp ieee754dp_floor(ieee754dp x)
{
ieee754dp i;
if (ieee754dp_lt(ieee754dp_modf(x, &i), ieee754dp_zero(0)))
return ieee754dp_sub(i, ieee754dp_one(0));
else
return i;
}
ieee754dp ieee754dp_ceil(ieee754dp x)
{
ieee754dp i;
if (ieee754dp_gt(ieee754dp_modf(x, &i), ieee754dp_zero(0)))
return ieee754dp_add(i, ieee754dp_one(0));
else
return i;
}
ieee754dp ieee754dp_trunc(ieee754dp x)
{
ieee754dp i;
(void) ieee754dp_modf(x, &i);
return i;
}
