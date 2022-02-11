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
if( V_15 )
* V_15 = 0 ;
if ( ! * V_13 )
return 0 ;
V_17 = F_8 ( (struct V_20 * ) V_13 ) ;
F_9 ( V_17 != NULL ) ;
F_10 ( V_17 ) ;
if ( V_17 -> V_21 -> V_22 &&
V_17 -> V_21 -> V_22 != V_14 ) {
struct V_18 * V_23 = V_17 -> V_21 -> V_22 ;
F_11 ( V_23 -> V_24 & V_25 ,
L_2
L_3 , V_23 ,
V_23 -> V_26 , V_23 -> V_27 ,
V_23 -> V_24 ,
V_19 , V_19 -> V_26 , V_19 -> V_27 ) ;
}
V_17 -> V_21 -> V_22 = V_19 ;
if ( V_15 )
* V_15 = V_17 -> V_28 . V_29 . V_15 ;
F_12 ( V_17 ) ;
F_13 ( V_17 ) ;
return 0 ;
}
T_2 F_14 ( struct V_12 * exp , T_1 V_30 ,
const struct V_31 * V_32 , T_3 type ,
T_4 * V_33 , T_2 V_34 ,
struct V_20 * V_13 )
{
struct V_35 V_36 ;
T_2 V_37 ;
F_15 ( V_32 , & V_36 ) ;
V_37 = F_16 ( F_17 ( exp ) -> V_38 , V_30 ,
& V_36 , type , V_33 , V_34 , V_13 , 0 ) ;
return V_37 ;
}
int F_18 ( struct V_12 * exp ,
const struct V_31 * V_32 ,
T_4 * V_33 ,
T_2 V_34 ,
T_5 V_30 ,
void * V_39 )
{
struct V_35 V_36 ;
struct V_40 * V_41 = F_17 ( exp ) ;
int V_37 ;
F_15 ( V_32 , & V_36 ) ;
V_37 = F_19 ( V_41 -> V_38 , & V_36 ,
V_33 , V_34 , V_30 , V_39 ) ;
return V_37 ;
}
int F_20 ( struct V_12 * exp ,
const struct V_31 * V_32 )
{
struct V_35 V_36 ;
struct V_42 * V_43 ;
struct V_44 * V_45 = F_17 ( exp ) -> V_38 ;
F_11 ( V_45 != NULL , L_4 ) ;
F_15 ( V_32 , & V_36 ) ;
V_43 = F_21 ( V_45 , NULL , & V_36 , 0 , 0 ) ;
if( V_43 == NULL )
return 0 ;
F_22 ( V_43 ) ;
V_43 -> V_22 = NULL ;
F_23 ( V_43 ) ;
F_24 ( V_43 ) ;
return 0 ;
}
int F_25 ( struct V_12 * exp ,
const struct V_31 * V_32 ,
T_6 V_2 , void * V_14 )
{
struct V_35 V_36 ;
int V_37 = 0 ;
F_15 ( (struct V_31 * ) V_32 , & V_36 ) ;
V_37 = F_26 ( F_17 ( exp ) -> V_38 , & V_36 ,
V_2 , V_14 ) ;
if ( V_37 == V_46 )
return 1 ;
else if ( V_37 == V_47 )
return 0 ;
return V_37 ;
}
static inline void F_27 ( struct V_48 * V_49 , int V_37 )
{
if ( V_49 -> V_50 ) {
F_28 ( & V_49 -> V_51 ) ;
V_49 -> V_50 = 0 ;
F_29 ( & V_49 -> V_51 ) ;
}
if ( V_37 && V_49 -> V_52 != 0 ) {
F_30 ( V_53 , V_49 , L_5 , V_37 ) ;
F_6 () ;
}
}
static void F_31 ( struct V_48 * V_49 ,
struct V_54 * V_55 )
{
int V_37 ;
V_37 = F_32 ( V_49 , V_56 + 4 ,
V_55 -> V_57 ) ;
if ( V_37 ) {
F_5 ( L_6 ,
V_56 + 4 , V_55 -> V_57 ) ;
V_55 -> V_58 &= ~ V_59 ;
V_55 -> V_57 = 0 ;
}
}
static struct V_48 * F_33 ( struct V_12 * exp ,
struct V_1 * V_2 ,
struct V_60 * V_61 ,
void * V_62 , int V_63 ,
void * V_64 )
{
struct V_48 * V_49 ;
struct V_40 * V_65 = F_17 ( exp ) ;
struct V_66 * V_67 ;
F_34 ( V_68 ) ;
int V_69 = 0 ;
int V_34 ;
int V_37 ;
V_2 -> V_70 = ( V_2 -> V_70 & ~ V_71 ) | V_72 ;
if ( F_35 ( & V_61 -> V_73 ) ) {
if ( V_2 -> V_74 & ( V_75 | V_76 ) )
V_34 = V_77 ;
#ifdef F_36
else if ( V_2 -> V_74 & F_36 )
V_34 = V_78 ;
#endif
else
V_34 = V_79 ;
V_69 = F_37 ( exp , & V_61 -> V_73 ,
& V_68 , V_34 ,
V_80 ) ;
}
if ( V_2 -> V_81 & V_82 )
V_34 = V_83 ;
else
V_34 = V_79 ;
V_69 += F_37 ( exp , & V_61 -> V_84 ,
& V_68 , V_34 ,
V_85 ) ;
V_49 = F_38 ( F_39 ( exp ) ,
& V_86 ) ;
if ( V_49 == NULL ) {
F_40 ( & V_68 , V_87 , V_69 ) ;
return F_41 ( - V_88 ) ;
}
F_42 ( V_49 , & V_89 , V_61 -> V_90 ) ;
F_42 ( V_49 , & V_91 , V_61 -> V_90 ) ;
F_43 ( & V_49 -> V_92 , & V_93 , V_94 ,
V_61 -> V_95 + 1 ) ;
F_43 ( & V_49 -> V_92 , & V_96 , V_94 ,
F_44 ( V_63 , V_65 -> V_97 . V_98 . V_99 ) ) ;
V_37 = F_45 ( exp , V_49 , & V_68 , V_69 ) ;
if ( V_37 ) {
F_46 ( V_49 ) ;
return NULL ;
}
F_28 ( & V_49 -> V_51 ) ;
V_49 -> V_50 = V_49 -> V_100 -> V_101 ;
F_29 ( & V_49 -> V_51 ) ;
V_67 = F_47 ( & V_49 -> V_92 , & V_102 ) ;
V_67 -> V_103 = ( T_1 ) V_2 -> V_81 ;
F_48 ( V_49 , V_61 , V_2 -> V_70 , 0 , V_2 -> V_74 , V_62 ,
V_63 ) ;
if ( F_49 ( exp ) )
F_43 ( & V_49 -> V_92 , & V_104 , V_105 ,
sizeof( struct V_106 ) ) ;
F_50 ( V_49 ) ;
return V_49 ;
}
static struct V_48 * F_51 ( struct V_12 * exp ,
struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_48 * V_49 ;
struct V_40 * V_65 = F_17 ( exp ) ;
struct V_66 * V_67 ;
int V_37 ;
V_49 = F_38 ( F_39 ( exp ) ,
& V_107 ) ;
if ( V_49 == NULL )
return F_41 ( - V_88 ) ;
F_42 ( V_49 , & V_89 , V_61 -> V_90 ) ;
F_43 ( & V_49 -> V_92 , & V_93 , V_94 ,
V_61 -> V_95 + 1 ) ;
V_37 = F_45 ( exp , V_49 , NULL , 0 ) ;
if ( V_37 ) {
F_46 ( V_49 ) ;
return F_41 ( V_37 ) ;
}
V_67 = F_47 ( & V_49 -> V_92 , & V_102 ) ;
V_67 -> V_103 = ( T_1 ) V_2 -> V_81 ;
F_52 ( V_49 , V_61 ) ;
F_43 ( & V_49 -> V_92 , & V_108 , V_105 ,
V_65 -> V_97 . V_98 . V_109 ) ;
F_43 ( & V_49 -> V_92 , & V_104 , V_105 ,
V_65 -> V_97 . V_98 . V_110 ) ;
F_50 ( V_49 ) ;
return V_49 ;
}
static struct V_48 * F_53 ( struct V_12 * exp ,
struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_48 * V_49 ;
struct V_40 * V_65 = F_17 ( exp ) ;
T_7 V_58 = V_111 | V_59 |
V_112 | V_113 |
V_114 | V_115 |
( F_49 ( exp ) ?
V_116 : V_117 ) ;
struct V_66 * V_67 ;
int V_37 ;
V_49 = F_38 ( F_39 ( exp ) ,
& V_118 ) ;
if ( V_49 == NULL )
return F_41 ( - V_88 ) ;
F_42 ( V_49 , & V_89 , V_61 -> V_90 ) ;
F_43 ( & V_49 -> V_92 , & V_93 , V_94 ,
V_61 -> V_95 + 1 ) ;
V_37 = F_45 ( exp , V_49 , NULL , 0 ) ;
if ( V_37 ) {
F_46 ( V_49 ) ;
return F_41 ( V_37 ) ;
}
V_67 = F_47 ( & V_49 -> V_92 , & V_102 ) ;
V_67 -> V_103 = ( T_1 ) V_2 -> V_81 ;
F_54 ( V_49 , V_58 , V_2 -> V_74 , V_61 ,
V_65 -> V_97 . V_98 . V_109 ) ;
F_43 ( & V_49 -> V_92 , & V_108 , V_105 ,
V_65 -> V_97 . V_98 . V_109 ) ;
if ( F_49 ( exp ) )
F_43 ( & V_49 -> V_92 , & V_104 , V_105 ,
sizeof( struct V_106 ) ) ;
F_50 ( V_49 ) ;
return V_49 ;
}
static struct V_48 * F_55 ( struct V_12 * exp ,
struct V_1 * V_2 ,
struct V_60 * V_119 )
{
struct V_40 * V_41 = F_17 ( exp ) ;
struct V_48 * V_49 ;
struct V_66 * V_67 ;
struct V_120 * V_121 ;
int V_37 ;
V_49 = F_38 ( F_39 ( exp ) ,
& V_122 ) ;
if ( V_49 == NULL )
return F_41 ( - V_88 ) ;
F_43 ( & V_49 -> V_92 , & V_96 , V_94 , 0 ) ;
V_37 = F_45 ( exp , V_49 , NULL , 0 ) ;
if ( V_37 ) {
F_46 ( V_49 ) ;
return F_41 ( V_37 ) ;
}
V_67 = F_47 ( & V_49 -> V_92 , & V_102 ) ;
V_67 -> V_103 = ( T_1 ) V_2 -> V_81 ;
V_121 = F_47 ( & V_49 -> V_92 , & V_123 ) ;
V_121 -> V_124 = V_125 ;
F_43 ( & V_49 -> V_92 , & V_126 , V_105 ,
V_41 -> V_97 . V_98 . V_109 ) ;
F_50 ( V_49 ) ;
return V_49 ;
}
static struct V_48 *
F_56 ( struct V_12 * exp , int V_127 )
{
struct V_48 * V_49 ;
int V_37 ;
V_49 = F_38 ( F_39 ( exp ) , & V_128 ) ;
if ( V_49 == NULL )
return F_41 ( - V_88 ) ;
V_37 = F_45 ( exp , V_49 , NULL , 0 ) ;
if ( V_37 ) {
F_46 ( V_49 ) ;
return F_41 ( V_37 ) ;
}
F_43 ( & V_49 -> V_92 , & V_126 , V_105 , V_127 ) ;
F_50 ( V_49 ) ;
return V_49 ;
}
static int F_57 ( struct V_12 * exp ,
struct V_48 * V_49 ,
struct V_129 * V_130 ,
struct V_1 * V_2 ,
struct V_20 * V_13 ,
int V_37 )
{
struct V_131 * V_132 = & V_49 -> V_92 ;
struct V_133 * V_134 ;
struct V_135 * V_136 ;
struct V_137 * V_138 = & V_2 -> V_4 . V_5 ;
struct V_16 * V_17 ;
void * V_139 = NULL ;
int V_127 = 0 ;
F_9 ( V_37 >= 0 ) ;
if ( V_49 -> V_52 || V_49 -> V_50 ) {
V_134 = F_47 ( V_132 , & V_140 ) ;
V_134 -> V_141 |= F_58 ( V_142 ) ;
}
if ( V_37 == V_143 ) {
V_130 -> V_144 = 0 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_37 = 0 ;
} else {
V_17 = F_8 ( V_13 ) ;
F_9 ( V_17 != NULL ) ;
if ( V_17 -> V_145 != V_130 -> V_144 ) {
F_59 ( V_13 , V_17 -> V_145 ) ;
F_60 ( V_13 , V_130 -> V_144 ) ;
V_130 -> V_144 = V_17 -> V_145 ;
}
F_13 ( V_17 ) ;
}
V_136 = F_61 ( V_132 , & V_146 ) ;
F_9 ( V_136 != NULL ) ;
V_138 -> F_1 = ( int ) V_136 -> V_147 ;
V_138 -> V_8 = ( int ) V_136 -> V_148 ;
V_138 -> V_149 = V_130 -> V_144 ;
V_138 -> V_150 = V_13 -> V_151 ;
V_138 -> V_152 = V_49 ;
if ( ( ! V_49 -> V_52 || V_138 -> V_8 < 0 ) && V_49 -> V_50 )
F_27 ( V_49 , V_138 -> V_8 ) ;
if ( V_2 -> V_81 & V_153 && V_49 -> V_50 &&
( ! F_1 ( V_2 , V_7 ) || V_138 -> V_8 != 0 ) )
F_27 ( V_49 , V_138 -> V_8 ) ;
F_30 ( V_154 , V_49 , L_7 ,
V_2 -> V_81 , V_138 -> F_1 , V_138 -> V_8 ) ;
if ( V_2 -> V_81 & ( V_153 | V_155 | V_156 | V_157 ) ) {
struct V_54 * V_55 ;
V_55 = F_61 ( V_132 , & V_158 ) ;
if ( V_55 == NULL ) {
F_5 ( L_8 ) ;
return - V_159 ;
}
if ( F_1 ( V_2 , V_7 ) &&
! F_4 ( V_7 , V_2 ) ) {
F_62 ( NULL , NULL , V_49 ) ;
}
if ( ( V_55 -> V_58 & ( V_113 | V_59 ) ) != 0 ) {
void * V_160 ;
F_63 ( exp , V_55 ) ;
V_160 = F_64 ( V_132 , & V_108 ,
V_55 -> V_57 ) ;
if ( V_160 == NULL )
return - V_159 ;
V_139 = V_160 ;
V_127 = V_55 -> V_57 ;
if ( ( V_2 -> V_81 & V_153 ) && V_49 -> V_50 ) {
void * V_62 ;
if ( F_65 ( V_132 , & V_96 ,
V_94 ) <
V_55 -> V_57 )
F_31 ( V_49 , V_55 ) ;
else
F_66 ( V_132 , & V_96 ,
V_55 -> V_57 ,
V_94 ) ;
F_43 ( V_132 , & V_96 ,
V_94 ,
V_55 -> V_57 ) ;
V_62 = F_47 ( V_132 , & V_96 ) ;
if ( V_62 )
memcpy ( V_62 , V_160 , V_55 -> V_57 ) ;
}
}
if ( V_55 -> V_58 & V_116 ) {
struct V_106 * V_161 ;
F_9 ( F_49 ( exp ) ) ;
V_161 = F_67 ( V_132 , & V_104 ,
V_162 ) ;
if ( V_161 == NULL )
return - V_159 ;
}
if ( V_55 -> V_58 & V_114 ) {
struct V_163 * V_164 , * V_165 ;
V_164 = F_61 ( V_132 , & V_89 ) ;
if ( V_164 == NULL )
return - V_159 ;
if ( V_2 -> V_81 & V_153 ) {
V_165 = F_47 ( V_132 , & V_91 ) ;
F_9 ( V_165 ) ;
* V_165 = * V_164 ;
}
}
if ( V_55 -> V_58 & V_166 ) {
struct V_163 * V_164 ;
V_164 = F_61 ( V_132 , & V_91 ) ;
if ( V_164 == NULL )
return - V_159 ;
}
} else if ( V_2 -> V_81 & V_167 ) {
V_127 = F_65 ( V_132 , & V_126 , V_105 ) ;
if ( V_127 > 0 ) {
V_139 = F_64 ( V_132 ,
& V_126 , V_127 ) ;
if ( V_139 == NULL )
return - V_159 ;
}
}
V_17 = F_8 ( V_13 ) ;
if ( V_17 != NULL && F_68 ( V_17 ) && V_139 != NULL ) {
void * V_62 ;
F_69 ( V_17 , L_9 ,
F_70 ( V_2 -> V_81 ) , V_127 ) ;
F_71 ( V_62 , V_127 ) ;
if ( V_62 == NULL ) {
F_13 ( V_17 ) ;
return - V_88 ;
}
memcpy ( V_62 , V_139 , V_127 ) ;
F_10 ( V_17 ) ;
if ( V_17 -> V_168 == NULL ) {
V_17 -> V_168 = V_62 ;
V_17 -> V_169 = V_127 ;
V_62 = NULL ;
}
F_12 ( V_17 ) ;
if ( V_62 != NULL )
F_72 ( V_62 , V_127 ) ;
}
if ( V_17 != NULL )
F_13 ( V_17 ) ;
return V_37 ;
}
int F_73 ( struct V_12 * exp , struct V_129 * V_130 ,
struct V_1 * V_2 , struct V_60 * V_61 ,
struct V_20 * V_13 , void * V_62 , int V_63 ,
struct V_48 * * V_170 , T_1 V_171 )
{
struct V_40 * V_65 = F_17 ( exp ) ;
struct V_48 * V_49 = NULL ;
T_1 V_30 , V_172 = V_171 ;
int V_37 ;
struct V_35 V_36 ;
static const T_4 V_173 =
{ . V_29 = { V_174 } } ;
static const T_4 V_175 =
{ . V_29 = { V_85 } } ;
static const T_4 V_176 =
{ . V_29 = { V_177 } } ;
T_4 const * V_33 = & V_173 ;
int V_178 , V_179 = 0 ;
struct V_135 * V_136 ;
enum V_180 V_180 = 0 ;
F_11 ( ! V_2 || V_130 -> V_181 == V_182 , L_10 ,
V_130 -> V_181 ) ;
F_15 ( & V_61 -> V_84 , & V_36 ) ;
if ( V_2 ) {
V_172 |= V_183 ;
if ( V_2 -> V_81 & ( V_155 | V_157 | V_184 ) )
V_33 = & V_175 ;
else if ( V_2 -> V_81 & V_167 )
V_33 = & V_176 ;
}
F_9 ( V_170 == NULL ) ;
V_178 = V_65 -> V_97 . V_98 . V_185 -> V_186 ;
V_187:
V_30 = V_172 ;
if ( ! V_2 ) {
F_9 ( V_62 && V_63 == 0 ) ;
F_11 ( V_130 -> V_181 == V_188 , L_10 ,
V_130 -> V_181 ) ;
V_33 = ( T_4 * ) V_62 ;
V_36 . V_189 [ 3 ] = V_188 ;
} else if ( V_2 -> V_81 & V_153 ) {
V_49 = F_33 ( exp , V_2 , V_61 , V_62 , V_63 ,
V_130 -> V_190 ) ;
V_33 = & V_175 ;
V_130 -> V_190 = NULL ;
V_62 = NULL ;
} else if ( V_2 -> V_81 & V_155 ) {
V_49 = F_51 ( exp , V_2 , V_61 ) ;
} else if ( V_2 -> V_81 & ( V_157 | V_156 ) ) {
V_49 = F_53 ( exp , V_2 , V_61 ) ;
} else if ( V_2 -> V_81 & V_184 ) {
V_49 = F_56 ( exp , 0 ) ;
} else if ( V_2 -> V_81 & V_167 ) {
if ( ! F_74 ( F_39 ( exp ) ) )
return - V_191 ;
V_49 = F_55 ( exp , V_2 , V_61 ) ;
V_180 = V_192 ;
} else {
F_6 () ;
return - V_193 ;
}
if ( F_75 ( V_49 ) )
return F_76 ( V_49 ) ;
if ( V_49 != NULL && V_2 && V_2 -> V_81 & V_82 )
V_49 -> V_194 = 1 ;
if ( V_179 ) {
V_49 -> V_195 = 1 ;
V_49 -> V_196 = V_178 ;
V_49 -> V_197 = F_77 () + V_179 ;
}
if ( V_2 ) {
F_78 ( V_65 -> V_97 . V_98 . V_198 , V_2 ) ;
V_37 = F_79 ( & V_65 -> V_97 . V_98 ) ;
if ( V_37 != 0 ) {
F_80 ( V_65 -> V_97 . V_98 . V_198 , V_2 ) ;
F_27 ( V_49 , 0 ) ;
F_81 ( V_49 ) ;
return V_37 ;
}
}
V_37 = F_82 ( exp , & V_49 , V_130 , & V_36 , V_33 , & V_30 , NULL ,
0 , V_180 , V_13 , 0 ) ;
if ( ! V_2 ) {
if ( ( V_37 == - V_199 ) || ( V_37 == - V_200 ) )
goto V_187;
return V_37 ;
}
F_83 ( & V_65 -> V_97 . V_98 ) ;
F_80 ( V_65 -> V_97 . V_98 . V_198 , V_2 ) ;
if ( V_37 < 0 ) {
F_5 ( L_11 , V_37 ) ;
F_27 ( V_49 , V_37 ) ;
F_81 ( V_49 ) ;
return V_37 ;
}
V_136 = F_61 ( & V_49 -> V_92 , & V_146 ) ;
F_9 ( V_136 != NULL ) ;
V_136 -> V_148 =
F_84 ( V_136 -> V_148 ) ;
if ( V_2 && V_2 -> V_81 & V_82 &&
( int ) V_136 -> V_148 == - V_201 ) {
F_27 ( V_49 , V_37 ) ;
F_81 ( V_49 ) ;
V_179 ++ ;
F_85 ( V_202 , L_12 V_203 L_13 V_203 L_14 ,
V_65 -> V_204 , V_179 , V_2 -> V_81 ,
F_86 ( & V_61 -> V_84 ) , F_86 ( & V_61 -> V_73 ) ) ;
if ( V_178 == V_65 -> V_97 . V_98 . V_185 -> V_186 ) {
goto V_187;
} else {
F_85 ( V_202 , L_15 ) ;
return - V_205 ;
}
}
V_37 = F_57 ( exp , V_49 , V_130 , V_2 , V_13 , V_37 ) ;
if ( V_37 < 0 ) {
if ( F_87 ( V_13 ) ) {
F_60 ( V_13 , V_130 -> V_144 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
}
F_81 ( V_49 ) ;
}
return V_37 ;
}
static int F_88 ( struct V_12 * exp ,
struct V_48 * V_206 ,
struct V_60 * V_61 ,
struct V_1 * V_2 ,
struct V_20 * V_13 )
{
struct V_20 V_207 ;
struct V_54 * V_54 ;
struct V_16 * V_17 ;
int V_37 ;
F_9 ( V_206 != NULL ) ;
F_9 ( V_206 != V_208 ) ;
F_9 ( V_206 -> V_209 != V_208 ) ;
if ( ! F_1 ( V_2 , V_11 ) ) {
F_9 ( V_2 -> V_4 . V_5 . V_8 != 0 ) ;
return V_2 -> V_4 . V_5 . V_8 ;
}
V_37 = F_4 ( V_11 , V_2 ) ;
if ( V_37 )
return V_37 ;
V_54 = F_61 ( & V_206 -> V_92 , & V_158 ) ;
F_9 ( V_54 != NULL ) ;
if ( F_35 ( & V_61 -> V_73 ) &&
V_2 -> V_70 & V_210 &&
V_2 -> V_81 != V_157 ) {
F_2 ( V_2 , V_211 ) ;
if ( ( ! F_89 ( & V_61 -> V_73 , & V_54 -> V_212 ) ) &&
( ! F_89 ( & V_61 -> V_213 , & V_54 -> V_212 ) ) ) {
F_85 ( V_214 , L_16 V_203 L_17 V_203 L_18 V_203
L_14 , F_86 ( & V_61 -> V_73 ) ,
F_86 ( & V_61 -> V_73 ) , F_86 ( & V_54 -> V_212 ) ) ;
return - V_215 ;
}
}
V_37 = F_4 ( V_10 , V_2 ) ;
if ( V_37 )
return V_37 ;
if ( ! F_1 ( V_2 , V_216 ) &&
F_1 ( V_2 , V_9 ) &&
! F_4 ( V_9 , V_2 ) ) {
F_2 ( V_2 , V_216 ) ;
F_90 ( V_206 ) ;
}
if ( ! F_1 ( V_2 , V_217 ) &&
F_1 ( V_2 , V_7 ) &&
! F_4 ( V_7 , V_2 ) ) {
F_2 ( V_2 , V_217 ) ;
F_90 ( V_206 ) ;
F_91 ( V_218 , V_219 ) ;
}
if ( V_2 -> V_81 & V_82 ) {
} else if ( V_2 -> V_81 == V_153 ) {
F_9 ( ! F_1 ( V_2 , V_9 ) ) ;
} else {
F_9 ( V_2 -> V_81 & ( V_157 | V_156 | V_167 ) ) ;
}
V_17 = F_8 ( V_13 ) ;
if ( V_17 ) {
T_4 V_33 = V_17 -> V_28 ;
F_69 ( V_17 , L_19 ) ;
F_11 ( F_92 ( & V_54 -> V_212 ,
& V_17 -> V_21 -> V_220 ) ,
L_20 ,
( unsigned long ) V_17 -> V_21 -> V_220 . V_189 [ 0 ] ,
( unsigned long ) V_17 -> V_21 -> V_220 . V_189 [ 1 ] ,
( unsigned long ) V_17 -> V_21 -> V_220 . V_189 [ 2 ] ,
( unsigned long ) F_93 ( & V_54 -> V_212 ) ,
( unsigned long ) F_94 ( & V_54 -> V_212 ) ,
( unsigned long ) F_95 ( & V_54 -> V_212 ) ) ;
F_13 ( V_17 ) ;
memcpy ( & V_207 , V_13 , sizeof( * V_13 ) ) ;
if ( F_16 ( NULL , V_221 , NULL ,
V_182 , & V_33 , V_222 , & V_207 , 0 ) ) {
F_96 ( V_13 ,
V_2 -> V_4 . V_5 . V_149 ) ;
memcpy ( V_13 , & V_207 , sizeof( V_207 ) ) ;
V_2 -> V_4 . V_5 . V_150 = V_13 -> V_151 ;
}
}
F_85 ( V_214 , L_21 ,
V_61 -> V_95 , V_61 -> V_223 , F_70 ( V_2 -> V_81 ) ,
V_2 -> V_4 . V_5 . V_8 , V_2 -> V_4 . V_5 . F_1 , V_37 ) ;
return V_37 ;
}
int F_97 ( struct V_12 * exp , struct V_1 * V_2 ,
struct V_31 * V_32 , T_1 * V_15 )
{
struct V_35 V_36 ;
struct V_20 V_13 ;
T_4 V_33 ;
T_2 V_34 ;
if ( V_2 -> V_4 . V_5 . V_150 ) {
V_13 . V_151 = V_2 -> V_4 . V_5 . V_150 ;
V_34 = F_98 ( & V_13 , V_15 ) ;
} else {
F_15 ( V_32 , & V_36 ) ;
switch ( V_2 -> V_81 ) {
case V_157 :
V_33 . V_29 . V_15 = V_85 ;
break;
case V_167 :
V_33 . V_29 . V_15 = V_177 ;
break;
default:
V_33 . V_29 . V_15 = V_174 ;
break;
}
V_34 = F_16 ( exp -> V_224 -> V_38 ,
V_221 , & V_36 ,
V_182 , & V_33 ,
V_79 | V_77 | V_78 | V_225 , & V_13 , 0 ) ;
}
if ( V_34 ) {
V_2 -> V_4 . V_5 . V_150 = V_13 . V_151 ;
V_2 -> V_4 . V_5 . V_149 = V_34 ;
} else {
V_2 -> V_4 . V_5 . V_150 = 0 ;
V_2 -> V_4 . V_5 . V_149 = 0 ;
}
return ! ! V_34 ;
}
int F_99 ( struct V_12 * exp , struct V_60 * V_61 ,
void * V_62 , int V_63 , struct V_1 * V_2 ,
int V_226 , struct V_48 * * V_170 ,
T_8 V_227 ,
T_1 V_171 )
{
struct V_20 V_13 ;
int V_37 = 0 ;
F_9 ( V_2 ) ;
F_85 ( V_228 , L_22 V_203 L_23 V_203
L_24 , V_61 -> V_95 ,
V_61 -> V_223 , F_86 ( & V_61 -> V_73 ) ,
F_86 ( & V_61 -> V_84 ) , F_70 ( V_2 -> V_81 ) ,
V_2 -> V_74 ) ;
V_13 . V_151 = 0 ;
if ( F_35 ( & V_61 -> V_73 ) &&
( V_2 -> V_81 & ( V_156 | V_157 ) ) ) {
V_2 -> V_4 . V_5 . V_150 = 0 ;
V_37 = F_97 ( exp , V_2 , & V_61 -> V_73 , NULL ) ;
if ( V_37 || V_61 -> V_95 != 0 )
return V_37 ;
}
if ( ! F_1 ( V_2 , V_211 ) ) {
struct V_129 V_130 = {
. V_181 = V_182 ,
. V_144 = F_100 ( V_2 ) ,
. V_229 = V_227 ,
. V_230 = V_231 ,
} ;
if ( ! F_35 ( & V_61 -> V_73 ) && V_2 -> V_81 & V_82 ) {
V_37 = F_101 ( exp , & V_61 -> V_73 , V_61 ) ;
if ( V_37 < 0 ) {
F_5 ( L_25 , V_37 ) ;
return V_37 ;
}
}
V_37 = F_73 ( exp , & V_130 , V_2 , V_61 , & V_13 ,
V_62 , V_63 , NULL , V_171 ) ;
if ( V_37 < 0 )
return V_37 ;
} else if ( ! F_35 ( & V_61 -> V_73 ) ||
! ( V_2 -> V_70 & V_210 ) ) {
F_3 ( V_2 , V_211 ) ;
}
* V_170 = V_2 -> V_4 . V_5 . V_152 ;
V_37 = F_88 ( exp , * V_170 , V_61 , V_2 , & V_13 ) ;
return V_37 ;
}
static int F_102 ( const struct V_232 * V_233 ,
struct V_48 * V_49 ,
void * args , int V_37 )
{
struct V_234 * V_235 = args ;
struct V_12 * exp = V_235 -> V_236 ;
struct V_237 * V_238 = V_235 -> V_239 ;
struct V_129 * V_130 = V_235 -> V_240 ;
struct V_1 * V_2 ;
struct V_20 * V_13 ;
struct V_40 * V_65 ;
struct V_135 * V_136 ;
T_1 V_30 = V_183 ;
V_2 = & V_238 -> V_241 ;
V_13 = & V_238 -> V_242 ;
V_65 = F_17 ( exp ) ;
F_83 ( & V_65 -> V_97 . V_98 ) ;
if ( F_103 ( V_243 ) )
V_37 = - V_200 ;
V_37 = F_104 ( exp , V_49 , V_130 -> V_181 , 1 , V_130 -> V_144 ,
& V_30 , NULL , 0 , V_13 , V_37 ) ;
if ( V_37 < 0 ) {
F_5 ( L_26 , V_37 ) ;
F_27 ( V_49 , V_37 ) ;
GOTO ( V_244 , V_37 ) ;
}
V_136 = F_61 ( & V_49 -> V_92 , & V_146 ) ;
F_9 ( V_136 != NULL ) ;
V_136 -> V_148 =
F_84 ( V_136 -> V_148 ) ;
V_37 = F_57 ( exp , V_49 , V_130 , V_2 , V_13 , V_37 ) ;
if ( V_37 )
GOTO ( V_244 , V_37 ) ;
V_37 = F_88 ( exp , V_49 , & V_238 -> V_245 , V_2 , V_13 ) ;
V_244:
F_105 ( V_130 ) ;
V_238 -> V_246 ( V_49 , V_238 , V_37 ) ;
return 0 ;
}
int F_106 ( struct V_12 * exp ,
struct V_237 * V_238 ,
struct V_129 * V_130 )
{
struct V_60 * V_61 = & V_238 -> V_245 ;
struct V_1 * V_2 = & V_238 -> V_241 ;
struct V_48 * V_49 ;
struct V_234 * V_235 ;
struct V_40 * V_65 = F_17 ( exp ) ;
struct V_35 V_36 ;
T_4 V_33 = {
. V_29 = { V_174 |
V_85 }
} ;
int V_37 = 0 ;
T_1 V_30 = V_183 ;
F_85 ( V_228 , L_27 V_203 L_24 ,
V_61 -> V_95 , V_61 -> V_223 , F_86 ( & V_61 -> V_84 ) ,
F_70 ( V_2 -> V_81 ) , V_2 -> V_74 ) ;
F_15 ( & V_61 -> V_84 , & V_36 ) ;
V_49 = F_53 ( exp , V_2 , V_61 ) ;
if ( ! V_49 )
return - V_88 ;
V_37 = F_79 ( & V_65 -> V_97 . V_98 ) ;
if ( V_37 != 0 ) {
F_81 ( V_49 ) ;
return V_37 ;
}
V_37 = F_82 ( exp , & V_49 , V_130 , & V_36 , & V_33 , & V_30 , NULL ,
0 , V_247 , & V_238 -> V_242 , 1 ) ;
if ( V_37 < 0 ) {
F_83 ( & V_65 -> V_97 . V_98 ) ;
F_81 ( V_49 ) ;
return V_37 ;
}
F_107 ( sizeof( * V_235 ) <= sizeof( V_49 -> V_248 ) ) ;
V_235 = F_108 ( V_49 ) ;
V_235 -> V_236 = exp ;
V_235 -> V_239 = V_238 ;
V_235 -> V_240 = V_130 ;
V_49 -> V_249 = F_102 ;
F_109 ( V_49 , V_250 , - 1 ) ;
return 0 ;
}
