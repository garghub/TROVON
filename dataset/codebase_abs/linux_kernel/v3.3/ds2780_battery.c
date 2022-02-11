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
if ( V_7 -> V_12 == V_13 )
return F_6 ( V_7 -> V_14 , V_8 , V_9 , V_10 , V_11 ) ;
else
return F_7 ( V_7 -> V_14 , V_8 , V_9 , V_10 , V_11 ) ;
}
static inline int F_8 ( struct V_1 * V_7 , T_2 * V_15 ,
int V_9 )
{
return F_5 ( V_7 , V_15 , V_9 , sizeof( T_2 ) , 0 ) ;
}
static int F_9 ( struct V_1 * V_7 , T_3 * V_15 ,
int V_9 )
{
int V_16 ;
T_2 V_17 [ 2 ] ;
V_16 = F_5 ( V_7 , V_17 , V_9 , sizeof( V_17 ) , 0 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_15 = ( V_17 [ 0 ] << 8 ) | V_17 [ 1 ] ;
return 0 ;
}
static inline int F_10 ( struct V_1 * V_7 ,
T_2 * V_15 , int V_9 , T_1 V_10 )
{
return F_5 ( V_7 , V_15 , V_9 , V_10 , 0 ) ;
}
static inline int F_11 ( struct V_1 * V_7 , T_2 * V_15 ,
int V_9 , T_1 V_10 )
{
return F_5 ( V_7 , V_15 , V_9 , V_10 , 1 ) ;
}
static inline int F_12 ( struct V_5 * V_6 , int V_9 )
{
return F_13 ( V_6 , V_9 , V_18 ) ;
}
static inline int F_14 ( struct V_5 * V_6 , int V_9 )
{
return F_13 ( V_6 , V_9 , V_19 ) ;
}
static int F_15 ( struct V_1 * V_7 , int V_20 )
{
int V_16 ;
V_16 = F_12 ( V_7 -> V_14 , V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_14 ( V_7 -> V_14 , V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_7 ,
T_2 V_21 )
{
int V_16 ;
V_16 = F_11 ( V_7 , & V_21 ,
V_22 , sizeof( T_2 ) ) ;
if ( V_16 < 0 )
return V_16 ;
return F_15 ( V_7 , V_22 ) ;
}
static int F_17 ( struct V_1 * V_7 ,
T_4 * V_23 )
{
return F_9 ( V_7 , V_23 , V_24 ) ;
}
static int F_18 ( struct V_1 * V_7 ,
T_4 V_23 )
{
int V_16 ;
T_2 V_17 [] = { V_23 >> 8 , V_23 & 0xFF } ;
V_16 = F_11 ( V_7 , V_17 ,
V_24 , sizeof( V_17 ) ) ;
if ( V_16 < 0 )
return V_16 ;
return F_15 ( V_7 , V_24 ) ;
}
static int F_19 ( struct V_1 * V_7 ,
int * V_25 )
{
int V_16 ;
T_3 V_26 ;
V_16 = F_9 ( V_7 , & V_26 ,
V_27 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_25 = ( V_26 / 32 ) * 4880 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_7 ,
int * V_28 )
{
int V_16 ;
T_3 V_29 ;
V_16 = F_9 ( V_7 , & V_29 ,
V_30 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_28 = ( ( V_29 / 32 ) * 125 ) / 100 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_7 ,
enum V_31 type , int * V_32 )
{
int V_16 , V_33 ;
T_3 V_34 ;
T_2 V_35 , V_36 ;
V_16 = F_8 ( V_7 , & V_35 , V_22 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_35 == 0 ) {
F_22 ( V_7 -> V_6 , L_1 ) ;
return - V_37 ;
}
V_33 = 1000 / V_35 ;
if ( type == V_38 )
V_36 = V_39 ;
else if ( type == V_40 )
V_36 = V_41 ;
else
return - V_37 ;
V_16 = F_9 ( V_7 , & V_34 , V_36 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_32 = V_34 * ( V_42 / V_33 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_7 ,
int * V_43 )
{
int V_16 , V_33 ;
T_3 V_34 ;
T_2 V_35 ;
V_16 = F_8 ( V_7 , & V_35 , V_22 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_35 == 0 ) {
F_22 ( V_7 -> V_6 , L_1 ) ;
return - V_44 ;
}
V_33 = 1000 / V_35 ;
V_16 = F_9 ( V_7 , & V_34 , V_45 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_43 = V_34 * ( V_46 / V_33 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_7 ,
int * V_47 )
{
int V_16 ;
T_2 V_17 ;
V_16 = F_8 ( V_7 , & V_17 , V_48 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_47 = V_17 ;
return V_17 ;
}
static int F_25 ( struct V_1 * V_7 , int * V_49 )
{
int V_16 , V_32 , V_47 ;
V_16 = F_21 ( V_7 , V_38 , & V_32 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_24 ( V_7 , & V_47 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_47 == 100 )
* V_49 = V_50 ;
else if ( V_32 == 0 )
* V_49 = V_51 ;
else if ( V_32 < 0 )
* V_49 = V_52 ;
else
* V_49 = V_53 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_7 ,
int * V_54 )
{
int V_16 ;
T_4 V_55 ;
V_16 = F_9 ( V_7 , & V_55 , V_56 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_54 = V_55 * 1600 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_7 ,
T_2 * V_57 )
{
return F_8 ( V_7 , V_57 , V_58 ) ;
}
static int F_28 ( struct V_1 * V_7 ,
T_2 V_57 )
{
int V_16 ;
V_16 = F_11 ( V_7 , & V_57 ,
V_58 , sizeof( T_2 ) ) ;
if ( V_16 < 0 )
return V_16 ;
return F_15 ( V_7 , V_58 ) ;
}
static int F_29 ( struct V_2 * V_3 ,
enum V_59 V_60 ,
union V_61 * V_15 )
{
int V_16 = 0 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
switch ( V_60 ) {
case V_62 :
V_16 = F_19 ( V_7 , & V_15 -> V_63 ) ;
break;
case V_64 :
V_16 = F_20 ( V_7 , & V_15 -> V_63 ) ;
break;
case V_65 :
V_15 -> V_66 = V_67 ;
break;
case V_68 :
V_15 -> V_66 = V_69 ;
break;
case V_70 :
V_16 = F_21 ( V_7 , V_38 , & V_15 -> V_63 ) ;
break;
case V_71 :
V_16 = F_21 ( V_7 , V_40 , & V_15 -> V_63 ) ;
break;
case V_72 :
V_16 = F_25 ( V_7 , & V_15 -> V_63 ) ;
break;
case V_73 :
V_16 = F_24 ( V_7 , & V_15 -> V_63 ) ;
break;
case V_74 :
V_16 = F_23 ( V_7 , & V_15 -> V_63 ) ;
break;
case V_75 :
V_16 = F_26 ( V_7 , & V_15 -> V_63 ) ;
break;
default:
V_16 = - V_37 ;
}
return V_16 ;
}
static T_5 F_30 ( struct V_5 * V_6 ,
struct V_76 * V_77 ,
char * V_8 )
{
int V_16 ;
T_2 V_57 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_27 ( V_7 , & V_57 ) ;
if ( V_16 < 0 )
return V_16 ;
return sprintf ( V_8 , L_2 ,
! ! ( V_57 & V_78 ) ) ;
}
static T_5 F_31 ( struct V_5 * V_6 ,
struct V_76 * V_77 ,
const char * V_8 ,
T_1 V_10 )
{
int V_16 ;
T_2 V_57 , V_79 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_27 ( V_7 , & V_57 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_32 ( V_8 , 0 , & V_79 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ( V_79 != 0 ) && ( V_79 != 1 ) ) {
F_22 ( V_7 -> V_6 , L_3 ) ;
return - V_37 ;
}
if ( V_79 )
V_57 |= V_78 ;
else
V_57 &= ~ V_78 ;
V_16 = F_28 ( V_7 , V_57 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_10 ;
}
static T_5 F_33 ( struct V_5 * V_6 ,
struct V_76 * V_77 ,
char * V_8 )
{
int V_16 ;
T_2 V_80 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_8 ( V_7 , & V_80 , V_22 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = sprintf ( V_8 , L_2 , V_80 ) ;
return V_16 ;
}
static T_5 F_34 ( struct V_5 * V_6 ,
struct V_76 * V_77 ,
const char * V_8 ,
T_1 V_10 )
{
int V_16 ;
T_2 V_79 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_32 ( V_8 , 0 , & V_79 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_16 ( V_7 , V_79 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_10 ;
}
static T_5 F_35 ( struct V_5 * V_6 ,
struct V_76 * V_77 ,
char * V_8 )
{
int V_16 ;
T_4 V_23 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_17 ( V_7 , & V_23 ) ;
if ( V_16 < 0 )
return V_16 ;
return sprintf ( V_8 , L_2 , V_23 ) ;
}
static T_5 F_36 ( struct V_5 * V_6 ,
struct V_76 * V_77 ,
const char * V_8 ,
T_1 V_10 )
{
int V_16 ;
T_4 V_79 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_37 ( V_8 , 0 , & V_79 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_79 > 1999 ) {
F_22 ( V_7 -> V_6 , L_4 ) ;
return - V_37 ;
}
V_16 = F_18 ( V_7 , V_79 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_10 ;
}
static T_5 F_38 ( struct V_5 * V_6 ,
struct V_76 * V_77 ,
char * V_8 )
{
int V_16 ;
T_2 V_81 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_8 ( V_7 , & V_81 , V_82 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = sprintf ( V_8 , L_2 , V_81 & V_83 ) ;
return V_16 ;
}
static T_5 F_39 ( struct V_5 * V_6 ,
struct V_76 * V_77 ,
const char * V_8 ,
T_1 V_10 )
{
int V_16 ;
T_2 V_79 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_32 ( V_8 , 0 , & V_79 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ( V_79 != 0 ) && ( V_79 != 1 ) ) {
F_22 ( V_7 -> V_6 , L_5 ) ;
return - V_37 ;
}
V_16 = F_11 ( V_7 , & V_79 ,
V_82 , sizeof( T_2 ) ) ;
if ( V_16 < 0 )
return V_16 ;
return V_10 ;
}
static T_5 F_40 ( struct V_84 * V_85 ,
struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_8 , T_6 V_90 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_87 , struct V_5 , V_87 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_10 = F_41 ( T_6 , V_10 ,
V_91 -
V_92 + 1 - V_90 ) ;
return F_10 ( V_7 , V_8 ,
V_92 + V_90 , V_10 ) ;
}
static T_5 F_42 ( struct V_84 * V_85 ,
struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_8 , T_6 V_90 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_87 , struct V_5 , V_87 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_16 ;
V_10 = F_41 ( T_6 , V_10 ,
V_91 -
V_92 + 1 - V_90 ) ;
V_16 = F_11 ( V_7 , V_8 ,
V_92 + V_90 , V_10 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_15 ( V_7 , V_92 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_10 ;
}
static T_5 F_43 ( struct V_84 * V_85 ,
struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_8 , T_6 V_90 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_87 , struct V_5 , V_87 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_10 = F_41 ( T_6 , V_10 ,
V_93 -
V_94 + 1 - V_90 ) ;
return F_10 ( V_7 , V_8 ,
V_94 + V_90 , V_10 ) ;
}
static T_5 F_44 ( struct V_84 * V_85 ,
struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_8 , T_6 V_90 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_87 , struct V_5 , V_87 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_16 ;
V_10 = F_41 ( T_6 , V_10 ,
V_93 -
V_94 + 1 - V_90 ) ;
V_16 = F_11 ( V_7 , V_8 ,
V_94 + V_90 , V_10 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_15 ( V_7 , V_94 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_10 ;
}
static int T_7 F_45 ( struct V_95 * V_96 )
{
int V_16 = 0 ;
struct V_1 * V_7 ;
V_7 = F_46 ( sizeof( * V_7 ) , V_97 ) ;
if ( ! V_7 ) {
V_16 = - V_98 ;
goto V_99;
}
F_47 ( V_96 , V_7 ) ;
V_7 -> V_6 = & V_96 -> V_6 ;
V_7 -> V_14 = V_96 -> V_6 . V_100 ;
V_7 -> V_4 . V_101 = F_48 ( & V_96 -> V_6 ) ;
V_7 -> V_4 . type = V_102 ;
V_7 -> V_4 . V_103 = V_104 ;
V_7 -> V_4 . V_105 = F_49 ( V_104 ) ;
V_7 -> V_4 . V_106 = F_29 ;
V_7 -> V_12 = V_13 ;
V_16 = F_50 ( & V_96 -> V_6 , & V_7 -> V_4 ) ;
if ( V_16 ) {
F_22 ( V_7 -> V_6 , L_6 ) ;
goto V_107;
}
V_16 = F_51 ( & V_7 -> V_4 . V_6 -> V_87 , & V_108 ) ;
if ( V_16 ) {
F_22 ( V_7 -> V_6 , L_7 ) ;
goto V_109;
}
V_16 = F_52 ( & V_7 -> V_4 . V_6 -> V_87 ,
& V_110 ) ;
if ( V_16 ) {
F_22 ( V_7 -> V_6 ,
L_8 ) ;
goto V_111;
}
V_16 = F_52 ( & V_7 -> V_4 . V_6 -> V_87 ,
& V_112 ) ;
if ( V_16 ) {
F_22 ( V_7 -> V_6 ,
L_9 ) ;
goto V_113;
}
V_7 -> V_12 = NULL ;
return 0 ;
V_113:
F_53 ( & V_7 -> V_4 . V_6 -> V_87 ,
& V_110 ) ;
V_111:
F_54 ( & V_7 -> V_4 . V_6 -> V_87 , & V_108 ) ;
V_109:
F_55 ( & V_7 -> V_4 ) ;
V_107:
F_56 ( V_7 ) ;
V_99:
return V_16 ;
}
static int T_8 F_57 ( struct V_95 * V_96 )
{
struct V_1 * V_7 = F_58 ( V_96 ) ;
V_7 -> V_12 = V_13 ;
F_54 ( & V_7 -> V_4 . V_6 -> V_87 , & V_108 ) ;
F_55 ( & V_7 -> V_4 ) ;
F_56 ( V_7 ) ;
return 0 ;
}
