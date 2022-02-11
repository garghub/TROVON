static int F_1 ( struct V_1 * V_1 ,
enum V_2 type ,
T_1 V_3 , T_1 V_4 ,
T_1 V_5 , T_1 V_6 ,
T_2 * V_7 )
{
V_8 ;
T_3 V_9 = 0 ;
int V_10 = 0 ;
T_4 V_11 = 0 ;
struct V_12 * V_13 ;
struct V_14 V_15 ;
struct V_16 V_17 ;
if ( V_5 > V_6 ) {
F_2 ( 1 ) ;
return - V_18 ;
}
if ( ( ( V_4 != 1 ) && ( V_4 & ( V_4 - 1 ) ) )
|| V_3 == 0 || V_4 == 0 )
return - V_18 ;
switch( type ) {
case V_19 :
case V_20 :
V_9 = V_21 |
V_22 ;
V_11 = V_23 ;
if ( V_6 > V_24 -> V_25 . V_26 )
return - V_18 ;
V_17 . V_27 = V_5 >> V_28 ;
V_17 . V_29 = V_6 >> V_28 ;
V_17 . V_9 = V_30 | V_31 |
V_32 ;
break;
case V_33 :
case V_34 :
V_9 = V_35 |
V_22 ;
V_11 = V_23 ;
if ( V_24 -> V_25 . V_36 < V_24 -> V_25 . V_26 ) {
V_17 . V_27 =
F_3 ( V_5 , V_24 -> V_25 . V_36 ) >> V_28 ;
V_17 . V_29 =
F_4 ( V_6 , V_24 -> V_25 . V_26 ) >> V_28 ;
V_17 . V_9 = V_30 | V_31 |
V_32 ;
}
break;
case V_37 :
V_11 = V_38 ;
V_17 . V_27 = V_5 >> V_28 ;
V_17 . V_29 = V_6 >> V_28 ;
V_17 . V_9 = V_39 | V_40 ;
break;
case V_41 :
V_9 = V_42 ;
V_11 = V_38 ;
V_17 . V_27 = V_5 >> V_28 ;
V_17 . V_29 = V_6 >> V_28 ;
V_17 . V_9 = V_30 | V_40 |
V_31 ;
break;
default:
return - V_18 ;
}
* V_7 = 0 ;
V_15 . V_15 = & V_17 ;
V_15 . V_43 = 1 ;
V_15 . V_44 = & V_17 ;
V_15 . V_45 = 1 ;
V_10 = F_5 ( V_24 , V_3 , V_46 ,
true , V_11 , V_9 ,
NULL , & V_15 , NULL ,
& V_13 ) ;
if ( V_10 ) {
F_6 ( L_1 , V_10 ) ;
return V_10 ;
}
* V_7 = ( T_2 ) V_13 ;
return V_10 ;
}
static int F_7 ( struct V_1 * V_1 , T_2 V_7 )
{
struct V_12 * V_13 = (struct V_12 * ) V_7 ;
if ( V_13 ) {
int V_47 = F_8 ( V_13 , true ) ;
if ( F_9 ( V_47 == 0 ) ) {
F_10 ( V_13 ) ;
F_11 ( V_13 ) ;
F_12 ( V_13 ) ;
}
F_13 ( & V_13 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , T_2 V_7 ,
T_1 * V_48 )
{
int V_47 ;
T_5 V_5 , V_6 ;
struct V_12 * V_13 = (struct V_12 * ) V_7 ;
F_15 ( V_13 -> V_15 . V_43 > 1 ) ;
V_5 = V_13 -> V_49 [ 0 ] . V_27 << V_28 ;
V_6 = V_13 -> V_49 [ 0 ] . V_29 << V_28 ;
V_47 = F_8 ( V_13 , true ) ;
if ( F_16 ( V_47 != 0 ) )
return V_47 ;
V_47 = F_17 ( V_13 , V_13 -> V_50 ,
V_5 , V_6 , V_48 ) ;
F_12 ( V_13 ) ;
return V_47 ;
}
static int F_18 ( struct V_1 * V_1 , T_2 V_7 )
{
int V_47 ;
struct V_12 * V_13 = (struct V_12 * ) V_7 ;
V_47 = F_8 ( V_13 , true ) ;
if ( F_16 ( V_47 != 0 ) )
return V_47 ;
V_47 = F_11 ( V_13 ) ;
F_12 ( V_13 ) ;
return V_47 ;
}
static int F_19 ( struct V_1 * V_1 , T_2 V_7 ,
void * * V_51 )
{
int V_47 ;
struct V_12 * V_13 = (struct V_12 * ) V_7 ;
V_47 = F_8 ( V_13 , true ) ;
if ( F_16 ( V_47 != 0 ) )
return V_47 ;
V_47 = F_20 ( V_13 , V_51 ) ;
F_12 ( V_13 ) ;
return V_47 ;
}
static int F_21 ( struct V_1 * V_1 , T_2 V_7 )
{
int V_47 ;
struct V_12 * V_13 = (struct V_12 * ) V_7 ;
V_47 = F_8 ( V_13 , true ) ;
if ( F_16 ( V_47 != 0 ) )
return V_47 ;
F_10 ( V_13 ) ;
F_12 ( V_13 ) ;
return V_47 ;
}
static T_4 F_22 ( struct V_1 * V_1 , unsigned V_52 )
{
V_8 ;
return F_23 ( V_52 ) ;
}
static void F_24 ( struct V_1 * V_1 , unsigned V_52 ,
T_4 V_53 )
{
V_8 ;
F_25 ( V_52 , V_53 ) ;
}
static T_4 F_26 ( struct V_1 * V_1 ,
enum V_54 V_55 ,
unsigned V_56 )
{
V_8 ;
switch ( V_55 ) {
case V_57 :
return F_27 ( V_56 ) ;
case V_58 :
return F_28 ( V_56 ) ;
case V_59 :
return F_29 ( V_56 ) ;
case V_60 :
return F_30 ( V_56 ) ;
case V_61 :
return F_31 ( V_56 ) ;
case V_62 :
return F_32 ( V_56 ) ;
case V_63 :
F_6 ( L_2 ) ;
return 0 ;
}
F_33 ( 1 , L_3 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_1 ,
enum V_54 V_55 ,
unsigned V_56 , T_4 V_53 )
{
V_8 ;
switch ( V_55 ) {
case V_57 :
return F_35 ( V_56 , V_53 ) ;
case V_58 :
return F_36 ( V_56 , V_53 ) ;
case V_59 :
return F_37 ( V_56 , V_53 ) ;
case V_60 :
return F_38 ( V_56 , V_53 ) ;
case V_61 :
return F_39 ( V_56 , V_53 ) ;
case V_62 :
return F_40 ( V_56 , V_53 ) ;
case V_63 :
F_6 ( L_2 ) ;
return;
}
F_33 ( 1 , L_3 ) ;
}
static int F_41 ( struct V_1 * V_1 ,
enum V_64 V_65 ,
T_1 V_3 ,
T_1 V_52 ,
T_1 * V_66 )
{
V_8 ;
if ( V_66 == NULL )
return - V_18 ;
switch ( V_65 ) {
case V_67 :
if ( V_24 -> V_68 == 0 )
return - V_69 ;
if ( ( V_52 + V_3 ) > V_24 -> V_68 )
return - V_18 ;
* V_66 = V_24 -> V_70 ;
return 0 ;
case V_71 :
if ( V_24 -> V_72 . V_3 == 0 )
return - V_69 ;
if ( ( V_52 + V_3 ) > V_24 -> V_72 . V_3 )
return - V_18 ;
* V_66 = V_24 -> V_72 . V_73 ;
return 0 ;
case V_74 :
case V_75 :
case V_76 :
default:
return - V_18 ;
}
}
static const void * F_42 ( struct V_1 * V_1 ,
unsigned V_77 , T_3 * V_3 ,
T_6 * V_78 , T_6 * V_79 )
{
V_8 ;
T_3 V_80 ;
if ( F_43 (
V_24 -> V_81 . V_82 , V_77 , V_3 ,
V_78 , V_79 , & V_80 ) )
return ( T_6 * ) V_24 -> V_81 . V_82 -> V_83 +
V_80 ;
return NULL ;
}
static int F_44 ( struct V_1 * V_1 , unsigned V_77 ,
T_6 * V_78 , T_6 * V_79 )
{
V_8 ;
if ( F_45 (
V_24 -> V_81 . V_82 , V_77 ,
V_78 , V_79 ) )
return 0 ;
return - V_18 ;
}
static int F_46 ( struct V_1 * V_1 , unsigned V_77 ,
void * args )
{
V_8 ;
return F_47 (
V_24 -> V_81 . V_82 , V_77 , args ) ;
}
static int F_48 ( struct V_84 * V_24 ,
struct V_85 * V_86 ,
unsigned type ,
enum V_87 V_88 )
{
struct V_89 * V_90 =
(struct V_89 * ) V_86 -> V_91 ;
if ( ! V_90 )
return - V_18 ;
if ( ! V_90 -> V_92 )
return - V_18 ;
return V_90 -> V_92 ( V_90 -> V_93 ,
V_90 -> V_94 ,
type ,
( int ) V_88 ) ;
}
static int F_49 ( struct V_84 * V_24 ,
struct V_85 * V_95 ,
struct V_96 * V_97 )
{
struct V_89 * V_90 =
(struct V_89 * ) V_95 -> V_91 ;
if ( ! V_90 )
return - V_18 ;
if ( ! V_90 -> V_98 )
return - V_18 ;
return V_90 -> V_98 ( V_90 -> V_93 ,
V_90 -> V_94 ,
V_97 -> V_99 ) ;
}
static int F_50 ( void * V_1 ,
unsigned V_100 ,
unsigned V_94 ,
unsigned V_101 ,
T_7 V_92 ,
T_8 V_98 ,
void * V_93 )
{
V_8 ;
int V_10 = 0 ;
struct V_89 * V_90 ;
struct V_85 * V_95 =
F_51 ( sizeof( struct V_85 ) , V_102 ) ;
if ( ! V_95 )
return - V_103 ;
V_90 =
F_51 ( sizeof( struct V_89 ) , V_102 ) ;
if ( ! V_90 ) {
F_52 ( V_95 ) ;
return - V_103 ;
}
V_95 -> V_101 = V_101 ;
V_95 -> V_104 = & V_105 ;
V_90 -> V_94 = V_94 ;
V_90 -> V_92 = V_92 ;
V_90 -> V_98 = V_98 ;
V_90 -> V_93 = V_93 ;
V_95 -> V_91 = ( void * ) V_90 ;
V_10 = F_53 ( V_24 , V_100 , V_94 , V_95 ) ;
if ( V_10 ) {
F_52 ( V_90 ) ;
F_52 ( V_95 ) ;
}
return V_10 ;
}
static int F_54 ( void * V_1 , unsigned V_100 ,
unsigned V_94 , unsigned type )
{
V_8 ;
if ( ! V_24 -> V_106 . V_107 [ V_100 ] . V_108 )
return - V_18 ;
return F_55 ( V_24 , V_24 -> V_106 . V_107 [ V_100 ] . V_108 [ V_94 ] , type ) ;
}
static int F_56 ( void * V_1 , unsigned V_100 ,
unsigned V_94 , unsigned type )
{
V_8 ;
if ( ! V_24 -> V_106 . V_107 [ V_100 ] . V_108 )
return - V_18 ;
return F_57 ( V_24 , V_24 -> V_106 . V_107 [ V_100 ] . V_108 [ V_94 ] , type ) ;
}
static int F_58 ( struct V_1 * V_1 ,
enum V_109 V_110 ,
enum V_111 V_88 )
{
V_8 ;
int V_112 , V_47 = - 1 ;
for ( V_112 = 0 ; V_112 < V_24 -> V_113 ; V_112 ++ ) {
if ( ! V_24 -> V_114 [ V_112 ] . V_115 . V_116 )
continue;
if ( V_24 -> V_114 [ V_112 ] . V_117 -> type == V_110 ) {
V_47 = V_24 -> V_114 [ V_112 ] . V_117 -> V_104 -> V_118 (
( void * ) V_24 ,
V_88 ) ;
break;
}
}
return V_47 ;
}
static int F_59 ( struct V_1 * V_1 ,
enum V_109 V_110 ,
enum V_119 V_88 )
{
V_8 ;
int V_112 , V_47 = - 1 ;
for ( V_112 = 0 ; V_112 < V_24 -> V_113 ; V_112 ++ ) {
if ( ! V_24 -> V_114 [ V_112 ] . V_115 . V_116 )
continue;
if ( V_24 -> V_114 [ V_112 ] . V_117 -> type == V_110 ) {
V_47 = V_24 -> V_114 [ V_112 ] . V_117 -> V_104 -> V_120 (
( void * ) V_24 ,
V_88 ) ;
break;
}
}
return V_47 ;
}
static T_4 F_60 ( struct V_1 * V_1 , T_4 V_121 )
{
V_8 ;
enum V_122 V_123 = V_124 ;
switch ( V_121 ) {
case V_125 :
V_123 = V_126 ;
break;
case V_127 :
V_123 = V_128 ;
break;
case V_129 :
V_123 = V_130 ;
break;
case V_131 :
V_123 = V_132 ;
break;
case V_133 :
V_123 = V_134 ;
break;
case V_135 :
case V_136 :
V_123 = V_137 ;
break;
case V_138 :
if ( V_24 -> V_139 >= V_140 )
V_123 = V_137 ;
else
V_123 = V_141 ;
break;
case V_142 :
V_123 = V_143 ;
break;
case V_144 :
V_123 = V_145 ;
break;
default:
F_6 ( L_4 ) ;
}
return V_123 ;
}
static int F_61 ( struct V_1 * V_1 , enum V_146 type )
{
V_8 ;
if ( ( V_147 == type ) || ( V_148 == type ) ) {
F_62 ( V_24 -> V_149 . V_150 ) ;
V_24 -> V_149 . V_150 = NULL ;
return 0 ;
}
return - V_18 ;
}
static T_3 F_63 ( struct V_1 * V_1 ,
enum V_146 type )
{
V_8 ;
T_3 V_151 = 0 ;
switch ( type ) {
case V_125 :
V_151 = V_24 -> V_152 . V_153 [ 0 ] . V_151 ;
break;
case V_127 :
V_151 = V_24 -> V_152 . V_153 [ 1 ] . V_151 ;
break;
case V_129 :
V_151 = V_24 -> V_154 . V_155 ;
break;
case V_131 :
V_151 = V_24 -> V_154 . V_156 ;
break;
case V_133 :
V_151 = V_24 -> V_154 . V_157 ;
break;
case V_135 :
V_151 = V_24 -> V_154 . V_158 ;
break;
case V_136 :
V_151 = V_24 -> V_154 . V_158 ;
break;
case V_138 :
V_151 = V_24 -> V_154 . V_158 ;
break;
case V_142 :
V_151 = V_24 -> V_154 . V_159 ;
break;
case V_144 :
break;
default:
F_6 ( L_5 , type ) ;
break;
}
return V_151 ;
}
static int F_64 ( struct V_1 * V_1 ,
bool V_160 )
{
V_8 ;
if ( V_24 -> V_154 . V_161 . V_104 -> V_162 == NULL ||
V_24 -> V_154 . V_161 . V_104 -> V_163 == NULL )
return 0 ;
if ( V_160 )
V_24 -> V_154 . V_161 . V_104 -> V_162 ( V_24 ) ;
else
V_24 -> V_154 . V_161 . V_104 -> V_163 ( V_24 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_1 ,
enum V_146 type ,
struct V_164 * V_165 )
{
V_8 ;
if ( ( V_147 != type ) && ( V_148 != type ) ) {
T_1 V_166 ;
T_4 V_167 ;
const struct V_168 * V_169 ;
enum V_122 V_170 ;
struct V_171 * V_172 ;
V_170 = F_60 ( V_1 , type ) ;
V_172 = & V_24 -> V_173 . V_172 [ V_170 ] ;
if ( V_172 -> V_150 == NULL )
return - V_18 ;
V_166 = V_172 -> V_174 ;
V_169 = ( const struct V_168 * ) V_172 -> V_150 -> V_91 ;
V_167 = F_66 ( V_169 -> V_169 . V_175 ) ;
if ( ( type == V_136 ) ||
( type == V_138 ) ) {
V_166 += F_67 ( F_66 ( V_169 -> V_169 . V_175 ) , V_46 ) ;
V_167 = F_66 ( V_169 -> V_176 ) << 2 ;
}
V_165 -> V_177 = V_172 -> V_178 ;
V_165 -> V_179 = V_167 ;
V_165 -> V_174 = V_166 ;
V_165 -> V_117 = ( T_3 ) F_66 ( V_169 -> V_169 . V_180 ) ;
if ( V_135 == type )
V_165 -> V_179 = ( V_169 -> V_181 ) << 2 ;
V_165 -> V_151 = F_63 ( V_1 , type ) ;
V_165 -> V_182 = ( T_3 ) F_66 ( V_169 -> V_183 ) ;
} else {
char V_184 [ 30 ] = { 0 } ;
int V_185 = 0 ;
T_4 V_186 ;
T_4 V_187 ;
const T_6 * V_86 ;
const struct V_188 * V_189 ;
const struct V_190 * V_169 ;
struct V_171 * V_172 = NULL ;
if ( ! V_24 -> V_149 . V_150 ) {
switch ( V_24 -> V_139 ) {
case V_140 :
if ( ( ( V_24 -> V_191 -> V_192 == 0x6900 ) && ( V_24 -> V_191 -> V_193 == 0x81 ) ) ||
( ( V_24 -> V_191 -> V_192 == 0x6900 ) && ( V_24 -> V_191 -> V_193 == 0x83 ) ) ||
( ( V_24 -> V_191 -> V_192 == 0x6907 ) && ( V_24 -> V_191 -> V_193 == 0x87 ) ) ) {
V_165 -> V_194 = true ;
strcpy ( V_184 , L_6 ) ;
} else
strcpy ( V_184 , L_7 ) ;
break;
case V_195 :
if ( ( ( V_24 -> V_191 -> V_192 == 0x6939 ) && ( V_24 -> V_191 -> V_193 == 0xf1 ) ) ||
( ( V_24 -> V_191 -> V_192 == 0x6938 ) && ( V_24 -> V_191 -> V_193 == 0xf1 ) ) ) {
V_165 -> V_194 = true ;
strcpy ( V_184 , L_8 ) ;
} else
strcpy ( V_184 , L_9 ) ;
break;
case V_196 :
strcpy ( V_184 , L_10 ) ;
break;
case V_197 :
if ( type == V_147 ) {
if ( ( ( V_24 -> V_191 -> V_192 == 0x67ef ) &&
( ( V_24 -> V_191 -> V_193 == 0xe0 ) ||
( V_24 -> V_191 -> V_193 == 0xe2 ) ||
( V_24 -> V_191 -> V_193 == 0xe5 ) ) ) ||
( ( V_24 -> V_191 -> V_192 == 0x67ff ) &&
( ( V_24 -> V_191 -> V_193 == 0xcf ) ||
( V_24 -> V_191 -> V_193 == 0xef ) ||
( V_24 -> V_191 -> V_193 == 0xff ) ) ) ) {
V_165 -> V_194 = true ;
strcpy ( V_184 , L_11 ) ;
} else
strcpy ( V_184 , L_12 ) ;
} else if ( type == V_148 ) {
strcpy ( V_184 , L_13 ) ;
}
break;
case V_198 :
if ( type == V_147 ) {
if ( ( V_24 -> V_191 -> V_192 == 0x67df ) &&
( ( V_24 -> V_191 -> V_193 == 0xe0 ) ||
( V_24 -> V_191 -> V_193 == 0xe3 ) ||
( V_24 -> V_191 -> V_193 == 0xe4 ) ||
( V_24 -> V_191 -> V_193 == 0xe5 ) ||
( V_24 -> V_191 -> V_193 == 0xe7 ) ||
( V_24 -> V_191 -> V_193 == 0xef ) ) ) {
V_165 -> V_194 = true ;
strcpy ( V_184 , L_14 ) ;
} else
strcpy ( V_184 , L_15 ) ;
} else if ( type == V_148 ) {
strcpy ( V_184 , L_16 ) ;
}
break;
case V_199 :
strcpy ( V_184 , L_17 ) ;
break;
case V_200 :
strcpy ( V_184 , L_18 ) ;
break;
default:
F_6 ( L_19 ) ;
return - V_18 ;
}
V_185 = F_68 ( & V_24 -> V_149 . V_150 , V_184 , V_24 -> V_201 ) ;
if ( V_185 ) {
F_6 ( L_20 ) ;
return V_185 ;
}
V_185 = F_69 ( V_24 -> V_149 . V_150 ) ;
if ( V_185 ) {
F_6 ( L_21 , V_184 ) ;
F_62 ( V_24 -> V_149 . V_150 ) ;
V_24 -> V_149 . V_150 = NULL ;
return V_185 ;
}
if ( V_24 -> V_173 . V_202 == V_203 ) {
V_172 = & V_24 -> V_173 . V_172 [ V_204 ] ;
V_172 -> V_205 = V_204 ;
V_172 -> V_150 = V_24 -> V_149 . V_150 ;
V_169 = ( const struct V_190 * ) V_172 -> V_150 -> V_91 ;
V_24 -> V_173 . V_206 +=
F_67 ( F_66 ( V_169 -> V_175 ) , V_46 ) ;
}
}
V_189 = ( const struct V_188 * ) V_24 -> V_149 . V_150 -> V_91 ;
F_70 ( & V_189 -> V_169 ) ;
V_24 -> V_149 . V_151 = F_66 ( V_189 -> V_169 . V_180 ) ;
V_186 = F_66 ( V_189 -> V_169 . V_175 ) ;
V_187 = F_66 ( V_189 -> V_207 ) ;
V_86 = ( const T_6 * ) ( V_24 -> V_149 . V_150 -> V_91 +
F_66 ( V_189 -> V_169 . V_208 ) ) ;
V_165 -> V_117 = V_24 -> V_149 . V_151 ;
V_165 -> V_179 = V_186 ;
V_165 -> V_187 = V_187 ;
V_165 -> V_177 = ( void * ) V_86 ;
}
return 0 ;
}
static int F_71 ( void * V_1 )
{
V_8 ;
return F_72 ( V_24 ) ;
}
static int F_73 ( struct V_1 * V_1 ,
struct V_209 * V_210 )
{
V_8 ;
if ( NULL == V_210 )
return - V_211 ;
if ( sizeof( struct V_209 ) != V_210 -> V_3 )
return - V_211 ;
switch ( V_210 -> V_212 ) {
case V_213 :
V_210 -> V_53 = V_24 -> V_191 -> V_214 | ( V_24 -> V_191 -> V_215 -> V_216 << 8 ) ;
break;
case V_217 :
V_210 -> V_53 = V_24 -> V_149 . V_218 ;
break;
case V_219 :
V_210 -> V_53 = V_24 -> V_149 . V_220 ;
break;
case V_221 :
V_210 -> V_53 = V_24 -> V_191 -> V_192 ;
break;
case V_222 :
V_210 -> V_53 = V_24 -> V_191 -> V_193 ;
break;
case V_223 :
V_210 -> V_53 = V_24 -> V_224 ;
break;
case V_225 :
V_210 -> V_53 = V_24 -> V_226 ;
break;
case V_227 :
V_210 -> V_53 = V_24 -> V_154 . V_228 . V_216 ;
break;
case V_229 :
V_210 -> V_53 = V_24 -> V_154 . V_230 . V_231 ;
break;
case V_232 :
V_210 -> V_53 = V_24 -> V_191 -> V_233 ;
break;
case V_234 :
V_210 -> V_53 = V_24 -> V_191 -> V_235 ;
break;
default:
return - V_211 ;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_1 ,
struct V_236 * V_165 )
{
V_8 ;
struct V_237 * V_237 ;
struct V_238 * V_239 = V_24 -> V_239 ;
struct V_240 * V_241 ;
T_4 V_242 , V_243 ;
struct V_244 * V_81 ;
if ( V_165 == NULL )
return - V_18 ;
V_81 = V_165 -> V_81 ;
if ( V_24 -> V_81 . V_245 && V_24 -> V_81 . V_246 ) {
F_75 (crtc,
&ddev->mode_config.crtc_list, head) {
V_237 = F_76 ( V_241 ) ;
if ( V_241 -> V_247 ) {
V_165 -> V_248 |= ( 1 << V_237 -> V_249 ) ;
V_165 -> V_250 ++ ;
}
if ( V_81 != NULL &&
V_241 -> V_247 && V_237 -> V_247 &&
V_237 -> V_251 . clock ) {
V_242 = ( V_237 -> V_251 . V_252 * 1000 ) /
V_237 -> V_251 . clock ;
V_243 = V_237 -> V_251 . V_253 -
V_237 -> V_251 . V_254 +
( V_237 -> V_255 * 2 ) ;
V_81 -> V_256 = V_243 * V_242 ;
V_81 -> V_257 = F_77 ( & V_237 -> V_251 ) ;
V_81 -> V_258 = V_24 -> clock . V_259 . V_260 ;
V_81 = NULL ;
}
}
}
return 0 ;
}
static int F_78 ( struct V_1 * V_1 , bool V_247 )
{
V_8 ;
V_24 -> V_149 . V_261 = V_247 ;
return 0 ;
}
static int F_79 ( struct V_1 * V_1 ,
struct V_262 * V_165 )
{
V_8 ;
T_9 V_7 ;
struct V_263 V_264 ;
struct V_265 V_266 = { V_267 , NULL } ;
union V_268 * V_269 , * V_13 ;
T_6 V_270 [ 5 ] = { '\0' } ;
struct V_271 * V_272 ;
T_4 V_112 , V_273 ;
T_10 V_115 ;
int V_123 ;
V_7 = F_80 ( & V_24 -> V_191 -> V_201 ) ;
if ( ! V_7 )
return - V_211 ;
memset ( & V_264 , 0 , sizeof( struct V_263 ) ) ;
if ( V_165 -> V_3 != sizeof( struct V_262 ) )
return - V_18 ;
V_264 . V_273 = V_165 -> V_274 ;
if ( V_165 -> V_274 > 0 ) {
if ( V_165 -> V_275 == NULL )
return - V_18 ;
V_272 = V_165 -> V_275 ;
for ( V_112 = 0 ; V_112 < V_165 -> V_274 ; V_112 ++ ) {
if ( ( ( V_272 -> type == V_276 ) ||
( V_272 -> type == V_277 ) ) &&
( V_272 -> V_278 == NULL ) )
return - V_18 ;
V_272 ++ ;
}
}
if ( V_165 -> V_279 > 0 ) {
if ( V_165 -> V_280 == NULL )
return - V_18 ;
V_272 = V_165 -> V_280 ;
for ( V_112 = 0 ; V_112 < V_165 -> V_279 ; V_112 ++ ) {
if ( ( ( V_272 -> type == V_276 ) ||
( V_272 -> type == V_277 ) )
&& ( V_272 -> V_278 == NULL ) )
return - V_18 ;
V_272 ++ ;
}
}
if ( ( V_165 -> V_281 & V_282 ) != 0 ) {
strncpy ( V_270 , ( char * ) & ( V_165 -> V_270 ) , sizeof( T_4 ) ) ;
V_270 [ 4 ] = '\0' ;
}
if ( V_264 . V_273 > 0 ) {
V_264 . V_278 = V_269 =
F_51 ( sizeof( union V_268 ) * V_264 . V_273 , V_102 ) ;
if ( V_269 == NULL )
return - V_18 ;
V_272 = V_165 -> V_275 ;
for ( V_112 = 0 ; V_112 < V_264 . V_273 ; V_112 ++ ) {
V_269 -> type = V_272 -> type ;
switch ( V_269 -> type ) {
case V_283 :
V_269 -> integer . V_53 = V_272 -> V_53 ;
break;
case V_276 :
V_269 -> string . V_284 = V_272 -> V_285 ;
V_269 -> string . V_278 = V_272 -> V_278 ;
break;
case V_277 :
V_269 -> V_286 . V_284 = V_272 -> V_285 ;
V_269 -> V_286 . V_278 = V_272 -> V_278 ;
break;
default:
break;
}
V_269 ++ ;
V_272 ++ ;
}
}
V_273 = V_165 -> V_279 ;
V_272 = V_165 -> V_280 ;
V_115 = F_81 ( V_7 , V_270 , & V_264 , & V_266 ) ;
if ( F_82 ( V_115 ) ) {
V_123 = - V_287 ;
goto V_288;
}
V_13 = V_266 . V_278 ;
if ( V_273 > 1 ) {
if ( ( V_13 -> type != V_289 ) ||
( V_13 -> V_290 . V_273 != V_273 ) ) {
V_123 = - V_287 ;
goto V_291;
}
V_269 = V_13 -> V_290 . V_292 ;
} else
V_269 = V_13 ;
if ( V_269 == NULL ) {
V_123 = - V_287 ;
goto V_291;
}
for ( V_112 = 0 ; V_112 < V_273 ; V_112 ++ ) {
if ( V_272 -> type != V_269 -> type ) {
V_123 = - V_287 ;
goto V_291;
}
switch ( V_269 -> type ) {
case V_283 :
V_272 -> V_53 = V_269 -> integer . V_53 ;
break;
case V_276 :
if ( ( V_269 -> string . V_284 != V_272 -> V_285 ) ||
( V_269 -> string . V_278 == NULL ) ) {
V_123 = - V_287 ;
goto V_291;
}
strncpy ( V_272 -> V_278 ,
V_269 -> string . V_278 ,
V_269 -> string . V_284 ) ;
break;
case V_277 :
if ( V_269 -> V_286 . V_278 == NULL ) {
V_123 = - V_287 ;
goto V_291;
}
memcpy ( V_272 -> V_278 ,
V_269 -> V_286 . V_278 ,
V_272 -> V_285 ) ;
break;
default:
break;
}
V_272 ++ ;
V_269 ++ ;
}
V_123 = 0 ;
V_291:
F_52 ( V_13 ) ;
V_288:
F_52 ( ( void * ) V_264 . V_278 ) ;
return V_123 ;
}
static int F_79 ( struct V_1 * V_1 ,
struct V_262 * V_165 )
{
return - V_287 ;
}
static int F_83 ( struct V_1 * V_1 ,
T_4 V_293 ,
T_4 V_294 ,
void * V_295 , void * V_296 ,
T_4 V_279 ,
T_4 V_297 ,
T_4 V_298 )
{
struct V_271 V_299 [ 2 ] = { { 0 } , { 0 } } ;
struct V_271 V_300 = { 0 } ;
struct V_262 V_165 = { 0 } ;
V_299 [ 0 ] . type = V_301 ;
V_299 [ 0 ] . V_285 = sizeof( T_4 ) ;
V_299 [ 0 ] . V_53 = V_294 ;
V_299 [ 1 ] . type = V_302 ;
V_299 [ 1 ] . V_285 = V_297 ;
V_299 [ 1 ] . V_278 = V_295 ;
V_300 . type = V_302 ;
V_300 . V_285 = V_298 ;
V_300 . V_278 = V_296 ;
V_165 . V_3 = sizeof( struct V_262 ) ;
V_165 . V_281 = V_282 | V_303 ;
V_165 . V_274 = 2 ;
V_165 . V_270 = V_293 ;
V_165 . V_275 = V_299 ;
V_165 . V_279 = V_279 ;
V_165 . V_280 = & V_300 ;
return F_79 ( V_1 , & V_165 ) ;
}
struct V_1 * F_84 ( struct V_84 * V_24 )
{
struct V_304 * V_1 =
F_85 ( sizeof( * V_1 ) , V_102 ) ;
if ( ! V_1 ) {
F_6 ( L_22 ) ;
return NULL ;
}
V_1 -> V_73 . V_305 = & V_306 ;
V_1 -> V_73 . V_307 = & V_308 ;
V_1 -> V_24 = V_24 ;
return (struct V_1 * ) V_1 ;
}
void F_86 ( struct V_1 * V_1 )
{
F_52 ( V_1 ) ;
}
