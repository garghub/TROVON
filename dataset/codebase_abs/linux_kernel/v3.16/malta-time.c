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
#if F_7 ( V_10 ) && V_11
V_12 = V_11 * 1000000 ;
return;
#endif
F_8 ( V_5 ) ;
while ( F_9 ( V_13 ) & V_14 ) ;
while ( ! ( F_9 ( V_13 ) & V_14 ) ) ;
V_7 = F_10 () ;
#ifdef F_6
if ( V_15 )
F_11 ( F_12 ( V_16 , V_17 ) , V_9 ) ;
#endif
while ( F_9 ( V_13 ) & V_14 ) ;
while ( ! ( F_9 ( V_13 ) & V_14 ) ) ;
V_6 = F_10 () ;
#ifdef F_6
if ( V_15 )
F_11 ( F_12 ( V_16 , V_17 ) , V_8 ) ;
#endif
F_13 ( V_5 ) ;
V_6 -= V_7 ;
V_12 = V_6 ;
#ifdef F_6
if ( V_15 ) {
V_8 -= V_9 ;
V_18 = V_8 ;
}
#endif
}
void F_14 ( struct V_19 * V_20 )
{
V_20 -> V_21 = F_15 () ;
V_20 -> V_22 = 0 ;
}
static void T_1 F_16 ( void )
{
#ifdef F_17
if ( V_23 ) {
F_18 ( V_24 , F_3 ) ;
V_2 = F_17 + V_24 ;
} else
#endif
if ( V_25 >= 0 ) {
if ( V_26 )
F_18 ( V_25 , F_3 ) ;
V_2 = V_27 + V_25 ;
#ifdef F_19
F_20 ( V_2 , V_28 ) ;
#endif
}
}
unsigned int F_21 ( void )
{
#ifdef F_17
if ( V_23 ) {
F_18 ( V_29 , F_1 ) ;
V_1 = F_17 + V_29 ;
} else
#endif
{
if ( V_26 )
F_18 ( V_30 , F_1 ) ;
V_1 = V_27 + V_30 ;
}
return V_1 ;
}
static void T_1 F_22 ( void )
{
F_23 ( V_31 | V_32 , V_33 ) ;
F_23 ( V_34 , V_35 ) ;
F_23 ( V_32 , V_33 ) ;
}
void T_1 F_24 ( void )
{
unsigned int V_36 = F_25 () & ( V_37 | V_38 ) ;
unsigned int V_3 ;
F_22 () ;
F_5 () ;
V_3 = V_12 ;
if ( ( V_36 != ( V_39 | V_40 ) ) &&
( V_36 != ( V_39 | V_41 ) ) )
V_3 *= 2 ;
V_3 = F_4 ( V_3 , 5000 ) ;
F_26 ( L_1 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
F_27 () ;
#ifdef F_28
F_29 () ;
#endif
#ifdef F_6
if ( V_15 ) {
V_3 = F_4 ( V_18 , 5000 ) ;
F_26 ( L_2 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
#ifdef F_30
F_31 ( V_18 ) ;
#endif
}
#endif
F_16 () ;
}
