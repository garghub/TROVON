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
V_18 -> V_19 = F_7 ( V_8 , & V_16 -> V_10 , & V_16 -> V_11 ) ;
}
static inline T_2 F_12 ( struct V_7 * V_8 )
{
return F_13 ( F_14 ( V_8 ) -> V_11 . V_20 ,
F_14 ( V_8 ) -> V_10 . V_20 ,
V_17 ( V_8 ) -> V_21 ,
V_17 ( V_8 ) -> V_22 ) ;
}
static void F_15 ( struct V_7 * V_8 , struct V_23 * V_24 ,
T_3 type , T_3 V_25 , int V_26 , T_4 V_27 )
{
const struct V_28 * V_29 = ( const struct V_28 * ) V_8 -> V_30 ;
const struct V_17 * V_18 = (struct V_17 * ) ( V_8 -> V_30 + V_26 ) ;
struct V_31 * V_32 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_33 ;
T_2 V_34 ;
struct V_35 * V_35 = F_16 ( V_8 -> V_36 ) ;
if ( V_8 -> V_12 < V_26 + sizeof( * V_18 ) ||
V_8 -> V_12 < V_26 + F_17 ( V_18 ) ) {
F_18 ( V_35 , F_19 ( V_8 -> V_36 ) ,
V_37 ) ;
return;
}
V_2 = F_20 ( V_35 , & V_38 ,
& V_29 -> V_11 , V_18 -> V_21 ,
& V_29 -> V_10 , V_18 -> V_22 , F_21 ( V_8 ) ) ;
if ( V_2 == NULL ) {
F_18 ( V_35 , F_19 ( V_8 -> V_36 ) ,
V_37 ) ;
return;
}
if ( V_2 -> V_3 == V_39 ) {
F_22 ( F_23 ( V_2 ) ) ;
return;
}
F_24 ( V_2 ) ;
if ( F_25 ( V_2 ) )
F_26 ( V_35 , V_40 ) ;
if ( V_2 -> V_3 == V_4 )
goto V_41;
V_32 = F_27 ( V_2 ) ;
V_34 = F_28 ( V_18 ) ;
if ( ( 1 << V_2 -> V_3 ) & ~ ( V_42 | V_43 ) &&
! F_29 ( V_34 , V_32 -> V_44 , V_32 -> V_45 ) ) {
F_26 ( V_35 , V_46 ) ;
goto V_41;
}
V_16 = F_10 ( V_2 ) ;
if ( type == V_47 ) {
struct V_48 * V_49 = F_30 ( V_2 , V_16 -> V_50 ) ;
if ( V_49 )
V_49 -> V_51 -> V_52 ( V_49 , V_2 , V_8 ) ;
goto V_41;
}
if ( type == V_53 ) {
struct V_48 * V_49 = NULL ;
if ( F_25 ( V_2 ) )
goto V_41;
if ( ( 1 << V_2 -> V_3 ) & ( V_43 | V_54 ) )
goto V_41;
V_49 = F_31 ( V_2 , F_32 ( V_27 ) ) ;
if ( ! V_49 )
goto V_41;
if ( F_2 ( V_2 ) -> V_55 > F_33 ( V_49 ) )
F_34 ( V_2 , F_33 ( V_49 ) ) ;
goto V_41;
}
F_35 ( type , V_25 , & V_33 ) ;
switch ( V_2 -> V_3 ) {
struct V_56 * V_57 , * * V_58 ;
case V_59 :
if ( F_25 ( V_2 ) )
goto V_41;
V_57 = F_36 ( V_2 , & V_58 , V_18 -> V_21 ,
& V_29 -> V_11 , & V_29 -> V_10 ,
F_21 ( V_8 ) ) ;
if ( V_57 == NULL )
goto V_41;
F_37 ( V_57 -> V_2 != NULL ) ;
if ( ! F_29 ( V_34 , F_38 ( V_57 ) -> V_60 ,
F_38 ( V_57 ) -> V_61 ) ) {
F_26 ( V_35 , V_46 ) ;
goto V_41;
}
F_39 ( V_2 , V_57 , V_58 ) ;
goto V_41;
case V_62 :
case V_63 :
if ( ! F_25 ( V_2 ) ) {
F_40 ( V_64 ) ;
V_2 -> V_65 = V_33 ;
V_2 -> V_66 ( V_2 ) ;
F_41 ( V_2 ) ;
} else
V_2 -> V_67 = V_33 ;
goto V_41;
}
if ( ! F_25 ( V_2 ) && V_16 -> V_68 ) {
V_2 -> V_65 = V_33 ;
V_2 -> V_66 ( V_2 ) ;
} else
V_2 -> V_67 = V_33 ;
V_41:
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
struct V_69 * V_70 = F_45 ( V_57 ) ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_9 * V_71 , V_72 ;
struct V_73 V_74 ;
int V_33 = - 1 ;
struct V_48 * V_49 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_75 = V_13 ;
V_74 . V_11 = V_70 -> V_76 ;
V_74 . V_10 = V_70 -> V_77 ;
V_74 . V_78 = 0 ;
V_74 . V_79 = V_70 -> V_80 ;
V_74 . V_81 = F_46 ( V_57 ) -> V_82 ;
V_74 . V_83 = F_46 ( V_57 ) -> V_84 ;
F_47 ( V_57 , F_48 ( & V_74 ) ) ;
V_71 = F_49 ( & V_74 , V_16 -> V_24 , & V_72 ) ;
V_49 = F_50 ( V_2 , & V_74 , V_71 , false ) ;
if ( F_51 ( V_49 ) ) {
V_33 = F_52 ( V_49 ) ;
V_49 = NULL ;
goto V_85;
}
V_8 = F_53 ( V_2 , V_49 , V_57 ) ;
if ( V_8 != NULL ) {
struct V_17 * V_18 = V_17 ( V_8 ) ;
V_18 -> V_19 = F_7 ( V_8 ,
& V_70 -> V_77 ,
& V_70 -> V_76 ) ;
V_74 . V_11 = V_70 -> V_76 ;
V_33 = F_54 ( V_2 , V_8 , & V_74 , V_16 -> V_24 , V_16 -> V_86 ) ;
V_33 = F_55 ( V_33 ) ;
}
V_85:
F_56 ( V_49 ) ;
return V_33 ;
}
static void F_57 ( struct V_56 * V_57 )
{
F_58 ( & F_38 ( V_57 ) -> V_87 ) ;
if ( F_45 ( V_57 ) -> V_88 != NULL )
F_59 ( F_45 ( V_57 ) -> V_88 ) ;
}
static void F_60 ( struct V_1 * V_2 , struct V_7 * V_89 )
{
const struct V_28 * V_90 ;
struct V_7 * V_8 ;
struct V_73 V_74 ;
struct V_35 * V_35 = F_16 ( F_61 ( V_89 ) -> V_36 ) ;
struct V_1 * V_91 = V_35 -> V_92 . V_93 ;
struct V_48 * V_49 ;
if ( V_17 ( V_89 ) -> V_94 == V_95 )
return;
if ( ! F_62 ( V_89 ) )
return;
V_8 = F_63 ( V_91 , V_89 ) ;
if ( V_8 == NULL )
return;
V_90 = F_14 ( V_89 ) ;
V_17 ( V_8 ) -> V_19 = F_7 ( V_8 , & V_90 -> V_10 ,
& V_90 -> V_11 ) ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_11 = V_90 -> V_10 ;
V_74 . V_10 = V_90 -> V_11 ;
V_74 . V_75 = V_13 ;
V_74 . V_79 = F_21 ( V_89 ) ;
V_74 . V_81 = V_17 ( V_8 ) -> V_21 ;
V_74 . V_83 = V_17 ( V_8 ) -> V_22 ;
F_64 ( V_89 , F_48 ( & V_74 ) ) ;
V_49 = F_50 ( V_91 , & V_74 , NULL , false ) ;
if ( ! F_51 ( V_49 ) ) {
F_65 ( V_8 , V_49 ) ;
F_54 ( V_91 , V_8 , & V_74 , NULL , 0 ) ;
F_40 ( V_96 ) ;
F_40 ( V_97 ) ;
return;
}
F_59 ( V_8 ) ;
}
static struct V_1 * F_66 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
const struct V_17 * V_18 = V_17 ( V_8 ) ;
const struct V_28 * V_98 = F_14 ( V_8 ) ;
struct V_1 * V_99 ;
struct V_56 * * V_58 ;
struct V_56 * V_57 = F_36 ( V_2 , & V_58 ,
V_18 -> V_22 ,
& V_98 -> V_10 ,
& V_98 -> V_11 ,
F_21 ( V_8 ) ) ;
if ( V_57 != NULL )
return F_67 ( V_2 , V_8 , V_57 , V_58 ) ;
V_99 = F_68 ( F_69 ( V_2 ) , & V_38 ,
& V_98 -> V_10 , V_18 -> V_22 ,
& V_98 -> V_11 , F_70 ( V_18 -> V_21 ) ,
F_21 ( V_8 ) ) ;
if ( V_99 != NULL ) {
if ( V_99 -> V_3 != V_39 ) {
F_24 ( V_99 ) ;
return V_99 ;
}
F_22 ( F_23 ( V_99 ) ) ;
return NULL ;
}
return V_2 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_56 * V_57 ;
struct V_100 * V_101 ;
struct V_69 * V_70 ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
const T_4 V_102 = F_72 ( V_8 ) -> V_103 ;
struct V_104 * V_105 = F_73 ( V_8 ) ;
if ( V_8 -> V_106 == F_74 ( V_107 ) )
return F_75 ( V_2 , V_8 ) ;
if ( ! F_62 ( V_8 ) )
return 0 ;
if ( F_76 ( V_2 , V_102 ) ) {
V_105 -> V_108 = V_109 ;
goto V_110;
}
V_105 -> V_108 = V_111 ;
if ( F_77 ( V_2 ) )
goto V_110;
if ( F_78 ( V_2 ) && F_79 ( V_2 ) > 1 )
goto V_110;
V_57 = F_80 ( & V_112 ) ;
if ( V_57 == NULL )
goto V_110;
if ( F_81 ( V_57 , F_27 ( V_2 ) , V_8 ) )
goto V_113;
V_101 = F_38 ( V_57 ) ;
if ( F_82 ( V_2 , V_101 , V_8 ) )
goto V_113;
if ( F_83 ( V_2 , V_8 , V_57 ) )
goto V_113;
V_70 = F_45 ( V_57 ) ;
V_70 -> V_76 = F_14 ( V_8 ) -> V_10 ;
V_70 -> V_77 = F_14 ( V_8 ) -> V_11 ;
if ( F_84 ( V_2 , V_8 ) ||
V_16 -> V_114 . V_115 . V_116 || V_16 -> V_114 . V_115 . V_117 ||
V_16 -> V_114 . V_115 . V_118 || V_16 -> V_114 . V_115 . V_119 ) {
F_85 ( & V_8 -> V_120 ) ;
V_70 -> V_88 = V_8 ;
}
V_70 -> V_80 = V_2 -> V_121 ;
if ( ! V_2 -> V_121 &&
F_86 ( & V_70 -> V_76 ) & V_122 )
V_70 -> V_80 = F_21 ( V_8 ) ;
V_101 -> V_123 = V_105 -> V_124 ;
V_101 -> V_125 = V_101 -> V_123 ;
V_101 -> V_60 = F_12 ( V_8 ) ;
V_101 -> V_61 = V_101 -> V_60 ;
V_101 -> V_126 = V_102 ;
if ( F_44 ( V_2 , V_57 ) )
goto V_113;
F_87 ( V_2 , V_57 , V_127 ) ;
return 0 ;
V_113:
F_88 ( V_57 ) ;
V_110:
F_40 ( V_64 ) ;
return - 1 ;
}
static struct V_1 * F_89 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_56 * V_57 ,
struct V_48 * V_49 )
{
struct V_69 * V_70 = F_45 ( V_57 ) ;
struct V_15 * V_128 , * V_16 = F_10 ( V_2 ) ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
struct V_1 * V_133 ;
if ( V_8 -> V_106 == F_74 ( V_107 ) ) {
V_133 = F_90 ( V_2 , V_8 , V_57 , V_49 ) ;
if ( V_133 == NULL )
return NULL ;
V_132 = (struct V_131 * ) V_133 ;
V_130 = F_91 ( V_133 ) ;
V_130 -> V_134 = & V_132 -> V_135 ;
V_128 = F_10 ( V_133 ) ;
memcpy ( V_128 , V_16 , sizeof( struct V_15 ) ) ;
F_92 ( V_130 -> V_136 , & V_128 -> V_11 ) ;
F_92 ( V_130 -> V_137 , & V_128 -> V_10 ) ;
V_128 -> V_138 = V_128 -> V_10 ;
F_2 ( V_133 ) -> V_5 = & V_6 ;
V_133 -> V_139 = V_140 ;
V_128 -> V_141 = NULL ;
V_128 -> V_24 = NULL ;
V_128 -> V_142 = F_21 ( V_8 ) ;
V_128 -> V_143 = F_14 ( V_8 ) -> V_144 ;
F_34 ( V_133 , F_2 ( V_133 ) -> V_55 ) ;
return V_133 ;
}
if ( F_78 ( V_2 ) )
goto V_145;
if ( V_49 == NULL ) {
struct V_9 * V_71 , V_72 ;
struct V_73 V_74 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_75 = V_13 ;
V_74 . V_11 = V_70 -> V_76 ;
V_71 = F_49 ( & V_74 , V_16 -> V_24 , & V_72 ) ;
V_74 . V_10 = V_70 -> V_77 ;
V_74 . V_79 = V_2 -> V_121 ;
V_74 . V_81 = F_46 ( V_57 ) -> V_82 ;
V_74 . V_83 = F_46 ( V_57 ) -> V_84 ;
F_93 ( V_2 , F_48 ( & V_74 ) ) ;
V_49 = F_50 ( V_2 , & V_74 , V_71 , false ) ;
if ( F_51 ( V_49 ) )
goto V_41;
}
V_133 = F_94 ( V_2 , V_57 , V_8 ) ;
if ( V_133 == NULL )
goto V_146;
F_95 ( V_133 , V_49 , NULL , NULL ) ;
V_133 -> V_147 = V_49 -> V_36 -> V_148 & ~ ( V_149 |
V_150 ) ;
V_132 = (struct V_131 * ) V_133 ;
V_130 = F_91 ( V_133 ) ;
V_130 -> V_134 = & V_132 -> V_135 ;
V_128 = F_10 ( V_133 ) ;
memcpy ( V_128 , V_16 , sizeof( struct V_15 ) ) ;
V_128 -> V_11 = V_70 -> V_76 ;
V_128 -> V_10 = V_70 -> V_77 ;
V_128 -> V_138 = V_70 -> V_77 ;
V_133 -> V_121 = V_70 -> V_80 ;
V_130 -> V_151 = NULL ;
V_128 -> V_114 . V_152 = V_16 -> V_114 . V_152 ;
V_128 -> V_141 = NULL ;
if ( V_70 -> V_88 != NULL ) {
V_128 -> V_141 = F_96 ( V_70 -> V_88 , V_153 ) ;
F_97 ( V_70 -> V_88 ) ;
V_70 -> V_88 = NULL ;
if ( V_128 -> V_141 )
F_98 ( V_128 -> V_141 , V_133 ) ;
}
V_128 -> V_24 = NULL ;
V_128 -> V_142 = F_21 ( V_8 ) ;
V_128 -> V_143 = F_14 ( V_8 ) -> V_144 ;
if ( V_16 -> V_24 != NULL )
V_128 -> V_24 = F_99 ( V_133 , V_16 -> V_24 ) ;
F_2 ( V_133 ) -> V_154 = 0 ;
if ( V_128 -> V_24 != NULL )
F_2 ( V_133 ) -> V_154 = ( V_128 -> V_24 -> V_155 +
V_128 -> V_24 -> V_156 ) ;
F_34 ( V_133 , F_33 ( V_49 ) ) ;
V_130 -> V_136 = V_130 -> V_137 = V_157 ;
V_130 -> V_158 = V_157 ;
if ( F_100 ( V_2 , V_133 ) < 0 ) {
F_101 ( V_133 ) ;
F_41 ( V_133 ) ;
goto V_41;
}
F_5 ( V_133 , NULL ) ;
return V_133 ;
V_145:
F_26 ( F_69 ( V_2 ) , V_159 ) ;
V_146:
F_56 ( V_49 ) ;
V_41:
F_26 ( F_69 ( V_2 ) , V_160 ) ;
return NULL ;
}
static int F_102 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_7 * V_161 = NULL ;
if ( V_8 -> V_106 == F_74 ( V_107 ) )
return V_140 ( V_2 , V_8 ) ;
if ( F_103 ( V_2 , V_8 ) )
goto V_162;
if ( V_16 -> V_114 . V_152 )
V_161 = F_96 ( V_8 , V_153 ) ;
if ( V_2 -> V_3 == V_163 ) {
if ( F_104 ( V_2 , V_8 , V_17 ( V_8 ) , V_8 -> V_12 ) )
goto V_164;
if ( V_161 ) {
F_105 ( V_161 ) ;
}
return 0 ;
}
if ( V_2 -> V_3 == V_59 ) {
struct V_1 * V_99 = F_66 ( V_2 , V_8 ) ;
if ( V_99 == NULL )
goto V_162;
if ( V_99 != V_2 ) {
if ( F_106 ( V_2 , V_99 , V_8 ) )
goto V_164;
if ( V_161 != NULL )
F_105 ( V_161 ) ;
return 0 ;
}
}
if ( F_107 ( V_2 , V_8 , V_17 ( V_8 ) , V_8 -> V_12 ) )
goto V_164;
if ( V_161 ) {
F_105 ( V_161 ) ;
}
return 0 ;
V_164:
F_60 ( V_2 , V_8 ) ;
V_162:
if ( V_161 != NULL )
F_105 ( V_161 ) ;
F_59 ( V_8 ) ;
return 0 ;
}
static int F_108 ( struct V_7 * V_8 )
{
const struct V_17 * V_18 ;
struct V_1 * V_2 ;
int V_165 ;
if ( F_109 ( V_8 ) )
goto V_166;
if ( F_7 ( V_8 , & F_14 ( V_8 ) -> V_10 ,
& F_14 ( V_8 ) -> V_11 ) ) {
F_110 ( L_1 ) ;
goto V_166;
}
V_18 = V_17 ( V_8 ) ;
F_73 ( V_8 ) -> V_124 = F_28 ( V_18 ) ;
F_73 ( V_8 ) -> V_167 = V_18 -> V_94 ;
if ( F_111 ( V_8 ) )
F_73 ( V_8 ) -> V_168 = V_169 ;
else
F_73 ( V_8 ) -> V_168 = F_112 ( V_8 ) ;
V_2 = F_113 ( & V_38 , V_8 ,
V_18 -> V_22 , V_18 -> V_21 ) ;
if ( V_2 == NULL ) {
F_114 ( L_2
L_3 ) ;
goto V_170;
}
if ( V_2 -> V_3 == V_39 ) {
F_114 ( L_4 ) ;
F_22 ( F_23 ( V_2 ) ) ;
goto V_170;
}
V_165 = F_27 ( V_2 ) -> V_171 ;
if ( V_18 -> V_172 && ( V_165 == 0 || V_18 -> V_172 < V_165 ) ) {
F_114 ( L_5 ,
V_18 -> V_172 , V_165 ) ;
goto V_173;
}
if ( ! F_115 ( V_2 , V_174 , V_8 ) )
goto V_173;
return F_116 ( V_2 , V_8 , 1 ) ? - 1 : 0 ;
V_170:
if ( ! F_115 ( NULL , V_174 , V_8 ) )
goto V_166;
if ( V_18 -> V_94 != V_95 ) {
F_73 ( V_8 ) -> V_108 =
V_175 ;
F_60 ( V_2 , V_8 ) ;
}
V_166:
F_59 ( V_8 ) ;
return 0 ;
V_173:
F_43 ( V_2 ) ;
goto V_166;
}
static int F_117 ( struct V_1 * V_2 , struct V_176 * V_177 ,
int V_178 )
{
struct V_179 * V_180 = (struct V_179 * ) V_177 ;
struct V_181 * V_182 = F_2 ( V_2 ) ;
struct V_129 * V_183 = F_91 ( V_2 ) ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_31 * V_32 = F_27 ( V_2 ) ;
struct V_9 * V_10 = NULL , * V_71 , V_72 ;
struct V_73 V_74 ;
struct V_48 * V_49 ;
int V_184 ;
int V_33 ;
V_32 -> V_185 = V_186 ;
if ( V_178 < V_187 )
return - V_188 ;
if ( V_180 -> V_189 != V_190 )
return - V_191 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
if ( V_16 -> V_192 ) {
V_74 . V_78 = V_180 -> V_193 & V_194 ;
F_118 ( V_74 . V_78 ) ;
if ( V_74 . V_78 & V_195 ) {
struct V_196 * V_78 ;
V_78 = F_119 ( V_2 , V_74 . V_78 ) ;
if ( V_78 == NULL )
return - V_188 ;
V_180 -> V_197 = V_78 -> V_49 ;
F_120 ( V_78 ) ;
}
}
if ( F_121 ( & V_180 -> V_197 ) )
V_180 -> V_197 . V_198 [ 15 ] = 1 ;
V_184 = F_86 ( & V_180 -> V_197 ) ;
if ( V_184 & V_199 )
return - V_200 ;
if ( V_184 & V_122 ) {
if ( V_178 >= sizeof( struct V_179 ) &&
V_180 -> V_201 ) {
if ( V_2 -> V_121 &&
V_2 -> V_121 != V_180 -> V_201 )
return - V_188 ;
V_2 -> V_121 = V_180 -> V_201 ;
}
if ( ! V_2 -> V_121 )
return - V_188 ;
}
V_16 -> V_11 = V_180 -> V_197 ;
V_16 -> V_202 = V_74 . V_78 ;
if ( V_184 == V_203 ) {
T_5 V_204 = V_182 -> V_154 ;
struct V_205 sin ;
F_122 ( V_2 , L_6 ) ;
if ( F_123 ( V_2 ) )
return - V_200 ;
sin . V_206 = V_207 ;
sin . V_208 = V_180 -> V_209 ;
sin . V_210 . V_211 = V_180 -> V_197 . V_20 [ 3 ] ;
V_182 -> V_5 = & V_6 ;
V_2 -> V_139 = V_140 ;
V_33 = F_124 ( V_2 , (struct V_176 * ) & sin , sizeof( sin ) ) ;
if ( V_33 ) {
V_182 -> V_154 = V_204 ;
V_182 -> V_5 = & V_212 ;
V_2 -> V_139 = F_102 ;
goto V_213;
}
F_92 ( V_183 -> V_137 , & V_16 -> V_10 ) ;
F_92 ( V_183 -> V_158 , & V_16 -> V_138 ) ;
return V_33 ;
}
if ( ! F_121 ( & V_16 -> V_138 ) )
V_10 = & V_16 -> V_138 ;
V_74 . V_75 = V_13 ;
V_74 . V_11 = V_16 -> V_11 ;
V_74 . V_10 = V_10 ? * V_10 : V_16 -> V_10 ;
V_74 . V_79 = V_2 -> V_121 ;
V_74 . V_81 = V_180 -> V_209 ;
V_74 . V_83 = V_183 -> V_214 ;
F_93 ( V_2 , F_48 ( & V_74 ) ) ;
V_71 = F_49 ( & V_74 , V_16 -> V_24 , & V_72 ) ;
V_49 = F_50 ( V_2 , & V_74 , V_71 , true ) ;
if ( F_51 ( V_49 ) ) {
V_33 = F_52 ( V_49 ) ;
goto V_213;
}
if ( V_10 == NULL ) {
V_10 = & V_74 . V_10 ;
V_16 -> V_138 = * V_10 ;
}
V_16 -> V_10 = * V_10 ;
V_183 -> V_158 = V_157 ;
F_95 ( V_2 , V_49 , NULL , NULL ) ;
V_182 -> V_154 = 0 ;
if ( V_16 -> V_24 != NULL )
V_182 -> V_154 = ( V_16 -> V_24 -> V_156 +
V_16 -> V_24 -> V_155 ) ;
V_183 -> V_215 = V_180 -> V_209 ;
F_125 ( V_2 , V_62 ) ;
V_33 = F_126 ( & V_216 , V_2 ) ;
if ( V_33 )
goto V_217;
V_32 -> V_218 = F_13 ( V_16 -> V_10 . V_20 ,
V_16 -> V_11 . V_20 ,
V_183 -> V_214 ,
V_183 -> V_215 ) ;
V_33 = F_127 ( V_2 ) ;
if ( V_33 )
goto V_217;
return 0 ;
V_217:
F_125 ( V_2 , V_4 ) ;
F_128 ( V_2 ) ;
V_213:
V_183 -> V_215 = 0 ;
V_2 -> V_147 = 0 ;
return V_33 ;
}
static int F_129 ( struct V_1 * V_2 )
{
static T_6 V_219 ;
int V_33 = F_130 ( V_2 , V_219 ) ;
if ( V_33 == 0 ) {
if ( F_131 ( ! V_219 ) )
V_219 = 1 ;
F_2 ( V_2 ) -> V_5 = & V_212 ;
}
return V_33 ;
}
static void F_132 ( struct V_1 * V_2 )
{
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
}
static int T_7 F_135 ( struct V_35 * V_35 )
{
if ( V_38 . V_220 == NULL )
return - V_221 ;
return F_136 ( & V_35 -> V_92 . V_93 , V_222 ,
V_223 , V_13 , V_35 ) ;
}
static void T_8 F_137 ( struct V_35 * V_35 )
{
F_138 ( V_35 -> V_92 . V_93 ) ;
}
static int T_9 F_139 ( void )
{
int V_33 = F_140 ( & V_224 , 1 ) ;
if ( V_33 != 0 )
goto V_41;
V_33 = F_141 ( & V_225 , V_13 ) ;
if ( V_33 != 0 )
goto V_226;
F_142 ( & V_227 ) ;
V_33 = F_143 ( & V_228 ) ;
if ( V_33 != 0 )
goto V_229;
V_41:
return V_33 ;
V_229:
F_144 ( & V_225 , V_13 ) ;
F_145 ( & V_227 ) ;
V_226:
F_146 ( & V_224 ) ;
goto V_41;
}
static void T_10 F_147 ( void )
{
F_148 ( & V_228 ) ;
F_144 ( & V_225 , V_13 ) ;
F_145 ( & V_227 ) ;
F_146 ( & V_224 ) ;
}
