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
F_14 ( & V_8 -> V_27 . V_28 ) ;
V_8 -> V_27 . V_29 = V_17 -> V_29 ;
V_8 -> V_27 . V_30 = V_17 -> V_30 ++ ;
F_15 ( V_8 , V_31 ) ;
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
const struct V_36 * V_37 ,
unsigned int * V_38 , unsigned int * V_39 ,
unsigned int V_40 [] , void * V_41 [] )
{
struct V_42 * V_43 = F_20 ( V_35 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
if ( ! V_17 -> V_15 [ 0 ] )
return - V_48 ;
if ( V_37 ) {
const struct V_49 * V_50 = F_22 ( V_43 ,
V_37 -> V_37 . V_51 . V_52 ) ;
unsigned int V_53 ;
int V_54 ;
if ( ! V_50 )
return - V_48 ;
V_54 = F_23 ( V_37 -> V_37 . V_51 . V_55 ,
V_50 -> V_56 ) ;
if ( V_54 < 0 )
return V_54 ;
V_53 = F_24 ( T_1 , V_37 -> V_37 . V_51 . V_57 , V_54 ) ;
V_54 = F_25 ( V_50 -> V_56 , V_53 ,
V_37 -> V_37 . V_51 . V_58 ) ;
if ( V_54 < 0 )
return V_54 ;
V_40 [ 0 ] = F_24 ( T_1 , V_37 -> V_37 . V_51 . V_59 , V_54 ) ;
} else {
V_40 [ 0 ] = V_43 -> V_59 ;
}
V_41 [ 0 ] = V_17 -> V_60 ;
if ( ! V_35 -> V_61 )
V_17 -> V_30 = 0 ;
if ( ! * V_38 )
* V_38 = 2 ;
if ( ! * V_39 &&
V_40 [ 0 ] * * V_38 + V_17 -> V_62 > V_63 * 1024 * 1024 )
* V_38 = ( V_63 * 1024 * 1024 - V_17 -> V_62 ) /
V_40 [ 0 ] ;
* V_39 = 1 ;
return 0 ;
}
static enum V_64 F_26 ( T_3 V_65 )
{
switch ( V_65 ) {
case V_66 :
return V_67 ;
case V_68 :
case V_69 :
default:
return V_70 ;
}
}
static void F_27 ( struct V_7 * V_8 )
{
struct V_42 * V_43 = F_20 ( V_8 -> V_34 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_6 * V_25 = F_5 ( V_8 ) ;
struct V_71 * V_23 = & V_25 -> V_23 ;
struct V_72 * V_14 ;
struct V_15 * V_73 = V_17 -> V_15 [ 0 ] ;
struct V_74 * V_75 = & V_73 -> V_76 . V_75 ;
const struct V_77 * V_56 = V_43 -> V_78 -> V_56 ;
T_4 V_21 ;
T_5 V_79 ;
V_79 = V_43 -> V_59 ;
if ( F_28 ( V_8 , 0 ) < V_79 ) {
F_29 ( V_43 -> V_46 , L_2 ,
V_8 -> V_27 . V_80 , F_28 ( V_8 , 0 ) , V_79 ) ;
goto error;
}
if ( ! V_25 -> V_14 ) {
F_11 ( V_23 ) = F_30 ( V_8 , 0 ) ;
F_31 ( V_23 ) = V_79 ;
V_14 = F_32 (
& V_73 -> V_12 , V_23 , 1 , V_81 ,
V_82 ) ;
if ( ! V_14 )
goto error;
V_14 -> V_83 = V_14 ;
V_14 -> V_84 = F_7 ;
V_25 -> V_14 = V_14 ;
} else {
V_14 = V_25 -> V_14 ;
}
F_33 ( V_8 , 0 , V_79 ) ;
V_75 -> V_85 = F_26 ( V_56 -> V_65 ) ;
if ( V_75 -> V_85 == V_70 ) {
V_75 -> V_86 = V_43 -> V_57 ;
V_75 -> V_87 = V_43 -> V_88 ;
V_75 -> V_89 = V_43 -> V_57 ;
} else {
V_75 -> V_86 = V_43 -> V_90 ;
V_75 -> V_87 = V_43 -> V_88 ;
V_75 -> V_89 = V_43 -> V_90 ;
}
#ifdef F_34
if ( F_35 ( V_8 , 0 ) )
memset ( F_35 ( V_8 , 0 ) , 0xaa , F_36 ( V_8 , 0 ) ) ;
#endif
F_37 ( & V_17 -> V_24 ) ;
F_38 ( & V_25 -> V_26 , & V_17 -> V_32 ) ;
if ( ! V_17 -> V_22 )
V_17 -> V_22 = V_25 ;
F_39 ( & V_17 -> V_24 ) ;
V_21 = V_14 -> V_91 ( V_14 ) ;
F_10 ( V_43 -> V_46 , L_3 ,
V_21 , F_11 ( & V_25 -> V_23 ) ) ;
if ( V_21 >= 0 )
return;
F_37 ( & V_17 -> V_24 ) ;
F_13 ( & V_25 -> V_26 ) ;
if ( V_17 -> V_22 == V_25 )
V_17 -> V_22 = NULL ;
F_39 ( & V_17 -> V_24 ) ;
error:
F_15 ( V_8 , V_92 ) ;
}
static void F_40 ( struct V_7 * V_8 )
{
struct V_42 * V_43 = F_20 ( V_8 -> V_34 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_6 * V_25 = F_5 ( V_8 ) ;
struct V_72 * V_14 = V_25 -> V_14 ;
unsigned long V_93 ;
F_10 ( V_43 -> V_46 ,
L_4 ,
V_17 -> V_22 == V_25 ? L_5 : L_6 , F_11 ( & V_25 -> V_23 ) ,
F_16 ( & V_25 -> V_26 ) ? L_6 : L_7 ) ;
F_41 ( & V_17 -> V_24 , V_93 ) ;
if ( V_17 -> V_22 == V_25 )
V_17 -> V_22 = NULL ;
F_13 ( & V_25 -> V_26 ) ;
if ( V_14 ) {
V_25 -> V_14 = NULL ;
if ( V_17 -> V_15 [ 0 ] )
F_42 ( V_14 ) ;
}
F_43 ( & V_17 -> V_24 , V_93 ) ;
V_17 -> V_62 -= F_28 ( V_8 , 0 ) ;
}
static int F_44 ( struct V_7 * V_8 )
{
struct V_42 * V_43 = F_20 ( V_8 -> V_34 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_6 * V_25 = F_5 ( V_8 ) ;
if ( ! V_25 -> V_14 ) {
F_45 ( & V_25 -> V_26 ) ;
F_46 ( & V_25 -> V_23 , 1 ) ;
V_17 -> V_62 += F_28 ( V_8 , 0 ) ;
}
return 0 ;
}
static void F_47 ( struct V_34 * V_94 )
{
struct V_42 * V_43 = F_20 ( V_94 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_15 * V_73 = V_17 -> V_15 [ 0 ] ;
struct V_6 * V_25 , * V_95 ;
unsigned long V_93 ;
if ( V_73 )
F_48 ( & V_73 -> V_12 ) ;
F_41 ( & V_17 -> V_24 , V_93 ) ;
V_17 -> V_22 = NULL ;
F_49 (buf, tmp, &mx3_cam->capture, queue) {
F_13 ( & V_25 -> V_26 ) ;
F_15 ( & V_25 -> V_8 , V_92 ) ;
}
F_43 ( & V_17 -> V_24 , V_93 ) ;
}
static int F_50 ( struct V_34 * V_94 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
V_94 -> type = V_96 ;
V_94 -> V_97 = V_98 | V_99 ;
V_94 -> V_100 = V_43 ;
V_94 -> V_101 = & V_102 ;
V_94 -> V_103 = & V_104 ;
V_94 -> V_105 = sizeof( struct V_6 ) ;
V_94 -> V_106 = V_107 ;
V_94 -> V_24 = & V_45 -> V_108 ;
return F_51 ( V_94 ) ;
}
static void F_52 ( struct V_1 * V_17 )
{
T_1 V_109 ;
long V_110 ;
F_3 ( V_17 , ( 640 - 1 ) | ( ( 480 - 1 ) << 16 ) , V_111 ) ;
V_109 = F_1 ( V_17 , V_112 ) & 0xffff0000 ;
F_3 ( V_17 , V_109 , V_112 ) ;
V_109 = 0 << V_113 ;
V_109 |= V_114 ;
if ( V_17 -> V_115 & V_116 )
V_109 |= 3 << V_117 ;
else if ( V_17 -> V_115 & V_118 )
V_109 |= 2 << V_117 ;
else if ( V_17 -> V_115 & V_119 )
V_109 |= 1 << V_117 ;
else
V_109 |= 0 << V_117 ;
if ( V_17 -> V_115 & V_120 )
V_109 |= 1 << V_121 ;
if ( V_17 -> V_115 & V_122 )
V_109 |= 1 << V_123 ;
if ( V_17 -> V_115 & V_124 )
V_109 |= 1 << V_125 ;
if ( V_17 -> V_115 & V_126 )
V_109 |= 1 << V_127 ;
if ( V_17 -> V_115 & V_128 )
V_109 |= 1 << V_129 ;
if ( V_17 -> V_115 & V_130 )
V_109 |= 1 << V_131 ;
F_3 ( V_17 , V_109 , V_132 ) ;
F_53 ( V_17 -> V_133 ) ;
V_110 = F_54 ( V_17 -> V_133 , V_17 -> V_134 ) ;
F_10 ( V_17 -> V_135 . V_136 . V_20 , L_8 , V_109 , V_110 ) ;
if ( V_110 )
F_55 ( V_17 -> V_133 , V_110 ) ;
}
static int F_56 ( struct V_42 * V_43 )
{
F_57 ( V_43 -> V_46 , L_9 ,
V_43 -> V_137 ) ;
return 0 ;
}
static void F_58 ( struct V_42 * V_43 )
{
F_57 ( V_43 -> V_46 , L_10 ,
V_43 -> V_137 ) ;
}
static int F_59 ( struct V_44 * V_45 )
{
struct V_1 * V_17 = V_45 -> V_47 ;
F_52 ( V_17 ) ;
V_17 -> V_62 = 0 ;
return 0 ;
}
static void F_60 ( struct V_44 * V_45 )
{
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_15 * * V_73 = & V_17 -> V_15 [ 0 ] ;
if ( * V_73 ) {
F_61 ( & ( * V_73 ) -> V_12 ) ;
* V_73 = NULL ;
}
F_62 ( V_17 -> V_133 ) ;
}
static int F_63 ( struct V_1 * V_17 ,
unsigned char V_138 , unsigned long * V_93 )
{
if ( V_138 > F_64 ( V_17 -> V_139 ) )
return - V_48 ;
* V_93 = V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 ;
return 0 ;
}
static int F_65 ( struct V_42 * V_43 ,
const unsigned int V_149 )
{
struct V_150 * V_151 = F_66 ( V_43 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_152 V_153 = { . type = V_154 ,} ;
unsigned long V_155 , V_156 ;
int V_54 = F_63 ( V_17 , V_149 , & V_155 ) ;
F_10 ( V_43 -> V_46 , L_11 , V_149 , V_54 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_67 ( V_151 , V_75 , V_157 , & V_153 ) ;
if ( ! V_54 ) {
V_156 = F_68 ( & V_153 ,
V_155 ) ;
if ( ! V_156 ) {
F_69 ( V_43 -> V_46 ,
L_12 ,
V_153 . V_93 , V_155 ) ;
return - V_48 ;
}
} else if ( V_54 != - V_158 ) {
return V_54 ;
}
return 0 ;
}
static bool F_70 ( struct V_12 * V_13 , void * V_9 )
{
struct V_159 * V_160 = V_9 ;
struct V_161 * V_162 ;
if ( ! F_71 ( V_13 ) )
return false ;
if ( ! V_160 )
return false ;
V_162 = V_160 -> V_17 -> V_135 . V_136 . V_20 -> V_163 ;
return V_160 -> V_164 == V_13 -> V_165 &&
V_162 -> V_166 == V_13 -> V_19 -> V_20 ;
}
static bool F_72 ( const struct V_77 * V_37 )
{
return V_37 -> V_167 == V_168 ||
( V_37 -> V_169 == 8 &&
V_37 -> V_167 == V_170 ) ||
( V_37 -> V_169 > 8 &&
V_37 -> V_167 == V_171 ) ;
}
static int F_73 ( struct V_42 * V_43 , unsigned int V_172 ,
struct V_49 * V_50 )
{
struct V_150 * V_151 = F_66 ( V_43 ) ;
struct V_19 * V_20 = V_43 -> V_46 ;
int V_173 = 0 , V_54 ;
struct V_174 V_175 = {
. V_176 = V_177 ,
. V_80 = V_172 ,
} ;
const struct V_77 * V_37 ;
V_54 = F_67 ( V_151 , V_178 , V_179 , NULL , & V_175 ) ;
if ( V_54 < 0 )
return 0 ;
V_37 = F_74 ( V_175 . V_175 ) ;
if ( ! V_37 ) {
F_69 ( V_43 -> V_46 ,
L_13 , V_172 , V_175 . V_175 ) ;
return 0 ;
}
V_54 = F_65 ( V_43 , V_37 -> V_169 ) ;
if ( V_54 < 0 )
return 0 ;
switch ( V_175 . V_175 ) {
case V_180 :
V_173 ++ ;
if ( V_50 ) {
V_50 -> V_56 = & V_181 [ 0 ] ;
V_50 -> V_175 = V_175 . V_175 ;
V_50 ++ ;
F_10 ( V_20 , L_14 ,
V_181 [ 0 ] . V_182 , V_175 . V_175 ) ;
}
break;
case V_183 :
V_173 ++ ;
if ( V_50 ) {
V_50 -> V_56 = & V_181 [ 1 ] ;
V_50 -> V_175 = V_175 . V_175 ;
V_50 ++ ;
F_10 ( V_20 , L_14 ,
V_181 [ 1 ] . V_182 , V_175 . V_175 ) ;
}
break;
default:
if ( ! F_72 ( V_37 ) )
return 0 ;
}
V_173 ++ ;
if ( V_50 ) {
V_50 -> V_56 = V_37 ;
V_50 -> V_175 = V_175 . V_175 ;
F_10 ( V_20 , L_15 ,
( V_37 -> V_65 >> ( 0 * 8 ) ) & 0xFF ,
( V_37 -> V_65 >> ( 1 * 8 ) ) & 0xFF ,
( V_37 -> V_65 >> ( 2 * 8 ) ) & 0xFF ,
( V_37 -> V_65 >> ( 3 * 8 ) ) & 0xFF ) ;
V_50 ++ ;
}
return V_173 ;
}
static void F_75 ( struct V_1 * V_17 ,
unsigned int V_55 , unsigned int V_58 ,
const struct V_77 * V_37 )
{
T_1 V_184 , V_185 , V_186 ;
if ( F_26 ( V_37 -> V_65 ) == V_70 ) {
unsigned int V_187 , V_188 ;
int V_54 = F_76 ( V_37 , & V_187 , & V_188 ) ;
F_77 ( V_54 < 0 ) ;
V_55 = V_55 * V_187 / V_188 ;
}
V_185 = V_55 - 1 ;
V_186 = V_58 - 1 ;
F_3 ( V_17 , V_185 | ( V_186 << 16 ) , V_189 ) ;
F_3 ( V_17 , V_185 << 16 , V_190 ) ;
F_3 ( V_17 , ( V_186 << 16 ) | 0x22 , V_191 ) ;
F_3 ( V_17 , V_185 | ( V_186 << 16 ) , V_111 ) ;
V_184 = F_1 ( V_17 , V_112 ) & 0xffff0000 ;
F_3 ( V_17 , V_184 | 0 | ( 0 << 8 ) , V_112 ) ;
}
static int F_78 ( struct V_1 * V_17 )
{
T_6 V_192 ;
struct V_12 * V_13 ;
struct V_15 * * V_73 = & V_17 -> V_15 [ 0 ] ;
struct V_159 V_160 = { . V_17 = V_17 ,
. V_164 = V_193 } ;
F_79 ( V_192 ) ;
F_80 ( V_194 , V_192 ) ;
F_80 ( V_195 , V_192 ) ;
V_13 = F_81 ( V_192 , F_70 , & V_160 ) ;
if ( ! V_13 )
return - V_196 ;
* V_73 = F_9 ( V_13 ) ;
( * V_73 ) -> V_18 = V_17 ;
return 0 ;
}
static inline void F_82 ( T_3 * V_55 )
{
if ( F_83 ( * V_55 , 8 ) < 4096 )
* V_55 = F_83 ( * V_55 , 8 ) ;
else
* V_55 = * V_55 & ~ 7 ;
}
static int F_84 ( struct V_42 * V_43 ,
const struct V_197 * V_198 )
{
struct V_197 V_199 = * V_198 ;
struct V_200 * V_201 = & V_199 . V_202 ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_150 * V_151 = F_66 ( V_43 ) ;
struct V_203 V_37 = {
. V_176 = V_177 ,
} ;
struct V_204 * V_205 = & V_37 . V_206 ;
int V_54 ;
F_85 ( & V_201 -> V_207 , & V_201 -> V_55 , 0 , 2 , 4096 ) ;
F_85 ( & V_201 -> V_208 , & V_201 -> V_58 , 0 , 2 , 4096 ) ;
V_54 = F_67 ( V_151 , V_75 , V_209 , V_198 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_67 ( V_151 , V_178 , V_210 , NULL , & V_37 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_205 -> V_175 != V_43 -> V_78 -> V_175 )
return - V_48 ;
if ( V_205 -> V_55 & 7 ) {
F_82 ( & V_205 -> V_55 ) ;
V_54 = F_67 ( V_151 , V_178 , V_211 , NULL , & V_37 ) ;
if ( V_54 < 0 )
return V_54 ;
}
if ( V_205 -> V_55 != V_43 -> V_90 || V_205 -> V_58 != V_43 -> V_88 )
F_75 ( V_17 , V_205 -> V_55 , V_205 -> V_58 ,
V_43 -> V_78 -> V_56 ) ;
F_10 ( V_43 -> V_46 , L_16 ,
V_205 -> V_55 , V_205 -> V_58 ) ;
V_43 -> V_90 = V_205 -> V_55 ;
V_43 -> V_88 = V_205 -> V_58 ;
return V_54 ;
}
static int F_86 ( struct V_42 * V_43 ,
struct V_36 * V_212 )
{
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_150 * V_151 = F_66 ( V_43 ) ;
const struct V_49 * V_50 ;
struct V_213 * V_51 = & V_212 -> V_37 . V_51 ;
struct V_203 V_206 = {
. V_176 = V_177 ,
} ;
struct V_204 * V_205 = & V_206 . V_206 ;
int V_54 ;
V_50 = F_22 ( V_43 , V_51 -> V_52 ) ;
if ( ! V_50 ) {
F_69 ( V_43 -> V_46 , L_17 ,
V_51 -> V_52 ) ;
return - V_48 ;
}
F_82 ( & V_51 -> V_55 ) ;
F_10 ( V_43 -> V_46 , L_18 , V_51 -> V_55 , V_51 -> V_58 ) ;
F_75 ( V_17 , V_51 -> V_55 , V_51 -> V_58 , V_50 -> V_56 ) ;
V_205 -> V_55 = V_51 -> V_55 ;
V_205 -> V_58 = V_51 -> V_58 ;
V_205 -> V_29 = V_51 -> V_29 ;
V_205 -> V_214 = V_51 -> V_214 ;
V_205 -> V_175 = V_50 -> V_175 ;
V_54 = F_67 ( V_151 , V_178 , V_211 , NULL , & V_206 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_205 -> V_175 != V_50 -> V_175 )
return - V_48 ;
if ( ! V_17 -> V_15 [ 0 ] ) {
V_54 = F_78 ( V_17 ) ;
if ( V_54 < 0 )
return V_54 ;
}
V_51 -> V_55 = V_205 -> V_55 ;
V_51 -> V_58 = V_205 -> V_58 ;
V_51 -> V_29 = V_205 -> V_29 ;
V_17 -> V_29 = V_205 -> V_29 ;
V_51 -> V_214 = V_205 -> V_214 ;
V_43 -> V_78 = V_50 ;
F_10 ( V_43 -> V_46 , L_19 , V_51 -> V_55 , V_51 -> V_58 ) ;
return V_54 ;
}
static int F_87 ( struct V_42 * V_43 ,
struct V_36 * V_212 )
{
struct V_150 * V_151 = F_66 ( V_43 ) ;
const struct V_49 * V_50 ;
struct V_213 * V_51 = & V_212 -> V_37 . V_51 ;
struct V_215 V_216 ;
struct V_203 V_206 = {
. V_176 = V_217 ,
} ;
struct V_204 * V_205 = & V_206 . V_206 ;
T_3 V_218 = V_51 -> V_52 ;
int V_54 ;
V_50 = F_22 ( V_43 , V_218 ) ;
if ( V_218 && ! V_50 ) {
F_69 ( V_43 -> V_46 , L_17 , V_218 ) ;
return - V_48 ;
}
if ( V_51 -> V_58 > 4096 )
V_51 -> V_58 = 4096 ;
if ( V_51 -> V_55 > 4096 )
V_51 -> V_55 = 4096 ;
V_205 -> V_55 = V_51 -> V_55 ;
V_205 -> V_58 = V_51 -> V_58 ;
V_205 -> V_29 = V_51 -> V_29 ;
V_205 -> V_214 = V_51 -> V_214 ;
V_205 -> V_175 = V_50 -> V_175 ;
V_54 = F_67 ( V_151 , V_178 , V_211 , & V_216 , & V_206 ) ;
if ( V_54 < 0 )
return V_54 ;
V_51 -> V_55 = V_205 -> V_55 ;
V_51 -> V_58 = V_205 -> V_58 ;
V_51 -> V_214 = V_205 -> V_214 ;
switch ( V_205 -> V_29 ) {
case V_219 :
V_51 -> V_29 = V_220 ;
break;
case V_220 :
break;
default:
F_29 ( V_43 -> V_46 , L_20 ,
V_205 -> V_29 ) ;
V_54 = - V_48 ;
}
return V_54 ;
}
static int F_88 ( struct V_42 * V_43 ,
struct V_221 * V_222 )
{
return 0 ;
}
static unsigned int F_89 ( struct V_223 * V_223 , T_7 * V_224 )
{
struct V_42 * V_43 = V_223 -> V_225 ;
return F_90 ( & V_43 -> V_226 , V_223 , V_224 ) ;
}
static int F_91 ( struct V_44 * V_45 ,
struct V_227 * V_228 )
{
F_92 ( V_228 -> V_229 , L_21 , sizeof( V_228 -> V_229 ) ) ;
V_228 -> V_230 = V_231 | V_232 ;
V_228 -> V_233 = V_228 -> V_230 | V_234 ;
return 0 ;
}
static int F_93 ( struct V_42 * V_43 )
{
struct V_150 * V_151 = F_66 ( V_43 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_152 V_153 = { . type = V_154 ,} ;
T_1 V_218 = V_43 -> V_78 -> V_56 -> V_65 ;
unsigned long V_155 , V_156 ;
T_1 V_235 , V_236 ;
const struct V_77 * V_37 ;
int V_138 ;
int V_54 ;
const struct V_49 * V_50 ;
struct V_19 * V_20 = V_43 -> V_46 ;
V_37 = F_74 ( V_43 -> V_78 -> V_175 ) ;
if ( ! V_37 )
return - V_48 ;
V_50 = F_22 ( V_43 , V_218 ) ;
if ( ! V_50 ) {
F_69 ( V_20 , L_17 , V_218 ) ;
return - V_48 ;
}
V_138 = V_37 -> V_169 ;
V_54 = F_63 ( V_17 , V_138 , & V_155 ) ;
F_10 ( V_20 , L_22 , V_138 , V_54 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_67 ( V_151 , V_75 , V_157 , & V_153 ) ;
if ( ! V_54 ) {
V_156 = F_68 ( & V_153 ,
V_155 ) ;
if ( ! V_156 ) {
F_69 ( V_43 -> V_46 ,
L_12 ,
V_153 . V_93 , V_155 ) ;
return - V_48 ;
}
} else if ( V_54 != - V_158 ) {
return V_54 ;
} else {
V_156 = V_155 ;
}
F_10 ( V_20 , L_23 ,
V_153 . V_93 , V_155 , V_156 ) ;
if ( ( V_156 & V_141 ) &&
( V_156 & V_142 ) ) {
if ( V_17 -> V_115 & V_128 )
V_156 &= ~ V_141 ;
else
V_156 &= ~ V_142 ;
}
if ( ( V_156 & V_143 ) &&
( V_156 & V_144 ) ) {
if ( V_17 -> V_115 & V_130 )
V_156 &= ~ V_143 ;
else
V_156 &= ~ V_144 ;
}
if ( ( V_156 & V_147 ) &&
( V_156 & V_148 ) ) {
if ( V_17 -> V_115 & V_124 )
V_156 &= ~ V_147 ;
else
V_156 &= ~ V_148 ;
}
if ( ( V_156 & V_145 ) &&
( V_156 & V_146 ) ) {
if ( V_17 -> V_115 & V_126 )
V_156 &= ~ V_145 ;
else
V_156 &= ~ V_146 ;
}
V_153 . V_93 = V_156 ;
V_54 = F_67 ( V_151 , V_75 , V_237 , & V_153 ) ;
if ( V_54 < 0 && V_54 != - V_158 ) {
F_10 ( V_20 , L_24 ,
V_156 , V_54 ) ;
return V_54 ;
}
V_236 = F_1 ( V_17 , V_132 ) &
~ ( ( 1 << V_131 ) |
( 1 << V_129 ) |
( 1 << V_125 ) |
( 1 << V_127 ) |
( 3 << V_238 ) |
( 3 << V_117 ) ) ;
V_236 |= V_114 ;
if ( V_156 & V_146 )
V_236 |= 1 << V_127 ;
if ( V_156 & V_142 )
V_236 |= 1 << V_129 ;
if ( V_156 & V_144 )
V_236 |= 1 << V_131 ;
if ( V_156 & V_148 )
V_236 |= 1 << V_125 ;
switch ( V_50 -> V_56 -> V_169 ) {
case 4 :
V_235 = 0 << V_117 ;
break;
case 8 :
V_235 = 1 << V_117 ;
break;
case 10 :
V_235 = 2 << V_117 ;
break;
default:
case 15 :
V_235 = 3 << V_117 ;
}
F_3 ( V_17 , V_236 | V_235 , V_132 ) ;
F_10 ( V_20 , L_25 , V_236 | V_235 ) ;
return 0 ;
}
static int F_94 ( struct V_239 * V_240 )
{
struct V_161 * V_162 = V_240 -> V_20 . V_163 ;
struct V_1 * V_17 ;
struct V_241 * V_242 ;
void T_8 * V_4 ;
int V_243 = 0 ;
struct V_44 * V_135 ;
V_242 = F_95 ( V_240 , V_244 , 0 ) ;
V_4 = F_96 ( & V_240 -> V_20 , V_242 ) ;
if ( F_97 ( V_4 ) )
return F_98 ( V_4 ) ;
if ( ! V_162 )
return - V_48 ;
V_17 = F_99 ( & V_240 -> V_20 , sizeof( * V_17 ) , V_245 ) ;
if ( ! V_17 ) {
F_29 ( & V_240 -> V_20 , L_26 ) ;
return - V_246 ;
}
V_17 -> V_133 = F_100 ( & V_240 -> V_20 , NULL ) ;
if ( F_97 ( V_17 -> V_133 ) )
return F_98 ( V_17 -> V_133 ) ;
V_17 -> V_162 = V_162 ;
V_17 -> V_115 = V_162 -> V_93 ;
if ( ! ( V_17 -> V_115 & V_247 ) ) {
F_69 ( & V_240 -> V_20 , L_27
L_28 ) ;
V_17 -> V_115 |= V_119 ;
}
if ( V_17 -> V_115 & V_248 )
V_17 -> V_139 = 1 << 3 ;
if ( V_17 -> V_115 & V_119 )
V_17 -> V_139 |= 1 << 7 ;
if ( V_17 -> V_115 & V_118 )
V_17 -> V_139 |= 1 << 9 ;
if ( V_17 -> V_115 & V_116 )
V_17 -> V_139 |= 1 << 14 ;
V_17 -> V_134 = V_162 -> V_249 * 10000 ;
if ( ! V_17 -> V_134 ) {
F_69 ( & V_240 -> V_20 ,
L_29
L_30 ) ;
V_17 -> V_134 = 20000000 ;
}
F_45 ( & V_17 -> V_32 ) ;
F_101 ( & V_17 -> V_24 ) ;
V_17 -> V_4 = V_4 ;
V_135 = & V_17 -> V_135 ;
V_135 -> V_250 = V_251 ;
V_135 -> V_101 = & V_252 ;
V_135 -> V_47 = V_17 ;
V_135 -> V_136 . V_20 = & V_240 -> V_20 ;
V_135 -> V_253 = V_240 -> V_164 ;
V_17 -> V_60 = F_102 ( & V_240 -> V_20 ) ;
if ( F_97 ( V_17 -> V_60 ) )
return F_98 ( V_17 -> V_60 ) ;
if ( V_162 -> V_254 ) {
V_135 -> V_255 = V_162 -> V_255 ;
V_135 -> V_254 = V_162 -> V_254 ;
}
V_243 = F_103 ( V_135 ) ;
if ( V_243 )
goto V_256;
F_104 () ;
return 0 ;
V_256:
F_105 ( V_17 -> V_60 ) ;
return V_243 ;
}
static int F_106 ( struct V_239 * V_240 )
{
struct V_44 * V_135 = F_21 ( & V_240 -> V_20 ) ;
struct V_1 * V_17 = F_6 ( V_135 ,
struct V_1 , V_135 ) ;
F_107 ( V_135 ) ;
if ( F_108 ( V_17 -> V_15 [ 0 ] ) )
F_61 ( & V_17 -> V_15 [ 0 ] -> V_12 ) ;
F_105 ( V_17 -> V_60 ) ;
F_109 () ;
return 0 ;
}
