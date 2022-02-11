int F_1 ( int V_1 , struct V_2 * V_3 )
{
if ( F_2 ( V_3 , V_4 ) ) {
if ( V_1 >= V_4 )
return V_3 -> V_5 ;
else
return 0 ;
}
if ( F_2 ( V_3 , V_6 ) ) {
if ( V_1 >= V_6 )
return V_3 -> V_5 ;
else
return 0 ;
}
if ( F_2 ( V_3 , V_7 ) ) {
if ( V_1 >= V_7 )
return V_3 -> V_5 ;
else
return 0 ;
}
if ( F_2 ( V_3 , V_8 ) ) {
if ( V_1 >= V_8 )
return V_3 -> V_5 ;
else
return 0 ;
}
if ( F_2 ( V_3 , V_9 ) ) {
if ( V_1 >= V_9 )
return V_3 -> V_5 ;
else
return 0 ;
}
F_3 ( L_1 , V_3 -> F_2 ,
V_3 -> V_5 ) ;
F_4 () ;
return 0 ;
}
int F_5 ( struct V_10 * exp , const struct V_11 * V_12 ,
void * V_13 , T_1 * V_14 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 = V_13 ;
if ( V_14 )
* V_14 = 0 ;
if ( ! F_6 ( V_12 ) )
return 0 ;
V_16 = F_7 ( V_12 ) ;
F_8 ( V_16 ) ;
F_9 ( V_16 ) ;
if ( V_16 -> V_19 -> V_20 &&
V_16 -> V_19 -> V_20 != V_13 ) {
struct V_17 * V_21 = V_16 -> V_19 -> V_20 ;
F_10 ( V_21 -> V_22 & V_23 ,
L_2 ,
V_21 , V_21 -> V_24 , V_21 -> V_25 ,
V_21 -> V_22 , V_18 , V_18 -> V_24 ,
V_18 -> V_25 ) ;
}
V_16 -> V_19 -> V_20 = V_18 ;
if ( V_14 )
* V_14 = V_16 -> V_26 . V_27 . V_14 ;
F_11 ( V_16 ) ;
F_12 ( V_16 ) ;
return 0 ;
}
enum V_28 F_13 ( struct V_10 * exp , T_1 V_29 ,
const struct V_30 * V_31 , enum V_32 type ,
T_2 * V_33 , enum V_28 V_34 ,
struct V_11 * V_12 )
{
struct V_35 V_36 ;
enum V_28 V_37 ;
F_14 ( V_31 , & V_36 ) ;
V_33 -> V_27 . V_14 &= F_15 ( exp ) ;
V_37 = F_16 ( F_17 ( exp ) -> V_38 , V_29 ,
& V_36 , type , V_33 , V_34 , V_12 , 0 ) ;
return V_37 ;
}
int F_18 ( struct V_10 * exp ,
const struct V_30 * V_31 ,
T_2 * V_33 ,
enum V_28 V_34 ,
enum V_39 V_29 ,
void * V_40 )
{
struct V_35 V_36 ;
struct V_41 * V_42 = F_17 ( exp ) ;
int V_37 ;
F_14 ( V_31 , & V_36 ) ;
V_37 = F_19 ( V_42 -> V_38 , & V_36 ,
V_33 , V_34 , V_29 , V_40 ) ;
return V_37 ;
}
int F_20 ( struct V_10 * exp ,
const struct V_30 * V_31 )
{
struct V_35 V_36 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = F_17 ( exp ) -> V_38 ;
F_10 ( V_46 , L_3 ) ;
F_14 ( V_31 , & V_36 ) ;
V_44 = F_21 ( V_46 , NULL , & V_36 , 0 , 0 ) ;
if ( F_22 ( V_44 ) )
return 0 ;
F_23 ( V_44 ) ;
V_44 -> V_20 = NULL ;
F_24 ( V_44 ) ;
F_25 ( V_44 ) ;
return 0 ;
}
static inline void F_26 ( struct V_47 * V_48 , int V_37 )
{
if ( V_48 -> V_49 ) {
F_27 ( & V_48 -> V_50 ) ;
V_48 -> V_49 = 0 ;
F_28 ( & V_48 -> V_50 ) ;
}
if ( V_37 && V_48 -> V_51 != 0 ) {
F_29 ( V_52 , V_48 , L_4 , V_37 ) ;
F_4 () ;
}
}
static void F_30 ( struct V_47 * V_48 ,
struct V_53 * V_54 )
{
int V_37 ;
V_37 = F_31 ( V_48 , V_55 + 4 ,
V_54 -> V_56 ) ;
if ( V_37 ) {
F_3 ( L_5 ,
V_55 + 4 , V_54 -> V_56 ) ;
V_54 -> V_57 &= ~ V_58 ;
V_54 -> V_56 = 0 ;
}
}
static struct V_47 *
F_32 ( struct V_10 * exp , struct V_2 * V_3 ,
struct V_59 * V_60 )
{
struct V_47 * V_48 ;
struct V_41 * V_61 = F_17 ( exp ) ;
struct V_62 * V_63 ;
const void * V_64 = V_60 -> V_60 ;
T_3 V_65 = V_60 -> V_66 ;
F_33 ( V_67 ) ;
int V_68 = 0 ;
int V_34 ;
int V_37 ;
V_3 -> V_69 = ( V_3 -> V_69 & ~ V_70 ) | V_71 ;
if ( F_34 ( & V_60 -> V_72 ) ) {
if ( V_3 -> V_73 & V_74 ) {
if ( V_3 -> V_73 & V_75 )
V_34 = V_76 ;
else
V_34 = V_77 ;
} else {
if ( V_3 -> V_73 & ( V_75 | V_78 ) )
V_34 = V_79 ;
else if ( V_3 -> V_73 & V_80 )
V_34 = V_77 ;
else
V_34 = V_81 ;
}
V_68 = F_35 ( exp , & V_60 -> V_72 ,
& V_67 , V_34 ,
V_82 ) ;
}
if ( V_3 -> V_83 & V_84 )
V_34 = V_76 ;
else
V_34 = V_81 ;
V_68 += F_35 ( exp , & V_60 -> V_85 ,
& V_67 , V_34 ,
V_86 ) ;
V_48 = F_36 ( F_37 ( exp ) ,
& V_87 ) ;
if ( ! V_48 ) {
F_38 ( & V_67 , V_88 , V_68 ) ;
return F_39 ( - V_89 ) ;
}
F_40 ( & V_48 -> V_90 , & V_91 , V_92 ,
V_60 -> V_93 + 1 ) ;
F_40 ( & V_48 -> V_90 , & V_94 , V_92 ,
F_41 ( V_65 , V_61 -> V_95 . V_96 . V_97 ) ) ;
V_37 = F_42 ( exp , V_48 , & V_67 , V_68 ) ;
if ( V_37 < 0 ) {
F_43 ( V_48 ) ;
return F_39 ( V_37 ) ;
}
F_27 ( & V_48 -> V_50 ) ;
V_48 -> V_49 = V_48 -> V_98 -> V_99 ;
F_28 ( & V_48 -> V_50 ) ;
V_63 = F_44 ( & V_48 -> V_90 , & V_100 ) ;
V_63 -> V_101 = ( T_1 ) V_3 -> V_83 ;
F_45 ( V_48 , V_60 , V_3 -> V_69 , 0 , V_3 -> V_73 , V_64 ,
V_65 ) ;
F_40 ( & V_48 -> V_90 , & V_102 , V_103 ,
V_61 -> V_95 . V_96 . V_104 ) ;
F_46 ( V_48 ) ;
return V_48 ;
}
static struct V_47 *
F_47 ( struct V_10 * exp ,
struct V_2 * V_3 ,
struct V_59 * V_60 )
{
struct V_47 * V_48 ;
struct V_62 * V_63 ;
int V_37 , V_68 = 0 ;
T_3 V_105 ;
F_33 ( V_67 ) ;
V_48 = F_36 ( F_37 ( exp ) ,
& V_106 ) ;
if ( ! V_48 )
return F_39 ( - V_89 ) ;
V_37 = F_42 ( exp , V_48 , & V_67 , V_68 ) ;
if ( V_37 ) {
F_43 ( V_48 ) ;
return F_39 ( V_37 ) ;
}
V_63 = F_44 ( & V_48 -> V_90 , & V_100 ) ;
V_63 -> V_101 = V_107 ;
V_105 = F_37 ( exp ) -> V_108 . V_109 ;
F_48 ( V_48 , & V_60 -> V_85 , V_60 -> V_110 , V_105 , - 1 ,
0 ) ;
F_40 ( & V_48 -> V_90 , & V_94 , V_103 , V_105 ) ;
F_40 ( & V_48 -> V_90 , & V_111 , V_103 , V_105 ) ;
F_40 ( & V_48 -> V_90 , & V_112 ,
V_103 , V_105 ) ;
F_46 ( V_48 ) ;
return V_48 ;
}
static struct V_47 * F_49 ( struct V_10 * exp ,
struct V_2 * V_3 ,
struct V_59 * V_60 )
{
struct V_47 * V_48 ;
struct V_41 * V_61 = F_17 ( exp ) ;
struct V_62 * V_63 ;
int V_37 ;
V_48 = F_36 ( F_37 ( exp ) ,
& V_113 ) ;
if ( ! V_48 )
return F_39 ( - V_89 ) ;
F_40 ( & V_48 -> V_90 , & V_91 , V_92 ,
V_60 -> V_93 + 1 ) ;
V_37 = F_42 ( exp , V_48 , NULL , 0 ) ;
if ( V_37 ) {
F_43 ( V_48 ) ;
return F_39 ( V_37 ) ;
}
V_63 = F_44 ( & V_48 -> V_90 , & V_100 ) ;
V_63 -> V_101 = ( T_1 ) V_3 -> V_83 ;
F_50 ( V_48 , V_60 ) ;
F_40 ( & V_48 -> V_90 , & V_102 , V_103 ,
V_61 -> V_95 . V_96 . V_97 ) ;
F_40 ( & V_48 -> V_90 , & V_114 , V_103 ,
V_61 -> V_95 . V_96 . V_115 ) ;
F_46 ( V_48 ) ;
return V_48 ;
}
static struct V_47 * F_51 ( struct V_10 * exp ,
struct V_2 * V_3 ,
struct V_59 * V_60 )
{
struct V_47 * V_48 ;
struct V_41 * V_61 = F_17 ( exp ) ;
T_4 V_116 = V_117 | V_58 |
V_118 | V_119 |
V_120 | V_121 ;
struct V_62 * V_63 ;
int V_37 ;
T_3 V_122 ;
V_48 = F_36 ( F_37 ( exp ) ,
& V_123 ) ;
if ( ! V_48 )
return F_39 ( - V_89 ) ;
F_40 ( & V_48 -> V_90 , & V_91 , V_92 ,
V_60 -> V_93 + 1 ) ;
V_37 = F_42 ( exp , V_48 , NULL , 0 ) ;
if ( V_37 ) {
F_43 ( V_48 ) ;
return F_39 ( V_37 ) ;
}
V_63 = F_44 ( & V_48 -> V_90 , & V_100 ) ;
V_63 -> V_101 = ( T_1 ) V_3 -> V_83 ;
if ( V_61 -> V_95 . V_96 . V_97 > 0 )
V_122 = V_61 -> V_95 . V_96 . V_97 ;
else
V_122 = V_61 -> V_95 . V_96 . V_104 ;
F_52 ( V_48 , V_116 , V_3 -> V_73 , V_60 , V_122 ) ;
F_40 ( & V_48 -> V_90 , & V_102 , V_103 , V_122 ) ;
F_46 ( V_48 ) ;
return V_48 ;
}
static struct V_47 * F_53 ( struct V_10 * exp ,
struct V_2 * V_3 ,
struct V_59 * V_124 )
{
struct V_41 * V_42 = F_17 ( exp ) ;
struct V_47 * V_48 ;
struct V_62 * V_63 ;
struct V_125 * V_126 ;
int V_37 ;
V_48 = F_36 ( F_37 ( exp ) ,
& V_127 ) ;
if ( ! V_48 )
return F_39 ( - V_89 ) ;
F_40 ( & V_48 -> V_90 , & V_94 , V_92 , 0 ) ;
V_37 = F_42 ( exp , V_48 , NULL , 0 ) ;
if ( V_37 ) {
F_43 ( V_48 ) ;
return F_39 ( V_37 ) ;
}
V_63 = F_44 ( & V_48 -> V_90 , & V_100 ) ;
V_63 -> V_101 = ( T_1 ) V_3 -> V_83 ;
V_126 = F_44 ( & V_48 -> V_90 , & V_128 ) ;
V_126 -> V_129 = V_130 ;
F_40 ( & V_48 -> V_90 , & V_131 , V_103 ,
V_42 -> V_95 . V_96 . V_97 ) ;
F_46 ( V_48 ) ;
return V_48 ;
}
static struct V_47 *
F_54 ( struct V_10 * exp , int V_132 )
{
struct V_47 * V_48 ;
int V_37 ;
V_48 = F_36 ( F_37 ( exp ) , & V_133 ) ;
if ( ! V_48 )
return F_39 ( - V_89 ) ;
V_37 = F_42 ( exp , V_48 , NULL , 0 ) ;
if ( V_37 ) {
F_43 ( V_48 ) ;
return F_39 ( V_37 ) ;
}
F_40 ( & V_48 -> V_90 , & V_131 , V_103 , V_132 ) ;
F_46 ( V_48 ) ;
return V_48 ;
}
static int F_55 ( struct V_10 * exp ,
struct V_47 * V_48 ,
struct V_134 * V_135 ,
struct V_2 * V_3 ,
struct V_11 * V_12 ,
int V_37 )
{
struct V_136 * V_137 = & V_48 -> V_90 ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
struct V_15 * V_16 ;
void * V_142 = NULL ;
T_3 V_132 = 0 ;
F_8 ( V_37 >= 0 ) ;
if ( V_48 -> V_51 || V_48 -> V_49 ) {
V_139 = F_44 ( V_137 , & V_143 ) ;
V_139 -> V_144 |= F_56 ( V_145 ) ;
}
if ( V_37 == V_146 ) {
V_135 -> V_147 = 0 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_37 = 0 ;
} else {
V_16 = F_7 ( V_12 ) ;
if ( V_16 -> V_148 != V_135 -> V_147 ) {
F_57 ( V_12 , V_16 -> V_148 ) ;
F_58 ( V_12 , V_135 -> V_147 ) ;
V_135 -> V_147 = V_16 -> V_148 ;
}
F_12 ( V_16 ) ;
}
V_141 = F_59 ( V_137 , & V_149 ) ;
V_3 -> F_2 = ( int ) V_141 -> V_150 ;
V_3 -> V_5 = ( int ) V_141 -> V_151 ;
V_3 -> V_152 = V_135 -> V_147 ;
V_3 -> V_153 = V_12 -> V_154 ;
V_3 -> V_155 = V_48 ;
if ( ( ! V_48 -> V_51 || V_3 -> V_5 < 0 ) && V_48 -> V_49 )
F_26 ( V_48 , V_3 -> V_5 ) ;
if ( V_3 -> V_83 & V_156 && V_48 -> V_49 &&
( ! F_2 ( V_3 , V_6 ) || V_3 -> V_5 != 0 ) )
F_26 ( V_48 , V_3 -> V_5 ) ;
F_29 ( V_157 , V_48 , L_6 ,
V_3 -> V_83 , V_3 -> F_2 , V_3 -> V_5 ) ;
if ( V_3 -> V_83 & ( V_156 | V_158 | V_159 | V_160 ) ) {
struct V_53 * V_54 ;
V_54 = F_59 ( V_137 , & V_161 ) ;
if ( ! V_54 ) {
F_3 ( L_7 ) ;
return - V_162 ;
}
if ( F_2 ( V_3 , V_6 ) &&
! F_1 ( V_6 , V_3 ) ) {
F_60 ( NULL , NULL , V_3 ) ;
}
if ( ( V_54 -> V_57 & ( V_119 | V_58 ) ) != 0 ) {
void * V_163 ;
F_61 ( exp , V_54 ) ;
V_163 = F_62 ( V_137 , & V_102 ,
V_54 -> V_56 ) ;
if ( ! V_163 )
return - V_162 ;
V_142 = V_163 ;
V_132 = V_54 -> V_56 ;
if ( ( V_3 -> V_83 & V_156 ) && V_48 -> V_49 ) {
void * V_64 ;
if ( F_63 ( V_137 , & V_94 ,
V_92 ) <
V_54 -> V_56 )
F_30 ( V_48 , V_54 ) ;
else
F_64 ( V_137 , & V_94 ,
V_54 -> V_56 ,
V_92 ) ;
F_40 ( V_137 , & V_94 ,
V_92 ,
V_54 -> V_56 ) ;
V_64 = F_44 ( V_137 , & V_94 ) ;
if ( V_64 )
memcpy ( V_64 , V_163 , V_54 -> V_56 ) ;
}
}
} else if ( V_3 -> V_83 & V_164 ) {
V_132 = F_63 ( V_137 , & V_131 , V_103 ) ;
if ( V_132 > 0 ) {
V_142 = F_62 ( V_137 ,
& V_131 ,
V_132 ) ;
if ( ! V_142 )
return - V_162 ;
}
}
V_16 = F_7 ( V_12 ) ;
if ( V_16 && F_65 ( V_16 ) && V_142 ) {
void * V_64 ;
F_66 ( V_16 , L_8 ,
F_67 ( V_3 -> V_83 ) , V_132 ) ;
V_64 = F_68 ( V_132 , V_165 ) ;
if ( ! V_64 ) {
F_12 ( V_16 ) ;
return - V_89 ;
}
memcpy ( V_64 , V_142 , V_132 ) ;
F_9 ( V_16 ) ;
if ( ! V_16 -> V_166 ) {
V_16 -> V_167 = V_168 ;
V_16 -> V_166 = V_64 ;
V_16 -> V_169 = V_132 ;
V_64 = NULL ;
}
F_11 ( V_16 ) ;
if ( V_64 )
F_69 ( V_64 ) ;
}
if ( V_16 )
F_12 ( V_16 ) ;
return V_37 ;
}
int F_70 ( struct V_10 * exp , struct V_134 * V_135 ,
const T_2 * V_33 ,
struct V_2 * V_3 , struct V_59 * V_60 ,
struct V_11 * V_12 , T_4 V_170 )
{
static const T_2 V_171 = {
. V_27 = { V_172 }
} ;
static const T_2 V_173 = {
. V_27 = { V_86 }
} ;
static const T_2 V_174 = {
. V_27 = { V_175 }
} ;
static const T_2 V_176 = {
. V_27 = { V_177 }
} ;
struct V_41 * V_61 = F_17 ( exp ) ;
struct V_47 * V_48 = NULL ;
T_4 V_29 , V_178 = V_170 ;
struct V_35 V_36 ;
int V_179 , V_180 = 0 ;
struct V_140 * V_141 ;
enum V_181 V_181 = V_182 ;
int V_37 ;
F_10 ( ! V_3 || V_135 -> V_183 == V_184 , L_9 ,
V_135 -> V_183 ) ;
F_14 ( & V_60 -> V_85 , & V_36 ) ;
if ( V_3 ) {
F_8 ( ! V_33 ) ;
V_178 |= V_185 ;
if ( V_3 -> V_83 & ( V_156 | V_158 | V_160 | V_186 ) )
V_33 = & V_173 ;
else if ( V_3 -> V_83 & V_164 )
V_33 = & V_174 ;
else if ( V_3 -> V_83 & ( V_107 | V_187 ) )
V_33 = & V_176 ;
else
V_33 = & V_171 ;
}
V_179 = V_61 -> V_95 . V_96 . V_188 -> V_189 ;
V_190:
V_29 = V_178 ;
if ( ! V_3 ) {
F_10 ( V_135 -> V_183 == V_191 , L_9 ,
V_135 -> V_183 ) ;
V_36 . V_192 [ 3 ] = V_191 ;
} else if ( V_3 -> V_83 & V_156 ) {
V_48 = F_32 ( exp , V_3 , V_60 ) ;
} else if ( V_3 -> V_83 & V_158 ) {
V_48 = F_49 ( exp , V_3 , V_60 ) ;
} else if ( V_3 -> V_83 & ( V_160 | V_159 ) ) {
V_48 = F_51 ( exp , V_3 , V_60 ) ;
} else if ( V_3 -> V_83 & V_186 ) {
V_48 = F_54 ( exp , 0 ) ;
} else if ( V_3 -> V_83 & V_164 ) {
if ( ! F_71 ( F_37 ( exp ) ) )
return - V_193 ;
V_48 = F_53 ( exp , V_3 , V_60 ) ;
V_181 = V_168 ;
} else if ( V_3 -> V_83 & V_107 ) {
V_48 = F_47 ( exp , V_3 , V_60 ) ;
} else {
F_4 () ;
return - V_194 ;
}
if ( F_22 ( V_48 ) )
return F_72 ( V_48 ) ;
if ( V_48 && V_3 && V_3 -> V_83 & V_84 )
V_48 -> V_195 = 1 ;
if ( V_180 ) {
V_48 -> V_196 = 1 ;
V_48 -> V_197 = V_179 ;
V_48 -> V_198 = F_73 () + V_180 ;
}
if ( V_3 ) {
F_74 ( V_61 -> V_95 . V_96 . V_199 , V_3 ) ;
V_37 = F_75 ( & V_61 -> V_95 . V_96 ) ;
if ( V_37 != 0 ) {
F_76 ( V_61 -> V_95 . V_96 . V_199 , V_3 ) ;
F_26 ( V_48 , 0 ) ;
F_77 ( V_48 ) ;
return V_37 ;
}
}
V_37 = F_78 ( exp , & V_48 , V_135 , & V_36 , V_33 , & V_29 , NULL ,
0 , V_181 , V_12 , 0 ) ;
if ( ! V_3 ) {
if ( ( ( V_37 == - V_200 ) || ( V_37 == - V_201 ) ) &&
( V_135 -> V_183 == V_191 ) &&
( V_135 -> V_147 == V_202 ) )
goto V_190;
return V_37 ;
}
F_79 ( & V_61 -> V_95 . V_96 ) ;
F_76 ( V_61 -> V_95 . V_96 . V_199 , V_3 ) ;
if ( V_37 < 0 ) {
F_80 ( V_203 , L_10 ,
V_61 -> V_204 , V_37 ) ;
F_26 ( V_48 , V_37 ) ;
F_77 ( V_48 ) ;
return V_37 ;
}
V_141 = F_59 ( & V_48 -> V_90 , & V_149 ) ;
V_141 -> V_151 =
F_81 ( V_141 -> V_151 ) ;
if ( V_3 -> V_83 & V_84 &&
( int ) V_141 -> V_151 == - V_205 ) {
F_26 ( V_48 , V_37 ) ;
F_77 ( V_48 ) ;
V_180 ++ ;
F_80 ( V_206 , L_11 V_207 L_12 V_207 L_13 ,
V_61 -> V_204 , V_180 , V_3 -> V_83 ,
F_82 ( & V_60 -> V_85 ) , F_82 ( & V_60 -> V_72 ) ) ;
if ( V_179 == V_61 -> V_95 . V_96 . V_188 -> V_189 ) {
goto V_190;
} else {
F_80 ( V_206 , L_14 ) ;
return - V_208 ;
}
}
V_37 = F_55 ( exp , V_48 , V_135 , V_3 , V_12 , V_37 ) ;
if ( V_37 < 0 ) {
if ( F_6 ( V_12 ) ) {
F_58 ( V_12 , V_135 -> V_147 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
}
F_77 ( V_48 ) ;
V_3 -> V_153 = 0 ;
V_3 -> V_152 = 0 ;
V_3 -> V_155 = NULL ;
}
return V_37 ;
}
static int F_83 ( struct V_10 * exp ,
struct V_47 * V_209 ,
struct V_59 * V_60 ,
struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_11 V_210 ;
struct V_53 * V_53 ;
struct V_15 * V_16 ;
int V_37 ;
F_8 ( V_209 != V_211 ) ;
F_8 ( V_209 -> V_212 != V_211 ) ;
if ( V_3 -> V_83 & V_186 )
return 0 ;
if ( ! F_2 ( V_3 , V_9 ) ) {
F_8 ( V_3 -> V_5 != 0 ) ;
return V_3 -> V_5 ;
}
V_37 = F_1 ( V_9 , V_3 ) ;
if ( V_37 )
return V_37 ;
V_53 = F_59 ( & V_209 -> V_90 , & V_161 ) ;
F_8 ( V_53 ) ;
V_37 = F_1 ( V_8 , V_3 ) ;
if ( V_37 )
return V_37 ;
if ( ! F_2 ( V_3 , V_213 ) &&
F_2 ( V_3 , V_7 ) &&
! F_1 ( V_7 , V_3 ) ) {
F_84 ( V_3 , V_213 ) ;
F_85 ( V_209 ) ;
}
if ( ! F_2 ( V_3 , V_214 ) &&
F_2 ( V_3 , V_6 ) &&
! F_1 ( V_6 , V_3 ) ) {
F_84 ( V_3 , V_214 ) ;
F_85 ( V_209 ) ;
F_86 ( V_215 , V_216 ) ;
}
if ( V_3 -> V_83 & V_84 ) {
} else if ( V_3 -> V_83 == V_156 ) {
F_8 ( ! F_2 ( V_3 , V_7 ) ) ;
} else {
F_8 ( V_3 -> V_83 & ( V_160 | V_159 | V_164 ) ) ;
}
V_16 = F_7 ( V_12 ) ;
if ( V_16 ) {
T_2 V_33 = V_16 -> V_26 ;
F_66 ( V_16 , L_15 ) ;
F_10 ( F_87 ( & V_53 -> V_217 ,
& V_16 -> V_19 -> V_218 ) ,
L_16 V_219 L_17 V_207 L_13 ,
F_88 ( V_16 -> V_19 ) , F_82 ( & V_53 -> V_217 ) ) ;
F_12 ( V_16 ) ;
memcpy ( & V_210 , V_12 , sizeof( * V_12 ) ) ;
if ( F_16 ( NULL , V_220 , NULL ,
V_184 , & V_33 , V_202 ,
& V_210 , 0 ) ) {
F_89 ( V_12 ,
V_3 -> V_152 ) ;
memcpy ( V_12 , & V_210 , sizeof( V_210 ) ) ;
V_3 -> V_153 = V_12 -> V_154 ;
}
}
F_80 ( V_221 ,
L_18 ,
( int ) V_60 -> V_93 , V_60 -> V_222 ,
F_67 ( V_3 -> V_83 ) , V_3 -> V_5 , V_3 -> F_2 , V_37 ) ;
return V_37 ;
}
int F_90 ( struct V_10 * exp , struct V_2 * V_3 ,
struct V_30 * V_31 , T_1 * V_14 )
{
struct V_35 V_36 ;
struct V_11 V_12 ;
T_2 V_33 ;
enum V_28 V_34 ;
if ( V_3 -> V_153 ) {
V_12 . V_154 = V_3 -> V_153 ;
V_34 = F_91 ( & V_12 , V_14 ) ;
} else {
F_14 ( V_31 , & V_36 ) ;
switch ( V_3 -> V_83 ) {
case V_160 :
V_33 . V_27 . V_14 = V_86 |
V_172 |
V_223 ;
break;
case V_186 :
V_33 . V_27 . V_14 = V_86 ;
break;
case V_164 :
V_33 . V_27 . V_14 = V_175 ;
break;
default:
V_33 . V_27 . V_14 = V_172 ;
break;
}
V_34 = F_13 ( exp , V_220 , V_31 ,
V_184 , & V_33 ,
V_81 | V_79 | V_77 | V_224 ,
& V_12 ) ;
}
if ( V_34 ) {
V_3 -> V_153 = V_12 . V_154 ;
V_3 -> V_152 = V_34 ;
} else {
V_3 -> V_153 = 0 ;
V_3 -> V_152 = 0 ;
}
return ! ! V_34 ;
}
int F_92 ( struct V_10 * exp , struct V_59 * V_60 ,
struct V_2 * V_3 , struct V_47 * * V_225 ,
T_5 V_226 , T_1 V_170 )
{
struct V_134 V_135 = {
. V_183 = V_184 ,
. V_147 = F_93 ( V_3 ) ,
. V_227 = V_226 ,
. V_228 = V_229 ,
} ;
struct V_11 V_12 ;
int V_37 = 0 ;
F_8 ( V_3 ) ;
F_80 ( V_230 , L_19 V_207 L_20 V_207
L_21 , ( int ) V_60 -> V_93 ,
V_60 -> V_222 , F_82 ( & V_60 -> V_72 ) ,
F_82 ( & V_60 -> V_85 ) , F_67 ( V_3 -> V_83 ) ,
V_3 -> V_73 ) ;
V_12 . V_154 = 0 ;
if ( F_34 ( & V_60 -> V_72 ) &&
( V_3 -> V_83 & ( V_159 | V_160 | V_186 ) ) ) {
V_3 -> V_153 = 0 ;
V_37 = F_90 ( exp , V_3 , & V_60 -> V_72 , NULL ) ;
if ( V_37 || V_60 -> V_93 != 0 )
return V_37 ;
}
if ( ! F_34 ( & V_60 -> V_72 ) && V_3 -> V_83 & V_84 ) {
V_37 = F_94 ( NULL , exp , & V_60 -> V_72 , V_60 ) ;
if ( V_37 < 0 ) {
F_3 ( L_22 , V_37 ) ;
return V_37 ;
}
}
V_37 = F_70 ( exp , & V_135 , NULL , V_3 , V_60 , & V_12 ,
V_170 ) ;
if ( V_37 < 0 )
return V_37 ;
* V_225 = V_3 -> V_155 ;
V_37 = F_83 ( exp , * V_225 , V_60 , V_3 , & V_12 ) ;
return V_37 ;
}
static int F_95 ( const struct V_231 * V_232 ,
struct V_47 * V_48 ,
void * args , int V_37 )
{
struct V_233 * V_234 = args ;
struct V_10 * exp = V_234 -> V_235 ;
struct V_236 * V_237 = V_234 -> V_238 ;
struct V_134 * V_135 = V_234 -> V_239 ;
struct V_2 * V_3 ;
struct V_11 * V_12 ;
struct V_41 * V_61 ;
struct V_140 * V_141 ;
T_1 V_29 = V_185 ;
V_3 = & V_237 -> V_240 ;
V_12 = & V_237 -> V_241 ;
V_61 = F_17 ( exp ) ;
F_79 ( & V_61 -> V_95 . V_96 ) ;
if ( F_96 ( V_242 ) )
V_37 = - V_201 ;
V_37 = F_97 ( exp , V_48 , V_135 -> V_183 , 1 , V_135 -> V_147 ,
& V_29 , NULL , 0 , V_12 , V_37 ) ;
if ( V_37 < 0 ) {
F_3 ( L_23 , V_37 ) ;
F_26 ( V_48 , V_37 ) ;
goto V_243;
}
V_141 = F_59 ( & V_48 -> V_90 , & V_149 ) ;
V_141 -> V_151 =
F_81 ( V_141 -> V_151 ) ;
V_37 = F_55 ( exp , V_48 , V_135 , V_3 , V_12 , V_37 ) ;
if ( V_37 )
goto V_243;
V_37 = F_83 ( exp , V_48 , & V_237 -> V_244 , V_3 , V_12 ) ;
V_243:
F_98 ( V_135 ) ;
V_237 -> V_245 ( V_48 , V_237 , V_37 ) ;
return 0 ;
}
int F_99 ( struct V_10 * exp ,
struct V_236 * V_237 ,
struct V_134 * V_135 )
{
struct V_59 * V_60 = & V_237 -> V_244 ;
struct V_2 * V_3 = & V_237 -> V_240 ;
struct V_47 * V_48 ;
struct V_233 * V_234 ;
struct V_41 * V_61 = F_17 ( exp ) ;
struct V_35 V_36 ;
T_2 V_33 = {
. V_27 = { V_172 |
V_86 }
} ;
int V_37 = 0 ;
T_1 V_29 = V_185 ;
F_80 ( V_230 ,
L_24 V_207 L_21 ,
( int ) V_60 -> V_93 , V_60 -> V_222 ,
F_82 ( & V_60 -> V_85 ) , F_67 ( V_3 -> V_83 ) , V_3 -> V_73 ) ;
F_14 ( & V_60 -> V_85 , & V_36 ) ;
V_48 = F_51 ( exp , V_3 , V_60 ) ;
if ( F_22 ( V_48 ) )
return F_72 ( V_48 ) ;
V_37 = F_75 ( & V_61 -> V_95 . V_96 ) ;
if ( V_37 != 0 ) {
F_77 ( V_48 ) ;
return V_37 ;
}
V_37 = F_78 ( exp , & V_48 , V_135 , & V_36 , & V_33 , & V_29 , NULL ,
0 , V_182 , & V_237 -> V_241 , 1 ) ;
if ( V_37 < 0 ) {
F_79 ( & V_61 -> V_95 . V_96 ) ;
F_77 ( V_48 ) ;
return V_37 ;
}
F_100 ( sizeof( * V_234 ) <= sizeof( V_48 -> V_246 ) ) ;
V_234 = F_101 ( V_48 ) ;
V_234 -> V_235 = exp ;
V_234 -> V_238 = V_237 ;
V_234 -> V_239 = V_135 ;
V_48 -> V_247 = F_95 ;
F_102 ( V_48 ) ;
return 0 ;
}
