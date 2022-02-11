void T_1 F_1 ( unsigned V_1 ,
const struct V_2 * V_3 , unsigned V_4 )
{
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
if ( V_1 & F_3 ( 0 ) )
F_2 ( V_8 ) ;
if ( V_1 & F_3 ( 1 ) )
F_2 ( V_9 ) ;
F_4 ( V_3 , V_4 ) ;
F_5 ( & V_10 ) ;
}
int T_1 F_6 ( void )
{
return F_7 ( V_11 ,
F_8 ( V_11 ) ,
& V_12 ) ;
}
void T_1 F_9 ( struct V_13 * V_14 )
{
F_2 ( V_15 ) ;
F_2 ( V_16 ) ;
F_2 ( V_17 ) ;
F_2 ( V_18 ) ;
F_2 ( V_19 ) ;
F_2 ( V_20 ) ;
F_2 ( V_21 ) ;
F_2 ( V_22 ) ;
V_23 . V_24 . V_25 = V_14 ;
F_5 ( & V_23 ) ;
}
void T_1 F_10 ( struct V_13 * V_14 )
{
F_2 ( V_26 ) ;
F_2 ( V_27 ) ;
V_28 . V_24 . V_25 = V_14 ;
F_5 ( & V_28 ) ;
}
void T_1 F_11 ( struct V_29 * V_14 )
{
V_30 . V_24 . V_25 = V_14 ;
F_5 ( & V_30 ) ;
}
void T_1 F_12 ( void )
{
F_2 ( V_31 ) ;
F_5 ( & V_32 ) ;
}
void T_1 F_13 ( void )
{
F_14 ( & V_33 ) ;
F_15 () ;
}
static void F_16 ( void )
{
F_2 ( V_34 ) ;
F_2 ( V_35 ) ;
F_2 ( V_36 ) ;
F_2 ( V_37 ) ;
F_2 ( V_38 ) ;
}
static int F_17 ( T_2 V_39 , int V_40 )
{
switch ( V_39 ) {
case V_41 :
F_2 ( V_42 ) ;
F_2 ( V_43 ) ;
F_2 ( V_44 ) ;
break;
case V_45 :
if ( V_40 )
F_2 ( V_46 ) ;
else
F_2 ( V_42 ) ;
F_2 ( V_43 ) ;
F_2 ( V_44 ) ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_18 ( enum V_48 type ,
unsigned int V_49 )
{
void T_3 * V_50 ;
T_2 V_51 ;
V_50 = F_19 ( V_52 ) ;
switch ( type ) {
case V_53 :
V_51 = V_54 | V_55 ;
break;
case V_56 :
if ( V_49 <= 27000000 ) {
V_51 = V_54 | V_55 ;
} else {
V_51 = V_57 | V_55 |
V_54 ;
}
break;
default:
return - V_47 ;
}
F_20 ( V_51 , V_50 ) ;
return 0 ;
}
int T_1 F_21 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
if ( V_59 || V_61 )
F_5 ( & V_62 ) ;
if ( V_59 ) {
V_63 . V_24 . V_25 = V_59 ;
F_5 ( & V_64 ) ;
F_5 ( & V_63 ) ;
}
if ( V_61 ) {
V_65 . V_24 . V_25 = V_61 ;
F_5 ( & V_66 ) ;
F_5 ( & V_67 ) ;
F_5 ( & V_65 ) ;
F_5 ( & V_68 ) ;
}
return 0 ;
}
static int T_1 F_22 ( void )
{
int V_69 = 0 ;
if ( ! F_23 () )
return 0 ;
F_2 ( V_70 ) ;
F_5 ( & V_71 ) ;
F_5 ( & V_72 ) ;
F_5 ( & V_73 ) ;
V_69 = F_24 () ;
if ( V_69 )
F_25 ( L_1 , V_74 , V_69 ) ;
return V_69 ;
}
