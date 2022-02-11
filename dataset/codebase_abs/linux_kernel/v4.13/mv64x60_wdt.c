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
F_8 ( L_1 ) ;
}
}
static void F_9 ( void )
{
if ( F_1 ( V_11 ,
V_14 ) )
F_8 ( L_2 ) ;
}
static void F_10 ( unsigned int V_15 )
{
if ( V_15 > 0xFFFFFFFF / V_16 )
V_15 = 0xFFFFFFFF / V_16 ;
V_10 = V_15 * V_16 >> 8 ;
V_17 = V_15 ;
}
static int F_11 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
if ( F_12 ( V_20 , & V_21 ) )
return - V_22 ;
if ( V_23 )
F_13 ( V_24 ) ;
F_7 () ;
return F_14 ( V_18 , V_19 ) ;
}
static int F_15 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
if ( V_25 == 42 )
F_9 () ;
else {
F_16 ( L_3 ) ;
F_6 () ;
}
V_25 = 0 ;
F_17 ( V_20 , & V_21 ) ;
return 0 ;
}
static T_2 F_18 ( struct V_19 * V_19 , const char T_3 * V_3 ,
T_4 V_26 , T_5 * V_27 )
{
if ( V_26 ) {
if ( ! V_23 ) {
T_4 V_28 ;
V_25 = 0 ;
for ( V_28 = 0 ; V_28 != V_26 ; V_28 ++ ) {
char V_29 ;
if ( F_19 ( V_29 , V_3 + V_28 ) )
return - V_30 ;
if ( V_29 == 'V' )
V_25 = 42 ;
}
}
F_6 () ;
}
return V_26 ;
}
static long F_20 ( struct V_19 * V_19 ,
unsigned int V_31 , unsigned long V_32 )
{
int V_15 ;
int V_33 ;
void T_3 * V_34 = ( void T_3 * ) V_32 ;
static const struct V_35 V_36 = {
. V_33 = V_37 |
V_38 |
V_39 ,
. V_40 = 0 ,
. V_41 = L_4 ,
} ;
switch ( V_31 ) {
case V_42 :
if ( F_21 ( V_34 , & V_36 , sizeof( V_36 ) ) )
return - V_30 ;
break;
case V_43 :
case V_44 :
if ( F_22 ( V_45 , ( int T_3 * ) V_34 ) )
return - V_30 ;
V_45 &= ~ V_39 ;
break;
case V_46 :
return - V_47 ;
case V_48 :
if ( F_19 ( V_33 , ( int T_3 * ) V_34 ) )
return - V_30 ;
if ( V_33 & V_49 )
F_9 () ;
if ( V_33 & V_50 )
F_7 () ;
break;
case V_51 :
F_6 () ;
V_45 |= V_39 ;
break;
case V_52 :
if ( F_19 ( V_15 , ( int T_3 * ) V_34 ) )
return - V_30 ;
F_10 ( V_15 ) ;
case V_53 :
if ( F_22 ( V_17 , ( int T_3 * ) V_34 ) )
return - V_30 ;
break;
default:
return - V_54 ;
}
return 0 ;
}
static int F_23 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_24 ( & V_56 -> V_56 ) ;
struct V_59 * V_60 ;
int V_15 = 10 ;
V_16 = 133 ;
if ( V_58 ) {
V_15 = V_58 -> V_15 ;
V_16 = V_58 -> V_16 ;
}
V_16 ++ ;
V_16 *= 1000000 ;
V_60 = F_25 ( V_56 , V_61 , 0 ) ;
if ( ! V_60 )
return - V_62 ;
V_7 = F_26 ( & V_56 -> V_56 , V_60 -> V_63 , F_27 ( V_60 ) ) ;
if ( V_7 == NULL )
return - V_64 ;
F_10 ( V_15 ) ;
F_9 () ;
return F_28 ( & V_65 ) ;
}
static int F_29 ( struct V_55 * V_56 )
{
F_30 ( & V_65 ) ;
F_9 () ;
return 0 ;
}
static int T_6 F_31 ( void )
{
F_32 ( L_5 ) ;
return F_33 ( & V_66 ) ;
}
static void T_7 F_34 ( void )
{
F_35 ( & V_66 ) ;
}
