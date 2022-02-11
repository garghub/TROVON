static int F_1 ( struct V_1 * V_1 , enum V_2 type ,
T_1 * V_3 , T_1 * V_4 ,
T_1 * V_5 )
{
V_6 ;
switch( type ) {
case V_7 :
case V_8 :
* V_3 = 0 ;
* V_4 = V_9 -> V_10 . V_11 ;
* V_5 = V_9 -> V_10 . V_11 - V_9 -> V_12 ;
break;
case V_13 :
case V_14 :
* V_3 = V_9 -> V_10 . V_11 ;
* V_4 = V_9 -> V_10 . V_15 - V_9 -> V_10 . V_11 ;
* V_5 = * V_4 ;
break;
case V_16 :
case V_17 :
* V_3 = V_9 -> V_10 . V_18 ;
* V_4 = V_9 -> V_10 . V_19 ;
* V_5 = V_9 -> V_10 . V_19 - V_9 -> V_20 ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_2 ( struct V_1 * V_1 , void * V_22 ,
T_1 V_23 ,
T_1 V_24 , T_1 V_25 ,
T_2 * V_26 , T_1 * V_27 )
{
V_6 ;
int V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 = F_3 ( V_22 ) ;
int V_33 = F_4 ( V_23 , V_34 ) >> V_35 ;
struct V_36 * V_37 = F_5 ( & V_32 , V_33 ) ;
V_28 = F_6 ( V_9 , V_23 , V_34 , false ,
V_38 , 0 , V_37 , NULL , & V_30 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_30 , false ) ;
if ( F_8 ( V_28 != 0 ) )
return V_28 ;
V_28 = F_9 ( V_30 , V_38 ,
V_24 , V_25 , V_27 ) ;
F_10 ( V_30 ) ;
* V_26 = ( T_2 ) V_30 ;
return V_28 ;
}
static int F_11 ( struct V_1 * V_1 , T_2 V_26 )
{
struct V_29 * V_39 = (struct V_29 * ) V_26 ;
if ( V_39 ) {
int V_40 = F_7 ( V_39 , false ) ;
if ( F_12 ( V_40 == 0 ) ) {
F_13 ( V_39 ) ;
F_10 ( V_39 ) ;
}
F_14 ( & V_39 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_1 ,
enum V_2 type ,
T_1 V_23 , T_1 V_41 ,
T_1 V_24 , T_1 V_25 ,
T_2 * V_42 )
{
V_6 ;
T_3 V_43 = 0 ;
int V_28 = 0 ;
T_4 V_44 = 0 ;
struct V_29 * V_39 ;
struct V_45 V_46 ;
struct V_47 V_48 ;
if ( V_24 > V_25 ) {
F_16 ( 1 ) ;
return - V_21 ;
}
if ( ( ( V_41 != 1 ) && ( V_41 & ( V_41 - 1 ) ) )
|| V_23 == 0 || V_41 == 0 )
return - V_21 ;
switch( type ) {
case V_7 :
case V_8 :
V_43 = V_49 |
V_50 ;
V_44 = V_51 ;
if ( V_25 > V_9 -> V_10 . V_15 )
return - V_21 ;
V_48 . V_52 = V_24 >> V_35 ;
V_48 . V_53 = V_25 >> V_35 ;
V_48 . V_43 = V_54 | V_55 |
V_56 ;
break;
case V_13 :
case V_14 :
V_43 = V_57 |
V_50 ;
V_44 = V_51 ;
if ( V_9 -> V_10 . V_11 < V_9 -> V_10 . V_15 ) {
V_48 . V_52 =
F_17 ( V_24 , V_9 -> V_10 . V_11 ) >> V_35 ;
V_48 . V_53 =
F_18 ( V_25 , V_9 -> V_10 . V_15 ) >> V_35 ;
V_48 . V_43 = V_54 | V_55 |
V_56 ;
}
break;
case V_16 :
V_44 = V_38 ;
V_48 . V_52 = V_24 >> V_35 ;
V_48 . V_53 = V_25 >> V_35 ;
V_48 . V_43 = V_58 | V_59 ;
break;
case V_17 :
V_43 = V_60 ;
V_44 = V_38 ;
V_48 . V_52 = V_24 >> V_35 ;
V_48 . V_53 = V_25 >> V_35 ;
V_48 . V_43 = V_54 | V_59 |
V_55 ;
break;
default:
return - V_21 ;
}
* V_42 = 0 ;
V_46 . V_46 = & V_48 ;
V_46 . V_61 = 1 ;
V_46 . V_62 = & V_48 ;
V_46 . V_63 = 1 ;
V_28 = F_19 ( V_9 , V_23 , V_34 ,
true , V_44 , V_43 ,
NULL , & V_46 , NULL ,
& V_39 ) ;
if ( V_28 ) {
F_20 ( L_1 , V_28 ) ;
return V_28 ;
}
* V_42 = ( T_2 ) V_39 ;
return V_28 ;
}
static int F_21 ( struct V_1 * V_1 , T_2 V_42 )
{
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
if ( V_39 ) {
int V_40 = F_7 ( V_39 , false ) ;
if ( F_12 ( V_40 == 0 ) ) {
F_22 ( V_39 ) ;
F_13 ( V_39 ) ;
F_10 ( V_39 ) ;
}
F_14 ( & V_39 ) ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_1 , T_2 V_42 ,
T_1 * V_27 )
{
int V_40 ;
T_5 V_24 , V_25 ;
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
F_24 ( V_39 -> V_46 . V_61 > 1 ) ;
V_24 = V_39 -> V_64 [ 0 ] . V_52 << V_35 ;
V_25 = V_39 -> V_64 [ 0 ] . V_53 << V_35 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
V_40 = F_9 ( V_39 , V_39 -> V_65 ,
V_24 , V_25 , V_27 ) ;
F_10 ( V_39 ) ;
return V_40 ;
}
static int F_25 ( struct V_1 * V_1 , T_2 V_42 )
{
int V_40 ;
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
V_40 = F_13 ( V_39 ) ;
F_10 ( V_39 ) ;
return V_40 ;
}
static int F_26 ( struct V_1 * V_1 , T_2 V_42 ,
void * * V_66 )
{
int V_40 ;
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
V_40 = F_27 ( V_39 , V_66 ) ;
F_10 ( V_39 ) ;
return V_40 ;
}
static int F_28 ( struct V_1 * V_1 , T_2 V_42 )
{
int V_40 ;
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
F_22 ( V_39 ) ;
F_10 ( V_39 ) ;
return V_40 ;
}
static T_4 F_29 ( struct V_1 * V_1 , unsigned V_67 )
{
V_6 ;
return F_30 ( V_67 ) ;
}
static void F_31 ( struct V_1 * V_1 , unsigned V_67 ,
T_4 V_68 )
{
V_6 ;
F_32 ( V_67 , V_68 ) ;
}
static T_4 F_33 ( struct V_1 * V_1 ,
enum V_69 V_70 ,
unsigned V_71 )
{
V_6 ;
switch ( V_70 ) {
case V_72 :
return F_34 ( V_71 ) ;
case V_73 :
return F_35 ( V_71 ) ;
case V_74 :
return F_36 ( V_71 ) ;
case V_75 :
return F_37 ( V_71 ) ;
case V_76 :
return F_38 ( V_71 ) ;
case V_77 :
return F_39 ( V_71 ) ;
case V_78 :
F_20 ( L_2 ) ;
return 0 ;
}
F_40 ( 1 , L_3 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_1 ,
enum V_69 V_70 ,
unsigned V_71 , T_4 V_68 )
{
V_6 ;
switch ( V_70 ) {
case V_72 :
return F_42 ( V_71 , V_68 ) ;
case V_73 :
return F_43 ( V_71 , V_68 ) ;
case V_74 :
return F_44 ( V_71 , V_68 ) ;
case V_75 :
return F_45 ( V_71 , V_68 ) ;
case V_76 :
return F_46 ( V_71 , V_68 ) ;
case V_77 :
return F_47 ( V_71 , V_68 ) ;
case V_78 :
F_20 ( L_2 ) ;
return;
}
F_40 ( 1 , L_3 ) ;
}
static T_6 F_48 ( struct V_1 * V_1 , unsigned V_79 )
{
V_6 ;
T_6 V_80 ;
int V_28 = F_49 ( V_9 -> V_81 , V_79 , & V_80 ) ;
if ( F_40 ( V_28 , L_4 ) )
return 0 ;
return V_80 ;
}
static T_3 F_50 ( struct V_1 * V_1 , unsigned V_79 )
{
V_6 ;
T_3 V_80 ;
int V_28 = F_51 ( V_9 -> V_81 , V_79 , & V_80 ) ;
if ( F_40 ( V_28 , L_5 ) )
return 0 ;
return V_80 ;
}
static T_4 F_52 ( struct V_1 * V_1 ,
unsigned V_79 )
{
V_6 ;
T_4 V_80 ;
int V_28 = F_53 ( V_9 -> V_81 , V_79 , & V_80 ) ;
if ( F_40 ( V_28 , L_6 ) )
return 0 ;
return V_80 ;
}
static void F_54 ( struct V_1 * V_1 , unsigned V_79 ,
T_6 V_68 )
{
V_6 ;
int V_28 = F_55 ( V_9 -> V_81 , V_79 , V_68 ) ;
F_40 ( V_28 , L_7 ) ;
}
static void F_56 ( struct V_1 * V_1 , unsigned V_79 ,
T_3 V_68 )
{
V_6 ;
int V_28 = F_57 ( V_9 -> V_81 , V_79 , V_68 ) ;
F_40 ( V_28 , L_8 ) ;
}
static void F_58 ( struct V_1 * V_1 , unsigned V_79 ,
T_4 V_68 )
{
V_6 ;
int V_28 = F_59 ( V_9 -> V_81 , V_79 , V_68 ) ;
F_40 ( V_28 , L_9 ) ;
}
static int F_60 ( struct V_1 * V_1 ,
enum V_82 V_83 ,
T_1 V_23 ,
T_1 V_67 ,
T_1 * V_84 )
{
V_6 ;
if ( V_84 == NULL )
return - V_21 ;
switch ( V_83 ) {
case V_85 :
if ( V_9 -> V_86 == 0 )
return - V_87 ;
if ( ( V_67 + V_23 ) > V_9 -> V_86 )
return - V_21 ;
* V_84 = V_9 -> V_88 ;
return 0 ;
case V_89 :
if ( V_9 -> V_90 . V_23 == 0 )
return - V_87 ;
if ( ( V_67 + V_23 ) > V_9 -> V_90 . V_23 )
return - V_21 ;
* V_84 = V_9 -> V_90 . V_91 ;
return 0 ;
case V_92 :
case V_93 :
case V_94 :
default:
return - V_21 ;
}
}
static const void * F_61 ( struct V_1 * V_1 ,
unsigned V_95 , T_3 * V_23 ,
T_6 * V_96 , T_6 * V_97 )
{
V_6 ;
T_3 V_98 ;
if ( F_62 (
V_9 -> V_99 . V_100 , V_95 , V_23 ,
V_96 , V_97 , & V_98 ) )
return ( T_6 * ) V_9 -> V_99 . V_100 -> V_101 +
V_98 ;
return NULL ;
}
static int F_63 ( struct V_1 * V_1 , unsigned V_95 ,
T_6 * V_96 , T_6 * V_97 )
{
V_6 ;
if ( F_64 (
V_9 -> V_99 . V_100 , V_95 ,
V_96 , V_97 ) )
return 0 ;
return - V_21 ;
}
static int F_65 ( struct V_1 * V_1 , unsigned V_95 ,
void * args )
{
V_6 ;
return F_66 (
V_9 -> V_99 . V_100 , V_95 , args ) ;
}
static int F_67 ( struct V_1 * V_1 , T_2 * V_102 )
{
return 0 ;
}
static int F_68 ( struct V_1 * V_1 , T_2 V_102 )
{
return 0 ;
}
static int F_69 ( struct V_1 * V_1 , T_2 V_102 ,
int V_103 )
{
return 0 ;
}
static int F_70 ( struct V_1 * V_1 , T_2 V_102 ,
enum V_104 clock , unsigned V_105 )
{
return 0 ;
}
static int F_71 ( struct V_1 * V_1 , T_2 V_102 ,
enum V_106 V_107 , int V_108 )
{
return 0 ;
}
static int F_72 ( struct V_1 * V_1 ,
enum V_104 clock ,
struct V_109 * V_110 )
{
return 0 ;
}
static int F_73 ( struct V_1 * V_1 , T_4 V_111 ,
const T_4 * V_112 )
{
F_20 ( L_10 ) ;
return - V_113 ;
}
static int F_74 ( struct V_114 * V_9 ,
struct V_115 * V_116 ,
unsigned type ,
enum V_117 V_118 )
{
struct V_119 * V_120 =
(struct V_119 * ) V_116 -> V_121 ;
if ( ! V_120 )
return - V_21 ;
if ( ! V_120 -> V_122 )
return - V_21 ;
return V_120 -> V_122 ( V_120 -> V_123 ,
V_120 -> V_124 ,
type ,
( int ) V_118 ) ;
}
static int F_75 ( struct V_114 * V_9 ,
struct V_115 * V_125 ,
struct V_126 * V_127 )
{
struct V_119 * V_120 =
(struct V_119 * ) V_125 -> V_121 ;
if ( ! V_120 )
return - V_21 ;
if ( ! V_120 -> V_128 )
return - V_21 ;
return V_120 -> V_128 ( V_120 -> V_123 ,
V_120 -> V_124 ,
V_127 -> V_129 ) ;
}
static int F_76 ( struct V_1 * V_1 , unsigned V_124 ,
unsigned V_130 ,
T_7 V_122 ,
T_8 V_128 ,
void * V_123 )
{
V_6 ;
int V_28 = 0 ;
struct V_119 * V_120 ;
struct V_115 * V_125 =
F_77 ( sizeof( struct V_115 ) , V_131 ) ;
if ( ! V_125 )
return - V_132 ;
V_120 =
F_77 ( sizeof( struct V_119 ) , V_131 ) ;
if ( ! V_120 ) {
F_78 ( V_125 ) ;
return - V_132 ;
}
V_125 -> V_130 = V_130 ;
V_125 -> V_133 = & V_134 ;
V_120 -> V_124 = V_124 ;
V_120 -> V_122 = V_122 ;
V_120 -> V_128 = V_128 ;
V_120 -> V_123 = V_123 ;
V_125 -> V_121 = ( void * ) V_120 ;
V_28 = F_79 ( V_9 , V_124 , V_125 ) ;
if ( V_28 ) {
F_78 ( V_120 ) ;
F_78 ( V_125 ) ;
}
return V_28 ;
}
static int F_80 ( struct V_1 * V_1 , unsigned V_124 , unsigned type )
{
V_6 ;
return F_81 ( V_9 , V_9 -> V_135 . V_136 [ V_124 ] , type ) ;
}
static int F_82 ( struct V_1 * V_1 , unsigned V_124 , unsigned type )
{
V_6 ;
return F_83 ( V_9 , V_9 -> V_135 . V_136 [ V_124 ] , type ) ;
}
static int F_84 ( struct V_1 * V_1 ,
enum V_137 V_138 ,
enum V_139 V_118 )
{
V_6 ;
int V_140 , V_40 = - 1 ;
for ( V_140 = 0 ; V_140 < V_9 -> V_141 ; V_140 ++ ) {
if ( ! V_9 -> V_142 [ V_140 ] . V_143 . V_144 )
continue;
if ( V_9 -> V_142 [ V_140 ] . V_145 -> type == V_138 ) {
V_40 = V_9 -> V_142 [ V_140 ] . V_145 -> V_133 -> V_146 (
( void * ) V_9 ,
V_118 ) ;
break;
}
}
return V_40 ;
}
static int F_85 ( struct V_1 * V_1 ,
enum V_137 V_138 ,
enum V_147 V_118 )
{
V_6 ;
int V_140 , V_40 = - 1 ;
for ( V_140 = 0 ; V_140 < V_9 -> V_141 ; V_140 ++ ) {
if ( ! V_9 -> V_142 [ V_140 ] . V_143 . V_144 )
continue;
if ( V_9 -> V_142 [ V_140 ] . V_145 -> type == V_138 ) {
V_40 = V_9 -> V_142 [ V_140 ] . V_145 -> V_133 -> V_148 (
( void * ) V_9 ,
V_118 ) ;
break;
}
}
return V_40 ;
}
static T_4 F_86 ( struct V_1 * V_1 , T_4 V_149 )
{
V_6 ;
enum V_150 V_151 = V_152 ;
switch ( V_149 ) {
case V_153 :
V_151 = V_154 ;
break;
case V_155 :
V_151 = V_156 ;
break;
case V_157 :
V_151 = V_158 ;
break;
case V_159 :
V_151 = V_160 ;
break;
case V_161 :
V_151 = V_162 ;
break;
case V_163 :
case V_164 :
V_151 = V_165 ;
break;
case V_166 :
if ( V_9 -> V_167 >= V_168 )
V_151 = V_165 ;
else
V_151 = V_169 ;
break;
case V_170 :
V_151 = V_171 ;
break;
case V_172 :
V_151 = V_173 ;
break;
default:
F_20 ( L_11 ) ;
}
return V_151 ;
}
static int F_87 ( struct V_1 * V_1 , enum V_174 type )
{
V_6 ;
if ( ( V_175 == type ) || ( V_176 == type ) ) {
F_88 ( V_9 -> V_177 . V_178 ) ;
V_9 -> V_177 . V_178 = NULL ;
return 0 ;
}
return - V_21 ;
}
static T_3 F_89 ( struct V_1 * V_1 ,
enum V_174 type )
{
V_6 ;
T_3 V_179 = 0 ;
switch ( type ) {
case V_153 :
V_179 = V_9 -> V_180 . V_181 [ 0 ] . V_179 ;
break;
case V_155 :
V_179 = V_9 -> V_180 . V_181 [ 1 ] . V_179 ;
break;
case V_157 :
V_179 = V_9 -> V_182 . V_183 ;
break;
case V_159 :
V_179 = V_9 -> V_182 . V_184 ;
break;
case V_161 :
V_179 = V_9 -> V_182 . V_185 ;
break;
case V_163 :
V_179 = V_9 -> V_182 . V_186 ;
break;
case V_164 :
V_179 = V_9 -> V_182 . V_186 ;
break;
case V_166 :
V_179 = V_9 -> V_182 . V_186 ;
break;
case V_170 :
V_179 = V_9 -> V_182 . V_187 ;
break;
case V_172 :
break;
default:
F_20 ( L_12 , type ) ;
break;
}
return V_179 ;
}
static int F_90 ( struct V_1 * V_1 ,
bool V_188 )
{
V_6 ;
if ( V_9 -> V_182 . V_189 . V_133 -> V_190 == NULL ||
V_9 -> V_182 . V_189 . V_133 -> V_191 == NULL )
return 0 ;
if ( V_188 )
V_9 -> V_182 . V_189 . V_133 -> V_190 ( V_9 ) ;
else
V_9 -> V_182 . V_189 . V_133 -> V_191 ( V_9 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_1 ,
enum V_174 type ,
struct V_192 * V_193 )
{
V_6 ;
if ( ( V_175 != type ) && ( V_176 != type ) ) {
T_1 V_194 ;
T_4 V_195 ;
const struct V_196 * V_197 ;
enum V_150 V_198 ;
struct V_199 * V_200 ;
V_198 = F_86 ( V_1 , type ) ;
V_200 = & V_9 -> V_201 . V_200 [ V_198 ] ;
if ( V_200 -> V_178 == NULL )
return - V_21 ;
V_194 = V_200 -> V_202 ;
V_197 = ( const struct V_196 * ) V_200 -> V_178 -> V_121 ;
V_195 = F_92 ( V_197 -> V_197 . V_203 ) ;
if ( ( type == V_164 ) ||
( type == V_166 ) ) {
V_194 += F_4 ( F_92 ( V_197 -> V_197 . V_203 ) , V_34 ) ;
V_195 = F_92 ( V_197 -> V_204 ) << 2 ;
}
V_193 -> V_205 = V_200 -> V_206 ;
V_193 -> V_207 = V_195 ;
V_193 -> V_202 = V_194 ;
V_193 -> V_145 = ( T_3 ) F_92 ( V_197 -> V_197 . V_208 ) ;
if ( V_163 == type )
V_193 -> V_207 = ( V_197 -> V_209 ) << 2 ;
V_193 -> V_179 = F_89 ( V_1 , type ) ;
V_193 -> V_210 = ( T_3 ) F_92 ( V_197 -> V_211 ) ;
} else {
char V_212 [ 30 ] = { 0 } ;
int V_213 = 0 ;
T_4 V_214 ;
T_4 V_215 ;
const T_6 * V_116 ;
const struct V_216 * V_217 ;
if ( V_176 == type )
F_87 ( V_1 , V_175 ) ;
if ( ! V_9 -> V_177 . V_178 ) {
switch ( V_9 -> V_167 ) {
case V_168 :
if ( ( ( V_9 -> V_81 -> V_218 == 0x6900 ) && ( V_9 -> V_81 -> V_219 == 0x81 ) ) ||
( ( V_9 -> V_81 -> V_218 == 0x6900 ) && ( V_9 -> V_81 -> V_219 == 0x83 ) ) ||
( ( V_9 -> V_81 -> V_218 == 0x6907 ) && ( V_9 -> V_81 -> V_219 == 0x87 ) ) ) {
V_193 -> V_220 = true ;
strcpy ( V_212 , L_13 ) ;
} else
strcpy ( V_212 , L_14 ) ;
break;
case V_221 :
if ( ( ( V_9 -> V_81 -> V_218 == 0x6939 ) && ( V_9 -> V_81 -> V_219 == 0xf1 ) ) ||
( ( V_9 -> V_81 -> V_218 == 0x6938 ) && ( V_9 -> V_81 -> V_219 == 0xf1 ) ) ) {
V_193 -> V_220 = true ;
strcpy ( V_212 , L_15 ) ;
} else
strcpy ( V_212 , L_16 ) ;
break;
case V_222 :
strcpy ( V_212 , L_17 ) ;
break;
case V_223 :
if ( type == V_175 ) {
if ( ( ( V_9 -> V_81 -> V_218 == 0x67ef ) &&
( ( V_9 -> V_81 -> V_219 == 0xe0 ) ||
( V_9 -> V_81 -> V_219 == 0xe2 ) ||
( V_9 -> V_81 -> V_219 == 0xe5 ) ) ) ||
( ( V_9 -> V_81 -> V_218 == 0x67ff ) &&
( ( V_9 -> V_81 -> V_219 == 0xcf ) ||
( V_9 -> V_81 -> V_219 == 0xef ) ||
( V_9 -> V_81 -> V_219 == 0xff ) ) ) ) {
V_193 -> V_220 = true ;
strcpy ( V_212 , L_18 ) ;
} else
strcpy ( V_212 , L_19 ) ;
} else if ( type == V_176 ) {
strcpy ( V_212 , L_20 ) ;
}
break;
case V_224 :
if ( type == V_175 ) {
if ( ( V_9 -> V_81 -> V_218 == 0x67df ) &&
( ( V_9 -> V_81 -> V_219 == 0xe0 ) ||
( V_9 -> V_81 -> V_219 == 0xe3 ) ||
( V_9 -> V_81 -> V_219 == 0xe4 ) ||
( V_9 -> V_81 -> V_219 == 0xe5 ) ||
( V_9 -> V_81 -> V_219 == 0xe7 ) ||
( V_9 -> V_81 -> V_219 == 0xef ) ) ) {
V_193 -> V_220 = true ;
strcpy ( V_212 , L_21 ) ;
} else
strcpy ( V_212 , L_22 ) ;
} else if ( type == V_176 ) {
strcpy ( V_212 , L_23 ) ;
}
break;
case V_225 :
strcpy ( V_212 , L_24 ) ;
break;
default:
F_20 ( L_25 ) ;
return - V_21 ;
}
V_213 = F_93 ( & V_9 -> V_177 . V_178 , V_212 , V_9 -> V_226 ) ;
if ( V_213 ) {
F_20 ( L_26 ) ;
return V_213 ;
}
V_213 = F_94 ( V_9 -> V_177 . V_178 ) ;
if ( V_213 ) {
F_20 ( L_27 , V_212 ) ;
F_88 ( V_9 -> V_177 . V_178 ) ;
V_9 -> V_177 . V_178 = NULL ;
return V_213 ;
}
}
V_217 = ( const struct V_216 * ) V_9 -> V_177 . V_178 -> V_121 ;
F_95 ( & V_217 -> V_197 ) ;
V_9 -> V_177 . V_179 = F_92 ( V_217 -> V_197 . V_208 ) ;
V_214 = F_92 ( V_217 -> V_197 . V_203 ) ;
V_215 = F_92 ( V_217 -> V_227 ) ;
V_116 = ( const T_6 * ) ( V_9 -> V_177 . V_178 -> V_121 +
F_92 ( V_217 -> V_197 . V_228 ) ) ;
V_193 -> V_145 = V_9 -> V_177 . V_179 ;
V_193 -> V_207 = V_214 ;
V_193 -> V_215 = V_215 ;
V_193 -> V_205 = ( void * ) V_116 ;
}
return 0 ;
}
static int F_96 ( void * V_1 )
{
V_6 ;
return F_97 ( V_9 ) ;
}
static int F_98 ( struct V_1 * V_1 ,
struct V_229 * V_230 )
{
V_6 ;
if ( NULL == V_230 )
return - V_231 ;
if ( sizeof( struct V_229 ) != V_230 -> V_23 )
return - V_231 ;
switch ( V_230 -> V_232 ) {
case V_233 :
V_230 -> V_68 = V_9 -> V_81 -> V_234 | ( V_9 -> V_81 -> V_235 -> V_236 << 8 ) ;
break;
case V_237 :
V_230 -> V_68 = V_9 -> V_177 . V_238 ;
break;
case V_239 :
V_230 -> V_68 = V_9 -> V_177 . V_240 ;
break;
case V_241 :
V_230 -> V_68 = V_9 -> V_81 -> V_218 ;
break;
case V_242 :
V_230 -> V_68 = V_9 -> V_81 -> V_219 ;
break;
case V_243 :
V_230 -> V_68 = V_9 -> V_244 ;
break;
case V_245 :
V_230 -> V_68 = V_9 -> V_246 ;
break;
case V_247 :
V_230 -> V_68 = V_9 -> V_182 . V_248 . V_236 ;
break;
case V_249 :
V_230 -> V_68 = V_9 -> V_182 . V_250 . V_251 ;
break;
case V_252 :
V_230 -> V_68 = V_9 -> V_81 -> V_253 ;
break;
case V_254 :
V_230 -> V_68 = V_9 -> V_81 -> V_255 ;
break;
default:
return - V_231 ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_1 ,
struct V_256 * V_193 )
{
V_6 ;
struct V_257 * V_257 ;
struct V_258 * V_259 = V_9 -> V_259 ;
struct V_260 * V_261 ;
T_4 V_262 , V_263 ;
struct V_264 * V_99 ;
if ( V_193 == NULL )
return - V_21 ;
V_99 = V_193 -> V_99 ;
if ( V_9 -> V_99 . V_265 && V_9 -> V_99 . V_266 ) {
F_100 (crtc,
&ddev->mode_config.crtc_list, head) {
V_257 = F_101 ( V_261 ) ;
if ( V_261 -> V_267 ) {
V_193 -> V_268 |= ( 1 << V_257 -> V_269 ) ;
V_193 -> V_270 ++ ;
}
if ( V_99 != NULL &&
V_261 -> V_267 && V_257 -> V_267 &&
V_257 -> V_271 . clock ) {
V_262 = ( V_257 -> V_271 . V_272 * 1000 ) /
V_257 -> V_271 . clock ;
V_263 = V_257 -> V_271 . V_273 -
V_257 -> V_271 . V_274 +
( V_257 -> V_275 * 2 ) ;
V_99 -> V_276 = V_263 * V_262 ;
V_99 -> V_277 = F_102 ( & V_257 -> V_271 ) ;
V_99 -> V_278 = V_9 -> clock . V_279 . V_280 ;
V_99 = NULL ;
}
}
}
return 0 ;
}
static int F_103 ( struct V_1 * V_1 , bool V_267 )
{
V_6 ;
V_9 -> V_177 . V_281 = V_267 ;
return 0 ;
}
static int F_104 ( struct V_1 * V_1 ,
struct V_282 * V_193 )
{
V_6 ;
T_9 V_42 ;
struct V_283 V_284 ;
struct V_285 V_286 = { V_287 , NULL } ;
union V_288 * V_289 , * V_39 ;
T_6 V_290 [ 5 ] = { '\0' } ;
struct V_291 * V_292 ;
T_4 V_140 , V_293 ;
T_10 V_143 ;
int V_151 ;
V_42 = F_105 ( & V_9 -> V_81 -> V_226 ) ;
if ( ! V_42 )
return - V_231 ;
memset ( & V_284 , 0 , sizeof( struct V_283 ) ) ;
if ( V_193 -> V_23 != sizeof( struct V_282 ) )
return - V_21 ;
V_284 . V_293 = V_193 -> V_294 ;
if ( V_193 -> V_294 > 0 ) {
if ( V_193 -> V_295 == NULL )
return - V_21 ;
V_292 = V_193 -> V_295 ;
for ( V_140 = 0 ; V_140 < V_193 -> V_294 ; V_140 ++ ) {
if ( ( ( V_292 -> type == V_296 ) ||
( V_292 -> type == V_297 ) ) &&
( V_292 -> V_298 == NULL ) )
return - V_21 ;
V_292 ++ ;
}
}
if ( V_193 -> V_299 > 0 ) {
if ( V_193 -> V_300 == NULL )
return - V_21 ;
V_292 = V_193 -> V_300 ;
for ( V_140 = 0 ; V_140 < V_193 -> V_299 ; V_140 ++ ) {
if ( ( ( V_292 -> type == V_296 ) ||
( V_292 -> type == V_297 ) )
&& ( V_292 -> V_298 == NULL ) )
return - V_21 ;
V_292 ++ ;
}
}
if ( ( V_193 -> V_301 & V_302 ) != 0 ) {
strncpy ( V_290 , ( char * ) & ( V_193 -> V_290 ) , sizeof( T_4 ) ) ;
V_290 [ 4 ] = '\0' ;
}
if ( V_284 . V_293 > 0 ) {
V_284 . V_298 = V_289 =
F_77 ( sizeof( union V_288 ) * V_284 . V_293 , V_131 ) ;
if ( V_289 == NULL )
return - V_21 ;
V_292 = V_193 -> V_295 ;
for ( V_140 = 0 ; V_140 < V_284 . V_293 ; V_140 ++ ) {
V_289 -> type = V_292 -> type ;
switch ( V_289 -> type ) {
case V_303 :
V_289 -> integer . V_68 = V_292 -> V_68 ;
break;
case V_296 :
V_289 -> string . V_304 = V_292 -> V_305 ;
V_289 -> string . V_298 = V_292 -> V_298 ;
break;
case V_297 :
V_289 -> V_306 . V_304 = V_292 -> V_305 ;
V_289 -> V_306 . V_298 = V_292 -> V_298 ;
break;
default:
break;
}
V_289 ++ ;
V_292 ++ ;
}
}
V_293 = V_193 -> V_299 ;
V_292 = V_193 -> V_300 ;
V_143 = F_106 ( V_42 , V_290 , & V_284 , & V_286 ) ;
if ( F_107 ( V_143 ) ) {
V_151 = - V_307 ;
goto V_308;
}
V_39 = V_286 . V_298 ;
if ( V_293 > 1 ) {
if ( ( V_39 -> type != V_309 ) ||
( V_39 -> V_310 . V_293 != V_293 ) ) {
V_151 = - V_307 ;
goto V_311;
}
V_289 = V_39 -> V_310 . V_312 ;
} else
V_289 = V_39 ;
if ( V_289 == NULL ) {
V_151 = - V_307 ;
goto V_311;
}
for ( V_140 = 0 ; V_140 < V_293 ; V_140 ++ ) {
if ( V_292 -> type != V_289 -> type ) {
V_151 = - V_307 ;
goto V_311;
}
switch ( V_289 -> type ) {
case V_303 :
V_292 -> V_68 = V_289 -> integer . V_68 ;
break;
case V_296 :
if ( ( V_289 -> string . V_304 != V_292 -> V_305 ) ||
( V_289 -> string . V_298 == NULL ) ) {
V_151 = - V_307 ;
goto V_311;
}
strncpy ( V_292 -> V_298 ,
V_289 -> string . V_298 ,
V_289 -> string . V_304 ) ;
break;
case V_297 :
if ( V_289 -> V_306 . V_298 == NULL ) {
V_151 = - V_307 ;
goto V_311;
}
memcpy ( V_292 -> V_298 ,
V_289 -> V_306 . V_298 ,
V_292 -> V_305 ) ;
break;
default:
break;
}
V_292 ++ ;
V_289 ++ ;
}
V_151 = 0 ;
V_311:
F_78 ( V_39 ) ;
V_308:
F_78 ( ( void * ) V_284 . V_298 ) ;
return V_151 ;
}
static int F_104 ( struct V_1 * V_1 ,
struct V_282 * V_193 )
{
return - V_307 ;
}
static int F_108 ( struct V_1 * V_1 ,
T_4 V_313 ,
T_4 V_314 ,
void * V_315 , void * V_316 ,
T_4 V_299 ,
T_4 V_317 ,
T_4 V_318 )
{
struct V_291 V_319 [ 2 ] = { { 0 } , { 0 } } ;
struct V_291 V_320 = { 0 } ;
struct V_282 V_193 = { 0 } ;
V_319 [ 0 ] . type = V_321 ;
V_319 [ 0 ] . V_305 = sizeof( T_4 ) ;
V_319 [ 0 ] . V_68 = V_314 ;
V_319 [ 1 ] . type = V_322 ;
V_319 [ 1 ] . V_305 = V_317 ;
V_319 [ 1 ] . V_298 = V_315 ;
V_320 . type = V_322 ;
V_320 . V_305 = V_318 ;
V_320 . V_298 = V_316 ;
V_193 . V_23 = sizeof( struct V_282 ) ;
V_193 . V_301 = V_302 | V_323 ;
V_193 . V_294 = 2 ;
V_193 . V_290 = V_313 ;
V_193 . V_295 = V_319 ;
V_193 . V_299 = V_299 ;
V_193 . V_300 = & V_320 ;
return F_104 ( V_1 , & V_193 ) ;
}
struct V_1 * F_109 ( struct V_114 * V_9 )
{
struct V_324 * V_1 =
F_110 ( sizeof( * V_1 ) , V_131 ) ;
if ( ! V_1 ) {
F_20 ( L_28 ) ;
return NULL ;
}
V_1 -> V_91 . V_325 = & V_326 ;
V_1 -> V_91 . V_327 = & V_328 ;
V_1 -> V_9 = V_9 ;
return (struct V_1 * ) V_1 ;
}
void F_111 ( struct V_1 * V_1 )
{
F_78 ( V_1 ) ;
}
