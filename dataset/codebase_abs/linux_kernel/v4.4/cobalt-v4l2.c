static int F_1 ( struct V_1 * V_2 , const void * V_3 ,
unsigned int * V_4 , unsigned int * V_5 ,
unsigned int V_6 [] , void * V_7 [] )
{
const struct V_8 * V_9 = V_3 ;
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned V_13 = V_11 -> V_14 * V_11 -> V_15 ;
if ( * V_4 < 3 )
* V_4 = 3 ;
if ( * V_4 > V_16 )
* V_4 = V_16 ;
* V_5 = 1 ;
if ( V_9 ) {
if ( V_9 -> V_9 . V_17 . V_18 < V_13 )
return - V_19 ;
V_13 = V_9 -> V_9 . V_17 . V_18 ;
}
V_6 [ 0 ] = V_13 ;
V_7 [ 0 ] = V_11 -> V_20 -> V_21 ;
return 0 ;
}
static int F_2 ( struct V_22 * V_23 )
{
struct V_10 * V_11 = V_23 -> V_1 -> V_12 ;
struct V_20 * V_20 = V_11 -> V_20 ;
const T_1 V_24 =
( V_25 * V_26 ) / V_27 + 2 ;
const T_1 V_28 =
V_29 * V_24 * 0x20 ;
const T_1 V_30 = ( ( 1920 * 4 ) / V_27 + 1 ) * 0x20 ;
struct V_31 * V_32 = & V_11 -> V_33 [ V_23 -> V_34 ] ;
struct V_35 * V_36 = F_3 ( V_23 , 0 ) ;
unsigned V_13 ;
int V_37 ;
V_13 = V_11 -> V_14 * V_11 -> V_15 ;
if ( F_4 ( V_23 , 0 ) < V_13 ) {
F_5 ( L_1 ,
F_4 ( V_23 , 0 ) , V_13 ) ;
return - V_19 ;
}
if ( V_32 -> V_38 == NULL ) {
V_32 -> V_39 = & V_20 -> V_40 -> V_39 ;
F_6 ( V_32 ,
V_11 -> V_41 ? V_30 : V_28 ) ;
if ( V_32 -> V_38 == NULL )
return - V_42 ;
}
V_37 = F_7 ( V_20 , V_36 -> V_43 ,
! V_11 -> V_44 , V_36 -> V_45 , V_13 ,
V_11 -> V_46 * V_11 -> V_47 , V_11 -> V_14 , V_32 ) ;
if ( V_37 )
F_8 ( V_32 ) ;
return V_37 ;
}
static void F_9 ( struct V_22 * V_23 )
{
struct V_10 * V_11 = V_23 -> V_1 -> V_12 ;
struct V_31 * V_32 = & V_11 -> V_33 [ V_23 -> V_34 ] ;
F_8 ( V_32 ) ;
}
static int F_10 ( struct V_22 * V_23 )
{
struct V_48 * V_49 = F_11 ( V_23 ) ;
struct V_10 * V_11 = V_23 -> V_1 -> V_12 ;
F_12 ( V_23 , 0 , V_11 -> V_14 * V_11 -> V_15 ) ;
V_49 -> V_50 = V_51 ;
return 0 ;
}
static void F_13 ( struct V_10 * V_11 )
{
struct V_31 * V_32 [ V_16 ] ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
int V_56 = 0 ;
F_14 (p, &s->bufs) {
V_53 = F_15 ( V_55 , struct V_52 , V_57 ) ;
V_32 [ V_56 ] = & V_11 -> V_33 [ V_53 -> V_23 . V_58 . V_34 ] ;
if ( V_56 > 0 )
F_16 ( V_32 [ V_56 - 1 ] , V_32 [ V_56 ] ) ;
V_56 ++ ;
}
}
static void F_17 ( struct V_22 * V_23 )
{
struct V_48 * V_49 = F_11 ( V_23 ) ;
struct V_1 * V_2 = V_23 -> V_1 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_52 * V_53 = F_18 ( V_49 ) ;
struct V_31 * V_32 = & V_11 -> V_33 [ V_23 -> V_34 ] ;
unsigned long V_59 ;
F_19 ( V_32 ) ;
F_20 ( V_32 ) ;
F_21 ( & V_11 -> V_60 , V_59 ) ;
F_22 ( & V_53 -> V_57 , & V_11 -> V_61 ) ;
F_13 ( V_11 ) ;
F_23 ( & V_11 -> V_60 , V_59 ) ;
}
static void F_24 ( struct V_10 * V_11 )
{
struct V_20 * V_20 = V_11 -> V_20 ;
struct V_62 * V_63 = & V_11 -> V_64 . V_63 ;
struct V_65 T_2 * V_66 =
F_25 ( V_20 ) ;
unsigned V_9 = V_11 -> V_67 != V_68 ?
V_69 : 0 ;
struct V_70 V_71 = {
. V_72 = V_73 ,
} ;
if ( ! F_26 ( V_20 , V_63 -> V_74 ) ) {
F_27 ( L_2 ) ;
return;
}
V_71 . V_75 . V_76 = V_11 -> V_76 ;
V_71 . V_75 . V_77 = V_11 -> V_77 ;
V_71 . V_75 . V_78 = V_11 -> V_78 ;
V_71 . V_75 . V_79 = V_11 -> V_79 ;
V_71 . V_75 . V_46 = V_63 -> V_46 ;
V_71 . V_75 . V_15 = V_63 -> V_15 ;
switch ( V_11 -> V_67 ) {
case V_80 :
V_71 . V_75 . V_81 = V_82 ;
break;
case V_68 :
V_71 . V_75 . V_81 = V_83 ;
break;
}
F_28 ( V_11 -> V_84 , V_85 , V_86 , NULL , & V_71 ) ;
F_29 ( 0 , & V_66 -> V_87 ) ;
F_29 ( V_63 -> V_88 , & V_66 -> V_89 ) ;
F_29 ( V_63 -> V_90 , & V_66 -> V_91 ) ;
F_29 ( V_63 -> V_46 , & V_66 -> V_92 ) ;
F_29 ( V_63 -> V_93 , & V_66 -> V_94 ) ;
F_29 ( V_63 -> V_95 , & V_66 -> V_96 ) ;
F_29 ( V_63 -> V_97 , & V_66 -> V_98 ) ;
F_29 ( V_63 -> V_15 , & V_66 -> V_99 ) ;
F_29 ( V_63 -> V_100 , & V_66 -> V_101 ) ;
F_29 ( 0x9900c1 , & V_66 -> V_102 ) ;
F_29 ( V_103 | V_9 ,
& V_66 -> V_87 ) ;
F_29 ( V_104 | V_9 , & V_66 -> V_87 ) ;
F_29 ( V_105 |
V_106 |
V_9 , & V_66 -> V_87 ) ;
}
static void F_30 ( struct V_10 * V_11 )
{
struct V_20 * V_20 = V_11 -> V_20 ;
int V_107 = ( int ) V_11 -> V_108 ;
struct V_109 T_2 * V_110 ;
struct V_70 V_111 = {
. V_85 = V_11 -> V_112 ,
. V_72 = V_73 ,
. V_75 . V_81 = V_113 ,
} ;
struct V_70 V_114 = {
. V_85 = V_11 -> V_112 ,
. V_72 = V_73 ,
. V_75 . V_81 = V_83 ,
} ;
F_31 ( 1 , L_3 ,
V_11 -> V_108 ,
V_11 -> V_115 == 0 ? L_4 : L_5 ,
L_6 ) ;
V_110 = F_32 ( V_20 , V_107 ) ;
switch ( V_11 -> V_67 ) {
case V_80 :
F_29 ( V_116 |
( 1 << V_117 ) ,
& V_110 -> V_87 ) ;
F_28 ( V_11 -> V_84 , V_85 , V_86 , NULL ,
& V_111 ) ;
break;
case V_118 :
F_29 ( V_116 |
( 2 << V_117 ) ,
& V_110 -> V_87 ) ;
F_28 ( V_11 -> V_84 , V_85 , V_86 , NULL ,
& V_114 ) ;
break;
case V_68 :
F_29 ( V_116 |
V_119 |
( 3 << V_117 ) ,
& V_110 -> V_87 ) ;
F_28 ( V_11 -> V_84 , V_85 , V_86 , NULL ,
& V_114 ) ;
break;
}
}
static void F_33 ( struct V_10 * V_11 )
{
struct V_20 * V_20 = V_11 -> V_20 ;
int V_120 = V_11 -> V_108 ;
struct V_121 T_2 * V_122 =
F_34 ( V_20 , V_120 ) ;
struct V_52 * V_53 ;
unsigned long V_59 ;
F_21 ( & V_11 -> V_60 , V_59 ) ;
if ( ! V_11 -> V_44 ) {
F_29 ( V_123 , & V_122 -> V_87 ) ;
F_29 ( V_124 , & V_122 -> V_87 ) ;
} else {
struct V_65 T_2 * V_66 =
F_25 ( V_20 ) ;
T_3 V_125 = F_35 ( & V_66 -> V_87 ) ;
V_125 &= ~ ( V_126 |
V_104 ) ;
F_29 ( V_125 | V_104 ,
& V_66 -> V_87 ) ;
F_29 ( V_125 | V_126 ,
& V_66 -> V_87 ) ;
}
V_53 = F_36 ( & V_11 -> V_61 , struct V_52 , V_57 ) ;
F_37 ( V_11 , & V_11 -> V_33 [ V_53 -> V_23 . V_58 . V_34 ] ) ;
F_23 ( & V_11 -> V_60 , V_59 ) ;
}
static int F_38 ( struct V_1 * V_2 , unsigned int V_127 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_20 * V_20 = V_11 -> V_20 ;
struct V_128 T_2 * V_129 ;
struct V_130 T_2 * V_131 ;
struct V_132 T_2 * V_133 ;
int V_120 = V_11 -> V_108 ;
struct V_134 T_2 * V_135 = F_39 ( V_20 , V_120 ) ;
struct V_121 T_2 * V_122 = F_34 ( V_20 , V_120 ) ;
struct V_62 * V_63 = & V_11 -> V_64 . V_63 ;
T_4 V_136 ;
T_3 V_137 ;
if ( V_11 -> V_41 )
goto V_138;
if ( V_11 -> V_44 ) {
V_11 -> V_139 = false ;
F_24 ( V_11 ) ;
goto V_138;
}
F_30 ( V_11 ) ;
V_131 = F_40 ( V_20 , V_120 ) ;
V_129 = F_41 ( V_20 , V_120 ) ;
V_133 = F_42 ( V_20 , V_120 ) ;
F_29 ( V_123 , & V_122 -> V_87 ) ;
F_29 ( V_124 , & V_122 -> V_87 ) ;
F_29 ( V_63 -> V_46 , & V_135 -> V_140 ) ;
F_29 ( V_63 -> V_15 , & V_135 -> V_141 ) ;
V_136 = F_43 ( V_63 ) * F_44 ( V_63 ) ;
F_29 ( F_45 ( ( T_4 ) F_43 ( V_63 ) * V_142 * 4 ,
V_63 -> V_74 ) , & V_129 -> V_143 ) ;
F_29 ( V_144 , & V_129 -> V_87 ) ;
V_137 = F_35 ( & V_131 -> V_137 ) ;
F_29 ( V_137 / 1000000 , & V_133 -> V_145 ) ;
F_29 ( F_45 ( V_63 -> V_74 * 995 , 1000000000 ) ,
& V_133 -> V_146 ) ;
F_29 ( V_63 -> V_46 * V_63 -> V_15 , & V_131 -> V_147 ) ;
F_29 ( F_45 ( ( T_4 ) V_137 * V_136 , V_63 -> V_74 ) ,
& V_131 -> V_148 ) ;
F_29 ( V_149 |
V_150 ,
& V_129 -> V_151 ) ;
F_29 ( 0 , & V_135 -> V_87 ) ;
F_29 ( V_144 , & V_129 -> V_87 ) ;
F_29 ( 0xff , & V_131 -> V_152 ) ;
F_29 ( V_153 , & V_133 -> V_125 ) ;
F_29 ( V_154 |
V_155 , & V_131 -> V_125 ) ;
V_11 -> V_139 = true ;
V_11 -> V_156 = false ;
V_11 -> V_157 = false ;
V_11 -> V_158 = 0 ;
V_138:
V_11 -> V_159 = 0 ;
F_33 ( V_11 ) ;
return 0 ;
}
static void F_46 ( struct V_10 * V_11 )
{
struct V_20 * V_20 = V_11 -> V_20 ;
struct V_31 * V_32 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
unsigned long V_59 ;
int V_160 = 100 ;
int V_120 = V_11 -> V_108 ;
struct V_121 T_2 * V_122 =
F_34 ( V_20 , V_120 ) ;
if ( ! V_11 -> V_44 ) {
F_29 ( 0 , & V_122 -> V_87 ) ;
} else if ( ! V_11 -> V_41 ) {
struct V_65 T_2 * V_66 =
F_25 ( V_20 ) ;
F_29 ( V_104 , & V_66 -> V_87 ) ;
F_29 ( 0 , & V_66 -> V_87 ) ;
}
F_21 ( & V_11 -> V_60 , V_59 ) ;
F_14 (p, &s->bufs) {
V_53 = F_15 ( V_55 , struct V_52 , V_57 ) ;
V_32 = & V_11 -> V_33 [ V_53 -> V_23 . V_58 . V_34 ] ;
F_47 ( V_32 ) ;
}
F_23 ( & V_11 -> V_60 , V_59 ) ;
if ( ! F_48 ( V_11 -> V_2 . V_161 , F_49 ( V_11 ) ,
F_50 ( V_160 ) ) ) {
F_51 ( V_11 ) ;
F_52 ( L_7 ) ;
}
F_53 ( V_20 , V_162 ,
1 << V_11 -> V_163 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_20 * V_20 = V_11 -> V_20 ;
int V_120 = V_11 -> V_108 ;
struct V_128 T_2 * V_129 ;
struct V_130 T_2 * V_131 ;
struct V_132 T_2 * V_133 ;
struct V_52 * V_53 ;
struct V_54 * V_55 , * V_164 ;
unsigned long V_59 ;
F_46 ( V_11 ) ;
F_21 ( & V_11 -> V_60 , V_59 ) ;
F_55 (p, safe, &s->bufs) {
V_53 = F_15 ( V_55 , struct V_52 , V_57 ) ;
F_56 ( & V_53 -> V_57 ) ;
F_57 ( & V_53 -> V_23 . V_58 , V_165 ) ;
}
F_23 ( & V_11 -> V_60 , V_59 ) ;
if ( V_11 -> V_41 || V_11 -> V_44 )
return;
V_131 = F_40 ( V_20 , V_120 ) ;
V_129 = F_41 ( V_20 , V_120 ) ;
V_133 = F_42 ( V_20 , V_120 ) ;
F_29 ( 0 , & V_129 -> V_87 ) ;
F_29 ( V_144 , & V_129 -> V_87 ) ;
F_29 ( 0 , & V_131 -> V_125 ) ;
F_29 ( 0 , & V_133 -> V_125 ) ;
}
static int F_58 ( struct V_20 * V_20 , unsigned int V_166 , void * V_167 )
{
struct V_168 * V_169 = V_167 ;
void T_2 * V_170 = V_20 -> V_171 + V_169 -> V_172 ;
F_5 ( L_8 , V_170 ) ;
if ( ! F_59 ( V_173 ) )
return - V_174 ;
V_169 -> V_13 = 4 ;
if ( V_166 == V_175 )
F_29 ( V_169 -> V_176 , V_170 ) ;
else
V_169 -> V_176 = F_35 ( V_170 ) ;
return 0 ;
}
static int F_60 ( struct V_177 * V_177 , void * V_178 ,
struct V_168 * V_172 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
struct V_20 * V_20 = V_11 -> V_20 ;
return F_58 ( V_20 , V_179 , V_172 ) ;
}
static int F_62 ( struct V_177 * V_177 , void * V_178 ,
const struct V_168 * V_172 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
struct V_20 * V_20 = V_11 -> V_20 ;
return F_58 ( V_20 , V_175 ,
(struct V_168 * ) V_172 ) ;
}
static int F_63 ( struct V_177 * V_177 , void * V_178 ,
struct V_180 * V_181 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
struct V_20 * V_20 = V_11 -> V_20 ;
F_64 ( V_181 -> V_182 , L_9 , sizeof( V_181 -> V_182 ) ) ;
F_64 ( V_181 -> V_183 , L_9 , sizeof( V_181 -> V_183 ) ) ;
snprintf ( V_181 -> V_184 , sizeof( V_181 -> V_184 ) ,
L_10 , F_65 ( V_20 -> V_40 ) ) ;
V_181 -> V_185 = V_186 | V_187 ;
if ( V_11 -> V_44 )
V_181 -> V_185 |= V_188 ;
else
V_181 -> V_185 |= V_189 ;
V_181 -> V_190 = V_181 -> V_185 | V_191 |
V_189 ;
if ( V_20 -> V_192 )
V_181 -> V_190 |= V_188 ;
return 0 ;
}
static void F_66 ( struct V_10 * V_11 )
{
struct V_134 T_2 * V_135 ;
struct V_128 T_2 * V_129 ;
struct V_130 T_2 * V_131 ;
struct V_132 T_2 * V_133 ;
struct V_109 T_2 * V_110 ;
int V_120 = V_11 -> V_108 ;
struct V_20 * V_20 = V_11 -> V_20 ;
T_3 V_193 , V_194 ;
T_3 V_195 , V_196 ;
V_135 = F_39 ( V_20 , V_120 ) ;
V_129 = F_41 ( V_20 , V_120 ) ;
V_131 = F_40 ( V_20 , V_120 ) ;
V_133 = F_42 ( V_20 , V_120 ) ;
V_110 = F_32 ( V_20 , V_120 ) ;
V_193 = F_35 ( & V_135 -> V_87 ) ;
V_194 = F_35 ( & V_135 -> V_197 ) ;
V_195 = F_35 ( & V_129 -> V_87 ) ;
V_196 = F_35 ( & V_129 -> V_87 ) ;
F_5 ( L_11 , V_120 ,
F_35 ( & V_135 -> V_140 ) , F_35 ( & V_135 -> V_141 ) ) ;
F_5 ( L_12 , V_120 ,
( V_193 & V_198 ) ?
L_13 : L_14 ,
( V_193 & V_199 ) ?
L_15 : L_16 ,
( V_193 & V_200 ) ?
L_17 : L_18 ) ;
F_5 ( L_19 , V_120 ,
( V_194 & V_201 ) ?
L_20 : L_21 ,
( V_194 & V_202 ) ?
L_22 : L_23 ) ;
F_5 ( L_24 , V_120 ,
( V_195 & V_203 ) ?
L_15 : L_16 ,
( V_195 & V_204 ) ?
L_17 : L_18 ,
( V_195 & V_144 ) ?
L_25 : L_26 ,
( V_195 & V_205 ) ?
L_27 : L_28 ,
( V_195 & V_206 ) ?
L_29 : L_30 ,
( V_196 & V_207 ) ?
L_31 : L_30 ,
( V_196 & V_208 ) ?
L_32 : L_30 ) ;
F_5 ( L_33 , V_120 ,
F_35 ( & V_129 -> V_209 ) & 0xff ,
F_35 ( & V_129 -> V_151 ) & 0xff ) ;
F_5 ( L_34 , V_120 , F_35 ( & V_129 -> V_210 ) ) ;
F_5 ( L_35 , V_120 , F_35 ( & V_129 -> V_211 ) ) ;
F_5 ( L_36 , V_120 , F_35 ( & V_129 -> V_212 ) ) ;
F_5 ( L_37 , V_120 , F_35 ( & V_129 -> V_213 ) ) ;
F_5 ( L_38 , V_120 , F_35 ( & V_129 -> V_214 ) ) ;
F_5 ( L_39 , V_120 , F_35 ( & V_129 -> V_215 ) ) ;
F_5 ( L_40 , V_120 , F_35 ( & V_129 -> V_216 ) ) ;
F_5 ( L_41 , V_120 , F_35 ( & V_129 -> V_217 ) ) ;
F_5 ( L_42 , V_120 ,
( F_35 ( & V_131 -> V_125 ) & V_154 ) ?
L_25 : L_26 ,
( F_35 ( & V_131 -> V_125 ) & V_155 ) ?
L_43 : L_30 ,
( F_35 ( & V_131 -> V_197 ) & V_218 ) ?
L_44 : L_45 ) ;
F_29 ( 0xff , & V_129 -> V_209 ) ;
F_5 ( L_46 , V_120 ,
( F_35 ( & V_133 -> V_125 ) & V_153 ) ?
L_25 : L_26 ,
( F_35 ( & V_133 -> V_197 ) & V_219 ) ?
L_47 : L_48 ) ;
F_5 ( L_49 , V_120 , F_35 ( & V_110 -> V_87 ) ) ;
}
static int F_67 ( struct V_177 * V_177 , void * V_178 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
struct V_20 * V_20 = V_11 -> V_20 ;
struct V_65 T_2 * V_66 =
F_25 ( V_20 ) ;
T_5 V_220 ;
F_5 ( L_50 , V_20 -> V_221 ) ;
F_5 ( L_51 ,
F_68 ( V_20 ) ,
F_69 ( V_20 ) ) ;
F_5 ( L_52 ,
V_11 -> V_163 , V_11 -> V_108 ) ;
F_70 ( V_20 ) ;
F_71 ( V_20 ) ;
F_72 ( V_20 ) ;
F_28 ( V_11 -> V_84 , V_222 , V_223 ) ;
if ( ! V_11 -> V_44 ) {
F_66 ( V_11 ) ;
return 0 ;
}
V_220 = F_35 ( & V_66 -> V_224 ) ;
F_5 ( L_53 ,
( V_220 & V_225 ) ?
L_54 : L_30 ,
( V_220 & V_226 ) ?
L_55 : L_30 ) ;
F_5 ( L_56 , F_35 ( & V_66 -> V_227 ) ) ;
return 0 ;
}
static int F_73 ( struct V_177 * V_177 , void * V_178 ,
struct V_228 * V_64 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
if ( V_11 -> V_115 == 1 ) {
if ( V_64 -> V_34 )
return - V_19 ;
memset ( V_64 -> V_229 , 0 , sizeof( V_64 -> V_229 ) ) ;
V_64 -> V_64 = V_230 ;
return 0 ;
}
V_64 -> V_85 = 0 ;
return F_28 ( V_11 -> V_84 ,
V_85 , V_231 , V_64 ) ;
}
static int F_74 ( struct V_177 * V_177 , void * V_178 ,
struct V_232 * V_64 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
int V_233 ;
if ( V_11 -> V_115 == 1 ) {
* V_64 = V_230 ;
return 0 ;
}
if ( F_75 ( V_64 , & V_11 -> V_64 , 0 ) )
return 0 ;
if ( F_76 ( & V_11 -> V_2 ) )
return - V_234 ;
V_233 = F_28 ( V_11 -> V_84 ,
V_235 , V_236 , V_64 ) ;
if ( ! V_233 ) {
V_11 -> V_64 = * V_64 ;
V_11 -> V_46 = V_64 -> V_63 . V_46 ;
V_11 -> V_15 = V_64 -> V_63 . V_15 ;
V_11 -> V_14 = V_64 -> V_63 . V_46 * V_11 -> V_47 ;
}
return V_233 ;
}
static int F_77 ( struct V_177 * V_177 , void * V_178 ,
struct V_232 * V_64 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
if ( V_11 -> V_115 == 1 ) {
* V_64 = V_230 ;
return 0 ;
}
return F_28 ( V_11 -> V_84 ,
V_235 , V_237 , V_64 ) ;
}
static int F_78 ( struct V_177 * V_177 , void * V_178 ,
struct V_232 * V_64 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
if ( V_11 -> V_115 == 1 ) {
* V_64 = V_230 ;
return 0 ;
}
return F_28 ( V_11 -> V_84 ,
V_235 , V_238 , V_64 ) ;
}
static int F_79 ( struct V_177 * V_177 , void * V_178 ,
struct V_239 * V_240 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
V_240 -> V_85 = 0 ;
return F_28 ( V_11 -> V_84 ,
V_85 , V_241 , V_240 ) ;
}
static int F_80 ( struct V_177 * V_177 , void * V_178 ,
struct V_242 * V_243 )
{
switch ( V_243 -> V_34 ) {
case 0 :
F_64 ( V_243 -> V_244 , L_57 , sizeof( V_243 -> V_244 ) ) ;
V_243 -> V_245 = V_80 ;
break;
case 1 :
F_64 ( V_243 -> V_244 , L_58 , sizeof( V_243 -> V_244 ) ) ;
V_243 -> V_245 = V_118 ;
break;
case 2 :
F_64 ( V_243 -> V_244 , L_59 , sizeof( V_243 -> V_244 ) ) ;
V_243 -> V_245 = V_68 ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static int F_81 ( struct V_177 * V_177 , void * V_178 ,
struct V_8 * V_243 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
struct V_246 * V_17 = & V_243 -> V_9 . V_17 ;
struct V_70 V_71 ;
V_17 -> V_46 = V_11 -> V_46 ;
V_17 -> V_15 = V_11 -> V_15 ;
V_17 -> V_247 = V_11 -> V_14 ;
V_17 -> V_50 = V_51 ;
if ( V_11 -> V_115 == 1 ) {
V_17 -> V_76 = V_248 ;
} else {
V_71 . V_85 = V_11 -> V_112 ;
V_71 . V_72 = V_73 ;
F_28 ( V_11 -> V_84 , V_85 , V_249 , NULL , & V_71 ) ;
F_82 ( V_17 , & V_71 . V_75 ) ;
}
V_17 -> V_245 = V_11 -> V_67 ;
V_17 -> V_18 = V_17 -> V_247 * V_17 -> V_15 ;
return 0 ;
}
static int F_83 ( struct V_177 * V_177 , void * V_178 ,
struct V_8 * V_243 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
struct V_246 * V_17 = & V_243 -> V_9 . V_17 ;
struct V_70 V_71 ;
if ( ( V_17 -> V_46 < 176 ) || ( V_17 -> V_15 < 144 ) ) {
V_17 -> V_46 = 176 ;
V_17 -> V_15 = 144 ;
}
if ( ( V_17 -> V_46 > 1920 ) || ( V_17 -> V_15 > 1080 ) ) {
V_17 -> V_46 = 1920 ;
V_17 -> V_15 = 1080 ;
}
V_17 -> V_46 &= ~ 0x3 ;
V_17 -> V_15 &= ~ 0x1 ;
if ( V_11 -> V_115 == 1 ) {
V_17 -> V_46 = 1920 ;
V_17 -> V_15 = 1080 ;
V_17 -> V_76 = V_248 ;
} else {
V_71 . V_85 = V_11 -> V_112 ;
V_71 . V_72 = V_73 ;
F_28 ( V_11 -> V_84 , V_85 , V_249 , NULL , & V_71 ) ;
F_82 ( V_17 , & V_71 . V_75 ) ;
}
switch ( V_17 -> V_245 ) {
case V_80 :
default:
V_17 -> V_247 = F_84 ( V_17 -> V_247 & ~ 0x3 ,
V_17 -> V_46 * V_250 ) ;
V_17 -> V_245 = V_80 ;
break;
case V_118 :
V_17 -> V_247 = F_84 ( V_17 -> V_247 & ~ 0x3 ,
V_17 -> V_46 * V_251 ) ;
break;
case V_68 :
V_17 -> V_247 = F_84 ( V_17 -> V_247 & ~ 0x3 ,
V_17 -> V_46 * V_252 ) ;
break;
}
V_17 -> V_18 = V_17 -> V_247 * V_17 -> V_15 ;
V_17 -> V_50 = V_51 ;
V_17 -> V_253 = 0 ;
return 0 ;
}
static int F_85 ( struct V_177 * V_177 , void * V_178 ,
struct V_8 * V_243 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
struct V_246 * V_17 = & V_243 -> V_9 . V_17 ;
if ( F_76 ( & V_11 -> V_2 ) )
return - V_234 ;
if ( F_83 ( V_177 , V_178 , V_243 ) )
return - V_19 ;
V_11 -> V_46 = V_17 -> V_46 ;
V_11 -> V_15 = V_17 -> V_15 ;
V_11 -> V_14 = V_17 -> V_247 ;
switch ( V_17 -> V_245 ) {
case V_80 :
V_11 -> V_47 = V_250 ;
break;
case V_118 :
V_11 -> V_47 = V_251 ;
break;
case V_68 :
V_11 -> V_47 = V_252 ;
break;
default:
return - V_19 ;
}
V_11 -> V_67 = V_17 -> V_245 ;
F_30 ( V_11 ) ;
return 0 ;
}
static int F_86 ( struct V_177 * V_177 , void * V_178 ,
struct V_8 * V_243 )
{
struct V_246 * V_17 = & V_243 -> V_9 . V_17 ;
if ( ( V_17 -> V_46 < 176 ) || ( V_17 -> V_15 < 144 ) ) {
V_17 -> V_46 = 176 ;
V_17 -> V_15 = 144 ;
}
if ( ( V_17 -> V_46 > 1920 ) || ( V_17 -> V_15 > 1080 ) ) {
V_17 -> V_46 = 1920 ;
V_17 -> V_15 = 1080 ;
}
V_17 -> V_46 &= ~ 0x3 ;
V_17 -> V_15 &= ~ 0x1 ;
switch ( V_17 -> V_245 ) {
case V_80 :
default:
V_17 -> V_247 = F_84 ( V_17 -> V_247 & ~ 0x3 ,
V_17 -> V_46 * V_250 ) ;
V_17 -> V_245 = V_80 ;
break;
case V_68 :
V_17 -> V_247 = F_84 ( V_17 -> V_247 & ~ 0x3 ,
V_17 -> V_46 * V_252 ) ;
break;
}
V_17 -> V_18 = V_17 -> V_247 * V_17 -> V_15 ;
V_17 -> V_50 = V_51 ;
return 0 ;
}
static int F_87 ( struct V_177 * V_177 , void * V_178 ,
struct V_8 * V_243 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
struct V_246 * V_17 = & V_243 -> V_9 . V_17 ;
V_17 -> V_46 = V_11 -> V_46 ;
V_17 -> V_15 = V_11 -> V_15 ;
V_17 -> V_247 = V_11 -> V_14 ;
V_17 -> V_50 = V_51 ;
V_17 -> V_245 = V_11 -> V_67 ;
V_17 -> V_76 = V_11 -> V_76 ;
V_17 -> V_77 = V_11 -> V_77 ;
V_17 -> V_78 = V_11 -> V_78 ;
V_17 -> V_79 = V_11 -> V_79 ;
V_17 -> V_18 = V_17 -> V_247 * V_17 -> V_15 ;
return 0 ;
}
static int F_88 ( struct V_177 * V_177 , void * V_178 ,
struct V_242 * V_243 )
{
switch ( V_243 -> V_34 ) {
case 0 :
F_64 ( V_243 -> V_244 , L_57 , sizeof( V_243 -> V_244 ) ) ;
V_243 -> V_245 = V_80 ;
break;
case 1 :
F_64 ( V_243 -> V_244 , L_59 , sizeof( V_243 -> V_244 ) ) ;
V_243 -> V_245 = V_68 ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static int F_89 ( struct V_177 * V_177 , void * V_178 ,
struct V_8 * V_243 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
struct V_246 * V_17 = & V_243 -> V_9 . V_17 ;
struct V_70 V_71 = { 0 } ;
T_3 V_81 ;
if ( F_86 ( V_177 , V_178 , V_243 ) )
return - V_19 ;
if ( F_76 ( & V_11 -> V_2 ) && ( V_17 -> V_245 != V_11 -> V_67 ||
V_17 -> V_46 != V_11 -> V_46 || V_17 -> V_15 != V_11 -> V_15 ||
V_17 -> V_247 != V_11 -> V_14 ) )
return - V_234 ;
switch ( V_17 -> V_245 ) {
case V_80 :
V_11 -> V_47 = V_250 ;
V_81 = V_82 ;
break;
case V_68 :
V_11 -> V_47 = V_252 ;
V_81 = V_83 ;
break;
default:
return - V_19 ;
}
V_11 -> V_46 = V_17 -> V_46 ;
V_11 -> V_15 = V_17 -> V_15 ;
V_11 -> V_14 = V_17 -> V_247 ;
V_11 -> V_67 = V_17 -> V_245 ;
V_11 -> V_76 = V_17 -> V_76 ;
V_11 -> V_77 = V_17 -> V_77 ;
V_11 -> V_78 = V_17 -> V_78 ;
V_11 -> V_79 = V_17 -> V_79 ;
V_71 . V_72 = V_73 ;
F_90 ( & V_71 . V_75 , V_17 , V_81 ) ;
F_28 ( V_11 -> V_84 , V_85 , V_86 , NULL , & V_71 ) ;
return 0 ;
}
static int F_91 ( struct V_177 * V_177 , void * V_178 ,
struct V_254 * V_255 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
if ( V_255 -> V_34 > 1 )
return - V_19 ;
if ( V_255 -> V_34 == 0 )
snprintf ( V_255 -> V_256 , sizeof( V_255 -> V_256 ) ,
L_60 , V_11 -> V_108 ) ;
else
snprintf ( V_255 -> V_256 , sizeof( V_255 -> V_256 ) ,
L_61 , V_11 -> V_108 ) ;
V_255 -> type = V_257 ;
V_255 -> V_190 = V_258 ;
if ( V_255 -> V_34 == 1 )
return 0 ;
return F_28 ( V_11 -> V_84 ,
V_235 , V_259 , & V_255 -> V_197 ) ;
}
static int F_92 ( struct V_177 * V_177 , void * V_178 , unsigned int * V_56 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
* V_56 = V_11 -> V_115 ;
return 0 ;
}
static int F_93 ( struct V_177 * V_177 , void * V_178 , unsigned int V_56 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
if ( V_56 >= 2 )
return - V_19 ;
if ( F_76 ( & V_11 -> V_2 ) )
return - V_234 ;
V_11 -> V_115 = V_56 ;
F_30 ( V_11 ) ;
if ( V_11 -> V_115 == 1 )
return 0 ;
return F_28 ( V_11 -> V_84 , V_235 , V_260 ,
V_261 , 0 , 0 ) ;
}
static int F_94 ( struct V_177 * V_177 , void * V_178 ,
struct V_262 * V_263 )
{
if ( V_263 -> V_34 )
return - V_19 ;
snprintf ( V_263 -> V_256 , sizeof( V_263 -> V_256 ) , L_60 , V_263 -> V_34 ) ;
V_263 -> type = V_264 ;
V_263 -> V_190 = V_265 ;
return 0 ;
}
static int F_95 ( struct V_177 * V_177 , void * V_178 , unsigned int * V_56 )
{
* V_56 = 0 ;
return 0 ;
}
static int F_96 ( struct V_177 * V_177 , void * V_178 , unsigned int V_56 )
{
return V_56 ? - V_19 : 0 ;
}
static int F_97 ( struct V_177 * V_177 , void * V_266 , struct V_267 * V_268 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
T_3 V_85 = V_268 -> V_85 ;
int V_37 ;
if ( V_268 -> V_85 >= ( V_11 -> V_44 ? 1 : 2 ) )
return - V_19 ;
V_268 -> V_85 = 0 ;
V_37 = F_28 ( V_11 -> V_84 , V_85 , V_269 , V_268 ) ;
V_268 -> V_85 = V_85 ;
return V_37 ;
}
static int F_98 ( struct V_177 * V_177 , void * V_266 , struct V_267 * V_268 )
{
struct V_10 * V_11 = F_61 ( V_177 ) ;
T_3 V_85 = V_268 -> V_85 ;
int V_37 ;
if ( V_268 -> V_85 >= 2 )
return - V_19 ;
V_268 -> V_85 = 0 ;
V_37 = F_28 ( V_11 -> V_84 , V_85 , V_270 , V_268 ) ;
V_268 -> V_85 = V_85 ;
return V_37 ;
}
static int F_99 ( struct V_271 * V_266 ,
const struct V_272 * V_273 )
{
switch ( V_273 -> type ) {
case V_274 :
return F_100 ( V_266 , V_273 , 4 , NULL ) ;
}
return F_101 ( V_266 , V_273 ) ;
}
static int F_102 ( struct V_177 * V_177 , void * V_266 , struct V_275 * V_276 )
{
if ( V_276 -> type != V_277 )
return - V_19 ;
V_276 -> V_278 . V_279 . V_280 . V_281 = 1 ;
V_276 -> V_278 . V_279 . V_280 . V_282 = 60 ;
V_276 -> V_278 . V_279 . V_283 = 3 ;
return 0 ;
}
static int F_103 ( struct V_20 * V_20 , int V_284 )
{
static const struct V_232 V_285 =
V_286 ;
struct V_10 * V_11 = V_20 -> V_287 + V_284 ;
struct V_288 * V_289 = & V_11 -> V_289 ;
struct V_1 * V_2 = & V_11 -> V_2 ;
int V_37 ;
F_104 ( & V_11 -> V_290 ) ;
F_105 ( & V_11 -> V_60 ) ;
snprintf ( V_289 -> V_256 , sizeof( V_289 -> V_256 ) ,
L_62 , V_20 -> V_291 . V_256 , V_284 ) ;
V_11 -> V_46 = 1920 ;
V_11 -> V_15 = V_11 -> V_41 ? 4 : 1080 ;
if ( V_11 -> V_41 ) {
V_11 -> V_47 = 1 ;
V_11 -> V_67 = V_292 ;
} else if ( V_11 -> V_44 ) {
V_11 -> V_47 = V_252 ;
V_11 -> V_67 = V_68 ;
} else {
V_11 -> V_47 = V_250 ;
V_11 -> V_67 = V_80 ;
}
V_11 -> V_76 = V_248 ;
V_11 -> V_14 = V_11 -> V_46 * V_11 -> V_47 ;
if ( ! V_11 -> V_41 ) {
if ( V_11 -> V_293 )
F_106 ( L_63 , V_284 ) ;
V_289 -> V_291 = & V_20 -> V_291 ;
if ( V_11 -> V_293 )
V_289 -> V_294 = & V_295 ;
else
V_289 -> V_294 = V_11 -> V_44 ? & V_296 :
& V_297 ;
V_289 -> V_298 = V_299 ;
V_289 -> V_300 = V_11 -> V_44 ? V_301 : V_302 ;
V_289 -> V_290 = & V_11 -> V_290 ;
if ( V_11 -> V_84 )
V_289 -> V_303 = V_11 -> V_84 -> V_303 ;
V_11 -> V_64 = V_285 ;
F_28 ( V_11 -> V_84 , V_235 , V_236 , & V_11 -> V_64 ) ;
if ( ! V_11 -> V_44 && V_11 -> V_84 )
F_30 ( V_11 ) ;
V_289 -> V_304 = V_11 -> V_293 ? & V_305 :
& V_306 ;
}
F_107 ( & V_11 -> V_61 ) ;
V_2 -> type = V_11 -> V_44 ? V_307 :
V_277 ;
V_2 -> V_308 = V_309 | V_310 | V_311 ;
V_2 -> V_308 |= V_11 -> V_44 ? V_312 : V_313 ;
V_2 -> V_12 = V_11 ;
V_2 -> V_314 = sizeof( struct V_52 ) ;
V_2 -> V_315 = & V_316 ;
V_2 -> V_317 = & V_318 ;
V_2 -> V_319 = V_320 ;
V_2 -> V_321 = 2 ;
V_2 -> V_290 = & V_11 -> V_290 ;
V_289 -> V_322 = V_2 ;
F_108 ( V_289 , V_11 ) ;
V_37 = F_109 ( V_2 ) ;
if ( ! V_11 -> V_41 && V_37 == 0 )
V_37 = F_110 ( V_289 , V_323 , - 1 ) ;
else if ( ! V_11 -> V_293 )
V_37 = F_111 ( V_11 ) ;
if ( V_37 < 0 ) {
if ( ! V_11 -> V_41 )
F_27 ( L_64 ,
V_284 ) ;
return V_37 ;
}
F_5 ( L_65 , V_284 ) ;
return 0 ;
}
int F_112 ( struct V_20 * V_20 )
{
int V_284 , V_37 ;
for ( V_284 = 0 ; V_284 < V_324 ; V_284 ++ ) {
V_37 = F_103 ( V_20 , V_284 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
void F_113 ( struct V_20 * V_20 )
{
int V_284 ;
for ( V_284 = 0 ; V_284 < V_324 ; V_284 ++ ) {
struct V_10 * V_11 = V_20 -> V_287 + V_284 ;
struct V_288 * V_289 = & V_11 -> V_289 ;
if ( ! V_11 -> V_41 )
F_114 ( V_289 ) ;
else if ( ! V_11 -> V_293 )
F_115 ( V_11 ) ;
}
}
