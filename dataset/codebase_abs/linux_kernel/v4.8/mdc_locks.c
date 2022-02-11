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
int F_5 ( struct V_10 * exp , T_1 * V_11 , void * V_12 ,
T_1 * V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 = V_12 ;
if ( V_13 )
* V_13 = 0 ;
if ( ! * V_11 )
return 0 ;
V_15 = F_6 ( (struct V_18 * ) V_11 ) ;
F_7 ( V_15 ) ;
F_8 ( V_15 ) ;
if ( V_15 -> V_19 -> V_20 &&
V_15 -> V_19 -> V_20 != V_12 ) {
struct V_16 * V_21 = V_15 -> V_19 -> V_20 ;
F_9 ( V_21 -> V_22 & V_23 ,
L_2 ,
V_21 , V_21 -> V_24 , V_21 -> V_25 ,
V_21 -> V_22 , V_17 , V_17 -> V_24 ,
V_17 -> V_25 ) ;
}
V_15 -> V_19 -> V_20 = V_17 ;
if ( V_13 )
* V_13 = V_15 -> V_26 . V_27 . V_13 ;
F_10 ( V_15 ) ;
F_11 ( V_15 ) ;
return 0 ;
}
enum V_28 F_12 ( struct V_10 * exp , T_1 V_29 ,
const struct V_30 * V_31 , enum V_32 type ,
T_2 * V_33 , enum V_28 V_34 ,
struct V_18 * V_11 )
{
struct V_35 V_36 ;
enum V_28 V_37 ;
F_13 ( V_31 , & V_36 ) ;
V_33 -> V_27 . V_13 &= F_14 ( exp ) ;
V_37 = F_15 ( F_16 ( exp ) -> V_38 , V_29 ,
& V_36 , type , V_33 , V_34 , V_11 , 0 ) ;
return V_37 ;
}
int F_17 ( struct V_10 * exp ,
const struct V_30 * V_31 ,
T_2 * V_33 ,
enum V_28 V_34 ,
enum V_39 V_29 ,
void * V_40 )
{
struct V_35 V_36 ;
struct V_41 * V_42 = F_16 ( exp ) ;
int V_37 ;
F_13 ( V_31 , & V_36 ) ;
V_37 = F_18 ( V_42 -> V_38 , & V_36 ,
V_33 , V_34 , V_29 , V_40 ) ;
return V_37 ;
}
int F_19 ( struct V_10 * exp ,
const struct V_30 * V_31 )
{
struct V_35 V_36 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = F_16 ( exp ) -> V_38 ;
F_9 ( V_46 , L_3 ) ;
F_13 ( V_31 , & V_36 ) ;
V_44 = F_20 ( V_46 , NULL , & V_36 , 0 , 0 ) ;
if ( ! V_44 )
return 0 ;
F_21 ( V_44 ) ;
V_44 -> V_20 = NULL ;
F_22 ( V_44 ) ;
F_23 ( V_44 ) ;
return 0 ;
}
int F_24 ( struct V_10 * exp ,
const struct V_30 * V_31 ,
T_3 V_3 , void * V_12 )
{
struct V_35 V_36 ;
int V_37 = 0 ;
F_13 ( (struct V_30 * ) V_31 , & V_36 ) ;
V_37 = F_25 ( F_16 ( exp ) -> V_38 , & V_36 ,
V_3 , V_12 ) ;
if ( V_37 == V_47 )
return 1 ;
else if ( V_37 == V_48 )
return 0 ;
return V_37 ;
}
static inline void F_26 ( struct V_49 * V_50 , int V_37 )
{
if ( V_50 -> V_51 ) {
F_27 ( & V_50 -> V_52 ) ;
V_50 -> V_51 = 0 ;
F_28 ( & V_50 -> V_52 ) ;
}
if ( V_37 && V_50 -> V_53 != 0 ) {
F_29 ( V_54 , V_50 , L_4 , V_37 ) ;
F_4 () ;
}
}
static void F_30 ( struct V_49 * V_50 ,
struct V_55 * V_56 )
{
int V_37 ;
V_37 = F_31 ( V_50 , V_57 + 4 ,
V_56 -> V_58 ) ;
if ( V_37 ) {
F_3 ( L_5 ,
V_57 + 4 , V_56 -> V_58 ) ;
V_56 -> V_59 &= ~ V_60 ;
V_56 -> V_58 = 0 ;
}
}
static struct V_49 * F_32 ( struct V_10 * exp ,
struct V_2 * V_3 ,
struct V_61 * V_62 ,
void * V_63 , int V_64 ,
void * V_65 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_16 ( exp ) ;
struct V_67 * V_68 ;
F_33 ( V_69 ) ;
int V_70 = 0 ;
int V_34 ;
int V_37 ;
V_3 -> V_71 = ( V_3 -> V_71 & ~ V_72 ) | V_73 ;
if ( F_34 ( & V_62 -> V_74 ) ) {
if ( V_3 -> V_75 & V_76 ) {
if ( V_3 -> V_75 & V_77 )
V_34 = V_78 ;
else
V_34 = V_79 ;
} else {
if ( V_3 -> V_75 & ( V_77 | V_80 ) )
V_34 = V_81 ;
else if ( V_3 -> V_75 & V_82 )
V_34 = V_79 ;
else
V_34 = V_83 ;
}
V_70 = F_35 ( exp , & V_62 -> V_74 ,
& V_69 , V_34 ,
V_84 ) ;
}
if ( V_3 -> V_85 & V_86 )
V_34 = V_78 ;
else
V_34 = V_83 ;
V_70 += F_35 ( exp , & V_62 -> V_87 ,
& V_69 , V_34 ,
V_88 ) ;
V_50 = F_36 ( F_37 ( exp ) ,
& V_89 ) ;
if ( ! V_50 ) {
F_38 ( & V_69 , V_90 , V_70 ) ;
return F_39 ( - V_91 ) ;
}
F_40 ( & V_50 -> V_92 , & V_93 , V_94 ,
V_62 -> V_95 + 1 ) ;
F_40 ( & V_50 -> V_92 , & V_96 , V_94 ,
F_41 ( V_64 , V_66 -> V_97 . V_98 . V_99 ) ) ;
V_37 = F_42 ( exp , V_50 , & V_69 , V_70 ) ;
if ( V_37 < 0 ) {
F_43 ( V_50 ) ;
return F_39 ( V_37 ) ;
}
F_27 ( & V_50 -> V_52 ) ;
V_50 -> V_51 = V_50 -> V_100 -> V_101 ;
F_28 ( & V_50 -> V_52 ) ;
V_68 = F_44 ( & V_50 -> V_92 , & V_102 ) ;
V_68 -> V_103 = ( T_1 ) V_3 -> V_85 ;
F_45 ( V_50 , V_62 , V_3 -> V_71 , 0 , V_3 -> V_75 , V_63 ,
V_64 ) ;
F_46 ( V_50 ) ;
return V_50 ;
}
static struct V_49 *
F_47 ( struct V_10 * exp ,
struct V_2 * V_3 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_67 * V_68 ;
int V_37 , V_70 = 0 , V_104 ;
F_33 ( V_69 ) ;
V_50 = F_36 ( F_37 ( exp ) ,
& V_105 ) ;
if ( ! V_50 )
return F_39 ( - V_91 ) ;
V_37 = F_42 ( exp , V_50 , & V_69 , V_70 ) ;
if ( V_37 ) {
F_43 ( V_50 ) ;
return F_39 ( V_37 ) ;
}
V_68 = F_44 ( & V_50 -> V_92 , & V_102 ) ;
V_68 -> V_103 = V_106 ;
V_104 = F_37 ( exp ) -> V_107 . V_108 ;
F_48 ( V_50 , & V_62 -> V_87 , V_62 -> V_109 , V_104 , - 1 ,
0 ) ;
F_40 ( & V_50 -> V_92 , & V_96 , V_110 , V_104 ) ;
F_40 ( & V_50 -> V_92 , & V_111 , V_110 , V_104 ) ;
F_40 ( & V_50 -> V_92 , & V_112 ,
V_110 , V_104 ) ;
F_46 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_49 ( struct V_10 * exp ,
struct V_2 * V_3 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_16 ( exp ) ;
struct V_67 * V_68 ;
int V_37 ;
V_50 = F_36 ( F_37 ( exp ) ,
& V_113 ) ;
if ( ! V_50 )
return F_39 ( - V_91 ) ;
F_40 ( & V_50 -> V_92 , & V_93 , V_94 ,
V_62 -> V_95 + 1 ) ;
V_37 = F_42 ( exp , V_50 , NULL , 0 ) ;
if ( V_37 ) {
F_43 ( V_50 ) ;
return F_39 ( V_37 ) ;
}
V_68 = F_44 ( & V_50 -> V_92 , & V_102 ) ;
V_68 -> V_103 = ( T_1 ) V_3 -> V_85 ;
F_50 ( V_50 , V_62 ) ;
F_40 ( & V_50 -> V_92 , & V_114 , V_110 ,
V_66 -> V_97 . V_98 . V_99 ) ;
F_40 ( & V_50 -> V_92 , & V_115 , V_110 ,
V_66 -> V_97 . V_98 . V_116 ) ;
F_46 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_51 ( struct V_10 * exp ,
struct V_2 * V_3 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_16 ( exp ) ;
T_4 V_59 = V_117 | V_60 |
V_118 | V_119 |
V_120 | V_121 ;
struct V_67 * V_68 ;
int V_37 ;
int V_122 ;
V_50 = F_36 ( F_37 ( exp ) ,
& V_123 ) ;
if ( ! V_50 )
return F_39 ( - V_91 ) ;
F_40 ( & V_50 -> V_92 , & V_93 , V_94 ,
V_62 -> V_95 + 1 ) ;
V_37 = F_42 ( exp , V_50 , NULL , 0 ) ;
if ( V_37 ) {
F_43 ( V_50 ) ;
return F_39 ( V_37 ) ;
}
V_68 = F_44 ( & V_50 -> V_92 , & V_102 ) ;
V_68 -> V_103 = ( T_1 ) V_3 -> V_85 ;
if ( V_66 -> V_97 . V_98 . V_99 > 0 )
V_122 = V_66 -> V_97 . V_98 . V_99 ;
else
V_122 = V_66 -> V_97 . V_98 . V_124 ;
F_52 ( V_50 , V_59 , V_3 -> V_75 , V_62 , V_122 ) ;
F_40 ( & V_50 -> V_92 , & V_114 , V_110 , V_122 ) ;
F_46 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_53 ( struct V_10 * exp ,
struct V_2 * V_3 ,
struct V_61 * V_125 )
{
struct V_41 * V_42 = F_16 ( exp ) ;
struct V_49 * V_50 ;
struct V_67 * V_68 ;
struct V_126 * V_127 ;
int V_37 ;
V_50 = F_36 ( F_37 ( exp ) ,
& V_128 ) ;
if ( ! V_50 )
return F_39 ( - V_91 ) ;
F_40 ( & V_50 -> V_92 , & V_96 , V_94 , 0 ) ;
V_37 = F_42 ( exp , V_50 , NULL , 0 ) ;
if ( V_37 ) {
F_43 ( V_50 ) ;
return F_39 ( V_37 ) ;
}
V_68 = F_44 ( & V_50 -> V_92 , & V_102 ) ;
V_68 -> V_103 = ( T_1 ) V_3 -> V_85 ;
V_127 = F_44 ( & V_50 -> V_92 , & V_129 ) ;
V_127 -> V_130 = V_131 ;
F_40 ( & V_50 -> V_92 , & V_132 , V_110 ,
V_42 -> V_97 . V_98 . V_99 ) ;
F_46 ( V_50 ) ;
return V_50 ;
}
static struct V_49 *
F_54 ( struct V_10 * exp , int V_133 )
{
struct V_49 * V_50 ;
int V_37 ;
V_50 = F_36 ( F_37 ( exp ) , & V_134 ) ;
if ( ! V_50 )
return F_39 ( - V_91 ) ;
V_37 = F_42 ( exp , V_50 , NULL , 0 ) ;
if ( V_37 ) {
F_43 ( V_50 ) ;
return F_39 ( V_37 ) ;
}
F_40 ( & V_50 -> V_92 , & V_132 , V_110 , V_133 ) ;
F_46 ( V_50 ) ;
return V_50 ;
}
static int F_55 ( struct V_10 * exp ,
struct V_49 * V_50 ,
struct V_135 * V_136 ,
struct V_2 * V_3 ,
struct V_18 * V_11 ,
int V_37 )
{
struct V_137 * V_138 = & V_50 -> V_92 ;
struct V_139 * V_140 ;
struct V_141 * V_142 ;
struct V_14 * V_15 ;
void * V_143 = NULL ;
int V_133 = 0 ;
F_7 ( V_37 >= 0 ) ;
if ( V_50 -> V_53 || V_50 -> V_51 ) {
V_140 = F_44 ( V_138 , & V_144 ) ;
V_140 -> V_145 |= F_56 ( V_146 ) ;
}
if ( V_37 == V_147 ) {
V_136 -> V_148 = 0 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_37 = 0 ;
} else {
V_15 = F_6 ( V_11 ) ;
if ( V_15 -> V_149 != V_136 -> V_148 ) {
F_57 ( V_11 , V_15 -> V_149 ) ;
F_58 ( V_11 , V_136 -> V_148 ) ;
V_136 -> V_148 = V_15 -> V_149 ;
}
F_11 ( V_15 ) ;
}
V_142 = F_59 ( V_138 , & V_150 ) ;
V_3 -> F_2 = ( int ) V_142 -> V_151 ;
V_3 -> V_5 = ( int ) V_142 -> V_152 ;
V_3 -> V_153 = V_136 -> V_148 ;
V_3 -> V_154 = V_11 -> V_155 ;
V_3 -> V_156 = V_50 ;
if ( ( ! V_50 -> V_53 || V_3 -> V_5 < 0 ) && V_50 -> V_51 )
F_26 ( V_50 , V_3 -> V_5 ) ;
if ( V_3 -> V_85 & V_157 && V_50 -> V_51 &&
( ! F_2 ( V_3 , V_6 ) || V_3 -> V_5 != 0 ) )
F_26 ( V_50 , V_3 -> V_5 ) ;
F_29 ( V_158 , V_50 , L_6 ,
V_3 -> V_85 , V_3 -> F_2 , V_3 -> V_5 ) ;
if ( V_3 -> V_85 & ( V_157 | V_159 | V_160 | V_161 ) ) {
struct V_55 * V_56 ;
V_56 = F_59 ( V_138 , & V_162 ) ;
if ( ! V_56 ) {
F_3 ( L_7 ) ;
return - V_163 ;
}
if ( F_2 ( V_3 , V_6 ) &&
! F_1 ( V_6 , V_3 ) ) {
F_60 ( NULL , NULL , V_3 ) ;
}
if ( ( V_56 -> V_59 & ( V_119 | V_60 ) ) != 0 ) {
void * V_164 ;
F_61 ( exp , V_56 ) ;
V_164 = F_62 ( V_138 , & V_114 ,
V_56 -> V_58 ) ;
if ( ! V_164 )
return - V_163 ;
V_143 = V_164 ;
V_133 = V_56 -> V_58 ;
if ( ( V_3 -> V_85 & V_157 ) && V_50 -> V_51 ) {
void * V_63 ;
if ( F_63 ( V_138 , & V_96 ,
V_94 ) <
V_56 -> V_58 )
F_30 ( V_50 , V_56 ) ;
else
F_64 ( V_138 , & V_96 ,
V_56 -> V_58 ,
V_94 ) ;
F_40 ( V_138 , & V_96 ,
V_94 ,
V_56 -> V_58 ) ;
V_63 = F_44 ( V_138 , & V_96 ) ;
if ( V_63 )
memcpy ( V_63 , V_164 , V_56 -> V_58 ) ;
}
}
} else if ( V_3 -> V_85 & V_165 ) {
V_133 = F_63 ( V_138 , & V_132 , V_110 ) ;
if ( V_133 > 0 ) {
V_143 = F_62 ( V_138 ,
& V_132 , V_133 ) ;
if ( ! V_143 )
return - V_163 ;
}
}
V_15 = F_6 ( V_11 ) ;
if ( V_15 && F_65 ( V_15 ) && V_143 ) {
void * V_63 ;
F_66 ( V_15 , L_8 ,
F_67 ( V_3 -> V_85 ) , V_133 ) ;
V_63 = F_68 ( V_133 , V_166 ) ;
if ( ! V_63 ) {
F_11 ( V_15 ) ;
return - V_91 ;
}
memcpy ( V_63 , V_143 , V_133 ) ;
F_8 ( V_15 ) ;
if ( ! V_15 -> V_167 ) {
V_15 -> V_168 = V_169 ;
V_15 -> V_167 = V_63 ;
V_15 -> V_170 = V_133 ;
V_63 = NULL ;
}
F_10 ( V_15 ) ;
if ( V_63 )
F_69 ( V_63 ) ;
}
if ( V_15 )
F_11 ( V_15 ) ;
return V_37 ;
}
int F_70 ( struct V_10 * exp , struct V_135 * V_136 ,
struct V_2 * V_3 , struct V_61 * V_62 ,
struct V_18 * V_11 , void * V_63 , int V_64 ,
struct V_49 * * V_171 , T_4 V_172 )
{
static const T_2 V_173 = {
. V_27 = { V_174 }
} ;
static const T_2 V_175 = {
. V_27 = { V_88 }
} ;
static const T_2 V_176 = {
. V_27 = { V_177 }
} ;
static const T_2 V_178 = {
. V_27 = { V_179 }
} ;
T_2 const * V_33 = & V_173 ;
struct V_41 * V_66 = F_16 ( exp ) ;
struct V_49 * V_50 ;
T_4 V_29 , V_180 = V_172 ;
struct V_35 V_36 ;
int V_181 , V_182 = 0 ;
struct V_141 * V_142 ;
enum V_183 V_183 = V_184 ;
int V_37 ;
F_9 ( ! V_3 || V_136 -> V_185 == V_186 , L_9 ,
V_136 -> V_185 ) ;
F_13 ( & V_62 -> V_87 , & V_36 ) ;
if ( V_3 ) {
V_180 |= V_187 ;
if ( V_3 -> V_85 & ( V_159 | V_161 | V_188 ) )
V_33 = & V_175 ;
else if ( V_3 -> V_85 & V_165 )
V_33 = & V_176 ;
else if ( V_3 -> V_85 & ( V_106 | V_189 ) )
V_33 = & V_178 ;
}
F_7 ( ! V_171 ) ;
V_181 = V_66 -> V_97 . V_98 . V_190 -> V_191 ;
V_192:
V_29 = V_180 ;
if ( ! V_3 ) {
F_7 ( V_63 && V_64 == 0 ) ;
F_9 ( V_136 -> V_185 == V_193 , L_9 ,
V_136 -> V_185 ) ;
V_33 = V_63 ;
V_36 . V_194 [ 3 ] = V_193 ;
V_50 = NULL ;
} else if ( V_3 -> V_85 & V_157 ) {
V_50 = F_32 ( exp , V_3 , V_62 , V_63 , V_64 ,
V_136 -> V_195 ) ;
V_33 = & V_175 ;
V_136 -> V_195 = NULL ;
V_63 = NULL ;
} else if ( V_3 -> V_85 & V_159 ) {
V_50 = F_49 ( exp , V_3 , V_62 ) ;
} else if ( V_3 -> V_85 & ( V_161 | V_160 ) ) {
V_50 = F_51 ( exp , V_3 , V_62 ) ;
} else if ( V_3 -> V_85 & V_188 ) {
V_50 = F_54 ( exp , 0 ) ;
} else if ( V_3 -> V_85 & V_165 ) {
if ( ! F_71 ( F_37 ( exp ) ) )
return - V_196 ;
V_50 = F_53 ( exp , V_3 , V_62 ) ;
V_183 = V_169 ;
} else if ( V_3 -> V_85 & V_106 ) {
V_50 = F_47 ( exp , V_3 , V_62 ) ;
} else {
F_4 () ;
return - V_197 ;
}
if ( F_72 ( V_50 ) )
return F_73 ( V_50 ) ;
if ( V_50 && V_3 && V_3 -> V_85 & V_86 )
V_50 -> V_198 = 1 ;
if ( V_182 ) {
V_50 -> V_199 = 1 ;
V_50 -> V_200 = V_181 ;
V_50 -> V_201 = F_74 () + V_182 ;
}
if ( V_3 ) {
F_75 ( V_66 -> V_97 . V_98 . V_202 , V_3 ) ;
V_37 = F_76 ( & V_66 -> V_97 . V_98 ) ;
if ( V_37 != 0 ) {
F_77 ( V_66 -> V_97 . V_98 . V_202 , V_3 ) ;
F_26 ( V_50 , 0 ) ;
F_78 ( V_50 ) ;
return V_37 ;
}
}
V_37 = F_79 ( exp , & V_50 , V_136 , & V_36 , V_33 , & V_29 , NULL ,
0 , V_183 , V_11 , 0 ) ;
if ( ! V_3 ) {
if ( ( ( V_37 == - V_203 ) || ( V_37 == - V_204 ) ) &&
( V_136 -> V_185 == V_193 ) &&
( V_136 -> V_148 == V_205 ) )
goto V_192;
return V_37 ;
}
F_80 ( & V_66 -> V_97 . V_98 ) ;
F_77 ( V_66 -> V_97 . V_98 . V_202 , V_3 ) ;
if ( V_37 < 0 ) {
F_81 ( ( V_37 == - V_206 || V_37 == - V_207 ) ? V_208 : V_54 ,
L_10 ,
V_66 -> V_209 , V_37 ) ;
F_26 ( V_50 , V_37 ) ;
F_78 ( V_50 ) ;
return V_37 ;
}
V_142 = F_59 ( & V_50 -> V_92 , & V_150 ) ;
V_142 -> V_152 =
F_82 ( V_142 -> V_152 ) ;
if ( V_3 -> V_85 & V_86 &&
( int ) V_142 -> V_152 == - V_210 ) {
F_26 ( V_50 , V_37 ) ;
F_78 ( V_50 ) ;
V_182 ++ ;
F_83 ( V_211 , L_11 V_212 L_12 V_212 L_13 ,
V_66 -> V_209 , V_182 , V_3 -> V_85 ,
F_84 ( & V_62 -> V_87 ) , F_84 ( & V_62 -> V_74 ) ) ;
if ( V_181 == V_66 -> V_97 . V_98 . V_190 -> V_191 ) {
goto V_192;
} else {
F_83 ( V_211 , L_14 ) ;
return - V_213 ;
}
}
V_37 = F_55 ( exp , V_50 , V_136 , V_3 , V_11 , V_37 ) ;
if ( V_37 < 0 ) {
if ( F_85 ( V_11 ) ) {
F_58 ( V_11 , V_136 -> V_148 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
}
F_78 ( V_50 ) ;
V_3 -> V_154 = 0 ;
V_3 -> V_153 = 0 ;
V_3 -> V_156 = NULL ;
}
return V_37 ;
}
static int F_86 ( struct V_10 * exp ,
struct V_49 * V_214 ,
struct V_61 * V_62 ,
struct V_2 * V_3 ,
struct V_18 * V_11 )
{
struct V_18 V_215 ;
struct V_55 * V_55 ;
struct V_14 * V_15 ;
int V_37 ;
F_7 ( V_214 != V_216 ) ;
F_7 ( V_214 -> V_217 != V_216 ) ;
if ( ! F_2 ( V_3 , V_9 ) ) {
F_7 ( V_3 -> V_5 != 0 ) ;
return V_3 -> V_5 ;
}
V_37 = F_1 ( V_9 , V_3 ) ;
if ( V_37 )
return V_37 ;
V_55 = F_59 ( & V_214 -> V_92 , & V_162 ) ;
F_7 ( V_55 ) ;
if ( F_34 ( & V_62 -> V_74 ) &&
V_3 -> V_71 & V_218 &&
V_3 -> V_85 != V_161 ) {
if ( ( ! F_87 ( & V_62 -> V_74 , & V_55 -> V_219 ) ) &&
( ! F_87 ( & V_62 -> V_220 , & V_55 -> V_219 ) ) ) {
F_83 ( V_221 , L_15 V_212 L_16 V_212 L_17 V_212
L_13 , F_84 ( & V_62 -> V_74 ) ,
F_84 ( & V_62 -> V_74 ) , F_84 ( & V_55 -> V_219 ) ) ;
return - V_222 ;
}
}
V_37 = F_1 ( V_8 , V_3 ) ;
if ( V_37 )
return V_37 ;
if ( ! F_2 ( V_3 , V_223 ) &&
F_2 ( V_3 , V_7 ) &&
! F_1 ( V_7 , V_3 ) ) {
F_88 ( V_3 , V_223 ) ;
F_89 ( V_214 ) ;
}
if ( ! F_2 ( V_3 , V_224 ) &&
F_2 ( V_3 , V_6 ) &&
! F_1 ( V_6 , V_3 ) ) {
F_88 ( V_3 , V_224 ) ;
F_89 ( V_214 ) ;
F_90 ( V_225 , V_226 ) ;
}
if ( V_3 -> V_85 & V_86 ) {
} else if ( V_3 -> V_85 == V_157 ) {
F_7 ( ! F_2 ( V_3 , V_7 ) ) ;
} else {
F_7 ( V_3 -> V_85 & ( V_161 | V_160 | V_165 ) ) ;
}
V_15 = F_6 ( V_11 ) ;
if ( V_15 ) {
T_2 V_33 = V_15 -> V_26 ;
F_66 ( V_15 , L_18 ) ;
F_9 ( F_91 ( & V_55 -> V_219 ,
& V_15 -> V_19 -> V_227 ) ,
L_19 V_228 L_20 V_212 L_13 ,
F_92 ( V_15 -> V_19 ) , F_84 ( & V_55 -> V_219 ) ) ;
F_11 ( V_15 ) ;
memcpy ( & V_215 , V_11 , sizeof( * V_11 ) ) ;
if ( F_15 ( NULL , V_229 , NULL ,
V_186 , & V_33 , V_205 ,
& V_215 , 0 ) ) {
F_93 ( V_11 ,
V_3 -> V_153 ) ;
memcpy ( V_11 , & V_215 , sizeof( V_215 ) ) ;
V_3 -> V_154 = V_11 -> V_155 ;
}
}
F_83 ( V_221 ,
L_21 ,
V_62 -> V_95 , V_62 -> V_230 , F_67 ( V_3 -> V_85 ) ,
V_3 -> V_5 , V_3 -> F_2 , V_37 ) ;
return V_37 ;
}
int F_94 ( struct V_10 * exp , struct V_2 * V_3 ,
struct V_30 * V_31 , T_1 * V_13 )
{
struct V_35 V_36 ;
struct V_18 V_11 ;
T_2 V_33 ;
enum V_28 V_34 ;
if ( V_3 -> V_154 ) {
V_11 . V_155 = V_3 -> V_154 ;
V_34 = F_95 ( & V_11 , V_13 ) ;
} else {
F_13 ( V_31 , & V_36 ) ;
switch ( V_3 -> V_85 ) {
case V_161 :
V_33 . V_27 . V_13 = V_88 |
V_174 |
V_231 ;
break;
case V_165 :
V_33 . V_27 . V_13 = V_177 ;
break;
default:
V_33 . V_27 . V_13 = V_174 ;
break;
}
V_34 = F_12 ( exp , V_229 , V_31 ,
V_186 , & V_33 ,
V_83 | V_81 | V_79 | V_232 ,
& V_11 ) ;
}
if ( V_34 ) {
V_3 -> V_154 = V_11 . V_155 ;
V_3 -> V_153 = V_34 ;
} else {
V_3 -> V_154 = 0 ;
V_3 -> V_153 = 0 ;
}
return ! ! V_34 ;
}
int F_96 ( struct V_10 * exp , struct V_61 * V_62 ,
void * V_63 , int V_64 , struct V_2 * V_3 ,
int V_233 , struct V_49 * * V_171 ,
T_5 V_234 ,
T_1 V_172 )
{
struct V_135 V_136 = {
. V_185 = V_186 ,
. V_148 = F_97 ( V_3 ) ,
. V_235 = V_234 ,
. V_236 = V_237 ,
} ;
struct V_18 V_11 ;
int V_37 = 0 ;
F_7 ( V_3 ) ;
F_83 ( V_238 , L_22 V_212 L_23 V_212
L_24 , V_62 -> V_95 ,
V_62 -> V_230 , F_84 ( & V_62 -> V_74 ) ,
F_84 ( & V_62 -> V_87 ) , F_67 ( V_3 -> V_85 ) ,
V_3 -> V_75 ) ;
V_11 . V_155 = 0 ;
if ( F_34 ( & V_62 -> V_74 ) &&
( V_3 -> V_85 & ( V_160 | V_161 ) ) ) {
V_3 -> V_154 = 0 ;
V_37 = F_94 ( exp , V_3 , & V_62 -> V_74 , NULL ) ;
if ( V_37 || V_62 -> V_95 != 0 )
return V_37 ;
}
if ( ! F_34 ( & V_62 -> V_74 ) && V_3 -> V_85 & V_86 ) {
V_37 = F_98 ( exp , & V_62 -> V_74 , V_62 ) ;
if ( V_37 < 0 ) {
F_3 ( L_25 , V_37 ) ;
return V_37 ;
}
}
V_37 = F_70 ( exp , & V_136 , V_3 , V_62 , & V_11 , V_63 , V_64 , NULL ,
V_172 ) ;
if ( V_37 < 0 )
return V_37 ;
* V_171 = V_3 -> V_156 ;
V_37 = F_86 ( exp , * V_171 , V_62 , V_3 , & V_11 ) ;
return V_37 ;
}
static int F_99 ( const struct V_239 * V_240 ,
struct V_49 * V_50 ,
void * args , int V_37 )
{
struct V_241 * V_242 = args ;
struct V_10 * exp = V_242 -> V_243 ;
struct V_244 * V_245 = V_242 -> V_246 ;
struct V_135 * V_136 = V_242 -> V_247 ;
struct V_2 * V_3 ;
struct V_18 * V_11 ;
struct V_41 * V_66 ;
struct V_141 * V_142 ;
T_1 V_29 = V_187 ;
V_3 = & V_245 -> V_248 ;
V_11 = & V_245 -> V_249 ;
V_66 = F_16 ( exp ) ;
F_80 ( & V_66 -> V_97 . V_98 ) ;
if ( F_100 ( V_250 ) )
V_37 = - V_204 ;
V_37 = F_101 ( exp , V_50 , V_136 -> V_185 , 1 , V_136 -> V_148 ,
& V_29 , NULL , 0 , V_11 , V_37 ) ;
if ( V_37 < 0 ) {
F_3 ( L_26 , V_37 ) ;
F_26 ( V_50 , V_37 ) ;
goto V_251;
}
V_142 = F_59 ( & V_50 -> V_92 , & V_150 ) ;
V_142 -> V_152 =
F_82 ( V_142 -> V_152 ) ;
V_37 = F_55 ( exp , V_50 , V_136 , V_3 , V_11 , V_37 ) ;
if ( V_37 )
goto V_251;
V_37 = F_86 ( exp , V_50 , & V_245 -> V_252 , V_3 , V_11 ) ;
V_251:
F_102 ( V_136 ) ;
V_245 -> V_253 ( V_50 , V_245 , V_37 ) ;
return 0 ;
}
int F_103 ( struct V_10 * exp ,
struct V_244 * V_245 ,
struct V_135 * V_136 )
{
struct V_61 * V_62 = & V_245 -> V_252 ;
struct V_2 * V_3 = & V_245 -> V_248 ;
struct V_49 * V_50 ;
struct V_241 * V_242 ;
struct V_41 * V_66 = F_16 ( exp ) ;
struct V_35 V_36 ;
T_2 V_33 = {
. V_27 = { V_174 |
V_88 }
} ;
int V_37 = 0 ;
T_1 V_29 = V_187 ;
F_83 ( V_238 ,
L_27 V_212 L_24 ,
V_62 -> V_95 , V_62 -> V_230 , F_84 ( & V_62 -> V_87 ) ,
F_67 ( V_3 -> V_85 ) , V_3 -> V_75 ) ;
F_13 ( & V_62 -> V_87 , & V_36 ) ;
V_50 = F_51 ( exp , V_3 , V_62 ) ;
if ( F_72 ( V_50 ) )
return F_73 ( V_50 ) ;
V_37 = F_76 ( & V_66 -> V_97 . V_98 ) ;
if ( V_37 != 0 ) {
F_78 ( V_50 ) ;
return V_37 ;
}
V_37 = F_79 ( exp , & V_50 , V_136 , & V_36 , & V_33 , & V_29 , NULL ,
0 , V_184 , & V_245 -> V_249 , 1 ) ;
if ( V_37 < 0 ) {
F_80 ( & V_66 -> V_97 . V_98 ) ;
F_78 ( V_50 ) ;
return V_37 ;
}
F_104 ( sizeof( * V_242 ) <= sizeof( V_50 -> V_254 ) ) ;
V_242 = F_105 ( V_50 ) ;
V_242 -> V_243 = exp ;
V_242 -> V_246 = V_245 ;
V_242 -> V_247 = V_136 ;
V_50 -> V_255 = F_99 ;
F_106 ( V_50 ) ;
return 0 ;
}
