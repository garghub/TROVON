static int F_1 ( int V_1 , int V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
int V_5 = 0 ;
F_2 ( & V_6 ) ;
V_3 = F_3 ( V_7 + V_8 ) ;
V_4 = ( V_3 >> V_9 ) & 1 ;
if ( ( V_4 ^ V_1 ) == 0 ) {
V_3 = ( 1 << V_2 ) | V_10 ;
F_4 ( V_3 , V_7 + V_8 ) ;
V_3 = ( 2 << V_2 ) | V_10 ;
F_4 ( V_3 , V_7 + V_8 ) ;
V_5 = 1 ;
}
F_5 ( & V_6 ) ;
return V_5 ;
}
static void F_6 ( void )
{
F_1 ( V_11 ,
V_12 ) ;
}
static void F_7 ( void )
{
if ( F_1 ( V_13 ,
V_14 ) ) {
F_6 () ;
F_8 ( V_15 L_1 ) ;
}
}
static void F_9 ( void )
{
if ( F_1 ( V_11 ,
V_14 ) )
F_8 ( V_15 L_2 ) ;
}
static void F_10 ( unsigned int V_16 )
{
if ( V_16 > 0xFFFFFFFF / V_17 )
V_16 = 0xFFFFFFFF / V_17 ;
V_10 = V_16 * V_17 >> 8 ;
V_18 = V_16 ;
}
static int F_11 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
if ( F_12 ( V_21 , & V_22 ) )
return - V_23 ;
if ( V_24 )
F_13 ( V_25 ) ;
F_7 () ;
return F_14 ( V_19 , V_20 ) ;
}
static int F_15 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
if ( V_26 == 42 )
F_9 () ;
else {
F_8 ( V_27
L_3 ) ;
F_6 () ;
}
V_26 = 0 ;
F_16 ( V_21 , & V_22 ) ;
return 0 ;
}
static T_2 F_17 ( struct V_20 * V_20 , const char T_3 * V_3 ,
T_4 V_28 , T_5 * V_29 )
{
if ( V_28 ) {
if ( ! V_24 ) {
T_4 V_30 ;
V_26 = 0 ;
for ( V_30 = 0 ; V_30 != V_28 ; V_30 ++ ) {
char V_31 ;
if ( F_18 ( V_31 , V_3 + V_30 ) )
return - V_32 ;
if ( V_31 == 'V' )
V_26 = 42 ;
}
}
F_6 () ;
}
return V_28 ;
}
static long F_19 ( struct V_20 * V_20 ,
unsigned int V_33 , unsigned long V_34 )
{
int V_16 ;
int V_35 ;
void T_3 * V_36 = ( void T_3 * ) V_34 ;
static const struct V_37 V_38 = {
. V_35 = V_39 |
V_40 |
V_41 ,
. V_42 = 0 ,
. V_43 = L_4 ,
} ;
switch ( V_33 ) {
case V_44 :
if ( F_20 ( V_36 , & V_38 , sizeof( V_38 ) ) )
return - V_32 ;
break;
case V_45 :
case V_46 :
if ( F_21 ( V_47 , ( int T_3 * ) V_36 ) )
return - V_32 ;
V_47 &= ~ V_41 ;
break;
case V_48 :
return - V_49 ;
case V_50 :
if ( F_18 ( V_35 , ( int T_3 * ) V_36 ) )
return - V_32 ;
if ( V_35 & V_51 )
F_9 () ;
if ( V_35 & V_52 )
F_7 () ;
break;
case V_53 :
F_6 () ;
V_47 |= V_41 ;
break;
case V_54 :
if ( F_18 ( V_16 , ( int T_3 * ) V_36 ) )
return - V_32 ;
F_10 ( V_16 ) ;
case V_55 :
if ( F_21 ( V_18 , ( int T_3 * ) V_36 ) )
return - V_32 ;
break;
default:
return - V_56 ;
}
return 0 ;
}
static int T_6 F_22 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = V_58 -> V_58 . V_61 ;
struct V_62 * V_63 ;
int V_16 = 10 ;
V_17 = 133 ;
if ( V_60 ) {
V_16 = V_60 -> V_16 ;
V_17 = V_60 -> V_17 ;
}
V_17 ++ ;
V_17 *= 1000000 ;
V_63 = F_23 ( V_58 , V_64 , 0 ) ;
if ( ! V_63 )
return - V_65 ;
V_7 = F_24 ( V_63 -> V_66 , F_25 ( V_63 ) ) ;
if ( V_7 == NULL )
return - V_67 ;
F_10 ( V_16 ) ;
F_9 () ;
return F_26 ( & V_68 ) ;
}
static int T_7 F_27 ( struct V_57 * V_58 )
{
F_28 ( & V_68 ) ;
F_9 () ;
F_29 ( V_7 ) ;
return 0 ;
}
static int T_8 F_30 ( void )
{
F_8 ( V_69 L_5 ) ;
return F_31 ( & V_70 ) ;
}
static void T_9 F_32 ( void )
{
F_33 ( & V_70 ) ;
}
