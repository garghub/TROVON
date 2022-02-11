int F_1 ( struct V_1 * exp , struct V_2 * V_3 ,
const struct V_4 * V_5 , struct V_6 * * V_7 )
{
struct V_8 * V_9 ;
struct V_6 * V_10 ;
V_9 = F_2 ( & V_3 -> V_11 , V_5 ) ;
if ( V_9 == NULL )
return - V_12 ;
V_10 = F_3 ( V_13 ) ;
if ( F_4 ( V_10 ) ) {
F_5 ( V_14 , L_1 ) ;
return F_6 ( V_10 ) ;
} else {
V_10 -> V_15 = * V_9 ;
* V_7 = V_10 ;
return 0 ;
}
}
static inline int F_7 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = & V_3 -> V_18 -> V_19 -> V_20 . V_17 ;
int V_21 ;
V_21 = F_8 ( V_17 ) ;
if ( V_21 != 0 )
return V_21 ;
V_21 = F_9 ( V_3 ) ;
F_10 ( V_17 ) ;
return V_21 ;
}
static int F_11 ( struct V_22 * V_23 , struct V_24 * V_25 ,
struct V_6 * * V_26 , int V_27 , int V_28 )
{
struct V_2 * V_3 ;
struct V_29 * V_30 ;
int V_21 ;
V_3 = F_12 ( V_23 , & V_31 ,
V_32 , V_33 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_13 ( V_3 , NULL , NULL , 0 , 0 , - 1 , 0 ) ;
F_14 ( V_3 -> V_35 , V_28 ) ;
V_3 -> V_36 = V_27 ;
F_15 ( V_3 ) ;
V_21 = F_9 ( V_3 ) ;
if ( V_21 )
GOTO ( V_37 , V_21 ) ;
V_30 = F_2 ( & V_3 -> V_11 , & V_38 ) ;
if ( V_30 == NULL )
GOTO ( V_37 , V_21 = - V_12 ) ;
if ( V_30 -> V_39 & V_40 ) {
V_21 = F_1 ( NULL , V_3 , & V_41 , V_26 ) ;
if ( V_21 )
GOTO ( V_37 , V_21 ) ;
}
* V_25 = V_30 -> V_42 ;
F_5 ( V_43 ,
L_2 V_44 L_3 V_45 L_4 ,
F_16 ( V_25 ) ,
F_17 ( V_3 -> V_46 ) ) ;
V_37:
F_18 ( V_3 ) ;
return V_21 ;
}
int F_19 ( struct V_1 * exp , struct V_24 * V_25 ,
struct V_6 * * V_26 )
{
return F_11 ( F_20 ( exp ) , V_25 , V_26 ,
V_47 , 0 ) ;
}
static int F_21 ( struct V_1 * exp ,
struct V_2 * V_3 )
{
struct V_48 * V_49 = & V_3 -> V_11 ;
struct V_29 * V_30 ;
void * V_50 ;
int V_21 ;
V_21 = F_9 ( V_3 ) ;
if ( V_21 != 0 )
return V_21 ;
V_30 = F_2 ( V_49 , & V_38 ) ;
if ( V_30 == NULL )
return - V_12 ;
F_5 ( V_43 , L_5 , V_30 -> V_51 ) ;
if ( V_30 -> V_52 != 0 ) {
F_22 ( exp , V_30 ) ;
V_50 = F_23 ( V_49 , & V_53 ,
V_30 -> V_52 ) ;
if ( V_50 == NULL )
return - V_12 ;
}
if ( V_30 -> V_39 & V_54 ) {
struct V_55 * V_56 ;
F_24 ( F_25 ( exp ) ) ;
V_56 = F_26 ( V_49 , & V_57 ,
V_58 ) ;
if ( V_56 == NULL )
return - V_12 ;
}
if ( V_30 -> V_39 & V_40 ) {
struct V_8 * V_9 ;
V_9 = F_2 ( V_49 , & V_41 ) ;
if ( V_9 == NULL )
return - V_12 ;
}
return 0 ;
}
int F_27 ( struct V_1 * exp , struct V_59 * V_60 ,
struct V_2 * * V_61 )
{
struct V_2 * V_3 ;
int V_21 ;
if ( V_60 -> V_62 & V_63 ) {
V_60 -> V_64 = 0 ;
return 0 ;
}
* V_61 = NULL ;
V_3 = F_28 ( F_20 ( exp ) , & V_65 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_29 ( V_3 , & V_41 , V_60 -> V_66 ) ;
V_21 = F_30 ( V_3 , V_32 , V_67 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
F_13 ( V_3 , & V_60 -> V_68 , V_60 -> V_66 ,
V_60 -> V_69 , V_60 -> V_70 , - 1 , 0 ) ;
F_32 ( & V_3 -> V_11 , & V_53 , V_71 ,
V_60 -> V_70 ) ;
if ( V_60 -> V_69 & V_54 ) {
F_24 ( F_25 ( exp ) ) ;
F_32 ( & V_3 -> V_11 , & V_57 , V_71 ,
sizeof( struct V_55 ) ) ;
}
F_15 ( V_3 ) ;
V_21 = F_21 ( exp , V_3 ) ;
if ( V_21 )
F_18 ( V_3 ) ;
else
* V_61 = V_3 ;
return V_21 ;
}
int F_33 ( struct V_1 * exp , struct V_59 * V_60 ,
struct V_2 * * V_61 )
{
struct V_2 * V_3 ;
int V_21 ;
* V_61 = NULL ;
V_3 = F_28 ( F_20 ( exp ) ,
& V_72 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_29 ( V_3 , & V_41 , V_60 -> V_66 ) ;
F_32 ( & V_3 -> V_11 , & V_73 , V_74 ,
V_60 -> V_75 + 1 ) ;
V_21 = F_30 ( V_3 , V_32 , V_76 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
F_13 ( V_3 , & V_60 -> V_68 , V_60 -> V_66 ,
V_60 -> V_69 , V_60 -> V_70 ,
V_60 -> V_77 [ 0 ] , 0 ) ;
if ( V_60 -> V_78 ) {
char * V_79 = F_34 ( & V_3 -> V_11 , & V_73 ) ;
F_24 ( F_35 ( V_60 -> V_78 , V_60 -> V_75 ) ==
V_60 -> V_75 ) ;
memcpy ( V_79 , V_60 -> V_78 , V_60 -> V_75 ) ;
}
F_32 ( & V_3 -> V_11 , & V_53 , V_71 ,
V_60 -> V_70 ) ;
F_15 ( V_3 ) ;
V_21 = F_21 ( exp , V_3 ) ;
if ( V_21 )
F_18 ( V_3 ) ;
else
* V_61 = V_3 ;
return V_21 ;
}
static int F_36 ( struct V_1 * exp ,
const struct V_24 * V_80 ,
const struct V_24 * V_81 ,
struct V_2 * * V_61 )
{
struct V_2 * V_3 ;
int V_21 ;
* V_61 = NULL ;
V_3 = F_12 ( F_20 ( exp ) ,
& V_82 , V_32 ,
V_83 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_37 ( V_3 , V_80 , V_81 , 0 ) ;
F_15 ( V_3 ) ;
V_21 = F_9 ( V_3 ) ;
if ( V_21 && V_21 != - V_84 )
F_18 ( V_3 ) ;
else
* V_61 = V_3 ;
return V_21 ;
}
static int F_38 ( struct V_1 * exp , const struct V_85 * V_86 ,
const struct V_24 * V_87 ,
struct V_6 * V_7 , int V_88 , T_1 V_39 ,
const char * V_89 , const char * V_90 ,
int V_91 , int V_92 , int V_93 ,
T_2 V_94 , struct V_2 * * V_61 )
{
struct V_2 * V_3 ;
int V_95 = 0 ;
char * V_96 ;
int V_21 ;
* V_61 = NULL ;
V_3 = F_28 ( F_20 ( exp ) , V_86 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_29 ( V_3 , & V_41 , V_7 ) ;
if ( V_89 ) {
V_95 = strlen ( V_89 ) + 1 ;
F_32 ( & V_3 -> V_11 , & V_73 , V_74 ,
V_95 ) ;
}
if ( V_91 ) {
F_24 ( V_90 ) ;
F_32 ( & V_3 -> V_11 , & V_97 , V_74 ,
V_91 ) ;
}
if ( V_88 == V_98 && F_39 ( V_87 ) &&
exp -> V_99 . V_100 & V_101 ) {
F_40 ( V_102 ) ;
int V_103 ;
if ( V_91 == 0 )
F_32 ( & V_3 -> V_11 , & V_97 ,
V_74 , 0 ) ;
V_103 = F_41 ( exp , V_87 ,
& V_102 , V_104 ,
V_101 ) ;
V_21 = F_42 ( exp , V_3 , V_98 , & V_102 , V_103 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
} else {
V_21 = F_30 ( V_3 , V_32 , V_88 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
}
if ( V_88 == V_98 ) {
struct V_105 * V_106 ;
F_43 ( sizeof( struct V_105 ) ==
sizeof( struct V_107 ) ) ;
V_106 = F_34 ( & V_3 -> V_11 , & V_108 ) ;
V_106 -> V_109 = V_110 ;
V_106 -> V_111 = F_44 ( & V_112 , F_45 () ) ;
V_106 -> V_113 = F_46 ( & V_112 , F_47 () ) ;
V_106 -> V_114 = F_48 () ;
V_106 -> V_115 = V_94 ;
V_106 -> V_116 = - 1 ;
V_106 -> V_117 = * V_87 ;
V_106 -> V_118 = V_39 | V_119 ;
V_106 -> V_120 = F_49 () ;
V_106 -> V_121 = V_92 ;
V_106 -> V_122 = V_93 ;
F_50 ( V_3 , & V_41 , V_7 ) ;
} else {
F_13 ( V_3 , V_87 , V_7 , V_39 , V_92 , V_94 , V_93 ) ;
}
if ( V_89 ) {
V_96 = F_34 ( & V_3 -> V_11 , & V_73 ) ;
memcpy ( V_96 , V_89 , V_95 ) ;
}
if ( V_91 ) {
V_96 = F_34 ( & V_3 -> V_11 , & V_97 ) ;
memcpy ( V_96 , V_90 , V_91 ) ;
}
if ( F_51 ( & V_3 -> V_11 , & V_97 , V_71 ) )
F_32 ( & V_3 -> V_11 , & V_97 ,
V_71 , V_92 ) ;
F_15 ( V_3 ) ;
if ( V_88 == V_98 )
F_52 ( exp -> V_123 -> V_20 . V_17 . V_124 , NULL ) ;
V_21 = F_9 ( V_3 ) ;
if ( V_88 == V_98 )
F_53 ( exp -> V_123 -> V_20 . V_17 . V_124 , NULL ) ;
if ( V_21 )
F_18 ( V_3 ) ;
else
* V_61 = V_3 ;
return V_21 ;
}
int F_54 ( struct V_1 * exp , const struct V_24 * V_87 ,
struct V_6 * V_7 , T_1 V_39 , const char * V_89 ,
const char * V_90 , int V_91 , int V_92 ,
int V_93 , T_2 V_94 , struct V_2 * * V_61 )
{
return F_38 ( exp , & V_125 ,
V_87 , V_7 , V_98 , V_39 , V_89 ,
V_90 , V_91 , V_92 , V_93 ,
V_94 , V_61 ) ;
}
int F_55 ( struct V_1 * exp , const struct V_24 * V_87 ,
struct V_6 * V_7 , T_1 V_39 , const char * V_89 ,
const char * V_90 , int V_91 , int V_92 ,
int V_93 , struct V_2 * * V_61 )
{
return F_38 ( exp , & V_126 ,
V_87 , V_7 , V_127 , V_39 , V_89 ,
V_90 , V_91 , V_92 , V_93 ,
- 1 , V_61 ) ;
}
static int F_56 ( struct V_2 * V_3 , struct V_128 * V_129 )
{
struct V_48 * V_49 = & V_3 -> V_11 ;
struct V_29 * V_30 = V_129 -> V_30 ;
struct V_130 * V_131 ;
void * V_132 ;
int V_21 ;
if ( ! V_30 -> V_133 )
return 0 ;
V_132 = F_23 ( V_49 , & V_57 , V_30 -> V_133 ) ;
if ( ! V_132 )
return - V_12 ;
V_131 = F_57 ( & V_112 , V_132 , V_30 -> V_133 ) ;
if ( F_4 ( V_131 ) ) {
V_21 = F_6 ( V_131 ) ;
F_58 ( L_6 , V_21 ) ;
return V_21 ;
}
V_21 = F_59 ( V_131 ) ;
if ( V_21 ) {
F_58 ( L_7 , V_21 ) ;
F_60 ( V_131 ) ;
return V_21 ;
}
V_129 -> V_130 = V_131 ;
return 0 ;
}
int F_61 ( struct V_1 * exp , struct V_2 * V_3 ,
struct V_1 * V_134 , struct V_1 * V_135 ,
struct V_128 * V_129 )
{
struct V_48 * V_49 = & V_3 -> V_11 ;
int V_21 ;
F_24 ( V_129 ) ;
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
V_129 -> V_30 = F_2 ( V_49 , & V_38 ) ;
F_24 ( V_129 -> V_30 != NULL ) ;
if ( V_129 -> V_30 -> V_39 & V_136 ) {
int V_137 ;
struct V_138 * V_139 ;
if ( ! F_62 ( V_129 -> V_30 -> V_51 ) ) {
F_5 ( V_14 , L_8
L_9 ) ;
GOTO ( V_37 , V_21 = - V_12 ) ;
}
if ( V_129 -> V_30 -> V_52 == 0 ) {
F_5 ( V_14 , L_10
L_11 ) ;
GOTO ( V_37 , V_21 = - V_12 ) ;
}
V_137 = V_129 -> V_30 -> V_52 ;
V_139 = F_23 ( V_49 , & V_53 , V_137 ) ;
if ( ! V_139 )
GOTO ( V_37 , V_21 = - V_12 ) ;
V_21 = F_63 ( V_134 , & V_129 -> V_140 , V_139 , V_137 ) ;
if ( V_21 < 0 )
GOTO ( V_37 , V_21 ) ;
if ( V_21 < sizeof( * V_129 -> V_140 ) ) {
F_5 ( V_14 , L_12
L_13 ,
V_21 , ( int ) sizeof( * V_129 -> V_140 ) ) ;
GOTO ( V_37 , V_21 = - V_12 ) ;
}
} else if ( V_129 -> V_30 -> V_39 & V_141 ) {
int V_142 ;
struct V_138 * V_143 ;
if( ! F_64 ( V_129 -> V_30 -> V_51 ) ) {
F_5 ( V_14 , L_14
L_15 ) ;
GOTO ( V_37 , V_21 = - V_12 ) ;
}
if ( V_129 -> V_30 -> V_52 == 0 ) {
F_5 ( V_14 , L_16
L_11 ) ;
return - V_12 ;
}
if ( V_129 -> V_30 -> V_39 & V_144 ) {
V_142 = V_129 -> V_30 -> V_52 ;
V_143 = F_23 ( V_49 , & V_53 ,
V_142 ) ;
if ( ! V_143 )
GOTO ( V_37 , V_21 = - V_12 ) ;
V_21 = F_63 ( V_135 , ( void * ) & V_129 -> V_145 , V_143 ,
V_142 ) ;
if ( V_21 < 0 )
GOTO ( V_37 , V_21 ) ;
if ( V_21 < sizeof( * V_129 -> V_145 ) ) {
F_5 ( V_14 , L_17
L_18 ,
V_21 , ( int ) sizeof( * V_129 -> V_145 ) ) ;
GOTO ( V_37 , V_21 = - V_12 ) ;
}
}
}
V_21 = 0 ;
if ( V_129 -> V_30 -> V_39 & V_54 ) {
F_24 ( F_25 ( exp ) ) ;
V_129 -> V_146 = F_26 ( V_49 , & V_57 ,
V_58 ) ;
if ( ! V_129 -> V_146 )
GOTO ( V_37 , V_21 = - V_12 ) ;
}
else if ( V_129 -> V_30 -> V_39 & V_147 ) {
if ( V_129 -> V_30 -> V_133 ) {
V_21 = F_56 ( V_3 , V_129 ) ;
if ( V_21 )
GOTO ( V_37 , V_21 ) ;
#ifdef F_65
} else {
V_129 -> V_130 = NULL ;
#endif
}
}
if ( V_129 -> V_30 -> V_39 & V_40 ) {
struct V_6 * V_7 = NULL ;
V_21 = F_1 ( NULL , V_3 , & V_41 , & V_7 ) ;
if ( V_21 )
GOTO ( V_37 , V_21 ) ;
V_129 -> V_148 = V_7 ;
}
if ( V_129 -> V_30 -> V_39 & V_149 ) {
struct V_6 * V_7 = NULL ;
V_21 = F_1 ( NULL , V_3 , & V_150 , & V_7 ) ;
if ( V_21 )
GOTO ( V_37 , V_21 ) ;
V_129 -> V_151 = V_7 ;
}
V_37:
if ( V_21 ) {
if ( V_129 -> V_151 ) {
F_66 ( V_129 -> V_151 ) ;
V_129 -> V_151 = NULL ;
}
if ( V_129 -> V_148 ) {
F_66 ( V_129 -> V_148 ) ;
V_129 -> V_148 = NULL ;
}
#ifdef F_65
F_60 ( V_129 -> V_130 ) ;
#endif
if ( V_129 -> V_140 )
F_67 ( V_134 , & V_129 -> V_140 ) ;
}
return V_21 ;
}
int F_68 ( struct V_1 * exp , struct V_128 * V_129 )
{
return 0 ;
}
void F_69 ( struct V_2 * V_3 )
{
struct V_152 * V_153 = V_3 -> V_154 ;
struct V_2 * V_155 ;
struct V_156 * V_157 ;
struct V_158 V_159 ;
struct V_29 * V_30 ;
if ( V_153 == NULL ) {
F_70 ( V_160 , V_3 ,
L_19 ) ;
return;
}
V_30 = F_2 ( & V_3 -> V_11 , & V_38 ) ;
F_24 ( V_30 != NULL ) ;
V_157 = V_153 -> V_161 ;
if ( V_157 != NULL ) {
struct V_158 * V_162 ;
F_24 ( V_157 -> V_163 == V_164 ) ;
V_162 = & V_157 -> V_165 ;
F_5 ( V_166 , L_20 V_167 L_21 V_167 L_4 ,
V_162 -> V_168 , V_30 -> V_169 . V_168 ) ;
V_159 = * V_162 ;
* V_162 = V_30 -> V_169 ;
}
V_155 = V_153 -> V_170 ;
if ( V_155 != NULL ) {
T_2 V_171 = F_71 ( V_155 -> V_35 ) ;
struct V_172 * V_173 ;
F_24 ( V_171 == V_174 || V_171 == V_175 ) ;
V_173 = F_34 ( & V_155 -> V_11 ,
& V_176 ) ;
F_24 ( V_173 ) ;
if ( V_157 != NULL )
F_24 ( ! memcmp ( & V_159 , & V_173 -> V_169 , sizeof( V_159 ) ) ) ;
F_70 ( V_166 , V_155 , L_22 ) ;
V_173 -> V_169 = V_30 -> V_169 ;
}
}
void F_72 ( struct V_2 * V_3 )
{
struct V_152 * V_153 = V_3 -> V_154 ;
if ( V_153 == NULL )
return;
F_73 ( V_3 ) ;
F_74 ( & V_3 -> V_177 ) ;
V_3 -> V_178 = 1 ;
F_75 ( & V_3 -> V_177 ) ;
V_3 -> V_154 = NULL ;
F_76 ( V_153 ) ;
}
int F_77 ( struct V_1 * exp ,
struct V_156 * V_157 ,
struct V_179 * V_180 )
{
struct V_152 * V_153 ;
struct V_181 * V_106 ;
struct V_29 * V_30 ;
struct V_2 * V_182 = V_180 -> V_183 . V_184 . V_185 ;
struct V_22 * V_23 = V_182 -> V_18 ;
if ( ! V_182 -> V_186 )
return 0 ;
V_106 = F_34 ( & V_182 -> V_11 , & V_108 ) ;
V_30 = F_2 ( & V_182 -> V_11 , & V_38 ) ;
F_24 ( V_106 != NULL ) ;
F_24 ( V_30 != NULL ) ;
if ( V_157 && V_23 -> V_187 ) {
V_153 = F_78 () ;
if ( V_153 == NULL ) {
F_70 ( V_160 , V_182 ,
L_23 ) ;
return 0 ;
}
F_79 ( V_153 ) ;
F_79 ( V_153 ) ;
F_74 ( & V_182 -> V_177 ) ;
V_157 -> V_188 = V_153 ;
V_153 -> V_161 = V_157 ;
V_153 -> V_189 = F_80 ( V_180 , V_190 ) ||
F_80 ( V_180 , V_191 ) ;
V_153 -> V_192 = V_182 ;
V_182 -> V_154 = V_153 ;
V_182 -> V_193 = F_72 ;
F_75 ( & V_182 -> V_177 ) ;
}
V_106 -> V_194 = V_30 -> V_42 ;
V_106 -> V_195 = V_30 -> V_196 ;
V_106 -> V_197 . V_168 = V_30 -> V_169 . V_168 ;
V_182 -> V_198 = F_69 ;
if ( ! F_39 ( & V_30 -> V_42 ) ) {
F_70 ( V_160 , V_182 , L_24
L_25 ) ;
F_81 () ;
}
F_70 ( V_199 , V_182 , L_26 ) ;
return 0 ;
}
static void F_82 ( struct V_152 * V_153 )
{
int V_200 = 0 ;
if ( V_153 -> V_189 == 0 &&
F_83 ( V_153 -> V_192 -> V_18 ) )
V_200 = 1 ;
F_24 ( V_153 -> V_192 -> V_186 == 0 ) ;
F_70 ( V_199 , V_153 -> V_192 , L_27 ) ;
F_84 ( V_153 -> V_192 , V_200 ) ;
if ( V_153 -> V_170 )
F_84 ( V_153 -> V_170 , V_200 ) ;
}
int F_85 ( struct V_1 * exp ,
struct V_156 * V_157 )
{
struct V_152 * V_153 = V_157 -> V_188 ;
if ( V_153 == NULL )
return 0 ;
F_24 ( V_153 != V_201 ) ;
F_24 ( V_153 -> V_192 != NULL ) ;
F_82 ( V_153 ) ;
V_153 -> V_161 = NULL ;
V_157 -> V_188 = NULL ;
F_76 ( V_153 ) ;
return 0 ;
}
static void F_86 ( struct V_2 * V_3 ,
struct V_59 * V_60 , int V_21 ) {
struct V_29 * V_202 ;
struct V_172 * V_173 ;
if ( V_3 && V_21 == - V_203 ) {
V_202 = F_2 ( & V_3 -> V_11 , & V_38 ) ;
V_173 = F_34 ( & V_3 -> V_11 , & V_176 ) ;
V_173 -> V_93 |= V_204 ;
if ( V_202 -> V_39 & V_205 )
V_60 -> V_62 |= V_206 ;
}
}
int F_87 ( struct V_1 * exp , struct V_59 * V_60 ,
struct V_152 * V_153 , struct V_2 * * V_61 )
{
struct V_207 * V_208 = F_88 ( exp ) ;
struct V_2 * V_3 ;
struct V_85 * V_209 ;
int V_21 ;
int V_210 = 0 ;
V_209 = & V_211 ;
if ( V_60 -> V_212 & V_213 ) {
V_209 = & V_214 ;
V_21 = F_89 ( exp , & V_60 -> V_215 , V_60 ) ;
if ( V_21 < 0 ) {
F_58 ( L_28 V_44 L_29 ,
V_208 -> V_216 , F_16 ( & V_60 -> V_68 ) , V_21 ) ;
V_210 = V_21 ;
}
}
* V_61 = NULL ;
V_3 = F_28 ( F_20 ( exp ) , V_209 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_29 ( V_3 , & V_41 , V_60 -> V_66 ) ;
V_21 = F_30 ( V_3 , V_32 , V_174 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
V_3 -> V_217 = V_218 ;
F_90 ( V_3 ) ;
if ( F_91 ( V_153 != NULL ) ) {
F_92 ( V_153 -> V_192 != NULL &&
V_153 -> V_192 -> V_219 != V_220 ,
L_30 , V_153 -> V_192 ) ;
V_153 -> V_170 = V_3 ;
F_70 ( V_166 , V_153 -> V_192 , L_31 ) ;
F_74 ( & V_153 -> V_192 -> V_177 ) ;
V_153 -> V_192 -> V_186 = 0 ;
F_75 ( & V_153 -> V_192 -> V_177 ) ;
} else {
F_5 ( V_166 , L_32 ) ;
}
F_93 ( V_3 , V_60 ) ;
F_32 ( & V_3 -> V_11 , & V_53 , V_71 ,
V_208 -> V_20 . V_17 . V_221 ) ;
F_32 ( & V_3 -> V_11 , & V_222 , V_71 ,
V_208 -> V_20 . V_17 . V_223 ) ;
F_15 ( V_3 ) ;
F_52 ( V_208 -> V_20 . V_17 . V_224 , NULL ) ;
V_21 = F_9 ( V_3 ) ;
F_53 ( V_208 -> V_20 . V_17 . V_224 , NULL ) ;
if ( V_3 -> V_46 == NULL ) {
F_5 ( V_199 , L_33 , V_3 ,
V_3 -> V_225 ) ;
if ( V_21 == 0 )
V_21 = V_3 -> V_225 ? : - V_226 ;
} else if ( V_21 == 0 || V_21 == - V_203 ) {
struct V_29 * V_30 ;
V_21 = F_94 ( V_3 -> V_46 ) ;
if ( F_95 ( V_3 -> V_46 ) == V_227 ) {
F_70 ( V_160 , V_3 , L_34
L_35 , V_21 ) ;
if ( V_21 > 0 )
V_21 = - V_21 ;
}
V_30 = F_2 ( & V_3 -> V_11 , & V_38 ) ;
if ( V_30 == NULL )
V_21 = - V_12 ;
} else if ( V_21 == - V_228 ) {
if ( V_153 ) {
F_70 ( V_166 , V_3 , L_36 , V_21 ) ;
F_24 ( V_153 -> V_192 != NULL ) ;
if ( V_153 -> V_192 -> V_178 )
V_21 = 0 ;
}
}
if ( V_153 ) {
if ( V_21 != 0 )
V_153 -> V_170 = NULL ;
F_76 ( V_153 ) ;
}
* V_61 = V_3 ;
F_86 ( V_3 , V_60 , V_21 ) ;
return V_21 < 0 ? V_21 : V_210 ;
}
int F_96 ( struct V_1 * exp , struct V_59 * V_60 ,
struct V_152 * V_153 )
{
struct V_207 * V_208 = F_88 ( exp ) ;
struct V_2 * V_3 ;
int V_21 ;
V_3 = F_28 ( F_20 ( exp ) ,
& V_229 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_29 ( V_3 , & V_41 , V_60 -> V_66 ) ;
V_21 = F_30 ( V_3 , V_32 , V_175 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
if ( V_153 != NULL ) {
F_92 ( V_153 -> V_192 != NULL &&
V_153 -> V_192 -> V_219 != V_220 ,
L_37 , V_153 -> V_192 ) ;
V_153 -> V_170 = V_3 ;
F_70 ( V_166 , V_153 -> V_192 , L_38 ) ;
F_74 ( & V_153 -> V_192 -> V_177 ) ;
V_153 -> V_192 -> V_186 = 0 ;
F_75 ( & V_153 -> V_192 -> V_177 ) ;
}
F_93 ( V_3 , V_60 ) ;
F_15 ( V_3 ) ;
F_52 ( V_208 -> V_20 . V_17 . V_224 , NULL ) ;
V_21 = F_9 ( V_3 ) ;
F_53 ( V_208 -> V_20 . V_17 . V_224 , NULL ) ;
if ( V_21 == - V_228 ) {
if ( V_153 ) {
F_24 ( V_153 -> V_192 != NULL ) ;
if ( V_153 -> V_192 -> V_178 )
V_21 = 0 ;
}
}
if ( V_153 ) {
if ( V_21 != 0 )
V_153 -> V_170 = NULL ;
F_24 ( V_153 -> V_192 != NULL ) ;
F_82 ( V_153 ) ;
F_76 ( V_153 ) ;
}
F_86 ( V_3 , V_60 , V_21 ) ;
F_18 ( V_3 ) ;
return V_21 ;
}
int F_97 ( struct V_1 * exp , struct V_59 * V_60 ,
struct V_230 * * V_231 , struct V_2 * * V_61 )
{
struct V_2 * V_3 ;
struct V_232 * V_233 ;
int V_234 ;
T_3 V_235 ;
int V_236 = 0 ;
struct V_237 V_238 ;
int V_21 ;
* V_61 = NULL ;
F_98 ( & V_235 ) ;
V_239:
V_3 = F_28 ( F_20 ( exp ) , & V_240 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_29 ( V_3 , & V_41 , V_60 -> V_66 ) ;
V_21 = F_30 ( V_3 , V_32 , V_241 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
V_3 -> V_217 = V_218 ;
F_90 ( V_3 ) ;
V_233 = F_99 ( V_3 , V_60 -> V_242 , 1 , V_243 ,
V_244 ) ;
if ( V_233 == NULL ) {
F_31 ( V_3 ) ;
return - V_34 ;
}
for ( V_234 = 0 ; V_234 < V_60 -> V_242 ; V_234 ++ )
F_100 ( V_233 , V_231 [ V_234 ] , 0 , V_245 ) ;
F_101 ( V_3 , V_60 -> V_246 ,
V_245 * V_60 -> V_242 ,
& V_60 -> V_68 , V_60 -> V_66 ) ;
F_15 ( V_3 ) ;
V_21 = F_9 ( V_3 ) ;
if ( V_21 ) {
F_18 ( V_3 ) ;
if ( V_21 != - V_247 )
return V_21 ;
V_236 ++ ;
if ( ! F_102 ( V_236 , & exp -> V_123 -> V_20 . V_17 ) ) {
F_58 ( L_39 ) ;
return - V_226 ;
}
V_238 = F_103 ( F_104 ( V_236 ) , NULL , NULL , NULL ) ;
F_105 ( V_235 , 0 , & V_238 ) ;
goto V_239;
}
V_21 = F_106 ( V_3 , V_3 -> V_248 ,
V_3 -> V_248 -> V_249 ) ;
if ( V_21 < 0 ) {
F_18 ( V_3 ) ;
return V_21 ;
}
if ( V_3 -> V_248 -> V_249 & ~ V_250 ) {
F_58 ( L_40 ,
V_3 -> V_248 -> V_249 ,
V_245 * V_60 -> V_242 ) ;
F_18 ( V_3 ) ;
return - V_12 ;
}
* V_61 = V_3 ;
return 0 ;
}
static int F_107 ( const struct V_251 * V_252 ,
struct V_1 * exp , struct V_253 * V_254 ,
T_4 V_255 , T_2 V_93 )
{
struct V_207 * V_208 = F_88 ( exp ) ;
struct V_2 * V_3 ;
struct V_253 * V_256 ;
struct V_22 * V_23 = NULL ;
int V_21 ;
F_108 ( & V_208 -> V_20 . V_17 . V_257 ) ;
if ( V_208 -> V_20 . V_17 . V_258 )
V_23 = F_109 ( V_208 -> V_20 . V_17 . V_258 ) ;
F_110 ( & V_208 -> V_20 . V_17 . V_257 ) ;
if ( ! V_23 )
return - V_259 ;
V_3 = F_12 ( V_23 , & V_260 ,
V_32 , V_261 ) ;
if ( V_3 == NULL )
GOTO ( V_262 , V_21 = - V_34 ) ;
F_15 ( V_3 ) ;
if ( V_93 & V_263 ) {
V_3 -> V_264 = 1 ;
V_3 -> V_265 = 1 ;
}
V_21 = F_9 ( V_3 ) ;
if ( V_21 ) {
if ( V_23 -> V_266 )
V_21 = V_23 -> V_266 ;
GOTO ( V_37 , V_21 ) ;
}
V_256 = F_2 ( & V_3 -> V_11 , & V_267 ) ;
if ( V_256 == NULL )
GOTO ( V_37 , V_21 = - V_12 ) ;
* V_254 = * V_256 ;
V_37:
F_18 ( V_3 ) ;
V_262:
F_111 ( V_23 ) ;
return V_21 ;
}
static int F_112 ( struct V_1 * exp , struct V_268 * V_269 )
{
T_2 V_270 , V_271 ;
void * V_272 ;
int V_21 ;
if ( V_269 -> V_273 > V_274 )
return - V_275 ;
if ( V_269 -> V_273 < 2 )
return - V_276 ;
V_270 = F_113 ( sizeof( V_277 ) ) + sizeof( * V_269 ) ;
F_114 ( V_272 , V_270 ) ;
if ( V_272 == NULL )
return - V_34 ;
memcpy ( V_272 , V_277 , sizeof( V_277 ) ) ;
memcpy ( V_272 + F_113 ( sizeof( V_277 ) ) , V_269 , sizeof( * V_269 ) ) ;
F_5 ( V_278 , L_41 V_44 L_42 V_45 L_43 ,
F_16 ( & V_269 -> V_279 ) , V_269 -> V_280 , V_269 -> V_281 ) ;
if ( ! F_39 ( & V_269 -> V_279 ) )
GOTO ( V_37 , V_21 = - V_282 ) ;
V_271 = sizeof( * V_269 ) + V_269 -> V_273 ;
V_21 = F_115 ( NULL , exp , V_270 , V_272 , & V_271 , V_269 , NULL ) ;
if ( V_21 != 0 && V_21 != - V_84 )
GOTO ( V_37 , V_21 ) ;
if ( V_271 <= sizeof( * V_269 ) )
GOTO ( V_37 , V_21 = - V_12 ) ;
else if ( V_271 > sizeof( * V_269 ) + V_269 -> V_273 )
GOTO ( V_37 , V_21 = - V_276 ) ;
F_5 ( V_278 , L_41 V_44 L_42 V_45 L_44 ,
F_16 ( & V_269 -> V_279 ) , V_269 -> V_280 , V_269 -> V_281 , V_269 -> V_283 ) ;
V_37:
F_116 ( V_272 , V_270 ) ;
return V_21 ;
}
static int F_117 ( struct V_1 * exp ,
struct V_284 * V_285 )
{
struct V_22 * V_23 = F_20 ( exp ) ;
struct V_284 * V_286 ;
struct V_2 * V_3 ;
int V_21 ;
V_3 = F_12 ( V_23 , & V_287 ,
V_32 , V_288 ) ;
if ( V_3 == NULL )
GOTO ( V_37 , V_21 = - V_34 ) ;
F_13 ( V_3 , NULL , NULL , V_54 , 0 , 0 , 0 ) ;
V_286 = F_34 ( & V_3 -> V_11 , & V_289 ) ;
if ( V_286 == NULL )
GOTO ( V_37 , V_21 = - V_12 ) ;
* V_286 = * V_285 ;
V_286 -> V_290 = F_118 ( V_285 -> V_290 ) ;
F_15 ( V_3 ) ;
V_21 = F_7 ( V_3 ) ;
GOTO ( V_37 , V_21 ) ;
V_37:
F_18 ( V_3 ) ;
return V_21 ;
}
static int F_119 ( struct V_22 * V_23 , T_2 V_291 )
{
T_2 * V_292 ;
struct V_2 * V_3 ;
int V_21 ;
V_3 = F_12 ( V_23 , & V_293 ,
V_32 ,
V_294 ) ;
if ( V_3 == NULL )
GOTO ( V_37 , V_21 = - V_34 ) ;
F_13 ( V_3 , NULL , NULL , V_54 , 0 , 0 , 0 ) ;
V_292 = F_34 ( & V_3 -> V_11 ,
& V_295 ) ;
if ( V_292 == NULL )
GOTO ( V_37 , V_21 = - V_12 ) ;
* V_292 = V_291 ;
F_15 ( V_3 ) ;
V_21 = F_7 ( V_3 ) ;
GOTO ( V_37 , V_21 ) ;
V_37:
F_18 ( V_3 ) ;
return V_21 ;
}
static int F_120 ( struct V_1 * exp ,
struct V_59 * V_60 )
{
struct V_296 * V_297 = V_60 -> V_60 ;
struct V_296 * V_298 ;
struct V_2 * V_3 ;
int V_21 ;
V_3 = F_28 ( F_20 ( exp ) ,
& V_299 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_29 ( V_3 , & V_41 , V_60 -> V_66 ) ;
V_21 = F_30 ( V_3 , V_32 , V_300 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
F_13 ( V_3 , & V_60 -> V_68 , V_60 -> V_66 ,
V_54 , 0 , V_60 -> V_77 [ 0 ] , 0 ) ;
F_15 ( V_3 ) ;
V_21 = F_7 ( V_3 ) ;
if ( V_21 )
GOTO ( V_37 , V_21 ) ;
V_298 = F_2 ( & V_3 -> V_11 ,
& V_301 ) ;
if ( V_298 == NULL )
GOTO ( V_37 , V_21 = - V_12 ) ;
* V_297 = * V_298 ;
V_37:
F_18 ( V_3 ) ;
return V_21 ;
}
static int F_121 ( struct V_22 * V_23 )
{
struct V_2 * V_3 ;
int V_21 ;
V_3 = F_12 ( V_23 , & V_302 ,
V_32 ,
V_303 ) ;
if ( V_3 == NULL )
GOTO ( V_37 , V_21 = - V_34 ) ;
F_13 ( V_3 , NULL , NULL , V_54 , 0 , 0 , 0 ) ;
F_15 ( V_3 ) ;
V_21 = F_7 ( V_3 ) ;
GOTO ( V_37 , V_21 ) ;
V_37:
F_18 ( V_3 ) ;
return V_21 ;
}
static int F_122 ( struct V_1 * exp ,
struct V_59 * V_60 )
{
struct V_304 * V_305 = V_60 -> V_60 ;
struct V_304 * V_306 ;
struct V_2 * V_3 ;
int V_21 ;
V_3 = F_28 ( F_20 ( exp ) ,
& V_307 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_29 ( V_3 , & V_41 , V_60 -> V_66 ) ;
V_21 = F_30 ( V_3 , V_32 , V_308 ) ;
if ( V_21 != 0 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
F_13 ( V_3 , & V_60 -> V_68 , V_60 -> V_66 ,
V_54 , 0 , V_60 -> V_77 [ 0 ] , 0 ) ;
F_15 ( V_3 ) ;
V_21 = F_7 ( V_3 ) ;
if ( V_21 )
GOTO ( V_37 , V_21 ) ;
V_306 = F_2 ( & V_3 -> V_11 , & V_309 ) ;
if ( V_306 == NULL )
GOTO ( V_37 , V_21 = - V_12 ) ;
* V_305 = * V_306 ;
V_37:
F_18 ( V_3 ) ;
return V_21 ;
}
static int F_123 ( struct V_1 * exp ,
struct V_59 * V_60 )
{
struct V_310 * V_311 = V_60 -> V_60 ;
struct V_310 * V_312 ;
struct V_2 * V_3 ;
int V_21 ;
V_3 = F_28 ( F_20 ( exp ) ,
& V_313 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_29 ( V_3 , & V_41 , V_60 -> V_66 ) ;
V_21 = F_30 ( V_3 , V_32 , V_314 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
F_13 ( V_3 , & V_60 -> V_68 , V_60 -> V_66 ,
V_54 , 0 , V_60 -> V_77 [ 0 ] , 0 ) ;
V_312 = F_34 ( & V_3 -> V_11 , & V_315 ) ;
if ( V_312 == NULL )
GOTO ( V_37 , V_21 = - V_12 ) ;
* V_312 = * V_311 ;
F_15 ( V_3 ) ;
V_21 = F_7 ( V_3 ) ;
GOTO ( V_37 , V_21 ) ;
V_37:
F_18 ( V_3 ) ;
return V_21 ;
}
static int F_124 ( struct V_1 * exp ,
struct V_316 * V_317 )
{
struct V_22 * V_23 = F_20 ( exp ) ;
struct V_2 * V_3 ;
struct V_318 * V_319 ;
struct V_320 * V_321 ;
char * V_322 ;
int V_21 ;
V_3 = F_28 ( V_23 , & V_323 ) ;
if ( V_3 == NULL )
GOTO ( V_37 , V_21 = - V_34 ) ;
F_32 ( & V_3 -> V_11 , & V_324 , V_74 ,
V_317 -> V_325 . V_326
* sizeof( struct V_320 ) ) ;
F_32 ( & V_3 -> V_11 , & V_327 , V_74 ,
V_317 -> V_325 . V_328 ) ;
V_21 = F_30 ( V_3 , V_32 , V_329 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
F_13 ( V_3 , NULL , NULL , V_54 , 0 , 0 , 0 ) ;
V_319 = F_34 ( & V_3 -> V_11 , & V_330 ) ;
if ( V_319 == NULL )
GOTO ( V_37 , V_21 = - V_12 ) ;
* V_319 = V_317 -> V_325 ;
V_321 = F_34 ( & V_3 -> V_11 , & V_324 ) ;
if ( V_321 == NULL )
GOTO ( V_37 , V_21 = - V_12 ) ;
memcpy ( V_321 , V_317 -> V_331 ,
V_317 -> V_325 . V_326 * sizeof( struct V_320 ) ) ;
V_322 = F_34 ( & V_3 -> V_11 , & V_327 ) ;
if ( V_322 == NULL )
GOTO ( V_37 , V_21 = - V_12 ) ;
memcpy ( V_322 , F_125 ( V_317 ) , V_317 -> V_325 . V_328 ) ;
F_15 ( V_3 ) ;
V_21 = F_7 ( V_3 ) ;
GOTO ( V_37 , V_21 ) ;
V_37:
F_18 ( V_3 ) ;
return V_21 ;
}
static struct V_332 * F_126 ( char * V_132 , int V_333 , int V_93 )
{
struct V_332 * V_334 = (struct V_332 * ) V_132 ;
F_24 ( V_333 <= V_335 ) ;
V_334 -> V_336 = V_337 ;
V_334 -> V_338 = V_339 ;
V_334 -> V_340 = V_93 ;
V_334 -> V_341 = V_342 ;
V_334 -> V_343 = V_333 ;
return V_334 ;
}
static int F_127 ( const struct V_251 * V_252 , struct V_344 * V_345 ,
struct V_346 * V_347 , void * V_348 )
{
struct V_349 * V_350 = V_348 ;
struct V_351 * V_106 = (struct V_351 * ) V_347 ;
struct V_332 * V_334 ;
int V_333 , V_21 ;
if ( V_106 -> V_352 . V_353 != V_354 ) {
V_21 = - V_282 ;
F_58 ( L_45 ,
V_350 -> V_355 -> V_216 , V_106 -> V_352 . V_353 ,
V_106 -> V_356 . V_357 , V_21 ) ;
return V_21 ;
}
if ( V_106 -> V_356 . V_358 < V_350 -> V_359 ) {
F_5 ( V_360 , L_46 V_45 L_47 V_45 L_4 ,
V_106 -> V_356 . V_358 , V_350 -> V_359 ) ;
return 0 ;
}
F_5 ( V_360 , V_45 L_48 V_45 L_49 V_44 L_50 V_44
L_51 , V_106 -> V_356 . V_358 , V_106 -> V_356 . V_357 ,
F_128 ( V_106 -> V_356 . V_357 ) , V_106 -> V_356 . V_361 ,
V_106 -> V_356 . V_362 & V_363 ,
F_16 ( & V_106 -> V_356 . V_364 ) , F_16 ( & V_106 -> V_356 . V_365 ) ,
V_106 -> V_356 . V_366 , F_129 ( & V_106 -> V_356 ) ) ;
V_333 = sizeof( * V_334 ) + F_130 ( & V_106 -> V_356 ) + V_106 -> V_356 . V_366 ;
V_334 = F_126 ( V_350 -> V_367 , V_333 , V_350 -> V_368 ) ;
memcpy ( V_334 + 1 , & V_106 -> V_356 , V_333 - sizeof( * V_334 ) ) ;
V_21 = F_131 ( V_350 -> V_369 , V_334 ) ;
F_5 ( V_360 , L_52 , V_350 -> V_369 , V_333 , V_21 ) ;
return V_21 ;
}
static int F_132 ( void * V_370 )
{
struct V_349 * V_350 = V_370 ;
struct V_371 * V_372 = NULL ;
struct V_344 * V_345 = NULL ;
struct V_332 * V_373 ;
int V_21 ;
F_5 ( V_360 , L_53 V_45 L_4 ,
V_350 -> V_369 , V_350 -> V_359 ) ;
F_114 ( V_350 -> V_367 , V_335 ) ;
if ( V_350 -> V_367 == NULL )
GOTO ( V_37 , V_21 = - V_34 ) ;
V_372 = F_133 ( V_350 -> V_355 , V_374 ) ;
if ( V_372 == NULL )
GOTO ( V_37 , V_21 = - V_375 ) ;
V_21 = F_134 ( NULL , V_372 , & V_345 , NULL , V_376 ,
V_377 ) ;
if ( V_21 ) {
F_58 ( L_54 ,
V_350 -> V_355 -> V_216 , V_21 ) ;
GOTO ( V_37 , V_21 ) ;
}
V_21 = F_135 ( NULL , V_345 , V_378 , NULL ) ;
if ( V_21 ) {
F_58 ( L_55 , V_21 ) ;
GOTO ( V_37 , V_21 ) ;
}
V_21 = F_136 ( NULL , V_345 , F_127 , V_350 , 0 , 0 ) ;
V_373 = F_126 ( V_350 -> V_367 , sizeof( * V_373 ) , V_350 -> V_368 ) ;
if ( V_373 ) {
V_373 -> V_341 = V_379 ;
F_131 ( V_350 -> V_369 , V_373 ) ;
}
V_37:
F_137 ( V_350 -> V_369 ) ;
if ( V_345 )
F_138 ( NULL , V_345 ) ;
if ( V_372 )
F_139 ( V_372 ) ;
if ( V_350 -> V_367 )
F_116 ( V_350 -> V_367 , V_335 ) ;
F_140 ( V_350 ) ;
return V_21 ;
}
static int F_141 ( struct V_207 * V_208 ,
struct V_380 * V_381 )
{
struct V_349 * V_350 ;
int V_21 ;
F_142 ( V_350 ) ;
if ( ! V_350 )
return - V_34 ;
V_350 -> V_355 = V_208 ;
V_350 -> V_359 = V_381 -> V_382 ;
V_350 -> V_369 = F_143 ( V_381 -> V_383 ) ;
V_350 -> V_368 = V_381 -> V_384 ;
V_21 = F_6 ( F_144 ( F_132 , V_350 ,
L_56 ) ) ;
if ( ! F_145 ( V_21 ) ) {
F_5 ( V_360 , L_57 ) ;
return 0 ;
}
F_58 ( L_58 , V_21 ) ;
F_140 ( V_350 ) ;
return V_21 ;
}
static int F_146 ( struct V_207 * V_385 , struct V_1 * exp ,
struct V_386 * V_387 )
{
struct V_16 * V_17 = & exp -> V_123 -> V_20 . V_17 ;
struct V_2 * V_3 ;
struct V_386 * V_30 ;
int V_21 ;
V_3 = F_12 ( F_20 ( exp ) ,
& V_388 , V_32 ,
V_389 ) ;
if ( V_3 == NULL )
return - V_34 ;
V_30 = F_34 ( & V_3 -> V_11 , & V_390 ) ;
* V_30 = * V_387 ;
F_15 ( V_3 ) ;
V_17 -> V_391 = - V_392 ;
V_21 = F_9 ( V_3 ) ;
if ( V_21 )
V_17 -> V_391 = V_21 ;
F_18 ( V_3 ) ;
return V_21 ;
}
static int F_147 ( struct V_1 * exp ,
struct V_393 * V_394 )
{
struct V_16 * V_17 = & exp -> V_123 -> V_20 . V_17 ;
int V_21 ;
V_394 -> V_395 = V_17 -> V_396 ;
memcpy ( V_394 -> V_397 , V_398 , strlen ( V_398 ) ) ;
V_21 = V_17 -> V_391 ;
if ( V_21 == V_399 )
V_21 = - V_400 ;
return V_21 ;
}
static int F_148 ( struct V_207 * V_385 , struct V_1 * exp ,
struct V_386 * V_387 )
{
struct V_2 * V_3 ;
struct V_386 * V_401 ;
int V_21 ;
V_3 = F_12 ( F_20 ( exp ) ,
& V_402 , V_32 ,
V_403 ) ;
if ( V_3 == NULL )
return - V_34 ;
V_401 = F_34 ( & V_3 -> V_11 , & V_390 ) ;
* V_401 = * V_387 ;
F_15 ( V_3 ) ;
F_90 ( V_3 ) ;
V_3 -> V_264 = 1 ;
V_21 = F_9 ( V_3 ) ;
if ( V_21 )
F_58 ( L_59 , V_21 ) ;
if ( V_3 -> V_46 ) {
V_401 = F_2 ( & V_3 -> V_11 , & V_390 ) ;
if ( V_401 ) {
* V_387 = * V_401 ;
} else if ( ! V_21 ) {
F_58 ( L_60 ) ;
V_21 = - V_12 ;
}
} else if ( ! V_21 ) {
F_58 ( L_60 ) ;
V_21 = - V_12 ;
}
F_18 ( V_3 ) ;
return V_21 ;
}
static int F_149 ( struct V_1 * exp ,
struct V_59 * V_60 )
{
F_40 ( V_102 ) ;
struct V_2 * V_3 ;
int V_21 , V_103 ;
struct V_404 * V_405 , * V_406 ;
V_405 = V_60 -> V_60 ;
V_103 = F_41 ( exp , & V_60 -> V_68 , & V_102 ,
V_407 , V_408 ) ;
V_103 += F_41 ( exp , & V_60 -> V_215 , & V_102 ,
V_407 , V_408 ) ;
V_3 = F_28 ( F_20 ( exp ) ,
& V_409 ) ;
if ( V_3 == NULL ) {
F_150 ( & V_102 , V_410 , V_103 ) ;
return - V_34 ;
}
F_29 ( V_3 , & V_41 , V_60 -> V_66 ) ;
F_29 ( V_3 , & V_150 , V_60 -> V_411 ) ;
V_21 = F_42 ( exp , V_3 , V_412 , & V_102 , V_103 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
F_151 ( V_3 , V_60 ) ;
V_406 = F_34 ( & V_3 -> V_11 , & V_413 ) ;
F_24 ( V_406 ) ;
* V_406 = * V_405 ;
F_15 ( V_3 ) ;
V_21 = F_9 ( V_3 ) ;
if ( V_21 )
GOTO ( V_37 , V_21 ) ;
V_37:
F_18 ( V_3 ) ;
return V_21 ;
}
static int F_152 ( unsigned int V_414 , struct V_1 * exp , int V_333 ,
void * V_415 , void * V_416 )
{
struct V_207 * V_208 = exp -> V_123 ;
struct V_417 * V_348 = V_415 ;
struct V_22 * V_23 = V_208 -> V_20 . V_17 . V_258 ;
struct V_371 * V_372 ;
int V_21 ;
if ( ! F_153 ( V_418 ) ) {
F_58 ( L_61 ) ;
return - V_282 ;
}
switch ( V_414 ) {
case V_419 :
V_21 = F_141 ( V_208 , V_415 ) ;
GOTO ( V_37 , V_21 ) ;
case V_420 : {
struct V_380 * V_381 = V_415 ;
struct V_421 V_350 =
{ . V_422 = V_381 -> V_382 , . V_423 = V_381 -> V_383 } ;
V_21 = F_154 ( NULL , exp , strlen ( V_424 ) ,
V_424 , sizeof( V_350 ) , & V_350 ,
NULL ) ;
GOTO ( V_37 , V_21 ) ;
}
case V_425 :
V_21 = F_112 ( exp , V_415 ) ;
GOTO ( V_37 , V_21 ) ;
case V_426 :
V_21 = F_155 ( exp , V_415 ) ;
if ( V_21 == - V_427 )
V_21 = 0 ;
GOTO ( V_37 , V_21 ) ;
case V_428 :
V_21 = F_117 ( exp , V_415 ) ;
GOTO ( V_37 , V_21 ) ;
case V_429 :
V_21 = F_122 ( exp , V_415 ) ;
GOTO ( V_37 , V_21 ) ;
case V_430 :
V_21 = F_123 ( exp , V_415 ) ;
GOTO ( V_37 , V_21 ) ;
case V_431 :
V_21 = F_120 ( exp , V_415 ) ;
GOTO ( V_37 , V_21 ) ;
case V_432 :
V_21 = F_124 ( exp , V_415 ) ;
GOTO ( V_37 , V_21 ) ;
case V_433 :
V_21 = F_156 ( V_23 , V_348 -> V_434 , 0 ) ;
if ( V_21 < 0 )
GOTO ( V_37 , V_21 ) ;
GOTO ( V_37 , V_21 = 0 ) ;
case V_435 :
V_21 = F_157 ( V_23 , V_348 -> V_436 ) ;
GOTO ( V_37 , V_21 ) ;
case V_437 : {
V_372 = F_133 ( exp -> V_123 , V_438 ) ;
V_21 = F_158 ( NULL , V_372 , V_348 -> V_434 ,
NULL ) ;
F_139 ( V_372 ) ;
GOTO ( V_37 , V_21 ) ;
}
case V_439 :
case V_440 : {
V_372 = F_133 ( V_208 , V_438 ) ;
V_21 = F_159 ( NULL , V_372 , V_414 , V_348 ) ;
F_139 ( V_372 ) ;
GOTO ( V_37 , V_21 ) ;
}
case V_441 :
V_21 = F_147 ( exp , (struct V_393 * ) V_415 ) ;
GOTO ( V_37 , V_21 ) ;
case V_442 :
V_21 = F_160 ( V_208 ) ;
GOTO ( V_37 , V_21 ) ;
case V_443 : {
struct V_253 V_444 = { 0 } ;
if ( * ( ( T_2 * ) V_348 -> V_445 ) != 0 )
GOTO ( V_37 , V_21 = - V_259 ) ;
if ( F_161 ( V_348 -> V_446 , F_162 ( V_208 ) ,
F_163 ( ( int ) V_348 -> V_447 ,
( int ) sizeof( struct V_395 ) ) ) )
GOTO ( V_37 , V_21 = - V_448 ) ;
V_21 = F_107 ( NULL , V_208 -> V_449 , & V_444 ,
F_164 ( - V_450 ) ,
0 ) ;
if ( V_21 != 0 )
GOTO ( V_37 , V_21 ) ;
if ( F_161 ( V_348 -> V_451 , & V_444 ,
F_163 ( ( int ) V_348 -> V_452 ,
( int ) sizeof( V_444 ) ) ) )
GOTO ( V_37 , V_21 = - V_448 ) ;
GOTO ( V_37 , V_21 = 0 ) ;
}
case V_453 : {
struct V_454 * V_455 = V_415 ;
struct V_386 * V_387 ;
F_142 ( V_387 ) ;
if ( V_387 == NULL )
GOTO ( V_37 , V_21 = - V_34 ) ;
F_165 ( V_387 , V_455 ) ;
V_21 = V_386 ( exp , V_387 ) ;
if ( V_21 == 0 ) {
F_165 ( V_455 , V_387 ) ;
V_455 -> V_456 = V_457 ;
V_455 -> V_395 = V_208 -> V_20 . V_17 . V_396 ;
}
F_140 ( V_387 ) ;
GOTO ( V_37 , V_21 ) ;
}
case V_458 :
if ( F_161 ( V_416 , F_166 ( exp ) ,
sizeof( * F_166 ( exp ) ) ) )
GOTO ( V_37 , V_21 = - V_448 ) ;
GOTO ( V_37 , V_21 = 0 ) ;
case V_459 :
V_21 = F_149 ( exp , V_415 ) ;
GOTO ( V_37 , V_21 ) ;
default:
F_58 ( L_62 , V_414 ) ;
GOTO ( V_37 , V_21 = - V_460 ) ;
}
V_37:
F_167 ( V_418 ) ;
return V_21 ;
}
int F_168 ( struct V_1 * exp ,
T_5 V_270 , void * V_272 ,
int V_271 , void * V_461 )
{
struct V_22 * V_23 = F_20 ( exp ) ;
struct V_2 * V_3 ;
char * V_96 ;
int V_21 = - V_282 ;
V_3 = F_28 ( V_23 , & V_462 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_32 ( & V_3 -> V_11 , & V_463 ,
V_74 , V_270 ) ;
F_32 ( & V_3 -> V_11 , & V_464 ,
V_74 , sizeof( T_2 ) ) ;
V_21 = F_30 ( V_3 , V_32 , V_465 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
V_96 = F_34 ( & V_3 -> V_11 , & V_463 ) ;
memcpy ( V_96 , V_272 , V_270 ) ;
V_96 = F_34 ( & V_3 -> V_11 , & V_464 ) ;
memcpy ( V_96 , & V_271 , sizeof( T_2 ) ) ;
F_32 ( & V_3 -> V_11 , & V_466 ,
V_71 , V_271 ) ;
F_15 ( V_3 ) ;
V_21 = F_9 ( V_3 ) ;
if ( V_21 == 0 || V_21 == - V_84 ) {
V_96 = F_2 ( & V_3 -> V_11 , & V_466 ) ;
memcpy ( V_461 , V_96 , V_271 ) ;
if ( F_169 ( V_3 ) ) {
if ( F_170 ( V_277 ) )
F_171 ( V_461 ) ;
}
}
F_18 ( V_3 ) ;
return V_21 ;
}
static void F_172 ( struct V_467 * V_468 )
{
F_173 ( & V_468 -> V_469 ) ;
F_173 ( & V_468 -> V_470 ) ;
F_174 ( & V_468 -> V_471 ) ;
F_174 ( & V_468 -> V_472 ) ;
F_175 ( & V_468 -> V_473 ) ;
F_175 ( & V_468 -> V_474 . V_475 ) ;
F_175 ( & V_468 -> V_474 . V_476 ) ;
F_175 ( & V_468 -> V_477 ) ;
}
static void F_176 ( struct V_478 * V_468 )
{
struct V_467 * V_479 ;
int V_234 ;
F_173 ( & V_468 -> V_480 ) ;
F_173 ( & V_468 -> V_481 ) ;
F_173 ( & V_468 -> V_482 ) ;
F_175 ( & V_468 -> V_483 ) ;
V_479 = F_177 ( V_468 ) ;
for ( V_234 = 0 ; V_234 < V_468 -> V_481 ; V_234 ++ , V_479 = F_178 ( V_479 ) )
F_172 ( V_479 ) ;
}
static void F_179 ( struct V_332 * V_484 )
{
F_180 ( & V_484 -> V_336 ) ;
F_180 ( & V_484 -> V_341 ) ;
F_180 ( & V_484 -> V_343 ) ;
}
static int F_155 ( struct V_1 * exp ,
struct V_485 * V_486 )
{
struct V_22 * V_23 = F_20 ( exp ) ;
T_2 V_487 = V_486 -> V_488 ;
int V_21 = 0 ;
if ( V_486 -> V_489 != V_490 ) {
F_58 ( L_63 , V_486 -> V_489 ) ;
return - V_282 ;
}
F_5 ( V_491 , L_64 , V_486 -> V_492 , V_486 -> V_493 ,
V_486 -> V_494 , V_486 -> V_489 , V_486 -> V_495 ) ;
if ( V_486 -> V_495 & V_496 ) {
V_21 = F_121 ( V_23 ) ;
} else {
V_21 = F_119 ( V_23 , V_487 ) ;
}
return V_21 ;
}
static int F_181 ( int V_333 , void * V_461 )
{
struct V_332 * V_334 = (struct V_332 * ) V_461 ;
struct V_478 * V_497 = (struct V_478 * ) ( V_334 + 1 ) ;
int V_21 ;
if ( V_333 < sizeof( * V_334 ) + sizeof( * V_497 ) ) {
F_58 ( L_65 , V_333 ,
( int ) ( sizeof( * V_334 ) + sizeof( * V_497 ) ) ) ;
return - V_12 ;
}
if ( V_334 -> V_336 == F_182 ( V_337 ) ) {
F_179 ( V_334 ) ;
F_176 ( V_497 ) ;
} else if ( V_334 -> V_336 != V_337 ) {
F_58 ( L_66 , V_334 -> V_336 , V_337 ) ;
return - V_12 ;
}
F_5 ( V_491 , L_67
L_68 ,
V_334 -> V_336 , V_334 -> V_338 , V_334 -> V_341 ,
V_334 -> V_343 , V_497 -> V_481 , V_497 -> V_498 ) ;
V_21 = F_183 ( V_490 , V_334 ) ;
return V_21 ;
}
static int F_184 ( T_2 V_348 , void * V_499 )
{
struct V_22 * V_23 = (struct V_22 * ) V_499 ;
T_2 V_487 = V_348 ;
int V_21 ;
F_5 ( V_166 , L_69 ,
V_487 ) ;
V_21 = F_119 ( V_23 , V_487 ) ;
return ( ( V_21 != 0 ) && ( V_21 != - V_427 ) ) ? V_21 : 0 ;
}
static int F_185 ( struct V_22 * V_23 )
{
return F_186 ( V_490 , F_184 ,
( void * ) V_23 ) ;
}
int F_187 ( const struct V_251 * V_252 ,
struct V_1 * exp ,
T_5 V_270 , void * V_272 ,
T_5 V_271 , void * V_461 ,
struct V_500 * V_501 )
{
struct V_22 * V_23 = F_20 ( exp ) ;
int V_21 ;
if ( F_170 ( V_502 ) ) {
if ( V_271 != sizeof( int ) )
return - V_282 ;
F_74 ( & V_23 -> V_503 ) ;
if ( * ( ( int * ) V_461 ) ) {
V_23 -> V_504 |= V_505 ;
V_23 -> V_506 . V_507 |=
V_505 ;
} else {
V_23 -> V_504 &= ~ V_505 ;
V_23 -> V_506 . V_507 &=
~ V_505 ;
}
F_75 ( & V_23 -> V_503 ) ;
V_21 = F_188 ( V_23 , V_508 , V_32 ,
V_270 , V_272 , V_271 , V_461 , V_501 ) ;
return V_21 ;
}
if ( F_170 ( V_509 ) ) {
F_189 ( exp -> V_123 ) ;
return 0 ;
}
if ( F_170 ( V_510 ) ) {
F_190 ( V_23 ) ;
return 0 ;
}
if ( F_170 ( V_424 ) ) {
V_21 = F_188 ( V_23 , V_508 , V_32 ,
V_270 , V_272 , V_271 , V_461 , V_501 ) ;
return V_21 ;
}
if ( F_170 ( V_511 ) ) {
V_21 = F_181 ( V_271 , V_461 ) ;
return V_21 ;
}
F_58 ( L_70 , ( char * ) V_272 ) ;
return - V_282 ;
}
int F_191 ( const struct V_251 * V_252 , struct V_1 * exp ,
T_2 V_270 , void * V_272 , T_2 * V_271 , void * V_461 ,
struct V_512 * V_140 )
{
int V_21 = - V_282 ;
if ( F_170 ( V_513 ) ) {
int V_514 , * V_515 ;
if ( * V_271 != sizeof( int ) )
return - V_282 ;
V_514 = * ( int * ) V_461 ;
if ( V_514 > exp -> V_123 -> V_20 . V_17 . V_516 )
exp -> V_123 -> V_20 . V_17 . V_516 = V_514 ;
V_515 = V_461 ;
* V_515 = exp -> V_123 -> V_20 . V_17 . V_516 ;
return 0 ;
} else if ( F_170 ( V_517 ) ) {
int * V_518 ;
if ( * V_271 != sizeof( int ) )
return - V_282 ;
V_518 = V_461 ;
* V_518 = exp -> V_123 -> V_20 . V_17 . V_221 ;
return 0 ;
} else if ( F_170 ( V_519 ) ) {
int V_514 , * V_520 ;
if ( * V_271 != sizeof( int ) )
return - V_282 ;
V_514 = * ( int * ) V_461 ;
if ( V_514 > exp -> V_123 -> V_20 . V_17 . V_521 )
exp -> V_123 -> V_20 . V_17 . V_521 = V_514 ;
V_520 = V_461 ;
* V_520 = exp -> V_123 -> V_20 . V_17 . V_521 ;
return 0 ;
} else if ( F_170 ( V_522 ) ) {
int * V_523 ;
if ( * V_271 != sizeof( int ) )
return - V_282 ;
V_523 = V_461 ;
* V_523 =
exp -> V_123 -> V_20 . V_17 . V_223 ;
return 0 ;
} else if ( F_170 ( V_524 ) ) {
struct V_22 * V_23 = F_20 ( exp ) ;
struct V_525 * V_348 = V_461 ;
if ( * V_271 != sizeof( * V_348 ) )
return - V_282 ;
* V_348 = V_23 -> V_506 ;
return 0 ;
} else if ( F_170 ( V_526 ) ) {
* ( ( int * ) V_461 ) = 1 ;
return 0 ;
}
V_21 = F_168 ( exp , V_270 , V_272 , * V_271 , V_461 ) ;
return V_21 ;
}
static int F_192 ( struct V_1 * exp , const struct V_24 * V_87 ,
struct V_6 * V_7 , struct V_156 * V_169 ,
int V_93 )
{
struct V_2 * V_3 ;
struct V_29 * V_30 ;
int V_21 ;
V_3 = F_28 ( F_20 ( exp ) , & V_527 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_29 ( V_3 , & V_41 , V_7 ) ;
V_21 = F_30 ( V_3 , V_32 , V_528 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
F_13 ( V_3 , V_87 , V_7 , 0 , 0 , - 1 , V_93 ) ;
F_15 ( V_3 ) ;
F_52 ( exp -> V_123 -> V_20 . V_17 . V_124 , NULL ) ;
V_21 = F_9 ( V_3 ) ;
F_53 ( exp -> V_123 -> V_20 . V_17 . V_124 , NULL ) ;
if ( V_21 ) {
F_58 ( L_71 , V_21 ) ;
GOTO ( V_529 , V_21 ) ;
}
V_30 = F_2 ( & V_3 -> V_11 , & V_38 ) ;
if ( V_30 == NULL )
GOTO ( V_529 , V_21 = - V_12 ) ;
V_169 -> V_165 = V_30 -> V_169 ;
V_169 -> V_163 = V_164 ;
V_169 -> V_188 = F_78 () ;
if ( V_169 -> V_188 == NULL ) {
F_70 ( V_160 , V_3 , L_72 ) ;
GOTO ( V_529 , V_21 = - V_34 ) ;
}
V_169 -> V_188 -> V_192 = V_3 ;
return 0 ;
V_529:
F_18 ( V_3 ) ;
return V_21 ;
}
static int F_193 ( struct V_1 * exp , struct V_156 * V_169 ,
int V_530 )
{
struct V_2 * V_3 ;
struct V_29 * V_30 ;
int V_21 ;
V_3 = F_12 ( F_20 ( exp ) , & V_531 ,
V_32 , V_532 ) ;
if ( V_3 == NULL )
return - V_34 ;
V_30 = F_34 ( & V_3 -> V_11 , & V_38 ) ;
V_30 -> V_169 = V_169 -> V_165 ;
V_30 -> V_93 = V_530 ;
F_15 ( V_3 ) ;
F_52 ( exp -> V_123 -> V_20 . V_17 . V_124 , NULL ) ;
V_21 = F_9 ( V_3 ) ;
F_53 ( exp -> V_123 -> V_20 . V_17 . V_124 , NULL ) ;
if ( V_21 != 0 )
F_58 ( L_73 , V_21 ) ;
F_18 ( V_3 ) ;
F_18 ( V_169 -> V_188 -> V_192 ) ;
F_76 ( V_169 -> V_188 ) ;
return V_21 ;
}
int F_194 ( struct V_1 * exp , const struct V_24 * V_87 ,
struct V_6 * V_7 , struct V_2 * * V_61 )
{
struct V_2 * V_3 ;
int V_21 ;
* V_61 = NULL ;
V_3 = F_28 ( F_20 ( exp ) , & V_533 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_29 ( V_3 , & V_41 , V_7 ) ;
V_21 = F_30 ( V_3 , V_32 , V_534 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
F_13 ( V_3 , V_87 , V_7 , 0 , 0 , - 1 , 0 ) ;
F_15 ( V_3 ) ;
V_21 = F_9 ( V_3 ) ;
if ( V_21 )
F_18 ( V_3 ) ;
else
* V_61 = V_3 ;
return V_21 ;
}
static int F_195 ( struct V_207 * V_208 , struct V_22 * V_23 ,
enum V_535 V_536 )
{
int V_21 = 0 ;
F_24 ( V_23 -> V_19 == V_208 ) ;
switch ( V_536 ) {
case V_537 : {
#if 0
rc = obd_notify_observer(obd, obd, OBD_NOTIFY_DISCON, NULL);
#endif
break;
}
case V_538 : {
struct V_16 * V_17 = & V_208 -> V_20 . V_17 ;
if ( V_17 -> V_539 != NULL )
F_196 ( V_17 -> V_539 ) ;
V_21 = F_197 ( V_208 , V_208 , V_540 , NULL ) ;
break;
}
case V_541 : {
struct V_542 * V_543 = V_208 -> V_544 ;
F_198 ( V_543 , V_545 ) ;
break;
}
case V_546 :
V_21 = F_197 ( V_208 , V_208 , V_547 , NULL ) ;
if ( V_21 == 0 )
V_21 = F_185 ( V_23 ) ;
break;
case V_548 :
V_21 = F_197 ( V_208 , V_208 , V_549 , NULL ) ;
break;
case V_550 :
case V_551 :
break;
default:
F_58 ( L_74 , V_536 ) ;
F_81 () ;
}
return V_21 ;
}
int F_89 ( struct V_1 * exp , struct V_24 * V_87 ,
struct V_59 * V_60 )
{
struct V_16 * V_17 = & exp -> V_123 -> V_20 . V_17 ;
struct V_552 * V_553 = V_17 -> V_539 ;
return F_199 ( NULL , V_553 , V_87 ) ;
}
struct V_395 * F_200 ( struct V_1 * exp ) {
struct V_16 * V_17 = & exp -> V_123 -> V_20 . V_17 ;
return & V_17 -> V_396 ;
}
static int F_201 ( struct V_554 * V_555 )
{
if ( V_555 -> V_556 -> V_557 != V_558 )
return 0 ;
if ( V_555 -> V_559 . V_560 . V_561 & V_562 )
return 0 ;
return 1 ;
}
static int F_202 ( struct V_563 * V_564 )
{
if ( V_564 -> V_565 )
V_564 -> V_565 = NULL ;
return 0 ;
}
static int F_203 ( struct V_207 * V_208 , struct V_566 * V_567 )
{
struct V_16 * V_17 = & V_208 -> V_20 . V_17 ;
struct V_568 V_569 = { 0 } ;
int V_21 ;
F_114 ( V_17 -> V_124 , sizeof ( * V_17 -> V_124 ) ) ;
if ( ! V_17 -> V_124 )
return - V_34 ;
F_204 ( V_17 -> V_124 ) ;
F_205 () ;
F_114 ( V_17 -> V_224 , sizeof ( * V_17 -> V_224 ) ) ;
if ( ! V_17 -> V_224 )
GOTO ( V_570 , V_21 = - V_34 ) ;
F_204 ( V_17 -> V_224 ) ;
V_21 = F_206 ( V_208 , V_567 ) ;
if ( V_21 )
GOTO ( V_571 , V_21 ) ;
F_207 ( & V_569 ) ;
F_208 ( V_208 , V_569 . V_572 ) ;
F_209 ( V_208 ) ;
F_210 ( V_208 ) ;
F_211 ( V_208 -> V_544 , F_201 ) ;
V_208 -> V_544 -> V_573 = & V_574 ;
V_21 = F_212 ( V_208 , & V_208 -> V_575 , V_208 , NULL ) ;
if ( V_21 ) {
F_213 ( V_208 ) ;
F_58 ( L_75 ) ;
}
return V_21 ;
V_571:
F_116 ( V_17 -> V_224 , sizeof ( * V_17 -> V_224 ) ) ;
V_570:
F_116 ( V_17 -> V_124 , sizeof ( * V_17 -> V_124 ) ) ;
F_214 () ;
return V_21 ;
}
static int F_215 ( struct V_1 * exp , int V_576 ,
int V_577 , int V_578 , int V_579 )
{
struct V_207 * V_208 = exp -> V_123 ;
struct V_16 * V_17 = & V_208 -> V_20 . V_17 ;
if ( V_17 -> V_516 < V_576 )
V_17 -> V_516 = V_576 ;
if ( V_17 -> V_221 < V_577 )
V_17 -> V_221 = V_577 ;
if ( V_17 -> V_521 < V_578 )
V_17 -> V_521 = V_578 ;
if ( V_17 -> V_223 < V_579 )
V_17 -> V_223 = V_579 ;
return 0 ;
}
static int F_216 ( struct V_207 * V_208 , enum V_580 V_581 )
{
int V_21 = 0 ;
switch ( V_581 ) {
case V_582 :
break;
case V_583 :
if ( V_208 -> V_397 -> V_584 <= 1 )
F_217 ( 0 , V_490 ) ;
F_218 ( V_208 ) ;
F_219 ( V_208 ) ;
F_220 ( V_208 ) ;
V_21 = F_221 ( V_208 , 0 ) ;
if ( V_21 != 0 )
F_58 ( L_76 ) ;
break;
}
return V_21 ;
}
static int F_213 ( struct V_207 * V_208 )
{
struct V_16 * V_17 = & V_208 -> V_20 . V_17 ;
F_116 ( V_17 -> V_124 , sizeof ( * V_17 -> V_124 ) ) ;
F_116 ( V_17 -> V_224 , sizeof ( * V_17 -> V_224 ) ) ;
F_214 () ;
return F_222 ( V_208 ) ;
}
static int F_223 ( struct V_207 * V_208 , struct V_585 * V_586 ,
struct V_207 * V_587 , int * V_588 )
{
struct V_371 * V_372 ;
int V_21 ;
F_24 ( V_586 == & V_208 -> V_575 ) ;
V_21 = F_224 ( NULL , V_208 , V_586 , V_374 , V_587 ,
& V_589 ) ;
if ( V_21 )
return V_21 ;
V_372 = F_225 ( V_586 , V_374 ) ;
F_226 ( V_372 ) ;
F_139 ( V_372 ) ;
return 0 ;
}
static int F_227 ( struct V_207 * V_208 , int V_103 )
{
struct V_371 * V_372 ;
V_372 = F_133 ( V_208 , V_374 ) ;
if ( V_372 )
F_228 ( NULL , V_372 ) ;
return 0 ;
}
static int F_229 ( struct V_207 * V_208 , T_5 V_333 , void * V_132 )
{
struct V_566 * V_590 = V_132 ;
struct V_568 V_569 = { 0 } ;
int V_21 = 0 ;
F_207 ( & V_569 ) ;
switch ( V_590 -> V_591 ) {
default:
V_21 = F_230 ( V_592 , V_569 . V_572 ,
V_590 , V_208 ) ;
if ( V_21 > 0 )
V_21 = 0 ;
break;
}
return ( V_21 ) ;
}
int F_231 ( struct V_1 * exp , const struct V_24 * V_87 ,
struct V_6 * V_7 , T_2 V_94 ,
struct V_2 * * V_61 )
{
struct V_2 * V_3 ;
int V_21 ;
F_24 ( F_25 ( exp ) ) ;
* V_61 = NULL ;
V_3 = F_28 ( F_20 ( exp ) , & V_65 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_29 ( V_3 , & V_41 , V_7 ) ;
V_21 = F_30 ( V_3 , V_32 , V_67 ) ;
if ( V_21 ) {
F_31 ( V_3 ) ;
return V_21 ;
}
F_13 ( V_3 , V_87 , V_7 , V_54 , 0 , V_94 , 0 ) ;
F_32 ( & V_3 -> V_11 , & V_57 , V_71 ,
sizeof( struct V_55 ) ) ;
F_15 ( V_3 ) ;
V_21 = F_9 ( V_3 ) ;
if ( V_21 )
F_18 ( V_3 ) ;
else
* V_61 = V_3 ;
return V_21 ;
}
static int F_232 ( const struct V_251 * V_252 ,
struct V_2 * V_3 , void * args ,
int V_593 )
{
struct V_594 * V_595 = args ;
struct V_29 * V_30 = NULL ;
struct V_8 * V_9 ;
if ( V_593 )
GOTO ( V_37 , V_9 = F_233 ( V_593 ) ) ;
V_30 = F_2 ( & V_3 -> V_11 , & V_38 ) ;
if ( V_30 == NULL )
GOTO ( V_37 , V_9 = F_233 ( - V_448 ) ) ;
if ( ( V_30 -> V_39 & V_149 ) == 0 )
GOTO ( V_37 , V_9 = F_233 ( - V_375 ) ) ;
V_9 = F_2 ( & V_3 -> V_11 , & V_150 ) ;
if ( ! V_9 )
GOTO ( V_37 , V_9 = F_233 ( - V_448 ) ) ;
V_37:
V_595 -> V_596 ( V_595 -> V_597 , V_9 ) ;
return 0 ;
}
static int F_234 ( struct V_1 * exp , struct V_6 * V_7 ,
T_6 V_598 )
{
struct V_2 * V_3 ;
struct V_594 * V_595 ;
V_3 = F_12 ( F_20 ( exp ) , & V_65 ,
V_32 , V_67 ) ;
if ( V_3 == NULL )
return - V_34 ;
F_13 ( V_3 , & V_7 -> V_15 . V_599 , V_7 , V_149 , 0 , - 1 , 0 ) ;
F_15 ( V_3 ) ;
F_43 ( sizeof( * V_595 ) <= sizeof( V_3 -> V_600 ) ) ;
V_595 = F_235 ( V_3 ) ;
V_595 -> V_597 = V_7 ;
V_595 -> V_596 = V_598 ;
V_3 -> V_601 = F_232 ;
F_236 ( V_3 , V_602 , - 1 ) ;
return 0 ;
}
int T_7 F_237 ( void )
{
int V_21 ;
struct V_568 V_569 = { 0 } ;
F_207 ( & V_569 ) ;
V_21 = F_238 ( & V_603 , & V_604 , V_569 . V_605 ,
V_606 , NULL ) ;
return V_21 ;
}
static void F_239 ( void )
{
F_240 ( V_606 ) ;
}
