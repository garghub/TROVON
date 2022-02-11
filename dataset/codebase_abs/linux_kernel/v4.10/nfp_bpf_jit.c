static bool
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return V_3 -> V_4 . V_5 != & V_1 -> V_6 ;
}
static bool
F_2 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return V_3 -> V_4 . V_7 != & V_1 -> V_6 ;
}
static void F_3 ( struct V_1 * V_1 )
{
struct V_2 * V_3 , * V_8 ;
F_4 (meta, tmp, &nfp_prog->insns, l) {
F_5 ( & V_3 -> V_4 ) ;
F_6 ( V_3 ) ;
}
F_6 ( V_1 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_9 )
{
if ( V_1 -> V_10 == V_1 -> V_11 ) {
V_1 -> error = - V_12 ;
return;
}
V_1 -> V_13 [ V_1 -> V_11 ] = V_9 ;
V_1 -> V_11 ++ ;
}
static unsigned int F_8 ( struct V_1 * V_1 )
{
return V_1 -> V_14 + V_1 -> V_11 ;
}
static unsigned int
F_9 ( struct V_1 * V_1 , unsigned int V_15 )
{
return V_15 - V_1 -> V_14 ;
}
static T_2 F_10 ( T_3 V_16 , bool V_17 )
{
T_2 V_18 = F_11 ( V_19 , V_16 ) ;
switch ( F_11 ( V_20 , V_16 ) ) {
case V_21 :
case V_22 :
case V_23 :
return V_18 ;
case V_24 :
return V_25 | V_18 ;
case V_26 :
return V_27 | V_18 ;
case V_28 :
if ( V_18 & ~ 0xff ) {
F_12 ( L_1 ) ;
return 0 ;
}
return F_13 ( V_18 ) ;
case V_29 :
return V_17 ? V_30 : V_31 ;
default:
F_12 ( L_2 , V_16 ) ;
return 0 ;
}
}
static int
F_14 ( T_3 V_32 , T_3 V_33 , T_3 V_34 , struct V_35 * V_36 )
{
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
if ( F_11 ( V_20 , V_32 ) == V_28 )
return - V_37 ;
if ( F_11 ( V_20 , V_32 ) == V_22 )
V_36 -> V_38 = V_39 ;
if ( F_11 ( V_20 , V_32 ) == V_23 )
V_36 -> V_40 = true ;
V_36 -> V_32 = F_10 ( V_32 , true ) ;
if ( F_11 ( V_20 , V_33 ) == F_11 ( V_20 , V_34 ) )
return - V_37 ;
if ( F_11 ( V_20 , V_33 ) == V_22 ||
F_11 ( V_20 , V_34 ) == V_21 ) {
V_36 -> V_41 = F_10 ( V_34 , false ) ;
V_36 -> V_42 = F_10 ( V_33 , false ) ;
V_36 -> V_43 = true ;
} else {
V_36 -> V_41 = F_10 ( V_33 , false ) ;
V_36 -> V_42 = F_10 ( V_34 , false ) ;
}
return 0 ;
}
static T_2 F_15 ( T_3 V_16 , bool V_17 , bool V_44 , bool * V_45 )
{
T_2 V_18 = F_11 ( V_19 , V_16 ) ;
switch ( F_11 ( V_20 , V_16 ) ) {
case V_21 :
case V_22 :
case V_23 :
return V_18 ;
case V_26 :
return V_46 | V_18 ;
case V_28 :
if ( V_18 & ~ ( 0x7f | V_44 << 7 ) ) {
F_12 ( L_1 ) ;
return 0 ;
}
* V_45 = V_18 & 0x80 ;
return F_16 ( V_18 & 0x7f ) ;
case V_29 :
return V_17 ? V_47 : V_31 ;
default:
F_12 ( L_3 ) ;
return 0 ;
}
}
static int
F_17 ( T_3 V_32 , T_3 V_33 , T_3 V_34 , struct V_48 * V_36 ,
bool V_44 )
{
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
if ( F_11 ( V_20 , V_32 ) == V_28 )
return - V_37 ;
if ( F_11 ( V_20 , V_32 ) == V_22 )
V_36 -> V_38 = V_39 ;
if ( F_11 ( V_20 , V_32 ) == V_23 )
V_36 -> V_40 = true ;
V_36 -> V_32 = F_15 ( V_32 , true , false , NULL ) ;
if ( F_11 ( V_20 , V_33 ) == F_11 ( V_20 , V_34 ) )
return - V_37 ;
if ( F_11 ( V_20 , V_33 ) == V_22 ||
F_11 ( V_20 , V_34 ) == V_21 ) {
V_36 -> V_41 = F_15 ( V_34 , false , V_44 , & V_36 -> V_45 ) ;
V_36 -> V_42 = F_15 ( V_33 , false , V_44 , & V_36 -> V_45 ) ;
V_36 -> V_43 = true ;
} else {
V_36 -> V_41 = F_15 ( V_33 , false , V_44 , & V_36 -> V_45 ) ;
V_36 -> V_42 = F_15 ( V_34 , false , V_44 , & V_36 -> V_45 ) ;
}
return 0 ;
}
static void
F_18 ( struct V_1 * V_1 , enum V_49 V_50 ,
T_4 V_51 , T_4 V_52 , T_4 V_41 , T_4 V_42 , T_4 V_53 , bool V_54 )
{
enum V_55 V_56 ;
T_1 V_9 ;
if ( V_54 )
V_56 = V_57 ;
else
V_56 = V_58 ;
V_9 = F_19 ( V_59 , V_41 ) |
F_19 ( V_60 , V_56 ) |
F_19 ( V_61 , V_42 ) |
F_19 ( V_62 , V_63 [ V_50 ] . V_64 ) |
F_19 ( V_65 , V_52 ) |
F_19 ( V_66 , V_53 ) |
F_19 ( V_67 , V_54 ) |
F_19 ( V_68 , V_63 [ V_50 ] . V_69 ) |
F_19 ( V_70 , V_51 ) ;
F_7 ( V_1 , V_9 ) ;
}
static void
F_20 ( struct V_1 * V_1 , enum V_49 V_50 ,
T_4 V_51 , T_4 V_52 , T_3 V_33 , T_3 V_34 , T_4 V_53 , bool V_54 )
{
struct V_48 V_36 ;
int V_71 ;
V_71 = F_17 ( F_21 () , V_33 , V_34 , & V_36 , false ) ;
if ( V_71 ) {
V_1 -> error = V_71 ;
return;
}
if ( V_36 . V_43 ) {
F_12 ( L_4 ) ;
V_1 -> error = - V_37 ;
return;
}
F_18 ( V_1 , V_50 , V_51 , V_52 , V_36 . V_41 , V_36 . V_42 , V_53 , V_54 ) ;
}
static void
F_22 ( struct V_1 * V_1 , enum V_72 V_73 , enum V_74 V_75 ,
enum V_76 V_77 , T_2 V_78 , T_4 V_79 )
{
T_2 V_80 , V_81 ;
T_1 V_9 ;
V_80 = V_78 & ( V_82 >> F_23 ( V_82 ) ) ;
V_81 = V_78 != V_80 ;
V_9 = V_83 |
F_19 ( V_84 , V_73 ) |
F_19 ( V_85 , V_75 ) |
F_19 ( V_86 , V_77 ) |
F_19 ( V_87 , V_79 ) |
F_19 ( V_82 , V_80 ) |
F_19 ( V_88 , V_81 ) ;
F_7 ( V_1 , V_9 ) ;
}
static void F_24 ( struct V_1 * V_1 , T_2 V_78 , T_4 V_79 )
{
if ( V_79 > 2 ) {
F_12 ( L_5 , V_79 ) ;
V_1 -> error = - V_37 ;
return;
}
F_22 ( V_1 , V_89 , V_90 , V_91 , V_78 , V_79 ) ;
}
static void
F_25 ( struct V_1 * V_1 , enum V_72 V_73 , T_2 V_78 , T_4 V_79 )
{
F_22 ( V_1 , V_73 ,
V_73 != V_89 ? V_92 : V_90 ,
V_91 , V_78 , V_79 ) ;
}
static void
F_26 ( struct V_1 * V_1 , T_4 V_41 , T_4 V_42 , bool V_93 ,
T_4 V_94 , bool V_95 , T_2 V_78 , T_4 V_79 )
{
T_2 V_80 , V_81 ;
T_1 V_9 ;
V_80 = V_78 & ( V_96 >> F_23 ( V_96 ) ) ;
V_81 = V_78 != V_80 ;
V_9 = V_97 |
F_19 ( V_98 , V_41 ) |
F_19 ( V_99 , V_94 ) |
F_19 ( V_100 , V_42 ) |
F_19 ( V_101 , V_93 ) |
F_19 ( V_102 , V_95 ) |
F_19 ( V_103 , V_79 ) |
F_19 ( V_96 , V_80 ) |
F_19 ( V_104 , V_81 ) ;
F_7 ( V_1 , V_9 ) ;
}
static void
F_27 ( struct V_1 * V_1 ,
T_3 V_32 , T_4 V_105 , T_4 V_94 , T_2 V_78 , T_4 V_79 )
{
struct V_48 V_36 ;
int V_71 ;
V_71 = F_17 ( F_21 () , V_32 , F_28 ( V_105 ) , & V_36 , true ) ;
if ( V_71 ) {
V_1 -> error = V_71 ;
return;
}
F_26 ( V_1 , V_36 . V_41 , V_36 . V_42 , V_36 . V_45 , V_94 , false , V_78 ,
V_79 ) ;
}
static void
F_29 ( struct V_1 * V_1 , T_2 V_41 , T_2 V_42 , T_2 V_106 ,
enum V_107 V_108 , bool V_109 ,
enum V_110 V_111 , bool V_40 )
{
T_1 V_9 ;
V_9 = V_112 |
F_19 ( V_113 , V_41 ) |
F_19 ( V_114 , V_42 ) |
F_19 ( V_115 , V_106 ) |
F_19 ( V_116 , V_108 ) |
F_19 ( V_117 , V_109 ) |
F_19 ( V_118 , V_111 ) |
F_19 ( V_119 , V_40 ) ;
F_7 ( V_1 , V_9 ) ;
}
static void
F_30 ( struct V_1 * V_1 , T_3 V_32 , T_2 V_105 ,
enum V_107 V_108 , bool V_109 , enum V_110 V_111 )
{
struct V_35 V_36 ;
int V_71 ;
if ( F_11 ( V_20 , V_32 ) == V_28 ) {
V_1 -> error = - V_37 ;
return;
}
V_71 = F_14 ( V_32 , V_32 , F_28 ( V_105 & 0xff ) , & V_36 ) ;
if ( V_71 ) {
V_1 -> error = V_71 ;
return;
}
F_29 ( V_1 , V_36 . V_41 , V_36 . V_42 , V_105 >> 8 , V_108 ,
V_109 , V_111 , V_36 . V_40 ) ;
}
static void
F_31 ( struct V_1 * V_1 , T_2 V_32 , enum V_120 V_38 ,
enum V_121 V_122 , T_4 V_111 ,
T_2 V_41 , enum V_123 V_50 , T_2 V_42 , bool V_45 , bool V_124 , bool V_40 )
{
T_1 V_9 ;
if ( ! F_32 ( V_125 , V_111 ) ) {
V_1 -> error = - V_37 ;
return;
}
if ( V_122 == V_126 )
V_111 = 32 - V_111 ;
V_9 = V_127 |
F_19 ( V_128 , V_41 ) |
F_19 ( V_129 , V_122 ) |
F_19 ( V_130 , V_42 ) |
F_19 ( V_131 , V_45 ) |
F_19 ( V_132 , V_124 ) |
F_19 ( V_133 , V_32 ) |
F_19 ( V_125 , V_111 ) |
F_19 ( V_134 , V_50 ) |
F_19 ( V_135 , V_38 ) |
F_19 ( V_136 , V_40 ) ;
F_7 ( V_1 , V_9 ) ;
}
static void
F_33 ( struct V_1 * V_1 , T_3 V_32 , T_3 V_33 , enum V_123 V_50 , T_3 V_34 ,
enum V_121 V_122 , T_4 V_111 )
{
struct V_48 V_36 ;
int V_71 ;
V_71 = F_17 ( V_32 , V_33 , V_34 , & V_36 , true ) ;
if ( V_71 ) {
V_1 -> error = V_71 ;
return;
}
F_31 ( V_1 , V_36 . V_32 , V_36 . V_38 , V_122 , V_111 ,
V_36 . V_41 , V_50 , V_36 . V_42 , V_36 . V_45 , V_36 . V_43 , V_36 . V_40 ) ;
}
static void
F_34 ( struct V_1 * V_1 , T_2 V_32 , enum V_120 V_38 ,
T_2 V_41 , enum V_137 V_50 , T_2 V_42 , bool V_43 , bool V_40 )
{
T_1 V_9 ;
V_9 = V_138 |
F_19 ( V_139 , V_41 ) |
F_19 ( V_140 , V_42 ) |
F_19 ( V_141 , V_32 ) |
F_19 ( V_142 , V_43 ) |
F_19 ( V_143 , V_50 ) |
F_19 ( V_144 , V_38 ) |
F_19 ( V_145 , V_40 ) ;
F_7 ( V_1 , V_9 ) ;
}
static void
F_35 ( struct V_1 * V_1 , T_3 V_32 , T_3 V_33 , enum V_137 V_50 , T_3 V_34 )
{
struct V_35 V_36 ;
int V_71 ;
V_71 = F_14 ( V_32 , V_33 , V_34 , & V_36 ) ;
if ( V_71 ) {
V_1 -> error = V_71 ;
return;
}
F_34 ( V_1 , V_36 . V_32 , V_36 . V_38 ,
V_36 . V_41 , V_50 , V_36 . V_42 , V_36 . V_43 , V_36 . V_40 ) ;
}
static void
F_36 ( struct V_1 * V_1 , enum V_121 V_122 ,
T_4 V_41 , T_4 V_146 , T_4 V_42 , T_4 V_111 , bool V_93 ,
bool V_147 , bool V_43 , bool V_40 )
{
T_1 V_9 ;
V_9 = V_148 |
F_19 ( V_149 , V_41 ) |
F_19 ( V_150 , V_122 ) |
F_19 ( V_151 , V_42 ) |
F_19 ( V_152 , V_93 ) |
F_19 ( V_153 , V_43 ) |
F_19 ( V_154 , V_147 ) |
F_19 ( V_155 , V_146 ) |
F_19 ( V_156 , V_111 ) |
F_19 ( V_157 , V_40 ) ;
F_7 ( V_1 , V_9 ) ;
}
static void
F_37 ( struct V_1 * V_1 , enum V_121 V_122 , T_4 V_111 ,
T_3 V_32 , T_4 V_146 , T_3 V_158 , bool V_147 )
{
struct V_48 V_36 ;
int V_71 ;
V_71 = F_17 ( F_21 () , V_32 , V_158 , & V_36 , true ) ;
if ( V_71 ) {
V_1 -> error = V_71 ;
return;
}
F_36 ( V_1 , V_122 , V_36 . V_41 , V_146 , V_36 . V_42 , V_111 ,
V_36 . V_45 , V_147 , V_36 . V_43 , V_36 . V_40 ) ;
}
static void
F_38 ( struct V_1 * V_1 , T_3 V_32 , T_4 V_146 , T_3 V_158 ,
enum V_121 V_122 , T_4 V_111 )
{
F_37 ( V_1 , V_122 , V_111 , V_32 , V_146 , V_158 , false ) ;
}
static bool F_39 ( T_3 V_105 , T_2 * V_18 , enum V_110 * V_111 )
{
if ( ! ( V_105 & 0xffff0000 ) ) {
* V_18 = V_105 ;
* V_111 = V_159 ;
} else if ( ! ( V_105 & 0xff0000ff ) ) {
* V_18 = V_105 >> 8 ;
* V_111 = V_160 ;
} else if ( ! ( V_105 & 0x0000ffff ) ) {
* V_18 = V_105 >> 16 ;
* V_111 = V_161 ;
} else {
return false ;
}
return true ;
}
static void F_40 ( struct V_1 * V_1 , T_3 V_32 , T_3 V_105 )
{
enum V_110 V_111 ;
T_2 V_18 ;
if ( F_39 ( V_105 , & V_18 , & V_111 ) ) {
F_30 ( V_1 , V_32 , V_18 , V_162 , false , V_111 ) ;
} else if ( F_39 ( ~ V_105 , & V_18 , & V_111 ) ) {
F_30 ( V_1 , V_32 , V_18 , V_162 , true , V_111 ) ;
} else {
F_30 ( V_1 , V_32 , V_105 & 0xffff , V_162 ,
false , V_159 ) ;
F_30 ( V_1 , V_32 , V_105 >> 16 , V_163 ,
false , V_161 ) ;
}
}
static T_3 F_41 ( struct V_1 * V_1 , T_3 V_105 , T_3 V_164 )
{
if ( F_32 ( V_165 , V_105 ) )
return F_28 ( V_105 ) ;
F_40 ( V_1 , V_164 , V_105 ) ;
return V_164 ;
}
static T_3 F_42 ( struct V_1 * V_1 , T_3 V_105 , T_3 V_164 )
{
if ( F_32 ( V_166 , V_105 ) )
return F_28 ( V_105 ) ;
F_40 ( V_1 , V_164 , V_105 ) ;
return V_164 ;
}
static void
F_43 ( struct V_1 * V_1 , enum V_72 V_73 ,
enum V_167 V_168 )
{
F_25 ( V_1 , V_73 , 0 , 0 ) ;
V_1 -> V_13 [ V_1 -> V_11 - 1 ] |=
F_19 ( V_169 , V_168 ) ;
}
static void F_44 ( struct V_1 * V_1 , T_2 V_32 , T_2 V_158 )
{
F_35 ( V_1 , F_45 ( V_32 ) , F_21 () , V_170 , F_46 ( V_158 ) ) ;
}
static int
F_47 ( struct V_1 * V_1 , T_2 V_15 ,
T_2 V_158 , bool V_171 , T_4 V_53 )
{
unsigned int V_172 ;
T_2 V_111 , V_173 ;
T_3 V_164 ;
V_173 = V_53 < 4 ? 4 : V_53 ;
V_111 = V_53 < 4 ? 4 - V_53 : 0 ;
if ( V_171 ) {
V_164 = F_41 ( V_1 , V_15 , F_48 ( V_1 ) ) ;
F_35 ( V_1 , F_49 ( V_1 ) ,
F_50 ( V_158 ) , V_174 , V_164 ) ;
F_35 ( V_1 , F_51 ( V_1 ) ,
F_51 ( V_1 ) , V_174 , F_28 ( V_53 ) ) ;
F_35 ( V_1 , F_21 () ,
V_175 , V_176 , F_51 ( V_1 ) ) ;
F_43 ( V_1 , V_177 , V_178 ) ;
F_20 ( V_1 , V_179 , V_180 , 0 ,
F_52 ( V_1 ) , F_48 ( V_1 ) , V_173 - 1 , true ) ;
} else {
V_164 = F_41 ( V_1 , V_15 + V_53 ,
F_51 ( V_1 ) ) ;
F_35 ( V_1 , F_21 () ,
V_175 , V_176 , V_164 ) ;
F_43 ( V_1 , V_177 , V_178 ) ;
V_164 = F_42 ( V_1 , V_15 , F_48 ( V_1 ) ) ;
F_20 ( V_1 , V_179 , V_180 , 0 ,
F_52 ( V_1 ) , V_164 , V_173 - 1 , true ) ;
}
V_172 = 0 ;
if ( V_111 )
F_33 ( V_1 , F_45 ( 0 ) , F_21 () , V_181 ,
F_53 ( 0 ) , V_182 , V_111 * 8 ) ;
else
for (; V_172 * 4 < V_53 ; V_172 ++ )
F_35 ( V_1 , F_45 ( V_172 ) ,
F_21 () , V_170 , F_53 ( V_172 ) ) ;
if ( V_172 < 2 )
F_40 ( V_1 , F_45 ( 1 ) , 0 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_1 , T_2 V_15 , T_4 V_53 )
{
return F_47 ( V_1 , V_15 , 0 , false , V_53 ) ;
}
static int F_55 ( struct V_1 * V_1 , T_4 V_158 )
{
F_35 ( V_1 , V_183 ,
F_21 () , V_170 , F_46 ( V_158 ) ) ;
F_35 ( V_1 , V_184 ,
V_184 , V_185 , F_28 ( V_186 ) ) ;
return 0 ;
}
static void
F_56 ( struct V_1 * V_1 , T_4 V_32 , enum V_137 V_137 , T_3 V_105 )
{
T_3 V_164 ;
if ( V_137 == V_187 ) {
if ( ! V_105 )
F_40 ( V_1 , F_45 ( V_32 ) , 0 ) ;
if ( ! V_105 || ! ~ V_105 )
return;
}
if ( V_137 == V_185 ) {
if ( ! ~ V_105 )
F_40 ( V_1 , F_45 ( V_32 ) , ~ 0U ) ;
if ( ! V_105 || ! ~ V_105 )
return;
}
if ( V_137 == V_188 ) {
if ( ! ~ V_105 )
F_35 ( V_1 , F_45 ( V_32 ) , F_21 () ,
V_189 , F_46 ( V_32 ) ) ;
if ( ! V_105 || ! ~ V_105 )
return;
}
V_164 = F_41 ( V_1 , V_105 , F_48 ( V_1 ) ) ;
F_35 ( V_1 , F_45 ( V_32 ) , F_50 ( V_32 ) , V_137 , V_164 ) ;
}
static int
F_57 ( struct V_1 * V_1 , struct V_2 * V_3 ,
enum V_137 V_137 , bool V_190 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
T_1 V_105 = V_9 -> V_105 ;
if ( V_190 ) {
V_3 -> V_190 = true ;
return 0 ;
}
F_56 ( V_1 , V_9 -> V_192 * 2 , V_137 , V_105 & ~ 0U ) ;
F_56 ( V_1 , V_9 -> V_192 * 2 + 1 , V_137 , V_105 >> 32 ) ;
return 0 ;
}
static int
F_58 ( struct V_1 * V_1 , struct V_2 * V_3 ,
enum V_137 V_137 )
{
T_4 V_32 = V_3 -> V_9 . V_192 * 2 , V_158 = V_3 -> V_9 . V_193 * 2 ;
F_35 ( V_1 , F_45 ( V_32 ) , F_50 ( V_32 ) , V_137 , F_46 ( V_158 ) ) ;
F_35 ( V_1 , F_45 ( V_32 + 1 ) ,
F_50 ( V_32 + 1 ) , V_137 , F_46 ( V_158 + 1 ) ) ;
return 0 ;
}
static int
F_59 ( struct V_1 * V_1 , struct V_2 * V_3 ,
enum V_137 V_137 , bool V_190 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
if ( V_190 ) {
V_3 -> V_190 = true ;
return 0 ;
}
F_56 ( V_1 , V_9 -> V_192 * 2 , V_137 , V_9 -> V_105 ) ;
F_40 ( V_1 , F_45 ( V_9 -> V_192 * 2 + 1 ) , 0 ) ;
return 0 ;
}
static int
F_60 ( struct V_1 * V_1 , struct V_2 * V_3 ,
enum V_137 V_137 )
{
T_4 V_32 = V_3 -> V_9 . V_192 * 2 , V_158 = V_3 -> V_9 . V_193 * 2 ;
F_35 ( V_1 , F_45 ( V_32 ) , F_50 ( V_32 ) , V_137 , F_46 ( V_158 ) ) ;
F_40 ( V_1 , F_45 ( V_3 -> V_9 . V_192 * 2 + 1 ) , 0 ) ;
return 0 ;
}
static void
F_61 ( struct V_1 * V_1 , T_4 V_32 , enum V_137 V_137 , T_4 V_158 ,
enum V_72 V_72 , T_2 V_194 )
{
F_35 ( V_1 , F_21 () , F_50 ( V_32 ) , V_137 , F_46 ( V_158 ) ) ;
F_25 ( V_1 , V_72 , V_194 , 0 ) ;
}
static int
F_62 ( struct V_1 * V_1 , struct V_2 * V_3 ,
enum V_137 V_137 , enum V_72 V_72 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
if ( V_9 -> V_194 < 0 )
return - V_195 ;
F_61 ( V_1 , V_9 -> V_192 * 2 , V_137 ,
V_9 -> V_193 * 2 , V_72 , V_9 -> V_194 ) ;
F_61 ( V_1 , V_9 -> V_192 * 2 + 1 , V_137 ,
V_9 -> V_193 * 2 + 1 , V_72 , V_9 -> V_194 ) ;
return 0 ;
}
static int
F_63 ( struct V_1 * V_1 , struct V_2 * V_3 ,
enum V_72 V_72 , bool V_43 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
T_1 V_105 = V_9 -> V_105 ;
T_4 V_36 = V_9 -> V_192 * 2 ;
T_3 V_164 ;
if ( V_9 -> V_194 < 0 )
return - V_195 ;
V_164 = F_41 ( V_1 , V_105 & ~ 0U , F_48 ( V_1 ) ) ;
if ( ! V_43 )
F_35 ( V_1 , F_21 () , F_50 ( V_36 ) , V_176 , V_164 ) ;
else
F_35 ( V_1 , F_21 () , V_164 , V_176 , F_50 ( V_36 ) ) ;
V_164 = F_41 ( V_1 , V_105 >> 32 , F_48 ( V_1 ) ) ;
if ( ! V_43 )
F_35 ( V_1 , F_21 () ,
F_50 ( V_36 + 1 ) , V_196 , V_164 ) ;
else
F_35 ( V_1 , F_21 () ,
V_164 , V_196 , F_50 ( V_36 + 1 ) ) ;
F_25 ( V_1 , V_72 , V_9 -> V_194 , 0 ) ;
return 0 ;
}
static int
F_64 ( struct V_1 * V_1 , struct V_2 * V_3 ,
enum V_72 V_72 , bool V_43 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
T_4 V_41 = V_9 -> V_193 * 2 , V_42 = V_9 -> V_192 * 2 ;
if ( V_9 -> V_194 < 0 )
return - V_195 ;
if ( V_43 ) {
V_41 ^= V_42 ;
V_42 ^= V_41 ;
V_41 ^= V_42 ;
}
F_35 ( V_1 , F_21 () , F_50 ( V_41 ) , V_176 , F_46 ( V_42 ) ) ;
F_35 ( V_1 , F_21 () ,
F_50 ( V_41 + 1 ) , V_196 , F_46 ( V_42 + 1 ) ) ;
F_25 ( V_1 , V_72 , V_9 -> V_194 , 0 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
F_44 ( V_1 , V_9 -> V_192 * 2 , V_9 -> V_193 * 2 ) ;
F_44 ( V_1 , V_9 -> V_192 * 2 + 1 , V_9 -> V_193 * 2 + 1 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
T_1 V_105 = V_3 -> V_9 . V_105 ;
F_40 ( V_1 , F_45 ( V_3 -> V_9 . V_192 * 2 ) , V_105 & ~ 0U ) ;
F_40 ( V_1 , F_45 ( V_3 -> V_9 . V_192 * 2 + 1 ) , V_105 >> 32 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_58 ( V_1 , V_3 , V_188 ) ;
}
static int F_68 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_57 ( V_1 , V_3 , V_188 , ! V_3 -> V_9 . V_105 ) ;
}
static int F_69 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_58 ( V_1 , V_3 , V_187 ) ;
}
static int F_70 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_57 ( V_1 , V_3 , V_187 , ! ~ V_3 -> V_9 . V_105 ) ;
}
static int F_71 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_58 ( V_1 , V_3 , V_185 ) ;
}
static int F_72 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_57 ( V_1 , V_3 , V_185 , ! V_3 -> V_9 . V_105 ) ;
}
static int F_73 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
F_35 ( V_1 , F_45 ( V_9 -> V_192 * 2 ) ,
F_50 ( V_9 -> V_192 * 2 ) , V_174 ,
F_46 ( V_9 -> V_193 * 2 ) ) ;
F_35 ( V_1 , F_45 ( V_9 -> V_192 * 2 + 1 ) ,
F_50 ( V_9 -> V_192 * 2 + 1 ) , V_197 ,
F_46 ( V_9 -> V_193 * 2 + 1 ) ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
T_1 V_105 = V_9 -> V_105 ;
F_56 ( V_1 , V_9 -> V_192 * 2 , V_174 , V_105 & ~ 0U ) ;
F_56 ( V_1 , V_9 -> V_192 * 2 + 1 , V_197 , V_105 >> 32 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
F_35 ( V_1 , F_45 ( V_9 -> V_192 * 2 ) ,
F_50 ( V_9 -> V_192 * 2 ) , V_176 ,
F_46 ( V_9 -> V_193 * 2 ) ) ;
F_35 ( V_1 , F_45 ( V_9 -> V_192 * 2 + 1 ) ,
F_50 ( V_9 -> V_192 * 2 + 1 ) , V_196 ,
F_46 ( V_9 -> V_193 * 2 + 1 ) ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
T_1 V_105 = V_9 -> V_105 ;
F_56 ( V_1 , V_9 -> V_192 * 2 , V_176 , V_105 & ~ 0U ) ;
F_56 ( V_1 , V_9 -> V_192 * 2 + 1 , V_196 , V_105 >> 32 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
if ( V_9 -> V_105 != 32 )
return 1 ;
F_44 ( V_1 , V_9 -> V_192 * 2 + 1 , V_9 -> V_192 * 2 ) ;
F_40 ( V_1 , F_45 ( V_9 -> V_192 * 2 ) , 0 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
if ( V_9 -> V_105 != 32 )
return 1 ;
F_44 ( V_1 , V_9 -> V_192 * 2 , V_9 -> V_192 * 2 + 1 ) ;
F_40 ( V_1 , F_45 ( V_9 -> V_192 * 2 + 1 ) , 0 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
F_44 ( V_1 , V_9 -> V_192 * 2 , V_9 -> V_193 * 2 ) ;
F_40 ( V_1 , F_45 ( V_9 -> V_192 * 2 + 1 ) , 0 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
F_40 ( V_1 , F_45 ( V_9 -> V_192 * 2 ) , V_9 -> V_105 ) ;
F_40 ( V_1 , F_45 ( V_9 -> V_192 * 2 + 1 ) , 0 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_60 ( V_1 , V_3 , V_188 ) ;
}
static int F_82 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_59 ( V_1 , V_3 , V_188 , ! ~ V_3 -> V_9 . V_105 ) ;
}
static int F_83 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_60 ( V_1 , V_3 , V_187 ) ;
}
static int F_84 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_59 ( V_1 , V_3 , V_187 , ! ~ V_3 -> V_9 . V_105 ) ;
}
static int F_85 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_60 ( V_1 , V_3 , V_185 ) ;
}
static int F_86 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_59 ( V_1 , V_3 , V_185 , ! V_3 -> V_9 . V_105 ) ;
}
static int F_87 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_60 ( V_1 , V_3 , V_174 ) ;
}
static int F_88 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_59 ( V_1 , V_3 , V_174 , ! V_3 -> V_9 . V_105 ) ;
}
static int F_89 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_60 ( V_1 , V_3 , V_176 ) ;
}
static int F_90 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_59 ( V_1 , V_3 , V_176 , ! V_3 -> V_9 . V_105 ) ;
}
static int F_91 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
if ( ! V_9 -> V_105 )
return 1 ;
F_33 ( V_1 , F_45 ( V_9 -> V_192 * 2 ) ,
F_21 () , V_181 , F_46 ( V_9 -> V_192 * 2 ) ,
V_126 , V_9 -> V_105 ) ;
F_40 ( V_1 , F_45 ( V_9 -> V_192 * 2 + 1 ) , 0 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_40 ( V_1 , F_45 ( F_93 ( V_3 ) -> V_9 . V_192 * 2 + 1 ) ,
V_3 -> V_9 . V_105 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
V_3 -> V_198 = F_92 ;
F_40 ( V_1 , F_45 ( V_9 -> V_192 * 2 ) , V_9 -> V_105 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_54 ( V_1 , V_3 -> V_9 . V_105 , 1 ) ;
}
static int F_96 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_54 ( V_1 , V_3 -> V_9 . V_105 , 2 ) ;
}
static int F_97 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_54 ( V_1 , V_3 -> V_9 . V_105 , 4 ) ;
}
static int F_98 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_47 ( V_1 , V_3 -> V_9 . V_105 ,
V_3 -> V_9 . V_193 * 2 , true , 1 ) ;
}
static int F_99 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_47 ( V_1 , V_3 -> V_9 . V_105 ,
V_3 -> V_9 . V_193 * 2 , true , 2 ) ;
}
static int F_100 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_47 ( V_1 , V_3 -> V_9 . V_105 ,
V_3 -> V_9 . V_193 * 2 , true , 4 ) ;
}
static int F_101 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( V_3 -> V_9 . V_194 == F_102 ( struct V_199 , V_200 ) )
F_35 ( V_1 , F_45 ( V_3 -> V_9 . V_192 * 2 ) ,
F_21 () , V_170 , V_175 ) ;
else
return - V_195 ;
return 0 ;
}
static int F_103 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
T_3 V_32 = F_45 ( V_3 -> V_9 . V_192 * 2 ) ;
if ( V_3 -> V_9 . V_194 != F_102 ( struct V_201 , V_202 ) &&
V_3 -> V_9 . V_194 != F_102 ( struct V_201 , V_203 ) )
return - V_195 ;
F_35 ( V_1 , V_32 , F_21 () , V_170 , V_204 ) ;
if ( V_3 -> V_9 . V_194 == F_102 ( struct V_201 , V_202 ) )
return 0 ;
F_35 ( V_1 , V_32 , V_32 , V_174 , V_175 ) ;
return 0 ;
}
static int F_104 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_205 ;
if ( V_1 -> V_206 == V_207 )
V_205 = F_103 ( V_1 , V_3 ) ;
else
V_205 = F_101 ( V_1 , V_3 ) ;
F_40 ( V_1 , F_45 ( V_3 -> V_9 . V_192 * 2 + 1 ) , 0 ) ;
return V_205 ;
}
static int F_105 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( V_3 -> V_9 . V_194 == F_102 ( struct V_199 , V_208 ) )
return F_55 ( V_1 , V_3 -> V_9 . V_193 * 2 ) ;
return - V_195 ;
}
static int F_106 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return - V_195 ;
}
static int F_107 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( V_1 -> V_206 == V_207 )
return F_106 ( V_1 , V_3 ) ;
return F_105 ( V_1 , V_3 ) ;
}
static int F_108 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( V_3 -> V_9 . V_194 < 0 )
return - V_195 ;
F_25 ( V_1 , V_89 , V_3 -> V_9 . V_194 , 0 ) ;
return 0 ;
}
static int F_109 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
T_1 V_105 = V_9 -> V_105 ;
T_3 V_209 = F_50 ( V_9 -> V_192 * 2 ) , V_210 = F_46 ( V_9 -> V_192 * 2 + 1 ) ;
T_3 V_164 ;
if ( V_9 -> V_194 < 0 )
return - V_195 ;
if ( V_105 & ~ 0U ) {
V_164 = F_41 ( V_1 , V_105 & ~ 0U , F_48 ( V_1 ) ) ;
F_35 ( V_1 , F_51 ( V_1 ) ,
F_50 ( V_9 -> V_192 * 2 ) , V_188 , V_164 ) ;
V_209 = F_51 ( V_1 ) ;
}
if ( V_105 >> 32 ) {
V_164 = F_41 ( V_1 , V_105 >> 32 , F_48 ( V_1 ) ) ;
F_35 ( V_1 , F_48 ( V_1 ) ,
F_50 ( V_9 -> V_192 * 2 + 1 ) , V_188 , V_164 ) ;
V_210 = F_48 ( V_1 ) ;
}
F_35 ( V_1 , F_21 () , V_209 , V_185 , V_210 ) ;
F_25 ( V_1 , V_211 , V_9 -> V_194 , 0 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_63 ( V_1 , V_3 , V_177 , false ) ;
}
static int F_111 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_63 ( V_1 , V_3 , V_212 , true ) ;
}
static int F_112 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
T_1 V_105 = V_9 -> V_105 ;
T_3 V_164 ;
if ( V_9 -> V_194 < 0 )
return - V_195 ;
if ( ! V_105 ) {
V_3 -> V_190 = true ;
return 0 ;
}
if ( V_105 & ~ 0U ) {
V_164 = F_41 ( V_1 , V_105 & ~ 0U , F_48 ( V_1 ) ) ;
F_35 ( V_1 , F_21 () ,
F_50 ( V_9 -> V_192 * 2 ) , V_187 , V_164 ) ;
F_25 ( V_1 , V_213 , V_9 -> V_194 , 0 ) ;
}
if ( V_105 >> 32 ) {
V_164 = F_41 ( V_1 , V_105 >> 32 , F_48 ( V_1 ) ) ;
F_35 ( V_1 , F_21 () ,
F_50 ( V_9 -> V_192 * 2 + 1 ) , V_187 , V_164 ) ;
F_25 ( V_1 , V_213 , V_9 -> V_194 , 0 ) ;
}
return 0 ;
}
static int F_113 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
T_1 V_105 = V_9 -> V_105 ;
T_3 V_164 ;
if ( V_9 -> V_194 < 0 )
return - V_195 ;
if ( ! V_105 ) {
F_35 ( V_1 , F_21 () , F_50 ( V_9 -> V_192 * 2 ) ,
V_185 , F_46 ( V_9 -> V_192 * 2 + 1 ) ) ;
F_25 ( V_1 , V_213 , V_9 -> V_194 , 0 ) ;
}
V_164 = F_41 ( V_1 , V_105 & ~ 0U , F_48 ( V_1 ) ) ;
F_35 ( V_1 , F_21 () ,
F_50 ( V_9 -> V_192 * 2 ) , V_188 , V_164 ) ;
F_25 ( V_1 , V_213 , V_9 -> V_194 , 0 ) ;
V_164 = F_41 ( V_1 , V_105 >> 32 , F_48 ( V_1 ) ) ;
F_35 ( V_1 , F_21 () ,
F_50 ( V_9 -> V_192 * 2 + 1 ) , V_188 , V_164 ) ;
F_25 ( V_1 , V_213 , V_9 -> V_194 , 0 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
const struct V_191 * V_9 = & V_3 -> V_9 ;
if ( V_9 -> V_194 < 0 )
return - V_195 ;
F_35 ( V_1 , F_51 ( V_1 ) , F_50 ( V_9 -> V_192 * 2 ) ,
V_188 , F_46 ( V_9 -> V_193 * 2 ) ) ;
F_35 ( V_1 , F_48 ( V_1 ) , F_50 ( V_9 -> V_192 * 2 + 1 ) ,
V_188 , F_46 ( V_9 -> V_193 * 2 + 1 ) ) ;
F_35 ( V_1 , F_21 () ,
F_51 ( V_1 ) , V_185 , F_48 ( V_1 ) ) ;
F_25 ( V_1 , V_211 , V_9 -> V_194 , 0 ) ;
return 0 ;
}
static int F_115 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_64 ( V_1 , V_3 , V_177 , false ) ;
}
static int F_116 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_64 ( V_1 , V_3 , V_212 , true ) ;
}
static int F_117 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_62 ( V_1 , V_3 , V_187 , V_213 ) ;
}
static int F_118 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
return F_62 ( V_1 , V_3 , V_188 , V_213 ) ;
}
static int F_119 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_43 ( V_1 , V_89 , V_214 ) ;
return 0 ;
}
static void F_120 ( T_1 * V_215 , T_2 V_15 )
{
T_2 V_80 , V_81 ;
V_80 = V_15 & ( V_82 >> F_23 ( V_82 ) ) ;
V_81 = V_15 != V_80 ;
* V_215 &= ~ ( V_88 | V_82 ) ;
* V_215 |= F_19 ( V_88 , V_81 ) ;
* V_215 |= F_19 ( V_82 , V_80 ) ;
}
static int F_121 ( struct V_1 * V_1 )
{
struct V_2 * V_3 , * V_5 ;
T_3 V_194 , V_216 ;
T_3 V_217 ;
F_122 (nfp_prog, meta, next) {
if ( V_3 -> V_190 )
continue;
if ( F_123 ( V_3 -> V_9 . V_218 ) != V_219 )
continue;
V_216 = F_9 ( V_1 , V_5 -> V_194 ) - 1 ;
if ( ! F_124 ( V_1 -> V_13 [ V_216 ] ) ) {
F_12 ( L_6 ,
V_216 , V_3 -> V_9 . V_218 , V_1 -> V_13 [ V_216 ] ) ;
return - V_220 ;
}
if ( F_11 ( V_169 , V_1 -> V_13 [ V_216 ] ) )
continue;
V_194 = V_3 -> V_9 . V_194 ;
if ( ! V_194 ) {
F_12 ( L_7 ) ;
return - V_220 ;
}
while ( V_194 && F_1 ( V_1 , V_5 ) ) {
V_5 = F_125 ( V_5 ) ;
V_194 -- ;
}
if ( V_194 ) {
F_12 ( L_8 , V_194 ) ;
return - V_220 ;
}
if ( V_5 -> V_190 ) {
F_12 ( L_9 ) ;
return - V_220 ;
}
for ( V_217 = F_9 ( V_1 , V_3 -> V_194 ) ;
V_217 <= V_216 ; V_217 ++ ) {
if ( ! F_124 ( V_1 -> V_13 [ V_217 ] ) )
continue;
F_120 ( & V_1 -> V_13 [ V_217 ] , V_5 -> V_194 ) ;
}
}
for ( V_216 = 0 ; V_216 < V_1 -> V_11 ; V_216 ++ ) {
enum V_167 V_168 ;
if ( ( V_1 -> V_13 [ V_216 ] & V_221 ) != V_83 )
continue;
V_168 = F_11 ( V_169 , V_1 -> V_13 [ V_216 ] ) ;
switch ( V_168 ) {
case V_222 :
break;
case V_214 :
F_120 ( & V_1 -> V_13 [ V_216 ] ,
V_1 -> V_223 ) ;
break;
case V_178 :
F_120 ( & V_1 -> V_13 [ V_216 ] ,
V_1 -> V_224 ) ;
break;
}
V_1 -> V_13 [ V_216 ] &= ~ V_169 ;
}
return 0 ;
}
static void F_126 ( struct V_1 * V_1 )
{
F_35 ( V_1 , F_52 ( V_1 ) ,
F_21 () , V_170 , V_204 ) ;
}
static void F_127 ( struct V_1 * V_1 )
{
const T_4 V_225 [] = {
[ V_226 ] = 0x22 ,
[ V_227 ] = 0x24
} ;
V_1 -> V_224 = F_8 ( V_1 ) ;
F_40 ( V_1 , F_45 ( 0 ) , 0 ) ;
V_1 -> V_223 = F_8 ( V_1 ) ;
F_27 ( V_1 , F_46 ( 0 ) , 0xff , 0 , V_1 -> V_228 , 2 ) ;
F_35 ( V_1 , F_50 ( 0 ) ,
F_21 () , V_170 , V_184 ) ;
F_38 ( V_1 , F_50 ( 0 ) , 0xc , F_28 ( 0x11 ) , V_126 , 16 ) ;
F_25 ( V_1 , V_89 , V_1 -> V_228 , 1 ) ;
F_38 ( V_1 , F_50 ( 0 ) , 0xc , F_28 ( V_225 [ V_1 -> V_206 ] ) ,
V_126 , 16 ) ;
}
static void F_128 ( struct V_1 * V_1 )
{
V_1 -> V_224 = F_8 ( V_1 ) ;
F_24 ( V_1 , V_1 -> V_228 , 2 ) ;
F_35 ( V_1 , F_50 ( 0 ) ,
F_21 () , V_170 , V_184 ) ;
F_38 ( V_1 , F_50 ( 0 ) , 0xc , F_28 ( 0x11 ) , V_126 , 16 ) ;
V_1 -> V_223 = F_8 ( V_1 ) ;
F_35 ( V_1 , F_21 () , F_28 ( 7 ) , V_176 , F_46 ( 0 ) ) ;
F_25 ( V_1 , V_177 , V_1 -> V_224 , 0 ) ;
F_35 ( V_1 , F_50 ( 0 ) ,
F_21 () , V_170 , V_184 ) ;
F_40 ( V_1 , F_46 ( 2 ) , 0x41221211 ) ;
F_40 ( V_1 , F_46 ( 3 ) , 0x41001211 ) ;
F_33 ( V_1 , F_50 ( 1 ) ,
F_21 () , V_181 , F_46 ( 0 ) , V_126 , 2 ) ;
F_35 ( V_1 , F_21 () , F_50 ( 1 ) , V_185 , F_28 ( 0 ) ) ;
F_33 ( V_1 , F_50 ( 2 ) ,
F_28 ( 0xf ) , V_229 , F_46 ( 2 ) , V_182 , 0 ) ;
F_35 ( V_1 , F_21 () , F_50 ( 1 ) , V_185 , F_28 ( 0 ) ) ;
F_33 ( V_1 , F_46 ( 2 ) ,
F_28 ( 0xf ) , V_229 , F_46 ( 3 ) , V_182 , 0 ) ;
F_24 ( V_1 , V_1 -> V_228 , 2 ) ;
F_33 ( V_1 , F_46 ( 2 ) ,
F_50 ( 2 ) , V_230 , F_46 ( 2 ) , V_126 , 4 ) ;
F_38 ( V_1 , F_50 ( 0 ) , 0xc , F_46 ( 2 ) , V_126 , 16 ) ;
}
static void F_129 ( struct V_1 * V_1 )
{
V_1 -> V_224 = F_8 ( V_1 ) ;
F_24 ( V_1 , V_1 -> V_228 , 2 ) ;
F_35 ( V_1 , F_50 ( 0 ) ,
F_21 () , V_170 , V_184 ) ;
F_38 ( V_1 , F_50 ( 0 ) , 0xc , F_28 ( 0x82 ) , V_126 , 16 ) ;
V_1 -> V_223 = F_8 ( V_1 ) ;
F_35 ( V_1 , F_21 () , F_28 ( 3 ) , V_176 , F_46 ( 0 ) ) ;
F_25 ( V_1 , V_177 , V_1 -> V_224 , 0 ) ;
F_40 ( V_1 , F_46 ( 2 ) , 0x44112282 ) ;
F_33 ( V_1 , F_50 ( 1 ) ,
F_21 () , V_181 , F_46 ( 0 ) , V_126 , 3 ) ;
F_35 ( V_1 , F_21 () , F_50 ( 1 ) , V_185 , F_28 ( 0 ) ) ;
F_33 ( V_1 , F_46 ( 2 ) ,
F_28 ( 0xff ) , V_229 , F_46 ( 2 ) , V_182 , 0 ) ;
F_24 ( V_1 , V_1 -> V_228 , 2 ) ;
F_35 ( V_1 , F_50 ( 0 ) ,
F_21 () , V_170 , V_184 ) ;
F_38 ( V_1 , F_50 ( 0 ) , 0xc , F_46 ( 2 ) , V_126 , 16 ) ;
}
static void F_130 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_206 ) {
case V_231 :
F_128 ( V_1 ) ;
break;
case V_226 :
case V_227 :
F_127 ( V_1 ) ;
break;
case V_207 :
F_129 ( V_1 ) ;
break;
}
}
static int F_131 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
int V_71 ;
F_126 ( V_1 ) ;
if ( V_1 -> error )
return V_1 -> error ;
F_132 (meta, &nfp_prog->insns, l) {
T_5 V_232 = V_233 [ V_3 -> V_9 . V_218 ] ;
V_3 -> V_194 = F_8 ( V_1 ) ;
if ( V_3 -> V_190 ) {
V_1 -> V_234 ++ ;
continue;
}
if ( F_2 ( V_1 , V_3 ) &&
F_93 ( V_3 ) -> V_198 )
V_232 = F_93 ( V_3 ) -> V_198 ;
if ( ! V_232 )
return - V_235 ;
V_71 = V_232 ( V_1 , V_3 ) ;
if ( V_71 )
return V_71 ;
V_1 -> V_234 ++ ;
}
F_130 ( V_1 ) ;
if ( V_1 -> error )
return V_1 -> error ;
return F_121 ( V_1 ) ;
}
static int
F_133 ( struct V_1 * V_1 , const struct V_191 * V_13 ,
unsigned int V_236 )
{
unsigned int V_172 ;
for ( V_172 = 0 ; V_172 < V_236 ; V_172 ++ ) {
struct V_2 * V_3 ;
V_3 = F_134 ( sizeof( * V_3 ) , V_237 ) ;
if ( ! V_3 )
return - V_238 ;
V_3 -> V_9 = V_13 [ V_172 ] ;
V_3 -> V_239 = V_172 ;
F_135 ( & V_3 -> V_4 , & V_1 -> V_6 ) ;
}
return 0 ;
}
static void F_136 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
F_132 (meta, &nfp_prog->insns, l) {
struct V_191 V_9 = V_3 -> V_9 ;
if ( V_9 . V_218 == ( V_240 | V_241 | V_242 ) &&
V_9 . V_193 == V_9 . V_192 )
continue;
if ( V_9 . V_218 == ( V_240 | V_243 | V_242 ) &&
V_9 . V_193 == 1 && V_9 . V_192 == 6 )
V_3 -> V_190 = true ;
if ( ! V_3 -> V_190 )
return;
}
}
static int F_137 ( struct V_1 * V_1 )
{
bool V_244 [ V_245 ] = {} ;
T_4 V_246 [ V_245 ] = {} ;
struct V_2 * V_3 ;
unsigned int V_172 , V_247 ;
F_132 (meta, &nfp_prog->insns, l) {
if ( V_3 -> V_190 )
continue;
V_244 [ V_3 -> V_9 . V_193 ] = true ;
V_244 [ V_3 -> V_9 . V_192 ] = true ;
}
for ( V_172 = 0 , V_247 = 0 ; V_172 < F_138 ( V_246 ) ; V_172 ++ ) {
if ( ! V_244 [ V_172 ] )
continue;
V_246 [ V_172 ] = V_247 ++ ;
}
V_1 -> V_248 = V_247 ;
F_132 (meta, &nfp_prog->insns, l) {
V_3 -> V_9 . V_193 = V_246 [ V_3 -> V_9 . V_193 ] ;
V_3 -> V_9 . V_192 = V_246 [ V_3 -> V_9 . V_192 ] ;
}
return 0 ;
}
static void F_139 ( struct V_1 * V_1 )
{
struct V_2 * V_249 , * V_250 ;
const T_6 V_251 [] = {
[ V_252 ] = 0x000000ffU ,
[ V_253 ] = 0x0000ffffU ,
[ V_254 ] = 0xffffffffU ,
} ;
F_122 (nfp_prog, meta1, meta2) {
struct V_191 V_9 , V_5 ;
V_9 = V_249 -> V_9 ;
V_5 = V_250 -> V_9 ;
if ( F_123 ( V_9 . V_218 ) != V_255 )
continue;
if ( F_140 ( V_9 . V_218 ) != V_256 &&
F_140 ( V_9 . V_218 ) != V_257 )
continue;
if ( V_5 . V_218 != ( V_240 | V_258 | V_259 ) )
continue;
if ( ! V_251 [ F_141 ( V_9 . V_218 ) ] )
continue;
if ( V_251 [ F_141 ( V_9 . V_218 ) ] != V_5 . V_105 )
continue;
if ( V_5 . V_193 || V_5 . V_192 )
continue;
V_250 -> V_190 = true ;
}
}
static void F_142 ( struct V_1 * V_1 )
{
struct V_2 * V_249 , * V_250 , * V_260 ;
F_143 (nfp_prog, meta1, meta2, meta3) {
struct V_191 V_9 , V_261 , V_262 ;
V_9 = V_249 -> V_9 ;
V_261 = V_250 -> V_9 ;
V_262 = V_260 -> V_9 ;
if ( F_123 ( V_9 . V_218 ) != V_255 )
continue;
if ( F_140 ( V_9 . V_218 ) != V_256 &&
F_140 ( V_9 . V_218 ) != V_257 )
continue;
if ( F_141 ( V_9 . V_218 ) != V_254 )
continue;
if ( ! ( V_261 . V_218 == ( V_263 | V_259 | V_240 ) &&
V_262 . V_218 == ( V_264 | V_259 | V_240 ) ) &&
! ( V_261 . V_218 == ( V_264 | V_259 | V_240 ) &&
V_262 . V_218 == ( V_263 | V_259 | V_240 ) ) )
continue;
if ( V_261 . V_193 || V_261 . V_192 ||
V_262 . V_193 || V_262 . V_192 )
continue;
if ( V_261 . V_105 != 0x20 || V_262 . V_105 != 0x20 )
continue;
V_250 -> V_190 = true ;
V_260 -> V_190 = true ;
}
}
static int F_144 ( struct V_1 * V_1 )
{
int V_205 ;
F_136 ( V_1 ) ;
V_205 = F_137 ( V_1 ) ;
if ( V_205 )
return V_205 ;
F_139 ( V_1 ) ;
F_142 ( V_1 ) ;
return 0 ;
}
int
F_145 ( struct V_265 * V_266 , void * V_267 ,
enum V_268 V_206 ,
unsigned int V_269 , unsigned int V_270 ,
unsigned int V_271 , struct V_272 * V_273 )
{
struct V_1 * V_1 ;
int V_205 ;
V_1 = F_134 ( sizeof( * V_1 ) , V_237 ) ;
if ( ! V_1 )
return - V_238 ;
F_146 ( & V_1 -> V_6 ) ;
V_1 -> V_206 = V_206 ;
V_1 -> V_14 = V_269 ;
V_1 -> V_228 = V_270 ;
V_205 = F_133 ( V_1 , V_266 -> V_274 , V_266 -> V_200 ) ;
if ( V_205 )
goto V_275;
V_205 = F_147 ( V_1 , V_266 ) ;
if ( V_205 )
goto V_275;
V_205 = F_144 ( V_1 ) ;
if ( V_205 )
goto V_275;
if ( V_1 -> V_248 <= 7 )
V_1 -> V_276 = 16 ;
else
V_1 -> V_276 = 32 ;
V_1 -> V_13 = V_267 ;
V_1 -> V_10 = V_271 ;
V_205 = F_131 ( V_1 ) ;
if ( V_205 ) {
F_12 ( L_10 ,
V_205 , V_1 -> V_234 ) ;
V_205 = - V_277 ;
}
V_273 -> V_278 = V_1 -> V_11 ;
V_273 -> V_279 = V_1 -> V_248 <= 7 ;
V_275:
F_3 ( V_1 ) ;
return V_205 ;
}
