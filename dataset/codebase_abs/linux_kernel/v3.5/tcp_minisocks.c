static bool F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_7 * V_8 ;
bool V_9 ;
V_8 = V_4 -> V_10 -> V_11 ( V_2 , & V_9 ) ;
if ( V_8 ) {
if ( ( V_12 ) ( V_8 -> V_13 - V_6 -> V_14 . V_15 ) <= 0 ||
( ( V_16 ) F_4 () - V_8 -> V_17 > V_18 &&
V_8 -> V_17 <= ( V_16 ) V_6 -> V_14 . V_19 ) ) {
V_8 -> V_17 = ( V_16 ) V_6 -> V_14 . V_19 ;
V_8 -> V_13 = V_6 -> V_14 . V_15 ;
}
if ( V_9 )
F_5 ( V_8 ) ;
return true ;
}
return false ;
}
static bool F_6 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = (struct V_1 * ) V_21 ;
struct V_7 * V_8 ;
V_8 = F_7 ( V_2 ) ;
if ( V_8 ) {
const struct V_22 * V_23 = F_8 ( V_2 ) ;
if ( ( V_12 ) ( V_8 -> V_13 - V_23 -> V_24 ) <= 0 ||
( ( V_16 ) F_4 () - V_8 -> V_17 > V_18 &&
V_8 -> V_17 <= ( V_16 ) V_23 -> V_25 ) ) {
V_8 -> V_17 = ( V_16 ) V_23 -> V_25 ;
V_8 -> V_13 = V_23 -> V_24 ;
}
F_5 ( V_8 ) ;
return true ;
}
return false ;
}
static bool F_9 ( V_16 V_26 , V_16 V_27 , V_16 V_28 , V_16 V_29 )
{
if ( V_26 == V_28 )
return true ;
if ( F_10 ( V_27 , V_28 ) && F_11 ( V_26 , V_29 ) )
return true ;
return V_26 == V_29 && V_26 == V_27 ;
}
enum V_30
F_12 ( struct V_20 * V_21 , struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
struct V_35 V_36 ;
const T_1 * V_37 ;
struct V_22 * V_23 = F_8 ( (struct V_1 * ) V_21 ) ;
bool V_38 = false ;
V_36 . V_39 = 0 ;
if ( V_34 -> V_40 > ( sizeof( * V_34 ) >> 2 ) && V_23 -> V_25 ) {
F_13 ( V_32 , & V_36 , & V_37 , 0 ) ;
if ( V_36 . V_39 ) {
V_36 . V_15 = V_23 -> V_24 ;
V_36 . V_19 = V_23 -> V_25 ;
V_38 = F_14 ( & V_36 , V_34 -> V_41 ) ;
}
}
if ( V_21 -> V_42 == V_43 ) {
if ( V_38 ||
! F_9 ( F_15 ( V_32 ) -> V_26 , F_15 ( V_32 ) -> V_27 ,
V_23 -> V_44 ,
V_23 -> V_44 + V_23 -> V_45 ) )
return V_46 ;
if ( V_34 -> V_41 )
goto V_47;
if ( V_34 -> V_48 && ! F_11 ( F_15 ( V_32 ) -> V_26 , V_23 -> V_44 ) )
goto V_49;
if ( ! V_34 -> V_50 ||
! F_10 ( F_15 ( V_32 ) -> V_27 , V_23 -> V_44 ) ||
F_15 ( V_32 ) -> V_27 == F_15 ( V_32 ) -> V_26 ) {
F_16 ( V_21 ) ;
return V_51 ;
}
if ( ! V_34 -> V_52 ||
F_15 ( V_32 ) -> V_27 != V_23 -> V_44 + 1 ) {
V_49:
F_17 ( V_21 , & V_53 ) ;
F_16 ( V_21 ) ;
return V_54 ;
}
V_21 -> V_42 = V_55 ;
V_23 -> V_44 = F_15 ( V_32 ) -> V_27 ;
if ( V_36 . V_39 ) {
V_23 -> V_25 = F_4 () ;
V_23 -> V_24 = V_36 . V_56 ;
}
if ( V_53 . V_57 &&
V_23 -> V_25 &&
F_6 ( V_21 ) )
F_18 ( V_21 , & V_53 , V_21 -> V_58 ,
V_59 ) ;
else
F_18 ( V_21 , & V_53 , V_59 ,
V_59 ) ;
return V_46 ;
}
if ( ! V_38 &&
( F_15 ( V_32 ) -> V_26 == V_23 -> V_44 &&
( F_15 ( V_32 ) -> V_26 == F_15 ( V_32 ) -> V_27 || V_34 -> V_41 ) ) ) {
if ( V_34 -> V_41 ) {
if ( V_60 == 0 ) {
V_47:
F_17 ( V_21 , & V_53 ) ;
F_16 ( V_21 ) ;
return V_51 ;
}
}
F_18 ( V_21 , & V_53 , V_59 ,
V_59 ) ;
if ( V_36 . V_39 ) {
V_23 -> V_24 = V_36 . V_56 ;
V_23 -> V_25 = F_4 () ;
}
F_16 ( V_21 ) ;
return V_51 ;
}
if ( V_34 -> V_48 && ! V_34 -> V_41 && ! V_34 -> V_50 && ! V_38 &&
( F_10 ( F_15 ( V_32 ) -> V_26 , V_23 -> V_44 ) ||
( V_36 . V_39 &&
( V_12 ) ( V_23 -> V_24 - V_36 . V_56 ) < 0 ) ) ) {
V_16 V_61 = V_23 -> V_62 + 65535 + 2 ;
if ( V_61 == 0 )
V_61 ++ ;
F_15 ( V_32 ) -> V_63 = V_61 ;
return V_64 ;
}
if ( V_38 )
F_19 ( F_20 ( V_21 ) , V_65 ) ;
if ( ! V_34 -> V_41 ) {
if ( V_38 || V_34 -> V_50 )
F_18 ( V_21 , & V_53 , V_59 ,
V_59 ) ;
return V_46 ;
}
F_16 ( V_21 ) ;
return V_51 ;
}
void F_21 ( struct V_1 * V_2 , int V_66 , int V_67 )
{
struct V_20 * V_21 = NULL ;
const struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = F_3 ( V_2 ) ;
bool V_68 = false ;
if ( V_53 . V_57 && V_6 -> V_14 . V_19 )
V_68 = F_1 ( V_2 ) ;
if ( V_53 . V_69 < V_53 . V_70 )
V_21 = F_22 ( V_2 , V_66 ) ;
if ( V_21 != NULL ) {
struct V_22 * V_23 = F_8 ( (struct V_1 * ) V_21 ) ;
const int V_71 = ( V_4 -> V_72 << 2 ) - ( V_4 -> V_72 >> 1 ) ;
V_21 -> V_73 = F_23 ( V_2 ) -> V_74 ;
V_21 -> V_75 = V_6 -> V_14 . V_76 ;
V_23 -> V_44 = V_6 -> V_77 ;
V_23 -> V_62 = V_6 -> V_78 ;
V_23 -> V_45 = F_24 ( V_6 ) ;
V_23 -> V_24 = V_6 -> V_14 . V_15 ;
V_23 -> V_25 = V_6 -> V_14 . V_19 ;
#if F_25 ( V_79 )
if ( V_21 -> V_80 == V_81 ) {
struct V_82 * V_83 = F_26 ( V_2 ) ;
struct V_84 * V_85 ;
V_21 -> V_86 = F_27 ( V_2 -> V_87 ) ;
V_85 = F_28 ( (struct V_1 * ) V_21 ) ;
V_85 -> V_88 = V_83 -> V_89 ;
V_85 -> V_90 = V_83 -> V_91 ;
V_21 -> V_92 = V_83 -> V_93 ;
V_21 -> V_94 = V_83 -> V_95 ;
}
#endif
#ifdef F_29
do {
struct V_96 * V_97 ;
V_23 -> V_98 = NULL ;
V_97 = V_6 -> V_99 -> V_100 ( V_2 , V_2 ) ;
if ( V_97 != NULL ) {
V_23 -> V_98 = F_30 ( V_97 , sizeof( * V_97 ) , V_101 ) ;
if ( V_23 -> V_98 && F_31 ( V_2 ) == NULL )
F_32 () ;
}
} while ( 0 );
#endif
F_33 ( V_21 , V_2 , & V_102 ) ;
if ( V_67 < V_71 )
V_67 = V_71 ;
if ( V_68 ) {
V_21 -> V_58 = V_71 ;
} else {
V_21 -> V_58 = V_59 ;
if ( V_66 == V_55 )
V_67 = V_59 ;
}
F_18 ( V_21 , & V_53 , V_67 ,
V_59 ) ;
F_16 ( V_21 ) ;
} else {
F_19 ( F_34 ( V_2 ) , V_103 ) ;
}
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
#ifdef F_29
struct V_22 * V_104 = F_8 ( V_2 ) ;
if ( V_104 -> V_98 ) {
F_38 () ;
F_39 ( V_104 -> V_98 , V_105 ) ;
}
#endif
}
static inline void F_40 ( struct V_5 * V_6 ,
struct V_106 * V_107 )
{
V_6 -> V_108 = F_41 ( V_107 ) -> V_109 ? V_110 : 0 ;
}
struct V_1 * F_42 ( struct V_1 * V_2 , struct V_106 * V_107 , struct V_31 * V_32 )
{
struct V_1 * V_111 = F_43 ( V_2 , V_107 , V_101 ) ;
if ( V_111 != NULL ) {
const struct V_112 * V_113 = F_41 ( V_107 ) ;
struct V_114 * V_115 = F_44 ( V_107 ) ;
struct V_3 * V_116 = F_2 ( V_111 ) ;
struct V_5 * V_117 = F_3 ( V_111 ) ;
struct V_5 * V_118 = F_3 ( V_2 ) ;
struct V_119 * V_120 = V_118 -> V_121 ;
if ( V_120 != NULL ) {
struct V_119 * V_122 =
F_45 ( sizeof( * V_117 -> V_121 ) ,
V_101 ) ;
if ( V_122 != NULL ) {
F_46 ( & V_122 -> V_123 ) ;
V_122 -> V_124 =
V_120 -> V_124 ;
V_117 -> V_121 = V_122 ;
} else {
V_117 -> V_121 = NULL ;
}
}
V_117 -> V_125 = 0 ;
V_117 -> V_126 = V_117 -> V_127 =
V_117 -> V_77 = V_115 -> V_128 + 1 ;
V_117 -> V_129 = V_117 -> V_130 =
V_117 -> V_78 = V_117 -> V_131 =
V_115 -> V_132 + 1 + F_47 ( V_118 ) ;
F_48 ( V_117 ) ;
F_49 ( V_117 , V_115 -> V_128 ) ;
V_117 -> V_133 = 0 ;
V_117 -> V_134 = V_135 ;
V_116 -> V_72 = V_135 ;
V_117 -> V_136 = 0 ;
V_117 -> V_137 = 0 ;
V_117 -> V_138 = 0 ;
V_117 -> V_139 = 0 ;
V_117 -> V_140 = V_141 ;
F_50 ( V_117 ) ;
V_117 -> V_142 = V_143 ;
V_117 -> V_144 = 0 ;
V_117 -> V_145 = 0 ;
V_117 -> V_146 = 0 ;
V_117 -> V_147 = 0 ;
if ( V_116 -> V_148 != & V_149 &&
! F_51 ( V_116 -> V_148 -> V_150 ) )
V_116 -> V_148 = & V_149 ;
F_52 ( V_111 , V_151 ) ;
F_53 ( V_111 ) ;
F_54 ( & V_117 -> V_152 ) ;
V_117 -> V_153 = V_117 -> V_154 =
V_115 -> V_132 + 1 + F_47 ( V_118 ) ;
V_117 -> V_14 . V_39 = 0 ;
V_117 -> V_14 . V_155 = 0 ;
V_117 -> V_14 . V_156 = 0 ;
V_117 -> V_157 = 0 ;
if ( F_55 ( V_111 , V_158 ) )
F_56 ( V_111 ,
F_57 ( V_117 ) ) ;
V_117 -> V_14 . V_159 = V_113 -> V_159 ;
if ( ( V_117 -> V_14 . V_160 = V_113 -> V_160 ) != 0 ) {
if ( V_161 )
F_58 ( V_117 ) ;
}
V_117 -> V_162 = V_107 -> V_162 ;
V_117 -> V_163 = V_107 -> V_164 ;
V_117 -> V_164 = V_107 -> V_164 ;
V_117 -> V_14 . V_165 = V_113 -> V_165 ;
if ( V_117 -> V_14 . V_165 ) {
V_117 -> V_14 . V_166 = V_113 -> V_166 ;
V_117 -> V_14 . V_76 = V_113 -> V_76 ;
} else {
V_117 -> V_14 . V_166 = V_117 -> V_14 . V_76 = 0 ;
V_117 -> V_162 = F_59 ( V_117 -> V_162 , 65535U ) ;
}
V_117 -> V_167 = ( F_60 ( F_61 ( V_32 ) -> V_168 ) <<
V_117 -> V_14 . V_166 ) ;
V_117 -> V_169 = V_117 -> V_167 ;
if ( V_117 -> V_14 . V_159 ) {
V_117 -> V_14 . V_15 = V_107 -> V_15 ;
V_117 -> V_14 . V_19 = F_4 () ;
V_117 -> V_170 = sizeof( struct V_33 ) + V_171 ;
} else {
V_117 -> V_14 . V_19 = 0 ;
V_117 -> V_170 = sizeof( struct V_33 ) ;
}
#ifdef F_29
V_117 -> V_172 = NULL ;
if ( V_117 -> V_99 -> V_100 ( V_2 , V_111 ) )
V_117 -> V_170 += V_173 ;
#endif
if ( V_32 -> V_174 >= V_175 + V_117 -> V_170 )
V_116 -> V_176 . V_177 = V_32 -> V_174 - V_117 -> V_170 ;
V_117 -> V_14 . V_178 = V_107 -> V_179 ;
F_40 ( V_117 , V_107 ) ;
F_62 ( F_34 ( V_2 ) , V_180 ) ;
}
return V_111 ;
}
struct V_1 * F_63 ( struct V_1 * V_2 , struct V_31 * V_32 ,
struct V_106 * V_107 ,
struct V_106 * * V_181 )
{
struct V_35 V_36 ;
const T_1 * V_37 ;
struct V_1 * V_182 ;
const struct V_33 * V_34 = F_61 ( V_32 ) ;
T_2 V_183 = F_64 ( V_34 ) & ( V_184 | V_185 | V_186 ) ;
bool V_38 = false ;
V_36 . V_39 = 0 ;
if ( V_34 -> V_40 > ( sizeof( struct V_33 ) >> 2 ) ) {
F_13 ( V_32 , & V_36 , & V_37 , 0 ) ;
if ( V_36 . V_39 ) {
V_36 . V_15 = V_107 -> V_15 ;
V_36 . V_19 = F_4 () - ( ( V_135 / V_187 ) << V_107 -> V_188 ) ;
V_38 = F_14 ( & V_36 , V_34 -> V_41 ) ;
}
}
if ( F_15 ( V_32 ) -> V_26 == F_44 ( V_107 ) -> V_128 &&
V_183 == V_185 &&
! V_38 ) {
V_107 -> V_189 -> V_190 ( V_2 , V_107 , NULL ) ;
return NULL ;
}
if ( ( V_183 & V_186 ) &&
( F_15 ( V_32 ) -> V_191 !=
F_44 ( V_107 ) -> V_132 + 1 + F_47 ( F_3 ( V_2 ) ) ) )
return V_2 ;
if ( V_38 || ! F_9 ( F_15 ( V_32 ) -> V_26 , F_15 ( V_32 ) -> V_27 ,
F_44 ( V_107 ) -> V_128 + 1 , F_44 ( V_107 ) -> V_128 + 1 + V_107 -> V_164 ) ) {
if ( ! ( V_183 & V_184 ) )
V_107 -> V_189 -> V_192 ( V_2 , V_32 , V_107 ) ;
if ( V_38 )
F_19 ( F_34 ( V_2 ) , V_65 ) ;
return NULL ;
}
if ( V_36 . V_39 && ! F_10 ( F_15 ( V_32 ) -> V_26 , F_44 ( V_107 ) -> V_128 + 1 ) )
V_107 -> V_15 = V_36 . V_56 ;
if ( F_15 ( V_32 ) -> V_26 == F_44 ( V_107 ) -> V_128 ) {
V_183 &= ~ V_185 ;
}
if ( V_183 & ( V_184 | V_185 ) ) {
F_62 ( F_34 ( V_2 ) , V_193 ) ;
goto V_194;
}
if ( ! ( V_183 & V_186 ) )
return NULL ;
if ( V_107 -> V_188 < F_2 ( V_2 ) -> V_195 . V_196 &&
F_15 ( V_32 ) -> V_27 == F_44 ( V_107 ) -> V_128 + 1 ) {
F_41 ( V_107 ) -> V_197 = 1 ;
F_19 ( F_34 ( V_2 ) , V_198 ) ;
return NULL ;
}
if ( V_36 . V_39 && V_36 . V_199 )
F_44 ( V_107 ) -> V_200 = V_36 . V_199 ;
else if ( V_107 -> V_188 )
F_44 ( V_107 ) -> V_200 = 0 ;
V_182 = F_2 ( V_2 ) -> V_10 -> V_201 ( V_2 , V_32 , V_107 , NULL ) ;
if ( V_182 == NULL )
goto V_202;
F_65 ( V_2 , V_107 , V_181 ) ;
F_66 ( V_2 , V_107 ) ;
F_67 ( V_2 , V_107 , V_182 ) ;
return V_182 ;
V_202:
if ( ! V_203 ) {
F_41 ( V_107 ) -> V_197 = 1 ;
return NULL ;
}
V_194:
F_19 ( F_34 ( V_2 ) , V_204 ) ;
if ( ! ( V_183 & V_184 ) )
V_107 -> V_189 -> V_205 ( V_2 , V_32 ) ;
F_68 ( V_2 , V_107 , V_181 ) ;
return NULL ;
}
int F_69 ( struct V_1 * V_206 , struct V_1 * V_182 ,
struct V_31 * V_32 )
{
int V_207 = 0 ;
int V_66 = V_182 -> V_208 ;
if ( ! F_70 ( V_182 ) ) {
V_207 = F_71 ( V_182 , V_32 , F_61 ( V_32 ) ,
V_32 -> V_174 ) ;
if ( V_66 == V_209 && V_182 -> V_208 != V_66 )
V_206 -> V_210 ( V_206 , 0 ) ;
} else {
F_72 ( V_182 , V_32 ) ;
}
F_73 ( V_182 ) ;
F_74 ( V_182 ) ;
return V_207 ;
}
