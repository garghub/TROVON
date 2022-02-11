static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
unsigned int V_5 = 0 ;
F_2 ( V_3 , V_2 -> V_6 + V_7 ) ;
for ( V_4 = 0 ; V_4 < V_8 ; V_4 ++ ) {
V_5 = F_3 ( V_2 -> V_6 + V_7 ) ;
V_5 &= V_9 ;
if ( V_5 != V_10 )
break;
F_4 ( 1 ) ;
}
if ( V_5 != V_11 )
F_5 ( V_2 -> V_12 , L_1 ,
V_13 , V_5 ) ;
}
static unsigned int F_6 ( struct V_1 * V_2 ,
unsigned int V_14 , unsigned int V_15 ,
unsigned int V_16 )
{
F_2 ( V_14 , V_2 -> V_6 + V_17 ) ;
F_2 ( V_15 , V_2 -> V_6 + F_7 ( 0 ) ) ;
F_2 ( V_16 , V_2 -> V_6 + F_7 ( 1 ) ) ;
F_1 ( V_2 , V_18 ) ;
return F_3 ( V_2 -> V_6 + F_7 ( 2 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_15 , unsigned int V_19 )
{
F_2 ( V_14 , V_2 -> V_6 + V_17 ) ;
F_2 ( V_15 , V_2 -> V_6 + F_7 ( 0 ) ) ;
F_2 ( 0 , V_2 -> V_6 + F_7 ( 1 ) ) ;
F_2 ( V_19 , V_2 -> V_6 + F_7 ( 2 ) ) ;
F_1 ( V_2 , V_20 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
int V_26 ;
int V_27 ;
int V_28 ;
int V_4 ;
unsigned short V_19 ;
V_26 = F_3 ( V_2 -> V_6 + V_29 ) ;
V_28 = V_26 - V_24 -> V_30 ;
if ( V_28 < 0 )
V_28 += V_31 ;
V_27 = V_24 -> V_32 ;
for ( V_4 = 0 ; V_4 < V_28 ; V_4 ++ ) {
V_19 = F_3 ( V_2 -> V_6 + V_33 + V_27 ) ;
F_10 ( V_22 , & V_19 , 1 ) ;
V_27 ++ ;
if ( V_27 >= V_31 )
V_27 = 0 ;
}
V_24 -> V_32 = V_27 ;
F_2 ( V_27 , V_2 -> V_6 + V_34 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
F_2 ( V_35 , V_2 -> V_6 + V_17 ) ;
F_1 ( V_2 , V_36 ) ;
F_2 ( 0 , V_2 -> V_6 + V_37 ) ;
return 0 ;
}
static T_1 F_12 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
struct V_21 * V_22 = V_2 -> V_40 ;
unsigned int V_5 ;
if ( ! V_2 -> V_41 )
return V_42 ;
V_5 = F_3 ( V_2 -> V_6 + V_43 ) ;
if ( V_5 & V_44 )
F_9 ( V_2 , V_22 ) ;
if ( V_5 & ( V_45 | V_46 ) )
V_22 -> V_47 -> V_48 |= V_49 ;
V_50 ++ ;
if ( V_50 >= 10 )
V_22 -> V_47 -> V_48 |= V_51 ;
F_13 ( V_2 , V_22 ) ;
return V_52 ;
}
static int F_14 ( unsigned int V_53 , unsigned int * V_54 ,
unsigned int V_55 )
{
int V_56 , V_57 , V_58 ;
for ( V_58 = 0 ; V_58 < 16 ; V_58 ++ ) {
V_57 = V_53 * ( V_58 + 1 ) ;
switch ( V_55 & V_59 ) {
case V_60 :
default:
V_56 = ( * V_54 + V_57 / 2 ) / V_57 ;
break;
case V_61 :
V_56 = ( * V_54 ) / V_57 ;
break;
case V_62 :
V_56 = ( * V_54 ) / V_57 ;
break;
}
if ( V_56 < 65536 ) {
* V_54 = V_56 * V_57 ;
return ( V_58 << 16 ) | ( V_56 ) ;
}
}
V_58 = 15 ;
V_57 = V_53 * ( 1 << V_58 ) ;
V_56 = 65535 ;
* V_54 = V_56 * V_57 ;
return ( V_58 << 16 ) | ( V_56 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_21 * V_22 , struct V_63 * V_3 )
{
const struct V_64 * V_65 = V_2 -> V_66 ;
int V_67 = 0 ;
unsigned int V_68 ;
V_67 |= F_16 ( & V_3 -> V_69 , V_70 ) ;
V_67 |= F_16 ( & V_3 -> V_71 , V_72 ) ;
V_67 |= F_16 ( & V_3 -> V_73 , V_72 ) ;
V_67 |= F_16 ( & V_3 -> V_74 , V_75 ) ;
V_67 |= F_16 ( & V_3 -> V_76 , V_75 ) ;
if ( V_67 )
return 1 ;
V_67 |= F_17 ( & V_3 -> V_77 , 0 ) ;
if ( V_3 -> V_71 == V_72 ) {
V_67 |= F_18 ( & V_3 -> V_78 ,
V_65 -> V_79 ) ;
V_67 |= F_19 ( & V_3 -> V_78 ,
100 * 16 * 65535 ) ;
}
if ( V_3 -> V_73 == V_72 ) {
V_67 |= F_18 ( & V_3 -> V_80 ,
V_65 -> V_79 ) ;
V_67 |= F_19 ( & V_3 -> V_80 ,
50 * 16 * 65535 ) ;
}
V_67 |= F_17 ( & V_3 -> V_81 ,
V_3 -> V_82 ) ;
if ( V_3 -> V_76 == V_75 )
V_67 |= F_19 ( & V_3 -> V_83 , 0x00ffffff ) ;
else
V_67 |= F_17 ( & V_3 -> V_83 , 0 ) ;
if ( V_67 )
return 3 ;
if ( V_3 -> V_71 == V_72 ) {
V_68 = V_3 -> V_78 ;
F_14 ( 100 , & V_68 , V_3 -> V_55 ) ;
V_67 |= F_17 ( & V_3 -> V_78 , V_68 ) ;
}
if ( V_3 -> V_73 == V_72 ) {
V_68 = V_3 -> V_80 ;
F_14 ( 50 , & V_68 , V_3 -> V_55 ) ;
V_67 |= F_17 ( & V_3 -> V_80 , V_68 ) ;
if ( V_3 -> V_71 == V_72 ) {
V_68 = V_3 -> V_80 * V_3 -> V_81 ;
V_67 |= F_18 ( & V_3 ->
V_78 ,
V_68 ) ;
}
}
if ( V_67 )
return 4 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_63 * V_3 = & V_22 -> V_47 -> V_3 ;
int V_4 ;
unsigned int V_15 , V_84 , V_85 ;
unsigned int V_56 ;
unsigned int V_86 ;
for ( V_4 = 0 ; V_4 < V_3 -> V_82 ; V_4 ++ ) {
V_15 = F_21 ( V_3 -> V_87 [ V_4 ] ) ;
V_84 = F_22 ( V_3 -> V_87 [ V_4 ] ) ;
F_2 ( ( V_84 << 6 ) | V_15 , V_2 -> V_6 + V_33 + V_4 ) ;
}
V_85 = F_23 ( V_3 -> V_87 [ 0 ] ) ;
F_2 ( V_3 -> V_81 , V_2 -> V_6 + F_7 ( 0 ) ) ;
if ( V_3 -> V_73 == V_72 ) {
V_56 = F_14 ( 50 , & V_3 -> V_80 , V_3 -> V_55 ) ;
F_2 ( ( V_56 >> 16 ) , V_2 -> V_6 + F_7 ( 1 ) ) ;
F_2 ( ( V_56 & 0xffff ) , V_2 -> V_6 + F_7 ( 2 ) ) ;
}
if ( V_3 -> V_71 == V_72 ) {
V_86 = F_14 ( 100 , & V_3 -> V_78 ,
V_3 -> V_55 ) ;
F_2 ( ( V_86 >> 16 ) , V_2 -> V_6 + F_7 ( 3 ) ) ;
F_2 ( ( V_86 & 0xffff ) , V_2 -> V_6 + F_7 ( 4 ) ) ;
}
F_2 ( V_88 , V_2 -> V_6 + F_7 ( 5 ) ) ;
F_2 ( ( V_85 == V_89 ) ? V_90 : 0 ,
V_2 -> V_6 + F_7 ( 6 ) ) ;
F_2 ( V_31 / 2 , V_2 -> V_6 + F_7 ( 7 ) ) ;
F_2 ( V_35 , V_2 -> V_6 + V_17 ) ;
F_1 ( V_2 , V_91 ) ;
F_2 ( V_44 | V_45 | V_46 ,
V_2 -> V_6 + V_37 ) ;
V_50 = 0 ;
F_2 ( V_35 , V_2 -> V_6 + V_17 ) ;
F_1 ( V_2 , V_92 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_93 * V_94 ,
unsigned int * V_19 )
{
int V_4 ;
unsigned int V_15 , V_16 , V_85 ;
V_15 = F_21 ( V_94 -> V_95 ) ;
V_16 = F_22 ( V_94 -> V_95 ) ;
V_85 = F_23 ( V_94 -> V_95 ) ;
for ( V_4 = 0 ; V_4 < V_94 -> V_96 ; V_4 ++ )
V_19 [ V_4 ] = F_6 ( V_2 , V_35 , V_15 , V_16 ) ;
return V_4 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_93 * V_94 ,
unsigned int * V_19 )
{
unsigned int V_15 = F_21 ( V_94 -> V_95 ) ;
unsigned int V_97 = V_22 -> V_98 [ V_15 ] ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_94 -> V_96 ; V_4 ++ ) {
V_97 = V_19 [ V_4 ] ;
F_8 ( V_2 , V_99 , V_15 , V_97 ) ;
}
V_22 -> V_98 [ V_15 ] = V_97 ;
return V_94 -> V_96 ;
}
static void F_26 ( struct V_1 * V_2 , int V_100 )
{
F_2 ( V_101 , V_2 -> V_6 + V_17 ) ;
F_2 ( V_100 , V_2 -> V_6 + F_7 ( 0 ) ) ;
F_1 ( V_2 , V_91 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_93 * V_94 ,
unsigned int * V_19 )
{
unsigned int V_15 = F_21 ( V_94 -> V_95 ) ;
unsigned int V_102 ;
int V_103 ;
if ( V_15 < 4 )
V_102 = 0x0f ;
else
V_102 = 0xf0 ;
V_103 = F_28 ( V_2 , V_22 , V_94 , V_19 , V_102 ) ;
if ( V_103 )
return V_103 ;
F_26 ( V_2 , ( V_22 -> V_104 & 0x01 ) | ( ( V_22 -> V_104 & 0x10 ) >> 3 ) ) ;
return V_94 -> V_96 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_93 * V_94 ,
unsigned int * V_19 )
{
if ( F_30 ( V_22 , V_19 ) )
F_8 ( V_2 , V_101 , 0 , V_22 -> V_105 ) ;
V_19 [ 1 ] = F_6 ( V_2 , V_106 , 0 , 0 ) ;
return V_94 -> V_96 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_93 * V_94 ,
unsigned int * V_19 )
{
unsigned int V_107 = F_21 ( V_94 -> V_95 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_94 -> V_96 ; V_4 ++ ) {
F_2 ( V_108 , V_2 -> V_6 + V_17 ) ;
F_2 ( V_107 , V_2 -> V_6 + F_7 ( 0 ) ) ;
F_2 ( 1 , V_2 -> V_6 + F_7 ( 1 ) ) ;
F_1 ( V_2 , V_109 ) ;
V_19 [ V_4 ] = F_3 ( V_2 -> V_6 + F_7 ( 2 ) ) ;
}
return V_4 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned long V_110 )
{
struct V_111 * V_112 = F_33 ( V_2 ) ;
const struct V_64 * V_65 = NULL ;
struct V_23 * V_24 ;
struct V_21 * V_22 ;
int V_103 = 0 ;
if ( V_110 < F_34 ( V_113 ) )
V_65 = & V_113 [ V_110 ] ;
if ( ! V_65 )
return - V_114 ;
V_2 -> V_66 = V_65 ;
V_2 -> V_115 = V_65 -> V_116 ;
V_24 = F_35 ( V_2 , sizeof( * V_24 ) ) ;
if ( ! V_24 )
return - V_117 ;
V_103 = F_36 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
V_2 -> V_6 = F_37 ( V_112 , 0 ) ;
if ( ! V_2 -> V_6 )
return - V_117 ;
if ( V_112 -> V_38 ) {
V_103 = F_38 ( V_112 -> V_38 , F_12 , V_118 ,
V_2 -> V_115 , V_2 ) ;
if ( V_103 == 0 )
V_2 -> V_38 = V_112 -> V_38 ;
}
V_103 = F_39 ( V_2 , 4 ) ;
if ( V_103 )
return V_103 ;
V_22 = & V_2 -> V_119 [ 0 ] ;
V_22 -> type = V_120 ;
V_22 -> V_121 = V_122 | V_123 | V_124 ;
V_22 -> V_125 = V_65 -> V_126 ;
V_22 -> V_127 = V_65 -> V_128 ? 0xffff : 0x0fff ;
V_22 -> V_129 = & V_130 ;
V_22 -> V_131 = F_24 ;
if ( V_2 -> V_38 ) {
V_2 -> V_40 = V_22 ;
V_22 -> V_121 |= V_132 ;
V_22 -> V_133 = 512 ;
V_22 -> V_134 = F_20 ;
V_22 -> V_135 = F_15 ;
V_22 -> V_136 = F_11 ;
}
V_22 = & V_2 -> V_119 [ 1 ] ;
if ( V_65 -> V_137 ) {
V_22 -> type = V_138 ;
V_22 -> V_121 = V_139 ;
V_22 -> V_125 = 2 ;
V_22 -> V_127 = 0x0fff ;
V_22 -> V_129 = & V_140 ;
V_22 -> V_141 = F_25 ;
V_103 = F_40 ( V_22 ) ;
if ( V_103 )
return V_103 ;
} else {
V_22 -> type = V_142 ;
}
V_22 = & V_2 -> V_119 [ 2 ] ;
V_22 -> type = V_143 ;
V_22 -> V_121 = V_122 | V_139 ;
V_22 -> V_125 = 8 ;
V_22 -> V_127 = 1 ;
V_22 -> V_129 = & V_144 ;
V_22 -> V_145 = F_27 ;
V_22 -> V_146 = F_29 ;
V_22 = & V_2 -> V_119 [ 3 ] ;
V_22 -> type = V_147 ;
V_22 -> V_121 = V_122 ;
V_22 -> V_125 = 0x1000 ;
V_22 -> V_127 = 0xff ;
V_22 -> V_129 = & V_148 ;
V_22 -> V_131 = F_31 ;
return 0 ;
}
static int F_41 ( struct V_111 * V_2 ,
const struct V_149 * V_150 )
{
return F_42 ( V_2 , & V_151 , V_150 -> V_152 ) ;
}
