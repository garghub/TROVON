static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 ,
unsigned int V_5 [] , struct V_6 * V_7 [] )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned V_11 = V_9 -> V_12 * V_9 -> V_13 ;
if ( * V_3 < 3 )
* V_3 = 3 ;
if ( * V_3 > V_14 )
* V_3 = V_14 ;
if ( * V_4 )
return V_5 [ 0 ] < V_11 ? - V_15 : 0 ;
* V_4 = 1 ;
V_5 [ 0 ] = V_11 ;
return 0 ;
}
static int F_2 ( struct V_16 * V_17 )
{
struct V_8 * V_9 = V_17 -> V_1 -> V_10 ;
struct V_18 * V_18 = V_9 -> V_18 ;
const T_1 V_19 =
( V_20 * V_21 ) / V_22 + 2 ;
const T_1 V_23 =
V_24 * V_19 * 0x20 ;
const T_1 V_25 = ( ( 1920 * 4 ) / V_22 + 1 ) * 0x20 ;
struct V_26 * V_27 = & V_9 -> V_28 [ V_17 -> V_29 ] ;
struct V_30 * V_31 = F_3 ( V_17 , 0 ) ;
unsigned V_11 ;
int V_32 ;
V_11 = V_9 -> V_12 * V_9 -> V_13 ;
if ( F_4 ( V_17 , 0 ) < V_11 ) {
F_5 ( L_1 ,
F_4 ( V_17 , 0 ) , V_11 ) ;
return - V_15 ;
}
if ( V_27 -> V_33 == NULL ) {
V_27 -> V_34 = & V_18 -> V_35 -> V_34 ;
F_6 ( V_27 ,
V_9 -> V_36 ? V_25 : V_23 ) ;
if ( V_27 -> V_33 == NULL )
return - V_37 ;
}
V_32 = F_7 ( V_18 , V_31 -> V_38 ,
! V_9 -> V_39 , V_31 -> V_40 , V_11 ,
V_9 -> V_41 * V_9 -> V_42 , V_9 -> V_12 , V_27 ) ;
if ( V_32 )
F_8 ( V_27 ) ;
return V_32 ;
}
static void F_9 ( struct V_16 * V_17 )
{
struct V_8 * V_9 = V_17 -> V_1 -> V_10 ;
struct V_26 * V_27 = & V_9 -> V_28 [ V_17 -> V_29 ] ;
F_8 ( V_27 ) ;
}
static int F_10 ( struct V_16 * V_17 )
{
struct V_43 * V_44 = F_11 ( V_17 ) ;
struct V_8 * V_9 = V_17 -> V_1 -> V_10 ;
F_12 ( V_17 , 0 , V_9 -> V_12 * V_9 -> V_13 ) ;
V_44 -> V_45 = V_46 ;
return 0 ;
}
static void F_13 ( struct V_8 * V_9 )
{
struct V_26 * V_27 [ V_14 ] ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
int V_51 = 0 ;
F_14 (p, &s->bufs) {
V_48 = F_15 ( V_50 , struct V_47 , V_52 ) ;
V_27 [ V_51 ] = & V_9 -> V_28 [ V_48 -> V_17 . V_53 . V_29 ] ;
if ( V_51 > 0 )
F_16 ( V_27 [ V_51 - 1 ] , V_27 [ V_51 ] ) ;
V_51 ++ ;
}
}
static void F_17 ( struct V_16 * V_17 )
{
struct V_43 * V_44 = F_11 ( V_17 ) ;
struct V_1 * V_2 = V_17 -> V_1 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_47 * V_48 = F_18 ( V_44 ) ;
struct V_26 * V_27 = & V_9 -> V_28 [ V_17 -> V_29 ] ;
unsigned long V_54 ;
F_19 ( V_27 ) ;
F_20 ( V_27 ) ;
F_21 ( & V_9 -> V_55 , V_54 ) ;
F_22 ( & V_48 -> V_52 , & V_9 -> V_56 ) ;
F_13 ( V_9 ) ;
F_23 ( & V_9 -> V_55 , V_54 ) ;
}
static void F_24 ( struct V_8 * V_9 )
{
struct V_18 * V_18 = V_9 -> V_18 ;
struct V_57 * V_58 = & V_9 -> V_59 . V_58 ;
struct V_60 T_2 * V_61 =
F_25 ( V_18 ) ;
unsigned V_62 = V_9 -> V_63 != V_64 ?
V_65 : 0 ;
struct V_66 V_67 = {
. V_68 = V_69 ,
} ;
T_3 V_70 = V_58 -> V_71 ;
if ( V_58 -> V_54 & V_72 )
V_70 = F_26 ( V_70 * 1000ULL , 1001 ) ;
if ( ! F_27 ( V_18 , V_70 ) ) {
F_28 ( L_2 ) ;
return;
}
V_67 . V_73 . V_74 = V_9 -> V_74 ;
V_67 . V_73 . V_75 = V_9 -> V_75 ;
V_67 . V_73 . V_76 = V_9 -> V_76 ;
V_67 . V_73 . V_77 = V_9 -> V_77 ;
V_67 . V_73 . V_41 = V_58 -> V_41 ;
V_67 . V_73 . V_13 = V_58 -> V_13 ;
switch ( V_9 -> V_63 ) {
case V_78 :
V_67 . V_73 . V_79 = V_80 ;
break;
case V_64 :
V_67 . V_73 . V_79 = V_81 ;
break;
}
F_29 ( V_9 -> V_82 , V_83 , V_84 , NULL , & V_67 ) ;
F_30 ( 0 , & V_61 -> V_85 ) ;
F_30 ( V_58 -> V_86 , & V_61 -> V_87 ) ;
F_30 ( V_58 -> V_88 , & V_61 -> V_89 ) ;
F_30 ( V_58 -> V_41 , & V_61 -> V_90 ) ;
F_30 ( V_58 -> V_91 , & V_61 -> V_92 ) ;
F_30 ( V_58 -> V_93 , & V_61 -> V_94 ) ;
F_30 ( V_58 -> V_95 , & V_61 -> V_96 ) ;
F_30 ( V_58 -> V_13 , & V_61 -> V_97 ) ;
F_30 ( V_58 -> V_98 , & V_61 -> V_99 ) ;
F_30 ( 0x9900c1 , & V_61 -> V_100 ) ;
F_30 ( V_101 | V_62 ,
& V_61 -> V_85 ) ;
F_30 ( V_102 | V_62 , & V_61 -> V_85 ) ;
F_30 ( V_103 |
V_104 |
V_62 , & V_61 -> V_85 ) ;
}
static void F_31 ( struct V_8 * V_9 )
{
struct V_18 * V_18 = V_9 -> V_18 ;
int V_105 = ( int ) V_9 -> V_106 ;
struct V_107 T_2 * V_108 ;
struct V_66 V_109 = {
. V_83 = V_9 -> V_110 ,
. V_68 = V_69 ,
. V_73 . V_79 = V_111 ,
} ;
struct V_66 V_112 = {
. V_83 = V_9 -> V_110 ,
. V_68 = V_69 ,
. V_73 . V_79 = V_81 ,
} ;
F_32 ( 1 , L_3 ,
V_9 -> V_106 ,
V_9 -> V_113 == 0 ? L_4 : L_5 ,
L_6 ) ;
V_108 = F_33 ( V_18 , V_105 ) ;
switch ( V_9 -> V_63 ) {
case V_78 :
F_30 ( V_114 |
( 1 << V_115 ) ,
& V_108 -> V_85 ) ;
F_29 ( V_9 -> V_82 , V_83 , V_84 , NULL ,
& V_109 ) ;
break;
case V_116 :
F_30 ( V_114 |
( 2 << V_115 ) ,
& V_108 -> V_85 ) ;
F_29 ( V_9 -> V_82 , V_83 , V_84 , NULL ,
& V_112 ) ;
break;
case V_64 :
F_30 ( V_114 |
V_117 |
( 3 << V_115 ) ,
& V_108 -> V_85 ) ;
F_29 ( V_9 -> V_82 , V_83 , V_84 , NULL ,
& V_112 ) ;
break;
}
}
static void F_34 ( struct V_8 * V_9 )
{
struct V_18 * V_18 = V_9 -> V_18 ;
int V_118 = V_9 -> V_106 ;
struct V_119 T_2 * V_120 =
F_35 ( V_18 , V_118 ) ;
struct V_47 * V_48 ;
unsigned long V_54 ;
F_21 ( & V_9 -> V_55 , V_54 ) ;
if ( ! V_9 -> V_39 ) {
F_30 ( V_121 , & V_120 -> V_85 ) ;
F_30 ( V_122 , & V_120 -> V_85 ) ;
} else {
struct V_60 T_2 * V_61 =
F_25 ( V_18 ) ;
T_4 V_123 = F_36 ( & V_61 -> V_85 ) ;
V_123 &= ~ ( V_124 |
V_102 ) ;
F_30 ( V_123 | V_102 ,
& V_61 -> V_85 ) ;
F_30 ( V_123 | V_124 ,
& V_61 -> V_85 ) ;
}
V_48 = F_37 ( & V_9 -> V_56 , struct V_47 , V_52 ) ;
F_38 ( V_9 , & V_9 -> V_28 [ V_48 -> V_17 . V_53 . V_29 ] ) ;
F_23 ( & V_9 -> V_55 , V_54 ) ;
}
static int F_39 ( struct V_1 * V_2 , unsigned int V_125 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_18 * V_18 = V_9 -> V_18 ;
struct V_126 T_2 * V_127 ;
struct V_128 T_2 * V_129 ;
struct V_130 T_2 * V_131 ;
int V_118 = V_9 -> V_106 ;
struct V_132 T_2 * V_133 = F_40 ( V_18 , V_118 ) ;
struct V_119 T_2 * V_120 = F_35 ( V_18 , V_118 ) ;
struct V_57 * V_58 = & V_9 -> V_59 . V_58 ;
T_3 V_134 ;
T_4 V_135 ;
if ( V_9 -> V_36 )
goto V_136;
if ( V_9 -> V_39 ) {
V_9 -> V_137 = false ;
F_24 ( V_9 ) ;
goto V_136;
}
F_31 ( V_9 ) ;
V_129 = F_41 ( V_18 , V_118 ) ;
V_127 = F_42 ( V_18 , V_118 ) ;
V_131 = F_43 ( V_18 , V_118 ) ;
F_30 ( V_121 , & V_120 -> V_85 ) ;
F_30 ( V_122 , & V_120 -> V_85 ) ;
F_30 ( V_58 -> V_41 , & V_133 -> V_138 ) ;
F_30 ( V_58 -> V_13 , & V_133 -> V_139 ) ;
V_134 = F_44 ( V_58 ) * F_45 ( V_58 ) ;
F_30 ( F_26 ( ( T_3 ) F_44 ( V_58 ) * V_140 * 4 ,
V_58 -> V_71 ) , & V_127 -> V_141 ) ;
F_30 ( V_142 , & V_127 -> V_85 ) ;
V_135 = F_36 ( & V_129 -> V_135 ) ;
F_30 ( V_135 / 1000000 , & V_131 -> V_143 ) ;
F_30 ( F_26 ( V_58 -> V_71 * 995 , 1000000000 ) ,
& V_131 -> V_144 ) ;
F_30 ( V_58 -> V_41 * V_58 -> V_13 , & V_129 -> V_145 ) ;
F_30 ( F_26 ( ( T_3 ) V_135 * V_134 , V_58 -> V_71 ) ,
& V_129 -> V_146 ) ;
F_30 ( V_147 |
V_148 ,
& V_127 -> V_149 ) ;
F_30 ( 0 , & V_133 -> V_85 ) ;
F_30 ( V_142 , & V_127 -> V_85 ) ;
F_30 ( 0xff , & V_129 -> V_150 ) ;
F_30 ( V_151 , & V_131 -> V_123 ) ;
F_30 ( V_152 |
V_153 , & V_129 -> V_123 ) ;
V_9 -> V_137 = true ;
V_9 -> V_154 = false ;
V_9 -> V_155 = false ;
V_9 -> V_156 = 0 ;
V_136:
V_9 -> V_157 = 0 ;
F_34 ( V_9 ) ;
return 0 ;
}
static void F_46 ( struct V_8 * V_9 )
{
struct V_18 * V_18 = V_9 -> V_18 ;
struct V_26 * V_27 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
unsigned long V_54 ;
int V_158 = 100 ;
int V_118 = V_9 -> V_106 ;
struct V_119 T_2 * V_120 =
F_35 ( V_18 , V_118 ) ;
if ( ! V_9 -> V_39 ) {
F_30 ( 0 , & V_120 -> V_85 ) ;
} else if ( ! V_9 -> V_36 ) {
struct V_60 T_2 * V_61 =
F_25 ( V_18 ) ;
F_30 ( V_102 , & V_61 -> V_85 ) ;
F_30 ( 0 , & V_61 -> V_85 ) ;
}
F_21 ( & V_9 -> V_55 , V_54 ) ;
F_14 (p, &s->bufs) {
V_48 = F_15 ( V_50 , struct V_47 , V_52 ) ;
V_27 = & V_9 -> V_28 [ V_48 -> V_17 . V_53 . V_29 ] ;
F_47 ( V_27 ) ;
}
F_23 ( & V_9 -> V_55 , V_54 ) ;
if ( ! F_48 ( V_9 -> V_2 . V_159 , F_49 ( V_9 ) ,
F_50 ( V_158 ) ) ) {
F_51 ( V_9 ) ;
F_52 ( L_7 ) ;
}
F_53 ( V_18 , V_160 ,
1 << V_9 -> V_161 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_18 * V_18 = V_9 -> V_18 ;
int V_118 = V_9 -> V_106 ;
struct V_126 T_2 * V_127 ;
struct V_128 T_2 * V_129 ;
struct V_130 T_2 * V_131 ;
struct V_47 * V_48 ;
struct V_49 * V_50 , * V_162 ;
unsigned long V_54 ;
F_46 ( V_9 ) ;
F_21 ( & V_9 -> V_55 , V_54 ) ;
F_55 (p, safe, &s->bufs) {
V_48 = F_15 ( V_50 , struct V_47 , V_52 ) ;
F_56 ( & V_48 -> V_52 ) ;
F_57 ( & V_48 -> V_17 . V_53 , V_163 ) ;
}
F_23 ( & V_9 -> V_55 , V_54 ) ;
if ( V_9 -> V_36 || V_9 -> V_39 )
return;
V_129 = F_41 ( V_18 , V_118 ) ;
V_127 = F_42 ( V_18 , V_118 ) ;
V_131 = F_43 ( V_18 , V_118 ) ;
F_30 ( 0 , & V_127 -> V_85 ) ;
F_30 ( V_142 , & V_127 -> V_85 ) ;
F_30 ( 0 , & V_129 -> V_123 ) ;
F_30 ( 0 , & V_131 -> V_123 ) ;
}
static int F_58 ( struct V_18 * V_18 , unsigned int V_164 , void * V_165 )
{
struct V_166 * V_167 = V_165 ;
void T_2 * V_168 = V_18 -> V_169 + V_167 -> V_170 ;
F_5 ( L_8 , V_168 ) ;
if ( ! F_59 ( V_171 ) )
return - V_172 ;
V_167 -> V_11 = 4 ;
if ( V_164 == V_173 )
F_30 ( V_167 -> V_174 , V_168 ) ;
else
V_167 -> V_174 = F_36 ( V_168 ) ;
return 0 ;
}
static int F_60 ( struct V_175 * V_175 , void * V_176 ,
struct V_166 * V_170 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
struct V_18 * V_18 = V_9 -> V_18 ;
return F_58 ( V_18 , V_177 , V_170 ) ;
}
static int F_62 ( struct V_175 * V_175 , void * V_176 ,
const struct V_166 * V_170 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
struct V_18 * V_18 = V_9 -> V_18 ;
return F_58 ( V_18 , V_173 ,
(struct V_166 * ) V_170 ) ;
}
static int F_63 ( struct V_175 * V_175 , void * V_176 ,
struct V_178 * V_179 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
struct V_18 * V_18 = V_9 -> V_18 ;
F_64 ( V_179 -> V_180 , L_9 , sizeof( V_179 -> V_180 ) ) ;
F_64 ( V_179 -> V_181 , L_9 , sizeof( V_179 -> V_181 ) ) ;
snprintf ( V_179 -> V_182 , sizeof( V_179 -> V_182 ) ,
L_10 , F_65 ( V_18 -> V_35 ) ) ;
V_179 -> V_183 = V_184 | V_185 ;
if ( V_9 -> V_39 )
V_179 -> V_183 |= V_186 ;
else
V_179 -> V_183 |= V_187 ;
V_179 -> V_188 = V_179 -> V_183 | V_189 |
V_187 ;
if ( V_18 -> V_190 )
V_179 -> V_188 |= V_186 ;
return 0 ;
}
static void F_66 ( struct V_8 * V_9 )
{
struct V_132 T_2 * V_133 ;
struct V_126 T_2 * V_127 ;
struct V_128 T_2 * V_129 ;
struct V_130 T_2 * V_131 ;
struct V_107 T_2 * V_108 ;
int V_118 = V_9 -> V_106 ;
struct V_18 * V_18 = V_9 -> V_18 ;
T_4 V_191 , V_192 ;
T_4 V_193 , V_194 ;
V_133 = F_40 ( V_18 , V_118 ) ;
V_127 = F_42 ( V_18 , V_118 ) ;
V_129 = F_41 ( V_18 , V_118 ) ;
V_131 = F_43 ( V_18 , V_118 ) ;
V_108 = F_33 ( V_18 , V_118 ) ;
V_191 = F_36 ( & V_133 -> V_85 ) ;
V_192 = F_36 ( & V_133 -> V_195 ) ;
V_193 = F_36 ( & V_127 -> V_85 ) ;
V_194 = F_36 ( & V_127 -> V_195 ) ;
F_5 ( L_11 , V_118 ,
F_36 ( & V_133 -> V_138 ) , F_36 ( & V_133 -> V_139 ) ) ;
F_5 ( L_12 , V_118 ,
( V_191 & V_196 ) ?
L_13 : L_14 ,
( V_191 & V_197 ) ?
L_15 : L_16 ,
( V_191 & V_198 ) ?
L_17 : L_18 ) ;
F_5 ( L_19 , V_118 ,
( V_192 & V_199 ) ?
L_20 : L_21 ,
( V_192 & V_200 ) ?
L_22 : L_23 ) ;
F_5 ( L_24 , V_118 ,
( V_193 & V_201 ) ?
L_15 : L_16 ,
( V_193 & V_202 ) ?
L_17 : L_18 ,
( V_193 & V_142 ) ?
L_25 : L_26 ,
( V_193 & V_203 ) ?
L_27 : L_28 ,
( V_193 & V_204 ) ?
L_29 : L_30 ,
( V_194 & V_205 ) ?
L_31 : L_30 ,
( V_194 & V_206 ) ?
L_32 : L_30 ) ;
F_5 ( L_33 , V_118 ,
F_36 ( & V_127 -> V_207 ) & 0xff ,
F_36 ( & V_127 -> V_149 ) & 0xff ) ;
F_5 ( L_34 , V_118 , F_36 ( & V_127 -> V_208 ) ) ;
F_5 ( L_35 , V_118 , F_36 ( & V_127 -> V_209 ) ) ;
F_5 ( L_36 , V_118 , F_36 ( & V_127 -> V_210 ) ) ;
F_5 ( L_37 , V_118 , F_36 ( & V_127 -> V_211 ) ) ;
F_5 ( L_38 , V_118 , F_36 ( & V_127 -> V_212 ) ) ;
F_5 ( L_39 , V_118 , F_36 ( & V_127 -> V_213 ) ) ;
F_5 ( L_40 , V_118 , F_36 ( & V_127 -> V_214 ) ) ;
F_5 ( L_41 , V_118 , F_36 ( & V_127 -> V_215 ) ) ;
F_5 ( L_42 , V_118 ,
( F_36 ( & V_129 -> V_123 ) & V_152 ) ?
L_25 : L_26 ,
( F_36 ( & V_129 -> V_123 ) & V_153 ) ?
L_43 : L_30 ,
( F_36 ( & V_129 -> V_195 ) & V_216 ) ?
L_44 : L_45 ) ;
F_30 ( 0xff , & V_127 -> V_207 ) ;
F_5 ( L_46 , V_118 ,
( F_36 ( & V_131 -> V_123 ) & V_151 ) ?
L_25 : L_26 ,
( F_36 ( & V_131 -> V_195 ) & V_217 ) ?
L_47 : L_48 ) ;
F_5 ( L_49 , V_118 , F_36 ( & V_108 -> V_85 ) ) ;
}
static int F_67 ( struct V_175 * V_175 , void * V_176 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
struct V_18 * V_18 = V_9 -> V_18 ;
struct V_60 T_2 * V_61 =
F_25 ( V_18 ) ;
T_5 V_218 ;
F_5 ( L_50 , V_18 -> V_219 ) ;
F_5 ( L_51 ,
F_68 ( V_18 ) ,
F_69 ( V_18 ) ) ;
F_5 ( L_52 ,
V_9 -> V_161 , V_9 -> V_106 ) ;
F_70 ( V_18 ) ;
F_71 ( V_18 ) ;
F_72 ( V_18 ) ;
F_29 ( V_9 -> V_82 , V_220 , V_221 ) ;
if ( ! V_9 -> V_39 ) {
F_66 ( V_9 ) ;
return 0 ;
}
V_218 = F_36 ( & V_61 -> V_222 ) ;
F_5 ( L_53 ,
( V_218 & V_223 ) ?
L_54 : L_30 ,
( V_218 & V_224 ) ?
L_55 : L_30 ) ;
F_5 ( L_56 , F_36 ( & V_61 -> V_225 ) ) ;
return 0 ;
}
static int F_73 ( struct V_175 * V_175 , void * V_176 ,
struct V_226 * V_59 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
if ( V_9 -> V_113 == 1 ) {
if ( V_59 -> V_29 )
return - V_15 ;
memset ( V_59 -> V_227 , 0 , sizeof( V_59 -> V_227 ) ) ;
V_59 -> V_59 = V_228 ;
return 0 ;
}
V_59 -> V_83 = 0 ;
return F_29 ( V_9 -> V_82 ,
V_83 , V_229 , V_59 ) ;
}
static int F_74 ( struct V_175 * V_175 , void * V_176 ,
struct V_230 * V_59 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
int V_231 ;
if ( V_9 -> V_113 == 1 ) {
* V_59 = V_228 ;
return 0 ;
}
if ( F_75 ( V_59 , & V_9 -> V_59 , 0 , true ) )
return 0 ;
if ( F_76 ( & V_9 -> V_2 ) )
return - V_232 ;
V_231 = F_29 ( V_9 -> V_82 ,
V_233 , V_234 , V_59 ) ;
if ( ! V_231 ) {
V_9 -> V_59 = * V_59 ;
V_9 -> V_41 = V_59 -> V_58 . V_41 ;
V_9 -> V_13 = V_59 -> V_58 . V_13 ;
V_9 -> V_12 = V_59 -> V_58 . V_41 * V_9 -> V_42 ;
}
return V_231 ;
}
static int F_77 ( struct V_175 * V_175 , void * V_176 ,
struct V_230 * V_59 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
if ( V_9 -> V_113 == 1 ) {
* V_59 = V_228 ;
return 0 ;
}
return F_29 ( V_9 -> V_82 ,
V_233 , V_235 , V_59 ) ;
}
static int F_78 ( struct V_175 * V_175 , void * V_176 ,
struct V_230 * V_59 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
if ( V_9 -> V_113 == 1 ) {
* V_59 = V_228 ;
return 0 ;
}
return F_29 ( V_9 -> V_82 ,
V_233 , V_236 , V_59 ) ;
}
static int F_79 ( struct V_175 * V_175 , void * V_176 ,
struct V_237 * V_238 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
V_238 -> V_83 = 0 ;
return F_29 ( V_9 -> V_82 ,
V_83 , V_239 , V_238 ) ;
}
static int F_80 ( struct V_175 * V_175 , void * V_176 ,
struct V_240 * V_241 )
{
switch ( V_241 -> V_29 ) {
case 0 :
F_64 ( V_241 -> V_242 , L_57 , sizeof( V_241 -> V_242 ) ) ;
V_241 -> V_243 = V_78 ;
break;
case 1 :
F_64 ( V_241 -> V_242 , L_58 , sizeof( V_241 -> V_242 ) ) ;
V_241 -> V_243 = V_116 ;
break;
case 2 :
F_64 ( V_241 -> V_242 , L_59 , sizeof( V_241 -> V_242 ) ) ;
V_241 -> V_243 = V_64 ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_81 ( struct V_175 * V_175 , void * V_176 ,
struct V_244 * V_241 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
struct V_245 * V_246 = & V_241 -> V_62 . V_246 ;
struct V_66 V_67 ;
V_246 -> V_41 = V_9 -> V_41 ;
V_246 -> V_13 = V_9 -> V_13 ;
V_246 -> V_247 = V_9 -> V_12 ;
V_246 -> V_45 = V_46 ;
if ( V_9 -> V_113 == 1 ) {
V_246 -> V_74 = V_248 ;
} else {
V_67 . V_83 = V_9 -> V_110 ;
V_67 . V_68 = V_69 ;
F_29 ( V_9 -> V_82 , V_83 , V_249 , NULL , & V_67 ) ;
F_82 ( V_246 , & V_67 . V_73 ) ;
}
V_246 -> V_243 = V_9 -> V_63 ;
V_246 -> V_250 = V_246 -> V_247 * V_246 -> V_13 ;
return 0 ;
}
static int F_83 ( struct V_175 * V_175 , void * V_176 ,
struct V_244 * V_241 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
struct V_245 * V_246 = & V_241 -> V_62 . V_246 ;
struct V_66 V_67 ;
if ( ( V_246 -> V_41 < 176 ) || ( V_246 -> V_13 < 144 ) ) {
V_246 -> V_41 = 176 ;
V_246 -> V_13 = 144 ;
}
if ( ( V_246 -> V_41 > 1920 ) || ( V_246 -> V_13 > 1080 ) ) {
V_246 -> V_41 = 1920 ;
V_246 -> V_13 = 1080 ;
}
V_246 -> V_41 &= ~ 0x3 ;
V_246 -> V_13 &= ~ 0x1 ;
if ( V_9 -> V_113 == 1 ) {
V_246 -> V_41 = 1920 ;
V_246 -> V_13 = 1080 ;
V_246 -> V_74 = V_248 ;
} else {
V_67 . V_83 = V_9 -> V_110 ;
V_67 . V_68 = V_69 ;
F_29 ( V_9 -> V_82 , V_83 , V_249 , NULL , & V_67 ) ;
F_82 ( V_246 , & V_67 . V_73 ) ;
}
switch ( V_246 -> V_243 ) {
case V_78 :
default:
V_246 -> V_247 = F_84 ( V_246 -> V_247 & ~ 0x3 ,
V_246 -> V_41 * V_251 ) ;
V_246 -> V_243 = V_78 ;
break;
case V_116 :
V_246 -> V_247 = F_84 ( V_246 -> V_247 & ~ 0x3 ,
V_246 -> V_41 * V_252 ) ;
break;
case V_64 :
V_246 -> V_247 = F_84 ( V_246 -> V_247 & ~ 0x3 ,
V_246 -> V_41 * V_253 ) ;
break;
}
V_246 -> V_250 = V_246 -> V_247 * V_246 -> V_13 ;
V_246 -> V_45 = V_46 ;
V_246 -> V_254 = 0 ;
return 0 ;
}
static int F_85 ( struct V_175 * V_175 , void * V_176 ,
struct V_244 * V_241 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
struct V_245 * V_246 = & V_241 -> V_62 . V_246 ;
if ( F_76 ( & V_9 -> V_2 ) )
return - V_232 ;
if ( F_83 ( V_175 , V_176 , V_241 ) )
return - V_15 ;
V_9 -> V_41 = V_246 -> V_41 ;
V_9 -> V_13 = V_246 -> V_13 ;
V_9 -> V_12 = V_246 -> V_247 ;
switch ( V_246 -> V_243 ) {
case V_78 :
V_9 -> V_42 = V_251 ;
break;
case V_116 :
V_9 -> V_42 = V_252 ;
break;
case V_64 :
V_9 -> V_42 = V_253 ;
break;
default:
return - V_15 ;
}
V_9 -> V_63 = V_246 -> V_243 ;
F_31 ( V_9 ) ;
return 0 ;
}
static int F_86 ( struct V_175 * V_175 , void * V_176 ,
struct V_244 * V_241 )
{
struct V_245 * V_246 = & V_241 -> V_62 . V_246 ;
if ( ( V_246 -> V_41 < 176 ) || ( V_246 -> V_13 < 144 ) ) {
V_246 -> V_41 = 176 ;
V_246 -> V_13 = 144 ;
}
if ( ( V_246 -> V_41 > 1920 ) || ( V_246 -> V_13 > 1080 ) ) {
V_246 -> V_41 = 1920 ;
V_246 -> V_13 = 1080 ;
}
V_246 -> V_41 &= ~ 0x3 ;
V_246 -> V_13 &= ~ 0x1 ;
switch ( V_246 -> V_243 ) {
case V_78 :
default:
V_246 -> V_247 = F_84 ( V_246 -> V_247 & ~ 0x3 ,
V_246 -> V_41 * V_251 ) ;
V_246 -> V_243 = V_78 ;
break;
case V_64 :
V_246 -> V_247 = F_84 ( V_246 -> V_247 & ~ 0x3 ,
V_246 -> V_41 * V_253 ) ;
break;
}
V_246 -> V_250 = V_246 -> V_247 * V_246 -> V_13 ;
V_246 -> V_45 = V_46 ;
return 0 ;
}
static int F_87 ( struct V_175 * V_175 , void * V_176 ,
struct V_244 * V_241 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
struct V_245 * V_246 = & V_241 -> V_62 . V_246 ;
V_246 -> V_41 = V_9 -> V_41 ;
V_246 -> V_13 = V_9 -> V_13 ;
V_246 -> V_247 = V_9 -> V_12 ;
V_246 -> V_45 = V_46 ;
V_246 -> V_243 = V_9 -> V_63 ;
V_246 -> V_74 = V_9 -> V_74 ;
V_246 -> V_75 = V_9 -> V_75 ;
V_246 -> V_76 = V_9 -> V_76 ;
V_246 -> V_77 = V_9 -> V_77 ;
V_246 -> V_250 = V_246 -> V_247 * V_246 -> V_13 ;
return 0 ;
}
static int F_88 ( struct V_175 * V_175 , void * V_176 ,
struct V_240 * V_241 )
{
switch ( V_241 -> V_29 ) {
case 0 :
F_64 ( V_241 -> V_242 , L_57 , sizeof( V_241 -> V_242 ) ) ;
V_241 -> V_243 = V_78 ;
break;
case 1 :
F_64 ( V_241 -> V_242 , L_59 , sizeof( V_241 -> V_242 ) ) ;
V_241 -> V_243 = V_64 ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_89 ( struct V_175 * V_175 , void * V_176 ,
struct V_244 * V_241 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
struct V_245 * V_246 = & V_241 -> V_62 . V_246 ;
struct V_66 V_67 = { 0 } ;
T_4 V_79 ;
if ( F_86 ( V_175 , V_176 , V_241 ) )
return - V_15 ;
if ( F_76 ( & V_9 -> V_2 ) && ( V_246 -> V_243 != V_9 -> V_63 ||
V_246 -> V_41 != V_9 -> V_41 || V_246 -> V_13 != V_9 -> V_13 ||
V_246 -> V_247 != V_9 -> V_12 ) )
return - V_232 ;
switch ( V_246 -> V_243 ) {
case V_78 :
V_9 -> V_42 = V_251 ;
V_79 = V_80 ;
break;
case V_64 :
V_9 -> V_42 = V_253 ;
V_79 = V_81 ;
break;
default:
return - V_15 ;
}
V_9 -> V_41 = V_246 -> V_41 ;
V_9 -> V_13 = V_246 -> V_13 ;
V_9 -> V_12 = V_246 -> V_247 ;
V_9 -> V_63 = V_246 -> V_243 ;
V_9 -> V_74 = V_246 -> V_74 ;
V_9 -> V_75 = V_246 -> V_75 ;
V_9 -> V_76 = V_246 -> V_76 ;
V_9 -> V_77 = V_246 -> V_77 ;
V_67 . V_68 = V_69 ;
F_90 ( & V_67 . V_73 , V_246 , V_79 ) ;
F_29 ( V_9 -> V_82 , V_83 , V_84 , NULL , & V_67 ) ;
return 0 ;
}
static int F_91 ( struct V_175 * V_175 , void * V_176 ,
struct V_255 * V_256 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
if ( V_256 -> V_29 > 1 )
return - V_15 ;
if ( V_256 -> V_29 == 0 )
snprintf ( V_256 -> V_257 , sizeof( V_256 -> V_257 ) ,
L_60 , V_9 -> V_106 ) ;
else
snprintf ( V_256 -> V_257 , sizeof( V_256 -> V_257 ) ,
L_61 , V_9 -> V_106 ) ;
V_256 -> type = V_258 ;
V_256 -> V_188 = V_259 ;
if ( V_256 -> V_29 == 1 )
return 0 ;
return F_29 ( V_9 -> V_82 ,
V_233 , V_260 , & V_256 -> V_195 ) ;
}
static int F_92 ( struct V_175 * V_175 , void * V_176 , unsigned int * V_51 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
* V_51 = V_9 -> V_113 ;
return 0 ;
}
static int F_93 ( struct V_175 * V_175 , void * V_176 , unsigned int V_51 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
if ( V_51 >= 2 )
return - V_15 ;
if ( F_76 ( & V_9 -> V_2 ) )
return - V_232 ;
V_9 -> V_113 = V_51 ;
F_31 ( V_9 ) ;
if ( V_9 -> V_113 == 1 )
return 0 ;
return F_29 ( V_9 -> V_82 , V_233 , V_261 ,
V_262 , 0 , 0 ) ;
}
static int F_94 ( struct V_175 * V_175 , void * V_176 ,
struct V_263 * V_264 )
{
if ( V_264 -> V_29 )
return - V_15 ;
snprintf ( V_264 -> V_257 , sizeof( V_264 -> V_257 ) , L_60 , V_264 -> V_29 ) ;
V_264 -> type = V_265 ;
V_264 -> V_188 = V_266 ;
return 0 ;
}
static int F_95 ( struct V_175 * V_175 , void * V_176 , unsigned int * V_51 )
{
* V_51 = 0 ;
return 0 ;
}
static int F_96 ( struct V_175 * V_175 , void * V_176 , unsigned int V_51 )
{
return V_51 ? - V_15 : 0 ;
}
static int F_97 ( struct V_175 * V_175 , void * V_267 , struct V_268 * V_269 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
T_4 V_83 = V_269 -> V_83 ;
int V_32 ;
if ( V_269 -> V_83 >= ( V_9 -> V_39 ? 1 : 2 ) )
return - V_15 ;
V_269 -> V_83 = 0 ;
V_32 = F_29 ( V_9 -> V_82 , V_83 , V_270 , V_269 ) ;
V_269 -> V_83 = V_83 ;
return V_32 ;
}
static int F_98 ( struct V_175 * V_175 , void * V_267 , struct V_268 * V_269 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
T_4 V_83 = V_269 -> V_83 ;
int V_32 ;
if ( V_269 -> V_83 >= 2 )
return - V_15 ;
V_269 -> V_83 = 0 ;
V_32 = F_29 ( V_9 -> V_82 , V_83 , V_271 , V_269 ) ;
V_269 -> V_83 = V_83 ;
return V_32 ;
}
static int F_99 ( struct V_272 * V_267 ,
const struct V_273 * V_274 )
{
switch ( V_274 -> type ) {
case V_275 :
return F_100 ( V_267 , V_274 , 4 , NULL ) ;
}
return F_101 ( V_267 , V_274 ) ;
}
static int F_102 ( struct V_175 * V_175 , void * V_267 , struct V_276 * V_277 )
{
if ( V_277 -> type != V_278 )
return - V_15 ;
V_277 -> V_279 . V_280 . V_281 . V_282 = 1 ;
V_277 -> V_279 . V_280 . V_281 . V_283 = 60 ;
V_277 -> V_279 . V_280 . V_284 = 3 ;
return 0 ;
}
static int F_103 ( struct V_175 * V_175 , void * V_267 , struct V_285 * V_286 )
{
struct V_8 * V_9 = F_61 ( V_175 ) ;
struct V_230 V_59 ;
int V_231 = 0 ;
if ( V_286 -> type != V_278 )
return - V_15 ;
if ( V_9 -> V_113 == 1 )
V_59 = V_228 ;
else
V_231 = F_29 ( V_9 -> V_82 , V_233 , V_235 , & V_59 ) ;
if ( ! V_231 ) {
V_286 -> V_287 . V_41 = V_286 -> V_288 . V_41 = V_59 . V_58 . V_41 ;
V_286 -> V_287 . V_13 = V_286 -> V_288 . V_13 = V_59 . V_58 . V_13 ;
V_286 -> V_289 = F_104 ( & V_59 ) ;
}
return V_231 ;
}
static int F_105 ( struct V_18 * V_18 , int V_290 )
{
static const struct V_230 V_291 =
V_292 ;
struct V_8 * V_9 = V_18 -> V_293 + V_290 ;
struct V_294 * V_295 = & V_9 -> V_295 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_32 ;
F_106 ( & V_9 -> V_296 ) ;
F_107 ( & V_9 -> V_55 ) ;
snprintf ( V_295 -> V_257 , sizeof( V_295 -> V_257 ) ,
L_62 , V_18 -> V_297 . V_257 , V_290 ) ;
V_9 -> V_41 = 1920 ;
V_9 -> V_13 = V_9 -> V_36 ? 4 : 1080 ;
if ( V_9 -> V_36 ) {
V_9 -> V_42 = 1 ;
V_9 -> V_63 = V_298 ;
} else if ( V_9 -> V_39 ) {
V_9 -> V_42 = V_253 ;
V_9 -> V_63 = V_64 ;
} else {
V_9 -> V_42 = V_251 ;
V_9 -> V_63 = V_78 ;
}
V_9 -> V_74 = V_248 ;
V_9 -> V_12 = V_9 -> V_41 * V_9 -> V_42 ;
if ( ! V_9 -> V_36 ) {
if ( V_9 -> V_299 )
F_108 ( L_63 , V_290 ) ;
V_295 -> V_297 = & V_18 -> V_297 ;
if ( V_9 -> V_299 )
V_295 -> V_300 = & V_301 ;
else
V_295 -> V_300 = V_9 -> V_39 ? & V_302 :
& V_303 ;
V_295 -> V_304 = V_305 ;
V_295 -> V_306 = V_9 -> V_39 ? V_307 : V_308 ;
V_295 -> V_296 = & V_9 -> V_296 ;
if ( V_9 -> V_82 )
V_295 -> V_309 = V_9 -> V_82 -> V_309 ;
V_9 -> V_59 = V_291 ;
F_29 ( V_9 -> V_82 , V_233 , V_234 , & V_9 -> V_59 ) ;
if ( ! V_9 -> V_39 && V_9 -> V_82 )
F_31 ( V_9 ) ;
V_295 -> V_310 = V_9 -> V_299 ? & V_311 :
& V_312 ;
}
F_109 ( & V_9 -> V_56 ) ;
V_2 -> type = V_9 -> V_39 ? V_313 :
V_278 ;
V_2 -> V_314 = V_315 | V_316 | V_317 ;
V_2 -> V_314 |= V_9 -> V_39 ? V_318 : V_319 ;
V_2 -> V_10 = V_9 ;
V_2 -> V_320 = sizeof( struct V_47 ) ;
V_2 -> V_321 = & V_322 ;
V_2 -> V_323 = & V_324 ;
V_2 -> V_325 = V_326 ;
V_2 -> V_327 = 2 ;
V_2 -> V_296 = & V_9 -> V_296 ;
V_2 -> V_34 = & V_18 -> V_35 -> V_34 ;
V_295 -> V_328 = V_2 ;
F_110 ( V_295 , V_9 ) ;
V_32 = F_111 ( V_2 ) ;
if ( ! V_9 -> V_36 && V_32 == 0 )
V_32 = F_112 ( V_295 , V_329 , - 1 ) ;
else if ( ! V_9 -> V_299 )
V_32 = F_113 ( V_9 ) ;
if ( V_32 < 0 ) {
if ( ! V_9 -> V_36 )
F_28 ( L_64 ,
V_290 ) ;
return V_32 ;
}
F_5 ( L_65 , V_290 ) ;
return 0 ;
}
int F_114 ( struct V_18 * V_18 )
{
int V_290 , V_32 ;
for ( V_290 = 0 ; V_290 < V_330 ; V_290 ++ ) {
V_32 = F_105 ( V_18 , V_290 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
void F_115 ( struct V_18 * V_18 )
{
int V_290 ;
for ( V_290 = 0 ; V_290 < V_330 ; V_290 ++ ) {
struct V_8 * V_9 = V_18 -> V_293 + V_290 ;
struct V_294 * V_295 = & V_9 -> V_295 ;
if ( ! V_9 -> V_36 )
F_116 ( V_295 ) ;
else if ( ! V_9 -> V_299 )
F_117 ( V_9 ) ;
}
}
