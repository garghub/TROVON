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
V_5 = F_3 ( V_2 , V_27 -> V_3 , 0 ,
V_33 , 0 ) ;
V_5 &= V_34 ;
V_31 -> V_35 . integer . V_35 [ 0 ] = V_5 ;
V_31 -> V_35 . integer . V_35 [ 1 ] = V_5 ;
V_29 -> V_36 ( V_29 , V_31 ) ;
F_17 ( V_31 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_37 )
{
F_19 ( V_2 , V_37 >> 2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
int V_38 ;
V_38 = F_6 ( V_2 ) ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0262 :
F_21 ( V_2 , 0x7 , 0 , 1 << 5 ) ;
break;
case 0x10ec0267 :
case 0x10ec0268 :
F_21 ( V_2 , 0x7 , 0 , 1 << 13 ) ;
break;
case 0x10ec0269 :
if ( ( V_38 & 0x00f0 ) == 0x0010 )
F_21 ( V_2 , 0xd , 0 , 1 << 14 ) ;
if ( ( V_38 & 0x00f0 ) == 0x0020 )
F_21 ( V_2 , 0x4 , 1 << 15 , 0 ) ;
if ( ( V_38 & 0x00f0 ) == 0x0030 )
F_21 ( V_2 , 0x10 , 1 << 9 , 0 ) ;
break;
case 0x10ec0280 :
case 0x10ec0284 :
case 0x10ec0290 :
case 0x10ec0292 :
F_21 ( V_2 , 0x4 , 1 << 15 , 0 ) ;
break;
case 0x10ec0215 :
case 0x10ec0225 :
case 0x10ec0233 :
case 0x10ec0236 :
case 0x10ec0255 :
case 0x10ec0256 :
case 0x10ec0282 :
case 0x10ec0283 :
case 0x10ec0286 :
case 0x10ec0288 :
case 0x10ec0285 :
case 0x10ec0295 :
case 0x10ec0298 :
case 0x10ec0289 :
case 0x10ec0299 :
F_21 ( V_2 , 0x10 , 1 << 9 , 0 ) ;
break;
case 0x10ec0293 :
F_21 ( V_2 , 0xa , 1 << 13 , 0 ) ;
break;
case 0x10ec0234 :
case 0x10ec0274 :
case 0x10ec0294 :
case 0x10ec0700 :
case 0x10ec0701 :
case 0x10ec0703 :
F_21 ( V_2 , 0x10 , 1 << 15 , 0 ) ;
break;
case 0x10ec0662 :
if ( ( V_38 & 0x00f0 ) == 0x0030 )
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
if ( ( V_38 & 0x00f0 ) == 0x0020 || ( V_38 & 0x00f0 ) == 0x0030 )
F_21 ( V_2 , 0x7 , 1 << 5 , 0 ) ;
break;
case 0x10ec0892 :
F_21 ( V_2 , 0x7 , 1 << 5 , 0 ) ;
break;
case 0x10ec0899 :
case 0x10ec0900 :
case 0x10ec1168 :
case 0x10ec1220 :
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
static void F_23 ( struct V_1 * V_2 , T_1 V_3 , int V_41 )
{
if ( F_24 ( F_25 ( V_2 , V_3 ) ) != V_42 )
return;
if ( F_26 ( V_2 , V_3 ) & V_43 )
F_2 ( V_2 , V_3 , 0 , V_44 ,
V_41 ? 2 : 0 ) ;
}
static void F_27 ( struct V_1 * V_2 , bool V_41 )
{
static T_1 V_45 [] = {
0x0f , 0x10 , 0x14 , 0x15 , 0x17 , 0
} ;
T_1 * V_46 ;
for ( V_46 = V_45 ; * V_46 ; V_46 ++ )
F_23 ( V_2 , * V_46 , V_41 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_27 ( V_2 , false ) ;
if ( ! V_13 -> V_47 )
F_29 ( 200 ) ;
F_30 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 , int type )
{
F_20 ( V_2 ) ;
F_27 ( V_2 , true ) ;
switch ( type ) {
case V_48 :
F_32 ( V_2 , V_49 ) ;
break;
case V_50 :
F_32 ( V_2 , V_51 ) ;
break;
case V_52 :
F_32 ( V_2 , V_53 ) ;
break;
case V_54 :
switch ( V_2 -> V_39 . V_40 ) {
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
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_59 . V_60 = 1 ;
V_13 -> V_59 . V_61 = V_62 ;
}
}
static void F_34 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_63 ) {
V_13 -> V_47 = 1 ;
V_2 -> V_64 = 0 ;
}
}
static int F_35 ( struct V_1 * V_2 )
{
unsigned int V_65 , V_66 , V_67 ;
unsigned V_3 = 0 ;
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_59 . V_68 = 1 ;
if ( V_13 -> V_59 . V_60 ) {
V_65 = V_13 -> V_59 . V_61 ;
if ( V_65 == V_62 )
return - 1 ;
goto V_69;
}
if ( ! V_2 -> V_70 -> V_71 )
return - 1 ;
V_65 = V_2 -> V_39 . V_72 & 0xffff ;
if ( V_65 != V_2 -> V_70 -> V_71 -> V_73 && ( V_65 & 1 ) )
goto V_69;
V_3 = 0x1d ;
if ( V_2 -> V_39 . V_40 == 0x10ec0260 )
V_3 = 0x17 ;
V_65 = F_36 ( V_2 , V_3 ) ;
if ( ! ( V_65 & 1 ) ) {
F_37 ( V_2 , L_2 ,
V_2 -> V_39 . V_74 , V_65 ) ;
return - 1 ;
}
V_66 = 0 ;
for ( V_67 = 1 ; V_67 < 16 ; V_67 ++ ) {
if ( ( V_65 >> V_67 ) & 1 )
V_66 ++ ;
}
if ( ( ( V_65 >> 16 ) & 0xf ) != V_66 )
return - 1 ;
V_13 -> V_59 . V_75 = V_65 >> 30 ;
V_13 -> V_59 . V_68 = ( V_65 & 0x100000 ) >> 20 ;
V_13 -> V_59 . V_76 = ( V_65 >> 16 ) & 0xf ;
V_13 -> V_59 . V_77 = V_65 >> 8 ;
V_69:
V_13 -> V_59 . V_61 = V_65 ;
V_13 -> V_59 . V_78 = ( V_65 & 0x38 ) >> 3 ;
V_13 -> V_59 . V_79 = ( V_65 & 0x4 ) >> 2 ;
V_13 -> V_59 . V_80 = ( V_65 & 0x2 ) >> 1 ;
V_13 -> V_59 . V_81 = V_65 & 0x1 ;
F_38 ( V_2 , L_3 ,
V_3 , V_13 -> V_59 . V_61 ) ;
F_38 ( V_2 , L_4 ,
V_13 -> V_59 . V_75 ) ;
F_38 ( V_2 , L_5 , V_13 -> V_59 . V_68 ) ;
F_38 ( V_2 , L_6 , V_13 -> V_59 . V_76 ) ;
F_38 ( V_2 , L_7 , V_13 -> V_59 . V_77 ) ;
F_38 ( V_2 , L_8 , V_13 -> V_59 . V_78 ) ;
F_38 ( V_2 , L_9 , V_13 -> V_59 . V_79 ) ;
F_38 ( V_2 , L_10 , V_13 -> V_59 . V_80 ) ;
F_38 ( V_2 , L_11 , V_13 -> V_59 . V_81 ) ;
return 0 ;
}
static int F_39 ( T_1 V_3 , const T_1 * V_82 , int V_83 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_83 ; V_67 ++ )
if ( V_82 [ V_67 ] == V_3 )
return V_67 ;
return - 1 ;
}
static bool F_40 ( T_1 V_3 , const T_1 * V_82 , int V_83 )
{
return F_39 ( V_3 , V_82 , V_83 ) >= 0 ;
}
static int F_41 ( struct V_1 * V_2 , const T_1 * V_84 )
{
unsigned int V_65 , V_66 , V_67 ;
unsigned V_3 ;
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_59 . V_60 ) {
V_65 = V_13 -> V_59 . V_61 ;
if ( V_65 == V_62 )
return 0 ;
goto V_69;
}
V_65 = V_2 -> V_39 . V_72 & 0xffff ;
if ( V_2 -> V_70 -> V_71 &&
V_65 != V_2 -> V_70 -> V_71 -> V_73 && ( V_65 & 1 ) )
goto V_69;
V_3 = 0x1d ;
if ( V_2 -> V_39 . V_40 == 0x10ec0260 )
V_3 = 0x17 ;
V_65 = F_36 ( V_2 , V_3 ) ;
F_38 ( V_2 ,
L_12 ,
V_65 , V_3 ) ;
if ( ! ( V_65 & 1 ) )
return 0 ;
if ( ( V_65 >> 30 ) != 1 )
return 0 ;
V_66 = 0 ;
for ( V_67 = 1 ; V_67 < 16 ; V_67 ++ ) {
if ( ( V_65 >> V_67 ) & 1 )
V_66 ++ ;
}
if ( ( ( V_65 >> 16 ) & 0xf ) != V_66 )
return 0 ;
V_69:
F_38 ( V_2 , L_13 ,
V_65 & 0xffff , V_2 -> V_39 . V_40 ) ;
V_66 = ( V_65 & 0x38 ) >> 3 ;
switch ( V_66 ) {
case 1 :
V_13 -> V_85 = V_48 ;
break;
case 3 :
V_13 -> V_85 = V_50 ;
break;
case 7 :
V_13 -> V_85 = V_52 ;
break;
case 5 :
default:
V_13 -> V_85 = V_54 ;
break;
}
if ( ! ( V_65 & 0x8000 ) )
return 1 ;
if ( ! V_13 -> V_86 . V_87 . V_88 [ 0 ] &&
! ( V_13 -> V_86 . V_87 . V_89 [ 0 ] &&
V_13 -> V_86 . V_87 . V_90 == V_91 ) ) {
T_1 V_3 ;
V_66 = ( V_65 >> 11 ) & 0x3 ;
V_3 = V_84 [ V_66 ] ;
if ( F_40 ( V_3 , V_13 -> V_86 . V_87 . V_89 ,
V_13 -> V_86 . V_87 . V_92 ) )
return 1 ;
V_13 -> V_86 . V_87 . V_88 [ 0 ] = V_3 ;
}
return 1 ;
}
static void F_42 ( struct V_1 * V_2 , const T_1 * V_84 )
{
if ( ! F_41 ( V_2 , V_84 ) ) {
struct V_12 * V_13 = V_2 -> V_13 ;
F_38 ( V_2 ,
L_14 ) ;
V_13 -> V_85 = V_54 ;
}
}
static void F_43 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_93 = 1 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_67 , V_94 ;
V_94 = F_45 ( V_2 ) ;
if ( V_94 < 0 )
return V_94 ;
for ( V_67 = 0 ; V_67 < V_13 -> V_20 ; V_67 ++ ) {
V_94 = F_46 ( V_2 , V_13 -> V_21 [ V_67 ] ) ;
if ( V_94 < 0 )
return V_94 ;
}
#ifdef F_47
if ( V_13 -> V_95 ) {
const struct V_18 * V_96 ;
for ( V_96 = V_97 ; V_96 -> V_98 ; V_96 ++ ) {
struct V_28 * V_29 ;
V_29 = F_48 ( V_96 , V_2 ) ;
if ( ! V_29 )
return - V_99 ;
V_29 -> V_100 = V_13 -> V_95 ;
V_94 = F_49 ( V_2 , 0 , V_29 ) ;
if ( V_94 < 0 )
return V_94 ;
}
}
#endif
F_50 ( V_2 , V_101 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_102 )
V_13 -> V_102 ( V_2 ) ;
F_12 ( V_2 ) ;
F_31 ( V_2 , V_13 -> V_85 ) ;
F_52 ( V_2 ) ;
F_50 ( V_2 , V_103 ) ;
return 0 ;
}
static inline void F_53 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 && V_13 -> V_104 )
V_13 -> V_104 ( V_2 ) ;
else
F_30 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 && V_13 -> V_105 )
V_13 -> V_105 ( V_2 ) ;
else
F_53 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_56 ( V_2 , V_2 -> V_39 . V_106 , V_107 ) ;
F_2 ( V_2 , V_2 -> V_39 . V_106 , 0 ,
V_108 , V_107 ) ;
F_29 ( 10 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_27 ( V_2 , false ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_53 ( V_2 ) ;
if ( V_13 && V_13 -> V_109 )
V_13 -> V_109 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( ! V_13 -> V_47 )
F_29 ( 150 ) ;
V_2 -> V_110 . V_111 ( V_2 ) ;
F_60 ( V_2 -> V_39 . V_112 ) ;
F_61 ( V_2 , 0x01 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
const struct V_113 * V_46 ;
const struct V_114 * V_115 ;
for ( V_46 = V_116 ; V_46 -> V_40 ; V_46 ++ ) {
if ( V_46 -> V_40 != V_2 -> V_39 . V_40 )
continue;
if ( ( F_6 ( V_2 ) & V_46 -> V_117 ) == V_46 -> V_118 )
return F_63 ( V_2 , V_46 -> V_98 ) ;
}
if ( ! V_2 -> V_70 -> V_71 )
return 0 ;
for ( V_115 = V_119 ; V_115 -> V_120 ; V_115 ++ ) {
if ( V_115 -> V_120 != V_2 -> V_39 . V_40 )
continue;
if ( V_115 -> V_121 != V_2 -> V_70 -> V_71 -> V_122 )
continue;
if ( ! V_115 -> V_123 ||
V_115 -> V_123 == V_2 -> V_70 -> V_71 -> V_73 )
return F_63 ( V_2 , V_115 -> V_98 ) ;
}
return 0 ;
}
static inline int F_64 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
const struct V_124 * V_115 ;
V_115 = F_65 ( V_2 -> V_70 -> V_71 , V_125 ) ;
if ( V_115 )
return V_115 -> V_35 ;
return V_13 -> V_59 . V_68 ;
}
static int F_66 ( struct V_1 * V_2 ,
const T_1 * V_126 ,
const T_1 * V_127 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_128 * V_129 = & V_13 -> V_86 . V_87 ;
int V_94 ;
V_94 = F_67 ( V_2 , V_129 , V_126 ,
V_13 -> V_130 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( V_127 )
F_42 ( V_2 , V_127 ) ;
V_94 = F_68 ( V_2 , V_129 ) ;
if ( V_94 < 0 )
return V_94 ;
return 1 ;
}
static int F_69 ( struct V_1 * V_2 , T_1 V_131 )
{
struct V_12 * V_13 = F_16 ( sizeof( * V_13 ) , V_32 ) ;
int V_94 ;
if ( ! V_13 )
return - V_99 ;
V_2 -> V_13 = V_13 ;
F_70 ( & V_13 -> V_86 ) ;
V_13 -> V_86 . V_131 = V_131 ;
V_13 -> V_86 . V_132 = 1 ;
V_2 -> V_133 = 1 ;
V_2 -> V_134 = 1 ;
V_2 -> V_110 = V_135 ;
V_94 = F_62 ( V_2 ) ;
if ( V_94 < 0 ) {
F_17 ( V_13 ) ;
return V_94 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
static const T_1 V_136 [] = { 0x1d , 0 } ;
static const T_1 V_137 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , V_136 , V_137 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_63 )
F_73 ( V_2 , 0x21 ,
F_14 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_138 = 1 ;
V_13 -> V_86 . V_139 = 0x01 ;
V_2 -> V_110 . V_140 = F_18 ;
F_75 ( V_2 , V_141 , V_142 ,
V_143 ) ;
F_50 ( V_2 , V_58 ) ;
V_94 = F_71 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_144 )
F_76 ( V_13 , 0x0b , 0x05 , V_145 ) ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_77 ( V_2 ) ;
return V_94 ;
}
static int F_78 ( struct V_1 * V_2 )
{
static const T_1 V_146 [] = { 0x17 , 0 } ;
static const T_1 V_147 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_66 ( V_2 , V_146 , V_147 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_2 ( V_2 , 0x01 , 0 , V_148 ,
V_13 -> V_86 . V_149 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_63 ) {
V_13 -> V_86 . V_150 = F_79 ;
V_13 -> V_86 . V_151 = 1 ;
V_13 -> V_86 . V_152 = 1 ;
V_13 -> V_86 . V_87 . V_88 [ 0 ] = 0x0f ;
F_73 ( V_2 , 0x0f ,
V_153 ) ;
F_81 ( V_2 , V_49 ) ;
}
}
static void F_82 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_154 V_155 [] = {
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
switch ( V_57 ) {
case V_58 :
F_83 ( V_2 , V_155 ) ;
break;
case V_63 :
V_13 -> V_85 = V_156 ;
break;
}
}
static void F_84 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_63 )
V_13 -> V_85 = V_156 ;
}
static void F_85 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_157 = 1 ;
V_13 -> V_86 . V_158 = 1 ;
}
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x07 ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_159 = 1 ;
V_13 -> V_86 . V_139 = 0x01 ;
V_13 -> V_104 = F_28 ;
F_75 ( V_2 , V_160 , V_161 ,
V_162 ) ;
F_50 ( V_2 , V_58 ) ;
V_94 = F_78 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_144 )
F_76 ( V_13 , 0x07 , 0x05 , V_145 ) ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_77 ( V_2 ) ;
return V_94 ;
}
static void F_87 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 != V_103 )
return;
F_21 ( V_2 , 7 , 0 , 0x2030 ) ;
}
static void F_88 ( struct V_1 * V_2 , int V_163 , int V_164 )
{
unsigned int V_165 , V_166 , V_167 ;
V_165 = F_3 ( V_2 , V_2 -> V_39 . V_106 , 0 ,
V_168 , 0 ) ;
if ( ! V_164 )
V_165 |= ( 1 << V_163 ) ;
else
V_165 &= ~ ( 1 << V_163 ) ;
V_166 = F_3 ( V_2 , V_2 -> V_39 . V_106 , 0 ,
V_169 , 0 ) ;
V_166 |= ( 1 << V_163 ) ;
V_167 = F_3 ( V_2 , V_2 -> V_39 . V_106 , 0 ,
V_170 , 0 ) ;
V_167 |= ( 1 << V_163 ) ;
F_2 ( V_2 , V_2 -> V_39 . V_106 , 0 ,
V_171 , V_166 ) ;
F_2 ( V_2 , V_2 -> V_39 . V_106 , 0 ,
V_172 , V_167 ) ;
F_29 ( 1 ) ;
F_2 ( V_2 , V_2 -> V_39 . V_106 , 0 ,
V_148 , V_165 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 != V_103 )
return;
F_88 ( V_2 , 0 , 0 ) ;
F_88 ( V_2 , 1 , 0 ) ;
}
static void F_90 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
T_1 V_173 [ 2 ] = { 0x0c , 0x0d } ;
T_1 V_174 [ 2 ] = { 0x0e , 0x0f } ;
F_91 ( V_2 , 0x14 , 2 , V_173 ) ;
F_91 ( V_2 , 0x15 , 2 , V_173 ) ;
F_91 ( V_2 , 0x18 , 2 , V_174 ) ;
F_91 ( V_2 , 0x1a , 2 , V_174 ) ;
} else if ( V_57 == V_63 ) {
T_1 V_175 [ 5 ] = { 0x0c , 0x0d , 0x0e , 0x0f , 0x26 } ;
F_91 ( V_2 , 0x14 , 5 , V_175 ) ;
F_91 ( V_2 , 0x15 , 5 , V_175 ) ;
F_91 ( V_2 , 0x18 , 5 , V_175 ) ;
F_91 ( V_2 , 0x1a , 5 , V_175 ) ;
}
}
static void F_92 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static T_1 V_176 [ 3 ] = { 0x14 , 0x15 , 0x19 } ;
int V_67 ;
if ( V_57 != V_103 )
return;
for ( V_67 = 0 ; V_67 < F_11 ( V_176 ) ; V_67 ++ ) {
unsigned int V_5 = F_36 ( V_2 , V_176 [ V_67 ] ) ;
if ( F_93 ( V_5 ) != V_177 )
continue;
V_5 = F_94 ( V_2 , V_176 [ V_67 ] ) ;
V_5 |= V_178 ;
F_95 ( V_2 , V_176 [ V_67 ] , V_5 ) ;
V_13 -> V_86 . V_179 = 1 ;
break;
}
}
static void F_96 ( struct V_1 * V_2 ,
const T_1 * V_176 , int V_180 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_180 ; V_67 ++ ) {
unsigned int V_5 ;
V_5 = F_94 ( V_2 , V_176 [ V_67 ] ) ;
V_5 |= V_181 ;
F_95 ( V_2 , V_176 [ V_67 ] , V_5 ) ;
}
V_13 -> V_86 . V_179 = 1 ;
}
static void F_97 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static T_1 V_176 [ 2 ] = { 0x18 , 0x1a } ;
if ( V_57 == V_103 )
F_96 ( V_2 , V_176 , F_11 ( V_176 ) ) ;
}
static void F_98 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static T_1 V_176 [ 1 ] = { 0x18 } ;
if ( V_57 == V_103 )
F_96 ( V_2 , V_176 , F_11 ( V_176 ) ) ;
}
static void F_99 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static T_1 V_176 [ 2 ] = { 0x18 , 0x19 } ;
if ( V_57 == V_103 )
F_96 ( V_2 , V_176 , F_11 ( V_176 ) ) ;
}
static void F_100 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_182 = 1 ;
V_13 -> V_86 . V_183 = 1 ;
}
}
static void F_101 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 != V_58 )
return;
V_13 -> V_86 . V_184 = 1 ;
V_13 -> V_86 . V_185 = 1 ;
V_13 -> V_86 . V_186 = 1 ;
V_13 -> V_86 . V_131 = 0 ;
V_2 -> V_187 = 1 ;
}
static void F_102 ( struct V_1 * V_2 , const char * V_188 ,
const char * V_189 )
{
struct V_28 * V_29 ;
V_29 = F_15 ( V_2 , V_188 ) ;
if ( V_29 )
strcpy ( V_29 -> V_190 . V_98 , V_189 ) ;
}
static void F_103 ( struct V_1 * V_2 ,
const struct V_55 * V_56 ,
int V_57 )
{
F_101 ( V_2 , V_56 , V_57 ) ;
switch ( V_57 ) {
case V_58 :
strcpy ( V_2 -> V_191 -> V_192 , L_15 ) ;
break;
case V_101 :
F_102 ( V_2 , L_16 ,
V_2 -> V_193 == 0 ?
L_17 :
L_18 ) ;
F_102 ( V_2 , L_19 ,
V_2 -> V_193 == 0 ?
L_20 :
L_21 ) ;
break;
}
}
static int F_104 ( struct V_1 * V_2 )
{
static const T_1 V_194 [] = { 0x1d , 0 } ;
static const T_1 V_195 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , V_194 , V_195 ) ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0882 :
case 0x10ec0885 :
case 0x10ec0900 :
case 0x10ec1220 :
break;
default:
F_13 ( V_2 , 0x20 , 0x0a , 10 ) ;
break;
}
F_75 ( V_2 , V_196 , V_197 ,
V_198 ) ;
F_50 ( V_2 , V_58 ) ;
F_35 ( V_2 ) ;
if ( F_64 ( V_2 ) )
V_13 -> V_86 . V_139 = 0x01 ;
V_94 = F_104 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_144 && V_13 -> V_86 . V_139 )
F_76 ( V_13 , 0x0b , 0x05 , V_145 ) ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_77 ( V_2 ) ;
return V_94 ;
}
static int F_106 ( struct V_1 * V_2 )
{
static const T_1 V_199 [] = { 0x1d , 0 } ;
static const T_1 V_200 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , V_199 , V_200 ) ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_201 = 0x18 ;
V_13 -> V_104 = F_28 ;
#if 0
alc_update_coefex_idx(codec, 0x1a, 7, 0, 0x80);
#endif
F_13 ( V_2 , 0x20 , 0x0a , 10 ) ;
F_75 ( V_2 , V_202 , V_203 ,
V_204 ) ;
F_50 ( V_2 , V_58 ) ;
F_35 ( V_2 ) ;
if ( F_64 ( V_2 ) )
V_13 -> V_86 . V_139 = 0x01 ;
V_94 = F_106 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_144 && V_13 -> V_86 . V_139 )
F_76 ( V_13 , 0x0b , 0x05 , V_145 ) ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_77 ( V_2 ) ;
return V_94 ;
}
static int F_108 ( struct V_28 * V_205 ,
struct V_30 * V_206 )
{
struct V_1 * V_2 = F_109 ( V_205 ) ;
unsigned long V_207 ;
int V_94 ;
F_110 ( & V_2 -> V_208 ) ;
V_207 = V_205 -> V_100 ;
V_205 -> V_100 = ( V_207 & ~ 0xff ) | 0x0f ;
V_94 = F_111 ( V_205 , V_206 ) ;
if ( V_94 >= 0 ) {
V_205 -> V_100 = ( V_207 & ~ 0xff ) | 0x10 ;
V_94 = F_111 ( V_205 , V_206 ) ;
}
V_205 -> V_100 = V_207 ;
F_112 ( & V_2 -> V_208 ) ;
return V_94 ;
}
static int F_113 ( struct V_1 * V_2 )
{
static const T_1 V_209 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , NULL , V_209 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_139 = 0x01 ;
V_13 -> V_104 = F_28 ;
F_75 ( V_2 , V_210 , V_211 , V_212 ) ;
F_50 ( V_2 , V_58 ) ;
V_94 = F_113 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( V_94 > 0 && ! V_13 -> V_86 . V_144 &&
V_13 -> V_86 . V_87 . V_213 [ 0 ] != 0x1d ) {
F_9 ( V_13 , V_214 ) ;
F_81 ( V_2 , V_215 ) ;
if ( ! F_115 ( V_2 , 0x1d , V_145 ) )
F_116 ( V_2 , 0x1d , V_145 ,
( 0x0c << V_216 ) |
( 0x0c << V_217 ) |
( 0x07 << V_218 ) |
( 0 << V_219 ) ) ;
}
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_77 ( V_2 ) ;
return V_94 ;
}
static int F_117 ( struct V_1 * V_2 )
{
static const T_1 V_220 [] = { 0x1d , 0 } ;
static const T_1 V_221 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_222 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_12 * V_13 = V_2 -> V_13 ;
const T_1 * V_223 ;
switch ( V_13 -> V_224 ) {
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
V_223 = V_222 ;
break;
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
V_223 = V_221 ;
break;
default:
V_223 = V_221 ;
break;
}
return F_66 ( V_2 , V_220 , V_223 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
int V_67 ;
int V_242 = F_119 ( V_2 ) ;
if ( V_2 -> V_70 -> V_243 )
return;
for ( V_67 = 0 ; V_67 < V_2 -> V_244 . V_245 ; V_67 ++ ) {
struct V_246 * V_163 = F_120 ( & V_2 -> V_244 , V_67 ) ;
if ( V_163 -> V_3 != V_242 )
F_3 ( V_2 , V_163 -> V_3 , 0 ,
V_247 , 0 ) ;
}
V_2 -> V_248 = 1 ;
}
static void F_121 ( struct V_1 * V_2 , int V_249 )
{
F_21 ( V_2 , 0x04 , 1 << 11 , V_249 ? ( 1 << 11 ) : 0 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_224 == V_230 )
F_121 ( V_2 , 0 ) ;
if ( V_13 -> V_224 == V_230 &&
( F_6 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_29 ( 150 ) ;
}
F_30 ( V_2 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_250 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_251 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_252 ;
int V_253 ;
F_123 ( V_2 ) ;
if ( ! V_251 )
return;
V_252 = F_125 ( V_2 , V_251 ) ;
V_253 = F_7 ( V_2 , 0x78 ) ;
F_126 ( V_2 , 0x78 , 0x9004 ) ;
if ( V_252 )
F_29 ( 2 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_254 , V_255 ) ;
if ( V_252 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_247 , V_256 ) ;
if ( V_252 )
F_29 ( 100 ) ;
F_126 ( V_2 , 0x78 , V_253 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_251 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_252 ;
int V_253 ;
if ( ! V_251 ) {
F_122 ( V_2 ) ;
return;
}
V_252 = F_125 ( V_2 , V_251 ) ;
V_253 = F_7 ( V_2 , 0x78 ) ;
F_126 ( V_2 , 0x78 , 0x9004 ) ;
if ( V_252 )
F_29 ( 2 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_254 , V_255 ) ;
if ( V_252 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_247 , 0x0 ) ;
if ( V_252 )
F_29 ( 100 ) ;
F_27 ( V_2 , false ) ;
F_30 ( V_2 ) ;
F_126 ( V_2 , 0x78 , V_253 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_257 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_251 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_252 ;
if ( ! V_13 -> V_86 . V_87 . V_258 ) {
if ( V_13 -> V_86 . V_87 . V_90 == V_177 )
V_251 = V_13 -> V_86 . V_87 . V_89 [ 0 ] ;
}
F_128 ( V_2 ) ;
if ( ! V_251 )
return;
F_29 ( 30 ) ;
V_252 = F_125 ( V_2 , V_251 ) ;
F_126 ( V_2 , 0x43 , 0x9004 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_254 , V_255 ) ;
if ( V_252 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_247 , V_256 ) ;
if ( V_252 )
F_29 ( 85 ) ;
F_21 ( V_2 , 0x46 , 3 << 12 , 0 ) ;
F_126 ( V_2 , 0x43 , 0x9614 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_251 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_252 ;
if ( ! V_13 -> V_86 . V_87 . V_258 ) {
if ( V_13 -> V_86 . V_87 . V_90 == V_177 )
V_251 = V_13 -> V_86 . V_87 . V_89 [ 0 ] ;
}
if ( ! V_251 ) {
F_122 ( V_2 ) ;
return;
}
V_252 = F_125 ( V_2 , V_251 ) ;
F_126 ( V_2 , 0x43 , 0x9004 ) ;
F_126 ( V_2 , 0x06 , 0x2100 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_254 , V_255 ) ;
if ( V_252 )
F_29 ( 100 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_247 , 0x0 ) ;
F_21 ( V_2 , 0x46 , 0 , 3 << 12 ) ;
if ( V_252 )
F_29 ( 100 ) ;
F_27 ( V_2 , false ) ;
F_30 ( V_2 ) ;
F_126 ( V_2 , 0x43 , 0x9614 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_251 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_252 ;
if ( ! V_251 )
return;
F_29 ( 30 ) ;
V_252 = F_125 ( V_2 , V_251 ) ;
if ( V_252 )
F_29 ( 2 ) ;
F_5 ( V_2 , 0x57 , 0x04 , 0x0007 , 0x1 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_254 , V_255 ) ;
if ( V_252 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_247 , V_256 ) ;
if ( V_252 )
F_29 ( 100 ) ;
F_21 ( V_2 , 0x46 , 3 << 12 , 0 ) ;
F_5 ( V_2 , 0x57 , 0x04 , 0x0007 , 0x4 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_251 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_252 ;
if ( ! V_251 ) {
F_122 ( V_2 ) ;
return;
}
V_252 = F_125 ( V_2 , V_251 ) ;
if ( V_252 )
F_29 ( 2 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_254 , V_255 ) ;
if ( V_252 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_247 , 0x0 ) ;
F_21 ( V_2 , 0x46 , 0 , 3 << 12 ) ;
if ( V_252 )
F_29 ( 100 ) ;
F_27 ( V_2 , false ) ;
F_30 ( V_2 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_251 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_252 ;
if ( ! V_251 )
return;
F_29 ( 30 ) ;
V_252 = F_125 ( V_2 , V_251 ) ;
if ( V_252 )
F_29 ( 2 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_254 , V_255 ) ;
if ( V_252 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_247 , V_256 ) ;
if ( V_252 )
F_29 ( 100 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_251 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_252 ;
if ( ! V_251 ) {
F_122 ( V_2 ) ;
return;
}
V_252 = F_125 ( V_2 , V_251 ) ;
if ( V_252 )
F_29 ( 2 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_254 , V_255 ) ;
if ( V_252 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_251 , 0 ,
V_247 , 0x0 ) ;
if ( V_252 )
F_29 ( 100 ) ;
F_27 ( V_2 , false ) ;
F_30 ( V_2 ) ;
}
static void F_135 ( struct V_1 * V_2 , unsigned int V_259 ,
unsigned int V_5 )
{
F_2 ( V_2 , 0x51 , 0 , V_6 , V_259 >> 1 ) ;
F_2 ( V_2 , 0x51 , 0 , V_9 , V_5 & 0xffff ) ;
F_2 ( V_2 , 0x51 , 0 , V_9 , V_5 >> 16 ) ;
}
static int F_136 ( struct V_1 * V_2 , unsigned int V_259 )
{
unsigned int V_5 ;
F_2 ( V_2 , 0x51 , 0 , V_6 , V_259 >> 1 ) ;
V_5 = F_3 ( V_2 , 0x51 , 0 , V_7 , 0 )
& 0xffff ;
V_5 |= F_3 ( V_2 , 0x51 , 0 , V_7 , 0 )
<< 16 ;
return V_5 ;
}
static void F_137 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
F_135 ( V_2 , 0x3000 , 0x000c ) ;
F_135 ( V_2 , 0x880c , 0x0008 ) ;
F_135 ( V_2 , 0x61c0 , 0x11110080 ) ;
F_135 ( V_2 , 0x6230 , 0xfc0d4011 ) ;
F_135 ( V_2 , 0x61b4 , 0x040a2b03 ) ;
F_135 ( V_2 , 0x61b0 , 0x00005b17 ) ;
F_135 ( V_2 , 0x61b8 , 0x04133303 ) ;
V_5 = F_136 ( V_2 , 0x6220 ) ;
F_135 ( V_2 , 0x6220 , ( V_5 | 0x3000 ) ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
F_135 ( V_2 , 0x61b8 , 0x04133302 ) ;
F_135 ( V_2 , 0x61b0 , 0x00005b16 ) ;
F_135 ( V_2 , 0x61b4 , 0x040a2b02 ) ;
F_135 ( V_2 , 0x6230 , 0xf80d4011 ) ;
F_135 ( V_2 , 0x6220 , 0x2002010f ) ;
F_135 ( V_2 , 0x880c , 0x00000004 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
F_137 ( V_2 ) ;
F_138 ( V_2 ) ;
F_135 ( V_2 , 0x61b0 , 0x5b14 ) ;
F_135 ( V_2 , 0x61b0 , 0x5b16 ) ;
F_135 ( V_2 , 0x61b4 , 0x04132b00 ) ;
F_135 ( V_2 , 0x61b4 , 0x04132b02 ) ;
F_135 ( V_2 , 0x61b8 , 0x041f3300 ) ;
F_135 ( V_2 , 0x61b8 , 0x041f3302 ) ;
F_2 ( V_2 , 0x51 , 0 , V_260 , 0 ) ;
F_135 ( V_2 , 0x61b8 , 0x041b3302 ) ;
F_135 ( V_2 , 0x61b8 , 0x04173302 ) ;
F_135 ( V_2 , 0x61b8 , 0x04163302 ) ;
F_135 ( V_2 , 0x8800 , 0x348b328b ) ;
F_135 ( V_2 , 0x8808 , 0x00020022 ) ;
F_135 ( V_2 , 0x8818 , 0x00000400 ) ;
V_5 = F_136 ( V_2 , 0x6200 ) >> 16 ;
if ( V_5 <= 3 )
F_135 ( V_2 , 0x6220 , 0x2002010f ) ;
else
F_135 ( V_2 , 0x6220 , 0x6002018f ) ;
F_135 ( V_2 , 0x61ac , 0x055525f0 ) ;
F_135 ( V_2 , 0x61c0 , 0x12230080 ) ;
F_135 ( V_2 , 0x61b4 , 0x040e2b02 ) ;
F_135 ( V_2 , 0x61bc , 0x010234f8 ) ;
F_135 ( V_2 , 0x880c , 0x00000004 ) ;
F_135 ( V_2 , 0x880c , 0x00000003 ) ;
F_135 ( V_2 , 0x880c , 0x00000010 ) ;
#ifdef F_140
F_137 ( V_2 ) ;
#endif
}
static int F_141 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_261 )
F_142 ( V_2 ) ;
return F_58 ( V_2 ) ;
}
static int F_143 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_224 == V_230 )
F_121 ( V_2 , 0 ) ;
if ( V_13 -> V_224 == V_230 &&
( F_6 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_29 ( 150 ) ;
}
V_2 -> V_110 . V_111 ( V_2 ) ;
if ( V_13 -> V_224 == V_230 )
F_121 ( V_2 , 1 ) ;
if ( V_13 -> V_224 == V_230 &&
( F_6 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_29 ( 200 ) ;
}
F_60 ( V_2 -> V_39 . V_112 ) ;
F_61 ( V_2 , 0x01 ) ;
if ( V_13 -> V_262 )
F_2 ( V_2 , V_2 -> V_39 . V_106 , 0 , V_148 ,
V_13 -> V_262 ) ;
if ( V_13 -> V_261 )
F_144 ( V_2 ) ;
return 0 ;
}
static void F_145 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 )
V_13 -> V_130 = V_263 ;
}
static void F_146 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_103 )
F_21 ( V_2 , 0x1e , 0 , 0x80 ) ;
}
static void F_147 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 )
V_13 -> V_130 |= V_264 ;
}
static void F_148 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static const struct V_265 V_266 [] = {
{ 0x20 , V_6 , 0x0d } ,
{ 0x20 , V_9 , 0x4000 } ,
{}
} ;
unsigned int V_129 ;
if ( strcmp ( V_2 -> V_39 . V_74 , L_22 ) &&
strcmp ( V_2 -> V_39 . V_74 , L_23 ) )
return;
V_129 = F_36 ( V_2 , 0x12 ) ;
if ( F_149 ( V_129 ) == V_267 )
F_32 ( V_2 , V_266 ) ;
}
static void F_150 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 != V_63 )
return;
V_13 -> V_86 . V_268 = & V_269 ;
V_13 -> V_86 . V_270 = & V_271 ;
}
static void F_151 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_103 )
F_21 ( V_2 , 0x07 , 0 , 0x80 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
F_153 ( V_2 ) ;
F_126 ( V_2 , 0x0c , 0x680 ) ;
F_126 ( V_2 , 0x0c , 0x480 ) ;
}
static void F_154 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 != V_63 )
return;
V_13 -> V_86 . V_150 = F_152 ;
}
static void F_155 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_272 ;
F_29 ( 200 ) ;
V_153 ( V_2 , V_27 ) ;
V_272 = V_13 -> V_86 . V_149 ? V_273 : 0 ;
F_29 ( 100 ) ;
F_2 ( V_2 , 0x18 , 0 , V_247 ,
V_272 ) ;
F_29 ( 500 ) ;
F_2 ( V_2 , 0x18 , 0 , V_247 ,
V_272 ) ;
}
static void F_156 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_130 |= V_264 ;
V_13 -> V_86 . V_274 = F_155 ;
}
}
static void F_157 ( void * V_275 , int V_276 )
{
struct V_1 * V_2 = V_275 ;
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_277 ;
if ( V_13 -> V_278 )
V_276 = ! V_276 ;
V_277 = F_94 ( V_2 , V_13 -> V_279 ) ;
V_277 &= ~ V_280 ;
V_277 |= V_276 ? V_281 : V_178 ;
if ( V_13 -> V_279 )
F_158 ( V_2 , V_13 -> V_279 , V_277 ) ;
}
static unsigned int F_159 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_282 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_282 != V_107 || V_3 == 0 ||
( V_3 != V_13 -> V_279 && V_3 != V_13 -> V_283 ) )
return V_282 ;
F_95 ( V_2 , V_3 ,
F_94 ( V_2 , V_3 ) ) ;
return F_160 ( V_2 , V_3 , V_282 ) ;
}
static void F_161 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
const struct V_284 * V_285 = NULL ;
if ( V_57 != V_58 )
return;
while ( ( V_285 = F_162 ( V_286 , NULL , V_285 ) ) ) {
int V_287 , V_163 ;
if ( sscanf ( V_285 -> V_98 , L_24 , & V_287 , & V_163 ) != 2 )
continue;
if ( V_163 < 0x0a || V_163 >= 0x10 )
break;
V_13 -> V_278 = V_287 ;
V_13 -> V_279 = V_163 - 0x0a + 0x18 ;
V_13 -> V_86 . V_288 . V_289 = F_157 ;
V_13 -> V_86 . V_290 = 1 ;
V_2 -> V_291 = F_159 ;
F_38 ( V_2 ,
L_25 , V_13 -> V_279 ,
V_13 -> V_278 ) ;
break;
}
}
static void F_163 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_278 = 0 ;
V_13 -> V_279 = 0x18 ;
V_13 -> V_86 . V_288 . V_289 = F_157 ;
V_13 -> V_86 . V_290 = 1 ;
V_2 -> V_291 = F_159 ;
}
}
static void F_164 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_278 = 0 ;
V_13 -> V_279 = 0x19 ;
V_13 -> V_86 . V_288 . V_289 = F_157 ;
V_13 -> V_86 . V_290 = 1 ;
V_2 -> V_291 = F_159 ;
}
}
static void F_165 ( struct V_1 * V_2 , unsigned int V_10 ,
bool V_276 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_292 = V_13 -> V_262 ;
if ( V_13 -> V_278 )
V_276 = ! V_276 ;
if ( V_276 )
V_13 -> V_262 &= ~ V_10 ;
else
V_13 -> V_262 |= V_10 ;
if ( V_13 -> V_262 != V_292 )
F_2 ( V_2 , 0x01 , 0 , V_148 ,
V_13 -> V_262 ) ;
}
static void F_166 ( void * V_275 , int V_276 )
{
struct V_1 * V_2 = V_275 ;
struct V_12 * V_13 = V_2 -> V_13 ;
F_165 ( V_2 , V_13 -> V_293 , V_276 ) ;
}
static void F_167 ( struct V_1 * V_2 ,
struct V_28 * V_205 ,
struct V_30 * V_206 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_206 )
F_165 ( V_2 , V_13 -> V_294 ,
V_206 -> V_35 . integer . V_35 [ 0 ] ||
V_206 -> V_35 . integer . V_35 [ 1 ] ) ;
}
static void F_168 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_265 V_295 [] = {
{ 0x01 , V_171 , 0x18 } ,
{ 0x01 , V_172 , 0x18 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_288 . V_289 = F_166 ;
V_13 -> V_86 . V_296 = F_167 ;
V_13 -> V_262 = 0 ;
V_13 -> V_278 = 0 ;
V_13 -> V_293 = 0x08 ;
V_13 -> V_294 = 0x10 ;
F_81 ( V_2 , V_295 ) ;
}
}
static void F_169 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_265 V_295 [] = {
{ 0x01 , V_171 , 0x22 } ,
{ 0x01 , V_172 , 0x22 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_288 . V_289 = F_166 ;
V_13 -> V_86 . V_296 = F_167 ;
V_13 -> V_262 = 0 ;
V_13 -> V_278 = 0 ;
V_13 -> V_293 = 0x02 ;
V_13 -> V_294 = 0x20 ;
F_81 ( V_2 , V_295 ) ;
}
}
static void F_170 ( struct V_1 * V_2 ,
struct V_28 * V_205 ,
struct V_30 * V_206 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_277 , V_297 , V_298 ;
V_277 = F_94 ( V_2 , V_13 -> V_283 ) ;
V_277 &= ~ V_280 ;
V_297 = V_277 | V_178 ;
V_298 = V_277 | V_281 ;
if ( ! V_206 )
return;
if ( V_206 -> V_35 . integer . V_35 [ 0 ] ||
V_206 -> V_35 . integer . V_35 [ 1 ] )
V_277 = V_298 ;
else
V_277 = V_297 ;
if ( V_13 -> V_283 )
F_158 ( V_2 , V_13 -> V_283 , V_277 ) ;
}
static void F_171 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_265 V_295 [] = {
{ 0x01 , V_171 , 0x08 } ,
{ 0x01 , V_172 , 0x08 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_288 . V_289 = F_166 ;
V_13 -> V_86 . V_296 = F_170 ;
V_13 -> V_262 = 0 ;
V_13 -> V_278 = 0 ;
V_13 -> V_293 = 0x08 ;
V_13 -> V_283 = 0x18 ;
F_81 ( V_2 , V_295 ) ;
V_2 -> V_291 = F_159 ;
}
}
static void F_172 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_265 V_295 [] = {
{ 0x01 , V_171 , 0x18 } ,
{ 0x01 , V_172 , 0x18 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_288 . V_289 = F_166 ;
V_13 -> V_86 . V_296 = F_170 ;
V_13 -> V_262 = 0 ;
V_13 -> V_278 = 0 ;
V_13 -> V_293 = 0x08 ;
V_13 -> V_283 = 0x18 ;
F_81 ( V_2 , V_295 ) ;
V_2 -> V_291 = F_159 ;
}
}
static void F_173 ( struct V_1 * V_2 ,
struct V_26 * V_299 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_174 ( V_13 -> V_300 , V_13 -> V_301 [ V_302 ] , 1 ) ;
F_175 ( V_13 -> V_300 ) ;
F_174 ( V_13 -> V_300 , V_13 -> V_301 [ V_302 ] , 0 ) ;
F_175 ( V_13 -> V_300 ) ;
}
static int F_176 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_67 ;
V_13 -> V_300 = F_177 () ;
if ( ! V_13 -> V_300 ) {
F_178 ( V_2 , L_26 ) ;
return - V_99 ;
}
V_13 -> V_301 [ V_302 ] = V_303 ;
V_13 -> V_300 -> V_98 = L_27 ;
V_13 -> V_300 -> V_304 [ 0 ] = F_179 ( V_305 ) ;
V_13 -> V_300 -> V_306 = sizeof( V_13 -> V_301 [ 0 ] ) ;
V_13 -> V_300 -> V_307 = F_11 ( V_13 -> V_301 ) ;
V_13 -> V_300 -> V_308 = V_13 -> V_301 ;
for ( V_67 = 0 ; V_67 < F_11 ( V_13 -> V_301 ) ; V_67 ++ )
F_180 ( V_13 -> V_301 [ V_67 ] , V_13 -> V_300 -> V_309 ) ;
if ( F_181 ( V_13 -> V_300 ) ) {
F_178 ( V_2 , L_28 ) ;
F_182 ( V_13 -> V_300 ) ;
V_13 -> V_300 = NULL ;
return - V_99 ;
}
return 0 ;
}
static void F_183 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static const struct V_265 V_295 [] = {
{ 0x01 , V_171 , 0x1e } ,
{ 0x01 , V_172 , 0x1a } ,
{ 0x01 , V_148 , 0x02 } ,
{}
} ;
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
if ( F_176 ( V_2 ) != 0 )
return;
F_81 ( V_2 , V_295 ) ;
F_184 ( V_2 , V_2 -> V_39 . V_106 , 0 ,
V_310 , 0x04 ) ;
F_73 ( V_2 , V_2 -> V_39 . V_106 ,
F_173 ) ;
V_13 -> V_86 . V_288 . V_289 = F_166 ;
V_13 -> V_86 . V_296 = F_167 ;
V_13 -> V_262 = 0 ;
V_13 -> V_278 = 0 ;
V_13 -> V_293 = 0x08 ;
V_13 -> V_294 = 0x10 ;
return;
}
if ( ! V_13 -> V_300 )
return;
switch ( V_57 ) {
case V_63 :
V_13 -> V_85 = V_54 ;
break;
case V_311 :
F_185 ( V_13 -> V_300 ) ;
V_13 -> V_300 = NULL ;
}
}
static void F_186 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static const struct V_265 V_295 [] = {
{ 0x01 , V_171 , 0x04 } ,
{ 0x01 , V_172 , 0x04 } ,
{}
} ;
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
if ( F_176 ( V_2 ) != 0 )
return;
F_81 ( V_2 , V_295 ) ;
F_73 ( V_2 , 0x1b ,
F_173 ) ;
V_13 -> V_86 . V_296 = F_167 ;
V_13 -> V_262 = 0 ;
V_13 -> V_278 = 0 ;
V_13 -> V_294 = 0x04 ;
return;
}
if ( ! V_13 -> V_300 )
return;
switch ( V_57 ) {
case V_63 :
V_13 -> V_85 = V_54 ;
break;
case V_311 :
F_185 ( V_13 -> V_300 ) ;
V_13 -> V_300 = NULL ;
}
}
static void F_187 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_288 . V_289 = F_157 ;
V_13 -> V_86 . V_296 = F_170 ;
V_13 -> V_278 = 0 ;
V_13 -> V_279 = 0x1a ;
V_13 -> V_283 = 0x18 ;
V_13 -> V_86 . V_290 = 1 ;
V_2 -> V_291 = F_159 ;
}
}
static void F_188 ( struct V_1 * V_2 )
{
static struct V_15 V_312 [] = {
F_189 ( 0x45 , 0xd089 ) ,
F_190 ( 0x57 , 0x05 , 1 << 14 , 0 ) ,
F_189 ( 0x06 , 0x6104 ) ,
F_191 ( 0x57 , 0x03 , 0x8aa6 ) ,
{}
} ;
static struct V_15 V_313 [] = {
F_189 ( 0x1b , 0x0c0b ) ,
{}
} ;
static struct V_15 V_314 [] = {
F_189 ( 0x1b , 0x0c4b ) ,
{}
} ;
static struct V_15 V_315 [] = {
F_189 ( 0x1b , 0x0c0b ) ,
F_189 ( 0x45 , 0xc429 ) ,
F_192 ( 0x35 , 0x4000 , 0 ) ,
F_189 ( 0x06 , 0x2104 ) ,
F_189 ( 0x1a , 0x0001 ) ,
F_189 ( 0x26 , 0x0004 ) ,
F_189 ( 0x32 , 0x42a3 ) ,
{}
} ;
static struct V_15 V_316 [] = {
F_192 ( 0x4f , 0xfcc0 , 0xc400 ) ,
F_192 ( 0x50 , 0x2000 , 0x2000 ) ,
F_192 ( 0x56 , 0x0006 , 0x0006 ) ,
F_192 ( 0x66 , 0x0008 , 0 ) ,
F_192 ( 0x67 , 0x2000 , 0 ) ,
{}
} ;
static struct V_15 V_317 [] = {
F_192 ( 0x19 , 0x1300 , 0x0300 ) ,
{}
} ;
static struct V_15 V_318 [] = {
F_189 ( 0x76 , 0x000e ) ,
F_189 ( 0x6c , 0x2400 ) ,
F_189 ( 0x18 , 0x7308 ) ,
F_189 ( 0x6b , 0xc429 ) ,
{}
} ;
static struct V_15 V_319 [] = {
F_192 ( 0x10 , 7 << 8 , 6 << 8 ) ,
F_190 ( 0x57 , 0x05 , 1 << 15 | 1 << 13 , 0x0 ) ,
F_190 ( 0x57 , 0x03 , 1 << 10 , 1 << 10 ) ,
F_192 ( 0x1a , 1 << 3 , 1 << 3 ) ,
F_189 ( 0x45 , 0xc429 ) ,
F_192 ( 0x4a , 0x000f , 0x000e ) ,
{}
} ;
static struct V_15 V_320 [] = {
F_189 ( 0x15 , 0x0d40 ) ,
F_189 ( 0xb7 , 0x802b ) ,
{}
} ;
static struct V_15 V_321 [] = {
F_192 ( 0x63 , 3 << 14 , 0 ) ,
{}
} ;
static struct V_15 V_322 [] = {
F_192 ( 0x4a , 0x0100 , 0 ) ,
F_190 ( 0x57 , 0x05 , 0x4000 , 0 ) ,
F_192 ( 0x6b , 0xf000 , 0x5000 ) ,
F_192 ( 0x4a , 0x0010 , 0 ) ,
F_192 ( 0x4a , 0x0c00 , 0x0c00 ) ,
F_189 ( 0x45 , 0x5289 ) ,
F_192 ( 0x4a , 0x0c00 , 0 ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0255 :
F_8 ( V_2 , V_313 ) ;
F_8 ( V_2 , V_312 ) ;
break;
case 0x10ec0236 :
case 0x10ec0256 :
F_8 ( V_2 , V_314 ) ;
F_8 ( V_2 , V_312 ) ;
break;
case 0x10ec0234 :
case 0x10ec0274 :
case 0x10ec0294 :
F_8 ( V_2 , V_322 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_315 ) ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
F_8 ( V_2 , V_316 ) ;
break;
case 0x10ec0298 :
F_8 ( V_2 , V_317 ) ;
F_8 ( V_2 , V_316 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_318 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_319 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_320 ) ;
break;
case 0x10ec0225 :
case 0x10ec0295 :
case 0x10ec0299 :
F_8 ( V_2 , V_321 ) ;
break;
case 0x10ec0867 :
F_5 ( V_2 , 0x57 , 0x5 , 1 << 14 , 0 ) ;
break;
}
F_38 ( V_2 , L_29 ) ;
}
static void F_193 ( struct V_1 * V_2 , T_1 V_251 ,
T_1 V_242 )
{
static struct V_15 V_312 [] = {
F_191 ( 0x57 , 0x03 , 0x8aa6 ) ,
F_189 ( 0x06 , 0x6100 ) ,
{}
} ;
static struct V_15 V_315 [] = {
F_192 ( 0x35 , 0 , 1 << 14 ) ,
F_189 ( 0x06 , 0x2100 ) ,
F_189 ( 0x1a , 0x0021 ) ,
F_189 ( 0x26 , 0x008c ) ,
{}
} ;
static struct V_15 V_316 [] = {
F_192 ( 0x4f , 0x00c0 , 0 ) ,
F_192 ( 0x50 , 0x2000 , 0 ) ,
F_192 ( 0x56 , 0x0006 , 0 ) ,
F_192 ( 0x4f , 0xfcc0 , 0xc400 ) ,
F_192 ( 0x66 , 0x0008 , 0x0008 ) ,
F_192 ( 0x67 , 0x2000 , 0x2000 ) ,
{}
} ;
static struct V_15 V_318 [] = {
F_189 ( 0x19 , 0xa208 ) ,
F_189 ( 0x2e , 0xacf0 ) ,
{}
} ;
static struct V_15 V_319 [] = {
F_190 ( 0x57 , 0x05 , 0 , 1 << 15 | 1 << 13 ) ,
F_190 ( 0x57 , 0x03 , 1 << 10 , 0 ) ,
F_192 ( 0x1a , 1 << 3 , 0 ) ,
{}
} ;
static struct V_15 V_323 [] = {
F_189 ( 0xb7 , 0x802b ) ,
F_189 ( 0xb5 , 0x1040 ) ,
F_192 ( 0xc3 , 0 , 1 << 12 ) ,
{}
} ;
static struct V_15 V_321 [] = {
F_190 ( 0x57 , 0x05 , 1 << 14 , 1 << 14 ) ,
F_192 ( 0x4a , 3 << 4 , 2 << 4 ) ,
F_192 ( 0x63 , 3 << 14 , 0 ) ,
{}
} ;
static struct V_15 V_322 [] = {
F_190 ( 0x57 , 0x05 , 0x4000 , 0x4000 ) ,
F_192 ( 0x4a , 0x0010 , 0 ) ,
F_192 ( 0x6b , 0xf000 , 0 ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0236 :
case 0x10ec0255 :
case 0x10ec0256 :
F_126 ( V_2 , 0x45 , 0xc489 ) ;
F_158 ( V_2 , V_251 , 0 ) ;
F_8 ( V_2 , V_312 ) ;
F_158 ( V_2 , V_242 , V_324 ) ;
break;
case 0x10ec0234 :
case 0x10ec0274 :
case 0x10ec0294 :
F_126 ( V_2 , 0x45 , 0x4689 ) ;
F_158 ( V_2 , V_251 , 0 ) ;
F_8 ( V_2 , V_322 ) ;
F_158 ( V_2 , V_242 , V_324 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_126 ( V_2 , 0x45 , 0xc429 ) ;
F_158 ( V_2 , V_251 , 0 ) ;
F_8 ( V_2 , V_315 ) ;
F_158 ( V_2 , V_242 , V_324 ) ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
case 0x10ec0298 :
F_158 ( V_2 , V_251 , 0 ) ;
F_8 ( V_2 , V_316 ) ;
F_158 ( V_2 , V_242 , V_324 ) ;
break;
case 0x10ec0292 :
F_158 ( V_2 , V_251 , 0 ) ;
F_8 ( V_2 , V_318 ) ;
break;
case 0x10ec0293 :
F_126 ( V_2 , 0x45 , 0xc429 ) ;
F_158 ( V_2 , V_251 , 0 ) ;
F_8 ( V_2 , V_319 ) ;
F_158 ( V_2 , V_242 , V_324 ) ;
break;
case 0x10ec0867 :
F_5 ( V_2 , 0x57 , 0x5 , 0 , 1 << 14 ) ;
case 0x10ec0221 :
case 0x10ec0662 :
F_158 ( V_2 , V_251 , 0 ) ;
F_158 ( V_2 , V_242 , V_324 ) ;
break;
case 0x10ec0668 :
F_126 ( V_2 , 0x11 , 0x0001 ) ;
F_158 ( V_2 , V_251 , 0 ) ;
F_8 ( V_2 , V_323 ) ;
F_158 ( V_2 , V_242 , V_324 ) ;
break;
case 0x10ec0225 :
case 0x10ec0295 :
case 0x10ec0299 :
F_8 ( V_2 , V_325 ) ;
F_21 ( V_2 , 0x45 , 0x3f << 10 , 0x31 << 10 ) ;
F_158 ( V_2 , V_251 , 0 ) ;
F_8 ( V_2 , V_321 ) ;
F_158 ( V_2 , V_242 , V_324 ) ;
break;
}
F_38 ( V_2 , L_30 ) ;
}
static void F_194 ( struct V_1 * V_2 )
{
static struct V_15 V_321 [] = {
F_192 ( 0x45 , 0x3f << 10 , 0x30 << 10 ) ,
F_192 ( 0x45 , 0x3f << 10 , 0x31 << 10 ) ,
F_192 ( 0x49 , 3 << 8 , 0 << 8 ) ,
F_192 ( 0x4a , 3 << 4 , 3 << 4 ) ,
F_192 ( 0x63 , 3 << 14 , 0 ) ,
F_192 ( 0x67 , 0xf000 , 0x3000 ) ,
{}
} ;
static struct V_15 V_312 [] = {
F_189 ( 0x45 , 0xc089 ) ,
F_189 ( 0x45 , 0xc489 ) ,
F_191 ( 0x57 , 0x03 , 0x8ea6 ) ,
F_189 ( 0x49 , 0x0049 ) ,
{}
} ;
static struct V_15 V_315 [] = {
F_189 ( 0x06 , 0x2100 ) ,
F_189 ( 0x32 , 0x4ea3 ) ,
{}
} ;
static struct V_15 V_316 [] = {
F_192 ( 0x4f , 0xfcc0 , 0xc400 ) ,
F_192 ( 0x50 , 0x2000 , 0x2000 ) ,
F_192 ( 0x56 , 0x0006 , 0x0006 ) ,
F_192 ( 0x66 , 0x0008 , 0 ) ,
F_192 ( 0x67 , 0x2000 , 0 ) ,
{}
} ;
static struct V_15 V_318 [] = {
F_189 ( 0x76 , 0x000e ) ,
F_189 ( 0x6c , 0x2400 ) ,
F_189 ( 0x6b , 0xc429 ) ,
F_189 ( 0x18 , 0x7308 ) ,
{}
} ;
static struct V_15 V_319 [] = {
F_192 ( 0x4a , 0x000f , 0x000e ) ,
F_189 ( 0x45 , 0xC429 ) ,
F_192 ( 0x1a , 1 << 3 , 0 ) ,
{}
} ;
static struct V_15 V_323 [] = {
F_189 ( 0x11 , 0x0041 ) ,
F_189 ( 0x15 , 0x0d40 ) ,
F_189 ( 0xb7 , 0x802b ) ,
{}
} ;
static struct V_15 V_322 [] = {
F_189 ( 0x45 , 0x4289 ) ,
F_192 ( 0x4a , 0x0010 , 0x0010 ) ,
F_192 ( 0x6b , 0x0f00 , 0 ) ,
F_192 ( 0x49 , 0x0300 , 0x0300 ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0225 :
case 0x10ec0295 :
case 0x10ec0299 :
F_8 ( V_2 , V_325 ) ;
F_8 ( V_2 , V_321 ) ;
break;
case 0x10ec0236 :
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_312 ) ;
break;
case 0x10ec0234 :
case 0x10ec0274 :
case 0x10ec0294 :
F_8 ( V_2 , V_322 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_315 ) ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
case 0x10ec0298 :
F_8 ( V_2 , V_316 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_318 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_319 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_323 ) ;
break;
case 0x10ec0867 :
F_5 ( V_2 , 0x57 , 0x5 , 1 << 14 , 0 ) ;
break;
}
F_38 ( V_2 , L_31 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
int V_5 ;
static struct V_15 V_312 [] = {
F_189 ( 0x45 , 0xd489 ) ,
F_189 ( 0x1b , 0x0c2b ) ,
F_191 ( 0x57 , 0x03 , 0x8ea6 ) ,
{}
} ;
static struct V_15 V_314 [] = {
F_189 ( 0x45 , 0xd489 ) ,
F_189 ( 0x1b , 0x0c6b ) ,
F_191 ( 0x57 , 0x03 , 0x8ea6 ) ,
{}
} ;
static struct V_15 V_315 [] = {
F_189 ( 0x45 , 0xd429 ) ,
F_189 ( 0x1b , 0x0c2b ) ,
F_189 ( 0x32 , 0x4ea3 ) ,
{}
} ;
static struct V_15 V_316 [] = {
F_192 ( 0x50 , 0x2000 , 0x2000 ) ,
F_192 ( 0x56 , 0x0006 , 0x0006 ) ,
F_192 ( 0x66 , 0x0008 , 0 ) ,
F_192 ( 0x67 , 0x2000 , 0 ) ,
{}
} ;
static struct V_15 V_318 [] = {
F_189 ( 0x6b , 0xd429 ) ,
F_189 ( 0x76 , 0x0008 ) ,
F_189 ( 0x18 , 0x7388 ) ,
{}
} ;
static struct V_15 V_319 [] = {
F_189 ( 0x45 , 0xd429 ) ,
F_192 ( 0x10 , 7 << 8 , 7 << 8 ) ,
{}
} ;
static struct V_15 V_323 [] = {
F_189 ( 0x11 , 0x0001 ) ,
F_189 ( 0x15 , 0x0d60 ) ,
F_189 ( 0xc3 , 0x0000 ) ,
{}
} ;
static struct V_15 V_326 [] = {
F_192 ( 0x45 , 0x3f << 10 , 0x35 << 10 ) ,
F_192 ( 0x63 , 3 << 14 , 2 << 14 ) ,
{}
} ;
static struct V_15 V_327 [] = {
F_192 ( 0x45 , 0x3f << 10 , 0x35 << 10 ) ,
F_192 ( 0x63 , 3 << 14 , 1 << 14 ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0255 :
F_8 ( V_2 , V_312 ) ;
break;
case 0x10ec0236 :
case 0x10ec0256 :
F_8 ( V_2 , V_314 ) ;
break;
case 0x10ec0234 :
case 0x10ec0274 :
case 0x10ec0294 :
F_126 ( V_2 , 0x45 , 0xd689 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_315 ) ;
break;
case 0x10ec0298 :
V_5 = F_7 ( V_2 , 0x50 ) ;
if ( V_5 & ( 1 << 12 ) ) {
F_21 ( V_2 , 0x8e , 0x0070 , 0x0020 ) ;
F_21 ( V_2 , 0x4f , 0xfcc0 , 0xd400 ) ;
F_29 ( 300 ) ;
} else {
F_21 ( V_2 , 0x8e , 0x0070 , 0x0010 ) ;
F_21 ( V_2 , 0x4f , 0xfcc0 , 0xd400 ) ;
F_29 ( 300 ) ;
}
break;
case 0x10ec0286 :
case 0x10ec0288 :
F_21 ( V_2 , 0x4f , 0xfcc0 , 0xd400 ) ;
F_29 ( 300 ) ;
F_8 ( V_2 , V_316 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_318 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_319 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_323 ) ;
break;
case 0x10ec0225 :
case 0x10ec0295 :
case 0x10ec0299 :
V_5 = F_7 ( V_2 , 0x45 ) ;
if ( V_5 & ( 1 << 9 ) )
F_8 ( V_2 , V_327 ) ;
else
F_8 ( V_2 , V_326 ) ;
break;
case 0x10ec0867 :
F_5 ( V_2 , 0x57 , 0x5 , 1 << 14 , 0 ) ;
break;
}
F_38 ( V_2 , L_32 ) ;
}
static void F_196 ( struct V_1 * V_2 )
{
static struct V_15 V_312 [] = {
F_189 ( 0x45 , 0xe489 ) ,
F_189 ( 0x1b , 0x0c2b ) ,
F_191 ( 0x57 , 0x03 , 0x8ea6 ) ,
{}
} ;
static struct V_15 V_314 [] = {
F_189 ( 0x45 , 0xe489 ) ,
F_189 ( 0x1b , 0x0c6b ) ,
F_191 ( 0x57 , 0x03 , 0x8ea6 ) ,
{}
} ;
static struct V_15 V_315 [] = {
F_189 ( 0x45 , 0xe429 ) ,
F_189 ( 0x1b , 0x0c2b ) ,
F_189 ( 0x32 , 0x4ea3 ) ,
{}
} ;
static struct V_15 V_316 [] = {
F_192 ( 0x50 , 0x2000 , 0x2000 ) ,
F_192 ( 0x56 , 0x0006 , 0x0006 ) ,
F_192 ( 0x66 , 0x0008 , 0 ) ,
F_192 ( 0x67 , 0x2000 , 0 ) ,
{}
} ;
static struct V_15 V_318 [] = {
F_189 ( 0x6b , 0xe429 ) ,
F_189 ( 0x76 , 0x0008 ) ,
F_189 ( 0x18 , 0x7388 ) ,
{}
} ;
static struct V_15 V_319 [] = {
F_189 ( 0x45 , 0xe429 ) ,
F_192 ( 0x10 , 7 << 8 , 7 << 8 ) ,
{}
} ;
static struct V_15 V_323 [] = {
F_189 ( 0x11 , 0x0001 ) ,
F_189 ( 0x15 , 0x0d50 ) ,
F_189 ( 0xc3 , 0x0000 ) ,
{}
} ;
static struct V_15 V_321 [] = {
F_192 ( 0x45 , 0x3f << 10 , 0x39 << 10 ) ,
F_192 ( 0x63 , 3 << 14 , 2 << 14 ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0255 :
F_8 ( V_2 , V_312 ) ;
break;
case 0x10ec0236 :
case 0x10ec0256 :
F_8 ( V_2 , V_314 ) ;
break;
case 0x10ec0234 :
case 0x10ec0274 :
case 0x10ec0294 :
F_126 ( V_2 , 0x45 , 0xe689 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_315 ) ;
break;
case 0x10ec0298 :
F_21 ( V_2 , 0x8e , 0x0070 , 0x0010 ) ;
F_21 ( V_2 , 0x4f , 0xfcc0 , 0xe400 ) ;
F_29 ( 300 ) ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
F_21 ( V_2 , 0x4f , 0xfcc0 , 0xe400 ) ;
F_29 ( 300 ) ;
F_8 ( V_2 , V_316 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_318 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_319 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_323 ) ;
break;
case 0x10ec0225 :
case 0x10ec0295 :
case 0x10ec0299 :
F_8 ( V_2 , V_321 ) ;
break;
}
F_38 ( V_2 , L_33 ) ;
}
static void F_197 ( struct V_1 * V_2 )
{
int V_5 ;
bool V_328 = false ;
struct V_12 * V_13 = V_2 -> V_13 ;
static struct V_15 V_312 [] = {
F_189 ( 0x45 , 0xd089 ) ,
F_189 ( 0x49 , 0x0149 ) ,
{}
} ;
static struct V_15 V_316 [] = {
F_192 ( 0x4f , 0xfcc0 , 0xd400 ) ,
{}
} ;
static struct V_15 V_317 [] = {
F_192 ( 0x50 , 0x2000 , 0x2000 ) ,
F_192 ( 0x56 , 0x0006 , 0x0006 ) ,
F_192 ( 0x66 , 0x0008 , 0 ) ,
F_192 ( 0x67 , 0x2000 , 0 ) ,
F_192 ( 0x19 , 0x1300 , 0x1300 ) ,
{}
} ;
static struct V_15 V_319 [] = {
F_192 ( 0x4a , 0x000f , 0x0008 ) ,
F_189 ( 0x45 , 0xD429 ) ,
{}
} ;
static struct V_15 V_323 [] = {
F_189 ( 0x11 , 0x0001 ) ,
F_189 ( 0xb7 , 0x802b ) ,
F_189 ( 0x15 , 0x0d60 ) ,
F_189 ( 0xc3 , 0x0c00 ) ,
{}
} ;
static struct V_15 V_322 [] = {
F_192 ( 0x4a , 0x0010 , 0 ) ,
F_192 ( 0x4a , 0x8000 , 0 ) ,
F_189 ( 0x45 , 0xd289 ) ,
F_192 ( 0x49 , 0x0300 , 0x0300 ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0236 :
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_312 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_328 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0234 :
case 0x10ec0274 :
case 0x10ec0294 :
F_8 ( V_2 , V_322 ) ;
F_29 ( 80 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_328 = ( V_5 & 0x00f0 ) == 0x00f0 ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_126 ( V_2 , 0x45 , 0xd029 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_328 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0298 :
F_2 ( V_2 , 0x21 , 0 ,
V_254 , V_255 ) ;
F_29 ( 100 ) ;
F_2 ( V_2 , 0x21 , 0 ,
V_247 , 0x0 ) ;
F_29 ( 200 ) ;
V_5 = F_7 ( V_2 , 0x50 ) ;
if ( V_5 & ( 1 << 12 ) ) {
F_21 ( V_2 , 0x8e , 0x0070 , 0x0020 ) ;
F_8 ( V_2 , V_316 ) ;
F_29 ( 350 ) ;
V_5 = F_7 ( V_2 , 0x50 ) ;
V_328 = ( V_5 & 0x0070 ) == 0x0070 ;
} else {
F_21 ( V_2 , 0x8e , 0x0070 , 0x0010 ) ;
F_8 ( V_2 , V_316 ) ;
F_29 ( 350 ) ;
V_5 = F_7 ( V_2 , 0x50 ) ;
V_328 = ( V_5 & 0x0070 ) == 0x0070 ;
}
F_8 ( V_2 , V_317 ) ;
F_2 ( V_2 , 0x21 , 0 ,
V_247 , V_329 ) ;
F_29 ( 75 ) ;
F_2 ( V_2 , 0x21 , 0 ,
V_254 , V_330 ) ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
F_8 ( V_2 , V_316 ) ;
F_29 ( 350 ) ;
V_5 = F_7 ( V_2 , 0x50 ) ;
V_328 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0292 :
F_126 ( V_2 , 0x6b , 0xd429 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x6c ) ;
V_328 = ( V_5 & 0x001c ) == 0x001c ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_319 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_328 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_323 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0xbe ) ;
V_328 = ( V_5 & 0x1c02 ) == 0x1c02 ;
break;
case 0x10ec0225 :
case 0x10ec0295 :
case 0x10ec0299 :
F_8 ( V_2 , V_325 ) ;
F_21 ( V_2 , 0x67 , 0xf000 , 0x1000 ) ;
V_5 = F_7 ( V_2 , 0x45 ) ;
if ( V_5 & ( 1 << 9 ) ) {
F_21 ( V_2 , 0x45 , 0x3f << 10 , 0x34 << 10 ) ;
F_21 ( V_2 , 0x49 , 3 << 8 , 2 << 8 ) ;
F_29 ( 800 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_328 = ( V_5 & 0x00f0 ) == 0x00f0 ;
} else {
F_21 ( V_2 , 0x45 , 0x3f << 10 , 0x34 << 10 ) ;
F_21 ( V_2 , 0x49 , 3 << 8 , 1 << 8 ) ;
F_29 ( 800 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_328 = ( V_5 & 0x00f0 ) == 0x00f0 ;
}
F_21 ( V_2 , 0x4a , 7 << 6 , 7 << 6 ) ;
F_21 ( V_2 , 0x4a , 3 << 4 , 3 << 4 ) ;
F_21 ( V_2 , 0x67 , 0xf000 , 0x3000 ) ;
break;
case 0x10ec0867 :
V_328 = true ;
break;
}
F_38 ( V_2 , L_34 ,
V_328 ? L_35 : L_36 ) ;
V_13 -> V_331 = V_328 ? V_332 : V_333 ;
}
static void F_198 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_334 = V_13 -> V_86 . V_335 [ V_13 -> V_86 . V_336 [ 0 ] ] ;
T_1 V_251 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
int V_337 ;
if ( ! F_125 ( V_2 , V_251 ) )
V_337 = V_338 ;
else if ( V_334 == V_13 -> V_339 )
V_337 = V_340 ;
else if ( V_334 == V_13 -> V_341 )
V_337 = V_342 ;
else
V_337 = V_343 ;
if ( V_337 == V_13 -> V_344 ) {
F_153 ( V_2 ) ;
return;
}
switch ( V_337 ) {
case V_338 :
F_188 ( V_2 ) ;
V_13 -> V_86 . V_149 = false ;
break;
case V_340 :
if ( V_13 -> V_331 == V_345 )
F_197 ( V_2 ) ;
if ( V_13 -> V_331 == V_332 )
F_195 ( V_2 ) ;
else if ( V_13 -> V_331 == V_333 )
F_196 ( V_2 ) ;
V_13 -> V_86 . V_149 = true ;
break;
case V_342 :
F_193 ( V_2 , V_251 , V_13 -> V_341 ) ;
V_13 -> V_86 . V_149 = false ;
break;
case V_343 :
F_194 ( V_2 ) ;
V_13 -> V_86 . V_149 = true ;
break;
}
if ( V_337 != V_342 ) {
F_158 ( V_2 , V_251 ,
V_346 | V_347 ) ;
if ( V_13 -> V_341 && V_13 -> V_341 != V_251 )
F_158 ( V_2 , V_13 -> V_341 ,
V_348 ) ;
}
V_13 -> V_344 = V_337 ;
F_153 ( V_2 ) ;
}
static void F_199 ( struct V_1 * V_2 ,
struct V_28 * V_205 ,
struct V_30 * V_206 )
{
F_198 ( V_2 ) ;
}
static void F_200 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_331 = V_345 ;
V_153 ( V_2 , V_27 ) ;
}
static void F_201 ( struct V_1 * V_2 )
{
int V_67 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_128 * V_129 = & V_13 -> V_86 . V_87 ;
for ( V_67 = 0 ; V_67 < V_129 -> V_349 ; V_67 ++ ) {
if ( V_129 -> V_350 [ V_67 ] . V_351 && ! V_13 -> V_339 )
V_13 -> V_339 = V_129 -> V_350 [ V_67 ] . V_163 ;
if ( V_129 -> V_350 [ V_67 ] . V_352 && ! V_13 -> V_341 )
V_13 -> V_341 = V_129 -> V_350 [ V_67 ] . V_163 ;
}
V_13 -> V_86 . V_296 = F_199 ;
V_13 -> V_86 . V_150 = F_198 ;
V_13 -> V_86 . V_274 = F_200 ;
}
static void F_202 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
switch ( V_57 ) {
case V_58 :
V_13 -> V_130 |= V_264 | V_353 ;
break;
case V_63 :
F_201 ( V_2 ) ;
break;
case V_103 :
V_13 -> V_344 = 0 ;
F_198 ( V_2 ) ;
break;
}
}
static void F_203 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_130 |= V_264 ;
}
else
F_202 ( V_2 , V_56 , V_57 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
static struct V_15 V_354 [] = {
F_189 ( 0x1b , 0x880b ) ,
F_189 ( 0x45 , 0xd089 ) ,
F_189 ( 0x1b , 0x080b ) ,
F_189 ( 0x46 , 0x0004 ) ,
F_189 ( 0x1b , 0x0c0b ) ,
{}
} ;
static struct V_15 V_355 [] = {
F_189 ( 0x1b , 0x884b ) ,
F_189 ( 0x45 , 0xd089 ) ,
F_189 ( 0x1b , 0x084b ) ,
F_189 ( 0x46 , 0x0004 ) ,
F_189 ( 0x1b , 0x0c4b ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0255 :
F_8 ( V_2 , V_354 ) ;
break;
case 0x10ec0236 :
case 0x10ec0256 :
F_8 ( V_2 , V_355 ) ;
break;
}
F_29 ( 30 ) ;
}
static void F_205 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
F_204 ( V_2 ) ;
}
F_202 ( V_2 , V_56 , V_57 ) ;
}
static void F_206 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_130 |= V_264 ;
F_204 ( V_2 ) ;
}
else
F_202 ( V_2 , V_56 , V_57 ) ;
}
static void F_207 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_356 ;
F_200 ( V_2 , V_27 ) ;
V_356 = V_13 -> V_86 . V_149 ? 0x40 : 0 ;
F_2 ( V_2 , 0x01 , 0 , V_148 ,
V_356 ) ;
}
static void F_208 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
F_202 ( V_2 , V_56 , V_57 ) ;
if ( V_57 == V_63 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_274 = F_207 ;
}
}
static void F_209 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_357 = 1 ;
}
}
static void F_210 ( struct V_1 * V_2 )
{
}
static void F_211 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_63 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_104 = F_210 ;
}
}
static void F_212 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_131 = 0 ;
}
}
static void F_213 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static const struct V_154 V_155 [] = {
{ 0x16 , 0x21211010 } ,
{ 0x19 , 0x21a11010 } ,
{ }
} ;
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_104 = F_210 ;
V_13 -> V_105 = F_55 ;
V_13 -> V_130 = V_263 ;
V_2 -> V_358 = 0 ;
F_83 ( V_2 , V_155 ) ;
}
}
static void F_214 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_251 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
F_2 ( V_2 , V_251 , 0 ,
V_254 , V_255 ) ;
F_29 ( 20 ) ;
}
static void F_215 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_359 * V_360 = & V_13 -> V_86 . V_361 ;
int V_67 ;
switch ( V_57 ) {
case V_58 :
F_216 ( V_2 , 0x19 , V_348 ) ;
break;
case V_63 :
V_13 -> V_104 = F_214 ;
for ( V_67 = 0 ; V_67 < V_360 -> V_362 ; V_67 ++ ) {
if ( V_13 -> V_86 . V_335 [ V_67 ] == 0x12 ) {
V_13 -> V_86 . V_336 [ 0 ] = V_67 ;
break;
}
}
break;
}
}
static void F_217 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_130 |= V_264 ;
V_13 -> V_86 . V_158 = 1 ;
F_2 ( V_2 , 0x1b , 0 , V_254 , 0x7000 ) ;
F_218 ( V_2 , 0x1b , F_25 ( V_2 , 0x1b ) & ~ V_363 ) ;
} else
F_202 ( V_2 , V_56 , V_57 ) ;
}
static void F_219 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
F_126 ( V_2 , 0xc4 , 0x8000 ) ;
F_21 ( V_2 , 0xc2 , ~ 0xfe , 0 ) ;
F_158 ( V_2 , 0x18 , 0 ) ;
}
F_202 ( V_2 , V_56 , V_57 ) ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_128 * V_129 = & V_13 -> V_86 . V_87 ;
T_1 V_3 ;
unsigned int V_364 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_129 -> V_349 ; V_67 ++ ) {
if ( V_129 -> V_350 [ V_67 ] . type != V_365 )
continue;
V_3 = V_129 -> V_350 [ V_67 ] . V_163 ;
V_364 = F_36 ( V_2 , V_3 ) ;
if ( F_220 ( V_364 ) == V_366 )
continue;
return V_3 ;
}
return 0 ;
}
static void F_221 ( struct V_1 * V_2 ,
const struct V_55 * V_56 ,
int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_63 ) {
int V_242 = F_119 ( V_2 ) ;
int V_251 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
if ( F_10 ( ! V_242 || ! V_251 ) )
return;
F_222 ( V_2 , V_242 , V_251 ) ;
}
}
static void F_223 ( struct V_1 * V_2 ,
const struct V_55 * V_56 ,
int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_128 * V_129 = & V_13 -> V_86 . V_87 ;
int V_67 ;
if ( V_57 != V_63 )
return;
for ( V_67 = 0 ; V_67 < V_129 -> V_349 ; V_67 ++ ) {
T_1 V_3 = V_129 -> V_350 [ V_67 ] . V_163 ;
unsigned int V_364 ;
if ( V_129 -> V_350 [ V_67 ] . type != V_365 )
continue;
V_364 = F_36 ( V_2 , V_3 ) ;
if ( F_220 ( V_364 ) != V_366 )
continue;
F_116 ( V_2 , V_3 , V_145 ,
( 0x00 << V_216 ) |
( 0x01 << V_217 ) |
( 0x2f << V_218 ) |
( 0 << V_219 ) ) ;
}
}
static void F_224 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_272 ;
F_29 ( 200 ) ;
V_153 ( V_2 , V_27 ) ;
V_272 = V_13 -> V_86 . V_149 ? V_273 : 0 ;
F_29 ( 600 ) ;
F_2 ( V_2 , 0x19 , 0 , V_247 ,
V_272 ) ;
}
static void F_225 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
switch ( V_57 ) {
case V_58 :
F_218 ( V_2 , 0x03 , 0 ) ;
V_13 -> V_86 . V_131 = 0 ;
break;
case V_103 :
F_21 ( V_2 , 0x06 , 0x000c , 0 ) ;
F_21 ( V_2 , 0x1a , 0 , 1 << 4 ) ;
break;
}
}
static void F_226 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
switch ( V_57 ) {
case V_58 :
V_13 -> V_86 . V_274 = F_224 ;
break;
case V_103 :
F_21 ( V_2 , 0x06 , 0x000c , 0 ) ;
break;
}
}
static void F_227 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_153 ( V_2 ) ;
if ( F_125 ( V_2 , 0x1b ) )
V_13 -> V_86 . V_367 |= ( 1ULL << 0x14 ) ;
}
static void F_228 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_265 V_368 [] = {
{ 0x01 , V_171 , 0x04 } ,
{ 0x01 , V_172 , 0x04 } ,
{ 0x01 , V_148 , 0x04 } ,
{}
} ;
static const struct V_154 V_369 [] = {
{ 0x1b , 0x21114000 } ,
{}
} ;
switch ( V_57 ) {
case V_58 :
F_81 ( V_2 , V_368 ) ;
F_83 ( V_2 , V_369 ) ;
V_13 -> V_86 . V_357 = 1 ;
V_13 -> V_86 . V_150 = F_227 ;
F_73 ( V_2 , 0x1b ,
V_153 ) ;
break;
case V_101 :
F_102 ( V_2 , L_37 ,
L_38 ) ;
F_102 ( V_2 , L_39 ,
L_37 ) ;
break;
}
}
static void F_229 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
T_1 V_173 [ 2 ] = { 0x0c } ;
F_91 ( V_2 , 0x14 , 1 , V_173 ) ;
F_91 ( V_2 , 0x15 , 1 , V_173 ) ;
}
}
static void F_230 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
T_1 V_173 [ 1 ] = { 0x0c } ;
F_91 ( V_2 , 0x17 , 1 , V_173 ) ;
}
}
static void F_231 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
V_153 ( V_2 , V_27 ) ;
F_165 ( V_2 , 0x10 , ! V_13 -> V_86 . V_149 ) ;
}
static void F_232 ( struct V_1 * V_2 ,
const struct V_55 * V_56 ,
int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_265 V_295 [] = {
{ 0x01 , V_171 , 0x18 } ,
{ 0x01 , V_172 , 0x18 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_288 . V_289 = F_166 ;
V_13 -> V_86 . V_274 = F_231 ;
V_13 -> V_262 = 0 ;
V_13 -> V_278 = 0 ;
V_13 -> V_293 = 0x08 ;
F_81 ( V_2 , V_295 ) ;
}
}
static void F_233 ( struct V_1 * V_2 ,
const struct V_55 * V_56 ,
int V_57 )
{
F_101 ( V_2 , V_56 , V_57 ) ;
switch ( V_57 ) {
case V_58 :
strcpy ( V_2 -> V_191 -> V_192 , L_40 ) ;
break;
case V_101 :
F_102 ( V_2 , L_16 ,
V_2 -> V_193 == 0 ?
L_17 :
L_18 ) ;
F_102 ( V_2 , L_19 ,
V_2 -> V_193 == 0 ?
L_20 :
L_21 ) ;
break;
}
}
static void F_234 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_5 ;
if ( V_13 -> V_224 != V_230 )
return;
if ( ( F_6 ( V_2 ) & 0x00ff ) < 0x015 ) {
F_126 ( V_2 , 0xf , 0x960b ) ;
F_126 ( V_2 , 0xe , 0x8817 ) ;
}
if ( ( F_6 ( V_2 ) & 0x00ff ) == 0x016 ) {
F_126 ( V_2 , 0xf , 0x960b ) ;
F_126 ( V_2 , 0xe , 0x8814 ) ;
}
if ( ( F_6 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_21 ( V_2 , 0x04 , 0 , 1 << 11 ) ;
}
if ( ( F_6 ( V_2 ) & 0x00ff ) == 0x018 ) {
V_5 = F_7 ( V_2 , 0xd ) ;
if ( V_5 != - 1 && ( V_5 & 0x0c00 ) >> 10 != 0x1 ) {
F_126 ( V_2 , 0xd , V_5 | ( 1 << 10 ) ) ;
}
V_5 = F_7 ( V_2 , 0x17 ) ;
if ( V_5 != - 1 && ( V_5 & 0x01c0 ) >> 6 != 0x4 ) {
F_126 ( V_2 , 0x17 , V_5 | ( 1 << 7 ) ) ;
}
}
F_21 ( V_2 , 0x4 , 0 , 1 << 11 ) ;
}
static int F_235 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_201 = 0x18 ;
V_2 -> V_358 = 1 ;
#ifdef F_236
V_2 -> V_110 . V_370 = F_141 ;
V_2 -> V_110 . V_371 = F_143 ;
#endif
V_13 -> V_104 = F_134 ;
V_13 -> V_102 = F_133 ;
F_75 ( V_2 , V_372 ,
V_373 , V_374 ) ;
F_237 ( V_2 , V_375 , V_374 ) ;
F_75 ( V_2 , NULL , V_376 ,
V_374 ) ;
F_50 ( V_2 , V_58 ) ;
F_35 ( V_2 ) ;
if ( F_64 ( V_2 ) )
V_13 -> V_86 . V_139 = 0x01 ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0269 :
V_13 -> V_224 = V_225 ;
switch ( F_6 ( V_2 ) & 0x00f0 ) {
case 0x0010 :
if ( V_2 -> V_70 -> V_71 &&
V_2 -> V_70 -> V_71 -> V_122 == 0x1025 &&
V_13 -> V_59 . V_79 == 1 )
V_94 = F_63 ( V_2 , L_22 ) ;
V_13 -> V_224 = V_230 ;
break;
case 0x0020 :
if ( V_2 -> V_70 -> V_71 &&
V_2 -> V_70 -> V_71 -> V_122 == 0x17aa &&
V_2 -> V_70 -> V_71 -> V_73 == 0x21f3 )
V_94 = F_63 ( V_2 , L_41 ) ;
V_13 -> V_224 = V_226 ;
break;
case 0x0030 :
V_13 -> V_224 = V_231 ;
break;
default:
F_13 ( V_2 , 0x20 , 0x04 , 15 ) ;
}
if ( V_94 < 0 )
goto error;
V_13 -> V_104 = F_122 ;
V_13 -> V_102 = F_234 ;
F_234 ( V_2 ) ;
break;
case 0x10ec0280 :
case 0x10ec0290 :
V_13 -> V_224 = V_227 ;
break;
case 0x10ec0282 :
V_13 -> V_224 = V_232 ;
V_13 -> V_104 = F_127 ;
V_13 -> V_102 = F_124 ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
V_13 -> V_224 = V_233 ;
V_13 -> V_104 = F_130 ;
V_13 -> V_102 = F_129 ;
break;
case 0x10ec0284 :
case 0x10ec0292 :
V_13 -> V_224 = V_228 ;
break;
case 0x10ec0293 :
V_13 -> V_224 = V_229 ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
V_13 -> V_224 = V_234 ;
V_13 -> V_104 = F_118 ;
break;
case 0x10ec0298 :
V_13 -> V_224 = V_235 ;
break;
case 0x10ec0255 :
V_13 -> V_224 = V_236 ;
break;
case 0x10ec0236 :
case 0x10ec0256 :
V_13 -> V_224 = V_237 ;
V_13 -> V_104 = F_132 ;
V_13 -> V_102 = F_131 ;
V_13 -> V_86 . V_131 = 0 ;
F_21 ( V_2 , 0x36 , 1 << 13 , 1 << 5 ) ;
break;
case 0x10ec0215 :
case 0x10ec0285 :
case 0x10ec0289 :
V_13 -> V_224 = V_238 ;
V_13 -> V_86 . V_131 = 0 ;
break;
case 0x10ec0225 :
case 0x10ec0295 :
V_13 -> V_224 = V_239 ;
V_13 -> V_86 . V_131 = 0 ;
break;
case 0x10ec0299 :
V_13 -> V_224 = V_239 ;
V_13 -> V_86 . V_131 = 0 ;
break;
case 0x10ec0234 :
case 0x10ec0274 :
case 0x10ec0294 :
V_13 -> V_224 = V_240 ;
V_13 -> V_86 . V_131 = 0 ;
F_21 ( V_2 , 0x6b , 0x0018 , ( 1 << 4 ) | ( 1 << 3 ) ) ;
break;
case 0x10ec0700 :
case 0x10ec0701 :
case 0x10ec0703 :
V_13 -> V_224 = V_241 ;
V_13 -> V_86 . V_131 = 0 ;
F_21 ( V_2 , 0x4a , 0 , 1 << 15 ) ;
break;
}
if ( F_3 ( V_2 , 0x51 , 0 , V_377 , 0 ) == 0x10ec5505 ) {
V_13 -> V_261 = 1 ;
V_13 -> V_102 = F_139 ;
}
V_94 = F_117 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_144 && V_13 -> V_86 . V_139 && V_13 -> V_86 . V_131 )
F_76 ( V_13 , V_13 -> V_86 . V_131 , 0x04 , V_145 ) ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_77 ( V_2 ) ;
return V_94 ;
}
static int F_238 ( struct V_1 * V_2 )
{
static const T_1 V_378 [] = { 0x1d , 0 } ;
static const T_1 V_379 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_66 ( V_2 , V_378 , V_379 ) ;
}
static void F_239 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_5 ;
if ( V_57 != V_103 )
return;
V_5 = F_94 ( V_2 , 0x0f ) ;
if ( ! ( V_5 & ( V_380 | V_346 ) ) )
V_5 |= V_380 ;
V_5 |= V_181 ;
F_95 ( V_2 , 0x0f , V_5 ) ;
V_13 -> V_86 . V_179 = 1 ;
}
static void F_240 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 )
V_2 -> V_381 = 1 ;
}
static int F_241 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x15 ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_139 = 0x23 ;
#ifdef F_236
V_13 -> V_109 = F_57 ;
#endif
F_75 ( V_2 , NULL , V_382 , V_383 ) ;
F_50 ( V_2 , V_58 ) ;
V_94 = F_238 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_144 )
F_76 ( V_13 , 0x23 , 0 , V_384 ) ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_77 ( V_2 ) ;
return V_94 ;
}
static int F_242 ( struct V_1 * V_2 )
{
static const T_1 V_385 [] = { 0x1d , 0 } ;
static const T_1 V_386 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , V_385 , V_386 ) ;
}
static void F_243 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
F_244 ( V_2 , 0x18 , 0x00000734 ) ;
F_244 ( V_2 , 0x19 , 0x0000073c ) ;
}
}
static int F_245 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_139 = 0x23 ;
V_13 -> V_104 = F_28 ;
F_75 ( V_2 , NULL , V_387 , V_388 ) ;
F_50 ( V_2 , V_58 ) ;
V_94 = F_242 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_144 )
F_76 ( V_13 , 0x0b , 0x05 , V_145 ) ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_77 ( V_2 ) ;
return V_94 ;
}
static int F_246 ( struct V_1 * V_2 )
{
static const T_1 V_389 [] = { 0x1d , 0 } ;
static const T_1 V_390 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_391 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_223 ;
if ( V_2 -> V_39 . V_40 == 0x10ec0272 || V_2 -> V_39 . V_40 == 0x10ec0663 ||
V_2 -> V_39 . V_40 == 0x10ec0665 || V_2 -> V_39 . V_40 == 0x10ec0670 ||
V_2 -> V_39 . V_40 == 0x10ec0671 )
V_223 = V_390 ;
else
V_223 = V_391 ;
return F_66 ( V_2 , V_389 , V_223 ) ;
}
static void F_247 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 != V_58 )
return;
if ( F_116 ( V_2 , 0x2 , V_384 ,
( 0x3b << V_216 ) |
( 0x3b << V_217 ) |
( 0x03 << V_218 ) |
( 0 << V_219 ) ) )
F_248 ( V_2 , L_42 ) ;
}
static void F_249 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_101 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_392 [ 0 ] -> V_393 [ 0 ] . V_394 = V_395 ;
}
}
static unsigned int F_250 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_282 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_3 == V_2 -> V_39 . V_106 && V_282 == V_107 && V_13 -> V_262 )
return V_396 ;
return V_282 ;
}
static void F_251 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_265 V_295 [] = {
{ 0x01 , V_171 , 0x01 } ,
{ 0x01 , V_172 , 0x01 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_288 . V_289 = F_166 ;
V_13 -> V_262 = 0 ;
V_13 -> V_278 = 1 ;
V_13 -> V_293 = 0x01 ;
F_81 ( V_2 , V_295 ) ;
V_2 -> V_291 = F_250 ;
}
}
static void F_252 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_272 ;
F_29 ( 200 ) ;
V_153 ( V_2 , V_27 ) ;
V_272 = V_13 -> V_86 . V_149 ? V_273 : 0 ;
F_29 ( 100 ) ;
F_2 ( V_2 , 0x19 , 0 , V_247 ,
V_272 ) ;
}
static void F_253 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_130 |= V_264 ;
V_13 -> V_86 . V_274 = F_252 ;
}
}
static void F_254 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_397 ) ;
}
static int F_255 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_104 = F_28 ;
V_13 -> V_130 = V_263 ;
F_13 ( V_2 , 0x20 , 0x04 , 15 ) ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0668 :
V_13 -> V_102 = F_254 ;
break;
}
F_75 ( V_2 , V_398 ,
V_399 , V_400 ) ;
F_237 ( V_2 , V_401 , V_400 ) ;
F_50 ( V_2 , V_58 ) ;
F_35 ( V_2 ) ;
if ( F_64 ( V_2 ) )
V_13 -> V_86 . V_139 = 0x01 ;
if ( ( F_6 ( V_2 ) & ( 1 << 14 ) ) &&
V_2 -> V_70 -> V_71 && V_2 -> V_70 -> V_71 -> V_122 == 0x1025 &&
V_13 -> V_59 . V_79 == 1 ) {
V_94 = F_63 ( V_2 , L_43 ) ;
if ( V_94 < 0 )
goto error;
}
V_94 = F_246 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_144 && V_13 -> V_86 . V_139 ) {
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0662 :
F_76 ( V_13 , 0x0b , 0x05 , V_145 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0668 :
F_76 ( V_13 , 0x0b , 0x04 , V_145 ) ;
break;
case 0x10ec0273 :
F_76 ( V_13 , 0x0b , 0x03 , V_145 ) ;
break;
}
}
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_77 ( V_2 ) ;
return V_94 ;
}
static int F_256 ( struct V_1 * V_2 )
{
return F_66 ( V_2 , NULL , NULL ) ;
}
static int F_257 ( struct V_1 * V_2 )
{
int V_94 ;
V_94 = F_69 ( V_2 , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
V_94 = F_256 ( V_2 ) ;
if ( V_94 < 0 ) {
F_77 ( V_2 ) ;
return V_94 ;
}
return 0 ;
}
