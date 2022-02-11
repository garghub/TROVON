static void F_1 ( void * V_1 )
{
}
static int F_2 ( int V_2 , int type )
{
int V_3 = V_4 ;
if ( type == V_5 )
V_3 -= V_6 ;
if ( V_2 > V_3 )
V_3 = ( V_2 - V_3 ) * sizeof( struct V_7 ) ;
else
V_3 = 0 ;
return sizeof( struct V_8 ) + V_3 ;
}
static int F_3 ( void * V_1 )
{
struct V_9 * V_10 = V_1 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
if ( ! V_12 -> V_18 ) {
static unsigned long V_19 , V_20 ;
F_4 ( V_12 , L_1 ,
( V_21 ) V_12 -> V_22 ,
( V_21 ) ( F_5 () -
V_12 -> V_22 ) ) ;
if ( F_6 ( F_7 () , V_19 ) ) {
V_20 = V_19 ;
V_19 = F_8 ( 300 ) ;
F_9 ( V_23 ,
F_10 ( V_12 ) ) ;
if ( V_20 == 0 )
F_11 () ;
}
return 0 ;
}
V_17 = V_12 -> V_18 -> V_24 ;
V_15 = V_17 -> V_25 . V_26 . V_27 ;
F_12 ( V_15 , V_10 -> V_28 ) ;
F_4 ( V_12 , L_2 ,
( V_21 ) V_12 -> V_22 ,
( V_21 ) ( F_5 () - V_12 -> V_22 ) ,
F_13 ( V_17 ) , V_15 -> V_29 -> V_30 . V_31 ) ;
return 0 ;
}
static unsigned int F_14 ( struct V_11 * V_12 )
{
unsigned int V_32 ;
if ( V_33 )
return V_34 ;
V_32 = F_15 ( F_16 ( V_12 ) ) ;
return F_17 ( 3 * V_32 , V_35 ) ;
}
static int F_18 ( struct V_11 * V_12 , void * V_1 )
{
long V_36 ;
int V_37 = 0 ;
if ( F_19 ( V_12 ) || F_20 ( V_12 ) ) {
F_21 ( V_12 , L_3 ) ;
V_37 = - V_38 ;
} else if ( ! V_1 ) {
F_21 ( V_12 , L_4 ) ;
} else {
V_36 = F_5 () - V_12 -> V_22 ;
F_21 ( V_12 , L_5 ,
V_36 ) ;
F_22 ( F_16 ( V_12 ) , V_36 ) ;
}
return V_37 ;
}
int F_23 ( struct V_11 * V_12 , T_1 V_39 , void * V_1 )
{
if ( V_39 == V_40 ) {
F_21 ( V_12 , L_6 ) ;
return 0 ;
}
if ( ! ( V_39 & V_41 ) ) {
F_24 ( & V_12 -> V_42 ) ;
return F_18 ( V_12 , V_1 ) ;
}
F_21 ( V_12 , L_7 ) ;
return 0 ;
}
int F_25 ( struct V_11 * V_12 , T_1 V_39 , void * V_1 )
{
struct V_9 V_10 ;
struct V_16 * V_17 ;
struct V_14 * V_15 = NULL ;
struct V_43 V_44 ;
T_2 V_32 ;
int V_45 = 0 ;
if ( V_39 == V_40 ) {
F_21 ( V_12 , L_6 ) ;
goto V_46;
}
if ( ! ( V_39 & V_41 ) ) {
F_24 ( & V_12 -> V_42 ) ;
return 0 ;
}
F_21 ( V_12 , L_8 ) ;
V_46:
V_17 = F_26 ( V_12 -> V_18 ) ;
if ( V_17 )
V_15 = V_17 -> V_25 . V_26 . V_27 ;
V_32 = F_14 ( V_12 ) ;
V_10 . V_13 = V_12 ;
V_12 -> V_22 = F_5 () ;
if ( F_27 ( V_12 ) ) {
F_21 ( V_12 , L_9 ) ;
V_44 = F_28 ( F_1 , & V_10 ) ;
} else {
V_44 = F_29 ( F_30 ( V_32 ) ,
F_3 ,
F_1 , & V_10 ) ;
}
if ( V_15 ) {
F_31 ( & V_15 -> V_47 ) ;
V_10 . V_28 = V_15 -> V_48 ;
F_32 ( & V_15 -> V_47 ) ;
}
if ( F_33 ( V_49 ,
V_50 | V_51 ) ) {
F_34 ( V_12 ) ;
V_45 = - V_52 ;
} else {
V_45 = F_35 ( V_12 -> V_42 ,
F_36 ( V_12 ) , & V_44 ) ;
}
if ( V_45 ) {
F_21 ( V_12 , L_10 ,
V_45 ) ;
return V_45 ;
}
return F_18 ( V_12 , V_1 ) ;
}
static void F_37 ( struct V_53 * V_54 ,
struct V_11 * V_12 , int V_55 )
{
int V_56 = 0 ;
F_38 ( V_12 ) ;
if ( ( V_12 -> V_57 != V_12 -> V_58 ) &&
! F_20 ( V_12 ) ) {
V_12 -> V_59 |= V_60 | V_61 |
V_62 | V_63 ;
V_56 = 1 ;
}
F_39 ( V_12 ) ;
if ( V_56 )
F_21 ( V_12 ,
L_11 ) ;
else
F_21 ( V_12 , L_12 ) ;
if ( V_12 -> V_64 -> V_65 == V_66 ) {
F_38 ( V_12 ) ;
if ( ! F_19 ( V_12 ) ) {
F_40 ( V_12 ) ;
F_41 ( V_12 , V_55 ) ;
F_42 ( V_12 ) ;
}
F_39 ( V_12 ) ;
} else {
F_43 ( V_12 , V_55 ) ;
}
}
int F_44 ( struct V_67 * exp , struct V_68 * V_69 ,
enum V_70 type , T_3 V_71 ,
enum V_72 V_55 ,
T_1 * V_39 , void * V_73 , T_2 V_74 ,
const struct V_7 * V_75 , int V_45 )
{
struct V_53 * V_54 = exp -> V_24 -> V_76 ;
int V_77 = * V_39 & V_78 ;
struct V_11 * V_12 ;
struct V_79 * V_80 ;
int V_81 = 1 ;
V_12 = F_45 ( V_75 ) ;
if ( ! V_12 ) {
F_46 ( type == V_66 ) ;
return - V_82 ;
}
F_47 ( F_48 ( V_74 != 0 , V_74 == V_12 -> V_83 ) ,
L_13 , V_74 , V_12 -> V_83 ) ;
if ( V_45 != V_84 ) {
F_46 ( ! V_77 ) ;
F_21 ( V_12 , L_14 ,
V_45 == V_85 ? L_15 : L_16 ) ;
if ( V_45 != V_85 )
goto V_86;
}
V_80 = F_49 ( & V_69 -> V_87 , & V_88 ) ;
if ( ! V_80 ) {
V_45 = - V_89 ;
goto V_86;
}
if ( V_74 > 0 ) {
int V_90 = 0 ;
V_90 = F_50 ( & V_69 -> V_87 , & V_91 ,
V_92 ) ;
if ( V_90 < 0 ) {
F_4 ( V_12 , L_17 , V_90 ) ;
V_45 = V_90 ;
goto V_86;
} else if ( F_51 ( V_90 > V_74 ) ) {
F_4 ( V_12 , L_18 ,
V_74 , V_90 ) ;
V_45 = - V_93 ;
goto V_86;
}
V_74 = V_90 ;
}
if ( V_45 == V_85 ) {
if ( V_74 > 0 && V_73 )
V_45 = F_52 ( V_12 , & V_69 -> V_87 , V_92 ,
V_73 , V_74 ) ;
if ( V_45 == 0 )
V_45 = V_85 ;
goto V_86;
}
V_81 = 0 ;
F_38 ( V_12 ) ;
if ( exp -> V_94 ) {
F_53 ( exp -> V_94 ,
& V_12 -> V_95 ,
& V_80 -> V_96 ,
& V_12 -> V_97 ) ;
} else {
V_12 -> V_95 = V_80 -> V_96 ;
}
* V_39 = F_54 ( V_80 -> V_98 ) ;
V_12 -> V_59 |= F_54 ( V_80 -> V_98 &
V_99 ) ;
F_39 ( V_12 ) ;
F_55 ( V_100 , L_19 ,
V_12 , V_80 -> V_96 . V_101 , * V_39 ) ;
if ( ( * V_39 ) & V_102 ) {
int V_103 = V_80 -> V_104 . V_57 ;
F_46 ( ! V_77 ) ;
if ( V_103 && V_103 != V_12 -> V_57 ) {
F_21 ( V_12 , L_20 ,
V_105 [ V_103 ] ) ;
V_12 -> V_57 = V_103 ;
}
if ( ! F_56 ( & V_80 -> V_104 . V_64 . V_106 ,
& V_12 -> V_64 -> V_106 ) ) {
F_55 ( V_100 , L_21 V_107
L_22 V_107 L_23 ,
F_57 ( & V_80 -> V_104 . V_64 ) ,
F_57 ( V_12 -> V_64 ) ) ;
V_45 = F_58 ( V_54 , V_12 ,
& V_80 -> V_104 . V_64 . V_106 ) ;
if ( V_45 || ! V_12 -> V_64 ) {
V_45 = - V_108 ;
goto V_86;
}
F_21 ( V_12 , L_24 ) ;
}
if ( V_71 )
if ( ! ( type == V_109 &&
! ( F_59 ( exp ) & V_110 ) ) )
F_60 ( exp ,
V_12 -> V_64 -> V_65 ,
& V_80 -> V_104 . V_111 ,
& V_12 -> V_111 ) ;
if ( type != V_112 )
F_21 ( V_12 ,
L_25 ) ;
}
if ( ( * V_39 ) & V_113 ) {
F_38 ( V_12 ) ;
V_12 -> V_59 |= V_63 | V_114 ;
F_39 ( V_12 ) ;
F_21 ( V_12 , L_26 ) ;
}
if ( V_74 > 0 ) {
F_38 ( V_12 ) ;
if ( V_12 -> V_57 != V_12 -> V_58 )
V_45 = F_52 ( V_12 , & V_69 -> V_87 , V_92 ,
V_12 -> V_115 , V_74 ) ;
F_39 ( V_12 ) ;
if ( V_45 < 0 ) {
V_81 = 1 ;
goto V_86;
}
}
if ( ! V_77 ) {
V_45 = F_61 ( V_54 , & V_12 , NULL , V_39 ) ;
if ( V_12 -> V_116 ) {
int V_117 = V_12 -> V_116 ( V_12 , * V_39 , NULL ) ;
if ( ! V_45 )
V_45 = V_117 ;
if ( V_45 )
V_81 = 1 ;
}
}
if ( V_74 > 0 && V_73 ) {
memcpy ( V_73 , V_12 -> V_115 , V_74 ) ;
}
F_21 ( V_12 , L_27 ) ;
V_86:
if ( V_81 == 1 && V_45 )
F_37 ( V_54 , V_12 , V_55 ) ;
F_62 ( V_12 ) ;
F_63 ( V_12 ) ;
return V_45 ;
}
static inline int F_64 ( int V_118 , int V_119 )
{
int V_3 ;
V_3 = F_65 ( int , V_120 , V_121 - 512 ) - V_118 ;
if ( F_66 ( V_3 >= 0 ) )
V_3 /= ( int ) sizeof( struct V_7 ) ;
else
V_3 = 0 ;
V_3 += V_4 - V_119 ;
return V_3 ;
}
static inline int F_67 ( struct V_122 * V_123 ,
enum V_124 V_125 ,
int V_119 )
{
T_4 V_90 = F_68 ( V_123 , V_125 ) ;
return F_64 ( V_90 , V_119 ) ;
}
static inline int F_69 ( struct V_14 * V_15 ,
const struct V_126 * V_127 ,
enum V_124 V_125 , int V_119 )
{
T_4 V_90 = F_70 ( V_15 -> V_128 , V_127 , V_125 ) ;
return F_64 ( V_90 , V_119 ) ;
}
int F_71 ( struct V_67 * exp , struct V_68 * V_69 ,
int V_129 , int V_130 , int V_131 ,
struct V_132 * V_133 , int V_2 )
{
struct V_53 * V_54 = exp -> V_24 -> V_76 ;
struct V_122 * V_123 = & V_69 -> V_87 ;
struct V_8 * V_134 = NULL ;
int V_39 , V_3 , V_135 , V_136 = 0 ;
F_72 ( V_137 ) ;
int V_45 ;
if ( ! V_133 )
V_133 = & V_137 ;
if ( F_73 ( V_54 ) ) {
F_74 ( V_123 , V_138 ) ;
V_3 = F_67 ( V_123 , V_138 , V_131 ) ;
V_39 = F_75 ( V_54 ) ?
V_139 : V_140 ;
V_135 = ! F_75 ( V_54 ) &&
V_130 == V_5 ? 1 : 0 ;
if ( V_3 > V_2 )
V_2 += F_76 ( V_54 , V_133 , V_135 ,
V_3 - V_2 , 0 , V_39 ) ;
if ( V_3 > V_2 )
V_136 = V_2 ;
else
V_136 = V_3 ;
F_77 ( V_123 , & V_141 , V_138 ,
F_2 ( V_136 , V_130 ) ) ;
}
V_45 = F_78 ( V_69 , V_129 , V_130 ) ;
if ( V_45 ) {
F_79 ( V_133 , V_142 , V_2 ) ;
return V_45 ;
}
if ( F_73 ( V_54 ) ) {
if ( V_131 ) {
V_134 = F_80 ( V_123 , & V_141 ) ;
F_46 ( V_134 ) ;
V_134 -> V_143 = V_131 ;
}
F_81 ( V_133 , V_136 , V_69 , 0 ) ;
F_81 ( V_133 , V_2 - V_136 , NULL , 0 ) ;
} else {
F_79 ( V_133 , V_142 , V_2 ) ;
}
return 0 ;
}
int F_82 ( struct V_67 * exp , struct V_68 * V_69 ,
struct V_132 * V_133 , int V_2 )
{
return F_71 ( exp , V_69 , V_144 , V_5 ,
V_6 , V_133 , V_2 ) ;
}
static struct V_68 * F_83 ( struct V_67 * exp ,
int V_74 )
{
struct V_68 * V_69 ;
int V_45 ;
V_69 = F_84 ( F_85 ( exp ) , & V_145 ) ;
if ( ! V_69 )
return F_86 ( - V_108 ) ;
V_45 = F_82 ( exp , V_69 , NULL , 0 ) ;
if ( V_45 ) {
F_87 ( V_69 ) ;
return F_86 ( V_45 ) ;
}
F_77 ( & V_69 -> V_87 , & V_91 , V_92 , V_74 ) ;
F_88 ( V_69 ) ;
return V_69 ;
}
int F_89 ( struct V_67 * exp , struct V_68 * * V_146 ,
struct V_147 * V_148 ,
const struct V_149 * V_150 ,
union V_151 const * V_152 , T_1 * V_39 ,
void * V_73 , T_2 V_74 , enum V_153 V_153 ,
struct V_7 * V_75 , int V_154 )
{
struct V_53 * V_54 ;
struct V_11 * V_12 ;
struct V_8 * V_155 ;
int V_77 = * V_39 & V_78 ;
int V_156 = 1 ;
int V_45 , V_117 ;
struct V_68 * V_69 ;
V_54 = exp -> V_24 -> V_76 ;
if ( V_77 ) {
V_12 = F_90 ( V_75 , 0 ) ;
F_46 ( V_12 ) ;
F_21 ( V_12 , L_28 ) ;
F_46 ( exp == V_12 -> V_18 ) ;
} else {
const struct V_157 V_158 = {
. V_159 = V_148 -> V_160 ,
. V_161 = V_148 -> V_162 ,
. V_163 = V_148 -> V_164
} ;
V_12 = F_91 ( V_54 , V_150 , V_148 -> V_165 ,
V_148 -> V_166 , & V_158 , V_148 -> V_167 ,
V_74 , V_153 ) ;
if ( F_92 ( V_12 ) )
return F_93 ( V_12 ) ;
F_94 ( V_12 , V_148 -> V_166 ) ;
F_95 ( V_12 , V_75 ) ;
if ( V_152 )
V_12 -> V_111 = * V_152 ;
if ( V_148 -> V_165 == V_168 ) {
if ( ! V_152 )
F_96 () ;
V_12 -> V_169 = V_152 -> V_170 ;
}
F_21 ( V_12 , L_29 ,
* V_39 ) ;
}
V_12 -> V_18 = exp ;
V_12 -> V_171 = NULL ;
V_12 -> V_172 = V_148 -> V_162 ;
V_12 -> V_59 |= ( * V_39 & ( V_173 | V_174 ) ) ;
V_12 -> V_22 = F_5 () ;
if ( ! V_146 || ! * V_146 ) {
V_69 = F_83 ( exp , V_74 ) ;
if ( F_92 ( V_69 ) ) {
F_37 ( V_54 , V_12 , V_148 -> V_166 ) ;
F_63 ( V_12 ) ;
return F_93 ( V_69 ) ;
}
V_156 = 0 ;
if ( V_146 )
* V_146 = V_69 ;
} else {
int V_175 ;
V_69 = * V_146 ;
V_175 = F_50 ( & V_69 -> V_87 , & V_141 ,
V_138 ) ;
F_47 ( V_175 >= sizeof( * V_155 ) , L_30 ,
V_176 , V_175 , ( int ) sizeof( * V_155 ) ) ;
}
V_155 = F_80 ( & V_69 -> V_87 , & V_141 ) ;
F_97 ( V_12 , & V_155 -> V_104 ) ;
V_155 -> V_98 = F_98 ( * V_39 ) ;
V_155 -> V_96 [ 0 ] = * V_75 ;
if ( V_154 ) {
F_46 ( V_146 ) ;
return 0 ;
}
F_21 ( V_12 , L_31 ) ;
V_45 = F_99 ( V_69 ) ;
V_117 = F_44 ( exp , V_69 , V_148 -> V_165 , V_152 ? 1 : 0 ,
V_148 -> V_166 , V_39 , V_73 , V_74 ,
V_75 , V_45 ) ;
if ( V_117 == - V_82 )
F_63 ( V_12 ) ;
else
V_45 = V_117 ;
if ( ! V_156 && V_69 ) {
F_100 ( V_69 ) ;
if ( V_146 )
* V_146 = NULL ;
}
return V_45 ;
}
static T_1 F_101 ( struct V_11 * V_12 )
{
T_1 V_45 = V_60 ;
if ( V_12 -> V_18 ) {
bool V_177 ;
F_21 ( V_12 , L_32 ) ;
F_38 ( V_12 ) ;
F_102 ( V_12 ) ;
V_177 = ! ! ( V_12 -> V_59 &
( V_60 | V_178 ) ) ;
F_103 ( V_12 ) ;
V_45 = F_104 ( V_12 ) ? V_114 : V_179 ;
F_39 ( V_12 ) ;
if ( V_177 ) {
F_55 ( V_23 , L_33 ) ;
V_45 = V_60 ;
}
F_105 ( V_12 ) ;
} else {
F_4 ( V_12 , L_34 ) ;
F_96 () ;
}
return V_45 ;
}
static void F_106 ( struct V_68 * V_69 ,
struct V_132 * V_137 , int V_2 )
{
struct V_8 * V_134 ;
struct V_11 * V_12 ;
int F_17 , V_180 = 0 ;
V_134 = F_80 ( & V_69 -> V_87 , & V_141 ) ;
F_46 ( V_134 ) ;
F_17 = F_50 ( & V_69 -> V_87 , & V_141 , V_138 ) -
sizeof( struct V_8 ) ;
F_17 /= sizeof( struct V_7 ) ;
F_17 += V_4 ;
F_46 ( F_17 >= V_134 -> V_143 + V_2 ) ;
F_107 (lock, head, l_bl_ast) {
if ( ! V_2 -- )
break;
F_46 ( V_12 -> V_18 ) ;
F_21 ( V_12 , L_35 ) ;
V_134 -> V_96 [ V_134 -> V_143 ++ ] = V_12 -> V_95 ;
V_180 ++ ;
}
F_55 ( V_23 , L_36 , V_180 ) ;
}
static int F_108 ( struct V_67 * exp ,
struct V_132 * V_133 ,
int V_2 , enum V_181 V_39 )
{
struct V_68 * V_69 = NULL ;
struct V_14 * V_15 ;
int free , V_182 = 0 ;
int V_45 = 0 ;
F_46 ( exp ) ;
F_46 ( V_2 > 0 ) ;
F_109 ( V_183 , V_184 ) ;
if ( F_110 ( V_185 ) )
return V_2 ;
free = F_69 ( F_85 ( exp ) ,
& V_186 , V_138 , 0 ) ;
if ( V_2 > free )
V_2 = free ;
while ( 1 ) {
V_15 = F_85 ( exp ) ;
if ( ! V_15 || V_15 -> V_187 ) {
F_55 ( V_23 ,
L_37 , V_15 ) ;
return V_2 ;
}
V_69 = F_84 ( V_15 , & V_186 ) ;
if ( ! V_69 ) {
V_45 = - V_108 ;
goto V_188;
}
F_74 ( & V_69 -> V_87 , V_138 ) ;
F_77 ( & V_69 -> V_87 , & V_141 , V_138 ,
F_2 ( V_2 , V_189 ) ) ;
V_45 = F_78 ( V_69 , V_144 , V_189 ) ;
if ( V_45 ) {
F_87 ( V_69 ) ;
goto V_188;
}
V_69 -> V_190 = V_191 ;
V_69 -> V_192 = V_193 ;
F_111 ( V_69 ) ;
F_106 ( V_69 , V_133 , V_2 ) ;
F_88 ( V_69 ) ;
if ( V_39 & V_194 ) {
F_112 ( V_69 ) ;
V_182 = V_2 ;
goto V_188;
}
V_45 = F_99 ( V_69 ) ;
if ( V_45 == V_195 ) {
F_55 ( V_23 , L_38 ,
F_113 ( V_69 -> V_196 ->
V_29 -> V_197 . V_198 ) ) ;
V_45 = 0 ;
} else if ( V_45 == - V_199 &&
V_69 -> V_200 == V_15 -> V_201 ) {
F_100 ( V_69 ) ;
continue;
} else if ( V_45 != V_84 ) {
F_114 ( V_45 == - V_202 ? V_23 : V_203 ,
L_39 ,
V_45 ) ;
break;
}
V_182 = V_2 ;
break;
}
F_100 ( V_69 ) ;
V_188:
return V_182 ? V_182 : V_45 ;
}
static inline struct V_204 * F_115 ( struct V_14 * V_15 )
{
return & V_15 -> V_205 -> V_76 -> V_206 ;
}
int F_116 ( struct V_68 * V_69 )
{
struct V_16 * V_17 ;
T_1 V_207 ;
T_2 V_208 ;
if ( F_51 ( ! V_69 -> V_196 || ! V_69 -> V_196 -> V_205 ||
! F_117 ( V_69 -> V_196 ) ) ) {
return 0 ;
}
if ( F_118 ( V_69 -> V_209 ) == 0 ||
F_119 ( V_69 -> V_209 ) == 0 ) {
F_120 ( V_210 , V_69 ,
L_40 ,
F_118 ( V_69 -> V_209 ) ,
F_119 ( V_69 -> V_209 ) ) ;
return 0 ;
}
V_208 = F_119 ( V_69 -> V_209 ) ;
V_207 = F_118 ( V_69 -> V_209 ) ;
V_17 = V_69 -> V_196 -> V_205 ;
F_121 ( & V_17 -> V_211 ) ;
V_17 -> V_212 = V_207 ;
V_17 -> V_213 = V_208 ;
F_122 ( & V_17 -> V_211 ) ;
return 0 ;
}
int F_123 ( const struct V_7 * V_75 ,
enum V_181 V_214 )
{
struct V_67 * exp ;
int V_3 , V_39 , V_2 = 1 ;
T_1 V_45 = 0 ;
struct V_53 * V_54 ;
struct V_11 * V_12 ;
F_72 ( V_133 ) ;
V_12 = F_90 ( V_75 , 0 ) ;
if ( ! V_12 ) {
F_124 ( L_41 ) ;
return 0 ;
}
F_38 ( V_12 ) ;
if ( F_125 ( V_12 ) && ( V_214 & V_194 ) ) {
F_39 ( V_12 ) ;
F_63 ( V_12 ) ;
return 0 ;
}
F_126 ( V_12 ) ;
F_39 ( V_12 ) ;
V_45 = F_101 ( V_12 ) ;
if ( V_45 == V_60 || V_214 & V_215 ) {
F_63 ( V_12 ) ;
return 0 ;
}
F_46 ( F_127 ( & V_12 -> V_142 ) ) ;
F_128 ( & V_12 -> V_142 , & V_133 ) ;
exp = V_12 -> V_18 ;
if ( F_129 ( exp ) ) {
V_3 = F_69 ( F_85 ( exp ) ,
& V_186 ,
V_138 , 0 ) ;
F_46 ( V_3 > 0 ) ;
V_54 = F_10 ( V_12 ) ;
V_39 = F_75 ( V_54 ) ?
V_216 : V_140 ;
V_2 += F_76 ( V_54 , & V_133 , 0 , V_3 - 1 ,
V_217 , V_39 ) ;
}
F_81 ( & V_133 , V_2 , NULL , V_214 ) ;
return 0 ;
}
int F_130 ( struct V_132 * V_133 , int V_2 ,
enum V_181 V_39 )
{
F_72 ( V_137 ) ;
struct V_11 * V_12 , * V_218 ;
int V_219 = 0 , V_220 = 0 ;
T_1 V_45 ;
V_219 = V_2 ;
F_131 (lock, next, cancels, l_bl_ast) {
if ( V_219 -- == 0 )
break;
if ( V_39 & V_215 ) {
V_45 = V_60 ;
F_105 ( V_12 ) ;
} else {
V_45 = F_101 ( V_12 ) ;
}
if ( ! ( V_39 & V_217 ) && ( V_45 == V_114 ) ) {
F_21 ( V_12 , L_42 ) ;
F_132 ( & V_12 -> V_142 ) ;
F_128 ( & V_12 -> V_142 , & V_137 ) ;
V_220 ++ ;
continue;
}
if ( V_45 == V_60 ) {
F_132 ( & V_12 -> V_142 ) ;
F_63 ( V_12 ) ;
V_2 -- ;
}
}
if ( V_220 > 0 ) {
V_2 -= V_220 ;
F_81 ( & V_137 , V_220 , NULL , 0 ) ;
}
return V_2 ;
}
static enum V_221
F_133 ( struct V_53 * V_54 , struct V_11 * V_12 ,
int V_222 , int V_223 , int V_2 )
{
enum V_221 V_37 = V_224 ;
switch ( V_12 -> V_64 -> V_65 ) {
case V_168 :
case V_109 :
if ( V_54 -> V_225 && V_54 -> V_225 ( V_12 ) != 0 )
break;
default:
V_37 = V_226 ;
F_38 ( V_12 ) ;
F_134 ( V_12 ) ;
F_39 ( V_12 ) ;
break;
}
return V_37 ;
}
static enum V_221 F_135 ( struct V_53 * V_54 ,
struct V_11 * V_12 ,
int V_222 , int V_223 ,
int V_2 )
{
unsigned long V_227 = F_7 () ;
struct V_204 * V_228 = & V_54 -> V_206 ;
T_1 V_229 , V_230 , V_231 ;
unsigned long V_232 ;
if ( V_2 && V_223 >= V_2 )
return V_233 ;
if ( F_6 ( F_7 () ,
F_136 ( V_12 -> V_234 , V_54 -> V_235 ) ) )
return V_224 ;
V_229 = F_137 ( V_228 ) ;
V_230 = F_138 ( V_228 ) ;
V_232 = F_139 ( F_140 ( V_227 , V_12 -> V_234 ) ) ;
V_231 = V_230 * V_232 * V_222 ;
F_141 ( V_228 , V_231 ) ;
if ( V_229 == 0 || V_231 < V_229 )
return V_233 ;
return V_224 ;
}
static enum V_221 F_142 ( struct V_53 * V_54 ,
struct V_11 * V_12 ,
int V_222 , int V_223 ,
int V_2 )
{
return ( V_223 >= V_2 ) ?
V_233 : V_224 ;
}
static enum V_221 F_143 ( struct V_53 * V_54 ,
struct V_11 * V_12 ,
int V_222 , int V_223 ,
int V_2 )
{
if ( ( V_223 >= V_2 ) &&
F_144 ( F_7 () ,
F_136 ( V_12 -> V_234 , V_54 -> V_235 ) ) )
return V_233 ;
return V_224 ;
}
static enum V_221
F_145 ( struct V_53 * V_54 ,
struct V_11 * V_12 ,
int V_222 , int V_223 ,
int V_2 )
{
enum V_221 V_37 ;
V_37 = F_135 ( V_54 , V_12 , V_222 , V_223 , V_2 ) ;
if ( V_37 == V_233 )
return V_37 ;
return F_133 ( V_54 , V_12 , V_222 , V_223 , V_2 ) ;
}
static enum V_221
F_146 ( struct V_53 * V_54 , struct V_11 * V_12 ,
int V_222 , int V_223 , int V_2 )
{
return ( V_223 >= V_2 ) ?
V_233 : V_224 ;
}
static T_5
F_147 ( struct V_53 * V_54 , int V_39 )
{
if ( V_39 & V_236 )
return F_133 ;
if ( F_75 ( V_54 ) ) {
if ( V_39 & V_237 )
return F_142 ;
else if ( V_39 & V_216 )
return F_135 ;
else if ( V_39 & V_238 )
return F_142 ;
else if ( V_39 & V_139 )
return F_145 ;
} else {
if ( V_39 & V_140 )
return F_143 ;
}
return F_146 ;
}
static int F_148 ( struct V_53 * V_54 ,
struct V_132 * V_133 , int V_2 , int F_17 ,
int V_39 )
{
T_5 V_239 ;
struct V_11 * V_12 , * V_218 ;
int V_223 = 0 , V_222 , V_240 ;
int V_241 = V_39 & ( V_236 | V_139 ) ;
F_31 ( & V_54 -> V_242 ) ;
V_222 = V_54 -> V_243 ;
V_240 = V_222 ;
if ( ! F_75 ( V_54 ) )
V_2 += V_222 - V_54 -> V_244 ;
V_239 = F_147 ( V_54 , V_39 ) ;
F_46 ( V_239 ) ;
while ( ! F_127 ( & V_54 -> V_245 ) ) {
enum V_221 V_37 ;
T_6 V_246 = 0 ;
if ( V_240 -- <= 0 )
break;
if ( F_17 && V_223 >= F_17 )
break;
F_131 (lock, next, &ns->ns_unused_list,
l_lru) {
F_46 ( ! F_104 ( V_12 ) ) ;
if ( V_241 && F_149 ( V_12 ) )
continue;
V_246 = V_12 -> V_234 ;
if ( V_246 == F_7 () )
continue;
if ( ! F_125 ( V_12 ) )
break;
F_150 ( V_12 ) ;
}
if ( & V_12 -> V_247 == & V_54 -> V_245 )
break;
F_151 ( V_12 ) ;
F_32 ( & V_54 -> V_242 ) ;
F_152 ( & V_12 -> V_248 , V_249 , V_250 ) ;
V_37 = V_239 ( V_54 , V_12 , V_222 , V_223 , V_2 ) ;
if ( V_37 == V_233 ) {
F_153 ( & V_12 -> V_248 ,
V_249 , V_250 ) ;
F_63 ( V_12 ) ;
F_31 ( & V_54 -> V_242 ) ;
break;
}
if ( V_37 == V_226 ) {
F_153 ( & V_12 -> V_248 ,
V_249 , V_250 ) ;
F_63 ( V_12 ) ;
F_31 ( & V_54 -> V_242 ) ;
continue;
}
F_38 ( V_12 ) ;
if ( F_125 ( V_12 ) ||
( F_154 ( V_12 , V_246 ) == 0 ) ) {
F_39 ( V_12 ) ;
F_153 ( & V_12 -> V_248 ,
V_249 , V_250 ) ;
F_63 ( V_12 ) ;
F_31 ( & V_54 -> V_242 ) ;
continue;
}
F_46 ( ! V_12 -> V_251 && ! V_12 -> V_252 ) ;
F_155 ( V_12 ) ;
V_12 -> V_59 |= V_63 | V_179 ;
F_46 ( F_127 ( & V_12 -> V_142 ) ) ;
F_128 ( & V_12 -> V_142 , V_133 ) ;
F_39 ( V_12 ) ;
F_153 ( & V_12 -> V_248 , V_249 , V_250 ) ;
F_31 ( & V_54 -> V_242 ) ;
V_223 ++ ;
V_222 -- ;
}
F_32 ( & V_54 -> V_242 ) ;
return V_223 ;
}
int F_76 ( struct V_53 * V_54 ,
struct V_132 * V_133 , int V_2 , int F_17 ,
enum V_181 V_214 , int V_39 )
{
int V_223 ;
V_223 = F_148 ( V_54 , V_133 , V_2 , F_17 , V_39 ) ;
if ( V_223 <= 0 )
return V_223 ;
return F_130 ( V_133 , V_223 , V_214 ) ;
}
int F_156 ( struct V_53 * V_54 , int V_253 ,
enum V_181 V_214 ,
int V_39 )
{
F_72 ( V_133 ) ;
int V_2 , V_45 ;
V_2 = F_148 ( V_54 , & V_133 , V_253 , 0 , V_39 ) ;
V_45 = F_157 ( V_54 , NULL , & V_133 , V_2 , V_214 ) ;
if ( V_45 == 0 )
return V_2 ;
return 0 ;
}
int F_158 ( struct V_254 * V_255 ,
struct V_132 * V_133 ,
union V_151 * V_152 ,
enum V_72 V_55 , T_1 V_98 ,
enum V_181 V_214 ,
void * V_256 )
{
struct V_11 * V_12 ;
int V_2 = 0 ;
F_159 ( V_255 ) ;
F_107 (lock, &res->lr_granted, l_res_link) {
if ( V_256 && V_12 -> V_257 != V_256 ) {
F_4 ( V_12 , L_43 ,
V_12 -> V_257 , V_256 ) ;
continue;
}
if ( V_12 -> V_251 || V_12 -> V_252 )
continue;
if ( F_104 ( V_12 ) || F_125 ( V_12 ) )
continue;
if ( F_160 ( V_12 -> V_58 , V_55 ) )
continue;
if ( V_152 && ( V_12 -> V_64 -> V_65 == V_109 ) &&
! ( V_12 -> V_111 . V_258 . V_259 &
V_152 -> V_258 . V_259 ) )
continue;
V_12 -> V_59 |= V_63 | V_179 |
V_98 ;
F_46 ( F_127 ( & V_12 -> V_142 ) ) ;
F_128 ( & V_12 -> V_142 , V_133 ) ;
F_151 ( V_12 ) ;
V_2 ++ ;
}
F_161 ( V_255 ) ;
return F_130 ( V_133 , V_2 , V_214 ) ;
}
int F_81 ( struct V_132 * V_133 , int V_2 ,
struct V_68 * V_69 ,
enum V_181 V_39 )
{
struct V_11 * V_12 ;
int V_255 = 0 ;
if ( F_127 ( V_133 ) || V_2 == 0 )
return 0 ;
while ( V_2 > 0 ) {
F_46 ( ! F_127 ( V_133 ) ) ;
V_12 = F_162 ( V_133 -> V_218 , struct V_11 , V_142 ) ;
F_46 ( V_12 -> V_18 ) ;
if ( F_129 ( V_12 -> V_18 ) ) {
V_255 = V_2 ;
if ( V_69 )
F_106 ( V_69 , V_133 , V_2 ) ;
else
V_255 = F_108 ( V_12 -> V_18 ,
V_133 , V_2 ,
V_39 ) ;
} else {
V_255 = F_108 ( V_12 -> V_18 ,
V_133 , 1 , V_39 ) ;
}
if ( V_255 < 0 ) {
F_114 ( V_255 == - V_202 ? V_23 : V_203 ,
L_44 , V_249 , V_255 ) ;
V_255 = V_2 ;
}
V_2 -= V_255 ;
F_79 ( V_133 , V_142 , V_255 ) ;
}
F_46 ( V_2 == 0 ) ;
return 0 ;
}
int F_163 ( struct V_53 * V_54 ,
const struct V_149 * V_150 ,
union V_151 * V_152 ,
enum V_72 V_55 ,
enum V_181 V_39 ,
void * V_256 )
{
struct V_254 * V_255 ;
F_72 ( V_133 ) ;
int V_2 ;
int V_45 ;
V_255 = F_164 ( V_54 , NULL , V_150 , 0 , 0 ) ;
if ( F_92 ( V_255 ) ) {
F_55 ( V_100 , L_45 , V_150 -> V_260 [ 0 ] ) ;
return 0 ;
}
F_165 ( V_255 ) ;
V_2 = F_158 ( V_255 , & V_133 , V_152 , V_55 ,
0 , V_39 | V_217 , V_256 ) ;
V_45 = F_81 ( & V_133 , V_2 , NULL , V_39 ) ;
if ( V_45 != V_84 )
F_166 ( L_46 V_107 L_47 ,
F_57 ( V_255 ) , V_45 ) ;
F_167 ( V_255 ) ;
F_168 ( V_255 ) ;
return 0 ;
}
static int F_169 ( struct V_261 * V_262 ,
struct V_263 * V_264 ,
struct V_265 * V_266 , void * V_267 )
{
struct V_254 * V_255 = F_170 ( V_262 , V_266 ) ;
struct V_268 * V_269 = V_267 ;
F_163 ( F_171 ( V_255 ) , & V_255 -> V_106 ,
NULL , V_270 ,
V_269 -> V_271 , V_269 -> V_272 ) ;
return 0 ;
}
int F_172 ( struct V_53 * V_54 ,
const struct V_149 * V_150 ,
enum V_181 V_39 , void * V_256 )
{
struct V_268 V_267 = {
. V_271 = V_39 ,
. V_272 = V_256 ,
} ;
if ( ! V_54 )
return V_84 ;
if ( V_150 ) {
return F_163 ( V_54 , V_150 , NULL ,
V_270 , V_39 ,
V_256 ) ;
} else {
F_173 ( V_54 -> V_273 ,
F_169 , & V_267 , 0 ) ;
return V_84 ;
}
}
static int F_174 ( struct V_254 * V_255 ,
T_7 V_274 , void * V_275 )
{
struct V_132 * V_276 , * V_218 ;
struct V_11 * V_12 ;
int V_45 = V_277 ;
if ( ! V_255 )
return V_277 ;
F_159 ( V_255 ) ;
F_175 (tmp, next, &res->lr_granted) {
V_12 = F_162 ( V_276 , struct V_11 , V_278 ) ;
if ( V_274 ( V_12 , V_275 ) == V_279 ) {
V_45 = V_279 ;
goto V_188;
}
}
F_175 (tmp, next, &res->lr_waiting) {
V_12 = F_162 ( V_276 , struct V_11 , V_278 ) ;
if ( V_274 ( V_12 , V_275 ) == V_279 ) {
V_45 = V_279 ;
goto V_188;
}
}
V_188:
F_161 ( V_255 ) ;
return V_45 ;
}
static int F_176 ( struct V_11 * V_12 , void * V_275 )
{
struct V_280 * V_281 = V_275 ;
return V_281 -> V_274 ( V_12 , V_281 -> V_275 ) ;
}
static int F_177 ( struct V_261 * V_262 , struct V_263 * V_264 ,
struct V_265 * V_266 , void * V_267 )
{
struct V_254 * V_255 = F_170 ( V_262 , V_266 ) ;
return F_174 ( V_255 , F_176 , V_267 ) ==
V_279 ;
}
static void F_178 ( struct V_53 * V_54 ,
T_7 V_274 , void * V_275 )
{
struct V_280 V_281 = {
. V_274 = V_274 ,
. V_275 = V_275 ,
} ;
F_173 ( V_54 -> V_273 ,
F_177 , & V_281 , 0 ) ;
}
int F_179 ( struct V_53 * V_54 ,
const struct V_149 * V_150 ,
T_7 V_274 , void * V_1 )
{
struct V_254 * V_255 ;
int V_45 ;
F_47 ( V_54 , L_48 ) ;
V_255 = F_164 ( V_54 , NULL , V_150 , 0 , 0 ) ;
if ( F_92 ( V_255 ) )
return 0 ;
F_165 ( V_255 ) ;
V_45 = F_174 ( V_255 , V_274 , V_1 ) ;
F_167 ( V_255 ) ;
F_168 ( V_255 ) ;
return V_45 ;
}
static int F_180 ( struct V_11 * V_12 , void * V_275 )
{
struct V_132 * V_282 = V_275 ;
F_47 ( F_127 ( & V_12 -> V_283 ) ,
L_49 ,
V_12 , & V_12 -> V_283 . V_218 ,
& V_12 -> V_283 . V_284 ) ;
if ( ! ( V_12 -> V_59 & ( V_61 | V_285 ) ) ) {
F_128 ( & V_12 -> V_283 , V_282 ) ;
F_151 ( V_12 ) ;
}
return V_277 ;
}
static int F_181 ( const struct V_286 * V_287 ,
struct V_68 * V_69 ,
struct V_288 * V_289 , int V_45 )
{
struct V_11 * V_12 ;
struct V_79 * V_80 ;
struct V_67 * exp ;
F_182 ( & V_69 -> V_196 -> V_290 ) ;
if ( V_45 != V_84 )
goto V_188;
V_80 = F_49 ( & V_69 -> V_87 , & V_88 ) ;
if ( ! V_80 ) {
V_45 = - V_89 ;
goto V_188;
}
V_12 = F_45 ( & V_289 -> V_96 ) ;
if ( ! V_12 ) {
F_166 ( L_50 ,
V_289 -> V_96 . V_101 , V_80 -> V_96 . V_101 ,
V_69 -> V_291 -> V_292 . V_31 ,
F_183 ( V_69 -> V_293 ) ) ;
V_45 = - V_294 ;
goto V_188;
}
exp = V_69 -> V_291 ;
if ( exp && exp -> V_94 ) {
F_53 ( exp -> V_94 ,
& V_12 -> V_95 ,
& V_80 -> V_96 ,
& V_12 -> V_97 ) ;
} else {
V_12 -> V_95 = V_80 -> V_96 ;
}
F_21 ( V_12 , L_51 ) ;
F_184 ( V_69 -> V_196 ) ;
F_62 ( V_12 ) ;
V_188:
if ( V_45 != V_84 )
F_185 ( V_69 -> V_196 ) ;
return V_45 ;
}
static int F_186 ( struct V_14 * V_15 , struct V_11 * V_12 )
{
struct V_68 * V_69 ;
struct V_288 * V_289 ;
struct V_8 * V_155 ;
int V_39 ;
if ( F_187 ( V_12 ) ) {
F_21 ( V_12 , L_52 ) ;
return 0 ;
}
if ( F_188 ( V_12 ) ) {
F_21 ( V_12 , L_53 ) ;
F_105 ( V_12 ) ;
return 0 ;
}
if ( V_12 -> V_58 == V_12 -> V_57 )
V_39 = V_78 | V_295 ;
else if ( V_12 -> V_58 )
V_39 = V_78 | V_296 ;
else if ( ! F_127 ( & V_12 -> V_278 ) )
V_39 = V_78 | V_297 ;
else
V_39 = V_78 ;
V_69 = F_189 ( V_15 , & V_145 ,
V_144 , V_5 ) ;
if ( ! V_69 )
return - V_108 ;
V_69 -> V_298 = V_299 ;
V_155 = F_80 ( & V_69 -> V_87 , & V_141 ) ;
F_97 ( V_12 , & V_155 -> V_104 ) ;
V_155 -> V_98 = F_98 ( V_39 ) ;
F_95 ( V_12 , & V_155 -> V_96 [ 0 ] ) ;
if ( V_12 -> V_83 > 0 )
F_190 ( & V_69 -> V_87 , & V_300 ) ;
F_77 ( & V_69 -> V_87 , & V_91 , V_92 ,
V_12 -> V_83 ) ;
F_88 ( V_69 ) ;
F_191 ( V_69 -> V_301 , V_302 ) ;
F_21 ( V_12 , L_54 ) ;
F_192 ( & V_69 -> V_196 -> V_290 ) ;
F_193 ( sizeof( * V_289 ) > sizeof( V_69 -> V_303 ) ) ;
V_289 = F_194 ( V_69 ) ;
V_289 -> V_96 = V_155 -> V_96 [ 0 ] ;
V_69 -> V_304 = ( V_305 ) F_181 ;
F_112 ( V_69 ) ;
return 0 ;
}
static void F_195 ( struct V_53 * V_54 )
{
int V_306 ;
F_72 ( V_133 ) ;
F_55 ( V_23 , L_55 ,
F_196 ( V_54 ) , V_54 -> V_243 ) ;
V_306 = F_76 ( V_54 , & V_133 , V_54 -> V_243 , 0 ,
V_215 , V_236 ) ;
F_55 ( V_23 , L_56 ,
V_306 , F_196 ( V_54 ) ) ;
}
int F_197 ( struct V_14 * V_15 )
{
struct V_53 * V_54 = V_15 -> V_205 -> V_76 ;
F_72 ( V_282 ) ;
struct V_11 * V_12 , * V_218 ;
int V_45 = 0 ;
F_46 ( F_198 ( & V_15 -> V_290 ) == 0 ) ;
if ( V_15 -> V_307 )
return 0 ;
F_192 ( & V_15 -> V_290 ) ;
if ( V_308 )
F_195 ( V_54 ) ;
F_178 ( V_54 , F_180 , & V_282 ) ;
F_131 (lock, next, &list, l_pending_chain) {
F_132 ( & V_12 -> V_283 ) ;
if ( V_45 ) {
F_63 ( V_12 ) ;
continue;
}
V_45 = F_186 ( V_15 , V_12 ) ;
F_63 ( V_12 ) ;
}
F_182 ( & V_15 -> V_290 ) ;
return V_45 ;
}
