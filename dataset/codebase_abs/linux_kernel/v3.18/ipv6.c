static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != V_4 ) {
if ( F_2 ( V_2 ) -> V_5 == & V_6 ) {
F_3 ( V_2 ) ;
return;
}
F_4 () ;
F_5 ( V_2 , NULL ) ;
F_6 () ;
}
}
static inline T_1 F_7 ( struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const struct V_9 * V_11 )
{
return F_8 ( V_10 , V_11 , V_8 -> V_12 , V_13 , V_8 -> V_14 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_17 * V_18 = V_17 ( V_8 ) ;
F_11 ( V_8 ) ;
V_18 -> V_19 = F_7 ( V_8 , & V_16 -> V_10 , & V_2 -> V_20 ) ;
}
static inline T_2 F_12 ( struct V_7 * V_8 )
{
return F_13 ( F_14 ( V_8 ) -> V_11 . V_21 ,
F_14 ( V_8 ) -> V_10 . V_21 ,
V_17 ( V_8 ) -> V_22 ,
V_17 ( V_8 ) -> V_23 ) ;
}
static void F_15 ( struct V_7 * V_8 , struct V_24 * V_25 ,
T_3 type , T_3 V_26 , int V_27 , T_4 V_28 )
{
const struct V_29 * V_30 = ( const struct V_29 * ) V_8 -> V_31 ;
const struct V_17 * V_18 = (struct V_17 * ) ( V_8 -> V_31 + V_27 ) ;
struct V_32 * V_33 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_34 ;
T_2 V_35 ;
struct V_36 * V_36 = F_16 ( V_8 -> V_37 ) ;
if ( V_8 -> V_12 < V_27 + sizeof( * V_18 ) ||
V_8 -> V_12 < V_27 + F_17 ( V_18 ) ) {
F_18 ( V_36 , F_19 ( V_8 -> V_37 ) ,
V_38 ) ;
return;
}
V_2 = F_20 ( V_36 , & V_39 ,
& V_30 -> V_11 , V_18 -> V_22 ,
& V_30 -> V_10 , V_18 -> V_23 , F_21 ( V_8 ) ) ;
if ( V_2 == NULL ) {
F_18 ( V_36 , F_19 ( V_8 -> V_37 ) ,
V_38 ) ;
return;
}
if ( V_2 -> V_3 == V_40 ) {
F_22 ( F_23 ( V_2 ) ) ;
return;
}
F_24 ( V_2 ) ;
if ( F_25 ( V_2 ) )
F_26 ( V_36 , V_41 ) ;
if ( V_2 -> V_3 == V_4 )
goto V_42;
V_33 = F_27 ( V_2 ) ;
V_35 = F_28 ( V_18 ) ;
if ( ( 1 << V_2 -> V_3 ) & ~ ( V_43 | V_44 ) &&
! F_29 ( V_35 , V_33 -> V_45 , V_33 -> V_46 ) ) {
F_26 ( V_36 , V_47 ) ;
goto V_42;
}
V_16 = F_10 ( V_2 ) ;
if ( type == V_48 ) {
struct V_49 * V_50 = F_30 ( V_2 , V_16 -> V_51 ) ;
if ( V_50 )
V_50 -> V_52 -> V_53 ( V_50 , V_2 , V_8 ) ;
goto V_42;
}
if ( type == V_54 ) {
struct V_49 * V_50 = NULL ;
if ( ! F_31 ( V_2 ) )
goto V_42;
if ( F_25 ( V_2 ) )
goto V_42;
if ( ( 1 << V_2 -> V_3 ) & ( V_44 | V_55 ) )
goto V_42;
V_50 = F_32 ( V_2 , F_33 ( V_28 ) ) ;
if ( ! V_50 )
goto V_42;
if ( F_2 ( V_2 ) -> V_56 > F_34 ( V_50 ) )
F_35 ( V_2 , F_34 ( V_50 ) ) ;
goto V_42;
}
F_36 ( type , V_26 , & V_34 ) ;
switch ( V_2 -> V_3 ) {
struct V_57 * V_58 , * * V_59 ;
case V_60 :
if ( F_25 ( V_2 ) )
goto V_42;
V_58 = F_37 ( V_2 , & V_59 , V_18 -> V_22 ,
& V_30 -> V_11 , & V_30 -> V_10 ,
F_21 ( V_8 ) ) ;
if ( V_58 == NULL )
goto V_42;
F_38 ( V_58 -> V_2 != NULL ) ;
if ( ! F_29 ( V_35 , F_39 ( V_58 ) -> V_61 ,
F_39 ( V_58 ) -> V_62 ) ) {
F_26 ( V_36 , V_47 ) ;
goto V_42;
}
F_40 ( V_2 , V_58 , V_59 ) ;
goto V_42;
case V_63 :
case V_64 :
if ( ! F_25 ( V_2 ) ) {
F_41 ( V_65 ) ;
V_2 -> V_66 = V_34 ;
V_2 -> V_67 ( V_2 ) ;
F_42 ( V_2 ) ;
} else
V_2 -> V_68 = V_34 ;
goto V_42;
}
if ( ! F_25 ( V_2 ) && V_16 -> V_69 ) {
V_2 -> V_66 = V_34 ;
V_2 -> V_67 ( V_2 ) ;
} else
V_2 -> V_68 = V_34 ;
V_42:
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static int F_45 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
struct V_70 * V_71 = F_46 ( V_58 ) ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_9 * V_72 , V_73 ;
struct V_74 V_75 ;
int V_34 = - 1 ;
struct V_49 * V_50 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_76 = V_13 ;
V_75 . V_11 = V_71 -> V_77 ;
V_75 . V_10 = V_71 -> V_78 ;
V_75 . V_79 = 0 ;
V_75 . V_80 = V_71 -> V_81 ;
V_75 . V_82 = V_71 -> V_83 ;
V_75 . V_84 = F_47 ( V_71 -> V_85 ) ;
F_48 ( V_58 , F_49 ( & V_75 ) ) ;
V_72 = F_50 ( & V_75 , V_16 -> V_25 , & V_73 ) ;
V_50 = F_51 ( V_2 , & V_75 , V_72 ) ;
if ( F_52 ( V_50 ) ) {
V_34 = F_53 ( V_50 ) ;
V_50 = NULL ;
goto V_86;
}
V_8 = F_54 ( V_2 , V_50 , V_58 ) ;
if ( V_8 != NULL ) {
struct V_17 * V_18 = V_17 ( V_8 ) ;
V_18 -> V_19 = F_7 ( V_8 ,
& V_71 -> V_78 ,
& V_71 -> V_77 ) ;
V_75 . V_11 = V_71 -> V_77 ;
V_34 = F_55 ( V_2 , V_8 , & V_75 , V_16 -> V_25 , V_16 -> V_87 ) ;
V_34 = F_56 ( V_34 ) ;
}
V_86:
F_57 ( V_50 ) ;
return V_34 ;
}
static void F_58 ( struct V_57 * V_58 )
{
F_59 ( & F_39 ( V_58 ) -> V_88 ) ;
F_60 ( F_46 ( V_58 ) -> V_89 ) ;
}
static void F_61 ( struct V_1 * V_2 , struct V_7 * V_90 )
{
const struct V_29 * V_91 ;
struct V_7 * V_8 ;
struct V_74 V_75 ;
struct V_36 * V_36 = F_16 ( F_62 ( V_90 ) -> V_37 ) ;
struct V_1 * V_92 = V_36 -> V_93 . V_94 ;
struct V_49 * V_50 ;
if ( V_17 ( V_90 ) -> V_95 == V_96 )
return;
if ( ! F_63 ( V_90 ) )
return;
V_8 = F_64 ( V_92 , V_90 ) ;
if ( V_8 == NULL )
return;
V_91 = F_14 ( V_90 ) ;
V_17 ( V_8 ) -> V_19 = F_7 ( V_8 , & V_91 -> V_10 ,
& V_91 -> V_11 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_11 = V_91 -> V_10 ;
V_75 . V_10 = V_91 -> V_11 ;
V_75 . V_76 = V_13 ;
V_75 . V_80 = F_21 ( V_90 ) ;
V_75 . V_82 = V_17 ( V_8 ) -> V_22 ;
V_75 . V_84 = V_17 ( V_8 ) -> V_23 ;
F_65 ( V_90 , F_49 ( & V_75 ) ) ;
V_50 = F_51 ( V_92 , & V_75 , NULL ) ;
if ( ! F_52 ( V_50 ) ) {
F_66 ( V_8 , V_50 ) ;
F_55 ( V_92 , V_8 , & V_75 , NULL , 0 ) ;
F_41 ( V_97 ) ;
F_41 ( V_98 ) ;
return;
}
F_60 ( V_8 ) ;
}
static struct V_1 * F_67 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
const struct V_17 * V_18 = V_17 ( V_8 ) ;
const struct V_29 * V_99 = F_14 ( V_8 ) ;
struct V_1 * V_100 ;
struct V_57 * * V_59 ;
struct V_57 * V_58 = F_37 ( V_2 , & V_59 ,
V_18 -> V_23 ,
& V_99 -> V_10 ,
& V_99 -> V_11 ,
F_21 ( V_8 ) ) ;
if ( V_58 != NULL )
return F_68 ( V_2 , V_8 , V_58 , V_59 ) ;
V_100 = F_69 ( F_70 ( V_2 ) , & V_39 ,
& V_99 -> V_10 , V_18 -> V_23 ,
& V_99 -> V_11 , F_71 ( V_18 -> V_22 ) ,
F_21 ( V_8 ) ) ;
if ( V_100 != NULL ) {
if ( V_100 -> V_3 != V_40 ) {
F_24 ( V_100 ) ;
return V_100 ;
}
F_22 ( F_23 ( V_100 ) ) ;
return NULL ;
}
return V_2 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_57 * V_58 ;
struct V_101 * V_102 ;
struct V_70 * V_71 ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
const T_4 V_103 = F_73 ( V_8 ) -> V_104 ;
struct V_105 * V_106 = F_74 ( V_8 ) ;
if ( V_8 -> V_107 == F_47 ( V_108 ) )
return F_75 ( V_2 , V_8 ) ;
if ( ! F_63 ( V_8 ) )
return 0 ;
if ( F_76 ( V_2 , V_103 ) ) {
V_106 -> V_109 = V_110 ;
goto V_111;
}
V_106 -> V_109 = V_112 ;
if ( F_77 ( V_2 ) )
goto V_111;
if ( F_78 ( V_2 ) && F_79 ( V_2 ) > 1 )
goto V_111;
V_58 = F_80 ( & V_113 ) ;
if ( V_58 == NULL )
goto V_111;
if ( F_81 ( V_58 , F_27 ( V_2 ) , V_8 ) )
goto V_114;
V_102 = F_39 ( V_58 ) ;
if ( F_82 ( V_2 , V_102 , V_8 ) )
goto V_114;
if ( F_83 ( V_2 , V_8 , V_58 ) )
goto V_114;
V_71 = F_46 ( V_58 ) ;
V_71 -> V_77 = F_14 ( V_8 ) -> V_10 ;
V_71 -> V_78 = F_14 ( V_8 ) -> V_11 ;
if ( F_84 ( V_2 , V_8 , F_85 ( V_8 ) ) ||
V_16 -> V_115 . V_116 . V_117 || V_16 -> V_115 . V_116 . V_118 ||
V_16 -> V_115 . V_116 . V_119 || V_16 -> V_115 . V_116 . V_120 ) {
F_86 ( & V_8 -> V_121 ) ;
V_71 -> V_89 = V_8 ;
}
V_71 -> V_81 = V_2 -> V_122 ;
if ( ! V_2 -> V_122 &&
F_87 ( & V_71 -> V_77 ) & V_123 )
V_71 -> V_81 = F_21 ( V_8 ) ;
V_102 -> V_124 = V_106 -> V_125 ;
V_102 -> V_126 = V_102 -> V_124 ;
V_102 -> V_61 = F_12 ( V_8 ) ;
V_102 -> V_62 = V_102 -> V_61 ;
V_102 -> V_127 = V_103 ;
if ( F_45 ( V_2 , V_58 ) )
goto V_114;
F_88 ( V_2 , V_58 , V_128 ) ;
return 0 ;
V_114:
F_89 ( V_58 ) ;
V_111:
F_41 ( V_65 ) ;
return - 1 ;
}
static struct V_1 * F_90 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_57 * V_58 ,
struct V_49 * V_50 )
{
struct V_70 * V_71 = F_46 ( V_58 ) ;
struct V_15 * V_129 , * V_16 = F_10 ( V_2 ) ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
struct V_1 * V_134 ;
if ( V_8 -> V_107 == F_47 ( V_108 ) ) {
V_134 = F_91 ( V_2 , V_8 , V_58 , V_50 ) ;
if ( V_134 == NULL )
return NULL ;
V_133 = (struct V_132 * ) V_134 ;
V_131 = F_92 ( V_134 ) ;
V_131 -> V_135 = & V_133 -> V_136 ;
V_129 = F_10 ( V_134 ) ;
memcpy ( V_129 , V_16 , sizeof( struct V_15 ) ) ;
F_93 ( V_131 -> V_137 , & V_134 -> V_20 ) ;
F_93 ( V_131 -> V_138 , & V_129 -> V_10 ) ;
V_134 -> V_139 = V_129 -> V_10 ;
F_2 ( V_134 ) -> V_5 = & V_6 ;
V_134 -> V_140 = V_141 ;
V_129 -> V_142 = NULL ;
V_129 -> V_25 = NULL ;
V_129 -> V_143 = F_21 ( V_8 ) ;
V_129 -> V_144 = F_14 ( V_8 ) -> V_145 ;
F_35 ( V_134 , F_2 ( V_134 ) -> V_56 ) ;
return V_134 ;
}
if ( F_78 ( V_2 ) )
goto V_146;
if ( V_50 == NULL ) {
struct V_9 * V_72 , V_73 ;
struct V_74 V_75 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_76 = V_13 ;
V_75 . V_11 = V_71 -> V_77 ;
V_72 = F_50 ( & V_75 , V_16 -> V_25 , & V_73 ) ;
V_75 . V_10 = V_71 -> V_78 ;
V_75 . V_80 = V_2 -> V_122 ;
V_75 . V_82 = V_71 -> V_83 ;
V_75 . V_84 = F_47 ( V_71 -> V_85 ) ;
F_94 ( V_2 , F_49 ( & V_75 ) ) ;
V_50 = F_51 ( V_2 , & V_75 , V_72 ) ;
if ( F_52 ( V_50 ) )
goto V_42;
}
V_134 = F_95 ( V_2 , V_58 , V_8 ) ;
if ( V_134 == NULL )
goto V_147;
F_96 ( V_134 , V_50 , NULL , NULL ) ;
V_134 -> V_148 = V_50 -> V_37 -> V_149 & ~ ( V_150 |
V_151 ) ;
V_133 = (struct V_132 * ) V_134 ;
V_131 = F_92 ( V_134 ) ;
V_131 -> V_135 = & V_133 -> V_136 ;
V_129 = F_10 ( V_134 ) ;
memcpy ( V_129 , V_16 , sizeof( struct V_15 ) ) ;
V_134 -> V_20 = V_71 -> V_77 ;
V_129 -> V_10 = V_71 -> V_78 ;
V_134 -> V_139 = V_71 -> V_78 ;
V_134 -> V_122 = V_71 -> V_81 ;
V_131 -> V_152 = NULL ;
V_129 -> V_115 . V_153 = V_16 -> V_115 . V_153 ;
V_129 -> V_142 = NULL ;
if ( V_71 -> V_89 != NULL ) {
V_129 -> V_142 = F_97 ( V_71 -> V_89 , V_154 ) ;
F_98 ( V_71 -> V_89 ) ;
V_71 -> V_89 = NULL ;
if ( V_129 -> V_142 )
F_99 ( V_129 -> V_142 , V_134 ) ;
}
V_129 -> V_25 = NULL ;
V_129 -> V_143 = F_21 ( V_8 ) ;
V_129 -> V_144 = F_14 ( V_8 ) -> V_145 ;
if ( V_16 -> V_25 != NULL )
V_129 -> V_25 = F_100 ( V_134 , V_16 -> V_25 ) ;
F_2 ( V_134 ) -> V_155 = 0 ;
if ( V_129 -> V_25 != NULL )
F_2 ( V_134 ) -> V_155 = ( V_129 -> V_25 -> V_156 +
V_129 -> V_25 -> V_157 ) ;
F_35 ( V_134 , F_34 ( V_50 ) ) ;
V_131 -> V_137 = V_131 -> V_138 = V_158 ;
V_131 -> V_159 = V_158 ;
if ( F_101 ( V_2 , V_134 ) < 0 ) {
F_102 ( V_134 ) ;
F_42 ( V_134 ) ;
goto V_42;
}
F_5 ( V_134 , NULL ) ;
return V_134 ;
V_146:
F_26 ( F_70 ( V_2 ) , V_160 ) ;
V_147:
F_57 ( V_50 ) ;
V_42:
F_26 ( F_70 ( V_2 ) , V_161 ) ;
return NULL ;
}
static int F_103 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_7 * V_162 = NULL ;
if ( V_8 -> V_107 == F_47 ( V_108 ) )
return V_141 ( V_2 , V_8 ) ;
if ( F_104 ( V_2 , V_8 ) )
goto V_163;
if ( V_16 -> V_115 . V_153 )
V_162 = F_97 ( V_8 , V_154 ) ;
if ( V_2 -> V_3 == V_164 ) {
if ( F_105 ( V_2 , V_8 , V_17 ( V_8 ) , V_8 -> V_12 ) )
goto V_165;
if ( V_162 ) {
F_106 ( V_162 ) ;
}
return 0 ;
}
if ( V_2 -> V_3 == V_60 ) {
struct V_1 * V_100 = F_67 ( V_2 , V_8 ) ;
if ( V_100 == NULL )
goto V_163;
if ( V_100 != V_2 ) {
if ( F_107 ( V_2 , V_100 , V_8 ) )
goto V_165;
if ( V_162 != NULL )
F_106 ( V_162 ) ;
return 0 ;
}
}
if ( F_108 ( V_2 , V_8 , V_17 ( V_8 ) , V_8 -> V_12 ) )
goto V_165;
if ( V_162 ) {
F_106 ( V_162 ) ;
}
return 0 ;
V_165:
F_61 ( V_2 , V_8 ) ;
V_163:
if ( V_162 != NULL )
F_106 ( V_162 ) ;
F_60 ( V_8 ) ;
return 0 ;
}
static int F_109 ( struct V_7 * V_8 )
{
const struct V_17 * V_18 ;
struct V_1 * V_2 ;
int V_166 ;
if ( F_110 ( V_8 ) )
goto V_167;
if ( F_7 ( V_8 , & F_14 ( V_8 ) -> V_10 ,
& F_14 ( V_8 ) -> V_11 ) ) {
F_111 ( L_1 ) ;
goto V_167;
}
V_18 = V_17 ( V_8 ) ;
F_74 ( V_8 ) -> V_125 = F_28 ( V_18 ) ;
F_74 ( V_8 ) -> V_168 = V_18 -> V_95 ;
if ( F_112 ( V_8 ) )
F_74 ( V_8 ) -> V_169 = V_170 ;
else
F_74 ( V_8 ) -> V_169 = F_113 ( V_8 ) ;
V_2 = F_114 ( & V_39 , V_8 ,
V_18 -> V_23 , V_18 -> V_22 ,
F_21 ( V_8 ) ) ;
if ( V_2 == NULL ) {
F_115 ( L_2
L_3 ) ;
goto V_171;
}
if ( V_2 -> V_3 == V_40 ) {
F_115 ( L_4 ) ;
F_22 ( F_23 ( V_2 ) ) ;
goto V_171;
}
V_166 = F_27 ( V_2 ) -> V_172 ;
if ( V_18 -> V_173 && ( V_166 == 0 || V_18 -> V_173 < V_166 ) ) {
F_115 ( L_5 ,
V_18 -> V_173 , V_166 ) ;
goto V_174;
}
if ( ! F_116 ( V_2 , V_175 , V_8 ) )
goto V_174;
return F_117 ( V_2 , V_8 , 1 ) ? - 1 : 0 ;
V_171:
if ( ! F_116 ( NULL , V_175 , V_8 ) )
goto V_167;
if ( V_18 -> V_95 != V_96 ) {
F_74 ( V_8 ) -> V_109 =
V_176 ;
F_61 ( V_2 , V_8 ) ;
}
V_167:
F_60 ( V_8 ) ;
return 0 ;
V_174:
F_44 ( V_2 ) ;
goto V_167;
}
static int F_118 ( struct V_1 * V_2 , struct V_177 * V_178 ,
int V_179 )
{
struct V_180 * V_181 = (struct V_180 * ) V_178 ;
struct V_182 * V_183 = F_2 ( V_2 ) ;
struct V_130 * V_184 = F_92 ( V_2 ) ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_32 * V_33 = F_27 ( V_2 ) ;
struct V_9 * V_10 = NULL , * V_72 , V_73 ;
struct V_74 V_75 ;
struct V_49 * V_50 ;
int V_185 ;
int V_34 ;
V_33 -> V_186 = V_187 ;
if ( V_179 < V_188 )
return - V_189 ;
if ( V_181 -> V_190 != V_191 )
return - V_192 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
if ( V_16 -> V_193 ) {
V_75 . V_79 = V_181 -> V_194 & V_195 ;
F_119 ( V_75 . V_79 ) ;
if ( V_75 . V_79 & V_196 ) {
struct V_197 * V_79 ;
V_79 = F_120 ( V_2 , V_75 . V_79 ) ;
if ( V_79 == NULL )
return - V_189 ;
F_121 ( V_79 ) ;
}
}
if ( F_122 ( & V_181 -> V_198 ) )
V_181 -> V_198 . V_199 [ 15 ] = 1 ;
V_185 = F_87 ( & V_181 -> V_198 ) ;
if ( V_185 & V_200 )
return - V_201 ;
if ( V_185 & V_123 ) {
if ( V_179 >= sizeof( struct V_180 ) &&
V_181 -> V_202 ) {
if ( V_2 -> V_122 &&
V_2 -> V_122 != V_181 -> V_202 )
return - V_189 ;
V_2 -> V_122 = V_181 -> V_202 ;
}
if ( ! V_2 -> V_122 )
return - V_189 ;
}
V_2 -> V_20 = V_181 -> V_198 ;
V_16 -> V_203 = V_75 . V_79 ;
if ( V_185 == V_204 ) {
T_5 V_205 = V_183 -> V_155 ;
struct V_206 sin ;
F_123 ( V_2 , L_6 ) ;
if ( F_124 ( V_2 ) )
return - V_201 ;
sin . V_207 = V_208 ;
sin . V_209 = V_181 -> V_210 ;
sin . V_211 . V_212 = V_181 -> V_198 . V_21 [ 3 ] ;
V_183 -> V_5 = & V_6 ;
V_2 -> V_140 = V_141 ;
V_34 = F_125 ( V_2 , (struct V_177 * ) & sin , sizeof( sin ) ) ;
if ( V_34 ) {
V_183 -> V_155 = V_205 ;
V_183 -> V_5 = & V_213 ;
V_2 -> V_140 = F_103 ;
goto V_214;
}
F_93 ( V_184 -> V_138 , & V_16 -> V_10 ) ;
F_93 ( V_184 -> V_159 , & V_2 -> V_139 ) ;
return V_34 ;
}
if ( ! F_122 ( & V_2 -> V_139 ) )
V_10 = & V_2 -> V_139 ;
V_75 . V_76 = V_13 ;
V_75 . V_11 = V_2 -> V_20 ;
V_75 . V_10 = V_10 ? * V_10 : V_16 -> V_10 ;
V_75 . V_80 = V_2 -> V_122 ;
V_75 . V_82 = V_181 -> V_210 ;
V_75 . V_84 = V_184 -> V_215 ;
F_94 ( V_2 , F_49 ( & V_75 ) ) ;
V_72 = F_50 ( & V_75 , V_16 -> V_25 , & V_73 ) ;
V_50 = F_51 ( V_2 , & V_75 , V_72 ) ;
if ( F_52 ( V_50 ) ) {
V_34 = F_53 ( V_50 ) ;
goto V_214;
}
if ( V_10 == NULL ) {
V_10 = & V_75 . V_10 ;
V_2 -> V_139 = * V_10 ;
}
V_16 -> V_10 = * V_10 ;
V_184 -> V_159 = V_158 ;
F_96 ( V_2 , V_50 , NULL , NULL ) ;
V_183 -> V_155 = 0 ;
if ( V_16 -> V_25 != NULL )
V_183 -> V_155 = ( V_16 -> V_25 -> V_157 +
V_16 -> V_25 -> V_156 ) ;
V_184 -> V_216 = V_181 -> V_210 ;
F_126 ( V_2 , V_63 ) ;
V_34 = F_127 ( & V_217 , V_2 ) ;
if ( V_34 )
goto V_218;
V_33 -> V_219 = F_13 ( V_16 -> V_10 . V_21 ,
V_2 -> V_20 . V_21 ,
V_184 -> V_215 ,
V_184 -> V_216 ) ;
V_34 = F_128 ( V_2 ) ;
if ( V_34 )
goto V_218;
return 0 ;
V_218:
F_126 ( V_2 , V_4 ) ;
F_129 ( V_2 ) ;
V_214:
V_184 -> V_216 = 0 ;
V_2 -> V_148 = 0 ;
return V_34 ;
}
static int F_130 ( struct V_1 * V_2 )
{
static T_6 V_220 ;
int V_34 = F_131 ( V_2 , V_220 ) ;
if ( V_34 == 0 ) {
if ( F_132 ( ! V_220 ) )
V_220 = 1 ;
F_2 ( V_2 ) -> V_5 = & V_213 ;
}
return V_34 ;
}
static void F_133 ( struct V_1 * V_2 )
{
F_134 ( V_2 ) ;
F_135 ( V_2 ) ;
}
static int T_7 F_136 ( struct V_36 * V_36 )
{
if ( V_39 . V_221 == NULL )
return - V_222 ;
return F_137 ( & V_36 -> V_93 . V_94 , V_223 ,
V_224 , V_13 , V_36 ) ;
}
static void T_8 F_138 ( struct V_36 * V_36 )
{
F_139 ( V_36 -> V_93 . V_94 ) ;
}
static int T_9 F_140 ( void )
{
int V_34 = F_141 ( & V_225 , 1 ) ;
if ( V_34 != 0 )
goto V_42;
V_34 = F_142 ( & V_226 , V_13 ) ;
if ( V_34 != 0 )
goto V_227;
F_143 ( & V_228 ) ;
V_34 = F_144 ( & V_229 ) ;
if ( V_34 != 0 )
goto V_230;
V_42:
return V_34 ;
V_230:
F_145 ( & V_226 , V_13 ) ;
F_146 ( & V_228 ) ;
V_227:
F_147 ( & V_225 ) ;
goto V_42;
}
static void T_10 F_148 ( void )
{
F_149 ( & V_229 ) ;
F_145 ( & V_226 , V_13 ) ;
F_146 ( & V_228 ) ;
F_147 ( & V_225 ) ;
}
