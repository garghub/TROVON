static inline T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_3 * V_5 )
{
return F_2 ( V_4 , V_5 , V_2 -> V_6 , V_7 , V_2 -> V_8 ) ;
}
static inline void F_3 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_13 * V_14 = V_13 ( V_2 ) ;
F_5 ( V_2 ) ;
V_14 -> V_15 = F_1 ( V_2 , & V_12 -> V_4 , & V_10 -> V_16 ) ;
}
static inline T_2 F_6 ( struct V_1 * V_2 )
{
return F_7 ( F_8 ( V_2 ) -> V_5 . V_17 ,
F_8 ( V_2 ) -> V_4 . V_17 ,
V_13 ( V_2 ) -> V_18 ,
V_13 ( V_2 ) -> V_19 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_20 * V_21 ,
T_3 type , T_3 V_22 , int V_23 , T_4 V_24 )
{
const struct V_25 * V_26 = ( const struct V_25 * ) V_2 -> V_27 ;
const struct V_13 * V_14 = (struct V_13 * ) ( V_2 -> V_27 + V_23 ) ;
struct V_28 * V_29 ;
struct V_11 * V_12 ;
struct V_9 * V_10 ;
int V_30 ;
T_2 V_31 ;
struct V_32 * V_32 = F_10 ( V_2 -> V_33 ) ;
if ( V_2 -> V_6 < V_23 + sizeof( * V_14 ) ||
V_2 -> V_6 < V_23 + F_11 ( V_14 ) ) {
F_12 ( V_32 , F_13 ( V_2 -> V_33 ) ,
V_34 ) ;
return;
}
V_10 = F_14 ( V_32 , & V_35 ,
& V_26 -> V_5 , V_14 -> V_18 ,
& V_26 -> V_4 , F_15 ( V_14 -> V_19 ) ,
F_16 ( V_2 ) ) ;
if ( ! V_10 ) {
F_12 ( V_32 , F_13 ( V_2 -> V_33 ) ,
V_34 ) ;
return;
}
if ( V_10 -> V_36 == V_37 ) {
F_17 ( F_18 ( V_10 ) ) ;
return;
}
V_31 = F_19 ( V_14 ) ;
if ( V_10 -> V_36 == V_38 )
return F_20 ( V_10 , V_31 ) ;
F_21 ( V_10 ) ;
if ( F_22 ( V_10 ) )
F_23 ( V_32 , V_39 ) ;
if ( V_10 -> V_36 == V_40 )
goto V_41;
V_29 = F_24 ( V_10 ) ;
if ( ( 1 << V_10 -> V_36 ) & ~ ( V_42 | V_43 ) &&
! F_25 ( V_31 , V_29 -> V_44 , V_29 -> V_45 ) ) {
F_23 ( V_32 , V_46 ) ;
goto V_41;
}
V_12 = F_4 ( V_10 ) ;
if ( type == V_47 ) {
struct V_48 * V_49 = F_26 ( V_10 , V_12 -> V_50 ) ;
if ( V_49 )
V_49 -> V_51 -> V_52 ( V_49 , V_10 , V_2 ) ;
goto V_41;
}
if ( type == V_53 ) {
struct V_48 * V_49 = NULL ;
if ( ! F_27 ( V_10 ) )
goto V_41;
if ( F_22 ( V_10 ) )
goto V_41;
if ( ( 1 << V_10 -> V_36 ) & ( V_43 | V_54 ) )
goto V_41;
V_49 = F_28 ( V_10 , F_29 ( V_24 ) ) ;
if ( ! V_49 )
goto V_41;
if ( F_30 ( V_10 ) -> V_55 > F_31 ( V_49 ) )
F_32 ( V_10 , F_31 ( V_49 ) ) ;
goto V_41;
}
F_33 ( type , V_22 , & V_30 ) ;
switch ( V_10 -> V_36 ) {
case V_56 :
case V_57 :
if ( ! F_22 ( V_10 ) ) {
F_34 ( V_58 ) ;
V_10 -> V_59 = V_30 ;
V_10 -> V_60 ( V_10 ) ;
F_35 ( V_10 ) ;
} else
V_10 -> V_61 = V_30 ;
goto V_41;
}
if ( ! F_22 ( V_10 ) && V_12 -> V_62 ) {
V_10 -> V_59 = V_30 ;
V_10 -> V_60 ( V_10 ) ;
} else
V_10 -> V_61 = V_30 ;
V_41:
F_36 ( V_10 ) ;
F_37 ( V_10 ) ;
}
static int F_38 ( const struct V_9 * V_10 , struct V_63 * V_64 )
{
struct V_65 * V_66 = F_39 ( V_64 ) ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_1 * V_2 ;
struct V_3 * V_67 , V_68 ;
struct V_69 V_70 ;
int V_30 = - 1 ;
struct V_48 * V_49 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 . V_71 = V_7 ;
V_70 . V_5 = V_66 -> V_72 ;
V_70 . V_4 = V_66 -> V_73 ;
V_70 . V_74 = 0 ;
V_70 . V_75 = V_66 -> V_76 ;
V_70 . V_77 = V_66 -> V_78 ;
V_70 . V_79 = F_40 ( V_66 -> V_80 ) ;
F_41 ( V_64 , F_42 ( & V_70 ) ) ;
F_43 () ;
V_67 = F_44 ( & V_70 , F_45 ( V_12 -> V_21 ) , & V_68 ) ;
F_46 () ;
V_49 = F_47 ( V_10 , & V_70 , V_67 ) ;
if ( F_48 ( V_49 ) ) {
V_30 = F_49 ( V_49 ) ;
V_49 = NULL ;
goto V_81;
}
V_2 = F_50 ( V_10 , V_49 , V_64 ) ;
if ( V_2 != NULL ) {
struct V_13 * V_14 = V_13 ( V_2 ) ;
V_14 -> V_15 = F_1 ( V_2 ,
& V_66 -> V_73 ,
& V_66 -> V_72 ) ;
V_70 . V_5 = V_66 -> V_72 ;
F_43 () ;
V_30 = F_51 ( V_10 , V_2 , & V_70 , F_45 ( V_12 -> V_21 ) ,
V_12 -> V_82 ) ;
F_46 () ;
V_30 = F_52 ( V_30 ) ;
}
V_81:
F_53 ( V_49 ) ;
return V_30 ;
}
static void F_54 ( struct V_63 * V_64 )
{
F_55 ( & F_56 ( V_64 ) -> V_83 ) ;
F_57 ( F_39 ( V_64 ) -> V_84 ) ;
}
static void F_58 ( const struct V_9 * V_10 , struct V_1 * V_85 )
{
const struct V_25 * V_86 ;
struct V_1 * V_2 ;
struct V_69 V_70 ;
struct V_32 * V_32 = F_10 ( F_59 ( V_85 ) -> V_33 ) ;
struct V_9 * V_87 = V_32 -> V_88 . V_89 ;
struct V_48 * V_49 ;
if ( V_13 ( V_85 ) -> V_90 == V_91 )
return;
if ( ! F_60 ( V_85 ) )
return;
V_2 = F_61 ( V_87 , V_85 ) ;
if ( V_2 == NULL )
return;
V_86 = F_8 ( V_85 ) ;
V_13 ( V_2 ) -> V_15 = F_1 ( V_2 , & V_86 -> V_4 ,
& V_86 -> V_5 ) ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 . V_5 = V_86 -> V_4 ;
V_70 . V_4 = V_86 -> V_5 ;
V_70 . V_71 = V_7 ;
V_70 . V_75 = F_16 ( V_85 ) ;
V_70 . V_77 = V_13 ( V_2 ) -> V_18 ;
V_70 . V_79 = V_13 ( V_2 ) -> V_19 ;
F_62 ( V_85 , F_42 ( & V_70 ) ) ;
V_49 = F_47 ( V_87 , & V_70 , NULL ) ;
if ( ! F_48 ( V_49 ) ) {
F_63 ( V_2 , V_49 ) ;
F_51 ( V_87 , V_2 , & V_70 , NULL , 0 ) ;
F_34 ( V_92 ) ;
F_34 ( V_93 ) ;
return;
}
F_57 ( V_2 ) ;
}
static int F_64 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_63 * V_64 ;
struct V_94 * V_95 ;
struct V_65 * V_66 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
const T_4 V_96 = F_65 ( V_2 ) -> V_97 ;
struct V_98 * V_99 = F_66 ( V_2 ) ;
if ( V_2 -> V_100 == F_40 ( V_101 ) )
return F_67 ( V_10 , V_2 ) ;
if ( ! F_60 ( V_2 ) )
return 0 ;
if ( F_68 ( V_10 , V_96 ) ) {
V_99 -> V_102 = V_103 ;
goto V_104;
}
V_99 -> V_102 = V_105 ;
if ( F_69 ( V_10 ) )
goto V_104;
if ( F_70 ( V_10 ) && F_71 ( V_10 ) > 1 )
goto V_104;
V_64 = F_72 ( & V_106 , V_10 , true ) ;
if ( V_64 == NULL )
goto V_104;
if ( F_73 ( V_64 , F_24 ( V_10 ) , V_2 ) )
goto V_107;
V_95 = F_56 ( V_64 ) ;
if ( F_74 ( V_10 , V_95 , V_2 ) )
goto V_107;
if ( F_75 ( V_10 , V_2 , V_64 ) )
goto V_107;
V_66 = F_39 ( V_64 ) ;
V_66 -> V_72 = F_8 ( V_2 ) -> V_4 ;
V_66 -> V_73 = F_8 ( V_2 ) -> V_5 ;
V_66 -> V_108 = V_109 ;
if ( F_76 ( V_10 , V_2 , F_77 ( V_2 ) ) ||
V_12 -> V_110 . V_111 . V_112 || V_12 -> V_110 . V_111 . V_113 ||
V_12 -> V_110 . V_111 . V_114 || V_12 -> V_110 . V_111 . V_115 ) {
F_78 ( & V_2 -> V_116 ) ;
V_66 -> V_84 = V_2 ;
}
V_66 -> V_76 = V_10 -> V_117 ;
if ( ! V_10 -> V_117 &&
F_79 ( & V_66 -> V_72 ) & V_118 )
V_66 -> V_76 = F_16 ( V_2 ) ;
V_95 -> V_119 = V_99 -> V_120 ;
V_95 -> V_121 = V_95 -> V_119 ;
V_95 -> V_122 = F_6 ( V_2 ) ;
V_95 -> V_123 = V_95 -> V_122 ;
V_95 -> V_124 = V_96 ;
if ( F_38 ( V_10 , V_64 ) )
goto V_107;
F_80 ( V_10 , V_64 , V_125 ) ;
return 0 ;
V_107:
F_81 ( V_64 ) ;
V_104:
F_34 ( V_58 ) ;
return - 1 ;
}
static struct V_9 * F_82 ( const struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_63 * V_64 ,
struct V_48 * V_49 ,
struct V_63 * V_126 ,
bool * V_127 )
{
struct V_65 * V_66 = F_39 ( V_64 ) ;
struct V_11 * V_128 ;
const struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_129 * V_21 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
struct V_9 * V_134 ;
if ( V_2 -> V_100 == F_40 ( V_101 ) ) {
V_134 = F_83 ( V_10 , V_2 , V_64 , V_49 ,
V_126 , V_127 ) ;
if ( V_134 == NULL )
return NULL ;
V_133 = (struct V_132 * ) V_134 ;
V_131 = F_84 ( V_134 ) ;
V_131 -> V_135 = & V_133 -> V_136 ;
V_128 = F_4 ( V_134 ) ;
memcpy ( V_128 , V_12 , sizeof( struct V_11 ) ) ;
V_128 -> V_4 = V_134 -> V_137 ;
F_30 ( V_134 ) -> V_138 = & V_139 ;
V_134 -> V_140 = V_141 ;
V_128 -> V_142 = NULL ;
V_128 -> V_21 = NULL ;
V_128 -> V_143 = F_16 ( V_2 ) ;
V_128 -> V_144 = F_8 ( V_2 ) -> V_145 ;
F_32 ( V_134 , F_30 ( V_134 ) -> V_55 ) ;
return V_134 ;
}
if ( F_70 ( V_10 ) )
goto V_146;
if ( ! V_49 ) {
struct V_69 V_70 ;
V_49 = F_85 ( V_10 , & V_70 , V_64 , V_7 ) ;
if ( ! V_49 )
goto V_41;
}
V_134 = F_86 ( V_10 , V_64 , V_2 ) ;
if ( V_134 == NULL )
goto V_147;
F_87 ( V_134 , V_49 , NULL , NULL ) ;
V_134 -> V_148 = V_49 -> V_33 -> V_149 & ~ ( V_150 |
V_151 ) ;
V_133 = (struct V_132 * ) V_134 ;
V_131 = F_84 ( V_134 ) ;
V_131 -> V_135 = & V_133 -> V_136 ;
V_128 = F_4 ( V_134 ) ;
memcpy ( V_128 , V_12 , sizeof( struct V_11 ) ) ;
V_134 -> V_16 = V_66 -> V_72 ;
V_128 -> V_4 = V_66 -> V_73 ;
V_134 -> V_137 = V_66 -> V_73 ;
V_134 -> V_117 = V_66 -> V_76 ;
V_131 -> V_152 = NULL ;
V_128 -> V_110 . V_153 = V_12 -> V_110 . V_153 ;
V_128 -> V_142 = NULL ;
V_128 -> V_21 = NULL ;
V_128 -> V_143 = F_16 ( V_2 ) ;
V_128 -> V_144 = F_8 ( V_2 ) -> V_145 ;
V_21 = F_45 ( V_12 -> V_21 ) ;
if ( V_21 ) {
V_21 = F_88 ( V_134 , V_21 ) ;
F_89 ( V_128 -> V_21 , V_21 ) ;
}
F_30 ( V_134 ) -> V_154 = 0 ;
if ( V_21 )
F_30 ( V_134 ) -> V_154 = V_21 -> V_155 +
V_21 -> V_156 ;
F_32 ( V_134 , F_31 ( V_49 ) ) ;
V_131 -> V_157 = V_131 -> V_158 = V_159 ;
V_131 -> V_160 = V_159 ;
if ( F_90 ( V_10 , V_134 ) < 0 ) {
F_91 ( V_134 ) ;
F_35 ( V_134 ) ;
goto V_41;
}
* V_127 = F_92 ( V_134 , F_93 ( V_126 ) ) ;
if ( * V_127 && V_66 -> V_84 ) {
V_128 -> V_142 = F_94 ( V_66 -> V_84 , V_161 ) ;
F_95 ( V_66 -> V_84 ) ;
V_66 -> V_84 = NULL ;
if ( V_128 -> V_142 )
F_96 ( V_128 -> V_142 , V_134 ) ;
}
return V_134 ;
V_146:
F_23 ( F_97 ( V_10 ) , V_162 ) ;
V_147:
F_53 ( V_49 ) ;
V_41:
F_23 ( F_97 ( V_10 ) , V_163 ) ;
return NULL ;
}
static int F_98 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_1 * V_164 = NULL ;
if ( V_2 -> V_100 == F_40 ( V_101 ) )
return V_141 ( V_10 , V_2 ) ;
if ( F_99 ( V_10 , V_2 ) )
goto V_165;
if ( V_12 -> V_110 . V_153 )
V_164 = F_94 ( V_2 , V_161 ) ;
if ( V_10 -> V_36 == V_166 ) {
if ( F_100 ( V_10 , V_2 , V_13 ( V_2 ) , V_2 -> V_6 ) )
goto V_167;
if ( V_164 ) {
F_101 ( V_164 ) ;
}
return 0 ;
}
if ( F_102 ( V_10 , V_2 , V_13 ( V_2 ) , V_2 -> V_6 ) )
goto V_167;
if ( V_164 ) {
F_101 ( V_164 ) ;
}
return 0 ;
V_167:
F_58 ( V_10 , V_2 ) ;
V_165:
if ( V_164 != NULL )
F_101 ( V_164 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 ;
struct V_9 * V_10 ;
int V_168 ;
if ( F_104 ( V_2 ) )
goto V_169;
if ( F_1 ( V_2 , & F_8 ( V_2 ) -> V_4 ,
& F_8 ( V_2 ) -> V_5 ) ) {
F_105 ( L_1 ) ;
goto V_169;
}
V_14 = V_13 ( V_2 ) ;
F_66 ( V_2 ) -> V_120 = F_19 ( V_14 ) ;
F_66 ( V_2 ) -> V_170 = V_14 -> V_90 ;
if ( F_106 ( V_2 ) )
F_66 ( V_2 ) -> V_171 = V_172 ;
else
F_66 ( V_2 ) -> V_171 = F_107 ( V_2 ) ;
V_173:
V_10 = F_108 ( & V_35 , V_2 ,
V_14 -> V_19 , V_14 -> V_18 ,
F_16 ( V_2 ) ) ;
if ( ! V_10 ) {
F_109 ( L_2
L_3 ) ;
goto V_174;
}
if ( V_10 -> V_36 == V_37 ) {
F_109 ( L_4 ) ;
F_17 ( F_18 ( V_10 ) ) ;
goto V_174;
}
if ( V_10 -> V_36 == V_38 ) {
struct V_63 * V_64 = F_110 ( V_10 ) ;
struct V_9 * V_175 ;
V_10 = V_64 -> V_176 ;
if ( F_111 ( V_10 -> V_36 != V_177 ) ) {
F_112 ( V_10 , V_64 ) ;
goto V_173;
}
F_113 ( V_10 ) ;
V_175 = F_114 ( V_10 , V_2 , V_64 ) ;
if ( ! V_175 ) {
F_115 ( V_64 ) ;
goto V_178;
}
if ( V_175 == V_10 ) {
F_115 ( V_64 ) ;
} else if ( F_116 ( V_10 , V_175 , V_2 ) ) {
F_58 ( V_10 , V_2 ) ;
goto V_178;
} else {
F_37 ( V_10 ) ;
return 0 ;
}
}
V_168 = F_24 ( V_10 ) -> V_179 ;
if ( V_14 -> V_180 && ( V_168 == 0 || V_14 -> V_180 < V_168 ) ) {
F_109 ( L_5 ,
V_14 -> V_180 , V_168 ) ;
goto V_178;
}
if ( ! F_117 ( V_10 , V_181 , V_2 ) )
goto V_178;
return F_118 ( V_10 , V_2 , 1 ) ? - 1 : 0 ;
V_174:
if ( ! F_117 ( NULL , V_181 , V_2 ) )
goto V_169;
if ( V_14 -> V_90 != V_91 ) {
F_66 ( V_2 ) -> V_102 =
V_182 ;
F_58 ( V_10 , V_2 ) ;
}
V_169:
F_57 ( V_2 ) ;
return 0 ;
V_178:
F_37 ( V_10 ) ;
goto V_169;
}
static int F_119 ( struct V_9 * V_10 , struct V_183 * V_184 ,
int V_185 )
{
struct V_186 * V_187 = (struct V_186 * ) V_184 ;
struct V_188 * V_189 = F_30 ( V_10 ) ;
struct V_130 * V_190 = F_84 ( V_10 ) ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_28 * V_29 = F_24 ( V_10 ) ;
struct V_3 * V_4 = NULL , * V_67 , V_68 ;
struct V_129 * V_21 ;
struct V_69 V_70 ;
struct V_48 * V_49 ;
int V_191 ;
int V_30 ;
V_29 -> V_192 = V_193 ;
if ( V_185 < V_194 )
return - V_195 ;
if ( V_187 -> V_196 != V_109 )
return - V_197 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
if ( V_12 -> V_198 ) {
V_70 . V_74 = V_187 -> V_199 & V_200 ;
F_120 ( V_70 . V_74 ) ;
if ( V_70 . V_74 & V_201 ) {
struct V_202 * V_74 ;
V_74 = F_121 ( V_10 , V_70 . V_74 ) ;
if ( V_74 == NULL )
return - V_195 ;
F_122 ( V_74 ) ;
}
}
if ( F_123 ( & V_187 -> V_203 ) )
V_187 -> V_203 . V_204 [ 15 ] = 1 ;
V_191 = F_79 ( & V_187 -> V_203 ) ;
if ( V_191 & V_205 )
return - V_206 ;
if ( V_191 & V_118 ) {
if ( V_185 >= sizeof( struct V_186 ) &&
V_187 -> V_207 ) {
if ( V_10 -> V_117 &&
V_10 -> V_117 != V_187 -> V_207 )
return - V_195 ;
V_10 -> V_117 = V_187 -> V_207 ;
}
if ( ! V_10 -> V_117 )
return - V_195 ;
}
V_10 -> V_16 = V_187 -> V_203 ;
V_12 -> V_208 = V_70 . V_74 ;
if ( V_191 == V_209 ) {
T_5 V_210 = V_189 -> V_154 ;
struct V_211 sin ;
F_124 ( V_10 , L_6 ) ;
if ( F_125 ( V_10 ) )
return - V_206 ;
sin . V_212 = V_213 ;
sin . V_214 = V_187 -> V_215 ;
sin . V_216 . V_217 = V_187 -> V_203 . V_17 [ 3 ] ;
V_189 -> V_138 = & V_139 ;
V_10 -> V_140 = V_141 ;
V_30 = F_126 ( V_10 , (struct V_183 * ) & sin , sizeof( sin ) ) ;
if ( V_30 ) {
V_189 -> V_154 = V_210 ;
V_189 -> V_138 = & V_218 ;
V_10 -> V_140 = F_98 ;
goto V_219;
}
V_12 -> V_4 = V_10 -> V_137 ;
return V_30 ;
}
if ( ! F_123 ( & V_10 -> V_137 ) )
V_4 = & V_10 -> V_137 ;
V_70 . V_71 = V_7 ;
V_70 . V_5 = V_10 -> V_16 ;
V_70 . V_4 = V_4 ? * V_4 : V_12 -> V_4 ;
V_70 . V_75 = V_10 -> V_117 ;
V_70 . V_77 = V_187 -> V_215 ;
V_70 . V_79 = V_190 -> V_220 ;
F_127 ( V_10 , F_42 ( & V_70 ) ) ;
V_21 = F_128 ( V_12 -> V_21 , F_22 ( V_10 ) ) ;
V_67 = F_44 ( & V_70 , V_21 , & V_68 ) ;
V_49 = F_47 ( V_10 , & V_70 , V_67 ) ;
if ( F_48 ( V_49 ) ) {
V_30 = F_49 ( V_49 ) ;
goto V_219;
}
if ( V_4 == NULL ) {
V_4 = & V_70 . V_4 ;
V_10 -> V_137 = * V_4 ;
}
V_12 -> V_4 = * V_4 ;
V_190 -> V_160 = V_159 ;
F_87 ( V_10 , V_49 , NULL , NULL ) ;
V_189 -> V_154 = 0 ;
if ( V_21 )
V_189 -> V_154 = V_21 -> V_156 + V_21 -> V_155 ;
V_190 -> V_221 = V_187 -> V_215 ;
F_129 ( V_10 , V_56 ) ;
V_30 = F_130 ( & V_222 , V_10 ) ;
if ( V_30 )
goto V_223;
V_29 -> V_224 = F_7 ( V_12 -> V_4 . V_17 ,
V_10 -> V_16 . V_17 ,
V_190 -> V_220 ,
V_190 -> V_221 ) ;
V_30 = F_131 ( V_10 ) ;
if ( V_30 )
goto V_223;
return 0 ;
V_223:
F_129 ( V_10 , V_40 ) ;
F_132 ( V_10 ) ;
V_219:
V_190 -> V_221 = 0 ;
V_10 -> V_148 = 0 ;
return V_30 ;
}
static int F_133 ( struct V_9 * V_10 )
{
static T_6 V_225 ;
int V_30 = F_134 ( V_10 , V_225 ) ;
if ( V_30 == 0 ) {
if ( F_111 ( ! V_225 ) )
V_225 = 1 ;
F_30 ( V_10 ) -> V_138 = & V_218 ;
}
return V_30 ;
}
static void F_135 ( struct V_9 * V_10 )
{
F_136 ( V_10 ) ;
F_137 ( V_10 ) ;
}
static int T_7 F_138 ( struct V_32 * V_32 )
{
if ( V_35 . V_226 == NULL )
return - V_227 ;
return F_139 ( & V_32 -> V_88 . V_89 , V_228 ,
V_229 , V_7 , V_32 ) ;
}
static void T_8 F_140 ( struct V_32 * V_32 )
{
F_141 ( V_32 -> V_88 . V_89 ) ;
}
static int T_9 F_142 ( void )
{
int V_30 = F_143 ( & V_230 , 1 ) ;
if ( V_30 != 0 )
goto V_41;
V_30 = F_144 ( & V_231 , V_7 ) ;
if ( V_30 != 0 )
goto V_232;
F_145 ( & V_233 ) ;
V_30 = F_146 ( & V_234 ) ;
if ( V_30 != 0 )
goto V_235;
V_41:
return V_30 ;
V_235:
F_147 ( & V_231 , V_7 ) ;
F_148 ( & V_233 ) ;
V_232:
F_149 ( & V_230 ) ;
goto V_41;
}
static void T_10 F_150 ( void )
{
F_151 ( & V_234 ) ;
F_147 ( & V_231 , V_7 ) ;
F_148 ( & V_233 ) ;
F_149 ( & V_230 ) ;
}
