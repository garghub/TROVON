int F_1 ( const struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 , T_1 * V_5 )
{
unsigned int V_6 = 0xf ;
if ( V_3 > V_4 )
return - V_7 ;
if ( V_3 > V_2 -> V_8 || V_4 < V_2 -> V_9 )
return - V_7 ;
if ( V_4 < V_2 -> V_10 ) {
* V_5 = 0x0 ;
return 0 ;
}
V_4 = V_9 ( V_2 -> V_8 , V_4 ) ;
V_4 -= V_2 -> V_10 ;
V_6 = V_4 / V_2 -> V_11 ;
* V_5 = 0x1 << V_12 ;
* V_5 |= V_6 << V_13 ;
return 0 ;
}
static bool F_2 ( struct V_14 * V_15 , unsigned int V_16 )
{
switch ( V_16 ) {
case V_17 ... V_18 :
return true ;
default:
break;
}
return false ;
}
static bool F_3 ( struct V_14 * V_15 , unsigned int V_16 )
{
if ( F_2 ( V_15 , V_16 ) )
return true ;
switch ( V_16 ) {
case V_19 ... V_20 :
case V_21 ... V_22 :
case V_23 ... V_24 :
case V_25 :
case V_26 :
case V_27 :
return true ;
default:
break;
}
return false ;
}
static void F_4 ( struct V_28 * V_28 )
{
T_1 V_29 , V_30 , V_31 ;
int V_32 ;
V_32 = F_5 ( V_28 -> V_33 , V_34 ,
& V_29 ) ;
if ( V_32 ) {
F_6 ( V_28 -> V_15 ,
L_1 , V_32 ) ;
return;
}
V_30 = ( ( V_29 & V_35 ) >>
V_36 ) ;
V_31 = ( ( V_29 & V_37 ) >>
V_38 ) ;
F_7 ( V_28 -> V_15 , L_2 ,
V_28 -> V_39 , V_31 , V_30 ) ;
}
static int F_8 ( struct V_28 * V_28 )
{
int V_32 ;
T_1 V_40 ;
V_28 -> V_41 = F_9 ( V_28 -> V_42 -> V_43 ,
V_44 ) ;
if ( ! V_28 -> V_41 ) {
F_6 ( V_28 -> V_15 , L_3 ) ;
return - V_45 ;
}
F_10 ( V_28 -> V_41 , V_28 ) ;
V_28 -> V_46 = F_11 ( V_28 -> V_41 ,
& V_47 ) ;
if ( F_12 ( V_28 -> V_46 ) ) {
V_32 = F_13 ( V_28 -> V_46 ) ;
F_6 ( V_28 -> V_15 , L_4 ,
V_32 ) ;
goto V_48;
}
V_32 = F_5 ( V_28 -> V_46 ,
V_49 , & V_40 ) ;
if ( V_32 < 0 ) {
F_6 ( V_28 -> V_15 , L_5 ) ;
goto V_48;
}
V_40 &= ~ ( V_50 ) ;
V_40 &= ~ ( V_51 ) ;
V_32 = F_14 ( V_28 -> V_46 ,
V_49 , V_40 ) ;
if ( V_32 < 0 ) {
F_6 ( V_28 -> V_15 , L_6 ) ;
goto V_48;
}
V_32 = F_15 ( V_28 -> V_46 , V_28 -> V_52 ,
V_53 | V_54 | V_55 ,
0 , & V_56 ,
& V_28 -> V_57 ) ;
if ( V_32 != 0 ) {
F_6 ( V_28 -> V_15 , L_7 ,
V_28 -> V_52 , V_32 ) ;
goto V_48;
}
return 0 ;
V_48:
F_16 ( V_28 -> V_41 ) ;
return V_32 ;
}
static void F_17 ( struct V_28 * V_28 )
{
F_18 ( V_28 -> V_52 , V_28 -> V_57 ) ;
F_16 ( V_28 -> V_41 ) ;
}
static int F_19 ( struct V_58 * V_42 ,
const struct V_59 * V_60 )
{
struct V_28 * V_28 ;
struct V_61 * V_62 = F_20 ( & V_42 -> V_15 ) ;
struct V_63 * V_64 = V_42 -> V_15 . V_65 ;
int V_32 = 0 ;
const struct V_66 * V_67 ;
const struct V_68 * V_69 ;
unsigned int V_70 ;
int V_71 ;
if ( V_64 ) {
V_62 = F_21 ( & V_42 -> V_15 , sizeof( * V_62 ) , V_72 ) ;
if ( ! V_62 )
return - V_73 ;
V_42 -> V_15 . V_74 = V_62 ;
}
if ( ! V_62 ) {
F_6 ( & V_42 -> V_15 , L_8 ) ;
return - V_7 ;
}
V_28 = F_21 ( & V_42 -> V_15 , sizeof( * V_28 ) , V_72 ) ;
if ( ! V_28 )
return - V_73 ;
F_10 ( V_42 , V_28 ) ;
V_28 -> V_15 = & V_42 -> V_15 ;
V_28 -> V_42 = V_42 ;
V_28 -> V_52 = V_42 -> V_52 ;
V_28 -> V_33 = F_11 ( V_42 ,
& V_75 ) ;
if ( F_12 ( V_28 -> V_33 ) ) {
V_32 = F_13 ( V_28 -> V_33 ) ;
F_6 ( V_28 -> V_15 , L_9 ,
V_32 ) ;
return V_32 ;
}
if ( V_64 ) {
const struct V_76 * V_77 ;
V_77 = F_22 ( V_78 , & V_42 -> V_15 ) ;
if ( V_77 )
V_28 -> V_39 =
(enum V_79 ) V_77 -> V_80 ;
} else {
V_28 -> V_39 = V_60 -> V_81 ;
}
F_4 ( V_28 ) ;
switch ( V_28 -> V_39 ) {
case V_82 :
V_67 = & V_83 ;
V_69 = V_84 ;
V_70 = F_23 ( V_84 ) ;
V_71 = V_53 | V_54 | V_55 ;
break;
case V_85 :
default:
V_67 = & V_86 ;
V_69 = V_87 ;
V_70 = F_23 ( V_87 ) ;
V_71 = V_53 | V_54 ;
break;
}
V_32 = F_15 ( V_28 -> V_33 , V_28 -> V_52 ,
V_71 , 0 , V_67 ,
& V_28 -> V_88 ) ;
if ( V_32 != 0 ) {
F_6 ( & V_42 -> V_15 , L_10 ,
V_28 -> V_52 , V_32 ) ;
return V_32 ;
}
if ( V_28 -> V_39 == V_82 ) {
V_32 = F_8 ( V_28 ) ;
if ( V_32 < 0 )
goto V_89;
}
V_32 = F_24 ( V_28 -> V_15 , - 1 , V_69 ,
V_70 , NULL , 0 , NULL ) ;
if ( V_32 < 0 )
goto V_90;
F_25 ( V_28 -> V_15 , 1 ) ;
return 0 ;
V_90:
if ( V_28 -> V_39 == V_82 )
F_17 ( V_28 ) ;
V_89:
F_18 ( V_28 -> V_52 , V_28 -> V_88 ) ;
return V_32 ;
}
static int F_26 ( struct V_58 * V_42 )
{
struct V_28 * V_28 = F_27 ( V_42 ) ;
F_28 ( V_28 -> V_15 ) ;
F_18 ( V_28 -> V_52 , V_28 -> V_88 ) ;
if ( V_28 -> V_39 == V_82 )
F_17 ( V_28 ) ;
return 0 ;
}
static int F_29 ( struct V_14 * V_15 )
{
struct V_58 * V_42 = F_30 ( V_15 ) ;
struct V_28 * V_28 = F_27 ( V_42 ) ;
if ( F_31 ( V_15 ) )
F_32 ( V_28 -> V_52 ) ;
F_33 ( V_28 -> V_52 ) ;
return 0 ;
}
static int F_34 ( struct V_14 * V_15 )
{
struct V_58 * V_42 = F_30 ( V_15 ) ;
struct V_28 * V_28 = F_27 ( V_42 ) ;
if ( F_31 ( V_15 ) )
F_35 ( V_28 -> V_52 ) ;
F_36 ( V_28 -> V_52 ) ;
return 0 ;
}
static int T_2 F_37 ( void )
{
F_38 ( F_23 ( V_91 ) != V_92 ) ;
F_38 ( F_23 ( V_78 ) != V_92 ) ;
F_38 ( F_23 ( V_93 ) != V_92 ) ;
F_38 ( V_94 +
V_95 * 0xf !=
V_96 ) ;
F_38 ( V_95 == 0 ) ;
F_38 ( V_97 +
V_98 * 0xf !=
V_99 ) ;
F_38 ( V_98 == 0 ) ;
return F_39 ( & V_100 ) ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_100 ) ;
}
