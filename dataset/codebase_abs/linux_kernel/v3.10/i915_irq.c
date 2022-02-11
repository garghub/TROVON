static void
F_1 ( T_1 * V_1 , T_2 V_2 )
{
if ( ( V_1 -> V_3 & V_2 ) != 0 ) {
V_1 -> V_3 &= ~ V_2 ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_3 ( V_4 ) ;
}
}
static void
F_4 ( T_1 * V_1 , T_2 V_2 )
{
if ( ( V_1 -> V_3 & V_2 ) != V_2 ) {
V_1 -> V_3 |= V_2 ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_3 ( V_4 ) ;
}
}
void
F_5 ( T_1 * V_1 , int V_5 , T_2 V_2 )
{
T_2 V_6 = F_6 ( V_5 ) ;
T_2 V_7 = F_7 ( V_6 ) & 0x7fff0000 ;
if ( ( V_7 & V_2 ) == V_2 )
return;
V_7 |= V_2 | ( V_2 >> 16 ) ;
F_2 ( V_6 , V_7 ) ;
F_3 ( V_6 ) ;
}
void
F_8 ( T_1 * V_1 , int V_5 , T_2 V_2 )
{
T_2 V_6 = F_6 ( V_5 ) ;
T_2 V_7 = F_7 ( V_6 ) & 0x7fff0000 ;
if ( ( V_7 & V_2 ) == 0 )
return;
V_7 &= ~ V_2 ;
F_2 ( V_6 , V_7 ) ;
F_3 ( V_6 ) ;
}
void F_9 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
unsigned long V_11 ;
if ( F_10 ( V_9 ) )
return;
F_11 ( & V_1 -> V_12 , V_11 ) ;
if ( F_12 ( V_9 ) )
F_1 ( V_1 , V_13 ) ;
else {
F_5 ( V_1 , 1 ,
V_14 ) ;
if ( F_13 ( V_9 ) -> V_15 >= 4 )
F_5 ( V_1 , 0 ,
V_14 ) ;
}
F_14 ( & V_1 -> V_12 , V_11 ) ;
}
static int
F_15 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
enum V_16 V_17 = F_16 ( V_1 ,
V_5 ) ;
return F_7 ( F_17 ( V_17 ) ) & V_18 ;
}
static T_2 F_18 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_19 ;
unsigned long V_20 ;
T_2 V_21 , V_22 , V_23 ;
if ( ! F_15 ( V_9 , V_5 ) ) {
F_19 ( L_1
L_2 , F_20 ( V_5 ) ) ;
return 0 ;
}
V_19 = F_21 ( V_5 ) ;
V_20 = F_22 ( V_5 ) ;
do {
V_21 = F_7 ( V_19 ) & V_24 ;
V_23 = F_7 ( V_20 ) & V_25 ;
V_22 = F_7 ( V_19 ) & V_24 ;
} while ( V_21 != V_22 );
V_21 >>= V_26 ;
V_23 >>= V_27 ;
return ( V_21 << 8 ) | V_23 ;
}
static T_2 F_23 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_6 = F_24 ( V_5 ) ;
if ( ! F_15 ( V_9 , V_5 ) ) {
F_19 ( L_1
L_2 , F_20 ( V_5 ) ) ;
return 0 ;
}
return F_7 ( V_6 ) ;
}
static int F_25 ( struct V_8 * V_9 , int V_5 ,
int * V_28 , int * V_29 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_30 = 0 , V_31 = 0 ;
int V_32 , V_33 , V_34 , V_35 ;
bool V_36 = true ;
int V_37 = 0 ;
enum V_16 V_17 = F_16 ( V_1 ,
V_5 ) ;
if ( ! F_15 ( V_9 , V_5 ) ) {
F_19 ( L_3
L_2 , F_20 ( V_5 ) ) ;
return 0 ;
}
V_35 = 1 + ( ( F_7 ( F_26 ( V_17 ) ) >> 16 ) & 0x1fff ) ;
if ( F_13 ( V_9 ) -> V_15 >= 4 ) {
V_31 = F_7 ( F_27 ( V_5 ) ) ;
* V_28 = V_31 & 0x1fff ;
* V_29 = 0 ;
} else {
V_31 = ( F_7 ( F_22 ( V_5 ) ) & V_38 ) >> V_39 ;
V_34 = 1 + ( ( F_7 ( F_28 ( V_17 ) ) >> 16 ) & 0x1fff ) ;
* V_28 = V_31 / V_34 ;
* V_29 = V_31 - ( * V_28 * V_34 ) ;
}
V_30 = F_7 ( F_29 ( V_17 ) ) ;
V_32 = V_30 & 0x1fff ;
V_33 = ( V_30 >> 16 ) & 0x1fff ;
if ( ( * V_28 < V_32 ) || ( * V_28 > V_33 ) )
V_36 = false ;
if ( V_36 && ( * V_28 >= V_32 ) )
* V_28 = * V_28 - V_35 ;
if ( V_30 > 0 )
V_37 |= V_40 | V_41 ;
if ( V_36 )
V_37 |= V_42 ;
return V_37 ;
}
static int F_30 ( struct V_8 * V_9 , int V_5 ,
int * V_43 ,
struct V_44 * V_45 ,
unsigned V_46 )
{
struct V_47 * V_48 ;
if ( V_5 < 0 || V_5 >= F_13 ( V_9 ) -> V_49 ) {
F_31 ( L_4 , V_5 ) ;
return - V_50 ;
}
V_48 = F_32 ( V_9 , V_5 ) ;
if ( V_48 == NULL ) {
F_31 ( L_4 , V_5 ) ;
return - V_50 ;
}
if ( ! V_48 -> V_51 ) {
F_33 ( L_5 , V_5 ) ;
return - V_52 ;
}
return F_34 ( V_9 , V_5 , V_43 ,
V_45 , V_46 ,
V_48 ) ;
}
static void F_35 ( struct V_53 * V_54 )
{
T_1 * V_1 = F_36 ( V_54 , T_1 ,
V_55 ) ;
struct V_8 * V_9 = V_1 -> V_9 ;
struct V_56 * V_57 = & V_9 -> V_57 ;
struct V_58 * V_58 ;
struct V_59 * V_59 ;
struct V_60 * V_61 ;
unsigned long V_11 ;
bool V_62 = false ;
if ( ! V_1 -> V_63 )
return;
F_37 ( & V_57 -> V_64 ) ;
F_33 ( L_6 ) ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
F_38 (connector, &mode_config->connector_list, head) {
V_58 = F_39 ( V_61 ) ;
V_59 = V_58 -> V_65 ;
if ( V_59 -> V_66 > V_67 &&
V_1 -> V_68 [ V_59 -> V_66 ] . V_69 == V_70 &&
V_61 -> V_71 == V_72 ) {
F_40 ( L_7
L_8 ,
F_41 ( V_61 ) ) ;
V_1 -> V_68 [ V_59 -> V_66 ] . V_69 = V_73 ;
V_61 -> V_71 = V_74
| V_75 ;
V_62 = true ;
}
}
if ( V_62 ) {
F_42 ( V_9 ) ;
F_43 ( & V_1 -> V_76 ,
V_77 + F_44 ( V_78 ) ) ;
}
F_14 ( & V_1 -> V_12 , V_11 ) ;
F_38 (intel_encoder, &mode_config->encoder_list, base.head)
if ( V_59 -> V_79 )
V_59 -> V_79 ( V_59 ) ;
F_45 ( & V_57 -> V_64 ) ;
F_46 ( V_9 ) ;
}
static void F_47 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
T_2 V_80 , V_81 , V_82 , V_83 ;
T_3 V_84 ;
unsigned long V_46 ;
F_11 ( & V_85 , V_46 ) ;
F_48 ( V_86 , F_7 ( V_86 ) ) ;
V_84 = V_1 -> V_87 . V_88 ;
F_48 ( V_86 , V_89 ) ;
V_80 = F_7 ( V_90 ) ;
V_81 = F_7 ( V_91 ) ;
V_82 = F_7 ( V_92 ) ;
V_83 = F_7 ( V_93 ) ;
if ( V_80 > V_82 ) {
if ( V_1 -> V_87 . V_88 != V_1 -> V_87 . V_94 )
V_84 = V_1 -> V_87 . V_88 - 1 ;
if ( V_84 < V_1 -> V_87 . V_94 )
V_84 = V_1 -> V_87 . V_94 ;
} else if ( V_81 < V_83 ) {
if ( V_1 -> V_87 . V_88 != V_1 -> V_87 . V_95 )
V_84 = V_1 -> V_87 . V_88 + 1 ;
if ( V_84 > V_1 -> V_87 . V_95 )
V_84 = V_1 -> V_87 . V_95 ;
}
if ( F_49 ( V_9 , V_84 ) )
V_1 -> V_87 . V_88 = V_84 ;
F_14 ( & V_85 , V_46 ) ;
return;
}
static void F_50 ( struct V_8 * V_9 ,
struct V_96 * V_97 )
{
struct V_98 * V_1 = V_9 -> V_10 ;
if ( V_97 -> V_99 == NULL )
return;
F_51 ( V_97 , V_97 -> V_100 ( V_97 , false ) ) ;
F_52 ( & V_97 -> V_101 ) ;
if ( V_102 ) {
V_1 -> V_103 . V_104 = 0 ;
F_43 ( & V_1 -> V_103 . V_105 ,
F_53 ( V_77 + V_106 ) ) ;
}
}
static void F_54 ( struct V_53 * V_54 )
{
T_1 * V_1 = F_36 ( V_54 , T_1 ,
V_107 . V_54 ) ;
T_2 V_108 , V_109 ;
T_3 V_84 ;
F_55 ( & V_1 -> V_107 . V_110 ) ;
V_108 = V_1 -> V_107 . V_108 ;
V_1 -> V_107 . V_108 = 0 ;
V_109 = F_7 ( V_111 ) ;
F_2 ( V_111 , 0 ) ;
F_56 ( & V_1 -> V_107 . V_110 ) ;
if ( ( V_108 & V_112 ) == 0 )
return;
F_37 ( & V_1 -> V_107 . V_113 ) ;
if ( V_108 & V_114 )
V_84 = V_1 -> V_107 . V_88 + 1 ;
else
V_84 = V_1 -> V_107 . V_88 - 1 ;
if ( ! ( V_84 > V_1 -> V_107 . V_94 ||
V_84 < V_1 -> V_107 . V_95 ) ) {
F_57 ( V_1 -> V_9 , V_84 ) ;
}
F_45 ( & V_1 -> V_107 . V_113 ) ;
}
static void F_58 ( struct V_53 * V_54 )
{
T_1 * V_1 = F_36 ( V_54 , T_1 ,
V_115 . V_116 ) ;
T_2 V_117 , V_118 , V_119 , V_120 ;
char * V_121 [ 5 ] ;
T_4 V_122 ;
unsigned long V_46 ;
F_37 ( & V_1 -> V_9 -> V_123 ) ;
V_122 = F_7 ( V_124 ) ;
F_2 ( V_124 , V_122 & ~ V_125 ) ;
F_3 ( V_124 ) ;
V_117 = F_7 ( V_126 ) ;
V_118 = F_59 ( V_117 ) ;
V_119 = F_60 ( V_117 ) ;
V_120 = F_61 ( V_117 ) ;
F_2 ( V_126 , V_127 |
V_128 ) ;
F_3 ( V_126 ) ;
F_2 ( V_124 , V_122 ) ;
F_11 ( & V_1 -> V_12 , V_46 ) ;
V_1 -> V_129 &= ~ V_130 ;
F_2 ( V_131 , V_1 -> V_129 ) ;
F_14 ( & V_1 -> V_12 , V_46 ) ;
F_45 ( & V_1 -> V_9 -> V_123 ) ;
V_121 [ 0 ] = L_9 ;
V_121 [ 1 ] = F_62 ( V_132 , L_10 , V_118 ) ;
V_121 [ 2 ] = F_62 ( V_132 , L_11 , V_119 ) ;
V_121 [ 3 ] = F_62 ( V_132 , L_12 , V_120 ) ;
V_121 [ 4 ] = NULL ;
F_63 ( & V_1 -> V_9 -> V_133 -> V_134 . V_135 ,
V_136 , V_121 ) ;
F_64 ( L_13 ,
V_118 , V_119 , V_120 ) ;
F_65 ( V_121 [ 3 ] ) ;
F_65 ( V_121 [ 2 ] ) ;
F_65 ( V_121 [ 1 ] ) ;
}
static void F_66 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_46 ;
if ( ! F_67 ( V_9 ) )
return;
F_11 ( & V_1 -> V_12 , V_46 ) ;
V_1 -> V_129 |= V_130 ;
F_2 ( V_131 , V_1 -> V_129 ) ;
F_14 ( & V_1 -> V_12 , V_46 ) ;
F_68 ( V_1 -> V_137 , & V_1 -> V_115 . V_116 ) ;
}
static void F_69 ( struct V_8 * V_9 ,
struct V_98 * V_1 ,
T_2 V_138 )
{
if ( V_138 & ( V_139 |
V_140 ) )
F_50 ( V_9 , & V_1 -> V_97 [ V_141 ] ) ;
if ( V_138 & V_142 )
F_50 ( V_9 , & V_1 -> V_97 [ V_143 ] ) ;
if ( V_138 & V_144 )
F_50 ( V_9 , & V_1 -> V_97 [ V_145 ] ) ;
if ( V_138 & ( V_146 |
V_147 |
V_148 ) ) {
F_31 ( L_14 , V_138 ) ;
F_70 ( V_9 , false ) ;
}
if ( V_138 & V_130 )
F_66 ( V_9 ) ;
}
static void F_71 ( struct V_98 * V_1 ,
T_2 V_108 )
{
unsigned long V_46 ;
F_11 ( & V_1 -> V_107 . V_110 , V_46 ) ;
V_1 -> V_107 . V_108 |= V_108 ;
F_2 ( V_111 , V_1 -> V_107 . V_108 ) ;
F_3 ( V_111 ) ;
F_14 ( & V_1 -> V_107 . V_110 , V_46 ) ;
F_68 ( V_1 -> V_137 , & V_1 -> V_107 . V_54 ) ;
}
static inline bool F_72 ( struct V_8 * V_9 ,
T_2 V_149 ,
const T_2 * V_150 )
{
T_1 * V_1 = V_9 -> V_10 ;
unsigned long V_11 ;
int V_151 ;
bool V_37 = false ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
for ( V_151 = 1 ; V_151 < V_152 ; V_151 ++ ) {
if ( ! ( V_150 [ V_151 ] & V_149 ) ||
V_1 -> V_68 [ V_151 ] . V_69 != V_153 )
continue;
if ( ! F_73 ( V_77 , V_1 -> V_68 [ V_151 ] . V_154 ,
V_1 -> V_68 [ V_151 ] . V_154
+ F_44 ( V_155 ) ) ) {
V_1 -> V_68 [ V_151 ] . V_154 = V_77 ;
V_1 -> V_68 [ V_151 ] . V_156 = 0 ;
} else if ( V_1 -> V_68 [ V_151 ] . V_156 > V_157 ) {
V_1 -> V_68 [ V_151 ] . V_69 = V_70 ;
F_33 ( L_15 , V_151 ) ;
V_37 = true ;
} else {
V_1 -> V_68 [ V_151 ] . V_156 ++ ;
}
}
F_14 ( & V_1 -> V_12 , V_11 ) ;
return V_37 ;
}
static void F_74 ( struct V_8 * V_9 )
{
struct V_98 * V_1 = ( T_1 * ) V_9 -> V_10 ;
F_52 ( & V_1 -> V_158 ) ;
}
static void F_75 ( struct V_8 * V_9 )
{
struct V_98 * V_1 = ( T_1 * ) V_9 -> V_10 ;
F_52 ( & V_1 -> V_158 ) ;
}
static T_5 F_76 ( int V_159 , void * V_160 )
{
struct V_8 * V_9 = (struct V_8 * ) V_160 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_161 , V_138 , V_108 ;
T_5 V_37 = V_162 ;
unsigned long V_11 ;
int V_5 ;
T_2 V_163 [ V_164 ] ;
F_77 ( & V_1 -> V_165 ) ;
while ( true ) {
V_161 = F_7 ( V_166 ) ;
V_138 = F_7 ( V_167 ) ;
V_108 = F_7 ( V_168 ) ;
if ( V_138 == 0 && V_108 == 0 && V_161 == 0 )
goto V_169;
V_37 = V_170 ;
F_69 ( V_9 , V_1 , V_138 ) ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
F_78 (pipe) {
int V_6 = F_6 ( V_5 ) ;
V_163 [ V_5 ] = F_7 ( V_6 ) ;
if ( V_163 [ V_5 ] & 0x8000ffff ) {
if ( V_163 [ V_5 ] & V_171 )
F_19 ( L_16 ,
F_20 ( V_5 ) ) ;
F_2 ( V_6 , V_163 [ V_5 ] ) ;
}
}
F_14 ( & V_1 -> V_12 , V_11 ) ;
F_78 (pipe) {
if ( V_163 [ V_5 ] & V_172 )
F_79 ( V_9 , V_5 ) ;
if ( V_163 [ V_5 ] & V_173 ) {
F_80 ( V_9 , V_5 ) ;
F_81 ( V_9 , V_5 ) ;
}
}
if ( V_161 & V_174 ) {
T_2 V_175 = F_7 ( V_176 ) ;
T_2 V_149 = V_175 & V_177 ;
F_19 ( L_17 ,
V_175 ) ;
if ( V_149 ) {
if ( F_72 ( V_9 , V_149 , V_178 ) )
F_82 ( V_9 ) ;
F_68 ( V_1 -> V_137 ,
& V_1 -> V_55 ) ;
}
F_2 ( V_176 , V_175 ) ;
F_7 ( V_176 ) ;
}
if ( V_163 [ 0 ] & V_179 )
F_74 ( V_9 ) ;
if ( V_108 & V_112 )
F_71 ( V_1 , V_108 ) ;
F_2 ( V_167 , V_138 ) ;
F_2 ( V_168 , V_108 ) ;
F_2 ( V_166 , V_161 ) ;
}
V_169:
return V_37 ;
}
static void F_83 ( struct V_8 * V_9 , T_2 V_180 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
T_2 V_149 = V_180 & V_181 ;
if ( V_149 ) {
if ( F_72 ( V_9 , V_149 , V_182 ) )
F_84 ( V_9 ) ;
F_68 ( V_1 -> V_137 , & V_1 -> V_55 ) ;
}
if ( V_180 & V_183 )
F_19 ( L_18 ,
( V_180 & V_183 ) >>
V_184 ) ;
if ( V_180 & V_185 )
F_75 ( V_9 ) ;
if ( V_180 & V_186 )
F_74 ( V_9 ) ;
if ( V_180 & V_187 )
F_19 ( L_19 ) ;
if ( V_180 & V_188 )
F_19 ( L_20 ) ;
if ( V_180 & V_189 )
F_31 ( L_21 ) ;
if ( V_180 & V_190 )
F_78 (pipe)
F_19 ( L_22 ,
F_20 ( V_5 ) ,
F_7 ( F_85 ( V_5 ) ) ) ;
if ( V_180 & ( V_191 | V_192 ) )
F_19 ( L_23 ) ;
if ( V_180 & ( V_193 | V_194 ) )
F_19 ( L_24 ) ;
if ( V_180 & V_195 )
F_19 ( L_25 ) ;
if ( V_180 & V_196 )
F_19 ( L_26 ) ;
}
static void F_86 ( struct V_8 * V_9 , T_2 V_180 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
T_2 V_149 = V_180 & V_197 ;
if ( V_149 ) {
if ( F_72 ( V_9 , V_149 , V_198 ) )
F_84 ( V_9 ) ;
F_68 ( V_1 -> V_137 , & V_1 -> V_55 ) ;
}
if ( V_180 & V_199 )
F_19 ( L_18 ,
( V_180 & V_199 ) >>
V_200 ) ;
if ( V_180 & V_201 )
F_75 ( V_9 ) ;
if ( V_180 & V_202 )
F_74 ( V_9 ) ;
if ( V_180 & V_203 )
F_19 ( L_27 ) ;
if ( V_180 & V_204 )
F_19 ( L_28 ) ;
if ( V_180 & V_205 )
F_78 (pipe)
F_19 ( L_22 ,
F_20 ( V_5 ) ,
F_7 ( F_85 ( V_5 ) ) ) ;
}
static T_5 F_87 ( int V_159 , void * V_160 )
{
struct V_8 * V_9 = (struct V_8 * ) V_160 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_206 , V_138 , V_207 , V_108 , V_208 = 0 ;
T_5 V_37 = V_162 ;
int V_151 ;
F_77 ( & V_1 -> V_165 ) ;
V_207 = F_7 ( V_209 ) ;
F_2 ( V_209 , V_207 & ~ V_210 ) ;
if ( ! F_88 ( V_9 ) ) {
V_208 = F_7 ( V_211 ) ;
F_2 ( V_211 , 0 ) ;
F_3 ( V_211 ) ;
}
V_138 = F_7 ( V_167 ) ;
if ( V_138 ) {
F_69 ( V_9 , V_1 , V_138 ) ;
F_2 ( V_167 , V_138 ) ;
V_37 = V_170 ;
}
V_206 = F_7 ( V_212 ) ;
if ( V_206 ) {
if ( V_206 & V_213 )
F_75 ( V_9 ) ;
if ( V_206 & V_214 )
F_89 ( V_9 ) ;
for ( V_151 = 0 ; V_151 < 3 ; V_151 ++ ) {
if ( V_206 & ( V_215 << ( 5 * V_151 ) ) )
F_79 ( V_9 , V_151 ) ;
if ( V_206 & ( V_216 << ( 5 * V_151 ) ) ) {
F_80 ( V_9 , V_151 ) ;
F_90 ( V_9 , V_151 ) ;
}
}
if ( ! F_88 ( V_9 ) && ( V_206 & V_217 ) ) {
T_2 V_180 = F_7 ( V_218 ) ;
F_86 ( V_9 , V_180 ) ;
F_2 ( V_218 , V_180 ) ;
}
F_2 ( V_212 , V_206 ) ;
V_37 = V_170 ;
}
V_108 = F_7 ( V_168 ) ;
if ( V_108 ) {
if ( V_108 & V_112 )
F_71 ( V_1 , V_108 ) ;
F_2 ( V_168 , V_108 ) ;
V_37 = V_170 ;
}
F_2 ( V_209 , V_207 ) ;
F_3 ( V_209 ) ;
if ( ! F_88 ( V_9 ) ) {
F_2 ( V_211 , V_208 ) ;
F_3 ( V_211 ) ;
}
return V_37 ;
}
static void F_91 ( struct V_8 * V_9 ,
struct V_98 * V_1 ,
T_2 V_138 )
{
if ( V_138 & ( V_219 | V_220 ) )
F_50 ( V_9 , & V_1 -> V_97 [ V_141 ] ) ;
if ( V_138 & V_221 )
F_50 ( V_9 , & V_1 -> V_97 [ V_143 ] ) ;
}
static T_5 F_92 ( int V_159 , void * V_160 )
{
struct V_8 * V_9 = (struct V_8 * ) V_160 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_37 = V_162 ;
T_2 V_206 , V_138 , V_207 , V_108 , V_208 ;
F_77 ( & V_1 -> V_165 ) ;
V_207 = F_7 ( V_209 ) ;
F_2 ( V_209 , V_207 & ~ V_210 ) ;
F_3 ( V_209 ) ;
V_208 = F_7 ( V_211 ) ;
F_2 ( V_211 , 0 ) ;
F_3 ( V_211 ) ;
V_206 = F_7 ( V_212 ) ;
V_138 = F_7 ( V_167 ) ;
V_108 = F_7 ( V_168 ) ;
if ( V_206 == 0 && V_138 == 0 && ( ! F_93 ( V_9 ) || V_108 == 0 ) )
goto V_222;
V_37 = V_170 ;
if ( F_94 ( V_9 ) )
F_91 ( V_9 , V_1 , V_138 ) ;
else
F_69 ( V_9 , V_1 , V_138 ) ;
if ( V_206 & V_223 )
F_75 ( V_9 ) ;
if ( V_206 & V_13 )
F_89 ( V_9 ) ;
if ( V_206 & V_224 )
F_79 ( V_9 , 0 ) ;
if ( V_206 & V_225 )
F_79 ( V_9 , 1 ) ;
if ( V_206 & V_226 ) {
F_80 ( V_9 , 0 ) ;
F_90 ( V_9 , 0 ) ;
}
if ( V_206 & V_227 ) {
F_80 ( V_9 , 1 ) ;
F_90 ( V_9 , 1 ) ;
}
if ( V_206 & V_228 ) {
T_2 V_180 = F_7 ( V_218 ) ;
if ( F_95 ( V_9 ) )
F_86 ( V_9 , V_180 ) ;
else
F_83 ( V_9 , V_180 ) ;
F_2 ( V_218 , V_180 ) ;
}
if ( F_94 ( V_9 ) && V_206 & V_229 )
F_47 ( V_9 ) ;
if ( F_93 ( V_9 ) && V_108 & V_112 )
F_71 ( V_1 , V_108 ) ;
F_2 ( V_167 , V_138 ) ;
F_2 ( V_212 , V_206 ) ;
F_2 ( V_168 , V_108 ) ;
V_222:
F_2 ( V_209 , V_207 ) ;
F_3 ( V_209 ) ;
F_2 ( V_211 , V_208 ) ;
F_3 ( V_211 ) ;
return V_37 ;
}
static void F_96 ( struct V_53 * V_54 )
{
struct V_230 * error = F_36 ( V_54 , struct V_230 ,
V_54 ) ;
T_1 * V_1 = F_36 ( error , T_1 ,
V_103 ) ;
struct V_8 * V_9 = V_1 -> V_9 ;
struct V_96 * V_97 ;
char * V_231 [] = { L_29 , NULL } ;
char * V_232 [] = { L_30 , NULL } ;
char * V_233 [] = { L_31 , NULL } ;
int V_151 , V_37 ;
F_63 ( & V_9 -> V_133 -> V_134 . V_135 , V_136 , V_231 ) ;
if ( F_97 ( error ) && ! F_98 ( error ) ) {
F_19 ( L_32 ) ;
F_63 ( & V_9 -> V_133 -> V_134 . V_135 , V_136 ,
V_232 ) ;
V_37 = F_99 ( V_9 ) ;
if ( V_37 == 0 ) {
F_100 () ;
F_77 ( & V_1 -> V_103 . V_234 ) ;
F_63 ( & V_9 -> V_133 -> V_134 . V_135 ,
V_136 , V_233 ) ;
} else {
F_101 ( & error -> V_234 , V_235 ) ;
}
F_102 (ring, dev_priv, i)
F_52 ( & V_97 -> V_101 ) ;
F_103 ( V_9 ) ;
F_52 ( & V_1 -> V_103 . V_236 ) ;
}
}
static void F_104 ( struct V_8 * V_9 ,
T_4 * V_237 )
{
struct V_98 * V_1 = V_9 -> V_10 ;
memset ( V_237 , 0 , sizeof( * V_237 ) * V_238 ) ;
switch( F_13 ( V_9 ) -> V_15 ) {
case 2 :
case 3 :
V_237 [ 0 ] = F_7 ( V_239 ) ;
break;
case 4 :
case 5 :
case 6 :
V_237 [ 0 ] = F_7 ( V_240 ) ;
V_237 [ 1 ] = F_7 ( V_241 ) ;
break;
default:
F_105 ( 1 , L_33 ) ;
case 7 :
V_237 [ 0 ] = F_7 ( V_242 ) ;
V_237 [ 1 ] = F_7 ( V_243 ) ;
V_237 [ 2 ] = F_7 ( V_244 ) ;
V_237 [ 3 ] = F_7 ( V_245 ) ;
break;
}
}
static struct V_246 *
F_106 ( struct V_98 * V_1 ,
struct V_247 * V_248 ,
const int V_249 )
{
struct V_246 * V_250 ;
int V_151 ;
T_2 V_251 ;
if ( V_248 == NULL || V_248 -> V_252 == NULL )
return NULL ;
V_250 = F_107 ( sizeof( * V_250 ) + V_249 * sizeof( T_2 * ) , V_253 ) ;
if ( V_250 == NULL )
return NULL ;
V_251 = V_248 -> V_254 ;
for ( V_151 = 0 ; V_151 < V_249 ; V_151 ++ ) {
unsigned long V_46 ;
void * V_255 ;
V_255 = F_107 ( V_256 , V_253 ) ;
if ( V_255 == NULL )
goto V_257;
F_108 ( V_46 ) ;
if ( V_251 < V_1 -> V_258 . V_259 &&
V_248 -> V_260 ) {
void T_6 * V_261 ;
V_261 = F_109 ( V_1 -> V_258 . V_262 ,
V_251 ) ;
F_110 ( V_255 , V_261 , V_256 ) ;
F_111 ( V_261 ) ;
} else if ( V_248 -> V_263 ) {
unsigned long V_264 ;
V_264 = V_1 -> V_265 . V_266 ;
V_264 += V_248 -> V_263 -> V_267 ;
V_264 += V_151 << V_268 ;
F_110 ( V_255 , ( void T_6 * ) V_264 , V_256 ) ;
} else {
struct V_269 * V_269 ;
void * V_261 ;
V_269 = F_112 ( V_248 , V_151 ) ;
F_113 ( & V_269 , 1 ) ;
V_261 = F_114 ( V_269 ) ;
memcpy ( V_255 , V_261 , V_256 ) ;
F_115 ( V_261 ) ;
F_113 ( & V_269 , 1 ) ;
}
F_116 ( V_46 ) ;
V_250 -> V_252 [ V_151 ] = V_255 ;
V_251 += V_256 ;
}
V_250 -> V_270 = V_249 ;
V_250 -> V_254 = V_248 -> V_254 ;
return V_250 ;
V_257:
while ( V_151 -- )
F_65 ( V_250 -> V_252 [ V_151 ] ) ;
F_65 ( V_250 ) ;
return NULL ;
}
static void
F_117 ( struct V_246 * V_99 )
{
int V_269 ;
if ( V_99 == NULL )
return;
for ( V_269 = 0 ; V_269 < V_99 -> V_270 ; V_269 ++ )
F_65 ( V_99 -> V_252 [ V_269 ] ) ;
F_65 ( V_99 ) ;
}
void
F_118 ( struct V_271 * V_272 )
{
struct V_273 * error = F_36 ( V_272 ,
F_119 ( * error ) , V_274 ) ;
int V_151 ;
for ( V_151 = 0 ; V_151 < F_120 ( error -> V_97 ) ; V_151 ++ ) {
F_117 ( error -> V_97 [ V_151 ] . V_275 ) ;
F_117 ( error -> V_97 [ V_151 ] . V_276 ) ;
F_65 ( error -> V_97 [ V_151 ] . V_277 ) ;
}
F_65 ( error -> V_278 ) ;
F_65 ( error -> V_279 ) ;
F_65 ( error ) ;
}
static void F_121 ( struct V_280 * V_281 ,
struct V_247 * V_99 )
{
V_281 -> V_282 = V_99 -> V_283 . V_282 ;
V_281 -> V_284 = V_99 -> V_283 . V_284 ;
V_281 -> V_285 = V_99 -> V_286 ;
V_281 -> V_287 = V_99 -> V_288 ;
V_281 -> V_254 = V_99 -> V_254 ;
V_281 -> V_289 = V_99 -> V_283 . V_289 ;
V_281 -> V_290 = V_99 -> V_283 . V_290 ;
V_281 -> V_291 = V_99 -> V_291 ;
V_281 -> V_292 = 0 ;
if ( V_99 -> V_293 > 0 )
V_281 -> V_292 = 1 ;
if ( V_99 -> V_294 > 0 )
V_281 -> V_292 = - 1 ;
V_281 -> V_295 = V_99 -> V_296 ;
V_281 -> V_297 = V_99 -> V_297 ;
V_281 -> V_298 = V_99 -> V_299 != V_300 ;
V_281 -> V_97 = V_99 -> V_97 ? V_99 -> V_97 -> V_301 : - 1 ;
V_281 -> V_302 = V_99 -> V_302 ;
}
static T_2 F_122 ( struct V_280 * V_281 ,
int V_303 , struct V_304 * V_305 )
{
struct V_247 * V_99 ;
int V_151 = 0 ;
F_38 (obj, head, mm_list) {
F_121 ( V_281 ++ , V_99 ) ;
if ( ++ V_151 == V_303 )
break;
}
return V_151 ;
}
static T_2 F_123 ( struct V_280 * V_281 ,
int V_303 , struct V_304 * V_305 )
{
struct V_247 * V_99 ;
int V_151 = 0 ;
F_38 (obj, head, gtt_list) {
if ( V_99 -> V_293 == 0 )
continue;
F_121 ( V_281 ++ , V_99 ) ;
if ( ++ V_151 == V_303 )
break;
}
return V_151 ;
}
static void F_124 ( struct V_8 * V_9 ,
struct V_273 * error )
{
struct V_98 * V_1 = V_9 -> V_10 ;
int V_151 ;
switch ( F_13 ( V_9 ) -> V_15 ) {
case 7 :
case 6 :
for ( V_151 = 0 ; V_151 < V_1 -> V_306 ; V_151 ++ )
error -> V_307 [ V_151 ] = F_125 ( V_308 + ( V_151 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_151 = 0 ; V_151 < 16 ; V_151 ++ )
error -> V_307 [ V_151 ] = F_125 ( V_309 + ( V_151 * 8 ) ) ;
break;
case 3 :
if ( F_126 ( V_9 ) || F_127 ( V_9 ) || F_128 ( V_9 ) )
for ( V_151 = 0 ; V_151 < 8 ; V_151 ++ )
error -> V_307 [ V_151 + 8 ] = F_7 ( V_310 + ( V_151 * 4 ) ) ;
case 2 :
for ( V_151 = 0 ; V_151 < 8 ; V_151 ++ )
error -> V_307 [ V_151 ] = F_7 ( V_311 + ( V_151 * 4 ) ) ;
break;
default:
F_129 () ;
}
}
static struct V_246 *
F_130 ( struct V_98 * V_1 ,
struct V_96 * V_97 )
{
struct V_247 * V_99 ;
T_2 V_312 ;
if ( ! V_97 -> V_100 )
return NULL ;
if ( F_131 ( V_1 -> V_9 ) ) {
T_2 V_313 = F_7 ( V_314 ) ;
if ( F_132 ( V_97 -> V_301 != V_141 ) )
return NULL ;
V_99 = V_97 -> V_315 ;
if ( V_313 >= V_99 -> V_254 &&
V_313 < V_99 -> V_254 + V_99 -> V_283 . V_282 )
return F_133 ( V_1 , V_99 ) ;
}
V_312 = V_97 -> V_100 ( V_97 , false ) ;
F_38 (obj, &dev_priv->mm.active_list, mm_list) {
if ( V_99 -> V_97 != V_97 )
continue;
if ( F_134 ( V_312 , V_99 -> V_286 ) )
continue;
if ( ( V_99 -> V_283 . V_289 & V_316 ) == 0 )
continue;
return F_133 ( V_1 , V_99 ) ;
}
return NULL ;
}
static void F_135 ( struct V_8 * V_9 ,
struct V_273 * error ,
struct V_96 * V_97 )
{
struct V_98 * V_1 = V_9 -> V_10 ;
if ( F_13 ( V_9 ) -> V_15 >= 6 ) {
error -> V_317 [ V_97 -> V_301 ] = F_7 ( V_97 -> V_318 + 0x50 ) ;
error -> V_319 [ V_97 -> V_301 ] = F_7 ( F_136 ( V_97 ) ) ;
error -> V_320 [ V_97 -> V_301 ] [ 0 ]
= F_7 ( F_137 ( V_97 -> V_318 ) ) ;
error -> V_320 [ V_97 -> V_301 ] [ 1 ]
= F_7 ( F_138 ( V_97 -> V_318 ) ) ;
error -> V_321 [ V_97 -> V_301 ] [ 0 ] = V_97 -> V_322 [ 0 ] ;
error -> V_321 [ V_97 -> V_301 ] [ 1 ] = V_97 -> V_322 [ 1 ] ;
}
if ( F_13 ( V_9 ) -> V_15 >= 4 ) {
error -> V_323 [ V_97 -> V_301 ] = F_7 ( F_139 ( V_97 -> V_318 ) ) ;
error -> V_324 [ V_97 -> V_301 ] = F_7 ( F_140 ( V_97 -> V_318 ) ) ;
error -> V_325 [ V_97 -> V_301 ] = F_7 ( F_141 ( V_97 -> V_318 ) ) ;
error -> V_237 [ V_97 -> V_301 ] = F_7 ( F_142 ( V_97 -> V_318 ) ) ;
error -> V_326 [ V_97 -> V_301 ] = F_7 ( F_143 ( V_97 -> V_318 ) ) ;
if ( V_97 -> V_301 == V_141 )
error -> V_327 = F_125 ( V_328 ) ;
} else {
error -> V_323 [ V_97 -> V_301 ] = F_7 ( V_329 ) ;
error -> V_324 [ V_97 -> V_301 ] = F_7 ( V_330 ) ;
error -> V_325 [ V_97 -> V_301 ] = F_7 ( V_331 ) ;
error -> V_237 [ V_97 -> V_301 ] = F_7 ( V_239 ) ;
}
error -> V_332 [ V_97 -> V_301 ] = F_144 ( & V_97 -> V_101 ) ;
error -> V_333 [ V_97 -> V_301 ] = F_7 ( F_145 ( V_97 -> V_318 ) ) ;
error -> V_312 [ V_97 -> V_301 ] = V_97 -> V_100 ( V_97 , false ) ;
error -> V_313 [ V_97 -> V_301 ] = F_146 ( V_97 ) ;
error -> V_305 [ V_97 -> V_301 ] = F_147 ( V_97 ) ;
error -> V_334 [ V_97 -> V_301 ] = F_148 ( V_97 ) ;
error -> V_335 [ V_97 -> V_301 ] = F_149 ( V_97 ) ;
error -> V_336 [ V_97 -> V_301 ] = V_97 -> V_305 ;
error -> V_337 [ V_97 -> V_301 ] = V_97 -> V_334 ;
}
static void F_150 ( struct V_96 * V_97 ,
struct V_273 * error ,
struct V_338 * V_339 )
{
struct V_98 * V_1 = V_97 -> V_9 -> V_10 ;
struct V_247 * V_99 ;
if ( V_97 -> V_301 != V_141 || ! error -> V_340 )
return;
F_38 (obj, &dev_priv->mm.bound_list, gtt_list) {
if ( ( error -> V_340 & V_341 ) == V_99 -> V_254 ) {
V_339 -> V_342 = F_106 ( V_1 ,
V_99 , 1 ) ;
}
}
}
static void F_151 ( struct V_8 * V_9 ,
struct V_273 * error )
{
struct V_98 * V_1 = V_9 -> V_10 ;
struct V_96 * V_97 ;
struct V_343 * V_344 ;
int V_151 , V_303 ;
F_102 (ring, dev_priv, i) {
F_135 ( V_9 , error , V_97 ) ;
error -> V_97 [ V_151 ] . V_275 =
F_130 ( V_1 , V_97 ) ;
error -> V_97 [ V_151 ] . V_276 =
F_133 ( V_1 , V_97 -> V_99 ) ;
F_150 ( V_97 , error , & error -> V_97 [ V_151 ] ) ;
V_303 = 0 ;
F_38 (request, &ring->request_list, list)
V_303 ++ ;
error -> V_97 [ V_151 ] . V_345 = V_303 ;
error -> V_97 [ V_151 ] . V_277 =
F_107 ( V_303 * sizeof( struct V_346 ) ,
V_253 ) ;
if ( error -> V_97 [ V_151 ] . V_277 == NULL ) {
error -> V_97 [ V_151 ] . V_345 = 0 ;
continue;
}
V_303 = 0 ;
F_38 (request, &ring->request_list, list) {
struct V_346 * V_347 ;
V_347 = & error -> V_97 [ V_151 ] . V_277 [ V_303 ++ ] ;
V_347 -> V_312 = V_344 -> V_312 ;
V_347 -> V_77 = V_344 -> V_348 ;
V_347 -> V_334 = V_344 -> V_334 ;
}
}
}
static void F_152 ( struct V_8 * V_9 )
{
struct V_98 * V_1 = V_9 -> V_10 ;
struct V_247 * V_99 ;
struct V_273 * error ;
unsigned long V_46 ;
int V_151 , V_5 ;
F_11 ( & V_1 -> V_103 . V_110 , V_46 ) ;
error = V_1 -> V_103 . V_349 ;
F_14 ( & V_1 -> V_103 . V_110 , V_46 ) ;
if ( error )
return;
error = F_153 ( sizeof( * error ) , V_253 ) ;
if ( ! error ) {
F_19 ( L_34 ) ;
return;
}
F_40 ( L_35
L_36 ,
V_9 -> V_133 -> V_350 ) ;
F_154 ( & error -> V_274 ) ;
error -> V_351 = F_7 ( V_352 ) ;
error -> V_353 = F_7 ( V_354 ) ;
if ( F_155 ( V_9 ) )
error -> V_340 = F_7 ( V_355 ) ;
if ( F_12 ( V_9 ) )
error -> V_356 = F_7 ( V_209 ) | F_7 ( V_357 ) ;
else if ( F_10 ( V_9 ) )
error -> V_356 = F_7 ( V_357 ) | F_7 ( V_358 ) ;
else if ( F_156 ( V_9 ) )
error -> V_356 = F_157 ( V_359 ) ;
else
error -> V_356 = F_7 ( V_359 ) ;
if ( F_13 ( V_9 ) -> V_15 >= 6 )
error -> V_360 = F_7 ( V_361 ) ;
if ( F_10 ( V_9 ) )
error -> V_362 = F_7 ( V_363 ) ;
else if ( F_13 ( V_9 ) -> V_15 >= 7 )
error -> V_362 = F_7 ( V_364 ) ;
else if ( F_13 ( V_9 ) -> V_15 == 6 )
error -> V_362 = F_7 ( V_365 ) ;
if ( ! F_12 ( V_9 ) )
F_78 ( V_5 )
error -> V_7 [ V_5 ] = F_7 ( F_6 ( V_5 ) ) ;
if ( F_13 ( V_9 ) -> V_15 >= 6 ) {
error -> error = F_7 ( V_366 ) ;
error -> V_367 = F_7 ( V_368 ) ;
}
if ( F_13 ( V_9 ) -> V_15 == 7 )
error -> V_369 = F_7 ( V_370 ) ;
F_104 ( V_9 , error -> V_371 ) ;
F_124 ( V_9 , error ) ;
F_151 ( V_9 , error ) ;
error -> V_278 = NULL ;
error -> V_372 = NULL ;
V_151 = 0 ;
F_38 (obj, &dev_priv->mm.active_list, mm_list)
V_151 ++ ;
error -> V_373 = V_151 ;
F_38 (obj, &dev_priv->mm.bound_list, gtt_list)
if ( V_99 -> V_293 )
V_151 ++ ;
error -> V_374 = V_151 - error -> V_373 ;
error -> V_278 = NULL ;
error -> V_372 = NULL ;
if ( V_151 ) {
error -> V_278 = F_107 ( sizeof( * error -> V_278 ) * V_151 ,
V_253 ) ;
if ( error -> V_278 )
error -> V_372 =
error -> V_278 + error -> V_373 ;
}
if ( error -> V_278 )
error -> V_373 =
F_122 ( error -> V_278 ,
error -> V_373 ,
& V_1 -> V_265 . V_375 ) ;
if ( error -> V_372 )
error -> V_374 =
F_123 ( error -> V_372 ,
error -> V_374 ,
& V_1 -> V_265 . V_376 ) ;
F_158 ( & error -> time ) ;
error -> V_279 = F_159 ( V_9 ) ;
error -> V_377 = F_160 ( V_9 ) ;
F_11 ( & V_1 -> V_103 . V_110 , V_46 ) ;
if ( V_1 -> V_103 . V_349 == NULL ) {
V_1 -> V_103 . V_349 = error ;
error = NULL ;
}
F_14 ( & V_1 -> V_103 . V_110 , V_46 ) ;
if ( error )
F_118 ( & error -> V_274 ) ;
}
void F_161 ( struct V_8 * V_9 )
{
struct V_98 * V_1 = V_9 -> V_10 ;
struct V_273 * error ;
unsigned long V_46 ;
F_11 ( & V_1 -> V_103 . V_110 , V_46 ) ;
error = V_1 -> V_103 . V_349 ;
V_1 -> V_103 . V_349 = NULL ;
F_14 ( & V_1 -> V_103 . V_110 , V_46 ) ;
if ( error )
F_162 ( & error -> V_274 , F_118 ) ;
}
static void F_163 ( struct V_8 * V_9 )
{
struct V_98 * V_1 = V_9 -> V_10 ;
T_4 V_237 [ V_238 ] ;
T_2 V_351 = F_7 ( V_352 ) ;
int V_5 , V_151 ;
if ( ! V_351 )
return;
F_164 ( L_37 , V_351 ) ;
F_104 ( V_9 , V_237 ) ;
if ( F_165 ( V_9 ) ) {
if ( V_351 & ( V_378 | V_379 ) ) {
T_2 V_324 = F_7 ( V_380 ) ;
F_164 ( L_38 , F_7 ( V_380 ) ) ;
F_164 ( L_39 , F_7 ( V_381 ) ) ;
for ( V_151 = 0 ; V_151 < F_120 ( V_237 ) ; V_151 ++ )
F_164 ( L_40 , V_151 , V_237 [ V_151 ] ) ;
F_164 ( L_41 , F_7 ( V_382 ) ) ;
F_164 ( L_42 , F_7 ( V_383 ) ) ;
F_2 ( V_380 , V_324 ) ;
F_3 ( V_380 ) ;
}
if ( V_351 & V_384 ) {
T_2 V_385 = F_7 ( V_354 ) ;
F_164 ( L_43 ) ;
F_164 ( L_44 , V_385 ) ;
F_2 ( V_354 , V_385 ) ;
F_3 ( V_354 ) ;
}
}
if ( ! F_156 ( V_9 ) ) {
if ( V_351 & V_386 ) {
T_2 V_385 = F_7 ( V_354 ) ;
F_164 ( L_43 ) ;
F_164 ( L_44 , V_385 ) ;
F_2 ( V_354 , V_385 ) ;
F_3 ( V_354 ) ;
}
}
if ( V_351 & V_387 ) {
F_164 ( L_45 ) ;
F_78 (pipe)
F_164 ( L_46 ,
F_20 ( V_5 ) , F_7 ( F_6 ( V_5 ) ) ) ;
}
if ( V_351 & V_388 ) {
F_164 ( L_47 ) ;
F_164 ( L_48 , F_7 ( V_389 ) ) ;
for ( V_151 = 0 ; V_151 < F_120 ( V_237 ) ; V_151 ++ )
F_164 ( L_40 , V_151 , V_237 [ V_151 ] ) ;
if ( F_13 ( V_9 ) -> V_15 < 4 ) {
T_2 V_324 = F_7 ( V_330 ) ;
F_164 ( L_38 , F_7 ( V_330 ) ) ;
F_164 ( L_39 , F_7 ( V_331 ) ) ;
F_164 ( L_42 , F_7 ( V_314 ) ) ;
F_2 ( V_330 , V_324 ) ;
F_3 ( V_330 ) ;
} else {
T_2 V_324 = F_7 ( V_380 ) ;
F_164 ( L_38 , F_7 ( V_380 ) ) ;
F_164 ( L_39 , F_7 ( V_381 ) ) ;
F_164 ( L_41 , F_7 ( V_382 ) ) ;
F_164 ( L_42 , F_7 ( V_383 ) ) ;
F_2 ( V_380 , V_324 ) ;
F_3 ( V_380 ) ;
}
}
F_2 ( V_352 , V_351 ) ;
F_3 ( V_352 ) ;
V_351 = F_7 ( V_352 ) ;
if ( V_351 ) {
F_31 ( L_49 , V_351 ) ;
F_2 ( V_390 , F_7 ( V_390 ) | V_351 ) ;
F_2 ( V_391 , V_392 ) ;
}
}
void F_70 ( struct V_8 * V_9 , bool V_393 )
{
struct V_98 * V_1 = V_9 -> V_10 ;
struct V_96 * V_97 ;
int V_151 ;
F_152 ( V_9 ) ;
F_163 ( V_9 ) ;
if ( V_393 ) {
F_166 ( V_394 ,
& V_1 -> V_103 . V_234 ) ;
F_102 (ring, dev_priv, i)
F_52 ( & V_97 -> V_101 ) ;
}
F_68 ( V_1 -> V_137 , & V_1 -> V_103 . V_54 ) ;
}
static void T_7 F_167 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = V_9 -> V_10 ;
struct V_47 * V_48 = V_1 -> V_395 [ V_5 ] ;
struct V_396 * V_396 = F_168 ( V_48 ) ;
struct V_247 * V_99 ;
struct V_397 * V_54 ;
unsigned long V_46 ;
bool V_398 ;
if ( V_396 == NULL )
return;
F_11 ( & V_9 -> V_399 , V_46 ) ;
V_54 = V_396 -> V_400 ;
if ( V_54 == NULL ||
F_169 ( & V_54 -> V_401 ) >= V_402 ||
! V_54 -> V_403 ) {
F_14 ( & V_9 -> V_399 , V_46 ) ;
return;
}
V_99 = V_54 -> V_404 ;
if ( F_13 ( V_9 ) -> V_15 >= 4 ) {
int V_405 = F_170 ( V_396 -> V_406 ) ;
V_398 = F_171 ( F_7 ( V_405 ) ) ==
V_99 -> V_254 ;
} else {
int V_407 = F_172 ( V_396 -> V_406 ) ;
V_398 = F_7 ( V_407 ) == ( V_99 -> V_254 +
V_48 -> V_408 * V_48 -> V_409 -> V_410 [ 0 ] +
V_48 -> V_411 * V_48 -> V_409 -> V_412 / 8 ) ;
}
F_14 ( & V_9 -> V_399 , V_46 ) ;
if ( V_398 ) {
F_19 ( L_50 ) ;
F_80 ( V_9 , V_396 -> V_406 ) ;
}
}
static int F_173 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_15 ( V_9 , V_5 ) )
return - V_50 ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
if ( F_13 ( V_9 ) -> V_15 >= 4 )
F_5 ( V_1 , V_5 ,
V_413 ) ;
else
F_5 ( V_1 , V_5 ,
V_414 ) ;
if ( V_1 -> V_415 -> V_15 == 3 )
F_2 ( V_389 , F_174 ( V_416 ) ) ;
F_14 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_175 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_15 ( V_9 , V_5 ) )
return - V_50 ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
F_1 ( V_1 , ( V_5 == 0 ) ?
V_224 : V_225 ) ;
F_14 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_176 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_15 ( V_9 , V_5 ) )
return - V_50 ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
F_1 ( V_1 ,
V_215 << ( 5 * V_5 ) ) ;
F_14 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_177 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
T_2 V_417 ;
if ( ! F_15 ( V_9 , V_5 ) )
return - V_50 ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
V_417 = F_7 ( V_418 ) ;
if ( V_5 == 0 )
V_417 &= ~ V_419 ;
else
V_417 &= ~ V_420 ;
F_2 ( V_418 , V_417 ) ;
F_5 ( V_1 , V_5 ,
V_413 ) ;
F_14 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static void F_178 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
if ( V_1 -> V_415 -> V_15 == 3 )
F_2 ( V_389 , F_179 ( V_416 ) ) ;
F_8 ( V_1 , V_5 ,
V_414 |
V_413 ) ;
F_14 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_180 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
F_4 ( V_1 , ( V_5 == 0 ) ?
V_224 : V_225 ) ;
F_14 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_181 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
F_4 ( V_1 ,
V_215 << ( V_5 * 5 ) ) ;
F_14 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_182 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
T_2 V_417 ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
F_8 ( V_1 , V_5 ,
V_413 ) ;
V_417 = F_7 ( V_418 ) ;
if ( V_5 == 0 )
V_417 |= V_419 ;
else
V_417 |= V_420 ;
F_2 ( V_418 , V_417 ) ;
F_14 ( & V_1 -> V_12 , V_11 ) ;
}
static T_2
F_183 ( struct V_96 * V_97 )
{
return F_184 ( V_97 -> V_421 . V_422 ,
struct V_343 , V_423 ) -> V_312 ;
}
static bool F_185 ( struct V_96 * V_97 , bool * V_281 )
{
if ( F_186 ( & V_97 -> V_421 ) ||
F_134 ( V_97 -> V_100 ( V_97 , false ) ,
F_183 ( V_97 ) ) ) {
if ( F_144 ( & V_97 -> V_101 ) ) {
F_31 ( L_51 ,
V_97 -> V_284 ) ;
F_52 ( & V_97 -> V_101 ) ;
* V_281 = true ;
}
return true ;
}
return false ;
}
static bool F_187 ( struct V_96 * V_97 )
{
struct V_98 * V_1 = V_97 -> V_9 -> V_10 ;
T_2 V_313 = F_146 ( V_97 ) & V_424 ;
struct V_96 * V_425 ;
T_2 V_426 , V_325 , V_427 ;
V_325 = F_7 ( F_141 ( V_97 -> V_318 ) ) ;
if ( ( V_325 & ~ ( 0x3 << 16 ) ) !=
( V_428 | V_429 | V_430 ) )
return false ;
V_427 = F_188 ( ( int ) V_313 - 3 * 4 , 0 ) ;
do {
V_426 = F_189 ( V_97 -> V_431 + V_313 ) ;
if ( V_426 == V_325 )
break;
V_313 -= 4 ;
if ( V_313 < V_427 )
return false ;
} while ( 1 );
V_425 = & V_1 -> V_97 [ ( V_97 -> V_301 + ( ( ( V_325 >> 17 ) & 1 ) + 1 ) ) % 3 ] ;
return F_134 ( V_425 -> V_100 ( V_425 , false ) ,
F_189 ( V_97 -> V_431 + V_313 + 4 ) + 1 ) ;
}
static bool F_190 ( struct V_96 * V_97 )
{
struct V_8 * V_9 = V_97 -> V_9 ;
struct V_98 * V_1 = V_9 -> V_10 ;
T_2 V_432 = F_149 ( V_97 ) ;
if ( V_432 & V_433 ) {
F_31 ( L_52 ,
V_97 -> V_284 ) ;
F_191 ( V_97 , V_432 ) ;
return true ;
}
if ( F_13 ( V_9 ) -> V_15 >= 6 &&
V_432 & V_434 &&
F_187 ( V_97 ) ) {
F_31 ( L_53 ,
V_97 -> V_284 ) ;
F_191 ( V_97 , V_432 ) ;
return true ;
}
return false ;
}
static bool F_192 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
if ( V_1 -> V_103 . V_104 ++ > 1 ) {
bool V_435 = true ;
F_31 ( L_54 ) ;
F_70 ( V_9 , true ) ;
if ( ! F_156 ( V_9 ) ) {
struct V_96 * V_97 ;
int V_151 ;
F_102 (ring, dev_priv, i)
V_435 &= ! F_190 ( V_97 ) ;
}
return V_435 ;
}
return false ;
}
void F_193 ( unsigned long V_436 )
{
struct V_8 * V_9 = (struct V_8 * ) V_436 ;
T_1 * V_1 = V_9 -> V_10 ;
T_4 V_313 [ V_437 ] , V_237 [ V_238 ] ;
struct V_96 * V_97 ;
bool V_281 = false , V_438 ;
int V_151 ;
if ( ! V_102 )
return;
memset ( V_313 , 0 , sizeof( V_313 ) ) ;
V_438 = true ;
F_102 (ring, dev_priv, i) {
V_438 &= F_185 ( V_97 , & V_281 ) ;
V_313 [ V_151 ] = F_146 ( V_97 ) ;
}
if ( V_438 ) {
if ( V_281 ) {
if ( F_192 ( V_9 ) )
return;
goto V_439;
}
V_1 -> V_103 . V_104 = 0 ;
return;
}
F_104 ( V_9 , V_237 ) ;
if ( memcmp ( V_1 -> V_103 . V_440 , V_313 ,
sizeof( V_313 ) ) == 0 &&
memcmp ( V_1 -> V_103 . V_441 , V_237 ,
sizeof( V_237 ) ) == 0 ) {
if ( F_192 ( V_9 ) )
return;
} else {
V_1 -> V_103 . V_104 = 0 ;
memcpy ( V_1 -> V_103 . V_440 , V_313 ,
sizeof( V_313 ) ) ;
memcpy ( V_1 -> V_103 . V_441 , V_237 ,
sizeof( V_237 ) ) ;
}
V_439:
F_43 ( & V_1 -> V_103 . V_105 ,
F_53 ( V_77 + V_106 ) ) ;
}
static void F_194 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
F_101 ( & V_1 -> V_165 , 0 ) ;
F_2 ( V_442 , 0xeffe ) ;
F_2 ( V_4 , 0xffffffff ) ;
F_2 ( V_209 , 0x0 ) ;
F_3 ( V_209 ) ;
F_2 ( V_131 , 0xffffffff ) ;
F_2 ( V_357 , 0x0 ) ;
F_3 ( V_357 ) ;
if ( F_88 ( V_9 ) )
return;
F_2 ( V_443 , 0xffffffff ) ;
F_2 ( V_211 , 0xffffffff ) ;
F_3 ( V_211 ) ;
}
static void F_195 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_101 ( & V_1 -> V_165 , 0 ) ;
F_2 ( V_418 , 0 ) ;
F_2 ( F_196 ( V_444 ) , 0 ) ;
F_2 ( F_196 ( V_445 ) , 0 ) ;
F_2 ( F_196 ( V_446 ) , 0 ) ;
F_2 ( V_167 , F_7 ( V_167 ) ) ;
F_2 ( V_167 , F_7 ( V_167 ) ) ;
F_2 ( V_131 , 0xffffffff ) ;
F_2 ( V_357 , 0x0 ) ;
F_3 ( V_357 ) ;
F_2 ( V_447 , 0xff ) ;
F_2 ( V_448 , 0 ) ;
F_2 ( V_176 , F_7 ( V_176 ) ) ;
F_78 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_166 , 0xffffffff ) ;
F_2 ( V_418 , 0xffffffff ) ;
F_2 ( V_358 , 0x0 ) ;
F_3 ( V_358 ) ;
}
static void F_84 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
struct V_56 * V_57 = & V_9 -> V_57 ;
struct V_59 * V_59 ;
T_2 V_2 = ~ F_7 ( V_443 ) ;
T_2 V_449 ;
if ( F_197 ( V_9 ) ) {
V_2 &= ~ V_181 ;
F_38 (intel_encoder, &mode_config->encoder_list, base.head)
if ( V_1 -> V_68 [ V_59 -> V_66 ] . V_69 == V_153 )
V_2 |= V_182 [ V_59 -> V_66 ] ;
} else {
V_2 &= ~ V_197 ;
F_38 (intel_encoder, &mode_config->encoder_list, base.head)
if ( V_1 -> V_68 [ V_59 -> V_66 ] . V_69 == V_153 )
V_2 |= V_198 [ V_59 -> V_66 ] ;
}
F_2 ( V_443 , ~ V_2 ) ;
V_449 = F_7 ( V_450 ) ;
V_449 &= ~ ( V_451 | V_452 | V_453 ) ;
V_449 |= V_454 | V_455 ;
V_449 |= V_456 | V_457 ;
V_449 |= V_458 | V_459 ;
F_2 ( V_450 , V_449 ) ;
}
static void F_198 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_2 ;
if ( F_197 ( V_9 ) )
V_2 = V_186 | V_185 ;
else
V_2 = V_202 | V_201 ;
if ( F_88 ( V_9 ) )
return;
F_2 ( V_218 , F_7 ( V_218 ) ) ;
F_2 ( V_443 , ~ V_2 ) ;
}
static int F_199 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_460 = V_210 | V_13 | V_228 |
V_226 | V_227 |
V_223 ;
T_2 V_461 ;
V_1 -> V_3 = ~ V_460 ;
F_2 ( V_212 , F_7 ( V_212 ) ) ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_2 ( V_209 , V_460 | V_224 | V_225 ) ;
F_3 ( V_209 ) ;
V_1 -> V_129 = ~ 0 ;
F_2 ( V_167 , F_7 ( V_167 ) ) ;
F_2 ( V_131 , V_1 -> V_129 ) ;
if ( F_93 ( V_9 ) )
V_461 =
V_219 |
V_142 |
V_144 ;
else
V_461 =
V_219 |
V_220 |
V_221 ;
F_2 ( V_357 , V_461 ) ;
F_3 ( V_357 ) ;
F_198 ( V_9 ) ;
if ( F_200 ( V_9 ) ) {
F_2 ( V_212 , V_229 ) ;
F_2 ( V_209 , F_7 ( V_209 ) | V_229 ) ;
F_1 ( V_1 , V_229 ) ;
}
return 0 ;
}
static int F_201 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_460 =
V_210 | V_214 | V_217 |
V_462 |
V_463 |
V_216 |
V_213 ;
T_2 V_461 ;
V_1 -> V_3 = ~ V_460 ;
F_2 ( V_212 , F_7 ( V_212 ) ) ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_2 ( V_209 ,
V_460 |
V_464 |
V_465 |
V_215 ) ;
F_3 ( V_209 ) ;
V_1 -> V_129 = ~ V_130 ;
F_2 ( V_167 , F_7 ( V_167 ) ) ;
F_2 ( V_131 , V_1 -> V_129 ) ;
V_461 = V_219 | V_142 |
V_144 | V_130 ;
F_2 ( V_357 , V_461 ) ;
F_3 ( V_357 ) ;
F_198 ( V_9 ) ;
return 0 ;
}
static int F_202 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_466 ;
T_2 V_467 = V_468 ;
T_2 V_461 ;
T_8 V_469 ;
V_466 = V_174 ;
V_466 |= V_470 |
V_419 |
V_471 |
V_420 ;
V_1 -> V_3 = ( ~ V_466 ) |
V_419 |
V_420 ;
F_203 ( V_1 -> V_9 -> V_472 , 0x94 , 0xfee00000 ) ;
F_204 ( V_9 -> V_472 , 0x98 , & V_469 ) ;
V_469 &= 0xff ;
V_469 |= ( 1 << 14 ) ;
F_205 ( V_1 -> V_9 -> V_472 , 0x98 , V_469 ) ;
F_2 ( V_448 , 0 ) ;
F_3 ( V_448 ) ;
F_2 ( V_418 , V_1 -> V_3 ) ;
F_2 ( V_358 , V_466 ) ;
F_2 ( V_166 , 0xffffffff ) ;
F_2 ( F_6 ( 0 ) , 0xffff ) ;
F_2 ( F_6 ( 1 ) , 0xffff ) ;
F_3 ( V_358 ) ;
F_5 ( V_1 , 0 , V_467 ) ;
F_5 ( V_1 , 0 , V_473 ) ;
F_5 ( V_1 , 1 , V_467 ) ;
F_2 ( V_166 , 0xffffffff ) ;
F_2 ( V_166 , 0xffffffff ) ;
F_2 ( V_167 , F_7 ( V_167 ) ) ;
F_2 ( V_131 , V_1 -> V_129 ) ;
V_461 = V_219 | V_142 |
V_144 ;
F_2 ( V_357 , V_461 ) ;
F_3 ( V_357 ) ;
#if 0
I915_WRITE(DPINVGTT, DPINVGTT_STATUS_MASK);
I915_WRITE(DPINVGTT, DPINVGTT_EN_MASK);
#endif
F_2 ( V_474 , V_475 ) ;
return 0 ;
}
static void F_206 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( ! V_1 )
return;
F_207 ( & V_1 -> V_76 ) ;
F_78 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_442 , 0xffffffff ) ;
F_2 ( V_448 , 0 ) ;
F_2 ( V_176 , F_7 ( V_176 ) ) ;
F_78 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_166 , 0xffffffff ) ;
F_2 ( V_418 , 0xffffffff ) ;
F_2 ( V_358 , 0x0 ) ;
F_3 ( V_358 ) ;
}
static void F_208 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
if ( ! V_1 )
return;
F_207 ( & V_1 -> V_76 ) ;
F_2 ( V_442 , 0xffffffff ) ;
F_2 ( V_4 , 0xffffffff ) ;
F_2 ( V_209 , 0x0 ) ;
F_2 ( V_212 , F_7 ( V_212 ) ) ;
F_2 ( V_131 , 0xffffffff ) ;
F_2 ( V_357 , 0x0 ) ;
F_2 ( V_167 , F_7 ( V_167 ) ) ;
if ( F_88 ( V_9 ) )
return;
F_2 ( V_443 , 0xffffffff ) ;
F_2 ( V_211 , 0x0 ) ;
F_2 ( V_218 , F_7 ( V_218 ) ) ;
}
static void F_209 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_101 ( & V_1 -> V_165 , 0 ) ;
F_78 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_48 ( V_476 , 0xffff ) ;
F_48 ( V_359 , 0x0 ) ;
F_210 ( V_359 ) ;
}
static int F_211 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
F_48 ( V_390 ,
~ ( V_386 | V_387 ) ) ;
V_1 -> V_3 =
~ ( V_470 |
V_471 |
V_477 |
V_478 |
V_392 ) ;
F_48 ( V_476 , V_1 -> V_3 ) ;
F_48 ( V_359 ,
V_470 |
V_471 |
V_392 |
V_479 ) ;
F_210 ( V_359 ) ;
return 0 ;
}
static bool F_212 ( struct V_8 * V_9 ,
int V_5 , T_8 V_161 )
{
T_1 * V_1 = V_9 -> V_10 ;
T_8 V_480 = F_213 ( V_5 ) ;
if ( ! F_79 ( V_9 , V_5 ) )
return false ;
if ( ( V_161 & V_480 ) == 0 )
return false ;
F_80 ( V_9 , V_5 ) ;
if ( F_157 ( V_481 ) & V_480 )
return false ;
F_81 ( V_9 , V_5 ) ;
return true ;
}
static T_5 F_214 ( int V_159 , void * V_160 )
{
struct V_8 * V_9 = (struct V_8 * ) V_160 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_8 V_161 , V_482 ;
T_2 V_163 [ 2 ] ;
unsigned long V_11 ;
int V_165 ;
int V_5 ;
T_8 V_483 =
V_477 |
V_478 ;
F_77 ( & V_1 -> V_165 ) ;
V_161 = F_157 ( V_391 ) ;
if ( V_161 == 0 )
return V_162 ;
while ( V_161 & ~ V_483 ) {
F_11 ( & V_1 -> V_12 , V_11 ) ;
if ( V_161 & V_392 )
F_70 ( V_9 , false ) ;
F_78 (pipe) {
int V_6 = F_6 ( V_5 ) ;
V_163 [ V_5 ] = F_7 ( V_6 ) ;
if ( V_163 [ V_5 ] & 0x8000ffff ) {
if ( V_163 [ V_5 ] & V_171 )
F_19 ( L_16 ,
F_20 ( V_5 ) ) ;
F_2 ( V_6 , V_163 [ V_5 ] ) ;
V_165 = 1 ;
}
}
F_14 ( & V_1 -> V_12 , V_11 ) ;
F_48 ( V_391 , V_161 & ~ V_483 ) ;
V_482 = F_157 ( V_391 ) ;
F_215 ( V_9 ) ;
if ( V_161 & V_479 )
F_50 ( V_9 , & V_1 -> V_97 [ V_141 ] ) ;
if ( V_163 [ 0 ] & V_172 &&
F_212 ( V_9 , 0 , V_161 ) )
V_483 &= ~ F_213 ( 0 ) ;
if ( V_163 [ 1 ] & V_172 &&
F_212 ( V_9 , 1 , V_161 ) )
V_483 &= ~ F_213 ( 1 ) ;
V_161 = V_482 ;
}
return V_170 ;
}
static void F_216 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_78 (pipe) {
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( F_6 ( V_5 ) , F_7 ( F_6 ( V_5 ) ) ) ;
}
F_48 ( V_476 , 0xffff ) ;
F_48 ( V_359 , 0x0 ) ;
F_48 ( V_391 , F_157 ( V_391 ) ) ;
}
static void F_217 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_101 ( & V_1 -> V_165 , 0 ) ;
if ( F_218 ( V_9 ) ) {
F_2 ( V_448 , 0 ) ;
F_2 ( V_176 , F_7 ( V_176 ) ) ;
}
F_48 ( V_442 , 0xeffe ) ;
F_78 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_476 , 0xffffffff ) ;
F_2 ( V_359 , 0x0 ) ;
F_3 ( V_359 ) ;
}
static int F_219 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_466 ;
F_2 ( V_390 , ~ ( V_386 | V_387 ) ) ;
V_1 -> V_3 =
~ ( V_484 |
V_470 |
V_471 |
V_477 |
V_478 |
V_392 ) ;
V_466 =
V_484 |
V_470 |
V_471 |
V_392 |
V_479 ;
if ( F_218 ( V_9 ) ) {
F_2 ( V_448 , 0 ) ;
F_3 ( V_448 ) ;
V_466 |= V_174 ;
V_1 -> V_3 &= ~ V_174 ;
}
F_2 ( V_476 , V_1 -> V_3 ) ;
F_2 ( V_359 , V_466 ) ;
F_3 ( V_359 ) ;
F_220 ( V_9 ) ;
return 0 ;
}
static bool F_221 ( struct V_8 * V_9 ,
int V_406 , int V_5 , T_2 V_161 )
{
T_1 * V_1 = V_9 -> V_10 ;
T_2 V_480 = F_213 ( V_406 ) ;
if ( ! F_79 ( V_9 , V_5 ) )
return false ;
if ( ( V_161 & V_480 ) == 0 )
return false ;
F_80 ( V_9 , V_406 ) ;
if ( F_7 ( V_481 ) & V_480 )
return false ;
F_81 ( V_9 , V_5 ) ;
return true ;
}
static T_5 F_222 ( int V_159 , void * V_160 )
{
struct V_8 * V_9 = (struct V_8 * ) V_160 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_161 , V_482 , V_163 [ V_164 ] ;
unsigned long V_11 ;
T_2 V_483 =
V_477 |
V_478 ;
int V_5 , V_37 = V_162 ;
F_77 ( & V_1 -> V_165 ) ;
V_161 = F_7 ( V_391 ) ;
do {
bool V_165 = ( V_161 & ~ V_483 ) != 0 ;
bool V_485 = false ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
if ( V_161 & V_392 )
F_70 ( V_9 , false ) ;
F_78 (pipe) {
int V_6 = F_6 ( V_5 ) ;
V_163 [ V_5 ] = F_7 ( V_6 ) ;
if ( V_163 [ V_5 ] & 0x8000ffff ) {
if ( V_163 [ V_5 ] & V_171 )
F_19 ( L_16 ,
F_20 ( V_5 ) ) ;
F_2 ( V_6 , V_163 [ V_5 ] ) ;
V_165 = true ;
}
}
F_14 ( & V_1 -> V_12 , V_11 ) ;
if ( ! V_165 )
break;
if ( ( F_218 ( V_9 ) ) &&
( V_161 & V_174 ) ) {
T_2 V_175 = F_7 ( V_176 ) ;
T_2 V_149 = V_175 & V_177 ;
F_19 ( L_17 ,
V_175 ) ;
if ( V_149 ) {
if ( F_72 ( V_9 , V_149 , V_178 ) )
F_82 ( V_9 ) ;
F_68 ( V_1 -> V_137 ,
& V_1 -> V_55 ) ;
}
F_2 ( V_176 , V_175 ) ;
F_3 ( V_176 ) ;
}
F_2 ( V_391 , V_161 & ~ V_483 ) ;
V_482 = F_7 ( V_391 ) ;
if ( V_161 & V_479 )
F_50 ( V_9 , & V_1 -> V_97 [ V_141 ] ) ;
F_78 (pipe) {
int V_406 = V_5 ;
if ( F_223 ( V_9 ) )
V_406 = ! V_406 ;
if ( V_163 [ V_5 ] & V_172 &&
F_221 ( V_9 , V_406 , V_5 , V_161 ) )
V_483 &= ~ F_213 ( V_406 ) ;
if ( V_163 [ V_5 ] & V_486 )
V_485 = true ;
}
if ( V_485 || ( V_161 & V_484 ) )
F_224 ( V_9 ) ;
V_37 = V_170 ;
V_161 = V_482 ;
} while ( V_161 & ~ V_483 );
F_215 ( V_9 ) ;
return V_37 ;
}
static void F_225 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_207 ( & V_1 -> V_76 ) ;
if ( F_218 ( V_9 ) ) {
F_2 ( V_448 , 0 ) ;
F_2 ( V_176 , F_7 ( V_176 ) ) ;
}
F_48 ( V_442 , 0xffff ) ;
F_78 (pipe) {
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( F_6 ( V_5 ) , F_7 ( F_6 ( V_5 ) ) ) ;
}
F_2 ( V_476 , 0xffffffff ) ;
F_2 ( V_359 , 0x0 ) ;
F_2 ( V_391 , F_7 ( V_391 ) ) ;
}
static void F_226 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_101 ( & V_1 -> V_165 , 0 ) ;
F_2 ( V_448 , 0 ) ;
F_2 ( V_176 , F_7 ( V_176 ) ) ;
F_2 ( V_442 , 0xeffe ) ;
F_78 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_476 , 0xffffffff ) ;
F_2 ( V_359 , 0x0 ) ;
F_3 ( V_359 ) ;
}
static int F_227 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_466 ;
T_2 V_487 ;
V_1 -> V_3 = ~ ( V_484 |
V_174 |
V_470 |
V_471 |
V_477 |
V_478 |
V_392 ) ;
V_466 = ~ V_1 -> V_3 ;
V_466 &= ~ ( V_477 |
V_478 ) ;
V_466 |= V_479 ;
if ( F_165 ( V_9 ) )
V_466 |= V_488 ;
F_5 ( V_1 , 0 , V_473 ) ;
if ( F_165 ( V_9 ) ) {
V_487 = ~ ( V_384 |
V_378 |
V_379 |
V_387 ) ;
} else {
V_487 = ~ ( V_386 |
V_387 ) ;
}
F_2 ( V_390 , V_487 ) ;
F_2 ( V_476 , V_1 -> V_3 ) ;
F_2 ( V_359 , V_466 ) ;
F_3 ( V_359 ) ;
F_2 ( V_448 , 0 ) ;
F_3 ( V_448 ) ;
F_220 ( V_9 ) ;
return 0 ;
}
static void F_82 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
struct V_56 * V_57 = & V_9 -> V_57 ;
struct V_59 * V_59 ;
T_2 V_489 ;
if ( F_218 ( V_9 ) ) {
V_489 = F_7 ( V_448 ) ;
V_489 &= ~ V_490 ;
F_38 (intel_encoder, &mode_config->encoder_list, base.head)
if ( V_1 -> V_68 [ V_59 -> V_66 ] . V_69 == V_153 )
V_489 |= V_491 [ V_59 -> V_66 ] ;
if ( F_165 ( V_9 ) )
V_489 |= V_492 ;
V_489 &= ~ V_493 ;
V_489 |= V_494 ;
F_2 ( V_448 , V_489 ) ;
}
}
static T_5 F_228 ( int V_159 , void * V_160 )
{
struct V_8 * V_9 = (struct V_8 * ) V_160 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_161 , V_482 ;
T_2 V_163 [ V_164 ] ;
unsigned long V_11 ;
int V_165 ;
int V_37 = V_162 , V_5 ;
T_2 V_483 =
V_477 |
V_478 ;
F_77 ( & V_1 -> V_165 ) ;
V_161 = F_7 ( V_391 ) ;
for (; ; ) {
bool V_485 = false ;
V_165 = ( V_161 & ~ V_483 ) != 0 ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
if ( V_161 & V_392 )
F_70 ( V_9 , false ) ;
F_78 (pipe) {
int V_6 = F_6 ( V_5 ) ;
V_163 [ V_5 ] = F_7 ( V_6 ) ;
if ( V_163 [ V_5 ] & 0x8000ffff ) {
if ( V_163 [ V_5 ] & V_171 )
F_19 ( L_16 ,
F_20 ( V_5 ) ) ;
F_2 ( V_6 , V_163 [ V_5 ] ) ;
V_165 = 1 ;
}
}
F_14 ( & V_1 -> V_12 , V_11 ) ;
if ( ! V_165 )
break;
V_37 = V_170 ;
if ( V_161 & V_174 ) {
T_2 V_175 = F_7 ( V_176 ) ;
T_2 V_149 = V_175 & ( F_165 ( V_9 ) ?
V_495 :
V_496 ) ;
F_19 ( L_17 ,
V_175 ) ;
if ( V_149 ) {
if ( F_72 ( V_9 , V_149 ,
F_165 ( V_9 ) ? V_497 : V_498 ) )
F_82 ( V_9 ) ;
F_68 ( V_1 -> V_137 ,
& V_1 -> V_55 ) ;
}
F_2 ( V_176 , V_175 ) ;
F_7 ( V_176 ) ;
}
F_2 ( V_391 , V_161 & ~ V_483 ) ;
V_482 = F_7 ( V_391 ) ;
if ( V_161 & V_479 )
F_50 ( V_9 , & V_1 -> V_97 [ V_141 ] ) ;
if ( V_161 & V_488 )
F_50 ( V_9 , & V_1 -> V_97 [ V_143 ] ) ;
F_78 (pipe) {
if ( V_163 [ V_5 ] & V_499 &&
F_221 ( V_9 , V_5 , V_5 , V_161 ) )
V_483 &= ~ F_213 ( V_5 ) ;
if ( V_163 [ V_5 ] & V_486 )
V_485 = true ;
}
if ( V_485 || ( V_161 & V_484 ) )
F_224 ( V_9 ) ;
if ( V_163 [ 0 ] & V_179 )
F_74 ( V_9 ) ;
V_161 = V_482 ;
}
F_215 ( V_9 ) ;
return V_37 ;
}
static void F_229 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( ! V_1 )
return;
F_207 ( & V_1 -> V_76 ) ;
F_2 ( V_448 , 0 ) ;
F_2 ( V_176 , F_7 ( V_176 ) ) ;
F_2 ( V_442 , 0xffffffff ) ;
F_78 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_476 , 0xffffffff ) ;
F_2 ( V_359 , 0x0 ) ;
F_78 (pipe)
F_2 ( F_6 ( V_5 ) ,
F_7 ( F_6 ( V_5 ) ) & 0x8000ffff ) ;
F_2 ( V_391 , F_7 ( V_391 ) ) ;
}
static void F_230 ( unsigned long V_436 )
{
T_1 * V_1 = ( T_1 * ) V_436 ;
struct V_8 * V_9 = V_1 -> V_9 ;
struct V_56 * V_57 = & V_9 -> V_57 ;
unsigned long V_11 ;
int V_151 ;
F_11 ( & V_1 -> V_12 , V_11 ) ;
for ( V_151 = ( V_67 + 1 ) ; V_151 < V_152 ; V_151 ++ ) {
struct V_60 * V_61 ;
if ( V_1 -> V_68 [ V_151 ] . V_69 != V_73 )
continue;
V_1 -> V_68 [ V_151 ] . V_69 = V_153 ;
F_38 (connector, &mode_config->connector_list, head) {
struct V_58 * V_58 = F_39 ( V_61 ) ;
if ( V_58 -> V_65 -> V_66 == V_151 ) {
if ( V_61 -> V_71 != V_58 -> V_71 )
F_19 ( L_55 ,
F_41 ( V_61 ) ) ;
V_61 -> V_71 = V_58 -> V_71 ;
if ( ! V_61 -> V_71 )
V_61 -> V_71 = V_72 ;
}
}
}
if ( V_1 -> V_377 . V_500 )
V_1 -> V_377 . V_500 ( V_9 ) ;
F_14 ( & V_1 -> V_12 , V_11 ) ;
}
void F_231 ( struct V_8 * V_9 )
{
struct V_98 * V_1 = V_9 -> V_10 ;
F_232 ( & V_1 -> V_55 , F_35 ) ;
F_232 ( & V_1 -> V_103 . V_54 , F_96 ) ;
F_232 ( & V_1 -> V_107 . V_54 , F_54 ) ;
F_232 ( & V_1 -> V_115 . V_116 , F_58 ) ;
F_233 ( & V_1 -> V_103 . V_105 ,
F_193 ,
( unsigned long ) V_9 ) ;
F_233 ( & V_1 -> V_76 , F_230 ,
( unsigned long ) V_1 ) ;
F_234 ( & V_1 -> V_501 , V_502 , V_503 ) ;
V_9 -> V_504 -> V_505 = F_18 ;
V_9 -> V_506 = 0xffffff ;
if ( F_165 ( V_9 ) || F_13 ( V_9 ) -> V_15 >= 5 ) {
V_9 -> V_506 = 0xffffffff ;
V_9 -> V_504 -> V_505 = F_23 ;
}
if ( F_235 ( V_9 , V_507 ) )
V_9 -> V_504 -> V_508 = F_30 ;
else
V_9 -> V_504 -> V_508 = NULL ;
V_9 -> V_504 -> V_509 = F_25 ;
if ( F_10 ( V_9 ) ) {
V_9 -> V_504 -> V_510 = F_76 ;
V_9 -> V_504 -> V_511 = F_195 ;
V_9 -> V_504 -> V_512 = F_202 ;
V_9 -> V_504 -> V_513 = F_206 ;
V_9 -> V_504 -> V_514 = F_177 ;
V_9 -> V_504 -> V_515 = F_182 ;
V_1 -> V_377 . V_500 = F_82 ;
} else if ( F_236 ( V_9 ) || F_237 ( V_9 ) ) {
V_9 -> V_504 -> V_510 = F_87 ;
V_9 -> V_504 -> V_511 = F_194 ;
V_9 -> V_504 -> V_512 = F_201 ;
V_9 -> V_504 -> V_513 = F_208 ;
V_9 -> V_504 -> V_514 = F_176 ;
V_9 -> V_504 -> V_515 = F_181 ;
V_1 -> V_377 . V_500 = F_84 ;
} else if ( F_12 ( V_9 ) ) {
V_9 -> V_504 -> V_510 = F_92 ;
V_9 -> V_504 -> V_511 = F_194 ;
V_9 -> V_504 -> V_512 = F_199 ;
V_9 -> V_504 -> V_513 = F_208 ;
V_9 -> V_504 -> V_514 = F_175 ;
V_9 -> V_504 -> V_515 = F_180 ;
V_1 -> V_377 . V_500 = F_84 ;
} else {
if ( F_13 ( V_9 ) -> V_15 == 2 ) {
V_9 -> V_504 -> V_511 = F_209 ;
V_9 -> V_504 -> V_512 = F_211 ;
V_9 -> V_504 -> V_510 = F_214 ;
V_9 -> V_504 -> V_513 = F_216 ;
} else if ( F_13 ( V_9 ) -> V_15 == 3 ) {
V_9 -> V_504 -> V_511 = F_217 ;
V_9 -> V_504 -> V_512 = F_219 ;
V_9 -> V_504 -> V_513 = F_225 ;
V_9 -> V_504 -> V_510 = F_222 ;
V_1 -> V_377 . V_500 = F_82 ;
} else {
V_9 -> V_504 -> V_511 = F_226 ;
V_9 -> V_504 -> V_512 = F_227 ;
V_9 -> V_504 -> V_513 = F_229 ;
V_9 -> V_504 -> V_510 = F_228 ;
V_1 -> V_377 . V_500 = F_82 ;
}
V_9 -> V_504 -> V_514 = F_173 ;
V_9 -> V_504 -> V_515 = F_178 ;
}
}
void F_238 ( struct V_8 * V_9 )
{
struct V_98 * V_1 = V_9 -> V_10 ;
struct V_56 * V_57 = & V_9 -> V_57 ;
struct V_60 * V_61 ;
int V_151 ;
for ( V_151 = 1 ; V_151 < V_152 ; V_151 ++ ) {
V_1 -> V_68 [ V_151 ] . V_156 = 0 ;
V_1 -> V_68 [ V_151 ] . V_69 = V_153 ;
}
F_38 (connector, &mode_config->connector_list, head) {
struct V_58 * V_58 = F_39 ( V_61 ) ;
V_61 -> V_71 = V_58 -> V_71 ;
if ( ! V_61 -> V_71 && F_218 ( V_9 ) && V_58 -> V_65 -> V_66 > V_67 )
V_61 -> V_71 = V_72 ;
}
if ( V_1 -> V_377 . V_500 )
V_1 -> V_377 . V_500 ( V_9 ) ;
}
