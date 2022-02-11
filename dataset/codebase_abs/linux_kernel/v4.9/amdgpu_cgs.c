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
static int F_84 ( struct V_1 * V_1 ,
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
static int F_85 ( struct V_1 * V_1 ,
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
static T_3 F_89 ( struct V_1 * V_1 ,
enum V_171 type )
{
V_6 ;
T_3 V_176 ;
switch ( type ) {
case V_150 :
V_176 = V_9 -> V_177 . V_178 [ 0 ] . V_176 ;
break;
case V_152 :
V_176 = V_9 -> V_177 . V_178 [ 1 ] . V_176 ;
break;
case V_154 :
V_176 = V_9 -> V_179 . V_180 ;
break;
case V_156 :
V_176 = V_9 -> V_179 . V_181 ;
break;
case V_158 :
V_176 = V_9 -> V_179 . V_182 ;
break;
case V_160 :
V_176 = V_9 -> V_179 . V_183 ;
break;
case V_161 :
V_176 = V_9 -> V_179 . V_183 ;
break;
case V_163 :
V_176 = V_9 -> V_179 . V_183 ;
break;
case V_169 :
V_176 = V_9 -> V_179 . V_184 ;
break;
default:
F_20 ( L_12 , type ) ;
V_176 = 0 ;
}
return V_176 ;
}
static int F_90 ( struct V_1 * V_1 ,
enum V_171 type ,
struct V_185 * V_186 )
{
V_6 ;
if ( ( V_172 != type ) && ( V_173 != type ) ) {
T_1 V_187 ;
T_4 V_188 ;
const struct V_189 * V_190 ;
enum V_147 V_191 ;
struct V_192 * V_193 ;
V_191 = F_86 ( V_1 , type ) ;
V_193 = & V_9 -> V_194 . V_193 [ V_191 ] ;
if ( V_193 -> V_175 == NULL )
return - V_21 ;
V_187 = V_193 -> V_195 ;
V_190 = ( const struct V_189 * ) V_193 -> V_175 -> V_119 ;
V_188 = F_91 ( V_190 -> V_190 . V_196 ) ;
if ( ( type == V_161 ) ||
( type == V_163 ) ) {
V_187 += F_91 ( V_190 -> V_197 ) << 2 ;
V_188 = F_91 ( V_190 -> V_198 ) << 2 ;
}
V_186 -> V_195 = V_187 ;
V_186 -> V_199 = V_188 ;
V_186 -> V_200 = ( T_3 ) F_91 ( V_190 -> V_190 . V_201 ) ;
V_186 -> V_176 = F_89 ( V_1 , type ) ;
V_186 -> V_202 = ( T_3 ) F_91 ( V_190 -> V_203 ) ;
} else {
char V_204 [ 30 ] = { 0 } ;
int V_205 = 0 ;
T_4 V_206 ;
T_4 V_207 ;
const T_6 * V_114 ;
const struct V_208 * V_209 ;
if ( ! V_9 -> V_174 . V_175 ) {
switch ( V_9 -> V_164 ) {
case V_210 :
if ( ( ( V_9 -> V_79 -> V_211 == 0x6900 ) && ( V_9 -> V_79 -> V_212 == 0x81 ) ) ||
( ( V_9 -> V_79 -> V_211 == 0x6900 ) && ( V_9 -> V_79 -> V_212 == 0x83 ) ) ||
( ( V_9 -> V_79 -> V_211 == 0x6907 ) && ( V_9 -> V_79 -> V_212 == 0x87 ) ) )
strcpy ( V_204 , L_13 ) ;
else
strcpy ( V_204 , L_14 ) ;
break;
case V_165 :
if ( ( ( V_9 -> V_79 -> V_211 == 0x6939 ) && ( V_9 -> V_79 -> V_212 == 0xf1 ) ) ||
( ( V_9 -> V_79 -> V_211 == 0x6938 ) && ( V_9 -> V_79 -> V_212 == 0xf1 ) ) )
strcpy ( V_204 , L_15 ) ;
else
strcpy ( V_204 , L_16 ) ;
break;
case V_213 :
strcpy ( V_204 , L_17 ) ;
break;
case V_166 :
if ( type == V_172 )
strcpy ( V_204 , L_18 ) ;
else if ( type == V_173 )
strcpy ( V_204 , L_19 ) ;
break;
case V_167 :
if ( type == V_172 )
strcpy ( V_204 , L_20 ) ;
else if ( type == V_173 )
strcpy ( V_204 , L_21 ) ;
break;
default:
F_20 ( L_22 ) ;
return - V_21 ;
}
V_205 = F_92 ( & V_9 -> V_174 . V_175 , V_204 , V_9 -> V_214 ) ;
if ( V_205 ) {
F_20 ( L_23 ) ;
return V_205 ;
}
V_205 = F_93 ( V_9 -> V_174 . V_175 ) ;
if ( V_205 ) {
F_20 ( L_24 , V_204 ) ;
F_88 ( V_9 -> V_174 . V_175 ) ;
V_9 -> V_174 . V_175 = NULL ;
return V_205 ;
}
}
V_209 = ( const struct V_208 * ) V_9 -> V_174 . V_175 -> V_119 ;
F_94 ( & V_209 -> V_190 ) ;
V_9 -> V_174 . V_176 = F_91 ( V_209 -> V_190 . V_201 ) ;
V_206 = F_91 ( V_209 -> V_190 . V_196 ) ;
V_207 = F_91 ( V_209 -> V_215 ) ;
V_114 = ( const T_6 * ) ( V_9 -> V_174 . V_175 -> V_119 +
F_91 ( V_209 -> V_190 . V_216 ) ) ;
V_186 -> V_200 = V_9 -> V_174 . V_176 ;
V_186 -> V_199 = V_206 ;
V_186 -> V_207 = V_207 ;
V_186 -> V_217 = ( void * ) V_114 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_1 ,
struct V_218 * V_219 )
{
V_6 ;
if ( NULL == V_219 )
return - V_220 ;
if ( sizeof( struct V_218 ) != V_219 -> V_23 )
return - V_220 ;
switch ( V_219 -> V_221 ) {
case V_222 :
V_219 -> V_66 = V_9 -> V_79 -> V_223 | ( V_9 -> V_79 -> V_224 -> V_225 << 8 ) ;
break;
case V_226 :
V_219 -> V_66 = V_9 -> V_174 . V_227 ;
break;
case V_228 :
V_219 -> V_66 = V_9 -> V_174 . V_229 ;
break;
case V_230 :
V_219 -> V_66 = V_9 -> V_79 -> V_211 ;
break;
case V_231 :
V_219 -> V_66 = V_9 -> V_79 -> V_212 ;
break;
case V_232 :
V_219 -> V_66 = V_9 -> V_233 ;
break;
case V_234 :
V_219 -> V_66 = V_9 -> V_235 ;
break;
case V_236 :
V_219 -> V_66 = V_9 -> V_179 . V_237 . V_225 ;
break;
case V_238 :
V_219 -> V_66 = V_9 -> V_179 . V_239 . V_240 ;
break;
case V_241 :
V_219 -> V_66 = V_9 -> V_79 -> V_242 ;
break;
case V_243 :
V_219 -> V_66 = V_9 -> V_79 -> V_244 ;
break;
default:
return - V_220 ;
}
return 0 ;
}
static int F_96 ( struct V_1 * V_1 ,
struct V_245 * V_186 )
{
V_6 ;
struct V_246 * V_246 ;
struct V_247 * V_248 = V_9 -> V_248 ;
struct V_249 * V_250 ;
T_4 V_251 , V_252 ;
struct V_253 * V_97 ;
if ( V_186 == NULL )
return - V_21 ;
V_97 = V_186 -> V_97 ;
if ( V_9 -> V_97 . V_254 && V_9 -> V_97 . V_255 ) {
F_97 (crtc,
&ddev->mode_config.crtc_list, head) {
V_246 = F_98 ( V_250 ) ;
if ( V_250 -> V_256 ) {
V_186 -> V_257 |= ( 1 << V_246 -> V_258 ) ;
V_186 -> V_259 ++ ;
}
if ( V_97 != NULL &&
V_250 -> V_256 && V_246 -> V_256 &&
V_246 -> V_260 . clock ) {
V_251 = ( V_246 -> V_260 . V_261 * 1000 ) /
V_246 -> V_260 . clock ;
V_252 = V_246 -> V_260 . V_262 -
V_246 -> V_260 . V_263 +
( V_246 -> V_264 * 2 ) ;
V_97 -> V_265 = V_252 * V_251 ;
V_97 -> V_266 = F_99 ( & V_246 -> V_260 ) ;
V_97 -> V_267 = V_9 -> clock . V_268 . V_269 ;
V_97 = NULL ;
}
}
}
return 0 ;
}
static int F_100 ( struct V_1 * V_1 , bool V_256 )
{
V_6 ;
V_9 -> V_174 . V_270 = V_256 ;
return 0 ;
}
static int F_101 ( struct V_1 * V_1 ,
struct V_271 * V_186 )
{
V_6 ;
T_9 V_42 ;
struct V_272 V_273 ;
struct V_274 V_275 = { V_276 , NULL } ;
union V_277 * V_278 , * V_39 ;
T_6 V_279 [ 5 ] = { '\0' } ;
struct V_280 * V_281 ;
T_4 V_138 , V_282 ;
T_10 V_283 ;
int V_148 ;
V_42 = F_102 ( & V_9 -> V_79 -> V_214 ) ;
if ( ! V_42 )
return - V_220 ;
memset ( & V_273 , 0 , sizeof( struct V_272 ) ) ;
if ( V_186 -> V_23 != sizeof( struct V_271 ) )
return - V_21 ;
V_273 . V_282 = V_186 -> V_284 ;
if ( V_186 -> V_284 > 0 ) {
if ( V_186 -> V_285 == NULL )
return - V_21 ;
V_281 = V_186 -> V_285 ;
for ( V_138 = 0 ; V_138 < V_186 -> V_284 ; V_138 ++ ) {
if ( ( ( V_281 -> type == V_286 ) ||
( V_281 -> type == V_287 ) ) &&
( V_281 -> V_288 == NULL ) )
return - V_21 ;
V_281 ++ ;
}
}
if ( V_186 -> V_289 > 0 ) {
if ( V_186 -> V_290 == NULL )
return - V_21 ;
V_281 = V_186 -> V_290 ;
for ( V_138 = 0 ; V_138 < V_186 -> V_289 ; V_138 ++ ) {
if ( ( ( V_281 -> type == V_286 ) ||
( V_281 -> type == V_287 ) )
&& ( V_281 -> V_288 == NULL ) )
return - V_21 ;
V_281 ++ ;
}
}
if ( ( V_186 -> V_291 & V_292 ) != 0 ) {
strncpy ( V_279 , ( char * ) & ( V_186 -> V_279 ) , sizeof( T_4 ) ) ;
V_279 [ 4 ] = '\0' ;
}
if ( V_273 . V_282 > 0 ) {
V_273 . V_288 = V_278 =
F_77 ( sizeof( union V_277 ) * V_273 . V_282 , V_129 ) ;
if ( V_278 == NULL )
return - V_21 ;
V_281 = V_186 -> V_285 ;
for ( V_138 = 0 ; V_138 < V_273 . V_282 ; V_138 ++ ) {
V_278 -> type = V_281 -> type ;
switch ( V_278 -> type ) {
case V_293 :
V_278 -> integer . V_66 = V_281 -> V_66 ;
break;
case V_286 :
V_278 -> string . V_294 = V_281 -> V_295 ;
V_278 -> string . V_288 = V_281 -> V_288 ;
break;
case V_287 :
V_278 -> V_296 . V_294 = V_281 -> V_295 ;
V_278 -> V_296 . V_288 = V_281 -> V_288 ;
break;
default:
break;
}
V_278 ++ ;
V_281 ++ ;
}
}
V_282 = V_186 -> V_289 ;
V_281 = V_186 -> V_290 ;
V_283 = F_103 ( V_42 , V_279 , & V_273 , & V_275 ) ;
if ( F_104 ( V_283 ) ) {
V_148 = - V_297 ;
goto V_298;
}
V_39 = V_275 . V_288 ;
if ( V_282 > 1 ) {
if ( ( V_39 -> type != V_299 ) ||
( V_39 -> V_300 . V_282 != V_282 ) ) {
V_148 = - V_297 ;
goto V_301;
}
V_278 = V_39 -> V_300 . V_302 ;
} else
V_278 = V_39 ;
if ( V_278 == NULL ) {
V_148 = - V_297 ;
goto V_301;
}
for ( V_138 = 0 ; V_138 < V_282 ; V_138 ++ ) {
if ( V_281 -> type != V_278 -> type ) {
V_148 = - V_297 ;
goto V_301;
}
switch ( V_278 -> type ) {
case V_293 :
V_281 -> V_66 = V_278 -> integer . V_66 ;
break;
case V_286 :
if ( ( V_278 -> string . V_294 != V_281 -> V_295 ) ||
( V_278 -> string . V_288 == NULL ) ) {
V_148 = - V_297 ;
goto V_301;
}
strncpy ( V_281 -> V_288 ,
V_278 -> string . V_288 ,
V_278 -> string . V_294 ) ;
break;
case V_287 :
if ( V_278 -> V_296 . V_288 == NULL ) {
V_148 = - V_297 ;
goto V_301;
}
memcpy ( V_281 -> V_288 ,
V_278 -> V_296 . V_288 ,
V_281 -> V_295 ) ;
break;
default:
break;
}
V_281 ++ ;
V_278 ++ ;
}
V_148 = 0 ;
V_301:
F_78 ( V_39 ) ;
V_298:
F_78 ( ( void * ) V_273 . V_288 ) ;
return V_148 ;
}
static int F_101 ( struct V_1 * V_1 ,
struct V_271 * V_186 )
{
return - V_297 ;
}
static int F_105 ( struct V_1 * V_1 ,
T_4 V_303 ,
T_4 V_304 ,
void * V_305 , void * V_306 ,
T_4 V_289 ,
T_4 V_307 ,
T_4 V_308 )
{
struct V_280 V_309 [ 2 ] = { { 0 } , { 0 } } ;
struct V_280 V_310 = { 0 } ;
struct V_271 V_186 = { 0 } ;
V_309 [ 0 ] . type = V_311 ;
V_309 [ 0 ] . V_295 = sizeof( T_4 ) ;
V_309 [ 0 ] . V_66 = V_304 ;
V_309 [ 1 ] . type = V_312 ;
V_309 [ 1 ] . V_295 = V_307 ;
V_309 [ 1 ] . V_288 = V_305 ;
V_310 . type = V_312 ;
V_310 . V_295 = V_308 ;
V_310 . V_288 = V_306 ;
V_186 . V_23 = sizeof( struct V_271 ) ;
V_186 . V_291 = V_292 | V_313 ;
V_186 . V_284 = 2 ;
V_186 . V_279 = V_303 ;
V_186 . V_285 = V_309 ;
V_186 . V_289 = V_289 ;
V_186 . V_290 = & V_310 ;
return F_101 ( V_1 , & V_186 ) ;
}
struct V_1 * F_106 ( struct V_112 * V_9 )
{
struct V_314 * V_1 =
F_107 ( sizeof( * V_1 ) , V_129 ) ;
if ( ! V_1 ) {
F_20 ( L_25 ) ;
return NULL ;
}
V_1 -> V_89 . V_315 = & V_316 ;
V_1 -> V_89 . V_317 = & V_318 ;
V_1 -> V_9 = V_9 ;
return (struct V_1 * ) V_1 ;
}
void F_108 ( struct V_1 * V_1 )
{
F_78 ( V_1 ) ;
}
