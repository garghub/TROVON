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
if ( ! F_26 ( V_18 , V_58 -> V_70 ) ) {
F_27 ( L_2 ) ;
return;
}
V_67 . V_71 . V_72 = V_9 -> V_72 ;
V_67 . V_71 . V_73 = V_9 -> V_73 ;
V_67 . V_71 . V_74 = V_9 -> V_74 ;
V_67 . V_71 . V_75 = V_9 -> V_75 ;
V_67 . V_71 . V_41 = V_58 -> V_41 ;
V_67 . V_71 . V_13 = V_58 -> V_13 ;
switch ( V_9 -> V_63 ) {
case V_76 :
V_67 . V_71 . V_77 = V_78 ;
break;
case V_64 :
V_67 . V_71 . V_77 = V_79 ;
break;
}
F_28 ( V_9 -> V_80 , V_81 , V_82 , NULL , & V_67 ) ;
F_29 ( 0 , & V_61 -> V_83 ) ;
F_29 ( V_58 -> V_84 , & V_61 -> V_85 ) ;
F_29 ( V_58 -> V_86 , & V_61 -> V_87 ) ;
F_29 ( V_58 -> V_41 , & V_61 -> V_88 ) ;
F_29 ( V_58 -> V_89 , & V_61 -> V_90 ) ;
F_29 ( V_58 -> V_91 , & V_61 -> V_92 ) ;
F_29 ( V_58 -> V_93 , & V_61 -> V_94 ) ;
F_29 ( V_58 -> V_13 , & V_61 -> V_95 ) ;
F_29 ( V_58 -> V_96 , & V_61 -> V_97 ) ;
F_29 ( 0x9900c1 , & V_61 -> V_98 ) ;
F_29 ( V_99 | V_62 ,
& V_61 -> V_83 ) ;
F_29 ( V_100 | V_62 , & V_61 -> V_83 ) ;
F_29 ( V_101 |
V_102 |
V_62 , & V_61 -> V_83 ) ;
}
static void F_30 ( struct V_8 * V_9 )
{
struct V_18 * V_18 = V_9 -> V_18 ;
int V_103 = ( int ) V_9 -> V_104 ;
struct V_105 T_2 * V_106 ;
struct V_66 V_107 = {
. V_81 = V_9 -> V_108 ,
. V_68 = V_69 ,
. V_71 . V_77 = V_109 ,
} ;
struct V_66 V_110 = {
. V_81 = V_9 -> V_108 ,
. V_68 = V_69 ,
. V_71 . V_77 = V_79 ,
} ;
F_31 ( 1 , L_3 ,
V_9 -> V_104 ,
V_9 -> V_111 == 0 ? L_4 : L_5 ,
L_6 ) ;
V_106 = F_32 ( V_18 , V_103 ) ;
switch ( V_9 -> V_63 ) {
case V_76 :
F_29 ( V_112 |
( 1 << V_113 ) ,
& V_106 -> V_83 ) ;
F_28 ( V_9 -> V_80 , V_81 , V_82 , NULL ,
& V_107 ) ;
break;
case V_114 :
F_29 ( V_112 |
( 2 << V_113 ) ,
& V_106 -> V_83 ) ;
F_28 ( V_9 -> V_80 , V_81 , V_82 , NULL ,
& V_110 ) ;
break;
case V_64 :
F_29 ( V_112 |
V_115 |
( 3 << V_113 ) ,
& V_106 -> V_83 ) ;
F_28 ( V_9 -> V_80 , V_81 , V_82 , NULL ,
& V_110 ) ;
break;
}
}
static void F_33 ( struct V_8 * V_9 )
{
struct V_18 * V_18 = V_9 -> V_18 ;
int V_116 = V_9 -> V_104 ;
struct V_117 T_2 * V_118 =
F_34 ( V_18 , V_116 ) ;
struct V_47 * V_48 ;
unsigned long V_54 ;
F_21 ( & V_9 -> V_55 , V_54 ) ;
if ( ! V_9 -> V_39 ) {
F_29 ( V_119 , & V_118 -> V_83 ) ;
F_29 ( V_120 , & V_118 -> V_83 ) ;
} else {
struct V_60 T_2 * V_61 =
F_25 ( V_18 ) ;
T_3 V_121 = F_35 ( & V_61 -> V_83 ) ;
V_121 &= ~ ( V_122 |
V_100 ) ;
F_29 ( V_121 | V_100 ,
& V_61 -> V_83 ) ;
F_29 ( V_121 | V_122 ,
& V_61 -> V_83 ) ;
}
V_48 = F_36 ( & V_9 -> V_56 , struct V_47 , V_52 ) ;
F_37 ( V_9 , & V_9 -> V_28 [ V_48 -> V_17 . V_53 . V_29 ] ) ;
F_23 ( & V_9 -> V_55 , V_54 ) ;
}
static int F_38 ( struct V_1 * V_2 , unsigned int V_123 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_18 * V_18 = V_9 -> V_18 ;
struct V_124 T_2 * V_125 ;
struct V_126 T_2 * V_127 ;
struct V_128 T_2 * V_129 ;
int V_116 = V_9 -> V_104 ;
struct V_130 T_2 * V_131 = F_39 ( V_18 , V_116 ) ;
struct V_117 T_2 * V_118 = F_34 ( V_18 , V_116 ) ;
struct V_57 * V_58 = & V_9 -> V_59 . V_58 ;
T_4 V_132 ;
T_3 V_133 ;
if ( V_9 -> V_36 )
goto V_134;
if ( V_9 -> V_39 ) {
V_9 -> V_135 = false ;
F_24 ( V_9 ) ;
goto V_134;
}
F_30 ( V_9 ) ;
V_127 = F_40 ( V_18 , V_116 ) ;
V_125 = F_41 ( V_18 , V_116 ) ;
V_129 = F_42 ( V_18 , V_116 ) ;
F_29 ( V_119 , & V_118 -> V_83 ) ;
F_29 ( V_120 , & V_118 -> V_83 ) ;
F_29 ( V_58 -> V_41 , & V_131 -> V_136 ) ;
F_29 ( V_58 -> V_13 , & V_131 -> V_137 ) ;
V_132 = F_43 ( V_58 ) * F_44 ( V_58 ) ;
F_29 ( F_45 ( ( T_4 ) F_43 ( V_58 ) * V_138 * 4 ,
V_58 -> V_70 ) , & V_125 -> V_139 ) ;
F_29 ( V_140 , & V_125 -> V_83 ) ;
V_133 = F_35 ( & V_127 -> V_133 ) ;
F_29 ( V_133 / 1000000 , & V_129 -> V_141 ) ;
F_29 ( F_45 ( V_58 -> V_70 * 995 , 1000000000 ) ,
& V_129 -> V_142 ) ;
F_29 ( V_58 -> V_41 * V_58 -> V_13 , & V_127 -> V_143 ) ;
F_29 ( F_45 ( ( T_4 ) V_133 * V_132 , V_58 -> V_70 ) ,
& V_127 -> V_144 ) ;
F_29 ( V_145 |
V_146 ,
& V_125 -> V_147 ) ;
F_29 ( 0 , & V_131 -> V_83 ) ;
F_29 ( V_140 , & V_125 -> V_83 ) ;
F_29 ( 0xff , & V_127 -> V_148 ) ;
F_29 ( V_149 , & V_129 -> V_121 ) ;
F_29 ( V_150 |
V_151 , & V_127 -> V_121 ) ;
V_9 -> V_135 = true ;
V_9 -> V_152 = false ;
V_9 -> V_153 = false ;
V_9 -> V_154 = 0 ;
V_134:
V_9 -> V_155 = 0 ;
F_33 ( V_9 ) ;
return 0 ;
}
static void F_46 ( struct V_8 * V_9 )
{
struct V_18 * V_18 = V_9 -> V_18 ;
struct V_26 * V_27 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
unsigned long V_54 ;
int V_156 = 100 ;
int V_116 = V_9 -> V_104 ;
struct V_117 T_2 * V_118 =
F_34 ( V_18 , V_116 ) ;
if ( ! V_9 -> V_39 ) {
F_29 ( 0 , & V_118 -> V_83 ) ;
} else if ( ! V_9 -> V_36 ) {
struct V_60 T_2 * V_61 =
F_25 ( V_18 ) ;
F_29 ( V_100 , & V_61 -> V_83 ) ;
F_29 ( 0 , & V_61 -> V_83 ) ;
}
F_21 ( & V_9 -> V_55 , V_54 ) ;
F_14 (p, &s->bufs) {
V_48 = F_15 ( V_50 , struct V_47 , V_52 ) ;
V_27 = & V_9 -> V_28 [ V_48 -> V_17 . V_53 . V_29 ] ;
F_47 ( V_27 ) ;
}
F_23 ( & V_9 -> V_55 , V_54 ) ;
if ( ! F_48 ( V_9 -> V_2 . V_157 , F_49 ( V_9 ) ,
F_50 ( V_156 ) ) ) {
F_51 ( V_9 ) ;
F_52 ( L_7 ) ;
}
F_53 ( V_18 , V_158 ,
1 << V_9 -> V_159 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_18 * V_18 = V_9 -> V_18 ;
int V_116 = V_9 -> V_104 ;
struct V_124 T_2 * V_125 ;
struct V_126 T_2 * V_127 ;
struct V_128 T_2 * V_129 ;
struct V_47 * V_48 ;
struct V_49 * V_50 , * V_160 ;
unsigned long V_54 ;
F_46 ( V_9 ) ;
F_21 ( & V_9 -> V_55 , V_54 ) ;
F_55 (p, safe, &s->bufs) {
V_48 = F_15 ( V_50 , struct V_47 , V_52 ) ;
F_56 ( & V_48 -> V_52 ) ;
F_57 ( & V_48 -> V_17 . V_53 , V_161 ) ;
}
F_23 ( & V_9 -> V_55 , V_54 ) ;
if ( V_9 -> V_36 || V_9 -> V_39 )
return;
V_127 = F_40 ( V_18 , V_116 ) ;
V_125 = F_41 ( V_18 , V_116 ) ;
V_129 = F_42 ( V_18 , V_116 ) ;
F_29 ( 0 , & V_125 -> V_83 ) ;
F_29 ( V_140 , & V_125 -> V_83 ) ;
F_29 ( 0 , & V_127 -> V_121 ) ;
F_29 ( 0 , & V_129 -> V_121 ) ;
}
static int F_58 ( struct V_18 * V_18 , unsigned int V_162 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
void T_2 * V_166 = V_18 -> V_167 + V_165 -> V_168 ;
F_5 ( L_8 , V_166 ) ;
if ( ! F_59 ( V_169 ) )
return - V_170 ;
V_165 -> V_11 = 4 ;
if ( V_162 == V_171 )
F_29 ( V_165 -> V_172 , V_166 ) ;
else
V_165 -> V_172 = F_35 ( V_166 ) ;
return 0 ;
}
static int F_60 ( struct V_173 * V_173 , void * V_174 ,
struct V_164 * V_168 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
struct V_18 * V_18 = V_9 -> V_18 ;
return F_58 ( V_18 , V_175 , V_168 ) ;
}
static int F_62 ( struct V_173 * V_173 , void * V_174 ,
const struct V_164 * V_168 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
struct V_18 * V_18 = V_9 -> V_18 ;
return F_58 ( V_18 , V_171 ,
(struct V_164 * ) V_168 ) ;
}
static int F_63 ( struct V_173 * V_173 , void * V_174 ,
struct V_176 * V_177 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
struct V_18 * V_18 = V_9 -> V_18 ;
F_64 ( V_177 -> V_178 , L_9 , sizeof( V_177 -> V_178 ) ) ;
F_64 ( V_177 -> V_179 , L_9 , sizeof( V_177 -> V_179 ) ) ;
snprintf ( V_177 -> V_180 , sizeof( V_177 -> V_180 ) ,
L_10 , F_65 ( V_18 -> V_35 ) ) ;
V_177 -> V_181 = V_182 | V_183 ;
if ( V_9 -> V_39 )
V_177 -> V_181 |= V_184 ;
else
V_177 -> V_181 |= V_185 ;
V_177 -> V_186 = V_177 -> V_181 | V_187 |
V_185 ;
if ( V_18 -> V_188 )
V_177 -> V_186 |= V_184 ;
return 0 ;
}
static void F_66 ( struct V_8 * V_9 )
{
struct V_130 T_2 * V_131 ;
struct V_124 T_2 * V_125 ;
struct V_126 T_2 * V_127 ;
struct V_128 T_2 * V_129 ;
struct V_105 T_2 * V_106 ;
int V_116 = V_9 -> V_104 ;
struct V_18 * V_18 = V_9 -> V_18 ;
T_3 V_189 , V_190 ;
T_3 V_191 , V_192 ;
V_131 = F_39 ( V_18 , V_116 ) ;
V_125 = F_41 ( V_18 , V_116 ) ;
V_127 = F_40 ( V_18 , V_116 ) ;
V_129 = F_42 ( V_18 , V_116 ) ;
V_106 = F_32 ( V_18 , V_116 ) ;
V_189 = F_35 ( & V_131 -> V_83 ) ;
V_190 = F_35 ( & V_131 -> V_193 ) ;
V_191 = F_35 ( & V_125 -> V_83 ) ;
V_192 = F_35 ( & V_125 -> V_83 ) ;
F_5 ( L_11 , V_116 ,
F_35 ( & V_131 -> V_136 ) , F_35 ( & V_131 -> V_137 ) ) ;
F_5 ( L_12 , V_116 ,
( V_189 & V_194 ) ?
L_13 : L_14 ,
( V_189 & V_195 ) ?
L_15 : L_16 ,
( V_189 & V_196 ) ?
L_17 : L_18 ) ;
F_5 ( L_19 , V_116 ,
( V_190 & V_197 ) ?
L_20 : L_21 ,
( V_190 & V_198 ) ?
L_22 : L_23 ) ;
F_5 ( L_24 , V_116 ,
( V_191 & V_199 ) ?
L_15 : L_16 ,
( V_191 & V_200 ) ?
L_17 : L_18 ,
( V_191 & V_140 ) ?
L_25 : L_26 ,
( V_191 & V_201 ) ?
L_27 : L_28 ,
( V_191 & V_202 ) ?
L_29 : L_30 ,
( V_192 & V_203 ) ?
L_31 : L_30 ,
( V_192 & V_204 ) ?
L_32 : L_30 ) ;
F_5 ( L_33 , V_116 ,
F_35 ( & V_125 -> V_205 ) & 0xff ,
F_35 ( & V_125 -> V_147 ) & 0xff ) ;
F_5 ( L_34 , V_116 , F_35 ( & V_125 -> V_206 ) ) ;
F_5 ( L_35 , V_116 , F_35 ( & V_125 -> V_207 ) ) ;
F_5 ( L_36 , V_116 , F_35 ( & V_125 -> V_208 ) ) ;
F_5 ( L_37 , V_116 , F_35 ( & V_125 -> V_209 ) ) ;
F_5 ( L_38 , V_116 , F_35 ( & V_125 -> V_210 ) ) ;
F_5 ( L_39 , V_116 , F_35 ( & V_125 -> V_211 ) ) ;
F_5 ( L_40 , V_116 , F_35 ( & V_125 -> V_212 ) ) ;
F_5 ( L_41 , V_116 , F_35 ( & V_125 -> V_213 ) ) ;
F_5 ( L_42 , V_116 ,
( F_35 ( & V_127 -> V_121 ) & V_150 ) ?
L_25 : L_26 ,
( F_35 ( & V_127 -> V_121 ) & V_151 ) ?
L_43 : L_30 ,
( F_35 ( & V_127 -> V_193 ) & V_214 ) ?
L_44 : L_45 ) ;
F_29 ( 0xff , & V_125 -> V_205 ) ;
F_5 ( L_46 , V_116 ,
( F_35 ( & V_129 -> V_121 ) & V_149 ) ?
L_25 : L_26 ,
( F_35 ( & V_129 -> V_193 ) & V_215 ) ?
L_47 : L_48 ) ;
F_5 ( L_49 , V_116 , F_35 ( & V_106 -> V_83 ) ) ;
}
static int F_67 ( struct V_173 * V_173 , void * V_174 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
struct V_18 * V_18 = V_9 -> V_18 ;
struct V_60 T_2 * V_61 =
F_25 ( V_18 ) ;
T_5 V_216 ;
F_5 ( L_50 , V_18 -> V_217 ) ;
F_5 ( L_51 ,
F_68 ( V_18 ) ,
F_69 ( V_18 ) ) ;
F_5 ( L_52 ,
V_9 -> V_159 , V_9 -> V_104 ) ;
F_70 ( V_18 ) ;
F_71 ( V_18 ) ;
F_72 ( V_18 ) ;
F_28 ( V_9 -> V_80 , V_218 , V_219 ) ;
if ( ! V_9 -> V_39 ) {
F_66 ( V_9 ) ;
return 0 ;
}
V_216 = F_35 ( & V_61 -> V_220 ) ;
F_5 ( L_53 ,
( V_216 & V_221 ) ?
L_54 : L_30 ,
( V_216 & V_222 ) ?
L_55 : L_30 ) ;
F_5 ( L_56 , F_35 ( & V_61 -> V_223 ) ) ;
return 0 ;
}
static int F_73 ( struct V_173 * V_173 , void * V_174 ,
struct V_224 * V_59 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
if ( V_9 -> V_111 == 1 ) {
if ( V_59 -> V_29 )
return - V_15 ;
memset ( V_59 -> V_225 , 0 , sizeof( V_59 -> V_225 ) ) ;
V_59 -> V_59 = V_226 ;
return 0 ;
}
V_59 -> V_81 = 0 ;
return F_28 ( V_9 -> V_80 ,
V_81 , V_227 , V_59 ) ;
}
static int F_74 ( struct V_173 * V_173 , void * V_174 ,
struct V_228 * V_59 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
int V_229 ;
if ( V_9 -> V_111 == 1 ) {
* V_59 = V_226 ;
return 0 ;
}
if ( F_75 ( V_59 , & V_9 -> V_59 , 0 , false ) )
return 0 ;
if ( F_76 ( & V_9 -> V_2 ) )
return - V_230 ;
V_229 = F_28 ( V_9 -> V_80 ,
V_231 , V_232 , V_59 ) ;
if ( ! V_229 ) {
V_9 -> V_59 = * V_59 ;
V_9 -> V_41 = V_59 -> V_58 . V_41 ;
V_9 -> V_13 = V_59 -> V_58 . V_13 ;
V_9 -> V_12 = V_59 -> V_58 . V_41 * V_9 -> V_42 ;
}
return V_229 ;
}
static int F_77 ( struct V_173 * V_173 , void * V_174 ,
struct V_228 * V_59 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
if ( V_9 -> V_111 == 1 ) {
* V_59 = V_226 ;
return 0 ;
}
return F_28 ( V_9 -> V_80 ,
V_231 , V_233 , V_59 ) ;
}
static int F_78 ( struct V_173 * V_173 , void * V_174 ,
struct V_228 * V_59 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
if ( V_9 -> V_111 == 1 ) {
* V_59 = V_226 ;
return 0 ;
}
return F_28 ( V_9 -> V_80 ,
V_231 , V_234 , V_59 ) ;
}
static int F_79 ( struct V_173 * V_173 , void * V_174 ,
struct V_235 * V_236 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
V_236 -> V_81 = 0 ;
return F_28 ( V_9 -> V_80 ,
V_81 , V_237 , V_236 ) ;
}
static int F_80 ( struct V_173 * V_173 , void * V_174 ,
struct V_238 * V_239 )
{
switch ( V_239 -> V_29 ) {
case 0 :
F_64 ( V_239 -> V_240 , L_57 , sizeof( V_239 -> V_240 ) ) ;
V_239 -> V_241 = V_76 ;
break;
case 1 :
F_64 ( V_239 -> V_240 , L_58 , sizeof( V_239 -> V_240 ) ) ;
V_239 -> V_241 = V_114 ;
break;
case 2 :
F_64 ( V_239 -> V_240 , L_59 , sizeof( V_239 -> V_240 ) ) ;
V_239 -> V_241 = V_64 ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_81 ( struct V_173 * V_173 , void * V_174 ,
struct V_242 * V_239 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
struct V_243 * V_244 = & V_239 -> V_62 . V_244 ;
struct V_66 V_67 ;
V_244 -> V_41 = V_9 -> V_41 ;
V_244 -> V_13 = V_9 -> V_13 ;
V_244 -> V_245 = V_9 -> V_12 ;
V_244 -> V_45 = V_46 ;
if ( V_9 -> V_111 == 1 ) {
V_244 -> V_72 = V_246 ;
} else {
V_67 . V_81 = V_9 -> V_108 ;
V_67 . V_68 = V_69 ;
F_28 ( V_9 -> V_80 , V_81 , V_247 , NULL , & V_67 ) ;
F_82 ( V_244 , & V_67 . V_71 ) ;
}
V_244 -> V_241 = V_9 -> V_63 ;
V_244 -> V_248 = V_244 -> V_245 * V_244 -> V_13 ;
return 0 ;
}
static int F_83 ( struct V_173 * V_173 , void * V_174 ,
struct V_242 * V_239 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
struct V_243 * V_244 = & V_239 -> V_62 . V_244 ;
struct V_66 V_67 ;
if ( ( V_244 -> V_41 < 176 ) || ( V_244 -> V_13 < 144 ) ) {
V_244 -> V_41 = 176 ;
V_244 -> V_13 = 144 ;
}
if ( ( V_244 -> V_41 > 1920 ) || ( V_244 -> V_13 > 1080 ) ) {
V_244 -> V_41 = 1920 ;
V_244 -> V_13 = 1080 ;
}
V_244 -> V_41 &= ~ 0x3 ;
V_244 -> V_13 &= ~ 0x1 ;
if ( V_9 -> V_111 == 1 ) {
V_244 -> V_41 = 1920 ;
V_244 -> V_13 = 1080 ;
V_244 -> V_72 = V_246 ;
} else {
V_67 . V_81 = V_9 -> V_108 ;
V_67 . V_68 = V_69 ;
F_28 ( V_9 -> V_80 , V_81 , V_247 , NULL , & V_67 ) ;
F_82 ( V_244 , & V_67 . V_71 ) ;
}
switch ( V_244 -> V_241 ) {
case V_76 :
default:
V_244 -> V_245 = F_84 ( V_244 -> V_245 & ~ 0x3 ,
V_244 -> V_41 * V_249 ) ;
V_244 -> V_241 = V_76 ;
break;
case V_114 :
V_244 -> V_245 = F_84 ( V_244 -> V_245 & ~ 0x3 ,
V_244 -> V_41 * V_250 ) ;
break;
case V_64 :
V_244 -> V_245 = F_84 ( V_244 -> V_245 & ~ 0x3 ,
V_244 -> V_41 * V_251 ) ;
break;
}
V_244 -> V_248 = V_244 -> V_245 * V_244 -> V_13 ;
V_244 -> V_45 = V_46 ;
V_244 -> V_252 = 0 ;
return 0 ;
}
static int F_85 ( struct V_173 * V_173 , void * V_174 ,
struct V_242 * V_239 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
struct V_243 * V_244 = & V_239 -> V_62 . V_244 ;
if ( F_76 ( & V_9 -> V_2 ) )
return - V_230 ;
if ( F_83 ( V_173 , V_174 , V_239 ) )
return - V_15 ;
V_9 -> V_41 = V_244 -> V_41 ;
V_9 -> V_13 = V_244 -> V_13 ;
V_9 -> V_12 = V_244 -> V_245 ;
switch ( V_244 -> V_241 ) {
case V_76 :
V_9 -> V_42 = V_249 ;
break;
case V_114 :
V_9 -> V_42 = V_250 ;
break;
case V_64 :
V_9 -> V_42 = V_251 ;
break;
default:
return - V_15 ;
}
V_9 -> V_63 = V_244 -> V_241 ;
F_30 ( V_9 ) ;
return 0 ;
}
static int F_86 ( struct V_173 * V_173 , void * V_174 ,
struct V_242 * V_239 )
{
struct V_243 * V_244 = & V_239 -> V_62 . V_244 ;
if ( ( V_244 -> V_41 < 176 ) || ( V_244 -> V_13 < 144 ) ) {
V_244 -> V_41 = 176 ;
V_244 -> V_13 = 144 ;
}
if ( ( V_244 -> V_41 > 1920 ) || ( V_244 -> V_13 > 1080 ) ) {
V_244 -> V_41 = 1920 ;
V_244 -> V_13 = 1080 ;
}
V_244 -> V_41 &= ~ 0x3 ;
V_244 -> V_13 &= ~ 0x1 ;
switch ( V_244 -> V_241 ) {
case V_76 :
default:
V_244 -> V_245 = F_84 ( V_244 -> V_245 & ~ 0x3 ,
V_244 -> V_41 * V_249 ) ;
V_244 -> V_241 = V_76 ;
break;
case V_64 :
V_244 -> V_245 = F_84 ( V_244 -> V_245 & ~ 0x3 ,
V_244 -> V_41 * V_251 ) ;
break;
}
V_244 -> V_248 = V_244 -> V_245 * V_244 -> V_13 ;
V_244 -> V_45 = V_46 ;
return 0 ;
}
static int F_87 ( struct V_173 * V_173 , void * V_174 ,
struct V_242 * V_239 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
struct V_243 * V_244 = & V_239 -> V_62 . V_244 ;
V_244 -> V_41 = V_9 -> V_41 ;
V_244 -> V_13 = V_9 -> V_13 ;
V_244 -> V_245 = V_9 -> V_12 ;
V_244 -> V_45 = V_46 ;
V_244 -> V_241 = V_9 -> V_63 ;
V_244 -> V_72 = V_9 -> V_72 ;
V_244 -> V_73 = V_9 -> V_73 ;
V_244 -> V_74 = V_9 -> V_74 ;
V_244 -> V_75 = V_9 -> V_75 ;
V_244 -> V_248 = V_244 -> V_245 * V_244 -> V_13 ;
return 0 ;
}
static int F_88 ( struct V_173 * V_173 , void * V_174 ,
struct V_238 * V_239 )
{
switch ( V_239 -> V_29 ) {
case 0 :
F_64 ( V_239 -> V_240 , L_57 , sizeof( V_239 -> V_240 ) ) ;
V_239 -> V_241 = V_76 ;
break;
case 1 :
F_64 ( V_239 -> V_240 , L_59 , sizeof( V_239 -> V_240 ) ) ;
V_239 -> V_241 = V_64 ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_89 ( struct V_173 * V_173 , void * V_174 ,
struct V_242 * V_239 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
struct V_243 * V_244 = & V_239 -> V_62 . V_244 ;
struct V_66 V_67 = { 0 } ;
T_3 V_77 ;
if ( F_86 ( V_173 , V_174 , V_239 ) )
return - V_15 ;
if ( F_76 ( & V_9 -> V_2 ) && ( V_244 -> V_241 != V_9 -> V_63 ||
V_244 -> V_41 != V_9 -> V_41 || V_244 -> V_13 != V_9 -> V_13 ||
V_244 -> V_245 != V_9 -> V_12 ) )
return - V_230 ;
switch ( V_244 -> V_241 ) {
case V_76 :
V_9 -> V_42 = V_249 ;
V_77 = V_78 ;
break;
case V_64 :
V_9 -> V_42 = V_251 ;
V_77 = V_79 ;
break;
default:
return - V_15 ;
}
V_9 -> V_41 = V_244 -> V_41 ;
V_9 -> V_13 = V_244 -> V_13 ;
V_9 -> V_12 = V_244 -> V_245 ;
V_9 -> V_63 = V_244 -> V_241 ;
V_9 -> V_72 = V_244 -> V_72 ;
V_9 -> V_73 = V_244 -> V_73 ;
V_9 -> V_74 = V_244 -> V_74 ;
V_9 -> V_75 = V_244 -> V_75 ;
V_67 . V_68 = V_69 ;
F_90 ( & V_67 . V_71 , V_244 , V_77 ) ;
F_28 ( V_9 -> V_80 , V_81 , V_82 , NULL , & V_67 ) ;
return 0 ;
}
static int F_91 ( struct V_173 * V_173 , void * V_174 ,
struct V_253 * V_254 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
if ( V_254 -> V_29 > 1 )
return - V_15 ;
if ( V_254 -> V_29 == 0 )
snprintf ( V_254 -> V_255 , sizeof( V_254 -> V_255 ) ,
L_60 , V_9 -> V_104 ) ;
else
snprintf ( V_254 -> V_255 , sizeof( V_254 -> V_255 ) ,
L_61 , V_9 -> V_104 ) ;
V_254 -> type = V_256 ;
V_254 -> V_186 = V_257 ;
if ( V_254 -> V_29 == 1 )
return 0 ;
return F_28 ( V_9 -> V_80 ,
V_231 , V_258 , & V_254 -> V_193 ) ;
}
static int F_92 ( struct V_173 * V_173 , void * V_174 , unsigned int * V_51 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
* V_51 = V_9 -> V_111 ;
return 0 ;
}
static int F_93 ( struct V_173 * V_173 , void * V_174 , unsigned int V_51 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
if ( V_51 >= 2 )
return - V_15 ;
if ( F_76 ( & V_9 -> V_2 ) )
return - V_230 ;
V_9 -> V_111 = V_51 ;
F_30 ( V_9 ) ;
if ( V_9 -> V_111 == 1 )
return 0 ;
return F_28 ( V_9 -> V_80 , V_231 , V_259 ,
V_260 , 0 , 0 ) ;
}
static int F_94 ( struct V_173 * V_173 , void * V_174 ,
struct V_261 * V_262 )
{
if ( V_262 -> V_29 )
return - V_15 ;
snprintf ( V_262 -> V_255 , sizeof( V_262 -> V_255 ) , L_60 , V_262 -> V_29 ) ;
V_262 -> type = V_263 ;
V_262 -> V_186 = V_264 ;
return 0 ;
}
static int F_95 ( struct V_173 * V_173 , void * V_174 , unsigned int * V_51 )
{
* V_51 = 0 ;
return 0 ;
}
static int F_96 ( struct V_173 * V_173 , void * V_174 , unsigned int V_51 )
{
return V_51 ? - V_15 : 0 ;
}
static int F_97 ( struct V_173 * V_173 , void * V_265 , struct V_266 * V_267 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
T_3 V_81 = V_267 -> V_81 ;
int V_32 ;
if ( V_267 -> V_81 >= ( V_9 -> V_39 ? 1 : 2 ) )
return - V_15 ;
V_267 -> V_81 = 0 ;
V_32 = F_28 ( V_9 -> V_80 , V_81 , V_268 , V_267 ) ;
V_267 -> V_81 = V_81 ;
return V_32 ;
}
static int F_98 ( struct V_173 * V_173 , void * V_265 , struct V_266 * V_267 )
{
struct V_8 * V_9 = F_61 ( V_173 ) ;
T_3 V_81 = V_267 -> V_81 ;
int V_32 ;
if ( V_267 -> V_81 >= 2 )
return - V_15 ;
V_267 -> V_81 = 0 ;
V_32 = F_28 ( V_9 -> V_80 , V_81 , V_269 , V_267 ) ;
V_267 -> V_81 = V_81 ;
return V_32 ;
}
static int F_99 ( struct V_270 * V_265 ,
const struct V_271 * V_272 )
{
switch ( V_272 -> type ) {
case V_273 :
return F_100 ( V_265 , V_272 , 4 , NULL ) ;
}
return F_101 ( V_265 , V_272 ) ;
}
static int F_102 ( struct V_173 * V_173 , void * V_265 , struct V_274 * V_275 )
{
if ( V_275 -> type != V_276 )
return - V_15 ;
V_275 -> V_277 . V_278 . V_279 . V_280 = 1 ;
V_275 -> V_277 . V_278 . V_279 . V_281 = 60 ;
V_275 -> V_277 . V_278 . V_282 = 3 ;
return 0 ;
}
static int F_103 ( struct V_18 * V_18 , int V_283 )
{
static const struct V_228 V_284 =
V_285 ;
struct V_8 * V_9 = V_18 -> V_286 + V_283 ;
struct V_287 * V_288 = & V_9 -> V_288 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_32 ;
F_104 ( & V_9 -> V_289 ) ;
F_105 ( & V_9 -> V_55 ) ;
snprintf ( V_288 -> V_255 , sizeof( V_288 -> V_255 ) ,
L_62 , V_18 -> V_290 . V_255 , V_283 ) ;
V_9 -> V_41 = 1920 ;
V_9 -> V_13 = V_9 -> V_36 ? 4 : 1080 ;
if ( V_9 -> V_36 ) {
V_9 -> V_42 = 1 ;
V_9 -> V_63 = V_291 ;
} else if ( V_9 -> V_39 ) {
V_9 -> V_42 = V_251 ;
V_9 -> V_63 = V_64 ;
} else {
V_9 -> V_42 = V_249 ;
V_9 -> V_63 = V_76 ;
}
V_9 -> V_72 = V_246 ;
V_9 -> V_12 = V_9 -> V_41 * V_9 -> V_42 ;
if ( ! V_9 -> V_36 ) {
if ( V_9 -> V_292 )
F_106 ( L_63 , V_283 ) ;
V_288 -> V_290 = & V_18 -> V_290 ;
if ( V_9 -> V_292 )
V_288 -> V_293 = & V_294 ;
else
V_288 -> V_293 = V_9 -> V_39 ? & V_295 :
& V_296 ;
V_288 -> V_297 = V_298 ;
V_288 -> V_299 = V_9 -> V_39 ? V_300 : V_301 ;
V_288 -> V_289 = & V_9 -> V_289 ;
if ( V_9 -> V_80 )
V_288 -> V_302 = V_9 -> V_80 -> V_302 ;
V_9 -> V_59 = V_284 ;
F_28 ( V_9 -> V_80 , V_231 , V_232 , & V_9 -> V_59 ) ;
if ( ! V_9 -> V_39 && V_9 -> V_80 )
F_30 ( V_9 ) ;
V_288 -> V_303 = V_9 -> V_292 ? & V_304 :
& V_305 ;
}
F_107 ( & V_9 -> V_56 ) ;
V_2 -> type = V_9 -> V_39 ? V_306 :
V_276 ;
V_2 -> V_307 = V_308 | V_309 | V_310 ;
V_2 -> V_307 |= V_9 -> V_39 ? V_311 : V_312 ;
V_2 -> V_10 = V_9 ;
V_2 -> V_313 = sizeof( struct V_47 ) ;
V_2 -> V_314 = & V_315 ;
V_2 -> V_316 = & V_317 ;
V_2 -> V_318 = V_319 ;
V_2 -> V_320 = 2 ;
V_2 -> V_289 = & V_9 -> V_289 ;
V_2 -> V_34 = & V_18 -> V_35 -> V_34 ;
V_288 -> V_321 = V_2 ;
F_108 ( V_288 , V_9 ) ;
V_32 = F_109 ( V_2 ) ;
if ( ! V_9 -> V_36 && V_32 == 0 )
V_32 = F_110 ( V_288 , V_322 , - 1 ) ;
else if ( ! V_9 -> V_292 )
V_32 = F_111 ( V_9 ) ;
if ( V_32 < 0 ) {
if ( ! V_9 -> V_36 )
F_27 ( L_64 ,
V_283 ) ;
return V_32 ;
}
F_5 ( L_65 , V_283 ) ;
return 0 ;
}
int F_112 ( struct V_18 * V_18 )
{
int V_283 , V_32 ;
for ( V_283 = 0 ; V_283 < V_323 ; V_283 ++ ) {
V_32 = F_103 ( V_18 , V_283 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
void F_113 ( struct V_18 * V_18 )
{
int V_283 ;
for ( V_283 = 0 ; V_283 < V_323 ; V_283 ++ ) {
struct V_8 * V_9 = V_18 -> V_286 + V_283 ;
struct V_287 * V_288 = & V_9 -> V_288 ;
if ( ! V_9 -> V_36 )
F_114 ( V_288 ) ;
else if ( ! V_9 -> V_292 )
F_115 ( V_9 ) ;
}
}
