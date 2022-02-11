static const struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
if ( V_5 [ V_3 ] . V_2 == V_2 )
return V_5 + V_3 ;
return NULL ;
}
static struct V_6 * F_2 ( unsigned int V_7 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ )
if ( V_9 [ V_3 ] . V_7 == V_7 )
return V_9 + V_3 ;
return NULL ;
}
static int F_3 ( struct V_10 * V_11 , struct V_12 * V_13 , unsigned int V_14 )
{
if ( V_13 -> V_15 & V_14 )
return 1 ;
F_4 ( & V_11 -> V_16 ) ;
if ( V_11 -> V_15 & V_14 ) {
F_5 ( & V_11 -> V_16 ) ;
return 0 ;
}
V_13 -> V_15 |= V_14 ;
V_11 -> V_15 |= V_14 ;
F_6 ( L_1 , V_14 ) ;
F_5 ( & V_11 -> V_16 ) ;
return 1 ;
}
static int F_7 ( struct V_12 * V_13 , unsigned int V_14 )
{
return ( V_13 -> V_15 & V_14 ) ;
}
static int F_8 ( struct V_10 * V_11 , unsigned int V_14 )
{
return ( V_11 -> V_15 & V_14 ) ;
}
static
void F_9 ( struct V_10 * V_11 , struct V_12 * V_13 , unsigned int V_17 )
{
F_10 ( ( V_13 -> V_15 & V_17 ) != V_17 ) ;
F_4 ( & V_11 -> V_16 ) ;
V_13 -> V_15 &= ~ V_17 ;
V_11 -> V_15 &= ~ V_17 ;
F_6 ( L_2 , V_17 ) ;
F_5 ( & V_11 -> V_16 ) ;
}
static void F_11 ( struct V_10 * V_11 , struct V_18 * V_19 )
{
F_6 ( L_3 , V_19 -> V_20 ) ;
V_11 -> V_21 = V_19 ;
V_11 -> V_22 . V_23 = V_19 -> V_24 ;
V_11 -> V_25 . V_23 = V_19 -> V_24 ;
V_11 -> V_22 . V_26 = V_19 -> V_27 - V_19 -> V_24 + 1 ;
V_11 -> V_25 . V_26 = V_19 -> V_27 - V_19 -> V_24 + 1 ;
V_11 -> V_22 . V_28 = ( V_19 -> V_29 + 1 ) * 2 ;
V_11 -> V_25 . V_28 = V_19 -> V_30 * 2 ;
V_11 -> V_22 . V_31 = ( ( V_19 -> V_2 & V_32 ) ? 524 : 624 )
- V_11 -> V_22 . V_28 ;
V_11 -> V_25 . V_31 = ( V_19 -> V_33 - V_19 -> V_30 + 1 ) * 2 ;
V_11 -> V_34 = V_11 -> V_25 ;
F_12 ( V_11 ) ;
}
static void F_13 ( struct V_10 * V_11 , int V_35 )
{
F_6 ( L_4 , V_35 , F_14 ( V_11 , V_35 ) . V_20 ) ;
V_11 -> V_36 = V_35 ;
F_11 ( V_11 , V_11 -> V_21 ) ;
F_15 ( V_11 , & F_14 ( V_11 , V_35 ) ) ;
}
static void F_16 ( struct V_10 * V_11 )
{
int V_37 , V_38 , V_39 ;
struct V_18 * V_19 = V_11 -> V_21 ;
V_39 = F_14 ( V_11 , V_11 -> V_36 ) . V_40 ;
V_37 = V_19 -> V_37 ;
V_38 = V_19 -> V_38 ;
if ( V_39 > 5 )
V_37 |= 0x80 ;
if ( V_41 || V_11 -> V_42 )
V_38 |= 0x20 ;
F_17 ( V_43 , 0x08 ) ;
F_17 ( V_44 , 0xc0 | V_39 ) ;
F_17 ( V_45 , 0x00 ) ;
F_17 ( V_46 , 0x90 ) ;
F_17 ( V_47 , 0x90 ) ;
F_17 ( V_48 , 0xeb ) ;
F_17 ( V_49 , 0xe0 ) ;
F_17 ( V_50 , V_19 -> V_51 ) ;
F_17 ( V_52 , V_38 ) ;
F_17 ( V_53 , V_37 ) ;
F_17 ( V_54 , V_11 -> V_55 ) ;
F_17 ( V_56 ,
V_11 -> V_57 ? - V_11 -> V_58 : V_11 -> V_58 ) ;
F_17 ( V_59 ,
V_11 -> V_57 ? - V_11 -> V_60 : V_11 -> V_60 ) ;
F_17 ( V_61 , V_11 -> V_62 ) ;
F_17 ( V_63 , V_19 -> V_64 ) ;
F_17 ( V_65 , V_19 -> V_66 ) ;
F_17 ( V_67 , V_19 -> V_68 ) ;
F_17 ( V_69 , 0x00 ) ;
F_17 ( V_70 , 0x01 ) ;
F_17 ( V_71 , 0x11 ) ;
F_17 ( V_72 , 0xfe ) ;
F_17 ( V_73 , V_19 -> V_74 ) ;
F_17 ( V_75 , 0x40 ) ;
F_17 ( V_76 , 0x80 ) ;
}
void F_12 ( struct V_10 * V_11 )
{
F_16 ( V_11 ) ;
if ( F_14 ( V_11 , V_11 -> V_36 ) . V_77 )
F_18 ( V_11 , V_78 , V_79 , V_11 -> V_21 -> V_2 ) ;
F_19 ( V_11 , V_78 , V_79 , V_11 -> V_21 -> V_2 ) ;
}
static void F_20 ( struct V_10 * V_11 , int V_80 , int V_81 )
{
static const struct {
int V_82 ;
int V_83 ;
int V_84 ;
int V_85 ;
int V_86 ;
} V_87 [] = {
{ 1 , 0 , 0 , 0 , 0 } ,
{ 2 , 2 , 1 , 2 , 2 } ,
{ 3 , 4 , 1 , 3 , 2 } ,
{ 4 , 8 , 1 , 4 , 2 } ,
{ 5 , 8 , 1 , 4 , 2 } ,
{ 6 , 8 , 1 , 4 , 3 } ,
{ 7 , 8 , 1 , 4 , 3 } ,
{ 8 , 15 , 0 , 4 , 3 } ,
{ 9 , 15 , 0 , 4 , 3 } ,
{ 10 , 16 , 1 , 5 , 3 } ,
} ;
static const int V_88 = F_21 ( V_87 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_88 ; V_3 ++ )
if ( V_87 [ V_3 ] . V_82 == V_81 )
break;
if ( V_3 == V_88 )
return;
F_17 ( F_22 ( V_80 ) , V_87 [ V_3 ] . V_82 ) ;
F_17 ( F_23 ( V_80 ) , V_87 [ V_3 ] . V_83 ) ;
F_17 ( F_24 ( V_80 ) ,
( V_87 [ V_3 ] . V_84 << 3 ) | ( V_87 [ V_3 ] . V_85 ) ) ;
F_25 ( F_26 ( V_80 ) , 0x0f ,
( V_87 [ V_3 ] . V_86 << 2 ) | V_87 [ V_3 ] . V_86 ) ;
}
static void F_27 ( struct V_10 * V_11 , int V_80 , int V_89 )
{
int V_90 , V_91 ;
F_17 ( F_28 ( V_80 ) , V_89 & 0xff ) ;
F_17 ( F_29 ( V_80 ) , V_89 >> 8 ) ;
V_91 = ( V_11 -> V_92 ) ? 0x02 : 0x00 ;
if ( V_89 < 2048 ) {
F_6 ( L_5 , V_89 ) ;
F_17 ( F_30 ( V_80 ) , 0x00 | V_91 ) ;
F_17 ( F_31 ( V_80 ) , 0x40 ) ;
F_17 ( F_32 ( V_80 ) , 0x40 ) ;
} else {
V_90 = 0x40 * 1024 / V_89 ;
F_6 ( L_6 , V_89 , V_90 ) ;
F_17 ( F_30 ( V_80 ) , 0x01 | V_91 ) ;
F_17 ( F_31 ( V_80 ) , V_90 ) ;
F_17 ( F_32 ( V_80 ) , V_90 ) ;
}
F_17 ( F_33 ( V_80 ) , 0x80 ) ;
}
static void F_34 ( struct V_10 * V_11 , int V_80 ,
int V_26 , int V_31 , int V_93 )
{
int V_81 , V_94 , V_89 , V_95 , V_96 ;
int V_24 , V_27 , V_97 , V_98 ;
int div = V_93 ? 2 : 1 ;
V_24 = V_11 -> V_34 . V_23 ;
V_97 = V_11 -> V_34 . V_28 / 2 ;
V_27 = ( V_11 -> V_34 . V_23 + V_11 -> V_34 . V_26 - 1 ) ;
V_98 = ( V_11 -> V_34 . V_28 + V_11 -> V_34 . V_31 - 1 ) / 2 ;
F_17 ( F_35 ( V_80 ) , V_24 & 0xff ) ;
F_17 ( F_36 ( V_80 ) , V_24 >> 8 ) ;
F_17 ( F_37 ( V_80 ) , V_27 & 0xff ) ;
F_17 ( F_38 ( V_80 ) , V_27 >> 8 ) ;
F_17 ( F_39 ( V_80 ) , V_97 & 0xff ) ;
F_17 ( F_40 ( V_80 ) , V_97 >> 8 ) ;
F_17 ( F_41 ( V_80 ) , V_98 & 0xff ) ;
F_17 ( F_42 ( V_80 ) , V_98 >> 8 ) ;
V_81 = V_11 -> V_34 . V_26 / V_26 ;
if ( 0 == V_81 )
V_81 = 1 ;
V_94 = 1024 * V_11 -> V_34 . V_26 / V_81 / V_26 ;
V_89 = 512 * div * V_11 -> V_34 . V_31 / V_31 ;
F_6 ( L_7 , V_81 , V_94 , V_89 ) ;
F_20 ( V_11 , V_80 , V_81 ) ;
F_17 ( F_43 ( V_80 ) , V_94 & 0xff ) ;
F_17 ( F_44 ( V_80 ) , V_94 >> 8 ) ;
F_27 ( V_11 , V_80 , V_89 ) ;
F_17 ( F_45 ( V_80 ) , V_26 & 0xff ) ;
F_17 ( F_46 ( V_80 ) , V_26 >> 8 ) ;
F_17 ( F_47 ( V_80 ) , V_31 / div & 0xff ) ;
F_17 ( F_48 ( V_80 ) , V_31 / div >> 8 ) ;
V_96 = V_11 -> V_99 ;
V_95 = V_11 -> V_100 ;
F_17 ( F_49 ( V_80 ) , V_96 ) ;
F_17 ( F_50 ( V_80 ) , V_95 ) ;
F_17 ( F_51 ( V_80 ) , V_96 ) ;
F_17 ( F_52 ( V_80 ) , V_95 ) ;
}
static void F_53 ( struct V_10 * V_11 , int V_101 ,
struct V_102 * V_103 , int V_104 , char * V_20 )
{
T_1 V_105 = 0 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_104 ; V_3 ++ ) {
V_105 |= V_103 [ V_3 ] . V_106 ;
V_105 &= ~ V_103 [ V_3 ] . V_107 ;
if ( V_3 < 15 && V_103 [ V_3 ] . V_108 == V_103 [ V_3 + 1 ] . V_108 )
continue;
F_17 ( V_101 + 0 , V_105 ) ;
F_17 ( V_101 + 2 , V_103 [ V_3 ] . V_108 & 0xff ) ;
F_17 ( V_101 + 3 , V_103 [ V_3 ] . V_108 >> 8 ) ;
F_6 ( L_8 ,
V_20 , V_105 , V_103 [ V_3 ] . V_108 ) ;
V_101 += 8 ;
}
for (; V_101 < 0x400 ; V_101 += 8 ) {
F_17 ( V_101 + 0 , 0 ) ;
F_17 ( V_101 + 1 , 0 ) ;
F_17 ( V_101 + 2 , 0 ) ;
F_17 ( V_101 + 3 , 0 ) ;
}
}
static int F_54 ( int V_90 )
{
if ( V_90 < 0 )
V_90 = 0 ;
return V_90 ;
}
static int F_55 ( const void * V_109 , const void * V_110 )
{
const struct V_102 * V_111 = V_109 ;
const struct V_102 * V_112 = V_110 ;
if ( V_111 -> V_108 < V_112 -> V_108 )
return - 1 ;
if ( V_111 -> V_108 > V_112 -> V_108 )
return 1 ;
return 0 ;
}
static int F_56 ( struct V_10 * V_11 , struct V_113 * V_114 ,
int V_115 , int V_93 )
{
struct V_102 V_116 [ 16 ] , V_117 [ 16 ] ;
int V_118 = 0 , V_119 = 0 , V_3 ;
int div = V_93 ? 2 : 1 ;
memset ( V_116 , 0 , sizeof( V_116 ) ) ;
memset ( V_117 , 0 , sizeof( V_117 ) ) ;
for ( V_3 = 0 ; V_3 < V_115 && V_3 < 8 ; V_3 ++ ) {
V_116 [ V_118 ] . V_108 = F_54 ( V_114 [ V_3 ] . V_120 . V_23 ) ;
V_116 [ V_118 ] . V_106 = ( 1 << V_3 ) ;
V_118 ++ ;
V_116 [ V_118 ] . V_108 = F_54 ( V_114 [ V_3 ] . V_120 . V_23 + V_114 [ V_3 ] . V_120 . V_26 ) ;
V_116 [ V_118 ] . V_107 = ( 1 << V_3 ) ;
V_118 ++ ;
V_117 [ V_119 ] . V_108 = F_54 ( V_114 [ V_3 ] . V_120 . V_28 / div ) ;
V_117 [ V_119 ] . V_106 = ( 1 << V_3 ) ;
V_119 ++ ;
V_117 [ V_119 ] . V_108 = F_54 ( ( V_114 [ V_3 ] . V_120 . V_28 + V_114 [ V_3 ] . V_120 . V_31 )
/ div ) ;
V_117 [ V_119 ] . V_107 = ( 1 << V_3 ) ;
V_119 ++ ;
}
F_57 ( V_116 , V_118 , sizeof V_116 [ 0 ] , F_55 , NULL ) ;
F_57 ( V_117 , V_119 , sizeof V_117 [ 0 ] , F_55 , NULL ) ;
F_53 ( V_11 , 0x380 , V_116 , V_118 , L_9 ) ;
F_53 ( V_11 , 0x384 , V_117 , V_119 , L_10 ) ;
return 0 ;
}
static int F_58 ( struct V_10 * V_11 , struct V_121 * V_122 )
{
enum V_123 V_124 ;
int V_125 , V_126 ;
if ( NULL == V_11 -> V_127 . V_128 )
return - V_129 ;
if ( NULL == V_11 -> V_130 )
return - V_129 ;
if ( V_122 -> V_131 . V_26 < 48 || V_122 -> V_131 . V_31 < 32 )
return - V_129 ;
if ( V_122 -> V_132 > 2048 )
return - V_129 ;
V_124 = V_122 -> V_124 ;
V_125 = V_11 -> V_34 . V_26 ;
V_126 = V_11 -> V_34 . V_31 ;
if ( V_133 == V_124 ) {
V_124 = ( V_122 -> V_131 . V_31 > V_126 / 2 )
? V_134
: V_135 ;
}
switch ( V_124 ) {
case V_135 :
case V_136 :
V_126 = V_126 / 2 ;
break;
case V_134 :
break;
default:
return - V_129 ;
}
V_122 -> V_124 = V_124 ;
if ( V_122 -> V_131 . V_26 > V_125 )
V_122 -> V_131 . V_26 = V_125 ;
if ( V_122 -> V_131 . V_31 > V_126 )
V_122 -> V_131 . V_31 = V_126 ;
return 0 ;
}
static int F_59 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
unsigned long V_128 , V_137 , V_138 ;
int V_139 ;
V_139 = F_58 ( V_11 , & V_13 -> V_122 ) ;
if ( 0 != V_139 )
return V_139 ;
V_11 -> V_140 = V_13 -> V_122 . V_124 ;
F_6 ( L_11 ,
V_13 -> V_122 . V_131 . V_26 , V_13 -> V_122 . V_131 . V_31 ,
V_13 -> V_122 . V_131 . V_23 , V_13 -> V_122 . V_131 . V_28 ,
V_11 -> V_130 -> V_20 , V_141 [ V_11 -> V_140 ] ) ;
F_34 ( V_11 , V_142 , V_13 -> V_122 . V_131 . V_26 , V_13 -> V_122 . V_131 . V_31 ,
F_60 ( V_11 -> V_140 ) ) ;
F_56 ( V_11 , V_13 -> V_114 , V_13 -> V_115 ,
F_60 ( V_11 -> V_140 ) ) ;
if ( V_11 -> V_130 -> V_143 )
F_25 ( F_61 ( V_142 ) , 0x3f , 0x03 ) ;
else
F_25 ( F_61 ( V_142 ) , 0x3f , 0x01 ) ;
F_17 ( V_144 , V_11 -> V_130 -> V_145 | 0x20 ) ;
V_128 = ( unsigned long ) V_11 -> V_127 . V_128 ;
V_128 += V_11 -> V_127 . V_146 . V_147 * V_13 -> V_122 . V_131 . V_28 ;
V_128 += V_11 -> V_130 -> V_148 / 8 * V_13 -> V_122 . V_131 . V_23 ;
V_138 = V_11 -> V_127 . V_146 . V_147 ;
V_137 = V_149 ;
if ( V_11 -> V_130 -> V_150 )
V_137 |= V_151 ;
if ( V_11 -> V_130 -> V_152 )
V_137 |= V_153 ;
if ( F_60 ( V_11 -> V_140 ) ) {
F_62 ( F_63 ( 1 ) , V_128 ) ;
F_62 ( F_64 ( 1 ) , V_128 + V_138 ) ;
F_62 ( F_65 ( 1 ) , V_138 * 2 ) ;
F_62 ( F_66 ( 1 ) , V_137 ) ;
} else {
F_62 ( F_63 ( 1 ) , V_128 ) ;
F_62 ( F_64 ( 1 ) , V_128 ) ;
F_62 ( F_65 ( 1 ) , V_138 ) ;
F_62 ( F_66 ( 1 ) , V_137 ) ;
}
V_11 -> V_154 = 1 ;
F_67 ( V_11 ) ;
return 0 ;
}
static int F_68 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
V_11 -> V_154 = 0 ;
F_67 ( V_11 ) ;
return 0 ;
}
static int F_69 ( struct V_10 * V_11 ,
struct V_155 * V_156 ,
struct V_155 * V_157 )
{
unsigned long V_128 , V_137 , V_138 ;
unsigned long V_158 , V_159 , V_160 , V_161 , V_162 ;
F_6 ( L_12 , V_156 ) ;
V_156 -> V_163 . V_164 = V_165 ;
V_156 -> V_166 = 0 ;
F_34 ( V_11 , V_167 , V_156 -> V_163 . V_26 , V_156 -> V_163 . V_31 ,
F_60 ( V_156 -> V_163 . V_124 ) ) ;
if ( V_156 -> V_146 -> V_143 )
F_25 ( F_61 ( V_167 ) , 0x3f , 0x03 ) ;
else
F_25 ( F_61 ( V_167 ) , 0x3f , 0x01 ) ;
F_17 ( V_168 , V_156 -> V_146 -> V_145 ) ;
V_128 = F_70 ( V_156 ) ;
if ( V_156 -> V_146 -> V_169 )
V_138 = V_156 -> V_163 . V_26 ;
else
V_138 = ( V_156 -> V_163 . V_26 * V_156 -> V_146 -> V_148 ) / 8 ;
V_137 = V_149 |
V_170 |
( V_156 -> V_171 -> V_172 >> 12 ) ;
if ( V_156 -> V_146 -> V_150 )
V_137 |= V_151 ;
if ( V_156 -> V_146 -> V_152 )
V_137 |= V_153 ;
if ( F_60 ( V_156 -> V_163 . V_124 ) ) {
F_62 ( F_63 ( 0 ) , V_128 ) ;
F_62 ( F_64 ( 0 ) , V_128 + V_138 ) ;
F_62 ( F_65 ( 0 ) , V_138 * 2 ) ;
} else {
F_62 ( F_63 ( 0 ) , V_128 ) ;
F_62 ( F_64 ( 0 ) , V_128 ) ;
F_62 ( F_65 ( 0 ) , V_138 ) ;
}
F_62 ( F_66 ( 0 ) , V_137 ) ;
if ( V_156 -> V_146 -> V_169 ) {
V_158 = V_138 >> V_156 -> V_146 -> V_173 ;
V_159 = V_156 -> V_163 . V_31 >> V_156 -> V_146 -> V_174 ;
V_160 = V_128 + V_138 * V_156 -> V_163 . V_31 ;
V_161 = V_160 + V_158 * V_159 ;
if ( V_156 -> V_146 -> V_175 )
V_162 = V_160 , V_160 = V_161 , V_161 = V_162 ;
F_6 ( L_13 ,
V_158 , V_159 , V_160 , V_161 ) ;
if ( F_60 ( V_156 -> V_163 . V_124 ) ) {
F_62 ( F_63 ( 4 ) , V_160 ) ;
F_62 ( F_64 ( 4 ) , V_160 + V_158 ) ;
F_62 ( F_65 ( 4 ) , V_158 * 2 ) ;
F_62 ( F_63 ( 5 ) , V_161 ) ;
F_62 ( F_64 ( 5 ) , V_161 + V_158 ) ;
F_62 ( F_65 ( 5 ) , V_158 * 2 ) ;
} else {
F_62 ( F_63 ( 4 ) , V_160 ) ;
F_62 ( F_64 ( 4 ) , V_160 ) ;
F_62 ( F_65 ( 4 ) , V_158 ) ;
F_62 ( F_63 ( 5 ) , V_161 ) ;
F_62 ( F_64 ( 5 ) , V_161 ) ;
F_62 ( F_65 ( 5 ) , V_158 ) ;
}
F_62 ( F_66 ( 4 ) , V_137 ) ;
F_62 ( F_66 ( 5 ) , V_137 ) ;
}
F_67 ( V_11 ) ;
F_71 ( & V_11 -> V_176 . V_177 , V_178 + V_179 ) ;
return 0 ;
}
static int F_72 ( struct V_180 * V_181 ,
struct V_182 * V_163 ,
enum V_123 V_124 )
{
struct V_12 * V_13 = V_181 -> V_183 ;
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_155 * V_156 = F_73 ( V_163 , struct V_155 , V_163 ) ;
unsigned int V_184 ;
int V_139 ;
if ( NULL == V_13 -> V_146 )
return - V_129 ;
if ( V_13 -> V_26 < 48 ||
V_13 -> V_31 < 32 ||
V_13 -> V_26 / 4 > V_11 -> V_34 . V_26 ||
V_13 -> V_31 / 4 > V_11 -> V_34 . V_31 ||
V_13 -> V_26 > V_11 -> V_22 . V_26 ||
V_13 -> V_31 > V_11 -> V_22 . V_31 )
return - V_129 ;
V_184 = ( V_13 -> V_26 * V_13 -> V_31 * V_13 -> V_146 -> V_148 ) >> 3 ;
if ( 0 != V_156 -> V_163 . V_185 && V_156 -> V_163 . V_186 < V_184 )
return - V_129 ;
F_6 ( L_14 ,
V_163 -> V_3 , V_13 -> V_26 , V_13 -> V_31 , V_184 , V_141 [ V_124 ] ,
V_13 -> V_146 -> V_20 ) ;
if ( V_156 -> V_163 . V_26 != V_13 -> V_26 ||
V_156 -> V_163 . V_31 != V_13 -> V_31 ||
V_156 -> V_163 . V_184 != V_184 ||
V_156 -> V_163 . V_124 != V_124 ||
V_156 -> V_146 != V_13 -> V_146 ) {
F_74 ( V_181 , V_156 ) ;
}
if ( V_187 == V_156 -> V_163 . V_164 ) {
struct V_188 * V_172 = F_75 ( & V_156 -> V_163 ) ;
V_156 -> V_163 . V_26 = V_13 -> V_26 ;
V_156 -> V_163 . V_31 = V_13 -> V_31 ;
V_156 -> V_163 . V_184 = V_184 ;
V_156 -> V_163 . V_124 = V_124 ;
V_156 -> V_146 = V_13 -> V_146 ;
V_156 -> V_171 = & V_13 -> V_189 ;
V_11 -> V_176 . V_190 = NULL ;
V_139 = F_76 ( V_181 , & V_156 -> V_163 , & V_11 -> V_127 ) ;
if ( V_139 )
goto V_191;
V_139 = F_77 ( V_11 -> V_192 , V_156 -> V_171 ,
V_172 -> V_193 ,
V_172 -> V_194 ,
F_78 ( V_156 ) ) ;
if ( V_139 )
goto V_191;
}
V_156 -> V_163 . V_164 = V_195 ;
V_156 -> V_196 = F_69 ;
return 0 ;
V_191:
F_74 ( V_181 , V_156 ) ;
return V_139 ;
}
static int
F_79 ( struct V_180 * V_181 , unsigned int * V_88 , unsigned int * V_184 )
{
struct V_12 * V_13 = V_181 -> V_183 ;
* V_184 = V_13 -> V_146 -> V_148 * V_13 -> V_26 * V_13 -> V_31 >> 3 ;
if ( 0 == * V_88 )
* V_88 = V_197 ;
* V_88 = F_80 ( * V_184 , * V_88 ) ;
return 0 ;
}
static void F_81 ( struct V_180 * V_181 , struct V_182 * V_163 )
{
struct V_12 * V_13 = V_181 -> V_183 ;
struct V_155 * V_156 = F_73 ( V_163 , struct V_155 , V_163 ) ;
F_82 ( V_13 -> V_11 , & V_13 -> V_11 -> V_176 , V_156 ) ;
}
static void F_83 ( struct V_180 * V_181 , struct V_182 * V_163 )
{
struct V_155 * V_156 = F_73 ( V_163 , struct V_155 , V_163 ) ;
F_74 ( V_181 , V_156 ) ;
}
int F_84 ( struct V_10 * V_11 , struct V_12 * V_13 , struct V_198 * V_120 )
{
const struct V_1 * V_199 ;
V_199 = F_1 ( V_120 -> V_2 ) ;
if ( NULL == V_199 )
return - V_129 ;
switch ( V_120 -> V_2 ) {
case V_200 :
V_120 -> V_201 = V_11 -> V_55 ;
break;
case V_202 :
V_120 -> V_201 = V_11 -> V_62 ;
break;
case V_203 :
V_120 -> V_201 = V_11 -> V_58 ;
break;
case V_204 :
V_120 -> V_201 = V_11 -> V_60 ;
break;
case V_205 :
V_120 -> V_201 = V_11 -> V_206 ;
break;
case V_207 :
V_120 -> V_201 = V_11 -> V_208 ;
break;
case V_209 :
V_120 -> V_201 = V_11 -> V_57 ;
break;
case V_210 :
V_120 -> V_201 = V_11 -> V_92 ;
break;
case V_211 :
V_120 -> V_201 = V_11 -> V_100 ;
break;
case V_212 :
V_120 -> V_201 = V_11 -> V_99 ;
break;
case V_213 :
V_120 -> V_201 = V_11 -> V_214 ;
break;
default:
return - V_129 ;
}
return 0 ;
}
static int F_85 ( struct V_215 * V_215 , void * V_216 , struct V_198 * V_120 )
{
struct V_12 * V_13 = V_216 ;
return F_84 ( V_13 -> V_11 , V_13 , V_120 ) ;
}
int F_86 ( struct V_10 * V_11 , struct V_12 * V_13 , struct V_198 * V_120 )
{
const struct V_1 * V_199 ;
unsigned long V_217 ;
int V_218 = 0 ;
int V_139 ;
if ( V_13 ) {
V_139 = F_87 ( & V_11 -> V_219 , V_13 -> V_219 ) ;
if ( 0 != V_139 )
return V_139 ;
}
V_139 = - V_129 ;
F_4 ( & V_11 -> V_16 ) ;
V_199 = F_1 ( V_120 -> V_2 ) ;
if ( NULL == V_199 )
goto error;
F_6 ( L_15 , V_199 -> V_20 , V_120 -> V_201 ) ;
switch ( V_199 -> type ) {
case V_220 :
case V_221 :
case V_222 :
if ( V_120 -> V_201 < V_199 -> V_223 )
V_120 -> V_201 = V_199 -> V_223 ;
if ( V_120 -> V_201 > V_199 -> V_224 )
V_120 -> V_201 = V_199 -> V_224 ;
break;
default:
;
}
switch ( V_120 -> V_2 ) {
case V_200 :
V_11 -> V_55 = V_120 -> V_201 ;
F_17 ( V_54 , V_11 -> V_55 ) ;
break;
case V_202 :
V_11 -> V_62 = V_120 -> V_201 ;
F_17 ( V_61 , V_11 -> V_62 ) ;
break;
case V_203 :
V_11 -> V_58 = V_120 -> V_201 ;
F_17 ( V_56 ,
V_11 -> V_57 ? - V_11 -> V_58 : V_11 -> V_58 ) ;
break;
case V_204 :
V_11 -> V_60 = V_120 -> V_201 ;
F_17 ( V_59 ,
V_11 -> V_57 ? - V_11 -> V_60 : V_11 -> V_60 ) ;
break;
case V_205 :
V_11 -> V_206 = V_120 -> V_201 ;
F_88 ( V_11 ) ;
break;
case V_207 :
V_11 -> V_208 = V_120 -> V_201 ;
F_89 ( V_11 , V_11 -> V_208 ) ;
break;
case V_209 :
V_11 -> V_57 = V_120 -> V_201 ;
F_17 ( V_56 ,
V_11 -> V_57 ? - V_11 -> V_58 : V_11 -> V_58 ) ;
F_17 ( V_59 ,
V_11 -> V_57 ? - V_11 -> V_60 : V_11 -> V_60 ) ;
break;
case V_210 :
V_11 -> V_92 = V_120 -> V_201 ;
V_218 = 1 ;
break;
case V_211 :
V_11 -> V_100 = V_120 -> V_201 ;
V_218 = 1 ;
break;
case V_212 :
V_11 -> V_99 = V_120 -> V_201 ;
V_218 = 1 ;
break;
case V_213 :
{
struct V_225 V_226 ;
V_226 . V_227 = V_228 ;
V_226 . V_216 = & V_11 -> V_229 ;
V_11 -> V_214 = V_120 -> V_201 ;
if ( V_11 -> V_229 ) {
if ( V_11 -> V_214 )
V_11 -> V_229 |= V_230 ;
else
V_11 -> V_229 &= ~ V_230 ;
F_18 ( V_11 , V_227 , V_231 , & V_226 ) ;
}
break;
}
default:
goto error;
}
if ( V_218 && V_13 && F_7 ( V_13 , V_232 ) ) {
F_90 ( & V_11 -> V_233 , V_217 ) ;
F_68 ( V_11 , V_13 ) ;
F_59 ( V_11 , V_13 ) ;
F_91 ( & V_11 -> V_233 , V_217 ) ;
}
V_139 = 0 ;
error:
F_5 ( & V_11 -> V_16 ) ;
return V_139 ;
}
static int F_92 ( struct V_215 * V_215 , void * V_234 , struct V_198 * V_120 )
{
struct V_12 * V_13 = V_234 ;
return F_86 ( V_13 -> V_11 , V_13 , V_120 ) ;
}
static struct V_180 * F_93 ( struct V_12 * V_13 )
{
struct V_180 * V_181 = NULL ;
switch ( V_13 -> type ) {
case V_235 :
V_181 = & V_13 -> V_236 ;
break;
case V_237 :
V_181 = & V_13 -> V_238 ;
break;
default:
F_94 () ;
}
return V_181 ;
}
static int F_95 ( struct V_12 * V_13 )
{
if ( V_13 -> type == V_235 )
return V_239 ;
if ( V_13 -> type == V_237 )
return V_240 ;
F_94 () ;
return 0 ;
}
static int F_96 ( struct V_215 * V_215 )
{
struct V_241 * V_242 = F_97 ( V_215 ) ;
struct V_10 * V_11 = F_98 ( V_215 ) ;
struct V_12 * V_13 ;
enum V_243 type = 0 ;
int V_244 = 0 ;
switch ( V_242 -> V_245 ) {
case V_246 :
type = V_235 ;
break;
case V_247 :
type = V_237 ;
break;
case V_248 :
V_244 = 1 ;
break;
}
F_6 ( L_16 , F_99 ( V_242 ) ,
V_244 , V_249 [ type ] ) ;
V_13 = F_100 ( sizeof( * V_13 ) , V_250 ) ;
if ( NULL == V_13 )
return - V_251 ;
V_215 -> V_252 = V_13 ;
V_13 -> V_11 = V_11 ;
V_13 -> V_244 = V_244 ;
V_13 -> type = type ;
V_13 -> V_146 = F_2 ( V_253 ) ;
V_13 -> V_26 = 720 ;
V_13 -> V_31 = 576 ;
F_101 ( & V_11 -> V_219 , & V_13 -> V_219 ) ;
F_102 ( & V_13 -> V_236 , & V_254 ,
& V_11 -> V_192 -> V_11 , & V_11 -> V_233 ,
V_235 ,
V_134 ,
sizeof( struct V_155 ) ,
V_13 , NULL ) ;
F_102 ( & V_13 -> V_238 , & V_255 ,
& V_11 -> V_192 -> V_11 , & V_11 -> V_233 ,
V_237 ,
V_256 ,
sizeof( struct V_155 ) ,
V_13 , NULL ) ;
F_103 ( V_11 -> V_192 , & V_13 -> V_189 ) ;
F_103 ( V_11 -> V_192 , & V_13 -> V_257 ) ;
if ( V_13 -> V_244 ) {
F_15 ( V_11 , & F_104 ( V_11 ) . V_244 ) ;
F_18 ( V_11 , V_227 , V_258 ) ;
} else {
F_13 ( V_11 , V_11 -> V_36 ) ;
}
return 0 ;
}
static T_2
F_105 ( struct V_215 * V_215 , char T_3 * V_259 , T_4 V_88 , T_5 * V_260 )
{
struct V_12 * V_13 = V_215 -> V_252 ;
switch ( V_13 -> type ) {
case V_235 :
if ( F_8 ( V_13 -> V_11 , V_239 ) )
return - V_261 ;
return F_106 ( F_93 ( V_13 ) ,
V_259 , V_88 , V_260 ,
V_215 -> V_262 & V_263 ) ;
case V_237 :
if ( ! F_3 ( V_13 -> V_11 , V_13 , V_240 ) )
return - V_261 ;
return F_107 ( F_93 ( V_13 ) ,
V_259 , V_88 , V_260 , 1 ,
V_215 -> V_262 & V_263 ) ;
break;
default:
F_94 () ;
return 0 ;
}
}
static unsigned int
F_108 ( struct V_215 * V_215 , struct V_264 * V_265 )
{
struct V_12 * V_13 = V_215 -> V_252 ;
struct V_182 * V_156 = NULL ;
unsigned int V_266 = 0 ;
if ( V_237 == V_13 -> type )
return F_109 ( V_215 , & V_13 -> V_238 , V_265 ) ;
if ( F_7 ( V_13 , V_239 ) ) {
F_4 ( & V_13 -> V_236 . V_267 ) ;
if ( ! F_110 ( & V_13 -> V_236 . V_268 ) )
V_156 = F_111 ( V_13 -> V_236 . V_268 . V_157 , struct V_182 , V_268 ) ;
} else {
F_4 ( & V_13 -> V_236 . V_267 ) ;
if ( V_269 == V_13 -> V_236 . V_270 ) {
if ( F_8 ( V_13 -> V_11 , V_239 ) )
goto V_139;
if ( 0 != V_13 -> V_236 . V_271 -> V_272 ( & V_13 -> V_236 , V_13 -> V_236 . V_273 , V_13 -> V_236 . V_124 ) )
goto V_139;
V_13 -> V_236 . V_271 -> V_274 ( & V_13 -> V_236 , V_13 -> V_236 . V_273 ) ;
V_13 -> V_236 . V_270 = 0 ;
}
V_156 = V_13 -> V_236 . V_273 ;
}
if ( ! V_156 )
goto V_139;
F_112 ( V_215 , & V_156 -> V_275 , V_265 ) ;
if ( V_156 -> V_164 == V_276 ||
V_156 -> V_164 == V_277 )
V_266 = V_278 | V_279 ;
F_5 ( & V_13 -> V_236 . V_267 ) ;
return V_266 ;
V_139:
F_5 ( & V_13 -> V_236 . V_267 ) ;
return V_280 ;
}
static int F_113 ( struct V_215 * V_215 )
{
struct V_12 * V_13 = V_215 -> V_252 ;
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_281 V_282 ;
unsigned long V_217 ;
F_114 ( V_11 ) ;
if ( F_7 ( V_13 , V_232 ) ) {
F_90 ( & V_11 -> V_233 , V_217 ) ;
F_68 ( V_11 , V_13 ) ;
F_91 ( & V_11 -> V_233 , V_217 ) ;
F_9 ( V_11 , V_13 , V_232 ) ;
}
if ( F_7 ( V_13 , V_239 ) ) {
F_115 ( & V_13 -> V_236 ) ;
F_9 ( V_11 , V_13 , V_239 ) ;
}
if ( V_13 -> V_236 . V_273 ) {
F_83 ( & V_13 -> V_236 , V_13 -> V_236 . V_273 ) ;
F_116 ( V_13 -> V_236 . V_273 ) ;
}
if ( F_7 ( V_13 , V_240 ) ) {
F_117 ( & V_13 -> V_238 ) ;
F_9 ( V_11 , V_13 , V_240 ) ;
}
F_25 ( V_168 , 0x1f , 0 ) ;
F_25 ( V_144 , 0x1f , 0 ) ;
F_25 ( V_283 , 0x1f , 0 ) ;
F_25 ( V_284 , 0x1f , 0 ) ;
F_18 ( V_11 , V_78 , V_285 , 0 ) ;
if ( V_13 -> V_244 )
F_18 ( V_11 , V_78 , V_286 , V_287 , & V_282 ) ;
F_118 ( & V_13 -> V_236 ) ;
F_118 ( & V_13 -> V_238 ) ;
F_119 ( V_11 -> V_192 , & V_13 -> V_189 ) ;
F_119 ( V_11 -> V_192 , & V_13 -> V_257 ) ;
F_120 ( & V_11 -> V_219 , V_13 -> V_219 ) ;
V_215 -> V_252 = NULL ;
F_116 ( V_13 ) ;
return 0 ;
}
static int F_121 ( struct V_215 * V_215 , struct V_288 * V_289 )
{
struct V_12 * V_13 = V_215 -> V_252 ;
return F_122 ( F_93 ( V_13 ) , V_289 ) ;
}
static T_2 F_123 ( struct V_215 * V_215 , char T_3 * V_259 ,
T_4 V_88 , T_5 * V_260 )
{
struct V_12 * V_13 = V_215 -> V_252 ;
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_281 V_282 ;
V_282 . V_290 = V_88 / 3 ;
V_282 . V_291 = V_259 ;
V_282 . V_292 = V_215 ;
V_282 . V_293 = - V_294 ;
F_18 ( V_11 , V_78 , V_286 , V_295 , & V_282 ) ;
return V_282 . V_293 ;
}
static unsigned int F_124 ( struct V_215 * V_215 , T_6 * V_265 )
{
struct V_12 * V_13 = V_215 -> V_252 ;
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_281 V_282 ;
V_282 . V_292 = V_215 ;
V_282 . V_296 = V_265 ;
V_282 . V_293 = - V_294 ;
F_18 ( V_11 , V_78 , V_286 , V_297 , & V_282 ) ;
return V_282 . V_293 ;
}
static int F_125 ( struct V_215 * V_215 , void * V_216 ,
struct V_298 * V_234 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_18 * V_19 = V_11 -> V_21 ;
V_234 -> V_146 . V_238 . V_299 = 6750000 * 4 ;
V_234 -> V_146 . V_238 . V_300 = 2048 ;
V_234 -> V_146 . V_238 . V_301 = V_302 ;
V_234 -> V_146 . V_238 . V_303 = 64 * 4 ;
V_234 -> V_146 . V_238 . V_304 [ 0 ] = V_19 -> V_305 ;
V_234 -> V_146 . V_238 . V_88 [ 0 ] = V_19 -> V_29 - V_19 -> V_305 + 1 ;
V_234 -> V_146 . V_238 . V_304 [ 1 ] = V_19 -> V_306 ;
V_234 -> V_146 . V_238 . V_88 [ 1 ] = V_234 -> V_146 . V_238 . V_88 [ 0 ] ;
V_234 -> V_146 . V_238 . V_217 = 0 ;
return 0 ;
}
static int F_126 ( struct V_215 * V_215 , void * V_216 ,
struct V_298 * V_234 )
{
struct V_12 * V_13 = V_216 ;
V_234 -> V_146 . V_307 . V_26 = V_13 -> V_26 ;
V_234 -> V_146 . V_307 . V_31 = V_13 -> V_31 ;
V_234 -> V_146 . V_307 . V_124 = V_13 -> V_236 . V_124 ;
V_234 -> V_146 . V_307 . V_308 = V_13 -> V_146 -> V_7 ;
V_234 -> V_146 . V_307 . V_147 =
( V_234 -> V_146 . V_307 . V_26 * V_13 -> V_146 -> V_148 ) >> 3 ;
V_234 -> V_146 . V_307 . V_309 =
V_234 -> V_146 . V_307 . V_31 * V_234 -> V_146 . V_307 . V_147 ;
return 0 ;
}
static int F_127 ( struct V_215 * V_215 , void * V_216 ,
struct V_298 * V_234 )
{
struct V_12 * V_13 = V_216 ;
if ( V_310 > 0 ) {
F_128 ( V_311 L_17 ) ;
return - V_129 ;
}
V_234 -> V_146 . V_122 = V_13 -> V_122 ;
return 0 ;
}
static int F_129 ( struct V_215 * V_215 , void * V_216 ,
struct V_298 * V_234 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_6 * V_146 ;
enum V_123 V_124 ;
unsigned int V_125 , V_126 ;
V_146 = F_2 ( V_234 -> V_146 . V_307 . V_308 ) ;
if ( NULL == V_146 )
return - V_129 ;
V_124 = V_234 -> V_146 . V_307 . V_124 ;
V_125 = F_130 ( V_11 -> V_34 . V_26 * 4 , V_11 -> V_22 . V_26 ) ;
V_126 = F_130 ( V_11 -> V_34 . V_31 * 4 , V_11 -> V_22 . V_31 ) ;
if ( V_133 == V_124 ) {
V_124 = ( V_234 -> V_146 . V_307 . V_31 > V_126 / 2 )
? V_134
: V_136 ;
}
switch ( V_124 ) {
case V_135 :
case V_136 :
V_126 = V_126 / 2 ;
break;
case V_134 :
break;
default:
return - V_129 ;
}
V_234 -> V_146 . V_307 . V_124 = V_124 ;
if ( V_234 -> V_146 . V_307 . V_26 < 48 )
V_234 -> V_146 . V_307 . V_26 = 48 ;
if ( V_234 -> V_146 . V_307 . V_31 < 32 )
V_234 -> V_146 . V_307 . V_31 = 32 ;
if ( V_234 -> V_146 . V_307 . V_26 > V_125 )
V_234 -> V_146 . V_307 . V_26 = V_125 ;
if ( V_234 -> V_146 . V_307 . V_31 > V_126 )
V_234 -> V_146 . V_307 . V_31 = V_126 ;
V_234 -> V_146 . V_307 . V_26 &= ~ 0x03 ;
V_234 -> V_146 . V_307 . V_147 =
( V_234 -> V_146 . V_307 . V_26 * V_146 -> V_148 ) >> 3 ;
V_234 -> V_146 . V_307 . V_309 =
V_234 -> V_146 . V_307 . V_31 * V_234 -> V_146 . V_307 . V_147 ;
return 0 ;
}
static int F_131 ( struct V_215 * V_215 , void * V_216 ,
struct V_298 * V_234 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
if ( V_310 > 0 ) {
F_128 ( V_311 L_17 ) ;
return - V_129 ;
}
return F_58 ( V_11 , & V_234 -> V_146 . V_122 ) ;
}
static int F_132 ( struct V_215 * V_215 , void * V_216 ,
struct V_298 * V_234 )
{
struct V_12 * V_13 = V_216 ;
int V_139 ;
V_139 = F_129 ( V_215 , V_216 , V_234 ) ;
if ( 0 != V_139 )
return V_139 ;
V_13 -> V_146 = F_2 ( V_234 -> V_146 . V_307 . V_308 ) ;
V_13 -> V_26 = V_234 -> V_146 . V_307 . V_26 ;
V_13 -> V_31 = V_234 -> V_146 . V_307 . V_31 ;
V_13 -> V_236 . V_124 = V_234 -> V_146 . V_307 . V_124 ;
return 0 ;
}
static int F_133 ( struct V_215 * V_215 , void * V_216 ,
struct V_298 * V_234 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_139 ;
unsigned long V_217 ;
if ( V_310 > 0 ) {
F_128 ( V_311 L_17 ) ;
return - V_129 ;
}
V_139 = F_58 ( V_11 , & V_234 -> V_146 . V_122 ) ;
if ( 0 != V_139 )
return V_139 ;
F_4 ( & V_11 -> V_16 ) ;
V_13 -> V_122 = V_234 -> V_146 . V_122 ;
V_13 -> V_115 = V_234 -> V_146 . V_122 . V_132 ;
if ( V_13 -> V_115 > 8 )
V_13 -> V_115 = 8 ;
if ( F_134 ( V_13 -> V_114 , V_234 -> V_146 . V_122 . V_114 ,
sizeof( struct V_113 ) * V_13 -> V_115 ) ) {
F_5 ( & V_11 -> V_16 ) ;
return - V_312 ;
}
if ( F_7 ( V_13 , V_232 ) ) {
F_90 ( & V_11 -> V_233 , V_217 ) ;
F_68 ( V_11 , V_13 ) ;
F_59 ( V_11 , V_13 ) ;
F_91 ( & V_11 -> V_233 , V_217 ) ;
}
F_5 ( & V_11 -> V_16 ) ;
return 0 ;
}
int F_135 ( struct V_215 * V_215 , void * V_216 , struct V_1 * V_120 )
{
const struct V_1 * V_199 ;
if ( ( V_120 -> V_2 < V_313 ||
V_120 -> V_2 >= V_314 ) &&
( V_120 -> V_2 < V_315 ||
V_120 -> V_2 >= V_316 ) )
return - V_129 ;
V_199 = F_1 ( V_120 -> V_2 ) ;
* V_120 = ( NULL != V_199 ) ? * V_199 : V_317 ;
return 0 ;
}
static int F_136 ( struct V_215 * V_215 , void * V_216 ,
struct V_318 * V_3 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_319 ;
V_319 = V_3 -> V_320 ;
if ( V_319 >= V_321 )
return - V_129 ;
if ( NULL == F_14 ( V_11 , V_3 -> V_320 ) . V_20 )
return - V_129 ;
V_3 -> V_320 = V_319 ;
V_3 -> type = V_322 ;
strcpy ( V_3 -> V_20 , F_14 ( V_11 , V_319 ) . V_20 ) ;
if ( F_14 ( V_11 , V_319 ) . V_77 )
V_3 -> type = V_323 ;
V_3 -> V_324 = 1 ;
if ( V_319 == V_11 -> V_36 ) {
int V_325 = F_137 ( V_326 ) ;
int V_327 = F_137 ( V_328 ) ;
if ( 0 != ( V_325 & 0x40 ) )
V_3 -> V_329 |= V_330 ;
if ( 0 != ( V_327 & 0x40 ) )
V_3 -> V_329 |= V_331 ;
if ( 0 != ( V_327 & 0x0e ) )
V_3 -> V_329 |= V_332 ;
}
V_3 -> V_333 = V_334 ;
return 0 ;
}
static int F_138 ( struct V_215 * V_215 , void * V_216 , unsigned int * V_3 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
* V_3 = V_11 -> V_36 ;
return 0 ;
}
static int F_139 ( struct V_215 * V_215 , void * V_216 , unsigned int V_3 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_139 ;
V_139 = F_87 ( & V_11 -> V_219 , V_13 -> V_219 ) ;
if ( 0 != V_139 )
return V_139 ;
if ( V_3 >= V_321 )
return - V_129 ;
if ( NULL == F_14 ( V_11 , V_3 ) . V_20 )
return - V_129 ;
F_4 ( & V_11 -> V_16 ) ;
F_13 ( V_11 , V_3 ) ;
F_5 ( & V_11 -> V_16 ) ;
return 0 ;
}
static int F_140 ( struct V_215 * V_215 , void * V_216 ,
struct V_335 * V_236 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned int V_336 = V_11 -> V_336 ;
strcpy ( V_236 -> V_337 , L_18 ) ;
F_141 ( V_236 -> F_104 , V_338 [ V_11 -> V_339 ] . V_20 ,
sizeof( V_236 -> F_104 ) ) ;
sprintf ( V_236 -> V_340 , L_19 , F_142 ( V_11 -> V_192 ) ) ;
V_236 -> V_341 =
V_342 |
V_343 |
V_344 |
V_345 |
V_346 ;
if ( V_11 -> V_347 )
V_236 -> V_341 |= V_348 ;
if ( V_310 <= 0 )
V_236 -> V_341 |= V_349 ;
if ( ( V_336 == V_350 ) || ( V_336 == V_269 ) )
V_236 -> V_341 &= ~ V_346 ;
return 0 ;
}
int F_143 ( struct V_10 * V_11 , struct V_12 * V_13 , T_7 * V_2 )
{
unsigned long V_217 ;
unsigned int V_3 ;
T_7 V_351 ;
int V_139 ;
if ( V_13 ) {
V_139 = F_87 ( & V_11 -> V_219 , V_13 -> V_219 ) ;
if ( 0 != V_139 )
return V_139 ;
} else if ( F_8 ( V_11 , V_232 ) ) {
return - V_261 ;
}
for ( V_3 = 0 ; V_3 < V_352 ; V_3 ++ )
if ( * V_2 == V_353 [ V_3 ] . V_2 )
break;
if ( V_3 == V_352 )
for ( V_3 = 0 ; V_3 < V_352 ; V_3 ++ )
if ( * V_2 & V_353 [ V_3 ] . V_2 )
break;
if ( V_3 == V_352 )
return - V_129 ;
if ( ( * V_2 & V_354 ) && ( V_355 [ 0 ] != '-' ) ) {
if ( V_355 [ 0 ] == 'L' || V_355 [ 0 ] == 'l' ) {
if ( V_355 [ 1 ] == 'C' || V_355 [ 1 ] == 'c' )
V_351 = V_356 ;
else
V_351 = V_357 ;
} else {
if ( V_355 [ 0 ] == 'D' || V_355 [ 0 ] == 'd' )
V_351 = V_358 ;
else
V_351 = V_354 ;
}
for ( V_3 = 0 ; V_3 < V_352 ; V_3 ++ ) {
if ( V_351 == V_353 [ V_3 ] . V_2 )
break;
}
if ( V_3 == V_352 )
return - V_129 ;
}
* V_2 = V_353 [ V_3 ] . V_2 ;
F_4 ( & V_11 -> V_16 ) ;
if ( V_13 && F_7 ( V_13 , V_232 ) ) {
F_90 ( & V_11 -> V_233 , V_217 ) ;
F_68 ( V_11 , V_13 ) ;
F_91 ( & V_11 -> V_233 , V_217 ) ;
F_11 ( V_11 , & V_353 [ V_3 ] ) ;
F_90 ( & V_11 -> V_233 , V_217 ) ;
F_59 ( V_11 , V_13 ) ;
F_91 ( & V_11 -> V_233 , V_217 ) ;
} else
F_11 ( V_11 , & V_353 [ V_3 ] ) ;
F_144 ( V_11 ) ;
F_5 ( & V_11 -> V_16 ) ;
return 0 ;
}
static int F_145 ( struct V_215 * V_215 , void * V_216 , T_7 * V_2 )
{
struct V_12 * V_13 = V_216 ;
return F_143 ( V_13 -> V_11 , V_13 , V_2 ) ;
}
static int F_146 ( struct V_215 * V_215 , void * V_216 , T_7 * V_2 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
* V_2 = V_11 -> V_21 -> V_2 ;
return 0 ;
}
static int F_147 ( struct V_215 * V_215 , void * V_216 ,
struct V_359 * V_236 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
if ( V_236 -> type != V_235 &&
V_236 -> type != V_360 )
return - V_129 ;
V_236 -> V_361 = V_11 -> V_22 ;
V_236 -> V_362 = V_11 -> V_25 ;
V_236 -> V_363 . V_364 = 1 ;
V_236 -> V_363 . V_365 = 1 ;
if ( V_11 -> V_21 -> V_2 & V_32 ) {
V_236 -> V_363 . V_364 = 11 ;
V_236 -> V_363 . V_365 = 10 ;
}
if ( V_11 -> V_21 -> V_2 & V_366 ) {
V_236 -> V_363 . V_364 = 54 ;
V_236 -> V_363 . V_365 = 59 ;
}
return 0 ;
}
static int F_148 ( struct V_215 * V_215 , void * V_234 , struct V_367 * V_368 )
{
struct V_12 * V_13 = V_234 ;
struct V_10 * V_11 = V_13 -> V_11 ;
if ( V_368 -> type != V_235 &&
V_368 -> type != V_360 )
return - V_129 ;
V_368 -> V_120 = V_11 -> V_34 ;
return 0 ;
}
static int F_149 ( struct V_215 * V_215 , void * V_234 , const struct V_367 * V_368 )
{
struct V_12 * V_13 = V_234 ;
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_369 * V_110 = & V_11 -> V_22 ;
struct V_369 * V_120 = & V_11 -> V_34 ;
if ( V_368 -> type != V_235 &&
V_368 -> type != V_360 )
return - V_129 ;
if ( V_368 -> V_120 . V_31 < 0 )
return - V_129 ;
if ( V_368 -> V_120 . V_26 < 0 )
return - V_129 ;
if ( F_8 ( V_13 -> V_11 , V_232 ) )
return - V_261 ;
if ( F_8 ( V_13 -> V_11 , V_239 ) )
return - V_261 ;
* V_120 = V_368 -> V_120 ;
if ( V_120 -> V_28 < V_110 -> V_28 )
V_120 -> V_28 = V_110 -> V_28 ;
if ( V_120 -> V_28 > V_110 -> V_28 + V_110 -> V_31 )
V_120 -> V_28 = V_110 -> V_28 + V_110 -> V_31 ;
if ( V_120 -> V_31 > V_110 -> V_28 - V_120 -> V_28 + V_110 -> V_31 )
V_120 -> V_31 = V_110 -> V_28 - V_120 -> V_28 + V_110 -> V_31 ;
if ( V_120 -> V_23 < V_110 -> V_23 )
V_120 -> V_23 = V_110 -> V_23 ;
if ( V_120 -> V_23 > V_110 -> V_23 + V_110 -> V_26 )
V_120 -> V_23 = V_110 -> V_23 + V_110 -> V_26 ;
if ( V_120 -> V_26 > V_110 -> V_23 - V_120 -> V_23 + V_110 -> V_26 )
V_120 -> V_26 = V_110 -> V_23 - V_120 -> V_23 + V_110 -> V_26 ;
return 0 ;
}
static int F_150 ( struct V_215 * V_215 , void * V_216 ,
struct V_370 * V_371 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_319 ;
if ( 0 != V_371 -> V_320 )
return - V_129 ;
memset ( V_371 , 0 , sizeof( * V_371 ) ) ;
for ( V_319 = 0 ; V_319 < V_321 ; V_319 ++ ) {
if ( F_14 ( V_11 , V_319 ) . V_77 )
break;
}
if ( V_319 == V_321 )
return - V_129 ;
if ( NULL != F_14 ( V_11 , V_319 ) . V_20 ) {
strcpy ( V_371 -> V_20 , L_20 ) ;
V_371 -> type = V_372 ;
V_371 -> V_373 = V_374 |
V_375 |
V_376 |
V_377 ;
V_371 -> V_378 = 0xffffffffUL ;
V_371 -> V_379 = F_151 ( V_11 ) ;
V_371 -> V_380 = F_152 ( V_371 -> V_379 ) ;
}
if ( 0 != ( F_137 ( V_326 ) & 0x03 ) )
V_371 -> signal = 0xffff ;
return 0 ;
}
static int F_153 ( struct V_215 * V_215 , void * V_216 ,
struct V_370 * V_371 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_381 , V_382 , V_139 ;
V_139 = F_87 ( & V_11 -> V_219 , V_13 -> V_219 ) ;
if ( 0 != V_139 )
return V_139 ;
V_382 = V_11 -> V_383 . V_382 ;
if ( V_269 == V_382 ) {
V_381 = F_151 ( V_11 ) ;
V_382 = F_152 ( V_381 ) ;
}
if ( V_382 != V_371 -> V_380 )
V_11 -> V_383 . V_382 = V_371 -> V_380 ;
return 0 ;
}
static int F_154 ( struct V_215 * V_215 , void * V_216 ,
struct V_384 * V_234 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
V_234 -> type = V_13 -> V_244 ? V_385 : V_372 ;
V_234 -> V_386 = V_11 -> V_387 ;
return 0 ;
}
static int F_155 ( struct V_215 * V_215 , void * V_216 ,
struct V_384 * V_234 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_139 ;
V_139 = F_87 ( & V_11 -> V_219 , V_13 -> V_219 ) ;
if ( 0 != V_139 )
return V_139 ;
if ( 0 != V_234 -> V_227 )
return - V_129 ;
if ( 0 == V_13 -> V_244 && V_372 != V_234 -> type )
return - V_129 ;
if ( 1 == V_13 -> V_244 && V_385 != V_234 -> type )
return - V_129 ;
F_4 ( & V_11 -> V_16 ) ;
V_11 -> V_387 = V_234 -> V_386 ;
F_18 ( V_11 , V_227 , V_388 , V_234 ) ;
F_144 ( V_11 ) ;
F_5 ( & V_11 -> V_16 ) ;
return 0 ;
}
static int F_156 ( struct V_215 * V_215 , void * V_216 , struct V_389 * V_109 )
{
strcpy ( V_109 -> V_20 , L_21 ) ;
return 0 ;
}
static int F_157 ( struct V_215 * V_215 , void * V_216 , const struct V_389 * V_109 )
{
return 0 ;
}
static int F_158 ( struct V_215 * V_215 , void * V_234 , enum V_390 * V_391 )
{
struct V_12 * V_13 = V_234 ;
struct V_10 * V_11 = V_13 -> V_11 ;
* V_391 = F_159 ( & V_11 -> V_219 ) ;
return 0 ;
}
static int F_160 ( struct V_215 * V_215 , void * V_234 ,
enum V_390 V_219 )
{
struct V_12 * V_13 = V_234 ;
struct V_10 * V_11 = V_13 -> V_11 ;
return F_161 ( & V_11 -> V_219 , & V_13 -> V_219 , V_219 ) ;
}
static int F_162 ( struct V_215 * V_215 , void * V_216 ,
struct V_392 * V_234 )
{
if ( V_234 -> V_320 >= V_8 )
return - V_129 ;
F_141 ( V_234 -> V_393 , V_9 [ V_234 -> V_320 ] . V_20 ,
sizeof( V_234 -> V_393 ) ) ;
V_234 -> V_308 = V_9 [ V_234 -> V_320 ] . V_7 ;
return 0 ;
}
static int F_163 ( struct V_215 * V_215 , void * V_216 ,
struct V_392 * V_234 )
{
if ( V_310 > 0 ) {
F_128 ( V_311 L_17 ) ;
return - V_129 ;
}
if ( ( V_234 -> V_320 >= V_8 ) || V_9 [ V_234 -> V_320 ] . V_169 )
return - V_129 ;
F_141 ( V_234 -> V_393 , V_9 [ V_234 -> V_320 ] . V_20 ,
sizeof( V_234 -> V_393 ) ) ;
V_234 -> V_308 = V_9 [ V_234 -> V_320 ] . V_7 ;
return 0 ;
}
static int F_164 ( struct V_215 * V_215 , void * V_234 ,
struct V_394 * V_395 )
{
struct V_12 * V_13 = V_234 ;
struct V_10 * V_11 = V_13 -> V_11 ;
* V_395 = V_11 -> V_127 ;
V_395 -> V_373 = V_396 ;
return 0 ;
}
static int F_165 ( struct V_215 * V_215 , void * V_234 ,
const struct V_394 * V_395 )
{
struct V_12 * V_13 = V_234 ;
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_6 * V_146 ;
if ( ! F_166 ( V_397 ) &&
! F_166 ( V_398 ) )
return - V_399 ;
V_146 = F_2 ( V_395 -> V_146 . V_308 ) ;
if ( NULL == V_146 )
return - V_129 ;
V_11 -> V_127 = * V_395 ;
V_11 -> V_130 = V_146 ;
if ( 0 == V_11 -> V_127 . V_146 . V_147 )
V_11 -> V_127 . V_146 . V_147 =
V_11 -> V_127 . V_146 . V_26 * V_146 -> V_148 / 8 ;
return 0 ;
}
static int F_167 ( struct V_215 * V_215 , void * V_234 , unsigned int V_400 )
{
struct V_12 * V_13 = V_234 ;
struct V_10 * V_11 = V_13 -> V_11 ;
unsigned long V_217 ;
if ( V_400 ) {
if ( V_310 > 0 ) {
F_6 ( L_22 ) ;
return - V_129 ;
}
if ( ! F_3 ( V_11 , V_13 , V_232 ) )
return - V_261 ;
F_90 ( & V_11 -> V_233 , V_217 ) ;
F_59 ( V_11 , V_13 ) ;
F_91 ( & V_11 -> V_233 , V_217 ) ;
}
if ( ! V_400 ) {
if ( ! F_7 ( V_13 , V_232 ) )
return - V_129 ;
F_90 ( & V_11 -> V_233 , V_217 ) ;
F_68 ( V_11 , V_13 ) ;
F_91 ( & V_11 -> V_233 , V_217 ) ;
F_9 ( V_11 , V_13 , V_232 ) ;
}
return 0 ;
}
static int F_168 ( struct V_215 * V_215 , void * V_216 ,
struct V_401 * V_391 )
{
struct V_12 * V_13 = V_216 ;
return F_169 ( F_93 ( V_13 ) , V_391 ) ;
}
static int F_170 ( struct V_215 * V_215 , void * V_216 ,
struct V_402 * V_110 )
{
struct V_12 * V_13 = V_216 ;
return F_171 ( F_93 ( V_13 ) , V_110 ) ;
}
static int F_172 ( struct V_215 * V_215 , void * V_216 , struct V_402 * V_110 )
{
struct V_12 * V_13 = V_216 ;
return F_173 ( F_93 ( V_13 ) , V_110 ) ;
}
static int F_174 ( struct V_215 * V_215 , void * V_216 , struct V_402 * V_110 )
{
struct V_12 * V_13 = V_216 ;
return F_175 ( F_93 ( V_13 ) , V_110 ,
V_215 -> V_262 & V_263 ) ;
}
static int F_176 ( struct V_215 * V_215 , void * V_216 ,
enum V_243 type )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_403 = F_95 ( V_13 ) ;
if ( ! F_3 ( V_11 , V_13 , V_403 ) )
return - V_261 ;
return F_177 ( F_93 ( V_13 ) ) ;
}
static int F_178 ( struct V_215 * V_215 , void * V_216 ,
enum V_243 type )
{
int V_139 ;
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_403 = F_95 ( V_13 ) ;
V_139 = F_115 ( F_93 ( V_13 ) ) ;
if ( V_139 < 0 )
return V_139 ;
F_9 ( V_11 , V_13 , V_403 ) ;
return 0 ;
}
static int F_179 ( struct V_215 * V_215 , void * V_13 ,
struct V_404 * V_405 )
{
return 0 ;
}
static int F_180 ( struct V_215 * V_215 , void * V_216 ,
struct V_406 * V_101 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
if ( ! F_181 ( & V_101 -> V_407 ) )
return - V_129 ;
V_101 -> V_90 = F_137 ( V_101 -> V_101 ) ;
V_101 -> V_184 = 1 ;
return 0 ;
}
static int F_182 ( struct V_215 * V_215 , void * V_216 ,
struct V_406 * V_101 )
{
struct V_12 * V_13 = V_216 ;
struct V_10 * V_11 = V_13 -> V_11 ;
if ( ! F_181 ( & V_101 -> V_407 ) )
return - V_129 ;
F_17 ( V_101 -> V_101 & 0xffffff , V_101 -> V_90 ) ;
return 0 ;
}
static int F_183 ( struct V_215 * V_215 , void * V_216 ,
struct V_335 * V_236 )
{
struct V_12 * V_13 = V_215 -> V_252 ;
struct V_10 * V_11 = V_13 -> V_11 ;
strcpy ( V_236 -> V_337 , L_18 ) ;
F_141 ( V_236 -> F_104 , V_338 [ V_11 -> V_339 ] . V_20 , sizeof( V_236 -> F_104 ) ) ;
sprintf ( V_236 -> V_340 , L_19 , F_142 ( V_11 -> V_192 ) ) ;
V_236 -> V_341 = V_346 ;
return 0 ;
}
static int F_184 ( struct V_215 * V_215 , void * V_216 ,
struct V_370 * V_371 )
{
struct V_12 * V_13 = V_215 -> V_252 ;
struct V_10 * V_11 = V_13 -> V_11 ;
if ( 0 != V_371 -> V_320 )
return - V_129 ;
memset ( V_371 , 0 , sizeof( * V_371 ) ) ;
strcpy ( V_371 -> V_20 , L_23 ) ;
V_371 -> type = V_385 ;
F_18 ( V_11 , V_227 , V_408 , V_371 ) ;
if ( V_11 -> V_35 -> V_409 == V_410 ) {
V_371 -> signal = 0xf800 - ( ( F_137 ( 0x581 ) & 0x1f ) << 11 ) ;
V_371 -> V_379 = ( F_137 ( 0x529 ) & 0x08 ) ?
V_411 : V_412 ;
}
return 0 ;
}
static int F_185 ( struct V_215 * V_215 , void * V_216 ,
struct V_370 * V_371 )
{
struct V_12 * V_13 = V_215 -> V_252 ;
struct V_10 * V_11 = V_13 -> V_11 ;
if ( 0 != V_371 -> V_320 )
return - V_129 ;
F_18 ( V_11 , V_227 , V_413 , V_371 ) ;
return 0 ;
}
static int F_186 ( struct V_215 * V_215 , void * V_216 ,
struct V_318 * V_3 )
{
if ( V_3 -> V_320 != 0 )
return - V_129 ;
strcpy ( V_3 -> V_20 , L_23 ) ;
V_3 -> type = V_323 ;
return 0 ;
}
static int F_187 ( struct V_215 * V_414 , void * V_216 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_188 ( struct V_215 * V_215 , void * V_216 ,
struct V_389 * V_109 )
{
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
strcpy ( V_109 -> V_20 , L_23 ) ;
return 0 ;
}
static int F_189 ( struct V_215 * V_215 , void * V_216 ,
const struct V_389 * V_109 )
{
return 0 ;
}
static int F_190 ( struct V_215 * V_414 , void * V_216 , unsigned int V_3 )
{
return 0 ;
}
static int F_191 ( struct V_215 * V_215 , void * V_13 , T_7 * V_19 )
{
return 0 ;
}
static int F_192 ( struct V_215 * V_215 , void * V_216 ,
struct V_1 * V_120 )
{
const struct V_1 * V_199 ;
if ( V_120 -> V_2 < V_313 ||
V_120 -> V_2 >= V_314 )
return - V_129 ;
if ( V_120 -> V_2 == V_205 ) {
V_199 = F_1 ( V_120 -> V_2 ) ;
* V_120 = * V_199 ;
} else
* V_120 = V_317 ;
return 0 ;
}
int F_193 ( struct V_10 * V_11 )
{
if ( V_197 < 2 || V_197 > V_415 )
V_197 = 2 ;
if ( V_416 > V_417 )
V_416 = V_417 ;
V_416 = ( V_416 + V_418 - 1 ) & V_419 ;
V_11 -> V_55 = F_1 ( V_200 ) -> V_420 ;
V_11 -> V_58 = F_1 ( V_203 ) -> V_420 ;
V_11 -> V_62 = F_1 ( V_202 ) -> V_420 ;
V_11 -> V_60 = F_1 ( V_204 ) -> V_420 ;
V_11 -> V_208 = F_1 ( V_207 ) -> V_420 ;
V_11 -> V_206 = 1 ;
V_11 -> V_57 = F_1 ( V_209 ) -> V_420 ;
V_11 -> V_214 = F_1 ( V_213 ) -> V_420 ;
if ( V_11 -> V_229 && V_11 -> V_214 )
V_11 -> V_229 |= V_230 ;
V_11 -> V_421 = 0 ;
F_194 ( & V_11 -> V_176 . V_422 ) ;
F_195 ( & V_11 -> V_176 . V_177 ) ;
V_11 -> V_176 . V_177 . V_423 = V_424 ;
V_11 -> V_176 . V_177 . V_259 = ( unsigned long ) ( & V_11 -> V_176 ) ;
V_11 -> V_176 . V_11 = V_11 ;
if ( V_338 [ V_11 -> V_339 ] . V_425 )
F_196 ( V_11 ) ;
return 0 ;
}
int F_196 ( struct V_10 * V_11 )
{
int V_426 = V_338 [ V_11 -> V_339 ] . V_425 ;
int V_427 ;
unsigned int V_428 = V_338 [ V_11 -> V_339 ] . V_428 ;
F_17 ( V_429 , V_425 [ V_426 ] [ 0 ] ) ;
V_427 = V_425 [ V_426 ] [ 1 ] ;
if ( V_428 & V_430 )
V_427 &= ~ V_431 ;
F_17 ( V_432 , V_427 ) ;
F_17 ( V_433 , V_425 [ V_426 ] [ 2 ] ) ;
F_17 ( V_434 , V_425 [ V_426 ] [ 4 ] ) ;
V_427 = V_425 [ V_426 ] [ 5 ] ;
if ( V_428 & V_435 )
V_427 &= ~ V_436 ;
if ( V_428 & V_437 )
V_427 |= V_438 ;
F_17 ( V_439 , V_427 ) ;
V_427 = V_425 [ V_426 ] [ 6 ] ;
if ( V_428 & V_440 ) {
V_427 &= ~ V_441 ;
V_427 |= V_442 ;
}
F_17 ( V_443 , V_427 ) ;
F_17 ( V_444 , V_425 [ V_426 ] [ 7 ] ) ;
F_17 ( V_445 , V_425 [ V_426 ] [ 8 ] ) ;
F_17 ( V_446 , V_425 [ V_426 ] [ 3 ] ) ;
return 0 ;
}
int F_197 ( struct V_10 * V_11 )
{
F_11 ( V_11 , & V_353 [ 0 ] ) ;
F_13 ( V_11 , 0 ) ;
F_88 ( V_11 ) ;
F_89 ( V_11 , V_11 -> V_208 ) ;
return 0 ;
}
void F_198 ( struct V_10 * V_11 )
{
static const char * V_447 [] = {
L_24 , L_25 , L_26 , L_27 } ;
T_8 V_448 , V_449 ;
V_448 = F_137 ( V_326 ) ;
V_449 = F_137 ( V_328 ) ;
F_6 ( L_28 ,
( V_448 & 0x40 ) ? L_29 : L_30 ,
( V_449 & 0x40 ) ? L_31 : L_32 ,
V_447 [ V_448 & 0x03 ] ) ;
V_11 -> V_42 = ( V_448 & 0x40 ) || ( V_449 & 0x40 ) || ! ( V_449 & 0x1 ) ;
if ( V_11 -> V_42 ) {
if ( V_11 -> V_214 )
V_11 -> V_421 = 1 ;
F_88 ( V_11 ) ;
} else {
F_144 ( V_11 ) ;
}
if ( ( V_449 & 0x80 ) && ! V_41 && ! V_11 -> V_42 )
F_199 ( V_52 , 0x20 ) ;
else
F_200 ( V_52 , 0x20 ) ;
if ( V_11 -> V_450 && V_11 -> V_450 -> V_451 )
V_11 -> V_450 -> V_451 ( V_11 ) ;
}
void F_201 ( struct V_10 * V_11 , unsigned long V_329 )
{
enum V_123 V_124 ;
F_202 ( & V_11 -> V_233 ) ;
if ( V_11 -> V_176 . V_190 ) {
V_11 -> V_452 ++ ;
V_124 = V_11 -> V_176 . V_190 -> V_163 . V_124 ;
if ( F_60 ( V_124 ) ) {
if ( ( V_329 & 0x10 ) == 0x00 ) {
V_11 -> V_176 . V_190 -> V_166 = 1 ;
goto V_275;
}
if ( ! V_11 -> V_176 . V_190 -> V_166 )
goto V_275;
} else if ( V_124 == V_135 ) {
if ( ( V_329 & 0x10 ) != 0x10 )
goto V_275;
} else if ( V_124 == V_136 ) {
if ( ( V_329 & 0x10 ) != 0x00 )
goto V_275;
}
V_11 -> V_176 . V_190 -> V_163 . V_453 = V_11 -> V_452 ;
F_203 ( V_11 , & V_11 -> V_176 , V_276 ) ;
}
F_204 ( V_11 , & V_11 -> V_176 ) ;
V_275:
F_205 ( & V_11 -> V_233 ) ;
}
