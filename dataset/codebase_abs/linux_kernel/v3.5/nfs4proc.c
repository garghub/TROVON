static int F_1 ( int V_1 )
{
if ( V_1 >= - 1000 )
return V_1 ;
switch ( V_1 ) {
case - V_2 :
return - V_3 ;
case - V_4 :
return - V_5 ;
case - V_6 :
case - V_7 :
return - V_8 ;
case - V_9 :
return - V_10 ;
case - V_11 :
return - V_12 ;
default:
F_2 ( L_1 ,
V_13 , - V_1 ) ;
break;
}
return - V_14 ;
}
static void F_3 ( T_1 V_15 , T_2 * V_16 , struct V_17 * V_17 ,
struct V_18 * V_19 )
{
T_2 * V_20 , * V_21 ;
F_4 ( V_19 -> V_22 < 80 ) ;
if ( V_15 > 2 ) {
V_19 -> V_15 = V_15 ;
memcpy ( & V_19 -> V_16 , V_16 , sizeof( V_19 -> V_16 ) ) ;
return;
}
V_19 -> V_15 = 0 ;
memset ( & V_19 -> V_16 , 0 , sizeof( V_19 -> V_16 ) ) ;
if ( V_15 == 2 )
return;
V_20 = V_21 = F_5 ( * V_19 -> V_23 ) ;
if ( V_15 == 0 ) {
* V_21 ++ = V_24 ;
* V_21 ++ = V_25 ;
* V_21 ++ = V_24 ;
* V_21 ++ = V_24 ;
memcpy ( V_21 , L_2 , 4 ) ;
V_21 ++ ;
* V_21 ++ = V_24 ;
* V_21 ++ = F_6 ( V_26 ) ;
* V_21 ++ = F_6 ( 8 ) ;
V_21 = F_7 ( V_21 , F_8 ( V_17 -> V_27 ) ) ;
}
* V_21 ++ = V_24 ;
* V_21 ++ = V_25 ;
* V_21 ++ = V_28 ;
* V_21 ++ = V_28 ;
memcpy ( V_21 , L_3 , 4 ) ;
V_21 ++ ;
* V_21 ++ = V_24 ;
* V_21 ++ = F_6 ( V_26 ) ;
* V_21 ++ = F_6 ( 8 ) ;
V_21 = F_7 ( V_21 , F_8 ( V_17 -> V_29 -> V_27 ) ) ;
V_19 -> V_30 = ( char * ) V_21 - ( char * ) V_20 ;
V_19 -> V_22 -= V_19 -> V_30 ;
F_9 ( V_20 ) ;
}
static int F_10 ( struct V_31 * V_32 )
{
int V_33 ;
F_11 () ;
V_33 = F_12 ( & V_32 -> V_34 , V_35 ,
V_36 , V_37 ) ;
return V_33 ;
}
static int F_13 ( struct V_38 * V_39 , long * V_40 )
{
int V_33 = 0 ;
F_11 () ;
if ( * V_40 <= 0 )
* V_40 = V_41 ;
if ( * V_40 > V_42 )
* V_40 = V_42 ;
F_14 ( * V_40 ) ;
if ( F_15 ( V_43 ) )
V_33 = - V_44 ;
* V_40 <<= 1 ;
return V_33 ;
}
static int F_16 ( struct V_45 * V_46 , int V_47 , struct V_48 * V_49 )
{
struct V_31 * V_32 = V_46 -> V_31 ;
struct V_50 * V_51 = V_49 -> V_51 ;
struct V_52 * V_52 = V_49 -> V_52 ;
int V_53 = V_47 ;
V_49 -> V_54 = 0 ;
switch( V_47 ) {
case 0 :
return 0 ;
case - V_55 :
if ( V_52 && F_17 ( V_52 , V_56 ) ) {
F_18 ( V_52 ) ;
V_49 -> V_54 = 1 ;
return 0 ;
}
if ( V_51 == NULL )
break;
F_19 ( V_46 , V_51 ) ;
goto V_57;
case - V_58 :
case - V_59 :
case - V_60 :
if ( V_51 == NULL )
break;
F_20 ( V_51 -> V_52 ) ;
F_19 ( V_46 , V_51 ) ;
goto V_57;
case - V_61 :
if ( V_51 != NULL )
F_19 ( V_46 , V_51 ) ;
case - V_62 :
case - V_63 :
F_21 ( V_32 ) ;
goto V_57;
#if F_22 ( V_64 )
case - V_65 :
case - V_66 :
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
case - V_71 :
F_2 ( L_4 , V_13 ,
V_47 ) ;
F_23 ( V_32 -> V_72 , V_47 ) ;
V_49 -> V_54 = 1 ;
break;
#endif
case - V_73 :
if ( V_49 -> V_40 > V_74 ) {
V_53 = - V_75 ;
break;
}
case - V_76 :
case - V_77 :
case - V_78 :
V_53 = F_13 ( V_46 -> V_79 , & V_49 -> V_40 ) ;
if ( V_53 != 0 )
break;
case - V_80 :
case - V_81 :
V_49 -> V_54 = 1 ;
break;
case - V_6 :
case - V_7 :
if ( V_46 -> V_82 & V_83 ) {
V_46 -> V_82 &= ~ V_83 ;
V_49 -> V_54 = 1 ;
F_24 ( V_84 L_5
L_6
L_7
L_8 ,
V_46 -> V_31 -> V_85 ) ;
}
}
return F_1 ( V_53 ) ;
V_57:
V_53 = F_10 ( V_32 ) ;
if ( V_53 == 0 )
V_49 -> V_54 = 1 ;
return V_53 ;
}
static void F_25 ( struct V_31 * V_32 , unsigned long V_86 )
{
F_26 ( & V_32 -> V_87 ) ;
if ( F_27 ( V_32 -> V_88 , V_86 ) )
V_32 -> V_88 = V_86 ;
F_28 ( & V_32 -> V_87 ) ;
}
static void F_29 ( const struct V_45 * V_46 , unsigned long V_86 )
{
F_25 ( V_46 -> V_31 , V_86 ) ;
}
static void
F_30 ( struct V_89 * V_90 , T_3 V_91 )
{
F_4 ( V_91 >= V_92 ) ;
F_31 ( V_91 , V_90 -> V_93 ) ;
if ( V_91 == V_90 -> V_94 ) {
V_91 = F_32 ( V_90 -> V_93 , V_90 -> V_95 ) ;
if ( V_91 < V_90 -> V_95 )
V_90 -> V_94 = V_91 ;
else
V_90 -> V_94 = V_96 ;
}
F_2 ( L_9 , V_13 ,
V_91 , V_90 -> V_94 ) ;
}
bool F_33 ( struct V_97 * V_98 , void * V_99 )
{
F_34 ( V_98 , V_100 ) ;
return true ;
}
static void F_35 ( struct V_101 * V_102 )
{
if ( ! F_36 ( V_103 , & V_102 -> V_104 ) ) {
F_37 ( & V_102 -> V_105 . V_106 ,
F_33 , NULL ) ;
return;
}
if ( V_102 -> V_105 . V_94 != V_96 )
return;
F_2 ( L_10 , V_13 ) ;
F_38 ( & V_102 -> V_105 . F_38 ) ;
}
void F_39 ( struct V_101 * V_102 )
{
if ( ! F_36 ( V_103 , & V_102 -> V_104 ) ||
V_102 -> V_107 . V_94 != V_96 )
return;
F_2 ( L_11 , V_13 ) ;
F_38 ( & V_102 -> V_107 . F_38 ) ;
}
static void F_40 ( struct V_108 * V_33 )
{
struct V_89 * V_90 ;
V_90 = & V_33 -> V_109 -> V_105 ;
if ( ! V_33 -> V_110 ) {
F_2 ( L_12 , V_13 ) ;
return;
}
F_26 ( & V_90 -> V_111 ) ;
F_30 ( V_90 , V_33 -> V_110 - V_90 -> V_112 ) ;
F_35 ( V_33 -> V_109 ) ;
F_28 ( & V_90 -> V_111 ) ;
V_33 -> V_110 = NULL ;
}
static int F_41 ( struct V_97 * V_98 , struct V_108 * V_33 )
{
unsigned long V_86 ;
struct V_31 * V_32 ;
if ( V_33 -> V_113 == 1 )
V_33 -> V_113 = V_114 ;
if ( ! F_42 ( V_98 ) )
goto V_115;
switch ( V_33 -> V_113 ) {
case 0 :
++ V_33 -> V_110 -> V_116 ;
V_86 = V_33 -> V_117 ;
V_32 = V_33 -> V_109 -> V_32 ;
F_25 ( V_32 , V_86 ) ;
if ( V_33 -> V_118 != 0 )
F_21 ( V_32 ) ;
break;
case - V_77 :
F_2 ( L_13 ,
V_13 ,
V_33 -> V_110 - V_33 -> V_109 -> V_105 . V_112 ,
V_33 -> V_110 -> V_116 ) ;
goto V_119;
default:
++ V_33 -> V_110 -> V_116 ;
}
V_115:
F_2 ( L_14 , V_13 , V_33 -> V_113 ) ;
F_40 ( V_33 ) ;
return 1 ;
V_119:
if ( ! F_43 ( V_98 ) )
goto V_115;
F_44 ( V_98 , V_42 ) ;
return 0 ;
}
static int F_45 ( struct V_97 * V_98 ,
struct V_108 * V_33 )
{
if ( V_33 -> V_109 == NULL )
return 1 ;
return F_41 ( V_98 , V_33 ) ;
}
static T_3
F_46 ( struct V_89 * V_90 )
{
T_3 V_91 ;
T_3 V_120 = V_96 ;
F_2 ( L_15 ,
V_13 , V_90 -> V_93 [ 0 ] , V_90 -> V_94 ,
V_90 -> V_95 ) ;
V_91 = F_47 ( V_90 -> V_93 , V_90 -> V_95 ) ;
if ( V_91 >= V_90 -> V_95 )
goto V_115;
F_48 ( V_91 , V_90 -> V_93 ) ;
if ( V_91 > V_90 -> V_94 ||
V_90 -> V_94 == V_96 )
V_90 -> V_94 = V_91 ;
V_120 = V_91 ;
V_115:
F_2 ( L_16 ,
V_13 , V_90 -> V_93 [ 0 ] , V_90 -> V_94 , V_120 ) ;
return V_120 ;
}
static void F_49 ( struct V_121 * args ,
struct V_108 * V_33 , int V_122 )
{
args -> V_123 = NULL ;
args -> V_124 = 0 ;
if ( V_122 )
args -> V_124 = 1 ;
V_33 -> V_109 = NULL ;
V_33 -> V_110 = NULL ;
}
int F_50 ( struct V_101 * V_125 ,
struct V_121 * args ,
struct V_108 * V_33 ,
struct V_97 * V_98 )
{
struct V_126 * V_127 ;
struct V_89 * V_90 ;
T_3 V_91 ;
F_2 ( L_17 , V_13 ) ;
if ( V_33 -> V_110 != NULL )
return 0 ;
V_90 = & V_125 -> V_105 ;
F_26 ( & V_90 -> V_111 ) ;
if ( F_36 ( V_103 , & V_125 -> V_104 ) &&
! F_51 ( V_98 , V_100 ) ) {
F_52 ( & V_90 -> V_106 , V_98 , NULL ) ;
F_28 ( & V_90 -> V_111 ) ;
F_2 ( L_18 , V_13 ) ;
return - V_128 ;
}
if ( ! F_53 ( & V_90 -> V_106 ) &&
! F_51 ( V_98 , V_100 ) ) {
F_52 ( & V_90 -> V_106 , V_98 , NULL ) ;
F_28 ( & V_90 -> V_111 ) ;
F_2 ( L_19 , V_13 ) ;
return - V_128 ;
}
V_91 = F_46 ( V_90 ) ;
if ( V_91 == V_96 ) {
F_52 ( & V_90 -> V_106 , V_98 , NULL ) ;
F_28 ( & V_90 -> V_111 ) ;
F_2 ( L_20 , V_13 ) ;
return - V_128 ;
}
F_28 ( & V_90 -> V_111 ) ;
F_34 ( V_98 , V_129 ) ;
V_127 = V_90 -> V_112 + V_91 ;
args -> V_123 = V_125 ;
args -> V_130 = V_91 ;
F_2 ( L_21 , V_13 , V_91 , V_127 -> V_116 ) ;
V_33 -> V_109 = V_125 ;
V_33 -> V_110 = V_127 ;
V_33 -> V_117 = V_131 ;
V_33 -> V_118 = 0 ;
V_33 -> V_113 = 1 ;
return 0 ;
}
int F_54 ( const struct V_45 * V_46 ,
struct V_121 * args ,
struct V_108 * V_33 ,
struct V_97 * V_98 )
{
struct V_101 * V_125 = F_55 ( V_46 ) ;
int V_53 = 0 ;
if ( V_125 == NULL )
goto V_115;
F_2 ( L_22 ,
V_13 , V_125 -> V_32 , V_125 , V_33 -> V_110 ?
V_33 -> V_110 - V_125 -> V_105 . V_112 : - 1 ) ;
V_53 = F_50 ( V_125 , args , V_33 , V_98 ) ;
V_115:
F_2 ( L_23 , V_13 , V_53 ) ;
return V_53 ;
}
static void F_56 ( struct V_97 * V_98 , void * V_132 )
{
struct V_133 * V_134 = V_132 ;
F_2 ( L_24 , V_13 , V_134 -> V_135 ) ;
if ( F_54 ( V_134 -> V_135 , V_134 -> V_136 ,
V_134 -> V_137 , V_98 ) )
return;
F_57 ( V_98 ) ;
}
static void F_58 ( struct V_97 * V_98 , void * V_132 )
{
F_34 ( V_98 , V_100 ) ;
F_56 ( V_98 , V_132 ) ;
}
static void F_59 ( struct V_97 * V_98 , void * V_132 )
{
struct V_133 * V_134 = V_132 ;
F_41 ( V_98 , V_134 -> V_137 ) ;
}
static int F_60 ( struct V_38 * V_39 ,
struct V_45 * V_46 ,
struct V_138 * V_139 ,
struct V_121 * args ,
struct V_108 * V_33 ,
int V_140 )
{
int V_53 ;
struct V_97 * V_98 ;
struct V_133 V_134 = {
. V_135 = V_46 ,
. V_136 = args ,
. V_137 = V_33 ,
} ;
struct V_141 V_142 = {
. V_143 = V_39 ,
. V_138 = V_139 ,
. V_144 = & V_145 ,
. V_146 = & V_134
} ;
if ( V_140 )
V_142 . V_144 = & V_147 ;
V_98 = F_61 ( & V_142 ) ;
if ( F_62 ( V_98 ) )
V_53 = F_63 ( V_98 ) ;
else {
V_53 = V_98 -> V_148 ;
F_64 ( V_98 ) ;
}
return V_53 ;
}
int F_65 ( struct V_38 * V_39 ,
struct V_45 * V_46 ,
struct V_138 * V_139 ,
struct V_121 * args ,
struct V_108 * V_33 ,
int V_122 )
{
F_49 ( args , V_33 , V_122 ) ;
return F_60 ( V_39 , V_46 , V_139 , args , V_33 , 0 ) ;
}
static inline
void F_49 ( struct V_121 * args ,
struct V_108 * V_33 , int V_122 )
{
}
static int F_45 ( struct V_97 * V_98 ,
struct V_108 * V_33 )
{
return 1 ;
}
int F_66 ( struct V_38 * V_39 ,
struct V_45 * V_46 ,
struct V_138 * V_139 ,
struct V_121 * args ,
struct V_108 * V_33 ,
int V_122 )
{
F_49 ( args , V_33 , V_122 ) ;
return F_67 ( V_39 , V_139 , 0 ) ;
}
static inline
int F_68 ( struct V_38 * V_39 ,
struct V_45 * V_46 ,
struct V_138 * V_139 ,
struct V_121 * args ,
struct V_108 * V_33 ,
int V_122 )
{
return V_46 -> V_31 -> V_149 -> V_150 ( V_39 , V_46 , V_139 ,
args , V_33 , V_122 ) ;
}
static void F_69 ( struct V_52 * V_151 , struct V_152 * V_153 )
{
struct V_154 * V_155 = F_70 ( V_151 ) ;
F_26 ( & V_151 -> V_156 ) ;
V_155 -> V_157 |= V_158 | V_159 ;
if ( ! V_153 -> V_160 || V_153 -> V_161 != V_151 -> V_162 )
F_71 ( V_151 ) ;
V_151 -> V_162 = V_153 -> V_163 ;
F_28 ( & V_151 -> V_156 ) ;
}
static void F_72 ( struct V_164 * V_21 )
{
V_21 -> V_165 . V_166 = & V_21 -> V_166 ;
V_21 -> V_165 . V_167 = V_21 -> V_168 . V_167 ;
V_21 -> V_169 . V_167 = V_21 -> V_170 . V_167 ;
V_21 -> V_165 . V_46 = V_21 -> V_168 . V_46 ;
F_73 ( & V_21 -> V_166 ) ;
F_74 ( & V_21 -> V_166 , & V_21 -> V_171 , & V_21 -> V_172 ) ;
}
static struct V_164 * F_75 ( struct V_17 * V_17 ,
struct V_173 * V_174 , T_4 V_175 , int V_176 ,
const struct V_177 * V_178 ,
T_5 V_179 )
{
struct V_17 * V_180 = F_76 ( V_17 ) ;
struct V_52 * V_151 = V_180 -> V_27 ;
struct V_45 * V_46 = F_77 ( V_151 ) ;
struct V_164 * V_21 ;
V_21 = F_78 ( sizeof( * V_21 ) , V_179 ) ;
if ( V_21 == NULL )
goto V_1;
V_21 -> V_168 . V_167 = F_79 ( & V_174 -> V_181 , V_179 ) ;
if ( V_21 -> V_168 . V_167 == NULL )
goto V_182;
F_80 ( V_17 -> V_183 ) ;
V_21 -> V_17 = F_81 ( V_17 ) ;
V_21 -> V_151 = V_180 ;
V_21 -> V_184 = V_174 ;
F_82 ( & V_174 -> V_185 ) ;
V_21 -> V_168 . V_186 = F_83 ( V_151 ) ;
V_21 -> V_168 . V_187 = V_176 ;
V_21 -> V_168 . V_175 = V_175 & ( V_56 | V_188 ) ;
V_21 -> V_168 . V_189 = V_46 -> V_31 -> V_190 ;
V_21 -> V_168 . V_191 . V_192 = F_84 ( V_174 -> V_181 . V_192 ) ;
V_21 -> V_168 . V_191 . V_193 = V_174 -> V_181 . V_194 ;
V_21 -> V_168 . V_195 = & V_17 -> V_196 ;
V_21 -> V_168 . V_46 = V_46 ;
V_21 -> V_168 . V_197 = V_46 -> V_198 ;
V_21 -> V_168 . V_199 = & V_200 [ 0 ] ;
V_21 -> V_168 . V_201 = V_202 ;
if ( V_178 != NULL && V_178 -> V_203 != 0 ) {
T_2 V_204 [ 2 ] ;
V_21 -> V_168 . V_205 . V_178 = & V_21 -> V_178 ;
memcpy ( & V_21 -> V_178 , V_178 , sizeof( V_21 -> V_178 ) ) ;
V_204 [ 0 ] = V_131 ;
V_204 [ 1 ] = V_43 -> V_206 ;
memcpy ( V_21 -> V_168 . V_205 . V_16 . V_134 , V_204 ,
sizeof( V_21 -> V_168 . V_205 . V_16 . V_134 ) ) ;
}
V_21 -> V_170 . V_186 = & V_21 -> V_165 . V_186 ;
V_21 -> V_170 . V_207 = & V_21 -> V_165 . V_207 ;
V_21 -> V_170 . V_167 = V_21 -> V_168 . V_167 ;
F_72 ( V_21 ) ;
F_85 ( & V_21 -> V_208 ) ;
return V_21 ;
V_182:
F_86 ( V_21 ) ;
V_1:
F_87 ( V_180 ) ;
return NULL ;
}
static void F_88 ( struct V_208 * V_208 )
{
struct V_164 * V_21 = F_89 ( V_208 ,
struct V_164 , V_208 ) ;
struct V_209 * V_210 = V_21 -> V_17 -> V_183 ;
F_90 ( V_21 -> V_168 . V_167 ) ;
if ( V_21 -> V_51 != NULL )
F_91 ( V_21 -> V_51 ) ;
F_92 ( V_21 -> V_184 ) ;
F_87 ( V_21 -> V_151 ) ;
F_87 ( V_21 -> V_17 ) ;
F_93 ( V_210 ) ;
F_94 ( & V_21 -> V_166 ) ;
F_86 ( V_21 ) ;
}
static void F_95 ( struct V_164 * V_21 )
{
if ( V_21 != NULL )
F_96 ( & V_21 -> V_208 , F_88 ) ;
}
static int F_97 ( struct V_97 * V_98 )
{
int V_53 ;
V_53 = F_98 ( V_98 ) ;
return V_53 ;
}
static int F_99 ( struct V_50 * V_51 , T_4 V_211 , int V_212 )
{
int V_53 = 0 ;
if ( V_212 & ( V_213 | V_214 ) )
goto V_115;
switch ( V_211 & ( V_56 | V_188 ) ) {
case V_56 :
V_53 |= F_36 ( V_215 , & V_51 -> V_176 ) != 0
&& V_51 -> V_216 != 0 ;
break;
case V_188 :
V_53 |= F_36 ( V_217 , & V_51 -> V_176 ) != 0
&& V_51 -> V_218 != 0 ;
break;
case V_56 | V_188 :
V_53 |= F_36 ( V_219 , & V_51 -> V_176 ) != 0
&& V_51 -> V_220 != 0 ;
}
V_115:
return V_53 ;
}
static int F_100 ( struct V_221 * V_222 , T_4 V_175 )
{
if ( V_222 == NULL )
return 0 ;
if ( ( V_222 -> type & V_175 ) != V_175 )
return 0 ;
if ( F_36 ( V_223 , & V_222 -> V_176 ) )
return 0 ;
F_101 ( V_222 ) ;
return 1 ;
}
static void F_102 ( struct V_50 * V_51 , T_4 V_175 )
{
switch ( V_175 ) {
case V_188 :
V_51 -> V_218 ++ ;
break;
case V_56 :
V_51 -> V_216 ++ ;
break;
case V_56 | V_188 :
V_51 -> V_220 ++ ;
}
F_103 ( V_51 , V_51 -> V_51 | V_175 ) ;
}
static void F_104 ( struct V_50 * V_51 , T_6 * V_207 , T_4 V_175 )
{
if ( F_36 ( V_224 , & V_51 -> V_176 ) == 0 )
F_105 ( & V_51 -> V_207 , V_207 ) ;
F_105 ( & V_51 -> V_225 , V_207 ) ;
switch ( V_175 ) {
case V_56 :
F_106 ( V_215 , & V_51 -> V_176 ) ;
break;
case V_188 :
F_106 ( V_217 , & V_51 -> V_176 ) ;
break;
case V_56 | V_188 :
F_106 ( V_219 , & V_51 -> V_176 ) ;
}
}
static void F_107 ( struct V_50 * V_51 , T_6 * V_207 , T_4 V_175 )
{
F_108 ( & V_51 -> V_226 ) ;
F_104 ( V_51 , V_207 , V_175 ) ;
F_109 ( & V_51 -> V_226 ) ;
}
static void F_110 ( struct V_50 * V_51 , T_6 * V_225 , const T_6 * V_227 , T_4 V_175 )
{
F_108 ( & V_51 -> V_226 ) ;
if ( V_227 != NULL ) {
F_105 ( & V_51 -> V_207 , V_227 ) ;
F_106 ( V_224 , & V_51 -> V_176 ) ;
}
if ( V_225 != NULL )
F_104 ( V_51 , V_225 , V_175 ) ;
F_109 ( & V_51 -> V_226 ) ;
F_26 ( & V_51 -> V_184 -> V_228 ) ;
F_102 ( V_51 , V_175 ) ;
F_28 ( & V_51 -> V_184 -> V_228 ) ;
}
static int F_111 ( struct V_50 * V_51 , T_6 * V_225 , T_6 * V_222 , T_4 V_175 )
{
struct V_154 * V_155 = F_70 ( V_51 -> V_52 ) ;
struct V_221 * V_229 ;
int V_53 = 0 ;
V_175 &= ( V_56 | V_188 ) ;
F_112 () ;
V_229 = F_113 ( V_155 -> V_222 ) ;
if ( V_229 == NULL )
goto V_230;
F_26 ( & V_229 -> V_231 ) ;
if ( V_155 -> V_222 != V_229 ||
( V_229 -> type & V_175 ) != V_175 )
goto V_232;
if ( V_222 == NULL )
V_222 = & V_229 -> V_207 ;
else if ( ! F_114 ( & V_229 -> V_207 , V_222 ) )
goto V_232;
F_101 ( V_229 ) ;
F_110 ( V_51 , V_225 , & V_229 -> V_207 , V_175 ) ;
V_53 = 1 ;
V_232:
F_28 ( & V_229 -> V_231 ) ;
V_230:
F_115 () ;
if ( ! V_53 && V_225 != NULL ) {
F_110 ( V_51 , V_225 , NULL , V_175 ) ;
V_53 = 1 ;
}
return V_53 ;
}
static void F_116 ( struct V_52 * V_52 , T_4 V_175 )
{
struct V_221 * V_222 ;
F_112 () ;
V_222 = F_113 ( F_70 ( V_52 ) -> V_222 ) ;
if ( V_222 == NULL || ( V_222 -> type & V_175 ) == V_175 ) {
F_115 () ;
return;
}
F_115 () ;
F_18 ( V_52 ) ;
}
static struct V_50 * F_117 ( struct V_164 * V_233 )
{
struct V_50 * V_51 = V_233 -> V_51 ;
struct V_154 * V_155 = F_70 ( V_51 -> V_52 ) ;
struct V_221 * V_222 ;
int V_212 = V_233 -> V_168 . V_187 & ( V_213 | V_214 ) ;
T_4 V_175 = V_233 -> V_168 . V_175 ;
T_6 V_207 ;
int V_53 = - V_128 ;
for (; ; ) {
if ( F_99 ( V_51 , V_175 , V_212 ) ) {
F_26 ( & V_51 -> V_184 -> V_228 ) ;
if ( F_99 ( V_51 , V_175 , V_212 ) ) {
F_102 ( V_51 , V_175 ) ;
F_28 ( & V_51 -> V_184 -> V_228 ) ;
goto V_234;
}
F_28 ( & V_51 -> V_184 -> V_228 ) ;
}
F_112 () ;
V_222 = F_113 ( V_155 -> V_222 ) ;
if ( ! F_100 ( V_222 , V_175 ) ) {
F_115 () ;
break;
}
F_105 ( & V_207 , & V_222 -> V_207 ) ;
F_115 () ;
V_53 = F_118 ( V_51 -> V_52 , V_51 -> V_184 -> V_235 , V_212 ) ;
if ( V_53 != 0 )
goto V_115;
V_53 = - V_128 ;
if ( F_111 ( V_51 , NULL , & V_207 , V_175 ) )
goto V_234;
}
V_115:
return F_119 ( V_53 ) ;
V_234:
F_82 ( & V_51 -> V_22 ) ;
return V_51 ;
}
static struct V_50 * F_120 ( struct V_164 * V_134 )
{
struct V_52 * V_52 ;
struct V_50 * V_51 = NULL ;
struct V_221 * V_222 ;
int V_53 ;
if ( ! V_134 -> V_236 ) {
V_51 = F_117 ( V_134 ) ;
goto V_115;
}
V_53 = - V_128 ;
if ( ! ( V_134 -> V_166 . V_237 & V_238 ) )
goto V_1;
V_52 = F_121 ( V_134 -> V_151 -> V_183 , & V_134 -> V_165 . V_186 , & V_134 -> V_166 ) ;
V_53 = F_63 ( V_52 ) ;
if ( F_62 ( V_52 ) )
goto V_1;
V_53 = - V_239 ;
V_51 = F_122 ( V_52 , V_134 -> V_184 ) ;
if ( V_51 == NULL )
goto V_240;
if ( V_134 -> V_165 . V_241 != 0 ) {
struct V_31 * V_32 = F_77 ( V_52 ) -> V_31 ;
int V_242 = 0 ;
F_112 () ;
V_222 = F_113 ( F_70 ( V_52 ) -> V_222 ) ;
if ( V_222 )
V_242 = V_222 -> V_176 ;
F_115 () ;
if ( V_134 -> V_168 . V_201 == V_243 ) {
F_123 ( L_25
L_26
L_27 ,
V_32 -> V_85 ) ;
} else if ( ( V_242 & 1UL << V_223 ) == 0 )
F_124 ( V_51 -> V_52 ,
V_134 -> V_184 -> V_235 ,
& V_134 -> V_165 ) ;
else
F_125 ( V_51 -> V_52 ,
V_134 -> V_184 -> V_235 ,
& V_134 -> V_165 ) ;
}
F_111 ( V_51 , & V_134 -> V_165 . V_207 , NULL ,
V_134 -> V_168 . V_175 ) ;
F_126 ( V_52 ) ;
V_115:
return V_51 ;
V_240:
F_126 ( V_52 ) ;
V_1:
return F_119 ( V_53 ) ;
}
static struct V_244 * F_127 ( struct V_50 * V_51 )
{
struct V_154 * V_155 = F_70 ( V_51 -> V_52 ) ;
struct V_244 * V_245 ;
F_26 ( & V_51 -> V_52 -> V_156 ) ;
F_128 (ctx, &nfsi->open_files, list) {
if ( V_245 -> V_51 != V_51 )
continue;
F_129 ( V_245 ) ;
F_28 ( & V_51 -> V_52 -> V_156 ) ;
return V_245 ;
}
F_28 ( & V_51 -> V_52 -> V_156 ) ;
return F_119 ( - V_246 ) ;
}
static struct V_164 * F_130 ( struct V_244 * V_245 , struct V_50 * V_51 )
{
struct V_164 * V_233 ;
V_233 = F_75 ( V_245 -> V_17 , V_51 -> V_184 , 0 , 0 , NULL , V_247 ) ;
if ( V_233 == NULL )
return F_119 ( - V_239 ) ;
V_233 -> V_51 = V_51 ;
F_82 ( & V_51 -> V_22 ) ;
return V_233 ;
}
static int F_131 ( struct V_164 * V_233 , T_4 V_175 , struct V_50 * * V_33 )
{
struct V_50 * V_248 ;
int V_53 ;
V_233 -> V_168 . V_187 = 0 ;
V_233 -> V_168 . V_175 = V_175 ;
memset ( & V_233 -> V_165 , 0 , sizeof( V_233 -> V_165 ) ) ;
memset ( & V_233 -> V_169 , 0 , sizeof( V_233 -> V_169 ) ) ;
F_72 ( V_233 ) ;
V_53 = F_132 ( V_233 ) ;
if ( V_53 != 0 )
return V_53 ;
V_248 = F_120 ( V_233 ) ;
if ( F_62 ( V_248 ) )
return F_63 ( V_248 ) ;
F_133 ( V_248 , V_175 ) ;
* V_33 = V_248 ;
return 0 ;
}
static int F_134 ( struct V_164 * V_233 , struct V_50 * V_51 )
{
struct V_50 * V_248 ;
int V_53 ;
F_135 ( V_224 , & V_51 -> V_176 ) ;
F_136 () ;
if ( V_51 -> V_220 != 0 ) {
F_135 ( V_219 , & V_51 -> V_176 ) ;
V_53 = F_131 ( V_233 , V_56 | V_188 , & V_248 ) ;
if ( V_53 != 0 )
return V_53 ;
if ( V_248 != V_51 )
return - V_249 ;
}
if ( V_51 -> V_218 != 0 ) {
F_135 ( V_217 , & V_51 -> V_176 ) ;
V_53 = F_131 ( V_233 , V_188 , & V_248 ) ;
if ( V_53 != 0 )
return V_53 ;
if ( V_248 != V_51 )
return - V_249 ;
}
if ( V_51 -> V_216 != 0 ) {
F_135 ( V_215 , & V_51 -> V_176 ) ;
V_53 = F_131 ( V_233 , V_56 , & V_248 ) ;
if ( V_53 != 0 )
return V_53 ;
if ( V_248 != V_51 )
return - V_249 ;
}
if ( F_36 ( V_224 , & V_51 -> V_176 ) == 0 &&
! F_114 ( & V_51 -> V_207 , & V_51 -> V_225 ) ) {
F_108 ( & V_51 -> V_226 ) ;
if ( F_36 ( V_224 , & V_51 -> V_176 ) == 0 )
F_105 ( & V_51 -> V_207 , & V_51 -> V_225 ) ;
F_109 ( & V_51 -> V_226 ) ;
}
return 0 ;
}
static int F_137 ( struct V_244 * V_245 , struct V_50 * V_51 )
{
struct V_221 * V_222 ;
struct V_164 * V_233 ;
T_4 V_241 = 0 ;
int V_250 ;
V_233 = F_130 ( V_245 , V_51 ) ;
if ( F_62 ( V_233 ) )
return F_63 ( V_233 ) ;
V_233 -> V_168 . V_201 = V_251 ;
V_233 -> V_168 . V_186 = F_83 ( V_51 -> V_52 ) ;
F_112 () ;
V_222 = F_113 ( F_70 ( V_51 -> V_52 ) -> V_222 ) ;
if ( V_222 != NULL && F_36 ( V_223 , & V_222 -> V_176 ) != 0 )
V_241 = V_222 -> type ;
F_115 () ;
V_233 -> V_168 . V_205 . V_241 = V_241 ;
V_250 = F_134 ( V_233 , V_51 ) ;
F_95 ( V_233 ) ;
return V_250 ;
}
static int F_138 ( struct V_244 * V_245 , struct V_50 * V_51 )
{
struct V_45 * V_46 = F_77 ( V_51 -> V_52 ) ;
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_137 ( V_245 , V_51 ) ;
if ( V_1 != - V_77 )
break;
F_16 ( V_46 , V_1 , & V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_139 ( struct V_173 * V_174 , struct V_50 * V_51 )
{
struct V_244 * V_245 ;
int V_53 ;
V_245 = F_127 ( V_51 ) ;
if ( F_62 ( V_245 ) )
return F_63 ( V_245 ) ;
V_53 = F_138 ( V_245 , V_51 ) ;
F_140 ( V_245 ) ;
return V_53 ;
}
static int F_141 ( struct V_244 * V_245 , struct V_50 * V_51 , const T_6 * V_207 )
{
struct V_164 * V_233 ;
int V_53 ;
V_233 = F_130 ( V_245 , V_51 ) ;
if ( F_62 ( V_233 ) )
return F_63 ( V_233 ) ;
V_233 -> V_168 . V_201 = V_243 ;
F_105 ( & V_233 -> V_168 . V_205 . V_222 , V_207 ) ;
V_53 = F_134 ( V_233 , V_51 ) ;
F_95 ( V_233 ) ;
return V_53 ;
}
int F_142 ( struct V_244 * V_245 , struct V_50 * V_51 , const T_6 * V_207 )
{
struct V_48 V_49 = { } ;
struct V_45 * V_46 = F_77 ( V_51 -> V_52 ) ;
int V_1 ;
do {
V_1 = F_141 ( V_245 , V_51 , V_207 ) ;
switch ( V_1 ) {
case 0 :
case - V_246 :
case - V_249 :
goto V_115;
case - V_65 :
case - V_66 :
case - V_67 :
case - V_68 :
case - V_69 :
F_23 ( V_46 -> V_31 -> V_72 , V_1 ) ;
goto V_115;
case - V_63 :
case - V_62 :
case - V_61 :
F_21 ( V_46 -> V_31 ) ;
goto V_115;
case - V_44 :
case - V_58 :
case - V_59 :
case - V_60 :
F_143 ( V_51 -> V_52 ,
V_207 ) ;
F_19 ( V_46 , V_51 ) ;
case - V_78 :
case - V_239 :
V_1 = 0 ;
goto V_115;
}
V_1 = F_16 ( V_46 , V_1 , & V_49 ) ;
} while ( V_49 . V_54 );
V_115:
return V_1 ;
}
static void F_144 ( struct V_97 * V_98 , void * V_132 )
{
struct V_164 * V_134 = V_132 ;
V_134 -> V_252 = V_98 -> V_148 ;
if ( V_134 -> V_252 == 0 ) {
F_105 ( & V_134 -> V_165 . V_207 , & V_134 -> V_169 . V_207 ) ;
F_145 ( & V_134 -> V_184 -> V_181 , 0 ) ;
F_29 ( V_134 -> V_165 . V_46 , V_134 -> V_86 ) ;
V_134 -> V_236 = 1 ;
}
}
static void F_146 ( void * V_132 )
{
struct V_164 * V_134 = V_132 ;
struct V_50 * V_51 = NULL ;
if ( V_134 -> V_253 == 0 )
goto V_254;
if ( ! V_134 -> V_236 )
goto V_254;
V_51 = F_120 ( V_134 ) ;
if ( ! F_62 ( V_51 ) )
F_133 ( V_51 , V_134 -> V_168 . V_175 ) ;
V_254:
F_95 ( V_134 ) ;
}
static int F_147 ( struct V_164 * V_134 )
{
struct V_45 * V_46 = F_77 ( V_134 -> V_151 -> V_27 ) ;
struct V_97 * V_98 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_257 ] ,
. V_258 = & V_134 -> V_170 ,
. V_259 = & V_134 -> V_169 ,
. V_260 = V_134 -> V_184 -> V_235 ,
} ;
struct V_141 V_261 = {
. V_143 = V_46 -> V_79 ,
. V_138 = & V_139 ,
. V_144 = & V_262 ,
. V_146 = V_134 ,
. V_263 = V_264 ,
. V_176 = V_265 ,
} ;
int V_250 ;
F_148 ( & V_134 -> V_208 ) ;
V_134 -> V_236 = 0 ;
V_134 -> V_252 = 0 ;
V_134 -> V_86 = V_131 ;
V_98 = F_61 ( & V_261 ) ;
if ( F_62 ( V_98 ) )
return F_63 ( V_98 ) ;
V_250 = F_97 ( V_98 ) ;
if ( V_250 != 0 ) {
V_134 -> V_253 = 1 ;
F_149 () ;
} else
V_250 = V_134 -> V_252 ;
F_64 ( V_98 ) ;
return V_250 ;
}
static void F_150 ( struct V_97 * V_98 , void * V_132 )
{
struct V_164 * V_134 = V_132 ;
struct V_173 * V_174 = V_134 -> V_184 ;
if ( F_151 ( V_134 -> V_168 . V_167 , V_98 ) != 0 )
return;
if ( V_134 -> V_51 != NULL ) {
struct V_221 * V_222 ;
if ( F_99 ( V_134 -> V_51 , V_134 -> V_168 . V_175 , V_134 -> V_168 . V_187 ) )
goto V_266;
F_112 () ;
V_222 = F_113 ( F_70 ( V_134 -> V_51 -> V_52 ) -> V_222 ) ;
if ( V_134 -> V_168 . V_201 != V_243 &&
F_100 ( V_222 , V_134 -> V_168 . V_175 ) )
goto V_267;
F_115 () ;
}
V_134 -> V_168 . V_189 = V_174 -> V_268 -> V_31 -> V_190 ;
if ( V_134 -> V_168 . V_201 == V_251 ) {
V_98 -> V_269 . V_255 = & V_256 [ V_270 ] ;
F_152 ( & V_134 -> V_165 . V_186 , V_134 -> V_168 . V_186 ) ;
}
V_134 -> V_86 = V_131 ;
if ( F_54 ( V_134 -> V_168 . V_46 ,
& V_134 -> V_168 . V_136 ,
& V_134 -> V_165 . V_137 , V_98 ) )
return;
F_57 ( V_98 ) ;
return;
V_267:
F_115 () ;
V_266:
V_98 -> V_271 = NULL ;
}
static void F_153 ( struct V_97 * V_98 , void * V_132 )
{
F_34 ( V_98 , V_100 ) ;
F_150 ( V_98 , V_132 ) ;
}
static void F_154 ( struct V_97 * V_98 , void * V_132 )
{
struct V_164 * V_134 = V_132 ;
V_134 -> V_252 = V_98 -> V_148 ;
if ( ! F_45 ( V_98 , & V_134 -> V_165 . V_137 ) )
return;
if ( V_98 -> V_148 == 0 ) {
switch ( V_134 -> V_165 . V_166 -> V_211 & V_272 ) {
case V_273 :
break;
case V_274 :
V_134 -> V_252 = - V_275 ;
break;
case V_276 :
V_134 -> V_252 = - V_277 ;
break;
default:
V_134 -> V_252 = - V_278 ;
}
F_29 ( V_134 -> V_165 . V_46 , V_134 -> V_86 ) ;
if ( ! ( V_134 -> V_165 . V_279 & V_280 ) )
F_145 ( & V_134 -> V_184 -> V_181 , 0 ) ;
}
V_134 -> V_236 = 1 ;
}
static void F_155 ( void * V_132 )
{
struct V_164 * V_134 = V_132 ;
struct V_50 * V_51 = NULL ;
if ( V_134 -> V_253 == 0 )
goto V_254;
if ( V_134 -> V_252 != 0 || ! V_134 -> V_236 )
goto V_254;
if ( V_134 -> V_165 . V_279 & V_280 )
goto V_254;
V_51 = F_120 ( V_134 ) ;
if ( ! F_62 ( V_51 ) )
F_133 ( V_51 , V_134 -> V_168 . V_175 ) ;
V_254:
F_95 ( V_134 ) ;
}
static int F_156 ( struct V_164 * V_134 , int V_281 )
{
struct V_52 * V_151 = V_134 -> V_151 -> V_27 ;
struct V_45 * V_46 = F_77 ( V_151 ) ;
struct V_282 * V_168 = & V_134 -> V_168 ;
struct V_283 * V_165 = & V_134 -> V_165 ;
struct V_97 * V_98 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_284 ] ,
. V_258 = V_168 ,
. V_259 = V_165 ,
. V_260 = V_134 -> V_184 -> V_235 ,
} ;
struct V_141 V_261 = {
. V_143 = V_46 -> V_79 ,
. V_138 = & V_139 ,
. V_144 = & V_285 ,
. V_146 = V_134 ,
. V_263 = V_264 ,
. V_176 = V_265 ,
} ;
int V_250 ;
F_49 ( & V_168 -> V_136 , & V_165 -> V_137 , 1 ) ;
F_148 ( & V_134 -> V_208 ) ;
V_134 -> V_236 = 0 ;
V_134 -> V_252 = 0 ;
V_134 -> V_253 = 0 ;
if ( V_281 )
V_261 . V_144 = & V_286 ;
V_98 = F_61 ( & V_261 ) ;
if ( F_62 ( V_98 ) )
return F_63 ( V_98 ) ;
V_250 = F_97 ( V_98 ) ;
if ( V_250 != 0 ) {
V_134 -> V_253 = 1 ;
F_149 () ;
} else
V_250 = V_134 -> V_252 ;
F_64 ( V_98 ) ;
return V_250 ;
}
static int F_132 ( struct V_164 * V_134 )
{
struct V_52 * V_151 = V_134 -> V_151 -> V_27 ;
struct V_283 * V_165 = & V_134 -> V_165 ;
int V_250 ;
V_250 = F_156 ( V_134 , 1 ) ;
if ( V_250 != 0 || ! V_134 -> V_236 )
return V_250 ;
F_157 ( F_77 ( V_151 ) , & V_134 -> V_166 ) ;
if ( V_165 -> V_279 & V_280 ) {
V_250 = F_147 ( V_134 ) ;
if ( V_250 != 0 )
return V_250 ;
}
return V_250 ;
}
static int F_158 ( struct V_164 * V_134 )
{
struct V_52 * V_151 = V_134 -> V_151 -> V_27 ;
struct V_45 * V_46 = F_77 ( V_151 ) ;
struct V_282 * V_168 = & V_134 -> V_168 ;
struct V_283 * V_165 = & V_134 -> V_165 ;
int V_250 ;
V_250 = F_156 ( V_134 , 0 ) ;
if ( ! V_134 -> V_236 )
return V_250 ;
if ( V_250 != 0 ) {
if ( V_250 == - V_7 &&
! ( V_168 -> V_187 & V_287 ) )
return - V_246 ;
return V_250 ;
}
F_157 ( V_46 , & V_134 -> V_166 ) ;
if ( V_168 -> V_187 & V_287 )
F_69 ( V_151 , & V_165 -> V_153 ) ;
if ( ( V_165 -> V_279 & V_288 ) == 0 )
V_46 -> V_82 &= ~ V_289 ;
if( V_165 -> V_279 & V_280 ) {
V_250 = F_147 ( V_134 ) ;
if ( V_250 != 0 )
return V_250 ;
}
if ( ! ( V_165 -> V_166 -> V_237 & V_238 ) )
F_159 ( V_46 , & V_165 -> V_186 , V_165 -> V_166 ) ;
return 0 ;
}
static int F_160 ( struct V_31 * V_32 )
{
unsigned int V_290 ;
int V_53 ;
for ( V_290 = V_291 ; V_290 != 0 ; V_290 -- ) {
V_53 = F_10 ( V_32 ) ;
if ( V_53 != 0 )
break;
if ( ! F_36 ( V_292 , & V_32 -> V_34 ) &&
! F_36 ( V_293 , & V_32 -> V_34 ) )
break;
F_161 ( V_32 ) ;
V_53 = - V_14 ;
}
return V_53 ;
}
static int F_162 ( struct V_45 * V_46 )
{
return F_160 ( V_46 -> V_31 ) ;
}
static int F_163 ( struct V_244 * V_245 , struct V_50 * V_51 )
{
struct V_164 * V_233 ;
int V_53 ;
V_233 = F_130 ( V_245 , V_51 ) ;
if ( F_62 ( V_233 ) )
return F_63 ( V_233 ) ;
V_53 = F_134 ( V_233 , V_51 ) ;
if ( V_53 == - V_249 )
F_164 ( V_245 -> V_17 ) ;
F_95 ( V_233 ) ;
return V_53 ;
}
static int F_165 ( struct V_244 * V_245 , struct V_50 * V_51 )
{
struct V_45 * V_46 = F_77 ( V_51 -> V_52 ) ;
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_163 ( V_245 , V_51 ) ;
switch ( V_1 ) {
default:
goto V_115;
case - V_76 :
case - V_77 :
F_16 ( V_46 , V_1 , & V_49 ) ;
V_1 = 0 ;
}
} while ( V_49 . V_54 );
V_115:
return V_1 ;
}
static int F_166 ( struct V_173 * V_174 , struct V_50 * V_51 )
{
struct V_244 * V_245 ;
int V_53 ;
V_245 = F_127 ( V_51 ) ;
if ( F_62 ( V_245 ) )
return F_63 ( V_245 ) ;
V_53 = F_165 ( V_245 , V_51 ) ;
F_140 ( V_245 ) ;
return V_53 ;
}
static int F_167 ( struct V_50 * V_51 , T_6 * V_207 , unsigned int V_176 )
{
int V_250 = V_114 ;
struct V_45 * V_46 = F_77 ( V_51 -> V_52 ) ;
if ( V_51 -> V_176 & V_176 ) {
V_250 = F_168 ( V_46 , V_207 ) ;
if ( V_250 != V_114 ) {
F_169 ( V_46 , V_207 ) ;
V_51 -> V_176 &= ~ V_176 ;
}
}
return V_250 ;
}
static int F_170 ( struct V_173 * V_174 , struct V_50 * V_51 )
{
int V_294 , V_295 ;
int V_296 = 1 << V_224 ;
int V_187 = ( 1 << V_215 ) | ( 1 << V_217 ) | ( 1 << V_219 ) ;
V_294 = F_167 ( V_51 , & V_51 -> V_207 , V_296 ) ;
V_295 = F_167 ( V_51 , & V_51 -> V_225 , V_187 ) ;
if ( ( V_294 == V_114 ) && ( V_295 == V_114 ) )
return V_114 ;
return F_166 ( V_174 , V_51 ) ;
}
static inline void F_171 ( struct V_164 * V_233 , struct V_177 * V_297 )
{
if ( ( V_233 -> V_165 . V_298 [ 1 ] & V_299 ) &&
! ( V_297 -> V_203 & V_300 ) )
V_297 -> V_203 |= V_301 ;
if ( ( V_233 -> V_165 . V_298 [ 1 ] & V_302 ) &&
! ( V_297 -> V_203 & V_303 ) )
V_297 -> V_203 |= V_304 ;
}
static int F_172 ( struct V_52 * V_151 ,
struct V_17 * V_17 ,
T_4 V_175 ,
int V_176 ,
struct V_177 * V_297 ,
struct V_260 * V_305 ,
struct V_50 * * V_33 ,
struct V_306 * * V_307 )
{
struct V_173 * V_174 ;
struct V_50 * V_51 = NULL ;
struct V_45 * V_46 = F_77 ( V_151 ) ;
struct V_164 * V_233 ;
int V_250 ;
V_250 = - V_239 ;
V_174 = F_173 ( V_46 , V_305 , V_308 ) ;
if ( V_174 == NULL ) {
F_2 ( L_28 ) ;
goto V_309;
}
V_250 = F_162 ( V_46 ) ;
if ( V_250 != 0 )
goto V_310;
if ( V_17 -> V_27 != NULL )
F_116 ( V_17 -> V_27 , V_175 ) ;
V_250 = - V_239 ;
V_233 = F_75 ( V_17 , V_174 , V_175 , V_176 , V_297 , V_308 ) ;
if ( V_233 == NULL )
goto V_310;
if ( V_307 && V_46 -> V_198 [ 2 ] & V_311 ) {
V_233 -> V_166 . V_312 = F_174 () ;
if ( ! V_233 -> V_166 . V_312 )
goto V_313;
V_233 -> V_168 . V_199 = & V_314 [ 0 ] ;
}
if ( V_17 -> V_27 != NULL )
V_233 -> V_51 = F_122 ( V_17 -> V_27 , V_174 ) ;
V_250 = F_158 ( V_233 ) ;
if ( V_250 != 0 )
goto V_313;
V_51 = F_120 ( V_233 ) ;
V_250 = F_63 ( V_51 ) ;
if ( F_62 ( V_51 ) )
goto V_313;
if ( V_46 -> V_82 & V_289 )
F_106 ( V_315 , & V_51 -> V_176 ) ;
if ( V_233 -> V_168 . V_187 & V_213 ) {
F_171 ( V_233 , V_297 ) ;
F_73 ( V_233 -> V_165 . V_166 ) ;
V_250 = F_175 ( V_51 -> V_52 , V_305 ,
V_233 -> V_165 . V_166 , V_297 ,
V_51 ) ;
if ( V_250 == 0 )
F_176 ( V_51 -> V_52 , V_297 ) ;
F_177 ( V_51 -> V_52 , V_233 -> V_165 . V_166 ) ;
}
if ( F_178 ( V_307 , V_233 -> V_166 . V_312 , V_46 ) )
* V_307 = V_233 -> V_166 . V_312 ;
else
F_86 ( V_233 -> V_166 . V_312 ) ;
V_233 -> V_166 . V_312 = NULL ;
F_95 ( V_233 ) ;
F_92 ( V_174 ) ;
* V_33 = V_51 ;
return 0 ;
V_313:
F_86 ( V_233 -> V_166 . V_312 ) ;
F_95 ( V_233 ) ;
V_310:
F_92 ( V_174 ) ;
V_309:
* V_33 = NULL ;
return V_250 ;
}
static struct V_50 * F_179 ( struct V_52 * V_151 ,
struct V_17 * V_17 ,
T_4 V_175 ,
int V_176 ,
struct V_177 * V_297 ,
struct V_260 * V_305 ,
struct V_306 * * V_307 )
{
struct V_48 V_49 = { } ;
struct V_50 * V_33 ;
int V_250 ;
V_175 &= V_56 | V_188 ;
do {
V_250 = F_172 ( V_151 , V_17 , V_175 , V_176 , V_297 , V_305 ,
& V_33 , V_307 ) ;
if ( V_250 == 0 )
break;
if ( V_250 == - V_316 ) {
F_180 ( L_5
L_29 ,
F_77 ( V_151 ) -> V_31 -> V_85 ) ;
V_49 . V_54 = 1 ;
continue;
}
if ( V_250 == - V_60 ) {
V_49 . V_54 = 1 ;
continue;
}
if ( V_250 == - V_128 ) {
V_49 . V_54 = 1 ;
continue;
}
V_33 = F_119 ( F_16 ( F_77 ( V_151 ) ,
V_250 , & V_49 ) ) ;
} while ( V_49 . V_54 );
return V_33 ;
}
static int F_181 ( struct V_52 * V_52 , struct V_260 * V_305 ,
struct V_317 * V_318 , struct V_177 * V_297 ,
struct V_50 * V_51 )
{
struct V_45 * V_46 = F_77 ( V_52 ) ;
struct V_319 V_320 = {
. V_186 = F_83 ( V_52 ) ,
. V_321 = V_297 ,
. V_46 = V_46 ,
. V_197 = V_46 -> V_198 ,
} ;
struct V_322 V_33 = {
. V_318 = V_318 ,
. V_46 = V_46 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_323 ] ,
. V_258 = & V_320 ,
. V_259 = & V_33 ,
. V_260 = V_305 ,
} ;
unsigned long V_86 = V_131 ;
int V_250 ;
F_73 ( V_318 ) ;
if ( V_51 != NULL ) {
F_182 ( & V_320 . V_207 , V_51 , V_188 ,
V_43 -> V_324 , V_43 -> V_325 ) ;
} else if ( F_183 ( & V_320 . V_207 , V_52 ,
V_188 ) ) {
} else
F_105 ( & V_320 . V_207 , & V_326 ) ;
V_250 = F_68 ( V_46 -> V_79 , V_46 , & V_139 , & V_320 . V_136 , & V_33 . V_137 , 1 ) ;
if ( V_250 == 0 && V_51 != NULL )
F_29 ( V_46 , V_86 ) ;
return V_250 ;
}
static int F_175 ( struct V_52 * V_52 , struct V_260 * V_305 ,
struct V_317 * V_318 , struct V_177 * V_297 ,
struct V_50 * V_51 )
{
struct V_45 * V_46 = F_77 ( V_52 ) ;
struct V_48 V_49 = {
. V_51 = V_51 ,
. V_52 = V_52 ,
} ;
int V_1 ;
do {
V_1 = F_181 ( V_52 , V_305 , V_318 , V_297 , V_51 ) ;
switch ( V_1 ) {
case - V_55 :
if ( V_51 && ! ( V_51 -> V_51 & V_188 ) ) {
V_1 = - V_327 ;
if ( V_297 -> V_203 & V_328 )
V_1 = - V_10 ;
goto V_115;
}
}
V_1 = F_16 ( V_46 , V_1 , & V_49 ) ;
} while ( V_49 . V_54 );
V_115:
return V_1 ;
}
static void F_184 ( void * V_134 )
{
struct V_329 * V_132 = V_134 ;
struct V_173 * V_174 = V_132 -> V_51 -> V_184 ;
struct V_209 * V_210 = V_132 -> V_51 -> V_52 -> V_330 ;
if ( V_132 -> V_331 )
F_185 ( V_132 -> V_51 -> V_52 ) ;
F_91 ( V_132 -> V_51 ) ;
F_90 ( V_132 -> V_320 . V_167 ) ;
F_92 ( V_174 ) ;
F_93 ( V_210 ) ;
F_86 ( V_132 ) ;
}
static void F_186 ( struct V_50 * V_51 ,
T_4 V_175 )
{
F_26 ( & V_51 -> V_184 -> V_228 ) ;
if ( ! ( V_175 & V_56 ) )
F_135 ( V_215 , & V_51 -> V_176 ) ;
if ( ! ( V_175 & V_188 ) )
F_135 ( V_217 , & V_51 -> V_176 ) ;
F_135 ( V_219 , & V_51 -> V_176 ) ;
F_28 ( & V_51 -> V_184 -> V_228 ) ;
}
static void F_187 ( struct V_97 * V_98 , void * V_134 )
{
struct V_329 * V_132 = V_134 ;
struct V_50 * V_51 = V_132 -> V_51 ;
struct V_45 * V_46 = F_77 ( V_132 -> V_52 ) ;
F_2 ( L_30 , V_13 ) ;
if ( ! F_45 ( V_98 , & V_132 -> V_33 . V_137 ) )
return;
switch ( V_98 -> V_148 ) {
case 0 :
if ( V_132 -> V_331 )
F_188 ( V_51 -> V_52 ,
V_132 -> V_332 ) ;
F_107 ( V_51 , & V_132 -> V_33 . V_207 , 0 ) ;
F_29 ( V_46 , V_132 -> V_86 ) ;
F_186 ( V_51 ,
V_132 -> V_320 . V_175 ) ;
break;
case - V_62 :
case - V_81 :
case - V_60 :
case - V_61 :
if ( V_132 -> V_320 . V_175 == 0 )
break;
default:
if ( F_189 ( V_98 , V_46 , V_51 ) == - V_128 )
F_190 ( V_98 ) ;
}
F_191 ( V_132 -> V_320 . V_167 ) ;
F_192 ( V_132 -> V_52 , V_132 -> V_33 . V_318 ) ;
F_2 ( L_31 , V_13 , V_98 -> V_148 ) ;
}
static void F_193 ( struct V_97 * V_98 , void * V_134 )
{
struct V_329 * V_132 = V_134 ;
struct V_50 * V_51 = V_132 -> V_51 ;
int V_333 = 0 ;
F_2 ( L_30 , V_13 ) ;
if ( F_151 ( V_132 -> V_320 . V_167 , V_98 ) != 0 )
return;
V_98 -> V_269 . V_255 = & V_256 [ V_334 ] ;
V_132 -> V_320 . V_175 = V_56 | V_188 ;
F_26 ( & V_51 -> V_184 -> V_228 ) ;
if ( V_51 -> V_220 == 0 ) {
if ( V_51 -> V_216 == 0 ) {
V_333 |= F_36 ( V_215 , & V_51 -> V_176 ) ;
V_333 |= F_36 ( V_219 , & V_51 -> V_176 ) ;
V_132 -> V_320 . V_175 &= ~ V_56 ;
}
if ( V_51 -> V_218 == 0 ) {
V_333 |= F_36 ( V_217 , & V_51 -> V_176 ) ;
V_333 |= F_36 ( V_219 , & V_51 -> V_176 ) ;
V_132 -> V_320 . V_175 &= ~ V_188 ;
}
}
F_28 ( & V_51 -> V_184 -> V_228 ) ;
if ( ! V_333 ) {
V_98 -> V_271 = NULL ;
goto V_115;
}
if ( V_132 -> V_320 . V_175 == 0 ) {
V_98 -> V_269 . V_255 = & V_256 [ V_335 ] ;
if ( V_132 -> V_331 &&
F_194 ( V_132 -> V_52 , & V_132 -> V_332 ) ) {
F_52 ( & F_77 ( V_132 -> V_52 ) -> V_336 ,
V_98 , NULL ) ;
goto V_115;
}
}
F_73 ( V_132 -> V_33 . V_318 ) ;
V_132 -> V_86 = V_131 ;
if ( F_54 ( F_77 ( V_132 -> V_52 ) ,
& V_132 -> V_320 . V_136 ,
& V_132 -> V_33 . V_137 ,
V_98 ) )
goto V_115;
F_57 ( V_98 ) ;
V_115:
F_2 ( L_32 , V_13 ) ;
}
int F_195 ( struct V_50 * V_51 , T_5 V_179 , int V_337 , bool V_331 )
{
struct V_45 * V_46 = F_77 ( V_51 -> V_52 ) ;
struct V_329 * V_132 ;
struct V_173 * V_174 = V_51 -> V_184 ;
struct V_97 * V_98 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_335 ] ,
. V_260 = V_51 -> V_184 -> V_235 ,
} ;
struct V_141 V_261 = {
. V_143 = V_46 -> V_79 ,
. V_138 = & V_139 ,
. V_144 = & V_338 ,
. V_263 = V_264 ,
. V_176 = V_265 ,
} ;
int V_250 = - V_239 ;
V_132 = F_78 ( sizeof( * V_132 ) , V_179 ) ;
if ( V_132 == NULL )
goto V_115;
F_49 ( & V_132 -> V_320 . V_136 , & V_132 -> V_33 . V_137 , 1 ) ;
V_132 -> V_52 = V_51 -> V_52 ;
V_132 -> V_51 = V_51 ;
V_132 -> V_320 . V_186 = F_83 ( V_51 -> V_52 ) ;
V_132 -> V_320 . V_207 = & V_51 -> V_225 ;
V_132 -> V_320 . V_167 = F_79 ( & V_51 -> V_184 -> V_181 , V_179 ) ;
if ( V_132 -> V_320 . V_167 == NULL )
goto V_339;
V_132 -> V_320 . V_175 = 0 ;
V_132 -> V_320 . V_197 = V_46 -> V_340 ;
V_132 -> V_33 . V_318 = & V_132 -> V_318 ;
V_132 -> V_33 . V_167 = V_132 -> V_320 . V_167 ;
V_132 -> V_33 . V_46 = V_46 ;
V_132 -> V_331 = V_331 ;
F_80 ( V_132 -> V_52 -> V_330 ) ;
V_139 . V_258 = & V_132 -> V_320 ;
V_139 . V_259 = & V_132 -> V_33 ;
V_261 . V_146 = V_132 ;
V_98 = F_61 ( & V_261 ) ;
if ( F_62 ( V_98 ) )
return F_63 ( V_98 ) ;
V_250 = 0 ;
if ( V_337 )
V_250 = F_98 ( V_98 ) ;
F_64 ( V_98 ) ;
return V_250 ;
V_339:
F_86 ( V_132 ) ;
V_115:
if ( V_331 )
F_185 ( V_51 -> V_52 ) ;
F_91 ( V_51 ) ;
F_92 ( V_174 ) ;
return V_250 ;
}
static struct V_52 *
F_196 ( struct V_52 * V_151 , struct V_244 * V_245 , int V_187 , struct V_177 * V_341 )
{
struct V_50 * V_51 ;
V_51 = F_179 ( V_151 , V_245 -> V_17 , V_245 -> V_211 , V_187 , V_341 ,
V_245 -> V_305 , & V_245 -> V_312 ) ;
if ( F_62 ( V_51 ) )
return F_197 ( V_51 ) ;
V_245 -> V_51 = V_51 ;
return F_198 ( V_51 -> V_52 ) ;
}
static void F_199 ( struct V_244 * V_245 , int V_342 )
{
if ( V_245 -> V_51 == NULL )
return;
if ( V_342 )
F_200 ( V_245 -> V_51 , V_245 -> V_211 ) ;
else
F_133 ( V_245 -> V_51 , V_245 -> V_211 ) ;
}
static int F_201 ( struct V_45 * V_46 , struct V_343 * V_344 )
{
struct V_345 args = {
. V_344 = V_344 ,
} ;
struct V_346 V_33 = {} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_347 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
int V_250 ;
V_250 = F_68 ( V_46 -> V_79 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
if ( V_250 == 0 ) {
memcpy ( V_46 -> V_198 , V_33 . V_198 , sizeof( V_46 -> V_198 ) ) ;
V_46 -> V_82 &= ~ ( V_348 | V_349 |
V_350 | V_351 |
V_352 | V_353 | V_354 |
V_355 | V_356 |
V_357 | V_358 ) ;
if ( V_33 . V_198 [ 0 ] & V_359 )
V_46 -> V_82 |= V_348 ;
if ( V_33 . V_360 != 0 )
V_46 -> V_82 |= V_349 ;
if ( V_33 . V_361 != 0 )
V_46 -> V_82 |= V_350 ;
if ( V_33 . V_198 [ 0 ] & V_26 )
V_46 -> V_82 |= V_351 ;
if ( V_33 . V_198 [ 1 ] & V_362 )
V_46 -> V_82 |= V_352 ;
if ( V_33 . V_198 [ 1 ] & V_363 )
V_46 -> V_82 |= V_353 ;
if ( V_33 . V_198 [ 1 ] & V_364 )
V_46 -> V_82 |= V_354 ;
if ( V_33 . V_198 [ 1 ] & V_365 )
V_46 -> V_82 |= V_355 ;
if ( V_33 . V_198 [ 1 ] & V_299 )
V_46 -> V_82 |= V_356 ;
if ( V_33 . V_198 [ 1 ] & V_366 )
V_46 -> V_82 |= V_357 ;
if ( V_33 . V_198 [ 1 ] & V_302 )
V_46 -> V_82 |= V_358 ;
memcpy ( V_46 -> V_340 , V_33 . V_198 , sizeof( V_46 -> V_340 ) ) ;
V_46 -> V_340 [ 0 ] &= V_367 | V_368 ;
V_46 -> V_340 [ 1 ] &= V_366 | V_302 ;
V_46 -> V_369 = V_33 . V_369 ;
V_46 -> V_370 = V_33 . V_370 ;
}
return V_250 ;
}
int F_202 ( struct V_45 * V_46 , struct V_343 * V_344 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_46 ,
F_201 ( V_46 , V_344 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_203 ( struct V_45 * V_46 , struct V_343 * V_344 ,
struct V_371 * V_372 )
{
struct V_373 args = {
. V_197 = V_200 ,
} ;
struct V_374 V_33 = {
. V_46 = V_46 ,
. V_318 = V_372 -> V_318 ,
. V_186 = V_344 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_375 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
F_73 ( V_372 -> V_318 ) ;
return F_68 ( V_46 -> V_79 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
}
static int F_204 ( struct V_45 * V_46 , struct V_343 * V_344 ,
struct V_371 * V_372 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_203 ( V_46 , V_344 , V_372 ) ;
switch ( V_1 ) {
case 0 :
case - V_4 :
goto V_115;
default:
V_1 = F_16 ( V_46 , V_1 , & V_49 ) ;
}
} while ( V_49 . V_54 );
V_115:
return V_1 ;
}
static int F_205 ( struct V_45 * V_46 , struct V_343 * V_344 ,
struct V_371 * V_372 , T_7 V_376 )
{
struct V_377 * V_378 ;
int V_53 ;
V_378 = F_206 ( V_376 , V_46 -> V_79 ) ;
if ( ! V_378 ) {
V_53 = - V_14 ;
goto V_115;
}
V_53 = F_204 ( V_46 , V_344 , V_372 ) ;
V_115:
return V_53 ;
}
static int F_207 ( struct V_45 * V_46 , struct V_343 * V_344 ,
struct V_371 * V_372 )
{
int V_379 , V_380 , V_250 = 0 ;
T_7 V_381 [ V_382 ] ;
V_380 = F_208 ( & V_381 [ 0 ] ) ;
V_381 [ V_380 ] = V_383 ;
V_380 += 1 ;
for ( V_379 = 0 ; V_379 < V_380 ; V_379 ++ ) {
V_250 = F_205 ( V_46 , V_344 , V_372 , V_381 [ V_379 ] ) ;
if ( V_250 == - V_4 || V_250 == - V_10 )
continue;
break;
}
if ( V_250 == - V_10 )
V_250 = - V_5 ;
return V_250 ;
}
int F_209 ( struct V_45 * V_46 , struct V_343 * V_344 ,
struct V_371 * V_372 )
{
int V_384 = V_46 -> V_31 -> V_385 ;
int V_250 = F_204 ( V_46 , V_344 , V_372 ) ;
if ( ( V_250 == - V_4 ) && ! ( V_46 -> V_176 & V_386 ) )
V_250 = V_387 [ V_384 ] -> F_210 ( V_46 , V_344 , V_372 ) ;
if ( V_250 == 0 )
V_250 = F_202 ( V_46 , V_344 ) ;
if ( V_250 == 0 )
V_250 = F_211 ( V_46 , V_344 , V_372 ) ;
return F_1 ( V_250 ) ;
}
static int F_212 ( struct V_45 * V_46 , struct V_343 * V_388 ,
struct V_371 * V_372 )
{
int error ;
struct V_317 * V_318 = V_372 -> V_318 ;
error = F_202 ( V_46 , V_388 ) ;
if ( error < 0 ) {
F_2 ( L_33 , - error ) ;
return error ;
}
error = F_213 ( V_46 , V_388 , V_318 ) ;
if ( error < 0 ) {
F_2 ( L_34 , - error ) ;
return error ;
}
if ( V_318 -> V_237 & V_389 &&
! F_214 ( & V_46 -> V_390 , & V_318 -> V_390 ) )
memcpy ( & V_46 -> V_390 , & V_318 -> V_390 , sizeof( V_46 -> V_390 ) ) ;
return error ;
}
static int F_215 ( struct V_38 * V_79 , struct V_52 * V_151 ,
const struct V_391 * V_195 , struct V_317 * V_318 ,
struct V_343 * V_344 )
{
int V_250 = - V_239 ;
struct V_392 * V_392 = NULL ;
struct V_393 * V_394 = NULL ;
V_392 = F_216 ( V_308 ) ;
if ( V_392 == NULL )
goto V_115;
V_394 = F_217 ( sizeof( struct V_393 ) , V_308 ) ;
if ( V_394 == NULL )
goto V_115;
V_250 = F_218 ( V_79 , V_151 , V_195 , V_394 , V_392 ) ;
if ( V_250 != 0 )
goto V_115;
if ( F_214 ( & F_77 ( V_151 ) -> V_390 , & V_394 -> V_318 . V_390 ) ) {
F_2 ( L_35
L_36 , V_13 , V_195 -> V_195 ) ;
V_250 = - V_14 ;
goto V_115;
}
F_219 ( & V_394 -> V_318 ) ;
memcpy ( V_318 , & V_394 -> V_318 , sizeof( struct V_317 ) ) ;
memset ( V_344 , 0 , sizeof( struct V_343 ) ) ;
V_115:
if ( V_392 )
F_220 ( V_392 ) ;
F_86 ( V_394 ) ;
return V_250 ;
}
static int F_159 ( struct V_45 * V_46 , struct V_343 * V_344 , struct V_317 * V_318 )
{
struct V_395 args = {
. V_186 = V_344 ,
. V_197 = V_46 -> V_198 ,
} ;
struct V_396 V_33 = {
. V_318 = V_318 ,
. V_46 = V_46 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_397 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
F_73 ( V_318 ) ;
return F_68 ( V_46 -> V_79 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
}
static int F_213 ( struct V_45 * V_46 , struct V_343 * V_344 , struct V_317 * V_318 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_46 ,
F_159 ( V_46 , V_344 , V_318 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int
F_221 ( struct V_17 * V_17 , struct V_317 * V_318 ,
struct V_177 * V_297 )
{
struct V_52 * V_52 = V_17 -> V_27 ;
struct V_260 * V_305 = NULL ;
struct V_50 * V_51 = NULL ;
int V_250 ;
if ( F_222 ( V_52 ) )
F_223 ( V_52 ) ;
F_73 ( V_318 ) ;
if ( V_297 -> V_203 & V_328 )
V_297 -> V_203 &= ~ ( V_304 | V_398 | V_328 ) ;
if ( ( V_297 -> V_203 & ~ ( V_399 ) ) == 0 )
return 0 ;
if ( V_297 -> V_203 & V_399 ) {
struct V_244 * V_245 ;
V_245 = F_224 ( V_297 -> V_400 ) ;
if ( V_245 ) {
V_305 = V_245 -> V_305 ;
V_51 = V_245 -> V_51 ;
}
}
V_250 = F_175 ( V_52 , V_305 , V_318 , V_297 , V_51 ) ;
if ( V_250 == 0 )
F_176 ( V_52 , V_297 ) ;
return V_250 ;
}
static int F_225 ( struct V_38 * V_39 , struct V_52 * V_151 ,
const struct V_391 * V_195 , struct V_343 * V_344 ,
struct V_317 * V_318 )
{
struct V_45 * V_46 = F_77 ( V_151 ) ;
int V_250 ;
struct V_401 args = {
. V_197 = V_46 -> V_198 ,
. V_402 = F_83 ( V_151 ) ,
. V_195 = V_195 ,
} ;
struct V_374 V_33 = {
. V_46 = V_46 ,
. V_318 = V_318 ,
. V_186 = V_344 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_403 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
F_73 ( V_318 ) ;
F_2 ( L_37 , V_195 -> V_195 ) ;
V_250 = F_68 ( V_39 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
F_2 ( L_38 , V_250 ) ;
return V_250 ;
}
static void F_226 ( struct V_317 * V_318 )
{
V_318 -> V_237 |= V_404 | V_405 |
V_406 | V_407 ;
V_318 -> V_211 = V_276 | V_408 | V_409 ;
V_318 -> V_410 = 2 ;
}
static int F_227 ( struct V_38 * * V_39 , struct V_52 * V_151 ,
struct V_391 * V_195 , struct V_343 * V_344 ,
struct V_317 * V_318 )
{
struct V_48 V_49 = { } ;
struct V_38 * V_79 = * V_39 ;
int V_1 ;
do {
V_1 = F_225 ( V_79 , V_151 , V_195 , V_344 , V_318 ) ;
switch ( V_1 ) {
case - V_7 :
V_1 = - V_246 ;
goto V_115;
case - V_411 :
V_1 = F_215 ( V_79 , V_151 , V_195 , V_318 , V_344 ) ;
goto V_115;
case - V_4 :
V_1 = - V_5 ;
if ( V_79 != * V_39 )
goto V_115;
V_79 = F_228 ( V_79 , V_151 , V_195 ) ;
if ( F_62 ( V_79 ) )
return F_63 ( V_79 ) ;
V_49 . V_54 = 1 ;
break;
default:
V_1 = F_16 ( F_77 ( V_151 ) , V_1 , & V_49 ) ;
}
} while ( V_49 . V_54 );
V_115:
if ( V_1 == 0 )
* V_39 = V_79 ;
else if ( V_79 != * V_39 )
F_229 ( V_79 ) ;
return V_1 ;
}
static int F_230 ( struct V_52 * V_151 , struct V_391 * V_195 ,
struct V_343 * V_344 , struct V_317 * V_318 )
{
int V_250 ;
struct V_38 * V_79 = F_231 ( V_151 ) ;
V_250 = F_227 ( & V_79 , V_151 , V_195 , V_344 , V_318 ) ;
if ( V_79 != F_231 ( V_151 ) ) {
F_229 ( V_79 ) ;
F_226 ( V_318 ) ;
}
return V_250 ;
}
struct V_38 *
F_232 ( struct V_52 * V_151 , struct V_391 * V_195 ,
struct V_343 * V_344 , struct V_317 * V_318 )
{
int V_250 ;
struct V_38 * V_79 = F_233 ( F_231 ( V_151 ) ) ;
V_250 = F_227 ( & V_79 , V_151 , V_195 , V_344 , V_318 ) ;
if ( V_250 < 0 ) {
F_229 ( V_79 ) ;
return F_119 ( V_250 ) ;
}
return V_79 ;
}
static int F_234 ( struct V_52 * V_52 , struct V_412 * V_413 )
{
struct V_45 * V_46 = F_77 ( V_52 ) ;
struct V_414 args = {
. V_186 = F_83 ( V_52 ) ,
. V_197 = V_46 -> V_340 ,
} ;
struct V_415 V_33 = {
. V_46 = V_46 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_416 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
. V_260 = V_413 -> V_305 ,
} ;
int V_211 = V_413 -> V_417 ;
int V_250 ;
if ( V_211 & V_418 )
args . V_419 |= V_420 ;
if ( F_235 ( V_52 -> V_421 ) ) {
if ( V_211 & V_422 )
args . V_419 |= V_423 | V_424 | V_425 ;
if ( V_211 & V_426 )
args . V_419 |= V_427 ;
} else {
if ( V_211 & V_422 )
args . V_419 |= V_423 | V_424 ;
if ( V_211 & V_426 )
args . V_419 |= V_428 ;
}
V_33 . V_318 = F_236 () ;
if ( V_33 . V_318 == NULL )
return - V_239 ;
V_250 = F_68 ( V_46 -> V_79 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
if ( ! V_250 ) {
V_413 -> V_417 = 0 ;
if ( V_33 . V_419 & V_420 )
V_413 -> V_417 |= V_418 ;
if ( V_33 . V_419 & ( V_423 | V_424 | V_425 ) )
V_413 -> V_417 |= V_422 ;
if ( V_33 . V_419 & ( V_427 | V_428 ) )
V_413 -> V_417 |= V_426 ;
F_192 ( V_52 , V_33 . V_318 ) ;
}
F_237 ( V_33 . V_318 ) ;
return V_250 ;
}
static int F_238 ( struct V_52 * V_52 , struct V_412 * V_413 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_52 ) ,
F_234 ( V_52 , V_413 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_239 ( struct V_52 * V_52 , struct V_392 * V_392 ,
unsigned int V_30 , unsigned int V_429 )
{
struct V_430 args = {
. V_186 = F_83 ( V_52 ) ,
. V_30 = V_30 ,
. V_429 = V_429 ,
. V_23 = & V_392 ,
} ;
struct V_431 V_33 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_432 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
return F_68 ( F_77 ( V_52 ) -> V_79 , F_77 ( V_52 ) , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
}
static int F_240 ( struct V_52 * V_52 , struct V_392 * V_392 ,
unsigned int V_30 , unsigned int V_429 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_52 ) ,
F_239 ( V_52 , V_392 , V_30 , V_429 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int
F_241 ( struct V_52 * V_151 , struct V_17 * V_17 , struct V_177 * V_297 ,
int V_176 , struct V_244 * V_245 )
{
struct V_17 * V_433 = V_17 ;
struct V_50 * V_51 ;
struct V_260 * V_305 = NULL ;
T_4 V_175 = 0 ;
int V_250 = 0 ;
if ( V_245 != NULL ) {
V_305 = V_245 -> V_305 ;
V_433 = V_245 -> V_17 ;
V_175 = V_245 -> V_211 ;
}
V_297 -> V_434 &= ~ F_242 () ;
V_51 = F_179 ( V_151 , V_433 , V_175 , V_176 , V_297 , V_305 , NULL ) ;
F_164 ( V_17 ) ;
if ( F_62 ( V_51 ) ) {
V_250 = F_63 ( V_51 ) ;
goto V_115;
}
F_243 ( V_17 , F_198 ( V_51 -> V_52 ) ) ;
F_244 ( V_17 , F_245 ( V_151 ) ) ;
if ( V_245 != NULL )
V_245 -> V_51 = V_51 ;
else
F_200 ( V_51 , V_175 ) ;
V_115:
return V_250 ;
}
static int F_246 ( struct V_52 * V_151 , struct V_391 * V_195 )
{
struct V_45 * V_46 = F_77 ( V_151 ) ;
struct V_435 args = {
. V_186 = F_83 ( V_151 ) ,
. V_195 = * V_195 ,
} ;
struct V_436 V_33 = {
. V_46 = V_46 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_437 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
int V_250 ;
V_250 = F_68 ( V_46 -> V_79 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 1 ) ;
if ( V_250 == 0 )
F_69 ( V_151 , & V_33 . V_153 ) ;
return V_250 ;
}
static int F_247 ( struct V_52 * V_151 , struct V_391 * V_195 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_151 ) ,
F_246 ( V_151 , V_195 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static void F_248 ( struct V_138 * V_139 , struct V_52 * V_151 )
{
struct V_45 * V_46 = F_77 ( V_151 ) ;
struct V_435 * args = V_139 -> V_258 ;
struct V_436 * V_33 = V_139 -> V_259 ;
V_33 -> V_46 = V_46 ;
V_139 -> V_255 = & V_256 [ V_437 ] ;
F_49 ( & args -> V_136 , & V_33 -> V_137 , 1 ) ;
}
static void F_249 ( struct V_97 * V_98 , struct V_438 * V_134 )
{
if ( F_54 ( F_77 ( V_134 -> V_151 ) ,
& V_134 -> args . V_136 ,
& V_134 -> V_33 . V_137 ,
V_98 ) )
return;
F_57 ( V_98 ) ;
}
static int F_250 ( struct V_97 * V_98 , struct V_52 * V_151 )
{
struct V_436 * V_33 = V_98 -> V_269 . V_259 ;
if ( ! F_45 ( V_98 , & V_33 -> V_137 ) )
return 0 ;
if ( F_189 ( V_98 , V_33 -> V_46 , NULL ) == - V_128 )
return 0 ;
F_69 ( V_151 , & V_33 -> V_153 ) ;
return 1 ;
}
static void F_251 ( struct V_138 * V_139 , struct V_52 * V_151 )
{
struct V_45 * V_46 = F_77 ( V_151 ) ;
struct V_439 * V_320 = V_139 -> V_258 ;
struct V_440 * V_33 = V_139 -> V_259 ;
V_139 -> V_255 = & V_256 [ V_441 ] ;
V_33 -> V_46 = V_46 ;
F_49 ( & V_320 -> V_136 , & V_33 -> V_137 , 1 ) ;
}
static void F_252 ( struct V_97 * V_98 , struct V_442 * V_134 )
{
if ( F_54 ( F_77 ( V_134 -> V_443 ) ,
& V_134 -> args . V_136 ,
& V_134 -> V_33 . V_137 ,
V_98 ) )
return;
F_57 ( V_98 ) ;
}
static int F_253 ( struct V_97 * V_98 , struct V_52 * V_443 ,
struct V_52 * V_444 )
{
struct V_440 * V_33 = V_98 -> V_269 . V_259 ;
if ( ! F_45 ( V_98 , & V_33 -> V_137 ) )
return 0 ;
if ( F_189 ( V_98 , V_33 -> V_46 , NULL ) == - V_128 )
return 0 ;
F_69 ( V_443 , & V_33 -> V_445 ) ;
F_69 ( V_444 , & V_33 -> V_446 ) ;
return 1 ;
}
static int F_254 ( struct V_52 * V_443 , struct V_391 * V_447 ,
struct V_52 * V_444 , struct V_391 * V_448 )
{
struct V_45 * V_46 = F_77 ( V_443 ) ;
struct V_439 V_320 = {
. V_443 = F_83 ( V_443 ) ,
. V_444 = F_83 ( V_444 ) ,
. V_447 = V_447 ,
. V_448 = V_448 ,
} ;
struct V_440 V_33 = {
. V_46 = V_46 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_441 ] ,
. V_258 = & V_320 ,
. V_259 = & V_33 ,
} ;
int V_250 = - V_239 ;
V_250 = F_68 ( V_46 -> V_79 , V_46 , & V_139 , & V_320 . V_136 , & V_33 . V_137 , 1 ) ;
if ( ! V_250 ) {
F_69 ( V_443 , & V_33 . V_445 ) ;
F_69 ( V_444 , & V_33 . V_446 ) ;
}
return V_250 ;
}
static int F_255 ( struct V_52 * V_443 , struct V_391 * V_447 ,
struct V_52 * V_444 , struct V_391 * V_448 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_443 ) ,
F_254 ( V_443 , V_447 ,
V_444 , V_448 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_256 ( struct V_52 * V_52 , struct V_52 * V_151 , struct V_391 * V_195 )
{
struct V_45 * V_46 = F_77 ( V_52 ) ;
struct V_449 V_320 = {
. V_186 = F_83 ( V_52 ) ,
. V_402 = F_83 ( V_151 ) ,
. V_195 = V_195 ,
. V_197 = V_46 -> V_198 ,
} ;
struct V_450 V_33 = {
. V_46 = V_46 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_451 ] ,
. V_258 = & V_320 ,
. V_259 = & V_33 ,
} ;
int V_250 = - V_239 ;
V_33 . V_318 = F_236 () ;
if ( V_33 . V_318 == NULL )
goto V_115;
V_250 = F_68 ( V_46 -> V_79 , V_46 , & V_139 , & V_320 . V_136 , & V_33 . V_137 , 1 ) ;
if ( ! V_250 ) {
F_69 ( V_151 , & V_33 . V_153 ) ;
F_177 ( V_52 , V_33 . V_318 ) ;
}
V_115:
F_237 ( V_33 . V_318 ) ;
return V_250 ;
}
static int F_257 ( struct V_52 * V_52 , struct V_52 * V_151 , struct V_391 * V_195 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_52 ) ,
F_256 ( V_52 , V_151 , V_195 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static struct V_452 * F_258 ( struct V_52 * V_151 ,
struct V_391 * V_195 , struct V_177 * V_297 , T_3 V_453 )
{
struct V_452 * V_134 ;
V_134 = F_78 ( sizeof( * V_134 ) , V_308 ) ;
if ( V_134 != NULL ) {
struct V_45 * V_46 = F_77 ( V_151 ) ;
V_134 -> V_139 . V_255 = & V_256 [ V_454 ] ;
V_134 -> V_139 . V_258 = & V_134 -> V_320 ;
V_134 -> V_139 . V_259 = & V_134 -> V_33 ;
V_134 -> V_320 . V_402 = F_83 ( V_151 ) ;
V_134 -> V_320 . V_46 = V_46 ;
V_134 -> V_320 . V_195 = V_195 ;
V_134 -> V_320 . V_178 = V_297 ;
V_134 -> V_320 . V_453 = V_453 ;
V_134 -> V_320 . V_197 = V_46 -> V_198 ;
V_134 -> V_33 . V_46 = V_46 ;
V_134 -> V_33 . V_186 = & V_134 -> V_186 ;
V_134 -> V_33 . V_318 = & V_134 -> V_318 ;
F_73 ( V_134 -> V_33 . V_318 ) ;
}
return V_134 ;
}
static int F_259 ( struct V_52 * V_151 , struct V_17 * V_17 , struct V_452 * V_134 )
{
int V_250 = F_68 ( F_77 ( V_151 ) -> V_79 , F_77 ( V_151 ) , & V_134 -> V_139 ,
& V_134 -> V_320 . V_136 , & V_134 -> V_33 . V_137 , 1 ) ;
if ( V_250 == 0 ) {
F_69 ( V_151 , & V_134 -> V_33 . V_455 ) ;
V_250 = F_260 ( V_17 , V_134 -> V_33 . V_186 , V_134 -> V_33 . V_318 ) ;
}
return V_250 ;
}
static void F_261 ( struct V_452 * V_134 )
{
F_86 ( V_134 ) ;
}
static int F_262 ( struct V_52 * V_151 , struct V_17 * V_17 ,
struct V_392 * V_392 , unsigned int V_380 , struct V_177 * V_297 )
{
struct V_452 * V_134 ;
int V_250 = - V_456 ;
if ( V_380 > V_457 )
goto V_115;
V_250 = - V_239 ;
V_134 = F_258 ( V_151 , & V_17 -> V_196 , V_297 , V_458 ) ;
if ( V_134 == NULL )
goto V_115;
V_134 -> V_139 . V_255 = & V_256 [ V_459 ] ;
V_134 -> V_320 . V_205 . V_460 . V_23 = & V_392 ;
V_134 -> V_320 . V_205 . V_460 . V_380 = V_380 ;
V_250 = F_259 ( V_151 , V_17 , V_134 ) ;
F_261 ( V_134 ) ;
V_115:
return V_250 ;
}
static int F_263 ( struct V_52 * V_151 , struct V_17 * V_17 ,
struct V_392 * V_392 , unsigned int V_380 , struct V_177 * V_297 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_151 ) ,
F_262 ( V_151 , V_17 , V_392 ,
V_380 , V_297 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_264 ( struct V_52 * V_151 , struct V_17 * V_17 ,
struct V_177 * V_297 )
{
struct V_452 * V_134 ;
int V_250 = - V_239 ;
V_134 = F_258 ( V_151 , & V_17 -> V_196 , V_297 , V_461 ) ;
if ( V_134 == NULL )
goto V_115;
V_250 = F_259 ( V_151 , V_17 , V_134 ) ;
F_261 ( V_134 ) ;
V_115:
return V_250 ;
}
static int F_265 ( struct V_52 * V_151 , struct V_17 * V_17 ,
struct V_177 * V_297 )
{
struct V_48 V_49 = { } ;
int V_1 ;
V_297 -> V_434 &= ~ F_242 () ;
do {
V_1 = F_16 ( F_77 ( V_151 ) ,
F_264 ( V_151 , V_17 , V_297 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_266 ( struct V_17 * V_17 , struct V_260 * V_305 ,
T_1 V_15 , struct V_392 * * V_23 , unsigned int V_22 , int V_462 )
{
struct V_52 * V_151 = V_17 -> V_27 ;
struct V_18 args = {
. V_186 = F_83 ( V_151 ) ,
. V_23 = V_23 ,
. V_30 = 0 ,
. V_22 = V_22 ,
. V_197 = F_77 ( V_17 -> V_27 ) -> V_198 ,
. V_462 = V_462 ,
} ;
struct V_463 V_33 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_464 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
. V_260 = V_305 ,
} ;
int V_250 ;
F_2 ( L_39 , V_13 ,
V_17 -> V_29 -> V_196 . V_195 ,
V_17 -> V_196 . V_195 ,
( unsigned long long ) V_15 ) ;
F_3 ( V_15 , F_267 ( V_151 ) , V_17 , & args ) ;
V_33 . V_30 = args . V_30 ;
V_250 = F_68 ( F_77 ( V_151 ) -> V_79 , F_77 ( V_151 ) , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
if ( V_250 >= 0 ) {
memcpy ( F_267 ( V_151 ) , V_33 . V_16 . V_134 , V_465 ) ;
V_250 += args . V_30 ;
}
F_268 ( V_151 ) ;
F_2 ( L_40 , V_13 , V_250 ) ;
return V_250 ;
}
static int F_269 ( struct V_17 * V_17 , struct V_260 * V_305 ,
T_1 V_15 , struct V_392 * * V_23 , unsigned int V_22 , int V_462 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_17 -> V_27 ) ,
F_266 ( V_17 , V_305 , V_15 ,
V_23 , V_22 , V_462 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_270 ( struct V_52 * V_151 , struct V_17 * V_17 ,
struct V_177 * V_297 , T_8 V_466 )
{
struct V_452 * V_134 ;
int V_211 = V_297 -> V_434 ;
int V_250 = - V_239 ;
F_4 ( ! ( V_297 -> V_203 & V_467 ) ) ;
F_4 ( ! F_271 ( V_211 ) && ! F_272 ( V_211 ) && ! F_273 ( V_211 ) && ! F_274 ( V_211 ) ) ;
V_134 = F_258 ( V_151 , & V_17 -> V_196 , V_297 , V_468 ) ;
if ( V_134 == NULL )
goto V_115;
if ( F_271 ( V_211 ) )
V_134 -> V_320 . V_453 = V_469 ;
else if ( F_272 ( V_211 ) ) {
V_134 -> V_320 . V_453 = V_470 ;
V_134 -> V_320 . V_205 . V_471 . V_472 = F_275 ( V_466 ) ;
V_134 -> V_320 . V_205 . V_471 . V_473 = F_276 ( V_466 ) ;
}
else if ( F_273 ( V_211 ) ) {
V_134 -> V_320 . V_453 = V_474 ;
V_134 -> V_320 . V_205 . V_471 . V_472 = F_275 ( V_466 ) ;
V_134 -> V_320 . V_205 . V_471 . V_473 = F_276 ( V_466 ) ;
}
V_250 = F_259 ( V_151 , V_17 , V_134 ) ;
F_261 ( V_134 ) ;
V_115:
return V_250 ;
}
static int F_277 ( struct V_52 * V_151 , struct V_17 * V_17 ,
struct V_177 * V_297 , T_8 V_466 )
{
struct V_48 V_49 = { } ;
int V_1 ;
V_297 -> V_434 &= ~ F_242 () ;
do {
V_1 = F_16 ( F_77 ( V_151 ) ,
F_270 ( V_151 , V_17 , V_297 , V_466 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_278 ( struct V_45 * V_46 , struct V_343 * V_344 ,
struct V_475 * V_476 )
{
struct V_477 args = {
. V_186 = V_344 ,
. V_197 = V_46 -> V_198 ,
} ;
struct V_478 V_33 = {
. V_476 = V_476 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_479 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
F_73 ( V_476 -> V_318 ) ;
return F_68 ( V_46 -> V_79 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
}
static int F_279 ( struct V_45 * V_46 , struct V_343 * V_344 , struct V_475 * V_476 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_46 ,
F_278 ( V_46 , V_344 , V_476 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_280 ( struct V_45 * V_46 , struct V_343 * V_344 ,
struct V_371 * V_480 )
{
struct V_481 args = {
. V_186 = V_344 ,
. V_197 = V_46 -> V_198 ,
} ;
struct V_482 V_33 = {
. V_480 = V_480 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_483 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
return F_68 ( V_46 -> V_79 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
}
static int F_211 ( struct V_45 * V_46 , struct V_343 * V_344 , struct V_371 * V_480 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_46 ,
F_280 ( V_46 , V_344 , V_480 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_281 ( struct V_45 * V_46 , struct V_343 * V_344 , struct V_371 * V_480 )
{
F_73 ( V_480 -> V_318 ) ;
return F_211 ( V_46 , V_344 , V_480 ) ;
}
static int F_282 ( struct V_45 * V_46 , struct V_343 * V_344 ,
struct V_484 * V_485 )
{
struct V_486 args = {
. V_186 = V_344 ,
. V_197 = V_46 -> V_198 ,
} ;
struct V_487 V_33 = {
. V_485 = V_485 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_488 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
if ( ( args . V_197 [ 0 ] & V_489 [ 0 ] ) == 0 ) {
memset ( V_485 , 0 , sizeof( * V_485 ) ) ;
return 0 ;
}
F_73 ( V_485 -> V_318 ) ;
return F_68 ( V_46 -> V_79 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
}
static int F_283 ( struct V_45 * V_46 , struct V_343 * V_344 ,
struct V_484 * V_485 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_46 ,
F_282 ( V_46 , V_344 , V_485 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
void F_284 ( struct V_490 * V_134 )
{
F_268 ( V_134 -> V_491 -> V_52 ) ;
}
static int F_285 ( struct V_97 * V_98 , struct V_490 * V_134 )
{
struct V_45 * V_46 = F_77 ( V_134 -> V_491 -> V_52 ) ;
if ( F_189 ( V_98 , V_46 , V_134 -> args . V_492 -> V_51 ) == - V_128 ) {
F_190 ( V_98 ) ;
return - V_128 ;
}
F_284 ( V_134 ) ;
if ( V_98 -> V_148 > 0 )
F_29 ( V_46 , V_134 -> V_86 ) ;
return 0 ;
}
static int F_286 ( struct V_97 * V_98 , struct V_490 * V_134 )
{
F_2 ( L_17 , V_13 ) ;
if ( ! F_45 ( V_98 , & V_134 -> V_33 . V_137 ) )
return - V_128 ;
return V_134 -> V_493 ? V_134 -> V_493 ( V_98 , V_134 ) :
F_285 ( V_98 , V_134 ) ;
}
static void F_287 ( struct V_490 * V_134 , struct V_138 * V_139 )
{
V_134 -> V_86 = V_131 ;
V_134 -> V_493 = F_285 ;
V_139 -> V_255 = & V_256 [ V_494 ] ;
F_49 ( & V_134 -> args . V_136 , & V_134 -> V_33 . V_137 , 0 ) ;
}
static void F_288 ( struct V_97 * V_98 , struct V_490 * V_134 )
{
if ( F_54 ( F_77 ( V_134 -> V_491 -> V_52 ) ,
& V_134 -> args . V_136 ,
& V_134 -> V_33 . V_137 ,
V_98 ) )
return;
F_57 ( V_98 ) ;
}
static int F_289 ( struct V_97 * V_98 , struct V_495 * V_134 )
{
struct V_52 * V_52 = V_134 -> V_491 -> V_52 ;
if ( F_189 ( V_98 , F_77 ( V_52 ) , V_134 -> args . V_492 -> V_51 ) == - V_128 ) {
F_190 ( V_98 ) ;
return - V_128 ;
}
if ( V_98 -> V_148 >= 0 ) {
F_29 ( F_77 ( V_52 ) , V_134 -> V_86 ) ;
F_290 ( V_52 , & V_134 -> V_318 ) ;
}
return 0 ;
}
static int F_291 ( struct V_97 * V_98 , struct V_495 * V_134 )
{
if ( ! F_45 ( V_98 , & V_134 -> V_33 . V_137 ) )
return - V_128 ;
return V_134 -> V_496 ? V_134 -> V_496 ( V_98 , V_134 ) :
F_289 ( V_98 , V_134 ) ;
}
static
bool F_292 ( const struct V_495 * V_134 )
{
const struct V_497 * V_498 = V_134 -> V_491 ;
if ( V_134 -> V_499 != NULL || V_498 -> V_500 != NULL )
return false ;
return F_17 ( V_498 -> V_52 , V_56 ) == 0 ;
}
static void F_293 ( struct V_495 * V_134 , struct V_138 * V_139 )
{
struct V_45 * V_46 = F_77 ( V_134 -> V_491 -> V_52 ) ;
if ( ! F_292 ( V_134 ) ) {
V_134 -> args . V_197 = NULL ;
V_134 -> V_33 . V_318 = NULL ;
} else
V_134 -> args . V_197 = V_46 -> V_340 ;
if ( ! V_134 -> V_496 )
V_134 -> V_496 = F_289 ;
V_134 -> V_33 . V_46 = V_46 ;
V_134 -> V_86 = V_131 ;
V_139 -> V_255 = & V_256 [ V_501 ] ;
F_49 ( & V_134 -> args . V_136 , & V_134 -> V_33 . V_137 , 1 ) ;
}
static void F_294 ( struct V_97 * V_98 , struct V_495 * V_134 )
{
if ( F_54 ( F_77 ( V_134 -> V_491 -> V_52 ) ,
& V_134 -> args . V_136 ,
& V_134 -> V_33 . V_137 ,
V_98 ) )
return;
F_57 ( V_98 ) ;
}
static void F_295 ( struct V_97 * V_98 , struct V_502 * V_134 )
{
if ( F_54 ( F_77 ( V_134 -> V_52 ) ,
& V_134 -> args . V_136 ,
& V_134 -> V_33 . V_137 ,
V_98 ) )
return;
F_57 ( V_98 ) ;
}
static int F_296 ( struct V_97 * V_98 , struct V_502 * V_134 )
{
struct V_52 * V_52 = V_134 -> V_52 ;
if ( F_189 ( V_98 , F_77 ( V_52 ) , NULL ) == - V_128 ) {
F_190 ( V_98 ) ;
return - V_128 ;
}
return 0 ;
}
static int F_297 ( struct V_97 * V_98 , struct V_502 * V_134 )
{
if ( ! F_45 ( V_98 , & V_134 -> V_33 . V_137 ) )
return - V_128 ;
return V_134 -> V_503 ( V_98 , V_134 ) ;
}
static void F_298 ( struct V_502 * V_134 , struct V_138 * V_139 )
{
struct V_45 * V_46 = F_77 ( V_134 -> V_52 ) ;
if ( V_134 -> V_503 == NULL )
V_134 -> V_503 = F_296 ;
V_134 -> V_33 . V_46 = V_46 ;
V_139 -> V_255 = & V_256 [ V_504 ] ;
F_49 ( & V_134 -> args . V_136 , & V_134 -> V_33 . V_137 , 1 ) ;
}
static void F_299 ( void * V_132 )
{
struct V_505 * V_134 = V_132 ;
struct V_31 * V_32 = V_134 -> V_79 ;
if ( F_300 ( & V_32 -> V_506 ) > 1 )
F_301 ( V_32 ) ;
F_302 ( V_32 ) ;
F_86 ( V_134 ) ;
}
static void F_303 ( struct V_97 * V_98 , void * V_132 )
{
struct V_505 * V_134 = V_132 ;
struct V_31 * V_32 = V_134 -> V_79 ;
unsigned long V_86 = V_134 -> V_86 ;
if ( V_98 -> V_148 < 0 ) {
if ( F_36 ( V_507 , & V_32 -> V_508 ) == 0 )
return;
if ( V_98 -> V_148 != V_509 ) {
F_21 ( V_32 ) ;
return;
}
F_304 ( V_32 ) ;
}
F_25 ( V_32 , V_86 ) ;
}
static int F_305 ( struct V_31 * V_32 , struct V_260 * V_305 , unsigned V_510 )
{
struct V_138 V_139 = {
. V_255 = & V_256 [ V_511 ] ,
. V_258 = V_32 ,
. V_260 = V_305 ,
} ;
struct V_505 * V_134 ;
if ( V_510 == 0 )
return 0 ;
if ( ! F_306 ( & V_32 -> V_506 ) )
return - V_14 ;
V_134 = F_217 ( sizeof( * V_134 ) , V_247 ) ;
if ( V_134 == NULL )
return - V_239 ;
V_134 -> V_79 = V_32 ;
V_134 -> V_86 = V_131 ;
return F_307 ( V_32 -> V_512 , & V_139 , V_513 ,
& V_514 , V_134 ) ;
}
static int F_308 ( struct V_31 * V_32 , struct V_260 * V_305 )
{
struct V_138 V_139 = {
. V_255 = & V_256 [ V_511 ] ,
. V_258 = V_32 ,
. V_260 = V_305 ,
} ;
unsigned long V_515 = V_131 ;
int V_250 ;
V_250 = F_67 ( V_32 -> V_512 , & V_139 , 0 ) ;
if ( V_250 < 0 )
return V_250 ;
F_25 ( V_32 , V_515 ) ;
return 0 ;
}
static inline int F_309 ( struct V_45 * V_46 )
{
return ( V_46 -> V_82 & V_348 )
&& ( V_46 -> V_369 & V_516 )
&& ( V_46 -> V_369 & V_517 ) ;
}
static int F_310 ( const void * V_518 , T_9 V_519 ,
struct V_392 * * V_23 , unsigned int * V_30 )
{
struct V_392 * V_520 , * * V_521 ;
int V_522 = 0 ;
T_9 V_380 ;
V_521 = V_23 ;
do {
V_380 = F_311 ( T_9 , V_523 , V_519 ) ;
V_520 = F_216 ( V_308 ) ;
if ( V_520 == NULL )
goto V_524;
memcpy ( F_312 ( V_520 ) , V_518 , V_380 ) ;
V_518 += V_380 ;
V_519 -= V_380 ;
* V_23 ++ = V_520 ;
V_522 ++ ;
} while ( V_519 != 0 );
return V_522 ;
V_524:
for(; V_522 > 0 ; V_522 -- )
F_220 ( V_521 [ V_522 - 1 ] ) ;
return - V_239 ;
}
static void F_313 ( struct V_52 * V_52 , struct V_525 * V_526 )
{
struct V_154 * V_155 = F_70 ( V_52 ) ;
F_26 ( & V_52 -> V_156 ) ;
F_86 ( V_155 -> V_527 ) ;
V_155 -> V_527 = V_526 ;
F_28 ( & V_52 -> V_156 ) ;
}
static void F_314 ( struct V_52 * V_52 )
{
F_313 ( V_52 , NULL ) ;
}
static inline T_10 F_315 ( struct V_52 * V_52 , char * V_518 , T_9 V_519 )
{
struct V_154 * V_155 = F_70 ( V_52 ) ;
struct V_525 * V_526 ;
int V_53 = - V_246 ;
F_26 ( & V_52 -> V_156 ) ;
V_526 = V_155 -> V_527 ;
if ( V_526 == NULL )
goto V_115;
if ( V_518 == NULL )
goto V_528;
if ( V_526 -> V_529 == 0 )
goto V_115;
V_53 = - V_530 ;
if ( V_526 -> V_380 > V_519 )
goto V_115;
memcpy ( V_518 , V_526 -> V_134 , V_526 -> V_380 ) ;
V_528:
V_53 = V_526 -> V_380 ;
V_115:
F_28 ( & V_52 -> V_156 ) ;
return V_53 ;
}
static void F_316 ( struct V_52 * V_52 , struct V_392 * * V_23 , T_9 V_30 , T_9 V_531 )
{
struct V_525 * V_526 ;
if ( V_23 && V_531 <= V_532 ) {
V_526 = F_217 ( sizeof( * V_526 ) + V_531 , V_308 ) ;
if ( V_526 == NULL )
goto V_115;
V_526 -> V_529 = 1 ;
F_317 ( V_526 -> V_134 , V_23 , V_30 , V_531 ) ;
} else {
V_526 = F_217 ( sizeof( * V_526 ) , V_308 ) ;
if ( V_526 == NULL )
goto V_115;
V_526 -> V_529 = 0 ;
}
V_526 -> V_380 = V_531 ;
V_115:
F_313 ( V_52 , V_526 ) ;
}
static T_10 F_318 ( struct V_52 * V_52 , void * V_518 , T_9 V_519 )
{
struct V_392 * V_23 [ V_533 ] = { NULL , } ;
struct V_534 args = {
. V_186 = F_83 ( V_52 ) ,
. V_535 = V_23 ,
. V_531 = V_519 ,
} ;
struct V_536 V_33 = {
. V_531 = V_519 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_537 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
int V_53 = - V_239 , V_538 , V_379 , V_531 = 0 ;
V_538 = ( V_519 + V_532 - 1 ) >> V_539 ;
if ( V_538 == 0 )
V_538 = 1 ;
V_538 ++ ;
for ( V_379 = 0 ; V_379 < V_538 ; V_379 ++ ) {
V_23 [ V_379 ] = F_216 ( V_308 ) ;
if ( ! V_23 [ V_379 ] )
goto V_254;
}
V_33 . V_540 = F_216 ( V_308 ) ;
if ( ! V_33 . V_540 )
goto V_254;
args . V_531 = V_538 * V_532 ;
args . V_541 = 0 ;
if ( V_518 == NULL )
V_33 . V_542 |= V_543 ;
F_2 ( L_41 ,
V_13 , V_518 , V_519 , V_538 , args . V_531 ) ;
V_53 = F_68 ( F_77 ( V_52 ) -> V_79 , F_77 ( V_52 ) ,
& V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
if ( V_53 )
goto V_254;
V_531 = V_33 . V_531 - V_33 . V_544 ;
if ( V_531 > args . V_531 )
F_316 ( V_52 , NULL , 0 , V_531 ) ;
else
F_316 ( V_52 , V_23 , V_33 . V_544 ,
V_531 ) ;
if ( V_518 ) {
V_53 = - V_530 ;
if ( V_531 > V_519 )
goto V_254;
F_317 ( V_518 , V_23 , V_33 . V_544 ,
V_531 ) ;
}
V_53 = V_531 ;
V_254:
for ( V_379 = 0 ; V_379 < V_538 ; V_379 ++ )
if ( V_23 [ V_379 ] )
F_220 ( V_23 [ V_379 ] ) ;
if ( V_33 . V_540 )
F_220 ( V_33 . V_540 ) ;
return V_53 ;
}
static T_10 F_319 ( struct V_52 * V_52 , void * V_518 , T_9 V_519 )
{
struct V_48 V_49 = { } ;
T_10 V_53 ;
do {
V_53 = F_318 ( V_52 , V_518 , V_519 ) ;
if ( V_53 >= 0 )
break;
V_53 = F_16 ( F_77 ( V_52 ) , V_53 , & V_49 ) ;
} while ( V_49 . V_54 );
return V_53 ;
}
static T_10 F_320 ( struct V_52 * V_52 , void * V_518 , T_9 V_519 )
{
struct V_45 * V_46 = F_77 ( V_52 ) ;
int V_53 ;
if ( ! F_309 ( V_46 ) )
return - V_545 ;
V_53 = F_321 ( V_46 , V_52 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_70 ( V_52 ) -> V_157 & V_546 )
F_322 ( V_52 ) ;
V_53 = F_315 ( V_52 , V_518 , V_519 ) ;
if ( V_53 != - V_246 )
return V_53 ;
return F_319 ( V_52 , V_518 , V_519 ) ;
}
static int F_323 ( struct V_52 * V_52 , const void * V_518 , T_9 V_519 )
{
struct V_45 * V_46 = F_77 ( V_52 ) ;
struct V_392 * V_23 [ V_533 ] ;
struct V_547 V_320 = {
. V_186 = F_83 ( V_52 ) ,
. V_535 = V_23 ,
. V_531 = V_519 ,
} ;
struct V_548 V_33 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_549 ] ,
. V_258 = & V_320 ,
. V_259 = & V_33 ,
} ;
int V_53 , V_379 ;
if ( ! F_309 ( V_46 ) )
return - V_545 ;
V_379 = F_310 ( V_518 , V_519 , V_320 . V_535 , & V_320 . V_541 ) ;
if ( V_379 < 0 )
return V_379 ;
F_18 ( V_52 ) ;
V_53 = F_68 ( V_46 -> V_79 , V_46 , & V_139 , & V_320 . V_136 , & V_33 . V_137 , 1 ) ;
for (; V_379 > 0 ; V_379 -- )
F_324 ( V_23 [ V_379 - 1 ] ) ;
F_26 ( & V_52 -> V_156 ) ;
F_70 ( V_52 ) -> V_157 |= V_158 ;
F_28 ( & V_52 -> V_156 ) ;
F_325 ( V_52 ) ;
F_322 ( V_52 ) ;
return V_53 ;
}
static int F_326 ( struct V_52 * V_52 , const void * V_518 , T_9 V_519 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_52 ) ,
F_323 ( V_52 , V_518 , V_519 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int
F_189 ( struct V_97 * V_98 , const struct V_45 * V_46 , struct V_50 * V_51 )
{
struct V_31 * V_32 = V_46 -> V_31 ;
if ( V_98 -> V_148 >= 0 )
return 0 ;
switch( V_98 -> V_148 ) {
case - V_58 :
case - V_59 :
case - V_60 :
if ( V_51 == NULL )
break;
F_20 ( V_51 -> V_52 ) ;
case - V_55 :
if ( V_51 == NULL )
break;
F_19 ( V_46 , V_51 ) ;
goto V_57;
case - V_61 :
if ( V_51 != NULL )
F_19 ( V_46 , V_51 ) ;
case - V_62 :
case - V_63 :
F_21 ( V_32 ) ;
goto V_57;
#if F_22 ( V_64 )
case - V_65 :
case - V_66 :
case - V_67 :
case - V_69 :
case - V_68 :
case - V_70 :
case - V_71 :
F_2 ( L_42 , V_13 ,
V_98 -> V_148 ) ;
F_23 ( V_32 -> V_72 , V_98 -> V_148 ) ;
V_98 -> V_148 = 0 ;
return - V_128 ;
#endif
case - V_77 :
F_327 ( V_46 , V_550 ) ;
case - V_76 :
case - V_78 :
F_44 ( V_98 , V_42 ) ;
V_98 -> V_148 = 0 ;
return - V_128 ;
case - V_80 :
case - V_81 :
V_98 -> V_148 = 0 ;
return - V_128 ;
}
V_98 -> V_148 = F_1 ( V_98 -> V_148 ) ;
return 0 ;
V_57:
F_52 ( & V_32 -> V_551 , V_98 , NULL ) ;
if ( F_36 ( V_35 , & V_32 -> V_34 ) == 0 )
F_328 ( & V_32 -> V_551 , V_98 ) ;
V_98 -> V_148 = 0 ;
return - V_128 ;
}
static void F_329 ( const struct V_31 * V_32 ,
T_11 * V_552 )
{
T_2 V_204 [ 2 ] ;
if ( F_36 ( V_553 , & V_32 -> V_34 ) ) {
V_204 [ 0 ] = 0 ;
V_204 [ 1 ] = ( T_2 ) ( V_554 + 1 ) ;
} else {
struct V_555 * V_556 = F_330 ( V_32 -> V_557 , V_558 ) ;
V_204 [ 0 ] = ( T_2 ) V_556 -> V_559 . V_560 ;
V_204 [ 1 ] = ( T_2 ) V_556 -> V_559 . V_561 ;
}
memcpy ( V_552 -> V_134 , V_204 , sizeof( V_552 -> V_134 ) ) ;
}
int F_331 ( struct V_31 * V_32 , T_3 V_562 ,
unsigned short V_563 , struct V_260 * V_305 ,
struct V_564 * V_33 )
{
T_11 V_565 ;
struct V_566 V_567 = {
. V_565 = & V_565 ,
. V_568 = V_562 ,
. V_569 = V_32 -> V_570 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_571 ] ,
. V_258 = & V_567 ,
. V_259 = V_33 ,
. V_260 = V_305 ,
} ;
int V_290 = 0 ;
int V_250 ;
F_329 ( V_32 , & V_565 ) ;
for(; ; ) {
F_112 () ;
V_567 . V_572 = F_332 ( V_567 . V_573 ,
sizeof( V_567 . V_573 ) , L_43 ,
V_32 -> V_574 ,
F_333 ( V_32 -> V_512 ,
V_575 ) ,
F_333 ( V_32 -> V_512 ,
V_576 ) ,
V_32 -> V_512 -> V_577 -> V_578 -> V_579 ,
V_32 -> V_580 ) ;
V_567 . V_581 = F_332 ( V_567 . V_582 ,
sizeof( V_567 . V_582 ) ,
F_333 ( V_32 -> V_512 ,
V_583 ) ) ;
V_567 . V_584 = F_332 ( V_567 . V_585 ,
sizeof( V_567 . V_585 ) , L_44 ,
V_32 -> V_574 , V_563 >> 8 , V_563 & 255 ) ;
F_115 () ;
V_250 = F_67 ( V_32 -> V_512 , & V_139 , V_586 ) ;
if ( V_250 != - V_587 )
break;
if ( V_290 != 0 ) {
++ V_32 -> V_580 ;
break;
}
++ V_290 ;
F_334 ( V_32 -> V_588 / V_74 + 1 ) ;
}
return V_250 ;
}
int F_335 ( struct V_31 * V_32 ,
struct V_564 * V_320 ,
struct V_260 * V_305 )
{
struct V_371 V_480 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_589 ] ,
. V_258 = V_320 ,
. V_259 = & V_480 ,
. V_260 = V_305 ,
} ;
unsigned long V_515 ;
int V_250 ;
V_515 = V_131 ;
V_250 = F_67 ( V_32 -> V_512 , & V_139 , V_586 ) ;
if ( V_250 == 0 ) {
F_26 ( & V_32 -> V_87 ) ;
V_32 -> V_588 = V_480 . V_590 * V_74 ;
V_32 -> V_88 = V_515 ;
F_28 ( & V_32 -> V_87 ) ;
}
return V_250 ;
}
static void F_336 ( struct V_97 * V_98 , void * V_132 )
{
struct V_591 * V_134 = V_132 ;
if ( ! F_45 ( V_98 , & V_134 -> V_33 . V_137 ) )
return;
switch ( V_98 -> V_148 ) {
case - V_62 :
case - V_61 :
case 0 :
F_29 ( V_134 -> V_33 . V_46 , V_134 -> V_86 ) ;
break;
default:
if ( F_189 ( V_98 , V_134 -> V_33 . V_46 , NULL ) ==
- V_128 ) {
F_190 ( V_98 ) ;
return;
}
}
V_134 -> V_252 = V_98 -> V_148 ;
}
static void F_337 ( void * V_132 )
{
F_86 ( V_132 ) ;
}
static void F_338 ( struct V_97 * V_98 , void * V_134 )
{
struct V_591 * V_592 ;
V_592 = (struct V_591 * ) V_134 ;
if ( F_54 ( V_592 -> V_33 . V_46 ,
& V_592 -> args . V_136 ,
& V_592 -> V_33 . V_137 , V_98 ) )
return;
F_57 ( V_98 ) ;
}
static int F_339 ( struct V_52 * V_52 , struct V_260 * V_305 , const T_6 * V_207 , int V_593 )
{
struct V_591 * V_134 ;
struct V_45 * V_46 = F_77 ( V_52 ) ;
struct V_97 * V_98 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_594 ] ,
. V_260 = V_305 ,
} ;
struct V_141 V_261 = {
. V_143 = V_46 -> V_79 ,
. V_138 = & V_139 ,
. V_144 = & V_595 ,
. V_176 = V_265 ,
} ;
int V_250 = 0 ;
V_134 = F_78 ( sizeof( * V_134 ) , V_247 ) ;
if ( V_134 == NULL )
return - V_239 ;
F_49 ( & V_134 -> args . V_136 , & V_134 -> V_33 . V_137 , 1 ) ;
V_134 -> args . V_344 = & V_134 -> V_186 ;
V_134 -> args . V_207 = & V_134 -> V_207 ;
V_134 -> args . V_197 = V_46 -> V_340 ;
F_152 ( & V_134 -> V_186 , F_83 ( V_52 ) ) ;
F_105 ( & V_134 -> V_207 , V_207 ) ;
V_134 -> V_33 . V_318 = & V_134 -> V_318 ;
V_134 -> V_33 . V_46 = V_46 ;
F_73 ( V_134 -> V_33 . V_318 ) ;
V_134 -> V_86 = V_131 ;
V_134 -> V_252 = 0 ;
V_261 . V_146 = V_134 ;
V_139 . V_258 = & V_134 -> args ;
V_139 . V_259 = & V_134 -> V_33 ;
V_98 = F_61 ( & V_261 ) ;
if ( F_62 ( V_98 ) )
return F_63 ( V_98 ) ;
if ( ! V_593 )
goto V_115;
V_250 = F_97 ( V_98 ) ;
if ( V_250 != 0 )
goto V_115;
V_250 = V_134 -> V_252 ;
if ( V_250 == 0 )
F_290 ( V_52 , & V_134 -> V_318 ) ;
else
F_192 ( V_52 , & V_134 -> V_318 ) ;
V_115:
F_64 ( V_98 ) ;
return V_250 ;
}
int F_340 ( struct V_52 * V_52 , struct V_260 * V_305 , const T_6 * V_207 , int V_593 )
{
struct V_45 * V_46 = F_77 ( V_52 ) ;
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_339 ( V_52 , V_305 , V_207 , V_593 ) ;
switch ( V_1 ) {
case - V_62 :
case - V_61 :
case 0 :
return 0 ;
}
V_1 = F_16 ( V_46 , V_1 , & V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static unsigned long
F_341 ( unsigned long V_40 )
{
F_14 ( V_40 ) ;
V_40 <<= 1 ;
if ( V_40 > V_596 )
return V_596 ;
return V_40 ;
}
static int F_342 ( struct V_50 * V_51 , int V_597 , struct V_598 * V_599 )
{
struct V_52 * V_52 = V_51 -> V_52 ;
struct V_45 * V_46 = F_77 ( V_52 ) ;
struct V_31 * V_32 = V_46 -> V_31 ;
struct V_600 V_320 = {
. V_186 = F_83 ( V_52 ) ,
. V_601 = V_599 ,
} ;
struct V_602 V_33 = {
. V_603 = V_599 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_604 ] ,
. V_258 = & V_320 ,
. V_259 = & V_33 ,
. V_260 = V_51 -> V_184 -> V_235 ,
} ;
struct V_605 * V_606 ;
int V_250 ;
V_320 . V_607 . V_189 = V_32 -> V_190 ;
V_250 = F_343 ( V_51 , V_599 ) ;
if ( V_250 != 0 )
goto V_115;
V_606 = V_599 -> V_608 . V_609 . V_184 ;
V_320 . V_607 . V_191 = V_606 -> V_610 . V_194 ;
V_320 . V_607 . V_611 = V_46 -> V_611 ;
V_250 = F_68 ( V_46 -> V_79 , V_46 , & V_139 , & V_320 . V_136 , & V_33 . V_137 , 1 ) ;
switch ( V_250 ) {
case 0 :
V_599 -> V_612 = V_613 ;
break;
case - V_614 :
V_250 = 0 ;
}
V_599 -> V_615 -> V_616 ( V_599 ) ;
V_115:
return V_250 ;
}
static int F_344 ( struct V_50 * V_51 , int V_597 , struct V_598 * V_599 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_51 -> V_52 ) ,
F_342 ( V_51 , V_597 , V_599 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_345 ( struct V_617 * V_617 , struct V_598 * V_601 )
{
int V_33 = 0 ;
switch ( V_601 -> V_618 & ( V_619 | V_620 ) ) {
case V_619 :
V_33 = F_346 ( V_617 , V_601 ) ;
break;
case V_620 :
V_33 = F_347 ( V_617 , V_601 ) ;
break;
default:
F_348 () ;
}
return V_33 ;
}
static struct V_621 * F_349 ( struct V_598 * V_601 ,
struct V_244 * V_245 ,
struct V_605 * V_606 ,
struct V_622 * V_167 )
{
struct V_621 * V_21 ;
struct V_52 * V_52 = V_606 -> V_623 -> V_52 ;
V_21 = F_78 ( sizeof( * V_21 ) , V_247 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_320 . V_186 = F_83 ( V_52 ) ;
V_21 -> V_320 . V_601 = & V_21 -> V_601 ;
V_21 -> V_320 . V_167 = V_167 ;
V_21 -> V_33 . V_167 = V_167 ;
V_21 -> V_320 . V_207 = & V_606 -> V_624 ;
V_21 -> V_606 = V_606 ;
F_82 ( & V_606 -> V_625 ) ;
V_21 -> V_245 = F_129 ( V_245 ) ;
memcpy ( & V_21 -> V_601 , V_601 , sizeof( V_21 -> V_601 ) ) ;
V_21 -> V_46 = F_77 ( V_52 ) ;
return V_21 ;
}
static void F_350 ( void * V_134 )
{
struct V_621 * V_132 = V_134 ;
F_90 ( V_132 -> V_320 . V_167 ) ;
F_351 ( V_132 -> V_606 ) ;
F_140 ( V_132 -> V_245 ) ;
F_86 ( V_132 ) ;
}
static void F_352 ( struct V_97 * V_98 , void * V_134 )
{
struct V_621 * V_132 = V_134 ;
if ( ! F_45 ( V_98 , & V_132 -> V_33 . V_137 ) )
return;
switch ( V_98 -> V_148 ) {
case 0 :
F_105 ( & V_132 -> V_606 -> V_624 ,
& V_132 -> V_33 . V_207 ) ;
F_29 ( V_132 -> V_46 , V_132 -> V_86 ) ;
break;
case - V_60 :
case - V_81 :
case - V_62 :
case - V_61 :
break;
default:
if ( F_189 ( V_98 , V_132 -> V_46 , NULL ) == - V_128 )
F_190 ( V_98 ) ;
}
}
static void F_353 ( struct V_97 * V_98 , void * V_134 )
{
struct V_621 * V_132 = V_134 ;
if ( F_151 ( V_132 -> V_320 . V_167 , V_98 ) != 0 )
return;
if ( ( V_132 -> V_606 -> V_626 & V_627 ) == 0 ) {
V_98 -> V_271 = NULL ;
return;
}
V_132 -> V_86 = V_131 ;
if ( F_54 ( V_132 -> V_46 ,
& V_132 -> V_320 . V_136 ,
& V_132 -> V_33 . V_137 , V_98 ) )
return;
F_57 ( V_98 ) ;
}
static struct V_97 * F_354 ( struct V_598 * V_601 ,
struct V_244 * V_245 ,
struct V_605 * V_606 ,
struct V_622 * V_167 )
{
struct V_621 * V_134 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_628 ] ,
. V_260 = V_245 -> V_305 ,
} ;
struct V_141 V_261 = {
. V_143 = F_231 ( V_606 -> V_623 -> V_52 ) ,
. V_138 = & V_139 ,
. V_144 = & V_629 ,
. V_263 = V_264 ,
. V_176 = V_265 ,
} ;
V_601 -> V_612 = V_613 ;
V_134 = F_349 ( V_601 , V_245 , V_606 , V_167 ) ;
if ( V_134 == NULL ) {
F_90 ( V_167 ) ;
return F_119 ( - V_239 ) ;
}
F_49 ( & V_134 -> V_320 . V_136 , & V_134 -> V_33 . V_137 , 1 ) ;
V_139 . V_258 = & V_134 -> V_320 ;
V_139 . V_259 = & V_134 -> V_33 ;
V_261 . V_146 = V_134 ;
return F_61 ( & V_261 ) ;
}
static int F_355 ( struct V_50 * V_51 , int V_597 , struct V_598 * V_599 )
{
struct V_154 * V_155 = F_70 ( V_51 -> V_52 ) ;
struct V_622 * V_167 ;
struct V_605 * V_606 ;
struct V_97 * V_98 ;
int V_250 = 0 ;
unsigned char V_618 = V_599 -> V_618 ;
V_250 = F_343 ( V_51 , V_599 ) ;
V_599 -> V_618 |= V_630 ;
F_356 ( & V_155 -> V_631 ) ;
if ( F_345 ( V_599 -> V_632 , V_599 ) == - V_246 ) {
F_357 ( & V_155 -> V_631 ) ;
goto V_115;
}
F_357 ( & V_155 -> V_631 ) ;
if ( V_250 != 0 )
goto V_115;
if ( F_36 ( V_224 , & V_51 -> V_176 ) )
goto V_115;
V_606 = V_599 -> V_608 . V_609 . V_184 ;
V_167 = F_79 ( & V_606 -> V_610 , V_308 ) ;
V_250 = - V_239 ;
if ( V_167 == NULL )
goto V_115;
V_98 = F_354 ( V_599 , F_224 ( V_599 -> V_632 ) , V_606 , V_167 ) ;
V_250 = F_63 ( V_98 ) ;
if ( F_62 ( V_98 ) )
goto V_115;
V_250 = F_97 ( V_98 ) ;
F_64 ( V_98 ) ;
V_115:
V_599 -> V_618 = V_618 ;
return V_250 ;
}
static struct V_633 * F_358 ( struct V_598 * V_601 ,
struct V_244 * V_245 , struct V_605 * V_606 ,
T_5 V_179 )
{
struct V_633 * V_21 ;
struct V_52 * V_52 = V_606 -> V_623 -> V_52 ;
struct V_45 * V_46 = F_77 ( V_52 ) ;
V_21 = F_78 ( sizeof( * V_21 ) , V_179 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_320 . V_186 = F_83 ( V_52 ) ;
V_21 -> V_320 . V_601 = & V_21 -> V_601 ;
V_21 -> V_320 . V_634 = F_79 ( & V_606 -> V_623 -> V_184 -> V_181 , V_179 ) ;
if ( V_21 -> V_320 . V_634 == NULL )
goto V_254;
V_21 -> V_320 . V_635 = F_79 ( & V_606 -> V_610 , V_179 ) ;
if ( V_21 -> V_320 . V_635 == NULL )
goto V_636;
V_21 -> V_320 . V_637 = & V_606 -> V_624 ;
V_21 -> V_320 . V_607 . V_189 = V_46 -> V_31 -> V_190 ;
V_21 -> V_320 . V_607 . V_191 = V_606 -> V_610 . V_194 ;
V_21 -> V_320 . V_607 . V_611 = V_46 -> V_611 ;
V_21 -> V_33 . V_635 = V_21 -> V_320 . V_635 ;
V_21 -> V_606 = V_606 ;
V_21 -> V_46 = V_46 ;
F_82 ( & V_606 -> V_625 ) ;
V_21 -> V_245 = F_129 ( V_245 ) ;
memcpy ( & V_21 -> V_601 , V_601 , sizeof( V_21 -> V_601 ) ) ;
return V_21 ;
V_636:
F_90 ( V_21 -> V_320 . V_634 ) ;
V_254:
F_86 ( V_21 ) ;
return NULL ;
}
static void F_359 ( struct V_97 * V_98 , void * V_132 )
{
struct V_633 * V_134 = V_132 ;
struct V_50 * V_51 = V_134 -> V_606 -> V_623 ;
F_2 ( L_30 , V_13 ) ;
if ( F_151 ( V_134 -> V_320 . V_635 , V_98 ) != 0 )
return;
if ( ! ( V_134 -> V_320 . V_635 -> V_638 -> V_176 & V_639 ) ) {
if ( F_151 ( V_134 -> V_320 . V_634 , V_98 ) != 0 )
return;
V_134 -> V_320 . V_225 = & V_51 -> V_207 ;
V_134 -> V_320 . V_640 = 1 ;
V_134 -> V_33 . V_634 = V_134 -> V_320 . V_634 ;
} else
V_134 -> V_320 . V_640 = 0 ;
V_134 -> V_86 = V_131 ;
if ( F_54 ( V_134 -> V_46 ,
& V_134 -> V_320 . V_136 ,
& V_134 -> V_33 . V_137 , V_98 ) )
return;
F_57 ( V_98 ) ;
F_2 ( L_45 , V_13 , V_134 -> V_252 ) ;
}
static void F_360 ( struct V_97 * V_98 , void * V_132 )
{
F_34 ( V_98 , V_100 ) ;
F_359 ( V_98 , V_132 ) ;
}
static void F_361 ( struct V_97 * V_98 , void * V_132 )
{
struct V_633 * V_134 = V_132 ;
F_2 ( L_30 , V_13 ) ;
if ( ! F_45 ( V_98 , & V_134 -> V_33 . V_137 ) )
return;
V_134 -> V_252 = V_98 -> V_148 ;
if ( V_134 -> V_320 . V_640 != 0 ) {
if ( V_134 -> V_252 == 0 )
F_145 ( & V_134 -> V_606 -> V_610 , 0 ) ;
else
goto V_115;
}
if ( V_134 -> V_252 == 0 ) {
F_105 ( & V_134 -> V_606 -> V_624 , & V_134 -> V_33 . V_207 ) ;
V_134 -> V_606 -> V_626 |= V_627 ;
F_29 ( F_77 ( V_134 -> V_245 -> V_17 -> V_27 ) , V_134 -> V_86 ) ;
}
V_115:
F_2 ( L_31 , V_13 , V_134 -> V_252 ) ;
}
static void F_362 ( void * V_132 )
{
struct V_633 * V_134 = V_132 ;
F_2 ( L_30 , V_13 ) ;
F_90 ( V_134 -> V_320 . V_634 ) ;
if ( V_134 -> V_253 != 0 ) {
struct V_97 * V_98 ;
V_98 = F_354 ( & V_134 -> V_601 , V_134 -> V_245 , V_134 -> V_606 ,
V_134 -> V_320 . V_635 ) ;
if ( ! F_62 ( V_98 ) )
F_363 ( V_98 ) ;
F_2 ( L_46 , V_13 ) ;
} else
F_90 ( V_134 -> V_320 . V_635 ) ;
F_351 ( V_134 -> V_606 ) ;
F_140 ( V_134 -> V_245 ) ;
F_86 ( V_134 ) ;
F_2 ( L_32 , V_13 ) ;
}
static void F_364 ( struct V_45 * V_46 , struct V_605 * V_606 , int V_640 , int error )
{
switch ( error ) {
case - V_59 :
case - V_60 :
V_606 -> V_610 . V_176 &= ~ V_639 ;
if ( V_640 != 0 ||
( V_606 -> V_626 & V_627 ) != 0 )
F_19 ( V_46 , V_606 -> V_623 ) ;
break;
case - V_62 :
V_606 -> V_610 . V_176 &= ~ V_639 ;
case - V_61 :
F_21 ( V_46 -> V_31 ) ;
} ;
}
static int F_365 ( struct V_50 * V_51 , int V_597 , struct V_598 * V_601 , int V_641 )
{
struct V_633 * V_134 ;
struct V_97 * V_98 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_642 ] ,
. V_260 = V_51 -> V_184 -> V_235 ,
} ;
struct V_141 V_261 = {
. V_143 = F_231 ( V_51 -> V_52 ) ,
. V_138 = & V_139 ,
. V_144 = & V_643 ,
. V_263 = V_264 ,
. V_176 = V_265 ,
} ;
int V_53 ;
F_2 ( L_30 , V_13 ) ;
V_134 = F_358 ( V_601 , F_224 ( V_601 -> V_632 ) ,
V_601 -> V_608 . V_609 . V_184 ,
V_641 == V_644 ? V_308 : V_247 ) ;
if ( V_134 == NULL )
return - V_239 ;
if ( F_366 ( V_597 ) )
V_134 -> V_320 . V_645 = 1 ;
if ( V_641 > V_644 ) {
if ( V_641 == V_646 )
V_134 -> V_320 . V_647 = V_646 ;
V_261 . V_144 = & V_648 ;
}
F_49 ( & V_134 -> V_320 . V_136 , & V_134 -> V_33 . V_137 , 1 ) ;
V_139 . V_258 = & V_134 -> V_320 ;
V_139 . V_259 = & V_134 -> V_33 ;
V_261 . V_146 = V_134 ;
V_98 = F_61 ( & V_261 ) ;
if ( F_62 ( V_98 ) )
return F_63 ( V_98 ) ;
V_53 = F_97 ( V_98 ) ;
if ( V_53 == 0 ) {
V_53 = V_134 -> V_252 ;
if ( V_53 )
F_364 ( V_134 -> V_46 , V_134 -> V_606 ,
V_134 -> V_320 . V_640 , V_53 ) ;
} else
V_134 -> V_253 = 1 ;
F_64 ( V_98 ) ;
F_2 ( L_31 , V_13 , V_53 ) ;
return V_53 ;
}
static int F_367 ( struct V_50 * V_51 , struct V_598 * V_599 )
{
struct V_45 * V_46 = F_77 ( V_51 -> V_52 ) ;
struct V_48 V_49 = {
. V_52 = V_51 -> V_52 ,
} ;
int V_1 ;
do {
if ( F_36 ( V_224 , & V_51 -> V_176 ) != 0 )
return 0 ;
V_1 = F_365 ( V_51 , V_649 , V_599 , V_646 ) ;
if ( V_1 != - V_77 )
break;
F_16 ( V_46 , V_1 , & V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_368 ( struct V_50 * V_51 , struct V_598 * V_599 )
{
struct V_45 * V_46 = F_77 ( V_51 -> V_52 ) ;
struct V_48 V_49 = {
. V_52 = V_51 -> V_52 ,
} ;
int V_1 ;
V_1 = F_343 ( V_51 , V_599 ) ;
if ( V_1 != 0 )
return V_1 ;
do {
if ( F_36 ( V_224 , & V_51 -> V_176 ) != 0 )
return 0 ;
V_1 = F_365 ( V_51 , V_649 , V_599 , V_650 ) ;
switch ( V_1 ) {
default:
goto V_115;
case - V_76 :
case - V_77 :
F_16 ( V_46 , V_1 , & V_49 ) ;
V_1 = 0 ;
}
} while ( V_49 . V_54 );
V_115:
return V_1 ;
}
static int F_369 ( struct V_50 * V_51 )
{
int V_250 , V_53 = V_114 ;
struct V_605 * V_606 ;
struct V_45 * V_46 = F_77 ( V_51 -> V_52 ) ;
F_128 (lsp, &state->lock_states, ls_locks) {
if ( V_606 -> V_626 & V_627 ) {
V_250 = F_168 ( V_46 , & V_606 -> V_624 ) ;
if ( V_250 != V_114 ) {
F_169 ( V_46 , & V_606 -> V_624 ) ;
V_606 -> V_626 &= ~ V_627 ;
V_53 = V_250 ;
}
}
} ;
return V_53 ;
}
static int F_370 ( struct V_50 * V_51 , struct V_598 * V_599 )
{
int V_250 = V_114 ;
if ( F_36 ( V_651 , & V_51 -> V_176 ) )
V_250 = F_369 ( V_51 ) ;
if ( V_250 == V_114 )
return V_250 ;
return F_368 ( V_51 , V_599 ) ;
}
static int F_371 ( struct V_50 * V_51 , int V_597 , struct V_598 * V_599 )
{
struct V_154 * V_155 = F_70 ( V_51 -> V_52 ) ;
unsigned char V_618 = V_599 -> V_618 ;
int V_250 = - V_652 ;
if ( ( V_618 & V_619 ) &&
! F_36 ( V_315 , & V_51 -> V_176 ) )
goto V_115;
V_250 = F_343 ( V_51 , V_599 ) ;
if ( V_250 != 0 )
goto V_115;
V_599 -> V_618 |= V_653 ;
V_250 = F_345 ( V_599 -> V_632 , V_599 ) ;
if ( V_250 < 0 )
goto V_115;
F_356 ( & V_155 -> V_631 ) ;
if ( F_36 ( V_224 , & V_51 -> V_176 ) ) {
V_599 -> V_618 = V_618 & ~ V_654 ;
V_250 = F_345 ( V_599 -> V_632 , V_599 ) ;
goto V_655;
}
V_250 = F_365 ( V_51 , V_597 , V_599 , V_644 ) ;
if ( V_250 != 0 )
goto V_655;
V_599 -> V_618 = V_618 | V_654 ;
if ( F_345 ( V_599 -> V_632 , V_599 ) < 0 )
F_24 ( V_84 L_47
L_48 , V_13 ) ;
V_655:
F_357 ( & V_155 -> V_631 ) ;
V_115:
V_599 -> V_618 = V_618 ;
return V_250 ;
}
static int F_372 ( struct V_50 * V_51 , int V_597 , struct V_598 * V_599 )
{
struct V_48 V_49 = {
. V_51 = V_51 ,
. V_52 = V_51 -> V_52 ,
} ;
int V_1 ;
do {
V_1 = F_371 ( V_51 , V_597 , V_599 ) ;
if ( V_1 == - V_614 )
V_1 = - V_128 ;
V_1 = F_16 ( F_77 ( V_51 -> V_52 ) ,
V_1 , & V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int
F_373 ( struct V_617 * V_656 , int V_597 , struct V_598 * V_599 )
{
struct V_244 * V_245 ;
struct V_50 * V_51 ;
unsigned long V_40 = V_657 ;
int V_250 ;
V_245 = F_224 ( V_656 ) ;
V_51 = V_245 -> V_51 ;
if ( V_599 -> V_658 < 0 || V_599 -> V_659 < 0 )
return - V_8 ;
if ( F_374 ( V_597 ) ) {
if ( V_51 != NULL )
return F_344 ( V_51 , V_660 , V_599 ) ;
return 0 ;
}
if ( ! ( F_375 ( V_597 ) || F_366 ( V_597 ) ) )
return - V_8 ;
if ( V_599 -> V_612 == V_613 ) {
if ( V_51 != NULL )
return F_355 ( V_51 , V_597 , V_599 ) ;
return 0 ;
}
if ( V_51 == NULL )
return - V_652 ;
switch ( V_599 -> V_612 & ( V_661 | V_662 | V_613 ) ) {
case V_661 :
if ( ! ( V_656 -> V_663 & V_56 ) )
return - V_327 ;
break;
case V_662 :
if ( ! ( V_656 -> V_663 & V_188 ) )
return - V_327 ;
}
do {
V_250 = F_372 ( V_51 , V_597 , V_599 ) ;
if ( ( V_250 != - V_128 ) || F_375 ( V_597 ) )
break;
V_40 = F_341 ( V_40 ) ;
V_250 = - V_44 ;
if ( F_376 () )
break;
} while( V_250 < 0 );
return V_250 ;
}
int F_377 ( struct V_50 * V_51 , struct V_598 * V_601 )
{
struct V_45 * V_46 = F_77 ( V_51 -> V_52 ) ;
struct V_48 V_49 = { } ;
int V_1 ;
V_1 = F_343 ( V_51 , V_601 ) ;
if ( V_1 != 0 )
goto V_115;
do {
V_1 = F_365 ( V_51 , V_649 , V_601 , V_644 ) ;
switch ( V_1 ) {
default:
F_24 ( V_664 L_49
L_50 , V_13 , V_1 ) ;
case 0 :
case - V_249 :
goto V_115;
case - V_61 :
F_19 ( V_46 , V_51 ) ;
case - V_63 :
case - V_62 :
F_21 ( V_46 -> V_31 ) ;
goto V_115;
case - V_65 :
case - V_66 :
case - V_67 :
case - V_68 :
case - V_69 :
F_23 ( V_46 -> V_31 -> V_72 , V_1 ) ;
goto V_115;
case - V_44 :
case - V_58 :
case - V_59 :
case - V_60 :
case - V_55 :
F_19 ( V_46 , V_51 ) ;
V_1 = 0 ;
goto V_115;
case - V_78 :
V_1 = 0 ;
goto V_115;
case - V_239 :
case - V_614 :
V_1 = 0 ;
goto V_115;
case - V_77 :
break;
}
V_1 = F_16 ( V_46 , V_1 , & V_49 ) ;
} while ( V_49 . V_54 );
V_115:
return V_1 ;
}
static void F_378 ( void * V_132 )
{
struct V_665 * V_134 = V_132 ;
F_379 ( V_134 -> V_46 , V_134 -> V_606 ) ;
F_86 ( V_132 ) ;
}
int F_380 ( struct V_605 * V_606 )
{
struct V_45 * V_46 = V_606 -> V_623 -> V_184 -> V_268 ;
struct V_665 * V_134 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_666 ] ,
} ;
if ( V_46 -> V_31 -> V_149 -> V_384 != 0 )
return - V_8 ;
V_134 = F_217 ( sizeof( * V_134 ) , V_247 ) ;
if ( ! V_134 )
return - V_239 ;
V_134 -> V_606 = V_606 ;
V_134 -> V_46 = V_46 ;
V_134 -> args . V_607 . V_189 = V_46 -> V_31 -> V_190 ;
V_134 -> args . V_607 . V_191 = V_606 -> V_610 . V_194 ;
V_134 -> args . V_607 . V_611 = V_46 -> V_611 ;
V_139 . V_258 = & V_134 -> args ;
F_307 ( V_46 -> V_79 , & V_139 , 0 , & V_667 , V_134 ) ;
return 0 ;
}
static int F_381 ( struct V_17 * V_17 , const char * V_668 ,
const void * V_518 , T_9 V_519 ,
int V_176 , int type )
{
if ( strcmp ( V_668 , L_51 ) != 0 )
return - V_8 ;
return F_326 ( V_17 -> V_27 , V_518 , V_519 ) ;
}
static int F_382 ( struct V_17 * V_17 , const char * V_668 ,
void * V_518 , T_9 V_519 , int type )
{
if ( strcmp ( V_668 , L_51 ) != 0 )
return - V_8 ;
return F_320 ( V_17 -> V_27 , V_518 , V_519 ) ;
}
static T_9 F_383 ( struct V_17 * V_17 , char * V_669 ,
T_9 V_670 , const char * V_195 ,
T_9 V_671 , int type )
{
T_9 V_380 = sizeof( V_672 ) ;
if ( ! F_309 ( F_77 ( V_17 -> V_27 ) ) )
return 0 ;
if ( V_669 && V_380 <= V_670 )
memcpy ( V_669 , V_672 , V_380 ) ;
return V_380 ;
}
static void F_219 ( struct V_317 * V_318 )
{
if ( ! ( ( ( V_318 -> V_237 & V_673 ) ||
( V_318 -> V_237 & V_674 ) ) &&
( V_318 -> V_237 & V_389 ) &&
( V_318 -> V_237 & V_675 ) ) )
return;
V_318 -> V_237 |= V_404 | V_405 |
V_406 | V_676 ;
V_318 -> V_211 = V_276 | V_408 | V_409 ;
V_318 -> V_410 = 2 ;
}
static int F_384 ( struct V_38 * V_79 , struct V_52 * V_151 ,
const struct V_391 * V_195 ,
struct V_393 * V_677 ,
struct V_392 * V_392 )
{
struct V_45 * V_46 = F_77 ( V_151 ) ;
T_3 V_197 [ 2 ] = {
[ 0 ] = V_678 | V_679 ,
} ;
struct V_680 args = {
. V_402 = F_83 ( V_151 ) ,
. V_195 = V_195 ,
. V_392 = V_392 ,
. V_197 = V_197 ,
} ;
struct V_681 V_33 = {
. V_677 = V_677 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_682 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
int V_250 ;
F_2 ( L_52 , V_13 ) ;
if ( F_77 ( V_151 ) -> V_198 [ 1 ] & V_683 )
V_197 [ 1 ] |= V_683 ;
else
V_197 [ 0 ] |= V_26 ;
F_73 ( & V_677 -> V_318 ) ;
V_677 -> V_46 = V_46 ;
V_677 -> V_684 = 0 ;
V_250 = F_68 ( V_79 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
F_2 ( L_53 , V_13 , V_250 ) ;
return V_250 ;
}
int F_218 ( struct V_38 * V_79 , struct V_52 * V_151 ,
const struct V_391 * V_195 ,
struct V_393 * V_677 ,
struct V_392 * V_392 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_151 ) ,
F_384 ( V_79 , V_151 , V_195 , V_677 , V_392 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_385 ( struct V_52 * V_151 , const struct V_391 * V_195 , struct V_685 * V_686 )
{
int V_250 ;
struct V_687 args = {
. V_402 = F_83 ( V_151 ) ,
. V_195 = V_195 ,
} ;
struct V_688 V_33 = {
. V_686 = V_686 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_689 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
F_2 ( L_54 , V_195 -> V_195 ) ;
V_250 = F_68 ( F_77 ( V_151 ) -> V_79 , F_77 ( V_151 ) , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
F_2 ( L_55 , V_250 ) ;
return V_250 ;
}
int F_386 ( struct V_52 * V_151 , const struct V_391 * V_195 ,
struct V_685 * V_686 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_151 ) ,
F_385 ( V_151 , V_195 , V_686 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_387 ( T_3 V_176 )
{
if ( V_176 & ~ V_690 )
goto V_691;
if ( ( V_176 & V_692 ) &&
( V_176 & V_693 ) )
goto V_691;
if ( ! ( V_176 & ( V_694 ) ) )
goto V_691;
return V_114 ;
V_691:
return - V_695 ;
}
static bool
F_388 ( struct V_696 * V_697 ,
struct V_696 * V_698 )
{
if ( V_697 -> V_699 == V_698 -> V_699 &&
memcmp ( V_697 -> V_700 , V_698 -> V_700 , V_697 -> V_699 ) == 0 )
return true ;
return false ;
}
int F_389 ( struct V_31 * V_32 , struct V_260 * V_305 )
{
int V_250 ;
struct V_701 V_33 ;
struct V_138 V_139 = {
. V_255 =
& V_256 [ V_702 ] ,
. V_258 = V_32 ,
. V_259 = & V_33 ,
. V_260 = V_305 ,
} ;
F_2 ( L_17 , V_13 ) ;
F_4 ( V_32 == NULL ) ;
V_33 . V_125 = F_78 ( sizeof( struct V_101 ) , V_247 ) ;
if ( F_390 ( V_33 . V_125 == NULL ) ) {
V_250 = - V_239 ;
goto V_115;
}
V_250 = F_67 ( V_32 -> V_512 , & V_139 , V_586 ) ;
if ( V_250 == 0 ) {
if ( memcmp ( V_33 . V_125 -> V_703 . V_134 ,
V_32 -> V_72 -> V_703 . V_134 , V_704 ) ) {
F_2 ( L_56 , V_13 ) ;
V_250 = - V_14 ;
goto V_705;
}
if ( V_33 . V_151 != V_706 ) {
F_2 ( L_57 ,
V_13 ) ;
V_250 = - V_14 ;
goto V_705;
}
if ( V_33 . V_707 ) {
F_2 ( L_58 ,
V_13 ) ;
V_250 = - V_14 ;
goto V_705;
}
}
V_705:
F_86 ( V_33 . V_125 ) ;
V_115:
F_2 ( L_59 , V_13 , V_250 ) ;
return V_250 ;
}
int F_391 ( struct V_31 * V_32 , struct V_260 * V_305 )
{
T_11 V_16 ;
struct V_708 args = {
. V_16 = & V_16 ,
. V_79 = V_32 ,
. V_176 = V_709 ,
} ;
struct V_710 V_33 = {
0
} ;
int V_250 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_711 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
. V_260 = V_305 ,
} ;
F_2 ( L_17 , V_13 ) ;
F_4 ( V_32 == NULL ) ;
F_329 ( V_32 , & V_16 ) ;
args . V_712 = F_332 ( args . V_191 , sizeof( args . V_191 ) ,
L_60 ,
V_32 -> V_574 ,
V_32 -> V_512 -> V_713 ,
V_32 -> V_512 -> V_577 -> V_714 ) ;
V_33 . V_715 = F_78 ( sizeof( struct V_716 ) ,
V_247 ) ;
if ( F_390 ( V_33 . V_715 == NULL ) ) {
V_250 = - V_239 ;
goto V_115;
}
V_33 . V_700 = F_78 ( sizeof( struct V_696 ) ,
V_247 ) ;
if ( F_390 ( V_33 . V_700 == NULL ) ) {
V_250 = - V_239 ;
goto V_717;
}
V_33 . V_718 = F_78 ( sizeof( struct V_719 ) , V_247 ) ;
if ( F_390 ( V_33 . V_718 == NULL ) ) {
V_250 = - V_239 ;
goto V_720;
}
V_250 = F_67 ( V_32 -> V_512 , & V_139 , V_586 ) ;
if ( V_250 == 0 )
V_250 = F_387 ( V_33 . V_176 ) ;
if ( V_250 == 0 ) {
V_32 -> V_190 = V_33 . V_189 ;
V_32 -> V_721 = ( V_33 . V_176 & ~ V_722 ) ;
if ( ! ( V_33 . V_176 & V_722 ) )
V_32 -> V_723 = V_33 . V_167 ;
F_86 ( V_32 -> V_724 ) ;
V_32 -> V_724 = V_33 . V_715 ;
V_33 . V_715 = NULL ;
F_86 ( V_32 -> V_725 ) ;
V_32 -> V_725 = V_33 . V_718 ;
if ( V_32 -> V_726 != NULL &&
! F_388 ( V_32 -> V_726 ,
V_33 . V_700 ) ) {
F_2 ( L_61 ,
V_13 ) ;
F_106 ( V_727 , & V_32 -> V_34 ) ;
F_86 ( V_32 -> V_726 ) ;
V_32 -> V_726 = NULL ;
}
if ( V_32 -> V_726 == NULL ) {
V_32 -> V_726 = V_33 . V_700 ;
goto V_115;
}
} else
F_86 ( V_33 . V_718 ) ;
V_717:
F_86 ( V_33 . V_715 ) ;
V_720:
F_86 ( V_33 . V_700 ) ;
V_115:
if ( V_32 -> V_725 != NULL )
F_2 ( L_62
L_63 ,
V_13 , V_32 -> V_725 -> V_728 , V_32 -> V_725 -> V_195 ,
V_32 -> V_725 -> V_729 . V_730 ,
V_32 -> V_725 -> V_729 . V_731 ) ;
F_2 ( L_59 , V_13 , V_250 ) ;
return V_250 ;
}
static int F_392 ( struct V_31 * V_32 ,
struct V_260 * V_305 )
{
struct V_138 V_139 = {
. V_255 = & V_256 [ V_732 ] ,
. V_258 = V_32 ,
. V_260 = V_305 ,
} ;
int V_250 ;
V_250 = F_67 ( V_32 -> V_512 , & V_139 , V_586 ) ;
if ( V_250 )
F_2 ( L_64
L_65 , V_250 , V_32 -> V_85 ) ;
return V_250 ;
}
static int F_393 ( struct V_31 * V_32 ,
struct V_260 * V_305 )
{
unsigned int V_290 ;
int V_53 ;
for ( V_290 = V_291 ; V_290 != 0 ; V_290 -- ) {
V_53 = F_392 ( V_32 , V_305 ) ;
switch ( V_53 ) {
case - V_77 :
case - V_733 :
F_334 ( 1 ) ;
break;
default:
return V_53 ;
}
}
return 0 ;
}
int F_394 ( struct V_31 * V_32 )
{
struct V_260 * V_305 ;
int V_53 = 0 ;
if ( V_32 -> V_149 -> V_384 < 1 )
goto V_115;
if ( V_32 -> V_721 == 0 )
goto V_115;
V_305 = F_395 ( V_32 ) ;
V_53 = F_393 ( V_32 , V_305 ) ;
if ( V_305 )
F_396 ( V_305 ) ;
switch ( V_53 ) {
case 0 :
case - V_63 :
V_32 -> V_721 = 0 ;
}
V_115:
return V_53 ;
}
static void F_397 ( struct V_97 * V_98 ,
void * V_132 )
{
int V_53 ;
struct V_734 * V_134 =
(struct V_734 * ) V_132 ;
F_2 ( L_17 , V_13 ) ;
F_34 ( V_98 , V_100 ) ;
V_53 = F_50 ( V_134 -> V_32 -> V_72 ,
& V_134 -> args -> V_735 ,
& V_134 -> V_33 -> V_736 , V_98 ) ;
F_4 ( V_53 == - V_128 ) ;
F_57 ( V_98 ) ;
F_2 ( L_66 , V_13 ) ;
}
static void F_398 ( struct V_97 * V_98 , void * V_132 )
{
struct V_734 * V_134 =
(struct V_734 * ) V_132 ;
F_2 ( L_17 , V_13 ) ;
if ( ! F_41 ( V_98 , & V_134 -> V_33 -> V_736 ) )
return;
switch ( V_98 -> V_148 ) {
case - V_77 :
case - V_76 :
F_2 ( L_67 , V_13 , V_98 -> V_148 ) ;
F_44 ( V_98 , V_41 ) ;
V_98 -> V_148 = 0 ;
case - V_80 :
F_190 ( V_98 ) ;
return;
}
F_2 ( L_66 , V_13 ) ;
}
int F_399 ( struct V_31 * V_32 , struct V_371 * V_480 )
{
struct V_97 * V_98 ;
struct V_737 args ;
struct V_738 V_33 = {
. V_739 = V_480 ,
} ;
struct V_734 V_134 = {
. args = & args ,
. V_33 = & V_33 ,
. V_32 = V_32 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_740 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
struct V_141 V_142 = {
. V_143 = V_32 -> V_512 ,
. V_138 = & V_139 ,
. V_144 = & V_741 ,
. V_146 = & V_134 ,
. V_176 = V_586 ,
} ;
int V_250 ;
F_49 ( & args . V_735 , & V_33 . V_736 , 0 ) ;
F_2 ( L_17 , V_13 ) ;
V_98 = F_61 ( & V_142 ) ;
if ( F_62 ( V_98 ) )
V_250 = F_63 ( V_98 ) ;
else {
V_250 = V_98 -> V_148 ;
F_64 ( V_98 ) ;
}
F_2 ( L_68 , V_13 , V_250 ) ;
return V_250 ;
}
static struct V_126 * F_400 ( T_3 V_95 , T_5 V_742 )
{
return F_401 ( V_95 , sizeof( struct V_126 ) , V_742 ) ;
}
static void F_402 ( struct V_89 * V_90 ,
struct V_126 * V_743 ,
T_3 V_95 ,
T_3 V_744 )
{
struct V_126 * V_745 = NULL ;
T_3 V_379 ;
F_26 ( & V_90 -> V_111 ) ;
if ( V_743 ) {
V_745 = V_90 -> V_112 ;
V_90 -> V_112 = V_743 ;
V_90 -> V_95 = V_95 ;
}
V_90 -> V_94 = - 1 ;
for ( V_379 = 0 ; V_379 < V_90 -> V_95 ; V_379 ++ )
V_90 -> V_112 [ V_379 ] . V_116 = V_744 ;
F_28 ( & V_90 -> V_111 ) ;
F_86 ( V_745 ) ;
}
static int F_403 ( struct V_89 * V_90 , T_3 V_746 ,
T_3 V_744 )
{
struct V_126 * V_743 = NULL ;
int V_53 = - V_239 ;
F_2 ( L_69 , V_13 ,
V_746 , V_90 -> V_95 ) ;
if ( V_746 != V_90 -> V_95 ) {
V_743 = F_400 ( V_746 , V_247 ) ;
if ( ! V_743 )
goto V_115;
}
V_53 = 0 ;
F_402 ( V_90 , V_743 , V_746 , V_744 ) ;
F_2 ( L_70 , V_13 ,
V_90 , V_90 -> V_112 , V_90 -> V_95 ) ;
V_115:
F_2 ( L_71 , V_13 , V_53 ) ;
return V_53 ;
}
static void F_404 ( struct V_101 * V_125 )
{
if ( V_125 -> V_105 . V_112 != NULL ) {
F_86 ( V_125 -> V_105 . V_112 ) ;
V_125 -> V_105 . V_112 = NULL ;
}
if ( V_125 -> V_107 . V_112 != NULL ) {
F_86 ( V_125 -> V_107 . V_112 ) ;
V_125 -> V_107 . V_112 = NULL ;
}
return;
}
static int F_405 ( struct V_101 * V_102 )
{
struct V_89 * V_90 ;
int V_250 ;
F_2 ( L_17 , V_13 ) ;
V_90 = & V_102 -> V_105 ;
V_250 = F_403 ( V_90 , V_102 -> V_747 . V_746 , 1 ) ;
if ( V_250 )
return V_250 ;
V_90 = & V_102 -> V_107 ;
V_250 = F_403 ( V_90 , V_102 -> V_748 . V_746 , 0 ) ;
if ( V_250 && V_90 -> V_112 == NULL )
F_404 ( V_102 ) ;
return V_250 ;
}
struct V_101 * F_406 ( struct V_31 * V_32 )
{
struct V_101 * V_125 ;
struct V_89 * V_90 ;
V_125 = F_78 ( sizeof( struct V_101 ) , V_247 ) ;
if ( ! V_125 )
return NULL ;
V_90 = & V_125 -> V_105 ;
V_90 -> V_94 = V_96 ;
F_407 ( & V_90 -> V_111 ) ;
F_408 ( & V_90 -> V_106 , L_72 ) ;
F_409 ( & V_90 -> F_38 ) ;
V_90 = & V_125 -> V_107 ;
V_90 -> V_94 = V_96 ;
F_407 ( & V_90 -> V_111 ) ;
F_410 ( & V_90 -> V_106 , L_73 ) ;
F_409 ( & V_90 -> F_38 ) ;
V_125 -> V_104 = 1 << V_749 ;
V_125 -> V_32 = V_32 ;
return V_125 ;
}
void F_411 ( struct V_101 * V_125 )
{
struct V_750 * V_751 ;
struct V_260 * V_305 ;
V_305 = F_395 ( V_125 -> V_32 ) ;
F_412 ( V_125 , V_305 ) ;
if ( V_305 )
F_396 ( V_305 ) ;
F_112 () ;
V_751 = F_113 ( V_125 -> V_32 -> V_512 -> V_752 ) ;
F_115 () ;
F_2 ( L_74 ,
V_13 , V_751 ) ;
F_413 ( V_751 , V_753 ) ;
F_404 ( V_125 ) ;
F_86 ( V_125 ) ;
}
static void F_414 ( struct V_754 * args )
{
struct V_101 * V_125 = args -> V_79 -> V_72 ;
unsigned int V_755 = V_125 -> V_747 . V_756 ,
V_757 = V_125 -> V_747 . V_758 ;
if ( V_755 == 0 )
V_755 = V_759 ;
if ( V_757 == 0 )
V_757 = V_759 ;
args -> V_747 . V_756 = V_755 ;
args -> V_747 . V_758 = V_757 ;
args -> V_747 . V_760 = V_761 ;
args -> V_747 . V_746 = V_762 ;
F_2 ( L_75
L_76 ,
V_13 ,
args -> V_747 . V_756 , args -> V_747 . V_758 ,
args -> V_747 . V_760 , args -> V_747 . V_746 ) ;
args -> V_748 . V_756 = V_532 ;
args -> V_748 . V_758 = V_532 ;
args -> V_748 . V_763 = 0 ;
args -> V_748 . V_760 = V_764 ;
args -> V_748 . V_746 = 1 ;
F_2 ( L_77
L_78 ,
V_13 ,
args -> V_748 . V_756 , args -> V_748 . V_758 ,
args -> V_748 . V_763 , args -> V_748 . V_760 ,
args -> V_748 . V_746 ) ;
}
static int F_415 ( struct V_754 * args , struct V_101 * V_125 )
{
struct V_765 * V_766 = & args -> V_747 ;
struct V_765 * V_767 = & V_125 -> V_747 ;
if ( V_767 -> V_758 > V_766 -> V_758 )
return - V_8 ;
if ( V_767 -> V_760 < V_766 -> V_760 )
return - V_8 ;
if ( V_767 -> V_746 == 0 )
return - V_8 ;
if ( V_767 -> V_746 > V_92 )
V_767 -> V_746 = V_92 ;
return 0 ;
}
static int F_416 ( struct V_754 * args , struct V_101 * V_125 )
{
struct V_765 * V_766 = & args -> V_748 ;
struct V_765 * V_767 = & V_125 -> V_748 ;
if ( V_767 -> V_756 > V_766 -> V_756 )
return - V_8 ;
if ( V_767 -> V_758 < V_766 -> V_758 )
return - V_8 ;
if ( V_767 -> V_763 > V_766 -> V_763 )
return - V_8 ;
if ( V_767 -> V_760 != V_766 -> V_760 )
return - V_8 ;
if ( V_767 -> V_746 != V_766 -> V_746 )
return - V_8 ;
return 0 ;
}
static int F_417 ( struct V_754 * args ,
struct V_101 * V_125 )
{
int V_53 ;
V_53 = F_415 ( args , V_125 ) ;
if ( V_53 )
return V_53 ;
return F_416 ( args , V_125 ) ;
}
static int F_418 ( struct V_31 * V_32 ,
struct V_260 * V_305 )
{
struct V_101 * V_125 = V_32 -> V_72 ;
struct V_754 args = {
. V_79 = V_32 ,
. V_768 = V_769 ,
} ;
struct V_770 V_33 = {
. V_79 = V_32 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_771 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
. V_260 = V_305 ,
} ;
int V_250 ;
F_414 ( & args ) ;
args . V_176 = ( V_772 | V_773 ) ;
V_250 = F_67 ( V_125 -> V_32 -> V_512 , & V_139 , V_586 ) ;
if ( ! V_250 )
V_250 = F_417 ( & args , V_125 ) ;
if ( ! V_250 ) {
V_32 -> V_723 ++ ;
}
return V_250 ;
}
int F_419 ( struct V_31 * V_32 , struct V_260 * V_305 )
{
int V_250 ;
unsigned * V_774 ;
struct V_101 * V_125 = V_32 -> V_72 ;
F_2 ( L_79 , V_13 , V_32 , V_125 ) ;
V_250 = F_418 ( V_32 , V_305 ) ;
if ( V_250 )
goto V_115;
V_250 = F_405 ( V_125 ) ;
F_2 ( L_80 , V_250 ) ;
if ( V_250 )
goto V_115;
V_774 = ( unsigned * ) & V_125 -> V_703 . V_134 [ 0 ] ;
F_2 ( L_81 , V_13 ,
V_32 -> V_723 , V_774 [ 0 ] , V_774 [ 1 ] , V_774 [ 2 ] , V_774 [ 3 ] ) ;
V_115:
F_2 ( L_66 , V_13 ) ;
return V_250 ;
}
int F_412 ( struct V_101 * V_125 ,
struct V_260 * V_305 )
{
struct V_138 V_139 = {
. V_255 = & V_256 [ V_775 ] ,
. V_258 = V_125 ,
. V_260 = V_305 ,
} ;
int V_250 = 0 ;
F_2 ( L_82 ) ;
if ( V_125 -> V_32 -> V_776 != V_777 )
return V_250 ;
V_250 = F_67 ( V_125 -> V_32 -> V_512 , & V_139 , V_586 ) ;
if ( V_250 )
F_2 ( L_83
L_84 , V_250 ) ;
F_2 ( L_85 ) ;
return V_250 ;
}
static int F_420 ( struct V_31 * V_32 )
{
int V_53 ;
if ( V_32 -> V_776 == V_778 ) {
V_53 = F_160 ( V_32 ) ;
if ( V_53 )
return V_53 ;
}
if ( V_32 -> V_776 < V_777 )
return - V_12 ;
F_136 () ;
return 0 ;
}
int F_421 ( struct V_45 * V_46 )
{
struct V_31 * V_32 = V_46 -> V_31 ;
struct V_101 * V_125 ;
unsigned int V_779 , V_780 ;
if ( ! F_422 ( V_32 ) )
return 0 ;
V_125 = V_32 -> V_72 ;
F_26 ( & V_32 -> V_87 ) ;
if ( F_423 ( V_749 , & V_125 -> V_104 ) ) {
V_779 = V_46 -> V_779 ;
if ( V_779 == 0 )
V_779 = V_759 ;
V_780 = V_46 -> V_780 ;
if ( V_780 == 0 )
V_780 = V_759 ;
V_125 -> V_747 . V_756 = V_780 + V_781 ;
V_125 -> V_747 . V_758 = V_779 + V_782 ;
}
F_28 ( & V_32 -> V_87 ) ;
return F_420 ( V_32 ) ;
}
int F_424 ( struct V_31 * V_32 , unsigned long V_590 )
{
struct V_101 * V_125 = V_32 -> V_72 ;
int V_53 ;
F_26 ( & V_32 -> V_87 ) ;
if ( F_423 ( V_749 , & V_125 -> V_104 ) ) {
V_32 -> V_588 = V_590 ;
V_32 -> V_88 = V_131 ;
}
F_28 ( & V_32 -> V_87 ) ;
V_53 = F_420 ( V_32 ) ;
if ( V_53 )
return V_53 ;
if ( ! F_425 ( V_32 ) )
return - V_783 ;
return 0 ;
}
static void F_426 ( void * V_134 )
{
struct V_784 * V_132 = V_134 ;
struct V_31 * V_32 = V_132 -> V_32 ;
if ( F_300 ( & V_32 -> V_506 ) > 1 )
F_301 ( V_32 ) ;
F_302 ( V_32 ) ;
F_86 ( V_132 ) ;
}
static int F_427 ( struct V_97 * V_98 , struct V_31 * V_32 )
{
switch( V_98 -> V_148 ) {
case - V_77 :
F_44 ( V_98 , V_42 ) ;
return - V_128 ;
default:
F_21 ( V_32 ) ;
}
return 0 ;
}
static void F_428 ( struct V_97 * V_98 , void * V_134 )
{
struct V_784 * V_132 = V_134 ;
struct V_31 * V_32 = V_132 -> V_32 ;
if ( ! F_41 ( V_98 , V_98 -> V_269 . V_259 ) )
return;
if ( V_98 -> V_148 < 0 ) {
F_2 ( L_86 , V_13 , V_98 -> V_148 ) ;
if ( F_300 ( & V_32 -> V_506 ) == 1 )
goto V_115;
if ( F_427 ( V_98 , V_32 ) == - V_128 ) {
F_190 ( V_98 ) ;
return;
}
}
F_2 ( L_87 , V_13 , V_98 -> V_269 . V_260 ) ;
V_115:
F_2 ( L_66 , V_13 ) ;
}
static void F_429 ( struct V_97 * V_98 , void * V_134 )
{
struct V_784 * V_132 = V_134 ;
struct V_31 * V_32 = V_132 -> V_32 ;
struct V_121 * args ;
struct V_108 * V_33 ;
args = V_98 -> V_269 . V_258 ;
V_33 = V_98 -> V_269 . V_259 ;
if ( F_50 ( V_32 -> V_72 , args , V_33 , V_98 ) )
return;
F_57 ( V_98 ) ;
}
static struct V_97 * F_430 ( struct V_31 * V_32 , struct V_260 * V_305 )
{
struct V_784 * V_132 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_785 ] ,
. V_260 = V_305 ,
} ;
struct V_141 V_261 = {
. V_143 = V_32 -> V_512 ,
. V_138 = & V_139 ,
. V_144 = & V_786 ,
. V_176 = V_265 | V_513 ,
} ;
if ( ! F_306 ( & V_32 -> V_506 ) )
return F_119 ( - V_14 ) ;
V_132 = F_78 ( sizeof( * V_132 ) , V_247 ) ;
if ( V_132 == NULL ) {
F_302 ( V_32 ) ;
return F_119 ( - V_239 ) ;
}
F_49 ( & V_132 -> args , & V_132 -> V_33 , 0 ) ;
V_139 . V_258 = & V_132 -> args ;
V_139 . V_259 = & V_132 -> V_33 ;
V_132 -> V_32 = V_32 ;
V_261 . V_146 = V_132 ;
return F_61 ( & V_261 ) ;
}
static int F_431 ( struct V_31 * V_32 , struct V_260 * V_305 , unsigned V_510 )
{
struct V_97 * V_98 ;
int V_53 = 0 ;
if ( ( V_510 & V_787 ) == 0 )
return 0 ;
V_98 = F_430 ( V_32 , V_305 ) ;
if ( F_62 ( V_98 ) )
V_53 = F_63 ( V_98 ) ;
else
F_363 ( V_98 ) ;
F_2 ( L_23 , V_13 , V_53 ) ;
return V_53 ;
}
static int F_432 ( struct V_31 * V_32 , struct V_260 * V_305 )
{
struct V_97 * V_98 ;
int V_53 ;
V_98 = F_430 ( V_32 , V_305 ) ;
if ( F_62 ( V_98 ) ) {
V_53 = F_63 ( V_98 ) ;
goto V_115;
}
V_53 = F_98 ( V_98 ) ;
if ( ! V_53 ) {
struct V_108 * V_33 = V_98 -> V_269 . V_259 ;
if ( V_98 -> V_148 == 0 )
F_433 ( V_32 , V_33 -> V_118 ) ;
V_53 = V_98 -> V_148 ;
}
F_64 ( V_98 ) ;
V_115:
F_2 ( L_23 , V_13 , V_53 ) ;
return V_53 ;
}
static void F_434 ( struct V_97 * V_98 , void * V_134 )
{
struct V_788 * V_132 = V_134 ;
F_34 ( V_98 , V_100 ) ;
if ( F_50 ( V_132 -> V_32 -> V_72 ,
& V_132 -> V_320 . V_136 ,
& V_132 -> V_33 . V_137 , V_98 ) )
return;
F_57 ( V_98 ) ;
}
static int F_435 ( struct V_97 * V_98 , struct V_31 * V_32 )
{
switch( V_98 -> V_148 ) {
case 0 :
case - V_789 :
case - V_790 :
break;
case - V_77 :
F_44 ( V_98 , V_42 ) ;
case - V_80 :
return - V_128 ;
default:
F_21 ( V_32 ) ;
}
return 0 ;
}
static void F_436 ( struct V_97 * V_98 , void * V_134 )
{
struct V_788 * V_132 = V_134 ;
struct V_31 * V_32 = V_132 -> V_32 ;
struct V_108 * V_33 = & V_132 -> V_33 . V_137 ;
F_2 ( L_17 , V_13 ) ;
if ( ! F_41 ( V_98 , V_33 ) )
return;
if ( F_435 ( V_98 , V_32 ) == - V_128 ) {
F_190 ( V_98 ) ;
return;
}
F_2 ( L_66 , V_13 ) ;
}
static void F_437 ( void * V_134 )
{
struct V_788 * V_132 = V_134 ;
F_86 ( V_132 ) ;
}
static int F_438 ( struct V_31 * V_32 )
{
struct V_788 * V_132 ;
struct V_97 * V_98 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_791 ] ,
} ;
struct V_141 V_261 = {
. V_143 = V_32 -> V_512 ,
. V_138 = & V_139 ,
. V_144 = & V_792 ,
. V_176 = V_265 ,
} ;
int V_250 = - V_239 ;
F_2 ( L_17 , V_13 ) ;
V_132 = F_78 ( sizeof( * V_132 ) , V_247 ) ;
if ( V_132 == NULL )
goto V_115;
V_132 -> V_32 = V_32 ;
V_132 -> V_320 . V_793 = 0 ;
F_49 ( & V_132 -> V_320 . V_136 , & V_132 -> V_33 . V_137 , 0 ) ;
V_139 . V_258 = & V_132 -> V_320 ;
V_139 . V_259 = & V_132 -> V_33 ;
V_261 . V_146 = V_132 ;
V_98 = F_61 ( & V_261 ) ;
if ( F_62 ( V_98 ) ) {
V_250 = F_63 ( V_98 ) ;
goto V_115;
}
V_250 = F_97 ( V_98 ) ;
if ( V_250 == 0 )
V_250 = V_98 -> V_148 ;
F_64 ( V_98 ) ;
return 0 ;
V_115:
F_2 ( L_23 , V_13 , V_250 ) ;
return V_250 ;
}
static void
F_439 ( struct V_97 * V_98 , void * V_132 )
{
struct V_794 * V_795 = V_132 ;
struct V_45 * V_46 = F_77 ( V_795 -> args . V_52 ) ;
F_2 ( L_17 , V_13 ) ;
if ( F_54 ( V_46 , & V_795 -> args . V_136 ,
& V_795 -> V_33 . V_137 , V_98 ) )
return;
if ( F_440 ( & V_795 -> args . V_207 ,
F_70 ( V_795 -> args . V_52 ) -> V_796 ,
V_795 -> args . V_245 -> V_51 ) ) {
F_441 ( V_98 , V_797 ) ;
return;
}
F_57 ( V_98 ) ;
}
static void F_442 ( struct V_97 * V_98 , void * V_132 )
{
struct V_794 * V_795 = V_132 ;
struct V_45 * V_46 = F_77 ( V_795 -> args . V_52 ) ;
F_2 ( L_17 , V_13 ) ;
if ( ! F_45 ( V_98 , & V_795 -> V_33 . V_137 ) )
return;
switch ( V_98 -> V_148 ) {
case 0 :
break;
case - V_798 :
case - V_799 :
V_98 -> V_148 = - V_77 ;
default:
if ( F_189 ( V_98 , V_46 , NULL ) == - V_128 ) {
F_190 ( V_98 ) ;
return;
}
}
F_2 ( L_66 , V_13 ) ;
}
static void F_443 ( void * V_132 )
{
struct V_794 * V_795 = V_132 ;
F_2 ( L_17 , V_13 ) ;
F_140 ( V_795 -> args . V_245 ) ;
F_86 ( V_132 ) ;
F_2 ( L_66 , V_13 ) ;
}
int F_444 ( struct V_794 * V_795 )
{
struct V_45 * V_46 = F_77 ( V_795 -> args . V_52 ) ;
struct V_97 * V_98 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_800 ] ,
. V_258 = & V_795 -> args ,
. V_259 = & V_795 -> V_33 ,
} ;
struct V_141 V_261 = {
. V_143 = V_46 -> V_79 ,
. V_138 = & V_139 ,
. V_144 = & V_801 ,
. V_146 = V_795 ,
. V_176 = V_265 ,
} ;
int V_250 = 0 ;
F_2 ( L_17 , V_13 ) ;
V_795 -> V_33 . V_802 = & V_795 -> args . V_796 ;
V_795 -> V_33 . V_137 . V_110 = NULL ;
F_49 ( & V_795 -> args . V_136 , & V_795 -> V_33 . V_137 , 0 ) ;
V_98 = F_61 ( & V_261 ) ;
if ( F_62 ( V_98 ) )
return F_63 ( V_98 ) ;
V_250 = F_97 ( V_98 ) ;
if ( V_250 == 0 )
V_250 = V_98 -> V_148 ;
if ( V_250 == 0 )
V_250 = F_445 ( V_795 ) ;
F_64 ( V_98 ) ;
F_2 ( L_23 , V_13 , V_250 ) ;
return V_250 ;
}
static void
F_446 ( struct V_97 * V_98 , void * V_132 )
{
struct V_803 * V_804 = V_132 ;
F_2 ( L_17 , V_13 ) ;
if ( F_50 ( V_804 -> V_32 -> V_72 , & V_804 -> args . V_136 ,
& V_804 -> V_33 . V_137 , V_98 ) )
return;
F_57 ( V_98 ) ;
}
static void F_447 ( struct V_97 * V_98 , void * V_132 )
{
struct V_803 * V_804 = V_132 ;
struct V_45 * V_46 ;
struct V_805 * V_806 = V_804 -> args . V_796 ;
F_2 ( L_17 , V_13 ) ;
if ( ! F_45 ( V_98 , & V_804 -> V_33 . V_137 ) )
return;
V_46 = F_77 ( V_804 -> args . V_52 ) ;
if ( F_189 ( V_98 , V_46 , NULL ) == - V_128 ) {
F_190 ( V_98 ) ;
return;
}
F_26 ( & V_806 -> V_807 -> V_156 ) ;
if ( V_98 -> V_148 == 0 ) {
if ( V_804 -> V_33 . V_808 ) {
F_448 ( V_806 , & V_804 -> V_33 . V_207 , true ) ;
} else
F_4 ( ! F_449 ( & V_806 -> V_809 ) ) ;
}
V_806 -> V_810 -- ;
F_28 ( & V_806 -> V_807 -> V_156 ) ;
F_2 ( L_66 , V_13 ) ;
}
static void F_450 ( void * V_132 )
{
struct V_803 * V_804 = V_132 ;
F_2 ( L_17 , V_13 ) ;
F_451 ( V_804 -> args . V_796 ) ;
F_86 ( V_132 ) ;
F_2 ( L_66 , V_13 ) ;
}
int F_452 ( struct V_803 * V_804 )
{
struct V_97 * V_98 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_811 ] ,
. V_258 = & V_804 -> args ,
. V_259 = & V_804 -> V_33 ,
} ;
struct V_141 V_261 = {
. V_143 = V_804 -> V_32 -> V_512 ,
. V_138 = & V_139 ,
. V_144 = & V_812 ,
. V_146 = V_804 ,
} ;
int V_250 ;
F_2 ( L_17 , V_13 ) ;
F_49 ( & V_804 -> args . V_136 , & V_804 -> V_33 . V_137 , 1 ) ;
V_98 = F_61 ( & V_261 ) ;
if ( F_62 ( V_98 ) )
return F_63 ( V_98 ) ;
V_250 = V_98 -> V_148 ;
F_2 ( L_23 , V_13 , V_250 ) ;
F_64 ( V_98 ) ;
return V_250 ;
}
static int F_453 ( struct V_45 * V_46 ,
const struct V_343 * V_186 ,
struct V_813 * V_814 )
{
struct V_815 args = {
. V_186 = V_186 ,
. V_816 = V_46 -> V_817 -> V_191 ,
} ;
struct V_818 V_33 = {
. V_814 = V_814 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_819 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
int V_250 ;
F_2 ( L_17 , V_13 ) ;
V_250 = F_68 ( V_46 -> V_79 , V_46 , & V_139 , & args . V_136 ,
& V_33 . V_137 , 0 ) ;
F_2 ( L_23 , V_13 , V_250 ) ;
return V_250 ;
}
int F_454 ( struct V_45 * V_46 ,
const struct V_343 * V_186 ,
struct V_813 * V_814 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_46 ,
F_453 ( V_46 , V_186 , V_814 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
F_2 ( L_88 , V_13 ,
V_1 , V_814 -> V_820 ) ;
return V_1 ;
}
static int
F_455 ( struct V_45 * V_46 , struct V_821 * V_822 )
{
struct V_823 args = {
. V_822 = V_822 ,
} ;
struct V_824 V_33 = {
. V_822 = V_822 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_825 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
int V_250 ;
F_2 ( L_17 , V_13 ) ;
V_250 = F_68 ( V_46 -> V_79 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
F_2 ( L_23 , V_13 , V_250 ) ;
return V_250 ;
}
int F_456 ( struct V_45 * V_46 , struct V_821 * V_822 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_46 ,
F_455 ( V_46 , V_822 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static void F_457 ( struct V_97 * V_98 , void * V_132 )
{
struct V_826 * V_134 = V_132 ;
struct V_45 * V_46 = F_77 ( V_134 -> args . V_52 ) ;
if ( F_54 ( V_46 , & V_134 -> args . V_136 ,
& V_134 -> V_33 . V_137 , V_98 ) )
return;
F_57 ( V_98 ) ;
}
static void
F_458 ( struct V_97 * V_98 , void * V_132 )
{
struct V_826 * V_134 = V_132 ;
struct V_45 * V_46 = F_77 ( V_134 -> args . V_52 ) ;
if ( ! F_45 ( V_98 , & V_134 -> V_33 . V_137 ) )
return;
switch ( V_98 -> V_148 ) {
case - V_58 :
case - V_827 :
case - V_828 :
case - V_76 :
V_98 -> V_148 = 0 ;
break;
case 0 :
F_290 ( V_134 -> args . V_52 ,
V_134 -> V_33 . V_318 ) ;
break;
default:
if ( F_189 ( V_98 , V_46 , NULL ) == - V_128 ) {
F_190 ( V_98 ) ;
return;
}
}
}
static void F_459 ( void * V_132 )
{
struct V_826 * V_134 = V_132 ;
struct V_829 * V_830 , * V_831 ;
unsigned long * V_832 = & F_70 ( V_134 -> args . V_52 ) -> V_176 ;
F_460 ( V_134 ) ;
F_461 (lseg, tmp, &data->lseg_list, pls_lc_list) {
F_462 ( & V_830 -> V_833 ) ;
if ( F_423 ( V_834 ,
& V_830 -> V_835 ) )
F_463 ( V_830 ) ;
}
F_464 ( V_836 , V_832 ) ;
F_465 () ;
F_466 ( V_832 , V_836 ) ;
F_396 ( V_134 -> V_305 ) ;
F_86 ( V_134 ) ;
}
int
F_467 ( struct V_826 * V_134 , bool V_837 )
{
struct V_138 V_139 = {
. V_255 = & V_256 [ V_838 ] ,
. V_258 = & V_134 -> args ,
. V_259 = & V_134 -> V_33 ,
. V_260 = V_134 -> V_305 ,
} ;
struct V_141 V_261 = {
. V_98 = & V_134 -> V_98 ,
. V_143 = F_231 ( V_134 -> args . V_52 ) ,
. V_138 = & V_139 ,
. V_144 = & V_839 ,
. V_146 = V_134 ,
. V_176 = V_265 ,
} ;
struct V_97 * V_98 ;
int V_250 = 0 ;
F_2 ( L_89
L_90 ,
V_134 -> V_98 . V_840 , V_837 ,
V_134 -> args . V_841 ,
V_134 -> args . V_52 -> V_842 ) ;
F_49 ( & V_134 -> args . V_136 , & V_134 -> V_33 . V_137 , 1 ) ;
V_98 = F_61 ( & V_261 ) ;
if ( F_62 ( V_98 ) )
return F_63 ( V_98 ) ;
if ( V_837 == false )
goto V_115;
V_250 = F_97 ( V_98 ) ;
if ( V_250 != 0 )
goto V_115;
V_250 = V_98 -> V_148 ;
V_115:
F_2 ( L_91 , V_13 , V_250 ) ;
F_64 ( V_98 ) ;
return V_250 ;
}
static int
F_468 ( struct V_45 * V_46 , struct V_343 * V_344 ,
struct V_371 * V_372 , struct V_685 * V_686 )
{
struct V_843 args = {
. V_844 = V_845 ,
} ;
struct V_688 V_33 = {
. V_686 = V_686 ,
} ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_846 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
return F_68 ( V_46 -> V_79 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 0 ) ;
}
static int
F_469 ( struct V_45 * V_46 , struct V_343 * V_344 ,
struct V_371 * V_372 , struct V_685 * V_686 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_468 ( V_46 , V_344 , V_372 , V_686 ) ;
switch ( V_1 ) {
case 0 :
case - V_4 :
case - V_847 :
goto V_115;
default:
V_1 = F_16 ( V_46 , V_1 , & V_49 ) ;
}
} while ( V_49 . V_54 );
V_115:
return V_1 ;
}
static int
F_470 ( struct V_45 * V_46 , struct V_343 * V_344 ,
struct V_371 * V_372 )
{
int V_1 ;
struct V_392 * V_392 ;
T_7 V_376 ;
struct V_685 * V_686 ;
V_392 = F_216 ( V_308 ) ;
if ( ! V_392 ) {
V_1 = - V_239 ;
goto V_115;
}
V_686 = F_312 ( V_392 ) ;
V_1 = F_469 ( V_46 , V_344 , V_372 , V_686 ) ;
if ( V_1 == - V_4 || V_1 == - V_847 ) {
V_1 = F_207 ( V_46 , V_344 , V_372 ) ;
goto V_848;
}
if ( V_1 )
goto V_848;
V_376 = F_471 ( V_686 ) ;
if ( V_1 == 0 )
V_1 = F_205 ( V_46 , V_344 , V_372 , V_376 ) ;
V_848:
F_324 ( V_392 ) ;
if ( V_1 == - V_10 )
return - V_5 ;
V_115:
return V_1 ;
}
static int F_472 ( struct V_45 * V_46 , T_6 * V_207 )
{
int V_250 ;
struct V_849 args = {
. V_207 = V_207 ,
} ;
struct V_850 V_33 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_851 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
F_49 ( & args . V_136 , & V_33 . V_137 , 0 ) ;
V_250 = F_60 ( V_46 -> V_79 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 1 ) ;
if ( V_250 == V_114 )
return V_33 . V_250 ;
return V_250 ;
}
static int F_168 ( struct V_45 * V_46 , T_6 * V_207 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_46 ,
F_472 ( V_46 , V_207 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static int F_473 ( struct V_45 * V_46 , T_6 * V_207 )
{
struct V_852 args = {
. V_207 = V_207 ,
} ;
struct V_853 V_33 ;
struct V_138 V_139 = {
. V_255 = & V_256 [ V_854 ] ,
. V_258 = & args ,
. V_259 = & V_33 ,
} ;
F_49 ( & args . V_136 , & V_33 . V_137 , 0 ) ;
return F_60 ( V_46 -> V_79 , V_46 , & V_139 , & args . V_136 , & V_33 . V_137 , 1 ) ;
}
static int F_169 ( struct V_45 * V_46 , T_6 * V_207 )
{
struct V_48 V_49 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_46 ,
F_473 ( V_46 , V_207 ) ,
& V_49 ) ;
} while ( V_49 . V_54 );
return V_1 ;
}
static bool F_474 ( const T_6 * V_855 ,
const T_6 * V_856 )
{
if ( memcmp ( V_855 -> V_857 , V_856 -> V_857 , sizeof( V_855 -> V_857 ) ) != 0 )
return false ;
if ( V_855 -> V_167 == V_856 -> V_167 )
return true ;
if ( V_855 -> V_167 == 0 || V_856 -> V_167 == 0 )
return true ;
return false ;
}
static bool F_475 ( const T_6 * V_855 ,
const T_6 * V_856 )
{
return F_114 ( V_855 , V_856 ) ;
}
