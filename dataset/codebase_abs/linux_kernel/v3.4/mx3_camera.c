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
V_14 = F_31 (
& V_73 -> V_12 , V_23 , 1 , V_83 ,
V_84 ) ;
if ( ! V_14 )
goto error;
V_14 -> V_85 = V_14 ;
V_14 -> V_86 = F_7 ;
V_25 -> V_81 = V_87 ;
V_25 -> V_14 = V_14 ;
} else {
V_14 = V_25 -> V_14 ;
}
F_32 ( V_8 , 0 , V_79 ) ;
V_75 -> V_88 = F_24 ( V_56 -> V_65 ) ;
if ( V_75 -> V_88 == V_70 ) {
V_75 -> V_89 = V_48 ;
V_75 -> V_90 = V_43 -> V_59 ;
V_75 -> V_91 = V_48 ;
} else {
V_75 -> V_89 = V_43 -> V_57 ;
V_75 -> V_90 = V_43 -> V_59 ;
V_75 -> V_91 = V_43 -> V_57 ;
}
#ifdef F_33
if ( F_34 ( V_8 , 0 ) )
memset ( F_34 ( V_8 , 0 ) , 0xaa , F_35 ( V_8 , 0 ) ) ;
#endif
F_36 ( & V_17 -> V_24 , V_78 ) ;
F_37 ( & V_25 -> V_26 , & V_17 -> V_32 ) ;
if ( ! V_17 -> V_22 )
V_17 -> V_22 = V_25 ;
F_38 ( & V_17 -> V_24 ) ;
V_21 = V_14 -> V_92 ( V_14 ) ;
F_10 ( V_43 -> V_46 , L_3 ,
V_21 , F_11 ( & V_25 -> V_23 ) ) ;
if ( V_21 >= 0 )
return;
F_39 ( & V_17 -> V_24 ) ;
F_13 ( & V_25 -> V_26 ) ;
if ( V_17 -> V_22 == V_25 )
V_17 -> V_22 = NULL ;
F_40 ( & V_17 -> V_24 , V_78 ) ;
error:
F_15 ( V_8 , V_93 ) ;
}
static void F_41 ( struct V_7 * V_8 )
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
F_36 ( & V_17 -> V_24 , V_78 ) ;
if ( V_17 -> V_22 == V_25 )
V_17 -> V_22 = NULL ;
F_13 ( & V_25 -> V_26 ) ;
V_25 -> V_81 = V_82 ;
if ( V_14 ) {
V_25 -> V_14 = NULL ;
if ( V_17 -> V_15 [ 0 ] )
F_42 ( V_14 ) ;
}
F_40 ( & V_17 -> V_24 , V_78 ) ;
V_17 -> V_62 -= F_27 ( V_8 , 0 ) ;
}
static int F_43 ( struct V_7 * V_8 )
{
struct V_42 * V_43 = F_20 ( V_8 -> V_34 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_6 * V_25 = F_5 ( V_8 ) ;
F_44 ( & V_25 -> V_26 ) ;
F_45 ( & V_25 -> V_23 , 1 ) ;
V_25 -> V_81 = V_82 ;
V_17 -> V_62 += F_27 ( V_8 , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_34 * V_94 )
{
struct V_42 * V_43 = F_20 ( V_94 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_15 * V_73 = V_17 -> V_15 [ 0 ] ;
struct V_6 * V_25 , * V_95 ;
unsigned long V_78 ;
if ( V_73 ) {
struct V_12 * V_13 = & V_73 -> V_12 ;
V_13 -> V_19 -> V_96 ( V_13 , V_97 , 0 ) ;
}
F_36 ( & V_17 -> V_24 , V_78 ) ;
V_17 -> V_22 = NULL ;
F_47 (buf, tmp, &mx3_cam->capture, queue) {
F_13 ( & V_25 -> V_26 ) ;
F_15 ( & V_25 -> V_8 , V_93 ) ;
}
F_40 ( & V_17 -> V_24 , V_78 ) ;
return 0 ;
}
static int F_48 ( struct V_34 * V_94 ,
struct V_42 * V_43 )
{
V_94 -> type = V_98 ;
V_94 -> V_99 = V_100 | V_101 ;
V_94 -> V_102 = V_43 ;
V_94 -> V_103 = & V_104 ;
V_94 -> V_105 = & V_106 ;
V_94 -> V_107 = sizeof( struct V_6 ) ;
return F_49 ( V_94 ) ;
}
static void F_50 ( struct V_1 * V_17 ,
struct V_42 * V_43 )
{
T_1 V_108 ;
long V_109 ;
F_3 ( V_17 , ( 640 - 1 ) | ( ( 480 - 1 ) << 16 ) , V_110 ) ;
V_108 = F_1 ( V_17 , V_111 ) & 0xffff0000 ;
F_3 ( V_17 , V_108 , V_111 ) ;
V_108 = 0 << V_112 ;
V_108 |= V_113 ;
if ( V_17 -> V_114 & V_115 )
V_108 |= 3 << V_116 ;
else if ( V_17 -> V_114 & V_117 )
V_108 |= 2 << V_116 ;
else if ( V_17 -> V_114 & V_118 )
V_108 |= 1 << V_116 ;
else
V_108 |= 0 << V_116 ;
if ( V_17 -> V_114 & V_119 )
V_108 |= 1 << V_120 ;
if ( V_17 -> V_114 & V_121 )
V_108 |= 1 << V_122 ;
if ( V_17 -> V_114 & V_123 )
V_108 |= 1 << V_124 ;
if ( V_17 -> V_114 & V_125 )
V_108 |= 1 << V_126 ;
if ( V_17 -> V_114 & V_127 )
V_108 |= 1 << V_128 ;
if ( V_17 -> V_114 & V_129 )
V_108 |= 1 << V_130 ;
F_3 ( V_17 , V_108 , V_131 ) ;
F_51 ( V_17 -> V_132 ) ;
V_109 = F_52 ( V_17 -> V_132 , V_17 -> V_133 ) ;
F_10 ( V_43 -> V_46 , L_8 , V_108 , V_109 ) ;
if ( V_109 )
F_53 ( V_17 -> V_132 , V_109 ) ;
}
static int F_54 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
if ( V_17 -> V_43 )
return - V_134 ;
F_50 ( V_17 , V_43 ) ;
V_17 -> V_62 = 0 ;
V_17 -> V_43 = V_43 ;
F_55 ( V_43 -> V_46 , L_9 ,
V_43 -> V_135 ) ;
return 0 ;
}
static void F_56 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_15 * * V_73 = & V_17 -> V_15 [ 0 ] ;
F_26 ( V_43 != V_17 -> V_43 ) ;
if ( * V_73 ) {
F_57 ( & ( * V_73 ) -> V_12 ) ;
* V_73 = NULL ;
}
F_58 ( V_17 -> V_132 ) ;
V_17 -> V_43 = NULL ;
F_55 ( V_43 -> V_46 , L_10 ,
V_43 -> V_135 ) ;
}
static int F_59 ( struct V_1 * V_17 ,
unsigned char V_136 , unsigned long * V_78 )
{
if ( V_136 > F_60 ( V_17 -> V_137 ) )
return - V_50 ;
* V_78 = V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 ;
return 0 ;
}
static int F_61 ( struct V_42 * V_43 ,
const unsigned int V_147 )
{
struct V_148 * V_149 = F_62 ( V_43 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_150 V_151 = { . type = V_152 ,} ;
unsigned long V_153 , V_154 ;
int V_155 = F_59 ( V_17 , V_147 , & V_153 ) ;
F_10 ( V_43 -> V_46 , L_11 , V_147 , V_155 ) ;
if ( V_155 < 0 )
return V_155 ;
V_155 = F_63 ( V_149 , V_75 , V_156 , & V_151 ) ;
if ( ! V_155 ) {
V_154 = F_64 ( & V_151 ,
V_153 ) ;
if ( ! V_154 ) {
F_65 ( V_43 -> V_46 ,
L_12 ,
V_151 . V_78 , V_153 ) ;
return - V_50 ;
}
} else if ( V_155 != - V_157 ) {
return V_155 ;
}
return 0 ;
}
static bool F_66 ( struct V_12 * V_13 , void * V_9 )
{
struct V_158 * V_159 = V_9 ;
struct V_160 * V_161 ;
if ( ! F_67 ( V_13 ) )
return false ;
if ( ! V_159 )
return false ;
V_161 = V_159 -> V_17 -> V_162 . V_163 . V_20 -> V_164 ;
return V_159 -> V_165 == V_13 -> V_166 &&
V_161 -> V_167 == V_13 -> V_19 -> V_20 ;
}
static bool F_68 ( const struct V_77 * V_37 )
{
return V_37 -> V_168 == V_169 ||
( V_37 -> V_170 == 8 &&
V_37 -> V_168 == V_171 ) ||
( V_37 -> V_170 > 8 &&
V_37 -> V_168 == V_172 ) ;
}
static int F_69 ( struct V_42 * V_43 , unsigned int V_173 ,
struct V_51 * V_52 )
{
struct V_148 * V_149 = F_62 ( V_43 ) ;
struct V_19 * V_20 = V_43 -> V_46 ;
int V_174 = 0 , V_155 ;
enum V_175 V_176 ;
const struct V_77 * V_37 ;
V_155 = F_63 ( V_149 , V_75 , V_177 , V_173 , & V_176 ) ;
if ( V_155 < 0 )
return 0 ;
V_37 = F_70 ( V_176 ) ;
if ( ! V_37 ) {
F_65 ( V_43 -> V_46 ,
L_13 , V_173 , V_176 ) ;
return 0 ;
}
V_155 = F_61 ( V_43 , V_37 -> V_170 ) ;
if ( V_155 < 0 )
return 0 ;
switch ( V_176 ) {
case V_178 :
V_174 ++ ;
if ( V_52 ) {
V_52 -> V_56 = & V_179 [ 0 ] ;
V_52 -> V_176 = V_176 ;
V_52 ++ ;
F_10 ( V_20 , L_14 ,
V_179 [ 0 ] . V_180 , V_176 ) ;
}
break;
case V_181 :
V_174 ++ ;
if ( V_52 ) {
V_52 -> V_56 = & V_179 [ 1 ] ;
V_52 -> V_176 = V_176 ;
V_52 ++ ;
F_10 ( V_20 , L_14 ,
V_179 [ 1 ] . V_180 , V_176 ) ;
}
break;
default:
if ( ! F_68 ( V_37 ) )
return 0 ;
}
V_174 ++ ;
if ( V_52 ) {
V_52 -> V_56 = V_37 ;
V_52 -> V_176 = V_176 ;
F_10 ( V_20 , L_15 ,
( V_37 -> V_65 >> ( 0 * 8 ) ) & 0xFF ,
( V_37 -> V_65 >> ( 1 * 8 ) ) & 0xFF ,
( V_37 -> V_65 >> ( 2 * 8 ) ) & 0xFF ,
( V_37 -> V_65 >> ( 3 * 8 ) ) & 0xFF ) ;
V_52 ++ ;
}
return V_174 ;
}
static void F_71 ( struct V_1 * V_17 ,
unsigned int V_55 , unsigned int V_49 ,
const struct V_77 * V_37 )
{
T_1 V_182 , V_183 , V_184 ;
if ( F_24 ( V_37 -> V_65 ) == V_70 ) {
unsigned int V_185 , V_186 ;
int V_155 = F_72 ( V_37 , & V_185 , & V_186 ) ;
F_26 ( V_155 < 0 ) ;
V_55 = V_55 * V_185 / V_186 ;
}
V_183 = V_55 - 1 ;
V_184 = V_49 - 1 ;
F_3 ( V_17 , V_183 | ( V_184 << 16 ) , V_187 ) ;
F_3 ( V_17 , V_183 << 16 , V_188 ) ;
F_3 ( V_17 , ( V_184 << 16 ) | 0x22 , V_189 ) ;
F_3 ( V_17 , V_183 | ( V_184 << 16 ) , V_110 ) ;
V_182 = F_1 ( V_17 , V_111 ) & 0xffff0000 ;
F_3 ( V_17 , V_182 | 0 | ( 0 << 8 ) , V_111 ) ;
}
static int F_73 ( struct V_1 * V_17 )
{
T_6 V_190 ;
struct V_12 * V_13 ;
struct V_15 * * V_73 = & V_17 -> V_15 [ 0 ] ;
struct V_158 V_159 = { . V_17 = V_17 ,
. V_165 = V_191 } ;
F_74 ( V_190 ) ;
F_75 ( V_192 , V_190 ) ;
F_75 ( V_193 , V_190 ) ;
V_13 = F_76 ( V_190 , F_66 , & V_159 ) ;
if ( ! V_13 )
return - V_134 ;
* V_73 = F_9 ( V_13 ) ;
( * V_73 ) -> V_18 = V_17 ;
return 0 ;
}
static inline void F_77 ( T_3 * V_55 )
{
if ( F_78 ( * V_55 , 8 ) < 4096 )
* V_55 = F_78 ( * V_55 , 8 ) ;
else
* V_55 = * V_55 & ~ 7 ;
}
static int F_79 ( struct V_42 * V_43 ,
struct V_194 * V_195 )
{
struct V_196 * V_197 = & V_195 -> V_198 ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_148 * V_149 = F_62 ( V_43 ) ;
struct V_199 V_200 ;
int V_155 ;
F_80 ( & V_197 -> V_201 , & V_197 -> V_55 , 0 , 2 , 4096 ) ;
F_80 ( & V_197 -> V_202 , & V_197 -> V_49 , 0 , 2 , 4096 ) ;
V_155 = F_63 ( V_149 , V_75 , V_203 , V_195 ) ;
if ( V_155 < 0 )
return V_155 ;
V_155 = F_63 ( V_149 , V_75 , V_204 , & V_200 ) ;
if ( V_155 < 0 )
return V_155 ;
if ( V_200 . V_176 != V_43 -> V_58 -> V_176 )
return - V_50 ;
if ( V_200 . V_55 & 7 ) {
F_77 ( & V_200 . V_55 ) ;
V_155 = F_63 ( V_149 , V_75 , V_205 , & V_200 ) ;
if ( V_155 < 0 )
return V_155 ;
}
if ( V_200 . V_55 != V_43 -> V_57 || V_200 . V_49 != V_43 -> V_59 )
F_71 ( V_17 , V_200 . V_55 , V_200 . V_49 ,
V_43 -> V_58 -> V_56 ) ;
F_10 ( V_43 -> V_46 , L_16 ,
V_200 . V_55 , V_200 . V_49 ) ;
V_43 -> V_57 = V_200 . V_55 ;
V_43 -> V_59 = V_200 . V_49 ;
return V_155 ;
}
static int F_81 ( struct V_42 * V_43 ,
struct V_36 * V_206 )
{
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_148 * V_149 = F_62 ( V_43 ) ;
const struct V_51 * V_52 ;
struct V_207 * V_53 = & V_206 -> V_37 . V_53 ;
struct V_199 V_200 ;
int V_155 ;
V_52 = F_22 ( V_43 , V_53 -> V_54 ) ;
if ( ! V_52 ) {
F_65 ( V_43 -> V_46 , L_17 ,
V_53 -> V_54 ) ;
return - V_50 ;
}
F_77 ( & V_53 -> V_55 ) ;
F_10 ( V_43 -> V_46 , L_18 , V_53 -> V_55 , V_53 -> V_49 ) ;
F_71 ( V_17 , V_53 -> V_55 , V_53 -> V_49 , V_52 -> V_56 ) ;
V_200 . V_55 = V_53 -> V_55 ;
V_200 . V_49 = V_53 -> V_49 ;
V_200 . V_29 = V_53 -> V_29 ;
V_200 . V_208 = V_53 -> V_208 ;
V_200 . V_176 = V_52 -> V_176 ;
V_155 = F_63 ( V_149 , V_75 , V_205 , & V_200 ) ;
if ( V_155 < 0 )
return V_155 ;
if ( V_200 . V_176 != V_52 -> V_176 )
return - V_50 ;
if ( ! V_17 -> V_15 [ 0 ] ) {
V_155 = F_73 ( V_17 ) ;
if ( V_155 < 0 )
return V_155 ;
}
V_53 -> V_55 = V_200 . V_55 ;
V_53 -> V_49 = V_200 . V_49 ;
V_53 -> V_29 = V_200 . V_29 ;
V_17 -> V_29 = V_200 . V_29 ;
V_53 -> V_208 = V_200 . V_208 ;
V_43 -> V_58 = V_52 ;
F_10 ( V_43 -> V_46 , L_19 , V_53 -> V_55 , V_53 -> V_49 ) ;
return V_155 ;
}
static int F_82 ( struct V_42 * V_43 ,
struct V_36 * V_206 )
{
struct V_148 * V_149 = F_62 ( V_43 ) ;
const struct V_51 * V_52 ;
struct V_207 * V_53 = & V_206 -> V_37 . V_53 ;
struct V_199 V_200 ;
T_3 V_209 = V_53 -> V_54 ;
int V_155 ;
V_52 = F_22 ( V_43 , V_209 ) ;
if ( V_209 && ! V_52 ) {
F_65 ( V_43 -> V_46 , L_17 , V_209 ) ;
return - V_50 ;
}
if ( V_53 -> V_49 > 4096 )
V_53 -> V_49 = 4096 ;
if ( V_53 -> V_55 > 4096 )
V_53 -> V_55 = 4096 ;
V_200 . V_55 = V_53 -> V_55 ;
V_200 . V_49 = V_53 -> V_49 ;
V_200 . V_29 = V_53 -> V_29 ;
V_200 . V_208 = V_53 -> V_208 ;
V_200 . V_176 = V_52 -> V_176 ;
V_155 = F_63 ( V_149 , V_75 , V_210 , & V_200 ) ;
if ( V_155 < 0 )
return V_155 ;
V_53 -> V_55 = V_200 . V_55 ;
V_53 -> V_49 = V_200 . V_49 ;
V_53 -> V_208 = V_200 . V_208 ;
switch ( V_200 . V_29 ) {
case V_211 :
V_53 -> V_29 = V_212 ;
break;
case V_212 :
break;
default:
F_28 ( V_43 -> V_46 , L_20 ,
V_200 . V_29 ) ;
V_155 = - V_50 ;
}
return V_155 ;
}
static int F_83 ( struct V_42 * V_43 ,
struct V_213 * V_214 )
{
return 0 ;
}
static unsigned int F_84 ( struct V_215 * V_215 , T_7 * V_216 )
{
struct V_42 * V_43 = V_215 -> V_217 ;
return F_85 ( & V_43 -> V_218 , V_215 , V_216 ) ;
}
static int F_86 ( struct V_44 * V_45 ,
struct V_219 * V_220 )
{
F_87 ( V_220 -> V_221 , L_21 , sizeof( V_220 -> V_221 ) ) ;
V_220 -> V_222 = V_223 | V_224 ;
return 0 ;
}
static int F_88 ( struct V_42 * V_43 )
{
struct V_148 * V_149 = F_62 ( V_43 ) ;
struct V_44 * V_45 = F_21 ( V_43 -> V_46 ) ;
struct V_1 * V_17 = V_45 -> V_47 ;
struct V_150 V_151 = { . type = V_152 ,} ;
T_1 V_209 = V_43 -> V_58 -> V_56 -> V_65 ;
unsigned long V_153 , V_154 ;
T_1 V_225 , V_226 ;
const struct V_77 * V_37 ;
int V_136 ;
int V_155 ;
const struct V_51 * V_52 ;
struct V_19 * V_20 = V_43 -> V_46 ;
V_37 = F_70 ( V_43 -> V_58 -> V_176 ) ;
if ( ! V_37 )
return - V_50 ;
V_52 = F_22 ( V_43 , V_209 ) ;
if ( ! V_52 ) {
F_65 ( V_20 , L_17 , V_209 ) ;
return - V_50 ;
}
V_136 = V_37 -> V_170 ;
V_155 = F_59 ( V_17 , V_136 , & V_153 ) ;
F_10 ( V_20 , L_22 , V_136 , V_155 ) ;
if ( V_155 < 0 )
return V_155 ;
V_155 = F_63 ( V_149 , V_75 , V_156 , & V_151 ) ;
if ( ! V_155 ) {
V_154 = F_64 ( & V_151 ,
V_153 ) ;
if ( ! V_154 ) {
F_65 ( V_43 -> V_46 ,
L_12 ,
V_151 . V_78 , V_153 ) ;
return - V_50 ;
}
} else if ( V_155 != - V_157 ) {
return V_155 ;
} else {
V_154 = V_153 ;
}
F_10 ( V_20 , L_23 ,
V_151 . V_78 , V_153 , V_154 ) ;
if ( ( V_154 & V_139 ) &&
( V_154 & V_140 ) ) {
if ( V_17 -> V_114 & V_127 )
V_154 &= ~ V_139 ;
else
V_154 &= ~ V_140 ;
}
if ( ( V_154 & V_141 ) &&
( V_154 & V_142 ) ) {
if ( V_17 -> V_114 & V_129 )
V_154 &= ~ V_141 ;
else
V_154 &= ~ V_142 ;
}
if ( ( V_154 & V_145 ) &&
( V_154 & V_146 ) ) {
if ( V_17 -> V_114 & V_123 )
V_154 &= ~ V_145 ;
else
V_154 &= ~ V_146 ;
}
if ( ( V_154 & V_143 ) &&
( V_154 & V_144 ) ) {
if ( V_17 -> V_114 & V_125 )
V_154 &= ~ V_143 ;
else
V_154 &= ~ V_144 ;
}
V_151 . V_78 = V_154 ;
V_155 = F_63 ( V_149 , V_75 , V_227 , & V_151 ) ;
if ( V_155 < 0 && V_155 != - V_157 ) {
F_10 ( V_20 , L_24 ,
V_154 , V_155 ) ;
return V_155 ;
}
V_226 = F_1 ( V_17 , V_131 ) &
~ ( ( 1 << V_130 ) |
( 1 << V_128 ) |
( 1 << V_124 ) |
( 1 << V_126 ) |
( 3 << V_228 ) |
( 3 << V_116 ) ) ;
V_226 |= V_113 ;
if ( V_154 & V_144 )
V_226 |= 1 << V_126 ;
if ( V_154 & V_140 )
V_226 |= 1 << V_128 ;
if ( V_154 & V_142 )
V_226 |= 1 << V_130 ;
if ( V_154 & V_146 )
V_226 |= 1 << V_124 ;
switch ( V_52 -> V_56 -> V_170 ) {
case 4 :
V_225 = 0 << V_116 ;
break;
case 8 :
V_225 = 1 << V_116 ;
break;
case 10 :
V_225 = 2 << V_116 ;
break;
default:
case 15 :
V_225 = 3 << V_116 ;
}
F_3 ( V_17 , V_226 | V_225 , V_131 ) ;
F_10 ( V_20 , L_25 , V_226 | V_225 ) ;
return 0 ;
}
static int T_8 F_89 ( struct V_229 * V_230 )
{
struct V_1 * V_17 ;
struct V_231 * V_232 ;
void T_9 * V_4 ;
int V_233 = 0 ;
struct V_44 * V_162 ;
V_232 = F_90 ( V_230 , V_234 , 0 ) ;
if ( ! V_232 ) {
V_233 = - V_235 ;
goto V_236;
}
V_17 = F_91 ( sizeof( * V_17 ) ) ;
if ( ! V_17 ) {
F_28 ( & V_230 -> V_20 , L_26 ) ;
V_233 = - V_237 ;
goto V_238;
}
V_17 -> V_132 = F_92 ( & V_230 -> V_20 , NULL ) ;
if ( F_93 ( V_17 -> V_132 ) ) {
V_233 = F_94 ( V_17 -> V_132 ) ;
goto V_239;
}
V_17 -> V_161 = V_230 -> V_20 . V_164 ;
V_17 -> V_114 = V_17 -> V_161 -> V_78 ;
if ( ! ( V_17 -> V_114 & ( V_240 |
V_118 | V_117 |
V_115 ) ) ) {
F_65 ( & V_230 -> V_20 , L_27
L_28 ) ;
V_17 -> V_114 |= V_118 ;
}
if ( V_17 -> V_114 & V_240 )
V_17 -> V_137 = 1 << 3 ;
if ( V_17 -> V_114 & V_118 )
V_17 -> V_137 |= 1 << 7 ;
if ( V_17 -> V_114 & V_117 )
V_17 -> V_137 |= 1 << 9 ;
if ( V_17 -> V_114 & V_115 )
V_17 -> V_137 |= 1 << 14 ;
V_17 -> V_133 = V_17 -> V_161 -> V_241 * 10000 ;
if ( ! V_17 -> V_133 ) {
F_65 ( & V_230 -> V_20 ,
L_29
L_30 ) ;
V_17 -> V_133 = 20000000 ;
}
F_44 ( & V_17 -> V_32 ) ;
F_95 ( & V_17 -> V_24 ) ;
V_4 = F_96 ( V_232 -> V_242 , F_97 ( V_232 ) ) ;
if ( ! V_4 ) {
F_98 ( L_31 , F_97 ( V_232 ) , V_232 -> V_242 ) ;
V_233 = - V_237 ;
goto V_243;
}
V_17 -> V_4 = V_4 ;
V_162 = & V_17 -> V_162 ;
V_162 -> V_244 = V_245 ;
V_162 -> V_103 = & V_246 ;
V_162 -> V_47 = V_17 ;
V_162 -> V_163 . V_20 = & V_230 -> V_20 ;
V_162 -> V_247 = V_230 -> V_165 ;
V_17 -> V_60 = F_99 ( & V_230 -> V_20 ) ;
if ( F_93 ( V_17 -> V_60 ) ) {
V_233 = F_94 ( V_17 -> V_60 ) ;
goto V_248;
}
V_233 = F_100 ( V_162 ) ;
if ( V_233 )
goto V_249;
F_101 () ;
return 0 ;
V_249:
F_102 ( V_17 -> V_60 ) ;
V_248:
F_103 ( V_4 ) ;
V_243:
F_104 ( V_17 -> V_132 ) ;
V_239:
F_105 ( V_17 ) ;
V_238:
V_236:
return V_233 ;
}
static int T_10 F_106 ( struct V_229 * V_230 )
{
struct V_44 * V_162 = F_21 ( & V_230 -> V_20 ) ;
struct V_1 * V_17 = F_6 ( V_162 ,
struct V_1 , V_162 ) ;
F_104 ( V_17 -> V_132 ) ;
F_107 ( V_162 ) ;
F_103 ( V_17 -> V_4 ) ;
if ( F_108 ( V_17 -> V_15 [ 0 ] ) )
F_57 ( & V_17 -> V_15 [ 0 ] -> V_12 ) ;
F_102 ( V_17 -> V_60 ) ;
F_105 ( V_17 ) ;
F_109 () ;
return 0 ;
}
