static int F_1 ( int V_1 , int V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
int V_5 = 0 ;
F_2 ( & V_6 ) ;
V_3 = F_3 ( V_7 ) ;
V_4 = ( V_3 >> V_8 ) & 1 ;
if ( ( V_4 ^ V_1 ) == 0 ) {
V_3 = ( 1 << V_2 ) | V_9 ;
F_4 ( V_3 , V_7 ) ;
V_3 = ( 2 << V_2 ) | V_9 ;
F_4 ( V_3 , V_7 ) ;
V_5 = 1 ;
}
F_5 ( & V_6 ) ;
return V_5 ;
}
static void F_6 ( void )
{
F_1 ( V_10 ,
V_11 ) ;
}
static void F_7 ( void )
{
if ( F_1 ( V_12 ,
V_13 ) ) {
F_6 () ;
F_8 ( V_14 L_1 ) ;
}
}
static void F_9 ( void )
{
if ( F_1 ( V_10 ,
V_13 ) )
F_8 ( V_14 L_2 ) ;
}
static void F_10 ( unsigned int V_15 )
{
if ( V_15 > 0xFFFFFFFF / V_16 )
V_15 = 0xFFFFFFFF / V_16 ;
V_9 = ( V_15 * V_16 ) >> 8 ;
V_17 = V_15 ;
}
static T_2 F_11 ( struct V_18 * V_18 , const char T_3 * V_3 ,
T_4 V_19 , T_5 * V_20 )
{
if ( V_19 ) {
if ( ! V_21 ) {
T_4 V_22 ;
V_23 = 0 ;
for ( V_22 = 0 ; V_22 != V_19 ; V_22 ++ ) {
char V_24 ;
if ( F_12 ( V_24 , V_3 + V_22 ) )
return - V_25 ;
if ( V_24 == 'V' )
V_23 = 42 ;
}
}
F_6 () ;
}
return V_19 ;
}
static long F_13 ( struct V_18 * V_18 , unsigned int V_26 ,
unsigned long V_27 )
{
int V_15 ;
int V_28 ;
void T_3 * V_29 = ( void T_3 * ) V_27 ;
static const struct V_30 V_31 = {
. V_28 = V_32 | V_33 |
V_34 ,
. V_35 = 0 ,
. V_36 = L_3 ,
} ;
switch ( V_26 ) {
case V_37 :
if ( F_14 ( V_29 , & V_31 , sizeof( V_31 ) ) )
return - V_25 ;
break;
case V_38 :
case V_39 :
if ( F_15 ( V_40 , ( int T_3 * ) V_29 ) )
return - V_25 ;
V_40 &= ~ V_34 ;
break;
case V_41 :
if ( F_12 ( V_28 , ( int T_3 * ) V_29 ) )
return - V_25 ;
if ( V_28 & V_42 )
F_9 () ;
if ( V_28 & V_43 )
F_7 () ;
break;
case V_44 :
F_6 () ;
V_40 |= V_34 ;
break;
case V_45 :
if ( F_12 ( V_15 , ( int T_3 * ) V_29 ) )
return - V_25 ;
F_10 ( V_15 ) ;
case V_46 :
if ( F_15 ( V_17 , ( int T_3 * ) V_29 ) )
return - V_25 ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_16 ( struct V_48 * V_48 , struct V_18 * V_18 )
{
if ( F_17 ( V_49 , & V_50 ) )
return - V_51 ;
if ( V_21 )
F_18 ( V_52 ) ;
F_7 () ;
return F_19 ( V_48 , V_18 ) ;
}
static int F_20 ( struct V_48 * V_48 , struct V_18 * V_18 )
{
if ( V_23 == 42 )
F_9 () ;
else {
F_8 ( V_53
L_4 ) ;
F_6 () ;
}
V_23 = 0 ;
F_21 ( V_49 , & V_50 ) ;
return 0 ;
}
static int T_6 F_22 ( struct V_54 * V_55 )
{
int V_15 = 10 ;
T_1 V_56 ;
V_16 = 133 ;
V_56 = F_23 () ;
if ( V_56 != - 1 )
V_16 = V_56 ;
V_7 = F_24 ( V_55 -> V_55 . V_57 , 0 ) ;
if ( V_7 == NULL )
return - V_58 ;
F_10 ( V_15 ) ;
F_9 () ;
return F_25 ( & V_59 ) ;
}
static int T_7 F_26 ( struct V_54 * V_55 )
{
F_27 ( & V_59 ) ;
F_9 () ;
F_28 ( V_7 ) ;
return 0 ;
}
static int T_8 F_29 ( void )
{
F_8 ( V_60 L_5 ) ;
return F_30 ( & V_61 ) ;
}
static void T_9 F_31 ( void )
{
F_32 ( & V_61 ) ;
}
