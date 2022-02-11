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
enum V_174 type ,
struct V_188 * V_189 )
{
V_6 ;
if ( ( V_175 != type ) && ( V_176 != type ) ) {
T_1 V_190 ;
T_4 V_191 ;
const struct V_192 * V_193 ;
enum V_150 V_194 ;
struct V_195 * V_196 ;
V_194 = F_86 ( V_1 , type ) ;
V_196 = & V_9 -> V_197 . V_196 [ V_194 ] ;
if ( V_196 -> V_178 == NULL )
return - V_21 ;
V_190 = V_196 -> V_198 ;
V_193 = ( const struct V_192 * ) V_196 -> V_178 -> V_121 ;
V_191 = F_91 ( V_193 -> V_193 . V_199 ) ;
if ( ( type == V_164 ) ||
( type == V_166 ) ) {
V_190 += F_4 ( F_91 ( V_193 -> V_193 . V_199 ) , V_34 ) ;
V_191 = F_91 ( V_193 -> V_200 ) << 2 ;
}
V_189 -> V_201 = V_196 -> V_202 ;
V_189 -> V_203 = V_191 ;
V_189 -> V_198 = V_190 ;
V_189 -> V_145 = ( T_3 ) F_91 ( V_193 -> V_193 . V_204 ) ;
if ( V_163 == type )
V_189 -> V_203 = ( V_193 -> V_205 ) << 2 ;
V_189 -> V_179 = F_89 ( V_1 , type ) ;
V_189 -> V_206 = ( T_3 ) F_91 ( V_193 -> V_207 ) ;
} else {
char V_208 [ 30 ] = { 0 } ;
int V_209 = 0 ;
T_4 V_210 ;
T_4 V_211 ;
const T_6 * V_116 ;
const struct V_212 * V_213 ;
if ( ! V_9 -> V_177 . V_178 ) {
switch ( V_9 -> V_167 ) {
case V_168 :
if ( ( ( V_9 -> V_81 -> V_214 == 0x6900 ) && ( V_9 -> V_81 -> V_215 == 0x81 ) ) ||
( ( V_9 -> V_81 -> V_214 == 0x6900 ) && ( V_9 -> V_81 -> V_215 == 0x83 ) ) ||
( ( V_9 -> V_81 -> V_214 == 0x6907 ) && ( V_9 -> V_81 -> V_215 == 0x87 ) ) )
strcpy ( V_208 , L_13 ) ;
else
strcpy ( V_208 , L_14 ) ;
break;
case V_216 :
if ( ( ( V_9 -> V_81 -> V_214 == 0x6939 ) && ( V_9 -> V_81 -> V_215 == 0xf1 ) ) ||
( ( V_9 -> V_81 -> V_214 == 0x6938 ) && ( V_9 -> V_81 -> V_215 == 0xf1 ) ) )
strcpy ( V_208 , L_15 ) ;
else
strcpy ( V_208 , L_16 ) ;
break;
case V_217 :
strcpy ( V_208 , L_17 ) ;
break;
case V_218 :
if ( type == V_175 )
strcpy ( V_208 , L_18 ) ;
else if ( type == V_176 )
strcpy ( V_208 , L_19 ) ;
break;
case V_219 :
if ( type == V_175 )
strcpy ( V_208 , L_20 ) ;
else if ( type == V_176 )
strcpy ( V_208 , L_21 ) ;
break;
case V_220 :
strcpy ( V_208 , L_22 ) ;
break;
default:
F_20 ( L_23 ) ;
return - V_21 ;
}
V_209 = F_92 ( & V_9 -> V_177 . V_178 , V_208 , V_9 -> V_221 ) ;
if ( V_209 ) {
F_20 ( L_24 ) ;
return V_209 ;
}
V_209 = F_93 ( V_9 -> V_177 . V_178 ) ;
if ( V_209 ) {
F_20 ( L_25 , V_208 ) ;
F_88 ( V_9 -> V_177 . V_178 ) ;
V_9 -> V_177 . V_178 = NULL ;
return V_209 ;
}
}
V_213 = ( const struct V_212 * ) V_9 -> V_177 . V_178 -> V_121 ;
F_94 ( & V_213 -> V_193 ) ;
V_9 -> V_177 . V_179 = F_91 ( V_213 -> V_193 . V_204 ) ;
V_210 = F_91 ( V_213 -> V_193 . V_199 ) ;
V_211 = F_91 ( V_213 -> V_222 ) ;
V_116 = ( const T_6 * ) ( V_9 -> V_177 . V_178 -> V_121 +
F_91 ( V_213 -> V_193 . V_223 ) ) ;
V_189 -> V_145 = V_9 -> V_177 . V_179 ;
V_189 -> V_203 = V_210 ;
V_189 -> V_211 = V_211 ;
V_189 -> V_201 = ( void * ) V_116 ;
}
return 0 ;
}
static int F_95 ( void * V_1 )
{
V_6 ;
return F_96 ( V_9 ) ;
}
static int F_97 ( struct V_1 * V_1 ,
struct V_224 * V_225 )
{
V_6 ;
if ( NULL == V_225 )
return - V_226 ;
if ( sizeof( struct V_224 ) != V_225 -> V_23 )
return - V_226 ;
switch ( V_225 -> V_227 ) {
case V_228 :
V_225 -> V_68 = V_9 -> V_81 -> V_229 | ( V_9 -> V_81 -> V_230 -> V_231 << 8 ) ;
break;
case V_232 :
V_225 -> V_68 = V_9 -> V_177 . V_233 ;
break;
case V_234 :
V_225 -> V_68 = V_9 -> V_177 . V_235 ;
break;
case V_236 :
V_225 -> V_68 = V_9 -> V_81 -> V_214 ;
break;
case V_237 :
V_225 -> V_68 = V_9 -> V_81 -> V_215 ;
break;
case V_238 :
V_225 -> V_68 = V_9 -> V_239 ;
break;
case V_240 :
V_225 -> V_68 = V_9 -> V_241 ;
break;
case V_242 :
V_225 -> V_68 = V_9 -> V_182 . V_243 . V_231 ;
break;
case V_244 :
V_225 -> V_68 = V_9 -> V_182 . V_245 . V_246 ;
break;
case V_247 :
V_225 -> V_68 = V_9 -> V_81 -> V_248 ;
break;
case V_249 :
V_225 -> V_68 = V_9 -> V_81 -> V_250 ;
break;
default:
return - V_226 ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_1 ,
struct V_251 * V_189 )
{
V_6 ;
struct V_252 * V_252 ;
struct V_253 * V_254 = V_9 -> V_254 ;
struct V_255 * V_256 ;
T_4 V_257 , V_258 ;
struct V_259 * V_99 ;
if ( V_189 == NULL )
return - V_21 ;
V_99 = V_189 -> V_99 ;
if ( V_9 -> V_99 . V_260 && V_9 -> V_99 . V_261 ) {
F_99 (crtc,
&ddev->mode_config.crtc_list, head) {
V_252 = F_100 ( V_256 ) ;
if ( V_256 -> V_262 ) {
V_189 -> V_263 |= ( 1 << V_252 -> V_264 ) ;
V_189 -> V_265 ++ ;
}
if ( V_99 != NULL &&
V_256 -> V_262 && V_252 -> V_262 &&
V_252 -> V_266 . clock ) {
V_257 = ( V_252 -> V_266 . V_267 * 1000 ) /
V_252 -> V_266 . clock ;
V_258 = V_252 -> V_266 . V_268 -
V_252 -> V_266 . V_269 +
( V_252 -> V_270 * 2 ) ;
V_99 -> V_271 = V_258 * V_257 ;
V_99 -> V_272 = F_101 ( & V_252 -> V_266 ) ;
V_99 -> V_273 = V_9 -> clock . V_274 . V_275 ;
V_99 = NULL ;
}
}
}
return 0 ;
}
static int F_102 ( struct V_1 * V_1 , bool V_262 )
{
V_6 ;
V_9 -> V_177 . V_276 = V_262 ;
return 0 ;
}
static int F_103 ( struct V_1 * V_1 ,
struct V_277 * V_189 )
{
V_6 ;
T_9 V_42 ;
struct V_278 V_279 ;
struct V_280 V_281 = { V_282 , NULL } ;
union V_283 * V_284 , * V_39 ;
T_6 V_285 [ 5 ] = { '\0' } ;
struct V_286 * V_287 ;
T_4 V_140 , V_288 ;
T_10 V_143 ;
int V_151 ;
V_42 = F_104 ( & V_9 -> V_81 -> V_221 ) ;
if ( ! V_42 )
return - V_226 ;
memset ( & V_279 , 0 , sizeof( struct V_278 ) ) ;
if ( V_189 -> V_23 != sizeof( struct V_277 ) )
return - V_21 ;
V_279 . V_288 = V_189 -> V_289 ;
if ( V_189 -> V_289 > 0 ) {
if ( V_189 -> V_290 == NULL )
return - V_21 ;
V_287 = V_189 -> V_290 ;
for ( V_140 = 0 ; V_140 < V_189 -> V_289 ; V_140 ++ ) {
if ( ( ( V_287 -> type == V_291 ) ||
( V_287 -> type == V_292 ) ) &&
( V_287 -> V_293 == NULL ) )
return - V_21 ;
V_287 ++ ;
}
}
if ( V_189 -> V_294 > 0 ) {
if ( V_189 -> V_295 == NULL )
return - V_21 ;
V_287 = V_189 -> V_295 ;
for ( V_140 = 0 ; V_140 < V_189 -> V_294 ; V_140 ++ ) {
if ( ( ( V_287 -> type == V_291 ) ||
( V_287 -> type == V_292 ) )
&& ( V_287 -> V_293 == NULL ) )
return - V_21 ;
V_287 ++ ;
}
}
if ( ( V_189 -> V_296 & V_297 ) != 0 ) {
strncpy ( V_285 , ( char * ) & ( V_189 -> V_285 ) , sizeof( T_4 ) ) ;
V_285 [ 4 ] = '\0' ;
}
if ( V_279 . V_288 > 0 ) {
V_279 . V_293 = V_284 =
F_77 ( sizeof( union V_283 ) * V_279 . V_288 , V_131 ) ;
if ( V_284 == NULL )
return - V_21 ;
V_287 = V_189 -> V_290 ;
for ( V_140 = 0 ; V_140 < V_279 . V_288 ; V_140 ++ ) {
V_284 -> type = V_287 -> type ;
switch ( V_284 -> type ) {
case V_298 :
V_284 -> integer . V_68 = V_287 -> V_68 ;
break;
case V_291 :
V_284 -> string . V_299 = V_287 -> V_300 ;
V_284 -> string . V_293 = V_287 -> V_293 ;
break;
case V_292 :
V_284 -> V_301 . V_299 = V_287 -> V_300 ;
V_284 -> V_301 . V_293 = V_287 -> V_293 ;
break;
default:
break;
}
V_284 ++ ;
V_287 ++ ;
}
}
V_288 = V_189 -> V_294 ;
V_287 = V_189 -> V_295 ;
V_143 = F_105 ( V_42 , V_285 , & V_279 , & V_281 ) ;
if ( F_106 ( V_143 ) ) {
V_151 = - V_302 ;
goto V_303;
}
V_39 = V_281 . V_293 ;
if ( V_288 > 1 ) {
if ( ( V_39 -> type != V_304 ) ||
( V_39 -> V_305 . V_288 != V_288 ) ) {
V_151 = - V_302 ;
goto V_306;
}
V_284 = V_39 -> V_305 . V_307 ;
} else
V_284 = V_39 ;
if ( V_284 == NULL ) {
V_151 = - V_302 ;
goto V_306;
}
for ( V_140 = 0 ; V_140 < V_288 ; V_140 ++ ) {
if ( V_287 -> type != V_284 -> type ) {
V_151 = - V_302 ;
goto V_306;
}
switch ( V_284 -> type ) {
case V_298 :
V_287 -> V_68 = V_284 -> integer . V_68 ;
break;
case V_291 :
if ( ( V_284 -> string . V_299 != V_287 -> V_300 ) ||
( V_284 -> string . V_293 == NULL ) ) {
V_151 = - V_302 ;
goto V_306;
}
strncpy ( V_287 -> V_293 ,
V_284 -> string . V_293 ,
V_284 -> string . V_299 ) ;
break;
case V_292 :
if ( V_284 -> V_301 . V_293 == NULL ) {
V_151 = - V_302 ;
goto V_306;
}
memcpy ( V_287 -> V_293 ,
V_284 -> V_301 . V_293 ,
V_287 -> V_300 ) ;
break;
default:
break;
}
V_287 ++ ;
V_284 ++ ;
}
V_151 = 0 ;
V_306:
F_78 ( V_39 ) ;
V_303:
F_78 ( ( void * ) V_279 . V_293 ) ;
return V_151 ;
}
static int F_103 ( struct V_1 * V_1 ,
struct V_277 * V_189 )
{
return - V_302 ;
}
static int F_107 ( struct V_1 * V_1 ,
T_4 V_308 ,
T_4 V_309 ,
void * V_310 , void * V_311 ,
T_4 V_294 ,
T_4 V_312 ,
T_4 V_313 )
{
struct V_286 V_314 [ 2 ] = { { 0 } , { 0 } } ;
struct V_286 V_315 = { 0 } ;
struct V_277 V_189 = { 0 } ;
V_314 [ 0 ] . type = V_316 ;
V_314 [ 0 ] . V_300 = sizeof( T_4 ) ;
V_314 [ 0 ] . V_68 = V_309 ;
V_314 [ 1 ] . type = V_317 ;
V_314 [ 1 ] . V_300 = V_312 ;
V_314 [ 1 ] . V_293 = V_310 ;
V_315 . type = V_317 ;
V_315 . V_300 = V_313 ;
V_315 . V_293 = V_311 ;
V_189 . V_23 = sizeof( struct V_277 ) ;
V_189 . V_296 = V_297 | V_318 ;
V_189 . V_289 = 2 ;
V_189 . V_285 = V_308 ;
V_189 . V_290 = V_314 ;
V_189 . V_294 = V_294 ;
V_189 . V_295 = & V_315 ;
return F_103 ( V_1 , & V_189 ) ;
}
struct V_1 * F_108 ( struct V_114 * V_9 )
{
struct V_319 * V_1 =
F_109 ( sizeof( * V_1 ) , V_131 ) ;
if ( ! V_1 ) {
F_20 ( L_26 ) ;
return NULL ;
}
V_1 -> V_91 . V_320 = & V_321 ;
V_1 -> V_91 . V_322 = & V_323 ;
V_1 -> V_9 = V_9 ;
return (struct V_1 * ) V_1 ;
}
void F_110 ( struct V_1 * V_1 )
{
F_78 ( V_1 ) ;
}
