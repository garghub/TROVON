bool F_1 ( const char * V_1 , int line )
{
if ( V_2 >= V_3 . V_4 )
return false ;
if ( ++ V_2 == V_3 . V_4 ) {
F_2 ( L_1 ,
V_3 . V_4 , V_1 , line ) ;
return true ;
}
return false ;
}
void
F_3 ( struct V_5 * V_6 , const char * V_7 ,
const char * V_8 , ... )
{
static bool V_9 ;
struct V_10 * V_11 = V_6 -> V_11 -> V_11 ;
bool V_12 = V_7 [ 1 ] <= V_13 [ 1 ] ;
bool V_14 = V_7 [ 1 ] == V_15 [ 1 ] ;
struct V_16 V_17 ;
T_1 args ;
if ( V_14 && ! ( V_18 & V_19 ) )
return;
va_start ( args , V_8 ) ;
V_17 . V_8 = V_8 ;
V_17 . V_20 = & args ;
F_4 ( V_7 , V_11 , L_2 V_21 L_3 ,
F_5 ( 0 ) , & V_17 ) ;
if ( V_12 && ! V_9 ) {
F_6 ( V_11 , L_4 , V_22 ) ;
V_9 = true ;
}
va_end ( args ) ;
}
static bool F_7 ( struct V_5 * V_6 )
{
return V_3 . V_4 &&
V_2 == V_3 . V_4 ;
}
static int F_8 ( struct V_23 * V_11 , void * V_24 ,
struct V_25 * V_26 )
{
struct V_5 * V_6 = V_11 -> V_27 ;
T_2 * V_28 = V_24 ;
int V_29 ;
switch ( V_28 -> V_28 ) {
case V_30 :
case V_31 :
case V_32 :
return - V_33 ;
case V_34 :
V_29 = V_11 -> V_35 -> V_10 ;
break;
case V_36 :
V_29 = V_11 -> V_35 -> V_37 ;
break;
case V_38 :
V_29 = 1 ;
break;
case V_39 :
V_29 = V_6 -> V_40 ;
break;
case V_41 :
V_29 = V_6 -> V_42 ? 1 : 0 ;
break;
case V_43 :
V_29 = 1 ;
break;
case V_44 :
V_29 = 1 ;
break;
case V_45 :
V_29 = F_9 ( & V_6 -> V_46 [ V_47 ] ) ;
break;
case V_48 :
V_29 = F_9 ( & V_6 -> V_46 [ V_49 ] ) ;
break;
case V_50 :
V_29 = F_9 ( & V_6 -> V_46 [ V_51 ] ) ;
break;
case V_52 :
V_29 = F_9 ( & V_6 -> V_46 [ V_53 ] ) ;
break;
case V_54 :
V_29 = 1 ;
break;
case V_55 :
V_29 = 1 ;
break;
case V_56 :
V_29 = F_10 ( V_11 ) -> V_57 >= 4 ;
break;
case V_58 :
V_29 = 1 ;
break;
case V_59 :
V_29 = 1 ;
break;
case V_60 :
V_29 = F_11 ( V_11 ) ;
break;
case V_61 :
V_29 = F_12 ( V_11 ) ;
break;
case V_62 :
V_29 = F_13 ( V_11 ) ;
break;
case V_63 :
V_29 = 1 ;
break;
case V_64 :
V_29 = F_14 ( V_11 ) ;
break;
case V_65 :
V_29 = 1 ;
break;
case V_66 :
V_29 = F_15 ( V_67 ) ;
break;
case V_68 :
V_29 = 1 ;
break;
case V_69 :
V_29 = 1 ;
break;
case V_70 :
V_29 = 1 ;
break;
case V_71 :
V_29 = F_16 () ;
break;
case V_72 :
V_29 = 1 ;
break;
case V_73 :
V_29 = 1 ;
break;
case V_74 :
V_29 = F_10 ( V_11 ) -> V_75 ;
if ( ! V_29 )
return - V_33 ;
break;
case V_76 :
V_29 = F_10 ( V_11 ) -> V_77 ;
if ( ! V_29 )
return - V_33 ;
break;
case V_78 :
V_29 = V_3 . V_79 &&
F_17 ( V_11 ) ;
break;
case V_80 :
V_29 = F_18 ( V_11 ) ;
break;
case V_81 :
V_29 = 1 ;
break;
default:
F_19 ( L_5 , V_28 -> V_28 ) ;
return - V_82 ;
}
if ( F_20 ( V_28 -> V_29 , & V_29 , sizeof( int ) ) ) {
F_21 ( L_6 ) ;
return - V_83 ;
}
return 0 ;
}
static int F_22 ( struct V_23 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_27 ;
V_6 -> V_84 = F_23 ( 0 , F_24 ( 0 , 0 ) ) ;
if ( ! V_6 -> V_84 ) {
F_21 ( L_7 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_25 ( struct V_23 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_27 ;
int V_85 = F_10 ( V_11 ) -> V_57 >= 4 ? V_86 : V_87 ;
T_3 V_88 , V_89 = 0 ;
T_4 V_90 ;
int V_91 ;
if ( F_10 ( V_11 ) -> V_57 >= 4 )
F_26 ( V_6 -> V_84 , V_85 + 4 , & V_89 ) ;
F_26 ( V_6 -> V_84 , V_85 , & V_88 ) ;
V_90 = ( ( T_4 ) V_89 << 32 ) | V_88 ;
#ifdef F_27
if ( V_90 &&
F_28 ( V_90 , V_90 + V_92 ) )
return 0 ;
#endif
V_6 -> V_93 . V_94 = L_8 ;
V_6 -> V_93 . V_95 = V_96 ;
V_91 = F_29 ( V_6 -> V_84 -> V_97 ,
& V_6 -> V_93 ,
V_92 , V_92 ,
V_98 ,
0 , V_99 ,
V_6 -> V_84 ) ;
if ( V_91 ) {
F_30 ( L_9 , V_91 ) ;
V_6 -> V_93 . V_100 = 0 ;
return V_91 ;
}
if ( F_10 ( V_11 ) -> V_57 >= 4 )
F_31 ( V_6 -> V_84 , V_85 + 4 ,
F_32 ( V_6 -> V_93 . V_100 ) ) ;
F_31 ( V_6 -> V_84 , V_85 ,
F_33 ( V_6 -> V_93 . V_100 ) ) ;
return 0 ;
}
static void
F_34 ( struct V_23 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_27 ;
int V_101 = F_10 ( V_11 ) -> V_57 >= 4 ? V_86 : V_87 ;
T_3 V_102 ;
bool V_103 ;
if ( F_35 ( V_11 ) || F_36 ( V_11 ) )
return;
V_6 -> V_104 = false ;
if ( F_37 ( V_11 ) || F_38 ( V_11 ) ) {
F_26 ( V_6 -> V_84 , V_105 , & V_102 ) ;
V_103 = ! ! ( V_102 & V_106 ) ;
} else {
F_26 ( V_6 -> V_84 , V_101 , & V_102 ) ;
V_103 = V_102 & 1 ;
}
if ( V_103 )
return;
if ( F_25 ( V_11 ) )
return;
V_6 -> V_104 = true ;
if ( F_37 ( V_11 ) || F_38 ( V_11 ) ) {
F_31 ( V_6 -> V_84 , V_105 ,
V_102 | V_106 ) ;
} else {
F_26 ( V_6 -> V_84 , V_101 , & V_102 ) ;
F_31 ( V_6 -> V_84 , V_101 , V_102 | 1 ) ;
}
}
static void
F_39 ( struct V_23 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_27 ;
int V_101 = F_10 ( V_11 ) -> V_57 >= 4 ? V_86 : V_87 ;
if ( V_6 -> V_104 ) {
if ( F_37 ( V_11 ) || F_38 ( V_11 ) ) {
T_3 V_107 ;
F_26 ( V_6 -> V_84 , V_105 ,
& V_107 ) ;
V_107 &= ~ V_106 ;
F_31 ( V_6 -> V_84 , V_105 ,
V_107 ) ;
} else {
T_3 V_108 ;
F_26 ( V_6 -> V_84 , V_101 ,
& V_108 ) ;
V_108 &= ~ 1 ;
F_31 ( V_6 -> V_84 , V_101 ,
V_108 ) ;
}
}
if ( V_6 -> V_93 . V_100 )
F_40 ( & V_6 -> V_93 ) ;
}
static unsigned int F_41 ( void * V_109 , bool V_110 )
{
struct V_23 * V_11 = V_109 ;
F_42 ( V_11 , V_110 ) ;
if ( V_110 )
return V_111 | V_112 |
V_113 | V_114 ;
else
return V_113 | V_114 ;
}
static void F_43 ( struct V_115 * V_35 , enum V_116 V_110 )
{
struct V_23 * V_11 = F_44 ( V_35 ) ;
T_5 V_117 = { . V_118 = V_119 } ;
if ( V_110 == V_120 ) {
F_45 ( L_10 ) ;
V_11 -> V_121 = V_122 ;
F_46 ( V_11 -> V_35 , V_123 ) ;
F_47 ( V_11 ) ;
V_11 -> V_121 = V_124 ;
} else {
F_45 ( L_11 ) ;
V_11 -> V_121 = V_122 ;
F_48 ( V_11 , V_117 ) ;
V_11 -> V_121 = V_125 ;
}
}
static bool F_49 ( struct V_115 * V_35 )
{
struct V_23 * V_11 = F_44 ( V_35 ) ;
return V_11 -> V_126 == 0 ;
}
static int F_50 ( struct V_23 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_27 ;
int V_91 ;
if ( F_51 () )
return - V_33 ;
V_91 = F_52 ( V_6 ) ;
if ( V_91 )
F_2 ( L_12 ) ;
V_91 = F_53 ( V_11 -> V_35 , V_11 , NULL , F_41 ) ;
if ( V_91 && V_91 != - V_33 )
goto V_127;
F_54 () ;
V_91 = F_55 ( V_11 -> V_35 , & V_128 , false ) ;
if ( V_91 )
goto V_129;
F_56 ( V_6 , false ) ;
F_57 ( V_6 ) ;
V_91 = F_58 ( V_6 ) ;
if ( V_91 )
goto V_130;
F_59 ( V_11 ) ;
F_60 ( V_11 ) ;
F_61 ( V_11 ) ;
V_91 = F_62 ( V_11 ) ;
if ( V_91 )
goto V_131;
F_63 ( V_11 ) ;
if ( F_10 ( V_11 ) -> V_132 == 0 )
return 0 ;
V_91 = F_64 ( V_11 ) ;
if ( V_91 )
goto V_133;
F_65 ( V_6 ) ;
F_66 ( V_11 ) ;
F_67 ( V_11 ) ;
return 0 ;
V_133:
F_68 ( & V_11 -> V_134 ) ;
F_69 ( V_11 ) ;
F_70 ( V_11 ) ;
F_71 ( & V_11 -> V_134 ) ;
V_131:
F_72 ( V_11 ) ;
F_73 ( V_11 ) ;
F_74 ( V_11 ) ;
V_130:
F_75 ( V_6 ) ;
F_76 ( V_6 ) ;
F_77 ( V_11 -> V_35 ) ;
V_129:
F_53 ( V_11 -> V_35 , NULL , NULL , NULL ) ;
V_127:
return V_91 ;
}
static int F_78 ( struct V_5 * V_6 )
{
struct V_135 * V_136 ;
struct V_115 * V_35 = V_6 -> V_11 -> V_35 ;
struct V_137 * V_138 = & V_6 -> V_138 ;
bool V_139 ;
int V_91 ;
V_136 = F_79 ( 1 ) ;
if ( ! V_136 )
return - V_140 ;
V_136 -> V_141 [ 0 ] . V_142 = V_138 -> V_143 ;
V_136 -> V_141 [ 0 ] . V_144 = V_138 -> V_145 ;
V_139 =
V_35 -> V_146 [ V_147 ] . V_95 & V_148 ;
V_91 = F_80 ( V_136 , L_13 , V_139 ) ;
F_81 ( V_136 ) ;
return V_91 ;
}
static int F_78 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_82 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_82 ( struct V_5 * V_6 )
{
return - V_33 ;
}
static int F_82 ( struct V_5 * V_6 )
{
int V_91 = 0 ;
F_2 ( L_14 ) ;
F_83 () ;
if ( F_84 ( & V_149 ) )
V_91 = F_85 ( & V_150 , 0 , V_151 - 1 , 1 ) ;
if ( V_91 == 0 ) {
V_91 = F_86 ( & V_149 ) ;
if ( V_91 == - V_33 )
V_91 = 0 ;
}
F_87 () ;
return V_91 ;
}
static void F_88 ( struct V_5 * V_6 )
{
const struct V_152 * V_153 = & V_6 -> V_153 ;
#define F_89 ( V_94 ) "%s"
#define F_90
#define F_91 ( V_94 ) info->name ? #name "," : ""
#define F_92 ,
F_30 ( L_15
F_93 ( F_89 , F_90 ) ,
V_153 -> V_57 ,
V_6 -> V_11 -> V_35 -> V_10 ,
V_6 -> V_11 -> V_35 -> V_37 ,
F_93 ( F_91 , F_92 ) ) ;
#undef F_89
#undef F_90
#undef F_91
#undef F_92
}
static void F_94 ( struct V_23 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_27 ;
struct V_152 * V_153 ;
T_3 V_154 , V_155 ;
V_153 = (struct V_152 * ) & V_6 -> V_153 ;
V_154 = F_95 ( V_156 ) ;
V_153 -> V_157 = 1 ;
if ( ! ( V_154 & V_158 ) ) {
V_153 -> V_159 ++ ;
V_155 = V_154 & ( V_160 |
V_161 ) ;
V_153 -> V_77 += 8 - F_96 ( V_155 ) ;
}
if ( ! ( V_154 & V_162 ) ) {
V_153 -> V_159 ++ ;
V_155 = V_154 & ( V_163 |
V_164 ) ;
V_153 -> V_77 += 8 - F_96 ( V_155 ) ;
}
V_153 -> V_75 = V_153 -> V_159 ;
V_153 -> V_165 = V_153 -> V_75 ?
V_153 -> V_77 / V_153 -> V_75 :
0 ;
V_153 -> V_166 = 0 ;
V_153 -> V_167 = ( V_153 -> V_75 > 1 ) ;
V_153 -> V_168 = ( V_153 -> V_165 > 2 ) ;
}
static void F_97 ( struct V_23 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_27 ;
struct V_152 * V_153 ;
int V_169 = 3 , V_170 = 4 , V_171 = 8 ;
int V_172 , V_173 ;
T_3 V_174 , V_175 , V_176 , V_177 ;
T_6 V_178 = 0xff ;
V_153 = (struct V_152 * ) & V_6 -> V_153 ;
V_174 = F_95 ( V_179 ) ;
V_175 = ( V_174 & V_180 ) >>
V_181 ;
V_176 = ( V_174 & V_182 ) >>
V_183 ;
V_153 -> V_157 = F_96 ( V_175 ) ;
V_153 -> V_159 = V_170 - F_96 ( V_176 ) ;
V_153 -> V_75 = V_153 -> V_157 *
V_153 -> V_159 ;
for ( V_172 = 0 ; V_172 < V_169 ; V_172 ++ ) {
if ( ! ( V_175 & ( 0x1 << V_172 ) ) )
continue;
V_177 = F_95 ( F_98 ( V_172 ) ) ;
for ( V_173 = 0 ; V_173 < V_170 ; V_173 ++ ) {
int V_184 ;
if ( V_176 & ( 0x1 << V_173 ) )
continue;
V_184 = V_171 - F_99 ( ( V_177 >> ( V_173 * 8 ) ) &
V_178 ) ;
if ( V_184 == 7 )
V_153 -> V_185 [ V_172 ] |= 1 << V_173 ;
V_153 -> V_77 += V_184 ;
}
}
V_153 -> V_165 = V_153 -> V_75 ?
F_100 ( V_153 -> V_77 ,
V_153 -> V_75 ) : 0 ;
V_153 -> V_166 = ( ( F_101 ( V_11 ) || F_102 ( V_11 ) ) &&
( V_153 -> V_157 > 1 ) ) ;
V_153 -> V_167 = ( F_103 ( V_11 ) && ( V_153 -> V_75 > 1 ) ) ;
V_153 -> V_168 = ( V_153 -> V_165 > 2 ) ;
}
static void F_104 ( struct V_23 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_27 ;
struct V_152 * V_153 ;
const int V_169 = 3 , V_170 = 3 , V_171 = 8 ;
int V_172 , V_173 ;
T_3 V_174 , V_177 [ V_169 ] , V_175 , V_176 ;
V_174 = F_95 ( V_179 ) ;
V_175 = ( V_174 & V_180 ) >> V_181 ;
V_176 = ( V_174 & V_186 ) >> V_187 ;
V_177 [ 0 ] = F_95 ( V_188 ) & V_189 ;
V_177 [ 1 ] = ( F_95 ( V_188 ) >> V_190 ) |
( ( F_95 ( V_191 ) & V_192 ) <<
( 32 - V_190 ) ) ;
V_177 [ 2 ] = ( F_95 ( V_191 ) >> V_193 ) |
( ( F_95 ( V_194 ) & V_195 ) <<
( 32 - V_193 ) ) ;
V_153 = (struct V_152 * ) & V_6 -> V_153 ;
V_153 -> V_157 = F_96 ( V_175 ) ;
V_153 -> V_159 = V_170 - F_96 ( V_176 ) ;
V_153 -> V_75 = V_153 -> V_157 * V_153 -> V_159 ;
for ( V_172 = 0 ; V_172 < V_169 ; V_172 ++ ) {
if ( ! ( V_175 & ( 0x1 << V_172 ) ) )
continue;
for ( V_173 = 0 ; V_173 < V_170 ; V_173 ++ ) {
T_3 V_196 ;
if ( V_176 & ( 0x1 << V_173 ) )
continue;
V_196 = F_99 ( V_177 [ V_172 ] >> ( V_173 * V_171 ) ) ;
if ( V_171 - V_196 == 7 )
V_153 -> V_185 [ V_172 ] |= 1 << V_173 ;
V_153 -> V_77 += V_171 - V_196 ;
}
}
V_153 -> V_165 = V_153 -> V_75 ?
F_100 ( V_153 -> V_77 , V_153 -> V_75 ) : 0 ;
V_153 -> V_166 = ( V_153 -> V_157 > 1 ) ;
V_153 -> V_167 = 0 ;
V_153 -> V_168 = 0 ;
}
static void F_105 ( struct V_23 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_27 ;
struct V_152 * V_153 ;
enum V_197 V_197 ;
V_153 = (struct V_152 * ) & V_6 -> V_153 ;
if ( F_103 ( V_11 ) ) {
V_153 -> V_198 [ V_199 ] = 2 ;
V_153 -> V_198 [ V_200 ] = 2 ;
V_153 -> V_198 [ V_201 ] = 1 ;
} else if ( F_35 ( V_11 ) || F_36 ( V_11 ) )
F_106 (dev_priv, pipe)
V_153 -> V_198 [ V_197 ] = 2 ;
else
F_106 (dev_priv, pipe)
V_153 -> V_198 [ V_197 ] = 1 ;
if ( V_3 . V_202 ) {
F_2 ( L_16 ) ;
V_153 -> V_132 = 0 ;
} else if ( V_153 -> V_132 > 0 &&
( F_10 ( V_11 ) -> V_57 == 7 || F_10 ( V_11 ) -> V_57 == 8 ) &&
F_107 ( V_11 ) ) {
T_3 V_203 = F_95 ( V_204 ) ;
T_3 V_205 = F_95 ( V_206 ) ;
if ( V_203 & V_207 ||
V_205 & V_208 ||
( V_6 -> V_209 == V_210 &&
! ( V_205 & V_211 ) ) ) {
F_2 ( L_17 ) ;
V_153 -> V_132 = 0 ;
} else if ( V_203 & V_212 ) {
F_2 ( L_18 ) ;
V_153 -> V_132 -= 1 ;
}
} else if ( V_153 -> V_132 > 0 && F_10 ( V_11 ) -> V_57 == 9 ) {
T_3 V_213 = F_95 ( V_214 ) ;
T_6 V_215 = 0 ;
bool V_216 ;
int V_217 ;
if ( V_213 & V_218 )
V_215 |= F_108 ( V_199 ) ;
if ( V_213 & V_219 )
V_215 |= F_108 ( V_200 ) ;
if ( V_213 & V_220 )
V_215 |= F_108 ( V_201 ) ;
V_217 = F_99 ( V_215 ) ;
switch ( V_215 ) {
case F_108 ( V_199 ) :
case F_108 ( V_200 ) :
case F_108 ( V_199 ) | F_108 ( V_200 ) :
case F_108 ( V_199 ) | F_108 ( V_201 ) :
V_216 = true ;
break;
default:
V_216 = false ;
}
if ( V_217 > V_153 -> V_132 || V_216 )
F_21 ( L_19 ,
V_215 ) ;
else
V_153 -> V_132 -= V_217 ;
}
if ( F_36 ( V_11 ) )
F_94 ( V_11 ) ;
else if ( F_109 ( V_11 ) )
F_104 ( V_11 ) ;
else if ( F_10 ( V_11 ) -> V_57 >= 9 )
F_97 ( V_11 ) ;
V_153 -> V_221 = ! V_153 -> V_222 ;
V_153 -> V_221 &= ! F_110 ( V_11 , 0 , V_223 ) ;
F_30 ( L_20 , V_153 -> V_157 ) ;
F_30 ( L_21 , V_153 -> V_75 ) ;
F_30 ( L_22 , V_153 -> V_159 ) ;
F_30 ( L_23 , V_153 -> V_77 ) ;
F_30 ( L_24 , V_153 -> V_165 ) ;
F_30 ( L_25 ,
V_153 -> V_166 ? L_26 : L_27 ) ;
F_30 ( L_28 ,
V_153 -> V_167 ? L_26 : L_27 ) ;
F_30 ( L_29 ,
V_153 -> V_168 ? L_26 : L_27 ) ;
}
static void F_111 ( struct V_5 * V_6 )
{
if ( F_36 ( V_6 ) ) {
F_112 ( V_224 ) = V_225 ;
F_112 ( V_226 ) = V_227 ;
} else if ( F_35 ( V_6 ) ) {
F_112 ( V_224 ) = V_227 ;
}
}
static int F_113 ( struct V_5 * V_6 )
{
V_6 -> V_228 = F_114 ( L_30 , 0 ) ;
if ( V_6 -> V_228 == NULL )
goto V_229;
V_6 -> V_230 . V_231 = F_114 ( L_31 , 0 ) ;
if ( V_6 -> V_230 . V_231 == NULL )
goto V_232;
V_6 -> V_233 . V_234 =
F_114 ( L_32 , 0 ) ;
if ( V_6 -> V_233 . V_234 == NULL )
goto V_235;
return 0 ;
V_235:
F_115 ( V_6 -> V_230 . V_231 ) ;
V_232:
F_115 ( V_6 -> V_228 ) ;
V_229:
F_21 ( L_33 ) ;
return - V_140 ;
}
static void F_116 ( struct V_5 * V_6 )
{
F_115 ( V_6 -> V_233 . V_234 ) ;
F_115 ( V_6 -> V_230 . V_231 ) ;
F_115 ( V_6 -> V_228 ) ;
}
static int F_117 ( struct V_5 * V_6 ,
struct V_23 * V_11 ,
struct V_152 * V_153 )
{
struct V_152 * V_236 ;
int V_91 = 0 ;
if ( F_51 () )
return - V_33 ;
V_236 = (struct V_152 * ) & V_6 -> V_153 ;
memcpy ( V_236 , V_153 , sizeof( V_6 -> V_153 ) ) ;
V_236 -> V_237 = V_11 -> V_35 -> V_10 ;
F_118 ( & V_6 -> V_238 ) ;
F_118 ( & V_6 -> V_233 . V_239 ) ;
F_119 ( & V_6 -> V_240 ) ;
F_118 ( & V_6 -> V_241 . V_239 ) ;
F_118 ( & V_6 -> V_242 . V_243 ) ;
F_118 ( & V_6 -> V_244 ) ;
F_119 ( & V_6 -> V_245 ) ;
F_119 ( & V_6 -> V_246 ) ;
F_119 ( & V_6 -> V_247 ) ;
F_119 ( & V_6 -> V_248 . V_249 ) ;
F_119 ( & V_6 -> V_250 ) ;
V_91 = F_113 ( V_6 ) ;
if ( V_91 < 0 )
return V_91 ;
F_120 ( V_11 ) ;
F_121 ( V_11 ) ;
F_111 ( V_6 ) ;
F_122 ( V_6 ) ;
F_123 ( V_6 ) ;
F_124 ( V_6 ) ;
F_125 ( V_6 ) ;
F_126 ( V_6 ) ;
F_127 ( V_11 ) ;
F_128 ( V_11 ) ;
F_88 ( V_6 ) ;
if ( F_129 ( V_11 ) )
F_2 ( L_34
L_35 ) ;
return 0 ;
}
static void F_130 ( struct V_5 * V_6 )
{
F_131 ( V_6 -> V_11 ) ;
F_116 ( V_6 ) ;
}
static int F_132 ( struct V_23 * V_11 )
{
struct V_5 * V_6 = F_133 ( V_11 ) ;
int V_251 ;
int V_252 ;
V_251 = F_134 ( V_11 ) ? 1 : 0 ;
if ( F_10 ( V_11 ) -> V_57 < 5 )
V_252 = 512 * 1024 ;
else
V_252 = 2 * 1024 * 1024 ;
V_6 -> V_253 = F_135 ( V_11 -> V_35 , V_251 , V_252 ) ;
if ( V_6 -> V_253 == NULL ) {
F_21 ( L_36 ) ;
return - V_254 ;
}
F_34 ( V_11 ) ;
return 0 ;
}
static void F_136 ( struct V_23 * V_11 )
{
struct V_5 * V_6 = F_133 ( V_11 ) ;
F_39 ( V_11 ) ;
F_137 ( V_11 -> V_35 , V_6 -> V_253 ) ;
}
static int F_138 ( struct V_5 * V_6 )
{
struct V_23 * V_11 = V_6 -> V_11 ;
int V_91 ;
if ( F_51 () )
return - V_33 ;
if ( F_22 ( V_11 ) )
return - V_254 ;
V_91 = F_132 ( V_11 ) ;
if ( V_91 < 0 )
goto V_255;
F_139 ( V_11 ) ;
return 0 ;
V_255:
F_140 ( V_6 -> V_84 ) ;
return V_91 ;
}
static void F_141 ( struct V_5 * V_6 )
{
struct V_23 * V_11 = V_6 -> V_11 ;
F_142 ( V_11 ) ;
F_136 ( V_11 ) ;
F_140 ( V_6 -> V_84 ) ;
}
static int F_143 ( struct V_5 * V_6 )
{
struct V_23 * V_11 = V_6 -> V_11 ;
struct V_137 * V_138 = & V_6 -> V_138 ;
T_7 V_256 ;
int V_91 ;
if ( F_51 () )
return - V_33 ;
F_105 ( V_11 ) ;
V_91 = F_144 ( V_11 ) ;
if ( V_91 )
return V_91 ;
V_91 = F_145 ( V_11 ) ;
if ( V_91 ) {
F_21 ( L_37 ) ;
goto V_257;
}
V_91 = F_78 ( V_6 ) ;
if ( V_91 ) {
F_21 ( L_38 ) ;
goto V_257;
}
V_91 = F_82 ( V_6 ) ;
if ( V_91 ) {
F_21 ( L_39 ) ;
goto V_257;
}
F_146 ( V_11 -> V_35 ) ;
if ( F_134 ( V_11 ) )
F_147 ( & V_11 -> V_35 -> V_11 , F_148 ( 30 ) ) ;
if ( F_149 ( V_11 ) || F_150 ( V_11 ) )
F_147 ( & V_11 -> V_35 -> V_11 , F_148 ( 32 ) ) ;
V_256 = V_138 -> V_145 ;
V_138 -> V_258 =
F_151 ( V_138 -> V_143 ,
V_256 ) ;
if ( ! V_138 -> V_258 ) {
V_91 = - V_254 ;
goto V_257;
}
V_138 -> V_259 = F_152 ( V_138 -> V_143 ,
V_256 ) ;
F_153 ( & V_6 -> V_260 , V_261 ,
V_262 ) ;
F_154 ( V_11 ) ;
F_155 ( V_11 ) ;
F_156 ( V_6 ) ;
if ( ! F_157 ( V_11 ) && ! F_158 ( V_11 ) ) {
if ( F_159 ( V_11 -> V_35 ) < 0 )
F_30 ( L_40 ) ;
}
return 0 ;
V_257:
F_160 ( V_11 ) ;
return V_91 ;
}
static void F_161 ( struct V_5 * V_6 )
{
struct V_23 * V_11 = V_6 -> V_11 ;
struct V_137 * V_138 = & V_6 -> V_138 ;
if ( V_11 -> V_35 -> V_263 )
F_162 ( V_11 -> V_35 ) ;
F_163 ( & V_6 -> V_260 ) ;
F_164 ( V_138 -> V_259 ) ;
F_165 ( V_138 -> V_258 ) ;
F_160 ( V_11 ) ;
}
static void F_166 ( struct V_5 * V_6 )
{
struct V_23 * V_11 = V_6 -> V_11 ;
F_167 ( V_6 ) ;
if ( F_168 ( V_11 ) )
F_169 ( F_170 ( V_264 ) , V_265 ) ;
F_171 ( V_11 ) ;
if ( F_10 ( V_6 ) -> V_132 ) {
F_172 ( V_11 ) ;
F_173 () ;
}
if ( F_174 ( V_6 ) )
F_175 ( V_6 ) ;
F_176 ( V_6 ) ;
}
static void F_177 ( struct V_5 * V_6 )
{
F_178 ( V_6 ) ;
F_179 () ;
F_180 () ;
F_181 ( V_6 -> V_11 ) ;
F_182 ( V_6 -> V_11 ) ;
F_183 ( V_6 ) ;
}
int F_184 ( struct V_23 * V_11 , unsigned long V_95 )
{
struct V_5 * V_6 ;
int V_91 = 0 ;
V_6 = F_185 ( sizeof( * V_6 ) , V_266 ) ;
if ( V_6 == NULL )
return - V_140 ;
V_11 -> V_27 = V_6 ;
V_6 -> V_11 = V_11 ;
V_91 = F_117 ( V_6 , V_11 ,
(struct V_152 * ) V_95 ) ;
if ( V_91 < 0 )
goto V_267;
F_186 ( V_6 ) ;
V_91 = F_138 ( V_6 ) ;
if ( V_91 < 0 )
goto V_268;
V_91 = F_143 ( V_6 ) ;
if ( V_91 < 0 )
goto V_269;
if ( F_10 ( V_11 ) -> V_132 ) {
V_91 = F_187 ( V_11 , F_10 ( V_11 ) -> V_132 ) ;
if ( V_91 )
goto V_270;
}
V_91 = F_50 ( V_11 ) ;
if ( V_91 < 0 )
goto V_271;
F_166 ( V_6 ) ;
F_188 ( V_6 ) ;
F_189 ( V_6 ) ;
return 0 ;
V_271:
F_190 ( V_11 ) ;
V_270:
F_161 ( V_6 ) ;
V_269:
F_141 ( V_6 ) ;
V_268:
F_189 ( V_6 ) ;
F_130 ( V_6 ) ;
V_267:
F_191 ( V_6 , L_41 , V_91 ) ;
F_81 ( V_6 ) ;
return V_91 ;
}
int F_192 ( struct V_23 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_27 ;
int V_91 ;
F_193 ( V_11 ) ;
V_91 = F_194 ( V_11 ) ;
if ( V_91 ) {
F_21 ( L_42 , V_91 ) ;
return V_91 ;
}
F_195 ( V_6 , V_272 ) ;
F_177 ( V_6 ) ;
F_190 ( V_11 ) ;
F_196 ( V_11 ) ;
if ( V_6 -> V_273 . V_274 && V_6 -> V_273 . V_275 ) {
F_81 ( V_6 -> V_273 . V_274 ) ;
V_6 -> V_273 . V_274 = NULL ;
V_6 -> V_273 . V_275 = 0 ;
}
F_81 ( V_6 -> V_273 . V_276 ) ;
V_6 -> V_273 . V_276 = NULL ;
F_81 ( V_6 -> V_273 . V_277 ) ;
V_6 -> V_273 . V_277 = NULL ;
F_77 ( V_11 -> V_35 ) ;
F_53 ( V_11 -> V_35 , NULL , NULL , NULL ) ;
F_75 ( V_6 ) ;
F_197 ( & V_6 -> V_233 . V_278 ) ;
F_198 ( V_11 ) ;
F_199 ( V_6 -> V_228 ) ;
F_72 ( V_11 ) ;
F_68 ( & V_11 -> V_134 ) ;
F_69 ( V_11 ) ;
F_70 ( V_11 ) ;
F_71 ( & V_11 -> V_134 ) ;
F_200 ( V_6 ) ;
F_76 ( V_6 ) ;
F_161 ( V_6 ) ;
F_141 ( V_6 ) ;
F_201 ( V_6 , V_272 ) ;
F_130 ( V_6 ) ;
F_81 ( V_6 ) ;
return 0 ;
}
int F_202 ( struct V_23 * V_11 , struct V_25 * V_279 )
{
int V_91 ;
V_91 = F_203 ( V_11 , V_279 ) ;
if ( V_91 )
return V_91 ;
return 0 ;
}
void F_204 ( struct V_23 * V_11 )
{
F_205 ( V_11 ) ;
F_206 () ;
}
void F_207 ( struct V_23 * V_11 , struct V_25 * V_279 )
{
F_68 ( & V_11 -> V_134 ) ;
F_208 ( V_11 , V_279 ) ;
F_209 ( V_11 , V_279 ) ;
F_71 ( & V_11 -> V_134 ) ;
}
void F_210 ( struct V_23 * V_11 , struct V_25 * V_279 )
{
struct V_280 * V_26 = V_279 -> V_281 ;
F_81 ( V_26 ) ;
}
static int
F_211 ( struct V_23 * V_11 , void * V_24 ,
struct V_25 * V_279 )
{
return - V_33 ;
}
