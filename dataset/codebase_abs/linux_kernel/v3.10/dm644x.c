static int F_1 ( enum V_1 type ,
unsigned int V_2 )
{
int V_3 = 0 ;
T_1 V_4 = V_5 ;
switch ( type ) {
case V_6 :
V_4 |= V_7 ;
F_2 ( V_4 , F_3 ( V_8 ) ) ;
break;
case V_9 :
if ( V_2 <= 27000000 ) {
V_4 |= V_7 ;
F_2 ( V_4 , F_3 ( V_8 ) ) ;
} else {
V_4 |= V_10 ;
F_2 ( V_4 , F_3 ( V_8 ) ) ;
}
break;
default:
V_3 = - V_11 ;
}
return V_3 ;
}
void T_2 F_4 ( struct V_12 * V_13 )
{
F_5 ( V_14 ) ;
V_15 . V_16 . V_17 = V_13 ;
F_6 ( & V_15 ) ;
}
void T_2 F_7 ( void )
{
F_8 ( & V_18 ) ;
F_9 () ;
}
int T_2 F_10 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
if ( V_20 || V_22 )
F_6 ( & V_23 ) ;
if ( V_20 ) {
V_24 . V_16 . V_17 = V_20 ;
F_6 ( & V_25 ) ;
F_6 ( & V_24 ) ;
}
if ( V_22 ) {
V_26 . V_16 . V_17 = V_22 ;
F_6 ( & V_27 ) ;
F_6 ( & V_28 ) ;
F_6 ( & V_26 ) ;
F_6 ( & V_29 ) ;
}
return 0 ;
}
static int T_2 F_11 ( void )
{
if ( ! F_12 () )
return 0 ;
F_6 ( & V_30 ) ;
F_6 ( & V_31 ) ;
F_6 ( & V_32 ) ;
F_13 ( NULL , F_14 ( & V_31 . V_16 ) ,
NULL , & V_32 . V_16 ) ;
return 0 ;
}
