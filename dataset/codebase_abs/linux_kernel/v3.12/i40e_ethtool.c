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
case V_42 :
default:
V_4 -> V_23 = V_43 ;
V_4 -> V_25 = V_44 ;
break;
}
V_4 -> V_23 |= V_45 ;
if ( V_12 -> V_15 . V_46 == V_47 ) {
V_4 -> V_23 |= V_48 ;
V_4 -> V_25 |= V_49 ;
V_4 -> V_50 = V_51 ;
} else if ( V_12 -> V_15 . V_46 == V_52 ) {
V_4 -> V_23 |= V_53 ;
V_4 -> V_25 |= V_54 ;
V_4 -> V_50 = V_55 ;
} else {
V_4 -> V_23 |= V_56 ;
V_4 -> V_25 |= V_57 ;
V_4 -> V_50 = V_58 ;
}
V_4 -> V_59 = V_60 ;
if ( V_17 ) {
switch ( V_19 ) {
case V_61 :
F_3 ( V_4 , 40000 ) ;
break;
case V_62 :
F_3 ( V_4 , V_63 ) ;
break;
default:
break;
}
V_4 -> V_64 = V_65 ;
} else {
F_3 ( V_4 , V_66 ) ;
V_4 -> V_64 = V_67 ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
struct V_13 * V_14 = & V_12 -> V_15 . V_16 ;
V_69 -> V_70 =
( ( V_14 -> V_71 & V_72 ) ?
V_73 : V_74 ) ;
V_69 -> V_75 = 0 ;
V_69 -> V_76 = 0 ;
if ( V_14 -> V_71 & V_77 )
V_69 -> V_75 = 1 ;
if ( V_14 -> V_71 & V_78 )
V_69 -> V_76 = 1 ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
return V_8 -> V_79 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_80 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
if ( V_81 & V_80 )
V_8 -> V_12 . V_82 = V_80 ;
V_8 -> V_79 = V_80 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_83 = 0 ;
int V_84 ;
for ( V_84 = 0 ; V_85 [ V_84 ] . V_86 != 0 ; V_84 ++ )
V_83 += V_85 [ V_84 ] . V_87 ;
return V_83 * sizeof( T_1 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_88 * V_89 ,
void * V_90 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_1 * V_91 = V_90 ;
int V_84 , V_92 , V_93 ;
T_1 V_94 ;
V_89 -> V_95 = 1 ;
V_93 = 0 ;
for ( V_84 = 0 ; V_85 [ V_84 ] . V_86 != 0 ; V_84 ++ ) {
for ( V_92 = 0 ; V_92 < V_85 [ V_84 ] . V_87 ; V_92 ++ ) {
V_94 = V_85 [ V_84 ] . V_86
+ ( V_92 * V_85 [ V_84 ] . V_96 ) ;
V_91 [ V_93 ++ ] = F_9 ( V_12 , V_94 ) ;
}
}
}
static int F_10 ( struct V_1 * V_2 ,
struct V_97 * V_98 , T_2 * V_99 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_6 -> V_9 -> V_10 -> V_12 ;
int V_100 , V_101 ;
T_3 V_84 , V_102 ;
T_3 * V_103 ;
int V_104 = 0 ;
if ( V_98 -> V_105 == 0 )
return - V_106 ;
V_98 -> V_107 = V_12 -> V_108 | ( V_12 -> V_109 << 16 ) ;
V_100 = V_98 -> V_86 >> 1 ;
V_101 = ( V_98 -> V_86 + V_98 -> V_105 - 1 ) >> 1 ;
V_102 = V_101 - V_100 + 1 ;
V_103 = F_11 ( sizeof( T_3 ) * V_102 , V_110 ) ;
if ( ! V_103 )
return - V_111 ;
V_104 = F_12 ( V_12 , V_100 , & V_102 ,
V_103 ) ;
if ( V_102 == 0 ) {
F_13 ( V_103 ) ;
return - V_112 ;
}
for ( V_84 = 0 ; V_84 < V_102 ; V_84 ++ )
F_14 ( & V_103 [ V_84 ] ) ;
memcpy ( V_99 , ( T_2 * ) V_103 + ( V_98 -> V_86 & 1 ) , V_98 -> V_105 ) ;
F_13 ( V_103 ) ;
return V_104 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_6 -> V_9 -> V_10 -> V_12 ;
return V_12 -> V_113 . V_114 * 2 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_115 * V_116 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_117 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
F_17 ( V_116 -> V_118 , V_119 , sizeof( V_116 -> V_118 ) ) ;
F_17 ( V_116 -> V_95 , V_120 ,
sizeof( V_116 -> V_95 ) ) ;
F_17 ( V_116 -> V_121 , F_18 ( & V_8 -> V_12 ) ,
sizeof( V_116 -> V_121 ) ) ;
F_17 ( V_116 -> V_122 , F_19 ( V_8 -> V_123 ) ,
sizeof( V_116 -> V_122 ) ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_117 * V_9 = V_8 -> V_9 [ V_8 -> V_126 ] ;
V_125 -> V_127 = V_128 ;
V_125 -> V_129 = V_128 ;
V_125 -> V_130 = 0 ;
V_125 -> V_131 = 0 ;
V_125 -> V_132 = V_9 -> V_133 [ 0 ] . V_134 ;
V_125 -> V_135 = V_9 -> V_136 [ 0 ] . V_134 ;
V_125 -> V_137 = 0 ;
V_125 -> V_138 = 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
struct V_139 * V_136 = NULL , * V_133 = NULL ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_117 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
T_1 V_140 , V_141 ;
int V_84 , V_142 = 0 ;
if ( ( V_125 -> V_137 ) || ( V_125 -> V_138 ) )
return - V_106 ;
V_141 = F_22 ( T_1 , V_125 -> V_135 ,
V_143 ,
V_128 ) ;
V_141 = F_23 ( V_141 , V_144 ) ;
V_140 = F_22 ( T_1 , V_125 -> V_132 ,
V_143 ,
V_128 ) ;
V_140 = F_23 ( V_140 , V_144 ) ;
if ( ( V_141 == V_9 -> V_136 [ 0 ] . V_134 ) &&
( V_140 == V_9 -> V_133 [ 0 ] . V_134 ) )
return 0 ;
while ( F_24 ( V_145 , & V_8 -> V_146 ) )
F_25 ( 1000 , 2000 ) ;
if ( ! F_26 ( V_9 -> V_2 ) ) {
for ( V_84 = 0 ; V_84 < V_9 -> V_147 ; V_84 ++ ) {
V_9 -> V_136 [ V_84 ] . V_134 = V_141 ;
V_9 -> V_133 [ V_84 ] . V_134 = V_140 ;
}
goto V_148;
}
if ( V_141 != V_9 -> V_136 [ 0 ] . V_134 ) {
F_27 ( V_2 ,
L_1 ,
V_9 -> V_136 [ 0 ] . V_134 , V_141 ) ;
V_136 = F_28 ( V_9 -> V_149 ,
sizeof( struct V_139 ) , V_110 ) ;
if ( ! V_136 ) {
V_142 = - V_111 ;
goto V_148;
}
for ( V_84 = 0 ; V_84 < V_9 -> V_147 ; V_84 ++ ) {
V_136 [ V_84 ] = V_9 -> V_136 [ V_84 ] ;
V_136 [ V_84 ] . V_134 = V_141 ;
V_142 = F_29 ( & V_136 [ V_84 ] ) ;
if ( V_142 ) {
while ( V_84 ) {
V_84 -- ;
F_30 ( & V_136 [ V_84 ] ) ;
}
F_13 ( V_136 ) ;
V_136 = NULL ;
goto V_148;
}
}
}
if ( V_140 != V_9 -> V_133 [ 0 ] . V_134 ) {
F_27 ( V_2 ,
L_2 ,
V_9 -> V_133 [ 0 ] . V_134 , V_140 ) ;
V_133 = F_28 ( V_9 -> V_149 ,
sizeof( struct V_139 ) , V_110 ) ;
if ( ! V_133 ) {
V_142 = - V_111 ;
goto V_150;
}
for ( V_84 = 0 ; V_84 < V_9 -> V_147 ; V_84 ++ ) {
V_133 [ V_84 ] = V_9 -> V_133 [ V_84 ] ;
V_133 [ V_84 ] . V_134 = V_140 ;
V_142 = F_31 ( & V_133 [ V_84 ] ) ;
if ( V_142 ) {
while ( V_84 ) {
V_84 -- ;
F_32 ( & V_133 [ V_84 ] ) ;
}
F_13 ( V_133 ) ;
V_133 = NULL ;
goto V_150;
}
}
}
F_33 ( V_9 ) ;
if ( V_136 ) {
for ( V_84 = 0 ; V_84 < V_9 -> V_147 ; V_84 ++ ) {
F_30 ( & V_9 -> V_136 [ V_84 ] ) ;
V_9 -> V_136 [ V_84 ] = V_136 [ V_84 ] ;
}
F_13 ( V_136 ) ;
V_136 = NULL ;
}
if ( V_133 ) {
for ( V_84 = 0 ; V_84 < V_9 -> V_147 ; V_84 ++ ) {
F_32 ( & V_9 -> V_133 [ V_84 ] ) ;
V_9 -> V_133 [ V_84 ] = V_133 [ V_84 ] ;
}
F_13 ( V_133 ) ;
V_133 = NULL ;
}
F_34 ( V_9 ) ;
V_150:
if ( V_136 ) {
for ( V_84 = 0 ; V_84 < V_9 -> V_147 ; V_84 ++ )
F_30 ( & V_136 [ V_84 ] ) ;
F_13 ( V_136 ) ;
V_136 = NULL ;
}
V_148:
F_35 ( V_145 , & V_8 -> V_146 ) ;
return V_142 ;
}
static int F_36 ( struct V_1 * V_2 , int V_151 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_117 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
switch ( V_151 ) {
case V_152 :
return V_153 ;
case V_154 :
if ( V_9 == V_8 -> V_9 [ V_8 -> V_126 ] )
return F_37 ( V_2 ) ;
else
return F_38 ( V_2 ) ;
default:
return - V_155 ;
}
}
static void F_39 ( struct V_1 * V_2 ,
struct V_156 * V_157 , T_4 * V_80 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_117 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_84 = 0 ;
char * V_90 ;
int V_92 ;
struct V_158 * V_159 = F_40 ( V_9 ) ;
F_41 ( V_9 ) ;
for ( V_92 = 0 ; V_92 < V_160 ; V_92 ++ ) {
V_90 = ( char * ) V_159 + V_161 [ V_92 ] . V_162 ;
V_80 [ V_84 ++ ] = ( V_161 [ V_92 ] . V_163 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_90 : * ( T_1 * ) V_90 ;
}
for ( V_92 = 0 ; V_92 < V_9 -> V_147 ; V_92 ++ ) {
V_80 [ V_84 ++ ] = V_9 -> V_136 [ V_92 ] . V_164 . V_165 ;
V_80 [ V_84 ++ ] = V_9 -> V_136 [ V_92 ] . V_164 . V_99 ;
}
for ( V_92 = 0 ; V_92 < V_9 -> V_147 ; V_92 ++ ) {
V_80 [ V_84 ++ ] = V_9 -> V_133 [ V_92 ] . V_166 . V_165 ;
V_80 [ V_84 ++ ] = V_9 -> V_133 [ V_92 ] . V_166 . V_99 ;
}
if ( V_9 == V_8 -> V_9 [ V_8 -> V_126 ] ) {
for ( V_92 = 0 ; V_92 < V_167 ; V_92 ++ ) {
V_90 = ( char * ) V_8 + V_168 [ V_92 ] . V_162 ;
V_80 [ V_84 ++ ] = ( V_168 [ V_92 ] . V_163 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_90 : * ( T_1 * ) V_90 ;
}
for ( V_92 = 0 ; V_92 < V_169 ; V_92 ++ ) {
V_80 [ V_84 ++ ] = V_8 -> V_157 . V_170 [ V_92 ] ;
V_80 [ V_84 ++ ] = V_8 -> V_157 . V_171 [ V_92 ] ;
}
for ( V_92 = 0 ; V_92 < V_169 ; V_92 ++ ) {
V_80 [ V_84 ++ ] = V_8 -> V_157 . V_172 [ V_92 ] ;
V_80 [ V_84 ++ ] = V_8 -> V_157 . V_173 [ V_92 ] ;
}
for ( V_92 = 0 ; V_92 < V_169 ; V_92 ++ )
V_80 [ V_84 ++ ] = V_8 -> V_157 . V_174 [ V_92 ] ;
}
}
static void F_42 ( struct V_1 * V_2 , T_1 V_175 ,
T_2 * V_80 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_117 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
char * V_90 = ( char * ) V_80 ;
int V_84 ;
switch ( V_175 ) {
case V_152 :
for ( V_84 = 0 ; V_84 < V_153 ; V_84 ++ ) {
memcpy ( V_80 , V_176 [ V_84 ] , V_177 ) ;
V_80 += V_177 ;
}
break;
case V_154 :
for ( V_84 = 0 ; V_84 < V_160 ; V_84 ++ ) {
snprintf ( V_90 , V_177 , L_3 ,
V_161 [ V_84 ] . V_178 ) ;
V_90 += V_177 ;
}
for ( V_84 = 0 ; V_84 < V_9 -> V_147 ; V_84 ++ ) {
snprintf ( V_90 , V_177 , L_4 , V_84 ) ;
V_90 += V_177 ;
snprintf ( V_90 , V_177 , L_5 , V_84 ) ;
V_90 += V_177 ;
}
for ( V_84 = 0 ; V_84 < V_9 -> V_147 ; V_84 ++ ) {
snprintf ( V_90 , V_177 , L_6 , V_84 ) ;
V_90 += V_177 ;
snprintf ( V_90 , V_177 , L_7 , V_84 ) ;
V_90 += V_177 ;
}
if ( V_9 == V_8 -> V_9 [ V_8 -> V_126 ] ) {
for ( V_84 = 0 ; V_84 < V_167 ; V_84 ++ ) {
snprintf ( V_90 , V_177 , L_8 ,
V_168 [ V_84 ] . V_178 ) ;
V_90 += V_177 ;
}
for ( V_84 = 0 ; V_84 < V_169 ; V_84 ++ ) {
snprintf ( V_90 , V_177 ,
L_9 , V_84 ) ;
V_90 += V_177 ;
snprintf ( V_90 , V_177 ,
L_10 , V_84 ) ;
V_90 += V_177 ;
}
for ( V_84 = 0 ; V_84 < V_169 ; V_84 ++ ) {
snprintf ( V_90 , V_177 ,
L_11 , V_84 ) ;
V_90 += V_177 ;
snprintf ( V_90 , V_177 ,
L_12 , V_84 ) ;
V_90 += V_177 ;
}
for ( V_84 = 0 ; V_84 < V_169 ; V_84 ++ ) {
snprintf ( V_90 , V_177 ,
L_13 , V_84 ) ;
V_90 += V_177 ;
}
}
break;
}
}
static int F_43 ( struct V_1 * V_179 ,
struct V_180 * V_181 )
{
return F_44 ( V_179 , V_181 ) ;
}
static int F_45 ( struct V_7 * V_8 , T_4 * V_80 )
{
if ( F_46 ( & V_8 -> V_12 ) )
* V_80 = 0 ;
else
* V_80 = 1 ;
return * V_80 ;
}
static int F_47 ( struct V_7 * V_8 , T_4 * V_80 )
{
T_5 V_182 ;
V_182 = F_48 ( & V_8 -> V_12 ) ;
* V_80 = V_182 ;
return V_182 ;
}
static int F_49 ( struct V_7 * V_8 , T_4 * V_80 )
{
T_5 V_182 ;
V_182 = F_50 ( & V_8 -> V_12 ) ;
* V_80 = V_182 ;
return V_182 ;
}
static int F_51 ( struct V_7 * V_8 , T_4 * V_80 )
{
* V_80 = - V_183 ;
return * V_80 ;
}
static int F_52 ( struct V_7 * V_8 , T_4 * V_80 )
{
* V_80 = - V_183 ;
return * V_80 ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_184 * V_185 , T_4 * V_80 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_54 ( V_186 , & V_8 -> V_146 ) ;
if ( V_185 -> V_187 == V_188 ) {
F_27 ( V_2 , L_14 ) ;
F_27 ( V_2 , L_15 ) ;
if ( F_45 ( V_8 , & V_80 [ V_189 ] ) )
V_185 -> V_187 |= V_190 ;
F_27 ( V_2 , L_16 ) ;
if ( F_47 ( V_8 , & V_80 [ V_191 ] ) )
V_185 -> V_187 |= V_190 ;
F_55 ( V_8 , ( 1 << V_192 ) ) ;
F_27 ( V_2 , L_17 ) ;
if ( F_49 ( V_8 , & V_80 [ V_193 ] ) )
V_185 -> V_187 |= V_190 ;
F_55 ( V_8 , ( 1 << V_192 ) ) ;
F_27 ( V_2 , L_18 ) ;
if ( F_51 ( V_8 , & V_80 [ V_194 ] ) )
V_185 -> V_187 |= V_190 ;
F_55 ( V_8 , ( 1 << V_192 ) ) ;
F_27 ( V_2 , L_19 ) ;
if ( F_52 ( V_8 , & V_80 [ V_195 ] ) )
V_185 -> V_187 |= V_190 ;
} else {
F_27 ( V_2 , L_20 ) ;
if ( F_45 ( V_8 , & V_80 [ V_189 ] ) )
V_185 -> V_187 |= V_190 ;
V_80 [ V_191 ] = 0 ;
V_80 [ V_193 ] = 0 ;
V_80 [ V_194 ] = 0 ;
V_80 [ V_195 ] = 0 ;
F_35 ( V_186 , & V_8 -> V_146 ) ;
}
}
static void F_56 ( struct V_1 * V_2 ,
struct V_196 * V_197 )
{
V_197 -> V_23 = 0 ;
V_197 -> V_198 = 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_5 V_182 = 0 ;
V_182 = F_58 ( V_12 , NULL ) ;
if ( V_182 ) {
F_27 ( V_2 , L_21 ,
V_8 -> V_12 . V_199 . V_200 ) ;
return - V_201 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
enum V_202 V_146 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
int V_203 = 2 ;
switch ( V_146 ) {
case V_204 :
V_8 -> V_205 = F_60 ( V_12 ) ;
return V_203 ;
case V_206 :
F_61 ( V_12 , 0xF ) ;
break;
case V_207 :
F_61 ( V_12 , 0x0 ) ;
break;
case V_208 :
F_61 ( V_12 , V_8 -> V_205 ) ;
break;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_209 * V_210 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_117 * V_9 = V_6 -> V_9 ;
V_210 -> V_211 = V_9 -> V_212 ;
V_210 -> V_213 = V_9 -> V_212 ;
if ( F_63 ( V_9 -> V_214 ) )
V_210 -> V_215 = 1 ;
else
V_210 -> V_215 = V_9 -> V_214 ;
if ( F_63 ( V_9 -> V_216 ) )
V_210 -> V_217 = 1 ;
else
V_210 -> V_217 = V_9 -> V_216 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_209 * V_210 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_218 * V_219 ;
struct V_117 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_3 V_220 ;
int V_84 ;
if ( V_210 -> V_211 || V_210 -> V_213 )
V_9 -> V_212 = V_210 -> V_211 ;
switch ( V_210 -> V_215 ) {
case 0 :
V_9 -> V_214 = 0 ;
break;
case 1 :
V_9 -> V_214 = ( V_221 |
F_65 ( V_222 ) ) ;
break;
default:
if ( ( V_210 -> V_215 < ( V_223 << 1 ) ) ||
( V_210 -> V_215 > ( V_224 << 1 ) ) )
return - V_106 ;
V_9 -> V_214 = V_210 -> V_215 ;
break;
}
switch ( V_210 -> V_217 ) {
case 0 :
V_9 -> V_216 = 0 ;
break;
case 1 :
V_9 -> V_216 = ( V_221 |
F_65 ( V_225 ) ) ;
break;
default:
if ( ( V_210 -> V_217 < ( V_223 << 1 ) ) ||
( V_210 -> V_217 > ( V_224 << 1 ) ) )
return - V_106 ;
V_9 -> V_216 = V_210 -> V_217 ;
break;
}
V_220 = V_9 -> V_226 ;
V_219 = V_9 -> V_227 ;
for ( V_84 = 0 ; V_84 < V_9 -> V_228 ; V_84 ++ , V_220 ++ , V_219 ++ ) {
V_219 -> V_229 . V_230 = F_66 ( V_9 -> V_214 ) ;
F_67 ( V_12 , F_68 ( 0 , V_220 - 1 ) , V_219 -> V_229 . V_230 ) ;
V_219 -> V_231 . V_230 = F_66 ( V_9 -> V_216 ) ;
F_67 ( V_12 , F_68 ( 1 , V_220 - 1 ) , V_219 -> V_231 . V_230 ) ;
F_69 ( V_12 ) ;
}
return 0 ;
}
static int F_70 ( struct V_7 * V_8 , struct V_232 * V_233 )
{
V_233 -> V_80 = 0 ;
switch ( V_233 -> V_234 ) {
case V_235 :
case V_236 :
V_233 -> V_80 |= V_237 | V_238 ;
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
V_233 -> V_80 |= V_244 | V_245 ;
break;
case V_246 :
case V_247 :
V_233 -> V_80 |= V_237 | V_238 ;
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
V_233 -> V_80 |= V_244 | V_245 ;
break;
default:
return - V_106 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_232 * V_233 ,
T_1 * V_253 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_117 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_182 = - V_155 ;
switch ( V_233 -> V_233 ) {
case V_254 :
V_233 -> V_80 = V_9 -> V_149 ;
V_182 = 0 ;
break;
case V_255 :
V_182 = F_70 ( V_8 , V_233 ) ;
break;
case V_256 :
V_182 = 0 ;
break;
case V_257 :
V_182 = 0 ;
break;
case V_258 :
V_233 -> V_80 = 500 ;
V_182 = 0 ;
default:
break;
}
return V_182 ;
}
static int F_72 ( struct V_7 * V_8 , struct V_232 * V_259 )
{
struct V_11 * V_12 = & V_8 -> V_12 ;
T_4 V_260 = ( T_4 ) F_9 ( V_12 , F_73 ( 0 ) ) |
( ( T_4 ) F_9 ( V_12 , F_73 ( 1 ) ) << 32 ) ;
if ( V_259 -> V_80 & ~ ( V_244 | V_245 |
V_237 | V_238 ) )
return - V_106 ;
if ( ! ( V_259 -> V_80 & V_244 ) ||
! ( V_259 -> V_80 & V_245 ) )
return - V_106 ;
switch ( V_259 -> V_234 ) {
case V_235 :
switch ( V_259 -> V_80 & ( V_237 | V_238 ) ) {
case 0 :
V_260 &= ~ ( ( T_4 ) 1 << V_261 ) ;
break;
case ( V_237 | V_238 ) :
V_260 |= ( ( T_4 ) 1 << V_261 ) ;
break;
default:
return - V_106 ;
}
break;
case V_246 :
switch ( V_259 -> V_80 & ( V_237 | V_238 ) ) {
case 0 :
V_260 &= ~ ( ( T_4 ) 1 << V_262 ) ;
break;
case ( V_237 | V_238 ) :
V_260 |= ( ( T_4 ) 1 << V_262 ) ;
break;
default:
return - V_106 ;
}
break;
case V_236 :
switch ( V_259 -> V_80 & ( V_237 | V_238 ) ) {
case 0 :
V_260 &=
~ ( ( ( T_4 ) 1 << V_263 ) |
( ( T_4 ) 1 << V_264 ) |
( ( T_4 ) 1 << V_265 ) ) ;
break;
case ( V_237 | V_238 ) :
V_260 |=
( ( ( T_4 ) 1 << V_263 ) |
( ( T_4 ) 1 << V_264 ) |
( ( T_4 ) 1 << V_265 ) ) ;
break;
default:
return - V_106 ;
}
break;
case V_247 :
switch ( V_259 -> V_80 & ( V_237 | V_238 ) ) {
case 0 :
V_260 &=
~ ( ( ( T_4 ) 1 << V_266 ) |
( ( T_4 ) 1 << V_267 ) |
( ( T_4 ) 1 << V_268 ) ) ;
break;
case ( V_237 | V_238 ) :
V_260 |=
( ( ( T_4 ) 1 << V_266 ) |
( ( T_4 ) 1 << V_267 ) |
( ( T_4 ) 1 << V_268 ) ) ;
break;
default:
return - V_106 ;
}
break;
case V_240 :
case V_241 :
case V_242 :
case V_239 :
if ( ( V_259 -> V_80 & V_237 ) ||
( V_259 -> V_80 & V_238 ) )
return - V_106 ;
V_260 |= ( ( T_4 ) 1 << V_269 ) ;
break;
case V_249 :
case V_250 :
case V_251 :
case V_248 :
if ( ( V_259 -> V_80 & V_237 ) ||
( V_259 -> V_80 & V_238 ) )
return - V_106 ;
V_260 |= ( ( T_4 ) 1 << V_270 ) ;
break;
case V_243 :
V_260 |= ( ( T_4 ) 1 << V_269 ) |
( ( T_4 ) 1 << V_265 ) ;
break;
case V_252 :
V_260 |= ( ( T_4 ) 1 << V_270 ) |
( ( T_4 ) 1 << V_268 ) ;
break;
default:
return - V_106 ;
}
F_67 ( V_12 , F_73 ( 0 ) , ( T_1 ) V_260 ) ;
F_67 ( V_12 , F_73 ( 1 ) , ( T_1 ) ( V_260 >> 32 ) ) ;
F_69 ( V_12 ) ;
return 0 ;
}
static int F_74 ( struct V_117 * V_9 ,
struct V_271 * V_272 ,
struct V_273 * V_274 , bool V_275 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_276 * V_277 ;
struct V_278 * V_279 ;
bool V_142 = false ;
int V_182 ;
int V_84 ;
V_279 = (struct V_278 * ) ( V_272 -> V_280 + V_281 ) ;
V_277 = (struct V_276 * ) ( V_272 -> V_280 + V_281
+ sizeof( struct V_278 ) ) ;
V_279 -> V_282 = V_274 -> V_283 . V_284 . V_285 ;
V_279 -> V_286 = V_274 -> V_283 . V_284 . V_287 ;
V_277 -> V_288 = V_274 -> V_283 . V_284 . V_289 ;
V_277 -> V_290 = V_274 -> V_283 . V_284 . V_291 ;
for ( V_84 = V_263 ;
V_84 <= V_292 ; V_84 ++ ) {
V_272 -> V_293 = V_84 ;
V_182 = F_75 ( V_272 , V_8 , V_275 ) ;
if ( V_182 ) {
F_76 ( & V_8 -> V_123 -> V_179 ,
L_22 ,
V_272 -> V_293 , V_182 ) ;
V_142 = true ;
} else {
F_76 ( & V_8 -> V_123 -> V_179 ,
L_23 ,
V_272 -> V_293 , V_182 ) ;
}
}
return V_142 ? - V_155 : 0 ;
}
static int F_77 ( struct V_117 * V_9 ,
struct V_271 * V_272 ,
struct V_273 * V_274 , bool V_275 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_294 * V_295 ;
struct V_278 * V_279 ;
bool V_142 = false ;
int V_182 ;
V_279 = (struct V_278 * ) ( V_272 -> V_280 + V_281 ) ;
V_295 = (struct V_294 * ) ( V_272 -> V_280 + V_281
+ sizeof( struct V_278 ) ) ;
V_279 -> V_286 = V_274 -> V_283 . V_284 . V_287 ;
V_295 -> V_290 = V_274 -> V_283 . V_284 . V_291 ;
V_272 -> V_293 = V_296 ;
V_182 = F_75 ( V_272 , V_8 , V_275 ) ;
if ( V_182 ) {
F_76 ( & V_8 -> V_123 -> V_179 ,
L_22 ,
V_272 -> V_293 , V_182 ) ;
V_142 = true ;
} else {
F_76 ( & V_8 -> V_123 -> V_179 , L_23 ,
V_272 -> V_293 , V_182 ) ;
}
V_279 -> V_282 = V_274 -> V_283 . V_284 . V_285 ;
V_295 -> V_288 = V_274 -> V_283 . V_284 . V_289 ;
V_272 -> V_293 = V_261 ;
V_182 = F_75 ( V_272 , V_8 , V_275 ) ;
if ( V_182 ) {
F_76 ( & V_8 -> V_123 -> V_179 ,
L_22 ,
V_272 -> V_293 , V_182 ) ;
V_142 = true ;
} else {
F_76 ( & V_8 -> V_123 -> V_179 , L_23 ,
V_272 -> V_293 , V_182 ) ;
}
return V_142 ? - V_155 : 0 ;
}
static int F_78 ( struct V_117 * V_9 ,
struct V_271 * V_272 ,
struct V_273 * V_274 , bool V_275 )
{
return - V_155 ;
}
static int F_79 ( struct V_117 * V_9 ,
struct V_271 * V_272 ,
struct V_273 * V_274 , bool V_275 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_278 * V_279 ;
bool V_142 = false ;
int V_182 ;
int V_84 ;
V_279 = (struct V_278 * ) ( V_272 -> V_280 + V_281 ) ;
V_279 -> V_282 = V_274 -> V_283 . V_297 . V_285 ;
V_279 -> V_286 = V_274 -> V_283 . V_297 . V_287 ;
V_279 -> V_298 = V_274 -> V_283 . V_297 . V_299 ;
for ( V_84 = V_269 ;
V_84 <= V_265 ; V_84 ++ ) {
V_272 -> V_293 = V_84 ;
V_182 = F_75 ( V_272 , V_8 , V_275 ) ;
if ( V_182 ) {
F_76 ( & V_8 -> V_123 -> V_179 ,
L_22 ,
V_272 -> V_293 , V_182 ) ;
V_142 = true ;
} else {
F_76 ( & V_8 -> V_123 -> V_179 ,
L_23 ,
V_272 -> V_293 , V_182 ) ;
}
}
return V_142 ? - V_155 : 0 ;
}
static int F_80 ( struct V_117 * V_9 ,
struct V_232 * V_233 , bool V_275 )
{
struct V_271 V_272 ;
int V_182 = - V_106 ;
struct V_7 * V_8 ;
struct V_273 * V_274 =
(struct V_273 * ) & V_233 -> V_300 ;
if ( ! V_9 )
return - V_106 ;
V_8 = V_9 -> V_10 ;
if ( ( V_274 -> V_301 != V_302 ) &&
( V_274 -> V_301 >= V_9 -> V_147 ) )
return - V_106 ;
V_272 . V_280 = F_81 ( V_303 ,
V_110 ) ;
if ( ! V_272 . V_280 ) {
F_76 ( & V_8 -> V_123 -> V_179 , L_24 ) ;
return - V_111 ;
}
V_272 . V_304 = V_274 -> V_301 ;
V_272 . V_305 = 0 ;
V_272 . V_293 = 0 ;
V_272 . V_306 = V_9 -> V_307 ;
V_272 . V_308 = 0 ;
V_272 . V_309 = 0 ;
V_272 . V_310 = 0 ;
V_272 . V_311 = 0 ;
switch ( V_274 -> V_234 & ~ V_312 ) {
case V_235 :
V_182 = F_77 ( V_9 , & V_272 , V_274 , V_275 ) ;
break;
case V_236 :
V_182 = F_74 ( V_9 , & V_272 , V_274 , V_275 ) ;
break;
case V_239 :
V_182 = F_78 ( V_9 , & V_272 , V_274 , V_275 ) ;
break;
case V_243 :
V_182 = F_79 ( V_9 , & V_272 , V_274 , V_275 ) ;
break;
case V_313 :
switch ( V_274 -> V_283 . V_297 . V_299 ) {
case V_314 :
V_182 = F_77 ( V_9 , & V_272 , V_274 , V_275 ) ;
break;
case V_315 :
V_182 = F_74 ( V_9 , & V_272 , V_274 , V_275 ) ;
break;
case V_316 :
V_182 = F_78 ( V_9 , & V_272 , V_274 , V_275 ) ;
break;
default:
V_182 = F_79 ( V_9 , & V_272 , V_274 , V_275 ) ;
break;
}
break;
default:
F_76 ( & V_8 -> V_123 -> V_179 , L_25 ) ;
V_182 = - V_106 ;
}
F_13 ( V_272 . V_280 ) ;
V_272 . V_280 = NULL ;
return V_182 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_232 * V_233 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_117 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_182 = - V_155 ;
switch ( V_233 -> V_233 ) {
case V_317 :
V_182 = F_72 ( V_8 , V_233 ) ;
break;
case V_318 :
V_182 = F_80 ( V_9 , V_233 , true ) ;
break;
case V_319 :
V_182 = F_80 ( V_9 , V_233 , false ) ;
break;
default:
break;
}
return V_182 ;
}
void F_83 ( struct V_1 * V_2 )
{
F_84 ( V_2 , & V_320 ) ;
}
