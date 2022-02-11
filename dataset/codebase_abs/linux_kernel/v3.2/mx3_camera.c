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
int V_48 ;
unsigned int V_49 ;
if ( ! V_17 -> V_15 [ 0 ] )
return - V_50 ;
if ( V_37 ) {
const struct V_51 * V_52 = F_22 ( V_43 ,
V_37 -> V_37 . V_53 . V_54 ) ;
if ( ! V_52 )
return - V_50 ;
V_48 = F_23 ( V_37 -> V_37 . V_53 . V_55 ,
V_52 -> V_56 ) ;
V_49 = V_37 -> V_37 . V_53 . V_49 ;
} else {
V_48 = F_23 ( V_43 -> V_57 ,
V_43 -> V_58 -> V_56 ) ;
V_49 = V_43 -> V_59 ;
}
if ( V_48 < 0 )
return V_48 ;
V_40 [ 0 ] = V_48 * V_49 ;
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
static enum V_64 F_24 ( T_3 V_65 )
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
static void F_25 ( struct V_7 * V_8 )
{
struct V_42 * V_43 = F_20 ( V_8 -> V_34 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_6 * V_25 = F_5 ( V_8 ) ;
struct V_71 * V_23 = & V_25 -> V_23 ;
struct V_72 * V_14 ;
struct V_15 * V_73 = V_17 -> V_15 [ 0 ] ;
struct V_74 * V_75 = & V_73 -> V_76 . V_75 ;
const struct V_77 * V_56 = V_43 -> V_58 -> V_56 ;
int V_48 = F_23 ( V_43 -> V_57 , V_56 ) ;
unsigned long V_78 ;
T_4 V_21 ;
T_5 V_79 ;
F_26 ( V_48 <= 0 ) ;
V_79 = V_48 * V_43 -> V_59 ;
if ( F_27 ( V_8 , 0 ) < V_79 ) {
F_28 ( V_43 -> V_46 , L_2 ,
V_8 -> V_27 . V_80 , F_27 ( V_8 , 0 ) , V_79 ) ;
goto error;
}
if ( V_25 -> V_81 == V_82 ) {
F_11 ( V_23 ) = F_29 ( V_8 , 0 ) ;
F_30 ( V_23 ) = V_79 ;
V_14 = V_73 -> V_12 . V_19 -> V_83 (
& V_73 -> V_12 , V_23 , 1 , V_84 ,
V_85 ) ;
if ( ! V_14 )
goto error;
V_14 -> V_86 = V_14 ;
V_14 -> V_87 = F_7 ;
V_25 -> V_81 = V_88 ;
V_25 -> V_14 = V_14 ;
} else {
V_14 = V_25 -> V_14 ;
}
F_31 ( V_8 , 0 , V_79 ) ;
V_75 -> V_89 = F_24 ( V_56 -> V_65 ) ;
if ( V_75 -> V_89 == V_70 ) {
V_75 -> V_90 = V_48 ;
V_75 -> V_91 = V_43 -> V_59 ;
V_75 -> V_92 = V_48 ;
} else {
V_75 -> V_90 = V_43 -> V_57 ;
V_75 -> V_91 = V_43 -> V_59 ;
V_75 -> V_92 = V_43 -> V_57 ;
}
#ifdef F_32
if ( F_33 ( V_8 , 0 ) )
memset ( F_33 ( V_8 , 0 ) , 0xaa , F_34 ( V_8 , 0 ) ) ;
#endif
F_35 ( & V_17 -> V_24 , V_78 ) ;
F_36 ( & V_25 -> V_26 , & V_17 -> V_32 ) ;
if ( ! V_17 -> V_22 )
V_17 -> V_22 = V_25 ;
F_37 ( & V_17 -> V_24 ) ;
V_21 = V_14 -> V_93 ( V_14 ) ;
F_10 ( V_43 -> V_46 , L_3 ,
V_21 , F_11 ( & V_25 -> V_23 ) ) ;
if ( V_21 >= 0 )
return;
F_38 ( & V_17 -> V_24 ) ;
F_13 ( & V_25 -> V_26 ) ;
if ( V_17 -> V_22 == V_25 )
V_17 -> V_22 = NULL ;
F_39 ( & V_17 -> V_24 , V_78 ) ;
error:
F_15 ( V_8 , V_94 ) ;
}
static void F_40 ( struct V_7 * V_8 )
{
struct V_42 * V_43 = F_20 ( V_8 -> V_34 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_6 * V_25 = F_5 ( V_8 ) ;
struct V_72 * V_14 = V_25 -> V_14 ;
unsigned long V_78 ;
F_10 ( V_43 -> V_46 ,
L_4 ,
V_17 -> V_22 == V_25 ? L_5 : L_6 , F_11 ( & V_25 -> V_23 ) ,
F_16 ( & V_25 -> V_26 ) ? L_6 : L_7 ) ;
F_35 ( & V_17 -> V_24 , V_78 ) ;
if ( V_17 -> V_22 == V_25 )
V_17 -> V_22 = NULL ;
F_13 ( & V_25 -> V_26 ) ;
V_25 -> V_81 = V_82 ;
if ( V_14 ) {
V_25 -> V_14 = NULL ;
if ( V_17 -> V_15 [ 0 ] )
F_41 ( V_14 ) ;
}
F_39 ( & V_17 -> V_24 , V_78 ) ;
V_17 -> V_62 -= F_27 ( V_8 , 0 ) ;
}
static int F_42 ( struct V_7 * V_8 )
{
struct V_42 * V_43 = F_20 ( V_8 -> V_34 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_6 * V_25 = F_5 ( V_8 ) ;
F_43 ( & V_25 -> V_26 ) ;
F_44 ( & V_25 -> V_23 , 1 ) ;
V_25 -> V_81 = V_82 ;
V_17 -> V_62 += F_27 ( V_8 , 0 ) ;
return 0 ;
}
static int F_45 ( struct V_34 * V_95 )
{
struct V_42 * V_43 = F_20 ( V_95 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_15 * V_73 = V_17 -> V_15 [ 0 ] ;
struct V_6 * V_25 , * V_96 ;
unsigned long V_78 ;
if ( V_73 ) {
struct V_12 * V_13 = & V_73 -> V_12 ;
V_13 -> V_19 -> V_97 ( V_13 , V_98 , 0 ) ;
}
F_35 ( & V_17 -> V_24 , V_78 ) ;
V_17 -> V_22 = NULL ;
F_46 (buf, tmp, &mx3_cam->capture, queue) {
F_13 ( & V_25 -> V_26 ) ;
F_15 ( & V_25 -> V_8 , V_94 ) ;
}
F_39 ( & V_17 -> V_24 , V_78 ) ;
return 0 ;
}
static int F_47 ( struct V_34 * V_95 ,
struct V_42 * V_43 )
{
V_95 -> type = V_99 ;
V_95 -> V_100 = V_101 | V_102 ;
V_95 -> V_103 = V_43 ;
V_95 -> V_104 = & V_105 ;
V_95 -> V_106 = & V_107 ;
V_95 -> V_108 = sizeof( struct V_6 ) ;
return F_48 ( V_95 ) ;
}
static void F_49 ( struct V_1 * V_17 ,
struct V_42 * V_43 )
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
F_50 ( V_17 -> V_133 ) ;
V_110 = F_51 ( V_17 -> V_133 , V_17 -> V_134 ) ;
F_10 ( V_43 -> V_46 , L_8 , V_109 , V_110 ) ;
if ( V_110 )
F_52 ( V_17 -> V_133 , V_110 ) ;
}
static int F_53 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
if ( V_17 -> V_43 )
return - V_135 ;
F_49 ( V_17 , V_43 ) ;
V_17 -> V_62 = 0 ;
V_17 -> V_43 = V_43 ;
F_54 ( V_43 -> V_46 , L_9 ,
V_43 -> V_136 ) ;
return 0 ;
}
static void F_55 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_15 * * V_73 = & V_17 -> V_15 [ 0 ] ;
F_26 ( V_43 != V_17 -> V_43 ) ;
if ( * V_73 ) {
F_56 ( & ( * V_73 ) -> V_12 ) ;
* V_73 = NULL ;
}
F_57 ( V_17 -> V_133 ) ;
V_17 -> V_43 = NULL ;
F_54 ( V_43 -> V_46 , L_10 ,
V_43 -> V_136 ) ;
}
static int F_58 ( struct V_1 * V_17 ,
unsigned char V_137 , unsigned long * V_78 )
{
if ( V_137 > F_59 ( V_17 -> V_138 ) )
return - V_50 ;
* V_78 = V_139 |
V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 ;
return 0 ;
}
static int F_60 ( struct V_42 * V_43 ,
const unsigned int V_148 )
{
struct V_149 * V_150 = F_61 ( V_43 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_151 V_152 = { . type = V_153 ,} ;
unsigned long V_154 , V_155 ;
int V_156 = F_58 ( V_17 , V_148 , & V_154 ) ;
F_10 ( V_43 -> V_46 , L_11 , V_148 , V_156 ) ;
if ( V_156 < 0 )
return V_156 ;
V_156 = F_62 ( V_150 , V_75 , V_157 , & V_152 ) ;
if ( ! V_156 ) {
V_155 = F_63 ( & V_152 ,
V_154 ) ;
if ( ! V_155 ) {
F_64 ( V_43 -> V_46 ,
L_12 ,
V_152 . V_78 , V_154 ) ;
return - V_50 ;
}
} else if ( V_156 != - V_158 ) {
return V_156 ;
}
return 0 ;
}
static bool F_65 ( struct V_12 * V_13 , void * V_9 )
{
struct V_159 * V_160 = V_9 ;
struct V_161 * V_162 ;
if ( ! F_66 ( V_13 ) )
return false ;
if ( ! V_160 )
return false ;
V_162 = V_160 -> V_17 -> V_163 . V_164 . V_20 -> V_165 ;
return V_160 -> V_166 == V_13 -> V_167 &&
V_162 -> V_168 == V_13 -> V_19 -> V_20 ;
}
static bool F_67 ( const struct V_77 * V_37 )
{
return V_37 -> V_169 == V_170 ||
( V_37 -> V_171 == 8 &&
V_37 -> V_169 == V_172 ) ||
( V_37 -> V_171 > 8 &&
V_37 -> V_169 == V_173 ) ;
}
static int F_68 ( struct V_42 * V_43 , unsigned int V_174 ,
struct V_51 * V_52 )
{
struct V_149 * V_150 = F_61 ( V_43 ) ;
struct V_19 * V_20 = V_43 -> V_46 ;
int V_175 = 0 , V_156 ;
enum V_176 V_177 ;
const struct V_77 * V_37 ;
V_156 = F_62 ( V_150 , V_75 , V_178 , V_174 , & V_177 ) ;
if ( V_156 < 0 )
return 0 ;
V_37 = F_69 ( V_177 ) ;
if ( ! V_37 ) {
F_64 ( V_43 -> V_46 ,
L_13 , V_174 , V_177 ) ;
return 0 ;
}
V_156 = F_60 ( V_43 , V_37 -> V_171 ) ;
if ( V_156 < 0 )
return 0 ;
switch ( V_177 ) {
case V_179 :
V_175 ++ ;
if ( V_52 ) {
V_52 -> V_56 = & V_180 [ 0 ] ;
V_52 -> V_177 = V_177 ;
V_52 ++ ;
F_10 ( V_20 , L_14 ,
V_180 [ 0 ] . V_181 , V_177 ) ;
}
break;
case V_182 :
V_175 ++ ;
if ( V_52 ) {
V_52 -> V_56 = & V_180 [ 1 ] ;
V_52 -> V_177 = V_177 ;
V_52 ++ ;
F_10 ( V_20 , L_14 ,
V_180 [ 1 ] . V_181 , V_177 ) ;
}
break;
default:
if ( ! F_67 ( V_37 ) )
return 0 ;
}
V_175 ++ ;
if ( V_52 ) {
V_52 -> V_56 = V_37 ;
V_52 -> V_177 = V_177 ;
F_10 ( V_20 , L_15 ,
( V_37 -> V_65 >> ( 0 * 8 ) ) & 0xFF ,
( V_37 -> V_65 >> ( 1 * 8 ) ) & 0xFF ,
( V_37 -> V_65 >> ( 2 * 8 ) ) & 0xFF ,
( V_37 -> V_65 >> ( 3 * 8 ) ) & 0xFF ) ;
V_52 ++ ;
}
return V_175 ;
}
static void F_70 ( struct V_1 * V_17 ,
unsigned int V_55 , unsigned int V_49 ,
const struct V_77 * V_37 )
{
T_1 V_183 , V_184 , V_185 ;
if ( F_24 ( V_37 -> V_65 ) == V_70 ) {
unsigned int V_186 , V_187 ;
int V_156 = F_71 ( V_37 , & V_186 , & V_187 ) ;
F_26 ( V_156 < 0 ) ;
V_55 = V_55 * V_186 / V_187 ;
}
V_184 = V_55 - 1 ;
V_185 = V_49 - 1 ;
F_3 ( V_17 , V_184 | ( V_185 << 16 ) , V_188 ) ;
F_3 ( V_17 , V_184 << 16 , V_189 ) ;
F_3 ( V_17 , ( V_185 << 16 ) | 0x22 , V_190 ) ;
F_3 ( V_17 , V_184 | ( V_185 << 16 ) , V_111 ) ;
V_183 = F_1 ( V_17 , V_112 ) & 0xffff0000 ;
F_3 ( V_17 , V_183 | 0 | ( 0 << 8 ) , V_112 ) ;
}
static int F_72 ( struct V_1 * V_17 )
{
T_6 V_191 ;
struct V_12 * V_13 ;
struct V_15 * * V_73 = & V_17 -> V_15 [ 0 ] ;
struct V_159 V_160 = { . V_17 = V_17 ,
. V_166 = V_192 } ;
F_73 ( V_191 ) ;
F_74 ( V_193 , V_191 ) ;
F_74 ( V_194 , V_191 ) ;
V_13 = F_75 ( V_191 , F_65 , & V_160 ) ;
if ( ! V_13 )
return - V_135 ;
* V_73 = F_9 ( V_13 ) ;
( * V_73 ) -> V_18 = V_17 ;
return 0 ;
}
static inline void F_76 ( T_3 * V_55 )
{
if ( F_77 ( * V_55 , 8 ) < 4096 )
* V_55 = F_77 ( * V_55 , 8 ) ;
else
* V_55 = * V_55 & ~ 7 ;
}
static int F_78 ( struct V_42 * V_43 ,
struct V_195 * V_196 )
{
struct V_197 * V_198 = & V_196 -> V_199 ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_149 * V_150 = F_61 ( V_43 ) ;
struct V_200 V_201 ;
int V_156 ;
F_79 ( & V_198 -> V_202 , & V_198 -> V_55 , 0 , 2 , 4096 ) ;
F_79 ( & V_198 -> V_203 , & V_198 -> V_49 , 0 , 2 , 4096 ) ;
V_156 = F_62 ( V_150 , V_75 , V_204 , V_196 ) ;
if ( V_156 < 0 )
return V_156 ;
V_156 = F_62 ( V_150 , V_75 , V_205 , & V_201 ) ;
if ( V_156 < 0 )
return V_156 ;
if ( V_201 . V_177 != V_43 -> V_58 -> V_177 )
return - V_50 ;
if ( V_201 . V_55 & 7 ) {
F_76 ( & V_201 . V_55 ) ;
V_156 = F_62 ( V_150 , V_75 , V_206 , & V_201 ) ;
if ( V_156 < 0 )
return V_156 ;
}
if ( V_201 . V_55 != V_43 -> V_57 || V_201 . V_49 != V_43 -> V_59 )
F_70 ( V_17 , V_201 . V_55 , V_201 . V_49 ,
V_43 -> V_58 -> V_56 ) ;
F_10 ( V_43 -> V_46 , L_16 ,
V_201 . V_55 , V_201 . V_49 ) ;
V_43 -> V_57 = V_201 . V_55 ;
V_43 -> V_59 = V_201 . V_49 ;
return V_156 ;
}
static int F_80 ( struct V_42 * V_43 ,
struct V_36 * V_207 )
{
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_149 * V_150 = F_61 ( V_43 ) ;
const struct V_51 * V_52 ;
struct V_208 * V_53 = & V_207 -> V_37 . V_53 ;
struct V_200 V_201 ;
int V_156 ;
V_52 = F_22 ( V_43 , V_53 -> V_54 ) ;
if ( ! V_52 ) {
F_64 ( V_43 -> V_46 , L_17 ,
V_53 -> V_54 ) ;
return - V_50 ;
}
F_76 ( & V_53 -> V_55 ) ;
F_10 ( V_43 -> V_46 , L_18 , V_53 -> V_55 , V_53 -> V_49 ) ;
F_70 ( V_17 , V_53 -> V_55 , V_53 -> V_49 , V_52 -> V_56 ) ;
V_201 . V_55 = V_53 -> V_55 ;
V_201 . V_49 = V_53 -> V_49 ;
V_201 . V_29 = V_53 -> V_29 ;
V_201 . V_209 = V_53 -> V_209 ;
V_201 . V_177 = V_52 -> V_177 ;
V_156 = F_62 ( V_150 , V_75 , V_206 , & V_201 ) ;
if ( V_156 < 0 )
return V_156 ;
if ( V_201 . V_177 != V_52 -> V_177 )
return - V_50 ;
if ( ! V_17 -> V_15 [ 0 ] ) {
V_156 = F_72 ( V_17 ) ;
if ( V_156 < 0 )
return V_156 ;
}
V_53 -> V_55 = V_201 . V_55 ;
V_53 -> V_49 = V_201 . V_49 ;
V_53 -> V_29 = V_201 . V_29 ;
V_17 -> V_29 = V_201 . V_29 ;
V_53 -> V_209 = V_201 . V_209 ;
V_43 -> V_58 = V_52 ;
F_10 ( V_43 -> V_46 , L_19 , V_53 -> V_55 , V_53 -> V_49 ) ;
return V_156 ;
}
static int F_81 ( struct V_42 * V_43 ,
struct V_36 * V_207 )
{
struct V_149 * V_150 = F_61 ( V_43 ) ;
const struct V_51 * V_52 ;
struct V_208 * V_53 = & V_207 -> V_37 . V_53 ;
struct V_200 V_201 ;
T_3 V_210 = V_53 -> V_54 ;
int V_156 ;
V_52 = F_22 ( V_43 , V_210 ) ;
if ( V_210 && ! V_52 ) {
F_64 ( V_43 -> V_46 , L_17 , V_210 ) ;
return - V_50 ;
}
if ( V_53 -> V_49 > 4096 )
V_53 -> V_49 = 4096 ;
if ( V_53 -> V_55 > 4096 )
V_53 -> V_55 = 4096 ;
V_201 . V_55 = V_53 -> V_55 ;
V_201 . V_49 = V_53 -> V_49 ;
V_201 . V_29 = V_53 -> V_29 ;
V_201 . V_209 = V_53 -> V_209 ;
V_201 . V_177 = V_52 -> V_177 ;
V_156 = F_62 ( V_150 , V_75 , V_211 , & V_201 ) ;
if ( V_156 < 0 )
return V_156 ;
V_53 -> V_55 = V_201 . V_55 ;
V_53 -> V_49 = V_201 . V_49 ;
V_53 -> V_209 = V_201 . V_209 ;
switch ( V_201 . V_29 ) {
case V_212 :
V_53 -> V_29 = V_213 ;
break;
case V_213 :
break;
default:
F_28 ( V_43 -> V_46 , L_20 ,
V_201 . V_29 ) ;
V_156 = - V_50 ;
}
return V_156 ;
}
static int F_82 ( struct V_42 * V_43 ,
struct V_214 * V_215 )
{
return 0 ;
}
static unsigned int F_83 ( struct V_216 * V_216 , T_7 * V_217 )
{
struct V_42 * V_43 = V_216 -> V_218 ;
return F_84 ( & V_43 -> V_219 , V_216 , V_217 ) ;
}
static int F_85 ( struct V_44 * V_45 ,
struct V_220 * V_221 )
{
F_86 ( V_221 -> V_222 , L_21 , sizeof( V_221 -> V_222 ) ) ;
V_221 -> V_223 = V_224 | V_225 ;
return 0 ;
}
static int F_87 ( struct V_42 * V_43 , T_3 V_210 )
{
struct V_149 * V_150 = F_61 ( V_43 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_151 V_152 = { . type = V_153 ,} ;
unsigned long V_154 , V_155 ;
T_1 V_226 , V_227 ;
const struct V_77 * V_37 ;
int V_137 ;
int V_156 ;
const struct V_51 * V_52 ;
struct V_19 * V_20 = V_43 -> V_46 ;
V_37 = F_69 ( V_43 -> V_58 -> V_177 ) ;
if ( ! V_37 )
return - V_50 ;
V_52 = F_22 ( V_43 , V_210 ) ;
if ( ! V_52 ) {
F_64 ( V_20 , L_17 , V_210 ) ;
return - V_50 ;
}
V_137 = V_37 -> V_171 ;
V_156 = F_58 ( V_17 , V_137 , & V_154 ) ;
F_10 ( V_20 , L_22 , V_137 , V_156 ) ;
if ( V_156 < 0 )
return V_156 ;
V_156 = F_62 ( V_150 , V_75 , V_157 , & V_152 ) ;
if ( ! V_156 ) {
V_155 = F_63 ( & V_152 ,
V_154 ) ;
if ( ! V_155 ) {
F_64 ( V_43 -> V_46 ,
L_12 ,
V_152 . V_78 , V_154 ) ;
return - V_50 ;
}
} else if ( V_156 != - V_158 ) {
return V_156 ;
} else {
V_155 = V_154 ;
}
F_10 ( V_20 , L_23 ,
V_152 . V_78 , V_154 , V_155 ) ;
if ( ( V_155 & V_140 ) &&
( V_155 & V_141 ) ) {
if ( V_17 -> V_115 & V_128 )
V_155 &= ~ V_140 ;
else
V_155 &= ~ V_141 ;
}
if ( ( V_155 & V_142 ) &&
( V_155 & V_143 ) ) {
if ( V_17 -> V_115 & V_130 )
V_155 &= ~ V_142 ;
else
V_155 &= ~ V_143 ;
}
if ( ( V_155 & V_146 ) &&
( V_155 & V_147 ) ) {
if ( V_17 -> V_115 & V_124 )
V_155 &= ~ V_146 ;
else
V_155 &= ~ V_147 ;
}
if ( ( V_155 & V_144 ) &&
( V_155 & V_145 ) ) {
if ( V_17 -> V_115 & V_126 )
V_155 &= ~ V_144 ;
else
V_155 &= ~ V_145 ;
}
V_152 . V_78 = V_155 ;
V_156 = F_62 ( V_150 , V_75 , V_228 , & V_152 ) ;
if ( V_156 < 0 && V_156 != - V_158 ) {
F_10 ( V_20 , L_24 ,
V_155 , V_156 ) ;
return V_156 ;
}
V_227 = F_1 ( V_17 , V_132 ) &
~ ( ( 1 << V_131 ) |
( 1 << V_129 ) |
( 1 << V_125 ) |
( 1 << V_127 ) |
( 3 << V_229 ) |
( 3 << V_117 ) ) ;
V_227 |= V_114 ;
if ( V_155 & V_145 )
V_227 |= 1 << V_127 ;
if ( V_155 & V_141 )
V_227 |= 1 << V_129 ;
if ( V_155 & V_143 )
V_227 |= 1 << V_131 ;
if ( V_155 & V_147 )
V_227 |= 1 << V_125 ;
switch ( V_52 -> V_56 -> V_171 ) {
case 4 :
V_226 = 0 << V_117 ;
break;
case 8 :
V_226 = 1 << V_117 ;
break;
case 10 :
V_226 = 2 << V_117 ;
break;
default:
case 15 :
V_226 = 3 << V_117 ;
}
F_3 ( V_17 , V_227 | V_226 , V_132 ) ;
F_10 ( V_20 , L_25 , V_227 | V_226 ) ;
return 0 ;
}
static int T_8 F_88 ( struct V_230 * V_231 )
{
struct V_1 * V_17 ;
struct V_232 * V_233 ;
void T_9 * V_4 ;
int V_234 = 0 ;
struct V_44 * V_163 ;
V_233 = F_89 ( V_231 , V_235 , 0 ) ;
if ( ! V_233 ) {
V_234 = - V_236 ;
goto V_237;
}
V_17 = F_90 ( sizeof( * V_17 ) ) ;
if ( ! V_17 ) {
F_28 ( & V_231 -> V_20 , L_26 ) ;
V_234 = - V_238 ;
goto V_239;
}
V_17 -> V_133 = F_91 ( & V_231 -> V_20 , NULL ) ;
if ( F_92 ( V_17 -> V_133 ) ) {
V_234 = F_93 ( V_17 -> V_133 ) ;
goto V_240;
}
V_17 -> V_162 = V_231 -> V_20 . V_165 ;
V_17 -> V_115 = V_17 -> V_162 -> V_78 ;
if ( ! ( V_17 -> V_115 & ( V_241 |
V_119 | V_118 |
V_116 ) ) ) {
F_64 ( & V_231 -> V_20 , L_27
L_28 ) ;
V_17 -> V_115 |= V_119 ;
}
if ( V_17 -> V_115 & V_241 )
V_17 -> V_138 = 1 << 3 ;
if ( V_17 -> V_115 & V_119 )
V_17 -> V_138 |= 1 << 7 ;
if ( V_17 -> V_115 & V_118 )
V_17 -> V_138 |= 1 << 9 ;
if ( V_17 -> V_115 & V_116 )
V_17 -> V_138 |= 1 << 14 ;
V_17 -> V_134 = V_17 -> V_162 -> V_242 * 10000 ;
if ( ! V_17 -> V_134 ) {
F_64 ( & V_231 -> V_20 ,
L_29
L_30 ) ;
V_17 -> V_134 = 20000000 ;
}
F_43 ( & V_17 -> V_32 ) ;
F_94 ( & V_17 -> V_24 ) ;
V_4 = F_95 ( V_233 -> V_243 , F_96 ( V_233 ) ) ;
if ( ! V_4 ) {
F_97 ( L_31 , F_96 ( V_233 ) , V_233 -> V_243 ) ;
V_234 = - V_238 ;
goto V_244;
}
V_17 -> V_4 = V_4 ;
V_163 = & V_17 -> V_163 ;
V_163 -> V_245 = V_246 ;
V_163 -> V_104 = & V_247 ;
V_163 -> V_47 = V_17 ;
V_163 -> V_164 . V_20 = & V_231 -> V_20 ;
V_163 -> V_248 = V_231 -> V_166 ;
V_17 -> V_60 = F_98 ( & V_231 -> V_20 ) ;
if ( F_92 ( V_17 -> V_60 ) ) {
V_234 = F_93 ( V_17 -> V_60 ) ;
goto V_249;
}
V_234 = F_99 ( V_163 ) ;
if ( V_234 )
goto V_250;
F_100 () ;
return 0 ;
V_250:
F_101 ( V_17 -> V_60 ) ;
V_249:
F_102 ( V_4 ) ;
V_244:
F_103 ( V_17 -> V_133 ) ;
V_240:
F_104 ( V_17 ) ;
V_239:
V_237:
return V_234 ;
}
static int T_10 F_105 ( struct V_230 * V_231 )
{
struct V_44 * V_163 = F_21 ( & V_231 -> V_20 ) ;
struct V_1 * V_17 = F_6 ( V_163 ,
struct V_1 , V_163 ) ;
F_103 ( V_17 -> V_133 ) ;
F_106 ( V_163 ) ;
F_102 ( V_17 -> V_4 ) ;
if ( F_107 ( V_17 -> V_15 [ 0 ] ) )
F_56 ( & V_17 -> V_15 [ 0 ] -> V_12 ) ;
F_101 ( V_17 -> V_60 ) ;
F_104 ( V_17 ) ;
F_108 () ;
return 0 ;
}
static int T_11 F_109 ( void )
{
return F_110 ( & V_251 ) ;
}
static void T_12 F_111 ( void )
{
F_112 ( & V_251 ) ;
}
