static void F_1 ( void * V_1 )
{
}
static int F_2 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
if ( ! V_5 -> V_11 ) {
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
if ( V_10 )
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
if ( V_8 ) {
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
enum V_69 type , T_3 V_70 ,
enum V_71 V_56 ,
T_1 * V_36 , void * V_72 , T_2 V_73 ,
struct V_74 * V_75 , int V_44 )
{
struct V_54 * V_55 = exp -> V_17 -> V_76 ;
int V_77 = * V_36 & V_78 ;
struct V_4 * V_5 ;
struct V_79 * V_80 ;
int V_81 = 1 ;
int V_82 = 0 ;
V_5 = F_41 ( V_75 ) ;
if ( ! V_5 ) {
F_42 ( type == V_65 ) ;
return - V_83 ;
}
F_43 ( F_44 ( V_73 != 0 , V_73 == V_5 -> V_84 ) ,
L_13 , V_73 , V_5 -> V_84 ) ;
if ( V_44 != V_85 ) {
F_42 ( ! V_77 ) ;
F_5 ( V_5 , L_14 ,
V_44 == V_86 ? L_15 : L_16 ) ;
if ( V_44 != V_86 )
goto V_87;
}
V_80 = F_45 ( & V_68 -> V_88 , & V_89 ) ;
if ( ! V_80 ) {
V_44 = - V_90 ;
goto V_87;
}
if ( V_73 != 0 ) {
F_42 ( V_72 ) ;
V_82 = F_46 ( & V_68 -> V_88 , & V_91 ,
V_92 ) ;
if ( V_82 < 0 ) {
F_13 ( V_5 , L_17 , V_82 ) ;
V_44 = V_82 ;
goto V_87;
} else if ( F_47 ( V_82 > V_73 ) ) {
F_13 ( V_5 , L_18 ,
V_73 , V_82 ) ;
V_44 = - V_93 ;
goto V_87;
}
}
if ( V_44 == V_86 ) {
if ( V_73 != 0 )
V_44 = F_48 ( V_5 , & V_68 -> V_88 , V_92 ,
V_72 , V_82 ) ;
if ( V_44 == 0 )
V_44 = V_86 ;
goto V_87;
}
V_81 = 0 ;
F_35 ( V_5 ) ;
if ( exp -> V_94 ) {
F_49 ( exp -> V_94 ,
& V_5 -> V_95 ,
& V_80 -> V_96 ,
& V_5 -> V_97 ) ;
} else {
V_5 -> V_95 = V_80 -> V_96 ;
}
* V_36 = F_50 ( V_80 -> V_98 ) ;
V_5 -> V_32 |= F_50 ( V_80 -> V_98 &
V_99 ) ;
V_5 -> V_32 |= F_50 ( V_80 -> V_98 &
V_46 ) ;
F_36 ( V_5 ) ;
F_51 ( V_100 , L_19 ,
V_5 , V_80 -> V_96 . V_101 , * V_36 ) ;
if ( ( * V_36 ) & V_102 ) {
int V_103 = V_80 -> V_104 . V_58 ;
F_42 ( ! V_77 ) ;
if ( V_103 && V_103 != V_5 -> V_58 ) {
F_5 ( V_5 , L_20 ,
V_105 [ V_103 ] ) ;
V_5 -> V_58 = V_103 ;
}
if ( ! F_52 ( & V_80 -> V_104 . V_63 . V_106 ,
& V_5 -> V_63 -> V_106 ) ) {
F_51 ( V_100 , L_21 V_107
L_22 V_107 L_23 ,
F_53 ( & V_80 -> V_104 . V_63 ) ,
F_53 ( V_5 -> V_63 ) ) ;
V_44 = F_54 ( V_55 , V_5 ,
& V_80 -> V_104 . V_63 . V_106 ) ;
if ( V_44 || ! V_5 -> V_63 ) {
V_44 = - V_108 ;
goto V_87;
}
F_5 ( V_5 , L_24 ) ;
}
if ( V_70 )
if ( ! ( type == V_109 &&
! ( F_55 ( exp ) & V_110 ) ) )
F_56 ( exp ,
V_5 -> V_63 -> V_64 ,
& V_80 -> V_104 . V_111 ,
& V_5 -> V_111 ) ;
if ( type != V_112 )
F_5 ( V_5 ,
L_25 ) ;
}
if ( ( * V_36 ) & V_113 ||
( V_114 && type == V_115 ) ) {
F_35 ( V_5 ) ;
V_5 -> V_32 |= V_62 | V_116 ;
F_36 ( V_5 ) ;
F_5 ( V_5 , L_26 ) ;
}
if ( V_73 != 0 ) {
F_35 ( V_5 ) ;
if ( V_5 -> V_58 != V_5 -> V_59 )
V_44 = F_48 ( V_5 , & V_68 -> V_88 , V_92 ,
V_5 -> V_117 , V_82 ) ;
F_36 ( V_5 ) ;
if ( V_44 < 0 ) {
V_81 = 1 ;
goto V_87;
}
}
if ( ! V_77 ) {
V_44 = F_57 ( V_55 , & V_5 , NULL , V_36 ) ;
if ( V_5 -> V_118 ) {
int V_119 = V_5 -> V_118 ( V_5 , * V_36 , NULL ) ;
if ( ! V_44 )
V_44 = V_119 ;
if ( V_44 )
V_81 = 1 ;
}
}
if ( V_73 && V_72 ) {
memcpy ( V_72 , V_5 -> V_117 , V_73 ) ;
}
F_5 ( V_5 , L_27 ) ;
V_87:
if ( V_81 == 1 && V_44 )
F_34 ( V_55 , V_5 , V_56 ) ;
F_58 ( V_5 ) ;
F_59 ( V_5 ) ;
return V_44 ;
}
static inline int F_60 ( int V_120 , int V_121 )
{
int V_122 ;
V_122 = F_18 ( int , V_123 , V_124 - 512 ) - V_120 ;
if ( F_61 ( V_122 >= 0 ) )
V_122 /= ( int ) sizeof( struct V_74 ) ;
else
V_122 = 0 ;
V_122 += V_125 - V_121 ;
return V_122 ;
}
static inline int F_62 ( struct V_126 * V_127 ,
enum V_128 V_129 ,
int V_121 )
{
int V_82 = F_63 ( V_127 , V_129 ) ;
return F_60 ( V_82 , V_121 ) ;
}
static inline int F_64 ( struct V_7 * V_8 ,
const struct V_130 * V_131 ,
enum V_128 V_129 , int V_121 )
{
int V_82 = F_65 ( V_8 -> V_132 , V_131 , V_129 ) ;
return F_60 ( V_82 , V_121 ) ;
}
int F_66 ( struct V_66 * exp , struct V_67 * V_68 ,
int V_133 , int V_134 , int V_135 ,
struct V_136 * V_137 , int V_138 )
{
struct V_54 * V_55 = exp -> V_17 -> V_76 ;
struct V_126 * V_127 = & V_68 -> V_88 ;
struct V_139 * V_140 = NULL ;
int V_36 , V_122 , V_141 , V_142 = 0 ;
F_67 ( V_143 ) ;
int V_44 ;
if ( ! V_137 )
V_137 = & V_143 ;
if ( F_68 ( V_55 ) ) {
F_69 ( V_127 , V_144 ) ;
V_122 = F_62 ( V_127 , V_144 , V_135 ) ;
V_36 = F_70 ( V_55 ) ?
V_145 : V_146 ;
V_141 = ! F_70 ( V_55 ) &&
V_134 == V_147 ? 1 : 0 ;
if ( V_122 > V_138 )
V_138 += F_71 ( V_55 , V_137 , V_141 ,
V_122 - V_138 , 0 , V_36 ) ;
if ( V_122 > V_138 )
V_142 = V_138 ;
else
V_142 = V_122 ;
F_72 ( V_127 , & V_148 , V_144 ,
F_73 ( V_142 , V_134 ) ) ;
}
V_44 = F_74 ( V_68 , V_133 , V_134 ) ;
if ( V_44 ) {
F_75 ( V_137 , V_149 , V_138 ) ;
return V_44 ;
}
if ( F_68 ( V_55 ) ) {
if ( V_135 ) {
V_140 = F_76 ( V_127 , & V_148 ) ;
F_42 ( V_140 ) ;
V_140 -> V_150 = V_135 ;
}
F_77 ( V_137 , V_142 , V_68 , 0 ) ;
F_77 ( V_137 , V_138 - V_142 , NULL , 0 ) ;
} else {
F_75 ( V_137 , V_149 , V_138 ) ;
}
return 0 ;
}
int F_78 ( struct V_66 * exp , struct V_67 * V_68 ,
struct V_136 * V_137 , int V_138 )
{
return F_66 ( exp , V_68 , V_151 , V_147 ,
V_152 , V_137 , V_138 ) ;
}
int F_79 ( struct V_66 * exp , struct V_67 * * V_153 ,
struct V_154 * V_155 ,
const struct V_156 * V_157 ,
T_4 const * V_158 , T_1 * V_36 ,
void * V_72 , T_2 V_73 , enum V_159 V_159 ,
struct V_74 * V_75 , int V_160 )
{
struct V_54 * V_55 ;
struct V_4 * V_5 ;
struct V_139 * V_161 ;
int V_77 = * V_36 & V_78 ;
int V_162 = 1 ;
int V_44 , V_119 ;
struct V_67 * V_68 ;
V_55 = exp -> V_17 -> V_76 ;
if ( V_77 ) {
V_5 = F_80 ( V_75 , 0 ) ;
F_42 ( V_5 ) ;
F_5 ( V_5 , L_28 ) ;
F_42 ( exp == V_5 -> V_11 ) ;
} else {
const struct V_163 V_164 = {
. V_165 = V_155 -> V_166 ,
. V_167 = V_155 -> V_168 ,
. V_169 = V_155 -> V_170
} ;
V_5 = F_81 ( V_55 , V_157 , V_155 -> V_171 ,
V_155 -> V_172 , & V_164 , V_155 -> V_173 ,
V_73 , V_159 ) ;
if ( ! V_5 )
return - V_108 ;
F_82 ( V_5 , V_155 -> V_172 ) ;
F_83 ( V_5 , V_75 ) ;
if ( V_158 )
V_5 -> V_111 = * V_158 ;
if ( V_155 -> V_171 == V_115 ) {
if ( ! V_158 )
F_84 () ;
V_5 -> V_174 = V_158 -> V_175 ;
}
F_5 ( V_5 , L_29 ,
* V_36 ) ;
}
V_5 -> V_11 = exp ;
V_5 -> V_176 = NULL ;
V_5 -> V_177 = V_155 -> V_168 ;
V_5 -> V_32 |= ( * V_36 & ( V_178 | V_179 ) ) ;
if ( ! V_153 || ! * V_153 ) {
V_68 = F_85 ( F_86 ( exp ) ,
& V_180 ,
V_151 ,
V_147 ) ;
if ( ! V_68 ) {
F_34 ( V_55 , V_5 , V_155 -> V_172 ) ;
F_59 ( V_5 ) ;
return - V_108 ;
}
V_162 = 0 ;
if ( V_153 )
* V_153 = V_68 ;
} else {
int V_181 ;
V_68 = * V_153 ;
V_181 = F_46 ( & V_68 -> V_88 , & V_148 ,
V_144 ) ;
F_43 ( V_181 >= sizeof( * V_161 ) , L_30 ,
V_182 , V_181 , ( int ) sizeof( * V_161 ) ) ;
}
V_161 = F_76 ( & V_68 -> V_88 , & V_148 ) ;
F_87 ( V_5 , & V_161 -> V_104 ) ;
V_161 -> V_98 = F_88 ( * V_36 ) ;
V_161 -> V_96 [ 0 ] = * V_75 ;
if ( ! V_162 ) {
if ( V_73 > 0 )
F_89 ( & V_68 -> V_88 ,
& V_183 ) ;
F_72 ( & V_68 -> V_88 , & V_91 , V_92 ,
V_73 ) ;
F_90 ( V_68 ) ;
}
F_42 ( F_44 ( V_114 , V_155 -> V_171 != V_115 ||
V_158 -> V_175 . V_184 == V_185 ) ) ;
if ( V_160 ) {
F_42 ( V_153 ) ;
return 0 ;
}
F_5 ( V_5 , L_31 ) ;
V_44 = F_91 ( V_68 ) ;
V_119 = F_40 ( exp , V_68 , V_155 -> V_171 , V_158 ? 1 : 0 ,
V_155 -> V_172 , V_36 , V_72 , V_73 ,
V_75 , V_44 ) ;
if ( V_119 == - V_83 )
F_59 ( V_5 ) ;
else
V_44 = V_119 ;
if ( ! V_162 && V_68 ) {
F_92 ( V_68 ) ;
if ( V_153 )
* V_153 = NULL ;
}
return V_44 ;
}
static T_1 F_93 ( struct V_4 * V_5 )
{
T_1 V_44 = V_60 ;
if ( V_5 -> V_11 ) {
bool V_186 ;
F_5 ( V_5 , L_32 ) ;
F_35 ( V_5 ) ;
V_5 -> V_32 |= V_62 ;
V_186 = ! ! ( V_5 -> V_32 &
( V_60 | V_187 ) ) ;
F_94 ( V_5 ) ;
V_44 = ( V_5 -> V_32 & V_116 ) ?
V_116 : V_188 ;
F_36 ( V_5 ) ;
if ( V_186 ) {
F_51 ( V_16 , L_33 ) ;
V_44 = V_60 ;
}
F_95 ( V_5 ) ;
} else {
F_13 ( V_5 , L_34 ) ;
F_84 () ;
}
return V_44 ;
}
static void F_96 ( struct V_67 * V_68 ,
struct V_136 * V_143 , int V_138 )
{
struct V_139 * V_140 ;
struct V_4 * V_5 ;
int F_19 , V_189 = 0 ;
V_140 = F_76 ( & V_68 -> V_88 , & V_148 ) ;
F_42 ( V_140 ) ;
F_19 = F_46 ( & V_68 -> V_88 , & V_148 , V_144 ) -
sizeof( struct V_139 ) ;
F_19 /= sizeof( struct V_74 ) ;
F_19 += V_125 ;
F_42 ( F_19 >= V_140 -> V_150 + V_138 ) ;
F_97 (lock, head, l_bl_ast) {
if ( ! V_138 -- )
break;
F_42 ( V_5 -> V_11 ) ;
F_5 ( V_5 , L_35 ) ;
V_140 -> V_96 [ V_140 -> V_150 ++ ] = V_5 -> V_95 ;
V_189 ++ ;
}
F_51 ( V_16 , L_36 , V_189 ) ;
}
static int F_98 ( struct V_66 * exp ,
struct V_136 * V_137 ,
int V_138 , enum V_190 V_36 )
{
struct V_67 * V_68 = NULL ;
struct V_7 * V_8 ;
int free , V_191 = 0 ;
int V_44 = 0 ;
F_42 ( exp ) ;
F_42 ( V_138 > 0 ) ;
F_99 ( V_192 , V_193 ) ;
if ( F_100 ( V_194 ) )
return V_138 ;
free = F_64 ( F_86 ( exp ) ,
& V_195 , V_144 , 0 ) ;
if ( V_138 > free )
V_138 = free ;
while ( 1 ) {
V_8 = F_86 ( exp ) ;
if ( ! V_8 || V_8 -> V_196 ) {
F_51 ( V_16 ,
L_37 , V_8 ) ;
return V_138 ;
}
V_68 = F_101 ( V_8 , & V_195 ) ;
if ( ! V_68 ) {
V_44 = - V_108 ;
goto V_197;
}
F_69 ( & V_68 -> V_88 , V_144 ) ;
F_72 ( & V_68 -> V_88 , & V_148 , V_144 ,
F_73 ( V_138 , V_198 ) ) ;
V_44 = F_74 ( V_68 , V_151 , V_198 ) ;
if ( V_44 ) {
F_102 ( V_68 ) ;
goto V_197;
}
V_68 -> V_199 = V_200 ;
V_68 -> V_201 = V_202 ;
F_103 ( V_68 ) ;
F_96 ( V_68 , V_137 , V_138 ) ;
F_90 ( V_68 ) ;
if ( V_36 & V_203 ) {
F_104 ( V_68 ) ;
V_191 = V_138 ;
goto V_197;
}
V_44 = F_91 ( V_68 ) ;
if ( V_44 == V_204 ) {
F_51 ( V_16 , L_38 ,
F_105 ( V_68 -> V_205 ->
V_22 -> V_206 . V_207 ) ) ;
V_44 = 0 ;
} else if ( V_44 == - V_208 &&
V_68 -> V_209 == V_8 -> V_210 ) {
F_92 ( V_68 ) ;
continue;
} else if ( V_44 != V_85 ) {
F_106 ( V_44 == - V_211 ? V_16 : V_212 ,
L_39 ,
V_44 ) ;
break;
}
V_191 = V_138 ;
break;
}
F_92 ( V_68 ) ;
V_197:
return V_191 ? V_191 : V_44 ;
}
static inline struct V_213 * F_107 ( struct V_7 * V_8 )
{
return & V_8 -> V_214 -> V_76 -> V_215 ;
}
int F_108 ( struct V_67 * V_68 )
{
struct V_9 * V_10 ;
T_1 V_216 ;
T_2 V_217 ;
if ( F_47 ( ! V_68 -> V_205 || ! V_68 -> V_205 -> V_214 ||
! F_109 ( V_68 -> V_205 ) ) ) {
return 0 ;
}
if ( F_110 ( V_68 -> V_218 ) == 0 ||
F_111 ( V_68 -> V_218 ) == 0 ) {
F_112 ( V_219 , V_68 ,
L_40 ,
F_110 ( V_68 -> V_218 ) ,
F_111 ( V_68 -> V_218 ) ) ;
return 0 ;
}
V_217 = F_111 ( V_68 -> V_218 ) ;
V_216 = F_110 ( V_68 -> V_218 ) ;
V_10 = V_68 -> V_205 -> V_214 ;
F_113 ( & V_10 -> V_220 ) ;
V_10 -> V_221 = V_216 ;
V_10 -> V_222 = V_217 ;
F_114 ( & V_10 -> V_220 ) ;
return 0 ;
}
int F_115 ( struct V_74 * V_75 ,
enum V_190 V_223 )
{
struct V_66 * exp ;
int V_122 , V_36 , V_138 = 1 ;
T_1 V_44 = 0 ;
struct V_54 * V_55 ;
struct V_4 * V_5 ;
F_67 ( V_137 ) ;
V_5 = F_80 ( V_75 , V_188 ) ;
if ( ! V_5 ) {
F_116 ( L_41 ) ;
return 0 ;
}
V_44 = F_93 ( V_5 ) ;
if ( V_44 == V_60 || V_223 & V_224 ) {
F_59 ( V_5 ) ;
return 0 ;
}
F_42 ( F_117 ( & V_5 -> V_149 ) ) ;
F_118 ( & V_5 -> V_149 , & V_137 ) ;
exp = V_5 -> V_11 ;
if ( F_119 ( exp ) ) {
V_122 = F_64 ( F_86 ( exp ) ,
& V_195 ,
V_144 , 0 ) ;
F_42 ( V_122 > 0 ) ;
V_55 = F_10 ( V_5 ) ;
V_36 = F_70 ( V_55 ) ?
V_145 : V_146 ;
V_138 += F_71 ( V_55 , & V_137 , 0 , V_122 - 1 ,
V_225 , V_36 ) ;
}
F_77 ( & V_137 , V_138 , NULL , V_223 ) ;
return 0 ;
}
int F_120 ( struct V_136 * V_137 , int V_138 ,
enum V_190 V_36 )
{
F_67 ( V_143 ) ;
struct V_4 * V_5 , * V_226 ;
int V_227 = 0 , V_228 = 0 ;
T_1 V_44 ;
V_227 = V_138 ;
F_121 (lock, next, cancels, l_bl_ast) {
if ( V_227 -- == 0 )
break;
if ( V_36 & V_224 ) {
V_44 = V_60 ;
F_95 ( V_5 ) ;
} else {
V_44 = F_93 ( V_5 ) ;
}
if ( ! ( V_36 & V_225 ) && ( V_44 == V_116 ) ) {
F_5 ( V_5 , L_42 ) ;
F_122 ( & V_5 -> V_149 ) ;
F_118 ( & V_5 -> V_149 , & V_143 ) ;
V_228 ++ ;
continue;
}
if ( V_44 == V_60 ) {
F_122 ( & V_5 -> V_149 ) ;
F_59 ( V_5 ) ;
V_138 -- ;
}
}
if ( V_228 > 0 ) {
V_138 -= V_228 ;
F_77 ( & V_143 , V_228 , NULL , 0 ) ;
}
return V_138 ;
}
static T_5 F_123 ( struct V_54 * V_55 ,
struct V_4 * V_5 ,
int V_229 , int V_230 ,
int V_138 )
{
T_5 V_31 = V_231 ;
T_6 V_232 = V_55 -> V_233 ;
F_35 ( V_5 ) ;
switch ( V_5 -> V_63 -> V_64 ) {
case V_115 :
case V_109 :
if ( V_232 && V_232 ( V_5 ) )
break;
default:
V_31 = V_234 ;
V_5 -> V_32 |= V_235 ;
break;
}
F_36 ( V_5 ) ;
return V_31 ;
}
static T_5 F_124 ( struct V_54 * V_55 ,
struct V_4 * V_5 ,
int V_229 , int V_230 ,
int V_138 )
{
unsigned long V_236 = F_7 () ;
struct V_213 * V_237 = & V_55 -> V_215 ;
T_1 V_238 , V_239 , V_240 ;
unsigned long V_241 ;
if ( V_138 && V_230 >= V_138 )
return V_242 ;
V_238 = F_125 ( V_237 ) ;
V_239 = F_126 ( V_237 ) ;
V_241 = F_127 ( F_128 ( V_236 ,
V_5 -> V_243 ) ) ;
V_240 = V_239 * V_241 * V_229 ;
F_129 ( V_237 , V_240 ) ;
return ( V_238 == 0 || V_240 < V_238 ) ?
V_242 : V_231 ;
}
static T_5 F_130 ( struct V_54 * V_55 ,
struct V_4 * V_5 ,
int V_229 , int V_230 ,
int V_138 )
{
return ( V_230 >= V_138 ) ?
V_242 : V_231 ;
}
static T_5 F_131 ( struct V_54 * V_55 ,
struct V_4 * V_5 ,
int V_229 , int V_230 ,
int V_138 )
{
return ( ( V_230 >= V_138 ) &&
F_132 ( F_7 () ,
F_133 ( V_5 -> V_243 , V_55 -> V_244 ) ) ) ?
V_242 : V_231 ;
}
static T_5 F_134 ( struct V_54 * V_55 ,
struct V_4 * V_5 ,
int V_229 , int V_230 ,
int V_138 )
{
return ( V_230 >= V_138 ) ?
V_242 : V_231 ;
}
static T_7
F_135 ( struct V_54 * V_55 , int V_36 )
{
if ( V_36 & V_245 )
return F_123 ;
if ( F_70 ( V_55 ) ) {
if ( V_36 & V_246 )
return F_130 ;
else if ( V_36 & V_145 )
return F_124 ;
else if ( V_36 & V_247 )
return F_130 ;
} else {
if ( V_36 & V_146 )
return F_131 ;
}
return F_134 ;
}
static int F_136 ( struct V_54 * V_55 ,
struct V_136 * V_137 , int V_138 , int F_19 ,
int V_36 )
{
T_7 V_248 ;
struct V_4 * V_5 , * V_226 ;
int V_230 = 0 , V_229 , V_249 ;
F_29 ( & V_55 -> V_250 ) ;
V_229 = V_55 -> V_251 ;
V_249 = V_229 ;
if ( ! F_70 ( V_55 ) )
V_138 += V_229 - V_55 -> V_252 ;
V_248 = F_135 ( V_55 , V_36 ) ;
F_42 ( V_248 ) ;
while ( ! F_117 ( & V_55 -> V_253 ) ) {
T_5 V_31 ;
if ( V_249 -- <= 0 )
break;
if ( F_19 && V_230 >= F_19 )
break;
F_121 (lock, next, &ns->ns_unused_list,
l_lru) {
F_42 ( ! ( V_5 -> V_32 & V_116 ) ) ;
if ( V_36 & V_245 &&
V_5 -> V_32 & V_235 )
continue;
if ( ! ( V_5 -> V_32 & V_188 ) )
break;
F_137 ( V_5 ) ;
}
if ( & V_5 -> V_254 == & V_55 -> V_253 )
break;
F_138 ( V_5 ) ;
F_30 ( & V_55 -> V_250 ) ;
F_139 ( & V_5 -> V_255 , V_256 , V_257 ) ;
V_31 = V_248 ( V_55 , V_5 , V_229 , V_230 , V_138 ) ;
if ( V_31 == V_242 ) {
F_140 ( & V_5 -> V_255 ,
V_256 , V_257 ) ;
F_59 ( V_5 ) ;
F_29 ( & V_55 -> V_250 ) ;
break;
}
if ( V_31 == V_234 ) {
F_140 ( & V_5 -> V_255 ,
V_256 , V_257 ) ;
F_59 ( V_5 ) ;
F_29 ( & V_55 -> V_250 ) ;
continue;
}
F_35 ( V_5 ) ;
if ( ( V_5 -> V_32 & V_188 ) ||
( F_141 ( V_5 ) == 0 ) ) {
F_36 ( V_5 ) ;
F_140 ( & V_5 -> V_255 ,
V_256 , V_257 ) ;
F_59 ( V_5 ) ;
F_29 ( & V_55 -> V_250 ) ;
continue;
}
F_42 ( ! V_5 -> V_258 && ! V_5 -> V_259 ) ;
V_5 -> V_32 &= ~ V_187 ;
V_5 -> V_32 |= V_62 | V_188 ;
F_42 ( F_117 ( & V_5 -> V_149 ) ) ;
F_118 ( & V_5 -> V_149 , V_137 ) ;
F_36 ( V_5 ) ;
F_140 ( & V_5 -> V_255 , V_256 , V_257 ) ;
F_29 ( & V_55 -> V_250 ) ;
V_230 ++ ;
V_229 -- ;
}
F_30 ( & V_55 -> V_250 ) ;
return V_230 ;
}
int F_71 ( struct V_54 * V_55 ,
struct V_136 * V_137 , int V_138 , int F_19 ,
enum V_190 V_223 , int V_36 )
{
int V_230 ;
V_230 = F_136 ( V_55 , V_137 , V_138 , F_19 , V_36 ) ;
if ( V_230 <= 0 )
return V_230 ;
return F_120 ( V_137 , V_230 , V_223 ) ;
}
int F_142 ( struct V_54 * V_55 , int V_260 ,
enum V_190 V_223 ,
int V_36 )
{
F_67 ( V_137 ) ;
int V_138 , V_44 ;
V_138 = F_136 ( V_55 , & V_137 , V_260 , 0 , V_36 ) ;
V_44 = F_143 ( V_55 , NULL , & V_137 , V_138 , V_223 ) ;
if ( V_44 == 0 )
return V_138 ;
return 0 ;
}
int F_144 ( struct V_261 * V_262 ,
struct V_136 * V_137 ,
T_4 * V_158 ,
enum V_71 V_56 , T_1 V_98 ,
enum V_190 V_223 ,
void * V_263 )
{
struct V_4 * V_5 ;
int V_138 = 0 ;
F_145 ( V_262 ) ;
F_97 (lock, &res->lr_granted, l_res_link) {
if ( V_263 && V_5 -> V_264 != V_263 ) {
F_13 ( V_5 , L_43 ,
V_5 -> V_264 , V_263 ) ;
continue;
}
if ( V_5 -> V_258 || V_5 -> V_259 )
continue;
if ( V_5 -> V_32 & V_116 ||
V_5 -> V_32 & V_188 )
continue;
if ( F_146 ( V_5 -> V_59 , V_56 ) )
continue;
if ( V_158 && ( V_5 -> V_63 -> V_64 == V_109 ) &&
! ( V_5 -> V_111 . V_265 . V_266 &
V_158 -> V_265 . V_266 ) )
continue;
V_5 -> V_32 |= V_62 | V_188 |
V_98 ;
F_42 ( F_117 ( & V_5 -> V_149 ) ) ;
F_118 ( & V_5 -> V_149 , V_137 ) ;
F_138 ( V_5 ) ;
V_138 ++ ;
}
F_147 ( V_262 ) ;
return F_120 ( V_137 , V_138 , V_223 ) ;
}
int F_77 ( struct V_136 * V_137 , int V_138 ,
struct V_67 * V_68 ,
enum V_190 V_36 )
{
struct V_4 * V_5 ;
int V_262 = 0 ;
if ( F_117 ( V_137 ) || V_138 == 0 )
return 0 ;
while ( V_138 > 0 ) {
F_42 ( ! F_117 ( V_137 ) ) ;
V_5 = F_148 ( V_137 -> V_226 , struct V_4 ,
V_149 ) ;
F_42 ( V_5 -> V_11 ) ;
if ( F_119 ( V_5 -> V_11 ) ) {
V_262 = V_138 ;
if ( V_68 )
F_96 ( V_68 , V_137 , V_138 ) ;
else
V_262 = F_98 ( V_5 -> V_11 ,
V_137 , V_138 ,
V_36 ) ;
} else {
V_262 = F_98 ( V_5 -> V_11 ,
V_137 , 1 , V_36 ) ;
}
if ( V_262 < 0 ) {
F_106 ( V_262 == - V_211 ? V_16 : V_212 ,
L_44 , V_262 ) ;
V_262 = V_138 ;
}
V_138 -= V_262 ;
F_75 ( V_137 , V_149 , V_262 ) ;
}
F_42 ( V_138 == 0 ) ;
return 0 ;
}
int F_149 ( struct V_54 * V_55 ,
const struct V_156 * V_157 ,
T_4 * V_158 ,
enum V_71 V_56 ,
enum V_190 V_36 ,
void * V_263 )
{
struct V_261 * V_262 ;
F_67 ( V_137 ) ;
int V_138 ;
int V_44 ;
V_262 = F_150 ( V_55 , NULL , V_157 , 0 , 0 ) ;
if ( ! V_262 ) {
F_51 ( V_100 , L_45 , V_157 -> V_267 [ 0 ] ) ;
return 0 ;
}
F_151 ( V_262 ) ;
V_138 = F_144 ( V_262 , & V_137 , V_158 , V_56 ,
0 , V_36 | V_225 , V_263 ) ;
V_44 = F_77 ( & V_137 , V_138 , NULL , V_36 ) ;
if ( V_44 != V_85 )
F_152 ( L_46 V_107 L_47 ,
F_53 ( V_262 ) , V_44 ) ;
F_153 ( V_262 ) ;
F_154 ( V_262 ) ;
return 0 ;
}
static int F_155 ( struct V_268 * V_269 ,
struct V_270 * V_271 ,
struct V_272 * V_273 , void * V_274 )
{
struct V_261 * V_262 = F_156 ( V_269 , V_273 ) ;
struct V_275 * V_276 = V_274 ;
F_149 ( F_157 ( V_262 ) , & V_262 -> V_106 ,
NULL , V_277 ,
V_276 -> V_278 , V_276 -> V_279 ) ;
return 0 ;
}
int F_158 ( struct V_54 * V_55 ,
const struct V_156 * V_157 ,
enum V_190 V_36 , void * V_263 )
{
struct V_275 V_274 = {
. V_278 = V_36 ,
. V_279 = V_263 ,
} ;
if ( ! V_55 )
return V_85 ;
if ( V_157 ) {
return F_149 ( V_55 , V_157 , NULL ,
V_277 , V_36 ,
V_263 ) ;
} else {
F_159 ( V_55 -> V_280 ,
F_155 , & V_274 ) ;
return V_85 ;
}
}
static int F_160 ( struct V_261 * V_262 ,
T_8 V_281 , void * V_282 )
{
struct V_136 * V_283 , * V_226 ;
struct V_4 * V_5 ;
int V_44 = V_284 ;
if ( ! V_262 )
return V_284 ;
F_145 ( V_262 ) ;
F_161 (tmp, next, &res->lr_granted) {
V_5 = F_148 ( V_283 , struct V_4 , V_285 ) ;
if ( V_281 ( V_5 , V_282 ) == V_286 ) {
V_44 = V_286 ;
goto V_197;
}
}
F_161 (tmp, next, &res->lr_waiting) {
V_5 = F_148 ( V_283 , struct V_4 , V_285 ) ;
if ( V_281 ( V_5 , V_282 ) == V_286 ) {
V_44 = V_286 ;
goto V_197;
}
}
V_197:
F_147 ( V_262 ) ;
return V_44 ;
}
static int F_162 ( struct V_4 * V_5 , void * V_282 )
{
struct V_287 * V_288 = V_282 ;
return V_288 -> V_281 ( V_5 , V_288 -> V_282 ) ;
}
static int F_163 ( struct V_268 * V_269 , struct V_270 * V_271 ,
struct V_272 * V_273 , void * V_274 )
{
struct V_261 * V_262 = F_156 ( V_269 , V_273 ) ;
return F_160 ( V_262 , F_162 , V_274 ) ==
V_286 ;
}
static void F_164 ( struct V_54 * V_55 ,
T_8 V_281 , void * V_282 )
{
struct V_287 V_288 = {
. V_281 = V_281 ,
. V_282 = V_282 ,
} ;
F_159 ( V_55 -> V_280 ,
F_163 , & V_288 ) ;
}
int F_165 ( struct V_54 * V_55 ,
const struct V_156 * V_157 ,
T_8 V_281 , void * V_1 )
{
struct V_261 * V_262 ;
int V_44 ;
if ( ! V_55 ) {
F_152 ( L_48 ) ;
F_84 () ;
}
V_262 = F_150 ( V_55 , NULL , V_157 , 0 , 0 ) ;
if ( ! V_262 )
return 0 ;
F_151 ( V_262 ) ;
V_44 = F_160 ( V_262 , V_281 , V_1 ) ;
F_153 ( V_262 ) ;
F_154 ( V_262 ) ;
return V_44 ;
}
static int F_166 ( struct V_4 * V_5 , void * V_282 )
{
struct V_136 * V_289 = V_282 ;
F_43 ( F_117 ( & V_5 -> V_290 ) ,
L_49 ,
V_5 , & V_5 -> V_290 . V_226 ,
& V_5 -> V_290 . V_291 ) ;
if ( ! ( V_5 -> V_32 & ( V_34 | V_188 ) ) ) {
F_118 ( & V_5 -> V_290 , V_289 ) ;
F_138 ( V_5 ) ;
}
return V_284 ;
}
static int F_167 ( const struct V_292 * V_293 ,
struct V_67 * V_68 ,
struct V_294 * V_295 , int V_44 )
{
struct V_4 * V_5 ;
struct V_79 * V_80 ;
struct V_66 * exp ;
F_168 ( & V_68 -> V_205 -> V_296 ) ;
if ( V_44 != V_85 )
goto V_197;
V_80 = F_45 ( & V_68 -> V_88 , & V_89 ) ;
if ( ! V_80 ) {
V_44 = - V_90 ;
goto V_197;
}
V_5 = F_41 ( & V_295 -> V_96 ) ;
if ( ! V_5 ) {
F_152 ( L_50 ,
V_295 -> V_96 . V_101 , V_80 -> V_96 . V_101 ,
V_68 -> V_297 -> V_298 . V_24 ,
F_169 ( V_68 -> V_299 ) ) ;
V_44 = - V_300 ;
goto V_197;
}
exp = V_68 -> V_297 ;
if ( exp && exp -> V_94 ) {
F_49 ( exp -> V_94 ,
& V_5 -> V_95 ,
& V_80 -> V_96 ,
& V_5 -> V_97 ) ;
} else {
V_5 -> V_95 = V_80 -> V_96 ;
}
F_5 ( V_5 , L_51 ) ;
F_170 ( V_68 -> V_205 ) ;
F_58 ( V_5 ) ;
V_197:
if ( V_44 != V_85 )
F_171 ( V_68 -> V_205 ) ;
return V_44 ;
}
static int F_172 ( struct V_7 * V_8 , struct V_4 * V_5 )
{
struct V_67 * V_68 ;
struct V_294 * V_295 ;
struct V_139 * V_161 ;
int V_36 ;
if ( V_5 -> V_32 & V_188 ) {
F_5 ( V_5 , L_52 ) ;
return 0 ;
}
if ( V_5 -> V_32 & V_187 ) {
F_5 ( V_5 , L_53 ) ;
F_95 ( V_5 ) ;
return 0 ;
}
if ( V_5 -> V_59 == V_5 -> V_58 )
V_36 = V_78 | V_39 ;
else if ( V_5 -> V_59 )
V_36 = V_78 | V_40 ;
else if ( ! F_117 ( & V_5 -> V_285 ) )
V_36 = V_78 | V_38 ;
else
V_36 = V_78 ;
V_68 = F_85 ( V_8 , & V_180 ,
V_151 , V_147 ) ;
if ( ! V_68 )
return - V_108 ;
V_68 -> V_301 = V_302 ;
V_161 = F_76 ( & V_68 -> V_88 , & V_148 ) ;
F_87 ( V_5 , & V_161 -> V_104 ) ;
V_161 -> V_98 = F_88 ( V_36 ) ;
F_83 ( V_5 , & V_161 -> V_96 [ 0 ] ) ;
if ( V_5 -> V_84 > 0 )
F_89 ( & V_68 -> V_88 , & V_183 ) ;
F_72 ( & V_68 -> V_88 , & V_91 , V_92 ,
V_5 -> V_84 ) ;
F_90 ( V_68 ) ;
F_173 ( V_68 -> V_303 , V_304 ) ;
F_5 ( V_5 , L_54 ) ;
F_174 ( & V_68 -> V_205 -> V_296 ) ;
F_175 ( sizeof( * V_295 ) <= sizeof( V_68 -> V_305 ) ) ;
V_295 = F_176 ( V_68 ) ;
V_295 -> V_96 = V_161 -> V_96 [ 0 ] ;
V_68 -> V_306 = ( V_307 ) F_167 ;
F_104 ( V_68 ) ;
return 0 ;
}
static void F_177 ( struct V_54 * V_55 )
{
int V_308 ;
F_67 ( V_137 ) ;
F_51 ( V_16 , L_55 ,
F_178 ( V_55 ) , V_55 -> V_251 ) ;
V_308 = F_71 ( V_55 , & V_137 , V_55 -> V_251 , 0 ,
V_224 , V_245 ) ;
F_51 ( V_16 , L_56 ,
V_308 , F_178 ( V_55 ) ) ;
}
int F_179 ( struct V_7 * V_8 )
{
struct V_54 * V_55 = V_8 -> V_214 -> V_76 ;
F_67 ( V_289 ) ;
struct V_4 * V_5 , * V_226 ;
int V_44 = 0 ;
F_42 ( F_180 ( & V_8 -> V_296 ) == 0 ) ;
if ( V_8 -> V_309 )
return 0 ;
F_174 ( & V_8 -> V_296 ) ;
if ( V_310 )
F_177 ( V_55 ) ;
F_164 ( V_55 , F_166 , & V_289 ) ;
F_121 (lock, next, &list, l_pending_chain) {
F_122 ( & V_5 -> V_290 ) ;
if ( V_44 ) {
F_59 ( V_5 ) ;
continue;
}
V_44 = F_172 ( V_8 , V_5 ) ;
F_59 ( V_5 ) ;
}
F_168 ( & V_8 -> V_296 ) ;
return V_44 ;
}
