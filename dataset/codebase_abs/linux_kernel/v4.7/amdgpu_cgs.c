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
V_43 = V_49 ;
V_44 = V_50 ;
if ( V_25 > V_9 -> V_10 . V_15 )
return - V_21 ;
V_48 . V_51 = V_24 >> V_35 ;
V_48 . V_52 = V_25 >> V_35 ;
V_48 . V_43 = V_53 | V_54 |
V_55 ;
break;
case V_13 :
case V_14 :
V_43 = V_56 ;
V_44 = V_50 ;
if ( V_9 -> V_10 . V_11 < V_9 -> V_10 . V_15 ) {
V_48 . V_51 =
F_17 ( V_24 , V_9 -> V_10 . V_11 ) >> V_35 ;
V_48 . V_52 =
F_18 ( V_25 , V_9 -> V_10 . V_15 ) >> V_35 ;
V_48 . V_43 = V_53 | V_54 |
V_55 ;
}
break;
case V_16 :
V_44 = V_38 ;
V_48 . V_51 = V_24 >> V_35 ;
V_48 . V_52 = V_25 >> V_35 ;
V_48 . V_43 = V_57 | V_58 ;
break;
case V_17 :
V_43 = V_59 ;
V_44 = V_38 ;
V_48 . V_51 = V_24 >> V_35 ;
V_48 . V_52 = V_25 >> V_35 ;
V_48 . V_43 = V_53 | V_58 |
V_54 ;
break;
default:
return - V_21 ;
}
* V_42 = 0 ;
V_46 . V_46 = & V_48 ;
V_46 . V_60 = 1 ;
V_46 . V_61 = & V_48 ;
V_46 . V_62 = 1 ;
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
F_24 ( V_39 -> V_46 . V_60 > 1 ) ;
V_24 = V_39 -> V_63 [ 0 ] . V_51 << V_35 ;
V_25 = V_39 -> V_63 [ 0 ] . V_52 << V_35 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
V_40 = F_9 ( V_39 , V_38 ,
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
void * * V_64 )
{
int V_40 ;
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
V_40 = F_27 ( V_39 , V_64 ) ;
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
static T_4 F_29 ( struct V_1 * V_1 , unsigned V_65 )
{
V_6 ;
return F_30 ( V_65 ) ;
}
static void F_31 ( struct V_1 * V_1 , unsigned V_65 ,
T_4 V_66 )
{
V_6 ;
F_32 ( V_65 , V_66 ) ;
}
static T_4 F_33 ( struct V_1 * V_1 ,
enum V_67 V_68 ,
unsigned V_69 )
{
V_6 ;
switch ( V_68 ) {
case V_70 :
return F_34 ( V_69 ) ;
case V_71 :
return F_35 ( V_69 ) ;
case V_72 :
return F_36 ( V_69 ) ;
case V_73 :
return F_37 ( V_69 ) ;
case V_74 :
return F_38 ( V_69 ) ;
case V_75 :
F_20 ( L_2 ) ;
return 0 ;
}
F_39 ( 1 , L_3 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_1 ,
enum V_67 V_68 ,
unsigned V_69 , T_4 V_66 )
{
V_6 ;
switch ( V_68 ) {
case V_70 :
return F_41 ( V_69 , V_66 ) ;
case V_71 :
return F_42 ( V_69 , V_66 ) ;
case V_72 :
return F_43 ( V_69 , V_66 ) ;
case V_73 :
return F_44 ( V_69 , V_66 ) ;
case V_74 :
return F_45 ( V_69 , V_66 ) ;
case V_75 :
F_20 ( L_2 ) ;
return;
}
F_39 ( 1 , L_3 ) ;
}
static T_6 F_46 ( struct V_1 * V_1 , unsigned V_76 )
{
V_6 ;
T_6 V_77 ;
int V_28 = F_47 ( V_9 -> V_78 , V_76 , & V_77 ) ;
if ( F_39 ( V_28 , L_4 ) )
return 0 ;
return V_77 ;
}
static T_3 F_48 ( struct V_1 * V_1 , unsigned V_76 )
{
V_6 ;
T_3 V_77 ;
int V_28 = F_49 ( V_9 -> V_78 , V_76 , & V_77 ) ;
if ( F_39 ( V_28 , L_5 ) )
return 0 ;
return V_77 ;
}
static T_4 F_50 ( struct V_1 * V_1 ,
unsigned V_76 )
{
V_6 ;
T_4 V_77 ;
int V_28 = F_51 ( V_9 -> V_78 , V_76 , & V_77 ) ;
if ( F_39 ( V_28 , L_6 ) )
return 0 ;
return V_77 ;
}
static void F_52 ( struct V_1 * V_1 , unsigned V_76 ,
T_6 V_66 )
{
V_6 ;
int V_28 = F_53 ( V_9 -> V_78 , V_76 , V_66 ) ;
F_39 ( V_28 , L_7 ) ;
}
static void F_54 ( struct V_1 * V_1 , unsigned V_76 ,
T_3 V_66 )
{
V_6 ;
int V_28 = F_55 ( V_9 -> V_78 , V_76 , V_66 ) ;
F_39 ( V_28 , L_8 ) ;
}
static void F_56 ( struct V_1 * V_1 , unsigned V_76 ,
T_4 V_66 )
{
V_6 ;
int V_28 = F_57 ( V_9 -> V_78 , V_76 , V_66 ) ;
F_39 ( V_28 , L_9 ) ;
}
static int F_58 ( struct V_1 * V_1 ,
enum V_79 V_80 ,
T_1 V_23 ,
T_1 V_65 ,
T_1 * V_81 )
{
V_6 ;
if ( V_81 == NULL )
return - V_21 ;
switch ( V_80 ) {
case V_82 :
if ( V_9 -> V_83 == 0 )
return - V_84 ;
if ( ( V_65 + V_23 ) > V_9 -> V_83 )
return - V_21 ;
* V_81 = V_9 -> V_85 ;
return 0 ;
case V_86 :
if ( V_9 -> V_87 . V_23 == 0 )
return - V_84 ;
if ( ( V_65 + V_23 ) > V_9 -> V_87 . V_23 )
return - V_21 ;
* V_81 = V_9 -> V_87 . V_88 ;
return 0 ;
case V_89 :
case V_90 :
case V_91 :
default:
return - V_21 ;
}
}
static const void * F_59 ( struct V_1 * V_1 ,
unsigned V_92 , T_3 * V_23 ,
T_6 * V_93 , T_6 * V_94 )
{
V_6 ;
T_3 V_95 ;
if ( F_60 (
V_9 -> V_96 . V_97 , V_92 , V_23 ,
V_93 , V_94 , & V_95 ) )
return ( T_6 * ) V_9 -> V_96 . V_97 -> V_98 +
V_95 ;
return NULL ;
}
static int F_61 ( struct V_1 * V_1 , unsigned V_92 ,
T_6 * V_93 , T_6 * V_94 )
{
V_6 ;
if ( F_62 (
V_9 -> V_96 . V_97 , V_92 ,
V_93 , V_94 ) )
return 0 ;
return - V_21 ;
}
static int F_63 ( struct V_1 * V_1 , unsigned V_92 ,
void * args )
{
V_6 ;
return F_64 (
V_9 -> V_96 . V_97 , V_92 , args ) ;
}
static int F_65 ( struct V_1 * V_1 , T_2 * V_99 )
{
return 0 ;
}
static int F_66 ( struct V_1 * V_1 , T_2 V_99 )
{
return 0 ;
}
static int F_67 ( struct V_1 * V_1 , T_2 V_99 ,
int V_100 )
{
return 0 ;
}
static int F_68 ( struct V_1 * V_1 , T_2 V_99 ,
enum V_101 clock , unsigned V_102 )
{
return 0 ;
}
static int F_69 ( struct V_1 * V_1 , T_2 V_99 ,
enum V_103 V_104 , int V_105 )
{
return 0 ;
}
static int F_70 ( struct V_1 * V_1 ,
enum V_101 clock ,
struct V_106 * V_107 )
{
return 0 ;
}
static int F_71 ( struct V_1 * V_1 , T_4 V_108 ,
const T_4 * V_109 )
{
F_20 ( L_10 ) ;
return - V_110 ;
}
static int F_72 ( struct V_111 * V_9 ,
struct V_112 * V_113 ,
unsigned type ,
enum V_114 V_115 )
{
struct V_116 * V_117 =
(struct V_116 * ) V_113 -> V_118 ;
if ( ! V_117 )
return - V_21 ;
if ( ! V_117 -> V_119 )
return - V_21 ;
return V_117 -> V_119 ( V_117 -> V_120 ,
V_117 -> V_121 ,
type ,
( int ) V_115 ) ;
}
static int F_73 ( struct V_111 * V_9 ,
struct V_112 * V_122 ,
struct V_123 * V_124 )
{
struct V_116 * V_117 =
(struct V_116 * ) V_122 -> V_118 ;
if ( ! V_117 )
return - V_21 ;
if ( ! V_117 -> V_125 )
return - V_21 ;
return V_117 -> V_125 ( V_117 -> V_120 ,
V_117 -> V_121 ,
V_124 -> V_126 ) ;
}
static int F_74 ( struct V_1 * V_1 , unsigned V_121 ,
unsigned V_127 ,
T_7 V_119 ,
T_8 V_125 ,
void * V_120 )
{
V_6 ;
int V_28 = 0 ;
struct V_116 * V_117 ;
struct V_112 * V_122 =
F_75 ( sizeof( struct V_112 ) , V_128 ) ;
if ( ! V_122 )
return - V_129 ;
V_117 =
F_75 ( sizeof( struct V_116 ) , V_128 ) ;
if ( ! V_117 ) {
F_76 ( V_122 ) ;
return - V_129 ;
}
V_122 -> V_127 = V_127 ;
V_122 -> V_130 = & V_131 ;
V_117 -> V_121 = V_121 ;
V_117 -> V_119 = V_119 ;
V_117 -> V_125 = V_125 ;
V_117 -> V_120 = V_120 ;
V_122 -> V_118 = ( void * ) V_117 ;
V_28 = F_77 ( V_9 , V_121 , V_122 ) ;
if ( V_28 ) {
F_76 ( V_117 ) ;
F_76 ( V_122 ) ;
}
return V_28 ;
}
static int F_78 ( struct V_1 * V_1 , unsigned V_121 , unsigned type )
{
V_6 ;
return F_79 ( V_9 , V_9 -> V_132 . V_133 [ V_121 ] , type ) ;
}
static int F_80 ( struct V_1 * V_1 , unsigned V_121 , unsigned type )
{
V_6 ;
return F_81 ( V_9 , V_9 -> V_132 . V_133 [ V_121 ] , type ) ;
}
int F_82 ( struct V_1 * V_1 ,
enum V_134 V_135 ,
enum V_136 V_115 )
{
V_6 ;
int V_137 , V_40 = - 1 ;
for ( V_137 = 0 ; V_137 < V_9 -> V_138 ; V_137 ++ ) {
if ( ! V_9 -> V_139 [ V_137 ] . V_140 )
continue;
if ( V_9 -> V_141 [ V_137 ] . type == V_135 ) {
V_40 = V_9 -> V_141 [ V_137 ] . V_130 -> V_142 (
( void * ) V_9 ,
V_115 ) ;
break;
}
}
return V_40 ;
}
int F_83 ( struct V_1 * V_1 ,
enum V_134 V_135 ,
enum V_143 V_115 )
{
V_6 ;
int V_137 , V_40 = - 1 ;
for ( V_137 = 0 ; V_137 < V_9 -> V_138 ; V_137 ++ ) {
if ( ! V_9 -> V_139 [ V_137 ] . V_140 )
continue;
if ( V_9 -> V_141 [ V_137 ] . type == V_135 ) {
V_40 = V_9 -> V_141 [ V_137 ] . V_130 -> V_144 (
( void * ) V_9 ,
V_115 ) ;
break;
}
}
return V_40 ;
}
static T_4 F_84 ( struct V_1 * V_1 , T_4 V_145 )
{
V_6 ;
enum V_146 V_147 = V_148 ;
switch ( V_145 ) {
case V_149 :
V_147 = V_150 ;
break;
case V_151 :
V_147 = V_152 ;
break;
case V_153 :
V_147 = V_154 ;
break;
case V_155 :
V_147 = V_156 ;
break;
case V_157 :
V_147 = V_158 ;
break;
case V_159 :
case V_160 :
V_147 = V_161 ;
break;
case V_162 :
if ( V_9 -> V_163 == V_164 || V_9 -> V_163 == V_165
|| V_9 -> V_163 == V_166 )
V_147 = V_167 ;
else
V_147 = V_161 ;
break;
case V_168 :
V_147 = V_169 ;
break;
default:
F_20 ( L_11 ) ;
}
return V_147 ;
}
static int F_85 ( struct V_1 * V_1 , enum V_170 type )
{
V_6 ;
if ( ( V_171 == type ) || ( V_172 == type ) ) {
F_86 ( V_9 -> V_173 . V_174 ) ;
return 0 ;
}
return - V_21 ;
}
static int F_87 ( struct V_1 * V_1 ,
enum V_170 type ,
struct V_175 * V_176 )
{
V_6 ;
if ( ( V_171 != type ) && ( V_172 != type ) ) {
T_1 V_177 ;
T_4 V_178 ;
const struct V_179 * V_180 ;
enum V_146 V_181 ;
struct V_182 * V_183 ;
V_181 = F_84 ( V_1 , type ) ;
V_183 = & V_9 -> V_184 . V_183 [ V_181 ] ;
if ( V_183 -> V_174 == NULL )
return - V_21 ;
V_177 = V_183 -> V_185 ;
V_180 = ( const struct V_179 * ) V_183 -> V_174 -> V_118 ;
V_178 = F_88 ( V_180 -> V_180 . V_186 ) ;
if ( ( type == V_160 ) ||
( type == V_162 ) ) {
V_177 += F_88 ( V_180 -> V_187 ) << 2 ;
V_178 = F_88 ( V_180 -> V_188 ) << 2 ;
}
V_176 -> V_185 = V_177 ;
V_176 -> V_189 = V_178 ;
V_176 -> V_190 = ( T_3 ) F_88 ( V_180 -> V_180 . V_191 ) ;
V_176 -> V_192 = ( T_3 ) F_88 ( V_180 -> V_193 ) ;
} else {
char V_194 [ 30 ] = { 0 } ;
int V_195 = 0 ;
T_4 V_196 ;
T_4 V_197 ;
const T_6 * V_113 ;
const struct V_198 * V_199 ;
if ( ! V_9 -> V_173 . V_174 ) {
switch ( V_9 -> V_163 ) {
case V_164 :
strcpy ( V_194 , L_12 ) ;
break;
case V_200 :
strcpy ( V_194 , L_13 ) ;
break;
case V_165 :
if ( type == V_171 )
strcpy ( V_194 , L_14 ) ;
else if ( type == V_172 )
strcpy ( V_194 , L_15 ) ;
break;
case V_166 :
if ( type == V_171 )
strcpy ( V_194 , L_16 ) ;
else if ( type == V_172 )
strcpy ( V_194 , L_17 ) ;
break;
default:
F_20 ( L_18 ) ;
return - V_21 ;
}
V_195 = F_89 ( & V_9 -> V_173 . V_174 , V_194 , V_9 -> V_201 ) ;
if ( V_195 ) {
F_20 ( L_19 ) ;
return V_195 ;
}
V_195 = F_90 ( V_9 -> V_173 . V_174 ) ;
if ( V_195 ) {
F_20 ( L_20 , V_194 ) ;
F_86 ( V_9 -> V_173 . V_174 ) ;
V_9 -> V_173 . V_174 = NULL ;
return V_195 ;
}
}
V_199 = ( const struct V_198 * ) V_9 -> V_173 . V_174 -> V_118 ;
V_9 -> V_173 . V_202 = F_88 ( V_199 -> V_180 . V_191 ) ;
V_196 = F_88 ( V_199 -> V_180 . V_186 ) ;
V_197 = F_88 ( V_199 -> V_203 ) ;
V_113 = ( const T_6 * ) ( V_9 -> V_173 . V_174 -> V_118 +
F_88 ( V_199 -> V_180 . V_204 ) ) ;
V_176 -> V_190 = V_9 -> V_173 . V_202 ;
V_176 -> V_189 = V_196 ;
V_176 -> V_205 = ( void * ) V_113 ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_1 ,
struct V_206 * V_207 )
{
V_6 ;
if ( NULL == V_207 )
return - V_208 ;
if ( sizeof( struct V_206 ) != V_207 -> V_23 )
return - V_208 ;
switch ( V_207 -> V_209 ) {
case V_210 :
V_207 -> V_66 = V_9 -> V_78 -> V_211 | ( V_9 -> V_78 -> V_212 -> V_213 << 8 ) ;
break;
case V_214 :
V_207 -> V_66 = V_9 -> V_173 . V_215 ;
break;
case V_216 :
V_207 -> V_66 = V_9 -> V_173 . V_217 ;
break;
case V_218 :
V_207 -> V_66 = V_9 -> V_219 ;
break;
case V_220 :
V_207 -> V_66 = V_9 -> V_221 ;
break;
case V_222 :
V_207 -> V_66 = V_9 -> V_223 . V_224 . V_213 ;
break;
default:
return - V_208 ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_1 ,
struct V_225 * V_176 )
{
V_6 ;
struct V_226 * V_226 ;
struct V_227 * V_228 = V_9 -> V_228 ;
struct V_229 * V_230 ;
T_4 V_231 , V_232 ;
struct V_233 * V_96 ;
if ( V_176 == NULL )
return - V_21 ;
V_96 = V_176 -> V_96 ;
if ( V_9 -> V_96 . V_234 && V_9 -> V_96 . V_235 ) {
F_93 (crtc,
&ddev->mode_config.crtc_list, head) {
V_226 = F_94 ( V_230 ) ;
if ( V_230 -> V_236 ) {
V_176 -> V_237 |= ( 1 << V_226 -> V_238 ) ;
V_176 -> V_239 ++ ;
}
if ( V_96 != NULL &&
V_230 -> V_236 && V_226 -> V_236 &&
V_226 -> V_240 . clock ) {
V_231 = ( V_226 -> V_240 . V_241 * 1000 ) /
V_226 -> V_240 . clock ;
V_232 = V_226 -> V_240 . V_242 -
V_226 -> V_240 . V_243 +
( V_226 -> V_244 * 2 ) ;
V_96 -> V_245 = V_232 * V_231 ;
V_96 -> V_246 = F_95 ( & V_226 -> V_240 ) ;
V_96 -> V_247 = V_9 -> clock . V_248 . V_249 ;
V_96 = NULL ;
}
}
}
return 0 ;
}
static int F_96 ( struct V_1 * V_1 , bool V_236 )
{
V_6 ;
V_9 -> V_173 . V_250 = V_236 ;
return 0 ;
}
static int F_97 ( struct V_1 * V_1 ,
struct V_251 * V_176 )
{
V_6 ;
T_9 V_42 ;
struct V_252 V_253 ;
struct V_254 V_255 = { V_256 , NULL } ;
union V_257 * V_258 = NULL ;
union V_257 * V_39 = NULL ;
T_6 V_259 [ 5 ] = { '\0' } ;
struct V_260 * V_261 = NULL ;
T_4 V_137 , V_262 ;
T_10 V_263 ;
int V_147 = 0 ;
T_4 V_264 = 0xFFFFFFFF ;
V_42 = F_98 ( & V_9 -> V_78 -> V_201 ) ;
if ( ! V_42 )
return - V_208 ;
memset ( & V_253 , 0 , sizeof( struct V_252 ) ) ;
if ( V_176 -> V_23 != sizeof( struct V_251 ) )
return - V_21 ;
V_253 . V_262 = V_176 -> V_265 ;
if ( V_176 -> V_265 > 0 ) {
if ( V_176 -> V_266 == NULL )
return - V_21 ;
V_261 = V_176 -> V_266 ;
V_264 = V_261 -> V_66 ;
for ( V_137 = 0 ; V_137 < V_176 -> V_265 ; V_137 ++ ) {
if ( ( ( V_261 -> type == V_267 ) ||
( V_261 -> type == V_268 ) ) &&
( V_261 -> V_269 == NULL ) )
return - V_21 ;
V_261 ++ ;
}
}
if ( V_176 -> V_270 > 0 ) {
if ( V_176 -> V_271 == NULL )
return - V_21 ;
V_261 = V_176 -> V_271 ;
for ( V_137 = 0 ; V_137 < V_176 -> V_270 ; V_137 ++ ) {
if ( ( ( V_261 -> type == V_267 ) ||
( V_261 -> type == V_268 ) )
&& ( V_261 -> V_269 == NULL ) )
return - V_21 ;
V_261 ++ ;
}
}
if ( ( V_176 -> V_272 & V_273 ) != 0 ) {
strncpy ( V_259 , ( char * ) & ( V_176 -> V_259 ) , sizeof( T_4 ) ) ;
V_259 [ 4 ] = '\0' ;
}
if ( V_253 . V_262 > 0 ) {
V_253 . V_269 = V_258 =
F_75 ( sizeof( union V_257 ) * V_253 . V_262 , V_128 ) ;
if ( V_258 == NULL )
return - V_21 ;
V_261 = V_176 -> V_266 ;
for ( V_137 = 0 ; V_137 < V_253 . V_262 ; V_137 ++ ) {
V_258 -> type = V_261 -> type ;
switch ( V_258 -> type ) {
case V_274 :
V_258 -> integer . V_66 = V_261 -> V_66 ;
break;
case V_267 :
V_258 -> string . V_275 = V_261 -> V_276 ;
V_258 -> string . V_269 = V_261 -> V_269 ;
break;
case V_268 :
V_258 -> V_277 . V_275 = V_261 -> V_276 ;
V_258 -> V_277 . V_269 = V_261 -> V_269 ;
break;
default:
break;
}
V_258 ++ ;
V_261 ++ ;
}
}
V_262 = V_176 -> V_270 ;
V_261 = V_176 -> V_271 ;
V_263 = F_99 ( V_42 , V_259 , & V_253 , & V_255 ) ;
if ( F_100 ( V_263 ) ) {
V_147 = - V_278 ;
goto error;
}
V_39 = V_255 . V_269 ;
if ( V_262 > 1 ) {
if ( ( V_39 -> type != V_279 ) ||
( V_39 -> V_280 . V_262 != V_262 ) ) {
V_147 = - V_278 ;
goto error;
}
V_258 = V_39 -> V_280 . V_281 ;
} else
V_258 = V_39 ;
if ( V_258 == NULL ) {
V_147 = - V_278 ;
goto error;
}
for ( V_137 = 0 ; V_137 < V_262 ; V_137 ++ ) {
if ( V_261 -> type != V_258 -> type ) {
V_147 = - V_278 ;
goto error;
}
switch ( V_258 -> type ) {
case V_274 :
V_261 -> V_66 = V_258 -> integer . V_66 ;
break;
case V_267 :
if ( ( V_258 -> string . V_275 != V_261 -> V_282 ) ||
( V_258 -> string . V_269 == NULL ) ) {
V_147 = - V_278 ;
goto error;
}
strncpy ( V_261 -> V_269 ,
V_258 -> string . V_269 ,
V_258 -> string . V_275 ) ;
break;
case V_268 :
if ( V_258 -> V_277 . V_269 == NULL ) {
V_147 = - V_278 ;
goto error;
}
memcpy ( V_261 -> V_269 ,
V_258 -> V_277 . V_269 ,
V_261 -> V_282 ) ;
break;
default:
break;
}
V_261 ++ ;
V_258 ++ ;
}
error:
if ( V_39 != NULL )
F_76 ( V_39 ) ;
F_76 ( ( void * ) V_253 . V_269 ) ;
return V_147 ;
}
static int F_97 ( struct V_1 * V_1 ,
struct V_251 * V_176 )
{
return - V_278 ;
}
int F_101 ( struct V_1 * V_1 ,
T_4 V_283 ,
T_4 V_284 ,
void * V_285 , void * V_286 ,
T_4 V_270 ,
T_4 V_287 ,
T_4 V_288 )
{
struct V_260 V_289 [ 2 ] = { { 0 } , { 0 } } ;
struct V_260 V_290 = { 0 } ;
struct V_251 V_176 = { 0 } ;
V_289 [ 0 ] . type = V_291 ;
V_289 [ 0 ] . V_276 = sizeof( T_4 ) ;
V_289 [ 0 ] . V_282 = sizeof( T_4 ) ;
V_289 [ 0 ] . V_66 = V_284 ;
V_289 [ 1 ] . type = V_292 ;
V_289 [ 1 ] . V_276 = V_293 ;
V_289 [ 1 ] . V_282 = V_287 ;
V_289 [ 1 ] . V_269 = V_285 ;
V_290 . type = V_292 ;
V_290 . V_276 = V_293 ;
V_290 . V_282 = V_288 ;
V_290 . V_269 = V_286 ;
V_176 . V_23 = sizeof( struct V_251 ) ;
V_176 . V_272 = V_273 | V_294 ;
V_176 . V_265 = 2 ;
V_176 . V_259 = V_283 ;
V_176 . V_266 = V_289 ;
V_176 . V_270 = V_270 ;
V_176 . V_271 = & V_290 ;
return F_97 ( V_1 , & V_176 ) ;
}
struct V_1 * F_102 ( struct V_111 * V_9 )
{
struct V_295 * V_1 =
F_103 ( sizeof( * V_1 ) , V_128 ) ;
if ( ! V_1 ) {
F_20 ( L_21 ) ;
return NULL ;
}
V_1 -> V_88 . V_296 = & V_297 ;
V_1 -> V_88 . V_298 = & V_299 ;
V_1 -> V_9 = V_9 ;
return (struct V_1 * ) V_1 ;
}
void F_104 ( struct V_1 * V_1 )
{
F_76 ( V_1 ) ;
}
