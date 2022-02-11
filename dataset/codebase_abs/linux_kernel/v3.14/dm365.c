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
static int F_17 ( enum V_39 V_40 ,
int V_41 )
{
switch ( V_40 ) {
case V_42 :
F_2 ( V_43 ) ;
F_2 ( V_44 ) ;
F_2 ( V_45 ) ;
break;
case V_46 :
if ( V_41 )
F_2 ( V_47 ) ;
else
F_2 ( V_43 ) ;
F_2 ( V_44 ) ;
F_2 ( V_45 ) ;
break;
default:
return - V_48 ;
}
return 0 ;
}
static int F_18 ( enum V_49 type ,
unsigned int V_50 )
{
void T_2 * V_51 ;
T_3 V_52 ;
V_51 = F_19 ( V_53 ) ;
switch ( type ) {
case V_54 :
V_52 = V_55 | V_56 ;
break;
case V_57 :
if ( V_50 <= 27000000 ) {
V_52 = V_55 | V_56 ;
} else {
V_52 = V_58 | V_56 |
V_55 ;
}
break;
default:
return - V_48 ;
}
F_20 ( V_52 , V_51 ) ;
return 0 ;
}
int T_1 F_21 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
if ( V_60 || V_62 )
F_5 ( & V_63 ) ;
if ( V_60 ) {
V_64 . V_24 . V_25 = V_60 ;
F_5 ( & V_65 ) ;
F_5 ( & V_64 ) ;
}
if ( V_62 ) {
V_66 . V_24 . V_25 = V_62 ;
F_5 ( & V_67 ) ;
F_5 ( & V_68 ) ;
F_5 ( & V_66 ) ;
F_5 ( & V_69 ) ;
}
return 0 ;
}
static int T_1 F_22 ( void )
{
if ( ! F_23 () )
return 0 ;
F_2 ( V_70 ) ;
F_5 ( & V_71 ) ;
F_5 ( & V_72 ) ;
F_5 ( & V_73 ) ;
return 0 ;
}
