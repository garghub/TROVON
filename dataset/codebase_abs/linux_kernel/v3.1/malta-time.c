static void F_1 ( void )
{
F_2 ( V_1 ) ;
}
static void F_3 ( void )
{
F_2 ( V_2 ) ;
}
static unsigned int T_1 F_4 ( void )
{
unsigned int V_3 = F_5 () & 0xffff00 ;
unsigned int V_4 ;
unsigned long V_5 ;
unsigned int V_6 ;
F_6 ( V_5 ) ;
while ( F_7 ( V_7 ) & V_8 ) ;
while ( ! ( F_7 ( V_7 ) & V_8 ) ) ;
V_6 = F_8 () ;
while ( F_7 ( V_7 ) & V_8 ) ;
while ( ! ( F_7 ( V_7 ) & V_8 ) ) ;
V_4 = F_8 () - V_6 ;
F_9 ( V_5 ) ;
V_9 = V_4 ;
if ( ( V_3 != ( V_10 | V_11 ) ) &&
( V_3 != ( V_10 | V_12 ) ) )
V_4 *= 2 ;
V_4 += 5000 ;
V_4 -= V_4 % 10000 ;
return V_4 ;
}
void F_10 ( struct V_13 * V_14 )
{
V_14 -> V_15 = F_11 () ;
V_14 -> V_16 = 0 ;
}
static void T_1 F_12 ( void )
{
#ifdef F_13
if ( V_17 ) {
F_14 ( V_18 , F_3 ) ;
V_2 = F_13 + V_18 ;
} else
#endif
if ( V_19 >= 0 ) {
if ( V_20 )
F_14 ( V_19 , F_3 ) ;
V_2 = V_21 + V_19 ;
#ifdef F_15
F_16 ( V_2 , V_22 ) ;
#endif
}
}
unsigned int T_2 F_17 ( void )
{
#ifdef F_13
if ( V_17 ) {
F_14 ( V_23 , F_1 ) ;
V_1 = F_13 + V_23 ;
} else
#endif
{
if ( V_20 )
F_14 ( V_24 , F_1 ) ;
V_1 = V_21 + V_24 ;
}
return V_1 ;
}
void T_1 F_18 ( void )
{
unsigned int V_25 ;
F_19 ( F_7 ( V_26 ) | V_27 , V_26 ) ;
V_25 = F_4 () ;
F_20 ( L_1 , V_25 / 1000000 ,
( V_25 % 1000000 ) * 100 / 1000000 ) ;
V_28 = V_25 / 1000 ;
F_21 () ;
#ifdef F_22
F_23 () ;
#endif
F_12 () ;
}
