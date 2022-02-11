static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_2 * F_3 ( struct V_5 * V_6 )
{
return F_4 ( V_6 ) ;
}
static inline int F_5 ( struct V_1 * V_7 ,
char * V_8 , int V_9 , T_1 V_10 , int V_11 )
{
return F_6 ( V_7 -> V_12 , V_8 , V_9 , V_10 , V_11 ) ;
}
static inline int F_7 ( struct V_1 * V_7 , T_2 * V_13 ,
int V_9 )
{
return F_5 ( V_7 , V_13 , V_9 , sizeof( T_2 ) , 0 ) ;
}
static int F_8 ( struct V_1 * V_7 , T_3 * V_13 ,
int V_9 )
{
int V_14 ;
T_2 V_15 [ 2 ] ;
V_14 = F_5 ( V_7 , V_15 , V_9 , sizeof( V_15 ) , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_13 = ( V_15 [ 0 ] << 8 ) | V_15 [ 1 ] ;
return 0 ;
}
static inline int F_9 ( struct V_1 * V_7 ,
T_2 * V_13 , int V_9 , T_1 V_10 )
{
return F_5 ( V_7 , V_13 , V_9 , V_10 , 0 ) ;
}
static inline int F_10 ( struct V_1 * V_7 , T_2 * V_13 ,
int V_9 , T_1 V_10 )
{
return F_5 ( V_7 , V_13 , V_9 , V_10 , 1 ) ;
}
static inline int F_11 ( struct V_5 * V_6 , int V_9 )
{
return F_12 ( V_6 , V_9 , V_16 ) ;
}
static inline int F_13 ( struct V_5 * V_6 , int V_9 )
{
return F_12 ( V_6 , V_9 , V_17 ) ;
}
static int F_14 ( struct V_1 * V_7 , int V_18 )
{
int V_14 ;
V_14 = F_11 ( V_7 -> V_12 , V_18 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_13 ( V_7 -> V_12 , V_18 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_7 ,
T_2 V_19 )
{
int V_14 ;
V_14 = F_10 ( V_7 , & V_19 ,
V_20 , sizeof( T_2 ) ) ;
if ( V_14 < 0 )
return V_14 ;
return F_14 ( V_7 , V_20 ) ;
}
static int F_16 ( struct V_1 * V_7 ,
T_4 * V_21 )
{
return F_8 ( V_7 , V_21 , V_22 ) ;
}
static int F_17 ( struct V_1 * V_7 ,
T_4 V_21 )
{
int V_14 ;
T_2 V_15 [] = { V_21 >> 8 , V_21 & 0xFF } ;
V_14 = F_10 ( V_7 , V_15 ,
V_22 , sizeof( V_15 ) ) ;
if ( V_14 < 0 )
return V_14 ;
return F_14 ( V_7 , V_22 ) ;
}
static int F_18 ( struct V_1 * V_7 ,
int * V_23 )
{
int V_14 ;
T_3 V_24 ;
V_14 = F_8 ( V_7 , & V_24 ,
V_25 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_23 = ( V_24 / 32 ) * 4880 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_7 ,
int * V_26 )
{
int V_14 ;
T_3 V_27 ;
V_14 = F_8 ( V_7 , & V_27 ,
V_28 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_26 = ( ( V_27 / 32 ) * 125 ) / 100 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_7 ,
enum V_29 type , int * V_30 )
{
int V_14 , V_31 ;
T_3 V_32 ;
T_2 V_33 , V_34 ;
V_14 = F_7 ( V_7 , & V_33 , V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_33 == 0 ) {
F_21 ( V_7 -> V_6 , L_1 ) ;
return - V_35 ;
}
V_31 = 1000 / V_33 ;
if ( type == V_36 )
V_34 = V_37 ;
else if ( type == V_38 )
V_34 = V_39 ;
else
return - V_35 ;
V_14 = F_8 ( V_7 , & V_32 , V_34 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_30 = V_32 * ( V_40 / V_31 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_7 ,
int * V_41 )
{
int V_14 , V_31 ;
T_3 V_32 ;
T_2 V_33 ;
V_14 = F_7 ( V_7 , & V_33 , V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_33 == 0 ) {
F_21 ( V_7 -> V_6 , L_1 ) ;
return - V_42 ;
}
V_31 = 1000 / V_33 ;
V_14 = F_8 ( V_7 , & V_32 , V_43 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_41 = V_32 * ( V_44 / V_31 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_7 ,
int * V_45 )
{
int V_14 ;
T_2 V_15 ;
V_14 = F_7 ( V_7 , & V_15 , V_46 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_45 = V_15 ;
return V_15 ;
}
static int F_24 ( struct V_1 * V_7 , int * V_47 )
{
int V_14 , V_30 , V_45 ;
V_14 = F_20 ( V_7 , V_36 , & V_30 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_23 ( V_7 , & V_45 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_45 == 100 )
* V_47 = V_48 ;
else if ( V_30 == 0 )
* V_47 = V_49 ;
else if ( V_30 < 0 )
* V_47 = V_50 ;
else
* V_47 = V_51 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_7 ,
int * V_52 )
{
int V_14 ;
T_4 V_53 ;
V_14 = F_8 ( V_7 , & V_53 , V_54 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_52 = V_53 * 1600 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_7 ,
T_2 * V_55 )
{
return F_7 ( V_7 , V_55 , V_56 ) ;
}
static int F_27 ( struct V_1 * V_7 ,
T_2 V_55 )
{
int V_14 ;
V_14 = F_10 ( V_7 , & V_55 ,
V_56 , sizeof( T_2 ) ) ;
if ( V_14 < 0 )
return V_14 ;
return F_14 ( V_7 , V_56 ) ;
}
static int F_28 ( struct V_2 * V_3 ,
enum V_57 V_58 ,
union V_59 * V_13 )
{
int V_14 = 0 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
switch ( V_58 ) {
case V_60 :
V_14 = F_18 ( V_7 , & V_13 -> V_61 ) ;
break;
case V_62 :
V_14 = F_19 ( V_7 , & V_13 -> V_61 ) ;
break;
case V_63 :
V_13 -> V_64 = V_65 ;
break;
case V_66 :
V_13 -> V_64 = V_67 ;
break;
case V_68 :
V_14 = F_20 ( V_7 , V_36 , & V_13 -> V_61 ) ;
break;
case V_69 :
V_14 = F_20 ( V_7 , V_38 , & V_13 -> V_61 ) ;
break;
case V_70 :
V_14 = F_24 ( V_7 , & V_13 -> V_61 ) ;
break;
case V_71 :
V_14 = F_23 ( V_7 , & V_13 -> V_61 ) ;
break;
case V_72 :
V_14 = F_22 ( V_7 , & V_13 -> V_61 ) ;
break;
case V_73 :
V_14 = F_25 ( V_7 , & V_13 -> V_61 ) ;
break;
default:
V_14 = - V_35 ;
}
return V_14 ;
}
static T_5 F_29 ( struct V_5 * V_6 ,
struct V_74 * V_75 ,
char * V_8 )
{
int V_14 ;
T_2 V_55 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_26 ( V_7 , & V_55 ) ;
if ( V_14 < 0 )
return V_14 ;
return sprintf ( V_8 , L_2 ,
! ! ( V_55 & V_76 ) ) ;
}
static T_5 F_30 ( struct V_5 * V_6 ,
struct V_74 * V_75 ,
const char * V_8 ,
T_1 V_10 )
{
int V_14 ;
T_2 V_55 , V_77 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_26 ( V_7 , & V_55 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_31 ( V_8 , 0 , & V_77 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( ( V_77 != 0 ) && ( V_77 != 1 ) ) {
F_21 ( V_7 -> V_6 , L_3 ) ;
return - V_35 ;
}
if ( V_77 )
V_55 |= V_76 ;
else
V_55 &= ~ V_76 ;
V_14 = F_27 ( V_7 , V_55 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_10 ;
}
static T_5 F_32 ( struct V_5 * V_6 ,
struct V_74 * V_75 ,
char * V_8 )
{
int V_14 ;
T_2 V_78 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_7 ( V_7 , & V_78 , V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = sprintf ( V_8 , L_2 , V_78 ) ;
return V_14 ;
}
static T_5 F_33 ( struct V_5 * V_6 ,
struct V_74 * V_75 ,
const char * V_8 ,
T_1 V_10 )
{
int V_14 ;
T_2 V_77 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_31 ( V_8 , 0 , & V_77 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_15 ( V_7 , V_77 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_10 ;
}
static T_5 F_34 ( struct V_5 * V_6 ,
struct V_74 * V_75 ,
char * V_8 )
{
int V_14 ;
T_4 V_21 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_16 ( V_7 , & V_21 ) ;
if ( V_14 < 0 )
return V_14 ;
return sprintf ( V_8 , L_2 , V_21 ) ;
}
static T_5 F_35 ( struct V_5 * V_6 ,
struct V_74 * V_75 ,
const char * V_8 ,
T_1 V_10 )
{
int V_14 ;
T_4 V_77 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_36 ( V_8 , 0 , & V_77 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_77 > 1999 ) {
F_21 ( V_7 -> V_6 , L_4 ) ;
return - V_35 ;
}
V_14 = F_17 ( V_7 , V_77 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_10 ;
}
static T_5 F_37 ( struct V_5 * V_6 ,
struct V_74 * V_75 ,
char * V_8 )
{
int V_14 ;
T_2 V_79 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_7 ( V_7 , & V_79 , V_80 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = sprintf ( V_8 , L_2 , V_79 & V_81 ) ;
return V_14 ;
}
static T_5 F_38 ( struct V_5 * V_6 ,
struct V_74 * V_75 ,
const char * V_8 ,
T_1 V_10 )
{
int V_14 ;
T_2 V_77 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_31 ( V_8 , 0 , & V_77 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( ( V_77 != 0 ) && ( V_77 != 1 ) ) {
F_21 ( V_7 -> V_6 , L_5 ) ;
return - V_35 ;
}
V_14 = F_10 ( V_7 , & V_77 ,
V_80 , sizeof( T_2 ) ) ;
if ( V_14 < 0 )
return V_14 ;
return V_10 ;
}
static T_5 F_39 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
struct V_86 * V_87 ,
char * V_8 , T_6 V_88 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_85 , struct V_5 , V_85 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_10 = F_40 ( T_6 , V_10 ,
V_89 -
V_90 + 1 - V_88 ) ;
return F_9 ( V_7 , V_8 ,
V_90 + V_88 , V_10 ) ;
}
static T_5 F_41 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
struct V_86 * V_87 ,
char * V_8 , T_6 V_88 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_85 , struct V_5 , V_85 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_14 ;
V_10 = F_40 ( T_6 , V_10 ,
V_89 -
V_90 + 1 - V_88 ) ;
V_14 = F_10 ( V_7 , V_8 ,
V_90 + V_88 , V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_14 ( V_7 , V_90 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_10 ;
}
static T_5 F_42 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
struct V_86 * V_87 ,
char * V_8 , T_6 V_88 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_85 , struct V_5 , V_85 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_10 = F_40 ( T_6 , V_10 ,
V_91 -
V_92 + 1 - V_88 ) ;
return F_9 ( V_7 , V_8 ,
V_92 + V_88 , V_10 ) ;
}
static T_5 F_43 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
struct V_86 * V_87 ,
char * V_8 , T_6 V_88 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_85 , struct V_5 , V_85 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_14 ;
V_10 = F_40 ( T_6 , V_10 ,
V_91 -
V_92 + 1 - V_88 ) ;
V_14 = F_10 ( V_7 , V_8 ,
V_92 + V_88 , V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_14 ( V_7 , V_92 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_10 ;
}
static int F_44 ( struct V_93 * V_94 )
{
int V_14 = 0 ;
struct V_1 * V_7 ;
V_7 = F_45 ( sizeof( * V_7 ) , V_95 ) ;
if ( ! V_7 ) {
V_14 = - V_96 ;
goto V_97;
}
F_46 ( V_94 , V_7 ) ;
V_7 -> V_6 = & V_94 -> V_6 ;
V_7 -> V_12 = V_94 -> V_6 . V_98 ;
V_7 -> V_4 . V_99 = F_47 ( & V_94 -> V_6 ) ;
V_7 -> V_4 . type = V_100 ;
V_7 -> V_4 . V_101 = V_102 ;
V_7 -> V_4 . V_103 = F_48 ( V_102 ) ;
V_7 -> V_4 . V_104 = F_28 ;
V_14 = F_49 ( & V_94 -> V_6 , & V_7 -> V_4 ) ;
if ( V_14 ) {
F_21 ( V_7 -> V_6 , L_6 ) ;
goto V_105;
}
V_14 = F_50 ( & V_7 -> V_4 . V_6 -> V_85 , & V_106 ) ;
if ( V_14 ) {
F_21 ( V_7 -> V_6 , L_7 ) ;
goto V_107;
}
V_14 = F_51 ( & V_7 -> V_4 . V_6 -> V_85 ,
& V_108 ) ;
if ( V_14 ) {
F_21 ( V_7 -> V_6 ,
L_8 ) ;
goto V_109;
}
V_14 = F_51 ( & V_7 -> V_4 . V_6 -> V_85 ,
& V_110 ) ;
if ( V_14 ) {
F_21 ( V_7 -> V_6 ,
L_9 ) ;
goto V_111;
}
return 0 ;
V_111:
F_52 ( & V_7 -> V_4 . V_6 -> V_85 ,
& V_108 ) ;
V_109:
F_53 ( & V_7 -> V_4 . V_6 -> V_85 , & V_106 ) ;
V_107:
F_54 ( & V_7 -> V_4 ) ;
V_105:
F_55 ( V_7 ) ;
V_97:
return V_14 ;
}
static int F_56 ( struct V_93 * V_94 )
{
struct V_1 * V_7 = F_57 ( V_94 ) ;
F_53 ( & V_7 -> V_4 . V_6 -> V_85 , & V_106 ) ;
F_54 ( & V_7 -> V_4 ) ;
F_55 ( V_7 ) ;
return 0 ;
}
