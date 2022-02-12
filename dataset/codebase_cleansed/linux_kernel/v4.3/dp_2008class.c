int ieee754dp_2008class(union ieee754dp x)
{
COMPXDP;
EXPLODEXDP;
switch(xc) {
case IEEE754_CLASS_SNAN:
return 0x01;
case IEEE754_CLASS_QNAN:
return 0x02;
case IEEE754_CLASS_INF:
return 0x04 << (xs ? 0 : 4);
case IEEE754_CLASS_NORM:
return 0x08 << (xs ? 0 : 4);
case IEEE754_CLASS_DNORM:
return 0x10 << (xs ? 0 : 4);
case IEEE754_CLASS_ZERO:
return 0x20 << (xs ? 0 : 4);
default:
pr_err("Unknown class: %d\n", xc);
return 0;
}
}
