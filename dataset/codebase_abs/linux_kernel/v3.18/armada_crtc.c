void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
while ( V_4 -> V_5 != ~ 0 ) {
void T_1 * V_6 = V_2 -> V_7 + V_4 -> V_5 ;
T_2 V_8 ;
V_8 = V_4 -> V_9 ;
if ( V_8 != 0 )
V_8 &= F_2 ( V_6 ) ;
F_3 ( V_8 | V_4 -> V_8 , V_6 ) ;
++ V_4 ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
T_2 V_10 ;
V_10 = V_2 -> V_11 ;
if ( ! F_5 ( V_2 -> V_12 ) )
V_10 |= V_13 ;
if ( F_5 ( V_2 -> V_12 ) &&
( V_10 & V_14 ) == V_15 ) {
V_10 &= ~ V_14 ;
V_10 |= V_16 ;
}
if ( V_2 -> V_17 . V_18 . V_19 & V_20 )
V_10 |= V_21 ;
if ( V_2 -> V_17 . V_18 . V_19 & V_22 )
V_10 |= V_23 ;
if ( V_2 -> V_17 . V_18 . V_19 & V_24 )
V_10 |= V_25 ;
if ( V_2 -> V_10 != V_10 ) {
V_2 -> V_10 = V_10 ;
F_3 ( V_10 , V_2 -> V_7 + V_26 ) ;
}
}
static unsigned F_6 ( struct V_27 * V_28 ,
int V_29 , int V_30 , struct V_3 * V_4 , bool V_31 )
{
struct V_32 * V_33 = F_7 ( V_28 ) ;
unsigned V_34 = V_28 -> V_35 [ 0 ] ;
unsigned V_5 = V_30 * V_34 + V_29 * V_28 -> V_36 / 8 ;
T_2 V_37 , V_38 ;
unsigned V_39 = 0 ;
F_8 ( L_1 ,
V_34 , V_29 , V_30 , V_28 -> V_36 ) ;
V_37 = V_38 = V_33 -> V_40 + V_5 ;
if ( V_31 ) {
V_38 += V_34 ;
V_34 *= 2 ;
}
F_9 ( V_4 , V_39 , V_37 , V_41 ) ;
F_9 ( V_4 , V_39 , V_38 , V_42 ) ;
F_10 ( V_4 , V_39 , V_34 , 0xffff , V_43 ) ;
return V_39 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 = V_2 -> V_17 . V_47 ;
unsigned long V_19 ;
int V_48 ;
V_48 = F_12 ( V_47 , V_2 -> V_49 ) ;
if ( V_48 ) {
F_13 ( L_2 ) ;
return V_48 ;
}
F_14 ( & V_47 -> V_50 , V_19 ) ;
if ( ! V_2 -> V_51 )
V_2 -> V_51 = V_45 ;
else
V_48 = - V_52 ;
F_15 ( & V_47 -> V_50 , V_19 ) ;
if ( V_48 )
F_16 ( V_47 , V_2 -> V_49 ) ;
return V_48 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_17 . V_47 ;
struct V_44 * V_45 = V_2 -> V_51 ;
V_2 -> V_51 = NULL ;
F_1 ( V_2 , V_45 -> V_4 ) ;
if ( V_45 -> V_53 )
F_18 ( V_47 , V_2 -> V_49 , V_45 -> V_53 ) ;
F_16 ( V_47 , V_2 -> V_49 ) ;
F_19 ( V_2 -> V_17 . V_47 , V_45 -> V_54 ) ;
F_20 ( V_45 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_27 * V_28 , bool V_55 )
{
struct V_44 * V_45 ;
if ( ! V_28 )
return;
if ( V_55 ) {
F_22 ( V_28 ) ;
return;
}
V_45 = F_23 ( sizeof( * V_45 ) , V_56 ) ;
if ( V_45 ) {
int V_39 = 0 ;
V_45 -> V_53 = NULL ;
V_45 -> V_54 = V_28 ;
F_24 ( V_45 -> V_4 , V_39 ) ;
if ( F_11 ( V_2 , V_45 ) == 0 )
return;
F_20 ( V_45 ) ;
}
F_22 ( V_28 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_17 . V_47 ;
F_26 ( & V_2 -> V_17 ) ;
F_27 ( & V_47 -> V_50 ) ;
if ( V_2 -> V_51 )
F_17 ( V_2 ) ;
F_28 ( & V_47 -> V_50 ) ;
}
void F_29 ( struct V_57 * V_17 , T_3 V_58 , T_3 V_59 , T_3 V_60 ,
int V_61 )
{
}
void F_30 ( struct V_57 * V_17 , T_3 * V_58 , T_3 * V_59 , T_3 * V_60 ,
int V_61 )
{
}
static void F_31 ( struct V_57 * V_17 , int V_12 )
{
struct V_1 * V_2 = F_32 ( V_17 ) ;
if ( V_2 -> V_12 != V_12 ) {
V_2 -> V_12 = V_12 ;
F_4 ( V_2 ) ;
if ( F_5 ( V_12 ) )
F_25 ( V_2 ) ;
else
F_33 ( & V_2 -> V_17 ) ;
}
}
static void F_34 ( struct V_57 * V_17 )
{
struct V_1 * V_2 = F_32 ( V_17 ) ;
struct V_62 * V_63 ;
V_63 = V_2 -> V_63 ;
if ( V_63 ) {
struct V_27 * V_28 = V_63 -> V_28 ;
V_63 -> V_64 -> V_65 ( V_63 ) ;
V_63 -> V_28 = NULL ;
V_63 -> V_17 = NULL ;
F_22 ( V_28 ) ;
}
}
static void F_35 ( struct V_57 * V_17 )
{
struct V_1 * V_2 = F_32 ( V_17 ) ;
if ( V_2 -> V_12 != V_66 ) {
V_2 -> V_12 = V_66 ;
F_4 ( V_2 ) ;
}
}
static bool F_36 ( struct V_57 * V_17 ,
const struct V_67 * V_18 , struct V_67 * V_68 )
{
struct V_1 * V_2 = F_32 ( V_17 ) ;
int V_48 ;
if ( ! V_2 -> V_69 -> V_70 &&
V_68 -> V_19 & V_71 )
return false ;
V_48 = V_2 -> V_69 -> V_72 ( V_2 , V_68 , NULL ) ;
if ( V_48 )
return false ;
return true ;
}
static void F_37 ( struct V_1 * V_2 , T_4 V_73 )
{
struct V_74 * V_75 , * V_76 ;
void T_1 * V_7 = V_2 -> V_7 ;
if ( V_73 & V_77 )
F_13 ( L_3 , V_2 -> V_49 ) ;
if ( V_73 & V_78 )
F_13 ( L_4 , V_2 -> V_49 ) ;
if ( V_73 & V_79 )
F_38 ( V_2 -> V_17 . V_47 , V_2 -> V_49 ) ;
F_39 ( & V_2 -> V_80 ) ;
F_40 (e, n, &dcrtc->vbl_list, node) {
F_41 ( & V_75 -> V_81 ) ;
F_16 ( V_2 -> V_17 . V_47 , V_2 -> V_49 ) ;
V_75 -> V_82 ( V_2 , V_75 -> V_83 ) ;
}
if ( V_73 & V_84 && V_2 -> V_31 ) {
int V_39 = V_73 & V_85 ? 0 : 1 ;
T_2 V_8 ;
F_3 ( V_2 -> V_86 [ V_39 ] . V_87 , V_7 + V_88 ) ;
F_3 ( V_2 -> V_86 [ V_39 ] . V_89 ,
V_7 + V_90 ) ;
V_8 = F_2 ( V_7 + V_91 ) ;
V_8 &= ~ ( V_92 | V_93 | V_94 ) ;
V_8 |= V_2 -> V_86 [ V_39 ] . V_95 ;
F_3 ( V_8 , V_7 + V_91 ) ;
}
if ( V_73 & V_96 && V_2 -> V_97 ) {
F_3 ( V_2 -> V_98 ,
V_7 + V_99 ) ;
F_3 ( V_2 -> V_100 ,
V_7 + V_101 ) ;
F_42 ( V_102 ,
V_102 | V_103 | V_104 ,
V_7 + V_105 ) ;
V_2 -> V_97 = false ;
F_43 ( V_2 , V_106 ) ;
}
F_44 ( & V_2 -> V_80 ) ;
if ( V_73 & V_84 ) {
struct V_46 * V_47 = V_2 -> V_17 . V_47 ;
F_39 ( & V_47 -> V_50 ) ;
if ( V_2 -> V_51 )
F_17 ( V_2 ) ;
F_44 ( & V_47 -> V_50 ) ;
F_45 ( & V_2 -> V_107 ) ;
}
}
static T_5 F_46 ( int V_108 , void * V_109 )
{
struct V_1 * V_2 = V_109 ;
T_4 V_86 , V_73 = F_2 ( V_2 -> V_7 + V_110 ) ;
F_3 ( 0 , V_2 -> V_7 + V_110 ) ;
V_86 = V_73 & V_2 -> V_111 ;
if ( V_86 & ( V_79 | V_84 | V_96 ) ) {
F_37 ( V_2 , V_73 ) ;
return V_112 ;
}
return V_113 ;
}
void F_43 ( struct V_1 * V_2 , T_4 V_9 )
{
if ( V_2 -> V_111 & V_9 ) {
V_2 -> V_111 &= ~ V_9 ;
F_47 ( V_2 -> V_111 , V_2 -> V_7 + V_114 ) ;
}
}
void F_48 ( struct V_1 * V_2 , T_4 V_9 )
{
if ( ( V_2 -> V_111 & V_9 ) != V_9 ) {
V_2 -> V_111 |= V_9 ;
F_47 ( V_2 -> V_111 , V_2 -> V_7 + V_114 ) ;
if ( F_2 ( V_2 -> V_7 + V_110 ) & V_9 )
F_47 ( 0 , V_2 -> V_7 + V_110 ) ;
}
}
static T_2 F_49 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = & V_2 -> V_17 . V_18 ;
T_2 V_8 = 0 ;
if ( V_2 -> V_115 == V_116 )
V_8 |= V_117 ;
if ( V_2 -> V_118 == V_119 )
V_8 |= V_120 ;
if ( ( V_68 -> V_121 == 1280 && V_68 -> V_122 == 720 &&
! ( V_68 -> V_19 & V_71 ) ) ||
( V_68 -> V_121 == 1920 && V_68 -> V_122 == 1080 ) ) {
if ( V_2 -> V_115 == V_123 )
V_8 |= V_117 ;
}
if ( V_2 -> V_118 == V_123 )
V_8 |= V_120 ;
return V_8 ;
}
static int F_50 ( struct V_57 * V_17 ,
struct V_67 * V_18 , struct V_67 * V_68 ,
int V_29 , int V_30 , struct V_27 * V_54 )
{
struct V_1 * V_2 = F_32 ( V_17 ) ;
struct V_3 V_4 [ 17 ] ;
T_2 V_124 , V_125 , V_126 , V_127 , V_8 , V_128 ;
unsigned long V_19 ;
unsigned V_39 ;
bool V_31 ;
F_51 ( V_17 -> V_129 -> V_28 ) ;
V_31 = ! ! ( V_68 -> V_19 & V_71 ) ;
V_39 = F_6 ( V_2 -> V_17 . V_129 -> V_28 ,
V_29 , V_30 , V_4 , V_31 ) ;
V_125 = V_68 -> V_130 - V_68 -> V_131 ;
V_124 = V_68 -> V_132 - V_68 -> V_133 ;
V_127 = V_68 -> V_134 - V_68 -> V_135 ;
V_126 = V_68 -> V_136 - V_68 -> V_137 ;
F_8 ( L_5 ,
V_68 -> V_131 ,
V_68 -> V_130 ,
V_68 -> V_133 ,
V_68 -> V_132 , V_124 , V_125 ) ;
F_8 ( L_6 ,
V_68 -> V_135 ,
V_68 -> V_134 ,
V_68 -> V_137 ,
V_68 -> V_136 , V_126 , V_127 ) ;
F_52 ( V_2 -> V_107 , ! V_2 -> V_51 ) ;
F_26 ( V_17 ) ;
V_17 -> V_18 = * V_68 ;
V_8 = V_2 -> V_10 & ~ V_13 ;
if ( V_8 != V_2 -> V_10 ) {
V_2 -> V_10 = V_8 ;
F_3 ( V_8 , V_2 -> V_7 + V_26 ) ;
}
V_2 -> V_69 -> V_72 ( V_2 , V_68 , & V_128 ) ;
F_10 ( V_4 , V_39 , 0 , V_138 , V_139 ) ;
F_9 ( V_4 , V_39 , V_128 , V_140 ) ;
if ( V_31 ^ V_2 -> V_31 ) {
if ( V_68 -> V_19 & V_71 )
F_12 ( V_2 -> V_17 . V_47 , V_2 -> V_49 ) ;
else
F_16 ( V_2 -> V_17 . V_47 , V_2 -> V_49 ) ;
V_2 -> V_31 = V_31 ;
}
F_14 ( & V_2 -> V_80 , V_19 ) ;
V_2 -> V_86 [ 1 ] . V_89 = V_68 -> V_136 << 16 |
V_68 -> V_132 ;
V_2 -> V_86 [ 1 ] . V_87 = V_126 << 16 | V_127 ;
V_8 = V_68 -> V_130 ;
V_2 -> V_86 [ 1 ] . V_95 = V_8 << 20 | V_8 | V_94 |
V_2 -> V_69 -> V_95 ;
if ( V_31 ) {
V_2 -> V_86 [ 0 ] . V_89 = V_2 -> V_86 [ 1 ] . V_89 +
( 1 << 16 ) ;
V_2 -> V_86 [ 0 ] . V_87 = V_2 -> V_86 [ 1 ] . V_87 + 1 ;
V_8 = V_68 -> V_130 - V_68 -> V_132 / 2 ;
V_2 -> V_86 [ 0 ] . V_95 = V_8 << 20 | V_8 | V_94 |
V_2 -> V_69 -> V_95 ;
} else {
V_2 -> V_86 [ 0 ] = V_2 -> V_86 [ 1 ] ;
}
V_8 = V_68 -> V_135 << 16 | V_68 -> V_131 ;
F_9 ( V_4 , V_39 , V_8 , V_141 ) ;
F_9 ( V_4 , V_39 , V_8 , V_142 ) ;
F_9 ( V_4 , V_39 , V_8 , V_143 ) ;
F_9 ( V_4 , V_39 , ( V_124 << 16 ) | V_125 , V_144 ) ;
F_9 ( V_4 , V_39 , V_2 -> V_86 [ 0 ] . V_87 , V_88 ) ;
F_9 ( V_4 , V_39 , V_2 -> V_86 [ 0 ] . V_89 ,
V_90 ) ;
if ( V_2 -> V_69 -> V_70 ) {
F_10 ( V_4 , V_39 , V_2 -> V_86 [ 0 ] . V_95 ,
V_92 | V_93 |
V_94 , V_91 ) ;
}
V_8 = V_145 | V_146 ;
V_8 |= F_53 ( F_54 ( V_2 -> V_17 . V_129 -> V_28 ) -> V_147 ) ;
V_8 |= F_55 ( F_54 ( V_2 -> V_17 . V_129 -> V_28 ) -> V_148 ) ;
if ( F_54 ( V_2 -> V_17 . V_129 -> V_28 ) -> V_147 > V_149 )
V_8 |= V_150 ;
if ( V_31 )
V_8 |= V_151 ;
F_10 ( V_4 , V_39 , V_8 , V_152 |
F_55 ( V_153 | V_154 |
V_155 | V_156 ) |
V_150 | V_151 ,
V_105 ) ;
V_8 = V_68 -> V_19 & V_24 ? V_157 : 0 ;
F_10 ( V_4 , V_39 , V_8 , V_157 , V_158 ) ;
V_8 = V_2 -> V_159 | F_49 ( V_2 ) ;
F_9 ( V_4 , V_39 , V_8 , V_160 ) ;
F_24 ( V_4 , V_39 ) ;
F_1 ( V_2 , V_4 ) ;
F_15 ( & V_2 -> V_80 , V_19 ) ;
F_4 ( V_2 ) ;
F_33 ( V_17 ) ;
F_21 ( V_2 , V_54 , F_5 ( V_2 -> V_12 ) ) ;
return 0 ;
}
static int F_56 ( struct V_57 * V_17 , int V_29 , int V_30 ,
struct V_27 * V_54 )
{
struct V_1 * V_2 = F_32 ( V_17 ) ;
struct V_3 V_4 [ 4 ] ;
unsigned V_39 ;
V_39 = F_6 ( V_17 -> V_129 -> V_28 , V_17 -> V_29 , V_17 -> V_30 , V_4 ,
V_2 -> V_31 ) ;
F_24 ( V_4 , V_39 ) ;
F_52 ( V_2 -> V_107 , ! V_2 -> V_51 ) ;
F_51 ( V_17 -> V_129 -> V_28 ) ;
F_1 ( V_2 , V_4 ) ;
F_21 ( V_2 , V_54 , F_5 ( V_2 -> V_12 ) ) ;
return 0 ;
}
static void F_57 ( struct V_57 * V_17 )
{
}
static void F_58 ( struct V_57 * V_17 )
{
struct V_1 * V_2 = F_32 ( V_17 ) ;
F_31 ( V_17 , V_161 ) ;
F_21 ( V_2 , V_17 -> V_129 -> V_28 , true ) ;
F_3 ( V_162 | V_163 | V_164 |
V_165 | V_166 | V_167 |
V_138 , V_2 -> V_7 + V_139 ) ;
}
static void F_59 ( void T_1 * V_7 , T_2 * V_168 ,
unsigned V_169 , unsigned V_170 , unsigned V_171 )
{
T_2 V_172 ;
unsigned V_30 ;
V_172 = V_173 ;
for ( V_30 = 0 ; V_30 < V_171 ; V_30 ++ ) {
T_2 * V_174 = & V_168 [ V_30 * V_169 ] ;
unsigned V_29 ;
for ( V_29 = 0 ; V_29 < V_170 ; V_29 ++ , V_174 ++ ) {
T_2 V_8 = * V_174 ;
V_8 = ( V_8 & 0xff00ff00 ) |
( V_8 & 0x000000ff ) << 16 |
( V_8 & 0x00ff0000 ) >> 16 ;
F_3 ( V_8 ,
V_7 + V_175 ) ;
F_3 ( V_172 | V_176 ,
V_7 + V_177 ) ;
F_2 ( V_7 + V_99 ) ;
V_172 += 1 ;
if ( ( V_172 & 0x00ff ) == 0 )
V_172 += 0xf00 ;
if ( ( V_172 & 0x30ff ) == 0 )
V_172 = V_178 ;
}
}
}
static void F_60 ( void T_1 * V_7 )
{
unsigned V_172 ;
for ( V_172 = 0 ; V_172 < 256 ; V_172 ++ ) {
F_3 ( 0x55555555 , V_7 + V_175 ) ;
F_3 ( V_172 | V_176 | V_179 ,
V_7 + V_177 ) ;
}
}
static int F_61 ( struct V_1 * V_2 , bool V_180 )
{
T_2 V_181 , V_182 , V_183 = V_2 -> V_184 , V_185 ;
T_2 V_186 , V_187 , V_188 = V_2 -> V_189 ;
T_2 V_190 ;
if ( V_2 -> V_191 < 0 ) {
V_181 = - V_2 -> V_191 ;
V_182 = 0 ;
V_183 -= F_62 ( V_181 , V_183 ) ;
} else if ( V_2 -> V_191 + V_183 > V_2 -> V_17 . V_18 . V_121 ) {
V_181 = 0 ;
V_182 = V_2 -> V_191 ;
V_183 = F_63 ( int , V_2 -> V_17 . V_18 . V_121 - V_2 -> V_191 , 0 ) ;
} else {
V_181 = 0 ;
V_182 = V_2 -> V_191 ;
}
if ( V_2 -> V_192 < 0 ) {
V_186 = - V_2 -> V_192 ;
V_187 = 0 ;
V_188 -= F_62 ( V_186 , V_188 ) ;
} else if ( V_2 -> V_192 + V_188 > V_2 -> V_17 . V_18 . V_122 ) {
V_186 = 0 ;
V_187 = V_2 -> V_192 ;
V_188 = F_63 ( int , V_2 -> V_17 . V_18 . V_122 - V_2 -> V_192 , 0 ) ;
} else {
V_186 = 0 ;
V_187 = V_2 -> V_192 ;
}
V_185 = V_2 -> V_184 ;
if ( V_2 -> V_31 ) {
V_185 *= 2 ;
V_187 /= 2 ;
V_188 /= 2 ;
}
if ( ! V_2 -> V_193 || ! V_188 || ! V_183 ) {
F_27 ( & V_2 -> V_80 ) ;
F_43 ( V_2 , V_106 ) ;
V_2 -> V_97 = false ;
F_42 ( 0 , V_102 , V_2 -> V_7 + V_105 ) ;
F_28 ( & V_2 -> V_80 ) ;
return 0 ;
}
V_190 = F_2 ( V_2 -> V_7 + V_139 ) ;
F_42 ( V_194 , V_194 | V_162 ,
V_2 -> V_7 + V_139 ) ;
if ( ! ( V_190 & V_194 ) ) {
F_60 ( V_2 -> V_7 ) ;
V_180 = true ;
}
if ( V_2 -> V_100 != ( V_188 << 16 | V_183 ) ) {
F_27 ( & V_2 -> V_80 ) ;
F_43 ( V_2 , V_106 ) ;
V_2 -> V_97 = false ;
F_42 ( 0 , V_102 , V_2 -> V_7 + V_105 ) ;
F_28 ( & V_2 -> V_80 ) ;
V_180 = true ;
}
if ( V_180 ) {
struct V_32 * V_33 = V_2 -> V_193 ;
T_2 * V_168 ;
V_168 = V_33 -> V_172 ;
V_168 += V_186 * V_185 + V_181 ;
F_59 ( V_2 -> V_7 , V_168 , V_185 , V_183 , V_188 ) ;
}
F_27 ( & V_2 -> V_80 ) ;
V_2 -> V_98 = V_187 << 16 | V_182 ;
V_2 -> V_100 = V_188 << 16 | V_183 ;
V_2 -> V_97 = true ;
F_48 ( V_2 , V_106 ) ;
F_28 ( & V_2 -> V_80 ) ;
return 0 ;
}
static void V_97 ( void * V_83 )
{
F_61 ( V_83 , true ) ;
}
static int F_64 ( struct V_57 * V_17 ,
struct V_195 * V_196 , T_2 V_197 , T_2 V_183 , T_2 V_188 )
{
struct V_46 * V_47 = V_17 -> V_47 ;
struct V_1 * V_2 = F_32 ( V_17 ) ;
struct V_32 * V_33 = NULL ;
int V_48 ;
if ( ! V_2 -> V_69 -> V_70 )
return - V_198 ;
if ( V_197 && V_183 > 0 && V_188 > 0 ) {
if ( V_183 > 64 || V_188 > 64 || ( V_183 > 32 && V_188 > 32 ) )
return - V_199 ;
V_33 = F_65 ( V_47 , V_196 , V_197 ) ;
if ( ! V_33 )
return - V_200 ;
if ( ! V_33 -> V_172 ) {
F_66 ( & V_33 -> V_33 ) ;
return - V_201 ;
}
if ( V_33 -> V_33 . V_202 < V_183 * V_188 * 4 ) {
F_13 ( L_7 ) ;
F_66 ( & V_33 -> V_33 ) ;
return - V_199 ;
}
}
F_67 ( & V_47 -> V_203 ) ;
if ( V_2 -> V_193 ) {
V_2 -> V_193 -> V_204 = NULL ;
V_2 -> V_193 -> V_205 = NULL ;
F_68 ( & V_2 -> V_193 -> V_33 ) ;
}
V_2 -> V_193 = V_33 ;
V_2 -> V_184 = V_183 ;
V_2 -> V_189 = V_188 ;
V_48 = F_61 ( V_2 , true ) ;
if ( V_33 ) {
V_33 -> V_205 = V_2 ;
V_33 -> V_204 = V_97 ;
}
F_69 ( & V_47 -> V_203 ) ;
return V_48 ;
}
static int F_70 ( struct V_57 * V_17 , int V_29 , int V_30 )
{
struct V_46 * V_47 = V_17 -> V_47 ;
struct V_1 * V_2 = F_32 ( V_17 ) ;
int V_48 ;
if ( ! V_2 -> V_69 -> V_70 )
return - V_206 ;
F_67 ( & V_47 -> V_203 ) ;
V_2 -> V_191 = V_29 ;
V_2 -> V_192 = V_30 ;
V_48 = F_61 ( V_2 , false ) ;
F_69 ( & V_47 -> V_203 ) ;
return V_48 ;
}
static void F_71 ( struct V_57 * V_17 )
{
struct V_1 * V_2 = F_32 ( V_17 ) ;
struct V_207 * V_208 = V_17 -> V_47 -> V_209 ;
if ( V_2 -> V_193 )
F_68 ( & V_2 -> V_193 -> V_33 ) ;
V_208 -> V_2 [ V_2 -> V_49 ] = NULL ;
F_72 ( & V_2 -> V_17 ) ;
if ( ! F_73 ( V_2 -> V_210 ) )
F_74 ( V_2 -> V_210 ) ;
F_3 ( 0 , V_2 -> V_7 + V_114 ) ;
F_75 ( V_2 -> V_17 . V_211 ) ;
F_20 ( V_2 ) ;
}
static int F_76 ( struct V_57 * V_17 ,
struct V_27 * V_28 , struct V_212 * V_53 , T_2 V_213 )
{
struct V_1 * V_2 = F_32 ( V_17 ) ;
struct V_44 * V_45 ;
struct V_46 * V_47 = V_17 -> V_47 ;
unsigned long V_19 ;
unsigned V_39 ;
int V_48 ;
if ( V_28 -> V_214 != V_17 -> V_129 -> V_28 -> V_214 )
return - V_201 ;
V_45 = F_23 ( sizeof( * V_45 ) , V_56 ) ;
if ( ! V_45 )
return - V_199 ;
V_45 -> V_53 = V_53 ;
V_45 -> V_54 = V_2 -> V_17 . V_129 -> V_28 ;
V_39 = F_6 ( V_28 , V_17 -> V_29 , V_17 -> V_30 , V_45 -> V_4 ,
V_2 -> V_31 ) ;
F_24 ( V_45 -> V_4 , V_39 ) ;
F_51 ( V_28 ) ;
V_48 = F_11 ( V_2 , V_45 ) ;
if ( V_48 ) {
F_22 ( V_28 ) ;
F_20 ( V_45 ) ;
return V_48 ;
}
V_2 -> V_17 . V_129 -> V_28 = V_28 ;
if ( F_5 ( V_2 -> V_12 ) ) {
F_14 ( & V_47 -> V_50 , V_19 ) ;
if ( V_2 -> V_51 )
F_17 ( V_2 ) ;
F_15 ( & V_47 -> V_50 , V_19 ) ;
}
return 0 ;
}
static int
F_77 ( struct V_57 * V_17 ,
struct V_215 * V_216 , T_6 V_8 )
{
struct V_207 * V_208 = V_17 -> V_47 -> V_209 ;
struct V_1 * V_2 = F_32 ( V_17 ) ;
bool V_217 = false ;
if ( V_216 == V_208 -> V_218 ) {
V_2 -> V_115 = V_8 ;
V_217 = true ;
} else if ( V_216 == V_208 -> V_219 ) {
V_2 -> V_118 = V_8 ;
V_217 = true ;
}
if ( V_217 ) {
T_2 V_8 ;
V_8 = V_2 -> V_159 |
F_49 ( V_2 ) ;
F_3 ( V_8 , V_2 -> V_7 + V_160 ) ;
}
return 0 ;
}
static int F_78 ( struct V_46 * V_47 )
{
struct V_207 * V_208 = V_47 -> V_209 ;
if ( V_208 -> V_218 )
return 0 ;
V_208 -> V_218 = F_79 ( V_47 , 0 ,
L_8 , V_220 ,
F_80 ( V_220 ) ) ;
V_208 -> V_219 = F_79 ( V_47 , 0 ,
L_9 , V_221 ,
F_80 ( V_221 ) ) ;
if ( ! V_208 -> V_218 || ! V_208 -> V_219 )
return - V_199 ;
return 0 ;
}
int F_81 ( struct V_46 * V_222 , struct V_223 * V_47 ,
struct V_224 * V_225 , int V_108 , const struct V_226 * V_69 ,
struct V_227 * V_211 )
{
struct V_207 * V_208 = V_222 -> V_209 ;
struct V_1 * V_2 ;
void T_1 * V_7 ;
int V_48 ;
V_48 = F_78 ( V_222 ) ;
if ( V_48 )
return V_48 ;
V_7 = F_82 ( V_47 , V_225 ) ;
if ( F_73 ( V_7 ) )
return F_83 ( V_7 ) ;
V_2 = F_84 ( sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 ) {
F_13 ( L_10 ) ;
return - V_199 ;
}
if ( V_47 != V_222 -> V_47 )
F_85 ( V_47 , V_2 ) ;
V_2 -> V_69 = V_69 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_49 = V_222 -> V_228 . V_229 ;
V_2 -> V_210 = F_86 ( - V_201 ) ;
V_2 -> V_115 = V_123 ;
V_2 -> V_118 = V_123 ;
V_2 -> V_11 = V_15 ;
V_2 -> V_159 = V_230 | V_231 ;
F_87 ( & V_2 -> V_80 ) ;
V_2 -> V_111 = V_232 ;
F_88 ( & V_2 -> V_233 ) ;
F_89 ( & V_2 -> V_107 ) ;
F_3 ( 0x00000001 , V_2 -> V_7 + V_140 ) ;
F_3 ( 0x00000000 , V_2 -> V_7 + V_234 ) ;
F_3 ( V_2 -> V_159 ,
V_2 -> V_7 + V_160 ) ;
F_3 ( 0x00000000 , V_2 -> V_7 + V_235 ) ;
F_3 ( V_162 | V_163 | V_164 |
V_165 | V_166 | V_167 |
V_138 , V_2 -> V_7 + V_139 ) ;
F_3 ( 0x2032ff81 , V_2 -> V_7 + V_158 ) ;
F_3 ( 0x00000000 , V_2 -> V_7 + V_236 ) ;
F_3 ( V_2 -> V_111 , V_2 -> V_7 + V_114 ) ;
F_3 ( 0 , V_2 -> V_7 + V_110 ) ;
V_48 = F_90 ( V_47 , V_108 , F_46 , 0 , L_11 ,
V_2 ) ;
if ( V_48 < 0 ) {
F_20 ( V_2 ) ;
return V_48 ;
}
if ( V_2 -> V_69 -> V_237 ) {
V_48 = V_2 -> V_69 -> V_237 ( V_2 , V_47 ) ;
if ( V_48 ) {
F_20 ( V_2 ) ;
return V_48 ;
}
}
F_42 ( V_238 , 0 , V_2 -> V_7 + V_105 ) ;
V_208 -> V_2 [ V_2 -> V_49 ] = V_2 ;
V_2 -> V_17 . V_211 = V_211 ;
F_91 ( V_222 , & V_2 -> V_17 , & V_239 ) ;
F_92 ( & V_2 -> V_17 , & V_240 ) ;
F_93 ( & V_2 -> V_17 . V_7 , V_208 -> V_218 ,
V_2 -> V_115 ) ;
F_93 ( & V_2 -> V_17 . V_7 , V_208 -> V_219 ,
V_2 -> V_118 ) ;
return F_94 ( V_222 , 1 << V_2 -> V_49 ) ;
}
static int
F_95 ( struct V_223 * V_47 , struct V_223 * V_241 , void * V_83 )
{
struct V_242 * V_243 = F_96 ( V_47 ) ;
struct V_46 * V_222 = V_83 ;
struct V_224 * V_225 = F_97 ( V_243 , V_244 , 0 ) ;
int V_108 = F_98 ( V_243 , 0 ) ;
const struct V_226 * V_69 ;
struct V_227 * V_211 = NULL ;
if ( V_108 < 0 )
return V_108 ;
if ( ! V_47 -> V_245 ) {
const struct V_246 * V_247 ;
V_247 = F_99 ( V_243 ) ;
if ( ! V_247 )
return - V_198 ;
V_69 = ( const struct V_226 * ) V_247 -> V_248 ;
} else {
const struct V_249 * V_250 ;
struct V_227 * V_251 , * V_252 = V_47 -> V_245 ;
V_250 = F_100 ( V_47 -> V_253 -> V_254 , V_47 ) ;
if ( ! V_250 )
return - V_198 ;
V_251 = F_101 ( V_252 , L_12 ) ;
if ( V_251 )
V_252 = V_251 ;
V_211 = F_101 ( V_252 , L_13 ) ;
F_75 ( V_251 ) ;
if ( ! V_211 ) {
F_102 ( V_47 , L_14 ,
V_252 -> V_255 ) ;
return - V_198 ;
}
V_69 = V_250 -> V_83 ;
}
return F_81 ( V_222 , V_47 , V_225 , V_108 , V_69 , V_211 ) ;
}
static void
F_103 ( struct V_223 * V_47 , struct V_223 * V_241 , void * V_83 )
{
struct V_1 * V_2 = F_104 ( V_47 ) ;
F_71 ( & V_2 -> V_17 ) ;
}
static int F_105 ( struct V_242 * V_243 )
{
return F_106 ( & V_243 -> V_47 , & V_256 ) ;
}
static int F_107 ( struct V_242 * V_243 )
{
F_108 ( & V_243 -> V_47 , & V_256 ) ;
return 0 ;
}
