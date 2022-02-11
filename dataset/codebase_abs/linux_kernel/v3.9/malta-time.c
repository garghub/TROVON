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
unsigned int V_8 = 0 , V_9 = 0 ;
F_6 ( V_5 ) ;
while ( F_7 ( V_10 ) & V_11 ) ;
while ( ! ( F_7 ( V_10 ) & V_11 ) ) ;
V_7 = F_8 () ;
if ( V_12 )
F_9 ( F_10 ( V_13 , V_14 ) , V_9 ) ;
while ( F_7 ( V_10 ) & V_11 ) ;
while ( ! ( F_7 ( V_10 ) & V_11 ) ) ;
V_6 = F_8 () ;
if ( V_12 )
F_9 ( F_10 ( V_13 , V_14 ) , V_8 ) ;
F_11 ( V_5 ) ;
V_6 -= V_7 ;
if ( V_12 )
V_8 -= V_9 ;
V_15 = V_6 ;
if ( V_12 )
V_16 = V_8 ;
}
void F_12 ( struct V_17 * V_18 )
{
V_18 -> V_19 = F_13 () ;
V_18 -> V_20 = 0 ;
}
static void T_1 F_14 ( void )
{
#ifdef F_15
if ( V_21 ) {
F_16 ( V_22 , F_3 ) ;
V_2 = F_15 + V_22 ;
} else
#endif
if ( V_23 >= 0 ) {
if ( V_24 )
F_16 ( V_23 , F_3 ) ;
V_2 = V_25 + V_23 ;
#ifdef F_17
F_18 ( V_2 , V_26 ) ;
#endif
}
}
unsigned int T_2 F_19 ( void )
{
#ifdef F_15
if ( V_21 ) {
F_16 ( V_27 , F_1 ) ;
V_1 = F_15 + V_27 ;
} else
#endif
{
if ( V_24 )
F_16 ( V_28 , F_1 ) ;
V_1 = V_25 + V_28 ;
}
return V_1 ;
}
void T_1 F_20 ( void )
{
unsigned int V_29 = F_21 () & 0xffff00 ;
unsigned int V_3 ;
F_5 () ;
V_3 = V_15 ;
if ( ( V_29 != ( V_30 | V_31 ) ) &&
( V_29 != ( V_30 | V_32 ) ) )
V_3 *= 2 ;
V_3 = F_4 ( V_3 , 5000 ) ;
F_22 ( L_1 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
V_33 = V_3 / 1000 ;
if ( V_12 ) {
V_3 = F_4 ( V_16 , 5000 ) ;
F_22 ( L_2 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
F_23 ( V_16 ) ;
} else
F_24 () ;
#ifdef F_25
F_26 () ;
#endif
F_27 () ;
F_14 () ;
}
