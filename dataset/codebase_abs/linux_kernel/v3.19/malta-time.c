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
T_2 V_8 = 0 , V_9 = 0 ;
#if F_6 ( V_10 ) && V_11
V_12 = V_11 * 1000000 ;
return;
#endif
F_7 ( V_5 ) ;
while ( F_8 ( V_13 ) & V_14 ) ;
while ( ! ( F_8 ( V_13 ) & V_14 ) ) ;
V_7 = F_9 () ;
if ( V_15 )
V_9 = F_10 () ;
while ( F_8 ( V_13 ) & V_14 ) ;
while ( ! ( F_8 ( V_13 ) & V_14 ) ) ;
V_6 = F_9 () ;
if ( V_15 )
V_8 = F_10 () ;
F_11 ( V_5 ) ;
V_6 -= V_7 ;
V_12 = V_6 ;
if ( V_15 ) {
V_8 -= V_9 ;
V_16 = V_8 ;
}
}
void F_12 ( struct V_17 * V_18 )
{
V_18 -> V_19 = F_13 () ;
V_18 -> V_20 = 0 ;
}
int F_14 ( void )
{
if ( V_21 ) {
F_15 ( V_22 , F_3 ) ;
V_2 = V_23 + V_22 ;
} else if ( V_15 ) {
V_2 = F_16 () ;
} else if ( V_24 >= 0 ) {
V_2 = V_25 + V_24 ;
} else {
V_2 = - 1 ;
}
return V_2 ;
}
unsigned int F_17 ( void )
{
if ( V_21 ) {
F_15 ( V_26 , F_1 ) ;
V_1 = V_23 + V_26 ;
} else if ( V_15 ) {
V_1 = F_18 () ;
} else {
V_1 = V_25 + V_27 ;
}
return V_1 ;
}
static void T_1 F_19 ( void )
{
F_20 ( V_28 | V_29 , V_30 ) ;
F_20 ( V_31 , V_32 ) ;
F_20 ( V_29 , V_30 ) ;
}
void T_1 F_21 ( void )
{
unsigned int V_33 = F_22 () & ( V_34 | V_35 ) ;
unsigned int V_3 ;
F_19 () ;
F_5 () ;
V_3 = V_12 ;
if ( ( V_33 != ( V_36 | V_37 ) ) &&
( V_33 != ( V_36 | V_38 ) ) )
V_3 *= 2 ;
V_3 = F_4 ( V_3 , 5000 ) ;
F_23 ( L_1 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
F_24 () ;
#ifdef F_25
F_26 () ;
#endif
#ifdef F_27
if ( V_15 ) {
V_3 = F_4 ( V_16 , 5000 ) ;
F_23 ( L_2 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
#ifdef F_28
F_29 ( V_16 ) ;
#endif
}
#endif
}
