static struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
if ( V_5 [ V_3 ] . V_2 == V_2 )
return V_5 + V_3 ;
return NULL ;
}
static void F_2 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
F_3 ( L_1 , V_9 -> V_10 ) ;
V_7 -> V_11 = V_9 ;
V_7 -> V_12 . V_13 = V_9 -> V_14 ;
V_7 -> V_15 . V_13 = V_9 -> V_14 ;
V_7 -> V_12 . V_16 = V_9 -> V_17 - V_9 -> V_14 + 1 ;
V_7 -> V_15 . V_16 = V_9 -> V_17 - V_9 -> V_14 + 1 ;
V_7 -> V_12 . V_18 = ( V_9 -> V_19 + 1 ) * 2 ;
V_7 -> V_15 . V_18 = V_9 -> V_20 * 2 ;
V_7 -> V_12 . V_21 = ( ( V_9 -> V_22 & V_23 ) ? 524 : 624 )
- V_7 -> V_12 . V_18 ;
V_7 -> V_15 . V_21 = ( V_9 -> V_24 - V_9 -> V_20 + 1 ) * 2 ;
V_7 -> V_25 = V_7 -> V_15 ;
F_4 ( V_7 ) ;
}
static void F_5 ( struct V_6 * V_7 , int V_26 )
{
F_3 ( L_2 , V_26 , F_6 ( V_7 , V_26 ) . V_10 ) ;
V_7 -> V_27 = V_26 ;
F_2 ( V_7 , V_7 -> V_11 ) ;
F_7 ( V_7 , & F_6 ( V_7 , V_26 ) ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
int V_28 , V_29 , V_30 , V_31 ;
struct V_8 * V_9 = V_7 -> V_11 ;
V_31 = F_6 ( V_7 , V_7 -> V_27 ) . V_32 ;
V_28 = V_9 -> V_28 ;
V_29 = V_9 -> V_29 ;
V_30 = V_9 -> V_30 ;
if ( V_31 > 5 )
V_28 |= 0x80 ;
if ( V_33 || V_7 -> V_34 )
V_29 |= 0x20 ;
V_29 |= V_35 ;
V_30 |= V_36 ;
V_30 &= ~ V_37 ;
V_28 &= ~ V_38 ;
F_9 ( V_39 , 0x08 ) ;
F_9 ( V_40 , 0xc0 | V_31 ) ;
F_9 ( V_41 , 0x00 ) ;
F_9 ( V_42 , 0x90 ) ;
F_9 ( V_43 , 0x90 ) ;
F_9 ( V_44 , 0xeb ) ;
F_9 ( V_45 , 0xe0 ) ;
F_9 ( V_46 , V_9 -> V_47 ) ;
F_9 ( V_48 , V_29 ) ;
F_9 ( V_49 , V_28 ) ;
F_9 ( V_50 , V_7 -> V_51 ) ;
F_9 ( V_52 ,
V_7 -> V_53 ? - V_7 -> V_54 : V_7 -> V_54 ) ;
F_9 ( V_55 ,
V_7 -> V_53 ? - V_7 -> V_56 : V_7 -> V_56 ) ;
F_9 ( V_57 , V_7 -> V_58 ) ;
F_9 ( V_59 , V_30 ) ;
F_9 ( V_60 , V_9 -> V_61 ) ;
F_9 ( V_62 , V_9 -> V_63 ) ;
F_9 ( V_64 , 0x00 ) ;
F_9 ( V_65 , 0x01 ) ;
F_9 ( V_66 , 0x11 ) ;
F_9 ( V_67 , 0xfe ) ;
F_9 ( V_68 , V_9 -> V_69 ) ;
F_9 ( V_70 , 0x40 ) ;
F_9 ( V_71 , 0x80 ) ;
}
void F_4 ( struct V_6 * V_7 )
{
F_8 ( V_7 ) ;
if ( F_6 ( V_7 , V_7 -> V_27 ) . V_72 )
F_10 ( V_7 , V_73 , V_74 , V_7 -> V_11 -> V_22 ) ;
F_11 ( V_7 , V_73 , V_74 , V_7 -> V_11 -> V_22 ) ;
}
static void F_12 ( struct V_6 * V_7 , int V_75 , int V_76 )
{
static const struct {
int V_77 ;
int V_78 ;
int V_79 ;
int V_80 ;
int V_81 ;
} V_82 [] = {
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
static const int V_83 = F_13 ( V_82 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_83 ; V_3 ++ )
if ( V_82 [ V_3 ] . V_77 == V_76 )
break;
if ( V_3 == V_83 )
return;
F_9 ( F_14 ( V_75 ) , V_82 [ V_3 ] . V_77 ) ;
F_9 ( F_15 ( V_75 ) , V_82 [ V_3 ] . V_78 ) ;
F_9 ( F_16 ( V_75 ) ,
( V_82 [ V_3 ] . V_79 << 3 ) | ( V_82 [ V_3 ] . V_80 ) ) ;
F_17 ( F_18 ( V_75 ) , 0x0f ,
( V_82 [ V_3 ] . V_81 << 2 ) | V_82 [ V_3 ] . V_81 ) ;
}
static void F_19 ( struct V_6 * V_7 , int V_75 , int V_84 )
{
int V_85 , V_86 ;
F_9 ( F_20 ( V_75 ) , V_84 & 0xff ) ;
F_9 ( F_21 ( V_75 ) , V_84 >> 8 ) ;
V_86 = ( V_7 -> V_87 ) ? 0x02 : 0x00 ;
if ( V_84 < 2048 ) {
F_3 ( L_3 , V_84 ) ;
F_9 ( F_22 ( V_75 ) , 0x00 | V_86 ) ;
F_9 ( F_23 ( V_75 ) , 0x40 ) ;
F_9 ( F_24 ( V_75 ) , 0x40 ) ;
} else {
V_85 = 0x40 * 1024 / V_84 ;
F_3 ( L_4 , V_84 , V_85 ) ;
F_9 ( F_22 ( V_75 ) , 0x01 | V_86 ) ;
F_9 ( F_23 ( V_75 ) , V_85 ) ;
F_9 ( F_24 ( V_75 ) , V_85 ) ;
}
F_9 ( F_25 ( V_75 ) , 0x80 ) ;
}
static void F_26 ( struct V_6 * V_7 , int V_75 ,
int V_16 , int V_21 , int V_88 )
{
int V_76 , V_89 , V_84 , V_90 , V_91 ;
int V_14 , V_17 , V_92 , V_93 ;
int div = V_88 ? 2 : 1 ;
V_14 = V_7 -> V_25 . V_13 ;
V_92 = V_7 -> V_25 . V_18 / 2 ;
V_17 = ( V_7 -> V_25 . V_13 + V_7 -> V_25 . V_16 - 1 ) ;
V_93 = ( V_7 -> V_25 . V_18 + V_7 -> V_25 . V_21 - 1 ) / 2 ;
F_9 ( F_27 ( V_75 ) , V_14 & 0xff ) ;
F_9 ( F_28 ( V_75 ) , V_14 >> 8 ) ;
F_9 ( F_29 ( V_75 ) , V_17 & 0xff ) ;
F_9 ( F_30 ( V_75 ) , V_17 >> 8 ) ;
F_9 ( F_31 ( V_75 ) , V_92 & 0xff ) ;
F_9 ( F_32 ( V_75 ) , V_92 >> 8 ) ;
F_9 ( F_33 ( V_75 ) , V_93 & 0xff ) ;
F_9 ( F_34 ( V_75 ) , V_93 >> 8 ) ;
V_76 = V_7 -> V_25 . V_16 / V_16 ;
if ( 0 == V_76 )
V_76 = 1 ;
V_89 = 1024 * V_7 -> V_25 . V_16 / V_76 / V_16 ;
V_84 = 512 * div * V_7 -> V_25 . V_21 / V_21 ;
F_3 ( L_5 , V_76 , V_89 , V_84 ) ;
F_12 ( V_7 , V_75 , V_76 ) ;
F_9 ( F_35 ( V_75 ) , V_89 & 0xff ) ;
F_9 ( F_36 ( V_75 ) , V_89 >> 8 ) ;
F_19 ( V_7 , V_75 , V_84 ) ;
F_9 ( F_37 ( V_75 ) , V_16 & 0xff ) ;
F_9 ( F_38 ( V_75 ) , V_16 >> 8 ) ;
F_9 ( F_39 ( V_75 ) , V_21 / div & 0xff ) ;
F_9 ( F_40 ( V_75 ) , V_21 / div >> 8 ) ;
V_91 = V_7 -> V_94 ;
V_90 = V_7 -> V_95 ;
F_9 ( F_41 ( V_75 ) , V_91 ) ;
F_9 ( F_42 ( V_75 ) , V_90 ) ;
F_9 ( F_43 ( V_75 ) , V_91 ) ;
F_9 ( F_44 ( V_75 ) , V_90 ) ;
}
static void F_45 ( struct V_6 * V_7 , int V_96 ,
struct V_97 * V_98 , int V_99 , char * V_10 )
{
T_1 V_100 = 0 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_99 ; V_3 ++ ) {
V_100 |= V_98 [ V_3 ] . V_101 ;
V_100 &= ~ V_98 [ V_3 ] . V_102 ;
if ( V_3 < 15 && V_98 [ V_3 ] . V_103 == V_98 [ V_3 + 1 ] . V_103 )
continue;
F_9 ( V_96 + 0 , V_100 ) ;
F_9 ( V_96 + 2 , V_98 [ V_3 ] . V_103 & 0xff ) ;
F_9 ( V_96 + 3 , V_98 [ V_3 ] . V_103 >> 8 ) ;
F_3 ( L_6 ,
V_10 , V_100 , V_98 [ V_3 ] . V_103 ) ;
V_96 += 8 ;
}
for (; V_96 < 0x400 ; V_96 += 8 ) {
F_9 ( V_96 + 0 , 0 ) ;
F_9 ( V_96 + 1 , 0 ) ;
F_9 ( V_96 + 2 , 0 ) ;
F_9 ( V_96 + 3 , 0 ) ;
}
}
static int F_46 ( int V_85 )
{
if ( V_85 < 0 )
V_85 = 0 ;
return V_85 ;
}
static int F_47 ( const void * V_104 , const void * V_105 )
{
const struct V_97 * V_106 = V_104 ;
const struct V_97 * V_107 = V_105 ;
if ( V_106 -> V_103 < V_107 -> V_103 )
return - 1 ;
if ( V_106 -> V_103 > V_107 -> V_103 )
return 1 ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 , struct V_108 * V_109 ,
int V_110 , int V_88 )
{
struct V_97 V_111 [ 16 ] , V_112 [ 16 ] ;
int V_113 = 0 , V_114 = 0 , V_3 ;
int div = V_88 ? 2 : 1 ;
memset ( V_111 , 0 , sizeof( V_111 ) ) ;
memset ( V_112 , 0 , sizeof( V_112 ) ) ;
for ( V_3 = 0 ; V_3 < V_110 && V_3 < 8 ; V_3 ++ ) {
V_111 [ V_113 ] . V_103 = F_46 ( V_109 [ V_3 ] . V_115 . V_13 ) ;
V_111 [ V_113 ] . V_101 = ( 1 << V_3 ) ;
V_113 ++ ;
V_111 [ V_113 ] . V_103 = F_46 ( V_109 [ V_3 ] . V_115 . V_13 + V_109 [ V_3 ] . V_115 . V_16 ) ;
V_111 [ V_113 ] . V_102 = ( 1 << V_3 ) ;
V_113 ++ ;
V_112 [ V_114 ] . V_103 = F_46 ( V_109 [ V_3 ] . V_115 . V_18 / div ) ;
V_112 [ V_114 ] . V_101 = ( 1 << V_3 ) ;
V_114 ++ ;
V_112 [ V_114 ] . V_103 = F_46 ( ( V_109 [ V_3 ] . V_115 . V_18 + V_109 [ V_3 ] . V_115 . V_21 )
/ div ) ;
V_112 [ V_114 ] . V_102 = ( 1 << V_3 ) ;
V_114 ++ ;
}
F_49 ( V_111 , V_113 , sizeof V_111 [ 0 ] , F_47 , NULL ) ;
F_49 ( V_112 , V_114 , sizeof V_112 [ 0 ] , F_47 , NULL ) ;
F_45 ( V_7 , 0x380 , V_111 , V_113 , L_7 ) ;
F_45 ( V_7 , 0x384 , V_112 , V_114 , L_8 ) ;
return 0 ;
}
static int F_50 ( struct V_6 * V_7 , struct V_116 * V_117 , bool V_118 )
{
enum V_119 V_120 ;
int V_121 , V_122 ;
if ( ! V_118 && ( V_7 -> V_123 . V_124 == NULL || V_7 -> V_125 == NULL ) )
return - V_126 ;
if ( V_117 -> V_127 . V_16 < 48 )
V_117 -> V_127 . V_16 = 48 ;
if ( V_117 -> V_127 . V_21 < 32 )
V_117 -> V_127 . V_21 = 32 ;
if ( V_117 -> V_128 > 8 )
V_117 -> V_128 = 8 ;
V_117 -> V_129 = 0 ;
V_117 -> V_130 = 0 ;
V_120 = V_117 -> V_120 ;
V_121 = V_7 -> V_25 . V_16 ;
V_122 = V_7 -> V_25 . V_21 ;
if ( V_131 == V_120 ) {
V_120 = ( V_117 -> V_127 . V_21 > V_122 / 2 )
? V_132
: V_133 ;
}
switch ( V_120 ) {
case V_133 :
case V_134 :
V_122 = V_122 / 2 ;
break;
default:
V_120 = V_132 ;
break;
}
V_117 -> V_120 = V_120 ;
if ( V_117 -> V_127 . V_16 > V_121 )
V_117 -> V_127 . V_16 = V_121 ;
if ( V_117 -> V_127 . V_21 > V_122 )
V_117 -> V_127 . V_21 = V_122 ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 )
{
unsigned long V_124 , V_135 , V_136 ;
int V_137 ;
V_137 = F_50 ( V_7 , & V_7 -> V_117 , false ) ;
if ( 0 != V_137 )
return V_137 ;
V_7 -> V_138 = V_7 -> V_117 . V_120 ;
F_3 ( L_9 ,
V_7 -> V_117 . V_127 . V_16 , V_7 -> V_117 . V_127 . V_21 ,
V_7 -> V_117 . V_127 . V_13 , V_7 -> V_117 . V_127 . V_18 ,
V_7 -> V_125 -> V_10 , V_139 [ V_7 -> V_138 ] ) ;
F_26 ( V_7 , V_140 , V_7 -> V_117 . V_127 . V_16 , V_7 -> V_117 . V_127 . V_21 ,
F_52 ( V_7 -> V_138 ) ) ;
F_48 ( V_7 , V_7 -> V_109 , V_7 -> V_110 ,
F_52 ( V_7 -> V_138 ) ) ;
if ( V_7 -> V_125 -> V_141 )
F_17 ( F_53 ( V_140 ) , 0x3f , 0x03 ) ;
else
F_17 ( F_53 ( V_140 ) , 0x3f , 0x01 ) ;
F_9 ( V_142 , V_7 -> V_125 -> V_143 | 0x20 ) ;
V_124 = ( unsigned long ) V_7 -> V_123 . V_124 ;
V_124 += V_7 -> V_123 . V_144 . V_145 * V_7 -> V_117 . V_127 . V_18 ;
V_124 += V_7 -> V_125 -> V_146 / 8 * V_7 -> V_117 . V_127 . V_13 ;
V_136 = V_7 -> V_123 . V_144 . V_145 ;
V_135 = V_147 ;
if ( V_7 -> V_125 -> V_148 )
V_135 |= V_149 ;
if ( V_7 -> V_125 -> V_150 )
V_135 |= V_151 ;
if ( F_52 ( V_7 -> V_138 ) ) {
F_54 ( F_55 ( 1 ) , V_124 ) ;
F_54 ( F_56 ( 1 ) , V_124 + V_136 ) ;
F_54 ( F_57 ( 1 ) , V_136 * 2 ) ;
F_54 ( F_58 ( 1 ) , V_135 ) ;
} else {
F_54 ( F_55 ( 1 ) , V_124 ) ;
F_54 ( F_56 ( 1 ) , V_124 ) ;
F_54 ( F_57 ( 1 ) , V_136 ) ;
F_54 ( F_58 ( 1 ) , V_135 ) ;
}
V_7 -> V_152 = 1 ;
F_59 ( V_7 ) ;
return 0 ;
}
static int F_60 ( struct V_6 * V_7 )
{
V_7 -> V_152 = 0 ;
F_59 ( V_7 ) ;
return 0 ;
}
static int F_61 ( struct V_6 * V_7 ,
struct V_153 * V_154 ,
struct V_153 * V_155 )
{
struct V_156 * V_157 = V_154 -> V_158 . V_159 -> V_160 ;
unsigned long V_124 , V_135 , V_136 ;
unsigned long V_161 , V_162 , V_163 , V_164 , V_165 ;
F_3 ( L_10 , V_154 ) ;
V_154 -> V_166 = 0 ;
F_26 ( V_7 , V_167 , V_7 -> V_16 , V_7 -> V_21 ,
F_52 ( V_7 -> V_120 ) ) ;
if ( V_7 -> V_144 -> V_141 )
F_17 ( F_53 ( V_167 ) , 0x3f , 0x03 ) ;
else
F_17 ( F_53 ( V_167 ) , 0x3f , 0x01 ) ;
F_9 ( V_168 , V_7 -> V_144 -> V_143 ) ;
V_124 = F_62 ( V_154 ) ;
if ( V_7 -> V_144 -> V_169 )
V_136 = V_7 -> V_16 ;
else
V_136 = ( V_7 -> V_16 * V_7 -> V_144 -> V_146 ) / 8 ;
V_135 = V_147 |
V_170 |
( V_157 -> V_171 . V_172 >> 12 ) ;
if ( V_7 -> V_144 -> V_148 )
V_135 |= V_149 ;
if ( V_7 -> V_144 -> V_150 )
V_135 |= V_151 ;
if ( F_52 ( V_7 -> V_120 ) ) {
F_54 ( F_55 ( 0 ) , V_124 ) ;
F_54 ( F_56 ( 0 ) , V_124 + V_136 ) ;
F_54 ( F_57 ( 0 ) , V_136 * 2 ) ;
} else {
F_54 ( F_55 ( 0 ) , V_124 ) ;
F_54 ( F_56 ( 0 ) , V_124 ) ;
F_54 ( F_57 ( 0 ) , V_136 ) ;
}
F_54 ( F_58 ( 0 ) , V_135 ) ;
if ( V_7 -> V_144 -> V_169 ) {
V_161 = V_136 >> V_7 -> V_144 -> V_173 ;
V_162 = V_7 -> V_21 >> V_7 -> V_144 -> V_174 ;
V_163 = V_124 + V_136 * V_7 -> V_21 ;
V_164 = V_163 + V_161 * V_162 ;
if ( V_7 -> V_144 -> V_175 )
V_165 = V_163 , V_163 = V_164 , V_164 = V_165 ;
F_3 ( L_11 ,
V_161 , V_162 , V_163 , V_164 ) ;
if ( F_52 ( V_7 -> V_120 ) ) {
F_54 ( F_55 ( 4 ) , V_163 ) ;
F_54 ( F_56 ( 4 ) , V_163 + V_161 ) ;
F_54 ( F_57 ( 4 ) , V_161 * 2 ) ;
F_54 ( F_55 ( 5 ) , V_164 ) ;
F_54 ( F_56 ( 5 ) , V_164 + V_161 ) ;
F_54 ( F_57 ( 5 ) , V_161 * 2 ) ;
} else {
F_54 ( F_55 ( 4 ) , V_163 ) ;
F_54 ( F_56 ( 4 ) , V_163 ) ;
F_54 ( F_57 ( 4 ) , V_161 ) ;
F_54 ( F_55 ( 5 ) , V_164 ) ;
F_54 ( F_56 ( 5 ) , V_164 ) ;
F_54 ( F_57 ( 5 ) , V_161 ) ;
}
F_54 ( F_58 ( 4 ) , V_135 ) ;
F_54 ( F_58 ( 5 ) , V_135 ) ;
}
F_59 ( V_7 ) ;
F_63 ( & V_157 -> V_176 , V_177 + V_178 ) ;
return 0 ;
}
static int F_64 ( struct V_179 * V_158 )
{
struct V_156 * V_157 = V_158 -> V_159 -> V_160 ;
struct V_153 * V_154 = F_65 ( V_158 , struct V_153 , V_158 ) ;
V_157 -> V_180 = NULL ;
V_154 -> V_181 = F_61 ;
return 0 ;
}
static int F_66 ( struct V_179 * V_158 )
{
struct V_156 * V_157 = V_158 -> V_159 -> V_160 ;
struct V_6 * V_7 = V_157 -> V_7 ;
struct V_153 * V_154 = F_65 ( V_158 , struct V_153 , V_158 ) ;
struct V_182 * V_172 = F_67 ( & V_154 -> V_158 , 0 ) ;
unsigned int V_183 ;
if ( V_172 -> V_184 -> V_185 ) {
F_68 ( L_12 ) ;
return - V_126 ;
}
V_183 = ( V_7 -> V_16 * V_7 -> V_21 * V_7 -> V_144 -> V_146 ) >> 3 ;
if ( F_69 ( V_158 , 0 ) < V_183 )
return - V_126 ;
F_70 ( V_158 , 0 , V_183 ) ;
V_158 -> V_186 . V_120 = V_7 -> V_120 ;
return F_71 ( V_7 -> V_187 , & V_157 -> V_171 , V_172 -> V_184 , V_172 -> V_188 ,
F_72 ( V_154 ) ) ;
}
static int F_73 ( struct V_159 * V_189 , const struct V_190 * V_144 ,
unsigned int * V_191 , unsigned int * V_192 ,
unsigned int V_193 [] , void * V_194 [] )
{
struct V_156 * V_157 = V_189 -> V_160 ;
struct V_6 * V_7 = V_157 -> V_7 ;
int V_183 = V_7 -> V_144 -> V_146 * V_7 -> V_16 * V_7 -> V_21 >> 3 ;
if ( V_7 -> V_16 < 48 ||
V_7 -> V_21 < 32 ||
V_7 -> V_16 / 4 > V_7 -> V_25 . V_16 ||
V_7 -> V_21 / 4 > V_7 -> V_25 . V_21 ||
V_7 -> V_16 > V_7 -> V_12 . V_16 ||
V_7 -> V_21 > V_7 -> V_12 . V_21 )
return - V_126 ;
* V_191 = F_74 ( V_183 , * V_191 ) ;
* V_192 = 1 ;
V_193 [ 0 ] = V_183 ;
V_194 [ 0 ] = V_7 -> V_195 ;
return 0 ;
}
void F_75 ( struct V_179 * V_196 )
{
struct V_156 * V_157 = V_196 -> V_159 -> V_160 ;
struct V_6 * V_7 = V_157 -> V_7 ;
struct V_153 * V_154 = F_65 ( V_196 , struct V_153 , V_158 ) ;
F_76 ( V_7 , V_157 , V_154 ) ;
}
int F_77 ( struct V_159 * V_197 , unsigned int V_83 )
{
struct V_156 * V_157 = V_197 -> V_160 ;
struct V_6 * V_7 = V_157 -> V_7 ;
if ( F_78 ( V_7 ) && F_79 ( & V_7 -> V_198 ) &&
V_157 == & V_7 -> V_199 && V_7 -> V_144 -> V_169 ) {
struct V_153 * V_154 , * V_165 ;
F_80 (buf, tmp, &dmaq->queue, entry) {
F_81 ( & V_154 -> V_200 ) ;
F_82 ( & V_154 -> V_158 , V_201 ) ;
}
if ( V_157 -> V_180 ) {
F_82 ( & V_157 -> V_180 -> V_158 , V_201 ) ;
V_157 -> V_180 = NULL ;
}
return - V_202 ;
}
if ( ( V_157 == & V_7 -> V_199 && ! F_83 ( & V_7 -> V_203 ) ) ||
( V_157 == & V_7 -> V_204 && ! F_83 ( & V_7 -> V_205 ) ) )
F_84 ( & V_7 -> V_206 ,
V_207 , 20 ) ;
V_157 -> V_208 = 0 ;
return 0 ;
}
void F_85 ( struct V_159 * V_197 )
{
struct V_156 * V_157 = V_197 -> V_160 ;
struct V_6 * V_7 = V_157 -> V_7 ;
F_86 ( V_7 , V_157 ) ;
if ( ( V_157 == & V_7 -> V_199 && ! F_83 ( & V_7 -> V_203 ) ) ||
( V_157 == & V_7 -> V_204 && ! F_83 ( & V_7 -> V_205 ) ) )
F_87 ( & V_7 -> V_206 ) ;
}
static int F_88 ( struct V_209 * V_210 )
{
struct V_6 * V_7 = F_65 ( V_210 -> V_211 , struct V_6 , V_212 ) ;
unsigned long V_213 ;
int V_214 = 0 ;
switch ( V_210 -> V_22 ) {
case V_215 :
V_7 -> V_51 = V_210 -> V_85 ;
F_9 ( V_50 , V_210 -> V_85 ) ;
break;
case V_216 :
V_7 -> V_58 = V_210 -> V_85 ;
F_9 ( V_57 , V_210 -> V_85 ) ;
break;
case V_217 :
V_7 -> V_54 = V_210 -> V_85 ;
F_9 ( V_52 ,
V_7 -> V_53 ? - V_7 -> V_54 : V_7 -> V_54 ) ;
break;
case V_218 :
V_7 -> V_56 = V_210 -> V_85 ;
F_9 ( V_55 ,
V_7 -> V_53 ? - V_7 -> V_56 : V_7 -> V_56 ) ;
break;
case V_219 :
V_7 -> V_220 = V_210 -> V_85 ;
F_89 ( V_7 ) ;
break;
case V_221 :
V_7 -> V_222 = V_210 -> V_85 ;
F_90 ( V_7 , V_7 -> V_222 ) ;
break;
case V_223 :
V_7 -> V_53 = V_210 -> V_85 ;
F_9 ( V_52 ,
V_7 -> V_53 ? - V_7 -> V_54 : V_7 -> V_54 ) ;
F_9 ( V_55 ,
V_7 -> V_53 ? - V_7 -> V_56 : V_7 -> V_56 ) ;
break;
case V_224 :
V_7 -> V_87 = V_210 -> V_85 ;
V_214 = 1 ;
break;
case V_225 :
V_7 -> V_95 = V_210 -> V_85 ;
V_214 = 1 ;
break;
case V_226 :
V_7 -> V_94 = V_210 -> V_85 ;
V_214 = 1 ;
break;
case V_227 :
{
struct V_228 V_229 ;
V_229 . V_230 = V_231 ;
V_229 . V_232 = & V_7 -> V_233 ;
V_7 -> V_234 = V_210 -> V_85 ;
if ( V_7 -> V_233 ) {
if ( V_7 -> V_234 )
V_7 -> V_233 |= V_235 ;
else
V_7 -> V_233 &= ~ V_235 ;
F_10 ( V_7 , V_230 , V_236 , & V_229 ) ;
}
break;
}
default:
return - V_126 ;
}
if ( V_214 && V_7 -> V_237 ) {
F_91 ( & V_7 -> V_238 , V_213 ) ;
F_60 ( V_7 ) ;
F_51 ( V_7 ) ;
F_92 ( & V_7 -> V_238 , V_213 ) ;
}
return 0 ;
}
static int F_93 ( struct V_239 * V_239 )
{
struct V_240 * V_241 = F_94 ( V_239 ) ;
struct V_6 * V_7 = F_95 ( V_239 ) ;
int V_242 = F_96 ( V_239 ) ;
if ( V_242 < 0 )
return V_242 ;
F_97 ( & V_7 -> V_243 ) ;
if ( V_241 -> V_244 == V_245 ) {
F_7 ( V_7 , & F_98 ( V_7 ) . V_246 ) ;
F_10 ( V_7 , V_230 , V_247 ) ;
} else {
F_5 ( V_7 , V_7 -> V_27 ) ;
}
F_99 ( & V_7 -> V_243 ) ;
return 0 ;
}
static int F_100 ( struct V_239 * V_239 )
{
struct V_240 * V_241 = F_94 ( V_239 ) ;
struct V_6 * V_7 = F_95 ( V_239 ) ;
struct V_248 * V_249 = V_239 -> V_250 ;
struct V_251 V_252 ;
unsigned long V_213 ;
F_97 ( & V_7 -> V_243 ) ;
F_101 ( V_7 ) ;
if ( V_249 == V_7 -> V_237 ) {
F_91 ( & V_7 -> V_238 , V_213 ) ;
F_60 ( V_7 ) ;
F_92 ( & V_7 -> V_238 , V_213 ) ;
V_7 -> V_237 = NULL ;
}
if ( V_241 -> V_244 == V_245 )
F_102 ( V_239 ) ;
else
F_103 ( V_239 , NULL ) ;
F_17 ( V_168 , 0x1f , 0 ) ;
F_17 ( V_142 , 0x1f , 0 ) ;
F_17 ( V_253 , 0x1f , 0 ) ;
F_17 ( V_254 , 0x1f , 0 ) ;
F_10 ( V_7 , V_255 , V_256 , 0 ) ;
if ( V_241 -> V_244 == V_245 )
F_10 ( V_7 , V_255 , V_257 , V_258 , & V_252 ) ;
F_99 ( & V_7 -> V_243 ) ;
return 0 ;
}
static T_2 F_104 ( struct V_239 * V_239 , char T_3 * V_259 ,
T_4 V_83 , T_5 * V_260 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
struct V_251 V_252 ;
V_252 . V_261 = V_83 / 3 ;
V_252 . V_262 = V_239 -> V_263 & V_264 ;
V_252 . V_265 = V_259 ;
V_252 . V_266 = V_239 ;
V_252 . V_267 = - V_268 ;
F_97 ( & V_7 -> V_243 ) ;
F_10 ( V_7 , V_255 , V_257 , V_269 , & V_252 ) ;
F_99 ( & V_7 -> V_243 ) ;
return V_252 . V_267 ;
}
static unsigned int F_105 ( struct V_239 * V_239 , T_6 * V_270 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
struct V_251 V_252 ;
unsigned int V_271 = F_106 ( V_239 , V_270 ) ;
V_252 . V_266 = V_239 ;
V_252 . V_272 = V_270 ;
V_252 . V_267 = 0 ;
F_97 ( & V_7 -> V_243 ) ;
F_10 ( V_7 , V_255 , V_257 , V_273 , & V_252 ) ;
F_99 ( & V_7 -> V_243 ) ;
return V_271 | V_252 . V_267 ;
}
static int F_107 ( struct V_239 * V_239 , void * V_232 ,
struct V_190 * V_274 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
struct V_8 * V_9 = V_7 -> V_11 ;
memset ( & V_274 -> V_144 . V_275 . V_276 , 0 , sizeof( V_274 -> V_144 . V_275 . V_276 ) ) ;
V_274 -> V_144 . V_275 . V_277 = 6750000 * 4 ;
V_274 -> V_144 . V_275 . V_278 = 2048 ;
V_274 -> V_144 . V_275 . V_279 = V_280 ;
V_274 -> V_144 . V_275 . V_185 = 64 * 4 ;
V_274 -> V_144 . V_275 . V_281 [ 0 ] = V_9 -> V_282 ;
V_274 -> V_144 . V_275 . V_83 [ 0 ] = V_9 -> V_19 - V_9 -> V_282 + 1 ;
V_274 -> V_144 . V_275 . V_281 [ 1 ] = V_9 -> V_283 ;
V_274 -> V_144 . V_275 . V_83 [ 1 ] = V_274 -> V_144 . V_275 . V_83 [ 0 ] ;
V_274 -> V_144 . V_275 . V_213 = 0 ;
return 0 ;
}
static int F_108 ( struct V_239 * V_239 , void * V_232 ,
struct V_190 * V_274 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
V_274 -> V_144 . V_284 . V_16 = V_7 -> V_16 ;
V_274 -> V_144 . V_284 . V_21 = V_7 -> V_21 ;
V_274 -> V_144 . V_284 . V_120 = V_7 -> V_120 ;
V_274 -> V_144 . V_284 . V_285 = V_7 -> V_144 -> V_2 ;
V_274 -> V_144 . V_284 . V_145 =
( V_274 -> V_144 . V_284 . V_16 * V_7 -> V_144 -> V_146 ) >> 3 ;
V_274 -> V_144 . V_284 . V_286 =
V_274 -> V_144 . V_284 . V_21 * V_274 -> V_144 . V_284 . V_145 ;
V_274 -> V_144 . V_284 . V_287 = V_288 ;
return 0 ;
}
static int F_109 ( struct V_239 * V_239 , void * V_232 ,
struct V_190 * V_274 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
struct V_108 T_3 * V_109 = V_274 -> V_144 . V_117 . V_109 ;
T_7 V_128 = V_274 -> V_144 . V_117 . V_128 ;
int V_137 = 0 ;
int V_3 ;
if ( V_289 > 0 ) {
F_110 ( V_290 L_13 ) ;
return - V_126 ;
}
V_274 -> V_144 . V_117 = V_7 -> V_117 ;
V_274 -> V_144 . V_117 . V_109 = V_109 ;
if ( V_109 == NULL )
V_128 = 0 ;
if ( V_7 -> V_110 < V_128 )
V_128 = V_7 -> V_110 ;
V_274 -> V_144 . V_117 . V_128 = V_128 ;
for ( V_3 = 0 ; ! V_137 && V_3 < V_128 ; V_3 ++ ) {
if ( F_111 ( & V_274 -> V_144 . V_117 . V_109 [ V_3 ] . V_115 , & V_7 -> V_109 [ V_3 ] . V_115 ,
sizeof( struct V_291 ) ) )
V_137 = - V_292 ;
}
return V_137 ;
}
static int F_112 ( struct V_239 * V_239 , void * V_232 ,
struct V_190 * V_274 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
struct V_1 * V_144 ;
enum V_119 V_120 ;
unsigned int V_121 , V_122 ;
V_144 = F_1 ( V_274 -> V_144 . V_284 . V_285 ) ;
if ( NULL == V_144 )
return - V_126 ;
V_120 = V_274 -> V_144 . V_284 . V_120 ;
V_121 = F_113 ( V_7 -> V_25 . V_16 * 4 , V_7 -> V_12 . V_16 ) ;
V_122 = F_113 ( V_7 -> V_25 . V_21 * 4 , V_7 -> V_12 . V_21 ) ;
if ( V_131 == V_120 ) {
V_120 = ( V_274 -> V_144 . V_284 . V_21 > V_122 / 2 )
? V_132
: V_134 ;
}
switch ( V_120 ) {
case V_133 :
case V_134 :
V_122 = V_122 / 2 ;
break;
default:
V_120 = V_132 ;
break;
}
V_274 -> V_144 . V_284 . V_120 = V_120 ;
if ( V_274 -> V_144 . V_284 . V_16 < 48 )
V_274 -> V_144 . V_284 . V_16 = 48 ;
if ( V_274 -> V_144 . V_284 . V_21 < 32 )
V_274 -> V_144 . V_284 . V_21 = 32 ;
if ( V_274 -> V_144 . V_284 . V_16 > V_121 )
V_274 -> V_144 . V_284 . V_16 = V_121 ;
if ( V_274 -> V_144 . V_284 . V_21 > V_122 )
V_274 -> V_144 . V_284 . V_21 = V_122 ;
V_274 -> V_144 . V_284 . V_16 &= ~ 0x03 ;
V_274 -> V_144 . V_284 . V_145 =
( V_274 -> V_144 . V_284 . V_16 * V_144 -> V_146 ) >> 3 ;
V_274 -> V_144 . V_284 . V_286 =
V_274 -> V_144 . V_284 . V_21 * V_274 -> V_144 . V_284 . V_145 ;
V_274 -> V_144 . V_284 . V_287 = V_288 ;
return 0 ;
}
static int F_114 ( struct V_239 * V_239 , void * V_232 ,
struct V_190 * V_274 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
if ( V_289 > 0 ) {
F_110 ( V_290 L_13 ) ;
return - V_126 ;
}
if ( V_274 -> V_144 . V_117 . V_109 == NULL )
V_274 -> V_144 . V_117 . V_128 = 0 ;
return F_50 ( V_7 , & V_274 -> V_144 . V_117 , true ) ;
}
static int F_115 ( struct V_239 * V_239 , void * V_232 ,
struct V_190 * V_274 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
int V_137 ;
V_137 = F_112 ( V_239 , V_232 , V_274 ) ;
if ( 0 != V_137 )
return V_137 ;
V_7 -> V_144 = F_1 ( V_274 -> V_144 . V_284 . V_285 ) ;
V_7 -> V_16 = V_274 -> V_144 . V_284 . V_16 ;
V_7 -> V_21 = V_274 -> V_144 . V_284 . V_21 ;
V_7 -> V_120 = V_274 -> V_144 . V_284 . V_120 ;
return 0 ;
}
static int F_116 ( struct V_239 * V_239 , void * V_232 ,
struct V_190 * V_274 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
int V_137 ;
unsigned long V_213 ;
if ( V_289 > 0 ) {
F_110 ( V_290 L_13 ) ;
return - V_126 ;
}
if ( V_274 -> V_144 . V_117 . V_109 == NULL )
V_274 -> V_144 . V_117 . V_128 = 0 ;
V_137 = F_50 ( V_7 , & V_274 -> V_144 . V_117 , true ) ;
if ( 0 != V_137 )
return V_137 ;
V_7 -> V_117 = V_274 -> V_144 . V_117 ;
V_7 -> V_110 = V_274 -> V_144 . V_117 . V_128 ;
if ( F_117 ( V_7 -> V_109 , V_274 -> V_144 . V_117 . V_109 ,
sizeof( struct V_108 ) * V_7 -> V_110 ) )
return - V_292 ;
if ( V_232 == V_7 -> V_237 ) {
F_91 ( & V_7 -> V_238 , V_213 ) ;
F_60 ( V_7 ) ;
F_51 ( V_7 ) ;
F_92 ( & V_7 -> V_238 , V_213 ) ;
}
return 0 ;
}
int F_118 ( struct V_239 * V_239 , void * V_232 , struct V_293 * V_3 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
unsigned int V_294 ;
V_294 = V_3 -> V_295 ;
if ( V_294 >= V_296 )
return - V_126 ;
if ( NULL == F_6 ( V_7 , V_3 -> V_295 ) . V_10 )
return - V_126 ;
V_3 -> V_295 = V_294 ;
V_3 -> type = V_297 ;
strcpy ( V_3 -> V_10 , F_6 ( V_7 , V_294 ) . V_10 ) ;
if ( F_6 ( V_7 , V_294 ) . V_72 )
V_3 -> type = V_298 ;
if ( V_294 == V_7 -> V_27 ) {
int V_299 = F_119 ( V_300 ) ;
int V_301 = F_119 ( V_302 ) ;
if ( 0 != ( V_299 & 0x40 ) )
V_3 -> V_303 |= V_304 ;
if ( 0 != ( V_301 & 0x40 ) )
V_3 -> V_303 |= V_305 ;
if ( 0 != ( V_301 & 0x0e ) )
V_3 -> V_303 |= V_306 ;
}
V_3 -> V_307 = V_308 ;
return 0 ;
}
int F_120 ( struct V_239 * V_239 , void * V_232 , unsigned int * V_3 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
* V_3 = V_7 -> V_27 ;
return 0 ;
}
int F_121 ( struct V_239 * V_239 , void * V_232 , unsigned int V_3 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
if ( V_3 >= V_296 )
return - V_126 ;
if ( NULL == F_6 ( V_7 , V_3 ) . V_10 )
return - V_126 ;
F_5 ( V_7 , V_3 ) ;
return 0 ;
}
int F_122 ( struct V_239 * V_239 , void * V_232 ,
struct V_309 * V_310 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
struct V_240 * V_241 = F_94 ( V_239 ) ;
T_7 V_311 , V_312 , V_313 ;
unsigned int V_314 = V_7 -> V_314 ;
strcpy ( V_310 -> V_315 , L_14 ) ;
F_123 ( V_310 -> F_98 , V_316 [ V_7 -> V_317 ] . V_10 ,
sizeof( V_310 -> F_98 ) ) ;
sprintf ( V_310 -> V_318 , L_15 , F_124 ( V_7 -> V_187 ) ) ;
V_310 -> V_319 = V_320 | V_321 ;
if ( ( V_314 != V_322 ) && ( V_314 != V_323 ) )
V_310 -> V_319 |= V_324 ;
V_311 = V_325 ;
if ( V_7 -> V_326 )
V_311 |= V_327 ;
V_312 = V_328 ;
if ( V_289 <= 0 && ! F_125 ( V_239 ) )
V_312 |= V_329 ;
V_313 = V_330 ;
switch ( V_241 -> V_244 ) {
case V_245 :
V_310 -> V_319 |= V_311 ;
break;
case V_331 :
V_310 -> V_319 |= V_312 ;
break;
case V_332 :
V_310 -> V_319 |= V_313 ;
break;
}
V_310 -> V_333 = V_311 | V_312 | V_313 |
V_310 -> V_319 | V_334 ;
if ( V_241 -> V_244 == V_245 ) {
V_310 -> V_319 &= ~ V_321 ;
if ( ! V_7 -> V_326 )
V_310 -> V_319 &= ~ V_320 ;
}
return 0 ;
}
int F_126 ( struct V_239 * V_239 , void * V_232 , T_8 V_22 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
struct V_248 * V_249 = V_232 ;
unsigned long V_213 ;
unsigned int V_3 ;
T_8 V_335 ;
if ( F_125 ( V_239 ) && V_7 -> V_237 ) {
return - V_202 ;
}
for ( V_3 = 0 ; V_3 < V_336 ; V_3 ++ )
if ( V_22 == V_337 [ V_3 ] . V_22 )
break;
if ( V_3 == V_336 )
for ( V_3 = 0 ; V_3 < V_336 ; V_3 ++ )
if ( V_22 & V_337 [ V_3 ] . V_22 )
break;
if ( V_3 == V_336 )
return - V_126 ;
if ( ( V_22 & V_338 ) && ( V_339 [ 0 ] != '-' ) ) {
if ( V_339 [ 0 ] == 'L' || V_339 [ 0 ] == 'l' ) {
if ( V_339 [ 1 ] == 'C' || V_339 [ 1 ] == 'c' )
V_335 = V_340 ;
else
V_335 = V_341 ;
} else {
if ( V_339 [ 0 ] == 'D' || V_339 [ 0 ] == 'd' )
V_335 = V_342 ;
else
V_335 = V_338 ;
}
for ( V_3 = 0 ; V_3 < V_336 ; V_3 ++ ) {
if ( V_335 == V_337 [ V_3 ] . V_22 )
break;
}
if ( V_3 == V_336 )
return - V_126 ;
}
V_22 = V_337 [ V_3 ] . V_22 ;
if ( ! F_125 ( V_239 ) && V_249 == V_7 -> V_237 ) {
F_91 ( & V_7 -> V_238 , V_213 ) ;
F_60 ( V_7 ) ;
F_92 ( & V_7 -> V_238 , V_213 ) ;
F_2 ( V_7 , & V_337 [ V_3 ] ) ;
F_91 ( & V_7 -> V_238 , V_213 ) ;
F_51 ( V_7 ) ;
F_92 ( & V_7 -> V_238 , V_213 ) ;
} else
F_2 ( V_7 , & V_337 [ V_3 ] ) ;
F_127 ( V_7 ) ;
return 0 ;
}
int F_128 ( struct V_239 * V_239 , void * V_232 , T_8 * V_22 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
* V_22 = V_7 -> V_11 -> V_22 ;
return 0 ;
}
static T_8 F_129 ( struct V_6 * V_7 )
{
static T_8 V_343 [] = {
V_344 ,
V_345 ,
V_346 ,
V_338 } ;
T_8 V_267 = 0 ;
T_9 V_347 = F_119 ( V_300 ) ;
T_9 V_348 = F_119 ( V_302 ) ;
if ( ! ( V_348 & 0x1 ) )
V_267 = V_344 ;
else
V_267 = V_343 [ V_347 & 0x03 ] ;
return V_267 ;
}
int F_130 ( struct V_239 * V_239 , void * V_232 , T_8 * V_307 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
* V_307 &= F_129 ( V_7 ) ;
return 0 ;
}
static int F_131 ( struct V_239 * V_239 , void * V_232 ,
struct V_349 * V_310 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
if ( V_310 -> type != V_350 &&
V_310 -> type != V_351 )
return - V_126 ;
V_310 -> V_352 = V_7 -> V_12 ;
V_310 -> V_353 = V_7 -> V_15 ;
V_310 -> V_354 . V_355 = 1 ;
V_310 -> V_354 . V_356 = 1 ;
if ( V_7 -> V_11 -> V_22 & V_23 ) {
V_310 -> V_354 . V_355 = 11 ;
V_310 -> V_354 . V_356 = 10 ;
}
if ( V_7 -> V_11 -> V_22 & V_357 ) {
V_310 -> V_354 . V_355 = 54 ;
V_310 -> V_354 . V_356 = 59 ;
}
return 0 ;
}
static int F_132 ( struct V_239 * V_239 , void * V_274 , struct V_358 * V_359 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
if ( V_359 -> type != V_350 &&
V_359 -> type != V_351 )
return - V_126 ;
V_359 -> V_115 = V_7 -> V_25 ;
return 0 ;
}
static int F_133 ( struct V_239 * V_239 , void * V_274 , const struct V_358 * V_359 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
struct V_291 * V_105 = & V_7 -> V_12 ;
struct V_291 * V_115 = & V_7 -> V_25 ;
if ( V_359 -> type != V_350 &&
V_359 -> type != V_351 )
return - V_126 ;
if ( V_7 -> V_237 )
return - V_202 ;
if ( F_83 ( & V_7 -> V_205 ) )
return - V_202 ;
* V_115 = V_359 -> V_115 ;
if ( V_115 -> V_18 < V_105 -> V_18 )
V_115 -> V_18 = V_105 -> V_18 ;
if ( V_115 -> V_18 > V_105 -> V_18 + V_105 -> V_21 )
V_115 -> V_18 = V_105 -> V_18 + V_105 -> V_21 ;
if ( V_115 -> V_21 > V_105 -> V_18 - V_115 -> V_18 + V_105 -> V_21 )
V_115 -> V_21 = V_105 -> V_18 - V_115 -> V_18 + V_105 -> V_21 ;
if ( V_115 -> V_13 < V_105 -> V_13 )
V_115 -> V_13 = V_105 -> V_13 ;
if ( V_115 -> V_13 > V_105 -> V_13 + V_105 -> V_16 )
V_115 -> V_13 = V_105 -> V_13 + V_105 -> V_16 ;
if ( V_115 -> V_16 > V_105 -> V_13 - V_115 -> V_13 + V_105 -> V_16 )
V_115 -> V_16 = V_105 -> V_13 - V_115 -> V_13 + V_105 -> V_16 ;
return 0 ;
}
int F_134 ( struct V_239 * V_239 , void * V_232 ,
struct V_360 * V_361 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
int V_294 ;
if ( 0 != V_361 -> V_295 )
return - V_126 ;
memset ( V_361 , 0 , sizeof( * V_361 ) ) ;
for ( V_294 = 0 ; V_294 < V_296 ; V_294 ++ ) {
if ( F_6 ( V_7 , V_294 ) . V_72 )
break;
}
if ( V_294 == V_296 )
return - V_126 ;
if ( NULL != F_6 ( V_7 , V_294 ) . V_10 ) {
strcpy ( V_361 -> V_10 , L_16 ) ;
V_361 -> type = V_362 ;
F_10 ( V_7 , V_230 , V_363 , V_361 ) ;
V_361 -> V_364 = V_365 |
V_366 |
V_367 |
V_368 ;
V_361 -> V_369 = F_135 ( V_7 ) ;
V_361 -> V_370 = F_136 ( V_361 -> V_369 ) ;
}
if ( 0 != ( F_119 ( V_300 ) & 0x03 ) )
V_361 -> signal = 0xffff ;
return 0 ;
}
int F_137 ( struct V_239 * V_239 , void * V_232 ,
const struct V_360 * V_361 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
int V_371 , V_372 ;
if ( 0 != V_361 -> V_295 )
return - V_126 ;
V_372 = V_7 -> V_373 . V_372 ;
if ( V_323 == V_372 ) {
V_371 = F_135 ( V_7 ) ;
V_372 = F_136 ( V_371 ) ;
}
if ( V_372 != V_361 -> V_370 )
V_7 -> V_373 . V_372 = V_361 -> V_370 ;
return 0 ;
}
int F_138 ( struct V_239 * V_239 , void * V_232 ,
struct V_374 * V_274 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
if ( 0 != V_274 -> V_230 )
return - V_126 ;
F_10 ( V_7 , V_230 , V_375 , V_274 ) ;
return 0 ;
}
int F_139 ( struct V_239 * V_239 , void * V_232 ,
const struct V_374 * V_274 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
if ( 0 != V_274 -> V_230 )
return - V_126 ;
F_10 ( V_7 , V_230 , V_376 , V_274 ) ;
F_127 ( V_7 ) ;
return 0 ;
}
static int F_140 ( struct V_239 * V_239 , void * V_232 ,
struct V_377 * V_274 )
{
if ( V_274 -> V_295 >= V_4 )
return - V_126 ;
F_123 ( V_274 -> V_378 , V_5 [ V_274 -> V_295 ] . V_10 ,
sizeof( V_274 -> V_378 ) ) ;
V_274 -> V_285 = V_5 [ V_274 -> V_295 ] . V_2 ;
return 0 ;
}
static int F_141 ( struct V_239 * V_239 , void * V_232 ,
struct V_377 * V_274 )
{
if ( V_289 > 0 ) {
F_110 ( V_290 L_13 ) ;
return - V_126 ;
}
if ( ( V_274 -> V_295 >= V_4 ) || V_5 [ V_274 -> V_295 ] . V_169 )
return - V_126 ;
F_123 ( V_274 -> V_378 , V_5 [ V_274 -> V_295 ] . V_10 ,
sizeof( V_274 -> V_378 ) ) ;
V_274 -> V_285 = V_5 [ V_274 -> V_295 ] . V_2 ;
return 0 ;
}
static int F_142 ( struct V_239 * V_239 , void * V_274 ,
struct V_379 * V_380 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
* V_380 = V_7 -> V_123 ;
V_380 -> V_364 = V_381 ;
return 0 ;
}
static int F_143 ( struct V_239 * V_239 , void * V_274 ,
const struct V_379 * V_380 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
struct V_1 * V_144 ;
if ( ! F_144 ( V_382 ) &&
! F_144 ( V_383 ) )
return - V_384 ;
V_144 = F_1 ( V_380 -> V_144 . V_285 ) ;
if ( NULL == V_144 )
return - V_126 ;
V_7 -> V_123 = * V_380 ;
V_7 -> V_125 = V_144 ;
if ( 0 == V_7 -> V_123 . V_144 . V_145 )
V_7 -> V_123 . V_144 . V_145 =
V_7 -> V_123 . V_144 . V_16 * V_144 -> V_146 / 8 ;
return 0 ;
}
static int F_145 ( struct V_239 * V_239 , void * V_232 , unsigned int V_385 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
unsigned long V_213 ;
if ( V_385 ) {
if ( V_289 > 0 ) {
F_3 ( L_17 ) ;
return - V_126 ;
}
if ( V_7 -> V_237 && V_232 != V_7 -> V_237 )
return - V_202 ;
V_7 -> V_237 = V_232 ;
F_91 ( & V_7 -> V_238 , V_213 ) ;
F_51 ( V_7 ) ;
F_92 ( & V_7 -> V_238 , V_213 ) ;
}
if ( ! V_385 ) {
if ( V_232 != V_7 -> V_237 )
return - V_126 ;
F_91 ( & V_7 -> V_238 , V_213 ) ;
F_60 ( V_7 ) ;
F_92 ( & V_7 -> V_238 , V_213 ) ;
V_7 -> V_237 = NULL ;
}
return 0 ;
}
static int F_146 ( struct V_239 * V_239 , void * V_232 ,
struct V_386 * V_96 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
V_96 -> V_85 = F_119 ( V_96 -> V_96 & 0xffffff ) ;
V_96 -> V_183 = 1 ;
return 0 ;
}
static int F_147 ( struct V_239 * V_239 , void * V_232 ,
const struct V_386 * V_96 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
F_9 ( V_96 -> V_96 & 0xffffff , V_96 -> V_85 ) ;
return 0 ;
}
static int F_148 ( struct V_239 * V_239 , void * V_232 ,
struct V_360 * V_361 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
if ( 0 != V_361 -> V_295 )
return - V_126 ;
strcpy ( V_361 -> V_10 , L_18 ) ;
F_10 ( V_7 , V_230 , V_363 , V_361 ) ;
V_361 -> V_370 &= V_387 | V_388 ;
if ( V_7 -> V_26 -> V_389 == V_390 ) {
V_361 -> signal = 0xf800 - ( ( F_119 ( 0x581 ) & 0x1f ) << 11 ) ;
V_361 -> V_369 = ( F_119 ( 0x529 ) & 0x08 ) ?
V_391 : V_392 ;
}
return 0 ;
}
static int F_149 ( struct V_239 * V_239 , void * V_232 ,
const struct V_360 * V_361 )
{
struct V_6 * V_7 = F_95 ( V_239 ) ;
if ( 0 != V_361 -> V_295 )
return - V_126 ;
F_10 ( V_7 , V_230 , V_393 , V_361 ) ;
return 0 ;
}
int F_150 ( struct V_6 * V_7 )
{
struct V_394 * V_395 = & V_7 -> V_212 ;
struct V_159 * V_189 ;
int V_242 ;
if ( V_396 < 2 || V_396 > V_397 )
V_396 = 2 ;
if ( V_398 > V_399 )
V_398 = V_399 ;
V_398 = ( V_398 + V_400 - 1 ) & V_401 ;
F_151 ( V_395 , 11 ) ;
F_152 ( V_395 , & V_402 ,
V_215 , 0 , 255 , 1 , 128 ) ;
F_152 ( V_395 , & V_402 ,
V_217 , 0 , 127 , 1 , 68 ) ;
F_152 ( V_395 , & V_402 ,
V_218 , 0 , 127 , 1 , 64 ) ;
F_152 ( V_395 , & V_402 ,
V_216 , - 128 , 127 , 1 , 0 ) ;
F_152 ( V_395 , & V_402 ,
V_224 , 0 , 1 , 1 , 0 ) ;
F_152 ( V_395 , & V_402 ,
V_219 , 0 , 1 , 1 , 0 ) ;
F_152 ( V_395 , & V_402 ,
V_221 , - 15 , 15 , 1 , 0 ) ;
F_153 ( V_395 , & V_403 , NULL ) ;
F_153 ( V_395 , & V_404 , NULL ) ;
F_153 ( V_395 , & V_405 , NULL ) ;
F_153 ( V_395 , & V_406 , NULL ) ;
if ( V_395 -> error )
return V_395 -> error ;
if ( F_154 ( V_7 ) ) {
V_395 = & V_7 -> V_407 ;
F_151 ( V_395 , 2 ) ;
F_155 ( V_395 , & V_7 -> V_212 ,
V_408 ) ;
if ( V_395 -> error )
return V_395 -> error ;
}
V_7 -> V_220 = 1 ;
if ( V_7 -> V_233 && V_406 . V_409 )
V_7 -> V_233 |= V_235 ;
V_7 -> V_410 = 0 ;
F_156 ( & V_7 -> V_199 . V_411 ) ;
F_157 ( & V_7 -> V_199 . V_176 ) ;
V_7 -> V_199 . V_176 . V_412 = V_413 ;
V_7 -> V_199 . V_176 . V_259 = ( unsigned long ) ( & V_7 -> V_199 ) ;
V_7 -> V_199 . V_7 = V_7 ;
V_7 -> V_144 = F_1 ( V_414 ) ;
V_7 -> V_16 = 720 ;
V_7 -> V_21 = 576 ;
V_7 -> V_120 = V_132 ;
V_7 -> V_117 . V_127 . V_16 = V_7 -> V_16 ;
V_7 -> V_117 . V_127 . V_21 = V_7 -> V_21 ;
V_7 -> V_117 . V_120 = V_132 ;
V_7 -> V_123 . V_144 . V_16 = V_7 -> V_16 ;
V_7 -> V_123 . V_144 . V_21 = V_7 -> V_21 ;
V_7 -> V_123 . V_144 . V_285 = V_7 -> V_144 -> V_2 ;
V_7 -> V_123 . V_144 . V_287 = V_288 ;
if ( V_316 [ V_7 -> V_317 ] . V_415 )
F_158 ( V_7 ) ;
V_189 = & V_7 -> V_205 ;
V_189 -> type = V_350 ;
V_189 -> V_416 = V_417 | V_418 ;
if ( V_419 )
V_189 -> V_416 |= V_420 ;
V_189 -> V_160 = & V_7 -> V_199 ;
V_189 -> V_421 = & V_422 ;
V_189 -> V_423 = V_424 ;
V_189 -> V_425 = & V_426 ;
V_189 -> V_427 = sizeof( struct V_153 ) ;
V_189 -> V_428 = V_429 ;
V_189 -> V_243 = & V_7 -> V_243 ;
V_242 = F_159 ( V_189 ) ;
if ( V_242 )
return V_242 ;
F_160 ( V_7 -> V_187 , & V_7 -> V_199 . V_171 ) ;
V_189 = & V_7 -> V_203 ;
V_189 -> type = V_430 ;
V_189 -> V_416 = V_417 | V_418 ;
if ( V_419 )
V_189 -> V_416 |= V_420 ;
V_189 -> V_160 = & V_7 -> V_204 ;
V_189 -> V_421 = & V_431 ;
V_189 -> V_423 = V_424 ;
V_189 -> V_425 = & V_426 ;
V_189 -> V_427 = sizeof( struct V_153 ) ;
V_189 -> V_428 = V_429 ;
V_189 -> V_243 = & V_7 -> V_243 ;
V_242 = F_159 ( V_189 ) ;
if ( V_242 )
return V_242 ;
F_160 ( V_7 -> V_187 , & V_7 -> V_204 . V_171 ) ;
return 0 ;
}
void F_161 ( struct V_6 * V_7 )
{
F_162 ( & V_7 -> V_205 ) ;
F_163 ( V_7 -> V_187 , & V_7 -> V_199 . V_171 ) ;
F_162 ( & V_7 -> V_203 ) ;
F_163 ( V_7 -> V_187 , & V_7 -> V_204 . V_171 ) ;
F_164 ( & V_7 -> V_212 ) ;
if ( F_154 ( V_7 ) )
F_164 ( & V_7 -> V_407 ) ;
}
int F_158 ( struct V_6 * V_7 )
{
int V_432 = V_316 [ V_7 -> V_317 ] . V_415 ;
int V_433 ;
unsigned int V_434 = V_316 [ V_7 -> V_317 ] . V_434 ;
F_9 ( V_435 , V_415 [ V_432 ] [ 0 ] ) ;
V_433 = V_415 [ V_432 ] [ 1 ] ;
if ( V_434 & V_436 )
V_433 &= ~ V_437 ;
F_9 ( V_438 , V_433 ) ;
F_9 ( V_439 , V_415 [ V_432 ] [ 2 ] ) ;
F_9 ( V_440 , V_415 [ V_432 ] [ 4 ] ) ;
V_433 = V_415 [ V_432 ] [ 5 ] ;
if ( V_434 & V_441 )
V_433 &= ~ V_442 ;
if ( V_434 & V_443 )
V_433 |= V_444 ;
F_9 ( V_445 , V_433 ) ;
V_433 = V_415 [ V_432 ] [ 6 ] ;
if ( V_434 & V_446 ) {
V_433 &= ~ V_447 ;
V_433 |= V_448 ;
}
F_9 ( V_449 , V_433 ) ;
F_9 ( V_450 , V_415 [ V_432 ] [ 7 ] ) ;
F_9 ( V_451 , V_415 [ V_432 ] [ 8 ] ) ;
F_9 ( V_452 , V_415 [ V_432 ] [ 3 ] ) ;
return 0 ;
}
int F_165 ( struct V_6 * V_7 )
{
F_2 ( V_7 , & V_337 [ 0 ] ) ;
F_5 ( V_7 , 0 ) ;
F_166 ( & V_7 -> V_212 ) ;
F_89 ( V_7 ) ;
F_90 ( V_7 , V_7 -> V_222 ) ;
return 0 ;
}
void F_167 ( struct V_6 * V_7 )
{
static const char * V_453 [] = {
L_19 , L_20 , L_21 , L_22 } ;
T_7 V_347 , V_348 ;
V_347 = F_119 ( V_300 ) ;
V_348 = F_119 ( V_302 ) ;
F_3 ( L_23 ,
( V_347 & 0x40 ) ? L_24 : L_25 ,
( V_348 & 0x40 ) ? L_26 : L_27 ,
V_453 [ V_347 & 0x03 ] ) ;
V_7 -> V_34 = ( V_347 & 0x40 ) || ( V_348 & 0x40 ) || ! ( V_348 & 0x1 ) ;
if ( V_7 -> V_34 ) {
if ( V_7 -> V_234 )
V_7 -> V_410 = 1 ;
F_89 ( V_7 ) ;
} else {
F_127 ( V_7 ) ;
}
if ( ( V_348 & 0x80 ) && ! V_33 && ! V_7 -> V_34 )
F_168 ( V_48 , 0x20 ) ;
else
F_169 ( V_48 , 0x20 ) ;
if ( V_7 -> V_454 && V_7 -> V_454 -> V_455 )
V_7 -> V_454 -> V_455 ( V_7 ) ;
}
void F_170 ( struct V_6 * V_7 , unsigned long V_303 )
{
enum V_119 V_120 ;
F_171 ( & V_7 -> V_238 ) ;
if ( V_7 -> V_199 . V_180 ) {
V_120 = V_7 -> V_120 ;
if ( F_52 ( V_120 ) ) {
if ( ( V_303 & 0x10 ) == 0x00 ) {
V_7 -> V_199 . V_180 -> V_166 = 1 ;
goto V_456;
}
if ( ! V_7 -> V_199 . V_180 -> V_166 )
goto V_456;
} else if ( V_120 == V_133 ) {
if ( ( V_303 & 0x10 ) != 0x10 )
goto V_456;
} else if ( V_120 == V_134 ) {
if ( ( V_303 & 0x10 ) != 0x00 )
goto V_456;
}
F_172 ( V_7 , & V_7 -> V_199 , V_457 ) ;
}
F_173 ( V_7 , & V_7 -> V_199 ) ;
V_456:
F_174 ( & V_7 -> V_238 ) ;
}
