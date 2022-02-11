static int
F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
const struct V_5 * V_6 = & V_7 [ V_4 ] ;
struct V_8 * V_9 ;
F_2 ( V_2 -> V_9 [ V_4 ] ) ;
V_9 = F_3 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return - V_11 ;
V_9 -> V_4 = V_4 ;
V_9 -> V_12 = V_2 ;
V_9 -> V_13 = V_6 -> V_13 ;
V_9 -> V_14 = V_6 -> V_14 ;
V_9 -> V_15 = V_9 -> V_16 = V_6 -> V_15 ;
V_9 -> V_17 = V_6 -> V_17 ;
V_9 -> V_18 = V_6 -> V_18 ;
V_9 -> V_19 = NULL ;
F_4 ( & V_9 -> V_20 ) ;
V_2 -> V_9 [ V_4 ] = V_9 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_6 ( V_2 ) ;
unsigned int V_23 = F_7 ( V_2 ) -> V_23 ;
unsigned int V_24 = 0 ;
struct V_8 * V_9 ;
enum V_3 V_4 ;
unsigned int V_25 ;
int V_26 ;
F_8 ( V_23 == 0 ) ;
F_8 ( V_23 &
F_9 ( sizeof( V_24 ) * V_27 - 1 , V_28 ) ) ;
for ( V_25 = 0 ; V_25 < F_10 ( V_7 ) ; V_25 ++ ) {
if ( ! F_11 ( V_2 , V_25 ) )
continue;
V_26 = F_1 ( V_2 , V_25 ) ;
if ( V_26 )
goto V_29;
V_24 |= F_12 ( V_25 ) ;
}
if ( F_8 ( V_24 != V_23 ) )
V_22 -> V_23 = V_24 ;
V_22 -> V_30 = F_13 ( V_24 ) ;
return 0 ;
V_29:
F_14 (engine, dev_priv, id)
F_15 ( V_9 ) ;
return V_26 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_6 ( V_2 ) ;
struct V_8 * V_9 ;
enum V_3 V_4 , V_31 ;
unsigned int V_24 = 0 ;
int V_26 = 0 ;
F_14 (engine, dev_priv, id) {
int (* F_17)( struct V_8 * V_9 );
if ( V_12 . V_32 )
F_17 = V_7 [ V_4 ] . V_33 ;
else
F_17 = V_7 [ V_4 ] . V_34 ;
if ( ! F_17 ) {
F_15 ( V_9 ) ;
V_2 -> V_9 [ V_4 ] = NULL ;
continue;
}
V_26 = F_17 ( V_9 ) ;
if ( V_26 ) {
V_31 = V_4 ;
goto V_29;
}
F_2 ( ! V_9 -> V_35 ) ;
V_24 |= F_12 ( V_4 ) ;
}
if ( F_8 ( V_24 != F_7 ( V_2 ) -> V_23 ) )
V_22 -> V_23 = V_24 ;
V_22 -> V_30 = F_13 ( V_24 ) ;
return 0 ;
V_29:
F_14 (engine, dev_priv, id) {
if ( V_4 >= V_31 )
F_15 ( V_9 ) ;
else
V_2 -> V_36 . V_37 ( V_9 ) ;
}
return V_26 ;
}
void F_18 ( struct V_8 * V_9 , T_1 V_38 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
if ( F_19 ( V_2 ) || F_20 ( V_2 ) ) {
F_21 ( F_22 ( V_9 -> V_17 ) , 0 ) ;
F_21 ( F_23 ( V_9 -> V_17 ) , 0 ) ;
if ( F_24 ( V_2 ) )
F_21 ( F_25 ( V_9 -> V_17 ) , 0 ) ;
}
if ( V_2 -> V_39 ) {
struct V_40 * V_40 = F_26 ( V_2 -> V_39 ) ;
void * V_41 ;
V_41 = F_27 ( V_40 ) ;
memset ( V_41 + F_28 ( V_9 -> V_4 , 0 ) ,
0 , V_28 * V_42 ) ;
F_29 ( V_41 + F_28 ( V_9 -> V_4 , 0 ) ,
V_28 * V_42 ) ;
F_30 ( V_41 ) ;
}
F_31 ( V_9 , V_43 , V_38 ) ;
F_32 ( V_44 , & V_9 -> V_45 ) ;
F_2 ( F_33 ( & V_9 -> V_46 -> V_47 ) ) ;
V_9 -> V_48 . V_38 = V_38 ;
F_34 ( V_9 ) ;
}
static void F_35 ( struct V_8 * V_9 )
{
V_9 -> V_46 = & V_9 -> V_12 -> V_36 . V_49 . V_9 [ V_9 -> V_4 ] ;
}
void F_36 ( struct V_8 * V_9 )
{
V_9 -> V_50 = V_51 ;
V_9 -> V_52 = NULL ;
F_35 ( V_9 ) ;
F_37 ( V_9 ) ;
F_38 ( V_9 , & V_9 -> V_53 ) ;
F_39 ( V_9 ) ;
}
int F_40 ( struct V_8 * V_9 , int V_54 )
{
struct V_55 * V_56 ;
struct V_57 * V_58 ;
int V_59 ;
F_8 ( V_9 -> V_60 ) ;
V_56 = F_41 ( V_9 -> V_12 , V_54 ) ;
if ( ! V_56 )
V_56 = F_42 ( V_9 -> V_12 , V_54 ) ;
if ( F_43 ( V_56 ) ) {
F_44 ( L_1 ) ;
return F_45 ( V_56 ) ;
}
V_58 = F_46 ( V_56 , & V_9 -> V_12 -> V_61 . V_62 , NULL ) ;
if ( F_43 ( V_58 ) ) {
V_59 = F_45 ( V_58 ) ;
goto V_63;
}
V_59 = F_47 ( V_58 , 0 , 4096 , V_64 | V_65 ) ;
if ( V_59 )
goto V_63;
V_9 -> V_60 = V_58 ;
F_48 ( L_2 ,
V_9 -> V_13 , F_49 ( V_58 ) ) ;
return 0 ;
V_63:
F_50 ( V_56 ) ;
return V_59 ;
}
static void F_51 ( struct V_8 * V_9 )
{
F_52 ( & V_9 -> V_60 ) ;
}
int F_53 ( struct V_8 * V_9 )
{
int V_59 ;
V_9 -> V_66 ( V_9 ) ;
V_59 = V_9 -> V_67 ( V_9 , V_9 -> V_12 -> V_68 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_54 ( V_9 ) ;
if ( V_59 )
goto V_69;
V_59 = F_55 ( V_9 ) ;
if ( V_59 )
goto V_69;
return 0 ;
V_69:
V_9 -> V_70 ( V_9 , V_9 -> V_12 -> V_68 ) ;
return V_59 ;
}
void F_56 ( struct V_8 * V_9 )
{
F_51 ( V_9 ) ;
F_57 ( V_9 ) ;
F_58 ( V_9 ) ;
F_59 ( V_9 ) ;
F_60 ( & V_9 -> V_53 ) ;
V_9 -> V_70 ( V_9 , V_9 -> V_12 -> V_68 ) ;
}
T_2 F_61 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
T_2 V_71 ;
if ( F_62 ( V_2 ) >= 8 )
V_71 = F_63 ( F_64 ( V_9 -> V_17 ) ,
F_65 ( V_9 -> V_17 ) ) ;
else if ( F_62 ( V_2 ) >= 4 )
V_71 = F_66 ( F_64 ( V_9 -> V_17 ) ) ;
else
V_71 = F_66 ( V_72 ) ;
return V_71 ;
}
T_2 F_67 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
T_2 V_73 ;
if ( F_62 ( V_2 ) >= 8 )
V_73 = F_63 ( F_68 ( V_9 -> V_17 ) ,
F_69 ( V_9 -> V_17 ) ) ;
else
V_73 = F_66 ( F_68 ( V_9 -> V_17 ) ) ;
return V_73 ;
}
const char * F_70 ( struct V_1 * V_12 , int type )
{
switch ( type ) {
case V_74 : return L_3 ;
case V_75 : return F_71 ( V_12 ) ? L_4 : L_5 ;
case V_76 : return L_6 ;
case V_77 : return L_7 ;
default: return L_8 ;
}
}
static inline T_3
F_72 ( struct V_1 * V_2 , int V_78 ,
int V_79 , T_4 V_80 )
{
T_3 V_81 ;
T_3 V_59 ;
enum V_82 V_83 ;
V_83 = F_73 ( V_2 , V_80 ,
V_84 ) ;
V_83 |= F_73 ( V_2 ,
V_85 ,
V_84 | V_86 ) ;
F_74 ( & V_2 -> V_87 . V_88 ) ;
F_75 ( V_2 , V_83 ) ;
V_81 = F_76 ( V_85 ) ;
F_77 ( V_81 & ( V_89 | V_90 ) ) ;
V_81 &= ~ ( V_89 | V_90 ) ;
V_81 |= F_78 ( V_78 ) | F_79 ( V_79 ) ;
F_80 ( V_85 , V_81 ) ;
V_59 = F_76 ( V_80 ) ;
V_81 &= ~ ( V_89 | V_90 ) ;
F_80 ( V_85 , V_81 ) ;
F_81 ( V_2 , V_83 ) ;
F_82 ( & V_2 -> V_87 . V_88 ) ;
return V_59 ;
}
void F_83 ( struct V_8 * V_9 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
T_1 V_17 = V_9 -> V_17 ;
int V_78 ;
int V_79 ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
switch ( F_62 ( V_2 ) ) {
default:
V_92 -> V_92 = F_66 ( F_84 ( V_17 ) ) ;
if ( V_9 -> V_4 != V_93 )
break;
V_92 -> V_94 = F_66 ( V_95 ) ;
F_85 (dev_priv, slice, subslice) {
V_92 -> V_96 [ V_78 ] [ V_79 ] =
F_72 ( V_2 , V_78 , V_79 ,
V_97 ) ;
V_92 -> V_98 [ V_78 ] [ V_79 ] =
F_72 ( V_2 , V_78 , V_79 ,
V_99 ) ;
}
break;
case 7 :
V_92 -> V_92 = F_66 ( F_84 ( V_17 ) ) ;
if ( V_9 -> V_4 != V_93 )
break;
V_92 -> V_94 = F_66 ( V_95 ) ;
V_92 -> V_96 [ 0 ] [ 0 ] = F_66 ( V_97 ) ;
V_92 -> V_98 [ 0 ] [ 0 ] = F_66 ( V_99 ) ;
break;
case 6 :
case 5 :
case 4 :
V_92 -> V_92 = F_66 ( F_84 ( V_17 ) ) ;
if ( V_9 -> V_4 == V_93 )
V_92 -> V_94 = F_66 ( V_100 ) ;
break;
case 3 :
case 2 :
V_92 -> V_92 = F_66 ( V_101 ) ;
break;
}
}
static int F_86 ( struct V_1 * V_2 ,
T_4 V_102 ,
const T_1 V_24 , const T_1 V_103 )
{
const T_1 V_104 = V_2 -> V_105 . V_106 ;
if ( F_8 ( V_104 >= V_107 ) )
return - V_108 ;
V_2 -> V_105 . V_80 [ V_104 ] . V_102 = V_102 ;
V_2 -> V_105 . V_80 [ V_104 ] . V_109 = V_103 ;
V_2 -> V_105 . V_80 [ V_104 ] . V_24 = V_24 ;
V_2 -> V_105 . V_106 ++ ;
return 0 ;
}
static int F_87 ( struct V_8 * V_9 ,
T_4 V_80 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
struct V_110 * V_111 = & V_2 -> V_105 ;
const T_3 V_112 = V_111 -> V_113 [ V_9 -> V_4 ] ;
if ( F_8 ( V_112 >= V_114 ) )
return - V_115 ;
F_88 ( F_89 ( V_9 -> V_17 , V_112 ) ,
F_90 ( V_80 ) ) ;
V_111 -> V_113 [ V_9 -> V_4 ] ++ ;
return 0 ;
}
static int F_91 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
F_92 ( V_116 , V_117 ) ;
F_92 ( V_118 , V_119 ) ;
F_92 ( V_120 ,
V_121 ) ;
F_92 ( V_122 ,
V_123 |
V_124 ) ;
F_93 ( V_125 , V_126 ) ;
F_92 ( V_127 , V_128 ) ;
F_94 ( V_129 ,
V_130 ,
V_131 ) ;
return 0 ;
}
static int F_95 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
int V_59 ;
V_59 = F_91 ( V_9 ) ;
if ( V_59 )
return V_59 ;
F_92 ( V_120 , V_132 ) ;
F_92 ( V_133 ,
V_134 ) ;
F_92 ( V_135 ,
V_136 ) ;
F_92 ( V_122 ,
V_137 |
( F_96 ( V_2 ) ? V_138 : 0 ) ) ;
return 0 ;
}
static int F_97 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
int V_59 ;
V_59 = F_91 ( V_9 ) ;
if ( V_59 )
return V_59 ;
F_92 ( V_120 , V_132 ) ;
F_92 ( V_139 , V_140 ) ;
return 0 ;
}
static int F_98 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
int V_59 ;
F_21 ( V_141 , F_99 ( V_142 ) ) ;
F_21 ( V_143 , F_66 ( V_143 ) |
V_144 ) ;
F_21 ( V_145 , F_66 ( V_145 ) |
V_146 ) ;
F_92 ( V_120 ,
V_147 |
V_121 ) ;
F_92 ( V_135 ,
V_148 ) ;
if ( F_100 ( V_2 , 0 , V_149 ) )
F_93 ( V_150 ,
V_151 ) ;
if ( F_100 ( V_2 , 0 , V_149 ) ) {
F_92 ( V_152 ,
V_153 ) ;
}
F_92 ( V_154 ,
V_155 ) ;
F_92 ( V_127 , ( V_128 |
V_156 ) ) ;
F_93 ( V_150 ,
V_157 ) ;
if ( F_100 ( V_2 , 0 , V_149 ) )
F_92 ( V_158 ,
V_159 ) ;
F_92 ( V_122 ,
V_137 |
V_160 ) ;
F_92 ( V_122 ,
V_124 ) ;
F_21 ( V_145 , F_66 ( V_145 ) |
V_161 ) ;
if ( F_101 ( V_2 ) ||
F_102 ( V_2 ) ||
F_100 ( V_2 , 0 , V_162 ) )
F_92 ( V_135 ,
V_136 ) ;
F_92 ( V_163 , V_164 ) ;
F_21 ( V_165 , ( F_66 ( V_165 ) |
V_166 ) ) ;
V_59 = F_87 ( V_9 , V_167 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_87 ( V_9 , V_168 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_87 ( V_9 , V_169 ) ;
if ( V_59 )
return V_59 ;
return 0 ;
}
static int F_103 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
T_5 V_170 [ 3 ] = { 0 , 0 , 0 } ;
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ ) {
T_5 V_171 ;
if ( ! F_104 ( F_7 ( V_2 ) -> V_172 . V_173 [ V_25 ] ) )
continue;
V_171 = F_105 ( F_7 ( V_2 ) -> V_172 . V_173 [ V_25 ] ) - 1 ;
V_170 [ V_25 ] = 3 - V_171 ;
}
if ( V_170 [ 0 ] == 0 && V_170 [ 1 ] == 0 && V_170 [ 2 ] == 0 )
return 0 ;
F_94 ( V_129 ,
F_106 ( 2 ) |
F_106 ( 1 ) |
F_106 ( 0 ) ,
F_107 ( 2 , V_170 [ 2 ] ) |
F_107 ( 1 , V_170 [ 1 ] ) |
F_107 ( 0 , V_170 [ 0 ] ) ) ;
return 0 ;
}
static int F_108 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
int V_59 ;
V_59 = F_98 ( V_9 ) ;
if ( V_59 )
return V_59 ;
F_21 ( V_174 ,
F_99 ( V_175 ) ) ;
F_21 ( V_176 , ( F_66 ( V_176 ) |
V_177 ) ) ;
F_109 ( V_178 , V_179 ) ;
if ( F_110 ( V_2 , V_180 , V_181 ) )
F_109 ( V_182 ,
V_183 ) ;
V_59 = F_87 ( V_9 , V_165 ) ;
if ( V_59 )
return V_59 ;
return F_103 ( V_9 ) ;
}
static int F_111 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
int V_59 ;
V_59 = F_98 ( V_9 ) ;
if ( V_59 )
return V_59 ;
if ( F_100 ( V_2 , 0 , V_149 ) )
F_21 ( V_184 , F_66 ( V_184 ) | V_185 ) ;
if ( F_100 ( V_2 , 0 , V_149 ) ) {
F_21 ( V_186 , ( F_66 ( V_186 ) &
~ V_187 ) ) ;
}
F_92 ( V_120 ,
V_132 ) ;
if ( F_100 ( V_2 , V_162 , V_181 ) ) {
F_92 ( V_188 ,
V_189 ) ;
}
if ( F_100 ( V_2 , 0 , V_162 ) ) {
F_92 (
V_190 ,
V_191 ) ;
}
if ( F_100 ( V_2 , 0 , V_149 ) ) {
V_59 = F_87 ( V_9 , V_192 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_87 ( V_9 , V_165 ) ;
if ( V_59 )
return V_59 ;
}
if ( F_100 ( V_2 , V_162 , V_181 ) )
F_21 ( V_193 , F_112 ( 62 ) |
F_113 ( 2 ) ) ;
if ( F_100 ( V_2 , V_194 , V_181 ) )
F_92 ( V_195 ,
V_196 ) ;
if ( F_100 ( V_2 , V_194 , V_181 ) )
F_109 ( V_182 ,
V_183 ) ;
return 0 ;
}
static int F_114 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
int V_59 ;
V_59 = F_98 ( V_9 ) ;
if ( V_59 )
return V_59 ;
F_21 ( V_176 , ( F_66 ( V_176 ) |
V_177 ) ) ;
if ( F_115 ( V_2 , 0 , V_197 ) )
F_109 ( V_198 ,
V_199 ) ;
if ( F_115 ( V_2 , V_200 , V_200 ) )
F_92 ( V_122 ,
V_138 ) ;
if ( F_115 ( V_2 , V_201 , V_181 ) )
F_92 ( V_195 ,
V_196 ) ;
F_109 ( V_178 , V_179 ) ;
F_92 (
V_190 ,
V_191 ) ;
F_109 ( V_182 ,
V_183 ) ;
V_59 = F_87 ( V_9 , V_165 ) ;
if ( V_59 )
return V_59 ;
return 0 ;
}
static int F_116 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
int V_59 ;
V_59 = F_98 ( V_9 ) ;
if ( V_59 )
return V_59 ;
F_92 ( V_195 ,
V_196 ) ;
return 0 ;
}
int F_117 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
int V_26 ;
F_8 ( V_9 -> V_4 != V_93 ) ;
V_2 -> V_105 . V_106 = 0 ;
V_2 -> V_105 . V_113 [ V_9 -> V_4 ] = 0 ;
if ( F_118 ( V_2 ) )
V_26 = F_95 ( V_9 ) ;
else if ( F_119 ( V_2 ) )
V_26 = F_97 ( V_9 ) ;
else if ( F_101 ( V_2 ) )
V_26 = F_108 ( V_9 ) ;
else if ( F_120 ( V_2 ) )
V_26 = F_111 ( V_9 ) ;
else if ( F_102 ( V_2 ) )
V_26 = F_114 ( V_9 ) ;
else if ( F_121 ( V_2 ) )
V_26 = F_116 ( V_9 ) ;
else
V_26 = 0 ;
if ( V_26 )
return V_26 ;
F_48 ( L_9 ,
V_9 -> V_13 , V_2 -> V_105 . V_106 ) ;
return 0 ;
}
int F_122 ( struct V_202 * V_203 )
{
struct V_110 * V_204 = & V_203 -> V_12 -> V_105 ;
T_1 * V_205 ;
int V_59 , V_25 ;
if ( V_204 -> V_106 == 0 )
return 0 ;
V_59 = V_203 -> V_9 -> V_206 ( V_203 , V_207 ) ;
if ( V_59 )
return V_59 ;
V_205 = F_123 ( V_203 , ( V_204 -> V_106 * 2 + 2 ) ) ;
if ( F_43 ( V_205 ) )
return F_45 ( V_205 ) ;
* V_205 ++ = F_124 ( V_204 -> V_106 ) ;
for ( V_25 = 0 ; V_25 < V_204 -> V_106 ; V_25 ++ ) {
* V_205 ++ = F_90 ( V_204 -> V_80 [ V_25 ] . V_102 ) ;
* V_205 ++ = V_204 -> V_80 [ V_25 ] . V_109 ;
}
* V_205 ++ = V_208 ;
F_125 ( V_203 , V_205 ) ;
V_59 = V_203 -> V_9 -> V_206 ( V_203 , V_207 ) ;
if ( V_59 )
return V_59 ;
return 0 ;
}
static bool F_126 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
bool V_209 = true ;
F_127 ( V_2 ) ;
if ( F_62 ( V_2 ) > 2 && ! ( F_128 ( V_9 ) & V_210 ) )
V_209 = false ;
F_129 ( V_2 ) ;
return V_209 ;
}
bool F_130 ( struct V_8 * V_9 )
{
if ( ! F_131 ( F_132 ( V_9 ) ,
F_133 ( V_9 ) ) )
return false ;
if ( F_134 ( V_211 , & V_9 -> V_45 ) )
return false ;
if ( V_9 -> V_212 [ 0 ] . V_213 )
return false ;
if ( ! F_126 ( V_9 ) )
return false ;
return true ;
}
bool F_135 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
enum V_3 V_4 ;
if ( F_136 ( V_2 -> V_36 . V_214 ) )
return false ;
if ( F_137 ( & V_2 -> V_215 ) )
return true ;
F_14 (engine, dev_priv, id) {
if ( ! F_130 ( V_9 ) )
return false ;
}
return true ;
}
void F_138 ( struct V_1 * V_12 )
{
struct V_8 * V_9 ;
enum V_3 V_4 ;
F_14 (engine, i915, id)
V_9 -> V_66 ( V_9 ) ;
}
