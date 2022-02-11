static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return F_4 ( V_5 ) ;
}
static inline int F_5 ( struct V_1 * V_6 ,
char * V_7 , int V_8 , T_1 V_9 , int V_10 )
{
return F_6 ( V_6 -> V_11 , V_7 , V_8 , V_9 , V_10 ) ;
}
static inline int F_7 ( struct V_1 * V_6 , T_2 * V_12 ,
int V_8 )
{
return F_5 ( V_6 , V_12 , V_8 , sizeof( T_2 ) , 0 ) ;
}
static int F_8 ( struct V_1 * V_6 , T_3 * V_12 ,
int V_8 )
{
int V_13 ;
T_2 V_14 [ 2 ] ;
V_13 = F_5 ( V_6 , V_14 , V_8 , sizeof( V_14 ) , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_12 = ( V_14 [ 0 ] << 8 ) | V_14 [ 1 ] ;
return 0 ;
}
static inline int F_9 ( struct V_1 * V_6 ,
T_2 * V_12 , int V_8 , T_1 V_9 )
{
return F_5 ( V_6 , V_12 , V_8 , V_9 , 0 ) ;
}
static inline int F_10 ( struct V_1 * V_6 , T_2 * V_12 ,
int V_8 , T_1 V_9 )
{
return F_5 ( V_6 , V_12 , V_8 , V_9 , 1 ) ;
}
static inline int F_11 ( struct V_4 * V_5 , int V_8 )
{
return F_12 ( V_5 , V_8 , V_15 ) ;
}
static inline int F_13 ( struct V_4 * V_5 , int V_8 )
{
return F_12 ( V_5 , V_8 , V_16 ) ;
}
static int F_14 ( struct V_1 * V_6 , int V_17 )
{
int V_13 ;
V_13 = F_11 ( V_6 -> V_11 , V_17 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_13 ( V_6 -> V_11 , V_17 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_6 ,
T_2 V_18 )
{
int V_13 ;
V_13 = F_10 ( V_6 , & V_18 ,
V_19 , sizeof( T_2 ) ) ;
if ( V_13 < 0 )
return V_13 ;
return F_14 ( V_6 , V_19 ) ;
}
static int F_16 ( struct V_1 * V_6 ,
T_4 * V_20 )
{
return F_8 ( V_6 , V_20 , V_21 ) ;
}
static int F_17 ( struct V_1 * V_6 ,
T_4 V_20 )
{
int V_13 ;
T_2 V_14 [] = { V_20 >> 8 , V_20 & 0xFF } ;
V_13 = F_10 ( V_6 , V_14 ,
V_21 , sizeof( V_14 ) ) ;
if ( V_13 < 0 )
return V_13 ;
return F_14 ( V_6 , V_21 ) ;
}
static int F_18 ( struct V_1 * V_6 ,
int * V_22 )
{
int V_13 ;
T_3 V_23 ;
V_13 = F_8 ( V_6 , & V_23 ,
V_24 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_22 = ( V_23 / 32 ) * 4880 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_6 ,
int * V_25 )
{
int V_13 ;
T_3 V_26 ;
V_13 = F_8 ( V_6 , & V_26 ,
V_27 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_25 = ( ( V_26 / 32 ) * 125 ) / 100 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_6 ,
enum V_28 type , int * V_29 )
{
int V_13 , V_30 ;
T_3 V_31 ;
T_2 V_32 , V_33 ;
V_13 = F_7 ( V_6 , & V_32 , V_19 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_32 == 0 ) {
F_21 ( V_6 -> V_5 , L_1 ) ;
return - V_34 ;
}
V_30 = 1000 / V_32 ;
if ( type == V_35 )
V_33 = V_36 ;
else if ( type == V_37 )
V_33 = V_38 ;
else
return - V_34 ;
V_13 = F_8 ( V_6 , & V_31 , V_33 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_29 = V_31 * ( V_39 / V_30 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_6 ,
int * V_40 )
{
int V_13 , V_30 ;
T_3 V_31 ;
T_2 V_32 ;
V_13 = F_7 ( V_6 , & V_32 , V_19 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_32 == 0 ) {
F_21 ( V_6 -> V_5 , L_1 ) ;
return - V_41 ;
}
V_30 = 1000 / V_32 ;
V_13 = F_8 ( V_6 , & V_31 , V_42 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_40 = V_31 * ( V_43 / V_30 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_6 ,
int * V_44 )
{
int V_13 ;
T_2 V_14 ;
V_13 = F_7 ( V_6 , & V_14 , V_45 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_44 = V_14 ;
return V_14 ;
}
static int F_24 ( struct V_1 * V_6 , int * V_46 )
{
int V_13 , V_29 , V_44 ;
V_13 = F_20 ( V_6 , V_35 , & V_29 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_23 ( V_6 , & V_44 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_44 == 100 )
* V_46 = V_47 ;
else if ( V_29 == 0 )
* V_46 = V_48 ;
else if ( V_29 < 0 )
* V_46 = V_49 ;
else
* V_46 = V_50 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_6 ,
int * V_51 )
{
int V_13 ;
T_4 V_52 ;
V_13 = F_8 ( V_6 , & V_52 , V_53 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_51 = V_52 * 1600 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_6 ,
T_2 * V_54 )
{
return F_7 ( V_6 , V_54 , V_55 ) ;
}
static int F_27 ( struct V_1 * V_6 ,
T_2 V_54 )
{
int V_13 ;
V_13 = F_10 ( V_6 , & V_54 ,
V_55 , sizeof( T_2 ) ) ;
if ( V_13 < 0 )
return V_13 ;
return F_14 ( V_6 , V_55 ) ;
}
static int F_28 ( struct V_2 * V_3 ,
enum V_56 V_57 ,
union V_58 * V_12 )
{
int V_13 = 0 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
switch ( V_57 ) {
case V_59 :
V_13 = F_18 ( V_6 , & V_12 -> V_60 ) ;
break;
case V_61 :
V_13 = F_19 ( V_6 , & V_12 -> V_60 ) ;
break;
case V_62 :
V_12 -> V_63 = V_64 ;
break;
case V_65 :
V_12 -> V_63 = V_66 ;
break;
case V_67 :
V_13 = F_20 ( V_6 , V_35 , & V_12 -> V_60 ) ;
break;
case V_68 :
V_13 = F_20 ( V_6 , V_37 , & V_12 -> V_60 ) ;
break;
case V_69 :
V_13 = F_24 ( V_6 , & V_12 -> V_60 ) ;
break;
case V_70 :
V_13 = F_23 ( V_6 , & V_12 -> V_60 ) ;
break;
case V_71 :
V_13 = F_22 ( V_6 , & V_12 -> V_60 ) ;
break;
case V_72 :
V_13 = F_25 ( V_6 , & V_12 -> V_60 ) ;
break;
default:
V_13 = - V_34 ;
}
return V_13 ;
}
static T_5 F_29 ( struct V_4 * V_5 ,
struct V_73 * V_74 ,
char * V_7 )
{
int V_13 ;
T_2 V_54 ;
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_13 = F_26 ( V_6 , & V_54 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_7 , L_2 ,
! ! ( V_54 & V_75 ) ) ;
}
static T_5 F_30 ( struct V_4 * V_5 ,
struct V_73 * V_74 ,
const char * V_7 ,
T_1 V_9 )
{
int V_13 ;
T_2 V_54 , V_76 ;
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_13 = F_26 ( V_6 , & V_54 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_31 ( V_7 , 0 , & V_76 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ( V_76 != 0 ) && ( V_76 != 1 ) ) {
F_21 ( V_6 -> V_5 , L_3 ) ;
return - V_34 ;
}
if ( V_76 )
V_54 |= V_75 ;
else
V_54 &= ~ V_75 ;
V_13 = F_27 ( V_6 , V_54 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_9 ;
}
static T_5 F_32 ( struct V_4 * V_5 ,
struct V_73 * V_74 ,
char * V_7 )
{
int V_13 ;
T_2 V_77 ;
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_13 = F_7 ( V_6 , & V_77 , V_19 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = sprintf ( V_7 , L_2 , V_77 ) ;
return V_13 ;
}
static T_5 F_33 ( struct V_4 * V_5 ,
struct V_73 * V_74 ,
const char * V_7 ,
T_1 V_9 )
{
int V_13 ;
T_2 V_76 ;
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_13 = F_31 ( V_7 , 0 , & V_76 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_15 ( V_6 , V_76 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_9 ;
}
static T_5 F_34 ( struct V_4 * V_5 ,
struct V_73 * V_74 ,
char * V_7 )
{
int V_13 ;
T_4 V_20 ;
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_13 = F_16 ( V_6 , & V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_7 , L_2 , V_20 ) ;
}
static T_5 F_35 ( struct V_4 * V_5 ,
struct V_73 * V_74 ,
const char * V_7 ,
T_1 V_9 )
{
int V_13 ;
T_4 V_76 ;
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_13 = F_36 ( V_7 , 0 , & V_76 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_76 > 1999 ) {
F_21 ( V_6 -> V_5 , L_4 ) ;
return - V_34 ;
}
V_13 = F_17 ( V_6 , V_76 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_9 ;
}
static T_5 F_37 ( struct V_4 * V_5 ,
struct V_73 * V_74 ,
char * V_7 )
{
int V_13 ;
T_2 V_78 ;
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_13 = F_7 ( V_6 , & V_78 , V_79 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = sprintf ( V_7 , L_2 , V_78 & V_80 ) ;
return V_13 ;
}
static T_5 F_38 ( struct V_4 * V_5 ,
struct V_73 * V_74 ,
const char * V_7 ,
T_1 V_9 )
{
int V_13 ;
T_2 V_76 ;
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_13 = F_31 ( V_7 , 0 , & V_76 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ( V_76 != 0 ) && ( V_76 != 1 ) ) {
F_21 ( V_6 -> V_5 , L_5 ) ;
return - V_34 ;
}
V_13 = F_10 ( V_6 , & V_76 ,
V_79 , sizeof( T_2 ) ) ;
if ( V_13 < 0 )
return V_13 ;
return V_9 ;
}
static T_5 F_39 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_7 , T_6 V_87 , T_1 V_9 )
{
struct V_4 * V_5 = F_40 ( V_84 , struct V_4 , V_84 ) ;
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_9 ( V_6 , V_7 ,
V_88 + V_87 , V_9 ) ;
}
static T_5 F_41 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_7 , T_6 V_87 , T_1 V_9 )
{
struct V_4 * V_5 = F_40 ( V_84 , struct V_4 , V_84 ) ;
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_13 ;
V_13 = F_10 ( V_6 , V_7 ,
V_88 + V_87 , V_9 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_14 ( V_6 , V_88 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_9 ;
}
static T_5 F_42 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_7 , T_6 V_87 , T_1 V_9 )
{
struct V_4 * V_5 = F_40 ( V_84 , struct V_4 , V_84 ) ;
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_9 ( V_6 , V_7 ,
V_89 + V_87 , V_9 ) ;
}
static T_5 F_43 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_7 , T_6 V_87 , T_1 V_9 )
{
struct V_4 * V_5 = F_40 ( V_84 , struct V_4 , V_84 ) ;
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_13 ;
V_13 = F_10 ( V_6 , V_7 ,
V_89 + V_87 , V_9 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_14 ( V_6 , V_89 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_9 ;
}
static int F_44 ( struct V_90 * V_91 )
{
struct V_92 V_93 = {} ;
int V_13 = 0 ;
struct V_1 * V_6 ;
V_6 = F_45 ( & V_91 -> V_5 , sizeof( * V_6 ) , V_94 ) ;
if ( ! V_6 ) {
V_13 = - V_95 ;
goto V_96;
}
F_46 ( V_91 , V_6 ) ;
V_6 -> V_5 = & V_91 -> V_5 ;
V_6 -> V_11 = V_91 -> V_5 . V_97 ;
V_6 -> V_98 . V_99 = F_47 ( & V_91 -> V_5 ) ;
V_6 -> V_98 . type = V_100 ;
V_6 -> V_98 . V_101 = V_102 ;
V_6 -> V_98 . V_103 = F_48 ( V_102 ) ;
V_6 -> V_98 . V_104 = F_28 ;
V_93 . V_105 = V_6 ;
V_6 -> V_106 = F_49 ( & V_91 -> V_5 , & V_6 -> V_98 ,
& V_93 ) ;
if ( F_50 ( V_6 -> V_106 ) ) {
F_21 ( V_6 -> V_5 , L_6 ) ;
V_13 = F_51 ( V_6 -> V_106 ) ;
goto V_96;
}
V_13 = F_52 ( & V_6 -> V_106 -> V_5 . V_84 , & V_107 ) ;
if ( V_13 ) {
F_21 ( V_6 -> V_5 , L_7 ) ;
goto V_108;
}
V_13 = F_53 ( & V_6 -> V_106 -> V_5 . V_84 ,
& V_109 ) ;
if ( V_13 ) {
F_21 ( V_6 -> V_5 ,
L_8 ) ;
goto V_110;
}
V_13 = F_53 ( & V_6 -> V_106 -> V_5 . V_84 ,
& V_111 ) ;
if ( V_13 ) {
F_21 ( V_6 -> V_5 ,
L_9 ) ;
goto V_112;
}
return 0 ;
V_112:
F_54 ( & V_6 -> V_106 -> V_5 . V_84 ,
& V_109 ) ;
V_110:
F_55 ( & V_6 -> V_106 -> V_5 . V_84 , & V_107 ) ;
V_108:
F_56 ( V_6 -> V_106 ) ;
V_96:
return V_13 ;
}
static int F_57 ( struct V_90 * V_91 )
{
struct V_1 * V_6 = F_58 ( V_91 ) ;
F_55 ( & V_6 -> V_106 -> V_5 . V_84 , & V_107 ) ;
F_56 ( V_6 -> V_106 ) ;
return 0 ;
}
