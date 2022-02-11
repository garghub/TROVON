static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 )
{
unsigned int V_5 ;
F_2 ( V_2 , V_3 , 0 , V_6 , V_4 ) ;
V_5 = F_3 ( V_2 , V_3 , 0 , V_7 , 0 ) ;
return V_5 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 , unsigned int V_8 )
{
F_2 ( V_2 , V_3 , 0 , V_6 , V_4 ) ;
F_2 ( V_2 , V_3 , 0 , V_9 , V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 , unsigned int V_10 ,
unsigned int V_11 )
{
unsigned int V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_5 != - 1 )
F_4 ( V_2 , V_3 , V_4 ,
( V_5 & ~ V_10 ) | V_11 ) ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( ! V_13 -> V_14 )
V_13 -> V_14 = F_7 ( V_2 , 0 ) ;
return V_13 -> V_14 ;
}
static void F_8 ( struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
for (; V_16 -> V_3 ; V_16 ++ ) {
if ( V_16 -> V_10 == ( unsigned short ) - 1 )
F_4 ( V_2 , V_16 -> V_3 , V_16 -> V_17 , V_16 -> V_5 ) ;
else
F_5 ( V_2 , V_16 -> V_3 , V_16 -> V_17 ,
V_16 -> V_10 , V_16 -> V_5 ) ;
}
}
static void F_9 ( struct V_12 * V_13 , const struct V_18 * V_19 )
{
if ( F_10 ( V_13 -> V_20 >= F_11 ( V_13 -> V_21 ) ) )
return;
V_13 -> V_21 [ V_13 -> V_20 ++ ] = V_19 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_22 )
F_5 ( V_2 , V_13 -> V_22 , V_13 -> V_23 ,
1 << V_13 -> V_24 , 0 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 , unsigned int V_25 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_22 = V_3 ;
V_13 -> V_23 = V_4 ;
V_13 -> V_24 = V_25 ;
F_12 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
unsigned int V_5 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
V_29 = F_15 ( V_2 , L_1 ) ;
if ( ! V_29 )
return;
V_31 = F_16 ( sizeof( * V_31 ) , V_32 ) ;
if ( ! V_31 )
return;
V_5 = F_3 ( V_2 , V_27 -> V_33 -> V_3 , 0 ,
V_34 , 0 ) ;
V_5 &= V_35 ;
V_31 -> V_36 . integer . V_36 [ 0 ] = V_5 ;
V_31 -> V_36 . integer . V_36 [ 1 ] = V_5 ;
V_29 -> V_37 ( V_29 , V_31 ) ;
F_17 ( V_31 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_38 )
{
F_19 ( V_2 , V_38 >> 2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
int V_39 ;
V_39 = F_6 ( V_2 ) ;
switch ( V_2 -> V_40 . V_41 ) {
case 0x10ec0262 :
F_21 ( V_2 , 0x7 , 0 , 1 << 5 ) ;
break;
case 0x10ec0267 :
case 0x10ec0268 :
F_21 ( V_2 , 0x7 , 0 , 1 << 13 ) ;
break;
case 0x10ec0269 :
if ( ( V_39 & 0x00f0 ) == 0x0010 )
F_21 ( V_2 , 0xd , 0 , 1 << 14 ) ;
if ( ( V_39 & 0x00f0 ) == 0x0020 )
F_21 ( V_2 , 0x4 , 1 << 15 , 0 ) ;
if ( ( V_39 & 0x00f0 ) == 0x0030 )
F_21 ( V_2 , 0x10 , 1 << 9 , 0 ) ;
break;
case 0x10ec0280 :
case 0x10ec0284 :
case 0x10ec0290 :
case 0x10ec0292 :
F_21 ( V_2 , 0x4 , 1 << 15 , 0 ) ;
break;
case 0x10ec0233 :
case 0x10ec0255 :
case 0x10ec0256 :
case 0x10ec0282 :
case 0x10ec0283 :
case 0x10ec0286 :
case 0x10ec0288 :
case 0x10ec0298 :
F_21 ( V_2 , 0x10 , 1 << 9 , 0 ) ;
break;
case 0x10ec0285 :
case 0x10ec0293 :
F_21 ( V_2 , 0xa , 1 << 13 , 0 ) ;
break;
case 0x10ec0662 :
if ( ( V_39 & 0x00f0 ) == 0x0030 )
F_21 ( V_2 , 0x4 , 1 << 10 , 0 ) ;
break;
case 0x10ec0272 :
case 0x10ec0273 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0670 :
case 0x10ec0671 :
case 0x10ec0672 :
F_21 ( V_2 , 0xd , 0 , 1 << 14 ) ;
break;
case 0x10ec0668 :
F_21 ( V_2 , 0x7 , 3 << 13 , 0 ) ;
break;
case 0x10ec0867 :
F_21 ( V_2 , 0x4 , 1 << 10 , 0 ) ;
break;
case 0x10ec0888 :
if ( ( V_39 & 0x00f0 ) == 0x0020 || ( V_39 & 0x00f0 ) == 0x0030 )
F_21 ( V_2 , 0x7 , 1 << 5 , 0 ) ;
break;
case 0x10ec0892 :
F_21 ( V_2 , 0x7 , 1 << 5 , 0 ) ;
break;
case 0x10ec0899 :
case 0x10ec0900 :
F_21 ( V_2 , 0x7 , 1 << 1 , 0 ) ;
break;
}
}
static void F_22 ( struct V_1 * V_2 )
{
switch ( F_6 ( V_2 ) & 0x00f0 ) {
case 0x00 :
case 0x10 :
F_21 ( V_2 , 7 , 0 , 0x2030 ) ;
break;
}
}
static void F_23 ( struct V_1 * V_2 , T_1 V_3 , int V_42 )
{
if ( F_24 ( F_25 ( V_2 , V_3 ) ) != V_43 )
return;
if ( F_26 ( V_2 , V_3 ) & V_44 )
F_2 ( V_2 , V_3 , 0 , V_45 ,
V_42 ? 2 : 0 ) ;
}
static void F_27 ( struct V_1 * V_2 , bool V_42 )
{
static T_1 V_46 [] = {
0x0f , 0x10 , 0x14 , 0x15 , 0x17 , 0
} ;
T_1 * V_47 ;
for ( V_47 = V_46 ; * V_47 ; V_47 ++ )
F_23 ( V_2 , * V_47 , V_42 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_27 ( V_2 , false ) ;
if ( ! V_13 -> V_48 )
F_29 ( 200 ) ;
F_30 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 , int type )
{
F_20 ( V_2 ) ;
F_27 ( V_2 , true ) ;
switch ( type ) {
case V_49 :
F_32 ( V_2 , V_50 ) ;
break;
case V_51 :
F_32 ( V_2 , V_52 ) ;
break;
case V_53 :
F_32 ( V_2 , V_54 ) ;
break;
case V_55 :
switch ( V_2 -> V_40 . V_41 ) {
case 0x10ec0260 :
F_5 ( V_2 , 0x1a , 7 , 0 , 0x2010 ) ;
break;
case 0x10ec0880 :
case 0x10ec0882 :
case 0x10ec0883 :
case 0x10ec0885 :
F_21 ( V_2 , 7 , 0 , 0x2030 ) ;
break;
case 0x10ec0888 :
F_22 ( V_2 ) ;
break;
}
break;
}
}
static void F_33 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_59 ) {
V_13 -> V_60 . V_61 = 1 ;
V_13 -> V_60 . V_62 = V_63 ;
}
}
static void F_34 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_64 ) {
V_13 -> V_48 = 1 ;
V_2 -> V_65 = 0 ;
}
}
static int F_35 ( struct V_1 * V_2 )
{
unsigned int V_66 , V_67 , V_68 ;
unsigned V_3 = 0 ;
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_60 . V_69 = 1 ;
if ( V_13 -> V_60 . V_61 ) {
V_66 = V_13 -> V_60 . V_62 ;
if ( V_66 == V_63 )
return - 1 ;
goto V_70;
}
if ( ! V_2 -> V_71 -> V_72 )
return - 1 ;
V_66 = V_2 -> V_40 . V_73 & 0xffff ;
if ( V_66 != V_2 -> V_71 -> V_72 -> V_74 && ( V_66 & 1 ) )
goto V_70;
V_3 = 0x1d ;
if ( V_2 -> V_40 . V_41 == 0x10ec0260 )
V_3 = 0x17 ;
V_66 = F_36 ( V_2 , V_3 ) ;
if ( ! ( V_66 & 1 ) ) {
F_37 ( V_2 , L_2 ,
V_2 -> V_40 . V_75 , V_66 ) ;
return - 1 ;
}
V_67 = 0 ;
for ( V_68 = 1 ; V_68 < 16 ; V_68 ++ ) {
if ( ( V_66 >> V_68 ) & 1 )
V_67 ++ ;
}
if ( ( ( V_66 >> 16 ) & 0xf ) != V_67 )
return - 1 ;
V_13 -> V_60 . V_76 = V_66 >> 30 ;
V_13 -> V_60 . V_69 = ( V_66 & 0x100000 ) >> 20 ;
V_13 -> V_60 . V_77 = ( V_66 >> 16 ) & 0xf ;
V_13 -> V_60 . V_78 = V_66 >> 8 ;
V_70:
V_13 -> V_60 . V_62 = V_66 ;
V_13 -> V_60 . V_79 = ( V_66 & 0x38 ) >> 3 ;
V_13 -> V_60 . V_80 = ( V_66 & 0x4 ) >> 2 ;
V_13 -> V_60 . V_81 = ( V_66 & 0x2 ) >> 1 ;
V_13 -> V_60 . V_82 = V_66 & 0x1 ;
F_38 ( V_2 , L_3 ,
V_3 , V_13 -> V_60 . V_62 ) ;
F_38 ( V_2 , L_4 ,
V_13 -> V_60 . V_76 ) ;
F_38 ( V_2 , L_5 , V_13 -> V_60 . V_69 ) ;
F_38 ( V_2 , L_6 , V_13 -> V_60 . V_77 ) ;
F_38 ( V_2 , L_7 , V_13 -> V_60 . V_78 ) ;
F_38 ( V_2 , L_8 , V_13 -> V_60 . V_79 ) ;
F_38 ( V_2 , L_9 , V_13 -> V_60 . V_80 ) ;
F_38 ( V_2 , L_10 , V_13 -> V_60 . V_81 ) ;
F_38 ( V_2 , L_11 , V_13 -> V_60 . V_82 ) ;
return 0 ;
}
static int F_39 ( T_1 V_3 , const T_1 * V_83 , int V_84 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_84 ; V_68 ++ )
if ( V_83 [ V_68 ] == V_3 )
return V_68 ;
return - 1 ;
}
static bool F_40 ( T_1 V_3 , const T_1 * V_83 , int V_84 )
{
return F_39 ( V_3 , V_83 , V_84 ) >= 0 ;
}
static int F_41 ( struct V_1 * V_2 , const T_1 * V_85 )
{
unsigned int V_66 , V_67 , V_68 ;
unsigned V_3 ;
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_60 . V_61 ) {
V_66 = V_13 -> V_60 . V_62 ;
if ( V_66 == V_63 )
return 0 ;
goto V_70;
}
V_66 = V_2 -> V_40 . V_73 & 0xffff ;
if ( V_2 -> V_71 -> V_72 &&
V_66 != V_2 -> V_71 -> V_72 -> V_74 && ( V_66 & 1 ) )
goto V_70;
V_3 = 0x1d ;
if ( V_2 -> V_40 . V_41 == 0x10ec0260 )
V_3 = 0x17 ;
V_66 = F_36 ( V_2 , V_3 ) ;
F_38 ( V_2 ,
L_12 ,
V_66 , V_3 ) ;
if ( ! ( V_66 & 1 ) )
return 0 ;
if ( ( V_66 >> 30 ) != 1 )
return 0 ;
V_67 = 0 ;
for ( V_68 = 1 ; V_68 < 16 ; V_68 ++ ) {
if ( ( V_66 >> V_68 ) & 1 )
V_67 ++ ;
}
if ( ( ( V_66 >> 16 ) & 0xf ) != V_67 )
return 0 ;
V_70:
F_38 ( V_2 , L_13 ,
V_66 & 0xffff , V_2 -> V_40 . V_41 ) ;
V_67 = ( V_66 & 0x38 ) >> 3 ;
switch ( V_67 ) {
case 1 :
V_13 -> V_86 = V_49 ;
break;
case 3 :
V_13 -> V_86 = V_51 ;
break;
case 7 :
V_13 -> V_86 = V_53 ;
break;
case 5 :
default:
V_13 -> V_86 = V_55 ;
break;
}
if ( ! ( V_66 & 0x8000 ) )
return 1 ;
if ( ! V_13 -> V_87 . V_88 . V_89 [ 0 ] &&
! ( V_13 -> V_87 . V_88 . V_90 [ 0 ] &&
V_13 -> V_87 . V_88 . V_91 == V_92 ) ) {
T_1 V_3 ;
V_67 = ( V_66 >> 11 ) & 0x3 ;
V_3 = V_85 [ V_67 ] ;
if ( F_40 ( V_3 , V_13 -> V_87 . V_88 . V_90 ,
V_13 -> V_87 . V_88 . V_93 ) )
return 1 ;
V_13 -> V_87 . V_88 . V_89 [ 0 ] = V_3 ;
}
return 1 ;
}
static void F_42 ( struct V_1 * V_2 , const T_1 * V_85 )
{
if ( ! F_41 ( V_2 , V_85 ) ) {
struct V_12 * V_13 = V_2 -> V_13 ;
F_38 ( V_2 ,
L_14 ) ;
V_13 -> V_86 = V_55 ;
}
}
static void F_43 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_87 . V_94 = 1 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_68 , V_95 ;
V_95 = F_45 ( V_2 ) ;
if ( V_95 < 0 )
return V_95 ;
for ( V_68 = 0 ; V_68 < V_13 -> V_20 ; V_68 ++ ) {
V_95 = F_46 ( V_2 , V_13 -> V_21 [ V_68 ] ) ;
if ( V_95 < 0 )
return V_95 ;
}
#ifdef F_47
if ( V_13 -> V_96 ) {
const struct V_18 * V_97 ;
for ( V_97 = V_98 ; V_97 -> V_99 ; V_97 ++ ) {
struct V_28 * V_29 ;
V_29 = F_48 ( V_97 , V_2 ) ;
if ( ! V_29 )
return - V_100 ;
V_29 -> V_101 = V_13 -> V_96 ;
V_95 = F_49 ( V_2 , 0 , V_29 ) ;
if ( V_95 < 0 )
return V_95 ;
}
}
#endif
F_50 ( V_2 , V_102 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_103 )
V_13 -> V_103 ( V_2 ) ;
F_12 ( V_2 ) ;
F_31 ( V_2 , V_13 -> V_86 ) ;
F_52 ( V_2 ) ;
F_50 ( V_2 , V_104 ) ;
return 0 ;
}
static inline void F_53 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 && V_13 -> V_105 )
V_13 -> V_105 ( V_2 ) ;
else
F_30 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_27 ( V_2 , false ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_53 ( V_2 ) ;
if ( V_13 && V_13 -> V_106 )
V_13 -> V_106 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( ! V_13 -> V_48 )
F_29 ( 150 ) ;
V_2 -> V_107 . V_108 ( V_2 ) ;
F_57 ( V_2 -> V_40 . V_109 ) ;
F_58 ( V_2 , 0x01 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , const char * V_99 )
{
F_17 ( V_2 -> V_40 . V_75 ) ;
V_2 -> V_40 . V_75 = F_60 ( V_99 , V_32 ) ;
if ( ! V_2 -> V_40 . V_75 ) {
F_61 ( V_2 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
const struct V_110 * V_47 ;
const struct V_111 * V_112 ;
for ( V_47 = V_113 ; V_47 -> V_41 ; V_47 ++ ) {
if ( V_47 -> V_41 != V_2 -> V_40 . V_41 )
continue;
if ( ( F_6 ( V_2 ) & V_47 -> V_114 ) == V_47 -> V_115 )
return F_59 ( V_2 , V_47 -> V_99 ) ;
}
if ( ! V_2 -> V_71 -> V_72 )
return 0 ;
for ( V_112 = V_116 ; V_112 -> V_117 ; V_112 ++ ) {
if ( V_112 -> V_117 != V_2 -> V_40 . V_41 )
continue;
if ( V_112 -> V_118 != V_2 -> V_71 -> V_72 -> V_119 )
continue;
if ( ! V_112 -> V_120 ||
V_112 -> V_120 == V_2 -> V_71 -> V_72 -> V_74 )
return F_59 ( V_2 , V_112 -> V_99 ) ;
}
return 0 ;
}
static inline int F_63 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
const struct V_121 * V_112 ;
V_112 = F_64 ( V_2 -> V_71 -> V_72 , V_122 ) ;
if ( V_112 )
return V_112 -> V_36 ;
return V_13 -> V_60 . V_69 ;
}
static int F_65 ( struct V_1 * V_2 ,
const T_1 * V_123 ,
const T_1 * V_124 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_125 * V_126 = & V_13 -> V_87 . V_88 ;
int V_95 ;
V_95 = F_66 ( V_2 , V_126 , V_123 ,
V_13 -> V_127 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( V_124 )
F_42 ( V_2 , V_124 ) ;
V_95 = F_67 ( V_2 , V_126 ) ;
if ( V_95 < 0 )
return V_95 ;
return 1 ;
}
static int F_68 ( struct V_1 * V_2 , T_1 V_128 )
{
struct V_12 * V_13 = F_16 ( sizeof( * V_13 ) , V_32 ) ;
int V_95 ;
if ( ! V_13 )
return - V_100 ;
V_2 -> V_13 = V_13 ;
F_69 ( & V_13 -> V_87 ) ;
V_13 -> V_87 . V_128 = V_128 ;
V_13 -> V_87 . V_129 = 1 ;
V_2 -> V_130 = 1 ;
V_2 -> V_131 = 1 ;
V_95 = F_62 ( V_2 ) ;
if ( V_95 < 0 ) {
F_17 ( V_13 ) ;
return V_95 ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
static const T_1 V_132 [] = { 0x1d , 0 } ;
static const T_1 V_133 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_65 ( V_2 , V_132 , V_133 ) ;
}
static void F_71 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_64 )
F_72 ( V_2 , 0x21 ,
F_14 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_95 ;
V_95 = F_68 ( V_2 , 0x0b ) ;
if ( V_95 < 0 )
return V_95 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_87 . V_134 = 1 ;
V_13 -> V_87 . V_135 = 0x01 ;
F_74 ( V_2 , V_136 , V_137 ,
V_138 ) ;
F_50 ( V_2 , V_59 ) ;
V_95 = F_70 ( V_2 ) ;
if ( V_95 < 0 )
goto error;
if ( ! V_13 -> V_87 . V_139 )
F_75 ( V_13 , 0x0b , 0x05 , V_140 ) ;
V_2 -> V_107 = V_141 ;
V_2 -> V_107 . V_142 = F_18 ;
F_50 ( V_2 , V_64 ) ;
return 0 ;
error:
F_61 ( V_2 ) ;
return V_95 ;
}
static int F_76 ( struct V_1 * V_2 )
{
static const T_1 V_143 [] = { 0x17 , 0 } ;
static const T_1 V_144 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_65 ( V_2 , V_143 , V_144 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_2 ( V_2 , 0x01 , 0 , V_145 ,
V_13 -> V_87 . V_146 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_64 ) {
V_13 -> V_87 . V_147 = F_77 ;
V_13 -> V_87 . V_148 = 1 ;
V_13 -> V_87 . V_149 = 1 ;
V_13 -> V_87 . V_88 . V_89 [ 0 ] = 0x0f ;
F_72 ( V_2 , 0x0f ,
V_150 ) ;
F_79 ( V_2 , V_50 ) ;
}
}
static void F_80 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_151 V_152 [] = {
{ 0x0f , 0x02214000 } ,
{ 0x12 , 0x90a60160 } ,
{ 0x13 , 0x02a19000 } ,
{ 0x18 , 0x01446000 } ,
{ 0x10 , 0x411111f0 } ,
{ 0x11 , 0x411111f0 } ,
{ 0x14 , 0x411111f0 } ,
{ 0x15 , 0x411111f0 } ,
{ 0x16 , 0x411111f0 } ,
{ 0x17 , 0x411111f0 } ,
{ 0x19 , 0x411111f0 } ,
{ }
} ;
switch ( V_58 ) {
case V_59 :
F_81 ( V_2 , V_152 ) ;
break;
case V_64 :
V_13 -> V_86 = V_153 ;
break;
}
}
static void F_82 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_64 )
V_13 -> V_86 = V_153 ;
}
static void F_83 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_59 ) {
V_13 -> V_87 . V_154 = 1 ;
V_13 -> V_87 . V_155 = 1 ;
}
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_95 ;
V_95 = F_68 ( V_2 , 0x07 ) ;
if ( V_95 < 0 )
return V_95 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_87 . V_156 = 1 ;
V_13 -> V_87 . V_135 = 0x01 ;
F_74 ( V_2 , V_157 , V_158 ,
V_159 ) ;
F_50 ( V_2 , V_59 ) ;
V_95 = F_76 ( V_2 ) ;
if ( V_95 < 0 )
goto error;
if ( ! V_13 -> V_87 . V_139 )
F_75 ( V_13 , 0x07 , 0x05 , V_140 ) ;
V_2 -> V_107 = V_141 ;
V_13 -> V_105 = F_28 ;
F_50 ( V_2 , V_64 ) ;
return 0 ;
error:
F_61 ( V_2 ) ;
return V_95 ;
}
static void F_85 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 != V_104 )
return;
F_21 ( V_2 , 7 , 0 , 0x2030 ) ;
}
static void F_86 ( struct V_1 * V_2 , int V_160 , int V_161 )
{
unsigned int V_162 , V_163 , V_164 ;
V_162 = F_3 ( V_2 , V_2 -> V_40 . V_165 , 0 ,
V_166 , 0 ) ;
if ( ! V_161 )
V_162 |= ( 1 << V_160 ) ;
else
V_162 &= ~ ( 1 << V_160 ) ;
V_163 = F_3 ( V_2 , V_2 -> V_40 . V_165 , 0 ,
V_167 , 0 ) ;
V_163 |= ( 1 << V_160 ) ;
V_164 = F_3 ( V_2 , V_2 -> V_40 . V_165 , 0 ,
V_168 , 0 ) ;
V_164 |= ( 1 << V_160 ) ;
F_2 ( V_2 , V_2 -> V_40 . V_165 , 0 ,
V_169 , V_163 ) ;
F_2 ( V_2 , V_2 -> V_40 . V_165 , 0 ,
V_170 , V_164 ) ;
F_29 ( 1 ) ;
F_2 ( V_2 , V_2 -> V_40 . V_165 , 0 ,
V_145 , V_162 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 != V_104 )
return;
F_86 ( V_2 , 0 , 0 ) ;
F_86 ( V_2 , 1 , 0 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_59 ) {
T_1 V_171 [ 2 ] = { 0x0c , 0x0d } ;
T_1 V_172 [ 2 ] = { 0x0e , 0x0f } ;
F_89 ( V_2 , 0x14 , 2 , V_171 ) ;
F_89 ( V_2 , 0x15 , 2 , V_171 ) ;
F_89 ( V_2 , 0x18 , 2 , V_172 ) ;
F_89 ( V_2 , 0x1a , 2 , V_172 ) ;
} else if ( V_58 == V_64 ) {
T_1 V_173 [ 5 ] = { 0x0c , 0x0d , 0x0e , 0x0f , 0x26 } ;
F_89 ( V_2 , 0x14 , 5 , V_173 ) ;
F_89 ( V_2 , 0x15 , 5 , V_173 ) ;
F_89 ( V_2 , 0x18 , 5 , V_173 ) ;
F_89 ( V_2 , 0x1a , 5 , V_173 ) ;
}
}
static void F_90 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static T_1 V_174 [ 2 ] = { 0x14 , 0x15 } ;
int V_68 ;
if ( V_58 != V_104 )
return;
for ( V_68 = 0 ; V_68 < F_11 ( V_174 ) ; V_68 ++ ) {
unsigned int V_5 = F_36 ( V_2 , V_174 [ V_68 ] ) ;
if ( F_91 ( V_5 ) != V_175 )
continue;
V_5 = F_92 ( V_2 , V_174 [ V_68 ] ) ;
V_5 |= V_176 ;
F_93 ( V_2 , V_174 [ V_68 ] , V_5 ) ;
V_13 -> V_87 . V_177 = 1 ;
break;
}
}
static void F_94 ( struct V_1 * V_2 ,
const T_1 * V_174 , int V_178 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_178 ; V_68 ++ ) {
unsigned int V_5 ;
V_5 = F_92 ( V_2 , V_174 [ V_68 ] ) ;
V_5 |= V_179 ;
F_93 ( V_2 , V_174 [ V_68 ] , V_5 ) ;
}
V_13 -> V_87 . V_177 = 1 ;
}
static void F_95 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
static T_1 V_174 [ 2 ] = { 0x18 , 0x1a } ;
if ( V_58 == V_104 )
F_94 ( V_2 , V_174 , F_11 ( V_174 ) ) ;
}
static void F_96 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
static T_1 V_174 [ 1 ] = { 0x18 } ;
if ( V_58 == V_104 )
F_94 ( V_2 , V_174 , F_11 ( V_174 ) ) ;
}
static void F_97 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
static T_1 V_174 [ 2 ] = { 0x18 , 0x19 } ;
if ( V_58 == V_104 )
F_94 ( V_2 , V_174 , F_11 ( V_174 ) ) ;
}
static void F_98 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_59 ) {
V_13 -> V_87 . V_180 = 1 ;
V_13 -> V_87 . V_181 = 1 ;
}
}
static int F_99 ( struct V_1 * V_2 )
{
static const T_1 V_182 [] = { 0x1d , 0 } ;
static const T_1 V_183 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_65 ( V_2 , V_182 , V_183 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_95 ;
V_95 = F_68 ( V_2 , 0x0b ) ;
if ( V_95 < 0 )
return V_95 ;
V_13 = V_2 -> V_13 ;
switch ( V_2 -> V_40 . V_41 ) {
case 0x10ec0882 :
case 0x10ec0885 :
case 0x10ec0900 :
break;
default:
F_13 ( V_2 , 0x20 , 0x0a , 10 ) ;
break;
}
F_74 ( V_2 , V_184 , V_185 ,
V_186 ) ;
F_50 ( V_2 , V_59 ) ;
F_35 ( V_2 ) ;
if ( F_63 ( V_2 ) )
V_13 -> V_87 . V_135 = 0x01 ;
V_95 = F_99 ( V_2 ) ;
if ( V_95 < 0 )
goto error;
if ( ! V_13 -> V_87 . V_139 && V_13 -> V_87 . V_135 )
F_75 ( V_13 , 0x0b , 0x05 , V_140 ) ;
V_2 -> V_107 = V_141 ;
F_50 ( V_2 , V_64 ) ;
return 0 ;
error:
F_61 ( V_2 ) ;
return V_95 ;
}
static int F_101 ( struct V_1 * V_2 )
{
static const T_1 V_187 [] = { 0x1d , 0 } ;
static const T_1 V_188 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_65 ( V_2 , V_187 , V_188 ) ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_95 ;
V_95 = F_68 ( V_2 , 0x0b ) ;
if ( V_95 < 0 )
return V_95 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_87 . V_189 = 0x18 ;
#if 0
alc_update_coefex_idx(codec, 0x1a, 7, 0, 0x80);
#endif
F_13 ( V_2 , 0x20 , 0x0a , 10 ) ;
F_74 ( V_2 , V_190 , V_191 ,
V_192 ) ;
F_50 ( V_2 , V_59 ) ;
F_35 ( V_2 ) ;
if ( F_63 ( V_2 ) )
V_13 -> V_87 . V_135 = 0x01 ;
V_95 = F_101 ( V_2 ) ;
if ( V_95 < 0 )
goto error;
if ( ! V_13 -> V_87 . V_139 && V_13 -> V_87 . V_135 )
F_75 ( V_13 , 0x0b , 0x05 , V_140 ) ;
V_2 -> V_107 = V_141 ;
V_13 -> V_105 = F_28 ;
F_50 ( V_2 , V_64 ) ;
return 0 ;
error:
F_61 ( V_2 ) ;
return V_95 ;
}
static int F_103 ( struct V_1 * V_2 )
{
static const T_1 V_193 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_65 ( V_2 , NULL , V_193 ) ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_95 ;
V_95 = F_68 ( V_2 , 0 ) ;
if ( V_95 < 0 )
return V_95 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_87 . V_135 = 0x01 ;
F_74 ( V_2 , V_194 , V_195 , V_196 ) ;
F_50 ( V_2 , V_59 ) ;
V_95 = F_103 ( V_2 ) ;
if ( V_95 < 0 )
goto error;
if ( V_95 > 0 && ! V_13 -> V_87 . V_139 &&
V_13 -> V_87 . V_88 . V_197 [ 0 ] != 0x1d ) {
F_9 ( V_13 , V_198 ) ;
F_79 ( V_2 , V_199 ) ;
if ( ! F_105 ( V_2 , 0x1d , V_140 ) )
F_106 ( V_2 , 0x1d , V_140 ,
( 0x0c << V_200 ) |
( 0x0c << V_201 ) |
( 0x07 << V_202 ) |
( 0 << V_203 ) ) ;
}
V_2 -> V_107 = V_141 ;
V_13 -> V_105 = F_28 ;
F_50 ( V_2 , V_64 ) ;
return 0 ;
error:
F_61 ( V_2 ) ;
return V_95 ;
}
static int F_107 ( struct V_1 * V_2 )
{
static const T_1 V_204 [] = { 0x1d , 0 } ;
static const T_1 V_205 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_206 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_12 * V_13 = V_2 -> V_13 ;
const T_1 * V_207 ;
switch ( V_13 -> V_208 ) {
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
V_207 = V_206 ;
break;
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
V_207 = V_205 ;
break;
default:
V_207 = V_205 ;
break;
}
return F_65 ( V_2 , V_204 , V_207 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
int V_68 ;
int V_222 = F_109 ( V_2 ) ;
if ( V_2 -> V_71 -> V_223 )
return;
for ( V_68 = 0 ; V_68 < V_2 -> V_224 . V_225 ; V_68 ++ ) {
struct V_226 * V_160 = F_110 ( & V_2 -> V_224 , V_68 ) ;
if ( V_160 -> V_3 != V_222 )
F_3 ( V_2 , V_160 -> V_3 , 0 ,
V_227 , 0 ) ;
}
V_2 -> V_228 = 1 ;
}
static void F_111 ( struct V_1 * V_2 , int V_229 )
{
F_21 ( V_2 , 0x04 , 1 << 11 , V_229 ? ( 1 << 11 ) : 0 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_208 == V_214 )
F_111 ( V_2 , 0 ) ;
if ( V_13 -> V_208 == V_214 &&
( F_6 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_29 ( 150 ) ;
}
F_30 ( V_2 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_230 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_231 = V_13 -> V_87 . V_88 . V_89 [ 0 ] ;
bool V_232 ;
int V_233 ;
F_113 ( V_2 ) ;
if ( ! V_231 )
return;
V_232 = F_115 ( V_2 , V_231 ) ;
V_233 = F_7 ( V_2 , 0x78 ) ;
F_116 ( V_2 , 0x78 , 0x9004 ) ;
if ( V_232 )
F_29 ( 2 ) ;
F_2 ( V_2 , V_231 , 0 ,
V_234 , V_235 ) ;
if ( V_232 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_231 , 0 ,
V_227 , V_236 ) ;
if ( V_232 )
F_29 ( 100 ) ;
F_116 ( V_2 , 0x78 , V_233 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_231 = V_13 -> V_87 . V_88 . V_89 [ 0 ] ;
bool V_232 ;
int V_233 ;
if ( ! V_231 ) {
F_112 ( V_2 ) ;
return;
}
V_232 = F_115 ( V_2 , V_231 ) ;
V_233 = F_7 ( V_2 , 0x78 ) ;
F_116 ( V_2 , 0x78 , 0x9004 ) ;
if ( V_232 )
F_29 ( 2 ) ;
F_2 ( V_2 , V_231 , 0 ,
V_234 , V_235 ) ;
if ( V_232 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_231 , 0 ,
V_227 , 0x0 ) ;
if ( V_232 )
F_29 ( 100 ) ;
F_27 ( V_2 , false ) ;
F_30 ( V_2 ) ;
F_116 ( V_2 , 0x78 , V_233 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_237 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_231 = V_13 -> V_87 . V_88 . V_89 [ 0 ] ;
bool V_232 ;
if ( ! V_13 -> V_87 . V_88 . V_238 ) {
if ( V_13 -> V_87 . V_88 . V_91 == V_175 )
V_231 = V_13 -> V_87 . V_88 . V_90 [ 0 ] ;
}
F_118 ( V_2 ) ;
if ( ! V_231 )
return;
F_29 ( 30 ) ;
V_232 = F_115 ( V_2 , V_231 ) ;
F_116 ( V_2 , 0x43 , 0x9004 ) ;
F_2 ( V_2 , V_231 , 0 ,
V_234 , V_235 ) ;
if ( V_232 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_231 , 0 ,
V_227 , V_236 ) ;
if ( V_232 )
F_29 ( 85 ) ;
F_21 ( V_2 , 0x46 , 3 << 12 , 0 ) ;
F_116 ( V_2 , 0x43 , 0x9614 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_231 = V_13 -> V_87 . V_88 . V_89 [ 0 ] ;
bool V_232 ;
if ( ! V_13 -> V_87 . V_88 . V_238 ) {
if ( V_13 -> V_87 . V_88 . V_91 == V_175 )
V_231 = V_13 -> V_87 . V_88 . V_90 [ 0 ] ;
}
if ( ! V_231 ) {
F_112 ( V_2 ) ;
return;
}
V_232 = F_115 ( V_2 , V_231 ) ;
F_116 ( V_2 , 0x43 , 0x9004 ) ;
F_116 ( V_2 , 0x06 , 0x2100 ) ;
F_2 ( V_2 , V_231 , 0 ,
V_234 , V_235 ) ;
if ( V_232 )
F_29 ( 100 ) ;
F_2 ( V_2 , V_231 , 0 ,
V_227 , 0x0 ) ;
F_21 ( V_2 , 0x46 , 0 , 3 << 12 ) ;
if ( V_232 )
F_29 ( 100 ) ;
F_27 ( V_2 , false ) ;
F_30 ( V_2 ) ;
F_116 ( V_2 , 0x43 , 0x9614 ) ;
}
static void F_121 ( struct V_1 * V_2 , unsigned int V_239 ,
unsigned int V_5 )
{
F_2 ( V_2 , 0x51 , 0 , V_6 , V_239 >> 1 ) ;
F_2 ( V_2 , 0x51 , 0 , V_9 , V_5 & 0xffff ) ;
F_2 ( V_2 , 0x51 , 0 , V_9 , V_5 >> 16 ) ;
}
static int F_122 ( struct V_1 * V_2 , unsigned int V_239 )
{
unsigned int V_5 ;
F_2 ( V_2 , 0x51 , 0 , V_6 , V_239 >> 1 ) ;
V_5 = F_3 ( V_2 , 0x51 , 0 , V_7 , 0 )
& 0xffff ;
V_5 |= F_3 ( V_2 , 0x51 , 0 , V_7 , 0 )
<< 16 ;
return V_5 ;
}
static void F_123 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
F_121 ( V_2 , 0x3000 , 0x000c ) ;
F_121 ( V_2 , 0x880c , 0x0008 ) ;
F_121 ( V_2 , 0x61c0 , 0x11110080 ) ;
F_121 ( V_2 , 0x6230 , 0xfc0d4011 ) ;
F_121 ( V_2 , 0x61b4 , 0x040a2b03 ) ;
F_121 ( V_2 , 0x61b0 , 0x00005b17 ) ;
F_121 ( V_2 , 0x61b8 , 0x04133303 ) ;
V_5 = F_122 ( V_2 , 0x6220 ) ;
F_121 ( V_2 , 0x6220 , ( V_5 | 0x3000 ) ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
F_121 ( V_2 , 0x61b8 , 0x04133302 ) ;
F_121 ( V_2 , 0x61b0 , 0x00005b16 ) ;
F_121 ( V_2 , 0x61b4 , 0x040a2b02 ) ;
F_121 ( V_2 , 0x6230 , 0xf80d4011 ) ;
F_121 ( V_2 , 0x6220 , 0x2002010f ) ;
F_121 ( V_2 , 0x880c , 0x00000004 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
F_121 ( V_2 , 0x61b0 , 0x5b14 ) ;
F_121 ( V_2 , 0x61b0 , 0x5b16 ) ;
F_121 ( V_2 , 0x61b4 , 0x04132b00 ) ;
F_121 ( V_2 , 0x61b4 , 0x04132b02 ) ;
F_121 ( V_2 , 0x61b8 , 0x041f3300 ) ;
F_121 ( V_2 , 0x61b8 , 0x041f3302 ) ;
F_2 ( V_2 , 0x51 , 0 , V_240 , 0 ) ;
F_121 ( V_2 , 0x61b8 , 0x041b3302 ) ;
F_121 ( V_2 , 0x61b8 , 0x04173302 ) ;
F_121 ( V_2 , 0x61b8 , 0x04163302 ) ;
F_121 ( V_2 , 0x8800 , 0x348b328b ) ;
F_121 ( V_2 , 0x8808 , 0x00020022 ) ;
F_121 ( V_2 , 0x8818 , 0x00000400 ) ;
V_5 = F_122 ( V_2 , 0x6200 ) >> 16 ;
if ( V_5 <= 3 )
F_121 ( V_2 , 0x6220 , 0x2002010f ) ;
else
F_121 ( V_2 , 0x6220 , 0x6002018f ) ;
F_121 ( V_2 , 0x61ac , 0x055525f0 ) ;
F_121 ( V_2 , 0x61c0 , 0x12230080 ) ;
F_121 ( V_2 , 0x61b4 , 0x040e2b02 ) ;
F_121 ( V_2 , 0x61bc , 0x010234f8 ) ;
F_121 ( V_2 , 0x880c , 0x00000004 ) ;
F_121 ( V_2 , 0x880c , 0x00000003 ) ;
F_121 ( V_2 , 0x880c , 0x00000010 ) ;
#ifdef F_126
F_123 ( V_2 ) ;
#endif
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_241 )
F_128 ( V_2 ) ;
return F_55 ( V_2 ) ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_208 == V_214 )
F_111 ( V_2 , 0 ) ;
if ( V_13 -> V_208 == V_214 &&
( F_6 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_29 ( 150 ) ;
}
V_2 -> V_107 . V_108 ( V_2 ) ;
if ( V_13 -> V_208 == V_214 )
F_111 ( V_2 , 1 ) ;
if ( V_13 -> V_208 == V_214 &&
( F_6 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_29 ( 200 ) ;
}
F_57 ( V_2 -> V_40 . V_109 ) ;
F_58 ( V_2 , 0x01 ) ;
if ( V_13 -> V_242 )
F_2 ( V_2 , V_2 -> V_40 . V_165 , 0 , V_145 ,
V_13 -> V_242 ) ;
if ( V_13 -> V_241 )
F_130 ( V_2 ) ;
return 0 ;
}
static void F_131 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_59 )
V_13 -> V_127 = V_243 ;
}
static void F_132 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_104 )
F_21 ( V_2 , 0x1e , 0 , 0x80 ) ;
}
static void F_133 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_59 )
V_13 -> V_127 |= V_244 ;
}
static void F_134 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
static const struct V_245 V_246 [] = {
{ 0x20 , V_6 , 0x0d } ,
{ 0x20 , V_9 , 0x4000 } ,
{}
} ;
unsigned int V_126 ;
if ( strcmp ( V_2 -> V_40 . V_75 , L_15 ) &&
strcmp ( V_2 -> V_40 . V_75 , L_16 ) )
return;
V_126 = F_36 ( V_2 , 0x12 ) ;
if ( F_135 ( V_126 ) == V_247 )
F_32 ( V_2 , V_246 ) ;
}
static void F_136 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 != V_64 )
return;
V_13 -> V_87 . V_248 = & V_249 ;
V_13 -> V_87 . V_250 = & V_251 ;
}
static void F_137 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_104 )
F_21 ( V_2 , 0x07 , 0 , 0x80 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
F_139 ( V_2 ) ;
F_116 ( V_2 , 0x0c , 0x680 ) ;
F_116 ( V_2 , 0x0c , 0x480 ) ;
}
static void F_140 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 != V_64 )
return;
V_13 -> V_87 . V_147 = F_138 ;
}
static void F_141 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_252 ;
F_29 ( 200 ) ;
V_150 ( V_2 , V_27 ) ;
V_252 = V_13 -> V_87 . V_146 ? V_253 : 0 ;
F_29 ( 100 ) ;
F_2 ( V_2 , 0x18 , 0 , V_227 ,
V_252 ) ;
F_29 ( 500 ) ;
F_2 ( V_2 , 0x18 , 0 , V_227 ,
V_252 ) ;
}
static void F_142 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_59 ) {
V_13 -> V_127 |= V_244 ;
V_13 -> V_87 . V_254 = F_141 ;
}
}
static void F_143 ( void * V_255 , int V_256 )
{
struct V_1 * V_2 = V_255 ;
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_257 ;
if ( V_13 -> V_258 )
V_256 = ! V_256 ;
V_257 = F_92 ( V_2 , V_13 -> V_259 ) ;
V_257 &= ~ V_260 ;
V_257 |= V_256 ? V_261 : V_176 ;
if ( V_13 -> V_259 )
F_144 ( V_2 , V_13 -> V_259 , V_257 ) ;
}
static unsigned int F_145 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_262 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_262 != V_263 || V_3 == 0 ||
( V_3 != V_13 -> V_259 && V_3 != V_13 -> V_264 ) )
return V_262 ;
F_93 ( V_2 , V_3 ,
F_92 ( V_2 , V_3 ) ) ;
return F_146 ( V_2 , V_3 , V_262 ) ;
}
static void F_147 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
const struct V_265 * V_266 = NULL ;
if ( V_58 != V_59 )
return;
while ( ( V_266 = F_148 ( V_267 , NULL , V_266 ) ) ) {
int V_268 , V_160 ;
if ( sscanf ( V_266 -> V_99 , L_17 , & V_268 , & V_160 ) != 2 )
continue;
if ( V_160 < 0x0a || V_160 >= 0x10 )
break;
V_13 -> V_258 = V_268 ;
V_13 -> V_259 = V_160 - 0x0a + 0x18 ;
V_13 -> V_87 . V_269 . V_270 = F_143 ;
V_13 -> V_87 . V_271 = 1 ;
V_2 -> V_272 = F_145 ;
F_38 ( V_2 ,
L_18 , V_13 -> V_259 ,
V_13 -> V_258 ) ;
break;
}
}
static void F_149 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_59 ) {
V_13 -> V_258 = 0 ;
V_13 -> V_259 = 0x18 ;
V_13 -> V_87 . V_269 . V_270 = F_143 ;
V_13 -> V_87 . V_271 = 1 ;
V_2 -> V_272 = F_145 ;
}
}
static void F_150 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_59 ) {
V_13 -> V_258 = 0 ;
V_13 -> V_259 = 0x19 ;
V_13 -> V_87 . V_269 . V_270 = F_143 ;
V_13 -> V_87 . V_271 = 1 ;
V_2 -> V_272 = F_145 ;
}
}
static void F_151 ( struct V_1 * V_2 , unsigned int V_10 ,
bool V_256 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_273 = V_13 -> V_242 ;
if ( V_13 -> V_258 )
V_256 = ! V_256 ;
if ( V_256 )
V_13 -> V_242 &= ~ V_10 ;
else
V_13 -> V_242 |= V_10 ;
if ( V_13 -> V_242 != V_273 )
F_2 ( V_2 , 0x01 , 0 , V_145 ,
V_13 -> V_242 ) ;
}
static void F_152 ( void * V_255 , int V_256 )
{
struct V_1 * V_2 = V_255 ;
struct V_12 * V_13 = V_2 -> V_13 ;
F_151 ( V_2 , V_13 -> V_274 , V_256 ) ;
}
static void F_153 ( struct V_1 * V_2 ,
struct V_28 * V_275 ,
struct V_30 * V_276 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_276 )
F_151 ( V_2 , V_13 -> V_277 ,
V_276 -> V_36 . integer . V_36 [ 0 ] ||
V_276 -> V_36 . integer . V_36 [ 1 ] ) ;
}
static void F_154 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_245 V_278 [] = {
{ 0x01 , V_169 , 0x18 } ,
{ 0x01 , V_170 , 0x18 } ,
{}
} ;
if ( V_58 == V_59 ) {
V_13 -> V_87 . V_269 . V_270 = F_152 ;
V_13 -> V_87 . V_279 = F_153 ;
V_13 -> V_242 = 0 ;
V_13 -> V_258 = 0 ;
V_13 -> V_274 = 0x08 ;
V_13 -> V_277 = 0x10 ;
F_79 ( V_2 , V_278 ) ;
}
}
static void F_155 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_245 V_278 [] = {
{ 0x01 , V_169 , 0x22 } ,
{ 0x01 , V_170 , 0x22 } ,
{}
} ;
if ( V_58 == V_59 ) {
V_13 -> V_87 . V_269 . V_270 = F_152 ;
V_13 -> V_87 . V_279 = F_153 ;
V_13 -> V_242 = 0 ;
V_13 -> V_258 = 0 ;
V_13 -> V_274 = 0x02 ;
V_13 -> V_277 = 0x20 ;
F_79 ( V_2 , V_278 ) ;
}
}
static void F_156 ( struct V_1 * V_2 ,
struct V_28 * V_275 ,
struct V_30 * V_276 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_257 , V_280 , V_281 ;
V_257 = F_92 ( V_2 , V_13 -> V_264 ) ;
V_257 &= ~ V_260 ;
V_280 = V_257 | V_176 ;
V_281 = V_257 | V_261 ;
if ( ! V_276 )
return;
if ( V_276 -> V_36 . integer . V_36 [ 0 ] ||
V_276 -> V_36 . integer . V_36 [ 1 ] )
V_257 = V_281 ;
else
V_257 = V_280 ;
if ( V_13 -> V_264 )
F_144 ( V_2 , V_13 -> V_264 , V_257 ) ;
}
static void F_157 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_245 V_278 [] = {
{ 0x01 , V_169 , 0x08 } ,
{ 0x01 , V_170 , 0x08 } ,
{}
} ;
if ( V_58 == V_59 ) {
V_13 -> V_87 . V_269 . V_270 = F_152 ;
V_13 -> V_87 . V_279 = F_156 ;
V_13 -> V_242 = 0 ;
V_13 -> V_258 = 0 ;
V_13 -> V_274 = 0x08 ;
V_13 -> V_264 = 0x18 ;
F_79 ( V_2 , V_278 ) ;
V_2 -> V_272 = F_145 ;
}
}
static void F_158 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_245 V_278 [] = {
{ 0x01 , V_169 , 0x18 } ,
{ 0x01 , V_170 , 0x18 } ,
{}
} ;
if ( V_58 == V_59 ) {
V_13 -> V_87 . V_269 . V_270 = F_152 ;
V_13 -> V_87 . V_279 = F_156 ;
V_13 -> V_242 = 0 ;
V_13 -> V_258 = 0 ;
V_13 -> V_274 = 0x08 ;
V_13 -> V_264 = 0x18 ;
F_79 ( V_2 , V_278 ) ;
V_2 -> V_272 = F_145 ;
}
}
static void F_159 ( struct V_1 * V_2 ,
struct V_26 * V_282 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_160 ( V_13 -> V_283 , V_284 , 1 ) ;
F_161 ( V_13 -> V_283 ) ;
F_160 ( V_13 -> V_283 , V_284 , 0 ) ;
F_161 ( V_13 -> V_283 ) ;
}
static void F_162 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
static const struct V_245 V_278 [] = {
{ 0x01 , V_169 , 0x1e } ,
{ 0x01 , V_170 , 0x1a } ,
{ 0x01 , V_145 , 0x02 } ,
{}
} ;
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_59 ) {
V_13 -> V_283 = F_163 () ;
if ( ! V_13 -> V_283 ) {
F_164 ( V_2 , L_19 ) ;
return;
}
V_13 -> V_283 -> V_99 = L_20 ;
V_13 -> V_283 -> V_285 [ 0 ] = F_165 ( V_286 ) ;
V_13 -> V_283 -> V_287 [ F_166 ( V_284 ) ] = F_165 ( V_284 ) ;
if ( F_167 ( V_13 -> V_283 ) ) {
F_164 ( V_2 , L_21 ) ;
F_168 ( V_13 -> V_283 ) ;
V_13 -> V_283 = NULL ;
return;
}
F_79 ( V_2 , V_278 ) ;
F_169 ( V_2 , V_2 -> V_40 . V_165 , 0 ,
V_288 , 0x04 ) ;
F_72 ( V_2 , V_2 -> V_40 . V_165 ,
F_159 ) ;
V_13 -> V_87 . V_269 . V_270 = F_152 ;
V_13 -> V_87 . V_279 = F_153 ;
V_13 -> V_242 = 0 ;
V_13 -> V_258 = 0 ;
V_13 -> V_274 = 0x08 ;
V_13 -> V_277 = 0x10 ;
return;
}
if ( ! V_13 -> V_283 )
return;
switch ( V_58 ) {
case V_64 :
V_13 -> V_86 = V_55 ;
break;
case V_289 :
F_170 ( V_13 -> V_283 ) ;
V_13 -> V_283 = NULL ;
}
}
static void F_171 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_59 ) {
V_13 -> V_87 . V_269 . V_270 = F_143 ;
V_13 -> V_87 . V_279 = F_156 ;
V_13 -> V_258 = 0 ;
V_13 -> V_259 = 0x1a ;
V_13 -> V_264 = 0x18 ;
V_13 -> V_87 . V_271 = 1 ;
V_2 -> V_272 = F_145 ;
}
}
static void F_172 ( struct V_1 * V_2 )
{
static struct V_15 V_290 [] = {
F_173 ( 0x1b , 0x0c0b ) ,
F_173 ( 0x45 , 0xd089 ) ,
F_174 ( 0x57 , 0x05 , 1 << 14 , 0 ) ,
F_173 ( 0x06 , 0x6104 ) ,
F_175 ( 0x57 , 0x03 , 0x8aa6 ) ,
{}
} ;
static struct V_15 V_291 [] = {
F_173 ( 0x1b , 0x0c0b ) ,
F_173 ( 0x45 , 0xc429 ) ,
F_176 ( 0x35 , 0x4000 , 0 ) ,
F_173 ( 0x06 , 0x2104 ) ,
F_173 ( 0x1a , 0x0001 ) ,
F_173 ( 0x26 , 0x0004 ) ,
F_173 ( 0x32 , 0x42a3 ) ,
{}
} ;
static struct V_15 V_292 [] = {
F_176 ( 0x4f , 0xfcc0 , 0xc400 ) ,
F_176 ( 0x50 , 0x2000 , 0x2000 ) ,
F_176 ( 0x56 , 0x0006 , 0x0006 ) ,
F_176 ( 0x66 , 0x0008 , 0 ) ,
F_176 ( 0x67 , 0x2000 , 0 ) ,
{}
} ;
static struct V_15 V_293 [] = {
F_173 ( 0x76 , 0x000e ) ,
F_173 ( 0x6c , 0x2400 ) ,
F_173 ( 0x18 , 0x7308 ) ,
F_173 ( 0x6b , 0xc429 ) ,
{}
} ;
static struct V_15 V_294 [] = {
F_176 ( 0x10 , 7 << 8 , 6 << 8 ) ,
F_174 ( 0x57 , 0x05 , 1 << 15 | 1 << 13 , 0x0 ) ,
F_174 ( 0x57 , 0x03 , 1 << 10 , 1 << 10 ) ,
F_176 ( 0x1a , 1 << 3 , 1 << 3 ) ,
F_173 ( 0x45 , 0xc429 ) ,
F_176 ( 0x4a , 0x000f , 0x000e ) ,
{}
} ;
static struct V_15 V_295 [] = {
F_173 ( 0x15 , 0x0d40 ) ,
F_173 ( 0xb7 , 0x802b ) ,
{}
} ;
switch ( V_2 -> V_40 . V_41 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_290 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_291 ) ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
F_8 ( V_2 , V_292 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_293 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_294 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_295 ) ;
break;
}
F_38 ( V_2 , L_22 ) ;
}
static void F_177 ( struct V_1 * V_2 , T_1 V_231 ,
T_1 V_222 )
{
static struct V_15 V_290 [] = {
F_175 ( 0x57 , 0x03 , 0x8aa6 ) ,
F_173 ( 0x06 , 0x6100 ) ,
{}
} ;
static struct V_15 V_291 [] = {
F_176 ( 0x35 , 0 , 1 << 14 ) ,
F_173 ( 0x06 , 0x2100 ) ,
F_173 ( 0x1a , 0x0021 ) ,
F_173 ( 0x26 , 0x008c ) ,
{}
} ;
static struct V_15 V_292 [] = {
F_176 ( 0x50 , 0x2000 , 0 ) ,
F_176 ( 0x56 , 0x0006 , 0 ) ,
F_176 ( 0x4f , 0xfcc0 , 0xc400 ) ,
F_176 ( 0x66 , 0x0008 , 0x0008 ) ,
F_176 ( 0x67 , 0x2000 , 0x2000 ) ,
{}
} ;
static struct V_15 V_293 [] = {
F_173 ( 0x19 , 0xa208 ) ,
F_173 ( 0x2e , 0xacf0 ) ,
{}
} ;
static struct V_15 V_294 [] = {
F_174 ( 0x57 , 0x05 , 0 , 1 << 15 | 1 << 13 ) ,
F_174 ( 0x57 , 0x03 , 1 << 10 , 0 ) ,
F_176 ( 0x1a , 1 << 3 , 0 ) ,
{}
} ;
static struct V_15 V_296 [] = {
F_173 ( 0xb7 , 0x802b ) ,
F_173 ( 0xb5 , 0x1040 ) ,
F_176 ( 0xc3 , 0 , 1 << 12 ) ,
{}
} ;
switch ( V_2 -> V_40 . V_41 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_116 ( V_2 , 0x45 , 0xc489 ) ;
F_144 ( V_2 , V_231 , 0 ) ;
F_8 ( V_2 , V_290 ) ;
F_144 ( V_2 , V_222 , V_297 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_116 ( V_2 , 0x45 , 0xc429 ) ;
F_144 ( V_2 , V_231 , 0 ) ;
F_8 ( V_2 , V_291 ) ;
F_144 ( V_2 , V_222 , V_297 ) ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
F_21 ( V_2 , 0x4f , 0x000c , 0 ) ;
F_144 ( V_2 , V_231 , 0 ) ;
F_8 ( V_2 , V_292 ) ;
F_144 ( V_2 , V_222 , V_297 ) ;
break;
case 0x10ec0292 :
F_144 ( V_2 , V_231 , 0 ) ;
F_8 ( V_2 , V_293 ) ;
break;
case 0x10ec0293 :
F_116 ( V_2 , 0x45 , 0xc429 ) ;
F_144 ( V_2 , V_231 , 0 ) ;
F_8 ( V_2 , V_294 ) ;
F_144 ( V_2 , V_222 , V_297 ) ;
break;
case 0x10ec0662 :
F_144 ( V_2 , V_231 , 0 ) ;
F_144 ( V_2 , V_222 , V_297 ) ;
break;
case 0x10ec0668 :
F_116 ( V_2 , 0x11 , 0x0001 ) ;
F_144 ( V_2 , V_231 , 0 ) ;
F_8 ( V_2 , V_296 ) ;
F_144 ( V_2 , V_222 , V_297 ) ;
break;
}
F_38 ( V_2 , L_23 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
static struct V_15 V_290 [] = {
F_173 ( 0x45 , 0xc089 ) ,
F_173 ( 0x45 , 0xc489 ) ,
F_175 ( 0x57 , 0x03 , 0x8ea6 ) ,
F_173 ( 0x49 , 0x0049 ) ,
{}
} ;
static struct V_15 V_291 [] = {
F_173 ( 0x06 , 0x2100 ) ,
F_173 ( 0x32 , 0x4ea3 ) ,
{}
} ;
static struct V_15 V_292 [] = {
F_176 ( 0x4f , 0xfcc0 , 0xc400 ) ,
F_176 ( 0x50 , 0x2000 , 0x2000 ) ,
F_176 ( 0x56 , 0x0006 , 0x0006 ) ,
F_176 ( 0x66 , 0x0008 , 0 ) ,
F_176 ( 0x67 , 0x2000 , 0 ) ,
{}
} ;
static struct V_15 V_293 [] = {
F_173 ( 0x76 , 0x000e ) ,
F_173 ( 0x6c , 0x2400 ) ,
F_173 ( 0x6b , 0xc429 ) ,
F_173 ( 0x18 , 0x7308 ) ,
{}
} ;
static struct V_15 V_294 [] = {
F_176 ( 0x4a , 0x000f , 0x000e ) ,
F_173 ( 0x45 , 0xC429 ) ,
F_176 ( 0x1a , 1 << 3 , 0 ) ,
{}
} ;
static struct V_15 V_296 [] = {
F_173 ( 0x11 , 0x0041 ) ,
F_173 ( 0x15 , 0x0d40 ) ,
F_173 ( 0xb7 , 0x802b ) ,
{}
} ;
switch ( V_2 -> V_40 . V_41 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_290 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_291 ) ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
F_8 ( V_2 , V_292 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_293 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_294 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_296 ) ;
break;
}
F_38 ( V_2 , L_24 ) ;
}
static void F_179 ( struct V_1 * V_2 )
{
static struct V_15 V_290 [] = {
F_173 ( 0x45 , 0xd489 ) ,
F_173 ( 0x1b , 0x0c2b ) ,
F_175 ( 0x57 , 0x03 , 0x8ea6 ) ,
{}
} ;
static struct V_15 V_291 [] = {
F_173 ( 0x45 , 0xd429 ) ,
F_173 ( 0x1b , 0x0c2b ) ,
F_173 ( 0x32 , 0x4ea3 ) ,
{}
} ;
static struct V_15 V_292 [] = {
F_176 ( 0x50 , 0x2000 , 0x2000 ) ,
F_176 ( 0x56 , 0x0006 , 0x0006 ) ,
F_176 ( 0x66 , 0x0008 , 0 ) ,
F_176 ( 0x67 , 0x2000 , 0 ) ,
{}
} ;
static struct V_15 V_293 [] = {
F_173 ( 0x6b , 0xd429 ) ,
F_173 ( 0x76 , 0x0008 ) ,
F_173 ( 0x18 , 0x7388 ) ,
{}
} ;
static struct V_15 V_294 [] = {
F_173 ( 0x45 , 0xd429 ) ,
F_176 ( 0x10 , 7 << 8 , 7 << 8 ) ,
{}
} ;
static struct V_15 V_296 [] = {
F_173 ( 0x11 , 0x0001 ) ,
F_173 ( 0x15 , 0x0d60 ) ,
F_173 ( 0xc3 , 0x0000 ) ,
{}
} ;
switch ( V_2 -> V_40 . V_41 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_290 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_291 ) ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
F_21 ( V_2 , 0x4f , 0xfcc0 , 0xd400 ) ;
F_29 ( 300 ) ;
F_8 ( V_2 , V_292 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_293 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_294 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_296 ) ;
break;
}
F_38 ( V_2 , L_25 ) ;
}
static void F_180 ( struct V_1 * V_2 )
{
static struct V_15 V_290 [] = {
F_173 ( 0x45 , 0xe489 ) ,
F_173 ( 0x1b , 0x0c2b ) ,
F_175 ( 0x57 , 0x03 , 0x8ea6 ) ,
{}
} ;
static struct V_15 V_291 [] = {
F_173 ( 0x45 , 0xe429 ) ,
F_173 ( 0x1b , 0x0c2b ) ,
F_173 ( 0x32 , 0x4ea3 ) ,
{}
} ;
static struct V_15 V_292 [] = {
F_176 ( 0x50 , 0x2000 , 0x2000 ) ,
F_176 ( 0x56 , 0x0006 , 0x0006 ) ,
F_176 ( 0x66 , 0x0008 , 0 ) ,
F_176 ( 0x67 , 0x2000 , 0 ) ,
{}
} ;
static struct V_15 V_293 [] = {
F_173 ( 0x6b , 0xe429 ) ,
F_173 ( 0x76 , 0x0008 ) ,
F_173 ( 0x18 , 0x7388 ) ,
{}
} ;
static struct V_15 V_294 [] = {
F_173 ( 0x45 , 0xe429 ) ,
F_176 ( 0x10 , 7 << 8 , 7 << 8 ) ,
{}
} ;
static struct V_15 V_296 [] = {
F_173 ( 0x11 , 0x0001 ) ,
F_173 ( 0x15 , 0x0d50 ) ,
F_173 ( 0xc3 , 0x0000 ) ,
{}
} ;
switch ( V_2 -> V_40 . V_41 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_290 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_291 ) ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
F_21 ( V_2 , 0x4f , 0xfcc0 , 0xe400 ) ;
F_29 ( 300 ) ;
F_8 ( V_2 , V_292 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_293 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_294 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_296 ) ;
break;
}
F_38 ( V_2 , L_26 ) ;
}
static void F_181 ( struct V_1 * V_2 )
{
int V_5 ;
bool V_298 = false ;
struct V_12 * V_13 = V_2 -> V_13 ;
static struct V_15 V_290 [] = {
F_173 ( 0x45 , 0xd089 ) ,
F_173 ( 0x49 , 0x0149 ) ,
{}
} ;
static struct V_15 V_292 [] = {
F_176 ( 0x4f , 0xfcc0 , 0xd400 ) ,
{}
} ;
static struct V_15 V_294 [] = {
F_176 ( 0x4a , 0x000f , 0x0008 ) ,
F_173 ( 0x45 , 0xD429 ) ,
{}
} ;
static struct V_15 V_296 [] = {
F_173 ( 0x11 , 0x0001 ) ,
F_173 ( 0xb7 , 0x802b ) ,
F_173 ( 0x15 , 0x0d60 ) ,
F_173 ( 0xc3 , 0x0c00 ) ,
{}
} ;
switch ( V_2 -> V_40 . V_41 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_290 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_298 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_116 ( V_2 , 0x45 , 0xd029 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_298 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
F_8 ( V_2 , V_292 ) ;
F_29 ( 350 ) ;
V_5 = F_7 ( V_2 , 0x50 ) ;
V_298 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0292 :
F_116 ( V_2 , 0x6b , 0xd429 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x6c ) ;
V_298 = ( V_5 & 0x001c ) == 0x001c ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_294 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_298 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_296 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0xbe ) ;
V_298 = ( V_5 & 0x1c02 ) == 0x1c02 ;
break;
}
F_38 ( V_2 , L_27 ,
V_298 ? L_28 : L_29 ) ;
V_13 -> V_299 = V_298 ? V_300 : V_301 ;
}
static void F_182 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_302 = V_13 -> V_87 . V_303 [ V_13 -> V_87 . V_304 [ 0 ] ] ;
T_1 V_231 = V_13 -> V_87 . V_88 . V_89 [ 0 ] ;
int V_305 ;
if ( ! F_115 ( V_2 , V_231 ) )
V_305 = V_306 ;
else if ( V_302 == V_13 -> V_307 )
V_305 = V_308 ;
else if ( V_302 == V_13 -> V_309 )
V_305 = V_310 ;
else
V_305 = V_311 ;
if ( V_305 == V_13 -> V_312 ) {
F_139 ( V_2 ) ;
return;
}
switch ( V_305 ) {
case V_306 :
F_172 ( V_2 ) ;
V_13 -> V_87 . V_146 = false ;
break;
case V_308 :
if ( V_13 -> V_299 == V_313 )
F_181 ( V_2 ) ;
if ( V_13 -> V_299 == V_300 )
F_179 ( V_2 ) ;
else if ( V_13 -> V_299 == V_301 )
F_180 ( V_2 ) ;
V_13 -> V_87 . V_146 = true ;
break;
case V_310 :
F_177 ( V_2 , V_231 , V_13 -> V_309 ) ;
V_13 -> V_87 . V_146 = false ;
break;
case V_311 :
F_178 ( V_2 ) ;
V_13 -> V_87 . V_146 = true ;
break;
}
if ( V_305 != V_310 ) {
F_144 ( V_2 , V_231 ,
V_314 | V_315 ) ;
if ( V_13 -> V_309 && V_13 -> V_309 != V_231 )
F_144 ( V_2 , V_13 -> V_309 ,
V_316 ) ;
}
V_13 -> V_312 = V_305 ;
F_139 ( V_2 ) ;
}
static void F_183 ( struct V_1 * V_2 ,
struct V_28 * V_275 ,
struct V_30 * V_276 )
{
F_182 ( V_2 ) ;
}
static void F_184 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_299 = V_313 ;
V_150 ( V_2 , V_27 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
int V_68 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_125 * V_126 = & V_13 -> V_87 . V_88 ;
for ( V_68 = 0 ; V_68 < V_126 -> V_317 ; V_68 ++ ) {
if ( V_126 -> V_318 [ V_68 ] . V_319 && ! V_13 -> V_307 )
V_13 -> V_307 = V_126 -> V_318 [ V_68 ] . V_160 ;
if ( V_126 -> V_318 [ V_68 ] . V_320 && ! V_13 -> V_309 )
V_13 -> V_309 = V_126 -> V_318 [ V_68 ] . V_160 ;
}
V_13 -> V_87 . V_279 = F_183 ;
V_13 -> V_87 . V_147 = F_182 ;
V_13 -> V_87 . V_254 = F_184 ;
}
static void F_186 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
switch ( V_58 ) {
case V_59 :
V_13 -> V_127 |= V_244 | V_321 ;
break;
case V_64 :
F_185 ( V_2 ) ;
break;
case V_104 :
V_13 -> V_312 = 0 ;
F_182 ( V_2 ) ;
break;
}
}
static void F_187 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_59 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_127 |= V_244 ;
}
else
F_186 ( V_2 , V_57 , V_58 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
static struct V_15 V_16 [] = {
F_173 ( 0x1b , 0x880b ) ,
F_173 ( 0x45 , 0xd089 ) ,
F_173 ( 0x1b , 0x080b ) ,
F_173 ( 0x46 , 0x0004 ) ,
F_173 ( 0x1b , 0x0c0b ) ,
{}
} ;
F_8 ( V_2 , V_16 ) ;
F_29 ( 30 ) ;
}
static void F_189 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_59 ) {
F_188 ( V_2 ) ;
}
F_186 ( V_2 , V_57 , V_58 ) ;
}
static void F_190 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_59 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_127 |= V_244 ;
F_188 ( V_2 ) ;
}
else
F_186 ( V_2 , V_57 , V_58 ) ;
}
static void F_191 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_322 ;
F_184 ( V_2 , V_27 ) ;
V_322 = V_13 -> V_87 . V_146 ? 0x40 : 0 ;
F_2 ( V_2 , 0x01 , 0 , V_145 ,
V_322 ) ;
}
static void F_192 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
F_186 ( V_2 , V_57 , V_58 ) ;
if ( V_58 == V_64 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_87 . V_254 = F_191 ;
}
}
static void F_193 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_59 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_87 . V_323 = 1 ;
}
}
static void F_194 ( struct V_1 * V_2 )
{
}
static void F_195 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_59 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_105 = F_194 ;
}
}
static void F_196 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_59 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_87 . V_128 = 0 ;
}
}
static void F_197 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_231 = V_13 -> V_87 . V_88 . V_89 [ 0 ] ;
F_2 ( V_2 , V_231 , 0 ,
V_234 , V_235 ) ;
F_29 ( 20 ) ;
}
static void F_198 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_324 * V_325 = & V_13 -> V_87 . V_326 ;
int V_68 ;
switch ( V_58 ) {
case V_59 :
F_199 ( V_2 , 0x19 , V_316 ) ;
break;
case V_64 :
V_13 -> V_105 = F_197 ;
for ( V_68 = 0 ; V_68 < V_325 -> V_327 ; V_68 ++ ) {
if ( V_13 -> V_87 . V_303 [ V_68 ] == 0x12 ) {
V_13 -> V_87 . V_304 [ 0 ] = V_68 ;
break;
}
}
break;
}
}
static void F_200 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_59 ) {
V_13 -> V_127 |= V_244 ;
V_13 -> V_87 . V_155 = 1 ;
F_2 ( V_2 , 0x1b , 0 , V_234 , 0x7000 ) ;
F_201 ( V_2 , 0x1b , F_25 ( V_2 , 0x1b ) & ~ V_328 ) ;
} else
F_186 ( V_2 , V_57 , V_58 ) ;
}
static void F_202 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_59 ) {
F_116 ( V_2 , 0xc4 , 0x8000 ) ;
F_21 ( V_2 , 0xc2 , ~ 0xfe , 0 ) ;
F_144 ( V_2 , 0x18 , 0 ) ;
}
F_186 ( V_2 , V_57 , V_58 ) ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_125 * V_126 = & V_13 -> V_87 . V_88 ;
T_1 V_3 ;
unsigned int V_329 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_126 -> V_317 ; V_68 ++ ) {
if ( V_126 -> V_318 [ V_68 ] . type != V_330 )
continue;
V_3 = V_126 -> V_318 [ V_68 ] . V_160 ;
V_329 = F_36 ( V_2 , V_3 ) ;
if ( F_203 ( V_329 ) == V_331 )
continue;
return V_3 ;
}
return 0 ;
}
static void F_204 ( struct V_1 * V_2 ,
const struct V_56 * V_57 ,
int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_58 == V_64 ) {
int V_222 = F_109 ( V_2 ) ;
int V_231 = V_13 -> V_87 . V_88 . V_89 [ 0 ] ;
if ( F_10 ( ! V_222 || ! V_231 ) )
return;
F_205 ( V_2 , V_222 , V_231 ) ;
}
}
static void F_206 ( struct V_1 * V_2 ,
const struct V_56 * V_57 ,
int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_125 * V_126 = & V_13 -> V_87 . V_88 ;
int V_68 ;
if ( V_58 != V_64 )
return;
for ( V_68 = 0 ; V_68 < V_126 -> V_317 ; V_68 ++ ) {
T_1 V_3 = V_126 -> V_318 [ V_68 ] . V_160 ;
unsigned int V_329 ;
if ( V_126 -> V_318 [ V_68 ] . type != V_330 )
continue;
V_329 = F_36 ( V_2 , V_3 ) ;
if ( F_203 ( V_329 ) != V_331 )
continue;
F_106 ( V_2 , V_3 , V_140 ,
( 0x00 << V_200 ) |
( 0x01 << V_201 ) |
( 0x2f << V_202 ) |
( 0 << V_203 ) ) ;
}
}
static void F_207 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_252 ;
F_29 ( 200 ) ;
V_150 ( V_2 , V_27 ) ;
V_252 = V_13 -> V_87 . V_146 ? V_253 : 0 ;
F_29 ( 600 ) ;
F_2 ( V_2 , 0x19 , 0 , V_227 ,
V_252 ) ;
}
static void F_208 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
switch ( V_58 ) {
case V_59 :
F_201 ( V_2 , 0x03 , 0 ) ;
V_13 -> V_87 . V_128 = 0 ;
break;
case V_104 :
F_21 ( V_2 , 0x06 , 0x000c , 0 ) ;
F_21 ( V_2 , 0x1a , 0 , 1 << 4 ) ;
break;
}
}
static void F_209 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
switch ( V_58 ) {
case V_59 :
V_13 -> V_87 . V_254 = F_207 ;
break;
case V_104 :
F_21 ( V_2 , 0x06 , 0x000c , 0 ) ;
break;
}
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_139 ( V_2 ) ;
if ( F_115 ( V_2 , 0x1b ) )
V_13 -> V_87 . V_332 |= ( 1ULL << 0x14 ) ;
}
static void F_211 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_245 V_333 [] = {
{ 0x01 , V_169 , 0x04 } ,
{ 0x01 , V_170 , 0x04 } ,
{ 0x01 , V_145 , 0x04 } ,
{}
} ;
static const struct V_151 V_334 [] = {
{ 0x1b , 0x21114000 } ,
{}
} ;
struct V_28 * V_29 ;
switch ( V_58 ) {
case V_59 :
F_79 ( V_2 , V_333 ) ;
F_81 ( V_2 , V_334 ) ;
V_13 -> V_87 . V_323 = 1 ;
V_13 -> V_87 . V_147 = F_210 ;
F_72 ( V_2 , 0x1b ,
V_150 ) ;
break;
case V_102 :
V_29 = F_15 ( V_2 , L_30 ) ;
if ( V_29 )
strcpy ( V_29 -> V_335 . V_99 , L_31 ) ;
V_29 = F_15 ( V_2 , L_32 ) ;
if ( V_29 )
strcpy ( V_29 -> V_335 . V_99 , L_30 ) ;
break;
}
}
static void F_212 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_59 ) {
T_1 V_171 [ 2 ] = { 0x0c } ;
F_89 ( V_2 , 0x14 , 1 , V_171 ) ;
F_89 ( V_2 , 0x15 , 1 , V_171 ) ;
}
}
static void F_213 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_5 ;
if ( V_13 -> V_208 != V_214 )
return;
if ( ( F_6 ( V_2 ) & 0x00ff ) < 0x015 ) {
F_116 ( V_2 , 0xf , 0x960b ) ;
F_116 ( V_2 , 0xe , 0x8817 ) ;
}
if ( ( F_6 ( V_2 ) & 0x00ff ) == 0x016 ) {
F_116 ( V_2 , 0xf , 0x960b ) ;
F_116 ( V_2 , 0xe , 0x8814 ) ;
}
if ( ( F_6 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_21 ( V_2 , 0x04 , 0 , 1 << 11 ) ;
}
if ( ( F_6 ( V_2 ) & 0x00ff ) == 0x018 ) {
V_5 = F_7 ( V_2 , 0xd ) ;
if ( V_5 != - 1 && ( V_5 & 0x0c00 ) >> 10 != 0x1 ) {
F_116 ( V_2 , 0xd , V_5 | ( 1 << 10 ) ) ;
}
V_5 = F_7 ( V_2 , 0x17 ) ;
if ( V_5 != - 1 && ( V_5 & 0x01c0 ) >> 6 != 0x4 ) {
F_116 ( V_2 , 0x17 , V_5 | ( 1 << 7 ) ) ;
}
}
F_21 ( V_2 , 0x4 , 0 , 1 << 11 ) ;
}
static int F_214 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_95 ;
V_95 = F_68 ( V_2 , 0x0b ) ;
if ( V_95 < 0 )
return V_95 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_87 . V_189 = 0x18 ;
V_2 -> V_336 = 1 ;
F_74 ( V_2 , V_337 ,
V_338 , V_339 ) ;
F_215 ( V_2 , V_340 , V_339 ) ;
F_74 ( V_2 , NULL , V_341 ,
V_339 ) ;
F_50 ( V_2 , V_59 ) ;
F_35 ( V_2 ) ;
if ( F_63 ( V_2 ) )
V_13 -> V_87 . V_135 = 0x01 ;
switch ( V_2 -> V_40 . V_41 ) {
case 0x10ec0269 :
V_13 -> V_208 = V_209 ;
switch ( F_6 ( V_2 ) & 0x00f0 ) {
case 0x0010 :
if ( V_2 -> V_71 -> V_72 &&
V_2 -> V_71 -> V_72 -> V_119 == 0x1025 &&
V_13 -> V_60 . V_80 == 1 )
V_95 = F_59 ( V_2 , L_15 ) ;
V_13 -> V_208 = V_214 ;
break;
case 0x0020 :
if ( V_2 -> V_71 -> V_72 &&
V_2 -> V_71 -> V_72 -> V_119 == 0x17aa &&
V_2 -> V_71 -> V_72 -> V_74 == 0x21f3 )
V_95 = F_59 ( V_2 , L_33 ) ;
V_13 -> V_208 = V_210 ;
break;
case 0x0030 :
V_13 -> V_208 = V_215 ;
break;
default:
F_13 ( V_2 , 0x20 , 0x04 , 15 ) ;
}
if ( V_95 < 0 )
goto error;
V_13 -> V_103 = F_213 ;
F_213 ( V_2 ) ;
break;
case 0x10ec0280 :
case 0x10ec0290 :
V_13 -> V_208 = V_211 ;
break;
case 0x10ec0282 :
V_13 -> V_208 = V_216 ;
V_13 -> V_105 = F_117 ;
V_13 -> V_103 = F_114 ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
V_13 -> V_208 = V_217 ;
V_13 -> V_105 = F_120 ;
V_13 -> V_103 = F_119 ;
break;
case 0x10ec0284 :
case 0x10ec0292 :
V_13 -> V_208 = V_212 ;
break;
case 0x10ec0285 :
case 0x10ec0293 :
V_13 -> V_208 = V_213 ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
V_13 -> V_208 = V_218 ;
V_13 -> V_105 = F_108 ;
break;
case 0x10ec0298 :
V_13 -> V_208 = V_219 ;
break;
case 0x10ec0255 :
V_13 -> V_208 = V_220 ;
break;
case 0x10ec0256 :
V_13 -> V_208 = V_221 ;
V_13 -> V_87 . V_128 = 0 ;
F_21 ( V_2 , 0x36 , 1 << 13 , 1 << 5 ) ;
break;
}
if ( F_3 ( V_2 , 0x51 , 0 , V_342 , 0 ) == 0x10ec5505 ) {
V_13 -> V_241 = 1 ;
V_13 -> V_103 = F_125 ;
}
V_95 = F_107 ( V_2 ) ;
if ( V_95 < 0 )
goto error;
if ( ! V_13 -> V_87 . V_139 && V_13 -> V_87 . V_135 && V_13 -> V_87 . V_128 )
F_75 ( V_13 , V_13 -> V_87 . V_128 , 0x04 , V_140 ) ;
V_2 -> V_107 = V_141 ;
V_2 -> V_107 . V_343 = V_344 ;
#ifdef F_216
V_2 -> V_107 . V_345 = F_127 ;
V_2 -> V_107 . V_346 = F_129 ;
#endif
if ( ! V_13 -> V_105 )
V_13 -> V_105 = F_112 ;
F_50 ( V_2 , V_64 ) ;
return 0 ;
error:
F_61 ( V_2 ) ;
return V_95 ;
}
static int F_217 ( struct V_1 * V_2 )
{
static const T_1 V_347 [] = { 0x1d , 0 } ;
static const T_1 V_348 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_65 ( V_2 , V_347 , V_348 ) ;
}
static void F_218 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_5 ;
if ( V_58 != V_104 )
return;
V_5 = F_92 ( V_2 , 0x0f ) ;
if ( ! ( V_5 & ( V_349 | V_314 ) ) )
V_5 |= V_349 ;
V_5 |= V_179 ;
F_93 ( V_2 , 0x0f , V_5 ) ;
V_13 -> V_87 . V_177 = 1 ;
}
static void F_219 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_59 )
V_2 -> V_350 = 1 ;
}
static int F_220 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_95 ;
V_95 = F_68 ( V_2 , 0x15 ) ;
if ( V_95 < 0 )
return V_95 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_87 . V_135 = 0x23 ;
F_74 ( V_2 , NULL , V_351 , V_352 ) ;
F_50 ( V_2 , V_59 ) ;
V_95 = F_217 ( V_2 ) ;
if ( V_95 < 0 )
goto error;
if ( ! V_13 -> V_87 . V_139 )
F_75 ( V_13 , 0x23 , 0 , V_353 ) ;
V_2 -> V_107 = V_141 ;
#ifdef F_216
V_13 -> V_106 = F_54 ;
#endif
F_50 ( V_2 , V_64 ) ;
return 0 ;
error:
F_61 ( V_2 ) ;
return V_95 ;
}
static int F_221 ( struct V_1 * V_2 )
{
static const T_1 V_354 [] = { 0x1d , 0 } ;
static const T_1 V_355 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_65 ( V_2 , V_354 , V_355 ) ;
}
static void F_222 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_59 ) {
F_223 ( V_2 , 0x18 , 0x00000734 ) ;
F_223 ( V_2 , 0x19 , 0x0000073c ) ;
}
}
static int F_224 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_95 ;
V_95 = F_68 ( V_2 , 0x0b ) ;
if ( V_95 < 0 )
return V_95 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_87 . V_135 = 0x23 ;
F_74 ( V_2 , NULL , V_356 , V_357 ) ;
F_50 ( V_2 , V_59 ) ;
V_95 = F_221 ( V_2 ) ;
if ( V_95 < 0 )
goto error;
if ( ! V_13 -> V_87 . V_139 )
F_75 ( V_13 , 0x0b , 0x05 , V_140 ) ;
V_2 -> V_107 = V_141 ;
V_13 -> V_105 = F_28 ;
F_50 ( V_2 , V_64 ) ;
return 0 ;
error:
F_61 ( V_2 ) ;
return V_95 ;
}
static int F_225 ( struct V_1 * V_2 )
{
static const T_1 V_358 [] = { 0x1d , 0 } ;
static const T_1 V_359 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_360 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_207 ;
if ( V_2 -> V_40 . V_41 == 0x10ec0272 || V_2 -> V_40 . V_41 == 0x10ec0663 ||
V_2 -> V_40 . V_41 == 0x10ec0665 || V_2 -> V_40 . V_41 == 0x10ec0670 ||
V_2 -> V_40 . V_41 == 0x10ec0671 )
V_207 = V_359 ;
else
V_207 = V_360 ;
return F_65 ( V_2 , V_358 , V_207 ) ;
}
static void F_226 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 != V_59 )
return;
if ( F_106 ( V_2 , 0x2 , V_353 ,
( 0x3b << V_200 ) |
( 0x3b << V_201 ) |
( 0x03 << V_202 ) |
( 0 << V_203 ) ) )
F_227 ( V_2 , L_34 ) ;
}
static void F_228 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
if ( V_58 == V_102 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_87 . V_361 [ 0 ] -> V_362 [ 0 ] . V_363 = V_364 ;
}
}
static unsigned int F_229 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_262 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_3 == V_2 -> V_40 . V_165 && V_262 == V_263 && V_13 -> V_242 )
return V_365 ;
return V_262 ;
}
static void F_230 ( struct V_1 * V_2 ,
const struct V_56 * V_57 , int V_58 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_245 V_278 [] = {
{ 0x01 , V_169 , 0x01 } ,
{ 0x01 , V_170 , 0x01 } ,
{}
} ;
if ( V_58 == V_59 ) {
V_13 -> V_87 . V_269 . V_270 = F_152 ;
V_13 -> V_242 = 0 ;
V_13 -> V_258 = 1 ;
V_13 -> V_274 = 0x01 ;
F_79 ( V_2 , V_278 ) ;
V_2 -> V_272 = F_229 ;
}
}
static void F_231 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_366 ) ;
}
static int F_232 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_95 ;
V_95 = F_68 ( V_2 , 0x0b ) ;
if ( V_95 < 0 )
return V_95 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_127 = V_243 ;
F_13 ( V_2 , 0x20 , 0x04 , 15 ) ;
switch ( V_2 -> V_40 . V_41 ) {
case 0x10ec0668 :
V_13 -> V_103 = F_231 ;
break;
}
F_74 ( V_2 , V_367 ,
V_368 , V_369 ) ;
F_215 ( V_2 , V_370 , V_369 ) ;
F_50 ( V_2 , V_59 ) ;
F_35 ( V_2 ) ;
if ( F_63 ( V_2 ) )
V_13 -> V_87 . V_135 = 0x01 ;
if ( ( F_6 ( V_2 ) & ( 1 << 14 ) ) &&
V_2 -> V_71 -> V_72 && V_2 -> V_71 -> V_72 -> V_119 == 0x1025 &&
V_13 -> V_60 . V_80 == 1 ) {
V_95 = F_59 ( V_2 , L_35 ) ;
if ( V_95 < 0 )
goto error;
}
V_95 = F_225 ( V_2 ) ;
if ( V_95 < 0 )
goto error;
if ( ! V_13 -> V_87 . V_139 && V_13 -> V_87 . V_135 ) {
switch ( V_2 -> V_40 . V_41 ) {
case 0x10ec0662 :
F_75 ( V_13 , 0x0b , 0x05 , V_140 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0668 :
F_75 ( V_13 , 0x0b , 0x04 , V_140 ) ;
break;
case 0x10ec0273 :
F_75 ( V_13 , 0x0b , 0x03 , V_140 ) ;
break;
}
}
V_2 -> V_107 = V_141 ;
V_13 -> V_105 = F_28 ;
F_50 ( V_2 , V_64 ) ;
return 0 ;
error:
F_61 ( V_2 ) ;
return V_95 ;
}
static int F_233 ( struct V_1 * V_2 )
{
return F_65 ( V_2 , NULL , NULL ) ;
}
static int F_234 ( struct V_1 * V_2 )
{
int V_95 ;
V_95 = F_68 ( V_2 , 0 ) ;
if ( V_95 < 0 )
return V_95 ;
V_95 = F_233 ( V_2 ) ;
if ( V_95 < 0 ) {
F_61 ( V_2 ) ;
return V_95 ;
}
V_2 -> V_107 = V_141 ;
return 0 ;
}
