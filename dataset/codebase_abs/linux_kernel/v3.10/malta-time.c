static void F_1 ( void )
{
F_2 ( V_1 ) ;
}
static void F_3 ( void )
{
F_2 ( V_2 ) ;
}
static unsigned int F_4 ( unsigned int V_3 , unsigned int V_4 )
{
V_3 += V_4 ;
V_3 -= V_3 % ( V_4 * 2 ) ;
return V_3 ;
}
static void T_1 F_5 ( void )
{
unsigned long V_5 ;
unsigned int V_6 , V_7 ;
#ifdef F_6
unsigned int V_8 = 0 , V_9 = 0 ;
#endif
#if F_7 ( V_10 ) && F_7 ( V_11 )
unsigned int V_12 = F_8 () & 0xffff00 ;
V_6 = ( V_11 * 1000000 ) >> 3 ;
if ( ( V_12 != ( V_13 | V_14 ) ) &&
( V_12 != ( V_13 | V_15 ) ) )
V_6 *= 2 ;
V_16 = V_6 ;
return;
#endif
F_9 ( V_5 ) ;
while ( F_10 ( V_17 ) & V_18 ) ;
while ( ! ( F_10 ( V_17 ) & V_18 ) ) ;
V_7 = F_11 () ;
#ifdef F_6
if ( V_19 )
F_12 ( F_13 ( V_20 , V_21 ) , V_9 ) ;
#endif
while ( F_10 ( V_17 ) & V_18 ) ;
while ( ! ( F_10 ( V_17 ) & V_18 ) ) ;
V_6 = F_11 () ;
#ifdef F_6
if ( V_19 )
F_12 ( F_13 ( V_20 , V_21 ) , V_8 ) ;
#endif
F_14 ( V_5 ) ;
V_6 -= V_7 ;
V_16 = V_6 ;
#ifdef F_6
if ( V_19 ) {
V_8 -= V_9 ;
V_22 = V_8 ;
}
#endif
}
void F_15 ( struct V_23 * V_24 )
{
V_24 -> V_25 = F_16 () ;
V_24 -> V_26 = 0 ;
}
static void T_1 F_17 ( void )
{
#ifdef F_18
if ( V_27 ) {
F_19 ( V_28 , F_3 ) ;
V_2 = F_18 + V_28 ;
} else
#endif
if ( V_29 >= 0 ) {
if ( V_30 )
F_19 ( V_29 , F_3 ) ;
V_2 = V_31 + V_29 ;
#ifdef F_20
F_21 ( V_2 , V_32 ) ;
#endif
}
}
unsigned int T_2 F_22 ( void )
{
#ifdef F_18
if ( V_27 ) {
F_19 ( V_33 , F_1 ) ;
V_1 = F_18 + V_33 ;
} else
#endif
{
if ( V_30 )
F_19 ( V_34 , F_1 ) ;
V_1 = V_31 + V_34 ;
}
return V_1 ;
}
void T_1 F_23 ( void )
{
unsigned int V_12 = F_8 () & 0xffff00 ;
unsigned int V_3 ;
F_5 () ;
V_3 = V_16 ;
if ( ( V_12 != ( V_13 | V_14 ) ) &&
( V_12 != ( V_13 | V_15 ) ) )
V_3 *= 2 ;
V_3 = F_4 ( V_3 , 5000 ) ;
F_24 ( L_1 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
V_35 = V_3 / 1000 ;
F_25 () ;
#ifdef F_26
F_27 () ;
#endif
#ifdef F_6
if ( V_19 ) {
V_3 = F_4 ( V_22 , 5000 ) ;
F_24 ( L_2 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
#ifdef F_28
F_29 ( V_22 ) ;
#endif
}
#endif
F_17 () ;
}
