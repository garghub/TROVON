static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
struct V_13 * V_14 = & V_12 -> V_15 . V_16 ;
bool V_17 = V_14 -> V_16 & V_18 ;
T_1 V_19 = V_14 -> V_19 ;
switch ( V_14 -> V_20 ) {
case V_21 :
case V_22 :
V_4 -> V_23 = V_24 ;
V_4 -> V_25 = V_26 ;
break;
case V_27 :
V_4 -> V_23 = V_28 ;
V_4 -> V_25 = V_29 ;
break;
case V_30 :
V_4 -> V_23 = V_31 ;
V_4 -> V_25 = V_32 ;
break;
case V_33 :
V_4 -> V_23 = V_34 ;
V_4 -> V_25 = V_35 ;
break;
case V_36 :
V_4 -> V_23 = V_37 ;
V_4 -> V_25 = V_38 ;
break;
case V_39 :
V_4 -> V_23 = V_40 ;
V_4 -> V_25 = V_41 ;
break;
default:
if ( F_3 ( V_12 -> V_42 ) ) {
V_4 -> V_23 = V_31 ;
V_4 -> V_25 = V_32 ;
} else {
V_4 -> V_23 = V_43 ;
V_4 -> V_25 = V_44 ;
}
break;
}
V_4 -> V_23 |= V_45 ;
V_4 -> V_25 |= V_46 ;
V_4 -> V_47 = ( ( V_14 -> V_48 & V_49 ) ?
V_50 : V_51 ) ;
switch ( V_12 -> V_15 . V_52 ) {
case V_53 :
V_4 -> V_23 |= V_54 ;
V_4 -> V_25 |= V_55 ;
V_4 -> V_56 = V_57 ;
break;
case V_58 :
V_4 -> V_23 |= V_59 ;
V_4 -> V_25 |= V_60 ;
V_4 -> V_56 = V_61 ;
break;
case V_62 :
case V_63 :
V_4 -> V_23 |= V_64 ;
V_4 -> V_25 |= V_65 ;
V_4 -> V_56 = V_66 ;
break;
case V_67 :
V_4 -> V_23 |= V_64 ;
V_4 -> V_25 |= V_65 ;
V_4 -> V_56 = V_68 ;
break;
case V_69 :
default:
V_4 -> V_56 = V_70 ;
break;
}
V_4 -> V_71 = V_72 ;
if ( V_17 ) {
switch ( V_19 ) {
case V_73 :
F_4 ( V_4 , 40000 ) ;
break;
case V_74 :
F_4 ( V_4 , V_75 ) ;
break;
default:
break;
}
V_4 -> V_76 = V_77 ;
} else {
F_4 ( V_4 , V_78 ) ;
V_4 -> V_76 = V_79 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
struct V_13 * V_14 = & V_12 -> V_15 . V_16 ;
V_81 -> V_47 =
( ( V_14 -> V_48 & V_49 ) ?
V_50 : V_51 ) ;
if ( V_12 -> V_82 . V_83 == V_84 ) {
V_81 -> V_85 = 1 ;
} else if ( V_12 -> V_82 . V_83 == V_86 ) {
V_81 -> V_87 = 1 ;
} else if ( V_12 -> V_82 . V_83 == V_88 ) {
V_81 -> V_85 = 1 ;
V_81 -> V_87 = 1 ;
}
}
static T_1 F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
return V_8 -> V_89 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
if ( V_91 & V_90 )
V_8 -> V_12 . V_92 = V_90 ;
V_8 -> V_89 = V_90 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_93 = 0 ;
int V_94 ;
for ( V_94 = 0 ; V_95 [ V_94 ] . V_96 != 0 ; V_94 ++ )
V_93 += V_95 [ V_94 ] . V_97 ;
return V_93 * sizeof( T_1 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_98 * V_99 ,
void * V_100 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_1 * V_101 = V_100 ;
int V_94 , V_102 , V_103 ;
T_1 V_104 ;
V_99 -> V_105 = 1 ;
V_103 = 0 ;
for ( V_94 = 0 ; V_95 [ V_94 ] . V_96 != 0 ; V_94 ++ ) {
for ( V_102 = 0 ; V_102 < V_95 [ V_94 ] . V_97 ; V_102 ++ ) {
V_104 = V_95 [ V_94 ] . V_96
+ ( V_102 * V_95 [ V_94 ] . V_106 ) ;
V_101 [ V_103 ++ ] = F_10 ( V_12 , V_104 ) ;
}
}
}
static int F_11 ( struct V_1 * V_2 ,
struct V_107 * V_108 , T_2 * V_109 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_6 -> V_9 -> V_10 -> V_12 ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
int V_110 = 0 , V_111 ;
T_2 * V_112 ;
T_3 V_94 , V_113 ;
bool V_114 ;
#define F_12 4096
if ( V_108 -> V_111 == 0 )
return - V_115 ;
V_108 -> V_116 = V_12 -> V_117 | ( V_12 -> V_42 << 16 ) ;
V_112 = F_13 ( V_108 -> V_111 , V_118 ) ;
if ( ! V_112 )
return - V_119 ;
V_110 = F_14 ( V_12 , V_120 ) ;
if ( V_110 ) {
F_15 ( & V_8 -> V_121 -> V_122 ,
L_1 ,
V_110 , V_12 -> V_123 . V_124 ) ;
goto V_125;
}
V_113 = V_108 -> V_111 / F_12 ;
V_113 += ( V_108 -> V_111 % F_12 ) ? 1 : 0 ;
V_111 = F_12 ;
V_114 = false ;
for ( V_94 = 0 ; V_94 < V_113 ; V_94 ++ ) {
if ( V_94 == ( V_113 - 1 ) ) {
V_111 = V_108 -> V_111 - ( F_12 * V_94 ) ;
V_114 = true ;
}
V_110 = F_16 ( V_12 , 0x0 ,
V_108 -> V_96 + ( F_12 * V_94 ) ,
V_111 ,
V_112 + ( F_12 * V_94 ) ,
V_114 , NULL ) ;
if ( V_110 ) {
F_15 ( & V_8 -> V_121 -> V_122 ,
L_2 ,
V_110 , V_12 -> V_123 . V_124 ) ;
goto V_126;
}
}
V_126:
F_17 ( V_12 ) ;
memcpy ( V_109 , V_112 , V_108 -> V_111 ) ;
V_125:
F_18 ( V_112 ) ;
return V_110 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_6 -> V_9 -> V_10 -> V_12 ;
T_1 V_127 ;
V_127 = ( F_10 ( V_12 , V_128 )
& V_129 )
>> V_130 ;
V_127 = ( 64 * 1024 ) * ( 1 << V_127 ) ;
return V_127 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
F_21 ( V_132 -> V_134 , V_135 , sizeof( V_132 -> V_134 ) ) ;
F_21 ( V_132 -> V_105 , V_136 ,
sizeof( V_132 -> V_105 ) ) ;
F_21 ( V_132 -> V_137 , F_22 ( & V_8 -> V_12 ) ,
sizeof( V_132 -> V_137 ) ) ;
F_21 ( V_132 -> V_138 , F_23 ( V_8 -> V_121 ) ,
sizeof( V_132 -> V_138 ) ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_139 * V_140 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_133 * V_9 = V_8 -> V_9 [ V_8 -> V_141 ] ;
V_140 -> V_142 = V_143 ;
V_140 -> V_144 = V_143 ;
V_140 -> V_145 = 0 ;
V_140 -> V_146 = 0 ;
V_140 -> V_147 = V_9 -> V_148 [ 0 ] -> V_149 ;
V_140 -> V_150 = V_9 -> V_151 [ 0 ] -> V_149 ;
V_140 -> V_152 = 0 ;
V_140 -> V_153 = 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_139 * V_140 )
{
struct V_154 * V_151 = NULL , * V_148 = NULL ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
T_1 V_155 , V_156 ;
int V_94 , V_157 = 0 ;
if ( ( V_140 -> V_152 ) || ( V_140 -> V_153 ) )
return - V_115 ;
if ( V_140 -> V_150 > V_143 ||
V_140 -> V_150 < V_158 ||
V_140 -> V_147 > V_143 ||
V_140 -> V_147 < V_158 ) {
F_26 ( V_2 ,
L_3 ,
V_140 -> V_150 , V_140 -> V_147 ,
V_158 , V_143 ) ;
return - V_115 ;
}
V_156 = F_27 ( V_140 -> V_150 , V_159 ) ;
V_155 = F_27 ( V_140 -> V_147 , V_159 ) ;
if ( ( V_156 == V_9 -> V_151 [ 0 ] -> V_149 ) &&
( V_155 == V_9 -> V_148 [ 0 ] -> V_149 ) )
return 0 ;
while ( F_28 ( V_160 , & V_8 -> V_161 ) )
F_29 ( 1000 , 2000 ) ;
if ( ! F_30 ( V_9 -> V_2 ) ) {
for ( V_94 = 0 ; V_94 < V_9 -> V_162 ; V_94 ++ ) {
V_9 -> V_151 [ V_94 ] -> V_149 = V_156 ;
V_9 -> V_148 [ V_94 ] -> V_149 = V_155 ;
}
goto V_163;
}
if ( V_156 != V_9 -> V_151 [ 0 ] -> V_149 ) {
F_26 ( V_2 ,
L_4 ,
V_9 -> V_151 [ 0 ] -> V_149 , V_156 ) ;
V_151 = F_31 ( V_9 -> V_164 ,
sizeof( struct V_154 ) , V_118 ) ;
if ( ! V_151 ) {
V_157 = - V_119 ;
goto V_163;
}
for ( V_94 = 0 ; V_94 < V_9 -> V_162 ; V_94 ++ ) {
V_151 [ V_94 ] = * V_9 -> V_151 [ V_94 ] ;
V_151 [ V_94 ] . V_149 = V_156 ;
V_157 = F_32 ( & V_151 [ V_94 ] ) ;
if ( V_157 ) {
while ( V_94 ) {
V_94 -- ;
F_33 ( & V_151 [ V_94 ] ) ;
}
F_18 ( V_151 ) ;
V_151 = NULL ;
goto V_163;
}
}
}
if ( V_155 != V_9 -> V_148 [ 0 ] -> V_149 ) {
F_26 ( V_2 ,
L_5 ,
V_9 -> V_148 [ 0 ] -> V_149 , V_155 ) ;
V_148 = F_31 ( V_9 -> V_164 ,
sizeof( struct V_154 ) , V_118 ) ;
if ( ! V_148 ) {
V_157 = - V_119 ;
goto V_165;
}
for ( V_94 = 0 ; V_94 < V_9 -> V_162 ; V_94 ++ ) {
V_148 [ V_94 ] = * V_9 -> V_148 [ V_94 ] ;
V_148 [ V_94 ] . V_149 = V_155 ;
V_157 = F_34 ( & V_148 [ V_94 ] ) ;
if ( V_157 ) {
while ( V_94 ) {
V_94 -- ;
F_35 ( & V_148 [ V_94 ] ) ;
}
F_18 ( V_148 ) ;
V_148 = NULL ;
goto V_165;
}
}
}
F_36 ( V_9 ) ;
if ( V_151 ) {
for ( V_94 = 0 ; V_94 < V_9 -> V_162 ; V_94 ++ ) {
F_33 ( V_9 -> V_151 [ V_94 ] ) ;
* V_9 -> V_151 [ V_94 ] = V_151 [ V_94 ] ;
}
F_18 ( V_151 ) ;
V_151 = NULL ;
}
if ( V_148 ) {
for ( V_94 = 0 ; V_94 < V_9 -> V_162 ; V_94 ++ ) {
F_35 ( V_9 -> V_148 [ V_94 ] ) ;
* V_9 -> V_148 [ V_94 ] = V_148 [ V_94 ] ;
}
F_18 ( V_148 ) ;
V_148 = NULL ;
}
F_37 ( V_9 ) ;
V_165:
if ( V_151 ) {
for ( V_94 = 0 ; V_94 < V_9 -> V_162 ; V_94 ++ )
F_33 ( & V_151 [ V_94 ] ) ;
F_18 ( V_151 ) ;
V_151 = NULL ;
}
V_163:
F_38 ( V_160 , & V_8 -> V_161 ) ;
return V_157 ;
}
static int F_39 ( struct V_1 * V_2 , int V_166 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
switch ( V_166 ) {
case V_167 :
return V_168 ;
case V_169 :
if ( V_9 == V_8 -> V_9 [ V_8 -> V_141 ] ) {
int V_111 = F_40 ( V_2 ) ;
if ( V_8 -> V_170 != V_171 )
V_111 += V_172 ;
return V_111 ;
} else {
return F_41 ( V_2 ) ;
}
default:
return - V_173 ;
}
}
static void F_42 ( struct V_1 * V_2 ,
struct V_174 * V_175 , T_4 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_154 * V_176 , * V_177 ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_94 = 0 ;
char * V_100 ;
int V_102 ;
struct V_178 * V_179 = F_43 ( V_9 ) ;
unsigned int V_180 ;
F_44 ( V_9 ) ;
for ( V_102 = 0 ; V_102 < V_181 ; V_102 ++ ) {
V_100 = ( char * ) V_179 + V_182 [ V_102 ] . V_183 ;
V_90 [ V_94 ++ ] = ( V_182 [ V_102 ] . V_184 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_100 : * ( T_1 * ) V_100 ;
}
for ( V_102 = 0 ; V_102 < V_185 ; V_102 ++ ) {
V_100 = ( char * ) V_9 + V_186 [ V_102 ] . V_183 ;
V_90 [ V_94 ++ ] = ( V_186 [ V_102 ] . V_184 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_100 : * ( T_1 * ) V_100 ;
}
F_45 () ;
for ( V_102 = 0 ; V_102 < V_9 -> V_162 ; V_102 ++ ) {
V_176 = F_46 ( V_9 -> V_151 [ V_102 ] ) ;
if ( ! V_176 )
continue;
do {
V_180 = F_47 ( & V_176 -> V_187 ) ;
V_90 [ V_94 ] = V_176 -> V_175 . V_188 ;
V_90 [ V_94 + 1 ] = V_176 -> V_175 . V_109 ;
} while ( F_48 ( & V_176 -> V_187 , V_180 ) );
V_94 += 2 ;
V_177 = & V_176 [ 1 ] ;
do {
V_180 = F_47 ( & V_177 -> V_187 ) ;
V_90 [ V_94 ] = V_177 -> V_175 . V_188 ;
V_90 [ V_94 + 1 ] = V_177 -> V_175 . V_109 ;
} while ( F_48 ( & V_177 -> V_187 , V_180 ) );
V_94 += 2 ;
}
F_49 () ;
if ( V_9 != V_8 -> V_9 [ V_8 -> V_141 ] )
return;
if ( V_8 -> V_170 != V_171 ) {
struct V_189 * V_190 = V_8 -> V_190 [ V_8 -> V_170 ] ;
for ( V_102 = 0 ; V_102 < V_172 ; V_102 ++ ) {
V_100 = ( char * ) V_190 ;
V_100 += V_191 [ V_102 ] . V_183 ;
V_90 [ V_94 ++ ] = ( V_191 [ V_102 ] . V_184 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_100 : * ( T_1 * ) V_100 ;
}
}
for ( V_102 = 0 ; V_102 < V_192 ; V_102 ++ ) {
V_100 = ( char * ) V_8 + V_193 [ V_102 ] . V_183 ;
V_90 [ V_94 ++ ] = ( V_193 [ V_102 ] . V_184 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_100 : * ( T_1 * ) V_100 ;
}
for ( V_102 = 0 ; V_102 < V_194 ; V_102 ++ ) {
V_90 [ V_94 ++ ] = V_8 -> V_175 . V_195 [ V_102 ] ;
V_90 [ V_94 ++ ] = V_8 -> V_175 . V_196 [ V_102 ] ;
}
for ( V_102 = 0 ; V_102 < V_194 ; V_102 ++ ) {
V_90 [ V_94 ++ ] = V_8 -> V_175 . V_197 [ V_102 ] ;
V_90 [ V_94 ++ ] = V_8 -> V_175 . V_198 [ V_102 ] ;
}
for ( V_102 = 0 ; V_102 < V_194 ; V_102 ++ )
V_90 [ V_94 ++ ] = V_8 -> V_175 . V_199 [ V_102 ] ;
}
static void F_50 ( struct V_1 * V_2 , T_1 V_200 ,
T_2 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
char * V_100 = ( char * ) V_90 ;
int V_94 ;
switch ( V_200 ) {
case V_167 :
for ( V_94 = 0 ; V_94 < V_168 ; V_94 ++ ) {
memcpy ( V_90 , V_201 [ V_94 ] , V_202 ) ;
V_90 += V_202 ;
}
break;
case V_169 :
for ( V_94 = 0 ; V_94 < V_181 ; V_94 ++ ) {
snprintf ( V_100 , V_202 , L_6 ,
V_182 [ V_94 ] . V_203 ) ;
V_100 += V_202 ;
}
for ( V_94 = 0 ; V_94 < V_185 ; V_94 ++ ) {
snprintf ( V_100 , V_202 , L_6 ,
V_186 [ V_94 ] . V_203 ) ;
V_100 += V_202 ;
}
for ( V_94 = 0 ; V_94 < V_9 -> V_162 ; V_94 ++ ) {
snprintf ( V_100 , V_202 , L_7 , V_94 ) ;
V_100 += V_202 ;
snprintf ( V_100 , V_202 , L_8 , V_94 ) ;
V_100 += V_202 ;
snprintf ( V_100 , V_202 , L_9 , V_94 ) ;
V_100 += V_202 ;
snprintf ( V_100 , V_202 , L_10 , V_94 ) ;
V_100 += V_202 ;
}
if ( V_9 != V_8 -> V_9 [ V_8 -> V_141 ] )
return;
if ( V_8 -> V_170 != V_171 ) {
for ( V_94 = 0 ; V_94 < V_172 ; V_94 ++ ) {
snprintf ( V_100 , V_202 , L_11 ,
V_191 [ V_94 ] . V_203 ) ;
V_100 += V_202 ;
}
}
for ( V_94 = 0 ; V_94 < V_192 ; V_94 ++ ) {
snprintf ( V_100 , V_202 , L_12 ,
V_193 [ V_94 ] . V_203 ) ;
V_100 += V_202 ;
}
for ( V_94 = 0 ; V_94 < V_194 ; V_94 ++ ) {
snprintf ( V_100 , V_202 ,
L_13 , V_94 ) ;
V_100 += V_202 ;
snprintf ( V_100 , V_202 ,
L_14 , V_94 ) ;
V_100 += V_202 ;
}
for ( V_94 = 0 ; V_94 < V_194 ; V_94 ++ ) {
snprintf ( V_100 , V_202 ,
L_15 , V_94 ) ;
V_100 += V_202 ;
snprintf ( V_100 , V_202 ,
L_16 , V_94 ) ;
V_100 += V_202 ;
}
for ( V_94 = 0 ; V_94 < V_194 ; V_94 ++ ) {
snprintf ( V_100 , V_202 ,
L_17 , V_94 ) ;
V_100 += V_202 ;
}
break;
}
}
static int F_51 ( struct V_1 * V_122 ,
struct V_204 * V_205 )
{
struct V_7 * V_8 = F_52 ( V_122 ) ;
V_205 -> V_206 = V_207 |
V_208 |
V_209 |
V_210 |
V_211 |
V_212 ;
if ( V_8 -> V_213 )
V_205 -> V_214 = F_53 ( V_8 -> V_213 ) ;
else
V_205 -> V_214 = - 1 ;
V_205 -> V_215 = ( 1 << V_216 ) | ( 1 << V_217 ) ;
V_205 -> V_218 = ( 1 << V_219 ) |
( 1 << V_220 ) |
( 1 << V_221 ) |
( 1 << V_222 ) |
( 1 << V_223 ) |
( 1 << V_224 ) |
( 1 << V_225 ) |
( 1 << V_226 ) |
( 1 << V_227 ) |
( 1 << V_228 ) |
( 1 << V_229 ) |
( 1 << V_230 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , T_4 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_55 ( V_8 , V_12 , V_2 , L_18 ) ;
if ( F_56 ( & V_8 -> V_12 ) )
* V_90 = 0 ;
else
* V_90 = 1 ;
return * V_90 ;
}
static int F_57 ( struct V_1 * V_2 , T_4 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_55 ( V_8 , V_12 , V_2 , L_19 ) ;
* V_90 = F_58 ( & V_8 -> V_12 ) ;
return * V_90 ;
}
static int F_59 ( struct V_1 * V_2 , T_4 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_55 ( V_8 , V_12 , V_2 , L_20 ) ;
* V_90 = F_60 ( & V_8 -> V_12 ) ;
return * V_90 ;
}
static int F_61 ( struct V_1 * V_2 , T_4 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
T_3 V_231 = V_8 -> V_232 ;
F_55 ( V_8 , V_12 , V_2 , L_21 ) ;
F_62 ( & V_8 -> V_12 , V_233 ,
( V_234 |
V_235 ) ) ;
F_29 ( 1000 , 2000 ) ;
* V_90 = ( V_231 == V_8 -> V_232 ) ;
return * V_90 ;
}
static int F_63 ( struct V_1 * V_2 , T_4 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_55 ( V_8 , V_12 , V_2 , L_22 ) ;
* V_90 = 0 ;
return * V_90 ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_236 * V_237 , T_4 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
if ( V_237 -> V_238 == V_239 ) {
F_55 ( V_8 , V_240 , V_2 , L_23 ) ;
F_65 ( V_241 , & V_8 -> V_161 ) ;
if ( F_54 ( V_2 , & V_90 [ V_242 ] ) )
V_237 -> V_238 |= V_243 ;
if ( F_59 ( V_2 , & V_90 [ V_244 ] ) )
V_237 -> V_238 |= V_243 ;
if ( F_61 ( V_2 , & V_90 [ V_245 ] ) )
V_237 -> V_238 |= V_243 ;
if ( F_63 ( V_2 , & V_90 [ V_246 ] ) )
V_237 -> V_238 |= V_243 ;
if ( F_57 ( V_2 , & V_90 [ V_247 ] ) )
V_237 -> V_238 |= V_243 ;
F_38 ( V_241 , & V_8 -> V_161 ) ;
F_66 ( V_8 , ( 1 << V_248 ) ) ;
} else {
F_55 ( V_8 , V_240 , V_2 , L_24 ) ;
if ( F_54 ( V_2 , & V_90 [ V_242 ] ) )
V_237 -> V_238 |= V_243 ;
V_90 [ V_247 ] = 0 ;
V_90 [ V_244 ] = 0 ;
V_90 [ V_245 ] = 0 ;
V_90 [ V_246 ] = 0 ;
}
F_55 ( V_8 , V_240 , V_2 , L_25 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_249 * V_250 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_3 V_251 ;
F_68 ( V_12 , V_252 , & V_251 ) ;
if ( ( 1 << V_12 -> V_56 ) & V_251 ) {
V_250 -> V_23 = 0 ;
V_250 -> V_253 = 0 ;
} else {
V_250 -> V_23 = V_254 ;
V_250 -> V_253 = ( V_8 -> V_255 ? V_254 : 0 ) ;
}
}
static int F_69 ( struct V_1 * V_2 , struct V_249 * V_250 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_3 V_251 ;
F_68 ( V_12 , V_252 , & V_251 ) ;
if ( ( ( 1 << V_12 -> V_56 ) & V_251 ) )
return - V_173 ;
if ( V_250 -> V_253 && ( V_250 -> V_253 != V_254 ) )
return - V_173 ;
if ( V_8 -> V_255 != ! ! V_250 -> V_253 ) {
V_8 -> V_255 = ! ! V_250 -> V_253 ;
F_70 ( & V_8 -> V_121 -> V_122 , V_8 -> V_255 ) ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_5 V_256 = 0 ;
V_256 = F_72 ( V_12 , NULL ) ;
if ( V_256 ) {
F_26 ( V_2 , L_26 ,
V_8 -> V_12 . V_123 . V_124 ) ;
return - V_257 ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
enum V_258 V_161 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
int V_259 = 2 ;
switch ( V_161 ) {
case V_260 :
V_8 -> V_261 = F_74 ( V_12 ) ;
return V_259 ;
case V_262 :
F_75 ( V_12 , 0xF , false ) ;
break;
case V_263 :
F_75 ( V_12 , 0x0 , false ) ;
break;
case V_264 :
F_75 ( V_12 , V_8 -> V_261 , false ) ;
break;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_265 * V_266 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
V_266 -> V_267 = V_9 -> V_268 ;
V_266 -> V_269 = V_9 -> V_268 ;
if ( F_77 ( V_9 -> V_270 ) )
V_266 -> V_271 = 1 ;
if ( F_77 ( V_9 -> V_272 ) )
V_266 -> V_273 = 1 ;
V_266 -> V_274 = V_9 -> V_270 & ~ V_275 ;
V_266 -> V_276 = V_9 -> V_272 & ~ V_275 ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_265 * V_266 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_277 * V_278 ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_3 V_279 ;
int V_94 ;
if ( V_266 -> V_267 || V_266 -> V_269 )
V_9 -> V_268 = V_266 -> V_267 ;
if ( ( V_266 -> V_274 >= ( V_280 << 1 ) ) &&
( V_266 -> V_274 <= ( V_281 << 1 ) ) )
V_9 -> V_270 = V_266 -> V_274 ;
else
return - V_115 ;
if ( ( V_266 -> V_276 >= ( V_280 << 1 ) ) &&
( V_266 -> V_276 <= ( V_281 << 1 ) ) )
V_9 -> V_272 = V_266 -> V_276 ;
else
return - V_115 ;
if ( V_266 -> V_271 )
V_9 -> V_270 |= V_275 ;
else
V_9 -> V_270 &= ~ V_275 ;
if ( V_266 -> V_273 )
V_9 -> V_272 |= V_275 ;
else
V_9 -> V_272 &= ~ V_275 ;
V_279 = V_9 -> V_282 ;
for ( V_94 = 0 ; V_94 < V_9 -> V_283 ; V_94 ++ , V_279 ++ ) {
V_278 = V_9 -> V_284 [ V_94 ] ;
V_278 -> V_285 . V_286 = F_79 ( V_9 -> V_270 ) ;
F_62 ( V_12 , F_80 ( 0 , V_279 - 1 ) , V_278 -> V_285 . V_286 ) ;
V_278 -> V_287 . V_286 = F_79 ( V_9 -> V_272 ) ;
F_62 ( V_12 , F_80 ( 1 , V_279 - 1 ) , V_278 -> V_287 . V_286 ) ;
F_81 ( V_12 ) ;
}
return 0 ;
}
static int F_82 ( struct V_7 * V_8 , struct V_288 * V_289 )
{
V_289 -> V_90 = 0 ;
switch ( V_289 -> V_290 ) {
case V_291 :
case V_292 :
V_289 -> V_90 |= V_293 | V_294 ;
case V_295 :
case V_296 :
case V_297 :
case V_298 :
case V_299 :
V_289 -> V_90 |= V_300 | V_301 ;
break;
case V_302 :
case V_303 :
V_289 -> V_90 |= V_293 | V_294 ;
case V_304 :
case V_305 :
case V_306 :
case V_307 :
case V_308 :
V_289 -> V_90 |= V_300 | V_301 ;
break;
default:
return - V_115 ;
}
return 0 ;
}
static int F_83 ( struct V_7 * V_8 ,
struct V_288 * V_289 ,
T_1 * V_309 )
{
struct V_310 * V_311 ;
struct V_312 * V_313 ;
int V_314 = 0 ;
V_289 -> V_90 = F_84 ( V_8 ) ;
F_85 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_314 == V_289 -> V_315 )
return - V_316 ;
V_309 [ V_314 ] = V_311 -> V_317 ;
V_314 ++ ;
}
V_289 -> V_315 = V_314 ;
return 0 ;
}
static int F_86 ( struct V_7 * V_8 ,
struct V_288 * V_289 )
{
struct V_318 * V_319 =
(struct V_318 * ) & V_289 -> V_320 ;
struct V_310 * V_311 = NULL ;
struct V_312 * V_313 ;
F_85 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_319 -> V_321 <= V_311 -> V_317 )
break;
}
if ( ! V_311 || V_319 -> V_321 != V_311 -> V_317 )
return - V_115 ;
V_319 -> V_290 = V_311 -> V_290 ;
if ( V_319 -> V_290 == V_322 ) {
V_319 -> V_323 . V_324 . V_325 = V_326 ;
V_319 -> V_323 . V_324 . V_327 = 0 ;
V_319 -> V_328 . V_324 . V_327 = 0 ;
}
V_319 -> V_323 . V_329 . V_330 = V_311 -> V_331 ;
V_319 -> V_323 . V_329 . V_332 = V_311 -> V_333 ;
V_319 -> V_323 . V_329 . V_334 = V_311 -> V_335 [ 0 ] ;
V_319 -> V_323 . V_329 . V_336 = V_311 -> V_337 [ 0 ] ;
if ( V_311 -> V_338 == V_339 )
V_319 -> V_340 = V_341 ;
else
V_319 -> V_340 = V_311 -> V_342 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_288 * V_289 ,
T_1 * V_309 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_256 = - V_173 ;
switch ( V_289 -> V_289 ) {
case V_343 :
V_289 -> V_90 = V_9 -> V_164 ;
V_256 = 0 ;
break;
case V_344 :
V_256 = F_82 ( V_8 , V_289 ) ;
break;
case V_345 :
V_289 -> V_315 = V_8 -> V_346 ;
V_289 -> V_90 = F_84 ( V_8 ) ;
V_256 = 0 ;
break;
case V_347 :
V_256 = F_86 ( V_8 , V_289 ) ;
break;
case V_348 :
V_256 = F_83 ( V_8 , V_289 , V_309 ) ;
break;
default:
break;
}
return V_256 ;
}
static int F_88 ( struct V_7 * V_8 , struct V_288 * V_349 )
{
struct V_11 * V_12 = & V_8 -> V_12 ;
T_4 V_350 = ( T_4 ) F_10 ( V_12 , F_89 ( 0 ) ) |
( ( T_4 ) F_10 ( V_12 , F_89 ( 1 ) ) << 32 ) ;
if ( V_349 -> V_90 & ~ ( V_300 | V_301 |
V_293 | V_294 ) )
return - V_115 ;
if ( ! ( V_349 -> V_90 & V_300 ) ||
! ( V_349 -> V_90 & V_301 ) )
return - V_115 ;
switch ( V_349 -> V_290 ) {
case V_291 :
switch ( V_349 -> V_90 & ( V_293 | V_294 ) ) {
case 0 :
V_350 &= ~ ( ( T_4 ) 1 << V_351 ) ;
break;
case ( V_293 | V_294 ) :
V_350 |= ( ( T_4 ) 1 << V_351 ) ;
break;
default:
return - V_115 ;
}
break;
case V_302 :
switch ( V_349 -> V_90 & ( V_293 | V_294 ) ) {
case 0 :
V_350 &= ~ ( ( T_4 ) 1 << V_352 ) ;
break;
case ( V_293 | V_294 ) :
V_350 |= ( ( T_4 ) 1 << V_352 ) ;
break;
default:
return - V_115 ;
}
break;
case V_292 :
switch ( V_349 -> V_90 & ( V_293 | V_294 ) ) {
case 0 :
V_350 &= ~ ( ( ( T_4 ) 1 << V_353 ) |
( ( T_4 ) 1 << V_354 ) ) ;
break;
case ( V_293 | V_294 ) :
V_350 |= ( ( ( T_4 ) 1 << V_353 ) |
( ( T_4 ) 1 << V_354 ) ) ;
break;
default:
return - V_115 ;
}
break;
case V_303 :
switch ( V_349 -> V_90 & ( V_293 | V_294 ) ) {
case 0 :
V_350 &= ~ ( ( ( T_4 ) 1 << V_355 ) |
( ( T_4 ) 1 << V_356 ) ) ;
break;
case ( V_293 | V_294 ) :
V_350 |= ( ( ( T_4 ) 1 << V_355 ) |
( ( T_4 ) 1 << V_356 ) ) ;
break;
default:
return - V_115 ;
}
break;
case V_296 :
case V_297 :
case V_298 :
case V_295 :
if ( ( V_349 -> V_90 & V_293 ) ||
( V_349 -> V_90 & V_294 ) )
return - V_115 ;
V_350 |= ( ( T_4 ) 1 << V_357 ) ;
break;
case V_305 :
case V_306 :
case V_307 :
case V_304 :
if ( ( V_349 -> V_90 & V_293 ) ||
( V_349 -> V_90 & V_294 ) )
return - V_115 ;
V_350 |= ( ( T_4 ) 1 << V_358 ) ;
break;
case V_299 :
V_350 |= ( ( T_4 ) 1 << V_357 ) |
( ( T_4 ) 1 << V_354 ) ;
break;
case V_308 :
V_350 |= ( ( T_4 ) 1 << V_358 ) |
( ( T_4 ) 1 << V_356 ) ;
break;
default:
return - V_115 ;
}
F_62 ( V_12 , F_89 ( 0 ) , ( T_1 ) V_350 ) ;
F_62 ( V_12 , F_89 ( 1 ) , ( T_1 ) ( V_350 >> 32 ) ) ;
F_81 ( V_12 ) ;
return 0 ;
}
static bool F_90 ( struct V_310 * V_311 ,
struct V_310 * V_359 )
{
if ( ( V_311 -> V_335 [ 0 ] != V_359 -> V_335 [ 0 ] ) ||
( V_311 -> V_337 [ 0 ] != V_359 -> V_337 [ 0 ] ) ||
( V_311 -> V_331 != V_359 -> V_331 ) ||
( V_311 -> V_333 != V_359 -> V_333 ) )
return false ;
return true ;
}
static int F_91 ( struct V_133 * V_9 ,
struct V_310 * V_359 ,
T_3 V_360 ,
struct V_288 * V_289 )
{
struct V_310 * V_311 , * V_361 ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_312 * V_313 ;
int V_157 = - V_115 ;
V_361 = NULL ;
V_311 = NULL ;
F_85 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_311 -> V_317 >= V_360 )
break;
V_361 = V_311 ;
}
if ( V_311 && ( V_311 -> V_317 == V_360 ) ) {
if ( V_359 && ! F_90 ( V_311 , V_359 ) )
V_157 = F_92 ( V_9 , V_311 , false ) ;
else if ( ! V_359 )
V_157 = F_92 ( V_9 , V_311 , false ) ;
F_93 ( & V_311 -> V_362 ) ;
F_18 ( V_311 ) ;
V_8 -> V_346 -- ;
}
if ( ! V_359 )
return V_157 ;
F_94 ( & V_359 -> V_362 ) ;
if ( V_361 )
F_95 ( & V_361 -> V_362 , & V_359 -> V_362 ) ;
else
F_96 ( & V_359 -> V_362 ,
& V_8 -> V_363 ) ;
V_8 -> V_346 ++ ;
return 0 ;
}
static int F_97 ( struct V_133 * V_9 ,
struct V_288 * V_289 )
{
struct V_318 * V_319 =
(struct V_318 * ) & V_289 -> V_320 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_256 = 0 ;
V_256 = F_91 ( V_9 , NULL , V_319 -> V_321 , V_289 ) ;
F_98 ( V_8 ) ;
return V_256 ;
}
static int F_99 ( struct V_133 * V_9 ,
struct V_288 * V_289 )
{
struct V_318 * V_319 ;
struct V_310 * V_359 ;
struct V_7 * V_8 ;
int V_256 = - V_115 ;
if ( ! V_9 )
return - V_115 ;
V_8 = V_9 -> V_10 ;
if ( ! ( V_8 -> V_238 & V_364 ) )
return - V_173 ;
if ( V_8 -> V_365 & V_364 )
return - V_366 ;
V_319 = (struct V_318 * ) & V_289 -> V_320 ;
if ( V_319 -> V_321 >= ( V_8 -> V_12 . V_367 . V_368 +
V_8 -> V_12 . V_367 . V_369 ) ) {
return - V_115 ;
}
if ( ( V_319 -> V_340 != V_341 ) &&
( V_319 -> V_340 >= V_9 -> V_162 ) )
return - V_115 ;
V_359 = F_13 ( sizeof( * V_359 ) , V_118 ) ;
if ( ! V_359 )
return - V_119 ;
V_359 -> V_317 = V_319 -> V_321 ;
if ( V_319 -> V_340 == V_341 )
V_359 -> V_338 = V_339 ;
else
V_359 -> V_338 =
V_370 ;
V_359 -> V_342 = V_319 -> V_340 ;
V_359 -> V_371 = 0 ;
V_359 -> V_372 = 0 ;
V_359 -> V_373 = V_9 -> V_374 ;
V_359 -> V_375 = V_376 ;
V_359 -> V_377 = V_8 -> V_378 ;
V_359 -> V_290 = V_319 -> V_290 ;
V_359 -> V_379 = V_319 -> V_323 . V_324 . V_327 ;
V_359 -> V_331 = V_319 -> V_323 . V_329 . V_330 ;
V_359 -> V_333 = V_319 -> V_323 . V_329 . V_332 ;
V_359 -> V_335 [ 0 ] = V_319 -> V_323 . V_329 . V_334 ;
V_359 -> V_337 [ 0 ] = V_319 -> V_323 . V_329 . V_336 ;
V_256 = F_92 ( V_9 , V_359 , true ) ;
if ( V_256 )
F_18 ( V_359 ) ;
else
F_91 ( V_9 , V_359 , V_319 -> V_321 , NULL ) ;
return V_256 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_288 * V_289 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_256 = - V_173 ;
switch ( V_289 -> V_289 ) {
case V_380 :
V_256 = F_88 ( V_8 , V_289 ) ;
break;
case V_381 :
V_256 = F_99 ( V_9 , V_289 ) ;
break;
case V_382 :
V_256 = F_97 ( V_9 , V_289 ) ;
break;
default:
break;
}
return V_256 ;
}
static unsigned int F_101 ( struct V_133 * V_9 )
{
return V_9 -> V_164 ;
}
static void F_102 ( struct V_1 * V_122 ,
struct V_383 * V_384 )
{
struct V_5 * V_6 = F_2 ( V_122 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
V_384 -> V_385 = F_101 ( V_9 ) ;
V_384 -> V_386 = ( V_8 -> V_238 & V_364 ) ? 1 : 0 ;
V_384 -> V_387 = V_384 -> V_386 ;
V_384 -> V_388 = V_9 -> V_162 ;
}
static int F_103 ( struct V_1 * V_122 ,
struct V_383 * V_384 )
{
struct V_5 * V_6 = F_2 ( V_122 ) ;
unsigned int V_149 = V_384 -> V_388 ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_389 ;
if ( V_9 -> type != V_390 )
return - V_115 ;
if ( ! V_149 || V_384 -> V_391 || V_384 -> V_392 )
return - V_115 ;
if ( V_384 -> V_386 != ( ( V_8 -> V_238 & V_364 ) ? 1 : 0 ) )
return - V_115 ;
if ( V_149 > F_101 ( V_9 ) )
return - V_115 ;
if ( V_149 > V_8 -> V_393 )
V_149 = V_8 -> V_393 ;
V_389 = F_104 ( V_8 , V_149 ) ;
if ( V_389 > 0 )
return 0 ;
else
return - V_115 ;
}
void F_105 ( struct V_1 * V_2 )
{
V_2 -> V_394 = & V_395 ;
}
