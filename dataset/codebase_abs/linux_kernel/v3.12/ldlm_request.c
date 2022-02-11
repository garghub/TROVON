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
static T_1 V_12 = 0 , V_13 = 0 ;
if ( F_3 () )
return 0 ;
F_4 ( L_1 V_14 L_2
V_15 L_3 ,
V_5 -> V_16 ,
F_5 ( F_6 () ,
V_5 -> V_16 ) ) ;
F_7 ( V_5 , L_1 V_14 L_2
V_15 L_4
L_5 ,
V_5 -> V_16 ,
F_5 ( F_6 () ,
V_5 -> V_16 ) ) ;
if ( F_8 ( F_9 () , V_12 ) ) {
V_13 = V_12 ;
V_12 = F_10 ( 300 ) ;
F_11 ( V_17 ,
F_12 ( V_5 ) ) ;
if ( V_13 == 0 )
F_13 () ;
}
return 0 ;
}
V_10 = V_5 -> V_11 -> V_18 ;
V_8 = V_10 -> V_19 . V_20 . V_21 ;
F_14 ( V_8 , V_3 -> V_22 ) ;
F_15 ( V_5 , L_1 V_14 L_2
V_15 L_6 ,
V_5 -> V_16 ,
F_5 ( F_6 () , V_5 -> V_16 ) ,
F_16 ( V_10 ) , V_8 -> V_23 -> V_24 . V_25 ) ;
return 0 ;
}
int F_17 ( struct V_4 * V_5 )
{
int V_26 = F_18 ( F_19 ( V_5 ) ) ;
if ( V_27 )
return V_28 / 2 ;
V_26 = F_20 ( int , V_29 , V_26 + ( V_26 >> 1 ) ) ;
return F_21 ( V_26 , V_30 ) ;
}
static int F_22 ( struct V_4 * V_5 )
{
long V_31 ;
int V_32 ;
if ( V_5 -> V_33 & ( V_34 | V_35 ) ) {
F_7 ( V_5 , L_7 ) ;
V_32 = - V_36 ;
} else {
V_31 = F_5 ( F_6 () ,
V_5 -> V_16 ) ;
F_7 ( V_5 , L_8
V_15 L_9 , V_31 ) ;
F_23 ( F_19 ( V_5 ) ,
V_31 ) ;
V_32 = 0 ;
}
return V_32 ;
}
int F_24 ( struct V_4 * V_5 , T_2 V_37 , void * V_1 )
{
if ( V_37 == V_38 ) {
F_7 ( V_5 , L_10 ) ;
return 0 ;
}
if ( ! ( V_37 & ( V_39 | V_40 |
V_41 ) ) ) {
F_25 ( & V_5 -> V_42 ) ;
return F_22 ( V_5 ) ;
}
F_7 ( V_5 , L_11
L_12 ) ;
F_26 ( V_5 -> V_43 ) ;
return 0 ;
}
int F_27 ( struct V_4 * V_5 , T_2 V_37 , void * V_1 )
{
struct V_2 V_3 ;
struct V_9 * V_10 ;
struct V_7 * V_8 = NULL ;
struct V_44 V_45 ;
T_3 V_26 ;
int V_46 = 0 ;
if ( V_37 == V_38 ) {
F_7 ( V_5 , L_10 ) ;
goto V_47;
}
if ( ! ( V_37 & ( V_39 | V_40 |
V_41 ) ) ) {
F_25 ( & V_5 -> V_42 ) ;
return 0 ;
}
F_7 ( V_5 , L_11
L_13 ) ;
V_47:
V_10 = F_28 ( V_5 -> V_11 ) ;
if ( V_10 != NULL ) {
V_8 = V_10 -> V_19 . V_20 . V_21 ;
}
V_26 = F_17 ( V_5 ) * 2 ;
V_3 . V_6 = V_5 ;
if ( V_5 -> V_33 & V_48 ) {
F_7 ( V_5 , L_14 ) ;
V_45 = F_29 ( F_1 , & V_3 ) ;
} else {
V_45 = F_30 ( F_31 ( V_26 ) ,
F_2 ,
F_1 , & V_3 ) ;
}
if ( V_8 != NULL ) {
F_32 ( & V_8 -> V_49 ) ;
V_3 . V_22 = V_8 -> V_50 ;
F_33 ( & V_8 -> V_49 ) ;
}
if ( F_34 ( F_12 ( V_5 ) ) &&
F_35 ( V_51 ,
V_52 | V_53 ) ) {
V_5 -> V_33 |= V_54 ;
V_46 = - V_55 ;
} else {
V_46 = F_36 ( V_5 -> V_42 ,
F_37 ( V_5 ) , & V_45 ) ;
}
if ( V_46 ) {
F_7 ( V_5 , L_15 ,
V_46 ) ;
return V_46 ;
}
return F_22 ( V_5 ) ;
}
int F_38 ( struct V_4 * V_5 )
{
int V_56 ;
V_5 -> V_33 |= V_57 ;
V_56 = ( ! V_5 -> V_58 && ! V_5 -> V_59 ) ;
F_39 ( V_5 ) ;
if ( V_56 ) {
struct V_60 V_61 ;
int V_46 ;
F_7 ( V_5 , L_16 ) ;
F_40 ( V_5 , & V_61 ) ;
V_46 = F_41 ( & V_61 , V_62 ) ;
if ( V_46 < 0 )
F_42 ( L_17 , V_46 ) ;
} else {
F_7 ( V_5 , L_18
L_19 ) ;
}
return 0 ;
}
int F_43 ( struct V_4 * V_5 , struct V_63 * V_64 ,
void * V_1 , int V_65 )
{
if ( V_65 == V_66 ) {
return 0 ;
}
F_44 ( V_5 ) ;
if ( V_5 -> V_67 != F_43 ) {
F_39 ( V_5 ) ;
return 0 ;
}
return F_38 ( V_5 ) ;
}
int F_45 ( struct V_4 * V_5 , void * V_68 )
{
return - V_69 ;
}
int F_46 ( struct V_70 * V_71 ,
const struct V_72 * V_73 ,
T_4 type , T_5 * V_74 ,
T_6 V_75 , T_2 * V_37 ,
T_7 V_76 ,
T_8 V_77 ,
T_9 V_78 ,
void * V_1 , T_3 V_79 , enum V_80 V_80 ,
const T_2 * V_81 ,
struct V_60 * V_61 )
{
struct V_4 * V_5 ;
int V_82 ;
const struct V_83 V_84 = { . V_85 = V_77 ,
. V_86 = V_76 ,
. V_87 = V_78 ,
} ;
F_47 ( ! ( * V_37 & V_88 ) ) ;
if ( F_48 ( F_34 ( V_71 ) ) ) {
F_42 ( L_20 ) ;
F_49 () ;
}
V_5 = F_50 ( V_71 , V_73 , type , V_75 , & V_84 , V_1 , V_79 ,
V_80 ) ;
if ( F_48 ( ! V_5 ) )
GOTO ( V_89 , V_82 = - V_90 ) ;
F_40 ( V_5 , V_61 ) ;
F_51 ( V_5 , V_75 ) ;
V_5 -> V_33 |= V_91 ;
if ( * V_37 & V_92 )
V_5 -> V_33 |= V_92 ;
if ( V_74 != NULL )
V_5 -> V_93 = * V_74 ;
if ( V_81 != NULL )
V_5 -> V_94 = * V_81 ;
if ( type == V_95 )
V_5 -> V_96 = V_74 -> V_97 ;
V_82 = F_52 ( V_71 , & V_5 , V_74 , V_37 ) ;
if ( F_48 ( V_82 != V_98 ) )
GOTO ( V_99 , V_82 ) ;
if ( V_74 != NULL )
* V_74 = V_5 -> V_93 ;
if ( V_5 -> V_100 )
V_5 -> V_100 ( V_5 , * V_37 , NULL ) ;
F_7 ( V_5 , L_21 ) ;
V_99:
F_53 ( V_5 ) ;
V_89:
return V_82 ;
}
static void F_54 ( struct V_70 * V_71 ,
struct V_4 * V_5 , int V_75 )
{
int V_101 = 0 ;
F_44 ( V_5 ) ;
if ( ( V_5 -> V_102 != V_5 -> V_103 ) &&
! ( V_5 -> V_33 & V_35 ) ) {
V_5 -> V_33 |= V_104 | V_35 |
V_92 | V_57 ;
V_101 = 1 ;
}
F_39 ( V_5 ) ;
if ( V_101 )
F_7 ( V_5 ,
L_22
L_23 ) ;
else
F_7 ( V_5 , L_24 ) ;
F_55 ( V_5 , V_75 ) ;
if ( V_5 -> V_43 -> V_105 == V_106 ) {
F_44 ( V_5 ) ;
F_56 ( V_5 ) ;
F_57 ( V_5 ) ;
F_39 ( V_5 ) ;
}
}
int F_58 ( struct V_107 * exp , struct V_108 * V_109 ,
T_4 type , T_10 V_110 , T_6 V_75 ,
T_2 * V_37 , void * V_111 , T_3 V_79 ,
struct V_60 * V_61 , int V_46 )
{
struct V_70 * V_71 = exp -> V_18 -> V_112 ;
int V_113 = * V_37 & V_88 ;
struct V_4 * V_5 ;
struct V_114 * V_115 ;
int V_116 = 1 ;
int V_117 = 0 ;
V_5 = F_59 ( V_61 ) ;
if ( ! V_5 ) {
F_47 ( type == V_106 ) ;
return - V_118 ;
}
F_60 ( F_61 ( V_79 != 0 , V_79 == V_5 -> V_119 ) ,
L_25 , V_79 , V_5 -> V_119 ) ;
if ( V_46 != V_98 ) {
F_47 ( ! V_113 ) ;
F_7 ( V_5 , L_26 ,
V_46 == V_120 ? L_27 : L_28 ) ;
if ( V_46 != V_120 )
GOTO ( V_121 , V_46 ) ;
}
V_115 = F_62 ( & V_109 -> V_122 , & V_123 ) ;
if ( V_115 == NULL )
GOTO ( V_121 , V_46 = - V_124 ) ;
if ( V_79 != 0 ) {
F_47 ( V_111 != NULL ) ;
V_117 = F_63 ( & V_109 -> V_122 , & V_125 ,
V_126 ) ;
if ( V_117 < 0 ) {
F_15 ( V_5 , L_29 , V_117 ) ;
GOTO ( V_121 , V_46 = V_117 ) ;
} else if ( F_48 ( V_117 > V_79 ) ) {
F_15 ( V_5 , L_30
L_31 ,
V_79 , V_117 ) ;
GOTO ( V_121 , V_46 = - V_127 ) ;
}
}
if ( V_46 == V_120 ) {
if ( V_79 != 0 )
V_46 = F_64 ( V_5 , & V_109 -> V_122 , V_126 ,
V_111 , V_117 ) ;
GOTO ( V_121 , V_46 = ( V_46 != 0 ? V_46 : V_120 ) ) ;
}
V_116 = 0 ;
F_44 ( V_5 ) ;
if ( exp -> V_128 ) {
F_65 ( exp -> V_128 ,
& V_5 -> V_129 ,
& V_115 -> V_130 ,
& V_5 -> V_131 ) ;
} else {
V_5 -> V_129 = V_115 -> V_130 ;
}
* V_37 = F_66 ( V_115 -> V_132 ) ;
V_5 -> V_33 |= F_66 ( V_115 -> V_132 &
V_133 ) ;
V_5 -> V_33 |= F_66 ( V_115 -> V_132 &
V_48 ) ;
F_39 ( V_5 ) ;
F_67 ( V_134 , L_32 V_135 L_33 ,
V_5 , V_115 -> V_130 . V_136 , * V_37 ) ;
if ( ( * V_37 ) & V_137 ) {
int V_138 = V_115 -> V_139 . V_102 ;
F_47 ( ! V_113 ) ;
if ( V_138 && V_138 != V_5 -> V_102 ) {
F_7 ( V_5 , L_34 ,
V_140 [ V_138 ] ) ;
V_5 -> V_102 = V_138 ;
}
if ( memcmp ( V_115 -> V_139 . V_43 . V_141 . V_142 ,
V_5 -> V_43 -> V_141 . V_142 ,
sizeof( struct V_72 ) ) ) {
F_67 ( V_134 , L_35
L_36
L_37 ,
( long ) V_115 -> V_139 . V_43 . V_141 . V_142 [ 0 ] ,
( long ) V_115 -> V_139 . V_43 . V_141 . V_142 [ 1 ] ,
( long ) V_115 -> V_139 . V_43 . V_141 . V_142 [ 2 ] ,
( long ) V_5 -> V_43 -> V_141 . V_142 [ 0 ] ,
( long ) V_5 -> V_43 -> V_141 . V_142 [ 1 ] ,
( long ) V_5 -> V_43 -> V_141 . V_142 [ 2 ] ) ;
V_46 = F_68 ( V_71 , V_5 ,
& V_115 -> V_139 . V_43 . V_141 ) ;
if ( V_46 || V_5 -> V_43 == NULL )
GOTO ( V_121 , V_46 = - V_90 ) ;
F_7 ( V_5 , L_38 ) ;
}
if ( V_110 )
if ( ! ( type == V_143 &&
! ( F_69 ( exp ) & V_144 ) ) )
F_70 ( exp ,
V_5 -> V_43 -> V_105 ,
& V_115 -> V_139 . V_93 ,
& V_5 -> V_93 ) ;
if ( type != V_145 )
F_7 ( V_5 , L_39 ) ;
}
if ( ( * V_37 ) & V_146 ||
( V_147 && type == V_95 ) ) {
F_44 ( V_5 ) ;
V_5 -> V_33 |= V_57 | V_148 ;
F_39 ( V_5 ) ;
F_7 ( V_5 , L_40 ) ;
}
if ( V_79 != 0 ) {
F_44 ( V_5 ) ;
if ( V_5 -> V_102 != V_5 -> V_103 )
V_46 = F_64 ( V_5 , & V_109 -> V_122 , V_126 ,
V_5 -> V_149 , V_117 ) ;
F_39 ( V_5 ) ;
if ( V_46 < 0 ) {
V_116 = 1 ;
GOTO ( V_121 , V_46 ) ;
}
}
if ( ! V_113 ) {
V_46 = F_52 ( V_71 , & V_5 , NULL , V_37 ) ;
if ( V_5 -> V_100 != NULL ) {
int V_82 = V_5 -> V_100 ( V_5 , * V_37 , NULL ) ;
if ( ! V_46 )
V_46 = V_82 ;
if ( V_46 )
V_116 = 1 ;
}
}
if ( V_79 && V_111 != NULL ) {
memcpy ( V_111 , V_5 -> V_149 , V_79 ) ;
}
F_7 ( V_5 , L_41 ) ;
V_121:
if ( V_116 == 1 && V_46 )
F_54 ( V_71 , V_5 , V_75 ) ;
F_71 ( V_5 ) ;
F_53 ( V_5 ) ;
return V_46 ;
}
static inline int F_72 ( int V_150 , int V_151 )
{
int V_152 ;
V_152 = F_20 ( int , V_153 , V_154 - 512 ) - V_150 ;
if ( F_73 ( V_152 >= 0 ) )
V_152 /= ( int ) sizeof( struct V_60 ) ;
else
V_152 = 0 ;
V_152 += V_155 - V_151 ;
return V_152 ;
}
static inline int F_74 ( struct V_156 * V_157 ,
enum V_158 V_159 ,
int V_151 )
{
int V_117 = F_75 ( V_157 , V_159 ) ;
return F_72 ( V_117 , V_151 ) ;
}
static inline int F_76 ( struct V_7 * V_8 ,
const struct V_160 * V_161 ,
enum V_158 V_159 , int V_151 )
{
int V_117 = F_77 ( V_8 -> V_162 , V_161 , V_159 ) ;
return F_72 ( V_117 , V_151 ) ;
}
int F_78 ( struct V_107 * exp , struct V_108 * V_109 ,
int V_163 , int V_164 , int V_165 ,
struct V_166 * V_167 , int V_168 )
{
struct V_70 * V_71 = exp -> V_18 -> V_112 ;
struct V_156 * V_157 = & V_109 -> V_122 ;
struct V_169 * V_170 = NULL ;
int V_37 , V_152 , V_171 , V_172 = 0 ;
F_79 ( V_173 ) ;
int V_46 ;
if ( V_167 == NULL )
V_167 = & V_173 ;
if ( F_80 ( V_71 ) ) {
F_81 ( V_157 , V_174 ) ;
V_152 = F_74 ( V_157 , V_174 , V_165 ) ;
V_37 = F_82 ( V_71 ) ?
V_175 : V_176 ;
V_171 = ! F_82 ( V_71 ) &&
V_164 == V_177 ? 1 : 0 ;
if ( V_152 > V_168 )
V_168 += F_83 ( V_71 , V_167 , V_171 ,
V_152 - V_168 , 0 , V_37 ) ;
if ( V_152 > V_168 )
V_172 = V_168 ;
else
V_172 = V_152 ;
F_84 ( V_157 , & V_178 , V_174 ,
F_85 ( V_172 , V_164 ) ) ;
}
V_46 = F_86 ( V_109 , V_163 , V_164 ) ;
if ( V_46 ) {
F_87 ( V_167 , V_179 , V_168 ) ;
return V_46 ;
}
if ( F_80 ( V_71 ) ) {
if ( V_165 ) {
V_170 = F_88 ( V_157 , & V_178 ) ;
F_47 ( V_170 ) ;
V_170 -> V_180 = V_165 ;
}
F_89 ( V_167 , V_172 , V_109 , 0 ) ;
F_89 ( V_167 , V_168 - V_172 , NULL , 0 ) ;
} else {
F_87 ( V_167 , V_179 , V_168 ) ;
}
return 0 ;
}
int F_90 ( struct V_107 * exp , struct V_108 * V_109 ,
struct V_166 * V_167 , int V_168 )
{
return F_78 ( exp , V_109 , V_181 , V_177 ,
V_182 , V_167 , V_168 ) ;
}
struct V_108 * F_91 ( struct V_107 * exp , int V_79 )
{
struct V_108 * V_109 ;
int V_46 ;
V_109 = F_92 ( F_93 ( exp ) , & V_183 ) ;
if ( V_109 == NULL )
return F_94 ( - V_90 ) ;
V_46 = F_90 ( exp , V_109 , NULL , 0 ) ;
if ( V_46 ) {
F_95 ( V_109 ) ;
return F_94 ( V_46 ) ;
}
F_84 ( & V_109 -> V_122 , & V_125 , V_126 , V_79 ) ;
F_96 ( V_109 ) ;
return V_109 ;
}
int F_97 ( struct V_107 * exp , struct V_108 * * V_68 ,
struct V_184 * V_185 ,
const struct V_72 * V_73 ,
T_5 const * V_74 , T_2 * V_37 ,
void * V_111 , T_3 V_79 , enum V_80 V_80 ,
struct V_60 * V_61 , int V_186 )
{
struct V_70 * V_71 ;
struct V_4 * V_5 ;
struct V_169 * V_187 ;
int V_113 = * V_37 & V_88 ;
int V_188 = 1 ;
int V_46 , V_82 ;
struct V_108 * V_109 ;
F_47 ( exp != NULL ) ;
V_71 = exp -> V_18 -> V_112 ;
if ( V_113 ) {
V_5 = F_98 ( V_61 , 0 ) ;
F_47 ( V_5 != NULL ) ;
F_7 ( V_5 , L_42 ) ;
F_47 ( exp == V_5 -> V_11 ) ;
} else {
const struct V_83 V_84 = {
. V_85 = V_185 -> V_189 ,
. V_86 = V_185 -> V_190 ,
. V_87 = V_185 -> V_191
} ;
V_5 = F_50 ( V_71 , V_73 , V_185 -> V_192 ,
V_185 -> V_193 , & V_84 , V_185 -> V_194 ,
V_79 , V_80 ) ;
if ( V_5 == NULL )
return - V_90 ;
F_99 ( V_5 , V_185 -> V_193 ) ;
F_40 ( V_5 , V_61 ) ;
if ( V_74 != NULL ) {
if ( V_185 -> V_192 == V_143 &&
! ( F_69 ( exp ) &
V_144 ) )
V_5 -> V_93 . V_195 . V_196 =
V_197 |
V_198 ;
else
V_5 -> V_93 = * V_74 ;
}
if ( V_185 -> V_192 == V_95 )
V_5 -> V_96 = V_74 -> V_97 ;
F_7 ( V_5 , L_43 ,
* V_37 ) ;
}
V_5 -> V_11 = exp ;
V_5 -> V_199 = NULL ;
V_5 -> V_67 = V_185 -> V_190 ;
V_5 -> V_33 |= ( * V_37 & V_200 ) ;
if ( V_68 == NULL || * V_68 == NULL ) {
V_109 = F_100 ( F_93 ( exp ) ,
& V_183 ,
V_181 ,
V_177 ) ;
if ( V_109 == NULL ) {
F_54 ( V_71 , V_5 , V_185 -> V_193 ) ;
F_53 ( V_5 ) ;
return - V_90 ;
}
V_188 = 0 ;
if ( V_68 )
* V_68 = V_109 ;
} else {
int V_201 ;
V_109 = * V_68 ;
V_201 = F_63 ( & V_109 -> V_122 , & V_178 ,
V_174 ) ;
F_60 ( V_201 >= sizeof( * V_187 ) , L_44 ,
V_202 , V_201 , ( int ) sizeof( * V_187 ) ) ;
}
V_187 = F_88 ( & V_109 -> V_122 , & V_178 ) ;
F_101 ( V_5 , & V_187 -> V_139 ) ;
V_187 -> V_132 = F_102 ( * V_37 ) ;
V_187 -> V_130 [ 0 ] = * V_61 ;
if ( ! V_188 ) {
if ( V_79 > 0 )
F_103 ( & V_109 -> V_122 ,
& V_203 ) ;
F_84 ( & V_109 -> V_122 , & V_125 , V_126 ,
V_79 ) ;
F_96 ( V_109 ) ;
}
F_47 ( F_61 ( V_147 , V_185 -> V_192 != V_95 ||
V_74 -> V_97 . V_204 == V_205 ) ) ;
if ( V_186 ) {
F_47 ( V_68 != NULL ) ;
return 0 ;
}
F_7 ( V_5 , L_45 ) ;
V_46 = F_104 ( V_109 ) ;
V_82 = F_58 ( exp , V_109 , V_185 -> V_192 , V_74 ? 1 : 0 ,
V_185 -> V_193 , V_37 , V_111 , V_79 ,
V_61 , V_46 ) ;
if ( V_82 == - V_118 )
F_53 ( V_5 ) ;
else
V_46 = V_82 ;
if ( ! V_188 && V_109 != NULL ) {
F_105 ( V_109 ) ;
if ( V_68 )
* V_68 = NULL ;
}
return V_46 ;
}
static int F_106 ( struct V_4 * V_5 , int V_206 ,
T_3 * V_37 )
{
struct V_207 * V_208 ;
int V_46 ;
if ( F_34 ( F_12 ( V_5 ) ) ) {
F_42 ( L_46 ) ;
F_49 () ;
}
F_7 ( V_5 , L_47 ) ;
V_208 = F_107 ( V_5 , V_206 , V_37 ) ;
if ( V_208 ) {
F_26 ( V_208 ) ;
V_46 = 0 ;
} else {
V_46 = V_209 ;
}
F_7 ( V_5 , L_48 ) ;
F_71 ( V_5 ) ;
return V_46 ;
}
int F_108 ( struct V_60 * V_61 , int V_206 , T_3 * V_37 )
{
struct V_169 * V_187 ;
struct V_114 * V_115 ;
struct V_4 * V_5 ;
struct V_207 * V_208 ;
struct V_108 * V_109 ;
int V_46 ;
V_5 = F_59 ( V_61 ) ;
if ( ! V_5 ) {
F_49 () ;
return - V_127 ;
}
* V_37 = 0 ;
if ( V_5 -> V_11 == NULL )
return F_106 ( V_5 , V_206 , V_37 ) ;
F_7 ( V_5 , L_49 ) ;
V_109 = F_100 ( F_93 ( V_5 -> V_11 ) ,
& V_210 , V_181 ,
V_211 ) ;
if ( V_109 == NULL ) {
F_71 ( V_5 ) ;
return - V_90 ;
}
V_187 = F_88 ( & V_109 -> V_122 , & V_178 ) ;
V_187 -> V_130 [ 0 ] = V_5 -> V_129 ;
V_187 -> V_139 . V_102 = V_206 ;
V_187 -> V_132 = F_102 ( * V_37 ) ;
F_96 ( V_109 ) ;
V_46 = F_104 ( V_109 ) ;
if ( V_46 != V_98 )
GOTO ( V_99 , V_46 ) ;
V_115 = F_62 ( & V_109 -> V_122 , & V_123 ) ;
if ( V_115 == NULL )
GOTO ( V_99 , V_46 = - V_124 ) ;
if ( V_109 -> V_212 )
GOTO ( V_99 , V_46 = V_109 -> V_212 ) ;
V_208 = F_107 ( V_5 , V_206 , & V_115 -> V_132 ) ;
if ( V_208 != NULL ) {
F_26 ( V_208 ) ;
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
F_71 ( V_5 ) ;
F_105 ( V_109 ) ;
return V_46 ;
}
static T_2 F_109 ( struct V_4 * V_5 )
{
T_2 V_46 = V_104 ;
if ( V_5 -> V_11 ) {
bool V_213 ;
F_7 ( V_5 , L_50 ) ;
F_44 ( V_5 ) ;
V_5 -> V_33 |= V_57 ;
V_213 = ! ! ( V_5 -> V_33 &
( V_104 | V_214 ) ) ;
F_110 ( V_5 ) ;
V_46 = ( V_5 -> V_33 & V_148 ) ?
V_148 : V_215 ;
F_39 ( V_5 ) ;
if ( V_213 ) {
F_67 ( V_17 , L_51
L_52 ) ;
V_46 = V_104 ;
}
F_111 ( V_5 ) ;
} else {
if ( F_34 ( F_12 ( V_5 ) ) ) {
F_15 ( V_5 , L_53 ) ;
F_49 () ;
}
F_7 ( V_5 , L_54 ) ;
F_111 ( V_5 ) ;
F_26 ( V_5 -> V_43 ) ;
}
return V_46 ;
}
static void F_112 ( struct V_108 * V_109 ,
struct V_166 * V_173 , int V_168 )
{
struct V_169 * V_170 ;
struct V_4 * V_5 ;
int F_21 , V_216 = 0 ;
V_170 = F_88 ( & V_109 -> V_122 , & V_178 ) ;
F_47 ( V_170 != NULL ) ;
F_21 = F_63 ( & V_109 -> V_122 , & V_178 , V_174 ) -
sizeof( struct V_169 ) ;
F_21 /= sizeof( struct V_60 ) ;
F_21 += V_155 ;
F_47 ( F_21 >= V_170 -> V_180 + V_168 ) ;
F_113 (lock, head, l_bl_ast) {
if ( ! V_168 -- )
break;
F_47 ( V_5 -> V_11 ) ;
F_7 ( V_5 , L_55 ) ;
V_170 -> V_130 [ V_170 -> V_180 ++ ] = V_5 -> V_129 ;
V_216 ++ ;
}
F_67 ( V_17 , L_56 , V_216 ) ;
}
int F_114 ( struct V_107 * exp , struct V_166 * V_167 ,
int V_168 , T_11 V_37 )
{
struct V_108 * V_109 = NULL ;
struct V_7 * V_8 ;
int free , V_217 = 0 ;
int V_46 = 0 ;
F_47 ( exp != NULL ) ;
F_47 ( V_168 > 0 ) ;
F_115 ( V_218 , V_219 ) ;
if ( F_116 ( V_220 ) )
return V_168 ;
free = F_76 ( F_93 ( exp ) ,
& V_221 , V_174 , 0 ) ;
if ( V_168 > free )
V_168 = free ;
while ( 1 ) {
V_8 = F_93 ( exp ) ;
if ( V_8 == NULL || V_8 -> V_222 ) {
F_67 ( V_17 ,
L_57 , V_8 ) ;
return V_168 ;
}
V_109 = F_92 ( V_8 , & V_221 ) ;
if ( V_109 == NULL )
GOTO ( V_99 , V_46 = - V_90 ) ;
F_81 ( & V_109 -> V_122 , V_174 ) ;
F_84 ( & V_109 -> V_122 , & V_178 , V_174 ,
F_85 ( V_168 , V_223 ) ) ;
V_46 = F_86 ( V_109 , V_181 , V_223 ) ;
if ( V_46 ) {
F_95 ( V_109 ) ;
GOTO ( V_99 , V_46 ) ;
}
V_109 -> V_224 = V_225 ;
V_109 -> V_226 = V_227 ;
F_117 ( V_109 ) ;
F_112 ( V_109 , V_167 , V_168 ) ;
F_96 ( V_109 ) ;
if ( V_37 & V_62 ) {
F_118 ( V_109 , V_228 , - 1 ) ;
V_217 = V_168 ;
GOTO ( V_99 , 0 ) ;
} else {
V_46 = F_104 ( V_109 ) ;
}
if ( V_46 == V_229 ) {
F_67 ( V_17 , L_58
L_59 ,
F_119 ( V_109 -> V_230 ->
V_23 -> V_231 . V_232 ) ) ;
V_46 = 0 ;
} else if ( V_46 == - V_233 &&
V_109 -> V_234 == V_8 -> V_235 ) {
F_105 ( V_109 ) ;
continue;
} else if ( V_46 != V_98 ) {
F_120 ( V_46 == - V_236 ? V_17 : V_237 ,
L_60
L_61 , V_46 ) ;
break;
}
V_217 = V_168 ;
break;
}
F_105 ( V_109 ) ;
V_99:
return V_217 ? V_217 : V_46 ;
}
static inline struct V_238 * F_121 ( struct V_7 * V_8 )
{
F_47 ( V_8 != NULL ) ;
return & V_8 -> V_239 -> V_112 -> V_240 ;
}
int F_122 ( struct V_108 * V_109 )
{
struct V_9 * V_10 ;
T_2 V_241 ;
T_3 V_242 ;
if ( F_48 ( ! V_109 -> V_230 || ! V_109 -> V_230 -> V_239 ||
! F_123 ( V_109 -> V_230 ) ) )
{
return 0 ;
}
if ( F_124 ( V_109 -> V_243 ) == 0 ||
F_125 ( V_109 -> V_243 ) == 0 ) {
F_126 ( V_244 , V_109 , L_62
L_63 V_245 L_64 ,
F_124 ( V_109 -> V_243 ) ,
F_125 ( V_109 -> V_243 ) ) ;
return 0 ;
}
V_242 = F_125 ( V_109 -> V_243 ) ;
V_241 = F_124 ( V_109 -> V_243 ) ;
V_10 = V_109 -> V_230 -> V_239 ;
F_127 ( & V_10 -> V_246 ) ;
V_10 -> V_247 = V_241 ;
V_10 -> V_248 = V_242 ;
F_128 ( & V_10 -> V_246 ) ;
return 0 ;
}
int F_41 ( struct V_60 * V_61 ,
T_11 V_249 )
{
struct V_107 * exp ;
int V_152 , V_37 , V_168 = 1 ;
T_2 V_46 = 0 ;
struct V_70 * V_71 ;
struct V_4 * V_5 ;
F_79 ( V_167 ) ;
V_5 = F_98 ( V_61 , V_215 ) ;
if ( V_5 == NULL ) {
F_129 ( L_65 ) ;
return 0 ;
}
V_46 = F_109 ( V_5 ) ;
if ( V_46 == V_104 ) {
F_53 ( V_5 ) ;
return 0 ;
}
F_47 ( F_130 ( & V_5 -> V_179 ) ) ;
F_131 ( & V_5 -> V_179 , & V_167 ) ;
exp = V_5 -> V_11 ;
if ( F_132 ( exp ) ) {
V_152 = F_76 ( F_93 ( exp ) ,
& V_221 ,
V_174 , 0 ) ;
F_47 ( V_152 > 0 ) ;
V_71 = F_12 ( V_5 ) ;
V_37 = F_82 ( V_71 ) ?
V_175 : V_176 ;
V_168 += F_83 ( V_71 , & V_167 , 0 , V_152 - 1 ,
V_250 , V_37 ) ;
}
F_89 ( & V_167 , V_168 , NULL , V_249 ) ;
return 0 ;
}
int F_133 ( struct V_166 * V_167 , int V_168 ,
T_11 V_37 )
{
F_79 ( V_173 ) ;
struct V_4 * V_5 , * V_251 ;
int V_252 = 0 , V_253 = 0 ;
T_2 V_46 ;
V_252 = V_168 ;
F_134 (lock, next, cancels, l_bl_ast) {
if ( V_252 -- == 0 )
break;
if ( V_37 & V_254 ) {
V_46 = V_104 ;
F_111 ( V_5 ) ;
} else {
V_46 = F_109 ( V_5 ) ;
}
if ( ! ( V_37 & V_250 ) && ( V_46 == V_148 ) ) {
F_7 ( V_5 , L_66 ) ;
F_135 ( & V_5 -> V_179 ) ;
F_131 ( & V_5 -> V_179 , & V_173 ) ;
V_253 ++ ;
continue;
}
if ( V_46 == V_104 ) {
F_135 ( & V_5 -> V_179 ) ;
F_53 ( V_5 ) ;
V_168 -- ;
}
}
if ( V_253 > 0 ) {
V_168 -= V_253 ;
F_89 ( & V_173 , V_253 , NULL , 0 ) ;
}
return V_168 ;
}
static T_12 F_136 ( struct V_70 * V_71 ,
struct V_4 * V_5 ,
int V_255 , int V_256 ,
int V_168 )
{
T_12 V_32 = V_257 ;
T_13 V_258 = V_71 -> V_259 ;
F_44 ( V_5 ) ;
switch ( V_5 -> V_43 -> V_105 ) {
case V_95 :
case V_143 :
if ( V_258 && V_258 ( V_5 ) )
break;
default:
V_32 = V_260 ;
V_5 -> V_33 |= V_261 ;
break;
}
F_39 ( V_5 ) ;
return V_32 ;
}
static T_12 F_137 ( struct V_70 * V_71 ,
struct V_4 * V_5 ,
int V_255 , int V_256 ,
int V_168 )
{
T_1 V_262 = F_9 () ;
struct V_238 * V_263 = & V_71 -> V_240 ;
T_2 V_264 , V_265 , V_266 ;
T_1 V_267 ;
if ( V_168 && V_256 >= V_168 )
return V_268 ;
V_264 = F_138 ( V_263 ) ;
V_265 = F_139 ( V_263 ) ;
V_267 = F_140 ( F_5 ( V_262 ,
V_5 -> V_269 ) ) ;
V_266 = V_265 * V_267 * V_255 ;
F_141 ( V_263 , V_266 ) ;
return ( V_264 == 0 || V_266 < V_264 ) ?
V_268 : V_257 ;
}
static T_12 F_142 ( struct V_70 * V_71 ,
struct V_4 * V_5 ,
int V_255 , int V_256 ,
int V_168 )
{
return ( V_256 >= V_168 ) ?
V_268 : V_257 ;
}
static T_12 F_143 ( struct V_70 * V_71 ,
struct V_4 * V_5 ,
int V_255 , int V_256 ,
int V_168 )
{
return ( ( V_256 >= V_168 ) &&
F_144 ( F_9 () ,
F_145 ( V_5 -> V_269 ,
V_71 -> V_270 ) ) ) ?
V_268 : V_257 ;
}
static T_12 F_146 ( struct V_70 * V_71 ,
struct V_4 * V_5 ,
int V_255 , int V_256 ,
int V_168 )
{
return ( V_256 >= V_168 ) ?
V_268 : V_257 ;
}
static T_14
F_147 ( struct V_70 * V_71 , int V_37 )
{
if ( V_37 & V_271 )
return F_136 ;
if ( F_82 ( V_71 ) ) {
if ( V_37 & V_272 )
return F_142 ;
else if ( V_37 & V_175 )
return F_137 ;
else if ( V_37 & V_273 )
return F_142 ;
} else {
if ( V_37 & V_176 )
return F_143 ;
}
return F_146 ;
}
static int F_148 ( struct V_70 * V_71 , struct V_166 * V_167 ,
int V_168 , int F_21 , int V_37 )
{
T_14 V_274 ;
struct V_4 * V_5 , * V_251 ;
int V_256 = 0 , V_255 , V_275 ;
F_32 ( & V_71 -> V_276 ) ;
V_255 = V_71 -> V_277 ;
V_275 = V_255 ;
if ( ! F_82 ( V_71 ) )
V_168 += V_255 - V_71 -> V_278 ;
V_274 = F_147 ( V_71 , V_37 ) ;
F_47 ( V_274 != NULL ) ;
while ( ! F_130 ( & V_71 -> V_279 ) ) {
T_12 V_32 ;
if ( V_275 -- <= 0 )
break;
if ( F_21 && V_256 >= F_21 )
break;
F_134 (lock, next, &ns->ns_unused_list,
l_lru) {
F_47 ( ! ( V_5 -> V_33 & V_148 ) ) ;
if ( V_37 & V_271 &&
V_5 -> V_33 & V_261 )
continue;
if ( ! ( V_5 -> V_33 & V_215 ) )
break;
F_149 ( V_5 ) ;
}
if ( & V_5 -> V_280 == & V_71 -> V_279 )
break;
F_150 ( V_5 ) ;
F_33 ( & V_71 -> V_276 ) ;
F_151 ( & V_5 -> V_281 , V_282 , V_283 ) ;
V_32 = V_274 ( V_71 , V_5 , V_255 , V_256 , V_168 ) ;
if ( V_32 == V_268 ) {
F_152 ( & V_5 -> V_281 ,
V_282 , V_283 ) ;
F_53 ( V_5 ) ;
F_32 ( & V_71 -> V_276 ) ;
break;
}
if ( V_32 == V_260 ) {
F_152 ( & V_5 -> V_281 ,
V_284 , V_283 ) ;
F_53 ( V_5 ) ;
F_32 ( & V_71 -> V_276 ) ;
continue;
}
F_44 ( V_5 ) ;
if ( ( V_5 -> V_33 & V_215 ) ||
( F_153 ( V_5 ) == 0 ) ) {
F_39 ( V_5 ) ;
F_152 ( & V_5 -> V_281 ,
V_282 , V_283 ) ;
F_53 ( V_5 ) ;
F_32 ( & V_71 -> V_276 ) ;
continue;
}
F_47 ( ! V_5 -> V_58 && ! V_5 -> V_59 ) ;
V_5 -> V_33 &= ~ V_214 ;
V_5 -> V_33 |= V_57 | V_215 ;
F_47 ( F_130 ( & V_5 -> V_179 ) ) ;
F_131 ( & V_5 -> V_179 , V_167 ) ;
F_39 ( V_5 ) ;
F_152 ( & V_5 -> V_281 , V_282 , V_283 ) ;
F_32 ( & V_71 -> V_276 ) ;
V_256 ++ ;
V_255 -- ;
}
F_33 ( & V_71 -> V_276 ) ;
return V_256 ;
}
int F_83 ( struct V_70 * V_71 , struct V_166 * V_167 ,
int V_168 , int F_21 , T_11 V_249 ,
int V_37 )
{
int V_256 ;
V_256 = F_148 ( V_71 , V_167 , V_168 , F_21 , V_37 ) ;
if ( V_256 <= 0 )
return V_256 ;
return F_133 ( V_167 , V_256 , V_249 ) ;
}
int F_154 ( struct V_70 * V_71 , int V_285 ,
T_11 V_249 ,
int V_37 )
{
F_79 ( V_167 ) ;
int V_168 , V_46 ;
V_168 = F_148 ( V_71 , & V_167 , V_285 , 0 , V_37 ) ;
V_46 = F_155 ( V_71 , NULL , & V_167 , V_168 , V_249 ) ;
if ( V_46 == 0 )
return V_168 ;
return 0 ;
}
int F_156 ( struct V_207 * V_208 ,
struct V_166 * V_167 ,
T_5 * V_74 ,
T_6 V_75 , int V_132 ,
T_11 V_249 , void * V_286 )
{
struct V_4 * V_5 ;
int V_168 = 0 ;
F_157 ( V_208 ) ;
F_113 (lock, &res->lr_granted, l_res_link) {
if ( V_286 != NULL && V_5 -> V_287 != V_286 ) {
F_15 ( V_5 , L_67 ,
V_5 -> V_287 , V_286 ) ;
continue;
}
if ( V_5 -> V_58 || V_5 -> V_59 )
continue;
if ( V_5 -> V_33 & V_148 ||
V_5 -> V_33 & V_215 )
continue;
if ( F_158 ( V_5 -> V_103 , V_75 ) )
continue;
if ( V_74 && ( V_5 -> V_43 -> V_105 == V_143 ) &&
! ( V_5 -> V_93 . V_195 . V_196 &
V_74 -> V_195 . V_196 ) )
continue;
V_5 -> V_33 |= V_57 | V_215 |
V_132 ;
F_47 ( F_130 ( & V_5 -> V_179 ) ) ;
F_131 ( & V_5 -> V_179 , V_167 ) ;
F_150 ( V_5 ) ;
V_168 ++ ;
}
F_159 ( V_208 ) ;
return F_133 ( V_167 , V_168 , V_249 ) ;
}
int F_89 ( struct V_166 * V_167 , int V_168 ,
struct V_108 * V_109 , T_11 V_37 )
{
struct V_4 * V_5 ;
int V_208 = 0 ;
if ( F_130 ( V_167 ) || V_168 == 0 )
return 0 ;
while ( V_168 > 0 ) {
F_47 ( ! F_130 ( V_167 ) ) ;
V_5 = F_160 ( V_167 -> V_251 , struct V_4 ,
V_179 ) ;
F_47 ( V_5 -> V_11 ) ;
if ( F_132 ( V_5 -> V_11 ) ) {
V_208 = V_168 ;
if ( V_109 )
F_112 ( V_109 , V_167 , V_168 ) ;
else
V_208 = F_114 ( V_5 -> V_11 ,
V_167 , V_168 ,
V_37 ) ;
} else {
V_208 = F_114 ( V_5 -> V_11 ,
V_167 , 1 , V_37 ) ;
}
if ( V_208 < 0 ) {
F_120 ( V_208 == - V_236 ? V_17 : V_237 ,
L_68 , V_208 ) ;
V_208 = V_168 ;
}
V_168 -= V_208 ;
F_87 ( V_167 , V_179 , V_208 ) ;
}
F_47 ( V_168 == 0 ) ;
return 0 ;
}
int F_161 ( struct V_70 * V_71 ,
const struct V_72 * V_73 ,
T_5 * V_74 ,
T_6 V_75 ,
T_11 V_37 ,
void * V_286 )
{
struct V_207 * V_208 ;
F_79 ( V_167 ) ;
int V_168 ;
int V_46 ;
V_208 = F_162 ( V_71 , NULL , V_73 , 0 , 0 ) ;
if ( V_208 == NULL ) {
F_67 ( V_134 , L_69 V_245 L_70 , V_73 -> V_142 [ 0 ] ) ;
return 0 ;
}
F_163 ( V_208 ) ;
V_168 = F_156 ( V_208 , & V_167 , V_74 , V_75 ,
0 , V_37 | V_250 , V_286 ) ;
V_46 = F_89 ( & V_167 , V_168 , NULL , V_37 ) ;
if ( V_46 != V_98 )
F_42 ( L_71 , V_46 ) ;
F_164 ( V_208 ) ;
F_165 ( V_208 ) ;
return 0 ;
}
static int F_166 ( T_15 * V_288 , T_16 * V_289 ,
struct V_290 * V_291 , void * V_292 )
{
struct V_207 * V_208 = F_167 ( V_288 , V_291 ) ;
struct V_293 * V_294 = V_292 ;
int V_46 ;
V_46 = F_161 ( F_168 ( V_208 ) , & V_208 -> V_141 ,
NULL , V_295 ,
V_294 -> V_296 , V_294 -> V_297 ) ;
if ( V_46 != 0 ) {
F_42 ( L_72 V_245 L_73 ,
V_208 -> V_141 . V_142 [ 0 ] , V_46 ) ;
}
return 0 ;
}
int F_169 ( struct V_70 * V_71 ,
const struct V_72 * V_73 ,
T_11 V_37 , void * V_286 )
{
struct V_293 V_292 = {
. V_296 = V_37 ,
. V_297 = V_286 ,
} ;
if ( V_71 == NULL )
return V_98 ;
if ( V_73 != NULL ) {
return F_161 ( V_71 , V_73 , NULL ,
V_295 , V_37 ,
V_286 ) ;
} else {
F_170 ( V_71 -> V_298 ,
F_166 , & V_292 ) ;
return V_98 ;
}
}
int F_171 ( struct V_207 * V_208 , T_17 V_299 ,
void * V_300 )
{
struct V_166 * V_301 , * V_251 ;
struct V_4 * V_5 ;
int V_46 = V_302 ;
if ( ! V_208 )
return V_302 ;
F_157 ( V_208 ) ;
F_172 (tmp, next, &res->lr_granted) {
V_5 = F_160 ( V_301 , struct V_4 , V_303 ) ;
if ( V_299 ( V_5 , V_300 ) == V_304 )
GOTO ( V_99 , V_46 = V_304 ) ;
}
F_172 (tmp, next, &res->lr_converting) {
V_5 = F_160 ( V_301 , struct V_4 , V_303 ) ;
if ( V_299 ( V_5 , V_300 ) == V_304 )
GOTO ( V_99 , V_46 = V_304 ) ;
}
F_172 (tmp, next, &res->lr_waiting) {
V_5 = F_160 ( V_301 , struct V_4 , V_303 ) ;
if ( V_299 ( V_5 , V_300 ) == V_304 )
GOTO ( V_99 , V_46 = V_304 ) ;
}
V_99:
F_159 ( V_208 ) ;
return V_46 ;
}
static int F_173 ( struct V_4 * V_5 , void * V_300 )
{
struct V_305 * V_306 = V_300 ;
return V_306 -> V_299 ( V_5 , V_306 -> V_300 ) ;
}
static int F_174 ( T_15 * V_288 , T_16 * V_289 ,
struct V_290 * V_291 , void * V_292 )
{
struct V_207 * V_208 = F_167 ( V_288 , V_291 ) ;
return F_171 ( V_208 , F_173 , V_292 ) ==
V_304 ;
}
void F_175 ( struct V_70 * V_71 ,
T_17 V_299 , void * V_300 )
{
struct V_305 V_306 = {
. V_299 = V_299 ,
. V_300 = V_300 ,
} ;
F_170 ( V_71 -> V_298 ,
F_174 , & V_306 ) ;
}
int F_176 ( struct V_70 * V_71 ,
const struct V_72 * V_73 ,
T_17 V_299 , void * V_1 )
{
struct V_207 * V_208 ;
int V_46 ;
if ( V_71 == NULL ) {
F_42 ( L_74 ) ;
F_49 () ;
}
V_208 = F_162 ( V_71 , NULL , V_73 , 0 , 0 ) ;
if ( V_208 == NULL )
return 0 ;
F_163 ( V_208 ) ;
V_46 = F_171 ( V_208 , V_299 , V_1 ) ;
F_164 ( V_208 ) ;
F_165 ( V_208 ) ;
return V_46 ;
}
static int F_177 ( struct V_4 * V_5 , void * V_300 )
{
struct V_166 * V_307 = V_300 ;
F_60 ( F_130 ( & V_5 -> V_308 ) ,
L_75 ,
V_5 , & V_5 -> V_308 . V_251 , & V_5 -> V_308 . V_309 ) ;
if ( ! ( V_5 -> V_33 & ( V_35 | V_215 ) ) ) {
F_131 ( & V_5 -> V_308 , V_307 ) ;
F_150 ( V_5 ) ;
}
return V_302 ;
}
static int F_178 ( const struct V_310 * V_311 ,
struct V_108 * V_109 ,
struct V_312 * V_313 , int V_46 )
{
struct V_4 * V_5 ;
struct V_114 * V_115 ;
struct V_107 * exp ;
F_179 ( & V_109 -> V_230 -> V_314 ) ;
if ( V_46 != V_98 )
GOTO ( V_99 , V_46 ) ;
V_115 = F_62 ( & V_109 -> V_122 , & V_123 ) ;
if ( V_115 == NULL )
GOTO ( V_99 , V_46 = - V_124 ) ;
V_5 = F_59 ( & V_313 -> V_130 ) ;
if ( ! V_5 ) {
F_42 ( L_76 V_135
L_77 V_135 L_78 ,
V_313 -> V_130 . V_136 , V_115 -> V_130 . V_136 ,
V_109 -> V_315 -> V_316 . V_25 ,
F_180 ( V_109 -> V_317 ) ) ;
GOTO ( V_99 , V_46 = - V_318 ) ;
}
exp = V_109 -> V_315 ;
if ( exp && exp -> V_128 ) {
F_65 ( exp -> V_128 ,
& V_5 -> V_129 ,
& V_115 -> V_130 ,
& V_5 -> V_131 ) ;
} else {
V_5 -> V_129 = V_115 -> V_130 ;
}
F_7 ( V_5 , L_79 ) ;
F_181 ( V_109 -> V_230 ) ;
F_71 ( V_5 ) ;
V_99:
if ( V_46 != V_98 )
F_182 ( V_109 -> V_230 ) ;
return V_46 ;
}
static int F_183 ( struct V_7 * V_8 , struct V_4 * V_5 )
{
struct V_108 * V_109 ;
struct V_312 * V_313 ;
struct V_169 * V_187 ;
int V_37 ;
if ( V_5 -> V_33 & V_215 ) {
F_7 ( V_5 , L_80 ) ;
return 0 ;
}
if ( V_5 -> V_33 & V_214 ) {
F_7 ( V_5 , L_81 ) ;
F_111 ( V_5 ) ;
return 0 ;
}
if ( V_5 -> V_103 == V_5 -> V_102 )
V_37 = V_88 | V_40 ;
else if ( V_5 -> V_103 )
V_37 = V_88 | V_41 ;
else if ( ! F_130 ( & V_5 -> V_303 ) )
V_37 = V_88 | V_39 ;
else
V_37 = V_88 ;
V_109 = F_100 ( V_8 , & V_183 ,
V_181 , V_177 ) ;
if ( V_109 == NULL )
return - V_90 ;
V_109 -> V_319 = V_320 ;
V_187 = F_88 ( & V_109 -> V_122 , & V_178 ) ;
F_101 ( V_5 , & V_187 -> V_139 ) ;
V_187 -> V_132 = F_102 ( V_37 ) ;
F_40 ( V_5 , & V_187 -> V_130 [ 0 ] ) ;
if ( V_5 -> V_119 > 0 )
F_103 ( & V_109 -> V_122 , & V_203 ) ;
F_84 ( & V_109 -> V_122 , & V_125 , V_126 ,
V_5 -> V_119 ) ;
F_96 ( V_109 ) ;
F_184 ( V_109 -> V_321 , V_322 ) ;
F_7 ( V_5 , L_82 ) ;
F_185 ( & V_109 -> V_230 -> V_314 ) ;
F_186 ( sizeof( * V_313 ) <= sizeof( V_109 -> V_323 ) ) ;
V_313 = F_187 ( V_109 ) ;
V_313 -> V_130 = V_187 -> V_130 [ 0 ] ;
V_109 -> V_324 = ( V_325 ) F_178 ;
F_118 ( V_109 , V_228 , - 1 ) ;
return 0 ;
}
static void F_188 ( struct V_70 * V_71 )
{
int V_326 ;
F_79 ( V_167 ) ;
F_67 ( V_17 , L_83
L_84 ,
F_189 ( V_71 ) , V_71 -> V_277 ) ;
V_326 = F_83 ( V_71 , & V_167 , V_71 -> V_277 , 0 ,
V_254 , V_271 ) ;
F_67 ( V_17 , L_85 ,
V_326 , F_189 ( V_71 ) ) ;
}
int F_190 ( struct V_7 * V_8 )
{
struct V_70 * V_71 = V_8 -> V_239 -> V_112 ;
F_79 ( V_307 ) ;
struct V_4 * V_5 , * V_251 ;
int V_46 = 0 ;
F_47 ( F_191 ( & V_8 -> V_314 ) == 0 ) ;
if ( V_8 -> V_327 )
return 0 ;
F_185 ( & V_8 -> V_314 ) ;
if ( V_328 )
F_188 ( V_71 ) ;
F_175 ( V_71 , F_177 , & V_307 ) ;
F_134 (lock, next, &list, l_pending_chain) {
F_135 ( & V_5 -> V_308 ) ;
if ( V_46 ) {
F_53 ( V_5 ) ;
continue;
}
V_46 = F_183 ( V_8 , V_5 ) ;
F_53 ( V_5 ) ;
}
F_179 ( & V_8 -> V_314 ) ;
return V_46 ;
}
