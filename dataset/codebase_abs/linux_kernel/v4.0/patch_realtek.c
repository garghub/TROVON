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
switch ( V_2 -> V_40 ) {
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
switch ( V_2 -> V_40 ) {
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
V_65 = V_2 -> V_72 & 0xffff ;
if ( V_65 != V_2 -> V_70 -> V_71 -> V_73 && ( V_65 & 1 ) )
goto V_69;
V_3 = 0x1d ;
if ( V_2 -> V_40 == 0x10ec0260 )
V_3 = 0x17 ;
V_65 = F_36 ( V_2 , V_3 ) ;
if ( ! ( V_65 & 1 ) ) {
F_37 ( V_2 , L_2 ,
V_2 -> V_74 , V_65 ) ;
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
V_65 = V_2 -> V_72 & 0xffff ;
if ( V_2 -> V_70 -> V_71 &&
V_65 != V_2 -> V_70 -> V_71 -> V_73 && ( V_65 & 1 ) )
goto V_69;
V_3 = 0x1d ;
if ( V_2 -> V_40 == 0x10ec0260 )
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
V_65 & 0xffff , V_2 -> V_40 ) ;
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
F_27 ( V_2 , false ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_53 ( V_2 ) ;
if ( V_13 && V_13 -> V_105 )
V_13 -> V_105 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( ! V_13 -> V_47 )
F_29 ( 150 ) ;
V_2 -> V_106 . V_107 ( V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 , 0x01 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , const char * V_98 )
{
F_17 ( V_2 -> V_74 ) ;
V_2 -> V_74 = F_61 ( V_98 , V_32 ) ;
if ( ! V_2 -> V_74 ) {
F_62 ( V_2 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
const struct V_108 * V_46 ;
const struct V_109 * V_110 ;
for ( V_46 = V_111 ; V_46 -> V_40 ; V_46 ++ ) {
if ( V_46 -> V_40 != V_2 -> V_40 )
continue;
if ( ( F_6 ( V_2 ) & V_46 -> V_112 ) == V_46 -> V_113 )
return F_60 ( V_2 , V_46 -> V_98 ) ;
}
if ( ! V_2 -> V_70 -> V_71 )
return 0 ;
for ( V_110 = V_114 ; V_110 -> V_115 ; V_110 ++ ) {
if ( V_110 -> V_115 != V_2 -> V_40 )
continue;
if ( V_110 -> V_116 != V_2 -> V_70 -> V_71 -> V_117 )
continue;
if ( ! V_110 -> V_118 ||
V_110 -> V_118 == V_2 -> V_70 -> V_71 -> V_73 )
return F_60 ( V_2 , V_110 -> V_98 ) ;
}
return 0 ;
}
static inline int F_64 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
const struct V_119 * V_110 ;
V_110 = F_65 ( V_2 -> V_70 -> V_71 , V_120 ) ;
if ( V_110 )
return V_110 -> V_36 ;
return V_13 -> V_59 . V_68 ;
}
static int F_66 ( struct V_1 * V_2 ,
const T_1 * V_121 ,
const T_1 * V_122 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_123 * V_124 = & V_13 -> V_86 . V_87 ;
int V_94 ;
V_94 = F_67 ( V_2 , V_124 , V_121 ,
V_13 -> V_125 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( V_122 )
F_42 ( V_2 , V_122 ) ;
V_94 = F_68 ( V_2 , V_124 ) ;
if ( V_94 < 0 )
return V_94 ;
return 1 ;
}
static int F_69 ( struct V_1 * V_2 , T_1 V_126 )
{
struct V_12 * V_13 = F_16 ( sizeof( * V_13 ) , V_32 ) ;
int V_94 ;
if ( ! V_13 )
return - V_99 ;
V_2 -> V_13 = V_13 ;
F_70 ( & V_13 -> V_86 ) ;
V_13 -> V_86 . V_126 = V_126 ;
V_13 -> V_86 . V_127 = 1 ;
V_2 -> V_128 = 1 ;
V_2 -> V_129 = 1 ;
V_94 = F_63 ( V_2 ) ;
if ( V_94 < 0 ) {
F_17 ( V_13 ) ;
return V_94 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
static const T_1 V_130 [] = { 0x1d , 0 } ;
static const T_1 V_131 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , V_130 , V_131 ) ;
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
V_13 -> V_86 . V_132 = 1 ;
V_13 -> V_86 . V_133 = 0x01 ;
F_75 ( V_2 , V_134 , V_135 ,
V_136 ) ;
F_50 ( V_2 , V_58 ) ;
V_94 = F_71 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_137 )
F_76 ( V_13 , 0x0b , 0x05 , V_138 ) ;
V_2 -> V_106 = V_139 ;
V_2 -> V_106 . V_140 = F_18 ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_62 ( V_2 ) ;
return V_94 ;
}
static int F_77 ( struct V_1 * V_2 )
{
static const T_1 V_141 [] = { 0x17 , 0 } ;
static const T_1 V_142 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_66 ( V_2 , V_141 , V_142 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_2 ( V_2 , 0x01 , 0 , V_143 ,
V_13 -> V_86 . V_144 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_63 ) {
V_13 -> V_86 . V_145 = F_78 ;
V_13 -> V_86 . V_146 = 1 ;
V_13 -> V_86 . V_147 = 1 ;
V_13 -> V_86 . V_87 . V_88 [ 0 ] = 0x0f ;
F_73 ( V_2 , 0x0f ,
V_148 ) ;
F_80 ( V_2 , V_49 ) ;
}
}
static void F_81 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_149 V_150 [] = {
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
F_82 ( V_2 , V_150 ) ;
break;
case V_63 :
V_13 -> V_85 = V_151 ;
break;
}
}
static void F_83 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_63 )
V_13 -> V_85 = V_151 ;
}
static void F_84 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_152 = 1 ;
V_13 -> V_86 . V_153 = 1 ;
}
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x07 ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_154 = 1 ;
V_13 -> V_86 . V_133 = 0x01 ;
F_75 ( V_2 , V_155 , V_156 ,
V_157 ) ;
F_50 ( V_2 , V_58 ) ;
V_94 = F_77 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_137 )
F_76 ( V_13 , 0x07 , 0x05 , V_138 ) ;
V_2 -> V_106 = V_139 ;
V_13 -> V_104 = F_28 ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_62 ( V_2 ) ;
return V_94 ;
}
static void F_86 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 != V_103 )
return;
F_21 ( V_2 , 7 , 0 , 0x2030 ) ;
}
static void F_87 ( struct V_1 * V_2 , int V_158 , int V_159 )
{
unsigned int V_160 , V_161 , V_162 ;
V_160 = F_3 ( V_2 , V_2 -> V_163 , 0 ,
V_164 , 0 ) ;
if ( ! V_159 )
V_160 |= ( 1 << V_158 ) ;
else
V_160 &= ~ ( 1 << V_158 ) ;
V_161 = F_3 ( V_2 , V_2 -> V_163 , 0 ,
V_165 , 0 ) ;
V_161 |= ( 1 << V_158 ) ;
V_162 = F_3 ( V_2 , V_2 -> V_163 , 0 ,
V_166 , 0 ) ;
V_162 |= ( 1 << V_158 ) ;
F_2 ( V_2 , V_2 -> V_163 , 0 ,
V_167 , V_161 ) ;
F_2 ( V_2 , V_2 -> V_163 , 0 ,
V_168 , V_162 ) ;
F_29 ( 1 ) ;
F_2 ( V_2 , V_2 -> V_163 , 0 ,
V_143 , V_160 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 != V_103 )
return;
F_87 ( V_2 , 0 , 0 ) ;
F_87 ( V_2 , 1 , 0 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
T_1 V_169 [ 2 ] = { 0x0c , 0x0d } ;
T_1 V_170 [ 2 ] = { 0x0e , 0x0f } ;
F_90 ( V_2 , 0x14 , 2 , V_169 ) ;
F_90 ( V_2 , 0x15 , 2 , V_169 ) ;
F_90 ( V_2 , 0x18 , 2 , V_170 ) ;
F_90 ( V_2 , 0x1a , 2 , V_170 ) ;
} else if ( V_57 == V_63 ) {
T_1 V_171 [ 5 ] = { 0x0c , 0x0d , 0x0e , 0x0f , 0x26 } ;
F_90 ( V_2 , 0x14 , 5 , V_171 ) ;
F_90 ( V_2 , 0x15 , 5 , V_171 ) ;
F_90 ( V_2 , 0x18 , 5 , V_171 ) ;
F_90 ( V_2 , 0x1a , 5 , V_171 ) ;
}
}
static void F_91 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static T_1 V_172 [ 2 ] = { 0x14 , 0x15 } ;
int V_67 ;
if ( V_57 != V_103 )
return;
for ( V_67 = 0 ; V_67 < F_11 ( V_172 ) ; V_67 ++ ) {
unsigned int V_5 = F_36 ( V_2 , V_172 [ V_67 ] ) ;
if ( F_92 ( V_5 ) != V_173 )
continue;
V_5 = F_93 ( V_2 , V_172 [ V_67 ] ) ;
V_5 |= V_174 ;
F_94 ( V_2 , V_172 [ V_67 ] , V_5 ) ;
V_13 -> V_86 . V_175 = 1 ;
break;
}
}
static void F_95 ( struct V_1 * V_2 ,
const T_1 * V_172 , int V_176 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_176 ; V_67 ++ ) {
unsigned int V_5 ;
V_5 = F_93 ( V_2 , V_172 [ V_67 ] ) ;
V_5 |= V_177 ;
F_94 ( V_2 , V_172 [ V_67 ] , V_5 ) ;
}
V_13 -> V_86 . V_175 = 1 ;
}
static void F_96 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static T_1 V_172 [ 2 ] = { 0x18 , 0x1a } ;
if ( V_57 == V_103 )
F_95 ( V_2 , V_172 , F_11 ( V_172 ) ) ;
}
static void F_97 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static T_1 V_172 [ 1 ] = { 0x18 } ;
if ( V_57 == V_103 )
F_95 ( V_2 , V_172 , F_11 ( V_172 ) ) ;
}
static void F_98 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static T_1 V_172 [ 2 ] = { 0x18 , 0x19 } ;
if ( V_57 == V_103 )
F_95 ( V_2 , V_172 , F_11 ( V_172 ) ) ;
}
static void F_99 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_178 = 1 ;
V_13 -> V_86 . V_179 = 1 ;
}
}
static int F_100 ( struct V_1 * V_2 )
{
static const T_1 V_180 [] = { 0x1d , 0 } ;
static const T_1 V_181 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , V_180 , V_181 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
switch ( V_2 -> V_40 ) {
case 0x10ec0882 :
case 0x10ec0885 :
case 0x10ec0900 :
break;
default:
F_13 ( V_2 , 0x20 , 0x0a , 10 ) ;
break;
}
F_75 ( V_2 , V_182 , V_183 ,
V_184 ) ;
F_50 ( V_2 , V_58 ) ;
F_35 ( V_2 ) ;
if ( F_64 ( V_2 ) )
V_13 -> V_86 . V_133 = 0x01 ;
V_94 = F_100 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_137 && V_13 -> V_86 . V_133 )
F_76 ( V_13 , 0x0b , 0x05 , V_138 ) ;
V_2 -> V_106 = V_139 ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_62 ( V_2 ) ;
return V_94 ;
}
static int F_102 ( struct V_1 * V_2 )
{
static const T_1 V_185 [] = { 0x1d , 0 } ;
static const T_1 V_186 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , V_185 , V_186 ) ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_187 = 0x18 ;
#if 0
alc_update_coefex_idx(codec, 0x1a, 7, 0, 0x80);
#endif
F_13 ( V_2 , 0x20 , 0x0a , 10 ) ;
F_75 ( V_2 , V_188 , V_189 ,
V_190 ) ;
F_50 ( V_2 , V_58 ) ;
F_35 ( V_2 ) ;
if ( F_64 ( V_2 ) )
V_13 -> V_86 . V_133 = 0x01 ;
V_94 = F_102 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_137 && V_13 -> V_86 . V_133 )
F_76 ( V_13 , 0x0b , 0x05 , V_138 ) ;
V_2 -> V_106 = V_139 ;
V_13 -> V_104 = F_28 ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_62 ( V_2 ) ;
return V_94 ;
}
static int F_104 ( struct V_1 * V_2 )
{
static const T_1 V_191 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , NULL , V_191 ) ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_133 = 0x01 ;
F_75 ( V_2 , V_192 , V_193 , V_194 ) ;
F_50 ( V_2 , V_58 ) ;
V_94 = F_104 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( V_94 > 0 && ! V_13 -> V_86 . V_137 &&
V_13 -> V_86 . V_87 . V_195 [ 0 ] != 0x1d ) {
F_9 ( V_13 , V_196 ) ;
F_80 ( V_2 , V_197 ) ;
if ( ! F_106 ( V_2 , 0x1d , V_138 ) )
F_107 ( V_2 , 0x1d , V_138 ,
( 0x0c << V_198 ) |
( 0x0c << V_199 ) |
( 0x07 << V_200 ) |
( 0 << V_201 ) ) ;
}
V_2 -> V_106 = V_139 ;
V_13 -> V_104 = F_28 ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_62 ( V_2 ) ;
return V_94 ;
}
static int F_108 ( struct V_202 * V_203 ,
struct V_1 * V_2 ,
struct V_204 * V_205 )
{
struct V_206 * V_13 = V_2 -> V_13 ;
return F_109 ( V_2 , & V_13 -> V_207 , V_205 ,
V_203 ) ;
}
static int F_110 ( struct V_202 * V_203 ,
struct V_1 * V_2 ,
unsigned int V_208 ,
unsigned int V_209 ,
struct V_204 * V_205 )
{
struct V_206 * V_13 = V_2 -> V_13 ;
return F_111 ( V_2 , & V_13 -> V_207 ,
V_208 , V_209 , V_205 ) ;
}
static int F_112 ( struct V_202 * V_203 ,
struct V_1 * V_2 ,
struct V_204 * V_205 )
{
struct V_206 * V_13 = V_2 -> V_13 ;
return F_113 ( V_2 , & V_13 -> V_207 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
static const T_1 V_210 [] = { 0x1d , 0 } ;
static const T_1 V_211 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_212 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_12 * V_13 = V_2 -> V_13 ;
const T_1 * V_213 ;
switch ( V_13 -> V_214 ) {
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
V_213 = V_212 ;
break;
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
V_213 = V_211 ;
break;
default:
V_213 = V_211 ;
break;
}
return F_66 ( V_2 , V_210 , V_213 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
int V_67 ;
int V_228 = F_116 ( V_2 ) ;
if ( V_2 -> V_70 -> V_229 )
return;
for ( V_67 = 0 ; V_67 < V_2 -> V_230 . V_231 ; V_67 ++ ) {
struct V_232 * V_158 = F_117 ( & V_2 -> V_230 , V_67 ) ;
if ( V_158 -> V_3 != V_228 )
F_3 ( V_2 , V_158 -> V_3 , 0 ,
V_233 , 0 ) ;
}
V_2 -> V_234 = 1 ;
}
static void F_118 ( struct V_1 * V_2 , int V_235 )
{
F_21 ( V_2 , 0x04 , 1 << 11 , V_235 ? ( 1 << 11 ) : 0 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_214 == V_220 )
F_118 ( V_2 , 0 ) ;
if ( V_13 -> V_214 == V_220 &&
( F_6 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_29 ( 150 ) ;
}
F_30 ( V_2 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_236 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_237 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_238 ;
int V_239 ;
F_120 ( V_2 ) ;
if ( ! V_237 )
return;
V_238 = F_122 ( V_2 , V_237 ) ;
V_239 = F_7 ( V_2 , 0x78 ) ;
F_123 ( V_2 , 0x78 , 0x9004 ) ;
if ( V_238 )
F_29 ( 2 ) ;
F_2 ( V_2 , V_237 , 0 ,
V_240 , V_241 ) ;
if ( V_238 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_237 , 0 ,
V_233 , V_242 ) ;
if ( V_238 )
F_29 ( 100 ) ;
F_123 ( V_2 , 0x78 , V_239 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_237 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_238 ;
int V_239 ;
if ( ! V_237 ) {
F_119 ( V_2 ) ;
return;
}
V_238 = F_122 ( V_2 , V_237 ) ;
V_239 = F_7 ( V_2 , 0x78 ) ;
F_123 ( V_2 , 0x78 , 0x9004 ) ;
if ( V_238 )
F_29 ( 2 ) ;
F_2 ( V_2 , V_237 , 0 ,
V_240 , V_241 ) ;
if ( V_238 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_237 , 0 ,
V_233 , 0x0 ) ;
if ( V_238 )
F_29 ( 100 ) ;
F_27 ( V_2 , false ) ;
F_30 ( V_2 ) ;
F_123 ( V_2 , 0x78 , V_239 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_243 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_237 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_238 ;
if ( ! V_13 -> V_86 . V_87 . V_244 ) {
if ( V_13 -> V_86 . V_87 . V_90 == V_173 )
V_237 = V_13 -> V_86 . V_87 . V_89 [ 0 ] ;
}
F_125 ( V_2 ) ;
if ( ! V_237 )
return;
F_29 ( 30 ) ;
V_238 = F_122 ( V_2 , V_237 ) ;
F_123 ( V_2 , 0x43 , 0x9004 ) ;
F_2 ( V_2 , V_237 , 0 ,
V_240 , V_241 ) ;
if ( V_238 )
F_29 ( 85 ) ;
F_2 ( V_2 , V_237 , 0 ,
V_233 , V_242 ) ;
if ( V_238 )
F_29 ( 85 ) ;
F_21 ( V_2 , 0x46 , 3 << 12 , 0 ) ;
F_123 ( V_2 , 0x43 , 0x9614 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_237 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
bool V_238 ;
if ( ! V_13 -> V_86 . V_87 . V_244 ) {
if ( V_13 -> V_86 . V_87 . V_90 == V_173 )
V_237 = V_13 -> V_86 . V_87 . V_89 [ 0 ] ;
}
if ( ! V_237 ) {
F_119 ( V_2 ) ;
return;
}
V_238 = F_122 ( V_2 , V_237 ) ;
F_123 ( V_2 , 0x43 , 0x9004 ) ;
F_123 ( V_2 , 0x06 , 0x2100 ) ;
F_2 ( V_2 , V_237 , 0 ,
V_240 , V_241 ) ;
if ( V_238 )
F_29 ( 100 ) ;
F_2 ( V_2 , V_237 , 0 ,
V_233 , 0x0 ) ;
F_21 ( V_2 , 0x46 , 0 , 3 << 12 ) ;
if ( V_238 )
F_29 ( 100 ) ;
F_27 ( V_2 , false ) ;
F_30 ( V_2 ) ;
F_123 ( V_2 , 0x43 , 0x9614 ) ;
}
static void F_128 ( struct V_1 * V_2 , unsigned int V_245 ,
unsigned int V_5 )
{
F_2 ( V_2 , 0x51 , 0 , V_6 , V_245 >> 1 ) ;
F_2 ( V_2 , 0x51 , 0 , V_9 , V_5 & 0xffff ) ;
F_2 ( V_2 , 0x51 , 0 , V_9 , V_5 >> 16 ) ;
}
static int F_129 ( struct V_1 * V_2 , unsigned int V_245 )
{
unsigned int V_5 ;
F_2 ( V_2 , 0x51 , 0 , V_6 , V_245 >> 1 ) ;
V_5 = F_3 ( V_2 , 0x51 , 0 , V_7 , 0 )
& 0xffff ;
V_5 |= F_3 ( V_2 , 0x51 , 0 , V_7 , 0 )
<< 16 ;
return V_5 ;
}
static void F_130 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
F_128 ( V_2 , 0x3000 , 0x000c ) ;
F_128 ( V_2 , 0x880c , 0x0008 ) ;
F_128 ( V_2 , 0x61c0 , 0x11110080 ) ;
F_128 ( V_2 , 0x6230 , 0xfc0d4011 ) ;
F_128 ( V_2 , 0x61b4 , 0x040a2b03 ) ;
F_128 ( V_2 , 0x61b0 , 0x00005b17 ) ;
F_128 ( V_2 , 0x61b8 , 0x04133303 ) ;
V_5 = F_129 ( V_2 , 0x6220 ) ;
F_128 ( V_2 , 0x6220 , ( V_5 | 0x3000 ) ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
F_128 ( V_2 , 0x61b8 , 0x04133302 ) ;
F_128 ( V_2 , 0x61b0 , 0x00005b16 ) ;
F_128 ( V_2 , 0x61b4 , 0x040a2b02 ) ;
F_128 ( V_2 , 0x6230 , 0xf80d4011 ) ;
F_128 ( V_2 , 0x6220 , 0x2002010f ) ;
F_128 ( V_2 , 0x880c , 0x00000004 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
F_128 ( V_2 , 0x61b0 , 0x5b14 ) ;
F_128 ( V_2 , 0x61b0 , 0x5b16 ) ;
F_128 ( V_2 , 0x61b4 , 0x04132b00 ) ;
F_128 ( V_2 , 0x61b4 , 0x04132b02 ) ;
F_128 ( V_2 , 0x61b8 , 0x041f3300 ) ;
F_128 ( V_2 , 0x61b8 , 0x041f3302 ) ;
F_2 ( V_2 , 0x51 , 0 , V_246 , 0 ) ;
F_128 ( V_2 , 0x61b8 , 0x041b3302 ) ;
F_128 ( V_2 , 0x61b8 , 0x04173302 ) ;
F_128 ( V_2 , 0x61b8 , 0x04163302 ) ;
F_128 ( V_2 , 0x8800 , 0x348b328b ) ;
F_128 ( V_2 , 0x8808 , 0x00020022 ) ;
F_128 ( V_2 , 0x8818 , 0x00000400 ) ;
V_5 = F_129 ( V_2 , 0x6200 ) >> 16 ;
if ( V_5 <= 3 )
F_128 ( V_2 , 0x6220 , 0x2002010f ) ;
else
F_128 ( V_2 , 0x6220 , 0x6002018f ) ;
F_128 ( V_2 , 0x61ac , 0x055525f0 ) ;
F_128 ( V_2 , 0x61c0 , 0x12230080 ) ;
F_128 ( V_2 , 0x61b4 , 0x040e2b02 ) ;
F_128 ( V_2 , 0x61bc , 0x010234f8 ) ;
F_128 ( V_2 , 0x880c , 0x00000004 ) ;
F_128 ( V_2 , 0x880c , 0x00000003 ) ;
F_128 ( V_2 , 0x880c , 0x00000010 ) ;
#ifdef F_133
F_130 ( V_2 ) ;
#endif
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_247 )
F_135 ( V_2 ) ;
return F_55 ( V_2 ) ;
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_214 == V_220 )
F_118 ( V_2 , 0 ) ;
if ( V_13 -> V_214 == V_220 &&
( F_6 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_29 ( 150 ) ;
}
V_2 -> V_106 . V_107 ( V_2 ) ;
if ( V_13 -> V_214 == V_220 )
F_118 ( V_2 , 1 ) ;
if ( V_13 -> V_214 == V_220 &&
( F_6 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_29 ( 200 ) ;
}
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 , 0x01 ) ;
if ( V_13 -> V_248 )
F_2 ( V_2 , V_2 -> V_163 , 0 , V_143 ,
V_13 -> V_248 ) ;
if ( V_13 -> V_247 )
F_137 ( V_2 ) ;
return 0 ;
}
static void F_138 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 )
V_13 -> V_125 = V_249 ;
}
static void F_139 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_103 )
F_21 ( V_2 , 0x1e , 0 , 0x80 ) ;
}
static void F_140 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 )
V_13 -> V_125 |= V_250 ;
}
static void F_141 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static const struct V_251 V_252 [] = {
{ 0x20 , V_6 , 0x0d } ,
{ 0x20 , V_9 , 0x4000 } ,
{}
} ;
unsigned int V_124 ;
if ( strcmp ( V_2 -> V_74 , L_15 ) &&
strcmp ( V_2 -> V_74 , L_16 ) )
return;
V_124 = F_36 ( V_2 , 0x12 ) ;
if ( F_142 ( V_124 ) == V_253 )
F_32 ( V_2 , V_252 ) ;
}
static void F_143 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 != V_63 )
return;
V_13 -> V_86 . V_254 = & V_255 ;
V_13 -> V_86 . V_256 = & V_257 ;
}
static void F_144 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_103 )
F_21 ( V_2 , 0x07 , 0 , 0x80 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
F_146 ( V_2 ) ;
F_123 ( V_2 , 0x0c , 0x680 ) ;
F_123 ( V_2 , 0x0c , 0x480 ) ;
}
static void F_147 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 != V_63 )
return;
V_13 -> V_86 . V_145 = F_145 ;
}
static void F_148 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_258 ;
F_29 ( 200 ) ;
V_148 ( V_2 , V_27 ) ;
V_258 = V_13 -> V_86 . V_144 ? V_259 : 0 ;
F_29 ( 100 ) ;
F_2 ( V_2 , 0x18 , 0 , V_233 ,
V_258 ) ;
F_29 ( 500 ) ;
F_2 ( V_2 , 0x18 , 0 , V_233 ,
V_258 ) ;
}
static void F_149 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_125 |= V_250 ;
V_13 -> V_86 . V_260 = F_148 ;
}
}
static void F_150 ( void * V_261 , int V_262 )
{
struct V_1 * V_2 = V_261 ;
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_263 ;
if ( V_13 -> V_264 )
V_262 = ! V_262 ;
V_263 = F_93 ( V_2 , V_13 -> V_265 ) ;
V_263 &= ~ V_266 ;
V_263 |= V_262 ? V_267 : V_174 ;
if ( V_13 -> V_265 )
F_151 ( V_2 , V_13 -> V_265 , V_263 ) ;
}
static unsigned int F_152 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_268 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_268 != V_269 || V_3 == 0 ||
( V_3 != V_13 -> V_265 && V_3 != V_13 -> V_270 ) )
return V_268 ;
F_94 ( V_2 , V_3 ,
F_93 ( V_2 , V_3 ) ) ;
return V_271 ;
}
static void F_153 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
const struct V_272 * V_273 = NULL ;
if ( V_57 != V_58 )
return;
while ( ( V_273 = F_154 ( V_274 , NULL , V_273 ) ) ) {
int V_275 , V_158 ;
if ( sscanf ( V_273 -> V_98 , L_17 , & V_275 , & V_158 ) != 2 )
continue;
if ( V_158 < 0x0a || V_158 >= 0x10 )
break;
V_13 -> V_264 = V_275 ;
V_13 -> V_265 = V_158 - 0x0a + 0x18 ;
V_13 -> V_86 . V_276 . V_277 = F_150 ;
V_13 -> V_86 . V_278 = 1 ;
V_2 -> V_279 = F_152 ;
F_38 ( V_2 ,
L_18 , V_13 -> V_265 ,
V_13 -> V_264 ) ;
break;
}
}
static void F_155 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_264 = 0 ;
V_13 -> V_265 = 0x18 ;
V_13 -> V_86 . V_276 . V_277 = F_150 ;
V_13 -> V_86 . V_278 = 1 ;
V_2 -> V_279 = F_152 ;
}
}
static void F_156 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_264 = 0 ;
V_13 -> V_265 = 0x19 ;
V_13 -> V_86 . V_276 . V_277 = F_150 ;
V_13 -> V_86 . V_278 = 1 ;
V_2 -> V_279 = F_152 ;
}
}
static void F_157 ( struct V_1 * V_2 , unsigned int V_10 ,
bool V_262 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_280 = V_13 -> V_248 ;
if ( V_13 -> V_264 )
V_262 = ! V_262 ;
if ( V_262 )
V_13 -> V_248 &= ~ V_10 ;
else
V_13 -> V_248 |= V_10 ;
if ( V_13 -> V_248 != V_280 )
F_2 ( V_2 , 0x01 , 0 , V_143 ,
V_13 -> V_248 ) ;
}
static void F_158 ( void * V_261 , int V_262 )
{
struct V_1 * V_2 = V_261 ;
struct V_12 * V_13 = V_2 -> V_13 ;
F_157 ( V_2 , V_13 -> V_281 , V_262 ) ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_28 * V_282 ,
struct V_30 * V_283 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_283 )
F_157 ( V_2 , V_13 -> V_284 ,
V_283 -> V_36 . integer . V_36 [ 0 ] ||
V_283 -> V_36 . integer . V_36 [ 1 ] ) ;
}
static void F_160 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_251 V_285 [] = {
{ 0x01 , V_167 , 0x18 } ,
{ 0x01 , V_168 , 0x18 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_276 . V_277 = F_158 ;
V_13 -> V_86 . V_286 = F_159 ;
V_13 -> V_248 = 0 ;
V_13 -> V_264 = 0 ;
V_13 -> V_281 = 0x08 ;
V_13 -> V_284 = 0x10 ;
F_80 ( V_2 , V_285 ) ;
}
}
static void F_161 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_251 V_285 [] = {
{ 0x01 , V_167 , 0x22 } ,
{ 0x01 , V_168 , 0x22 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_276 . V_277 = F_158 ;
V_13 -> V_86 . V_286 = F_159 ;
V_13 -> V_248 = 0 ;
V_13 -> V_264 = 0 ;
V_13 -> V_281 = 0x02 ;
V_13 -> V_284 = 0x20 ;
F_80 ( V_2 , V_285 ) ;
}
}
static void F_162 ( struct V_1 * V_2 ,
struct V_28 * V_282 ,
struct V_30 * V_283 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_263 , V_287 , V_288 ;
V_263 = F_93 ( V_2 , V_13 -> V_270 ) ;
V_263 &= ~ V_266 ;
V_287 = V_263 | V_174 ;
V_288 = V_263 | V_267 ;
if ( ! V_283 )
return;
if ( V_283 -> V_36 . integer . V_36 [ 0 ] ||
V_283 -> V_36 . integer . V_36 [ 1 ] )
V_263 = V_288 ;
else
V_263 = V_287 ;
if ( V_13 -> V_270 )
F_151 ( V_2 , V_13 -> V_270 , V_263 ) ;
}
static void F_163 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_251 V_285 [] = {
{ 0x01 , V_167 , 0x08 } ,
{ 0x01 , V_168 , 0x08 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_276 . V_277 = F_158 ;
V_13 -> V_86 . V_286 = F_162 ;
V_13 -> V_248 = 0 ;
V_13 -> V_264 = 0 ;
V_13 -> V_281 = 0x08 ;
V_13 -> V_270 = 0x18 ;
F_80 ( V_2 , V_285 ) ;
V_2 -> V_279 = F_152 ;
}
}
static void F_164 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_251 V_285 [] = {
{ 0x01 , V_167 , 0x18 } ,
{ 0x01 , V_168 , 0x18 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_276 . V_277 = F_158 ;
V_13 -> V_86 . V_286 = F_162 ;
V_13 -> V_248 = 0 ;
V_13 -> V_264 = 0 ;
V_13 -> V_281 = 0x08 ;
V_13 -> V_270 = 0x18 ;
F_80 ( V_2 , V_285 ) ;
V_2 -> V_279 = F_152 ;
}
}
static void F_165 ( struct V_1 * V_2 ,
struct V_26 * V_289 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_166 ( V_13 -> V_290 , V_291 , 1 ) ;
F_167 ( V_13 -> V_290 ) ;
F_166 ( V_13 -> V_290 , V_291 , 0 ) ;
F_167 ( V_13 -> V_290 ) ;
}
static void F_168 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
static const struct V_251 V_285 [] = {
{ 0x01 , V_167 , 0x1e } ,
{ 0x01 , V_168 , 0x1a } ,
{ 0x01 , V_143 , 0x02 } ,
{}
} ;
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_290 = F_169 () ;
if ( ! V_13 -> V_290 ) {
F_170 ( V_2 , L_19 ) ;
return;
}
V_13 -> V_290 -> V_98 = L_20 ;
V_13 -> V_290 -> V_292 [ 0 ] = F_171 ( V_293 ) ;
V_13 -> V_290 -> V_294 [ F_172 ( V_291 ) ] = F_171 ( V_291 ) ;
if ( F_173 ( V_13 -> V_290 ) ) {
F_170 ( V_2 , L_21 ) ;
F_174 ( V_13 -> V_290 ) ;
V_13 -> V_290 = NULL ;
return;
}
F_80 ( V_2 , V_285 ) ;
F_175 ( V_2 , V_2 -> V_163 , 0 ,
V_295 , 0x04 ) ;
F_73 ( V_2 , V_2 -> V_163 ,
F_165 ) ;
V_13 -> V_86 . V_276 . V_277 = F_158 ;
V_13 -> V_86 . V_286 = F_159 ;
V_13 -> V_248 = 0 ;
V_13 -> V_264 = 0 ;
V_13 -> V_281 = 0x08 ;
V_13 -> V_284 = 0x10 ;
return;
}
if ( ! V_13 -> V_290 )
return;
switch ( V_57 ) {
case V_63 :
V_13 -> V_85 = V_54 ;
break;
case V_296 :
F_176 ( V_13 -> V_290 ) ;
V_13 -> V_290 = NULL ;
}
}
static void F_177 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_276 . V_277 = F_150 ;
V_13 -> V_86 . V_286 = F_162 ;
V_13 -> V_264 = 0 ;
V_13 -> V_265 = 0x1a ;
V_13 -> V_270 = 0x18 ;
V_13 -> V_86 . V_278 = 1 ;
V_2 -> V_279 = F_152 ;
}
}
static void F_178 ( struct V_1 * V_2 )
{
static struct V_15 V_297 [] = {
F_179 ( 0x1b , 0x0c0b ) ,
F_179 ( 0x45 , 0xd089 ) ,
F_180 ( 0x57 , 0x05 , 1 << 14 , 0 ) ,
F_179 ( 0x06 , 0x6104 ) ,
F_181 ( 0x57 , 0x03 , 0x8aa6 ) ,
{}
} ;
static struct V_15 V_298 [] = {
F_179 ( 0x1b , 0x0c0b ) ,
F_179 ( 0x45 , 0xc429 ) ,
F_182 ( 0x35 , 0x4000 , 0 ) ,
F_179 ( 0x06 , 0x2104 ) ,
F_179 ( 0x1a , 0x0001 ) ,
F_179 ( 0x26 , 0x0004 ) ,
F_179 ( 0x32 , 0x42a3 ) ,
{}
} ;
static struct V_15 V_299 [] = {
F_179 ( 0x76 , 0x000e ) ,
F_179 ( 0x6c , 0x2400 ) ,
F_179 ( 0x18 , 0x7308 ) ,
F_179 ( 0x6b , 0xc429 ) ,
{}
} ;
static struct V_15 V_300 [] = {
F_182 ( 0x10 , 7 << 8 , 6 << 8 ) ,
F_180 ( 0x57 , 0x05 , 1 << 15 | 1 << 13 , 0x0 ) ,
F_180 ( 0x57 , 0x03 , 1 << 10 , 1 << 10 ) ,
F_182 ( 0x1a , 1 << 3 , 1 << 3 ) ,
F_179 ( 0x45 , 0xc429 ) ,
F_182 ( 0x4a , 0x000f , 0x000e ) ,
{}
} ;
static struct V_15 V_301 [] = {
F_179 ( 0x15 , 0x0d40 ) ,
F_179 ( 0xb7 , 0x802b ) ,
{}
} ;
switch ( V_2 -> V_40 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_297 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_298 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_299 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_300 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_301 ) ;
break;
}
F_38 ( V_2 , L_22 ) ;
}
static void F_183 ( struct V_1 * V_2 , T_1 V_237 ,
T_1 V_228 )
{
static struct V_15 V_297 [] = {
F_181 ( 0x57 , 0x03 , 0x8aa6 ) ,
F_179 ( 0x06 , 0x6100 ) ,
{}
} ;
static struct V_15 V_298 [] = {
F_182 ( 0x35 , 0 , 1 << 14 ) ,
F_179 ( 0x06 , 0x2100 ) ,
F_179 ( 0x1a , 0x0021 ) ,
F_179 ( 0x26 , 0x008c ) ,
{}
} ;
static struct V_15 V_299 [] = {
F_179 ( 0x19 , 0xa208 ) ,
F_179 ( 0x2e , 0xacf0 ) ,
{}
} ;
static struct V_15 V_300 [] = {
F_180 ( 0x57 , 0x05 , 0 , 1 << 15 | 1 << 13 ) ,
F_180 ( 0x57 , 0x03 , 1 << 10 , 0 ) ,
F_182 ( 0x1a , 1 << 3 , 0 ) ,
{}
} ;
static struct V_15 V_302 [] = {
F_179 ( 0xb7 , 0x802b ) ,
F_179 ( 0xb5 , 0x1040 ) ,
F_182 ( 0xc3 , 0 , 1 << 12 ) ,
{}
} ;
switch ( V_2 -> V_40 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_123 ( V_2 , 0x45 , 0xc489 ) ;
F_151 ( V_2 , V_237 , 0 ) ;
F_8 ( V_2 , V_297 ) ;
F_151 ( V_2 , V_228 , V_303 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_123 ( V_2 , 0x45 , 0xc429 ) ;
F_151 ( V_2 , V_237 , 0 ) ;
F_8 ( V_2 , V_298 ) ;
F_151 ( V_2 , V_228 , V_303 ) ;
break;
case 0x10ec0292 :
F_151 ( V_2 , V_237 , 0 ) ;
F_8 ( V_2 , V_299 ) ;
break;
case 0x10ec0293 :
F_123 ( V_2 , 0x45 , 0xc429 ) ;
F_151 ( V_2 , V_237 , 0 ) ;
F_8 ( V_2 , V_300 ) ;
F_151 ( V_2 , V_228 , V_303 ) ;
break;
case 0x10ec0668 :
F_123 ( V_2 , 0x11 , 0x0001 ) ;
F_151 ( V_2 , V_237 , 0 ) ;
F_8 ( V_2 , V_302 ) ;
F_151 ( V_2 , V_228 , V_303 ) ;
break;
}
F_38 ( V_2 , L_23 ) ;
}
static void F_184 ( struct V_1 * V_2 )
{
static struct V_15 V_297 [] = {
F_179 ( 0x45 , 0xc089 ) ,
F_179 ( 0x45 , 0xc489 ) ,
F_181 ( 0x57 , 0x03 , 0x8ea6 ) ,
F_179 ( 0x49 , 0x0049 ) ,
{}
} ;
static struct V_15 V_298 [] = {
F_179 ( 0x06 , 0x2100 ) ,
F_179 ( 0x32 , 0x4ea3 ) ,
{}
} ;
static struct V_15 V_299 [] = {
F_179 ( 0x76 , 0x000e ) ,
F_179 ( 0x6c , 0x2400 ) ,
F_179 ( 0x6b , 0xc429 ) ,
F_179 ( 0x18 , 0x7308 ) ,
{}
} ;
static struct V_15 V_300 [] = {
F_182 ( 0x4a , 0x000f , 0x000e ) ,
F_179 ( 0x45 , 0xC429 ) ,
F_182 ( 0x1a , 1 << 3 , 0 ) ,
{}
} ;
static struct V_15 V_302 [] = {
F_179 ( 0x11 , 0x0041 ) ,
F_179 ( 0x15 , 0x0d40 ) ,
F_179 ( 0xb7 , 0x802b ) ,
{}
} ;
switch ( V_2 -> V_40 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_297 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_298 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_299 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_300 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_302 ) ;
break;
}
F_38 ( V_2 , L_24 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
static struct V_15 V_297 [] = {
F_179 ( 0x45 , 0xd489 ) ,
F_179 ( 0x1b , 0x0c2b ) ,
F_181 ( 0x57 , 0x03 , 0x8ea6 ) ,
{}
} ;
static struct V_15 V_298 [] = {
F_179 ( 0x45 , 0xd429 ) ,
F_179 ( 0x1b , 0x0c2b ) ,
F_179 ( 0x32 , 0x4ea3 ) ,
{}
} ;
static struct V_15 V_299 [] = {
F_179 ( 0x6b , 0xd429 ) ,
F_179 ( 0x76 , 0x0008 ) ,
F_179 ( 0x18 , 0x7388 ) ,
{}
} ;
static struct V_15 V_300 [] = {
F_179 ( 0x45 , 0xd429 ) ,
F_182 ( 0x10 , 7 << 8 , 7 << 8 ) ,
{}
} ;
static struct V_15 V_302 [] = {
F_179 ( 0x11 , 0x0001 ) ,
F_179 ( 0x15 , 0x0d60 ) ,
F_179 ( 0xc3 , 0x0000 ) ,
{}
} ;
switch ( V_2 -> V_40 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_297 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_298 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_299 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_300 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_302 ) ;
break;
}
F_38 ( V_2 , L_25 ) ;
}
static void F_186 ( struct V_1 * V_2 )
{
static struct V_15 V_297 [] = {
F_179 ( 0x45 , 0xe489 ) ,
F_179 ( 0x1b , 0x0c2b ) ,
F_181 ( 0x57 , 0x03 , 0x8ea6 ) ,
{}
} ;
static struct V_15 V_298 [] = {
F_179 ( 0x45 , 0xe429 ) ,
F_179 ( 0x1b , 0x0c2b ) ,
F_179 ( 0x32 , 0x4ea3 ) ,
{}
} ;
static struct V_15 V_299 [] = {
F_179 ( 0x6b , 0xe429 ) ,
F_179 ( 0x76 , 0x0008 ) ,
F_179 ( 0x18 , 0x7388 ) ,
{}
} ;
static struct V_15 V_300 [] = {
F_179 ( 0x45 , 0xe429 ) ,
F_182 ( 0x10 , 7 << 8 , 7 << 8 ) ,
{}
} ;
static struct V_15 V_302 [] = {
F_179 ( 0x11 , 0x0001 ) ,
F_179 ( 0x15 , 0x0d50 ) ,
F_179 ( 0xc3 , 0x0000 ) ,
{}
} ;
switch ( V_2 -> V_40 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_297 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_8 ( V_2 , V_298 ) ;
break;
case 0x10ec0292 :
F_8 ( V_2 , V_299 ) ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_300 ) ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_302 ) ;
break;
}
F_38 ( V_2 , L_26 ) ;
}
static void F_187 ( struct V_1 * V_2 )
{
int V_5 ;
bool V_304 = false ;
struct V_12 * V_13 = V_2 -> V_13 ;
static struct V_15 V_297 [] = {
F_179 ( 0x45 , 0xd089 ) ,
F_179 ( 0x49 , 0x0149 ) ,
{}
} ;
static struct V_15 V_300 [] = {
F_182 ( 0x4a , 0x000f , 0x0008 ) ,
F_179 ( 0x45 , 0xD429 ) ,
{}
} ;
static struct V_15 V_302 [] = {
F_179 ( 0x11 , 0x0001 ) ,
F_179 ( 0xb7 , 0x802b ) ,
F_179 ( 0x15 , 0x0d60 ) ,
F_179 ( 0xc3 , 0x0c00 ) ,
{}
} ;
switch ( V_2 -> V_40 ) {
case 0x10ec0255 :
case 0x10ec0256 :
F_8 ( V_2 , V_297 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_304 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_123 ( V_2 , 0x45 , 0xd029 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_304 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0292 :
F_123 ( V_2 , 0x6b , 0xd429 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x6c ) ;
V_304 = ( V_5 & 0x001c ) == 0x001c ;
break;
case 0x10ec0293 :
F_8 ( V_2 , V_300 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0x46 ) ;
V_304 = ( V_5 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0668 :
F_8 ( V_2 , V_302 ) ;
F_29 ( 300 ) ;
V_5 = F_7 ( V_2 , 0xbe ) ;
V_304 = ( V_5 & 0x1c02 ) == 0x1c02 ;
break;
}
F_38 ( V_2 , L_27 ,
V_304 ? L_28 : L_29 ) ;
V_13 -> V_305 = V_304 ? V_306 : V_307 ;
}
static void F_188 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_308 = V_13 -> V_86 . V_309 [ V_13 -> V_86 . V_310 [ 0 ] ] ;
T_1 V_237 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
int V_311 ;
if ( ! F_122 ( V_2 , V_237 ) )
V_311 = V_312 ;
else if ( V_308 == V_13 -> V_313 )
V_311 = V_314 ;
else if ( V_308 == V_13 -> V_315 )
V_311 = V_316 ;
else
V_311 = V_317 ;
if ( V_311 == V_13 -> V_318 ) {
F_146 ( V_2 ) ;
return;
}
switch ( V_311 ) {
case V_312 :
F_178 ( V_2 ) ;
V_13 -> V_86 . V_144 = false ;
break;
case V_314 :
if ( V_13 -> V_305 == V_319 )
F_187 ( V_2 ) ;
if ( V_13 -> V_305 == V_306 )
F_185 ( V_2 ) ;
else if ( V_13 -> V_305 == V_307 )
F_186 ( V_2 ) ;
V_13 -> V_86 . V_144 = true ;
break;
case V_316 :
F_183 ( V_2 , V_237 , V_13 -> V_315 ) ;
V_13 -> V_86 . V_144 = false ;
break;
case V_317 :
F_184 ( V_2 ) ;
V_13 -> V_86 . V_144 = true ;
break;
}
if ( V_311 != V_316 ) {
F_151 ( V_2 , V_237 ,
V_320 | V_321 ) ;
if ( V_13 -> V_315 )
F_151 ( V_2 , V_13 -> V_315 ,
V_322 ) ;
}
V_13 -> V_318 = V_311 ;
F_146 ( V_2 ) ;
}
static void F_189 ( struct V_1 * V_2 ,
struct V_28 * V_282 ,
struct V_30 * V_283 )
{
F_188 ( V_2 ) ;
}
static void F_190 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_305 = V_319 ;
V_148 ( V_2 , V_27 ) ;
}
static void F_191 ( struct V_1 * V_2 )
{
int V_67 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_123 * V_124 = & V_13 -> V_86 . V_87 ;
for ( V_67 = 0 ; V_67 < V_124 -> V_323 ; V_67 ++ ) {
if ( V_124 -> V_324 [ V_67 ] . V_325 && ! V_13 -> V_313 )
V_13 -> V_313 = V_124 -> V_324 [ V_67 ] . V_158 ;
if ( V_124 -> V_324 [ V_67 ] . V_326 && ! V_13 -> V_315 )
V_13 -> V_315 = V_124 -> V_324 [ V_67 ] . V_158 ;
}
V_13 -> V_86 . V_286 = F_189 ;
V_13 -> V_86 . V_145 = F_188 ;
V_13 -> V_86 . V_260 = F_190 ;
}
static void F_192 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
switch ( V_57 ) {
case V_58 :
V_13 -> V_125 |= V_250 | V_327 ;
break;
case V_63 :
F_191 ( V_2 ) ;
break;
case V_103 :
V_13 -> V_318 = 0 ;
F_188 ( V_2 ) ;
break;
}
}
static void F_193 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_125 |= V_250 ;
}
else
F_192 ( V_2 , V_56 , V_57 ) ;
}
static void F_194 ( struct V_1 * V_2 )
{
static struct V_15 V_16 [] = {
F_179 ( 0x1b , 0x880b ) ,
F_179 ( 0x45 , 0xd089 ) ,
F_179 ( 0x1b , 0x080b ) ,
F_179 ( 0x46 , 0x0004 ) ,
F_179 ( 0x1b , 0x0c0b ) ,
{}
} ;
F_8 ( V_2 , V_16 ) ;
F_29 ( 30 ) ;
}
static void F_195 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
F_194 ( V_2 ) ;
}
F_192 ( V_2 , V_56 , V_57 ) ;
}
static void F_196 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_125 |= V_250 ;
F_194 ( V_2 ) ;
}
else
F_192 ( V_2 , V_56 , V_57 ) ;
}
static void F_197 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_328 = 1 ;
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
V_13 -> V_86 . V_126 = 0 ;
}
}
static unsigned int F_201 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_268 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_13 -> V_86 . V_144 )
if ( V_3 == V_2 -> V_163 || V_3 == 0x02 || V_3 == 0x15 )
return V_271 ;
return V_268 ;
}
static void F_202 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_63 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_329 * V_330 = & V_13 -> V_86 . V_331 ;
int V_67 ;
V_13 -> V_104 = F_198 ;
V_2 -> V_279 = F_201 ;
for ( V_67 = 0 ; V_67 < V_330 -> V_332 ; V_67 ++ ) {
if ( V_13 -> V_86 . V_309 [ V_67 ] == 0x12 ) {
V_13 -> V_86 . V_310 [ 0 ] = V_67 ;
break;
}
}
}
}
static void F_203 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
F_123 ( V_2 , 0xc4 , 0x8000 ) ;
F_21 ( V_2 , 0xc2 , ~ 0xfe , 0 ) ;
F_151 ( V_2 , 0x18 , 0 ) ;
}
F_192 ( V_2 , V_56 , V_57 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_123 * V_124 = & V_13 -> V_86 . V_87 ;
T_1 V_3 ;
unsigned int V_333 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_124 -> V_323 ; V_67 ++ ) {
if ( V_124 -> V_324 [ V_67 ] . type != V_334 )
continue;
V_3 = V_124 -> V_324 [ V_67 ] . V_158 ;
V_333 = F_36 ( V_2 , V_3 ) ;
if ( F_204 ( V_333 ) == V_335 )
continue;
return V_3 ;
}
return 0 ;
}
static void F_205 ( struct V_1 * V_2 ,
const struct V_55 * V_56 ,
int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_57 == V_63 ) {
int V_228 = F_116 ( V_2 ) ;
int V_237 = V_13 -> V_86 . V_87 . V_88 [ 0 ] ;
if ( F_10 ( ! V_228 || ! V_237 ) )
return;
F_206 ( V_2 , V_228 , V_237 ) ;
}
}
static void F_207 ( struct V_1 * V_2 ,
const struct V_55 * V_56 ,
int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_123 * V_124 = & V_13 -> V_86 . V_87 ;
int V_67 ;
if ( V_57 != V_63 )
return;
for ( V_67 = 0 ; V_67 < V_124 -> V_323 ; V_67 ++ ) {
T_1 V_3 = V_124 -> V_324 [ V_67 ] . V_158 ;
unsigned int V_333 ;
if ( V_124 -> V_324 [ V_67 ] . type != V_334 )
continue;
V_333 = F_36 ( V_2 , V_3 ) ;
if ( F_204 ( V_333 ) != V_335 )
continue;
F_107 ( V_2 , V_3 , V_138 ,
( 0x00 << V_198 ) |
( 0x01 << V_199 ) |
( 0x2f << V_200 ) |
( 0 << V_201 ) ) ;
}
}
static void F_208 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_258 ;
F_29 ( 200 ) ;
V_148 ( V_2 , V_27 ) ;
V_258 = V_13 -> V_86 . V_144 ? V_259 : 0 ;
F_29 ( 600 ) ;
F_2 ( V_2 , 0x19 , 0 , V_233 ,
V_258 ) ;
}
static void F_209 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
switch ( V_57 ) {
case V_58 :
F_210 ( V_2 , 0x03 , 0 ) ;
V_13 -> V_86 . V_126 = 0 ;
break;
case V_103 :
F_21 ( V_2 , 0x06 , 0x000c , 0 ) ;
F_21 ( V_2 , 0x1a , 0 , 1 << 4 ) ;
break;
}
}
static void F_211 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
switch ( V_57 ) {
case V_58 :
V_13 -> V_86 . V_260 = F_208 ;
break;
case V_103 :
F_21 ( V_2 , 0x06 , 0x000c , 0 ) ;
break;
}
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_146 ( V_2 ) ;
if ( F_122 ( V_2 , 0x1b ) )
V_13 -> V_86 . V_336 |= ( 1ULL << 0x14 ) ;
}
static void F_213 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_251 V_337 [] = {
{ 0x01 , V_167 , 0x04 } ,
{ 0x01 , V_168 , 0x04 } ,
{ 0x01 , V_143 , 0x04 } ,
{}
} ;
static const struct V_149 V_338 [] = {
{ 0x1b , 0x21114000 } ,
{}
} ;
struct V_28 * V_29 ;
switch ( V_57 ) {
case V_58 :
F_80 ( V_2 , V_337 ) ;
F_82 ( V_2 , V_338 ) ;
V_13 -> V_86 . V_328 = 1 ;
V_13 -> V_86 . V_145 = F_212 ;
F_73 ( V_2 , 0x1b ,
V_148 ) ;
break;
case V_101 :
V_29 = F_15 ( V_2 , L_30 ) ;
if ( V_29 )
strcpy ( V_29 -> V_339 . V_98 , L_31 ) ;
V_29 = F_15 ( V_2 , L_32 ) ;
if ( V_29 )
strcpy ( V_29 -> V_339 . V_98 , L_30 ) ;
break;
}
}
static void F_214 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
T_1 V_169 [ 2 ] = { 0x0c } ;
F_90 ( V_2 , 0x14 , 1 , V_169 ) ;
F_90 ( V_2 , 0x15 , 1 , V_169 ) ;
}
}
static void F_215 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_5 ;
if ( V_13 -> V_214 != V_220 )
return;
if ( ( F_6 ( V_2 ) & 0x00ff ) < 0x015 ) {
F_123 ( V_2 , 0xf , 0x960b ) ;
F_123 ( V_2 , 0xe , 0x8817 ) ;
}
if ( ( F_6 ( V_2 ) & 0x00ff ) == 0x016 ) {
F_123 ( V_2 , 0xf , 0x960b ) ;
F_123 ( V_2 , 0xe , 0x8814 ) ;
}
if ( ( F_6 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_21 ( V_2 , 0x04 , 0 , 1 << 11 ) ;
}
if ( ( F_6 ( V_2 ) & 0x00ff ) == 0x018 ) {
V_5 = F_7 ( V_2 , 0xd ) ;
if ( V_5 != - 1 && ( V_5 & 0x0c00 ) >> 10 != 0x1 ) {
F_123 ( V_2 , 0xd , V_5 | ( 1 << 10 ) ) ;
}
V_5 = F_7 ( V_2 , 0x17 ) ;
if ( V_5 != - 1 && ( V_5 & 0x01c0 ) >> 6 != 0x4 ) {
F_123 ( V_2 , 0x17 , V_5 | ( 1 << 7 ) ) ;
}
}
F_21 ( V_2 , 0x4 , 0 , 1 << 11 ) ;
}
static int F_216 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_187 = 0x18 ;
F_75 ( V_2 , V_340 ,
V_341 , V_342 ) ;
F_217 ( V_2 , V_343 , V_342 ) ;
F_75 ( V_2 , NULL , V_344 ,
V_342 ) ;
F_50 ( V_2 , V_58 ) ;
F_35 ( V_2 ) ;
if ( F_64 ( V_2 ) )
V_13 -> V_86 . V_133 = 0x01 ;
switch ( V_2 -> V_40 ) {
case 0x10ec0269 :
V_13 -> V_214 = V_215 ;
switch ( F_6 ( V_2 ) & 0x00f0 ) {
case 0x0010 :
if ( V_2 -> V_70 -> V_71 &&
V_2 -> V_70 -> V_71 -> V_117 == 0x1025 &&
V_13 -> V_59 . V_79 == 1 )
V_94 = F_60 ( V_2 , L_15 ) ;
V_13 -> V_214 = V_220 ;
break;
case 0x0020 :
if ( V_2 -> V_70 -> V_71 &&
V_2 -> V_70 -> V_71 -> V_117 == 0x17aa &&
V_2 -> V_70 -> V_71 -> V_73 == 0x21f3 )
V_94 = F_60 ( V_2 , L_33 ) ;
V_13 -> V_214 = V_216 ;
break;
case 0x0030 :
V_13 -> V_214 = V_221 ;
break;
default:
F_13 ( V_2 , 0x20 , 0x04 , 15 ) ;
}
if ( V_94 < 0 )
goto error;
V_13 -> V_102 = F_215 ;
F_215 ( V_2 ) ;
break;
case 0x10ec0280 :
case 0x10ec0290 :
V_13 -> V_214 = V_217 ;
break;
case 0x10ec0282 :
V_13 -> V_214 = V_222 ;
V_13 -> V_104 = F_124 ;
V_13 -> V_102 = F_121 ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
V_13 -> V_214 = V_223 ;
V_13 -> V_104 = F_127 ;
V_13 -> V_102 = F_126 ;
break;
case 0x10ec0284 :
case 0x10ec0292 :
V_13 -> V_214 = V_218 ;
break;
case 0x10ec0285 :
case 0x10ec0293 :
V_13 -> V_214 = V_219 ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
V_13 -> V_214 = V_224 ;
V_13 -> V_104 = F_115 ;
break;
case 0x10ec0298 :
V_13 -> V_214 = V_225 ;
break;
case 0x10ec0255 :
V_13 -> V_214 = V_226 ;
break;
case 0x10ec0256 :
V_13 -> V_214 = V_227 ;
break;
}
if ( F_3 ( V_2 , 0x51 , 0 , V_345 , 0 ) == 0x10ec5505 ) {
V_13 -> V_247 = 1 ;
V_13 -> V_102 = F_132 ;
}
V_94 = F_114 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_137 && V_13 -> V_86 . V_133 )
F_76 ( V_13 , 0x0b , 0x04 , V_138 ) ;
V_2 -> V_106 = V_139 ;
#ifdef F_218
V_2 -> V_106 . V_346 = F_134 ;
V_2 -> V_106 . V_347 = F_136 ;
#endif
if ( ! V_13 -> V_104 )
V_13 -> V_104 = F_119 ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_62 ( V_2 ) ;
return V_94 ;
}
static int F_219 ( struct V_1 * V_2 )
{
static const T_1 V_348 [] = { 0x1d , 0 } ;
static const T_1 V_349 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_66 ( V_2 , V_348 , V_349 ) ;
}
static void F_220 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned int V_5 ;
if ( V_57 != V_103 )
return;
V_5 = F_93 ( V_2 , 0x0f ) ;
if ( ! ( V_5 & ( V_350 | V_320 ) ) )
V_5 |= V_350 ;
V_5 |= V_177 ;
F_94 ( V_2 , 0x0f , V_5 ) ;
V_13 -> V_86 . V_175 = 1 ;
}
static void F_221 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 )
V_2 -> V_351 = 1 ;
}
static int F_222 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x15 ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_133 = 0x23 ;
F_75 ( V_2 , NULL , V_352 , V_353 ) ;
F_50 ( V_2 , V_58 ) ;
V_94 = F_219 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_137 )
F_76 ( V_13 , 0x23 , 0 , V_354 ) ;
V_2 -> V_106 = V_139 ;
#ifdef F_218
V_13 -> V_105 = F_54 ;
#endif
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_62 ( V_2 ) ;
return V_94 ;
}
static int F_223 ( struct V_1 * V_2 )
{
static const T_1 V_355 [] = { 0x1d , 0 } ;
static const T_1 V_356 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_66 ( V_2 , V_355 , V_356 ) ;
}
static void F_224 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_58 ) {
F_225 ( V_2 , 0x18 , 0x00000734 ) ;
F_225 ( V_2 , 0x19 , 0x0000073c ) ;
}
}
static int F_226 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_133 = 0x23 ;
F_75 ( V_2 , NULL , V_357 , V_358 ) ;
F_50 ( V_2 , V_58 ) ;
V_94 = F_223 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_137 )
F_76 ( V_13 , 0x0b , 0x05 , V_138 ) ;
V_2 -> V_106 = V_139 ;
V_13 -> V_104 = F_28 ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_62 ( V_2 ) ;
return V_94 ;
}
static int F_227 ( struct V_1 * V_2 )
{
static const T_1 V_359 [] = { 0x1d , 0 } ;
static const T_1 V_360 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_361 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_213 ;
if ( V_2 -> V_40 == 0x10ec0272 || V_2 -> V_40 == 0x10ec0663 ||
V_2 -> V_40 == 0x10ec0665 || V_2 -> V_40 == 0x10ec0670 ||
V_2 -> V_40 == 0x10ec0671 )
V_213 = V_360 ;
else
V_213 = V_361 ;
return F_66 ( V_2 , V_359 , V_213 ) ;
}
static void F_228 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 != V_58 )
return;
if ( F_107 ( V_2 , 0x2 , V_354 ,
( 0x3b << V_198 ) |
( 0x3b << V_199 ) |
( 0x03 << V_200 ) |
( 0 << V_201 ) ) )
F_229 ( V_2 , L_34 ) ;
}
static void F_230 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
if ( V_57 == V_101 ) {
struct V_12 * V_13 = V_2 -> V_13 ;
V_13 -> V_86 . V_362 [ 0 ] . V_363 [ 0 ] . V_364 = V_365 ;
}
}
static unsigned int F_231 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_268 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_3 == V_2 -> V_163 && V_268 == V_269 && V_13 -> V_248 )
return V_271 ;
return V_268 ;
}
static void F_232 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , int V_57 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
static const struct V_251 V_285 [] = {
{ 0x01 , V_167 , 0x01 } ,
{ 0x01 , V_168 , 0x01 } ,
{}
} ;
if ( V_57 == V_58 ) {
V_13 -> V_86 . V_276 . V_277 = F_158 ;
V_13 -> V_248 = 0 ;
V_13 -> V_264 = 1 ;
V_13 -> V_281 = 0x01 ;
F_80 ( V_2 , V_285 ) ;
V_2 -> V_279 = F_231 ;
}
}
static void F_233 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_366 ) ;
}
static int F_234 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_94 ;
V_94 = F_69 ( V_2 , 0x0b ) ;
if ( V_94 < 0 )
return V_94 ;
V_13 = V_2 -> V_13 ;
V_13 -> V_125 = V_249 ;
F_13 ( V_2 , 0x20 , 0x04 , 15 ) ;
switch ( V_2 -> V_40 ) {
case 0x10ec0668 :
V_13 -> V_102 = F_233 ;
break;
}
F_75 ( V_2 , V_367 ,
V_368 , V_369 ) ;
F_217 ( V_2 , V_370 , V_369 ) ;
F_50 ( V_2 , V_58 ) ;
F_35 ( V_2 ) ;
if ( F_64 ( V_2 ) )
V_13 -> V_86 . V_133 = 0x01 ;
if ( ( F_6 ( V_2 ) & ( 1 << 14 ) ) &&
V_2 -> V_70 -> V_71 && V_2 -> V_70 -> V_71 -> V_117 == 0x1025 &&
V_13 -> V_59 . V_79 == 1 ) {
V_94 = F_60 ( V_2 , L_35 ) ;
if ( V_94 < 0 )
goto error;
}
V_94 = F_227 ( V_2 ) ;
if ( V_94 < 0 )
goto error;
if ( ! V_13 -> V_86 . V_137 && V_13 -> V_86 . V_133 ) {
switch ( V_2 -> V_40 ) {
case 0x10ec0662 :
F_76 ( V_13 , 0x0b , 0x05 , V_138 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0668 :
F_76 ( V_13 , 0x0b , 0x04 , V_138 ) ;
break;
case 0x10ec0273 :
F_76 ( V_13 , 0x0b , 0x03 , V_138 ) ;
break;
}
}
V_2 -> V_106 = V_139 ;
V_13 -> V_104 = F_28 ;
F_50 ( V_2 , V_63 ) ;
return 0 ;
error:
F_62 ( V_2 ) ;
return V_94 ;
}
static int F_235 ( struct V_1 * V_2 )
{
return F_66 ( V_2 , NULL , NULL ) ;
}
static int F_236 ( struct V_1 * V_2 )
{
int V_94 ;
V_94 = F_69 ( V_2 , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
V_94 = F_235 ( V_2 ) ;
if ( V_94 < 0 ) {
F_62 ( V_2 ) ;
return V_94 ;
}
V_2 -> V_106 = V_139 ;
return 0 ;
}
static int T_2 F_237 ( void )
{
return F_238 ( & V_371 ) ;
}
static void T_3 F_239 ( void )
{
F_240 ( & V_371 ) ;
}
