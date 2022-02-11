static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_5 = V_4 -> V_6 - V_7 ;
void T_1 * V_8 = V_2 -> V_9 -> V_10 [ V_11 ] ;
void T_1 * V_12 = V_8 + V_13 ;
void T_1 * V_14 = V_8 + V_15 ;
void T_1 * V_16 = V_8 + V_17 ;
unsigned long V_18 ;
int V_19 ;
V_18 = F_2 ( V_12 ) ;
if ( V_18 & V_20 )
V_19 = 1 ;
else
V_19 = 0 ;
V_18 = V_21 [ V_19 ] [ V_5 ] << 16 | V_22 [ V_19 ] [ V_5 ] ;
F_3 ( V_14 , V_18 ) ;
V_18 = V_23 [ V_19 ] [ V_5 ] ;
F_3 ( V_16 , V_18 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_24 = V_4 -> V_25 ;
unsigned int V_26 = ( V_4 -> V_27 != 0 ) ;
T_2 V_28 = V_24 ;
void T_1 * V_8 = V_2 -> V_9 -> V_10 [ V_11 ] ;
void T_1 * V_12 = V_8 + V_13 ;
void T_1 * V_29 = V_8 + V_30 ;
void T_1 * V_31 = V_8 + V_32 ;
void T_1 * V_33 = V_8 + V_34 ;
void T_1 * V_35 = V_8 + V_36 ;
void T_1 * V_37 = V_8 + V_38 ;
void T_1 * V_39 = V_8 + V_40 ;
int V_19 , V_41 ;
if ( F_2 ( V_12 ) & V_20 )
V_19 = 1 ;
else
V_19 = 0 ;
if ( V_28 >= V_42 )
V_41 = V_28 - V_42 ;
else
return;
if ( V_26 ) {
F_3 ( V_33 , V_43 [ V_19 ] [ V_41 ] ) ;
F_3 ( V_35 , V_44 [ V_19 ] [ V_41 ] ) ;
F_3 ( V_39 ,
( F_2 ( V_39 ) & ~ V_45 ) | ( V_46 [ V_19 ] [ V_41 ] << 2 ) ) ;
} else {
F_3 ( V_29 , V_43 [ V_19 ] [ V_41 ] ) ;
F_3 ( V_31 , V_44 [ V_19 ] [ V_41 ] ) ;
F_3 ( V_39 ,
( F_2 ( V_39 ) & ~ V_47 ) | V_46 [ V_19 ] [ V_41 ] ) ;
}
F_3 ( V_37 ,
V_48 [ V_19 ] [ V_41 ] << 16 | V_49 [ V_19 ] [ V_41 ] ) ;
}
unsigned long F_5 ( struct V_3 * V_4 , unsigned long V_50 )
{
if ( V_4 -> V_51 == V_52 &&
( V_50 & ( 0xE0 << V_53 ) ) ) {
F_6 ( V_54 L_1 , V_55 ) ;
V_50 &= ~ ( 0xE0 << V_53 ) ;
}
return V_50 ;
}
static void F_7 ( struct V_1 * V_2 , const struct V_56 * V_57 )
{
struct V_58 * V_59 = & V_2 -> V_59 ;
unsigned int V_60 = V_57 -> V_61 & V_62 ;
if ( V_57 -> V_63 != V_2 -> V_64 ) {
F_3 ( V_59 -> V_65 , V_57 -> V_63 ) ;
V_2 -> V_64 = V_57 -> V_63 ;
F_8 ( V_2 ) ;
}
if ( V_60 && ( V_57 -> V_61 & V_66 ) ) {
F_3 ( V_59 -> V_67 , V_57 -> V_68 ) ;
F_3 ( V_59 -> V_69 , V_57 -> V_70 ) ;
F_3 ( V_59 -> V_71 , V_57 -> V_72 ) ;
F_3 ( V_59 -> V_73 , V_57 -> V_74 ) ;
F_3 ( V_59 -> V_75 , V_57 -> V_76 ) ;
F_9 ( L_2 ,
V_57 -> V_68 ,
V_57 -> V_70 ,
V_57 -> V_72 ,
V_57 -> V_74 ,
V_57 -> V_76 ) ;
}
if ( V_60 ) {
F_3 ( V_59 -> V_67 , V_57 -> V_77 ) ;
F_3 ( V_59 -> V_69 , V_57 -> V_78 ) ;
F_3 ( V_59 -> V_71 , V_57 -> V_79 ) ;
F_3 ( V_59 -> V_73 , V_57 -> V_80 ) ;
F_3 ( V_59 -> V_75 , V_57 -> V_81 ) ;
F_9 ( L_3 ,
V_57 -> V_77 ,
V_57 -> V_78 ,
V_57 -> V_79 ,
V_57 -> V_80 ,
V_57 -> V_81 ) ;
}
if ( V_57 -> V_61 & V_82 ) {
F_3 ( V_59 -> V_83 , V_57 -> V_84 ) ;
F_9 ( L_4 , V_57 -> V_84 ) ;
}
F_8 ( V_2 ) ;
}
static T_2 F_10 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_59 . V_85 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
struct V_58 * V_59 = & V_2 -> V_59 ;
V_57 -> V_86 = F_10 ( V_2 ) ;
V_57 -> V_77 = F_2 ( V_59 -> V_87 ) ;
V_57 -> V_78 = F_2 ( V_59 -> V_69 ) ;
V_57 -> V_79 = F_2 ( V_59 -> V_71 ) ;
V_57 -> V_80 = F_2 ( V_59 -> V_73 ) ;
V_57 -> V_81 = F_2 ( V_59 -> V_75 ) ;
V_57 -> V_84 = F_2 ( V_59 -> V_83 ) ;
if ( V_57 -> V_61 & V_66 ) {
F_3 ( V_59 -> V_65 , V_57 -> V_63 | V_88 ) ;
V_57 -> V_68 = F_2 ( V_59 -> V_87 ) ;
V_57 -> V_70 = F_2 ( V_59 -> V_69 ) ;
V_57 -> V_72 = F_2 ( V_59 -> V_71 ) ;
V_57 -> V_74 = F_2 ( V_59 -> V_73 ) ;
V_57 -> V_76 = F_2 ( V_59 -> V_75 ) ;
F_3 ( V_59 -> V_65 , V_57 -> V_63 ) ;
V_2 -> V_64 = V_57 -> V_63 ;
}
}
static void F_12 ( struct V_1 * V_2 ,
const struct V_56 * V_57 )
{
F_13 ( L_5 , V_2 -> V_89 , V_57 -> V_86 ) ;
F_3 ( V_2 -> V_59 . V_90 , V_57 -> V_86 ) ;
F_14 ( V_2 ) ;
}
static T_2 F_15 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_59 . V_91 ) ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_84 )
{
T_2 V_92 ;
if ( V_84 == 0 )
V_92 = V_93 ;
else
V_92 = V_93 | V_94 ;
F_3 ( V_2 -> V_59 . V_83 , V_92 ) ;
F_14 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_2 V_63 )
{
F_3 ( V_2 -> V_59 . V_65 , V_63 ) ;
}
static void F_18 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_2 ;
unsigned int V_97 = ( V_96 -> V_57 . V_61 & V_98 ) ;
T_2 V_99 ;
void T_1 * V_100 = V_2 -> V_59 . V_101 ;
F_3 ( V_100 + V_102 , V_2 -> V_103 ) ;
V_99 = F_2 ( V_100 + V_104 ) ;
V_99 &= ~ ( V_105 | V_106 ) ;
if ( ! V_97 )
V_99 |= V_105 ;
F_3 ( V_100 + V_104 , V_99 ) ;
V_2 -> V_107 -> V_108 ( V_2 , & V_96 -> V_57 ) ;
}
static void F_19 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_2 ;
T_2 V_99 ;
void T_1 * V_100 = V_2 -> V_59 . V_101 ;
V_99 = F_2 ( V_100 + V_104 ) ;
F_3 ( V_100 + V_104 , V_99 | V_106 ) ;
}
static unsigned int F_20 ( struct V_1 * V_2 ,
unsigned int V_84 )
{
struct V_58 * V_59 = & V_2 -> V_59 ;
T_2 V_78 , V_79 ;
V_2 -> V_107 -> V_109 ( V_2 , V_84 ) ;
F_3 ( V_59 -> V_69 , 0x55 ) ;
F_3 ( V_59 -> V_71 , 0xaa ) ;
F_3 ( V_59 -> V_69 , 0xaa ) ;
F_3 ( V_59 -> V_71 , 0x55 ) ;
F_3 ( V_59 -> V_69 , 0x55 ) ;
F_3 ( V_59 -> V_71 , 0xaa ) ;
V_78 = F_2 ( V_59 -> V_69 ) ;
V_79 = F_2 ( V_59 -> V_71 ) ;
if ( ( V_78 == 0x55 ) && ( V_79 == 0xaa ) )
return 1 ;
return 0 ;
}
static int F_21 ( struct V_110 * V_111 , unsigned int V_112 ,
unsigned long V_113 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
struct V_58 * V_59 = & V_2 -> V_59 ;
unsigned int V_114 = V_112 & ( 1 << 0 ) ;
unsigned int V_115 = V_112 & ( 1 << 1 ) ;
int V_116 , V_117 = 0 ;
F_22 ( V_2 , 150 ) ;
V_116 = F_23 ( V_111 , V_113 ) ;
if ( V_116 )
return V_116 ;
if ( V_115 ) {
int V_118 ;
V_2 -> V_107 -> V_109 ( V_2 , 1 ) ;
for ( V_118 = 0 ; V_118 < 2 ; V_118 ++ ) {
T_2 V_78 , V_79 ;
V_78 = F_2 ( V_59 -> V_69 ) ;
V_79 = F_2 ( V_59 -> V_71 ) ;
if ( ( V_78 == 1 ) && ( V_79 == 1 ) )
break;
F_22 ( V_2 , 50 ) ;
}
V_116 = F_23 ( V_111 , V_113 ) ;
if ( V_116 ) {
if ( V_116 != - V_119 )
return V_116 ;
V_117 = V_116 ;
}
}
V_2 -> V_107 -> V_109 ( V_2 , 0 ) ;
if ( V_115 )
V_2 -> V_107 -> V_109 ( V_2 , 1 ) ;
if ( V_114 )
V_2 -> V_107 -> V_109 ( V_2 , 0 ) ;
return V_117 ;
}
static unsigned int F_24 ( struct V_1 * V_2 , unsigned int V_112 ,
unsigned long V_113 )
{
struct V_58 * V_59 = & V_2 -> V_59 ;
F_13 ( L_6 , V_2 -> V_89 ) ;
F_3 ( V_59 -> V_65 , V_2 -> V_63 ) ;
F_25 ( 20 ) ;
F_3 ( V_59 -> V_65 , V_2 -> V_63 | V_120 ) ;
F_25 ( 20 ) ;
F_3 ( V_59 -> V_65 , V_2 -> V_63 ) ;
F_21 ( & V_2 -> V_111 , V_112 , V_113 ) ;
return 0 ;
}
static int F_26 ( struct V_110 * V_111 , unsigned int * V_121 ,
unsigned long V_113 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
unsigned int V_122 = V_2 -> V_61 & V_123 ;
unsigned int V_112 = 0 , V_124 ;
T_2 V_125 ;
F_13 ( L_7 ) ;
if ( F_20 ( V_2 , 0 ) )
V_112 |= ( 1 << 0 ) ;
if ( V_122 && F_20 ( V_2 , 1 ) )
V_112 |= ( 1 << 1 ) ;
V_2 -> V_107 -> V_109 ( V_2 , 0 ) ;
F_13 ( L_8 , V_112 ) ;
V_124 = F_24 ( V_2 , V_112 , V_113 ) ;
if ( V_124 ) {
F_27 ( V_2 , L_9 , V_124 ) ;
return - V_126 ;
}
V_121 [ 0 ] = F_28 ( & V_2 -> V_111 . V_84 [ 0 ] ,
V_112 & ( 1 << 0 ) , & V_125 ) ;
if ( V_122 && V_125 != 0x81 )
V_121 [ 1 ] = F_28 ( & V_2 -> V_111 . V_84 [ 1 ] ,
V_112 & ( 1 << 1 ) , & V_125 ) ;
F_13 ( L_10 , V_121 [ 0 ] , V_121 [ 1 ] ) ;
return 0 ;
}
static void F_29 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_2 ;
void T_1 * V_8 = V_2 -> V_9 -> V_10 [ V_11 ] ;
void T_1 * V_127 = V_2 -> V_9 -> V_10 [ V_128 ] ;
T_3 V_18 ;
while ( 1 ) {
V_18 = F_2 ( V_127 + V_129 ) ;
if ( V_18 & V_130 ) {
F_6 ( V_131 L_11 , V_55 ) ;
F_3 ( V_127 + V_129 , V_130 | V_132 ) ;
F_3 ( V_127 + V_104 ,
F_2 ( V_127 + V_104 ) & ~ V_106 ) ;
continue;
}
if ( V_18 & V_133 ) {
T_3 V_134 , V_135 ;
V_134 = F_2 ( V_8 + V_136 ) ;
V_135 = F_2 ( V_8 + V_137 ) ;
F_6 ( V_131 L_12 , V_55 , V_134 , V_135 ) ;
F_3 ( V_127 + V_129 , V_133 | V_132 ) ;
F_3 ( V_127 + V_104 ,
F_2 ( V_127 + V_104 ) & ~ V_106 ) ;
continue;
}
if ( V_18 & V_138 ) {
F_6 ( V_131 L_13 , V_55 ) ;
F_3 ( V_127 + V_129 , V_138 | V_132 ) ;
F_3 ( V_127 + V_104 ,
F_2 ( V_127 + V_104 ) & ~ V_106 ) ;
continue;
}
if ( V_18 & V_139 ) {
F_3 ( V_127 + V_104 ,
F_2 ( V_127 + V_104 ) & ~ V_106 ) ;
F_6 ( V_131 L_14 , V_55 ) ;
F_3 ( V_127 + V_129 , V_139 | V_132 ) ;
continue;
}
if ( V_18 & V_132 ) {
unsigned int V_121 ;
unsigned long V_113 = F_30 ( V_140 , V_141 ) ;
F_6 ( V_131 L_15 , V_55 ) ;
F_3 ( V_127 + V_129 , V_132 ) ;
F_26 ( & V_2 -> V_111 , & V_121 , V_113 ) ;
continue;
}
if ( V_18 & V_142 ) {
F_3 ( V_127 + V_129 , V_142 ) ;
continue;
}
if ( V_18 & V_143 ) {
F_3 ( V_127 + V_129 , V_143 ) ;
continue;
}
if ( V_18 & V_144 ) {
F_3 ( V_127 + V_129 , V_144 ) ;
continue;
}
break;
}
F_3 ( V_127 + V_104 ,
F_2 ( V_127 + V_104 ) & ~ V_106 ) ;
F_31 ( V_2 ) ;
}
static T_2 F_32 ( struct V_1 * V_2 )
{
void T_1 * V_100 = V_2 -> V_59 . V_101 ;
T_2 V_145 = F_2 ( V_100 + V_146 ) ;
T_3 V_147 = F_2 ( V_100 + V_129 ) ;
struct V_95 * V_96 = F_33 ( V_2 , V_2 -> V_111 . V_148 ) ;
static int V_149 = 0 ;
if ( ! ( F_2 ( V_100 + V_104 ) & V_106 ) )
return V_145 ;
if ( ( F_15 ( V_2 ) & V_150 )
&& ( V_147 & V_151 ) )
return ( V_145 | V_152 ) ;
if ( V_147 & V_144 ) {
V_145 |= V_152 ;
if ( ( V_96 -> V_57 . V_153 == V_154 &&
V_96 -> V_155 -> V_156 > V_157 ) ) {
if ( ! ( V_147 & V_143 ) ) {
F_6 ( V_131 L_16 ,
V_2 -> V_89 ) ;
V_145 |= V_158 ;
if ( V_149 ++ )
V_2 -> V_159 &= ~ ( 1 << V_96 -> V_155 -> V_156 ) ;
} else
V_149 = 0 ;
}
}
return V_145 ;
}
static unsigned int F_34 ( struct V_3 * V_155 , unsigned char * V_160 ,
unsigned int V_161 , int V_97 )
{
struct V_1 * V_2 = V_155 -> V_111 -> V_2 ;
unsigned int V_162 = V_161 >> 1 ;
unsigned int V_118 ;
T_4 * V_163 = ( T_4 * ) V_160 ;
void T_1 * V_100 = V_2 -> V_59 . V_164 ;
if ( V_97 == V_165 )
for ( V_118 = 0 ; V_118 < V_162 ; V_118 ++ )
V_163 [ V_118 ] = F_35 ( F_2 ( V_100 ) ) ;
else
for ( V_118 = 0 ; V_118 < V_162 ; V_118 ++ )
F_3 ( V_100 , F_36 ( V_163 [ V_118 ] ) ) ;
if ( F_37 ( V_161 & 0x01 ) ) {
T_4 V_166 [ 1 ] = { 0 } ;
unsigned char * V_167 = V_160 + V_161 - 1 ;
if ( V_97 == V_165 ) {
V_166 [ 0 ] = F_35 ( F_2 ( V_100 ) ) ;
memcpy ( V_167 , V_166 , 1 ) ;
} else {
memcpy ( V_166 , V_167 , 1 ) ;
F_3 ( V_100 , F_36 ( V_166 [ 0 ] ) ) ;
}
V_162 ++ ;
}
return V_162 << 1 ;
}
static void F_38 ( struct V_110 * V_111 , unsigned int * V_121 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
F_13 ( L_7 ) ;
if ( V_121 [ 0 ] != V_168 )
V_2 -> V_107 -> V_109 ( V_2 , 1 ) ;
if ( V_121 [ 1 ] != V_168 )
V_2 -> V_107 -> V_109 ( V_2 , 0 ) ;
if ( V_121 [ 0 ] == V_168 && V_121 [ 1 ] == V_168 ) {
F_13 ( L_17 ) ;
return;
}
F_3 ( V_2 -> V_59 . V_65 , V_2 -> V_63 ) ;
F_13 ( L_18 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
void T_1 * V_100 = V_2 -> V_59 . V_101 ;
if ( ! V_100 )
return;
F_3 ( V_100 + V_146 , F_2 ( V_100 + V_146 ) ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
void T_1 * V_100 = V_2 -> V_59 . V_101 ;
int V_116 ;
V_116 = F_41 ( V_2 ) ;
if ( V_116 )
return V_116 ;
F_3 ( V_100 + V_169 , V_2 -> V_103 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
void T_1 * V_100 = V_2 -> V_59 . V_101 ;
F_3 ( V_100 + V_169 , 0 ) ;
}
static int F_43 ( struct V_170 * V_9 )
{
void T_1 * V_8 = V_9 -> V_10 [ V_11 ] ;
void T_1 * V_127 = V_9 -> V_10 [ V_128 ] ;
void T_1 * V_12 = V_8 + V_13 ;
void T_1 * V_171 = V_8 + V_172 ;
void T_1 * V_173 = V_8 + V_174 ;
void T_1 * V_175 = V_127 + V_176 ;
void T_1 * V_177 = V_127 + V_146 ;
T_3 V_18 = 0 ;
F_3 ( V_12 , V_18 ) ;
V_18 |= V_20 ;
F_3 ( V_12 , V_18 ) ;
V_18 |= V_178 | V_179 ;
F_3 ( V_12 , V_18 ) ;
V_18 |= V_180 ;
F_3 ( V_12 , V_18 ) ;
for (; ; ) {
V_18 = F_2 ( V_12 ) ;
if ( V_18 & V_180 )
break;
F_25 ( 5000 ) ;
}
V_18 |= V_181 ;
F_3 ( V_12 , V_18 ) ;
F_3 ( V_173 , V_182 ) ;
F_3 ( V_171 , V_183 ) ;
F_3 ( V_175 , V_184 ) ;
if ( F_2 ( V_177 ) & V_185 ) {
F_6 ( V_131 L_19 , V_55 ) ;
return - V_126 ;
}
return 0 ;
}
static void F_44 ( struct V_58 * V_59 , void T_1 * V_186 )
{
V_59 -> V_187 = V_186 + V_188 ;
V_59 -> V_91 = V_59 -> V_187 + V_189 ;
V_59 -> V_65 = V_59 -> V_187 + V_189 ;
V_59 -> V_101 = V_186 ;
V_59 -> V_164 = V_59 -> V_187 + V_190 ;
V_59 -> V_87 = V_59 -> V_187 + V_191 ;
V_59 -> V_67 = V_59 -> V_187 + V_192 ;
V_59 -> V_69 = V_59 -> V_187 + V_193 ;
V_59 -> V_71 = V_59 -> V_187 + V_194 ;
V_59 -> V_73 = V_59 -> V_187 + V_195 ;
V_59 -> V_75 = V_59 -> V_187 + V_196 ;
V_59 -> V_83 = V_59 -> V_187 + V_197 ;
V_59 -> V_85 = V_59 -> V_187 + V_198 ;
V_59 -> V_90 = V_59 -> V_187 + V_199 ;
}
static int F_45 ( struct V_170 * V_9 )
{
struct V_200 * V_201 = F_46 ( V_9 -> V_155 ) ;
int V_116 ;
V_116 = F_43 ( V_9 ) ;
if ( V_116 )
return V_116 ;
V_116 = F_47 ( V_201 , V_202 ) ;
if ( V_116 )
return V_116 ;
V_116 = F_48 ( V_201 , V_202 ) ;
if ( V_116 )
return V_116 ;
F_44 ( & V_9 -> V_203 [ 0 ] -> V_59 , V_9 -> V_10 [ V_128 ] ) ;
F_49 ( V_201 ) ;
return 0 ;
}
static int F_50 ( struct V_200 * V_201 , const struct V_204 * V_205 )
{
unsigned int V_206 = ( unsigned int ) V_205 -> V_207 ;
const struct V_208 * V_209 [] = { & V_210 [ V_206 ] , NULL } ;
struct V_170 * V_9 ;
int V_116 ;
F_51 ( & V_201 -> V_155 , V_211 ) ;
V_9 = F_52 ( & V_201 -> V_155 , V_209 , 1 ) ;
if ( ! V_9 )
return - V_212 ;
V_116 = F_53 ( V_201 ) ;
if ( V_116 )
return V_116 ;
V_116 = F_54 ( V_201 , ( 1 << V_11 ) | ( 1 << V_128 ) , V_55 ) ;
if ( V_116 == - V_213 )
F_55 ( V_201 ) ;
if ( V_116 )
return V_116 ;
V_9 -> V_10 = F_56 ( V_201 ) ;
F_57 ( V_9 -> V_203 [ 0 ] , V_11 , - 1 , L_20 ) ;
F_57 ( V_9 -> V_203 [ 0 ] , V_128 , - 1 , L_21 ) ;
V_116 = F_45 ( V_9 ) ;
if ( V_116 )
return V_116 ;
return F_58 ( V_9 , V_201 -> V_214 , V_215 ,
V_216 , & V_217 ) ;
}
