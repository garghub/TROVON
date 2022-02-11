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
int T_1 F_11 ( void )
{
return F_12 ( V_35 ,
F_13 ( V_35 ) ,
& V_36 ) ;
}
void T_1 F_14 ( T_3 V_37 , struct V_38 * V_39 )
{
if ( V_37 & V_40 )
F_2 ( V_41 ) ;
if ( V_37 & V_42 )
F_2 ( V_43 ) ;
V_44 . V_45 . V_46 = V_39 ;
F_5 ( & V_44 ) ;
}
void T_1 F_15 ( void )
{
F_16 ( & V_47 ) ;
F_17 () ;
}
int T_1 F_18 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
if ( V_49 || V_51 )
F_5 ( & V_52 ) ;
if ( V_49 ) {
V_53 . V_45 . V_46 = V_49 ;
F_5 ( & V_54 ) ;
F_5 ( & V_53 ) ;
}
if ( V_51 ) {
V_55 . V_45 . V_46 = V_51 ;
F_5 ( & V_56 ) ;
F_5 ( & V_57 ) ;
F_5 ( & V_55 ) ;
F_5 ( & V_58 ) ;
}
return 0 ;
}
static int T_1 F_19 ( void )
{
int V_59 = 0 ;
if ( ! F_20 () )
return 0 ;
F_2 ( V_60 ) ;
F_5 ( & V_61 ) ;
V_59 = F_21 () ;
if ( V_59 )
F_22 ( L_1 , V_62 , V_59 ) ;
return V_59 ;
}
