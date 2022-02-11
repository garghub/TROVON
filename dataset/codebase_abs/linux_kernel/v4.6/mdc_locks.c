int F_1 ( struct V_1 * V_2 , int V_3 )
{
return V_2 -> V_4 . V_5 . F_1 & V_3 ;
}
void F_2 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 . V_5 . F_1 |= V_3 ;
}
void F_3 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 . V_5 . F_1 &= ~ V_3 ;
}
int F_4 ( int V_6 , struct V_1 * V_2 )
{
if ( F_1 ( V_2 , V_7 ) ) {
if ( V_6 >= V_7 )
return V_2 -> V_4 . V_5 . V_8 ;
else
return 0 ;
}
if ( F_1 ( V_2 , V_9 ) ) {
if ( V_6 >= V_9 )
return V_2 -> V_4 . V_5 . V_8 ;
else
return 0 ;
}
if ( F_1 ( V_2 , V_10 ) ) {
if ( V_6 >= V_10 )
return V_2 -> V_4 . V_5 . V_8 ;
else
return 0 ;
}
if ( F_1 ( V_2 , V_11 ) ) {
if ( V_6 >= V_11 )
return V_2 -> V_4 . V_5 . V_8 ;
else
return 0 ;
}
if ( F_1 ( V_2 , V_12 ) ) {
if ( V_6 >= V_12 )
return V_2 -> V_4 . V_5 . V_8 ;
else
return 0 ;
}
F_5 ( L_1 , V_2 -> V_4 . V_5 . F_1 ,
V_2 -> V_4 . V_5 . V_8 ) ;
F_6 () ;
return 0 ;
}
int F_7 ( struct V_13 * exp , T_1 * V_14 , void * V_15 ,
T_1 * V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 = V_15 ;
if ( V_16 )
* V_16 = 0 ;
if ( ! * V_14 )
return 0 ;
V_18 = F_8 ( (struct V_21 * ) V_14 ) ;
F_9 ( V_18 ) ;
F_10 ( V_18 ) ;
if ( V_18 -> V_22 -> V_23 &&
V_18 -> V_22 -> V_23 != V_15 ) {
struct V_19 * V_24 = V_18 -> V_22 -> V_23 ;
F_11 ( V_24 -> V_25 & V_26 ,
L_2 ,
V_24 , V_24 -> V_27 , V_24 -> V_28 ,
V_24 -> V_25 , V_20 , V_20 -> V_27 ,
V_20 -> V_28 ) ;
}
V_18 -> V_22 -> V_23 = V_20 ;
if ( V_16 )
* V_16 = V_18 -> V_29 . V_30 . V_16 ;
F_12 ( V_18 ) ;
F_13 ( V_18 ) ;
return 0 ;
}
enum V_31 F_14 ( struct V_13 * exp , T_1 V_32 ,
const struct V_33 * V_34 , enum V_35 type ,
T_2 * V_36 , enum V_31 V_37 ,
struct V_21 * V_14 )
{
struct V_38 V_39 ;
enum V_31 V_40 ;
F_15 ( V_34 , & V_39 ) ;
V_36 -> V_30 . V_16 &= F_16 ( exp ) ;
V_40 = F_17 ( F_18 ( exp ) -> V_41 , V_32 ,
& V_39 , type , V_36 , V_37 , V_14 , 0 ) ;
return V_40 ;
}
int F_19 ( struct V_13 * exp ,
const struct V_33 * V_34 ,
T_2 * V_36 ,
enum V_31 V_37 ,
enum V_42 V_32 ,
void * V_43 )
{
struct V_38 V_39 ;
struct V_44 * V_45 = F_18 ( exp ) ;
int V_40 ;
F_15 ( V_34 , & V_39 ) ;
V_40 = F_20 ( V_45 -> V_41 , & V_39 ,
V_36 , V_37 , V_32 , V_43 ) ;
return V_40 ;
}
int F_21 ( struct V_13 * exp ,
const struct V_33 * V_34 )
{
struct V_38 V_39 ;
struct V_46 * V_47 ;
struct V_48 * V_49 = F_18 ( exp ) -> V_41 ;
F_11 ( V_49 , L_3 ) ;
F_15 ( V_34 , & V_39 ) ;
V_47 = F_22 ( V_49 , NULL , & V_39 , 0 , 0 ) ;
if ( ! V_47 )
return 0 ;
F_23 ( V_47 ) ;
V_47 -> V_23 = NULL ;
F_24 ( V_47 ) ;
F_25 ( V_47 ) ;
return 0 ;
}
int F_26 ( struct V_13 * exp ,
const struct V_33 * V_34 ,
T_3 V_2 , void * V_15 )
{
struct V_38 V_39 ;
int V_40 = 0 ;
F_15 ( (struct V_33 * ) V_34 , & V_39 ) ;
V_40 = F_27 ( F_18 ( exp ) -> V_41 , & V_39 ,
V_2 , V_15 ) ;
if ( V_40 == V_50 )
return 1 ;
else if ( V_40 == V_51 )
return 0 ;
return V_40 ;
}
static inline void F_28 ( struct V_52 * V_53 , int V_40 )
{
if ( V_53 -> V_54 ) {
F_29 ( & V_53 -> V_55 ) ;
V_53 -> V_54 = 0 ;
F_30 ( & V_53 -> V_55 ) ;
}
if ( V_40 && V_53 -> V_56 != 0 ) {
F_31 ( V_57 , V_53 , L_4 , V_40 ) ;
F_6 () ;
}
}
static void F_32 ( struct V_52 * V_53 ,
struct V_58 * V_59 )
{
int V_40 ;
V_40 = F_33 ( V_53 , V_60 + 4 ,
V_59 -> V_61 ) ;
if ( V_40 ) {
F_5 ( L_5 ,
V_60 + 4 , V_59 -> V_61 ) ;
V_59 -> V_62 &= ~ V_63 ;
V_59 -> V_61 = 0 ;
}
}
static struct V_52 * F_34 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_64 * V_65 ,
void * V_66 , int V_67 ,
void * V_68 )
{
struct V_52 * V_53 ;
struct V_44 * V_69 = F_18 ( exp ) ;
struct V_70 * V_71 ;
F_35 ( V_72 ) ;
int V_73 = 0 ;
int V_37 ;
int V_40 ;
V_2 -> V_74 = ( V_2 -> V_74 & ~ V_75 ) | V_76 ;
if ( F_36 ( & V_65 -> V_77 ) ) {
if ( V_2 -> V_78 & V_79 ) {
if ( V_2 -> V_78 & V_80 )
V_37 = V_81 ;
else
V_37 = V_82 ;
} else {
if ( V_2 -> V_78 & ( V_80 | V_83 ) )
V_37 = V_84 ;
else if ( V_2 -> V_78 & V_85 )
V_37 = V_82 ;
else
V_37 = V_86 ;
}
V_73 = F_37 ( exp , & V_65 -> V_77 ,
& V_72 , V_37 ,
V_87 ) ;
}
if ( V_2 -> V_88 & V_89 )
V_37 = V_81 ;
else
V_37 = V_86 ;
V_73 += F_37 ( exp , & V_65 -> V_90 ,
& V_72 , V_37 ,
V_91 ) ;
V_53 = F_38 ( F_39 ( exp ) ,
& V_92 ) ;
if ( ! V_53 ) {
F_40 ( & V_72 , V_93 , V_73 ) ;
return F_41 ( - V_94 ) ;
}
F_42 ( & V_53 -> V_95 , & V_96 , V_97 ,
V_65 -> V_98 + 1 ) ;
F_42 ( & V_53 -> V_95 , & V_99 , V_97 ,
F_43 ( V_67 , V_69 -> V_100 . V_101 . V_102 ) ) ;
V_40 = F_44 ( exp , V_53 , & V_72 , V_73 ) ;
if ( V_40 < 0 ) {
F_45 ( V_53 ) ;
return F_41 ( V_40 ) ;
}
F_29 ( & V_53 -> V_55 ) ;
V_53 -> V_54 = V_53 -> V_103 -> V_104 ;
F_30 ( & V_53 -> V_55 ) ;
V_71 = F_46 ( & V_53 -> V_95 , & V_105 ) ;
V_71 -> V_106 = ( T_1 ) V_2 -> V_88 ;
F_47 ( V_53 , V_65 , V_2 -> V_74 , 0 , V_2 -> V_78 , V_66 ,
V_67 ) ;
if ( F_48 ( exp ) )
F_42 ( & V_53 -> V_95 , & V_107 , V_108 ,
sizeof( struct V_109 ) ) ;
F_49 ( V_53 ) ;
return V_53 ;
}
static struct V_52 *
F_50 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_52 * V_53 ;
struct V_70 * V_71 ;
int V_40 , V_73 = 0 , V_110 ;
F_35 ( V_72 ) ;
V_53 = F_38 ( F_39 ( exp ) ,
& V_111 ) ;
if ( ! V_53 )
return F_41 ( - V_94 ) ;
V_40 = F_44 ( exp , V_53 , & V_72 , V_73 ) ;
if ( V_40 ) {
F_45 ( V_53 ) ;
return F_41 ( V_40 ) ;
}
V_71 = F_46 ( & V_53 -> V_95 , & V_105 ) ;
V_71 -> V_106 = V_112 ;
V_110 = F_39 ( exp ) -> V_113 . V_114 ;
F_51 ( V_53 , & V_65 -> V_90 , V_65 -> V_115 , V_110 , - 1 ,
0 ) ;
F_42 ( & V_53 -> V_95 , & V_99 , V_108 , V_110 ) ;
F_42 ( & V_53 -> V_95 , & V_116 , V_108 , V_110 ) ;
F_42 ( & V_53 -> V_95 , & V_117 ,
V_108 , V_110 ) ;
F_49 ( V_53 ) ;
return V_53 ;
}
static struct V_52 * F_52 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_52 * V_53 ;
struct V_44 * V_69 = F_18 ( exp ) ;
struct V_70 * V_71 ;
int V_40 ;
V_53 = F_38 ( F_39 ( exp ) ,
& V_118 ) ;
if ( ! V_53 )
return F_41 ( - V_94 ) ;
F_42 ( & V_53 -> V_95 , & V_96 , V_97 ,
V_65 -> V_98 + 1 ) ;
V_40 = F_44 ( exp , V_53 , NULL , 0 ) ;
if ( V_40 ) {
F_45 ( V_53 ) ;
return F_41 ( V_40 ) ;
}
V_71 = F_46 ( & V_53 -> V_95 , & V_105 ) ;
V_71 -> V_106 = ( T_1 ) V_2 -> V_88 ;
F_53 ( V_53 , V_65 ) ;
F_42 ( & V_53 -> V_95 , & V_119 , V_108 ,
V_69 -> V_100 . V_101 . V_102 ) ;
F_42 ( & V_53 -> V_95 , & V_107 , V_108 ,
V_69 -> V_100 . V_101 . V_120 ) ;
F_49 ( V_53 ) ;
return V_53 ;
}
static struct V_52 * F_54 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_52 * V_53 ;
struct V_44 * V_69 = F_18 ( exp ) ;
T_4 V_62 = V_121 | V_63 |
V_122 | V_123 |
V_124 |
( F_48 ( exp ) ?
V_125 : V_126 ) ;
struct V_70 * V_71 ;
int V_40 ;
int V_127 ;
V_53 = F_38 ( F_39 ( exp ) ,
& V_128 ) ;
if ( ! V_53 )
return F_41 ( - V_94 ) ;
F_42 ( & V_53 -> V_95 , & V_96 , V_97 ,
V_65 -> V_98 + 1 ) ;
V_40 = F_44 ( exp , V_53 , NULL , 0 ) ;
if ( V_40 ) {
F_45 ( V_53 ) ;
return F_41 ( V_40 ) ;
}
V_71 = F_46 ( & V_53 -> V_95 , & V_105 ) ;
V_71 -> V_106 = ( T_1 ) V_2 -> V_88 ;
if ( V_69 -> V_100 . V_101 . V_102 > 0 )
V_127 = V_69 -> V_100 . V_101 . V_102 ;
else
V_127 = V_69 -> V_100 . V_101 . V_129 ;
F_55 ( V_53 , V_62 , V_2 -> V_78 , V_65 , V_127 ) ;
F_42 ( & V_53 -> V_95 , & V_119 , V_108 , V_127 ) ;
if ( F_48 ( exp ) )
F_42 ( & V_53 -> V_95 , & V_107 , V_108 ,
sizeof( struct V_109 ) ) ;
F_49 ( V_53 ) ;
return V_53 ;
}
static struct V_52 * F_56 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_64 * V_130 )
{
struct V_44 * V_45 = F_18 ( exp ) ;
struct V_52 * V_53 ;
struct V_70 * V_71 ;
struct V_131 * V_132 ;
int V_40 ;
V_53 = F_38 ( F_39 ( exp ) ,
& V_133 ) ;
if ( ! V_53 )
return F_41 ( - V_94 ) ;
F_42 ( & V_53 -> V_95 , & V_99 , V_97 , 0 ) ;
V_40 = F_44 ( exp , V_53 , NULL , 0 ) ;
if ( V_40 ) {
F_45 ( V_53 ) ;
return F_41 ( V_40 ) ;
}
V_71 = F_46 ( & V_53 -> V_95 , & V_105 ) ;
V_71 -> V_106 = ( T_1 ) V_2 -> V_88 ;
V_132 = F_46 ( & V_53 -> V_95 , & V_134 ) ;
V_132 -> V_135 = V_136 ;
F_42 ( & V_53 -> V_95 , & V_137 , V_108 ,
V_45 -> V_100 . V_101 . V_102 ) ;
F_49 ( V_53 ) ;
return V_53 ;
}
static struct V_52 *
F_57 ( struct V_13 * exp , int V_138 )
{
struct V_52 * V_53 ;
int V_40 ;
V_53 = F_38 ( F_39 ( exp ) , & V_139 ) ;
if ( ! V_53 )
return F_41 ( - V_94 ) ;
V_40 = F_44 ( exp , V_53 , NULL , 0 ) ;
if ( V_40 ) {
F_45 ( V_53 ) ;
return F_41 ( V_40 ) ;
}
F_42 ( & V_53 -> V_95 , & V_137 , V_108 , V_138 ) ;
F_49 ( V_53 ) ;
return V_53 ;
}
static int F_58 ( struct V_13 * exp ,
struct V_52 * V_53 ,
struct V_140 * V_141 ,
struct V_1 * V_2 ,
struct V_21 * V_14 ,
int V_40 )
{
struct V_142 * V_143 = & V_53 -> V_95 ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
struct V_148 * V_149 = & V_2 -> V_4 . V_5 ;
struct V_17 * V_18 ;
void * V_150 = NULL ;
int V_138 = 0 ;
F_9 ( V_40 >= 0 ) ;
if ( V_53 -> V_56 || V_53 -> V_54 ) {
V_145 = F_46 ( V_143 , & V_151 ) ;
V_145 -> V_152 |= F_59 ( V_153 ) ;
}
if ( V_40 == V_154 ) {
V_141 -> V_155 = 0 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_40 = 0 ;
} else {
V_18 = F_8 ( V_14 ) ;
if ( V_18 -> V_156 != V_141 -> V_155 ) {
F_60 ( V_14 , V_18 -> V_156 ) ;
F_61 ( V_14 , V_141 -> V_155 ) ;
V_141 -> V_155 = V_18 -> V_156 ;
}
F_13 ( V_18 ) ;
}
V_147 = F_62 ( V_143 , & V_157 ) ;
V_149 -> F_1 = ( int ) V_147 -> V_158 ;
V_149 -> V_8 = ( int ) V_147 -> V_159 ;
V_149 -> V_160 = V_141 -> V_155 ;
V_149 -> V_161 = V_14 -> V_162 ;
V_149 -> V_163 = V_53 ;
if ( ( ! V_53 -> V_56 || V_149 -> V_8 < 0 ) && V_53 -> V_54 )
F_28 ( V_53 , V_149 -> V_8 ) ;
if ( V_2 -> V_88 & V_164 && V_53 -> V_54 &&
( ! F_1 ( V_2 , V_9 ) || V_149 -> V_8 != 0 ) )
F_28 ( V_53 , V_149 -> V_8 ) ;
F_31 ( V_165 , V_53 , L_6 ,
V_2 -> V_88 , V_149 -> F_1 , V_149 -> V_8 ) ;
if ( V_2 -> V_88 & ( V_164 | V_166 | V_167 | V_168 ) ) {
struct V_58 * V_59 ;
V_59 = F_62 ( V_143 , & V_169 ) ;
if ( ! V_59 ) {
F_5 ( L_7 ) ;
return - V_170 ;
}
if ( F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_63 ( NULL , NULL , V_2 ) ;
}
if ( ( V_59 -> V_62 & ( V_123 | V_63 ) ) != 0 ) {
void * V_171 ;
F_64 ( exp , V_59 ) ;
V_171 = F_65 ( V_143 , & V_119 ,
V_59 -> V_61 ) ;
if ( ! V_171 )
return - V_170 ;
V_150 = V_171 ;
V_138 = V_59 -> V_61 ;
if ( ( V_2 -> V_88 & V_164 ) && V_53 -> V_54 ) {
void * V_66 ;
if ( F_66 ( V_143 , & V_99 ,
V_97 ) <
V_59 -> V_61 )
F_32 ( V_53 , V_59 ) ;
else
F_67 ( V_143 , & V_99 ,
V_59 -> V_61 ,
V_97 ) ;
F_42 ( V_143 , & V_99 ,
V_97 ,
V_59 -> V_61 ) ;
V_66 = F_46 ( V_143 , & V_99 ) ;
if ( V_66 )
memcpy ( V_66 , V_171 , V_59 -> V_61 ) ;
}
}
if ( V_59 -> V_62 & V_125 ) {
struct V_109 * V_172 ;
F_9 ( F_48 ( exp ) ) ;
V_172 = F_68 ( V_143 , & V_107 ,
V_173 ) ;
if ( ! V_172 )
return - V_170 ;
}
} else if ( V_2 -> V_88 & V_174 ) {
V_138 = F_66 ( V_143 , & V_137 , V_108 ) ;
if ( V_138 > 0 ) {
V_150 = F_65 ( V_143 ,
& V_137 , V_138 ) ;
if ( ! V_150 )
return - V_170 ;
}
}
V_18 = F_8 ( V_14 ) ;
if ( V_18 && F_69 ( V_18 ) && V_150 ) {
void * V_66 ;
F_70 ( V_18 , L_8 ,
F_71 ( V_2 -> V_88 ) , V_138 ) ;
V_66 = F_72 ( V_138 , V_175 ) ;
if ( ! V_66 ) {
F_13 ( V_18 ) ;
return - V_94 ;
}
memcpy ( V_66 , V_150 , V_138 ) ;
F_10 ( V_18 ) ;
if ( ! V_18 -> V_176 ) {
V_18 -> V_177 = V_178 ;
V_18 -> V_176 = V_66 ;
V_18 -> V_179 = V_138 ;
V_66 = NULL ;
}
F_12 ( V_18 ) ;
if ( V_66 )
F_73 ( V_66 ) ;
}
if ( V_18 )
F_13 ( V_18 ) ;
return V_40 ;
}
int F_74 ( struct V_13 * exp , struct V_140 * V_141 ,
struct V_1 * V_2 , struct V_64 * V_65 ,
struct V_21 * V_14 , void * V_66 , int V_67 ,
struct V_52 * * V_180 , T_4 V_181 )
{
static const T_2 V_182 = {
. V_30 = { V_183 }
} ;
static const T_2 V_184 = {
. V_30 = { V_91 }
} ;
static const T_2 V_185 = {
. V_30 = { V_186 }
} ;
static const T_2 V_187 = {
. V_30 = { V_188 }
} ;
T_2 const * V_36 = & V_182 ;
struct V_44 * V_69 = F_18 ( exp ) ;
struct V_52 * V_53 ;
T_4 V_32 , V_189 = V_181 ;
struct V_38 V_39 ;
int V_190 , V_191 = 0 ;
struct V_146 * V_147 ;
enum V_192 V_192 = V_193 ;
int V_40 ;
F_11 ( ! V_2 || V_141 -> V_194 == V_195 , L_9 ,
V_141 -> V_194 ) ;
F_15 ( & V_65 -> V_90 , & V_39 ) ;
if ( V_2 ) {
V_189 |= V_196 ;
if ( V_2 -> V_88 & ( V_166 | V_168 | V_197 ) )
V_36 = & V_184 ;
else if ( V_2 -> V_88 & V_174 )
V_36 = & V_185 ;
else if ( V_2 -> V_88 & ( V_112 | V_198 ) )
V_36 = & V_187 ;
}
F_9 ( ! V_180 ) ;
V_190 = V_69 -> V_100 . V_101 . V_199 -> V_200 ;
V_201:
V_32 = V_189 ;
if ( ! V_2 ) {
F_9 ( V_66 && V_67 == 0 ) ;
F_11 ( V_141 -> V_194 == V_202 , L_9 ,
V_141 -> V_194 ) ;
V_36 = V_66 ;
V_39 . V_203 [ 3 ] = V_202 ;
V_53 = NULL ;
} else if ( V_2 -> V_88 & V_164 ) {
V_53 = F_34 ( exp , V_2 , V_65 , V_66 , V_67 ,
V_141 -> V_204 ) ;
V_36 = & V_184 ;
V_141 -> V_204 = NULL ;
V_66 = NULL ;
} else if ( V_2 -> V_88 & V_166 ) {
V_53 = F_52 ( exp , V_2 , V_65 ) ;
} else if ( V_2 -> V_88 & ( V_168 | V_167 ) ) {
V_53 = F_54 ( exp , V_2 , V_65 ) ;
} else if ( V_2 -> V_88 & V_197 ) {
V_53 = F_57 ( exp , 0 ) ;
} else if ( V_2 -> V_88 & V_174 ) {
if ( ! F_75 ( F_39 ( exp ) ) )
return - V_205 ;
V_53 = F_56 ( exp , V_2 , V_65 ) ;
V_192 = V_178 ;
} else if ( V_2 -> V_88 & V_112 ) {
V_53 = F_50 ( exp , V_2 , V_65 ) ;
} else {
F_6 () ;
return - V_206 ;
}
if ( F_76 ( V_53 ) )
return F_77 ( V_53 ) ;
if ( V_53 && V_2 && V_2 -> V_88 & V_89 )
V_53 -> V_207 = 1 ;
if ( V_191 ) {
V_53 -> V_208 = 1 ;
V_53 -> V_209 = V_190 ;
V_53 -> V_210 = F_78 () + V_191 ;
}
if ( V_2 ) {
F_79 ( V_69 -> V_100 . V_101 . V_211 , V_2 ) ;
V_40 = F_80 ( & V_69 -> V_100 . V_101 ) ;
if ( V_40 != 0 ) {
F_81 ( V_69 -> V_100 . V_101 . V_211 , V_2 ) ;
F_28 ( V_53 , 0 ) ;
F_82 ( V_53 ) ;
return V_40 ;
}
}
V_40 = F_83 ( exp , & V_53 , V_141 , & V_39 , V_36 , & V_32 , NULL ,
0 , V_192 , V_14 , 0 ) ;
if ( ! V_2 ) {
if ( ( V_40 == - V_212 ) || ( V_40 == - V_213 ) )
goto V_201;
return V_40 ;
}
F_84 ( & V_69 -> V_100 . V_101 ) ;
F_81 ( V_69 -> V_100 . V_101 . V_211 , V_2 ) ;
if ( V_40 < 0 ) {
F_85 ( ( V_40 == - V_214 || V_40 == - V_215 ) ? V_216 : V_57 ,
L_10 ,
V_69 -> V_217 , V_40 ) ;
F_28 ( V_53 , V_40 ) ;
F_82 ( V_53 ) ;
return V_40 ;
}
V_147 = F_62 ( & V_53 -> V_95 , & V_157 ) ;
V_147 -> V_159 =
F_86 ( V_147 -> V_159 ) ;
if ( V_2 -> V_88 & V_89 &&
( int ) V_147 -> V_159 == - V_218 ) {
F_28 ( V_53 , V_40 ) ;
F_82 ( V_53 ) ;
V_191 ++ ;
F_87 ( V_219 , L_11 V_220 L_12 V_220 L_13 ,
V_69 -> V_217 , V_191 , V_2 -> V_88 ,
F_88 ( & V_65 -> V_90 ) , F_88 ( & V_65 -> V_77 ) ) ;
if ( V_190 == V_69 -> V_100 . V_101 . V_199 -> V_200 ) {
goto V_201;
} else {
F_87 ( V_219 , L_14 ) ;
return - V_221 ;
}
}
V_40 = F_58 ( exp , V_53 , V_141 , V_2 , V_14 , V_40 ) ;
if ( V_40 < 0 ) {
if ( F_89 ( V_14 ) ) {
F_61 ( V_14 , V_141 -> V_155 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
}
F_82 ( V_53 ) ;
V_2 -> V_4 . V_5 . V_161 = 0 ;
V_2 -> V_4 . V_5 . V_160 = 0 ;
V_2 -> V_4 . V_5 . V_163 = NULL ;
}
return V_40 ;
}
static int F_90 ( struct V_13 * exp ,
struct V_52 * V_222 ,
struct V_64 * V_65 ,
struct V_1 * V_2 ,
struct V_21 * V_14 )
{
struct V_21 V_223 ;
struct V_58 * V_58 ;
struct V_17 * V_18 ;
int V_40 ;
F_9 ( V_222 != V_224 ) ;
F_9 ( V_222 -> V_225 != V_224 ) ;
if ( ! F_1 ( V_2 , V_12 ) ) {
F_9 ( V_2 -> V_4 . V_5 . V_8 != 0 ) ;
return V_2 -> V_4 . V_5 . V_8 ;
}
V_40 = F_4 ( V_12 , V_2 ) ;
if ( V_40 )
return V_40 ;
V_58 = F_62 ( & V_222 -> V_95 , & V_169 ) ;
F_9 ( V_58 ) ;
if ( F_36 ( & V_65 -> V_77 ) &&
V_2 -> V_74 & V_226 &&
V_2 -> V_88 != V_168 ) {
if ( ( ! F_91 ( & V_65 -> V_77 , & V_58 -> V_227 ) ) &&
( ! F_91 ( & V_65 -> V_228 , & V_58 -> V_227 ) ) ) {
F_87 ( V_229 , L_15 V_220 L_16 V_220 L_17 V_220
L_13 , F_88 ( & V_65 -> V_77 ) ,
F_88 ( & V_65 -> V_77 ) , F_88 ( & V_58 -> V_227 ) ) ;
return - V_230 ;
}
}
V_40 = F_4 ( V_11 , V_2 ) ;
if ( V_40 )
return V_40 ;
if ( ! F_1 ( V_2 , V_231 ) &&
F_1 ( V_2 , V_10 ) &&
! F_4 ( V_10 , V_2 ) ) {
F_2 ( V_2 , V_231 ) ;
F_92 ( V_222 ) ;
}
if ( ! F_1 ( V_2 , V_232 ) &&
F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_2 ( V_2 , V_232 ) ;
F_92 ( V_222 ) ;
F_93 ( V_233 , V_234 ) ;
}
if ( V_2 -> V_88 & V_89 ) {
} else if ( V_2 -> V_88 == V_164 ) {
F_9 ( ! F_1 ( V_2 , V_10 ) ) ;
} else {
F_9 ( V_2 -> V_88 & ( V_168 | V_167 | V_174 ) ) ;
}
V_18 = F_8 ( V_14 ) ;
if ( V_18 ) {
T_2 V_36 = V_18 -> V_29 ;
F_70 ( V_18 , L_18 ) ;
F_11 ( F_94 ( & V_58 -> V_227 ,
& V_18 -> V_22 -> V_235 ) ,
L_19 V_236 L_20 V_220 L_13 ,
F_95 ( V_18 -> V_22 ) , F_88 ( & V_58 -> V_227 ) ) ;
F_13 ( V_18 ) ;
memcpy ( & V_223 , V_14 , sizeof( * V_14 ) ) ;
if ( F_17 ( NULL , V_237 , NULL ,
V_195 , & V_36 , V_238 ,
& V_223 , 0 ) ) {
F_96 ( V_14 ,
V_2 -> V_4 . V_5 . V_160 ) ;
memcpy ( V_14 , & V_223 , sizeof( V_223 ) ) ;
V_2 -> V_4 . V_5 . V_161 = V_14 -> V_162 ;
}
}
F_87 ( V_229 ,
L_21 ,
V_65 -> V_98 , V_65 -> V_239 , F_71 ( V_2 -> V_88 ) ,
V_2 -> V_4 . V_5 . V_8 , V_2 -> V_4 . V_5 . F_1 , V_40 ) ;
return V_40 ;
}
int F_97 ( struct V_13 * exp , struct V_1 * V_2 ,
struct V_33 * V_34 , T_1 * V_16 )
{
struct V_38 V_39 ;
struct V_21 V_14 ;
T_2 V_36 ;
enum V_31 V_37 ;
if ( V_2 -> V_4 . V_5 . V_161 ) {
V_14 . V_162 = V_2 -> V_4 . V_5 . V_161 ;
V_37 = F_98 ( & V_14 , V_16 ) ;
} else {
F_15 ( V_34 , & V_39 ) ;
switch ( V_2 -> V_88 ) {
case V_168 :
V_36 . V_30 . V_16 = V_91 |
V_183 |
V_240 ;
break;
case V_174 :
V_36 . V_30 . V_16 = V_186 ;
break;
default:
V_36 . V_30 . V_16 = V_183 ;
break;
}
V_37 = F_14 ( exp , V_237 , V_34 ,
V_195 , & V_36 ,
V_86 | V_84 | V_82 | V_241 ,
& V_14 ) ;
}
if ( V_37 ) {
V_2 -> V_4 . V_5 . V_161 = V_14 . V_162 ;
V_2 -> V_4 . V_5 . V_160 = V_37 ;
} else {
V_2 -> V_4 . V_5 . V_161 = 0 ;
V_2 -> V_4 . V_5 . V_160 = 0 ;
}
return ! ! V_37 ;
}
int F_99 ( struct V_13 * exp , struct V_64 * V_65 ,
void * V_66 , int V_67 , struct V_1 * V_2 ,
int V_242 , struct V_52 * * V_180 ,
T_5 V_243 ,
T_1 V_181 )
{
struct V_140 V_141 = {
. V_194 = V_195 ,
. V_155 = F_100 ( V_2 ) ,
. V_244 = V_243 ,
. V_245 = V_246 ,
} ;
struct V_21 V_14 ;
int V_40 = 0 ;
F_9 ( V_2 ) ;
F_87 ( V_247 , L_22 V_220 L_23 V_220
L_24 , V_65 -> V_98 ,
V_65 -> V_239 , F_88 ( & V_65 -> V_77 ) ,
F_88 ( & V_65 -> V_90 ) , F_71 ( V_2 -> V_88 ) ,
V_2 -> V_78 ) ;
V_14 . V_162 = 0 ;
if ( F_36 ( & V_65 -> V_77 ) &&
( V_2 -> V_88 & ( V_167 | V_168 ) ) ) {
V_2 -> V_4 . V_5 . V_161 = 0 ;
V_40 = F_97 ( exp , V_2 , & V_65 -> V_77 , NULL ) ;
if ( V_40 || V_65 -> V_98 != 0 )
return V_40 ;
}
if ( ! F_36 ( & V_65 -> V_77 ) && V_2 -> V_88 & V_89 ) {
V_40 = F_101 ( exp , & V_65 -> V_77 , V_65 ) ;
if ( V_40 < 0 ) {
F_5 ( L_25 , V_40 ) ;
return V_40 ;
}
}
V_40 = F_74 ( exp , & V_141 , V_2 , V_65 , & V_14 , V_66 , V_67 , NULL ,
V_181 ) ;
if ( V_40 < 0 )
return V_40 ;
* V_180 = V_2 -> V_4 . V_5 . V_163 ;
V_40 = F_90 ( exp , * V_180 , V_65 , V_2 , & V_14 ) ;
return V_40 ;
}
static int F_102 ( const struct V_248 * V_249 ,
struct V_52 * V_53 ,
void * args , int V_40 )
{
struct V_250 * V_251 = args ;
struct V_13 * exp = V_251 -> V_252 ;
struct V_253 * V_254 = V_251 -> V_255 ;
struct V_140 * V_141 = V_251 -> V_256 ;
struct V_1 * V_2 ;
struct V_21 * V_14 ;
struct V_44 * V_69 ;
struct V_146 * V_147 ;
T_1 V_32 = V_196 ;
V_2 = & V_254 -> V_257 ;
V_14 = & V_254 -> V_258 ;
V_69 = F_18 ( exp ) ;
F_84 ( & V_69 -> V_100 . V_101 ) ;
if ( F_103 ( V_259 ) )
V_40 = - V_213 ;
V_40 = F_104 ( exp , V_53 , V_141 -> V_194 , 1 , V_141 -> V_155 ,
& V_32 , NULL , 0 , V_14 , V_40 ) ;
if ( V_40 < 0 ) {
F_5 ( L_26 , V_40 ) ;
F_28 ( V_53 , V_40 ) ;
goto V_260;
}
V_147 = F_62 ( & V_53 -> V_95 , & V_157 ) ;
V_147 -> V_159 =
F_86 ( V_147 -> V_159 ) ;
V_40 = F_58 ( exp , V_53 , V_141 , V_2 , V_14 , V_40 ) ;
if ( V_40 )
goto V_260;
V_40 = F_90 ( exp , V_53 , & V_254 -> V_261 , V_2 , V_14 ) ;
V_260:
F_105 ( V_141 ) ;
V_254 -> V_262 ( V_53 , V_254 , V_40 ) ;
return 0 ;
}
int F_106 ( struct V_13 * exp ,
struct V_253 * V_254 ,
struct V_140 * V_141 )
{
struct V_64 * V_65 = & V_254 -> V_261 ;
struct V_1 * V_2 = & V_254 -> V_257 ;
struct V_52 * V_53 ;
struct V_250 * V_251 ;
struct V_44 * V_69 = F_18 ( exp ) ;
struct V_38 V_39 ;
T_2 V_36 = {
. V_30 = { V_183 |
V_91 }
} ;
int V_40 = 0 ;
T_1 V_32 = V_196 ;
F_87 ( V_247 ,
L_27 V_220 L_24 ,
V_65 -> V_98 , V_65 -> V_239 , F_88 ( & V_65 -> V_90 ) ,
F_71 ( V_2 -> V_88 ) , V_2 -> V_78 ) ;
F_15 ( & V_65 -> V_90 , & V_39 ) ;
V_53 = F_54 ( exp , V_2 , V_65 ) ;
if ( F_76 ( V_53 ) )
return F_77 ( V_53 ) ;
V_40 = F_80 ( & V_69 -> V_100 . V_101 ) ;
if ( V_40 != 0 ) {
F_82 ( V_53 ) ;
return V_40 ;
}
V_40 = F_83 ( exp , & V_53 , V_141 , & V_39 , & V_36 , & V_32 , NULL ,
0 , V_193 , & V_254 -> V_258 , 1 ) ;
if ( V_40 < 0 ) {
F_84 ( & V_69 -> V_100 . V_101 ) ;
F_82 ( V_53 ) ;
return V_40 ;
}
F_107 ( sizeof( * V_251 ) <= sizeof( V_53 -> V_263 ) ) ;
V_251 = F_108 ( V_53 ) ;
V_251 -> V_252 = exp ;
V_251 -> V_255 = V_254 ;
V_251 -> V_256 = V_141 ;
V_53 -> V_264 = F_102 ;
F_109 ( V_53 ) ;
return 0 ;
}
