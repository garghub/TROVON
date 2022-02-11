static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int * V_6 ,
unsigned int V_7 [] , void * V_8 [] )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned V_12 = V_10 -> V_13 * V_10 -> V_14 ;
if ( * V_5 < 3 )
* V_5 = 3 ;
if ( * V_5 > V_15 )
* V_5 = V_15 ;
* V_6 = 1 ;
if ( V_4 ) {
if ( V_4 -> V_4 . V_16 . V_17 < V_12 )
return - V_18 ;
V_12 = V_4 -> V_4 . V_16 . V_17 ;
}
V_7 [ 0 ] = V_12 ;
V_8 [ 0 ] = V_10 -> V_19 -> V_20 ;
return 0 ;
}
static int F_2 ( struct V_21 * V_22 )
{
struct V_9 * V_10 = V_22 -> V_1 -> V_11 ;
struct V_19 * V_19 = V_10 -> V_19 ;
const T_1 V_23 =
( V_24 * V_25 ) / V_26 + 2 ;
const T_1 V_27 =
V_28 * V_23 * 0x20 ;
const T_1 V_29 = ( ( 1920 * 4 ) / V_26 + 1 ) * 0x20 ;
struct V_30 * V_31 = & V_10 -> V_32 [ V_22 -> V_33 . V_34 ] ;
struct V_35 * V_36 = F_3 ( V_22 , 0 ) ;
unsigned V_12 ;
int V_37 ;
V_12 = V_10 -> V_13 * V_10 -> V_14 ;
if ( F_4 ( V_22 , 0 ) < V_12 ) {
F_5 ( L_1 ,
F_4 ( V_22 , 0 ) , V_12 ) ;
return - V_18 ;
}
if ( V_31 -> V_38 == NULL ) {
V_31 -> V_39 = & V_19 -> V_40 -> V_39 ;
F_6 ( V_31 ,
V_10 -> V_41 ? V_29 : V_27 ) ;
if ( V_31 -> V_38 == NULL )
return - V_42 ;
}
V_37 = F_7 ( V_19 , V_36 -> V_43 ,
! V_10 -> V_44 , V_36 -> V_45 , V_12 ,
V_10 -> V_46 * V_10 -> V_47 , V_10 -> V_13 , V_31 ) ;
if ( V_37 )
F_8 ( V_31 ) ;
return V_37 ;
}
static void F_9 ( struct V_21 * V_22 )
{
struct V_9 * V_10 = V_22 -> V_1 -> V_11 ;
struct V_30 * V_31 = & V_10 -> V_32 [ V_22 -> V_33 . V_34 ] ;
F_8 ( V_31 ) ;
}
static int F_10 ( struct V_21 * V_22 )
{
struct V_9 * V_10 = V_22 -> V_1 -> V_11 ;
F_11 ( V_22 , 0 , V_10 -> V_13 * V_10 -> V_14 ) ;
V_22 -> V_33 . V_48 = V_49 ;
return 0 ;
}
static void F_12 ( struct V_9 * V_10 )
{
struct V_30 * V_31 [ V_15 ] ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
int V_54 = 0 ;
F_13 (p, &s->bufs) {
V_51 = F_14 ( V_53 , struct V_50 , V_55 ) ;
V_31 [ V_54 ] = & V_10 -> V_32 [ V_51 -> V_22 . V_33 . V_34 ] ;
if ( V_54 > 0 )
F_15 ( V_31 [ V_54 - 1 ] , V_31 [ V_54 ] ) ;
V_54 ++ ;
}
}
static void F_16 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_1 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_50 * V_51 = F_17 ( V_22 ) ;
struct V_30 * V_31 = & V_10 -> V_32 [ V_22 -> V_33 . V_34 ] ;
unsigned long V_56 ;
F_18 ( V_31 ) ;
F_19 ( V_31 ) ;
F_20 ( & V_10 -> V_57 , V_56 ) ;
F_21 ( & V_51 -> V_55 , & V_10 -> V_58 ) ;
F_12 ( V_10 ) ;
F_22 ( & V_10 -> V_57 , V_56 ) ;
}
static void F_23 ( struct V_9 * V_10 )
{
struct V_19 * V_19 = V_10 -> V_19 ;
struct V_59 * V_60 = & V_10 -> V_61 . V_60 ;
struct V_62 T_2 * V_63 =
F_24 ( V_19 ) ;
unsigned V_4 = V_10 -> V_64 != V_65 ?
V_66 : 0 ;
struct V_67 V_68 = {
. V_69 = V_70 ,
} ;
if ( ! F_25 ( V_19 , V_60 -> V_71 ) ) {
F_26 ( L_2 ) ;
return;
}
V_68 . V_72 . V_73 = V_10 -> V_73 ;
V_68 . V_72 . V_74 = V_10 -> V_74 ;
V_68 . V_72 . V_75 = V_10 -> V_75 ;
V_68 . V_72 . V_76 = V_10 -> V_76 ;
V_68 . V_72 . V_46 = V_60 -> V_46 ;
V_68 . V_72 . V_14 = V_60 -> V_14 ;
switch ( V_10 -> V_64 ) {
case V_77 :
V_68 . V_72 . V_78 = V_79 ;
break;
case V_65 :
V_68 . V_72 . V_78 = V_80 ;
break;
}
F_27 ( V_10 -> V_81 , V_82 , V_83 , NULL , & V_68 ) ;
F_28 ( 0 , & V_63 -> V_84 ) ;
F_28 ( V_60 -> V_85 , & V_63 -> V_86 ) ;
F_28 ( V_60 -> V_87 , & V_63 -> V_88 ) ;
F_28 ( V_60 -> V_46 , & V_63 -> V_89 ) ;
F_28 ( V_60 -> V_90 , & V_63 -> V_91 ) ;
F_28 ( V_60 -> V_92 , & V_63 -> V_93 ) ;
F_28 ( V_60 -> V_94 , & V_63 -> V_95 ) ;
F_28 ( V_60 -> V_14 , & V_63 -> V_96 ) ;
F_28 ( V_60 -> V_97 , & V_63 -> V_98 ) ;
F_28 ( 0x9900c1 , & V_63 -> V_99 ) ;
F_28 ( V_100 | V_4 ,
& V_63 -> V_84 ) ;
F_28 ( V_101 | V_4 , & V_63 -> V_84 ) ;
F_28 ( V_102 |
V_103 |
V_4 , & V_63 -> V_84 ) ;
}
static void F_29 ( struct V_9 * V_10 )
{
struct V_19 * V_19 = V_10 -> V_19 ;
int V_104 = ( int ) V_10 -> V_105 ;
struct V_106 T_2 * V_107 ;
struct V_67 V_108 = {
. V_82 = V_10 -> V_109 ,
. V_69 = V_70 ,
. V_72 . V_78 = V_110 ,
} ;
struct V_67 V_111 = {
. V_82 = V_10 -> V_109 ,
. V_69 = V_70 ,
. V_72 . V_78 = V_80 ,
} ;
F_30 ( 1 , L_3 ,
V_10 -> V_105 ,
V_10 -> V_112 == 0 ? L_4 : L_5 ,
L_6 ) ;
V_107 = F_31 ( V_19 , V_104 ) ;
switch ( V_10 -> V_64 ) {
case V_77 :
F_28 ( V_113 |
( 1 << V_114 ) ,
& V_107 -> V_84 ) ;
F_27 ( V_10 -> V_81 , V_82 , V_83 , NULL ,
& V_108 ) ;
break;
case V_115 :
F_28 ( V_113 |
( 2 << V_114 ) ,
& V_107 -> V_84 ) ;
F_27 ( V_10 -> V_81 , V_82 , V_83 , NULL ,
& V_111 ) ;
break;
case V_65 :
F_28 ( V_113 |
V_116 |
( 3 << V_114 ) ,
& V_107 -> V_84 ) ;
F_27 ( V_10 -> V_81 , V_82 , V_83 , NULL ,
& V_111 ) ;
break;
}
}
static void F_32 ( struct V_9 * V_10 )
{
struct V_19 * V_19 = V_10 -> V_19 ;
int V_117 = V_10 -> V_105 ;
struct V_118 T_2 * V_119 =
F_33 ( V_19 , V_117 ) ;
struct V_50 * V_51 ;
unsigned long V_56 ;
F_20 ( & V_10 -> V_57 , V_56 ) ;
if ( ! V_10 -> V_44 ) {
F_28 ( V_120 , & V_119 -> V_84 ) ;
F_28 ( V_121 , & V_119 -> V_84 ) ;
} else {
struct V_62 T_2 * V_63 =
F_24 ( V_19 ) ;
T_3 V_122 = F_34 ( & V_63 -> V_84 ) ;
V_122 &= ~ ( V_123 |
V_101 ) ;
F_28 ( V_122 | V_101 ,
& V_63 -> V_84 ) ;
F_28 ( V_122 | V_123 ,
& V_63 -> V_84 ) ;
}
V_51 = F_35 ( & V_10 -> V_58 , struct V_50 , V_55 ) ;
F_36 ( V_10 , & V_10 -> V_32 [ V_51 -> V_22 . V_33 . V_34 ] ) ;
F_22 ( & V_10 -> V_57 , V_56 ) ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int V_124 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_19 * V_19 = V_10 -> V_19 ;
struct V_125 T_2 * V_126 ;
struct V_127 T_2 * V_128 ;
struct V_129 T_2 * V_130 ;
int V_117 = V_10 -> V_105 ;
struct V_131 T_2 * V_132 = F_38 ( V_19 , V_117 ) ;
struct V_118 T_2 * V_119 = F_33 ( V_19 , V_117 ) ;
struct V_59 * V_60 = & V_10 -> V_61 . V_60 ;
T_4 V_133 ;
T_3 V_134 ;
if ( V_10 -> V_41 )
goto V_135;
if ( V_10 -> V_44 ) {
V_10 -> V_136 = false ;
F_23 ( V_10 ) ;
goto V_135;
}
F_29 ( V_10 ) ;
V_128 = F_39 ( V_19 , V_117 ) ;
V_126 = F_40 ( V_19 , V_117 ) ;
V_130 = F_41 ( V_19 , V_117 ) ;
F_28 ( V_120 , & V_119 -> V_84 ) ;
F_28 ( V_121 , & V_119 -> V_84 ) ;
F_28 ( V_60 -> V_46 , & V_132 -> V_137 ) ;
F_28 ( V_60 -> V_14 , & V_132 -> V_138 ) ;
V_133 = F_42 ( V_60 ) * F_43 ( V_60 ) ;
F_28 ( F_44 ( ( T_4 ) F_42 ( V_60 ) * V_139 * 4 ,
V_60 -> V_71 ) , & V_126 -> V_140 ) ;
F_28 ( V_141 , & V_126 -> V_84 ) ;
V_134 = F_34 ( & V_128 -> V_134 ) ;
F_28 ( V_134 / 1000000 , & V_130 -> V_142 ) ;
F_28 ( F_44 ( V_60 -> V_71 * 995 , 1000000000 ) ,
& V_130 -> V_143 ) ;
F_28 ( V_60 -> V_46 * V_60 -> V_14 , & V_128 -> V_144 ) ;
F_28 ( F_44 ( ( T_4 ) V_134 * V_133 , V_60 -> V_71 ) ,
& V_128 -> V_145 ) ;
F_28 ( V_146 |
V_147 ,
& V_126 -> V_148 ) ;
F_28 ( 0 , & V_132 -> V_84 ) ;
F_28 ( V_141 , & V_126 -> V_84 ) ;
F_28 ( 0xff , & V_128 -> V_149 ) ;
F_28 ( V_150 , & V_130 -> V_122 ) ;
F_28 ( V_151 |
V_152 , & V_128 -> V_122 ) ;
V_10 -> V_136 = true ;
V_10 -> V_153 = false ;
V_10 -> V_154 = false ;
V_10 -> V_155 = 0 ;
V_135:
V_10 -> V_156 = 0 ;
F_32 ( V_10 ) ;
return 0 ;
}
static void F_45 ( struct V_9 * V_10 )
{
struct V_19 * V_19 = V_10 -> V_19 ;
struct V_30 * V_31 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
unsigned long V_56 ;
int V_157 = 100 ;
int V_117 = V_10 -> V_105 ;
struct V_118 T_2 * V_119 =
F_33 ( V_19 , V_117 ) ;
if ( ! V_10 -> V_44 ) {
F_28 ( 0 , & V_119 -> V_84 ) ;
} else if ( ! V_10 -> V_41 ) {
struct V_62 T_2 * V_63 =
F_24 ( V_19 ) ;
F_28 ( V_101 , & V_63 -> V_84 ) ;
F_28 ( 0 , & V_63 -> V_84 ) ;
}
F_20 ( & V_10 -> V_57 , V_56 ) ;
F_13 (p, &s->bufs) {
V_51 = F_14 ( V_53 , struct V_50 , V_55 ) ;
V_31 = & V_10 -> V_32 [ V_51 -> V_22 . V_33 . V_34 ] ;
F_46 ( V_31 ) ;
}
F_22 ( & V_10 -> V_57 , V_56 ) ;
if ( ! F_47 ( V_10 -> V_2 . V_158 , F_48 ( V_10 ) ,
F_49 ( V_157 ) ) ) {
F_50 ( V_10 ) ;
F_51 ( L_7 ) ;
}
F_52 ( V_19 , V_159 ,
1 << V_10 -> V_160 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_19 * V_19 = V_10 -> V_19 ;
int V_117 = V_10 -> V_105 ;
struct V_125 T_2 * V_126 ;
struct V_127 T_2 * V_128 ;
struct V_129 T_2 * V_130 ;
struct V_50 * V_51 ;
struct V_52 * V_53 , * V_161 ;
unsigned long V_56 ;
F_45 ( V_10 ) ;
F_20 ( & V_10 -> V_57 , V_56 ) ;
F_54 (p, safe, &s->bufs) {
V_51 = F_14 ( V_53 , struct V_50 , V_55 ) ;
F_55 ( & V_51 -> V_55 ) ;
F_56 ( & V_51 -> V_22 , V_162 ) ;
}
F_22 ( & V_10 -> V_57 , V_56 ) ;
if ( V_10 -> V_41 || V_10 -> V_44 )
return;
V_128 = F_39 ( V_19 , V_117 ) ;
V_126 = F_40 ( V_19 , V_117 ) ;
V_130 = F_41 ( V_19 , V_117 ) ;
F_28 ( 0 , & V_126 -> V_84 ) ;
F_28 ( V_141 , & V_126 -> V_84 ) ;
F_28 ( 0 , & V_128 -> V_122 ) ;
F_28 ( 0 , & V_130 -> V_122 ) ;
}
static int F_57 ( struct V_19 * V_19 , unsigned int V_163 , void * V_164 )
{
struct V_165 * V_166 = V_164 ;
void T_2 * V_167 = V_19 -> V_168 + V_166 -> V_169 ;
F_5 ( L_8 , V_167 ) ;
if ( ! F_58 ( V_170 ) )
return - V_171 ;
V_166 -> V_12 = 4 ;
if ( V_163 == V_172 )
F_28 ( V_166 -> V_173 , V_167 ) ;
else
V_166 -> V_173 = F_34 ( V_167 ) ;
return 0 ;
}
static int F_59 ( struct V_174 * V_174 , void * V_175 ,
struct V_165 * V_169 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
struct V_19 * V_19 = V_10 -> V_19 ;
return F_57 ( V_19 , V_176 , V_169 ) ;
}
static int F_61 ( struct V_174 * V_174 , void * V_175 ,
const struct V_165 * V_169 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
struct V_19 * V_19 = V_10 -> V_19 ;
return F_57 ( V_19 , V_172 ,
(struct V_165 * ) V_169 ) ;
}
static int F_62 ( struct V_174 * V_174 , void * V_175 ,
struct V_177 * V_178 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
struct V_19 * V_19 = V_10 -> V_19 ;
F_63 ( V_178 -> V_179 , L_9 , sizeof( V_178 -> V_179 ) ) ;
F_63 ( V_178 -> V_180 , L_9 , sizeof( V_178 -> V_180 ) ) ;
snprintf ( V_178 -> V_181 , sizeof( V_178 -> V_181 ) ,
L_10 , F_64 ( V_19 -> V_40 ) ) ;
V_178 -> V_182 = V_183 | V_184 ;
if ( V_10 -> V_44 )
V_178 -> V_182 |= V_185 ;
else
V_178 -> V_182 |= V_186 ;
V_178 -> V_187 = V_178 -> V_182 | V_188 |
V_186 ;
if ( V_19 -> V_189 )
V_178 -> V_187 |= V_185 ;
return 0 ;
}
static void F_65 ( struct V_9 * V_10 )
{
struct V_131 T_2 * V_132 ;
struct V_125 T_2 * V_126 ;
struct V_127 T_2 * V_128 ;
struct V_129 T_2 * V_130 ;
struct V_106 T_2 * V_107 ;
int V_117 = V_10 -> V_105 ;
struct V_19 * V_19 = V_10 -> V_19 ;
T_3 V_190 , V_191 ;
T_3 V_192 , V_193 ;
V_132 = F_38 ( V_19 , V_117 ) ;
V_126 = F_40 ( V_19 , V_117 ) ;
V_128 = F_39 ( V_19 , V_117 ) ;
V_130 = F_41 ( V_19 , V_117 ) ;
V_107 = F_31 ( V_19 , V_117 ) ;
V_190 = F_34 ( & V_132 -> V_84 ) ;
V_191 = F_34 ( & V_132 -> V_194 ) ;
V_192 = F_34 ( & V_126 -> V_84 ) ;
V_193 = F_34 ( & V_126 -> V_84 ) ;
F_5 ( L_11 , V_117 ,
F_34 ( & V_132 -> V_137 ) , F_34 ( & V_132 -> V_138 ) ) ;
F_5 ( L_12 , V_117 ,
( V_190 & V_195 ) ?
L_13 : L_14 ,
( V_190 & V_196 ) ?
L_15 : L_16 ,
( V_190 & V_197 ) ?
L_17 : L_18 ) ;
F_5 ( L_19 , V_117 ,
( V_191 & V_198 ) ?
L_20 : L_21 ,
( V_191 & V_199 ) ?
L_22 : L_23 ) ;
F_5 ( L_24 , V_117 ,
( V_192 & V_200 ) ?
L_15 : L_16 ,
( V_192 & V_201 ) ?
L_17 : L_18 ,
( V_192 & V_141 ) ?
L_25 : L_26 ,
( V_192 & V_202 ) ?
L_27 : L_28 ,
( V_192 & V_203 ) ?
L_29 : L_30 ,
( V_193 & V_204 ) ?
L_31 : L_30 ,
( V_193 & V_205 ) ?
L_32 : L_30 ) ;
F_5 ( L_33 , V_117 ,
F_34 ( & V_126 -> V_206 ) & 0xff ,
F_34 ( & V_126 -> V_148 ) & 0xff ) ;
F_5 ( L_34 , V_117 , F_34 ( & V_126 -> V_207 ) ) ;
F_5 ( L_35 , V_117 , F_34 ( & V_126 -> V_208 ) ) ;
F_5 ( L_36 , V_117 , F_34 ( & V_126 -> V_209 ) ) ;
F_5 ( L_37 , V_117 , F_34 ( & V_126 -> V_210 ) ) ;
F_5 ( L_38 , V_117 , F_34 ( & V_126 -> V_211 ) ) ;
F_5 ( L_39 , V_117 , F_34 ( & V_126 -> V_212 ) ) ;
F_5 ( L_40 , V_117 , F_34 ( & V_126 -> V_213 ) ) ;
F_5 ( L_41 , V_117 , F_34 ( & V_126 -> V_214 ) ) ;
F_5 ( L_42 , V_117 ,
( F_34 ( & V_128 -> V_122 ) & V_151 ) ?
L_25 : L_26 ,
( F_34 ( & V_128 -> V_122 ) & V_152 ) ?
L_43 : L_30 ,
( F_34 ( & V_128 -> V_194 ) & V_215 ) ?
L_44 : L_45 ) ;
F_28 ( 0xff , & V_126 -> V_206 ) ;
F_5 ( L_46 , V_117 ,
( F_34 ( & V_130 -> V_122 ) & V_150 ) ?
L_25 : L_26 ,
( F_34 ( & V_130 -> V_194 ) & V_216 ) ?
L_47 : L_48 ) ;
F_5 ( L_49 , V_117 , F_34 ( & V_107 -> V_84 ) ) ;
}
static int F_66 ( struct V_174 * V_174 , void * V_175 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
struct V_19 * V_19 = V_10 -> V_19 ;
struct V_62 T_2 * V_63 =
F_24 ( V_19 ) ;
T_5 V_217 ;
F_5 ( L_50 , V_19 -> V_218 ) ;
F_5 ( L_51 ,
F_67 ( V_19 ) ,
F_68 ( V_19 ) ) ;
F_5 ( L_52 ,
V_10 -> V_160 , V_10 -> V_105 ) ;
F_69 ( V_19 ) ;
F_70 ( V_19 ) ;
F_71 ( V_19 ) ;
F_27 ( V_10 -> V_81 , V_219 , V_220 ) ;
if ( ! V_10 -> V_44 ) {
F_65 ( V_10 ) ;
return 0 ;
}
V_217 = F_34 ( & V_63 -> V_221 ) ;
F_5 ( L_53 ,
( V_217 & V_222 ) ?
L_54 : L_30 ,
( V_217 & V_223 ) ?
L_55 : L_30 ) ;
F_5 ( L_56 , F_34 ( & V_63 -> V_224 ) ) ;
return 0 ;
}
static int F_72 ( struct V_174 * V_174 , void * V_175 ,
struct V_225 * V_61 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
if ( V_10 -> V_112 == 1 ) {
if ( V_61 -> V_34 )
return - V_18 ;
memset ( V_61 -> V_226 , 0 , sizeof( V_61 -> V_226 ) ) ;
V_61 -> V_61 = V_227 ;
return 0 ;
}
V_61 -> V_82 = 0 ;
return F_27 ( V_10 -> V_81 ,
V_82 , V_228 , V_61 ) ;
}
static int F_73 ( struct V_174 * V_174 , void * V_175 ,
struct V_229 * V_61 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
int V_230 ;
if ( F_74 ( & V_10 -> V_2 ) )
return - V_231 ;
if ( V_10 -> V_112 == 1 ) {
* V_61 = V_227 ;
return 0 ;
}
V_230 = F_27 ( V_10 -> V_81 ,
V_232 , V_233 , V_61 ) ;
if ( ! V_230 ) {
V_10 -> V_61 = * V_61 ;
V_10 -> V_46 = V_61 -> V_60 . V_46 ;
V_10 -> V_14 = V_61 -> V_60 . V_14 ;
V_10 -> V_13 = V_61 -> V_60 . V_46 * V_10 -> V_47 ;
}
return V_230 ;
}
static int F_75 ( struct V_174 * V_174 , void * V_175 ,
struct V_229 * V_61 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
if ( V_10 -> V_112 == 1 ) {
* V_61 = V_227 ;
return 0 ;
}
return F_27 ( V_10 -> V_81 ,
V_232 , V_234 , V_61 ) ;
}
static int F_76 ( struct V_174 * V_174 , void * V_175 ,
struct V_229 * V_61 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
if ( V_10 -> V_112 == 1 ) {
* V_61 = V_227 ;
return 0 ;
}
return F_27 ( V_10 -> V_81 ,
V_232 , V_235 , V_61 ) ;
}
static int F_77 ( struct V_174 * V_174 , void * V_175 ,
struct V_236 * V_237 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
V_237 -> V_82 = 0 ;
return F_27 ( V_10 -> V_81 ,
V_82 , V_238 , V_237 ) ;
}
static int F_78 ( struct V_174 * V_174 , void * V_175 ,
struct V_239 * V_240 )
{
switch ( V_240 -> V_34 ) {
case 0 :
F_63 ( V_240 -> V_241 , L_57 , sizeof( V_240 -> V_241 ) ) ;
V_240 -> V_242 = V_77 ;
break;
case 1 :
F_63 ( V_240 -> V_241 , L_58 , sizeof( V_240 -> V_241 ) ) ;
V_240 -> V_242 = V_115 ;
break;
case 2 :
F_63 ( V_240 -> V_241 , L_59 , sizeof( V_240 -> V_241 ) ) ;
V_240 -> V_242 = V_65 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_79 ( struct V_174 * V_174 , void * V_175 ,
struct V_3 * V_240 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
struct V_243 * V_16 = & V_240 -> V_4 . V_16 ;
struct V_67 V_68 ;
V_16 -> V_46 = V_10 -> V_46 ;
V_16 -> V_14 = V_10 -> V_14 ;
V_16 -> V_244 = V_10 -> V_13 ;
V_16 -> V_48 = V_49 ;
if ( V_10 -> V_112 == 1 ) {
V_16 -> V_73 = V_245 ;
} else {
V_68 . V_82 = V_10 -> V_109 ;
V_68 . V_69 = V_70 ;
F_27 ( V_10 -> V_81 , V_82 , V_246 , NULL , & V_68 ) ;
F_80 ( V_16 , & V_68 . V_72 ) ;
}
V_16 -> V_242 = V_10 -> V_64 ;
V_16 -> V_17 = V_16 -> V_244 * V_16 -> V_14 ;
return 0 ;
}
static int F_81 ( struct V_174 * V_174 , void * V_175 ,
struct V_3 * V_240 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
struct V_243 * V_16 = & V_240 -> V_4 . V_16 ;
struct V_67 V_68 ;
if ( ( V_16 -> V_46 < 176 ) || ( V_16 -> V_14 < 144 ) ) {
V_16 -> V_46 = 176 ;
V_16 -> V_14 = 144 ;
}
if ( ( V_16 -> V_46 > 1920 ) || ( V_16 -> V_14 > 1080 ) ) {
V_16 -> V_46 = 1920 ;
V_16 -> V_14 = 1080 ;
}
V_16 -> V_46 &= ~ 0x3 ;
V_16 -> V_14 &= ~ 0x1 ;
if ( V_10 -> V_112 == 1 ) {
V_16 -> V_46 = 1920 ;
V_16 -> V_14 = 1080 ;
V_16 -> V_73 = V_245 ;
} else {
V_68 . V_82 = V_10 -> V_109 ;
V_68 . V_69 = V_70 ;
F_27 ( V_10 -> V_81 , V_82 , V_246 , NULL , & V_68 ) ;
F_80 ( V_16 , & V_68 . V_72 ) ;
}
switch ( V_16 -> V_242 ) {
case V_77 :
default:
V_16 -> V_244 = F_82 ( V_16 -> V_244 & ~ 0x3 ,
V_16 -> V_46 * V_247 ) ;
V_16 -> V_242 = V_77 ;
break;
case V_115 :
V_16 -> V_244 = F_82 ( V_16 -> V_244 & ~ 0x3 ,
V_16 -> V_46 * V_248 ) ;
break;
case V_65 :
V_16 -> V_244 = F_82 ( V_16 -> V_244 & ~ 0x3 ,
V_16 -> V_46 * V_249 ) ;
break;
}
V_16 -> V_17 = V_16 -> V_244 * V_16 -> V_14 ;
V_16 -> V_48 = V_49 ;
V_16 -> V_250 = 0 ;
return 0 ;
}
static int F_83 ( struct V_174 * V_174 , void * V_175 ,
struct V_3 * V_240 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
struct V_243 * V_16 = & V_240 -> V_4 . V_16 ;
if ( F_74 ( & V_10 -> V_2 ) )
return - V_231 ;
if ( F_81 ( V_174 , V_175 , V_240 ) )
return - V_18 ;
V_10 -> V_46 = V_16 -> V_46 ;
V_10 -> V_14 = V_16 -> V_14 ;
V_10 -> V_13 = V_16 -> V_244 ;
switch ( V_16 -> V_242 ) {
case V_77 :
V_10 -> V_47 = V_247 ;
break;
case V_115 :
V_10 -> V_47 = V_248 ;
break;
case V_65 :
V_10 -> V_47 = V_249 ;
break;
default:
return - V_18 ;
}
V_10 -> V_64 = V_16 -> V_242 ;
F_29 ( V_10 ) ;
return 0 ;
}
static int F_84 ( struct V_174 * V_174 , void * V_175 ,
struct V_3 * V_240 )
{
struct V_243 * V_16 = & V_240 -> V_4 . V_16 ;
if ( ( V_16 -> V_46 < 176 ) || ( V_16 -> V_14 < 144 ) ) {
V_16 -> V_46 = 176 ;
V_16 -> V_14 = 144 ;
}
if ( ( V_16 -> V_46 > 1920 ) || ( V_16 -> V_14 > 1080 ) ) {
V_16 -> V_46 = 1920 ;
V_16 -> V_14 = 1080 ;
}
V_16 -> V_46 &= ~ 0x3 ;
V_16 -> V_14 &= ~ 0x1 ;
switch ( V_16 -> V_242 ) {
case V_77 :
default:
V_16 -> V_244 = F_82 ( V_16 -> V_244 & ~ 0x3 ,
V_16 -> V_46 * V_247 ) ;
V_16 -> V_242 = V_77 ;
break;
case V_65 :
V_16 -> V_244 = F_82 ( V_16 -> V_244 & ~ 0x3 ,
V_16 -> V_46 * V_249 ) ;
break;
}
V_16 -> V_17 = V_16 -> V_244 * V_16 -> V_14 ;
V_16 -> V_48 = V_49 ;
return 0 ;
}
static int F_85 ( struct V_174 * V_174 , void * V_175 ,
struct V_3 * V_240 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
struct V_243 * V_16 = & V_240 -> V_4 . V_16 ;
V_16 -> V_46 = V_10 -> V_46 ;
V_16 -> V_14 = V_10 -> V_14 ;
V_16 -> V_244 = V_10 -> V_13 ;
V_16 -> V_48 = V_49 ;
V_16 -> V_242 = V_10 -> V_64 ;
V_16 -> V_73 = V_10 -> V_73 ;
V_16 -> V_74 = V_10 -> V_74 ;
V_16 -> V_75 = V_10 -> V_75 ;
V_16 -> V_76 = V_10 -> V_76 ;
V_16 -> V_17 = V_16 -> V_244 * V_16 -> V_14 ;
return 0 ;
}
static int F_86 ( struct V_174 * V_174 , void * V_175 ,
struct V_239 * V_240 )
{
switch ( V_240 -> V_34 ) {
case 0 :
F_63 ( V_240 -> V_241 , L_57 , sizeof( V_240 -> V_241 ) ) ;
V_240 -> V_242 = V_77 ;
break;
case 1 :
F_63 ( V_240 -> V_241 , L_59 , sizeof( V_240 -> V_241 ) ) ;
V_240 -> V_242 = V_65 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_87 ( struct V_174 * V_174 , void * V_175 ,
struct V_3 * V_240 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
struct V_243 * V_16 = & V_240 -> V_4 . V_16 ;
struct V_67 V_68 = { 0 } ;
T_3 V_78 ;
if ( F_84 ( V_174 , V_175 , V_240 ) )
return - V_18 ;
if ( F_74 ( & V_10 -> V_2 ) && ( V_16 -> V_242 != V_10 -> V_64 ||
V_16 -> V_46 != V_10 -> V_46 || V_16 -> V_14 != V_10 -> V_14 ||
V_16 -> V_244 != V_10 -> V_13 ) )
return - V_231 ;
switch ( V_16 -> V_242 ) {
case V_77 :
V_10 -> V_47 = V_247 ;
V_78 = V_79 ;
break;
case V_65 :
V_10 -> V_47 = V_249 ;
V_78 = V_80 ;
break;
default:
return - V_18 ;
}
V_10 -> V_46 = V_16 -> V_46 ;
V_10 -> V_14 = V_16 -> V_14 ;
V_10 -> V_13 = V_16 -> V_244 ;
V_10 -> V_64 = V_16 -> V_242 ;
V_10 -> V_73 = V_16 -> V_73 ;
V_10 -> V_74 = V_16 -> V_74 ;
V_10 -> V_75 = V_16 -> V_75 ;
V_10 -> V_76 = V_16 -> V_76 ;
V_68 . V_69 = V_70 ;
F_88 ( & V_68 . V_72 , V_16 , V_78 ) ;
F_27 ( V_10 -> V_81 , V_82 , V_83 , NULL , & V_68 ) ;
return 0 ;
}
static int F_89 ( struct V_174 * V_174 , void * V_175 ,
struct V_251 * V_252 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
if ( V_252 -> V_34 > 1 )
return - V_18 ;
if ( V_252 -> V_34 == 0 )
snprintf ( V_252 -> V_253 , sizeof( V_252 -> V_253 ) ,
L_60 , V_10 -> V_105 ) ;
else
snprintf ( V_252 -> V_253 , sizeof( V_252 -> V_253 ) ,
L_61 , V_10 -> V_105 ) ;
V_252 -> type = V_254 ;
V_252 -> V_187 = V_255 ;
if ( V_252 -> V_34 == 1 )
return 0 ;
return F_27 ( V_10 -> V_81 ,
V_232 , V_256 , & V_252 -> V_194 ) ;
}
static int F_90 ( struct V_174 * V_174 , void * V_175 , unsigned int * V_54 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
* V_54 = V_10 -> V_112 ;
return 0 ;
}
static int F_91 ( struct V_174 * V_174 , void * V_175 , unsigned int V_54 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
if ( V_54 >= 2 )
return - V_18 ;
if ( F_74 ( & V_10 -> V_2 ) )
return - V_231 ;
V_10 -> V_112 = V_54 ;
F_29 ( V_10 ) ;
if ( V_10 -> V_112 == 1 )
return 0 ;
return F_27 ( V_10 -> V_81 , V_232 , V_257 ,
V_258 , 0 , 0 ) ;
}
static int F_92 ( struct V_174 * V_174 , void * V_175 ,
struct V_259 * V_260 )
{
if ( V_260 -> V_34 )
return - V_18 ;
snprintf ( V_260 -> V_253 , sizeof( V_260 -> V_253 ) , L_60 , V_260 -> V_34 ) ;
V_260 -> type = V_261 ;
V_260 -> V_187 = V_262 ;
return 0 ;
}
static int F_93 ( struct V_174 * V_174 , void * V_175 , unsigned int * V_54 )
{
* V_54 = 0 ;
return 0 ;
}
static int F_94 ( struct V_174 * V_174 , void * V_175 , unsigned int V_54 )
{
return V_54 ? - V_18 : 0 ;
}
static int F_95 ( struct V_174 * V_174 , void * V_263 , struct V_264 * V_265 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
T_3 V_82 = V_265 -> V_82 ;
int V_37 ;
if ( V_265 -> V_82 >= ( V_10 -> V_44 ? 1 : 2 ) )
return - V_18 ;
V_265 -> V_82 = 0 ;
V_37 = F_27 ( V_10 -> V_81 , V_82 , V_266 , V_265 ) ;
V_265 -> V_82 = V_82 ;
return V_37 ;
}
static int F_96 ( struct V_174 * V_174 , void * V_263 , struct V_264 * V_265 )
{
struct V_9 * V_10 = F_60 ( V_174 ) ;
T_3 V_82 = V_265 -> V_82 ;
int V_37 ;
if ( V_265 -> V_82 >= 2 )
return - V_18 ;
V_265 -> V_82 = 0 ;
V_37 = F_27 ( V_10 -> V_81 , V_82 , V_267 , V_265 ) ;
V_265 -> V_82 = V_82 ;
return V_37 ;
}
static int F_97 ( struct V_268 * V_263 ,
const struct V_269 * V_270 )
{
switch ( V_270 -> type ) {
case V_271 :
return F_98 ( V_263 , V_270 , 4 , NULL ) ;
}
return F_99 ( V_263 , V_270 ) ;
}
static int F_100 ( struct V_174 * V_174 , void * V_263 , struct V_272 * V_273 )
{
if ( V_273 -> type != V_274 )
return - V_18 ;
V_273 -> V_275 . V_276 . V_277 . V_278 = 1 ;
V_273 -> V_275 . V_276 . V_277 . V_279 = 60 ;
V_273 -> V_275 . V_276 . V_280 = 3 ;
return 0 ;
}
static int F_101 ( struct V_19 * V_19 , int V_281 )
{
static const struct V_229 V_282 =
V_283 ;
struct V_9 * V_10 = V_19 -> V_284 + V_281 ;
struct V_285 * V_286 = & V_10 -> V_286 ;
struct V_1 * V_2 = & V_10 -> V_2 ;
int V_37 ;
F_102 ( & V_10 -> V_287 ) ;
F_103 ( & V_10 -> V_57 ) ;
snprintf ( V_286 -> V_253 , sizeof( V_286 -> V_253 ) ,
L_62 , V_19 -> V_288 . V_253 , V_281 ) ;
V_10 -> V_46 = 1920 ;
V_10 -> V_14 = V_10 -> V_41 ? 4 : 1080 ;
if ( V_10 -> V_41 ) {
V_10 -> V_47 = 1 ;
V_10 -> V_64 = V_289 ;
} else if ( V_10 -> V_44 ) {
V_10 -> V_47 = V_249 ;
V_10 -> V_64 = V_65 ;
} else {
V_10 -> V_47 = V_247 ;
V_10 -> V_64 = V_77 ;
}
V_10 -> V_73 = V_245 ;
V_10 -> V_13 = V_10 -> V_46 * V_10 -> V_47 ;
if ( ! V_10 -> V_41 ) {
if ( V_10 -> V_290 )
F_104 ( L_63 , V_281 ) ;
V_286 -> V_288 = & V_19 -> V_288 ;
if ( V_10 -> V_290 )
V_286 -> V_291 = & V_292 ;
else
V_286 -> V_291 = V_10 -> V_44 ? & V_293 :
& V_294 ;
V_286 -> V_295 = V_296 ;
V_286 -> V_297 = V_10 -> V_44 ? V_298 : V_299 ;
V_286 -> V_287 = & V_10 -> V_287 ;
if ( V_10 -> V_81 )
V_286 -> V_300 = V_10 -> V_81 -> V_300 ;
V_10 -> V_61 = V_282 ;
F_27 ( V_10 -> V_81 , V_232 , V_233 , & V_10 -> V_61 ) ;
if ( ! V_10 -> V_44 && V_10 -> V_81 )
F_29 ( V_10 ) ;
V_286 -> V_301 = V_10 -> V_290 ? & V_302 :
& V_303 ;
}
F_105 ( & V_10 -> V_58 ) ;
V_2 -> type = V_10 -> V_44 ? V_304 :
V_274 ;
V_2 -> V_305 = V_306 | V_307 | V_308 ;
V_2 -> V_305 |= V_10 -> V_44 ? V_309 : V_310 ;
V_2 -> V_11 = V_10 ;
V_2 -> V_311 = sizeof( struct V_50 ) ;
V_2 -> V_312 = & V_313 ;
V_2 -> V_314 = & V_315 ;
V_2 -> V_316 = V_317 ;
V_2 -> V_318 = 2 ;
V_2 -> V_287 = & V_10 -> V_287 ;
V_286 -> V_319 = V_2 ;
F_106 ( V_286 , V_10 ) ;
V_37 = F_107 ( V_2 ) ;
if ( ! V_10 -> V_41 && V_37 == 0 )
V_37 = F_108 ( V_286 , V_320 , - 1 ) ;
else if ( ! V_10 -> V_290 )
V_37 = F_109 ( V_10 ) ;
if ( V_37 < 0 ) {
if ( ! V_10 -> V_41 )
F_26 ( L_64 ,
V_281 ) ;
return V_37 ;
}
F_5 ( L_65 , V_281 ) ;
return 0 ;
}
int F_110 ( struct V_19 * V_19 )
{
int V_281 , V_37 ;
for ( V_281 = 0 ; V_281 < V_321 ; V_281 ++ ) {
V_37 = F_101 ( V_19 , V_281 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
void F_111 ( struct V_19 * V_19 )
{
int V_281 ;
for ( V_281 = 0 ; V_281 < V_321 ; V_281 ++ ) {
struct V_9 * V_10 = V_19 -> V_284 + V_281 ;
struct V_285 * V_286 = & V_10 -> V_286 ;
if ( ! V_10 -> V_41 )
F_112 ( V_286 ) ;
else if ( ! V_10 -> V_290 )
F_113 ( V_10 ) ;
}
}
