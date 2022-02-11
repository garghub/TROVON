static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_4 ) ;
}
static int T_1 F_3 ( void )
{
struct V_1 * V_2 ;
V_5 . V_6 = F_4 ( V_7 |
V_8 ) ;
if ( ! V_5 . V_6 )
return - V_9 ;
V_2 = F_5 ( & V_5 ) ;
return F_6 ( V_2 ) ;
}
static inline int F_3 ( void ) { return 0 ; }
static void F_7 ( void )
{
if ( ! F_8 ( V_10 , L_1 ) ) {
F_9 ( V_10 , 0 ) ;
F_10 ( V_10 , false ) ;
}
if ( ! F_8 ( V_11 , L_2 ) ) {
F_9 ( V_11 , 0 ) ;
F_10 ( V_11 , false ) ;
}
if ( ! F_8 ( V_12 , L_3 ) ) {
F_9 ( V_12 , 0 ) ;
F_10 ( V_12 , false ) ;
}
if ( ! F_8 ( V_13 , L_4 ) ) {
F_9 ( V_13 , 0 ) ;
F_10 ( V_13 , false ) ;
}
}
void T_1 F_11 ( int V_14 )
{
F_12 ( V_15 L_5 ) ;
F_13 ( V_16 , F_14 ( V_16 ) ,
L_6 ) ;
F_15 ( & V_17 ) ;
switch ( V_14 ) {
case V_18 :
F_16 ( & V_19 ) ;
break;
case V_20 :
F_3 () ;
break;
default:
F_12 ( V_21 L_7 ,
V_14 ) ;
}
F_7 () ;
}
