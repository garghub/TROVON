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
static int F_38 ( struct V_9 * V_10 , struct V_63 * V_64 )
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
V_67 = F_43 ( & V_70 , V_12 -> V_21 , & V_68 ) ;
V_49 = F_44 ( V_10 , & V_70 , V_67 ) ;
if ( F_45 ( V_49 ) ) {
V_30 = F_46 ( V_49 ) ;
V_49 = NULL ;
goto V_81;
}
V_2 = F_47 ( V_10 , V_49 , V_64 ) ;
if ( V_2 != NULL ) {
struct V_13 * V_14 = V_13 ( V_2 ) ;
V_14 -> V_15 = F_1 ( V_2 ,
& V_66 -> V_73 ,
& V_66 -> V_72 ) ;
V_70 . V_5 = V_66 -> V_72 ;
V_30 = F_48 ( V_10 , V_2 , & V_70 , V_12 -> V_21 , V_12 -> V_82 ) ;
V_30 = F_49 ( V_30 ) ;
}
V_81:
F_50 ( V_49 ) ;
return V_30 ;
}
static void F_51 ( struct V_63 * V_64 )
{
F_52 ( & F_53 ( V_64 ) -> V_83 ) ;
F_54 ( F_39 ( V_64 ) -> V_84 ) ;
}
static void F_55 ( struct V_9 * V_10 , struct V_1 * V_85 )
{
const struct V_25 * V_86 ;
struct V_1 * V_2 ;
struct V_69 V_70 ;
struct V_32 * V_32 = F_10 ( F_56 ( V_85 ) -> V_33 ) ;
struct V_9 * V_87 = V_32 -> V_88 . V_89 ;
struct V_48 * V_49 ;
if ( V_13 ( V_85 ) -> V_90 == V_91 )
return;
if ( ! F_57 ( V_85 ) )
return;
V_2 = F_58 ( V_87 , V_85 ) ;
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
F_59 ( V_85 , F_42 ( & V_70 ) ) ;
V_49 = F_44 ( V_87 , & V_70 , NULL ) ;
if ( ! F_45 ( V_49 ) ) {
F_60 ( V_2 , V_49 ) ;
F_48 ( V_87 , V_2 , & V_70 , NULL , 0 ) ;
F_34 ( V_92 ) ;
F_34 ( V_93 ) ;
return;
}
F_54 ( V_2 ) ;
}
static struct V_9 * F_61 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
const struct V_13 * V_14 = V_13 ( V_2 ) ;
const struct V_25 * V_94 = F_8 ( V_2 ) ;
struct V_63 * V_64 ;
struct V_9 * V_95 ;
V_64 = F_62 ( V_10 , V_14 -> V_19 , & V_94 -> V_4 ,
& V_94 -> V_5 , F_16 ( V_2 ) ) ;
if ( V_64 ) {
V_95 = F_63 ( V_10 , V_2 , V_64 ) ;
if ( ! V_95 )
F_64 ( V_64 ) ;
return V_95 ;
}
V_95 = F_14 ( F_65 ( V_10 ) , & V_35 ,
& V_94 -> V_4 , V_14 -> V_19 ,
& V_94 -> V_5 , F_15 ( V_14 -> V_18 ) ,
F_16 ( V_2 ) ) ;
if ( V_95 != NULL ) {
if ( V_95 -> V_36 != V_37 ) {
F_21 ( V_95 ) ;
return V_95 ;
}
F_17 ( F_18 ( V_95 ) ) ;
return NULL ;
}
return V_10 ;
}
static int F_66 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_63 * V_64 ;
struct V_96 * V_97 ;
struct V_65 * V_66 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
const T_4 V_98 = F_67 ( V_2 ) -> V_99 ;
struct V_100 * V_101 = F_68 ( V_2 ) ;
if ( V_2 -> V_102 == F_40 ( V_103 ) )
return F_69 ( V_10 , V_2 ) ;
if ( ! F_57 ( V_2 ) )
return 0 ;
if ( F_70 ( V_10 , V_98 ) ) {
V_101 -> V_104 = V_105 ;
goto V_106;
}
V_101 -> V_104 = V_107 ;
if ( F_71 ( V_10 ) )
goto V_106;
if ( F_72 ( V_10 ) && F_73 ( V_10 ) > 1 )
goto V_106;
V_64 = F_74 ( & V_108 , V_10 ) ;
if ( V_64 == NULL )
goto V_106;
if ( F_75 ( V_64 , F_24 ( V_10 ) , V_2 ) )
goto V_109;
V_97 = F_53 ( V_64 ) ;
if ( F_76 ( V_10 , V_97 , V_2 ) )
goto V_109;
if ( F_77 ( V_10 , V_2 , V_64 ) )
goto V_109;
V_66 = F_39 ( V_64 ) ;
V_66 -> V_72 = F_8 ( V_2 ) -> V_4 ;
V_66 -> V_73 = F_8 ( V_2 ) -> V_5 ;
V_66 -> V_110 = V_111 ;
if ( F_78 ( V_10 , V_2 , F_79 ( V_2 ) ) ||
V_12 -> V_112 . V_113 . V_114 || V_12 -> V_112 . V_113 . V_115 ||
V_12 -> V_112 . V_113 . V_116 || V_12 -> V_112 . V_113 . V_117 ) {
F_80 ( & V_2 -> V_118 ) ;
V_66 -> V_84 = V_2 ;
}
V_66 -> V_76 = V_10 -> V_119 ;
if ( ! V_10 -> V_119 &&
F_81 ( & V_66 -> V_72 ) & V_120 )
V_66 -> V_76 = F_16 ( V_2 ) ;
V_97 -> V_121 = V_101 -> V_122 ;
V_97 -> V_123 = V_97 -> V_121 ;
V_97 -> V_124 = F_6 ( V_2 ) ;
V_97 -> V_125 = V_97 -> V_124 ;
V_97 -> V_126 = V_98 ;
if ( F_38 ( V_10 , V_64 ) )
goto V_109;
F_82 ( V_10 , V_64 , V_127 ) ;
return 0 ;
V_109:
F_83 ( V_64 ) ;
V_106:
F_34 ( V_58 ) ;
return - 1 ;
}
static struct V_9 * F_84 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_63 * V_64 ,
struct V_48 * V_49 )
{
struct V_65 * V_66 = F_39 ( V_64 ) ;
struct V_11 * V_128 , * V_12 = F_4 ( V_10 ) ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
struct V_9 * V_133 ;
if ( V_2 -> V_102 == F_40 ( V_103 ) ) {
V_133 = F_85 ( V_10 , V_2 , V_64 , V_49 ) ;
if ( V_133 == NULL )
return NULL ;
V_132 = (struct V_131 * ) V_133 ;
V_130 = F_86 ( V_133 ) ;
V_130 -> V_134 = & V_132 -> V_135 ;
V_128 = F_4 ( V_133 ) ;
memcpy ( V_128 , V_12 , sizeof( struct V_11 ) ) ;
V_128 -> V_4 = V_133 -> V_136 ;
F_30 ( V_133 ) -> V_137 = & V_138 ;
V_133 -> V_139 = V_140 ;
V_128 -> V_141 = NULL ;
V_128 -> V_21 = NULL ;
V_128 -> V_142 = F_16 ( V_2 ) ;
V_128 -> V_143 = F_8 ( V_2 ) -> V_144 ;
F_32 ( V_133 , F_30 ( V_133 ) -> V_55 ) ;
return V_133 ;
}
if ( F_72 ( V_10 ) )
goto V_145;
if ( V_49 == NULL ) {
struct V_3 * V_67 , V_68 ;
struct V_69 V_70 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 . V_71 = V_7 ;
V_70 . V_5 = V_66 -> V_72 ;
V_67 = F_43 ( & V_70 , V_12 -> V_21 , & V_68 ) ;
V_70 . V_4 = V_66 -> V_73 ;
V_70 . V_75 = V_10 -> V_119 ;
V_70 . V_77 = V_66 -> V_78 ;
V_70 . V_79 = F_40 ( V_66 -> V_80 ) ;
F_87 ( V_10 , F_42 ( & V_70 ) ) ;
V_49 = F_44 ( V_10 , & V_70 , V_67 ) ;
if ( F_45 ( V_49 ) )
goto V_41;
}
V_133 = F_88 ( V_10 , V_64 , V_2 ) ;
if ( V_133 == NULL )
goto V_146;
F_89 ( V_133 , V_49 , NULL , NULL ) ;
V_133 -> V_147 = V_49 -> V_33 -> V_148 & ~ ( V_149 |
V_150 ) ;
V_132 = (struct V_131 * ) V_133 ;
V_130 = F_86 ( V_133 ) ;
V_130 -> V_134 = & V_132 -> V_135 ;
V_128 = F_4 ( V_133 ) ;
memcpy ( V_128 , V_12 , sizeof( struct V_11 ) ) ;
V_133 -> V_16 = V_66 -> V_72 ;
V_128 -> V_4 = V_66 -> V_73 ;
V_133 -> V_136 = V_66 -> V_73 ;
V_133 -> V_119 = V_66 -> V_76 ;
V_130 -> V_151 = NULL ;
V_128 -> V_112 . V_152 = V_12 -> V_112 . V_152 ;
V_128 -> V_141 = NULL ;
if ( V_66 -> V_84 != NULL ) {
V_128 -> V_141 = F_90 ( V_66 -> V_84 , V_153 ) ;
F_91 ( V_66 -> V_84 ) ;
V_66 -> V_84 = NULL ;
if ( V_128 -> V_141 )
F_92 ( V_128 -> V_141 , V_133 ) ;
}
V_128 -> V_21 = NULL ;
V_128 -> V_142 = F_16 ( V_2 ) ;
V_128 -> V_143 = F_8 ( V_2 ) -> V_144 ;
if ( V_12 -> V_21 != NULL )
V_128 -> V_21 = F_93 ( V_133 , V_12 -> V_21 ) ;
F_30 ( V_133 ) -> V_154 = 0 ;
if ( V_128 -> V_21 != NULL )
F_30 ( V_133 ) -> V_154 = ( V_128 -> V_21 -> V_155 +
V_128 -> V_21 -> V_156 ) ;
F_32 ( V_133 , F_31 ( V_49 ) ) ;
V_130 -> V_157 = V_130 -> V_158 = V_159 ;
V_130 -> V_160 = V_159 ;
if ( F_94 ( V_10 , V_133 ) < 0 ) {
F_95 ( V_133 ) ;
F_35 ( V_133 ) ;
goto V_41;
}
F_96 ( V_133 , NULL ) ;
return V_133 ;
V_145:
F_23 ( F_65 ( V_10 ) , V_161 ) ;
V_146:
F_50 ( V_49 ) ;
V_41:
F_23 ( F_65 ( V_10 ) , V_162 ) ;
return NULL ;
}
static int F_97 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_1 * V_163 = NULL ;
if ( V_2 -> V_102 == F_40 ( V_103 ) )
return V_140 ( V_10 , V_2 ) ;
if ( F_98 ( V_10 , V_2 ) )
goto V_164;
if ( V_12 -> V_112 . V_152 )
V_163 = F_90 ( V_2 , V_153 ) ;
if ( V_10 -> V_36 == V_165 ) {
if ( F_99 ( V_10 , V_2 , V_13 ( V_2 ) , V_2 -> V_6 ) )
goto V_166;
if ( V_163 ) {
F_100 ( V_163 ) ;
}
return 0 ;
}
if ( V_10 -> V_36 == V_167 ) {
struct V_9 * V_95 = F_61 ( V_10 , V_2 ) ;
if ( V_95 == NULL )
goto V_164;
if ( V_95 != V_10 ) {
if ( F_101 ( V_10 , V_95 , V_2 ) )
goto V_166;
if ( V_163 != NULL )
F_100 ( V_163 ) ;
return 0 ;
}
}
if ( F_102 ( V_10 , V_2 , V_13 ( V_2 ) , V_2 -> V_6 ) )
goto V_166;
if ( V_163 ) {
F_100 ( V_163 ) ;
}
return 0 ;
V_166:
F_55 ( V_10 , V_2 ) ;
V_164:
if ( V_163 != NULL )
F_100 ( V_163 ) ;
F_54 ( V_2 ) ;
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
F_68 ( V_2 ) -> V_122 = F_19 ( V_14 ) ;
F_68 ( V_2 ) -> V_170 = V_14 -> V_90 ;
if ( F_106 ( V_2 ) )
F_68 ( V_2 ) -> V_171 = V_172 ;
else
F_68 ( V_2 ) -> V_171 = F_107 ( V_2 ) ;
V_10 = F_108 ( & V_35 , V_2 ,
V_14 -> V_19 , V_14 -> V_18 ,
F_16 ( V_2 ) ) ;
if ( V_10 == NULL ) {
F_109 ( L_2
L_3 ) ;
goto V_173;
}
if ( V_10 -> V_36 == V_37 ) {
F_109 ( L_4 ) ;
F_17 ( F_18 ( V_10 ) ) ;
goto V_173;
}
V_168 = F_24 ( V_10 ) -> V_174 ;
if ( V_14 -> V_175 && ( V_168 == 0 || V_14 -> V_175 < V_168 ) ) {
F_109 ( L_5 ,
V_14 -> V_175 , V_168 ) ;
goto V_176;
}
if ( ! F_110 ( V_10 , V_177 , V_2 ) )
goto V_176;
return F_111 ( V_10 , V_2 , 1 ) ? - 1 : 0 ;
V_173:
if ( ! F_110 ( NULL , V_177 , V_2 ) )
goto V_169;
if ( V_14 -> V_90 != V_91 ) {
F_68 ( V_2 ) -> V_104 =
V_178 ;
F_55 ( V_10 , V_2 ) ;
}
V_169:
F_54 ( V_2 ) ;
return 0 ;
V_176:
F_37 ( V_10 ) ;
goto V_169;
}
static int F_112 ( struct V_9 * V_10 , struct V_179 * V_180 ,
int V_181 )
{
struct V_182 * V_183 = (struct V_182 * ) V_180 ;
struct V_184 * V_185 = F_30 ( V_10 ) ;
struct V_129 * V_186 = F_86 ( V_10 ) ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_28 * V_29 = F_24 ( V_10 ) ;
struct V_3 * V_4 = NULL , * V_67 , V_68 ;
struct V_69 V_70 ;
struct V_48 * V_49 ;
int V_187 ;
int V_30 ;
V_29 -> V_188 = V_189 ;
if ( V_181 < V_190 )
return - V_191 ;
if ( V_183 -> V_192 != V_111 )
return - V_193 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
if ( V_12 -> V_194 ) {
V_70 . V_74 = V_183 -> V_195 & V_196 ;
F_113 ( V_70 . V_74 ) ;
if ( V_70 . V_74 & V_197 ) {
struct V_198 * V_74 ;
V_74 = F_114 ( V_10 , V_70 . V_74 ) ;
if ( V_74 == NULL )
return - V_191 ;
F_115 ( V_74 ) ;
}
}
if ( F_116 ( & V_183 -> V_199 ) )
V_183 -> V_199 . V_200 [ 15 ] = 1 ;
V_187 = F_81 ( & V_183 -> V_199 ) ;
if ( V_187 & V_201 )
return - V_202 ;
if ( V_187 & V_120 ) {
if ( V_181 >= sizeof( struct V_182 ) &&
V_183 -> V_203 ) {
if ( V_10 -> V_119 &&
V_10 -> V_119 != V_183 -> V_203 )
return - V_191 ;
V_10 -> V_119 = V_183 -> V_203 ;
}
if ( ! V_10 -> V_119 )
return - V_191 ;
}
V_10 -> V_16 = V_183 -> V_199 ;
V_12 -> V_204 = V_70 . V_74 ;
if ( V_187 == V_205 ) {
T_5 V_206 = V_185 -> V_154 ;
struct V_207 sin ;
F_117 ( V_10 , L_6 ) ;
if ( F_118 ( V_10 ) )
return - V_202 ;
sin . V_208 = V_209 ;
sin . V_210 = V_183 -> V_211 ;
sin . V_212 . V_213 = V_183 -> V_199 . V_17 [ 3 ] ;
V_185 -> V_137 = & V_138 ;
V_10 -> V_139 = V_140 ;
V_30 = F_119 ( V_10 , (struct V_179 * ) & sin , sizeof( sin ) ) ;
if ( V_30 ) {
V_185 -> V_154 = V_206 ;
V_185 -> V_137 = & V_214 ;
V_10 -> V_139 = F_97 ;
goto V_215;
}
V_12 -> V_4 = V_10 -> V_136 ;
return V_30 ;
}
if ( ! F_116 ( & V_10 -> V_136 ) )
V_4 = & V_10 -> V_136 ;
V_70 . V_71 = V_7 ;
V_70 . V_5 = V_10 -> V_16 ;
V_70 . V_4 = V_4 ? * V_4 : V_12 -> V_4 ;
V_70 . V_75 = V_10 -> V_119 ;
V_70 . V_77 = V_183 -> V_211 ;
V_70 . V_79 = V_186 -> V_216 ;
F_87 ( V_10 , F_42 ( & V_70 ) ) ;
V_67 = F_43 ( & V_70 , V_12 -> V_21 , & V_68 ) ;
V_49 = F_44 ( V_10 , & V_70 , V_67 ) ;
if ( F_45 ( V_49 ) ) {
V_30 = F_46 ( V_49 ) ;
goto V_215;
}
if ( V_4 == NULL ) {
V_4 = & V_70 . V_4 ;
V_10 -> V_136 = * V_4 ;
}
V_12 -> V_4 = * V_4 ;
V_186 -> V_160 = V_159 ;
F_89 ( V_10 , V_49 , NULL , NULL ) ;
V_185 -> V_154 = 0 ;
if ( V_12 -> V_21 != NULL )
V_185 -> V_154 = ( V_12 -> V_21 -> V_156 +
V_12 -> V_21 -> V_155 ) ;
V_186 -> V_217 = V_183 -> V_211 ;
F_120 ( V_10 , V_56 ) ;
V_30 = F_121 ( & V_218 , V_10 ) ;
if ( V_30 )
goto V_219;
V_29 -> V_220 = F_7 ( V_12 -> V_4 . V_17 ,
V_10 -> V_16 . V_17 ,
V_186 -> V_216 ,
V_186 -> V_217 ) ;
V_30 = F_122 ( V_10 ) ;
if ( V_30 )
goto V_219;
return 0 ;
V_219:
F_120 ( V_10 , V_40 ) ;
F_123 ( V_10 ) ;
V_215:
V_186 -> V_217 = 0 ;
V_10 -> V_147 = 0 ;
return V_30 ;
}
static int F_124 ( struct V_9 * V_10 )
{
static T_6 V_221 ;
int V_30 = F_125 ( V_10 , V_221 ) ;
if ( V_30 == 0 ) {
if ( F_126 ( ! V_221 ) )
V_221 = 1 ;
F_30 ( V_10 ) -> V_137 = & V_214 ;
}
return V_30 ;
}
static void F_127 ( struct V_9 * V_10 )
{
F_128 ( V_10 ) ;
F_129 ( V_10 ) ;
}
static int T_7 F_130 ( struct V_32 * V_32 )
{
if ( V_35 . V_222 == NULL )
return - V_223 ;
return F_131 ( & V_32 -> V_88 . V_89 , V_224 ,
V_225 , V_7 , V_32 ) ;
}
static void T_8 F_132 ( struct V_32 * V_32 )
{
F_133 ( V_32 -> V_88 . V_89 ) ;
}
static int T_9 F_134 ( void )
{
int V_30 = F_135 ( & V_226 , 1 ) ;
if ( V_30 != 0 )
goto V_41;
V_30 = F_136 ( & V_227 , V_7 ) ;
if ( V_30 != 0 )
goto V_228;
F_137 ( & V_229 ) ;
V_30 = F_138 ( & V_230 ) ;
if ( V_30 != 0 )
goto V_231;
V_41:
return V_30 ;
V_231:
F_139 ( & V_227 , V_7 ) ;
F_140 ( & V_229 ) ;
V_228:
F_141 ( & V_226 ) ;
goto V_41;
}
static void T_10 F_142 ( void )
{
F_143 ( & V_230 ) ;
F_139 ( & V_227 , V_7 ) ;
F_140 ( & V_229 ) ;
F_141 ( & V_226 ) ;
}
