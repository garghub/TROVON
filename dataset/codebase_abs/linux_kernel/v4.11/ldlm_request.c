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
F_3 ( V_5 , L_1 ,
( V_14 ) V_5 -> V_15 ,
( V_14 ) ( F_4 () -
V_5 -> V_15 ) ) ;
if ( F_5 ( F_6 () , V_12 ) ) {
V_13 = V_12 ;
V_12 = F_7 ( 300 ) ;
F_8 ( V_16 ,
F_9 ( V_5 ) ) ;
if ( V_13 == 0 )
F_10 () ;
}
return 0 ;
}
V_10 = V_5 -> V_11 -> V_17 ;
V_8 = V_10 -> V_18 . V_19 . V_20 ;
F_11 ( V_8 , V_3 -> V_21 ) ;
F_3 ( V_5 , L_2 ,
( V_14 ) V_5 -> V_15 ,
( V_14 ) ( F_4 () - V_5 -> V_15 ) ,
F_12 ( V_10 ) , V_8 -> V_22 -> V_23 . V_24 ) ;
return 0 ;
}
static unsigned int F_13 ( struct V_4 * V_5 )
{
unsigned int V_25 ;
if ( V_26 )
return V_27 ;
V_25 = F_14 ( F_15 ( V_5 ) ) ;
return F_16 ( 3 * V_25 , V_28 ) ;
}
static int F_17 ( struct V_4 * V_5 , void * V_1 )
{
long V_29 ;
int V_30 = 0 ;
if ( F_18 ( V_5 ) || F_19 ( V_5 ) ) {
F_20 ( V_5 , L_3 ) ;
V_30 = - V_31 ;
} else if ( ! V_1 ) {
F_20 ( V_5 , L_4 ) ;
} else {
V_29 = F_4 () - V_5 -> V_15 ;
F_20 ( V_5 , L_5 ,
V_29 ) ;
F_21 ( F_15 ( V_5 ) , V_29 ) ;
}
return V_30 ;
}
int F_22 ( struct V_4 * V_5 , T_1 V_32 , void * V_1 )
{
if ( V_32 == V_33 ) {
F_20 ( V_5 , L_6 ) ;
return 0 ;
}
if ( ! ( V_32 & V_34 ) ) {
F_23 ( & V_5 -> V_35 ) ;
return F_17 ( V_5 , V_1 ) ;
}
F_20 ( V_5 , L_7 ) ;
return 0 ;
}
int F_24 ( struct V_4 * V_5 , T_1 V_32 , void * V_1 )
{
struct V_2 V_3 ;
struct V_9 * V_10 ;
struct V_7 * V_8 = NULL ;
struct V_36 V_37 ;
T_2 V_25 ;
int V_38 = 0 ;
if ( V_32 == V_33 ) {
F_20 ( V_5 , L_6 ) ;
goto V_39;
}
if ( ! ( V_32 & V_34 ) ) {
F_23 ( & V_5 -> V_35 ) ;
return 0 ;
}
F_20 ( V_5 , L_8 ) ;
V_39:
V_10 = F_25 ( V_5 -> V_11 ) ;
if ( V_10 )
V_8 = V_10 -> V_18 . V_19 . V_20 ;
V_25 = F_13 ( V_5 ) ;
V_3 . V_6 = V_5 ;
V_5 -> V_15 = F_4 () ;
if ( F_26 ( V_5 ) ) {
F_20 ( V_5 , L_9 ) ;
V_37 = F_27 ( F_1 , & V_3 ) ;
} else {
V_37 = F_28 ( F_29 ( V_25 ) ,
F_2 ,
F_1 , & V_3 ) ;
}
if ( V_8 ) {
F_30 ( & V_8 -> V_40 ) ;
V_3 . V_21 = V_8 -> V_41 ;
F_31 ( & V_8 -> V_40 ) ;
}
if ( F_32 ( V_42 ,
V_43 | V_44 ) ) {
F_33 ( V_5 ) ;
V_38 = - V_45 ;
} else {
V_38 = F_34 ( V_5 -> V_35 ,
F_35 ( V_5 ) , & V_37 ) ;
}
if ( V_38 ) {
F_20 ( V_5 , L_10 ,
V_38 ) ;
return V_38 ;
}
return F_17 ( V_5 , V_1 ) ;
}
static void F_36 ( struct V_46 * V_47 ,
struct V_4 * V_5 , int V_48 )
{
int V_49 = 0 ;
F_37 ( V_5 ) ;
if ( ( V_5 -> V_50 != V_5 -> V_51 ) &&
! F_19 ( V_5 ) ) {
V_5 -> V_52 |= V_53 | V_54 |
V_55 | V_56 ;
V_49 = 1 ;
}
F_38 ( V_5 ) ;
if ( V_49 )
F_20 ( V_5 ,
L_11 ) ;
else
F_20 ( V_5 , L_12 ) ;
if ( V_5 -> V_57 -> V_58 == V_59 ) {
F_37 ( V_5 ) ;
if ( ! F_18 ( V_5 ) ) {
F_39 ( V_5 ) ;
F_40 ( V_5 , V_48 ) ;
F_41 ( V_5 ) ;
}
F_38 ( V_5 ) ;
} else {
F_42 ( V_5 , V_48 ) ;
}
}
int F_43 ( struct V_60 * exp , struct V_61 * V_62 ,
enum V_63 type , T_3 V_64 ,
enum V_65 V_48 ,
T_1 * V_32 , void * V_66 , T_2 V_67 ,
const struct V_68 * V_69 , int V_38 )
{
struct V_46 * V_47 = exp -> V_17 -> V_70 ;
int V_71 = * V_32 & V_72 ;
struct V_4 * V_5 ;
struct V_73 * V_74 ;
int V_75 = 1 ;
V_5 = F_44 ( V_69 ) ;
if ( ! V_5 ) {
F_45 ( type == V_59 ) ;
return - V_76 ;
}
F_46 ( F_47 ( V_67 != 0 , V_67 == V_5 -> V_77 ) ,
L_13 , V_67 , V_5 -> V_77 ) ;
if ( V_38 != V_78 ) {
F_45 ( ! V_71 ) ;
F_20 ( V_5 , L_14 ,
V_38 == V_79 ? L_15 : L_16 ) ;
if ( V_38 != V_79 )
goto V_80;
}
V_74 = F_48 ( & V_62 -> V_81 , & V_82 ) ;
if ( ! V_74 ) {
V_38 = - V_83 ;
goto V_80;
}
if ( V_67 > 0 ) {
int V_84 = 0 ;
V_84 = F_49 ( & V_62 -> V_81 , & V_85 ,
V_86 ) ;
if ( V_84 < 0 ) {
F_3 ( V_5 , L_17 , V_84 ) ;
V_38 = V_84 ;
goto V_80;
} else if ( F_50 ( V_84 > V_67 ) ) {
F_3 ( V_5 , L_18 ,
V_67 , V_84 ) ;
V_38 = - V_87 ;
goto V_80;
}
V_67 = V_84 ;
}
if ( V_38 == V_79 ) {
if ( V_67 > 0 && V_66 )
V_38 = F_51 ( V_5 , & V_62 -> V_81 , V_86 ,
V_66 , V_67 ) ;
if ( V_38 == 0 )
V_38 = V_79 ;
goto V_80;
}
V_75 = 0 ;
F_37 ( V_5 ) ;
if ( exp -> V_88 ) {
F_52 ( exp -> V_88 ,
& V_5 -> V_89 ,
& V_74 -> V_90 ,
& V_5 -> V_91 ) ;
} else {
V_5 -> V_89 = V_74 -> V_90 ;
}
* V_32 = F_53 ( V_74 -> V_92 ) ;
V_5 -> V_52 |= F_53 ( V_74 -> V_92 &
V_93 ) ;
F_38 ( V_5 ) ;
F_54 ( V_94 , L_19 ,
V_5 , V_74 -> V_90 . V_95 , * V_32 ) ;
if ( ( * V_32 ) & V_96 ) {
int V_97 = V_74 -> V_98 . V_50 ;
F_45 ( ! V_71 ) ;
if ( V_97 && V_97 != V_5 -> V_50 ) {
F_20 ( V_5 , L_20 ,
V_99 [ V_97 ] ) ;
V_5 -> V_50 = V_97 ;
}
if ( ! F_55 ( & V_74 -> V_98 . V_57 . V_100 ,
& V_5 -> V_57 -> V_100 ) ) {
F_54 ( V_94 , L_21 V_101
L_22 V_101 L_23 ,
F_56 ( & V_74 -> V_98 . V_57 ) ,
F_56 ( V_5 -> V_57 ) ) ;
V_38 = F_57 ( V_47 , V_5 ,
& V_74 -> V_98 . V_57 . V_100 ) ;
if ( V_38 || ! V_5 -> V_57 ) {
V_38 = - V_102 ;
goto V_80;
}
F_20 ( V_5 , L_24 ) ;
}
if ( V_64 )
if ( ! ( type == V_103 &&
! ( F_58 ( exp ) & V_104 ) ) )
F_59 ( exp ,
V_5 -> V_57 -> V_58 ,
& V_74 -> V_98 . V_105 ,
& V_5 -> V_105 ) ;
if ( type != V_106 )
F_20 ( V_5 ,
L_25 ) ;
}
if ( ( * V_32 ) & V_107 ) {
F_37 ( V_5 ) ;
V_5 -> V_52 |= V_56 | V_108 ;
F_38 ( V_5 ) ;
F_20 ( V_5 , L_26 ) ;
}
if ( V_67 > 0 ) {
F_37 ( V_5 ) ;
if ( V_5 -> V_50 != V_5 -> V_51 )
V_38 = F_51 ( V_5 , & V_62 -> V_81 , V_86 ,
V_5 -> V_109 , V_67 ) ;
F_38 ( V_5 ) ;
if ( V_38 < 0 ) {
V_75 = 1 ;
goto V_80;
}
}
if ( ! V_71 ) {
V_38 = F_60 ( V_47 , & V_5 , NULL , V_32 ) ;
if ( V_5 -> V_110 ) {
int V_111 = V_5 -> V_110 ( V_5 , * V_32 , NULL ) ;
if ( ! V_38 )
V_38 = V_111 ;
if ( V_38 )
V_75 = 1 ;
}
}
if ( V_67 > 0 && V_66 ) {
memcpy ( V_66 , V_5 -> V_109 , V_67 ) ;
}
F_20 ( V_5 , L_27 ) ;
V_80:
if ( V_75 == 1 && V_38 )
F_36 ( V_47 , V_5 , V_48 ) ;
F_61 ( V_5 ) ;
F_62 ( V_5 ) ;
return V_38 ;
}
static inline int F_63 ( int V_112 , int V_113 )
{
int V_114 ;
V_114 = F_64 ( int , V_115 , V_116 - 512 ) - V_112 ;
if ( F_65 ( V_114 >= 0 ) )
V_114 /= ( int ) sizeof( struct V_68 ) ;
else
V_114 = 0 ;
V_114 += V_117 - V_113 ;
return V_114 ;
}
static inline int F_66 ( struct V_118 * V_119 ,
enum V_120 V_121 ,
int V_113 )
{
T_4 V_84 = F_67 ( V_119 , V_121 ) ;
return F_63 ( V_84 , V_113 ) ;
}
static inline int F_68 ( struct V_7 * V_8 ,
const struct V_122 * V_123 ,
enum V_120 V_121 , int V_113 )
{
T_4 V_84 = F_69 ( V_8 -> V_124 , V_123 , V_121 ) ;
return F_63 ( V_84 , V_113 ) ;
}
int F_70 ( struct V_60 * exp , struct V_61 * V_62 ,
int V_125 , int V_126 , int V_127 ,
struct V_128 * V_129 , int V_130 )
{
struct V_46 * V_47 = exp -> V_17 -> V_70 ;
struct V_118 * V_119 = & V_62 -> V_81 ;
struct V_131 * V_132 = NULL ;
int V_32 , V_114 , V_133 , V_134 = 0 ;
F_71 ( V_135 ) ;
int V_38 ;
if ( ! V_129 )
V_129 = & V_135 ;
if ( F_72 ( V_47 ) ) {
F_73 ( V_119 , V_136 ) ;
V_114 = F_66 ( V_119 , V_136 , V_127 ) ;
V_32 = F_74 ( V_47 ) ?
V_137 : V_138 ;
V_133 = ! F_74 ( V_47 ) &&
V_126 == V_139 ? 1 : 0 ;
if ( V_114 > V_130 )
V_130 += F_75 ( V_47 , V_129 , V_133 ,
V_114 - V_130 , 0 , V_32 ) ;
if ( V_114 > V_130 )
V_134 = V_130 ;
else
V_134 = V_114 ;
F_76 ( V_119 , & V_140 , V_136 ,
F_77 ( V_134 , V_126 ) ) ;
}
V_38 = F_78 ( V_62 , V_125 , V_126 ) ;
if ( V_38 ) {
F_79 ( V_129 , V_141 , V_130 ) ;
return V_38 ;
}
if ( F_72 ( V_47 ) ) {
if ( V_127 ) {
V_132 = F_80 ( V_119 , & V_140 ) ;
F_45 ( V_132 ) ;
V_132 -> V_142 = V_127 ;
}
F_81 ( V_129 , V_134 , V_62 , 0 ) ;
F_81 ( V_129 , V_130 - V_134 , NULL , 0 ) ;
} else {
F_79 ( V_129 , V_141 , V_130 ) ;
}
return 0 ;
}
int F_82 ( struct V_60 * exp , struct V_61 * V_62 ,
struct V_128 * V_129 , int V_130 )
{
return F_70 ( exp , V_62 , V_143 , V_139 ,
V_144 , V_129 , V_130 ) ;
}
static struct V_61 * F_83 ( struct V_60 * exp ,
int V_67 )
{
struct V_61 * V_62 ;
int V_38 ;
V_62 = F_84 ( F_85 ( exp ) , & V_145 ) ;
if ( ! V_62 )
return F_86 ( - V_102 ) ;
V_38 = F_82 ( exp , V_62 , NULL , 0 ) ;
if ( V_38 ) {
F_87 ( V_62 ) ;
return F_86 ( V_38 ) ;
}
F_76 ( & V_62 -> V_81 , & V_85 , V_86 , V_67 ) ;
F_88 ( V_62 ) ;
return V_62 ;
}
int F_89 ( struct V_60 * exp , struct V_61 * * V_146 ,
struct V_147 * V_148 ,
const struct V_149 * V_150 ,
union V_151 const * V_152 , T_1 * V_32 ,
void * V_66 , T_2 V_67 , enum V_153 V_153 ,
struct V_68 * V_69 , int V_154 )
{
struct V_46 * V_47 ;
struct V_4 * V_5 ;
struct V_131 * V_155 ;
int V_71 = * V_32 & V_72 ;
int V_156 = 1 ;
int V_38 , V_111 ;
struct V_61 * V_62 ;
V_47 = exp -> V_17 -> V_70 ;
if ( V_71 ) {
V_5 = F_90 ( V_69 , 0 ) ;
F_45 ( V_5 ) ;
F_20 ( V_5 , L_28 ) ;
F_45 ( exp == V_5 -> V_11 ) ;
} else {
const struct V_157 V_158 = {
. V_159 = V_148 -> V_160 ,
. V_161 = V_148 -> V_162 ,
. V_163 = V_148 -> V_164
} ;
V_5 = F_91 ( V_47 , V_150 , V_148 -> V_165 ,
V_148 -> V_166 , & V_158 , V_148 -> V_167 ,
V_67 , V_153 ) ;
if ( F_92 ( V_5 ) )
return F_93 ( V_5 ) ;
F_94 ( V_5 , V_148 -> V_166 ) ;
F_95 ( V_5 , V_69 ) ;
if ( V_152 )
V_5 -> V_105 = * V_152 ;
if ( V_148 -> V_165 == V_168 ) {
if ( ! V_152 )
F_96 () ;
V_5 -> V_169 = V_152 -> V_170 ;
}
F_20 ( V_5 , L_29 ,
* V_32 ) ;
}
V_5 -> V_11 = exp ;
V_5 -> V_171 = NULL ;
V_5 -> V_172 = V_148 -> V_162 ;
V_5 -> V_52 |= ( * V_32 & ( V_173 | V_174 ) ) ;
V_5 -> V_15 = F_4 () ;
if ( ! V_146 || ! * V_146 ) {
V_62 = F_83 ( exp , V_67 ) ;
if ( F_92 ( V_62 ) ) {
F_36 ( V_47 , V_5 , V_148 -> V_166 ) ;
F_62 ( V_5 ) ;
return F_93 ( V_62 ) ;
}
V_156 = 0 ;
if ( V_146 )
* V_146 = V_62 ;
} else {
int V_175 ;
V_62 = * V_146 ;
V_175 = F_49 ( & V_62 -> V_81 , & V_140 ,
V_136 ) ;
F_46 ( V_175 >= sizeof( * V_155 ) , L_30 ,
V_176 , V_175 , ( int ) sizeof( * V_155 ) ) ;
}
V_155 = F_80 ( & V_62 -> V_81 , & V_140 ) ;
F_97 ( V_5 , & V_155 -> V_98 ) ;
V_155 -> V_92 = F_98 ( * V_32 ) ;
V_155 -> V_90 [ 0 ] = * V_69 ;
if ( V_154 ) {
F_45 ( V_146 ) ;
return 0 ;
}
F_20 ( V_5 , L_31 ) ;
V_38 = F_99 ( V_62 ) ;
V_111 = F_43 ( exp , V_62 , V_148 -> V_165 , V_152 ? 1 : 0 ,
V_148 -> V_166 , V_32 , V_66 , V_67 ,
V_69 , V_38 ) ;
if ( V_111 == - V_76 )
F_62 ( V_5 ) ;
else
V_38 = V_111 ;
if ( ! V_156 && V_62 ) {
F_100 ( V_62 ) ;
if ( V_146 )
* V_146 = NULL ;
}
return V_38 ;
}
static T_1 F_101 ( struct V_4 * V_5 )
{
T_1 V_38 = V_53 ;
if ( V_5 -> V_11 ) {
bool V_177 ;
F_20 ( V_5 , L_32 ) ;
F_37 ( V_5 ) ;
F_102 ( V_5 ) ;
V_177 = ! ! ( V_5 -> V_52 &
( V_53 | V_178 ) ) ;
F_103 ( V_5 ) ;
V_38 = F_104 ( V_5 ) ? V_108 : V_179 ;
F_38 ( V_5 ) ;
if ( V_177 ) {
F_54 ( V_16 , L_33 ) ;
V_38 = V_53 ;
}
F_105 ( V_5 ) ;
} else {
F_3 ( V_5 , L_34 ) ;
F_96 () ;
}
return V_38 ;
}
static void F_106 ( struct V_61 * V_62 ,
struct V_128 * V_135 , int V_130 )
{
struct V_131 * V_132 ;
struct V_4 * V_5 ;
int F_16 , V_180 = 0 ;
V_132 = F_80 ( & V_62 -> V_81 , & V_140 ) ;
F_45 ( V_132 ) ;
F_16 = F_49 ( & V_62 -> V_81 , & V_140 , V_136 ) -
sizeof( struct V_131 ) ;
F_16 /= sizeof( struct V_68 ) ;
F_16 += V_117 ;
F_45 ( F_16 >= V_132 -> V_142 + V_130 ) ;
F_107 (lock, head, l_bl_ast) {
if ( ! V_130 -- )
break;
F_45 ( V_5 -> V_11 ) ;
F_20 ( V_5 , L_35 ) ;
V_132 -> V_90 [ V_132 -> V_142 ++ ] = V_5 -> V_89 ;
V_180 ++ ;
}
F_54 ( V_16 , L_36 , V_180 ) ;
}
static int F_108 ( struct V_60 * exp ,
struct V_128 * V_129 ,
int V_130 , enum V_181 V_32 )
{
struct V_61 * V_62 = NULL ;
struct V_7 * V_8 ;
int free , V_182 = 0 ;
int V_38 = 0 ;
F_45 ( exp ) ;
F_45 ( V_130 > 0 ) ;
F_109 ( V_183 , V_184 ) ;
if ( F_110 ( V_185 ) )
return V_130 ;
free = F_68 ( F_85 ( exp ) ,
& V_186 , V_136 , 0 ) ;
if ( V_130 > free )
V_130 = free ;
while ( 1 ) {
V_8 = F_85 ( exp ) ;
if ( ! V_8 || V_8 -> V_187 ) {
F_54 ( V_16 ,
L_37 , V_8 ) ;
return V_130 ;
}
V_62 = F_84 ( V_8 , & V_186 ) ;
if ( ! V_62 ) {
V_38 = - V_102 ;
goto V_188;
}
F_73 ( & V_62 -> V_81 , V_136 ) ;
F_76 ( & V_62 -> V_81 , & V_140 , V_136 ,
F_77 ( V_130 , V_189 ) ) ;
V_38 = F_78 ( V_62 , V_143 , V_189 ) ;
if ( V_38 ) {
F_87 ( V_62 ) ;
goto V_188;
}
V_62 -> V_190 = V_191 ;
V_62 -> V_192 = V_193 ;
F_111 ( V_62 ) ;
F_106 ( V_62 , V_129 , V_130 ) ;
F_88 ( V_62 ) ;
if ( V_32 & V_194 ) {
F_112 ( V_62 ) ;
V_182 = V_130 ;
goto V_188;
}
V_38 = F_99 ( V_62 ) ;
if ( V_38 == V_195 ) {
F_54 ( V_16 , L_38 ,
F_113 ( V_62 -> V_196 ->
V_22 -> V_197 . V_198 ) ) ;
V_38 = 0 ;
} else if ( V_38 == - V_199 &&
V_62 -> V_200 == V_8 -> V_201 ) {
F_100 ( V_62 ) ;
continue;
} else if ( V_38 != V_78 ) {
F_114 ( V_38 == - V_202 ? V_16 : V_203 ,
L_39 ,
V_38 ) ;
break;
}
V_182 = V_130 ;
break;
}
F_100 ( V_62 ) ;
V_188:
return V_182 ? V_182 : V_38 ;
}
static inline struct V_204 * F_115 ( struct V_7 * V_8 )
{
return & V_8 -> V_205 -> V_70 -> V_206 ;
}
int F_116 ( struct V_61 * V_62 )
{
struct V_9 * V_10 ;
T_1 V_207 ;
T_2 V_208 ;
if ( F_50 ( ! V_62 -> V_196 || ! V_62 -> V_196 -> V_205 ||
! F_117 ( V_62 -> V_196 ) ) ) {
return 0 ;
}
if ( F_118 ( V_62 -> V_209 ) == 0 ||
F_119 ( V_62 -> V_209 ) == 0 ) {
F_120 ( V_210 , V_62 ,
L_40 ,
F_118 ( V_62 -> V_209 ) ,
F_119 ( V_62 -> V_209 ) ) ;
return 0 ;
}
V_208 = F_119 ( V_62 -> V_209 ) ;
V_207 = F_118 ( V_62 -> V_209 ) ;
V_10 = V_62 -> V_196 -> V_205 ;
F_121 ( & V_10 -> V_211 ) ;
V_10 -> V_212 = V_207 ;
V_10 -> V_213 = V_208 ;
F_122 ( & V_10 -> V_211 ) ;
return 0 ;
}
int F_123 ( const struct V_68 * V_69 ,
enum V_181 V_214 )
{
struct V_60 * exp ;
int V_114 , V_32 , V_130 = 1 ;
T_1 V_38 = 0 ;
struct V_46 * V_47 ;
struct V_4 * V_5 ;
F_71 ( V_129 ) ;
V_5 = F_90 ( V_69 , V_179 ) ;
if ( ! V_5 ) {
F_124 ( L_41 ) ;
return 0 ;
}
V_38 = F_101 ( V_5 ) ;
if ( V_38 == V_53 || V_214 & V_215 ) {
F_62 ( V_5 ) ;
return 0 ;
}
F_45 ( F_125 ( & V_5 -> V_141 ) ) ;
F_126 ( & V_5 -> V_141 , & V_129 ) ;
exp = V_5 -> V_11 ;
if ( F_127 ( exp ) ) {
V_114 = F_68 ( F_85 ( exp ) ,
& V_186 ,
V_136 , 0 ) ;
F_45 ( V_114 > 0 ) ;
V_47 = F_9 ( V_5 ) ;
V_32 = F_74 ( V_47 ) ?
V_216 : V_138 ;
V_130 += F_75 ( V_47 , & V_129 , 0 , V_114 - 1 ,
V_217 , V_32 ) ;
}
F_81 ( & V_129 , V_130 , NULL , V_214 ) ;
return 0 ;
}
int F_128 ( struct V_128 * V_129 , int V_130 ,
enum V_181 V_32 )
{
F_71 ( V_135 ) ;
struct V_4 * V_5 , * V_218 ;
int V_219 = 0 , V_220 = 0 ;
T_1 V_38 ;
V_219 = V_130 ;
F_129 (lock, next, cancels, l_bl_ast) {
if ( V_219 -- == 0 )
break;
if ( V_32 & V_215 ) {
V_38 = V_53 ;
F_105 ( V_5 ) ;
} else {
V_38 = F_101 ( V_5 ) ;
}
if ( ! ( V_32 & V_217 ) && ( V_38 == V_108 ) ) {
F_20 ( V_5 , L_42 ) ;
F_130 ( & V_5 -> V_141 ) ;
F_126 ( & V_5 -> V_141 , & V_135 ) ;
V_220 ++ ;
continue;
}
if ( V_38 == V_53 ) {
F_130 ( & V_5 -> V_141 ) ;
F_62 ( V_5 ) ;
V_130 -- ;
}
}
if ( V_220 > 0 ) {
V_130 -= V_220 ;
F_81 ( & V_135 , V_220 , NULL , 0 ) ;
}
return V_130 ;
}
static enum V_221
F_131 ( struct V_46 * V_47 , struct V_4 * V_5 ,
int V_222 , int V_223 , int V_130 )
{
enum V_221 V_30 = V_224 ;
switch ( V_5 -> V_57 -> V_58 ) {
case V_168 :
case V_103 :
if ( V_47 -> V_225 && V_47 -> V_225 ( V_5 ) != 0 )
break;
default:
V_30 = V_226 ;
F_37 ( V_5 ) ;
F_132 ( V_5 ) ;
F_38 ( V_5 ) ;
break;
}
return V_30 ;
}
static enum V_221 F_133 ( struct V_46 * V_47 ,
struct V_4 * V_5 ,
int V_222 , int V_223 ,
int V_130 )
{
unsigned long V_227 = F_6 () ;
struct V_204 * V_228 = & V_47 -> V_206 ;
T_1 V_229 , V_230 , V_231 ;
unsigned long V_232 ;
if ( V_130 && V_223 >= V_130 )
return V_233 ;
if ( F_5 ( F_6 () ,
F_134 ( V_5 -> V_234 , V_47 -> V_235 ) ) )
return V_224 ;
V_229 = F_135 ( V_228 ) ;
V_230 = F_136 ( V_228 ) ;
V_232 = F_137 ( F_138 ( V_227 , V_5 -> V_234 ) ) ;
V_231 = V_230 * V_232 * V_222 ;
F_139 ( V_228 , V_231 ) ;
if ( V_229 == 0 || V_231 < V_229 )
return V_233 ;
return V_224 ;
}
static enum V_221 F_140 ( struct V_46 * V_47 ,
struct V_4 * V_5 ,
int V_222 , int V_223 ,
int V_130 )
{
return ( V_223 >= V_130 ) ?
V_233 : V_224 ;
}
static enum V_221 F_141 ( struct V_46 * V_47 ,
struct V_4 * V_5 ,
int V_222 , int V_223 ,
int V_130 )
{
if ( ( V_223 >= V_130 ) &&
F_142 ( F_6 () ,
F_134 ( V_5 -> V_234 , V_47 -> V_235 ) ) )
return V_233 ;
return V_224 ;
}
static enum V_221
F_143 ( struct V_46 * V_47 ,
struct V_4 * V_5 ,
int V_222 , int V_223 ,
int V_130 )
{
enum V_221 V_30 ;
V_30 = F_133 ( V_47 , V_5 , V_222 , V_223 , V_130 ) ;
if ( V_30 == V_233 )
return V_30 ;
return F_131 ( V_47 , V_5 , V_222 , V_223 , V_130 ) ;
}
static enum V_221
F_144 ( struct V_46 * V_47 , struct V_4 * V_5 ,
int V_222 , int V_223 , int V_130 )
{
return ( V_223 >= V_130 ) ?
V_233 : V_224 ;
}
static T_5
F_145 ( struct V_46 * V_47 , int V_32 )
{
if ( V_32 & V_236 )
return F_131 ;
if ( F_74 ( V_47 ) ) {
if ( V_32 & V_237 )
return F_140 ;
else if ( V_32 & V_216 )
return F_133 ;
else if ( V_32 & V_238 )
return F_140 ;
else if ( V_32 & V_137 )
return F_143 ;
} else {
if ( V_32 & V_138 )
return F_141 ;
}
return F_144 ;
}
static int F_146 ( struct V_46 * V_47 ,
struct V_128 * V_129 , int V_130 , int F_16 ,
int V_32 )
{
T_5 V_239 ;
struct V_4 * V_5 , * V_218 ;
int V_223 = 0 , V_222 , V_240 ;
int V_241 = V_32 & ( V_236 | V_137 ) ;
F_30 ( & V_47 -> V_242 ) ;
V_222 = V_47 -> V_243 ;
V_240 = V_222 ;
if ( ! F_74 ( V_47 ) )
V_130 += V_222 - V_47 -> V_244 ;
V_239 = F_145 ( V_47 , V_32 ) ;
F_45 ( V_239 ) ;
while ( ! F_125 ( & V_47 -> V_245 ) ) {
enum V_221 V_30 ;
T_6 V_246 = 0 ;
if ( V_240 -- <= 0 )
break;
if ( F_16 && V_223 >= F_16 )
break;
F_129 (lock, next, &ns->ns_unused_list,
l_lru) {
F_45 ( ! F_104 ( V_5 ) ) ;
if ( V_241 && F_147 ( V_5 ) )
continue;
V_246 = V_5 -> V_234 ;
if ( V_246 == F_6 () )
continue;
if ( ! F_148 ( V_5 ) )
break;
F_149 ( V_5 ) ;
}
if ( & V_5 -> V_247 == & V_47 -> V_245 )
break;
F_150 ( V_5 ) ;
F_31 ( & V_47 -> V_242 ) ;
F_151 ( & V_5 -> V_248 , V_249 , V_250 ) ;
V_30 = V_239 ( V_47 , V_5 , V_222 , V_223 , V_130 ) ;
if ( V_30 == V_233 ) {
F_152 ( & V_5 -> V_248 ,
V_249 , V_250 ) ;
F_62 ( V_5 ) ;
F_30 ( & V_47 -> V_242 ) ;
break;
}
if ( V_30 == V_226 ) {
F_152 ( & V_5 -> V_248 ,
V_249 , V_250 ) ;
F_62 ( V_5 ) ;
F_30 ( & V_47 -> V_242 ) ;
continue;
}
F_37 ( V_5 ) ;
if ( F_148 ( V_5 ) ||
( F_153 ( V_5 , V_246 ) == 0 ) ) {
F_38 ( V_5 ) ;
F_152 ( & V_5 -> V_248 ,
V_249 , V_250 ) ;
F_62 ( V_5 ) ;
F_30 ( & V_47 -> V_242 ) ;
continue;
}
F_45 ( ! V_5 -> V_251 && ! V_5 -> V_252 ) ;
F_154 ( V_5 ) ;
V_5 -> V_52 |= V_56 | V_179 ;
F_45 ( F_125 ( & V_5 -> V_141 ) ) ;
F_126 ( & V_5 -> V_141 , V_129 ) ;
F_38 ( V_5 ) ;
F_152 ( & V_5 -> V_248 , V_249 , V_250 ) ;
F_30 ( & V_47 -> V_242 ) ;
V_223 ++ ;
V_222 -- ;
}
F_31 ( & V_47 -> V_242 ) ;
return V_223 ;
}
int F_75 ( struct V_46 * V_47 ,
struct V_128 * V_129 , int V_130 , int F_16 ,
enum V_181 V_214 , int V_32 )
{
int V_223 ;
V_223 = F_146 ( V_47 , V_129 , V_130 , F_16 , V_32 ) ;
if ( V_223 <= 0 )
return V_223 ;
return F_128 ( V_129 , V_223 , V_214 ) ;
}
int F_155 ( struct V_46 * V_47 , int V_253 ,
enum V_181 V_214 ,
int V_32 )
{
F_71 ( V_129 ) ;
int V_130 , V_38 ;
V_130 = F_146 ( V_47 , & V_129 , V_253 , 0 , V_32 ) ;
V_38 = F_156 ( V_47 , NULL , & V_129 , V_130 , V_214 ) ;
if ( V_38 == 0 )
return V_130 ;
return 0 ;
}
int F_157 ( struct V_254 * V_255 ,
struct V_128 * V_129 ,
union V_151 * V_152 ,
enum V_65 V_48 , T_1 V_92 ,
enum V_181 V_214 ,
void * V_256 )
{
struct V_4 * V_5 ;
int V_130 = 0 ;
F_158 ( V_255 ) ;
F_107 (lock, &res->lr_granted, l_res_link) {
if ( V_256 && V_5 -> V_257 != V_256 ) {
F_3 ( V_5 , L_43 ,
V_5 -> V_257 , V_256 ) ;
continue;
}
if ( V_5 -> V_251 || V_5 -> V_252 )
continue;
if ( F_104 ( V_5 ) || F_148 ( V_5 ) )
continue;
if ( F_159 ( V_5 -> V_51 , V_48 ) )
continue;
if ( V_152 && ( V_5 -> V_57 -> V_58 == V_103 ) &&
! ( V_5 -> V_105 . V_258 . V_259 &
V_152 -> V_258 . V_259 ) )
continue;
V_5 -> V_52 |= V_56 | V_179 |
V_92 ;
F_45 ( F_125 ( & V_5 -> V_141 ) ) ;
F_126 ( & V_5 -> V_141 , V_129 ) ;
F_150 ( V_5 ) ;
V_130 ++ ;
}
F_160 ( V_255 ) ;
return F_128 ( V_129 , V_130 , V_214 ) ;
}
int F_81 ( struct V_128 * V_129 , int V_130 ,
struct V_61 * V_62 ,
enum V_181 V_32 )
{
struct V_4 * V_5 ;
int V_255 = 0 ;
if ( F_125 ( V_129 ) || V_130 == 0 )
return 0 ;
while ( V_130 > 0 ) {
F_45 ( ! F_125 ( V_129 ) ) ;
V_5 = F_161 ( V_129 -> V_218 , struct V_4 , V_141 ) ;
F_45 ( V_5 -> V_11 ) ;
if ( F_127 ( V_5 -> V_11 ) ) {
V_255 = V_130 ;
if ( V_62 )
F_106 ( V_62 , V_129 , V_130 ) ;
else
V_255 = F_108 ( V_5 -> V_11 ,
V_129 , V_130 ,
V_32 ) ;
} else {
V_255 = F_108 ( V_5 -> V_11 ,
V_129 , 1 , V_32 ) ;
}
if ( V_255 < 0 ) {
F_114 ( V_255 == - V_202 ? V_16 : V_203 ,
L_44 , V_255 ) ;
V_255 = V_130 ;
}
V_130 -= V_255 ;
F_79 ( V_129 , V_141 , V_255 ) ;
}
F_45 ( V_130 == 0 ) ;
return 0 ;
}
int F_162 ( struct V_46 * V_47 ,
const struct V_149 * V_150 ,
union V_151 * V_152 ,
enum V_65 V_48 ,
enum V_181 V_32 ,
void * V_256 )
{
struct V_254 * V_255 ;
F_71 ( V_129 ) ;
int V_130 ;
int V_38 ;
V_255 = F_163 ( V_47 , NULL , V_150 , 0 , 0 ) ;
if ( F_92 ( V_255 ) ) {
F_54 ( V_94 , L_45 , V_150 -> V_260 [ 0 ] ) ;
return 0 ;
}
F_164 ( V_255 ) ;
V_130 = F_157 ( V_255 , & V_129 , V_152 , V_48 ,
0 , V_32 | V_217 , V_256 ) ;
V_38 = F_81 ( & V_129 , V_130 , NULL , V_32 ) ;
if ( V_38 != V_78 )
F_165 ( L_46 V_101 L_47 ,
F_56 ( V_255 ) , V_38 ) ;
F_166 ( V_255 ) ;
F_167 ( V_255 ) ;
return 0 ;
}
static int F_168 ( struct V_261 * V_262 ,
struct V_263 * V_264 ,
struct V_265 * V_266 , void * V_267 )
{
struct V_254 * V_255 = F_169 ( V_262 , V_266 ) ;
struct V_268 * V_269 = V_267 ;
F_162 ( F_170 ( V_255 ) , & V_255 -> V_100 ,
NULL , V_270 ,
V_269 -> V_271 , V_269 -> V_272 ) ;
return 0 ;
}
int F_171 ( struct V_46 * V_47 ,
const struct V_149 * V_150 ,
enum V_181 V_32 , void * V_256 )
{
struct V_268 V_267 = {
. V_271 = V_32 ,
. V_272 = V_256 ,
} ;
if ( ! V_47 )
return V_78 ;
if ( V_150 ) {
return F_162 ( V_47 , V_150 , NULL ,
V_270 , V_32 ,
V_256 ) ;
} else {
F_172 ( V_47 -> V_273 ,
F_168 , & V_267 , 0 ) ;
return V_78 ;
}
}
static int F_173 ( struct V_254 * V_255 ,
T_7 V_274 , void * V_275 )
{
struct V_128 * V_276 , * V_218 ;
struct V_4 * V_5 ;
int V_38 = V_277 ;
if ( ! V_255 )
return V_277 ;
F_158 ( V_255 ) ;
F_174 (tmp, next, &res->lr_granted) {
V_5 = F_161 ( V_276 , struct V_4 , V_278 ) ;
if ( V_274 ( V_5 , V_275 ) == V_279 ) {
V_38 = V_279 ;
goto V_188;
}
}
F_174 (tmp, next, &res->lr_waiting) {
V_5 = F_161 ( V_276 , struct V_4 , V_278 ) ;
if ( V_274 ( V_5 , V_275 ) == V_279 ) {
V_38 = V_279 ;
goto V_188;
}
}
V_188:
F_160 ( V_255 ) ;
return V_38 ;
}
static int F_175 ( struct V_4 * V_5 , void * V_275 )
{
struct V_280 * V_281 = V_275 ;
return V_281 -> V_274 ( V_5 , V_281 -> V_275 ) ;
}
static int F_176 ( struct V_261 * V_262 , struct V_263 * V_264 ,
struct V_265 * V_266 , void * V_267 )
{
struct V_254 * V_255 = F_169 ( V_262 , V_266 ) ;
return F_173 ( V_255 , F_175 , V_267 ) ==
V_279 ;
}
static void F_177 ( struct V_46 * V_47 ,
T_7 V_274 , void * V_275 )
{
struct V_280 V_281 = {
. V_274 = V_274 ,
. V_275 = V_275 ,
} ;
F_172 ( V_47 -> V_273 ,
F_176 , & V_281 , 0 ) ;
}
int F_178 ( struct V_46 * V_47 ,
const struct V_149 * V_150 ,
T_7 V_274 , void * V_1 )
{
struct V_254 * V_255 ;
int V_38 ;
F_46 ( V_47 , L_48 ) ;
V_255 = F_163 ( V_47 , NULL , V_150 , 0 , 0 ) ;
if ( F_92 ( V_255 ) )
return 0 ;
F_164 ( V_255 ) ;
V_38 = F_173 ( V_255 , V_274 , V_1 ) ;
F_166 ( V_255 ) ;
F_167 ( V_255 ) ;
return V_38 ;
}
static int F_179 ( struct V_4 * V_5 , void * V_275 )
{
struct V_128 * V_282 = V_275 ;
F_46 ( F_125 ( & V_5 -> V_283 ) ,
L_49 ,
V_5 , & V_5 -> V_283 . V_218 ,
& V_5 -> V_283 . V_284 ) ;
if ( ! ( V_5 -> V_52 & ( V_54 | V_285 ) ) ) {
F_126 ( & V_5 -> V_283 , V_282 ) ;
F_150 ( V_5 ) ;
}
return V_277 ;
}
static int F_180 ( const struct V_286 * V_287 ,
struct V_61 * V_62 ,
struct V_288 * V_289 , int V_38 )
{
struct V_4 * V_5 ;
struct V_73 * V_74 ;
struct V_60 * exp ;
F_181 ( & V_62 -> V_196 -> V_290 ) ;
if ( V_38 != V_78 )
goto V_188;
V_74 = F_48 ( & V_62 -> V_81 , & V_82 ) ;
if ( ! V_74 ) {
V_38 = - V_83 ;
goto V_188;
}
V_5 = F_44 ( & V_289 -> V_90 ) ;
if ( ! V_5 ) {
F_165 ( L_50 ,
V_289 -> V_90 . V_95 , V_74 -> V_90 . V_95 ,
V_62 -> V_291 -> V_292 . V_24 ,
F_182 ( V_62 -> V_293 ) ) ;
V_38 = - V_294 ;
goto V_188;
}
exp = V_62 -> V_291 ;
if ( exp && exp -> V_88 ) {
F_52 ( exp -> V_88 ,
& V_5 -> V_89 ,
& V_74 -> V_90 ,
& V_5 -> V_91 ) ;
} else {
V_5 -> V_89 = V_74 -> V_90 ;
}
F_20 ( V_5 , L_51 ) ;
F_183 ( V_62 -> V_196 ) ;
F_61 ( V_5 ) ;
V_188:
if ( V_38 != V_78 )
F_184 ( V_62 -> V_196 ) ;
return V_38 ;
}
static int F_185 ( struct V_7 * V_8 , struct V_4 * V_5 )
{
struct V_61 * V_62 ;
struct V_288 * V_289 ;
struct V_131 * V_155 ;
int V_32 ;
if ( F_186 ( V_5 ) ) {
F_20 ( V_5 , L_52 ) ;
return 0 ;
}
if ( F_187 ( V_5 ) ) {
F_20 ( V_5 , L_53 ) ;
F_105 ( V_5 ) ;
return 0 ;
}
if ( V_5 -> V_51 == V_5 -> V_50 )
V_32 = V_72 | V_295 ;
else if ( V_5 -> V_51 )
V_32 = V_72 | V_296 ;
else if ( ! F_125 ( & V_5 -> V_278 ) )
V_32 = V_72 | V_297 ;
else
V_32 = V_72 ;
V_62 = F_188 ( V_8 , & V_145 ,
V_143 , V_139 ) ;
if ( ! V_62 )
return - V_102 ;
V_62 -> V_298 = V_299 ;
V_155 = F_80 ( & V_62 -> V_81 , & V_140 ) ;
F_97 ( V_5 , & V_155 -> V_98 ) ;
V_155 -> V_92 = F_98 ( V_32 ) ;
F_95 ( V_5 , & V_155 -> V_90 [ 0 ] ) ;
if ( V_5 -> V_77 > 0 )
F_189 ( & V_62 -> V_81 , & V_300 ) ;
F_76 ( & V_62 -> V_81 , & V_85 , V_86 ,
V_5 -> V_77 ) ;
F_88 ( V_62 ) ;
F_190 ( V_62 -> V_301 , V_302 ) ;
F_20 ( V_5 , L_54 ) ;
F_191 ( & V_62 -> V_196 -> V_290 ) ;
F_192 ( sizeof( * V_289 ) > sizeof( V_62 -> V_303 ) ) ;
V_289 = F_193 ( V_62 ) ;
V_289 -> V_90 = V_155 -> V_90 [ 0 ] ;
V_62 -> V_304 = ( V_305 ) F_180 ;
F_112 ( V_62 ) ;
return 0 ;
}
static void F_194 ( struct V_46 * V_47 )
{
int V_306 ;
F_71 ( V_129 ) ;
F_54 ( V_16 , L_55 ,
F_195 ( V_47 ) , V_47 -> V_243 ) ;
V_306 = F_75 ( V_47 , & V_129 , V_47 -> V_243 , 0 ,
V_215 , V_236 ) ;
F_54 ( V_16 , L_56 ,
V_306 , F_195 ( V_47 ) ) ;
}
int F_196 ( struct V_7 * V_8 )
{
struct V_46 * V_47 = V_8 -> V_205 -> V_70 ;
F_71 ( V_282 ) ;
struct V_4 * V_5 , * V_218 ;
int V_38 = 0 ;
F_45 ( F_197 ( & V_8 -> V_290 ) == 0 ) ;
if ( V_8 -> V_307 )
return 0 ;
F_191 ( & V_8 -> V_290 ) ;
if ( V_308 )
F_194 ( V_47 ) ;
F_177 ( V_47 , F_179 , & V_282 ) ;
F_129 (lock, next, &list, l_pending_chain) {
F_130 ( & V_5 -> V_283 ) ;
if ( V_38 ) {
F_62 ( V_5 ) ;
continue;
}
V_38 = F_185 ( V_8 , V_5 ) ;
F_62 ( V_5 ) ;
}
F_181 ( & V_8 -> V_290 ) ;
return V_38 ;
}
