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
F_8 ( L_1 ) ;
}
}
static void F_9 ( void )
{
if ( F_1 ( V_10 ,
V_13 ) )
F_8 ( L_2 ) ;
}
static void F_10 ( unsigned int V_14 )
{
if ( V_14 > 0xFFFFFFFF / V_15 )
V_14 = 0xFFFFFFFF / V_15 ;
V_9 = ( V_14 * V_15 ) >> 8 ;
V_16 = V_14 ;
}
static T_2 F_11 ( struct V_17 * V_17 , const char T_3 * V_3 ,
T_4 V_18 , T_5 * V_19 )
{
if ( V_18 ) {
if ( ! V_20 ) {
T_4 V_21 ;
V_22 = 0 ;
for ( V_21 = 0 ; V_21 != V_18 ; V_21 ++ ) {
char V_23 ;
if ( F_12 ( V_23 , V_3 + V_21 ) )
return - V_24 ;
if ( V_23 == 'V' )
V_22 = 42 ;
}
}
F_6 () ;
}
return V_18 ;
}
static long F_13 ( struct V_17 * V_17 , unsigned int V_25 ,
unsigned long V_26 )
{
int V_14 ;
int V_27 ;
void T_3 * V_28 = ( void T_3 * ) V_26 ;
static const struct V_29 V_30 = {
. V_27 = V_31 | V_32 |
V_33 ,
. V_34 = 0 ,
. V_35 = L_3 ,
} ;
switch ( V_25 ) {
case V_36 :
if ( F_14 ( V_28 , & V_30 , sizeof( V_30 ) ) )
return - V_24 ;
break;
case V_37 :
case V_38 :
if ( F_15 ( V_39 , ( int T_3 * ) V_28 ) )
return - V_24 ;
V_39 &= ~ V_33 ;
break;
case V_40 :
if ( F_12 ( V_27 , ( int T_3 * ) V_28 ) )
return - V_24 ;
if ( V_27 & V_41 )
F_9 () ;
if ( V_27 & V_42 )
F_7 () ;
break;
case V_43 :
F_6 () ;
V_39 |= V_33 ;
break;
case V_44 :
if ( F_12 ( V_14 , ( int T_3 * ) V_28 ) )
return - V_24 ;
F_10 ( V_14 ) ;
case V_45 :
if ( F_15 ( V_16 , ( int T_3 * ) V_28 ) )
return - V_24 ;
break;
default:
return - V_46 ;
}
return 0 ;
}
static int F_16 ( struct V_47 * V_47 , struct V_17 * V_17 )
{
if ( F_17 ( V_48 , & V_49 ) )
return - V_50 ;
if ( V_20 )
F_18 ( V_51 ) ;
F_7 () ;
return F_19 ( V_47 , V_17 ) ;
}
static int F_20 ( struct V_47 * V_47 , struct V_17 * V_17 )
{
if ( V_22 == 42 )
F_9 () ;
else {
F_21 ( L_4 ) ;
F_6 () ;
}
V_22 = 0 ;
F_22 ( V_48 , & V_49 ) ;
return 0 ;
}
static int F_23 ( struct V_52 * V_53 )
{
int V_14 = 10 ;
T_1 V_54 ;
V_15 = 133 ;
V_54 = F_24 () ;
if ( V_54 != - 1 )
V_15 = V_54 ;
V_7 = F_25 ( V_53 -> V_53 . V_55 , 0 ) ;
if ( V_7 == NULL )
return - V_56 ;
F_10 ( V_14 ) ;
F_9 () ;
return F_26 ( & V_57 ) ;
}
static int F_27 ( struct V_52 * V_53 )
{
F_28 ( & V_57 ) ;
F_9 () ;
F_29 ( V_7 ) ;
return 0 ;
}
static int T_6 F_30 ( void )
{
F_31 ( L_5 ) ;
return F_32 ( & V_58 ) ;
}
static void T_7 F_33 ( void )
{
F_34 ( & V_58 ) ;
}
