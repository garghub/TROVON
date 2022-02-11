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
return F_6 ( V_7 -> V_14 , V_8 , V_9 ,
V_10 , V_11 ) ;
else
return F_7 ( V_7 -> V_14 , V_8 , V_9 , V_10 , V_11 ) ;
}
int F_8 ( struct V_1 * V_7 , char * V_8 ,
int V_9 , T_1 V_10 )
{
return F_5 ( V_7 , V_8 , V_9 , V_10 , 0 ) ;
}
static inline int F_9 ( struct V_1 * V_7 , T_2 * V_15 ,
int V_9 )
{
return F_5 ( V_7 , V_15 , V_9 , sizeof( T_2 ) , 0 ) ;
}
static int F_10 ( struct V_1 * V_7 , T_3 * V_15 ,
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
static inline int F_11 ( struct V_1 * V_7 ,
T_2 * V_15 , int V_9 , T_1 V_10 )
{
return F_5 ( V_7 , V_15 , V_9 , V_10 , 0 ) ;
}
static inline int F_12 ( struct V_1 * V_7 , T_2 * V_15 ,
int V_9 , T_1 V_10 )
{
return F_5 ( V_7 , V_15 , V_9 , V_10 , 1 ) ;
}
static inline int F_13 ( struct V_5 * V_6 , int V_9 )
{
return F_14 ( V_6 , V_9 , V_18 ) ;
}
static inline int F_15 ( struct V_5 * V_6 , int V_9 )
{
return F_14 ( V_6 , V_9 , V_19 ) ;
}
static int F_16 ( struct V_1 * V_7 , int V_20 )
{
int V_16 ;
V_16 = F_13 ( V_7 -> V_14 , V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_15 ( V_7 -> V_14 , V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_7 ,
T_2 V_21 )
{
int V_16 ;
V_16 = F_12 ( V_7 , & V_21 ,
V_22 , sizeof( T_2 ) ) ;
if ( V_16 < 0 )
return V_16 ;
return F_16 ( V_7 , V_22 ) ;
}
static int F_18 ( struct V_1 * V_7 ,
T_4 * V_23 )
{
return F_10 ( V_7 , V_23 , V_24 ) ;
}
static int F_19 ( struct V_1 * V_7 ,
T_4 V_23 )
{
int V_16 ;
T_2 V_17 [] = { V_23 >> 8 , V_23 & 0xFF } ;
V_16 = F_12 ( V_7 , V_17 ,
V_24 , sizeof( V_17 ) ) ;
if ( V_16 < 0 )
return V_16 ;
return F_16 ( V_7 , V_24 ) ;
}
static int F_20 ( struct V_1 * V_7 ,
int * V_25 )
{
int V_16 ;
char V_15 [ 2 ] ;
int V_26 ;
V_16 = F_8 ( V_7 , V_15 , V_27 , 2 * sizeof( T_2 ) ) ;
if ( V_16 < 0 )
return V_16 ;
V_26 = ( V_15 [ 0 ] << 3 ) |
( V_15 [ 1 ] >> 5 ) ;
* V_25 = V_26 * 9760 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_7 ,
int * V_28 )
{
int V_16 ;
char V_15 [ 2 ] ;
int V_29 ;
V_16 = F_8 ( V_7 , V_15 , V_30 , 2 * sizeof( T_2 ) ) ;
if ( V_16 < 0 )
return V_16 ;
V_29 = ( ( V_15 [ 0 ] ) << 3 ) |
( V_15 [ 1 ] >> 5 ) ;
* V_28 = V_29 + ( V_29 / 4 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_7 ,
enum V_31 type , int * V_32 )
{
int V_16 , V_33 ;
T_3 V_34 ;
T_2 V_35 , V_36 ;
V_16 = F_9 ( V_7 , & V_35 , V_22 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_35 == 0 ) {
F_23 ( V_7 -> V_6 , L_1 ) ;
return - V_37 ;
}
V_33 = 1000 / V_35 ;
if ( type == V_38 )
V_36 = V_39 ;
else if ( type == V_40 )
V_36 = V_41 ;
else
return - V_37 ;
V_16 = F_10 ( V_7 , & V_34 , V_36 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_32 = V_34 * ( V_42 / V_33 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_7 ,
int * V_43 )
{
int V_16 , V_33 ;
T_3 V_34 ;
T_2 V_35 ;
V_16 = F_9 ( V_7 , & V_35 , V_22 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_35 == 0 ) {
F_23 ( V_7 -> V_6 , L_1 ) ;
return - V_37 ;
}
V_33 = 1000 / V_35 ;
V_16 = F_10 ( V_7 , & V_34 , V_44 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_43 = V_34 * ( V_45 / V_33 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_7 ,
int * V_46 )
{
int V_16 ;
T_2 V_17 ;
V_16 = F_9 ( V_7 , & V_17 , V_47 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_46 = V_17 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_7 , int * V_48 )
{
int V_16 , V_32 , V_46 ;
V_16 = F_22 ( V_7 , V_38 , & V_32 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_25 ( V_7 , & V_46 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( F_27 ( & V_7 -> V_4 ) ) {
if ( V_46 == 100 )
* V_48 = V_49 ;
else if ( V_32 > 50000 )
* V_48 = V_50 ;
else
* V_48 = V_51 ;
} else {
* V_48 = V_52 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_7 ,
int * V_53 )
{
int V_16 ;
T_4 V_54 ;
V_16 = F_10 ( V_7 , & V_54 , V_55 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_53 = V_54 * 1600 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_7 ,
T_2 * V_56 )
{
return F_9 ( V_7 , V_56 , V_57 ) ;
}
static int F_30 ( struct V_1 * V_7 ,
T_2 V_56 )
{
int V_16 ;
V_16 = F_12 ( V_7 , & V_56 ,
V_57 , sizeof( T_2 ) ) ;
if ( V_16 < 0 )
return V_16 ;
return F_16 ( V_7 , V_57 ) ;
}
static int F_31 ( struct V_2 * V_3 ,
enum V_58 V_59 ,
union V_60 * V_15 )
{
int V_16 = 0 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
switch ( V_59 ) {
case V_61 :
V_16 = F_20 ( V_7 , & V_15 -> V_62 ) ;
break;
case V_63 :
V_16 = F_21 ( V_7 , & V_15 -> V_62 ) ;
break;
case V_64 :
V_15 -> V_65 = V_66 ;
break;
case V_67 :
V_15 -> V_65 = V_68 ;
break;
case V_69 :
V_16 = F_22 ( V_7 , V_38 , & V_15 -> V_62 ) ;
break;
case V_70 :
V_16 = F_22 ( V_7 , V_40 , & V_15 -> V_62 ) ;
break;
case V_71 :
V_16 = F_26 ( V_7 , & V_15 -> V_62 ) ;
break;
case V_72 :
V_16 = F_25 ( V_7 , & V_15 -> V_62 ) ;
break;
case V_73 :
V_16 = F_24 ( V_7 , & V_15 -> V_62 ) ;
break;
case V_74 :
V_16 = F_28 ( V_7 , & V_15 -> V_62 ) ;
break;
default:
V_16 = - V_37 ;
}
return V_16 ;
}
static T_5 F_32 ( struct V_5 * V_6 ,
struct V_75 * V_76 ,
char * V_8 )
{
int V_16 ;
T_2 V_56 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_29 ( V_7 , & V_56 ) ;
if ( V_16 < 0 )
return V_16 ;
return sprintf ( V_8 , L_2 ,
! ! ( V_56 & V_77 ) ) ;
}
static T_5 F_33 ( struct V_5 * V_6 ,
struct V_75 * V_76 ,
const char * V_8 ,
T_1 V_10 )
{
int V_16 ;
T_2 V_56 , V_78 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_29 ( V_7 , & V_56 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_34 ( V_8 , 0 , & V_78 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ( V_78 != 0 ) && ( V_78 != 1 ) ) {
F_23 ( V_7 -> V_6 , L_3 ) ;
return - V_37 ;
}
if ( V_78 )
V_56 |= V_77 ;
else
V_56 &= ~ V_77 ;
V_16 = F_30 ( V_7 , V_56 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_10 ;
}
static T_5 F_35 ( struct V_5 * V_6 ,
struct V_75 * V_76 ,
char * V_8 )
{
int V_16 ;
T_2 V_79 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_9 ( V_7 , & V_79 , V_22 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = sprintf ( V_8 , L_2 , V_79 ) ;
return V_16 ;
}
static T_5 F_36 ( struct V_5 * V_6 ,
struct V_75 * V_76 ,
const char * V_8 ,
T_1 V_10 )
{
int V_16 ;
T_2 V_78 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_34 ( V_8 , 0 , & V_78 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_17 ( V_7 , V_78 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_10 ;
}
static T_5 F_37 ( struct V_5 * V_6 ,
struct V_75 * V_76 ,
char * V_8 )
{
int V_16 ;
T_4 V_23 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_18 ( V_7 , & V_23 ) ;
if ( V_16 < 0 )
return V_16 ;
return sprintf ( V_8 , L_2 , V_23 ) ;
}
static T_5 F_38 ( struct V_5 * V_6 ,
struct V_75 * V_76 ,
const char * V_8 ,
T_1 V_10 )
{
int V_16 ;
T_4 V_78 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_39 ( V_8 , 0 , & V_78 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_78 > 1999 ) {
F_23 ( V_7 -> V_6 , L_4 ) ;
return - V_37 ;
}
V_16 = F_19 ( V_7 , V_78 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_10 ;
}
static T_5 F_40 ( struct V_5 * V_6 ,
struct V_75 * V_76 ,
char * V_8 )
{
int V_16 ;
T_2 V_80 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_9 ( V_7 , & V_80 , V_81 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = sprintf ( V_8 , L_2 , V_80 & V_82 ) ;
return V_16 ;
}
static T_5 F_41 ( struct V_5 * V_6 ,
struct V_75 * V_76 ,
const char * V_8 ,
T_1 V_10 )
{
int V_16 ;
T_2 V_78 ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_16 = F_34 ( V_8 , 0 , & V_78 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ( V_78 != 0 ) && ( V_78 != 1 ) ) {
F_23 ( V_7 -> V_6 , L_5 ) ;
return - V_37 ;
}
V_16 = F_12 ( V_7 , & V_78 ,
V_81 , sizeof( T_2 ) ) ;
if ( V_16 < 0 )
return V_16 ;
return V_10 ;
}
static T_5 F_42 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_8 , T_6 V_89 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_86 , struct V_5 , V_86 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_10 = F_43 ( T_6 , V_10 ,
V_90 -
V_91 + 1 - V_89 ) ;
return F_11 ( V_7 , V_8 ,
V_91 + V_89 , V_10 ) ;
}
static T_5 F_44 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_8 , T_6 V_89 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_86 , struct V_5 , V_86 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_16 ;
V_10 = F_43 ( T_6 , V_10 ,
V_90 -
V_91 + 1 - V_89 ) ;
V_16 = F_12 ( V_7 , V_8 ,
V_91 + V_89 , V_10 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_16 ( V_7 , V_91 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_10 ;
}
static T_5 F_45 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_8 , T_6 V_89 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_86 , struct V_5 , V_86 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_10 = F_43 ( T_6 , V_10 ,
V_92 -
V_93 + 1 - V_89 ) ;
return F_11 ( V_7 , V_8 ,
V_93 + V_89 , V_10 ) ;
}
static T_5 F_46 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_8 , T_6 V_89 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_86 , struct V_5 , V_86 ) ;
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_16 ;
V_10 = F_43 ( T_6 , V_10 ,
V_92 -
V_93 + 1 - V_89 ) ;
V_16 = F_12 ( V_7 , V_8 ,
V_93 + V_89 , V_10 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_16 ( V_7 , V_93 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_10 ;
}
static int T_7 F_47 ( struct V_94 * V_95 )
{
int V_16 = 0 ;
struct V_1 * V_7 ;
V_7 = F_48 ( sizeof( * V_7 ) , V_96 ) ;
if ( ! V_7 ) {
V_16 = - V_97 ;
goto V_98;
}
F_49 ( V_95 , V_7 ) ;
V_7 -> V_6 = & V_95 -> V_6 ;
V_7 -> V_14 = V_95 -> V_6 . V_99 ;
V_7 -> V_4 . V_100 = F_50 ( & V_95 -> V_6 ) ;
V_7 -> V_4 . type = V_101 ;
V_7 -> V_4 . V_102 = V_103 ;
V_7 -> V_4 . V_104 = F_51 ( V_103 ) ;
V_7 -> V_4 . V_105 = F_31 ;
V_7 -> V_12 = V_13 ;
V_16 = F_52 ( & V_95 -> V_6 , & V_7 -> V_4 ) ;
if ( V_16 ) {
F_23 ( V_7 -> V_6 , L_6 ) ;
goto V_106;
}
V_16 = F_53 ( & V_7 -> V_4 . V_6 -> V_86 , & V_107 ) ;
if ( V_16 ) {
F_23 ( V_7 -> V_6 , L_7 ) ;
goto V_108;
}
V_16 = F_54 ( & V_7 -> V_4 . V_6 -> V_86 ,
& V_109 ) ;
if ( V_16 ) {
F_23 ( V_7 -> V_6 ,
L_8 ) ;
goto V_110;
}
V_16 = F_54 ( & V_7 -> V_4 . V_6 -> V_86 ,
& V_111 ) ;
if ( V_16 ) {
F_23 ( V_7 -> V_6 ,
L_9 ) ;
goto V_112;
}
V_7 -> V_12 = NULL ;
return 0 ;
V_112:
F_55 ( & V_7 -> V_4 . V_6 -> V_86 ,
& V_109 ) ;
V_110:
F_56 ( & V_7 -> V_4 . V_6 -> V_86 , & V_107 ) ;
V_108:
F_57 ( & V_7 -> V_4 ) ;
V_106:
F_58 ( V_7 ) ;
V_98:
return V_16 ;
}
static int T_8 F_59 ( struct V_94 * V_95 )
{
struct V_1 * V_7 = F_60 ( V_95 ) ;
V_7 -> V_12 = V_13 ;
F_56 ( & V_7 -> V_4 . V_6 -> V_86 , & V_107 ) ;
F_57 ( & V_7 -> V_4 ) ;
F_58 ( V_7 ) ;
return 0 ;
}
static int T_9 F_61 ( void )
{
return F_62 ( & V_113 ) ;
}
static void T_10 F_63 ( void )
{
F_64 ( & V_113 ) ;
}
