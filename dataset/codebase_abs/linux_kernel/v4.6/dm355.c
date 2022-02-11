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
static int F_7 ( T_2 V_16 , int V_17 )
{
switch ( V_16 ) {
case V_18 :
F_2 ( V_19 ) ;
break;
case V_20 :
if ( V_17 )
F_2 ( V_21 ) ;
else
F_2 ( V_19 ) ;
break;
default:
return - V_22 ;
}
F_2 ( V_23 ) ;
F_2 ( V_24 ) ;
return 0 ;
}
static int F_8 ( enum V_25 type ,
unsigned int V_26 )
{
void T_3 * V_27 ;
V_27 = F_9 ( V_28 ) ;
switch ( type ) {
case V_29 :
F_10 ( V_30 | V_31 ,
V_27 ) ;
break;
case V_32 :
if ( V_26 > 27000000 )
F_10 ( V_33 , V_27 ) ;
break;
default:
return - V_22 ;
}
return 0 ;
}
int T_1 F_11 ( void )
{
return F_12 ( V_34 ,
F_13 ( V_34 ) ,
& V_35 ) ;
}
void T_1 F_14 ( T_2 V_36 , struct V_37 * V_38 )
{
if ( V_36 & V_39 )
F_2 ( V_40 ) ;
if ( V_36 & V_41 )
F_2 ( V_42 ) ;
V_43 . V_44 . V_45 = V_38 ;
F_5 ( & V_43 ) ;
}
void T_1 F_15 ( void )
{
F_16 ( & V_46 ) ;
F_17 () ;
}
int T_1 F_18 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
if ( V_48 || V_50 )
F_5 ( & V_51 ) ;
if ( V_48 ) {
V_52 . V_44 . V_45 = V_48 ;
F_5 ( & V_53 ) ;
F_5 ( & V_52 ) ;
}
if ( V_50 ) {
V_54 . V_44 . V_45 = V_50 ;
F_5 ( & V_55 ) ;
F_5 ( & V_56 ) ;
F_5 ( & V_54 ) ;
F_5 ( & V_57 ) ;
}
return 0 ;
}
static int T_1 F_19 ( void )
{
struct V_58 * V_59 ;
int V_60 = 0 ;
if ( ! F_20 () )
return 0 ;
F_2 ( V_61 ) ;
V_59 = F_21 ( & V_62 ) ;
if ( F_22 ( V_59 ) ) {
F_23 ( L_1 , V_63 ) ;
return F_24 ( V_59 ) ;
}
V_60 = F_25 () ;
if ( V_60 )
F_23 ( L_2 , V_63 , V_60 ) ;
return V_60 ;
}
