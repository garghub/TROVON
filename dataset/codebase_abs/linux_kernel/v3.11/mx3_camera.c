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
unsigned long V_79 ;
T_4 V_21 ;
T_5 V_80 ;
V_80 = V_43 -> V_59 ;
if ( F_28 ( V_8 , 0 ) < V_80 ) {
F_29 ( V_43 -> V_46 , L_2 ,
V_8 -> V_27 . V_81 , F_28 ( V_8 , 0 ) , V_80 ) ;
goto error;
}
if ( ! V_25 -> V_14 ) {
F_11 ( V_23 ) = F_30 ( V_8 , 0 ) ;
F_31 ( V_23 ) = V_80 ;
V_14 = F_32 (
& V_73 -> V_12 , V_23 , 1 , V_82 ,
V_83 ) ;
if ( ! V_14 )
goto error;
V_14 -> V_84 = V_14 ;
V_14 -> V_85 = F_7 ;
V_25 -> V_14 = V_14 ;
} else {
V_14 = V_25 -> V_14 ;
}
F_33 ( V_8 , 0 , V_80 ) ;
V_75 -> V_86 = F_26 ( V_56 -> V_65 ) ;
if ( V_75 -> V_86 == V_70 ) {
V_75 -> V_87 = V_43 -> V_57 ;
V_75 -> V_88 = V_43 -> V_89 ;
V_75 -> V_90 = V_43 -> V_57 ;
} else {
V_75 -> V_87 = V_43 -> V_91 ;
V_75 -> V_88 = V_43 -> V_89 ;
V_75 -> V_90 = V_43 -> V_91 ;
}
#ifdef F_34
if ( F_35 ( V_8 , 0 ) )
memset ( F_35 ( V_8 , 0 ) , 0xaa , F_36 ( V_8 , 0 ) ) ;
#endif
F_37 ( & V_17 -> V_24 , V_79 ) ;
F_38 ( & V_25 -> V_26 , & V_17 -> V_32 ) ;
if ( ! V_17 -> V_22 )
V_17 -> V_22 = V_25 ;
F_39 ( & V_17 -> V_24 ) ;
V_21 = V_14 -> V_92 ( V_14 ) ;
F_10 ( V_43 -> V_46 , L_3 ,
V_21 , F_11 ( & V_25 -> V_23 ) ) ;
if ( V_21 >= 0 )
return;
F_40 ( & V_17 -> V_24 ) ;
F_13 ( & V_25 -> V_26 ) ;
if ( V_17 -> V_22 == V_25 )
V_17 -> V_22 = NULL ;
F_41 ( & V_17 -> V_24 , V_79 ) ;
error:
F_15 ( V_8 , V_93 ) ;
}
static void F_42 ( struct V_7 * V_8 )
{
struct V_42 * V_43 = F_20 ( V_8 -> V_34 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_6 * V_25 = F_5 ( V_8 ) ;
struct V_72 * V_14 = V_25 -> V_14 ;
unsigned long V_79 ;
F_10 ( V_43 -> V_46 ,
L_4 ,
V_17 -> V_22 == V_25 ? L_5 : L_6 , F_11 ( & V_25 -> V_23 ) ,
F_16 ( & V_25 -> V_26 ) ? L_6 : L_7 ) ;
F_37 ( & V_17 -> V_24 , V_79 ) ;
if ( V_17 -> V_22 == V_25 )
V_17 -> V_22 = NULL ;
F_13 ( & V_25 -> V_26 ) ;
if ( V_14 ) {
V_25 -> V_14 = NULL ;
if ( V_17 -> V_15 [ 0 ] )
F_43 ( V_14 ) ;
}
F_41 ( & V_17 -> V_24 , V_79 ) ;
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
static int F_47 ( struct V_34 * V_94 )
{
struct V_42 * V_43 = F_20 ( V_94 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_15 * V_73 = V_17 -> V_15 [ 0 ] ;
struct V_6 * V_25 , * V_95 ;
unsigned long V_79 ;
if ( V_73 ) {
struct V_12 * V_13 = & V_73 -> V_12 ;
V_13 -> V_19 -> V_96 ( V_13 , V_97 , 0 ) ;
}
F_37 ( & V_17 -> V_24 , V_79 ) ;
V_17 -> V_22 = NULL ;
F_48 (buf, tmp, &mx3_cam->capture, queue) {
F_13 ( & V_25 -> V_26 ) ;
F_15 ( & V_25 -> V_8 , V_93 ) ;
}
F_41 ( & V_17 -> V_24 , V_79 ) ;
return 0 ;
}
static int F_49 ( struct V_34 * V_94 ,
struct V_42 * V_43 )
{
V_94 -> type = V_98 ;
V_94 -> V_99 = V_100 | V_101 ;
V_94 -> V_102 = V_43 ;
V_94 -> V_103 = & V_104 ;
V_94 -> V_105 = & V_106 ;
V_94 -> V_107 = sizeof( struct V_6 ) ;
V_94 -> V_108 = V_109 ;
return F_50 ( V_94 ) ;
}
static void F_51 ( struct V_1 * V_17 )
{
T_1 V_110 ;
long V_111 ;
F_3 ( V_17 , ( 640 - 1 ) | ( ( 480 - 1 ) << 16 ) , V_112 ) ;
V_110 = F_1 ( V_17 , V_113 ) & 0xffff0000 ;
F_3 ( V_17 , V_110 , V_113 ) ;
V_110 = 0 << V_114 ;
V_110 |= V_115 ;
if ( V_17 -> V_116 & V_117 )
V_110 |= 3 << V_118 ;
else if ( V_17 -> V_116 & V_119 )
V_110 |= 2 << V_118 ;
else if ( V_17 -> V_116 & V_120 )
V_110 |= 1 << V_118 ;
else
V_110 |= 0 << V_118 ;
if ( V_17 -> V_116 & V_121 )
V_110 |= 1 << V_122 ;
if ( V_17 -> V_116 & V_123 )
V_110 |= 1 << V_124 ;
if ( V_17 -> V_116 & V_125 )
V_110 |= 1 << V_126 ;
if ( V_17 -> V_116 & V_127 )
V_110 |= 1 << V_128 ;
if ( V_17 -> V_116 & V_129 )
V_110 |= 1 << V_130 ;
if ( V_17 -> V_116 & V_131 )
V_110 |= 1 << V_132 ;
F_3 ( V_17 , V_110 , V_133 ) ;
F_52 ( V_17 -> V_134 ) ;
V_111 = F_53 ( V_17 -> V_134 , V_17 -> V_135 ) ;
F_10 ( V_17 -> V_136 . V_137 . V_20 , L_8 , V_110 , V_111 ) ;
if ( V_111 )
F_54 ( V_17 -> V_134 , V_111 ) ;
}
static int F_55 ( struct V_42 * V_43 )
{
F_56 ( V_43 -> V_46 , L_9 ,
V_43 -> V_138 ) ;
return 0 ;
}
static void F_57 ( struct V_42 * V_43 )
{
F_56 ( V_43 -> V_46 , L_10 ,
V_43 -> V_138 ) ;
}
static int F_58 ( struct V_44 * V_45 )
{
struct V_1 * V_17 = V_45 -> V_47 ;
F_51 ( V_17 ) ;
V_17 -> V_62 = 0 ;
return 0 ;
}
static void F_59 ( struct V_44 * V_45 )
{
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_15 * * V_73 = & V_17 -> V_15 [ 0 ] ;
if ( * V_73 ) {
F_60 ( & ( * V_73 ) -> V_12 ) ;
* V_73 = NULL ;
}
F_61 ( V_17 -> V_134 ) ;
}
static int F_62 ( struct V_1 * V_17 ,
unsigned char V_139 , unsigned long * V_79 )
{
if ( V_139 > F_63 ( V_17 -> V_140 ) )
return - V_48 ;
* V_79 = V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 ;
return 0 ;
}
static int F_64 ( struct V_42 * V_43 ,
const unsigned int V_150 )
{
struct V_151 * V_152 = F_65 ( V_43 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_153 V_154 = { . type = V_155 ,} ;
unsigned long V_156 , V_157 ;
int V_54 = F_62 ( V_17 , V_150 , & V_156 ) ;
F_10 ( V_43 -> V_46 , L_11 , V_150 , V_54 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_66 ( V_152 , V_75 , V_158 , & V_154 ) ;
if ( ! V_54 ) {
V_157 = F_67 ( & V_154 ,
V_156 ) ;
if ( ! V_157 ) {
F_68 ( V_43 -> V_46 ,
L_12 ,
V_154 . V_79 , V_156 ) ;
return - V_48 ;
}
} else if ( V_54 != - V_159 ) {
return V_54 ;
}
return 0 ;
}
static bool F_69 ( struct V_12 * V_13 , void * V_9 )
{
struct V_160 * V_161 = V_9 ;
struct V_162 * V_163 ;
if ( ! F_70 ( V_13 ) )
return false ;
if ( ! V_161 )
return false ;
V_163 = V_161 -> V_17 -> V_136 . V_137 . V_20 -> V_164 ;
return V_161 -> V_165 == V_13 -> V_166 &&
V_163 -> V_167 == V_13 -> V_19 -> V_20 ;
}
static bool F_71 ( const struct V_77 * V_37 )
{
return V_37 -> V_168 == V_169 ||
( V_37 -> V_170 == 8 &&
V_37 -> V_168 == V_171 ) ||
( V_37 -> V_170 > 8 &&
V_37 -> V_168 == V_172 ) ;
}
static int F_72 ( struct V_42 * V_43 , unsigned int V_173 ,
struct V_49 * V_50 )
{
struct V_151 * V_152 = F_65 ( V_43 ) ;
struct V_19 * V_20 = V_43 -> V_46 ;
int V_174 = 0 , V_54 ;
enum V_175 V_176 ;
const struct V_77 * V_37 ;
V_54 = F_66 ( V_152 , V_75 , V_177 , V_173 , & V_176 ) ;
if ( V_54 < 0 )
return 0 ;
V_37 = F_73 ( V_176 ) ;
if ( ! V_37 ) {
F_68 ( V_43 -> V_46 ,
L_13 , V_173 , V_176 ) ;
return 0 ;
}
V_54 = F_64 ( V_43 , V_37 -> V_170 ) ;
if ( V_54 < 0 )
return 0 ;
switch ( V_176 ) {
case V_178 :
V_174 ++ ;
if ( V_50 ) {
V_50 -> V_56 = & V_179 [ 0 ] ;
V_50 -> V_176 = V_176 ;
V_50 ++ ;
F_10 ( V_20 , L_14 ,
V_179 [ 0 ] . V_180 , V_176 ) ;
}
break;
case V_181 :
V_174 ++ ;
if ( V_50 ) {
V_50 -> V_56 = & V_179 [ 1 ] ;
V_50 -> V_176 = V_176 ;
V_50 ++ ;
F_10 ( V_20 , L_14 ,
V_179 [ 1 ] . V_180 , V_176 ) ;
}
break;
default:
if ( ! F_71 ( V_37 ) )
return 0 ;
}
V_174 ++ ;
if ( V_50 ) {
V_50 -> V_56 = V_37 ;
V_50 -> V_176 = V_176 ;
F_10 ( V_20 , L_15 ,
( V_37 -> V_65 >> ( 0 * 8 ) ) & 0xFF ,
( V_37 -> V_65 >> ( 1 * 8 ) ) & 0xFF ,
( V_37 -> V_65 >> ( 2 * 8 ) ) & 0xFF ,
( V_37 -> V_65 >> ( 3 * 8 ) ) & 0xFF ) ;
V_50 ++ ;
}
return V_174 ;
}
static void F_74 ( struct V_1 * V_17 ,
unsigned int V_55 , unsigned int V_58 ,
const struct V_77 * V_37 )
{
T_1 V_182 , V_183 , V_184 ;
if ( F_26 ( V_37 -> V_65 ) == V_70 ) {
unsigned int V_185 , V_186 ;
int V_54 = F_75 ( V_37 , & V_185 , & V_186 ) ;
F_76 ( V_54 < 0 ) ;
V_55 = V_55 * V_185 / V_186 ;
}
V_183 = V_55 - 1 ;
V_184 = V_58 - 1 ;
F_3 ( V_17 , V_183 | ( V_184 << 16 ) , V_187 ) ;
F_3 ( V_17 , V_183 << 16 , V_188 ) ;
F_3 ( V_17 , ( V_184 << 16 ) | 0x22 , V_189 ) ;
F_3 ( V_17 , V_183 | ( V_184 << 16 ) , V_112 ) ;
V_182 = F_1 ( V_17 , V_113 ) & 0xffff0000 ;
F_3 ( V_17 , V_182 | 0 | ( 0 << 8 ) , V_113 ) ;
}
static int F_77 ( struct V_1 * V_17 )
{
T_6 V_190 ;
struct V_12 * V_13 ;
struct V_15 * * V_73 = & V_17 -> V_15 [ 0 ] ;
struct V_160 V_161 = { . V_17 = V_17 ,
. V_165 = V_191 } ;
F_78 ( V_190 ) ;
F_79 ( V_192 , V_190 ) ;
F_79 ( V_193 , V_190 ) ;
V_13 = F_80 ( V_190 , F_69 , & V_161 ) ;
if ( ! V_13 )
return - V_194 ;
* V_73 = F_9 ( V_13 ) ;
( * V_73 ) -> V_18 = V_17 ;
return 0 ;
}
static inline void F_81 ( T_3 * V_55 )
{
if ( F_82 ( * V_55 , 8 ) < 4096 )
* V_55 = F_82 ( * V_55 , 8 ) ;
else
* V_55 = * V_55 & ~ 7 ;
}
static int F_83 ( struct V_42 * V_43 ,
const struct V_195 * V_196 )
{
struct V_195 V_197 = * V_196 ;
struct V_198 * V_199 = & V_197 . V_200 ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_151 * V_152 = F_65 ( V_43 ) ;
struct V_201 V_202 ;
int V_54 ;
F_84 ( & V_199 -> V_203 , & V_199 -> V_55 , 0 , 2 , 4096 ) ;
F_84 ( & V_199 -> V_204 , & V_199 -> V_58 , 0 , 2 , 4096 ) ;
V_54 = F_66 ( V_152 , V_75 , V_205 , V_196 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_66 ( V_152 , V_75 , V_206 , & V_202 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_202 . V_176 != V_43 -> V_78 -> V_176 )
return - V_48 ;
if ( V_202 . V_55 & 7 ) {
F_81 ( & V_202 . V_55 ) ;
V_54 = F_66 ( V_152 , V_75 , V_207 , & V_202 ) ;
if ( V_54 < 0 )
return V_54 ;
}
if ( V_202 . V_55 != V_43 -> V_91 || V_202 . V_58 != V_43 -> V_89 )
F_74 ( V_17 , V_202 . V_55 , V_202 . V_58 ,
V_43 -> V_78 -> V_56 ) ;
F_10 ( V_43 -> V_46 , L_16 ,
V_202 . V_55 , V_202 . V_58 ) ;
V_43 -> V_91 = V_202 . V_55 ;
V_43 -> V_89 = V_202 . V_58 ;
return V_54 ;
}
static int F_85 ( struct V_42 * V_43 ,
struct V_36 * V_208 )
{
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_151 * V_152 = F_65 ( V_43 ) ;
const struct V_49 * V_50 ;
struct V_209 * V_51 = & V_208 -> V_37 . V_51 ;
struct V_201 V_202 ;
int V_54 ;
V_50 = F_22 ( V_43 , V_51 -> V_52 ) ;
if ( ! V_50 ) {
F_68 ( V_43 -> V_46 , L_17 ,
V_51 -> V_52 ) ;
return - V_48 ;
}
F_81 ( & V_51 -> V_55 ) ;
F_10 ( V_43 -> V_46 , L_18 , V_51 -> V_55 , V_51 -> V_58 ) ;
F_74 ( V_17 , V_51 -> V_55 , V_51 -> V_58 , V_50 -> V_56 ) ;
V_202 . V_55 = V_51 -> V_55 ;
V_202 . V_58 = V_51 -> V_58 ;
V_202 . V_29 = V_51 -> V_29 ;
V_202 . V_210 = V_51 -> V_210 ;
V_202 . V_176 = V_50 -> V_176 ;
V_54 = F_66 ( V_152 , V_75 , V_207 , & V_202 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_202 . V_176 != V_50 -> V_176 )
return - V_48 ;
if ( ! V_17 -> V_15 [ 0 ] ) {
V_54 = F_77 ( V_17 ) ;
if ( V_54 < 0 )
return V_54 ;
}
V_51 -> V_55 = V_202 . V_55 ;
V_51 -> V_58 = V_202 . V_58 ;
V_51 -> V_29 = V_202 . V_29 ;
V_17 -> V_29 = V_202 . V_29 ;
V_51 -> V_210 = V_202 . V_210 ;
V_43 -> V_78 = V_50 ;
F_10 ( V_43 -> V_46 , L_19 , V_51 -> V_55 , V_51 -> V_58 ) ;
return V_54 ;
}
static int F_86 ( struct V_42 * V_43 ,
struct V_36 * V_208 )
{
struct V_151 * V_152 = F_65 ( V_43 ) ;
const struct V_49 * V_50 ;
struct V_209 * V_51 = & V_208 -> V_37 . V_51 ;
struct V_201 V_202 ;
T_3 V_211 = V_51 -> V_52 ;
int V_54 ;
V_50 = F_22 ( V_43 , V_211 ) ;
if ( V_211 && ! V_50 ) {
F_68 ( V_43 -> V_46 , L_17 , V_211 ) ;
return - V_48 ;
}
if ( V_51 -> V_58 > 4096 )
V_51 -> V_58 = 4096 ;
if ( V_51 -> V_55 > 4096 )
V_51 -> V_55 = 4096 ;
V_202 . V_55 = V_51 -> V_55 ;
V_202 . V_58 = V_51 -> V_58 ;
V_202 . V_29 = V_51 -> V_29 ;
V_202 . V_210 = V_51 -> V_210 ;
V_202 . V_176 = V_50 -> V_176 ;
V_54 = F_66 ( V_152 , V_75 , V_212 , & V_202 ) ;
if ( V_54 < 0 )
return V_54 ;
V_51 -> V_55 = V_202 . V_55 ;
V_51 -> V_58 = V_202 . V_58 ;
V_51 -> V_210 = V_202 . V_210 ;
switch ( V_202 . V_29 ) {
case V_213 :
V_51 -> V_29 = V_214 ;
break;
case V_214 :
break;
default:
F_29 ( V_43 -> V_46 , L_20 ,
V_202 . V_29 ) ;
V_54 = - V_48 ;
}
return V_54 ;
}
static int F_87 ( struct V_42 * V_43 ,
struct V_215 * V_216 )
{
return 0 ;
}
static unsigned int F_88 ( struct V_217 * V_217 , T_7 * V_218 )
{
struct V_42 * V_43 = V_217 -> V_219 ;
return F_89 ( & V_43 -> V_220 , V_217 , V_218 ) ;
}
static int F_90 ( struct V_44 * V_45 ,
struct V_221 * V_222 )
{
F_91 ( V_222 -> V_223 , L_21 , sizeof( V_222 -> V_223 ) ) ;
V_222 -> V_224 = V_225 | V_226 ;
return 0 ;
}
static int F_92 ( struct V_42 * V_43 )
{
struct V_151 * V_152 = F_65 ( V_43 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_153 V_154 = { . type = V_155 ,} ;
T_1 V_211 = V_43 -> V_78 -> V_56 -> V_65 ;
unsigned long V_156 , V_157 ;
T_1 V_227 , V_228 ;
const struct V_77 * V_37 ;
int V_139 ;
int V_54 ;
const struct V_49 * V_50 ;
struct V_19 * V_20 = V_43 -> V_46 ;
V_37 = F_73 ( V_43 -> V_78 -> V_176 ) ;
if ( ! V_37 )
return - V_48 ;
V_50 = F_22 ( V_43 , V_211 ) ;
if ( ! V_50 ) {
F_68 ( V_20 , L_17 , V_211 ) ;
return - V_48 ;
}
V_139 = V_37 -> V_170 ;
V_54 = F_62 ( V_17 , V_139 , & V_156 ) ;
F_10 ( V_20 , L_22 , V_139 , V_54 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_66 ( V_152 , V_75 , V_158 , & V_154 ) ;
if ( ! V_54 ) {
V_157 = F_67 ( & V_154 ,
V_156 ) ;
if ( ! V_157 ) {
F_68 ( V_43 -> V_46 ,
L_12 ,
V_154 . V_79 , V_156 ) ;
return - V_48 ;
}
} else if ( V_54 != - V_159 ) {
return V_54 ;
} else {
V_157 = V_156 ;
}
F_10 ( V_20 , L_23 ,
V_154 . V_79 , V_156 , V_157 ) ;
if ( ( V_157 & V_142 ) &&
( V_157 & V_143 ) ) {
if ( V_17 -> V_116 & V_129 )
V_157 &= ~ V_142 ;
else
V_157 &= ~ V_143 ;
}
if ( ( V_157 & V_144 ) &&
( V_157 & V_145 ) ) {
if ( V_17 -> V_116 & V_131 )
V_157 &= ~ V_144 ;
else
V_157 &= ~ V_145 ;
}
if ( ( V_157 & V_148 ) &&
( V_157 & V_149 ) ) {
if ( V_17 -> V_116 & V_125 )
V_157 &= ~ V_148 ;
else
V_157 &= ~ V_149 ;
}
if ( ( V_157 & V_146 ) &&
( V_157 & V_147 ) ) {
if ( V_17 -> V_116 & V_127 )
V_157 &= ~ V_146 ;
else
V_157 &= ~ V_147 ;
}
V_154 . V_79 = V_157 ;
V_54 = F_66 ( V_152 , V_75 , V_229 , & V_154 ) ;
if ( V_54 < 0 && V_54 != - V_159 ) {
F_10 ( V_20 , L_24 ,
V_157 , V_54 ) ;
return V_54 ;
}
V_228 = F_1 ( V_17 , V_133 ) &
~ ( ( 1 << V_132 ) |
( 1 << V_130 ) |
( 1 << V_126 ) |
( 1 << V_128 ) |
( 3 << V_230 ) |
( 3 << V_118 ) ) ;
V_228 |= V_115 ;
if ( V_157 & V_147 )
V_228 |= 1 << V_128 ;
if ( V_157 & V_143 )
V_228 |= 1 << V_130 ;
if ( V_157 & V_145 )
V_228 |= 1 << V_132 ;
if ( V_157 & V_149 )
V_228 |= 1 << V_126 ;
switch ( V_50 -> V_56 -> V_170 ) {
case 4 :
V_227 = 0 << V_118 ;
break;
case 8 :
V_227 = 1 << V_118 ;
break;
case 10 :
V_227 = 2 << V_118 ;
break;
default:
case 15 :
V_227 = 3 << V_118 ;
}
F_3 ( V_17 , V_228 | V_227 , V_133 ) ;
F_10 ( V_20 , L_25 , V_228 | V_227 ) ;
return 0 ;
}
static int F_93 ( struct V_231 * V_232 )
{
struct V_1 * V_17 ;
struct V_233 * V_234 ;
void T_8 * V_4 ;
int V_235 = 0 ;
struct V_44 * V_136 ;
V_234 = F_94 ( V_232 , V_236 , 0 ) ;
if ( ! V_234 ) {
V_235 = - V_237 ;
goto V_238;
}
V_17 = F_95 ( sizeof( * V_17 ) ) ;
if ( ! V_17 ) {
F_29 ( & V_232 -> V_20 , L_26 ) ;
V_235 = - V_239 ;
goto V_240;
}
V_17 -> V_134 = F_96 ( & V_232 -> V_20 , NULL ) ;
if ( F_97 ( V_17 -> V_134 ) ) {
V_235 = F_98 ( V_17 -> V_134 ) ;
goto V_241;
}
V_17 -> V_163 = V_232 -> V_20 . V_164 ;
V_17 -> V_116 = V_17 -> V_163 -> V_79 ;
if ( ! ( V_17 -> V_116 & V_242 ) ) {
F_68 ( & V_232 -> V_20 , L_27
L_28 ) ;
V_17 -> V_116 |= V_120 ;
}
if ( V_17 -> V_116 & V_243 )
V_17 -> V_140 = 1 << 3 ;
if ( V_17 -> V_116 & V_120 )
V_17 -> V_140 |= 1 << 7 ;
if ( V_17 -> V_116 & V_119 )
V_17 -> V_140 |= 1 << 9 ;
if ( V_17 -> V_116 & V_117 )
V_17 -> V_140 |= 1 << 14 ;
V_17 -> V_135 = V_17 -> V_163 -> V_244 * 10000 ;
if ( ! V_17 -> V_135 ) {
F_68 ( & V_232 -> V_20 ,
L_29
L_30 ) ;
V_17 -> V_135 = 20000000 ;
}
F_45 ( & V_17 -> V_32 ) ;
F_99 ( & V_17 -> V_24 ) ;
V_4 = F_100 ( V_234 -> V_245 , F_101 ( V_234 ) ) ;
if ( ! V_4 ) {
F_102 ( L_31 , F_101 ( V_234 ) , V_234 -> V_245 ) ;
V_235 = - V_239 ;
goto V_246;
}
V_17 -> V_4 = V_4 ;
V_136 = & V_17 -> V_136 ;
V_136 -> V_247 = V_248 ;
V_136 -> V_103 = & V_249 ;
V_136 -> V_47 = V_17 ;
V_136 -> V_137 . V_20 = & V_232 -> V_20 ;
V_136 -> V_250 = V_232 -> V_165 ;
V_17 -> V_60 = F_103 ( & V_232 -> V_20 ) ;
if ( F_97 ( V_17 -> V_60 ) ) {
V_235 = F_98 ( V_17 -> V_60 ) ;
goto V_251;
}
V_235 = F_104 ( V_136 ) ;
if ( V_235 )
goto V_252;
F_105 () ;
return 0 ;
V_252:
F_106 ( V_17 -> V_60 ) ;
V_251:
F_107 ( V_4 ) ;
V_246:
F_108 ( V_17 -> V_134 ) ;
V_241:
F_109 ( V_17 ) ;
V_240:
V_238:
return V_235 ;
}
static int F_110 ( struct V_231 * V_232 )
{
struct V_44 * V_136 = F_21 ( & V_232 -> V_20 ) ;
struct V_1 * V_17 = F_6 ( V_136 ,
struct V_1 , V_136 ) ;
F_108 ( V_17 -> V_134 ) ;
F_111 ( V_136 ) ;
F_107 ( V_17 -> V_4 ) ;
if ( F_112 ( V_17 -> V_15 [ 0 ] ) )
F_60 ( & V_17 -> V_15 [ 0 ] -> V_12 ) ;
F_106 ( V_17 -> V_60 ) ;
F_109 ( V_17 ) ;
F_113 () ;
return 0 ;
}
