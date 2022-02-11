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
V_56 = F_38 ( F_43 ( int , F_44 () ,
V_77 ) ) ;
} else
V_56 = 1 ;
if ( ! F_35 ( V_2 , V_56 ) )
return;
F_39 ( V_2 ) ;
}
static void
F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 & V_59 )
F_46 ( V_2 -> V_30 ) ;
if ( V_2 -> V_49 & V_58 )
F_47 ( V_2 -> V_30 ) ;
}
static void
F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_67 -> V_78 != NULL )
F_49 ( V_2 -> V_67 -> V_78 ) ;
}
static int
F_50 ( struct V_1 * V_2 )
{
struct V_79 * V_80 ;
int V_36 , V_81 = 0 ;
T_2 V_82 ;
V_80 = F_51 ( V_83 , sizeof( * V_80 ) , V_16 ) ;
if ( ! V_80 )
return - V_21 ;
V_2 -> V_84 = F_7 ( sizeof( struct V_85 ) *
V_83 , V_16 ) ;
if ( ! V_2 -> V_84 ) {
V_81 = - V_21 ;
goto V_86;
}
V_2 -> V_87 = F_7 ( sizeof( struct V_88 ) *
V_89 , V_16 ) ;
if ( ! V_2 -> V_87 ) {
V_81 = - V_21 ;
goto V_90;
}
V_81 = F_52 ( V_2 , V_80 ) ;
if ( V_81 )
goto V_91;
for ( V_36 = 0 ; V_36 < V_83 ; V_36 ++ ) {
V_82 = V_80 [ V_36 ] . V_92 ;
if ( V_82 > V_83 ) {
V_81 = V_93 ;
goto V_91;
}
V_2 -> V_84 [ V_82 ] . V_94 = ( T_2 ) V_80 [ V_36 ] . V_94 ;
V_2 -> V_84 [ V_82 ] . type = ( T_2 ) V_80 [ V_36 ] . type ;
V_2 -> V_84 [ V_82 ] . V_95 = ( T_2 ) V_80 [ V_36 ] . V_96 ;
V_2 -> V_84 [ V_82 ] . V_97 = V_80 [ V_36 ] . V_98 ;
V_2 -> V_84 [ V_82 ] . V_99 = V_80 [ V_36 ] . V_100 ;
}
for ( V_36 = 0 ; V_36 < V_89 ; V_36 ++ )
V_2 -> V_87 [ V_36 ] . V_49 |= V_101 ;
F_9 ( V_80 ) ;
return 0 ;
V_91:
F_9 ( V_2 -> V_87 ) ;
V_2 -> V_87 = NULL ;
V_90:
F_9 ( V_2 -> V_84 ) ;
V_2 -> V_84 = NULL ;
V_86:
F_9 ( V_80 ) ;
return V_81 ;
}
static int
F_53 ( struct V_1 * V_2 )
{
T_2 V_92 ;
T_1 V_102 ;
int V_36 , V_81 = 1 ;
T_1 V_103 = V_104 ;
void T_3 * V_105 = V_2 -> V_67 -> V_78 + V_106 ;
V_102 = F_54 ( V_2 , V_107 ) ;
V_81 = F_55 ( V_2 ) ;
if ( V_81 )
goto V_108;
if ( V_109 ) {
for ( V_36 = 0 ; V_36 < V_83 ; V_36 ++ ) {
V_92 = V_36 ;
if ( V_2 -> V_84 [ V_36 ] . type != V_110 ||
V_92 == V_2 -> V_67 -> V_68 )
continue;
V_103 |= ( V_109 &
F_56 ( 0xf , V_92 ) ) ;
}
} else {
V_103 = F_57 ( V_105 ) ;
V_103 = ( V_103 & ~ F_56 ( 0xf , V_2 -> V_67 -> V_68 ) ) |
( F_56 ( V_104 ,
V_2 -> V_67 -> V_68 ) ) ;
}
F_2 ( V_103 , V_105 ) ;
F_58 ( V_2 ) ;
V_108:
return V_81 ;
}
static void
F_59 ( struct V_1 * V_2 )
{
void T_3 * V_111 ;
void T_3 * V_105 ;
T_1 V_112 ;
T_1 V_113 ;
T_1 V_114 , V_115 ;
V_2 -> V_116 = F_57 ( V_2 -> V_67 -> V_78 +
V_117 ) ;
F_22 ( V_2 -> V_30 , V_118 , & V_112 ) ;
V_111 = V_2 -> V_67 -> V_78 + V_119 ;
V_113 = F_57 ( V_111 ) ;
V_112 = ( V_112 - V_113 ) / V_120 ;
V_2 -> V_67 -> V_68 = V_112 ;
V_105 = V_2 -> V_67 -> V_78 + V_106 ;
V_114 = F_57 ( V_105 ) ;
if ( V_114 == V_121 )
V_115 = V_104 ;
else
V_115 = F_60 ( V_114 , V_2 -> V_67 -> V_68 ) ;
if ( V_115 == V_122 ) {
V_2 -> V_114 = V_122 ;
F_37 ( & V_2 -> V_30 -> V_45 ,
L_5 ,
V_2 -> V_116 ) ;
V_2 -> V_123 = & V_124 ;
} else
V_2 -> V_123 = & V_125 ;
}
static int
F_61 ( struct V_1 * V_2 )
{
void T_3 * V_126 = NULL ;
T_4 V_127 ;
unsigned long V_128 , V_129 = 0 ;
struct V_29 * V_30 = V_2 -> V_30 ;
V_127 = F_62 ( V_30 , 0 ) ;
V_128 = F_63 ( V_30 , 0 ) ;
if ( V_128 == V_130 ) {
V_126 = F_64 ( V_30 , 0 ) ;
if ( V_126 == NULL ) {
F_65 ( & V_30 -> V_45 , L_6 ) ;
return - V_41 ;
}
V_129 = V_128 ;
} else {
return - V_41 ;
}
F_37 ( & V_30 -> V_45 , L_7 , ( int ) ( V_128 >> 20 ) ) ;
V_2 -> V_67 -> V_78 = V_126 ;
V_2 -> V_67 -> V_129 = V_129 ;
F_59 ( V_2 ) ;
V_2 -> V_67 -> V_131 = F_41 ( V_2 ,
F_66 ( F_67 (
V_2 -> V_67 -> V_68 ) ) ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , char * V_132 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
int V_36 , V_133 = 0 ;
for ( V_36 = 0 ; V_36 < V_134 ; ++ V_36 ) {
if ( V_135 [ V_36 ] . V_136 == V_30 -> V_136 &&
V_135 [ V_36 ] . V_137 == V_30 -> V_137 &&
V_135 [ V_36 ] . V_138 == V_30 -> V_139 &&
V_135 [ V_36 ] . V_140 == V_30 -> V_141 ) {
sprintf ( V_132 , L_8 ,
V_2 -> V_39 ,
V_135 [ V_36 ] . V_142 ) ;
V_133 = 1 ;
break;
}
}
if ( ! V_133 )
sprintf ( V_132 , L_9 , V_2 -> V_39 ) ;
}
static void
F_69 ( struct V_1 * V_2 )
{
T_1 V_143 , V_144 , V_145 ;
struct V_29 * V_30 = V_2 -> V_30 ;
V_143 = F_54 ( V_2 , V_146 ) ;
V_144 = F_54 ( V_2 , V_147 ) ;
V_145 = F_54 ( V_2 , V_148 ) ;
V_2 -> V_149 = F_70 ( V_143 , V_144 , V_145 ) ;
F_37 ( & V_30 -> V_45 , L_10 ,
V_143 , V_144 , V_145 ) ;
if ( V_2 -> V_67 -> V_150 == V_151 ) {
if ( V_2 -> V_49 & V_152 ) {
V_2 -> V_153 = V_154 ;
V_2 -> V_155 = V_156 ;
} else {
V_2 -> V_153 = V_157 ;
V_2 -> V_155 = V_158 ;
}
V_2 -> V_159 = V_160 ;
V_2 -> V_161 = V_160 ;
} else if ( V_2 -> V_67 -> V_150 == V_162 ) {
V_2 -> V_153 = V_163 ;
V_2 -> V_159 = V_164 ;
V_2 -> V_161 = V_164 ;
V_2 -> V_155 = V_165 ;
}
V_2 -> V_60 = ! ! V_166 ;
V_2 -> V_167 = V_168 ;
V_2 -> V_169 = V_170 ;
}
static int
F_71 ( struct V_1 * V_2 )
{
int V_57 ;
struct V_171 V_172 ;
V_57 = F_72 ( V_2 , & V_172 , V_2 -> V_67 -> V_68 ) ;
if ( V_57 )
return V_57 ;
V_2 -> V_173 = ( T_2 ) V_172 . V_174 ;
V_2 -> V_175 = V_172 . V_175 ;
V_2 -> V_176 = V_172 . V_176 ;
V_2 -> V_177 = V_172 . V_177 ;
V_2 -> V_178 = V_172 . V_178 ;
V_2 -> V_179 = V_172 . V_179 ;
V_2 -> V_180 = V_172 . V_180 ;
if ( V_2 -> V_178 & V_181 )
V_2 -> V_49 |= V_152 ;
else
V_2 -> V_49 &= ~ V_152 ;
return V_57 ;
}
static void
F_73 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
if ( V_183 -> V_184 )
V_2 -> V_49 &= ~ V_185 ;
else
V_2 -> V_49 |= V_185 ;
if ( V_183 -> V_186 )
V_2 -> V_187 = V_183 -> V_186 ;
else
V_2 -> V_187 = 0 ;
}
static void
F_74 ( struct V_17 * V_18 , T_5 V_188 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
F_75 ( V_188 , V_2 -> V_189 ) ;
}
static void
F_76 ( struct V_17 * V_18 , T_5 V_188 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
F_77 ( V_18 , V_190 ) ;
F_78 ( V_188 , V_2 -> V_189 ) ;
}
static void
F_79 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
V_2 -> V_49 &= ~ ( V_191 | V_50 |
V_192 ) ;
if ( V_183 -> V_193 )
V_2 -> V_49 |= V_191 ;
if ( ! V_183 -> V_194 )
V_2 -> V_49 |= V_50 ;
if ( ! V_183 -> V_195 )
V_2 -> V_49 |= V_192 ;
F_80 ( V_2 , V_183 ) ;
}
static int
F_81 ( struct V_1 * V_2 )
{
struct V_182 V_183 ;
if ( ! ( V_2 -> V_49 & V_152 ) )
return 0 ;
V_183 . V_68 = V_2 -> V_67 -> V_68 ;
if ( F_82 ( V_2 , & V_183 ) )
return - V_41 ;
F_73 ( V_2 , & V_183 ) ;
F_79 ( V_2 , & V_183 ) ;
return 0 ;
}
static void
F_80 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
unsigned long V_196 , V_197 ;
V_196 = ( V_198 | V_199 | V_200 |
V_201 | V_202 ) ;
V_197 = ( V_198 | V_199 |
V_201 | V_203 ) ;
if ( V_2 -> V_178 & V_204 ) {
V_196 |= ( V_205 | V_206 ) ;
V_197 |= ( V_205 | V_206 ) ;
}
if ( V_18 -> V_196 & V_207 )
V_196 |= V_207 ;
if ( V_183 -> V_208 & V_209 ) {
V_18 -> V_196 |= V_196 ;
if ( ! ( V_183 -> V_208 & V_210 ) )
V_18 -> V_196 &= ~ V_205 ;
if ( ! ( V_183 -> V_208 & V_211 ) )
V_18 -> V_196 &= ~ V_206 ;
} else {
V_18 -> V_196 &= ~ V_196 ;
}
V_18 -> V_197 = ( V_196 & V_197 ) ;
}
static int
F_83 ( struct V_1 * V_2 )
{
void T_3 * V_105 ;
T_1 V_114 , V_115 ;
int V_57 = 0 ;
V_57 = F_71 ( V_2 ) ;
if ( V_57 )
return V_57 ;
if ( V_2 -> V_49 & V_212 )
return 0 ;
V_105 = V_2 -> V_67 -> V_78 + V_106 ;
V_114 = F_57 ( V_105 ) ;
V_115 = F_60 ( V_114 , V_2 -> V_67 -> V_68 ) ;
if ( V_114 == V_121 )
V_115 = V_104 ;
else
V_115 = F_60 ( V_114 , V_2 -> V_67 -> V_68 ) ;
if ( V_2 -> V_49 & V_152 ) {
if ( V_115 == V_104 ) {
V_2 -> V_114 = V_104 ;
V_57 = F_50 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_53 ( V_2 ) ;
F_37 ( & V_2 -> V_30 -> V_45 ,
L_11 ,
V_2 -> V_116 ) ;
} else if ( V_115 == V_213 ) {
V_2 -> V_114 = V_213 ;
F_37 ( & V_2 -> V_30 -> V_45 ,
L_12 ,
V_2 -> V_116 ) ;
}
}
V_2 -> V_49 |= V_212 ;
return V_57 ;
}
static int
F_84 ( struct V_1 * V_2 )
{
struct V_182 V_183 ;
struct V_85 * V_214 ;
T_2 V_36 ;
if ( V_2 -> V_215 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_83 ; V_36 ++ ) {
if ( V_2 -> V_84 [ V_36 ] . type != V_110 )
continue;
memset ( & V_183 , 0 , sizeof( struct V_182 ) ) ;
V_183 . V_68 = V_36 ;
V_183 . V_208 = V_209 ;
V_183 . V_194 = V_209 ;
V_183 . V_195 = V_209 ;
if ( V_2 -> V_178 & V_204 )
V_183 . V_208 |= ( V_210 | V_211 ) ;
if ( F_85 ( V_2 , & V_183 ) )
return - V_41 ;
V_214 = & V_2 -> V_84 [ V_36 ] ;
V_214 -> V_187 = V_183 . V_186 ;
V_214 -> V_194 = V_183 . V_194 ;
V_214 -> V_193 = V_183 . V_193 ;
V_214 -> V_184 = V_183 . V_184 ;
V_214 -> V_195 = V_183 . V_195 ;
V_214 -> V_208 = V_183 . V_208 ;
}
return 0 ;
}
static int
F_86 ( struct V_1 * V_2 ,
struct V_85 * V_214 , int V_68 )
{
struct V_182 V_183 ;
V_183 . V_114 = V_216 ;
V_183 . V_68 = V_68 ;
V_183 . V_186 = V_214 -> V_187 ;
V_183 . V_194 = V_214 -> V_194 ;
V_183 . V_184 = V_214 -> V_184 ;
V_183 . V_193 = V_214 -> V_193 ;
V_183 . V_208 = V_214 -> V_208 ;
V_183 . V_195 = V_214 -> V_195 ;
if ( F_85 ( V_2 , & V_183 ) )
return - V_41 ;
V_183 . V_114 = V_217 ;
if ( F_85 ( V_2 , & V_183 ) )
return - V_41 ;
return 0 ;
}
static int
F_87 ( struct V_1 * V_2 )
{
int V_36 , V_57 ;
struct V_85 * V_214 ;
struct V_171 V_172 ;
if ( ! V_2 -> V_215 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_83 ; V_36 ++ ) {
V_214 = & V_2 -> V_84 [ V_36 ] ;
if ( V_214 -> type != V_110 )
continue;
V_57 = F_72 ( V_2 , & V_172 , V_36 ) ;
if ( V_57 )
return V_57 ;
V_172 . V_218 = V_214 -> V_97 ;
V_172 . V_219 = V_214 -> V_99 ;
V_57 = F_88 ( V_2 , & V_172 ) ;
if ( V_57 )
return V_57 ;
if ( V_214 -> V_220 ) {
V_57 = F_89 ( V_2 ,
V_214 -> V_221 , 1 , V_36 ) ;
if ( V_57 )
return V_57 ;
}
V_57 = F_86 ( V_2 , V_214 , V_36 ) ;
if ( V_57 )
return V_57 ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
T_2 V_222 = V_223 ;
T_1 V_224 ;
if ( V_2 -> V_114 == V_104 )
return 0 ;
V_224 = F_54 ( V_2 , V_225 ) ;
while ( V_224 != V_226 && -- V_222 ) {
F_91 ( 1000 ) ;
V_224 = F_54 ( V_2 , V_225 ) ;
}
if ( ! V_222 ) {
F_65 ( & V_2 -> V_30 -> V_45 ,
L_13 ) ;
return - V_41 ;
}
return 0 ;
}
static int
F_92 ( struct V_1 * V_2 )
{
int V_57 ;
if ( ! ( V_2 -> V_49 & V_152 ) ||
V_2 -> V_114 != V_104 )
return 0 ;
V_57 = F_84 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_87 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_93 ( V_2 ) ;
return V_57 ;
}
static int
F_94 ( struct V_1 * V_2 )
{
int V_57 ;
V_57 = F_95 ( V_2 ) ;
if ( V_57 < 0 )
return V_57 ;
else if ( ! V_57 )
goto V_227;
if ( V_228 )
F_96 ( V_2 ) ;
else {
V_57 = F_97 ( V_2 ) ;
if ( V_57 )
goto V_229;
V_2 -> V_230 = V_231 ;
}
V_57 = F_98 ( V_2 ) ;
if ( V_57 == 0 )
goto V_227;
V_57 = F_99 ( V_2 ) ;
if ( V_57 )
goto V_229;
V_57 = F_100 ( V_2 ) ;
if ( V_57 )
goto V_229;
F_101 ( V_2 ) ;
F_102 ( V_2 , V_232 , V_233 ) ;
V_227:
V_57 = F_103 ( V_2 ) ;
if ( V_57 )
goto V_229;
F_102 ( V_2 , V_234 , V_235 ) ;
F_104 ( V_2 , 1 ) ;
V_57 = F_83 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_2 -> V_30 -> V_45 ,
L_14 ) ;
goto V_229;
}
V_57 = F_92 ( V_2 ) ;
if ( V_57 )
goto V_229;
F_69 ( V_2 ) ;
V_2 -> V_215 = 0 ;
F_101 ( V_2 ) ;
return 0 ;
V_229:
F_102 ( V_2 , V_234 , V_236 ) ;
F_65 ( & V_2 -> V_30 -> V_45 , L_15 ) ;
F_101 ( V_2 ) ;
return V_57 ;
}
static int
F_105 ( struct V_1 * V_2 )
{
T_6 V_237 ;
struct V_7 * V_8 ;
int V_57 , V_19 ;
unsigned long V_49 = 0 ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_11 * V_12 = V_2 -> V_12 ;
if ( V_2 -> V_238 == V_239 ) {
V_237 = V_240 ;
if ( ! F_5 ( V_2 ) )
V_49 |= V_241 ;
} else {
if ( V_2 -> V_49 & V_59 )
V_237 = V_242 ;
else if ( V_2 -> V_49 & V_58 )
V_237 = V_243 ;
else {
V_49 |= V_241 ;
V_237 = V_244 ;
}
}
V_2 -> V_70 = V_18 -> V_70 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_12 -> V_15 [ V_19 ] ;
sprintf ( V_8 -> V_132 , L_16 , V_18 -> V_132 , V_19 ) ;
V_57 = F_106 ( V_8 -> V_70 , V_237 ,
V_49 , V_8 -> V_132 , V_8 ) ;
if ( V_57 )
return V_57 ;
}
return 0 ;
}
static void
F_107 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_7 * V_8 ;
struct V_11 * V_12 = V_2 -> V_12 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_12 -> V_15 [ V_19 ] ;
F_108 ( V_8 -> V_70 , V_8 ) ;
}
}
static int
F_109 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_19 ;
struct V_245 * V_246 ;
if ( V_2 -> V_26 != V_27 )
return - V_41 ;
if ( F_31 ( V_54 , & V_2 -> V_55 ) )
return 0 ;
if ( F_81 ( V_2 ) )
return - V_41 ;
if ( F_110 ( V_2 ) )
return - V_41 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_169 ; V_19 ++ ) {
V_246 = & V_2 -> V_12 -> V_247 [ V_19 ] ;
F_111 ( V_2 , V_246 ) ;
}
F_33 ( V_18 ) ;
F_112 ( V_2 , V_18 -> V_248 ) ;
V_2 -> V_67 -> V_249 = 0 ;
if ( V_2 -> V_20 > 1 )
F_113 ( V_2 , 1 ) ;
F_114 ( V_2 ) ;
if ( V_18 -> V_196 & V_207 )
F_115 ( V_2 , V_250 ) ;
F_14 ( V_2 ) ;
F_116 ( V_2 , 1 ) ;
V_2 -> V_251 = 0 ;
F_75 ( V_54 , & V_2 -> V_55 ) ;
return 0 ;
}
static int
F_117 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_57 = 0 ;
F_118 () ;
if ( F_119 ( V_18 ) )
V_57 = F_109 ( V_2 , V_18 ) ;
F_120 () ;
return V_57 ;
}
static void
F_121 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
if ( V_2 -> V_26 != V_27 )
return;
if ( ! F_122 ( V_54 , & V_2 -> V_55 ) )
return;
F_123 () ;
F_124 ( & V_2 -> V_252 ) ;
F_125 ( V_18 ) ;
F_126 ( V_18 ) ;
F_127 ( V_2 ) ;
if ( V_2 -> V_253 . V_254 )
F_128 ( V_2 ) ;
F_129 ( V_2 , V_255 ) ;
F_16 ( V_2 ) ;
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
F_133 ( & V_2 -> V_252 ) ;
}
static void
F_134 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
F_118 () ;
if ( F_119 ( V_18 ) )
F_121 ( V_2 , V_18 ) ;
F_120 () ;
}
static int
F_135 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_29 * V_30 = V_2 -> V_30 ;
int V_57 ;
if ( V_2 -> V_26 == V_27 )
return 0 ;
V_57 = F_10 ( V_2 , V_18 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_136 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_17 ) ;
goto V_256;
}
V_57 = F_137 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_18 ) ;
goto V_257;
}
V_57 = F_105 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_19 ) ;
goto V_258;
}
F_138 ( V_2 ) ;
V_2 -> V_26 = V_27 ;
return 0 ;
V_258:
F_139 ( V_2 ) ;
V_257:
F_140 ( V_2 ) ;
V_256:
F_12 ( V_2 ) ;
return V_57 ;
}
static void
F_141 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 != V_27 )
return;
F_142 ( V_2 ) ;
F_139 ( V_2 ) ;
F_143 ( V_2 ) ;
F_107 ( V_2 ) ;
F_12 ( V_2 ) ;
F_140 ( V_2 ) ;
V_2 -> V_26 = 0 ;
}
void F_144 ( struct V_17 * V_18 , int V_20 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_7 * V_8 ;
int V_19 ;
F_78 ( V_54 , & V_2 -> V_55 ) ;
if ( V_2 -> V_238 == V_239 ) {
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_2 -> V_12 -> V_15 [ V_19 ] ;
F_3 ( V_8 ) ;
}
}
F_130 ( V_2 ) ;
F_141 ( V_2 ) ;
V_2 -> V_238 = 0 ;
V_2 -> V_20 = V_20 ;
if ( F_135 ( V_2 ) )
goto V_259;
if ( F_119 ( V_18 ) )
F_109 ( V_2 , V_18 ) ;
V_259:
F_34 ( V_18 ) ;
}
static int F_145 ( struct V_1 * V_2 )
{
int V_57 = 0 ;
V_2 -> V_67 = F_7 ( sizeof( struct V_260 ) ,
V_16 ) ;
if ( ! V_2 -> V_67 ) {
F_65 ( & V_2 -> V_30 -> V_45 ,
L_20 ) ;
V_57 = - V_21 ;
goto V_229;
}
V_2 -> V_12 = F_7 ( sizeof( struct V_11 ) ,
V_16 ) ;
if ( ! V_2 -> V_12 ) {
F_65 ( & V_2 -> V_30 -> V_45 ,
L_20 ) ;
F_9 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
V_57 = - V_21 ;
goto V_229;
}
V_2 -> V_67 -> V_261 . V_262 = V_263 ;
V_2 -> V_67 -> V_261 . V_264 = V_265 ;
V_2 -> V_67 -> V_261 . V_266 = V_267 ;
V_229:
return V_57 ;
}
static void F_146 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
if ( V_2 -> V_67 -> V_268 . V_269 ) {
F_147 ( V_2 -> V_67 -> V_268 . V_269 ) ;
V_2 -> V_67 -> V_268 . V_269 = NULL ;
}
F_9 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
}
int F_148 ( struct V_17 * V_18 , int V_270 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_7 * V_8 ;
struct V_245 * V_246 ;
int V_19 ;
int V_81 ;
F_32 ( V_18 ) ;
if ( F_119 ( V_18 ) )
F_121 ( V_2 , V_18 ) ;
F_141 ( V_2 ) ;
V_2 -> V_20 = 1 ;
V_2 -> V_238 = V_270 ;
V_81 = F_135 ( V_2 ) ;
if ( V_81 ) {
F_34 ( V_18 ) ;
return V_81 ;
}
V_81 = F_110 ( V_2 ) ;
if ( V_81 ) {
F_141 ( V_2 ) ;
F_34 ( V_18 ) ;
return V_81 ;
}
for ( V_19 = 0 ; V_19 < V_2 -> V_169 ; V_19 ++ ) {
V_246 = & V_2 -> V_12 -> V_247 [ V_19 ] ;
F_111 ( V_2 , V_246 ) ;
}
if ( V_2 -> V_238 == V_239 ) {
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_2 -> V_12 -> V_15 [ V_19 ] ;
F_4 ( V_8 ) ;
}
}
if ( V_2 -> V_238 == V_271 ) {
V_2 -> V_67 -> V_272 = 0 ;
F_116 ( V_2 , 1 ) ;
}
F_75 ( V_54 , & V_2 -> V_55 ) ;
return 0 ;
}
static int
F_149 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
if ( F_150 ( V_273 , & V_2 -> V_55 ) )
return - V_274 ;
F_32 ( V_18 ) ;
F_134 ( V_2 , V_18 ) ;
F_117 ( V_2 , V_18 ) ;
F_34 ( V_18 ) ;
F_78 ( V_273 , & V_2 -> V_55 ) ;
return 0 ;
}
int
F_151 ( struct V_1 * V_2 )
{
int V_57 = 0 ;
struct V_17 * V_18 = V_2 -> V_18 ;
if ( F_150 ( V_273 , & V_2 -> V_55 ) )
return - V_274 ;
if ( V_2 -> V_26 == V_27 ) {
F_32 ( V_18 ) ;
if ( F_119 ( V_18 ) )
F_121 ( V_2 , V_18 ) ;
F_141 ( V_2 ) ;
if ( F_119 ( V_18 ) ) {
V_57 = F_135 ( V_2 ) ;
if ( ! V_57 )
F_109 ( V_2 , V_18 ) ;
}
F_34 ( V_18 ) ;
}
F_78 ( V_273 , & V_2 -> V_55 ) ;
return V_57 ;
}
static int
F_152 ( struct V_1 * V_2 ,
struct V_17 * V_18 , T_2 V_275 )
{
int V_57 ;
struct V_29 * V_30 = V_2 -> V_30 ;
V_2 -> V_276 = 0 ;
V_2 -> V_277 = 38 ;
V_18 -> V_278 = & V_279 ;
V_18 -> V_280 = 5 * V_281 ;
F_153 ( V_18 , V_18 -> V_248 ) ;
F_154 ( V_18 , & V_282 ) ;
V_18 -> V_283 = V_198 | V_199 |
V_201 | V_200 ;
if ( V_2 -> V_178 & V_204 )
V_18 -> V_283 |= V_205 | V_206 ;
if ( V_275 )
V_18 -> V_283 |= V_284 ;
V_18 -> V_197 = V_18 -> V_283 ;
if ( V_2 -> V_178 & V_285 )
V_18 -> V_283 |= V_286 ;
if ( V_2 -> V_178 & V_287 )
V_18 -> V_283 |= V_207 ;
V_18 -> V_196 |= V_18 -> V_283 |
V_288 | V_203 ;
V_18 -> V_70 = V_2 -> V_37 [ 0 ] . V_69 ;
V_57 = F_155 ( V_18 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_21 ) ;
return V_57 ;
}
return 0 ;
}
static int F_156 ( struct V_29 * V_30 , T_2 * V_275 )
{
if ( ! F_157 ( V_30 , F_158 ( 64 ) ) &&
! F_159 ( V_30 , F_158 ( 64 ) ) )
* V_275 = 1 ;
else if ( ! F_157 ( V_30 , F_158 ( 32 ) ) &&
! F_159 ( V_30 , F_158 ( 32 ) ) )
* V_275 = 0 ;
else {
F_65 ( & V_30 -> V_45 , L_22 ) ;
return - V_41 ;
}
return 0 ;
}
static int
F_160 ( struct V_1 * V_2 , T_5 V_13 )
{
V_2 -> V_37 = F_51 ( V_13 , sizeof( struct V_289 ) ,
V_16 ) ;
if ( V_2 -> V_37 )
return 0 ;
F_65 ( & V_2 -> V_30 -> V_45 , L_23 ) ;
return - V_21 ;
}
static int T_7
F_161 ( struct V_29 * V_30 , const struct V_290 * V_291 )
{
struct V_17 * V_18 = NULL ;
struct V_1 * V_2 = NULL ;
int V_57 ;
T_8 V_292 ;
T_8 V_275 ;
char V_293 [ V_294 ] ;
V_57 = F_162 ( V_30 ) ;
if ( V_57 )
return V_57 ;
if ( ! ( F_163 ( V_30 , 0 ) & V_295 ) ) {
V_57 = - V_296 ;
goto V_297;
}
V_57 = F_156 ( V_30 , & V_275 ) ;
if ( V_57 )
goto V_297;
V_57 = F_164 ( V_30 , V_298 ) ;
if ( V_57 )
goto V_297;
F_165 ( V_30 ) ;
F_166 ( V_30 ) ;
V_18 = F_167 ( sizeof( struct V_1 ) ) ;
if ( ! V_18 ) {
F_65 ( & V_30 -> V_45 , L_24 ) ;
V_57 = - V_21 ;
goto V_299;
}
F_168 ( V_18 , & V_30 -> V_45 ) ;
V_2 = F_30 ( V_18 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_30 = V_30 ;
if ( F_145 ( V_2 ) )
goto V_300;
V_2 -> V_301 = V_302 ;
V_292 = V_30 -> V_303 ;
V_2 -> V_67 -> V_292 = V_292 ;
V_2 -> V_304 = V_305 ;
F_169 ( & V_2 -> V_67 -> V_306 ) ;
F_170 ( & V_2 -> V_67 -> V_307 ) ;
F_171 ( & V_2 -> V_252 ) ;
F_172 ( & V_2 -> V_308 ) ;
V_57 = F_61 ( V_2 ) ;
if ( V_57 )
goto V_258;
V_2 -> V_309 = V_2 -> V_67 -> V_68 ;
V_57 = F_173 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_25 ) ;
goto V_310;
}
V_57 = F_174 ( V_2 ) ;
if ( V_57 )
goto V_310;
V_2 -> V_49 |= V_311 ;
V_57 = V_2 -> V_123 -> V_312 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_26 ) ;
goto V_313;
}
if ( V_2 -> V_114 != V_122 )
if ( ! F_175 ( V_2 ) )
F_37 ( & V_30 -> V_45 ,
L_27 ) ;
if ( F_25 ( V_2 ) )
F_28 ( & V_30 -> V_45 , L_28 ) ;
if ( V_2 -> V_309 == 0 ) {
F_68 ( V_2 , V_293 ) ;
F_176 ( L_29 ,
F_177 ( V_314 ) ,
V_293 , V_2 -> V_67 -> V_292 ) ;
}
F_19 ( V_2 ) ;
V_57 = F_160 ( V_2 , V_2 -> V_177 ) ;
if ( V_57 )
goto V_313;
F_42 ( V_2 ) ;
V_57 = F_152 ( V_2 , V_18 , V_275 ) ;
if ( V_57 )
goto V_315;
F_178 ( V_30 , V_2 ) ;
F_179 ( V_2 , V_316 , V_317 ) ;
switch ( V_2 -> V_67 -> V_150 ) {
case V_162 :
F_37 ( & V_2 -> V_30 -> V_45 , L_30 ,
V_2 -> V_18 -> V_132 ) ;
break;
case V_151 :
F_37 ( & V_2 -> V_30 -> V_45 , L_31 ,
V_2 -> V_18 -> V_132 ) ;
break;
}
if ( V_2 -> V_304 )
F_180 ( V_2 ) ;
F_181 ( V_2 ) ;
return 0 ;
V_315:
F_45 ( V_2 ) ;
F_9 ( V_2 -> V_37 ) ;
V_313:
F_182 ( V_2 , 0 ) ;
V_310:
F_48 ( V_2 ) ;
V_258:
F_146 ( V_2 ) ;
V_300:
F_183 ( V_18 ) ;
V_299:
F_184 ( V_30 ) ;
V_297:
F_178 ( V_30 , NULL ) ;
F_185 ( V_30 ) ;
return V_57 ;
}
static void T_9 F_186 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 ;
V_2 = F_187 ( V_30 ) ;
if ( V_2 == NULL )
return;
V_18 = V_2 -> V_18 ;
F_188 ( V_2 ) ;
F_189 ( V_18 ) ;
F_141 ( V_2 ) ;
if ( V_2 -> V_84 != NULL )
F_9 ( V_2 -> V_84 ) ;
if ( V_2 -> V_87 != NULL )
F_9 ( V_2 -> V_87 ) ;
F_182 ( V_2 , 0 ) ;
F_78 ( V_273 , & V_2 -> V_55 ) ;
F_190 ( V_2 ) ;
F_45 ( V_2 ) ;
F_9 ( V_2 -> V_37 ) ;
F_191 ( V_2 ) ;
F_48 ( V_2 ) ;
F_101 ( V_2 ) ;
F_192 ( V_30 ) ;
F_184 ( V_30 ) ;
F_185 ( V_30 ) ;
F_178 ( V_30 , NULL ) ;
F_146 ( V_2 ) ;
F_183 ( V_18 ) ;
}
static int F_193 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_187 ( V_30 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
int V_318 ;
F_32 ( V_18 ) ;
F_188 ( V_2 ) ;
if ( F_119 ( V_18 ) )
F_134 ( V_2 , V_18 ) ;
F_182 ( V_2 , 0 ) ;
F_78 ( V_273 , & V_2 -> V_55 ) ;
V_318 = F_194 ( V_30 ) ;
if ( V_318 )
return V_318 ;
if ( F_195 ( V_2 ) ) {
F_196 ( V_30 , V_319 , 1 ) ;
F_196 ( V_30 , V_320 , 1 ) ;
}
return 0 ;
}
static void F_197 ( struct V_29 * V_30 )
{
if ( F_193 ( V_30 ) )
return;
F_185 ( V_30 ) ;
}
static int
F_198 ( struct V_29 * V_30 , T_10 V_55 )
{
int V_318 ;
V_318 = F_193 ( V_30 ) ;
if ( V_318 )
return V_318 ;
F_199 ( V_30 , F_200 ( V_30 , V_55 ) ) ;
return 0 ;
}
static int
F_201 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_187 ( V_30 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
int V_57 ;
V_57 = F_162 ( V_30 ) ;
if ( V_57 )
return V_57 ;
F_199 ( V_30 , V_321 ) ;
F_165 ( V_30 ) ;
F_202 ( V_30 ) ;
V_57 = V_2 -> V_123 -> V_312 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_32 ) ;
return V_57 ;
}
if ( F_119 ( V_18 ) ) {
V_57 = F_117 ( V_2 , V_18 ) ;
if ( V_57 )
goto V_322;
F_77 ( V_18 , V_323 ) ;
}
V_322:
F_34 ( V_18 ) ;
F_179 ( V_2 , V_316 , V_317 ) ;
return 0 ;
}
static int F_203 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
int V_57 ;
F_125 ( V_18 ) ;
V_57 = F_135 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_109 ( V_2 , V_18 ) ;
if ( V_57 )
goto V_229;
F_204 ( V_18 ) ;
return 0 ;
V_229:
F_141 ( V_2 ) ;
return V_57 ;
}
static int F_205 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
F_121 ( V_2 , V_18 ) ;
return 0 ;
}
void F_180 ( struct V_1 * V_2 )
{
void * V_324 ;
int V_36 ;
if ( V_2 -> V_253 . V_325 && V_2 -> V_253 . V_326 )
return;
F_171 ( & V_2 -> V_327 ) ;
V_324 = F_51 ( V_328 , sizeof( struct V_329 ) ,
V_16 ) ;
if ( ! V_324 )
return;
V_2 -> V_253 . V_325 = V_328 ;
V_2 -> V_253 . V_326 = V_324 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_253 . V_325 ; V_36 ++ )
F_206 ( & V_2 -> V_253 . V_326 [ V_36 ] ) ;
}
static void F_190 ( struct V_1 * V_2 )
{
if ( V_2 -> V_253 . V_325 && V_2 -> V_253 . V_326 )
F_9 ( V_2 -> V_253 . V_326 ) ;
V_2 -> V_253 . V_326 = NULL ;
V_2 -> V_253 . V_325 = 0 ;
}
static void F_207 ( struct V_1 * V_2 ,
T_11 V_330 , T_12 V_186 , struct V_3 * V_4 )
{
struct V_331 * V_332 ;
struct V_333 * V_334 ;
struct V_335 * V_336 ;
struct V_337 * V_338 ;
T_1 V_5 ;
T_11 V_339 ;
V_5 = V_4 -> V_5 ;
V_332 = & V_4 -> V_340 [ V_4 -> V_5 ] ;
V_334 = (struct V_333 * ) V_332 ;
memset ( V_334 , 0 , sizeof( struct V_333 ) ) ;
V_334 -> V_341 = F_208 ( V_342 << 23 ) ;
V_339 = V_343 | ( ( T_11 ) ( V_2 -> V_309 ) << 16 ) ;
V_334 -> V_344 = F_208 ( V_339 ) ;
V_336 = (struct V_335 * ) & ( V_334 -> V_345 [ 0 ] ) ;
V_336 -> V_346 = V_186 ? V_347 : V_348 ;
memcpy ( V_336 -> V_39 , & V_330 , V_40 ) ;
V_338 = (struct V_337 * ) & V_334 -> V_345 [ 1 ] ;
V_338 -> V_186 = V_186 ;
V_4 -> V_5 = F_209 ( V_5 , V_4 -> V_349 ) ;
F_123 () ;
}
static void
F_210 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_331 * V_350 ,
struct V_351 * V_352 )
{
struct V_353 * V_354 = (struct V_353 * ) ( V_352 -> V_103 ) ;
struct V_355 * V_356 , * V_357 ;
struct V_358 * V_359 , * V_360 ;
struct V_329 * V_324 ;
T_11 V_361 = 0 ;
T_12 V_186 = 0 ;
T_2 V_362 ;
if ( ! F_211 ( V_354 -> V_363 , V_2 -> V_39 ) )
return;
if ( V_2 -> V_253 . V_254 >= V_2 -> V_253 . V_325 )
return;
if ( V_2 -> V_49 & V_152 )
V_186 = V_350 -> V_364 ;
memcpy ( & V_361 , V_354 -> V_363 , V_40 ) ;
V_362 = F_212 ( V_361 ) & ( V_328 - 1 ) ;
V_324 = & ( V_2 -> V_253 . V_326 [ V_362 ] ) ;
F_213 (tmp_fil, tmp_hnode, n, head, fnode) {
if ( ! memcmp ( V_357 -> V_365 , & V_361 , V_40 ) &&
V_357 -> V_186 == V_186 ) {
if ( V_302 >
( V_366 * V_281 + V_357 -> V_367 ) )
F_207 ( V_2 , V_361 , V_186 ,
V_4 ) ;
V_357 -> V_367 = V_302 ;
return;
}
}
V_356 = F_7 ( sizeof( struct V_355 ) , V_368 ) ;
if ( ! V_356 )
return;
F_207 ( V_2 , V_361 , V_186 , V_4 ) ;
V_356 -> V_367 = V_302 ;
V_356 -> V_186 = V_186 ;
memcpy ( V_356 -> V_365 , & V_361 , V_40 ) ;
F_124 ( & V_2 -> V_327 ) ;
F_214 ( & ( V_356 -> V_369 ) , V_324 ) ;
V_2 -> V_253 . V_254 ++ ;
F_133 ( & V_2 -> V_327 ) ;
}
static int
F_215 ( struct V_1 * V_2 ,
struct V_331 * V_350 ,
struct V_351 * V_352 )
{
T_2 V_370 = 0 , V_371 = 0 ;
T_5 V_49 = 0 , V_372 = 0 ;
int V_373 , V_374 , V_375 ;
struct V_331 * V_332 ;
struct V_376 * V_377 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_5 V_378 = F_216 ( V_352 -> V_378 ) ;
T_1 V_5 = V_4 -> V_5 ;
if ( V_378 == V_379 ) {
V_377 = (struct V_376 * ) V_352 -> V_103 ;
V_49 = V_380 ;
V_372 = V_377 -> V_381 ;
} else if ( F_217 ( V_352 ) ) {
V_49 = V_382 ;
V_372 = F_218 ( V_352 ) ;
}
if ( F_219 ( V_2 -> V_187 ) ) {
if ( V_372 && ! ( V_2 -> V_49 & V_185 ) )
return - V_41 ;
if ( V_372 && ( V_2 -> V_49 & V_185 ) )
goto V_383;
V_49 = V_382 ;
V_372 = V_2 -> V_187 ;
}
V_383:
F_220 ( V_350 , V_372 ) ;
F_221 ( V_350 , V_49 , V_370 ) ;
if ( * ( V_352 -> V_103 ) & V_209 ) {
V_49 |= V_209 ;
memcpy ( & V_350 -> V_384 , V_352 -> V_103 , V_40 ) ;
}
V_370 = V_385 ;
if ( ( V_2 -> V_18 -> V_196 & ( V_205 | V_206 ) ) &&
F_222 ( V_352 ) -> V_386 > 0 ) {
V_371 = F_223 ( V_352 ) + F_224 ( V_352 ) ;
V_350 -> V_387 = F_225 ( F_222 ( V_352 ) -> V_386 ) ;
V_350 -> V_388 = V_371 ;
V_370 = ( V_378 == V_389 ) ? V_390 : V_391 ;
V_373 = 0 ;
V_374 = 2 ;
if ( V_49 & V_382 ) {
V_350 -> V_388 += V_392 ;
V_350 -> V_393 = V_392 ;
V_350 -> V_394 = V_392 ;
V_49 |= V_380 ;
V_332 = & V_4 -> V_340 [ V_5 ] ;
V_4 -> V_395 [ V_5 ] . V_352 = NULL ;
V_375 = F_226 ( ( int ) sizeof( struct V_331 ) -
V_374 , V_371 + V_392 ) ;
V_377 = (struct V_376 * ) ( ( char * ) V_332 + 2 ) ;
F_227 ( V_352 , V_377 , 12 ) ;
V_377 -> V_396 = F_228 ( V_379 ) ;
V_377 -> V_381 = F_228 ( V_372 ) ;
F_229 ( V_352 , 12 ,
( char * ) V_377 + 16 , V_375 - 16 ) ;
V_373 = V_375 - V_392 ;
V_374 = 0 ;
V_5 = F_209 ( V_5 , V_4 -> V_349 ) ;
}
while ( V_373 < V_371 ) {
V_375 = F_226 ( ( int ) sizeof( struct V_331 ) -
V_374 , ( V_371 - V_373 ) ) ;
V_332 = & V_4 -> V_340 [ V_5 ] ;
V_4 -> V_395 [ V_5 ] . V_352 = NULL ;
F_229 ( V_352 , V_373 ,
( char * ) V_332 + V_374 , V_375 ) ;
V_373 += V_375 ;
V_374 = 0 ;
V_5 = F_209 ( V_5 , V_4 -> V_349 ) ;
}
V_4 -> V_5 = V_5 ;
F_123 () ;
V_2 -> V_28 . V_397 ++ ;
} else if ( V_352 -> V_398 == V_399 ) {
T_2 V_400 ;
if ( V_378 == V_401 ) {
V_400 = F_230 ( V_352 ) -> V_378 ;
if ( V_400 == V_402 )
V_370 = V_403 ;
else if ( V_400 == V_404 )
V_370 = V_405 ;
} else if ( V_378 == V_389 ) {
V_400 = F_231 ( V_352 ) -> V_406 ;
if ( V_400 == V_402 )
V_370 = V_407 ;
else if ( V_400 == V_404 )
V_370 = V_408 ;
}
}
V_350 -> V_393 += F_223 ( V_352 ) ;
V_350 -> V_394 += F_232 ( V_352 ) ;
F_221 ( V_350 , V_49 , V_370 ) ;
return 0 ;
}
static int
F_233 ( struct V_29 * V_30 ,
struct V_351 * V_352 , struct V_409 * V_410 )
{
struct V_411 * V_412 ;
struct V_413 * V_414 ;
int V_36 , V_415 ;
T_13 V_416 ;
V_415 = F_222 ( V_352 ) -> V_415 ;
V_412 = & V_410 -> V_417 [ 0 ] ;
V_416 = F_234 ( V_30 , V_352 -> V_103 ,
F_235 ( V_352 ) , V_418 ) ;
if ( F_236 ( V_30 , V_416 ) )
goto V_419;
V_412 -> V_420 = V_416 ;
V_412 -> V_421 = F_235 ( V_352 ) ;
for ( V_36 = 0 ; V_36 < V_415 ; V_36 ++ ) {
V_414 = & F_222 ( V_352 ) -> V_422 [ V_36 ] ;
V_412 = & V_410 -> V_417 [ V_36 + 1 ] ;
V_416 = F_237 ( V_30 , V_414 -> V_423 , V_414 -> V_424 ,
V_414 -> V_14 , V_418 ) ;
if ( F_236 ( V_30 , V_416 ) )
goto V_425;
V_412 -> V_420 = V_416 ;
V_412 -> V_421 = V_414 -> V_14 ;
}
return 0 ;
V_425:
while ( -- V_36 >= 0 ) {
V_412 = & V_410 -> V_417 [ V_36 + 1 ] ;
F_238 ( V_30 , V_412 -> V_420 , V_412 -> V_421 , V_418 ) ;
}
V_412 = & V_410 -> V_417 [ 0 ] ;
F_239 ( V_30 , V_412 -> V_420 , F_235 ( V_352 ) , V_418 ) ;
V_419:
return - V_21 ;
}
static void
F_240 ( struct V_29 * V_30 , struct V_351 * V_352 ,
struct V_409 * V_410 )
{
struct V_411 * V_412 = & V_410 -> V_417 [ 0 ] ;
int V_415 = F_222 ( V_352 ) -> V_415 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_415 ; V_36 ++ ) {
V_412 = & V_410 -> V_417 [ V_36 + 1 ] ;
F_238 ( V_30 , V_412 -> V_420 , V_412 -> V_421 , V_418 ) ;
}
V_412 = & V_410 -> V_417 [ 0 ] ;
F_239 ( V_30 , V_412 -> V_420 , F_235 ( V_352 ) , V_418 ) ;
V_410 -> V_352 = NULL ;
}
static inline void
F_241 ( T_11 * V_426 )
{
V_426 [ 0 ] = 0ULL ;
V_426 [ 2 ] = 0ULL ;
V_426 [ 7 ] = 0ULL ;
}
T_14
F_242 ( struct V_351 * V_352 , struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_409 * V_410 ;
struct V_411 * V_427 ;
struct V_331 * V_332 , * V_350 ;
struct V_29 * V_30 ;
struct V_353 * V_354 ;
int V_428 = 0 ;
int V_36 , V_429 ;
T_1 V_5 ;
int V_430 ;
T_1 V_167 = V_4 -> V_349 ;
if ( ! F_31 ( V_54 , & V_2 -> V_55 ) ) {
F_243 ( V_18 ) ;
return V_431 ;
}
if ( V_2 -> V_49 & V_191 ) {
V_354 = (struct V_353 * ) V_352 -> V_103 ;
if ( F_211 ( V_354 -> V_363 ,
V_2 -> V_39 ) )
goto V_432;
}
V_430 = F_222 ( V_352 ) -> V_415 + 1 ;
if ( ! F_244 ( V_352 ) && V_430 > V_433 ) {
for ( V_36 = 0 ; V_36 < ( V_430 - V_433 ) ; V_36 ++ )
V_428 += F_222 ( V_352 ) -> V_422 [ V_36 ] . V_14 ;
if ( ! F_245 ( V_352 , V_428 ) )
goto V_432;
V_430 = 1 + F_222 ( V_352 ) -> V_415 ;
}
if ( F_219 ( F_246 ( V_4 ) <= V_434 ) ) {
F_243 ( V_18 ) ;
if ( F_246 ( V_4 ) > V_434 )
F_204 ( V_18 ) ;
else {
V_2 -> V_28 . V_435 ++ ;
return V_431 ;
}
}
V_5 = V_4 -> V_5 ;
V_410 = & V_4 -> V_395 [ V_5 ] ;
V_30 = V_2 -> V_30 ;
V_350 = V_332 = & V_4 -> V_340 [ V_5 ] ;
F_241 ( ( T_11 * ) V_332 ) ;
if ( F_233 ( V_30 , V_352 , V_410 ) ) {
V_2 -> V_28 . V_436 ++ ;
goto V_432;
}
V_410 -> V_352 = V_352 ;
V_410 -> V_430 = V_430 ;
F_247 ( V_350 , V_430 , V_352 -> V_437 ) ;
F_248 ( V_350 , V_2 -> V_309 ) ;
for ( V_36 = 0 ; V_36 < V_430 ; V_36 ++ ) {
V_429 = V_36 % 4 ;
if ( ( V_429 == 0 ) && ( V_36 > 0 ) ) {
V_5 = F_209 ( V_5 , V_167 ) ;
V_332 = & V_4 -> V_340 [ V_5 ] ;
F_241 ( ( T_11 * ) V_332 ) ;
V_4 -> V_395 [ V_5 ] . V_352 = NULL ;
}
V_427 = & V_410 -> V_417 [ V_36 ] ;
V_332 -> V_438 [ V_429 ] = F_225 ( V_427 -> V_421 ) ;
switch ( V_429 ) {
case 0 :
V_332 -> V_439 = F_208 ( V_427 -> V_420 ) ;
break;
case 1 :
V_332 -> V_440 = F_208 ( V_427 -> V_420 ) ;
break;
case 2 :
V_332 -> V_441 = F_208 ( V_427 -> V_420 ) ;
break;
case 3 :
V_332 -> V_442 = F_208 ( V_427 -> V_420 ) ;
break;
}
}
V_4 -> V_5 = F_209 ( V_5 , V_167 ) ;
F_123 () ;
if ( F_219 ( F_215 ( V_2 , V_350 , V_352 ) ) )
goto V_443;
if ( V_2 -> V_304 )
F_210 ( V_2 , V_4 , V_350 , V_352 ) ;
V_2 -> V_28 . V_444 += V_352 -> V_437 ;
V_2 -> V_28 . V_445 ++ ;
F_1 ( V_2 , V_4 ) ;
return V_446 ;
V_443:
F_240 ( V_30 , V_352 , V_410 ) ;
V_432:
V_2 -> V_28 . V_447 ++ ;
F_249 ( V_352 ) ;
return V_446 ;
}
static int F_250 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_448 , V_449 , V_450 ;
int V_451 = 0 ;
V_448 = F_54 ( V_2 , V_452 ) ;
V_449 = F_251 ( V_448 ) ;
V_450 = F_252 ( V_448 ) ;
if ( V_449 == V_453 ) {
F_65 ( & V_18 -> V_45 ,
L_33
L_34 ,
V_450 ) ;
V_451 = 1 ;
} else if ( V_449 == V_454 ) {
if ( V_2 -> V_448 == V_455 ) {
F_65 ( & V_18 -> V_45 ,
L_35
L_36
L_37 ,
V_450 ) ;
}
} else {
if ( V_2 -> V_448 == V_454 ) {
F_37 ( & V_18 -> V_45 ,
L_38
L_39 , V_450 ) ;
}
}
V_2 -> V_448 = V_449 ;
return V_451 ;
}
void F_253 ( struct V_1 * V_2 , int V_249 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
if ( V_2 -> V_67 -> V_249 && ! V_249 ) {
F_254 ( V_18 , L_40 ) ;
V_2 -> V_67 -> V_249 = 0 ;
if ( F_119 ( V_18 ) ) {
F_125 ( V_18 ) ;
F_243 ( V_18 ) ;
}
} else if ( ! V_2 -> V_67 -> V_249 && V_249 ) {
F_254 ( V_18 , L_41 ) ;
V_2 -> V_67 -> V_249 = 1 ;
if ( F_119 ( V_18 ) ) {
F_255 ( V_18 ) ;
F_256 ( V_18 ) ;
}
}
}
static void F_257 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
if ( F_31 ( V_273 , & V_2 -> V_55 ) )
return;
F_65 ( & V_18 -> V_45 , L_42 ) ;
if ( ++ V_2 -> V_456 >= V_457 )
V_2 -> V_215 = 1 ;
else
V_2 -> V_251 = 1 ;
}
static struct V_458 * F_258 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_458 * V_28 = & V_18 -> V_28 ;
V_28 -> V_266 = V_2 -> V_28 . V_459 + V_2 -> V_28 . V_460 ;
V_28 -> V_461 = V_2 -> V_28 . V_462 ;
V_28 -> V_463 = V_2 -> V_28 . V_464 + V_2 -> V_28 . V_465 ;
V_28 -> V_466 = V_2 -> V_28 . V_444 ;
V_28 -> V_467 = V_2 -> V_28 . V_468 ;
V_28 -> V_469 = V_2 -> V_28 . V_447 ;
return V_28 ;
}
static T_15 F_259 ( struct V_1 * V_2 )
{
T_1 V_470 ;
V_470 = F_57 ( V_2 -> V_73 ) ;
if ( ! ( V_470 & V_2 -> V_72 ) )
return V_471 ;
V_470 = F_57 ( V_2 -> V_75 ) ;
if ( ! F_260 ( V_470 ) )
return V_471 ;
F_2 ( 0xffffffff , V_2 -> V_65 ) ;
F_57 ( V_2 -> V_73 ) ;
F_57 ( V_2 -> V_73 ) ;
return V_472 ;
}
static T_15 V_240 ( int V_70 , void * V_103 )
{
struct V_7 * V_8 = V_103 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_49 & V_59 )
goto V_322;
else if ( V_2 -> V_49 & V_58 ) {
F_2 ( 0xffffffff , V_2 -> V_65 ) ;
goto V_322;
}
if ( F_259 ( V_2 ) == V_471 )
return V_471 ;
V_322:
V_2 -> V_473 ++ ;
F_4 ( V_8 ) ;
return V_472 ;
}
static T_15 V_244 ( int V_70 , void * V_103 )
{
struct V_7 * V_8 = V_103 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_259 ( V_2 ) == V_471 )
return V_471 ;
F_261 ( & V_8 -> V_22 ) ;
return V_472 ;
}
static T_15 V_243 ( int V_70 , void * V_103 )
{
struct V_7 * V_8 = V_103 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_2 ( 0xffffffff , V_2 -> V_65 ) ;
F_261 ( & V_8 -> V_22 ) ;
return V_472 ;
}
static T_15 V_242 ( int V_70 , void * V_103 )
{
struct V_7 * V_8 = V_103 ;
F_261 ( & V_8 -> V_22 ) ;
return V_472 ;
}
static int F_262 ( struct V_1 * V_2 )
{
T_1 V_474 , V_475 ;
int V_13 = 0 , V_36 ;
struct V_409 * V_476 ;
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_411 * V_414 ;
int V_322 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_263 ( & V_2 -> V_252 ) )
return 1 ;
V_474 = V_4 -> V_474 ;
V_475 = F_264 ( * ( V_4 -> V_475 ) ) ;
while ( V_474 != V_475 ) {
V_476 = & V_4 -> V_395 [ V_474 ] ;
if ( V_476 -> V_352 ) {
V_414 = & V_476 -> V_417 [ 0 ] ;
F_239 ( V_30 , V_414 -> V_420 , V_414 -> V_421 ,
V_418 ) ;
V_414 -> V_420 = 0ULL ;
for ( V_36 = 1 ; V_36 < V_476 -> V_430 ; V_36 ++ ) {
V_414 ++ ;
F_238 ( V_30 , V_414 -> V_420 , V_414 -> V_421 ,
V_418 ) ;
V_414 -> V_420 = 0ULL ;
}
V_2 -> V_28 . V_462 ++ ;
F_249 ( V_476 -> V_352 ) ;
V_476 -> V_352 = NULL ;
}
V_474 = F_209 ( V_474 , V_4 -> V_349 ) ;
if ( ++ V_13 >= V_477 )
break;
}
if ( V_13 && F_119 ( V_18 ) ) {
V_4 -> V_474 = V_474 ;
F_123 () ;
if ( F_265 ( V_18 ) && F_266 ( V_18 ) ) {
if ( F_246 ( V_4 ) > V_434 ) {
F_256 ( V_18 ) ;
V_2 -> V_28 . V_478 ++ ;
}
}
V_2 -> V_456 = 0 ;
}
V_475 = F_264 ( * ( V_4 -> V_475 ) ) ;
V_322 = ( V_474 == V_475 ) ;
F_133 ( & V_2 -> V_252 ) ;
return V_322 ;
}
static int V_23 ( struct V_479 * V_22 , int V_480 )
{
struct V_7 * V_8 =
F_267 ( V_22 , struct V_7 , V_22 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_481 ;
int V_482 ;
V_481 = F_262 ( V_2 ) ;
V_482 = F_268 ( V_8 , V_480 ) ;
if ( ( V_482 < V_480 ) && V_481 ) {
F_269 ( & V_8 -> V_22 ) ;
if ( F_31 ( V_54 , & V_2 -> V_55 ) )
F_4 ( V_8 ) ;
}
return V_482 ;
}
static int V_25 ( struct V_479 * V_22 , int V_480 )
{
struct V_7 * V_8 =
F_267 ( V_22 , struct V_7 , V_22 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_482 ;
V_482 = F_268 ( V_8 , V_480 ) ;
if ( V_482 < V_480 ) {
F_269 ( & V_8 -> V_22 ) ;
if ( F_31 ( V_54 , & V_2 -> V_55 ) )
F_4 ( V_8 ) ;
}
return V_482 ;
}
static void F_270 ( struct V_17 * V_18 )
{
int V_19 ;
struct V_7 * V_8 ;
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
F_271 ( V_2 -> V_70 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_12 -> V_15 [ V_19 ] ;
V_244 ( V_2 -> V_70 , V_8 ) ;
}
F_272 ( V_2 -> V_70 ) ;
}
static void
F_104 ( struct V_1 * V_2 , T_2 V_483 )
{
T_1 V_484 ;
V_484 = V_2 -> V_309 & 0xf ;
V_484 |= V_483 << 7 ;
V_484 |= ( V_302 - V_2 -> V_301 ) << 8 ;
F_102 ( V_2 , V_485 , V_484 ) ;
V_2 -> V_301 = V_302 ;
}
static int
F_273 ( struct V_1 * V_2 , T_2 V_55 )
{
T_1 V_484 ;
F_274 ( V_55 != V_486 &&
V_55 != V_487 ) ;
if ( F_55 ( V_2 ) )
return - V_41 ;
V_484 = F_54 ( V_2 , V_488 ) ;
if ( V_55 == V_486 )
F_275 ( V_484 , V_2 -> V_309 ) ;
else if ( V_55 == V_487 )
F_276 ( V_484 , V_2 -> V_309 ) ;
F_102 ( V_2 , V_488 , V_484 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
static int
F_277 ( struct V_1 * V_2 )
{
T_1 V_484 ;
if ( F_55 ( V_2 ) )
return - V_274 ;
V_484 = F_54 ( V_2 , V_488 ) ;
F_278 ( V_484 , V_2 -> V_309 ) ;
F_102 ( V_2 , V_488 , V_484 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
static void
F_182 ( struct V_1 * V_2 , T_2 V_489 )
{
T_1 V_484 ;
if ( F_55 ( V_2 ) )
goto V_57;
V_484 = F_54 ( V_2 , V_107 ) ;
F_279 ( V_484 , V_2 -> V_309 ) ;
F_102 ( V_2 , V_107 , V_484 ) ;
if ( V_489 ) {
F_102 ( V_2 , V_234 , V_236 ) ;
F_37 ( & V_2 -> V_30 -> V_45 ,
L_43 ) ;
} else if ( ! ( V_484 & 0x11111111 ) )
F_102 ( V_2 , V_234 , V_490 ) ;
V_484 = F_54 ( V_2 , V_488 ) ;
F_278 ( V_484 , V_2 -> V_309 ) ;
F_102 ( V_2 , V_488 , V_484 ) ;
F_58 ( V_2 ) ;
V_57:
V_2 -> V_491 = 0 ;
F_78 ( V_492 , & V_2 -> V_55 ) ;
F_78 ( V_273 , & V_2 -> V_55 ) ;
}
static int
F_280 ( struct V_1 * V_2 )
{
int V_493 , V_55 , V_494 ;
V_55 = F_54 ( V_2 , V_488 ) ;
V_493 = F_54 ( V_2 , V_107 ) ;
if ( V_2 -> V_49 & V_495 ) {
V_494 = ( ~ ( 1 << ( V_2 -> V_67 -> V_68 * 4 ) ) ) ;
V_493 = V_493 & V_494 ;
}
if ( ( ( V_55 & 0x11111111 ) == ( V_493 & 0x11111111 ) ) ||
( ( V_493 & 0x11111111 ) == ( ( V_55 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_281 ( struct V_1 * V_2 )
{
T_1 V_484 = F_54 ( V_2 , V_496 ) ;
if ( V_484 != V_497 ) {
F_28 ( & V_2 -> V_30 -> V_45 , L_44
L_45 , V_497 , V_484 ) ;
}
return 0 ;
}
static int
F_95 ( struct V_1 * V_2 )
{
T_1 V_484 , V_498 ;
T_2 V_499 = V_2 -> V_499 ;
T_2 V_309 = V_2 -> V_309 ;
T_2 V_81 ;
if ( F_122 ( V_492 , & V_2 -> V_55 ) )
return 1 ;
if ( F_55 ( V_2 ) )
return - 1 ;
V_484 = F_54 ( V_2 , V_107 ) ;
if ( ! ( V_484 & ( 1 << ( V_309 * 4 ) ) ) ) {
F_282 ( V_484 , V_309 ) ;
F_102 ( V_2 , V_107 , V_484 ) ;
}
V_498 = F_54 ( V_2 , V_234 ) ;
F_283 ( V_2 , V_500 , L_46 , V_498 ) ;
switch ( V_498 ) {
case V_490 :
F_102 ( V_2 , V_234 , V_501 ) ;
F_102 ( V_2 , V_496 , V_497 ) ;
F_104 ( V_2 , 0 ) ;
F_58 ( V_2 ) ;
return 1 ;
case V_235 :
V_81 = F_281 ( V_2 ) ;
F_58 ( V_2 ) ;
return V_81 ;
case V_486 :
V_484 = F_54 ( V_2 , V_488 ) ;
F_275 ( V_484 , V_309 ) ;
F_102 ( V_2 , V_488 , V_484 ) ;
break;
case V_487 :
V_484 = F_54 ( V_2 , V_488 ) ;
F_276 ( V_484 , V_309 ) ;
F_102 ( V_2 , V_488 , V_484 ) ;
break;
case V_236 :
F_65 ( & V_2 -> V_30 -> V_45 , L_47 ) ;
F_58 ( V_2 ) ;
return - 1 ;
case V_501 :
case V_502 :
break;
}
F_58 ( V_2 ) ;
do {
F_91 ( 1000 ) ;
V_498 = F_54 ( V_2 , V_234 ) ;
if ( V_498 == V_502 )
continue;
} while ( ( V_498 != V_235 ) && -- V_499 );
if ( ! V_499 ) {
F_65 ( & V_2 -> V_30 -> V_45 ,
L_48 ) ;
return - 1 ;
}
if ( F_55 ( V_2 ) )
return - 1 ;
V_484 = F_54 ( V_2 , V_488 ) ;
F_278 ( V_484 , V_309 ) ;
F_102 ( V_2 , V_488 , V_484 ) ;
V_81 = F_281 ( V_2 ) ;
F_58 ( V_2 ) ;
return V_81 ;
}
static void
F_284 ( struct V_503 * V_504 )
{
struct V_1 * V_2 = F_267 ( V_504 ,
struct V_1 , V_505 . V_504 ) ;
T_1 V_506 = 0xf ;
T_1 V_484 ;
if ( F_55 ( V_2 ) )
goto V_507;
V_506 = F_54 ( V_2 , V_234 ) ;
if ( V_506 == V_502 ||
V_506 == V_487 ) {
F_58 ( V_2 ) ;
F_179 ( V_2 , F_284 ,
V_317 * 2 ) ;
return;
}
if ( V_2 -> V_114 == V_122 ) {
F_58 ( V_2 ) ;
goto V_508;
}
if ( V_2 -> V_509 ++ > V_2 -> V_510 ) {
F_65 ( & V_2 -> V_30 -> V_45 , L_49 ,
V_2 -> V_510 ) ;
goto V_511;
}
if ( ! F_280 ( V_2 ) ) {
V_511:
V_506 = F_54 ( V_2 , V_234 ) ;
if ( V_506 == V_486 ) {
F_102 ( V_2 , V_234 ,
V_501 ) ;
F_75 ( V_492 , & V_2 -> V_55 ) ;
F_283 ( V_2 , V_512 , L_50 ) ;
F_104 ( V_2 , 0 ) ;
V_484 = F_54 ( V_2 , V_488 ) ;
F_275 ( V_484 , V_2 -> V_309 ) ;
F_102 ( V_2 , V_488 , V_484 ) ;
}
F_58 ( V_2 ) ;
F_118 () ;
if ( V_2 -> V_67 -> V_268 . V_31 &&
( V_2 -> V_49 & V_495 ) ) {
F_283 ( V_2 , V_512 , L_51 ) ;
F_285 ( V_2 ) ;
}
F_120 () ;
V_2 -> V_49 &= ~ V_495 ;
if ( ! V_2 -> V_123 -> V_312 ( V_2 ) ) {
F_179 ( V_2 , V_513 , 0 ) ;
V_2 -> V_509 = 0 ;
return;
}
goto V_507;
}
F_58 ( V_2 ) ;
V_508:
V_506 = F_54 ( V_2 , V_234 ) ;
F_283 ( V_2 , V_500 , L_52 , V_506 ) ;
switch ( V_506 ) {
case V_235 :
if ( ! V_2 -> V_123 -> V_312 ( V_2 ) ) {
F_179 ( V_2 , V_513 , 0 ) ;
V_2 -> V_509 = 0 ;
return;
}
case V_236 :
break;
default:
F_179 ( V_2 ,
F_284 , V_317 ) ;
return;
}
V_507:
F_65 ( & V_2 -> V_30 -> V_45 , L_53
L_54 , V_506 , V_2 -> V_509 ) ;
F_34 ( V_2 -> V_18 ) ;
F_182 ( V_2 , 0 ) ;
}
static void
F_286 ( struct V_503 * V_504 )
{
struct V_1 * V_2 = F_267 ( V_504 ,
struct V_1 , V_505 . V_504 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_470 ;
F_32 ( V_18 ) ;
if ( V_2 -> V_506 == V_487 ) {
if ( F_119 ( V_18 ) )
F_121 ( V_2 , V_18 ) ;
} else
F_134 ( V_2 , V_18 ) ;
V_470 = F_54 ( V_2 , V_514 ) ;
if ( V_470 & V_515 )
goto V_507;
if ( V_2 -> V_448 == V_453 )
goto V_507;
if ( ! ( V_2 -> V_49 & V_495 ) ) {
if ( F_273 ( V_2 , V_2 -> V_506 ) )
goto V_507;
}
V_2 -> V_509 = 0 ;
F_179 ( V_2 , F_284 , V_317 ) ;
return;
V_507:
F_65 ( & V_2 -> V_30 -> V_45 , L_55 ,
V_470 , V_2 -> V_448 ) ;
F_34 ( V_18 ) ;
F_182 ( V_2 , 1 ) ;
}
static void
F_287 ( struct V_1 * V_2 )
{
T_1 V_55 ;
V_55 = F_54 ( V_2 , V_225 ) ;
if ( V_55 == V_516 )
return;
if ( F_55 ( V_2 ) )
return;
F_102 ( V_2 , V_225 , V_516 ) ;
F_58 ( V_2 ) ;
}
void
F_288 ( struct V_1 * V_2 )
{
T_1 V_55 ;
V_2 -> V_215 = 1 ;
if ( F_55 ( V_2 ) )
return;
V_55 = F_54 ( V_2 , V_234 ) ;
if ( V_55 == V_235 ) {
F_102 ( V_2 , V_234 , V_486 ) ;
V_2 -> V_49 |= V_495 ;
F_283 ( V_2 , V_512 , L_56 ) ;
F_104 ( V_2 , 0 ) ;
}
F_102 ( V_2 , V_225 , V_516 ) ;
F_58 ( V_2 ) ;
}
static void
F_93 ( struct V_1 * V_2 )
{
if ( F_55 ( V_2 ) )
return;
F_102 ( V_2 , V_225 , V_226 ) ;
F_283 ( V_2 , V_512 , L_57 ) ;
F_58 ( V_2 ) ;
}
static void
F_179 ( struct V_1 * V_2 ,
T_16 V_112 , int V_517 )
{
if ( F_31 ( V_518 , & V_2 -> V_55 ) )
return;
F_289 ( & V_2 -> V_505 , V_112 ) ;
F_290 ( V_519 , & V_2 -> V_505 ,
F_291 ( V_517 ) ) ;
}
static void
F_188 ( struct V_1 * V_2 )
{
while ( F_150 ( V_273 , & V_2 -> V_55 ) )
F_91 ( 10 ) ;
F_292 ( & V_2 -> V_505 ) ;
}
static void
V_513 ( struct V_503 * V_504 )
{
struct V_1 * V_2 = F_267 ( V_504 ,
struct V_1 , V_505 . V_504 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_224 ;
if ( V_2 -> V_114 != V_104 ) {
V_224 = F_54 ( V_2 , V_225 ) ;
if ( V_2 -> V_509 ++ > V_223 )
F_182 ( V_2 , 0 ) ;
else if ( V_224 != V_226 )
F_179 ( V_2 , V_513 ,
V_317 ) ;
else
goto V_520;
F_283 ( V_2 , V_512 , L_58 ) ;
return;
}
V_520:
if ( F_119 ( V_18 ) ) {
if ( F_117 ( V_2 , V_18 ) )
goto V_322;
F_77 ( V_18 , V_323 ) ;
}
V_322:
F_34 ( V_18 ) ;
V_2 -> V_491 = 0 ;
F_78 ( V_273 , & V_2 -> V_55 ) ;
if ( ! F_277 ( V_2 ) )
F_179 ( V_2 , V_316 ,
V_317 ) ;
}
static int
F_293 ( struct V_1 * V_2 )
{
T_1 V_55 = 0 , V_521 ;
struct V_17 * V_18 = V_2 -> V_18 ;
if ( F_250 ( V_2 ) )
goto V_522;
if ( V_2 -> V_215 )
F_288 ( V_2 ) ;
V_55 = F_54 ( V_2 , V_234 ) ;
if ( V_55 == V_486 ) {
F_287 ( V_2 ) ;
V_2 -> V_215 = 1 ;
} else if ( V_55 == V_487 )
goto V_522;
V_521 = F_54 ( V_2 , V_523 ) ;
if ( V_521 != V_2 -> V_521 ) {
V_2 -> V_521 = V_521 ;
V_2 -> V_491 = 0 ;
if ( V_2 -> V_215 )
goto V_522;
if ( V_2 -> V_251 && V_524 ) {
F_149 ( V_2 ) ;
V_2 -> V_18 -> V_525 = V_302 ;
}
return 0 ;
}
if ( ++ V_2 -> V_491 < V_526 )
return 0 ;
F_288 ( V_2 ) ;
if ( V_524 )
F_78 ( V_527 , & V_2 -> V_55 ) ;
F_37 ( & V_18 -> V_45 , L_59 ) ;
V_522:
V_2 -> V_506 = ( V_55 == V_487 ) ? V_55 :
V_486 ;
if ( V_524 &&
! F_150 ( V_273 , & V_2 -> V_55 ) ) {
F_179 ( V_2 , F_286 , 0 ) ;
F_283 ( V_2 , V_512 , L_60 ) ;
}
return 1 ;
}
static void
V_316 ( struct V_503 * V_504 )
{
struct V_1 * V_2 = F_267 ( V_504 ,
struct V_1 , V_505 . V_504 ) ;
if ( F_31 ( V_273 , & V_2 -> V_55 ) )
goto V_528;
if ( F_293 ( V_2 ) )
return;
if ( V_2 -> V_253 . V_254 )
F_294 ( V_2 ) ;
V_528:
F_179 ( V_2 , V_316 , V_317 ) ;
}
static int F_295 ( struct V_29 * V_30 )
{
struct V_29 * V_529 ;
int V_484 = V_30 -> V_530 ;
while ( V_484 -- > 0 ) {
V_529 = F_296 ( F_297
( V_30 -> V_531 ) , V_30 -> V_531 -> V_532 ,
F_298 ( F_299 ( V_30 -> V_530 ) , V_484 ) ) ;
if ( ! V_529 )
continue;
if ( V_529 -> V_533 != V_319 ) {
F_300 ( V_529 ) ;
return 0 ;
}
F_300 ( V_529 ) ;
}
return 1 ;
}
static int F_301 ( struct V_29 * V_30 )
{
int V_57 , V_534 ;
struct V_1 * V_2 = F_187 ( V_30 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
V_30 -> V_535 = V_536 ;
V_57 = F_162 ( V_30 ) ;
if ( V_57 )
return V_57 ;
F_199 ( V_30 , V_321 ) ;
F_165 ( V_30 ) ;
F_202 ( V_30 ) ;
V_534 = F_295 ( V_30 ) ;
if ( F_55 ( V_2 ) )
return - V_53 ;
if ( V_2 -> V_114 != V_122 && V_534 ) {
V_2 -> V_215 = 1 ;
F_75 ( V_492 , & V_2 -> V_55 ) ;
F_102 ( V_2 , V_234 , V_501 ) ;
F_283 ( V_2 , V_512 , L_50 ) ;
}
F_58 ( V_2 ) ;
V_57 = V_2 -> V_123 -> V_312 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_277 ( V_2 ) ;
F_42 ( V_2 ) ;
if ( F_119 ( V_18 ) ) {
V_57 = F_135 ( V_2 ) ;
if ( V_57 ) {
F_182 ( V_2 , 1 ) ;
F_78 ( V_518 , & V_2 -> V_55 ) ;
F_34 ( V_18 ) ;
return V_57 ;
}
V_57 = F_117 ( V_2 , V_18 ) ;
if ( V_57 )
goto V_322;
F_77 ( V_18 , V_323 ) ;
}
V_322:
F_34 ( V_18 ) ;
return V_57 ;
}
static T_17 F_302 ( struct V_29 * V_30 ,
T_18 V_55 )
{
struct V_1 * V_2 = F_187 ( V_30 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
if ( V_55 == V_537 )
return V_538 ;
if ( V_55 == V_536 )
return V_539 ;
F_75 ( V_518 , & V_2 -> V_55 ) ;
F_32 ( V_18 ) ;
F_292 ( & V_2 -> V_505 ) ;
if ( F_119 ( V_18 ) )
F_134 ( V_2 , V_18 ) ;
F_141 ( V_2 ) ;
F_45 ( V_2 ) ;
F_78 ( V_273 , & V_2 -> V_55 ) ;
F_194 ( V_30 ) ;
F_185 ( V_30 ) ;
return V_540 ;
}
static T_17 F_303 ( struct V_29 * V_30 )
{
return F_301 ( V_30 ) ? V_538 :
V_539 ;
}
static void F_304 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_187 ( V_30 ) ;
F_305 ( V_30 ) ;
if ( F_54 ( V_2 , V_234 ) == V_235 &&
F_122 ( V_518 , & V_2 -> V_55 ) )
F_179 ( V_2 , V_316 ,
V_317 ) ;
}
static int
F_306 ( struct V_1 * V_2 )
{
int V_57 ;
V_57 = F_95 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_90 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_71 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_69 ( V_2 ) ;
V_57 = F_81 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_2 -> V_215 = 0 ;
return V_57 ;
}
static int
F_307 ( struct V_1 * V_2 , T_1 V_31 )
{
return - V_51 ;
}
static int
F_308 ( struct V_1 * V_2 , T_1 V_55 , T_1 V_541 )
{
return - V_51 ;
}
static T_19
F_309 ( struct V_137 * V_45 ,
struct V_542 * V_543 , const char * V_544 , T_20 V_437 )
{
struct V_1 * V_2 = F_310 ( V_45 ) ;
unsigned long V_545 ;
int V_81 = - V_53 ;
if ( ! ( V_2 -> V_178 & V_546 ) )
goto V_229;
if ( ! F_31 ( V_54 , & V_2 -> V_55 ) )
goto V_229;
if ( F_311 ( V_544 , 2 , & V_545 ) )
goto V_229;
if ( ! V_2 -> V_123 -> V_547 ( V_2 , ! ! V_545 ) )
V_81 = V_437 ;
V_229:
return V_81 ;
}
static T_19
F_312 ( struct V_137 * V_45 ,
struct V_542 * V_543 , char * V_544 )
{
struct V_1 * V_2 = F_310 ( V_45 ) ;
int V_548 = 0 ;
if ( V_2 -> V_178 & V_546 )
V_548 = ! ! ( V_2 -> V_49 & V_549 ) ;
return sprintf ( V_544 , L_61 , V_548 ) ;
}
static T_19
F_313 ( struct V_137 * V_45 ,
struct V_542 * V_543 , const char * V_544 , T_20 V_437 )
{
struct V_1 * V_2 = F_310 ( V_45 ) ;
unsigned long V_545 ;
if ( F_311 ( V_544 , 2 , & V_545 ) )
return - V_53 ;
if ( ! ! V_545 != ! ! ( V_2 -> V_49 & V_550 ) )
V_2 -> V_49 ^= V_550 ;
return V_437 ;
}
static T_19
F_314 ( struct V_137 * V_45 ,
struct V_542 * V_543 , char * V_544 )
{
struct V_1 * V_2 = F_310 ( V_45 ) ;
return sprintf ( V_544 , L_61 ,
! ! ( V_2 -> V_49 & V_550 ) ) ;
}
int F_315 ( struct V_17 * V_18 , T_2 V_551 , T_2 V_484 )
{
if ( ! V_166 && ! V_64 ) {
F_254 ( V_18 , L_62 ) ;
return - V_53 ;
}
if ( ( V_484 > V_551 ) || ( V_484 < 2 ) || ! F_316 ( V_484 ) ) {
F_254 ( V_18 , L_63
L_64 , V_551 ) ;
return - V_53 ;
}
return 0 ;
}
int F_317 ( struct V_1 * V_2 , T_2 V_103 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_57 = 0 ;
if ( F_150 ( V_273 , & V_2 -> V_55 ) )
return - V_274 ;
F_32 ( V_18 ) ;
if ( F_119 ( V_18 ) )
F_121 ( V_2 , V_18 ) ;
F_141 ( V_2 ) ;
F_45 ( V_2 ) ;
if ( F_35 ( V_2 , V_103 ) ) {
F_254 ( V_18 , L_65 ) ;
F_39 ( V_2 ) ;
}
if ( F_119 ( V_18 ) ) {
V_57 = F_135 ( V_2 ) ;
if ( V_57 )
goto V_322;
V_57 = F_109 ( V_2 , V_18 ) ;
if ( V_57 )
goto V_322;
F_77 ( V_18 , V_323 ) ;
}
V_322:
F_34 ( V_18 ) ;
F_78 ( V_273 , & V_2 -> V_55 ) ;
return V_57 ;
}
static int
F_318 ( struct V_1 * V_2 ,
T_21 V_374 , T_20 V_14 )
{
T_20 V_552 = 4 ;
if ( ! ( V_2 -> V_49 & V_550 ) )
return - V_41 ;
if ( V_374 < V_553 ) {
if ( F_319 ( V_374 , V_554 ,
V_555 ) )
V_552 = 8 ;
else
return - V_53 ;
}
if ( ( V_14 != V_552 ) || ( V_374 & ( V_552 - 1 ) ) )
return - V_53 ;
return 0 ;
}
static T_19
F_320 ( struct V_556 * V_557 , struct V_558 * V_559 ,
struct V_560 * V_543 ,
char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
T_1 V_103 ;
T_11 V_561 ;
int V_81 ;
V_81 = F_318 ( V_2 , V_374 , V_14 ) ;
if ( V_81 != 0 )
return V_81 ;
if ( F_319 ( V_374 , V_554 , V_555 ) ) {
F_321 ( V_2 , V_374 , & V_561 ) ;
memcpy ( V_544 , & V_561 , V_14 ) ;
} else {
V_103 = F_54 ( V_2 , V_374 ) ;
memcpy ( V_544 , & V_103 , V_14 ) ;
}
return V_14 ;
}
static T_19
F_322 ( struct V_556 * V_557 , struct V_558 * V_559 ,
struct V_560 * V_543 ,
char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
T_1 V_103 ;
T_11 V_561 ;
int V_81 ;
V_81 = F_318 ( V_2 , V_374 , V_14 ) ;
if ( V_81 != 0 )
return V_81 ;
if ( F_319 ( V_374 , V_554 , V_555 ) ) {
memcpy ( & V_561 , V_544 , V_14 ) ;
F_323 ( V_2 , V_374 , V_561 ) ;
} else {
memcpy ( & V_103 , V_544 , V_14 ) ;
F_102 ( V_2 , V_374 , V_103 ) ;
}
return V_14 ;
}
static int
F_324 ( struct V_1 * V_2 ,
T_21 V_374 , T_20 V_14 )
{
if ( ! ( V_2 -> V_49 & V_550 ) )
return - V_41 ;
if ( ( V_14 != 8 ) || ( V_374 & 0x7 ) )
return - V_41 ;
return 0 ;
}
static T_19
F_325 ( struct V_556 * V_557 , struct V_558 * V_559 ,
struct V_560 * V_543 ,
char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
T_11 V_103 ;
int V_81 ;
V_81 = F_324 ( V_2 , V_374 , V_14 ) ;
if ( V_81 != 0 )
return V_81 ;
if ( F_326 ( V_2 , V_374 , & V_103 ) )
return - V_41 ;
memcpy ( V_544 , & V_103 , V_14 ) ;
return V_14 ;
}
static T_19
F_327 ( struct V_556 * V_557 , struct V_558 * V_559 ,
struct V_560 * V_543 ,
char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
T_11 V_103 ;
int V_81 ;
V_81 = F_324 ( V_2 , V_374 , V_14 ) ;
if ( V_81 != 0 )
return V_81 ;
memcpy ( & V_103 , V_544 , V_14 ) ;
if ( F_328 ( V_2 , V_374 , V_103 ) )
return - V_41 ;
return V_14 ;
}
static int
F_329 ( struct V_1 * V_2 ,
struct V_562 * V_563 , int V_13 )
{
T_2 V_564 , V_565 , V_566 ;
T_2 V_567 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_564 = V_563 [ V_36 ] . V_68 ;
V_567 = V_563 [ V_36 ] . V_221 ;
if ( V_564 >= V_83
|| V_567 >= V_83 )
return V_93 ;
if ( V_2 -> V_84 [ V_564 ] . type != V_110 )
return V_93 ;
if ( V_2 -> V_84 [ V_567 ] . type != V_110 )
return V_93 ;
V_565 = V_2 -> V_84 [ V_564 ] . V_95 ;
V_566 = V_2 -> V_84 [ V_567 ] . V_95 ;
if ( V_565 != V_566 )
return V_93 ;
}
return 0 ;
}
static T_19
F_330 ( struct V_556 * V_557 , struct V_558 * V_559 ,
struct V_560 * V_543 , char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
struct V_562 * V_563 ;
T_1 V_92 , V_568 , V_68 ;
int V_13 , V_569 , V_36 , V_81 ;
V_13 = V_14 / sizeof( struct V_562 ) ;
V_569 = V_14 % sizeof( struct V_562 ) ;
if ( V_569 )
return V_93 ;
V_563 = (struct V_562 * ) V_544 ;
V_81 = F_329 ( V_2 , V_563 , V_13 ) ;
if ( V_81 )
return V_81 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_563 [ V_36 ] . V_68 ;
V_568 = ! ! V_563 [ V_36 ] . V_568 ;
V_92 = V_2 -> V_84 [ V_68 ] . V_95 ;
V_81 = F_89 ( V_2 , V_92 ,
V_568 , V_68 ) ;
if ( V_81 )
return V_81 ;
}
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_563 [ V_36 ] . V_68 ;
V_92 = V_2 -> V_84 [ V_68 ] . V_95 ;
V_2 -> V_84 [ V_68 ] . V_220 = ! ! V_563 [ V_36 ] . V_568 ;
V_2 -> V_84 [ V_68 ] . V_221 = V_92 ;
}
return V_14 ;
}
static T_19
F_331 ( struct V_556 * V_557 , struct V_558 * V_559 ,
struct V_560 * V_543 , char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
struct V_562 V_563 [ V_83 ] ;
int V_36 ;
if ( V_14 != sizeof( V_563 ) )
return V_93 ;
for ( V_36 = 0 ; V_36 < V_83 ; V_36 ++ ) {
if ( V_2 -> V_84 [ V_36 ] . type != V_110 )
continue;
V_563 [ V_36 ] . V_568 = V_2 -> V_84 [ V_36 ] . V_220 ;
V_563 [ V_36 ] . V_221 = 0 ;
V_563 [ V_36 ] . V_68 = V_36 ;
}
memcpy ( V_544 , & V_563 , V_14 ) ;
return V_14 ;
}
static int
F_332 ( struct V_1 * V_2 ,
struct V_182 * V_183 , int V_13 )
{
T_1 V_114 ;
T_2 V_68 ;
int V_36 ;
V_114 = F_57 ( V_2 -> V_67 -> V_78 + V_106 ) ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_183 [ V_36 ] . V_68 ;
if ( V_68 >= V_83 )
return V_93 ;
if ( V_2 -> V_114 == V_104 )
if ( V_2 -> V_84 [ V_68 ] . type != V_110 )
return V_93 ;
switch ( V_183 [ V_36 ] . V_114 ) {
case V_216 :
if ( F_60 ( V_114 , V_68 ) !=
V_122 ) {
if ( V_183 [ V_36 ] . V_193 != 0 )
return V_93 ;
if ( V_183 [ V_36 ] . V_194 != 1 )
return V_93 ;
if ( V_183 [ V_36 ] . V_195 != 1 )
return V_93 ;
}
break;
case V_217 :
if ( ! F_333 ( V_183 [ V_36 ] . V_186 ) )
return V_93 ;
if ( ! V_183 [ V_36 ] . V_570 )
return V_93 ;
break;
case V_571 :
if ( ! V_183 [ V_36 ] . V_570 )
return V_93 ;
break;
default:
return V_93 ;
}
}
return 0 ;
}
static T_19
F_334 ( struct V_556 * V_556 , struct V_558 * V_559 ,
struct V_560 * V_543 , char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
struct V_182 * V_183 ;
struct V_85 * V_214 ;
int V_13 , V_569 , V_36 , V_81 ;
T_2 V_68 , V_114 = 0 ;
V_13 = V_14 / sizeof( struct V_182 ) ;
V_569 = V_14 % sizeof( struct V_182 ) ;
if ( V_569 )
return V_93 ;
V_183 = (struct V_182 * ) V_544 ;
V_81 = F_332 ( V_2 , V_183 , V_13 ) ;
if ( V_81 )
return V_81 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
if ( V_2 -> V_114 == V_104 )
if ( F_85 ( V_2 , & V_183 [ V_36 ] ) )
return V_93 ;
if ( V_2 -> V_67 -> V_68 != V_183 [ V_36 ] . V_68 )
continue;
V_114 = V_183 [ V_36 ] . V_114 ;
F_82 ( V_2 , & V_183 [ V_36 ] ) ;
V_183 [ V_36 ] . V_114 = V_114 ;
V_183 [ V_36 ] . V_68 = V_2 -> V_67 -> V_68 ;
switch ( V_183 [ V_36 ] . V_114 ) {
case V_216 :
F_79 ( V_2 , & V_183 [ V_36 ] ) ;
break;
case V_217 :
F_73 ( V_2 , & V_183 [ V_36 ] ) ;
break;
case V_571 :
V_183 [ V_36 ] . V_186 = 0 ;
F_73 ( V_2 , & V_183 [ V_36 ] ) ;
break;
}
}
if ( V_2 -> V_114 != V_104 )
goto V_259;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_183 [ V_36 ] . V_68 ;
V_214 = & V_2 -> V_84 [ V_68 ] ;
switch ( V_183 [ V_36 ] . V_114 ) {
case V_216 :
V_214 -> V_195 = V_183 [ V_36 ] . V_195 ;
V_214 -> V_194 = V_183 [ V_36 ] . V_194 ;
V_214 -> V_208 = V_183 [ V_36 ] . V_208 ;
V_214 -> V_193 = V_183 [ V_36 ] . V_193 ;
V_214 -> V_184 = V_183 [ V_36 ] . V_184 ;
break;
case V_217 :
V_214 -> V_187 = V_183 [ V_36 ] . V_186 ;
break;
case V_571 :
V_214 -> V_187 = 0 ;
break;
}
}
V_259:
return V_14 ;
}
static T_19
F_335 ( struct V_556 * V_556 , struct V_558 * V_559 ,
struct V_560 * V_543 , char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
struct V_182 V_183 [ V_83 ] ;
T_2 V_36 ;
if ( V_14 != sizeof( V_183 ) )
return V_93 ;
for ( V_36 = 0 ; V_36 < V_83 ; V_36 ++ ) {
if ( V_2 -> V_84 [ V_36 ] . type != V_110 )
continue;
V_183 [ V_36 ] . V_68 = V_36 ;
if ( F_82 ( V_2 , & V_183 [ V_36 ] ) )
return V_93 ;
}
memcpy ( V_544 , & V_183 , V_14 ) ;
return V_14 ;
}
static int
F_336 ( struct V_1 * V_2 ,
struct V_572 * V_573 , int V_13 )
{
T_2 V_68 , V_36 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_573 [ V_36 ] . V_68 ;
if ( V_68 >= V_83 )
return V_93 ;
if ( V_2 -> V_84 [ V_68 ] . type != V_110 )
return V_93 ;
if ( ! F_337 ( V_573 [ V_36 ] . V_97 ) ||
! F_337 ( V_573 [ V_36 ] . V_99 ) )
return V_93 ;
}
return 0 ;
}
static T_19
F_338 ( struct V_556 * V_556 , struct V_558 * V_559 ,
struct V_560 * V_543 , char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
struct V_171 V_172 ;
struct V_572 * V_573 ;
int V_36 , V_13 , V_569 , V_81 ;
T_2 V_68 ;
V_13 = V_14 / sizeof( struct V_572 ) ;
V_569 = V_14 % sizeof( struct V_572 ) ;
if ( V_569 )
return V_93 ;
V_573 = (struct V_572 * ) V_544 ;
V_81 = F_336 ( V_2 , V_573 , V_13 ) ;
if ( V_81 )
return V_81 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_573 [ V_36 ] . V_68 ;
V_81 = F_72 ( V_2 , & V_172 , V_68 ) ;
if ( V_81 )
return V_81 ;
V_172 . V_68 = V_68 ;
V_172 . V_218 = V_573 [ V_36 ] . V_97 ;
V_172 . V_219 = V_573 [ V_36 ] . V_99 ;
V_81 = F_88 ( V_2 , & V_172 ) ;
if ( V_81 )
return V_81 ;
V_2 -> V_84 [ V_36 ] . V_97 = V_172 . V_218 ;
V_2 -> V_84 [ V_36 ] . V_99 = V_172 . V_219 ;
}
return V_14 ;
}
static T_19
F_339 ( struct V_556 * V_556 , struct V_558 * V_559 ,
struct V_560 * V_543 , char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
struct V_171 V_172 ;
struct V_572 V_573 [ V_83 ] ;
int V_36 , V_81 ;
if ( V_14 != sizeof( V_573 ) )
return V_93 ;
for ( V_36 = 0 ; V_36 < V_83 ; V_36 ++ ) {
if ( V_2 -> V_84 [ V_36 ] . type != V_110 )
continue;
V_81 = F_72 ( V_2 , & V_172 , V_36 ) ;
if ( V_81 )
return V_81 ;
V_573 [ V_36 ] . V_68 = V_36 ;
V_573 [ V_36 ] . V_114 = ( T_2 ) V_172 . V_114 ;
V_573 [ V_36 ] . V_574 = V_172 . V_174 ;
V_573 [ V_36 ] . V_575 = V_172 . V_178 ;
V_573 [ V_36 ] . V_97 = V_172 . V_218 ;
V_573 [ V_36 ] . V_99 = V_172 . V_219 ;
V_573 [ V_36 ] . V_576 = V_172 . V_176 ;
V_573 [ V_36 ] . V_577 = V_172 . V_177 ;
}
memcpy ( V_544 , & V_573 , V_14 ) ;
return V_14 ;
}
static T_19
F_340 ( struct V_556 * V_556 , struct V_558 * V_559 ,
struct V_560 * V_543 , char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
struct V_578 V_579 ;
int V_81 ;
if ( V_14 != sizeof( struct V_578 ) )
return V_93 ;
if ( V_374 >= V_83 )
return V_93 ;
memset ( & V_579 , 0 , V_14 ) ;
V_81 = F_341 ( V_2 , V_374 , V_580 ,
& V_579 . V_581 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_341 ( V_2 , V_374 , V_582 ,
& V_579 . V_583 ) ;
if ( V_81 )
return V_81 ;
memcpy ( V_544 , & V_579 , V_14 ) ;
return V_14 ;
}
static T_19
F_342 ( struct V_556 * V_556 , struct V_558 * V_559 ,
struct V_560 * V_543 , char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
struct V_578 V_584 ;
int V_81 ;
if ( V_14 != sizeof( struct V_578 ) )
return V_93 ;
if ( V_374 >= V_89 )
return V_93 ;
memset ( & V_584 , 0 , V_14 ) ;
V_81 = F_343 ( V_2 , V_374 , V_580 ,
& V_584 . V_581 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_343 ( V_2 , V_374 , V_582 ,
& V_584 . V_583 ) ;
if ( V_81 )
return V_81 ;
memcpy ( V_544 , & V_584 , V_14 ) ;
return V_14 ;
}
static T_19
F_344 ( struct V_556 * V_556 , struct V_558 * V_559 ,
struct V_560 * V_543 , char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
int V_81 ;
if ( V_374 >= V_89 )
return V_93 ;
V_81 = F_345 ( V_2 , V_585 , V_374 ,
V_580 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_345 ( V_2 , V_585 , V_374 ,
V_582 ) ;
if ( V_81 )
return V_81 ;
return V_14 ;
}
static T_19
F_346 ( struct V_556 * V_556 , struct V_558 * V_559 ,
struct V_560 * V_543 , char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
int V_81 ;
if ( V_374 >= V_83 )
return V_93 ;
V_81 = F_345 ( V_2 , V_586 , V_374 ,
V_580 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_345 ( V_2 , V_586 , V_374 ,
V_582 ) ;
if ( V_81 )
return V_81 ;
return V_14 ;
}
static T_19
F_347 ( struct V_556 * V_556 , struct V_558 * V_559 ,
struct V_560 * V_543 , char * V_544 , T_21 V_374 , T_20 V_14 )
{
struct V_137 * V_45 = F_267 ( V_559 , struct V_137 , V_559 ) ;
struct V_1 * V_2 = F_310 ( V_45 ) ;
struct V_587 V_588 [ V_83 ] ;
struct V_79 * V_80 ;
int V_36 , V_81 ;
if ( V_14 != sizeof( V_588 ) )
return V_93 ;
V_80 = F_51 ( V_83 , sizeof( * V_80 ) , V_16 ) ;
if ( ! V_80 )
return - V_21 ;
V_81 = F_52 ( V_2 , V_80 ) ;
if ( V_81 ) {
F_9 ( V_80 ) ;
return V_81 ;
}
for ( V_36 = 0 ; V_36 < V_83 ; V_36 ++ ) {
V_588 [ V_36 ] . V_68 = V_80 [ V_36 ] . V_92 ;
V_588 [ V_36 ] . V_589 = V_80 [ V_36 ] . type ;
V_588 [ V_36 ] . V_574 = V_80 [ V_36 ] . V_96 ;
V_588 [ V_36 ] . V_97 = V_80 [ V_36 ] . V_98 ;
V_588 [ V_36 ] . V_99 = V_80 [ V_36 ] . V_100 ;
memcpy ( & V_588 [ V_36 ] . V_590 , & V_80 [ V_36 ] . V_591 , V_40 ) ;
}
memcpy ( V_544 , & V_588 , V_14 ) ;
F_9 ( V_80 ) ;
return V_14 ;
}
static void
F_138 ( struct V_1 * V_2 )
{
struct V_137 * V_45 = & V_2 -> V_30 -> V_45 ;
if ( V_2 -> V_178 & V_546 )
if ( F_348 ( V_45 , & V_592 ) )
F_28 ( V_45 ,
L_66 ) ;
}
static void
F_142 ( struct V_1 * V_2 )
{
struct V_137 * V_45 = & V_2 -> V_30 -> V_45 ;
if ( V_2 -> V_178 & V_546 )
F_349 ( V_45 , & V_592 ) ;
}
static void
F_181 ( struct V_1 * V_2 )
{
struct V_137 * V_45 = & V_2 -> V_30 -> V_45 ;
if ( F_350 ( V_45 , & V_593 ) )
F_37 ( V_45 , L_67 ) ;
if ( V_2 -> V_114 == V_122 )
return;
if ( F_348 ( V_45 , & V_594 ) )
F_37 ( V_45 , L_68 ) ;
if ( F_350 ( V_45 , & V_595 ) )
F_37 ( V_45 , L_69 ) ;
if ( F_350 ( V_45 , & V_596 ) )
F_37 ( V_45 , L_70 ) ;
if ( F_350 ( V_45 , & V_597 ) )
F_37 ( V_45 , L_71 ) ;
if ( ! ( V_2 -> V_49 & V_152 ) )
return;
if ( F_350 ( V_45 , & V_598 ) )
F_37 ( V_45 , L_72 ) ;
if ( V_2 -> V_114 != V_104 )
return;
if ( F_350 ( V_45 , & V_599 ) )
F_37 ( V_45 , L_73 ) ;
if ( F_350 ( V_45 , & V_600 ) )
F_37 ( V_45 , L_74 ) ;
if ( F_350 ( V_45 , & V_601 ) )
F_37 ( V_45 , L_75 ) ;
}
static void
F_191 ( struct V_1 * V_2 )
{
struct V_137 * V_45 = & V_2 -> V_30 -> V_45 ;
F_351 ( V_45 , & V_593 ) ;
if ( V_2 -> V_114 == V_122 )
return;
F_349 ( V_45 , & V_594 ) ;
F_351 ( V_45 , & V_595 ) ;
F_351 ( V_45 , & V_596 ) ;
F_351 ( V_45 , & V_597 ) ;
if ( ! ( V_2 -> V_49 & V_152 ) )
return;
F_351 ( V_45 , & V_598 ) ;
if ( V_2 -> V_114 != V_104 )
return;
F_351 ( V_45 , & V_599 ) ;
F_351 ( V_45 , & V_600 ) ;
F_351 ( V_45 , & V_601 ) ;
}
static void
F_352 ( struct V_1 * V_2 ,
struct V_17 * V_45 , unsigned long V_602 )
{
struct V_603 * V_604 ;
V_604 = F_353 ( V_45 ) ;
if ( ! V_604 )
return;
F_354 (indev) {
switch ( V_602 ) {
case V_323 :
F_355 ( V_2 ,
V_605 -> V_606 , V_607 ) ;
break;
case V_190 :
F_355 ( V_2 ,
V_605 -> V_606 , V_608 ) ;
break;
default:
break;
}
} F_356 ( V_604 ) ;
F_357 ( V_604 ) ;
}
static void
F_77 ( struct V_17 * V_18 , unsigned long V_602 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_17 * V_45 ;
T_5 V_188 ;
F_352 ( V_2 , V_18 , V_602 ) ;
F_358 (vid, adapter->vlans, VLAN_N_VID) {
V_45 = F_359 ( V_18 , V_188 ) ;
if ( ! V_45 )
continue;
F_352 ( V_2 , V_45 , V_602 ) ;
}
}
static int F_360 ( struct V_609 * V_610 ,
unsigned long V_602 , void * V_611 )
{
struct V_1 * V_2 ;
struct V_17 * V_45 = (struct V_17 * ) V_611 ;
V_612:
if ( V_45 == NULL )
goto V_322;
if ( V_45 -> V_613 & V_614 ) {
V_45 = F_361 ( V_45 ) ;
goto V_612;
}
if ( ! F_362 ( V_45 ) )
goto V_322;
V_2 = F_30 ( V_45 ) ;
if ( ! V_2 )
goto V_322;
if ( ! F_31 ( V_54 , & V_2 -> V_55 ) )
goto V_322;
F_352 ( V_2 , V_45 , V_602 ) ;
V_322:
return V_615 ;
}
static int
F_363 ( struct V_609 * V_610 ,
unsigned long V_602 , void * V_611 )
{
struct V_1 * V_2 ;
struct V_17 * V_45 ;
struct V_616 * V_605 = (struct V_616 * ) V_611 ;
V_45 = V_605 -> V_617 ? V_605 -> V_617 -> V_45 : NULL ;
V_612:
if ( V_45 == NULL )
goto V_322;
if ( V_45 -> V_613 & V_614 ) {
V_45 = F_361 ( V_45 ) ;
goto V_612;
}
if ( ! F_362 ( V_45 ) )
goto V_322;
V_2 = F_30 ( V_45 ) ;
if ( ! V_2 )
goto V_322;
if ( ! F_31 ( V_54 , & V_2 -> V_55 ) )
goto V_322;
switch ( V_602 ) {
case V_323 :
F_355 ( V_2 , V_605 -> V_606 , V_607 ) ;
break;
case V_190 :
F_355 ( V_2 , V_605 -> V_606 , V_608 ) ;
break;
default:
break;
}
V_322:
return V_615 ;
}
static void
F_77 ( struct V_17 * V_45 , unsigned long V_602 )
{ }
static int T_22 F_364 ( void )
{
int V_81 ;
F_365 ( V_618 L_76 , V_619 ) ;
V_519 = F_366 ( L_77 ) ;
if ( V_519 == NULL ) {
F_365 ( V_620 L_78 ) ;
return - V_21 ;
}
#ifdef F_367
F_368 ( & V_621 ) ;
F_369 ( & V_622 ) ;
#endif
V_81 = F_370 ( & V_623 ) ;
if ( V_81 ) {
#ifdef F_367
F_371 ( & V_622 ) ;
F_372 ( & V_621 ) ;
#endif
F_373 ( V_519 ) ;
}
return V_81 ;
}
static void T_23 F_374 ( void )
{
F_375 ( & V_623 ) ;
#ifdef F_367
F_371 ( & V_622 ) ;
F_372 ( & V_621 ) ;
#endif
F_373 ( V_519 ) ;
}
