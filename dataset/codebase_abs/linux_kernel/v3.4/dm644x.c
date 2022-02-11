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
switch ( V_2 ) {
case V_10 :
case V_11 :
V_4 |= V_12 |
V_7 ;
F_2 ( V_4 , F_3 ( V_8 ) ) ;
break;
case V_13 :
case V_14 :
case V_15 :
V_4 |= V_16 ;
F_2 ( V_4 , F_3 ( V_8 ) ) ;
break;
default:
V_3 = - V_17 ;
break;
}
break;
default:
V_3 = - V_17 ;
}
return V_3 ;
}
void T_2 F_4 ( struct V_18 * V_19 )
{
F_5 ( V_20 ) ;
V_21 . V_22 . V_23 = V_19 ;
F_6 ( & V_21 ) ;
}
void T_2 F_7 ( void )
{
F_8 ( & V_24 ) ;
F_9 () ;
}
int T_2 F_10 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
if ( V_26 || V_28 )
F_6 ( & V_29 ) ;
if ( V_26 ) {
V_30 . V_22 . V_23 = V_26 ;
F_6 ( & V_31 ) ;
F_6 ( & V_30 ) ;
F_11 ( L_1 , V_31 . V_32 ,
L_2 , NULL ) ;
F_11 ( L_3 , V_31 . V_32 ,
L_4 , NULL ) ;
}
if ( V_28 ) {
V_33 . V_22 . V_23 = V_28 ;
F_6 ( & V_34 ) ;
F_6 ( & V_35 ) ;
F_6 ( & V_33 ) ;
F_6 ( & V_36 ) ;
}
return 0 ;
}
static int T_2 F_12 ( void )
{
if ( ! F_13 () )
return 0 ;
F_6 ( & V_37 ) ;
F_6 ( & V_38 ) ;
F_6 ( & V_39 ) ;
F_11 ( NULL , F_14 ( & V_38 . V_22 ) ,
NULL , & V_39 . V_22 ) ;
return 0 ;
}
