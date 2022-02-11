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
0 , & V_13 ) ;
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
return F_33 ( V_56 ) ;
case V_64 :
F_6 ( L_2 ) ;
return 0 ;
}
F_34 ( 1 , L_3 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_1 ,
enum V_54 V_55 ,
unsigned V_56 , T_4 V_53 )
{
V_8 ;
switch ( V_55 ) {
case V_57 :
return F_36 ( V_56 , V_53 ) ;
case V_58 :
return F_37 ( V_56 , V_53 ) ;
case V_59 :
return F_38 ( V_56 , V_53 ) ;
case V_60 :
return F_39 ( V_56 , V_53 ) ;
case V_61 :
return F_40 ( V_56 , V_53 ) ;
case V_62 :
return F_41 ( V_56 , V_53 ) ;
case V_63 :
return F_42 ( V_56 , V_53 ) ;
case V_64 :
F_6 ( L_2 ) ;
return;
}
F_34 ( 1 , L_3 ) ;
}
static int F_43 ( struct V_1 * V_1 ,
enum V_65 V_66 ,
T_1 V_3 ,
T_1 V_52 ,
T_1 * V_67 )
{
V_8 ;
if ( V_67 == NULL )
return - V_18 ;
switch ( V_66 ) {
case V_68 :
if ( V_24 -> V_69 == 0 )
return - V_70 ;
if ( ( V_52 + V_3 ) > V_24 -> V_69 )
return - V_18 ;
* V_67 = V_24 -> V_71 ;
return 0 ;
case V_72 :
if ( V_24 -> V_73 . V_3 == 0 )
return - V_70 ;
if ( ( V_52 + V_3 ) > V_24 -> V_73 . V_3 )
return - V_18 ;
* V_67 = V_24 -> V_73 . V_74 ;
return 0 ;
case V_75 :
case V_76 :
case V_77 :
default:
return - V_18 ;
}
}
static const void * F_44 ( struct V_1 * V_1 ,
unsigned V_78 , T_3 * V_3 ,
T_6 * V_79 , T_6 * V_80 )
{
V_8 ;
T_3 V_81 ;
if ( F_45 (
V_24 -> V_82 . V_83 , V_78 , V_3 ,
V_79 , V_80 , & V_81 ) )
return ( T_6 * ) V_24 -> V_82 . V_83 -> V_84 +
V_81 ;
return NULL ;
}
static int F_46 ( struct V_1 * V_1 , unsigned V_78 ,
T_6 * V_79 , T_6 * V_80 )
{
V_8 ;
if ( F_47 (
V_24 -> V_82 . V_83 , V_78 ,
V_79 , V_80 ) )
return 0 ;
return - V_18 ;
}
static int F_48 ( struct V_1 * V_1 , unsigned V_78 ,
void * args )
{
V_8 ;
return F_49 (
V_24 -> V_82 . V_83 , V_78 , args ) ;
}
static int F_50 ( struct V_85 * V_24 ,
struct V_86 * V_87 ,
unsigned type ,
enum V_88 V_89 )
{
struct V_90 * V_91 =
(struct V_90 * ) V_87 -> V_92 ;
if ( ! V_91 )
return - V_18 ;
if ( ! V_91 -> V_93 )
return - V_18 ;
return V_91 -> V_93 ( V_91 -> V_94 ,
V_91 -> V_95 ,
type ,
( int ) V_89 ) ;
}
static int F_51 ( struct V_85 * V_24 ,
struct V_86 * V_96 ,
struct V_97 * V_98 )
{
struct V_90 * V_91 =
(struct V_90 * ) V_96 -> V_92 ;
if ( ! V_91 )
return - V_18 ;
if ( ! V_91 -> V_99 )
return - V_18 ;
return V_91 -> V_99 ( V_91 -> V_94 ,
V_91 -> V_95 ,
V_98 -> V_100 ) ;
}
static int F_52 ( void * V_1 ,
unsigned V_101 ,
unsigned V_95 ,
unsigned V_102 ,
T_7 V_93 ,
T_8 V_99 ,
void * V_94 )
{
V_8 ;
int V_10 = 0 ;
struct V_90 * V_91 ;
struct V_86 * V_96 =
F_53 ( sizeof( struct V_86 ) , V_103 ) ;
if ( ! V_96 )
return - V_104 ;
V_91 =
F_53 ( sizeof( struct V_90 ) , V_103 ) ;
if ( ! V_91 ) {
F_54 ( V_96 ) ;
return - V_104 ;
}
V_96 -> V_102 = V_102 ;
V_96 -> V_105 = & V_106 ;
V_91 -> V_95 = V_95 ;
V_91 -> V_93 = V_93 ;
V_91 -> V_99 = V_99 ;
V_91 -> V_94 = V_94 ;
V_96 -> V_92 = ( void * ) V_91 ;
V_10 = F_55 ( V_24 , V_101 , V_95 , V_96 ) ;
if ( V_10 ) {
F_54 ( V_91 ) ;
F_54 ( V_96 ) ;
}
return V_10 ;
}
static int F_56 ( void * V_1 , unsigned V_101 ,
unsigned V_95 , unsigned type )
{
V_8 ;
if ( ! V_24 -> V_107 . V_108 [ V_101 ] . V_109 )
return - V_18 ;
return F_57 ( V_24 , V_24 -> V_107 . V_108 [ V_101 ] . V_109 [ V_95 ] , type ) ;
}
static int F_58 ( void * V_1 , unsigned V_101 ,
unsigned V_95 , unsigned type )
{
V_8 ;
if ( ! V_24 -> V_107 . V_108 [ V_101 ] . V_109 )
return - V_18 ;
return F_59 ( V_24 , V_24 -> V_107 . V_108 [ V_101 ] . V_109 [ V_95 ] , type ) ;
}
static int F_60 ( struct V_1 * V_1 ,
enum V_110 V_111 ,
enum V_112 V_89 )
{
V_8 ;
int V_113 , V_47 = - 1 ;
for ( V_113 = 0 ; V_113 < V_24 -> V_114 ; V_113 ++ ) {
if ( ! V_24 -> V_115 [ V_113 ] . V_116 . V_117 )
continue;
if ( V_24 -> V_115 [ V_113 ] . V_118 -> type == V_111 ) {
V_47 = V_24 -> V_115 [ V_113 ] . V_118 -> V_105 -> V_119 (
( void * ) V_24 ,
V_89 ) ;
break;
}
}
return V_47 ;
}
static int F_61 ( struct V_1 * V_1 ,
enum V_110 V_111 ,
enum V_120 V_89 )
{
V_8 ;
int V_113 , V_47 = - 1 ;
for ( V_113 = 0 ; V_113 < V_24 -> V_114 ; V_113 ++ ) {
if ( ! V_24 -> V_115 [ V_113 ] . V_116 . V_117 )
continue;
if ( V_24 -> V_115 [ V_113 ] . V_118 -> type == V_111 ) {
V_47 = V_24 -> V_115 [ V_113 ] . V_118 -> V_105 -> V_121 (
( void * ) V_24 ,
V_89 ) ;
break;
}
}
return V_47 ;
}
static T_4 F_62 ( struct V_1 * V_1 , T_4 V_122 )
{
V_8 ;
enum V_123 V_124 = V_125 ;
switch ( V_122 ) {
case V_126 :
V_124 = V_127 ;
break;
case V_128 :
V_124 = V_129 ;
break;
case V_130 :
V_124 = V_131 ;
break;
case V_132 :
V_124 = V_133 ;
break;
case V_134 :
V_124 = V_135 ;
break;
case V_136 :
case V_137 :
V_124 = V_138 ;
break;
case V_139 :
if ( V_24 -> V_140 >= V_141 )
V_124 = V_138 ;
else
V_124 = V_142 ;
break;
case V_143 :
V_124 = V_144 ;
break;
case V_145 :
V_124 = V_146 ;
break;
default:
F_6 ( L_4 ) ;
}
return V_124 ;
}
static int F_63 ( struct V_1 * V_1 , enum V_147 type )
{
V_8 ;
if ( ( V_148 == type ) || ( V_149 == type ) ) {
F_64 ( V_24 -> V_150 . V_151 ) ;
V_24 -> V_150 . V_151 = NULL ;
return 0 ;
}
return - V_18 ;
}
static T_3 F_65 ( struct V_1 * V_1 ,
enum V_147 type )
{
V_8 ;
T_3 V_152 = 0 ;
switch ( type ) {
case V_126 :
V_152 = V_24 -> V_153 . V_154 [ 0 ] . V_152 ;
break;
case V_128 :
V_152 = V_24 -> V_153 . V_154 [ 1 ] . V_152 ;
break;
case V_130 :
V_152 = V_24 -> V_155 . V_156 ;
break;
case V_132 :
V_152 = V_24 -> V_155 . V_157 ;
break;
case V_134 :
V_152 = V_24 -> V_155 . V_158 ;
break;
case V_136 :
V_152 = V_24 -> V_155 . V_159 ;
break;
case V_137 :
V_152 = V_24 -> V_155 . V_159 ;
break;
case V_139 :
V_152 = V_24 -> V_155 . V_159 ;
break;
case V_143 :
V_152 = V_24 -> V_155 . V_160 ;
break;
case V_145 :
break;
default:
F_6 ( L_5 , type ) ;
break;
}
return V_152 ;
}
static int F_66 ( struct V_1 * V_1 ,
bool V_161 )
{
V_8 ;
if ( V_24 -> V_155 . V_162 . V_105 -> V_163 == NULL ||
V_24 -> V_155 . V_162 . V_105 -> V_164 == NULL )
return 0 ;
if ( V_161 )
V_24 -> V_155 . V_162 . V_105 -> V_163 ( V_24 ) ;
else
V_24 -> V_155 . V_162 . V_105 -> V_164 ( V_24 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_1 ,
bool V_165 )
{
V_8 ;
if ( V_165 )
F_68 ( & V_24 -> V_166 ) ;
else
F_69 ( & V_24 -> V_166 ) ;
}
static int F_70 ( struct V_1 * V_1 ,
enum V_147 type ,
struct V_167 * V_168 )
{
V_8 ;
if ( ( V_148 != type ) && ( V_149 != type ) ) {
T_1 V_169 ;
T_4 V_170 ;
const struct V_171 * V_172 ;
enum V_123 V_173 ;
struct V_174 * V_175 ;
V_173 = F_62 ( V_1 , type ) ;
V_175 = & V_24 -> V_176 . V_175 [ V_173 ] ;
if ( V_175 -> V_151 == NULL )
return - V_18 ;
V_169 = V_175 -> V_177 ;
V_172 = ( const struct V_171 * ) V_175 -> V_151 -> V_92 ;
V_170 = F_71 ( V_172 -> V_172 . V_178 ) ;
if ( ( type == V_137 ) ||
( type == V_139 ) ) {
V_169 += F_72 ( F_71 ( V_172 -> V_172 . V_178 ) , V_46 ) ;
V_170 = F_71 ( V_172 -> V_179 ) << 2 ;
}
V_168 -> V_180 = V_175 -> V_181 ;
V_168 -> V_182 = V_170 ;
V_168 -> V_177 = V_169 ;
V_168 -> V_118 = ( T_3 ) F_71 ( V_172 -> V_172 . V_183 ) ;
if ( V_136 == type )
V_168 -> V_182 = F_71 ( V_172 -> V_184 ) << 2 ;
V_168 -> V_152 = F_65 ( V_1 , type ) ;
V_168 -> V_185 = ( T_3 ) F_71 ( V_172 -> V_186 ) ;
} else {
char V_187 [ 30 ] = { 0 } ;
int V_188 = 0 ;
T_4 V_189 ;
T_4 V_190 ;
const T_6 * V_87 ;
const struct V_191 * V_192 ;
const struct V_193 * V_172 ;
struct V_174 * V_175 = NULL ;
if ( ! V_24 -> V_150 . V_151 ) {
switch ( V_24 -> V_140 ) {
case V_141 :
if ( ( ( V_24 -> V_194 -> V_195 == 0x6900 ) && ( V_24 -> V_194 -> V_196 == 0x81 ) ) ||
( ( V_24 -> V_194 -> V_195 == 0x6900 ) && ( V_24 -> V_194 -> V_196 == 0x83 ) ) ||
( ( V_24 -> V_194 -> V_195 == 0x6907 ) && ( V_24 -> V_194 -> V_196 == 0x87 ) ) ) {
V_168 -> V_197 = true ;
strcpy ( V_187 , L_6 ) ;
} else
strcpy ( V_187 , L_7 ) ;
break;
case V_198 :
if ( ( ( V_24 -> V_194 -> V_195 == 0x6939 ) && ( V_24 -> V_194 -> V_196 == 0xf1 ) ) ||
( ( V_24 -> V_194 -> V_195 == 0x6938 ) && ( V_24 -> V_194 -> V_196 == 0xf1 ) ) ) {
V_168 -> V_197 = true ;
strcpy ( V_187 , L_8 ) ;
} else
strcpy ( V_187 , L_9 ) ;
break;
case V_199 :
strcpy ( V_187 , L_10 ) ;
break;
case V_200 :
if ( type == V_148 ) {
if ( ( ( V_24 -> V_194 -> V_195 == 0x67ef ) &&
( ( V_24 -> V_194 -> V_196 == 0xe0 ) ||
( V_24 -> V_194 -> V_196 == 0xe2 ) ||
( V_24 -> V_194 -> V_196 == 0xe5 ) ) ) ||
( ( V_24 -> V_194 -> V_195 == 0x67ff ) &&
( ( V_24 -> V_194 -> V_196 == 0xcf ) ||
( V_24 -> V_194 -> V_196 == 0xef ) ||
( V_24 -> V_194 -> V_196 == 0xff ) ) ) ) {
V_168 -> V_197 = true ;
strcpy ( V_187 , L_11 ) ;
} else
strcpy ( V_187 , L_12 ) ;
} else if ( type == V_149 ) {
strcpy ( V_187 , L_13 ) ;
}
break;
case V_201 :
if ( type == V_148 ) {
if ( ( V_24 -> V_194 -> V_195 == 0x67df ) &&
( ( V_24 -> V_194 -> V_196 == 0xe0 ) ||
( V_24 -> V_194 -> V_196 == 0xe3 ) ||
( V_24 -> V_194 -> V_196 == 0xe4 ) ||
( V_24 -> V_194 -> V_196 == 0xe5 ) ||
( V_24 -> V_194 -> V_196 == 0xe7 ) ||
( V_24 -> V_194 -> V_196 == 0xef ) ) ) {
V_168 -> V_197 = true ;
strcpy ( V_187 , L_14 ) ;
} else
strcpy ( V_187 , L_15 ) ;
} else if ( type == V_149 ) {
strcpy ( V_187 , L_16 ) ;
}
break;
case V_202 :
strcpy ( V_187 , L_17 ) ;
break;
case V_203 :
if ( ( V_24 -> V_194 -> V_195 == 0x687f ) &&
( ( V_24 -> V_194 -> V_196 == 0xc0 ) ||
( V_24 -> V_194 -> V_196 == 0xc1 ) ||
( V_24 -> V_194 -> V_196 == 0xc3 ) ) )
strcpy ( V_187 , L_18 ) ;
else
strcpy ( V_187 , L_19 ) ;
break;
default:
F_6 ( L_20 ) ;
return - V_18 ;
}
V_188 = F_73 ( & V_24 -> V_150 . V_151 , V_187 , V_24 -> V_204 ) ;
if ( V_188 ) {
F_6 ( L_21 ) ;
return V_188 ;
}
V_188 = F_74 ( V_24 -> V_150 . V_151 ) ;
if ( V_188 ) {
F_6 ( L_22 , V_187 ) ;
F_64 ( V_24 -> V_150 . V_151 ) ;
V_24 -> V_150 . V_151 = NULL ;
return V_188 ;
}
if ( V_24 -> V_176 . V_205 == V_206 ) {
V_175 = & V_24 -> V_176 . V_175 [ V_207 ] ;
V_175 -> V_208 = V_207 ;
V_175 -> V_151 = V_24 -> V_150 . V_151 ;
V_172 = ( const struct V_193 * ) V_175 -> V_151 -> V_92 ;
V_24 -> V_176 . V_209 +=
F_72 ( F_71 ( V_172 -> V_178 ) , V_46 ) ;
}
}
V_192 = ( const struct V_191 * ) V_24 -> V_150 . V_151 -> V_92 ;
F_75 ( & V_192 -> V_172 ) ;
V_24 -> V_150 . V_152 = F_71 ( V_192 -> V_172 . V_183 ) ;
V_189 = F_71 ( V_192 -> V_172 . V_178 ) ;
V_190 = F_71 ( V_192 -> V_210 ) ;
V_87 = ( const T_6 * ) ( V_24 -> V_150 . V_151 -> V_92 +
F_71 ( V_192 -> V_172 . V_211 ) ) ;
V_168 -> V_118 = V_24 -> V_150 . V_152 ;
V_168 -> V_182 = V_189 ;
V_168 -> V_190 = V_190 ;
V_168 -> V_180 = ( void * ) V_87 ;
}
return 0 ;
}
static int F_76 ( void * V_1 )
{
V_8 ;
return F_77 ( V_24 ) ;
}
static int F_78 ( struct V_1 * V_1 ,
struct V_212 * V_213 )
{
V_8 ;
if ( NULL == V_213 )
return - V_214 ;
if ( sizeof( struct V_212 ) != V_213 -> V_3 )
return - V_214 ;
switch ( V_213 -> V_215 ) {
case V_216 :
V_213 -> V_53 = V_24 -> V_194 -> V_217 | ( V_24 -> V_194 -> V_218 -> V_219 << 8 ) ;
break;
case V_220 :
V_213 -> V_53 = V_24 -> V_150 . V_221 ;
break;
case V_222 :
V_213 -> V_53 = V_24 -> V_150 . V_223 ;
break;
case V_224 :
V_213 -> V_53 = V_24 -> V_194 -> V_195 ;
break;
case V_225 :
V_213 -> V_53 = V_24 -> V_194 -> V_196 ;
break;
case V_226 :
V_213 -> V_53 = V_24 -> V_227 ;
break;
case V_228 :
V_213 -> V_53 = V_24 -> V_229 ;
break;
case V_230 :
V_213 -> V_53 = V_24 -> V_155 . V_231 . V_219 ;
break;
case V_232 :
V_213 -> V_53 = V_24 -> V_155 . V_233 . V_234 ;
break;
case V_235 :
V_213 -> V_53 = V_24 -> V_194 -> V_236 ;
break;
case V_237 :
V_213 -> V_53 = V_24 -> V_194 -> V_238 ;
break;
default:
return - V_214 ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_1 ,
struct V_239 * V_168 )
{
V_8 ;
struct V_240 * V_240 ;
struct V_241 * V_242 = V_24 -> V_242 ;
struct V_243 * V_244 ;
T_4 V_245 , V_246 ;
struct V_247 * V_82 ;
if ( V_168 == NULL )
return - V_18 ;
V_82 = V_168 -> V_82 ;
if ( V_82 ) {
V_82 -> V_248 = 0xffffffff ;
V_82 -> V_249 = V_24 -> clock . V_250 . V_251 ;
}
if ( V_24 -> V_82 . V_252 && V_24 -> V_82 . V_253 ) {
F_80 (crtc,
&ddev->mode_config.crtc_list, head) {
V_240 = F_81 ( V_244 ) ;
if ( V_244 -> V_254 ) {
V_168 -> V_255 |= ( 1 << V_240 -> V_256 ) ;
V_168 -> V_257 ++ ;
}
if ( V_82 != NULL &&
V_244 -> V_254 && V_240 -> V_254 &&
V_240 -> V_258 . clock ) {
V_245 = ( V_240 -> V_258 . V_259 * 1000 ) /
V_240 -> V_258 . clock ;
V_246 = V_240 -> V_258 . V_260 -
V_240 -> V_258 . V_261 +
( V_240 -> V_262 * 2 ) ;
V_82 -> V_248 = V_246 * V_245 ;
V_82 -> V_263 = F_82 ( & V_240 -> V_258 ) ;
V_82 -> V_249 = V_24 -> clock . V_250 . V_251 ;
V_82 = NULL ;
}
}
}
return 0 ;
}
static int F_83 ( struct V_1 * V_1 , bool V_254 )
{
V_8 ;
V_24 -> V_150 . V_264 = V_254 ;
return 0 ;
}
static int F_84 ( struct V_1 * V_1 ,
struct V_265 * V_168 )
{
V_8 ;
T_9 V_7 ;
struct V_266 V_267 ;
struct V_268 V_269 = { V_270 , NULL } ;
union V_271 * V_272 , * V_13 ;
T_6 V_273 [ 5 ] = { '\0' } ;
struct V_274 * V_275 ;
T_4 V_113 , V_276 ;
T_10 V_116 ;
int V_124 ;
V_7 = F_85 ( & V_24 -> V_194 -> V_204 ) ;
if ( ! V_7 )
return - V_214 ;
memset ( & V_267 , 0 , sizeof( struct V_266 ) ) ;
if ( V_168 -> V_3 != sizeof( struct V_265 ) )
return - V_18 ;
V_267 . V_276 = V_168 -> V_277 ;
if ( V_168 -> V_277 > 0 ) {
if ( V_168 -> V_278 == NULL )
return - V_18 ;
V_275 = V_168 -> V_278 ;
for ( V_113 = 0 ; V_113 < V_168 -> V_277 ; V_113 ++ ) {
if ( ( ( V_275 -> type == V_279 ) ||
( V_275 -> type == V_280 ) ) &&
( V_275 -> V_281 == NULL ) )
return - V_18 ;
V_275 ++ ;
}
}
if ( V_168 -> V_282 > 0 ) {
if ( V_168 -> V_283 == NULL )
return - V_18 ;
V_275 = V_168 -> V_283 ;
for ( V_113 = 0 ; V_113 < V_168 -> V_282 ; V_113 ++ ) {
if ( ( ( V_275 -> type == V_279 ) ||
( V_275 -> type == V_280 ) )
&& ( V_275 -> V_281 == NULL ) )
return - V_18 ;
V_275 ++ ;
}
}
if ( ( V_168 -> V_284 & V_285 ) != 0 ) {
strncpy ( V_273 , ( char * ) & ( V_168 -> V_273 ) , sizeof( T_4 ) ) ;
V_273 [ 4 ] = '\0' ;
}
if ( V_267 . V_276 > 0 ) {
V_267 . V_281 = V_272 =
F_53 ( sizeof( union V_271 ) * V_267 . V_276 , V_103 ) ;
if ( V_272 == NULL )
return - V_18 ;
V_275 = V_168 -> V_278 ;
for ( V_113 = 0 ; V_113 < V_267 . V_276 ; V_113 ++ ) {
V_272 -> type = V_275 -> type ;
switch ( V_272 -> type ) {
case V_286 :
V_272 -> integer . V_53 = V_275 -> V_53 ;
break;
case V_279 :
V_272 -> string . V_287 = V_275 -> V_288 ;
V_272 -> string . V_281 = V_275 -> V_281 ;
break;
case V_280 :
V_272 -> V_289 . V_287 = V_275 -> V_288 ;
V_272 -> V_289 . V_281 = V_275 -> V_281 ;
break;
default:
break;
}
V_272 ++ ;
V_275 ++ ;
}
}
V_276 = V_168 -> V_282 ;
V_275 = V_168 -> V_283 ;
V_116 = F_86 ( V_7 , V_273 , & V_267 , & V_269 ) ;
if ( F_87 ( V_116 ) ) {
V_124 = - V_290 ;
goto V_291;
}
V_13 = V_269 . V_281 ;
if ( V_276 > 1 ) {
if ( ( V_13 -> type != V_292 ) ||
( V_13 -> V_293 . V_276 != V_276 ) ) {
V_124 = - V_290 ;
goto V_294;
}
V_272 = V_13 -> V_293 . V_295 ;
} else
V_272 = V_13 ;
if ( V_272 == NULL ) {
V_124 = - V_290 ;
goto V_294;
}
for ( V_113 = 0 ; V_113 < V_276 ; V_113 ++ ) {
if ( V_275 -> type != V_272 -> type ) {
V_124 = - V_290 ;
goto V_294;
}
switch ( V_272 -> type ) {
case V_286 :
V_275 -> V_53 = V_272 -> integer . V_53 ;
break;
case V_279 :
if ( ( V_272 -> string . V_287 != V_275 -> V_288 ) ||
( V_272 -> string . V_281 == NULL ) ) {
V_124 = - V_290 ;
goto V_294;
}
strncpy ( V_275 -> V_281 ,
V_272 -> string . V_281 ,
V_272 -> string . V_287 ) ;
break;
case V_280 :
if ( V_272 -> V_289 . V_281 == NULL ) {
V_124 = - V_290 ;
goto V_294;
}
memcpy ( V_275 -> V_281 ,
V_272 -> V_289 . V_281 ,
V_275 -> V_288 ) ;
break;
default:
break;
}
V_275 ++ ;
V_272 ++ ;
}
V_124 = 0 ;
V_294:
F_54 ( V_13 ) ;
V_291:
F_54 ( ( void * ) V_267 . V_281 ) ;
return V_124 ;
}
static int F_84 ( struct V_1 * V_1 ,
struct V_265 * V_168 )
{
return - V_290 ;
}
static int F_88 ( struct V_1 * V_1 ,
T_4 V_296 ,
T_4 V_297 ,
void * V_298 , void * V_299 ,
T_4 V_282 ,
T_4 V_300 ,
T_4 V_301 )
{
struct V_274 V_302 [ 2 ] = { { 0 } , { 0 } } ;
struct V_274 V_303 = { 0 } ;
struct V_265 V_168 = { 0 } ;
V_302 [ 0 ] . type = V_304 ;
V_302 [ 0 ] . V_288 = sizeof( T_4 ) ;
V_302 [ 0 ] . V_53 = V_297 ;
V_302 [ 1 ] . type = V_305 ;
V_302 [ 1 ] . V_288 = V_300 ;
V_302 [ 1 ] . V_281 = V_298 ;
V_303 . type = V_305 ;
V_303 . V_288 = V_301 ;
V_303 . V_281 = V_299 ;
V_168 . V_3 = sizeof( struct V_265 ) ;
V_168 . V_284 = V_285 | V_306 ;
V_168 . V_277 = 2 ;
V_168 . V_273 = V_296 ;
V_168 . V_278 = V_302 ;
V_168 . V_282 = V_282 ;
V_168 . V_283 = & V_303 ;
return F_84 ( V_1 , & V_168 ) ;
}
struct V_1 * F_89 ( struct V_85 * V_24 )
{
struct V_307 * V_1 =
F_90 ( sizeof( * V_1 ) , V_103 ) ;
if ( ! V_1 ) {
F_6 ( L_23 ) ;
return NULL ;
}
V_1 -> V_74 . V_308 = & V_309 ;
V_1 -> V_74 . V_310 = & V_311 ;
V_1 -> V_24 = V_24 ;
return (struct V_1 * ) V_1 ;
}
void F_91 ( struct V_1 * V_1 )
{
F_54 ( V_1 ) ;
}
