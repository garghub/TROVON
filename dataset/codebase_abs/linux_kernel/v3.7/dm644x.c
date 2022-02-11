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
F_11 ( L_1 , V_25 . V_26 ,
L_2 , NULL ) ;
F_11 ( L_3 , V_25 . V_26 ,
L_4 , NULL ) ;
}
if ( V_22 ) {
V_27 . V_16 . V_17 = V_22 ;
F_6 ( & V_28 ) ;
F_6 ( & V_29 ) ;
F_6 ( & V_27 ) ;
F_6 ( & V_30 ) ;
}
return 0 ;
}
static int T_2 F_12 ( void )
{
if ( ! F_13 () )
return 0 ;
F_6 ( & V_31 ) ;
F_6 ( & V_32 ) ;
F_6 ( & V_33 ) ;
F_11 ( NULL , F_14 ( & V_32 . V_16 ) ,
NULL , & V_33 . V_16 ) ;
return 0 ;
}
