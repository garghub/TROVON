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
if ( V_2 == NULL )
return - V_17 ;
F_8 ( V_2 , NULL , 0 , 0 , - 1 , 0 ) ;
V_2 -> V_18 = V_19 ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
goto V_20;
V_13 = F_10 ( & V_2 -> V_21 , & V_22 ) ;
if ( V_13 == NULL ) {
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
if ( V_13 == NULL )
return - V_23 ;
F_11 ( V_25 , L_3 , V_13 -> V_31 ) ;
if ( V_13 -> V_32 != 0 ) {
F_16 ( exp , V_13 ) ;
V_30 = F_17 ( V_29 , & V_33 ,
V_13 -> V_32 ) ;
if ( V_30 == NULL )
return - V_23 ;
}
if ( V_13 -> V_34 & V_35 ) {
struct V_36 * V_37 ;
F_18 ( F_19 ( exp ) ) ;
V_37 = F_20 ( V_29 , & V_38 ,
V_39 ) ;
if ( V_37 == NULL )
return - V_23 ;
}
return 0 ;
}
static int F_21 ( struct V_9 * exp , struct V_40 * V_41 ,
struct V_1 * * V_42 )
{
struct V_1 * V_2 ;
int V_8 ;
if ( V_41 -> V_43 & V_44 ) {
V_41 -> V_45 = 0 ;
return 0 ;
}
* V_42 = NULL ;
V_2 = F_22 ( F_7 ( exp ) , & V_46 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_8 = F_23 ( V_2 , V_15 , V_47 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_41 -> V_48 , V_41 -> V_49 ,
V_41 -> V_50 , - 1 , 0 ) ;
F_25 ( & V_2 -> V_21 , & V_33 , V_51 ,
V_41 -> V_50 ) ;
if ( V_41 -> V_49 & V_35 ) {
F_18 ( F_19 ( exp ) ) ;
F_25 ( & V_2 -> V_21 , & V_38 , V_51 ,
sizeof( struct V_36 ) ) ;
}
F_9 ( V_2 ) ;
V_8 = F_15 ( exp , V_2 ) ;
if ( V_8 )
F_14 ( V_2 ) ;
else
* V_42 = V_2 ;
return V_8 ;
}
static int F_26 ( struct V_9 * exp , struct V_40 * V_41 ,
struct V_1 * * V_42 )
{
struct V_1 * V_2 ;
int V_8 ;
* V_42 = NULL ;
V_2 = F_22 ( F_7 ( exp ) ,
& V_52 ) ;
if ( V_2 == NULL )
return - V_17 ;
F_25 ( & V_2 -> V_21 , & V_53 , V_54 ,
V_41 -> V_55 + 1 ) ;
V_8 = F_23 ( V_2 , V_15 , V_56 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_41 -> V_48 , V_41 -> V_49 ,
V_41 -> V_50 , V_41 -> V_57 [ 0 ] , 0 ) ;
if ( V_41 -> V_58 ) {
char * V_59 = F_27 ( & V_2 -> V_21 , & V_53 ) ;
F_18 ( F_28 ( V_41 -> V_58 , V_41 -> V_55 ) ==
V_41 -> V_55 ) ;
memcpy ( V_59 , V_41 -> V_58 , V_41 -> V_55 ) ;
}
F_25 ( & V_2 -> V_21 , & V_33 , V_51 ,
V_41 -> V_50 ) ;
F_9 ( V_2 ) ;
V_8 = F_15 ( exp , V_2 ) ;
if ( V_8 )
F_14 ( V_2 ) ;
else
* V_42 = V_2 ;
return V_8 ;
}
static int F_29 ( struct V_9 * exp ,
const struct V_10 * V_60 ,
const struct V_10 * V_61 ,
struct V_1 * * V_42 )
{
struct V_1 * V_2 ;
int V_8 ;
* V_42 = NULL ;
V_2 = F_6 ( F_7 ( exp ) ,
& V_62 , V_15 ,
V_63 ) ;
if ( V_2 == NULL )
return - V_17 ;
F_30 ( V_2 , V_60 , V_61 , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 && V_8 != - V_64 )
F_14 ( V_2 ) ;
else
* V_42 = V_2 ;
return V_8 ;
}
static int F_31 ( struct V_9 * exp ,
const struct V_65 * V_66 ,
const struct V_10 * V_67 ,
int V_68 , T_1 V_34 ,
const char * V_69 , const char * V_70 ,
int V_71 , int V_72 , int V_73 ,
T_2 V_74 , struct V_1 * * V_42 )
{
struct V_1 * V_2 ;
int V_75 = 0 ;
char * V_76 ;
int V_8 ;
* V_42 = NULL ;
V_2 = F_22 ( F_7 ( exp ) , V_66 ) ;
if ( V_2 == NULL )
return - V_17 ;
if ( V_69 ) {
V_75 = strlen ( V_69 ) + 1 ;
F_25 ( & V_2 -> V_21 , & V_53 , V_54 ,
V_75 ) ;
}
if ( V_71 ) {
F_18 ( V_70 ) ;
F_25 ( & V_2 -> V_21 , & V_77 , V_54 ,
V_71 ) ;
}
if ( V_68 == V_78 && F_32 ( V_67 ) &&
exp -> V_79 . V_80 & V_81 ) {
F_33 ( V_82 ) ;
int V_83 ;
if ( V_71 == 0 )
F_25 ( & V_2 -> V_21 , & V_77 ,
V_54 , 0 ) ;
V_83 = F_34 ( exp , V_67 ,
& V_82 , V_84 ,
V_81 ) ;
V_8 = F_35 ( exp , V_2 , V_78 , & V_82 , V_83 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
} else {
V_8 = F_23 ( V_2 , V_15 , V_68 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
}
if ( V_68 == V_78 ) {
struct V_85 * V_86 ;
F_36 ( sizeof( struct V_85 ) ==
sizeof( struct V_87 ) ) ;
V_86 = F_27 ( & V_2 -> V_21 , & V_88 ) ;
V_86 -> V_89 = V_90 ;
V_86 -> V_91 = F_37 ( & V_92 , F_38 () ) ;
V_86 -> V_93 = F_39 ( & V_92 , F_40 () ) ;
V_86 -> V_94 = F_41 () ;
V_86 -> V_95 = V_74 ;
V_86 -> V_96 = - 1 ;
V_86 -> V_97 = * V_67 ;
V_86 -> V_98 = V_34 | V_99 ;
V_86 -> V_100 = F_42 () ;
V_86 -> V_101 = V_72 ;
V_86 -> V_102 = V_73 ;
} else {
F_8 ( V_2 , V_67 , V_34 , V_72 , V_74 , V_73 ) ;
}
if ( V_69 ) {
V_76 = F_27 ( & V_2 -> V_21 , & V_53 ) ;
memcpy ( V_76 , V_69 , V_75 ) ;
}
if ( V_71 ) {
V_76 = F_27 ( & V_2 -> V_21 , & V_77 ) ;
memcpy ( V_76 , V_70 , V_71 ) ;
}
if ( F_43 ( & V_2 -> V_21 , & V_77 , V_51 ) )
F_25 ( & V_2 -> V_21 , & V_77 ,
V_51 , V_72 ) ;
F_9 ( V_2 ) ;
if ( V_68 == V_78 )
F_44 ( exp -> V_103 -> V_7 . V_4 . V_104 , NULL ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_68 == V_78 )
F_45 ( exp -> V_103 -> V_7 . V_4 . V_104 , NULL ) ;
if ( V_8 )
F_14 ( V_2 ) ;
else
* V_42 = V_2 ;
return V_8 ;
}
static int F_46 ( struct V_9 * exp , const struct V_10 * V_67 ,
T_1 V_34 , const char * V_69 ,
const char * V_70 , int V_71 , int V_72 ,
int V_73 , T_2 V_74 ,
struct V_1 * * V_42 )
{
return F_31 ( exp , & V_105 ,
V_67 , V_78 , V_34 , V_69 ,
V_70 , V_71 , V_72 , V_73 ,
V_74 , V_42 ) ;
}
static int F_47 ( struct V_9 * exp , const struct V_10 * V_67 ,
T_1 V_34 , const char * V_69 ,
const char * V_70 , int V_71 , int V_72 ,
int V_73 , struct V_1 * * V_42 )
{
return F_31 ( exp , & V_106 ,
V_67 , V_107 , V_34 , V_69 ,
V_70 , V_71 , V_72 , V_73 ,
- 1 , V_42 ) ;
}
static int F_48 ( struct V_1 * V_2 , struct V_108 * V_109 )
{
struct V_28 * V_29 = & V_2 -> V_21 ;
struct V_12 * V_13 = V_109 -> V_13 ;
struct V_110 * V_111 ;
void * V_112 ;
int V_8 ;
if ( ! V_13 -> V_113 )
return 0 ;
V_112 = F_17 ( V_29 , & V_38 , V_13 -> V_113 ) ;
if ( ! V_112 )
return - V_23 ;
V_111 = F_49 ( & V_92 , V_112 , V_13 -> V_113 ) ;
if ( V_111 == NULL )
return 0 ;
if ( F_50 ( V_111 ) ) {
V_8 = F_51 ( V_111 ) ;
F_52 ( L_4 , V_8 ) ;
return V_8 ;
}
V_8 = F_53 ( V_111 ) ;
if ( V_8 ) {
F_52 ( L_5 , V_8 ) ;
F_54 ( V_111 ) ;
return V_8 ;
}
V_109 -> V_110 = V_111 ;
return 0 ;
}
int F_55 ( struct V_9 * exp , struct V_1 * V_2 ,
struct V_9 * V_114 , struct V_9 * V_115 ,
struct V_108 * V_109 )
{
struct V_28 * V_29 = & V_2 -> V_21 ;
int V_8 ;
F_18 ( V_109 ) ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_13 = F_10 ( V_29 , & V_22 ) ;
F_18 ( V_109 -> V_13 != NULL ) ;
if ( V_109 -> V_13 -> V_34 & V_116 ) {
int V_117 ;
struct V_118 * V_119 ;
if ( ! F_56 ( V_109 -> V_13 -> V_31 ) ) {
F_11 ( V_120 ,
L_6 ) ;
V_8 = - V_23 ;
goto V_20;
}
if ( V_109 -> V_13 -> V_32 == 0 ) {
F_11 ( V_120 ,
L_7 ) ;
V_8 = - V_23 ;
goto V_20;
}
V_117 = V_109 -> V_13 -> V_32 ;
V_119 = F_17 ( V_29 , & V_33 , V_117 ) ;
if ( ! V_119 ) {
V_8 = - V_23 ;
goto V_20;
}
V_8 = F_57 ( V_114 , & V_109 -> V_121 , V_119 , V_117 ) ;
if ( V_8 < 0 )
goto V_20;
if ( V_8 < sizeof( * V_109 -> V_121 ) ) {
F_11 ( V_120 ,
L_8 ,
V_8 , ( int ) sizeof( * V_109 -> V_121 ) ) ;
V_8 = - V_23 ;
goto V_20;
}
} else if ( V_109 -> V_13 -> V_34 & V_122 ) {
int V_123 ;
struct V_118 * V_124 ;
if ( ! F_58 ( V_109 -> V_13 -> V_31 ) ) {
F_11 ( V_120 ,
L_9 ) ;
V_8 = - V_23 ;
goto V_20;
}
if ( V_109 -> V_13 -> V_32 == 0 ) {
F_11 ( V_120 ,
L_10 ) ;
return - V_23 ;
}
if ( V_109 -> V_13 -> V_34 & V_125 ) {
V_123 = V_109 -> V_13 -> V_32 ;
V_124 = F_17 ( V_29 , & V_33 ,
V_123 ) ;
if ( ! V_124 ) {
V_8 = - V_23 ;
goto V_20;
}
V_8 = F_57 ( V_115 , ( void * ) & V_109 -> V_126 , V_124 ,
V_123 ) ;
if ( V_8 < 0 )
goto V_20;
if ( V_8 < sizeof( * V_109 -> V_126 ) ) {
F_11 ( V_120 ,
L_11 ,
V_8 , ( int ) sizeof( * V_109 -> V_126 ) ) ;
V_8 = - V_23 ;
goto V_20;
}
}
}
V_8 = 0 ;
if ( V_109 -> V_13 -> V_34 & V_35 ) {
F_18 ( F_19 ( exp ) ) ;
V_109 -> V_127 = F_20 ( V_29 , & V_38 ,
V_39 ) ;
if ( ! V_109 -> V_127 ) {
V_8 = - V_23 ;
goto V_20;
}
} else if ( V_109 -> V_13 -> V_34 & V_128 ) {
if ( V_109 -> V_13 -> V_113 ) {
V_8 = F_48 ( V_2 , V_109 ) ;
if ( V_8 )
goto V_20;
#ifdef F_59
} else {
V_109 -> V_110 = NULL ;
#endif
}
}
V_20:
if ( V_8 ) {
#ifdef F_59
F_54 ( V_109 -> V_110 ) ;
#endif
if ( V_109 -> V_121 )
F_60 ( V_114 , & V_109 -> V_121 ) ;
}
return V_8 ;
}
int F_61 ( struct V_9 * exp , struct V_108 * V_109 )
{
return 0 ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_129 * V_130 = V_2 -> V_131 ;
struct V_1 * V_132 ;
struct V_133 * V_134 ;
struct V_135 V_136 ;
struct V_12 * V_13 ;
if ( V_130 == NULL ) {
F_63 ( V_137 , V_2 ,
L_12 ) ;
return;
}
V_13 = F_10 ( & V_2 -> V_21 , & V_22 ) ;
F_18 ( V_13 != NULL ) ;
V_134 = V_130 -> V_138 ;
if ( V_134 != NULL ) {
struct V_135 * V_139 ;
F_18 ( V_134 -> V_140 == V_141 ) ;
V_139 = & V_134 -> V_142 ;
F_11 ( V_143 , L_13 ,
V_139 -> V_144 , V_13 -> V_145 . V_144 ) ;
V_136 = * V_139 ;
* V_139 = V_13 -> V_145 ;
}
V_132 = V_130 -> V_146 ;
if ( V_132 != NULL ) {
T_2 V_147 = F_64 ( V_132 -> V_148 ) ;
struct V_149 * V_150 ;
F_18 ( V_147 == V_151 || V_147 == V_152 ) ;
V_150 = F_27 ( & V_132 -> V_21 ,
& V_153 ) ;
F_18 ( V_150 ) ;
if ( V_134 != NULL )
F_18 ( ! memcmp ( & V_136 , & V_150 -> V_145 , sizeof( V_136 ) ) ) ;
F_63 ( V_143 , V_132 , L_14 ) ;
V_150 -> V_145 = V_13 -> V_145 ;
}
}
void F_65 ( struct V_1 * V_2 )
{
struct V_129 * V_130 = V_2 -> V_131 ;
if ( V_130 == NULL )
return;
F_66 ( V_2 ) ;
F_67 ( & V_2 -> V_154 ) ;
V_2 -> V_155 = 1 ;
F_68 ( & V_2 -> V_154 ) ;
V_2 -> V_131 = NULL ;
F_69 ( V_130 ) ;
}
int F_70 ( struct V_9 * exp ,
struct V_133 * V_134 ,
struct V_156 * V_157 )
{
struct V_129 * V_130 ;
struct V_158 * V_86 ;
struct V_12 * V_13 ;
struct V_1 * V_159 = V_157 -> V_160 . V_161 . V_162 ;
struct V_163 * V_164 = V_159 -> V_5 ;
if ( ! V_159 -> V_165 )
return 0 ;
V_86 = F_27 ( & V_159 -> V_21 , & V_88 ) ;
V_13 = F_10 ( & V_159 -> V_21 , & V_22 ) ;
F_18 ( V_86 != NULL ) ;
F_18 ( V_13 != NULL ) ;
if ( V_134 && V_164 -> V_166 ) {
V_130 = F_71 () ;
if ( V_130 == NULL ) {
F_63 ( V_137 , V_159 ,
L_15 ) ;
return 0 ;
}
F_72 ( V_130 ) ;
F_72 ( V_130 ) ;
F_67 ( & V_159 -> V_154 ) ;
V_134 -> V_167 = V_130 ;
V_130 -> V_138 = V_134 ;
V_130 -> V_168 = F_73 ( V_157 , V_169 ) ||
F_73 ( V_157 , V_170 ) ;
V_130 -> V_171 = V_159 ;
V_159 -> V_131 = V_130 ;
V_159 -> V_172 = F_65 ;
F_68 ( & V_159 -> V_154 ) ;
}
V_86 -> V_173 = V_13 -> V_24 ;
V_86 -> V_174 = V_13 -> V_175 ;
V_86 -> V_176 . V_144 = V_13 -> V_145 . V_144 ;
V_159 -> V_177 = F_62 ;
if ( ! F_32 ( & V_13 -> V_24 ) ) {
F_63 ( V_137 , V_159 ,
L_16 ) ;
F_74 () ;
}
F_63 ( V_178 , V_159 , L_17 ) ;
return 0 ;
}
static void F_75 ( struct V_129 * V_130 )
{
int V_179 = 0 ;
if ( V_130 -> V_168 == 0 &&
F_76 ( V_130 -> V_171 -> V_5 ) )
V_179 = 1 ;
F_18 ( V_130 -> V_171 -> V_165 == 0 ) ;
F_63 ( V_178 , V_130 -> V_171 , L_18 ) ;
F_77 ( V_130 -> V_171 , V_179 ) ;
if ( V_130 -> V_146 )
F_77 ( V_130 -> V_146 , V_179 ) ;
}
int F_78 ( struct V_9 * exp ,
struct V_133 * V_134 )
{
struct V_129 * V_130 = V_134 -> V_167 ;
if ( V_130 == NULL )
return 0 ;
F_18 ( V_130 != V_180 ) ;
F_18 ( V_130 -> V_171 != NULL ) ;
F_75 ( V_130 ) ;
V_130 -> V_138 = NULL ;
V_134 -> V_167 = NULL ;
F_69 ( V_130 ) ;
return 0 ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_40 * V_41 , int V_8 ) {
struct V_12 * V_181 ;
struct V_149 * V_150 ;
if ( V_2 && V_8 == - V_182 ) {
V_181 = F_10 ( & V_2 -> V_21 , & V_22 ) ;
V_150 = F_27 ( & V_2 -> V_21 , & V_153 ) ;
V_150 -> V_73 |= V_183 ;
if ( V_181 -> V_34 & V_184 )
V_41 -> V_43 |= V_185 ;
}
}
static int F_80 ( struct V_9 * exp , struct V_40 * V_41 ,
struct V_129 * V_130 , struct V_1 * * V_42 )
{
struct V_186 * V_187 = F_81 ( exp ) ;
struct V_1 * V_2 ;
struct V_65 * V_188 ;
int V_8 ;
int V_189 = 0 ;
V_188 = & V_190 ;
if ( V_41 -> V_191 & V_192 ) {
V_188 = & V_193 ;
V_8 = F_82 ( exp , & V_41 -> V_194 , V_41 ) ;
if ( V_8 < 0 ) {
F_52 ( L_19 V_26 L_20 ,
V_187 -> V_195 , F_12 ( & V_41 -> V_48 ) , V_8 ) ;
V_189 = V_8 ;
}
}
* V_42 = NULL ;
V_2 = F_22 ( F_7 ( exp ) , V_188 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_8 = F_23 ( V_2 , V_15 , V_151 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
V_2 -> V_196 = V_197 ;
F_83 ( V_2 ) ;
if ( F_84 ( V_130 != NULL ) ) {
F_85 ( V_130 -> V_171 != NULL &&
V_130 -> V_171 -> V_198 != V_199 ,
L_21 , V_130 -> V_171 ) ;
V_130 -> V_146 = V_2 ;
F_63 ( V_143 , V_130 -> V_171 , L_22 ) ;
F_67 ( & V_130 -> V_171 -> V_154 ) ;
V_130 -> V_171 -> V_165 = 0 ;
F_68 ( & V_130 -> V_171 -> V_154 ) ;
} else {
F_11 ( V_143 ,
L_23 ) ;
}
F_86 ( V_2 , V_41 ) ;
F_25 ( & V_2 -> V_21 , & V_33 , V_51 ,
V_187 -> V_7 . V_4 . V_200 ) ;
F_25 ( & V_2 -> V_21 , & V_201 , V_51 ,
V_187 -> V_7 . V_4 . V_202 ) ;
F_9 ( V_2 ) ;
F_44 ( V_187 -> V_7 . V_4 . V_203 , NULL ) ;
V_8 = F_3 ( V_2 ) ;
F_45 ( V_187 -> V_7 . V_4 . V_203 , NULL ) ;
if ( V_2 -> V_27 == NULL ) {
F_11 ( V_178 , L_24 , V_2 ,
V_2 -> V_204 ) ;
if ( V_8 == 0 )
V_8 = V_2 -> V_204 ? : - V_205 ;
} else if ( V_8 == 0 || V_8 == - V_182 ) {
struct V_12 * V_13 ;
V_8 = F_87 ( V_2 -> V_27 ) ;
if ( F_88 ( V_2 -> V_27 ) == V_206 ) {
F_63 ( V_137 , V_2 ,
L_25 , V_8 ) ;
if ( V_8 > 0 )
V_8 = - V_8 ;
}
V_13 = F_10 ( & V_2 -> V_21 , & V_22 ) ;
if ( V_13 == NULL )
V_8 = - V_23 ;
} else if ( V_8 == - V_207 ) {
if ( V_130 ) {
F_63 ( V_143 , V_2 , L_26 , V_8 ) ;
F_18 ( V_130 -> V_171 != NULL ) ;
if ( V_130 -> V_171 -> V_155 )
V_8 = 0 ;
}
}
if ( V_130 ) {
if ( V_8 != 0 )
V_130 -> V_146 = NULL ;
F_69 ( V_130 ) ;
}
* V_42 = V_2 ;
F_79 ( V_2 , V_41 , V_8 ) ;
return V_8 < 0 ? V_8 : V_189 ;
}
static int F_89 ( struct V_9 * exp , struct V_40 * V_41 ,
struct V_129 * V_130 )
{
struct V_186 * V_187 = F_81 ( exp ) ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_22 ( F_7 ( exp ) ,
& V_208 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_8 = F_23 ( V_2 , V_15 , V_152 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
if ( V_130 != NULL ) {
F_85 ( V_130 -> V_171 != NULL &&
V_130 -> V_171 -> V_198 != V_199 ,
L_27 , V_130 -> V_171 ) ;
V_130 -> V_146 = V_2 ;
F_63 ( V_143 , V_130 -> V_171 , L_28 ) ;
F_67 ( & V_130 -> V_171 -> V_154 ) ;
V_130 -> V_171 -> V_165 = 0 ;
F_68 ( & V_130 -> V_171 -> V_154 ) ;
}
F_86 ( V_2 , V_41 ) ;
F_9 ( V_2 ) ;
F_44 ( V_187 -> V_7 . V_4 . V_203 , NULL ) ;
V_8 = F_3 ( V_2 ) ;
F_45 ( V_187 -> V_7 . V_4 . V_203 , NULL ) ;
if ( V_8 == - V_207 ) {
if ( V_130 ) {
F_18 ( V_130 -> V_171 != NULL ) ;
if ( V_130 -> V_171 -> V_155 )
V_8 = 0 ;
}
}
if ( V_130 ) {
if ( V_8 != 0 )
V_130 -> V_146 = NULL ;
F_18 ( V_130 -> V_171 != NULL ) ;
F_75 ( V_130 ) ;
F_69 ( V_130 ) ;
}
F_79 ( V_2 , V_41 , V_8 ) ;
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_90 ( struct V_9 * exp , struct V_40 * V_41 ,
struct V_209 * * V_210 , struct V_1 * * V_42 )
{
struct V_1 * V_2 ;
struct V_211 * V_212 ;
int V_213 ;
T_3 V_214 ;
int V_215 = 0 ;
struct V_216 V_217 ;
int V_8 ;
* V_42 = NULL ;
F_91 ( & V_214 ) ;
V_218:
V_2 = F_22 ( F_7 ( exp ) , & V_219 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_8 = F_23 ( V_2 , V_15 , V_220 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
V_2 -> V_196 = V_197 ;
F_83 ( V_2 ) ;
V_212 = F_92 ( V_2 , V_41 -> V_221 , 1 , V_222 ,
V_223 ) ;
if ( V_212 == NULL ) {
F_24 ( V_2 ) ;
return - V_17 ;
}
for ( V_213 = 0 ; V_213 < V_41 -> V_221 ; V_213 ++ )
F_93 ( V_212 , V_210 [ V_213 ] , 0 , V_224 ) ;
F_94 ( V_2 , V_41 -> V_225 ,
V_224 * V_41 -> V_221 ,
& V_41 -> V_48 ) ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 ) {
F_14 ( V_2 ) ;
if ( V_8 != - V_226 )
return V_8 ;
V_215 ++ ;
if ( ! F_95 ( V_215 , & exp -> V_103 -> V_7 . V_4 ) ) {
F_52 ( L_29 ) ;
return - V_205 ;
}
V_217 = F_96 ( F_97 ( V_215 ) ,
NULL , NULL , NULL ) ;
F_98 ( V_214 , 0 , & V_217 ) ;
goto V_218;
}
V_8 = F_99 ( V_2 , V_2 -> V_227 ,
V_2 -> V_227 -> V_228 ) ;
if ( V_8 < 0 ) {
F_14 ( V_2 ) ;
return V_8 ;
}
if ( V_2 -> V_227 -> V_228 & ~ V_229 ) {
F_52 ( L_30 ,
V_2 -> V_227 -> V_228 ,
V_224 * V_41 -> V_221 ) ;
F_14 ( V_2 ) ;
return - V_23 ;
}
* V_42 = V_2 ;
return 0 ;
}
static int F_100 ( const struct V_230 * V_231 ,
struct V_9 * exp , struct V_232 * V_233 ,
T_4 V_234 , T_2 V_73 )
{
struct V_186 * V_187 = F_81 ( exp ) ;
struct V_1 * V_2 ;
struct V_232 * V_235 ;
struct V_163 * V_164 = NULL ;
int V_8 ;
F_101 ( & V_187 -> V_7 . V_4 . V_236 ) ;
if ( V_187 -> V_7 . V_4 . V_237 )
V_164 = F_102 ( V_187 -> V_7 . V_4 . V_237 ) ;
F_103 ( & V_187 -> V_7 . V_4 . V_236 ) ;
if ( ! V_164 )
return - V_238 ;
V_2 = F_6 ( V_164 , & V_239 ,
V_15 , V_240 ) ;
if ( V_2 == NULL ) {
V_8 = - V_17 ;
goto V_241;
}
F_9 ( V_2 ) ;
if ( V_73 & V_242 ) {
V_2 -> V_243 = 1 ;
V_2 -> V_244 = 1 ;
}
V_8 = F_3 ( V_2 ) ;
if ( V_8 ) {
if ( V_164 -> V_245 )
V_8 = V_164 -> V_245 ;
goto V_20;
}
V_235 = F_10 ( & V_2 -> V_21 , & V_246 ) ;
if ( V_235 == NULL ) {
V_8 = - V_23 ;
goto V_20;
}
* V_233 = * V_235 ;
V_20:
F_14 ( V_2 ) ;
V_241:
F_104 ( V_164 ) ;
return V_8 ;
}
static int F_105 ( struct V_9 * exp , struct V_247 * V_248 )
{
T_2 V_249 , V_250 ;
void * V_251 ;
int V_8 ;
if ( V_248 -> V_252 > V_253 )
return - V_254 ;
if ( V_248 -> V_252 < 2 )
return - V_255 ;
V_249 = F_106 ( sizeof( V_256 ) ) + sizeof( * V_248 ) ;
V_251 = F_107 ( V_249 , V_257 ) ;
if ( ! V_251 )
return - V_17 ;
memcpy ( V_251 , V_256 , sizeof( V_256 ) ) ;
memcpy ( V_251 + F_106 ( sizeof( V_256 ) ) , V_248 , sizeof( * V_248 ) ) ;
F_11 ( V_258 , L_31 V_26 L_32 ,
F_12 ( & V_248 -> V_259 ) , V_248 -> V_260 , V_248 -> V_261 ) ;
if ( ! F_32 ( & V_248 -> V_259 ) ) {
V_8 = - V_262 ;
goto V_20;
}
V_250 = sizeof( * V_248 ) + V_248 -> V_252 ;
V_8 = F_108 ( NULL , exp , V_249 , V_251 , & V_250 , V_248 , NULL ) ;
if ( V_8 != 0 && V_8 != - V_64 )
goto V_20;
if ( V_250 <= sizeof( * V_248 ) ) {
V_8 = - V_23 ;
goto V_20;
} else if ( V_250 > sizeof( * V_248 ) + V_248 -> V_252 ) {
V_8 = - V_255 ;
goto V_20;
}
F_11 ( V_258 , L_31 V_26 L_33 ,
F_12 ( & V_248 -> V_259 ) , V_248 -> V_260 , V_248 -> V_261 , V_248 -> V_263 ) ;
V_20:
F_109 ( V_251 ) ;
return V_8 ;
}
static int F_110 ( struct V_9 * exp ,
struct V_264 * V_265 )
{
struct V_163 * V_164 = F_7 ( exp ) ;
struct V_264 * V_266 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_6 ( V_164 , & V_267 ,
V_15 , V_268 ) ;
if ( V_2 == NULL ) {
V_8 = - V_17 ;
goto V_20;
}
F_8 ( V_2 , NULL , V_35 , 0 , 0 , 0 ) ;
V_266 = F_27 ( & V_2 -> V_21 , & V_269 ) ;
if ( V_266 == NULL ) {
V_8 = - V_23 ;
goto V_20;
}
* V_266 = * V_265 ;
V_266 -> V_270 = F_111 ( V_265 -> V_270 ) ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
goto V_20;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_112 ( struct V_163 * V_164 , T_2 V_271 )
{
T_2 * V_272 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_6 ( V_164 , & V_273 ,
V_15 ,
V_274 ) ;
if ( V_2 == NULL ) {
V_8 = - V_17 ;
goto V_20;
}
F_8 ( V_2 , NULL , V_35 , 0 , 0 , 0 ) ;
V_272 = F_27 ( & V_2 -> V_21 ,
& V_275 ) ;
if ( V_272 == NULL ) {
V_8 = - V_23 ;
goto V_20;
}
* V_272 = V_271 ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
goto V_20;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_113 ( struct V_9 * exp ,
struct V_40 * V_41 )
{
struct V_276 * V_277 = V_41 -> V_41 ;
struct V_276 * V_278 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_22 ( F_7 ( exp ) ,
& V_279 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_8 = F_23 ( V_2 , V_15 , V_280 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_41 -> V_48 , V_35 , 0 ,
V_41 -> V_57 [ 0 ] , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
goto V_20;
V_278 = F_10 ( & V_2 -> V_21 ,
& V_281 ) ;
if ( V_278 == NULL ) {
V_8 = - V_23 ;
goto V_20;
}
* V_277 = * V_278 ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_114 ( struct V_163 * V_164 )
{
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_6 ( V_164 , & V_282 ,
V_15 ,
V_283 ) ;
if ( V_2 == NULL ) {
V_8 = - V_17 ;
goto V_20;
}
F_8 ( V_2 , NULL , V_35 , 0 , 0 , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
goto V_20;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_115 ( struct V_9 * exp ,
struct V_40 * V_41 )
{
struct V_284 * V_285 = V_41 -> V_41 ;
struct V_284 * V_286 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_22 ( F_7 ( exp ) ,
& V_287 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_8 = F_23 ( V_2 , V_15 , V_288 ) ;
if ( V_8 != 0 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_41 -> V_48 , V_35 , 0 ,
V_41 -> V_57 [ 0 ] , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
goto V_20;
V_286 = F_10 ( & V_2 -> V_21 , & V_289 ) ;
if ( V_286 == NULL ) {
V_8 = - V_23 ;
goto V_20;
}
* V_285 = * V_286 ;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_116 ( struct V_9 * exp ,
struct V_40 * V_41 )
{
struct V_290 * V_291 = V_41 -> V_41 ;
struct V_290 * V_292 ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_22 ( F_7 ( exp ) ,
& V_293 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_8 = F_23 ( V_2 , V_15 , V_294 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , & V_41 -> V_48 , V_35 , 0 ,
V_41 -> V_57 [ 0 ] , 0 ) ;
V_292 = F_27 ( & V_2 -> V_21 , & V_295 ) ;
if ( V_292 == NULL ) {
V_8 = - V_23 ;
goto V_20;
}
* V_292 = * V_291 ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
goto V_20;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_117 ( struct V_9 * exp ,
struct V_296 * V_297 )
{
struct V_163 * V_164 = F_7 ( exp ) ;
struct V_1 * V_2 ;
struct V_298 * V_299 ;
struct V_300 * V_301 ;
char * V_302 ;
int V_8 ;
V_2 = F_22 ( V_164 , & V_303 ) ;
if ( V_2 == NULL ) {
V_8 = - V_17 ;
goto V_20;
}
F_25 ( & V_2 -> V_21 , & V_304 , V_54 ,
V_297 -> V_305 . V_306
* sizeof( struct V_300 ) ) ;
F_25 ( & V_2 -> V_21 , & V_307 , V_54 ,
V_297 -> V_305 . V_308 ) ;
V_8 = F_23 ( V_2 , V_15 , V_309 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , NULL , V_35 , 0 , 0 , 0 ) ;
V_299 = F_27 ( & V_2 -> V_21 , & V_310 ) ;
if ( V_299 == NULL ) {
V_8 = - V_23 ;
goto V_20;
}
* V_299 = V_297 -> V_305 ;
V_301 = F_27 ( & V_2 -> V_21 , & V_304 ) ;
if ( V_301 == NULL ) {
V_8 = - V_23 ;
goto V_20;
}
memcpy ( V_301 , V_297 -> V_311 ,
V_297 -> V_305 . V_306 * sizeof( struct V_300 ) ) ;
V_302 = F_27 ( & V_2 -> V_21 , & V_307 ) ;
if ( V_302 == NULL ) {
V_8 = - V_23 ;
goto V_20;
}
memcpy ( V_302 , F_118 ( V_297 ) , V_297 -> V_305 . V_308 ) ;
F_9 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
goto V_20;
V_20:
F_14 ( V_2 ) ;
return V_8 ;
}
static struct V_312 * F_119 ( char * V_112 , int V_313 , int V_73 )
{
struct V_312 * V_314 = (struct V_312 * ) V_112 ;
F_18 ( V_313 <= V_315 ) ;
V_314 -> V_316 = V_317 ;
V_314 -> V_318 = V_319 ;
V_314 -> V_320 = V_73 ;
V_314 -> V_321 = V_322 ;
V_314 -> V_323 = V_313 ;
return V_314 ;
}
static int F_120 ( const struct V_230 * V_231 , struct V_324 * V_325 ,
struct V_326 * V_327 , void * V_328 )
{
struct V_329 * V_330 = V_328 ;
struct V_331 * V_86 = (struct V_331 * ) V_327 ;
struct V_312 * V_314 ;
int V_313 , V_8 ;
if ( V_86 -> V_332 . V_333 != V_334 ) {
V_8 = - V_262 ;
F_52 ( L_34 ,
V_330 -> V_335 -> V_195 , V_86 -> V_332 . V_333 ,
V_86 -> V_336 . V_337 , V_8 ) ;
return V_8 ;
}
if ( V_86 -> V_336 . V_338 < V_330 -> V_339 ) {
F_11 ( V_340 , L_35 ,
V_86 -> V_336 . V_338 , V_330 -> V_339 ) ;
return 0 ;
}
F_11 ( V_340 , L_36 V_26 L_37 V_26
L_38 , V_86 -> V_336 . V_338 , V_86 -> V_336 . V_337 ,
F_121 ( V_86 -> V_336 . V_337 ) , V_86 -> V_336 . V_341 ,
V_86 -> V_336 . V_342 & V_343 ,
F_12 ( & V_86 -> V_336 . V_344 ) , F_12 ( & V_86 -> V_336 . V_345 ) ,
V_86 -> V_336 . V_346 , F_122 ( & V_86 -> V_336 ) ) ;
V_313 = sizeof( * V_314 ) + F_123 ( & V_86 -> V_336 ) + V_86 -> V_336 . V_346 ;
V_314 = F_119 ( V_330 -> V_347 , V_313 , V_330 -> V_348 ) ;
memcpy ( V_314 + 1 , & V_86 -> V_336 , V_313 - sizeof( * V_314 ) ) ;
V_8 = F_124 ( V_330 -> V_349 , V_314 ) ;
F_11 ( V_340 , L_39 , V_330 -> V_349 , V_313 , V_8 ) ;
return V_8 ;
}
static int F_125 ( void * V_350 )
{
struct V_329 * V_330 = V_350 ;
struct V_351 * V_352 = NULL ;
struct V_324 * V_325 = NULL ;
struct V_312 * V_353 ;
int V_8 ;
F_11 ( V_340 , L_40 ,
V_330 -> V_349 , V_330 -> V_339 ) ;
V_330 -> V_347 = F_107 ( V_315 , V_257 ) ;
if ( ! V_330 -> V_347 ) {
V_8 = - V_17 ;
goto V_20;
}
V_352 = F_126 ( V_330 -> V_335 , V_354 ) ;
if ( V_352 == NULL ) {
V_8 = - V_355 ;
goto V_20;
}
V_8 = F_127 ( NULL , V_352 , & V_325 , NULL , V_356 ,
V_357 ) ;
if ( V_8 ) {
F_52 ( L_41 ,
V_330 -> V_335 -> V_195 , V_8 ) ;
goto V_20;
}
V_8 = F_128 ( NULL , V_325 , V_358 , NULL ) ;
if ( V_8 ) {
F_52 ( L_42 , V_8 ) ;
goto V_20;
}
V_8 = F_129 ( NULL , V_325 , F_120 , V_330 , 0 , 0 ) ;
V_353 = F_119 ( V_330 -> V_347 , sizeof( * V_353 ) , V_330 -> V_348 ) ;
if ( V_353 ) {
V_353 -> V_321 = V_359 ;
F_124 ( V_330 -> V_349 , V_353 ) ;
}
V_20:
F_130 ( V_330 -> V_349 ) ;
if ( V_325 )
F_131 ( NULL , V_325 ) ;
if ( V_352 )
F_132 ( V_352 ) ;
F_109 ( V_330 -> V_347 ) ;
F_109 ( V_330 ) ;
return V_8 ;
}
static int F_133 ( struct V_186 * V_187 ,
struct V_360 * V_361 )
{
struct V_329 * V_330 ;
int V_8 ;
V_330 = F_107 ( sizeof( * V_330 ) , V_257 ) ;
if ( ! V_330 )
return - V_17 ;
V_330 -> V_335 = V_187 ;
V_330 -> V_339 = V_361 -> V_362 ;
V_330 -> V_349 = F_134 ( V_361 -> V_363 ) ;
V_330 -> V_348 = V_361 -> V_364 ;
V_8 = F_51 ( F_135 ( F_125 , V_330 ,
L_43 ) ) ;
if ( ! F_136 ( V_8 ) ) {
F_11 ( V_340 , L_44 ) ;
return 0 ;
}
F_52 ( L_45 , V_8 ) ;
F_109 ( V_330 ) ;
return V_8 ;
}
static int F_137 ( struct V_186 * V_365 , struct V_9 * exp ,
struct V_366 * V_367 )
{
struct V_3 * V_4 = & exp -> V_103 -> V_7 . V_4 ;
struct V_1 * V_2 ;
struct V_366 * V_13 ;
int V_8 ;
V_2 = F_6 ( F_7 ( exp ) ,
& V_368 , V_15 ,
V_369 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_13 = F_27 ( & V_2 -> V_21 , & V_370 ) ;
* V_13 = * V_367 ;
F_9 ( V_2 ) ;
V_4 -> V_371 = - V_372 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
V_4 -> V_371 = V_8 ;
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_138 ( struct V_9 * exp ,
struct V_373 * V_374 )
{
struct V_3 * V_4 = & exp -> V_103 -> V_7 . V_4 ;
int V_8 ;
V_374 -> V_375 = V_4 -> V_376 ;
memcpy ( V_374 -> V_377 , V_378 , strlen ( V_378 ) ) ;
V_8 = V_4 -> V_371 ;
if ( V_8 == V_379 )
V_8 = - V_380 ;
return V_8 ;
}
static int F_139 ( struct V_186 * V_365 , struct V_9 * exp ,
struct V_366 * V_367 )
{
struct V_1 * V_2 ;
struct V_366 * V_381 ;
int V_8 ;
V_2 = F_6 ( F_7 ( exp ) ,
& V_382 , V_15 ,
V_383 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_381 = F_27 ( & V_2 -> V_21 , & V_370 ) ;
* V_381 = * V_367 ;
F_9 ( V_2 ) ;
F_83 ( V_2 ) ;
V_2 -> V_243 = 1 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
F_52 ( L_46 , V_8 ) ;
if ( V_2 -> V_27 ) {
V_381 = F_10 ( & V_2 -> V_21 , & V_370 ) ;
if ( V_381 ) {
* V_367 = * V_381 ;
} else if ( ! V_8 ) {
F_52 ( L_47 ) ;
V_8 = - V_23 ;
}
} else if ( ! V_8 ) {
F_52 ( L_47 ) ;
V_8 = - V_23 ;
}
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_140 ( struct V_9 * exp ,
struct V_40 * V_41 )
{
F_33 ( V_82 ) ;
struct V_1 * V_2 ;
int V_8 , V_83 ;
struct V_384 * V_385 , * V_386 ;
V_385 = V_41 -> V_41 ;
V_83 = F_34 ( exp , & V_41 -> V_48 , & V_82 ,
V_387 , V_388 ) ;
V_83 += F_34 ( exp , & V_41 -> V_194 , & V_82 ,
V_387 , V_388 ) ;
V_2 = F_22 ( F_7 ( exp ) ,
& V_389 ) ;
if ( V_2 == NULL ) {
F_141 ( & V_82 , V_390 , V_83 ) ;
return - V_17 ;
}
V_8 = F_35 ( exp , V_2 , V_391 , & V_82 , V_83 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
F_142 ( V_2 , V_41 ) ;
V_386 = F_27 ( & V_2 -> V_21 , & V_392 ) ;
F_18 ( V_386 ) ;
* V_386 = * V_385 ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_143 ( unsigned int V_393 , struct V_9 * exp , int V_313 ,
void * V_394 , void * V_395 )
{
struct V_186 * V_187 = exp -> V_103 ;
struct V_396 * V_328 = V_394 ;
struct V_163 * V_164 = V_187 -> V_7 . V_4 . V_237 ;
int V_8 ;
if ( ! F_144 ( V_397 ) ) {
F_52 ( L_48 ) ;
return - V_262 ;
}
switch ( V_393 ) {
case V_398 :
V_8 = F_133 ( V_187 , V_394 ) ;
goto V_20;
case V_399 : {
struct V_360 * V_361 = V_394 ;
struct V_400 V_330 = {
. V_401 = V_361 -> V_362 ,
. V_402 = V_361 -> V_363
} ;
V_8 = F_145 ( NULL , exp , strlen ( V_403 ) ,
V_403 , sizeof( V_330 ) , & V_330 ,
NULL ) ;
goto V_20;
}
case V_404 :
V_8 = F_105 ( exp , V_394 ) ;
goto V_20;
case V_405 :
V_8 = F_146 ( exp , V_394 ) ;
if ( V_8 == - V_406 )
V_8 = 0 ;
goto V_20;
case V_407 :
V_8 = F_110 ( exp , V_394 ) ;
goto V_20;
case V_408 :
V_8 = F_115 ( exp , V_394 ) ;
goto V_20;
case V_409 :
V_8 = F_116 ( exp , V_394 ) ;
goto V_20;
case V_410 :
V_8 = F_113 ( exp , V_394 ) ;
goto V_20;
case V_411 :
V_8 = F_117 ( exp , V_394 ) ;
goto V_20;
case V_412 :
V_8 = F_147 ( V_164 , V_328 -> V_413 , 0 ) ;
if ( V_8 < 0 )
goto V_20;
V_8 = 0 ;
goto V_20;
case V_414 :
V_8 = F_148 ( V_164 , V_328 -> V_415 ) ;
goto V_20;
case V_416 :
V_8 = F_138 ( exp , (struct V_373 * ) V_394 ) ;
goto V_20;
case V_417 :
V_8 = F_149 ( V_187 ) ;
goto V_20;
case V_418 : {
struct V_232 V_419 = { 0 } ;
if ( * ( ( T_2 * ) V_328 -> V_420 ) != 0 ) {
V_8 = - V_238 ;
goto V_20;
}
if ( F_150 ( V_328 -> V_421 , F_151 ( V_187 ) ,
F_152 ( V_422 , V_328 -> V_423 ,
sizeof( struct V_375 ) ) ) ) {
V_8 = - V_424 ;
goto V_20;
}
V_8 = F_100 ( NULL , V_187 -> V_425 , & V_419 ,
F_153 ( - V_426 ) ,
0 ) ;
if ( V_8 != 0 )
goto V_20;
if ( F_150 ( V_328 -> V_427 , & V_419 ,
F_152 ( V_422 , V_328 -> V_428 ,
sizeof( V_419 ) ) ) ) {
V_8 = - V_424 ;
goto V_20;
}
V_8 = 0 ;
goto V_20;
}
case V_429 : {
struct V_430 * V_431 = V_394 ;
struct V_366 * V_367 ;
V_367 = F_107 ( sizeof( * V_367 ) , V_257 ) ;
if ( ! V_367 ) {
V_8 = - V_17 ;
goto V_20;
}
F_154 ( V_367 , V_431 ) ;
V_8 = V_366 ( exp , V_367 ) ;
if ( V_8 == 0 ) {
F_154 ( V_431 , V_367 ) ;
V_431 -> V_432 = V_433 ;
V_431 -> V_375 = V_187 -> V_7 . V_4 . V_376 ;
}
F_109 ( V_367 ) ;
goto V_20;
}
case V_434 :
if ( F_150 ( V_395 , F_155 ( exp ) ,
sizeof( * F_155 ( exp ) ) ) ) {
V_8 = - V_424 ;
goto V_20;
}
V_8 = 0 ;
goto V_20;
case V_435 :
V_8 = F_140 ( exp , V_394 ) ;
goto V_20;
default:
F_52 ( L_49 , V_393 ) ;
V_8 = - V_436 ;
goto V_20;
}
V_20:
F_156 ( V_397 ) ;
return V_8 ;
}
static int F_157 ( struct V_9 * exp ,
T_5 V_249 , void * V_251 ,
int V_250 , void * V_437 )
{
struct V_163 * V_164 = F_7 ( exp ) ;
struct V_1 * V_2 ;
char * V_76 ;
int V_8 = - V_262 ;
V_2 = F_22 ( V_164 , & V_438 ) ;
if ( V_2 == NULL )
return - V_17 ;
F_25 ( & V_2 -> V_21 , & V_439 ,
V_54 , V_249 ) ;
F_25 ( & V_2 -> V_21 , & V_440 ,
V_54 , sizeof( T_2 ) ) ;
V_8 = F_23 ( V_2 , V_15 , V_441 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
V_76 = F_27 ( & V_2 -> V_21 , & V_439 ) ;
memcpy ( V_76 , V_251 , V_249 ) ;
V_76 = F_27 ( & V_2 -> V_21 , & V_440 ) ;
memcpy ( V_76 , & V_250 , sizeof( T_2 ) ) ;
F_25 ( & V_2 -> V_21 , & V_442 ,
V_51 , V_250 ) ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 == 0 || V_8 == - V_64 ) {
V_76 = F_10 ( & V_2 -> V_21 , & V_442 ) ;
memcpy ( V_437 , V_76 , V_250 ) ;
if ( F_158 ( V_2 ) ) {
if ( F_159 ( V_256 ) )
F_160 ( V_437 ) ;
}
}
F_14 ( V_2 ) ;
return V_8 ;
}
static void F_161 ( struct V_443 * V_444 )
{
F_162 ( & V_444 -> V_445 ) ;
F_162 ( & V_444 -> V_446 ) ;
F_163 ( & V_444 -> V_447 ) ;
F_163 ( & V_444 -> V_448 ) ;
F_164 ( & V_444 -> V_449 ) ;
F_164 ( & V_444 -> V_450 . V_451 ) ;
F_164 ( & V_444 -> V_450 . V_452 ) ;
F_164 ( & V_444 -> V_453 ) ;
}
static void F_165 ( struct V_454 * V_444 )
{
struct V_443 * V_455 ;
int V_213 ;
F_162 ( & V_444 -> V_456 ) ;
F_162 ( & V_444 -> V_457 ) ;
F_162 ( & V_444 -> V_458 ) ;
F_164 ( & V_444 -> V_459 ) ;
V_455 = F_166 ( V_444 ) ;
for ( V_213 = 0 ; V_213 < V_444 -> V_457 ; V_213 ++ , V_455 = F_167 ( V_455 ) )
F_161 ( V_455 ) ;
}
static void F_168 ( struct V_312 * V_460 )
{
F_169 ( & V_460 -> V_316 ) ;
F_169 ( & V_460 -> V_321 ) ;
F_169 ( & V_460 -> V_323 ) ;
}
static int F_146 ( struct V_9 * exp ,
struct V_461 * V_462 )
{
struct V_163 * V_164 = F_7 ( exp ) ;
T_2 V_463 = V_462 -> V_464 ;
int V_8 = 0 ;
if ( V_462 -> V_465 != V_466 ) {
F_52 ( L_50 , V_462 -> V_465 ) ;
return - V_262 ;
}
F_11 ( V_467 , L_51 , V_462 -> V_468 , V_462 -> V_469 ,
V_462 -> V_470 , V_462 -> V_465 , V_462 -> V_471 ) ;
if ( V_462 -> V_471 & V_472 ) {
V_8 = F_114 ( V_164 ) ;
} else {
V_8 = F_112 ( V_164 , V_463 ) ;
}
return V_8 ;
}
static int F_170 ( int V_313 , void * V_437 )
{
struct V_312 * V_314 = (struct V_312 * ) V_437 ;
struct V_454 * V_473 = (struct V_454 * ) ( V_314 + 1 ) ;
if ( V_313 < sizeof( * V_314 ) + sizeof( * V_473 ) ) {
F_52 ( L_52 , V_313 ,
( int ) ( sizeof( * V_314 ) + sizeof( * V_473 ) ) ) ;
return - V_23 ;
}
if ( V_314 -> V_316 == F_171 ( V_317 ) ) {
F_168 ( V_314 ) ;
F_165 ( V_473 ) ;
} else if ( V_314 -> V_316 != V_317 ) {
F_52 ( L_53 , V_314 -> V_316 , V_317 ) ;
return - V_23 ;
}
F_11 ( V_467 ,
L_54 ,
V_314 -> V_316 , V_314 -> V_318 , V_314 -> V_321 ,
V_314 -> V_323 , V_473 -> V_457 , V_473 -> V_474 ) ;
return F_172 ( V_466 , V_314 ) ;
}
static int F_173 ( T_2 V_328 , void * V_475 )
{
struct V_163 * V_164 = (struct V_163 * ) V_475 ;
T_2 V_463 = V_328 ;
int V_8 ;
F_11 ( V_143 , L_55 ,
V_463 ) ;
V_8 = F_112 ( V_164 , V_463 ) ;
return ( ( V_8 != 0 ) && ( V_8 != - V_406 ) ) ? V_8 : 0 ;
}
static int F_174 ( struct V_163 * V_164 )
{
return F_175 ( V_466 , F_173 ,
( void * ) V_164 ) ;
}
static int F_176 ( const struct V_230 * V_231 ,
struct V_9 * exp ,
T_5 V_249 , void * V_251 ,
T_5 V_250 , void * V_437 ,
struct V_476 * V_477 )
{
struct V_163 * V_164 = F_7 ( exp ) ;
int V_8 ;
if ( F_159 ( V_478 ) ) {
if ( V_250 != sizeof( int ) )
return - V_262 ;
F_67 ( & V_164 -> V_479 ) ;
if ( * ( ( int * ) V_437 ) ) {
V_164 -> V_480 |= V_481 ;
V_164 -> V_482 . V_483 |=
V_481 ;
} else {
V_164 -> V_480 &= ~ V_481 ;
V_164 -> V_482 . V_483 &=
~ V_481 ;
}
F_68 ( & V_164 -> V_479 ) ;
V_8 = F_177 ( V_164 , V_484 , V_15 ,
V_249 , V_251 , V_250 , V_437 , V_477 ) ;
return V_8 ;
}
if ( F_159 ( V_485 ) ) {
F_178 ( exp -> V_103 ) ;
return 0 ;
}
if ( F_159 ( V_486 ) ) {
F_179 ( V_164 ) ;
return 0 ;
}
if ( F_159 ( V_403 ) ) {
V_8 = F_177 ( V_164 , V_484 , V_15 ,
V_249 , V_251 , V_250 , V_437 , V_477 ) ;
return V_8 ;
}
if ( F_159 ( V_487 ) ) {
V_8 = F_170 ( V_250 , V_437 ) ;
return V_8 ;
}
F_52 ( L_56 , ( char * ) V_251 ) ;
return - V_262 ;
}
static int F_180 ( const struct V_230 * V_231 , struct V_9 * exp ,
T_2 V_249 , void * V_251 , T_2 * V_250 , void * V_437 ,
struct V_488 * V_121 )
{
int V_8 = - V_262 ;
if ( F_159 ( V_489 ) ) {
int V_490 , * V_491 ;
if ( * V_250 != sizeof( int ) )
return - V_262 ;
V_490 = * ( int * ) V_437 ;
if ( V_490 > exp -> V_103 -> V_7 . V_4 . V_492 )
exp -> V_103 -> V_7 . V_4 . V_492 = V_490 ;
V_491 = V_437 ;
* V_491 = exp -> V_103 -> V_7 . V_4 . V_492 ;
return 0 ;
} else if ( F_159 ( V_493 ) ) {
int * V_494 ;
if ( * V_250 != sizeof( int ) )
return - V_262 ;
V_494 = V_437 ;
* V_494 = exp -> V_103 -> V_7 . V_4 . V_200 ;
return 0 ;
} else if ( F_159 ( V_495 ) ) {
struct V_163 * V_164 = F_7 ( exp ) ;
struct V_496 * V_328 = V_437 ;
if ( * V_250 != sizeof( * V_328 ) )
return - V_262 ;
* V_328 = V_164 -> V_482 ;
return 0 ;
} else if ( F_159 ( V_497 ) ) {
* ( ( int * ) V_437 ) = 1 ;
return 0 ;
}
V_8 = F_157 ( exp , V_249 , V_251 , * V_250 , V_437 ) ;
return V_8 ;
}
static int F_181 ( struct V_9 * exp , const struct V_10 * V_67 ,
struct V_1 * * V_42 )
{
struct V_1 * V_2 ;
int V_8 ;
* V_42 = NULL ;
V_2 = F_22 ( F_7 ( exp ) , & V_498 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_8 = F_23 ( V_2 , V_15 , V_499 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , V_67 , 0 , 0 , - 1 , 0 ) ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
F_14 ( V_2 ) ;
else
* V_42 = V_2 ;
return V_8 ;
}
static int F_182 ( struct V_186 * V_187 , struct V_163 * V_164 ,
enum V_500 V_501 )
{
int V_8 = 0 ;
F_18 ( V_164 -> V_6 == V_187 ) ;
switch ( V_501 ) {
case V_502 : {
#if 0
rc = obd_notify_observer(obd, obd, OBD_NOTIFY_DISCON, NULL);
#endif
break;
}
case V_503 : {
struct V_3 * V_4 = & V_187 -> V_7 . V_4 ;
if ( V_4 -> V_504 != NULL )
F_183 ( V_4 -> V_504 ) ;
V_8 = F_184 ( V_187 , V_187 , V_505 , NULL ) ;
break;
}
case V_506 : {
struct V_507 * V_508 = V_187 -> V_509 ;
F_185 ( V_508 , V_510 ) ;
break;
}
case V_511 :
V_8 = F_184 ( V_187 , V_187 , V_512 , NULL ) ;
if ( V_8 == 0 )
V_8 = F_174 ( V_164 ) ;
break;
case V_513 :
V_8 = F_184 ( V_187 , V_187 , V_514 , NULL ) ;
break;
case V_515 :
case V_516 :
break;
default:
F_52 ( L_57 , V_501 ) ;
F_74 () ;
}
return V_8 ;
}
int F_82 ( struct V_9 * exp , struct V_10 * V_67 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = & exp -> V_103 -> V_7 . V_4 ;
struct V_517 * V_518 = V_4 -> V_504 ;
return F_186 ( NULL , V_518 , V_67 ) ;
}
static struct V_375 * F_187 ( struct V_9 * exp )
{
struct V_3 * V_4 = & exp -> V_103 -> V_7 . V_4 ;
return & V_4 -> V_376 ;
}
static int F_188 ( struct V_519 * V_520 )
{
if ( V_520 -> V_521 -> V_522 != V_523 )
return 0 ;
if ( V_520 -> V_524 . V_525 . V_526 & V_527 )
return 0 ;
return 1 ;
}
static int F_189 ( struct V_528 * V_529 )
{
if ( V_529 -> V_530 )
V_529 -> V_530 = NULL ;
return 0 ;
}
static int F_190 ( struct V_186 * V_187 )
{
struct V_531 * V_532 = & V_187 -> V_533 ;
struct V_351 * V_352 ;
int V_8 ;
V_8 = F_191 ( NULL , V_187 , V_532 , V_354 , V_187 ,
& V_534 ) ;
if ( V_8 )
return V_8 ;
V_352 = F_192 ( V_532 , V_354 ) ;
F_193 ( V_352 ) ;
F_132 ( V_352 ) ;
return 0 ;
}
static void F_194 ( struct V_186 * V_187 )
{
struct V_351 * V_352 ;
V_352 = F_126 ( V_187 , V_354 ) ;
if ( V_352 )
F_195 ( NULL , V_352 ) ;
}
static int F_196 ( struct V_186 * V_187 , struct V_535 * V_536 )
{
struct V_3 * V_4 = & V_187 -> V_7 . V_4 ;
struct V_537 V_538 = { NULL } ;
int V_8 ;
V_4 -> V_104 = F_107 ( sizeof( * V_4 -> V_104 ) , V_257 ) ;
if ( ! V_4 -> V_104 )
return - V_17 ;
F_197 ( V_4 -> V_104 ) ;
F_198 () ;
V_4 -> V_203 = F_107 ( sizeof( * V_4 -> V_203 ) , V_257 ) ;
if ( ! V_4 -> V_203 ) {
V_8 = - V_17 ;
goto V_539;
}
F_197 ( V_4 -> V_203 ) ;
V_8 = F_199 ( V_187 , V_536 ) ;
if ( V_8 )
goto V_540;
F_200 ( & V_538 ) ;
F_201 ( V_187 , V_538 . V_541 , V_538 . V_542 ) ;
F_202 ( V_187 ) ;
F_203 ( V_187 ) ;
F_204 ( V_187 -> V_509 , F_188 ) ;
V_187 -> V_509 -> V_543 = & V_544 ;
V_8 = F_190 ( V_187 ) ;
if ( V_8 ) {
F_205 ( V_187 ) ;
F_52 ( L_58 ) ;
}
return V_8 ;
V_540:
F_109 ( V_4 -> V_203 ) ;
V_539:
F_109 ( V_4 -> V_104 ) ;
F_206 () ;
return V_8 ;
}
static int F_207 ( struct V_9 * exp , int V_545 ,
int V_546 , int V_547 , int V_548 )
{
struct V_186 * V_187 = exp -> V_103 ;
struct V_3 * V_4 = & V_187 -> V_7 . V_4 ;
if ( V_4 -> V_492 < V_545 )
V_4 -> V_492 = V_545 ;
if ( V_4 -> V_200 < V_546 )
V_4 -> V_200 = V_546 ;
if ( V_4 -> V_549 < V_547 )
V_4 -> V_549 = V_547 ;
if ( V_4 -> V_202 < V_548 )
V_4 -> V_202 = V_548 ;
return 0 ;
}
static int F_208 ( struct V_186 * V_187 , enum V_550 V_551 )
{
switch ( V_551 ) {
case V_552 :
break;
case V_553 :
if ( V_187 -> V_377 -> V_554 <= 1 )
F_209 ( 0 , V_466 ) ;
F_210 ( V_187 ) ;
F_211 ( V_187 ) ;
F_212 ( V_187 ) ;
F_194 ( V_187 ) ;
break;
}
return 0 ;
}
static int F_205 ( struct V_186 * V_187 )
{
struct V_3 * V_4 = & V_187 -> V_7 . V_4 ;
F_109 ( V_4 -> V_104 ) ;
F_109 ( V_4 -> V_203 ) ;
F_206 () ;
return F_213 ( V_187 ) ;
}
static int F_214 ( struct V_186 * V_187 , T_5 V_313 , void * V_112 )
{
struct V_535 * V_555 = V_112 ;
struct V_537 V_538 = { NULL } ;
int V_8 = 0 ;
F_200 ( & V_538 ) ;
switch ( V_555 -> V_556 ) {
default:
V_8 = F_215 ( V_557 , V_538 . V_541 ,
V_555 , V_187 ) ;
if ( V_8 > 0 )
V_8 = 0 ;
break;
}
return V_8 ;
}
static int F_216 ( struct V_9 * exp , const struct V_10 * V_67 ,
T_2 V_74 , struct V_1 * * V_42 )
{
struct V_1 * V_2 ;
int V_8 ;
F_18 ( F_19 ( exp ) ) ;
* V_42 = NULL ;
V_2 = F_22 ( F_7 ( exp ) , & V_46 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_8 = F_23 ( V_2 , V_15 , V_47 ) ;
if ( V_8 ) {
F_24 ( V_2 ) ;
return V_8 ;
}
F_8 ( V_2 , V_67 , V_35 , 0 , V_74 , 0 ) ;
F_25 ( & V_2 -> V_21 , & V_38 , V_51 ,
sizeof( struct V_36 ) ) ;
F_9 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
F_14 ( V_2 ) ;
else
* V_42 = V_2 ;
return V_8 ;
}
static int T_6 F_217 ( void )
{
struct V_537 V_538 = { NULL } ;
F_200 ( & V_538 ) ;
return F_218 ( & V_558 , & V_559 ,
V_560 , NULL ) ;
}
static void F_219 ( void )
{
F_220 ( V_560 ) ;
}
