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
F_5 ( L_1 , V_2 -> V_4 . V_5 . F_1 ,
V_2 -> V_4 . V_5 . V_8 ) ;
F_6 () ;
return 0 ;
}
int F_7 ( struct V_12 * exp , T_1 * V_13 , void * V_14 ,
T_1 * V_15 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 = V_14 ;
V_20 ;
if( V_15 )
* V_15 = 0 ;
if ( ! * V_13 )
RETURN ( 0 ) ;
V_17 = F_8 ( (struct V_21 * ) V_13 ) ;
F_9 ( V_17 != NULL ) ;
F_10 ( V_17 ) ;
if ( V_17 -> V_22 -> V_23 &&
V_17 -> V_22 -> V_23 != V_14 ) {
struct V_18 * V_24 = V_17 -> V_22 -> V_23 ;
F_11 ( V_24 -> V_25 & V_26 ,
L_2
L_3 , V_24 ,
V_24 -> V_27 , V_24 -> V_28 ,
V_24 -> V_25 ,
V_19 , V_19 -> V_27 , V_19 -> V_28 ) ;
}
V_17 -> V_22 -> V_23 = V_19 ;
if ( V_15 )
* V_15 = V_17 -> V_29 . V_30 . V_15 ;
F_12 ( V_17 ) ;
F_13 ( V_17 ) ;
RETURN ( 0 ) ;
}
T_2 F_14 ( struct V_12 * exp , T_1 V_31 ,
const struct V_32 * V_33 , T_3 type ,
T_4 * V_34 , T_2 V_35 ,
struct V_21 * V_13 )
{
struct V_36 V_37 ;
T_2 V_38 ;
V_20 ;
F_15 ( V_33 , & V_37 ) ;
V_38 = F_16 ( F_17 ( exp ) -> V_39 , V_31 ,
& V_37 , type , V_34 , V_35 , V_13 , 0 ) ;
RETURN ( V_38 ) ;
}
int F_18 ( struct V_12 * exp ,
const struct V_32 * V_33 ,
T_4 * V_34 ,
T_2 V_35 ,
T_5 V_31 ,
void * V_40 )
{
struct V_36 V_37 ;
struct V_41 * V_42 = F_17 ( exp ) ;
int V_38 ;
V_20 ;
F_15 ( V_33 , & V_37 ) ;
V_38 = F_19 ( V_42 -> V_39 , & V_37 ,
V_34 , V_35 , V_31 , V_40 ) ;
RETURN ( V_38 ) ;
}
int F_20 ( struct V_12 * exp ,
const struct V_32 * V_33 )
{
struct V_36 V_37 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = F_17 ( exp ) -> V_39 ;
V_20 ;
F_11 ( V_46 != NULL , L_4 ) ;
F_15 ( V_33 , & V_37 ) ;
V_44 = F_21 ( V_46 , NULL , & V_37 , 0 , 0 ) ;
if( V_44 == NULL )
RETURN ( 0 ) ;
F_22 ( V_44 ) ;
V_44 -> V_23 = NULL ;
F_23 ( V_44 ) ;
F_24 ( V_44 ) ;
RETURN ( 0 ) ;
}
int F_25 ( struct V_12 * exp ,
const struct V_32 * V_33 ,
T_6 V_2 , void * V_14 )
{
struct V_36 V_37 ;
int V_38 = 0 ;
V_20 ;
F_15 ( (struct V_32 * ) V_33 , & V_37 ) ;
V_38 = F_26 ( F_17 ( exp ) -> V_39 , & V_37 ,
V_2 , V_14 ) ;
if ( V_38 == V_47 )
RETURN ( 1 ) ;
else if ( V_38 == V_48 )
RETURN ( 0 ) ;
RETURN ( V_38 ) ;
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
static struct V_49 * F_33 ( struct V_12 * exp ,
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
V_20 ;
V_2 -> V_71 = ( V_2 -> V_71 & ~ V_72 ) | V_73 ;
if ( F_35 ( & V_62 -> V_74 ) ) {
if ( V_2 -> V_75 & ( V_76 | V_77 ) )
V_35 = V_78 ;
#ifdef F_36
else if ( V_2 -> V_75 & F_36 )
V_35 = V_79 ;
#endif
else
V_35 = V_80 ;
V_70 = F_37 ( exp , & V_62 -> V_74 ,
& V_69 , V_35 ,
V_81 ) ;
}
if ( V_2 -> V_82 & V_83 )
V_35 = V_84 ;
else
V_35 = V_80 ;
V_70 += F_37 ( exp , & V_62 -> V_85 ,
& V_69 , V_35 ,
V_86 ) ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_87 ) ;
if ( V_50 == NULL ) {
F_40 ( & V_69 , V_88 , V_70 ) ;
RETURN ( F_41 ( - V_89 ) ) ;
}
F_42 ( V_50 , & V_90 , V_62 -> V_91 ) ;
F_42 ( V_50 , & V_92 , V_62 -> V_91 ) ;
F_43 ( & V_50 -> V_93 , & V_94 , V_95 ,
V_62 -> V_96 + 1 ) ;
F_43 ( & V_50 -> V_93 , & V_97 , V_95 ,
F_44 ( V_64 , V_66 -> V_98 . V_99 . V_100 ) ) ;
V_38 = F_45 ( exp , V_50 , & V_69 , V_70 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
return NULL ;
}
F_28 ( & V_50 -> V_52 ) ;
V_50 -> V_51 = V_50 -> V_101 -> V_102 ;
F_29 ( & V_50 -> V_52 ) ;
V_68 = F_47 ( & V_50 -> V_93 , & V_103 ) ;
V_68 -> V_104 = ( T_1 ) V_2 -> V_82 ;
F_48 ( V_50 , V_62 , V_2 -> V_71 , 0 , V_2 -> V_75 , V_63 ,
V_64 ) ;
if ( F_49 ( exp ) )
F_43 ( & V_50 -> V_93 , & V_105 , V_106 ,
sizeof( struct V_107 ) ) ;
F_50 ( V_50 ) ;
return V_50 ;
}
static struct V_49 * F_51 ( struct V_12 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_17 ( exp ) ;
struct V_67 * V_68 ;
int V_38 ;
V_20 ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_108 ) ;
if ( V_50 == NULL )
RETURN ( F_41 ( - V_89 ) ) ;
F_42 ( V_50 , & V_90 , V_62 -> V_91 ) ;
F_43 ( & V_50 -> V_93 , & V_94 , V_95 ,
V_62 -> V_96 + 1 ) ;
V_38 = F_45 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
RETURN ( F_41 ( V_38 ) ) ;
}
V_68 = F_47 ( & V_50 -> V_93 , & V_103 ) ;
V_68 -> V_104 = ( T_1 ) V_2 -> V_82 ;
F_52 ( V_50 , V_62 ) ;
F_43 ( & V_50 -> V_93 , & V_109 , V_106 ,
V_66 -> V_98 . V_99 . V_110 ) ;
F_43 ( & V_50 -> V_93 , & V_105 , V_106 ,
V_66 -> V_98 . V_99 . V_111 ) ;
F_50 ( V_50 ) ;
RETURN ( V_50 ) ;
}
static struct V_49 * F_53 ( struct V_12 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_49 * V_50 ;
struct V_41 * V_66 = F_17 ( exp ) ;
T_7 V_59 = V_112 | V_60 |
V_113 | V_114 |
V_115 | V_116 |
( F_49 ( exp ) ?
V_117 : V_118 ) ;
struct V_67 * V_68 ;
int V_38 ;
V_20 ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_119 ) ;
if ( V_50 == NULL )
RETURN ( F_41 ( - V_89 ) ) ;
F_42 ( V_50 , & V_90 , V_62 -> V_91 ) ;
F_43 ( & V_50 -> V_93 , & V_94 , V_95 ,
V_62 -> V_96 + 1 ) ;
V_38 = F_45 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
RETURN ( F_41 ( V_38 ) ) ;
}
V_68 = F_47 ( & V_50 -> V_93 , & V_103 ) ;
V_68 -> V_104 = ( T_1 ) V_2 -> V_82 ;
F_54 ( V_50 , V_59 , V_2 -> V_75 , V_62 ,
V_66 -> V_98 . V_99 . V_110 ) ;
F_43 ( & V_50 -> V_93 , & V_109 , V_106 ,
V_66 -> V_98 . V_99 . V_110 ) ;
if ( F_49 ( exp ) )
F_43 ( & V_50 -> V_93 , & V_105 , V_106 ,
sizeof( struct V_107 ) ) ;
F_50 ( V_50 ) ;
RETURN ( V_50 ) ;
}
static struct V_49 * F_55 ( struct V_12 * exp ,
struct V_1 * V_2 ,
struct V_61 * V_120 )
{
struct V_41 * V_42 = F_17 ( exp ) ;
struct V_49 * V_50 ;
struct V_67 * V_68 ;
struct V_121 * V_122 ;
int V_38 ;
V_20 ;
V_50 = F_38 ( F_39 ( exp ) ,
& V_123 ) ;
if ( V_50 == NULL )
RETURN ( F_41 ( - V_89 ) ) ;
F_43 ( & V_50 -> V_93 , & V_97 , V_95 , 0 ) ;
V_38 = F_45 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
RETURN ( F_41 ( V_38 ) ) ;
}
V_68 = F_47 ( & V_50 -> V_93 , & V_103 ) ;
V_68 -> V_104 = ( T_1 ) V_2 -> V_82 ;
V_122 = F_47 ( & V_50 -> V_93 , & V_124 ) ;
V_122 -> V_125 = V_126 ;
F_43 ( & V_50 -> V_93 , & V_127 , V_106 ,
V_42 -> V_98 . V_99 . V_110 ) ;
F_50 ( V_50 ) ;
RETURN ( V_50 ) ;
}
static struct V_49 *
F_56 ( struct V_12 * exp , int V_128 )
{
struct V_49 * V_50 ;
int V_38 ;
V_20 ;
V_50 = F_38 ( F_39 ( exp ) , & V_129 ) ;
if ( V_50 == NULL )
RETURN ( F_41 ( - V_89 ) ) ;
V_38 = F_45 ( exp , V_50 , NULL , 0 ) ;
if ( V_38 ) {
F_46 ( V_50 ) ;
RETURN ( F_41 ( V_38 ) ) ;
}
F_43 ( & V_50 -> V_93 , & V_127 , V_106 , V_128 ) ;
F_50 ( V_50 ) ;
RETURN ( V_50 ) ;
}
static int F_57 ( struct V_12 * exp ,
struct V_49 * V_50 ,
struct V_130 * V_131 ,
struct V_1 * V_2 ,
struct V_21 * V_13 ,
int V_38 )
{
struct V_132 * V_133 = & V_50 -> V_93 ;
struct V_134 * V_135 ;
struct V_136 * V_137 ;
struct V_138 * V_139 = & V_2 -> V_4 . V_5 ;
struct V_16 * V_17 ;
void * V_140 = NULL ;
int V_128 = 0 ;
V_20 ;
F_9 ( V_38 >= 0 ) ;
if ( V_50 -> V_53 || V_50 -> V_51 ) {
V_135 = F_47 ( V_133 , & V_141 ) ;
V_135 -> V_142 |= F_58 ( V_143 ) ;
}
if ( V_38 == V_144 ) {
V_131 -> V_145 = 0 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_38 = 0 ;
} else {
V_17 = F_8 ( V_13 ) ;
F_9 ( V_17 != NULL ) ;
if ( V_17 -> V_146 != V_131 -> V_145 ) {
F_59 ( V_13 , V_17 -> V_146 ) ;
F_60 ( V_13 , V_131 -> V_145 ) ;
V_131 -> V_145 = V_17 -> V_146 ;
}
F_13 ( V_17 ) ;
}
V_137 = F_61 ( V_133 , & V_147 ) ;
F_9 ( V_137 != NULL ) ;
V_139 -> F_1 = ( int ) V_137 -> V_148 ;
V_139 -> V_8 = ( int ) V_137 -> V_149 ;
V_139 -> V_150 = V_131 -> V_145 ;
V_139 -> V_151 = V_13 -> V_152 ;
V_139 -> V_153 = V_50 ;
if ( ( ! V_50 -> V_53 || V_139 -> V_8 < 0 ) && V_50 -> V_51 )
F_27 ( V_50 , V_139 -> V_8 ) ;
if ( V_2 -> V_82 & V_154 && V_50 -> V_51 &&
( ! F_1 ( V_2 , V_7 ) || V_139 -> V_8 != 0 ) )
F_27 ( V_50 , V_139 -> V_8 ) ;
F_30 ( V_155 , V_50 , L_7 ,
V_2 -> V_82 , V_139 -> F_1 , V_139 -> V_8 ) ;
if ( V_2 -> V_82 & ( V_154 | V_156 | V_157 | V_158 ) ) {
struct V_55 * V_56 ;
V_56 = F_61 ( V_133 , & V_159 ) ;
if ( V_56 == NULL ) {
F_5 ( L_8 ) ;
RETURN ( - V_160 ) ;
}
if ( F_1 ( V_2 , V_7 ) &&
! F_4 ( V_7 , V_2 ) ) {
F_62 ( NULL , NULL , V_50 ) ;
}
if ( ( V_56 -> V_59 & ( V_114 | V_60 ) ) != 0 ) {
void * V_161 ;
F_63 ( exp , V_56 ) ;
V_161 = F_64 ( V_133 , & V_109 ,
V_56 -> V_58 ) ;
if ( V_161 == NULL )
RETURN ( - V_160 ) ;
V_140 = V_161 ;
V_128 = V_56 -> V_58 ;
if ( ( V_2 -> V_82 & V_154 ) && V_50 -> V_51 ) {
void * V_63 ;
if ( F_65 ( V_133 , & V_97 ,
V_95 ) <
V_56 -> V_58 )
F_31 ( V_50 , V_56 ) ;
else
F_66 ( V_133 , & V_97 ,
V_56 -> V_58 ,
V_95 ) ;
F_43 ( V_133 , & V_97 ,
V_95 ,
V_56 -> V_58 ) ;
V_63 = F_47 ( V_133 , & V_97 ) ;
if ( V_63 )
memcpy ( V_63 , V_161 , V_56 -> V_58 ) ;
}
}
if ( V_56 -> V_59 & V_117 ) {
struct V_107 * V_162 ;
F_9 ( F_49 ( exp ) ) ;
V_162 = F_67 ( V_133 , & V_105 ,
V_163 ) ;
if ( V_162 == NULL )
RETURN ( - V_160 ) ;
}
if ( V_56 -> V_59 & V_115 ) {
struct V_164 * V_165 , * V_166 ;
V_165 = F_61 ( V_133 , & V_90 ) ;
if ( V_165 == NULL )
RETURN ( - V_160 ) ;
if ( V_2 -> V_82 & V_154 ) {
V_166 = F_47 ( V_133 , & V_92 ) ;
F_9 ( V_166 ) ;
* V_166 = * V_165 ;
}
}
if ( V_56 -> V_59 & V_167 ) {
struct V_164 * V_165 ;
V_165 = F_61 ( V_133 , & V_92 ) ;
if ( V_165 == NULL )
RETURN ( - V_160 ) ;
}
} else if ( V_2 -> V_82 & V_168 ) {
V_128 = F_65 ( V_133 , & V_127 , V_106 ) ;
if ( V_128 > 0 ) {
V_140 = F_64 ( V_133 ,
& V_127 , V_128 ) ;
if ( V_140 == NULL )
RETURN ( - V_160 ) ;
}
}
V_17 = F_8 ( V_13 ) ;
if ( V_17 != NULL && F_68 ( V_17 ) && V_140 != NULL ) {
void * V_63 ;
F_69 ( V_17 , L_9 ,
F_70 ( V_2 -> V_82 ) , V_128 ) ;
F_71 ( V_63 , V_128 ) ;
if ( V_63 == NULL ) {
F_13 ( V_17 ) ;
RETURN ( - V_89 ) ;
}
memcpy ( V_63 , V_140 , V_128 ) ;
F_10 ( V_17 ) ;
if ( V_17 -> V_169 == NULL ) {
V_17 -> V_169 = V_63 ;
V_17 -> V_170 = V_128 ;
V_63 = NULL ;
}
F_12 ( V_17 ) ;
if ( V_63 != NULL )
F_72 ( V_63 , V_128 ) ;
}
if ( V_17 != NULL )
F_13 ( V_17 ) ;
RETURN ( V_38 ) ;
}
int F_73 ( struct V_12 * exp , struct V_130 * V_131 ,
struct V_1 * V_2 , struct V_61 * V_62 ,
struct V_21 * V_13 , void * V_63 , int V_64 ,
struct V_49 * * V_171 , T_1 V_172 )
{
struct V_41 * V_66 = F_17 ( exp ) ;
struct V_49 * V_50 = NULL ;
T_1 V_31 , V_173 = V_172 ;
int V_38 ;
struct V_36 V_37 ;
static const T_4 V_174 =
{ . V_30 = { V_175 } } ;
static const T_4 V_176 =
{ . V_30 = { V_86 } } ;
static const T_4 V_177 =
{ . V_30 = { V_178 } } ;
T_4 const * V_34 = & V_174 ;
int V_179 , V_180 = 0 ;
struct V_136 * V_137 ;
enum V_181 V_181 = 0 ;
V_20 ;
F_11 ( ! V_2 || V_131 -> V_182 == V_183 , L_10 ,
V_131 -> V_182 ) ;
F_15 ( & V_62 -> V_85 , & V_37 ) ;
if ( V_2 ) {
V_173 |= V_184 ;
if ( V_2 -> V_82 & ( V_156 | V_158 | V_185 ) )
V_34 = & V_176 ;
else if ( V_2 -> V_82 & V_168 )
V_34 = & V_177 ;
}
F_9 ( V_171 == NULL ) ;
V_179 = V_66 -> V_98 . V_99 . V_186 -> V_187 ;
V_188:
V_31 = V_173 ;
if ( ! V_2 ) {
F_9 ( V_63 && V_64 == 0 ) ;
F_11 ( V_131 -> V_182 == V_189 , L_10 ,
V_131 -> V_182 ) ;
V_34 = ( T_4 * ) V_63 ;
V_37 . V_190 [ 3 ] = V_189 ;
} else if ( V_2 -> V_82 & V_154 ) {
V_50 = F_33 ( exp , V_2 , V_62 , V_63 , V_64 ,
V_131 -> V_191 ) ;
V_34 = & V_176 ;
V_131 -> V_191 = NULL ;
V_63 = NULL ;
} else if ( V_2 -> V_82 & V_156 ) {
V_50 = F_51 ( exp , V_2 , V_62 ) ;
} else if ( V_2 -> V_82 & ( V_158 | V_157 ) ) {
V_50 = F_53 ( exp , V_2 , V_62 ) ;
} else if ( V_2 -> V_82 & V_185 ) {
V_50 = F_56 ( exp , 0 ) ;
} else if ( V_2 -> V_82 & V_168 ) {
if ( ! F_74 ( F_39 ( exp ) ) )
RETURN ( - V_192 ) ;
V_50 = F_55 ( exp , V_2 , V_62 ) ;
V_181 = V_193 ;
} else {
F_6 () ;
RETURN ( - V_194 ) ;
}
if ( F_75 ( V_50 ) )
RETURN ( F_76 ( V_50 ) ) ;
if ( V_50 != NULL && V_2 && V_2 -> V_82 & V_83 )
V_50 -> V_195 = 1 ;
if ( V_180 ) {
V_50 -> V_196 = 1 ;
V_50 -> V_197 = V_179 ;
V_50 -> V_198 = F_77 () + V_180 ;
}
if ( V_2 ) {
F_78 ( V_66 -> V_98 . V_99 . V_199 , V_2 ) ;
V_38 = F_79 ( & V_66 -> V_98 . V_99 ) ;
if ( V_38 != 0 ) {
F_80 ( V_66 -> V_98 . V_99 . V_199 , V_2 ) ;
F_27 ( V_50 , 0 ) ;
F_81 ( V_50 ) ;
RETURN ( V_38 ) ;
}
}
V_38 = F_82 ( exp , & V_50 , V_131 , & V_37 , V_34 , & V_31 , NULL ,
0 , V_181 , V_13 , 0 ) ;
if ( ! V_2 ) {
RETURN ( V_38 ) ;
}
F_83 ( & V_66 -> V_98 . V_99 ) ;
F_80 ( V_66 -> V_98 . V_99 . V_199 , V_2 ) ;
if ( V_38 < 0 ) {
F_5 ( L_11 , V_38 ) ;
F_27 ( V_50 , V_38 ) ;
F_81 ( V_50 ) ;
RETURN ( V_38 ) ;
}
V_137 = F_61 ( & V_50 -> V_93 , & V_147 ) ;
F_9 ( V_137 != NULL ) ;
if ( V_2 && V_2 -> V_82 & V_83 &&
( int ) V_137 -> V_149 == - V_200 ) {
F_27 ( V_50 , V_38 ) ;
F_81 ( V_50 ) ;
V_180 ++ ;
F_84 ( V_201 , L_12 V_202 L_13 V_202 L_14 ,
V_66 -> V_203 , V_180 , V_2 -> V_82 ,
F_85 ( & V_62 -> V_85 ) , F_85 ( & V_62 -> V_74 ) ) ;
if ( V_179 == V_66 -> V_98 . V_99 . V_186 -> V_187 ) {
goto V_188;
} else {
F_84 ( V_201 , L_15 ) ;
RETURN ( - V_204 ) ;
}
}
V_38 = F_57 ( exp , V_50 , V_131 , V_2 , V_13 , V_38 ) ;
if ( V_38 < 0 ) {
if ( F_86 ( V_13 ) ) {
F_60 ( V_13 , V_131 -> V_145 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
}
F_81 ( V_50 ) ;
}
RETURN ( V_38 ) ;
}
static int F_87 ( struct V_12 * exp ,
struct V_49 * V_205 ,
struct V_61 * V_62 ,
struct V_1 * V_2 ,
struct V_21 * V_13 )
{
struct V_21 V_206 ;
struct V_55 * V_55 ;
struct V_16 * V_17 ;
int V_38 ;
F_9 ( V_205 != NULL ) ;
F_9 ( V_205 != V_207 ) ;
F_9 ( V_205 -> V_208 != V_207 ) ;
if ( ! F_1 ( V_2 , V_11 ) ) {
F_9 ( V_2 -> V_4 . V_5 . V_8 != 0 ) ;
RETURN ( V_2 -> V_4 . V_5 . V_8 ) ;
}
V_38 = F_4 ( V_11 , V_2 ) ;
if ( V_38 )
RETURN ( V_38 ) ;
V_55 = F_61 ( & V_205 -> V_93 , & V_159 ) ;
F_9 ( V_55 != NULL ) ;
if ( F_35 ( & V_62 -> V_74 ) &&
V_2 -> V_71 & V_209 &&
V_2 -> V_82 != V_158 ) {
F_2 ( V_2 , V_210 ) ;
if ( ( ! F_88 ( & V_62 -> V_74 , & V_55 -> V_211 ) ) &&
( ! F_88 ( & V_62 -> V_212 , & V_55 -> V_211 ) ) ) {
F_84 ( V_213 , L_16 V_202 L_17 V_202 L_18 V_202
L_14 , F_85 ( & V_62 -> V_74 ) ,
F_85 ( & V_62 -> V_74 ) , F_85 ( & V_55 -> V_211 ) ) ;
RETURN ( - V_214 ) ;
}
}
V_38 = F_4 ( V_10 , V_2 ) ;
if ( V_38 )
RETURN ( V_38 ) ;
if ( ! F_1 ( V_2 , V_215 ) &&
F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_2 ( V_2 , V_215 ) ;
F_89 ( V_205 ) ;
}
if ( ! F_1 ( V_2 , V_216 ) &&
F_1 ( V_2 , V_7 ) &&
! F_4 ( V_7 , V_2 ) ) {
F_2 ( V_2 , V_216 ) ;
F_89 ( V_205 ) ;
F_90 ( V_217 , V_218 ) ;
}
if ( V_2 -> V_82 & V_83 ) {
} else if ( V_2 -> V_82 == V_154 ) {
F_9 ( ! F_1 ( V_2 , V_9 ) ) ;
} else {
F_9 ( V_2 -> V_82 & ( V_158 | V_157 | V_168 ) ) ;
}
V_17 = F_8 ( V_13 ) ;
if ( V_17 ) {
T_4 V_34 = V_17 -> V_29 ;
F_69 ( V_17 , L_19 ) ;
F_11 ( F_91 ( & V_55 -> V_211 ,
& V_17 -> V_22 -> V_219 ) ,
L_20 ,
( unsigned long ) V_17 -> V_22 -> V_219 . V_190 [ 0 ] ,
( unsigned long ) V_17 -> V_22 -> V_219 . V_190 [ 1 ] ,
( unsigned long ) V_17 -> V_22 -> V_219 . V_190 [ 2 ] ,
( unsigned long ) F_92 ( & V_55 -> V_211 ) ,
( unsigned long ) F_93 ( & V_55 -> V_211 ) ,
( unsigned long ) F_94 ( & V_55 -> V_211 ) ) ;
F_13 ( V_17 ) ;
memcpy ( & V_206 , V_13 , sizeof( * V_13 ) ) ;
if ( F_16 ( NULL , V_220 , NULL ,
V_183 , & V_34 , V_221 , & V_206 , 0 ) ) {
F_95 ( V_13 ,
V_2 -> V_4 . V_5 . V_150 ) ;
memcpy ( V_13 , & V_206 , sizeof( V_206 ) ) ;
V_2 -> V_4 . V_5 . V_151 = V_13 -> V_152 ;
}
}
F_84 ( V_213 , L_21 ,
V_62 -> V_96 , V_62 -> V_222 , F_70 ( V_2 -> V_82 ) ,
V_2 -> V_4 . V_5 . V_8 , V_2 -> V_4 . V_5 . F_1 , V_38 ) ;
RETURN ( V_38 ) ;
}
int F_96 ( struct V_12 * exp , struct V_1 * V_2 ,
struct V_32 * V_33 , T_1 * V_15 )
{
struct V_36 V_37 ;
struct V_21 V_13 ;
T_4 V_34 ;
T_2 V_35 ;
V_20 ;
if ( V_2 -> V_4 . V_5 . V_151 ) {
V_13 . V_152 = V_2 -> V_4 . V_5 . V_151 ;
V_35 = F_97 ( & V_13 , V_15 ) ;
} else {
F_15 ( V_33 , & V_37 ) ;
switch ( V_2 -> V_82 ) {
case V_158 :
V_34 . V_30 . V_15 = V_86 ;
break;
case V_168 :
V_34 . V_30 . V_15 = V_178 ;
break;
default:
V_34 . V_30 . V_15 = V_175 ;
break;
}
V_35 = F_16 ( exp -> V_223 -> V_39 ,
V_220 , & V_37 ,
V_183 , & V_34 ,
V_80 | V_78 | V_79 | V_224 , & V_13 , 0 ) ;
}
if ( V_35 ) {
V_2 -> V_4 . V_5 . V_151 = V_13 . V_152 ;
V_2 -> V_4 . V_5 . V_150 = V_35 ;
} else {
V_2 -> V_4 . V_5 . V_151 = 0 ;
V_2 -> V_4 . V_5 . V_150 = 0 ;
}
RETURN ( ! ! V_35 ) ;
}
int F_98 ( struct V_12 * exp , struct V_61 * V_62 ,
void * V_63 , int V_64 , struct V_1 * V_2 ,
int V_225 , struct V_49 * * V_171 ,
T_8 V_226 ,
T_1 V_172 )
{
struct V_21 V_13 ;
int V_38 = 0 ;
V_20 ;
F_9 ( V_2 ) ;
F_84 ( V_227 , L_22 V_202 L_23 V_202
L_24 , V_62 -> V_96 ,
V_62 -> V_222 , F_85 ( & V_62 -> V_74 ) ,
F_85 ( & V_62 -> V_85 ) , F_70 ( V_2 -> V_82 ) ,
V_2 -> V_75 ) ;
V_13 . V_152 = 0 ;
if ( F_35 ( & V_62 -> V_74 ) &&
( V_2 -> V_82 & ( V_157 | V_158 ) ) ) {
V_2 -> V_4 . V_5 . V_151 = 0 ;
V_38 = F_96 ( exp , V_2 , & V_62 -> V_74 , NULL ) ;
if ( V_38 || V_62 -> V_96 != 0 )
RETURN ( V_38 ) ;
}
if ( ! F_1 ( V_2 , V_210 ) ) {
struct V_130 V_131 =
{ V_183 , F_99 ( V_2 ) , V_226 ,
V_228 , NULL , NULL , NULL } ;
if ( ! F_35 ( & V_62 -> V_74 ) && V_2 -> V_82 & V_83 ) {
V_38 = F_100 ( exp , & V_62 -> V_74 , V_62 ) ;
if ( V_38 < 0 ) {
F_5 ( L_25 , V_38 ) ;
RETURN ( V_38 ) ;
}
}
V_38 = F_73 ( exp , & V_131 , V_2 , V_62 , & V_13 ,
V_63 , V_64 , NULL , V_172 ) ;
if ( V_38 < 0 )
RETURN ( V_38 ) ;
} else if ( ! F_35 ( & V_62 -> V_74 ) ||
! ( V_2 -> V_71 & V_209 ) ) {
F_3 ( V_2 , V_210 ) ;
}
* V_171 = V_2 -> V_4 . V_5 . V_153 ;
V_38 = F_87 ( exp , * V_171 , V_62 , V_2 , & V_13 ) ;
RETURN ( V_38 ) ;
}
static int F_101 ( const struct V_229 * V_230 ,
struct V_49 * V_50 ,
void * args , int V_38 )
{
struct V_231 * V_232 = args ;
struct V_12 * exp = V_232 -> V_233 ;
struct V_234 * V_235 = V_232 -> V_236 ;
struct V_130 * V_131 = V_232 -> V_237 ;
struct V_1 * V_2 ;
struct V_21 * V_13 ;
struct V_41 * V_66 ;
T_1 V_31 = V_184 ;
V_20 ;
V_2 = & V_235 -> V_238 ;
V_13 = & V_235 -> V_239 ;
V_66 = F_17 ( exp ) ;
F_83 ( & V_66 -> V_98 . V_99 ) ;
if ( F_102 ( V_240 ) )
V_38 = - V_241 ;
V_38 = F_103 ( exp , V_50 , V_131 -> V_182 , 1 , V_131 -> V_145 ,
& V_31 , NULL , 0 , V_13 , V_38 ) ;
if ( V_38 < 0 ) {
F_5 ( L_26 , V_38 ) ;
F_27 ( V_50 , V_38 ) ;
GOTO ( V_242 , V_38 ) ;
}
V_38 = F_57 ( exp , V_50 , V_131 , V_2 , V_13 , V_38 ) ;
if ( V_38 )
GOTO ( V_242 , V_38 ) ;
V_38 = F_87 ( exp , V_50 , & V_235 -> V_243 , V_2 , V_13 ) ;
EXIT ;
V_242:
F_104 ( V_131 ) ;
V_235 -> V_244 ( V_50 , V_235 , V_38 ) ;
return 0 ;
}
int F_105 ( struct V_12 * exp ,
struct V_234 * V_235 ,
struct V_130 * V_131 )
{
struct V_61 * V_62 = & V_235 -> V_243 ;
struct V_1 * V_2 = & V_235 -> V_238 ;
struct V_49 * V_50 ;
struct V_231 * V_232 ;
struct V_41 * V_66 = F_17 ( exp ) ;
struct V_36 V_37 ;
T_4 V_34 = {
. V_30 = { V_175 |
V_86 }
} ;
int V_38 = 0 ;
T_1 V_31 = V_184 ;
V_20 ;
F_84 ( V_227 , L_27 V_202 L_24 ,
V_62 -> V_96 , V_62 -> V_222 , F_85 ( & V_62 -> V_85 ) ,
F_70 ( V_2 -> V_82 ) , V_2 -> V_75 ) ;
F_15 ( & V_62 -> V_85 , & V_37 ) ;
V_50 = F_53 ( exp , V_2 , V_62 ) ;
if ( ! V_50 )
RETURN ( - V_89 ) ;
V_38 = F_79 ( & V_66 -> V_98 . V_99 ) ;
if ( V_38 != 0 ) {
F_81 ( V_50 ) ;
RETURN ( V_38 ) ;
}
V_38 = F_82 ( exp , & V_50 , V_131 , & V_37 , & V_34 , & V_31 , NULL ,
0 , V_245 , & V_235 -> V_239 , 1 ) ;
if ( V_38 < 0 ) {
F_83 ( & V_66 -> V_98 . V_99 ) ;
F_81 ( V_50 ) ;
RETURN ( V_38 ) ;
}
F_106 ( sizeof( * V_232 ) <= sizeof( V_50 -> V_246 ) ) ;
V_232 = F_107 ( V_50 ) ;
V_232 -> V_233 = exp ;
V_232 -> V_236 = V_235 ;
V_232 -> V_237 = V_131 ;
V_50 -> V_247 = F_101 ;
F_108 ( V_50 , V_248 , - 1 ) ;
RETURN ( 0 ) ;
}
