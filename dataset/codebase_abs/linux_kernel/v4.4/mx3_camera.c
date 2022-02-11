static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_2 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static struct V_6 * F_5 ( struct V_7 * V_8 )
{
return F_6 ( V_8 , struct V_6 , V_8 ) ;
}
static void F_7 ( void * V_9 )
{
struct V_10 * V_11 = F_8 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 . V_13 ;
struct V_15 * V_16 = F_9 ( V_13 ) ;
struct V_1 * V_17 = V_16 -> V_18 ;
F_10 ( V_13 -> V_19 -> V_20 , L_1 ,
V_11 -> V_14 . V_21 , V_17 -> V_22 ? F_11 ( & V_17 -> V_22 -> V_23 ) : 0 ) ;
F_12 ( & V_17 -> V_24 ) ;
if ( V_17 -> V_22 ) {
struct V_7 * V_8 = & V_17 -> V_22 -> V_8 ;
struct V_6 * V_25 = F_5 ( V_8 ) ;
F_13 ( & V_25 -> V_26 ) ;
F_14 ( & V_8 -> V_27 ) ;
V_8 -> V_28 = V_17 -> V_28 ;
V_8 -> V_29 = V_17 -> V_29 ++ ;
F_15 ( & V_8 -> V_30 , V_31 ) ;
}
if ( F_16 ( & V_17 -> V_32 ) ) {
V_17 -> V_22 = NULL ;
F_17 ( & V_17 -> V_24 ) ;
return;
}
V_17 -> V_22 = F_18 ( V_17 -> V_32 . V_33 ,
struct V_6 , V_26 ) ;
F_17 ( & V_17 -> V_24 ) ;
}
static int F_19 ( struct V_34 * V_35 ,
const void * V_36 ,
unsigned int * V_37 , unsigned int * V_38 ,
unsigned int V_39 [] , void * V_40 [] )
{
const struct V_41 * V_42 = V_36 ;
struct V_43 * V_44 = F_20 ( V_35 ) ;
struct V_45 * V_46 = F_21 ( V_44 -> V_47 ) ;
struct V_1 * V_17 = V_46 -> V_48 ;
if ( ! V_17 -> V_15 [ 0 ] )
return - V_49 ;
if ( V_42 ) {
const struct V_50 * V_51 = F_22 ( V_44 ,
V_42 -> V_42 . V_52 . V_53 ) ;
unsigned int V_54 ;
int V_55 ;
if ( ! V_51 )
return - V_49 ;
V_55 = F_23 ( V_42 -> V_42 . V_52 . V_56 ,
V_51 -> V_57 ) ;
if ( V_55 < 0 )
return V_55 ;
V_54 = F_24 ( T_1 , V_42 -> V_42 . V_52 . V_58 , V_55 ) ;
V_55 = F_25 ( V_51 -> V_57 , V_54 ,
V_42 -> V_42 . V_52 . V_59 ) ;
if ( V_55 < 0 )
return V_55 ;
V_39 [ 0 ] = F_24 ( T_1 , V_42 -> V_42 . V_52 . V_60 , V_55 ) ;
} else {
V_39 [ 0 ] = V_44 -> V_60 ;
}
V_40 [ 0 ] = V_17 -> V_61 ;
if ( ! V_35 -> V_62 )
V_17 -> V_29 = 0 ;
if ( ! * V_37 )
* V_37 = 2 ;
if ( ! * V_38 &&
V_39 [ 0 ] * * V_37 + V_17 -> V_63 > V_64 * 1024 * 1024 )
* V_37 = ( V_64 * 1024 * 1024 - V_17 -> V_63 ) /
V_39 [ 0 ] ;
* V_38 = 1 ;
return 0 ;
}
static enum V_65 F_26 ( T_3 V_66 )
{
switch ( V_66 ) {
case V_67 :
return V_68 ;
case V_69 :
case V_70 :
default:
return V_71 ;
}
}
static void F_27 ( struct V_72 * V_8 )
{
struct V_7 * V_73 = F_28 ( V_8 ) ;
struct V_43 * V_44 = F_20 ( V_8 -> V_34 ) ;
struct V_45 * V_46 = F_21 ( V_44 -> V_47 ) ;
struct V_1 * V_17 = V_46 -> V_48 ;
struct V_6 * V_25 = F_5 ( V_73 ) ;
struct V_74 * V_23 = & V_25 -> V_23 ;
struct V_75 * V_14 ;
struct V_15 * V_76 = V_17 -> V_15 [ 0 ] ;
struct V_77 * V_78 = & V_76 -> V_79 . V_78 ;
const struct V_80 * V_57 = V_44 -> V_81 -> V_57 ;
T_4 V_21 ;
T_5 V_82 ;
V_82 = V_44 -> V_60 ;
if ( F_29 ( V_8 , 0 ) < V_82 ) {
F_30 ( V_44 -> V_47 , L_2 ,
V_73 -> V_30 . V_83 , F_29 ( V_8 , 0 ) , V_82 ) ;
goto error;
}
if ( ! V_25 -> V_14 ) {
F_11 ( V_23 ) = F_31 ( V_8 , 0 ) ;
F_32 ( V_23 ) = V_82 ;
V_14 = F_33 (
& V_76 -> V_12 , V_23 , 1 , V_84 ,
V_85 ) ;
if ( ! V_14 )
goto error;
V_14 -> V_86 = V_14 ;
V_14 -> V_87 = F_7 ;
V_25 -> V_14 = V_14 ;
} else {
V_14 = V_25 -> V_14 ;
}
F_34 ( V_8 , 0 , V_82 ) ;
V_78 -> V_88 = F_26 ( V_57 -> V_66 ) ;
if ( V_78 -> V_88 == V_71 ) {
V_78 -> V_89 = V_44 -> V_58 ;
V_78 -> V_90 = V_44 -> V_91 ;
V_78 -> V_92 = V_44 -> V_58 ;
} else {
V_78 -> V_89 = V_44 -> V_93 ;
V_78 -> V_90 = V_44 -> V_91 ;
V_78 -> V_92 = V_44 -> V_93 ;
}
#ifdef F_35
if ( F_36 ( V_8 , 0 ) )
memset ( F_36 ( V_8 , 0 ) , 0xaa , F_37 ( V_8 , 0 ) ) ;
#endif
F_38 ( & V_17 -> V_24 ) ;
F_39 ( & V_25 -> V_26 , & V_17 -> V_32 ) ;
if ( ! V_17 -> V_22 )
V_17 -> V_22 = V_25 ;
F_40 ( & V_17 -> V_24 ) ;
V_21 = V_14 -> V_94 ( V_14 ) ;
F_10 ( V_44 -> V_47 , L_3 ,
V_21 , F_11 ( & V_25 -> V_23 ) ) ;
if ( V_21 >= 0 )
return;
F_38 ( & V_17 -> V_24 ) ;
F_13 ( & V_25 -> V_26 ) ;
if ( V_17 -> V_22 == V_25 )
V_17 -> V_22 = NULL ;
F_40 ( & V_17 -> V_24 ) ;
error:
F_15 ( V_8 , V_95 ) ;
}
static void F_41 ( struct V_72 * V_8 )
{
struct V_7 * V_73 = F_28 ( V_8 ) ;
struct V_43 * V_44 = F_20 ( V_8 -> V_34 ) ;
struct V_45 * V_46 = F_21 ( V_44 -> V_47 ) ;
struct V_1 * V_17 = V_46 -> V_48 ;
struct V_6 * V_25 = F_5 ( V_73 ) ;
struct V_75 * V_14 = V_25 -> V_14 ;
unsigned long V_96 ;
F_10 ( V_44 -> V_47 ,
L_4 ,
V_17 -> V_22 == V_25 ? L_5 : L_6 , F_11 ( & V_25 -> V_23 ) ,
F_16 ( & V_25 -> V_26 ) ? L_6 : L_7 ) ;
F_42 ( & V_17 -> V_24 , V_96 ) ;
if ( V_17 -> V_22 == V_25 )
V_17 -> V_22 = NULL ;
F_13 ( & V_25 -> V_26 ) ;
if ( V_14 ) {
V_25 -> V_14 = NULL ;
if ( V_17 -> V_15 [ 0 ] )
F_43 ( V_14 ) ;
}
F_44 ( & V_17 -> V_24 , V_96 ) ;
V_17 -> V_63 -= F_29 ( V_8 , 0 ) ;
}
static int F_45 ( struct V_72 * V_8 )
{
struct V_7 * V_73 = F_28 ( V_8 ) ;
struct V_43 * V_44 = F_20 ( V_8 -> V_34 ) ;
struct V_45 * V_46 = F_21 ( V_44 -> V_47 ) ;
struct V_1 * V_17 = V_46 -> V_48 ;
struct V_6 * V_25 = F_5 ( V_73 ) ;
if ( ! V_25 -> V_14 ) {
F_46 ( & V_25 -> V_26 ) ;
F_47 ( & V_25 -> V_23 , 1 ) ;
V_17 -> V_63 += F_29 ( V_8 , 0 ) ;
}
return 0 ;
}
static void F_48 ( struct V_34 * V_97 )
{
struct V_43 * V_44 = F_20 ( V_97 ) ;
struct V_45 * V_46 = F_21 ( V_44 -> V_47 ) ;
struct V_1 * V_17 = V_46 -> V_48 ;
struct V_15 * V_76 = V_17 -> V_15 [ 0 ] ;
struct V_6 * V_25 , * V_98 ;
unsigned long V_96 ;
if ( V_76 )
F_49 ( & V_76 -> V_12 ) ;
F_42 ( & V_17 -> V_24 , V_96 ) ;
V_17 -> V_22 = NULL ;
F_50 (buf, tmp, &mx3_cam->capture, queue) {
F_13 ( & V_25 -> V_26 ) ;
F_15 ( & V_25 -> V_8 . V_30 , V_95 ) ;
}
F_44 ( & V_17 -> V_24 , V_96 ) ;
}
static int F_51 ( struct V_34 * V_97 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 = F_21 ( V_44 -> V_47 ) ;
V_97 -> type = V_99 ;
V_97 -> V_100 = V_101 | V_102 ;
V_97 -> V_103 = V_44 ;
V_97 -> V_104 = & V_105 ;
V_97 -> V_106 = & V_107 ;
V_97 -> V_108 = sizeof( struct V_6 ) ;
V_97 -> V_109 = V_110 ;
V_97 -> V_24 = & V_46 -> V_111 ;
return F_52 ( V_97 ) ;
}
static void F_53 ( struct V_1 * V_17 )
{
T_1 V_112 ;
long V_113 ;
F_3 ( V_17 , ( 640 - 1 ) | ( ( 480 - 1 ) << 16 ) , V_114 ) ;
V_112 = F_1 ( V_17 , V_115 ) & 0xffff0000 ;
F_3 ( V_17 , V_112 , V_115 ) ;
V_112 = 0 << V_116 ;
V_112 |= V_117 ;
if ( V_17 -> V_118 & V_119 )
V_112 |= 3 << V_120 ;
else if ( V_17 -> V_118 & V_121 )
V_112 |= 2 << V_120 ;
else if ( V_17 -> V_118 & V_122 )
V_112 |= 1 << V_120 ;
else
V_112 |= 0 << V_120 ;
if ( V_17 -> V_118 & V_123 )
V_112 |= 1 << V_124 ;
if ( V_17 -> V_118 & V_125 )
V_112 |= 1 << V_126 ;
if ( V_17 -> V_118 & V_127 )
V_112 |= 1 << V_128 ;
if ( V_17 -> V_118 & V_129 )
V_112 |= 1 << V_130 ;
if ( V_17 -> V_118 & V_131 )
V_112 |= 1 << V_132 ;
if ( V_17 -> V_118 & V_133 )
V_112 |= 1 << V_134 ;
F_3 ( V_17 , V_112 , V_135 ) ;
F_54 ( V_17 -> V_136 ) ;
V_113 = F_55 ( V_17 -> V_136 , V_17 -> V_137 ) ;
F_10 ( V_17 -> V_138 . V_139 . V_20 , L_8 , V_112 , V_113 ) ;
if ( V_113 )
F_56 ( V_17 -> V_136 , V_113 ) ;
}
static int F_57 ( struct V_43 * V_44 )
{
F_58 ( V_44 -> V_47 , L_9 ,
V_44 -> V_140 ) ;
return 0 ;
}
static void F_59 ( struct V_43 * V_44 )
{
F_58 ( V_44 -> V_47 , L_10 ,
V_44 -> V_140 ) ;
}
static int F_60 ( struct V_45 * V_46 )
{
struct V_1 * V_17 = V_46 -> V_48 ;
F_53 ( V_17 ) ;
V_17 -> V_63 = 0 ;
return 0 ;
}
static void F_61 ( struct V_45 * V_46 )
{
struct V_1 * V_17 = V_46 -> V_48 ;
struct V_15 * * V_76 = & V_17 -> V_15 [ 0 ] ;
if ( * V_76 ) {
F_62 ( & ( * V_76 ) -> V_12 ) ;
* V_76 = NULL ;
}
F_63 ( V_17 -> V_136 ) ;
}
static int F_64 ( struct V_1 * V_17 ,
unsigned char V_141 , unsigned long * V_96 )
{
if ( V_141 > F_65 ( V_17 -> V_142 ) )
return - V_49 ;
* V_96 = V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 |
V_150 |
V_151 ;
return 0 ;
}
static int F_66 ( struct V_43 * V_44 ,
const unsigned int V_152 )
{
struct V_153 * V_154 = F_67 ( V_44 ) ;
struct V_45 * V_46 = F_21 ( V_44 -> V_47 ) ;
struct V_1 * V_17 = V_46 -> V_48 ;
struct V_155 V_156 = { . type = V_157 ,} ;
unsigned long V_158 , V_159 ;
int V_55 = F_64 ( V_17 , V_152 , & V_158 ) ;
F_10 ( V_44 -> V_47 , L_11 , V_152 , V_55 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = F_68 ( V_154 , V_78 , V_160 , & V_156 ) ;
if ( ! V_55 ) {
V_159 = F_69 ( & V_156 ,
V_158 ) ;
if ( ! V_159 ) {
F_70 ( V_44 -> V_47 ,
L_12 ,
V_156 . V_96 , V_158 ) ;
return - V_49 ;
}
} else if ( V_55 != - V_161 ) {
return V_55 ;
}
return 0 ;
}
static bool F_71 ( struct V_12 * V_13 , void * V_9 )
{
struct V_162 * V_163 = V_9 ;
struct V_164 * V_165 ;
if ( ! F_72 ( V_13 ) )
return false ;
if ( ! V_163 )
return false ;
V_165 = V_163 -> V_17 -> V_138 . V_139 . V_20 -> V_166 ;
return V_163 -> V_167 == V_13 -> V_168 &&
V_165 -> V_169 == V_13 -> V_19 -> V_20 ;
}
static bool F_73 ( const struct V_80 * V_42 )
{
return V_42 -> V_170 == V_171 ||
( V_42 -> V_172 == 8 &&
V_42 -> V_170 == V_173 ) ||
( V_42 -> V_172 > 8 &&
V_42 -> V_170 == V_174 ) ;
}
static int F_74 ( struct V_43 * V_44 , unsigned int V_175 ,
struct V_50 * V_51 )
{
struct V_153 * V_154 = F_67 ( V_44 ) ;
struct V_19 * V_20 = V_44 -> V_47 ;
int V_176 = 0 , V_55 ;
struct V_177 V_178 = {
. V_179 = V_180 ,
. V_83 = V_175 ,
} ;
const struct V_80 * V_42 ;
V_55 = F_68 ( V_154 , V_181 , V_182 , NULL , & V_178 ) ;
if ( V_55 < 0 )
return 0 ;
V_42 = F_75 ( V_178 . V_178 ) ;
if ( ! V_42 ) {
F_70 ( V_44 -> V_47 ,
L_13 , V_175 , V_178 . V_178 ) ;
return 0 ;
}
V_55 = F_66 ( V_44 , V_42 -> V_172 ) ;
if ( V_55 < 0 )
return 0 ;
switch ( V_178 . V_178 ) {
case V_183 :
V_176 ++ ;
if ( V_51 ) {
V_51 -> V_57 = & V_184 [ 0 ] ;
V_51 -> V_178 = V_178 . V_178 ;
V_51 ++ ;
F_10 ( V_20 , L_14 ,
V_184 [ 0 ] . V_185 , V_178 . V_178 ) ;
}
break;
case V_186 :
V_176 ++ ;
if ( V_51 ) {
V_51 -> V_57 = & V_184 [ 1 ] ;
V_51 -> V_178 = V_178 . V_178 ;
V_51 ++ ;
F_10 ( V_20 , L_14 ,
V_184 [ 1 ] . V_185 , V_178 . V_178 ) ;
}
break;
default:
if ( ! F_73 ( V_42 ) )
return 0 ;
}
V_176 ++ ;
if ( V_51 ) {
V_51 -> V_57 = V_42 ;
V_51 -> V_178 = V_178 . V_178 ;
F_10 ( V_20 , L_15 ,
( V_42 -> V_66 >> ( 0 * 8 ) ) & 0xFF ,
( V_42 -> V_66 >> ( 1 * 8 ) ) & 0xFF ,
( V_42 -> V_66 >> ( 2 * 8 ) ) & 0xFF ,
( V_42 -> V_66 >> ( 3 * 8 ) ) & 0xFF ) ;
V_51 ++ ;
}
return V_176 ;
}
static void F_76 ( struct V_1 * V_17 ,
unsigned int V_56 , unsigned int V_59 ,
const struct V_80 * V_42 )
{
T_1 V_187 , V_188 , V_189 ;
if ( F_26 ( V_42 -> V_66 ) == V_71 ) {
unsigned int V_190 , V_191 ;
int V_55 = F_77 ( V_42 , & V_190 , & V_191 ) ;
F_78 ( V_55 < 0 ) ;
V_56 = V_56 * V_190 / V_191 ;
}
V_188 = V_56 - 1 ;
V_189 = V_59 - 1 ;
F_3 ( V_17 , V_188 | ( V_189 << 16 ) , V_192 ) ;
F_3 ( V_17 , V_188 << 16 , V_193 ) ;
F_3 ( V_17 , ( V_189 << 16 ) | 0x22 , V_194 ) ;
F_3 ( V_17 , V_188 | ( V_189 << 16 ) , V_114 ) ;
V_187 = F_1 ( V_17 , V_115 ) & 0xffff0000 ;
F_3 ( V_17 , V_187 | 0 | ( 0 << 8 ) , V_115 ) ;
}
static int F_79 ( struct V_1 * V_17 )
{
T_6 V_195 ;
struct V_12 * V_13 ;
struct V_15 * * V_76 = & V_17 -> V_15 [ 0 ] ;
struct V_162 V_163 = { . V_17 = V_17 ,
. V_167 = V_196 } ;
F_80 ( V_195 ) ;
F_81 ( V_197 , V_195 ) ;
F_81 ( V_198 , V_195 ) ;
V_13 = F_82 ( V_195 , F_71 , & V_163 ) ;
if ( ! V_13 )
return - V_199 ;
* V_76 = F_9 ( V_13 ) ;
( * V_76 ) -> V_18 = V_17 ;
return 0 ;
}
static inline void F_83 ( T_3 * V_56 )
{
if ( F_84 ( * V_56 , 8 ) < 4096 )
* V_56 = F_84 ( * V_56 , 8 ) ;
else
* V_56 = * V_56 & ~ 7 ;
}
static int F_85 ( struct V_43 * V_44 ,
const struct V_200 * V_201 )
{
struct V_200 V_202 = * V_201 ;
struct V_203 * V_204 = & V_202 . V_205 ;
struct V_45 * V_46 = F_21 ( V_44 -> V_47 ) ;
struct V_1 * V_17 = V_46 -> V_48 ;
struct V_153 * V_154 = F_67 ( V_44 ) ;
struct V_206 V_42 = {
. V_179 = V_180 ,
} ;
struct V_207 * V_208 = & V_42 . V_209 ;
int V_55 ;
F_86 ( & V_204 -> V_210 , & V_204 -> V_56 , 0 , 2 , 4096 ) ;
F_86 ( & V_204 -> V_211 , & V_204 -> V_59 , 0 , 2 , 4096 ) ;
V_55 = F_68 ( V_154 , V_78 , V_212 , V_201 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = F_68 ( V_154 , V_181 , V_213 , NULL , & V_42 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_208 -> V_178 != V_44 -> V_81 -> V_178 )
return - V_49 ;
if ( V_208 -> V_56 & 7 ) {
F_83 ( & V_208 -> V_56 ) ;
V_55 = F_68 ( V_154 , V_181 , V_214 , NULL , & V_42 ) ;
if ( V_55 < 0 )
return V_55 ;
}
if ( V_208 -> V_56 != V_44 -> V_93 || V_208 -> V_59 != V_44 -> V_91 )
F_76 ( V_17 , V_208 -> V_56 , V_208 -> V_59 ,
V_44 -> V_81 -> V_57 ) ;
F_10 ( V_44 -> V_47 , L_16 ,
V_208 -> V_56 , V_208 -> V_59 ) ;
V_44 -> V_93 = V_208 -> V_56 ;
V_44 -> V_91 = V_208 -> V_59 ;
return V_55 ;
}
static int F_87 ( struct V_43 * V_44 ,
struct V_41 * V_215 )
{
struct V_45 * V_46 = F_21 ( V_44 -> V_47 ) ;
struct V_1 * V_17 = V_46 -> V_48 ;
struct V_153 * V_154 = F_67 ( V_44 ) ;
const struct V_50 * V_51 ;
struct V_216 * V_52 = & V_215 -> V_42 . V_52 ;
struct V_206 V_209 = {
. V_179 = V_180 ,
} ;
struct V_207 * V_208 = & V_209 . V_209 ;
int V_55 ;
V_51 = F_22 ( V_44 , V_52 -> V_53 ) ;
if ( ! V_51 ) {
F_70 ( V_44 -> V_47 , L_17 ,
V_52 -> V_53 ) ;
return - V_49 ;
}
F_83 ( & V_52 -> V_56 ) ;
F_10 ( V_44 -> V_47 , L_18 , V_52 -> V_56 , V_52 -> V_59 ) ;
F_76 ( V_17 , V_52 -> V_56 , V_52 -> V_59 , V_51 -> V_57 ) ;
V_208 -> V_56 = V_52 -> V_56 ;
V_208 -> V_59 = V_52 -> V_59 ;
V_208 -> V_28 = V_52 -> V_28 ;
V_208 -> V_217 = V_52 -> V_217 ;
V_208 -> V_178 = V_51 -> V_178 ;
V_55 = F_68 ( V_154 , V_181 , V_214 , NULL , & V_209 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_208 -> V_178 != V_51 -> V_178 )
return - V_49 ;
if ( ! V_17 -> V_15 [ 0 ] ) {
V_55 = F_79 ( V_17 ) ;
if ( V_55 < 0 )
return V_55 ;
}
V_52 -> V_56 = V_208 -> V_56 ;
V_52 -> V_59 = V_208 -> V_59 ;
V_52 -> V_28 = V_208 -> V_28 ;
V_17 -> V_28 = V_208 -> V_28 ;
V_52 -> V_217 = V_208 -> V_217 ;
V_44 -> V_81 = V_51 ;
F_10 ( V_44 -> V_47 , L_19 , V_52 -> V_56 , V_52 -> V_59 ) ;
return V_55 ;
}
static int F_88 ( struct V_43 * V_44 ,
struct V_41 * V_215 )
{
struct V_153 * V_154 = F_67 ( V_44 ) ;
const struct V_50 * V_51 ;
struct V_216 * V_52 = & V_215 -> V_42 . V_52 ;
struct V_218 V_219 ;
struct V_206 V_209 = {
. V_179 = V_220 ,
} ;
struct V_207 * V_208 = & V_209 . V_209 ;
T_3 V_221 = V_52 -> V_53 ;
int V_55 ;
V_51 = F_22 ( V_44 , V_221 ) ;
if ( V_221 && ! V_51 ) {
F_70 ( V_44 -> V_47 , L_17 , V_221 ) ;
return - V_49 ;
}
if ( V_52 -> V_59 > 4096 )
V_52 -> V_59 = 4096 ;
if ( V_52 -> V_56 > 4096 )
V_52 -> V_56 = 4096 ;
V_208 -> V_56 = V_52 -> V_56 ;
V_208 -> V_59 = V_52 -> V_59 ;
V_208 -> V_28 = V_52 -> V_28 ;
V_208 -> V_217 = V_52 -> V_217 ;
V_208 -> V_178 = V_51 -> V_178 ;
V_55 = F_68 ( V_154 , V_181 , V_214 , & V_219 , & V_209 ) ;
if ( V_55 < 0 )
return V_55 ;
V_52 -> V_56 = V_208 -> V_56 ;
V_52 -> V_59 = V_208 -> V_59 ;
V_52 -> V_217 = V_208 -> V_217 ;
switch ( V_208 -> V_28 ) {
case V_222 :
V_52 -> V_28 = V_223 ;
break;
case V_223 :
break;
default:
F_30 ( V_44 -> V_47 , L_20 ,
V_208 -> V_28 ) ;
V_55 = - V_49 ;
}
return V_55 ;
}
static int F_89 ( struct V_43 * V_44 ,
struct V_224 * V_225 )
{
return 0 ;
}
static unsigned int F_90 ( struct V_226 * V_226 , T_7 * V_227 )
{
struct V_43 * V_44 = V_226 -> V_228 ;
return F_91 ( & V_44 -> V_229 , V_226 , V_227 ) ;
}
static int F_92 ( struct V_45 * V_46 ,
struct V_230 * V_231 )
{
F_93 ( V_231 -> V_232 , L_21 , sizeof( V_231 -> V_232 ) ) ;
V_231 -> V_233 = V_234 | V_235 ;
V_231 -> V_236 = V_231 -> V_233 | V_237 ;
return 0 ;
}
static int F_94 ( struct V_43 * V_44 )
{
struct V_153 * V_154 = F_67 ( V_44 ) ;
struct V_45 * V_46 = F_21 ( V_44 -> V_47 ) ;
struct V_1 * V_17 = V_46 -> V_48 ;
struct V_155 V_156 = { . type = V_157 ,} ;
T_1 V_221 = V_44 -> V_81 -> V_57 -> V_66 ;
unsigned long V_158 , V_159 ;
T_1 V_238 , V_239 ;
const struct V_80 * V_42 ;
int V_141 ;
int V_55 ;
const struct V_50 * V_51 ;
struct V_19 * V_20 = V_44 -> V_47 ;
V_42 = F_75 ( V_44 -> V_81 -> V_178 ) ;
if ( ! V_42 )
return - V_49 ;
V_51 = F_22 ( V_44 , V_221 ) ;
if ( ! V_51 ) {
F_70 ( V_20 , L_17 , V_221 ) ;
return - V_49 ;
}
V_141 = V_42 -> V_172 ;
V_55 = F_64 ( V_17 , V_141 , & V_158 ) ;
F_10 ( V_20 , L_22 , V_141 , V_55 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = F_68 ( V_154 , V_78 , V_160 , & V_156 ) ;
if ( ! V_55 ) {
V_159 = F_69 ( & V_156 ,
V_158 ) ;
if ( ! V_159 ) {
F_70 ( V_44 -> V_47 ,
L_12 ,
V_156 . V_96 , V_158 ) ;
return - V_49 ;
}
} else if ( V_55 != - V_161 ) {
return V_55 ;
} else {
V_159 = V_158 ;
}
F_10 ( V_20 , L_23 ,
V_156 . V_96 , V_158 , V_159 ) ;
if ( ( V_159 & V_144 ) &&
( V_159 & V_145 ) ) {
if ( V_17 -> V_118 & V_131 )
V_159 &= ~ V_144 ;
else
V_159 &= ~ V_145 ;
}
if ( ( V_159 & V_146 ) &&
( V_159 & V_147 ) ) {
if ( V_17 -> V_118 & V_133 )
V_159 &= ~ V_146 ;
else
V_159 &= ~ V_147 ;
}
if ( ( V_159 & V_150 ) &&
( V_159 & V_151 ) ) {
if ( V_17 -> V_118 & V_127 )
V_159 &= ~ V_150 ;
else
V_159 &= ~ V_151 ;
}
if ( ( V_159 & V_148 ) &&
( V_159 & V_149 ) ) {
if ( V_17 -> V_118 & V_129 )
V_159 &= ~ V_148 ;
else
V_159 &= ~ V_149 ;
}
V_156 . V_96 = V_159 ;
V_55 = F_68 ( V_154 , V_78 , V_240 , & V_156 ) ;
if ( V_55 < 0 && V_55 != - V_161 ) {
F_10 ( V_20 , L_24 ,
V_159 , V_55 ) ;
return V_55 ;
}
V_239 = F_1 ( V_17 , V_135 ) &
~ ( ( 1 << V_134 ) |
( 1 << V_132 ) |
( 1 << V_128 ) |
( 1 << V_130 ) |
( 3 << V_241 ) |
( 3 << V_120 ) ) ;
V_239 |= V_117 ;
if ( V_159 & V_149 )
V_239 |= 1 << V_130 ;
if ( V_159 & V_145 )
V_239 |= 1 << V_132 ;
if ( V_159 & V_147 )
V_239 |= 1 << V_134 ;
if ( V_159 & V_151 )
V_239 |= 1 << V_128 ;
switch ( V_51 -> V_57 -> V_172 ) {
case 4 :
V_238 = 0 << V_120 ;
break;
case 8 :
V_238 = 1 << V_120 ;
break;
case 10 :
V_238 = 2 << V_120 ;
break;
default:
case 15 :
V_238 = 3 << V_120 ;
}
F_3 ( V_17 , V_239 | V_238 , V_135 ) ;
F_10 ( V_20 , L_25 , V_239 | V_238 ) ;
return 0 ;
}
static int F_95 ( struct V_242 * V_243 )
{
struct V_164 * V_165 = V_243 -> V_20 . V_166 ;
struct V_1 * V_17 ;
struct V_244 * V_245 ;
void T_8 * V_4 ;
int V_246 = 0 ;
struct V_45 * V_138 ;
V_245 = F_96 ( V_243 , V_247 , 0 ) ;
V_4 = F_97 ( & V_243 -> V_20 , V_245 ) ;
if ( F_98 ( V_4 ) )
return F_99 ( V_4 ) ;
if ( ! V_165 )
return - V_49 ;
V_17 = F_100 ( & V_243 -> V_20 , sizeof( * V_17 ) , V_248 ) ;
if ( ! V_17 ) {
F_30 ( & V_243 -> V_20 , L_26 ) ;
return - V_249 ;
}
V_17 -> V_136 = F_101 ( & V_243 -> V_20 , NULL ) ;
if ( F_98 ( V_17 -> V_136 ) )
return F_99 ( V_17 -> V_136 ) ;
V_17 -> V_165 = V_165 ;
V_17 -> V_118 = V_165 -> V_96 ;
if ( ! ( V_17 -> V_118 & V_250 ) ) {
F_70 ( & V_243 -> V_20 , L_27
L_28 ) ;
V_17 -> V_118 |= V_122 ;
}
if ( V_17 -> V_118 & V_251 )
V_17 -> V_142 = 1 << 3 ;
if ( V_17 -> V_118 & V_122 )
V_17 -> V_142 |= 1 << 7 ;
if ( V_17 -> V_118 & V_121 )
V_17 -> V_142 |= 1 << 9 ;
if ( V_17 -> V_118 & V_119 )
V_17 -> V_142 |= 1 << 14 ;
V_17 -> V_137 = V_165 -> V_252 * 10000 ;
if ( ! V_17 -> V_137 ) {
F_70 ( & V_243 -> V_20 ,
L_29
L_30 ) ;
V_17 -> V_137 = 20000000 ;
}
F_46 ( & V_17 -> V_32 ) ;
F_102 ( & V_17 -> V_24 ) ;
V_17 -> V_4 = V_4 ;
V_138 = & V_17 -> V_138 ;
V_138 -> V_253 = V_254 ;
V_138 -> V_104 = & V_255 ;
V_138 -> V_48 = V_17 ;
V_138 -> V_139 . V_20 = & V_243 -> V_20 ;
V_138 -> V_256 = V_243 -> V_167 ;
V_17 -> V_61 = F_103 ( & V_243 -> V_20 ) ;
if ( F_98 ( V_17 -> V_61 ) )
return F_99 ( V_17 -> V_61 ) ;
if ( V_165 -> V_257 ) {
V_138 -> V_258 = V_165 -> V_258 ;
V_138 -> V_257 = V_165 -> V_257 ;
}
V_246 = F_104 ( V_138 ) ;
if ( V_246 )
goto V_259;
F_105 () ;
return 0 ;
V_259:
F_106 ( V_17 -> V_61 ) ;
return V_246 ;
}
static int F_107 ( struct V_242 * V_243 )
{
struct V_45 * V_138 = F_21 ( & V_243 -> V_20 ) ;
struct V_1 * V_17 = F_6 ( V_138 ,
struct V_1 , V_138 ) ;
F_108 ( V_138 ) ;
if ( F_109 ( V_17 -> V_15 [ 0 ] ) )
F_62 ( & V_17 -> V_15 [ 0 ] -> V_12 ) ;
F_106 ( V_17 -> V_61 ) ;
F_110 () ;
return 0 ;
}
