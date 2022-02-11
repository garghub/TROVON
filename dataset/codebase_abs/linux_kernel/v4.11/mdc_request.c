static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_6 -> V_7 . V_4 ;
int V_8 ;
V_8 = F_2 ( V_4 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_3 ( V_2 ) ;
F_4 ( V_4 ) ;
return V_8 ;
}
static int F_5 ( struct V_9 * exp , struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_8 ;
V_2 = F_6 ( F_7 ( exp ) ,
& V_14 ,
V_15 , V_16 ) ;
if ( ! V_2 )
return - V_17 ;
F_8 ( V_2 , NULL , 0 , 0 , - 1 , 0 ) ;
V_2 -> V_18 = V_19 ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
goto V_20;
V_13 = F_10 ( & V_2 -> V_21 , & V_22 ) ;
if ( ! V_13 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_11 = V_13 -> V_24 ;
F_11 ( V_25 ,
L_1 V_26 L_2 ,
F_12 ( V_11 ) ,
F_13 ( V_2 -> V_27 ) ) ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_15 ( struct V_9 * exp ,
struct V_1 * V_2 )
{
struct V_28 * V_29 = & V_2 -> V_21 ;
struct V_12 * V_13 ;
void * V_30 ;
int V_8 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 != 0 )
return V_8 ;
V_13 = F_10 ( V_29 , & V_22 ) ;
if ( ! V_13 )
return - V_23 ;
F_11 ( V_25 , L_3 , V_13 -> V_31 ) ;
F_16 ( exp , V_13 ) ;
if ( V_13 -> V_32 != 0 ) {
V_30 = F_17 ( V_29 , & V_33 ,
V_13 -> V_32 ) ;
if ( ! V_30 )
return - V_23 ;
}
return 0 ;
}
static int F_18 ( struct V_9 * exp , struct V_34 * V_35 ,
struct V_1 * * V_36 )
{
struct V_1 * V_2 ;
int V_8 ;
if ( V_35 -> V_37 & V_38 ) {
V_35 -> V_39 = 0 ;
return 0 ;
}
* V_36 = NULL ;
V_2 = F_19 ( F_7 ( exp ) , & V_40 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_41 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_35 -> V_42 , V_35 -> V_43 ,
V_35 -> V_44 , - 1 , 0 ) ;
F_22 ( & V_2 -> V_21 , & V_33 , V_45 ,
V_35 -> V_44 ) ;
F_9 ( V_2 ) ;
V_8 = F_15 ( exp , V_2 ) ;
if ( V_8 )
F_14 ( V_2 ) ;
else
* V_36 = V_2 ;
return V_8 ;
}
static int F_23 ( struct V_9 * exp , struct V_34 * V_35 ,
struct V_1 * * V_36 )
{
struct V_1 * V_2 ;
int V_8 ;
* V_36 = NULL ;
V_2 = F_19 ( F_7 ( exp ) ,
& V_46 ) ;
if ( ! V_2 )
return - V_17 ;
F_22 ( & V_2 -> V_21 , & V_47 , V_48 ,
V_35 -> V_49 + 1 ) ;
V_8 = F_20 ( V_2 , V_15 , V_50 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_35 -> V_42 , V_35 -> V_43 ,
V_35 -> V_44 , V_35 -> V_51 [ 0 ] , 0 ) ;
if ( V_35 -> V_52 ) {
char * V_53 = F_24 ( & V_2 -> V_21 , & V_47 ) ;
F_25 ( F_26 ( V_35 -> V_52 , V_35 -> V_49 ) ==
V_35 -> V_49 ) ;
memcpy ( V_53 , V_35 -> V_52 , V_35 -> V_49 ) ;
}
F_22 ( & V_2 -> V_21 , & V_33 , V_45 ,
V_35 -> V_44 ) ;
F_9 ( V_2 ) ;
V_8 = F_15 ( exp , V_2 ) ;
if ( V_8 )
F_14 ( V_2 ) ;
else
* V_36 = V_2 ;
return V_8 ;
}
static int F_27 ( struct V_9 * exp ,
const struct V_54 * V_55 ,
const struct V_10 * V_56 ,
int V_57 , T_1 V_58 ,
const char * V_59 , const char * V_60 ,
int V_61 , int V_62 , int V_63 ,
T_2 V_64 , struct V_1 * * V_36 )
{
struct V_1 * V_2 ;
int V_65 = 0 ;
char * V_66 ;
int V_8 ;
* V_36 = NULL ;
V_2 = F_19 ( F_7 ( exp ) , V_55 ) ;
if ( ! V_2 )
return - V_17 ;
if ( V_59 ) {
V_65 = strlen ( V_59 ) + 1 ;
F_22 ( & V_2 -> V_21 , & V_47 , V_48 ,
V_65 ) ;
}
if ( V_61 ) {
F_25 ( V_60 ) ;
F_22 ( & V_2 -> V_21 , & V_67 , V_48 ,
V_61 ) ;
}
if ( V_57 == V_68 && F_28 ( V_56 ) &&
exp -> V_69 . V_70 & V_71 ) {
F_29 ( V_72 ) ;
int V_73 ;
if ( V_61 == 0 )
F_22 ( & V_2 -> V_21 , & V_67 ,
V_48 , 0 ) ;
V_73 = F_30 ( exp , V_56 ,
& V_72 , V_74 ,
V_71 ) ;
V_8 = F_31 ( exp , V_2 , V_68 , & V_72 , V_73 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
} else {
V_8 = F_20 ( V_2 , V_15 , V_57 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
}
if ( V_57 == V_68 ) {
struct V_75 * V_76 ;
F_32 ( sizeof( struct V_75 ) !=
sizeof( struct V_77 ) ) ;
V_76 = F_24 ( & V_2 -> V_21 , & V_78 ) ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = F_33 ( & V_82 , F_34 () ) ;
V_76 -> V_83 = F_35 ( & V_82 , F_36 () ) ;
V_76 -> V_84 = F_37 () ;
V_76 -> V_85 = V_64 ;
V_76 -> V_86 = - 1 ;
V_76 -> V_87 = * V_56 ;
V_76 -> V_88 = V_58 | V_89 ;
V_76 -> V_90 = F_38 () ;
V_76 -> V_91 = V_62 ;
V_76 -> V_92 = V_63 ;
} else {
F_8 ( V_2 , V_56 , V_58 , V_62 , V_64 , V_63 ) ;
}
if ( V_59 ) {
V_66 = F_24 ( & V_2 -> V_21 , & V_47 ) ;
memcpy ( V_66 , V_59 , V_65 ) ;
}
if ( V_61 ) {
V_66 = F_24 ( & V_2 -> V_21 , & V_67 ) ;
memcpy ( V_66 , V_60 , V_61 ) ;
}
if ( F_39 ( & V_2 -> V_21 , & V_67 , V_45 ) )
F_22 ( & V_2 -> V_21 , & V_67 ,
V_45 , V_62 ) ;
F_9 ( V_2 ) ;
if ( V_57 == V_68 )
F_40 ( V_2 , NULL ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_57 == V_68 )
F_41 ( V_2 , NULL ) ;
if ( V_8 )
F_14 ( V_2 ) ;
else
* V_36 = V_2 ;
return V_8 ;
}
static int F_42 ( struct V_9 * exp , const struct V_10 * V_56 ,
T_1 V_58 , const char * V_59 ,
const char * V_60 , int V_61 , int V_62 ,
int V_63 , T_2 V_64 ,
struct V_1 * * V_36 )
{
return F_27 ( exp , & V_93 ,
V_56 , V_68 , V_58 , V_59 ,
V_60 , V_61 , V_62 , V_63 ,
V_64 , V_36 ) ;
}
static int F_43 ( struct V_9 * exp , const struct V_10 * V_56 ,
T_1 V_58 , const char * V_59 ,
const char * V_60 , int V_61 , int V_62 ,
int V_63 , struct V_1 * * V_36 )
{
return F_27 ( exp , & V_94 ,
V_56 , V_95 , V_58 , V_59 ,
V_60 , V_61 , V_62 , V_63 ,
- 1 , V_36 ) ;
}
static int F_44 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
struct V_28 * V_29 = & V_2 -> V_21 ;
struct V_12 * V_13 = V_97 -> V_13 ;
struct V_98 * V_99 ;
void * V_100 ;
int V_8 ;
if ( ! V_13 -> V_101 )
return 0 ;
V_100 = F_17 ( V_29 , & V_102 , V_13 -> V_101 ) ;
if ( ! V_100 )
return - V_23 ;
V_99 = F_45 ( & V_82 , V_100 , V_13 -> V_101 ) ;
if ( ! V_99 )
return 0 ;
if ( F_46 ( V_99 ) ) {
V_8 = F_47 ( V_99 ) ;
F_48 ( L_4 , V_8 ) ;
return V_8 ;
}
V_8 = F_49 ( & V_82 , V_99 ) ;
if ( V_8 ) {
F_48 ( L_5 , V_8 ) ;
F_50 ( V_99 ) ;
return V_8 ;
}
V_97 -> V_98 = V_99 ;
return 0 ;
}
static int F_51 ( struct V_9 * exp ,
struct V_1 * V_2 ,
struct V_9 * V_103 ,
struct V_9 * V_104 ,
struct V_96 * V_97 )
{
struct V_28 * V_29 = & V_2 -> V_21 ;
int V_8 ;
F_25 ( V_97 ) ;
memset ( V_97 , 0 , sizeof( * V_97 ) ) ;
V_97 -> V_13 = F_10 ( V_29 , & V_22 ) ;
if ( V_97 -> V_13 -> V_105 & V_106 ) {
if ( ! F_52 ( V_97 -> V_13 -> V_31 ) ) {
F_11 ( V_107 ,
L_6 ) ;
V_8 = - V_23 ;
goto V_20;
}
if ( V_97 -> V_13 -> V_32 == 0 ) {
F_11 ( V_107 ,
L_7 ) ;
V_8 = - V_23 ;
goto V_20;
}
V_97 -> V_108 . V_109 = V_97 -> V_13 -> V_32 ;
V_97 -> V_108 . V_110 = F_17 ( V_29 ,
& V_33 ,
V_97 -> V_108 . V_109 ) ;
if ( ! V_97 -> V_108 . V_110 ) {
V_8 = - V_23 ;
goto V_20;
}
} else if ( V_97 -> V_13 -> V_105 & V_111 ) {
const union V_112 * V_113 ;
T_3 V_114 ;
if ( ! F_53 ( V_97 -> V_13 -> V_31 ) ) {
F_11 ( V_107 ,
L_8 ) ;
V_8 = - V_23 ;
goto V_20;
}
V_114 = V_97 -> V_13 -> V_32 ;
if ( ! V_114 ) {
F_11 ( V_107 ,
L_9 ) ;
return - V_23 ;
}
if ( V_97 -> V_13 -> V_105 & V_115 ) {
V_113 = F_17 ( V_29 , & V_33 ,
V_114 ) ;
if ( ! V_113 ) {
V_8 = - V_23 ;
goto V_20;
}
V_8 = F_54 ( V_104 , & V_97 -> V_113 , V_113 , V_114 ) ;
if ( V_8 < 0 )
goto V_20;
if ( V_8 < ( F_55 ( V_8 ) ) sizeof( * V_97 -> V_113 ) ) {
F_11 ( V_107 ,
L_10 ,
V_8 , ( int ) sizeof( * V_97 -> V_113 ) ) ;
V_8 = - V_23 ;
goto V_20;
}
}
}
V_8 = 0 ;
if ( V_97 -> V_13 -> V_105 & V_116 ) {
if ( V_97 -> V_13 -> V_101 ) {
V_8 = F_44 ( V_2 , V_97 ) ;
if ( V_8 )
goto V_20;
#ifdef F_56
} else {
V_97 -> V_98 = NULL ;
#endif
}
}
V_20:
if ( V_8 ) {
#ifdef F_56
F_50 ( V_97 -> V_98 ) ;
#endif
}
return V_8 ;
}
static int F_57 ( struct V_9 * exp , struct V_96 * V_97 )
{
return 0 ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_117 * V_118 = V_2 -> V_119 ;
struct V_1 * V_120 ;
struct V_121 * V_122 ;
struct V_123 V_124 ;
struct V_12 * V_13 ;
if ( ! V_118 ) {
F_59 ( V_125 , V_2 ,
L_11 ) ;
return;
}
V_13 = F_10 ( & V_2 -> V_21 , & V_22 ) ;
V_122 = V_118 -> V_126 ;
if ( V_122 ) {
struct V_123 * V_127 ;
F_25 ( V_122 -> V_128 == V_129 ) ;
V_127 = & V_122 -> V_130 ;
F_11 ( V_131 , L_12 ,
V_127 -> V_132 , V_13 -> V_133 . V_132 ) ;
V_124 = * V_127 ;
* V_127 = V_13 -> V_133 ;
}
V_120 = V_118 -> V_134 ;
if ( V_120 ) {
T_2 V_135 = F_60 ( V_120 -> V_136 ) ;
struct V_137 * V_138 ;
F_25 ( V_135 == V_139 ) ;
V_138 = F_24 ( & V_120 -> V_21 ,
& V_140 ) ;
F_25 ( V_138 ) ;
if ( V_122 )
F_25 ( ! memcmp ( & V_124 , & V_138 -> V_141 , sizeof( V_124 ) ) ) ;
F_59 ( V_131 , V_120 , L_13 ) ;
V_138 -> V_141 = V_13 -> V_133 ;
}
}
void F_61 ( struct V_1 * V_2 )
{
struct V_117 * V_118 = V_2 -> V_119 ;
if ( ! V_118 )
return;
F_62 ( V_2 ) ;
F_63 ( & V_2 -> V_142 ) ;
V_2 -> V_143 = 1 ;
F_64 ( & V_2 -> V_142 ) ;
V_2 -> V_119 = NULL ;
F_65 ( V_118 ) ;
}
int F_66 ( struct V_9 * exp ,
struct V_121 * V_122 ,
struct V_144 * V_145 )
{
struct V_117 * V_118 ;
struct V_146 * V_76 ;
struct V_12 * V_13 ;
struct V_1 * V_147 = V_145 -> V_148 ;
struct V_149 * V_150 = V_147 -> V_5 ;
if ( ! V_147 -> V_151 )
return 0 ;
V_76 = F_24 ( & V_147 -> V_21 , & V_78 ) ;
V_13 = F_10 ( & V_147 -> V_21 , & V_22 ) ;
F_25 ( V_76 ) ;
F_25 ( V_13 ) ;
if ( V_122 && V_150 -> V_152 ) {
V_118 = F_67 () ;
if ( ! V_118 ) {
F_59 ( V_125 , V_147 ,
L_14 ) ;
return 0 ;
}
F_68 ( V_118 ) ;
F_68 ( V_118 ) ;
F_63 ( & V_147 -> V_142 ) ;
V_122 -> V_153 = V_118 ;
V_118 -> V_126 = V_122 ;
V_118 -> V_154 = F_69 ( V_145 , V_155 ) ||
F_69 ( V_145 , V_156 ) ;
V_118 -> V_157 = V_147 ;
V_147 -> V_119 = V_118 ;
V_147 -> V_158 = F_61 ;
F_64 ( & V_147 -> V_142 ) ;
}
V_76 -> V_159 = V_13 -> V_24 ;
V_76 -> V_160 = V_13 -> V_161 ;
V_76 -> V_162 . V_132 = V_13 -> V_133 . V_132 ;
V_147 -> V_163 = F_58 ;
if ( ! F_28 ( & V_13 -> V_24 ) ) {
F_59 ( V_125 , V_147 ,
L_15 ) ;
F_70 () ;
}
F_59 ( V_164 , V_147 , L_16 ) ;
return 0 ;
}
static void F_71 ( struct V_117 * V_118 )
{
int V_165 = 0 ;
if ( V_118 -> V_154 == 0 &&
F_72 ( V_118 -> V_157 -> V_5 ) )
V_165 = 1 ;
F_59 ( V_164 , V_118 -> V_157 ,
L_17 ,
V_118 -> V_157 -> V_151 ) ;
F_73 ( V_118 -> V_157 , V_165 ) ;
if ( V_118 -> V_134 )
F_73 ( V_118 -> V_134 , V_165 ) ;
}
static int F_74 ( struct V_9 * exp ,
struct V_121 * V_122 )
{
struct V_117 * V_118 = V_122 -> V_153 ;
if ( ! V_118 )
return 0 ;
F_25 ( V_118 != V_166 ) ;
F_25 ( V_118 -> V_157 ) ;
F_71 ( V_118 ) ;
V_118 -> V_126 = NULL ;
V_122 -> V_153 = NULL ;
F_65 ( V_118 ) ;
return 0 ;
}
static int F_75 ( struct V_9 * exp , struct V_34 * V_35 ,
struct V_117 * V_118 , struct V_1 * * V_36 )
{
struct V_167 * V_168 = F_76 ( exp ) ;
struct V_1 * V_2 ;
struct V_54 * V_169 ;
int V_8 ;
int V_170 = 0 ;
if ( V_35 -> V_171 & V_172 ) {
V_169 = & V_173 ;
V_8 = F_77 ( NULL , exp , & V_35 -> V_174 , V_35 ) ;
if ( V_8 < 0 ) {
F_48 ( L_18 V_26 L_19 ,
V_168 -> V_175 , F_12 ( & V_35 -> V_42 ) , V_8 ) ;
V_170 = V_8 ;
}
} else if ( V_35 -> V_171 & V_176 ) {
V_169 = & V_173 ;
} else {
V_169 = & V_177 ;
}
* V_36 = NULL ;
if ( F_78 ( V_178 ) )
V_2 = NULL ;
else
V_2 = F_19 ( F_7 ( exp ) , V_169 ) ;
if ( F_79 ( V_118 ) ) {
F_80 ( V_118 -> V_157 &&
V_118 -> V_157 -> V_179 != V_180 ,
L_20 , V_118 -> V_157 ) ;
V_118 -> V_134 = V_2 ;
F_59 ( V_131 , V_118 -> V_157 , L_21 ) ;
F_63 ( & V_118 -> V_157 -> V_142 ) ;
V_118 -> V_157 -> V_151 = 0 ;
F_64 ( & V_118 -> V_157 -> V_142 ) ;
} else {
F_11 ( V_131 ,
L_22 ) ;
}
if ( ! V_2 ) {
F_81 ( L_23 V_26 L_24 ,
V_168 -> V_175 , F_12 ( & V_35 -> V_42 ) ) ;
V_8 = - V_17 ;
goto V_20;
}
V_8 = F_20 ( V_2 , V_15 , V_139 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
V_2 = NULL ;
goto V_20;
}
V_2 -> V_181 = V_182 ;
F_82 ( V_2 ) ;
F_83 ( V_2 , V_35 ) ;
F_22 ( & V_2 -> V_21 , & V_33 , V_45 ,
V_168 -> V_7 . V_4 . V_183 ) ;
F_9 ( V_2 ) ;
F_40 ( V_2 , NULL ) ;
V_8 = F_3 ( V_2 ) ;
F_41 ( V_2 , NULL ) ;
if ( ! V_2 -> V_27 ) {
F_11 ( V_164 , L_25 , V_2 ,
V_2 -> V_184 ) ;
if ( V_8 == 0 )
V_8 = V_2 -> V_184 ? : - V_185 ;
} else if ( V_8 == 0 || V_8 == - V_186 ) {
struct V_12 * V_13 ;
V_8 = F_84 ( V_2 -> V_27 ) ;
if ( F_85 ( V_2 -> V_27 ) == V_187 ) {
F_59 ( V_125 , V_2 ,
L_26 , V_8 ) ;
if ( V_8 > 0 )
V_8 = - V_8 ;
}
V_13 = F_10 ( & V_2 -> V_21 , & V_22 ) ;
if ( ! V_13 )
V_8 = - V_23 ;
} else if ( V_8 == - V_188 ) {
if ( V_118 ) {
F_59 ( V_131 , V_2 , L_27 , V_8 ) ;
if ( V_118 -> V_157 -> V_143 )
V_8 = 0 ;
}
}
V_20:
if ( V_118 ) {
if ( V_8 != 0 )
V_118 -> V_134 = NULL ;
F_65 ( V_118 ) ;
}
* V_36 = V_2 ;
return V_8 < 0 ? V_8 : V_170 ;
}
static int F_86 ( struct V_9 * exp , const struct V_10 * V_56 ,
T_1 V_189 , struct V_190 * * V_191 , int V_192 ,
struct V_1 * * V_36 )
{
struct V_193 * V_194 ;
struct V_1 * V_2 ;
T_4 V_195 ;
struct V_196 V_197 ;
int V_198 = 0 ;
int V_8 ;
int V_199 ;
* V_36 = NULL ;
F_87 ( & V_195 ) ;
V_200:
V_2 = F_19 ( F_7 ( exp ) , & V_201 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_202 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
V_2 -> V_181 = V_182 ;
F_82 ( V_2 ) ;
V_194 = F_88 ( V_2 , V_192 , 1 ,
V_203 | V_204 ,
V_205 ,
& V_206 ) ;
if ( ! V_194 ) {
F_21 ( V_2 ) ;
return - V_17 ;
}
for ( V_199 = 0 ; V_199 < V_192 ; V_199 ++ )
V_194 -> V_207 -> V_208 ( V_194 , V_191 [ V_199 ] , 0 , V_209 ) ;
F_89 ( V_2 , V_189 , V_209 * V_192 , V_56 ) ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 ) {
F_14 ( V_2 ) ;
if ( V_8 != - V_210 )
return V_8 ;
V_198 ++ ;
if ( ! F_90 ( V_198 , & exp -> V_211 -> V_7 . V_4 ) ) {
F_48 ( L_28 ,
exp -> V_211 -> V_175 , - V_185 ) ;
return - V_185 ;
}
V_197 = F_91 ( F_92 ( V_198 ) , NULL , NULL ,
NULL ) ;
F_93 ( V_195 , 0 , & V_197 ) ;
goto V_200;
}
V_8 = F_94 ( V_2 , V_2 -> V_212 ,
V_2 -> V_212 -> V_213 ) ;
if ( V_8 < 0 ) {
F_14 ( V_2 ) ;
return V_8 ;
}
if ( V_2 -> V_212 -> V_213 & ~ V_214 ) {
F_48 ( L_29 ,
exp -> V_211 -> V_175 , V_2 -> V_212 -> V_213 ,
V_209 * V_192 ) ;
F_14 ( V_2 ) ;
return - V_23 ;
}
* V_36 = V_2 ;
return 0 ;
}
static void F_95 ( struct V_190 * V_190 , int remove )
{
if ( remove ) {
F_96 ( V_190 ) ;
if ( F_79 ( V_190 -> V_215 ) )
F_97 ( V_190 -> V_215 , V_190 ) ;
F_98 ( V_190 ) ;
}
F_99 ( V_190 ) ;
}
static struct V_190 * F_100 ( struct V_216 * V_215 , T_5 * V_217 ,
T_5 * V_218 , T_5 * V_219 , int V_220 )
{
unsigned long V_189 = F_101 ( * V_217 , V_220 ) ;
struct V_190 * V_190 ;
int V_221 ;
F_102 ( & V_215 -> V_222 ) ;
V_221 = F_103 ( & V_215 -> V_223 ,
( void * * ) & V_190 , V_189 , 1 ) ;
if ( V_221 > 0 && ! F_104 ( V_190 ) ) {
struct V_224 * V_225 ;
F_105 ( V_190 ) ;
F_106 ( & V_215 -> V_222 ) ;
F_107 ( V_190 ) ;
if ( F_108 ( V_190 ) ) {
V_225 = F_109 ( V_190 ) ;
if ( V_226 == 32 && V_220 ) {
* V_218 = F_110 ( V_225 -> V_227 ) >> 32 ;
* V_219 = F_110 ( V_225 -> V_228 ) >> 32 ;
* V_217 = * V_217 >> 32 ;
} else {
* V_218 = F_110 ( V_225 -> V_227 ) ;
* V_219 = F_110 ( V_225 -> V_228 ) ;
}
if ( F_111 ( * V_218 == 1 && * V_217 == 0 ) )
* V_217 = * V_218 ;
else
F_80 ( * V_218 <= * V_217 , L_30 ,
* V_218 , * V_219 , * V_217 ) ;
F_11 ( V_229 , L_31 ,
V_189 , * V_218 , * V_219 , * V_217 ) ;
if ( * V_217 > * V_219 ) {
F_112 ( V_190 ) ;
F_95 ( V_190 , 0 ) ;
V_190 = NULL ;
} else if ( * V_219 != * V_218 && * V_217 == * V_219 ) {
F_112 ( V_190 ) ;
F_95 ( V_190 ,
F_113 ( V_225 -> V_230 ) & V_231 ) ;
V_190 = NULL ;
}
} else {
F_99 ( V_190 ) ;
V_190 = F_114 ( - V_185 ) ;
}
} else {
F_106 ( & V_215 -> V_222 ) ;
V_190 = NULL ;
}
return V_190 ;
}
static void F_115 ( struct V_190 * * V_191 , int V_232 , int V_233 )
{
int V_199 ;
for ( V_199 = 0 ; V_199 < V_232 ; V_199 ++ ) {
struct V_224 * V_225 = F_109 ( V_191 [ V_199 ] ) ;
T_5 V_234 = F_110 ( V_225 -> V_228 ) ;
T_2 V_63 = F_113 ( V_225 -> V_230 ) ;
struct V_224 * V_235 = V_225 ;
struct V_236 * V_237 = NULL ;
struct V_236 * V_238 ;
while ( -- V_233 > 0 ) {
V_238 = F_116 ( V_225 ) ;
for ( V_237 = V_238 ; V_238 ;
V_237 = V_238 , V_238 = F_117 ( V_238 ) ) ;
V_225 = (struct V_224 * ) ( ( char * ) V_225 + V_239 ) ;
if ( ! ( ( unsigned long ) V_225 & ~ V_240 ) )
break;
V_234 = F_110 ( V_225 -> V_228 ) ;
V_63 = F_113 ( V_225 -> V_230 ) ;
if ( ! V_237 )
break;
F_25 ( ! F_118 ( V_237 -> V_241 ) ) ;
V_237 -> V_241 =
F_119 ( ( char * ) ( V_225 -> V_242 ) -
( char * ) V_237 ) ;
}
V_235 -> V_228 = V_234 ;
V_235 -> V_230 &= ~ F_120 ( V_231 ) ;
V_235 -> V_230 |= V_63 & F_120 ( V_231 ) ;
F_112 ( V_191 [ V_199 ] ) ;
}
F_80 ( V_233 == 0 , L_32 , V_233 ) ;
}
static int F_121 ( void * V_243 , struct V_190 * V_244 )
{
struct V_245 * V_246 = V_243 ;
struct V_190 * * V_247 ;
struct V_190 * V_190 ;
struct V_224 * V_225 ;
int V_248 = 0 ;
int V_192 ;
struct V_34 * V_35 = V_246 -> V_249 ;
struct V_1 * V_2 ;
int V_250 = V_35 -> V_251 ;
struct V_252 * V_252 ;
struct V_10 * V_56 ;
int V_199 ;
int V_8 ;
F_25 ( V_250 > 0 && V_250 <= V_253 ) ;
V_252 = V_35 -> V_35 ;
V_56 = & V_35 -> V_42 ;
F_25 ( V_252 ) ;
V_247 = F_122 ( V_250 , sizeof( V_190 ) , V_254 ) ;
if ( V_247 ) {
V_247 [ 0 ] = V_244 ;
} else {
V_247 = & V_244 ;
V_250 = 1 ;
}
for ( V_192 = 1 ; V_192 < V_250 ; V_192 ++ ) {
V_190 = F_123 ( V_252 -> V_255 ) ;
if ( ! V_190 )
break;
V_247 [ V_192 ] = V_190 ;
}
V_8 = F_86 ( V_246 -> V_256 , V_56 , V_246 -> V_257 , V_247 , V_192 , & V_2 ) ;
if ( ! V_8 ) {
int V_233 = V_2 -> V_212 -> V_213 ;
V_248 = ( V_2 -> V_212 -> V_213 +
V_209 - 1 ) >> V_258 ;
V_233 >>= V_259 ;
F_25 ( ! ( V_2 -> V_212 -> V_213 & ~ V_214 ) ) ;
F_11 ( V_260 , L_33 , V_248 , V_233 ) ;
F_115 ( V_247 , V_248 , V_233 ) ;
F_124 ( V_244 ) ;
}
F_98 ( V_244 ) ;
F_14 ( V_2 ) ;
F_11 ( V_261 , L_34 , V_248 , V_192 ) ;
for ( V_199 = 1 ; V_199 < V_192 ; V_199 ++ ) {
unsigned long V_189 ;
T_5 V_217 ;
int V_262 ;
V_190 = V_247 [ V_199 ] ;
if ( V_8 < 0 || V_199 >= V_248 ) {
F_99 ( V_190 ) ;
continue;
}
F_124 ( V_190 ) ;
V_225 = F_109 ( V_190 ) ;
V_217 = F_110 ( V_225 -> V_227 ) ;
F_112 ( V_190 ) ;
V_189 = F_101 ( V_217 , V_246 -> V_263 ) ;
F_125 ( & V_190 -> V_63 ) ;
V_262 = F_126 ( V_190 , V_252 -> V_255 , V_189 ,
V_264 ) ;
if ( ! V_262 )
F_98 ( V_190 ) ;
else
F_11 ( V_229 , L_35 ,
V_189 , V_262 ) ;
F_99 ( V_190 ) ;
}
if ( V_247 != & V_244 )
F_127 ( V_247 ) ;
return V_8 ;
}
static int F_128 ( struct V_9 * exp , struct V_34 * V_35 ,
struct V_265 * V_266 , T_5 V_267 ,
struct V_190 * * V_268 )
{
struct V_144 V_145 = { . V_269 = V_270 } ;
struct V_190 * V_190 ;
struct V_252 * V_271 = V_35 -> V_35 ;
struct V_216 * V_215 ;
struct V_224 * V_225 ;
T_5 V_218 = 0 ;
T_5 V_219 = 0 ;
struct V_123 V_272 ;
struct V_1 * V_273 = NULL ;
struct V_245 V_274 ;
int V_8 ;
* V_268 = NULL ;
F_25 ( V_271 ) ;
V_215 = V_271 -> V_255 ;
V_8 = F_129 ( exp , V_35 , & V_145 , & V_273 ,
V_266 -> V_275 , 0 ) ;
if ( V_273 )
F_14 ( V_273 ) ;
if ( V_8 < 0 ) {
F_48 ( L_18 V_26 L_36 ,
exp -> V_211 -> V_175 , F_12 ( & V_35 -> V_42 ) , V_8 ) ;
return V_8 ;
}
V_8 = 0 ;
V_272 . V_132 = V_145 . V_276 ;
F_130 ( exp , & V_272 , V_271 , NULL ) ;
V_274 . V_257 = V_267 ;
V_274 . V_263 = V_35 -> V_277 & V_278 ;
V_190 = F_100 ( V_215 , & V_274 . V_257 , & V_218 , & V_219 ,
V_274 . V_263 ) ;
if ( F_46 ( V_190 ) ) {
F_11 ( V_107 , L_37 V_26 L_38 ,
exp -> V_211 -> V_175 , F_12 ( & V_35 -> V_42 ) ,
V_274 . V_257 , F_47 ( V_190 ) ) ;
V_8 = F_47 ( V_190 ) ;
goto V_279;
} else if ( V_190 ) {
goto V_280;
}
V_274 . V_256 = exp ;
V_274 . V_249 = V_35 ;
V_190 = F_131 ( V_215 ,
F_101 ( V_274 . V_257 ,
V_274 . V_263 ) ,
F_121 , & V_274 ) ;
if ( F_46 ( V_190 ) ) {
F_48 ( L_39 V_26 L_38 ,
exp -> V_211 -> V_175 , F_12 ( & V_35 -> V_42 ) ,
V_274 . V_257 , F_47 ( V_190 ) ) ;
V_8 = F_47 ( V_190 ) ;
goto V_279;
}
F_107 ( V_190 ) ;
( void ) F_109 ( V_190 ) ;
if ( ! F_108 ( V_190 ) ) {
F_48 ( L_40 V_26 L_41 ,
exp -> V_211 -> V_175 , F_12 ( & V_35 -> V_42 ) ,
V_274 . V_257 , - 5 ) ;
goto V_281;
}
if ( ! F_132 ( V_190 ) )
F_133 ( V_190 ) ;
if ( F_134 ( V_190 ) ) {
F_48 ( L_42 V_26 L_41 ,
exp -> V_211 -> V_175 , F_12 ( & V_35 -> V_42 ) ,
V_274 . V_257 , - 5 ) ;
goto V_281;
}
V_280:
V_225 = F_135 ( V_190 ) ;
if ( V_226 == 32 && V_274 . V_263 ) {
V_218 = F_110 ( V_225 -> V_227 ) >> 32 ;
V_219 = F_110 ( V_225 -> V_228 ) >> 32 ;
V_274 . V_257 = V_267 >> 32 ;
} else {
V_218 = F_110 ( V_225 -> V_227 ) ;
V_219 = F_110 ( V_225 -> V_228 ) ;
V_274 . V_257 = V_267 ;
}
if ( V_219 == V_218 ) {
F_25 ( V_218 == V_274 . V_257 ) ;
F_81 ( L_43 , ( unsigned long ) V_219 ) ;
#if V_226 == 32
F_81 ( L_44 ,
F_110 ( V_225 -> V_227 ) ,
F_110 ( V_225 -> V_228 ) , V_267 ) ;
#endif
goto V_281;
}
* V_268 = V_190 ;
V_279:
F_136 ( & V_272 , V_145 . V_282 ) ;
return V_8 ;
V_281:
F_112 ( V_190 ) ;
F_95 ( V_190 , 1 ) ;
V_8 = - V_185 ;
goto V_279;
}
static int F_137 ( const struct V_283 * V_284 ,
struct V_9 * exp , struct V_285 * V_286 ,
T_5 V_287 , T_2 V_63 )
{
struct V_167 * V_168 = F_76 ( exp ) ;
struct V_1 * V_2 ;
struct V_285 * V_288 ;
struct V_149 * V_150 = NULL ;
int V_8 ;
F_138 ( & V_168 -> V_7 . V_4 . V_289 ) ;
if ( V_168 -> V_7 . V_4 . V_290 )
V_150 = F_139 ( V_168 -> V_7 . V_4 . V_290 ) ;
F_140 ( & V_168 -> V_7 . V_4 . V_289 ) ;
if ( ! V_150 )
return - V_291 ;
V_2 = F_6 ( V_150 , & V_292 ,
V_15 , V_293 ) ;
if ( ! V_2 ) {
V_8 = - V_17 ;
goto V_294;
}
F_9 ( V_2 ) ;
if ( V_63 & V_295 ) {
V_2 -> V_296 = 1 ;
V_2 -> V_297 = 1 ;
}
V_8 = F_3 ( V_2 ) ;
if ( V_8 ) {
if ( V_150 -> V_298 )
V_8 = V_150 -> V_298 ;
goto V_20;
}
V_288 = F_10 ( & V_2 -> V_21 , & V_299 ) ;
if ( ! V_288 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_286 = * V_288 ;
V_20:
F_14 ( V_2 ) ;
V_294:
F_141 ( V_150 ) ;
return V_8 ;
}
static int F_142 ( struct V_9 * exp , struct V_300 * V_301 )
{
T_2 V_302 , V_303 ;
void * V_304 ;
int V_8 ;
if ( V_301 -> V_305 > V_306 )
return - V_307 ;
if ( V_301 -> V_305 < 2 )
return - V_308 ;
V_302 = F_143 ( sizeof( V_309 ) ) + sizeof( * V_301 ) ;
V_304 = F_144 ( V_302 , V_254 ) ;
if ( ! V_304 )
return - V_17 ;
memcpy ( V_304 , V_309 , sizeof( V_309 ) ) ;
memcpy ( V_304 + F_143 ( sizeof( V_309 ) ) , V_301 , sizeof( * V_301 ) ) ;
F_11 ( V_310 , L_45 V_26 L_46 ,
F_12 ( & V_301 -> V_311 ) , V_301 -> V_312 , V_301 -> V_313 ) ;
if ( ! F_28 ( & V_301 -> V_311 ) ) {
V_8 = - V_314 ;
goto V_20;
}
V_303 = sizeof( * V_301 ) + V_301 -> V_305 ;
V_8 = F_145 ( NULL , exp , V_302 , V_304 , & V_303 , V_301 ) ;
if ( V_8 != 0 && V_8 != - V_315 )
goto V_20;
if ( V_303 <= sizeof( * V_301 ) ) {
V_8 = - V_23 ;
goto V_20;
} else if ( V_303 > sizeof( * V_301 ) + V_301 -> V_305 ) {
V_8 = - V_308 ;
goto V_20;
}
F_11 ( V_310 , L_47 V_26 L_48 ,
F_12 ( & V_301 -> V_311 ) , V_301 -> V_312 , V_301 -> V_313 ,
V_301 -> V_305 < 512 ? V_301 -> V_316 :
V_301 -> V_316 + V_301 -> V_305 - 512 ) ;
V_20:
F_127 ( V_304 ) ;
return V_8 ;
}
static int F_146 ( struct V_9 * exp ,
struct V_317 * V_318 )
{
struct V_149 * V_150 = F_7 ( exp ) ;
struct V_317 * V_319 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_6 ( V_150 , & V_320 ,
V_15 , V_321 ) ;
if ( ! V_2 ) {
V_8 = - V_17 ;
goto V_20;
}
F_8 ( V_2 , NULL , 0 , 0 , - 1 , 0 ) ;
V_319 = F_24 ( & V_2 -> V_21 , & V_322 ) ;
if ( ! V_319 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_319 = * V_318 ;
V_319 -> V_323 = F_147 ( V_318 -> V_323 ) ;
F_9 ( V_2 ) ;
F_40 ( V_2 , NULL ) ;
V_8 = F_3 ( V_2 ) ;
F_41 ( V_2 , NULL ) ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_148 ( struct V_149 * V_150 , T_2 V_324 )
{
T_2 * V_325 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_6 ( V_150 , & V_326 ,
V_15 ,
V_327 ) ;
if ( ! V_2 ) {
V_8 = - V_17 ;
goto V_20;
}
F_8 ( V_2 , NULL , 0 , 0 , - 1 , 0 ) ;
V_325 = F_24 ( & V_2 -> V_21 ,
& V_328 ) ;
if ( ! V_325 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_325 = V_324 ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_149 ( struct V_9 * exp ,
struct V_34 * V_35 )
{
struct V_329 * V_330 = V_35 -> V_35 ;
struct V_329 * V_331 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_19 ( F_7 ( exp ) ,
& V_332 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_333 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_35 -> V_42 , 0 , 0 ,
V_35 -> V_51 [ 0 ] , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
goto V_20;
V_331 = F_10 ( & V_2 -> V_21 ,
& V_334 ) ;
if ( ! V_331 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_330 = * V_331 ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_150 ( struct V_149 * V_150 )
{
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_6 ( V_150 , & V_335 ,
V_15 ,
V_336 ) ;
if ( ! V_2 ) {
V_8 = - V_17 ;
goto V_20;
}
F_8 ( V_2 , NULL , 0 , 0 , - 1 , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_151 ( struct V_9 * exp ,
struct V_34 * V_35 )
{
struct V_337 * V_338 = V_35 -> V_35 ;
struct V_337 * V_339 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_19 ( F_7 ( exp ) ,
& V_340 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_341 ) ;
if ( V_8 != 0 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_35 -> V_42 , 0 , 0 ,
V_35 -> V_51 [ 0 ] , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
goto V_20;
V_339 = F_10 ( & V_2 -> V_21 , & V_342 ) ;
if ( ! V_339 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_338 = * V_339 ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_152 ( struct V_9 * exp ,
struct V_34 * V_35 )
{
struct V_343 * V_344 = V_35 -> V_35 ;
struct V_343 * V_345 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_19 ( F_7 ( exp ) ,
& V_346 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_347 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_35 -> V_42 , 0 , 0 ,
V_35 -> V_51 [ 0 ] , 0 ) ;
V_345 = F_24 ( & V_2 -> V_21 , & V_348 ) ;
if ( ! V_345 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_345 = * V_344 ;
F_9 ( V_2 ) ;
F_40 ( V_2 , NULL ) ;
V_8 = F_3 ( V_2 ) ;
F_41 ( V_2 , NULL ) ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_153 ( struct V_9 * exp ,
struct V_349 * V_350 )
{
struct V_149 * V_150 = F_7 ( exp ) ;
struct V_1 * V_2 ;
struct V_351 * V_352 ;
struct V_353 * V_354 ;
char * V_355 ;
int V_8 ;
V_2 = F_19 ( V_150 , & V_356 ) ;
if ( ! V_2 ) {
V_8 = - V_17 ;
goto V_20;
}
F_22 ( & V_2 -> V_21 , & V_357 , V_48 ,
V_350 -> V_358 . V_359
* sizeof( struct V_353 ) ) ;
F_22 ( & V_2 -> V_21 , & V_360 , V_48 ,
V_350 -> V_358 . V_361 ) ;
V_8 = F_20 ( V_2 , V_15 , V_362 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , NULL , 0 , 0 , - 1 , 0 ) ;
V_352 = F_24 ( & V_2 -> V_21 , & V_363 ) ;
if ( ! V_352 ) {
V_8 = - V_23 ;
goto V_20;
}
* V_352 = V_350 -> V_358 ;
V_354 = F_24 ( & V_2 -> V_21 , & V_357 ) ;
if ( ! V_354 ) {
V_8 = - V_23 ;
goto V_20;
}
memcpy ( V_354 , V_350 -> V_364 ,
V_350 -> V_358 . V_359 * sizeof( struct V_353 ) ) ;
V_355 = F_24 ( & V_2 -> V_21 , & V_360 ) ;
if ( ! V_355 ) {
V_8 = - V_23 ;
goto V_20;
}
memcpy ( V_355 , F_154 ( V_350 ) , V_350 -> V_358 . V_361 ) ;
F_9 ( V_2 ) ;
F_40 ( V_2 , NULL ) ;
V_8 = F_3 ( V_2 ) ;
F_41 ( V_2 , NULL ) ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static struct V_365 * F_155 ( char * V_100 , T_3 V_366 , T_6 V_63 )
{
struct V_365 * V_367 = (struct V_365 * ) V_100 ;
F_25 ( V_366 <= V_368 ) ;
V_367 -> V_369 = V_370 ;
V_367 -> V_371 = V_372 ;
V_367 -> V_373 = V_63 ;
V_367 -> V_374 = V_375 ;
V_367 -> V_376 = V_366 ;
return V_367 ;
}
static inline char * F_156 ( struct V_377 * V_378 )
{
return V_378 -> V_379 -> V_175 ;
}
static int F_157 ( const struct V_283 * V_284 , struct V_380 * V_381 ,
struct V_382 * V_383 , void * V_243 )
{
struct V_377 * V_378 = V_243 ;
struct V_384 * V_76 = (struct V_384 * ) V_383 ;
struct V_365 * V_367 ;
T_3 V_366 ;
int V_8 ;
if ( V_76 -> V_385 . V_386 != V_387 ) {
V_8 = - V_314 ;
F_48 ( L_49 ,
F_156 ( V_378 ) , V_76 -> V_385 . V_386 ,
V_76 -> V_388 . V_389 , V_8 ) ;
return V_8 ;
}
if ( V_76 -> V_388 . V_390 < V_378 -> V_391 ) {
F_11 ( V_392 , L_50 ,
V_76 -> V_388 . V_390 , V_378 -> V_391 ) ;
return 0 ;
}
F_11 ( V_392 , L_51 V_26 L_52 V_26
L_53 , V_76 -> V_388 . V_390 , V_76 -> V_388 . V_389 ,
F_158 ( V_76 -> V_388 . V_389 ) , V_76 -> V_388 . V_393 ,
V_76 -> V_388 . V_394 & V_395 ,
F_12 ( & V_76 -> V_388 . V_396 ) , F_12 ( & V_76 -> V_388 . V_397 ) ,
V_76 -> V_388 . V_398 , F_159 ( & V_76 -> V_388 ) ) ;
V_366 = sizeof( * V_367 ) + F_160 ( & V_76 -> V_388 ) + V_76 -> V_388 . V_398 ;
V_367 = F_155 ( V_378 -> V_399 , V_366 , V_378 -> V_400 ) ;
memcpy ( V_367 + 1 , & V_76 -> V_388 , V_366 - sizeof( * V_367 ) ) ;
V_8 = F_161 ( V_378 -> V_401 , V_367 ) ;
F_11 ( V_392 , L_54 , V_378 -> V_401 , V_366 , V_8 ) ;
return V_8 ;
}
static int F_162 ( void * V_402 )
{
enum V_403 V_63 = V_404 ;
struct V_377 * V_378 = V_402 ;
struct V_405 * V_406 = NULL ;
struct V_380 * V_381 = NULL ;
struct V_365 * V_407 ;
int V_8 ;
F_11 ( V_392 , L_55 ,
V_378 -> V_401 , V_378 -> V_391 ) ;
V_378 -> V_399 = F_144 ( V_368 , V_254 ) ;
if ( ! V_378 -> V_399 ) {
V_8 = - V_17 ;
goto V_20;
}
V_406 = F_163 ( V_378 -> V_379 , V_408 ) ;
if ( ! V_406 ) {
V_8 = - V_409 ;
goto V_20;
}
V_8 = F_164 ( NULL , V_406 , & V_381 , NULL , V_410 ,
V_411 ) ;
if ( V_8 ) {
F_48 ( L_56 ,
F_156 ( V_378 ) , V_8 ) ;
goto V_20;
}
if ( V_378 -> V_400 & V_412 )
V_63 |= V_413 ;
V_8 = F_165 ( NULL , V_381 , V_63 , NULL ) ;
if ( V_8 ) {
F_48 ( L_57 , V_8 ) ;
goto V_20;
}
V_8 = F_166 ( NULL , V_381 , F_157 , V_378 , 0 , 0 ) ;
V_407 = F_155 ( V_378 -> V_399 , sizeof( * V_407 ) , V_378 -> V_400 ) ;
V_407 -> V_374 = V_414 ;
F_161 ( V_378 -> V_401 , V_407 ) ;
V_20:
F_167 ( V_378 -> V_401 ) ;
if ( V_381 )
F_168 ( NULL , V_381 ) ;
if ( V_406 )
F_169 ( V_406 ) ;
F_127 ( V_378 -> V_399 ) ;
F_127 ( V_378 ) ;
return V_8 ;
}
static int F_170 ( struct V_167 * V_168 ,
struct V_415 * V_416 )
{
struct V_377 * V_378 ;
struct V_417 * V_418 ;
int V_8 ;
V_378 = F_144 ( sizeof( * V_378 ) , V_254 ) ;
if ( ! V_378 )
return - V_17 ;
V_378 -> V_379 = V_168 ;
V_378 -> V_391 = V_416 -> V_419 ;
V_378 -> V_401 = F_171 ( V_416 -> V_420 ) ;
V_378 -> V_400 = V_416 -> V_421 ;
V_418 = F_172 ( F_162 , V_378 ,
L_58 ) ;
if ( F_46 ( V_418 ) ) {
V_8 = F_47 ( V_418 ) ;
F_48 ( L_59 ,
F_156 ( V_378 ) , V_8 ) ;
F_127 ( V_378 ) ;
} else {
V_8 = 0 ;
F_11 ( V_392 , L_60 ,
F_156 ( V_378 ) ) ;
}
F_48 ( L_61 , V_8 ) ;
return V_8 ;
}
static int F_173 ( struct V_167 * V_422 , struct V_9 * exp ,
struct V_423 * V_424 )
{
struct V_1 * V_2 ;
struct V_423 * V_425 ;
int V_8 ;
V_2 = F_6 ( F_7 ( exp ) ,
& V_426 , V_15 ,
V_427 ) ;
if ( ! V_2 )
return - V_17 ;
V_425 = F_24 ( & V_2 -> V_21 , & V_428 ) ;
* V_425 = * V_424 ;
F_9 ( V_2 ) ;
F_82 ( V_2 ) ;
V_2 -> V_296 = 1 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
F_48 ( L_62 , V_8 ) ;
if ( V_2 -> V_27 ) {
V_425 = F_10 ( & V_2 -> V_21 , & V_428 ) ;
if ( V_425 ) {
* V_424 = * V_425 ;
} else if ( ! V_8 ) {
F_48 ( L_63 ) ;
V_8 = - V_23 ;
}
} else if ( ! V_8 ) {
F_48 ( L_63 ) ;
V_8 = - V_23 ;
}
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_174 ( struct V_9 * exp ,
struct V_34 * V_35 )
{
F_29 ( V_72 ) ;
struct V_1 * V_2 ;
int V_8 , V_73 ;
struct V_429 * V_430 , * V_431 ;
V_430 = V_35 -> V_35 ;
V_73 = F_30 ( exp , & V_35 -> V_42 , & V_72 ,
V_432 , V_433 |
V_71 ) ;
V_73 += F_30 ( exp , & V_35 -> V_174 , & V_72 ,
V_432 , V_433 |
V_71 ) ;
V_2 = F_19 ( F_7 ( exp ) ,
& V_434 ) ;
if ( ! V_2 ) {
F_175 ( & V_72 , V_435 , V_73 ) ;
return - V_17 ;
}
V_8 = F_31 ( exp , V_2 , V_436 , & V_72 , V_73 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_176 ( V_2 , V_35 ) ;
V_431 = F_24 ( & V_2 -> V_21 , & V_437 ) ;
F_25 ( V_431 ) ;
* V_431 = * V_430 ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_177 ( unsigned int V_438 , struct V_9 * exp , int V_366 ,
void * V_439 , void T_7 * V_440 )
{
struct V_167 * V_168 = exp -> V_211 ;
struct V_441 * V_243 = V_439 ;
struct V_149 * V_150 = V_168 -> V_7 . V_4 . V_290 ;
int V_8 ;
if ( ! F_178 ( V_442 ) ) {
F_48 ( L_64 , V_168 -> V_175 ,
F_179 ( V_442 ) ) ;
return - V_314 ;
}
switch ( V_438 ) {
case V_443 :
V_8 = F_170 ( V_168 , V_439 ) ;
goto V_20;
case V_444 : {
struct V_415 * V_416 = V_439 ;
struct V_445 V_378 = {
. V_446 = V_416 -> V_419 ,
. V_447 = V_416 -> V_420
} ;
V_8 = F_180 ( NULL , exp , strlen ( V_448 ) ,
V_448 , sizeof( V_378 ) , & V_378 ,
NULL ) ;
goto V_20;
}
case V_449 :
V_8 = F_142 ( exp , V_439 ) ;
goto V_20;
case V_450 :
V_8 = F_181 ( exp , V_439 ) ;
if ( V_8 == - V_451 )
V_8 = 0 ;
goto V_20;
case V_452 :
V_8 = F_146 ( exp , V_439 ) ;
goto V_20;
case V_453 :
V_8 = F_151 ( exp , V_439 ) ;
goto V_20;
case V_454 :
V_8 = F_152 ( exp , V_439 ) ;
goto V_20;
case V_455 :
V_8 = F_149 ( exp , V_439 ) ;
goto V_20;
case V_456 :
V_8 = F_153 ( exp , V_439 ) ;
goto V_20;
case V_457 :
V_8 = F_182 ( V_150 , V_243 -> V_458 , 0 ) ;
if ( V_8 < 0 )
goto V_20;
V_8 = 0 ;
goto V_20;
case V_459 :
V_8 = F_183 ( V_150 , V_243 -> V_460 ) ;
goto V_20;
case V_461 :
V_8 = F_184 ( V_168 ) ;
goto V_20;
case V_462 : {
struct V_285 V_463 = { 0 } ;
if ( * ( ( T_2 * ) V_243 -> V_464 ) != 0 ) {
V_8 = - V_291 ;
goto V_20;
}
if ( F_185 ( V_243 -> V_465 , F_186 ( V_168 ) ,
F_187 ( T_3 , V_243 -> V_466 ,
sizeof( struct V_467 ) ) ) ) {
V_8 = - V_468 ;
goto V_20;
}
V_8 = F_137 ( NULL , V_168 -> V_469 , & V_463 ,
F_188 ( - V_470 ) ,
0 ) ;
if ( V_8 != 0 )
goto V_20;
if ( F_185 ( V_243 -> V_471 , & V_463 ,
F_187 ( T_3 , V_243 -> V_472 ,
sizeof( V_463 ) ) ) ) {
V_8 = - V_468 ;
goto V_20;
}
V_8 = 0 ;
goto V_20;
}
case V_473 : {
struct V_474 * V_475 = V_439 ;
struct V_423 * V_424 ;
V_424 = F_144 ( sizeof( * V_424 ) , V_254 ) ;
if ( ! V_424 ) {
V_8 = - V_17 ;
goto V_20;
}
F_189 ( V_424 , V_475 ) ;
V_8 = V_423 ( exp , V_424 ) ;
if ( V_8 == 0 ) {
F_189 ( V_475 , V_424 ) ;
V_475 -> V_476 = V_477 ;
V_475 -> V_467 = V_168 -> V_7 . V_4 . V_478 ;
}
F_127 ( V_424 ) ;
goto V_20;
}
case V_479 :
if ( F_185 ( V_440 , F_190 ( exp ) ,
sizeof( * F_190 ( exp ) ) ) ) {
V_8 = - V_468 ;
goto V_20;
}
V_8 = 0 ;
goto V_20;
case V_480 :
V_8 = F_174 ( exp , V_439 ) ;
goto V_20;
default:
F_48 ( L_65 , V_438 ) ;
V_8 = - V_481 ;
goto V_20;
}
V_20:
F_191 ( V_442 ) ;
return V_8 ;
}
static int F_192 ( struct V_9 * exp ,
T_6 V_302 , void * V_304 ,
int V_303 , void * V_482 )
{
struct V_149 * V_150 = F_7 ( exp ) ;
struct V_1 * V_2 ;
char * V_66 ;
int V_8 = - V_314 ;
V_2 = F_19 ( V_150 , & V_483 ) ;
if ( ! V_2 )
return - V_17 ;
F_22 ( & V_2 -> V_21 , & V_484 ,
V_48 , V_302 ) ;
F_22 ( & V_2 -> V_21 , & V_485 ,
V_48 , sizeof( T_2 ) ) ;
V_8 = F_20 ( V_2 , V_15 , V_486 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
V_66 = F_24 ( & V_2 -> V_21 , & V_484 ) ;
memcpy ( V_66 , V_304 , V_302 ) ;
V_66 = F_24 ( & V_2 -> V_21 , & V_485 ) ;
memcpy ( V_66 , & V_303 , sizeof( T_2 ) ) ;
F_22 ( & V_2 -> V_21 , & V_487 ,
V_45 , V_303 ) ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 == 0 || V_8 == - V_315 ) {
V_66 = F_10 ( & V_2 -> V_21 , & V_487 ) ;
memcpy ( V_482 , V_66 , V_303 ) ;
if ( F_193 ( V_2 ) ) {
if ( F_194 ( V_309 ) )
F_195 ( V_482 ) ;
}
}
F_14 ( V_2 ) ;
return V_8 ;
}
static void F_196 ( struct V_488 * V_489 )
{
F_197 ( & V_489 -> V_490 ) ;
F_197 ( & V_489 -> V_491 ) ;
F_198 ( & V_489 -> V_492 ) ;
F_198 ( & V_489 -> V_493 ) ;
F_199 ( & V_489 -> V_494 ) ;
F_199 ( & V_489 -> V_495 . V_189 ) ;
F_199 ( & V_489 -> V_495 . V_496 ) ;
F_199 ( & V_489 -> V_497 ) ;
}
static void F_200 ( struct V_498 * V_489 )
{
struct V_488 * V_499 ;
T_6 V_199 ;
F_197 ( & V_489 -> V_500 ) ;
F_197 ( & V_489 -> V_501 ) ;
F_197 ( & V_489 -> V_502 ) ;
F_199 ( & V_489 -> V_503 ) ;
V_499 = F_201 ( V_489 ) ;
for ( V_199 = 0 ; V_199 < V_489 -> V_501 ; V_199 ++ , V_499 = F_202 ( V_499 ) )
F_196 ( V_499 ) ;
}
static void F_203 ( struct V_365 * V_504 )
{
F_204 ( & V_504 -> V_369 ) ;
F_204 ( & V_504 -> V_374 ) ;
F_204 ( & V_504 -> V_376 ) ;
}
static int F_181 ( struct V_9 * exp ,
struct V_505 * V_506 )
{
struct V_149 * V_150 = F_7 ( exp ) ;
T_2 V_507 = V_506 -> V_508 ;
int V_8 = 0 ;
if ( V_506 -> V_509 != V_510 ) {
F_48 ( L_66 , V_506 -> V_509 ) ;
return - V_314 ;
}
F_11 ( V_392 , L_67 , V_506 -> V_511 , V_506 -> V_512 ,
V_506 -> V_513 , V_506 -> V_509 , V_506 -> V_514 ) ;
if ( V_506 -> V_514 & V_515 ) {
V_8 = F_150 ( V_150 ) ;
} else {
V_8 = F_148 ( V_150 , V_507 ) ;
}
return V_8 ;
}
static int F_205 ( T_3 V_366 , void * V_482 )
{
struct V_365 * V_367 = (struct V_365 * ) V_482 ;
struct V_498 * V_516 = (struct V_498 * ) ( V_367 + 1 ) ;
if ( V_366 < sizeof( * V_367 ) + sizeof( * V_516 ) ) {
F_48 ( L_68 , V_366 ,
sizeof( * V_367 ) + sizeof( * V_516 ) ) ;
return - V_23 ;
}
if ( V_367 -> V_369 == F_206 ( V_370 ) ) {
F_203 ( V_367 ) ;
F_200 ( V_516 ) ;
} else if ( V_367 -> V_369 != V_370 ) {
F_48 ( L_69 , V_367 -> V_369 , V_370 ) ;
return - V_23 ;
}
F_11 ( V_392 ,
L_70 ,
V_367 -> V_369 , V_367 -> V_371 , V_367 -> V_374 ,
V_367 -> V_376 , V_516 -> V_501 , V_516 -> V_517 ) ;
return F_207 ( V_510 , V_367 ) ;
}
static int F_208 ( void * V_243 , void * V_518 )
{
struct V_519 * V_520 = V_243 ;
struct V_149 * V_150 = (struct V_149 * ) V_518 ;
int V_8 ;
if ( ! V_520 || V_520 -> V_521 != V_522 )
return - V_23 ;
if ( ! F_209 ( & V_520 -> V_523 , & V_150 -> V_6 -> V_467 ) )
return 0 ;
F_11 ( V_131 , L_71 ,
V_150 -> V_6 -> V_175 , V_520 -> V_524 ) ;
V_8 = F_148 ( V_150 , V_520 -> V_524 ) ;
return ( V_8 == - V_451 ) ? 0 : V_8 ;
}
static int F_210 ( const struct V_283 * V_284 ,
struct V_9 * exp ,
T_6 V_302 , void * V_304 ,
T_6 V_303 , void * V_482 ,
struct V_525 * V_526 )
{
struct V_149 * V_150 = F_7 ( exp ) ;
int V_8 ;
if ( F_194 ( V_527 ) ) {
if ( V_303 != sizeof( int ) )
return - V_314 ;
F_63 ( & V_150 -> V_528 ) ;
if ( * ( ( int * ) V_482 ) ) {
V_150 -> V_529 |= V_530 ;
V_150 -> V_531 . V_532 |=
V_530 ;
} else {
V_150 -> V_529 &= ~ V_530 ;
V_150 -> V_531 . V_532 &=
~ V_530 ;
}
F_64 ( & V_150 -> V_528 ) ;
return F_211 ( V_150 , V_533 , V_15 ,
V_302 , V_304 , V_303 , V_482 , V_526 ) ;
}
if ( F_194 ( V_534 ) ) {
F_212 ( exp -> V_211 ) ;
return 0 ;
}
if ( F_194 ( V_535 ) ) {
F_213 ( V_150 ) ;
return 0 ;
}
if ( F_194 ( V_448 ) ) {
V_8 = F_211 ( V_150 , V_533 , V_15 ,
V_302 , V_304 , V_303 , V_482 , V_526 ) ;
return V_8 ;
}
if ( F_194 ( V_536 ) ) {
V_8 = F_205 ( V_303 , V_482 ) ;
return V_8 ;
}
if ( F_194 ( V_537 ) ) {
T_6 * V_538 = V_482 ;
exp -> V_211 -> V_7 . V_4 . V_183 = * V_538 ;
return 0 ;
}
F_48 ( L_72 , ( char * ) V_304 ) ;
return - V_314 ;
}
static int F_214 ( const struct V_283 * V_284 , struct V_9 * exp ,
T_2 V_302 , void * V_304 , T_2 * V_303 , void * V_482 )
{
int V_8 = - V_314 ;
if ( F_194 ( V_539 ) ) {
T_6 V_540 , * V_541 ;
if ( * V_303 != sizeof( int ) )
return - V_314 ;
V_540 = * ( T_6 * ) V_482 ;
if ( V_540 > exp -> V_211 -> V_7 . V_4 . V_542 )
exp -> V_211 -> V_7 . V_4 . V_542 = V_540 ;
V_541 = V_482 ;
* V_541 = exp -> V_211 -> V_7 . V_4 . V_542 ;
return 0 ;
} else if ( F_194 ( V_537 ) ) {
T_6 * V_538 ;
if ( * V_303 != sizeof( int ) )
return - V_314 ;
V_538 = V_482 ;
* V_538 = exp -> V_211 -> V_7 . V_4 . V_183 ;
return 0 ;
} else if ( F_194 ( V_543 ) ) {
struct V_149 * V_150 = F_7 ( exp ) ;
struct V_544 * V_243 = V_482 ;
if ( * V_303 != sizeof( * V_243 ) )
return - V_314 ;
* V_243 = V_150 -> V_531 ;
return 0 ;
} else if ( F_194 ( V_545 ) ) {
* ( ( T_6 * ) V_482 ) = 1 ;
return 0 ;
}
V_8 = F_192 ( exp , V_302 , V_304 , * V_303 , V_482 ) ;
return V_8 ;
}
static int F_215 ( struct V_9 * exp , const struct V_10 * V_56 ,
struct V_1 * * V_36 )
{
struct V_1 * V_2 ;
int V_8 ;
* V_36 = NULL ;
V_2 = F_19 ( F_7 ( exp ) , & V_546 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_20 ( V_2 , V_15 , V_547 ) ;
if ( V_8 ) {
F_21 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , V_56 , 0 , 0 , - 1 , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
F_14 ( V_2 ) ;
else
* V_36 = V_2 ;
return V_8 ;
}
static int F_216 ( struct V_167 * V_168 , struct V_149 * V_150 ,
enum V_548 V_549 )
{
int V_8 = 0 ;
F_25 ( V_150 -> V_6 == V_168 ) ;
switch ( V_549 ) {
case V_550 : {
struct V_3 * V_4 = & V_168 -> V_7 . V_4 ;
if ( V_4 -> V_551 )
F_217 ( V_4 -> V_551 ) ;
V_8 = F_218 ( V_168 , V_168 , V_552 , NULL ) ;
break;
}
case V_553 : {
struct V_554 * V_555 = V_168 -> V_556 ;
F_219 ( V_555 , V_557 ) ;
break;
}
case V_558 :
V_8 = F_218 ( V_168 , V_168 , V_559 , NULL ) ;
if ( V_8 == 0 )
V_8 = F_220 ( V_510 ,
F_208 ,
( void * ) V_150 ) ;
break;
case V_560 :
V_8 = F_218 ( V_168 , V_168 , V_561 , NULL ) ;
break;
case V_562 :
case V_563 :
case V_564 :
break;
default:
F_48 ( L_73 , V_549 ) ;
F_70 () ;
}
return V_8 ;
}
int F_77 ( const struct V_283 * V_284 , struct V_9 * exp ,
struct V_10 * V_56 , struct V_34 * V_35 )
{
struct V_3 * V_4 = & exp -> V_211 -> V_7 . V_4 ;
struct V_565 * V_566 = V_4 -> V_551 ;
return F_221 ( V_284 , V_566 , V_56 ) ;
}
static struct V_467 * F_222 ( struct V_9 * exp )
{
struct V_3 * V_4 = & exp -> V_211 -> V_7 . V_4 ;
return & V_4 -> V_478 ;
}
static int F_223 ( struct V_567 * V_568 )
{
if ( V_568 -> V_569 -> V_570 != V_571 )
return 0 ;
if ( V_568 -> V_572 . V_573 . V_574 & V_575 )
return 0 ;
return 1 ;
}
static int F_224 ( struct V_576 * V_577 )
{
if ( V_577 -> V_578 )
V_577 -> V_578 = NULL ;
return 0 ;
}
static int F_225 ( struct V_167 * V_168 )
{
struct V_579 * V_580 = & V_168 -> V_581 ;
struct V_405 * V_406 ;
int V_8 ;
V_8 = F_226 ( NULL , V_168 , V_580 , V_408 , V_168 ,
& V_582 ) ;
if ( V_8 )
return V_8 ;
V_406 = F_227 ( V_580 , V_408 ) ;
F_228 ( V_406 ) ;
F_169 ( V_406 ) ;
return 0 ;
}
static void F_229 ( struct V_167 * V_168 )
{
struct V_405 * V_406 ;
V_406 = F_163 ( V_168 , V_408 ) ;
if ( V_406 )
F_230 ( NULL , V_406 ) ;
}
static int F_231 ( struct V_167 * V_168 , struct V_583 * V_584 )
{
struct V_585 V_586 = { NULL } ;
int V_8 ;
V_8 = F_232 () ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_233 ( V_168 , V_584 ) ;
if ( V_8 )
goto V_587;
F_234 ( & V_586 ) ;
F_235 ( V_168 , V_586 . V_588 , V_586 . V_589 ) ;
F_236 ( V_168 ) ;
F_237 ( V_168 ) ;
F_238 ( V_168 -> V_556 , F_223 ) ;
V_168 -> V_556 -> V_590 = & V_591 ;
V_8 = F_225 ( V_168 ) ;
if ( V_8 ) {
F_239 ( V_168 ) ;
F_48 ( L_74 ) ;
return V_8 ;
}
return V_8 ;
V_587:
F_240 () ;
return V_8 ;
}
static int F_241 ( struct V_9 * exp , T_6 V_592 , T_6 V_593 )
{
struct V_167 * V_168 = exp -> V_211 ;
struct V_3 * V_4 = & V_168 -> V_7 . V_4 ;
if ( V_4 -> V_542 < V_592 )
V_4 -> V_542 = V_592 ;
if ( V_4 -> V_183 < V_593 )
V_4 -> V_183 = V_593 ;
return 0 ;
}
static int F_242 ( struct V_167 * V_168 )
{
if ( V_168 -> V_594 -> V_595 <= 1 )
F_243 ( 0 , V_510 ) ;
F_244 ( V_168 ) ;
F_245 ( V_168 ) ;
F_246 ( V_168 ) ;
F_229 ( V_168 ) ;
return 0 ;
}
static int F_239 ( struct V_167 * V_168 )
{
F_240 () ;
return F_247 ( V_168 ) ;
}
static int F_248 ( struct V_167 * V_168 , T_6 V_366 , void * V_100 )
{
struct V_583 * V_596 = V_100 ;
struct V_585 V_586 = { NULL } ;
int V_8 = 0 ;
F_234 ( & V_586 ) ;
switch ( V_596 -> V_597 ) {
default:
V_8 = F_249 ( V_598 , V_586 . V_588 ,
V_596 , V_168 ) ;
if ( V_8 > 0 )
V_8 = 0 ;
break;
}
return V_8 ;
}
static int T_8 F_250 ( void )
{
struct V_585 V_586 = { NULL } ;
F_234 ( & V_586 ) ;
return F_251 ( & V_599 , & V_600 ,
V_601 , NULL ) ;
}
static void F_252 ( void )
{
F_253 ( V_601 ) ;
}
