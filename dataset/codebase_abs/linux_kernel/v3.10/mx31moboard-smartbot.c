static int F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_4 , ! V_3 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_2 ( V_5 , 0 ) ;
F_4 ( 100 ) ;
F_2 ( V_5 , 1 ) ;
return 0 ;
}
static int T_1 F_5 ( void )
{
int V_6 = F_6 ( V_5 , L_1 ) ;
if ( V_6 )
return V_6 ;
F_7 ( V_5 , 1 ) ;
V_6 = F_6 ( V_4 , L_2 ) ;
if ( V_6 )
return V_6 ;
F_7 ( V_4 , 0 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 )
{
return F_9 ( V_8 -> V_9 , V_10 ) ;
}
static int T_1 F_10 ( void )
{
struct V_7 * V_8 ;
V_11 . V_12 = F_11 ( V_13 |
V_14 ) ;
if ( ! V_11 . V_12 )
return - V_15 ;
V_8 = F_12 ( & V_11 ) ;
if ( F_13 ( V_8 ) )
return F_14 ( V_8 ) ;
return 0 ;
}
static inline int F_10 ( void ) { return 0 ; }
static void F_15 ( void )
{
if ( ! F_6 ( V_16 , L_3 ) ) {
F_7 ( V_16 , 0 ) ;
F_16 ( V_16 , false ) ;
}
if ( ! F_6 ( V_17 , L_4 ) ) {
F_7 ( V_17 , 0 ) ;
F_16 ( V_17 , false ) ;
}
if ( ! F_6 ( V_18 , L_5 ) ) {
F_7 ( V_18 , 0 ) ;
F_16 ( V_18 , false ) ;
}
if ( ! F_6 ( V_19 , L_6 ) ) {
F_7 ( V_19 , 0 ) ;
F_16 ( V_19 , false ) ;
}
}
void T_1 F_17 ( int V_20 )
{
F_18 ( V_21 L_7 ) ;
F_19 ( V_22 , F_20 ( V_22 ) ,
L_8 ) ;
F_21 ( & V_23 ) ;
switch ( V_20 ) {
case V_24 :
F_22 ( & V_25 ) ;
break;
case V_26 :
F_10 () ;
break;
default:
F_18 ( V_27 L_9 ,
V_20 ) ;
}
F_15 () ;
F_5 () ;
F_23 ( V_28 , F_20 ( V_28 ) ) ;
}
