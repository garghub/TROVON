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
( T_2 * ) V_112 + ( F_12 * V_94 ) ,
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
memcpy ( V_109 , ( T_2 * ) V_112 , V_108 -> V_111 ) ;
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
if ( V_9 == V_8 -> V_9 [ V_8 -> V_141 ] )
return F_40 ( V_2 ) ;
else
return F_41 ( V_2 ) ;
default:
return - V_170 ;
}
}
static void F_42 ( struct V_1 * V_2 ,
struct V_171 * V_172 , T_4 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_94 = 0 ;
char * V_100 ;
int V_102 ;
struct V_173 * V_174 = F_43 ( V_9 ) ;
unsigned int V_175 ;
F_44 ( V_9 ) ;
for ( V_102 = 0 ; V_102 < V_176 ; V_102 ++ ) {
V_100 = ( char * ) V_174 + V_177 [ V_102 ] . V_178 ;
V_90 [ V_94 ++ ] = ( V_177 [ V_102 ] . V_179 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_100 : * ( T_1 * ) V_100 ;
}
F_45 () ;
for ( V_102 = 0 ; V_102 < V_9 -> V_162 ; V_102 ++ , V_94 += 4 ) {
struct V_154 * V_180 = F_46 ( V_9 -> V_151 [ V_102 ] ) ;
struct V_154 * V_181 ;
if ( ! V_180 )
continue;
do {
V_175 = F_47 ( & V_180 -> V_182 ) ;
V_90 [ V_94 ] = V_180 -> V_172 . V_183 ;
V_90 [ V_94 + 1 ] = V_180 -> V_172 . V_109 ;
} while ( F_48 ( & V_180 -> V_182 , V_175 ) );
V_181 = & V_180 [ 1 ] ;
do {
V_175 = F_47 ( & V_181 -> V_182 ) ;
V_90 [ V_94 + 2 ] = V_181 -> V_172 . V_183 ;
V_90 [ V_94 + 3 ] = V_181 -> V_172 . V_109 ;
} while ( F_48 ( & V_181 -> V_182 , V_175 ) );
}
F_49 () ;
if ( V_9 == V_8 -> V_9 [ V_8 -> V_141 ] ) {
for ( V_102 = 0 ; V_102 < V_184 ; V_102 ++ ) {
V_100 = ( char * ) V_8 + V_185 [ V_102 ] . V_178 ;
V_90 [ V_94 ++ ] = ( V_185 [ V_102 ] . V_179 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_100 : * ( T_1 * ) V_100 ;
}
for ( V_102 = 0 ; V_102 < V_186 ; V_102 ++ ) {
V_90 [ V_94 ++ ] = V_8 -> V_172 . V_187 [ V_102 ] ;
V_90 [ V_94 ++ ] = V_8 -> V_172 . V_188 [ V_102 ] ;
}
for ( V_102 = 0 ; V_102 < V_186 ; V_102 ++ ) {
V_90 [ V_94 ++ ] = V_8 -> V_172 . V_189 [ V_102 ] ;
V_90 [ V_94 ++ ] = V_8 -> V_172 . V_190 [ V_102 ] ;
}
for ( V_102 = 0 ; V_102 < V_186 ; V_102 ++ )
V_90 [ V_94 ++ ] = V_8 -> V_172 . V_191 [ V_102 ] ;
}
}
static void F_50 ( struct V_1 * V_2 , T_1 V_192 ,
T_2 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
char * V_100 = ( char * ) V_90 ;
int V_94 ;
switch ( V_192 ) {
case V_167 :
for ( V_94 = 0 ; V_94 < V_168 ; V_94 ++ ) {
memcpy ( V_90 , V_193 [ V_94 ] , V_194 ) ;
V_90 += V_194 ;
}
break;
case V_169 :
for ( V_94 = 0 ; V_94 < V_176 ; V_94 ++ ) {
snprintf ( V_100 , V_194 , L_6 ,
V_177 [ V_94 ] . V_195 ) ;
V_100 += V_194 ;
}
for ( V_94 = 0 ; V_94 < V_9 -> V_162 ; V_94 ++ ) {
snprintf ( V_100 , V_194 , L_7 , V_94 ) ;
V_100 += V_194 ;
snprintf ( V_100 , V_194 , L_8 , V_94 ) ;
V_100 += V_194 ;
snprintf ( V_100 , V_194 , L_9 , V_94 ) ;
V_100 += V_194 ;
snprintf ( V_100 , V_194 , L_10 , V_94 ) ;
V_100 += V_194 ;
}
if ( V_9 == V_8 -> V_9 [ V_8 -> V_141 ] ) {
for ( V_94 = 0 ; V_94 < V_184 ; V_94 ++ ) {
snprintf ( V_100 , V_194 , L_11 ,
V_185 [ V_94 ] . V_195 ) ;
V_100 += V_194 ;
}
for ( V_94 = 0 ; V_94 < V_186 ; V_94 ++ ) {
snprintf ( V_100 , V_194 ,
L_12 , V_94 ) ;
V_100 += V_194 ;
snprintf ( V_100 , V_194 ,
L_13 , V_94 ) ;
V_100 += V_194 ;
}
for ( V_94 = 0 ; V_94 < V_186 ; V_94 ++ ) {
snprintf ( V_100 , V_194 ,
L_14 , V_94 ) ;
V_100 += V_194 ;
snprintf ( V_100 , V_194 ,
L_15 , V_94 ) ;
V_100 += V_194 ;
}
for ( V_94 = 0 ; V_94 < V_186 ; V_94 ++ ) {
snprintf ( V_100 , V_194 ,
L_16 , V_94 ) ;
V_100 += V_194 ;
}
}
break;
}
}
static int F_51 ( struct V_1 * V_122 ,
struct V_196 * V_197 )
{
struct V_7 * V_8 = F_52 ( V_122 ) ;
V_197 -> V_198 = V_199 |
V_200 |
V_201 |
V_202 |
V_203 |
V_204 ;
if ( V_8 -> V_205 )
V_197 -> V_206 = F_53 ( V_8 -> V_205 ) ;
else
V_197 -> V_206 = - 1 ;
V_197 -> V_207 = ( 1 << V_208 ) | ( 1 << V_209 ) ;
V_197 -> V_210 = ( 1 << V_211 ) |
( 1 << V_212 ) |
( 1 << V_213 ) |
( 1 << V_214 ) |
( 1 << V_215 ) |
( 1 << V_216 ) |
( 1 << V_217 ) |
( 1 << V_218 ) |
( 1 << V_219 ) |
( 1 << V_220 ) |
( 1 << V_221 ) |
( 1 << V_222 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , T_4 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_55 ( V_8 , V_12 , V_2 , L_17 ) ;
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
F_55 ( V_8 , V_12 , V_2 , L_18 ) ;
* V_90 = F_58 ( & V_8 -> V_12 ) ;
return * V_90 ;
}
static int F_59 ( struct V_1 * V_2 , T_4 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_55 ( V_8 , V_12 , V_2 , L_19 ) ;
* V_90 = F_60 ( & V_8 -> V_12 ) ;
return * V_90 ;
}
static int F_61 ( struct V_1 * V_2 , T_4 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
T_3 V_223 = V_8 -> V_224 ;
F_55 ( V_8 , V_12 , V_2 , L_20 ) ;
F_62 ( & V_8 -> V_12 , V_225 ,
( V_226 |
V_227 ) ) ;
F_29 ( 1000 , 2000 ) ;
* V_90 = ( V_223 == V_8 -> V_224 ) ;
return * V_90 ;
}
static int F_63 ( struct V_1 * V_2 , T_4 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_55 ( V_8 , V_12 , V_2 , L_21 ) ;
* V_90 = 0 ;
return * V_90 ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_228 * V_229 , T_4 * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
if ( V_229 -> V_230 == V_231 ) {
F_55 ( V_8 , V_232 , V_2 , L_22 ) ;
F_65 ( V_233 , & V_8 -> V_161 ) ;
if ( F_54 ( V_2 , & V_90 [ V_234 ] ) )
V_229 -> V_230 |= V_235 ;
if ( F_59 ( V_2 , & V_90 [ V_236 ] ) )
V_229 -> V_230 |= V_235 ;
if ( F_61 ( V_2 , & V_90 [ V_237 ] ) )
V_229 -> V_230 |= V_235 ;
if ( F_63 ( V_2 , & V_90 [ V_238 ] ) )
V_229 -> V_230 |= V_235 ;
if ( F_57 ( V_2 , & V_90 [ V_239 ] ) )
V_229 -> V_230 |= V_235 ;
F_38 ( V_233 , & V_8 -> V_161 ) ;
F_66 ( V_8 , ( 1 << V_240 ) ) ;
} else {
F_55 ( V_8 , V_232 , V_2 , L_23 ) ;
if ( F_54 ( V_2 , & V_90 [ V_234 ] ) )
V_229 -> V_230 |= V_235 ;
V_90 [ V_239 ] = 0 ;
V_90 [ V_236 ] = 0 ;
V_90 [ V_237 ] = 0 ;
V_90 [ V_238 ] = 0 ;
}
F_55 ( V_8 , V_232 , V_2 , L_24 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_241 * V_242 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_3 V_243 ;
F_68 ( V_12 , V_244 , & V_243 ) ;
if ( ( 1 << V_12 -> V_56 ) & V_243 ) {
V_242 -> V_23 = 0 ;
V_242 -> V_245 = 0 ;
} else {
V_242 -> V_23 = V_246 ;
V_242 -> V_245 = ( V_8 -> V_247 ? V_246 : 0 ) ;
}
}
static int F_69 ( struct V_1 * V_2 , struct V_241 * V_242 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_3 V_243 ;
F_68 ( V_12 , V_244 , & V_243 ) ;
if ( ( ( 1 << V_12 -> V_56 ) & V_243 ) )
return - V_170 ;
if ( V_242 -> V_245 && ( V_242 -> V_245 != V_246 ) )
return - V_170 ;
if ( V_8 -> V_247 != ! ! V_242 -> V_245 ) {
V_8 -> V_247 = ! ! V_242 -> V_245 ;
F_70 ( & V_8 -> V_121 -> V_122 , V_8 -> V_247 ) ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_5 V_248 = 0 ;
V_248 = F_72 ( V_12 , NULL ) ;
if ( V_248 ) {
F_26 ( V_2 , L_25 ,
V_8 -> V_12 . V_123 . V_124 ) ;
return - V_249 ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
enum V_250 V_161 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
int V_251 = 2 ;
switch ( V_161 ) {
case V_252 :
V_8 -> V_253 = F_74 ( V_12 ) ;
return V_251 ;
case V_254 :
F_75 ( V_12 , 0xF , false ) ;
break;
case V_255 :
F_75 ( V_12 , 0x0 , false ) ;
break;
case V_256 :
F_75 ( V_12 , V_8 -> V_253 , false ) ;
break;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_257 * V_258 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
V_258 -> V_259 = V_9 -> V_260 ;
V_258 -> V_261 = V_9 -> V_260 ;
if ( F_77 ( V_9 -> V_262 ) )
V_258 -> V_263 = 1 ;
else
V_258 -> V_263 = V_9 -> V_262 ;
if ( F_77 ( V_9 -> V_264 ) )
V_258 -> V_265 = 1 ;
else
V_258 -> V_265 = V_9 -> V_264 ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_257 * V_258 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_266 * V_267 ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_3 V_268 ;
int V_94 ;
if ( V_258 -> V_259 || V_258 -> V_261 )
V_9 -> V_260 = V_258 -> V_259 ;
switch ( V_258 -> V_263 ) {
case 0 :
V_9 -> V_262 = 0 ;
break;
case 1 :
V_9 -> V_262 = ( V_269 |
F_79 ( V_270 ) ) ;
break;
default:
if ( ( V_258 -> V_263 < ( V_271 << 1 ) ) ||
( V_258 -> V_263 > ( V_272 << 1 ) ) )
return - V_115 ;
V_9 -> V_262 = V_258 -> V_263 ;
break;
}
switch ( V_258 -> V_265 ) {
case 0 :
V_9 -> V_264 = 0 ;
break;
case 1 :
V_9 -> V_264 = ( V_269 |
F_79 ( V_273 ) ) ;
break;
default:
if ( ( V_258 -> V_265 < ( V_271 << 1 ) ) ||
( V_258 -> V_265 > ( V_272 << 1 ) ) )
return - V_115 ;
V_9 -> V_264 = V_258 -> V_265 ;
break;
}
V_268 = V_9 -> V_274 ;
for ( V_94 = 0 ; V_94 < V_9 -> V_275 ; V_94 ++ , V_268 ++ ) {
V_267 = V_9 -> V_276 [ V_94 ] ;
V_267 -> V_277 . V_278 = F_80 ( V_9 -> V_262 ) ;
F_62 ( V_12 , F_81 ( 0 , V_268 - 1 ) , V_267 -> V_277 . V_278 ) ;
V_267 -> V_279 . V_278 = F_80 ( V_9 -> V_264 ) ;
F_62 ( V_12 , F_81 ( 1 , V_268 - 1 ) , V_267 -> V_279 . V_278 ) ;
F_82 ( V_12 ) ;
}
return 0 ;
}
static int F_83 ( struct V_7 * V_8 , struct V_280 * V_281 )
{
V_281 -> V_90 = 0 ;
switch ( V_281 -> V_282 ) {
case V_283 :
case V_284 :
V_281 -> V_90 |= V_285 | V_286 ;
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
V_281 -> V_90 |= V_292 | V_293 ;
break;
case V_294 :
case V_295 :
V_281 -> V_90 |= V_285 | V_286 ;
case V_296 :
case V_297 :
case V_298 :
case V_299 :
case V_300 :
V_281 -> V_90 |= V_292 | V_293 ;
break;
default:
return - V_115 ;
}
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_280 * V_281 ,
T_1 * V_301 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_248 = - V_170 ;
switch ( V_281 -> V_281 ) {
case V_302 :
V_281 -> V_90 = V_9 -> V_164 ;
V_248 = 0 ;
break;
case V_303 :
V_248 = F_83 ( V_8 , V_281 ) ;
break;
case V_304 :
V_281 -> V_305 = 10 ;
V_248 = 0 ;
break;
case V_306 :
V_248 = 0 ;
break;
case V_307 :
V_281 -> V_90 = 500 ;
V_248 = 0 ;
default:
break;
}
return V_248 ;
}
static int F_85 ( struct V_7 * V_8 , struct V_280 * V_308 )
{
struct V_11 * V_12 = & V_8 -> V_12 ;
T_4 V_309 = ( T_4 ) F_10 ( V_12 , F_86 ( 0 ) ) |
( ( T_4 ) F_10 ( V_12 , F_86 ( 1 ) ) << 32 ) ;
if ( V_308 -> V_90 & ~ ( V_292 | V_293 |
V_285 | V_286 ) )
return - V_115 ;
if ( ! ( V_308 -> V_90 & V_292 ) ||
! ( V_308 -> V_90 & V_293 ) )
return - V_115 ;
switch ( V_308 -> V_282 ) {
case V_283 :
switch ( V_308 -> V_90 & ( V_285 | V_286 ) ) {
case 0 :
V_309 &= ~ ( ( T_4 ) 1 << V_310 ) ;
break;
case ( V_285 | V_286 ) :
V_309 |= ( ( T_4 ) 1 << V_310 ) ;
break;
default:
return - V_115 ;
}
break;
case V_294 :
switch ( V_308 -> V_90 & ( V_285 | V_286 ) ) {
case 0 :
V_309 &= ~ ( ( T_4 ) 1 << V_311 ) ;
break;
case ( V_285 | V_286 ) :
V_309 |= ( ( T_4 ) 1 << V_311 ) ;
break;
default:
return - V_115 ;
}
break;
case V_284 :
switch ( V_308 -> V_90 & ( V_285 | V_286 ) ) {
case 0 :
V_309 &=
~ ( ( ( T_4 ) 1 << V_312 ) |
( ( T_4 ) 1 << V_313 ) |
( ( T_4 ) 1 << V_314 ) ) ;
break;
case ( V_285 | V_286 ) :
V_309 |=
( ( ( T_4 ) 1 << V_312 ) |
( ( T_4 ) 1 << V_313 ) |
( ( T_4 ) 1 << V_314 ) ) ;
break;
default:
return - V_115 ;
}
break;
case V_295 :
switch ( V_308 -> V_90 & ( V_285 | V_286 ) ) {
case 0 :
V_309 &=
~ ( ( ( T_4 ) 1 << V_315 ) |
( ( T_4 ) 1 << V_316 ) |
( ( T_4 ) 1 << V_317 ) ) ;
break;
case ( V_285 | V_286 ) :
V_309 |=
( ( ( T_4 ) 1 << V_315 ) |
( ( T_4 ) 1 << V_316 ) |
( ( T_4 ) 1 << V_317 ) ) ;
break;
default:
return - V_115 ;
}
break;
case V_288 :
case V_289 :
case V_290 :
case V_287 :
if ( ( V_308 -> V_90 & V_285 ) ||
( V_308 -> V_90 & V_286 ) )
return - V_115 ;
V_309 |= ( ( T_4 ) 1 << V_318 ) ;
break;
case V_297 :
case V_298 :
case V_299 :
case V_296 :
if ( ( V_308 -> V_90 & V_285 ) ||
( V_308 -> V_90 & V_286 ) )
return - V_115 ;
V_309 |= ( ( T_4 ) 1 << V_319 ) ;
break;
case V_291 :
V_309 |= ( ( T_4 ) 1 << V_318 ) |
( ( T_4 ) 1 << V_314 ) ;
break;
case V_300 :
V_309 |= ( ( T_4 ) 1 << V_319 ) |
( ( T_4 ) 1 << V_317 ) ;
break;
default:
return - V_115 ;
}
F_62 ( V_12 , F_86 ( 0 ) , ( T_1 ) V_309 ) ;
F_62 ( V_12 , F_86 ( 1 ) , ( T_1 ) ( V_309 >> 32 ) ) ;
F_82 ( V_12 ) ;
return 0 ;
}
static int F_87 ( struct V_133 * V_9 ,
struct V_320 * V_321 ,
struct V_322 * V_323 , bool V_324 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_325 * V_326 ;
struct V_327 * V_328 ;
bool V_157 = false ;
int V_248 ;
int V_94 ;
char V_329 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0x08 , 0 ,
0x45 , 0 , 0 , 0x1c , 0 , 0 , 0x40 , 0 , 0x40 , 0x11 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_321 -> V_330 , V_329 , V_331 ) ;
V_328 = (struct V_327 * ) ( V_321 -> V_330 + V_332 ) ;
V_326 = (struct V_325 * ) ( V_321 -> V_330 + V_332
+ sizeof( struct V_327 ) ) ;
V_328 -> V_333 = V_323 -> V_334 . V_335 . V_336 ;
V_328 -> V_337 = V_323 -> V_334 . V_335 . V_338 ;
V_326 -> V_339 = V_323 -> V_334 . V_335 . V_340 ;
V_326 -> V_341 = V_323 -> V_334 . V_335 . V_342 ;
for ( V_94 = V_312 ;
V_94 <= V_343 ; V_94 ++ ) {
V_321 -> V_344 = V_94 ;
V_248 = F_88 ( V_321 , V_8 , V_324 ) ;
if ( V_248 ) {
F_15 ( & V_8 -> V_121 -> V_122 ,
L_26 ,
V_321 -> V_344 , V_248 ) ;
V_157 = true ;
} else {
F_15 ( & V_8 -> V_121 -> V_122 ,
L_27 ,
V_321 -> V_344 , V_248 ) ;
}
}
return V_157 ? - V_170 : 0 ;
}
static int F_89 ( struct V_133 * V_9 ,
struct V_320 * V_321 ,
struct V_322 * V_323 , bool V_324 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_345 * V_346 ;
struct V_327 * V_328 ;
bool V_157 = false ;
int V_248 ;
char V_329 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0x08 , 0 ,
0x45 , 0 , 0 , 0x28 , 0 , 0 , 0x40 , 0 , 0x40 , 0x6 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0x80 , 0x11 , 0x0 , 0x72 , 0 , 0 , 0 , 0 } ;
memcpy ( V_321 -> V_330 , V_329 , V_347 ) ;
V_328 = (struct V_327 * ) ( V_321 -> V_330 + V_332 ) ;
V_346 = (struct V_345 * ) ( V_321 -> V_330 + V_332
+ sizeof( struct V_327 ) ) ;
V_328 -> V_337 = V_323 -> V_334 . V_335 . V_338 ;
V_346 -> V_341 = V_323 -> V_334 . V_335 . V_342 ;
V_328 -> V_333 = V_323 -> V_334 . V_335 . V_336 ;
V_346 -> V_339 = V_323 -> V_334 . V_335 . V_340 ;
if ( V_324 ) {
if ( V_8 -> V_230 & V_348 ) {
F_15 ( & V_8 -> V_121 -> V_122 , L_28 ) ;
V_8 -> V_230 &= ~ V_348 ;
}
}
V_321 -> V_344 = V_349 ;
V_248 = F_88 ( V_321 , V_8 , V_324 ) ;
if ( V_248 ) {
F_15 ( & V_8 -> V_121 -> V_122 ,
L_26 ,
V_321 -> V_344 , V_248 ) ;
V_157 = true ;
} else {
F_15 ( & V_8 -> V_121 -> V_122 , L_27 ,
V_321 -> V_344 , V_248 ) ;
}
V_321 -> V_344 = V_310 ;
V_248 = F_88 ( V_321 , V_8 , V_324 ) ;
if ( V_248 ) {
F_15 ( & V_8 -> V_121 -> V_122 ,
L_26 ,
V_321 -> V_344 , V_248 ) ;
V_157 = true ;
} else {
F_15 ( & V_8 -> V_121 -> V_122 , L_27 ,
V_321 -> V_344 , V_248 ) ;
}
return V_157 ? - V_170 : 0 ;
}
static int F_90 ( struct V_133 * V_9 ,
struct V_320 * V_321 ,
struct V_322 * V_323 , bool V_324 )
{
return - V_170 ;
}
static int F_91 ( struct V_133 * V_9 ,
struct V_320 * V_321 ,
struct V_322 * V_323 , bool V_324 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_327 * V_328 ;
bool V_157 = false ;
int V_248 ;
int V_94 ;
char V_329 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0x08 , 0 ,
0x45 , 0 , 0 , 0x14 , 0 , 0 , 0x40 , 0 , 0x40 , 0x10 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_321 -> V_330 , V_329 , V_350 ) ;
V_328 = (struct V_327 * ) ( V_321 -> V_330 + V_332 ) ;
V_328 -> V_333 = V_323 -> V_334 . V_351 . V_336 ;
V_328 -> V_337 = V_323 -> V_334 . V_351 . V_338 ;
V_328 -> V_352 = V_323 -> V_334 . V_351 . V_353 ;
for ( V_94 = V_318 ;
V_94 <= V_314 ; V_94 ++ ) {
V_321 -> V_344 = V_94 ;
V_248 = F_88 ( V_321 , V_8 , V_324 ) ;
if ( V_248 ) {
F_15 ( & V_8 -> V_121 -> V_122 ,
L_26 ,
V_321 -> V_344 , V_248 ) ;
V_157 = true ;
} else {
F_15 ( & V_8 -> V_121 -> V_122 ,
L_27 ,
V_321 -> V_344 , V_248 ) ;
}
}
return V_157 ? - V_170 : 0 ;
}
static int F_92 ( struct V_133 * V_9 ,
struct V_280 * V_281 , bool V_324 )
{
struct V_320 V_321 ;
int V_248 = - V_115 ;
struct V_7 * V_8 ;
struct V_322 * V_323 =
(struct V_322 * ) & V_281 -> V_354 ;
if ( ! V_9 )
return - V_115 ;
V_8 = V_9 -> V_10 ;
if ( ( V_323 -> V_355 != V_356 ) &&
( V_323 -> V_355 >= V_9 -> V_162 ) )
return - V_115 ;
V_321 . V_330 = F_13 ( V_357 ,
V_118 ) ;
if ( ! V_321 . V_330 ) {
F_15 ( & V_8 -> V_121 -> V_122 , L_29 ) ;
return - V_119 ;
}
V_321 . V_358 = V_323 -> V_355 ;
V_321 . V_359 = 0 ;
V_321 . V_344 = 0 ;
V_321 . V_360 = V_9 -> V_361 ;
V_321 . V_362 = V_363 ;
V_321 . V_364 = V_365 ;
V_321 . V_366 = 0 ;
V_321 . V_367 = 0 ;
switch ( V_323 -> V_282 & ~ V_368 ) {
case V_283 :
V_248 = F_89 ( V_9 , & V_321 , V_323 , V_324 ) ;
break;
case V_284 :
V_248 = F_87 ( V_9 , & V_321 , V_323 , V_324 ) ;
break;
case V_287 :
V_248 = F_90 ( V_9 , & V_321 , V_323 , V_324 ) ;
break;
case V_291 :
V_248 = F_91 ( V_9 , & V_321 , V_323 , V_324 ) ;
break;
case V_369 :
switch ( V_323 -> V_334 . V_351 . V_353 ) {
case V_370 :
V_248 = F_89 ( V_9 , & V_321 , V_323 , V_324 ) ;
break;
case V_371 :
V_248 = F_87 ( V_9 , & V_321 , V_323 , V_324 ) ;
break;
case V_372 :
V_248 = F_90 ( V_9 , & V_321 , V_323 , V_324 ) ;
break;
default:
V_248 = F_91 ( V_9 , & V_321 , V_323 , V_324 ) ;
break;
}
break;
default:
F_15 ( & V_8 -> V_121 -> V_122 , L_30 ) ;
V_248 = - V_115 ;
}
F_18 ( V_321 . V_330 ) ;
V_321 . V_330 = NULL ;
return V_248 ;
}
static int F_93 ( struct V_1 * V_2 , struct V_280 * V_281 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_248 = - V_170 ;
switch ( V_281 -> V_281 ) {
case V_373 :
V_248 = F_85 ( V_8 , V_281 ) ;
break;
case V_374 :
V_248 = F_92 ( V_9 , V_281 , true ) ;
break;
case V_375 :
V_248 = F_92 ( V_9 , V_281 , false ) ;
break;
default:
break;
}
return V_248 ;
}
static unsigned int F_94 ( struct V_133 * V_9 )
{
return V_9 -> V_164 ;
}
static void F_95 ( struct V_1 * V_122 ,
struct V_376 * V_377 )
{
struct V_5 * V_6 = F_2 ( V_122 ) ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
V_377 -> V_378 = F_94 ( V_9 ) ;
V_377 -> V_379 = ( V_8 -> V_230 & V_380 ) ? 1 : 0 ;
V_377 -> V_381 = V_377 -> V_379 ;
V_377 -> V_382 = V_9 -> V_162 ;
}
static int F_96 ( struct V_1 * V_122 ,
struct V_376 * V_377 )
{
struct V_5 * V_6 = F_2 ( V_122 ) ;
unsigned int V_149 = V_377 -> V_382 ;
struct V_133 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_383 ;
if ( V_9 -> type != V_384 )
return - V_115 ;
if ( ! V_149 || V_377 -> V_385 || V_377 -> V_386 )
return - V_115 ;
if ( V_377 -> V_379 != ( ( V_8 -> V_230 & V_380 ) ? 1 : 0 ) )
return - V_115 ;
if ( V_149 > F_94 ( V_9 ) )
return - V_115 ;
if ( V_149 > V_8 -> V_387 )
V_149 = V_8 -> V_387 ;
V_383 = F_97 ( V_8 , V_149 ) ;
if ( V_383 > 0 )
return 0 ;
else
return - V_115 ;
}
void F_98 ( struct V_1 * V_2 )
{
F_99 ( V_2 , & V_388 ) ;
}
