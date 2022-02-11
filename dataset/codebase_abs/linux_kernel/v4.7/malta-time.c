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
unsigned char V_8 , V_9 , V_10 ;
int V_11 ;
T_2 V_12 = 0 , V_13 = 0 ;
#if F_6 ( V_14 ) && V_15
V_16 = V_15 * 1000000 ;
return;
#endif
F_7 ( V_5 ) ;
if ( V_17 )
F_8 () ;
while ( F_9 ( V_18 ) & V_19 ) ;
while ( ! ( F_9 ( V_18 ) & V_19 ) ) ;
V_7 = F_10 () ;
if ( V_17 )
V_13 = F_11 () ;
while ( F_9 ( V_18 ) & V_19 ) ;
V_8 = F_9 ( V_20 ) ;
while ( ! ( F_9 ( V_18 ) & V_19 ) ) ;
V_6 = F_10 () ;
if ( V_17 )
V_12 = F_11 () ;
while ( F_9 ( V_18 ) & V_19 ) ;
V_9 = F_9 ( V_20 ) ;
V_10 = F_9 ( V_21 ) ;
F_12 ( V_5 ) ;
if ( ! ( V_10 & V_22 ) || V_23 ) {
V_8 = F_13 ( V_8 ) ;
V_9 = F_13 ( V_9 ) ;
}
V_11 = V_9 - V_8 ;
if ( V_11 < 1 )
V_11 += 60 ;
V_6 -= V_7 ;
V_6 /= V_11 ;
V_16 = V_6 ;
if ( V_17 ) {
V_12 = F_14 ( V_12 - V_13 , V_11 ) ;
V_24 = V_12 ;
}
}
void F_15 ( struct V_25 * V_26 )
{
V_26 -> V_27 = F_16 () ;
V_26 -> V_28 = 0 ;
}
int F_17 ( void )
{
switch ( F_18 () ) {
case V_29 :
case V_30 :
return - 1 ;
} ;
if ( V_31 )
return - 1 ;
else if ( V_17 )
return F_19 () ;
else if ( V_32 >= 0 )
return V_33 + V_32 ;
else
return - 1 ;
}
int F_20 ( void )
{
if ( V_31 ) {
F_21 ( V_34 , F_3 ) ;
V_2 = V_35 + V_34 ;
} else if ( V_17 ) {
V_2 = F_22 () ;
} else if ( V_36 >= 0 ) {
V_2 = V_33 + V_36 ;
} else {
V_2 = - 1 ;
}
return V_2 ;
}
unsigned int F_23 ( void )
{
if ( V_31 ) {
F_21 ( V_37 , F_1 ) ;
V_1 = V_35 + V_37 ;
} else if ( V_17 ) {
V_1 = F_24 () ;
} else {
V_1 = V_33 + V_38 ;
}
return V_1 ;
}
static void T_1 F_25 ( void )
{
unsigned char V_3 , V_10 ;
V_3 = F_9 ( V_39 ) ;
if ( ( V_3 & V_40 ) != V_41 )
F_26 ( V_41 , V_39 ) ;
V_10 = F_9 ( V_21 ) ;
if ( V_10 & V_42 )
F_26 ( V_10 & ~ V_42 , V_21 ) ;
}
void T_1 F_27 ( void )
{
unsigned int V_43 = F_28 () & ( V_44 | V_45 ) ;
unsigned int V_3 ;
F_25 () ;
F_5 () ;
V_3 = V_16 ;
if ( ( V_43 != ( V_46 | V_47 ) ) &&
( V_43 != ( V_46 | V_48 ) ) )
V_3 *= 2 ;
V_3 = F_4 ( V_3 , 5000 ) ;
F_29 ( L_1 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
F_30 () ;
#ifdef F_31
F_32 () ;
#endif
#ifdef F_33
if ( V_17 ) {
V_3 = F_4 ( V_24 , 5000 ) ;
F_29 ( L_2 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
#ifdef F_34
F_35 ( V_24 ) ;
#endif
}
#endif
}
