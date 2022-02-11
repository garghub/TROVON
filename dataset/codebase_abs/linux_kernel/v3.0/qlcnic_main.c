inline void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , V_4 -> V_6 ) ;
}
static inline void F_3 ( struct V_7 * V_8 )
{
F_2 ( 0 , V_8 -> V_9 ) ;
}
static inline void F_4 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_2 ( 0x1 , V_8 -> V_9 ) ;
if ( ! F_5 ( V_2 ) )
F_2 ( 0xfbff , V_2 -> V_10 ) ;
}
static int
F_6 ( struct V_11 * V_12 , int V_13 )
{
int V_14 = sizeof( struct V_7 ) * V_13 ;
V_12 -> V_15 = F_7 ( V_14 , V_16 ) ;
return V_12 -> V_15 == NULL ;
}
static void
F_8 ( struct V_11 * V_12 )
{
if ( V_12 -> V_15 != NULL )
F_9 ( V_12 -> V_15 ) ;
V_12 -> V_15 = NULL ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_19 ;
struct V_7 * V_8 ;
struct V_11 * V_12 = V_2 -> V_12 ;
if ( F_6 ( V_12 , V_2 -> V_20 ) )
return - V_21 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_12 -> V_15 [ V_19 ] ;
if ( V_19 == V_2 -> V_20 - 1 )
F_11 ( V_18 , & V_8 -> V_22 , V_23 ,
V_24 / V_2 -> V_20 ) ;
else
F_11 ( V_18 , & V_8 -> V_22 ,
V_25 , V_24 * 2 ) ;
}
return 0 ;
}
static void
F_12 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_7 * V_8 ;
struct V_11 * V_12 = V_2 -> V_12 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_12 -> V_15 [ V_19 ] ;
F_13 ( & V_8 -> V_22 ) ;
}
F_8 ( V_2 -> V_12 ) ;
}
static void
F_14 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_7 * V_8 ;
struct V_11 * V_12 = V_2 -> V_12 ;
if ( V_2 -> V_26 != V_27 )
return;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_12 -> V_15 [ V_19 ] ;
F_15 ( & V_8 -> V_22 ) ;
F_4 ( V_8 ) ;
}
}
static void
F_16 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_7 * V_8 ;
struct V_11 * V_12 = V_2 -> V_12 ;
if ( V_2 -> V_26 != V_27 )
return;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_12 -> V_15 [ V_19 ] ;
F_3 ( V_8 ) ;
F_17 ( & V_8 -> V_22 ) ;
F_18 ( & V_8 -> V_22 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_28 , 0 , sizeof( V_2 -> V_28 ) ) ;
}
static void F_20 ( struct V_29 * V_30 , int V_31 )
{
T_1 V_32 ;
int V_33 ;
V_33 = F_21 ( V_30 , V_34 ) ;
if ( V_33 ) {
F_22 ( V_30 , V_33 , & V_32 ) ;
if ( V_31 )
V_32 |= V_35 ;
else
V_32 = 0 ;
F_23 ( V_30 , V_33 , V_32 ) ;
}
}
static void F_24 ( struct V_1 * V_2 , int V_13 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ )
V_2 -> V_37 [ V_36 ] . V_38 = V_36 ;
}
static int
F_25 ( struct V_1 * V_2 )
{
T_2 V_39 [ V_40 ] ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_29 * V_30 = V_2 -> V_30 ;
if ( F_26 ( V_2 , V_39 ) != 0 )
return - V_41 ;
memcpy ( V_18 -> V_42 , V_39 , V_40 ) ;
memcpy ( V_18 -> V_43 , V_18 -> V_42 , V_18 -> V_44 ) ;
memcpy ( V_2 -> V_39 , V_18 -> V_42 , V_18 -> V_44 ) ;
if ( ! F_27 ( V_18 -> V_43 ) )
F_28 ( & V_30 -> V_45 , L_1 ,
V_18 -> V_42 ) ;
return 0 ;
}
static int F_29 ( struct V_17 * V_18 , void * V_46 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_47 * V_48 = V_46 ;
if ( ( V_2 -> V_49 & V_50 ) )
return - V_51 ;
if ( ! F_27 ( V_48 -> V_52 ) )
return - V_53 ;
if ( F_31 ( V_54 , & V_2 -> V_55 ) ) {
F_32 ( V_18 ) ;
F_16 ( V_2 ) ;
}
memcpy ( V_2 -> V_39 , V_48 -> V_52 , V_18 -> V_44 ) ;
memcpy ( V_18 -> V_42 , V_48 -> V_52 , V_18 -> V_44 ) ;
F_33 ( V_2 -> V_18 ) ;
if ( F_31 ( V_54 , & V_2 -> V_55 ) ) {
F_34 ( V_18 ) ;
F_14 ( V_2 ) ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_56 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
int V_57 = - 1 ;
V_2 -> V_20 = 1 ;
V_2 -> V_49 &= ~ ( V_58 | V_59 ) ;
F_20 ( V_30 , 0 ) ;
if ( V_2 -> V_60 ) {
V_61:
F_24 ( V_2 , V_56 ) ;
V_57 = F_36 ( V_30 , V_2 -> V_37 , V_56 ) ;
if ( V_57 == 0 ) {
V_2 -> V_49 |= V_59 ;
F_20 ( V_30 , 1 ) ;
V_2 -> V_20 = V_56 ;
F_37 ( & V_30 -> V_45 , L_2 ) ;
return V_57 ;
}
if ( V_57 > 0 ) {
V_56 = F_38 ( V_57 ) ;
if ( V_56 )
goto V_61;
}
}
return V_57 ;
}
static void F_39 ( struct V_1 * V_2 )
{
const struct V_62 * V_63 ;
struct V_29 * V_30 = V_2 -> V_30 ;
if ( V_64 && ! F_40 ( V_30 ) ) {
V_2 -> V_49 |= V_58 ;
V_2 -> V_65 = F_41 ( V_2 ,
V_66 [ V_2 -> V_67 -> V_68 ] ) ;
F_37 ( & V_30 -> V_45 , L_3 ) ;
V_2 -> V_37 [ 0 ] . V_69 = V_30 -> V_70 ;
return;
}
V_63 = & V_71 [ V_2 -> V_67 -> V_68 ] ;
V_2 -> V_72 = V_63 -> V_72 ;
V_2 -> V_65 = F_41 ( V_2 ,
V_63 -> V_65 ) ;
V_2 -> V_10 = F_41 ( V_2 ,
V_63 -> V_10 ) ;
V_2 -> V_73 = F_41 ( V_2 , V_74 ) ;
V_2 -> V_75 = F_41 ( V_2 ,
V_76 ) ;
F_37 ( & V_30 -> V_45 , L_4 ) ;
V_2 -> V_37 [ 0 ] . V_69 = V_30 -> V_70 ;
}
static void
F_42 ( struct V_1 * V_2 )
{
int V_56 ;
if ( V_2 -> V_60 ) {
V_56 = ( F_43 () >=
V_77 ) ?
V_77 :
V_78 ;
} else
V_56 = 1 ;
if ( ! F_35 ( V_2 , V_56 ) )
return;
F_39 ( V_2 ) ;
}
static void
F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 & V_59 )
F_45 ( V_2 -> V_30 ) ;
if ( V_2 -> V_49 & V_58 )
F_46 ( V_2 -> V_30 ) ;
}
static void
F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_67 -> V_79 != NULL )
F_48 ( V_2 -> V_67 -> V_79 ) ;
}
static int
F_49 ( struct V_1 * V_2 )
{
struct V_80 * V_81 ;
int V_36 , V_82 = 0 ;
T_2 V_83 ;
V_81 = F_50 ( V_84 , sizeof( * V_81 ) , V_16 ) ;
if ( ! V_81 )
return - V_21 ;
V_2 -> V_85 = F_7 ( sizeof( struct V_86 ) *
V_84 , V_16 ) ;
if ( ! V_2 -> V_85 ) {
V_82 = - V_21 ;
goto V_87;
}
V_2 -> V_88 = F_7 ( sizeof( struct V_89 ) *
V_90 , V_16 ) ;
if ( ! V_2 -> V_88 ) {
V_82 = - V_21 ;
goto V_91;
}
V_82 = F_51 ( V_2 , V_81 ) ;
if ( V_82 )
goto V_92;
for ( V_36 = 0 ; V_36 < V_84 ; V_36 ++ ) {
V_83 = V_81 [ V_36 ] . V_93 ;
if ( V_83 > V_84 ) {
V_82 = V_94 ;
goto V_92;
}
V_2 -> V_85 [ V_83 ] . V_95 = ( T_2 ) V_81 [ V_36 ] . V_95 ;
V_2 -> V_85 [ V_83 ] . type = ( T_2 ) V_81 [ V_36 ] . type ;
V_2 -> V_85 [ V_83 ] . V_96 = ( T_2 ) V_81 [ V_36 ] . V_97 ;
V_2 -> V_85 [ V_83 ] . V_98 = V_81 [ V_36 ] . V_99 ;
V_2 -> V_85 [ V_83 ] . V_100 = V_81 [ V_36 ] . V_101 ;
}
for ( V_36 = 0 ; V_36 < V_90 ; V_36 ++ )
V_2 -> V_88 [ V_36 ] . V_49 |= V_102 ;
F_9 ( V_81 ) ;
return 0 ;
V_92:
F_9 ( V_2 -> V_88 ) ;
V_2 -> V_88 = NULL ;
V_91:
F_9 ( V_2 -> V_85 ) ;
V_2 -> V_85 = NULL ;
V_87:
F_9 ( V_81 ) ;
return V_82 ;
}
static int
F_52 ( struct V_1 * V_2 )
{
T_2 V_93 ;
T_1 V_103 ;
int V_36 , V_82 = 1 ;
T_1 V_104 = V_105 ;
void T_3 * V_106 = V_2 -> V_67 -> V_79 + V_107 ;
V_103 = F_53 ( V_2 , V_108 ) ;
V_82 = F_54 ( V_2 ) ;
if ( V_82 )
goto V_109;
if ( V_110 ) {
for ( V_36 = 0 ; V_36 < V_84 ; V_36 ++ ) {
V_93 = V_36 ;
if ( V_2 -> V_85 [ V_36 ] . type != V_111 ||
V_93 == V_2 -> V_67 -> V_68 )
continue;
V_104 |= ( V_110 &
F_55 ( 0xf , V_93 ) ) ;
}
} else {
V_104 = F_56 ( V_106 ) ;
V_104 = ( V_104 & ~ F_55 ( 0xf , V_2 -> V_67 -> V_68 ) ) |
( F_55 ( V_105 ,
V_2 -> V_67 -> V_68 ) ) ;
}
F_2 ( V_104 , V_106 ) ;
F_57 ( V_2 ) ;
V_109:
return V_82 ;
}
static void
F_58 ( struct V_1 * V_2 )
{
void T_3 * V_112 ;
void T_3 * V_106 ;
T_1 V_113 ;
T_1 V_114 ;
T_1 V_115 , V_116 ;
V_2 -> V_117 = F_56 ( V_2 -> V_67 -> V_79 +
V_118 ) ;
F_22 ( V_2 -> V_30 , V_119 , & V_113 ) ;
V_112 = V_2 -> V_67 -> V_79 + V_120 ;
V_114 = F_56 ( V_112 ) ;
V_113 = ( V_113 - V_114 ) / V_121 ;
V_2 -> V_67 -> V_68 = V_113 ;
V_106 = V_2 -> V_67 -> V_79 + V_107 ;
V_115 = F_56 ( V_106 ) ;
if ( V_115 == V_122 )
V_116 = V_105 ;
else
V_116 = F_59 ( V_115 , V_2 -> V_67 -> V_68 ) ;
if ( V_116 == V_123 ) {
V_2 -> V_115 = V_123 ;
F_37 ( & V_2 -> V_30 -> V_45 ,
L_5 ,
V_2 -> V_117 ) ;
V_2 -> V_124 = & V_125 ;
} else
V_2 -> V_124 = & V_126 ;
}
static int
F_60 ( struct V_1 * V_2 )
{
void T_3 * V_127 = NULL ;
T_4 V_128 ;
unsigned long V_129 , V_130 = 0 ;
struct V_29 * V_30 = V_2 -> V_30 ;
V_128 = F_61 ( V_30 , 0 ) ;
V_129 = F_62 ( V_30 , 0 ) ;
if ( V_129 == V_131 ) {
V_127 = F_63 ( V_30 , 0 ) ;
if ( V_127 == NULL ) {
F_64 ( & V_30 -> V_45 , L_6 ) ;
return - V_41 ;
}
V_130 = V_129 ;
} else {
return - V_41 ;
}
F_37 ( & V_30 -> V_45 , L_7 , ( int ) ( V_129 >> 20 ) ) ;
V_2 -> V_67 -> V_79 = V_127 ;
V_2 -> V_67 -> V_130 = V_130 ;
F_58 ( V_2 ) ;
V_2 -> V_67 -> V_132 = F_41 ( V_2 ,
F_65 ( F_66 (
V_2 -> V_67 -> V_68 ) ) ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 , char * V_133 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
int V_36 , V_134 = 0 ;
for ( V_36 = 0 ; V_36 < V_135 ; ++ V_36 ) {
if ( V_136 [ V_36 ] . V_137 == V_30 -> V_137 &&
V_136 [ V_36 ] . V_138 == V_30 -> V_138 &&
V_136 [ V_36 ] . V_139 == V_30 -> V_140 &&
V_136 [ V_36 ] . V_141 == V_30 -> V_142 ) {
sprintf ( V_133 , L_8 ,
V_2 -> V_39 ,
V_136 [ V_36 ] . V_143 ) ;
V_134 = 1 ;
break;
}
}
if ( ! V_134 )
sprintf ( V_133 , L_9 , V_2 -> V_39 ) ;
}
static void
F_68 ( struct V_1 * V_2 )
{
T_1 V_144 , V_145 , V_146 ;
struct V_29 * V_30 = V_2 -> V_30 ;
V_144 = F_53 ( V_2 , V_147 ) ;
V_145 = F_53 ( V_2 , V_148 ) ;
V_146 = F_53 ( V_2 , V_149 ) ;
V_2 -> V_150 = F_69 ( V_144 , V_145 , V_146 ) ;
F_37 ( & V_30 -> V_45 , L_10 ,
V_144 , V_145 , V_146 ) ;
if ( V_2 -> V_67 -> V_151 == V_152 ) {
if ( V_2 -> V_49 & V_153 ) {
V_2 -> V_154 = V_155 ;
V_2 -> V_156 = V_157 ;
} else {
V_2 -> V_154 = V_158 ;
V_2 -> V_156 = V_159 ;
}
V_2 -> V_160 = V_161 ;
V_2 -> V_162 = V_161 ;
} else if ( V_2 -> V_67 -> V_151 == V_163 ) {
V_2 -> V_154 = V_164 ;
V_2 -> V_160 = V_165 ;
V_2 -> V_162 = V_165 ;
V_2 -> V_156 = V_166 ;
}
V_2 -> V_60 = ! ! V_167 ;
V_2 -> V_168 = V_169 ;
V_2 -> V_170 = V_171 ;
}
static int
F_70 ( struct V_1 * V_2 )
{
int V_57 ;
struct V_172 V_173 ;
V_57 = F_71 ( V_2 , & V_173 , V_2 -> V_67 -> V_68 ) ;
if ( V_57 )
return V_57 ;
V_2 -> V_174 = ( T_2 ) V_173 . V_175 ;
V_2 -> V_176 = V_173 . V_176 ;
V_2 -> V_177 = V_173 . V_177 ;
V_2 -> V_178 = V_173 . V_178 ;
V_2 -> V_179 = V_173 . V_179 ;
V_2 -> V_180 = V_173 . V_180 ;
V_2 -> V_181 = V_173 . V_181 ;
if ( V_2 -> V_179 & V_182 )
V_2 -> V_49 |= V_153 ;
else
V_2 -> V_49 &= ~ V_153 ;
return V_57 ;
}
static void
F_72 ( struct V_1 * V_2 ,
struct V_183 * V_184 )
{
if ( V_184 -> V_185 )
V_2 -> V_49 &= ~ V_186 ;
else
V_2 -> V_49 |= V_186 ;
if ( V_184 -> V_187 )
V_2 -> V_188 = V_184 -> V_187 ;
else
V_2 -> V_188 = 0 ;
}
static void
F_73 ( struct V_17 * V_18 , T_5 V_189 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
F_74 ( V_189 , V_2 -> V_190 ) ;
}
static void
F_75 ( struct V_17 * V_18 , T_5 V_189 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
F_76 ( V_18 , V_191 ) ;
F_77 ( V_189 , V_2 -> V_190 ) ;
}
static void
F_78 ( struct V_1 * V_2 ,
struct V_183 * V_184 )
{
V_2 -> V_49 &= ~ ( V_192 | V_50 |
V_193 ) ;
if ( V_184 -> V_194 )
V_2 -> V_49 |= V_192 ;
if ( ! V_184 -> V_195 )
V_2 -> V_49 |= V_50 ;
if ( ! V_184 -> V_196 )
V_2 -> V_49 |= V_193 ;
F_79 ( V_2 , V_184 ) ;
}
static int
F_80 ( struct V_1 * V_2 )
{
struct V_183 V_184 ;
if ( ! ( V_2 -> V_49 & V_153 ) )
return 0 ;
V_184 . V_68 = V_2 -> V_67 -> V_68 ;
if ( F_81 ( V_2 , & V_184 ) )
return - V_41 ;
F_72 ( V_2 , & V_184 ) ;
F_78 ( V_2 , & V_184 ) ;
return 0 ;
}
static void
F_79 ( struct V_1 * V_2 ,
struct V_183 * V_184 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
unsigned long V_197 , V_198 ;
V_197 = ( V_199 | V_200 | V_201 |
V_202 | V_203 ) ;
V_198 = ( V_199 | V_200 |
V_202 | V_204 ) ;
if ( V_2 -> V_179 & V_205 ) {
V_197 |= ( V_206 | V_207 ) ;
V_198 |= ( V_206 | V_207 ) ;
}
if ( V_18 -> V_197 & V_208 )
V_197 |= V_208 ;
if ( V_184 -> V_209 & V_210 ) {
V_18 -> V_197 |= V_197 ;
if ( ! ( V_184 -> V_209 & V_211 ) )
V_18 -> V_197 &= ~ V_206 ;
if ( ! ( V_184 -> V_209 & V_212 ) )
V_18 -> V_197 &= ~ V_207 ;
} else {
V_18 -> V_197 &= ~ V_197 ;
}
V_18 -> V_198 = ( V_197 & V_198 ) ;
}
static int
F_82 ( struct V_1 * V_2 )
{
void T_3 * V_106 ;
T_1 V_115 , V_116 ;
int V_57 = 0 ;
V_57 = F_70 ( V_2 ) ;
if ( V_57 )
return V_57 ;
if ( V_2 -> V_49 & V_213 )
return 0 ;
V_106 = V_2 -> V_67 -> V_79 + V_107 ;
V_115 = F_56 ( V_106 ) ;
V_116 = F_59 ( V_115 , V_2 -> V_67 -> V_68 ) ;
if ( V_115 == V_122 )
V_116 = V_105 ;
else
V_116 = F_59 ( V_115 , V_2 -> V_67 -> V_68 ) ;
if ( V_2 -> V_49 & V_153 ) {
if ( V_116 == V_105 ) {
V_2 -> V_115 = V_105 ;
V_57 = F_49 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_52 ( V_2 ) ;
F_37 ( & V_2 -> V_30 -> V_45 ,
L_11 ,
V_2 -> V_117 ) ;
} else if ( V_116 == V_214 ) {
V_2 -> V_115 = V_214 ;
F_37 ( & V_2 -> V_30 -> V_45 ,
L_12 ,
V_2 -> V_117 ) ;
}
}
V_2 -> V_49 |= V_213 ;
return V_57 ;
}
static int
F_83 ( struct V_1 * V_2 )
{
struct V_183 V_184 ;
struct V_86 * V_215 ;
T_2 V_36 ;
if ( V_2 -> V_216 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_84 ; V_36 ++ ) {
if ( V_2 -> V_85 [ V_36 ] . type != V_111 )
continue;
memset ( & V_184 , 0 , sizeof( struct V_183 ) ) ;
V_184 . V_68 = V_36 ;
V_184 . V_209 = V_210 ;
V_184 . V_195 = V_210 ;
V_184 . V_196 = V_210 ;
if ( V_2 -> V_179 & V_205 )
V_184 . V_209 |= ( V_211 | V_212 ) ;
if ( F_84 ( V_2 , & V_184 ) )
return - V_41 ;
V_215 = & V_2 -> V_85 [ V_36 ] ;
V_215 -> V_188 = V_184 . V_187 ;
V_215 -> V_195 = V_184 . V_195 ;
V_215 -> V_194 = V_184 . V_194 ;
V_215 -> V_185 = V_184 . V_185 ;
V_215 -> V_196 = V_184 . V_196 ;
V_215 -> V_209 = V_184 . V_209 ;
}
return 0 ;
}
static int
F_85 ( struct V_1 * V_2 ,
struct V_86 * V_215 , int V_68 )
{
struct V_183 V_184 ;
V_184 . V_115 = V_217 ;
V_184 . V_68 = V_68 ;
V_184 . V_187 = V_215 -> V_188 ;
V_184 . V_195 = V_215 -> V_195 ;
V_184 . V_185 = V_215 -> V_185 ;
V_184 . V_194 = V_215 -> V_194 ;
V_184 . V_209 = V_215 -> V_209 ;
V_184 . V_196 = V_215 -> V_196 ;
if ( F_84 ( V_2 , & V_184 ) )
return - V_41 ;
V_184 . V_115 = V_218 ;
if ( F_84 ( V_2 , & V_184 ) )
return - V_41 ;
return 0 ;
}
static int
F_86 ( struct V_1 * V_2 )
{
int V_36 , V_57 ;
struct V_86 * V_215 ;
struct V_172 V_173 ;
if ( ! V_2 -> V_216 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_84 ; V_36 ++ ) {
V_215 = & V_2 -> V_85 [ V_36 ] ;
if ( V_215 -> type != V_111 )
continue;
V_57 = F_71 ( V_2 , & V_173 , V_36 ) ;
if ( V_57 )
return V_57 ;
V_173 . V_219 = V_215 -> V_98 ;
V_173 . V_220 = V_215 -> V_100 ;
V_57 = F_87 ( V_2 , & V_173 ) ;
if ( V_57 )
return V_57 ;
if ( V_215 -> V_221 ) {
V_57 = F_88 ( V_2 ,
V_215 -> V_222 , 1 , V_36 ) ;
if ( V_57 )
return V_57 ;
}
V_57 = F_85 ( V_2 , V_215 , V_36 ) ;
if ( V_57 )
return V_57 ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
T_2 V_223 = V_224 ;
T_1 V_225 ;
if ( V_2 -> V_115 == V_105 )
return 0 ;
V_225 = F_53 ( V_2 , V_226 ) ;
while ( V_225 != V_227 && -- V_223 ) {
F_90 ( 1000 ) ;
V_225 = F_53 ( V_2 , V_226 ) ;
}
if ( ! V_223 ) {
F_64 ( & V_2 -> V_30 -> V_45 ,
L_13 ) ;
return - V_41 ;
}
return 0 ;
}
static int
F_91 ( struct V_1 * V_2 )
{
int V_57 ;
if ( ! ( V_2 -> V_49 & V_153 ) ||
V_2 -> V_115 != V_105 )
return 0 ;
V_57 = F_83 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_86 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_92 ( V_2 ) ;
return V_57 ;
}
static int
F_93 ( struct V_1 * V_2 )
{
int V_57 ;
V_57 = F_94 ( V_2 ) ;
if ( V_57 < 0 )
return V_57 ;
else if ( ! V_57 )
goto V_228;
if ( V_229 )
F_95 ( V_2 ) ;
else {
V_57 = F_96 ( V_2 ) ;
if ( V_57 )
goto V_230;
V_2 -> V_231 = V_232 ;
}
V_57 = F_97 ( V_2 ) ;
if ( V_57 == 0 )
goto V_228;
V_57 = F_98 ( V_2 ) ;
if ( V_57 )
goto V_230;
V_57 = F_99 ( V_2 ) ;
if ( V_57 )
goto V_230;
F_100 ( V_2 ) ;
F_101 ( V_2 , V_233 , V_234 ) ;
V_228:
V_57 = F_102 ( V_2 ) ;
if ( V_57 )
goto V_230;
F_101 ( V_2 , V_235 , V_236 ) ;
F_103 ( V_2 , 1 ) ;
V_57 = F_82 ( V_2 ) ;
if ( V_57 ) {
F_64 ( & V_2 -> V_30 -> V_45 ,
L_14 ) ;
goto V_230;
}
V_57 = F_91 ( V_2 ) ;
if ( V_57 )
goto V_230;
F_68 ( V_2 ) ;
V_2 -> V_216 = 0 ;
F_100 ( V_2 ) ;
return 0 ;
V_230:
F_101 ( V_2 , V_235 , V_237 ) ;
F_64 ( & V_2 -> V_30 -> V_45 , L_15 ) ;
F_100 ( V_2 ) ;
return V_57 ;
}
static int
F_104 ( struct V_1 * V_2 )
{
T_6 V_238 ;
struct V_7 * V_8 ;
int V_57 , V_19 ;
unsigned long V_49 = 0 ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_11 * V_12 = V_2 -> V_12 ;
if ( V_2 -> V_239 == V_240 ) {
V_238 = V_241 ;
if ( ! F_5 ( V_2 ) )
V_49 |= V_242 ;
} else {
if ( V_2 -> V_49 & V_59 )
V_238 = V_243 ;
else if ( V_2 -> V_49 & V_58 )
V_238 = V_244 ;
else {
V_49 |= V_242 ;
V_238 = V_245 ;
}
}
V_2 -> V_70 = V_18 -> V_70 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_12 -> V_15 [ V_19 ] ;
sprintf ( V_8 -> V_133 , L_16 , V_18 -> V_133 , V_19 ) ;
V_57 = F_105 ( V_8 -> V_70 , V_238 ,
V_49 , V_8 -> V_133 , V_8 ) ;
if ( V_57 )
return V_57 ;
}
return 0 ;
}
static void
F_106 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_7 * V_8 ;
struct V_11 * V_12 = V_2 -> V_12 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_12 -> V_15 [ V_19 ] ;
F_107 ( V_8 -> V_70 , V_8 ) ;
}
}
static int
F_108 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_19 ;
struct V_246 * V_247 ;
if ( V_2 -> V_26 != V_27 )
return - V_41 ;
if ( F_31 ( V_54 , & V_2 -> V_55 ) )
return 0 ;
if ( F_80 ( V_2 ) )
return - V_41 ;
if ( F_109 ( V_2 ) )
return - V_41 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_170 ; V_19 ++ ) {
V_247 = & V_2 -> V_12 -> V_248 [ V_19 ] ;
F_110 ( V_2 , V_247 ) ;
}
F_33 ( V_18 ) ;
F_111 ( V_2 , V_18 -> V_249 ) ;
V_2 -> V_67 -> V_250 = 0 ;
if ( V_2 -> V_20 > 1 )
F_112 ( V_2 , 1 ) ;
F_113 ( V_2 ) ;
if ( V_18 -> V_197 & V_208 )
F_114 ( V_2 , V_251 ) ;
F_14 ( V_2 ) ;
F_115 ( V_2 , 1 ) ;
V_2 -> V_252 = 0 ;
F_74 ( V_54 , & V_2 -> V_55 ) ;
return 0 ;
}
static int
F_116 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_57 = 0 ;
F_117 () ;
if ( F_118 ( V_18 ) )
V_57 = F_108 ( V_2 , V_18 ) ;
F_119 () ;
return V_57 ;
}
static void
F_120 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
if ( V_2 -> V_26 != V_27 )
return;
if ( ! F_121 ( V_54 , & V_2 -> V_55 ) )
return;
F_122 () ;
F_123 ( & V_2 -> V_253 ) ;
F_124 ( V_18 ) ;
F_125 ( V_18 ) ;
F_126 ( V_2 ) ;
if ( V_2 -> V_254 . V_255 )
F_127 ( V_2 ) ;
F_128 ( V_2 , V_256 ) ;
F_16 ( V_2 ) ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
F_132 ( & V_2 -> V_253 ) ;
}
static void
F_133 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
F_117 () ;
if ( F_118 ( V_18 ) )
F_120 ( V_2 , V_18 ) ;
F_119 () ;
}
static int
F_134 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_29 * V_30 = V_2 -> V_30 ;
int V_57 ;
if ( V_2 -> V_26 == V_27 )
return 0 ;
V_57 = F_10 ( V_2 , V_18 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_135 ( V_2 ) ;
if ( V_57 ) {
F_64 ( & V_30 -> V_45 , L_17 ) ;
goto V_257;
}
V_57 = F_136 ( V_2 ) ;
if ( V_57 ) {
F_64 ( & V_30 -> V_45 , L_18 ) ;
goto V_258;
}
V_57 = F_104 ( V_2 ) ;
if ( V_57 ) {
F_64 ( & V_30 -> V_45 , L_19 ) ;
goto V_259;
}
F_137 ( V_2 ) ;
V_2 -> V_26 = V_27 ;
return 0 ;
V_259:
F_138 ( V_2 ) ;
V_258:
F_139 ( V_2 ) ;
V_257:
F_12 ( V_2 ) ;
return V_57 ;
}
static void
F_140 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 != V_27 )
return;
F_141 ( V_2 ) ;
F_138 ( V_2 ) ;
F_142 ( V_2 ) ;
F_106 ( V_2 ) ;
F_12 ( V_2 ) ;
F_139 ( V_2 ) ;
V_2 -> V_26 = 0 ;
}
void F_143 ( struct V_17 * V_18 , int V_20 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_7 * V_8 ;
int V_19 ;
F_77 ( V_54 , & V_2 -> V_55 ) ;
if ( V_2 -> V_239 == V_240 ) {
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_2 -> V_12 -> V_15 [ V_19 ] ;
F_3 ( V_8 ) ;
}
}
F_129 ( V_2 ) ;
F_140 ( V_2 ) ;
V_2 -> V_239 = 0 ;
V_2 -> V_20 = V_20 ;
if ( F_134 ( V_2 ) )
goto V_260;
if ( F_118 ( V_18 ) )
F_108 ( V_2 , V_18 ) ;
V_260:
F_34 ( V_18 ) ;
}
static int F_144 ( struct V_1 * V_2 )
{
int V_57 = 0 ;
V_2 -> V_67 = F_7 ( sizeof( struct V_261 ) ,
V_16 ) ;
if ( ! V_2 -> V_67 ) {
F_64 ( & V_2 -> V_30 -> V_45 ,
L_20 ) ;
V_57 = - V_21 ;
goto V_230;
}
V_2 -> V_12 = F_7 ( sizeof( struct V_11 ) ,
V_16 ) ;
if ( ! V_2 -> V_12 ) {
F_64 ( & V_2 -> V_30 -> V_45 ,
L_20 ) ;
F_9 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
V_57 = - V_21 ;
goto V_230;
}
V_2 -> V_67 -> V_262 . V_263 = V_264 ;
V_2 -> V_67 -> V_262 . V_265 = V_266 ;
V_2 -> V_67 -> V_262 . V_267 = V_268 ;
V_230:
return V_57 ;
}
static void F_145 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
if ( V_2 -> V_67 -> V_269 . V_270 ) {
F_146 ( V_2 -> V_67 -> V_269 . V_270 ) ;
V_2 -> V_67 -> V_269 . V_270 = NULL ;
}
F_9 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
}
int F_147 ( struct V_17 * V_18 , int V_271 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_7 * V_8 ;
struct V_246 * V_247 ;
int V_19 ;
int V_82 ;
F_32 ( V_18 ) ;
if ( F_118 ( V_18 ) )
F_120 ( V_2 , V_18 ) ;
F_140 ( V_2 ) ;
V_2 -> V_20 = 1 ;
V_2 -> V_239 = V_271 ;
V_82 = F_134 ( V_2 ) ;
if ( V_82 ) {
F_34 ( V_18 ) ;
return V_82 ;
}
V_82 = F_109 ( V_2 ) ;
if ( V_82 ) {
F_140 ( V_2 ) ;
F_34 ( V_18 ) ;
return V_82 ;
}
for ( V_19 = 0 ; V_19 < V_2 -> V_170 ; V_19 ++ ) {
V_247 = & V_2 -> V_12 -> V_248 [ V_19 ] ;
F_110 ( V_2 , V_247 ) ;
}
if ( V_2 -> V_239 == V_240 ) {
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_2 -> V_12 -> V_15 [ V_19 ] ;
F_4 ( V_8 ) ;
}
}
F_74 ( V_54 , & V_2 -> V_55 ) ;
return 0 ;
}
static int
F_148 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
if ( F_149 ( V_272 , & V_2 -> V_55 ) )
return - V_273 ;
F_32 ( V_18 ) ;
F_133 ( V_2 , V_18 ) ;
F_116 ( V_2 , V_18 ) ;
F_34 ( V_18 ) ;
F_77 ( V_272 , & V_2 -> V_55 ) ;
return 0 ;
}
int
F_150 ( struct V_1 * V_2 )
{
int V_57 = 0 ;
struct V_17 * V_18 = V_2 -> V_18 ;
if ( F_149 ( V_272 , & V_2 -> V_55 ) )
return - V_273 ;
if ( V_2 -> V_26 == V_27 ) {
F_32 ( V_18 ) ;
if ( F_118 ( V_18 ) )
F_120 ( V_2 , V_18 ) ;
F_140 ( V_2 ) ;
if ( F_118 ( V_18 ) ) {
V_57 = F_134 ( V_2 ) ;
if ( ! V_57 )
F_108 ( V_2 , V_18 ) ;
}
F_34 ( V_18 ) ;
}
F_77 ( V_272 , & V_2 -> V_55 ) ;
return V_57 ;
}
static int
F_151 ( struct V_1 * V_2 ,
struct V_17 * V_18 , T_2 V_274 )
{
int V_57 ;
struct V_29 * V_30 = V_2 -> V_30 ;
V_2 -> V_275 = 0 ;
V_2 -> V_276 = 38 ;
V_18 -> V_277 = & V_278 ;
V_18 -> V_279 = 5 * V_280 ;
F_152 ( V_18 , V_18 -> V_249 ) ;
F_153 ( V_18 , & V_281 ) ;
V_18 -> V_282 = V_199 | V_200 |
V_202 | V_201 ;
if ( V_2 -> V_179 & V_205 )
V_18 -> V_282 |= V_206 | V_207 ;
if ( V_274 )
V_18 -> V_282 |= V_283 ;
V_18 -> V_198 = V_18 -> V_282 ;
if ( V_2 -> V_179 & V_284 )
V_18 -> V_282 |= V_285 ;
if ( V_2 -> V_179 & V_286 )
V_18 -> V_282 |= V_208 ;
V_18 -> V_197 |= V_18 -> V_282 |
V_287 | V_204 ;
V_18 -> V_70 = V_2 -> V_37 [ 0 ] . V_69 ;
F_124 ( V_18 ) ;
V_57 = F_154 ( V_18 ) ;
if ( V_57 ) {
F_64 ( & V_30 -> V_45 , L_21 ) ;
return V_57 ;
}
return 0 ;
}
static int F_155 ( struct V_29 * V_30 , T_2 * V_274 )
{
if ( ! F_156 ( V_30 , F_157 ( 64 ) ) &&
! F_158 ( V_30 , F_157 ( 64 ) ) )
* V_274 = 1 ;
else if ( ! F_156 ( V_30 , F_157 ( 32 ) ) &&
! F_158 ( V_30 , F_157 ( 32 ) ) )
* V_274 = 0 ;
else {
F_64 ( & V_30 -> V_45 , L_22 ) ;
return - V_41 ;
}
return 0 ;
}
static int
F_159 ( struct V_1 * V_2 , T_5 V_13 )
{
V_2 -> V_37 = F_50 ( V_13 , sizeof( struct V_288 ) ,
V_16 ) ;
if ( V_2 -> V_37 )
return 0 ;
F_64 ( & V_2 -> V_30 -> V_45 , L_23 ) ;
return - V_21 ;
}
static int T_7
F_160 ( struct V_29 * V_30 , const struct V_289 * V_290 )
{
struct V_17 * V_18 = NULL ;
struct V_1 * V_2 = NULL ;
int V_57 ;
T_8 V_291 ;
T_8 V_274 ;
char V_292 [ V_293 ] ;
V_57 = F_161 ( V_30 ) ;
if ( V_57 )
return V_57 ;
if ( ! ( F_162 ( V_30 , 0 ) & V_294 ) ) {
V_57 = - V_295 ;
goto V_296;
}
V_57 = F_155 ( V_30 , & V_274 ) ;
if ( V_57 )
goto V_296;
V_57 = F_163 ( V_30 , V_297 ) ;
if ( V_57 )
goto V_296;
F_164 ( V_30 ) ;
F_165 ( V_30 ) ;
V_18 = F_166 ( sizeof( struct V_1 ) ) ;
if ( ! V_18 ) {
F_64 ( & V_30 -> V_45 , L_24 ) ;
V_57 = - V_21 ;
goto V_298;
}
F_167 ( V_18 , & V_30 -> V_45 ) ;
V_2 = F_30 ( V_18 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_30 = V_30 ;
if ( F_144 ( V_2 ) )
goto V_299;
V_2 -> V_300 = V_301 ;
V_291 = V_30 -> V_302 ;
V_2 -> V_67 -> V_291 = V_291 ;
F_168 ( & V_2 -> V_67 -> V_303 ) ;
F_169 ( & V_2 -> V_67 -> V_304 ) ;
F_170 ( & V_2 -> V_253 ) ;
F_171 ( & V_2 -> V_305 ) ;
V_57 = F_60 ( V_2 ) ;
if ( V_57 )
goto V_259;
V_2 -> V_306 = V_2 -> V_67 -> V_68 ;
if ( V_2 -> V_115 != V_123 )
F_172 ( V_2 ) ;
V_57 = F_173 ( V_2 ) ;
if ( V_57 ) {
F_64 ( & V_30 -> V_45 , L_25 ) ;
goto V_307;
}
V_57 = F_174 ( V_2 ) ;
if ( V_57 )
goto V_307;
V_2 -> V_49 |= V_308 ;
V_57 = V_2 -> V_124 -> V_309 ( V_2 ) ;
if ( V_57 ) {
F_64 ( & V_30 -> V_45 , L_26 ) ;
goto V_310;
}
if ( F_25 ( V_2 ) )
F_28 ( & V_30 -> V_45 , L_27 ) ;
if ( V_2 -> V_306 == 0 ) {
F_67 ( V_2 , V_292 ) ;
F_175 ( L_28 ,
F_176 ( V_311 ) ,
V_292 , V_2 -> V_67 -> V_291 ) ;
}
F_19 ( V_2 ) ;
V_57 = F_159 ( V_2 , V_2 -> V_178 ) ;
if ( V_57 )
goto V_310;
F_42 ( V_2 ) ;
V_57 = F_151 ( V_2 , V_18 , V_274 ) ;
if ( V_57 )
goto V_312;
F_177 ( V_30 , V_2 ) ;
F_178 ( V_2 , V_313 , V_314 ) ;
switch ( V_2 -> V_67 -> V_151 ) {
case V_163 :
F_37 ( & V_2 -> V_30 -> V_45 , L_29 ,
V_2 -> V_18 -> V_133 ) ;
break;
case V_152 :
F_37 ( & V_2 -> V_30 -> V_45 , L_30 ,
V_2 -> V_18 -> V_133 ) ;
break;
}
F_179 ( V_2 ) ;
F_180 ( V_2 ) ;
return 0 ;
V_312:
F_44 ( V_2 ) ;
F_9 ( V_2 -> V_37 ) ;
V_310:
F_181 ( V_2 , 0 ) ;
V_307:
F_47 ( V_2 ) ;
V_259:
F_145 ( V_2 ) ;
V_299:
F_182 ( V_18 ) ;
V_298:
F_183 ( V_30 ) ;
V_296:
F_177 ( V_30 , NULL ) ;
F_184 ( V_30 ) ;
return V_57 ;
}
static void T_9 F_185 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 ;
V_2 = F_186 ( V_30 ) ;
if ( V_2 == NULL )
return;
V_18 = V_2 -> V_18 ;
F_187 ( V_2 ) ;
F_188 ( V_18 ) ;
F_140 ( V_2 ) ;
if ( V_2 -> V_85 != NULL )
F_9 ( V_2 -> V_85 ) ;
if ( V_2 -> V_88 != NULL )
F_9 ( V_2 -> V_88 ) ;
F_181 ( V_2 , 0 ) ;
F_77 ( V_272 , & V_2 -> V_55 ) ;
F_189 ( V_2 ) ;
F_44 ( V_2 ) ;
F_9 ( V_2 -> V_37 ) ;
F_190 ( V_2 ) ;
F_47 ( V_2 ) ;
F_100 ( V_2 ) ;
F_191 ( V_30 ) ;
F_183 ( V_30 ) ;
F_184 ( V_30 ) ;
F_177 ( V_30 , NULL ) ;
F_145 ( V_2 ) ;
F_182 ( V_18 ) ;
}
static int F_192 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_186 ( V_30 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
int V_315 ;
F_32 ( V_18 ) ;
F_187 ( V_2 ) ;
if ( F_118 ( V_18 ) )
F_133 ( V_2 , V_18 ) ;
F_181 ( V_2 , 0 ) ;
F_77 ( V_272 , & V_2 -> V_55 ) ;
V_315 = F_193 ( V_30 ) ;
if ( V_315 )
return V_315 ;
if ( F_194 ( V_2 ) ) {
F_195 ( V_30 , V_316 , 1 ) ;
F_195 ( V_30 , V_317 , 1 ) ;
}
return 0 ;
}
static void F_196 ( struct V_29 * V_30 )
{
if ( F_192 ( V_30 ) )
return;
F_184 ( V_30 ) ;
}
static int
F_197 ( struct V_29 * V_30 , T_10 V_55 )
{
int V_315 ;
V_315 = F_192 ( V_30 ) ;
if ( V_315 )
return V_315 ;
F_198 ( V_30 , F_199 ( V_30 , V_55 ) ) ;
return 0 ;
}
static int
F_200 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_186 ( V_30 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
int V_57 ;
V_57 = F_161 ( V_30 ) ;
if ( V_57 )
return V_57 ;
F_198 ( V_30 , V_318 ) ;
F_164 ( V_30 ) ;
F_201 ( V_30 ) ;
V_57 = V_2 -> V_124 -> V_309 ( V_2 ) ;
if ( V_57 ) {
F_64 ( & V_30 -> V_45 , L_31 ) ;
return V_57 ;
}
if ( F_118 ( V_18 ) ) {
V_57 = F_116 ( V_2 , V_18 ) ;
if ( V_57 )
goto V_319;
F_76 ( V_18 , V_320 ) ;
}
V_319:
F_34 ( V_18 ) ;
F_178 ( V_2 , V_313 , V_314 ) ;
return 0 ;
}
static int F_202 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
int V_57 ;
V_57 = F_134 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_108 ( V_2 , V_18 ) ;
if ( V_57 )
goto V_230;
F_203 ( V_18 ) ;
return 0 ;
V_230:
F_140 ( V_2 ) ;
return V_57 ;
}
static int F_204 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
F_120 ( V_2 , V_18 ) ;
return 0 ;
}
static void
F_179 ( struct V_1 * V_2 )
{
void * V_321 ;
int V_36 ;
if ( ! V_322 )
return;
F_170 ( & V_2 -> V_323 ) ;
V_321 = F_50 ( V_324 , sizeof( struct V_325 ) ,
V_16 ) ;
if ( ! V_321 )
return;
V_2 -> V_254 . V_326 = V_324 ;
V_2 -> V_254 . V_327 = (struct V_325 * ) V_321 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_254 . V_326 ; V_36 ++ )
F_205 ( & V_2 -> V_254 . V_327 [ V_36 ] ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
if ( V_2 -> V_254 . V_326 && V_2 -> V_254 . V_327 )
F_9 ( V_2 -> V_254 . V_327 ) ;
V_2 -> V_254 . V_327 = NULL ;
V_2 -> V_254 . V_326 = 0 ;
}
static void F_206 ( struct V_1 * V_2 ,
T_11 V_328 , T_12 V_187 , struct V_3 * V_4 )
{
struct V_329 * V_330 ;
struct V_331 * V_332 ;
struct V_333 * V_334 ;
struct V_335 * V_336 ;
T_1 V_5 ;
T_11 V_337 ;
V_5 = V_4 -> V_5 ;
V_330 = & V_4 -> V_338 [ V_4 -> V_5 ] ;
V_332 = (struct V_331 * ) V_330 ;
memset ( V_332 , 0 , sizeof( struct V_331 ) ) ;
V_332 -> V_339 = F_207 ( V_340 << 23 ) ;
V_337 = V_341 | ( ( T_11 ) ( V_2 -> V_306 ) << 16 ) ;
V_332 -> V_342 = F_207 ( V_337 ) ;
V_334 = (struct V_333 * ) & ( V_332 -> V_343 [ 0 ] ) ;
V_334 -> V_344 = V_187 ? V_345 : V_346 ;
memcpy ( V_334 -> V_39 , & V_328 , V_40 ) ;
V_336 = (struct V_335 * ) & V_332 -> V_343 [ 1 ] ;
V_336 -> V_187 = V_187 ;
V_4 -> V_5 = F_208 ( V_5 , V_4 -> V_347 ) ;
F_122 () ;
}
static void
F_209 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_329 * V_348 ,
struct V_349 * V_350 )
{
struct V_351 * V_352 = (struct V_351 * ) ( V_350 -> V_104 ) ;
struct V_353 * V_354 , * V_355 ;
struct V_356 * V_357 , * V_358 ;
struct V_325 * V_321 ;
T_11 V_359 = 0 ;
T_12 V_187 = 0 ;
T_2 V_360 ;
if ( ! F_210 ( V_352 -> V_361 , V_2 -> V_39 ) )
return;
if ( V_2 -> V_254 . V_255 >= V_2 -> V_254 . V_326 )
return;
if ( V_2 -> V_49 & V_153 )
V_187 = V_348 -> V_362 ;
memcpy ( & V_359 , V_352 -> V_361 , V_40 ) ;
V_360 = F_211 ( V_359 ) & ( V_324 - 1 ) ;
V_321 = & ( V_2 -> V_254 . V_327 [ V_360 ] ) ;
F_212 (tmp_fil, tmp_hnode, n, head, fnode) {
if ( ! memcmp ( V_355 -> V_363 , & V_359 , V_40 ) &&
V_355 -> V_187 == V_187 ) {
if ( V_301 >
( V_364 * V_280 + V_355 -> V_365 ) )
F_206 ( V_2 , V_359 , V_187 ,
V_4 ) ;
V_355 -> V_365 = V_301 ;
return;
}
}
V_354 = F_7 ( sizeof( struct V_353 ) , V_366 ) ;
if ( ! V_354 )
return;
F_206 ( V_2 , V_359 , V_187 , V_4 ) ;
V_354 -> V_365 = V_301 ;
V_354 -> V_187 = V_187 ;
memcpy ( V_354 -> V_363 , & V_359 , V_40 ) ;
F_123 ( & V_2 -> V_323 ) ;
F_213 ( & ( V_354 -> V_367 ) , V_321 ) ;
V_2 -> V_254 . V_255 ++ ;
F_132 ( & V_2 -> V_323 ) ;
}
static int
F_214 ( struct V_1 * V_2 ,
struct V_329 * V_348 ,
struct V_349 * V_350 )
{
T_2 V_368 = 0 , V_369 = 0 ;
T_5 V_49 = 0 , V_370 = 0 ;
int V_371 , V_372 , V_373 ;
struct V_329 * V_330 ;
struct V_374 * V_375 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_5 V_376 = F_215 ( V_350 -> V_376 ) ;
T_1 V_5 = V_4 -> V_5 ;
if ( V_376 == V_377 ) {
V_375 = (struct V_374 * ) V_350 -> V_104 ;
V_49 = V_378 ;
V_370 = V_375 -> V_379 ;
} else if ( F_216 ( V_350 ) ) {
V_49 = V_380 ;
V_370 = F_217 ( V_350 ) ;
}
if ( F_218 ( V_2 -> V_188 ) ) {
if ( V_370 && ! ( V_2 -> V_49 & V_186 ) )
return - V_41 ;
if ( V_370 && ( V_2 -> V_49 & V_186 ) )
goto V_381;
V_49 = V_380 ;
V_370 = V_2 -> V_188 ;
}
V_381:
F_219 ( V_348 , V_370 ) ;
F_220 ( V_348 , V_49 , V_368 ) ;
if ( * ( V_350 -> V_104 ) & V_210 ) {
V_49 |= V_210 ;
memcpy ( & V_348 -> V_382 , V_350 -> V_104 , V_40 ) ;
}
V_368 = V_383 ;
if ( ( V_2 -> V_18 -> V_197 & ( V_206 | V_207 ) ) &&
F_221 ( V_350 ) -> V_384 > 0 ) {
V_369 = F_222 ( V_350 ) + F_223 ( V_350 ) ;
V_348 -> V_385 = F_224 ( F_221 ( V_350 ) -> V_384 ) ;
V_348 -> V_386 = V_369 ;
V_368 = ( V_376 == V_387 ) ? V_388 : V_389 ;
V_371 = 0 ;
V_372 = 2 ;
if ( V_49 & V_380 ) {
V_348 -> V_386 += V_390 ;
V_348 -> V_391 = V_390 ;
V_348 -> V_392 = V_390 ;
V_49 |= V_378 ;
V_330 = & V_4 -> V_338 [ V_5 ] ;
V_4 -> V_393 [ V_5 ] . V_350 = NULL ;
V_373 = F_225 ( ( int ) sizeof( struct V_329 ) -
V_372 , V_369 + V_390 ) ;
V_375 = (struct V_374 * ) ( ( char * ) V_330 + 2 ) ;
F_226 ( V_350 , V_375 , 12 ) ;
V_375 -> V_394 = F_227 ( V_377 ) ;
V_375 -> V_379 = F_227 ( V_370 ) ;
F_228 ( V_350 , 12 ,
( char * ) V_375 + 16 , V_373 - 16 ) ;
V_371 = V_373 - V_390 ;
V_372 = 0 ;
V_5 = F_208 ( V_5 , V_4 -> V_347 ) ;
}
while ( V_371 < V_369 ) {
V_373 = F_225 ( ( int ) sizeof( struct V_329 ) -
V_372 , ( V_369 - V_371 ) ) ;
V_330 = & V_4 -> V_338 [ V_5 ] ;
V_4 -> V_393 [ V_5 ] . V_350 = NULL ;
F_228 ( V_350 , V_371 ,
( char * ) V_330 + V_372 , V_373 ) ;
V_371 += V_373 ;
V_372 = 0 ;
V_5 = F_208 ( V_5 , V_4 -> V_347 ) ;
}
V_4 -> V_5 = V_5 ;
F_122 () ;
V_2 -> V_28 . V_395 ++ ;
} else if ( V_350 -> V_396 == V_397 ) {
T_2 V_398 ;
if ( V_376 == V_399 ) {
V_398 = F_229 ( V_350 ) -> V_376 ;
if ( V_398 == V_400 )
V_368 = V_401 ;
else if ( V_398 == V_402 )
V_368 = V_403 ;
} else if ( V_376 == V_387 ) {
V_398 = F_230 ( V_350 ) -> V_404 ;
if ( V_398 == V_400 )
V_368 = V_405 ;
else if ( V_398 == V_402 )
V_368 = V_406 ;
}
}
V_348 -> V_391 += F_222 ( V_350 ) ;
V_348 -> V_392 += F_231 ( V_350 ) ;
F_220 ( V_348 , V_49 , V_368 ) ;
return 0 ;
}
static int
F_232 ( struct V_29 * V_30 ,
struct V_349 * V_350 , struct V_407 * V_408 )
{
struct V_409 * V_410 ;
struct V_411 * V_412 ;
int V_36 , V_413 ;
T_13 V_414 ;
V_413 = F_221 ( V_350 ) -> V_413 ;
V_410 = & V_408 -> V_415 [ 0 ] ;
V_414 = F_233 ( V_30 , V_350 -> V_104 ,
F_234 ( V_350 ) , V_416 ) ;
if ( F_235 ( V_30 , V_414 ) )
goto V_417;
V_410 -> V_418 = V_414 ;
V_410 -> V_419 = F_234 ( V_350 ) ;
for ( V_36 = 0 ; V_36 < V_413 ; V_36 ++ ) {
V_412 = & F_221 ( V_350 ) -> V_420 [ V_36 ] ;
V_410 = & V_408 -> V_415 [ V_36 + 1 ] ;
V_414 = F_236 ( V_30 , V_412 -> V_421 , V_412 -> V_422 ,
V_412 -> V_14 , V_416 ) ;
if ( F_235 ( V_30 , V_414 ) )
goto V_423;
V_410 -> V_418 = V_414 ;
V_410 -> V_419 = V_412 -> V_14 ;
}
return 0 ;
V_423:
while ( -- V_36 >= 0 ) {
V_410 = & V_408 -> V_415 [ V_36 + 1 ] ;
F_237 ( V_30 , V_410 -> V_418 , V_410 -> V_419 , V_416 ) ;
}
V_410 = & V_408 -> V_415 [ 0 ] ;
F_238 ( V_30 , V_410 -> V_418 , F_234 ( V_350 ) , V_416 ) ;
V_417:
return - V_21 ;
}
static void
F_239 ( struct V_29 * V_30 , struct V_349 * V_350 ,
struct V_407 * V_408 )
{
struct V_409 * V_410 = & V_408 -> V_415 [ 0 ] ;
int V_413 = F_221 ( V_350 ) -> V_413 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_413 ; V_36 ++ ) {
V_410 = & V_408 -> V_415 [ V_36 + 1 ] ;
F_237 ( V_30 , V_410 -> V_418 , V_410 -> V_419 , V_416 ) ;
}
V_410 = & V_408 -> V_415 [ 0 ] ;
F_238 ( V_30 , V_410 -> V_418 , F_234 ( V_350 ) , V_416 ) ;
V_408 -> V_350 = NULL ;
}
static inline void
F_240 ( T_11 * V_424 )
{
V_424 [ 0 ] = 0ULL ;
V_424 [ 2 ] = 0ULL ;
V_424 [ 7 ] = 0ULL ;
}
T_14
F_241 ( struct V_349 * V_350 , struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_407 * V_408 ;
struct V_409 * V_425 ;
struct V_329 * V_330 , * V_348 ;
struct V_29 * V_30 ;
struct V_351 * V_352 ;
int V_426 = 0 ;
int V_36 , V_427 ;
T_1 V_5 ;
int V_428 ;
T_1 V_168 = V_4 -> V_347 ;
if ( ! F_31 ( V_54 , & V_2 -> V_55 ) ) {
F_242 ( V_18 ) ;
return V_429 ;
}
if ( V_2 -> V_49 & V_192 ) {
V_352 = (struct V_351 * ) V_350 -> V_104 ;
if ( F_210 ( V_352 -> V_361 ,
V_2 -> V_39 ) )
goto V_430;
}
V_428 = F_221 ( V_350 ) -> V_413 + 1 ;
if ( ! F_243 ( V_350 ) && V_428 > V_431 ) {
for ( V_36 = 0 ; V_36 < ( V_428 - V_431 ) ; V_36 ++ )
V_426 += F_221 ( V_350 ) -> V_420 [ V_36 ] . V_14 ;
if ( ! F_244 ( V_350 , V_426 ) )
goto V_430;
V_428 = 1 + F_221 ( V_350 ) -> V_413 ;
}
if ( F_218 ( F_245 ( V_4 ) <= V_432 ) ) {
F_242 ( V_18 ) ;
if ( F_245 ( V_4 ) > V_432 )
F_203 ( V_18 ) ;
else {
V_2 -> V_28 . V_433 ++ ;
return V_429 ;
}
}
V_5 = V_4 -> V_5 ;
V_408 = & V_4 -> V_393 [ V_5 ] ;
V_30 = V_2 -> V_30 ;
V_348 = V_330 = & V_4 -> V_338 [ V_5 ] ;
F_240 ( ( T_11 * ) V_330 ) ;
if ( F_232 ( V_30 , V_350 , V_408 ) ) {
V_2 -> V_28 . V_434 ++ ;
goto V_430;
}
V_408 -> V_350 = V_350 ;
V_408 -> V_428 = V_428 ;
F_246 ( V_348 , V_428 , V_350 -> V_435 ) ;
F_247 ( V_348 , V_2 -> V_306 ) ;
for ( V_36 = 0 ; V_36 < V_428 ; V_36 ++ ) {
V_427 = V_36 % 4 ;
if ( ( V_427 == 0 ) && ( V_36 > 0 ) ) {
V_5 = F_208 ( V_5 , V_168 ) ;
V_330 = & V_4 -> V_338 [ V_5 ] ;
F_240 ( ( T_11 * ) V_330 ) ;
V_4 -> V_393 [ V_5 ] . V_350 = NULL ;
}
V_425 = & V_408 -> V_415 [ V_36 ] ;
V_330 -> V_436 [ V_427 ] = F_224 ( V_425 -> V_419 ) ;
switch ( V_427 ) {
case 0 :
V_330 -> V_437 = F_207 ( V_425 -> V_418 ) ;
break;
case 1 :
V_330 -> V_438 = F_207 ( V_425 -> V_418 ) ;
break;
case 2 :
V_330 -> V_439 = F_207 ( V_425 -> V_418 ) ;
break;
case 3 :
V_330 -> V_440 = F_207 ( V_425 -> V_418 ) ;
break;
}
}
V_4 -> V_5 = F_208 ( V_5 , V_168 ) ;
F_122 () ;
if ( F_218 ( F_214 ( V_2 , V_348 , V_350 ) ) )
goto V_441;
if ( V_322 )
F_209 ( V_2 , V_4 , V_348 , V_350 ) ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_28 . V_442 += V_350 -> V_435 ;
V_2 -> V_28 . V_443 ++ ;
return V_444 ;
V_441:
F_239 ( V_30 , V_350 , V_408 ) ;
V_430:
V_2 -> V_28 . V_445 ++ ;
F_248 ( V_350 ) ;
return V_444 ;
}
static int F_249 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_446 , V_447 , V_448 ;
int V_449 = 0 ;
V_446 = F_53 ( V_2 , V_450 ) ;
V_447 = F_250 ( V_446 ) ;
V_448 = F_251 ( V_446 ) ;
if ( V_447 == V_451 ) {
F_64 ( & V_18 -> V_45 ,
L_32
L_33 ,
V_448 ) ;
V_449 = 1 ;
} else if ( V_447 == V_452 ) {
if ( V_2 -> V_446 == V_453 ) {
F_64 ( & V_18 -> V_45 ,
L_34
L_35
L_36 ,
V_448 ) ;
}
} else {
if ( V_2 -> V_446 == V_452 ) {
F_37 ( & V_18 -> V_45 ,
L_37
L_38 , V_448 ) ;
}
}
V_2 -> V_446 = V_447 ;
return V_449 ;
}
void F_252 ( struct V_1 * V_2 , int V_250 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
if ( V_2 -> V_67 -> V_250 && ! V_250 ) {
F_253 ( V_18 , L_39 ) ;
V_2 -> V_67 -> V_250 = 0 ;
if ( F_118 ( V_18 ) ) {
F_124 ( V_18 ) ;
F_242 ( V_18 ) ;
}
} else if ( ! V_2 -> V_67 -> V_250 && V_250 ) {
F_253 ( V_18 , L_40 ) ;
V_2 -> V_67 -> V_250 = 1 ;
if ( F_118 ( V_18 ) ) {
F_254 ( V_18 ) ;
F_255 ( V_18 ) ;
}
}
}
static void F_256 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
if ( F_31 ( V_272 , & V_2 -> V_55 ) )
return;
F_64 ( & V_18 -> V_45 , L_41 ) ;
if ( ++ V_2 -> V_454 >= V_455 )
V_2 -> V_216 = 1 ;
else
V_2 -> V_252 = 1 ;
}
static struct V_456 * F_257 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_456 * V_28 = & V_18 -> V_28 ;
V_28 -> V_267 = V_2 -> V_28 . V_457 + V_2 -> V_28 . V_458 ;
V_28 -> V_459 = V_2 -> V_28 . V_460 ;
V_28 -> V_461 = V_2 -> V_28 . V_462 + V_2 -> V_28 . V_463 ;
V_28 -> V_464 = V_2 -> V_28 . V_442 ;
V_28 -> V_465 = V_2 -> V_28 . V_466 ;
V_28 -> V_467 = V_2 -> V_28 . V_445 ;
return V_28 ;
}
static T_15 F_258 ( struct V_1 * V_2 )
{
T_1 V_468 ;
V_468 = F_56 ( V_2 -> V_73 ) ;
if ( ! ( V_468 & V_2 -> V_72 ) )
return V_469 ;
V_468 = F_56 ( V_2 -> V_75 ) ;
if ( ! F_259 ( V_468 ) )
return V_469 ;
F_2 ( 0xffffffff , V_2 -> V_65 ) ;
F_56 ( V_2 -> V_73 ) ;
F_56 ( V_2 -> V_73 ) ;
return V_470 ;
}
static T_15 V_241 ( int V_70 , void * V_104 )
{
struct V_7 * V_8 = V_104 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_49 & V_59 )
goto V_319;
else if ( V_2 -> V_49 & V_58 ) {
F_2 ( 0xffffffff , V_2 -> V_65 ) ;
goto V_319;
}
if ( F_258 ( V_2 ) == V_469 )
return V_469 ;
V_319:
V_2 -> V_471 ++ ;
F_4 ( V_8 ) ;
return V_470 ;
}
static T_15 V_245 ( int V_70 , void * V_104 )
{
struct V_7 * V_8 = V_104 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_258 ( V_2 ) == V_469 )
return V_469 ;
F_260 ( & V_8 -> V_22 ) ;
return V_470 ;
}
static T_15 V_244 ( int V_70 , void * V_104 )
{
struct V_7 * V_8 = V_104 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_2 ( 0xffffffff , V_2 -> V_65 ) ;
F_260 ( & V_8 -> V_22 ) ;
return V_470 ;
}
static T_15 V_243 ( int V_70 , void * V_104 )
{
struct V_7 * V_8 = V_104 ;
F_260 ( & V_8 -> V_22 ) ;
return V_470 ;
}
static int F_261 ( struct V_1 * V_2 )
{
T_1 V_472 , V_473 ;
int V_13 = 0 , V_36 ;
struct V_407 * V_474 ;
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_409 * V_412 ;
int V_319 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_262 ( & V_2 -> V_253 ) )
return 1 ;
V_472 = V_4 -> V_472 ;
V_473 = F_263 ( * ( V_4 -> V_473 ) ) ;
while ( V_472 != V_473 ) {
V_474 = & V_4 -> V_393 [ V_472 ] ;
if ( V_474 -> V_350 ) {
V_412 = & V_474 -> V_415 [ 0 ] ;
F_238 ( V_30 , V_412 -> V_418 , V_412 -> V_419 ,
V_416 ) ;
V_412 -> V_418 = 0ULL ;
for ( V_36 = 1 ; V_36 < V_474 -> V_428 ; V_36 ++ ) {
V_412 ++ ;
F_237 ( V_30 , V_412 -> V_418 , V_412 -> V_419 ,
V_416 ) ;
V_412 -> V_418 = 0ULL ;
}
V_2 -> V_28 . V_460 ++ ;
F_248 ( V_474 -> V_350 ) ;
V_474 -> V_350 = NULL ;
}
V_472 = F_208 ( V_472 , V_4 -> V_347 ) ;
if ( ++ V_13 >= V_475 )
break;
}
if ( V_13 && F_118 ( V_18 ) ) {
V_4 -> V_472 = V_472 ;
F_122 () ;
if ( F_264 ( V_18 ) && F_265 ( V_18 ) ) {
if ( F_245 ( V_4 ) > V_432 ) {
F_255 ( V_18 ) ;
V_2 -> V_28 . V_476 ++ ;
}
}
V_2 -> V_454 = 0 ;
}
V_473 = F_263 ( * ( V_4 -> V_473 ) ) ;
V_319 = ( V_472 == V_473 ) ;
F_132 ( & V_2 -> V_253 ) ;
return V_319 ;
}
static int V_23 ( struct V_477 * V_22 , int V_478 )
{
struct V_7 * V_8 =
F_266 ( V_22 , struct V_7 , V_22 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_479 ;
int V_480 ;
V_479 = F_261 ( V_2 ) ;
V_480 = F_267 ( V_8 , V_478 ) ;
if ( ( V_480 < V_478 ) && V_479 ) {
F_268 ( & V_8 -> V_22 ) ;
if ( F_31 ( V_54 , & V_2 -> V_55 ) )
F_4 ( V_8 ) ;
}
return V_480 ;
}
static int V_25 ( struct V_477 * V_22 , int V_478 )
{
struct V_7 * V_8 =
F_266 ( V_22 , struct V_7 , V_22 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_480 ;
V_480 = F_267 ( V_8 , V_478 ) ;
if ( V_480 < V_478 ) {
F_268 ( & V_8 -> V_22 ) ;
if ( F_31 ( V_54 , & V_2 -> V_55 ) )
F_4 ( V_8 ) ;
}
return V_480 ;
}
static void F_269 ( struct V_17 * V_18 )
{
int V_19 ;
struct V_7 * V_8 ;
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
F_270 ( V_2 -> V_70 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_12 -> V_15 [ V_19 ] ;
V_245 ( V_2 -> V_70 , V_8 ) ;
}
F_271 ( V_2 -> V_70 ) ;
}
static void
F_103 ( struct V_1 * V_2 , T_2 V_481 )
{
T_1 V_482 ;
V_482 = V_2 -> V_306 & 0xf ;
V_482 |= V_481 << 7 ;
V_482 |= ( V_301 - V_2 -> V_300 ) << 8 ;
F_101 ( V_2 , V_483 , V_482 ) ;
V_2 -> V_300 = V_301 ;
}
static int
F_272 ( struct V_1 * V_2 , T_2 V_55 )
{
T_1 V_482 ;
F_273 ( V_55 != V_484 &&
V_55 != V_485 ) ;
if ( F_54 ( V_2 ) )
return - V_41 ;
V_482 = F_53 ( V_2 , V_486 ) ;
if ( V_55 == V_484 )
F_274 ( V_482 , V_2 -> V_306 ) ;
else if ( V_55 == V_485 )
F_275 ( V_482 , V_2 -> V_306 ) ;
F_101 ( V_2 , V_486 , V_482 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
static int
F_276 ( struct V_1 * V_2 )
{
T_1 V_482 ;
if ( F_54 ( V_2 ) )
return - V_273 ;
V_482 = F_53 ( V_2 , V_486 ) ;
F_277 ( V_482 , V_2 -> V_306 ) ;
F_101 ( V_2 , V_486 , V_482 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
static void
F_181 ( struct V_1 * V_2 , T_2 V_487 )
{
T_1 V_482 ;
if ( F_54 ( V_2 ) )
goto V_57;
V_482 = F_53 ( V_2 , V_108 ) ;
F_278 ( V_482 , V_2 -> V_306 ) ;
F_101 ( V_2 , V_108 , V_482 ) ;
if ( V_487 ) {
F_101 ( V_2 , V_235 , V_237 ) ;
F_37 ( & V_2 -> V_30 -> V_45 ,
L_42 ) ;
} else if ( ! ( V_482 & 0x11111111 ) )
F_101 ( V_2 , V_235 , V_488 ) ;
V_482 = F_53 ( V_2 , V_486 ) ;
F_277 ( V_482 , V_2 -> V_306 ) ;
F_101 ( V_2 , V_486 , V_482 ) ;
F_57 ( V_2 ) ;
V_57:
V_2 -> V_489 = 0 ;
F_77 ( V_490 , & V_2 -> V_55 ) ;
F_77 ( V_272 , & V_2 -> V_55 ) ;
}
static int
F_279 ( struct V_1 * V_2 )
{
int V_491 , V_55 ;
V_55 = F_53 ( V_2 , V_486 ) ;
V_491 = F_53 ( V_2 , V_108 ) ;
if ( ( ( V_55 & 0x11111111 ) == ( V_491 & 0x11111111 ) ) ||
( ( V_491 & 0x11111111 ) == ( ( V_55 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_280 ( struct V_1 * V_2 )
{
T_1 V_482 = F_53 ( V_2 , V_492 ) ;
if ( V_482 != V_493 ) {
F_28 ( & V_2 -> V_30 -> V_45 , L_43
L_44 , V_493 , V_482 ) ;
}
return 0 ;
}
static int
F_94 ( struct V_1 * V_2 )
{
T_1 V_482 , V_494 ;
T_2 V_495 = V_2 -> V_495 ;
T_2 V_306 = V_2 -> V_306 ;
T_2 V_82 ;
if ( F_121 ( V_490 , & V_2 -> V_55 ) )
return 1 ;
if ( F_54 ( V_2 ) )
return - 1 ;
V_482 = F_53 ( V_2 , V_108 ) ;
if ( ! ( V_482 & ( 1 << ( V_306 * 4 ) ) ) ) {
F_281 ( V_482 , V_306 ) ;
F_101 ( V_2 , V_108 , V_482 ) ;
}
V_494 = F_53 ( V_2 , V_235 ) ;
F_282 ( V_2 , V_496 , L_45 , V_494 ) ;
switch ( V_494 ) {
case V_488 :
F_101 ( V_2 , V_235 , V_497 ) ;
F_101 ( V_2 , V_492 , V_493 ) ;
F_103 ( V_2 , 0 ) ;
F_57 ( V_2 ) ;
return 1 ;
case V_236 :
V_82 = F_280 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_82 ;
case V_484 :
V_482 = F_53 ( V_2 , V_486 ) ;
F_274 ( V_482 , V_306 ) ;
F_101 ( V_2 , V_486 , V_482 ) ;
break;
case V_485 :
V_482 = F_53 ( V_2 , V_486 ) ;
F_275 ( V_482 , V_306 ) ;
F_101 ( V_2 , V_486 , V_482 ) ;
break;
case V_237 :
F_64 ( & V_2 -> V_30 -> V_45 , L_46 ) ;
F_57 ( V_2 ) ;
return - 1 ;
case V_497 :
case V_498 :
break;
}
F_57 ( V_2 ) ;
do {
F_90 ( 1000 ) ;
V_494 = F_53 ( V_2 , V_235 ) ;
if ( V_494 == V_498 )
continue;
} while ( ( V_494 != V_236 ) && -- V_495 );
if ( ! V_495 ) {
F_64 ( & V_2 -> V_30 -> V_45 ,
L_47 ) ;
return - 1 ;
}
if ( F_54 ( V_2 ) )
return - 1 ;
V_482 = F_53 ( V_2 , V_486 ) ;
F_277 ( V_482 , V_306 ) ;
F_101 ( V_2 , V_486 , V_482 ) ;
V_82 = F_280 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_82 ;
}
static void
F_283 ( struct V_499 * V_500 )
{
struct V_1 * V_2 = F_266 ( V_500 ,
struct V_1 , V_501 . V_500 ) ;
T_1 V_502 = 0xf ;
if ( F_54 ( V_2 ) )
goto V_503;
V_502 = F_53 ( V_2 , V_235 ) ;
if ( V_502 == V_498 ||
V_502 == V_485 ) {
F_57 ( V_2 ) ;
F_178 ( V_2 , F_283 ,
V_314 * 2 ) ;
return;
}
if ( V_2 -> V_115 == V_123 ) {
F_57 ( V_2 ) ;
goto V_504;
}
if ( V_2 -> V_505 ++ > V_2 -> V_506 ) {
F_64 ( & V_2 -> V_30 -> V_45 , L_48 ,
V_2 -> V_506 ) ;
goto V_507;
}
if ( ! F_279 ( V_2 ) ) {
V_507:
V_502 = F_53 ( V_2 , V_235 ) ;
if ( V_502 == V_484 ) {
F_101 ( V_2 , V_235 ,
V_497 ) ;
F_74 ( V_490 , & V_2 -> V_55 ) ;
F_282 ( V_2 , V_508 , L_49 ) ;
F_103 ( V_2 , 0 ) ;
F_282 ( V_2 , V_508 , L_50 ) ;
F_284 ( V_2 ) ;
}
F_57 ( V_2 ) ;
if ( ! V_2 -> V_124 -> V_309 ( V_2 ) ) {
F_178 ( V_2 , V_509 , 0 ) ;
V_2 -> V_505 = 0 ;
return;
}
goto V_503;
}
F_57 ( V_2 ) ;
V_504:
V_502 = F_53 ( V_2 , V_235 ) ;
F_282 ( V_2 , V_496 , L_51 , V_502 ) ;
switch ( V_502 ) {
case V_236 :
if ( ! V_2 -> V_124 -> V_309 ( V_2 ) ) {
F_178 ( V_2 , V_509 , 0 ) ;
V_2 -> V_505 = 0 ;
return;
}
case V_237 :
break;
default:
F_178 ( V_2 ,
F_283 , V_314 ) ;
return;
}
V_503:
F_64 ( & V_2 -> V_30 -> V_45 , L_52
L_53 , V_502 , V_2 -> V_505 ) ;
F_34 ( V_2 -> V_18 ) ;
F_181 ( V_2 , 0 ) ;
}
static void
F_285 ( struct V_499 * V_500 )
{
struct V_1 * V_2 = F_266 ( V_500 ,
struct V_1 , V_501 . V_500 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_468 ;
F_32 ( V_18 ) ;
if ( V_2 -> V_502 == V_485 ) {
if ( F_118 ( V_18 ) )
F_120 ( V_2 , V_18 ) ;
} else
F_133 ( V_2 , V_18 ) ;
V_468 = F_53 ( V_2 , V_510 ) ;
if ( V_468 & V_511 )
goto V_503;
if ( V_2 -> V_446 == V_451 )
goto V_503;
if ( F_272 ( V_2 , V_2 -> V_502 ) )
goto V_503;
V_2 -> V_505 = 0 ;
F_178 ( V_2 , F_283 , V_314 ) ;
return;
V_503:
F_64 ( & V_2 -> V_30 -> V_45 , L_54 ,
V_468 , V_2 -> V_446 ) ;
F_34 ( V_18 ) ;
F_181 ( V_2 , 1 ) ;
}
static void
F_286 ( struct V_1 * V_2 )
{
T_1 V_55 ;
V_55 = F_53 ( V_2 , V_226 ) ;
if ( V_55 == V_512 )
return;
if ( F_54 ( V_2 ) )
return;
F_101 ( V_2 , V_226 , V_512 ) ;
F_57 ( V_2 ) ;
}
void
F_287 ( struct V_1 * V_2 )
{
T_1 V_55 ;
V_2 -> V_216 = 1 ;
if ( F_54 ( V_2 ) )
return;
V_55 = F_53 ( V_2 , V_235 ) ;
if ( V_55 == V_236 ) {
F_101 ( V_2 , V_235 , V_484 ) ;
F_282 ( V_2 , V_508 , L_55 ) ;
F_103 ( V_2 , 0 ) ;
}
F_101 ( V_2 , V_226 , V_512 ) ;
F_57 ( V_2 ) ;
}
static void
F_92 ( struct V_1 * V_2 )
{
if ( F_54 ( V_2 ) )
return;
F_101 ( V_2 , V_226 , V_227 ) ;
F_282 ( V_2 , V_508 , L_56 ) ;
F_57 ( V_2 ) ;
}
static void
F_178 ( struct V_1 * V_2 ,
T_16 V_113 , int V_513 )
{
if ( F_31 ( V_514 , & V_2 -> V_55 ) )
return;
F_288 ( & V_2 -> V_501 , V_113 ) ;
F_289 ( V_515 , & V_2 -> V_501 ,
F_290 ( V_513 ) ) ;
}
static void
F_187 ( struct V_1 * V_2 )
{
while ( F_149 ( V_272 , & V_2 -> V_55 ) )
F_90 ( 10 ) ;
F_291 ( & V_2 -> V_501 ) ;
}
static void
V_509 ( struct V_499 * V_500 )
{
struct V_1 * V_2 = F_266 ( V_500 ,
struct V_1 , V_501 . V_500 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_225 ;
if ( V_2 -> V_115 != V_105 ) {
V_225 = F_53 ( V_2 , V_226 ) ;
if ( V_2 -> V_505 ++ > V_224 )
F_181 ( V_2 , 0 ) ;
else if ( V_225 != V_227 )
F_178 ( V_2 , V_509 ,
V_314 ) ;
else
goto V_516;
F_282 ( V_2 , V_508 , L_57 ) ;
return;
}
V_516:
if ( F_118 ( V_18 ) ) {
if ( F_116 ( V_2 , V_18 ) )
goto V_319;
F_76 ( V_18 , V_320 ) ;
}
V_319:
F_34 ( V_18 ) ;
V_2 -> V_489 = 0 ;
F_77 ( V_272 , & V_2 -> V_55 ) ;
if ( ! F_276 ( V_2 ) )
F_178 ( V_2 , V_313 ,
V_314 ) ;
}
static int
F_292 ( struct V_1 * V_2 )
{
T_1 V_55 = 0 , V_517 ;
struct V_17 * V_18 = V_2 -> V_18 ;
if ( F_249 ( V_2 ) )
goto V_518;
if ( V_2 -> V_216 )
F_287 ( V_2 ) ;
V_55 = F_53 ( V_2 , V_235 ) ;
if ( V_55 == V_484 ) {
F_286 ( V_2 ) ;
V_2 -> V_216 = 1 ;
} else if ( V_55 == V_485 )
goto V_518;
V_517 = F_53 ( V_2 , V_519 ) ;
if ( V_517 != V_2 -> V_517 ) {
V_2 -> V_517 = V_517 ;
V_2 -> V_489 = 0 ;
if ( V_2 -> V_216 )
goto V_518;
if ( V_2 -> V_252 && V_520 ) {
F_148 ( V_2 ) ;
V_2 -> V_18 -> V_521 = V_301 ;
}
return 0 ;
}
if ( ++ V_2 -> V_489 < V_522 )
return 0 ;
F_287 ( V_2 ) ;
if ( V_520 )
F_77 ( V_523 , & V_2 -> V_55 ) ;
F_37 ( & V_18 -> V_45 , L_58 ) ;
V_518:
V_2 -> V_502 = ( V_55 == V_485 ) ? V_55 :
V_484 ;
if ( V_520 &&
! F_149 ( V_272 , & V_2 -> V_55 ) ) {
F_178 ( V_2 , F_285 , 0 ) ;
F_282 ( V_2 , V_508 , L_59 ) ;
}
return 1 ;
}
static void
V_313 ( struct V_499 * V_500 )
{
struct V_1 * V_2 = F_266 ( V_500 ,
struct V_1 , V_501 . V_500 ) ;
if ( F_31 ( V_272 , & V_2 -> V_55 ) )
goto V_524;
if ( F_292 ( V_2 ) )
return;
if ( V_2 -> V_254 . V_255 )
F_293 ( V_2 ) ;
V_524:
F_178 ( V_2 , V_313 , V_314 ) ;
}
static int F_294 ( struct V_29 * V_30 )
{
struct V_29 * V_525 ;
int V_482 = V_30 -> V_526 ;
while ( V_482 -- > 0 ) {
V_525 = F_295 ( F_296
( V_30 -> V_527 ) , V_30 -> V_527 -> V_528 ,
F_297 ( F_298 ( V_30 -> V_526 ) , V_482 ) ) ;
if ( ! V_525 )
continue;
if ( V_525 -> V_529 != V_316 ) {
F_299 ( V_525 ) ;
return 0 ;
}
F_299 ( V_525 ) ;
}
return 1 ;
}
static int F_300 ( struct V_29 * V_30 )
{
int V_57 , V_530 ;
struct V_1 * V_2 = F_186 ( V_30 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
V_30 -> V_531 = V_532 ;
V_57 = F_161 ( V_30 ) ;
if ( V_57 )
return V_57 ;
F_198 ( V_30 , V_318 ) ;
F_164 ( V_30 ) ;
F_201 ( V_30 ) ;
V_530 = F_294 ( V_30 ) ;
if ( F_54 ( V_2 ) )
return - V_53 ;
if ( V_2 -> V_115 != V_123 && V_530 ) {
V_2 -> V_216 = 1 ;
F_74 ( V_490 , & V_2 -> V_55 ) ;
F_101 ( V_2 , V_235 , V_497 ) ;
F_282 ( V_2 , V_508 , L_49 ) ;
}
F_57 ( V_2 ) ;
V_57 = V_2 -> V_124 -> V_309 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_276 ( V_2 ) ;
F_42 ( V_2 ) ;
if ( F_118 ( V_18 ) ) {
V_57 = F_134 ( V_2 ) ;
if ( V_57 ) {
F_181 ( V_2 , 1 ) ;
F_77 ( V_514 , & V_2 -> V_55 ) ;
F_34 ( V_18 ) ;
return V_57 ;
}
V_57 = F_116 ( V_2 , V_18 ) ;
if ( V_57 )
goto V_319;
F_76 ( V_18 , V_320 ) ;
}
V_319:
F_34 ( V_18 ) ;
return V_57 ;
}
static T_17 F_301 ( struct V_29 * V_30 ,
T_18 V_55 )
{
struct V_1 * V_2 = F_186 ( V_30 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
if ( V_55 == V_533 )
return V_534 ;
if ( V_55 == V_532 )
return V_535 ;
F_74 ( V_514 , & V_2 -> V_55 ) ;
F_32 ( V_18 ) ;
F_291 ( & V_2 -> V_501 ) ;
if ( F_118 ( V_18 ) )
F_133 ( V_2 , V_18 ) ;
F_140 ( V_2 ) ;
F_44 ( V_2 ) ;
F_77 ( V_272 , & V_2 -> V_55 ) ;
F_193 ( V_30 ) ;
F_184 ( V_30 ) ;
return V_536 ;
}
static T_17 F_302 ( struct V_29 * V_30 )
{
return F_300 ( V_30 ) ? V_534 :
V_535 ;
}
static void F_303 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_186 ( V_30 ) ;
F_304 ( V_30 ) ;
if ( F_53 ( V_2 , V_235 ) == V_236 &&
F_121 ( V_514 , & V_2 -> V_55 ) )
F_178 ( V_2 , V_313 ,
V_314 ) ;
}
static int
F_305 ( struct V_1 * V_2 )
{
int V_57 ;
V_57 = F_94 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_89 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_70 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_68 ( V_2 ) ;
V_57 = F_80 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_2 -> V_216 = 0 ;
return V_57 ;
}
static int
F_306 ( struct V_1 * V_2 , T_1 V_31 )
{
return - V_51 ;
}
static int
F_307 ( struct V_1 * V_2 , T_1 V_55 , T_1 V_537 )
{
return - V_51 ;
}
static T_19
F_308 ( struct V_138 * V_45 ,
struct V_538 * V_539 , const char * V_540 , T_20 V_435 )
{
struct V_1 * V_2 = F_309 ( V_45 ) ;
unsigned long V_541 ;
int V_82 = - V_53 ;
if ( ! ( V_2 -> V_179 & V_542 ) )
goto V_230;
if ( ! F_31 ( V_54 , & V_2 -> V_55 ) )
goto V_230;
if ( F_310 ( V_540 , 2 , & V_541 ) )
goto V_230;
if ( ! V_2 -> V_124 -> V_543 ( V_2 , ! ! V_541 ) )
V_82 = V_435 ;
V_230:
return V_82 ;
}
static T_19
F_311 ( struct V_138 * V_45 ,
struct V_538 * V_539 , char * V_540 )
{
struct V_1 * V_2 = F_309 ( V_45 ) ;
int V_544 = 0 ;
if ( V_2 -> V_179 & V_542 )
V_544 = ! ! ( V_2 -> V_49 & V_545 ) ;
return sprintf ( V_540 , L_60 , V_544 ) ;
}
static T_19
F_312 ( struct V_138 * V_45 ,
struct V_538 * V_539 , const char * V_540 , T_20 V_435 )
{
struct V_1 * V_2 = F_309 ( V_45 ) ;
unsigned long V_541 ;
if ( F_310 ( V_540 , 2 , & V_541 ) )
return - V_53 ;
if ( ! ! V_541 != ! ! ( V_2 -> V_49 & V_546 ) )
V_2 -> V_49 ^= V_546 ;
return V_435 ;
}
static T_19
F_313 ( struct V_138 * V_45 ,
struct V_538 * V_539 , char * V_540 )
{
struct V_1 * V_2 = F_309 ( V_45 ) ;
return sprintf ( V_540 , L_60 ,
! ! ( V_2 -> V_49 & V_546 ) ) ;
}
int F_314 ( struct V_17 * V_18 , T_2 V_547 , T_2 V_482 )
{
if ( ! V_167 && ! V_64 ) {
F_253 ( V_18 , L_61 ) ;
return - V_53 ;
}
if ( ( V_482 > V_547 ) || ( V_482 < 2 ) || ! F_315 ( V_482 ) ) {
F_253 ( V_18 , L_62
L_63 , V_547 ) ;
return - V_53 ;
}
return 0 ;
}
int F_316 ( struct V_1 * V_2 , T_2 V_104 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_57 = 0 ;
if ( F_149 ( V_272 , & V_2 -> V_55 ) )
return - V_273 ;
F_32 ( V_18 ) ;
if ( F_118 ( V_18 ) )
F_120 ( V_2 , V_18 ) ;
F_140 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( F_35 ( V_2 , V_104 ) ) {
F_253 ( V_18 , L_64 ) ;
F_39 ( V_2 ) ;
}
if ( F_118 ( V_18 ) ) {
V_57 = F_134 ( V_2 ) ;
if ( V_57 )
goto V_319;
V_57 = F_108 ( V_2 , V_18 ) ;
if ( V_57 )
goto V_319;
F_76 ( V_18 , V_320 ) ;
}
V_319:
F_34 ( V_18 ) ;
F_77 ( V_272 , & V_2 -> V_55 ) ;
return V_57 ;
}
static int
F_317 ( struct V_1 * V_2 ,
T_21 V_372 , T_20 V_14 )
{
T_20 V_548 = 4 ;
if ( ! ( V_2 -> V_49 & V_546 ) )
return - V_41 ;
if ( V_372 < V_549 ) {
if ( F_318 ( V_372 , V_550 ,
V_551 ) )
V_548 = 8 ;
else
return - V_53 ;
}
if ( ( V_14 != V_548 ) || ( V_372 & ( V_548 - 1 ) ) )
return - V_53 ;
return 0 ;
}
static T_19
F_319 ( struct V_552 * V_553 , struct V_554 * V_555 ,
struct V_556 * V_539 ,
char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
T_1 V_104 ;
T_11 V_557 ;
int V_82 ;
V_82 = F_317 ( V_2 , V_372 , V_14 ) ;
if ( V_82 != 0 )
return V_82 ;
if ( F_318 ( V_372 , V_550 , V_551 ) ) {
F_320 ( V_2 , V_372 , & V_557 ) ;
memcpy ( V_540 , & V_557 , V_14 ) ;
} else {
V_104 = F_53 ( V_2 , V_372 ) ;
memcpy ( V_540 , & V_104 , V_14 ) ;
}
return V_14 ;
}
static T_19
F_321 ( struct V_552 * V_553 , struct V_554 * V_555 ,
struct V_556 * V_539 ,
char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
T_1 V_104 ;
T_11 V_557 ;
int V_82 ;
V_82 = F_317 ( V_2 , V_372 , V_14 ) ;
if ( V_82 != 0 )
return V_82 ;
if ( F_318 ( V_372 , V_550 , V_551 ) ) {
memcpy ( & V_557 , V_540 , V_14 ) ;
F_322 ( V_2 , V_372 , V_557 ) ;
} else {
memcpy ( & V_104 , V_540 , V_14 ) ;
F_101 ( V_2 , V_372 , V_104 ) ;
}
return V_14 ;
}
static int
F_323 ( struct V_1 * V_2 ,
T_21 V_372 , T_20 V_14 )
{
if ( ! ( V_2 -> V_49 & V_546 ) )
return - V_41 ;
if ( ( V_14 != 8 ) || ( V_372 & 0x7 ) )
return - V_41 ;
return 0 ;
}
static T_19
F_324 ( struct V_552 * V_553 , struct V_554 * V_555 ,
struct V_556 * V_539 ,
char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
T_11 V_104 ;
int V_82 ;
V_82 = F_323 ( V_2 , V_372 , V_14 ) ;
if ( V_82 != 0 )
return V_82 ;
if ( F_325 ( V_2 , V_372 , & V_104 ) )
return - V_41 ;
memcpy ( V_540 , & V_104 , V_14 ) ;
return V_14 ;
}
static T_19
F_326 ( struct V_552 * V_553 , struct V_554 * V_555 ,
struct V_556 * V_539 ,
char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
T_11 V_104 ;
int V_82 ;
V_82 = F_323 ( V_2 , V_372 , V_14 ) ;
if ( V_82 != 0 )
return V_82 ;
memcpy ( & V_104 , V_540 , V_14 ) ;
if ( F_327 ( V_2 , V_372 , V_104 ) )
return - V_41 ;
return V_14 ;
}
static int
F_328 ( struct V_1 * V_2 ,
struct V_558 * V_559 , int V_13 )
{
T_2 V_560 , V_561 , V_562 ;
T_2 V_563 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_560 = V_559 [ V_36 ] . V_68 ;
V_563 = V_559 [ V_36 ] . V_222 ;
if ( V_560 >= V_84
|| V_563 >= V_84 )
return V_94 ;
if ( V_2 -> V_85 [ V_560 ] . type != V_111 )
return V_94 ;
if ( V_2 -> V_85 [ V_563 ] . type != V_111 )
return V_94 ;
V_561 = V_2 -> V_85 [ V_560 ] . V_96 ;
V_562 = V_2 -> V_85 [ V_563 ] . V_96 ;
if ( V_561 != V_562 )
return V_94 ;
}
return 0 ;
}
static T_19
F_329 ( struct V_552 * V_553 , struct V_554 * V_555 ,
struct V_556 * V_539 , char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
struct V_558 * V_559 ;
T_1 V_93 , V_564 , V_68 ;
int V_13 , V_565 , V_36 , V_82 ;
V_13 = V_14 / sizeof( struct V_558 ) ;
V_565 = V_14 % sizeof( struct V_558 ) ;
if ( V_565 )
return V_94 ;
V_559 = (struct V_558 * ) V_540 ;
V_82 = F_328 ( V_2 , V_559 , V_13 ) ;
if ( V_82 )
return V_82 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_559 [ V_36 ] . V_68 ;
V_564 = ! ! V_559 [ V_36 ] . V_564 ;
V_93 = V_2 -> V_85 [ V_68 ] . V_96 ;
V_82 = F_88 ( V_2 , V_93 ,
V_564 , V_68 ) ;
if ( V_82 )
return V_82 ;
}
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_559 [ V_36 ] . V_68 ;
V_93 = V_2 -> V_85 [ V_68 ] . V_96 ;
V_2 -> V_85 [ V_68 ] . V_221 = ! ! V_559 [ V_36 ] . V_564 ;
V_2 -> V_85 [ V_68 ] . V_222 = V_93 ;
}
return V_14 ;
}
static T_19
F_330 ( struct V_552 * V_553 , struct V_554 * V_555 ,
struct V_556 * V_539 , char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
struct V_558 V_559 [ V_84 ] ;
int V_36 ;
if ( V_14 != sizeof( V_559 ) )
return V_94 ;
for ( V_36 = 0 ; V_36 < V_84 ; V_36 ++ ) {
if ( V_2 -> V_85 [ V_36 ] . type != V_111 )
continue;
V_559 [ V_36 ] . V_564 = V_2 -> V_85 [ V_36 ] . V_221 ;
V_559 [ V_36 ] . V_222 = 0 ;
V_559 [ V_36 ] . V_68 = V_36 ;
}
memcpy ( V_540 , & V_559 , V_14 ) ;
return V_14 ;
}
static int
F_331 ( struct V_1 * V_2 ,
struct V_183 * V_184 , int V_13 )
{
T_1 V_115 ;
T_2 V_68 ;
int V_36 ;
V_115 = F_56 ( V_2 -> V_67 -> V_79 + V_107 ) ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_184 [ V_36 ] . V_68 ;
if ( V_68 >= V_84 )
return V_94 ;
if ( V_2 -> V_115 == V_105 )
if ( V_2 -> V_85 [ V_68 ] . type != V_111 )
return V_94 ;
switch ( V_184 [ V_36 ] . V_115 ) {
case V_217 :
if ( F_59 ( V_115 , V_68 ) !=
V_123 ) {
if ( V_184 [ V_36 ] . V_194 != 0 )
return V_94 ;
if ( V_184 [ V_36 ] . V_195 != 1 )
return V_94 ;
if ( V_184 [ V_36 ] . V_196 != 1 )
return V_94 ;
}
break;
case V_218 :
if ( ! F_332 ( V_184 [ V_36 ] . V_187 ) )
return V_94 ;
if ( ! V_184 [ V_36 ] . V_566 )
return V_94 ;
break;
case V_567 :
if ( ! V_184 [ V_36 ] . V_566 )
return V_94 ;
break;
default:
return V_94 ;
}
}
return 0 ;
}
static T_19
F_333 ( struct V_552 * V_552 , struct V_554 * V_555 ,
struct V_556 * V_539 , char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
struct V_183 * V_184 ;
struct V_86 * V_215 ;
int V_13 , V_565 , V_36 , V_82 ;
T_2 V_68 , V_115 = 0 ;
V_13 = V_14 / sizeof( struct V_183 ) ;
V_565 = V_14 % sizeof( struct V_183 ) ;
if ( V_565 )
return V_94 ;
V_184 = (struct V_183 * ) V_540 ;
V_82 = F_331 ( V_2 , V_184 , V_13 ) ;
if ( V_82 )
return V_82 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
if ( V_2 -> V_115 == V_105 )
if ( F_84 ( V_2 , & V_184 [ V_36 ] ) )
return V_94 ;
if ( V_2 -> V_67 -> V_68 != V_184 [ V_36 ] . V_68 )
continue;
V_115 = V_184 [ V_36 ] . V_115 ;
F_81 ( V_2 , & V_184 [ V_36 ] ) ;
V_184 [ V_36 ] . V_115 = V_115 ;
V_184 [ V_36 ] . V_68 = V_2 -> V_67 -> V_68 ;
switch ( V_184 [ V_36 ] . V_115 ) {
case V_217 :
F_78 ( V_2 , & V_184 [ V_36 ] ) ;
break;
case V_218 :
F_72 ( V_2 , & V_184 [ V_36 ] ) ;
break;
case V_567 :
V_184 [ V_36 ] . V_187 = 0 ;
F_72 ( V_2 , & V_184 [ V_36 ] ) ;
break;
}
}
if ( V_2 -> V_115 != V_105 )
goto V_260;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_184 [ V_36 ] . V_68 ;
V_215 = & V_2 -> V_85 [ V_68 ] ;
switch ( V_184 [ V_36 ] . V_115 ) {
case V_217 :
V_215 -> V_196 = V_184 [ V_36 ] . V_196 ;
V_215 -> V_195 = V_184 [ V_36 ] . V_195 ;
V_215 -> V_209 = V_184 [ V_36 ] . V_209 ;
V_215 -> V_194 = V_184 [ V_36 ] . V_194 ;
V_215 -> V_185 = V_184 [ V_36 ] . V_185 ;
break;
case V_218 :
V_215 -> V_188 = V_184 [ V_36 ] . V_187 ;
break;
case V_567 :
V_215 -> V_188 = 0 ;
break;
}
}
V_260:
return V_14 ;
}
static T_19
F_334 ( struct V_552 * V_552 , struct V_554 * V_555 ,
struct V_556 * V_539 , char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
struct V_183 V_184 [ V_84 ] ;
T_2 V_36 ;
if ( V_14 != sizeof( V_184 ) )
return V_94 ;
for ( V_36 = 0 ; V_36 < V_84 ; V_36 ++ ) {
if ( V_2 -> V_85 [ V_36 ] . type != V_111 )
continue;
V_184 [ V_36 ] . V_68 = V_36 ;
if ( F_81 ( V_2 , & V_184 [ V_36 ] ) )
return V_94 ;
}
memcpy ( V_540 , & V_184 , V_14 ) ;
return V_14 ;
}
static int
F_335 ( struct V_1 * V_2 ,
struct V_568 * V_569 , int V_13 )
{
T_2 V_68 , V_36 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_569 [ V_36 ] . V_68 ;
if ( V_68 >= V_84 )
return V_94 ;
if ( V_2 -> V_85 [ V_68 ] . type != V_111 )
return V_94 ;
if ( ! F_336 ( V_569 [ V_36 ] . V_98 ) ||
! F_336 ( V_569 [ V_36 ] . V_100 ) )
return V_94 ;
}
return 0 ;
}
static T_19
F_337 ( struct V_552 * V_552 , struct V_554 * V_555 ,
struct V_556 * V_539 , char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
struct V_172 V_173 ;
struct V_568 * V_569 ;
int V_36 , V_13 , V_565 , V_82 ;
T_2 V_68 ;
V_13 = V_14 / sizeof( struct V_568 ) ;
V_565 = V_14 % sizeof( struct V_568 ) ;
if ( V_565 )
return V_94 ;
V_569 = (struct V_568 * ) V_540 ;
V_82 = F_335 ( V_2 , V_569 , V_13 ) ;
if ( V_82 )
return V_82 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_569 [ V_36 ] . V_68 ;
V_82 = F_71 ( V_2 , & V_173 , V_68 ) ;
if ( V_82 )
return V_82 ;
V_173 . V_68 = V_68 ;
V_173 . V_219 = V_569 [ V_36 ] . V_98 ;
V_173 . V_220 = V_569 [ V_36 ] . V_100 ;
V_82 = F_87 ( V_2 , & V_173 ) ;
if ( V_82 )
return V_82 ;
V_2 -> V_85 [ V_36 ] . V_98 = V_173 . V_219 ;
V_2 -> V_85 [ V_36 ] . V_100 = V_173 . V_220 ;
}
return V_14 ;
}
static T_19
F_338 ( struct V_552 * V_552 , struct V_554 * V_555 ,
struct V_556 * V_539 , char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
struct V_172 V_173 ;
struct V_568 V_569 [ V_84 ] ;
int V_36 , V_82 ;
if ( V_14 != sizeof( V_569 ) )
return V_94 ;
for ( V_36 = 0 ; V_36 < V_84 ; V_36 ++ ) {
if ( V_2 -> V_85 [ V_36 ] . type != V_111 )
continue;
V_82 = F_71 ( V_2 , & V_173 , V_36 ) ;
if ( V_82 )
return V_82 ;
V_569 [ V_36 ] . V_68 = V_36 ;
V_569 [ V_36 ] . V_115 = ( T_2 ) V_173 . V_115 ;
V_569 [ V_36 ] . V_570 = V_173 . V_175 ;
V_569 [ V_36 ] . V_571 = V_173 . V_179 ;
V_569 [ V_36 ] . V_98 = V_173 . V_219 ;
V_569 [ V_36 ] . V_100 = V_173 . V_220 ;
V_569 [ V_36 ] . V_572 = V_173 . V_177 ;
V_569 [ V_36 ] . V_573 = V_173 . V_178 ;
}
memcpy ( V_540 , & V_569 , V_14 ) ;
return V_14 ;
}
static T_19
F_339 ( struct V_552 * V_552 , struct V_554 * V_555 ,
struct V_556 * V_539 , char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
struct V_574 V_575 ;
int V_82 ;
if ( V_14 != sizeof( struct V_574 ) )
return V_94 ;
if ( V_372 >= V_84 )
return V_94 ;
memset ( & V_575 , 0 , V_14 ) ;
V_82 = F_340 ( V_2 , V_372 , V_576 ,
& V_575 . V_577 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_340 ( V_2 , V_372 , V_578 ,
& V_575 . V_579 ) ;
if ( V_82 )
return V_82 ;
memcpy ( V_540 , & V_575 , V_14 ) ;
return V_14 ;
}
static T_19
F_341 ( struct V_552 * V_552 , struct V_554 * V_555 ,
struct V_556 * V_539 , char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
struct V_574 V_580 ;
int V_82 ;
if ( V_14 != sizeof( struct V_574 ) )
return V_94 ;
if ( V_372 >= V_90 )
return V_94 ;
memset ( & V_580 , 0 , V_14 ) ;
V_82 = F_342 ( V_2 , V_372 , V_576 ,
& V_580 . V_577 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_342 ( V_2 , V_372 , V_578 ,
& V_580 . V_579 ) ;
if ( V_82 )
return V_82 ;
memcpy ( V_540 , & V_580 , V_14 ) ;
return V_14 ;
}
static T_19
F_343 ( struct V_552 * V_552 , struct V_554 * V_555 ,
struct V_556 * V_539 , char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
int V_82 ;
if ( V_372 >= V_90 )
return V_94 ;
V_82 = F_344 ( V_2 , V_581 , V_372 ,
V_576 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_344 ( V_2 , V_581 , V_372 ,
V_578 ) ;
if ( V_82 )
return V_82 ;
return V_14 ;
}
static T_19
F_345 ( struct V_552 * V_552 , struct V_554 * V_555 ,
struct V_556 * V_539 , char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
int V_82 ;
if ( V_372 >= V_84 )
return V_94 ;
V_82 = F_344 ( V_2 , V_582 , V_372 ,
V_576 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_344 ( V_2 , V_582 , V_372 ,
V_578 ) ;
if ( V_82 )
return V_82 ;
return V_14 ;
}
static T_19
F_346 ( struct V_552 * V_552 , struct V_554 * V_555 ,
struct V_556 * V_539 , char * V_540 , T_21 V_372 , T_20 V_14 )
{
struct V_138 * V_45 = F_266 ( V_555 , struct V_138 , V_555 ) ;
struct V_1 * V_2 = F_309 ( V_45 ) ;
struct V_583 V_584 [ V_84 ] ;
struct V_80 * V_81 ;
int V_36 , V_82 ;
if ( V_14 != sizeof( V_584 ) )
return V_94 ;
V_81 = F_50 ( V_84 , sizeof( * V_81 ) , V_16 ) ;
if ( ! V_81 )
return - V_21 ;
V_82 = F_51 ( V_2 , V_81 ) ;
if ( V_82 ) {
F_9 ( V_81 ) ;
return V_82 ;
}
for ( V_36 = 0 ; V_36 < V_84 ; V_36 ++ ) {
V_584 [ V_36 ] . V_68 = V_81 [ V_36 ] . V_93 ;
V_584 [ V_36 ] . V_585 = V_81 [ V_36 ] . type ;
V_584 [ V_36 ] . V_570 = V_81 [ V_36 ] . V_97 ;
V_584 [ V_36 ] . V_98 = V_81 [ V_36 ] . V_99 ;
V_584 [ V_36 ] . V_100 = V_81 [ V_36 ] . V_101 ;
memcpy ( & V_584 [ V_36 ] . V_586 , & V_81 [ V_36 ] . V_587 , V_40 ) ;
}
memcpy ( V_540 , & V_584 , V_14 ) ;
F_9 ( V_81 ) ;
return V_14 ;
}
static void
F_137 ( struct V_1 * V_2 )
{
struct V_138 * V_45 = & V_2 -> V_30 -> V_45 ;
if ( V_2 -> V_179 & V_542 )
if ( F_347 ( V_45 , & V_588 ) )
F_28 ( V_45 ,
L_65 ) ;
}
static void
F_141 ( struct V_1 * V_2 )
{
struct V_138 * V_45 = & V_2 -> V_30 -> V_45 ;
if ( V_2 -> V_179 & V_542 )
F_348 ( V_45 , & V_588 ) ;
}
static void
F_180 ( struct V_1 * V_2 )
{
struct V_138 * V_45 = & V_2 -> V_30 -> V_45 ;
if ( F_349 ( V_45 , & V_589 ) )
F_37 ( V_45 , L_66 ) ;
if ( V_2 -> V_115 == V_123 )
return;
if ( F_347 ( V_45 , & V_590 ) )
F_37 ( V_45 , L_67 ) ;
if ( F_349 ( V_45 , & V_591 ) )
F_37 ( V_45 , L_68 ) ;
if ( F_349 ( V_45 , & V_592 ) )
F_37 ( V_45 , L_69 ) ;
if ( F_349 ( V_45 , & V_593 ) )
F_37 ( V_45 , L_70 ) ;
if ( ! ( V_2 -> V_49 & V_153 ) )
return;
if ( F_349 ( V_45 , & V_594 ) )
F_37 ( V_45 , L_71 ) ;
if ( V_2 -> V_115 != V_105 )
return;
if ( F_349 ( V_45 , & V_595 ) )
F_37 ( V_45 , L_72 ) ;
if ( F_349 ( V_45 , & V_596 ) )
F_37 ( V_45 , L_73 ) ;
if ( F_349 ( V_45 , & V_597 ) )
F_37 ( V_45 , L_74 ) ;
}
static void
F_190 ( struct V_1 * V_2 )
{
struct V_138 * V_45 = & V_2 -> V_30 -> V_45 ;
F_350 ( V_45 , & V_589 ) ;
if ( V_2 -> V_115 == V_123 )
return;
F_348 ( V_45 , & V_590 ) ;
F_350 ( V_45 , & V_591 ) ;
F_350 ( V_45 , & V_592 ) ;
F_350 ( V_45 , & V_593 ) ;
if ( ! ( V_2 -> V_49 & V_153 ) )
return;
F_350 ( V_45 , & V_594 ) ;
if ( V_2 -> V_115 != V_105 )
return;
F_350 ( V_45 , & V_595 ) ;
F_350 ( V_45 , & V_596 ) ;
F_350 ( V_45 , & V_597 ) ;
}
static void
F_351 ( struct V_1 * V_2 ,
struct V_17 * V_45 , unsigned long V_598 )
{
struct V_599 * V_600 ;
V_600 = F_352 ( V_45 ) ;
if ( ! V_600 )
return;
F_353 (indev) {
switch ( V_598 ) {
case V_320 :
F_354 ( V_2 ,
V_601 -> V_602 , V_603 ) ;
break;
case V_191 :
F_354 ( V_2 ,
V_601 -> V_602 , V_604 ) ;
break;
default:
break;
}
} F_355 ( V_600 ) ;
F_356 ( V_600 ) ;
}
static void
F_76 ( struct V_17 * V_18 , unsigned long V_598 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_17 * V_45 ;
T_5 V_189 ;
F_351 ( V_2 , V_18 , V_598 ) ;
F_357 (vid, adapter->vlans, VLAN_N_VID) {
V_45 = F_358 ( V_18 , V_189 ) ;
if ( ! V_45 )
continue;
F_351 ( V_2 , V_45 , V_598 ) ;
}
}
static int F_359 ( struct V_605 * V_606 ,
unsigned long V_598 , void * V_607 )
{
struct V_1 * V_2 ;
struct V_17 * V_45 = (struct V_17 * ) V_607 ;
V_608:
if ( V_45 == NULL )
goto V_319;
if ( V_45 -> V_609 & V_610 ) {
V_45 = F_360 ( V_45 ) ;
goto V_608;
}
if ( ! F_361 ( V_45 ) )
goto V_319;
V_2 = F_30 ( V_45 ) ;
if ( ! V_2 )
goto V_319;
if ( ! F_31 ( V_54 , & V_2 -> V_55 ) )
goto V_319;
F_351 ( V_2 , V_45 , V_598 ) ;
V_319:
return V_611 ;
}
static int
F_362 ( struct V_605 * V_606 ,
unsigned long V_598 , void * V_607 )
{
struct V_1 * V_2 ;
struct V_17 * V_45 ;
struct V_612 * V_601 = (struct V_612 * ) V_607 ;
V_45 = V_601 -> V_613 ? V_601 -> V_613 -> V_45 : NULL ;
V_608:
if ( V_45 == NULL )
goto V_319;
if ( V_45 -> V_609 & V_610 ) {
V_45 = F_360 ( V_45 ) ;
goto V_608;
}
if ( ! F_361 ( V_45 ) )
goto V_319;
V_2 = F_30 ( V_45 ) ;
if ( ! V_2 )
goto V_319;
if ( ! F_31 ( V_54 , & V_2 -> V_55 ) )
goto V_319;
switch ( V_598 ) {
case V_320 :
F_354 ( V_2 , V_601 -> V_602 , V_603 ) ;
break;
case V_191 :
F_354 ( V_2 , V_601 -> V_602 , V_604 ) ;
break;
default:
break;
}
V_319:
return V_611 ;
}
static void
F_76 ( struct V_17 * V_45 , unsigned long V_598 )
{ }
static int T_22 F_363 ( void )
{
int V_82 ;
F_364 ( V_614 L_75 , V_615 ) ;
V_515 = F_365 ( L_76 ) ;
if ( V_515 == NULL ) {
F_364 ( V_616 L_77 ) ;
return - V_21 ;
}
#ifdef F_366
F_367 ( & V_617 ) ;
F_368 ( & V_618 ) ;
#endif
V_82 = F_369 ( & V_619 ) ;
if ( V_82 ) {
#ifdef F_366
F_370 ( & V_618 ) ;
F_371 ( & V_617 ) ;
#endif
F_372 ( V_515 ) ;
}
return V_82 ;
}
static void T_23 F_373 ( void )
{
F_374 ( & V_619 ) ;
#ifdef F_366
F_370 ( & V_618 ) ;
F_371 ( & V_617 ) ;
#endif
F_372 ( V_515 ) ;
}
