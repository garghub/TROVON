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
T_1 V_143 , V_144 , V_145 , V_146 ;
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_147 * V_148 = & V_2 -> V_67 -> V_148 ;
V_146 = V_2 -> V_149 ;
V_143 = F_54 ( V_2 , V_150 ) ;
V_144 = F_54 ( V_2 , V_151 ) ;
V_145 = F_54 ( V_2 , V_152 ) ;
V_2 -> V_149 = F_70 ( V_143 , V_144 , V_145 ) ;
if ( V_2 -> V_114 != V_122 ) {
if ( V_148 -> V_153 == NULL ||
V_2 -> V_149 > V_146 ) {
if ( V_148 -> V_153 )
F_71 ( V_148 -> V_153 ) ;
if ( ! F_72 ( V_2 ) )
F_37 ( & V_30 -> V_45 ,
L_10 ) ;
}
}
F_37 ( & V_30 -> V_45 , L_11 ,
V_143 , V_144 , V_145 ) ;
if ( V_2 -> V_67 -> V_154 == V_155 ) {
if ( V_2 -> V_49 & V_156 ) {
V_2 -> V_157 = V_158 ;
V_2 -> V_159 = V_160 ;
} else {
V_2 -> V_157 = V_161 ;
V_2 -> V_159 = V_162 ;
}
V_2 -> V_163 = V_164 ;
V_2 -> V_165 = V_164 ;
} else if ( V_2 -> V_67 -> V_154 == V_166 ) {
V_2 -> V_157 = V_167 ;
V_2 -> V_163 = V_168 ;
V_2 -> V_165 = V_168 ;
V_2 -> V_159 = V_169 ;
}
V_2 -> V_60 = ! ! V_170 ;
V_2 -> V_171 = V_172 ;
V_2 -> V_173 = V_174 ;
}
static int
F_73 ( struct V_1 * V_2 )
{
int V_57 ;
struct V_175 V_176 ;
V_57 = F_74 ( V_2 , & V_176 , V_2 -> V_67 -> V_68 ) ;
if ( V_57 )
return V_57 ;
V_2 -> V_177 = ( T_2 ) V_176 . V_178 ;
V_2 -> V_179 = V_176 . V_179 ;
V_2 -> V_180 = V_176 . V_180 ;
V_2 -> V_181 = V_176 . V_181 ;
V_2 -> V_182 = V_176 . V_182 ;
V_2 -> V_183 = V_176 . V_183 ;
V_2 -> V_184 = V_176 . V_184 ;
if ( V_2 -> V_182 & V_185 )
V_2 -> V_49 |= V_156 ;
else
V_2 -> V_49 &= ~ V_156 ;
return V_57 ;
}
static void
F_75 ( struct V_1 * V_2 ,
struct V_186 * V_187 )
{
if ( V_187 -> V_188 )
V_2 -> V_49 &= ~ V_189 ;
else
V_2 -> V_49 |= V_189 ;
if ( V_187 -> V_190 )
V_2 -> V_191 = V_187 -> V_190 ;
else
V_2 -> V_191 = 0 ;
}
static int
F_76 ( struct V_17 * V_18 , T_5 V_192 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
F_77 ( V_192 , V_2 -> V_193 ) ;
return 0 ;
}
static int
F_78 ( struct V_17 * V_18 , T_5 V_192 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
F_79 ( V_18 , V_194 ) ;
F_80 ( V_192 , V_2 -> V_193 ) ;
return 0 ;
}
static void
F_81 ( struct V_1 * V_2 ,
struct V_186 * V_187 )
{
V_2 -> V_49 &= ~ ( V_195 | V_50 |
V_196 ) ;
if ( V_187 -> V_197 )
V_2 -> V_49 |= V_195 ;
if ( ! V_187 -> V_198 )
V_2 -> V_49 |= V_50 ;
if ( ! V_187 -> V_199 )
V_2 -> V_49 |= V_196 ;
F_82 ( V_2 , V_187 ) ;
}
static int
F_83 ( struct V_1 * V_2 )
{
struct V_186 V_187 ;
if ( ! ( V_2 -> V_49 & V_156 ) )
return 0 ;
V_187 . V_68 = V_2 -> V_67 -> V_68 ;
if ( F_84 ( V_2 , & V_187 ) )
return - V_41 ;
F_75 ( V_2 , & V_187 ) ;
F_81 ( V_2 , & V_187 ) ;
return 0 ;
}
static void
F_82 ( struct V_1 * V_2 ,
struct V_186 * V_187 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
T_6 V_200 , V_201 ;
V_200 = ( V_202 | V_203 | V_204 |
V_205 | V_206 ) ;
V_201 = ( V_202 | V_203 |
V_205 | V_207 ) ;
if ( V_2 -> V_182 & V_208 ) {
V_200 |= ( V_209 | V_210 ) ;
V_201 |= ( V_209 | V_210 ) ;
}
if ( V_18 -> V_200 & V_211 )
V_200 |= V_211 ;
if ( V_187 -> V_212 & V_213 ) {
V_18 -> V_200 |= V_200 ;
if ( ! ( V_187 -> V_212 & V_214 ) )
V_18 -> V_200 &= ~ V_209 ;
if ( ! ( V_187 -> V_212 & V_215 ) )
V_18 -> V_200 &= ~ V_210 ;
} else {
V_18 -> V_200 &= ~ V_200 ;
}
V_18 -> V_201 = ( V_200 & V_201 ) ;
}
static int
F_85 ( struct V_1 * V_2 )
{
void T_3 * V_105 ;
T_1 V_114 , V_115 ;
int V_57 = 0 ;
V_57 = F_73 ( V_2 ) ;
if ( V_57 )
return V_57 ;
if ( V_2 -> V_49 & V_216 )
return 0 ;
V_105 = V_2 -> V_67 -> V_78 + V_106 ;
V_114 = F_57 ( V_105 ) ;
V_115 = F_60 ( V_114 , V_2 -> V_67 -> V_68 ) ;
if ( V_114 == V_121 )
V_115 = V_104 ;
else
V_115 = F_60 ( V_114 , V_2 -> V_67 -> V_68 ) ;
if ( V_2 -> V_49 & V_156 ) {
if ( V_115 == V_104 ) {
V_2 -> V_114 = V_104 ;
V_57 = F_50 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_53 ( V_2 ) ;
F_37 ( & V_2 -> V_30 -> V_45 ,
L_12 ,
V_2 -> V_116 ) ;
} else if ( V_115 == V_217 ) {
V_2 -> V_114 = V_217 ;
F_37 ( & V_2 -> V_30 -> V_45 ,
L_13 ,
V_2 -> V_116 ) ;
}
}
V_2 -> V_49 |= V_216 ;
return V_57 ;
}
static int
F_86 ( struct V_1 * V_2 )
{
struct V_186 V_187 ;
struct V_85 * V_218 ;
T_2 V_36 ;
if ( V_2 -> V_219 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_83 ; V_36 ++ ) {
if ( V_2 -> V_84 [ V_36 ] . type != V_110 )
continue;
memset ( & V_187 , 0 , sizeof( struct V_186 ) ) ;
V_187 . V_68 = V_36 ;
V_187 . V_212 = V_213 ;
V_187 . V_198 = V_213 ;
V_187 . V_199 = V_213 ;
if ( V_2 -> V_182 & V_208 )
V_187 . V_212 |= ( V_214 | V_215 ) ;
if ( F_87 ( V_2 , & V_187 ) )
return - V_41 ;
V_218 = & V_2 -> V_84 [ V_36 ] ;
V_218 -> V_191 = V_187 . V_190 ;
V_218 -> V_198 = V_187 . V_198 ;
V_218 -> V_197 = V_187 . V_197 ;
V_218 -> V_188 = V_187 . V_188 ;
V_218 -> V_199 = V_187 . V_199 ;
V_218 -> V_212 = V_187 . V_212 ;
}
return 0 ;
}
static int
F_88 ( struct V_1 * V_2 ,
struct V_85 * V_218 , int V_68 )
{
struct V_186 V_187 ;
V_187 . V_114 = V_220 ;
V_187 . V_68 = V_68 ;
V_187 . V_190 = V_218 -> V_191 ;
V_187 . V_198 = V_218 -> V_198 ;
V_187 . V_188 = V_218 -> V_188 ;
V_187 . V_197 = V_218 -> V_197 ;
V_187 . V_212 = V_218 -> V_212 ;
V_187 . V_199 = V_218 -> V_199 ;
if ( F_87 ( V_2 , & V_187 ) )
return - V_41 ;
V_187 . V_114 = V_221 ;
if ( F_87 ( V_2 , & V_187 ) )
return - V_41 ;
return 0 ;
}
static int
F_89 ( struct V_1 * V_2 )
{
int V_36 , V_57 ;
struct V_85 * V_218 ;
struct V_175 V_176 ;
if ( ! V_2 -> V_219 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_83 ; V_36 ++ ) {
V_218 = & V_2 -> V_84 [ V_36 ] ;
if ( V_218 -> type != V_110 )
continue;
V_57 = F_74 ( V_2 , & V_176 , V_36 ) ;
if ( V_57 )
return V_57 ;
V_176 . V_222 = V_218 -> V_97 ;
V_176 . V_223 = V_218 -> V_99 ;
V_57 = F_90 ( V_2 , & V_176 ) ;
if ( V_57 )
return V_57 ;
if ( V_218 -> V_224 ) {
V_57 = F_91 ( V_2 ,
V_218 -> V_225 , 1 , V_36 ) ;
if ( V_57 )
return V_57 ;
}
V_57 = F_88 ( V_2 , V_218 , V_36 ) ;
if ( V_57 )
return V_57 ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
T_2 V_226 = V_227 ;
T_1 V_228 ;
if ( V_2 -> V_114 == V_104 )
return 0 ;
V_228 = F_54 ( V_2 , V_229 ) ;
while ( V_228 != V_230 && -- V_226 ) {
F_93 ( 1000 ) ;
V_228 = F_54 ( V_2 , V_229 ) ;
}
if ( ! V_226 ) {
F_65 ( & V_2 -> V_30 -> V_45 ,
L_14 ) ;
return - V_41 ;
}
return 0 ;
}
static int
F_94 ( struct V_1 * V_2 )
{
int V_57 ;
if ( ! ( V_2 -> V_49 & V_156 ) ||
V_2 -> V_114 != V_104 )
return 0 ;
V_57 = F_86 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_89 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_95 ( V_2 ) ;
return V_57 ;
}
static int
F_96 ( struct V_1 * V_2 )
{
int V_57 ;
V_57 = F_97 ( V_2 ) ;
if ( V_57 < 0 )
return V_57 ;
else if ( ! V_57 )
goto V_231;
if ( V_232 )
F_98 ( V_2 ) ;
else {
V_57 = F_99 ( V_2 ) ;
if ( V_57 )
goto V_233;
V_2 -> V_234 = V_235 ;
}
V_57 = F_100 ( V_2 ) ;
if ( V_57 == 0 )
goto V_231;
V_57 = F_101 ( V_2 ) ;
if ( V_57 )
goto V_233;
V_57 = F_102 ( V_2 ) ;
if ( V_57 )
goto V_233;
F_103 ( V_2 ) ;
F_104 ( V_2 , V_236 , V_237 ) ;
V_231:
V_57 = F_105 ( V_2 ) ;
if ( V_57 )
goto V_233;
F_104 ( V_2 , V_238 , V_239 ) ;
F_106 ( V_2 , 1 ) ;
V_57 = F_85 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_2 -> V_30 -> V_45 ,
L_15 ) ;
goto V_233;
}
V_57 = F_94 ( V_2 ) ;
if ( V_57 )
goto V_233;
F_69 ( V_2 ) ;
V_2 -> V_219 = 0 ;
F_103 ( V_2 ) ;
return 0 ;
V_233:
F_104 ( V_2 , V_238 , V_240 ) ;
F_65 ( & V_2 -> V_30 -> V_45 , L_16 ) ;
F_103 ( V_2 ) ;
return V_57 ;
}
static int
F_107 ( struct V_1 * V_2 )
{
T_7 V_241 ;
struct V_7 * V_8 ;
int V_57 , V_19 ;
unsigned long V_49 = 0 ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_11 * V_12 = V_2 -> V_12 ;
if ( V_2 -> V_242 == V_243 ) {
V_241 = V_244 ;
if ( ! F_5 ( V_2 ) )
V_49 |= V_245 ;
} else {
if ( V_2 -> V_49 & V_59 )
V_241 = V_246 ;
else if ( V_2 -> V_49 & V_58 )
V_241 = V_247 ;
else {
V_49 |= V_245 ;
V_241 = V_248 ;
}
}
V_2 -> V_70 = V_18 -> V_70 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_12 -> V_15 [ V_19 ] ;
sprintf ( V_8 -> V_132 , L_17 , V_18 -> V_132 , V_19 ) ;
V_57 = F_108 ( V_8 -> V_70 , V_241 ,
V_49 , V_8 -> V_132 , V_8 ) ;
if ( V_57 )
return V_57 ;
}
return 0 ;
}
static void
F_109 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_7 * V_8 ;
struct V_11 * V_12 = V_2 -> V_12 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_12 -> V_15 [ V_19 ] ;
F_110 ( V_8 -> V_70 , V_8 ) ;
}
}
static int
F_111 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_19 ;
struct V_249 * V_250 ;
if ( V_2 -> V_26 != V_27 )
return - V_41 ;
if ( F_31 ( V_54 , & V_2 -> V_55 ) )
return 0 ;
if ( F_83 ( V_2 ) )
return - V_41 ;
if ( F_112 ( V_2 ) )
return - V_41 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_173 ; V_19 ++ ) {
V_250 = & V_2 -> V_12 -> V_251 [ V_19 ] ;
F_113 ( V_2 , V_250 ) ;
}
F_33 ( V_18 ) ;
F_114 ( V_2 , V_18 -> V_252 ) ;
V_2 -> V_67 -> V_253 = 0 ;
if ( V_2 -> V_20 > 1 )
F_115 ( V_2 , 1 ) ;
F_116 ( V_2 ) ;
if ( V_18 -> V_200 & V_211 )
F_117 ( V_2 , V_254 ) ;
F_14 ( V_2 ) ;
F_118 ( V_2 , 1 ) ;
V_2 -> V_255 = 0 ;
F_77 ( V_54 , & V_2 -> V_55 ) ;
return 0 ;
}
static int
F_119 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_57 = 0 ;
F_120 () ;
if ( F_121 ( V_18 ) )
V_57 = F_111 ( V_2 , V_18 ) ;
F_122 () ;
return V_57 ;
}
static void
F_123 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
if ( V_2 -> V_26 != V_27 )
return;
if ( ! F_124 ( V_54 , & V_2 -> V_55 ) )
return;
F_125 () ;
F_126 ( & V_2 -> V_256 ) ;
F_127 ( V_18 ) ;
F_128 ( V_18 ) ;
F_129 ( V_2 ) ;
if ( V_2 -> V_257 . V_258 )
F_130 ( V_2 ) ;
F_131 ( V_2 , V_259 ) ;
F_16 ( V_2 ) ;
F_132 ( V_2 ) ;
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
F_135 ( & V_2 -> V_256 ) ;
}
static void
F_136 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
F_120 () ;
if ( F_121 ( V_18 ) )
F_123 ( V_2 , V_18 ) ;
F_122 () ;
}
static int
F_137 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_29 * V_30 = V_2 -> V_30 ;
int V_57 ;
if ( V_2 -> V_26 == V_27 )
return 0 ;
V_57 = F_10 ( V_2 , V_18 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_138 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_18 ) ;
goto V_260;
}
V_57 = F_139 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_19 ) ;
goto V_261;
}
V_57 = F_107 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_20 ) ;
goto V_262;
}
F_140 ( V_2 ) ;
V_2 -> V_26 = V_27 ;
return 0 ;
V_262:
F_141 ( V_2 ) ;
V_261:
F_142 ( V_2 ) ;
V_260:
F_12 ( V_2 ) ;
return V_57 ;
}
static void
F_143 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 != V_27 )
return;
F_144 ( V_2 ) ;
F_141 ( V_2 ) ;
F_145 ( V_2 ) ;
F_109 ( V_2 ) ;
F_12 ( V_2 ) ;
F_142 ( V_2 ) ;
V_2 -> V_26 = 0 ;
}
void F_146 ( struct V_17 * V_18 , int V_20 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_7 * V_8 ;
int V_19 ;
F_80 ( V_54 , & V_2 -> V_55 ) ;
if ( V_2 -> V_242 == V_243 ) {
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_2 -> V_12 -> V_15 [ V_19 ] ;
F_3 ( V_8 ) ;
}
}
F_132 ( V_2 ) ;
F_143 ( V_2 ) ;
V_2 -> V_242 = 0 ;
V_2 -> V_20 = V_20 ;
if ( F_137 ( V_2 ) )
goto V_263;
if ( F_121 ( V_18 ) )
F_111 ( V_2 , V_18 ) ;
V_263:
F_34 ( V_18 ) ;
}
static int F_147 ( struct V_1 * V_2 )
{
int V_57 = 0 ;
V_2 -> V_67 = F_7 ( sizeof( struct V_264 ) ,
V_16 ) ;
if ( ! V_2 -> V_67 ) {
F_65 ( & V_2 -> V_30 -> V_45 ,
L_21 ) ;
V_57 = - V_21 ;
goto V_233;
}
V_2 -> V_12 = F_7 ( sizeof( struct V_11 ) ,
V_16 ) ;
if ( ! V_2 -> V_12 ) {
F_65 ( & V_2 -> V_30 -> V_45 ,
L_21 ) ;
F_9 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
V_57 = - V_21 ;
goto V_233;
}
V_2 -> V_67 -> V_265 . V_266 = V_267 ;
V_2 -> V_67 -> V_265 . V_268 = V_269 ;
V_2 -> V_67 -> V_265 . V_270 = V_271 ;
V_233:
return V_57 ;
}
static void F_148 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
if ( V_2 -> V_67 -> V_148 . V_153 ) {
F_71 ( V_2 -> V_67 -> V_148 . V_153 ) ;
V_2 -> V_67 -> V_148 . V_153 = NULL ;
}
F_9 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
}
int F_149 ( struct V_17 * V_18 , int V_272 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_7 * V_8 ;
struct V_249 * V_250 ;
int V_19 ;
int V_81 ;
F_32 ( V_18 ) ;
if ( F_121 ( V_18 ) )
F_123 ( V_2 , V_18 ) ;
F_143 ( V_2 ) ;
V_2 -> V_20 = 1 ;
V_2 -> V_242 = V_272 ;
V_81 = F_137 ( V_2 ) ;
if ( V_81 ) {
F_34 ( V_18 ) ;
return V_81 ;
}
V_81 = F_112 ( V_2 ) ;
if ( V_81 ) {
F_143 ( V_2 ) ;
F_34 ( V_18 ) ;
return V_81 ;
}
for ( V_19 = 0 ; V_19 < V_2 -> V_173 ; V_19 ++ ) {
V_250 = & V_2 -> V_12 -> V_251 [ V_19 ] ;
F_113 ( V_2 , V_250 ) ;
}
if ( V_2 -> V_242 == V_243 ) {
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_2 -> V_12 -> V_15 [ V_19 ] ;
F_4 ( V_8 ) ;
}
}
if ( V_2 -> V_242 == V_273 ) {
V_2 -> V_67 -> V_274 = 0 ;
F_118 ( V_2 , 1 ) ;
}
F_77 ( V_54 , & V_2 -> V_55 ) ;
return 0 ;
}
static int
F_150 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
if ( F_151 ( V_275 , & V_2 -> V_55 ) )
return - V_276 ;
F_32 ( V_18 ) ;
F_136 ( V_2 , V_18 ) ;
F_119 ( V_2 , V_18 ) ;
F_34 ( V_18 ) ;
F_80 ( V_275 , & V_2 -> V_55 ) ;
return 0 ;
}
int
F_152 ( struct V_1 * V_2 )
{
int V_57 = 0 ;
struct V_17 * V_18 = V_2 -> V_18 ;
if ( F_151 ( V_275 , & V_2 -> V_55 ) )
return - V_276 ;
if ( V_2 -> V_26 == V_27 ) {
F_32 ( V_18 ) ;
if ( F_121 ( V_18 ) )
F_123 ( V_2 , V_18 ) ;
F_143 ( V_2 ) ;
if ( F_121 ( V_18 ) ) {
V_57 = F_137 ( V_2 ) ;
if ( ! V_57 )
F_111 ( V_2 , V_18 ) ;
}
F_34 ( V_18 ) ;
}
F_80 ( V_275 , & V_2 -> V_55 ) ;
return V_57 ;
}
static int
F_153 ( struct V_1 * V_2 ,
struct V_17 * V_18 , T_2 V_277 )
{
int V_57 ;
struct V_29 * V_30 = V_2 -> V_30 ;
V_2 -> V_278 = 0 ;
V_2 -> V_279 = 38 ;
V_18 -> V_280 = & V_281 ;
V_18 -> V_282 = 5 * V_283 ;
F_154 ( V_18 , V_18 -> V_252 ) ;
F_155 ( V_18 , & V_284 ) ;
V_18 -> V_285 = V_202 | V_203 |
V_205 | V_204 ;
if ( V_2 -> V_182 & V_208 )
V_18 -> V_285 |= V_209 | V_210 ;
if ( V_277 )
V_18 -> V_285 |= V_286 ;
V_18 -> V_201 = V_18 -> V_285 ;
if ( V_2 -> V_182 & V_287 )
V_18 -> V_285 |= V_288 ;
if ( V_2 -> V_182 & V_289 )
V_18 -> V_285 |= V_211 ;
V_18 -> V_200 |= V_18 -> V_285 |
V_290 | V_207 ;
V_18 -> V_70 = V_2 -> V_37 [ 0 ] . V_69 ;
V_57 = F_156 ( V_18 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_22 ) ;
return V_57 ;
}
return 0 ;
}
static int F_157 ( struct V_29 * V_30 , T_2 * V_277 )
{
if ( ! F_158 ( V_30 , F_159 ( 64 ) ) &&
! F_160 ( V_30 , F_159 ( 64 ) ) )
* V_277 = 1 ;
else if ( ! F_158 ( V_30 , F_159 ( 32 ) ) &&
! F_160 ( V_30 , F_159 ( 32 ) ) )
* V_277 = 0 ;
else {
F_65 ( & V_30 -> V_45 , L_23 ) ;
return - V_41 ;
}
return 0 ;
}
static int
F_161 ( struct V_1 * V_2 , T_5 V_13 )
{
V_2 -> V_37 = F_51 ( V_13 , sizeof( struct V_291 ) ,
V_16 ) ;
if ( V_2 -> V_37 )
return 0 ;
F_65 ( & V_2 -> V_30 -> V_45 , L_24 ) ;
return - V_21 ;
}
static int T_8
F_162 ( struct V_29 * V_30 , const struct V_292 * V_293 )
{
struct V_17 * V_18 = NULL ;
struct V_1 * V_2 = NULL ;
int V_57 ;
T_9 V_294 ;
T_9 V_277 ;
char V_295 [ V_296 ] ;
V_57 = F_163 ( V_30 ) ;
if ( V_57 )
return V_57 ;
if ( ! ( F_164 ( V_30 , 0 ) & V_297 ) ) {
V_57 = - V_298 ;
goto V_299;
}
V_57 = F_157 ( V_30 , & V_277 ) ;
if ( V_57 )
goto V_299;
V_57 = F_165 ( V_30 , V_300 ) ;
if ( V_57 )
goto V_299;
F_166 ( V_30 ) ;
F_167 ( V_30 ) ;
V_18 = F_168 ( sizeof( struct V_1 ) ) ;
if ( ! V_18 ) {
F_65 ( & V_30 -> V_45 , L_25 ) ;
V_57 = - V_21 ;
goto V_301;
}
F_169 ( V_18 , & V_30 -> V_45 ) ;
V_2 = F_30 ( V_18 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_30 = V_30 ;
if ( F_147 ( V_2 ) )
goto V_302;
V_2 -> V_303 = V_304 ;
V_294 = V_30 -> V_305 ;
V_2 -> V_67 -> V_294 = V_294 ;
V_2 -> V_306 = V_307 ;
F_170 ( & V_2 -> V_67 -> V_308 ) ;
F_171 ( & V_2 -> V_67 -> V_309 ) ;
F_172 ( & V_2 -> V_256 ) ;
F_173 ( & V_2 -> V_310 ) ;
V_57 = F_61 ( V_2 ) ;
if ( V_57 )
goto V_262;
V_2 -> V_311 = V_2 -> V_67 -> V_68 ;
V_57 = F_174 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_26 ) ;
goto V_312;
}
V_57 = F_175 ( V_2 ) ;
if ( V_57 )
goto V_312;
V_2 -> V_49 |= V_313 ;
V_57 = V_2 -> V_123 -> V_314 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_27 ) ;
goto V_315;
}
if ( F_25 ( V_2 ) )
F_28 ( & V_30 -> V_45 , L_28 ) ;
if ( V_2 -> V_311 == 0 ) {
F_68 ( V_2 , V_295 ) ;
F_176 ( L_29 ,
F_177 ( V_316 ) ,
V_295 , V_2 -> V_67 -> V_294 ) ;
}
F_19 ( V_2 ) ;
V_57 = F_161 ( V_2 , V_2 -> V_181 ) ;
if ( V_57 )
goto V_315;
F_42 ( V_2 ) ;
V_57 = F_153 ( V_2 , V_18 , V_277 ) ;
if ( V_57 )
goto V_317;
F_178 ( V_30 , V_2 ) ;
F_179 ( V_2 , V_318 , V_319 ) ;
switch ( V_2 -> V_67 -> V_154 ) {
case V_166 :
F_37 ( & V_2 -> V_30 -> V_45 , L_30 ,
V_2 -> V_18 -> V_132 ) ;
break;
case V_155 :
F_37 ( & V_2 -> V_30 -> V_45 , L_31 ,
V_2 -> V_18 -> V_132 ) ;
break;
}
if ( V_2 -> V_306 )
F_180 ( V_2 ) ;
F_181 ( V_2 ) ;
return 0 ;
V_317:
F_45 ( V_2 ) ;
F_9 ( V_2 -> V_37 ) ;
V_315:
F_182 ( V_2 , 0 ) ;
V_312:
F_48 ( V_2 ) ;
V_262:
F_148 ( V_2 ) ;
V_302:
F_183 ( V_18 ) ;
V_301:
F_184 ( V_30 ) ;
V_299:
F_178 ( V_30 , NULL ) ;
F_185 ( V_30 ) ;
return V_57 ;
}
static void T_10 F_186 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 ;
V_2 = F_187 ( V_30 ) ;
if ( V_2 == NULL )
return;
V_18 = V_2 -> V_18 ;
F_188 ( V_2 ) ;
F_189 ( V_18 ) ;
F_143 ( V_2 ) ;
if ( V_2 -> V_84 != NULL )
F_9 ( V_2 -> V_84 ) ;
if ( V_2 -> V_87 != NULL )
F_9 ( V_2 -> V_87 ) ;
F_182 ( V_2 , 0 ) ;
F_80 ( V_275 , & V_2 -> V_55 ) ;
F_190 ( V_2 ) ;
F_45 ( V_2 ) ;
F_9 ( V_2 -> V_37 ) ;
F_191 ( V_2 ) ;
F_48 ( V_2 ) ;
F_103 ( V_2 ) ;
F_192 ( V_30 ) ;
F_184 ( V_30 ) ;
F_185 ( V_30 ) ;
F_178 ( V_30 , NULL ) ;
F_148 ( V_2 ) ;
F_183 ( V_18 ) ;
}
static int F_193 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_187 ( V_30 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
int V_320 ;
F_32 ( V_18 ) ;
F_188 ( V_2 ) ;
if ( F_121 ( V_18 ) )
F_136 ( V_2 , V_18 ) ;
F_182 ( V_2 , 0 ) ;
F_80 ( V_275 , & V_2 -> V_55 ) ;
V_320 = F_194 ( V_30 ) ;
if ( V_320 )
return V_320 ;
if ( F_195 ( V_2 ) ) {
F_196 ( V_30 , V_321 , 1 ) ;
F_196 ( V_30 , V_322 , 1 ) ;
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
F_198 ( struct V_29 * V_30 , T_11 V_55 )
{
int V_320 ;
V_320 = F_193 ( V_30 ) ;
if ( V_320 )
return V_320 ;
F_199 ( V_30 , F_200 ( V_30 , V_55 ) ) ;
return 0 ;
}
static int
F_201 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_187 ( V_30 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
int V_57 ;
V_57 = F_163 ( V_30 ) ;
if ( V_57 )
return V_57 ;
F_199 ( V_30 , V_323 ) ;
F_166 ( V_30 ) ;
F_202 ( V_30 ) ;
V_57 = V_2 -> V_123 -> V_314 ( V_2 ) ;
if ( V_57 ) {
F_65 ( & V_30 -> V_45 , L_32 ) ;
return V_57 ;
}
if ( F_121 ( V_18 ) ) {
V_57 = F_119 ( V_2 , V_18 ) ;
if ( V_57 )
goto V_324;
F_79 ( V_18 , V_325 ) ;
}
V_324:
F_34 ( V_18 ) ;
F_179 ( V_2 , V_318 , V_319 ) ;
return 0 ;
}
static int F_203 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
int V_57 ;
F_127 ( V_18 ) ;
V_57 = F_137 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_111 ( V_2 , V_18 ) ;
if ( V_57 )
goto V_233;
F_204 ( V_18 ) ;
return 0 ;
V_233:
F_143 ( V_2 ) ;
return V_57 ;
}
static int F_205 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
F_123 ( V_2 , V_18 ) ;
return 0 ;
}
void F_180 ( struct V_1 * V_2 )
{
void * V_326 ;
int V_36 ;
if ( V_2 -> V_257 . V_327 && V_2 -> V_257 . V_328 )
return;
F_172 ( & V_2 -> V_329 ) ;
V_326 = F_51 ( V_330 , sizeof( struct V_331 ) ,
V_16 ) ;
if ( ! V_326 )
return;
V_2 -> V_257 . V_327 = V_330 ;
V_2 -> V_257 . V_328 = V_326 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_257 . V_327 ; V_36 ++ )
F_206 ( & V_2 -> V_257 . V_328 [ V_36 ] ) ;
}
static void F_190 ( struct V_1 * V_2 )
{
if ( V_2 -> V_257 . V_327 && V_2 -> V_257 . V_328 )
F_9 ( V_2 -> V_257 . V_328 ) ;
V_2 -> V_257 . V_328 = NULL ;
V_2 -> V_257 . V_327 = 0 ;
}
static void F_207 ( struct V_1 * V_2 ,
T_12 V_332 , T_13 V_190 , struct V_3 * V_4 )
{
struct V_333 * V_334 ;
struct V_335 * V_336 ;
struct V_337 * V_338 ;
struct V_339 * V_340 ;
T_1 V_5 ;
T_12 V_341 ;
V_5 = V_4 -> V_5 ;
V_334 = & V_4 -> V_342 [ V_4 -> V_5 ] ;
V_336 = (struct V_335 * ) V_334 ;
memset ( V_336 , 0 , sizeof( struct V_335 ) ) ;
V_336 -> V_343 = F_208 ( V_344 << 23 ) ;
V_341 = V_345 | ( ( T_12 ) ( V_2 -> V_311 ) << 16 ) ;
V_336 -> V_346 = F_208 ( V_341 ) ;
V_338 = (struct V_337 * ) & ( V_336 -> V_347 [ 0 ] ) ;
V_338 -> V_348 = V_190 ? V_349 : V_350 ;
memcpy ( V_338 -> V_39 , & V_332 , V_40 ) ;
V_340 = (struct V_339 * ) & V_336 -> V_347 [ 1 ] ;
V_340 -> V_190 = V_190 ;
V_4 -> V_5 = F_209 ( V_5 , V_4 -> V_351 ) ;
F_125 () ;
}
static void
F_210 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_333 * V_352 ,
struct V_353 * V_354 )
{
struct V_355 * V_356 = (struct V_355 * ) ( V_354 -> V_103 ) ;
struct V_357 * V_358 , * V_359 ;
struct V_360 * V_361 , * V_362 ;
struct V_331 * V_326 ;
T_12 V_363 = 0 ;
T_13 V_190 = 0 ;
T_2 V_364 ;
if ( ! F_211 ( V_356 -> V_365 , V_2 -> V_39 ) )
return;
if ( V_2 -> V_257 . V_258 >= V_2 -> V_257 . V_327 )
return;
if ( V_2 -> V_49 & V_156 )
V_190 = V_352 -> V_366 ;
memcpy ( & V_363 , V_356 -> V_365 , V_40 ) ;
V_364 = F_212 ( V_363 ) & ( V_330 - 1 ) ;
V_326 = & ( V_2 -> V_257 . V_328 [ V_364 ] ) ;
F_213 (tmp_fil, tmp_hnode, n, head, fnode) {
if ( ! memcmp ( V_359 -> V_367 , & V_363 , V_40 ) &&
V_359 -> V_190 == V_190 ) {
if ( V_304 >
( V_368 * V_283 + V_359 -> V_369 ) )
F_207 ( V_2 , V_363 , V_190 ,
V_4 ) ;
V_359 -> V_369 = V_304 ;
return;
}
}
V_358 = F_7 ( sizeof( struct V_357 ) , V_370 ) ;
if ( ! V_358 )
return;
F_207 ( V_2 , V_363 , V_190 , V_4 ) ;
V_358 -> V_369 = V_304 ;
V_358 -> V_190 = V_190 ;
memcpy ( V_358 -> V_367 , & V_363 , V_40 ) ;
F_126 ( & V_2 -> V_329 ) ;
F_214 ( & ( V_358 -> V_371 ) , V_326 ) ;
V_2 -> V_257 . V_258 ++ ;
F_135 ( & V_2 -> V_329 ) ;
}
static int
F_215 ( struct V_1 * V_2 ,
struct V_333 * V_352 ,
struct V_353 * V_354 )
{
T_2 V_372 = 0 , V_373 = 0 ;
T_5 V_49 = 0 , V_374 = 0 ;
int V_375 , V_376 , V_377 ;
struct V_333 * V_334 ;
struct V_378 * V_379 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_5 V_380 = F_216 ( V_354 -> V_380 ) ;
T_1 V_5 = V_4 -> V_5 ;
if ( V_380 == V_381 ) {
V_379 = (struct V_378 * ) V_354 -> V_103 ;
V_49 = V_382 ;
V_374 = V_379 -> V_383 ;
} else if ( F_217 ( V_354 ) ) {
V_49 = V_384 ;
V_374 = F_218 ( V_354 ) ;
}
if ( F_219 ( V_2 -> V_191 ) ) {
if ( V_374 && ! ( V_2 -> V_49 & V_189 ) )
return - V_41 ;
if ( V_374 && ( V_2 -> V_49 & V_189 ) )
goto V_385;
V_49 = V_384 ;
V_374 = V_2 -> V_191 ;
}
V_385:
F_220 ( V_352 , V_374 ) ;
F_221 ( V_352 , V_49 , V_372 ) ;
if ( * ( V_354 -> V_103 ) & V_213 ) {
V_49 |= V_213 ;
memcpy ( & V_352 -> V_386 , V_354 -> V_103 , V_40 ) ;
}
V_372 = V_387 ;
if ( ( V_2 -> V_18 -> V_200 & ( V_209 | V_210 ) ) &&
F_222 ( V_354 ) -> V_388 > 0 ) {
V_373 = F_223 ( V_354 ) + F_224 ( V_354 ) ;
V_352 -> V_389 = F_225 ( F_222 ( V_354 ) -> V_388 ) ;
V_352 -> V_390 = V_373 ;
V_372 = ( V_380 == V_391 ) ? V_392 : V_393 ;
V_375 = 0 ;
V_376 = 2 ;
if ( V_49 & V_384 ) {
V_352 -> V_390 += V_394 ;
V_352 -> V_395 = V_394 ;
V_352 -> V_396 = V_394 ;
V_49 |= V_382 ;
V_334 = & V_4 -> V_342 [ V_5 ] ;
V_4 -> V_397 [ V_5 ] . V_354 = NULL ;
V_377 = F_226 ( ( int ) sizeof( struct V_333 ) -
V_376 , V_373 + V_394 ) ;
V_379 = (struct V_378 * ) ( ( char * ) V_334 + 2 ) ;
F_227 ( V_354 , V_379 , 12 ) ;
V_379 -> V_398 = F_228 ( V_381 ) ;
V_379 -> V_383 = F_228 ( V_374 ) ;
F_229 ( V_354 , 12 ,
( char * ) V_379 + 16 , V_377 - 16 ) ;
V_375 = V_377 - V_394 ;
V_376 = 0 ;
V_5 = F_209 ( V_5 , V_4 -> V_351 ) ;
}
while ( V_375 < V_373 ) {
V_377 = F_226 ( ( int ) sizeof( struct V_333 ) -
V_376 , ( V_373 - V_375 ) ) ;
V_334 = & V_4 -> V_342 [ V_5 ] ;
V_4 -> V_397 [ V_5 ] . V_354 = NULL ;
F_229 ( V_354 , V_375 ,
( char * ) V_334 + V_376 , V_377 ) ;
V_375 += V_377 ;
V_376 = 0 ;
V_5 = F_209 ( V_5 , V_4 -> V_351 ) ;
}
V_4 -> V_5 = V_5 ;
F_125 () ;
V_2 -> V_28 . V_399 ++ ;
} else if ( V_354 -> V_400 == V_401 ) {
T_2 V_402 ;
if ( V_380 == V_403 ) {
V_402 = F_230 ( V_354 ) -> V_380 ;
if ( V_402 == V_404 )
V_372 = V_405 ;
else if ( V_402 == V_406 )
V_372 = V_407 ;
} else if ( V_380 == V_391 ) {
V_402 = F_231 ( V_354 ) -> V_408 ;
if ( V_402 == V_404 )
V_372 = V_409 ;
else if ( V_402 == V_406 )
V_372 = V_410 ;
}
}
V_352 -> V_395 += F_223 ( V_354 ) ;
V_352 -> V_396 += F_232 ( V_354 ) ;
F_221 ( V_352 , V_49 , V_372 ) ;
return 0 ;
}
static int
F_233 ( struct V_29 * V_30 ,
struct V_353 * V_354 , struct V_411 * V_412 )
{
struct V_413 * V_414 ;
struct V_415 * V_416 ;
int V_36 , V_417 ;
T_14 V_418 ;
V_417 = F_222 ( V_354 ) -> V_417 ;
V_414 = & V_412 -> V_419 [ 0 ] ;
V_418 = F_234 ( V_30 , V_354 -> V_103 ,
F_235 ( V_354 ) , V_420 ) ;
if ( F_236 ( V_30 , V_418 ) )
goto V_421;
V_414 -> V_422 = V_418 ;
V_414 -> V_423 = F_235 ( V_354 ) ;
for ( V_36 = 0 ; V_36 < V_417 ; V_36 ++ ) {
V_416 = & F_222 ( V_354 ) -> V_424 [ V_36 ] ;
V_414 = & V_412 -> V_419 [ V_36 + 1 ] ;
V_418 = F_237 ( & V_30 -> V_45 , V_416 , 0 , F_238 ( V_416 ) ,
V_425 ) ;
if ( F_239 ( & V_30 -> V_45 , V_418 ) )
goto V_426;
V_414 -> V_422 = V_418 ;
V_414 -> V_423 = F_238 ( V_416 ) ;
}
return 0 ;
V_426:
while ( -- V_36 >= 0 ) {
V_414 = & V_412 -> V_419 [ V_36 + 1 ] ;
F_240 ( V_30 , V_414 -> V_422 , V_414 -> V_423 , V_420 ) ;
}
V_414 = & V_412 -> V_419 [ 0 ] ;
F_241 ( V_30 , V_414 -> V_422 , F_235 ( V_354 ) , V_420 ) ;
V_421:
return - V_21 ;
}
static void
F_242 ( struct V_29 * V_30 , struct V_353 * V_354 ,
struct V_411 * V_412 )
{
struct V_413 * V_414 = & V_412 -> V_419 [ 0 ] ;
int V_417 = F_222 ( V_354 ) -> V_417 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_417 ; V_36 ++ ) {
V_414 = & V_412 -> V_419 [ V_36 + 1 ] ;
F_240 ( V_30 , V_414 -> V_422 , V_414 -> V_423 , V_420 ) ;
}
V_414 = & V_412 -> V_419 [ 0 ] ;
F_241 ( V_30 , V_414 -> V_422 , F_235 ( V_354 ) , V_420 ) ;
V_412 -> V_354 = NULL ;
}
static inline void
F_243 ( T_12 * V_427 )
{
V_427 [ 0 ] = 0ULL ;
V_427 [ 2 ] = 0ULL ;
V_427 [ 7 ] = 0ULL ;
}
T_15
F_244 ( struct V_353 * V_354 , struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_411 * V_412 ;
struct V_413 * V_428 ;
struct V_333 * V_334 , * V_352 ;
struct V_29 * V_30 ;
struct V_355 * V_356 ;
int V_429 = 0 ;
int V_36 , V_430 ;
T_1 V_5 ;
int V_431 ;
T_1 V_171 = V_4 -> V_351 ;
if ( ! F_31 ( V_54 , & V_2 -> V_55 ) ) {
F_245 ( V_18 ) ;
return V_432 ;
}
if ( V_2 -> V_49 & V_195 ) {
V_356 = (struct V_355 * ) V_354 -> V_103 ;
if ( F_211 ( V_356 -> V_365 ,
V_2 -> V_39 ) )
goto V_433;
}
V_431 = F_222 ( V_354 ) -> V_417 + 1 ;
if ( ! F_246 ( V_354 ) && V_431 > V_434 ) {
for ( V_36 = 0 ; V_36 < ( V_431 - V_434 ) ; V_36 ++ )
V_429 += F_238 ( & F_222 ( V_354 ) -> V_424 [ V_36 ] ) ;
if ( ! F_247 ( V_354 , V_429 ) )
goto V_433;
V_431 = 1 + F_222 ( V_354 ) -> V_417 ;
}
if ( F_219 ( F_248 ( V_4 ) <= V_435 ) ) {
F_245 ( V_18 ) ;
if ( F_248 ( V_4 ) > V_435 )
F_204 ( V_18 ) ;
else {
V_2 -> V_28 . V_436 ++ ;
return V_432 ;
}
}
V_5 = V_4 -> V_5 ;
V_412 = & V_4 -> V_397 [ V_5 ] ;
V_30 = V_2 -> V_30 ;
V_352 = V_334 = & V_4 -> V_342 [ V_5 ] ;
F_243 ( ( T_12 * ) V_334 ) ;
if ( F_233 ( V_30 , V_354 , V_412 ) ) {
V_2 -> V_28 . V_437 ++ ;
goto V_433;
}
V_412 -> V_354 = V_354 ;
V_412 -> V_431 = V_431 ;
F_249 ( V_352 , V_431 , V_354 -> V_438 ) ;
F_250 ( V_352 , V_2 -> V_311 ) ;
for ( V_36 = 0 ; V_36 < V_431 ; V_36 ++ ) {
V_430 = V_36 % 4 ;
if ( ( V_430 == 0 ) && ( V_36 > 0 ) ) {
V_5 = F_209 ( V_5 , V_171 ) ;
V_334 = & V_4 -> V_342 [ V_5 ] ;
F_243 ( ( T_12 * ) V_334 ) ;
V_4 -> V_397 [ V_5 ] . V_354 = NULL ;
}
V_428 = & V_412 -> V_419 [ V_36 ] ;
V_334 -> V_439 [ V_430 ] = F_225 ( V_428 -> V_423 ) ;
switch ( V_430 ) {
case 0 :
V_334 -> V_440 = F_208 ( V_428 -> V_422 ) ;
break;
case 1 :
V_334 -> V_441 = F_208 ( V_428 -> V_422 ) ;
break;
case 2 :
V_334 -> V_442 = F_208 ( V_428 -> V_422 ) ;
break;
case 3 :
V_334 -> V_443 = F_208 ( V_428 -> V_422 ) ;
break;
}
}
V_4 -> V_5 = F_209 ( V_5 , V_171 ) ;
F_125 () ;
if ( F_219 ( F_215 ( V_2 , V_352 , V_354 ) ) )
goto V_444;
if ( V_2 -> V_306 )
F_210 ( V_2 , V_4 , V_352 , V_354 ) ;
V_2 -> V_28 . V_445 += V_354 -> V_438 ;
V_2 -> V_28 . V_446 ++ ;
F_1 ( V_2 , V_4 ) ;
return V_447 ;
V_444:
F_242 ( V_30 , V_354 , V_412 ) ;
V_433:
V_2 -> V_28 . V_448 ++ ;
F_251 ( V_354 ) ;
return V_447 ;
}
static int F_252 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_449 , V_450 , V_451 ;
int V_452 = 0 ;
V_449 = F_54 ( V_2 , V_453 ) ;
V_450 = F_253 ( V_449 ) ;
V_451 = F_254 ( V_449 ) ;
if ( V_450 == V_454 ) {
F_65 ( & V_18 -> V_45 ,
L_33
L_34 ,
V_451 ) ;
V_452 = 1 ;
} else if ( V_450 == V_455 ) {
if ( V_2 -> V_449 == V_456 ) {
F_65 ( & V_18 -> V_45 ,
L_35
L_36
L_37 ,
V_451 ) ;
}
} else {
if ( V_2 -> V_449 == V_455 ) {
F_37 ( & V_18 -> V_45 ,
L_38
L_39 , V_451 ) ;
}
}
V_2 -> V_449 = V_450 ;
return V_452 ;
}
void F_255 ( struct V_1 * V_2 , int V_253 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
if ( V_2 -> V_67 -> V_253 && ! V_253 ) {
F_256 ( V_18 , L_40 ) ;
V_2 -> V_67 -> V_253 = 0 ;
if ( F_121 ( V_18 ) ) {
F_127 ( V_18 ) ;
F_245 ( V_18 ) ;
}
} else if ( ! V_2 -> V_67 -> V_253 && V_253 ) {
F_256 ( V_18 , L_41 ) ;
V_2 -> V_67 -> V_253 = 1 ;
if ( F_121 ( V_18 ) ) {
F_257 ( V_18 ) ;
F_258 ( V_18 ) ;
}
}
}
static void F_259 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
if ( F_31 ( V_275 , & V_2 -> V_55 ) )
return;
F_65 ( & V_18 -> V_45 , L_42 ) ;
if ( ++ V_2 -> V_457 >= V_458 )
V_2 -> V_219 = 1 ;
else
V_2 -> V_255 = 1 ;
}
static struct V_459 * F_260 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_459 * V_28 = & V_18 -> V_28 ;
V_28 -> V_270 = V_2 -> V_28 . V_460 + V_2 -> V_28 . V_461 ;
V_28 -> V_462 = V_2 -> V_28 . V_463 ;
V_28 -> V_464 = V_2 -> V_28 . V_465 + V_2 -> V_28 . V_466 ;
V_28 -> V_467 = V_2 -> V_28 . V_445 ;
V_28 -> V_468 = V_2 -> V_28 . V_469 ;
V_28 -> V_470 = V_2 -> V_28 . V_448 ;
return V_28 ;
}
static T_16 F_261 ( struct V_1 * V_2 )
{
T_1 V_471 ;
V_471 = F_57 ( V_2 -> V_73 ) ;
if ( ! ( V_471 & V_2 -> V_72 ) )
return V_472 ;
V_471 = F_57 ( V_2 -> V_75 ) ;
if ( ! F_262 ( V_471 ) )
return V_472 ;
F_2 ( 0xffffffff , V_2 -> V_65 ) ;
F_57 ( V_2 -> V_73 ) ;
F_57 ( V_2 -> V_73 ) ;
return V_473 ;
}
static T_16 V_244 ( int V_70 , void * V_103 )
{
struct V_7 * V_8 = V_103 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_49 & V_59 )
goto V_324;
else if ( V_2 -> V_49 & V_58 ) {
F_2 ( 0xffffffff , V_2 -> V_65 ) ;
goto V_324;
}
if ( F_261 ( V_2 ) == V_472 )
return V_472 ;
V_324:
V_2 -> V_474 ++ ;
F_4 ( V_8 ) ;
return V_473 ;
}
static T_16 V_248 ( int V_70 , void * V_103 )
{
struct V_7 * V_8 = V_103 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_261 ( V_2 ) == V_472 )
return V_472 ;
F_263 ( & V_8 -> V_22 ) ;
return V_473 ;
}
static T_16 V_247 ( int V_70 , void * V_103 )
{
struct V_7 * V_8 = V_103 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_2 ( 0xffffffff , V_2 -> V_65 ) ;
F_263 ( & V_8 -> V_22 ) ;
return V_473 ;
}
static T_16 V_246 ( int V_70 , void * V_103 )
{
struct V_7 * V_8 = V_103 ;
F_263 ( & V_8 -> V_22 ) ;
return V_473 ;
}
static int F_264 ( struct V_1 * V_2 )
{
T_1 V_475 , V_476 ;
int V_13 = 0 , V_36 ;
struct V_411 * V_477 ;
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_413 * V_416 ;
int V_324 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_265 ( & V_2 -> V_256 ) )
return 1 ;
V_475 = V_4 -> V_475 ;
V_476 = F_266 ( * ( V_4 -> V_476 ) ) ;
while ( V_475 != V_476 ) {
V_477 = & V_4 -> V_397 [ V_475 ] ;
if ( V_477 -> V_354 ) {
V_416 = & V_477 -> V_419 [ 0 ] ;
F_241 ( V_30 , V_416 -> V_422 , V_416 -> V_423 ,
V_420 ) ;
V_416 -> V_422 = 0ULL ;
for ( V_36 = 1 ; V_36 < V_477 -> V_431 ; V_36 ++ ) {
V_416 ++ ;
F_240 ( V_30 , V_416 -> V_422 , V_416 -> V_423 ,
V_420 ) ;
V_416 -> V_422 = 0ULL ;
}
V_2 -> V_28 . V_463 ++ ;
F_251 ( V_477 -> V_354 ) ;
V_477 -> V_354 = NULL ;
}
V_475 = F_209 ( V_475 , V_4 -> V_351 ) ;
if ( ++ V_13 >= V_478 )
break;
}
if ( V_13 && F_121 ( V_18 ) ) {
V_4 -> V_475 = V_475 ;
F_125 () ;
if ( F_267 ( V_18 ) && F_268 ( V_18 ) ) {
if ( F_248 ( V_4 ) > V_435 ) {
F_258 ( V_18 ) ;
V_2 -> V_28 . V_479 ++ ;
}
}
V_2 -> V_457 = 0 ;
}
V_476 = F_266 ( * ( V_4 -> V_476 ) ) ;
V_324 = ( V_475 == V_476 ) ;
F_135 ( & V_2 -> V_256 ) ;
return V_324 ;
}
static int V_23 ( struct V_480 * V_22 , int V_481 )
{
struct V_7 * V_8 =
F_269 ( V_22 , struct V_7 , V_22 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_482 ;
int V_483 ;
V_482 = F_264 ( V_2 ) ;
V_483 = F_270 ( V_8 , V_481 ) ;
if ( ( V_483 < V_481 ) && V_482 ) {
F_271 ( & V_8 -> V_22 ) ;
if ( F_31 ( V_54 , & V_2 -> V_55 ) )
F_4 ( V_8 ) ;
}
return V_483 ;
}
static int V_25 ( struct V_480 * V_22 , int V_481 )
{
struct V_7 * V_8 =
F_269 ( V_22 , struct V_7 , V_22 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_483 ;
V_483 = F_270 ( V_8 , V_481 ) ;
if ( V_483 < V_481 ) {
F_271 ( & V_8 -> V_22 ) ;
if ( F_31 ( V_54 , & V_2 -> V_55 ) )
F_4 ( V_8 ) ;
}
return V_483 ;
}
static void F_272 ( struct V_17 * V_18 )
{
int V_19 ;
struct V_7 * V_8 ;
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
F_273 ( V_2 -> V_70 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ ) {
V_8 = & V_12 -> V_15 [ V_19 ] ;
V_248 ( V_2 -> V_70 , V_8 ) ;
}
F_274 ( V_2 -> V_70 ) ;
}
static void
F_106 ( struct V_1 * V_2 , T_2 V_484 )
{
T_1 V_485 ;
V_485 = V_2 -> V_311 & 0xf ;
V_485 |= V_484 << 7 ;
V_485 |= ( V_304 - V_2 -> V_303 ) << 8 ;
F_104 ( V_2 , V_486 , V_485 ) ;
V_2 -> V_303 = V_304 ;
}
static int
F_275 ( struct V_1 * V_2 , T_2 V_55 )
{
T_1 V_485 ;
F_276 ( V_55 != V_487 &&
V_55 != V_488 ) ;
if ( F_55 ( V_2 ) )
return - V_41 ;
V_485 = F_54 ( V_2 , V_489 ) ;
if ( V_55 == V_487 )
F_277 ( V_485 , V_2 -> V_311 ) ;
else if ( V_55 == V_488 )
F_278 ( V_485 , V_2 -> V_311 ) ;
F_104 ( V_2 , V_489 , V_485 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
static int
F_279 ( struct V_1 * V_2 )
{
T_1 V_485 ;
if ( F_55 ( V_2 ) )
return - V_276 ;
V_485 = F_54 ( V_2 , V_489 ) ;
F_280 ( V_485 , V_2 -> V_311 ) ;
F_104 ( V_2 , V_489 , V_485 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
static void
F_182 ( struct V_1 * V_2 , T_2 V_490 )
{
T_1 V_485 ;
if ( F_55 ( V_2 ) )
goto V_57;
V_485 = F_54 ( V_2 , V_107 ) ;
F_281 ( V_485 , V_2 -> V_311 ) ;
F_104 ( V_2 , V_107 , V_485 ) ;
if ( V_490 ) {
F_104 ( V_2 , V_238 , V_240 ) ;
F_37 ( & V_2 -> V_30 -> V_45 ,
L_43 ) ;
} else if ( ! ( V_485 & 0x11111111 ) )
F_104 ( V_2 , V_238 , V_491 ) ;
V_485 = F_54 ( V_2 , V_489 ) ;
F_280 ( V_485 , V_2 -> V_311 ) ;
F_104 ( V_2 , V_489 , V_485 ) ;
F_58 ( V_2 ) ;
V_57:
V_2 -> V_492 = 0 ;
V_2 -> V_49 &= ~ V_493 ;
F_80 ( V_494 , & V_2 -> V_55 ) ;
F_80 ( V_275 , & V_2 -> V_55 ) ;
}
static int
F_282 ( struct V_1 * V_2 )
{
int V_495 , V_55 , V_496 ;
V_55 = F_54 ( V_2 , V_489 ) ;
V_495 = F_54 ( V_2 , V_107 ) ;
if ( V_2 -> V_49 & V_497 ) {
V_496 = ( ~ ( 1 << ( V_2 -> V_67 -> V_68 * 4 ) ) ) ;
V_495 = V_495 & V_496 ;
}
if ( ( ( V_55 & 0x11111111 ) == ( V_495 & 0x11111111 ) ) ||
( ( V_495 & 0x11111111 ) == ( ( V_55 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_283 ( struct V_1 * V_2 )
{
T_1 V_485 = F_54 ( V_2 , V_498 ) ;
if ( V_485 != V_499 ) {
F_28 ( & V_2 -> V_30 -> V_45 , L_44
L_45 , V_499 , V_485 ) ;
}
return 0 ;
}
static int
F_97 ( struct V_1 * V_2 )
{
T_1 V_485 , V_500 ;
T_2 V_501 = V_2 -> V_501 ;
T_2 V_311 = V_2 -> V_311 ;
T_2 V_81 ;
if ( F_124 ( V_494 , & V_2 -> V_55 ) )
return 1 ;
if ( F_55 ( V_2 ) )
return - 1 ;
V_485 = F_54 ( V_2 , V_107 ) ;
if ( ! ( V_485 & ( 1 << ( V_311 * 4 ) ) ) ) {
F_284 ( V_485 , V_311 ) ;
F_104 ( V_2 , V_107 , V_485 ) ;
}
V_500 = F_54 ( V_2 , V_238 ) ;
F_285 ( V_2 , V_502 , L_46 , V_500 ) ;
switch ( V_500 ) {
case V_491 :
F_104 ( V_2 , V_238 , V_503 ) ;
F_104 ( V_2 , V_498 , V_499 ) ;
F_106 ( V_2 , 0 ) ;
F_58 ( V_2 ) ;
return 1 ;
case V_239 :
V_81 = F_283 ( V_2 ) ;
F_58 ( V_2 ) ;
return V_81 ;
case V_487 :
V_485 = F_54 ( V_2 , V_489 ) ;
F_277 ( V_485 , V_311 ) ;
F_104 ( V_2 , V_489 , V_485 ) ;
break;
case V_488 :
V_485 = F_54 ( V_2 , V_489 ) ;
F_278 ( V_485 , V_311 ) ;
F_104 ( V_2 , V_489 , V_485 ) ;
break;
case V_240 :
F_65 ( & V_2 -> V_30 -> V_45 , L_47 ) ;
F_58 ( V_2 ) ;
return - 1 ;
case V_503 :
case V_504 :
break;
}
F_58 ( V_2 ) ;
do {
F_93 ( 1000 ) ;
V_500 = F_54 ( V_2 , V_238 ) ;
if ( V_500 == V_504 )
continue;
} while ( ( V_500 != V_239 ) && -- V_501 );
if ( ! V_501 ) {
F_65 ( & V_2 -> V_30 -> V_45 ,
L_48 ) ;
return - 1 ;
}
if ( F_55 ( V_2 ) )
return - 1 ;
V_485 = F_54 ( V_2 , V_489 ) ;
F_280 ( V_485 , V_311 ) ;
F_104 ( V_2 , V_489 , V_485 ) ;
V_81 = F_283 ( V_2 ) ;
F_58 ( V_2 ) ;
return V_81 ;
}
static void
F_286 ( struct V_505 * V_506 )
{
struct V_1 * V_2 = F_269 ( V_506 ,
struct V_1 , V_507 . V_506 ) ;
T_1 V_508 = 0xf ;
T_1 V_485 ;
if ( F_55 ( V_2 ) )
goto V_509;
V_508 = F_54 ( V_2 , V_238 ) ;
if ( V_508 == V_504 ||
V_508 == V_488 ) {
F_58 ( V_2 ) ;
F_179 ( V_2 , F_286 ,
V_319 * 2 ) ;
return;
}
if ( V_2 -> V_114 == V_122 ) {
F_58 ( V_2 ) ;
goto V_510;
}
if ( V_508 == V_503 ||
V_508 == V_239 ) {
F_37 ( & V_2 -> V_30 -> V_45 , L_49
L_50 ) ;
goto V_511;
}
if ( V_2 -> V_512 ++ > V_2 -> V_513 ) {
F_37 ( & V_2 -> V_30 -> V_45 , L_51 ,
V_2 -> V_513 ) ;
goto V_511;
}
if ( ! F_282 ( V_2 ) ) {
V_511:
V_508 = F_54 ( V_2 , V_238 ) ;
if ( V_508 == V_487 ) {
F_104 ( V_2 , V_238 ,
V_503 ) ;
F_77 ( V_494 , & V_2 -> V_55 ) ;
F_285 ( V_2 , V_514 , L_52 ) ;
F_106 ( V_2 , 0 ) ;
V_485 = F_54 ( V_2 , V_489 ) ;
F_277 ( V_485 , V_2 -> V_311 ) ;
F_104 ( V_2 , V_489 , V_485 ) ;
}
F_58 ( V_2 ) ;
F_120 () ;
if ( V_2 -> V_67 -> V_148 . V_31 &&
( V_2 -> V_49 & V_497 ) ) {
F_285 ( V_2 , V_514 , L_53 ) ;
F_287 ( V_2 ) ;
V_2 -> V_49 |= V_493 ;
}
F_122 () ;
V_2 -> V_49 &= ~ V_497 ;
if ( ! V_2 -> V_123 -> V_314 ( V_2 ) ) {
F_179 ( V_2 , V_515 , 0 ) ;
V_2 -> V_512 = 0 ;
return;
}
goto V_509;
}
F_58 ( V_2 ) ;
V_510:
V_508 = F_54 ( V_2 , V_238 ) ;
F_285 ( V_2 , V_502 , L_54 , V_508 ) ;
switch ( V_508 ) {
case V_239 :
if ( ! V_2 -> V_123 -> V_314 ( V_2 ) ) {
F_179 ( V_2 , V_515 , 0 ) ;
V_2 -> V_512 = 0 ;
return;
}
case V_240 :
break;
default:
F_179 ( V_2 ,
F_286 , V_319 ) ;
return;
}
V_509:
F_65 ( & V_2 -> V_30 -> V_45 , L_55
L_56 , V_508 , V_2 -> V_512 ) ;
F_34 ( V_2 -> V_18 ) ;
F_182 ( V_2 , 0 ) ;
}
static void
F_288 ( struct V_505 * V_506 )
{
struct V_1 * V_2 = F_269 ( V_506 ,
struct V_1 , V_507 . V_506 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_471 ;
F_32 ( V_18 ) ;
if ( V_2 -> V_508 == V_488 ) {
if ( F_121 ( V_18 ) )
F_123 ( V_2 , V_18 ) ;
} else
F_136 ( V_2 , V_18 ) ;
V_471 = F_54 ( V_2 , V_516 ) ;
if ( V_471 & V_517 ) {
F_65 ( & V_2 -> V_30 -> V_45 ,
L_57 ,
V_471 ) ;
if ( F_289 ( V_471 ) == V_518 ) {
F_65 ( & V_2 -> V_30 -> V_45 ,
L_58
L_59 ) ;
F_65 ( & V_2 -> V_30 -> V_45 ,
L_60 ) ;
}
goto V_509;
}
if ( V_2 -> V_449 == V_454 ) {
F_65 ( & V_2 -> V_30 -> V_45 , L_61 ,
V_2 -> V_449 ) ;
goto V_509;
}
if ( ! ( V_2 -> V_49 & V_497 ) ) {
if ( F_275 ( V_2 , V_2 -> V_508 ) ) {
F_65 ( & V_2 -> V_30 -> V_45 ,
L_62
L_63 ) ;
goto V_509;
}
}
V_2 -> V_512 = 0 ;
F_179 ( V_2 , F_286 , V_319 ) ;
return;
V_509:
F_34 ( V_18 ) ;
F_182 ( V_2 , 1 ) ;
}
static void
F_290 ( struct V_1 * V_2 )
{
T_1 V_55 ;
V_55 = F_54 ( V_2 , V_229 ) ;
if ( V_55 == V_519 )
return;
if ( F_55 ( V_2 ) )
return;
F_104 ( V_2 , V_229 , V_519 ) ;
F_58 ( V_2 ) ;
}
void
F_291 ( struct V_1 * V_2 )
{
T_1 V_55 ;
V_2 -> V_219 = 1 ;
if ( F_55 ( V_2 ) )
return;
V_55 = F_54 ( V_2 , V_238 ) ;
if ( V_55 == V_239 ) {
F_104 ( V_2 , V_238 , V_487 ) ;
V_2 -> V_49 |= V_497 ;
F_285 ( V_2 , V_514 , L_64 ) ;
F_106 ( V_2 , 0 ) ;
}
F_104 ( V_2 , V_229 , V_519 ) ;
F_58 ( V_2 ) ;
}
static void
F_95 ( struct V_1 * V_2 )
{
if ( F_55 ( V_2 ) )
return;
F_104 ( V_2 , V_229 , V_230 ) ;
F_285 ( V_2 , V_514 , L_65 ) ;
F_58 ( V_2 ) ;
}
static void
F_179 ( struct V_1 * V_2 ,
T_17 V_112 , int V_520 )
{
if ( F_31 ( V_521 , & V_2 -> V_55 ) )
return;
F_292 ( & V_2 -> V_507 , V_112 ) ;
F_293 ( V_522 , & V_2 -> V_507 ,
F_294 ( V_520 ) ) ;
}
static void
F_188 ( struct V_1 * V_2 )
{
while ( F_151 ( V_275 , & V_2 -> V_55 ) )
F_93 ( 10 ) ;
F_295 ( & V_2 -> V_507 ) ;
}
static void
V_515 ( struct V_505 * V_506 )
{
struct V_1 * V_2 = F_269 ( V_506 ,
struct V_1 , V_507 . V_506 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_228 ;
if ( V_2 -> V_114 != V_104 ) {
V_228 = F_54 ( V_2 , V_229 ) ;
if ( V_2 -> V_512 ++ > V_227 )
F_182 ( V_2 , 0 ) ;
else if ( V_228 != V_230 )
F_179 ( V_2 , V_515 ,
V_319 ) ;
else
goto V_523;
F_285 ( V_2 , V_514 , L_66 ) ;
return;
}
V_523:
if ( F_121 ( V_18 ) ) {
if ( F_119 ( V_2 , V_18 ) )
goto V_324;
F_79 ( V_18 , V_325 ) ;
}
V_324:
F_34 ( V_18 ) ;
V_2 -> V_492 = 0 ;
V_2 -> V_49 &= ~ V_493 ;
F_80 ( V_275 , & V_2 -> V_55 ) ;
if ( ! F_279 ( V_2 ) )
F_179 ( V_2 , V_318 ,
V_319 ) ;
}
static int
F_296 ( struct V_1 * V_2 )
{
T_1 V_55 = 0 , V_524 ;
T_1 V_525 ;
if ( F_252 ( V_2 ) )
goto V_526;
if ( V_2 -> V_219 )
F_291 ( V_2 ) ;
V_55 = F_54 ( V_2 , V_238 ) ;
if ( V_55 == V_487 ) {
F_290 ( V_2 ) ;
V_2 -> V_219 = 1 ;
} else if ( V_55 == V_488 )
goto V_526;
V_524 = F_54 ( V_2 , V_527 ) ;
if ( V_524 != V_2 -> V_524 ) {
V_2 -> V_524 = V_524 ;
V_2 -> V_492 = 0 ;
if ( V_2 -> V_219 )
goto V_526;
if ( V_2 -> V_255 && V_528 ) {
F_150 ( V_2 ) ;
V_2 -> V_18 -> V_529 = V_304 ;
}
return 0 ;
}
if ( ++ V_2 -> V_492 < V_530 )
return 0 ;
V_2 -> V_49 |= V_493 ;
F_291 ( V_2 ) ;
if ( V_528 )
F_80 ( V_531 , & V_2 -> V_55 ) ;
F_65 ( & V_2 -> V_30 -> V_45 , L_67 ) ;
F_65 ( & V_2 -> V_30 -> V_45 , L_68
L_69
L_70
L_71
L_72 ,
F_54 ( V_2 , V_516 ) ,
F_54 ( V_2 , V_532 ) ,
F_54 ( V_2 , V_533 + 0x3c ) ,
F_54 ( V_2 , V_534 + 0x3c ) ,
F_54 ( V_2 , V_535 + 0x3c ) ,
F_54 ( V_2 , V_536 + 0x3c ) ,
F_54 ( V_2 , V_537 + 0x3c ) ) ;
V_525 = F_54 ( V_2 , V_516 ) ;
if ( F_297 ( F_298 ( V_525 ) ) == 0x67 )
F_65 ( & V_2 -> V_30 -> V_45 ,
L_73
L_74 ) ;
V_526:
V_2 -> V_508 = ( V_55 == V_488 ) ? V_55 :
V_487 ;
if ( V_528 &&
! F_151 ( V_275 , & V_2 -> V_55 ) ) {
F_179 ( V_2 , F_288 , 0 ) ;
F_285 ( V_2 , V_514 , L_75 ) ;
}
return 1 ;
}
static void
V_318 ( struct V_505 * V_506 )
{
struct V_1 * V_2 = F_269 ( V_506 ,
struct V_1 , V_507 . V_506 ) ;
if ( F_31 ( V_275 , & V_2 -> V_55 ) )
goto V_538;
if ( F_296 ( V_2 ) )
return;
if ( V_2 -> V_257 . V_258 )
F_299 ( V_2 ) ;
V_538:
F_179 ( V_2 , V_318 , V_319 ) ;
}
static int F_300 ( struct V_29 * V_30 )
{
struct V_29 * V_539 ;
int V_485 = V_30 -> V_540 ;
while ( V_485 -- > 0 ) {
V_539 = F_301 ( F_302
( V_30 -> V_541 ) , V_30 -> V_541 -> V_542 ,
F_303 ( F_304 ( V_30 -> V_540 ) , V_485 ) ) ;
if ( ! V_539 )
continue;
if ( V_539 -> V_543 != V_321 ) {
F_305 ( V_539 ) ;
return 0 ;
}
F_305 ( V_539 ) ;
}
return 1 ;
}
static int F_306 ( struct V_29 * V_30 )
{
int V_57 , V_544 ;
struct V_1 * V_2 = F_187 ( V_30 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
V_30 -> V_545 = V_546 ;
V_57 = F_163 ( V_30 ) ;
if ( V_57 )
return V_57 ;
F_199 ( V_30 , V_323 ) ;
F_166 ( V_30 ) ;
F_202 ( V_30 ) ;
V_544 = F_300 ( V_30 ) ;
if ( F_55 ( V_2 ) )
return - V_53 ;
if ( V_2 -> V_114 != V_122 && V_544 ) {
V_2 -> V_219 = 1 ;
F_77 ( V_494 , & V_2 -> V_55 ) ;
F_104 ( V_2 , V_238 , V_503 ) ;
F_285 ( V_2 , V_514 , L_52 ) ;
}
F_58 ( V_2 ) ;
V_57 = V_2 -> V_123 -> V_314 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_279 ( V_2 ) ;
F_42 ( V_2 ) ;
if ( F_121 ( V_18 ) ) {
V_57 = F_137 ( V_2 ) ;
if ( V_57 ) {
F_182 ( V_2 , 1 ) ;
F_80 ( V_521 , & V_2 -> V_55 ) ;
F_34 ( V_18 ) ;
return V_57 ;
}
V_57 = F_119 ( V_2 , V_18 ) ;
if ( V_57 )
goto V_324;
F_79 ( V_18 , V_325 ) ;
}
V_324:
F_34 ( V_18 ) ;
return V_57 ;
}
static T_18 F_307 ( struct V_29 * V_30 ,
T_19 V_55 )
{
struct V_1 * V_2 = F_187 ( V_30 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
if ( V_55 == V_547 )
return V_548 ;
if ( V_55 == V_546 )
return V_549 ;
F_77 ( V_521 , & V_2 -> V_55 ) ;
F_32 ( V_18 ) ;
F_295 ( & V_2 -> V_507 ) ;
if ( F_121 ( V_18 ) )
F_136 ( V_2 , V_18 ) ;
F_143 ( V_2 ) ;
F_45 ( V_2 ) ;
F_80 ( V_275 , & V_2 -> V_55 ) ;
F_194 ( V_30 ) ;
F_185 ( V_30 ) ;
return V_550 ;
}
static T_18 F_308 ( struct V_29 * V_30 )
{
return F_306 ( V_30 ) ? V_548 :
V_549 ;
}
static void F_309 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_187 ( V_30 ) ;
F_310 ( V_30 ) ;
if ( F_54 ( V_2 , V_238 ) == V_239 &&
F_124 ( V_521 , & V_2 -> V_55 ) )
F_179 ( V_2 , V_318 ,
V_319 ) ;
}
static int
F_311 ( struct V_1 * V_2 )
{
int V_57 ;
V_57 = F_97 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_92 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_73 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_69 ( V_2 ) ;
V_57 = F_83 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_2 -> V_219 = 0 ;
return V_57 ;
}
static int
F_312 ( struct V_1 * V_2 , T_1 V_31 )
{
return - V_51 ;
}
static int
F_313 ( struct V_1 * V_2 , T_1 V_55 , T_1 V_551 )
{
return - V_51 ;
}
static T_20
F_314 ( struct V_137 * V_45 ,
struct V_552 * V_553 , const char * V_554 , T_21 V_438 )
{
struct V_1 * V_2 = F_315 ( V_45 ) ;
unsigned long V_555 ;
int V_81 = - V_53 ;
if ( ! ( V_2 -> V_182 & V_556 ) )
goto V_233;
if ( ! F_31 ( V_54 , & V_2 -> V_55 ) )
goto V_233;
if ( F_316 ( V_554 , 2 , & V_555 ) )
goto V_233;
if ( ! V_2 -> V_123 -> V_557 ( V_2 , ! ! V_555 ) )
V_81 = V_438 ;
V_233:
return V_81 ;
}
static T_20
F_317 ( struct V_137 * V_45 ,
struct V_552 * V_553 , char * V_554 )
{
struct V_1 * V_2 = F_315 ( V_45 ) ;
int V_558 = 0 ;
if ( V_2 -> V_182 & V_556 )
V_558 = ! ! ( V_2 -> V_49 & V_559 ) ;
return sprintf ( V_554 , L_76 , V_558 ) ;
}
static T_20
F_318 ( struct V_137 * V_45 ,
struct V_552 * V_553 , const char * V_554 , T_21 V_438 )
{
struct V_1 * V_2 = F_315 ( V_45 ) ;
unsigned long V_555 ;
if ( F_316 ( V_554 , 2 , & V_555 ) )
return - V_53 ;
if ( ! ! V_555 != ! ! ( V_2 -> V_49 & V_560 ) )
V_2 -> V_49 ^= V_560 ;
return V_438 ;
}
static T_20
F_319 ( struct V_137 * V_45 ,
struct V_552 * V_553 , char * V_554 )
{
struct V_1 * V_2 = F_315 ( V_45 ) ;
return sprintf ( V_554 , L_76 ,
! ! ( V_2 -> V_49 & V_560 ) ) ;
}
int F_320 ( struct V_17 * V_18 , T_2 V_561 , T_2 V_485 )
{
if ( ! V_170 && ! V_64 ) {
F_256 ( V_18 , L_77 ) ;
return - V_53 ;
}
if ( ( V_485 > V_561 ) || ( V_485 < 2 ) || ! F_321 ( V_485 ) ) {
F_256 ( V_18 , L_78
L_79 , V_561 ) ;
return - V_53 ;
}
return 0 ;
}
int F_322 ( struct V_1 * V_2 , T_2 V_103 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
int V_57 = 0 ;
if ( F_151 ( V_275 , & V_2 -> V_55 ) )
return - V_276 ;
F_32 ( V_18 ) ;
if ( F_121 ( V_18 ) )
F_123 ( V_2 , V_18 ) ;
F_143 ( V_2 ) ;
F_45 ( V_2 ) ;
if ( F_35 ( V_2 , V_103 ) ) {
F_256 ( V_18 , L_80 ) ;
F_39 ( V_2 ) ;
}
if ( F_121 ( V_18 ) ) {
V_57 = F_137 ( V_2 ) ;
if ( V_57 )
goto V_324;
V_57 = F_111 ( V_2 , V_18 ) ;
if ( V_57 )
goto V_324;
F_79 ( V_18 , V_325 ) ;
}
V_324:
F_34 ( V_18 ) ;
F_80 ( V_275 , & V_2 -> V_55 ) ;
return V_57 ;
}
static int
F_323 ( struct V_1 * V_2 , T_5 V_562 , T_2 * V_55 ,
T_2 * V_551 )
{
* V_551 = F_324 ( V_562 ) ;
* V_55 = F_298 ( V_562 ) ;
F_285 ( V_2 , V_514 , L_81 , * V_551 , * V_55 ) ;
if ( ! * V_55 ) {
* V_551 = V_563 ;
return 0 ;
} else if ( * V_55 > V_564 )
return - V_53 ;
if ( ( ! * V_551 ) || ( * V_551 > V_563 ) )
return - V_53 ;
return 0 ;
}
static T_20
F_325 ( struct V_137 * V_45 ,
struct V_552 * V_553 , const char * V_554 , T_21 V_438 )
{
struct V_1 * V_2 = F_315 ( V_45 ) ;
int V_20 = V_2 -> V_20 ;
T_5 V_562 ;
T_2 V_565 , V_566 ;
int V_57 ;
if ( V_2 -> V_114 == V_122 ) {
F_28 ( V_45 , L_82
L_83 ) ;
return - V_51 ;
}
if ( V_438 != sizeof( T_5 ) )
return V_93 ;
memcpy ( & V_562 , V_554 , sizeof( T_5 ) ) ;
V_57 = F_323 ( V_2 , V_562 , & V_565 , & V_566 ) ;
if ( V_57 )
return V_57 ;
if ( V_2 -> V_67 -> V_567 == V_565 )
return V_438 ;
F_120 () ;
if ( ! V_2 -> V_67 -> V_567 )
if ( F_151 ( V_568 , & V_2 -> V_55 ) ) {
F_122 () ;
return - V_276 ;
}
if ( F_31 ( V_275 , & V_2 -> V_55 ) ) {
V_57 = - V_41 ;
goto V_263;
}
if ( ! F_31 ( V_54 , & V_2 -> V_55 ) ) {
V_57 = F_149 ( V_2 -> V_18 , V_569 ) ;
if ( V_57 )
goto V_263;
F_77 ( V_570 , & V_2 -> V_55 ) ;
}
V_57 = F_326 ( V_2 , V_565 , V_566 ) ;
if ( ! V_57 ) {
V_57 = V_438 ;
V_2 -> V_67 -> V_567 = V_565 ;
}
if ( F_124 ( V_570 , & V_2 -> V_55 ) )
F_146 ( V_2 -> V_18 , V_20 ) ;
V_263:
if ( ! V_2 -> V_67 -> V_567 )
F_80 ( V_568 , & V_2 -> V_55 ) ;
F_122 () ;
return V_57 ;
}
static T_20
F_327 ( struct V_137 * V_45 ,
struct V_552 * V_553 , char * V_554 )
{
struct V_1 * V_2 = F_315 ( V_45 ) ;
return sprintf ( V_554 , L_76 , V_2 -> V_67 -> V_567 ) ;
}
static int
F_328 ( struct V_1 * V_2 ,
T_22 V_376 , T_21 V_14 )
{
T_21 V_571 = 4 ;
if ( ! ( V_2 -> V_49 & V_560 ) )
return - V_41 ;
if ( V_376 < V_572 ) {
if ( F_329 ( V_376 , V_573 ,
V_574 ) )
V_571 = 8 ;
else
return - V_53 ;
}
if ( ( V_14 != V_571 ) || ( V_376 & ( V_571 - 1 ) ) )
return - V_53 ;
return 0 ;
}
static T_20
F_330 ( struct V_575 * V_576 , struct V_577 * V_578 ,
struct V_579 * V_553 ,
char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
T_1 V_103 ;
T_12 V_580 ;
int V_81 ;
V_81 = F_328 ( V_2 , V_376 , V_14 ) ;
if ( V_81 != 0 )
return V_81 ;
if ( F_329 ( V_376 , V_573 , V_574 ) ) {
F_331 ( V_2 , V_376 , & V_580 ) ;
memcpy ( V_554 , & V_580 , V_14 ) ;
} else {
V_103 = F_54 ( V_2 , V_376 ) ;
memcpy ( V_554 , & V_103 , V_14 ) ;
}
return V_14 ;
}
static T_20
F_332 ( struct V_575 * V_576 , struct V_577 * V_578 ,
struct V_579 * V_553 ,
char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
T_1 V_103 ;
T_12 V_580 ;
int V_81 ;
V_81 = F_328 ( V_2 , V_376 , V_14 ) ;
if ( V_81 != 0 )
return V_81 ;
if ( F_329 ( V_376 , V_573 , V_574 ) ) {
memcpy ( & V_580 , V_554 , V_14 ) ;
F_333 ( V_2 , V_376 , V_580 ) ;
} else {
memcpy ( & V_103 , V_554 , V_14 ) ;
F_104 ( V_2 , V_376 , V_103 ) ;
}
return V_14 ;
}
static int
F_334 ( struct V_1 * V_2 ,
T_22 V_376 , T_21 V_14 )
{
if ( ! ( V_2 -> V_49 & V_560 ) )
return - V_41 ;
if ( ( V_14 != 8 ) || ( V_376 & 0x7 ) )
return - V_41 ;
return 0 ;
}
static T_20
F_335 ( struct V_575 * V_576 , struct V_577 * V_578 ,
struct V_579 * V_553 ,
char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
T_12 V_103 ;
int V_81 ;
V_81 = F_334 ( V_2 , V_376 , V_14 ) ;
if ( V_81 != 0 )
return V_81 ;
if ( F_336 ( V_2 , V_376 , & V_103 ) )
return - V_41 ;
memcpy ( V_554 , & V_103 , V_14 ) ;
return V_14 ;
}
static T_20
F_337 ( struct V_575 * V_576 , struct V_577 * V_578 ,
struct V_579 * V_553 ,
char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
T_12 V_103 ;
int V_81 ;
V_81 = F_334 ( V_2 , V_376 , V_14 ) ;
if ( V_81 != 0 )
return V_81 ;
memcpy ( & V_103 , V_554 , V_14 ) ;
if ( F_338 ( V_2 , V_376 , V_103 ) )
return - V_41 ;
return V_14 ;
}
static int
F_339 ( struct V_1 * V_2 ,
struct V_581 * V_582 , int V_13 )
{
T_2 V_583 , V_584 , V_585 ;
T_2 V_586 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_583 = V_582 [ V_36 ] . V_68 ;
V_586 = V_582 [ V_36 ] . V_225 ;
if ( V_583 >= V_83
|| V_586 >= V_83 )
return V_93 ;
if ( V_2 -> V_84 [ V_583 ] . type != V_110 )
return V_93 ;
if ( V_2 -> V_84 [ V_586 ] . type != V_110 )
return V_93 ;
V_584 = V_2 -> V_84 [ V_583 ] . V_95 ;
V_585 = V_2 -> V_84 [ V_586 ] . V_95 ;
if ( V_584 != V_585 )
return V_93 ;
}
return 0 ;
}
static T_20
F_340 ( struct V_575 * V_576 , struct V_577 * V_578 ,
struct V_579 * V_553 , char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
struct V_581 * V_582 ;
T_1 V_92 , V_587 , V_68 ;
int V_13 , V_588 , V_36 , V_81 ;
V_13 = V_14 / sizeof( struct V_581 ) ;
V_588 = V_14 % sizeof( struct V_581 ) ;
if ( V_588 )
return V_93 ;
V_582 = (struct V_581 * ) V_554 ;
V_81 = F_339 ( V_2 , V_582 , V_13 ) ;
if ( V_81 )
return V_81 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_582 [ V_36 ] . V_68 ;
V_587 = ! ! V_582 [ V_36 ] . V_587 ;
V_92 = V_2 -> V_84 [ V_68 ] . V_95 ;
V_81 = F_91 ( V_2 , V_92 ,
V_587 , V_68 ) ;
if ( V_81 )
return V_81 ;
}
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_582 [ V_36 ] . V_68 ;
V_92 = V_2 -> V_84 [ V_68 ] . V_95 ;
V_2 -> V_84 [ V_68 ] . V_224 = ! ! V_582 [ V_36 ] . V_587 ;
V_2 -> V_84 [ V_68 ] . V_225 = V_92 ;
}
return V_14 ;
}
static T_20
F_341 ( struct V_575 * V_576 , struct V_577 * V_578 ,
struct V_579 * V_553 , char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
struct V_581 V_582 [ V_83 ] ;
int V_36 ;
if ( V_14 != sizeof( V_582 ) )
return V_93 ;
for ( V_36 = 0 ; V_36 < V_83 ; V_36 ++ ) {
if ( V_2 -> V_84 [ V_36 ] . type != V_110 )
continue;
V_582 [ V_36 ] . V_587 = V_2 -> V_84 [ V_36 ] . V_224 ;
V_582 [ V_36 ] . V_225 = 0 ;
V_582 [ V_36 ] . V_68 = V_36 ;
}
memcpy ( V_554 , & V_582 , V_14 ) ;
return V_14 ;
}
static int
F_342 ( struct V_1 * V_2 ,
struct V_186 * V_187 , int V_13 )
{
T_1 V_114 ;
T_2 V_68 ;
int V_36 ;
V_114 = F_57 ( V_2 -> V_67 -> V_78 + V_106 ) ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_187 [ V_36 ] . V_68 ;
if ( V_68 >= V_83 )
return V_93 ;
if ( V_2 -> V_114 == V_104 )
if ( V_2 -> V_84 [ V_68 ] . type != V_110 )
return V_93 ;
switch ( V_187 [ V_36 ] . V_114 ) {
case V_220 :
if ( F_60 ( V_114 , V_68 ) !=
V_122 ) {
if ( V_187 [ V_36 ] . V_197 != 0 )
return V_93 ;
if ( V_187 [ V_36 ] . V_198 != 1 )
return V_93 ;
if ( V_187 [ V_36 ] . V_199 != 1 )
return V_93 ;
}
break;
case V_221 :
if ( ! F_343 ( V_187 [ V_36 ] . V_190 ) )
return V_93 ;
if ( ! V_187 [ V_36 ] . V_589 )
return V_93 ;
break;
case V_590 :
if ( ! V_187 [ V_36 ] . V_589 )
return V_93 ;
break;
default:
return V_93 ;
}
}
return 0 ;
}
static T_20
F_344 ( struct V_575 * V_575 , struct V_577 * V_578 ,
struct V_579 * V_553 , char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
struct V_186 * V_187 ;
struct V_85 * V_218 ;
int V_13 , V_588 , V_36 , V_81 ;
T_2 V_68 , V_114 = 0 ;
V_13 = V_14 / sizeof( struct V_186 ) ;
V_588 = V_14 % sizeof( struct V_186 ) ;
if ( V_588 )
return V_93 ;
V_187 = (struct V_186 * ) V_554 ;
V_81 = F_342 ( V_2 , V_187 , V_13 ) ;
if ( V_81 )
return V_81 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
if ( V_2 -> V_114 == V_104 )
if ( F_87 ( V_2 , & V_187 [ V_36 ] ) )
return V_93 ;
if ( V_2 -> V_67 -> V_68 != V_187 [ V_36 ] . V_68 )
continue;
V_114 = V_187 [ V_36 ] . V_114 ;
F_84 ( V_2 , & V_187 [ V_36 ] ) ;
V_187 [ V_36 ] . V_114 = V_114 ;
V_187 [ V_36 ] . V_68 = V_2 -> V_67 -> V_68 ;
switch ( V_187 [ V_36 ] . V_114 ) {
case V_220 :
F_81 ( V_2 , & V_187 [ V_36 ] ) ;
break;
case V_221 :
F_75 ( V_2 , & V_187 [ V_36 ] ) ;
break;
case V_590 :
V_187 [ V_36 ] . V_190 = 0 ;
F_75 ( V_2 , & V_187 [ V_36 ] ) ;
break;
}
}
if ( V_2 -> V_114 != V_104 )
goto V_263;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_187 [ V_36 ] . V_68 ;
V_218 = & V_2 -> V_84 [ V_68 ] ;
switch ( V_187 [ V_36 ] . V_114 ) {
case V_220 :
V_218 -> V_199 = V_187 [ V_36 ] . V_199 ;
V_218 -> V_198 = V_187 [ V_36 ] . V_198 ;
V_218 -> V_212 = V_187 [ V_36 ] . V_212 ;
V_218 -> V_197 = V_187 [ V_36 ] . V_197 ;
V_218 -> V_188 = V_187 [ V_36 ] . V_188 ;
break;
case V_221 :
V_218 -> V_191 = V_187 [ V_36 ] . V_190 ;
break;
case V_590 :
V_218 -> V_191 = 0 ;
break;
}
}
V_263:
return V_14 ;
}
static T_20
F_345 ( struct V_575 * V_575 , struct V_577 * V_578 ,
struct V_579 * V_553 , char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
struct V_186 V_187 [ V_83 ] ;
T_2 V_36 ;
if ( V_14 != sizeof( V_187 ) )
return V_93 ;
for ( V_36 = 0 ; V_36 < V_83 ; V_36 ++ ) {
if ( V_2 -> V_84 [ V_36 ] . type != V_110 )
continue;
V_187 [ V_36 ] . V_68 = V_36 ;
if ( F_84 ( V_2 , & V_187 [ V_36 ] ) )
return V_93 ;
}
memcpy ( V_554 , & V_187 , V_14 ) ;
return V_14 ;
}
static int
F_346 ( struct V_1 * V_2 ,
struct V_591 * V_592 , int V_13 )
{
T_2 V_68 , V_36 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_592 [ V_36 ] . V_68 ;
if ( V_68 >= V_83 )
return V_93 ;
if ( V_2 -> V_84 [ V_68 ] . type != V_110 )
return V_93 ;
if ( ! F_347 ( V_592 [ V_36 ] . V_97 ) ||
! F_347 ( V_592 [ V_36 ] . V_99 ) )
return V_93 ;
}
return 0 ;
}
static T_20
F_348 ( struct V_575 * V_575 , struct V_577 * V_578 ,
struct V_579 * V_553 , char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
struct V_175 V_176 ;
struct V_591 * V_592 ;
int V_36 , V_13 , V_588 , V_81 ;
T_2 V_68 ;
V_13 = V_14 / sizeof( struct V_591 ) ;
V_588 = V_14 % sizeof( struct V_591 ) ;
if ( V_588 )
return V_93 ;
V_592 = (struct V_591 * ) V_554 ;
V_81 = F_346 ( V_2 , V_592 , V_13 ) ;
if ( V_81 )
return V_81 ;
for ( V_36 = 0 ; V_36 < V_13 ; V_36 ++ ) {
V_68 = V_592 [ V_36 ] . V_68 ;
V_81 = F_74 ( V_2 , & V_176 , V_68 ) ;
if ( V_81 )
return V_81 ;
V_176 . V_68 = V_68 ;
V_176 . V_222 = V_592 [ V_36 ] . V_97 ;
V_176 . V_223 = V_592 [ V_36 ] . V_99 ;
V_81 = F_90 ( V_2 , & V_176 ) ;
if ( V_81 )
return V_81 ;
V_2 -> V_84 [ V_36 ] . V_97 = V_176 . V_222 ;
V_2 -> V_84 [ V_36 ] . V_99 = V_176 . V_223 ;
}
return V_14 ;
}
static T_20
F_349 ( struct V_575 * V_575 , struct V_577 * V_578 ,
struct V_579 * V_553 , char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
struct V_175 V_176 ;
struct V_591 V_592 [ V_83 ] ;
int V_36 , V_81 ;
if ( V_14 != sizeof( V_592 ) )
return V_93 ;
for ( V_36 = 0 ; V_36 < V_83 ; V_36 ++ ) {
if ( V_2 -> V_84 [ V_36 ] . type != V_110 )
continue;
V_81 = F_74 ( V_2 , & V_176 , V_36 ) ;
if ( V_81 )
return V_81 ;
V_592 [ V_36 ] . V_68 = V_36 ;
V_592 [ V_36 ] . V_114 = ( T_2 ) V_176 . V_114 ;
V_592 [ V_36 ] . V_593 = V_176 . V_178 ;
V_592 [ V_36 ] . V_594 = V_176 . V_182 ;
V_592 [ V_36 ] . V_97 = V_176 . V_222 ;
V_592 [ V_36 ] . V_99 = V_176 . V_223 ;
V_592 [ V_36 ] . V_595 = V_176 . V_180 ;
V_592 [ V_36 ] . V_596 = V_176 . V_181 ;
}
memcpy ( V_554 , & V_592 , V_14 ) ;
return V_14 ;
}
static T_20
F_350 ( struct V_575 * V_575 , struct V_577 * V_578 ,
struct V_579 * V_553 , char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
struct V_597 V_598 ;
int V_81 ;
if ( V_14 != sizeof( struct V_597 ) )
return V_93 ;
if ( V_376 >= V_83 )
return V_93 ;
memset ( & V_598 , 0 , V_14 ) ;
V_81 = F_351 ( V_2 , V_376 , V_599 ,
& V_598 . V_600 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_351 ( V_2 , V_376 , V_601 ,
& V_598 . V_602 ) ;
if ( V_81 )
return V_81 ;
memcpy ( V_554 , & V_598 , V_14 ) ;
return V_14 ;
}
static T_20
F_352 ( struct V_575 * V_575 , struct V_577 * V_578 ,
struct V_579 * V_553 , char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
struct V_597 V_603 ;
int V_81 ;
if ( V_14 != sizeof( struct V_597 ) )
return V_93 ;
if ( V_376 >= V_89 )
return V_93 ;
memset ( & V_603 , 0 , V_14 ) ;
V_81 = F_353 ( V_2 , V_376 , V_599 ,
& V_603 . V_600 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_353 ( V_2 , V_376 , V_601 ,
& V_603 . V_602 ) ;
if ( V_81 )
return V_81 ;
memcpy ( V_554 , & V_603 , V_14 ) ;
return V_14 ;
}
static T_20
F_354 ( struct V_575 * V_575 , struct V_577 * V_578 ,
struct V_579 * V_553 , char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
int V_81 ;
if ( V_376 >= V_89 )
return V_93 ;
V_81 = F_355 ( V_2 , V_604 , V_376 ,
V_599 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_355 ( V_2 , V_604 , V_376 ,
V_601 ) ;
if ( V_81 )
return V_81 ;
return V_14 ;
}
static T_20
F_356 ( struct V_575 * V_575 , struct V_577 * V_578 ,
struct V_579 * V_553 , char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
int V_81 ;
if ( V_376 >= V_83 )
return V_93 ;
V_81 = F_355 ( V_2 , V_605 , V_376 ,
V_599 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_355 ( V_2 , V_605 , V_376 ,
V_601 ) ;
if ( V_81 )
return V_81 ;
return V_14 ;
}
static T_20
F_357 ( struct V_575 * V_575 , struct V_577 * V_578 ,
struct V_579 * V_553 , char * V_554 , T_22 V_376 , T_21 V_14 )
{
struct V_137 * V_45 = F_269 ( V_578 , struct V_137 , V_578 ) ;
struct V_1 * V_2 = F_315 ( V_45 ) ;
struct V_606 V_607 [ V_83 ] ;
struct V_79 * V_80 ;
int V_36 , V_81 ;
if ( V_14 != sizeof( V_607 ) )
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
V_607 [ V_36 ] . V_68 = V_80 [ V_36 ] . V_92 ;
V_607 [ V_36 ] . V_608 = V_80 [ V_36 ] . type ;
V_607 [ V_36 ] . V_593 = V_80 [ V_36 ] . V_96 ;
V_607 [ V_36 ] . V_97 = V_80 [ V_36 ] . V_98 ;
V_607 [ V_36 ] . V_99 = V_80 [ V_36 ] . V_100 ;
memcpy ( & V_607 [ V_36 ] . V_609 , & V_80 [ V_36 ] . V_610 , V_40 ) ;
}
memcpy ( V_554 , & V_607 , V_14 ) ;
F_9 ( V_80 ) ;
return V_14 ;
}
static void
F_140 ( struct V_1 * V_2 )
{
struct V_137 * V_45 = & V_2 -> V_30 -> V_45 ;
if ( V_2 -> V_182 & V_556 )
if ( F_358 ( V_45 , & V_611 ) )
F_28 ( V_45 ,
L_84 ) ;
}
static void
F_144 ( struct V_1 * V_2 )
{
struct V_137 * V_45 = & V_2 -> V_30 -> V_45 ;
if ( V_2 -> V_182 & V_556 )
F_359 ( V_45 , & V_611 ) ;
}
static void
F_181 ( struct V_1 * V_2 )
{
struct V_137 * V_45 = & V_2 -> V_30 -> V_45 ;
if ( F_360 ( V_45 , & V_612 ) )
F_37 ( V_45 , L_85 ) ;
if ( V_2 -> V_114 == V_122 )
return;
if ( F_358 ( V_45 , & V_613 ) )
F_37 ( V_45 , L_86 ) ;
if ( F_358 ( V_45 , & V_614 ) )
F_37 ( V_45 , L_87 ) ;
if ( F_360 ( V_45 , & V_615 ) )
F_37 ( V_45 , L_88 ) ;
if ( F_360 ( V_45 , & V_616 ) )
F_37 ( V_45 , L_89 ) ;
if ( F_360 ( V_45 , & V_617 ) )
F_37 ( V_45 , L_90 ) ;
if ( ! ( V_2 -> V_49 & V_156 ) )
return;
if ( F_360 ( V_45 , & V_618 ) )
F_37 ( V_45 , L_91 ) ;
if ( V_2 -> V_114 != V_104 )
return;
if ( F_360 ( V_45 , & V_619 ) )
F_37 ( V_45 , L_92 ) ;
if ( F_360 ( V_45 , & V_620 ) )
F_37 ( V_45 , L_93 ) ;
if ( F_360 ( V_45 , & V_621 ) )
F_37 ( V_45 , L_94 ) ;
}
static void
F_191 ( struct V_1 * V_2 )
{
struct V_137 * V_45 = & V_2 -> V_30 -> V_45 ;
F_361 ( V_45 , & V_612 ) ;
if ( V_2 -> V_114 == V_122 )
return;
F_359 ( V_45 , & V_613 ) ;
F_359 ( V_45 , & V_614 ) ;
F_361 ( V_45 , & V_615 ) ;
F_361 ( V_45 , & V_616 ) ;
F_361 ( V_45 , & V_617 ) ;
if ( ! ( V_2 -> V_49 & V_156 ) )
return;
F_361 ( V_45 , & V_618 ) ;
if ( V_2 -> V_114 != V_104 )
return;
F_361 ( V_45 , & V_619 ) ;
F_361 ( V_45 , & V_620 ) ;
F_361 ( V_45 , & V_621 ) ;
}
static void
F_362 ( struct V_1 * V_2 ,
struct V_17 * V_45 , unsigned long V_622 )
{
struct V_623 * V_624 ;
V_624 = F_363 ( V_45 ) ;
if ( ! V_624 )
return;
F_364 (indev) {
switch ( V_622 ) {
case V_325 :
F_365 ( V_2 ,
V_625 -> V_626 , V_627 ) ;
break;
case V_194 :
F_365 ( V_2 ,
V_625 -> V_626 , V_628 ) ;
break;
default:
break;
}
} F_366 ( V_624 ) ;
F_367 ( V_624 ) ;
}
static void
F_79 ( struct V_17 * V_18 , unsigned long V_622 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
struct V_17 * V_45 ;
T_5 V_192 ;
F_362 ( V_2 , V_18 , V_622 ) ;
F_368 (vid, adapter->vlans, VLAN_N_VID) {
V_45 = F_369 ( V_18 , V_192 ) ;
if ( ! V_45 )
continue;
F_362 ( V_2 , V_45 , V_622 ) ;
}
}
static int F_370 ( struct V_629 * V_630 ,
unsigned long V_622 , void * V_631 )
{
struct V_1 * V_2 ;
struct V_17 * V_45 = (struct V_17 * ) V_631 ;
V_632:
if ( V_45 == NULL )
goto V_324;
if ( V_45 -> V_633 & V_634 ) {
V_45 = F_371 ( V_45 ) ;
goto V_632;
}
if ( ! F_372 ( V_45 ) )
goto V_324;
V_2 = F_30 ( V_45 ) ;
if ( ! V_2 )
goto V_324;
if ( ! F_31 ( V_54 , & V_2 -> V_55 ) )
goto V_324;
F_362 ( V_2 , V_45 , V_622 ) ;
V_324:
return V_635 ;
}
static int
F_373 ( struct V_629 * V_630 ,
unsigned long V_622 , void * V_631 )
{
struct V_1 * V_2 ;
struct V_17 * V_45 ;
struct V_636 * V_625 = (struct V_636 * ) V_631 ;
V_45 = V_625 -> V_637 ? V_625 -> V_637 -> V_45 : NULL ;
V_632:
if ( V_45 == NULL )
goto V_324;
if ( V_45 -> V_633 & V_634 ) {
V_45 = F_371 ( V_45 ) ;
goto V_632;
}
if ( ! F_372 ( V_45 ) )
goto V_324;
V_2 = F_30 ( V_45 ) ;
if ( ! V_2 )
goto V_324;
if ( ! F_31 ( V_54 , & V_2 -> V_55 ) )
goto V_324;
switch ( V_622 ) {
case V_325 :
F_365 ( V_2 , V_625 -> V_626 , V_627 ) ;
break;
case V_194 :
F_365 ( V_2 , V_625 -> V_626 , V_628 ) ;
break;
default:
break;
}
V_324:
return V_635 ;
}
static void
F_79 ( struct V_17 * V_45 , unsigned long V_622 )
{ }
static int T_23 F_374 ( void )
{
int V_81 ;
F_375 ( V_638 L_95 , V_639 ) ;
V_522 = F_376 ( L_96 ) ;
if ( V_522 == NULL ) {
F_375 ( V_640 L_97 ) ;
return - V_21 ;
}
#ifdef F_377
F_378 ( & V_641 ) ;
F_379 ( & V_642 ) ;
#endif
V_81 = F_380 ( & V_643 ) ;
if ( V_81 ) {
#ifdef F_377
F_381 ( & V_642 ) ;
F_382 ( & V_641 ) ;
#endif
F_383 ( V_522 ) ;
}
return V_81 ;
}
static void T_24 F_384 ( void )
{
F_385 ( & V_643 ) ;
#ifdef F_377
F_381 ( & V_642 ) ;
F_382 ( & V_641 ) ;
#endif
F_383 ( V_522 ) ;
}
