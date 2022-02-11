static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return NULL ;
}
static void F_2 ( struct V_2 * V_3 )
{
if ( V_3 -> V_6 != V_7 ) {
if ( F_3 ( V_3 ) -> V_8 == & V_9 ) {
V_10 . V_11 ( V_3 ) ;
return;
}
F_4 () ;
F_5 ( V_3 , NULL ) ;
F_6 () ;
}
}
static T_1 T_2 F_7 ( int V_12 ,
const struct V_4 * V_13 ,
const struct V_4 * V_14 ,
T_3 V_15 )
{
return F_8 ( V_13 , V_14 , V_12 , V_16 , V_15 ) ;
}
static T_4 F_9 ( const struct V_17 * V_18 )
{
return F_10 ( F_11 ( V_18 ) -> V_14 . V_19 ,
F_11 ( V_18 ) -> V_13 . V_19 ,
F_12 ( V_18 ) -> V_20 ,
F_12 ( V_18 ) -> V_21 ) ;
}
static int F_13 ( struct V_2 * V_3 , struct V_22 * V_23 ,
int V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) V_23 ;
struct V_27 * V_28 = F_14 ( V_3 ) ;
struct V_29 * V_30 = F_3 ( V_3 ) ;
struct V_31 * V_32 = F_15 ( V_3 ) ;
struct V_33 * V_34 = F_16 ( V_3 ) ;
struct V_4 * V_13 = NULL , * V_35 , V_36 ;
struct V_37 * V_38 ;
struct V_39 V_40 ;
struct V_41 * V_42 ;
int V_43 ;
int V_44 ;
if ( V_24 < V_45 )
return - V_46 ;
if ( V_26 -> V_47 != V_48 )
return - V_49 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
if ( V_32 -> V_50 ) {
V_40 . V_51 = V_26 -> V_52 & V_53 ;
F_17 ( V_40 . V_51 ) ;
if ( V_40 . V_51 & V_54 ) {
struct V_55 * V_51 ;
V_51 = F_18 ( V_3 , V_40 . V_51 ) ;
if ( V_51 == NULL )
return - V_46 ;
V_26 -> V_56 = V_51 -> V_42 ;
F_19 ( V_51 ) ;
}
}
if( F_20 ( & V_26 -> V_56 ) )
V_26 -> V_56 . V_57 [ 15 ] = 0x1 ;
V_43 = F_21 ( & V_26 -> V_56 ) ;
if( V_43 & V_58 )
return - V_59 ;
if ( V_43 & V_60 ) {
if ( V_24 >= sizeof( struct V_25 ) &&
V_26 -> V_61 ) {
if ( V_3 -> V_62 &&
V_3 -> V_62 != V_26 -> V_61 )
return - V_46 ;
V_3 -> V_62 = V_26 -> V_61 ;
}
if ( ! V_3 -> V_62 )
return - V_46 ;
}
if ( V_34 -> V_63 . V_64 &&
! F_22 ( & V_32 -> V_14 , & V_26 -> V_56 ) ) {
V_34 -> V_63 . V_65 = 0 ;
V_34 -> V_63 . V_64 = 0 ;
V_34 -> V_66 = 0 ;
}
V_32 -> V_14 = V_26 -> V_56 ;
V_32 -> V_67 = V_40 . V_51 ;
if ( V_43 == V_68 ) {
T_5 V_69 = V_30 -> V_70 ;
struct V_71 sin ;
F_23 ( V_3 , L_1 ) ;
if ( F_24 ( V_3 ) )
return - V_59 ;
sin . V_72 = V_73 ;
sin . V_74 = V_26 -> V_75 ;
sin . V_76 . V_77 = V_26 -> V_56 . V_19 [ 3 ] ;
V_30 -> V_8 = & V_9 ;
V_3 -> V_78 = V_79 ;
#ifdef F_25
V_34 -> V_80 = & V_81 ;
#endif
V_44 = F_26 ( V_3 , (struct V_22 * ) & sin , sizeof( sin ) ) ;
if ( V_44 ) {
V_30 -> V_70 = V_69 ;
V_30 -> V_8 = & V_82 ;
V_3 -> V_78 = V_83 ;
#ifdef F_25
V_34 -> V_80 = & V_84 ;
#endif
goto V_85;
} else {
F_27 ( V_28 -> V_86 , & V_32 -> V_13 ) ;
F_27 ( V_28 -> V_87 ,
& V_32 -> V_88 ) ;
}
return V_44 ;
}
if ( ! F_20 ( & V_32 -> V_88 ) )
V_13 = & V_32 -> V_88 ;
V_40 . V_89 = V_16 ;
V_40 . V_14 = V_32 -> V_14 ;
V_40 . V_13 = V_13 ? * V_13 : V_32 -> V_13 ;
V_40 . V_90 = V_3 -> V_62 ;
V_40 . V_91 = V_3 -> V_92 ;
V_40 . V_93 = V_26 -> V_75 ;
V_40 . V_94 = V_28 -> V_95 ;
V_35 = F_28 ( & V_40 , V_32 -> V_96 , & V_36 ) ;
F_29 ( V_3 , F_30 ( & V_40 ) ) ;
V_42 = F_31 ( V_3 , & V_40 , V_35 , true ) ;
if ( F_32 ( V_42 ) ) {
V_44 = F_33 ( V_42 ) ;
goto V_85;
}
if ( V_13 == NULL ) {
V_13 = & V_40 . V_13 ;
V_32 -> V_88 = * V_13 ;
}
V_32 -> V_13 = * V_13 ;
V_28 -> V_87 = V_97 ;
V_3 -> V_98 = V_99 ;
F_34 ( V_3 , V_42 , NULL , NULL ) ;
V_38 = (struct V_37 * ) V_42 ;
if ( V_100 . V_101 &&
! V_34 -> V_63 . V_64 &&
F_22 ( & V_38 -> V_102 . V_5 , & V_32 -> V_14 ) ) {
struct V_103 * V_104 = F_35 ( V_38 ) ;
if ( V_104 ) {
F_36 ( V_104 ) ;
if ( ( T_5 ) F_37 () - V_104 -> V_105 <= V_106 ) {
V_34 -> V_63 . V_64 = V_104 -> V_105 ;
V_34 -> V_63 . V_65 = V_104 -> V_107 ;
}
}
}
V_30 -> V_70 = 0 ;
if ( V_32 -> V_96 )
V_30 -> V_70 = ( V_32 -> V_96 -> V_108 +
V_32 -> V_96 -> V_109 ) ;
V_34 -> V_63 . V_110 = V_111 - sizeof( struct V_112 ) - sizeof( struct V_113 ) ;
V_28 -> V_114 = V_26 -> V_75 ;
F_38 ( V_3 , V_115 ) ;
V_44 = F_39 ( & V_100 , V_3 ) ;
if ( V_44 )
goto V_116;
if ( ! V_34 -> V_66 )
V_34 -> V_66 = F_10 ( V_32 -> V_13 . V_19 ,
V_32 -> V_14 . V_19 ,
V_28 -> V_95 ,
V_28 -> V_114 ) ;
V_44 = F_40 ( V_3 ) ;
if ( V_44 )
goto V_116;
return 0 ;
V_116:
F_38 ( V_3 , V_7 ) ;
F_41 ( V_3 ) ;
V_85:
V_28 -> V_114 = 0 ;
V_3 -> V_117 = 0 ;
return V_44 ;
}
static void F_42 ( struct V_17 * V_18 , struct V_118 * V_96 ,
T_6 type , T_6 V_119 , int V_120 , T_7 V_121 )
{
const struct V_113 * V_122 = ( const struct V_113 * ) V_18 -> V_123 ;
const struct V_112 * V_124 = (struct V_112 * ) ( V_18 -> V_123 + V_120 ) ;
struct V_31 * V_32 ;
struct V_2 * V_3 ;
int V_44 ;
struct V_33 * V_34 ;
T_4 V_125 ;
struct V_126 * V_126 = F_43 ( V_18 -> V_127 ) ;
V_3 = F_44 ( V_126 , & V_128 , & V_122 -> V_14 ,
V_124 -> V_20 , & V_122 -> V_13 , V_124 -> V_21 , V_18 -> V_127 -> V_129 ) ;
if ( V_3 == NULL ) {
F_45 ( V_126 , F_46 ( V_18 -> V_127 ) ,
V_130 ) ;
return;
}
if ( V_3 -> V_6 == V_131 ) {
F_47 ( F_48 ( V_3 ) ) ;
return;
}
F_49 ( V_3 ) ;
if ( F_50 ( V_3 ) )
F_51 ( V_126 , V_132 ) ;
if ( V_3 -> V_6 == V_7 )
goto V_133;
if ( F_11 ( V_18 ) -> V_134 < F_15 ( V_3 ) -> V_135 ) {
F_51 ( V_126 , V_136 ) ;
goto V_133;
}
V_34 = F_16 ( V_3 ) ;
V_125 = F_52 ( V_124 -> V_125 ) ;
if ( V_3 -> V_6 != V_137 &&
! F_53 ( V_125 , V_34 -> V_138 , V_34 -> V_139 ) ) {
F_51 ( V_126 , V_140 ) ;
goto V_133;
}
V_32 = F_15 ( V_3 ) ;
if ( type == V_141 ) {
struct V_41 * V_42 ;
if ( F_50 ( V_3 ) )
goto V_133;
if ( ( 1 << V_3 -> V_6 ) & ( V_142 | V_143 ) )
goto V_133;
V_42 = F_54 ( V_3 , V_32 -> V_144 ) ;
if ( V_42 == NULL ) {
struct V_27 * V_28 = F_14 ( V_3 ) ;
struct V_39 V_40 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_89 = V_16 ;
V_40 . V_14 = V_32 -> V_14 ;
V_40 . V_13 = V_32 -> V_13 ;
V_40 . V_90 = V_3 -> V_62 ;
V_40 . V_91 = V_3 -> V_92 ;
V_40 . V_93 = V_28 -> V_114 ;
V_40 . V_94 = V_28 -> V_95 ;
F_55 ( V_18 , F_30 ( & V_40 ) ) ;
V_42 = F_31 ( V_3 , & V_40 , NULL , false ) ;
if ( F_32 ( V_42 ) ) {
V_3 -> V_145 = - F_33 ( V_42 ) ;
goto V_133;
}
} else
F_56 ( V_42 ) ;
if ( F_3 ( V_3 ) -> V_146 > F_57 ( V_42 ) ) {
F_58 ( V_3 , F_57 ( V_42 ) ) ;
F_59 ( V_3 ) ;
}
F_60 ( V_42 ) ;
goto V_133;
}
F_61 ( type , V_119 , & V_44 ) ;
switch ( V_3 -> V_6 ) {
struct V_147 * V_148 , * * V_149 ;
case V_137 :
if ( F_50 ( V_3 ) )
goto V_133;
V_148 = F_62 ( V_3 , & V_149 , V_124 -> V_20 , & V_122 -> V_14 ,
& V_122 -> V_13 , F_63 ( V_18 ) ) ;
if ( ! V_148 )
goto V_133;
F_64 ( V_148 -> V_3 != NULL ) ;
if ( V_125 != F_65 ( V_148 ) -> V_150 ) {
F_51 ( V_126 , V_140 ) ;
goto V_133;
}
F_66 ( V_3 , V_148 , V_149 ) ;
goto V_133;
case V_115 :
case V_151 :
if ( ! F_50 ( V_3 ) ) {
V_3 -> V_152 = V_44 ;
V_3 -> V_153 ( V_3 ) ;
F_67 ( V_3 ) ;
} else
V_3 -> V_145 = V_44 ;
goto V_133;
}
if ( ! F_50 ( V_3 ) && V_32 -> V_154 ) {
V_3 -> V_152 = V_44 ;
V_3 -> V_153 ( V_3 ) ;
} else
V_3 -> V_145 = V_44 ;
V_133:
F_68 ( V_3 ) ;
F_69 ( V_3 ) ;
}
static int F_70 ( struct V_2 * V_3 , struct V_147 * V_148 ,
struct V_155 * V_156 ,
T_8 V_157 )
{
struct V_158 * V_159 = F_71 ( V_148 ) ;
struct V_31 * V_32 = F_15 ( V_3 ) ;
struct V_17 * V_18 ;
struct V_160 * V_96 = NULL ;
struct V_4 * V_35 , V_36 ;
struct V_39 V_40 ;
struct V_41 * V_42 ;
int V_44 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_89 = V_16 ;
V_40 . V_14 = V_159 -> V_161 ;
V_40 . V_13 = V_159 -> V_162 ;
V_40 . V_51 = 0 ;
V_40 . V_90 = V_159 -> V_163 ;
V_40 . V_91 = V_3 -> V_92 ;
V_40 . V_93 = F_72 ( V_148 ) -> V_164 ;
V_40 . V_94 = F_72 ( V_148 ) -> V_165 ;
F_73 ( V_148 , F_30 ( & V_40 ) ) ;
V_96 = V_32 -> V_96 ;
V_35 = F_28 ( & V_40 , V_96 , & V_36 ) ;
V_42 = F_31 ( V_3 , & V_40 , V_35 , false ) ;
if ( F_32 ( V_42 ) ) {
V_44 = F_33 ( V_42 ) ;
V_42 = NULL ;
goto V_166;
}
V_18 = F_74 ( V_3 , V_42 , V_148 , V_156 ) ;
V_44 = - V_167 ;
if ( V_18 ) {
F_75 ( V_18 , & V_159 -> V_162 , & V_159 -> V_161 ) ;
V_40 . V_14 = V_159 -> V_161 ;
F_76 ( V_18 , V_157 ) ;
V_44 = F_77 ( V_3 , V_18 , & V_40 , V_96 , V_32 -> V_168 ) ;
V_44 = F_78 ( V_44 ) ;
}
V_166:
if ( V_96 && V_96 != V_32 -> V_96 )
F_79 ( V_3 , V_96 , V_96 -> V_169 ) ;
F_60 ( V_42 ) ;
return V_44 ;
}
static int F_80 ( struct V_2 * V_3 , struct V_147 * V_148 ,
struct V_155 * V_156 )
{
F_81 ( F_82 ( V_3 ) , V_170 ) ;
return F_70 ( V_3 , V_148 , V_156 , 0 ) ;
}
static void F_83 ( struct V_147 * V_148 )
{
F_84 ( F_71 ( V_148 ) -> V_171 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_85 ( V_3 , (union V_172 * ) V_5 , V_48 ) ;
}
static struct V_1 * F_86 ( struct V_2 * V_3 ,
struct V_2 * V_173 )
{
return F_1 ( V_3 , & F_15 ( V_173 ) -> V_14 ) ;
}
static struct V_1 * F_87 ( struct V_2 * V_3 ,
struct V_147 * V_148 )
{
return F_1 ( V_3 , & F_71 ( V_148 ) -> V_161 ) ;
}
static int F_88 ( struct V_2 * V_3 , char T_9 * V_174 ,
int V_175 )
{
struct V_176 V_177 ;
struct V_25 * V_178 = (struct V_25 * ) & V_177 . V_179 ;
if ( V_175 < sizeof( V_177 ) )
return - V_46 ;
if ( F_89 ( & V_177 , V_174 , sizeof( V_177 ) ) )
return - V_180 ;
if ( V_178 -> V_47 != V_48 )
return - V_46 ;
if ( ! V_177 . V_181 ) {
if ( F_90 ( & V_178 -> V_56 ) )
return F_91 ( V_3 , (union V_172 * ) & V_178 -> V_56 . V_19 [ 3 ] ,
V_73 ) ;
return F_91 ( V_3 , (union V_172 * ) & V_178 -> V_56 ,
V_48 ) ;
}
if ( V_177 . V_181 > V_182 )
return - V_46 ;
if ( F_90 ( & V_178 -> V_56 ) )
return F_92 ( V_3 , (union V_172 * ) & V_178 -> V_56 . V_19 [ 3 ] ,
V_73 , V_177 . V_183 , V_177 . V_181 , V_184 ) ;
return F_92 ( V_3 , (union V_172 * ) & V_178 -> V_56 ,
V_48 , V_177 . V_183 , V_177 . V_181 , V_184 ) ;
}
static int F_93 ( struct V_185 * V_186 ,
const struct V_4 * V_14 ,
const struct V_4 * V_13 , int V_187 )
{
struct V_188 * V_189 ;
struct V_190 V_191 ;
V_189 = & V_186 -> V_192 . V_193 ;
V_189 -> V_13 = * V_13 ;
V_189 -> V_14 = * V_14 ;
V_189 -> V_194 = F_94 ( V_16 ) ;
V_189 -> V_12 = F_94 ( V_187 ) ;
F_95 ( & V_191 , V_189 , sizeof( * V_189 ) ) ;
return F_96 ( & V_186 -> V_195 , & V_191 , sizeof( * V_189 ) ) ;
}
static int F_97 ( char * V_196 , struct V_1 * V_197 ,
const struct V_4 * V_14 , struct V_4 * V_13 ,
const struct V_112 * V_124 )
{
struct V_185 * V_186 ;
struct V_198 * V_199 ;
V_186 = F_98 () ;
if ( ! V_186 )
goto V_200;
V_199 = & V_186 -> V_195 ;
if ( F_99 ( V_199 ) )
goto V_201;
if ( F_93 ( V_186 , V_14 , V_13 , V_124 -> V_202 << 2 ) )
goto V_201;
if ( F_100 ( V_186 , V_124 ) )
goto V_201;
if ( F_101 ( V_186 , V_197 ) )
goto V_201;
if ( F_102 ( V_199 , V_196 ) )
goto V_201;
F_103 () ;
return 0 ;
V_201:
F_103 () ;
V_200:
memset ( V_196 , 0 , 16 ) ;
return 1 ;
}
static int F_104 ( char * V_196 , struct V_1 * V_197 ,
const struct V_2 * V_3 ,
const struct V_147 * V_148 ,
const struct V_17 * V_18 )
{
const struct V_4 * V_13 , * V_14 ;
struct V_185 * V_186 ;
struct V_198 * V_199 ;
const struct V_112 * V_124 = F_12 ( V_18 ) ;
if ( V_3 ) {
V_13 = & F_15 ( V_3 ) -> V_13 ;
V_14 = & F_15 ( V_3 ) -> V_14 ;
} else if ( V_148 ) {
V_13 = & F_71 ( V_148 ) -> V_162 ;
V_14 = & F_71 ( V_148 ) -> V_161 ;
} else {
const struct V_113 * V_203 = F_11 ( V_18 ) ;
V_13 = & V_203 -> V_13 ;
V_14 = & V_203 -> V_14 ;
}
V_186 = F_98 () ;
if ( ! V_186 )
goto V_200;
V_199 = & V_186 -> V_195 ;
if ( F_99 ( V_199 ) )
goto V_201;
if ( F_93 ( V_186 , V_14 , V_13 , V_18 -> V_12 ) )
goto V_201;
if ( F_100 ( V_186 , V_124 ) )
goto V_201;
if ( F_105 ( V_186 , V_18 , V_124 -> V_202 << 2 ) )
goto V_201;
if ( F_101 ( V_186 , V_197 ) )
goto V_201;
if ( F_102 ( V_199 , V_196 ) )
goto V_201;
F_103 () ;
return 0 ;
V_201:
F_103 () ;
V_200:
memset ( V_196 , 0 , 16 ) ;
return 1 ;
}
static int F_106 ( struct V_2 * V_3 , const struct V_17 * V_18 )
{
const T_10 * V_204 = NULL ;
struct V_1 * V_205 ;
const struct V_113 * V_203 = F_11 ( V_18 ) ;
const struct V_112 * V_124 = F_12 ( V_18 ) ;
int V_206 ;
T_6 V_207 [ 16 ] ;
V_205 = F_1 ( V_3 , & V_203 -> V_13 ) ;
V_204 = F_107 ( V_124 ) ;
if ( ! V_205 && ! V_204 )
return 0 ;
if ( V_205 && ! V_204 ) {
F_51 ( F_82 ( V_3 ) , V_208 ) ;
return 1 ;
}
if ( ! V_205 && V_204 ) {
F_51 ( F_82 ( V_3 ) , V_209 ) ;
return 1 ;
}
V_206 = F_104 ( V_207 ,
V_205 ,
NULL , NULL , V_18 ) ;
if ( V_206 || memcmp ( V_204 , V_207 , 16 ) != 0 ) {
F_108 ( L_2 ,
V_206 ? L_3 : L_4 ,
& V_203 -> V_13 , F_109 ( V_124 -> V_21 ) ,
& V_203 -> V_14 , F_109 ( V_124 -> V_20 ) ) ;
return 1 ;
}
return 0 ;
}
static void F_75 ( struct V_17 * V_18 ,
const struct V_4 * V_13 , const struct V_4 * V_14 )
{
struct V_112 * V_124 = F_12 ( V_18 ) ;
if ( V_18 -> V_210 == V_211 ) {
V_124 -> V_212 = ~ F_7 ( V_18 -> V_12 , V_13 , V_14 , 0 ) ;
V_18 -> V_213 = F_110 ( V_18 ) - V_18 -> V_214 ;
V_18 -> V_215 = F_111 ( struct V_112 , V_212 ) ;
} else {
V_124 -> V_212 = F_7 ( V_18 -> V_12 , V_13 , V_14 ,
F_112 ( V_124 , V_124 -> V_202 << 2 ,
V_18 -> V_216 ) ) ;
}
}
static void F_113 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_31 * V_32 = F_15 ( V_3 ) ;
F_75 ( V_18 , & V_32 -> V_13 , & V_32 -> V_14 ) ;
}
static int F_114 ( struct V_17 * V_18 )
{
const struct V_113 * V_217 ;
struct V_112 * V_124 ;
if ( ! F_115 ( V_18 , sizeof( * V_124 ) ) )
return - V_46 ;
V_217 = F_11 ( V_18 ) ;
V_124 = F_12 ( V_18 ) ;
V_124 -> V_212 = 0 ;
V_18 -> V_210 = V_211 ;
F_75 ( V_18 , & V_217 -> V_13 , & V_217 -> V_14 ) ;
return 0 ;
}
static struct V_17 * * F_116 ( struct V_17 * * V_214 ,
struct V_17 * V_18 )
{
const struct V_113 * V_218 = F_117 ( V_18 ) ;
switch ( V_18 -> V_210 ) {
case V_219 :
if ( ! F_7 ( F_118 ( V_18 ) , & V_218 -> V_13 , & V_218 -> V_14 ,
V_18 -> V_216 ) ) {
V_18 -> V_210 = V_220 ;
break;
}
case V_221 :
F_119 ( V_18 ) -> V_222 = 1 ;
return NULL ;
}
return F_120 ( V_214 , V_18 ) ;
}
static int F_121 ( struct V_17 * V_18 )
{
const struct V_113 * V_218 = F_11 ( V_18 ) ;
struct V_112 * V_124 = F_12 ( V_18 ) ;
V_124 -> V_212 = ~ F_7 ( V_18 -> V_12 - F_122 ( V_18 ) ,
& V_218 -> V_13 , & V_218 -> V_14 , 0 ) ;
F_123 ( V_18 ) -> V_223 = V_99 ;
return F_124 ( V_18 ) ;
}
static void F_125 ( struct V_17 * V_18 , T_5 V_125 , T_5 V_224 , T_5 V_225 ,
T_5 V_226 , struct V_1 * V_197 , int V_227 , T_6 V_168 )
{
const struct V_112 * V_124 = F_12 ( V_18 ) ;
struct V_112 * V_228 ;
struct V_17 * V_229 ;
struct V_39 V_40 ;
struct V_126 * V_126 = F_43 ( F_126 ( V_18 ) -> V_127 ) ;
struct V_2 * V_230 = V_126 -> V_231 . F_16 ;
unsigned int V_169 = sizeof( struct V_112 ) ;
struct V_41 * V_42 ;
T_7 * V_232 ;
if ( V_226 )
V_169 += V_233 ;
#ifdef F_25
if ( V_197 )
V_169 += V_234 ;
#endif
V_229 = F_127 ( V_235 + sizeof( struct V_113 ) + V_169 ,
V_236 ) ;
if ( V_229 == NULL )
return;
F_128 ( V_229 , V_235 + sizeof( struct V_113 ) + V_169 ) ;
V_228 = (struct V_112 * ) F_129 ( V_229 , V_169 ) ;
F_130 ( V_229 ) ;
memset ( V_228 , 0 , sizeof( * V_228 ) ) ;
V_228 -> V_20 = V_124 -> V_21 ;
V_228 -> V_21 = V_124 -> V_20 ;
V_228 -> V_202 = V_169 / 4 ;
V_228 -> V_125 = F_131 ( V_125 ) ;
V_228 -> V_237 = F_131 ( V_224 ) ;
V_228 -> V_224 = ! V_227 || ! V_124 -> V_224 ;
V_228 -> V_227 = V_227 ;
V_228 -> V_238 = F_132 ( V_225 ) ;
V_232 = ( T_7 * ) ( V_228 + 1 ) ;
if ( V_226 ) {
* V_232 ++ = F_131 ( ( V_239 << 24 ) | ( V_239 << 16 ) |
( V_240 << 8 ) | V_241 ) ;
* V_232 ++ = F_131 ( V_242 ) ;
* V_232 ++ = F_131 ( V_226 ) ;
}
#ifdef F_25
if ( V_197 ) {
* V_232 ++ = F_131 ( ( V_239 << 24 ) | ( V_239 << 16 ) |
( V_243 << 8 ) | V_244 ) ;
F_97 ( ( T_10 * ) V_232 , V_197 ,
& F_11 ( V_18 ) -> V_13 ,
& F_11 ( V_18 ) -> V_14 , V_228 ) ;
}
#endif
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_14 = F_11 ( V_18 ) -> V_13 ;
V_40 . V_13 = F_11 ( V_18 ) -> V_14 ;
V_229 -> V_210 = V_211 ;
V_229 -> V_216 = 0 ;
F_75 ( V_229 , & V_40 . V_13 , & V_40 . V_14 ) ;
V_40 . V_89 = V_16 ;
V_40 . V_90 = F_63 ( V_18 ) ;
V_40 . V_93 = V_228 -> V_20 ;
V_40 . V_94 = V_228 -> V_21 ;
F_55 ( V_18 , F_30 ( & V_40 ) ) ;
V_42 = F_31 ( V_230 , & V_40 , NULL , false ) ;
if ( ! F_32 ( V_42 ) ) {
F_133 ( V_229 , V_42 ) ;
F_77 ( V_230 , V_229 , & V_40 , NULL , V_168 ) ;
F_81 ( V_126 , V_245 ) ;
if ( V_227 )
F_81 ( V_126 , V_246 ) ;
return;
}
F_84 ( V_229 ) ;
}
static void F_134 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
const struct V_112 * V_124 = F_12 ( V_18 ) ;
T_5 V_125 = 0 , V_237 = 0 ;
struct V_1 * V_197 = NULL ;
#ifdef F_25
const T_10 * V_204 = NULL ;
struct V_113 * V_217 = F_11 ( V_18 ) ;
unsigned char V_207 [ 16 ] ;
int V_206 ;
struct V_2 * V_247 = NULL ;
#endif
if ( V_124 -> V_227 )
return;
if ( ! F_135 ( V_18 ) )
return;
#ifdef F_25
V_204 = F_107 ( V_124 ) ;
if ( ! V_3 && V_204 ) {
V_247 = F_136 ( F_43 ( F_126 ( V_18 ) -> V_127 ) ,
& V_128 , & V_217 -> V_14 ,
F_109 ( V_124 -> V_21 ) , F_63 ( V_18 ) ) ;
if ( ! V_247 )
return;
F_137 () ;
V_197 = F_1 ( V_247 , & V_217 -> V_13 ) ;
if ( ! V_197 )
goto V_248;
V_206 = F_104 ( V_207 , V_197 , NULL , NULL , V_18 ) ;
if ( V_206 || memcmp ( V_204 , V_207 , 16 ) != 0 )
goto V_248;
} else {
V_197 = V_3 ? F_1 ( V_3 , & V_217 -> V_13 ) : NULL ;
}
#endif
if ( V_124 -> V_224 )
V_125 = F_52 ( V_124 -> V_237 ) ;
else
V_237 = F_52 ( V_124 -> V_125 ) + V_124 -> V_249 + V_124 -> V_250 + V_18 -> V_12 -
( V_124 -> V_202 << 2 ) ;
F_125 ( V_18 , V_125 , V_237 , 0 , 0 , V_197 , 1 , 0 ) ;
#ifdef F_25
V_248:
if ( V_247 ) {
F_138 () ;
F_69 ( V_247 ) ;
}
#endif
}
static void F_139 ( struct V_17 * V_18 , T_5 V_125 , T_5 V_224 , T_5 V_225 , T_5 V_226 ,
struct V_1 * V_197 , T_6 V_168 )
{
F_125 ( V_18 , V_125 , V_224 , V_225 , V_226 , V_197 , 0 , V_168 ) ;
}
static void F_140 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_251 * V_252 = F_48 ( V_3 ) ;
struct V_253 * V_254 = F_141 ( V_3 ) ;
F_139 ( V_18 , V_254 -> V_255 , V_254 -> V_256 ,
V_254 -> V_257 >> V_252 -> V_258 ,
V_254 -> V_259 , F_142 ( V_254 ) ,
V_252 -> V_260 ) ;
F_47 ( V_252 ) ;
}
static void F_143 ( struct V_2 * V_3 , struct V_17 * V_18 ,
struct V_147 * V_148 )
{
F_139 ( V_18 , F_65 ( V_148 ) -> V_150 + 1 , F_65 ( V_148 ) -> V_261 + 1 , V_148 -> V_262 , V_148 -> V_65 ,
F_1 ( V_3 , & F_11 ( V_18 ) -> V_14 ) , 0 ) ;
}
static struct V_2 * F_144 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_147 * V_148 , * * V_149 ;
const struct V_112 * V_124 = F_12 ( V_18 ) ;
struct V_2 * V_263 ;
V_148 = F_62 ( V_3 , & V_149 , V_124 -> V_21 ,
& F_11 ( V_18 ) -> V_13 ,
& F_11 ( V_18 ) -> V_14 , F_63 ( V_18 ) ) ;
if ( V_148 )
return F_145 ( V_3 , V_18 , V_148 , V_149 ) ;
V_263 = F_146 ( F_82 ( V_3 ) , & V_128 ,
& F_11 ( V_18 ) -> V_13 , V_124 -> V_21 ,
& F_11 ( V_18 ) -> V_14 , F_109 ( V_124 -> V_20 ) , F_63 ( V_18 ) ) ;
if ( V_263 ) {
if ( V_263 -> V_6 != V_131 ) {
F_49 ( V_263 ) ;
return V_263 ;
}
F_47 ( F_48 ( V_263 ) ) ;
return NULL ;
}
#ifdef F_147
if ( ! V_124 -> V_249 )
V_3 = F_148 ( V_3 , V_18 ) ;
#endif
return V_3 ;
}
static int F_149 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_264 V_265 ;
struct V_266 V_267 ;
const T_6 * V_204 ;
struct V_147 * V_148 ;
struct V_158 * V_159 ;
struct V_31 * V_32 = F_15 ( V_3 ) ;
struct V_33 * V_34 = F_16 ( V_3 ) ;
T_4 V_268 = F_150 ( V_18 ) -> V_269 ;
struct V_41 * V_42 = NULL ;
bool V_270 = false ;
if ( V_18 -> V_194 == F_132 ( V_271 ) )
return F_151 ( V_3 , V_18 ) ;
if ( ! F_135 ( V_18 ) )
goto V_272;
if ( F_152 ( V_3 ) && ! V_268 ) {
V_270 = F_153 ( V_3 , V_18 , L_5 ) ;
if ( ! V_270 )
goto V_272;
}
if ( F_154 ( V_3 ) && F_155 ( V_3 ) > 1 )
goto V_272;
V_148 = F_156 ( & V_273 ) ;
if ( V_148 == NULL )
goto V_272;
#ifdef F_25
F_65 ( V_148 ) -> V_80 = & V_274 ;
#endif
F_157 ( & V_267 ) ;
V_267 . V_110 = V_111 - sizeof( struct V_112 ) - sizeof( struct V_113 ) ;
V_267 . V_275 = V_34 -> V_63 . V_275 ;
F_158 ( V_18 , & V_267 , & V_204 , 0 ) ;
if ( V_267 . V_276 > 0 &&
V_267 . V_277 &&
! V_34 -> V_63 . V_278 &&
( V_279 > 0 ||
( V_34 -> V_280 != NULL &&
V_34 -> V_280 -> V_281 > 0 ) ) ) {
T_6 * V_282 ;
T_5 * V_283 ;
T_5 * V_284 = & V_265 . V_285 [ V_286 ] ;
int V_287 = V_267 . V_276 - V_288 ;
if ( F_159 ( & V_265 . V_285 [ 0 ] ) != 0 )
goto V_289;
V_283 = ( V_290 T_5 * ) & F_11 ( V_18 ) -> V_14 . V_19 [ 0 ] ;
* V_284 ++ ^= * V_283 ++ ;
* V_284 ++ ^= * V_283 ++ ;
* V_284 ++ ^= * V_283 ++ ;
* V_284 ++ ^= * V_283 ++ ;
V_283 = ( V_290 T_5 * ) & F_11 ( V_18 ) -> V_13 . V_19 [ 0 ] ;
* V_284 ++ ^= * V_283 ++ ;
* V_284 ++ ^= * V_283 ++ ;
* V_284 ++ ^= * V_283 ++ ;
* V_284 ++ ^= * V_283 ++ ;
V_282 = ( T_6 * ) V_284 ;
while ( V_287 -- > 0 )
* V_282 ++ ^= * V_204 ++ ;
V_270 = false ;
V_265 . V_278 = 0 ;
V_265 . V_276 = V_267 . V_276 ;
} else if ( ! V_34 -> V_63 . V_291 ) {
V_265 . V_278 = 1 ;
V_265 . V_276 = 0 ;
} else {
goto V_289;
}
V_265 . V_291 = V_34 -> V_63 . V_291 ;
if ( V_270 && ! V_267 . V_277 )
F_157 ( & V_267 ) ;
V_267 . V_292 = V_267 . V_277 ;
F_160 ( V_148 , & V_267 , V_18 ) ;
V_159 = F_71 ( V_148 ) ;
V_159 -> V_161 = F_11 ( V_18 ) -> V_13 ;
V_159 -> V_162 = F_11 ( V_18 ) -> V_14 ;
if ( ! V_270 || V_267 . V_292 )
F_161 ( V_148 , V_18 ) ;
V_159 -> V_163 = V_3 -> V_62 ;
if ( ! V_3 -> V_62 &&
F_21 ( & V_159 -> V_161 ) & V_60 )
V_159 -> V_163 = F_63 ( V_18 ) ;
if ( ! V_268 ) {
struct V_103 * V_104 = NULL ;
if ( F_162 ( V_3 , V_18 ) ||
V_32 -> V_293 . V_294 . V_295 || V_32 -> V_293 . V_294 . V_296 ||
V_32 -> V_293 . V_294 . V_297 || V_32 -> V_293 . V_294 . V_298 ) {
F_163 ( & V_18 -> V_299 ) ;
V_159 -> V_171 = V_18 ;
}
if ( V_270 ) {
V_268 = F_164 ( V_3 , V_18 , & V_148 -> V_300 ) ;
V_148 -> V_301 = V_267 . V_292 ;
goto V_302;
}
if ( V_267 . V_277 &&
V_100 . V_101 &&
( V_42 = F_165 ( V_3 , V_148 ) ) != NULL &&
( V_104 = F_35 ( (struct V_37 * ) V_42 ) ) != NULL &&
F_22 ( (struct V_4 * ) V_104 -> V_14 . V_5 . V_303 ,
& V_159 -> V_161 ) ) {
F_36 ( V_104 ) ;
if ( ( T_5 ) F_37 () - V_104 -> V_105 < V_106 &&
( V_304 ) ( V_104 -> V_107 - V_148 -> V_65 ) >
V_305 ) {
F_51 ( F_82 ( V_3 ) , V_306 ) ;
goto V_307;
}
}
else if ( ! V_308 &&
( V_309 - F_166 ( V_3 ) <
( V_309 >> 2 ) ) &&
( ! V_104 || ! V_104 -> V_105 ) &&
( ! V_42 || ! F_167 ( V_42 , V_310 ) ) ) {
F_168 ( V_311 L_6 ,
& V_159 -> V_161 , F_109 ( F_12 ( V_18 ) -> V_21 ) ) ;
goto V_307;
}
V_268 = F_9 ( V_18 ) ;
}
V_302:
F_65 ( V_148 ) -> V_150 = V_268 ;
F_65 ( V_148 ) -> V_312 = V_242 ;
if ( F_169 ( V_3 , V_18 , V_148 ) )
goto V_307;
if ( F_70 ( V_3 , V_148 ,
(struct V_155 * ) & V_265 ,
F_170 ( V_18 ) ) ||
V_270 )
goto V_289;
F_171 ( V_3 , V_148 , V_313 ) ;
return 0 ;
V_307:
F_60 ( V_42 ) ;
V_289:
F_172 ( V_148 ) ;
V_272:
return 0 ;
}
static struct V_2 * F_173 ( struct V_2 * V_3 , struct V_17 * V_18 ,
struct V_147 * V_148 ,
struct V_41 * V_42 )
{
struct V_158 * V_159 ;
struct V_31 * V_314 , * V_32 = F_15 ( V_3 ) ;
struct V_315 * V_316 ;
struct V_27 * V_317 ;
struct V_33 * V_318 ;
struct V_2 * V_319 ;
struct V_160 * V_96 ;
#ifdef F_25
struct V_1 * V_197 ;
#endif
if ( V_18 -> V_194 == F_132 ( V_271 ) ) {
V_319 = F_174 ( V_3 , V_18 , V_148 , V_42 ) ;
if ( V_319 == NULL )
return NULL ;
V_316 = (struct V_315 * ) V_319 ;
F_14 ( V_319 ) -> V_320 = & V_316 -> V_321 ;
V_317 = F_14 ( V_319 ) ;
V_314 = F_15 ( V_319 ) ;
V_318 = F_16 ( V_319 ) ;
memcpy ( V_314 , V_32 , sizeof( struct V_31 ) ) ;
F_27 ( V_317 -> V_322 , & V_314 -> V_14 ) ;
F_27 ( V_317 -> V_86 , & V_314 -> V_13 ) ;
V_314 -> V_88 = V_314 -> V_13 ;
F_3 ( V_319 ) -> V_8 = & V_9 ;
V_319 -> V_78 = V_79 ;
#ifdef F_25
V_318 -> V_80 = & V_81 ;
#endif
V_314 -> V_323 = NULL ;
V_314 -> V_324 = NULL ;
V_314 -> V_325 = NULL ;
V_314 -> V_96 = NULL ;
V_314 -> V_326 = F_63 ( V_18 ) ;
V_314 -> V_327 = F_11 ( V_18 ) -> V_134 ;
V_314 -> V_328 = F_175 ( F_11 ( V_18 ) ) ;
F_58 ( V_319 , F_3 ( V_319 ) -> V_146 ) ;
return V_319 ;
}
V_159 = F_71 ( V_148 ) ;
V_96 = V_32 -> V_96 ;
if ( F_154 ( V_3 ) )
goto V_329;
if ( ! V_42 ) {
V_42 = F_165 ( V_3 , V_148 ) ;
if ( ! V_42 )
goto V_133;
}
V_319 = F_176 ( V_3 , V_148 , V_18 ) ;
if ( V_319 == NULL )
goto V_330;
V_319 -> V_98 = V_99 ;
F_34 ( V_319 , V_42 , NULL , NULL ) ;
V_316 = (struct V_315 * ) V_319 ;
F_14 ( V_319 ) -> V_320 = & V_316 -> V_321 ;
V_318 = F_16 ( V_319 ) ;
V_317 = F_14 ( V_319 ) ;
V_314 = F_15 ( V_319 ) ;
memcpy ( V_314 , V_32 , sizeof( struct V_31 ) ) ;
V_314 -> V_14 = V_159 -> V_161 ;
V_314 -> V_13 = V_159 -> V_162 ;
V_314 -> V_88 = V_159 -> V_162 ;
V_319 -> V_62 = V_159 -> V_163 ;
V_317 -> V_331 = NULL ;
V_314 -> V_323 = NULL ;
V_314 -> V_324 = NULL ;
V_314 -> V_293 . V_332 = V_32 -> V_293 . V_332 ;
V_314 -> V_325 = NULL ;
if ( V_159 -> V_171 != NULL ) {
V_314 -> V_325 = F_177 ( V_159 -> V_171 , V_236 ) ;
F_178 ( V_159 -> V_171 ) ;
V_159 -> V_171 = NULL ;
if ( V_314 -> V_325 )
F_179 ( V_314 -> V_325 , V_319 ) ;
}
V_314 -> V_96 = NULL ;
V_314 -> V_326 = F_63 ( V_18 ) ;
V_314 -> V_327 = F_11 ( V_18 ) -> V_134 ;
V_314 -> V_328 = F_175 ( F_11 ( V_18 ) ) ;
if ( V_96 ) {
V_314 -> V_96 = F_180 ( V_319 , V_96 ) ;
if ( V_96 != V_32 -> V_96 )
F_79 ( V_3 , V_96 , V_96 -> V_169 ) ;
}
F_3 ( V_319 ) -> V_70 = 0 ;
if ( V_314 -> V_96 )
F_3 ( V_319 ) -> V_70 = ( V_314 -> V_96 -> V_109 +
V_314 -> V_96 -> V_108 ) ;
F_181 ( V_319 ) ;
F_58 ( V_319 , F_57 ( V_42 ) ) ;
V_318 -> V_333 = F_182 ( V_42 ) ;
if ( F_16 ( V_3 ) -> V_63 . V_275 &&
F_16 ( V_3 ) -> V_63 . V_275 < V_318 -> V_333 )
V_318 -> V_333 = F_16 ( V_3 ) -> V_63 . V_275 ;
F_183 ( V_319 ) ;
if ( F_65 ( V_148 ) -> V_312 )
F_184 ( V_319 ,
V_242 - F_65 ( V_148 ) -> V_312 ) ;
V_318 -> V_334 = V_148 -> V_335 ;
V_317 -> V_322 = V_317 -> V_86 = V_97 ;
V_317 -> V_87 = V_97 ;
#ifdef F_25
if ( ( V_197 = F_1 ( V_3 , & V_314 -> V_14 ) ) != NULL ) {
F_92 ( V_319 , (union V_172 * ) & V_314 -> V_14 ,
V_48 , V_197 -> V_197 , V_197 -> V_336 , V_236 ) ;
}
#endif
if ( F_185 ( V_3 , V_319 ) < 0 ) {
F_69 ( V_319 ) ;
goto V_133;
}
F_5 ( V_319 , NULL ) ;
return V_319 ;
V_329:
F_51 ( F_82 ( V_3 ) , V_337 ) ;
V_330:
if ( V_96 && V_96 != V_32 -> V_96 )
F_79 ( V_3 , V_96 , V_96 -> V_169 ) ;
F_60 ( V_42 ) ;
V_133:
F_51 ( F_82 ( V_3 ) , V_338 ) ;
return NULL ;
}
static T_2 F_186 ( struct V_17 * V_18 )
{
if ( V_18 -> V_210 == V_219 ) {
if ( ! F_7 ( V_18 -> V_12 , & F_11 ( V_18 ) -> V_13 ,
& F_11 ( V_18 ) -> V_14 , V_18 -> V_216 ) ) {
V_18 -> V_210 = V_220 ;
return 0 ;
}
}
V_18 -> V_216 = ~ F_187 ( F_7 ( V_18 -> V_12 ,
& F_11 ( V_18 ) -> V_13 ,
& F_11 ( V_18 ) -> V_14 , 0 ) ) ;
if ( V_18 -> V_12 <= 76 ) {
return F_188 ( V_18 ) ;
}
return 0 ;
}
static int V_83 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_31 * V_32 = F_15 ( V_3 ) ;
struct V_33 * V_34 ;
struct V_17 * V_339 = NULL ;
if ( V_18 -> V_194 == F_132 ( V_271 ) )
return V_79 ( V_3 , V_18 ) ;
#ifdef F_25
if ( F_106 ( V_3 , V_18 ) )
goto V_340;
#endif
if ( F_189 ( V_3 , V_18 ) )
goto V_340;
if ( V_32 -> V_293 . V_332 )
V_339 = F_177 ( V_18 , V_236 ) ;
if ( V_3 -> V_6 == V_341 ) {
F_190 ( V_3 , V_18 ) ;
if ( F_191 ( V_3 , V_18 , F_12 ( V_18 ) , V_18 -> V_12 ) )
goto V_342;
if ( V_339 )
goto V_343;
return 0 ;
}
if ( V_18 -> V_12 < F_192 ( V_18 ) || F_193 ( V_18 ) )
goto V_344;
if ( V_3 -> V_6 == V_137 ) {
struct V_2 * V_263 = F_144 ( V_3 , V_18 ) ;
if ( ! V_263 )
goto V_340;
if( V_263 != V_3 ) {
F_190 ( V_263 , V_18 ) ;
if ( F_194 ( V_3 , V_263 , V_18 ) )
goto V_342;
if ( V_339 )
F_195 ( V_339 ) ;
return 0 ;
}
} else
F_190 ( V_3 , V_18 ) ;
if ( F_196 ( V_3 , V_18 , F_12 ( V_18 ) , V_18 -> V_12 ) )
goto V_342;
if ( V_339 )
goto V_343;
return 0 ;
V_342:
F_134 ( V_3 , V_18 ) ;
V_340:
if ( V_339 )
F_195 ( V_339 ) ;
F_84 ( V_18 ) ;
return 0 ;
V_344:
F_81 ( F_82 ( V_3 ) , V_345 ) ;
goto V_340;
V_343:
V_34 = F_16 ( V_3 ) ;
if ( F_150 ( V_339 ) -> V_346 == V_34 -> V_347 &&
! ( ( 1 << V_3 -> V_6 ) & ( V_143 | V_142 ) ) ) {
if ( V_32 -> V_293 . V_294 . V_295 || V_32 -> V_293 . V_294 . V_296 )
V_32 -> V_326 = F_63 ( V_339 ) ;
if ( V_32 -> V_293 . V_294 . V_297 || V_32 -> V_293 . V_294 . V_298 )
V_32 -> V_327 = F_11 ( V_339 ) -> V_134 ;
if ( V_32 -> V_293 . V_294 . V_348 )
V_32 -> V_328 = F_175 ( F_11 ( V_18 ) ) ;
if ( F_162 ( V_3 , V_339 ) ) {
F_179 ( V_339 , V_3 ) ;
V_339 = F_197 ( & V_32 -> V_325 , V_339 ) ;
} else {
F_195 ( V_339 ) ;
V_339 = F_197 ( & V_32 -> V_325 , NULL ) ;
}
}
F_84 ( V_339 ) ;
return 0 ;
}
static int F_198 ( struct V_17 * V_18 )
{
const struct V_112 * V_124 ;
const struct V_113 * V_122 ;
struct V_2 * V_3 ;
int V_349 ;
struct V_126 * V_126 = F_43 ( V_18 -> V_127 ) ;
if ( V_18 -> V_350 != V_351 )
goto V_352;
F_81 ( V_126 , V_353 ) ;
if ( ! F_115 ( V_18 , sizeof( struct V_112 ) ) )
goto V_352;
V_124 = F_12 ( V_18 ) ;
if ( V_124 -> V_202 < sizeof( struct V_112 ) / 4 )
goto V_354;
if ( ! F_115 ( V_18 , V_124 -> V_202 * 4 ) )
goto V_352;
if ( ! F_199 ( V_18 ) && F_186 ( V_18 ) )
goto V_354;
V_124 = F_12 ( V_18 ) ;
V_122 = F_11 ( V_18 ) ;
F_150 ( V_18 ) -> V_125 = F_52 ( V_124 -> V_125 ) ;
F_150 ( V_18 ) -> V_346 = ( F_150 ( V_18 ) -> V_125 + V_124 -> V_249 + V_124 -> V_250 +
V_18 -> V_12 - V_124 -> V_202 * 4 ) ;
F_150 ( V_18 ) -> V_237 = F_52 ( V_124 -> V_237 ) ;
F_150 ( V_18 ) -> V_269 = 0 ;
F_150 ( V_18 ) -> V_355 = F_200 ( V_122 ) ;
F_150 ( V_18 ) -> V_356 = 0 ;
V_3 = F_201 ( & V_128 , V_18 , V_124 -> V_21 , V_124 -> V_20 ) ;
if ( ! V_3 )
goto V_357;
V_358:
if ( V_3 -> V_6 == V_131 )
goto V_359;
if ( V_122 -> V_134 < F_15 ( V_3 ) -> V_135 ) {
F_51 ( V_126 , V_136 ) ;
goto V_360;
}
if ( ! F_202 ( V_3 , V_361 , V_18 ) )
goto V_360;
if ( F_189 ( V_3 , V_18 ) )
goto V_360;
V_18 -> V_127 = NULL ;
F_203 ( V_3 ) ;
V_349 = 0 ;
if ( ! F_50 ( V_3 ) ) {
#ifdef F_204
struct V_33 * V_34 = F_16 ( V_3 ) ;
if ( ! V_34 -> V_362 . V_363 && V_34 -> V_362 . V_364 )
V_34 -> V_362 . V_363 = F_205 () ;
if ( V_34 -> V_362 . V_363 )
V_349 = V_83 ( V_3 , V_18 ) ;
else
#endif
{
if ( ! F_206 ( V_3 , V_18 ) )
V_349 = V_83 ( V_3 , V_18 ) ;
}
} else if ( F_207 ( F_208 ( V_3 , V_18 ,
V_3 -> V_365 + V_3 -> V_366 ) ) ) {
F_68 ( V_3 ) ;
F_51 ( V_126 , V_367 ) ;
goto V_360;
}
F_68 ( V_3 ) ;
F_69 ( V_3 ) ;
return V_349 ? - 1 : 0 ;
V_357:
if ( ! F_202 ( NULL , V_361 , V_18 ) )
goto V_352;
if ( V_18 -> V_12 < ( V_124 -> V_202 << 2 ) || F_193 ( V_18 ) ) {
V_354:
F_81 ( V_126 , V_345 ) ;
} else {
F_134 ( NULL , V_18 ) ;
}
V_352:
F_84 ( V_18 ) ;
return 0 ;
V_360:
F_69 ( V_3 ) ;
goto V_352;
V_359:
if ( ! F_202 ( NULL , V_361 , V_18 ) ) {
F_47 ( F_48 ( V_3 ) ) ;
goto V_352;
}
if ( V_18 -> V_12 < ( V_124 -> V_202 << 2 ) || F_193 ( V_18 ) ) {
F_81 ( V_126 , V_345 ) ;
F_47 ( F_48 ( V_3 ) ) ;
goto V_352;
}
switch ( F_209 ( F_48 ( V_3 ) , V_18 , V_124 ) ) {
case V_368 :
{
struct V_2 * V_369 ;
V_369 = F_136 ( F_43 ( V_18 -> V_127 ) , & V_128 ,
& F_11 ( V_18 ) -> V_14 ,
F_109 ( V_124 -> V_20 ) , F_63 ( V_18 ) ) ;
if ( V_369 != NULL ) {
struct V_251 * V_252 = F_48 ( V_3 ) ;
F_210 ( V_252 , & V_100 ) ;
F_47 ( V_252 ) ;
V_3 = V_369 ;
goto V_358;
}
}
case V_370 :
F_140 ( V_3 , V_18 ) ;
break;
case V_371 :
goto V_357;
case V_372 : ;
}
goto V_352;
}
static struct V_103 * F_211 ( struct V_2 * V_3 , bool * V_373 )
{
struct V_37 * V_38 = (struct V_37 * ) F_212 ( V_3 ) ;
struct V_31 * V_32 = F_15 ( V_3 ) ;
struct V_103 * V_104 ;
if ( ! V_38 ||
! F_22 ( & V_32 -> V_14 , & V_38 -> V_102 . V_5 ) ) {
V_104 = F_213 ( & V_32 -> V_14 , 1 ) ;
* V_373 = true ;
} else {
if ( ! V_38 -> V_374 )
F_214 ( V_38 , 1 ) ;
V_104 = V_38 -> V_374 ;
* V_373 = false ;
}
return V_104 ;
}
static void * F_215 ( struct V_2 * V_3 )
{
const struct V_375 * V_376 = F_216 ( V_3 ) ;
const struct V_251 * V_252 = F_48 ( V_3 ) ;
if ( V_252 -> V_377 == V_73 )
return F_217 ( V_3 ) ;
return F_213 ( & V_376 -> V_378 , 1 ) ;
}
static int F_218 ( struct V_2 * V_3 )
{
struct V_29 * V_30 = F_3 ( V_3 ) ;
F_219 ( V_3 ) ;
V_30 -> V_8 = & V_82 ;
#ifdef F_25
F_16 ( V_3 ) -> V_80 = & V_84 ;
#endif
return 0 ;
}
static void F_220 ( struct V_2 * V_3 )
{
F_221 ( V_3 ) ;
F_222 ( V_3 ) ;
}
static void F_223 ( struct V_379 * V_125 ,
const struct V_2 * V_3 , struct V_147 * V_148 , int V_380 , int V_381 )
{
int V_382 = V_148 -> V_383 - V_384 ;
const struct V_4 * V_385 = & F_71 ( V_148 ) -> V_162 ;
const struct V_4 * V_20 = & F_71 ( V_148 ) -> V_161 ;
if ( V_382 < 0 )
V_382 = 0 ;
F_224 ( V_125 ,
L_7
L_8 ,
V_380 ,
V_385 -> V_19 [ 0 ] , V_385 -> V_19 [ 1 ] ,
V_385 -> V_19 [ 2 ] , V_385 -> V_19 [ 3 ] ,
F_109 ( F_72 ( V_148 ) -> V_165 ) ,
V_20 -> V_19 [ 0 ] , V_20 -> V_19 [ 1 ] ,
V_20 -> V_19 [ 2 ] , V_20 -> V_19 [ 3 ] ,
F_109 ( F_72 ( V_148 ) -> V_164 ) ,
V_151 ,
0 , 0 ,
1 ,
F_225 ( V_382 ) ,
V_148 -> V_335 ,
V_381 ,
0 ,
0 ,
0 , V_148 ) ;
}
static void F_226 ( struct V_379 * V_125 , struct V_2 * V_386 , int V_380 )
{
const struct V_4 * V_20 , * V_385 ;
T_11 V_387 , V_388 ;
int V_389 ;
unsigned long V_390 ;
const struct V_27 * V_28 = F_14 ( V_386 ) ;
const struct V_33 * V_34 = F_16 ( V_386 ) ;
const struct V_29 * V_30 = F_3 ( V_386 ) ;
const struct V_31 * V_32 = F_15 ( V_386 ) ;
V_20 = & V_32 -> V_14 ;
V_385 = & V_32 -> V_88 ;
V_387 = F_109 ( V_28 -> V_114 ) ;
V_388 = F_109 ( V_28 -> V_95 ) ;
if ( V_30 -> V_391 == V_392 ) {
V_389 = 1 ;
V_390 = V_30 -> V_393 ;
} else if ( V_30 -> V_391 == V_394 ) {
V_389 = 4 ;
V_390 = V_30 -> V_393 ;
} else if ( F_227 ( & V_386 -> V_395 ) ) {
V_389 = 2 ;
V_390 = V_386 -> V_395 . V_383 ;
} else {
V_389 = 0 ;
V_390 = V_384 ;
}
F_224 ( V_125 ,
L_7
L_9 ,
V_380 ,
V_385 -> V_19 [ 0 ] , V_385 -> V_19 [ 1 ] ,
V_385 -> V_19 [ 2 ] , V_385 -> V_19 [ 3 ] , V_388 ,
V_20 -> V_19 [ 0 ] , V_20 -> V_19 [ 1 ] ,
V_20 -> V_19 [ 2 ] , V_20 -> V_19 [ 3 ] , V_387 ,
V_386 -> V_6 ,
V_34 -> V_66 - V_34 -> V_138 ,
( V_386 -> V_6 == V_137 ) ? V_386 -> V_396 : ( V_34 -> V_347 - V_34 -> V_397 ) ,
V_389 ,
F_225 ( V_390 - V_384 ) ,
V_30 -> V_398 ,
F_228 ( V_386 ) ,
V_30 -> V_399 ,
F_229 ( V_386 ) ,
F_230 ( & V_386 -> V_400 ) , V_386 ,
F_225 ( V_30 -> V_401 ) ,
F_225 ( V_30 -> V_402 . V_403 ) ,
( V_30 -> V_402 . V_404 << 1 ) | V_30 -> V_402 . V_405 ,
V_34 -> V_406 ,
F_231 ( V_34 ) ? - 1 : V_34 -> V_407
) ;
}
static void F_232 ( struct V_379 * V_125 ,
struct V_251 * V_252 , int V_380 )
{
const struct V_4 * V_20 , * V_385 ;
T_11 V_387 , V_388 ;
const struct V_375 * V_376 = F_216 ( (struct V_2 * ) V_252 ) ;
int V_382 = V_252 -> V_408 - V_384 ;
if ( V_382 < 0 )
V_382 = 0 ;
V_20 = & V_376 -> V_378 ;
V_385 = & V_376 -> V_409 ;
V_387 = F_109 ( V_252 -> V_410 ) ;
V_388 = F_109 ( V_252 -> V_411 ) ;
F_224 ( V_125 ,
L_7
L_8 ,
V_380 ,
V_385 -> V_19 [ 0 ] , V_385 -> V_19 [ 1 ] ,
V_385 -> V_19 [ 2 ] , V_385 -> V_19 [ 3 ] , V_388 ,
V_20 -> V_19 [ 0 ] , V_20 -> V_19 [ 1 ] ,
V_20 -> V_19 [ 2 ] , V_20 -> V_19 [ 3 ] , V_387 ,
V_252 -> V_412 , 0 , 0 ,
3 , F_225 ( V_382 ) , 0 , 0 , 0 , 0 ,
F_230 ( & V_252 -> V_413 ) , V_252 ) ;
}
static int F_233 ( struct V_379 * V_125 , void * V_414 )
{
struct V_415 * V_416 ;
if ( V_414 == V_417 ) {
F_234 ( V_125 ,
L_10
L_11
L_12
L_13
L_14 ) ;
goto V_133;
}
V_416 = V_125 -> V_418 ;
switch ( V_416 -> V_419 ) {
case V_420 :
case V_421 :
F_226 ( V_125 , V_414 , V_416 -> V_422 ) ;
break;
case V_423 :
F_223 ( V_125 , V_416 -> V_424 , V_414 , V_416 -> V_422 , V_416 -> V_381 ) ;
break;
case V_425 :
F_232 ( V_125 , V_414 , V_416 -> V_422 ) ;
break;
}
V_133:
return 0 ;
}
int T_12 F_235 ( struct V_126 * V_126 )
{
return F_236 ( V_126 , & V_426 ) ;
}
void F_237 ( struct V_126 * V_126 )
{
F_238 ( V_126 , & V_426 ) ;
}
static int T_12 F_239 ( struct V_126 * V_126 )
{
return F_240 ( & V_126 -> V_231 . F_16 , V_427 ,
V_428 , V_16 , V_126 ) ;
}
static void T_13 F_241 ( struct V_126 * V_126 )
{
F_242 ( V_126 -> V_231 . F_16 ) ;
}
static void T_13 F_243 ( struct V_429 * V_430 )
{
F_244 ( & V_128 , & V_100 , V_48 ) ;
}
int T_14 F_245 ( void )
{
int V_349 ;
V_349 = F_246 ( & V_431 , V_16 ) ;
if ( V_349 )
goto V_133;
V_349 = F_247 ( & V_432 ) ;
if ( V_349 )
goto V_433;
V_349 = F_248 ( & V_434 ) ;
if ( V_349 )
goto V_435;
V_133:
return V_349 ;
V_433:
F_249 ( & V_431 , V_16 ) ;
V_435:
F_250 ( & V_432 ) ;
goto V_133;
}
void F_251 ( void )
{
F_252 ( & V_434 ) ;
F_250 ( & V_432 ) ;
F_249 ( & V_431 , V_16 ) ;
}
