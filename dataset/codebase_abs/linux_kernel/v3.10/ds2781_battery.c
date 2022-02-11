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
static int F_7 ( struct V_1 * V_7 , char * V_8 ,
int V_9 , T_1 V_10 )
{
return F_5 ( V_7 , V_8 , V_9 , V_10 , 0 ) ;
}
static inline int F_8 ( struct V_1 * V_7 , T_2 * V_13 ,
int V_9 )
{
return F_5 ( V_7 , V_13 , V_9 , sizeof( T_2 ) , 0 ) ;
}
static int F_9 ( struct V_1 * V_7 , T_3 * V_13 ,
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
static inline int F_10 ( struct V_1 * V_7 ,
T_2 * V_13 , int V_9 , T_1 V_10 )
{
return F_5 ( V_7 , V_13 , V_9 , V_10 , 0 ) ;
}
static inline int F_11 ( struct V_1 * V_7 , T_2 * V_13 ,
int V_9 , T_1 V_10 )
{
return F_5 ( V_7 , V_13 , V_9 , V_10 , 1 ) ;
}
static inline int F_12 ( struct V_5 * V_6 , int V_9 )
{
return F_13 ( V_6 , V_9 , V_16 ) ;
}
static inline int F_14 ( struct V_5 * V_6 , int V_9 )
{
return F_13 ( V_6 , V_9 , V_17 ) ;
}
static int F_15 ( struct V_1 * V_7 , int V_18 )
{
int V_14 ;
V_14 = F_12 ( V_7 -> V_12 , V_18 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_14 ( V_7 -> V_12 , V_18 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_7 ,
T_2 V_19 )
{
int V_14 ;
V_14 = F_11 ( V_7 , & V_19 ,
V_20 , sizeof( T_2 ) ) ;
if ( V_14 < 0 )
return V_14 ;
return F_15 ( V_7 , V_20 ) ;
}
static int F_17 ( struct V_1 * V_7 ,
T_4 * V_21 )
{
return F_9 ( V_7 , V_21 , V_22 ) ;
}
static int F_18 ( struct V_1 * V_7 ,
T_4 V_21 )
{
int V_14 ;
T_2 V_15 [] = { V_21 >> 8 , V_21 & 0xFF } ;
V_14 = F_11 ( V_7 , V_15 ,
V_22 , sizeof( V_15 ) ) ;
if ( V_14 < 0 )
return V_14 ;
return F_15 ( V_7 , V_22 ) ;
}
static int F_19 ( struct V_1 * V_7 ,
int * V_23 )
{
int V_14 ;
char V_13 [ 2 ] ;
int V_24 ;
V_14 = F_7 ( V_7 , V_13 , V_25 , 2 * sizeof( T_2 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_24 = ( V_13 [ 0 ] << 3 ) |
( V_13 [ 1 ] >> 5 ) ;
* V_23 = V_24 * 9760 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_7 ,
int * V_26 )
{
int V_14 ;
char V_13 [ 2 ] ;
int V_27 ;
V_14 = F_7 ( V_7 , V_13 , V_28 , 2 * sizeof( T_2 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_27 = ( ( V_13 [ 0 ] ) << 3 ) |
( V_13 [ 1 ] >> 5 ) ;
* V_26 = V_27 + ( V_27 / 4 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_7 ,
enum V_29 type , int * V_30 )
{
int V_14 , V_31 ;
T_3 V_32 ;
T_2 V_33 , V_34 ;
V_14 = F_8 ( V_7 , & V_33 , V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_33 == 0 ) {
F_22 ( V_7 -> V_6 , L_1 ) ;
return - V_35 ;
}
V_31 = 1000 / V_33 ;
if ( type == V_36 )
V_34 = V_37 ;
else if ( type == V_38 )
V_34 = V_39 ;
else
return - V_35 ;
V_14 = F_9 ( V_7 , & V_32 , V_34 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_30 = V_32 * ( V_40 / V_31 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_7 ,
int * V_41 )
{
int V_14 , V_31 ;
T_3 V_32 ;
T_2 V_33 ;
V_14 = F_8 ( V_7 , & V_33 , V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_33 == 0 ) {
F_22 ( V_7 -> V_6 , L_1 ) ;
return - V_35 ;
}
V_31 = 1000 / V_33 ;
V_14 = F_9 ( V_7 , & V_32 , V_42 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_41 = V_32 * ( V_43 / V_31 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_7 ,
int * V_44 )
{
int V_14 ;
T_2 V_15 ;
V_14 = F_8 ( V_7 , & V_15 , V_45 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_44 = V_15 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_7 , int * V_46 )
{
int V_14 , V_30 , V_44 ;
V_14 = F_21 ( V_7 , V_36 , & V_30 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_24 ( V_7 , & V_44 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( F_26 ( & V_7 -> V_4 ) ) {
if ( V_44 == 100 )
* V_46 = V_47 ;
else if ( V_30 > 50000 )
* V_46 = V_48 ;
else
* V_46 = V_49 ;
} else {
* V_46 = V_50 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_7 ,
int * V_51 )
{
int V_14 ;
T_4 V_52 ;
V_14 = F_9 ( V_7 , & V_52 , V_53 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_51 = V_52 * 1600 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_7 ,
T_2 * V_54 )
{
return F_8 ( V_7 , V_54 , V_55 ) ;
}
static int F_29 ( struct V_1 * V_7 ,
T_2 V_54 )
{
int V_14 ;
V_14 = F_11 ( V_7 , & V_54 ,
V_55 , sizeof( T_2 ) ) ;
if ( V_14 < 0 )
return V_14 ;
return F_15 ( V_7 , V_55 ) ;
}
static int F_30 ( struct V_2 * V_3 ,
enum V_56 V_57 ,
union V_58 * V_13 )
{
int V_14 = 0 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
switch ( V_57 ) {
case V_59 :
V_14 = F_19 ( V_7 , & V_13 -> V_60 ) ;
break;
case V_61 :
V_14 = F_20 ( V_7 , & V_13 -> V_60 ) ;
break;
case V_62 :
V_13 -> V_63 = V_64 ;
break;
case V_65 :
V_13 -> V_63 = V_66 ;
break;
case V_67 :
V_14 = F_21 ( V_7 , V_36 , & V_13 -> V_60 ) ;
break;
case V_68 :
V_14 = F_21 ( V_7 , V_38 , & V_13 -> V_60 ) ;
break;
case V_69 :
V_14 = F_25 ( V_7 , & V_13 -> V_60 ) ;
break;
case V_70 :
V_14 = F_24 ( V_7 , & V_13 -> V_60 ) ;
break;
case V_71 :
V_14 = F_23 ( V_7 , & V_13 -> V_60 ) ;
break;
case V_72 :
V_14 = F_27 ( V_7 , & V_13 -> V_60 ) ;
break;
default:
V_14 = - V_35 ;
}
return V_14 ;
}
static T_5 F_31 ( struct V_5 * V_6 ,
struct V_73 * V_74 ,
char * V_8 )
{
int V_14 ;
T_2 V_54 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_28 ( V_7 , & V_54 ) ;
if ( V_14 < 0 )
return V_14 ;
return sprintf ( V_8 , L_2 ,
! ! ( V_54 & V_75 ) ) ;
}
static T_5 F_32 ( struct V_5 * V_6 ,
struct V_73 * V_74 ,
const char * V_8 ,
T_1 V_10 )
{
int V_14 ;
T_2 V_54 , V_76 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_28 ( V_7 , & V_54 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_33 ( V_8 , 0 , & V_76 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( ( V_76 != 0 ) && ( V_76 != 1 ) ) {
F_22 ( V_7 -> V_6 , L_3 ) ;
return - V_35 ;
}
if ( V_76 )
V_54 |= V_75 ;
else
V_54 &= ~ V_75 ;
V_14 = F_29 ( V_7 , V_54 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_10 ;
}
static T_5 F_34 ( struct V_5 * V_6 ,
struct V_73 * V_74 ,
char * V_8 )
{
int V_14 ;
T_2 V_77 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_8 ( V_7 , & V_77 , V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = sprintf ( V_8 , L_2 , V_77 ) ;
return V_14 ;
}
static T_5 F_35 ( struct V_5 * V_6 ,
struct V_73 * V_74 ,
const char * V_8 ,
T_1 V_10 )
{
int V_14 ;
T_2 V_76 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_33 ( V_8 , 0 , & V_76 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_16 ( V_7 , V_76 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_10 ;
}
static T_5 F_36 ( struct V_5 * V_6 ,
struct V_73 * V_74 ,
char * V_8 )
{
int V_14 ;
T_4 V_21 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_17 ( V_7 , & V_21 ) ;
if ( V_14 < 0 )
return V_14 ;
return sprintf ( V_8 , L_2 , V_21 ) ;
}
static T_5 F_37 ( struct V_5 * V_6 ,
struct V_73 * V_74 ,
const char * V_8 ,
T_1 V_10 )
{
int V_14 ;
T_4 V_76 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_38 ( V_8 , 0 , & V_76 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_76 > 1999 ) {
F_22 ( V_7 -> V_6 , L_4 ) ;
return - V_35 ;
}
V_14 = F_18 ( V_7 , V_76 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_10 ;
}
static T_5 F_39 ( struct V_5 * V_6 ,
struct V_73 * V_74 ,
char * V_8 )
{
int V_14 ;
T_2 V_78 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_8 ( V_7 , & V_78 , V_79 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = sprintf ( V_8 , L_2 , V_78 & V_80 ) ;
return V_14 ;
}
static T_5 F_40 ( struct V_5 * V_6 ,
struct V_73 * V_74 ,
const char * V_8 ,
T_1 V_10 )
{
int V_14 ;
T_2 V_76 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 = F_33 ( V_8 , 0 , & V_76 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( ( V_76 != 0 ) && ( V_76 != 1 ) ) {
F_22 ( V_7 -> V_6 , L_5 ) ;
return - V_35 ;
}
V_14 = F_11 ( V_7 , & V_76 ,
V_79 , sizeof( T_2 ) ) ;
if ( V_14 < 0 )
return V_14 ;
return V_10 ;
}
static T_5 F_41 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_8 , T_6 V_87 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_84 , struct V_5 , V_84 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_10 = F_42 ( T_6 , V_10 , V_88 - V_87 ) ;
return F_10 ( V_7 , V_8 ,
V_89 + V_87 , V_10 ) ;
}
static T_5 F_43 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_8 , T_6 V_87 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_84 , struct V_5 , V_84 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_14 ;
V_10 = F_42 ( T_6 , V_10 , V_88 - V_87 ) ;
V_14 = F_11 ( V_7 , V_8 ,
V_89 + V_87 , V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_15 ( V_7 , V_89 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_10 ;
}
static T_5 F_44 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_8 , T_6 V_87 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_84 , struct V_5 , V_84 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_10 = F_42 ( T_6 , V_10 , V_90 - V_87 ) ;
return F_10 ( V_7 , V_8 ,
V_91 + V_87 , V_10 ) ;
}
static T_5 F_45 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_8 , T_6 V_87 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_84 , struct V_5 , V_84 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_14 ;
V_10 = F_42 ( T_6 , V_10 , V_90 - V_87 ) ;
V_14 = F_11 ( V_7 , V_8 ,
V_91 + V_87 , V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_15 ( V_7 , V_91 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_10 ;
}
static int F_46 ( struct V_92 * V_93 )
{
int V_14 = 0 ;
struct V_1 * V_7 ;
V_7 = F_47 ( & V_93 -> V_6 , sizeof( * V_7 ) , V_94 ) ;
if ( ! V_7 )
return - V_95 ;
F_48 ( V_93 , V_7 ) ;
V_7 -> V_6 = & V_93 -> V_6 ;
V_7 -> V_12 = V_93 -> V_6 . V_96 ;
V_7 -> V_4 . V_97 = F_49 ( & V_93 -> V_6 ) ;
V_7 -> V_4 . type = V_98 ;
V_7 -> V_4 . V_99 = V_100 ;
V_7 -> V_4 . V_101 = F_50 ( V_100 ) ;
V_7 -> V_4 . V_102 = F_30 ;
V_14 = F_51 ( & V_93 -> V_6 , & V_7 -> V_4 ) ;
if ( V_14 ) {
F_22 ( V_7 -> V_6 , L_6 ) ;
goto V_103;
}
V_14 = F_52 ( & V_7 -> V_4 . V_6 -> V_84 , & V_104 ) ;
if ( V_14 ) {
F_22 ( V_7 -> V_6 , L_7 ) ;
goto V_105;
}
V_14 = F_53 ( & V_7 -> V_4 . V_6 -> V_84 ,
& V_106 ) ;
if ( V_14 ) {
F_22 ( V_7 -> V_6 ,
L_8 ) ;
goto V_107;
}
V_14 = F_53 ( & V_7 -> V_4 . V_6 -> V_84 ,
& V_108 ) ;
if ( V_14 ) {
F_22 ( V_7 -> V_6 ,
L_9 ) ;
goto V_109;
}
return 0 ;
V_109:
F_54 ( & V_7 -> V_4 . V_6 -> V_84 ,
& V_106 ) ;
V_107:
F_55 ( & V_7 -> V_4 . V_6 -> V_84 , & V_104 ) ;
V_105:
F_56 ( & V_7 -> V_4 ) ;
V_103:
return V_14 ;
}
static int F_57 ( struct V_92 * V_93 )
{
struct V_1 * V_7 = F_58 ( V_93 ) ;
F_55 ( & V_7 -> V_4 . V_6 -> V_84 , & V_104 ) ;
F_56 ( & V_7 -> V_4 ) ;
return 0 ;
}
