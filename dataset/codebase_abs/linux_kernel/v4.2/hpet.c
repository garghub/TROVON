static unsigned int F_1 ( int V_1 )
{
return * ( volatile unsigned int * ) ( V_2 + V_1 ) ;
}
static void F_2 ( int V_1 , int V_3 )
{
* ( volatile unsigned int * ) ( V_2 + V_1 ) = V_3 ;
}
static void F_3 ( int V_1 , int V_4 )
{
unsigned int V_5 = F_1 ( V_1 ) ;
V_5 |= V_4 ;
F_2 ( V_1 , V_5 ) ;
}
static int F_4 ( int V_1 )
{
return * ( volatile unsigned int * ) ( V_6 + V_1 ) ;
}
static void F_5 ( int V_1 , int V_3 )
{
* ( volatile unsigned int * ) ( V_6 + V_1 ) = V_3 ;
}
static void F_6 ( void )
{
unsigned int V_5 = F_4 ( V_7 ) ;
V_5 |= V_8 ;
F_5 ( V_7 , V_5 ) ;
}
static void F_7 ( void )
{
unsigned int V_5 = F_4 ( V_7 ) ;
V_5 &= ~ V_8 ;
F_5 ( V_7 , V_5 ) ;
}
static void F_8 ( void )
{
F_5 ( V_9 , 0 ) ;
F_5 ( V_9 + 4 , 0 ) ;
}
static void F_9 ( void )
{
F_7 () ;
F_8 () ;
F_6 () ;
}
static void F_10 ( void )
{
}
static void F_11 ( enum V_10 V_11 ,
struct V_12 * V_13 )
{
int V_5 = 0 ;
F_12 ( & V_14 ) ;
switch ( V_11 ) {
case V_15 :
F_13 ( L_1 ) ;
F_7 () ;
V_5 = F_4 ( V_16 ) ;
V_5 &= ~ V_17 ;
V_5 |= V_18 | V_19 |
V_20 | V_21 ;
F_5 ( V_16 , V_5 ) ;
F_5 ( V_22 , V_23 ) ;
F_14 ( 1 ) ;
F_5 ( V_22 , V_23 ) ;
F_6 () ;
break;
case V_24 :
case V_25 :
V_5 = F_4 ( V_16 ) ;
V_5 &= ~ V_18 ;
F_5 ( V_16 , V_5 ) ;
break;
case V_26 :
F_13 ( L_2 ) ;
V_5 = F_4 ( V_16 ) ;
V_5 &= ~ V_19 ;
V_5 |= V_18 | V_21 ;
F_5 ( V_16 , V_5 ) ;
break;
case V_27 :
F_10 () ;
break;
}
F_15 ( & V_14 ) ;
}
static int F_16 ( unsigned long V_28 ,
struct V_12 * V_13 )
{
unsigned int V_29 ;
int V_30 ;
V_29 = F_4 ( V_9 ) ;
V_29 += V_28 ;
F_5 ( V_22 , V_29 ) ;
V_30 = ( ( int ) ( F_4 ( V_9 ) - V_29 ) > 0 ) ? - V_31 : 0 ;
return V_30 ;
}
static T_1 F_17 ( int V_32 , void * V_3 )
{
int V_33 ;
struct V_12 * V_34 ;
unsigned int V_35 = F_18 () ;
V_33 = F_4 ( V_36 ) ;
if ( V_33 & V_37 ) {
F_5 ( V_36 , V_37 ) ;
V_34 = & F_19 ( V_38 , V_35 ) ;
V_34 -> V_39 ( V_34 ) ;
return V_40 ;
}
return V_41 ;
}
static void F_20 ( void )
{
F_2 ( V_42 , V_43 ) ;
F_3 ( V_44 , ( 1 << 28 ) ) ;
F_3 ( V_45 , ( 1 << 10 ) ) ;
F_10 () ;
}
void T_2 F_21 ( void )
{
unsigned int V_35 = F_18 () ;
struct V_12 * V_34 ;
F_20 () ;
V_34 = & F_19 ( V_38 , V_35 ) ;
V_34 -> V_46 = L_3 ;
V_34 -> V_47 = 320 ;
V_34 -> V_48 = V_49 | V_50 ;
V_34 -> V_51 = F_11 ;
V_34 -> V_52 = F_16 ;
V_34 -> V_32 = V_53 ;
V_34 -> V_54 = F_22 ( V_35 ) ;
F_23 ( V_34 , V_55 ) ;
V_34 -> V_56 = F_24 ( 0x7fffffff , V_34 ) ;
V_34 -> V_57 = 5000 ;
F_25 ( V_34 ) ;
F_26 ( V_53 , & V_58 ) ;
F_13 ( L_4 ) ;
}
static T_3 F_27 ( struct V_59 * V_60 )
{
return ( T_3 ) F_4 ( V_9 ) ;
}
static void F_28 ( struct V_59 * V_60 )
{
}
static void F_29 ( struct V_59 * V_60 )
{
F_20 () ;
F_9 () ;
}
int T_2 F_30 ( void )
{
V_61 . V_62 = F_31 ( V_55 , V_61 . V_63 ) ;
return F_32 ( & V_61 , V_55 ) ;
}
