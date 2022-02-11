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
F_15 ( V_2 ,
L_4 ,
V_27 -> V_45 . V_46 . type ) ;
V_32 = - V_47 ;
} else {
if ( ( * V_25 != V_48 ) &&
( * V_25 != V_49 ) )
F_15 ( V_2 ,
L_5 ,
* V_25 , V_27 -> V_45 . V_46 . type ) ;
else
F_3 ( V_2 , V_9 ,
L_5 ,
* V_25 , V_27 -> V_45 . V_46 . type ) ;
}
return V_32 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_52 * V_53 ;
if ( ! ( V_5 -> V_54 . V_55 . V_56 &
V_57 ) )
return;
V_53 = F_4 ( V_2 , & V_5 -> V_10 ,
V_58 , sizeof( * V_53 ) ) ;
V_53 -> V_59 = V_51 -> V_60 ;
}
int F_17 ( struct V_1 * V_2 , bool V_61 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_62 * V_21 ;
struct V_16 * V_63 ;
T_2 V_64 ;
int V_32 ;
V_63 = F_1 ( V_2 , V_65 , sizeof( * V_63 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_66 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( ! V_32 && V_21 -> V_23 . V_24 != V_48 )
V_32 = - V_67 ;
F_5 ( V_2 , V_32 ) ;
if ( ! V_61 )
return V_32 ;
V_2 -> V_68 = 0 ;
if ( V_5 -> V_12 )
F_18 ( & V_2 -> V_69 -> V_70 -> V_71 ,
sizeof( union V_13 ) ,
V_5 -> V_12 ,
V_5 -> V_39 ) ;
if ( V_5 -> V_14 )
F_18 ( & V_2 -> V_69 -> V_70 -> V_71 ,
sizeof( union V_15 ) ,
V_5 -> V_14 , V_5 -> V_19 ) ;
if ( V_5 -> V_72 . V_73 ) {
V_64 = sizeof( struct V_74 ) ;
F_18 ( & V_2 -> V_69 -> V_70 -> V_71 ,
V_64 ,
V_5 -> V_72 . V_73 , V_5 -> V_72 . V_75 ) ;
}
F_19 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
return V_32 ;
}
int F_20 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , true ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_76 * V_27 ,
struct V_77 * V_78 )
{
F_3 ( V_2 ,
V_9 ,
L_6 ,
V_27 -> V_79 ,
V_78 -> V_79 ,
V_27 -> V_79 ,
V_78 -> V_80 ,
V_27 -> V_81 ,
V_78 -> V_81 ,
V_27 -> V_82 ,
V_78 -> V_82 ,
V_27 -> V_83 ,
V_78 -> V_83 ,
V_27 -> V_84 ,
V_78 -> V_84 , V_27 -> V_85 , V_78 -> V_85 ) ;
V_27 -> V_80 = V_78 -> V_80 ;
V_27 -> V_79 = V_78 -> V_79 ;
V_27 -> V_81 = V_78 -> V_81 ;
V_27 -> V_82 = V_78 -> V_82 ;
V_27 -> V_83 = V_78 -> V_83 ;
V_27 -> V_84 = V_78 -> V_84 ;
V_27 -> V_85 = V_78 -> V_85 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_86 * V_21 = & V_5 -> V_14 -> V_54 ;
struct V_87 * V_55 = & V_21 -> V_55 ;
struct V_76 * V_88 ;
bool V_89 = false ;
struct V_90 * V_63 ;
int V_32 = 0 , V_91 = 0 ;
V_63 = F_1 ( V_2 , V_92 , sizeof( * V_63 ) ) ;
V_88 = & V_63 -> V_93 ;
V_63 -> V_94 . V_95 = V_2 -> V_36 . V_95 ;
V_88 -> V_79 = V_96 ;
V_88 -> V_80 = V_96 ;
V_88 -> V_81 = V_96 ;
V_88 -> V_82 = V_97 ;
V_88 -> V_83 = V_98 ;
V_88 -> V_85 = V_99 ;
V_63 -> V_94 . V_100 = V_101 ;
V_63 -> V_94 . V_102 = V_103 ;
V_63 -> V_94 . V_104 = V_105 ;
V_63 -> V_94 . V_106 = V_107 ;
V_63 -> V_94 . V_108 = V_109 ;
V_63 -> V_94 . V_110 = V_111 ;
V_63 -> V_94 . V_112 = V_113 ;
V_63 -> V_94 . V_56 |= V_114 ;
if ( V_5 -> V_115 ) {
V_63 -> V_94 . V_56 |= V_116 |
V_117 ;
V_88 -> V_85 = V_118 ;
}
V_63 -> V_119 = V_5 -> V_72 . V_75 ;
V_63 -> V_120 = V_5 -> V_72 . V_64 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_66 , sizeof( struct V_34 ) ) ;
while ( ! V_89 ) {
F_3 ( V_2 ,
V_9 , L_7 ) ;
memset ( V_5 -> V_14 , 0 , sizeof( union V_15 ) ) ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
memcpy ( & V_5 -> V_54 , V_21 , sizeof( V_5 -> V_54 ) ) ;
V_91 ++ ;
if ( V_21 -> V_23 . V_24 == V_48 ) {
if ( ! ( V_21 -> V_55 . V_56 &
V_121 ) ) {
V_63 -> V_94 . V_56 |=
V_122 ;
}
F_3 ( V_2 , V_9 , L_8 ) ;
V_89 = true ;
} else if ( V_21 -> V_23 . V_24 == V_49 &&
V_91 < V_123 ) {
F_21 ( V_2 , V_88 ,
& V_21 -> V_124 ) ;
} else if ( V_21 -> V_23 . V_24 == V_125 ) {
if ( V_55 -> V_126 &&
( V_55 -> V_126 != V_111 ) ) {
F_15 ( V_2 ,
L_9 ,
V_55 -> V_126 ,
V_55 -> V_127 ,
V_111 ,
V_113 ,
V_55 -> V_126 ) ;
V_32 = - V_128 ;
goto exit;
}
if ( ! V_55 -> V_126 ) {
if ( V_63 -> V_94 . V_56 &
V_122 ) {
F_15 ( V_2 ,
L_10 ) ;
V_32 = - V_128 ;
goto exit;
} else {
F_23 ( V_2 ,
L_11 ) ;
V_63 -> V_94 . V_56 |=
V_122 ;
continue;
}
}
F_15 ( V_2 , L_12 ) ;
V_32 = - V_128 ;
goto exit;
} else {
F_24 ( V_2 ,
L_13 ,
V_21 -> V_23 . V_24 ) ;
V_32 = - V_67 ;
goto exit;
}
}
if ( V_63 -> V_94 . V_56 & V_122 )
V_5 -> V_129 = true ;
if ( ! ( V_21 -> V_55 . V_56 & V_57 ) )
V_21 -> V_124 . V_85 = V_21 -> V_124 . V_79 + V_21 -> V_124 . V_80 ;
V_5 -> V_72 . V_64 = V_21 -> V_120 ;
V_2 -> V_69 -> type = V_21 -> V_55 . V_130 ;
V_2 -> V_69 -> V_131 = V_21 -> V_55 . V_131 ;
V_2 -> V_69 -> V_132 = V_55 -> V_132 & 0xffff ;
if ( F_25 ( V_2 ) ) {
if ( V_21 -> V_55 . V_56 & V_133 ) {
F_15 ( V_2 , L_14 ) ;
V_2 -> V_69 -> V_134 = 2 ;
}
}
if ( ! V_5 -> V_129 &&
V_113 &&
( V_21 -> V_55 . V_127 < V_113 ) ) {
F_23 ( V_2 ,
L_15 ,
V_111 , V_21 -> V_55 . V_127 ) ;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
T_2 F_26 ( struct V_1 * V_2 , enum V_135 V_136 )
{
T_2 V_137 ;
if ( V_136 == V_138 )
return 1 << 17 ;
V_137 = V_2 -> V_6 -> V_54 . V_55 . V_137 ;
if ( V_137 )
return 1 << V_137 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_1 * V_139 = F_28 ( V_2 -> V_69 ) ;
struct V_4 * V_5 ;
T_2 V_140 ;
int V_32 ;
if ( F_25 ( V_2 ) )
V_2 -> V_69 -> V_134 = 1 ;
V_140 = V_141 ;
V_2 -> V_36 . V_95 = ( T_1 ) F_29 ( V_2 , V_140 ) ;
V_140 = V_142 ;
V_2 -> V_36 . V_37 = F_29 ( V_2 , V_140 ) ;
V_5 = F_30 ( sizeof( * V_5 ) , V_143 ) ;
if ( ! V_5 )
return - V_144 ;
if ( ! V_2 -> V_145 ) {
V_2 -> V_145 = ( V_11 V_146 * ) V_2 -> V_147 +
V_148 ;
} else if ( V_2 == V_139 ) {
V_5 -> V_115 = true ;
} else {
if ( V_139 -> V_6 -> V_115 )
V_5 -> V_115 = true ;
else
V_2 -> V_145 = ( V_11 V_146 * )
V_2 -> V_147 + V_148 ;
}
V_5 -> V_12 = F_31 ( & V_2 -> V_69 -> V_70 -> V_71 ,
sizeof( union V_13 ) ,
& V_5 -> V_39 ,
V_143 ) ;
if ( ! V_5 -> V_12 )
goto V_149;
V_5 -> V_14 = F_31 ( & V_2 -> V_69 -> V_70 -> V_71 ,
sizeof( union V_15 ) ,
& V_5 -> V_19 ,
V_143 ) ;
if ( ! V_5 -> V_14 )
goto V_150;
F_3 ( V_2 ,
V_9 ,
L_16 ,
V_5 -> V_12 ,
( V_18 ) V_5 -> V_39 ,
V_5 -> V_14 , ( V_18 ) V_5 -> V_19 ) ;
V_5 -> V_72 . V_64 = sizeof( struct V_74 ) ;
V_5 -> V_72 . V_73 = F_31 ( & V_2 -> V_69 -> V_70 -> V_71 ,
V_5 -> V_72 . V_64 ,
& V_5 -> V_72 . V_75 ,
V_143 ) ;
F_3 ( V_2 , V_9 ,
L_17 ,
V_5 -> V_72 . V_73 ,
( V_18 ) V_5 -> V_72 . V_75 , V_5 -> V_72 . V_64 ) ;
F_32 ( & V_5 -> V_8 ) ;
V_2 -> V_6 = V_5 ;
V_2 -> V_36 . V_151 = V_152 ;
V_32 = F_22 ( V_2 ) ;
if ( ! V_32 && V_5 -> V_115 &&
! F_26 ( V_2 , V_153 ) &&
( V_2 -> V_69 -> V_134 > 1 ) ) {
V_32 = F_17 ( V_2 , false ) ;
if ( V_32 )
return V_32 ;
V_5 -> V_115 = false ;
V_2 -> V_145 = ( V_11 V_146 * ) V_2 -> V_147 +
V_148 ;
V_32 = F_22 ( V_2 ) ;
}
F_3 ( V_2 , V_9 ,
L_18 ,
V_2 -> V_147 , V_2 -> V_145 , V_2 -> V_69 -> V_145 ) ;
return V_32 ;
V_150:
F_18 ( & V_2 -> V_69 -> V_70 -> V_71 ,
sizeof( union V_13 ) ,
V_5 -> V_12 , V_5 -> V_39 ) ;
V_149:
F_19 ( V_5 ) ;
return - V_144 ;
}
static void
F_33 ( struct V_154 * V_27 ,
struct V_155 * V_156 ,
enum V_157 V_158 , V_11 * V_159 )
{
if ( V_156 -> V_160 ) {
V_27 -> V_161 |= F_34 ( V_158 ) ;
if ( V_156 -> V_162 )
V_27 -> V_163 |= F_34 ( V_158 ) ;
}
* V_159 = V_156 -> V_164 ;
}
static void
F_35 ( struct V_154 * V_27 ,
struct V_155 * V_156 ,
enum V_157 V_158 ,
V_11 * V_159 , struct V_165 * V_166 ,
V_11 * V_167 , T_1 * V_168 )
{
if ( V_166 -> V_169 ) {
* V_167 = 1 ;
* V_168 = V_166 -> V_170 ;
}
F_33 ( V_27 , V_156 , V_158 , V_159 ) ;
}
void F_36 ( struct V_171 * V_172 )
{
if ( V_172 -> V_173 . V_162 )
V_172 -> V_173 . V_160 = true ;
if ( V_172 -> V_174 . V_162 )
V_172 -> V_174 . V_160 = true ;
if ( V_172 -> V_175 . V_162 )
V_172 -> V_175 . V_160 = true ;
if ( V_172 -> V_176 . V_162 )
V_172 -> V_176 . V_160 = true ;
if ( V_172 -> V_177 . V_162 )
V_172 -> V_177 . V_160 = true ;
V_172 -> V_178 = true ;
V_172 -> V_179 = true ;
}
static void
F_37 ( struct V_155 * V_172 ,
T_1 V_180 , V_11 V_163 ,
V_11 V_181 , enum V_182 V_183 )
{
if ( V_180 & F_34 ( V_183 ) ) {
V_172 -> V_162 = V_163 ;
V_172 -> V_164 = V_181 ;
} else {
V_172 -> V_162 = false ;
}
}
static void F_38 ( struct V_1 * V_2 ,
struct V_171 * V_172 ,
struct V_184 * V_78 )
{
T_1 V_185 = V_78 -> V_186 ;
F_37 ( & V_172 -> V_173 , V_185 ,
V_78 -> V_187 , V_78 -> V_188 ,
V_189 ) ;
F_37 ( & V_172 -> V_174 , V_185 ,
V_78 -> V_190 ,
V_78 -> V_191 ,
V_192 ) ;
F_37 ( & V_172 -> V_175 , V_185 ,
V_78 -> V_193 ,
V_78 -> V_194 ,
V_195 ) ;
F_37 ( & V_172 -> V_176 , V_185 ,
V_78 -> V_196 , V_78 -> V_197 ,
V_198 ) ;
F_37 ( & V_172 -> V_177 , V_185 ,
V_78 -> V_199 , V_78 -> V_200 ,
V_201 ) ;
V_172 -> V_202 . V_170 = V_78 -> V_203 ;
V_172 -> V_204 . V_170 = V_78 -> V_205 ;
F_3 ( V_2 , V_9 ,
L_19 ,
V_172 -> V_173 . V_162 , V_172 -> V_174 . V_162 ,
V_172 -> V_175 . V_162 ,
V_172 -> V_176 . V_162 , V_172 -> V_177 . V_162 ) ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_171 * V_156 )
{
struct V_171 * V_172 = & V_2 -> V_69 -> V_206 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_184 * V_78 ;
struct V_154 * V_27 ;
int V_32 ;
V_27 = F_1 ( V_2 , V_207 ,
sizeof( * V_27 ) ) ;
if ( V_156 -> V_178 && V_156 -> V_179 )
V_27 -> V_208 = 1 ;
F_35 ( V_27 , & V_156 -> V_173 , V_189 ,
& V_27 -> V_188 , & V_156 -> V_204 ,
& V_27 -> V_209 ,
& V_27 -> V_204 ) ;
F_35 ( V_27 , & V_156 -> V_174 ,
V_192 ,
& V_27 -> V_191 , & V_156 -> V_202 ,
& V_27 -> V_210 ,
& V_27 -> V_202 ) ;
F_33 ( V_27 , & V_156 -> V_175 ,
V_195 ,
& V_27 -> V_194 ) ;
F_33 ( V_27 , & V_156 -> V_176 ,
V_198 , & V_27 -> V_197 ) ;
F_33 ( V_27 , & V_156 -> V_177 ,
V_201 , & V_27 -> V_200 ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_66 ,
sizeof( struct V_34 ) ) ;
V_78 = & V_5 -> V_14 -> V_211 ;
V_32 = F_7 ( V_2 , & V_78 -> V_23 . V_24 , sizeof( * V_78 ) ) ;
if ( V_32 )
goto exit;
if ( V_78 -> V_23 . V_24 != V_48 ) {
F_3 ( V_2 , V_9 ,
L_20 ) ;
V_32 = - V_128 ;
}
F_38 ( V_2 , V_172 , V_78 ) ;
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int
F_40 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
T_1 V_212 ,
T_3 V_213 ,
T_3 V_214 ,
T_1 V_215 , void V_146 * * V_216 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_217 * V_21 ;
struct V_218 * V_63 ;
V_11 V_219 = V_51 -> V_220 . V_221 ;
int V_32 ;
V_63 = F_1 ( V_2 , V_222 , sizeof( * V_63 ) ) ;
V_63 -> V_219 = V_219 ;
V_63 -> V_214 = V_214 ;
V_63 -> V_215 = V_215 ;
V_63 -> V_223 = V_213 ;
V_63 -> V_224 = V_51 -> V_225 ;
V_63 -> V_226 = V_51 -> V_227 ;
V_63 -> V_212 = V_212 ;
V_63 -> V_228 = - 1 ;
if ( V_5 -> V_129 ) {
V_11 V_229 = V_5 -> V_54 . V_124 . V_229 [ V_219 ] ;
T_2 V_230 = 0 ;
* V_216 = ( V_11 V_146 * )
V_2 -> V_147 +
F_41 ( V_2 -> V_69 ) +
V_229 * V_231 ;
F_42 ( V_2 , * V_216 , sizeof( T_2 ) ,
( T_2 * ) ( & V_230 ) ) ;
}
F_16 ( V_2 , V_51 ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_66 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_232 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_128 ;
goto exit;
}
if ( ! V_5 -> V_129 ) {
T_2 V_230 = 0 ;
* V_216 = ( V_11 V_146 * ) V_2 -> V_147 + V_21 -> V_10 ;
F_3 ( V_2 , V_9 ,
L_21 ,
V_219 , * V_216 , V_21 -> V_10 ) ;
F_42 ( V_2 , * V_216 , sizeof( T_2 ) ,
( T_2 * ) & V_230 ) ;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_50 * V_51 , bool V_233 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_234 * V_63 ;
struct V_62 * V_21 ;
int V_32 ;
V_63 = F_1 ( V_2 , V_235 , sizeof( * V_63 ) ) ;
V_63 -> V_219 = V_51 -> V_220 . V_221 ;
V_63 -> V_79 = 1 ;
V_63 -> V_233 = V_233 ;
F_16 ( V_2 , V_51 ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_66 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_128 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int
F_44 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
T_3 V_236 ,
T_1 V_237 , void V_146 * * V_238 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_217 * V_21 ;
struct V_239 * V_63 ;
T_1 V_59 = V_51 -> V_220 . V_221 ;
int V_32 ;
V_63 = F_1 ( V_2 , V_240 , sizeof( * V_63 ) ) ;
V_63 -> V_241 = V_59 ;
V_63 -> V_236 = V_236 ;
V_63 -> V_237 = V_237 ;
V_63 -> V_224 = V_51 -> V_225 ;
V_63 -> V_226 = V_51 -> V_227 ;
F_16 ( V_2 , V_51 ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_66 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_232 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_128 ;
goto exit;
}
if ( ! V_5 -> V_129 ) {
* V_238 = ( V_11 V_146 * ) V_2 -> V_145 + V_21 -> V_10 ;
} else {
V_11 V_242 = V_5 -> V_54 . V_124 . V_242 [ V_59 ] ;
* V_238 = ( V_11 V_146 * ) V_2 -> V_145 +
F_45 ( V_242 ,
V_243 ) ;
}
F_3 ( V_2 , V_9 ,
L_22 ,
V_59 , V_51 -> V_60 , * V_238 , V_21 -> V_10 ) ;
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_46 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_244 * V_63 ;
struct V_62 * V_21 ;
int V_32 ;
V_63 = F_1 ( V_2 , V_245 , sizeof( * V_63 ) ) ;
V_63 -> V_241 = V_51 -> V_220 . V_221 ;
V_63 -> V_80 = 1 ;
F_16 ( V_2 , V_51 ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_66 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_128 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_47 ( struct V_1 * V_2 ,
V_11 V_246 ,
T_1 V_247 ,
V_11 V_248 ,
enum V_249 V_250 ,
V_11 V_251 , V_11 V_252 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_253 * V_63 ;
struct V_62 * V_21 ;
int V_32 , V_254 ;
V_63 = F_1 ( V_2 , V_255 , sizeof( * V_63 ) ) ;
V_63 -> V_247 = V_247 ;
V_63 -> V_246 = V_246 ;
V_63 -> V_248 = V_248 ;
V_63 -> V_250 = V_250 ;
V_63 -> V_251 = V_251 ;
V_63 -> V_252 = V_252 ;
for ( V_254 = 0 ; V_254 < V_2 -> V_6 -> V_54 . V_124 . V_81 ; V_254 ++ ) {
struct V_256 * V_257 = V_2 -> V_6 -> V_258 [ V_254 ] ;
if ( V_257 )
V_63 -> V_259 [ V_254 ] = V_257 -> V_260 ;
}
F_4 ( V_2 , & V_5 -> V_10 ,
V_66 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_128 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_62 * V_21 = & V_5 -> V_14 -> V_22 ;
int V_32 ;
F_1 ( V_2 , V_261 ,
sizeof( struct V_16 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_66 , sizeof( struct V_34 ) ) ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_128 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
static bool
F_49 ( struct V_1 * V_2 ,
struct V_262 * V_263 ,
T_1 V_264 )
{
switch ( V_264 ) {
case V_265 :
return ! ! ( V_263 -> V_266 ||
V_263 -> V_267 ) ;
case V_268 :
return ! ! V_263 -> V_269 ;
case V_270 :
return ! ! V_263 -> V_271 ;
case V_272 :
return ! ! V_263 -> V_273 ;
case V_274 :
return ! ! V_263 -> V_275 ;
case V_276 :
return ! ! ( V_263 -> V_277 . V_278 ||
V_263 -> V_277 . V_279 ) ;
case V_280 :
return ! ! V_263 -> V_281 ;
case V_282 :
return ! ! V_263 -> V_283 ;
default:
F_23 ( V_2 , L_23 ,
V_264 ) ;
return false ;
}
}
static void
F_50 ( struct V_1 * V_2 ,
struct V_262 * V_263 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_62 * V_78 ;
T_1 V_264 ;
for ( V_264 = V_265 ;
V_264 < V_284 ; V_264 ++ ) {
if ( ! F_49 ( V_2 , V_263 , V_264 ) )
continue;
V_78 = (struct V_62 * )
F_51 ( V_2 , V_5 -> V_14 ,
V_264 ) ;
if ( V_78 && V_78 -> V_23 . V_24 )
F_3 ( V_2 , V_9 ,
L_24 ,
V_264 ,
( V_78 && V_78 -> V_23 . V_24 ) ? L_25
: L_26 ) ;
}
}
int F_52 ( struct V_1 * V_2 ,
struct V_262 * V_285 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_286 * V_63 ;
struct V_62 * V_21 ;
V_11 V_287 , V_288 ;
T_2 V_26 = 0 ;
T_1 V_64 , V_264 ;
int V_32 ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_26 = sizeof( * V_21 ) ;
V_287 = V_285 -> V_266 ;
V_288 = V_285 -> V_267 ;
F_1 ( V_2 , V_289 , sizeof( * V_63 ) ) ;
if ( V_287 || V_288 ) {
struct V_290 * V_291 ;
V_64 = sizeof( struct V_290 ) ;
V_291 = F_4 ( V_2 , & V_5 -> V_10 ,
V_265 ,
V_64 ) ;
V_26 += sizeof( struct V_62 ) ;
if ( V_287 ) {
V_291 -> V_287 = V_287 ;
V_291 -> V_292 = V_285 -> V_293 ;
}
if ( V_288 ) {
V_291 -> V_288 = V_288 ;
V_291 -> V_294 = V_285 -> V_295 ;
}
}
if ( V_285 -> V_269 ) {
struct V_296 * V_297 ;
V_64 = sizeof( struct V_296 ) ;
V_264 = V_268 ;
V_297 = F_4 ( V_2 , & V_5 -> V_10 ,
V_264 , V_64 ) ;
V_26 += sizeof( struct V_62 ) ;
V_297 -> V_298 = V_285 -> V_299 ;
}
if ( V_285 -> V_275 ) {
struct V_300 * V_301 ;
V_64 = sizeof( struct V_300 ) ;
V_301 = F_4 ( V_2 , & V_5 -> V_10 ,
V_274 , V_64 ) ;
V_26 += sizeof( struct V_62 ) ;
memcpy ( V_301 -> V_302 , V_285 -> V_302 ,
sizeof( unsigned long ) * V_303 ) ;
}
V_287 = V_285 -> V_277 . V_278 ;
V_288 = V_285 -> V_277 . V_279 ;
if ( V_287 || V_288 ) {
struct V_304 * V_305 ;
V_264 = V_276 ;
V_64 = sizeof( struct V_304 ) ;
V_305 = F_4 ( V_2 , & V_5 -> V_10 , V_264 , V_64 ) ;
V_26 += sizeof( struct V_62 ) ;
if ( V_287 ) {
V_305 -> V_306 = V_287 ;
V_305 -> V_307 =
V_285 -> V_277 . V_307 ;
}
if ( V_288 ) {
V_305 -> V_308 = V_288 ;
V_305 -> V_309 =
V_285 -> V_277 . V_309 ;
}
}
if ( V_285 -> V_281 ) {
struct V_310 * V_281 = V_285 -> V_281 ;
struct V_311 * V_312 ;
int V_254 , V_313 ;
V_64 = sizeof( struct V_311 ) ;
V_312 = F_4 ( V_2 ,
& V_5 -> V_10 ,
V_280 , V_64 ) ;
V_26 += sizeof( struct V_62 ) ;
if ( V_281 -> V_314 )
V_312 -> V_315 |=
V_316 ;
if ( V_281 -> V_317 )
V_312 -> V_315 |=
V_318 ;
if ( V_281 -> V_319 )
V_312 -> V_315 |=
V_320 ;
if ( V_281 -> V_321 )
V_312 -> V_315 |= V_322 ;
V_312 -> V_323 = V_281 -> V_323 ;
V_312 -> V_324 = V_281 -> V_324 ;
V_312 -> V_325 = V_281 -> V_325 ;
V_313 = F_53 ( int , V_326 ,
1 << V_312 -> V_325 ) ;
for ( V_254 = 0 ; V_254 < V_313 ; V_254 ++ ) {
struct V_50 * V_327 ;
V_327 = V_281 -> V_328 [ V_254 ] ;
V_312 -> V_328 [ V_254 ] = V_327 -> V_220 . V_221 ;
}
memcpy ( V_312 -> V_329 , V_281 -> V_329 ,
sizeof( V_281 -> V_329 ) ) ;
}
if ( V_285 -> V_273 ) {
struct V_330 * V_331 ;
V_64 = sizeof( struct V_330 ) ;
V_264 = V_272 ;
V_331 = F_4 ( V_2 , & V_5 -> V_10 , V_264 , V_64 ) ;
V_26 += sizeof( struct V_62 ) ;
V_331 -> V_332 = V_285 -> V_332 ;
V_331 -> V_273 =
V_285 -> V_273 ;
}
F_4 ( V_2 , & V_5 -> V_10 ,
V_66 , sizeof( struct V_34 ) ) ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , V_26 ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_128 ;
goto exit;
}
F_50 ( V_2 , V_285 ) ;
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_62 * V_21 ;
struct V_16 * V_63 ;
int V_32 ;
V_63 = F_1 ( V_2 , V_333 , sizeof( * V_63 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_66 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_67 ;
goto exit;
}
V_2 -> V_68 = 0 ;
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_334 * V_335 )
{
struct V_262 V_336 ;
int V_254 ;
memset ( & V_336 , 0 , sizeof( V_336 ) ) ;
V_336 . V_275 = 1 ;
if ( V_335 -> V_337 == V_338 ) {
for ( V_254 = 0 ; V_254 < V_335 -> V_339 ; V_254 ++ ) {
T_2 V_340 ;
V_340 = F_56 ( V_335 -> V_341 [ V_254 ] ) ;
F_57 ( V_340 , V_336 . V_302 ) ;
}
}
F_52 ( V_2 , & V_336 ) ;
}
int F_58 ( struct V_1 * V_2 ,
struct V_342 * V_343 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_344 * V_63 ;
struct V_62 * V_21 ;
int V_32 ;
V_63 = F_1 ( V_2 , V_345 , sizeof( * V_63 ) ) ;
V_63 -> V_337 = ( V_11 ) V_343 -> V_337 ;
V_63 -> type = ( V_11 ) V_343 -> type ;
memcpy ( V_63 -> V_341 , V_343 -> V_341 , V_346 ) ;
V_63 -> V_347 = V_343 -> V_347 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_66 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_67 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_62 * V_21 = & V_5 -> V_14 -> V_22 ;
int V_32 ;
F_1 ( V_2 , V_348 ,
sizeof( struct V_16 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_66 , sizeof( struct V_34 ) ) ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_128 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
T_1 F_60 ( struct V_1 * V_2 , T_1 V_349 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 ) {
F_15 ( V_2 , L_27 ) ;
return 0 ;
}
return V_5 -> V_54 . V_124 . V_350 [ V_349 ] . V_351 ;
}
void F_61 ( struct V_1 * V_2 ,
T_1 V_349 , struct V_256 * V_257 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 ) {
F_15 ( V_2 , L_27 ) ;
return;
}
if ( V_349 >= V_352 ) {
F_15 ( V_2 , L_28 , V_349 ) ;
return;
}
V_5 -> V_258 [ V_349 ] = V_257 ;
}
int F_62 ( struct V_1 * V_2 , V_11 * V_353 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_74 V_354 ;
T_2 V_355 , V_356 ;
V_356 = sizeof( V_5 -> V_72 . V_73 -> V_355 ) ;
* V_353 = 0 ;
memcpy ( & V_354 , V_5 -> V_72 . V_73 , V_5 -> V_72 . V_64 ) ;
if ( V_354 . V_357 == V_5 -> V_358 . V_357 )
return 0 ;
V_355 = F_63 ( 0 , ( V_11 * ) & V_354 + V_356 ,
V_5 -> V_72 . V_64 - V_356 ) ;
if ( V_355 != V_354 . V_355 )
return - V_67 ;
memcpy ( & V_5 -> V_358 , & V_354 , V_5 -> V_72 . V_64 ) ;
F_3 ( V_2 , V_9 ,
L_29 , V_354 . V_357 ) ;
* V_353 = 1 ;
return 0 ;
}
void F_64 ( struct V_1 * V_2 ,
struct V_359 * V_285 ,
struct V_74 * V_360 )
{
memset ( V_285 , 0 , sizeof( * V_285 ) ) ;
V_285 -> V_361 . V_362 = V_360 -> V_363 ;
V_285 -> V_361 . V_364 = V_360 -> V_365 ;
V_285 -> V_361 . V_366 = V_360 -> V_367 ;
V_285 -> V_368 . V_362 = V_360 -> V_369 ;
V_285 -> V_368 . V_370 = V_360 -> V_371 ;
V_285 -> V_368 . V_372 = V_360 -> V_373 ;
V_285 -> V_374 = V_360 -> V_375 ;
}
void F_65 ( struct V_1 * V_2 ,
struct V_359 * V_376 )
{
F_64 ( V_2 , V_376 ,
& ( V_2 -> V_6 -> V_358 ) ) ;
}
void F_66 ( struct V_1 * V_2 ,
struct V_377 * V_378 ,
struct V_74 * V_360 )
{
memset ( V_378 , 0 , sizeof( * V_378 ) ) ;
V_378 -> V_379 = V_360 -> V_379 ;
V_378 -> V_361 = V_360 -> V_361 ;
V_378 -> V_380 = V_360 -> V_380 ;
V_378 -> V_381 = V_360 -> V_362 ;
V_378 -> V_382 = V_360 -> V_383 ;
V_378 -> V_384 = V_360 -> V_384 ;
V_378 -> V_385 = V_360 -> V_385 ;
V_378 -> V_386 = V_360 -> V_386 ;
V_378 -> V_387 = V_360 -> V_387 ;
V_378 -> V_388 = V_360 -> V_388 ;
V_378 -> V_389 = V_360 -> V_389 ;
V_378 -> V_390 = V_360 -> V_390 ;
}
void F_67 ( struct V_1 * V_2 ,
struct V_377 * V_391 )
{
F_66 ( V_2 , V_391 ,
& ( V_2 -> V_6 -> V_358 ) ) ;
}
void F_68 ( struct V_1 * V_2 ,
struct V_392 * V_393 ,
struct V_74 * V_360 )
{
memset ( V_393 , 0 , sizeof( * V_393 ) ) ;
V_393 -> V_394 = V_360 -> V_395 ;
}
void F_69 ( struct V_1 * V_2 ,
struct V_392 * V_393 )
{
F_68 ( V_2 , V_393 ,
& ( V_2 -> V_6 -> V_358 ) ) ;
}
void F_70 ( struct V_1 * V_2 , V_11 * V_79 )
{
* V_79 = V_2 -> V_6 -> V_54 . V_124 . V_79 ;
}
void F_71 ( struct V_1 * V_2 , V_11 * V_80 )
{
* V_80 = V_2 -> V_6 -> V_54 . V_124 . V_80 ;
}
void F_72 ( struct V_1 * V_2 , V_11 * V_85 )
{
* V_85 = V_2 -> V_6 -> V_54 . V_124 . V_85 ;
}
void F_73 ( struct V_1 * V_2 , V_11 * V_396 )
{
memcpy ( V_396 ,
V_2 -> V_6 -> V_54 . V_55 . V_396 , V_346 ) ;
}
void F_74 ( struct V_1 * V_2 , V_11 * V_83 )
{
struct V_4 * V_397 ;
V_397 = V_2 -> V_6 ;
* V_83 = V_397 -> V_54 . V_124 . V_83 ;
}
void F_75 ( struct V_1 * V_2 , V_11 * V_82 )
{
struct V_4 * V_397 = V_2 -> V_6 ;
* V_82 = V_397 -> V_54 . V_124 . V_82 ;
}
bool F_76 ( struct V_1 * V_2 , V_11 * V_341 )
{
struct V_74 * V_72 ;
V_72 = & V_2 -> V_6 -> V_358 ;
if ( ! ( V_72 -> V_398 & ( 1 << V_399 ) ) )
return true ;
if ( F_77 ( V_72 -> V_341 , V_341 ) )
return false ;
return false ;
}
static bool F_78 ( struct V_1 * V_400 ,
V_11 * V_401 , V_11 * V_402 )
{
struct V_74 * V_72 ;
V_72 = & V_400 -> V_6 -> V_358 ;
if ( V_72 -> V_398 & ( 1 << V_399 ) ) {
if ( V_402 )
* V_402 = 1 ;
} else if ( V_72 -> V_398 & ( 1 << V_403 ) ) {
if ( V_402 )
* V_402 = 0 ;
} else {
return false ;
}
F_79 ( V_401 , V_72 -> V_341 ) ;
return true ;
}
static void
F_80 ( struct V_1 * V_2 ,
T_1 * V_404 , T_1 * V_405 )
{
struct V_74 * V_360 ;
V_360 = & V_2 -> V_6 -> V_358 ;
* V_404 = V_360 -> V_205 ;
* V_405 = V_360 -> V_203 ;
}
void F_81 ( struct V_1 * V_2 ,
T_1 * V_102 , T_1 * V_104 ,
T_1 * V_406 , T_1 * V_407 )
{
struct V_87 * V_408 ;
V_408 = & V_2 -> V_6 -> V_54 . V_55 ;
* V_102 = V_408 -> V_102 ;
* V_104 = V_408 -> V_104 ;
* V_406 = V_408 -> V_406 ;
* V_407 = V_408 -> V_407 ;
}
static void F_82 ( struct V_1 * V_400 )
{
struct V_409 * V_410 = V_400 -> V_69 -> V_411 . V_412 ;
V_11 V_341 [ V_346 ] , V_413 , V_414 ;
void * V_415 = V_400 -> V_69 -> V_416 ;
T_1 V_204 , V_202 ;
F_80 ( V_400 , & V_204 , & V_202 ) ;
V_413 = F_78 ( V_400 , V_341 ,
& V_414 ) ;
if ( V_413 && V_415 )
V_410 -> V_417 ( V_415 , V_341 , ! ! V_414 ) ;
V_410 -> V_418 ( V_415 , V_204 , V_202 ) ;
F_83 ( V_400 ) ;
}
void F_84 ( struct V_419 * V_420 )
{
struct V_1 * V_400 = F_85 ( V_420 , struct V_1 ,
V_421 . V_420 ) ;
V_11 V_422 = 0 ;
if ( F_86 ( V_423 , & V_400 -> V_424 ) )
return;
F_62 ( V_400 , & V_422 ) ;
if ( F_86 ( V_425 ,
& V_400 -> V_424 ) )
V_422 = 1 ;
if ( V_422 )
F_82 ( V_400 ) ;
F_87 ( V_400 -> V_426 , & V_400 -> V_421 , V_427 ) ;
}
