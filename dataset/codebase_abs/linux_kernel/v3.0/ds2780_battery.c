static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_2 * F_3 ( struct V_5 * V_6 )
{
return F_4 ( V_6 ) ;
}
static inline int F_5 ( struct V_5 * V_6 , T_1 * V_7 , int V_8 )
{
return F_6 ( V_6 , V_7 , V_8 , sizeof( T_1 ) , 0 ) ;
}
static int F_7 ( struct V_5 * V_6 , T_2 * V_7 , int V_8 )
{
int V_9 ;
T_1 V_10 [ 2 ] ;
V_9 = F_6 ( V_6 , V_10 , V_8 , sizeof( T_1 ) * 2 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_7 = ( V_10 [ 0 ] << 8 ) | V_10 [ 1 ] ;
return 0 ;
}
static inline int F_8 ( struct V_5 * V_6 , T_1 * V_7 , int V_8 ,
T_3 V_11 )
{
return F_6 ( V_6 , V_7 , V_8 , V_11 , 0 ) ;
}
static inline int F_9 ( struct V_5 * V_6 , T_1 * V_7 , int V_8 ,
T_3 V_11 )
{
return F_6 ( V_6 , V_7 , V_8 , V_11 , 1 ) ;
}
static inline int F_10 ( struct V_5 * V_6 , int V_8 )
{
return F_11 ( V_6 , V_8 , V_12 ) ;
}
static inline int F_12 ( struct V_5 * V_6 , int V_8 )
{
return F_11 ( V_6 , V_8 , V_13 ) ;
}
static int F_13 ( struct V_1 * V_14 , int V_15 )
{
int V_9 ;
V_9 = F_10 ( V_14 -> V_16 , V_15 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_12 ( V_14 -> V_16 , V_15 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_14 ,
T_1 V_17 )
{
int V_9 ;
V_9 = F_9 ( V_14 -> V_16 , & V_17 ,
V_18 , sizeof( T_1 ) ) ;
if ( V_9 < 0 )
return V_9 ;
return F_13 ( V_14 , V_18 ) ;
}
static int F_15 ( struct V_1 * V_14 ,
T_4 * V_19 )
{
return F_7 ( V_14 -> V_16 , V_19 , V_20 ) ;
}
static int F_16 ( struct V_1 * V_14 ,
T_4 V_19 )
{
int V_9 ;
T_1 V_10 [] = { V_19 >> 8 , V_19 & 0xFF } ;
V_9 = F_9 ( V_14 -> V_16 , V_10 ,
V_20 , sizeof( T_1 ) * 2 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_13 ( V_14 , V_20 ) ;
}
static int F_17 ( struct V_1 * V_14 ,
int * V_21 )
{
int V_9 ;
T_2 V_22 ;
V_9 = F_7 ( V_14 -> V_16 , & V_22 ,
V_23 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_21 = ( V_22 / 32 ) * 4880 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_14 ,
int * V_24 )
{
int V_9 ;
T_2 V_25 ;
V_9 = F_7 ( V_14 -> V_16 , & V_25 ,
V_26 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_24 = ( ( V_25 / 32 ) * 125 ) / 100 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_14 ,
enum V_27 type , int * V_28 )
{
int V_9 , V_29 ;
T_2 V_30 ;
T_1 V_31 , V_32 ;
V_9 = F_5 ( V_14 -> V_16 , & V_31 , V_18 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_31 == 0 ) {
F_20 ( V_14 -> V_6 , L_1 ) ;
return - V_33 ;
}
V_29 = 1000 / V_31 ;
if ( type == V_34 )
V_32 = V_35 ;
else if ( type == V_36 )
V_32 = V_37 ;
else
return - V_38 ;
V_9 = F_7 ( V_14 -> V_16 , & V_30 , V_32 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_28 = V_30 * ( V_39 / V_29 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_14 ,
int * V_40 )
{
int V_9 , V_29 ;
T_2 V_30 ;
T_1 V_31 ;
V_9 = F_5 ( V_14 -> V_16 , & V_31 , V_18 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_31 == 0 ) {
F_20 ( V_14 -> V_6 , L_1 ) ;
return - V_33 ;
}
V_29 = 1000 / V_31 ;
V_9 = F_7 ( V_14 -> V_16 , & V_30 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_40 = V_30 * ( V_42 / V_29 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_14 ,
int * V_43 )
{
int V_9 ;
T_1 V_10 ;
V_9 = F_5 ( V_14 -> V_16 , & V_10 , V_44 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_43 = V_10 ;
return V_10 ;
}
static int F_23 ( struct V_1 * V_14 , int * V_45 )
{
int V_9 , V_28 , V_43 ;
V_9 = F_19 ( V_14 , V_34 , & V_28 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_22 ( V_14 , & V_43 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_43 == 100 )
* V_45 = V_46 ;
else if ( V_28 == 0 )
* V_45 = V_47 ;
else if ( V_28 < 0 )
* V_45 = V_48 ;
else
* V_45 = V_49 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_14 ,
int * V_50 )
{
int V_9 ;
T_4 V_51 ;
V_9 = F_7 ( V_14 -> V_16 , & V_51 , V_52 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_50 = V_51 * 1600 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_14 ,
T_1 * V_53 )
{
return F_5 ( V_14 -> V_16 , V_53 , V_54 ) ;
}
static int F_26 ( struct V_1 * V_14 ,
T_1 V_53 )
{
int V_9 ;
V_9 = F_9 ( V_14 -> V_16 , & V_53 ,
V_54 , sizeof( T_1 ) ) ;
if ( V_9 < 0 )
return V_9 ;
return F_13 ( V_14 , V_54 ) ;
}
static int F_27 ( struct V_2 * V_3 ,
enum V_55 V_56 ,
union V_57 * V_7 )
{
int V_9 = 0 ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
switch ( V_56 ) {
case V_58 :
V_9 = F_17 ( V_14 , & V_7 -> V_59 ) ;
break;
case V_60 :
V_9 = F_18 ( V_14 , & V_7 -> V_59 ) ;
break;
case V_61 :
V_7 -> V_62 = V_63 ;
break;
case V_64 :
V_7 -> V_62 = V_65 ;
break;
case V_66 :
V_9 = F_19 ( V_14 , V_34 , & V_7 -> V_59 ) ;
break;
case V_67 :
V_9 = F_19 ( V_14 , V_36 , & V_7 -> V_59 ) ;
break;
case V_68 :
V_9 = F_23 ( V_14 , & V_7 -> V_59 ) ;
break;
case V_69 :
V_9 = F_22 ( V_14 , & V_7 -> V_59 ) ;
break;
case V_70 :
V_9 = F_21 ( V_14 , & V_7 -> V_59 ) ;
break;
case V_71 :
V_9 = F_24 ( V_14 , & V_7 -> V_59 ) ;
break;
default:
V_9 = - V_38 ;
}
return V_9 ;
}
static T_5 F_28 ( struct V_5 * V_6 ,
struct V_72 * V_73 ,
char * V_74 )
{
int V_9 ;
T_1 V_53 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
V_9 = F_25 ( V_14 , & V_53 ) ;
if ( V_9 < 0 )
return V_9 ;
return sprintf ( V_74 , L_2 ,
! ! ( V_53 & V_75 ) ) ;
}
static T_5 F_29 ( struct V_5 * V_6 ,
struct V_72 * V_73 ,
const char * V_74 ,
T_3 V_11 )
{
int V_9 ;
T_1 V_53 , V_76 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
V_9 = F_25 ( V_14 , & V_53 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_30 ( V_74 , 0 , & V_76 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ( V_76 != 0 ) && ( V_76 != 1 ) ) {
F_20 ( V_14 -> V_6 , L_3 ) ;
return - V_38 ;
}
if ( V_76 )
V_53 |= V_75 ;
else
V_53 &= ~ V_75 ;
V_9 = F_26 ( V_14 , V_53 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_11 ;
}
static T_5 F_31 ( struct V_5 * V_6 ,
struct V_72 * V_73 ,
char * V_74 )
{
int V_9 ;
T_1 V_77 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
V_9 = F_5 ( V_14 -> V_16 , & V_77 , V_18 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = sprintf ( V_74 , L_2 , V_77 ) ;
return V_9 ;
}
static T_5 F_32 ( struct V_5 * V_6 ,
struct V_72 * V_73 ,
const char * V_74 ,
T_3 V_11 )
{
int V_9 ;
T_1 V_76 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
V_9 = F_30 ( V_74 , 0 , & V_76 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_14 ( V_14 , V_76 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_11 ;
}
static T_5 F_33 ( struct V_5 * V_6 ,
struct V_72 * V_73 ,
char * V_74 )
{
int V_9 ;
T_4 V_19 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
V_9 = F_15 ( V_14 , & V_19 ) ;
if ( V_9 < 0 )
return V_9 ;
return sprintf ( V_74 , L_2 , V_19 ) ;
}
static T_5 F_34 ( struct V_5 * V_6 ,
struct V_72 * V_73 ,
const char * V_74 ,
T_3 V_11 )
{
int V_9 ;
T_4 V_76 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
V_9 = F_35 ( V_74 , 0 , & V_76 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_76 > 1999 ) {
F_20 ( V_14 -> V_6 , L_4 ) ;
return - V_38 ;
}
V_9 = F_16 ( V_14 , V_76 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_11 ;
}
static T_5 F_36 ( struct V_5 * V_6 ,
struct V_72 * V_73 ,
char * V_74 )
{
int V_9 ;
T_1 V_78 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
V_9 = F_5 ( V_14 -> V_16 , & V_78 , V_79 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = sprintf ( V_74 , L_2 , V_78 & V_80 ) ;
return V_9 ;
}
static T_5 F_37 ( struct V_5 * V_6 ,
struct V_72 * V_73 ,
const char * V_74 ,
T_3 V_11 )
{
int V_9 ;
T_1 V_76 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
V_9 = F_30 ( V_74 , 0 , & V_76 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ( V_76 != 0 ) && ( V_76 != 1 ) ) {
F_20 ( V_14 -> V_6 , L_5 ) ;
return - V_38 ;
}
V_9 = F_9 ( V_14 -> V_16 , & V_76 ,
V_79 , sizeof( T_1 ) ) ;
if ( V_9 < 0 )
return V_9 ;
return V_11 ;
}
static T_5 F_38 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_74 , T_6 V_87 , T_3 V_11 )
{
struct V_5 * V_6 = F_2 ( V_84 , struct V_5 , V_84 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
V_11 = F_39 ( T_6 , V_11 ,
V_88 -
V_89 + 1 - V_87 ) ;
return F_8 ( V_14 -> V_16 , V_74 ,
V_89 + V_87 , V_11 ) ;
}
static T_5 F_40 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_74 , T_6 V_87 , T_3 V_11 )
{
struct V_5 * V_6 = F_2 ( V_84 , struct V_5 , V_84 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_9 ;
V_11 = F_39 ( T_6 , V_11 ,
V_88 -
V_89 + 1 - V_87 ) ;
V_9 = F_9 ( V_14 -> V_16 , V_74 ,
V_89 + V_87 , V_11 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_13 ( V_14 , V_89 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_11 ;
}
static T_5 F_41 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_74 , T_6 V_87 , T_3 V_11 )
{
struct V_5 * V_6 = F_2 ( V_84 , struct V_5 , V_84 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
V_11 = F_39 ( T_6 , V_11 ,
V_90 -
V_91 + 1 - V_87 ) ;
return F_8 ( V_14 -> V_16 , V_74 ,
V_91 + V_87 , V_11 ) ;
}
static T_5 F_42 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_74 , T_6 V_87 , T_3 V_11 )
{
struct V_5 * V_6 = F_2 ( V_84 , struct V_5 , V_84 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_9 ;
V_11 = F_39 ( T_6 , V_11 ,
V_90 -
V_91 + 1 - V_87 ) ;
V_9 = F_9 ( V_14 -> V_16 , V_74 ,
V_91 + V_87 , V_11 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_13 ( V_14 , V_91 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_11 ;
}
static int T_7 F_43 ( struct V_92 * V_93 )
{
int V_9 = 0 ;
struct V_1 * V_14 ;
V_14 = F_44 ( sizeof( * V_14 ) , V_94 ) ;
if ( ! V_14 ) {
V_9 = - V_95 ;
goto V_96;
}
F_45 ( V_93 , V_14 ) ;
V_14 -> V_6 = & V_93 -> V_6 ;
V_14 -> V_16 = V_93 -> V_6 . V_97 ;
V_14 -> V_4 . V_98 = F_46 ( & V_93 -> V_6 ) ;
V_14 -> V_4 . type = V_99 ;
V_14 -> V_4 . V_100 = V_101 ;
V_14 -> V_4 . V_102 = F_47 ( V_101 ) ;
V_14 -> V_4 . V_103 = F_27 ;
V_9 = F_48 ( & V_93 -> V_6 , & V_14 -> V_4 ) ;
if ( V_9 ) {
F_20 ( V_14 -> V_6 , L_6 ) ;
goto V_104;
}
V_9 = F_49 ( & V_14 -> V_4 . V_6 -> V_84 , & V_105 ) ;
if ( V_9 ) {
F_20 ( V_14 -> V_6 , L_7 ) ;
goto V_106;
}
V_9 = F_50 ( & V_14 -> V_4 . V_6 -> V_84 ,
& V_107 ) ;
if ( V_9 ) {
F_20 ( V_14 -> V_6 ,
L_8 ) ;
goto V_108;
}
V_9 = F_50 ( & V_14 -> V_4 . V_6 -> V_84 ,
& V_109 ) ;
if ( V_9 ) {
F_20 ( V_14 -> V_6 ,
L_9 ) ;
goto V_110;
}
return 0 ;
V_110:
F_51 ( & V_14 -> V_4 . V_6 -> V_84 ,
& V_107 ) ;
V_108:
F_52 ( & V_14 -> V_4 . V_6 -> V_84 , & V_105 ) ;
V_106:
F_53 ( & V_14 -> V_4 ) ;
V_104:
F_54 ( V_14 ) ;
V_96:
return V_9 ;
}
static int T_8 F_55 ( struct V_92 * V_93 )
{
struct V_1 * V_14 = F_56 ( V_93 ) ;
F_52 ( & V_14 -> V_4 . V_6 -> V_84 , & V_105 ) ;
F_53 ( & V_14 -> V_4 ) ;
F_54 ( V_14 ) ;
return 0 ;
}
static int T_9 F_57 ( void )
{
return F_58 ( & V_111 ) ;
}
static void T_10 F_59 ( void )
{
F_60 ( & V_111 ) ;
}
