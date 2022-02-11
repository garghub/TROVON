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
if ( F_21 ( V_5 ) || F_22 ( V_5 ) ) {
F_5 ( V_5 , L_4 ) ;
V_31 = - V_32 ;
} else {
V_30 = F_4 () - V_5 -> V_15 ;
F_5 ( V_5 , L_5 ,
V_30 ) ;
F_23 ( F_17 ( V_5 ) ,
V_30 ) ;
V_31 = 0 ;
}
return V_31 ;
}
int F_24 ( struct V_4 * V_5 , T_1 V_33 , void * V_1 )
{
if ( V_33 == V_34 ) {
F_5 ( V_5 , L_6 ) ;
return 0 ;
}
if ( ! ( V_33 & ( V_35 | V_36 |
V_37 ) ) ) {
F_25 ( & V_5 -> V_38 ) ;
return F_20 ( V_5 ) ;
}
F_5 ( V_5 , L_7 ) ;
return 0 ;
}
int F_26 ( struct V_4 * V_5 , T_1 V_33 , void * V_1 )
{
struct V_2 V_3 ;
struct V_9 * V_10 ;
struct V_7 * V_8 = NULL ;
struct V_39 V_40 ;
T_2 V_25 ;
int V_41 = 0 ;
if ( V_33 == V_34 ) {
F_5 ( V_5 , L_6 ) ;
goto V_42;
}
if ( ! ( V_33 & ( V_35 | V_36 |
V_37 ) ) ) {
F_25 ( & V_5 -> V_38 ) ;
return 0 ;
}
F_5 ( V_5 , L_8 ) ;
V_42:
V_10 = F_27 ( V_5 -> V_11 ) ;
if ( V_10 )
V_8 = V_10 -> V_18 . V_19 . V_20 ;
V_25 = F_15 ( V_5 ) * 2 ;
V_3 . V_6 = V_5 ;
if ( F_28 ( V_5 ) ) {
F_5 ( V_5 , L_9 ) ;
V_40 = F_29 ( F_1 , & V_3 ) ;
} else {
V_40 = F_30 ( F_31 ( V_25 ) ,
F_2 ,
F_1 , & V_3 ) ;
}
if ( V_8 ) {
F_32 ( & V_8 -> V_43 ) ;
V_3 . V_21 = V_8 -> V_44 ;
F_33 ( & V_8 -> V_43 ) ;
}
if ( F_34 ( V_45 ,
V_46 | V_47 ) ) {
F_35 ( V_5 ) ;
V_41 = - V_48 ;
} else {
V_41 = F_36 ( V_5 -> V_38 ,
F_37 ( V_5 ) , & V_40 ) ;
}
if ( V_41 ) {
F_5 ( V_5 , L_10 ,
V_41 ) ;
return V_41 ;
}
return F_20 ( V_5 ) ;
}
static void F_38 ( struct V_49 * V_50 ,
struct V_4 * V_5 , int V_51 )
{
int V_52 = 0 ;
F_39 ( V_5 ) ;
if ( ( V_5 -> V_53 != V_5 -> V_54 ) &&
! F_22 ( V_5 ) ) {
V_5 -> V_55 |= V_56 | V_57 |
V_58 | V_59 ;
V_52 = 1 ;
}
F_40 ( V_5 ) ;
if ( V_52 )
F_5 ( V_5 ,
L_11 ) ;
else
F_5 ( V_5 , L_12 ) ;
F_41 ( V_5 , V_51 ) ;
if ( V_5 -> V_60 -> V_61 == V_62 ) {
F_39 ( V_5 ) ;
F_42 ( V_5 ) ;
F_43 ( V_5 ) ;
F_40 ( V_5 ) ;
}
}
int F_44 ( struct V_63 * exp , struct V_64 * V_65 ,
enum V_66 type , T_3 V_67 ,
enum V_68 V_51 ,
T_1 * V_33 , void * V_69 , T_2 V_70 ,
struct V_71 * V_72 , int V_41 )
{
struct V_49 * V_50 = exp -> V_17 -> V_73 ;
int V_74 = * V_33 & V_75 ;
struct V_4 * V_5 ;
struct V_76 * V_77 ;
int V_78 = 1 ;
V_5 = F_45 ( V_72 ) ;
if ( ! V_5 ) {
F_46 ( type == V_62 ) ;
return - V_79 ;
}
F_47 ( F_48 ( V_70 != 0 , V_70 == V_5 -> V_80 ) ,
L_13 , V_70 , V_5 -> V_80 ) ;
if ( V_41 != V_81 ) {
F_46 ( ! V_74 ) ;
F_5 ( V_5 , L_14 ,
V_41 == V_82 ? L_15 : L_16 ) ;
if ( V_41 != V_82 )
goto V_83;
}
V_77 = F_49 ( & V_65 -> V_84 , & V_85 ) ;
if ( ! V_77 ) {
V_41 = - V_86 ;
goto V_83;
}
if ( V_70 > 0 ) {
int V_87 = 0 ;
V_87 = F_50 ( & V_65 -> V_84 , & V_88 ,
V_89 ) ;
if ( V_87 < 0 ) {
F_13 ( V_5 , L_17 , V_87 ) ;
V_41 = V_87 ;
goto V_83;
} else if ( F_51 ( V_87 > V_70 ) ) {
F_13 ( V_5 , L_18 ,
V_70 , V_87 ) ;
V_41 = - V_90 ;
goto V_83;
}
V_70 = V_87 ;
}
if ( V_41 == V_82 ) {
if ( V_70 > 0 && V_69 )
V_41 = F_52 ( V_5 , & V_65 -> V_84 , V_89 ,
V_69 , V_70 ) ;
if ( V_41 == 0 )
V_41 = V_82 ;
goto V_83;
}
V_78 = 0 ;
F_39 ( V_5 ) ;
if ( exp -> V_91 ) {
F_53 ( exp -> V_91 ,
& V_5 -> V_92 ,
& V_77 -> V_93 ,
& V_5 -> V_94 ) ;
} else {
V_5 -> V_92 = V_77 -> V_93 ;
}
* V_33 = F_54 ( V_77 -> V_95 ) ;
V_5 -> V_55 |= F_54 ( V_77 -> V_95 &
V_96 ) ;
V_5 -> V_55 |= F_54 ( V_77 -> V_95 &
V_97 ) ;
F_40 ( V_5 ) ;
F_55 ( V_98 , L_19 ,
V_5 , V_77 -> V_93 . V_99 , * V_33 ) ;
if ( ( * V_33 ) & V_100 ) {
int V_101 = V_77 -> V_102 . V_53 ;
F_46 ( ! V_74 ) ;
if ( V_101 && V_101 != V_5 -> V_53 ) {
F_5 ( V_5 , L_20 ,
V_103 [ V_101 ] ) ;
V_5 -> V_53 = V_101 ;
}
if ( ! F_56 ( & V_77 -> V_102 . V_60 . V_104 ,
& V_5 -> V_60 -> V_104 ) ) {
F_55 ( V_98 , L_21 V_105
L_22 V_105 L_23 ,
F_57 ( & V_77 -> V_102 . V_60 ) ,
F_57 ( V_5 -> V_60 ) ) ;
V_41 = F_58 ( V_50 , V_5 ,
& V_77 -> V_102 . V_60 . V_104 ) ;
if ( V_41 || ! V_5 -> V_60 ) {
V_41 = - V_106 ;
goto V_83;
}
F_5 ( V_5 , L_24 ) ;
}
if ( V_67 )
if ( ! ( type == V_107 &&
! ( F_59 ( exp ) & V_108 ) ) )
F_60 ( exp ,
V_5 -> V_60 -> V_61 ,
& V_77 -> V_102 . V_109 ,
& V_5 -> V_109 ) ;
if ( type != V_110 )
F_5 ( V_5 ,
L_25 ) ;
}
if ( ( * V_33 ) & V_111 ||
( V_112 && type == V_113 ) ) {
F_39 ( V_5 ) ;
V_5 -> V_55 |= V_59 | V_114 ;
F_40 ( V_5 ) ;
F_5 ( V_5 , L_26 ) ;
}
if ( V_70 > 0 ) {
F_39 ( V_5 ) ;
if ( V_5 -> V_53 != V_5 -> V_54 )
V_41 = F_52 ( V_5 , & V_65 -> V_84 , V_89 ,
V_5 -> V_115 , V_70 ) ;
F_40 ( V_5 ) ;
if ( V_41 < 0 ) {
V_78 = 1 ;
goto V_83;
}
}
if ( ! V_74 ) {
V_41 = F_61 ( V_50 , & V_5 , NULL , V_33 ) ;
if ( V_5 -> V_116 ) {
int V_117 = V_5 -> V_116 ( V_5 , * V_33 , NULL ) ;
if ( ! V_41 )
V_41 = V_117 ;
if ( V_41 )
V_78 = 1 ;
}
}
if ( V_70 > 0 && V_69 ) {
memcpy ( V_69 , V_5 -> V_115 , V_70 ) ;
}
F_5 ( V_5 , L_27 ) ;
V_83:
if ( V_78 == 1 && V_41 )
F_38 ( V_50 , V_5 , V_51 ) ;
F_62 ( V_5 ) ;
F_63 ( V_5 ) ;
return V_41 ;
}
static inline int F_64 ( int V_118 , int V_119 )
{
int V_120 ;
V_120 = F_18 ( int , V_121 , V_122 - 512 ) - V_118 ;
if ( F_65 ( V_120 >= 0 ) )
V_120 /= ( int ) sizeof( struct V_71 ) ;
else
V_120 = 0 ;
V_120 += V_123 - V_119 ;
return V_120 ;
}
static inline int F_66 ( struct V_124 * V_125 ,
enum V_126 V_127 ,
int V_119 )
{
int V_87 = F_67 ( V_125 , V_127 ) ;
return F_64 ( V_87 , V_119 ) ;
}
static inline int F_68 ( struct V_7 * V_8 ,
const struct V_128 * V_129 ,
enum V_126 V_127 , int V_119 )
{
int V_87 = F_69 ( V_8 -> V_130 , V_129 , V_127 ) ;
return F_64 ( V_87 , V_119 ) ;
}
int F_70 ( struct V_63 * exp , struct V_64 * V_65 ,
int V_131 , int V_132 , int V_133 ,
struct V_134 * V_135 , int V_136 )
{
struct V_49 * V_50 = exp -> V_17 -> V_73 ;
struct V_124 * V_125 = & V_65 -> V_84 ;
struct V_137 * V_138 = NULL ;
int V_33 , V_120 , V_139 , V_140 = 0 ;
F_71 ( V_141 ) ;
int V_41 ;
if ( ! V_135 )
V_135 = & V_141 ;
if ( F_72 ( V_50 ) ) {
F_73 ( V_125 , V_142 ) ;
V_120 = F_66 ( V_125 , V_142 , V_133 ) ;
V_33 = F_74 ( V_50 ) ?
V_143 : V_144 ;
V_139 = ! F_74 ( V_50 ) &&
V_132 == V_145 ? 1 : 0 ;
if ( V_120 > V_136 )
V_136 += F_75 ( V_50 , V_135 , V_139 ,
V_120 - V_136 , 0 , V_33 ) ;
if ( V_120 > V_136 )
V_140 = V_136 ;
else
V_140 = V_120 ;
F_76 ( V_125 , & V_146 , V_142 ,
F_77 ( V_140 , V_132 ) ) ;
}
V_41 = F_78 ( V_65 , V_131 , V_132 ) ;
if ( V_41 ) {
F_79 ( V_135 , V_147 , V_136 ) ;
return V_41 ;
}
if ( F_72 ( V_50 ) ) {
if ( V_133 ) {
V_138 = F_80 ( V_125 , & V_146 ) ;
F_46 ( V_138 ) ;
V_138 -> V_148 = V_133 ;
}
F_81 ( V_135 , V_140 , V_65 , 0 ) ;
F_81 ( V_135 , V_136 - V_140 , NULL , 0 ) ;
} else {
F_79 ( V_135 , V_147 , V_136 ) ;
}
return 0 ;
}
int F_82 ( struct V_63 * exp , struct V_64 * V_65 ,
struct V_134 * V_135 , int V_136 )
{
return F_70 ( exp , V_65 , V_149 , V_145 ,
V_150 , V_135 , V_136 ) ;
}
int F_83 ( struct V_63 * exp , struct V_64 * * V_151 ,
struct V_152 * V_153 ,
const struct V_154 * V_155 ,
T_4 const * V_156 , T_1 * V_33 ,
void * V_69 , T_2 V_70 , enum V_157 V_157 ,
struct V_71 * V_72 , int V_158 )
{
struct V_49 * V_50 ;
struct V_4 * V_5 ;
struct V_137 * V_159 ;
int V_74 = * V_33 & V_75 ;
int V_160 = 1 ;
int V_41 , V_117 ;
struct V_64 * V_65 ;
V_50 = exp -> V_17 -> V_73 ;
if ( V_74 ) {
V_5 = F_84 ( V_72 , 0 ) ;
F_46 ( V_5 ) ;
F_5 ( V_5 , L_28 ) ;
F_46 ( exp == V_5 -> V_11 ) ;
} else {
const struct V_161 V_162 = {
. V_163 = V_153 -> V_164 ,
. V_165 = V_153 -> V_166 ,
. V_167 = V_153 -> V_168
} ;
V_5 = F_85 ( V_50 , V_155 , V_153 -> V_169 ,
V_153 -> V_170 , & V_162 , V_153 -> V_171 ,
V_70 , V_157 ) ;
if ( ! V_5 )
return - V_106 ;
F_86 ( V_5 , V_153 -> V_170 ) ;
F_87 ( V_5 , V_72 ) ;
if ( V_156 )
V_5 -> V_109 = * V_156 ;
if ( V_153 -> V_169 == V_113 ) {
if ( ! V_156 )
F_88 () ;
V_5 -> V_172 = V_156 -> V_173 ;
}
F_5 ( V_5 , L_29 ,
* V_33 ) ;
}
V_5 -> V_11 = exp ;
V_5 -> V_174 = NULL ;
V_5 -> V_175 = V_153 -> V_166 ;
V_5 -> V_55 |= ( * V_33 & ( V_176 | V_177 ) ) ;
if ( ! V_151 || ! * V_151 ) {
V_65 = F_89 ( F_90 ( exp ) ,
& V_178 ,
V_149 ,
V_145 ) ;
if ( ! V_65 ) {
F_38 ( V_50 , V_5 , V_153 -> V_170 ) ;
F_63 ( V_5 ) ;
return - V_106 ;
}
V_160 = 0 ;
if ( V_151 )
* V_151 = V_65 ;
} else {
int V_179 ;
V_65 = * V_151 ;
V_179 = F_50 ( & V_65 -> V_84 , & V_146 ,
V_142 ) ;
F_47 ( V_179 >= sizeof( * V_159 ) , L_30 ,
V_180 , V_179 , ( int ) sizeof( * V_159 ) ) ;
}
V_159 = F_80 ( & V_65 -> V_84 , & V_146 ) ;
F_91 ( V_5 , & V_159 -> V_102 ) ;
V_159 -> V_95 = F_92 ( * V_33 ) ;
V_159 -> V_93 [ 0 ] = * V_72 ;
if ( ! V_160 ) {
if ( V_70 > 0 )
F_93 ( & V_65 -> V_84 ,
& V_181 ) ;
F_76 ( & V_65 -> V_84 , & V_88 , V_89 ,
V_70 ) ;
F_94 ( V_65 ) ;
}
F_46 ( F_48 ( V_112 , V_153 -> V_169 != V_113 ||
V_156 -> V_173 . V_182 == V_183 ) ) ;
if ( V_158 ) {
F_46 ( V_151 ) ;
return 0 ;
}
F_5 ( V_5 , L_31 ) ;
V_41 = F_95 ( V_65 ) ;
V_117 = F_44 ( exp , V_65 , V_153 -> V_169 , V_156 ? 1 : 0 ,
V_153 -> V_170 , V_33 , V_69 , V_70 ,
V_72 , V_41 ) ;
if ( V_117 == - V_79 )
F_63 ( V_5 ) ;
else
V_41 = V_117 ;
if ( ! V_160 && V_65 ) {
F_96 ( V_65 ) ;
if ( V_151 )
* V_151 = NULL ;
}
return V_41 ;
}
static T_1 F_97 ( struct V_4 * V_5 )
{
T_1 V_41 = V_56 ;
if ( V_5 -> V_11 ) {
bool V_184 ;
F_5 ( V_5 , L_32 ) ;
F_39 ( V_5 ) ;
F_98 ( V_5 ) ;
V_184 = ! ! ( V_5 -> V_55 &
( V_56 | V_185 ) ) ;
F_99 ( V_5 ) ;
V_41 = F_100 ( V_5 ) ? V_114 : V_186 ;
F_40 ( V_5 ) ;
if ( V_184 ) {
F_55 ( V_16 , L_33 ) ;
V_41 = V_56 ;
}
F_101 ( V_5 ) ;
} else {
F_13 ( V_5 , L_34 ) ;
F_88 () ;
}
return V_41 ;
}
static void F_102 ( struct V_64 * V_65 ,
struct V_134 * V_141 , int V_136 )
{
struct V_137 * V_138 ;
struct V_4 * V_5 ;
int F_19 , V_187 = 0 ;
V_138 = F_80 ( & V_65 -> V_84 , & V_146 ) ;
F_46 ( V_138 ) ;
F_19 = F_50 ( & V_65 -> V_84 , & V_146 , V_142 ) -
sizeof( struct V_137 ) ;
F_19 /= sizeof( struct V_71 ) ;
F_19 += V_123 ;
F_46 ( F_19 >= V_138 -> V_148 + V_136 ) ;
F_103 (lock, head, l_bl_ast) {
if ( ! V_136 -- )
break;
F_46 ( V_5 -> V_11 ) ;
F_5 ( V_5 , L_35 ) ;
V_138 -> V_93 [ V_138 -> V_148 ++ ] = V_5 -> V_92 ;
V_187 ++ ;
}
F_55 ( V_16 , L_36 , V_187 ) ;
}
static int F_104 ( struct V_63 * exp ,
struct V_134 * V_135 ,
int V_136 , enum V_188 V_33 )
{
struct V_64 * V_65 = NULL ;
struct V_7 * V_8 ;
int free , V_189 = 0 ;
int V_41 = 0 ;
F_46 ( exp ) ;
F_46 ( V_136 > 0 ) ;
F_105 ( V_190 , V_191 ) ;
if ( F_106 ( V_192 ) )
return V_136 ;
free = F_68 ( F_90 ( exp ) ,
& V_193 , V_142 , 0 ) ;
if ( V_136 > free )
V_136 = free ;
while ( 1 ) {
V_8 = F_90 ( exp ) ;
if ( ! V_8 || V_8 -> V_194 ) {
F_55 ( V_16 ,
L_37 , V_8 ) ;
return V_136 ;
}
V_65 = F_107 ( V_8 , & V_193 ) ;
if ( ! V_65 ) {
V_41 = - V_106 ;
goto V_195;
}
F_73 ( & V_65 -> V_84 , V_142 ) ;
F_76 ( & V_65 -> V_84 , & V_146 , V_142 ,
F_77 ( V_136 , V_196 ) ) ;
V_41 = F_78 ( V_65 , V_149 , V_196 ) ;
if ( V_41 ) {
F_108 ( V_65 ) ;
goto V_195;
}
V_65 -> V_197 = V_198 ;
V_65 -> V_199 = V_200 ;
F_109 ( V_65 ) ;
F_102 ( V_65 , V_135 , V_136 ) ;
F_94 ( V_65 ) ;
if ( V_33 & V_201 ) {
F_110 ( V_65 ) ;
V_189 = V_136 ;
goto V_195;
}
V_41 = F_95 ( V_65 ) ;
if ( V_41 == V_202 ) {
F_55 ( V_16 , L_38 ,
F_111 ( V_65 -> V_203 ->
V_22 -> V_204 . V_205 ) ) ;
V_41 = 0 ;
} else if ( V_41 == - V_206 &&
V_65 -> V_207 == V_8 -> V_208 ) {
F_96 ( V_65 ) ;
continue;
} else if ( V_41 != V_81 ) {
F_112 ( V_41 == - V_209 ? V_16 : V_210 ,
L_39 ,
V_41 ) ;
break;
}
V_189 = V_136 ;
break;
}
F_96 ( V_65 ) ;
V_195:
return V_189 ? V_189 : V_41 ;
}
static inline struct V_211 * F_113 ( struct V_7 * V_8 )
{
return & V_8 -> V_212 -> V_73 -> V_213 ;
}
int F_114 ( struct V_64 * V_65 )
{
struct V_9 * V_10 ;
T_1 V_214 ;
T_2 V_215 ;
if ( F_51 ( ! V_65 -> V_203 || ! V_65 -> V_203 -> V_212 ||
! F_115 ( V_65 -> V_203 ) ) ) {
return 0 ;
}
if ( F_116 ( V_65 -> V_216 ) == 0 ||
F_117 ( V_65 -> V_216 ) == 0 ) {
F_118 ( V_217 , V_65 ,
L_40 ,
F_116 ( V_65 -> V_216 ) ,
F_117 ( V_65 -> V_216 ) ) ;
return 0 ;
}
V_215 = F_117 ( V_65 -> V_216 ) ;
V_214 = F_116 ( V_65 -> V_216 ) ;
V_10 = V_65 -> V_203 -> V_212 ;
F_119 ( & V_10 -> V_218 ) ;
V_10 -> V_219 = V_214 ;
V_10 -> V_220 = V_215 ;
F_120 ( & V_10 -> V_218 ) ;
return 0 ;
}
int F_121 ( struct V_71 * V_72 ,
enum V_188 V_221 )
{
struct V_63 * exp ;
int V_120 , V_33 , V_136 = 1 ;
T_1 V_41 = 0 ;
struct V_49 * V_50 ;
struct V_4 * V_5 ;
F_71 ( V_135 ) ;
V_5 = F_84 ( V_72 , V_186 ) ;
if ( ! V_5 ) {
F_122 ( L_41 ) ;
return 0 ;
}
V_41 = F_97 ( V_5 ) ;
if ( V_41 == V_56 || V_221 & V_222 ) {
F_63 ( V_5 ) ;
return 0 ;
}
F_46 ( F_123 ( & V_5 -> V_147 ) ) ;
F_124 ( & V_5 -> V_147 , & V_135 ) ;
exp = V_5 -> V_11 ;
if ( F_125 ( exp ) ) {
V_120 = F_68 ( F_90 ( exp ) ,
& V_193 ,
V_142 , 0 ) ;
F_46 ( V_120 > 0 ) ;
V_50 = F_10 ( V_5 ) ;
V_33 = F_74 ( V_50 ) ?
V_223 : V_144 ;
V_136 += F_75 ( V_50 , & V_135 , 0 , V_120 - 1 ,
V_224 , V_33 ) ;
}
F_81 ( & V_135 , V_136 , NULL , V_221 ) ;
return 0 ;
}
int F_126 ( struct V_134 * V_135 , int V_136 ,
enum V_188 V_33 )
{
F_71 ( V_141 ) ;
struct V_4 * V_5 , * V_225 ;
int V_226 = 0 , V_227 = 0 ;
T_1 V_41 ;
V_226 = V_136 ;
F_127 (lock, next, cancels, l_bl_ast) {
if ( V_226 -- == 0 )
break;
if ( V_33 & V_222 ) {
V_41 = V_56 ;
F_101 ( V_5 ) ;
} else {
V_41 = F_97 ( V_5 ) ;
}
if ( ! ( V_33 & V_224 ) && ( V_41 == V_114 ) ) {
F_5 ( V_5 , L_42 ) ;
F_128 ( & V_5 -> V_147 ) ;
F_124 ( & V_5 -> V_147 , & V_141 ) ;
V_227 ++ ;
continue;
}
if ( V_41 == V_56 ) {
F_128 ( & V_5 -> V_147 ) ;
F_63 ( V_5 ) ;
V_136 -- ;
}
}
if ( V_227 > 0 ) {
V_136 -= V_227 ;
F_81 ( & V_141 , V_227 , NULL , 0 ) ;
}
return V_136 ;
}
static enum V_228
F_129 ( struct V_49 * V_50 , struct V_4 * V_5 ,
int V_229 , int V_230 , int V_136 )
{
enum V_228 V_31 = V_231 ;
switch ( V_5 -> V_60 -> V_61 ) {
case V_113 :
case V_107 :
if ( V_50 -> V_232 && V_50 -> V_232 ( V_5 ) != 0 )
break;
default:
V_31 = V_233 ;
F_39 ( V_5 ) ;
F_130 ( V_5 ) ;
F_40 ( V_5 ) ;
break;
}
return V_31 ;
}
static enum V_228 F_131 ( struct V_49 * V_50 ,
struct V_4 * V_5 ,
int V_229 , int V_230 ,
int V_136 )
{
unsigned long V_234 = F_7 () ;
struct V_211 * V_235 = & V_50 -> V_213 ;
T_1 V_236 , V_237 , V_238 ;
unsigned long V_239 ;
if ( V_136 && V_230 >= V_136 )
return V_240 ;
V_236 = F_132 ( V_235 ) ;
V_237 = F_133 ( V_235 ) ;
V_239 = F_134 ( F_135 ( V_234 ,
V_5 -> V_241 ) ) ;
V_238 = V_237 * V_239 * V_229 ;
F_136 ( V_235 , V_238 ) ;
if ( V_236 == 0 || V_238 < V_236 )
return V_240 ;
if ( V_50 -> V_232 && V_50 -> V_232 ( V_5 ) == 0 )
return V_240 ;
return V_231 ;
}
static enum V_228 F_137 ( struct V_49 * V_50 ,
struct V_4 * V_5 ,
int V_229 , int V_230 ,
int V_136 )
{
return ( V_230 >= V_136 ) ?
V_240 : V_231 ;
}
static enum V_228 F_138 ( struct V_49 * V_50 ,
struct V_4 * V_5 ,
int V_229 , int V_230 ,
int V_136 )
{
if ( ( V_230 >= V_136 ) &&
F_139 ( F_7 () ,
F_140 ( V_5 -> V_241 , V_50 -> V_242 ) ) )
return V_240 ;
if ( V_50 -> V_232 && V_50 -> V_232 ( V_5 ) == 0 )
return V_240 ;
return V_231 ;
}
static enum V_228
F_141 ( struct V_49 * V_50 ,
struct V_4 * V_5 ,
int V_229 , int V_230 ,
int V_136 )
{
enum V_228 V_31 ;
V_31 = F_131 ( V_50 , V_5 , V_229 , V_230 , V_136 ) ;
if ( V_31 == V_240 )
return V_31 ;
return F_129 ( V_50 , V_5 , V_229 , V_230 , V_136 ) ;
}
static enum V_228
F_142 ( struct V_49 * V_50 , struct V_4 * V_5 ,
int V_229 , int V_230 , int V_136 )
{
return ( V_230 >= V_136 ) ?
V_240 : V_231 ;
}
static T_5
F_143 ( struct V_49 * V_50 , int V_33 )
{
if ( V_33 & V_243 )
return F_129 ;
if ( F_74 ( V_50 ) ) {
if ( V_33 & V_244 )
return F_137 ;
else if ( V_33 & V_223 )
return F_131 ;
else if ( V_33 & V_245 )
return F_137 ;
else if ( V_33 & V_143 )
return F_141 ;
} else {
if ( V_33 & V_144 )
return F_138 ;
}
return F_142 ;
}
static int F_144 ( struct V_49 * V_50 ,
struct V_134 * V_135 , int V_136 , int F_19 ,
int V_33 )
{
T_5 V_246 ;
struct V_4 * V_5 , * V_225 ;
int V_230 = 0 , V_229 , V_247 ;
int V_248 = V_33 & ( V_243 | V_143 ) ;
F_32 ( & V_50 -> V_249 ) ;
V_229 = V_50 -> V_250 ;
V_247 = V_229 ;
if ( ! F_74 ( V_50 ) )
V_136 += V_229 - V_50 -> V_251 ;
V_246 = F_143 ( V_50 , V_33 ) ;
F_46 ( V_246 ) ;
while ( ! F_123 ( & V_50 -> V_252 ) ) {
enum V_228 V_31 ;
T_6 V_253 = 0 ;
if ( V_247 -- <= 0 )
break;
if ( F_19 && V_230 >= F_19 )
break;
F_127 (lock, next, &ns->ns_unused_list,
l_lru) {
F_46 ( ! F_100 ( V_5 ) ) ;
if ( V_248 && F_145 ( V_5 ) )
continue;
V_253 = V_5 -> V_241 ;
if ( V_253 == F_7 () )
continue;
if ( ! F_146 ( V_5 ) )
break;
F_147 ( V_5 ) ;
}
if ( & V_5 -> V_254 == & V_50 -> V_252 )
break;
F_148 ( V_5 ) ;
F_33 ( & V_50 -> V_249 ) ;
F_149 ( & V_5 -> V_255 , V_256 , V_257 ) ;
V_31 = V_246 ( V_50 , V_5 , V_229 , V_230 , V_136 ) ;
if ( V_31 == V_240 ) {
F_150 ( & V_5 -> V_255 ,
V_256 , V_257 ) ;
F_63 ( V_5 ) ;
F_32 ( & V_50 -> V_249 ) ;
break;
}
if ( V_31 == V_233 ) {
F_150 ( & V_5 -> V_255 ,
V_256 , V_257 ) ;
F_63 ( V_5 ) ;
F_32 ( & V_50 -> V_249 ) ;
continue;
}
F_39 ( V_5 ) ;
if ( F_146 ( V_5 ) ||
( F_151 ( V_5 , V_253 ) == 0 ) ) {
F_40 ( V_5 ) ;
F_150 ( & V_5 -> V_255 ,
V_256 , V_257 ) ;
F_63 ( V_5 ) ;
F_32 ( & V_50 -> V_249 ) ;
continue;
}
F_46 ( ! V_5 -> V_258 && ! V_5 -> V_259 ) ;
F_152 ( V_5 ) ;
V_5 -> V_55 |= V_59 | V_186 ;
F_46 ( F_123 ( & V_5 -> V_147 ) ) ;
F_124 ( & V_5 -> V_147 , V_135 ) ;
F_40 ( V_5 ) ;
F_150 ( & V_5 -> V_255 , V_256 , V_257 ) ;
F_32 ( & V_50 -> V_249 ) ;
V_230 ++ ;
V_229 -- ;
}
F_33 ( & V_50 -> V_249 ) ;
return V_230 ;
}
int F_75 ( struct V_49 * V_50 ,
struct V_134 * V_135 , int V_136 , int F_19 ,
enum V_188 V_221 , int V_33 )
{
int V_230 ;
V_230 = F_144 ( V_50 , V_135 , V_136 , F_19 , V_33 ) ;
if ( V_230 <= 0 )
return V_230 ;
return F_126 ( V_135 , V_230 , V_221 ) ;
}
int F_153 ( struct V_49 * V_50 , int V_260 ,
enum V_188 V_221 ,
int V_33 )
{
F_71 ( V_135 ) ;
int V_136 , V_41 ;
V_136 = F_144 ( V_50 , & V_135 , V_260 , 0 , V_33 ) ;
V_41 = F_154 ( V_50 , NULL , & V_135 , V_136 , V_221 ) ;
if ( V_41 == 0 )
return V_136 ;
return 0 ;
}
int F_155 ( struct V_261 * V_262 ,
struct V_134 * V_135 ,
T_4 * V_156 ,
enum V_68 V_51 , T_1 V_95 ,
enum V_188 V_221 ,
void * V_263 )
{
struct V_4 * V_5 ;
int V_136 = 0 ;
F_156 ( V_262 ) ;
F_103 (lock, &res->lr_granted, l_res_link) {
if ( V_263 && V_5 -> V_264 != V_263 ) {
F_13 ( V_5 , L_43 ,
V_5 -> V_264 , V_263 ) ;
continue;
}
if ( V_5 -> V_258 || V_5 -> V_259 )
continue;
if ( F_100 ( V_5 ) || F_146 ( V_5 ) )
continue;
if ( F_157 ( V_5 -> V_54 , V_51 ) )
continue;
if ( V_156 && ( V_5 -> V_60 -> V_61 == V_107 ) &&
! ( V_5 -> V_109 . V_265 . V_266 &
V_156 -> V_265 . V_266 ) )
continue;
V_5 -> V_55 |= V_59 | V_186 |
V_95 ;
F_46 ( F_123 ( & V_5 -> V_147 ) ) ;
F_124 ( & V_5 -> V_147 , V_135 ) ;
F_148 ( V_5 ) ;
V_136 ++ ;
}
F_158 ( V_262 ) ;
return F_126 ( V_135 , V_136 , V_221 ) ;
}
int F_81 ( struct V_134 * V_135 , int V_136 ,
struct V_64 * V_65 ,
enum V_188 V_33 )
{
struct V_4 * V_5 ;
int V_262 = 0 ;
if ( F_123 ( V_135 ) || V_136 == 0 )
return 0 ;
while ( V_136 > 0 ) {
F_46 ( ! F_123 ( V_135 ) ) ;
V_5 = F_159 ( V_135 -> V_225 , struct V_4 ,
V_147 ) ;
F_46 ( V_5 -> V_11 ) ;
if ( F_125 ( V_5 -> V_11 ) ) {
V_262 = V_136 ;
if ( V_65 )
F_102 ( V_65 , V_135 , V_136 ) ;
else
V_262 = F_104 ( V_5 -> V_11 ,
V_135 , V_136 ,
V_33 ) ;
} else {
V_262 = F_104 ( V_5 -> V_11 ,
V_135 , 1 , V_33 ) ;
}
if ( V_262 < 0 ) {
F_112 ( V_262 == - V_209 ? V_16 : V_210 ,
L_44 , V_262 ) ;
V_262 = V_136 ;
}
V_136 -= V_262 ;
F_79 ( V_135 , V_147 , V_262 ) ;
}
F_46 ( V_136 == 0 ) ;
return 0 ;
}
int F_160 ( struct V_49 * V_50 ,
const struct V_154 * V_155 ,
T_4 * V_156 ,
enum V_68 V_51 ,
enum V_188 V_33 ,
void * V_263 )
{
struct V_261 * V_262 ;
F_71 ( V_135 ) ;
int V_136 ;
int V_41 ;
V_262 = F_161 ( V_50 , NULL , V_155 , 0 , 0 ) ;
if ( ! V_262 ) {
F_55 ( V_98 , L_45 , V_155 -> V_267 [ 0 ] ) ;
return 0 ;
}
F_162 ( V_262 ) ;
V_136 = F_155 ( V_262 , & V_135 , V_156 , V_51 ,
0 , V_33 | V_224 , V_263 ) ;
V_41 = F_81 ( & V_135 , V_136 , NULL , V_33 ) ;
if ( V_41 != V_81 )
F_163 ( L_46 V_105 L_47 ,
F_57 ( V_262 ) , V_41 ) ;
F_164 ( V_262 ) ;
F_165 ( V_262 ) ;
return 0 ;
}
static int F_166 ( struct V_268 * V_269 ,
struct V_270 * V_271 ,
struct V_272 * V_273 , void * V_274 )
{
struct V_261 * V_262 = F_167 ( V_269 , V_273 ) ;
struct V_275 * V_276 = V_274 ;
F_160 ( F_168 ( V_262 ) , & V_262 -> V_104 ,
NULL , V_277 ,
V_276 -> V_278 , V_276 -> V_279 ) ;
return 0 ;
}
int F_169 ( struct V_49 * V_50 ,
const struct V_154 * V_155 ,
enum V_188 V_33 , void * V_263 )
{
struct V_275 V_274 = {
. V_278 = V_33 ,
. V_279 = V_263 ,
} ;
if ( ! V_50 )
return V_81 ;
if ( V_155 ) {
return F_160 ( V_50 , V_155 , NULL ,
V_277 , V_33 ,
V_263 ) ;
} else {
F_170 ( V_50 -> V_280 ,
F_166 , & V_274 ) ;
return V_81 ;
}
}
static int F_171 ( struct V_261 * V_262 ,
T_7 V_281 , void * V_282 )
{
struct V_134 * V_283 , * V_225 ;
struct V_4 * V_5 ;
int V_41 = V_284 ;
if ( ! V_262 )
return V_284 ;
F_156 ( V_262 ) ;
F_172 (tmp, next, &res->lr_granted) {
V_5 = F_159 ( V_283 , struct V_4 , V_285 ) ;
if ( V_281 ( V_5 , V_282 ) == V_286 ) {
V_41 = V_286 ;
goto V_195;
}
}
F_172 (tmp, next, &res->lr_waiting) {
V_5 = F_159 ( V_283 , struct V_4 , V_285 ) ;
if ( V_281 ( V_5 , V_282 ) == V_286 ) {
V_41 = V_286 ;
goto V_195;
}
}
V_195:
F_158 ( V_262 ) ;
return V_41 ;
}
static int F_173 ( struct V_4 * V_5 , void * V_282 )
{
struct V_287 * V_288 = V_282 ;
return V_288 -> V_281 ( V_5 , V_288 -> V_282 ) ;
}
static int F_174 ( struct V_268 * V_269 , struct V_270 * V_271 ,
struct V_272 * V_273 , void * V_274 )
{
struct V_261 * V_262 = F_167 ( V_269 , V_273 ) ;
return F_171 ( V_262 , F_173 , V_274 ) ==
V_286 ;
}
static void F_175 ( struct V_49 * V_50 ,
T_7 V_281 , void * V_282 )
{
struct V_287 V_288 = {
. V_281 = V_281 ,
. V_282 = V_282 ,
} ;
F_170 ( V_50 -> V_280 ,
F_174 , & V_288 ) ;
}
int F_176 ( struct V_49 * V_50 ,
const struct V_154 * V_155 ,
T_7 V_281 , void * V_1 )
{
struct V_261 * V_262 ;
int V_41 ;
if ( ! V_50 ) {
F_163 ( L_48 ) ;
F_88 () ;
}
V_262 = F_161 ( V_50 , NULL , V_155 , 0 , 0 ) ;
if ( ! V_262 )
return 0 ;
F_162 ( V_262 ) ;
V_41 = F_171 ( V_262 , V_281 , V_1 ) ;
F_164 ( V_262 ) ;
F_165 ( V_262 ) ;
return V_41 ;
}
static int F_177 ( struct V_4 * V_5 , void * V_282 )
{
struct V_134 * V_289 = V_282 ;
F_47 ( F_123 ( & V_5 -> V_290 ) ,
L_49 ,
V_5 , & V_5 -> V_290 . V_225 ,
& V_5 -> V_290 . V_291 ) ;
if ( ! ( V_5 -> V_55 & ( V_57 | V_186 ) ) ) {
F_124 ( & V_5 -> V_290 , V_289 ) ;
F_148 ( V_5 ) ;
}
return V_284 ;
}
static int F_178 ( const struct V_292 * V_293 ,
struct V_64 * V_65 ,
struct V_294 * V_295 , int V_41 )
{
struct V_4 * V_5 ;
struct V_76 * V_77 ;
struct V_63 * exp ;
F_179 ( & V_65 -> V_203 -> V_296 ) ;
if ( V_41 != V_81 )
goto V_195;
V_77 = F_49 ( & V_65 -> V_84 , & V_85 ) ;
if ( ! V_77 ) {
V_41 = - V_86 ;
goto V_195;
}
V_5 = F_45 ( & V_295 -> V_93 ) ;
if ( ! V_5 ) {
F_163 ( L_50 ,
V_295 -> V_93 . V_99 , V_77 -> V_93 . V_99 ,
V_65 -> V_297 -> V_298 . V_24 ,
F_180 ( V_65 -> V_299 ) ) ;
V_41 = - V_300 ;
goto V_195;
}
exp = V_65 -> V_297 ;
if ( exp && exp -> V_91 ) {
F_53 ( exp -> V_91 ,
& V_5 -> V_92 ,
& V_77 -> V_93 ,
& V_5 -> V_94 ) ;
} else {
V_5 -> V_92 = V_77 -> V_93 ;
}
F_5 ( V_5 , L_51 ) ;
F_181 ( V_65 -> V_203 ) ;
F_62 ( V_5 ) ;
V_195:
if ( V_41 != V_81 )
F_182 ( V_65 -> V_203 ) ;
return V_41 ;
}
static int F_183 ( struct V_7 * V_8 , struct V_4 * V_5 )
{
struct V_64 * V_65 ;
struct V_294 * V_295 ;
struct V_137 * V_159 ;
int V_33 ;
if ( F_146 ( V_5 ) ) {
F_5 ( V_5 , L_52 ) ;
return 0 ;
}
if ( F_184 ( V_5 ) ) {
F_5 ( V_5 , L_53 ) ;
F_101 ( V_5 ) ;
return 0 ;
}
if ( V_5 -> V_54 == V_5 -> V_53 )
V_33 = V_75 | V_36 ;
else if ( V_5 -> V_54 )
V_33 = V_75 | V_37 ;
else if ( ! F_123 ( & V_5 -> V_285 ) )
V_33 = V_75 | V_35 ;
else
V_33 = V_75 ;
V_65 = F_89 ( V_8 , & V_178 ,
V_149 , V_145 ) ;
if ( ! V_65 )
return - V_106 ;
V_65 -> V_301 = V_302 ;
V_159 = F_80 ( & V_65 -> V_84 , & V_146 ) ;
F_91 ( V_5 , & V_159 -> V_102 ) ;
V_159 -> V_95 = F_92 ( V_33 ) ;
F_87 ( V_5 , & V_159 -> V_93 [ 0 ] ) ;
if ( V_5 -> V_80 > 0 )
F_93 ( & V_65 -> V_84 , & V_181 ) ;
F_76 ( & V_65 -> V_84 , & V_88 , V_89 ,
V_5 -> V_80 ) ;
F_94 ( V_65 ) ;
F_185 ( V_65 -> V_303 , V_304 ) ;
F_5 ( V_5 , L_54 ) ;
F_186 ( & V_65 -> V_203 -> V_296 ) ;
F_187 ( sizeof( * V_295 ) <= sizeof( V_65 -> V_305 ) ) ;
V_295 = F_188 ( V_65 ) ;
V_295 -> V_93 = V_159 -> V_93 [ 0 ] ;
V_65 -> V_306 = ( V_307 ) F_178 ;
F_110 ( V_65 ) ;
return 0 ;
}
static void F_189 ( struct V_49 * V_50 )
{
int V_308 ;
F_71 ( V_135 ) ;
F_55 ( V_16 , L_55 ,
F_190 ( V_50 ) , V_50 -> V_250 ) ;
V_308 = F_75 ( V_50 , & V_135 , V_50 -> V_250 , 0 ,
V_222 , V_243 ) ;
F_55 ( V_16 , L_56 ,
V_308 , F_190 ( V_50 ) ) ;
}
int F_191 ( struct V_7 * V_8 )
{
struct V_49 * V_50 = V_8 -> V_212 -> V_73 ;
F_71 ( V_289 ) ;
struct V_4 * V_5 , * V_225 ;
int V_41 = 0 ;
F_46 ( F_192 ( & V_8 -> V_296 ) == 0 ) ;
if ( V_8 -> V_309 )
return 0 ;
F_186 ( & V_8 -> V_296 ) ;
if ( V_310 )
F_189 ( V_50 ) ;
F_175 ( V_50 , F_177 , & V_289 ) ;
F_127 (lock, next, &list, l_pending_chain) {
F_128 ( & V_5 -> V_290 ) ;
if ( V_41 ) {
F_63 ( V_5 ) ;
continue;
}
V_41 = F_183 ( V_8 , V_5 ) ;
F_63 ( V_5 ) ;
}
F_179 ( & V_8 -> V_296 ) ;
return V_41 ;
}
