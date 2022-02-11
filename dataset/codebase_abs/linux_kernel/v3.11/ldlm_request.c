static void F_1 ( void * V_1 )
{
}
int F_2 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_11 ;
if ( V_5 -> V_12 == NULL ) {
static T_1 V_13 = 0 , V_14 = 0 ;
if ( F_3 () )
RETURN ( 0 ) ;
F_4 ( L_1 V_15 L_2
V_16 L_3 ,
V_5 -> V_17 ,
F_5 ( F_6 () ,
V_5 -> V_17 ) ) ;
F_7 ( V_5 , L_1 V_15 L_2
V_16 L_4
L_5 ,
V_5 -> V_17 ,
F_5 ( F_6 () ,
V_5 -> V_17 ) ) ;
if ( F_8 ( F_9 () , V_13 ) ) {
V_14 = V_13 ;
V_13 = F_10 ( 300 ) ;
F_11 ( V_18 ,
F_12 ( V_5 ) ) ;
if ( V_14 == 0 )
F_13 () ;
}
RETURN ( 0 ) ;
}
V_10 = V_5 -> V_12 -> V_19 ;
V_8 = V_10 -> V_20 . V_21 . V_22 ;
F_14 ( V_8 , V_3 -> V_23 ) ;
F_15 ( V_5 , L_1 V_15 L_2
V_16 L_6 ,
V_5 -> V_17 ,
F_5 ( F_6 () , V_5 -> V_17 ) ,
F_16 ( V_10 ) , V_8 -> V_24 -> V_25 . V_26 ) ;
RETURN ( 0 ) ;
}
int F_17 ( struct V_4 * V_5 )
{
int V_27 = F_18 ( F_19 ( V_5 ) ) ;
if ( V_28 )
return V_29 / 2 ;
V_27 = F_20 ( int , V_30 , V_27 + ( V_27 >> 1 ) ) ;
return F_21 ( V_27 , V_31 ) ;
}
static int F_22 ( struct V_4 * V_5 )
{
long V_32 ;
int V_33 ;
if ( V_5 -> V_34 || V_5 -> V_35 & V_36 ) {
F_7 ( V_5 , L_7 ) ;
V_33 = - V_37 ;
} else {
V_32 = F_5 ( F_6 () ,
V_5 -> V_17 ) ;
F_7 ( V_5 , L_8
V_16 L_9 , V_32 ) ;
F_23 ( F_19 ( V_5 ) ,
V_32 ) ;
V_33 = 0 ;
}
return V_33 ;
}
int F_24 ( struct V_4 * V_5 , T_2 V_38 , void * V_1 )
{
V_11 ;
if ( V_38 == V_39 ) {
F_7 ( V_5 , L_10 ) ;
RETURN ( 0 ) ;
}
if ( ! ( V_38 & ( V_40 | V_41 |
V_42 ) ) ) {
F_25 ( & V_5 -> V_43 ) ;
RETURN ( F_22 ( V_5 ) ) ;
}
F_7 ( V_5 , L_11
L_12 ) ;
F_26 ( V_5 -> V_44 ) ;
RETURN ( 0 ) ;
}
int F_27 ( struct V_4 * V_5 , T_2 V_38 , void * V_1 )
{
struct V_2 V_3 ;
struct V_9 * V_10 ;
struct V_7 * V_8 = NULL ;
struct V_45 V_46 ;
T_3 V_27 ;
int V_47 = 0 ;
V_11 ;
if ( V_38 == V_39 ) {
F_7 ( V_5 , L_10 ) ;
goto V_48;
}
if ( ! ( V_38 & ( V_40 | V_41 |
V_42 ) ) ) {
F_25 ( & V_5 -> V_43 ) ;
RETURN ( 0 ) ;
}
F_7 ( V_5 , L_11
L_13 ) ;
V_48:
V_10 = F_28 ( V_5 -> V_12 ) ;
if ( V_10 != NULL ) {
V_8 = V_10 -> V_20 . V_21 . V_22 ;
}
V_27 = F_17 ( V_5 ) * 2 ;
V_3 . V_6 = V_5 ;
if ( V_5 -> V_35 & V_49 ) {
F_7 ( V_5 , L_14 ) ;
V_46 = F_29 ( F_1 , & V_3 ) ;
} else {
V_46 = F_30 ( F_31 ( V_27 ) ,
F_2 ,
F_1 , & V_3 ) ;
}
if ( V_8 != NULL ) {
F_32 ( & V_8 -> V_50 ) ;
V_3 . V_23 = V_8 -> V_51 ;
F_33 ( & V_8 -> V_50 ) ;
}
if ( F_34 ( F_12 ( V_5 ) ) &&
F_35 ( V_52 ,
V_53 | V_54 ) ) {
V_5 -> V_35 |= V_55 ;
V_47 = - V_56 ;
} else {
V_47 = F_36 ( V_5 -> V_43 ,
F_37 ( V_5 ) , & V_46 ) ;
}
if ( V_47 ) {
F_7 ( V_5 , L_15 ,
V_47 ) ;
RETURN ( V_47 ) ;
}
RETURN ( F_22 ( V_5 ) ) ;
}
int F_38 ( struct V_4 * V_5 )
{
int V_57 ;
V_11 ;
V_5 -> V_35 |= V_58 ;
V_57 = ( ! V_5 -> V_59 && ! V_5 -> V_60 ) ;
F_39 ( V_5 ) ;
if ( V_57 ) {
struct V_61 V_62 ;
int V_47 ;
F_7 ( V_5 , L_16 ) ;
F_40 ( V_5 , & V_62 ) ;
V_47 = F_41 ( & V_62 , V_63 ) ;
if ( V_47 < 0 )
F_42 ( L_17 , V_47 ) ;
} else {
F_7 ( V_5 , L_18
L_19 ) ;
}
RETURN ( 0 ) ;
}
int F_43 ( struct V_4 * V_5 , struct V_64 * V_65 ,
void * V_1 , int V_66 )
{
V_11 ;
if ( V_66 == V_67 ) {
RETURN ( 0 ) ;
}
F_44 ( V_5 ) ;
if ( V_5 -> V_68 != F_43 ) {
F_39 ( V_5 ) ;
RETURN ( 0 ) ;
}
RETURN ( F_38 ( V_5 ) ) ;
}
int F_45 ( struct V_4 * V_5 , void * V_69 )
{
return - V_70 ;
}
int F_46 ( struct V_71 * V_72 ,
const struct V_73 * V_74 ,
T_4 type , T_5 * V_75 ,
T_6 V_76 , T_2 * V_38 ,
T_7 V_77 ,
T_8 V_78 ,
T_9 V_79 ,
void * V_1 , T_3 V_80 , enum V_81 V_81 ,
const T_2 * V_82 ,
struct V_61 * V_62 )
{
struct V_4 * V_5 ;
int V_83 ;
const struct V_84 V_85 = { . V_86 = V_78 ,
. V_87 = V_77 ,
. V_88 = V_79 ,
} ;
V_11 ;
F_47 ( ! ( * V_38 & V_89 ) ) ;
if ( F_48 ( F_34 ( V_72 ) ) ) {
F_42 ( L_20 ) ;
F_49 () ;
}
V_5 = F_50 ( V_72 , V_74 , type , V_76 , & V_85 , V_1 , V_80 ,
V_81 ) ;
if ( F_48 ( ! V_5 ) )
GOTO ( V_90 , V_83 = - V_91 ) ;
F_40 ( V_5 , V_62 ) ;
F_51 ( V_5 , V_76 ) ;
V_5 -> V_35 |= V_92 ;
if ( * V_38 & V_93 )
V_5 -> V_35 |= V_93 ;
if ( V_75 != NULL )
V_5 -> V_94 = * V_75 ;
if ( V_82 != NULL )
V_5 -> V_95 = * V_82 ;
if ( type == V_96 )
V_5 -> V_97 = V_75 -> V_98 ;
V_83 = F_52 ( V_72 , & V_5 , V_75 , V_38 ) ;
if ( F_48 ( V_83 != V_99 ) )
GOTO ( V_100 , V_83 ) ;
if ( V_75 != NULL )
* V_75 = V_5 -> V_94 ;
if ( V_5 -> V_101 )
V_5 -> V_101 ( V_5 , * V_38 , NULL ) ;
F_7 ( V_5 , L_21 ) ;
EXIT ;
V_100:
F_53 ( V_5 ) ;
V_90:
return V_83 ;
}
static void F_54 ( struct V_71 * V_72 ,
struct V_4 * V_5 , int V_76 )
{
int V_102 = 0 ;
F_44 ( V_5 ) ;
if ( ( V_5 -> V_103 != V_5 -> V_104 ) &&
! ( V_5 -> V_35 & V_36 ) ) {
V_5 -> V_35 |= V_105 | V_36 |
V_93 | V_58 ;
V_102 = 1 ;
}
F_39 ( V_5 ) ;
if ( V_102 )
F_7 ( V_5 ,
L_22
L_23 ) ;
else
F_7 ( V_5 , L_24 ) ;
F_55 ( V_5 , V_76 ) ;
if ( V_5 -> V_44 -> V_106 == V_107 ) {
F_44 ( V_5 ) ;
F_56 ( V_5 ) ;
F_57 ( V_5 ) ;
F_39 ( V_5 ) ;
}
}
int F_58 ( struct V_108 * exp , struct V_109 * V_110 ,
T_4 type , T_10 V_111 , T_6 V_76 ,
T_2 * V_38 , void * V_112 , T_3 V_80 ,
struct V_61 * V_62 , int V_47 )
{
struct V_71 * V_72 = exp -> V_19 -> V_113 ;
int V_114 = * V_38 & V_89 ;
struct V_4 * V_5 ;
struct V_115 * V_116 ;
int V_117 = 1 ;
int V_118 = 0 ;
V_11 ;
V_5 = F_59 ( V_62 ) ;
if ( ! V_5 ) {
F_47 ( type == V_107 ) ;
RETURN ( - V_119 ) ;
}
F_60 ( F_61 ( V_80 != 0 , V_80 == V_5 -> V_120 ) ,
L_25 , V_80 , V_5 -> V_120 ) ;
if ( V_47 != V_99 ) {
F_47 ( ! V_114 ) ;
F_7 ( V_5 , L_26 ,
V_47 == V_121 ? L_27 : L_28 ) ;
if ( V_47 != V_121 )
GOTO ( V_122 , V_47 ) ;
}
V_116 = F_62 ( & V_110 -> V_123 , & V_124 ) ;
if ( V_116 == NULL )
GOTO ( V_122 , V_47 = - V_125 ) ;
if ( V_80 != 0 ) {
F_47 ( V_112 != NULL ) ;
V_118 = F_63 ( & V_110 -> V_123 , & V_126 ,
V_127 ) ;
if ( V_118 < 0 ) {
F_15 ( V_5 , L_29 , V_118 ) ;
GOTO ( V_122 , V_47 = V_118 ) ;
} else if ( F_48 ( V_118 > V_80 ) ) {
F_15 ( V_5 , L_30
L_31 ,
V_80 , V_118 ) ;
GOTO ( V_122 , V_47 = - V_128 ) ;
}
}
if ( V_47 == V_121 ) {
if ( V_80 != 0 )
V_47 = F_64 ( V_5 , & V_110 -> V_123 , V_127 ,
V_112 , V_118 ) ;
GOTO ( V_122 , V_47 = ( V_47 != 0 ? V_47 : V_121 ) ) ;
}
V_117 = 0 ;
F_44 ( V_5 ) ;
if ( exp -> V_129 ) {
F_65 ( exp -> V_129 ,
& V_5 -> V_130 ,
& V_116 -> V_131 ,
& V_5 -> V_132 ) ;
} else {
V_5 -> V_130 = V_116 -> V_131 ;
}
* V_38 = F_66 ( V_116 -> V_133 ) ;
V_5 -> V_35 |= F_66 ( V_116 -> V_133 &
V_134 ) ;
V_5 -> V_35 |= F_66 ( V_116 -> V_133 &
V_49 ) ;
F_39 ( V_5 ) ;
F_67 ( V_135 , L_32 V_136 L_33 ,
V_5 , V_116 -> V_131 . V_137 , * V_38 ) ;
if ( ( * V_38 ) & V_138 ) {
int V_139 = V_116 -> V_140 . V_103 ;
F_47 ( ! V_114 ) ;
if ( V_139 && V_139 != V_5 -> V_103 ) {
F_7 ( V_5 , L_34 ,
V_141 [ V_139 ] ) ;
V_5 -> V_103 = V_139 ;
}
if ( memcmp ( V_116 -> V_140 . V_44 . V_142 . V_143 ,
V_5 -> V_44 -> V_142 . V_143 ,
sizeof( struct V_73 ) ) ) {
F_67 ( V_135 , L_35
L_36
L_37 ,
( long ) V_116 -> V_140 . V_44 . V_142 . V_143 [ 0 ] ,
( long ) V_116 -> V_140 . V_44 . V_142 . V_143 [ 1 ] ,
( long ) V_116 -> V_140 . V_44 . V_142 . V_143 [ 2 ] ,
( long ) V_5 -> V_44 -> V_142 . V_143 [ 0 ] ,
( long ) V_5 -> V_44 -> V_142 . V_143 [ 1 ] ,
( long ) V_5 -> V_44 -> V_142 . V_143 [ 2 ] ) ;
V_47 = F_68 ( V_72 , V_5 ,
& V_116 -> V_140 . V_44 . V_142 ) ;
if ( V_47 || V_5 -> V_44 == NULL )
GOTO ( V_122 , V_47 = - V_91 ) ;
F_7 ( V_5 , L_38 ) ;
}
if ( V_111 )
if ( ! ( type == V_144 &&
! ( F_69 ( exp ) & V_145 ) ) )
F_70 ( exp ,
V_5 -> V_44 -> V_106 ,
& V_116 -> V_140 . V_94 ,
& V_5 -> V_94 ) ;
if ( type != V_146 )
F_7 ( V_5 , L_39 ) ;
}
if ( ( * V_38 ) & V_147 ||
( V_148 && type == V_96 ) ) {
F_44 ( V_5 ) ;
V_5 -> V_35 |= V_58 | V_149 ;
F_39 ( V_5 ) ;
F_7 ( V_5 , L_40 ) ;
}
if ( V_80 != 0 ) {
F_44 ( V_5 ) ;
if ( V_5 -> V_103 != V_5 -> V_104 )
V_47 = F_64 ( V_5 , & V_110 -> V_123 , V_127 ,
V_5 -> V_150 , V_118 ) ;
F_39 ( V_5 ) ;
if ( V_47 < 0 ) {
V_117 = 1 ;
GOTO ( V_122 , V_47 ) ;
}
}
if ( ! V_114 ) {
V_47 = F_52 ( V_72 , & V_5 , NULL , V_38 ) ;
if ( V_5 -> V_101 != NULL ) {
int V_83 = V_5 -> V_101 ( V_5 , * V_38 , NULL ) ;
if ( ! V_47 )
V_47 = V_83 ;
if ( V_47 )
V_117 = 1 ;
}
}
if ( V_80 && V_112 != NULL ) {
memcpy ( V_112 , V_5 -> V_150 , V_80 ) ;
}
F_7 ( V_5 , L_41 ) ;
EXIT ;
V_122:
if ( V_117 == 1 && V_47 )
F_54 ( V_72 , V_5 , V_76 ) ;
F_71 ( V_5 ) ;
F_53 ( V_5 ) ;
return V_47 ;
}
static inline int F_72 ( int V_151 , int V_152 )
{
int V_153 ;
V_153 = F_20 ( int , V_154 , V_155 - 512 ) - V_151 ;
if ( F_73 ( V_153 >= 0 ) )
V_153 /= ( int ) sizeof( struct V_61 ) ;
else
V_153 = 0 ;
V_153 += V_156 - V_152 ;
return V_153 ;
}
static inline int F_74 ( struct V_157 * V_158 ,
enum V_159 V_160 ,
int V_152 )
{
int V_118 = F_75 ( V_158 , V_160 ) ;
return F_72 ( V_118 , V_152 ) ;
}
static inline int F_76 ( struct V_7 * V_8 ,
const struct V_161 * V_162 ,
enum V_159 V_160 , int V_152 )
{
int V_118 = F_77 ( V_8 -> V_163 , V_162 , V_160 ) ;
return F_72 ( V_118 , V_152 ) ;
}
int F_78 ( struct V_108 * exp , struct V_109 * V_110 ,
int V_164 , int V_165 , int V_166 ,
struct V_167 * V_168 , int V_169 )
{
struct V_71 * V_72 = exp -> V_19 -> V_113 ;
struct V_157 * V_158 = & V_110 -> V_123 ;
struct V_170 * V_171 = NULL ;
int V_38 , V_153 , V_172 , V_173 = 0 ;
F_79 ( V_174 ) ;
int V_47 ;
V_11 ;
if ( V_168 == NULL )
V_168 = & V_174 ;
if ( F_80 ( V_72 ) ) {
F_81 ( V_158 , V_175 ) ;
V_153 = F_74 ( V_158 , V_175 , V_166 ) ;
V_38 = F_82 ( V_72 ) ?
V_176 : V_177 ;
V_172 = ! F_82 ( V_72 ) &&
V_165 == V_178 ? 1 : 0 ;
if ( V_153 > V_169 )
V_169 += F_83 ( V_72 , V_168 , V_172 ,
V_153 - V_169 , 0 , V_38 ) ;
if ( V_153 > V_169 )
V_173 = V_169 ;
else
V_173 = V_153 ;
F_84 ( V_158 , & V_179 , V_175 ,
F_85 ( V_173 , V_165 ) ) ;
}
V_47 = F_86 ( V_110 , V_164 , V_165 ) ;
if ( V_47 ) {
F_87 ( V_168 , V_180 , V_169 ) ;
RETURN ( V_47 ) ;
}
if ( F_80 ( V_72 ) ) {
if ( V_166 ) {
V_171 = F_88 ( V_158 , & V_179 ) ;
F_47 ( V_171 ) ;
V_171 -> V_181 = V_166 ;
}
F_89 ( V_168 , V_173 , V_110 , 0 ) ;
F_89 ( V_168 , V_169 - V_173 , NULL , 0 ) ;
} else {
F_87 ( V_168 , V_180 , V_169 ) ;
}
RETURN ( 0 ) ;
}
int F_90 ( struct V_108 * exp , struct V_109 * V_110 ,
struct V_167 * V_168 , int V_169 )
{
return F_78 ( exp , V_110 , V_182 , V_178 ,
V_183 , V_168 , V_169 ) ;
}
struct V_109 * F_91 ( struct V_108 * exp , int V_80 )
{
struct V_109 * V_110 ;
int V_47 ;
V_11 ;
V_110 = F_92 ( F_93 ( exp ) , & V_184 ) ;
if ( V_110 == NULL )
RETURN ( F_94 ( - V_91 ) ) ;
V_47 = F_90 ( exp , V_110 , NULL , 0 ) ;
if ( V_47 ) {
F_95 ( V_110 ) ;
RETURN ( F_94 ( V_47 ) ) ;
}
F_84 ( & V_110 -> V_123 , & V_126 , V_127 , V_80 ) ;
F_96 ( V_110 ) ;
RETURN ( V_110 ) ;
}
int F_97 ( struct V_108 * exp , struct V_109 * * V_69 ,
struct V_185 * V_186 ,
const struct V_73 * V_74 ,
T_5 const * V_75 , T_2 * V_38 ,
void * V_112 , T_3 V_80 , enum V_81 V_81 ,
struct V_61 * V_62 , int V_187 )
{
struct V_71 * V_72 ;
struct V_4 * V_5 ;
struct V_170 * V_188 ;
int V_114 = * V_38 & V_89 ;
int V_189 = 1 ;
int V_47 , V_83 ;
struct V_109 * V_110 ;
V_11 ;
F_47 ( exp != NULL ) ;
V_72 = exp -> V_19 -> V_113 ;
if ( V_114 ) {
V_5 = F_98 ( V_62 , 0 ) ;
F_47 ( V_5 != NULL ) ;
F_7 ( V_5 , L_42 ) ;
F_47 ( exp == V_5 -> V_12 ) ;
} else {
const struct V_84 V_85 = {
. V_86 = V_186 -> V_190 ,
. V_87 = V_186 -> V_191 ,
. V_88 = V_186 -> V_192 ,
. V_193 = V_186 -> V_194
} ;
V_5 = F_50 ( V_72 , V_74 , V_186 -> V_195 ,
V_186 -> V_196 , & V_85 , V_186 -> V_197 ,
V_80 , V_81 ) ;
if ( V_5 == NULL )
RETURN ( - V_91 ) ;
F_99 ( V_5 , V_186 -> V_196 ) ;
F_40 ( V_5 , V_62 ) ;
if ( V_75 != NULL ) {
if ( V_186 -> V_195 == V_144 &&
! ( F_69 ( exp ) &
V_145 ) )
V_5 -> V_94 . V_198 . V_199 =
V_200 |
V_201 ;
else
V_5 -> V_94 = * V_75 ;
}
if ( V_186 -> V_195 == V_96 )
V_5 -> V_97 = V_75 -> V_98 ;
F_7 ( V_5 , L_43 ,
* V_38 ) ;
}
V_5 -> V_12 = exp ;
V_5 -> V_202 = NULL ;
V_5 -> V_68 = V_186 -> V_191 ;
V_5 -> V_35 |= ( * V_38 & V_203 ) ;
if ( V_69 == NULL || * V_69 == NULL ) {
V_110 = F_100 ( F_93 ( exp ) ,
& V_184 ,
V_182 ,
V_178 ) ;
if ( V_110 == NULL ) {
F_54 ( V_72 , V_5 , V_186 -> V_196 ) ;
F_53 ( V_5 ) ;
RETURN ( - V_91 ) ;
}
V_189 = 0 ;
if ( V_69 )
* V_69 = V_110 ;
} else {
int V_204 ;
V_110 = * V_69 ;
V_204 = F_63 ( & V_110 -> V_123 , & V_179 ,
V_175 ) ;
F_60 ( V_204 >= sizeof( * V_188 ) , L_44 ,
V_205 , V_204 , ( int ) sizeof( * V_188 ) ) ;
}
V_188 = F_88 ( & V_110 -> V_123 , & V_179 ) ;
F_101 ( V_5 , & V_188 -> V_140 ) ;
V_188 -> V_133 = F_102 ( * V_38 ) ;
V_188 -> V_131 [ 0 ] = * V_62 ;
if ( ! V_189 ) {
if ( V_80 > 0 )
F_103 ( & V_110 -> V_123 ,
& V_206 ) ;
F_84 ( & V_110 -> V_123 , & V_126 , V_127 ,
V_80 ) ;
F_96 ( V_110 ) ;
}
F_47 ( F_61 ( V_148 , V_186 -> V_195 != V_96 ||
V_75 -> V_98 . V_207 == V_208 ) ) ;
if ( V_187 ) {
F_47 ( V_69 != NULL ) ;
RETURN ( 0 ) ;
}
F_7 ( V_5 , L_45 ) ;
V_47 = F_104 ( V_110 ) ;
V_83 = F_58 ( exp , V_110 , V_186 -> V_195 , V_75 ? 1 : 0 ,
V_186 -> V_196 , V_38 , V_112 , V_80 ,
V_62 , V_47 ) ;
if ( V_83 == - V_119 )
F_53 ( V_5 ) ;
else
V_47 = V_83 ;
if ( ! V_189 && V_110 != NULL ) {
F_105 ( V_110 ) ;
if ( V_69 )
* V_69 = NULL ;
}
RETURN ( V_47 ) ;
}
static int F_106 ( struct V_4 * V_5 , int V_209 ,
T_3 * V_38 )
{
struct V_210 * V_211 ;
int V_47 ;
V_11 ;
if ( F_34 ( F_12 ( V_5 ) ) ) {
F_42 ( L_46 ) ;
F_49 () ;
}
F_7 ( V_5 , L_47 ) ;
V_211 = F_107 ( V_5 , V_209 , V_38 ) ;
if ( V_211 ) {
F_26 ( V_211 ) ;
V_47 = 0 ;
} else {
V_47 = V_212 ;
}
F_7 ( V_5 , L_48 ) ;
F_71 ( V_5 ) ;
RETURN ( V_47 ) ;
}
int F_108 ( struct V_61 * V_62 , int V_209 , T_3 * V_38 )
{
struct V_170 * V_188 ;
struct V_115 * V_116 ;
struct V_4 * V_5 ;
struct V_210 * V_211 ;
struct V_109 * V_110 ;
int V_47 ;
V_11 ;
V_5 = F_59 ( V_62 ) ;
if ( ! V_5 ) {
F_49 () ;
RETURN ( - V_128 ) ;
}
* V_38 = 0 ;
if ( V_5 -> V_12 == NULL )
RETURN ( F_106 ( V_5 , V_209 , V_38 ) ) ;
F_7 ( V_5 , L_49 ) ;
V_110 = F_100 ( F_93 ( V_5 -> V_12 ) ,
& V_213 , V_182 ,
V_214 ) ;
if ( V_110 == NULL ) {
F_71 ( V_5 ) ;
RETURN ( - V_91 ) ;
}
V_188 = F_88 ( & V_110 -> V_123 , & V_179 ) ;
V_188 -> V_131 [ 0 ] = V_5 -> V_130 ;
V_188 -> V_140 . V_103 = V_209 ;
V_188 -> V_133 = F_102 ( * V_38 ) ;
F_96 ( V_110 ) ;
V_47 = F_104 ( V_110 ) ;
if ( V_47 != V_99 )
GOTO ( V_100 , V_47 ) ;
V_116 = F_62 ( & V_110 -> V_123 , & V_124 ) ;
if ( V_116 == NULL )
GOTO ( V_100 , V_47 = - V_125 ) ;
if ( V_110 -> V_215 )
GOTO ( V_100 , V_47 = V_110 -> V_215 ) ;
V_211 = F_107 ( V_5 , V_209 , & V_116 -> V_133 ) ;
if ( V_211 != NULL ) {
F_26 ( V_211 ) ;
if ( V_5 -> V_101 ) {
V_47 = V_5 -> V_101 ( V_5 , V_39 ,
NULL ) ;
if ( V_47 )
GOTO ( V_100 , V_47 ) ;
}
} else {
V_47 = V_212 ;
}
EXIT ;
V_100:
F_71 ( V_5 ) ;
F_105 ( V_110 ) ;
return V_47 ;
}
static T_2 F_109 ( struct V_4 * V_5 )
{
T_2 V_47 = V_105 ;
V_11 ;
if ( V_5 -> V_12 ) {
bool V_216 ;
F_7 ( V_5 , L_50 ) ;
F_44 ( V_5 ) ;
V_5 -> V_35 |= V_58 ;
V_216 = ! ! ( V_5 -> V_35 &
( V_105 | V_217 ) ) ;
F_110 ( V_5 ) ;
V_47 = ( V_5 -> V_35 & V_149 ) ?
V_149 : V_218 ;
F_39 ( V_5 ) ;
if ( V_216 ) {
F_67 ( V_18 , L_51
L_52 ) ;
V_47 = V_105 ;
}
F_111 ( V_5 ) ;
} else {
if ( F_34 ( F_12 ( V_5 ) ) ) {
F_15 ( V_5 , L_53 ) ;
F_49 () ;
}
F_7 ( V_5 , L_54 ) ;
F_111 ( V_5 ) ;
F_26 ( V_5 -> V_44 ) ;
}
RETURN ( V_47 ) ;
}
static void F_112 ( struct V_109 * V_110 ,
struct V_167 * V_174 , int V_169 )
{
struct V_170 * V_171 ;
struct V_4 * V_5 ;
int F_21 , V_219 = 0 ;
V_11 ;
V_171 = F_88 ( & V_110 -> V_123 , & V_179 ) ;
F_47 ( V_171 != NULL ) ;
F_21 = F_63 ( & V_110 -> V_123 , & V_179 , V_175 ) -
sizeof( struct V_170 ) ;
F_21 /= sizeof( struct V_61 ) ;
F_21 += V_156 ;
F_47 ( F_21 >= V_171 -> V_181 + V_169 ) ;
F_113 (lock, head, l_bl_ast) {
if ( ! V_169 -- )
break;
F_47 ( V_5 -> V_12 ) ;
F_7 ( V_5 , L_55 ) ;
V_171 -> V_131 [ V_171 -> V_181 ++ ] = V_5 -> V_130 ;
V_219 ++ ;
}
F_67 ( V_18 , L_56 , V_219 ) ;
EXIT ;
}
int F_114 ( struct V_108 * exp , struct V_167 * V_168 ,
int V_169 , T_11 V_38 )
{
struct V_109 * V_110 = NULL ;
struct V_7 * V_8 ;
int free , V_220 = 0 ;
int V_47 = 0 ;
V_11 ;
F_47 ( exp != NULL ) ;
F_47 ( V_169 > 0 ) ;
F_115 ( V_221 , V_222 ) ;
if ( F_116 ( V_223 ) )
RETURN ( V_169 ) ;
free = F_76 ( F_93 ( exp ) ,
& V_224 , V_175 , 0 ) ;
if ( V_169 > free )
V_169 = free ;
while ( 1 ) {
V_8 = F_93 ( exp ) ;
if ( V_8 == NULL || V_8 -> V_225 ) {
F_67 ( V_18 ,
L_57 , V_8 ) ;
RETURN ( V_169 ) ;
}
V_110 = F_92 ( V_8 , & V_224 ) ;
if ( V_110 == NULL )
GOTO ( V_100 , V_47 = - V_91 ) ;
F_81 ( & V_110 -> V_123 , V_175 ) ;
F_84 ( & V_110 -> V_123 , & V_179 , V_175 ,
F_85 ( V_169 , V_226 ) ) ;
V_47 = F_86 ( V_110 , V_182 , V_226 ) ;
if ( V_47 ) {
F_95 ( V_110 ) ;
GOTO ( V_100 , V_47 ) ;
}
V_110 -> V_227 = V_228 ;
V_110 -> V_229 = V_230 ;
F_117 ( V_110 ) ;
F_112 ( V_110 , V_168 , V_169 ) ;
F_96 ( V_110 ) ;
if ( V_38 & V_63 ) {
F_118 ( V_110 , V_231 , - 1 ) ;
V_220 = V_169 ;
GOTO ( V_100 , 0 ) ;
} else {
V_47 = F_104 ( V_110 ) ;
}
if ( V_47 == V_232 ) {
F_67 ( V_18 , L_58
L_59 ,
F_119 ( V_110 -> V_233 ->
V_24 -> V_234 . V_235 ) ) ;
V_47 = 0 ;
} else if ( V_47 == - V_236 &&
V_110 -> V_237 == V_8 -> V_238 ) {
F_105 ( V_110 ) ;
continue;
} else if ( V_47 != V_99 ) {
F_120 ( V_47 == - V_239 ? V_18 : V_240 ,
L_60
L_61 , V_47 ) ;
break;
}
V_220 = V_169 ;
break;
}
F_105 ( V_110 ) ;
EXIT ;
V_100:
return V_220 ? V_220 : V_47 ;
}
static inline struct V_241 * F_121 ( struct V_7 * V_8 )
{
F_47 ( V_8 != NULL ) ;
return & V_8 -> V_242 -> V_113 -> V_243 ;
}
int F_122 ( struct V_109 * V_110 )
{
struct V_9 * V_10 ;
T_2 V_244 ;
T_3 V_245 ;
V_11 ;
if ( F_48 ( ! V_110 -> V_233 || ! V_110 -> V_233 -> V_242 ||
! F_123 ( V_110 -> V_233 ) ) )
{
RETURN ( 0 ) ;
}
if ( F_124 ( V_110 -> V_246 ) == 0 ||
F_125 ( V_110 -> V_246 ) == 0 ) {
F_126 ( V_247 , V_110 , L_62
L_63 V_248 L_64 ,
F_124 ( V_110 -> V_246 ) ,
F_125 ( V_110 -> V_246 ) ) ;
RETURN ( 0 ) ;
}
V_245 = F_125 ( V_110 -> V_246 ) ;
V_244 = F_124 ( V_110 -> V_246 ) ;
V_10 = V_110 -> V_233 -> V_242 ;
F_127 ( & V_10 -> V_249 ) ;
V_10 -> V_250 = V_244 ;
V_10 -> V_251 = V_245 ;
F_128 ( & V_10 -> V_249 ) ;
RETURN ( 0 ) ;
}
int F_41 ( struct V_61 * V_62 ,
T_11 V_252 )
{
struct V_108 * exp ;
int V_153 , V_38 , V_169 = 1 ;
T_2 V_47 = 0 ;
struct V_71 * V_72 ;
struct V_4 * V_5 ;
F_79 ( V_168 ) ;
V_11 ;
V_5 = F_98 ( V_62 , V_218 ) ;
if ( V_5 == NULL ) {
F_129 ( L_65 ) ;
RETURN ( 0 ) ;
}
V_47 = F_109 ( V_5 ) ;
if ( V_47 == V_105 ) {
F_53 ( V_5 ) ;
RETURN ( 0 ) ;
}
F_47 ( F_130 ( & V_5 -> V_180 ) ) ;
F_131 ( & V_5 -> V_180 , & V_168 ) ;
exp = V_5 -> V_12 ;
if ( F_132 ( exp ) ) {
V_153 = F_76 ( F_93 ( exp ) ,
& V_224 ,
V_175 , 0 ) ;
F_47 ( V_153 > 0 ) ;
V_72 = F_12 ( V_5 ) ;
V_38 = F_82 ( V_72 ) ?
V_176 : V_177 ;
V_169 += F_83 ( V_72 , & V_168 , 0 , V_153 - 1 ,
V_253 , V_38 ) ;
}
F_89 ( & V_168 , V_169 , NULL , V_252 ) ;
RETURN ( 0 ) ;
}
int F_133 ( struct V_167 * V_168 , int V_169 ,
T_11 V_38 )
{
F_79 ( V_174 ) ;
struct V_4 * V_5 , * V_254 ;
int V_255 = 0 , V_256 = 0 ;
T_2 V_47 ;
V_255 = V_169 ;
F_134 (lock, next, cancels, l_bl_ast) {
if ( V_255 -- == 0 )
break;
if ( V_38 & V_257 ) {
V_47 = V_105 ;
F_111 ( V_5 ) ;
} else {
V_47 = F_109 ( V_5 ) ;
}
if ( ! ( V_38 & V_253 ) && ( V_47 == V_149 ) ) {
F_7 ( V_5 , L_66 ) ;
F_135 ( & V_5 -> V_180 ) ;
F_131 ( & V_5 -> V_180 , & V_174 ) ;
V_256 ++ ;
continue;
}
if ( V_47 == V_105 ) {
F_135 ( & V_5 -> V_180 ) ;
F_53 ( V_5 ) ;
V_169 -- ;
}
}
if ( V_256 > 0 ) {
V_169 -= V_256 ;
F_89 ( & V_174 , V_256 , NULL , 0 ) ;
}
RETURN ( V_169 ) ;
}
static T_12 F_136 ( struct V_71 * V_72 ,
struct V_4 * V_5 ,
int V_258 , int V_259 ,
int V_169 )
{
T_12 V_33 = V_260 ;
T_13 V_261 = V_72 -> V_262 ;
F_44 ( V_5 ) ;
switch ( V_5 -> V_44 -> V_106 ) {
case V_96 :
case V_144 :
if ( V_261 && V_261 ( V_5 ) )
break;
default:
V_33 = V_263 ;
V_5 -> V_35 |= V_264 ;
break;
}
F_39 ( V_5 ) ;
RETURN ( V_33 ) ;
}
static T_12 F_137 ( struct V_71 * V_72 ,
struct V_4 * V_5 ,
int V_258 , int V_259 ,
int V_169 )
{
T_1 V_265 = F_9 () ;
struct V_241 * V_266 = & V_72 -> V_243 ;
T_2 V_267 , V_268 , V_269 ;
T_1 V_270 ;
if ( V_169 && V_259 >= V_169 )
return V_271 ;
V_267 = F_138 ( V_266 ) ;
V_268 = F_139 ( V_266 ) ;
V_270 = F_140 ( F_5 ( V_265 ,
V_5 -> V_272 ) ) ;
V_269 = V_268 * V_270 * V_258 ;
F_141 ( V_266 , V_269 ) ;
return ( V_267 == 0 || V_269 < V_267 ) ?
V_271 : V_260 ;
}
static T_12 F_142 ( struct V_71 * V_72 ,
struct V_4 * V_5 ,
int V_258 , int V_259 ,
int V_169 )
{
return ( V_259 >= V_169 ) ?
V_271 : V_260 ;
}
static T_12 F_143 ( struct V_71 * V_72 ,
struct V_4 * V_5 ,
int V_258 , int V_259 ,
int V_169 )
{
return ( ( V_259 >= V_169 ) &&
F_144 ( F_9 () ,
F_145 ( V_5 -> V_272 ,
V_72 -> V_273 ) ) ) ?
V_271 : V_260 ;
}
static T_12 F_146 ( struct V_71 * V_72 ,
struct V_4 * V_5 ,
int V_258 , int V_259 ,
int V_169 )
{
return ( V_259 >= V_169 ) ?
V_271 : V_260 ;
}
static T_14
F_147 ( struct V_71 * V_72 , int V_38 )
{
if ( V_38 & V_274 )
return F_136 ;
if ( F_82 ( V_72 ) ) {
if ( V_38 & V_275 )
return F_142 ;
else if ( V_38 & V_176 )
return F_137 ;
else if ( V_38 & V_276 )
return F_142 ;
} else {
if ( V_38 & V_177 )
return F_143 ;
}
return F_146 ;
}
static int F_148 ( struct V_71 * V_72 , struct V_167 * V_168 ,
int V_169 , int F_21 , int V_38 )
{
T_14 V_277 ;
struct V_4 * V_5 , * V_254 ;
int V_259 = 0 , V_258 , V_278 ;
V_11 ;
F_32 ( & V_72 -> V_279 ) ;
V_258 = V_72 -> V_280 ;
V_278 = V_258 ;
if ( ! F_82 ( V_72 ) )
V_169 += V_258 - V_72 -> V_281 ;
V_277 = F_147 ( V_72 , V_38 ) ;
F_47 ( V_277 != NULL ) ;
while ( ! F_130 ( & V_72 -> V_282 ) ) {
T_12 V_33 ;
if ( V_278 -- <= 0 )
break;
if ( F_21 && V_259 >= F_21 )
break;
F_134 (lock, next, &ns->ns_unused_list,
l_lru) {
F_47 ( ! ( V_5 -> V_35 & V_149 ) ) ;
if ( V_38 & V_274 &&
V_5 -> V_35 & V_264 )
continue;
if ( ! ( V_5 -> V_35 & V_218 ) )
break;
F_149 ( V_5 ) ;
}
if ( & V_5 -> V_283 == & V_72 -> V_282 )
break;
F_150 ( V_5 ) ;
F_33 ( & V_72 -> V_279 ) ;
F_151 ( & V_5 -> V_284 , V_285 , V_286 ) ;
V_33 = V_277 ( V_72 , V_5 , V_258 , V_259 , V_169 ) ;
if ( V_33 == V_271 ) {
F_152 ( & V_5 -> V_284 ,
V_285 , V_286 ) ;
F_53 ( V_5 ) ;
F_32 ( & V_72 -> V_279 ) ;
break;
}
if ( V_33 == V_263 ) {
F_152 ( & V_5 -> V_284 ,
V_287 , V_286 ) ;
F_53 ( V_5 ) ;
F_32 ( & V_72 -> V_279 ) ;
continue;
}
F_44 ( V_5 ) ;
if ( ( V_5 -> V_35 & V_218 ) ||
( F_153 ( V_5 ) == 0 ) ) {
F_39 ( V_5 ) ;
F_152 ( & V_5 -> V_284 ,
V_285 , V_286 ) ;
F_53 ( V_5 ) ;
F_32 ( & V_72 -> V_279 ) ;
continue;
}
F_47 ( ! V_5 -> V_59 && ! V_5 -> V_60 ) ;
V_5 -> V_35 &= ~ V_217 ;
V_5 -> V_35 |= V_58 | V_218 ;
F_47 ( F_130 ( & V_5 -> V_180 ) ) ;
F_131 ( & V_5 -> V_180 , V_168 ) ;
F_39 ( V_5 ) ;
F_152 ( & V_5 -> V_284 , V_285 , V_286 ) ;
F_32 ( & V_72 -> V_279 ) ;
V_259 ++ ;
V_258 -- ;
}
F_33 ( & V_72 -> V_279 ) ;
RETURN ( V_259 ) ;
}
int F_83 ( struct V_71 * V_72 , struct V_167 * V_168 ,
int V_169 , int F_21 , T_11 V_252 ,
int V_38 )
{
int V_259 ;
V_259 = F_148 ( V_72 , V_168 , V_169 , F_21 , V_38 ) ;
if ( V_259 <= 0 )
return V_259 ;
return F_133 ( V_168 , V_259 , V_252 ) ;
}
int F_154 ( struct V_71 * V_72 , int V_288 ,
T_11 V_252 ,
int V_38 )
{
F_79 ( V_168 ) ;
int V_169 , V_47 ;
V_11 ;
V_169 = F_148 ( V_72 , & V_168 , V_288 , 0 , V_38 ) ;
V_47 = F_155 ( V_72 , NULL , & V_168 , V_169 , V_252 ) ;
if ( V_47 == 0 )
RETURN ( V_169 ) ;
RETURN ( 0 ) ;
}
int F_156 ( struct V_210 * V_211 ,
struct V_167 * V_168 ,
T_5 * V_75 ,
T_6 V_76 , int V_133 ,
T_11 V_252 , void * V_289 )
{
struct V_4 * V_5 ;
int V_169 = 0 ;
V_11 ;
F_157 ( V_211 ) ;
F_113 (lock, &res->lr_granted, l_res_link) {
if ( V_289 != NULL && V_5 -> V_290 != V_289 ) {
F_15 ( V_5 , L_67 ,
V_5 -> V_290 , V_289 ) ;
continue;
}
if ( V_5 -> V_59 || V_5 -> V_60 )
continue;
if ( V_5 -> V_35 & V_149 ||
V_5 -> V_35 & V_218 )
continue;
if ( F_158 ( V_5 -> V_104 , V_76 ) )
continue;
if ( V_75 && ( V_5 -> V_44 -> V_106 == V_144 ) &&
! ( V_5 -> V_94 . V_198 . V_199 &
V_75 -> V_198 . V_199 ) )
continue;
V_5 -> V_35 |= V_58 | V_218 |
V_133 ;
F_47 ( F_130 ( & V_5 -> V_180 ) ) ;
F_131 ( & V_5 -> V_180 , V_168 ) ;
F_150 ( V_5 ) ;
V_169 ++ ;
}
F_159 ( V_211 ) ;
RETURN ( F_133 ( V_168 , V_169 , V_252 ) ) ;
}
int F_89 ( struct V_167 * V_168 , int V_169 ,
struct V_109 * V_110 , T_11 V_38 )
{
struct V_4 * V_5 ;
int V_211 = 0 ;
V_11 ;
if ( F_130 ( V_168 ) || V_169 == 0 )
RETURN ( 0 ) ;
while ( V_169 > 0 ) {
F_47 ( ! F_130 ( V_168 ) ) ;
V_5 = F_160 ( V_168 -> V_254 , struct V_4 ,
V_180 ) ;
F_47 ( V_5 -> V_12 ) ;
if ( F_132 ( V_5 -> V_12 ) ) {
V_211 = V_169 ;
if ( V_110 )
F_112 ( V_110 , V_168 , V_169 ) ;
else
V_211 = F_114 ( V_5 -> V_12 ,
V_168 , V_169 ,
V_38 ) ;
} else {
V_211 = F_114 ( V_5 -> V_12 ,
V_168 , 1 , V_38 ) ;
}
if ( V_211 < 0 ) {
F_120 ( V_211 == - V_239 ? V_18 : V_240 ,
L_68 , V_211 ) ;
V_211 = V_169 ;
}
V_169 -= V_211 ;
F_87 ( V_168 , V_180 , V_211 ) ;
}
F_47 ( V_169 == 0 ) ;
RETURN ( 0 ) ;
}
int F_161 ( struct V_71 * V_72 ,
const struct V_73 * V_74 ,
T_5 * V_75 ,
T_6 V_76 ,
T_11 V_38 ,
void * V_289 )
{
struct V_210 * V_211 ;
F_79 ( V_168 ) ;
int V_169 ;
int V_47 ;
V_11 ;
V_211 = F_162 ( V_72 , NULL , V_74 , 0 , 0 ) ;
if ( V_211 == NULL ) {
F_67 ( V_135 , L_69 V_248 L_70 , V_74 -> V_143 [ 0 ] ) ;
RETURN ( 0 ) ;
}
F_163 ( V_211 ) ;
V_169 = F_156 ( V_211 , & V_168 , V_75 , V_76 ,
0 , V_38 | V_253 , V_289 ) ;
V_47 = F_89 ( & V_168 , V_169 , NULL , V_38 ) ;
if ( V_47 != V_99 )
F_42 ( L_71 , V_47 ) ;
F_164 ( V_211 ) ;
F_165 ( V_211 ) ;
RETURN ( 0 ) ;
}
static int F_166 ( T_15 * V_291 , T_16 * V_292 ,
struct V_293 * V_294 , void * V_295 )
{
struct V_210 * V_211 = F_167 ( V_291 , V_294 ) ;
struct V_296 * V_297 = V_295 ;
int V_47 ;
V_47 = F_161 ( F_168 ( V_211 ) , & V_211 -> V_142 ,
NULL , V_298 ,
V_297 -> V_299 , V_297 -> V_300 ) ;
if ( V_47 != 0 ) {
F_42 ( L_72 V_248 L_73 ,
V_211 -> V_142 . V_143 [ 0 ] , V_47 ) ;
}
return 0 ;
}
int F_169 ( struct V_71 * V_72 ,
const struct V_73 * V_74 ,
T_11 V_38 , void * V_289 )
{
struct V_296 V_295 = {
. V_299 = V_38 ,
. V_300 = V_289 ,
} ;
V_11 ;
if ( V_72 == NULL )
RETURN ( V_99 ) ;
if ( V_74 != NULL ) {
RETURN ( F_161 ( V_72 , V_74 , NULL ,
V_298 , V_38 ,
V_289 ) ) ;
} else {
F_170 ( V_72 -> V_301 ,
F_166 , & V_295 ) ;
RETURN ( V_99 ) ;
}
}
int F_171 ( struct V_210 * V_211 , T_17 V_302 ,
void * V_303 )
{
struct V_167 * V_304 , * V_254 ;
struct V_4 * V_5 ;
int V_47 = V_305 ;
V_11 ;
if ( ! V_211 )
RETURN ( V_305 ) ;
F_157 ( V_211 ) ;
F_172 (tmp, next, &res->lr_granted) {
V_5 = F_160 ( V_304 , struct V_4 , V_306 ) ;
if ( V_302 ( V_5 , V_303 ) == V_307 )
GOTO ( V_100 , V_47 = V_307 ) ;
}
F_172 (tmp, next, &res->lr_converting) {
V_5 = F_160 ( V_304 , struct V_4 , V_306 ) ;
if ( V_302 ( V_5 , V_303 ) == V_307 )
GOTO ( V_100 , V_47 = V_307 ) ;
}
F_172 (tmp, next, &res->lr_waiting) {
V_5 = F_160 ( V_304 , struct V_4 , V_306 ) ;
if ( V_302 ( V_5 , V_303 ) == V_307 )
GOTO ( V_100 , V_47 = V_307 ) ;
}
V_100:
F_159 ( V_211 ) ;
RETURN ( V_47 ) ;
}
static int F_173 ( struct V_4 * V_5 , void * V_303 )
{
struct V_308 * V_309 = V_303 ;
return V_309 -> V_302 ( V_5 , V_309 -> V_303 ) ;
}
static int F_174 ( T_15 * V_291 , T_16 * V_292 ,
struct V_293 * V_294 , void * V_295 )
{
struct V_210 * V_211 = F_167 ( V_291 , V_294 ) ;
return F_171 ( V_211 , F_173 , V_295 ) ==
V_307 ;
}
void F_175 ( struct V_71 * V_72 ,
T_17 V_302 , void * V_303 )
{
struct V_308 V_309 = { V_302 : V_302 , V_303 : V_303 } ;
F_170 ( V_72 -> V_301 ,
F_174 , & V_309 ) ;
}
int F_176 ( struct V_71 * V_72 ,
const struct V_73 * V_74 ,
T_17 V_302 , void * V_1 )
{
struct V_210 * V_211 ;
int V_47 ;
V_11 ;
if ( V_72 == NULL ) {
F_42 ( L_74 ) ;
F_49 () ;
}
V_211 = F_162 ( V_72 , NULL , V_74 , 0 , 0 ) ;
if ( V_211 == NULL )
RETURN ( 0 ) ;
F_163 ( V_211 ) ;
V_47 = F_171 ( V_211 , V_302 , V_1 ) ;
F_164 ( V_211 ) ;
F_165 ( V_211 ) ;
RETURN ( V_47 ) ;
}
static int F_177 ( struct V_4 * V_5 , void * V_303 )
{
struct V_167 * V_310 = V_303 ;
F_60 ( F_130 ( & V_5 -> V_311 ) ,
L_75 ,
V_5 , & V_5 -> V_311 . V_254 , & V_5 -> V_311 . V_312 ) ;
if ( ! ( V_5 -> V_35 & ( V_36 | V_218 ) ) ) {
F_131 ( & V_5 -> V_311 , V_310 ) ;
F_150 ( V_5 ) ;
}
return V_305 ;
}
static int F_178 ( const struct V_313 * V_314 ,
struct V_109 * V_110 ,
struct V_315 * V_316 , int V_47 )
{
struct V_4 * V_5 ;
struct V_115 * V_116 ;
struct V_108 * exp ;
V_11 ;
F_179 ( & V_110 -> V_233 -> V_317 ) ;
if ( V_47 != V_99 )
GOTO ( V_100 , V_47 ) ;
V_116 = F_62 ( & V_110 -> V_123 , & V_124 ) ;
if ( V_116 == NULL )
GOTO ( V_100 , V_47 = - V_125 ) ;
V_5 = F_59 ( & V_316 -> V_131 ) ;
if ( ! V_5 ) {
F_42 ( L_76 V_136
L_77 V_136 L_78 ,
V_316 -> V_131 . V_137 , V_116 -> V_131 . V_137 ,
V_110 -> V_318 -> V_319 . V_26 ,
F_180 ( V_110 -> V_320 ) ) ;
GOTO ( V_100 , V_47 = - V_232 ) ;
}
exp = V_110 -> V_318 ;
if ( exp && exp -> V_129 ) {
F_65 ( exp -> V_129 ,
& V_5 -> V_130 ,
& V_116 -> V_131 ,
& V_5 -> V_132 ) ;
} else {
V_5 -> V_130 = V_116 -> V_131 ;
}
F_7 ( V_5 , L_79 ) ;
F_181 ( V_110 -> V_233 ) ;
F_71 ( V_5 ) ;
V_100:
if ( V_47 != V_99 )
F_182 ( V_110 -> V_233 ) ;
RETURN ( V_47 ) ;
}
static int F_183 ( struct V_7 * V_8 , struct V_4 * V_5 )
{
struct V_109 * V_110 ;
struct V_315 * V_316 ;
struct V_170 * V_188 ;
int V_38 ;
V_11 ;
if ( V_5 -> V_35 & V_218 ) {
F_7 ( V_5 , L_80 ) ;
RETURN ( 0 ) ;
}
if ( V_5 -> V_35 & V_217 ) {
F_7 ( V_5 , L_81 ) ;
F_111 ( V_5 ) ;
RETURN ( 0 ) ;
}
if ( V_5 -> V_104 == V_5 -> V_103 )
V_38 = V_89 | V_41 ;
else if ( V_5 -> V_104 )
V_38 = V_89 | V_42 ;
else if ( ! F_130 ( & V_5 -> V_306 ) )
V_38 = V_89 | V_40 ;
else
V_38 = V_89 ;
V_110 = F_100 ( V_8 , & V_184 ,
V_182 , V_178 ) ;
if ( V_110 == NULL )
RETURN ( - V_91 ) ;
V_110 -> V_321 = V_322 ;
V_188 = F_88 ( & V_110 -> V_123 , & V_179 ) ;
F_101 ( V_5 , & V_188 -> V_140 ) ;
V_188 -> V_133 = F_102 ( V_38 ) ;
F_40 ( V_5 , & V_188 -> V_131 [ 0 ] ) ;
if ( V_5 -> V_120 > 0 )
F_103 ( & V_110 -> V_123 , & V_206 ) ;
F_84 ( & V_110 -> V_123 , & V_126 , V_127 ,
V_5 -> V_120 ) ;
F_96 ( V_110 ) ;
F_184 ( V_110 -> V_323 , V_324 ) ;
F_7 ( V_5 , L_82 ) ;
F_185 ( & V_110 -> V_233 -> V_317 ) ;
F_186 ( sizeof( * V_316 ) <= sizeof( V_110 -> V_325 ) ) ;
V_316 = F_187 ( V_110 ) ;
V_316 -> V_131 = V_188 -> V_131 [ 0 ] ;
V_110 -> V_326 = ( V_327 ) F_178 ;
F_118 ( V_110 , V_231 , - 1 ) ;
RETURN ( 0 ) ;
}
static void F_188 ( struct V_71 * V_72 )
{
int V_328 ;
F_79 ( V_168 ) ;
F_67 ( V_18 , L_83
L_84 ,
F_189 ( V_72 ) , V_72 -> V_280 ) ;
V_328 = F_83 ( V_72 , & V_168 , V_72 -> V_280 , 0 ,
V_257 , V_274 ) ;
F_67 ( V_18 , L_85 ,
V_328 , F_189 ( V_72 ) ) ;
}
int F_190 ( struct V_7 * V_8 )
{
struct V_71 * V_72 = V_8 -> V_242 -> V_113 ;
F_79 ( V_310 ) ;
struct V_4 * V_5 , * V_254 ;
int V_47 = 0 ;
V_11 ;
F_47 ( F_191 ( & V_8 -> V_317 ) == 0 ) ;
if ( V_8 -> V_329 )
RETURN ( 0 ) ;
F_185 ( & V_8 -> V_317 ) ;
if ( V_330 )
F_188 ( V_72 ) ;
F_175 ( V_72 , F_177 , & V_310 ) ;
F_134 (lock, next, &list, l_pending_chain) {
F_135 ( & V_5 -> V_311 ) ;
if ( V_47 ) {
F_53 ( V_5 ) ;
continue;
}
V_47 = F_183 ( V_8 , V_5 ) ;
F_53 ( V_5 ) ;
}
F_179 ( & V_8 -> V_317 ) ;
RETURN ( V_47 ) ;
}
