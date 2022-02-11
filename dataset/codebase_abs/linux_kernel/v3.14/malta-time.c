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
unsigned int V_12 = F_8 () & ( V_13 | V_14 ) ;
V_6 = ( V_11 * 1000000 ) >> 3 ;
if ( ( V_12 != ( V_15 | V_16 ) ) &&
( V_12 != ( V_15 | V_17 ) ) )
V_6 *= 2 ;
V_18 = V_6 ;
return;
#endif
F_9 ( V_5 ) ;
while ( F_10 ( V_19 ) & V_20 ) ;
while ( ! ( F_10 ( V_19 ) & V_20 ) ) ;
V_7 = F_11 () ;
#ifdef F_6
if ( V_21 )
F_12 ( F_13 ( V_22 , V_23 ) , V_9 ) ;
#endif
while ( F_10 ( V_19 ) & V_20 ) ;
while ( ! ( F_10 ( V_19 ) & V_20 ) ) ;
V_6 = F_11 () ;
#ifdef F_6
if ( V_21 )
F_12 ( F_13 ( V_22 , V_23 ) , V_8 ) ;
#endif
F_14 ( V_5 ) ;
V_6 -= V_7 ;
V_18 = V_6 ;
#ifdef F_6
if ( V_21 ) {
V_8 -= V_9 ;
V_24 = V_8 ;
}
#endif
}
void F_15 ( struct V_25 * V_26 )
{
V_26 -> V_27 = F_16 () ;
V_26 -> V_28 = 0 ;
}
static void T_1 F_17 ( void )
{
#ifdef F_18
if ( V_29 ) {
F_19 ( V_30 , F_3 ) ;
V_2 = F_18 + V_30 ;
} else
#endif
if ( V_31 >= 0 ) {
if ( V_32 )
F_19 ( V_31 , F_3 ) ;
V_2 = V_33 + V_31 ;
#ifdef F_20
F_21 ( V_2 , V_34 ) ;
#endif
}
}
unsigned int F_22 ( void )
{
#ifdef F_18
if ( V_29 ) {
F_19 ( V_35 , F_1 ) ;
V_1 = F_18 + V_35 ;
} else
#endif
{
if ( V_32 )
F_19 ( V_36 , F_1 ) ;
V_1 = V_33 + V_36 ;
}
return V_1 ;
}
static void T_1 F_23 ( void )
{
F_24 ( V_37 | V_38 , V_39 ) ;
F_24 ( V_40 , V_41 ) ;
F_24 ( V_38 , V_39 ) ;
}
void T_1 F_25 ( void )
{
unsigned int V_12 = F_8 () & ( V_13 | V_14 ) ;
unsigned int V_3 ;
F_23 () ;
F_5 () ;
V_3 = V_18 ;
if ( ( V_12 != ( V_15 | V_16 ) ) &&
( V_12 != ( V_15 | V_17 ) ) )
V_3 *= 2 ;
V_3 = F_4 ( V_3 , 5000 ) ;
F_26 ( L_1 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
F_27 () ;
#ifdef F_28
F_29 () ;
#endif
#ifdef F_6
if ( V_21 ) {
V_3 = F_4 ( V_24 , 5000 ) ;
F_26 ( L_2 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
#ifdef F_30
F_31 ( V_24 ) ;
#endif
}
#endif
F_17 () ;
}
