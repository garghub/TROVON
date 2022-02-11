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
F_9 ( V_18 != NULL ) ;
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
T_2 F_14 ( struct V_13 * exp , T_1 V_31 ,
const struct V_32 * V_33 , T_3 type ,
T_4 * V_34 , T_2 V_35 ,
struct V_21 * V_14 )
{
struct V_36 V_37 ;
T_2 V_38 ;
F_15 ( V_33 , & V_37 ) ;
V_34 -> V_30 . V_16 &= F_16 ( exp ) ;
V_38 = F_17 ( F_18 ( exp ) -> V_39 , V_31 ,
& V_37 , type , V_34 , V_35 , V_14 , 0 ) ;
return V_38 ;
}
int F_19 ( struct V_13 * exp ,
const struct V_32 * V_33 ,
T_4 * V_34 ,
T_2 V_35 ,
T_5 V_31 ,
void * V_40 )
{
struct V_36 V_37 ;
struct V_41 * V_42 = F_18 ( exp ) ;
int V_38 ;
F_15 ( V_33 , & V_37 ) ;
V_38 = F_20 ( V_42 -> V_39 , & V_37 ,
V_34 , V_35 , V_31 , V_40 ) ;
return V_38 ;
}
int F_21 ( struct V_13 * exp ,
const struct V_32 * V_33 )
{
struct V_36 V_37 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = F_18 ( exp ) -> V_39 ;
F_11 ( V_46 != NULL , L_3 ) ;
F_15 ( V_33 , & V_37 ) ;
V_44 = F_22 ( V_46 , NULL , & V_37 , 0 , 0 ) ;
if ( V_44 == NULL )
return 0 ;
F_23 ( V_44 ) ;
V_44 -> V_23 = NULL ;
F_24 ( V_44 ) ;
F_25 ( V_44 ) ;
return 0 ;
}
int F_26 ( struct V_13 * exp ,
const struct V_32 * V_33 ,
T_6 V_2 , void * V_15 )
{
struct V_36 V_37 ;
int V_38 = 0 ;
F_15 ( (struct V_32 * ) V_33 , & V_37 ) ;
V_38 = F_27 ( F_18 ( exp ) -> V_39 , & V_37 ,
V_2 , V_15 ) ;
if ( V_38 == V_47 )
return 1 ;
else if ( V_38 == V_48 )
return 0 ;
return V_38 ;
}
static inline void F_28 ( struct V_49 * V_50 , int V_38 )
{
if ( V_50 -> V_51 ) {
F_29 ( & V_50 -> V_52 ) ;
V_50 -> V_51 = 0 ;
F_30 ( & V_50 -> V_52 ) ;
}
if ( V_38 && V_50 -> V_53 != 0 ) {
F_31 ( V_54 , V_50 , L_4 , V_38 ) ;
F_6 () ;
}
}
static void F_32 ( struct V_49 * V_50 ,
struct V_55 * V_56 )
{
int V_38 ;
V_38 = F_33 ( V_50 , V_57 + 4 ,
V_56 -> V_58 ) ;
if ( V_38 ) {
F_5 ( L_5 ,
V_57 + 4 , V_56 -> V_58 ) ;
V_56 -> V_59 &= ~ V_60 ;
V_56 -> V_58 = 0 ;
}
}
static struct V_49 * F_34 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 ,
void * V_63 , int V_64 ,
void * V_65 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_18 ( exp ) ;
struct V_67 * V_68 ;
F_35 ( V_69 ) ;
int V_70 = 0 ;
int V_35 ;
int V_38 ;
V_2 -> V_71 = ( V_2 -> V_71 & ~ V_72 ) | V_73 ;
if ( F_36 ( & V_62 -> V_74 ) ) {
if ( V_2 -> V_75 & V_76 ) {
if ( V_2 -> V_75 & V_77 )
V_35 = V_78 ;
else
V_35 = V_79 ;
} else {
if ( V_2 -> V_75 & ( V_77 | V_80 ) )
V_35 = V_81 ;
else if ( V_2 -> V_75 & V_82 )
V_35 = V_79 ;
else
V_35 = V_83 ;
}
V_70 = F_37 ( exp , & V_62 -> V_74 ,
& V_69 , V_35 ,
V_84 ) ;
}
if ( V_2 -> V_85 & V_86 )
V_35 = V_78 ;
else
V_35 = V_83 ;
V_70 += F_37 ( exp , & V_62 -> V_87 ,
& V_69 , V_35 ,
V_88 ) ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_89 ) ;
if ( V_50 == NULL ) {
F_40 ( & V_69 , V_90 , V_70 ) ;
return F_41 ( - V_91 ) ;
}
F_42 ( V_50 , & V_92 , V_62 -> V_93 ) ;
F_42 ( V_50 , & V_94 , V_62 -> V_93 ) ;
F_43 ( & V_50 -> V_95 , & V_96 , V_97 ,
V_62 -> V_98 + 1 ) ;
F_43 ( & V_50 -> V_95 , & V_99 , V_97 ,
F_44 ( V_64 , V_66 -> V_100 . V_101 . V_102 ) ) ;
V_38 = F_45 ( exp , V_50 , & V_69 , V_70 ) ;
if ( V_38 < 0 ) {
F_46 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
F_29 ( & V_50 -> V_52 ) ;
V_50 -> V_51 = V_50 -> V_103 -> V_104 ;
F_30 ( & V_50 -> V_52 ) ;
V_68 = F_47 ( & V_50 -> V_95 , & V_105 ) ;
V_68 -> V_106 = ( T_1 ) V_2 -> V_85 ;
F_48 ( V_50 , V_62 , V_2 -> V_71 , 0 , V_2 -> V_75 , V_63 ,
V_64 ) ;
if ( F_49 ( exp ) )
F_43 ( & V_50 -> V_95 , & V_107 , V_108 ,
sizeof( struct V_109 ) ) ;
F_50 ( V_50 ) ;
return V_50 ;
}
static struct V_49 *
F_51 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_67 * V_68 ;
int V_38 , V_70 = 0 , V_110 ;
F_35 ( V_69 ) ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_111 ) ;
if ( V_50 == NULL )
return F_41 ( - V_91 ) ;
F_42 ( V_50 , & V_92 , V_62 -> V_93 ) ;
V_38 = F_45 ( exp , V_50 , & V_69 , V_70 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
V_68 = F_47 ( & V_50 -> V_95 , & V_105 ) ;
V_68 -> V_106 = V_112 ;
V_110 = F_39 ( exp ) -> V_113 . V_114 ;
F_52 ( V_50 , & V_62 -> V_87 , V_62 -> V_93 ,
V_62 -> V_115 , V_110 , - 1 , 0 ) ;
F_43 ( & V_50 -> V_95 , & V_99 ,
V_108 , V_110 ) ;
F_43 ( & V_50 -> V_95 , & V_116 ,
V_108 , V_110 ) ;
F_43 ( & V_50 -> V_95 , & V_117 ,
V_108 , V_110 ) ;
F_50 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_53 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_18 ( exp ) ;
struct V_67 * V_68 ;
int V_38 ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_118 ) ;
if ( V_50 == NULL )
return F_41 ( - V_91 ) ;
F_42 ( V_50 , & V_92 , V_62 -> V_93 ) ;
F_43 ( & V_50 -> V_95 , & V_96 , V_97 ,
V_62 -> V_98 + 1 ) ;
V_38 = F_45 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
V_68 = F_47 ( & V_50 -> V_95 , & V_105 ) ;
V_68 -> V_106 = ( T_1 ) V_2 -> V_85 ;
F_54 ( V_50 , V_62 ) ;
F_43 ( & V_50 -> V_95 , & V_119 , V_108 ,
V_66 -> V_100 . V_101 . V_102 ) ;
F_43 ( & V_50 -> V_95 , & V_107 , V_108 ,
V_66 -> V_100 . V_101 . V_120 ) ;
F_50 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_55 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_18 ( exp ) ;
T_7 V_59 = V_121 | V_60 |
V_122 | V_123 |
V_124 | V_125 |
( F_49 ( exp ) ?
V_126 : V_127 ) ;
struct V_67 * V_68 ;
int V_38 ;
int V_128 ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_129 ) ;
if ( V_50 == NULL )
return F_41 ( - V_91 ) ;
F_42 ( V_50 , & V_92 , V_62 -> V_93 ) ;
F_43 ( & V_50 -> V_95 , & V_96 , V_97 ,
V_62 -> V_98 + 1 ) ;
V_38 = F_45 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
V_68 = F_47 ( & V_50 -> V_95 , & V_105 ) ;
V_68 -> V_106 = ( T_1 ) V_2 -> V_85 ;
if ( V_66 -> V_100 . V_101 . V_102 > 0 )
V_128 = V_66 -> V_100 . V_101 . V_102 ;
else
V_128 = V_66 -> V_100 . V_101 . V_130 ;
F_56 ( V_50 , V_59 , V_2 -> V_75 , V_62 , V_128 ) ;
F_43 ( & V_50 -> V_95 , & V_119 , V_108 , V_128 ) ;
if ( F_49 ( exp ) )
F_43 ( & V_50 -> V_95 , & V_107 , V_108 ,
sizeof( struct V_109 ) ) ;
F_50 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_57 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_131 )
{
struct V_41 * V_42 = F_18 ( exp ) ;
struct V_49 * V_50 ;
struct V_67 * V_68 ;
struct V_132 * V_133 ;
int V_38 ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_134 ) ;
if ( V_50 == NULL )
return F_41 ( - V_91 ) ;
F_43 ( & V_50 -> V_95 , & V_99 , V_97 , 0 ) ;
V_38 = F_45 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
V_68 = F_47 ( & V_50 -> V_95 , & V_105 ) ;
V_68 -> V_106 = ( T_1 ) V_2 -> V_85 ;
V_133 = F_47 ( & V_50 -> V_95 , & V_135 ) ;
V_133 -> V_136 = V_137 ;
F_43 ( & V_50 -> V_95 , & V_138 , V_108 ,
V_42 -> V_100 . V_101 . V_102 ) ;
F_50 ( V_50 ) ;
return V_50 ;
}
static struct V_49 *
F_58 ( struct V_13 * exp , int V_139 )
{
struct V_49 * V_50 ;
int V_38 ;
V_50 = F_38 ( F_39 ( exp ) , & V_140 ) ;
if ( V_50 == NULL )
return F_41 ( - V_91 ) ;
V_38 = F_45 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
F_43 ( & V_50 -> V_95 , & V_138 , V_108 , V_139 ) ;
F_50 ( V_50 ) ;
return V_50 ;
}
static int F_59 ( struct V_13 * exp ,
struct V_49 * V_50 ,
struct V_141 * V_142 ,
struct V_1 * V_2 ,
struct V_21 * V_14 ,
int V_38 )
{
struct V_143 * V_144 = & V_50 -> V_95 ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_149 * V_150 = & V_2 -> V_4 . V_5 ;
struct V_17 * V_18 ;
void * V_151 = NULL ;
int V_139 = 0 ;
F_9 ( V_38 >= 0 ) ;
if ( V_50 -> V_53 || V_50 -> V_51 ) {
V_146 = F_47 ( V_144 , & V_152 ) ;
V_146 -> V_153 |= F_60 ( V_154 ) ;
}
if ( V_38 == V_155 ) {
V_142 -> V_156 = 0 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_38 = 0 ;
} else {
V_18 = F_8 ( V_14 ) ;
F_9 ( V_18 != NULL ) ;
if ( V_18 -> V_157 != V_142 -> V_156 ) {
F_61 ( V_14 , V_18 -> V_157 ) ;
F_62 ( V_14 , V_142 -> V_156 ) ;
V_142 -> V_156 = V_18 -> V_157 ;
}
F_13 ( V_18 ) ;
}
V_148 = F_63 ( V_144 , & V_158 ) ;
F_9 ( V_148 != NULL ) ;
V_150 -> F_1 = ( int ) V_148 -> V_159 ;
V_150 -> V_8 = ( int ) V_148 -> V_160 ;
V_150 -> V_161 = V_142 -> V_156 ;
V_150 -> V_162 = V_14 -> V_163 ;
V_150 -> V_164 = V_50 ;
if ( ( ! V_50 -> V_53 || V_150 -> V_8 < 0 ) && V_50 -> V_51 )
F_28 ( V_50 , V_150 -> V_8 ) ;
if ( V_2 -> V_85 & V_165 && V_50 -> V_51 &&
( ! F_1 ( V_2 , V_9 ) || V_150 -> V_8 != 0 ) )
F_28 ( V_50 , V_150 -> V_8 ) ;
F_31 ( V_166 , V_50 , L_6 ,
V_2 -> V_85 , V_150 -> F_1 , V_150 -> V_8 ) ;
if ( V_2 -> V_85 & ( V_165 | V_167 | V_168 | V_169 ) ) {
struct V_55 * V_56 ;
V_56 = F_63 ( V_144 , & V_170 ) ;
if ( V_56 == NULL ) {
F_5 ( L_7 ) ;
return - V_171 ;
}
if ( F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_64 ( NULL , NULL , V_2 ) ;
}
if ( ( V_56 -> V_59 & ( V_123 | V_60 ) ) != 0 ) {
void * V_172 ;
F_65 ( exp , V_56 ) ;
V_172 = F_66 ( V_144 , & V_119 ,
V_56 -> V_58 ) ;
if ( V_172 == NULL )
return - V_171 ;
V_151 = V_172 ;
V_139 = V_56 -> V_58 ;
if ( ( V_2 -> V_85 & V_165 ) && V_50 -> V_51 ) {
void * V_63 ;
if ( F_67 ( V_144 , & V_99 ,
V_97 ) <
V_56 -> V_58 )
F_32 ( V_50 , V_56 ) ;
else
F_68 ( V_144 , & V_99 ,
V_56 -> V_58 ,
V_97 ) ;
F_43 ( V_144 , & V_99 ,
V_97 ,
V_56 -> V_58 ) ;
V_63 = F_47 ( V_144 , & V_99 ) ;
if ( V_63 )
memcpy ( V_63 , V_172 , V_56 -> V_58 ) ;
}
}
if ( V_56 -> V_59 & V_126 ) {
struct V_109 * V_173 ;
F_9 ( F_49 ( exp ) ) ;
V_173 = F_69 ( V_144 , & V_107 ,
V_174 ) ;
if ( V_173 == NULL )
return - V_171 ;
}
if ( V_56 -> V_59 & V_124 ) {
struct V_175 * V_176 , * V_177 ;
V_176 = F_63 ( V_144 , & V_92 ) ;
if ( V_176 == NULL )
return - V_171 ;
if ( V_2 -> V_85 & V_165 ) {
V_177 = F_47 ( V_144 , & V_94 ) ;
F_9 ( V_177 ) ;
* V_177 = * V_176 ;
}
}
if ( V_56 -> V_59 & V_178 ) {
struct V_175 * V_176 ;
V_176 = F_63 ( V_144 , & V_94 ) ;
if ( V_176 == NULL )
return - V_171 ;
}
} else if ( V_2 -> V_85 & V_179 ) {
V_139 = F_67 ( V_144 , & V_138 , V_108 ) ;
if ( V_139 > 0 ) {
V_151 = F_66 ( V_144 ,
& V_138 , V_139 ) ;
if ( V_151 == NULL )
return - V_171 ;
}
}
V_18 = F_8 ( V_14 ) ;
if ( V_18 != NULL && F_70 ( V_18 ) && V_151 != NULL ) {
void * V_63 ;
F_71 ( V_18 , L_8 ,
F_72 ( V_2 -> V_85 ) , V_139 ) ;
V_63 = F_73 ( V_139 , V_180 ) ;
if ( V_63 == NULL ) {
F_13 ( V_18 ) ;
return - V_91 ;
}
memcpy ( V_63 , V_151 , V_139 ) ;
F_10 ( V_18 ) ;
if ( V_18 -> V_181 == NULL ) {
V_18 -> V_182 = V_183 ;
V_18 -> V_181 = V_63 ;
V_18 -> V_184 = V_139 ;
V_63 = NULL ;
}
F_12 ( V_18 ) ;
if ( V_63 != NULL )
F_74 ( V_63 ) ;
}
if ( V_18 != NULL )
F_13 ( V_18 ) ;
return V_38 ;
}
int F_75 ( struct V_13 * exp , struct V_141 * V_142 ,
struct V_1 * V_2 , struct V_61 * V_62 ,
struct V_21 * V_14 , void * V_63 , int V_64 ,
struct V_49 * * V_185 , T_7 V_186 )
{
static const T_4 V_187 = {
. V_30 = { V_188 }
} ;
static const T_4 V_189 = {
. V_30 = { V_88 }
} ;
static const T_4 V_190 = {
. V_30 = { V_191 }
} ;
static const T_4 V_192 = {
. V_30 = { V_193 }
} ;
T_4 const * V_34 = & V_187 ;
struct V_41 * V_66 = F_18 ( exp ) ;
struct V_49 * V_50 ;
T_7 V_31 , V_194 = V_186 ;
struct V_36 V_37 ;
int V_195 , V_196 = 0 ;
struct V_147 * V_148 ;
enum V_197 V_197 = V_198 ;
int V_38 ;
F_11 ( ! V_2 || V_142 -> V_199 == V_200 , L_9 ,
V_142 -> V_199 ) ;
F_15 ( & V_62 -> V_87 , & V_37 ) ;
if ( V_2 ) {
V_194 |= V_201 ;
if ( V_2 -> V_85 & ( V_167 | V_169 | V_202 ) )
V_34 = & V_189 ;
else if ( V_2 -> V_85 & V_179 )
V_34 = & V_190 ;
else if ( V_2 -> V_85 & ( V_112 | V_203 ) )
V_34 = & V_192 ;
}
F_9 ( V_185 == NULL ) ;
V_195 = V_66 -> V_100 . V_101 . V_204 -> V_205 ;
V_206:
V_31 = V_194 ;
if ( ! V_2 ) {
F_9 ( V_63 && V_64 == 0 ) ;
F_11 ( V_142 -> V_199 == V_207 , L_9 ,
V_142 -> V_199 ) ;
V_34 = ( T_4 * ) V_63 ;
V_37 . V_208 [ 3 ] = V_207 ;
V_50 = NULL ;
} else if ( V_2 -> V_85 & V_165 ) {
V_50 = F_34 ( exp , V_2 , V_62 , V_63 , V_64 ,
V_142 -> V_209 ) ;
V_34 = & V_189 ;
V_142 -> V_209 = NULL ;
V_63 = NULL ;
} else if ( V_2 -> V_85 & V_167 ) {
V_50 = F_53 ( exp , V_2 , V_62 ) ;
} else if ( V_2 -> V_85 & ( V_169 | V_168 ) ) {
V_50 = F_55 ( exp , V_2 , V_62 ) ;
} else if ( V_2 -> V_85 & V_202 ) {
V_50 = F_58 ( exp , 0 ) ;
} else if ( V_2 -> V_85 & V_179 ) {
if ( ! F_76 ( F_39 ( exp ) ) )
return - V_210 ;
V_50 = F_57 ( exp , V_2 , V_62 ) ;
V_197 = V_183 ;
} else if ( V_2 -> V_85 & V_112 ) {
V_50 = F_51 ( exp , V_2 , V_62 ) ;
} else {
F_6 () ;
return - V_211 ;
}
if ( F_77 ( V_50 ) )
return F_78 ( V_50 ) ;
if ( V_50 != NULL && V_2 && V_2 -> V_85 & V_86 )
V_50 -> V_212 = 1 ;
if ( V_196 ) {
V_50 -> V_213 = 1 ;
V_50 -> V_214 = V_195 ;
V_50 -> V_215 = F_79 () + V_196 ;
}
if ( V_2 ) {
F_80 ( V_66 -> V_100 . V_101 . V_216 , V_2 ) ;
V_38 = F_81 ( & V_66 -> V_100 . V_101 ) ;
if ( V_38 != 0 ) {
F_82 ( V_66 -> V_100 . V_101 . V_216 , V_2 ) ;
F_28 ( V_50 , 0 ) ;
F_83 ( V_50 ) ;
return V_38 ;
}
}
V_38 = F_84 ( exp , & V_50 , V_142 , & V_37 , V_34 , & V_31 , NULL ,
0 , V_197 , V_14 , 0 ) ;
if ( ! V_2 ) {
if ( ( V_38 == - V_217 ) || ( V_38 == - V_218 ) )
goto V_206;
return V_38 ;
}
F_85 ( & V_66 -> V_100 . V_101 ) ;
F_82 ( V_66 -> V_100 . V_101 . V_216 , V_2 ) ;
if ( V_38 < 0 ) {
F_86 ( ( V_38 == - V_219 || V_38 == - V_220 ) ? V_221 : V_54 ,
L_10 ,
V_66 -> V_222 , V_38 ) ;
F_28 ( V_50 , V_38 ) ;
F_83 ( V_50 ) ;
return V_38 ;
}
V_148 = F_63 ( & V_50 -> V_95 , & V_158 ) ;
F_9 ( V_148 != NULL ) ;
V_148 -> V_160 =
F_87 ( V_148 -> V_160 ) ;
if ( V_2 && V_2 -> V_85 & V_86 &&
( int ) V_148 -> V_160 == - V_223 ) {
F_28 ( V_50 , V_38 ) ;
F_83 ( V_50 ) ;
V_196 ++ ;
F_88 ( V_224 , L_11 V_225 L_12 V_225 L_13 ,
V_66 -> V_222 , V_196 , V_2 -> V_85 ,
F_89 ( & V_62 -> V_87 ) , F_89 ( & V_62 -> V_74 ) ) ;
if ( V_195 == V_66 -> V_100 . V_101 . V_204 -> V_205 ) {
goto V_206;
} else {
F_88 ( V_224 , L_14 ) ;
return - V_226 ;
}
}
V_38 = F_59 ( exp , V_50 , V_142 , V_2 , V_14 , V_38 ) ;
if ( V_38 < 0 ) {
if ( F_90 ( V_14 ) ) {
F_62 ( V_14 , V_142 -> V_156 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
}
F_83 ( V_50 ) ;
V_2 -> V_4 . V_5 . V_162 = 0 ;
V_2 -> V_4 . V_5 . V_161 = 0 ;
V_2 -> V_4 . V_5 . V_164 = NULL ;
}
return V_38 ;
}
static int F_91 ( struct V_13 * exp ,
struct V_49 * V_227 ,
struct V_61 * V_62 ,
struct V_1 * V_2 ,
struct V_21 * V_14 )
{
struct V_21 V_228 ;
struct V_55 * V_55 ;
struct V_17 * V_18 ;
int V_38 ;
F_9 ( V_227 != NULL ) ;
F_9 ( V_227 != V_229 ) ;
F_9 ( V_227 -> V_230 != V_229 ) ;
if ( ! F_1 ( V_2 , V_12 ) ) {
F_9 ( V_2 -> V_4 . V_5 . V_8 != 0 ) ;
return V_2 -> V_4 . V_5 . V_8 ;
}
V_38 = F_4 ( V_12 , V_2 ) ;
if ( V_38 )
return V_38 ;
V_55 = F_63 ( & V_227 -> V_95 , & V_170 ) ;
F_9 ( V_55 != NULL ) ;
if ( F_36 ( & V_62 -> V_74 ) &&
V_2 -> V_71 & V_231 &&
V_2 -> V_85 != V_169 ) {
if ( ( ! F_92 ( & V_62 -> V_74 , & V_55 -> V_232 ) ) &&
( ! F_92 ( & V_62 -> V_233 , & V_55 -> V_232 ) ) ) {
F_88 ( V_234 , L_15 V_225 L_16 V_225 L_17 V_225
L_13 , F_89 ( & V_62 -> V_74 ) ,
F_89 ( & V_62 -> V_74 ) , F_89 ( & V_55 -> V_232 ) ) ;
return - V_235 ;
}
}
V_38 = F_4 ( V_11 , V_2 ) ;
if ( V_38 )
return V_38 ;
if ( ! F_1 ( V_2 , V_236 ) &&
F_1 ( V_2 , V_10 ) &&
! F_4 ( V_10 , V_2 ) ) {
F_2 ( V_2 , V_236 ) ;
F_93 ( V_227 ) ;
}
if ( ! F_1 ( V_2 , V_237 ) &&
F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_2 ( V_2 , V_237 ) ;
F_93 ( V_227 ) ;
F_94 ( V_238 , V_239 ) ;
}
if ( V_2 -> V_85 & V_86 ) {
} else if ( V_2 -> V_85 == V_165 ) {
F_9 ( ! F_1 ( V_2 , V_10 ) ) ;
} else {
F_9 ( V_2 -> V_85 & ( V_169 | V_168 | V_179 ) ) ;
}
V_18 = F_8 ( V_14 ) ;
if ( V_18 ) {
T_4 V_34 = V_18 -> V_29 ;
F_71 ( V_18 , L_18 ) ;
F_11 ( F_95 ( & V_55 -> V_232 ,
& V_18 -> V_22 -> V_240 ) ,
L_19 V_241 L_20 V_225 L_13 ,
F_96 ( V_18 -> V_22 ) , F_89 ( & V_55 -> V_232 ) ) ;
F_13 ( V_18 ) ;
memcpy ( & V_228 , V_14 , sizeof( * V_14 ) ) ;
if ( F_17 ( NULL , V_242 , NULL ,
V_200 , & V_34 , V_243 ,
& V_228 , 0 ) ) {
F_97 ( V_14 ,
V_2 -> V_4 . V_5 . V_161 ) ;
memcpy ( V_14 , & V_228 , sizeof( V_228 ) ) ;
V_2 -> V_4 . V_5 . V_162 = V_14 -> V_163 ;
}
}
F_88 ( V_234 ,
L_21 ,
V_62 -> V_98 , V_62 -> V_244 , F_72 ( V_2 -> V_85 ) ,
V_2 -> V_4 . V_5 . V_8 , V_2 -> V_4 . V_5 . F_1 , V_38 ) ;
return V_38 ;
}
int F_98 ( struct V_13 * exp , struct V_1 * V_2 ,
struct V_32 * V_33 , T_1 * V_16 )
{
struct V_36 V_37 ;
struct V_21 V_14 ;
T_4 V_34 ;
T_2 V_35 ;
if ( V_2 -> V_4 . V_5 . V_162 ) {
V_14 . V_163 = V_2 -> V_4 . V_5 . V_162 ;
V_35 = F_99 ( & V_14 , V_16 ) ;
} else {
F_15 ( V_33 , & V_37 ) ;
switch ( V_2 -> V_85 ) {
case V_169 :
V_34 . V_30 . V_16 = V_88 |
V_188 |
V_245 ;
break;
case V_179 :
V_34 . V_30 . V_16 = V_191 ;
break;
default:
V_34 . V_30 . V_16 = V_188 ;
break;
}
V_35 = F_14 ( exp , V_242 , V_33 ,
V_200 , & V_34 ,
V_83 | V_81 | V_79 | V_246 ,
& V_14 ) ;
}
if ( V_35 ) {
V_2 -> V_4 . V_5 . V_162 = V_14 . V_163 ;
V_2 -> V_4 . V_5 . V_161 = V_35 ;
} else {
V_2 -> V_4 . V_5 . V_162 = 0 ;
V_2 -> V_4 . V_5 . V_161 = 0 ;
}
return ! ! V_35 ;
}
int F_100 ( struct V_13 * exp , struct V_61 * V_62 ,
void * V_63 , int V_64 , struct V_1 * V_2 ,
int V_247 , struct V_49 * * V_185 ,
T_8 V_248 ,
T_1 V_186 )
{
struct V_141 V_142 = {
. V_199 = V_200 ,
. V_156 = F_101 ( V_2 ) ,
. V_249 = V_248 ,
. V_250 = V_251 ,
} ;
struct V_21 V_14 ;
int V_38 = 0 ;
F_9 ( V_2 ) ;
F_88 ( V_252 , L_22 V_225 L_23 V_225
L_24 , V_62 -> V_98 ,
V_62 -> V_244 , F_89 ( & V_62 -> V_74 ) ,
F_89 ( & V_62 -> V_87 ) , F_72 ( V_2 -> V_85 ) ,
V_2 -> V_75 ) ;
V_14 . V_163 = 0 ;
if ( F_36 ( & V_62 -> V_74 ) &&
( V_2 -> V_85 & ( V_168 | V_169 ) ) ) {
V_2 -> V_4 . V_5 . V_162 = 0 ;
V_38 = F_98 ( exp , V_2 , & V_62 -> V_74 , NULL ) ;
if ( V_38 || V_62 -> V_98 != 0 )
return V_38 ;
}
if ( ! F_36 ( & V_62 -> V_74 ) && V_2 -> V_85 & V_86 ) {
V_38 = F_102 ( exp , & V_62 -> V_74 , V_62 ) ;
if ( V_38 < 0 ) {
F_5 ( L_25 , V_38 ) ;
return V_38 ;
}
}
V_38 = F_75 ( exp , & V_142 , V_2 , V_62 , & V_14 , V_63 , V_64 , NULL ,
V_186 ) ;
if ( V_38 < 0 )
return V_38 ;
* V_185 = V_2 -> V_4 . V_5 . V_164 ;
V_38 = F_91 ( exp , * V_185 , V_62 , V_2 , & V_14 ) ;
return V_38 ;
}
static int F_103 ( const struct V_253 * V_254 ,
struct V_49 * V_50 ,
void * args , int V_38 )
{
struct V_255 * V_256 = args ;
struct V_13 * exp = V_256 -> V_257 ;
struct V_258 * V_259 = V_256 -> V_260 ;
struct V_141 * V_142 = V_256 -> V_261 ;
struct V_1 * V_2 ;
struct V_21 * V_14 ;
struct V_41 * V_66 ;
struct V_147 * V_148 ;
T_1 V_31 = V_201 ;
V_2 = & V_259 -> V_262 ;
V_14 = & V_259 -> V_263 ;
V_66 = F_18 ( exp ) ;
F_85 ( & V_66 -> V_100 . V_101 ) ;
if ( F_104 ( V_264 ) )
V_38 = - V_218 ;
V_38 = F_105 ( exp , V_50 , V_142 -> V_199 , 1 , V_142 -> V_156 ,
& V_31 , NULL , 0 , V_14 , V_38 ) ;
if ( V_38 < 0 ) {
F_5 ( L_26 , V_38 ) ;
F_28 ( V_50 , V_38 ) ;
goto V_265;
}
V_148 = F_63 ( & V_50 -> V_95 , & V_158 ) ;
F_9 ( V_148 != NULL ) ;
V_148 -> V_160 =
F_87 ( V_148 -> V_160 ) ;
V_38 = F_59 ( exp , V_50 , V_142 , V_2 , V_14 , V_38 ) ;
if ( V_38 )
goto V_265;
V_38 = F_91 ( exp , V_50 , & V_259 -> V_266 , V_2 , V_14 ) ;
V_265:
F_106 ( V_142 ) ;
V_259 -> V_267 ( V_50 , V_259 , V_38 ) ;
return 0 ;
}
int F_107 ( struct V_13 * exp ,
struct V_258 * V_259 ,
struct V_141 * V_142 )
{
struct V_61 * V_62 = & V_259 -> V_266 ;
struct V_1 * V_2 = & V_259 -> V_262 ;
struct V_49 * V_50 ;
struct V_255 * V_256 ;
struct V_41 * V_66 = F_18 ( exp ) ;
struct V_36 V_37 ;
T_4 V_34 = {
. V_30 = { V_188 |
V_88 }
} ;
int V_38 = 0 ;
T_1 V_31 = V_201 ;
F_88 ( V_252 ,
L_27 V_225 L_24 ,
V_62 -> V_98 , V_62 -> V_244 , F_89 ( & V_62 -> V_87 ) ,
F_72 ( V_2 -> V_85 ) , V_2 -> V_75 ) ;
F_15 ( & V_62 -> V_87 , & V_37 ) ;
V_50 = F_55 ( exp , V_2 , V_62 ) ;
if ( F_77 ( V_50 ) )
return F_78 ( V_50 ) ;
V_38 = F_81 ( & V_66 -> V_100 . V_101 ) ;
if ( V_38 != 0 ) {
F_83 ( V_50 ) ;
return V_38 ;
}
V_38 = F_84 ( exp , & V_50 , V_142 , & V_37 , & V_34 , & V_31 , NULL ,
0 , V_198 , & V_259 -> V_263 , 1 ) ;
if ( V_38 < 0 ) {
F_85 ( & V_66 -> V_100 . V_101 ) ;
F_83 ( V_50 ) ;
return V_38 ;
}
F_108 ( sizeof( * V_256 ) <= sizeof( V_50 -> V_268 ) ) ;
V_256 = F_109 ( V_50 ) ;
V_256 -> V_257 = exp ;
V_256 -> V_260 = V_259 ;
V_256 -> V_261 = V_142 ;
V_50 -> V_269 = F_103 ;
F_110 ( V_50 , V_270 , - 1 ) ;
return 0 ;
}
