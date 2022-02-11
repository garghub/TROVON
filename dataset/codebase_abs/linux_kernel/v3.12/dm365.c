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
void T_1 F_6 ( struct V_11 * V_12 )
{
F_2 ( V_13 ) ;
F_2 ( V_14 ) ;
F_2 ( V_15 ) ;
F_2 ( V_16 ) ;
F_2 ( V_17 ) ;
F_2 ( V_18 ) ;
F_2 ( V_19 ) ;
F_2 ( V_20 ) ;
V_21 . V_22 . V_23 = V_12 ;
F_5 ( & V_21 ) ;
}
void T_1 F_7 ( struct V_11 * V_12 )
{
F_2 ( V_24 ) ;
F_2 ( V_25 ) ;
V_26 . V_22 . V_23 = V_12 ;
F_5 ( & V_26 ) ;
}
void T_1 F_8 ( struct V_27 * V_12 )
{
V_28 . V_22 . V_23 = V_12 ;
F_5 ( & V_28 ) ;
}
void T_1 F_9 ( void )
{
F_2 ( V_29 ) ;
F_5 ( & V_30 ) ;
}
void T_1 F_10 ( void )
{
F_11 ( & V_31 ) ;
F_12 () ;
}
static void F_13 ( void )
{
F_2 ( V_32 ) ;
F_2 ( V_33 ) ;
F_2 ( V_34 ) ;
F_2 ( V_35 ) ;
F_2 ( V_36 ) ;
}
static int F_14 ( enum V_37 V_38 ,
int V_39 )
{
switch ( V_38 ) {
case V_40 :
F_2 ( V_41 ) ;
F_2 ( V_42 ) ;
F_2 ( V_43 ) ;
break;
case V_44 :
if ( V_39 )
F_2 ( V_45 ) ;
else
F_2 ( V_41 ) ;
F_2 ( V_42 ) ;
F_2 ( V_43 ) ;
break;
default:
return - V_46 ;
}
return 0 ;
}
static int F_15 ( enum V_47 type ,
unsigned int V_48 )
{
void T_2 * V_49 ;
T_3 V_50 ;
V_49 = F_16 ( V_51 ) ;
switch ( type ) {
case V_52 :
V_50 = V_53 | V_54 ;
break;
case V_55 :
if ( V_48 <= 27000000 ) {
V_50 = V_53 | V_54 ;
} else {
V_50 = V_56 | V_54 |
V_53 ;
}
break;
default:
return - V_46 ;
}
F_17 ( V_50 , V_49 ) ;
return 0 ;
}
int T_1 F_18 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
if ( V_58 || V_60 )
F_5 ( & V_61 ) ;
if ( V_58 ) {
V_62 . V_22 . V_23 = V_58 ;
F_5 ( & V_63 ) ;
F_5 ( & V_62 ) ;
}
if ( V_60 ) {
V_64 . V_22 . V_23 = V_60 ;
F_5 ( & V_65 ) ;
F_5 ( & V_66 ) ;
F_5 ( & V_64 ) ;
F_5 ( & V_67 ) ;
}
return 0 ;
}
static int T_1 F_19 ( void )
{
if ( ! F_20 () )
return 0 ;
F_2 ( V_68 ) ;
F_5 ( & V_69 ) ;
F_5 ( & V_70 ) ;
F_5 ( & V_71 ) ;
return 0 ;
}
