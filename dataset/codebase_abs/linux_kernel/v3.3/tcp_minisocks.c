static int F_1 ( struct V_1 * V_2 )
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
return 1 ;
}
return 0 ;
}
static int F_6 ( struct V_20 * V_21 )
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
return 1 ;
}
return 0 ;
}
static T_1 int F_9 ( V_16 V_26 , V_16 V_27 , V_16 V_28 , V_16 V_29 )
{
if ( V_26 == V_28 )
return 1 ;
if ( F_10 ( V_27 , V_28 ) && F_11 ( V_26 , V_29 ) )
return 1 ;
return V_26 == V_29 && V_26 == V_27 ;
}
enum V_30
F_12 ( struct V_20 * V_21 , struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
struct V_35 V_36 ;
const T_2 * V_37 ;
struct V_22 * V_23 = F_8 ( (struct V_1 * ) V_21 ) ;
int V_38 = 0 ;
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
int V_68 = 0 ;
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
memset ( V_23 -> V_98 , 0 , sizeof( V_23 -> V_98 ) ) ;
V_23 -> V_99 = 0 ;
V_97 = V_6 -> V_100 -> V_101 ( V_2 , V_2 ) ;
if ( V_97 != NULL ) {
memcpy ( & V_23 -> V_98 , V_97 -> V_97 , V_97 -> V_102 ) ;
V_23 -> V_99 = V_97 -> V_102 ;
if ( F_30 ( V_2 ) == NULL )
F_31 () ;
}
} while ( 0 );
#endif
F_32 ( V_21 , V_2 , & V_103 ) ;
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
F_19 ( F_33 ( V_2 ) , V_104 ) ;
}
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
#ifdef F_29
struct V_22 * V_105 = F_8 ( V_2 ) ;
if ( V_105 -> V_99 )
F_37 () ;
#endif
}
static inline void F_38 ( struct V_5 * V_6 ,
struct V_106 * V_107 )
{
V_6 -> V_108 = F_39 ( V_107 ) -> V_109 ? V_110 : 0 ;
}
struct V_1 * F_40 ( struct V_1 * V_2 , struct V_106 * V_107 , struct V_31 * V_32 )
{
struct V_1 * V_111 = F_41 ( V_2 , V_107 , V_112 ) ;
if ( V_111 != NULL ) {
const struct V_113 * V_114 = F_39 ( V_107 ) ;
struct V_115 * V_116 = F_42 ( V_107 ) ;
struct V_3 * V_117 = F_2 ( V_111 ) ;
struct V_5 * V_118 = F_3 ( V_111 ) ;
struct V_5 * V_119 = F_3 ( V_2 ) ;
struct V_120 * V_121 = V_119 -> V_122 ;
if ( V_121 != NULL ) {
struct V_120 * V_123 =
F_43 ( sizeof( * V_118 -> V_122 ) ,
V_112 ) ;
if ( V_123 != NULL ) {
F_44 ( & V_123 -> V_124 ) ;
V_123 -> V_125 =
V_121 -> V_125 ;
V_118 -> V_122 = V_123 ;
} else {
V_118 -> V_122 = NULL ;
}
}
V_118 -> V_126 = 0 ;
V_118 -> V_127 = V_118 -> V_128 =
V_118 -> V_77 = V_116 -> V_129 + 1 ;
V_118 -> V_130 = V_118 -> V_131 =
V_118 -> V_78 = V_118 -> V_132 =
V_116 -> V_133 + 1 + F_45 ( V_119 ) ;
F_46 ( V_118 ) ;
F_47 ( V_118 , V_116 -> V_129 ) ;
V_118 -> V_134 = 0 ;
V_118 -> V_135 = V_136 ;
V_117 -> V_72 = V_136 ;
V_118 -> V_137 = 0 ;
V_118 -> V_138 = 0 ;
V_118 -> V_139 = 0 ;
V_118 -> V_140 = 0 ;
V_118 -> V_141 = V_142 ;
V_118 -> V_143 = V_144 ;
V_118 -> V_145 = 0 ;
V_118 -> V_146 = 0 ;
V_118 -> V_147 = 0 ;
V_118 -> V_148 = 0 ;
if ( V_117 -> V_149 != & V_150 &&
! F_48 ( V_117 -> V_149 -> V_151 ) )
V_117 -> V_149 = & V_150 ;
F_49 ( V_111 , V_152 ) ;
F_50 ( V_111 ) ;
F_51 ( & V_118 -> V_153 ) ;
V_118 -> V_154 = V_118 -> V_155 =
V_116 -> V_133 + 1 + F_45 ( V_119 ) ;
V_118 -> V_14 . V_39 = 0 ;
V_118 -> V_14 . V_156 = 0 ;
V_118 -> V_14 . V_157 = 0 ;
V_118 -> V_158 = 0 ;
if ( F_52 ( V_111 , V_159 ) )
F_53 ( V_111 ,
F_54 ( V_118 ) ) ;
V_118 -> V_14 . V_160 = V_114 -> V_160 ;
if ( ( V_118 -> V_14 . V_161 = V_114 -> V_161 ) != 0 ) {
if ( V_162 )
F_55 ( V_118 ) ;
}
V_118 -> V_163 = V_107 -> V_163 ;
V_118 -> V_164 = V_107 -> V_165 ;
V_118 -> V_165 = V_107 -> V_165 ;
V_118 -> V_14 . V_166 = V_114 -> V_166 ;
if ( V_118 -> V_14 . V_166 ) {
V_118 -> V_14 . V_167 = V_114 -> V_167 ;
V_118 -> V_14 . V_76 = V_114 -> V_76 ;
} else {
V_118 -> V_14 . V_167 = V_118 -> V_14 . V_76 = 0 ;
V_118 -> V_163 = F_56 ( V_118 -> V_163 , 65535U ) ;
}
V_118 -> V_168 = ( F_57 ( F_58 ( V_32 ) -> V_169 ) <<
V_118 -> V_14 . V_167 ) ;
V_118 -> V_170 = V_118 -> V_168 ;
if ( V_118 -> V_14 . V_160 ) {
V_118 -> V_14 . V_15 = V_107 -> V_15 ;
V_118 -> V_14 . V_19 = F_4 () ;
V_118 -> V_171 = sizeof( struct V_33 ) + V_172 ;
} else {
V_118 -> V_14 . V_19 = 0 ;
V_118 -> V_171 = sizeof( struct V_33 ) ;
}
#ifdef F_29
V_118 -> V_173 = NULL ;
if ( V_118 -> V_100 -> V_101 ( V_2 , V_111 ) )
V_118 -> V_171 += V_174 ;
#endif
if ( V_32 -> V_175 >= V_176 + V_118 -> V_171 )
V_117 -> V_177 . V_178 = V_32 -> V_175 - V_118 -> V_171 ;
V_118 -> V_14 . V_179 = V_107 -> V_180 ;
F_38 ( V_118 , V_107 ) ;
F_59 ( F_33 ( V_2 ) , V_181 ) ;
}
return V_111 ;
}
struct V_1 * F_60 ( struct V_1 * V_2 , struct V_31 * V_32 ,
struct V_106 * V_107 ,
struct V_106 * * V_182 )
{
struct V_35 V_36 ;
const T_2 * V_37 ;
struct V_1 * V_183 ;
const struct V_33 * V_34 = F_58 ( V_32 ) ;
T_3 V_184 = F_61 ( V_34 ) & ( V_185 | V_186 | V_187 ) ;
int V_38 = 0 ;
V_36 . V_39 = 0 ;
if ( V_34 -> V_40 > ( sizeof( struct V_33 ) >> 2 ) ) {
F_13 ( V_32 , & V_36 , & V_37 , 0 ) ;
if ( V_36 . V_39 ) {
V_36 . V_15 = V_107 -> V_15 ;
V_36 . V_19 = F_4 () - ( ( V_136 / V_188 ) << V_107 -> V_189 ) ;
V_38 = F_14 ( & V_36 , V_34 -> V_41 ) ;
}
}
if ( F_15 ( V_32 ) -> V_26 == F_42 ( V_107 ) -> V_129 &&
V_184 == V_186 &&
! V_38 ) {
V_107 -> V_190 -> V_191 ( V_2 , V_107 , NULL ) ;
return NULL ;
}
if ( ( V_184 & V_187 ) &&
( F_15 ( V_32 ) -> V_192 !=
F_42 ( V_107 ) -> V_133 + 1 + F_45 ( F_3 ( V_2 ) ) ) )
return V_2 ;
if ( V_38 || ! F_9 ( F_15 ( V_32 ) -> V_26 , F_15 ( V_32 ) -> V_27 ,
F_42 ( V_107 ) -> V_129 + 1 , F_42 ( V_107 ) -> V_129 + 1 + V_107 -> V_165 ) ) {
if ( ! ( V_184 & V_185 ) )
V_107 -> V_190 -> V_193 ( V_2 , V_32 , V_107 ) ;
if ( V_38 )
F_19 ( F_33 ( V_2 ) , V_65 ) ;
return NULL ;
}
if ( V_36 . V_39 && ! F_10 ( F_15 ( V_32 ) -> V_26 , F_42 ( V_107 ) -> V_129 + 1 ) )
V_107 -> V_15 = V_36 . V_56 ;
if ( F_15 ( V_32 ) -> V_26 == F_42 ( V_107 ) -> V_129 ) {
V_184 &= ~ V_186 ;
}
if ( V_184 & ( V_185 | V_186 ) ) {
F_59 ( F_33 ( V_2 ) , V_194 ) ;
goto V_195;
}
if ( ! ( V_184 & V_187 ) )
return NULL ;
if ( V_107 -> V_189 < F_2 ( V_2 ) -> V_196 . V_197 &&
F_15 ( V_32 ) -> V_27 == F_42 ( V_107 ) -> V_129 + 1 ) {
F_39 ( V_107 ) -> V_198 = 1 ;
F_19 ( F_33 ( V_2 ) , V_199 ) ;
return NULL ;
}
if ( V_36 . V_39 && V_36 . V_200 )
F_42 ( V_107 ) -> V_201 = V_36 . V_200 ;
else if ( V_107 -> V_189 )
F_42 ( V_107 ) -> V_201 = 0 ;
V_183 = F_2 ( V_2 ) -> V_10 -> V_202 ( V_2 , V_32 , V_107 , NULL ) ;
if ( V_183 == NULL )
goto V_203;
F_62 ( V_2 , V_107 , V_182 ) ;
F_63 ( V_2 , V_107 ) ;
F_64 ( V_2 , V_107 , V_183 ) ;
return V_183 ;
V_203:
if ( ! V_204 ) {
F_39 ( V_107 ) -> V_198 = 1 ;
return NULL ;
}
V_195:
F_19 ( F_33 ( V_2 ) , V_205 ) ;
if ( ! ( V_184 & V_185 ) )
V_107 -> V_190 -> V_206 ( V_2 , V_32 ) ;
F_65 ( V_2 , V_107 , V_182 ) ;
return NULL ;
}
int F_66 ( struct V_1 * V_207 , struct V_1 * V_183 ,
struct V_31 * V_32 )
{
int V_208 = 0 ;
int V_66 = V_183 -> V_209 ;
if ( ! F_67 ( V_183 ) ) {
V_208 = F_68 ( V_183 , V_32 , F_58 ( V_32 ) ,
V_32 -> V_175 ) ;
if ( V_66 == V_210 && V_183 -> V_209 != V_66 )
V_207 -> V_211 ( V_207 , 0 ) ;
} else {
F_69 ( V_183 , V_32 ) ;
}
F_70 ( V_183 ) ;
F_71 ( V_183 ) ;
return V_208 ;
}
