static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_2 -> V_4 , V_5 ) ;
F_3 ( V_2 -> V_6 , L_1 ,
V_3 ) ;
F_4 ( V_2 , V_2 -> V_4 , V_7 ,
0xffffffff ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_2 -> V_4 ,
V_8 ) ;
if ( V_3 & V_9 ) {
T_1 V_10 , V_11 , V_12 ;
V_10 = F_2 ( V_2 , V_2 -> V_4 ,
V_13 ) ;
V_11 = F_2 ( V_2 , V_2 -> V_4 ,
V_14 ) ;
V_12 = F_2 ( V_2 , V_2 -> V_4 ,
V_15 ) ;
F_3 ( V_2 -> V_6 ,
L_2 ,
V_10 , V_12 ,
( V_16 ) F_6 ( V_11 , V_17 ) ,
( V_16 ) F_6 ( V_11 , V_18 ) ,
( V_16 ) F_6 ( V_11 ,
V_19 ) ,
( V_16 ) F_6 ( V_11 ,
V_20 ) ,
( V_16 ) F_6 ( V_11 , V_21 ) ,
( V_16 ) F_6 ( V_11 ,
V_22 ) ,
V_11 ) ;
}
return 0 ;
}
static const char * F_7 ( V_16 V_23 )
{
switch ( V_23 ) {
case 1 : return L_3 ;
case 2 : return L_4 ;
case 3 : return L_5 ;
case 4 : return L_6 ;
case 5 : return L_7 ;
case 6 : return L_8 ;
case 7 : return L_9 ;
case 8 : return L_10 ;
case 9 : return L_11 ;
case 10 : return L_12 ;
default:
return L_13 ;
}
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_3 , V_24 ;
V_3 = F_2 ( V_2 , V_2 -> V_4 ,
V_25 ) ;
if ( ! ( V_3 & V_26 ) )
goto V_27;
V_3 = F_2 ( V_2 , V_2 -> V_4 ,
V_28 ) ;
V_24 = F_2 ( V_2 , V_2 -> V_4 ,
V_29 ) ;
F_3 ( V_2 -> V_6 ,
L_14 ,
V_24 , V_3 ,
( V_3 & V_30 ) ? L_15 : L_16 ,
F_6 ( V_3 , V_31 ) << 2 ,
F_7 ( F_6 ( V_3 , V_32 ) ) ,
F_6 ( V_24 , V_33 ) ,
( F_6 ( V_24 , V_34 ) ==
V_35 ) ? L_17 : L_18 ,
F_6 ( V_24 , V_36 ) ) ;
V_27:
F_4 ( V_2 , V_2 -> V_4 ,
V_25 , 0 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_2 -> V_4 ,
V_37 ) ;
if ( V_3 & V_38 ) {
T_1 V_39 , V_40 , V_41 ;
V_39 = F_2 ( V_2 , V_2 -> V_4 ,
V_42 ) ;
V_40 = F_2 ( V_2 , V_2 -> V_4 ,
V_43 ) ;
V_41 = F_2 ( V_2 , V_2 -> V_4 ,
V_44 ) ;
F_3 ( V_2 ,
L_19
L_20
L_21 ,
V_40 , V_39 , V_41 ,
( V_16 ) F_6 ( V_41 , V_45 ) ,
( V_16 ) F_6 ( V_41 , V_46 ) ,
F_6 ( V_41 ,
V_47 ) ? 1 : 0 ,
V_3 ,
F_6 ( V_3 ,
V_48 ) ? 1 : 0 ,
F_6 ( V_3 ,
V_49 ) ? 1 : 0 ,
F_6 ( V_3 ,
V_50 ) ? 1 : 0 ) ;
}
V_3 = F_2 ( V_2 , V_2 -> V_4 ,
V_51 ) ;
if ( V_3 & V_52 ) {
T_1 V_39 , V_40 , V_41 ;
V_39 = F_2 ( V_2 , V_2 -> V_4 ,
V_53 ) ;
V_40 = F_2 ( V_2 , V_2 -> V_4 ,
V_54 ) ;
V_41 = F_2 ( V_2 , V_2 -> V_4 ,
V_55 ) ;
F_3 ( V_2 ,
L_22
L_23
L_24 ,
V_40 , V_39 , V_41 ,
( V_16 ) F_6 ( V_41 , V_45 ) ,
( V_16 ) F_6 ( V_41 , V_46 ) ,
F_6 ( V_41 ,
V_47 ) ? 1 : 0 ,
V_3 ,
F_6 ( V_3 , V_48 ) ? 1
: 0 ,
F_6 ( V_3 , V_49 ) ? 1 : 0 ,
F_6 ( V_3 , V_50 ) ? 1
: 0 ) ;
}
V_3 = F_2 ( V_2 , V_2 -> V_4 ,
V_56 ) ;
if ( V_3 & V_57 )
F_3 ( V_2 , L_25 , V_3 ) ;
V_3 = F_2 ( V_2 , V_2 -> V_4 ,
V_58 ) ;
if ( V_3 & V_59 ) {
T_1 V_40 , V_39 ;
V_39 = F_2 ( V_2 , V_2 -> V_4 ,
V_60 ) ;
V_40 = F_2 ( V_2 , V_2 -> V_4 ,
V_61 ) ;
F_3 ( V_2 , L_26 ,
V_3 , V_40 , V_39 ) ;
}
V_3 = F_2 ( V_2 , V_2 -> V_4 ,
V_62 ) ;
if ( V_3 & V_63 ) {
T_1 V_40 , V_39 , V_41 ;
V_39 = F_2 ( V_2 , V_2 -> V_4 ,
V_64 ) ;
V_40 = F_2 ( V_2 , V_2 -> V_4 ,
V_65 ) ;
V_41 = F_2 ( V_2 , V_2 -> V_4 ,
V_66 ) ;
F_3 ( V_2 ,
L_27 ,
V_41 , V_3 , V_40 , V_39 ) ;
}
F_4 ( V_2 , V_2 -> V_4 ,
V_67 , ( 1 << 2 ) ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_68 ;
V_68 = F_2 ( V_2 , V_2 -> V_4 , V_69 ) &
V_70 ;
if ( V_68 ) {
T_1 V_41 = F_2 ( V_2 , V_2 -> V_4 ,
V_71 ) ;
F_3 ( V_2 -> V_6 ,
L_28 ,
F_2 ( V_2 , V_2 -> V_4 ,
V_72 ) ,
( V_73 ) ( V_41 & V_74 ) ,
F_6 ( V_41 , V_75 ) * 4 ,
V_68 ) ;
}
return - V_76 ;
}
static inline V_73 F_11 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
V_73 V_79 = 0 ;
V_73 V_80 ;
F_12 () ;
V_80 = F_13 ( V_78 -> V_81 -> V_82 ) ;
if ( V_78 -> V_80 != V_80 ) {
V_78 -> V_80 = V_80 ;
V_79 = V_83 ;
}
F_12 () ;
return V_79 ;
}
static int F_14 ( struct V_1 * V_2 ,
V_73 V_84 )
{
struct V_77 * V_85 = V_2 -> V_86 ;
T_1 V_87 ;
V_87 = F_2 ( V_2 , V_2 -> V_4 ,
V_88 ) ;
F_15 ( V_2 , V_89 , L_29 ,
V_87 , V_87 & ~ ( V_84 & V_90 ) ) ;
V_87 &= ~ ( V_84 & V_90 ) ;
F_4 ( V_2 , V_2 -> V_4 , V_88 , V_87 ) ;
F_15 ( V_2 , V_89 ,
L_30 ,
V_85 -> V_91 ,
V_85 -> V_91 | V_84 ) ;
V_85 -> V_91 |= V_84 ;
if ( V_84 & 0x100 ) {
F_16 ( V_2 , V_2 -> V_4 ) ;
F_4 ( V_2 , V_2 -> V_4 ,
V_85 -> V_92 , 0 ) ;
}
F_17 ( ( V_16 V_93 * ) V_2 -> V_94 +
V_95 +
( ( V_96 -
V_97 ) << 3 ) ,
( T_1 ) V_84 ) ;
F_15 ( V_2 , V_89 , L_31 ,
V_84 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_98 * V_99 ,
struct V_100 * V_101 ,
enum V_102 type ,
T_1 V_103 , T_1 V_104 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_99 -> V_106 ; V_105 ++ ) {
if ( ! ( V_103 & ( 1 << V_105 ) ) )
continue;
F_19 ( V_2 ,
L_32 ,
V_101 -> V_107 ,
type == V_108 ? L_33 :
L_34 ,
V_99 -> V_109 , V_99 -> V_110 ,
V_105 , ( V_104 & ( 1 << V_105 ) ) ? L_35 : L_36 ) ;
}
}
static int
F_20 ( struct V_1 * V_2 ,
struct V_111 * V_112 ,
T_1 V_113 ,
T_1 V_114 )
{
int V_79 = - V_76 ;
T_1 V_103 ;
F_3 ( V_2 , L_37 ,
V_112 -> V_115 , V_114 ) ;
if ( V_112 -> V_116 ) {
F_3 ( V_2 , L_38 ,
V_112 -> V_115 ) ;
V_79 = V_112 -> V_116 ( V_2 ) ;
}
if ( V_112 -> V_117 != V_118 ) {
struct V_100 * V_101 ;
T_1 V_104 ;
int V_119 ;
V_101 = & V_120 [ V_112 -> V_117 ] ;
for ( V_119 = 0 ; V_119 < V_101 -> V_121 [ 0 ] . V_122 ; V_119 ++ ) {
struct V_98 * V_99 ;
T_1 V_110 ;
V_99 = V_101 -> V_121 [ 0 ] . V_123 [ V_119 ] ;
if ( V_79 == 0 )
V_110 = V_99 -> V_124 ;
else
V_110 = V_99 -> V_110 ;
V_103 = F_2 ( V_2 , V_2 -> V_4 , V_110 ) ;
V_104 = F_2 ( V_2 , V_2 -> V_4 ,
V_99 -> V_125 ) ;
F_18 ( V_2 , V_99 ,
V_101 ,
V_108 ,
V_103 , V_104 ) ;
}
}
if ( ! V_79 )
goto V_27;
V_103 = F_2 ( V_2 , V_2 -> V_4 , V_113 ) ;
F_4 ( V_2 , V_2 -> V_4 , V_113 , ( V_103 & ~ V_114 ) ) ;
F_3 ( V_2 , L_39 ,
V_112 -> V_115 ) ;
V_27:
return V_79 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_111 * V_112 ,
struct V_100 * V_101 ,
V_16 V_126 )
{
int V_119 ;
for ( V_119 = 0 ; V_119 < V_101 -> V_121 [ 0 ] . V_127 ; V_119 ++ ) {
struct V_98 * V_99 ;
T_1 V_103 , V_104 ;
V_99 = V_101 -> V_121 [ 0 ] . V_128 [ V_119 ] ;
V_103 = F_2 ( V_2 , V_2 -> V_4 ,
V_99 -> V_124 ) ;
V_104 = F_2 ( V_2 , V_2 -> V_4 ,
V_99 -> V_125 ) ;
F_18 ( V_2 , V_99 ,
V_101 ,
V_129 ,
V_103 , V_104 ) ;
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_111 * V_112 ,
V_16 V_126 )
{
T_1 V_130 = V_112 -> V_117 ;
F_3 ( V_2 -> V_6 , L_40 ,
V_112 -> V_115 , V_126 ) ;
if ( V_130 != V_118 ) {
F_21 ( V_2 , V_112 , & V_120 [ V_130 ] ,
V_126 ) ;
if ( V_130 == V_131 ) {
F_21 ( V_2 , V_112 ,
& V_120 [ V_132 ] ,
V_126 ) ;
F_21 ( V_2 , V_112 ,
& V_120 [ V_133 ] ,
V_126 ) ;
}
}
}
static int F_23 ( struct V_1 * V_2 ,
V_73 V_134 )
{
struct V_77 * V_85 = V_2 -> V_86 ;
T_1 V_135 [ V_136 ] , V_137 ;
V_16 V_119 , V_105 , V_138 , V_139 ;
int V_79 = 0 ;
for ( V_119 = 0 ; V_119 < V_136 ; V_119 ++ ) {
V_135 [ V_119 ] = F_2 ( V_2 , V_2 -> V_4 ,
V_140 +
V_119 * 0x4 ) ;
F_15 ( V_2 , V_89 ,
L_41 ,
V_119 , V_135 [ V_119 ] ) ;
}
for ( V_119 = 0 ; V_119 < V_136 ; V_119 ++ ) {
struct V_141 * V_112 = & V_85 -> V_142 [ V_119 ] ;
T_1 V_143 = F_2 ( V_2 , V_2 -> V_4 ,
V_144 +
V_119 * sizeof( T_1 ) ) ;
T_1 V_145 ;
V_145 = V_85 -> V_146 [ V_119 ] & V_135 [ V_119 ] & V_143 ;
if ( ! V_145 )
continue;
for ( V_105 = 0 , V_139 = 0 ; V_139 < 32 ; V_105 ++ ) {
struct V_111 * V_147 = & V_112 -> V_148 [ V_105 ] ;
if ( ( V_147 -> V_149 & V_150 ) &&
! ! ( V_145 & ( 1 << V_139 ) ) )
F_22 ( V_2 , V_147 ,
V_139 ) ;
V_139 += F_24 ( V_147 -> V_149 ) ;
}
}
for ( V_138 = 0 ; V_138 < V_151 ; V_138 ++ ) {
struct V_111 * V_112 ;
if ( ! ( V_134 & ( 1 << V_138 ) ) )
continue;
for ( V_119 = 0 ; V_119 < V_136 ; V_119 ++ ) {
T_1 V_152 = V_144 +
V_119 * sizeof( T_1 ) +
V_138 * sizeof( T_1 ) * V_136 ;
T_1 V_143 , V_148 ;
V_143 = F_2 ( V_2 , V_2 -> V_4 , V_152 ) ;
V_148 = V_135 [ V_119 ] & V_143 ;
if ( ! V_148 )
continue;
for ( V_105 = 0 , V_139 = 0 ; V_139 < 32 ; V_105 ++ ) {
V_16 V_153 , V_154 ;
T_1 V_114 ;
V_112 = & V_85 -> V_142 [ V_119 ] . V_148 [ V_105 ] ;
if ( V_112 -> V_149 == V_155 )
continue;
V_153 = V_139 ;
V_154 = F_24 ( V_112 -> V_149 ) ;
if ( V_112 -> V_149 & V_156 ) {
V_153 ++ ;
V_154 -- ;
}
V_114 = V_148 & ( ( ( 1 << V_154 ) - 1 ) << V_153 ) ;
if ( V_114 ) {
F_20 ( V_2 ,
V_112 ,
V_152 ,
V_114 ) ;
}
V_139 += F_24 ( V_112 -> V_149 ) ;
}
}
}
F_17 ( ( V_16 V_93 * ) V_2 -> V_94 +
V_95 +
( ( V_157 -
V_97 ) << 3 ) ,
~ ( ( T_1 ) V_134 ) ) ;
V_137 = F_2 ( V_2 , V_2 -> V_4 ,
V_88 ) ;
V_137 |= ( V_134 & V_90 ) ;
F_4 ( V_2 , V_2 -> V_4 , V_88 , V_137 ) ;
V_85 -> V_91 &= ~ V_134 ;
return V_79 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_77 * V_158 = V_2 -> V_86 ;
struct V_159 * V_86 = V_158 -> V_81 ;
T_1 V_160 = 0 , V_161 = 0 ;
V_73 V_84 , V_134 ;
T_2 V_80 ;
int V_79 = 0 ;
do {
V_80 = V_86 -> V_82 ;
V_160 = F_26 ( V_86 -> V_162 ) ;
V_161 = F_26 ( V_86 -> V_163 ) ;
} while ( V_80 != V_86 -> V_82 );
V_86 -> V_82 = V_80 ;
V_84 = ( V_160 & ~ V_161 & V_164 ) &
~ V_158 -> V_91 ;
V_134 = ( ~ V_160 & V_161 & V_164 ) &
V_158 -> V_91 ;
if ( ( V_84 & ~ 0x100 ) || ( V_134 & ~ 0x100 ) ) {
F_3 ( V_2 ,
L_42 ,
V_80 , V_160 , V_161 , V_84 ,
V_134 , V_158 -> V_91 ) ;
} else if ( V_84 == 0x100 ) {
F_3 ( V_2 ,
L_43 ) ;
} else {
F_15 ( V_2 , V_89 ,
L_44 ) ;
}
if ( V_84 ) {
V_79 = F_14 ( V_2 , V_84 ) ;
if ( V_79 )
return V_79 ;
}
if ( V_134 ) {
V_79 = F_23 ( V_2 , V_134 ) ;
if ( V_79 )
return V_79 ;
}
return V_79 ;
}
static void F_27 ( struct V_1 * V_2 ,
void V_93 * V_165 ,
T_1 V_166 )
{
struct V_167 V_168 = { 0 } ;
V_168 . V_169 =
( ( V_166 << V_170 ) |
( 1 << V_171 ) |
( V_172 << V_173 ) |
( V_174 <<
V_175 ) ) ;
F_17 ( V_165 , V_168 . V_169 ) ;
F_12 () ;
F_28 () ;
}
void F_29 ( unsigned long V_176 )
{
struct V_1 * V_2 = (struct V_1 * ) V_176 ;
struct V_177 * V_178 = NULL ;
struct V_77 * V_81 ;
struct V_179 * V_180 ;
int V_181 ;
V_73 V_79 = 0 ;
if ( ! V_2 -> V_182 ) {
F_30 ( V_2 -> V_6 , L_45 ) ;
return;
}
V_180 = & V_2 -> V_182 -> V_180 ;
V_181 = F_31 ( V_2 -> V_182 -> V_183 ) ;
if ( ! V_180 ) {
F_30 ( V_2 -> V_6 ,
L_46 ) ;
return;
}
if ( ! V_2 -> V_86 ) {
F_30 ( V_2 -> V_6 , L_47 ) ;
return;
}
V_81 = V_2 -> V_86 ;
F_15 ( V_2 , V_89 , L_48 ,
V_2 , V_2 -> V_184 ) ;
F_32 ( V_180 , V_185 , 0 ) ;
if ( ! V_180 -> V_186 ) {
F_30 (
V_2 -> V_6 ,
L_49 ) ;
} else {
T_1 V_187 = V_180 -> V_188 ;
V_79 = F_33 ( V_180 ) ;
F_15 ( V_2 -> V_6 , V_89 ,
L_50 ,
V_187 , V_180 -> V_188 ) ;
}
if ( ! V_81 || ! V_81 -> V_81 ) {
F_30 (
V_2 -> V_6 ,
L_51 ) ;
} else {
V_73 V_187 = V_81 -> V_80 ;
V_79 |= F_11 ( V_2 , V_81 ) ;
F_15 ( V_2 -> V_6 , V_89 ,
L_52 ,
V_187 , V_81 -> V_80 ) ;
}
if ( ! ( V_79 & V_189 ) ) {
F_32 ( V_180 , V_190 , 1 ) ;
return;
}
if ( ! V_2 -> V_4 ) {
F_19 ( V_2 -> V_6 , L_53 ) ;
F_32 ( V_180 , V_190 , 1 ) ;
return;
}
if ( V_79 & V_83 )
F_25 ( V_2 ) ;
if ( V_79 & V_191 ) {
int V_192 ;
for ( V_192 = 0 ; V_192 < V_181 ; V_192 ++ ) {
V_178 = & V_2 -> V_182 -> V_183 [ V_192 ] ;
if ( V_178 -> V_193 )
V_178 -> V_193 ( V_2 , V_178 -> V_194 ) ;
}
}
if ( V_81 && ( V_79 & V_83 ) )
F_27 ( V_2 , V_180 -> V_165 , V_81 -> V_80 ) ;
F_32 ( V_180 , V_190 , 1 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_77 * V_195 = V_2 -> V_86 ;
if ( ! V_195 )
return;
if ( V_195 -> V_81 )
F_35 ( & V_2 -> V_6 -> V_196 -> V_197 ,
F_36 ( V_2 ) ,
V_195 -> V_81 ,
V_195 -> V_198 ) ;
F_37 ( V_195 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_199 * V_200 )
{
struct V_77 * V_180 = V_2 -> V_86 ;
memset ( V_180 -> V_81 , 0 , sizeof( * V_180 -> V_81 ) ) ;
V_180 -> V_80 = 0 ;
V_180 -> V_91 = 0 ;
F_4 ( V_2 , V_200 , V_201 ,
F_39 ( V_2 -> V_86 -> V_198 ) ) ;
F_4 ( V_2 , V_200 , V_202 ,
F_40 ( V_2 -> V_86 -> V_198 ) ) ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_199 * V_200 ,
void * V_203 ,
T_3 V_204 )
{
struct V_77 * V_180 = V_2 -> V_86 ;
int V_119 , V_105 , V_138 ;
V_180 -> V_81 = V_203 ;
V_180 -> V_198 = V_204 ;
V_180 -> V_142 = V_205 ;
memset ( V_180 -> V_146 , 0 , sizeof( T_1 ) * V_136 ) ;
for ( V_119 = 0 ; V_119 < V_136 ; V_119 ++ ) {
for ( V_105 = 0 , V_138 = 0 ; V_138 < 32 ; V_105 ++ ) {
unsigned int V_149 = V_205 [ V_119 ] . V_148 [ V_105 ] . V_149 ;
if ( V_149 & V_150 )
V_180 -> V_146 [ V_119 ] |= 1 << V_138 ;
V_138 += F_24 ( V_149 ) ;
}
F_15 ( V_2 , V_89 ,
L_54 ,
V_119 , V_180 -> V_146 [ V_119 ] ) ;
}
V_180 -> V_92 = ( V_2 -> V_206 << 3 ) +
V_207 ;
F_38 ( V_2 , V_200 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_199 * V_200 )
{
struct V_208 * V_6 = V_2 -> V_6 ;
struct V_77 * V_195 ;
void * V_209 ;
T_3 V_210 = 0 ;
V_195 = F_43 ( sizeof( * V_195 ) , V_211 ) ;
if ( ! V_195 ) {
F_19 ( V_6 , L_55 ) ;
return - V_212 ;
}
V_209 = F_44 ( & V_6 -> V_196 -> V_197 ,
F_36 ( V_2 ) ,
& V_210 , V_211 ) ;
if ( ! V_209 ) {
F_19 ( V_6 , L_56 ) ;
F_37 ( V_195 ) ;
return - V_212 ;
}
V_2 -> V_86 = V_195 ;
F_41 ( V_2 , V_200 , V_209 , V_210 ) ;
return 0 ;
}
void F_45 ( struct V_1 * V_2 ,
struct V_213 * V_214 ,
V_16 V_215 ,
V_73 V_216 ,
V_16 V_217 )
{
struct V_208 * V_6 = V_2 -> V_6 ;
T_1 V_218 ;
memset ( V_214 , 0 , sizeof( * V_214 ) ) ;
F_46 ( V_214 -> V_219 , V_220 , V_215 ) ;
F_46 ( V_214 -> V_219 , V_221 , V_216 ) ;
F_46 ( V_214 -> V_219 , V_222 , V_217 ) ;
F_46 ( V_214 -> V_219 , V_223 , 0x7F ) ;
F_46 ( V_214 -> V_219 , V_224 , 0x7F ) ;
F_46 ( V_214 -> V_219 , V_225 ,
V_226 ) ;
F_46 ( V_214 -> V_219 , V_227 ,
V_228 ) ;
V_218 = V_229 ;
if ( V_6 -> V_230 == V_231 ) {
V_218 = V_232 ;
if ( ! V_6 -> V_233 )
V_6 -> V_233 = V_234 ;
if ( ! V_6 -> V_235 )
V_6 -> V_235 = V_236 ;
}
F_46 ( V_214 -> V_11 , V_237 , V_218 ) ;
F_46 ( V_214 -> V_11 , V_238 , V_218 ) ;
}
void F_47 ( struct V_1 * V_2 ,
struct V_199 * V_200 ,
T_3 V_198 ,
V_73 V_239 ,
V_73 V_216 ,
V_16 V_217 )
{
struct V_213 V_240 ;
F_45 ( V_2 , & V_240 , V_2 -> V_206 ,
V_216 , V_217 ) ;
if ( V_2 -> V_241 ) {
T_4 V_242 = ( T_4 ) V_198 ;
F_48 ( V_2 , V_200 , ( T_4 ) ( V_243 ) & V_242 ,
V_244 +
V_239 * sizeof( T_4 ) , 2 , 0 ) ;
F_48 ( V_2 , V_200 , ( T_4 ) ( V_243 ) & V_240 ,
V_245 +
V_239 * sizeof( T_4 ) , 2 , 0 ) ;
} else {
F_49 ( V_2 ,
V_246 +
V_239 * 2 ,
V_198 ) ;
F_49 ( V_2 ,
V_247 +
V_239 * 2 ,
V_240 ) ;
}
if ( V_2 -> V_6 -> V_230 == V_231 ) {
V_16 V_248 = V_2 -> V_6 -> V_233 >>
( V_226 + 1 ) ;
V_16 V_249 = 1 , V_119 ;
F_50 ( V_2 , V_200 , V_239 , V_250 ,
V_251 ,
V_248 ) ;
V_248 = V_2 -> V_6 -> V_235 >>
( V_228 + 1 ) ;
for ( V_119 = 0 ; V_119 < V_249 ; V_119 ++ ) {
F_50 ( V_2 , V_200 ,
V_239 , F_51 ( V_119 ) ,
V_252 ,
V_248 ) ;
}
}
}
void F_50 ( struct V_1 * V_2 ,
struct V_199 * V_200 ,
V_73 V_239 ,
T_1 V_253 ,
enum V_254 V_255 ,
V_16 V_248 )
{
struct V_256 V_257 ;
T_1 V_258 ;
T_1 V_259 ;
V_258 = V_239 * V_260 ;
memset ( & V_257 , 0 , sizeof( struct V_256 ) ) ;
F_46 ( V_257 . V_261 , V_262 , V_248 ) ;
if ( V_255 == V_251 )
F_46 ( V_257 . V_261 , V_263 , 0 ) ;
else
F_46 ( V_257 . V_261 , V_263 , 1 ) ;
V_259 = V_258 + V_253 ;
if ( V_2 -> V_241 ) {
F_4 ( V_2 , V_200 ,
V_264 + V_259 * sizeof( T_1 ) ,
* ( ( T_1 * ) & ( V_257 ) ) ) ;
} else {
F_52 ( V_2 ,
V_265 + V_259 ,
* ( ( T_1 * ) & ( V_257 ) ) ) ;
}
}
void F_53 ( struct V_1 * V_2 ,
struct V_199 * V_200 ,
struct V_179 * V_180 )
{
V_180 -> V_188 = 0 ;
memset ( V_180 -> V_186 , 0 , sizeof( * V_180 -> V_186 ) ) ;
F_47 ( V_2 , V_200 , V_180 -> V_198 ,
V_180 -> V_239 , 0 , 0 ) ;
}
static V_73 F_54 ( struct V_1 * V_2 ,
V_73 V_266 )
{
V_73 V_239 ;
if ( V_266 == V_267 )
V_239 = V_2 -> V_268 . V_269 -> V_270 ;
else
V_239 = V_266 + V_2 -> V_268 . V_269 -> V_271 ;
F_15 ( V_2 , V_89 , L_57 ,
( V_266 == V_267 ) ? L_58 : L_59 , V_239 ) ;
return V_239 ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_199 * V_200 ,
struct V_179 * V_180 ,
void * V_203 ,
T_3 V_204 ,
V_73 V_266 )
{
V_180 -> V_186 = V_203 ;
V_180 -> V_198 = V_204 ;
V_180 -> V_239 = F_54 ( V_2 , V_266 ) ;
if ( V_266 != V_267 ) {
V_2 -> V_272 [ V_266 ] = V_180 ;
V_2 -> V_273 ++ ;
}
V_180 -> V_6 = V_2 -> V_6 ;
V_180 -> V_165 = ( V_16 V_93 * ) V_2 -> V_94 +
V_95 +
( V_180 -> V_239 << 3 ) ;
V_180 -> V_149 |= V_274 ;
F_53 ( V_2 , V_200 , V_180 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_179 * V_180 ,
V_73 V_266 )
{
if ( V_266 == V_267 ) {
F_30 ( V_2 , L_60 ) ;
return - V_76 ;
}
V_180 -> V_188 = 0 ;
memset ( V_180 -> V_186 , 0 , sizeof( * V_180 -> V_186 ) ) ;
if ( V_2 -> V_272 [ V_266 ] != NULL ) {
V_2 -> V_272 [ V_266 ] = NULL ;
V_2 -> V_273 -- ;
}
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_275 * V_195 = V_2 -> V_182 ;
if ( ! V_195 )
return;
if ( V_195 -> V_180 . V_186 )
F_35 ( & V_2 -> V_6 -> V_196 -> V_197 ,
F_58 ( V_2 ) ,
V_195 -> V_180 . V_186 ,
V_195 -> V_180 . V_198 ) ;
F_37 ( V_195 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_199 * V_200 )
{
struct V_275 * V_195 ;
T_3 V_210 = 0 ;
void * V_209 ;
V_195 = F_43 ( sizeof( * V_195 ) , V_211 ) ;
if ( ! V_195 ) {
F_19 ( V_2 , L_61 ) ;
return - V_212 ;
}
V_209 = F_44 ( & V_2 -> V_6 -> V_196 -> V_197 ,
F_58 ( V_2 ) ,
& V_210 , V_211 ) ;
if ( ! V_209 ) {
F_19 ( V_2 , L_62 ) ;
F_37 ( V_195 ) ;
return - V_212 ;
}
V_2 -> V_182 = V_195 ;
F_55 ( V_2 , V_200 , & V_195 -> V_180 , V_209 ,
V_210 , V_267 ) ;
memset ( V_195 -> V_183 , 0 , sizeof( V_195 -> V_183 ) ) ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 ,
T_5 V_193 ,
void * V_194 ,
V_16 * V_276 ,
T_2 * * V_277 )
{
struct V_275 * V_182 = V_2 -> V_182 ;
int V_79 = - V_212 ;
V_16 V_192 ;
for ( V_192 = 0 ; V_192 < F_31 ( V_182 -> V_183 ) ; V_192 ++ ) {
if ( V_182 -> V_183 [ V_192 ] . V_193 )
continue;
V_182 -> V_183 [ V_192 ] . V_193 = V_193 ;
V_182 -> V_183 [ V_192 ] . V_194 = V_194 ;
* V_276 = V_192 ;
* V_277 = & V_182 -> V_180 . V_186 -> V_278 [ V_192 ] ;
V_79 = 0 ;
break;
}
return V_79 ;
}
int F_61 ( struct V_1 * V_2 , V_16 V_192 )
{
struct V_275 * V_182 = V_2 -> V_182 ;
if ( V_182 -> V_183 [ V_192 ] . V_193 == NULL )
return - V_212 ;
V_182 -> V_183 [ V_192 ] . V_193 = NULL ;
V_182 -> V_183 [ V_192 ] . V_194 = NULL ;
return 0 ;
}
V_73 F_62 ( struct V_1 * V_2 )
{
return V_2 -> V_182 -> V_180 . V_239 ;
}
void F_63 ( struct V_1 * V_2 ,
struct V_199 * V_200 ,
enum V_279 V_280 )
{
T_1 V_281 = V_282 | V_283 ;
V_2 -> V_6 -> V_280 = V_280 ;
switch ( V_2 -> V_6 -> V_280 ) {
case V_284 :
V_281 |= V_285 ;
V_281 |= V_286 ;
break;
case V_287 :
V_281 |= V_288 ;
V_281 |= V_286 ;
break;
case V_289 :
V_281 |= V_288 ;
break;
case V_290 :
break;
}
F_4 ( V_2 , V_200 , V_291 , V_281 ) ;
}
int F_64 ( struct V_1 * V_2 , struct V_199 * V_200 ,
enum V_279 V_280 )
{
int V_79 = 0 ;
F_4 ( V_2 , V_200 , V_88 , 0 ) ;
F_4 ( V_2 , V_200 , V_292 , 0xfff ) ;
F_4 ( V_2 , V_200 , V_293 , 0xfff ) ;
F_4 ( V_2 , V_200 , V_88 , 0xfff ) ;
F_12 () ;
F_4 ( V_2 , V_200 , V_294 , 0xff ) ;
if ( ( V_280 != V_284 ) || F_65 ( V_2 ) ) {
V_79 = F_66 ( V_2 ) ;
if ( V_79 != 0 ) {
F_19 ( V_2 , L_63 ) ;
return - V_76 ;
}
V_2 -> V_295 = true ;
}
F_63 ( V_2 , V_200 , V_280 ) ;
V_2 -> V_296 = 1 ;
return V_79 ;
}
void F_67 ( struct V_1 * V_2 ,
struct V_199 * V_200 )
{
V_2 -> V_296 = 0 ;
F_4 ( V_2 , V_200 , V_291 , 0 ) ;
}
void F_68 ( struct V_1 * V_2 ,
struct V_199 * V_200 ,
T_1 V_266 ,
bool V_297 ,
V_73 V_298
)
{
T_1 V_299 = V_97 + V_266 ;
T_1 V_300 = V_301 ;
T_1 V_11 = 0 ;
T_1 V_302 = 0 ;
T_1 V_103 = 0 ;
T_1 V_303 = 0 ;
T_1 V_304 = 0 ;
F_46 ( V_11 , V_305 , V_297 ? 1 : 0 ) ;
F_46 ( V_11 , V_306 , 0 ) ;
F_46 ( V_11 , V_307 , V_308 ) ;
F_46 ( V_302 , V_309 , V_299 ) ;
F_46 ( V_302 , V_310 , V_298 ) ;
F_46 ( V_302 , V_311 , V_312 ) ;
F_4 ( V_2 , V_200 , V_313 , V_11 ) ;
F_28 () ;
F_4 ( V_2 , V_200 , V_314 , V_302 ) ;
F_12 () ;
V_303 = 1 << ( V_266 % 32 ) ;
V_304 = V_266 / 32 * sizeof( T_1 ) ;
V_304 += V_315 ;
do {
V_103 = F_2 ( V_2 , V_200 , V_304 ) ;
if ( ( V_103 & V_303 ) == ( V_297 ? V_303 : 0 ) )
break;
F_69 ( 5000 , 10000 ) ;
} while ( -- V_300 );
if ( ! V_300 )
F_19 ( V_2 ,
L_64 ,
V_103 , V_266 ) ;
}
void F_70 ( struct V_1 * V_2 ,
struct V_199 * V_200 ,
T_1 V_266 ,
V_73 V_316 ,
bool V_317 )
{
int V_192 ;
if ( V_317 )
F_68 ( V_2 , V_200 , V_266 , 1 , V_316 ) ;
F_68 ( V_2 , V_200 , V_266 , 0 , V_316 ) ;
for ( V_192 = 0 ; V_192 < 12 ; V_192 ++ )
F_4 ( V_2 , V_200 ,
V_264 + ( V_266 * 12 + V_192 ) * 4 , 0 ) ;
}
void F_71 ( struct V_1 * V_2 ,
struct V_199 * V_200 ,
bool V_317 ,
bool V_318 )
{
T_1 V_271 = V_2 -> V_268 . V_269 -> V_271 ;
T_1 V_319 = V_2 -> V_268 . V_269 -> V_319 ;
T_1 V_266 = 0 ;
T_1 V_103 = 0 ;
V_103 = F_2 ( V_2 , V_200 , V_320 ) ;
V_103 |= V_321 ;
V_103 &= ~ V_322 ;
F_4 ( V_2 , V_200 , V_320 , V_103 ) ;
F_15 ( V_2 , V_89 ,
L_65 ,
V_271 , V_271 + V_319 - 1 ) ;
for ( V_266 = V_271 ; V_266 < V_271 + V_319 ; V_266 ++ )
F_70 ( V_2 , V_200 , V_266 ,
V_2 -> V_268 . V_298 ,
V_317 ) ;
if ( V_318 ) {
V_266 = V_2 -> V_268 . V_269 -> V_270 ;
F_15 ( V_2 , V_89 ,
L_66 , V_266 ) ;
F_70 ( V_2 , V_200 , V_266 ,
V_2 -> V_268 . V_298 ,
V_317 ) ;
}
}
static T_1 F_72 ( struct V_1 * V_2 ,
struct V_199 * V_200 ,
V_73 V_266 )
{
T_1 V_103 = F_2 ( V_2 , V_200 ,
V_323 +
sizeof( T_1 ) * V_266 ) ;
struct V_324 * V_101 ;
V_101 = & V_2 -> V_268 . V_269 -> V_325 . V_326 [ V_266 ] ;
if ( ! F_6 ( V_103 , V_327 ) &&
F_6 ( V_103 , V_328 ) )
goto V_27;
V_101 -> V_329 = V_330 ;
V_101 -> V_331 = F_6 ( V_103 ,
V_332 ) ;
V_101 -> V_333 = F_6 ( V_103 , V_328 ) ;
V_101 -> V_334 = F_6 ( V_103 ,
V_335 ) ;
F_15 ( V_2 , V_89 ,
L_67 ,
V_266 , V_103 , V_101 -> V_331 ,
V_101 -> V_333 , V_101 -> V_334 ) ;
V_27:
return V_103 ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_199 * V_200 )
{
struct V_336 * V_269 ;
struct V_324 * V_337 ;
T_1 V_103 ;
V_73 V_266 ;
V_73 V_338 = 0xFF ;
V_2 -> V_268 . V_269 = F_74 ( sizeof( * V_269 ) , V_211 ) ;
if ( ! V_2 -> V_268 . V_269 )
return - V_212 ;
V_269 = V_2 -> V_268 . V_269 ;
V_269 -> V_271 = 0xffff ;
V_269 -> V_319 = 0 ;
V_269 -> V_270 = 0xffff ;
V_269 -> V_339 = 0xffff ;
for ( V_266 = 0 ; V_266 < F_75 ( V_2 -> V_6 ) ;
V_266 ++ ) {
V_337 = & V_269 -> V_325 . V_326 [ V_266 ] ;
V_103 = F_72 ( V_2 , V_200 , V_266 ) ;
if ( ! F_6 ( V_103 , V_327 ) &&
F_6 ( V_103 , V_328 ) )
break;
if ( V_337 -> V_333 ) {
if ( V_337 -> V_331 == V_2 -> V_206 ) {
V_337 -> V_329 |= V_340 ;
if ( V_337 -> V_334 == 0 ) {
if ( V_269 -> V_270 == 0xffff )
V_269 -> V_270 = V_266 ;
} else {
if ( V_269 -> V_271 ==
0xffff ) {
V_269 -> V_271 = V_266 ;
} else if ( V_338 != V_266 - 1 ) {
F_19 ( V_2 -> V_6 ,
L_68 ,
V_2 -> V_206 ) ;
break;
}
V_338 = V_266 ;
( V_269 -> V_319 ) ++ ;
}
}
}
}
F_15 ( V_2 , V_89 ,
L_69 ,
V_269 -> V_271 ,
V_269 -> V_319 ,
V_269 -> V_270 ) ;
if ( V_269 -> V_271 == 0xffff ||
V_269 -> V_270 == 0xffff ||
V_269 -> V_319 == 0 ) {
F_19 ( V_2 ,
L_70 ,
V_269 -> V_271 ,
V_269 -> V_319 ,
V_269 -> V_270 ) ;
return - V_76 ;
}
return 0 ;
}
void F_76 ( struct V_1 * V_2 )
{
T_1 V_281 = 0 ;
V_281 |= V_282 ;
F_52 ( V_2 , V_341 , V_281 ) ;
}
T_4 F_77 ( struct V_1 * V_2 )
{
T_4 V_342 = 0 ;
T_1 V_343 = 0 ;
T_1 V_344 = 0 ;
T_1 V_345 = V_346 -
V_97 ;
T_1 V_347 = V_348 -
V_97 ;
V_343 = F_78 ( V_2 ,
V_95 +
V_345 * 8 ) ;
V_344 = F_78 ( V_2 ,
V_95 +
V_347 * 8 ) ;
V_342 = ( ( T_4 ) V_344 << 32 ) + ( T_4 ) V_343 ;
return V_342 ;
}
static void F_79 ( struct V_1 * V_2 )
{
F_80 ( V_2 -> V_349 ,
F_29 , ( unsigned long ) V_2 ) ;
V_2 -> V_350 = true ;
}
static int F_81 ( struct V_1 * V_2 )
{
V_2 -> V_349 = F_43 ( sizeof( * V_2 -> V_349 ) , V_211 ) ;
if ( ! V_2 -> V_349 )
return - V_212 ;
return 0 ;
}
static void F_82 ( struct V_1 * V_2 )
{
F_37 ( V_2 -> V_349 ) ;
}
int F_83 ( struct V_1 * V_2 ,
struct V_199 * V_200 )
{
int V_79 = 0 ;
V_79 = F_81 ( V_2 ) ;
if ( V_79 ) {
F_30 ( V_2 -> V_6 , L_71 ) ;
return V_79 ;
}
V_79 = F_59 ( V_2 , V_200 ) ;
if ( V_79 ) {
F_30 ( V_2 -> V_6 , L_72 ) ;
return V_79 ;
}
V_79 = F_42 ( V_2 , V_200 ) ;
if ( V_79 ) {
F_30 ( V_2 -> V_6 , L_73 ) ;
return V_79 ;
}
return V_79 ;
}
void F_84 ( struct V_1 * V_2 )
{
F_57 ( V_2 ) ;
F_34 ( V_2 ) ;
F_82 ( V_2 ) ;
}
void F_85 ( struct V_1 * V_2 ,
struct V_199 * V_200 )
{
F_53 ( V_2 , V_200 , & V_2 -> V_182 -> V_180 ) ;
F_38 ( V_2 , V_200 ) ;
F_79 ( V_2 ) ;
}
void F_86 ( struct V_1 * V_2 ,
struct V_351 * V_352 )
{
struct V_336 * V_353 = V_2 -> V_268 . V_269 ;
if ( ! V_353 || ! V_352 )
return;
V_352 -> V_354 = V_353 -> V_319 ;
V_352 -> V_355 = V_353 -> V_356 ;
V_352 -> V_357 = V_353 -> V_358 ;
}
void F_87 ( struct V_208 * V_6 )
{
int V_119 ;
F_88 (cdev, i)
V_6 -> V_359 [ V_119 ] . V_295 = false ;
}
