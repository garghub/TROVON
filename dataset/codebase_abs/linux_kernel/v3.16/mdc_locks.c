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
L_2
L_3 , V_24 ,
V_24 -> V_27 , V_24 -> V_28 ,
V_24 -> V_25 ,
V_20 , V_20 -> V_27 , V_20 -> V_28 ) ;
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
F_11 ( V_46 != NULL , L_4 ) ;
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
F_31 ( V_54 , V_50 , L_5 , V_38 ) ;
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
F_5 ( L_6 ,
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
#ifdef F_37
else if ( V_2 -> V_75 & F_37 )
V_35 = V_79 ;
#endif
else
V_35 = V_82 ;
}
V_70 = F_38 ( exp , & V_62 -> V_74 ,
& V_69 , V_35 ,
V_83 ) ;
}
if ( V_2 -> V_84 & V_85 )
V_35 = V_78 ;
else
V_35 = V_82 ;
V_70 += F_38 ( exp , & V_62 -> V_86 ,
& V_69 , V_35 ,
V_87 ) ;
V_50 = F_39 ( F_40 ( exp ) ,
& V_88 ) ;
if ( V_50 == NULL ) {
F_41 ( & V_69 , V_89 , V_70 ) ;
return F_42 ( - V_90 ) ;
}
F_43 ( V_50 , & V_91 , V_62 -> V_92 ) ;
F_43 ( V_50 , & V_93 , V_62 -> V_92 ) ;
F_44 ( & V_50 -> V_94 , & V_95 , V_96 ,
V_62 -> V_97 + 1 ) ;
F_44 ( & V_50 -> V_94 , & V_98 , V_96 ,
F_45 ( V_64 , V_66 -> V_99 . V_100 . V_101 ) ) ;
V_38 = F_46 ( exp , V_50 , & V_69 , V_70 ) ;
if ( V_38 < 0 ) {
F_47 ( V_50 ) ;
return F_42 ( V_38 ) ;
}
F_29 ( & V_50 -> V_52 ) ;
V_50 -> V_51 = V_50 -> V_102 -> V_103 ;
F_30 ( & V_50 -> V_52 ) ;
V_68 = F_48 ( & V_50 -> V_94 , & V_104 ) ;
V_68 -> V_105 = ( T_1 ) V_2 -> V_84 ;
F_49 ( V_50 , V_62 , V_2 -> V_71 , 0 , V_2 -> V_75 , V_63 ,
V_64 ) ;
if ( F_50 ( exp ) )
F_44 ( & V_50 -> V_94 , & V_106 , V_107 ,
sizeof( struct V_108 ) ) ;
F_51 ( V_50 ) ;
return V_50 ;
}
static struct V_49 *
F_52 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_67 * V_68 ;
int V_38 , V_70 = 0 , V_109 ;
F_35 ( V_69 ) ;
V_50 = F_39 ( F_40 ( exp ) ,
& V_110 ) ;
if ( V_50 == NULL )
return F_42 ( - V_90 ) ;
F_43 ( V_50 , & V_91 , V_62 -> V_92 ) ;
V_38 = F_46 ( exp , V_50 , & V_69 , V_70 ) ;
if ( V_38 ) {
F_47 ( V_50 ) ;
return F_42 ( V_38 ) ;
}
V_68 = F_48 ( & V_50 -> V_94 , & V_104 ) ;
V_68 -> V_105 = V_111 ;
V_109 = F_40 ( exp ) -> V_112 . V_113 ;
F_53 ( V_50 , & V_62 -> V_86 , V_62 -> V_92 ,
V_62 -> V_114 , V_109 , - 1 , 0 ) ;
F_44 ( & V_50 -> V_94 , & V_98 ,
V_107 , V_109 ) ;
F_44 ( & V_50 -> V_94 , & V_115 ,
V_107 , V_109 ) ;
F_44 ( & V_50 -> V_94 , & V_116 ,
V_107 , V_109 ) ;
F_51 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_54 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_18 ( exp ) ;
struct V_67 * V_68 ;
int V_38 ;
V_50 = F_39 ( F_40 ( exp ) ,
& V_117 ) ;
if ( V_50 == NULL )
return F_42 ( - V_90 ) ;
F_43 ( V_50 , & V_91 , V_62 -> V_92 ) ;
F_44 ( & V_50 -> V_94 , & V_95 , V_96 ,
V_62 -> V_97 + 1 ) ;
V_38 = F_46 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_47 ( V_50 ) ;
return F_42 ( V_38 ) ;
}
V_68 = F_48 ( & V_50 -> V_94 , & V_104 ) ;
V_68 -> V_105 = ( T_1 ) V_2 -> V_84 ;
F_55 ( V_50 , V_62 ) ;
F_44 ( & V_50 -> V_94 , & V_118 , V_107 ,
V_66 -> V_99 . V_100 . V_101 ) ;
F_44 ( & V_50 -> V_94 , & V_106 , V_107 ,
V_66 -> V_99 . V_100 . V_119 ) ;
F_51 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_56 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_18 ( exp ) ;
T_7 V_59 = V_120 | V_60 |
V_121 | V_122 |
V_123 | V_124 |
( F_50 ( exp ) ?
V_125 : V_126 ) ;
struct V_67 * V_68 ;
int V_38 ;
int V_127 ;
V_50 = F_39 ( F_40 ( exp ) ,
& V_128 ) ;
if ( V_50 == NULL )
return F_42 ( - V_90 ) ;
F_43 ( V_50 , & V_91 , V_62 -> V_92 ) ;
F_44 ( & V_50 -> V_94 , & V_95 , V_96 ,
V_62 -> V_97 + 1 ) ;
V_38 = F_46 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_47 ( V_50 ) ;
return F_42 ( V_38 ) ;
}
V_68 = F_48 ( & V_50 -> V_94 , & V_104 ) ;
V_68 -> V_105 = ( T_1 ) V_2 -> V_84 ;
if ( V_66 -> V_99 . V_100 . V_101 > 0 )
V_127 = V_66 -> V_99 . V_100 . V_101 ;
else
V_127 = V_66 -> V_99 . V_100 . V_129 ;
F_57 ( V_50 , V_59 , V_2 -> V_75 , V_62 , V_127 ) ;
F_44 ( & V_50 -> V_94 , & V_118 , V_107 , V_127 ) ;
if ( F_50 ( exp ) )
F_44 ( & V_50 -> V_94 , & V_106 , V_107 ,
sizeof( struct V_108 ) ) ;
F_51 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_58 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_130 )
{
struct V_41 * V_42 = F_18 ( exp ) ;
struct V_49 * V_50 ;
struct V_67 * V_68 ;
struct V_131 * V_132 ;
int V_38 ;
V_50 = F_39 ( F_40 ( exp ) ,
& V_133 ) ;
if ( V_50 == NULL )
return F_42 ( - V_90 ) ;
F_44 ( & V_50 -> V_94 , & V_98 , V_96 , 0 ) ;
V_38 = F_46 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_47 ( V_50 ) ;
return F_42 ( V_38 ) ;
}
V_68 = F_48 ( & V_50 -> V_94 , & V_104 ) ;
V_68 -> V_105 = ( T_1 ) V_2 -> V_84 ;
V_132 = F_48 ( & V_50 -> V_94 , & V_134 ) ;
V_132 -> V_135 = V_136 ;
F_44 ( & V_50 -> V_94 , & V_137 , V_107 ,
V_42 -> V_99 . V_100 . V_101 ) ;
F_51 ( V_50 ) ;
return V_50 ;
}
static struct V_49 *
F_59 ( struct V_13 * exp , int V_138 )
{
struct V_49 * V_50 ;
int V_38 ;
V_50 = F_39 ( F_40 ( exp ) , & V_139 ) ;
if ( V_50 == NULL )
return F_42 ( - V_90 ) ;
V_38 = F_46 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_47 ( V_50 ) ;
return F_42 ( V_38 ) ;
}
F_44 ( & V_50 -> V_94 , & V_137 , V_107 , V_138 ) ;
F_51 ( V_50 ) ;
return V_50 ;
}
static int F_60 ( struct V_13 * exp ,
struct V_49 * V_50 ,
struct V_140 * V_141 ,
struct V_1 * V_2 ,
struct V_21 * V_14 ,
int V_38 )
{
struct V_142 * V_143 = & V_50 -> V_94 ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
struct V_148 * V_149 = & V_2 -> V_4 . V_5 ;
struct V_17 * V_18 ;
void * V_150 = NULL ;
int V_138 = 0 ;
F_9 ( V_38 >= 0 ) ;
if ( V_50 -> V_53 || V_50 -> V_51 ) {
V_145 = F_48 ( V_143 , & V_151 ) ;
V_145 -> V_152 |= F_61 ( V_153 ) ;
}
if ( V_38 == V_154 ) {
V_141 -> V_155 = 0 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_38 = 0 ;
} else {
V_18 = F_8 ( V_14 ) ;
F_9 ( V_18 != NULL ) ;
if ( V_18 -> V_156 != V_141 -> V_155 ) {
F_62 ( V_14 , V_18 -> V_156 ) ;
F_63 ( V_14 , V_141 -> V_155 ) ;
V_141 -> V_155 = V_18 -> V_156 ;
}
F_13 ( V_18 ) ;
}
V_147 = F_64 ( V_143 , & V_157 ) ;
F_9 ( V_147 != NULL ) ;
V_149 -> F_1 = ( int ) V_147 -> V_158 ;
V_149 -> V_8 = ( int ) V_147 -> V_159 ;
V_149 -> V_160 = V_141 -> V_155 ;
V_149 -> V_161 = V_14 -> V_162 ;
V_149 -> V_163 = V_50 ;
if ( ( ! V_50 -> V_53 || V_149 -> V_8 < 0 ) && V_50 -> V_51 )
F_28 ( V_50 , V_149 -> V_8 ) ;
if ( V_2 -> V_84 & V_164 && V_50 -> V_51 &&
( ! F_1 ( V_2 , V_9 ) || V_149 -> V_8 != 0 ) )
F_28 ( V_50 , V_149 -> V_8 ) ;
F_31 ( V_165 , V_50 , L_7 ,
V_2 -> V_84 , V_149 -> F_1 , V_149 -> V_8 ) ;
if ( V_2 -> V_84 & ( V_164 | V_166 | V_167 | V_168 ) ) {
struct V_55 * V_56 ;
V_56 = F_64 ( V_143 , & V_169 ) ;
if ( V_56 == NULL ) {
F_5 ( L_8 ) ;
return - V_170 ;
}
if ( F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_65 ( NULL , NULL , V_2 ) ;
}
if ( ( V_56 -> V_59 & ( V_122 | V_60 ) ) != 0 ) {
void * V_171 ;
F_66 ( exp , V_56 ) ;
V_171 = F_67 ( V_143 , & V_118 ,
V_56 -> V_58 ) ;
if ( V_171 == NULL )
return - V_170 ;
V_150 = V_171 ;
V_138 = V_56 -> V_58 ;
if ( ( V_2 -> V_84 & V_164 ) && V_50 -> V_51 ) {
void * V_63 ;
if ( F_68 ( V_143 , & V_98 ,
V_96 ) <
V_56 -> V_58 )
F_32 ( V_50 , V_56 ) ;
else
F_69 ( V_143 , & V_98 ,
V_56 -> V_58 ,
V_96 ) ;
F_44 ( V_143 , & V_98 ,
V_96 ,
V_56 -> V_58 ) ;
V_63 = F_48 ( V_143 , & V_98 ) ;
if ( V_63 )
memcpy ( V_63 , V_171 , V_56 -> V_58 ) ;
}
}
if ( V_56 -> V_59 & V_125 ) {
struct V_108 * V_172 ;
F_9 ( F_50 ( exp ) ) ;
V_172 = F_70 ( V_143 , & V_106 ,
V_173 ) ;
if ( V_172 == NULL )
return - V_170 ;
}
if ( V_56 -> V_59 & V_123 ) {
struct V_174 * V_175 , * V_176 ;
V_175 = F_64 ( V_143 , & V_91 ) ;
if ( V_175 == NULL )
return - V_170 ;
if ( V_2 -> V_84 & V_164 ) {
V_176 = F_48 ( V_143 , & V_93 ) ;
F_9 ( V_176 ) ;
* V_176 = * V_175 ;
}
}
if ( V_56 -> V_59 & V_177 ) {
struct V_174 * V_175 ;
V_175 = F_64 ( V_143 , & V_93 ) ;
if ( V_175 == NULL )
return - V_170 ;
}
} else if ( V_2 -> V_84 & V_178 ) {
V_138 = F_68 ( V_143 , & V_137 , V_107 ) ;
if ( V_138 > 0 ) {
V_150 = F_67 ( V_143 ,
& V_137 , V_138 ) ;
if ( V_150 == NULL )
return - V_170 ;
}
}
V_18 = F_8 ( V_14 ) ;
if ( V_18 != NULL && F_71 ( V_18 ) && V_150 != NULL ) {
void * V_63 ;
F_72 ( V_18 , L_9 ,
F_73 ( V_2 -> V_84 ) , V_138 ) ;
F_74 ( V_63 , V_138 ) ;
if ( V_63 == NULL ) {
F_13 ( V_18 ) ;
return - V_90 ;
}
memcpy ( V_63 , V_150 , V_138 ) ;
F_10 ( V_18 ) ;
if ( V_18 -> V_179 == NULL ) {
V_18 -> V_180 = V_181 ;
V_18 -> V_179 = V_63 ;
V_18 -> V_182 = V_138 ;
V_63 = NULL ;
}
F_12 ( V_18 ) ;
if ( V_63 != NULL )
F_75 ( V_63 , V_138 ) ;
}
if ( V_18 != NULL )
F_13 ( V_18 ) ;
return V_38 ;
}
int F_76 ( struct V_13 * exp , struct V_140 * V_141 ,
struct V_1 * V_2 , struct V_61 * V_62 ,
struct V_21 * V_14 , void * V_63 , int V_64 ,
struct V_49 * * V_183 , T_1 V_184 )
{
struct V_41 * V_66 = F_18 ( exp ) ;
struct V_49 * V_50 = NULL ;
T_1 V_31 , V_185 = V_184 ;
int V_38 ;
struct V_36 V_37 ;
static const T_4 V_186 =
{ . V_30 = { V_187 } } ;
static const T_4 V_188 =
{ . V_30 = { V_87 } } ;
static const T_4 V_189 =
{ . V_30 = { V_190 } } ;
static const T_4 V_191 = {
. V_30 = { V_192 } } ;
T_4 const * V_34 = & V_186 ;
int V_193 , V_194 = 0 ;
struct V_146 * V_147 ;
enum V_195 V_195 = 0 ;
F_11 ( ! V_2 || V_141 -> V_196 == V_197 , L_10 ,
V_141 -> V_196 ) ;
F_15 ( & V_62 -> V_86 , & V_37 ) ;
if ( V_2 ) {
V_185 |= V_198 ;
if ( V_2 -> V_84 & ( V_166 | V_168 | V_199 ) )
V_34 = & V_188 ;
else if ( V_2 -> V_84 & V_178 )
V_34 = & V_189 ;
else if ( V_2 -> V_84 & ( V_111 | V_200 ) )
V_34 = & V_191 ;
}
F_9 ( V_183 == NULL ) ;
V_193 = V_66 -> V_99 . V_100 . V_201 -> V_202 ;
V_203:
V_31 = V_185 ;
if ( ! V_2 ) {
F_9 ( V_63 && V_64 == 0 ) ;
F_11 ( V_141 -> V_196 == V_204 , L_10 ,
V_141 -> V_196 ) ;
V_34 = ( T_4 * ) V_63 ;
V_37 . V_205 [ 3 ] = V_204 ;
} else if ( V_2 -> V_84 & V_164 ) {
V_50 = F_34 ( exp , V_2 , V_62 , V_63 , V_64 ,
V_141 -> V_206 ) ;
V_34 = & V_188 ;
V_141 -> V_206 = NULL ;
V_63 = NULL ;
} else if ( V_2 -> V_84 & V_166 ) {
V_50 = F_54 ( exp , V_2 , V_62 ) ;
} else if ( V_2 -> V_84 & ( V_168 | V_167 ) ) {
V_50 = F_56 ( exp , V_2 , V_62 ) ;
} else if ( V_2 -> V_84 & V_199 ) {
V_50 = F_59 ( exp , 0 ) ;
} else if ( V_2 -> V_84 & V_178 ) {
if ( ! F_77 ( F_40 ( exp ) ) )
return - V_207 ;
V_50 = F_58 ( exp , V_2 , V_62 ) ;
V_195 = V_181 ;
} else if ( V_2 -> V_84 & V_111 ) {
V_50 = F_52 ( exp , V_2 , V_62 ) ;
} else {
F_6 () ;
return - V_208 ;
}
if ( F_78 ( V_50 ) )
return F_79 ( V_50 ) ;
if ( V_50 != NULL && V_2 && V_2 -> V_84 & V_85 )
V_50 -> V_209 = 1 ;
if ( V_194 ) {
V_50 -> V_210 = 1 ;
V_50 -> V_211 = V_193 ;
V_50 -> V_212 = F_80 () + V_194 ;
}
if ( V_2 ) {
F_81 ( V_66 -> V_99 . V_100 . V_213 , V_2 ) ;
V_38 = F_82 ( & V_66 -> V_99 . V_100 ) ;
if ( V_38 != 0 ) {
F_83 ( V_66 -> V_99 . V_100 . V_213 , V_2 ) ;
F_28 ( V_50 , 0 ) ;
F_84 ( V_50 ) ;
return V_38 ;
}
}
V_38 = F_85 ( exp , & V_50 , V_141 , & V_37 , V_34 , & V_31 , NULL ,
0 , V_195 , V_14 , 0 ) ;
if ( ! V_2 ) {
if ( ( V_38 == - V_214 ) || ( V_38 == - V_215 ) )
goto V_203;
return V_38 ;
}
F_86 ( & V_66 -> V_99 . V_100 ) ;
F_83 ( V_66 -> V_99 . V_100 . V_213 , V_2 ) ;
if ( V_38 < 0 ) {
F_87 ( ( V_38 == - V_216 || V_38 == - V_217 ) ? V_218 : V_54 ,
L_11 ,
V_66 -> V_219 , V_38 ) ;
F_28 ( V_50 , V_38 ) ;
F_84 ( V_50 ) ;
return V_38 ;
}
V_147 = F_64 ( & V_50 -> V_94 , & V_157 ) ;
F_9 ( V_147 != NULL ) ;
V_147 -> V_159 =
F_88 ( V_147 -> V_159 ) ;
if ( V_2 && V_2 -> V_84 & V_85 &&
( int ) V_147 -> V_159 == - V_220 ) {
F_28 ( V_50 , V_38 ) ;
F_84 ( V_50 ) ;
V_194 ++ ;
F_89 ( V_221 , L_12 V_222 L_13 V_222 L_14 ,
V_66 -> V_219 , V_194 , V_2 -> V_84 ,
F_90 ( & V_62 -> V_86 ) , F_90 ( & V_62 -> V_74 ) ) ;
if ( V_193 == V_66 -> V_99 . V_100 . V_201 -> V_202 ) {
goto V_203;
} else {
F_89 ( V_221 , L_15 ) ;
return - V_223 ;
}
}
V_38 = F_60 ( exp , V_50 , V_141 , V_2 , V_14 , V_38 ) ;
if ( V_38 < 0 ) {
if ( F_91 ( V_14 ) ) {
F_63 ( V_14 , V_141 -> V_155 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
}
F_84 ( V_50 ) ;
}
return V_38 ;
}
static int F_92 ( struct V_13 * exp ,
struct V_49 * V_224 ,
struct V_61 * V_62 ,
struct V_1 * V_2 ,
struct V_21 * V_14 )
{
struct V_21 V_225 ;
struct V_55 * V_55 ;
struct V_17 * V_18 ;
int V_38 ;
F_9 ( V_224 != NULL ) ;
F_9 ( V_224 != V_226 ) ;
F_9 ( V_224 -> V_227 != V_226 ) ;
if ( ! F_1 ( V_2 , V_12 ) ) {
F_9 ( V_2 -> V_4 . V_5 . V_8 != 0 ) ;
return V_2 -> V_4 . V_5 . V_8 ;
}
V_38 = F_4 ( V_12 , V_2 ) ;
if ( V_38 )
return V_38 ;
V_55 = F_64 ( & V_224 -> V_94 , & V_169 ) ;
F_9 ( V_55 != NULL ) ;
if ( F_36 ( & V_62 -> V_74 ) &&
V_2 -> V_71 & V_228 &&
V_2 -> V_84 != V_168 ) {
if ( ( ! F_93 ( & V_62 -> V_74 , & V_55 -> V_229 ) ) &&
( ! F_93 ( & V_62 -> V_230 , & V_55 -> V_229 ) ) ) {
F_89 ( V_231 , L_16 V_222 L_17 V_222 L_18 V_222
L_14 , F_90 ( & V_62 -> V_74 ) ,
F_90 ( & V_62 -> V_74 ) , F_90 ( & V_55 -> V_229 ) ) ;
return - V_232 ;
}
}
V_38 = F_4 ( V_11 , V_2 ) ;
if ( V_38 )
return V_38 ;
if ( ! F_1 ( V_2 , V_233 ) &&
F_1 ( V_2 , V_10 ) &&
! F_4 ( V_10 , V_2 ) ) {
F_2 ( V_2 , V_233 ) ;
F_94 ( V_224 ) ;
}
if ( ! F_1 ( V_2 , V_234 ) &&
F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_2 ( V_2 , V_234 ) ;
F_94 ( V_224 ) ;
F_95 ( V_235 , V_236 ) ;
}
if ( V_2 -> V_84 & V_85 ) {
} else if ( V_2 -> V_84 == V_164 ) {
F_9 ( ! F_1 ( V_2 , V_10 ) ) ;
} else {
F_9 ( V_2 -> V_84 & ( V_168 | V_167 | V_178 ) ) ;
}
V_18 = F_8 ( V_14 ) ;
if ( V_18 ) {
T_4 V_34 = V_18 -> V_29 ;
F_72 ( V_18 , L_19 ) ;
F_11 ( F_96 ( & V_55 -> V_229 ,
& V_18 -> V_22 -> V_237 ) ,
L_20 V_238 L_21 V_222 L_14 ,
F_97 ( V_18 -> V_22 ) , F_90 ( & V_55 -> V_229 ) ) ;
F_13 ( V_18 ) ;
memcpy ( & V_225 , V_14 , sizeof( * V_14 ) ) ;
if ( F_17 ( NULL , V_239 , NULL ,
V_197 , & V_34 , V_240 , & V_225 , 0 ) ) {
F_98 ( V_14 ,
V_2 -> V_4 . V_5 . V_160 ) ;
memcpy ( V_14 , & V_225 , sizeof( V_225 ) ) ;
V_2 -> V_4 . V_5 . V_161 = V_14 -> V_162 ;
}
}
F_89 ( V_231 , L_22 ,
V_62 -> V_97 , V_62 -> V_241 , F_73 ( V_2 -> V_84 ) ,
V_2 -> V_4 . V_5 . V_8 , V_2 -> V_4 . V_5 . F_1 , V_38 ) ;
return V_38 ;
}
int F_99 ( struct V_13 * exp , struct V_1 * V_2 ,
struct V_32 * V_33 , T_1 * V_16 )
{
struct V_36 V_37 ;
struct V_21 V_14 ;
T_4 V_34 ;
T_2 V_35 ;
if ( V_2 -> V_4 . V_5 . V_161 ) {
V_14 . V_162 = V_2 -> V_4 . V_5 . V_161 ;
V_35 = F_100 ( & V_14 , V_16 ) ;
} else {
F_15 ( V_33 , & V_37 ) ;
switch ( V_2 -> V_84 ) {
case V_168 :
V_34 . V_30 . V_16 = V_87 |
V_187 |
V_242 ;
break;
case V_178 :
V_34 . V_30 . V_16 = V_190 ;
break;
default:
V_34 . V_30 . V_16 = V_187 ;
break;
}
V_35 = F_14 ( exp , V_239 , V_33 ,
V_197 , & V_34 ,
V_82 | V_81 | V_79 | V_243 ,
& V_14 ) ;
}
if ( V_35 ) {
V_2 -> V_4 . V_5 . V_161 = V_14 . V_162 ;
V_2 -> V_4 . V_5 . V_160 = V_35 ;
} else {
V_2 -> V_4 . V_5 . V_161 = 0 ;
V_2 -> V_4 . V_5 . V_160 = 0 ;
}
return ! ! V_35 ;
}
int F_101 ( struct V_13 * exp , struct V_61 * V_62 ,
void * V_63 , int V_64 , struct V_1 * V_2 ,
int V_244 , struct V_49 * * V_183 ,
T_8 V_245 ,
T_1 V_184 )
{
struct V_140 V_141 = {
. V_196 = V_197 ,
. V_155 = F_102 ( V_2 ) ,
. V_246 = V_245 ,
. V_247 = V_248 ,
} ;
struct V_21 V_14 ;
int V_38 = 0 ;
F_9 ( V_2 ) ;
F_89 ( V_249 , L_23 V_222 L_24 V_222
L_25 , V_62 -> V_97 ,
V_62 -> V_241 , F_90 ( & V_62 -> V_74 ) ,
F_90 ( & V_62 -> V_86 ) , F_73 ( V_2 -> V_84 ) ,
V_2 -> V_75 ) ;
V_14 . V_162 = 0 ;
if ( F_36 ( & V_62 -> V_74 ) &&
( V_2 -> V_84 & ( V_167 | V_168 ) ) ) {
V_2 -> V_4 . V_5 . V_161 = 0 ;
V_38 = F_99 ( exp , V_2 , & V_62 -> V_74 , NULL ) ;
if ( V_38 || V_62 -> V_97 != 0 )
return V_38 ;
}
if ( ! F_36 ( & V_62 -> V_74 ) && V_2 -> V_84 & V_85 ) {
V_38 = F_103 ( exp , & V_62 -> V_74 , V_62 ) ;
if ( V_38 < 0 ) {
F_5 ( L_26 , V_38 ) ;
return V_38 ;
}
}
V_38 = F_76 ( exp , & V_141 , V_2 , V_62 , & V_14 , V_63 , V_64 , NULL ,
V_184 ) ;
if ( V_38 < 0 )
return V_38 ;
* V_183 = V_2 -> V_4 . V_5 . V_163 ;
V_38 = F_92 ( exp , * V_183 , V_62 , V_2 , & V_14 ) ;
return V_38 ;
}
static int F_104 ( const struct V_250 * V_251 ,
struct V_49 * V_50 ,
void * args , int V_38 )
{
struct V_252 * V_253 = args ;
struct V_13 * exp = V_253 -> V_254 ;
struct V_255 * V_256 = V_253 -> V_257 ;
struct V_140 * V_141 = V_253 -> V_258 ;
struct V_1 * V_2 ;
struct V_21 * V_14 ;
struct V_41 * V_66 ;
struct V_146 * V_147 ;
T_1 V_31 = V_198 ;
V_2 = & V_256 -> V_259 ;
V_14 = & V_256 -> V_260 ;
V_66 = F_18 ( exp ) ;
F_86 ( & V_66 -> V_99 . V_100 ) ;
if ( F_105 ( V_261 ) )
V_38 = - V_215 ;
V_38 = F_106 ( exp , V_50 , V_141 -> V_196 , 1 , V_141 -> V_155 ,
& V_31 , NULL , 0 , V_14 , V_38 ) ;
if ( V_38 < 0 ) {
F_5 ( L_27 , V_38 ) ;
F_28 ( V_50 , V_38 ) ;
GOTO ( V_262 , V_38 ) ;
}
V_147 = F_64 ( & V_50 -> V_94 , & V_157 ) ;
F_9 ( V_147 != NULL ) ;
V_147 -> V_159 =
F_88 ( V_147 -> V_159 ) ;
V_38 = F_60 ( exp , V_50 , V_141 , V_2 , V_14 , V_38 ) ;
if ( V_38 )
GOTO ( V_262 , V_38 ) ;
V_38 = F_92 ( exp , V_50 , & V_256 -> V_263 , V_2 , V_14 ) ;
V_262:
F_107 ( V_141 ) ;
V_256 -> V_264 ( V_50 , V_256 , V_38 ) ;
return 0 ;
}
int F_108 ( struct V_13 * exp ,
struct V_255 * V_256 ,
struct V_140 * V_141 )
{
struct V_61 * V_62 = & V_256 -> V_263 ;
struct V_1 * V_2 = & V_256 -> V_259 ;
struct V_49 * V_50 ;
struct V_252 * V_253 ;
struct V_41 * V_66 = F_18 ( exp ) ;
struct V_36 V_37 ;
T_4 V_34 = {
. V_30 = { V_187 |
V_87 }
} ;
int V_38 = 0 ;
T_1 V_31 = V_198 ;
F_89 ( V_249 ,
L_28 V_222 L_25 ,
V_62 -> V_97 , V_62 -> V_241 , F_90 ( & V_62 -> V_86 ) ,
F_73 ( V_2 -> V_84 ) , V_2 -> V_75 ) ;
F_15 ( & V_62 -> V_86 , & V_37 ) ;
V_50 = F_56 ( exp , V_2 , V_62 ) ;
if ( F_78 ( V_50 ) )
return F_79 ( V_50 ) ;
V_38 = F_82 ( & V_66 -> V_99 . V_100 ) ;
if ( V_38 != 0 ) {
F_84 ( V_50 ) ;
return V_38 ;
}
V_38 = F_85 ( exp , & V_50 , V_141 , & V_37 , & V_34 , & V_31 , NULL ,
0 , V_265 , & V_256 -> V_260 , 1 ) ;
if ( V_38 < 0 ) {
F_86 ( & V_66 -> V_99 . V_100 ) ;
F_84 ( V_50 ) ;
return V_38 ;
}
F_109 ( sizeof( * V_253 ) <= sizeof( V_50 -> V_266 ) ) ;
V_253 = F_110 ( V_50 ) ;
V_253 -> V_254 = exp ;
V_253 -> V_257 = V_256 ;
V_253 -> V_258 = V_141 ;
V_50 -> V_267 = F_104 ;
F_111 ( V_50 , V_268 , - 1 ) ;
return 0 ;
}
