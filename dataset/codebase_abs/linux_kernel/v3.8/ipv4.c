int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
const struct V_6 * V_7 = (struct V_6 * ) V_4 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_2 ) ;
T_1 V_12 , V_13 ;
T_2 V_14 , V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_20 ;
struct V_21 * V_22 ;
V_11 -> V_23 = V_24 ;
if ( V_5 < sizeof( struct V_6 ) )
return - V_25 ;
if ( V_7 -> V_26 != V_27 )
return - V_28 ;
V_15 = V_14 = V_7 -> V_29 . V_30 ;
V_22 = F_4 ( V_9 -> V_22 ,
F_5 ( V_2 ) ) ;
if ( V_22 != NULL && V_22 -> V_31 . V_32 ) {
if ( V_14 == 0 )
return - V_25 ;
V_15 = V_22 -> V_31 . V_33 ;
}
V_12 = V_9 -> V_34 ;
V_13 = V_7 -> V_35 ;
V_17 = & V_9 -> V_36 . V_37 . V_38 . V_39 ;
V_19 = F_6 ( V_17 , V_15 , V_9 -> V_40 ,
F_7 ( V_2 ) , V_2 -> V_41 ,
V_42 ,
V_12 , V_13 , V_2 , true ) ;
if ( F_8 ( V_19 ) )
return F_9 ( V_19 ) ;
if ( V_19 -> V_43 & ( V_44 | V_45 ) ) {
F_10 ( V_19 ) ;
return - V_46 ;
}
if ( V_22 == NULL || ! V_22 -> V_31 . V_32 )
V_14 = V_17 -> V_14 ;
if ( V_9 -> V_40 == 0 )
V_9 -> V_40 = V_17 -> V_47 ;
V_9 -> V_48 = V_9 -> V_40 ;
V_9 -> V_49 = V_7 -> V_35 ;
V_9 -> V_50 = V_14 ;
F_11 ( V_2 ) -> V_51 = 0 ;
if ( V_22 )
F_11 ( V_2 ) -> V_51 = V_22 -> V_31 . V_52 ;
F_12 ( V_2 , V_53 ) ;
V_20 = F_13 ( & V_54 , V_2 ) ;
if ( V_20 != 0 )
goto V_55;
V_19 = F_14 ( V_17 , V_19 , V_12 , V_13 ,
V_9 -> V_34 , V_9 -> V_49 , V_2 ) ;
if ( F_8 ( V_19 ) ) {
V_20 = F_9 ( V_19 ) ;
V_19 = NULL ;
goto V_55;
}
F_15 ( V_2 , & V_19 -> V_56 ) ;
V_11 -> V_57 = F_16 ( V_9 -> V_40 ,
V_9 -> V_50 ,
V_9 -> V_34 ,
V_9 -> V_49 ) ;
V_9 -> V_58 = V_11 -> V_57 ^ V_59 ;
V_20 = F_17 ( V_2 ) ;
V_19 = NULL ;
if ( V_20 != 0 )
goto V_55;
V_60:
return V_20 ;
V_55:
F_12 ( V_2 , V_61 ) ;
F_10 ( V_19 ) ;
V_2 -> V_62 = 0 ;
V_9 -> V_49 = 0 ;
goto V_60;
}
static inline void F_18 ( struct V_1 * V_2 ,
const struct V_63 * V_64 ,
T_3 V_65 )
{
struct V_66 * V_56 ;
const struct V_8 * V_9 = F_2 ( V_2 ) ;
const struct V_10 * V_11 = F_3 ( V_2 ) ;
if ( V_2 -> V_67 == V_68 )
return;
V_56 = F_19 ( V_2 , V_65 ) ;
if ( ! V_56 )
return;
if ( V_65 < F_20 ( V_56 ) && F_21 ( V_2 , V_56 ) )
V_2 -> V_69 = V_70 ;
V_65 = F_20 ( V_56 ) ;
if ( V_9 -> V_71 != V_72 &&
F_11 ( V_2 ) -> V_73 > V_65 ) {
F_22 ( V_2 , V_65 ) ;
F_23 ( V_2 , V_11 -> V_74 , V_75 ) ;
}
}
static void F_24 ( struct V_76 * V_77 , struct V_1 * V_2 )
{
struct V_66 * V_56 = F_25 ( V_2 , 0 ) ;
if ( V_56 )
V_56 -> V_78 -> V_79 ( V_56 , V_2 , V_77 ) ;
}
static void F_26 ( struct V_76 * V_77 , T_3 V_80 )
{
const struct V_63 * V_64 = (struct V_63 * ) V_77 -> V_81 ;
const T_4 V_82 = V_64 -> V_83 << 2 ;
const struct V_84 * V_85 = (struct V_84 * ) ( V_77 -> V_81 + V_82 ) ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
const int type = F_27 ( V_77 ) -> type ;
const int V_86 = F_27 ( V_77 ) -> V_86 ;
struct V_1 * V_2 ;
T_5 V_87 ;
int V_20 ;
struct V_88 * V_88 = F_28 ( V_77 -> V_89 ) ;
if ( V_77 -> V_90 < V_82 + sizeof( * V_85 ) ||
V_77 -> V_90 < V_82 + F_29 ( V_85 ) ) {
F_30 ( V_88 , V_91 ) ;
return;
}
V_2 = F_31 ( V_88 , & V_92 ,
V_64 -> V_14 , V_85 -> V_93 ,
V_64 -> V_47 , V_85 -> V_94 , F_32 ( V_77 ) ) ;
if ( V_2 == NULL ) {
F_30 ( V_88 , V_91 ) ;
return;
}
if ( V_2 -> V_67 == V_95 ) {
F_33 ( F_34 ( V_2 ) ) ;
return;
}
F_35 ( V_2 ) ;
if ( F_5 ( V_2 ) )
F_36 ( V_88 , V_96 ) ;
if ( V_2 -> V_67 == V_61 )
goto V_60;
V_11 = F_3 ( V_2 ) ;
V_87 = F_37 ( V_85 ) ;
if ( ( 1 << V_2 -> V_67 ) & ~ ( V_97 | V_98 ) &&
! F_38 ( V_87 , V_11 -> V_99 , V_11 -> V_100 ) ) {
F_36 ( V_88 , V_101 ) ;
goto V_60;
}
switch ( type ) {
case V_102 :
F_24 ( V_77 , V_2 ) ;
goto V_60;
case V_103 :
goto V_60;
case V_104 :
V_20 = V_105 ;
break;
case V_106 :
if ( V_86 > V_107 )
goto V_60;
if ( V_86 == V_108 ) {
if ( ! F_5 ( V_2 ) )
F_18 ( V_2 , V_64 , V_80 ) ;
goto V_60;
}
V_20 = V_109 [ V_86 ] . V_110 ;
break;
case V_111 :
V_20 = V_112 ;
break;
default:
goto V_60;
}
switch ( V_2 -> V_67 ) {
struct V_113 * V_114 , * * V_115 ;
case V_68 :
if ( F_5 ( V_2 ) )
goto V_60;
V_114 = F_39 ( V_2 , & V_115 , V_85 -> V_93 ,
V_64 -> V_14 , V_64 -> V_47 ) ;
if ( ! V_114 )
goto V_60;
F_40 ( V_114 -> V_2 ) ;
if ( ! F_38 ( V_87 , F_41 ( V_114 ) -> V_116 ,
F_41 ( V_114 ) -> V_117 ) ) {
F_36 ( V_88 , V_101 ) ;
goto V_60;
}
F_42 ( V_2 , V_114 , V_115 ) ;
goto V_60;
case V_53 :
case V_118 :
if ( ! F_5 ( V_2 ) ) {
F_43 ( V_119 ) ;
V_2 -> V_120 = V_20 ;
V_2 -> V_121 ( V_2 ) ;
F_44 ( V_2 ) ;
} else
V_2 -> V_69 = V_20 ;
goto V_60;
}
V_9 = F_2 ( V_2 ) ;
if ( ! F_5 ( V_2 ) && V_9 -> V_122 ) {
V_2 -> V_120 = V_20 ;
V_2 -> V_121 ( V_2 ) ;
} else
V_2 -> V_69 = V_20 ;
V_60:
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
}
static inline T_6 F_47 ( struct V_76 * V_77 ,
T_2 V_123 , T_2 V_56 )
{
return F_48 ( V_123 , V_56 , V_77 -> V_90 , V_42 , V_77 -> V_124 ) ;
}
void F_49 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_84 * V_85 = V_84 ( V_77 ) ;
F_50 ( V_77 ) ;
V_85 -> V_125 = F_47 ( V_77 ,
V_9 -> V_40 ,
V_9 -> V_50 ) ;
}
static inline T_7 F_51 ( const struct V_76 * V_77 )
{
return F_16 ( F_52 ( V_77 ) -> V_14 ,
F_52 ( V_77 ) -> V_47 ,
V_84 ( V_77 ) -> V_93 ,
V_84 ( V_77 ) -> V_94 ) ;
}
struct V_1 * F_53 ( struct V_1 * V_2 , struct V_76 * V_77 ,
struct V_113 * V_114 ,
struct V_66 * V_56 )
{
struct V_126 * V_127 ;
struct V_8 * V_128 ;
struct V_1 * V_129 ;
if ( F_54 ( V_2 ) )
goto V_130;
V_129 = F_55 ( V_2 , V_114 , V_77 ) ;
if ( V_129 == NULL )
goto V_131;
V_128 = F_2 ( V_129 ) ;
V_127 = F_56 ( V_114 ) ;
V_128 -> V_50 = V_127 -> V_132 ;
V_128 -> V_48 = V_127 -> V_133 ;
V_128 -> V_40 = V_127 -> V_133 ;
V_128 -> V_22 = V_127 -> V_31 ;
V_127 -> V_31 = NULL ;
V_128 -> V_134 = F_32 ( V_77 ) ;
V_128 -> V_135 = F_52 ( V_77 ) -> V_136 ;
V_128 -> V_58 = V_59 ;
if ( V_56 == NULL && ( V_56 = F_57 ( V_2 , V_129 , V_114 ) ) == NULL )
goto V_137;
F_15 ( V_129 , V_56 ) ;
F_22 ( V_129 , F_20 ( V_56 ) ) ;
if ( F_58 ( V_2 , V_129 ) < 0 )
goto V_137;
F_59 ( V_129 , NULL ) ;
return V_129 ;
V_130:
F_36 ( F_60 ( V_2 ) , V_138 ) ;
V_131:
F_61 ( V_56 ) ;
exit:
F_36 ( F_60 ( V_2 ) , V_139 ) ;
return NULL ;
V_137:
F_62 ( V_129 ) ;
F_44 ( V_129 ) ;
goto exit;
}
static struct V_1 * F_63 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
const struct V_84 * V_85 = V_84 ( V_77 ) ;
const struct V_63 * V_64 = F_52 ( V_77 ) ;
struct V_1 * V_140 ;
struct V_113 * * V_115 ;
struct V_113 * V_114 = F_39 ( V_2 , & V_115 ,
V_85 -> V_94 ,
V_64 -> V_47 , V_64 -> V_14 ) ;
if ( V_114 != NULL )
return F_64 ( V_2 , V_77 , V_114 , V_115 ) ;
V_140 = F_65 ( F_60 ( V_2 ) , & V_92 ,
V_64 -> V_47 , V_85 -> V_94 ,
V_64 -> V_14 , V_85 -> V_93 ,
F_32 ( V_77 ) ) ;
if ( V_140 != NULL ) {
if ( V_140 -> V_67 != V_95 ) {
F_35 ( V_140 ) ;
return V_140 ;
}
F_33 ( F_34 ( V_140 ) ) ;
return NULL ;
}
return V_2 ;
}
static struct V_66 * F_66 ( struct V_88 * V_88 , struct V_1 * V_2 ,
struct V_76 * V_77 )
{
struct V_18 * V_19 ;
const struct V_63 * V_64 = F_52 ( V_77 ) ;
struct V_16 V_17 = {
. V_141 = F_32 ( V_77 ) ,
. V_14 = V_64 -> V_47 ,
. V_47 = V_64 -> V_14 ,
. V_142 = F_7 ( V_2 ) ,
. V_143 = V_2 -> V_144 ,
. V_145 = V_84 ( V_77 ) -> V_93 ,
. V_146 = V_84 ( V_77 ) -> V_94 ,
} ;
F_67 ( V_77 , F_68 ( & V_17 ) ) ;
V_19 = F_69 ( V_88 , & V_17 , V_2 ) ;
if ( F_8 ( V_19 ) ) {
F_70 ( V_88 , V_147 ) ;
return NULL ;
}
return & V_19 -> V_56 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_113 * V_114 ,
struct V_148 * V_149 )
{
int V_20 = - 1 ;
struct V_76 * V_77 ;
struct V_66 * V_56 ;
struct V_16 V_17 ;
V_56 = F_72 ( V_2 , & V_17 , V_114 ) ;
if ( V_56 == NULL )
goto V_60;
V_77 = F_73 ( V_2 , V_56 , V_114 ) ;
if ( V_77 != NULL ) {
const struct V_126 * V_127 = F_56 ( V_114 ) ;
struct V_84 * V_85 = V_84 ( V_77 ) ;
V_85 -> V_125 = F_47 ( V_77 , V_127 -> V_133 ,
V_127 -> V_132 ) ;
V_20 = F_74 ( V_77 , V_2 , V_127 -> V_133 ,
V_127 -> V_132 ,
V_127 -> V_31 ) ;
V_20 = F_75 ( V_20 ) ;
}
V_60:
F_61 ( V_56 ) ;
return V_20 ;
}
static void F_76 ( struct V_1 * V_2 , struct V_76 * V_150 )
{
int V_20 ;
const struct V_63 * V_151 ;
struct V_76 * V_77 ;
struct V_66 * V_56 ;
struct V_88 * V_88 = F_28 ( F_77 ( V_150 ) -> V_89 ) ;
struct V_1 * V_152 = V_88 -> V_153 . V_154 ;
if ( V_84 ( V_150 ) -> V_155 == V_156 )
return;
if ( F_78 ( V_150 ) -> V_157 != V_158 )
return;
V_56 = F_66 ( V_88 , V_152 , V_150 ) ;
if ( V_56 == NULL )
return;
V_77 = F_79 ( V_152 , V_150 ) ;
if ( V_77 == NULL )
goto V_60;
V_151 = F_52 ( V_150 ) ;
V_84 ( V_77 ) -> V_125 = F_47 ( V_77 , V_151 -> V_47 ,
V_151 -> V_14 ) ;
F_80 ( V_77 , F_81 ( V_56 ) ) ;
F_35 ( V_152 ) ;
V_20 = F_74 ( V_77 , V_152 ,
V_151 -> V_14 , V_151 -> V_47 , NULL ) ;
F_45 ( V_152 ) ;
if ( F_75 ( V_20 ) == 0 ) {
F_43 ( V_159 ) ;
F_43 ( V_160 ) ;
}
V_60:
F_61 ( V_56 ) ;
}
static void F_82 ( struct V_113 * V_114 )
{
F_83 ( & F_41 ( V_114 ) -> V_161 ) ;
F_84 ( F_56 ( V_114 ) -> V_31 ) ;
}
void F_85 ( struct V_1 * V_2 , struct V_113 * V_114 )
{
}
int F_86 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
struct V_126 * V_127 ;
struct V_113 * V_114 ;
struct V_162 * V_163 ;
const T_2 V_164 = F_87 ( V_77 ) -> V_165 ;
struct V_166 * V_167 = F_88 ( V_77 ) ;
if ( F_78 ( V_77 ) -> V_43 & ( V_45 | V_44 ) )
return 0 ;
if ( F_89 ( V_2 , V_164 ) ) {
V_167 -> V_168 = V_169 ;
goto V_170;
}
V_167 -> V_168 = V_171 ;
if ( F_90 ( V_2 ) )
goto V_170;
if ( F_54 ( V_2 ) && F_91 ( V_2 ) > 1 )
goto V_170;
V_114 = F_92 ( & V_172 ) ;
if ( V_114 == NULL )
goto V_170;
if ( F_93 ( V_114 , F_3 ( V_2 ) , V_77 ) )
goto V_173;
V_163 = F_41 ( V_114 ) ;
if ( F_94 ( V_2 , V_163 , V_77 ) )
goto V_173;
if ( F_95 ( V_2 , V_77 , V_114 ) )
goto V_173;
V_127 = F_56 ( V_114 ) ;
V_127 -> V_133 = F_52 ( V_77 ) -> V_14 ;
V_127 -> V_132 = F_52 ( V_77 ) -> V_47 ;
V_163 -> V_174 = V_167 -> V_175 ;
V_163 -> V_176 = V_163 -> V_174 ;
V_163 -> V_116 = F_51 ( V_77 ) ;
V_163 -> V_117 = V_163 -> V_116 ;
V_163 -> V_177 = V_164 ;
if ( F_71 ( V_2 , V_114 , NULL ) )
goto V_173;
F_96 ( V_2 , V_114 , V_178 ) ;
return 0 ;
V_173:
F_97 ( V_114 ) ;
V_170:
F_43 ( V_119 ) ;
return - 1 ;
}
int F_98 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
struct V_84 * V_85 = V_84 ( V_77 ) ;
if ( V_2 -> V_67 == V_179 ) {
if ( F_99 ( V_2 , V_77 , V_85 , V_77 -> V_90 ) )
goto V_180;
return 0 ;
}
if ( V_2 -> V_67 == V_68 ) {
struct V_1 * V_140 = F_63 ( V_2 , V_77 ) ;
if ( V_140 == NULL )
goto V_181;
if ( V_140 != V_2 ) {
if ( F_100 ( V_2 , V_140 , V_77 ) )
goto V_180;
return 0 ;
}
}
if ( F_101 ( V_2 , V_77 , V_85 , V_77 -> V_90 ) )
goto V_180;
return 0 ;
V_180:
F_76 ( V_2 , V_77 ) ;
V_181:
F_102 ( V_77 ) ;
return 0 ;
}
int F_103 ( struct V_76 * V_77 )
{
const struct V_84 * V_85 ;
unsigned int V_182 ;
if ( V_77 -> V_183 != V_184 )
return 1 ;
if ( ! F_104 ( V_77 , sizeof( struct V_84 ) ) ) {
F_105 ( L_1 ) ;
return 1 ;
}
V_85 = V_84 ( V_77 ) ;
if ( V_85 -> V_155 >= V_185 ) {
F_105 ( L_2 ) ;
return 1 ;
}
if ( V_85 -> V_186 < F_106 ( V_77 ) / sizeof( T_3 ) ) {
F_105 ( L_3 , V_85 -> V_186 ) ;
return 1 ;
}
if ( ! F_104 ( V_77 , V_85 -> V_186 * sizeof( T_3 ) ) ) {
F_105 ( L_4 , V_85 -> V_186 ) ;
return 1 ;
}
if ( ( V_85 -> V_155 < V_187 ||
V_85 -> V_155 > V_188 ) && V_85 -> V_189 == 0 ) {
F_105 ( L_5 ,
F_107 ( V_85 -> V_155 ) ) ;
return 1 ;
}
V_182 = F_108 ( V_77 ) ;
if ( V_182 > V_77 -> V_90 ) {
F_105 ( L_6 ,
V_85 -> V_190 , V_77 -> V_90 ) ;
return 1 ;
}
V_77 -> V_124 = F_109 ( V_77 , 0 , V_182 , 0 ) ;
return 0 ;
}
static int F_110 ( struct V_76 * V_77 )
{
const struct V_84 * V_85 ;
const struct V_63 * V_64 ;
struct V_1 * V_2 ;
int V_191 ;
if ( F_103 ( V_77 ) )
goto V_192;
V_64 = F_52 ( V_77 ) ;
if ( F_47 ( V_77 , V_64 -> V_47 , V_64 -> V_14 ) ) {
F_105 ( L_7 ) ;
goto V_192;
}
V_85 = V_84 ( V_77 ) ;
F_88 ( V_77 ) -> V_175 = F_37 ( V_85 ) ;
F_88 ( V_77 ) -> V_193 = V_85 -> V_155 ;
F_111 ( L_8 ,
F_107 ( V_85 -> V_155 ) ,
& V_64 -> V_47 , F_112 ( V_85 -> V_94 ) ,
& V_64 -> V_14 , F_112 ( V_85 -> V_93 ) ,
( unsigned long long ) F_88 ( V_77 ) -> V_175 ) ;
if ( F_113 ( V_77 ) ) {
F_88 ( V_77 ) -> V_194 = V_195 ;
F_114 ( L_9 ) ;
} else {
F_88 ( V_77 ) -> V_194 = F_115 ( V_77 ) ;
F_114 ( L_10 , ( unsigned long long )
F_88 ( V_77 ) -> V_194 ) ;
}
V_2 = F_116 ( & V_92 , V_77 ,
V_85 -> V_94 , V_85 -> V_93 ) ;
if ( V_2 == NULL ) {
F_111 ( L_11
L_12 ) ;
goto V_196;
}
if ( V_2 -> V_67 == V_95 ) {
F_111 ( L_13 ) ;
F_33 ( F_34 ( V_2 ) ) ;
goto V_196;
}
V_191 = F_3 ( V_2 ) -> V_197 ;
if ( V_85 -> V_190 && ( V_191 == 0 || V_85 -> V_190 < V_191 ) ) {
F_111 ( L_14 ,
V_85 -> V_190 , V_191 ) ;
goto V_198;
}
if ( ! F_117 ( V_2 , V_199 , V_77 ) )
goto V_198;
F_118 ( V_77 ) ;
return F_119 ( V_2 , V_77 , 1 ) ;
V_196:
if ( ! F_117 ( NULL , V_199 , V_77 ) )
goto V_192;
if ( V_85 -> V_155 != V_156 ) {
F_88 ( V_77 ) -> V_168 =
V_200 ;
F_76 ( V_2 , V_77 ) ;
}
V_192:
F_102 ( V_77 ) ;
return 0 ;
V_198:
F_46 ( V_2 ) ;
goto V_192;
}
static int F_120 ( struct V_1 * V_2 )
{
static T_8 V_201 ;
int V_20 = F_121 ( V_2 , V_201 ) ;
if ( V_20 == 0 ) {
if ( F_122 ( ! V_201 ) )
V_201 = 1 ;
F_11 ( V_2 ) -> V_202 = & V_203 ;
}
return V_20 ;
}
static int T_9 F_123 ( struct V_88 * V_88 )
{
if ( V_92 . V_204 == NULL )
return - V_205 ;
return F_124 ( & V_88 -> V_153 . V_154 , V_206 ,
V_207 , V_42 , V_88 ) ;
}
static void T_10 F_125 ( struct V_88 * V_88 )
{
F_126 ( V_88 -> V_153 . V_154 ) ;
}
static int T_11 F_127 ( void )
{
int V_20 = F_128 ( & V_208 , 1 ) ;
if ( V_20 != 0 )
goto V_60;
V_20 = F_129 ( & V_209 , V_42 ) ;
if ( V_20 != 0 )
goto V_210;
F_130 ( & V_211 ) ;
V_20 = F_131 ( & V_212 ) ;
if ( V_20 )
goto V_213;
V_60:
return V_20 ;
V_213:
F_132 ( & V_211 ) ;
F_133 ( & V_209 , V_42 ) ;
V_210:
F_134 ( & V_208 ) ;
goto V_60;
}
static void T_12 F_135 ( void )
{
F_136 ( & V_212 ) ;
F_132 ( & V_211 ) ;
F_133 ( & V_209 , V_42 ) ;
F_134 ( & V_208 ) ;
}
