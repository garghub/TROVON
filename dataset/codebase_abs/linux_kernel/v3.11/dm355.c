void T_1 F_1 ( unsigned V_1 ,
const struct V_2 * V_3 , unsigned V_4 )
{
F_2 ( V_5 ) ;
if ( V_1 & F_3 ( 0 ) )
F_2 ( V_6 ) ;
if ( V_1 & F_3 ( 1 ) )
F_2 ( V_7 ) ;
F_4 ( V_3 , V_4 ) ;
F_5 ( & V_8 ) ;
}
static void F_6 ( void )
{
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
F_2 ( V_12 ) ;
F_2 ( V_13 ) ;
F_2 ( V_14 ) ;
F_2 ( V_15 ) ;
}
static int F_7 ( enum V_16 V_17 ,
int V_18 )
{
switch ( V_17 ) {
case V_19 :
F_2 ( V_20 ) ;
break;
case V_21 :
if ( V_18 )
F_2 ( V_22 ) ;
else
F_2 ( V_20 ) ;
break;
default:
return - V_23 ;
}
F_2 ( V_24 ) ;
F_2 ( V_25 ) ;
return 0 ;
}
static int F_8 ( enum V_26 type ,
unsigned int V_27 )
{
void T_2 * V_28 ;
V_28 = F_9 ( V_29 ) ;
switch ( type ) {
case V_30 :
F_10 ( V_31 | V_32 ,
V_28 ) ;
break;
case V_33 :
if ( V_27 > 27000000 )
F_10 ( V_34 , V_28 ) ;
break;
default:
return - V_23 ;
}
return 0 ;
}
void T_1 F_11 ( T_3 V_35 , struct V_36 * V_37 )
{
if ( V_35 & V_38 )
F_2 ( V_39 ) ;
if ( V_35 & V_40 )
F_2 ( V_41 ) ;
V_42 . V_43 . V_44 = V_37 ;
F_5 ( & V_42 ) ;
}
void T_1 F_12 ( void )
{
F_13 ( & V_45 ) ;
F_14 () ;
}
int T_1 F_15 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
if ( V_47 || V_49 )
F_5 ( & V_50 ) ;
if ( V_47 ) {
V_51 . V_43 . V_44 = V_47 ;
F_5 ( & V_52 ) ;
F_5 ( & V_51 ) ;
}
if ( V_49 ) {
V_53 . V_43 . V_44 = V_49 ;
F_5 ( & V_54 ) ;
F_5 ( & V_55 ) ;
F_5 ( & V_53 ) ;
F_5 ( & V_56 ) ;
}
return 0 ;
}
static int T_1 F_16 ( void )
{
if ( ! F_17 () )
return 0 ;
F_2 ( V_57 ) ;
F_5 ( & V_58 ) ;
return 0 ;
}
