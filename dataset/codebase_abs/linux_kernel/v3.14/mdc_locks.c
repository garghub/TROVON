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
if( V_16 )
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
V_38 = F_16 ( F_17 ( exp ) -> V_39 , V_31 ,
& V_37 , type , V_34 , V_35 , V_14 , 0 ) ;
return V_38 ;
}
int F_18 ( struct V_13 * exp ,
const struct V_32 * V_33 ,
T_4 * V_34 ,
T_2 V_35 ,
T_5 V_31 ,
void * V_40 )
{
struct V_36 V_37 ;
struct V_41 * V_42 = F_17 ( exp ) ;
int V_38 ;
F_15 ( V_33 , & V_37 ) ;
V_38 = F_19 ( V_42 -> V_39 , & V_37 ,
V_34 , V_35 , V_31 , V_40 ) ;
return V_38 ;
}
int F_20 ( struct V_13 * exp ,
const struct V_32 * V_33 )
{
struct V_36 V_37 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = F_17 ( exp ) -> V_39 ;
F_11 ( V_46 != NULL , L_4 ) ;
F_15 ( V_33 , & V_37 ) ;
V_44 = F_21 ( V_46 , NULL , & V_37 , 0 , 0 ) ;
if( V_44 == NULL )
return 0 ;
F_22 ( V_44 ) ;
V_44 -> V_23 = NULL ;
F_23 ( V_44 ) ;
F_24 ( V_44 ) ;
return 0 ;
}
int F_25 ( struct V_13 * exp ,
const struct V_32 * V_33 ,
T_6 V_2 , void * V_15 )
{
struct V_36 V_37 ;
int V_38 = 0 ;
F_15 ( (struct V_32 * ) V_33 , & V_37 ) ;
V_38 = F_26 ( F_17 ( exp ) -> V_39 , & V_37 ,
V_2 , V_15 ) ;
if ( V_38 == V_47 )
return 1 ;
else if ( V_38 == V_48 )
return 0 ;
return V_38 ;
}
static inline void F_27 ( struct V_49 * V_50 , int V_38 )
{
if ( V_50 -> V_51 ) {
F_28 ( & V_50 -> V_52 ) ;
V_50 -> V_51 = 0 ;
F_29 ( & V_50 -> V_52 ) ;
}
if ( V_38 && V_50 -> V_53 != 0 ) {
F_30 ( V_54 , V_50 , L_5 , V_38 ) ;
F_6 () ;
}
}
static void F_31 ( struct V_49 * V_50 ,
struct V_55 * V_56 )
{
int V_38 ;
V_38 = F_32 ( V_50 , V_57 + 4 ,
V_56 -> V_58 ) ;
if ( V_38 ) {
F_5 ( L_6 ,
V_57 + 4 , V_56 -> V_58 ) ;
V_56 -> V_59 &= ~ V_60 ;
V_56 -> V_58 = 0 ;
}
}
static struct V_49 * F_33 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 ,
void * V_63 , int V_64 ,
void * V_65 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_17 ( exp ) ;
struct V_67 * V_68 ;
F_34 ( V_69 ) ;
int V_70 = 0 ;
int V_35 ;
int V_38 ;
V_2 -> V_71 = ( V_2 -> V_71 & ~ V_72 ) | V_73 ;
if ( F_35 ( & V_62 -> V_74 ) ) {
if ( V_2 -> V_75 & V_76 ) {
if ( V_2 -> V_75 & V_77 )
V_35 = V_78 ;
else
V_35 = V_79 ;
} else {
if ( V_2 -> V_75 & ( V_77 | V_80 ) )
V_35 = V_81 ;
#ifdef F_36
else if ( V_2 -> V_75 & F_36 )
V_35 = V_79 ;
#endif
else
V_35 = V_82 ;
}
V_70 = F_37 ( exp , & V_62 -> V_74 ,
& V_69 , V_35 ,
V_83 ) ;
}
if ( V_2 -> V_84 & V_85 )
V_35 = V_78 ;
else
V_35 = V_82 ;
V_70 += F_37 ( exp , & V_62 -> V_86 ,
& V_69 , V_35 ,
V_87 ) ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_88 ) ;
if ( V_50 == NULL ) {
F_40 ( & V_69 , V_89 , V_70 ) ;
return F_41 ( - V_90 ) ;
}
F_42 ( V_50 , & V_91 , V_62 -> V_92 ) ;
F_42 ( V_50 , & V_93 , V_62 -> V_92 ) ;
F_43 ( & V_50 -> V_94 , & V_95 , V_96 ,
V_62 -> V_97 + 1 ) ;
F_43 ( & V_50 -> V_94 , & V_98 , V_96 ,
F_44 ( V_64 , V_66 -> V_99 . V_100 . V_101 ) ) ;
V_38 = F_45 ( exp , V_50 , & V_69 , V_70 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
return NULL ;
}
F_28 ( & V_50 -> V_52 ) ;
V_50 -> V_51 = V_50 -> V_102 -> V_103 ;
F_29 ( & V_50 -> V_52 ) ;
V_68 = F_47 ( & V_50 -> V_94 , & V_104 ) ;
V_68 -> V_105 = ( T_1 ) V_2 -> V_84 ;
F_48 ( V_50 , V_62 , V_2 -> V_71 , 0 , V_2 -> V_75 , V_63 ,
V_64 ) ;
if ( F_49 ( exp ) )
F_43 ( & V_50 -> V_94 , & V_106 , V_107 ,
sizeof( struct V_108 ) ) ;
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
int V_38 , V_70 = 0 , V_109 ;
F_34 ( V_69 ) ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_110 ) ;
if ( V_50 == NULL )
return F_41 ( - V_90 ) ;
F_42 ( V_50 , & V_91 , V_62 -> V_92 ) ;
if ( V_2 -> V_84 == V_111 )
V_70 = F_37 ( exp , & V_62 -> V_86 ,
& V_69 , V_112 ,
V_113 ) ;
V_38 = F_45 ( exp , V_50 , & V_69 , V_70 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
V_68 = F_47 ( & V_50 -> V_94 , & V_104 ) ;
V_68 -> V_105 = V_114 ;
V_109 = F_39 ( exp ) -> V_115 . V_116 ;
F_52 ( V_50 , & V_62 -> V_86 , V_62 -> V_92 ,
V_62 -> V_117 , V_109 , - 1 , 0 ) ;
F_43 ( & V_50 -> V_94 , & V_98 ,
V_107 , V_109 ) ;
F_43 ( & V_50 -> V_94 , & V_118 ,
V_107 , V_109 ) ;
F_43 ( & V_50 -> V_94 , & V_119 ,
V_107 , V_109 ) ;
F_50 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_53 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_17 ( exp ) ;
struct V_67 * V_68 ;
int V_38 ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_120 ) ;
if ( V_50 == NULL )
return F_41 ( - V_90 ) ;
F_42 ( V_50 , & V_91 , V_62 -> V_92 ) ;
F_43 ( & V_50 -> V_94 , & V_95 , V_96 ,
V_62 -> V_97 + 1 ) ;
V_38 = F_45 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
V_68 = F_47 ( & V_50 -> V_94 , & V_104 ) ;
V_68 -> V_105 = ( T_1 ) V_2 -> V_84 ;
F_54 ( V_50 , V_62 ) ;
F_43 ( & V_50 -> V_94 , & V_121 , V_107 ,
V_66 -> V_99 . V_100 . V_122 ) ;
F_43 ( & V_50 -> V_94 , & V_106 , V_107 ,
V_66 -> V_99 . V_100 . V_123 ) ;
F_50 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_55 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_17 ( exp ) ;
T_7 V_59 = V_124 | V_60 |
V_125 | V_126 |
V_127 | V_128 |
( F_49 ( exp ) ?
V_129 : V_130 ) ;
struct V_67 * V_68 ;
int V_38 ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_131 ) ;
if ( V_50 == NULL )
return F_41 ( - V_90 ) ;
F_42 ( V_50 , & V_91 , V_62 -> V_92 ) ;
F_43 ( & V_50 -> V_94 , & V_95 , V_96 ,
V_62 -> V_97 + 1 ) ;
V_38 = F_45 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
V_68 = F_47 ( & V_50 -> V_94 , & V_104 ) ;
V_68 -> V_105 = ( T_1 ) V_2 -> V_84 ;
F_56 ( V_50 , V_59 , V_2 -> V_75 , V_62 ,
V_66 -> V_99 . V_100 . V_122 ) ;
F_43 ( & V_50 -> V_94 , & V_121 , V_107 ,
V_66 -> V_99 . V_100 . V_122 ) ;
if ( F_49 ( exp ) )
F_43 ( & V_50 -> V_94 , & V_106 , V_107 ,
sizeof( struct V_108 ) ) ;
F_50 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_57 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_132 )
{
struct V_41 * V_42 = F_17 ( exp ) ;
struct V_49 * V_50 ;
struct V_67 * V_68 ;
struct V_133 * V_134 ;
int V_38 ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_135 ) ;
if ( V_50 == NULL )
return F_41 ( - V_90 ) ;
F_43 ( & V_50 -> V_94 , & V_98 , V_96 , 0 ) ;
V_38 = F_45 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
V_68 = F_47 ( & V_50 -> V_94 , & V_104 ) ;
V_68 -> V_105 = ( T_1 ) V_2 -> V_84 ;
V_134 = F_47 ( & V_50 -> V_94 , & V_136 ) ;
V_134 -> V_137 = V_138 ;
F_43 ( & V_50 -> V_94 , & V_139 , V_107 ,
V_42 -> V_99 . V_100 . V_122 ) ;
F_50 ( V_50 ) ;
return V_50 ;
}
static struct V_49 *
F_58 ( struct V_13 * exp , int V_140 )
{
struct V_49 * V_50 ;
int V_38 ;
V_50 = F_38 ( F_39 ( exp ) , & V_141 ) ;
if ( V_50 == NULL )
return F_41 ( - V_90 ) ;
V_38 = F_45 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
F_43 ( & V_50 -> V_94 , & V_139 , V_107 , V_140 ) ;
F_50 ( V_50 ) ;
return V_50 ;
}
static int F_59 ( struct V_13 * exp ,
struct V_49 * V_50 ,
struct V_142 * V_143 ,
struct V_1 * V_2 ,
struct V_21 * V_14 ,
int V_38 )
{
struct V_144 * V_145 = & V_50 -> V_94 ;
struct V_146 * V_147 ;
struct V_148 * V_149 ;
struct V_150 * V_151 = & V_2 -> V_4 . V_5 ;
struct V_17 * V_18 ;
void * V_152 = NULL ;
int V_140 = 0 ;
F_9 ( V_38 >= 0 ) ;
if ( V_50 -> V_53 || V_50 -> V_51 ) {
V_147 = F_47 ( V_145 , & V_153 ) ;
V_147 -> V_154 |= F_60 ( V_155 ) ;
}
if ( V_38 == V_156 ) {
V_143 -> V_157 = 0 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_38 = 0 ;
} else {
V_18 = F_8 ( V_14 ) ;
F_9 ( V_18 != NULL ) ;
if ( V_18 -> V_158 != V_143 -> V_157 ) {
F_61 ( V_14 , V_18 -> V_158 ) ;
F_62 ( V_14 , V_143 -> V_157 ) ;
V_143 -> V_157 = V_18 -> V_158 ;
}
F_13 ( V_18 ) ;
}
V_149 = F_63 ( V_145 , & V_159 ) ;
F_9 ( V_149 != NULL ) ;
V_151 -> F_1 = ( int ) V_149 -> V_160 ;
V_151 -> V_8 = ( int ) V_149 -> V_161 ;
V_151 -> V_162 = V_143 -> V_157 ;
V_151 -> V_163 = V_14 -> V_164 ;
V_151 -> V_165 = V_50 ;
if ( ( ! V_50 -> V_53 || V_151 -> V_8 < 0 ) && V_50 -> V_51 )
F_27 ( V_50 , V_151 -> V_8 ) ;
if ( V_2 -> V_84 & V_166 && V_50 -> V_51 &&
( ! F_1 ( V_2 , V_9 ) || V_151 -> V_8 != 0 ) )
F_27 ( V_50 , V_151 -> V_8 ) ;
F_30 ( V_167 , V_50 , L_7 ,
V_2 -> V_84 , V_151 -> F_1 , V_151 -> V_8 ) ;
if ( V_2 -> V_84 & ( V_166 | V_168 | V_169 | V_170 ) ) {
struct V_55 * V_56 ;
V_56 = F_63 ( V_145 , & V_171 ) ;
if ( V_56 == NULL ) {
F_5 ( L_8 ) ;
return - V_172 ;
}
if ( F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_64 ( NULL , NULL , V_50 ) ;
}
if ( ( V_56 -> V_59 & ( V_126 | V_60 ) ) != 0 ) {
void * V_173 ;
F_65 ( exp , V_56 ) ;
V_173 = F_66 ( V_145 , & V_121 ,
V_56 -> V_58 ) ;
if ( V_173 == NULL )
return - V_172 ;
V_152 = V_173 ;
V_140 = V_56 -> V_58 ;
if ( ( V_2 -> V_84 & V_166 ) && V_50 -> V_51 ) {
void * V_63 ;
if ( F_67 ( V_145 , & V_98 ,
V_96 ) <
V_56 -> V_58 )
F_31 ( V_50 , V_56 ) ;
else
F_68 ( V_145 , & V_98 ,
V_56 -> V_58 ,
V_96 ) ;
F_43 ( V_145 , & V_98 ,
V_96 ,
V_56 -> V_58 ) ;
V_63 = F_47 ( V_145 , & V_98 ) ;
if ( V_63 )
memcpy ( V_63 , V_173 , V_56 -> V_58 ) ;
}
}
if ( V_56 -> V_59 & V_129 ) {
struct V_108 * V_174 ;
F_9 ( F_49 ( exp ) ) ;
V_174 = F_69 ( V_145 , & V_106 ,
V_175 ) ;
if ( V_174 == NULL )
return - V_172 ;
}
if ( V_56 -> V_59 & V_127 ) {
struct V_176 * V_177 , * V_178 ;
V_177 = F_63 ( V_145 , & V_91 ) ;
if ( V_177 == NULL )
return - V_172 ;
if ( V_2 -> V_84 & V_166 ) {
V_178 = F_47 ( V_145 , & V_93 ) ;
F_9 ( V_178 ) ;
* V_178 = * V_177 ;
}
}
if ( V_56 -> V_59 & V_179 ) {
struct V_176 * V_177 ;
V_177 = F_63 ( V_145 , & V_93 ) ;
if ( V_177 == NULL )
return - V_172 ;
}
} else if ( V_2 -> V_84 & V_180 ) {
V_140 = F_67 ( V_145 , & V_139 , V_107 ) ;
if ( V_140 > 0 ) {
V_152 = F_66 ( V_145 ,
& V_139 , V_140 ) ;
if ( V_152 == NULL )
return - V_172 ;
}
}
V_18 = F_8 ( V_14 ) ;
if ( V_18 != NULL && F_70 ( V_18 ) && V_152 != NULL ) {
void * V_63 ;
F_71 ( V_18 , L_9 ,
F_72 ( V_2 -> V_84 ) , V_140 ) ;
F_73 ( V_63 , V_140 ) ;
if ( V_63 == NULL ) {
F_13 ( V_18 ) ;
return - V_90 ;
}
memcpy ( V_63 , V_152 , V_140 ) ;
F_10 ( V_18 ) ;
if ( V_18 -> V_181 == NULL ) {
V_18 -> V_181 = V_63 ;
V_18 -> V_182 = V_140 ;
V_63 = NULL ;
}
F_12 ( V_18 ) ;
if ( V_63 != NULL )
F_74 ( V_63 , V_140 ) ;
}
if ( V_18 != NULL )
F_13 ( V_18 ) ;
return V_38 ;
}
int F_75 ( struct V_13 * exp , struct V_142 * V_143 ,
struct V_1 * V_2 , struct V_61 * V_62 ,
struct V_21 * V_14 , void * V_63 , int V_64 ,
struct V_49 * * V_183 , T_1 V_184 )
{
struct V_41 * V_66 = F_17 ( exp ) ;
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
. V_30 = { V_113 } } ;
T_4 const * V_34 = & V_186 ;
int V_192 , V_193 = 0 ;
struct V_148 * V_149 ;
enum V_194 V_194 = 0 ;
F_11 ( ! V_2 || V_143 -> V_195 == V_196 , L_10 ,
V_143 -> V_195 ) ;
F_15 ( & V_62 -> V_86 , & V_37 ) ;
if ( V_2 ) {
V_185 |= V_197 ;
if ( V_2 -> V_84 & ( V_168 | V_170 | V_198 ) )
V_34 = & V_188 ;
else if ( V_2 -> V_84 & V_180 )
V_34 = & V_189 ;
else if ( V_2 -> V_84 & ( V_114 | V_111 ) )
V_34 = & V_191 ;
}
F_9 ( V_183 == NULL ) ;
V_192 = V_66 -> V_99 . V_100 . V_199 -> V_200 ;
V_201:
V_31 = V_185 ;
if ( ! V_2 ) {
F_9 ( V_63 && V_64 == 0 ) ;
F_11 ( V_143 -> V_195 == V_202 , L_10 ,
V_143 -> V_195 ) ;
V_34 = ( T_4 * ) V_63 ;
V_37 . V_203 [ 3 ] = V_202 ;
} else if ( V_2 -> V_84 & V_166 ) {
V_50 = F_33 ( exp , V_2 , V_62 , V_63 , V_64 ,
V_143 -> V_204 ) ;
V_34 = & V_188 ;
V_143 -> V_204 = NULL ;
V_63 = NULL ;
} else if ( V_2 -> V_84 & V_168 ) {
V_50 = F_53 ( exp , V_2 , V_62 ) ;
} else if ( V_2 -> V_84 & ( V_170 | V_169 ) ) {
V_50 = F_55 ( exp , V_2 , V_62 ) ;
} else if ( V_2 -> V_84 & V_198 ) {
V_50 = F_58 ( exp , 0 ) ;
} else if ( V_2 -> V_84 & V_180 ) {
if ( ! F_76 ( F_39 ( exp ) ) )
return - V_205 ;
V_50 = F_57 ( exp , V_2 , V_62 ) ;
V_194 = V_206 ;
} else if ( V_2 -> V_84 & ( V_114 | V_111 ) ) {
V_50 = F_51 ( exp , V_2 , V_62 ) ;
} else {
F_6 () ;
return - V_207 ;
}
if ( F_77 ( V_50 ) )
return F_78 ( V_50 ) ;
if ( V_50 != NULL && V_2 && V_2 -> V_84 & V_85 )
V_50 -> V_208 = 1 ;
if ( V_193 ) {
V_50 -> V_209 = 1 ;
V_50 -> V_210 = V_192 ;
V_50 -> V_211 = F_79 () + V_193 ;
}
if ( V_2 ) {
F_80 ( V_66 -> V_99 . V_100 . V_212 , V_2 ) ;
V_38 = F_81 ( & V_66 -> V_99 . V_100 ) ;
if ( V_38 != 0 ) {
F_82 ( V_66 -> V_99 . V_100 . V_212 , V_2 ) ;
F_27 ( V_50 , 0 ) ;
F_83 ( V_50 ) ;
return V_38 ;
}
}
V_38 = F_84 ( exp , & V_50 , V_143 , & V_37 , V_34 , & V_31 , NULL ,
0 , V_194 , V_14 , 0 ) ;
if ( ! V_2 ) {
if ( ( V_38 == - V_213 ) || ( V_38 == - V_214 ) )
goto V_201;
return V_38 ;
}
F_85 ( & V_66 -> V_99 . V_100 ) ;
F_82 ( V_66 -> V_99 . V_100 . V_212 , V_2 ) ;
if ( V_38 < 0 ) {
F_5 ( L_11 , V_38 ) ;
F_27 ( V_50 , V_38 ) ;
F_83 ( V_50 ) ;
return V_38 ;
}
V_149 = F_63 ( & V_50 -> V_94 , & V_159 ) ;
F_9 ( V_149 != NULL ) ;
V_149 -> V_161 =
F_86 ( V_149 -> V_161 ) ;
if ( V_2 && V_2 -> V_84 & V_85 &&
( int ) V_149 -> V_161 == - V_215 ) {
F_27 ( V_50 , V_38 ) ;
F_83 ( V_50 ) ;
V_193 ++ ;
F_87 ( V_216 , L_12 V_217 L_13 V_217 L_14 ,
V_66 -> V_218 , V_193 , V_2 -> V_84 ,
F_88 ( & V_62 -> V_86 ) , F_88 ( & V_62 -> V_74 ) ) ;
if ( V_192 == V_66 -> V_99 . V_100 . V_199 -> V_200 ) {
goto V_201;
} else {
F_87 ( V_216 , L_15 ) ;
return - V_219 ;
}
}
V_38 = F_59 ( exp , V_50 , V_143 , V_2 , V_14 , V_38 ) ;
if ( V_38 < 0 ) {
if ( F_89 ( V_14 ) ) {
F_62 ( V_14 , V_143 -> V_157 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
}
F_83 ( V_50 ) ;
}
return V_38 ;
}
static int F_90 ( struct V_13 * exp ,
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
V_55 = F_63 ( & V_220 -> V_94 , & V_171 ) ;
F_9 ( V_55 != NULL ) ;
if ( F_35 ( & V_62 -> V_74 ) &&
V_2 -> V_71 & V_224 &&
V_2 -> V_84 != V_170 ) {
F_2 ( V_2 , V_225 ) ;
if ( ( ! F_91 ( & V_62 -> V_74 , & V_55 -> V_226 ) ) &&
( ! F_91 ( & V_62 -> V_227 , & V_55 -> V_226 ) ) ) {
F_87 ( V_228 , L_16 V_217 L_17 V_217 L_18 V_217
L_14 , F_88 ( & V_62 -> V_74 ) ,
F_88 ( & V_62 -> V_74 ) , F_88 ( & V_55 -> V_226 ) ) ;
return - V_229 ;
}
}
V_38 = F_4 ( V_11 , V_2 ) ;
if ( V_38 )
return V_38 ;
if ( ! F_1 ( V_2 , V_230 ) &&
F_1 ( V_2 , V_10 ) &&
! F_4 ( V_10 , V_2 ) ) {
F_2 ( V_2 , V_230 ) ;
F_92 ( V_220 ) ;
}
if ( ! F_1 ( V_2 , V_231 ) &&
F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_2 ( V_2 , V_231 ) ;
F_92 ( V_220 ) ;
F_93 ( V_232 , V_233 ) ;
}
if ( V_2 -> V_84 & V_85 ) {
} else if ( V_2 -> V_84 == V_166 ) {
F_9 ( ! F_1 ( V_2 , V_10 ) ) ;
} else {
F_9 ( V_2 -> V_84 & ( V_170 | V_169 | V_180 ) ) ;
}
V_18 = F_8 ( V_14 ) ;
if ( V_18 ) {
T_4 V_34 = V_18 -> V_29 ;
F_71 ( V_18 , L_19 ) ;
F_11 ( F_94 ( & V_55 -> V_226 ,
& V_18 -> V_22 -> V_234 ) ,
L_20 V_235 L_21 V_217 L_14 ,
F_95 ( V_18 -> V_22 ) , F_88 ( & V_55 -> V_226 ) ) ;
F_13 ( V_18 ) ;
memcpy ( & V_221 , V_14 , sizeof( * V_14 ) ) ;
if ( F_16 ( NULL , V_236 , NULL ,
V_196 , & V_34 , V_237 , & V_221 , 0 ) ) {
F_96 ( V_14 ,
V_2 -> V_4 . V_5 . V_162 ) ;
memcpy ( V_14 , & V_221 , sizeof( V_221 ) ) ;
V_2 -> V_4 . V_5 . V_163 = V_14 -> V_164 ;
}
}
F_87 ( V_228 , L_22 ,
V_62 -> V_97 , V_62 -> V_238 , F_72 ( V_2 -> V_84 ) ,
V_2 -> V_4 . V_5 . V_8 , V_2 -> V_4 . V_5 . F_1 , V_38 ) ;
return V_38 ;
}
int F_97 ( struct V_13 * exp , struct V_1 * V_2 ,
struct V_32 * V_33 , T_1 * V_16 )
{
struct V_36 V_37 ;
struct V_21 V_14 ;
T_4 V_34 ;
T_2 V_35 ;
if ( V_2 -> V_4 . V_5 . V_163 ) {
V_14 . V_164 = V_2 -> V_4 . V_5 . V_163 ;
V_35 = F_98 ( & V_14 , V_16 ) ;
} else {
F_15 ( V_33 , & V_37 ) ;
switch ( V_2 -> V_84 ) {
case V_170 :
V_34 . V_30 . V_16 = V_87 ;
break;
case V_180 :
V_34 . V_30 . V_16 = V_190 ;
break;
default:
V_34 . V_30 . V_16 = V_187 ;
break;
}
V_35 = F_16 ( exp -> V_239 -> V_39 ,
V_236 , & V_37 ,
V_196 , & V_34 ,
V_82 | V_81 | V_79 | V_112 , & V_14 , 0 ) ;
}
if ( V_35 ) {
V_2 -> V_4 . V_5 . V_163 = V_14 . V_164 ;
V_2 -> V_4 . V_5 . V_162 = V_35 ;
} else {
V_2 -> V_4 . V_5 . V_163 = 0 ;
V_2 -> V_4 . V_5 . V_162 = 0 ;
}
return ! ! V_35 ;
}
int F_99 ( struct V_13 * exp , struct V_61 * V_62 ,
void * V_63 , int V_64 , struct V_1 * V_2 ,
int V_240 , struct V_49 * * V_183 ,
T_8 V_241 ,
T_1 V_184 )
{
struct V_21 V_14 ;
int V_38 = 0 ;
F_9 ( V_2 ) ;
F_87 ( V_242 , L_23 V_217 L_24 V_217
L_25 , V_62 -> V_97 ,
V_62 -> V_238 , F_88 ( & V_62 -> V_74 ) ,
F_88 ( & V_62 -> V_86 ) , F_72 ( V_2 -> V_84 ) ,
V_2 -> V_75 ) ;
V_14 . V_164 = 0 ;
if ( F_35 ( & V_62 -> V_74 ) &&
( V_2 -> V_84 & ( V_169 | V_170 ) ) ) {
V_2 -> V_4 . V_5 . V_163 = 0 ;
V_38 = F_97 ( exp , V_2 , & V_62 -> V_74 , NULL ) ;
if ( V_38 || V_62 -> V_97 != 0 )
return V_38 ;
}
if ( ! F_1 ( V_2 , V_225 ) ) {
struct V_142 V_143 = {
. V_195 = V_196 ,
. V_157 = F_100 ( V_2 ) ,
. V_243 = V_241 ,
. V_244 = V_245 ,
} ;
if ( ! F_35 ( & V_62 -> V_74 ) && V_2 -> V_84 & V_85 ) {
V_38 = F_101 ( exp , & V_62 -> V_74 , V_62 ) ;
if ( V_38 < 0 ) {
F_5 ( L_26 , V_38 ) ;
return V_38 ;
}
}
V_38 = F_75 ( exp , & V_143 , V_2 , V_62 , & V_14 ,
V_63 , V_64 , NULL , V_184 ) ;
if ( V_38 < 0 )
return V_38 ;
} else if ( ! F_35 ( & V_62 -> V_74 ) ||
! ( V_2 -> V_71 & V_224 ) ) {
F_3 ( V_2 , V_225 ) ;
}
* V_183 = V_2 -> V_4 . V_5 . V_165 ;
V_38 = F_90 ( exp , * V_183 , V_62 , V_2 , & V_14 ) ;
return V_38 ;
}
static int F_102 ( const struct V_246 * V_247 ,
struct V_49 * V_50 ,
void * args , int V_38 )
{
struct V_248 * V_249 = args ;
struct V_13 * exp = V_249 -> V_250 ;
struct V_251 * V_252 = V_249 -> V_253 ;
struct V_142 * V_143 = V_249 -> V_254 ;
struct V_1 * V_2 ;
struct V_21 * V_14 ;
struct V_41 * V_66 ;
struct V_148 * V_149 ;
T_1 V_31 = V_197 ;
V_2 = & V_252 -> V_255 ;
V_14 = & V_252 -> V_256 ;
V_66 = F_17 ( exp ) ;
F_85 ( & V_66 -> V_99 . V_100 ) ;
if ( F_103 ( V_257 ) )
V_38 = - V_214 ;
V_38 = F_104 ( exp , V_50 , V_143 -> V_195 , 1 , V_143 -> V_157 ,
& V_31 , NULL , 0 , V_14 , V_38 ) ;
if ( V_38 < 0 ) {
F_5 ( L_27 , V_38 ) ;
F_27 ( V_50 , V_38 ) ;
GOTO ( V_258 , V_38 ) ;
}
V_149 = F_63 ( & V_50 -> V_94 , & V_159 ) ;
F_9 ( V_149 != NULL ) ;
V_149 -> V_161 =
F_86 ( V_149 -> V_161 ) ;
V_38 = F_59 ( exp , V_50 , V_143 , V_2 , V_14 , V_38 ) ;
if ( V_38 )
GOTO ( V_258 , V_38 ) ;
V_38 = F_90 ( exp , V_50 , & V_252 -> V_259 , V_2 , V_14 ) ;
V_258:
F_105 ( V_143 ) ;
V_252 -> V_260 ( V_50 , V_252 , V_38 ) ;
return 0 ;
}
int F_106 ( struct V_13 * exp ,
struct V_251 * V_252 ,
struct V_142 * V_143 )
{
struct V_61 * V_62 = & V_252 -> V_259 ;
struct V_1 * V_2 = & V_252 -> V_255 ;
struct V_49 * V_50 ;
struct V_248 * V_249 ;
struct V_41 * V_66 = F_17 ( exp ) ;
struct V_36 V_37 ;
T_4 V_34 = {
. V_30 = { V_187 |
V_87 }
} ;
int V_38 = 0 ;
T_1 V_31 = V_197 ;
F_87 ( V_242 ,
L_28 V_217 L_25 ,
V_62 -> V_97 , V_62 -> V_238 , F_88 ( & V_62 -> V_86 ) ,
F_72 ( V_2 -> V_84 ) , V_2 -> V_75 ) ;
F_15 ( & V_62 -> V_86 , & V_37 ) ;
V_50 = F_55 ( exp , V_2 , V_62 ) ;
if ( ! V_50 )
return - V_90 ;
V_38 = F_81 ( & V_66 -> V_99 . V_100 ) ;
if ( V_38 != 0 ) {
F_83 ( V_50 ) ;
return V_38 ;
}
V_38 = F_84 ( exp , & V_50 , V_143 , & V_37 , & V_34 , & V_31 , NULL ,
0 , V_261 , & V_252 -> V_256 , 1 ) ;
if ( V_38 < 0 ) {
F_85 ( & V_66 -> V_99 . V_100 ) ;
F_83 ( V_50 ) ;
return V_38 ;
}
F_107 ( sizeof( * V_249 ) <= sizeof( V_50 -> V_262 ) ) ;
V_249 = F_108 ( V_50 ) ;
V_249 -> V_250 = exp ;
V_249 -> V_253 = V_252 ;
V_249 -> V_254 = V_143 ;
V_50 -> V_263 = F_102 ;
F_109 ( V_50 , V_264 , - 1 ) ;
return 0 ;
}
