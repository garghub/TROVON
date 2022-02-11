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
V_66 -> V_99 . V_100 . V_119 ) ;
F_44 ( & V_50 -> V_94 , & V_106 , V_107 ,
V_66 -> V_99 . V_100 . V_120 ) ;
F_51 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_56 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_18 ( exp ) ;
T_7 V_59 = V_121 | V_60 |
V_122 | V_123 |
V_124 | V_125 |
( F_50 ( exp ) ?
V_126 : V_127 ) ;
struct V_67 * V_68 ;
int V_38 ;
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
F_57 ( V_50 , V_59 , V_2 -> V_75 , V_62 ,
V_66 -> V_99 . V_100 . V_119 ) ;
F_44 ( & V_50 -> V_94 , & V_118 , V_107 ,
V_66 -> V_99 . V_100 . V_119 ) ;
if ( F_50 ( exp ) )
F_44 ( & V_50 -> V_94 , & V_106 , V_107 ,
sizeof( struct V_108 ) ) ;
F_51 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_58 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_129 )
{
struct V_41 * V_42 = F_18 ( exp ) ;
struct V_49 * V_50 ;
struct V_67 * V_68 ;
struct V_130 * V_131 ;
int V_38 ;
V_50 = F_39 ( F_40 ( exp ) ,
& V_132 ) ;
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
V_131 = F_48 ( & V_50 -> V_94 , & V_133 ) ;
V_131 -> V_134 = V_135 ;
F_44 ( & V_50 -> V_94 , & V_136 , V_107 ,
V_42 -> V_99 . V_100 . V_119 ) ;
F_51 ( V_50 ) ;
return V_50 ;
}
static struct V_49 *
F_59 ( struct V_13 * exp , int V_137 )
{
struct V_49 * V_50 ;
int V_38 ;
V_50 = F_39 ( F_40 ( exp ) , & V_138 ) ;
if ( V_50 == NULL )
return F_42 ( - V_90 ) ;
V_38 = F_46 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_47 ( V_50 ) ;
return F_42 ( V_38 ) ;
}
F_44 ( & V_50 -> V_94 , & V_136 , V_107 , V_137 ) ;
F_51 ( V_50 ) ;
return V_50 ;
}
static int F_60 ( struct V_13 * exp ,
struct V_49 * V_50 ,
struct V_139 * V_140 ,
struct V_1 * V_2 ,
struct V_21 * V_14 ,
int V_38 )
{
struct V_141 * V_142 = & V_50 -> V_94 ;
struct V_143 * V_144 ;
struct V_145 * V_146 ;
struct V_147 * V_148 = & V_2 -> V_4 . V_5 ;
struct V_17 * V_18 ;
void * V_149 = NULL ;
int V_137 = 0 ;
F_9 ( V_38 >= 0 ) ;
if ( V_50 -> V_53 || V_50 -> V_51 ) {
V_144 = F_48 ( V_142 , & V_150 ) ;
V_144 -> V_151 |= F_61 ( V_152 ) ;
}
if ( V_38 == V_153 ) {
V_140 -> V_154 = 0 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_38 = 0 ;
} else {
V_18 = F_8 ( V_14 ) ;
F_9 ( V_18 != NULL ) ;
if ( V_18 -> V_155 != V_140 -> V_154 ) {
F_62 ( V_14 , V_18 -> V_155 ) ;
F_63 ( V_14 , V_140 -> V_154 ) ;
V_140 -> V_154 = V_18 -> V_155 ;
}
F_13 ( V_18 ) ;
}
V_146 = F_64 ( V_142 , & V_156 ) ;
F_9 ( V_146 != NULL ) ;
V_148 -> F_1 = ( int ) V_146 -> V_157 ;
V_148 -> V_8 = ( int ) V_146 -> V_158 ;
V_148 -> V_159 = V_140 -> V_154 ;
V_148 -> V_160 = V_14 -> V_161 ;
V_148 -> V_162 = V_50 ;
if ( ( ! V_50 -> V_53 || V_148 -> V_8 < 0 ) && V_50 -> V_51 )
F_28 ( V_50 , V_148 -> V_8 ) ;
if ( V_2 -> V_84 & V_163 && V_50 -> V_51 &&
( ! F_1 ( V_2 , V_9 ) || V_148 -> V_8 != 0 ) )
F_28 ( V_50 , V_148 -> V_8 ) ;
F_31 ( V_164 , V_50 , L_7 ,
V_2 -> V_84 , V_148 -> F_1 , V_148 -> V_8 ) ;
if ( V_2 -> V_84 & ( V_163 | V_165 | V_166 | V_167 ) ) {
struct V_55 * V_56 ;
V_56 = F_64 ( V_142 , & V_168 ) ;
if ( V_56 == NULL ) {
F_5 ( L_8 ) ;
return - V_169 ;
}
if ( F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_65 ( NULL , NULL , V_2 ) ;
}
if ( ( V_56 -> V_59 & ( V_123 | V_60 ) ) != 0 ) {
void * V_170 ;
F_66 ( exp , V_56 ) ;
V_170 = F_67 ( V_142 , & V_118 ,
V_56 -> V_58 ) ;
if ( V_170 == NULL )
return - V_169 ;
V_149 = V_170 ;
V_137 = V_56 -> V_58 ;
if ( ( V_2 -> V_84 & V_163 ) && V_50 -> V_51 ) {
void * V_63 ;
if ( F_68 ( V_142 , & V_98 ,
V_96 ) <
V_56 -> V_58 )
F_32 ( V_50 , V_56 ) ;
else
F_69 ( V_142 , & V_98 ,
V_56 -> V_58 ,
V_96 ) ;
F_44 ( V_142 , & V_98 ,
V_96 ,
V_56 -> V_58 ) ;
V_63 = F_48 ( V_142 , & V_98 ) ;
if ( V_63 )
memcpy ( V_63 , V_170 , V_56 -> V_58 ) ;
}
}
if ( V_56 -> V_59 & V_126 ) {
struct V_108 * V_171 ;
F_9 ( F_50 ( exp ) ) ;
V_171 = F_70 ( V_142 , & V_106 ,
V_172 ) ;
if ( V_171 == NULL )
return - V_169 ;
}
if ( V_56 -> V_59 & V_124 ) {
struct V_173 * V_174 , * V_175 ;
V_174 = F_64 ( V_142 , & V_91 ) ;
if ( V_174 == NULL )
return - V_169 ;
if ( V_2 -> V_84 & V_163 ) {
V_175 = F_48 ( V_142 , & V_93 ) ;
F_9 ( V_175 ) ;
* V_175 = * V_174 ;
}
}
if ( V_56 -> V_59 & V_176 ) {
struct V_173 * V_174 ;
V_174 = F_64 ( V_142 , & V_93 ) ;
if ( V_174 == NULL )
return - V_169 ;
}
} else if ( V_2 -> V_84 & V_177 ) {
V_137 = F_68 ( V_142 , & V_136 , V_107 ) ;
if ( V_137 > 0 ) {
V_149 = F_67 ( V_142 ,
& V_136 , V_137 ) ;
if ( V_149 == NULL )
return - V_169 ;
}
}
V_18 = F_8 ( V_14 ) ;
if ( V_18 != NULL && F_71 ( V_18 ) && V_149 != NULL ) {
void * V_63 ;
F_72 ( V_18 , L_9 ,
F_73 ( V_2 -> V_84 ) , V_137 ) ;
F_74 ( V_63 , V_137 ) ;
if ( V_63 == NULL ) {
F_13 ( V_18 ) ;
return - V_90 ;
}
memcpy ( V_63 , V_149 , V_137 ) ;
F_10 ( V_18 ) ;
if ( V_18 -> V_178 == NULL ) {
V_18 -> V_179 = V_180 ;
V_18 -> V_178 = V_63 ;
V_18 -> V_181 = V_137 ;
V_63 = NULL ;
}
F_12 ( V_18 ) ;
if ( V_63 != NULL )
F_75 ( V_63 , V_137 ) ;
}
if ( V_18 != NULL )
F_13 ( V_18 ) ;
return V_38 ;
}
int F_76 ( struct V_13 * exp , struct V_139 * V_140 ,
struct V_1 * V_2 , struct V_61 * V_62 ,
struct V_21 * V_14 , void * V_63 , int V_64 ,
struct V_49 * * V_182 , T_1 V_183 )
{
struct V_41 * V_66 = F_18 ( exp ) ;
struct V_49 * V_50 = NULL ;
T_1 V_31 , V_184 = V_183 ;
int V_38 ;
struct V_36 V_37 ;
static const T_4 V_185 =
{ . V_30 = { V_186 } } ;
static const T_4 V_187 =
{ . V_30 = { V_87 } } ;
static const T_4 V_188 =
{ . V_30 = { V_189 } } ;
static const T_4 V_190 = {
. V_30 = { V_191 } } ;
T_4 const * V_34 = & V_185 ;
int V_192 , V_193 = 0 ;
struct V_145 * V_146 ;
enum V_194 V_194 = 0 ;
F_11 ( ! V_2 || V_140 -> V_195 == V_196 , L_10 ,
V_140 -> V_195 ) ;
F_15 ( & V_62 -> V_86 , & V_37 ) ;
if ( V_2 ) {
V_184 |= V_197 ;
if ( V_2 -> V_84 & ( V_165 | V_167 | V_198 ) )
V_34 = & V_187 ;
else if ( V_2 -> V_84 & V_177 )
V_34 = & V_188 ;
else if ( V_2 -> V_84 & ( V_111 | V_199 ) )
V_34 = & V_190 ;
}
F_9 ( V_182 == NULL ) ;
V_192 = V_66 -> V_99 . V_100 . V_200 -> V_201 ;
V_202:
V_31 = V_184 ;
if ( ! V_2 ) {
F_9 ( V_63 && V_64 == 0 ) ;
F_11 ( V_140 -> V_195 == V_203 , L_10 ,
V_140 -> V_195 ) ;
V_34 = ( T_4 * ) V_63 ;
V_37 . V_204 [ 3 ] = V_203 ;
} else if ( V_2 -> V_84 & V_163 ) {
V_50 = F_34 ( exp , V_2 , V_62 , V_63 , V_64 ,
V_140 -> V_205 ) ;
V_34 = & V_187 ;
V_140 -> V_205 = NULL ;
V_63 = NULL ;
} else if ( V_2 -> V_84 & V_165 ) {
V_50 = F_54 ( exp , V_2 , V_62 ) ;
} else if ( V_2 -> V_84 & ( V_167 | V_166 ) ) {
V_50 = F_56 ( exp , V_2 , V_62 ) ;
} else if ( V_2 -> V_84 & V_198 ) {
V_50 = F_59 ( exp , 0 ) ;
} else if ( V_2 -> V_84 & V_177 ) {
if ( ! F_77 ( F_40 ( exp ) ) )
return - V_206 ;
V_50 = F_58 ( exp , V_2 , V_62 ) ;
V_194 = V_180 ;
} else if ( V_2 -> V_84 & V_111 ) {
V_50 = F_52 ( exp , V_2 , V_62 ) ;
} else {
F_6 () ;
return - V_207 ;
}
if ( F_78 ( V_50 ) )
return F_79 ( V_50 ) ;
if ( V_50 != NULL && V_2 && V_2 -> V_84 & V_85 )
V_50 -> V_208 = 1 ;
if ( V_193 ) {
V_50 -> V_209 = 1 ;
V_50 -> V_210 = V_192 ;
V_50 -> V_211 = F_80 () + V_193 ;
}
if ( V_2 ) {
F_81 ( V_66 -> V_99 . V_100 . V_212 , V_2 ) ;
V_38 = F_82 ( & V_66 -> V_99 . V_100 ) ;
if ( V_38 != 0 ) {
F_83 ( V_66 -> V_99 . V_100 . V_212 , V_2 ) ;
F_28 ( V_50 , 0 ) ;
F_84 ( V_50 ) ;
return V_38 ;
}
}
V_38 = F_85 ( exp , & V_50 , V_140 , & V_37 , V_34 , & V_31 , NULL ,
0 , V_194 , V_14 , 0 ) ;
if ( ! V_2 ) {
if ( ( V_38 == - V_213 ) || ( V_38 == - V_214 ) )
goto V_202;
return V_38 ;
}
F_86 ( & V_66 -> V_99 . V_100 ) ;
F_83 ( V_66 -> V_99 . V_100 . V_212 , V_2 ) ;
if ( V_38 < 0 ) {
F_5 ( L_11 , V_38 ) ;
F_28 ( V_50 , V_38 ) ;
F_84 ( V_50 ) ;
return V_38 ;
}
V_146 = F_64 ( & V_50 -> V_94 , & V_156 ) ;
F_9 ( V_146 != NULL ) ;
V_146 -> V_158 =
F_87 ( V_146 -> V_158 ) ;
if ( V_2 && V_2 -> V_84 & V_85 &&
( int ) V_146 -> V_158 == - V_215 ) {
F_28 ( V_50 , V_38 ) ;
F_84 ( V_50 ) ;
V_193 ++ ;
F_88 ( V_216 , L_12 V_217 L_13 V_217 L_14 ,
V_66 -> V_218 , V_193 , V_2 -> V_84 ,
F_89 ( & V_62 -> V_86 ) , F_89 ( & V_62 -> V_74 ) ) ;
if ( V_192 == V_66 -> V_99 . V_100 . V_200 -> V_201 ) {
goto V_202;
} else {
F_88 ( V_216 , L_15 ) ;
return - V_219 ;
}
}
V_38 = F_60 ( exp , V_50 , V_140 , V_2 , V_14 , V_38 ) ;
if ( V_38 < 0 ) {
if ( F_90 ( V_14 ) ) {
F_63 ( V_14 , V_140 -> V_154 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
}
F_84 ( V_50 ) ;
}
return V_38 ;
}
static int F_91 ( struct V_13 * exp ,
struct V_49 * V_220 ,
struct V_61 * V_62 ,
struct V_1 * V_2 ,
struct V_21 * V_14 )
{
struct V_21 V_221 ;
struct V_55 * V_55 ;
struct V_17 * V_18 ;
int V_38 ;
F_9 ( V_220 != NULL ) ;
F_9 ( V_220 != V_222 ) ;
F_9 ( V_220 -> V_223 != V_222 ) ;
if ( ! F_1 ( V_2 , V_12 ) ) {
F_9 ( V_2 -> V_4 . V_5 . V_8 != 0 ) ;
return V_2 -> V_4 . V_5 . V_8 ;
}
V_38 = F_4 ( V_12 , V_2 ) ;
if ( V_38 )
return V_38 ;
V_55 = F_64 ( & V_220 -> V_94 , & V_168 ) ;
F_9 ( V_55 != NULL ) ;
if ( F_36 ( & V_62 -> V_74 ) &&
V_2 -> V_71 & V_224 &&
V_2 -> V_84 != V_167 ) {
if ( ( ! F_92 ( & V_62 -> V_74 , & V_55 -> V_225 ) ) &&
( ! F_92 ( & V_62 -> V_226 , & V_55 -> V_225 ) ) ) {
F_88 ( V_227 , L_16 V_217 L_17 V_217 L_18 V_217
L_14 , F_89 ( & V_62 -> V_74 ) ,
F_89 ( & V_62 -> V_74 ) , F_89 ( & V_55 -> V_225 ) ) ;
return - V_228 ;
}
}
V_38 = F_4 ( V_11 , V_2 ) ;
if ( V_38 )
return V_38 ;
if ( ! F_1 ( V_2 , V_229 ) &&
F_1 ( V_2 , V_10 ) &&
! F_4 ( V_10 , V_2 ) ) {
F_2 ( V_2 , V_229 ) ;
F_93 ( V_220 ) ;
}
if ( ! F_1 ( V_2 , V_230 ) &&
F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_2 ( V_2 , V_230 ) ;
F_93 ( V_220 ) ;
F_94 ( V_231 , V_232 ) ;
}
if ( V_2 -> V_84 & V_85 ) {
} else if ( V_2 -> V_84 == V_163 ) {
F_9 ( ! F_1 ( V_2 , V_10 ) ) ;
} else {
F_9 ( V_2 -> V_84 & ( V_167 | V_166 | V_177 ) ) ;
}
V_18 = F_8 ( V_14 ) ;
if ( V_18 ) {
T_4 V_34 = V_18 -> V_29 ;
F_72 ( V_18 , L_19 ) ;
F_11 ( F_95 ( & V_55 -> V_225 ,
& V_18 -> V_22 -> V_233 ) ,
L_20 V_234 L_21 V_217 L_14 ,
F_96 ( V_18 -> V_22 ) , F_89 ( & V_55 -> V_225 ) ) ;
F_13 ( V_18 ) ;
memcpy ( & V_221 , V_14 , sizeof( * V_14 ) ) ;
if ( F_17 ( NULL , V_235 , NULL ,
V_196 , & V_34 , V_236 , & V_221 , 0 ) ) {
F_97 ( V_14 ,
V_2 -> V_4 . V_5 . V_159 ) ;
memcpy ( V_14 , & V_221 , sizeof( V_221 ) ) ;
V_2 -> V_4 . V_5 . V_160 = V_14 -> V_161 ;
}
}
F_88 ( V_227 , L_22 ,
V_62 -> V_97 , V_62 -> V_237 , F_73 ( V_2 -> V_84 ) ,
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
if ( V_2 -> V_4 . V_5 . V_160 ) {
V_14 . V_161 = V_2 -> V_4 . V_5 . V_160 ;
V_35 = F_99 ( & V_14 , V_16 ) ;
} else {
F_15 ( V_33 , & V_37 ) ;
switch ( V_2 -> V_84 ) {
case V_167 :
V_34 . V_30 . V_16 = V_87 |
V_186 |
V_238 ;
break;
case V_177 :
V_34 . V_30 . V_16 = V_189 ;
break;
default:
V_34 . V_30 . V_16 = V_186 ;
break;
}
V_35 = F_14 ( exp , V_235 , V_33 ,
V_196 , & V_34 ,
V_82 | V_81 | V_79 | V_239 ,
& V_14 ) ;
}
if ( V_35 ) {
V_2 -> V_4 . V_5 . V_160 = V_14 . V_161 ;
V_2 -> V_4 . V_5 . V_159 = V_35 ;
} else {
V_2 -> V_4 . V_5 . V_160 = 0 ;
V_2 -> V_4 . V_5 . V_159 = 0 ;
}
return ! ! V_35 ;
}
int F_100 ( struct V_13 * exp , struct V_61 * V_62 ,
void * V_63 , int V_64 , struct V_1 * V_2 ,
int V_240 , struct V_49 * * V_182 ,
T_8 V_241 ,
T_1 V_183 )
{
struct V_139 V_140 = {
. V_195 = V_196 ,
. V_154 = F_101 ( V_2 ) ,
. V_242 = V_241 ,
. V_243 = V_244 ,
} ;
struct V_21 V_14 ;
int V_38 = 0 ;
F_9 ( V_2 ) ;
F_88 ( V_245 , L_23 V_217 L_24 V_217
L_25 , V_62 -> V_97 ,
V_62 -> V_237 , F_89 ( & V_62 -> V_74 ) ,
F_89 ( & V_62 -> V_86 ) , F_73 ( V_2 -> V_84 ) ,
V_2 -> V_75 ) ;
V_14 . V_161 = 0 ;
if ( F_36 ( & V_62 -> V_74 ) &&
( V_2 -> V_84 & ( V_166 | V_167 ) ) ) {
V_2 -> V_4 . V_5 . V_160 = 0 ;
V_38 = F_98 ( exp , V_2 , & V_62 -> V_74 , NULL ) ;
if ( V_38 || V_62 -> V_97 != 0 )
return V_38 ;
}
if ( ! F_36 ( & V_62 -> V_74 ) && V_2 -> V_84 & V_85 ) {
V_38 = F_102 ( exp , & V_62 -> V_74 , V_62 ) ;
if ( V_38 < 0 ) {
F_5 ( L_26 , V_38 ) ;
return V_38 ;
}
}
V_38 = F_76 ( exp , & V_140 , V_2 , V_62 , & V_14 , V_63 , V_64 , NULL ,
V_183 ) ;
if ( V_38 < 0 )
return V_38 ;
* V_182 = V_2 -> V_4 . V_5 . V_162 ;
V_38 = F_91 ( exp , * V_182 , V_62 , V_2 , & V_14 ) ;
return V_38 ;
}
static int F_103 ( const struct V_246 * V_247 ,
struct V_49 * V_50 ,
void * args , int V_38 )
{
struct V_248 * V_249 = args ;
struct V_13 * exp = V_249 -> V_250 ;
struct V_251 * V_252 = V_249 -> V_253 ;
struct V_139 * V_140 = V_249 -> V_254 ;
struct V_1 * V_2 ;
struct V_21 * V_14 ;
struct V_41 * V_66 ;
struct V_145 * V_146 ;
T_1 V_31 = V_197 ;
V_2 = & V_252 -> V_255 ;
V_14 = & V_252 -> V_256 ;
V_66 = F_18 ( exp ) ;
F_86 ( & V_66 -> V_99 . V_100 ) ;
if ( F_104 ( V_257 ) )
V_38 = - V_214 ;
V_38 = F_105 ( exp , V_50 , V_140 -> V_195 , 1 , V_140 -> V_154 ,
& V_31 , NULL , 0 , V_14 , V_38 ) ;
if ( V_38 < 0 ) {
F_5 ( L_27 , V_38 ) ;
F_28 ( V_50 , V_38 ) ;
GOTO ( V_258 , V_38 ) ;
}
V_146 = F_64 ( & V_50 -> V_94 , & V_156 ) ;
F_9 ( V_146 != NULL ) ;
V_146 -> V_158 =
F_87 ( V_146 -> V_158 ) ;
V_38 = F_60 ( exp , V_50 , V_140 , V_2 , V_14 , V_38 ) ;
if ( V_38 )
GOTO ( V_258 , V_38 ) ;
V_38 = F_91 ( exp , V_50 , & V_252 -> V_259 , V_2 , V_14 ) ;
V_258:
F_106 ( V_140 ) ;
V_252 -> V_260 ( V_50 , V_252 , V_38 ) ;
return 0 ;
}
int F_107 ( struct V_13 * exp ,
struct V_251 * V_252 ,
struct V_139 * V_140 )
{
struct V_61 * V_62 = & V_252 -> V_259 ;
struct V_1 * V_2 = & V_252 -> V_255 ;
struct V_49 * V_50 ;
struct V_248 * V_249 ;
struct V_41 * V_66 = F_18 ( exp ) ;
struct V_36 V_37 ;
T_4 V_34 = {
. V_30 = { V_186 |
V_87 }
} ;
int V_38 = 0 ;
T_1 V_31 = V_197 ;
F_88 ( V_245 ,
L_28 V_217 L_25 ,
V_62 -> V_97 , V_62 -> V_237 , F_89 ( & V_62 -> V_86 ) ,
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
V_38 = F_85 ( exp , & V_50 , V_140 , & V_37 , & V_34 , & V_31 , NULL ,
0 , V_261 , & V_252 -> V_256 , 1 ) ;
if ( V_38 < 0 ) {
F_86 ( & V_66 -> V_99 . V_100 ) ;
F_84 ( V_50 ) ;
return V_38 ;
}
F_108 ( sizeof( * V_249 ) <= sizeof( V_50 -> V_262 ) ) ;
V_249 = F_109 ( V_50 ) ;
V_249 -> V_250 = exp ;
V_249 -> V_253 = V_252 ;
V_249 -> V_254 = V_140 ;
V_50 -> V_263 = F_103 ;
F_110 ( V_50 , V_264 , - 1 ) ;
return 0 ;
}
