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
case 0x10ec0225 :
case 0x10ec0233 :
case 0x10ec0255 :
case 0x10ec0256 :
case 0x10ec0282 :
case 0x10ec0283 :
case 0x10ec0286 :
case 0x10ec0288 :
case 0x10ec0295 :
case 0x10ec0298 :
F_21 ( V_2 , 0x10 , 1 << 9 , 0 ) ;
break;
case 0x10ec0285 :
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
static int F_101 ( struct V_1 * V_2 )
{
static const T_1 V_184 [] = { 0x1d , 0 } ;
static const T_1 V_185 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , V_184 , V_185 ) ;
}
static int F_102 ( struct V_1 * V_2 )
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
break;
default:
F_13 ( V_2 , 0x20 , 0x0a , 10 ) ;
break;
}
F_75 ( V_2 , V_186 , V_187 ,
V_188 ) ;
F_50 ( V_2 , V_58 ) ;
F_35 ( V_2 ) ;
if ( F_64 ( V_2 ) )
V_13 -> V_86 . V_139 = 0x01 ;
V_94 = F_101 ( V_2 ) ;
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
static int F_103 ( struct V_1 * V_2 )
{
static const T_1 V_189 [] = { 0x1d , 0 } ;
static const T_1 V_190 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , V_189 , V_190 ) ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_191 = 0x18 ;
V_13 -> V_104 = F_28 ;
#if 0
alc_update_coefex_idx(codec, 0x1a, 7, 0, 0x80);
#endif
F_13 ( V_2 , 0x20 , 0x0a , 10 ) ;
F_75 ( V_2 , V_192 , V_193 ,
V_194 ) ;
F_50 ( V_2 , V_58 ) ;
F_35 ( V_2 ) ;
if ( F_64 ( V_2 ) )
V_13 -> V_86 . V_139 = 0x01 ;
V_94 = F_103 ( V_2 ) ;
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
static int F_105 ( struct V_1 * V_2 )
{
static const T_1 V_195 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , NULL , V_195 ) ;
}
static int F_106 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_139 = 0x01 ;
V_13 -> V_104 = F_28 ;
F_75 ( V_2 , V_196 , V_197 , V_198 ) ;
F_50 ( V_2 , V_58 ) ;
V_94 = F_105 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( V_94 > 0 && ! V_13 -> V_86 . V_144 &&
V_13 -> V_86 . V_87 . V_199 [ 0 ] != 0x1d ) {
F_9 ( V_13 , V_200 ) ;
F_81 ( V_2 , V_201 ) ;
if ( ! F_107 ( V_2 , 0x1d , V_145 ) )
F_108 ( V_2 , 0x1d , V_145 ,
( 0x0c << V_202 ) |
( 0x0c << V_203 ) |
( 0x07 << V_204 ) |
( 0 << V_205 ) ) ;
}
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_77 ( V_2 ) ;
return V_94 ;
}
static int F_109 ( struct V_1 * V_2 )
{
static const T_1 V_206 [] = { 0x1d , 0 } ;
static const T_1 V_207 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_208 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_12 * V_13 = V_2 -> V_13 ;
const T_1 * V_209 ;
switch ( V_13 -> V_210 ) {
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
V_209 = V_208 ;
break;
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
V_209 = V_207 ;
break;
default:
V_209 = V_207 ;
break;
}
return F_66 ( V_2 , V_206 , V_209 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
int V_67 ;
int V_227 = F_111 ( V_2 ) ;
if ( V_2 -> V_70 -> V_228 )
return;
for ( V_67 = 0 ; V_67 < V_2 -> V_229 . V_230 ; V_67 ++ ) {
struct V_231 * V_163 = F_112 ( & V_2 -> V_229 , V_67 ) ;
if ( V_163 -> V_3 != V_227 )
F_3 ( V_2 , V_163 -> V_3 , 0 ,
V_232 , 0 ) ;
}
V_2 -> V_233 = 1 ;
}
static void F_113 ( struct V_1 * V_2 , int V_234 )
{
F_21 ( V_2 , 0x04 , 1 << 11 , V_234 ? ( 1 << 11 ) : 0 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_210 == V_216 )
F_113 ( V_2 , 0 ) ;
if ( V_13 -> V_210 == V_216 &&
( F_6 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_29 ( 150 ) ;
}
F_30 ( V_2 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_235 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_236 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_237 ;
int V_238 ;
F_115 ( V_2 ) ;
if ( ! V_236 )
return;
V_237 = F_117 ( V_2 , V_236 ) ;
V_238 = F_7 ( V_2 , 0x78 ) ;
F_118 ( V_2 , 0x78 , 0x9004 ) ;
if ( V_237 )
F_29 ( 2 ) ;
F_2 ( V_2 , V_236 , 0 ,
V_239 , V_240 ) ;
if ( V_237 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_236 , 0 ,
V_232 , V_241 ) ;
if ( V_237 )
F_29 ( 100 ) ;
F_118 ( V_2 , 0x78 , V_238 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_236 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_237 ;
int V_238 ;
if ( ! V_236 ) {
F_114 ( V_2 ) ;
return;
}
V_237 = F_117 ( V_2 , V_236 ) ;
V_238 = F_7 ( V_2 , 0x78 ) ;
F_118 ( V_2 , 0x78 , 0x9004 ) ;
if ( V_237 )
F_29 ( 2 ) ;
F_2 ( V_2 , V_236 , 0 ,
V_239 , V_240 ) ;
if ( V_237 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_236 , 0 ,
V_232 , 0x0 ) ;
if ( V_237 )
F_29 ( 100 ) ;
F_27 ( V_2 , false ) ;
F_30 ( V_2 ) ;
F_118 ( V_2 , 0x78 , V_238 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_242 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_236 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_237 ;
if ( ! V_13 -> V_86 . V_87 . V_243 ) {
if ( V_13 -> V_86 . V_87 . V_90 == V_177 )
V_236 = V_13 -> V_86 . V_87 . V_89 [ 0 ] ;
}
F_120 ( V_2 ) ;
if ( ! V_236 )
return;
F_29 ( 30 ) ;
V_237 = F_117 ( V_2 , V_236 ) ;
F_118 ( V_2 , 0x43 , 0x9004 ) ;
F_2 ( V_2 , V_236 , 0 ,
V_239 , V_240 ) ;
if ( V_237 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_236 , 0 ,
V_232 , V_241 ) ;
if ( V_237 )
F_29 ( 85 ) ;
F_21 ( V_2 , 0x46 , 3 << 12 , 0 ) ;
F_118 ( V_2 , 0x43 , 0x9614 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_236 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_237 ;
if ( ! V_13 -> V_86 . V_87 . V_243 ) {
if ( V_13 -> V_86 . V_87 . V_90 == V_177 )
V_236 = V_13 -> V_86 . V_87 . V_89 [ 0 ] ;
}
if ( ! V_236 ) {
F_114 ( V_2 ) ;
return;
}
V_237 = F_117 ( V_2 , V_236 ) ;
F_118 ( V_2 , 0x43 , 0x9004 ) ;
F_118 ( V_2 , 0x06 , 0x2100 ) ;
F_2 ( V_2 , V_236 , 0 ,
V_239 , V_240 ) ;
if ( V_237 )
F_29 ( 100 ) ;
F_2 ( V_2 , V_236 , 0 ,
V_232 , 0x0 ) ;
F_21 ( V_2 , 0x46 , 0 , 3 << 12 ) ;
if ( V_237 )
F_29 ( 100 ) ;
F_27 ( V_2 , false ) ;
F_30 ( V_2 ) ;
F_118 ( V_2 , 0x43 , 0x9614 ) ;
}
static void F_123 ( struct V_1 * V_2 , unsigned int V_244 ,
unsigned int V_5 )
{
F_2 ( V_2 , 0x51 , 0 , V_6 , V_244 >> 1 ) ;
F_2 ( V_2 , 0x51 , 0 , V_9 , V_5 & 0xffff ) ;
F_2 ( V_2 , 0x51 , 0 , V_9 , V_5 >> 16 ) ;
}
static int F_124 ( struct V_1 * V_2 , unsigned int V_244 )
{
unsigned int V_5 ;
F_2 ( V_2 , 0x51 , 0 , V_6 , V_244 >> 1 ) ;
V_5 = F_3 ( V_2 , 0x51 , 0 , V_7 , 0 )
& 0xffff ;
V_5 |= F_3 ( V_2 , 0x51 , 0 , V_7 , 0 )
<< 16 ;
return V_5 ;
}
static void F_125 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
F_123 ( V_2 , 0x3000 , 0x000c ) ;
F_123 ( V_2 , 0x880c , 0x0008 ) ;
F_123 ( V_2 , 0x61c0 , 0x11110080 ) ;
F_123 ( V_2 , 0x6230 , 0xfc0d4011 ) ;
F_123 ( V_2 , 0x61b4 , 0x040a2b03 ) ;
F_123 ( V_2 , 0x61b0 , 0x00005b17 ) ;
F_123 ( V_2 , 0x61b8 , 0x04133303 ) ;
V_5 = F_124 ( V_2 , 0x6220 ) ;
F_123 ( V_2 , 0x6220 , ( V_5 | 0x3000 ) ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
F_123 ( V_2 , 0x61b8 , 0x04133302 ) ;
F_123 ( V_2 , 0x61b0 , 0x00005b16 ) ;
F_123 ( V_2 , 0x61b4 , 0x040a2b02 ) ;
F_123 ( V_2 , 0x6230 , 0xf80d4011 ) ;
F_123 ( V_2 , 0x6220 , 0x2002010f ) ;
F_123 ( V_2 , 0x880c , 0x00000004 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
F_123 ( V_2 , 0x61b0 , 0x5b14 ) ;
F_123 ( V_2 , 0x61b0 , 0x5b16 ) ;
F_123 ( V_2 , 0x61b4 , 0x04132b00 ) ;
F_123 ( V_2 , 0x61b4 , 0x04132b02 ) ;
F_123 ( V_2 , 0x61b8 , 0x041f3300 ) ;
F_123 ( V_2 , 0x61b8 , 0x041f3302 ) ;
F_2 ( V_2 , 0x51 , 0 , V_245 , 0 ) ;
F_123 ( V_2 , 0x61b8 , 0x041b3302 ) ;
F_123 ( V_2 , 0x61b8 , 0x04173302 ) ;
F_123 ( V_2 , 0x61b8 , 0x04163302 ) ;
F_123 ( V_2 , 0x8800 , 0x348b328b ) ;
F_123 ( V_2 , 0x8808 , 0x00020022 ) ;
F_123 ( V_2 , 0x8818 , 0x00000400 ) ;
V_5 = F_124 ( V_2 , 0x6200 ) >> 16 ;
if ( V_5 <= 3 )
F_123 ( V_2 , 0x6220 , 0x2002010f ) ;
else
F_123 ( V_2 , 0x6220 , 0x6002018f ) ;
F_123 ( V_2 , 0x61ac , 0x055525f0 ) ;
F_123 ( V_2 , 0x61c0 , 0x12230080 ) ;
F_123 ( V_2 , 0x61b4 , 0x040e2b02 ) ;
F_123 ( V_2 , 0x61bc , 0x010234f8 ) ;
F_123 ( V_2 , 0x880c , 0x00000004 ) ;
F_123 ( V_2 , 0x880c , 0x00000003 ) ;
F_123 ( V_2 , 0x880c , 0x00000010 ) ;
#ifdef F_128
F_125 ( V_2 ) ;
#endif
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_246 )
F_130 ( V_2 ) ;
return F_58 ( V_2 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_210 == V_216 )
F_113 ( V_2 , 0 ) ;
if ( V_13 -> V_210 == V_216 &&
( F_6 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_29 ( 150 ) ;
}
V_2 -> V_110 . V_111 ( V_2 ) ;
if ( V_13 -> V_210 == V_216 )
F_113 ( V_2 , 1 ) ;
if ( V_13 -> V_210 == V_216 &&
( F_6 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_29 ( 200 ) ;
}
F_60 ( V_2 -> V_39 . V_112 ) ;
F_61 ( V_2 , 0x01 ) ;
if ( V_13 -> V_247 )
F_2 ( V_2 , V_2 -> V_39 . V_106 , 0 , V_148 ,
V_13 -> V_247 ) ;
if ( V_13 -> V_246 )
F_132 ( V_2 ) ;
return 0 ;
}
static void F_133 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 )
V_13 -> V_130 = V_248 ;
}
static void F_134 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_103 )
F_21 ( V_2 , 0x1e , 0 , 0x80 ) ;
}
static void F_135 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 )
V_13 -> V_130 |= V_249 ;
}
static void F_136 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static const struct V_250 V_251 [] = {
{ 0x20 , V_6 , 0x0d } ,
{ 0x20 , V_9 , 0x4000 } ,
{}
} ;
unsigned int V_129 ;
if ( strcmp ( V_2 -> V_39 . V_74 , L_15 ) &&
strcmp ( V_2 -> V_39 . V_74 , L_16 ) )
return;
V_129 = F_36 ( V_2 , 0x12 ) ;
if ( F_137 ( V_129 ) == V_252 )
F_32 ( V_2 , V_251 ) ;
}
static void F_138 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 != V_63 )
return;
V_13 -> V_86 . V_253 = & V_254 ;
V_13 -> V_86 . V_255 = & V_256 ;
}
static void F_139 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_103 )
F_21 ( V_2 , 0x07 , 0 , 0x80 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
F_141 ( V_2 ) ;
F_118 ( V_2 , 0x0c , 0x680 ) ;
F_118 ( V_2 , 0x0c , 0x480 ) ;
}
static void F_142 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 != V_63 )
return;
V_13 -> V_86 . V_150 = F_140 ;
}
static void F_143 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_257 ;
F_29 ( 200 ) ;
V_153 ( V_2 , V_27 ) ;
V_257 = V_13 -> V_86 . V_149 ? V_258 : 0 ;
F_29 ( 100 ) ;
F_2 ( V_2 , 0x18 , 0 , V_232 ,
V_257 ) ;
F_29 ( 500 ) ;
F_2 ( V_2 , 0x18 , 0 , V_232 ,
V_257 ) ;
}
static void F_144 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_130 |= V_249 ;
V_13 -> V_86 . V_259 = F_143 ;
}
}
static void F_145 ( void * V_260 , int V_261 )
{
struct V_1 * V_2 = V_260 ;
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_262 ;
if ( V_13 -> V_263 )
V_261 = ! V_261 ;
V_262 = F_94 ( V_2 , V_13 -> V_264 ) ;
V_262 &= ~ V_265 ;
V_262 |= V_261 ? V_266 : V_178 ;
if ( V_13 -> V_264 )
F_146 ( V_2 , V_13 -> V_264 , V_262 ) ;
}
static unsigned int F_147 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_267 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_267 != V_107 || V_3 == 0 ||
( V_3 != V_13 -> V_264 && V_3 != V_13 -> V_268 ) )
return V_267 ;
F_95 ( V_2 , V_3 ,
F_94 ( V_2 , V_3 ) ) ;
return F_148 ( V_2 , V_3 , V_267 ) ;
}
static void F_149 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
const struct V_269 * V_270 = NULL ;
if ( V_57 != V_58 )
return;
while ( ( V_270 = F_150 ( V_271 , NULL , V_270 ) ) ) {
int V_272 , V_163 ;
if ( sscanf ( V_270 -> V_98 , L_17 , & V_272 , & V_163 ) != 2 )
continue;
if ( V_163 < 0x0a || V_163 >= 0x10 )
break;
V_13 -> V_263 = V_272 ;
V_13 -> V_264 = V_163 - 0x0a + 0x18 ;
V_13 -> V_86 . V_273 . V_274 = F_145 ;
V_13 -> V_86 . V_275 = 1 ;
V_2 -> V_276 = F_147 ;
F_38 ( V_2 ,
L_18 , V_13 -> V_264 ,
V_13 -> V_263 ) ;
break;
}
}
static void F_151 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_263 = 0 ;
V_13 -> V_264 = 0x18 ;
V_13 -> V_86 . V_273 . V_274 = F_145 ;
V_13 -> V_86 . V_275 = 1 ;
V_2 -> V_276 = F_147 ;
}
}
static void F_152 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_263 = 0 ;
V_13 -> V_264 = 0x19 ;
V_13 -> V_86 . V_273 . V_274 = F_145 ;
V_13 -> V_86 . V_275 = 1 ;
V_2 -> V_276 = F_147 ;
}
}
static void F_153 ( struct V_1 * V_2 , unsigned int V_10 ,
bool V_261 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_277 = V_13 -> V_247 ;
if ( V_13 -> V_263 )
V_261 = ! V_261 ;
if ( V_261 )
V_13 -> V_247 &= ~ V_10 ;
else
V_13 -> V_247 |= V_10 ;
if ( V_13 -> V_247 != V_277 )
F_2 ( V_2 , 0x01 , 0 , V_148 ,
V_13 -> V_247 ) ;
}
static void F_154 ( void * V_260 , int V_261 )
{
struct V_1 * V_2 = V_260 ;
struct V_12 * V_13 = V_2 -> V_13 ;
F_153 ( V_2 , V_13 -> V_278 , V_261 ) ;
}
static void F_155 ( struct V_1 * V_2 ,
struct V_28 * V_279 ,
struct V_30 * V_280 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_280 )
F_153 ( V_2 , V_13 -> V_281 ,
V_280 -> V_35 . integer . V_35 [ 0 ] ||
V_280 -> V_35 . integer . V_35 [ 1 ] ) ;
}
static void F_156 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_250 V_282 [] = {
{ 0x01 , V_171 , 0x18 } ,
{ 0x01 , V_172 , 0x18 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_273 . V_274 = F_154 ;
V_13 -> V_86 . V_283 = F_155 ;
V_13 -> V_247 = 0 ;
V_13 -> V_263 = 0 ;
V_13 -> V_278 = 0x08 ;
V_13 -> V_281 = 0x10 ;
F_81 ( V_2 , V_282 ) ;
}
}
static void F_157 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_250 V_282 [] = {
{ 0x01 , V_171 , 0x22 } ,
{ 0x01 , V_172 , 0x22 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_273 . V_274 = F_154 ;
V_13 -> V_86 . V_283 = F_155 ;
V_13 -> V_247 = 0 ;
V_13 -> V_263 = 0 ;
V_13 -> V_278 = 0x02 ;
V_13 -> V_281 = 0x20 ;
F_81 ( V_2 , V_282 ) ;
}
}
static void F_158 ( struct V_1 * V_2 ,
struct V_28 * V_279 ,
struct V_30 * V_280 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_262 , V_284 , V_285 ;
V_262 = F_94 ( V_2 , V_13 -> V_268 ) ;
V_262 &= ~ V_265 ;
V_284 = V_262 | V_178 ;
V_285 = V_262 | V_266 ;
if ( ! V_280 )
return;
if ( V_280 -> V_35 . integer . V_35 [ 0 ] ||
V_280 -> V_35 . integer . V_35 [ 1 ] )
V_262 = V_285 ;
else
V_262 = V_284 ;
if ( V_13 -> V_268 )
F_146 ( V_2 , V_13 -> V_268 , V_262 ) ;
}
static void F_159 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_250 V_282 [] = {
{ 0x01 , V_171 , 0x08 } ,
{ 0x01 , V_172 , 0x08 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_273 . V_274 = F_154 ;
V_13 -> V_86 . V_283 = F_158 ;
V_13 -> V_247 = 0 ;
V_13 -> V_263 = 0 ;
V_13 -> V_278 = 0x08 ;
V_13 -> V_268 = 0x18 ;
F_81 ( V_2 , V_282 ) ;
V_2 -> V_276 = F_147 ;
}
}
static void F_160 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_250 V_282 [] = {
{ 0x01 , V_171 , 0x18 } ,
{ 0x01 , V_172 , 0x18 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_273 . V_274 = F_154 ;
V_13 -> V_86 . V_283 = F_158 ;
V_13 -> V_247 = 0 ;
V_13 -> V_263 = 0 ;
V_13 -> V_278 = 0x08 ;
V_13 -> V_268 = 0x18 ;
F_81 ( V_2 , V_282 ) ;
V_2 -> V_276 = F_147 ;
}
}
static void F_161 ( struct V_1 * V_2 ,
struct V_26 * V_286 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_162 ( V_13 -> V_287 , V_13 -> V_288 [ V_289 ] , 1 ) ;
F_163 ( V_13 -> V_287 ) ;
F_162 ( V_13 -> V_287 , V_13 -> V_288 [ V_289 ] , 0 ) ;
F_163 ( V_13 -> V_287 ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_67 ;
V_13 -> V_287 = F_165 () ;
if ( ! V_13 -> V_287 ) {
F_166 ( V_2 , L_19 ) ;
return - V_99 ;
}
V_13 -> V_288 [ V_289 ] = V_290 ;
V_13 -> V_287 -> V_98 = L_20 ;
V_13 -> V_287 -> V_291 [ 0 ] = F_167 ( V_292 ) ;
V_13 -> V_287 -> V_293 = sizeof( V_13 -> V_288 [ 0 ] ) ;
V_13 -> V_287 -> V_294 = F_11 ( V_13 -> V_288 ) ;
V_13 -> V_287 -> V_295 = V_13 -> V_288 ;
for ( V_67 = 0 ; V_67 < F_11 ( V_13 -> V_288 ) ; V_67 ++ )
F_168 ( V_13 -> V_288 [ V_67 ] , V_13 -> V_287 -> V_296 ) ;
if ( F_169 ( V_13 -> V_287 ) ) {
F_166 ( V_2 , L_21 ) ;
F_170 ( V_13 -> V_287 ) ;
V_13 -> V_287 = NULL ;
return - V_99 ;
}
return 0 ;
}
static void F_171 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static const struct V_250 V_282 [] = {
{ 0x01 , V_171 , 0x1e } ,
{ 0x01 , V_172 , 0x1a } ,
{ 0x01 , V_148 , 0x02 } ,
{}
} ;
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
if ( F_164 ( V_2 ) != 0 )
return;
F_81 ( V_2 , V_282 ) ;
F_172 ( V_2 , V_2 -> V_39 . V_106 , 0 ,
V_297 , 0x04 ) ;
F_73 ( V_2 , V_2 -> V_39 . V_106 ,
F_161 ) ;
V_13 -> V_86 . V_273 . V_274 = F_154 ;
V_13 -> V_86 . V_283 = F_155 ;
V_13 -> V_247 = 0 ;
V_13 -> V_263 = 0 ;
V_13 -> V_278 = 0x08 ;
V_13 -> V_281 = 0x10 ;
return;
}
if ( ! V_13 -> V_287 )
return;
switch ( V_57 ) {
case V_63 :
V_13 -> V_85 = V_54 ;
break;
case V_298 :
F_173 ( V_13 -> V_287 ) ;
V_13 -> V_287 = NULL ;
}
}
static void F_174 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static const struct V_250 V_282 [] = {
{ 0x01 , V_171 , 0x04 } ,
{ 0x01 , V_172 , 0x04 } ,
{}
} ;
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
if ( F_164 ( V_2 ) != 0 )
return;
F_81 ( V_2 , V_282 ) ;
F_73 ( V_2 , 0x1b ,
F_161 ) ;
V_13 -> V_86 . V_283 = F_155 ;
V_13 -> V_247 = 0 ;
V_13 -> V_263 = 0 ;
V_13 -> V_281 = 0x04 ;
return;
}
if ( ! V_13 -> V_287 )
return;
switch ( V_57 ) {
case V_63 :
V_13 -> V_85 = V_54 ;
break;
case V_298 :
F_173 ( V_13 -> V_287 ) ;
V_13 -> V_287 = NULL ;
}
}
static void F_175 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_273 . V_274 = F_145 ;
V_13 -> V_86 . V_283 = F_158 ;
V_13 -> V_263 = 0 ;
V_13 -> V_264 = 0x1a ;
V_13 -> V_268 = 0x18 ;
V_13 -> V_86 . V_275 = 1 ;
V_2 -> V_276 = F_147 ;
}
}
static void F_176 ( struct V_1 * V_2 )
{
static struct V_15 V_299 [] = {
F_177 ( 0x45 , 0xd089 ) ,
F_178 ( 0x57 , 0x05 , 1 << 14 , 0 ) ,
F_177 ( 0x06 , 0x6104 ) ,
F_179 ( 0x57 , 0x03 , 0x8aa6 ) ,
{}
} ;
static struct V_15 V_300 [] = {
F_177 ( 0x1b , 0x0c0b ) ,
{}
} ;
static struct V_15 V_301 [] = {
F_177 ( 0x1b , 0x0c4b ) ,
{}
} ;
static struct V_15 V_302 [] = {
F_177 ( 0x1b , 0x0c0b ) ,
F_177 ( 0x45 , 0xc429 ) ,
F_180 ( 0x35 , 0x4000 , 0 ) ,
F_177 ( 0x06 , 0x2104 ) ,
F_177 ( 0x1a , 0x0001 ) ,
F_177 ( 0x26 , 0x0004 ) ,
F_177 ( 0x32 , 0x42a3 ) ,
{}
} ;
static struct V_15 V_303 [] = {
F_180 ( 0x4f , 0xfcc0 , 0xc400 ) ,
F_180 ( 0x50 , 0x2000 , 0x2000 ) ,
F_180 ( 0x56 , 0x0006 , 0x0006 ) ,
F_180 ( 0x66 , 0x0008 , 0 ) ,
F_180 ( 0x67 , 0x2000 , 0 ) ,
{}
} ;
static struct V_15 V_304 [] = {
F_177 ( 0x76 , 0x000e ) ,
F_177 ( 0x6c , 0x2400 ) ,
F_177 ( 0x18 , 0x7308 ) ,
F_177 ( 0x6b , 0xc429 ) ,
{}
} ;
static struct V_15 V_305 [] = {
F_180 ( 0x10 , 7 << 8 , 6 << 8 ) ,
F_178 ( 0x57 , 0x05 , 1 << 15 | 1 << 13 , 0x0 ) ,
F_178 ( 0x57 , 0x03 , 1 << 10 , 1 << 10 ) ,
F_180 ( 0x1a , 1 << 3 , 1 << 3 ) ,
F_177 ( 0x45 , 0xc429 ) ,
F_180 ( 0x4a , 0x000f , 0x000e ) ,
{}
} ;
static struct V_15 V_306 [] = {
F_177 ( 0x15 , 0x0d40 ) ,
F_177 ( 0xb7 , 0x802b ) ,
{}
} ;
static struct V_15 V_307 [] = {
F_180 ( 0x4a , 1 << 8 , 0 ) ,
F_178 ( 0x57 , 0x05 , 1 << 14 , 0 ) ,
F_180 ( 0x63 , 3 << 14 , 3 << 14 ) ,
F_180 ( 0x4a , 3 << 4 , 2 << 4 ) ,
F_180 ( 0x4a , 3 << 10 , 3 << 10 ) ,
F_180 ( 0x45 , 0x3f << 10 , 0x34 << 10 ) ,
F_180 ( 0x4a , 3 << 10 , 0 ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0255 :
F_8 ( V_2 , V_300 ) ;
F_8 ( V_2 , V_299 ) ;
break;
case 0x10ec0256 :
F_8 ( V_2 , V_301 ) ;
F_8 ( V_2 , V_299 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_302 ) ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
case 0x10ec0298 :
F_8 ( V_2 , V_303 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_304 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_305 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_306 ) ;
break;
case 0x10ec0225 :
case 0x10ec0295 :
F_8 ( V_2 , V_307 ) ;
break;
}
F_38 ( V_2 , L_22 ) ;
}
static void F_181 ( struct V_1 * V_2 , T_1 V_236 ,
T_1 V_227 )
{
static struct V_15 V_299 [] = {
F_179 ( 0x57 , 0x03 , 0x8aa6 ) ,
F_177 ( 0x06 , 0x6100 ) ,
{}
} ;
static struct V_15 V_302 [] = {
F_180 ( 0x35 , 0 , 1 << 14 ) ,
F_177 ( 0x06 , 0x2100 ) ,
F_177 ( 0x1a , 0x0021 ) ,
F_177 ( 0x26 , 0x008c ) ,
{}
} ;
static struct V_15 V_303 [] = {
F_180 ( 0x50 , 0x2000 , 0 ) ,
F_180 ( 0x56 , 0x0006 , 0 ) ,
F_180 ( 0x4f , 0xfcc0 , 0xc400 ) ,
F_180 ( 0x66 , 0x0008 , 0x0008 ) ,
F_180 ( 0x67 , 0x2000 , 0x2000 ) ,
{}
} ;
static struct V_15 V_304 [] = {
F_177 ( 0x19 , 0xa208 ) ,
F_177 ( 0x2e , 0xacf0 ) ,
{}
} ;
static struct V_15 V_305 [] = {
F_178 ( 0x57 , 0x05 , 0 , 1 << 15 | 1 << 13 ) ,
F_178 ( 0x57 , 0x03 , 1 << 10 , 0 ) ,
F_180 ( 0x1a , 1 << 3 , 0 ) ,
{}
} ;
static struct V_15 V_308 [] = {
F_177 ( 0xb7 , 0x802b ) ,
F_177 ( 0xb5 , 0x1040 ) ,
F_180 ( 0xc3 , 0 , 1 << 12 ) ,
{}
} ;
static struct V_15 V_307 [] = {
F_178 ( 0x57 , 0x05 , 1 << 14 , 1 << 14 ) ,
F_180 ( 0x4a , 3 << 4 , 2 << 4 ) ,
F_180 ( 0x63 , 3 << 14 , 0 ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_118 ( V_2 , 0x45 , 0xc489 ) ;
F_146 ( V_2 , V_236 , 0 ) ;
F_8 ( V_2 , V_299 ) ;
F_146 ( V_2 , V_227 , V_309 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_118 ( V_2 , 0x45 , 0xc429 ) ;
F_146 ( V_2 , V_236 , 0 ) ;
F_8 ( V_2 , V_302 ) ;
F_146 ( V_2 , V_227 , V_309 ) ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
case 0x10ec0298 :
F_21 ( V_2 , 0x4f , 0x000c , 0 ) ;
F_146 ( V_2 , V_236 , 0 ) ;
F_8 ( V_2 , V_303 ) ;
F_146 ( V_2 , V_227 , V_309 ) ;
break;
case 0x10ec0292 :
F_146 ( V_2 , V_236 , 0 ) ;
F_8 ( V_2 , V_304 ) ;
break;
case 0x10ec0293 :
F_118 ( V_2 , 0x45 , 0xc429 ) ;
F_146 ( V_2 , V_236 , 0 ) ;
F_8 ( V_2 , V_305 ) ;
F_146 ( V_2 , V_227 , V_309 ) ;
break;
case 0x10ec0662 :
F_146 ( V_2 , V_236 , 0 ) ;
F_146 ( V_2 , V_227 , V_309 ) ;
break;
case 0x10ec0668 :
F_118 ( V_2 , 0x11 , 0x0001 ) ;
F_146 ( V_2 , V_236 , 0 ) ;
F_8 ( V_2 , V_308 ) ;
F_146 ( V_2 , V_227 , V_309 ) ;
break;
case 0x10ec0225 :
case 0x10ec0295 :
F_21 ( V_2 , 0x45 , 0x3f << 10 , 0x31 << 10 ) ;
F_146 ( V_2 , V_236 , 0 ) ;
F_8 ( V_2 , V_307 ) ;
F_146 ( V_2 , V_227 , V_309 ) ;
break;
}
F_38 ( V_2 , L_23 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
static struct V_15 V_307 [] = {
F_180 ( 0x45 , 0x3f << 10 , 0x34 << 10 ) ,
{}
} ;
static struct V_15 V_299 [] = {
F_177 ( 0x45 , 0xc089 ) ,
F_177 ( 0x45 , 0xc489 ) ,
F_179 ( 0x57 , 0x03 , 0x8ea6 ) ,
F_177 ( 0x49 , 0x0049 ) ,
{}
} ;
static struct V_15 V_302 [] = {
F_177 ( 0x06 , 0x2100 ) ,
F_177 ( 0x32 , 0x4ea3 ) ,
{}
} ;
static struct V_15 V_303 [] = {
F_180 ( 0x4f , 0xfcc0 , 0xc400 ) ,
F_180 ( 0x50 , 0x2000 , 0x2000 ) ,
F_180 ( 0x56 , 0x0006 , 0x0006 ) ,
F_180 ( 0x66 , 0x0008 , 0 ) ,
F_180 ( 0x67 , 0x2000 , 0 ) ,
{}
} ;
static struct V_15 V_304 [] = {
F_177 ( 0x76 , 0x000e ) ,
F_177 ( 0x6c , 0x2400 ) ,
F_177 ( 0x6b , 0xc429 ) ,
F_177 ( 0x18 , 0x7308 ) ,
{}
} ;
static struct V_15 V_305 [] = {
F_180 ( 0x4a , 0x000f , 0x000e ) ,
F_177 ( 0x45 , 0xC429 ) ,
F_180 ( 0x1a , 1 << 3 , 0 ) ,
{}
} ;
static struct V_15 V_308 [] = {
F_177 ( 0x11 , 0x0041 ) ,
F_177 ( 0x15 , 0x0d40 ) ,
F_177 ( 0xb7 , 0x802b ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0225 :
case 0x10ec0295 :
F_8 ( V_2 , V_307 ) ;
break;
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_299 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_302 ) ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
case 0x10ec0298 :
F_8 ( V_2 , V_303 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_304 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_305 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_308 ) ;
break;
}
F_38 ( V_2 , L_24 ) ;
}
static void F_183 ( struct V_1 * V_2 )
{
static struct V_15 V_299 [] = {
F_177 ( 0x45 , 0xd489 ) ,
F_177 ( 0x1b , 0x0c2b ) ,
F_179 ( 0x57 , 0x03 , 0x8ea6 ) ,
{}
} ;
static struct V_15 V_301 [] = {
F_177 ( 0x45 , 0xd489 ) ,
F_177 ( 0x1b , 0x0c6b ) ,
F_179 ( 0x57 , 0x03 , 0x8ea6 ) ,
{}
} ;
static struct V_15 V_302 [] = {
F_177 ( 0x45 , 0xd429 ) ,
F_177 ( 0x1b , 0x0c2b ) ,
F_177 ( 0x32 , 0x4ea3 ) ,
{}
} ;
static struct V_15 V_303 [] = {
F_180 ( 0x50 , 0x2000 , 0x2000 ) ,
F_180 ( 0x56 , 0x0006 , 0x0006 ) ,
F_180 ( 0x66 , 0x0008 , 0 ) ,
F_180 ( 0x67 , 0x2000 , 0 ) ,
{}
} ;
static struct V_15 V_304 [] = {
F_177 ( 0x6b , 0xd429 ) ,
F_177 ( 0x76 , 0x0008 ) ,
F_177 ( 0x18 , 0x7388 ) ,
{}
} ;
static struct V_15 V_305 [] = {
F_177 ( 0x45 , 0xd429 ) ,
F_180 ( 0x10 , 7 << 8 , 7 << 8 ) ,
{}
} ;
static struct V_15 V_308 [] = {
F_177 ( 0x11 , 0x0001 ) ,
F_177 ( 0x15 , 0x0d60 ) ,
F_177 ( 0xc3 , 0x0000 ) ,
{}
} ;
static struct V_15 V_307 [] = {
F_180 ( 0x45 , 0x3f << 10 , 0x35 << 10 ) ,
F_180 ( 0x49 , 1 << 8 , 1 << 8 ) ,
F_180 ( 0x4a , 7 << 6 , 7 << 6 ) ,
F_180 ( 0x4a , 3 << 4 , 3 << 4 ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0255 :
F_8 ( V_2 , V_299 ) ;
break;
case 0x10ec0256 :
F_8 ( V_2 , V_301 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_302 ) ;
break;
case 0x10ec0298 :
F_21 ( V_2 , 0x8e , 0x0070 , 0x0020 ) ;
case 0x10ec0286 :
case 0x10ec0288 :
F_21 ( V_2 , 0x4f , 0xfcc0 , 0xd400 ) ;
F_29 ( 300 ) ;
F_8 ( V_2 , V_303 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_304 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_305 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_308 ) ;
break;
case 0x10ec0225 :
case 0x10ec0295 :
F_8 ( V_2 , V_307 ) ;
break;
}
F_38 ( V_2 , L_25 ) ;
}
static void F_184 ( struct V_1 * V_2 )
{
static struct V_15 V_299 [] = {
F_177 ( 0x45 , 0xe489 ) ,
F_177 ( 0x1b , 0x0c2b ) ,
F_179 ( 0x57 , 0x03 , 0x8ea6 ) ,
{}
} ;
static struct V_15 V_301 [] = {
F_177 ( 0x45 , 0xe489 ) ,
F_177 ( 0x1b , 0x0c6b ) ,
F_179 ( 0x57 , 0x03 , 0x8ea6 ) ,
{}
} ;
static struct V_15 V_302 [] = {
F_177 ( 0x45 , 0xe429 ) ,
F_177 ( 0x1b , 0x0c2b ) ,
F_177 ( 0x32 , 0x4ea3 ) ,
{}
} ;
static struct V_15 V_303 [] = {
F_180 ( 0x50 , 0x2000 , 0x2000 ) ,
F_180 ( 0x56 , 0x0006 , 0x0006 ) ,
F_180 ( 0x66 , 0x0008 , 0 ) ,
F_180 ( 0x67 , 0x2000 , 0 ) ,
{}
} ;
static struct V_15 V_304 [] = {
F_177 ( 0x6b , 0xe429 ) ,
F_177 ( 0x76 , 0x0008 ) ,
F_177 ( 0x18 , 0x7388 ) ,
{}
} ;
static struct V_15 V_305 [] = {
F_177 ( 0x45 , 0xe429 ) ,
F_180 ( 0x10 , 7 << 8 , 7 << 8 ) ,
{}
} ;
static struct V_15 V_308 [] = {
F_177 ( 0x11 , 0x0001 ) ,
F_177 ( 0x15 , 0x0d50 ) ,
F_177 ( 0xc3 , 0x0000 ) ,
{}
} ;
static struct V_15 V_307 [] = {
F_180 ( 0x45 , 0x3f << 10 , 0x39 << 10 ) ,
F_180 ( 0x49 , 1 << 8 , 1 << 8 ) ,
F_180 ( 0x4a , 7 << 6 , 7 << 6 ) ,
F_180 ( 0x4a , 3 << 4 , 3 << 4 ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0255 :
F_8 ( V_2 , V_299 ) ;
break;
case 0x10ec0256 :
F_8 ( V_2 , V_301 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_302 ) ;
break;
case 0x10ec0298 :
F_21 ( V_2 , 0x8e , 0x0070 , 0x0010 ) ;
case 0x10ec0286 :
case 0x10ec0288 :
F_21 ( V_2 , 0x4f , 0xfcc0 , 0xe400 ) ;
F_29 ( 300 ) ;
F_8 ( V_2 , V_303 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_304 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_305 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_308 ) ;
break;
case 0x10ec0225 :
case 0x10ec0295 :
F_8 ( V_2 , V_307 ) ;
break;
}
F_38 ( V_2 , L_26 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
int V_5 ;
bool V_310 = false ;
struct V_12 * V_13 = V_2 -> V_13 ;
static struct V_15 V_299 [] = {
F_177 ( 0x45 , 0xd089 ) ,
F_177 ( 0x49 , 0x0149 ) ,
{}
} ;
static struct V_15 V_303 [] = {
F_180 ( 0x4f , 0xfcc0 , 0xd400 ) ,
{}
} ;
static struct V_15 V_305 [] = {
F_180 ( 0x4a , 0x000f , 0x0008 ) ,
F_177 ( 0x45 , 0xD429 ) ,
{}
} ;
static struct V_15 V_308 [] = {
F_177 ( 0x11 , 0x0001 ) ,
F_177 ( 0xb7 , 0x802b ) ,
F_177 ( 0x15 , 0x0d60 ) ,
F_177 ( 0xc3 , 0x0c00 ) ,
{}
} ;
static struct V_15 V_307 [] = {
F_180 ( 0x45 , 0x3f << 10 , 0x34 << 10 ) ,
F_180 ( 0x49 , 1 << 8 , 1 << 8 ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_299 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_310 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_118 ( V_2 , 0x45 , 0xd029 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_310 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0298 :
F_21 ( V_2 , 0x8e , 0x0070 , 0x0020 ) ;
case 0x10ec0286 :
case 0x10ec0288 :
F_8 ( V_2 , V_303 ) ;
F_29 ( 350 ) ;
V_5 = F_7 ( V_2 , 0x50 ) ;
V_310 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0292 :
F_118 ( V_2 , 0x6b , 0xd429 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x6c ) ;
V_310 = ( V_5 & 0x001c ) == 0x001c ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_305 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_310 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_308 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0xbe ) ;
V_310 = ( V_5 & 0x1c02 ) == 0x1c02 ;
break;
case 0x10ec0225 :
case 0x10ec0295 :
F_8 ( V_2 , V_307 ) ;
F_29 ( 800 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_310 = ( V_5 & 0x00f0 ) == 0x00f0 ;
break;
}
F_38 ( V_2 , L_27 ,
V_310 ? L_28 : L_29 ) ;
V_13 -> V_311 = V_310 ? V_312 : V_313 ;
}
static void F_186 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_314 = V_13 -> V_86 . V_315 [ V_13 -> V_86 . V_316 [ 0 ] ] ;
T_1 V_236 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
int V_317 ;
if ( ! F_117 ( V_2 , V_236 ) )
V_317 = V_318 ;
else if ( V_314 == V_13 -> V_319 )
V_317 = V_320 ;
else if ( V_314 == V_13 -> V_321 )
V_317 = V_322 ;
else
V_317 = V_323 ;
if ( V_317 == V_13 -> V_324 ) {
F_141 ( V_2 ) ;
return;
}
switch ( V_317 ) {
case V_318 :
F_176 ( V_2 ) ;
V_13 -> V_86 . V_149 = false ;
break;
case V_320 :
if ( V_13 -> V_311 == V_325 )
F_185 ( V_2 ) ;
if ( V_13 -> V_311 == V_312 )
F_183 ( V_2 ) ;
else if ( V_13 -> V_311 == V_313 )
F_184 ( V_2 ) ;
V_13 -> V_86 . V_149 = true ;
break;
case V_322 :
F_181 ( V_2 , V_236 , V_13 -> V_321 ) ;
V_13 -> V_86 . V_149 = false ;
break;
case V_323 :
F_182 ( V_2 ) ;
V_13 -> V_86 . V_149 = true ;
break;
}
if ( V_317 != V_322 ) {
F_146 ( V_2 , V_236 ,
V_326 | V_327 ) ;
if ( V_13 -> V_321 && V_13 -> V_321 != V_236 )
F_146 ( V_2 , V_13 -> V_321 ,
V_328 ) ;
}
V_13 -> V_324 = V_317 ;
F_141 ( V_2 ) ;
}
static void F_187 ( struct V_1 * V_2 ,
struct V_28 * V_279 ,
struct V_30 * V_280 )
{
F_186 ( V_2 ) ;
}
static void F_188 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_311 = V_325 ;
V_153 ( V_2 , V_27 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
int V_67 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_128 * V_129 = & V_13 -> V_86 . V_87 ;
for ( V_67 = 0 ; V_67 < V_129 -> V_329 ; V_67 ++ ) {
if ( V_129 -> V_330 [ V_67 ] . V_331 && ! V_13 -> V_319 )
V_13 -> V_319 = V_129 -> V_330 [ V_67 ] . V_163 ;
if ( V_129 -> V_330 [ V_67 ] . V_332 && ! V_13 -> V_321 )
V_13 -> V_321 = V_129 -> V_330 [ V_67 ] . V_163 ;
}
V_13 -> V_86 . V_283 = F_187 ;
V_13 -> V_86 . V_150 = F_186 ;
V_13 -> V_86 . V_259 = F_188 ;
}
static void F_190 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
switch ( V_57 ) {
case V_58 :
V_13 -> V_130 |= V_249 | V_333 ;
break;
case V_63 :
F_189 ( V_2 ) ;
break;
case V_103 :
V_13 -> V_324 = 0 ;
F_186 ( V_2 ) ;
break;
}
}
static void F_191 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_130 |= V_249 ;
}
else
F_190 ( V_2 , V_56 , V_57 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
static struct V_15 V_334 [] = {
F_177 ( 0x1b , 0x880b ) ,
F_177 ( 0x45 , 0xd089 ) ,
F_177 ( 0x1b , 0x080b ) ,
F_177 ( 0x46 , 0x0004 ) ,
F_177 ( 0x1b , 0x0c0b ) ,
{}
} ;
static struct V_15 V_335 [] = {
F_177 ( 0x1b , 0x884b ) ,
F_177 ( 0x45 , 0xd089 ) ,
F_177 ( 0x1b , 0x084b ) ,
F_177 ( 0x46 , 0x0004 ) ,
F_177 ( 0x1b , 0x0c4b ) ,
{}
} ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0255 :
F_8 ( V_2 , V_334 ) ;
break;
case 0x10ec0256 :
F_8 ( V_2 , V_335 ) ;
break;
}
F_29 ( 30 ) ;
}
static void F_193 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
F_192 ( V_2 ) ;
}
F_190 ( V_2 , V_56 , V_57 ) ;
}
static void F_194 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_130 |= V_249 ;
F_192 ( V_2 ) ;
}
else
F_190 ( V_2 , V_56 , V_57 ) ;
}
static void F_195 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_336 ;
F_188 ( V_2 , V_27 ) ;
V_336 = V_13 -> V_86 . V_149 ? 0x40 : 0 ;
F_2 ( V_2 , 0x01 , 0 , V_148 ,
V_336 ) ;
}
static void F_196 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
F_190 ( V_2 , V_56 , V_57 ) ;
if ( V_57 == V_63 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_259 = F_195 ;
}
}
static void F_197 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_337 = 1 ;
}
}
static void F_198 ( struct V_1 * V_2 )
{
}
static void F_199 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_104 = F_198 ;
}
}
static void F_200 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_131 = 0 ;
}
}
static void F_201 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static const struct V_154 V_155 [] = {
{ 0x16 , 0x21211010 } ,
{ 0x19 , 0x21a11010 } ,
{ }
} ;
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_104 = F_198 ;
V_13 -> V_105 = F_55 ;
V_13 -> V_130 = V_248 ;
V_2 -> V_338 = 0 ;
F_83 ( V_2 , V_155 ) ;
}
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_236 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
F_2 ( V_2 , V_236 , 0 ,
V_239 , V_240 ) ;
F_29 ( 20 ) ;
}
static void F_203 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_339 * V_340 = & V_13 -> V_86 . V_341 ;
int V_67 ;
switch ( V_57 ) {
case V_58 :
F_204 ( V_2 , 0x19 , V_328 ) ;
break;
case V_63 :
V_13 -> V_104 = F_202 ;
for ( V_67 = 0 ; V_67 < V_340 -> V_342 ; V_67 ++ ) {
if ( V_13 -> V_86 . V_315 [ V_67 ] == 0x12 ) {
V_13 -> V_86 . V_316 [ 0 ] = V_67 ;
break;
}
}
break;
}
}
static void F_205 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_130 |= V_249 ;
V_13 -> V_86 . V_158 = 1 ;
F_2 ( V_2 , 0x1b , 0 , V_239 , 0x7000 ) ;
F_206 ( V_2 , 0x1b , F_25 ( V_2 , 0x1b ) & ~ V_343 ) ;
} else
F_190 ( V_2 , V_56 , V_57 ) ;
}
static void F_207 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
F_118 ( V_2 , 0xc4 , 0x8000 ) ;
F_21 ( V_2 , 0xc2 , ~ 0xfe , 0 ) ;
F_146 ( V_2 , 0x18 , 0 ) ;
}
F_190 ( V_2 , V_56 , V_57 ) ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_128 * V_129 = & V_13 -> V_86 . V_87 ;
T_1 V_3 ;
unsigned int V_344 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_129 -> V_329 ; V_67 ++ ) {
if ( V_129 -> V_330 [ V_67 ] . type != V_345 )
continue;
V_3 = V_129 -> V_330 [ V_67 ] . V_163 ;
V_344 = F_36 ( V_2 , V_3 ) ;
if ( F_208 ( V_344 ) == V_346 )
continue;
return V_3 ;
}
return 0 ;
}
static void F_209 ( struct V_1 * V_2 ,
const struct V_55 * V_56 ,
int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_63 ) {
int V_227 = F_111 ( V_2 ) ;
int V_236 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
if ( F_10 ( ! V_227 || ! V_236 ) )
return;
F_210 ( V_2 , V_227 , V_236 ) ;
}
}
static void F_211 ( struct V_1 * V_2 ,
const struct V_55 * V_56 ,
int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_128 * V_129 = & V_13 -> V_86 . V_87 ;
int V_67 ;
if ( V_57 != V_63 )
return;
for ( V_67 = 0 ; V_67 < V_129 -> V_329 ; V_67 ++ ) {
T_1 V_3 = V_129 -> V_330 [ V_67 ] . V_163 ;
unsigned int V_344 ;
if ( V_129 -> V_330 [ V_67 ] . type != V_345 )
continue;
V_344 = F_36 ( V_2 , V_3 ) ;
if ( F_208 ( V_344 ) != V_346 )
continue;
F_108 ( V_2 , V_3 , V_145 ,
( 0x00 << V_202 ) |
( 0x01 << V_203 ) |
( 0x2f << V_204 ) |
( 0 << V_205 ) ) ;
}
}
static void F_212 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_257 ;
F_29 ( 200 ) ;
V_153 ( V_2 , V_27 ) ;
V_257 = V_13 -> V_86 . V_149 ? V_258 : 0 ;
F_29 ( 600 ) ;
F_2 ( V_2 , 0x19 , 0 , V_232 ,
V_257 ) ;
}
static void F_213 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
switch ( V_57 ) {
case V_58 :
F_206 ( V_2 , 0x03 , 0 ) ;
V_13 -> V_86 . V_131 = 0 ;
break;
case V_103 :
F_21 ( V_2 , 0x06 , 0x000c , 0 ) ;
F_21 ( V_2 , 0x1a , 0 , 1 << 4 ) ;
break;
}
}
static void F_214 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
switch ( V_57 ) {
case V_58 :
V_13 -> V_86 . V_259 = F_212 ;
break;
case V_103 :
F_21 ( V_2 , 0x06 , 0x000c , 0 ) ;
break;
}
}
static void F_215 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_141 ( V_2 ) ;
if ( F_117 ( V_2 , 0x1b ) )
V_13 -> V_86 . V_347 |= ( 1ULL << 0x14 ) ;
}
static void F_216 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_250 V_348 [] = {
{ 0x01 , V_171 , 0x04 } ,
{ 0x01 , V_172 , 0x04 } ,
{ 0x01 , V_148 , 0x04 } ,
{}
} ;
static const struct V_154 V_349 [] = {
{ 0x1b , 0x21114000 } ,
{}
} ;
struct V_28 * V_29 ;
switch ( V_57 ) {
case V_58 :
F_81 ( V_2 , V_348 ) ;
F_83 ( V_2 , V_349 ) ;
V_13 -> V_86 . V_337 = 1 ;
V_13 -> V_86 . V_150 = F_215 ;
F_73 ( V_2 , 0x1b ,
V_153 ) ;
break;
case V_101 :
V_29 = F_15 ( V_2 , L_30 ) ;
if ( V_29 )
strcpy ( V_29 -> V_350 . V_98 , L_31 ) ;
V_29 = F_15 ( V_2 , L_32 ) ;
if ( V_29 )
strcpy ( V_29 -> V_350 . V_98 , L_30 ) ;
break;
}
}
static void F_217 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
T_1 V_173 [ 2 ] = { 0x0c } ;
F_91 ( V_2 , 0x14 , 1 , V_173 ) ;
F_91 ( V_2 , 0x15 , 1 , V_173 ) ;
}
}
static void F_218 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
V_153 ( V_2 , V_27 ) ;
F_153 ( V_2 , 0x10 , ! V_13 -> V_86 . V_149 ) ;
}
static void F_219 ( struct V_1 * V_2 ,
const struct V_55 * V_56 ,
int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_250 V_282 [] = {
{ 0x01 , V_171 , 0x18 } ,
{ 0x01 , V_172 , 0x18 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_273 . V_274 = F_154 ;
V_13 -> V_86 . V_259 = F_218 ;
V_13 -> V_247 = 0 ;
V_13 -> V_263 = 0 ;
V_13 -> V_278 = 0x08 ;
F_81 ( V_2 , V_282 ) ;
}
}
static void F_220 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_5 ;
if ( V_13 -> V_210 != V_216 )
return;
if ( ( F_6 ( V_2 ) & 0x00ff ) < 0x015 ) {
F_118 ( V_2 , 0xf , 0x960b ) ;
F_118 ( V_2 , 0xe , 0x8817 ) ;
}
if ( ( F_6 ( V_2 ) & 0x00ff ) == 0x016 ) {
F_118 ( V_2 , 0xf , 0x960b ) ;
F_118 ( V_2 , 0xe , 0x8814 ) ;
}
if ( ( F_6 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_21 ( V_2 , 0x04 , 0 , 1 << 11 ) ;
}
if ( ( F_6 ( V_2 ) & 0x00ff ) == 0x018 ) {
V_5 = F_7 ( V_2 , 0xd ) ;
if ( V_5 != - 1 && ( V_5 & 0x0c00 ) >> 10 != 0x1 ) {
F_118 ( V_2 , 0xd , V_5 | ( 1 << 10 ) ) ;
}
V_5 = F_7 ( V_2 , 0x17 ) ;
if ( V_5 != - 1 && ( V_5 & 0x01c0 ) >> 6 != 0x4 ) {
F_118 ( V_2 , 0x17 , V_5 | ( 1 << 7 ) ) ;
}
}
F_21 ( V_2 , 0x4 , 0 , 1 << 11 ) ;
}
static int F_221 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_191 = 0x18 ;
V_2 -> V_338 = 1 ;
#ifdef F_222
V_2 -> V_110 . V_351 = F_129 ;
V_2 -> V_110 . V_352 = F_131 ;
#endif
V_13 -> V_104 = F_114 ;
F_75 ( V_2 , V_353 ,
V_354 , V_355 ) ;
F_223 ( V_2 , V_356 , V_355 ) ;
F_75 ( V_2 , NULL , V_357 ,
V_355 ) ;
F_50 ( V_2 , V_58 ) ;
F_35 ( V_2 ) ;
if ( F_64 ( V_2 ) )
V_13 -> V_86 . V_139 = 0x01 ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0269 :
V_13 -> V_210 = V_211 ;
switch ( F_6 ( V_2 ) & 0x00f0 ) {
case 0x0010 :
if ( V_2 -> V_70 -> V_71 &&
V_2 -> V_70 -> V_71 -> V_122 == 0x1025 &&
V_13 -> V_59 . V_79 == 1 )
V_94 = F_63 ( V_2 , L_15 ) ;
V_13 -> V_210 = V_216 ;
break;
case 0x0020 :
if ( V_2 -> V_70 -> V_71 &&
V_2 -> V_70 -> V_71 -> V_122 == 0x17aa &&
V_2 -> V_70 -> V_71 -> V_73 == 0x21f3 )
V_94 = F_63 ( V_2 , L_33 ) ;
V_13 -> V_210 = V_212 ;
break;
case 0x0030 :
V_13 -> V_210 = V_217 ;
break;
default:
F_13 ( V_2 , 0x20 , 0x04 , 15 ) ;
}
if ( V_94 < 0 )
goto error;
V_13 -> V_102 = F_220 ;
F_220 ( V_2 ) ;
break;
case 0x10ec0280 :
case 0x10ec0290 :
V_13 -> V_210 = V_213 ;
break;
case 0x10ec0282 :
V_13 -> V_210 = V_218 ;
V_13 -> V_104 = F_119 ;
V_13 -> V_102 = F_116 ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
V_13 -> V_210 = V_219 ;
V_13 -> V_104 = F_122 ;
V_13 -> V_102 = F_121 ;
break;
case 0x10ec0284 :
case 0x10ec0292 :
V_13 -> V_210 = V_214 ;
break;
case 0x10ec0285 :
case 0x10ec0293 :
V_13 -> V_210 = V_215 ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
V_13 -> V_210 = V_220 ;
V_13 -> V_104 = F_110 ;
break;
case 0x10ec0298 :
V_13 -> V_210 = V_221 ;
break;
case 0x10ec0255 :
V_13 -> V_210 = V_222 ;
break;
case 0x10ec0256 :
V_13 -> V_210 = V_223 ;
V_13 -> V_86 . V_131 = 0 ;
F_21 ( V_2 , 0x36 , 1 << 13 , 1 << 5 ) ;
break;
case 0x10ec0225 :
case 0x10ec0295 :
V_13 -> V_210 = V_224 ;
break;
case 0x10ec0234 :
case 0x10ec0274 :
case 0x10ec0294 :
V_13 -> V_210 = V_225 ;
break;
case 0x10ec0700 :
case 0x10ec0701 :
case 0x10ec0703 :
V_13 -> V_210 = V_226 ;
V_13 -> V_86 . V_131 = 0 ;
F_21 ( V_2 , 0x4a , 0 , 1 << 15 ) ;
break;
}
if ( F_3 ( V_2 , 0x51 , 0 , V_358 , 0 ) == 0x10ec5505 ) {
V_13 -> V_246 = 1 ;
V_13 -> V_102 = F_127 ;
}
V_94 = F_109 ( V_2 ) ;
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
static int F_224 ( struct V_1 * V_2 )
{
static const T_1 V_359 [] = { 0x1d , 0 } ;
static const T_1 V_360 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_66 ( V_2 , V_359 , V_360 ) ;
}
static void F_225 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_5 ;
if ( V_57 != V_103 )
return;
V_5 = F_94 ( V_2 , 0x0f ) ;
if ( ! ( V_5 & ( V_361 | V_326 ) ) )
V_5 |= V_361 ;
V_5 |= V_181 ;
F_95 ( V_2 , 0x0f , V_5 ) ;
V_13 -> V_86 . V_179 = 1 ;
}
static void F_226 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 )
V_2 -> V_362 = 1 ;
}
static int F_227 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x15 ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_139 = 0x23 ;
#ifdef F_222
V_13 -> V_109 = F_57 ;
#endif
F_75 ( V_2 , NULL , V_363 , V_364 ) ;
F_50 ( V_2 , V_58 ) ;
V_94 = F_224 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_144 )
F_76 ( V_13 , 0x23 , 0 , V_365 ) ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_77 ( V_2 ) ;
return V_94 ;
}
static int F_228 ( struct V_1 * V_2 )
{
static const T_1 V_366 [] = { 0x1d , 0 } ;
static const T_1 V_367 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , V_366 , V_367 ) ;
}
static void F_229 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
F_230 ( V_2 , 0x18 , 0x00000734 ) ;
F_230 ( V_2 , 0x19 , 0x0000073c ) ;
}
}
static int F_231 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_139 = 0x23 ;
V_13 -> V_104 = F_28 ;
F_75 ( V_2 , NULL , V_368 , V_369 ) ;
F_50 ( V_2 , V_58 ) ;
V_94 = F_228 ( V_2 ) ;
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
static int F_232 ( struct V_1 * V_2 )
{
static const T_1 V_370 [] = { 0x1d , 0 } ;
static const T_1 V_371 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_372 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_209 ;
if ( V_2 -> V_39 . V_40 == 0x10ec0272 || V_2 -> V_39 . V_40 == 0x10ec0663 ||
V_2 -> V_39 . V_40 == 0x10ec0665 || V_2 -> V_39 . V_40 == 0x10ec0670 ||
V_2 -> V_39 . V_40 == 0x10ec0671 )
V_209 = V_371 ;
else
V_209 = V_372 ;
return F_66 ( V_2 , V_370 , V_209 ) ;
}
static void F_233 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 != V_58 )
return;
if ( F_108 ( V_2 , 0x2 , V_365 ,
( 0x3b << V_202 ) |
( 0x3b << V_203 ) |
( 0x03 << V_204 ) |
( 0 << V_205 ) ) )
F_234 ( V_2 , L_34 ) ;
}
static void F_235 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_101 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_373 [ 0 ] -> V_374 [ 0 ] . V_375 = V_376 ;
}
}
static unsigned int F_236 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_267 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_3 == V_2 -> V_39 . V_106 && V_267 == V_107 && V_13 -> V_247 )
return V_377 ;
return V_267 ;
}
static void F_237 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_250 V_282 [] = {
{ 0x01 , V_171 , 0x01 } ,
{ 0x01 , V_172 , 0x01 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_273 . V_274 = F_154 ;
V_13 -> V_247 = 0 ;
V_13 -> V_263 = 1 ;
V_13 -> V_278 = 0x01 ;
F_81 ( V_2 , V_282 ) ;
V_2 -> V_276 = F_236 ;
}
}
static void F_238 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_378 ) ;
}
static int F_239 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_104 = F_28 ;
V_13 -> V_130 = V_248 ;
F_13 ( V_2 , 0x20 , 0x04 , 15 ) ;
switch ( V_2 -> V_39 . V_40 ) {
case 0x10ec0668 :
V_13 -> V_102 = F_238 ;
break;
}
F_75 ( V_2 , V_379 ,
V_380 , V_381 ) ;
F_223 ( V_2 , V_382 , V_381 ) ;
F_50 ( V_2 , V_58 ) ;
F_35 ( V_2 ) ;
if ( F_64 ( V_2 ) )
V_13 -> V_86 . V_139 = 0x01 ;
if ( ( F_6 ( V_2 ) & ( 1 << 14 ) ) &&
V_2 -> V_70 -> V_71 && V_2 -> V_70 -> V_71 -> V_122 == 0x1025 &&
V_13 -> V_59 . V_79 == 1 ) {
V_94 = F_63 ( V_2 , L_35 ) ;
if ( V_94 < 0 )
goto error;
}
V_94 = F_232 ( V_2 ) ;
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
static int F_240 ( struct V_1 * V_2 )
{
return F_66 ( V_2 , NULL , NULL ) ;
}
static int F_241 ( struct V_1 * V_2 )
{
int V_94 ;
V_94 = F_69 ( V_2 , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
V_94 = F_240 ( V_2 ) ;
if ( V_94 < 0 ) {
F_77 ( V_2 ) ;
return V_94 ;
}
return 0 ;
}
