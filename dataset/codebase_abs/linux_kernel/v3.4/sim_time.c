static unsigned int T_1 F_1 ( void )
{
unsigned int V_1 = F_2 () & 0xffff00 ;
unsigned int V_2 ;
#if 1
if ( ( V_1 == ( V_3 | V_4 ) ) ||
( V_1 == ( V_3 | V_5 ) ) )
V_2 = 12000000 ;
else
V_2 = 6000000 ;
#else
unsigned int V_6 ;
F_3 ( V_6 ) ;
while ( F_4 ( V_7 ) & V_8 ) ;
while ( ! ( F_4 ( V_7 ) & V_8 ) ) ;
F_5 ( 0 ) ;
while ( F_4 ( V_7 ) & V_8 ) ;
while ( ! ( F_4 ( V_7 ) & V_8 ) ) ;
V_2 = F_6 () ;
F_7 ( V_6 ) ;
#endif
V_9 = V_2 ;
if ( ( V_1 != ( V_3 | V_4 ) ) &&
( V_1 != ( V_3 | V_5 ) ) )
V_2 *= 2 ;
V_2 += 5000 ;
V_2 -= V_2 % 10000 ;
return V_2 ;
}
static void F_8 ( void )
{
F_9 ( V_10 ) ;
}
unsigned T_2 F_10 ( void )
{
#ifdef F_11
if ( V_11 ) {
F_12 ( V_12 , F_8 ) ;
V_10 = F_11 + V_12 ;
return V_10 ;
}
#endif
if ( V_13 )
F_12 ( V_14 , F_8 ) ;
V_10 = V_15 + V_14 ;
return V_10 ;
}
void T_1 F_13 ( void )
{
unsigned int V_16 ;
F_14 ( F_4 ( V_17 ) | V_18 , V_17 ) ;
V_16 = F_1 () ;
F_15 ( V_19 L_1 , V_16 / 1000000 ,
( V_16 % 1000000 ) * 100 / 1000000 ) ;
V_20 = V_16 / 1000 ;
}
