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
F_42 ( & V_50 -> V_92 , & V_93 , V_94 ,
V_62 -> V_95 + 1 ) ;
F_42 ( & V_50 -> V_92 , & V_96 , V_94 ,
F_43 ( V_64 , V_66 -> V_97 . V_98 . V_99 ) ) ;
V_38 = F_44 ( exp , V_50 , & V_69 , V_70 ) ;
if ( V_38 < 0 ) {
F_45 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
F_29 ( & V_50 -> V_52 ) ;
V_50 -> V_51 = V_50 -> V_100 -> V_101 ;
F_30 ( & V_50 -> V_52 ) ;
V_68 = F_46 ( & V_50 -> V_92 , & V_102 ) ;
V_68 -> V_103 = ( T_1 ) V_2 -> V_85 ;
F_47 ( V_50 , V_62 , V_2 -> V_71 , 0 , V_2 -> V_75 , V_63 ,
V_64 ) ;
if ( F_48 ( exp ) )
F_42 ( & V_50 -> V_92 , & V_104 , V_105 ,
sizeof( struct V_106 ) ) ;
F_49 ( V_50 ) ;
return V_50 ;
}
static struct V_49 *
F_50 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_67 * V_68 ;
int V_38 , V_70 = 0 , V_107 ;
F_35 ( V_69 ) ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_108 ) ;
if ( V_50 == NULL )
return F_41 ( - V_91 ) ;
V_38 = F_44 ( exp , V_50 , & V_69 , V_70 ) ;
if ( V_38 ) {
F_45 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
V_68 = F_46 ( & V_50 -> V_92 , & V_102 ) ;
V_68 -> V_103 = V_109 ;
V_107 = F_39 ( exp ) -> V_110 . V_111 ;
F_51 ( V_50 , & V_62 -> V_87 , V_62 -> V_112 , V_107 , - 1 ,
0 ) ;
F_42 ( & V_50 -> V_92 , & V_96 ,
V_105 , V_107 ) ;
F_42 ( & V_50 -> V_92 , & V_113 ,
V_105 , V_107 ) ;
F_42 ( & V_50 -> V_92 , & V_114 ,
V_105 , V_107 ) ;
F_49 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_52 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_18 ( exp ) ;
struct V_67 * V_68 ;
int V_38 ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_115 ) ;
if ( V_50 == NULL )
return F_41 ( - V_91 ) ;
F_42 ( & V_50 -> V_92 , & V_93 , V_94 ,
V_62 -> V_95 + 1 ) ;
V_38 = F_44 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_45 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
V_68 = F_46 ( & V_50 -> V_92 , & V_102 ) ;
V_68 -> V_103 = ( T_1 ) V_2 -> V_85 ;
F_53 ( V_50 , V_62 ) ;
F_42 ( & V_50 -> V_92 , & V_116 , V_105 ,
V_66 -> V_97 . V_98 . V_99 ) ;
F_42 ( & V_50 -> V_92 , & V_104 , V_105 ,
V_66 -> V_97 . V_98 . V_117 ) ;
F_49 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_54 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_18 ( exp ) ;
T_7 V_59 = V_118 | V_60 |
V_119 | V_120 |
V_121 |
( F_48 ( exp ) ?
V_122 : V_123 ) ;
struct V_67 * V_68 ;
int V_38 ;
int V_124 ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_125 ) ;
if ( V_50 == NULL )
return F_41 ( - V_91 ) ;
F_42 ( & V_50 -> V_92 , & V_93 , V_94 ,
V_62 -> V_95 + 1 ) ;
V_38 = F_44 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_45 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
V_68 = F_46 ( & V_50 -> V_92 , & V_102 ) ;
V_68 -> V_103 = ( T_1 ) V_2 -> V_85 ;
if ( V_66 -> V_97 . V_98 . V_99 > 0 )
V_124 = V_66 -> V_97 . V_98 . V_99 ;
else
V_124 = V_66 -> V_97 . V_98 . V_126 ;
F_55 ( V_50 , V_59 , V_2 -> V_75 , V_62 , V_124 ) ;
F_42 ( & V_50 -> V_92 , & V_116 , V_105 , V_124 ) ;
if ( F_48 ( exp ) )
F_42 ( & V_50 -> V_92 , & V_104 , V_105 ,
sizeof( struct V_106 ) ) ;
F_49 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_56 ( struct V_13 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_127 )
{
struct V_41 * V_42 = F_18 ( exp ) ;
struct V_49 * V_50 ;
struct V_67 * V_68 ;
struct V_128 * V_129 ;
int V_38 ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_130 ) ;
if ( V_50 == NULL )
return F_41 ( - V_91 ) ;
F_42 ( & V_50 -> V_92 , & V_96 , V_94 , 0 ) ;
V_38 = F_44 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_45 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
V_68 = F_46 ( & V_50 -> V_92 , & V_102 ) ;
V_68 -> V_103 = ( T_1 ) V_2 -> V_85 ;
V_129 = F_46 ( & V_50 -> V_92 , & V_131 ) ;
V_129 -> V_132 = V_133 ;
F_42 ( & V_50 -> V_92 , & V_134 , V_105 ,
V_42 -> V_97 . V_98 . V_99 ) ;
F_49 ( V_50 ) ;
return V_50 ;
}
static struct V_49 *
F_57 ( struct V_13 * exp , int V_135 )
{
struct V_49 * V_50 ;
int V_38 ;
V_50 = F_38 ( F_39 ( exp ) , & V_136 ) ;
if ( V_50 == NULL )
return F_41 ( - V_91 ) ;
V_38 = F_44 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_45 ( V_50 ) ;
return F_41 ( V_38 ) ;
}
F_42 ( & V_50 -> V_92 , & V_134 , V_105 , V_135 ) ;
F_49 ( V_50 ) ;
return V_50 ;
}
static int F_58 ( struct V_13 * exp ,
struct V_49 * V_50 ,
struct V_137 * V_138 ,
struct V_1 * V_2 ,
struct V_21 * V_14 ,
int V_38 )
{
struct V_139 * V_140 = & V_50 -> V_92 ;
struct V_141 * V_142 ;
struct V_143 * V_144 ;
struct V_145 * V_146 = & V_2 -> V_4 . V_5 ;
struct V_17 * V_18 ;
void * V_147 = NULL ;
int V_135 = 0 ;
F_9 ( V_38 >= 0 ) ;
if ( V_50 -> V_53 || V_50 -> V_51 ) {
V_142 = F_46 ( V_140 , & V_148 ) ;
V_142 -> V_149 |= F_59 ( V_150 ) ;
}
if ( V_38 == V_151 ) {
V_138 -> V_152 = 0 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_38 = 0 ;
} else {
V_18 = F_8 ( V_14 ) ;
F_9 ( V_18 != NULL ) ;
if ( V_18 -> V_153 != V_138 -> V_152 ) {
F_60 ( V_14 , V_18 -> V_153 ) ;
F_61 ( V_14 , V_138 -> V_152 ) ;
V_138 -> V_152 = V_18 -> V_153 ;
}
F_13 ( V_18 ) ;
}
V_144 = F_62 ( V_140 , & V_154 ) ;
F_9 ( V_144 != NULL ) ;
V_146 -> F_1 = ( int ) V_144 -> V_155 ;
V_146 -> V_8 = ( int ) V_144 -> V_156 ;
V_146 -> V_157 = V_138 -> V_152 ;
V_146 -> V_158 = V_14 -> V_159 ;
V_146 -> V_160 = V_50 ;
if ( ( ! V_50 -> V_53 || V_146 -> V_8 < 0 ) && V_50 -> V_51 )
F_28 ( V_50 , V_146 -> V_8 ) ;
if ( V_2 -> V_85 & V_161 && V_50 -> V_51 &&
( ! F_1 ( V_2 , V_9 ) || V_146 -> V_8 != 0 ) )
F_28 ( V_50 , V_146 -> V_8 ) ;
F_31 ( V_162 , V_50 , L_6 ,
V_2 -> V_85 , V_146 -> F_1 , V_146 -> V_8 ) ;
if ( V_2 -> V_85 & ( V_161 | V_163 | V_164 | V_165 ) ) {
struct V_55 * V_56 ;
V_56 = F_62 ( V_140 , & V_166 ) ;
if ( V_56 == NULL ) {
F_5 ( L_7 ) ;
return - V_167 ;
}
if ( F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_63 ( NULL , NULL , V_2 ) ;
}
if ( ( V_56 -> V_59 & ( V_120 | V_60 ) ) != 0 ) {
void * V_168 ;
F_64 ( exp , V_56 ) ;
V_168 = F_65 ( V_140 , & V_116 ,
V_56 -> V_58 ) ;
if ( V_168 == NULL )
return - V_167 ;
V_147 = V_168 ;
V_135 = V_56 -> V_58 ;
if ( ( V_2 -> V_85 & V_161 ) && V_50 -> V_51 ) {
void * V_63 ;
if ( F_66 ( V_140 , & V_96 ,
V_94 ) <
V_56 -> V_58 )
F_32 ( V_50 , V_56 ) ;
else
F_67 ( V_140 , & V_96 ,
V_56 -> V_58 ,
V_94 ) ;
F_42 ( V_140 , & V_96 ,
V_94 ,
V_56 -> V_58 ) ;
V_63 = F_46 ( V_140 , & V_96 ) ;
if ( V_63 )
memcpy ( V_63 , V_168 , V_56 -> V_58 ) ;
}
}
if ( V_56 -> V_59 & V_122 ) {
struct V_106 * V_169 ;
F_9 ( F_48 ( exp ) ) ;
V_169 = F_68 ( V_140 , & V_104 ,
V_170 ) ;
if ( V_169 == NULL )
return - V_167 ;
}
} else if ( V_2 -> V_85 & V_171 ) {
V_135 = F_66 ( V_140 , & V_134 , V_105 ) ;
if ( V_135 > 0 ) {
V_147 = F_65 ( V_140 ,
& V_134 , V_135 ) ;
if ( V_147 == NULL )
return - V_167 ;
}
}
V_18 = F_8 ( V_14 ) ;
if ( V_18 != NULL && F_69 ( V_18 ) && V_147 != NULL ) {
void * V_63 ;
F_70 ( V_18 , L_8 ,
F_71 ( V_2 -> V_85 ) , V_135 ) ;
V_63 = F_72 ( V_135 , V_172 ) ;
if ( V_63 == NULL ) {
F_13 ( V_18 ) ;
return - V_91 ;
}
memcpy ( V_63 , V_147 , V_135 ) ;
F_10 ( V_18 ) ;
if ( V_18 -> V_173 == NULL ) {
V_18 -> V_174 = V_175 ;
V_18 -> V_173 = V_63 ;
V_18 -> V_176 = V_135 ;
V_63 = NULL ;
}
F_12 ( V_18 ) ;
if ( V_63 != NULL )
F_73 ( V_63 ) ;
}
if ( V_18 != NULL )
F_13 ( V_18 ) ;
return V_38 ;
}
int F_74 ( struct V_13 * exp , struct V_137 * V_138 ,
struct V_1 * V_2 , struct V_61 * V_62 ,
struct V_21 * V_14 , void * V_63 , int V_64 ,
struct V_49 * * V_177 , T_7 V_178 )
{
static const T_4 V_179 = {
. V_30 = { V_180 }
} ;
static const T_4 V_181 = {
. V_30 = { V_88 }
} ;
static const T_4 V_182 = {
. V_30 = { V_183 }
} ;
static const T_4 V_184 = {
. V_30 = { V_185 }
} ;
T_4 const * V_34 = & V_179 ;
struct V_41 * V_66 = F_18 ( exp ) ;
struct V_49 * V_50 ;
T_7 V_31 , V_186 = V_178 ;
struct V_36 V_37 ;
int V_187 , V_188 = 0 ;
struct V_143 * V_144 ;
enum V_189 V_189 = V_190 ;
int V_38 ;
F_11 ( ! V_2 || V_138 -> V_191 == V_192 , L_9 ,
V_138 -> V_191 ) ;
F_15 ( & V_62 -> V_87 , & V_37 ) ;
if ( V_2 ) {
V_186 |= V_193 ;
if ( V_2 -> V_85 & ( V_163 | V_165 | V_194 ) )
V_34 = & V_181 ;
else if ( V_2 -> V_85 & V_171 )
V_34 = & V_182 ;
else if ( V_2 -> V_85 & ( V_109 | V_195 ) )
V_34 = & V_184 ;
}
F_9 ( V_177 == NULL ) ;
V_187 = V_66 -> V_97 . V_98 . V_196 -> V_197 ;
V_198:
V_31 = V_186 ;
if ( ! V_2 ) {
F_9 ( V_63 && V_64 == 0 ) ;
F_11 ( V_138 -> V_191 == V_199 , L_9 ,
V_138 -> V_191 ) ;
V_34 = V_63 ;
V_37 . V_200 [ 3 ] = V_199 ;
V_50 = NULL ;
} else if ( V_2 -> V_85 & V_161 ) {
V_50 = F_34 ( exp , V_2 , V_62 , V_63 , V_64 ,
V_138 -> V_201 ) ;
V_34 = & V_181 ;
V_138 -> V_201 = NULL ;
V_63 = NULL ;
} else if ( V_2 -> V_85 & V_163 ) {
V_50 = F_52 ( exp , V_2 , V_62 ) ;
} else if ( V_2 -> V_85 & ( V_165 | V_164 ) ) {
V_50 = F_54 ( exp , V_2 , V_62 ) ;
} else if ( V_2 -> V_85 & V_194 ) {
V_50 = F_57 ( exp , 0 ) ;
} else if ( V_2 -> V_85 & V_171 ) {
if ( ! F_75 ( F_39 ( exp ) ) )
return - V_202 ;
V_50 = F_56 ( exp , V_2 , V_62 ) ;
V_189 = V_175 ;
} else if ( V_2 -> V_85 & V_109 ) {
V_50 = F_50 ( exp , V_2 , V_62 ) ;
} else {
F_6 () ;
return - V_203 ;
}
if ( F_76 ( V_50 ) )
return F_77 ( V_50 ) ;
if ( V_50 != NULL && V_2 && V_2 -> V_85 & V_86 )
V_50 -> V_204 = 1 ;
if ( V_188 ) {
V_50 -> V_205 = 1 ;
V_50 -> V_206 = V_187 ;
V_50 -> V_207 = F_78 () + V_188 ;
}
if ( V_2 ) {
F_79 ( V_66 -> V_97 . V_98 . V_208 , V_2 ) ;
V_38 = F_80 ( & V_66 -> V_97 . V_98 ) ;
if ( V_38 != 0 ) {
F_81 ( V_66 -> V_97 . V_98 . V_208 , V_2 ) ;
F_28 ( V_50 , 0 ) ;
F_82 ( V_50 ) ;
return V_38 ;
}
}
V_38 = F_83 ( exp , & V_50 , V_138 , & V_37 , V_34 , & V_31 , NULL ,
0 , V_189 , V_14 , 0 ) ;
if ( ! V_2 ) {
if ( ( V_38 == - V_209 ) || ( V_38 == - V_210 ) )
goto V_198;
return V_38 ;
}
F_84 ( & V_66 -> V_97 . V_98 ) ;
F_81 ( V_66 -> V_97 . V_98 . V_208 , V_2 ) ;
if ( V_38 < 0 ) {
F_85 ( ( V_38 == - V_211 || V_38 == - V_212 ) ? V_213 : V_54 ,
L_10 ,
V_66 -> V_214 , V_38 ) ;
F_28 ( V_50 , V_38 ) ;
F_82 ( V_50 ) ;
return V_38 ;
}
V_144 = F_62 ( & V_50 -> V_92 , & V_154 ) ;
F_9 ( V_144 != NULL ) ;
V_144 -> V_156 =
F_86 ( V_144 -> V_156 ) ;
if ( V_2 -> V_85 & V_86 &&
( int ) V_144 -> V_156 == - V_215 ) {
F_28 ( V_50 , V_38 ) ;
F_82 ( V_50 ) ;
V_188 ++ ;
F_87 ( V_216 , L_11 V_217 L_12 V_217 L_13 ,
V_66 -> V_214 , V_188 , V_2 -> V_85 ,
F_88 ( & V_62 -> V_87 ) , F_88 ( & V_62 -> V_74 ) ) ;
if ( V_187 == V_66 -> V_97 . V_98 . V_196 -> V_197 ) {
goto V_198;
} else {
F_87 ( V_216 , L_14 ) ;
return - V_218 ;
}
}
V_38 = F_58 ( exp , V_50 , V_138 , V_2 , V_14 , V_38 ) ;
if ( V_38 < 0 ) {
if ( F_89 ( V_14 ) ) {
F_61 ( V_14 , V_138 -> V_152 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
}
F_82 ( V_50 ) ;
V_2 -> V_4 . V_5 . V_158 = 0 ;
V_2 -> V_4 . V_5 . V_157 = 0 ;
V_2 -> V_4 . V_5 . V_160 = NULL ;
}
return V_38 ;
}
static int F_90 ( struct V_13 * exp ,
struct V_49 * V_219 ,
struct V_61 * V_62 ,
struct V_1 * V_2 ,
struct V_21 * V_14 )
{
struct V_21 V_220 ;
struct V_55 * V_55 ;
struct V_17 * V_18 ;
int V_38 ;
F_9 ( V_219 != NULL ) ;
F_9 ( V_219 != V_221 ) ;
F_9 ( V_219 -> V_222 != V_221 ) ;
if ( ! F_1 ( V_2 , V_12 ) ) {
F_9 ( V_2 -> V_4 . V_5 . V_8 != 0 ) ;
return V_2 -> V_4 . V_5 . V_8 ;
}
V_38 = F_4 ( V_12 , V_2 ) ;
if ( V_38 )
return V_38 ;
V_55 = F_62 ( & V_219 -> V_92 , & V_166 ) ;
F_9 ( V_55 != NULL ) ;
if ( F_36 ( & V_62 -> V_74 ) &&
V_2 -> V_71 & V_223 &&
V_2 -> V_85 != V_165 ) {
if ( ( ! F_91 ( & V_62 -> V_74 , & V_55 -> V_224 ) ) &&
( ! F_91 ( & V_62 -> V_225 , & V_55 -> V_224 ) ) ) {
F_87 ( V_226 , L_15 V_217 L_16 V_217 L_17 V_217
L_13 , F_88 ( & V_62 -> V_74 ) ,
F_88 ( & V_62 -> V_74 ) , F_88 ( & V_55 -> V_224 ) ) ;
return - V_227 ;
}
}
V_38 = F_4 ( V_11 , V_2 ) ;
if ( V_38 )
return V_38 ;
if ( ! F_1 ( V_2 , V_228 ) &&
F_1 ( V_2 , V_10 ) &&
! F_4 ( V_10 , V_2 ) ) {
F_2 ( V_2 , V_228 ) ;
F_92 ( V_219 ) ;
}
if ( ! F_1 ( V_2 , V_229 ) &&
F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_2 ( V_2 , V_229 ) ;
F_92 ( V_219 ) ;
F_93 ( V_230 , V_231 ) ;
}
if ( V_2 -> V_85 & V_86 ) {
} else if ( V_2 -> V_85 == V_161 ) {
F_9 ( ! F_1 ( V_2 , V_10 ) ) ;
} else {
F_9 ( V_2 -> V_85 & ( V_165 | V_164 | V_171 ) ) ;
}
V_18 = F_8 ( V_14 ) ;
if ( V_18 ) {
T_4 V_34 = V_18 -> V_29 ;
F_70 ( V_18 , L_18 ) ;
F_11 ( F_94 ( & V_55 -> V_224 ,
& V_18 -> V_22 -> V_232 ) ,
L_19 V_233 L_20 V_217 L_13 ,
F_95 ( V_18 -> V_22 ) , F_88 ( & V_55 -> V_224 ) ) ;
F_13 ( V_18 ) ;
memcpy ( & V_220 , V_14 , sizeof( * V_14 ) ) ;
if ( F_17 ( NULL , V_234 , NULL ,
V_192 , & V_34 , V_235 ,
& V_220 , 0 ) ) {
F_96 ( V_14 ,
V_2 -> V_4 . V_5 . V_157 ) ;
memcpy ( V_14 , & V_220 , sizeof( V_220 ) ) ;
V_2 -> V_4 . V_5 . V_158 = V_14 -> V_159 ;
}
}
F_87 ( V_226 ,
L_21 ,
V_62 -> V_95 , V_62 -> V_236 , F_71 ( V_2 -> V_85 ) ,
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
if ( V_2 -> V_4 . V_5 . V_158 ) {
V_14 . V_159 = V_2 -> V_4 . V_5 . V_158 ;
V_35 = F_98 ( & V_14 , V_16 ) ;
} else {
F_15 ( V_33 , & V_37 ) ;
switch ( V_2 -> V_85 ) {
case V_165 :
V_34 . V_30 . V_16 = V_88 |
V_180 |
V_237 ;
break;
case V_171 :
V_34 . V_30 . V_16 = V_183 ;
break;
default:
V_34 . V_30 . V_16 = V_180 ;
break;
}
V_35 = F_14 ( exp , V_234 , V_33 ,
V_192 , & V_34 ,
V_83 | V_81 | V_79 | V_238 ,
& V_14 ) ;
}
if ( V_35 ) {
V_2 -> V_4 . V_5 . V_158 = V_14 . V_159 ;
V_2 -> V_4 . V_5 . V_157 = V_35 ;
} else {
V_2 -> V_4 . V_5 . V_158 = 0 ;
V_2 -> V_4 . V_5 . V_157 = 0 ;
}
return ! ! V_35 ;
}
int F_99 ( struct V_13 * exp , struct V_61 * V_62 ,
void * V_63 , int V_64 , struct V_1 * V_2 ,
int V_239 , struct V_49 * * V_177 ,
T_8 V_240 ,
T_1 V_178 )
{
struct V_137 V_138 = {
. V_191 = V_192 ,
. V_152 = F_100 ( V_2 ) ,
. V_241 = V_240 ,
. V_242 = V_243 ,
} ;
struct V_21 V_14 ;
int V_38 = 0 ;
F_9 ( V_2 ) ;
F_87 ( V_244 , L_22 V_217 L_23 V_217
L_24 , V_62 -> V_95 ,
V_62 -> V_236 , F_88 ( & V_62 -> V_74 ) ,
F_88 ( & V_62 -> V_87 ) , F_71 ( V_2 -> V_85 ) ,
V_2 -> V_75 ) ;
V_14 . V_159 = 0 ;
if ( F_36 ( & V_62 -> V_74 ) &&
( V_2 -> V_85 & ( V_164 | V_165 ) ) ) {
V_2 -> V_4 . V_5 . V_158 = 0 ;
V_38 = F_97 ( exp , V_2 , & V_62 -> V_74 , NULL ) ;
if ( V_38 || V_62 -> V_95 != 0 )
return V_38 ;
}
if ( ! F_36 ( & V_62 -> V_74 ) && V_2 -> V_85 & V_86 ) {
V_38 = F_101 ( exp , & V_62 -> V_74 , V_62 ) ;
if ( V_38 < 0 ) {
F_5 ( L_25 , V_38 ) ;
return V_38 ;
}
}
V_38 = F_74 ( exp , & V_138 , V_2 , V_62 , & V_14 , V_63 , V_64 , NULL ,
V_178 ) ;
if ( V_38 < 0 )
return V_38 ;
* V_177 = V_2 -> V_4 . V_5 . V_160 ;
V_38 = F_90 ( exp , * V_177 , V_62 , V_2 , & V_14 ) ;
return V_38 ;
}
static int F_102 ( const struct V_245 * V_246 ,
struct V_49 * V_50 ,
void * args , int V_38 )
{
struct V_247 * V_248 = args ;
struct V_13 * exp = V_248 -> V_249 ;
struct V_250 * V_251 = V_248 -> V_252 ;
struct V_137 * V_138 = V_248 -> V_253 ;
struct V_1 * V_2 ;
struct V_21 * V_14 ;
struct V_41 * V_66 ;
struct V_143 * V_144 ;
T_1 V_31 = V_193 ;
V_2 = & V_251 -> V_254 ;
V_14 = & V_251 -> V_255 ;
V_66 = F_18 ( exp ) ;
F_84 ( & V_66 -> V_97 . V_98 ) ;
if ( F_103 ( V_256 ) )
V_38 = - V_210 ;
V_38 = F_104 ( exp , V_50 , V_138 -> V_191 , 1 , V_138 -> V_152 ,
& V_31 , NULL , 0 , V_14 , V_38 ) ;
if ( V_38 < 0 ) {
F_5 ( L_26 , V_38 ) ;
F_28 ( V_50 , V_38 ) ;
goto V_257;
}
V_144 = F_62 ( & V_50 -> V_92 , & V_154 ) ;
F_9 ( V_144 != NULL ) ;
V_144 -> V_156 =
F_86 ( V_144 -> V_156 ) ;
V_38 = F_58 ( exp , V_50 , V_138 , V_2 , V_14 , V_38 ) ;
if ( V_38 )
goto V_257;
V_38 = F_90 ( exp , V_50 , & V_251 -> V_258 , V_2 , V_14 ) ;
V_257:
F_105 ( V_138 ) ;
V_251 -> V_259 ( V_50 , V_251 , V_38 ) ;
return 0 ;
}
int F_106 ( struct V_13 * exp ,
struct V_250 * V_251 ,
struct V_137 * V_138 )
{
struct V_61 * V_62 = & V_251 -> V_258 ;
struct V_1 * V_2 = & V_251 -> V_254 ;
struct V_49 * V_50 ;
struct V_247 * V_248 ;
struct V_41 * V_66 = F_18 ( exp ) ;
struct V_36 V_37 ;
T_4 V_34 = {
. V_30 = { V_180 |
V_88 }
} ;
int V_38 = 0 ;
T_1 V_31 = V_193 ;
F_87 ( V_244 ,
L_27 V_217 L_24 ,
V_62 -> V_95 , V_62 -> V_236 , F_88 ( & V_62 -> V_87 ) ,
F_71 ( V_2 -> V_85 ) , V_2 -> V_75 ) ;
F_15 ( & V_62 -> V_87 , & V_37 ) ;
V_50 = F_54 ( exp , V_2 , V_62 ) ;
if ( F_76 ( V_50 ) )
return F_77 ( V_50 ) ;
V_38 = F_80 ( & V_66 -> V_97 . V_98 ) ;
if ( V_38 != 0 ) {
F_82 ( V_50 ) ;
return V_38 ;
}
V_38 = F_83 ( exp , & V_50 , V_138 , & V_37 , & V_34 , & V_31 , NULL ,
0 , V_190 , & V_251 -> V_255 , 1 ) ;
if ( V_38 < 0 ) {
F_84 ( & V_66 -> V_97 . V_98 ) ;
F_82 ( V_50 ) ;
return V_38 ;
}
F_107 ( sizeof( * V_248 ) <= sizeof( V_50 -> V_260 ) ) ;
V_248 = F_108 ( V_50 ) ;
V_248 -> V_249 = exp ;
V_248 -> V_252 = V_251 ;
V_248 -> V_253 = V_138 ;
V_50 -> V_261 = F_102 ;
F_109 ( V_50 ) ;
return 0 ;
}
