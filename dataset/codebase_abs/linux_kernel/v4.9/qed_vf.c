static void * F_1 ( struct V_1 * V_2 , T_1 type , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void * V_7 ;
F_2 ( & ( V_5 -> V_8 ) ) ;
F_3 ( V_2 ,
V_9 ,
L_1 ,
type ) ;
V_5 -> V_10 = ( V_11 * ) V_5 -> V_12 ;
memset ( V_5 -> V_12 , 0 , sizeof( union V_13 ) ) ;
memset ( V_5 -> V_14 , 0 , sizeof( union V_15 ) ) ;
V_7 = F_4 ( V_2 , & V_5 -> V_10 , type , V_3 ) ;
( (struct V_16 * ) V_7 ) -> V_17 =
( V_18 ) V_5 -> V_19 ;
return V_7 ;
}
static void F_5 ( struct V_1 * V_2 , int V_20 )
{
union V_15 * V_21 = V_2 -> V_6 -> V_14 ;
F_3 ( V_2 , V_9 ,
L_2 ,
V_20 , V_21 -> V_22 . V_23 . V_24 ) ;
F_6 ( & ( V_2 -> V_6 -> V_8 ) ) ;
}
static int F_7 ( struct V_1 * V_2 , V_11 * V_25 , T_2 V_26 )
{
union V_13 * V_27 = V_2 -> V_6 -> V_12 ;
struct V_28 V_29 ;
struct V_30 * V_31 ;
int V_32 = 0 , time = 100 ;
V_31 = (struct V_30 * ) V_33 ;
F_8 ( V_2 , V_27 ) ;
V_26 += sizeof( struct V_34 ) ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 . V_35 = 1 ;
F_3 ( V_2 ,
V_9 ,
L_3 ,
F_9 ( V_2 -> V_36 . V_37 ,
V_38 ) ,
F_10 ( V_2 -> V_6 -> V_39 ) ,
F_11 ( V_2 -> V_6 -> V_39 ) ,
& V_31 -> V_40 . V_41 ,
* ( ( T_2 * ) & V_29 ) , & V_31 -> V_29 ) ;
F_12 ( V_2 ,
( V_42 ) & V_31 -> V_40 . V_41 . V_43 ,
F_11 ( V_2 -> V_6 -> V_39 ) ) ;
F_12 ( V_2 ,
( V_42 ) & V_31 -> V_40 . V_41 . V_44 ,
F_10 ( V_2 -> V_6 -> V_39 ) ) ;
F_13 () ;
F_12 ( V_2 , ( V_42 ) & V_31 -> V_29 , * ( ( T_2 * ) & V_29 ) ) ;
while ( ( ! * V_25 ) && time ) {
F_14 ( 25 ) ;
time -- ;
}
if ( ! * V_25 ) {
F_3 ( V_2 , V_9 ,
L_4 ,
V_27 -> V_45 . V_46 . type ) ;
V_32 = - V_47 ;
} else {
F_3 ( V_2 , V_9 ,
L_5 ,
* V_25 , V_27 -> V_45 . V_46 . type ) ;
}
return V_32 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_48 * V_27 ,
struct V_49 * V_50 )
{
F_3 ( V_2 ,
V_9 ,
L_6 ,
V_27 -> V_51 ,
V_50 -> V_51 ,
V_27 -> V_51 ,
V_50 -> V_52 ,
V_27 -> V_53 ,
V_50 -> V_53 ,
V_27 -> V_54 ,
V_50 -> V_54 ,
V_27 -> V_55 ,
V_50 -> V_55 ,
V_27 -> V_56 , V_50 -> V_56 ) ;
V_27 -> V_52 = V_50 -> V_52 ;
V_27 -> V_51 = V_50 -> V_51 ;
V_27 -> V_53 = V_50 -> V_53 ;
V_27 -> V_54 = V_50 -> V_54 ;
V_27 -> V_55 = V_50 -> V_55 ;
V_27 -> V_56 = V_50 -> V_56 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_57 * V_21 = & V_5 -> V_14 -> V_58 ;
struct V_59 * V_60 = & V_21 -> V_60 ;
struct V_48 * V_61 ;
bool V_62 = false ;
struct V_63 * V_64 ;
int V_32 = 0 , V_65 = 0 ;
V_64 = F_1 ( V_2 , V_66 , sizeof( * V_64 ) ) ;
V_61 = & V_64 -> V_67 ;
V_64 -> V_68 . V_69 = V_2 -> V_36 . V_69 ;
V_61 -> V_51 = V_70 ;
V_61 -> V_52 = V_70 ;
V_61 -> V_53 = V_70 ;
V_61 -> V_54 = V_71 ;
V_61 -> V_55 = V_72 ;
V_64 -> V_68 . V_73 = V_74 ;
V_64 -> V_68 . V_75 = V_76 ;
V_64 -> V_68 . V_77 = V_78 ;
V_64 -> V_68 . V_79 = V_80 ;
V_64 -> V_68 . V_81 = V_82 ;
V_64 -> V_68 . V_83 = V_84 ;
V_64 -> V_68 . V_85 = V_86 ;
V_64 -> V_68 . V_87 |= V_88 ;
V_64 -> V_89 = V_5 -> V_90 . V_91 ;
V_64 -> V_92 = V_5 -> V_90 . V_93 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_94 , sizeof( struct V_34 ) ) ;
while ( ! V_62 ) {
F_3 ( V_2 ,
V_9 , L_7 ) ;
memset ( V_5 -> V_14 , 0 , sizeof( union V_15 ) ) ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
return V_32 ;
memcpy ( & V_5 -> V_58 , V_21 , sizeof( V_5 -> V_58 ) ) ;
V_65 ++ ;
if ( V_21 -> V_23 . V_24 == V_95 ) {
if ( ! ( V_21 -> V_60 . V_87 &
V_96 ) ) {
V_64 -> V_68 . V_87 |=
V_97 ;
}
F_3 ( V_2 , V_9 , L_8 ) ;
V_62 = true ;
} else if ( V_21 -> V_23 . V_24 == V_98 &&
V_65 < V_99 ) {
F_15 ( V_2 , V_61 ,
& V_21 -> V_100 ) ;
} else if ( V_21 -> V_23 . V_24 == V_101 ) {
if ( V_60 -> V_102 &&
( V_60 -> V_102 != V_84 ) ) {
F_17 ( V_2 ,
L_9 ,
V_60 -> V_102 ,
V_60 -> V_103 ,
V_84 ,
V_86 ,
V_60 -> V_102 ) ;
V_32 = - V_104 ;
goto exit;
}
if ( ! V_60 -> V_102 ) {
if ( V_64 -> V_68 . V_87 &
V_97 ) {
F_17 ( V_2 ,
L_10 ) ;
V_32 = - V_104 ;
goto exit;
} else {
F_18 ( V_2 ,
L_11 ) ;
V_64 -> V_68 . V_87 |=
V_97 ;
continue;
}
}
F_17 ( V_2 , L_12 ) ;
V_32 = - V_104 ;
goto exit;
} else {
F_19 ( V_2 ,
L_13 ,
V_21 -> V_23 . V_24 ) ;
V_32 = - V_105 ;
goto exit;
}
}
if ( V_64 -> V_68 . V_87 & V_97 )
V_5 -> V_106 = true ;
V_5 -> V_90 . V_93 = V_21 -> V_92 ;
V_2 -> V_107 -> type = V_21 -> V_60 . V_108 ;
V_2 -> V_107 -> V_109 = V_21 -> V_60 . V_109 ;
V_2 -> V_107 -> V_110 = V_60 -> V_110 & 0xffff ;
if ( F_20 ( V_2 ) ) {
if ( V_21 -> V_60 . V_87 & V_111 ) {
F_17 ( V_2 , L_14 ) ;
V_2 -> V_107 -> V_112 = 2 ;
}
}
if ( ! V_5 -> V_106 &&
V_86 &&
( V_21 -> V_60 . V_103 < V_86 ) ) {
F_18 ( V_2 ,
L_15 ,
V_84 , V_21 -> V_60 . V_103 ) ;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
T_2 V_113 ;
if ( F_20 ( V_2 ) )
V_2 -> V_107 -> V_112 = 1 ;
V_2 -> V_114 = ( V_11 V_115 * ) V_2 -> V_116 +
V_117 ;
V_113 = V_118 ;
V_2 -> V_36 . V_69 = ( T_1 ) F_22 ( V_2 , V_113 ) ;
V_113 = V_119 ;
V_2 -> V_36 . V_37 = F_22 ( V_2 , V_113 ) ;
V_5 = F_23 ( sizeof( * V_5 ) , V_120 ) ;
if ( ! V_5 )
return - V_121 ;
V_5 -> V_12 = F_24 ( & V_2 -> V_107 -> V_122 -> V_123 ,
sizeof( union V_13 ) ,
& V_5 -> V_39 ,
V_120 ) ;
if ( ! V_5 -> V_12 )
goto V_124;
V_5 -> V_14 = F_24 ( & V_2 -> V_107 -> V_122 -> V_123 ,
sizeof( union V_15 ) ,
& V_5 -> V_19 ,
V_120 ) ;
if ( ! V_5 -> V_14 )
goto V_125;
F_3 ( V_2 ,
V_9 ,
L_16 ,
V_5 -> V_12 ,
( V_18 ) V_5 -> V_39 ,
V_5 -> V_14 , ( V_18 ) V_5 -> V_19 ) ;
V_5 -> V_90 . V_93 = sizeof( struct V_126 ) ;
V_5 -> V_90 . V_127 = F_24 ( & V_2 -> V_107 -> V_122 -> V_123 ,
V_5 -> V_90 . V_93 ,
& V_5 -> V_90 . V_91 ,
V_120 ) ;
F_3 ( V_2 , V_9 ,
L_17 ,
V_5 -> V_90 . V_127 ,
( V_18 ) V_5 -> V_90 . V_91 , V_5 -> V_90 . V_93 ) ;
F_25 ( & V_5 -> V_8 ) ;
V_2 -> V_6 = V_5 ;
V_2 -> V_36 . V_128 = V_129 ;
return F_16 ( V_2 ) ;
V_125:
F_26 ( & V_2 -> V_107 -> V_122 -> V_123 ,
sizeof( union V_13 ) ,
V_5 -> V_12 , V_5 -> V_39 ) ;
V_124:
F_27 ( V_5 ) ;
return - V_121 ;
}
int F_28 ( struct V_1 * V_2 ,
V_11 V_130 ,
T_1 V_131 ,
V_11 V_132 ,
T_1 V_133 ,
T_3 V_134 ,
T_3 V_135 ,
T_1 V_136 , void V_115 * * V_137 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_138 * V_21 ;
struct V_139 * V_64 ;
int V_32 ;
V_64 = F_1 ( V_2 , V_140 , sizeof( * V_64 ) ) ;
V_64 -> V_130 = V_130 ;
V_64 -> V_135 = V_135 ;
V_64 -> V_136 = V_136 ;
V_64 -> V_141 = V_134 ;
V_64 -> V_142 = V_131 ;
V_64 -> V_132 = V_132 ;
V_64 -> V_133 = V_133 ;
V_64 -> V_143 = - 1 ;
if ( V_137 && V_5 -> V_106 ) {
V_11 V_144 = V_5 -> V_58 . V_100 . V_144 [ V_130 ] ;
T_2 V_145 = 0 ;
* V_137 = ( V_11 V_115 * ) V_2 -> V_116 +
F_29 ( V_2 -> V_107 ) +
V_144 * V_146 ;
F_30 ( V_2 , * V_137 , sizeof( T_2 ) ,
( T_2 * ) ( & V_145 ) ) ;
}
F_4 ( V_2 , & V_5 -> V_10 ,
V_94 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_147 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_95 ) {
V_32 = - V_104 ;
goto exit;
}
if ( V_137 && ! V_5 -> V_106 ) {
T_2 V_145 = 0 ;
* V_137 = ( V_11 V_115 * ) V_2 -> V_116 + V_21 -> V_10 ;
F_3 ( V_2 , V_9 ,
L_18 ,
V_130 , * V_137 , V_21 -> V_10 ) ;
F_30 ( V_2 , * V_137 , sizeof( T_2 ) ,
( T_2 * ) & V_145 ) ;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_130 , bool V_148 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_149 * V_64 ;
struct V_150 * V_21 ;
int V_32 ;
V_64 = F_1 ( V_2 , V_151 , sizeof( * V_64 ) ) ;
V_64 -> V_130 = V_130 ;
V_64 -> V_51 = 1 ;
V_64 -> V_148 = V_148 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_94 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_95 ) {
V_32 = - V_104 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_32 ( struct V_1 * V_2 ,
T_1 V_152 ,
T_1 V_131 ,
V_11 V_132 ,
T_3 V_153 ,
T_1 V_154 , void V_115 * * V_155 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_138 * V_21 ;
struct V_156 * V_64 ;
int V_32 ;
V_64 = F_1 ( V_2 , V_157 , sizeof( * V_64 ) ) ;
V_64 -> V_158 = V_152 ;
V_64 -> V_153 = V_153 ;
V_64 -> V_154 = V_154 ;
V_64 -> V_142 = V_131 ;
V_64 -> V_132 = V_132 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_94 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_147 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_95 ) {
V_32 = - V_104 ;
goto exit;
}
if ( V_155 ) {
if ( ! V_5 -> V_106 ) {
* V_155 = ( V_11 V_115 * ) V_2 -> V_114 +
V_21 -> V_10 ;
} else {
V_11 V_159 = V_5 -> V_58 . V_100 . V_159 [ V_152 ] ;
T_2 V_160 ;
V_160 = F_33 ( V_159 , V_161 ) ;
* V_155 = ( V_11 V_115 * ) V_2 -> V_114 +
V_160 ;
}
F_3 ( V_2 , V_9 ,
L_19 ,
V_152 , * V_155 , V_21 -> V_10 ) ;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_34 ( struct V_1 * V_2 , T_1 V_158 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_162 * V_64 ;
struct V_150 * V_21 ;
int V_32 ;
V_64 = F_1 ( V_2 , V_163 , sizeof( * V_64 ) ) ;
V_64 -> V_158 = V_158 ;
V_64 -> V_52 = 1 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_94 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_95 ) {
V_32 = - V_104 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_35 ( struct V_1 * V_2 ,
V_11 V_164 ,
T_1 V_165 ,
V_11 V_166 ,
enum V_167 V_168 ,
V_11 V_169 , V_11 V_170 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_171 * V_64 ;
struct V_150 * V_21 ;
int V_32 , V_172 ;
V_64 = F_1 ( V_2 , V_173 , sizeof( * V_64 ) ) ;
V_64 -> V_165 = V_165 ;
V_64 -> V_164 = V_164 ;
V_64 -> V_166 = V_166 ;
V_64 -> V_168 = V_168 ;
V_64 -> V_169 = V_169 ;
V_64 -> V_170 = V_170 ;
for ( V_172 = 0 ; V_172 < V_2 -> V_6 -> V_58 . V_100 . V_53 ; V_172 ++ )
if ( V_2 -> V_174 [ V_172 ] )
V_64 -> V_175 [ V_172 ] = V_2 -> V_174 [ V_172 ] -> V_176 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_94 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_95 ) {
V_32 = - V_104 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_150 * V_21 = & V_5 -> V_14 -> V_22 ;
int V_32 ;
F_1 ( V_2 , V_177 ,
sizeof( struct V_16 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_94 , sizeof( struct V_34 ) ) ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_95 ) {
V_32 = - V_104 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
static bool
F_37 ( struct V_1 * V_2 ,
struct V_178 * V_179 ,
T_1 V_180 )
{
switch ( V_180 ) {
case V_181 :
return ! ! ( V_179 -> V_182 ||
V_179 -> V_183 ) ;
case V_184 :
return ! ! V_179 -> V_185 ;
case V_186 :
return ! ! V_179 -> V_187 ;
case V_188 :
return ! ! V_179 -> V_189 ;
case V_190 :
return ! ! V_179 -> V_191 ;
case V_192 :
return ! ! ( V_179 -> V_193 . V_194 ||
V_179 -> V_193 . V_195 ) ;
case V_196 :
return ! ! V_179 -> V_197 ;
case V_198 :
return ! ! V_179 -> V_199 ;
default:
F_18 ( V_2 , L_20 ,
V_180 ) ;
return false ;
}
}
static void
F_38 ( struct V_1 * V_2 ,
struct V_178 * V_179 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_150 * V_50 ;
T_1 V_180 ;
for ( V_180 = V_181 ;
V_180 < V_200 ; V_180 ++ ) {
if ( ! F_37 ( V_2 , V_179 , V_180 ) )
continue;
V_50 = (struct V_150 * )
F_39 ( V_2 , V_5 -> V_14 ,
V_180 ) ;
if ( V_50 && V_50 -> V_23 . V_24 )
F_3 ( V_2 , V_9 ,
L_21 ,
V_180 ,
( V_50 && V_50 -> V_23 . V_24 ) ? L_22
: L_23 ) ;
}
}
int F_40 ( struct V_1 * V_2 ,
struct V_178 * V_201 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_202 * V_64 ;
struct V_150 * V_21 ;
V_11 V_203 , V_204 ;
T_2 V_26 = 0 ;
T_1 V_93 , V_180 ;
int V_32 ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_26 = sizeof( * V_21 ) ;
V_203 = V_201 -> V_182 ;
V_204 = V_201 -> V_183 ;
F_1 ( V_2 , V_205 , sizeof( * V_64 ) ) ;
if ( V_203 || V_204 ) {
struct V_206 * V_207 ;
V_93 = sizeof( struct V_206 ) ;
V_207 = F_4 ( V_2 , & V_5 -> V_10 ,
V_181 ,
V_93 ) ;
V_26 += sizeof( struct V_150 ) ;
if ( V_203 ) {
V_207 -> V_203 = V_203 ;
V_207 -> V_208 = V_201 -> V_209 ;
}
if ( V_204 ) {
V_207 -> V_204 = V_204 ;
V_207 -> V_210 = V_201 -> V_211 ;
}
}
if ( V_201 -> V_185 ) {
struct V_212 * V_213 ;
V_93 = sizeof( struct V_212 ) ;
V_180 = V_184 ;
V_213 = F_4 ( V_2 , & V_5 -> V_10 ,
V_180 , V_93 ) ;
V_26 += sizeof( struct V_150 ) ;
V_213 -> V_214 = V_201 -> V_215 ;
}
if ( V_201 -> V_191 ) {
struct V_216 * V_217 ;
V_93 = sizeof( struct V_216 ) ;
V_217 = F_4 ( V_2 , & V_5 -> V_10 ,
V_190 , V_93 ) ;
V_26 += sizeof( struct V_150 ) ;
memcpy ( V_217 -> V_218 , V_201 -> V_218 ,
sizeof( unsigned long ) * V_219 ) ;
}
V_203 = V_201 -> V_193 . V_194 ;
V_204 = V_201 -> V_193 . V_195 ;
if ( V_203 || V_204 ) {
struct V_220 * V_221 ;
V_180 = V_192 ;
V_93 = sizeof( struct V_220 ) ;
V_221 = F_4 ( V_2 , & V_5 -> V_10 , V_180 , V_93 ) ;
V_26 += sizeof( struct V_150 ) ;
if ( V_203 ) {
V_221 -> V_222 = V_203 ;
V_221 -> V_223 =
V_201 -> V_193 . V_223 ;
}
if ( V_204 ) {
V_221 -> V_224 = V_204 ;
V_221 -> V_225 =
V_201 -> V_193 . V_225 ;
}
}
if ( V_201 -> V_197 ) {
struct V_226 * V_197 = V_201 -> V_197 ;
struct V_227 * V_228 ;
V_93 = sizeof( struct V_227 ) ;
V_228 = F_4 ( V_2 ,
& V_5 -> V_10 ,
V_196 , V_93 ) ;
V_26 += sizeof( struct V_150 ) ;
if ( V_197 -> V_229 )
V_228 -> V_230 |=
V_231 ;
if ( V_197 -> V_232 )
V_228 -> V_230 |=
V_233 ;
if ( V_197 -> V_234 )
V_228 -> V_230 |=
V_235 ;
if ( V_197 -> V_236 )
V_228 -> V_230 |= V_237 ;
V_228 -> V_238 = V_197 -> V_238 ;
V_228 -> V_239 = V_197 -> V_239 ;
V_228 -> V_240 = V_197 -> V_240 ;
memcpy ( V_228 -> V_241 , V_197 -> V_241 ,
sizeof( V_197 -> V_241 ) ) ;
memcpy ( V_228 -> V_242 , V_197 -> V_242 ,
sizeof( V_197 -> V_242 ) ) ;
}
if ( V_201 -> V_189 ) {
struct V_243 * V_244 ;
V_93 = sizeof( struct V_243 ) ;
V_180 = V_188 ;
V_244 = F_4 ( V_2 , & V_5 -> V_10 , V_180 , V_93 ) ;
V_26 += sizeof( struct V_150 ) ;
V_244 -> V_245 = V_201 -> V_245 ;
V_244 -> V_189 =
V_201 -> V_189 ;
}
F_4 ( V_2 , & V_5 -> V_10 ,
V_94 , sizeof( struct V_34 ) ) ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , V_26 ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_95 ) {
V_32 = - V_104 ;
goto exit;
}
F_38 ( V_2 , V_201 ) ;
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_150 * V_21 ;
struct V_16 * V_64 ;
int V_32 ;
V_64 = F_1 ( V_2 , V_246 , sizeof( * V_64 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_94 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_95 ) {
V_32 = - V_105 ;
goto exit;
}
V_2 -> V_247 = 0 ;
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_150 * V_21 ;
struct V_16 * V_64 ;
T_2 V_93 ;
int V_32 ;
V_64 = F_1 ( V_2 , V_248 , sizeof( * V_64 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_94 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( ! V_32 && V_21 -> V_23 . V_24 != V_95 )
V_32 = - V_105 ;
F_5 ( V_2 , V_32 ) ;
V_2 -> V_247 = 0 ;
if ( V_5 -> V_12 )
F_26 ( & V_2 -> V_107 -> V_122 -> V_123 ,
sizeof( union V_13 ) ,
V_5 -> V_12 ,
V_5 -> V_39 ) ;
if ( V_5 -> V_14 )
F_26 ( & V_2 -> V_107 -> V_122 -> V_123 ,
sizeof( union V_15 ) ,
V_5 -> V_14 , V_5 -> V_19 ) ;
if ( V_5 -> V_90 . V_127 ) {
V_93 = sizeof( struct V_126 ) ;
F_26 ( & V_2 -> V_107 -> V_122 -> V_123 ,
V_93 ,
V_5 -> V_90 . V_127 , V_5 -> V_90 . V_91 ) ;
}
F_27 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
return V_32 ;
}
void F_43 ( struct V_1 * V_2 ,
struct V_249 * V_250 )
{
struct V_178 V_251 ;
int V_172 ;
memset ( & V_251 , 0 , sizeof( V_251 ) ) ;
V_251 . V_191 = 1 ;
if ( V_250 -> V_252 == V_253 ) {
for ( V_172 = 0 ; V_172 < V_250 -> V_254 ; V_172 ++ ) {
T_2 V_255 ;
V_255 = F_44 ( V_250 -> V_256 [ V_172 ] ) ;
F_45 ( V_255 , V_251 . V_218 ) ;
}
}
F_40 ( V_2 , & V_251 ) ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_257 * V_258 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_259 * V_64 ;
struct V_150 * V_21 ;
int V_32 ;
V_64 = F_1 ( V_2 , V_260 , sizeof( * V_64 ) ) ;
V_64 -> V_252 = ( V_11 ) V_258 -> V_252 ;
V_64 -> type = ( V_11 ) V_258 -> type ;
memcpy ( V_64 -> V_256 , V_258 -> V_256 , V_261 ) ;
V_64 -> V_262 = V_258 -> V_262 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_94 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_95 ) {
V_32 = - V_105 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_150 * V_21 = & V_5 -> V_14 -> V_22 ;
int V_32 ;
F_1 ( V_2 , V_263 ,
sizeof( struct V_16 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_94 , sizeof( struct V_34 ) ) ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_95 ) {
V_32 = - V_104 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
T_1 F_48 ( struct V_1 * V_2 , T_1 V_264 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 ) {
F_17 ( V_2 , L_24 ) ;
return 0 ;
}
return V_5 -> V_58 . V_100 . V_265 [ V_264 ] . V_266 ;
}
int F_49 ( struct V_1 * V_2 , V_11 * V_267 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_126 V_268 ;
T_2 V_269 , V_270 ;
V_270 = sizeof( V_5 -> V_90 . V_127 -> V_269 ) ;
* V_267 = 0 ;
memcpy ( & V_268 , V_5 -> V_90 . V_127 , V_5 -> V_90 . V_93 ) ;
if ( V_268 . V_271 == V_5 -> V_272 . V_271 )
return 0 ;
V_269 = F_50 ( 0 , ( V_11 * ) & V_268 + V_270 ,
V_5 -> V_90 . V_93 - V_270 ) ;
if ( V_269 != V_268 . V_269 )
return - V_105 ;
memcpy ( & V_5 -> V_272 , & V_268 , V_5 -> V_90 . V_93 ) ;
F_3 ( V_2 , V_9 ,
L_25 , V_268 . V_271 ) ;
* V_267 = 1 ;
return 0 ;
}
void F_51 ( struct V_1 * V_2 ,
struct V_273 * V_201 ,
struct V_126 * V_274 )
{
memset ( V_201 , 0 , sizeof( * V_201 ) ) ;
V_201 -> V_275 . V_276 = V_274 -> V_277 ;
V_201 -> V_275 . V_278 = V_274 -> V_279 ;
V_201 -> V_275 . V_280 = V_274 -> V_281 ;
V_201 -> V_282 . V_276 = V_274 -> V_283 ;
V_201 -> V_282 . V_284 = V_274 -> V_285 ;
V_201 -> V_282 . V_286 = V_274 -> V_287 ;
V_201 -> V_288 = V_274 -> V_289 ;
}
void F_52 ( struct V_1 * V_2 ,
struct V_273 * V_290 )
{
F_51 ( V_2 , V_290 ,
& ( V_2 -> V_6 -> V_272 ) ) ;
}
void F_53 ( struct V_1 * V_2 ,
struct V_291 * V_292 ,
struct V_126 * V_274 )
{
memset ( V_292 , 0 , sizeof( * V_292 ) ) ;
V_292 -> V_293 = V_274 -> V_293 ;
V_292 -> V_275 = V_274 -> V_275 ;
V_292 -> V_294 = V_274 -> V_294 ;
V_292 -> V_295 = V_274 -> V_276 ;
V_292 -> V_296 = V_274 -> V_297 ;
V_292 -> V_298 = V_274 -> V_298 ;
V_292 -> V_299 = V_274 -> V_299 ;
V_292 -> V_300 = V_274 -> V_300 ;
V_292 -> V_301 = V_274 -> V_301 ;
V_292 -> V_302 = V_274 -> V_302 ;
V_292 -> V_303 = V_274 -> V_303 ;
V_292 -> V_304 = V_274 -> V_304 ;
}
void F_54 ( struct V_1 * V_2 ,
struct V_291 * V_305 )
{
F_53 ( V_2 , V_305 ,
& ( V_2 -> V_6 -> V_272 ) ) ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_306 * V_307 ,
struct V_126 * V_274 )
{
memset ( V_307 , 0 , sizeof( * V_307 ) ) ;
V_307 -> V_308 = V_274 -> V_309 ;
}
void F_56 ( struct V_1 * V_2 ,
struct V_306 * V_307 )
{
F_55 ( V_2 , V_307 ,
& ( V_2 -> V_6 -> V_272 ) ) ;
}
void F_57 ( struct V_1 * V_2 , V_11 * V_51 )
{
* V_51 = V_2 -> V_6 -> V_58 . V_100 . V_51 ;
}
void F_58 ( struct V_1 * V_2 , V_11 * V_310 )
{
memcpy ( V_310 ,
V_2 -> V_6 -> V_58 . V_60 . V_310 , V_261 ) ;
}
void F_59 ( struct V_1 * V_2 , V_11 * V_55 )
{
struct V_4 * V_311 ;
V_311 = V_2 -> V_6 ;
* V_55 = V_311 -> V_58 . V_100 . V_55 ;
}
bool F_60 ( struct V_1 * V_2 , V_11 * V_256 )
{
struct V_126 * V_90 ;
V_90 = & V_2 -> V_6 -> V_272 ;
if ( ! ( V_90 -> V_312 & ( 1 << V_313 ) ) )
return true ;
if ( F_61 ( V_90 -> V_256 , V_256 ) )
return false ;
return false ;
}
static bool F_62 ( struct V_1 * V_314 ,
V_11 * V_315 , V_11 * V_316 )
{
struct V_126 * V_90 ;
V_90 = & V_314 -> V_6 -> V_272 ;
if ( V_90 -> V_312 & ( 1 << V_313 ) ) {
if ( V_316 )
* V_316 = 1 ;
} else if ( V_90 -> V_312 & ( 1 << V_317 ) ) {
if ( V_316 )
* V_316 = 0 ;
} else {
return false ;
}
F_63 ( V_315 , V_90 -> V_256 ) ;
return true ;
}
void F_64 ( struct V_1 * V_2 ,
T_1 * V_75 , T_1 * V_77 ,
T_1 * V_318 , T_1 * V_319 )
{
struct V_59 * V_320 ;
V_320 = & V_2 -> V_6 -> V_58 . V_60 ;
* V_75 = V_320 -> V_75 ;
* V_77 = V_320 -> V_77 ;
* V_318 = V_320 -> V_318 ;
* V_319 = V_320 -> V_319 ;
}
static void F_65 ( struct V_1 * V_314 )
{
struct V_321 * V_322 = V_314 -> V_107 -> V_323 . V_324 ;
V_11 V_256 [ V_261 ] , V_325 , V_326 ;
void * V_327 = V_314 -> V_107 -> V_328 ;
V_325 = F_62 ( V_314 , V_256 ,
& V_326 ) ;
if ( V_325 && V_326 && V_327 )
V_322 -> V_329 ( V_327 , V_256 ) ;
F_66 ( V_314 ) ;
}
void F_67 ( struct V_330 * V_331 )
{
struct V_1 * V_314 = F_68 ( V_331 , struct V_1 ,
V_332 . V_331 ) ;
V_11 V_333 = 0 ;
if ( F_69 ( V_334 , & V_314 -> V_335 ) )
return;
F_49 ( V_314 , & V_333 ) ;
if ( V_333 )
F_65 ( V_314 ) ;
F_70 ( V_314 -> V_336 , & V_314 -> V_332 , V_337 ) ;
}
