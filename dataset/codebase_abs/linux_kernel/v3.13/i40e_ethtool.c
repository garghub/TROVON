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
V_125 -> V_132 = V_9 -> V_133 [ 0 ] -> V_134 ;
V_125 -> V_135 = V_9 -> V_136 [ 0 ] -> V_134 ;
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
if ( ( V_141 == V_9 -> V_136 [ 0 ] -> V_134 ) &&
( V_140 == V_9 -> V_133 [ 0 ] -> V_134 ) )
return 0 ;
while ( F_24 ( V_145 , & V_8 -> V_146 ) )
F_25 ( 1000 , 2000 ) ;
if ( ! F_26 ( V_9 -> V_2 ) ) {
for ( V_84 = 0 ; V_84 < V_9 -> V_147 ; V_84 ++ ) {
V_9 -> V_136 [ V_84 ] -> V_134 = V_141 ;
V_9 -> V_133 [ V_84 ] -> V_134 = V_140 ;
}
goto V_148;
}
if ( V_141 != V_9 -> V_136 [ 0 ] -> V_134 ) {
F_27 ( V_2 ,
L_1 ,
V_9 -> V_136 [ 0 ] -> V_134 , V_141 ) ;
V_136 = F_28 ( V_9 -> V_149 ,
sizeof( struct V_139 ) , V_110 ) ;
if ( ! V_136 ) {
V_142 = - V_111 ;
goto V_148;
}
for ( V_84 = 0 ; V_84 < V_9 -> V_147 ; V_84 ++ ) {
V_136 [ V_84 ] = * V_9 -> V_136 [ V_84 ] ;
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
if ( V_140 != V_9 -> V_133 [ 0 ] -> V_134 ) {
F_27 ( V_2 ,
L_2 ,
V_9 -> V_133 [ 0 ] -> V_134 , V_140 ) ;
V_133 = F_28 ( V_9 -> V_149 ,
sizeof( struct V_139 ) , V_110 ) ;
if ( ! V_133 ) {
V_142 = - V_111 ;
goto V_150;
}
for ( V_84 = 0 ; V_84 < V_9 -> V_147 ; V_84 ++ ) {
V_133 [ V_84 ] = * V_9 -> V_133 [ V_84 ] ;
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
F_30 ( V_9 -> V_136 [ V_84 ] ) ;
* V_9 -> V_136 [ V_84 ] = V_136 [ V_84 ] ;
}
F_13 ( V_136 ) ;
V_136 = NULL ;
}
if ( V_133 ) {
for ( V_84 = 0 ; V_84 < V_9 -> V_147 ; V_84 ++ ) {
F_32 ( V_9 -> V_133 [ V_84 ] ) ;
* V_9 -> V_133 [ V_84 ] = V_133 [ V_84 ] ;
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
unsigned int V_160 ;
F_41 ( V_9 ) ;
for ( V_92 = 0 ; V_92 < V_161 ; V_92 ++ ) {
V_90 = ( char * ) V_159 + V_162 [ V_92 ] . V_163 ;
V_80 [ V_84 ++ ] = ( V_162 [ V_92 ] . V_164 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_90 : * ( T_1 * ) V_90 ;
}
F_42 () ;
for ( V_92 = 0 ; V_92 < V_9 -> V_147 ; V_92 ++ , V_84 += 4 ) {
struct V_139 * V_165 = F_43 ( V_9 -> V_136 [ V_92 ] ) ;
struct V_139 * V_166 ;
if ( ! V_165 )
continue;
do {
V_160 = F_44 ( & V_165 -> V_167 ) ;
V_80 [ V_84 ] = V_165 -> V_157 . V_168 ;
V_80 [ V_84 + 1 ] = V_165 -> V_157 . V_99 ;
} while ( F_45 ( & V_165 -> V_167 , V_160 ) );
V_166 = & V_165 [ 1 ] ;
do {
V_160 = F_44 ( & V_166 -> V_167 ) ;
V_80 [ V_84 + 2 ] = V_166 -> V_157 . V_168 ;
V_80 [ V_84 + 3 ] = V_166 -> V_157 . V_99 ;
} while ( F_45 ( & V_166 -> V_167 , V_160 ) );
}
F_46 () ;
if ( V_9 == V_8 -> V_9 [ V_8 -> V_126 ] ) {
for ( V_92 = 0 ; V_92 < V_169 ; V_92 ++ ) {
V_90 = ( char * ) V_8 + V_170 [ V_92 ] . V_163 ;
V_80 [ V_84 ++ ] = ( V_170 [ V_92 ] . V_164 ==
sizeof( T_4 ) ) ? * ( T_4 * ) V_90 : * ( T_1 * ) V_90 ;
}
for ( V_92 = 0 ; V_92 < V_171 ; V_92 ++ ) {
V_80 [ V_84 ++ ] = V_8 -> V_157 . V_172 [ V_92 ] ;
V_80 [ V_84 ++ ] = V_8 -> V_157 . V_173 [ V_92 ] ;
}
for ( V_92 = 0 ; V_92 < V_171 ; V_92 ++ ) {
V_80 [ V_84 ++ ] = V_8 -> V_157 . V_174 [ V_92 ] ;
V_80 [ V_84 ++ ] = V_8 -> V_157 . V_175 [ V_92 ] ;
}
for ( V_92 = 0 ; V_92 < V_171 ; V_92 ++ )
V_80 [ V_84 ++ ] = V_8 -> V_157 . V_176 [ V_92 ] ;
}
}
static void F_47 ( struct V_1 * V_2 , T_1 V_177 ,
T_2 * V_80 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_117 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
char * V_90 = ( char * ) V_80 ;
int V_84 ;
switch ( V_177 ) {
case V_152 :
for ( V_84 = 0 ; V_84 < V_153 ; V_84 ++ ) {
memcpy ( V_80 , V_178 [ V_84 ] , V_179 ) ;
V_80 += V_179 ;
}
break;
case V_154 :
for ( V_84 = 0 ; V_84 < V_161 ; V_84 ++ ) {
snprintf ( V_90 , V_179 , L_3 ,
V_162 [ V_84 ] . V_180 ) ;
V_90 += V_179 ;
}
for ( V_84 = 0 ; V_84 < V_9 -> V_147 ; V_84 ++ ) {
snprintf ( V_90 , V_179 , L_4 , V_84 ) ;
V_90 += V_179 ;
snprintf ( V_90 , V_179 , L_5 , V_84 ) ;
V_90 += V_179 ;
snprintf ( V_90 , V_179 , L_6 , V_84 ) ;
V_90 += V_179 ;
snprintf ( V_90 , V_179 , L_7 , V_84 ) ;
V_90 += V_179 ;
}
if ( V_9 == V_8 -> V_9 [ V_8 -> V_126 ] ) {
for ( V_84 = 0 ; V_84 < V_169 ; V_84 ++ ) {
snprintf ( V_90 , V_179 , L_8 ,
V_170 [ V_84 ] . V_180 ) ;
V_90 += V_179 ;
}
for ( V_84 = 0 ; V_84 < V_171 ; V_84 ++ ) {
snprintf ( V_90 , V_179 ,
L_9 , V_84 ) ;
V_90 += V_179 ;
snprintf ( V_90 , V_179 ,
L_10 , V_84 ) ;
V_90 += V_179 ;
}
for ( V_84 = 0 ; V_84 < V_171 ; V_84 ++ ) {
snprintf ( V_90 , V_179 ,
L_11 , V_84 ) ;
V_90 += V_179 ;
snprintf ( V_90 , V_179 ,
L_12 , V_84 ) ;
V_90 += V_179 ;
}
for ( V_84 = 0 ; V_84 < V_171 ; V_84 ++ ) {
snprintf ( V_90 , V_179 ,
L_13 , V_84 ) ;
V_90 += V_179 ;
}
}
break;
}
}
static int F_48 ( struct V_1 * V_181 ,
struct V_182 * V_183 )
{
return F_49 ( V_181 , V_183 ) ;
}
static int F_50 ( struct V_7 * V_8 , T_4 * V_80 )
{
if ( F_51 ( & V_8 -> V_12 ) )
* V_80 = 0 ;
else
* V_80 = 1 ;
return * V_80 ;
}
static int F_52 ( struct V_7 * V_8 , T_4 * V_80 )
{
T_5 V_184 ;
V_184 = F_53 ( & V_8 -> V_12 ) ;
* V_80 = V_184 ;
return V_184 ;
}
static int F_54 ( struct V_7 * V_8 , T_4 * V_80 )
{
T_5 V_184 ;
V_184 = F_55 ( & V_8 -> V_12 ) ;
* V_80 = V_184 ;
return V_184 ;
}
static int F_56 ( struct V_7 * V_8 , T_4 * V_80 )
{
* V_80 = - V_185 ;
return * V_80 ;
}
static int F_57 ( struct V_7 * V_8 , T_4 * V_80 )
{
* V_80 = - V_185 ;
return * V_80 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_186 * V_187 , T_4 * V_80 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_59 ( V_188 , & V_8 -> V_146 ) ;
if ( V_187 -> V_189 == V_190 ) {
F_27 ( V_2 , L_14 ) ;
F_27 ( V_2 , L_15 ) ;
if ( F_50 ( V_8 , & V_80 [ V_191 ] ) )
V_187 -> V_189 |= V_192 ;
F_27 ( V_2 , L_16 ) ;
if ( F_52 ( V_8 , & V_80 [ V_193 ] ) )
V_187 -> V_189 |= V_192 ;
F_60 ( V_8 , ( 1 << V_194 ) ) ;
F_27 ( V_2 , L_17 ) ;
if ( F_54 ( V_8 , & V_80 [ V_195 ] ) )
V_187 -> V_189 |= V_192 ;
F_60 ( V_8 , ( 1 << V_194 ) ) ;
F_27 ( V_2 , L_18 ) ;
if ( F_56 ( V_8 , & V_80 [ V_196 ] ) )
V_187 -> V_189 |= V_192 ;
F_60 ( V_8 , ( 1 << V_194 ) ) ;
F_27 ( V_2 , L_19 ) ;
if ( F_57 ( V_8 , & V_80 [ V_197 ] ) )
V_187 -> V_189 |= V_192 ;
} else {
F_27 ( V_2 , L_20 ) ;
if ( F_50 ( V_8 , & V_80 [ V_191 ] ) )
V_187 -> V_189 |= V_192 ;
V_80 [ V_193 ] = 0 ;
V_80 [ V_195 ] = 0 ;
V_80 [ V_196 ] = 0 ;
V_80 [ V_197 ] = 0 ;
F_35 ( V_188 , & V_8 -> V_146 ) ;
}
}
static void F_61 ( struct V_1 * V_2 ,
struct V_198 * V_199 )
{
V_199 -> V_23 = 0 ;
V_199 -> V_200 = 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_5 V_184 = 0 ;
V_184 = F_63 ( V_12 , NULL ) ;
if ( V_184 ) {
F_27 ( V_2 , L_21 ,
V_8 -> V_12 . V_201 . V_202 ) ;
return - V_203 ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
enum V_204 V_146 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
int V_205 = 2 ;
switch ( V_146 ) {
case V_206 :
V_8 -> V_207 = F_65 ( V_12 ) ;
return V_205 ;
case V_208 :
F_66 ( V_12 , 0xF ) ;
break;
case V_209 :
F_66 ( V_12 , 0x0 ) ;
break;
case V_210 :
F_66 ( V_12 , V_8 -> V_207 ) ;
break;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_211 * V_212 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_117 * V_9 = V_6 -> V_9 ;
V_212 -> V_213 = V_9 -> V_214 ;
V_212 -> V_215 = V_9 -> V_214 ;
if ( F_68 ( V_9 -> V_216 ) )
V_212 -> V_217 = 1 ;
else
V_212 -> V_217 = V_9 -> V_216 ;
if ( F_68 ( V_9 -> V_218 ) )
V_212 -> V_219 = 1 ;
else
V_212 -> V_219 = V_9 -> V_218 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_211 * V_212 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_220 * V_221 ;
struct V_117 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_3 V_222 ;
int V_84 ;
if ( V_212 -> V_213 || V_212 -> V_215 )
V_9 -> V_214 = V_212 -> V_213 ;
switch ( V_212 -> V_217 ) {
case 0 :
V_9 -> V_216 = 0 ;
break;
case 1 :
V_9 -> V_216 = ( V_223 |
F_70 ( V_224 ) ) ;
break;
default:
if ( ( V_212 -> V_217 < ( V_225 << 1 ) ) ||
( V_212 -> V_217 > ( V_226 << 1 ) ) )
return - V_106 ;
V_9 -> V_216 = V_212 -> V_217 ;
break;
}
switch ( V_212 -> V_219 ) {
case 0 :
V_9 -> V_218 = 0 ;
break;
case 1 :
V_9 -> V_218 = ( V_223 |
F_70 ( V_227 ) ) ;
break;
default:
if ( ( V_212 -> V_219 < ( V_225 << 1 ) ) ||
( V_212 -> V_219 > ( V_226 << 1 ) ) )
return - V_106 ;
V_9 -> V_218 = V_212 -> V_219 ;
break;
}
V_222 = V_9 -> V_228 ;
for ( V_84 = 0 ; V_84 < V_9 -> V_229 ; V_84 ++ , V_222 ++ ) {
V_221 = V_9 -> V_230 [ V_84 ] ;
V_221 -> V_231 . V_232 = F_71 ( V_9 -> V_216 ) ;
F_72 ( V_12 , F_73 ( 0 , V_222 - 1 ) , V_221 -> V_231 . V_232 ) ;
V_221 -> V_233 . V_232 = F_71 ( V_9 -> V_218 ) ;
F_72 ( V_12 , F_73 ( 1 , V_222 - 1 ) , V_221 -> V_233 . V_232 ) ;
F_74 ( V_12 ) ;
}
return 0 ;
}
static int F_75 ( struct V_7 * V_8 , struct V_234 * V_235 )
{
V_235 -> V_80 = 0 ;
switch ( V_235 -> V_236 ) {
case V_237 :
case V_238 :
V_235 -> V_80 |= V_239 | V_240 ;
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
V_235 -> V_80 |= V_246 | V_247 ;
break;
case V_248 :
case V_249 :
V_235 -> V_80 |= V_239 | V_240 ;
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
V_235 -> V_80 |= V_246 | V_247 ;
break;
default:
return - V_106 ;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_234 * V_235 ,
T_1 * V_255 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_117 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_184 = - V_155 ;
switch ( V_235 -> V_235 ) {
case V_256 :
V_235 -> V_80 = V_9 -> V_149 ;
V_184 = 0 ;
break;
case V_257 :
V_184 = F_75 ( V_8 , V_235 ) ;
break;
case V_258 :
V_184 = 0 ;
break;
case V_259 :
V_184 = 0 ;
break;
case V_260 :
V_235 -> V_80 = 500 ;
V_184 = 0 ;
default:
break;
}
return V_184 ;
}
static int F_77 ( struct V_7 * V_8 , struct V_234 * V_261 )
{
struct V_11 * V_12 = & V_8 -> V_12 ;
T_4 V_262 = ( T_4 ) F_9 ( V_12 , F_78 ( 0 ) ) |
( ( T_4 ) F_9 ( V_12 , F_78 ( 1 ) ) << 32 ) ;
if ( V_261 -> V_80 & ~ ( V_246 | V_247 |
V_239 | V_240 ) )
return - V_106 ;
if ( ! ( V_261 -> V_80 & V_246 ) ||
! ( V_261 -> V_80 & V_247 ) )
return - V_106 ;
switch ( V_261 -> V_236 ) {
case V_237 :
switch ( V_261 -> V_80 & ( V_239 | V_240 ) ) {
case 0 :
V_262 &= ~ ( ( T_4 ) 1 << V_263 ) ;
break;
case ( V_239 | V_240 ) :
V_262 |= ( ( T_4 ) 1 << V_263 ) ;
break;
default:
return - V_106 ;
}
break;
case V_248 :
switch ( V_261 -> V_80 & ( V_239 | V_240 ) ) {
case 0 :
V_262 &= ~ ( ( T_4 ) 1 << V_264 ) ;
break;
case ( V_239 | V_240 ) :
V_262 |= ( ( T_4 ) 1 << V_264 ) ;
break;
default:
return - V_106 ;
}
break;
case V_238 :
switch ( V_261 -> V_80 & ( V_239 | V_240 ) ) {
case 0 :
V_262 &=
~ ( ( ( T_4 ) 1 << V_265 ) |
( ( T_4 ) 1 << V_266 ) |
( ( T_4 ) 1 << V_267 ) ) ;
break;
case ( V_239 | V_240 ) :
V_262 |=
( ( ( T_4 ) 1 << V_265 ) |
( ( T_4 ) 1 << V_266 ) |
( ( T_4 ) 1 << V_267 ) ) ;
break;
default:
return - V_106 ;
}
break;
case V_249 :
switch ( V_261 -> V_80 & ( V_239 | V_240 ) ) {
case 0 :
V_262 &=
~ ( ( ( T_4 ) 1 << V_268 ) |
( ( T_4 ) 1 << V_269 ) |
( ( T_4 ) 1 << V_270 ) ) ;
break;
case ( V_239 | V_240 ) :
V_262 |=
( ( ( T_4 ) 1 << V_268 ) |
( ( T_4 ) 1 << V_269 ) |
( ( T_4 ) 1 << V_270 ) ) ;
break;
default:
return - V_106 ;
}
break;
case V_242 :
case V_243 :
case V_244 :
case V_241 :
if ( ( V_261 -> V_80 & V_239 ) ||
( V_261 -> V_80 & V_240 ) )
return - V_106 ;
V_262 |= ( ( T_4 ) 1 << V_271 ) ;
break;
case V_251 :
case V_252 :
case V_253 :
case V_250 :
if ( ( V_261 -> V_80 & V_239 ) ||
( V_261 -> V_80 & V_240 ) )
return - V_106 ;
V_262 |= ( ( T_4 ) 1 << V_272 ) ;
break;
case V_245 :
V_262 |= ( ( T_4 ) 1 << V_271 ) |
( ( T_4 ) 1 << V_267 ) ;
break;
case V_254 :
V_262 |= ( ( T_4 ) 1 << V_272 ) |
( ( T_4 ) 1 << V_270 ) ;
break;
default:
return - V_106 ;
}
F_72 ( V_12 , F_78 ( 0 ) , ( T_1 ) V_262 ) ;
F_72 ( V_12 , F_78 ( 1 ) , ( T_1 ) ( V_262 >> 32 ) ) ;
F_74 ( V_12 ) ;
return 0 ;
}
static int F_79 ( struct V_117 * V_9 ,
struct V_273 * V_274 ,
struct V_275 * V_276 , bool V_277 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_278 * V_279 ;
struct V_280 * V_281 ;
bool V_142 = false ;
int V_184 ;
int V_84 ;
V_281 = (struct V_280 * ) ( V_274 -> V_282 + V_283 ) ;
V_279 = (struct V_278 * ) ( V_274 -> V_282 + V_283
+ sizeof( struct V_280 ) ) ;
V_281 -> V_284 = V_276 -> V_285 . V_286 . V_287 ;
V_281 -> V_288 = V_276 -> V_285 . V_286 . V_289 ;
V_279 -> V_290 = V_276 -> V_285 . V_286 . V_291 ;
V_279 -> V_292 = V_276 -> V_285 . V_286 . V_293 ;
for ( V_84 = V_265 ;
V_84 <= V_294 ; V_84 ++ ) {
V_274 -> V_295 = V_84 ;
V_184 = F_80 ( V_274 , V_8 , V_277 ) ;
if ( V_184 ) {
F_81 ( & V_8 -> V_123 -> V_181 ,
L_22 ,
V_274 -> V_295 , V_184 ) ;
V_142 = true ;
} else {
F_81 ( & V_8 -> V_123 -> V_181 ,
L_23 ,
V_274 -> V_295 , V_184 ) ;
}
}
return V_142 ? - V_155 : 0 ;
}
static int F_82 ( struct V_117 * V_9 ,
struct V_273 * V_274 ,
struct V_275 * V_276 , bool V_277 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_296 * V_297 ;
struct V_280 * V_281 ;
bool V_142 = false ;
int V_184 ;
V_281 = (struct V_280 * ) ( V_274 -> V_282 + V_283 ) ;
V_297 = (struct V_296 * ) ( V_274 -> V_282 + V_283
+ sizeof( struct V_280 ) ) ;
V_281 -> V_288 = V_276 -> V_285 . V_286 . V_289 ;
V_297 -> V_292 = V_276 -> V_285 . V_286 . V_293 ;
V_274 -> V_295 = V_298 ;
V_184 = F_80 ( V_274 , V_8 , V_277 ) ;
if ( V_184 ) {
F_81 ( & V_8 -> V_123 -> V_181 ,
L_22 ,
V_274 -> V_295 , V_184 ) ;
V_142 = true ;
} else {
F_81 ( & V_8 -> V_123 -> V_181 , L_23 ,
V_274 -> V_295 , V_184 ) ;
}
V_281 -> V_284 = V_276 -> V_285 . V_286 . V_287 ;
V_297 -> V_290 = V_276 -> V_285 . V_286 . V_291 ;
V_274 -> V_295 = V_263 ;
V_184 = F_80 ( V_274 , V_8 , V_277 ) ;
if ( V_184 ) {
F_81 ( & V_8 -> V_123 -> V_181 ,
L_22 ,
V_274 -> V_295 , V_184 ) ;
V_142 = true ;
} else {
F_81 ( & V_8 -> V_123 -> V_181 , L_23 ,
V_274 -> V_295 , V_184 ) ;
}
return V_142 ? - V_155 : 0 ;
}
static int F_83 ( struct V_117 * V_9 ,
struct V_273 * V_274 ,
struct V_275 * V_276 , bool V_277 )
{
return - V_155 ;
}
static int F_84 ( struct V_117 * V_9 ,
struct V_273 * V_274 ,
struct V_275 * V_276 , bool V_277 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_280 * V_281 ;
bool V_142 = false ;
int V_184 ;
int V_84 ;
V_281 = (struct V_280 * ) ( V_274 -> V_282 + V_283 ) ;
V_281 -> V_284 = V_276 -> V_285 . V_299 . V_287 ;
V_281 -> V_288 = V_276 -> V_285 . V_299 . V_289 ;
V_281 -> V_300 = V_276 -> V_285 . V_299 . V_301 ;
for ( V_84 = V_271 ;
V_84 <= V_267 ; V_84 ++ ) {
V_274 -> V_295 = V_84 ;
V_184 = F_80 ( V_274 , V_8 , V_277 ) ;
if ( V_184 ) {
F_81 ( & V_8 -> V_123 -> V_181 ,
L_22 ,
V_274 -> V_295 , V_184 ) ;
V_142 = true ;
} else {
F_81 ( & V_8 -> V_123 -> V_181 ,
L_23 ,
V_274 -> V_295 , V_184 ) ;
}
}
return V_142 ? - V_155 : 0 ;
}
static int F_85 ( struct V_117 * V_9 ,
struct V_234 * V_235 , bool V_277 )
{
struct V_273 V_274 ;
int V_184 = - V_106 ;
struct V_7 * V_8 ;
struct V_275 * V_276 =
(struct V_275 * ) & V_235 -> V_302 ;
if ( ! V_9 )
return - V_106 ;
V_8 = V_9 -> V_10 ;
if ( ( V_276 -> V_303 != V_304 ) &&
( V_276 -> V_303 >= V_9 -> V_147 ) )
return - V_106 ;
V_274 . V_282 = F_86 ( V_305 ,
V_110 ) ;
if ( ! V_274 . V_282 ) {
F_81 ( & V_8 -> V_123 -> V_181 , L_24 ) ;
return - V_111 ;
}
V_274 . V_306 = V_276 -> V_303 ;
V_274 . V_307 = 0 ;
V_274 . V_295 = 0 ;
V_274 . V_308 = V_9 -> V_309 ;
V_274 . V_310 = 0 ;
V_274 . V_311 = 0 ;
V_274 . V_312 = 0 ;
V_274 . V_313 = 0 ;
switch ( V_276 -> V_236 & ~ V_314 ) {
case V_237 :
V_184 = F_82 ( V_9 , & V_274 , V_276 , V_277 ) ;
break;
case V_238 :
V_184 = F_79 ( V_9 , & V_274 , V_276 , V_277 ) ;
break;
case V_241 :
V_184 = F_83 ( V_9 , & V_274 , V_276 , V_277 ) ;
break;
case V_245 :
V_184 = F_84 ( V_9 , & V_274 , V_276 , V_277 ) ;
break;
case V_315 :
switch ( V_276 -> V_285 . V_299 . V_301 ) {
case V_316 :
V_184 = F_82 ( V_9 , & V_274 , V_276 , V_277 ) ;
break;
case V_317 :
V_184 = F_79 ( V_9 , & V_274 , V_276 , V_277 ) ;
break;
case V_318 :
V_184 = F_83 ( V_9 , & V_274 , V_276 , V_277 ) ;
break;
default:
V_184 = F_84 ( V_9 , & V_274 , V_276 , V_277 ) ;
break;
}
break;
default:
F_81 ( & V_8 -> V_123 -> V_181 , L_25 ) ;
V_184 = - V_106 ;
}
F_13 ( V_274 . V_282 ) ;
V_274 . V_282 = NULL ;
return V_184 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_234 * V_235 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_117 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_184 = - V_155 ;
switch ( V_235 -> V_235 ) {
case V_319 :
V_184 = F_77 ( V_8 , V_235 ) ;
break;
case V_320 :
V_184 = F_85 ( V_9 , V_235 , true ) ;
break;
case V_321 :
V_184 = F_85 ( V_9 , V_235 , false ) ;
break;
default:
break;
}
return V_184 ;
}
void F_88 ( struct V_1 * V_2 )
{
F_89 ( V_2 , & V_322 ) ;
}
