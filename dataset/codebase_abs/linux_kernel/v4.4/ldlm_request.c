static void F_1 ( void * V_1 )
{
}
static int F_2 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
if ( V_5 -> V_11 == NULL ) {
static unsigned long V_12 , V_13 ;
F_3 ( L_1 ,
( V_14 ) V_5 -> V_15 ,
( V_14 ) ( F_4 () -
V_5 -> V_15 ) ) ;
F_5 ( V_5 , L_2 ,
( V_14 ) V_5 -> V_15 ,
( V_14 ) ( F_4 () -
V_5 -> V_15 ) ) ;
if ( F_6 ( F_7 () , V_12 ) ) {
V_13 = V_12 ;
V_12 = F_8 ( 300 ) ;
F_9 ( V_16 ,
F_10 ( V_5 ) ) ;
if ( V_13 == 0 )
F_11 () ;
}
return 0 ;
}
V_10 = V_5 -> V_11 -> V_17 ;
V_8 = V_10 -> V_18 . V_19 . V_20 ;
F_12 ( V_8 , V_3 -> V_21 ) ;
F_13 ( V_5 , L_3 ,
( V_14 ) V_5 -> V_15 ,
( V_14 ) ( F_4 () - V_5 -> V_15 ) ,
F_14 ( V_10 ) , V_8 -> V_22 -> V_23 . V_24 ) ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 )
{
int V_25 = F_16 ( F_17 ( V_5 ) ) ;
if ( V_26 )
return V_27 / 2 ;
V_25 = F_18 ( int , V_28 , V_25 + ( V_25 >> 1 ) ) ;
return F_19 ( V_25 , V_29 ) ;
}
static int F_20 ( struct V_4 * V_5 )
{
long V_30 ;
int V_31 ;
if ( V_5 -> V_32 & ( V_33 | V_34 ) ) {
F_5 ( V_5 , L_4 ) ;
V_31 = - V_35 ;
} else {
V_30 = F_4 () - V_5 -> V_15 ;
F_5 ( V_5 , L_5 ,
V_30 ) ;
F_21 ( F_17 ( V_5 ) ,
V_30 ) ;
V_31 = 0 ;
}
return V_31 ;
}
int F_22 ( struct V_4 * V_5 , T_1 V_36 , void * V_1 )
{
if ( V_36 == V_37 ) {
F_5 ( V_5 , L_6 ) ;
return 0 ;
}
if ( ! ( V_36 & ( V_38 | V_39 |
V_40 ) ) ) {
F_23 ( & V_5 -> V_41 ) ;
return F_20 ( V_5 ) ;
}
F_5 ( V_5 , L_7 ) ;
return 0 ;
}
int F_24 ( struct V_4 * V_5 , T_1 V_36 , void * V_1 )
{
struct V_2 V_3 ;
struct V_9 * V_10 ;
struct V_7 * V_8 = NULL ;
struct V_42 V_43 ;
T_2 V_25 ;
int V_44 = 0 ;
if ( V_36 == V_37 ) {
F_5 ( V_5 , L_6 ) ;
goto V_45;
}
if ( ! ( V_36 & ( V_38 | V_39 |
V_40 ) ) ) {
F_23 ( & V_5 -> V_41 ) ;
return 0 ;
}
F_5 ( V_5 , L_8 ) ;
V_45:
V_10 = F_25 ( V_5 -> V_11 ) ;
if ( V_10 != NULL )
V_8 = V_10 -> V_18 . V_19 . V_20 ;
V_25 = F_15 ( V_5 ) * 2 ;
V_3 . V_6 = V_5 ;
if ( V_5 -> V_32 & V_46 ) {
F_5 ( V_5 , L_9 ) ;
V_43 = F_26 ( F_1 , & V_3 ) ;
} else {
V_43 = F_27 ( F_28 ( V_25 ) ,
F_2 ,
F_1 , & V_3 ) ;
}
if ( V_8 != NULL ) {
F_29 ( & V_8 -> V_47 ) ;
V_3 . V_21 = V_8 -> V_48 ;
F_30 ( & V_8 -> V_47 ) ;
}
if ( F_31 ( V_49 ,
V_50 | V_51 ) ) {
V_5 -> V_32 |= V_52 ;
V_44 = - V_53 ;
} else {
V_44 = F_32 ( V_5 -> V_41 ,
F_33 ( V_5 ) , & V_43 ) ;
}
if ( V_44 ) {
F_5 ( V_5 , L_10 ,
V_44 ) ;
return V_44 ;
}
return F_20 ( V_5 ) ;
}
static void F_34 ( struct V_54 * V_55 ,
struct V_4 * V_5 , int V_56 )
{
int V_57 = 0 ;
F_35 ( V_5 ) ;
if ( ( V_5 -> V_58 != V_5 -> V_59 ) &&
! ( V_5 -> V_32 & V_34 ) ) {
V_5 -> V_32 |= V_60 | V_34 |
V_61 | V_62 ;
V_57 = 1 ;
}
F_36 ( V_5 ) ;
if ( V_57 )
F_5 ( V_5 ,
L_11 ) ;
else
F_5 ( V_5 , L_12 ) ;
F_37 ( V_5 , V_56 ) ;
if ( V_5 -> V_63 -> V_64 == V_65 ) {
F_35 ( V_5 ) ;
F_38 ( V_5 ) ;
F_39 ( V_5 ) ;
F_36 ( V_5 ) ;
}
}
int F_40 ( struct V_66 * exp , struct V_67 * V_68 ,
T_3 type , T_4 V_69 , T_5 V_56 ,
T_1 * V_36 , void * V_70 , T_2 V_71 ,
struct V_72 * V_73 , int V_44 )
{
struct V_54 * V_55 = exp -> V_17 -> V_74 ;
int V_75 = * V_36 & V_76 ;
struct V_4 * V_5 ;
struct V_77 * V_78 ;
int V_79 = 1 ;
int V_80 = 0 ;
V_5 = F_41 ( V_73 ) ;
if ( ! V_5 ) {
F_42 ( type == V_65 ) ;
return - V_81 ;
}
F_43 ( F_44 ( V_71 != 0 , V_71 == V_5 -> V_82 ) ,
L_13 , V_71 , V_5 -> V_82 ) ;
if ( V_44 != V_83 ) {
F_42 ( ! V_75 ) ;
F_5 ( V_5 , L_14 ,
V_44 == V_84 ? L_15 : L_16 ) ;
if ( V_44 != V_84 )
goto V_85;
}
V_78 = F_45 ( & V_68 -> V_86 , & V_87 ) ;
if ( V_78 == NULL ) {
V_44 = - V_88 ;
goto V_85;
}
if ( V_71 != 0 ) {
F_42 ( V_70 != NULL ) ;
V_80 = F_46 ( & V_68 -> V_86 , & V_89 ,
V_90 ) ;
if ( V_80 < 0 ) {
F_13 ( V_5 , L_17 , V_80 ) ;
V_44 = V_80 ;
goto V_85;
} else if ( F_47 ( V_80 > V_71 ) ) {
F_13 ( V_5 , L_18 ,
V_71 , V_80 ) ;
V_44 = - V_91 ;
goto V_85;
}
}
if ( V_44 == V_84 ) {
if ( V_71 != 0 )
V_44 = F_48 ( V_5 , & V_68 -> V_86 , V_90 ,
V_70 , V_80 ) ;
if ( V_44 == 0 )
V_44 = V_84 ;
goto V_85;
}
V_79 = 0 ;
F_35 ( V_5 ) ;
if ( exp -> V_92 ) {
F_49 ( exp -> V_92 ,
& V_5 -> V_93 ,
& V_78 -> V_94 ,
& V_5 -> V_95 ) ;
} else {
V_5 -> V_93 = V_78 -> V_94 ;
}
* V_36 = F_50 ( V_78 -> V_96 ) ;
V_5 -> V_32 |= F_50 ( V_78 -> V_96 &
V_97 ) ;
V_5 -> V_32 |= F_50 ( V_78 -> V_96 &
V_46 ) ;
F_36 ( V_5 ) ;
F_51 ( V_98 , L_19 ,
V_5 , V_78 -> V_94 . V_99 , * V_36 ) ;
if ( ( * V_36 ) & V_100 ) {
int V_101 = V_78 -> V_102 . V_58 ;
F_42 ( ! V_75 ) ;
if ( V_101 && V_101 != V_5 -> V_58 ) {
F_5 ( V_5 , L_20 ,
V_103 [ V_101 ] ) ;
V_5 -> V_58 = V_101 ;
}
if ( ! F_52 ( & V_78 -> V_102 . V_63 . V_104 ,
& V_5 -> V_63 -> V_104 ) ) {
F_51 ( V_98 , L_21 V_105
L_22 V_105 L_23 ,
F_53 ( & V_78 -> V_102 . V_63 ) ,
F_53 ( V_5 -> V_63 ) ) ;
V_44 = F_54 ( V_55 , V_5 ,
& V_78 -> V_102 . V_63 . V_104 ) ;
if ( V_44 || V_5 -> V_63 == NULL ) {
V_44 = - V_106 ;
goto V_85;
}
F_5 ( V_5 , L_24 ) ;
}
if ( V_69 )
if ( ! ( type == V_107 &&
! ( F_55 ( exp ) & V_108 ) ) )
F_56 ( exp ,
V_5 -> V_63 -> V_64 ,
& V_78 -> V_102 . V_109 ,
& V_5 -> V_109 ) ;
if ( type != V_110 )
F_5 ( V_5 ,
L_25 ) ;
}
if ( ( * V_36 ) & V_111 ||
( V_112 && type == V_113 ) ) {
F_35 ( V_5 ) ;
V_5 -> V_32 |= V_62 | V_114 ;
F_36 ( V_5 ) ;
F_5 ( V_5 , L_26 ) ;
}
if ( V_71 != 0 ) {
F_35 ( V_5 ) ;
if ( V_5 -> V_58 != V_5 -> V_59 )
V_44 = F_48 ( V_5 , & V_68 -> V_86 , V_90 ,
V_5 -> V_115 , V_80 ) ;
F_36 ( V_5 ) ;
if ( V_44 < 0 ) {
V_79 = 1 ;
goto V_85;
}
}
if ( ! V_75 ) {
V_44 = F_57 ( V_55 , & V_5 , NULL , V_36 ) ;
if ( V_5 -> V_116 != NULL ) {
int V_117 = V_5 -> V_116 ( V_5 , * V_36 , NULL ) ;
if ( ! V_44 )
V_44 = V_117 ;
if ( V_44 )
V_79 = 1 ;
}
}
if ( V_71 && V_70 != NULL ) {
memcpy ( V_70 , V_5 -> V_115 , V_71 ) ;
}
F_5 ( V_5 , L_27 ) ;
V_85:
if ( V_79 == 1 && V_44 )
F_34 ( V_55 , V_5 , V_56 ) ;
F_58 ( V_5 ) ;
F_59 ( V_5 ) ;
return V_44 ;
}
static inline int F_60 ( int V_118 , int V_119 )
{
int V_120 ;
V_120 = F_18 ( int , V_121 , V_122 - 512 ) - V_118 ;
if ( F_61 ( V_120 >= 0 ) )
V_120 /= ( int ) sizeof( struct V_72 ) ;
else
V_120 = 0 ;
V_120 += V_123 - V_119 ;
return V_120 ;
}
static inline int F_62 ( struct V_124 * V_125 ,
enum V_126 V_127 ,
int V_119 )
{
int V_80 = F_63 ( V_125 , V_127 ) ;
return F_60 ( V_80 , V_119 ) ;
}
static inline int F_64 ( struct V_7 * V_8 ,
const struct V_128 * V_129 ,
enum V_126 V_127 , int V_119 )
{
int V_80 = F_65 ( V_8 -> V_130 , V_129 , V_127 ) ;
return F_60 ( V_80 , V_119 ) ;
}
int F_66 ( struct V_66 * exp , struct V_67 * V_68 ,
int V_131 , int V_132 , int V_133 ,
struct V_134 * V_135 , int V_136 )
{
struct V_54 * V_55 = exp -> V_17 -> V_74 ;
struct V_124 * V_125 = & V_68 -> V_86 ;
struct V_137 * V_138 = NULL ;
int V_36 , V_120 , V_139 , V_140 = 0 ;
F_67 ( V_141 ) ;
int V_44 ;
if ( V_135 == NULL )
V_135 = & V_141 ;
if ( F_68 ( V_55 ) ) {
F_69 ( V_125 , V_142 ) ;
V_120 = F_62 ( V_125 , V_142 , V_133 ) ;
V_36 = F_70 ( V_55 ) ?
V_143 : V_144 ;
V_139 = ! F_70 ( V_55 ) &&
V_132 == V_145 ? 1 : 0 ;
if ( V_120 > V_136 )
V_136 += F_71 ( V_55 , V_135 , V_139 ,
V_120 - V_136 , 0 , V_36 ) ;
if ( V_120 > V_136 )
V_140 = V_136 ;
else
V_140 = V_120 ;
F_72 ( V_125 , & V_146 , V_142 ,
F_73 ( V_140 , V_132 ) ) ;
}
V_44 = F_74 ( V_68 , V_131 , V_132 ) ;
if ( V_44 ) {
F_75 ( V_135 , V_147 , V_136 ) ;
return V_44 ;
}
if ( F_68 ( V_55 ) ) {
if ( V_133 ) {
V_138 = F_76 ( V_125 , & V_146 ) ;
F_42 ( V_138 ) ;
V_138 -> V_148 = V_133 ;
}
F_77 ( V_135 , V_140 , V_68 , 0 ) ;
F_77 ( V_135 , V_136 - V_140 , NULL , 0 ) ;
} else {
F_75 ( V_135 , V_147 , V_136 ) ;
}
return 0 ;
}
int F_78 ( struct V_66 * exp , struct V_67 * V_68 ,
struct V_134 * V_135 , int V_136 )
{
return F_66 ( exp , V_68 , V_149 , V_145 ,
V_150 , V_135 , V_136 ) ;
}
int F_79 ( struct V_66 * exp , struct V_67 * * V_151 ,
struct V_152 * V_153 ,
const struct V_154 * V_155 ,
T_6 const * V_156 , T_1 * V_36 ,
void * V_70 , T_2 V_71 , enum V_157 V_157 ,
struct V_72 * V_73 , int V_158 )
{
struct V_54 * V_55 ;
struct V_4 * V_5 ;
struct V_137 * V_159 ;
int V_75 = * V_36 & V_76 ;
int V_160 = 1 ;
int V_44 , V_117 ;
struct V_67 * V_68 ;
F_42 ( exp != NULL ) ;
V_55 = exp -> V_17 -> V_74 ;
if ( V_75 ) {
V_5 = F_80 ( V_73 , 0 ) ;
F_42 ( V_5 != NULL ) ;
F_5 ( V_5 , L_28 ) ;
F_42 ( exp == V_5 -> V_11 ) ;
} else {
const struct V_161 V_162 = {
. V_163 = V_153 -> V_164 ,
. V_165 = V_153 -> V_166 ,
. V_167 = V_153 -> V_168
} ;
V_5 = F_81 ( V_55 , V_155 , V_153 -> V_169 ,
V_153 -> V_170 , & V_162 , V_153 -> V_171 ,
V_71 , V_157 ) ;
if ( V_5 == NULL )
return - V_106 ;
F_82 ( V_5 , V_153 -> V_170 ) ;
F_83 ( V_5 , V_73 ) ;
if ( V_156 != NULL )
V_5 -> V_109 = * V_156 ;
if ( V_153 -> V_169 == V_113 )
V_5 -> V_172 = V_156 -> V_173 ;
F_5 ( V_5 , L_29 ,
* V_36 ) ;
}
V_5 -> V_11 = exp ;
V_5 -> V_174 = NULL ;
V_5 -> V_175 = V_153 -> V_166 ;
V_5 -> V_32 |= ( * V_36 & ( V_176 | V_177 ) ) ;
if ( V_151 == NULL || * V_151 == NULL ) {
V_68 = F_84 ( F_85 ( exp ) ,
& V_178 ,
V_149 ,
V_145 ) ;
if ( V_68 == NULL ) {
F_34 ( V_55 , V_5 , V_153 -> V_170 ) ;
F_59 ( V_5 ) ;
return - V_106 ;
}
V_160 = 0 ;
if ( V_151 )
* V_151 = V_68 ;
} else {
int V_179 ;
V_68 = * V_151 ;
V_179 = F_46 ( & V_68 -> V_86 , & V_146 ,
V_142 ) ;
F_43 ( V_179 >= sizeof( * V_159 ) , L_30 ,
V_180 , V_179 , ( int ) sizeof( * V_159 ) ) ;
}
V_159 = F_76 ( & V_68 -> V_86 , & V_146 ) ;
F_86 ( V_5 , & V_159 -> V_102 ) ;
V_159 -> V_96 = F_87 ( * V_36 ) ;
V_159 -> V_94 [ 0 ] = * V_73 ;
if ( ! V_160 ) {
if ( V_71 > 0 )
F_88 ( & V_68 -> V_86 ,
& V_181 ) ;
F_72 ( & V_68 -> V_86 , & V_89 , V_90 ,
V_71 ) ;
F_89 ( V_68 ) ;
}
F_42 ( F_44 ( V_112 , V_153 -> V_169 != V_113 ||
V_156 -> V_173 . V_182 == V_183 ) ) ;
if ( V_158 ) {
F_42 ( V_151 != NULL ) ;
return 0 ;
}
F_5 ( V_5 , L_31 ) ;
V_44 = F_90 ( V_68 ) ;
V_117 = F_40 ( exp , V_68 , V_153 -> V_169 , V_156 ? 1 : 0 ,
V_153 -> V_170 , V_36 , V_70 , V_71 ,
V_73 , V_44 ) ;
if ( V_117 == - V_81 )
F_59 ( V_5 ) ;
else
V_44 = V_117 ;
if ( ! V_160 && V_68 != NULL ) {
F_91 ( V_68 ) ;
if ( V_151 )
* V_151 = NULL ;
}
return V_44 ;
}
static T_1 F_92 ( struct V_4 * V_5 )
{
T_1 V_44 = V_60 ;
if ( V_5 -> V_11 ) {
bool V_184 ;
F_5 ( V_5 , L_32 ) ;
F_35 ( V_5 ) ;
V_5 -> V_32 |= V_62 ;
V_184 = ! ! ( V_5 -> V_32 &
( V_60 | V_185 ) ) ;
F_93 ( V_5 ) ;
V_44 = ( V_5 -> V_32 & V_114 ) ?
V_114 : V_186 ;
F_36 ( V_5 ) ;
if ( V_184 ) {
F_51 ( V_16 , L_33 ) ;
V_44 = V_60 ;
}
F_94 ( V_5 ) ;
} else {
F_13 ( V_5 , L_34 ) ;
F_95 () ;
}
return V_44 ;
}
static void F_96 ( struct V_67 * V_68 ,
struct V_134 * V_141 , int V_136 )
{
struct V_137 * V_138 ;
struct V_4 * V_5 ;
int F_19 , V_187 = 0 ;
V_138 = F_76 ( & V_68 -> V_86 , & V_146 ) ;
F_42 ( V_138 != NULL ) ;
F_19 = F_46 ( & V_68 -> V_86 , & V_146 , V_142 ) -
sizeof( struct V_137 ) ;
F_19 /= sizeof( struct V_72 ) ;
F_19 += V_123 ;
F_42 ( F_19 >= V_138 -> V_148 + V_136 ) ;
F_97 (lock, head, l_bl_ast) {
if ( ! V_136 -- )
break;
F_42 ( V_5 -> V_11 ) ;
F_5 ( V_5 , L_35 ) ;
V_138 -> V_94 [ V_138 -> V_148 ++ ] = V_5 -> V_93 ;
V_187 ++ ;
}
F_51 ( V_16 , L_36 , V_187 ) ;
}
static int F_98 ( struct V_66 * exp ,
struct V_134 * V_135 ,
int V_136 , T_7 V_36 )
{
struct V_67 * V_68 = NULL ;
struct V_7 * V_8 ;
int free , V_188 = 0 ;
int V_44 = 0 ;
F_42 ( exp != NULL ) ;
F_42 ( V_136 > 0 ) ;
F_99 ( V_189 , V_190 ) ;
if ( F_100 ( V_191 ) )
return V_136 ;
free = F_64 ( F_85 ( exp ) ,
& V_192 , V_142 , 0 ) ;
if ( V_136 > free )
V_136 = free ;
while ( 1 ) {
V_8 = F_85 ( exp ) ;
if ( V_8 == NULL || V_8 -> V_193 ) {
F_51 ( V_16 ,
L_37 , V_8 ) ;
return V_136 ;
}
V_68 = F_101 ( V_8 , & V_192 ) ;
if ( V_68 == NULL ) {
V_44 = - V_106 ;
goto V_194;
}
F_69 ( & V_68 -> V_86 , V_142 ) ;
F_72 ( & V_68 -> V_86 , & V_146 , V_142 ,
F_73 ( V_136 , V_195 ) ) ;
V_44 = F_74 ( V_68 , V_149 , V_195 ) ;
if ( V_44 ) {
F_102 ( V_68 ) ;
goto V_194;
}
V_68 -> V_196 = V_197 ;
V_68 -> V_198 = V_199 ;
F_103 ( V_68 ) ;
F_96 ( V_68 , V_135 , V_136 ) ;
F_89 ( V_68 ) ;
if ( V_36 & V_200 ) {
F_104 ( V_68 ) ;
V_188 = V_136 ;
goto V_194;
}
V_44 = F_90 ( V_68 ) ;
if ( V_44 == V_201 ) {
F_51 ( V_16 , L_38 ,
F_105 ( V_68 -> V_202 ->
V_22 -> V_203 . V_204 ) ) ;
V_44 = 0 ;
} else if ( V_44 == - V_205 &&
V_68 -> V_206 == V_8 -> V_207 ) {
F_91 ( V_68 ) ;
continue;
} else if ( V_44 != V_83 ) {
F_106 ( V_44 == - V_208 ? V_16 : V_209 ,
L_39 ,
V_44 ) ;
break;
}
V_188 = V_136 ;
break;
}
F_91 ( V_68 ) ;
V_194:
return V_188 ? V_188 : V_44 ;
}
static inline struct V_210 * F_107 ( struct V_7 * V_8 )
{
F_42 ( V_8 != NULL ) ;
return & V_8 -> V_211 -> V_74 -> V_212 ;
}
int F_108 ( struct V_67 * V_68 )
{
struct V_9 * V_10 ;
T_1 V_213 ;
T_2 V_214 ;
if ( F_47 ( ! V_68 -> V_202 || ! V_68 -> V_202 -> V_211 ||
! F_109 ( V_68 -> V_202 ) ) ) {
return 0 ;
}
if ( F_110 ( V_68 -> V_215 ) == 0 ||
F_111 ( V_68 -> V_215 ) == 0 ) {
F_112 ( V_216 , V_68 ,
L_40 ,
F_110 ( V_68 -> V_215 ) ,
F_111 ( V_68 -> V_215 ) ) ;
return 0 ;
}
V_214 = F_111 ( V_68 -> V_215 ) ;
V_213 = F_110 ( V_68 -> V_215 ) ;
V_10 = V_68 -> V_202 -> V_211 ;
F_113 ( & V_10 -> V_217 ) ;
V_10 -> V_218 = V_213 ;
V_10 -> V_219 = V_214 ;
F_114 ( & V_10 -> V_217 ) ;
return 0 ;
}
int F_115 ( struct V_72 * V_73 ,
T_7 V_220 )
{
struct V_66 * exp ;
int V_120 , V_36 , V_136 = 1 ;
T_1 V_44 = 0 ;
struct V_54 * V_55 ;
struct V_4 * V_5 ;
F_67 ( V_135 ) ;
V_5 = F_80 ( V_73 , V_186 ) ;
if ( V_5 == NULL ) {
F_116 ( L_41 ) ;
return 0 ;
}
V_44 = F_92 ( V_5 ) ;
if ( V_44 == V_60 || V_220 & V_221 ) {
F_59 ( V_5 ) ;
return 0 ;
}
F_42 ( F_117 ( & V_5 -> V_147 ) ) ;
F_118 ( & V_5 -> V_147 , & V_135 ) ;
exp = V_5 -> V_11 ;
if ( F_119 ( exp ) ) {
V_120 = F_64 ( F_85 ( exp ) ,
& V_192 ,
V_142 , 0 ) ;
F_42 ( V_120 > 0 ) ;
V_55 = F_10 ( V_5 ) ;
V_36 = F_70 ( V_55 ) ?
V_143 : V_144 ;
V_136 += F_71 ( V_55 , & V_135 , 0 , V_120 - 1 ,
V_222 , V_36 ) ;
}
F_77 ( & V_135 , V_136 , NULL , V_220 ) ;
return 0 ;
}
int F_120 ( struct V_134 * V_135 , int V_136 ,
T_7 V_36 )
{
F_67 ( V_141 ) ;
struct V_4 * V_5 , * V_223 ;
int V_224 = 0 , V_225 = 0 ;
T_1 V_44 ;
V_224 = V_136 ;
F_121 (lock, next, cancels, l_bl_ast) {
if ( V_224 -- == 0 )
break;
if ( V_36 & V_221 ) {
V_44 = V_60 ;
F_94 ( V_5 ) ;
} else {
V_44 = F_92 ( V_5 ) ;
}
if ( ! ( V_36 & V_222 ) && ( V_44 == V_114 ) ) {
F_5 ( V_5 , L_42 ) ;
F_122 ( & V_5 -> V_147 ) ;
F_118 ( & V_5 -> V_147 , & V_141 ) ;
V_225 ++ ;
continue;
}
if ( V_44 == V_60 ) {
F_122 ( & V_5 -> V_147 ) ;
F_59 ( V_5 ) ;
V_136 -- ;
}
}
if ( V_225 > 0 ) {
V_136 -= V_225 ;
F_77 ( & V_141 , V_225 , NULL , 0 ) ;
}
return V_136 ;
}
static T_8 F_123 ( struct V_54 * V_55 ,
struct V_4 * V_5 ,
int V_226 , int V_227 ,
int V_136 )
{
T_8 V_31 = V_228 ;
T_9 V_229 = V_55 -> V_230 ;
F_35 ( V_5 ) ;
switch ( V_5 -> V_63 -> V_64 ) {
case V_113 :
case V_107 :
if ( V_229 && V_229 ( V_5 ) )
break;
default:
V_31 = V_231 ;
V_5 -> V_32 |= V_232 ;
break;
}
F_36 ( V_5 ) ;
return V_31 ;
}
static T_8 F_124 ( struct V_54 * V_55 ,
struct V_4 * V_5 ,
int V_226 , int V_227 ,
int V_136 )
{
unsigned long V_233 = F_7 () ;
struct V_210 * V_234 = & V_55 -> V_212 ;
T_1 V_235 , V_236 , V_237 ;
unsigned long V_238 ;
if ( V_136 && V_227 >= V_136 )
return V_239 ;
V_235 = F_125 ( V_234 ) ;
V_236 = F_126 ( V_234 ) ;
V_238 = F_127 ( F_128 ( V_233 ,
V_5 -> V_240 ) ) ;
V_237 = V_236 * V_238 * V_226 ;
F_129 ( V_234 , V_237 ) ;
return ( V_235 == 0 || V_237 < V_235 ) ?
V_239 : V_228 ;
}
static T_8 F_130 ( struct V_54 * V_55 ,
struct V_4 * V_5 ,
int V_226 , int V_227 ,
int V_136 )
{
return ( V_227 >= V_136 ) ?
V_239 : V_228 ;
}
static T_8 F_131 ( struct V_54 * V_55 ,
struct V_4 * V_5 ,
int V_226 , int V_227 ,
int V_136 )
{
return ( ( V_227 >= V_136 ) &&
F_132 ( F_7 () ,
F_133 ( V_5 -> V_240 , V_55 -> V_241 ) ) ) ?
V_239 : V_228 ;
}
static T_8 F_134 ( struct V_54 * V_55 ,
struct V_4 * V_5 ,
int V_226 , int V_227 ,
int V_136 )
{
return ( V_227 >= V_136 ) ?
V_239 : V_228 ;
}
static T_10
F_135 ( struct V_54 * V_55 , int V_36 )
{
if ( V_36 & V_242 )
return F_123 ;
if ( F_70 ( V_55 ) ) {
if ( V_36 & V_243 )
return F_130 ;
else if ( V_36 & V_143 )
return F_124 ;
else if ( V_36 & V_244 )
return F_130 ;
} else {
if ( V_36 & V_144 )
return F_131 ;
}
return F_134 ;
}
static int F_136 ( struct V_54 * V_55 ,
struct V_134 * V_135 , int V_136 , int F_19 ,
int V_36 )
{
T_10 V_245 ;
struct V_4 * V_5 , * V_223 ;
int V_227 = 0 , V_226 , V_246 ;
F_29 ( & V_55 -> V_247 ) ;
V_226 = V_55 -> V_248 ;
V_246 = V_226 ;
if ( ! F_70 ( V_55 ) )
V_136 += V_226 - V_55 -> V_249 ;
V_245 = F_135 ( V_55 , V_36 ) ;
F_42 ( V_245 != NULL ) ;
while ( ! F_117 ( & V_55 -> V_250 ) ) {
T_8 V_31 ;
if ( V_246 -- <= 0 )
break;
if ( F_19 && V_227 >= F_19 )
break;
F_121 (lock, next, &ns->ns_unused_list,
l_lru) {
F_42 ( ! ( V_5 -> V_32 & V_114 ) ) ;
if ( V_36 & V_242 &&
V_5 -> V_32 & V_232 )
continue;
if ( ! ( V_5 -> V_32 & V_186 ) )
break;
F_137 ( V_5 ) ;
}
if ( & V_5 -> V_251 == & V_55 -> V_250 )
break;
F_138 ( V_5 ) ;
F_30 ( & V_55 -> V_247 ) ;
F_139 ( & V_5 -> V_252 , V_253 , V_254 ) ;
V_31 = V_245 ( V_55 , V_5 , V_226 , V_227 , V_136 ) ;
if ( V_31 == V_239 ) {
F_140 ( & V_5 -> V_252 ,
V_253 , V_254 ) ;
F_59 ( V_5 ) ;
F_29 ( & V_55 -> V_247 ) ;
break;
}
if ( V_31 == V_231 ) {
F_140 ( & V_5 -> V_252 ,
V_253 , V_254 ) ;
F_59 ( V_5 ) ;
F_29 ( & V_55 -> V_247 ) ;
continue;
}
F_35 ( V_5 ) ;
if ( ( V_5 -> V_32 & V_186 ) ||
( F_141 ( V_5 ) == 0 ) ) {
F_36 ( V_5 ) ;
F_140 ( & V_5 -> V_252 ,
V_253 , V_254 ) ;
F_59 ( V_5 ) ;
F_29 ( & V_55 -> V_247 ) ;
continue;
}
F_42 ( ! V_5 -> V_255 && ! V_5 -> V_256 ) ;
V_5 -> V_32 &= ~ V_185 ;
V_5 -> V_32 |= V_62 | V_186 ;
F_42 ( F_117 ( & V_5 -> V_147 ) ) ;
F_118 ( & V_5 -> V_147 , V_135 ) ;
F_36 ( V_5 ) ;
F_140 ( & V_5 -> V_252 , V_253 , V_254 ) ;
F_29 ( & V_55 -> V_247 ) ;
V_227 ++ ;
V_226 -- ;
}
F_30 ( & V_55 -> V_247 ) ;
return V_227 ;
}
int F_71 ( struct V_54 * V_55 ,
struct V_134 * V_135 , int V_136 , int F_19 ,
T_7 V_220 , int V_36 )
{
int V_227 ;
V_227 = F_136 ( V_55 , V_135 , V_136 , F_19 , V_36 ) ;
if ( V_227 <= 0 )
return V_227 ;
return F_120 ( V_135 , V_227 , V_220 ) ;
}
int F_142 ( struct V_54 * V_55 , int V_257 ,
T_7 V_220 ,
int V_36 )
{
F_67 ( V_135 ) ;
int V_136 , V_44 ;
V_136 = F_136 ( V_55 , & V_135 , V_257 , 0 , V_36 ) ;
V_44 = F_143 ( V_55 , NULL , & V_135 , V_136 , V_220 ) ;
if ( V_44 == 0 )
return V_136 ;
return 0 ;
}
int F_144 ( struct V_258 * V_259 ,
struct V_134 * V_135 ,
T_6 * V_156 ,
T_5 V_56 , T_1 V_96 ,
T_7 V_220 , void * V_260 )
{
struct V_4 * V_5 ;
int V_136 = 0 ;
F_145 ( V_259 ) ;
F_97 (lock, &res->lr_granted, l_res_link) {
if ( V_260 != NULL && V_5 -> V_261 != V_260 ) {
F_13 ( V_5 , L_43 ,
V_5 -> V_261 , V_260 ) ;
continue;
}
if ( V_5 -> V_255 || V_5 -> V_256 )
continue;
if ( V_5 -> V_32 & V_114 ||
V_5 -> V_32 & V_186 )
continue;
if ( F_146 ( V_5 -> V_59 , V_56 ) )
continue;
if ( V_156 && ( V_5 -> V_63 -> V_64 == V_107 ) &&
! ( V_5 -> V_109 . V_262 . V_263 &
V_156 -> V_262 . V_263 ) )
continue;
V_5 -> V_32 |= V_62 | V_186 |
V_96 ;
F_42 ( F_117 ( & V_5 -> V_147 ) ) ;
F_118 ( & V_5 -> V_147 , V_135 ) ;
F_138 ( V_5 ) ;
V_136 ++ ;
}
F_147 ( V_259 ) ;
return F_120 ( V_135 , V_136 , V_220 ) ;
}
int F_77 ( struct V_134 * V_135 , int V_136 ,
struct V_67 * V_68 , T_7 V_36 )
{
struct V_4 * V_5 ;
int V_259 = 0 ;
if ( F_117 ( V_135 ) || V_136 == 0 )
return 0 ;
while ( V_136 > 0 ) {
F_42 ( ! F_117 ( V_135 ) ) ;
V_5 = F_148 ( V_135 -> V_223 , struct V_4 ,
V_147 ) ;
F_42 ( V_5 -> V_11 ) ;
if ( F_119 ( V_5 -> V_11 ) ) {
V_259 = V_136 ;
if ( V_68 )
F_96 ( V_68 , V_135 , V_136 ) ;
else
V_259 = F_98 ( V_5 -> V_11 ,
V_135 , V_136 ,
V_36 ) ;
} else {
V_259 = F_98 ( V_5 -> V_11 ,
V_135 , 1 , V_36 ) ;
}
if ( V_259 < 0 ) {
F_106 ( V_259 == - V_208 ? V_16 : V_209 ,
L_44 , V_259 ) ;
V_259 = V_136 ;
}
V_136 -= V_259 ;
F_75 ( V_135 , V_147 , V_259 ) ;
}
F_42 ( V_136 == 0 ) ;
return 0 ;
}
int F_149 ( struct V_54 * V_55 ,
const struct V_154 * V_155 ,
T_6 * V_156 ,
T_5 V_56 ,
T_7 V_36 ,
void * V_260 )
{
struct V_258 * V_259 ;
F_67 ( V_135 ) ;
int V_136 ;
int V_44 ;
V_259 = F_150 ( V_55 , NULL , V_155 , 0 , 0 ) ;
if ( V_259 == NULL ) {
F_51 ( V_98 , L_45 , V_155 -> V_264 [ 0 ] ) ;
return 0 ;
}
F_151 ( V_259 ) ;
V_136 = F_144 ( V_259 , & V_135 , V_156 , V_56 ,
0 , V_36 | V_222 , V_260 ) ;
V_44 = F_77 ( & V_135 , V_136 , NULL , V_36 ) ;
if ( V_44 != V_83 )
F_152 ( L_46 V_105 L_47 ,
F_53 ( V_259 ) , V_44 ) ;
F_153 ( V_259 ) ;
F_154 ( V_259 ) ;
return 0 ;
}
static int F_155 ( struct V_265 * V_266 ,
struct V_267 * V_268 ,
struct V_269 * V_270 , void * V_271 )
{
struct V_258 * V_259 = F_156 ( V_266 , V_270 ) ;
struct V_272 * V_273 = V_271 ;
F_149 ( F_157 ( V_259 ) , & V_259 -> V_104 ,
NULL , V_274 ,
V_273 -> V_275 , V_273 -> V_276 ) ;
return 0 ;
}
int F_158 ( struct V_54 * V_55 ,
const struct V_154 * V_155 ,
T_7 V_36 , void * V_260 )
{
struct V_272 V_271 = {
. V_275 = V_36 ,
. V_276 = V_260 ,
} ;
if ( V_55 == NULL )
return V_83 ;
if ( V_155 != NULL ) {
return F_149 ( V_55 , V_155 , NULL ,
V_274 , V_36 ,
V_260 ) ;
} else {
F_159 ( V_55 -> V_277 ,
F_155 , & V_271 ) ;
return V_83 ;
}
}
static int F_160 ( struct V_258 * V_259 ,
T_11 V_278 , void * V_279 )
{
struct V_134 * V_280 , * V_223 ;
struct V_4 * V_5 ;
int V_44 = V_281 ;
if ( ! V_259 )
return V_281 ;
F_145 ( V_259 ) ;
F_161 (tmp, next, &res->lr_granted) {
V_5 = F_148 ( V_280 , struct V_4 , V_282 ) ;
if ( V_278 ( V_5 , V_279 ) == V_283 ) {
V_44 = V_283 ;
goto V_194;
}
}
F_161 (tmp, next, &res->lr_waiting) {
V_5 = F_148 ( V_280 , struct V_4 , V_282 ) ;
if ( V_278 ( V_5 , V_279 ) == V_283 ) {
V_44 = V_283 ;
goto V_194;
}
}
V_194:
F_147 ( V_259 ) ;
return V_44 ;
}
static int F_162 ( struct V_4 * V_5 , void * V_279 )
{
struct V_284 * V_285 = V_279 ;
return V_285 -> V_278 ( V_5 , V_285 -> V_279 ) ;
}
static int F_163 ( struct V_265 * V_266 , struct V_267 * V_268 ,
struct V_269 * V_270 , void * V_271 )
{
struct V_258 * V_259 = F_156 ( V_266 , V_270 ) ;
return F_160 ( V_259 , F_162 , V_271 ) ==
V_283 ;
}
static void F_164 ( struct V_54 * V_55 ,
T_11 V_278 , void * V_279 )
{
struct V_284 V_285 = {
. V_278 = V_278 ,
. V_279 = V_279 ,
} ;
F_159 ( V_55 -> V_277 ,
F_163 , & V_285 ) ;
}
int F_165 ( struct V_54 * V_55 ,
const struct V_154 * V_155 ,
T_11 V_278 , void * V_1 )
{
struct V_258 * V_259 ;
int V_44 ;
if ( V_55 == NULL ) {
F_152 ( L_48 ) ;
F_95 () ;
}
V_259 = F_150 ( V_55 , NULL , V_155 , 0 , 0 ) ;
if ( V_259 == NULL )
return 0 ;
F_151 ( V_259 ) ;
V_44 = F_160 ( V_259 , V_278 , V_1 ) ;
F_153 ( V_259 ) ;
F_154 ( V_259 ) ;
return V_44 ;
}
static int F_166 ( struct V_4 * V_5 , void * V_279 )
{
struct V_134 * V_286 = V_279 ;
F_43 ( F_117 ( & V_5 -> V_287 ) ,
L_49 ,
V_5 , & V_5 -> V_287 . V_223 ,
& V_5 -> V_287 . V_288 ) ;
if ( ! ( V_5 -> V_32 & ( V_34 | V_186 ) ) ) {
F_118 ( & V_5 -> V_287 , V_286 ) ;
F_138 ( V_5 ) ;
}
return V_281 ;
}
static int F_167 ( const struct V_289 * V_290 ,
struct V_67 * V_68 ,
struct V_291 * V_292 , int V_44 )
{
struct V_4 * V_5 ;
struct V_77 * V_78 ;
struct V_66 * exp ;
F_168 ( & V_68 -> V_202 -> V_293 ) ;
if ( V_44 != V_83 )
goto V_194;
V_78 = F_45 ( & V_68 -> V_86 , & V_87 ) ;
if ( V_78 == NULL ) {
V_44 = - V_88 ;
goto V_194;
}
V_5 = F_41 ( & V_292 -> V_94 ) ;
if ( ! V_5 ) {
F_152 ( L_50 ,
V_292 -> V_94 . V_99 , V_78 -> V_94 . V_99 ,
V_68 -> V_294 -> V_295 . V_24 ,
F_169 ( V_68 -> V_296 ) ) ;
V_44 = - V_297 ;
goto V_194;
}
exp = V_68 -> V_294 ;
if ( exp && exp -> V_92 ) {
F_49 ( exp -> V_92 ,
& V_5 -> V_93 ,
& V_78 -> V_94 ,
& V_5 -> V_95 ) ;
} else {
V_5 -> V_93 = V_78 -> V_94 ;
}
F_5 ( V_5 , L_51 ) ;
F_170 ( V_68 -> V_202 ) ;
F_58 ( V_5 ) ;
V_194:
if ( V_44 != V_83 )
F_171 ( V_68 -> V_202 ) ;
return V_44 ;
}
static int F_172 ( struct V_7 * V_8 , struct V_4 * V_5 )
{
struct V_67 * V_68 ;
struct V_291 * V_292 ;
struct V_137 * V_159 ;
int V_36 ;
if ( V_5 -> V_32 & V_186 ) {
F_5 ( V_5 , L_52 ) ;
return 0 ;
}
if ( V_5 -> V_32 & V_185 ) {
F_5 ( V_5 , L_53 ) ;
F_94 ( V_5 ) ;
return 0 ;
}
if ( V_5 -> V_59 == V_5 -> V_58 )
V_36 = V_76 | V_39 ;
else if ( V_5 -> V_59 )
V_36 = V_76 | V_40 ;
else if ( ! F_117 ( & V_5 -> V_282 ) )
V_36 = V_76 | V_38 ;
else
V_36 = V_76 ;
V_68 = F_84 ( V_8 , & V_178 ,
V_149 , V_145 ) ;
if ( V_68 == NULL )
return - V_106 ;
V_68 -> V_298 = V_299 ;
V_159 = F_76 ( & V_68 -> V_86 , & V_146 ) ;
F_86 ( V_5 , & V_159 -> V_102 ) ;
V_159 -> V_96 = F_87 ( V_36 ) ;
F_83 ( V_5 , & V_159 -> V_94 [ 0 ] ) ;
if ( V_5 -> V_82 > 0 )
F_88 ( & V_68 -> V_86 , & V_181 ) ;
F_72 ( & V_68 -> V_86 , & V_89 , V_90 ,
V_5 -> V_82 ) ;
F_89 ( V_68 ) ;
F_173 ( V_68 -> V_300 , V_301 ) ;
F_5 ( V_5 , L_54 ) ;
F_174 ( & V_68 -> V_202 -> V_293 ) ;
F_175 ( sizeof( * V_292 ) <= sizeof( V_68 -> V_302 ) ) ;
V_292 = F_176 ( V_68 ) ;
V_292 -> V_94 = V_159 -> V_94 [ 0 ] ;
V_68 -> V_303 = ( V_304 ) F_167 ;
F_104 ( V_68 ) ;
return 0 ;
}
static void F_177 ( struct V_54 * V_55 )
{
int V_305 ;
F_67 ( V_135 ) ;
F_51 ( V_16 , L_55 ,
F_178 ( V_55 ) , V_55 -> V_248 ) ;
V_305 = F_71 ( V_55 , & V_135 , V_55 -> V_248 , 0 ,
V_221 , V_242 ) ;
F_51 ( V_16 , L_56 ,
V_305 , F_178 ( V_55 ) ) ;
}
int F_179 ( struct V_7 * V_8 )
{
struct V_54 * V_55 = V_8 -> V_211 -> V_74 ;
F_67 ( V_286 ) ;
struct V_4 * V_5 , * V_223 ;
int V_44 = 0 ;
F_42 ( F_180 ( & V_8 -> V_293 ) == 0 ) ;
if ( V_8 -> V_306 )
return 0 ;
F_174 ( & V_8 -> V_293 ) ;
if ( V_307 )
F_177 ( V_55 ) ;
F_164 ( V_55 , F_166 , & V_286 ) ;
F_121 (lock, next, &list, l_pending_chain) {
F_122 ( & V_5 -> V_287 ) ;
if ( V_44 ) {
F_59 ( V_5 ) ;
continue;
}
V_44 = F_172 ( V_8 , V_5 ) ;
F_59 ( V_5 ) ;
}
F_168 ( & V_8 -> V_293 ) ;
return V_44 ;
}
