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
static int F_44 ( struct V_1 * V_2 , struct V_56 * V_57 ,
struct V_69 * V_70 )
{
struct V_71 * V_72 = F_45 ( V_57 ) ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_9 * V_73 , V_74 ;
struct V_75 V_76 ;
int V_33 = - 1 ;
struct V_48 * V_49 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_77 = V_13 ;
V_76 . V_11 = V_72 -> V_78 ;
V_76 . V_10 = V_72 -> V_79 ;
V_76 . V_80 = 0 ;
V_76 . V_81 = V_72 -> V_82 ;
V_76 . V_83 = F_46 ( V_57 ) -> V_84 ;
V_76 . V_85 = F_46 ( V_57 ) -> V_86 ;
F_47 ( V_57 , F_48 ( & V_76 ) ) ;
V_73 = F_49 ( & V_76 , V_16 -> V_24 , & V_74 ) ;
V_49 = F_50 ( V_2 , & V_76 , V_73 , false ) ;
if ( F_51 ( V_49 ) ) {
V_33 = F_52 ( V_49 ) ;
V_49 = NULL ;
goto V_87;
}
V_8 = F_53 ( V_2 , V_49 , V_57 ) ;
if ( V_8 != NULL ) {
struct V_17 * V_18 = V_17 ( V_8 ) ;
V_18 -> V_19 = F_7 ( V_8 ,
& V_72 -> V_79 ,
& V_72 -> V_78 ) ;
V_76 . V_11 = V_72 -> V_78 ;
V_33 = F_54 ( V_2 , V_8 , & V_76 , V_16 -> V_24 , V_16 -> V_88 ) ;
V_33 = F_55 ( V_33 ) ;
}
V_87:
F_56 ( V_49 ) ;
return V_33 ;
}
static void F_57 ( struct V_56 * V_57 )
{
F_58 ( & F_38 ( V_57 ) -> V_89 ) ;
if ( F_45 ( V_57 ) -> V_90 != NULL )
F_59 ( F_45 ( V_57 ) -> V_90 ) ;
}
static void F_60 ( struct V_1 * V_2 , struct V_7 * V_91 )
{
const struct V_28 * V_92 ;
struct V_7 * V_8 ;
struct V_75 V_76 ;
struct V_35 * V_35 = F_16 ( F_61 ( V_91 ) -> V_36 ) ;
struct V_1 * V_93 = V_35 -> V_94 . V_95 ;
struct V_48 * V_49 ;
if ( V_17 ( V_91 ) -> V_96 == V_97 )
return;
if ( ! F_62 ( V_91 ) )
return;
V_8 = F_63 ( V_93 , V_91 ) ;
if ( V_8 == NULL )
return;
V_92 = F_14 ( V_91 ) ;
V_17 ( V_8 ) -> V_19 = F_7 ( V_8 , & V_92 -> V_10 ,
& V_92 -> V_11 ) ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_11 = V_92 -> V_10 ;
V_76 . V_10 = V_92 -> V_11 ;
V_76 . V_77 = V_13 ;
V_76 . V_81 = F_21 ( V_91 ) ;
V_76 . V_83 = V_17 ( V_8 ) -> V_21 ;
V_76 . V_85 = V_17 ( V_8 ) -> V_22 ;
F_64 ( V_91 , F_48 ( & V_76 ) ) ;
V_49 = F_50 ( V_93 , & V_76 , NULL , false ) ;
if ( ! F_51 ( V_49 ) ) {
F_65 ( V_8 , V_49 ) ;
F_54 ( V_93 , V_8 , & V_76 , NULL , 0 ) ;
F_40 ( V_98 ) ;
F_40 ( V_99 ) ;
return;
}
F_59 ( V_8 ) ;
}
static struct V_1 * F_66 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
const struct V_17 * V_18 = V_17 ( V_8 ) ;
const struct V_28 * V_100 = F_14 ( V_8 ) ;
struct V_1 * V_101 ;
struct V_56 * * V_58 ;
struct V_56 * V_57 = F_36 ( V_2 , & V_58 ,
V_18 -> V_22 ,
& V_100 -> V_10 ,
& V_100 -> V_11 ,
F_21 ( V_8 ) ) ;
if ( V_57 != NULL )
return F_67 ( V_2 , V_8 , V_57 , V_58 ) ;
V_101 = F_68 ( F_69 ( V_2 ) , & V_38 ,
& V_100 -> V_10 , V_18 -> V_22 ,
& V_100 -> V_11 , F_70 ( V_18 -> V_21 ) ,
F_21 ( V_8 ) ) ;
if ( V_101 != NULL ) {
if ( V_101 -> V_3 != V_39 ) {
F_24 ( V_101 ) ;
return V_101 ;
}
F_22 ( F_23 ( V_101 ) ) ;
return NULL ;
}
return V_2 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_56 * V_57 ;
struct V_102 * V_103 ;
struct V_71 * V_72 ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
const T_4 V_104 = F_72 ( V_8 ) -> V_105 ;
struct V_106 * V_107 = F_73 ( V_8 ) ;
if ( V_8 -> V_108 == F_74 ( V_109 ) )
return F_75 ( V_2 , V_8 ) ;
if ( ! F_62 ( V_8 ) )
return 0 ;
if ( F_76 ( V_2 , V_104 ) ) {
V_107 -> V_110 = V_111 ;
goto V_112;
}
V_107 -> V_110 = V_113 ;
if ( F_77 ( V_2 ) )
goto V_112;
if ( F_78 ( V_2 ) && F_79 ( V_2 ) > 1 )
goto V_112;
V_57 = F_80 ( & V_114 ) ;
if ( V_57 == NULL )
goto V_112;
if ( F_81 ( V_57 , F_27 ( V_2 ) , V_8 ) )
goto V_115;
V_103 = F_38 ( V_57 ) ;
if ( F_82 ( V_2 , V_103 , V_8 ) )
goto V_115;
if ( F_83 ( V_2 , V_8 , V_57 ) )
goto V_115;
V_72 = F_45 ( V_57 ) ;
V_72 -> V_78 = F_14 ( V_8 ) -> V_10 ;
V_72 -> V_79 = F_14 ( V_8 ) -> V_11 ;
if ( F_84 ( V_2 , V_8 ) ||
V_16 -> V_116 . V_117 . V_118 || V_16 -> V_116 . V_117 . V_119 ||
V_16 -> V_116 . V_117 . V_120 || V_16 -> V_116 . V_117 . V_121 ) {
F_85 ( & V_8 -> V_122 ) ;
V_72 -> V_90 = V_8 ;
}
V_72 -> V_82 = V_2 -> V_123 ;
if ( ! V_2 -> V_123 &&
F_86 ( & V_72 -> V_78 ) & V_124 )
V_72 -> V_82 = F_21 ( V_8 ) ;
V_103 -> V_125 = V_107 -> V_126 ;
V_103 -> V_127 = V_103 -> V_125 ;
V_103 -> V_60 = F_12 ( V_8 ) ;
V_103 -> V_61 = V_103 -> V_60 ;
V_103 -> V_128 = V_104 ;
if ( F_44 ( V_2 , V_57 , NULL ) )
goto V_115;
F_87 ( V_2 , V_57 , V_129 ) ;
return 0 ;
V_115:
F_88 ( V_57 ) ;
V_112:
F_40 ( V_64 ) ;
return - 1 ;
}
static struct V_1 * F_89 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_56 * V_57 ,
struct V_48 * V_49 )
{
struct V_71 * V_72 = F_45 ( V_57 ) ;
struct V_15 * V_130 , * V_16 = F_10 ( V_2 ) ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
struct V_1 * V_135 ;
if ( V_8 -> V_108 == F_74 ( V_109 ) ) {
V_135 = F_90 ( V_2 , V_8 , V_57 , V_49 ) ;
if ( V_135 == NULL )
return NULL ;
V_134 = (struct V_133 * ) V_135 ;
V_132 = F_91 ( V_135 ) ;
V_132 -> V_136 = & V_134 -> V_137 ;
V_130 = F_10 ( V_135 ) ;
memcpy ( V_130 , V_16 , sizeof( struct V_15 ) ) ;
F_92 ( V_132 -> V_138 , & V_130 -> V_11 ) ;
F_92 ( V_132 -> V_139 , & V_130 -> V_10 ) ;
V_130 -> V_140 = V_130 -> V_10 ;
F_2 ( V_135 ) -> V_5 = & V_6 ;
V_135 -> V_141 = V_142 ;
V_130 -> V_143 = NULL ;
V_130 -> V_24 = NULL ;
V_130 -> V_144 = F_21 ( V_8 ) ;
V_130 -> V_145 = F_14 ( V_8 ) -> V_146 ;
F_34 ( V_135 , F_2 ( V_135 ) -> V_55 ) ;
return V_135 ;
}
if ( F_78 ( V_2 ) )
goto V_147;
if ( V_49 == NULL ) {
struct V_9 * V_73 , V_74 ;
struct V_75 V_76 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_77 = V_13 ;
V_76 . V_11 = V_72 -> V_78 ;
V_73 = F_49 ( & V_76 , V_16 -> V_24 , & V_74 ) ;
V_76 . V_10 = V_72 -> V_79 ;
V_76 . V_81 = V_2 -> V_123 ;
V_76 . V_83 = F_46 ( V_57 ) -> V_84 ;
V_76 . V_85 = F_46 ( V_57 ) -> V_86 ;
F_93 ( V_2 , F_48 ( & V_76 ) ) ;
V_49 = F_50 ( V_2 , & V_76 , V_73 , false ) ;
if ( F_51 ( V_49 ) )
goto V_41;
}
V_135 = F_94 ( V_2 , V_57 , V_8 ) ;
if ( V_135 == NULL )
goto V_148;
F_95 ( V_135 , V_49 , NULL , NULL ) ;
V_135 -> V_149 = V_49 -> V_36 -> V_150 & ~ ( V_151 |
V_152 ) ;
V_134 = (struct V_133 * ) V_135 ;
V_132 = F_91 ( V_135 ) ;
V_132 -> V_136 = & V_134 -> V_137 ;
V_130 = F_10 ( V_135 ) ;
memcpy ( V_130 , V_16 , sizeof( struct V_15 ) ) ;
V_130 -> V_11 = V_72 -> V_78 ;
V_130 -> V_10 = V_72 -> V_79 ;
V_130 -> V_140 = V_72 -> V_79 ;
V_135 -> V_123 = V_72 -> V_82 ;
V_132 -> V_153 = NULL ;
V_130 -> V_116 . V_154 = V_16 -> V_116 . V_154 ;
V_130 -> V_143 = NULL ;
if ( V_72 -> V_90 != NULL ) {
V_130 -> V_143 = F_96 ( V_72 -> V_90 , V_155 ) ;
F_97 ( V_72 -> V_90 ) ;
V_72 -> V_90 = NULL ;
if ( V_130 -> V_143 )
F_98 ( V_130 -> V_143 , V_135 ) ;
}
V_130 -> V_24 = NULL ;
V_130 -> V_144 = F_21 ( V_8 ) ;
V_130 -> V_145 = F_14 ( V_8 ) -> V_146 ;
if ( V_16 -> V_24 != NULL )
V_130 -> V_24 = F_99 ( V_135 , V_16 -> V_24 ) ;
F_2 ( V_135 ) -> V_156 = 0 ;
if ( V_130 -> V_24 != NULL )
F_2 ( V_135 ) -> V_156 = ( V_130 -> V_24 -> V_157 +
V_130 -> V_24 -> V_158 ) ;
F_34 ( V_135 , F_33 ( V_49 ) ) ;
V_132 -> V_138 = V_132 -> V_139 = V_159 ;
V_132 -> V_160 = V_159 ;
if ( F_100 ( V_2 , V_135 ) < 0 ) {
F_101 ( V_135 ) ;
F_41 ( V_135 ) ;
goto V_41;
}
F_5 ( V_135 , NULL ) ;
return V_135 ;
V_147:
F_26 ( F_69 ( V_2 ) , V_161 ) ;
V_148:
F_56 ( V_49 ) ;
V_41:
F_26 ( F_69 ( V_2 ) , V_162 ) ;
return NULL ;
}
static int F_102 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_7 * V_163 = NULL ;
if ( V_8 -> V_108 == F_74 ( V_109 ) )
return V_142 ( V_2 , V_8 ) ;
if ( F_103 ( V_2 , V_8 ) )
goto V_164;
if ( V_16 -> V_116 . V_154 )
V_163 = F_96 ( V_8 , V_155 ) ;
if ( V_2 -> V_3 == V_165 ) {
if ( F_104 ( V_2 , V_8 , V_17 ( V_8 ) , V_8 -> V_12 ) )
goto V_166;
if ( V_163 ) {
F_105 ( V_163 ) ;
}
return 0 ;
}
if ( V_2 -> V_3 == V_59 ) {
struct V_1 * V_101 = F_66 ( V_2 , V_8 ) ;
if ( V_101 == NULL )
goto V_164;
if ( V_101 != V_2 ) {
if ( F_106 ( V_2 , V_101 , V_8 ) )
goto V_166;
if ( V_163 != NULL )
F_105 ( V_163 ) ;
return 0 ;
}
}
if ( F_107 ( V_2 , V_8 , V_17 ( V_8 ) , V_8 -> V_12 ) )
goto V_166;
if ( V_163 ) {
F_105 ( V_163 ) ;
}
return 0 ;
V_166:
F_60 ( V_2 , V_8 ) ;
V_164:
if ( V_163 != NULL )
F_105 ( V_163 ) ;
F_59 ( V_8 ) ;
return 0 ;
}
static int F_108 ( struct V_7 * V_8 )
{
const struct V_17 * V_18 ;
struct V_1 * V_2 ;
int V_167 ;
if ( F_109 ( V_8 ) )
goto V_168;
if ( F_7 ( V_8 , & F_14 ( V_8 ) -> V_10 ,
& F_14 ( V_8 ) -> V_11 ) ) {
F_110 ( L_1 ) ;
goto V_168;
}
V_18 = V_17 ( V_8 ) ;
F_73 ( V_8 ) -> V_126 = F_28 ( V_18 ) ;
F_73 ( V_8 ) -> V_169 = V_18 -> V_96 ;
if ( F_111 ( V_8 ) )
F_73 ( V_8 ) -> V_170 = V_171 ;
else
F_73 ( V_8 ) -> V_170 = F_112 ( V_8 ) ;
V_2 = F_113 ( & V_38 , V_8 ,
V_18 -> V_22 , V_18 -> V_21 ) ;
if ( V_2 == NULL ) {
F_114 ( L_2
L_3 ) ;
goto V_172;
}
if ( V_2 -> V_3 == V_39 ) {
F_114 ( L_4 ) ;
F_22 ( F_23 ( V_2 ) ) ;
goto V_172;
}
V_167 = F_27 ( V_2 ) -> V_173 ;
if ( V_18 -> V_174 && ( V_167 == 0 || V_18 -> V_174 < V_167 ) ) {
F_114 ( L_5 ,
V_18 -> V_174 , V_167 ) ;
goto V_175;
}
if ( ! F_115 ( V_2 , V_176 , V_8 ) )
goto V_175;
return F_116 ( V_2 , V_8 , 1 ) ? - 1 : 0 ;
V_172:
if ( ! F_115 ( NULL , V_176 , V_8 ) )
goto V_168;
if ( V_18 -> V_96 != V_97 ) {
F_73 ( V_8 ) -> V_110 =
V_177 ;
F_60 ( V_2 , V_8 ) ;
}
V_168:
F_59 ( V_8 ) ;
return 0 ;
V_175:
F_43 ( V_2 ) ;
goto V_168;
}
static int F_117 ( struct V_1 * V_2 , struct V_178 * V_179 ,
int V_180 )
{
struct V_181 * V_182 = (struct V_181 * ) V_179 ;
struct V_183 * V_184 = F_2 ( V_2 ) ;
struct V_131 * V_185 = F_91 ( V_2 ) ;
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_31 * V_32 = F_27 ( V_2 ) ;
struct V_9 * V_10 = NULL , * V_73 , V_74 ;
struct V_75 V_76 ;
struct V_48 * V_49 ;
int V_186 ;
int V_33 ;
V_32 -> V_187 = V_188 ;
if ( V_180 < V_189 )
return - V_190 ;
if ( V_182 -> V_191 != V_192 )
return - V_193 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
if ( V_16 -> V_194 ) {
V_76 . V_80 = V_182 -> V_195 & V_196 ;
F_118 ( V_76 . V_80 ) ;
if ( V_76 . V_80 & V_197 ) {
struct V_198 * V_80 ;
V_80 = F_119 ( V_2 , V_76 . V_80 ) ;
if ( V_80 == NULL )
return - V_190 ;
V_182 -> V_199 = V_80 -> V_49 ;
F_120 ( V_80 ) ;
}
}
if ( F_121 ( & V_182 -> V_199 ) )
V_182 -> V_199 . V_200 [ 15 ] = 1 ;
V_186 = F_86 ( & V_182 -> V_199 ) ;
if ( V_186 & V_201 )
return - V_202 ;
if ( V_186 & V_124 ) {
if ( V_180 >= sizeof( struct V_181 ) &&
V_182 -> V_203 ) {
if ( V_2 -> V_123 &&
V_2 -> V_123 != V_182 -> V_203 )
return - V_190 ;
V_2 -> V_123 = V_182 -> V_203 ;
}
if ( ! V_2 -> V_123 )
return - V_190 ;
}
V_16 -> V_11 = V_182 -> V_199 ;
V_16 -> V_204 = V_76 . V_80 ;
if ( V_186 == V_205 ) {
T_5 V_206 = V_184 -> V_156 ;
struct V_207 sin ;
F_122 ( V_2 , L_6 ) ;
if ( F_123 ( V_2 ) )
return - V_202 ;
sin . V_208 = V_209 ;
sin . V_210 = V_182 -> V_211 ;
sin . V_212 . V_213 = V_182 -> V_199 . V_20 [ 3 ] ;
V_184 -> V_5 = & V_6 ;
V_2 -> V_141 = V_142 ;
V_33 = F_124 ( V_2 , (struct V_178 * ) & sin , sizeof( sin ) ) ;
if ( V_33 ) {
V_184 -> V_156 = V_206 ;
V_184 -> V_5 = & V_214 ;
V_2 -> V_141 = F_102 ;
goto V_215;
}
F_92 ( V_185 -> V_139 , & V_16 -> V_10 ) ;
F_92 ( V_185 -> V_160 , & V_16 -> V_140 ) ;
return V_33 ;
}
if ( ! F_121 ( & V_16 -> V_140 ) )
V_10 = & V_16 -> V_140 ;
V_76 . V_77 = V_13 ;
V_76 . V_11 = V_16 -> V_11 ;
V_76 . V_10 = V_10 ? * V_10 : V_16 -> V_10 ;
V_76 . V_81 = V_2 -> V_123 ;
V_76 . V_83 = V_182 -> V_211 ;
V_76 . V_85 = V_185 -> V_216 ;
F_93 ( V_2 , F_48 ( & V_76 ) ) ;
V_73 = F_49 ( & V_76 , V_16 -> V_24 , & V_74 ) ;
V_49 = F_50 ( V_2 , & V_76 , V_73 , true ) ;
if ( F_51 ( V_49 ) ) {
V_33 = F_52 ( V_49 ) ;
goto V_215;
}
if ( V_10 == NULL ) {
V_10 = & V_76 . V_10 ;
V_16 -> V_140 = * V_10 ;
}
V_16 -> V_10 = * V_10 ;
V_185 -> V_160 = V_159 ;
F_95 ( V_2 , V_49 , NULL , NULL ) ;
V_184 -> V_156 = 0 ;
if ( V_16 -> V_24 != NULL )
V_184 -> V_156 = ( V_16 -> V_24 -> V_158 +
V_16 -> V_24 -> V_157 ) ;
V_185 -> V_217 = V_182 -> V_211 ;
F_125 ( V_2 , V_62 ) ;
V_33 = F_126 ( & V_218 , V_2 ) ;
if ( V_33 )
goto V_219;
V_32 -> V_220 = F_13 ( V_16 -> V_10 . V_20 ,
V_16 -> V_11 . V_20 ,
V_185 -> V_216 ,
V_185 -> V_217 ) ;
V_33 = F_127 ( V_2 ) ;
if ( V_33 )
goto V_219;
return 0 ;
V_219:
F_125 ( V_2 , V_4 ) ;
F_128 ( V_2 ) ;
V_215:
V_185 -> V_217 = 0 ;
V_2 -> V_149 = 0 ;
return V_33 ;
}
static int F_129 ( struct V_1 * V_2 )
{
static T_6 V_221 ;
int V_33 = F_130 ( V_2 , V_221 ) ;
if ( V_33 == 0 ) {
if ( F_131 ( ! V_221 ) )
V_221 = 1 ;
F_2 ( V_2 ) -> V_5 = & V_214 ;
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
if ( V_38 . V_222 == NULL )
return - V_223 ;
return F_136 ( & V_35 -> V_94 . V_95 , V_224 ,
V_225 , V_13 , V_35 ) ;
}
static void T_8 F_137 ( struct V_35 * V_35 )
{
F_138 ( V_35 -> V_94 . V_95 ) ;
}
static int T_9 F_139 ( void )
{
int V_33 = F_140 ( & V_226 , 1 ) ;
if ( V_33 != 0 )
goto V_41;
V_33 = F_141 ( & V_227 , V_13 ) ;
if ( V_33 != 0 )
goto V_228;
F_142 ( & V_229 ) ;
V_33 = F_143 ( & V_230 ) ;
if ( V_33 != 0 )
goto V_231;
V_41:
return V_33 ;
V_231:
F_144 ( & V_227 , V_13 ) ;
F_145 ( & V_229 ) ;
V_228:
F_146 ( & V_226 ) ;
goto V_41;
}
static void T_10 F_147 ( void )
{
F_148 ( & V_230 ) ;
F_144 ( & V_227 , V_13 ) ;
F_145 ( & V_229 ) ;
F_146 ( & V_226 ) ;
}
