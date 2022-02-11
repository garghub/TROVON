unsigned int F_1 ( int V_1 )
{
unsigned long V_2 , V_3 ;
unsigned int V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ;
V_2 = V_10 ;
asm( "mrc\tp14, 0, %0, c6, c0, 0" : "=r" (turbo) );
V_4 = V_11 [ ( V_2 >> 0 ) & 0x1f ] ;
V_6 = V_12 [ ( V_2 >> 5 ) & 0x03 ] ;
V_8 = V_13 [ ( V_2 >> 7 ) & 0x07 ] ;
V_5 = V_4 * V_14 ;
V_7 = V_6 * V_5 ;
V_9 = V_8 * V_7 / 2 ;
if( V_1 )
{
V_5 += 5000 ;
F_2 ( V_15 L_1 ,
V_5 / 1000000 , ( V_5 % 1000000 ) / 10000 , V_4 ) ;
V_7 += 5000 ;
F_2 ( V_15 L_2 ,
V_7 / 1000000 , ( V_7 % 1000000 ) / 10000 , V_6 ) ;
V_9 += 5000 ;
F_2 ( V_15 L_3 ,
V_9 / 1000000 , ( V_9 % 1000000 ) / 10000 , V_8 / 2 , ( V_8 % 2 ) * 5 ,
( V_3 & 1 ) ? L_4 : L_5 ) ;
}
return ( V_3 & 1 ) ? ( V_9 / 1000 ) : ( V_7 / 1000 ) ;
}
static unsigned long F_3 ( struct V_16 * V_16 )
{
return V_11 [ ( V_10 >> 0 ) & 0x1f ] * V_14 ;
}
static void F_4 ( struct V_16 * V_16 )
{
F_5 ( V_17 , 1 ) ;
}
static void F_6 ( struct V_16 * V_16 )
{
F_5 ( V_18 , 1 ) ;
}
static void F_7 ( struct V_16 * V_16 )
{
F_5 ( V_19 , 1 ) ;
}
static void F_8 ( struct V_16 * V_16 )
{
F_5 ( V_20 , 1 ) ;
}
static void F_9 ( unsigned long * V_21 )
{
F_10 ( V_22 ) ;
}
static void F_11 ( unsigned long * V_21 )
{
F_12 ( V_22 ) ;
}
static void F_13 ( T_1 V_23 )
{
V_24 = V_25 | V_26 | V_27 | V_28 ;
switch ( V_23 ) {
case V_29 :
F_14 ( V_30 , V_31 ) ;
break;
}
}
static int F_15 ( void )
{
V_32 = F_16 ( V_33 ) ;
return 0 ;
}
static void F_17 ( void )
{
V_32 = 0 ;
}
static void T_2 F_18 ( void )
{
V_34 = & V_35 ;
}
static inline void F_18 ( void ) {}
static int F_19 ( struct V_36 * V_37 , unsigned int V_38 )
{
int V_39 = F_20 ( V_37 -> V_40 ) ;
T_3 V_41 = 0 ;
if ( V_39 >= 0 && V_39 < 85 )
return F_21 ( V_39 , V_38 ) ;
if ( V_37 -> V_40 == V_42 ) {
V_41 = V_43 ;
goto V_44;
}
return - V_45 ;
V_44:
if ( V_38 )
V_46 |= V_41 ;
else
V_46 &= ~ V_41 ;
return 0 ;
}
void T_2 F_22 ( void )
{
F_23 ( 32 , F_19 ) ;
}
void T_2 F_24 ( void )
{
F_23 ( 32 , F_19 ) ;
}
void T_2 F_25 ( void )
{
F_26 () ;
F_27 ( F_28 ( V_47 ) ) ;
F_1 ( 1 ) ;
}
static int T_2 F_29 ( void )
{
int V_48 = 0 ;
if ( F_30 () ) {
V_49 = V_24 ;
F_31 ( V_50 , F_32 ( V_50 ) ) ;
if ( ( V_48 = F_33 ( V_51 , 16 ) ) )
return V_48 ;
F_18 () ;
F_34 ( & V_52 ) ;
F_34 ( & V_53 ) ;
F_34 ( & V_54 ) ;
F_35 ( & V_55 , & V_56 ) ;
V_48 = F_36 ( V_57 ,
F_32 ( V_57 ) ) ;
if ( V_48 )
return V_48 ;
}
if ( F_37 () )
F_38 ( & V_58 ) ;
return V_48 ;
}
