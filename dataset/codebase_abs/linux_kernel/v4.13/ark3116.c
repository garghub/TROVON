static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_2 ( V_4 -> V_5 . V_6 ) == 0x18ec &&
F_2 ( V_4 -> V_5 . V_7 ) == 0x3118 )
return 1 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_8 , T_1 V_9 )
{
int V_10 ;
V_10 = F_4 ( V_2 -> V_4 ,
F_5 ( V_2 -> V_4 , 0 ) ,
0xfe , 0x40 , V_9 , V_8 ,
NULL , 0 , V_11 ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned V_8 , unsigned char * V_12 )
{
int V_10 ;
V_10 = F_4 ( V_2 -> V_4 ,
F_7 ( V_2 -> V_4 , 0 ) ,
0xfe , 0xc0 , 0 , V_8 ,
V_12 , 1 , V_11 ) ;
if ( V_10 < 1 ) {
F_8 ( & V_2 -> V_13 -> V_4 ,
L_1 ,
V_8 , V_10 ) ;
if ( V_10 >= 0 )
V_10 = - V_14 ;
return V_10 ;
}
return V_12 [ 0 ] ;
}
static inline int F_9 ( int V_15 )
{
return ( 12000000 + 2 * V_15 ) / ( 4 * V_15 ) ;
}
static int F_10 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_18 * V_19 ;
V_19 = F_11 ( sizeof( * V_19 ) , V_20 ) ;
if ( ! V_19 )
return - V_21 ;
F_12 ( & V_19 -> V_22 ) ;
F_13 ( & V_19 -> V_23 ) ;
V_19 -> V_24 = F_1 ( V_2 ) ;
F_14 ( V_17 , V_19 ) ;
F_3 ( V_2 , V_25 , 0 ) ;
F_3 ( V_2 , V_26 , 0 ) ;
V_19 -> V_27 = 0 ;
F_3 ( V_2 , 0x8 , 0 ) ;
V_19 -> V_28 = 0 ;
F_3 ( V_2 , V_29 , 0 ) ;
if ( ! ( V_19 -> V_24 ) ) {
F_3 ( V_2 , 0xb , 0 ) ;
} else {
F_3 ( V_2 , 0xb , 1 ) ;
F_3 ( V_2 , 0xc , 0 ) ;
F_3 ( V_2 , 0xd , 0x41 ) ;
F_3 ( V_2 , 0xa , 1 ) ;
}
F_3 ( V_2 , V_30 , V_31 ) ;
V_19 -> V_32 = F_9 ( 9600 ) ;
F_3 ( V_2 , V_33 , V_19 -> V_32 & 0xff ) ;
F_3 ( V_2 , V_34 , ( V_19 -> V_32 >> 8 ) & 0xff ) ;
V_19 -> V_35 = V_36 ;
F_3 ( V_2 , V_30 , V_36 ) ;
F_3 ( V_2 , 0xe , 0 ) ;
if ( V_19 -> V_24 )
F_3 ( V_2 , 0x9 , 0 ) ;
F_15 ( & V_17 -> V_4 , L_2 , V_19 -> V_24 ? L_3 : L_4 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_17 ( V_17 ) ;
F_18 ( & V_19 -> V_22 ) ;
F_19 ( V_19 ) ;
return 0 ;
}
static void F_20 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = & V_38 -> V_40 ;
* V_40 = V_41 ;
V_40 -> V_42 = V_43 | V_44
| V_45 | V_46 | V_47 ;
V_40 -> V_48 = 9600 ;
V_40 -> V_49 = 9600 ;
}
static void F_21 ( struct V_37 * V_38 ,
struct V_16 * V_17 ,
struct V_39 * V_50 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_18 * V_19 = F_17 ( V_17 ) ;
struct V_39 * V_40 = & V_38 -> V_40 ;
unsigned int V_51 = V_40 -> V_42 ;
int V_15 = F_22 ( V_38 ) ;
int V_32 ;
T_1 V_35 , V_27 , V_52 ;
switch ( V_51 & V_53 ) {
case V_54 :
V_35 = V_55 ;
break;
case V_56 :
V_35 = V_57 ;
break;
case V_58 :
V_35 = V_59 ;
break;
default:
case V_44 :
V_35 = V_36 ;
break;
}
if ( V_51 & V_60 )
V_35 |= V_61 ;
if ( V_51 & V_62 )
V_35 |= V_63 ;
if ( ! ( V_51 & V_64 ) )
V_35 |= V_65 ;
#ifdef F_23
if ( V_51 & F_23 )
V_35 |= V_66 ;
#endif
V_27 = ( V_51 & V_67 ) ? 0x03 : 0x00 ;
F_24 ( & V_17 -> V_4 , L_5 , V_68 , V_15 ) ;
V_52 = 0 ;
switch ( V_15 ) {
case 0 :
V_32 = F_9 ( 9600 ) ;
break;
default:
if ( ( V_15 < 75 ) || ( V_15 > 3000000 ) )
V_15 = 9600 ;
V_32 = F_9 ( V_15 ) ;
break;
case 460800 :
V_52 = 1 ;
V_32 = F_9 ( V_15 ) ;
break;
case 921600 :
V_52 = 2 ;
V_32 = F_9 ( V_15 ) ;
break;
}
F_25 ( & V_19 -> V_22 ) ;
V_35 |= ( V_19 -> V_35 & V_69 ) ;
F_24 ( & V_17 -> V_4 , L_6 ,
V_68 , V_27 , V_35 , V_32 ) ;
if ( V_19 -> V_27 != V_27 ) {
V_19 -> V_27 = V_27 ;
F_3 ( V_2 , 0x8 , V_27 ) ;
}
if ( V_19 -> V_32 != V_32 ) {
V_19 -> V_32 = V_32 ;
V_19 -> V_35 = V_35 ;
F_3 ( V_2 , V_26 , 0 ) ;
F_3 ( V_2 , V_30 ,
V_35 | V_31 ) ;
F_3 ( V_2 , V_33 , V_32 & 0xff ) ;
F_3 ( V_2 , V_34 , ( V_32 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_30 , V_35 ) ;
F_3 ( V_2 , 0xe , V_52 ) ;
F_3 ( V_2 , V_26 , V_70 ) ;
} else if ( V_19 -> V_35 != V_35 ) {
V_19 -> V_35 = V_35 ;
F_3 ( V_2 , V_30 , V_35 ) ;
}
F_26 ( & V_19 -> V_22 ) ;
if ( F_27 ( V_38 ) || F_28 ( V_38 ) ) {
F_29 ( & V_17 -> V_4 ,
L_7 ) ;
}
if ( F_30 ( V_40 ) )
F_31 ( V_40 , V_15 , V_15 ) ;
}
static void F_32 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
F_3 ( V_2 , V_26 , 0 ) ;
F_3 ( V_2 , V_25 , 0 ) ;
F_33 ( V_17 ) ;
F_34 ( V_17 -> V_71 ) ;
}
static int F_35 ( struct V_37 * V_38 , struct V_16 * V_17 )
{
struct V_18 * V_19 = F_17 ( V_17 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
unsigned char * V_12 ;
int V_10 ;
V_12 = F_36 ( 1 , V_20 ) ;
if ( V_12 == NULL )
return - V_21 ;
V_10 = F_37 ( V_38 , V_17 ) ;
if ( V_10 ) {
F_24 ( & V_17 -> V_4 ,
L_8 ,
V_68 , V_10 ) ;
goto V_72;
}
F_6 ( V_2 , V_73 , V_12 ) ;
V_10 = F_6 ( V_2 , V_74 , V_12 ) ;
if ( V_10 < 0 )
goto V_75;
V_19 -> V_76 = * V_12 ;
V_10 = F_6 ( V_2 , V_77 , V_12 ) ;
if ( V_10 < 0 )
goto V_75;
V_19 -> V_78 = * V_12 ;
V_10 = F_38 ( V_17 -> V_71 , V_20 ) ;
if ( V_10 ) {
F_8 ( & V_17 -> V_4 , L_9 ,
V_10 ) ;
goto V_75;
}
F_3 ( V_17 -> V_2 , V_25 , V_79 | V_80 ) ;
F_3 ( V_17 -> V_2 , V_26 , V_70 ) ;
if ( V_38 )
F_21 ( V_38 , V_17 , NULL ) ;
F_19 ( V_12 ) ;
return 0 ;
V_75:
F_33 ( V_17 ) ;
V_72:
F_19 ( V_12 ) ;
return V_10 ;
}
static int F_39 ( struct V_37 * V_38 ,
unsigned int V_81 , unsigned long V_82 )
{
struct V_16 * V_17 = V_38 -> V_83 ;
struct V_84 V_85 ;
void T_2 * V_86 = ( void T_2 * ) V_82 ;
switch ( V_81 ) {
case V_87 :
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . type = V_88 ;
V_85 . line = V_17 -> V_89 ;
V_85 . V_17 = V_17 -> V_90 ;
V_85 . V_91 = 0 ;
V_85 . V_92 = 460800 ;
if ( F_40 ( V_86 , & V_85 , sizeof( V_85 ) ) )
return - V_93 ;
return 0 ;
case V_94 :
if ( F_41 ( & V_85 , V_86 , sizeof( V_85 ) ) )
return - V_93 ;
return 0 ;
}
return - V_95 ;
}
static int F_42 ( struct V_37 * V_38 )
{
struct V_16 * V_17 = V_38 -> V_83 ;
struct V_18 * V_19 = F_17 ( V_17 ) ;
T_3 V_96 ;
T_3 V_97 ;
unsigned long V_98 ;
F_25 ( & V_19 -> V_22 ) ;
V_97 = V_19 -> V_28 ;
F_26 ( & V_19 -> V_22 ) ;
F_43 ( & V_19 -> V_23 , V_98 ) ;
V_96 = V_19 -> V_76 ;
F_44 ( & V_19 -> V_23 , V_98 ) ;
return ( V_96 & V_99 ? V_100 : 0 ) |
( V_96 & V_101 ? V_102 : 0 ) |
( V_96 & V_103 ? V_104 : 0 ) |
( V_96 & V_105 ? V_106 : 0 ) |
( V_97 & V_107 ? V_108 : 0 ) |
( V_97 & V_109 ? V_110 : 0 ) |
( V_97 & V_111 ? V_112 : 0 ) |
( V_97 & V_113 ? V_114 : 0 ) ;
}
static int F_45 ( struct V_37 * V_38 ,
unsigned V_115 , unsigned V_116 )
{
struct V_16 * V_17 = V_38 -> V_83 ;
struct V_18 * V_19 = F_17 ( V_17 ) ;
F_25 ( & V_19 -> V_22 ) ;
if ( V_115 & V_110 )
V_19 -> V_28 |= V_109 ;
if ( V_115 & V_108 )
V_19 -> V_28 |= V_107 ;
if ( V_115 & V_112 )
V_19 -> V_28 |= V_111 ;
if ( V_115 & V_114 )
V_19 -> V_28 |= V_113 ;
if ( V_116 & V_110 )
V_19 -> V_28 &= ~ V_109 ;
if ( V_116 & V_108 )
V_19 -> V_28 &= ~ V_107 ;
if ( V_116 & V_112 )
V_19 -> V_28 &= ~ V_111 ;
if ( V_116 & V_114 )
V_19 -> V_28 &= ~ V_113 ;
F_3 ( V_17 -> V_2 , V_29 , V_19 -> V_28 ) ;
F_26 ( & V_19 -> V_22 ) ;
return 0 ;
}
static void F_46 ( struct V_37 * V_38 , int V_117 )
{
struct V_16 * V_17 = V_38 -> V_83 ;
struct V_18 * V_19 = F_17 ( V_17 ) ;
F_25 ( & V_19 -> V_22 ) ;
if ( V_117 )
V_19 -> V_35 |= V_69 ;
else
V_19 -> V_35 &= ~ V_69 ;
F_3 ( V_17 -> V_2 , V_30 , V_19 -> V_35 ) ;
F_26 ( & V_19 -> V_22 ) ;
}
static void F_47 ( struct V_16 * V_17 , T_1 V_76 )
{
struct V_18 * V_19 = F_17 ( V_17 ) ;
unsigned long V_98 ;
F_43 ( & V_19 -> V_23 , V_98 ) ;
V_19 -> V_76 = V_76 ;
F_44 ( & V_19 -> V_23 , V_98 ) ;
if ( V_76 & V_118 ) {
if ( V_76 & V_119 )
V_17 -> V_120 . V_121 ++ ;
if ( V_76 & V_122 )
V_17 -> V_120 . V_123 ++ ;
if ( V_76 & V_124 )
V_17 -> V_120 . V_125 ++ ;
if ( V_76 & V_126 )
V_17 -> V_120 . V_127 ++ ;
F_48 ( & V_17 -> V_17 . V_128 ) ;
}
}
static void F_49 ( struct V_16 * V_17 , T_1 V_78 )
{
struct V_18 * V_19 = F_17 ( V_17 ) ;
unsigned long V_98 ;
F_43 ( & V_19 -> V_23 , V_98 ) ;
V_19 -> V_78 |= V_78 ;
F_44 ( & V_19 -> V_23 , V_98 ) ;
if ( V_78 & V_129 ) {
if ( V_78 & V_130 )
V_17 -> V_120 . V_131 ++ ;
if ( V_78 & V_132 )
V_17 -> V_120 . V_133 ++ ;
if ( V_78 & V_134 )
V_17 -> V_120 . V_135 ++ ;
if ( V_78 & V_136 )
V_17 -> V_120 . V_137 ++ ;
}
}
static void F_50 ( struct V_138 * V_138 )
{
struct V_16 * V_17 = V_138 -> V_139 ;
int V_96 = V_138 -> V_96 ;
const T_1 * V_140 = V_138 -> V_141 ;
int V_10 ;
switch ( V_96 ) {
case - V_142 :
case - V_143 :
case - V_144 :
F_24 ( & V_17 -> V_4 , L_10 ,
V_68 , V_96 ) ;
return;
default:
F_24 ( & V_17 -> V_4 , L_11 ,
V_68 , V_96 ) ;
break;
case 0 :
if ( ( V_138 -> V_145 == 4 ) && ( V_140 [ 0 ] == 0xe8 ) ) {
const T_1 V_146 = V_140 [ 1 ] & V_147 ;
F_24 ( & V_17 -> V_4 , L_12 , V_68 , V_140 [ 1 ] ) ;
if ( V_146 == V_148 ) {
F_24 ( & V_17 -> V_4 , L_13 ,
V_68 , V_140 [ 3 ] ) ;
F_47 ( V_17 , V_140 [ 3 ] ) ;
break;
} else if ( V_146 == V_149 ) {
F_24 ( & V_17 -> V_4 , L_14 ,
V_68 , V_140 [ 2 ] ) ;
F_49 ( V_17 , V_140 [ 2 ] ) ;
break;
}
}
F_51 ( & V_17 -> V_4 , V_68 ,
V_138 -> V_145 ,
V_138 -> V_141 ) ;
break;
}
V_10 = F_38 ( V_138 , V_150 ) ;
if ( V_10 )
F_8 ( & V_17 -> V_4 , L_15 ,
V_10 ) ;
}
static void F_52 ( struct V_138 * V_138 )
{
struct V_16 * V_17 = V_138 -> V_139 ;
struct V_18 * V_19 = F_17 ( V_17 ) ;
unsigned char * V_140 = V_138 -> V_141 ;
char V_151 = V_152 ;
unsigned long V_98 ;
T_3 V_78 ;
F_43 ( & V_19 -> V_23 , V_98 ) ;
V_78 = V_19 -> V_78 ;
V_19 -> V_78 &= ~ V_129 ;
F_44 ( & V_19 -> V_23 , V_98 ) ;
if ( ! V_138 -> V_145 )
return;
if ( V_78 & V_129 ) {
if ( V_78 & V_130 )
V_151 = V_153 ;
else if ( V_78 & V_134 )
V_151 = V_154 ;
else if ( V_78 & V_132 )
V_151 = V_155 ;
if ( V_78 & V_136 )
F_53 ( & V_17 -> V_17 , 0 , V_156 ) ;
}
F_54 ( & V_17 -> V_17 , V_140 , V_151 ,
V_138 -> V_145 ) ;
F_55 ( & V_17 -> V_17 ) ;
}
