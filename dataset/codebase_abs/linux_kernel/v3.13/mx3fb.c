static T_1 F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
T_2 V_3 ;
V_3 = F_1 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_3 | V_9 , V_8 ) ;
}
static T_2 F_6 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
T_2 V_3 ;
V_3 = F_1 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_3 & ~ V_9 , V_8 ) ;
return V_3 & V_9 ;
}
static void F_7 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 = V_10 -> V_11 ;
struct V_13 * V_13 = & V_12 -> V_13 ;
unsigned long V_14 ;
T_3 V_15 ;
if ( V_10 -> V_16 )
F_8 ( V_2 -> V_17 , L_1 , V_10 ,
F_9 ( V_10 -> V_16 ) , F_9 ( V_10 -> V_16 ) -> V_18 ) ;
else
F_8 ( V_2 -> V_17 , L_2 , V_10 ) ;
if ( V_10 -> V_15 < 0 ) {
V_10 -> V_16 = F_10 ( V_13 ,
& V_10 -> V_18 [ 0 ] , 1 , V_19 , V_20 ) ;
if ( ! V_10 -> V_16 ) {
F_11 ( V_2 -> V_17 , L_3 ,
V_13 -> V_21 ) ;
return;
}
V_10 -> V_16 -> V_22 = V_10 -> V_16 ;
V_10 -> V_16 -> V_23 = V_24 ;
V_15 = V_10 -> V_16 -> V_25 ( V_10 -> V_16 ) ;
F_8 ( V_2 -> V_17 , L_4 , __LINE__ ,
V_10 -> V_16 , V_15 , F_12 ( & V_12 -> V_26 ) ? '-' : '+' ) ;
} else {
if ( ! V_10 -> V_16 || ! V_10 -> V_16 -> V_25 ) {
F_11 ( V_2 -> V_17 , L_5 ,
V_13 -> V_21 ) ;
return;
}
F_13 ( V_13 ) ;
V_15 = V_10 -> V_15 ;
F_8 ( V_2 -> V_17 , L_6 , __LINE__ ,
V_10 -> V_16 , V_15 , F_12 ( & V_12 -> V_26 ) ? '-' : '+' ) ;
}
if ( V_15 >= 0 ) {
F_14 ( & V_2 -> V_27 , V_14 ) ;
F_5 ( V_10 ) ;
V_10 -> V_15 = V_15 ;
F_15 ( & V_2 -> V_27 , V_14 ) ;
}
F_16 ( 2 ) ;
}
static void F_17 ( struct V_6 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_28 ;
unsigned long V_14 ;
if ( V_10 -> V_16 == NULL )
return;
F_14 ( & V_2 -> V_27 , V_14 ) ;
V_28 = F_6 ( V_10 ) ;
F_15 ( & V_2 -> V_27 , V_14 ) ;
V_10 -> V_16 -> V_29 -> V_30 -> V_31 ( V_10 -> V_16 -> V_29 ,
V_32 , 0 ) ;
V_10 -> V_16 = NULL ;
V_10 -> V_15 = - V_33 ;
}
static int F_18 ( struct V_1 * V_2 , enum V_34 V_35 ,
T_4 V_36 , T_4 V_37 )
{
if ( V_35 != V_38 )
return - V_33 ;
V_36 += V_2 -> V_39 ;
V_37 += V_2 -> V_40 ;
F_3 ( V_2 , ( V_36 << 16 ) | V_37 , V_41 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , enum V_42 V_43 ,
T_2 V_44 ,
T_5 V_45 , T_5 V_46 ,
T_5 V_39 , T_5 V_47 ,
T_5 V_48 , T_5 V_40 ,
T_5 V_49 , T_5 V_50 ,
struct V_51 V_52 )
{
unsigned long V_53 ;
T_2 V_3 ;
T_2 V_54 ;
T_2 div ;
struct V_55 * V_56 ;
const struct V_57 * V_58 ;
F_8 ( V_2 -> V_17 , L_7 , V_45 , V_46 ) ;
if ( V_49 == 0 || V_47 == 0 )
return - V_33 ;
V_3 = ( ( T_2 ) ( V_47 - 1 ) << 26 ) |
( ( T_2 ) ( V_45 + V_39 + V_48 - 1 ) << 16 ) ;
F_3 ( V_2 , V_3 , V_59 ) ;
#ifdef F_20
F_21 ( V_60 L_8 , V_3 ) ;
#endif
V_3 = ( ( T_2 ) ( V_49 - 1 ) << 26 ) | V_61 |
( ( T_2 ) ( V_46 + V_40 + V_50 - 1 ) << 16 ) ;
F_3 ( V_2 , V_3 , V_62 ) ;
#ifdef F_20
F_21 ( V_60 L_9 , V_3 ) ;
#endif
V_2 -> V_39 = V_39 ;
V_2 -> V_40 = V_40 ;
switch ( V_43 ) {
case V_63 :
F_3 ( V_2 , 0x00FD0102L , V_64 ) ;
F_3 ( V_2 , 0x00F500F4L , V_65 ) ;
F_3 ( V_2 , V_66 | V_67 , V_8 ) ;
break;
case V_68 :
F_3 ( V_2 , V_67 , V_8 ) ;
break;
default:
return - V_33 ;
}
V_56 = F_22 ( V_2 -> V_17 , NULL ) ;
if ( ! F_23 ( V_56 ) ) {
div = F_24 ( V_56 ) * 16 / V_44 ;
F_25 ( V_56 ) ;
} else {
div = 0 ;
}
if ( div < 0x40 ) {
F_8 ( V_2 -> V_17 ,
L_10 ) ;
div = 0x40 ;
}
F_8 ( V_2 -> V_17 , L_11 ,
V_44 , div >> 4 , ( div & 7 ) * 125 ) ;
F_14 ( & V_2 -> V_27 , V_53 ) ;
F_3 ( V_2 , ( ( ( div / 8 ) - 1 ) << 22 ) | div , V_69 ) ;
V_54 = F_1 ( V_2 , V_70 ) & 0x78FFFFFF ;
V_54 |= V_52 . V_71 << V_72 |
V_52 . V_73 << V_74 |
V_52 . V_75 << V_76 ;
F_3 ( V_2 , V_54 , V_70 ) ;
V_54 = F_1 ( V_2 , V_77 ) & 0xE0FFFFFF ;
V_54 |= V_52 . V_78 << V_79 |
V_52 . V_80 << V_81 |
V_52 . V_82 << V_83 |
V_52 . V_84 << V_85 |
V_52 . V_86 << V_87 ;
F_3 ( V_2 , V_54 , V_77 ) ;
V_58 = & V_88 [ V_2 -> V_89 ] ;
F_3 ( V_2 , V_58 -> V_90 , V_91 ) ;
F_3 ( V_2 , V_58 -> V_92 , V_93 ) ;
F_3 ( V_2 , V_58 -> V_94 , V_95 ) ;
F_15 ( & V_2 -> V_27 , V_53 ) ;
F_8 ( V_2 -> V_17 , L_12 ,
F_1 ( V_2 , V_70 ) ) ;
F_8 ( V_2 -> V_17 , L_13 ,
F_1 ( V_2 , V_77 ) ) ;
F_8 ( V_2 -> V_17 , L_14 ,
F_1 ( V_2 , V_69 ) ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , enum V_34 V_35 ,
bool V_96 , T_2 V_97 )
{
T_2 V_3 , V_98 ;
unsigned long V_53 ;
F_14 ( & V_2 -> V_27 , V_53 ) ;
V_98 = F_1 ( V_2 , V_8 ) ;
if ( V_35 == V_38 )
V_98 &= ~ V_99 ;
else
V_98 |= V_99 ;
if ( V_96 ) {
V_3 = F_1 ( V_2 , V_100 ) & 0xFF000000L ;
F_3 ( V_2 , V_3 | ( V_97 & 0x00FFFFFFL ) ,
V_100 ) ;
V_98 |= V_101 ;
} else {
V_98 &= ~ V_101 ;
}
F_3 ( V_2 , V_98 , V_8 ) ;
F_15 ( & V_2 -> V_27 , V_53 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , bool V_96 , T_6 V_102 )
{
T_2 V_3 ;
unsigned long V_53 ;
F_14 ( & V_2 -> V_27 , V_53 ) ;
if ( V_96 ) {
V_3 = F_1 ( V_2 , V_100 ) & 0x00FFFFFFL ;
F_3 ( V_2 , V_3 | ( ( T_2 ) V_102 << 24 ) , V_100 ) ;
V_3 = F_1 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_3 | V_103 , V_8 ) ;
} else {
V_3 = F_1 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_3 & ~ V_103 , V_8 ) ;
}
F_15 ( & V_2 -> V_27 , V_53 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , T_6 V_5 )
{
F_8 ( V_2 -> V_17 , L_15 , V_104 , V_5 ) ;
F_3 ( V_2 , 0x03000000UL | V_5 << 16 , V_105 ) ;
return;
}
static T_2 F_29 ( int V_106 )
{
T_2 V_107 = 0 ;
switch ( V_106 ) {
case 24 :
V_107 = V_108 ;
break;
case 32 :
V_107 = V_109 ;
break;
case 16 :
V_107 = V_110 ;
break;
}
return V_107 ;
}
static int F_30 ( struct V_111 * V_7 )
{
struct V_112 * V_113 = & V_7 -> V_113 ;
struct V_114 * V_115 = & V_7 -> V_115 ;
strncpy ( V_113 -> V_116 , L_16 , 8 ) ;
V_113 -> V_117 = V_115 -> V_118 * V_115 -> V_119 / 8 ;
V_113 -> type = V_120 ;
V_113 -> V_121 = V_122 ;
V_113 -> V_123 = V_124 ;
V_113 -> V_125 = 1 ;
V_113 -> V_126 = 1 ;
return 0 ;
}
static void V_24 ( void * V_127 )
{
struct V_128 * V_129 = F_9 ( V_127 ) ;
struct V_13 * V_29 = V_129 -> V_16 . V_29 ;
struct V_11 * V_130 = F_31 ( V_29 ) ;
struct V_1 * V_2 = V_130 -> V_131 ;
struct V_6 * V_10 = V_2 -> V_7 -> V_132 ;
F_8 ( V_2 -> V_17 , L_17 , V_130 -> V_133 ) ;
F_32 ( V_130 -> V_133 ) ;
F_33 ( & V_10 -> V_134 ) ;
}
static bool F_34 ( struct V_111 * V_7 )
{
struct V_6 * V_10 = V_7 -> V_132 ;
struct V_114 V_135 = V_10 -> V_136 ;
struct V_114 V_137 = V_7 -> V_115 ;
if ( ( V_7 -> V_115 . V_138 & V_139 ) &&
( V_7 -> V_115 . V_138 & V_140 ) == V_141 )
return true ;
V_135 . V_142 = V_137 . V_142 ;
V_135 . V_143 = V_137 . V_143 ;
return ! ! memcmp ( & V_135 , & V_137 , sizeof( struct V_114 ) ) ;
}
static int F_35 ( struct V_111 * V_7 , bool V_27 )
{
T_1 V_144 , V_145 , V_146 ;
struct V_51 V_147 ;
enum V_42 V_148 = V_68 ;
struct V_6 * V_10 = V_7 -> V_132 ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 = V_10 -> V_11 ;
struct V_149 * V_150 = & V_12 -> V_151 . V_150 ;
struct V_152 * V_18 = V_10 -> V_18 ;
if ( V_10 -> V_16 )
F_17 ( V_10 ) ;
F_30 ( V_7 ) ;
V_144 = V_7 -> V_115 . V_153 * V_7 -> V_113 . V_117 ;
if ( V_144 > V_7 -> V_113 . V_154 ) {
if ( V_7 -> V_113 . V_155 )
F_36 ( V_7 ) ;
if ( F_37 ( V_7 , V_144 , V_27 ) < 0 )
return - V_156 ;
}
F_38 ( & V_18 [ 0 ] , 1 ) ;
F_38 ( & V_18 [ 1 ] , 1 ) ;
F_39 ( & V_18 [ 0 ] ) = V_7 -> V_113 . V_155 ;
F_40 ( & V_18 [ 0 ] , F_41 ( V_7 -> V_157 ) ,
V_7 -> V_113 . V_154 ,
F_42 ( V_7 -> V_157 ) ) ;
if ( V_10 -> V_158 == V_38 ) {
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
if ( V_7 -> V_115 . V_159 & V_160 )
V_147 . V_84 = true ;
if ( V_7 -> V_115 . V_159 & V_161 )
V_147 . V_86 = true ;
if ( V_7 -> V_115 . V_159 & V_162 )
V_147 . V_80 = true ;
if ( V_7 -> V_115 . V_159 & V_163 )
V_147 . V_78 = true ;
if ( V_7 -> V_115 . V_159 & V_164 )
V_147 . V_82 = true ;
if ( V_7 -> V_115 . V_159 & V_165 )
V_147 . V_75 = true ;
if ( V_7 -> V_115 . V_159 & V_166 )
V_147 . V_73 = true ;
if ( V_7 -> V_115 . V_159 & V_167 )
V_148 = V_63 ;
F_8 ( V_7 -> V_30 , L_18 ,
( T_1 ) ( F_43 ( V_7 -> V_115 . V_168 ) * 1000UL ) ) ;
if ( F_19 ( V_2 , V_148 ,
( F_43 ( V_7 -> V_115 . V_168 ) ) * 1000UL ,
V_7 -> V_115 . V_169 , V_7 -> V_115 . V_170 ,
V_7 -> V_115 . V_171 ,
V_7 -> V_115 . V_172 ,
V_7 -> V_115 . V_173 +
V_7 -> V_115 . V_172 ,
V_7 -> V_115 . V_174 ,
V_7 -> V_115 . V_175 ,
V_7 -> V_115 . V_176 +
V_7 -> V_115 . V_175 , V_147 ) != 0 ) {
F_11 ( V_7 -> V_30 ,
L_19 ) ;
return - V_33 ;
}
}
F_18 ( V_2 , V_10 -> V_158 , 0 , 0 ) ;
V_10 -> V_177 = 0 ;
V_150 -> V_178 = F_29 ( V_7 -> V_115 . V_119 ) ;
V_150 -> V_179 = V_7 -> V_115 . V_169 ;
V_150 -> V_180 = V_7 -> V_115 . V_170 ;
V_150 -> V_181 = V_7 -> V_115 . V_118 ;
if ( V_10 -> V_182 == V_183 ) {
F_7 ( V_10 ) ;
V_10 -> V_136 . V_142 = 0 ;
V_10 -> V_136 . V_143 = 0 ;
}
V_145 = V_10 -> V_136 . V_142 ;
V_146 = V_10 -> V_136 . V_143 ;
V_10 -> V_136 = V_7 -> V_115 ;
V_10 -> V_136 . V_142 = V_145 ;
V_10 -> V_136 . V_143 = V_146 ;
return 0 ;
}
static int F_44 ( struct V_111 * V_7 )
{
struct V_6 * V_10 = V_7 -> V_132 ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 = V_10 -> V_11 ;
int V_184 ;
F_8 ( V_2 -> V_17 , L_20 , V_104 , F_12 ( & V_12 -> V_26 ) ? '-' : '+' ) ;
F_45 ( & V_10 -> V_185 ) ;
V_184 = F_34 ( V_7 ) ? F_35 ( V_7 , true ) : 0 ;
F_46 ( & V_10 -> V_185 ) ;
return V_184 ;
}
static int F_47 ( struct V_114 * V_115 , struct V_111 * V_7 )
{
struct V_6 * V_10 = V_7 -> V_132 ;
T_1 V_186 ;
T_1 V_187 ;
F_8 ( V_7 -> V_30 , L_21 , V_104 ) ;
if ( V_115 -> V_118 < V_115 -> V_169 )
V_115 -> V_118 = V_115 -> V_169 ;
if ( V_115 -> V_153 < V_115 -> V_170 )
V_115 -> V_153 = V_115 -> V_170 ;
if ( ( V_115 -> V_119 != 32 ) && ( V_115 -> V_119 != 24 ) &&
( V_115 -> V_119 != 16 ) )
V_115 -> V_119 = V_188 ;
switch ( V_115 -> V_119 ) {
case 16 :
V_115 -> V_189 . V_190 = 5 ;
V_115 -> V_189 . V_191 = 11 ;
V_115 -> V_189 . V_192 = 0 ;
V_115 -> V_193 . V_190 = 6 ;
V_115 -> V_193 . V_191 = 5 ;
V_115 -> V_193 . V_192 = 0 ;
V_115 -> V_194 . V_190 = 5 ;
V_115 -> V_194 . V_191 = 0 ;
V_115 -> V_194 . V_192 = 0 ;
V_115 -> V_195 . V_190 = 0 ;
V_115 -> V_195 . V_191 = 0 ;
V_115 -> V_195 . V_192 = 0 ;
break;
case 24 :
V_115 -> V_189 . V_190 = 8 ;
V_115 -> V_189 . V_191 = 16 ;
V_115 -> V_189 . V_192 = 0 ;
V_115 -> V_193 . V_190 = 8 ;
V_115 -> V_193 . V_191 = 8 ;
V_115 -> V_193 . V_192 = 0 ;
V_115 -> V_194 . V_190 = 8 ;
V_115 -> V_194 . V_191 = 0 ;
V_115 -> V_194 . V_192 = 0 ;
V_115 -> V_195 . V_190 = 0 ;
V_115 -> V_195 . V_191 = 0 ;
V_115 -> V_195 . V_192 = 0 ;
break;
case 32 :
V_115 -> V_189 . V_190 = 8 ;
V_115 -> V_189 . V_191 = 16 ;
V_115 -> V_189 . V_192 = 0 ;
V_115 -> V_193 . V_190 = 8 ;
V_115 -> V_193 . V_191 = 8 ;
V_115 -> V_193 . V_192 = 0 ;
V_115 -> V_194 . V_190 = 8 ;
V_115 -> V_194 . V_191 = 0 ;
V_115 -> V_194 . V_192 = 0 ;
V_115 -> V_195 . V_190 = 8 ;
V_115 -> V_195 . V_191 = 24 ;
V_115 -> V_195 . V_192 = 0 ;
break;
}
if ( V_115 -> V_168 < 1000 ) {
V_187 = V_115 -> V_169 + V_115 -> V_173 + V_115 -> V_172 +
V_115 -> V_171 ;
V_186 = V_115 -> V_170 + V_115 -> V_176 + V_115 -> V_175 +
V_115 -> V_174 ;
V_115 -> V_168 = ( V_186 * V_187 * 6UL ) / 100UL ;
V_115 -> V_168 = F_48 ( V_115 -> V_168 ) ;
F_8 ( V_7 -> V_30 , L_22 ,
V_115 -> V_168 ) ;
}
V_115 -> V_46 = - 1 ;
V_115 -> V_45 = - 1 ;
V_115 -> V_196 = 0 ;
V_115 -> V_159 |= V_10 -> V_136 . V_159 ;
V_10 -> V_136 . V_159 |= V_115 -> V_159 ;
return 0 ;
}
static T_1 F_49 ( unsigned int V_29 , struct V_197 * V_198 )
{
V_29 &= 0xffff ;
V_29 >>= 16 - V_198 -> V_190 ;
return V_29 << V_198 -> V_191 ;
}
static int F_50 ( unsigned int V_199 , unsigned int V_189 ,
unsigned int V_193 , unsigned int V_194 ,
unsigned int V_200 , struct V_111 * V_7 )
{
struct V_6 * V_10 = V_7 -> V_132 ;
T_1 V_201 ;
int V_184 = 1 ;
F_8 ( V_7 -> V_30 , L_23 , V_104 , V_199 ) ;
F_45 ( & V_10 -> V_185 ) ;
if ( V_7 -> V_115 . V_196 )
V_189 = V_193 = V_194 = ( 19595 * V_189 + 38470 * V_193 +
7471 * V_194 ) >> 16 ;
switch ( V_7 -> V_113 . V_123 ) {
case V_124 :
if ( V_199 < 16 ) {
T_1 * V_202 = V_7 -> V_203 ;
V_201 = F_49 ( V_189 , & V_7 -> V_115 . V_189 ) ;
V_201 |= F_49 ( V_193 , & V_7 -> V_115 . V_193 ) ;
V_201 |= F_49 ( V_194 , & V_7 -> V_115 . V_194 ) ;
V_202 [ V_199 ] = V_201 ;
V_184 = 0 ;
}
break;
case V_204 :
case V_205 :
break;
}
F_46 ( & V_10 -> V_185 ) ;
return V_184 ;
}
static void F_51 ( int V_182 , struct V_111 * V_7 )
{
struct V_6 * V_10 = V_7 -> V_132 ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_206 = V_10 -> V_182 ;
V_10 -> V_182 = V_182 ;
if ( V_182 > V_183 && V_206 > V_183 )
return;
switch ( V_182 ) {
case V_207 :
case V_208 :
case V_209 :
case V_210 :
F_28 ( V_2 , 0 ) ;
memset ( ( char * ) V_7 -> V_157 , 0 , V_7 -> V_113 . V_154 ) ;
F_16 ( 25 ) ;
F_17 ( V_10 ) ;
break;
case V_183 :
F_7 ( V_10 ) ;
F_28 ( V_2 , V_2 -> V_211 ) ;
break;
}
}
static int F_52 ( int V_182 , struct V_111 * V_7 )
{
struct V_6 * V_10 = V_7 -> V_132 ;
F_8 ( V_7 -> V_30 , L_24 , V_104 ,
V_182 , V_7 -> V_157 , V_7 -> V_113 . V_154 ) ;
if ( V_10 -> V_182 == V_182 )
return 0 ;
F_45 ( & V_10 -> V_185 ) ;
F_51 ( V_182 , V_7 ) ;
F_46 ( & V_10 -> V_185 ) ;
return 0 ;
}
static int F_53 ( struct V_114 * V_115 ,
struct V_111 * V_7 )
{
struct V_6 * V_10 = V_7 -> V_132 ;
T_1 V_212 ;
unsigned long V_213 ;
T_7 V_191 ;
T_3 V_15 ;
struct V_152 * V_18 = V_10 -> V_18 ;
struct V_13 * V_13 = & V_10 -> V_11 -> V_13 ;
struct V_214 * V_16 ;
int V_184 ;
F_8 ( V_7 -> V_30 , L_20 , V_104 ,
F_12 ( & V_10 -> V_11 -> V_26 ) ? '-' : '+' ) ;
if ( V_115 -> V_142 > 0 ) {
F_8 ( V_7 -> V_30 , L_25 ) ;
return - V_33 ;
}
if ( V_10 -> V_136 . V_142 == V_115 -> V_142 &&
V_10 -> V_136 . V_143 == V_115 -> V_143 )
return 0 ;
V_212 = V_115 -> V_143 ;
if ( ! ( V_115 -> V_215 & V_216 ) )
V_212 += V_7 -> V_115 . V_170 ;
if ( V_212 > V_7 -> V_115 . V_153 )
return - V_33 ;
F_45 ( & V_10 -> V_185 ) ;
V_191 = V_115 -> V_143 * V_7 -> V_113 . V_117
+ V_115 -> V_142 * ( V_7 -> V_115 . V_119 / 8 ) ;
V_213 = V_7 -> V_113 . V_155 + V_191 ;
F_8 ( V_7 -> V_30 , L_26 ,
V_10 -> V_177 , V_213 ) ;
F_54 ( & V_10 -> V_134 ) ;
F_55 ( V_10 -> V_11 -> V_133 ) ;
V_184 = F_56 ( & V_10 -> V_134 , V_217 / 10 ) ;
if ( V_184 <= 0 ) {
F_46 ( & V_10 -> V_185 ) ;
F_57 ( V_7 -> V_30 , L_27 , V_184 < 0 ?
L_28 : L_29 ) ;
F_58 ( V_10 -> V_11 -> V_133 ) ;
return V_184 ? : - V_218 ;
}
V_10 -> V_177 = ! V_10 -> V_177 ;
F_39 ( & V_18 [ V_10 -> V_177 ] ) = V_213 ;
F_40 ( & V_18 [ V_10 -> V_177 ] ,
F_41 ( V_7 -> V_157 + V_191 ) , V_7 -> V_113 . V_154 ,
F_42 ( V_7 -> V_157 + V_191 ) ) ;
if ( V_10 -> V_16 )
F_59 ( V_10 -> V_16 ) ;
V_16 = F_10 ( V_13 , V_18 +
V_10 -> V_177 , 1 , V_19 , V_20 ) ;
if ( ! V_16 ) {
F_11 ( V_7 -> V_30 ,
L_30 ) ;
F_46 ( & V_10 -> V_185 ) ;
return - V_219 ;
}
V_16 -> V_22 = V_16 ;
V_16 -> V_23 = V_24 ;
V_15 = V_16 -> V_25 ( V_16 ) ;
F_8 ( V_7 -> V_30 , L_31 , __LINE__ , V_16 , V_15 ) ;
if ( V_15 < 0 ) {
F_11 ( V_7 -> V_30 ,
L_32 ,
V_10 -> V_177 , V_213 ) ;
F_46 ( & V_10 -> V_185 ) ;
return - V_219 ;
}
V_10 -> V_16 = V_16 ;
V_7 -> V_115 . V_142 = V_115 -> V_142 ;
V_7 -> V_115 . V_143 = V_115 -> V_143 ;
if ( V_115 -> V_215 & V_216 )
V_7 -> V_115 . V_215 |= V_216 ;
else
V_7 -> V_115 . V_215 &= ~ V_216 ;
V_10 -> V_136 = V_7 -> V_115 ;
F_46 ( & V_10 -> V_185 ) ;
F_8 ( V_7 -> V_30 , L_33 ) ;
return 0 ;
}
static int F_60 ( struct V_220 * V_221 , T_8 V_222 )
{
struct V_1 * V_2 = F_61 ( V_221 ) ;
struct V_6 * V_10 = V_2 -> V_7 -> V_132 ;
F_62 () ;
F_63 ( V_2 -> V_7 , 1 ) ;
F_64 () ;
if ( V_10 -> V_182 == V_183 ) {
F_17 ( V_10 ) ;
F_28 ( V_2 , 0 ) ;
}
return 0 ;
}
static int F_65 ( struct V_220 * V_221 )
{
struct V_1 * V_2 = F_61 ( V_221 ) ;
struct V_6 * V_10 = V_2 -> V_7 -> V_132 ;
if ( V_10 -> V_182 == V_183 ) {
F_7 ( V_10 ) ;
F_28 ( V_2 , V_2 -> V_211 ) ;
}
F_62 () ;
F_63 ( V_2 -> V_7 , 0 ) ;
F_64 () ;
return 0 ;
}
static int F_37 ( struct V_111 * V_7 , unsigned int V_144 ,
bool V_27 )
{
int V_223 = 0 ;
T_9 V_224 ;
V_7 -> V_157 = F_66 ( V_7 -> V_30 ,
V_144 ,
& V_224 , V_225 ) ;
if ( ! V_7 -> V_157 ) {
F_11 ( V_7 -> V_30 , L_34 ,
V_144 ) ;
V_223 = - V_226 ;
goto V_227;
}
if ( V_27 )
F_45 ( & V_7 -> V_228 ) ;
V_7 -> V_113 . V_155 = V_224 ;
V_7 -> V_113 . V_154 = V_144 ;
if ( V_27 )
F_46 ( & V_7 -> V_228 ) ;
F_8 ( V_7 -> V_30 , L_35 ,
( T_2 ) V_7 -> V_113 . V_155 , V_7 -> V_157 , V_7 -> V_113 . V_154 ) ;
V_7 -> V_229 = V_7 -> V_113 . V_154 ;
memset ( ( char * ) V_7 -> V_157 , 0 , V_7 -> V_113 . V_154 ) ;
return 0 ;
V_227:
V_7 -> V_113 . V_154 = 0 ;
V_7 -> V_113 . V_155 = 0 ;
V_7 -> V_157 = NULL ;
return V_223 ;
}
static int F_36 ( struct V_111 * V_7 )
{
F_67 ( V_7 -> V_30 , V_7 -> V_113 . V_154 ,
V_7 -> V_157 , V_7 -> V_113 . V_155 ) ;
V_7 -> V_157 = NULL ;
F_45 ( & V_7 -> V_228 ) ;
V_7 -> V_113 . V_155 = 0 ;
V_7 -> V_113 . V_154 = 0 ;
F_46 ( & V_7 -> V_228 ) ;
return 0 ;
}
static struct V_111 * F_68 ( struct V_30 * V_17 , struct V_230 * V_231 )
{
struct V_111 * V_7 ;
struct V_6 * V_232 ;
int V_184 ;
V_7 = F_69 ( sizeof( struct V_6 ) , V_17 ) ;
if ( ! V_7 )
return NULL ;
V_232 = V_7 -> V_132 ;
V_232 -> V_15 = - V_33 ;
V_232 -> V_177 = 0 ;
V_7 -> V_115 . V_138 = V_141 ;
V_7 -> V_233 = V_231 ;
V_7 -> V_14 = V_234 ;
V_7 -> V_203 = V_232 -> V_203 ;
F_70 ( & V_232 -> V_185 ) ;
V_184 = F_71 ( & V_7 -> V_235 , 16 , 0 ) ;
if ( V_184 < 0 ) {
F_72 ( V_7 ) ;
return NULL ;
}
return V_7 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_30 * V_17 = V_2 -> V_17 ;
struct V_236 * V_237 = F_74 ( V_17 ) ;
const char * V_238 = V_237 -> V_238 ;
unsigned int V_239 ;
struct V_111 * V_7 ;
struct V_6 * V_232 ;
const struct V_240 * V_148 ;
int V_184 , V_241 ;
if ( V_237 -> V_89 >= F_75 ( V_88 ) ) {
F_11 ( V_17 , L_36 ,
V_237 -> V_89 ) ;
return - V_33 ;
}
V_12 -> V_131 = V_2 ;
V_239 = V_12 -> V_133 ;
if ( V_12 -> V_13 . V_21 != V_38 )
return - V_33 ;
V_7 = F_68 ( V_17 , & V_242 ) ;
if ( ! V_7 )
return - V_156 ;
if ( ! V_243 )
V_243 = V_238 ;
if ( ! V_243 ) {
V_184 = - V_33 ;
goto V_244;
}
if ( V_237 -> V_148 && V_237 -> V_241 ) {
V_148 = V_237 -> V_148 ;
V_241 = V_237 -> V_241 ;
} else {
V_148 = V_245 ;
V_241 = F_75 ( V_245 ) ;
}
if ( ! F_76 ( & V_7 -> V_115 , V_7 , V_243 , V_148 ,
V_241 , NULL , V_188 ) ) {
V_184 = - V_226 ;
goto V_244;
}
F_77 ( V_148 , V_241 , & V_7 -> V_246 ) ;
V_7 -> V_115 . V_153 = V_7 -> V_115 . V_170 * 2 ;
V_2 -> V_7 = V_7 ;
F_3 ( V_2 , 0x00100010L , V_247 ) ;
F_28 ( V_2 , 255 ) ;
F_27 ( V_2 , true , 0xFF ) ;
F_26 ( V_2 , V_38 , false , 0 ) ;
V_232 = V_7 -> V_132 ;
V_232 -> V_11 = V_12 ;
V_232 -> V_158 = V_12 -> V_13 . V_21 ;
V_232 -> V_2 = V_2 ;
V_232 -> V_182 = V_210 ;
V_2 -> V_89 = V_237 -> V_89 ;
F_54 ( & V_232 -> V_134 ) ;
F_58 ( V_12 -> V_133 ) ;
F_8 ( V_2 -> V_17 , L_37 , V_12 -> V_133 ) ;
V_184 = F_35 ( V_7 , false ) ;
if ( V_184 < 0 )
goto V_248;
F_51 ( V_183 , V_7 ) ;
F_57 ( V_17 , L_38 , V_243 ) ;
V_184 = F_78 ( V_7 ) ;
if ( V_184 < 0 )
goto V_249;
return 0 ;
V_249:
V_248:
V_244:
F_79 ( & V_7 -> V_235 ) ;
F_72 ( V_7 ) ;
return V_184 ;
}
static bool F_80 ( struct V_13 * V_29 , void * V_127 )
{
struct V_250 * V_251 = V_127 ;
struct V_30 * V_17 ;
struct V_236 * V_237 ;
if ( ! F_81 ( V_29 ) )
return false ;
if ( ! V_251 )
return false ;
V_17 = V_251 -> V_2 -> V_17 ;
V_237 = F_74 ( V_17 ) ;
return V_251 -> V_116 == V_29 -> V_21 &&
V_237 -> V_252 == V_29 -> V_30 -> V_17 ;
}
static void F_82 ( struct V_111 * V_7 )
{
F_36 ( V_7 ) ;
F_79 ( & V_7 -> V_235 ) ;
F_83 ( V_7 ) ;
F_72 ( V_7 ) ;
}
static int F_84 ( struct V_220 * V_221 )
{
struct V_30 * V_17 = & V_221 -> V_17 ;
int V_184 ;
struct V_253 * V_254 ;
struct V_1 * V_2 ;
T_10 V_255 ;
struct V_13 * V_29 ;
struct V_250 V_251 ;
V_254 = F_85 ( V_221 , V_256 , 0 ) ;
if ( ! V_254 )
return - V_33 ;
V_2 = F_86 ( sizeof( * V_2 ) , V_257 ) ;
if ( ! V_2 )
return - V_156 ;
F_87 ( & V_2 -> V_27 ) ;
V_2 -> V_4 = F_88 ( V_254 -> V_258 , F_89 ( V_254 ) ) ;
if ( ! V_2 -> V_4 ) {
V_184 = - V_156 ;
goto V_259;
}
F_90 ( L_39 , V_254 , V_2 -> V_4 ) ;
F_91 () ;
V_2 -> V_17 = V_17 ;
F_92 ( V_221 , V_2 ) ;
V_251 . V_2 = V_2 ;
F_93 ( V_255 ) ;
F_94 ( V_260 , V_255 ) ;
F_94 ( V_261 , V_255 ) ;
V_251 . V_116 = V_38 ;
V_29 = F_95 ( V_255 , F_80 , & V_251 ) ;
if ( ! V_29 ) {
V_184 = - V_226 ;
goto V_262;
}
V_2 -> V_211 = 255 ;
V_184 = F_73 ( V_2 , F_31 ( V_29 ) ) ;
if ( V_184 < 0 )
goto V_263;
return 0 ;
V_263:
F_96 ( V_29 ) ;
V_262:
F_97 () ;
F_98 ( V_2 -> V_4 ) ;
V_259:
F_99 ( V_2 ) ;
F_11 ( V_17 , L_40 ) ;
return V_184 ;
}
static int F_100 ( struct V_220 * V_17 )
{
struct V_1 * V_2 = F_61 ( V_17 ) ;
struct V_111 * V_7 = V_2 -> V_7 ;
struct V_6 * V_10 = V_7 -> V_132 ;
struct V_13 * V_29 ;
V_29 = & V_10 -> V_11 -> V_13 ;
F_82 ( V_7 ) ;
F_96 ( V_29 ) ;
F_97 () ;
F_98 ( V_2 -> V_4 ) ;
F_99 ( V_2 ) ;
return 0 ;
}
static int T_11 F_101 ( void )
{
#ifndef F_102
char * V_264 , * V_265 = NULL ;
if ( F_103 ( L_41 , & V_265 ) )
return - V_266 ;
if ( ! V_265 || ! * V_265 )
return 0 ;
while ( ( V_264 = F_104 ( & V_265 , L_42 ) ) != NULL ) {
if ( ! * V_264 )
continue;
if ( ! strncmp ( V_264 , L_43 , 4 ) )
V_188 = F_105 ( V_264 + 4 , NULL , 0 ) ;
else
V_243 = V_264 ;
}
#endif
return 0 ;
}
static int T_11 F_106 ( void )
{
int V_184 = F_101 () ;
if ( V_184 < 0 )
return V_184 ;
V_184 = F_107 ( & V_267 ) ;
return V_184 ;
}
static void T_12 F_108 ( void )
{
F_109 ( & V_267 ) ;
}
