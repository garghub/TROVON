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
static unsigned int F_15 ( struct V_4 * V_5 )
{
unsigned int V_25 ;
if ( V_26 )
return V_27 ;
V_25 = F_16 ( F_17 ( V_5 ) ) ;
return F_18 ( 3 * V_25 , V_28 ) ;
}
static int F_19 ( struct V_4 * V_5 , void * V_1 )
{
long V_29 ;
int V_30 = 0 ;
if ( F_20 ( V_5 ) || F_21 ( V_5 ) ) {
F_5 ( V_5 , L_4 ) ;
V_30 = - V_31 ;
} else if ( ! V_1 ) {
F_5 ( V_5 , L_5 ) ;
} else {
V_29 = F_4 () - V_5 -> V_15 ;
F_5 ( V_5 , L_6 ,
V_29 ) ;
F_22 ( F_17 ( V_5 ) , V_29 ) ;
}
return V_30 ;
}
int F_23 ( struct V_4 * V_5 , T_1 V_32 , void * V_1 )
{
if ( V_32 == V_33 ) {
F_5 ( V_5 , L_7 ) ;
return 0 ;
}
if ( ! ( V_32 & V_34 ) ) {
F_24 ( & V_5 -> V_35 ) ;
return F_19 ( V_5 , V_1 ) ;
}
F_5 ( V_5 , L_8 ) ;
return 0 ;
}
int F_25 ( struct V_4 * V_5 , T_1 V_32 , void * V_1 )
{
struct V_2 V_3 ;
struct V_9 * V_10 ;
struct V_7 * V_8 = NULL ;
struct V_36 V_37 ;
T_2 V_25 ;
int V_38 = 0 ;
if ( V_32 == V_33 ) {
F_5 ( V_5 , L_7 ) ;
goto V_39;
}
if ( ! ( V_32 & V_34 ) ) {
F_24 ( & V_5 -> V_35 ) ;
return 0 ;
}
F_5 ( V_5 , L_9 ) ;
V_39:
V_10 = F_26 ( V_5 -> V_11 ) ;
if ( V_10 )
V_8 = V_10 -> V_18 . V_19 . V_20 ;
V_25 = F_15 ( V_5 ) ;
V_3 . V_6 = V_5 ;
V_5 -> V_15 = F_4 () ;
if ( F_27 ( V_5 ) ) {
F_5 ( V_5 , L_10 ) ;
V_37 = F_28 ( F_1 , & V_3 ) ;
} else {
V_37 = F_29 ( F_30 ( V_25 ) ,
F_2 ,
F_1 , & V_3 ) ;
}
if ( V_8 ) {
F_31 ( & V_8 -> V_40 ) ;
V_3 . V_21 = V_8 -> V_41 ;
F_32 ( & V_8 -> V_40 ) ;
}
if ( F_33 ( V_42 ,
V_43 | V_44 ) ) {
F_34 ( V_5 ) ;
V_38 = - V_45 ;
} else {
V_38 = F_35 ( V_5 -> V_35 ,
F_36 ( V_5 ) , & V_37 ) ;
}
if ( V_38 ) {
F_5 ( V_5 , L_11 ,
V_38 ) ;
return V_38 ;
}
return F_19 ( V_5 , V_1 ) ;
}
static void F_37 ( struct V_46 * V_47 ,
struct V_4 * V_5 , int V_48 )
{
int V_49 = 0 ;
F_38 ( V_5 ) ;
if ( ( V_5 -> V_50 != V_5 -> V_51 ) &&
! F_21 ( V_5 ) ) {
V_5 -> V_52 |= V_53 | V_54 |
V_55 | V_56 ;
V_49 = 1 ;
}
F_39 ( V_5 ) ;
if ( V_49 )
F_5 ( V_5 ,
L_12 ) ;
else
F_5 ( V_5 , L_13 ) ;
if ( V_5 -> V_57 -> V_58 == V_59 ) {
F_38 ( V_5 ) ;
if ( ! F_20 ( V_5 ) ) {
F_40 ( V_5 ) ;
F_41 ( V_5 , V_48 ) ;
F_42 ( V_5 ) ;
}
F_39 ( V_5 ) ;
} else {
F_43 ( V_5 , V_48 ) ;
}
}
int F_44 ( struct V_60 * exp , struct V_61 * V_62 ,
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
V_5 = F_45 ( V_69 ) ;
if ( ! V_5 ) {
F_46 ( type == V_59 ) ;
return - V_76 ;
}
F_47 ( F_48 ( V_67 != 0 , V_67 == V_5 -> V_77 ) ,
L_14 , V_67 , V_5 -> V_77 ) ;
if ( V_38 != V_78 ) {
F_46 ( ! V_71 ) ;
F_5 ( V_5 , L_15 ,
V_38 == V_79 ? L_16 : L_17 ) ;
if ( V_38 != V_79 )
goto V_80;
}
V_74 = F_49 ( & V_62 -> V_81 , & V_82 ) ;
if ( ! V_74 ) {
V_38 = - V_83 ;
goto V_80;
}
if ( V_67 > 0 ) {
int V_84 = 0 ;
V_84 = F_50 ( & V_62 -> V_81 , & V_85 ,
V_86 ) ;
if ( V_84 < 0 ) {
F_13 ( V_5 , L_18 , V_84 ) ;
V_38 = V_84 ;
goto V_80;
} else if ( F_51 ( V_84 > V_67 ) ) {
F_13 ( V_5 , L_19 ,
V_67 , V_84 ) ;
V_38 = - V_87 ;
goto V_80;
}
V_67 = V_84 ;
}
if ( V_38 == V_79 ) {
if ( V_67 > 0 && V_66 )
V_38 = F_52 ( V_5 , & V_62 -> V_81 , V_86 ,
V_66 , V_67 ) ;
if ( V_38 == 0 )
V_38 = V_79 ;
goto V_80;
}
V_75 = 0 ;
F_38 ( V_5 ) ;
if ( exp -> V_88 ) {
F_53 ( exp -> V_88 ,
& V_5 -> V_89 ,
& V_74 -> V_90 ,
& V_5 -> V_91 ) ;
} else {
V_5 -> V_89 = V_74 -> V_90 ;
}
* V_32 = F_54 ( V_74 -> V_92 ) ;
V_5 -> V_52 |= F_54 ( V_74 -> V_92 &
V_93 ) ;
F_39 ( V_5 ) ;
F_55 ( V_94 , L_20 ,
V_5 , V_74 -> V_90 . V_95 , * V_32 ) ;
if ( ( * V_32 ) & V_96 ) {
int V_97 = V_74 -> V_98 . V_50 ;
F_46 ( ! V_71 ) ;
if ( V_97 && V_97 != V_5 -> V_50 ) {
F_5 ( V_5 , L_21 ,
V_99 [ V_97 ] ) ;
V_5 -> V_50 = V_97 ;
}
if ( ! F_56 ( & V_74 -> V_98 . V_57 . V_100 ,
& V_5 -> V_57 -> V_100 ) ) {
F_55 ( V_94 , L_22 V_101
L_23 V_101 L_24 ,
F_57 ( & V_74 -> V_98 . V_57 ) ,
F_57 ( V_5 -> V_57 ) ) ;
V_38 = F_58 ( V_47 , V_5 ,
& V_74 -> V_98 . V_57 . V_100 ) ;
if ( V_38 || ! V_5 -> V_57 ) {
V_38 = - V_102 ;
goto V_80;
}
F_5 ( V_5 , L_25 ) ;
}
if ( V_64 )
if ( ! ( type == V_103 &&
! ( F_59 ( exp ) & V_104 ) ) )
F_60 ( exp ,
V_5 -> V_57 -> V_58 ,
& V_74 -> V_98 . V_105 ,
& V_5 -> V_105 ) ;
if ( type != V_106 )
F_5 ( V_5 ,
L_26 ) ;
}
if ( ( * V_32 ) & V_107 ||
( V_108 && type == V_109 ) ) {
F_38 ( V_5 ) ;
V_5 -> V_52 |= V_56 | V_110 ;
F_39 ( V_5 ) ;
F_5 ( V_5 , L_27 ) ;
}
if ( V_67 > 0 ) {
F_38 ( V_5 ) ;
if ( V_5 -> V_50 != V_5 -> V_51 )
V_38 = F_52 ( V_5 , & V_62 -> V_81 , V_86 ,
V_5 -> V_111 , V_67 ) ;
F_39 ( V_5 ) ;
if ( V_38 < 0 ) {
V_75 = 1 ;
goto V_80;
}
}
if ( ! V_71 ) {
V_38 = F_61 ( V_47 , & V_5 , NULL , V_32 ) ;
if ( V_5 -> V_112 ) {
int V_113 = V_5 -> V_112 ( V_5 , * V_32 , NULL ) ;
if ( ! V_38 )
V_38 = V_113 ;
if ( V_38 )
V_75 = 1 ;
}
}
if ( V_67 > 0 && V_66 ) {
memcpy ( V_66 , V_5 -> V_111 , V_67 ) ;
}
F_5 ( V_5 , L_28 ) ;
V_80:
if ( V_75 == 1 && V_38 )
F_37 ( V_47 , V_5 , V_48 ) ;
F_62 ( V_5 ) ;
F_63 ( V_5 ) ;
return V_38 ;
}
static inline int F_64 ( int V_114 , int V_115 )
{
int V_116 ;
V_116 = F_65 ( int , V_117 , V_118 - 512 ) - V_114 ;
if ( F_66 ( V_116 >= 0 ) )
V_116 /= ( int ) sizeof( struct V_68 ) ;
else
V_116 = 0 ;
V_116 += V_119 - V_115 ;
return V_116 ;
}
static inline int F_67 ( struct V_120 * V_121 ,
enum V_122 V_123 ,
int V_115 )
{
T_4 V_84 = F_68 ( V_121 , V_123 ) ;
return F_64 ( V_84 , V_115 ) ;
}
static inline int F_69 ( struct V_7 * V_8 ,
const struct V_124 * V_125 ,
enum V_122 V_123 , int V_115 )
{
T_4 V_84 = F_70 ( V_8 -> V_126 , V_125 , V_123 ) ;
return F_64 ( V_84 , V_115 ) ;
}
int F_71 ( struct V_60 * exp , struct V_61 * V_62 ,
int V_127 , int V_128 , int V_129 ,
struct V_130 * V_131 , int V_132 )
{
struct V_46 * V_47 = exp -> V_17 -> V_70 ;
struct V_120 * V_121 = & V_62 -> V_81 ;
struct V_133 * V_134 = NULL ;
int V_32 , V_116 , V_135 , V_136 = 0 ;
F_72 ( V_137 ) ;
int V_38 ;
if ( ! V_131 )
V_131 = & V_137 ;
if ( F_73 ( V_47 ) ) {
F_74 ( V_121 , V_138 ) ;
V_116 = F_67 ( V_121 , V_138 , V_129 ) ;
V_32 = F_75 ( V_47 ) ?
V_139 : V_140 ;
V_135 = ! F_75 ( V_47 ) &&
V_128 == V_141 ? 1 : 0 ;
if ( V_116 > V_132 )
V_132 += F_76 ( V_47 , V_131 , V_135 ,
V_116 - V_132 , 0 , V_32 ) ;
if ( V_116 > V_132 )
V_136 = V_132 ;
else
V_136 = V_116 ;
F_77 ( V_121 , & V_142 , V_138 ,
F_78 ( V_136 , V_128 ) ) ;
}
V_38 = F_79 ( V_62 , V_127 , V_128 ) ;
if ( V_38 ) {
F_80 ( V_131 , V_143 , V_132 ) ;
return V_38 ;
}
if ( F_73 ( V_47 ) ) {
if ( V_129 ) {
V_134 = F_81 ( V_121 , & V_142 ) ;
F_46 ( V_134 ) ;
V_134 -> V_144 = V_129 ;
}
F_82 ( V_131 , V_136 , V_62 , 0 ) ;
F_82 ( V_131 , V_132 - V_136 , NULL , 0 ) ;
} else {
F_80 ( V_131 , V_143 , V_132 ) ;
}
return 0 ;
}
int F_83 ( struct V_60 * exp , struct V_61 * V_62 ,
struct V_130 * V_131 , int V_132 )
{
return F_71 ( exp , V_62 , V_145 , V_141 ,
V_146 , V_131 , V_132 ) ;
}
int F_84 ( struct V_60 * exp , struct V_61 * * V_147 ,
struct V_148 * V_149 ,
const struct V_150 * V_151 ,
T_5 const * V_152 , T_1 * V_32 ,
void * V_66 , T_2 V_67 , enum V_153 V_153 ,
struct V_68 * V_69 , int V_154 )
{
struct V_46 * V_47 ;
struct V_4 * V_5 ;
struct V_133 * V_155 ;
int V_71 = * V_32 & V_72 ;
int V_156 = 1 ;
int V_38 , V_113 ;
struct V_61 * V_62 ;
V_47 = exp -> V_17 -> V_70 ;
if ( V_71 ) {
V_5 = F_85 ( V_69 , 0 ) ;
F_46 ( V_5 ) ;
F_5 ( V_5 , L_29 ) ;
F_46 ( exp == V_5 -> V_11 ) ;
} else {
const struct V_157 V_158 = {
. V_159 = V_149 -> V_160 ,
. V_161 = V_149 -> V_162 ,
. V_163 = V_149 -> V_164
} ;
V_5 = F_86 ( V_47 , V_151 , V_149 -> V_165 ,
V_149 -> V_166 , & V_158 , V_149 -> V_167 ,
V_67 , V_153 ) ;
if ( F_87 ( V_5 ) )
return F_88 ( V_5 ) ;
F_89 ( V_5 , V_149 -> V_166 ) ;
F_90 ( V_5 , V_69 ) ;
if ( V_152 )
V_5 -> V_105 = * V_152 ;
if ( V_149 -> V_165 == V_109 ) {
if ( ! V_152 )
F_91 () ;
V_5 -> V_168 = V_152 -> V_169 ;
}
F_5 ( V_5 , L_30 ,
* V_32 ) ;
}
V_5 -> V_11 = exp ;
V_5 -> V_170 = NULL ;
V_5 -> V_171 = V_149 -> V_162 ;
V_5 -> V_52 |= ( * V_32 & ( V_172 | V_173 ) ) ;
V_5 -> V_15 = F_4 () ;
if ( ! V_147 || ! * V_147 ) {
V_62 = F_92 ( F_93 ( exp ) ,
& V_174 ,
V_145 ,
V_141 ) ;
if ( ! V_62 ) {
F_37 ( V_47 , V_5 , V_149 -> V_166 ) ;
F_63 ( V_5 ) ;
return - V_102 ;
}
V_156 = 0 ;
if ( V_147 )
* V_147 = V_62 ;
} else {
int V_175 ;
V_62 = * V_147 ;
V_175 = F_50 ( & V_62 -> V_81 , & V_142 ,
V_138 ) ;
F_47 ( V_175 >= sizeof( * V_155 ) , L_31 ,
V_176 , V_175 , ( int ) sizeof( * V_155 ) ) ;
}
V_155 = F_81 ( & V_62 -> V_81 , & V_142 ) ;
F_94 ( V_5 , & V_155 -> V_98 ) ;
V_155 -> V_92 = F_95 ( * V_32 ) ;
V_155 -> V_90 [ 0 ] = * V_69 ;
if ( ! V_156 ) {
if ( V_67 > 0 )
F_96 ( & V_62 -> V_81 ,
& V_177 ) ;
F_77 ( & V_62 -> V_81 , & V_85 , V_86 ,
V_67 ) ;
F_97 ( V_62 ) ;
}
F_46 ( F_48 ( V_108 , V_149 -> V_165 != V_109 ||
V_152 -> V_169 . V_178 == V_179 ) ) ;
if ( V_154 ) {
F_46 ( V_147 ) ;
return 0 ;
}
F_5 ( V_5 , L_32 ) ;
V_38 = F_98 ( V_62 ) ;
V_113 = F_44 ( exp , V_62 , V_149 -> V_165 , V_152 ? 1 : 0 ,
V_149 -> V_166 , V_32 , V_66 , V_67 ,
V_69 , V_38 ) ;
if ( V_113 == - V_76 )
F_63 ( V_5 ) ;
else
V_38 = V_113 ;
if ( ! V_156 && V_62 ) {
F_99 ( V_62 ) ;
if ( V_147 )
* V_147 = NULL ;
}
return V_38 ;
}
static T_1 F_100 ( struct V_4 * V_5 )
{
T_1 V_38 = V_53 ;
if ( V_5 -> V_11 ) {
bool V_180 ;
F_5 ( V_5 , L_33 ) ;
F_38 ( V_5 ) ;
F_101 ( V_5 ) ;
V_180 = ! ! ( V_5 -> V_52 &
( V_53 | V_181 ) ) ;
F_102 ( V_5 ) ;
V_38 = F_103 ( V_5 ) ? V_110 : V_182 ;
F_39 ( V_5 ) ;
if ( V_180 ) {
F_55 ( V_16 , L_34 ) ;
V_38 = V_53 ;
}
F_104 ( V_5 ) ;
} else {
F_13 ( V_5 , L_35 ) ;
F_91 () ;
}
return V_38 ;
}
static void F_105 ( struct V_61 * V_62 ,
struct V_130 * V_137 , int V_132 )
{
struct V_133 * V_134 ;
struct V_4 * V_5 ;
int F_18 , V_183 = 0 ;
V_134 = F_81 ( & V_62 -> V_81 , & V_142 ) ;
F_46 ( V_134 ) ;
F_18 = F_50 ( & V_62 -> V_81 , & V_142 , V_138 ) -
sizeof( struct V_133 ) ;
F_18 /= sizeof( struct V_68 ) ;
F_18 += V_119 ;
F_46 ( F_18 >= V_134 -> V_144 + V_132 ) ;
F_106 (lock, head, l_bl_ast) {
if ( ! V_132 -- )
break;
F_46 ( V_5 -> V_11 ) ;
F_5 ( V_5 , L_36 ) ;
V_134 -> V_90 [ V_134 -> V_144 ++ ] = V_5 -> V_89 ;
V_183 ++ ;
}
F_55 ( V_16 , L_37 , V_183 ) ;
}
static int F_107 ( struct V_60 * exp ,
struct V_130 * V_131 ,
int V_132 , enum V_184 V_32 )
{
struct V_61 * V_62 = NULL ;
struct V_7 * V_8 ;
int free , V_185 = 0 ;
int V_38 = 0 ;
F_46 ( exp ) ;
F_46 ( V_132 > 0 ) ;
F_108 ( V_186 , V_187 ) ;
if ( F_109 ( V_188 ) )
return V_132 ;
free = F_69 ( F_93 ( exp ) ,
& V_189 , V_138 , 0 ) ;
if ( V_132 > free )
V_132 = free ;
while ( 1 ) {
V_8 = F_93 ( exp ) ;
if ( ! V_8 || V_8 -> V_190 ) {
F_55 ( V_16 ,
L_38 , V_8 ) ;
return V_132 ;
}
V_62 = F_110 ( V_8 , & V_189 ) ;
if ( ! V_62 ) {
V_38 = - V_102 ;
goto V_191;
}
F_74 ( & V_62 -> V_81 , V_138 ) ;
F_77 ( & V_62 -> V_81 , & V_142 , V_138 ,
F_78 ( V_132 , V_192 ) ) ;
V_38 = F_79 ( V_62 , V_145 , V_192 ) ;
if ( V_38 ) {
F_111 ( V_62 ) ;
goto V_191;
}
V_62 -> V_193 = V_194 ;
V_62 -> V_195 = V_196 ;
F_112 ( V_62 ) ;
F_105 ( V_62 , V_131 , V_132 ) ;
F_97 ( V_62 ) ;
if ( V_32 & V_197 ) {
F_113 ( V_62 ) ;
V_185 = V_132 ;
goto V_191;
}
V_38 = F_98 ( V_62 ) ;
if ( V_38 == V_198 ) {
F_55 ( V_16 , L_39 ,
F_114 ( V_62 -> V_199 ->
V_22 -> V_200 . V_201 ) ) ;
V_38 = 0 ;
} else if ( V_38 == - V_202 &&
V_62 -> V_203 == V_8 -> V_204 ) {
F_99 ( V_62 ) ;
continue;
} else if ( V_38 != V_78 ) {
F_115 ( V_38 == - V_205 ? V_16 : V_206 ,
L_40 ,
V_38 ) ;
break;
}
V_185 = V_132 ;
break;
}
F_99 ( V_62 ) ;
V_191:
return V_185 ? V_185 : V_38 ;
}
static inline struct V_207 * F_116 ( struct V_7 * V_8 )
{
return & V_8 -> V_208 -> V_70 -> V_209 ;
}
int F_117 ( struct V_61 * V_62 )
{
struct V_9 * V_10 ;
T_1 V_210 ;
T_2 V_211 ;
if ( F_51 ( ! V_62 -> V_199 || ! V_62 -> V_199 -> V_208 ||
! F_118 ( V_62 -> V_199 ) ) ) {
return 0 ;
}
if ( F_119 ( V_62 -> V_212 ) == 0 ||
F_120 ( V_62 -> V_212 ) == 0 ) {
F_121 ( V_213 , V_62 ,
L_41 ,
F_119 ( V_62 -> V_212 ) ,
F_120 ( V_62 -> V_212 ) ) ;
return 0 ;
}
V_211 = F_120 ( V_62 -> V_212 ) ;
V_210 = F_119 ( V_62 -> V_212 ) ;
V_10 = V_62 -> V_199 -> V_208 ;
F_122 ( & V_10 -> V_214 ) ;
V_10 -> V_215 = V_210 ;
V_10 -> V_216 = V_211 ;
F_123 ( & V_10 -> V_214 ) ;
return 0 ;
}
int F_124 ( const struct V_68 * V_69 ,
enum V_184 V_217 )
{
struct V_60 * exp ;
int V_116 , V_32 , V_132 = 1 ;
T_1 V_38 = 0 ;
struct V_46 * V_47 ;
struct V_4 * V_5 ;
F_72 ( V_131 ) ;
V_5 = F_85 ( V_69 , V_182 ) ;
if ( ! V_5 ) {
F_125 ( L_42 ) ;
return 0 ;
}
V_38 = F_100 ( V_5 ) ;
if ( V_38 == V_53 || V_217 & V_218 ) {
F_63 ( V_5 ) ;
return 0 ;
}
F_46 ( F_126 ( & V_5 -> V_143 ) ) ;
F_127 ( & V_5 -> V_143 , & V_131 ) ;
exp = V_5 -> V_11 ;
if ( F_128 ( exp ) ) {
V_116 = F_69 ( F_93 ( exp ) ,
& V_189 ,
V_138 , 0 ) ;
F_46 ( V_116 > 0 ) ;
V_47 = F_10 ( V_5 ) ;
V_32 = F_75 ( V_47 ) ?
V_219 : V_140 ;
V_132 += F_76 ( V_47 , & V_131 , 0 , V_116 - 1 ,
V_220 , V_32 ) ;
}
F_82 ( & V_131 , V_132 , NULL , V_217 ) ;
return 0 ;
}
int F_129 ( struct V_130 * V_131 , int V_132 ,
enum V_184 V_32 )
{
F_72 ( V_137 ) ;
struct V_4 * V_5 , * V_221 ;
int V_222 = 0 , V_223 = 0 ;
T_1 V_38 ;
V_222 = V_132 ;
F_130 (lock, next, cancels, l_bl_ast) {
if ( V_222 -- == 0 )
break;
if ( V_32 & V_218 ) {
V_38 = V_53 ;
F_104 ( V_5 ) ;
} else {
V_38 = F_100 ( V_5 ) ;
}
if ( ! ( V_32 & V_220 ) && ( V_38 == V_110 ) ) {
F_5 ( V_5 , L_43 ) ;
F_131 ( & V_5 -> V_143 ) ;
F_127 ( & V_5 -> V_143 , & V_137 ) ;
V_223 ++ ;
continue;
}
if ( V_38 == V_53 ) {
F_131 ( & V_5 -> V_143 ) ;
F_63 ( V_5 ) ;
V_132 -- ;
}
}
if ( V_223 > 0 ) {
V_132 -= V_223 ;
F_82 ( & V_137 , V_223 , NULL , 0 ) ;
}
return V_132 ;
}
static enum V_224
F_132 ( struct V_46 * V_47 , struct V_4 * V_5 ,
int V_225 , int V_226 , int V_132 )
{
enum V_224 V_30 = V_227 ;
switch ( V_5 -> V_57 -> V_58 ) {
case V_109 :
case V_103 :
if ( V_47 -> V_228 && V_47 -> V_228 ( V_5 ) != 0 )
break;
default:
V_30 = V_229 ;
F_38 ( V_5 ) ;
F_133 ( V_5 ) ;
F_39 ( V_5 ) ;
break;
}
return V_30 ;
}
static enum V_224 F_134 ( struct V_46 * V_47 ,
struct V_4 * V_5 ,
int V_225 , int V_226 ,
int V_132 )
{
unsigned long V_230 = F_7 () ;
struct V_207 * V_231 = & V_47 -> V_209 ;
T_1 V_232 , V_233 , V_234 ;
unsigned long V_235 ;
if ( V_132 && V_226 >= V_132 )
return V_236 ;
V_232 = F_135 ( V_231 ) ;
V_233 = F_136 ( V_231 ) ;
V_235 = F_137 ( F_138 ( V_230 , V_5 -> V_237 ) ) ;
V_234 = V_233 * V_235 * V_225 ;
F_139 ( V_231 , V_234 ) ;
if ( V_232 == 0 || V_234 < V_232 )
return V_236 ;
return V_227 ;
}
static enum V_224 F_140 ( struct V_46 * V_47 ,
struct V_4 * V_5 ,
int V_225 , int V_226 ,
int V_132 )
{
return ( V_226 >= V_132 ) ?
V_236 : V_227 ;
}
static enum V_224 F_141 ( struct V_46 * V_47 ,
struct V_4 * V_5 ,
int V_225 , int V_226 ,
int V_132 )
{
if ( ( V_226 >= V_132 ) &&
F_142 ( F_7 () ,
F_143 ( V_5 -> V_237 , V_47 -> V_238 ) ) )
return V_236 ;
return V_227 ;
}
static enum V_224
F_144 ( struct V_46 * V_47 ,
struct V_4 * V_5 ,
int V_225 , int V_226 ,
int V_132 )
{
enum V_224 V_30 ;
V_30 = F_134 ( V_47 , V_5 , V_225 , V_226 , V_132 ) ;
if ( V_30 == V_236 )
return V_30 ;
return F_132 ( V_47 , V_5 , V_225 , V_226 , V_132 ) ;
}
static enum V_224
F_145 ( struct V_46 * V_47 , struct V_4 * V_5 ,
int V_225 , int V_226 , int V_132 )
{
return ( V_226 >= V_132 ) ?
V_236 : V_227 ;
}
static T_6
F_146 ( struct V_46 * V_47 , int V_32 )
{
if ( V_32 & V_239 )
return F_132 ;
if ( F_75 ( V_47 ) ) {
if ( V_32 & V_240 )
return F_140 ;
else if ( V_32 & V_219 )
return F_134 ;
else if ( V_32 & V_241 )
return F_140 ;
else if ( V_32 & V_139 )
return F_144 ;
} else {
if ( V_32 & V_140 )
return F_141 ;
}
return F_145 ;
}
static int F_147 ( struct V_46 * V_47 ,
struct V_130 * V_131 , int V_132 , int F_18 ,
int V_32 )
{
T_6 V_242 ;
struct V_4 * V_5 , * V_221 ;
int V_226 = 0 , V_225 , V_243 ;
int V_244 = V_32 & ( V_239 | V_139 ) ;
F_31 ( & V_47 -> V_245 ) ;
V_225 = V_47 -> V_246 ;
V_243 = V_225 ;
if ( ! F_75 ( V_47 ) )
V_132 += V_225 - V_47 -> V_247 ;
V_242 = F_146 ( V_47 , V_32 ) ;
F_46 ( V_242 ) ;
while ( ! F_126 ( & V_47 -> V_248 ) ) {
enum V_224 V_30 ;
T_7 V_249 = 0 ;
if ( V_243 -- <= 0 )
break;
if ( F_18 && V_226 >= F_18 )
break;
F_130 (lock, next, &ns->ns_unused_list,
l_lru) {
F_46 ( ! F_103 ( V_5 ) ) ;
if ( V_244 && F_148 ( V_5 ) )
continue;
V_249 = V_5 -> V_237 ;
if ( V_249 == F_7 () )
continue;
if ( ! F_149 ( V_5 ) )
break;
F_150 ( V_5 ) ;
}
if ( & V_5 -> V_250 == & V_47 -> V_248 )
break;
F_151 ( V_5 ) ;
F_32 ( & V_47 -> V_245 ) ;
F_152 ( & V_5 -> V_251 , V_252 , V_253 ) ;
V_30 = V_242 ( V_47 , V_5 , V_225 , V_226 , V_132 ) ;
if ( V_30 == V_236 ) {
F_153 ( & V_5 -> V_251 ,
V_252 , V_253 ) ;
F_63 ( V_5 ) ;
F_31 ( & V_47 -> V_245 ) ;
break;
}
if ( V_30 == V_229 ) {
F_153 ( & V_5 -> V_251 ,
V_252 , V_253 ) ;
F_63 ( V_5 ) ;
F_31 ( & V_47 -> V_245 ) ;
continue;
}
F_38 ( V_5 ) ;
if ( F_149 ( V_5 ) ||
( F_154 ( V_5 , V_249 ) == 0 ) ) {
F_39 ( V_5 ) ;
F_153 ( & V_5 -> V_251 ,
V_252 , V_253 ) ;
F_63 ( V_5 ) ;
F_31 ( & V_47 -> V_245 ) ;
continue;
}
F_46 ( ! V_5 -> V_254 && ! V_5 -> V_255 ) ;
F_155 ( V_5 ) ;
V_5 -> V_52 |= V_56 | V_182 ;
F_46 ( F_126 ( & V_5 -> V_143 ) ) ;
F_127 ( & V_5 -> V_143 , V_131 ) ;
F_39 ( V_5 ) ;
F_153 ( & V_5 -> V_251 , V_252 , V_253 ) ;
F_31 ( & V_47 -> V_245 ) ;
V_226 ++ ;
V_225 -- ;
}
F_32 ( & V_47 -> V_245 ) ;
return V_226 ;
}
int F_76 ( struct V_46 * V_47 ,
struct V_130 * V_131 , int V_132 , int F_18 ,
enum V_184 V_217 , int V_32 )
{
int V_226 ;
V_226 = F_147 ( V_47 , V_131 , V_132 , F_18 , V_32 ) ;
if ( V_226 <= 0 )
return V_226 ;
return F_129 ( V_131 , V_226 , V_217 ) ;
}
int F_156 ( struct V_46 * V_47 , int V_256 ,
enum V_184 V_217 ,
int V_32 )
{
F_72 ( V_131 ) ;
int V_132 , V_38 ;
V_132 = F_147 ( V_47 , & V_131 , V_256 , 0 , V_32 ) ;
V_38 = F_157 ( V_47 , NULL , & V_131 , V_132 , V_217 ) ;
if ( V_38 == 0 )
return V_132 ;
return 0 ;
}
int F_158 ( struct V_257 * V_258 ,
struct V_130 * V_131 ,
T_5 * V_152 ,
enum V_65 V_48 , T_1 V_92 ,
enum V_184 V_217 ,
void * V_259 )
{
struct V_4 * V_5 ;
int V_132 = 0 ;
F_159 ( V_258 ) ;
F_106 (lock, &res->lr_granted, l_res_link) {
if ( V_259 && V_5 -> V_260 != V_259 ) {
F_13 ( V_5 , L_44 ,
V_5 -> V_260 , V_259 ) ;
continue;
}
if ( V_5 -> V_254 || V_5 -> V_255 )
continue;
if ( F_103 ( V_5 ) || F_149 ( V_5 ) )
continue;
if ( F_160 ( V_5 -> V_51 , V_48 ) )
continue;
if ( V_152 && ( V_5 -> V_57 -> V_58 == V_103 ) &&
! ( V_5 -> V_105 . V_261 . V_262 &
V_152 -> V_261 . V_262 ) )
continue;
V_5 -> V_52 |= V_56 | V_182 |
V_92 ;
F_46 ( F_126 ( & V_5 -> V_143 ) ) ;
F_127 ( & V_5 -> V_143 , V_131 ) ;
F_151 ( V_5 ) ;
V_132 ++ ;
}
F_161 ( V_258 ) ;
return F_129 ( V_131 , V_132 , V_217 ) ;
}
int F_82 ( struct V_130 * V_131 , int V_132 ,
struct V_61 * V_62 ,
enum V_184 V_32 )
{
struct V_4 * V_5 ;
int V_258 = 0 ;
if ( F_126 ( V_131 ) || V_132 == 0 )
return 0 ;
while ( V_132 > 0 ) {
F_46 ( ! F_126 ( V_131 ) ) ;
V_5 = F_162 ( V_131 -> V_221 , struct V_4 , V_143 ) ;
F_46 ( V_5 -> V_11 ) ;
if ( F_128 ( V_5 -> V_11 ) ) {
V_258 = V_132 ;
if ( V_62 )
F_105 ( V_62 , V_131 , V_132 ) ;
else
V_258 = F_107 ( V_5 -> V_11 ,
V_131 , V_132 ,
V_32 ) ;
} else {
V_258 = F_107 ( V_5 -> V_11 ,
V_131 , 1 , V_32 ) ;
}
if ( V_258 < 0 ) {
F_115 ( V_258 == - V_205 ? V_16 : V_206 ,
L_45 , V_258 ) ;
V_258 = V_132 ;
}
V_132 -= V_258 ;
F_80 ( V_131 , V_143 , V_258 ) ;
}
F_46 ( V_132 == 0 ) ;
return 0 ;
}
int F_163 ( struct V_46 * V_47 ,
const struct V_150 * V_151 ,
T_5 * V_152 ,
enum V_65 V_48 ,
enum V_184 V_32 ,
void * V_259 )
{
struct V_257 * V_258 ;
F_72 ( V_131 ) ;
int V_132 ;
int V_38 ;
V_258 = F_164 ( V_47 , NULL , V_151 , 0 , 0 ) ;
if ( F_87 ( V_258 ) ) {
F_55 ( V_94 , L_46 , V_151 -> V_263 [ 0 ] ) ;
return 0 ;
}
F_165 ( V_258 ) ;
V_132 = F_158 ( V_258 , & V_131 , V_152 , V_48 ,
0 , V_32 | V_220 , V_259 ) ;
V_38 = F_82 ( & V_131 , V_132 , NULL , V_32 ) ;
if ( V_38 != V_78 )
F_166 ( L_47 V_101 L_48 ,
F_57 ( V_258 ) , V_38 ) ;
F_167 ( V_258 ) ;
F_168 ( V_258 ) ;
return 0 ;
}
static int F_169 ( struct V_264 * V_265 ,
struct V_266 * V_267 ,
struct V_268 * V_269 , void * V_270 )
{
struct V_257 * V_258 = F_170 ( V_265 , V_269 ) ;
struct V_271 * V_272 = V_270 ;
F_163 ( F_171 ( V_258 ) , & V_258 -> V_100 ,
NULL , V_273 ,
V_272 -> V_274 , V_272 -> V_275 ) ;
return 0 ;
}
int F_172 ( struct V_46 * V_47 ,
const struct V_150 * V_151 ,
enum V_184 V_32 , void * V_259 )
{
struct V_271 V_270 = {
. V_274 = V_32 ,
. V_275 = V_259 ,
} ;
if ( ! V_47 )
return V_78 ;
if ( V_151 ) {
return F_163 ( V_47 , V_151 , NULL ,
V_273 , V_32 ,
V_259 ) ;
} else {
F_173 ( V_47 -> V_276 ,
F_169 , & V_270 ) ;
return V_78 ;
}
}
static int F_174 ( struct V_257 * V_258 ,
T_8 V_277 , void * V_278 )
{
struct V_130 * V_279 , * V_221 ;
struct V_4 * V_5 ;
int V_38 = V_280 ;
if ( ! V_258 )
return V_280 ;
F_159 ( V_258 ) ;
F_175 (tmp, next, &res->lr_granted) {
V_5 = F_162 ( V_279 , struct V_4 , V_281 ) ;
if ( V_277 ( V_5 , V_278 ) == V_282 ) {
V_38 = V_282 ;
goto V_191;
}
}
F_175 (tmp, next, &res->lr_waiting) {
V_5 = F_162 ( V_279 , struct V_4 , V_281 ) ;
if ( V_277 ( V_5 , V_278 ) == V_282 ) {
V_38 = V_282 ;
goto V_191;
}
}
V_191:
F_161 ( V_258 ) ;
return V_38 ;
}
static int F_176 ( struct V_4 * V_5 , void * V_278 )
{
struct V_283 * V_284 = V_278 ;
return V_284 -> V_277 ( V_5 , V_284 -> V_278 ) ;
}
static int F_177 ( struct V_264 * V_265 , struct V_266 * V_267 ,
struct V_268 * V_269 , void * V_270 )
{
struct V_257 * V_258 = F_170 ( V_265 , V_269 ) ;
return F_174 ( V_258 , F_176 , V_270 ) ==
V_282 ;
}
static void F_178 ( struct V_46 * V_47 ,
T_8 V_277 , void * V_278 )
{
struct V_283 V_284 = {
. V_277 = V_277 ,
. V_278 = V_278 ,
} ;
F_173 ( V_47 -> V_276 ,
F_177 , & V_284 ) ;
}
int F_179 ( struct V_46 * V_47 ,
const struct V_150 * V_151 ,
T_8 V_277 , void * V_1 )
{
struct V_257 * V_258 ;
int V_38 ;
F_47 ( V_47 , L_49 ) ;
V_258 = F_164 ( V_47 , NULL , V_151 , 0 , 0 ) ;
if ( F_87 ( V_258 ) )
return 0 ;
F_165 ( V_258 ) ;
V_38 = F_174 ( V_258 , V_277 , V_1 ) ;
F_167 ( V_258 ) ;
F_168 ( V_258 ) ;
return V_38 ;
}
static int F_180 ( struct V_4 * V_5 , void * V_278 )
{
struct V_130 * V_285 = V_278 ;
F_47 ( F_126 ( & V_5 -> V_286 ) ,
L_50 ,
V_5 , & V_5 -> V_286 . V_221 ,
& V_5 -> V_286 . V_287 ) ;
if ( ! ( V_5 -> V_52 & ( V_54 | V_182 ) ) ) {
F_127 ( & V_5 -> V_286 , V_285 ) ;
F_151 ( V_5 ) ;
}
return V_280 ;
}
static int F_181 ( const struct V_288 * V_289 ,
struct V_61 * V_62 ,
struct V_290 * V_291 , int V_38 )
{
struct V_4 * V_5 ;
struct V_73 * V_74 ;
struct V_60 * exp ;
F_182 ( & V_62 -> V_199 -> V_292 ) ;
if ( V_38 != V_78 )
goto V_191;
V_74 = F_49 ( & V_62 -> V_81 , & V_82 ) ;
if ( ! V_74 ) {
V_38 = - V_83 ;
goto V_191;
}
V_5 = F_45 ( & V_291 -> V_90 ) ;
if ( ! V_5 ) {
F_166 ( L_51 ,
V_291 -> V_90 . V_95 , V_74 -> V_90 . V_95 ,
V_62 -> V_293 -> V_294 . V_24 ,
F_183 ( V_62 -> V_295 ) ) ;
V_38 = - V_296 ;
goto V_191;
}
exp = V_62 -> V_293 ;
if ( exp && exp -> V_88 ) {
F_53 ( exp -> V_88 ,
& V_5 -> V_89 ,
& V_74 -> V_90 ,
& V_5 -> V_91 ) ;
} else {
V_5 -> V_89 = V_74 -> V_90 ;
}
F_5 ( V_5 , L_52 ) ;
F_184 ( V_62 -> V_199 ) ;
F_62 ( V_5 ) ;
V_191:
if ( V_38 != V_78 )
F_185 ( V_62 -> V_199 ) ;
return V_38 ;
}
static int F_186 ( struct V_7 * V_8 , struct V_4 * V_5 )
{
struct V_61 * V_62 ;
struct V_290 * V_291 ;
struct V_133 * V_155 ;
int V_32 ;
if ( F_149 ( V_5 ) ) {
F_5 ( V_5 , L_53 ) ;
return 0 ;
}
if ( F_187 ( V_5 ) ) {
F_5 ( V_5 , L_54 ) ;
F_104 ( V_5 ) ;
return 0 ;
}
if ( V_5 -> V_51 == V_5 -> V_50 )
V_32 = V_72 | V_297 ;
else if ( V_5 -> V_51 )
V_32 = V_72 | V_298 ;
else if ( ! F_126 ( & V_5 -> V_281 ) )
V_32 = V_72 | V_299 ;
else
V_32 = V_72 ;
V_62 = F_92 ( V_8 , & V_174 ,
V_145 , V_141 ) ;
if ( ! V_62 )
return - V_102 ;
V_62 -> V_300 = V_301 ;
V_155 = F_81 ( & V_62 -> V_81 , & V_142 ) ;
F_94 ( V_5 , & V_155 -> V_98 ) ;
V_155 -> V_92 = F_95 ( V_32 ) ;
F_90 ( V_5 , & V_155 -> V_90 [ 0 ] ) ;
if ( V_5 -> V_77 > 0 )
F_96 ( & V_62 -> V_81 , & V_177 ) ;
F_77 ( & V_62 -> V_81 , & V_85 , V_86 ,
V_5 -> V_77 ) ;
F_97 ( V_62 ) ;
F_188 ( V_62 -> V_302 , V_303 ) ;
F_5 ( V_5 , L_55 ) ;
F_189 ( & V_62 -> V_199 -> V_292 ) ;
F_190 ( sizeof( * V_291 ) <= sizeof( V_62 -> V_304 ) ) ;
V_291 = F_191 ( V_62 ) ;
V_291 -> V_90 = V_155 -> V_90 [ 0 ] ;
V_62 -> V_305 = ( V_306 ) F_181 ;
F_113 ( V_62 ) ;
return 0 ;
}
static void F_192 ( struct V_46 * V_47 )
{
int V_307 ;
F_72 ( V_131 ) ;
F_55 ( V_16 , L_56 ,
F_193 ( V_47 ) , V_47 -> V_246 ) ;
V_307 = F_76 ( V_47 , & V_131 , V_47 -> V_246 , 0 ,
V_218 , V_239 ) ;
F_55 ( V_16 , L_57 ,
V_307 , F_193 ( V_47 ) ) ;
}
int F_194 ( struct V_7 * V_8 )
{
struct V_46 * V_47 = V_8 -> V_208 -> V_70 ;
F_72 ( V_285 ) ;
struct V_4 * V_5 , * V_221 ;
int V_38 = 0 ;
F_46 ( F_195 ( & V_8 -> V_292 ) == 0 ) ;
if ( V_8 -> V_308 )
return 0 ;
F_189 ( & V_8 -> V_292 ) ;
if ( V_309 )
F_192 ( V_47 ) ;
F_178 ( V_47 , F_180 , & V_285 ) ;
F_130 (lock, next, &list, l_pending_chain) {
F_131 ( & V_5 -> V_286 ) ;
if ( V_38 ) {
F_63 ( V_5 ) ;
continue;
}
V_38 = F_186 ( V_8 , V_5 ) ;
F_63 ( V_5 ) ;
}
F_182 ( & V_8 -> V_292 ) ;
return V_38 ;
}
