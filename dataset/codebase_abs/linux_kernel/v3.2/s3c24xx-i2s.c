static void F_1 ( int V_1 )
{
T_1 V_2 ;
T_1 V_3 ;
T_1 V_4 ;
F_2 ( L_1 , V_5 ) ;
V_2 = F_3 ( V_6 . V_7 + V_8 ) ;
V_3 = F_3 ( V_6 . V_7 + V_9 ) ;
V_4 = F_3 ( V_6 . V_7 + V_10 ) ;
F_2 ( L_2 , V_3 , V_4 , V_2 ) ;
if ( V_1 ) {
V_2 |= V_11 | V_12 ;
V_3 |= V_13 | V_14 ;
V_3 &= ~ V_15 ;
V_4 |= V_16 ;
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
F_4 ( V_2 , V_6 . V_7 + V_8 ) ;
F_4 ( V_3 , V_6 . V_7 + V_9 ) ;
} else {
V_2 &= ~ V_12 ;
V_2 &= ~ V_11 ;
V_3 |= V_15 ;
V_3 &= ~ V_13 ;
V_4 &= ~ V_16 ;
F_4 ( V_3 , V_6 . V_7 + V_9 ) ;
F_4 ( V_2 , V_6 . V_7 + V_8 ) ;
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
}
F_2 ( L_3 , V_3 , V_4 , V_2 ) ;
}
static void F_5 ( int V_1 )
{
T_1 V_2 ;
T_1 V_3 ;
T_1 V_4 ;
F_2 ( L_1 , V_5 ) ;
V_2 = F_3 ( V_6 . V_7 + V_8 ) ;
V_3 = F_3 ( V_6 . V_7 + V_9 ) ;
V_4 = F_3 ( V_6 . V_7 + V_10 ) ;
F_2 ( L_2 , V_3 , V_4 , V_2 ) ;
if ( V_1 ) {
V_2 |= V_17 | V_18 ;
V_3 |= V_19 | V_14 ;
V_3 &= ~ V_20 ;
V_4 |= V_21 ;
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
F_4 ( V_2 , V_6 . V_7 + V_8 ) ;
F_4 ( V_3 , V_6 . V_7 + V_9 ) ;
} else {
V_2 &= ~ V_18 ;
V_2 &= ~ V_17 ;
V_3 |= V_20 ;
V_3 &= ~ V_19 ;
V_4 &= ~ V_21 ;
F_4 ( V_2 , V_6 . V_7 + V_8 ) ;
F_4 ( V_3 , V_6 . V_7 + V_9 ) ;
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
}
F_2 ( L_3 , V_3 , V_4 , V_2 ) ;
}
static int F_6 ( void )
{
T_1 V_3 ;
int V_22 = 50 ;
F_2 ( L_1 , V_5 ) ;
while ( 1 ) {
V_3 = F_3 ( V_6 . V_7 + V_9 ) ;
if ( V_3 & V_23 )
break;
if ( ! V_22 -- )
return - V_24 ;
F_7 ( 100 ) ;
}
return 0 ;
}
static inline int F_8 ( void )
{
F_2 ( L_1 , V_5 ) ;
return ( F_3 ( V_6 . V_7 + V_10 ) & V_25 ) ? 0 : 1 ;
}
static int F_9 ( struct V_26 * V_27 ,
unsigned int V_28 )
{
T_1 V_4 ;
F_2 ( L_1 , V_5 ) ;
V_4 = F_3 ( V_6 . V_7 + V_10 ) ;
F_2 ( L_4 , V_4 ) ;
switch ( V_28 & V_29 ) {
case V_30 :
V_4 |= V_25 ;
break;
case V_31 :
V_4 &= ~ V_25 ;
break;
default:
return - V_32 ;
}
switch ( V_28 & V_33 ) {
case V_34 :
V_4 |= V_35 ;
break;
case V_36 :
V_4 &= ~ V_35 ;
break;
default:
return - V_32 ;
}
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
F_2 ( L_5 , V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_26 * V_41 )
{
struct V_42 * V_43 = V_38 -> V_44 ;
struct V_45 * V_46 ;
T_1 V_4 ;
F_2 ( L_1 , V_5 ) ;
if ( V_38 -> V_47 == V_48 )
V_46 = & V_49 ;
else
V_46 = & V_50 ;
F_11 ( V_43 -> V_27 , V_38 , V_46 ) ;
V_4 = F_3 ( V_6 . V_7 + V_10 ) ;
F_2 ( L_6 , V_4 ) ;
switch ( F_12 ( V_40 ) ) {
case V_51 :
V_4 &= ~ V_52 ;
V_46 -> V_53 = 1 ;
break;
case V_54 :
V_4 |= V_52 ;
V_46 -> V_53 = 2 ;
break;
default:
return - V_32 ;
}
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
F_2 ( L_7 , V_4 ) ;
return 0 ;
}
static int F_13 ( struct V_37 * V_38 , int V_55 ,
struct V_26 * V_41 )
{
int V_56 = 0 ;
struct V_45 * V_46 =
F_14 ( V_41 , V_38 ) ;
F_2 ( L_1 , V_5 ) ;
switch ( V_55 ) {
case V_57 :
case V_58 :
case V_59 :
if ( ! F_8 () ) {
V_56 = F_6 () ;
if ( V_56 )
goto V_60;
}
if ( V_38 -> V_47 == V_61 )
F_5 ( 1 ) ;
else
F_1 ( 1 ) ;
F_15 ( V_46 -> V_62 , V_63 ) ;
break;
case V_64 :
case V_65 :
case V_66 :
if ( V_38 -> V_47 == V_61 )
F_5 ( 0 ) ;
else
F_1 ( 0 ) ;
break;
default:
V_56 = - V_32 ;
break;
}
V_60:
return V_56 ;
}
static int F_16 ( struct V_26 * V_27 ,
int V_67 , unsigned int V_68 , int V_69 )
{
T_1 V_4 = F_3 ( V_6 . V_7 + V_10 ) ;
F_2 ( L_1 , V_5 ) ;
V_4 &= ~ V_70 ;
switch ( V_67 ) {
case V_71 :
break;
case V_72 :
V_4 |= V_70 ;
break;
default:
return - V_32 ;
}
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
return 0 ;
}
static int F_17 ( struct V_26 * V_27 ,
int V_73 , int div )
{
T_1 V_74 ;
F_2 ( L_1 , V_5 ) ;
switch ( V_73 ) {
case V_75 :
V_74 = F_3 ( V_6 . V_7 + V_10 ) & ~ V_76 ;
F_4 ( V_74 | div , V_6 . V_7 + V_10 ) ;
break;
case V_77 :
V_74 = F_3 ( V_6 . V_7 + V_10 ) & ~ ( V_78 ) ;
F_4 ( V_74 | div , V_6 . V_7 + V_10 ) ;
break;
case V_79 :
F_4 ( div , V_6 . V_7 + V_80 ) ;
V_74 = F_3 ( V_6 . V_7 + V_9 ) ;
F_4 ( V_74 | V_81 , V_6 . V_7 + V_9 ) ;
break;
default:
return - V_32 ;
}
return 0 ;
}
T_1 F_18 ( void )
{
return F_19 ( V_6 . V_82 ) ;
}
static int F_20 ( struct V_26 * V_41 )
{
F_2 ( L_1 , V_5 ) ;
V_6 . V_7 = F_21 ( V_83 , 0x100 ) ;
if ( V_6 . V_7 == NULL )
return - V_84 ;
V_6 . V_82 = F_22 ( V_41 -> V_85 , L_8 ) ;
if ( F_23 ( V_6 . V_82 ) ) {
F_24 ( L_9 ) ;
F_25 ( V_6 . V_7 ) ;
return F_26 ( V_6 . V_82 ) ;
}
F_27 ( V_6 . V_82 ) ;
F_28 ( V_86 , V_87 ) ;
F_28 ( V_88 , V_89 ) ;
F_28 ( V_90 , V_91 ) ;
F_28 ( V_92 , V_93 ) ;
F_28 ( V_94 , V_95 ) ;
F_4 ( V_14 , V_6 . V_7 + V_9 ) ;
F_1 ( 0 ) ;
F_5 ( 0 ) ;
return 0 ;
}
static int F_29 ( struct V_26 * V_27 )
{
F_2 ( L_1 , V_5 ) ;
V_6 . V_3 = F_3 ( V_6 . V_7 + V_9 ) ;
V_6 . V_4 = F_3 ( V_6 . V_7 + V_10 ) ;
V_6 . V_2 = F_3 ( V_6 . V_7 + V_8 ) ;
V_6 . V_96 = F_3 ( V_6 . V_7 + V_80 ) ;
F_30 ( V_6 . V_82 ) ;
return 0 ;
}
static int F_31 ( struct V_26 * V_27 )
{
F_2 ( L_1 , V_5 ) ;
F_27 ( V_6 . V_82 ) ;
F_4 ( V_6 . V_3 , V_6 . V_7 + V_9 ) ;
F_4 ( V_6 . V_4 , V_6 . V_7 + V_10 ) ;
F_4 ( V_6 . V_2 , V_6 . V_7 + V_8 ) ;
F_4 ( V_6 . V_96 , V_6 . V_7 + V_80 ) ;
return 0 ;
}
static T_2 int F_32 ( struct V_97 * V_98 )
{
return F_33 ( & V_98 -> V_85 , & V_99 ) ;
}
static T_3 int F_34 ( struct V_97 * V_98 )
{
F_35 ( & V_98 -> V_85 ) ;
return 0 ;
}
static int T_4 F_36 ( void )
{
return F_37 ( & V_100 ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( & V_100 ) ;
}
