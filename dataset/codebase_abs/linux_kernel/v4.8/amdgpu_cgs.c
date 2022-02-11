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
return F_39 ( V_69 ) ;
case V_76 :
F_20 ( L_2 ) ;
return 0 ;
}
F_40 ( 1 , L_3 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_1 ,
enum V_67 V_68 ,
unsigned V_69 , T_4 V_66 )
{
V_6 ;
switch ( V_68 ) {
case V_70 :
return F_42 ( V_69 , V_66 ) ;
case V_71 :
return F_43 ( V_69 , V_66 ) ;
case V_72 :
return F_44 ( V_69 , V_66 ) ;
case V_73 :
return F_45 ( V_69 , V_66 ) ;
case V_74 :
return F_46 ( V_69 , V_66 ) ;
case V_75 :
return F_47 ( V_69 , V_66 ) ;
case V_76 :
F_20 ( L_2 ) ;
return;
}
F_40 ( 1 , L_3 ) ;
}
static T_6 F_48 ( struct V_1 * V_1 , unsigned V_77 )
{
V_6 ;
T_6 V_78 ;
int V_28 = F_49 ( V_9 -> V_79 , V_77 , & V_78 ) ;
if ( F_40 ( V_28 , L_4 ) )
return 0 ;
return V_78 ;
}
static T_3 F_50 ( struct V_1 * V_1 , unsigned V_77 )
{
V_6 ;
T_3 V_78 ;
int V_28 = F_51 ( V_9 -> V_79 , V_77 , & V_78 ) ;
if ( F_40 ( V_28 , L_5 ) )
return 0 ;
return V_78 ;
}
static T_4 F_52 ( struct V_1 * V_1 ,
unsigned V_77 )
{
V_6 ;
T_4 V_78 ;
int V_28 = F_53 ( V_9 -> V_79 , V_77 , & V_78 ) ;
if ( F_40 ( V_28 , L_6 ) )
return 0 ;
return V_78 ;
}
static void F_54 ( struct V_1 * V_1 , unsigned V_77 ,
T_6 V_66 )
{
V_6 ;
int V_28 = F_55 ( V_9 -> V_79 , V_77 , V_66 ) ;
F_40 ( V_28 , L_7 ) ;
}
static void F_56 ( struct V_1 * V_1 , unsigned V_77 ,
T_3 V_66 )
{
V_6 ;
int V_28 = F_57 ( V_9 -> V_79 , V_77 , V_66 ) ;
F_40 ( V_28 , L_8 ) ;
}
static void F_58 ( struct V_1 * V_1 , unsigned V_77 ,
T_4 V_66 )
{
V_6 ;
int V_28 = F_59 ( V_9 -> V_79 , V_77 , V_66 ) ;
F_40 ( V_28 , L_9 ) ;
}
static int F_60 ( struct V_1 * V_1 ,
enum V_80 V_81 ,
T_1 V_23 ,
T_1 V_65 ,
T_1 * V_82 )
{
V_6 ;
if ( V_82 == NULL )
return - V_21 ;
switch ( V_81 ) {
case V_83 :
if ( V_9 -> V_84 == 0 )
return - V_85 ;
if ( ( V_65 + V_23 ) > V_9 -> V_84 )
return - V_21 ;
* V_82 = V_9 -> V_86 ;
return 0 ;
case V_87 :
if ( V_9 -> V_88 . V_23 == 0 )
return - V_85 ;
if ( ( V_65 + V_23 ) > V_9 -> V_88 . V_23 )
return - V_21 ;
* V_82 = V_9 -> V_88 . V_89 ;
return 0 ;
case V_90 :
case V_91 :
case V_92 :
default:
return - V_21 ;
}
}
static const void * F_61 ( struct V_1 * V_1 ,
unsigned V_93 , T_3 * V_23 ,
T_6 * V_94 , T_6 * V_95 )
{
V_6 ;
T_3 V_96 ;
if ( F_62 (
V_9 -> V_97 . V_98 , V_93 , V_23 ,
V_94 , V_95 , & V_96 ) )
return ( T_6 * ) V_9 -> V_97 . V_98 -> V_99 +
V_96 ;
return NULL ;
}
static int F_63 ( struct V_1 * V_1 , unsigned V_93 ,
T_6 * V_94 , T_6 * V_95 )
{
V_6 ;
if ( F_64 (
V_9 -> V_97 . V_98 , V_93 ,
V_94 , V_95 ) )
return 0 ;
return - V_21 ;
}
static int F_65 ( struct V_1 * V_1 , unsigned V_93 ,
void * args )
{
V_6 ;
return F_66 (
V_9 -> V_97 . V_98 , V_93 , args ) ;
}
static int F_67 ( struct V_1 * V_1 , T_2 * V_100 )
{
return 0 ;
}
static int F_68 ( struct V_1 * V_1 , T_2 V_100 )
{
return 0 ;
}
static int F_69 ( struct V_1 * V_1 , T_2 V_100 ,
int V_101 )
{
return 0 ;
}
static int F_70 ( struct V_1 * V_1 , T_2 V_100 ,
enum V_102 clock , unsigned V_103 )
{
return 0 ;
}
static int F_71 ( struct V_1 * V_1 , T_2 V_100 ,
enum V_104 V_105 , int V_106 )
{
return 0 ;
}
static int F_72 ( struct V_1 * V_1 ,
enum V_102 clock ,
struct V_107 * V_108 )
{
return 0 ;
}
static int F_73 ( struct V_1 * V_1 , T_4 V_109 ,
const T_4 * V_110 )
{
F_20 ( L_10 ) ;
return - V_111 ;
}
static int F_74 ( struct V_112 * V_9 ,
struct V_113 * V_114 ,
unsigned type ,
enum V_115 V_116 )
{
struct V_117 * V_118 =
(struct V_117 * ) V_114 -> V_119 ;
if ( ! V_118 )
return - V_21 ;
if ( ! V_118 -> V_120 )
return - V_21 ;
return V_118 -> V_120 ( V_118 -> V_121 ,
V_118 -> V_122 ,
type ,
( int ) V_116 ) ;
}
static int F_75 ( struct V_112 * V_9 ,
struct V_113 * V_123 ,
struct V_124 * V_125 )
{
struct V_117 * V_118 =
(struct V_117 * ) V_123 -> V_119 ;
if ( ! V_118 )
return - V_21 ;
if ( ! V_118 -> V_126 )
return - V_21 ;
return V_118 -> V_126 ( V_118 -> V_121 ,
V_118 -> V_122 ,
V_125 -> V_127 ) ;
}
static int F_76 ( struct V_1 * V_1 , unsigned V_122 ,
unsigned V_128 ,
T_7 V_120 ,
T_8 V_126 ,
void * V_121 )
{
V_6 ;
int V_28 = 0 ;
struct V_117 * V_118 ;
struct V_113 * V_123 =
F_77 ( sizeof( struct V_113 ) , V_129 ) ;
if ( ! V_123 )
return - V_130 ;
V_118 =
F_77 ( sizeof( struct V_117 ) , V_129 ) ;
if ( ! V_118 ) {
F_78 ( V_123 ) ;
return - V_130 ;
}
V_123 -> V_128 = V_128 ;
V_123 -> V_131 = & V_132 ;
V_118 -> V_122 = V_122 ;
V_118 -> V_120 = V_120 ;
V_118 -> V_126 = V_126 ;
V_118 -> V_121 = V_121 ;
V_123 -> V_119 = ( void * ) V_118 ;
V_28 = F_79 ( V_9 , V_122 , V_123 ) ;
if ( V_28 ) {
F_78 ( V_118 ) ;
F_78 ( V_123 ) ;
}
return V_28 ;
}
static int F_80 ( struct V_1 * V_1 , unsigned V_122 , unsigned type )
{
V_6 ;
return F_81 ( V_9 , V_9 -> V_133 . V_134 [ V_122 ] , type ) ;
}
static int F_82 ( struct V_1 * V_1 , unsigned V_122 , unsigned type )
{
V_6 ;
return F_83 ( V_9 , V_9 -> V_133 . V_134 [ V_122 ] , type ) ;
}
int F_84 ( struct V_1 * V_1 ,
enum V_135 V_136 ,
enum V_137 V_116 )
{
V_6 ;
int V_138 , V_40 = - 1 ;
for ( V_138 = 0 ; V_138 < V_9 -> V_139 ; V_138 ++ ) {
if ( ! V_9 -> V_140 [ V_138 ] . V_141 )
continue;
if ( V_9 -> V_142 [ V_138 ] . type == V_136 ) {
V_40 = V_9 -> V_142 [ V_138 ] . V_131 -> V_143 (
( void * ) V_9 ,
V_116 ) ;
break;
}
}
return V_40 ;
}
int F_85 ( struct V_1 * V_1 ,
enum V_135 V_136 ,
enum V_144 V_116 )
{
V_6 ;
int V_138 , V_40 = - 1 ;
for ( V_138 = 0 ; V_138 < V_9 -> V_139 ; V_138 ++ ) {
if ( ! V_9 -> V_140 [ V_138 ] . V_141 )
continue;
if ( V_9 -> V_142 [ V_138 ] . type == V_136 ) {
V_40 = V_9 -> V_142 [ V_138 ] . V_131 -> V_145 (
( void * ) V_9 ,
V_116 ) ;
break;
}
}
return V_40 ;
}
static T_4 F_86 ( struct V_1 * V_1 , T_4 V_146 )
{
V_6 ;
enum V_147 V_148 = V_149 ;
switch ( V_146 ) {
case V_150 :
V_148 = V_151 ;
break;
case V_152 :
V_148 = V_153 ;
break;
case V_154 :
V_148 = V_155 ;
break;
case V_156 :
V_148 = V_157 ;
break;
case V_158 :
V_148 = V_159 ;
break;
case V_160 :
case V_161 :
V_148 = V_162 ;
break;
case V_163 :
if ( V_9 -> V_164 == V_165 || V_9 -> V_164 == V_166
|| V_9 -> V_164 == V_167 )
V_148 = V_168 ;
else
V_148 = V_162 ;
break;
case V_169 :
V_148 = V_170 ;
break;
default:
F_20 ( L_11 ) ;
}
return V_148 ;
}
static int F_87 ( struct V_1 * V_1 , enum V_171 type )
{
V_6 ;
if ( ( V_172 == type ) || ( V_173 == type ) ) {
F_88 ( V_9 -> V_174 . V_175 ) ;
return 0 ;
}
return - V_21 ;
}
static int F_89 ( struct V_1 * V_1 ,
enum V_171 type ,
struct V_176 * V_177 )
{
V_6 ;
if ( ( V_172 != type ) && ( V_173 != type ) ) {
T_1 V_178 ;
T_4 V_179 ;
const struct V_180 * V_181 ;
enum V_147 V_182 ;
struct V_183 * V_184 ;
V_182 = F_86 ( V_1 , type ) ;
V_184 = & V_9 -> V_185 . V_184 [ V_182 ] ;
if ( V_184 -> V_175 == NULL )
return - V_21 ;
V_178 = V_184 -> V_186 ;
V_181 = ( const struct V_180 * ) V_184 -> V_175 -> V_119 ;
V_179 = F_90 ( V_181 -> V_181 . V_187 ) ;
if ( ( type == V_161 ) ||
( type == V_163 ) ) {
V_178 += F_90 ( V_181 -> V_188 ) << 2 ;
V_179 = F_90 ( V_181 -> V_189 ) << 2 ;
}
V_177 -> V_186 = V_178 ;
V_177 -> V_190 = V_179 ;
V_177 -> V_191 = ( T_3 ) F_90 ( V_181 -> V_181 . V_192 ) ;
V_177 -> V_193 = ( T_3 ) F_90 ( V_181 -> V_194 ) ;
} else {
char V_195 [ 30 ] = { 0 } ;
int V_196 = 0 ;
T_4 V_197 ;
T_4 V_198 ;
const T_6 * V_114 ;
const struct V_199 * V_200 ;
if ( ! V_9 -> V_174 . V_175 ) {
switch ( V_9 -> V_164 ) {
case V_201 :
strcpy ( V_195 , L_12 ) ;
break;
case V_165 :
strcpy ( V_195 , L_13 ) ;
break;
case V_202 :
strcpy ( V_195 , L_14 ) ;
break;
case V_166 :
if ( type == V_172 )
strcpy ( V_195 , L_15 ) ;
else if ( type == V_173 )
strcpy ( V_195 , L_16 ) ;
break;
case V_167 :
if ( type == V_172 )
strcpy ( V_195 , L_17 ) ;
else if ( type == V_173 )
strcpy ( V_195 , L_18 ) ;
break;
default:
F_20 ( L_19 ) ;
return - V_21 ;
}
V_196 = F_91 ( & V_9 -> V_174 . V_175 , V_195 , V_9 -> V_203 ) ;
if ( V_196 ) {
F_20 ( L_20 ) ;
return V_196 ;
}
V_196 = F_92 ( V_9 -> V_174 . V_175 ) ;
if ( V_196 ) {
F_20 ( L_21 , V_195 ) ;
F_88 ( V_9 -> V_174 . V_175 ) ;
V_9 -> V_174 . V_175 = NULL ;
return V_196 ;
}
}
V_200 = ( const struct V_199 * ) V_9 -> V_174 . V_175 -> V_119 ;
F_93 ( & V_200 -> V_181 ) ;
V_9 -> V_174 . V_204 = F_90 ( V_200 -> V_181 . V_192 ) ;
V_197 = F_90 ( V_200 -> V_181 . V_187 ) ;
V_198 = F_90 ( V_200 -> V_205 ) ;
V_114 = ( const T_6 * ) ( V_9 -> V_174 . V_175 -> V_119 +
F_90 ( V_200 -> V_181 . V_206 ) ) ;
V_177 -> V_191 = V_9 -> V_174 . V_204 ;
V_177 -> V_190 = V_197 ;
V_177 -> V_198 = V_198 ;
V_177 -> V_207 = ( void * ) V_114 ;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_1 ,
struct V_208 * V_209 )
{
V_6 ;
if ( NULL == V_209 )
return - V_210 ;
if ( sizeof( struct V_208 ) != V_209 -> V_23 )
return - V_210 ;
switch ( V_209 -> V_211 ) {
case V_212 :
V_209 -> V_66 = V_9 -> V_79 -> V_213 | ( V_9 -> V_79 -> V_214 -> V_215 << 8 ) ;
break;
case V_216 :
V_209 -> V_66 = V_9 -> V_174 . V_217 ;
break;
case V_218 :
V_209 -> V_66 = V_9 -> V_174 . V_219 ;
break;
case V_220 :
V_209 -> V_66 = V_9 -> V_79 -> V_221 ;
break;
case V_222 :
V_209 -> V_66 = V_9 -> V_79 -> V_223 ;
break;
case V_224 :
V_209 -> V_66 = V_9 -> V_225 ;
break;
case V_226 :
V_209 -> V_66 = V_9 -> V_227 ;
break;
case V_228 :
V_209 -> V_66 = V_9 -> V_229 . V_230 . V_215 ;
break;
case V_231 :
V_209 -> V_66 = V_9 -> V_229 . V_232 . V_233 ;
break;
default:
return - V_210 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_1 ,
struct V_234 * V_177 )
{
V_6 ;
struct V_235 * V_235 ;
struct V_236 * V_237 = V_9 -> V_237 ;
struct V_238 * V_239 ;
T_4 V_240 , V_241 ;
struct V_242 * V_97 ;
if ( V_177 == NULL )
return - V_21 ;
V_97 = V_177 -> V_97 ;
if ( V_9 -> V_97 . V_243 && V_9 -> V_97 . V_244 ) {
F_96 (crtc,
&ddev->mode_config.crtc_list, head) {
V_235 = F_97 ( V_239 ) ;
if ( V_239 -> V_245 ) {
V_177 -> V_246 |= ( 1 << V_235 -> V_247 ) ;
V_177 -> V_248 ++ ;
}
if ( V_97 != NULL &&
V_239 -> V_245 && V_235 -> V_245 &&
V_235 -> V_249 . clock ) {
V_240 = ( V_235 -> V_249 . V_250 * 1000 ) /
V_235 -> V_249 . clock ;
V_241 = V_235 -> V_249 . V_251 -
V_235 -> V_249 . V_252 +
( V_235 -> V_253 * 2 ) ;
V_97 -> V_254 = V_241 * V_240 ;
V_97 -> V_255 = F_98 ( & V_235 -> V_249 ) ;
V_97 -> V_256 = V_9 -> clock . V_257 . V_258 ;
V_97 = NULL ;
}
}
}
return 0 ;
}
static int F_99 ( struct V_1 * V_1 , bool V_245 )
{
V_6 ;
V_9 -> V_174 . V_259 = V_245 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_1 ,
struct V_260 * V_177 )
{
V_6 ;
T_9 V_42 ;
struct V_261 V_262 ;
struct V_263 V_264 = { V_265 , NULL } ;
union V_266 * V_267 , * V_39 ;
T_6 V_268 [ 5 ] = { '\0' } ;
struct V_269 * V_270 ;
T_4 V_138 , V_271 ;
T_10 V_272 ;
int V_148 ;
V_42 = F_101 ( & V_9 -> V_79 -> V_203 ) ;
if ( ! V_42 )
return - V_210 ;
memset ( & V_262 , 0 , sizeof( struct V_261 ) ) ;
if ( V_177 -> V_23 != sizeof( struct V_260 ) )
return - V_21 ;
V_262 . V_271 = V_177 -> V_273 ;
if ( V_177 -> V_273 > 0 ) {
if ( V_177 -> V_274 == NULL )
return - V_21 ;
V_270 = V_177 -> V_274 ;
for ( V_138 = 0 ; V_138 < V_177 -> V_273 ; V_138 ++ ) {
if ( ( ( V_270 -> type == V_275 ) ||
( V_270 -> type == V_276 ) ) &&
( V_270 -> V_277 == NULL ) )
return - V_21 ;
V_270 ++ ;
}
}
if ( V_177 -> V_278 > 0 ) {
if ( V_177 -> V_279 == NULL )
return - V_21 ;
V_270 = V_177 -> V_279 ;
for ( V_138 = 0 ; V_138 < V_177 -> V_278 ; V_138 ++ ) {
if ( ( ( V_270 -> type == V_275 ) ||
( V_270 -> type == V_276 ) )
&& ( V_270 -> V_277 == NULL ) )
return - V_21 ;
V_270 ++ ;
}
}
if ( ( V_177 -> V_280 & V_281 ) != 0 ) {
strncpy ( V_268 , ( char * ) & ( V_177 -> V_268 ) , sizeof( T_4 ) ) ;
V_268 [ 4 ] = '\0' ;
}
if ( V_262 . V_271 > 0 ) {
V_262 . V_277 = V_267 =
F_77 ( sizeof( union V_266 ) * V_262 . V_271 , V_129 ) ;
if ( V_267 == NULL )
return - V_21 ;
V_270 = V_177 -> V_274 ;
for ( V_138 = 0 ; V_138 < V_262 . V_271 ; V_138 ++ ) {
V_267 -> type = V_270 -> type ;
switch ( V_267 -> type ) {
case V_282 :
V_267 -> integer . V_66 = V_270 -> V_66 ;
break;
case V_275 :
V_267 -> string . V_283 = V_270 -> V_284 ;
V_267 -> string . V_277 = V_270 -> V_277 ;
break;
case V_276 :
V_267 -> V_285 . V_283 = V_270 -> V_284 ;
V_267 -> V_285 . V_277 = V_270 -> V_277 ;
break;
default:
break;
}
V_267 ++ ;
V_270 ++ ;
}
}
V_271 = V_177 -> V_278 ;
V_270 = V_177 -> V_279 ;
V_272 = F_102 ( V_42 , V_268 , & V_262 , & V_264 ) ;
if ( F_103 ( V_272 ) ) {
V_148 = - V_286 ;
goto V_287;
}
V_39 = V_264 . V_277 ;
if ( V_271 > 1 ) {
if ( ( V_39 -> type != V_288 ) ||
( V_39 -> V_289 . V_271 != V_271 ) ) {
V_148 = - V_286 ;
goto V_290;
}
V_267 = V_39 -> V_289 . V_291 ;
} else
V_267 = V_39 ;
if ( V_267 == NULL ) {
V_148 = - V_286 ;
goto V_290;
}
for ( V_138 = 0 ; V_138 < V_271 ; V_138 ++ ) {
if ( V_270 -> type != V_267 -> type ) {
V_148 = - V_286 ;
goto V_290;
}
switch ( V_267 -> type ) {
case V_282 :
V_270 -> V_66 = V_267 -> integer . V_66 ;
break;
case V_275 :
if ( ( V_267 -> string . V_283 != V_270 -> V_284 ) ||
( V_267 -> string . V_277 == NULL ) ) {
V_148 = - V_286 ;
goto V_290;
}
strncpy ( V_270 -> V_277 ,
V_267 -> string . V_277 ,
V_267 -> string . V_283 ) ;
break;
case V_276 :
if ( V_267 -> V_285 . V_277 == NULL ) {
V_148 = - V_286 ;
goto V_290;
}
memcpy ( V_270 -> V_277 ,
V_267 -> V_285 . V_277 ,
V_270 -> V_284 ) ;
break;
default:
break;
}
V_270 ++ ;
V_267 ++ ;
}
V_148 = 0 ;
V_290:
F_78 ( V_39 ) ;
V_287:
F_78 ( ( void * ) V_262 . V_277 ) ;
return V_148 ;
}
static int F_100 ( struct V_1 * V_1 ,
struct V_260 * V_177 )
{
return - V_286 ;
}
static int F_104 ( struct V_1 * V_1 ,
T_4 V_292 ,
T_4 V_293 ,
void * V_294 , void * V_295 ,
T_4 V_278 ,
T_4 V_296 ,
T_4 V_297 )
{
struct V_269 V_298 [ 2 ] = { { 0 } , { 0 } } ;
struct V_269 V_299 = { 0 } ;
struct V_260 V_177 = { 0 } ;
V_298 [ 0 ] . type = V_300 ;
V_298 [ 0 ] . V_284 = sizeof( T_4 ) ;
V_298 [ 0 ] . V_66 = V_293 ;
V_298 [ 1 ] . type = V_301 ;
V_298 [ 1 ] . V_284 = V_296 ;
V_298 [ 1 ] . V_277 = V_294 ;
V_299 . type = V_301 ;
V_299 . V_284 = V_297 ;
V_299 . V_277 = V_295 ;
V_177 . V_23 = sizeof( struct V_260 ) ;
V_177 . V_280 = V_281 | V_302 ;
V_177 . V_273 = 2 ;
V_177 . V_268 = V_292 ;
V_177 . V_274 = V_298 ;
V_177 . V_278 = V_278 ;
V_177 . V_279 = & V_299 ;
return F_100 ( V_1 , & V_177 ) ;
}
struct V_1 * F_105 ( struct V_112 * V_9 )
{
struct V_303 * V_1 =
F_106 ( sizeof( * V_1 ) , V_129 ) ;
if ( ! V_1 ) {
F_20 ( L_22 ) ;
return NULL ;
}
V_1 -> V_89 . V_304 = & V_305 ;
V_1 -> V_89 . V_306 = & V_307 ;
V_1 -> V_9 = V_9 ;
return (struct V_1 * ) V_1 ;
}
void F_107 ( struct V_1 * V_1 )
{
F_78 ( V_1 ) ;
}
