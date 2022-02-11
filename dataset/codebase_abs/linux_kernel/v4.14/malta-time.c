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
if ( F_8 () )
F_9 ( V_17 ) ;
while ( F_10 ( V_18 ) & V_19 ) ;
while ( ! ( F_10 ( V_18 ) & V_19 ) ) ;
V_7 = F_11 () ;
if ( F_8 () )
V_13 = F_12 () ;
while ( F_10 ( V_18 ) & V_19 ) ;
V_8 = F_10 ( V_20 ) ;
while ( ! ( F_10 ( V_18 ) & V_19 ) ) ;
V_6 = F_11 () ;
if ( F_8 () )
V_12 = F_12 () ;
while ( F_10 ( V_18 ) & V_19 ) ;
V_9 = F_10 ( V_20 ) ;
V_10 = F_10 ( V_21 ) ;
F_13 ( V_5 ) ;
if ( ! ( V_10 & V_22 ) || V_23 ) {
V_8 = F_14 ( V_8 ) ;
V_9 = F_14 ( V_9 ) ;
}
V_11 = V_9 - V_8 ;
if ( V_11 < 1 )
V_11 += 60 ;
V_6 -= V_7 ;
V_6 /= V_11 ;
V_16 = V_6 ;
if ( F_8 () ) {
V_12 = F_15 ( V_12 - V_13 , V_11 ) ;
V_24 = V_12 ;
}
}
void F_16 ( struct V_25 * V_26 )
{
V_26 -> V_27 = F_17 () ;
V_26 -> V_28 = 0 ;
}
int F_18 ( void )
{
switch ( F_19 () ) {
case V_29 :
case V_30 :
return - 1 ;
} ;
if ( V_31 )
return - 1 ;
else if ( F_8 () )
return F_20 () ;
else if ( V_32 >= 0 )
return V_33 + V_32 ;
else
return - 1 ;
}
int F_21 ( void )
{
if ( V_31 ) {
F_22 ( V_34 , F_3 ) ;
V_2 = V_35 + V_34 ;
} else if ( F_8 () ) {
V_2 = F_23 () ;
} else if ( V_36 >= 0 ) {
V_2 = V_33 + V_36 ;
} else {
V_2 = - 1 ;
}
return V_2 ;
}
unsigned int F_24 ( void )
{
if ( V_31 ) {
F_22 ( V_37 , F_1 ) ;
V_1 = V_35 + V_37 ;
} else if ( F_8 () ) {
V_1 = F_25 () ;
} else {
V_1 = V_33 + V_38 ;
}
return V_1 ;
}
static void T_1 F_26 ( void )
{
unsigned char V_3 , V_10 ;
V_3 = F_10 ( V_39 ) ;
if ( ( V_3 & V_40 ) != V_41 )
F_27 ( V_41 , V_39 ) ;
V_10 = F_10 ( V_21 ) ;
if ( V_10 & V_42 )
F_27 ( V_10 & ~ V_42 , V_21 ) ;
}
static void F_28 ( void )
{
struct V_43 * V_44 ;
V_45 = F_29 ( V_24 ) ;
V_44 = F_30 ( NULL , NULL , L_1 ) ;
if ( ! V_44 ) {
F_31 ( L_2 ) ;
return;
}
if ( F_32 ( V_44 , & V_46 ) < 0 )
F_31 ( L_3 ) ;
}
void T_1 F_33 ( void )
{
unsigned int V_47 = F_34 () & ( V_48 | V_49 ) ;
unsigned int V_3 ;
F_26 () ;
F_5 () ;
V_3 = V_16 ;
if ( ( V_47 != ( V_50 | V_51 ) ) &&
( V_47 != ( V_50 | V_52 ) ) )
V_3 *= 2 ;
V_3 = F_4 ( V_3 , 5000 ) ;
F_35 ( L_4 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
F_36 () ;
#ifdef F_37
F_38 () ;
#endif
if ( F_8 () ) {
V_3 = F_4 ( V_24 , 5000 ) ;
F_35 ( L_5 , V_3 / 1000000 ,
( V_3 % 1000000 ) * 100 / 1000000 ) ;
#ifdef F_39
F_28 () ;
F_40 () ;
#endif
}
}
