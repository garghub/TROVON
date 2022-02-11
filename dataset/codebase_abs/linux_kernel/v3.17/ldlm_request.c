static void F_1 ( void * V_1 )
{
}
int F_2 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
if ( V_5 -> V_11 == NULL ) {
static unsigned long V_12 = 0 , V_13 = 0 ;
F_3 ( L_1 V_14 L_2
V_15 L_3 ,
V_5 -> V_16 ,
F_4 ( F_5 () ,
V_5 -> V_16 ) ) ;
F_6 ( V_5 , L_1 V_14 L_2
V_15 L_4
L_5 ,
V_5 -> V_16 ,
F_4 ( F_5 () ,
V_5 -> V_16 ) ) ;
if ( F_7 ( F_8 () , V_12 ) ) {
V_13 = V_12 ;
V_12 = F_9 ( 300 ) ;
F_10 ( V_17 ,
F_11 ( V_5 ) ) ;
if ( V_13 == 0 )
F_12 () ;
}
return 0 ;
}
V_10 = V_5 -> V_11 -> V_18 ;
V_8 = V_10 -> V_19 . V_20 . V_21 ;
F_13 ( V_8 , V_3 -> V_22 ) ;
F_14 ( V_5 , L_1 V_14 L_2
V_15 L_6 ,
V_5 -> V_16 ,
F_4 ( F_5 () , V_5 -> V_16 ) ,
F_15 ( V_10 ) , V_8 -> V_23 -> V_24 . V_25 ) ;
return 0 ;
}
int F_16 ( struct V_4 * V_5 )
{
int V_26 = F_17 ( F_18 ( V_5 ) ) ;
if ( V_27 )
return V_28 / 2 ;
V_26 = F_19 ( int , V_29 , V_26 + ( V_26 >> 1 ) ) ;
return F_20 ( V_26 , V_30 ) ;
}
static int F_21 ( struct V_4 * V_5 )
{
long V_31 ;
int V_32 ;
if ( V_5 -> V_33 & ( V_34 | V_35 ) ) {
F_6 ( V_5 , L_7 ) ;
V_32 = - V_36 ;
} else {
V_31 = F_4 ( F_5 () ,
V_5 -> V_16 ) ;
F_6 ( V_5 , L_8
V_15 L_9 , V_31 ) ;
F_22 ( F_18 ( V_5 ) ,
V_31 ) ;
V_32 = 0 ;
}
return V_32 ;
}
int F_23 ( struct V_4 * V_5 , T_1 V_37 , void * V_1 )
{
if ( V_37 == V_38 ) {
F_6 ( V_5 , L_10 ) ;
return 0 ;
}
if ( ! ( V_37 & ( V_39 | V_40 |
V_41 ) ) ) {
F_24 ( & V_5 -> V_42 ) ;
return F_21 ( V_5 ) ;
}
F_6 ( V_5 , L_11
L_12 ) ;
F_25 ( V_5 -> V_43 ) ;
return 0 ;
}
int F_26 ( struct V_4 * V_5 , T_1 V_37 , void * V_1 )
{
struct V_2 V_3 ;
struct V_9 * V_10 ;
struct V_7 * V_8 = NULL ;
struct V_44 V_45 ;
T_2 V_26 ;
int V_46 = 0 ;
if ( V_37 == V_38 ) {
F_6 ( V_5 , L_10 ) ;
goto V_47;
}
if ( ! ( V_37 & ( V_39 | V_40 |
V_41 ) ) ) {
F_24 ( & V_5 -> V_42 ) ;
return 0 ;
}
F_6 ( V_5 , L_11
L_13 ) ;
V_47:
V_10 = F_27 ( V_5 -> V_11 ) ;
if ( V_10 != NULL ) {
V_8 = V_10 -> V_19 . V_20 . V_21 ;
}
V_26 = F_16 ( V_5 ) * 2 ;
V_3 . V_6 = V_5 ;
if ( V_5 -> V_33 & V_48 ) {
F_6 ( V_5 , L_14 ) ;
V_45 = F_28 ( F_1 , & V_3 ) ;
} else {
V_45 = F_29 ( F_30 ( V_26 ) ,
F_2 ,
F_1 , & V_3 ) ;
}
if ( V_8 != NULL ) {
F_31 ( & V_8 -> V_49 ) ;
V_3 . V_22 = V_8 -> V_50 ;
F_32 ( & V_8 -> V_49 ) ;
}
if ( F_33 ( F_11 ( V_5 ) ) &&
F_34 ( V_51 ,
V_52 | V_53 ) ) {
V_5 -> V_33 |= V_54 ;
V_46 = - V_55 ;
} else {
V_46 = F_35 ( V_5 -> V_42 ,
F_36 ( V_5 ) , & V_45 ) ;
}
if ( V_46 ) {
F_6 ( V_5 , L_15 ,
V_46 ) ;
return V_46 ;
}
return F_21 ( V_5 ) ;
}
int F_37 ( struct V_4 * V_5 )
{
int V_56 ;
V_5 -> V_33 |= V_57 ;
V_56 = ( ! V_5 -> V_58 && ! V_5 -> V_59 ) ;
F_38 ( V_5 ) ;
if ( V_56 ) {
struct V_60 V_61 ;
int V_46 ;
F_6 ( V_5 , L_16 ) ;
F_39 ( V_5 , & V_61 ) ;
V_46 = F_40 ( & V_61 , V_62 ) ;
if ( V_46 < 0 )
F_41 ( L_17 , V_46 ) ;
} else {
F_6 ( V_5 , L_18
L_19 ) ;
}
return 0 ;
}
int F_42 ( struct V_4 * V_5 , struct V_63 * V_64 ,
void * V_1 , int V_65 )
{
if ( V_65 == V_66 ) {
return 0 ;
}
F_43 ( V_5 ) ;
if ( V_5 -> V_67 != F_42 ) {
F_38 ( V_5 ) ;
return 0 ;
}
return F_37 ( V_5 ) ;
}
int F_44 ( struct V_4 * V_5 , void * V_68 )
{
return - V_69 ;
}
int F_45 ( struct V_70 * V_71 ,
const struct V_72 * V_73 ,
T_3 type , T_4 * V_74 ,
T_5 V_75 , T_1 * V_37 ,
T_6 V_76 ,
T_7 V_77 ,
T_8 V_78 ,
void * V_1 , T_2 V_79 , enum V_80 V_80 ,
const T_1 * V_81 ,
struct V_60 * V_61 )
{
struct V_4 * V_5 ;
int V_82 ;
const struct V_83 V_84 = { . V_85 = V_77 ,
. V_86 = V_76 ,
. V_87 = V_78 ,
} ;
F_46 ( ! ( * V_37 & V_88 ) ) ;
if ( F_47 ( F_33 ( V_71 ) ) ) {
F_41 ( L_20 ) ;
F_48 () ;
}
V_5 = F_49 ( V_71 , V_73 , type , V_75 , & V_84 , V_1 , V_79 ,
V_80 ) ;
if ( F_47 ( ! V_5 ) )
GOTO ( V_89 , V_82 = - V_90 ) ;
F_39 ( V_5 , V_61 ) ;
F_50 ( V_5 , V_75 ) ;
V_5 -> V_33 |= V_91 ;
if ( * V_37 & V_92 )
V_5 -> V_33 |= V_92 ;
if ( V_74 != NULL )
V_5 -> V_93 = * V_74 ;
if ( V_81 != NULL )
V_5 -> V_94 = * V_81 ;
if ( type == V_95 )
V_5 -> V_96 = V_74 -> V_97 ;
V_82 = F_51 ( V_71 , & V_5 , V_74 , V_37 ) ;
if ( F_47 ( V_82 != V_98 ) )
GOTO ( V_99 , V_82 ) ;
if ( V_74 != NULL )
* V_74 = V_5 -> V_93 ;
if ( V_5 -> V_100 )
V_5 -> V_100 ( V_5 , * V_37 , NULL ) ;
F_6 ( V_5 , L_21 ) ;
V_99:
F_52 ( V_5 ) ;
V_89:
return V_82 ;
}
static void F_53 ( struct V_70 * V_71 ,
struct V_4 * V_5 , int V_75 )
{
int V_101 = 0 ;
F_43 ( V_5 ) ;
if ( ( V_5 -> V_102 != V_5 -> V_103 ) &&
! ( V_5 -> V_33 & V_35 ) ) {
V_5 -> V_33 |= V_104 | V_35 |
V_92 | V_57 ;
V_101 = 1 ;
}
F_38 ( V_5 ) ;
if ( V_101 )
F_6 ( V_5 ,
L_22
L_23 ) ;
else
F_6 ( V_5 , L_24 ) ;
F_54 ( V_5 , V_75 ) ;
if ( V_5 -> V_43 -> V_105 == V_106 ) {
F_43 ( V_5 ) ;
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
F_38 ( V_5 ) ;
}
}
int F_57 ( struct V_107 * exp , struct V_108 * V_109 ,
T_3 type , T_9 V_110 , T_5 V_75 ,
T_1 * V_37 , void * V_111 , T_2 V_79 ,
struct V_60 * V_61 , int V_46 )
{
struct V_70 * V_71 = exp -> V_18 -> V_112 ;
int V_113 = * V_37 & V_88 ;
struct V_4 * V_5 ;
struct V_114 * V_115 ;
int V_116 = 1 ;
int V_117 = 0 ;
V_5 = F_58 ( V_61 ) ;
if ( ! V_5 ) {
F_46 ( type == V_106 ) ;
return - V_118 ;
}
F_59 ( F_60 ( V_79 != 0 , V_79 == V_5 -> V_119 ) ,
L_25 , V_79 , V_5 -> V_119 ) ;
if ( V_46 != V_98 ) {
F_46 ( ! V_113 ) ;
F_6 ( V_5 , L_26 ,
V_46 == V_120 ? L_27 : L_28 ) ;
if ( V_46 != V_120 )
GOTO ( V_121 , V_46 ) ;
}
V_115 = F_61 ( & V_109 -> V_122 , & V_123 ) ;
if ( V_115 == NULL )
GOTO ( V_121 , V_46 = - V_124 ) ;
if ( V_79 != 0 ) {
F_46 ( V_111 != NULL ) ;
V_117 = F_62 ( & V_109 -> V_122 , & V_125 ,
V_126 ) ;
if ( V_117 < 0 ) {
F_14 ( V_5 , L_29 , V_117 ) ;
GOTO ( V_121 , V_46 = V_117 ) ;
} else if ( F_47 ( V_117 > V_79 ) ) {
F_14 ( V_5 , L_30
L_31 ,
V_79 , V_117 ) ;
GOTO ( V_121 , V_46 = - V_127 ) ;
}
}
if ( V_46 == V_120 ) {
if ( V_79 != 0 )
V_46 = F_63 ( V_5 , & V_109 -> V_122 , V_126 ,
V_111 , V_117 ) ;
GOTO ( V_121 , V_46 = ( V_46 != 0 ? V_46 : V_120 ) ) ;
}
V_116 = 0 ;
F_43 ( V_5 ) ;
if ( exp -> V_128 ) {
F_64 ( exp -> V_128 ,
& V_5 -> V_129 ,
& V_115 -> V_130 ,
& V_5 -> V_131 ) ;
} else {
V_5 -> V_129 = V_115 -> V_130 ;
}
* V_37 = F_65 ( V_115 -> V_132 ) ;
V_5 -> V_33 |= F_65 ( V_115 -> V_132 &
V_133 ) ;
V_5 -> V_33 |= F_65 ( V_115 -> V_132 &
V_48 ) ;
F_38 ( V_5 ) ;
F_66 ( V_134 , L_32 ,
V_5 , V_115 -> V_130 . V_135 , * V_37 ) ;
if ( ( * V_37 ) & V_136 ) {
int V_137 = V_115 -> V_138 . V_102 ;
F_46 ( ! V_113 ) ;
if ( V_137 && V_137 != V_5 -> V_102 ) {
F_6 ( V_5 , L_33 ,
V_139 [ V_137 ] ) ;
V_5 -> V_102 = V_137 ;
}
if ( ! F_67 ( & V_115 -> V_138 . V_43 . V_140 ,
& V_5 -> V_43 -> V_140 ) ) {
F_66 ( V_134 , L_34 V_141
L_35 V_141 L_36 ,
F_68 ( & V_115 -> V_138 . V_43 ) ,
F_68 ( V_5 -> V_43 ) ) ;
V_46 = F_69 ( V_71 , V_5 ,
& V_115 -> V_138 . V_43 . V_140 ) ;
if ( V_46 || V_5 -> V_43 == NULL )
GOTO ( V_121 , V_46 = - V_90 ) ;
F_6 ( V_5 , L_37 ) ;
}
if ( V_110 )
if ( ! ( type == V_142 &&
! ( F_70 ( exp ) & V_143 ) ) )
F_71 ( exp ,
V_5 -> V_43 -> V_105 ,
& V_115 -> V_138 . V_93 ,
& V_5 -> V_93 ) ;
if ( type != V_144 )
F_6 ( V_5 , L_38 ) ;
}
if ( ( * V_37 ) & V_145 ||
( V_146 && type == V_95 ) ) {
F_43 ( V_5 ) ;
V_5 -> V_33 |= V_57 | V_147 ;
F_38 ( V_5 ) ;
F_6 ( V_5 , L_39 ) ;
}
if ( V_79 != 0 ) {
F_43 ( V_5 ) ;
if ( V_5 -> V_102 != V_5 -> V_103 )
V_46 = F_63 ( V_5 , & V_109 -> V_122 , V_126 ,
V_5 -> V_148 , V_117 ) ;
F_38 ( V_5 ) ;
if ( V_46 < 0 ) {
V_116 = 1 ;
GOTO ( V_121 , V_46 ) ;
}
}
if ( ! V_113 ) {
V_46 = F_51 ( V_71 , & V_5 , NULL , V_37 ) ;
if ( V_5 -> V_100 != NULL ) {
int V_82 = V_5 -> V_100 ( V_5 , * V_37 , NULL ) ;
if ( ! V_46 )
V_46 = V_82 ;
if ( V_46 )
V_116 = 1 ;
}
}
if ( V_79 && V_111 != NULL ) {
memcpy ( V_111 , V_5 -> V_148 , V_79 ) ;
}
F_6 ( V_5 , L_40 ) ;
V_121:
if ( V_116 == 1 && V_46 )
F_53 ( V_71 , V_5 , V_75 ) ;
F_72 ( V_5 ) ;
F_52 ( V_5 ) ;
return V_46 ;
}
static inline int F_73 ( int V_149 , int V_150 )
{
int V_151 ;
V_151 = F_19 ( int , V_152 , V_153 - 512 ) - V_149 ;
if ( F_74 ( V_151 >= 0 ) )
V_151 /= ( int ) sizeof( struct V_60 ) ;
else
V_151 = 0 ;
V_151 += V_154 - V_150 ;
return V_151 ;
}
static inline int F_75 ( struct V_155 * V_156 ,
enum V_157 V_158 ,
int V_150 )
{
int V_117 = F_76 ( V_156 , V_158 ) ;
return F_73 ( V_117 , V_150 ) ;
}
static inline int F_77 ( struct V_7 * V_8 ,
const struct V_159 * V_160 ,
enum V_157 V_158 , int V_150 )
{
int V_117 = F_78 ( V_8 -> V_161 , V_160 , V_158 ) ;
return F_73 ( V_117 , V_150 ) ;
}
int F_79 ( struct V_107 * exp , struct V_108 * V_109 ,
int V_162 , int V_163 , int V_164 ,
struct V_165 * V_166 , int V_167 )
{
struct V_70 * V_71 = exp -> V_18 -> V_112 ;
struct V_155 * V_156 = & V_109 -> V_122 ;
struct V_168 * V_169 = NULL ;
int V_37 , V_151 , V_170 , V_171 = 0 ;
F_80 ( V_172 ) ;
int V_46 ;
if ( V_166 == NULL )
V_166 = & V_172 ;
if ( F_81 ( V_71 ) ) {
F_82 ( V_156 , V_173 ) ;
V_151 = F_75 ( V_156 , V_173 , V_164 ) ;
V_37 = F_83 ( V_71 ) ?
V_174 : V_175 ;
V_170 = ! F_83 ( V_71 ) &&
V_163 == V_176 ? 1 : 0 ;
if ( V_151 > V_167 )
V_167 += F_84 ( V_71 , V_166 , V_170 ,
V_151 - V_167 , 0 , V_37 ) ;
if ( V_151 > V_167 )
V_171 = V_167 ;
else
V_171 = V_151 ;
F_85 ( V_156 , & V_177 , V_173 ,
F_86 ( V_171 , V_163 ) ) ;
}
V_46 = F_87 ( V_109 , V_162 , V_163 ) ;
if ( V_46 ) {
F_88 ( V_166 , V_178 , V_167 ) ;
return V_46 ;
}
if ( F_81 ( V_71 ) ) {
if ( V_164 ) {
V_169 = F_89 ( V_156 , & V_177 ) ;
F_46 ( V_169 ) ;
V_169 -> V_179 = V_164 ;
}
F_90 ( V_166 , V_171 , V_109 , 0 ) ;
F_90 ( V_166 , V_167 - V_171 , NULL , 0 ) ;
} else {
F_88 ( V_166 , V_178 , V_167 ) ;
}
return 0 ;
}
int F_91 ( struct V_107 * exp , struct V_108 * V_109 ,
struct V_165 * V_166 , int V_167 )
{
return F_79 ( exp , V_109 , V_180 , V_176 ,
V_181 , V_166 , V_167 ) ;
}
struct V_108 * F_92 ( struct V_107 * exp , int V_79 )
{
struct V_108 * V_109 ;
int V_46 ;
V_109 = F_93 ( F_94 ( exp ) , & V_182 ) ;
if ( V_109 == NULL )
return F_95 ( - V_90 ) ;
V_46 = F_91 ( exp , V_109 , NULL , 0 ) ;
if ( V_46 ) {
F_96 ( V_109 ) ;
return F_95 ( V_46 ) ;
}
F_85 ( & V_109 -> V_122 , & V_125 , V_126 , V_79 ) ;
F_97 ( V_109 ) ;
return V_109 ;
}
int F_98 ( struct V_107 * exp , struct V_108 * * V_68 ,
struct V_183 * V_184 ,
const struct V_72 * V_73 ,
T_4 const * V_74 , T_1 * V_37 ,
void * V_111 , T_2 V_79 , enum V_80 V_80 ,
struct V_60 * V_61 , int V_185 )
{
struct V_70 * V_71 ;
struct V_4 * V_5 ;
struct V_168 * V_186 ;
int V_113 = * V_37 & V_88 ;
int V_187 = 1 ;
int V_46 , V_82 ;
struct V_108 * V_109 ;
F_46 ( exp != NULL ) ;
V_71 = exp -> V_18 -> V_112 ;
if ( V_113 ) {
V_5 = F_99 ( V_61 , 0 ) ;
F_46 ( V_5 != NULL ) ;
F_6 ( V_5 , L_41 ) ;
F_46 ( exp == V_5 -> V_11 ) ;
} else {
const struct V_83 V_84 = {
. V_85 = V_184 -> V_188 ,
. V_86 = V_184 -> V_189 ,
. V_87 = V_184 -> V_190
} ;
V_5 = F_49 ( V_71 , V_73 , V_184 -> V_191 ,
V_184 -> V_192 , & V_84 , V_184 -> V_193 ,
V_79 , V_80 ) ;
if ( V_5 == NULL )
return - V_90 ;
F_100 ( V_5 , V_184 -> V_192 ) ;
F_39 ( V_5 , V_61 ) ;
if ( V_74 != NULL ) {
if ( V_184 -> V_191 == V_142 &&
! ( F_70 ( exp ) &
V_143 ) )
V_5 -> V_93 . V_194 . V_195 =
V_196 |
V_197 ;
else
V_5 -> V_93 = * V_74 ;
}
if ( V_184 -> V_191 == V_95 )
V_5 -> V_96 = V_74 -> V_97 ;
F_6 ( V_5 , L_42 ,
* V_37 ) ;
}
V_5 -> V_11 = exp ;
V_5 -> V_198 = NULL ;
V_5 -> V_67 = V_184 -> V_189 ;
V_5 -> V_33 |= ( * V_37 & ( V_199 | V_200 ) ) ;
if ( V_68 == NULL || * V_68 == NULL ) {
V_109 = F_101 ( F_94 ( exp ) ,
& V_182 ,
V_180 ,
V_176 ) ;
if ( V_109 == NULL ) {
F_53 ( V_71 , V_5 , V_184 -> V_192 ) ;
F_52 ( V_5 ) ;
return - V_90 ;
}
V_187 = 0 ;
if ( V_68 )
* V_68 = V_109 ;
} else {
int V_201 ;
V_109 = * V_68 ;
V_201 = F_62 ( & V_109 -> V_122 , & V_177 ,
V_173 ) ;
F_59 ( V_201 >= sizeof( * V_186 ) , L_43 ,
V_202 , V_201 , ( int ) sizeof( * V_186 ) ) ;
}
V_186 = F_89 ( & V_109 -> V_122 , & V_177 ) ;
F_102 ( V_5 , & V_186 -> V_138 ) ;
V_186 -> V_132 = F_103 ( * V_37 ) ;
V_186 -> V_130 [ 0 ] = * V_61 ;
if ( ! V_187 ) {
if ( V_79 > 0 )
F_104 ( & V_109 -> V_122 ,
& V_203 ) ;
F_85 ( & V_109 -> V_122 , & V_125 , V_126 ,
V_79 ) ;
F_97 ( V_109 ) ;
}
F_46 ( F_60 ( V_146 , V_184 -> V_191 != V_95 ||
V_74 -> V_97 . V_204 == V_205 ) ) ;
if ( V_185 ) {
F_46 ( V_68 != NULL ) ;
return 0 ;
}
F_6 ( V_5 , L_44 ) ;
V_46 = F_105 ( V_109 ) ;
V_82 = F_57 ( exp , V_109 , V_184 -> V_191 , V_74 ? 1 : 0 ,
V_184 -> V_192 , V_37 , V_111 , V_79 ,
V_61 , V_46 ) ;
if ( V_82 == - V_118 )
F_52 ( V_5 ) ;
else
V_46 = V_82 ;
if ( ! V_187 && V_109 != NULL ) {
F_106 ( V_109 ) ;
if ( V_68 )
* V_68 = NULL ;
}
return V_46 ;
}
static int F_107 ( struct V_4 * V_5 , int V_206 ,
T_2 * V_37 )
{
struct V_207 * V_208 ;
int V_46 ;
if ( F_33 ( F_11 ( V_5 ) ) ) {
F_41 ( L_45 ) ;
F_48 () ;
}
F_6 ( V_5 , L_46 ) ;
V_208 = F_108 ( V_5 , V_206 , V_37 ) ;
if ( V_208 ) {
F_25 ( V_208 ) ;
V_46 = 0 ;
} else {
V_46 = V_209 ;
}
F_6 ( V_5 , L_47 ) ;
F_72 ( V_5 ) ;
return V_46 ;
}
int F_109 ( struct V_60 * V_61 , int V_206 , T_2 * V_37 )
{
struct V_168 * V_186 ;
struct V_114 * V_115 ;
struct V_4 * V_5 ;
struct V_207 * V_208 ;
struct V_108 * V_109 ;
int V_46 ;
V_5 = F_58 ( V_61 ) ;
if ( ! V_5 ) {
F_48 () ;
return - V_127 ;
}
* V_37 = 0 ;
if ( V_5 -> V_11 == NULL )
return F_107 ( V_5 , V_206 , V_37 ) ;
F_6 ( V_5 , L_48 ) ;
V_109 = F_101 ( F_94 ( V_5 -> V_11 ) ,
& V_210 , V_180 ,
V_211 ) ;
if ( V_109 == NULL ) {
F_72 ( V_5 ) ;
return - V_90 ;
}
V_186 = F_89 ( & V_109 -> V_122 , & V_177 ) ;
V_186 -> V_130 [ 0 ] = V_5 -> V_129 ;
V_186 -> V_138 . V_102 = V_206 ;
V_186 -> V_132 = F_103 ( * V_37 ) ;
F_97 ( V_109 ) ;
V_46 = F_105 ( V_109 ) ;
if ( V_46 != V_98 )
GOTO ( V_99 , V_46 ) ;
V_115 = F_61 ( & V_109 -> V_122 , & V_123 ) ;
if ( V_115 == NULL )
GOTO ( V_99 , V_46 = - V_124 ) ;
if ( V_109 -> V_212 )
GOTO ( V_99 , V_46 = V_109 -> V_212 ) ;
V_208 = F_108 ( V_5 , V_206 , & V_115 -> V_132 ) ;
if ( V_208 != NULL ) {
F_25 ( V_208 ) ;
if ( V_5 -> V_100 ) {
V_46 = V_5 -> V_100 ( V_5 , V_38 ,
NULL ) ;
if ( V_46 )
GOTO ( V_99 , V_46 ) ;
}
} else {
V_46 = V_209 ;
}
V_99:
F_72 ( V_5 ) ;
F_106 ( V_109 ) ;
return V_46 ;
}
static T_1 F_110 ( struct V_4 * V_5 )
{
T_1 V_46 = V_104 ;
if ( V_5 -> V_11 ) {
bool V_213 ;
F_6 ( V_5 , L_49 ) ;
F_43 ( V_5 ) ;
V_5 -> V_33 |= V_57 ;
V_213 = ! ! ( V_5 -> V_33 &
( V_104 | V_214 ) ) ;
F_111 ( V_5 ) ;
V_46 = ( V_5 -> V_33 & V_147 ) ?
V_147 : V_215 ;
F_38 ( V_5 ) ;
if ( V_213 ) {
F_66 ( V_17 , L_50
L_51 ) ;
V_46 = V_104 ;
}
F_112 ( V_5 ) ;
} else {
if ( F_33 ( F_11 ( V_5 ) ) ) {
F_14 ( V_5 , L_52 ) ;
F_48 () ;
}
F_6 ( V_5 , L_53 ) ;
F_112 ( V_5 ) ;
F_25 ( V_5 -> V_43 ) ;
}
return V_46 ;
}
static void F_113 ( struct V_108 * V_109 ,
struct V_165 * V_172 , int V_167 )
{
struct V_168 * V_169 ;
struct V_4 * V_5 ;
int F_20 , V_216 = 0 ;
V_169 = F_89 ( & V_109 -> V_122 , & V_177 ) ;
F_46 ( V_169 != NULL ) ;
F_20 = F_62 ( & V_109 -> V_122 , & V_177 , V_173 ) -
sizeof( struct V_168 ) ;
F_20 /= sizeof( struct V_60 ) ;
F_20 += V_154 ;
F_46 ( F_20 >= V_169 -> V_179 + V_167 ) ;
F_114 (lock, head, l_bl_ast) {
if ( ! V_167 -- )
break;
F_46 ( V_5 -> V_11 ) ;
F_6 ( V_5 , L_54 ) ;
V_169 -> V_130 [ V_169 -> V_179 ++ ] = V_5 -> V_129 ;
V_216 ++ ;
}
F_66 ( V_17 , L_55 , V_216 ) ;
}
int F_115 ( struct V_107 * exp , struct V_165 * V_166 ,
int V_167 , T_10 V_37 )
{
struct V_108 * V_109 = NULL ;
struct V_7 * V_8 ;
int free , V_217 = 0 ;
int V_46 = 0 ;
F_46 ( exp != NULL ) ;
F_46 ( V_167 > 0 ) ;
F_116 ( V_218 , V_219 ) ;
if ( F_117 ( V_220 ) )
return V_167 ;
free = F_77 ( F_94 ( exp ) ,
& V_221 , V_173 , 0 ) ;
if ( V_167 > free )
V_167 = free ;
while ( 1 ) {
V_8 = F_94 ( exp ) ;
if ( V_8 == NULL || V_8 -> V_222 ) {
F_66 ( V_17 ,
L_56 , V_8 ) ;
return V_167 ;
}
V_109 = F_93 ( V_8 , & V_221 ) ;
if ( V_109 == NULL )
GOTO ( V_99 , V_46 = - V_90 ) ;
F_82 ( & V_109 -> V_122 , V_173 ) ;
F_85 ( & V_109 -> V_122 , & V_177 , V_173 ,
F_86 ( V_167 , V_223 ) ) ;
V_46 = F_87 ( V_109 , V_180 , V_223 ) ;
if ( V_46 ) {
F_96 ( V_109 ) ;
GOTO ( V_99 , V_46 ) ;
}
V_109 -> V_224 = V_225 ;
V_109 -> V_226 = V_227 ;
F_118 ( V_109 ) ;
F_113 ( V_109 , V_166 , V_167 ) ;
F_97 ( V_109 ) ;
if ( V_37 & V_62 ) {
F_119 ( V_109 , V_228 , - 1 ) ;
V_217 = V_167 ;
GOTO ( V_99 , 0 ) ;
} else {
V_46 = F_105 ( V_109 ) ;
}
if ( V_46 == V_229 ) {
F_66 ( V_17 , L_57
L_58 ,
F_120 ( V_109 -> V_230 ->
V_23 -> V_231 . V_232 ) ) ;
V_46 = 0 ;
} else if ( V_46 == - V_233 &&
V_109 -> V_234 == V_8 -> V_235 ) {
F_106 ( V_109 ) ;
continue;
} else if ( V_46 != V_98 ) {
F_121 ( V_46 == - V_236 ? V_17 : V_237 ,
L_59
L_60 , V_46 ) ;
break;
}
V_217 = V_167 ;
break;
}
F_106 ( V_109 ) ;
V_99:
return V_217 ? V_217 : V_46 ;
}
static inline struct V_238 * F_122 ( struct V_7 * V_8 )
{
F_46 ( V_8 != NULL ) ;
return & V_8 -> V_239 -> V_112 -> V_240 ;
}
int F_123 ( struct V_108 * V_109 )
{
struct V_9 * V_10 ;
T_1 V_241 ;
T_2 V_242 ;
if ( F_47 ( ! V_109 -> V_230 || ! V_109 -> V_230 -> V_239 ||
! F_124 ( V_109 -> V_230 ) ) )
{
return 0 ;
}
if ( F_125 ( V_109 -> V_243 ) == 0 ||
F_126 ( V_109 -> V_243 ) == 0 ) {
F_127 ( V_244 , V_109 , L_61 ,
F_125 ( V_109 -> V_243 ) ,
F_126 ( V_109 -> V_243 ) ) ;
return 0 ;
}
V_242 = F_126 ( V_109 -> V_243 ) ;
V_241 = F_125 ( V_109 -> V_243 ) ;
V_10 = V_109 -> V_230 -> V_239 ;
F_128 ( & V_10 -> V_245 ) ;
V_10 -> V_246 = V_241 ;
V_10 -> V_247 = V_242 ;
F_129 ( & V_10 -> V_245 ) ;
return 0 ;
}
int F_40 ( struct V_60 * V_61 ,
T_10 V_248 )
{
struct V_107 * exp ;
int V_151 , V_37 , V_167 = 1 ;
T_1 V_46 = 0 ;
struct V_70 * V_71 ;
struct V_4 * V_5 ;
F_80 ( V_166 ) ;
V_5 = F_99 ( V_61 , V_215 ) ;
if ( V_5 == NULL ) {
F_130 ( L_62 ) ;
return 0 ;
}
V_46 = F_110 ( V_5 ) ;
if ( V_46 == V_104 || V_248 & V_249 ) {
F_52 ( V_5 ) ;
return 0 ;
}
F_46 ( F_131 ( & V_5 -> V_178 ) ) ;
F_132 ( & V_5 -> V_178 , & V_166 ) ;
exp = V_5 -> V_11 ;
if ( F_133 ( exp ) ) {
V_151 = F_77 ( F_94 ( exp ) ,
& V_221 ,
V_173 , 0 ) ;
F_46 ( V_151 > 0 ) ;
V_71 = F_11 ( V_5 ) ;
V_37 = F_83 ( V_71 ) ?
V_174 : V_175 ;
V_167 += F_84 ( V_71 , & V_166 , 0 , V_151 - 1 ,
V_250 , V_37 ) ;
}
F_90 ( & V_166 , V_167 , NULL , V_248 ) ;
return 0 ;
}
int F_134 ( struct V_165 * V_166 , int V_167 ,
T_10 V_37 )
{
F_80 ( V_172 ) ;
struct V_4 * V_5 , * V_251 ;
int V_252 = 0 , V_253 = 0 ;
T_1 V_46 ;
V_252 = V_167 ;
F_135 (lock, next, cancels, l_bl_ast) {
if ( V_252 -- == 0 )
break;
if ( V_37 & V_249 ) {
V_46 = V_104 ;
F_112 ( V_5 ) ;
} else {
V_46 = F_110 ( V_5 ) ;
}
if ( ! ( V_37 & V_250 ) && ( V_46 == V_147 ) ) {
F_6 ( V_5 , L_63 ) ;
F_136 ( & V_5 -> V_178 ) ;
F_132 ( & V_5 -> V_178 , & V_172 ) ;
V_253 ++ ;
continue;
}
if ( V_46 == V_104 ) {
F_136 ( & V_5 -> V_178 ) ;
F_52 ( V_5 ) ;
V_167 -- ;
}
}
if ( V_253 > 0 ) {
V_167 -= V_253 ;
F_90 ( & V_172 , V_253 , NULL , 0 ) ;
}
return V_167 ;
}
static T_11 F_137 ( struct V_70 * V_71 ,
struct V_4 * V_5 ,
int V_254 , int V_255 ,
int V_167 )
{
T_11 V_32 = V_256 ;
T_12 V_257 = V_71 -> V_258 ;
F_43 ( V_5 ) ;
switch ( V_5 -> V_43 -> V_105 ) {
case V_95 :
case V_142 :
if ( V_257 && V_257 ( V_5 ) )
break;
default:
V_32 = V_259 ;
V_5 -> V_33 |= V_260 ;
break;
}
F_38 ( V_5 ) ;
return V_32 ;
}
static T_11 F_138 ( struct V_70 * V_71 ,
struct V_4 * V_5 ,
int V_254 , int V_255 ,
int V_167 )
{
unsigned long V_261 = F_8 () ;
struct V_238 * V_262 = & V_71 -> V_240 ;
T_1 V_263 , V_264 , V_265 ;
unsigned long V_266 ;
if ( V_167 && V_255 >= V_167 )
return V_267 ;
V_263 = F_139 ( V_262 ) ;
V_264 = F_140 ( V_262 ) ;
V_266 = F_141 ( F_4 ( V_261 ,
V_5 -> V_268 ) ) ;
V_265 = V_264 * V_266 * V_254 ;
F_142 ( V_262 , V_265 ) ;
return ( V_263 == 0 || V_265 < V_263 ) ?
V_267 : V_256 ;
}
static T_11 F_143 ( struct V_70 * V_71 ,
struct V_4 * V_5 ,
int V_254 , int V_255 ,
int V_167 )
{
return ( V_255 >= V_167 ) ?
V_267 : V_256 ;
}
static T_11 F_144 ( struct V_70 * V_71 ,
struct V_4 * V_5 ,
int V_254 , int V_255 ,
int V_167 )
{
return ( ( V_255 >= V_167 ) &&
F_145 ( F_8 () ,
F_146 ( V_5 -> V_268 , V_71 -> V_269 ) ) ) ?
V_267 : V_256 ;
}
static T_11 F_147 ( struct V_70 * V_71 ,
struct V_4 * V_5 ,
int V_254 , int V_255 ,
int V_167 )
{
return ( V_255 >= V_167 ) ?
V_267 : V_256 ;
}
static T_13
F_148 ( struct V_70 * V_71 , int V_37 )
{
if ( V_37 & V_270 )
return F_137 ;
if ( F_83 ( V_71 ) ) {
if ( V_37 & V_271 )
return F_143 ;
else if ( V_37 & V_174 )
return F_138 ;
else if ( V_37 & V_272 )
return F_143 ;
} else {
if ( V_37 & V_175 )
return F_144 ;
}
return F_147 ;
}
static int F_149 ( struct V_70 * V_71 , struct V_165 * V_166 ,
int V_167 , int F_20 , int V_37 )
{
T_13 V_273 ;
struct V_4 * V_5 , * V_251 ;
int V_255 = 0 , V_254 , V_274 ;
F_31 ( & V_71 -> V_275 ) ;
V_254 = V_71 -> V_276 ;
V_274 = V_254 ;
if ( ! F_83 ( V_71 ) )
V_167 += V_254 - V_71 -> V_277 ;
V_273 = F_148 ( V_71 , V_37 ) ;
F_46 ( V_273 != NULL ) ;
while ( ! F_131 ( & V_71 -> V_278 ) ) {
T_11 V_32 ;
if ( V_274 -- <= 0 )
break;
if ( F_20 && V_255 >= F_20 )
break;
F_135 (lock, next, &ns->ns_unused_list,
l_lru) {
F_46 ( ! ( V_5 -> V_33 & V_147 ) ) ;
if ( V_37 & V_270 &&
V_5 -> V_33 & V_260 )
continue;
if ( ! ( V_5 -> V_33 & V_215 ) )
break;
F_150 ( V_5 ) ;
}
if ( & V_5 -> V_279 == & V_71 -> V_278 )
break;
F_151 ( V_5 ) ;
F_32 ( & V_71 -> V_275 ) ;
F_152 ( & V_5 -> V_280 , V_281 , V_282 ) ;
V_32 = V_273 ( V_71 , V_5 , V_254 , V_255 , V_167 ) ;
if ( V_32 == V_267 ) {
F_153 ( & V_5 -> V_280 ,
V_281 , V_282 ) ;
F_52 ( V_5 ) ;
F_31 ( & V_71 -> V_275 ) ;
break;
}
if ( V_32 == V_259 ) {
F_153 ( & V_5 -> V_280 ,
V_281 , V_282 ) ;
F_52 ( V_5 ) ;
F_31 ( & V_71 -> V_275 ) ;
continue;
}
F_43 ( V_5 ) ;
if ( ( V_5 -> V_33 & V_215 ) ||
( F_154 ( V_5 ) == 0 ) ) {
F_38 ( V_5 ) ;
F_153 ( & V_5 -> V_280 ,
V_281 , V_282 ) ;
F_52 ( V_5 ) ;
F_31 ( & V_71 -> V_275 ) ;
continue;
}
F_46 ( ! V_5 -> V_58 && ! V_5 -> V_59 ) ;
V_5 -> V_33 &= ~ V_214 ;
V_5 -> V_33 |= V_57 | V_215 ;
F_46 ( F_131 ( & V_5 -> V_178 ) ) ;
F_132 ( & V_5 -> V_178 , V_166 ) ;
F_38 ( V_5 ) ;
F_153 ( & V_5 -> V_280 , V_281 , V_282 ) ;
F_31 ( & V_71 -> V_275 ) ;
V_255 ++ ;
V_254 -- ;
}
F_32 ( & V_71 -> V_275 ) ;
return V_255 ;
}
int F_84 ( struct V_70 * V_71 , struct V_165 * V_166 ,
int V_167 , int F_20 , T_10 V_248 ,
int V_37 )
{
int V_255 ;
V_255 = F_149 ( V_71 , V_166 , V_167 , F_20 , V_37 ) ;
if ( V_255 <= 0 )
return V_255 ;
return F_134 ( V_166 , V_255 , V_248 ) ;
}
int F_155 ( struct V_70 * V_71 , int V_283 ,
T_10 V_248 ,
int V_37 )
{
F_80 ( V_166 ) ;
int V_167 , V_46 ;
V_167 = F_149 ( V_71 , & V_166 , V_283 , 0 , V_37 ) ;
V_46 = F_156 ( V_71 , NULL , & V_166 , V_167 , V_248 ) ;
if ( V_46 == 0 )
return V_167 ;
return 0 ;
}
int F_157 ( struct V_207 * V_208 ,
struct V_165 * V_166 ,
T_4 * V_74 ,
T_5 V_75 , T_1 V_132 ,
T_10 V_248 , void * V_284 )
{
struct V_4 * V_5 ;
int V_167 = 0 ;
F_158 ( V_208 ) ;
F_114 (lock, &res->lr_granted, l_res_link) {
if ( V_284 != NULL && V_5 -> V_285 != V_284 ) {
F_14 ( V_5 , L_64 ,
V_5 -> V_285 , V_284 ) ;
continue;
}
if ( V_5 -> V_58 || V_5 -> V_59 )
continue;
if ( V_5 -> V_33 & V_147 ||
V_5 -> V_33 & V_215 )
continue;
if ( F_159 ( V_5 -> V_103 , V_75 ) )
continue;
if ( V_74 && ( V_5 -> V_43 -> V_105 == V_142 ) &&
! ( V_5 -> V_93 . V_194 . V_195 &
V_74 -> V_194 . V_195 ) )
continue;
V_5 -> V_33 |= V_57 | V_215 |
V_132 ;
F_46 ( F_131 ( & V_5 -> V_178 ) ) ;
F_132 ( & V_5 -> V_178 , V_166 ) ;
F_151 ( V_5 ) ;
V_167 ++ ;
}
F_160 ( V_208 ) ;
return F_134 ( V_166 , V_167 , V_248 ) ;
}
int F_90 ( struct V_165 * V_166 , int V_167 ,
struct V_108 * V_109 , T_10 V_37 )
{
struct V_4 * V_5 ;
int V_208 = 0 ;
if ( F_131 ( V_166 ) || V_167 == 0 )
return 0 ;
while ( V_167 > 0 ) {
F_46 ( ! F_131 ( V_166 ) ) ;
V_5 = F_161 ( V_166 -> V_251 , struct V_4 ,
V_178 ) ;
F_46 ( V_5 -> V_11 ) ;
if ( F_133 ( V_5 -> V_11 ) ) {
V_208 = V_167 ;
if ( V_109 )
F_113 ( V_109 , V_166 , V_167 ) ;
else
V_208 = F_115 ( V_5 -> V_11 ,
V_166 , V_167 ,
V_37 ) ;
} else {
V_208 = F_115 ( V_5 -> V_11 ,
V_166 , 1 , V_37 ) ;
}
if ( V_208 < 0 ) {
F_121 ( V_208 == - V_236 ? V_17 : V_237 ,
L_65 , V_208 ) ;
V_208 = V_167 ;
}
V_167 -= V_208 ;
F_88 ( V_166 , V_178 , V_208 ) ;
}
F_46 ( V_167 == 0 ) ;
return 0 ;
}
int F_162 ( struct V_70 * V_71 ,
const struct V_72 * V_73 ,
T_4 * V_74 ,
T_5 V_75 ,
T_10 V_37 ,
void * V_284 )
{
struct V_207 * V_208 ;
F_80 ( V_166 ) ;
int V_167 ;
int V_46 ;
V_208 = F_163 ( V_71 , NULL , V_73 , 0 , 0 ) ;
if ( V_208 == NULL ) {
F_66 ( V_134 , L_66 , V_73 -> V_286 [ 0 ] ) ;
return 0 ;
}
F_164 ( V_208 ) ;
V_167 = F_157 ( V_208 , & V_166 , V_74 , V_75 ,
0 , V_37 | V_250 , V_284 ) ;
V_46 = F_90 ( & V_166 , V_167 , NULL , V_37 ) ;
if ( V_46 != V_98 )
F_41 ( L_67 V_141 L_68 ,
F_68 ( V_208 ) , V_46 ) ;
F_165 ( V_208 ) ;
F_166 ( V_208 ) ;
return 0 ;
}
static int F_167 ( struct V_287 * V_288 , struct V_289 * V_290 ,
struct V_291 * V_292 , void * V_293 )
{
struct V_207 * V_208 = F_168 ( V_288 , V_292 ) ;
struct V_294 * V_295 = V_293 ;
F_162 ( F_169 ( V_208 ) , & V_208 -> V_140 ,
NULL , V_296 ,
V_295 -> V_297 , V_295 -> V_298 ) ;
return 0 ;
}
int F_170 ( struct V_70 * V_71 ,
const struct V_72 * V_73 ,
T_10 V_37 , void * V_284 )
{
struct V_294 V_293 = {
. V_297 = V_37 ,
. V_298 = V_284 ,
} ;
if ( V_71 == NULL )
return V_98 ;
if ( V_73 != NULL ) {
return F_162 ( V_71 , V_73 , NULL ,
V_296 , V_37 ,
V_284 ) ;
} else {
F_171 ( V_71 -> V_299 ,
F_167 , & V_293 ) ;
return V_98 ;
}
}
int F_172 ( struct V_207 * V_208 , T_14 V_300 ,
void * V_301 )
{
struct V_165 * V_302 , * V_251 ;
struct V_4 * V_5 ;
int V_46 = V_303 ;
if ( ! V_208 )
return V_303 ;
F_158 ( V_208 ) ;
F_173 (tmp, next, &res->lr_granted) {
V_5 = F_161 ( V_302 , struct V_4 , V_304 ) ;
if ( V_300 ( V_5 , V_301 ) == V_305 )
GOTO ( V_99 , V_46 = V_305 ) ;
}
F_173 (tmp, next, &res->lr_converting) {
V_5 = F_161 ( V_302 , struct V_4 , V_304 ) ;
if ( V_300 ( V_5 , V_301 ) == V_305 )
GOTO ( V_99 , V_46 = V_305 ) ;
}
F_173 (tmp, next, &res->lr_waiting) {
V_5 = F_161 ( V_302 , struct V_4 , V_304 ) ;
if ( V_300 ( V_5 , V_301 ) == V_305 )
GOTO ( V_99 , V_46 = V_305 ) ;
}
V_99:
F_160 ( V_208 ) ;
return V_46 ;
}
static int F_174 ( struct V_4 * V_5 , void * V_301 )
{
struct V_306 * V_307 = V_301 ;
return V_307 -> V_300 ( V_5 , V_307 -> V_301 ) ;
}
static int F_175 ( struct V_287 * V_288 , struct V_289 * V_290 ,
struct V_291 * V_292 , void * V_293 )
{
struct V_207 * V_208 = F_168 ( V_288 , V_292 ) ;
return F_172 ( V_208 , F_174 , V_293 ) ==
V_305 ;
}
void F_176 ( struct V_70 * V_71 ,
T_14 V_300 , void * V_301 )
{
struct V_306 V_307 = {
. V_300 = V_300 ,
. V_301 = V_301 ,
} ;
F_171 ( V_71 -> V_299 ,
F_175 , & V_307 ) ;
}
int F_177 ( struct V_70 * V_71 ,
const struct V_72 * V_73 ,
T_14 V_300 , void * V_1 )
{
struct V_207 * V_208 ;
int V_46 ;
if ( V_71 == NULL ) {
F_41 ( L_69 ) ;
F_48 () ;
}
V_208 = F_163 ( V_71 , NULL , V_73 , 0 , 0 ) ;
if ( V_208 == NULL )
return 0 ;
F_164 ( V_208 ) ;
V_46 = F_172 ( V_208 , V_300 , V_1 ) ;
F_165 ( V_208 ) ;
F_166 ( V_208 ) ;
return V_46 ;
}
static int F_178 ( struct V_4 * V_5 , void * V_301 )
{
struct V_165 * V_308 = V_301 ;
F_59 ( F_131 ( & V_5 -> V_309 ) ,
L_70 ,
V_5 , & V_5 -> V_309 . V_251 , & V_5 -> V_309 . V_310 ) ;
if ( ! ( V_5 -> V_33 & ( V_35 | V_215 ) ) ) {
F_132 ( & V_5 -> V_309 , V_308 ) ;
F_151 ( V_5 ) ;
}
return V_303 ;
}
static int F_179 ( const struct V_311 * V_312 ,
struct V_108 * V_109 ,
struct V_313 * V_314 , int V_46 )
{
struct V_4 * V_5 ;
struct V_114 * V_115 ;
struct V_107 * exp ;
F_180 ( & V_109 -> V_230 -> V_315 ) ;
if ( V_46 != V_98 )
GOTO ( V_99 , V_46 ) ;
V_115 = F_61 ( & V_109 -> V_122 , & V_123 ) ;
if ( V_115 == NULL )
GOTO ( V_99 , V_46 = - V_124 ) ;
V_5 = F_58 ( & V_314 -> V_130 ) ;
if ( ! V_5 ) {
F_41 ( L_71
L_72 ,
V_314 -> V_130 . V_135 , V_115 -> V_130 . V_135 ,
V_109 -> V_316 -> V_317 . V_25 ,
F_181 ( V_109 -> V_318 ) ) ;
GOTO ( V_99 , V_46 = - V_319 ) ;
}
exp = V_109 -> V_316 ;
if ( exp && exp -> V_128 ) {
F_64 ( exp -> V_128 ,
& V_5 -> V_129 ,
& V_115 -> V_130 ,
& V_5 -> V_131 ) ;
} else {
V_5 -> V_129 = V_115 -> V_130 ;
}
F_6 ( V_5 , L_73 ) ;
F_182 ( V_109 -> V_230 ) ;
F_72 ( V_5 ) ;
V_99:
if ( V_46 != V_98 )
F_183 ( V_109 -> V_230 ) ;
return V_46 ;
}
static int F_184 ( struct V_7 * V_8 , struct V_4 * V_5 )
{
struct V_108 * V_109 ;
struct V_313 * V_314 ;
struct V_168 * V_186 ;
int V_37 ;
if ( V_5 -> V_33 & V_215 ) {
F_6 ( V_5 , L_74 ) ;
return 0 ;
}
if ( V_5 -> V_33 & V_214 ) {
F_6 ( V_5 , L_75 ) ;
F_112 ( V_5 ) ;
return 0 ;
}
if ( V_5 -> V_103 == V_5 -> V_102 )
V_37 = V_88 | V_40 ;
else if ( V_5 -> V_103 )
V_37 = V_88 | V_41 ;
else if ( ! F_131 ( & V_5 -> V_304 ) )
V_37 = V_88 | V_39 ;
else
V_37 = V_88 ;
V_109 = F_101 ( V_8 , & V_182 ,
V_180 , V_176 ) ;
if ( V_109 == NULL )
return - V_90 ;
V_109 -> V_320 = V_321 ;
V_186 = F_89 ( & V_109 -> V_122 , & V_177 ) ;
F_102 ( V_5 , & V_186 -> V_138 ) ;
V_186 -> V_132 = F_103 ( V_37 ) ;
F_39 ( V_5 , & V_186 -> V_130 [ 0 ] ) ;
if ( V_5 -> V_119 > 0 )
F_104 ( & V_109 -> V_122 , & V_203 ) ;
F_85 ( & V_109 -> V_122 , & V_125 , V_126 ,
V_5 -> V_119 ) ;
F_97 ( V_109 ) ;
F_185 ( V_109 -> V_322 , V_323 ) ;
F_6 ( V_5 , L_76 ) ;
F_186 ( & V_109 -> V_230 -> V_315 ) ;
F_187 ( sizeof( * V_314 ) <= sizeof( V_109 -> V_324 ) ) ;
V_314 = F_188 ( V_109 ) ;
V_314 -> V_130 = V_186 -> V_130 [ 0 ] ;
V_109 -> V_325 = ( V_326 ) F_179 ;
F_119 ( V_109 , V_228 , - 1 ) ;
return 0 ;
}
static void F_189 ( struct V_70 * V_71 )
{
int V_327 ;
F_80 ( V_166 ) ;
F_66 ( V_17 , L_77
L_78 ,
F_190 ( V_71 ) , V_71 -> V_276 ) ;
V_327 = F_84 ( V_71 , & V_166 , V_71 -> V_276 , 0 ,
V_249 , V_270 ) ;
F_66 ( V_17 , L_79 ,
V_327 , F_190 ( V_71 ) ) ;
}
int F_191 ( struct V_7 * V_8 )
{
struct V_70 * V_71 = V_8 -> V_239 -> V_112 ;
F_80 ( V_308 ) ;
struct V_4 * V_5 , * V_251 ;
int V_46 = 0 ;
F_46 ( F_192 ( & V_8 -> V_315 ) == 0 ) ;
if ( V_8 -> V_328 )
return 0 ;
F_186 ( & V_8 -> V_315 ) ;
if ( V_329 )
F_189 ( V_71 ) ;
F_176 ( V_71 , F_178 , & V_308 ) ;
F_135 (lock, next, &list, l_pending_chain) {
F_136 ( & V_5 -> V_309 ) ;
if ( V_46 ) {
F_52 ( V_5 ) ;
continue;
}
V_46 = F_184 ( V_8 , V_5 ) ;
F_52 ( V_5 ) ;
}
F_180 ( & V_8 -> V_315 ) ;
return V_46 ;
}
