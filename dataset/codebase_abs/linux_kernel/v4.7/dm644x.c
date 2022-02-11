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
int T_2 F_4 ( void )
{
return F_5 ( V_12 ,
F_6 ( V_12 ) ,
& V_13 ) ;
}
void T_2 F_7 ( struct V_14 * V_15 )
{
F_8 ( V_16 ) ;
V_17 . V_18 . V_19 = V_15 ;
F_9 ( & V_17 ) ;
}
void T_2 F_10 ( void )
{
F_11 ( & V_20 ) ;
F_12 () ;
F_13 ( V_20 . V_21 ) ;
}
int T_2 F_14 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
if ( V_23 || V_25 )
F_9 ( & V_26 ) ;
if ( V_23 ) {
V_27 . V_18 . V_19 = V_23 ;
F_9 ( & V_28 ) ;
F_9 ( & V_27 ) ;
}
if ( V_25 ) {
V_29 . V_18 . V_19 = V_25 ;
F_9 ( & V_30 ) ;
F_9 ( & V_31 ) ;
F_9 ( & V_29 ) ;
F_9 ( & V_32 ) ;
}
return 0 ;
}
static int T_2 F_15 ( void )
{
struct V_33 * V_34 ;
int V_3 = 0 ;
if ( ! F_16 () )
return 0 ;
V_34 = F_17 ( & V_35 ) ;
if ( F_18 ( V_34 ) ) {
F_19 ( L_1 , V_36 ) ;
return F_20 ( V_34 ) ;
}
F_9 ( & V_37 ) ;
F_9 ( & V_38 ) ;
V_3 = F_21 () ;
if ( V_3 )
F_19 ( L_2 , V_36 , V_3 ) ;
return V_3 ;
}
