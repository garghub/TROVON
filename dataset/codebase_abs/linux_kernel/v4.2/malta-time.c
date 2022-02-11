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
if ( V_15 ) {
F_10 () ;
V_9 = F_11 () ;
}
while ( F_8 ( V_13 ) & V_14 ) ;
while ( ! ( F_8 ( V_13 ) & V_14 ) ) ;
V_6 = F_9 () ;
if ( V_15 )
V_8 = F_11 () ;
F_12 ( V_5 ) ;
V_6 -= V_7 ;
V_12 = V_6 ;
if ( V_15 ) {
V_8 -= V_9 ;
V_16 = V_8 ;
}
}
void F_13 ( struct V_17 * V_18 )
{
V_18 -> V_19 = F_14 () ;
V_18 -> V_20 = 0 ;
}
int F_15 ( void )
{
switch ( F_16 () ) {
case V_21 :
case V_22 :
return - 1 ;
} ;
if ( V_23 )
return - 1 ;
else if ( V_15 )
return F_17 () ;
else if ( V_24 >= 0 )
return V_25 + V_24 ;
else
return - 1 ;
}
int F_18 ( void )
{
if ( V_23 ) {
F_19 ( V_26 , F_3 ) ;
V_2 = V_27 + V_26 ;
} else if ( V_15 ) {
V_2 = F_20 () ;
} else if ( V_28 >= 0 ) {
V_2 = V_25 + V_28 ;
} else {
V_2 = - 1 ;
}
return V_2 ;
}
unsigned int F_21 ( void )
{
if ( V_23 ) {
F_19 ( V_29 , F_1 ) ;
V_1 = V_27 + V_29 ;
} else if ( V_15 ) {
V_1 = F_22 () ;
} else {
V_1 = V_25 + V_30 ;
}
return V_1 ;
}
static void T_1 F_23 ( void )
{
unsigned char V_3 , V_31 ;
V_3 = F_8 ( V_32 ) ;
if ( ( V_3 & V_33 ) != V_34 )
F_24 ( V_34 , V_32 ) ;
V_31 = F_8 ( V_35 ) ;
if ( V_31 & V_36 )
F_24 ( V_31 & ~ V_36 , V_35 ) ;
}
void T_1 F_25 ( void )
{
unsigned int V_37 = F_26 () & ( V_38 | V_39 ) ;
unsigned int V_3 ;
F_23 () ;
F_5 () ;
V_3 = V_12 ;
if ( ( V_37 != ( V_40 | V_41 ) ) &&
( V_37 != ( V_40 | V_42 ) ) )
V_3 *= 2 ;
V_3 = F_4 ( V_3 , 5000 ) ;
F_27 ( L_1 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
F_28 () ;
#ifdef F_29
F_30 () ;
#endif
#ifdef F_31
if ( V_15 ) {
V_3 = F_4 ( V_16 , 5000 ) ;
F_27 ( L_2 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
#ifdef F_32
F_33 ( V_16 ) ;
#endif
}
#endif
}
