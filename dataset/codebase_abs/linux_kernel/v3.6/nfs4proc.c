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
if ( V_33 )
return V_33 ;
if ( V_32 -> V_38 < 0 )
return V_32 -> V_38 ;
return 0 ;
}
static int F_13 ( struct V_39 * V_40 , long * V_41 )
{
int V_33 = 0 ;
F_11 () ;
if ( * V_41 <= 0 )
* V_41 = V_42 ;
if ( * V_41 > V_43 )
* V_41 = V_43 ;
F_14 ( * V_41 ) ;
if ( F_15 ( V_44 ) )
V_33 = - V_45 ;
* V_41 <<= 1 ;
return V_33 ;
}
static int F_16 ( struct V_46 * V_47 , int V_48 , struct V_49 * V_50 )
{
struct V_31 * V_32 = V_47 -> V_31 ;
struct V_51 * V_52 = V_50 -> V_52 ;
struct V_53 * V_53 = V_50 -> V_53 ;
int V_54 = V_48 ;
V_50 -> V_55 = 0 ;
switch( V_48 ) {
case 0 :
return 0 ;
case - V_56 :
if ( V_53 && F_17 ( V_53 , V_57 ) ) {
F_18 ( V_53 ) ;
V_50 -> V_55 = 1 ;
return 0 ;
}
if ( V_52 == NULL )
break;
F_19 ( V_47 , V_52 ) ;
goto V_58;
case - V_59 :
case - V_60 :
case - V_61 :
if ( V_52 == NULL )
break;
F_20 ( V_52 -> V_53 ) ;
F_19 ( V_47 , V_52 ) ;
goto V_58;
case - V_62 :
if ( V_52 != NULL )
F_19 ( V_47 , V_52 ) ;
case - V_63 :
case - V_64 :
F_21 ( V_32 ) ;
goto V_58;
#if F_22 ( V_65 )
case - V_66 :
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
case - V_71 :
case - V_72 :
F_2 ( L_4 , V_13 ,
V_48 ) ;
F_23 ( V_32 -> V_73 , V_48 ) ;
V_50 -> V_55 = 1 ;
break;
#endif
case - V_74 :
if ( V_50 -> V_41 > V_75 ) {
V_54 = - V_76 ;
break;
}
case - V_77 :
case - V_78 :
case - V_79 :
V_54 = F_13 ( V_47 -> V_80 , & V_50 -> V_41 ) ;
if ( V_54 != 0 )
break;
case - V_81 :
case - V_82 :
V_50 -> V_55 = 1 ;
break;
case - V_6 :
case - V_7 :
if ( V_47 -> V_83 & V_84 ) {
V_47 -> V_83 &= ~ V_84 ;
V_50 -> V_55 = 1 ;
F_24 ( V_85 L_5
L_6
L_7
L_8 ,
V_47 -> V_31 -> V_86 ) ;
}
}
return F_1 ( V_54 ) ;
V_58:
V_54 = F_10 ( V_32 ) ;
if ( V_54 == 0 )
V_50 -> V_55 = 1 ;
return V_54 ;
}
static void F_25 ( struct V_31 * V_32 , unsigned long V_87 )
{
F_26 ( & V_32 -> V_88 ) ;
if ( F_27 ( V_32 -> V_89 , V_87 ) )
V_32 -> V_89 = V_87 ;
F_28 ( & V_32 -> V_88 ) ;
}
static void F_29 ( const struct V_46 * V_47 , unsigned long V_87 )
{
F_25 ( V_47 -> V_31 , V_87 ) ;
}
static void
F_30 ( struct V_90 * V_91 , T_3 V_92 )
{
F_4 ( V_92 >= V_93 ) ;
F_31 ( V_92 , V_91 -> V_94 ) ;
if ( V_92 == V_91 -> V_95 ) {
V_92 = F_32 ( V_91 -> V_94 , V_91 -> V_96 ) ;
if ( V_92 < V_91 -> V_96 )
V_91 -> V_95 = V_92 ;
else
V_91 -> V_95 = V_97 ;
}
F_2 ( L_9 , V_13 ,
V_92 , V_91 -> V_95 ) ;
}
bool F_33 ( struct V_98 * V_99 , void * V_100 )
{
F_34 ( V_99 , V_101 ) ;
return true ;
}
static void F_35 ( struct V_102 * V_103 )
{
if ( ! F_36 ( V_104 , & V_103 -> V_105 ) ) {
F_37 ( & V_103 -> V_106 . V_107 ,
F_33 , NULL ) ;
return;
}
if ( V_103 -> V_106 . V_95 != V_97 )
return;
F_2 ( L_10 , V_13 ) ;
F_38 ( & V_103 -> V_106 . F_38 ) ;
}
void F_39 ( struct V_102 * V_103 )
{
if ( ! F_36 ( V_104 , & V_103 -> V_105 ) ||
V_103 -> V_108 . V_95 != V_97 )
return;
F_2 ( L_11 , V_13 ) ;
F_38 ( & V_103 -> V_108 . F_38 ) ;
}
static void F_40 ( struct V_109 * V_33 )
{
struct V_90 * V_91 ;
V_91 = & V_33 -> V_110 -> V_106 ;
if ( ! V_33 -> V_111 ) {
F_2 ( L_12 , V_13 ) ;
return;
}
F_26 ( & V_91 -> V_112 ) ;
F_30 ( V_91 , V_33 -> V_111 - V_91 -> V_113 ) ;
F_35 ( V_33 -> V_110 ) ;
F_28 ( & V_91 -> V_112 ) ;
V_33 -> V_111 = NULL ;
}
static int F_41 ( struct V_98 * V_99 , struct V_109 * V_33 )
{
unsigned long V_87 ;
struct V_31 * V_32 ;
if ( V_33 -> V_114 == 1 )
V_33 -> V_114 = V_115 ;
if ( ! F_42 ( V_99 ) )
goto V_116;
switch ( V_33 -> V_114 ) {
case 0 :
++ V_33 -> V_111 -> V_117 ;
V_87 = V_33 -> V_118 ;
V_32 = V_33 -> V_110 -> V_32 ;
F_25 ( V_32 , V_87 ) ;
if ( V_33 -> V_119 != 0 )
F_21 ( V_32 ) ;
break;
case - V_78 :
F_2 ( L_13 ,
V_13 ,
V_33 -> V_111 - V_33 -> V_110 -> V_106 . V_113 ,
V_33 -> V_111 -> V_117 ) ;
goto V_120;
default:
++ V_33 -> V_111 -> V_117 ;
}
V_116:
F_2 ( L_14 , V_13 , V_33 -> V_114 ) ;
F_40 ( V_33 ) ;
return 1 ;
V_120:
if ( ! F_43 ( V_99 ) )
goto V_116;
F_44 ( V_99 , V_43 ) ;
return 0 ;
}
static int F_45 ( struct V_98 * V_99 ,
struct V_109 * V_33 )
{
if ( V_33 -> V_110 == NULL )
return 1 ;
return F_41 ( V_99 , V_33 ) ;
}
static T_3
F_46 ( struct V_90 * V_91 )
{
T_3 V_92 ;
T_3 V_121 = V_97 ;
F_2 ( L_15 ,
V_13 , V_91 -> V_94 [ 0 ] , V_91 -> V_95 ,
V_91 -> V_96 ) ;
V_92 = F_47 ( V_91 -> V_94 , V_91 -> V_96 ) ;
if ( V_92 >= V_91 -> V_96 )
goto V_116;
F_48 ( V_92 , V_91 -> V_94 ) ;
if ( V_92 > V_91 -> V_95 ||
V_91 -> V_95 == V_97 )
V_91 -> V_95 = V_92 ;
V_121 = V_92 ;
V_116:
F_2 ( L_16 ,
V_13 , V_91 -> V_94 [ 0 ] , V_91 -> V_95 , V_121 ) ;
return V_121 ;
}
static void F_49 ( struct V_122 * args ,
struct V_109 * V_33 , int V_123 )
{
args -> V_124 = NULL ;
args -> V_125 = 0 ;
if ( V_123 )
args -> V_125 = 1 ;
V_33 -> V_110 = NULL ;
V_33 -> V_111 = NULL ;
}
int F_50 ( struct V_102 * V_126 ,
struct V_122 * args ,
struct V_109 * V_33 ,
struct V_98 * V_99 )
{
struct V_127 * V_128 ;
struct V_90 * V_91 ;
T_3 V_92 ;
F_2 ( L_17 , V_13 ) ;
if ( V_33 -> V_111 != NULL )
return 0 ;
V_91 = & V_126 -> V_106 ;
F_26 ( & V_91 -> V_112 ) ;
if ( F_36 ( V_104 , & V_126 -> V_105 ) &&
! F_51 ( V_99 , V_101 ) ) {
F_52 ( & V_91 -> V_107 , V_99 , NULL ) ;
F_28 ( & V_91 -> V_112 ) ;
F_2 ( L_18 , V_13 ) ;
return - V_129 ;
}
if ( ! F_53 ( & V_91 -> V_107 ) &&
! F_51 ( V_99 , V_101 ) ) {
F_52 ( & V_91 -> V_107 , V_99 , NULL ) ;
F_28 ( & V_91 -> V_112 ) ;
F_2 ( L_19 , V_13 ) ;
return - V_129 ;
}
V_92 = F_46 ( V_91 ) ;
if ( V_92 == V_97 ) {
F_52 ( & V_91 -> V_107 , V_99 , NULL ) ;
F_28 ( & V_91 -> V_112 ) ;
F_2 ( L_20 , V_13 ) ;
return - V_129 ;
}
F_28 ( & V_91 -> V_112 ) ;
F_34 ( V_99 , V_130 ) ;
V_128 = V_91 -> V_113 + V_92 ;
args -> V_124 = V_126 ;
args -> V_131 = V_92 ;
F_2 ( L_21 , V_13 , V_92 , V_128 -> V_117 ) ;
V_33 -> V_110 = V_126 ;
V_33 -> V_111 = V_128 ;
V_33 -> V_118 = V_132 ;
V_33 -> V_119 = 0 ;
V_33 -> V_114 = 1 ;
return 0 ;
}
int F_54 ( const struct V_46 * V_47 ,
struct V_122 * args ,
struct V_109 * V_33 ,
struct V_98 * V_99 )
{
struct V_102 * V_126 = F_55 ( V_47 ) ;
int V_54 = 0 ;
if ( V_126 == NULL )
goto V_116;
F_2 ( L_22 ,
V_13 , V_126 -> V_32 , V_126 , V_33 -> V_111 ?
V_33 -> V_111 - V_126 -> V_106 . V_113 : - 1 ) ;
V_54 = F_50 ( V_126 , args , V_33 , V_99 ) ;
V_116:
F_2 ( L_23 , V_13 , V_54 ) ;
return V_54 ;
}
static void F_56 ( struct V_98 * V_99 , void * V_133 )
{
struct V_134 * V_135 = V_133 ;
F_2 ( L_24 , V_13 , V_135 -> V_136 ) ;
if ( F_54 ( V_135 -> V_136 , V_135 -> V_137 ,
V_135 -> V_138 , V_99 ) )
return;
F_57 ( V_99 ) ;
}
static void F_58 ( struct V_98 * V_99 , void * V_133 )
{
F_34 ( V_99 , V_101 ) ;
F_56 ( V_99 , V_133 ) ;
}
static void F_59 ( struct V_98 * V_99 , void * V_133 )
{
struct V_134 * V_135 = V_133 ;
F_41 ( V_99 , V_135 -> V_138 ) ;
}
static int F_60 ( struct V_39 * V_40 ,
struct V_46 * V_47 ,
struct V_139 * V_140 ,
struct V_122 * args ,
struct V_109 * V_33 ,
int V_141 )
{
int V_54 ;
struct V_98 * V_99 ;
struct V_134 V_135 = {
. V_136 = V_47 ,
. V_137 = args ,
. V_138 = V_33 ,
} ;
struct V_142 V_143 = {
. V_144 = V_40 ,
. V_139 = V_140 ,
. V_145 = & V_146 ,
. V_147 = & V_135
} ;
if ( V_141 )
V_143 . V_145 = & V_148 ;
V_99 = F_61 ( & V_143 ) ;
if ( F_62 ( V_99 ) )
V_54 = F_63 ( V_99 ) ;
else {
V_54 = V_99 -> V_149 ;
F_64 ( V_99 ) ;
}
return V_54 ;
}
int F_65 ( struct V_39 * V_40 ,
struct V_46 * V_47 ,
struct V_139 * V_140 ,
struct V_122 * args ,
struct V_109 * V_33 ,
int V_123 )
{
F_49 ( args , V_33 , V_123 ) ;
return F_60 ( V_40 , V_47 , V_140 , args , V_33 , 0 ) ;
}
static inline
void F_49 ( struct V_122 * args ,
struct V_109 * V_33 , int V_123 )
{
}
static int F_45 ( struct V_98 * V_99 ,
struct V_109 * V_33 )
{
return 1 ;
}
int F_66 ( struct V_39 * V_40 ,
struct V_46 * V_47 ,
struct V_139 * V_140 ,
struct V_122 * args ,
struct V_109 * V_33 ,
int V_123 )
{
F_49 ( args , V_33 , V_123 ) ;
return F_67 ( V_40 , V_140 , 0 ) ;
}
static inline
int F_68 ( struct V_39 * V_40 ,
struct V_46 * V_47 ,
struct V_139 * V_140 ,
struct V_122 * args ,
struct V_109 * V_33 ,
int V_123 )
{
return V_47 -> V_31 -> V_150 -> V_151 ( V_40 , V_47 , V_140 ,
args , V_33 , V_123 ) ;
}
static void F_69 ( struct V_53 * V_152 , struct V_153 * V_154 )
{
struct V_155 * V_156 = F_70 ( V_152 ) ;
F_26 ( & V_152 -> V_157 ) ;
V_156 -> V_158 |= V_159 | V_160 ;
if ( ! V_154 -> V_161 || V_154 -> V_162 != V_152 -> V_163 )
F_71 ( V_152 ) ;
V_152 -> V_163 = V_154 -> V_164 ;
F_28 ( & V_152 -> V_157 ) ;
}
static void F_72 ( struct V_165 * V_21 )
{
V_21 -> V_166 . V_167 = & V_21 -> V_167 ;
V_21 -> V_166 . V_168 = V_21 -> V_169 . V_168 ;
V_21 -> V_170 . V_168 = V_21 -> V_171 . V_168 ;
V_21 -> V_166 . V_47 = V_21 -> V_169 . V_47 ;
F_73 ( & V_21 -> V_167 ) ;
F_74 ( & V_21 -> V_167 , & V_21 -> V_172 , & V_21 -> V_173 ) ;
}
static struct V_165 * F_75 ( struct V_17 * V_17 ,
struct V_174 * V_175 , T_4 V_176 , int V_177 ,
const struct V_178 * V_179 ,
T_5 V_180 )
{
struct V_17 * V_181 = F_76 ( V_17 ) ;
struct V_53 * V_152 = V_181 -> V_27 ;
struct V_46 * V_47 = F_77 ( V_152 ) ;
struct V_165 * V_21 ;
V_21 = F_78 ( sizeof( * V_21 ) , V_180 ) ;
if ( V_21 == NULL )
goto V_1;
V_21 -> V_169 . V_168 = F_79 ( & V_175 -> V_182 , V_180 ) ;
if ( V_21 -> V_169 . V_168 == NULL )
goto V_183;
F_80 ( V_17 -> V_184 ) ;
V_21 -> V_17 = F_81 ( V_17 ) ;
V_21 -> V_152 = V_181 ;
V_21 -> V_185 = V_175 ;
F_82 ( & V_175 -> V_186 ) ;
V_21 -> V_169 . V_187 = F_83 ( V_152 ) ;
V_21 -> V_169 . V_188 = V_177 ;
V_21 -> V_169 . V_176 = V_176 & ( V_57 | V_189 ) ;
V_21 -> V_169 . V_190 = V_47 -> V_31 -> V_191 ;
V_21 -> V_169 . V_192 . V_193 = F_84 ( V_175 -> V_182 . V_193 ) ;
V_21 -> V_169 . V_192 . V_194 = V_175 -> V_182 . V_195 ;
V_21 -> V_169 . V_196 = & V_17 -> V_197 ;
V_21 -> V_169 . V_47 = V_47 ;
V_21 -> V_169 . V_198 = V_47 -> V_199 ;
V_21 -> V_169 . V_200 = & V_201 [ 0 ] ;
V_21 -> V_169 . V_202 = V_203 ;
if ( V_179 != NULL && V_179 -> V_204 != 0 ) {
T_2 V_205 [ 2 ] ;
V_21 -> V_169 . V_206 . V_179 = & V_21 -> V_179 ;
memcpy ( & V_21 -> V_179 , V_179 , sizeof( V_21 -> V_179 ) ) ;
V_205 [ 0 ] = V_132 ;
V_205 [ 1 ] = V_44 -> V_207 ;
memcpy ( V_21 -> V_169 . V_206 . V_16 . V_135 , V_205 ,
sizeof( V_21 -> V_169 . V_206 . V_16 . V_135 ) ) ;
}
V_21 -> V_171 . V_187 = & V_21 -> V_166 . V_187 ;
V_21 -> V_171 . V_208 = & V_21 -> V_166 . V_208 ;
V_21 -> V_171 . V_168 = V_21 -> V_169 . V_168 ;
F_72 ( V_21 ) ;
F_85 ( & V_21 -> V_209 ) ;
return V_21 ;
V_183:
F_86 ( V_21 ) ;
V_1:
F_87 ( V_181 ) ;
return NULL ;
}
static void F_88 ( struct V_209 * V_209 )
{
struct V_165 * V_21 = F_89 ( V_209 ,
struct V_165 , V_209 ) ;
struct V_210 * V_211 = V_21 -> V_17 -> V_184 ;
F_90 ( V_21 -> V_169 . V_168 ) ;
if ( V_21 -> V_52 != NULL )
F_91 ( V_21 -> V_52 ) ;
F_92 ( V_21 -> V_185 ) ;
F_87 ( V_21 -> V_152 ) ;
F_87 ( V_21 -> V_17 ) ;
F_93 ( V_211 ) ;
F_94 ( & V_21 -> V_167 ) ;
F_86 ( V_21 ) ;
}
static void F_95 ( struct V_165 * V_21 )
{
if ( V_21 != NULL )
F_96 ( & V_21 -> V_209 , F_88 ) ;
}
static int F_97 ( struct V_98 * V_99 )
{
int V_54 ;
V_54 = F_98 ( V_99 ) ;
return V_54 ;
}
static int F_99 ( struct V_51 * V_52 , T_4 V_212 , int V_213 )
{
int V_54 = 0 ;
if ( V_213 & ( V_214 | V_215 ) )
goto V_116;
switch ( V_212 & ( V_57 | V_189 ) ) {
case V_57 :
V_54 |= F_36 ( V_216 , & V_52 -> V_177 ) != 0
&& V_52 -> V_217 != 0 ;
break;
case V_189 :
V_54 |= F_36 ( V_218 , & V_52 -> V_177 ) != 0
&& V_52 -> V_219 != 0 ;
break;
case V_57 | V_189 :
V_54 |= F_36 ( V_220 , & V_52 -> V_177 ) != 0
&& V_52 -> V_221 != 0 ;
}
V_116:
return V_54 ;
}
static int F_100 ( struct V_222 * V_223 , T_4 V_176 )
{
if ( V_223 == NULL )
return 0 ;
if ( ( V_223 -> type & V_176 ) != V_176 )
return 0 ;
if ( F_36 ( V_224 , & V_223 -> V_177 ) )
return 0 ;
F_101 ( V_223 ) ;
return 1 ;
}
static void F_102 ( struct V_51 * V_52 , T_4 V_176 )
{
switch ( V_176 ) {
case V_189 :
V_52 -> V_219 ++ ;
break;
case V_57 :
V_52 -> V_217 ++ ;
break;
case V_57 | V_189 :
V_52 -> V_221 ++ ;
}
F_103 ( V_52 , V_52 -> V_52 | V_176 ) ;
}
static void F_104 ( struct V_51 * V_52 , T_6 * V_208 , T_4 V_176 )
{
if ( F_36 ( V_225 , & V_52 -> V_177 ) == 0 )
F_105 ( & V_52 -> V_208 , V_208 ) ;
F_105 ( & V_52 -> V_226 , V_208 ) ;
switch ( V_176 ) {
case V_57 :
F_106 ( V_216 , & V_52 -> V_177 ) ;
break;
case V_189 :
F_106 ( V_218 , & V_52 -> V_177 ) ;
break;
case V_57 | V_189 :
F_106 ( V_220 , & V_52 -> V_177 ) ;
}
}
static void F_107 ( struct V_51 * V_52 , T_6 * V_208 , T_4 V_176 )
{
F_108 ( & V_52 -> V_227 ) ;
F_104 ( V_52 , V_208 , V_176 ) ;
F_109 ( & V_52 -> V_227 ) ;
}
static void F_110 ( struct V_51 * V_52 , T_6 * V_226 , const T_6 * V_228 , T_4 V_176 )
{
F_108 ( & V_52 -> V_227 ) ;
if ( V_228 != NULL ) {
F_105 ( & V_52 -> V_208 , V_228 ) ;
F_106 ( V_225 , & V_52 -> V_177 ) ;
}
if ( V_226 != NULL )
F_104 ( V_52 , V_226 , V_176 ) ;
F_109 ( & V_52 -> V_227 ) ;
F_26 ( & V_52 -> V_185 -> V_229 ) ;
F_102 ( V_52 , V_176 ) ;
F_28 ( & V_52 -> V_185 -> V_229 ) ;
}
static int F_111 ( struct V_51 * V_52 , T_6 * V_226 , T_6 * V_223 , T_4 V_176 )
{
struct V_155 * V_156 = F_70 ( V_52 -> V_53 ) ;
struct V_222 * V_230 ;
int V_54 = 0 ;
V_176 &= ( V_57 | V_189 ) ;
F_112 () ;
V_230 = F_113 ( V_156 -> V_223 ) ;
if ( V_230 == NULL )
goto V_231;
F_26 ( & V_230 -> V_232 ) ;
if ( V_156 -> V_223 != V_230 ||
( V_230 -> type & V_176 ) != V_176 )
goto V_233;
if ( V_223 == NULL )
V_223 = & V_230 -> V_208 ;
else if ( ! F_114 ( & V_230 -> V_208 , V_223 ) )
goto V_233;
F_101 ( V_230 ) ;
F_110 ( V_52 , V_226 , & V_230 -> V_208 , V_176 ) ;
V_54 = 1 ;
V_233:
F_28 ( & V_230 -> V_232 ) ;
V_231:
F_115 () ;
if ( ! V_54 && V_226 != NULL ) {
F_110 ( V_52 , V_226 , NULL , V_176 ) ;
V_54 = 1 ;
}
return V_54 ;
}
static void F_116 ( struct V_53 * V_53 , T_4 V_176 )
{
struct V_222 * V_223 ;
F_112 () ;
V_223 = F_113 ( F_70 ( V_53 ) -> V_223 ) ;
if ( V_223 == NULL || ( V_223 -> type & V_176 ) == V_176 ) {
F_115 () ;
return;
}
F_115 () ;
F_18 ( V_53 ) ;
}
static struct V_51 * F_117 ( struct V_165 * V_234 )
{
struct V_51 * V_52 = V_234 -> V_52 ;
struct V_155 * V_156 = F_70 ( V_52 -> V_53 ) ;
struct V_222 * V_223 ;
int V_213 = V_234 -> V_169 . V_188 & ( V_214 | V_215 ) ;
T_4 V_176 = V_234 -> V_169 . V_176 ;
T_6 V_208 ;
int V_54 = - V_129 ;
for (; ; ) {
if ( F_99 ( V_52 , V_176 , V_213 ) ) {
F_26 ( & V_52 -> V_185 -> V_229 ) ;
if ( F_99 ( V_52 , V_176 , V_213 ) ) {
F_102 ( V_52 , V_176 ) ;
F_28 ( & V_52 -> V_185 -> V_229 ) ;
goto V_235;
}
F_28 ( & V_52 -> V_185 -> V_229 ) ;
}
F_112 () ;
V_223 = F_113 ( V_156 -> V_223 ) ;
if ( ! F_100 ( V_223 , V_176 ) ) {
F_115 () ;
break;
}
F_105 ( & V_208 , & V_223 -> V_208 ) ;
F_115 () ;
V_54 = F_118 ( V_52 -> V_53 , V_52 -> V_185 -> V_236 , V_213 ) ;
if ( V_54 != 0 )
goto V_116;
V_54 = - V_129 ;
if ( F_111 ( V_52 , NULL , & V_208 , V_176 ) )
goto V_235;
}
V_116:
return F_119 ( V_54 ) ;
V_235:
F_82 ( & V_52 -> V_22 ) ;
return V_52 ;
}
static struct V_51 * F_120 ( struct V_165 * V_135 )
{
struct V_53 * V_53 ;
struct V_51 * V_52 = NULL ;
struct V_222 * V_223 ;
int V_54 ;
if ( ! V_135 -> V_237 ) {
V_52 = F_117 ( V_135 ) ;
goto V_116;
}
V_54 = - V_129 ;
if ( ! ( V_135 -> V_167 . V_238 & V_239 ) )
goto V_1;
V_53 = F_121 ( V_135 -> V_152 -> V_184 , & V_135 -> V_166 . V_187 , & V_135 -> V_167 ) ;
V_54 = F_63 ( V_53 ) ;
if ( F_62 ( V_53 ) )
goto V_1;
V_54 = - V_240 ;
V_52 = F_122 ( V_53 , V_135 -> V_185 ) ;
if ( V_52 == NULL )
goto V_241;
if ( V_135 -> V_166 . V_242 != 0 ) {
struct V_31 * V_32 = F_77 ( V_53 ) -> V_31 ;
int V_243 = 0 ;
F_112 () ;
V_223 = F_113 ( F_70 ( V_53 ) -> V_223 ) ;
if ( V_223 )
V_243 = V_223 -> V_177 ;
F_115 () ;
if ( V_135 -> V_169 . V_202 == V_244 ) {
F_123 ( L_25
L_26
L_27 ,
V_32 -> V_86 ) ;
} else if ( ( V_243 & 1UL << V_224 ) == 0 )
F_124 ( V_52 -> V_53 ,
V_135 -> V_185 -> V_236 ,
& V_135 -> V_166 ) ;
else
F_125 ( V_52 -> V_53 ,
V_135 -> V_185 -> V_236 ,
& V_135 -> V_166 ) ;
}
F_111 ( V_52 , & V_135 -> V_166 . V_208 , NULL ,
V_135 -> V_169 . V_176 ) ;
F_126 ( V_53 ) ;
V_116:
return V_52 ;
V_241:
F_126 ( V_53 ) ;
V_1:
return F_119 ( V_54 ) ;
}
static struct V_245 * F_127 ( struct V_51 * V_52 )
{
struct V_155 * V_156 = F_70 ( V_52 -> V_53 ) ;
struct V_245 * V_246 ;
F_26 ( & V_52 -> V_53 -> V_157 ) ;
F_128 (ctx, &nfsi->open_files, list) {
if ( V_246 -> V_52 != V_52 )
continue;
F_129 ( V_246 ) ;
F_28 ( & V_52 -> V_53 -> V_157 ) ;
return V_246 ;
}
F_28 ( & V_52 -> V_53 -> V_157 ) ;
return F_119 ( - V_247 ) ;
}
static struct V_165 * F_130 ( struct V_245 * V_246 , struct V_51 * V_52 )
{
struct V_165 * V_234 ;
V_234 = F_75 ( V_246 -> V_17 , V_52 -> V_185 , 0 , 0 , NULL , V_248 ) ;
if ( V_234 == NULL )
return F_119 ( - V_240 ) ;
V_234 -> V_52 = V_52 ;
F_82 ( & V_52 -> V_22 ) ;
return V_234 ;
}
static int F_131 ( struct V_165 * V_234 , T_4 V_176 , struct V_51 * * V_33 )
{
struct V_51 * V_249 ;
int V_54 ;
V_234 -> V_169 . V_188 = 0 ;
V_234 -> V_169 . V_176 = V_176 ;
memset ( & V_234 -> V_166 , 0 , sizeof( V_234 -> V_166 ) ) ;
memset ( & V_234 -> V_170 , 0 , sizeof( V_234 -> V_170 ) ) ;
F_72 ( V_234 ) ;
V_54 = F_132 ( V_234 ) ;
if ( V_54 != 0 )
return V_54 ;
V_249 = F_120 ( V_234 ) ;
if ( F_62 ( V_249 ) )
return F_63 ( V_249 ) ;
F_133 ( V_249 , V_176 ) ;
* V_33 = V_249 ;
return 0 ;
}
static int F_134 ( struct V_165 * V_234 , struct V_51 * V_52 )
{
struct V_51 * V_249 ;
int V_54 ;
F_135 ( V_225 , & V_52 -> V_177 ) ;
F_136 () ;
if ( V_52 -> V_221 != 0 ) {
F_135 ( V_220 , & V_52 -> V_177 ) ;
V_54 = F_131 ( V_234 , V_57 | V_189 , & V_249 ) ;
if ( V_54 != 0 )
return V_54 ;
if ( V_249 != V_52 )
return - V_250 ;
}
if ( V_52 -> V_219 != 0 ) {
F_135 ( V_218 , & V_52 -> V_177 ) ;
V_54 = F_131 ( V_234 , V_189 , & V_249 ) ;
if ( V_54 != 0 )
return V_54 ;
if ( V_249 != V_52 )
return - V_250 ;
}
if ( V_52 -> V_217 != 0 ) {
F_135 ( V_216 , & V_52 -> V_177 ) ;
V_54 = F_131 ( V_234 , V_57 , & V_249 ) ;
if ( V_54 != 0 )
return V_54 ;
if ( V_249 != V_52 )
return - V_250 ;
}
if ( F_36 ( V_225 , & V_52 -> V_177 ) == 0 &&
! F_114 ( & V_52 -> V_208 , & V_52 -> V_226 ) ) {
F_108 ( & V_52 -> V_227 ) ;
if ( F_36 ( V_225 , & V_52 -> V_177 ) == 0 )
F_105 ( & V_52 -> V_208 , & V_52 -> V_226 ) ;
F_109 ( & V_52 -> V_227 ) ;
}
return 0 ;
}
static int F_137 ( struct V_245 * V_246 , struct V_51 * V_52 )
{
struct V_222 * V_223 ;
struct V_165 * V_234 ;
T_4 V_242 = 0 ;
int V_251 ;
V_234 = F_130 ( V_246 , V_52 ) ;
if ( F_62 ( V_234 ) )
return F_63 ( V_234 ) ;
V_234 -> V_169 . V_202 = V_252 ;
V_234 -> V_169 . V_187 = F_83 ( V_52 -> V_53 ) ;
F_112 () ;
V_223 = F_113 ( F_70 ( V_52 -> V_53 ) -> V_223 ) ;
if ( V_223 != NULL && F_36 ( V_224 , & V_223 -> V_177 ) != 0 )
V_242 = V_223 -> type ;
F_115 () ;
V_234 -> V_169 . V_206 . V_242 = V_242 ;
V_251 = F_134 ( V_234 , V_52 ) ;
F_95 ( V_234 ) ;
return V_251 ;
}
static int F_138 ( struct V_245 * V_246 , struct V_51 * V_52 )
{
struct V_46 * V_47 = F_77 ( V_52 -> V_53 ) ;
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_137 ( V_246 , V_52 ) ;
if ( V_1 != - V_78 )
break;
F_16 ( V_47 , V_1 , & V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_139 ( struct V_174 * V_175 , struct V_51 * V_52 )
{
struct V_245 * V_246 ;
int V_54 ;
V_246 = F_127 ( V_52 ) ;
if ( F_62 ( V_246 ) )
return F_63 ( V_246 ) ;
V_54 = F_138 ( V_246 , V_52 ) ;
F_140 ( V_246 ) ;
return V_54 ;
}
static int F_141 ( struct V_245 * V_246 , struct V_51 * V_52 , const T_6 * V_208 )
{
struct V_165 * V_234 ;
int V_54 ;
V_234 = F_130 ( V_246 , V_52 ) ;
if ( F_62 ( V_234 ) )
return F_63 ( V_234 ) ;
V_234 -> V_169 . V_202 = V_244 ;
F_105 ( & V_234 -> V_169 . V_206 . V_223 , V_208 ) ;
V_54 = F_134 ( V_234 , V_52 ) ;
F_95 ( V_234 ) ;
return V_54 ;
}
int F_142 ( struct V_245 * V_246 , struct V_51 * V_52 , const T_6 * V_208 )
{
struct V_49 V_50 = { } ;
struct V_46 * V_47 = F_77 ( V_52 -> V_53 ) ;
int V_1 ;
do {
V_1 = F_141 ( V_246 , V_52 , V_208 ) ;
switch ( V_1 ) {
case 0 :
case - V_247 :
case - V_250 :
goto V_116;
case - V_66 :
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
F_23 ( V_47 -> V_31 -> V_73 , V_1 ) ;
goto V_116;
case - V_64 :
case - V_63 :
case - V_62 :
F_21 ( V_47 -> V_31 ) ;
goto V_116;
case - V_45 :
case - V_59 :
case - V_60 :
case - V_61 :
F_143 ( V_52 -> V_53 ,
V_208 ) ;
F_19 ( V_47 , V_52 ) ;
case - V_79 :
case - V_240 :
V_1 = 0 ;
goto V_116;
}
V_1 = F_16 ( V_47 , V_1 , & V_50 ) ;
} while ( V_50 . V_55 );
V_116:
return V_1 ;
}
static void F_144 ( struct V_98 * V_99 , void * V_133 )
{
struct V_165 * V_135 = V_133 ;
V_135 -> V_253 = V_99 -> V_149 ;
if ( V_135 -> V_253 == 0 ) {
F_105 ( & V_135 -> V_166 . V_208 , & V_135 -> V_170 . V_208 ) ;
F_145 ( & V_135 -> V_185 -> V_182 , 0 ) ;
F_29 ( V_135 -> V_166 . V_47 , V_135 -> V_87 ) ;
V_135 -> V_237 = 1 ;
}
}
static void F_146 ( void * V_133 )
{
struct V_165 * V_135 = V_133 ;
struct V_51 * V_52 = NULL ;
if ( V_135 -> V_254 == 0 )
goto V_255;
if ( ! V_135 -> V_237 )
goto V_255;
V_52 = F_120 ( V_135 ) ;
if ( ! F_62 ( V_52 ) )
F_133 ( V_52 , V_135 -> V_169 . V_176 ) ;
V_255:
F_95 ( V_135 ) ;
}
static int F_147 ( struct V_165 * V_135 )
{
struct V_46 * V_47 = F_77 ( V_135 -> V_152 -> V_27 ) ;
struct V_98 * V_99 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_258 ] ,
. V_259 = & V_135 -> V_171 ,
. V_260 = & V_135 -> V_170 ,
. V_261 = V_135 -> V_185 -> V_236 ,
} ;
struct V_142 V_262 = {
. V_144 = V_47 -> V_80 ,
. V_139 = & V_140 ,
. V_145 = & V_263 ,
. V_147 = V_135 ,
. V_264 = V_265 ,
. V_177 = V_266 ,
} ;
int V_251 ;
F_148 ( & V_135 -> V_209 ) ;
V_135 -> V_237 = 0 ;
V_135 -> V_253 = 0 ;
V_135 -> V_87 = V_132 ;
V_99 = F_61 ( & V_262 ) ;
if ( F_62 ( V_99 ) )
return F_63 ( V_99 ) ;
V_251 = F_97 ( V_99 ) ;
if ( V_251 != 0 ) {
V_135 -> V_254 = 1 ;
F_149 () ;
} else
V_251 = V_135 -> V_253 ;
F_64 ( V_99 ) ;
return V_251 ;
}
static void F_150 ( struct V_98 * V_99 , void * V_133 )
{
struct V_165 * V_135 = V_133 ;
struct V_174 * V_175 = V_135 -> V_185 ;
if ( F_151 ( V_135 -> V_169 . V_168 , V_99 ) != 0 )
return;
if ( V_135 -> V_52 != NULL ) {
struct V_222 * V_223 ;
if ( F_99 ( V_135 -> V_52 , V_135 -> V_169 . V_176 , V_135 -> V_169 . V_188 ) )
goto V_267;
F_112 () ;
V_223 = F_113 ( F_70 ( V_135 -> V_52 -> V_53 ) -> V_223 ) ;
if ( V_135 -> V_169 . V_202 != V_244 &&
F_100 ( V_223 , V_135 -> V_169 . V_176 ) )
goto V_268;
F_115 () ;
}
V_135 -> V_169 . V_190 = V_175 -> V_269 -> V_31 -> V_191 ;
if ( V_135 -> V_169 . V_202 == V_252 ) {
V_99 -> V_270 . V_256 = & V_257 [ V_271 ] ;
F_152 ( & V_135 -> V_166 . V_187 , V_135 -> V_169 . V_187 ) ;
}
V_135 -> V_87 = V_132 ;
if ( F_54 ( V_135 -> V_169 . V_47 ,
& V_135 -> V_169 . V_137 ,
& V_135 -> V_166 . V_138 , V_99 ) )
return;
F_57 ( V_99 ) ;
return;
V_268:
F_115 () ;
V_267:
V_99 -> V_272 = NULL ;
}
static void F_153 ( struct V_98 * V_99 , void * V_133 )
{
F_34 ( V_99 , V_101 ) ;
F_150 ( V_99 , V_133 ) ;
}
static void F_154 ( struct V_98 * V_99 , void * V_133 )
{
struct V_165 * V_135 = V_133 ;
V_135 -> V_253 = V_99 -> V_149 ;
if ( ! F_45 ( V_99 , & V_135 -> V_166 . V_138 ) )
return;
if ( V_99 -> V_149 == 0 ) {
switch ( V_135 -> V_166 . V_167 -> V_212 & V_273 ) {
case V_274 :
break;
case V_275 :
V_135 -> V_253 = - V_276 ;
break;
case V_277 :
V_135 -> V_253 = - V_278 ;
break;
default:
V_135 -> V_253 = - V_279 ;
}
F_29 ( V_135 -> V_166 . V_47 , V_135 -> V_87 ) ;
if ( ! ( V_135 -> V_166 . V_280 & V_281 ) )
F_145 ( & V_135 -> V_185 -> V_182 , 0 ) ;
}
V_135 -> V_237 = 1 ;
}
static void F_155 ( void * V_133 )
{
struct V_165 * V_135 = V_133 ;
struct V_51 * V_52 = NULL ;
if ( V_135 -> V_254 == 0 )
goto V_255;
if ( V_135 -> V_253 != 0 || ! V_135 -> V_237 )
goto V_255;
if ( V_135 -> V_166 . V_280 & V_281 )
goto V_255;
V_52 = F_120 ( V_135 ) ;
if ( ! F_62 ( V_52 ) )
F_133 ( V_52 , V_135 -> V_169 . V_176 ) ;
V_255:
F_95 ( V_135 ) ;
}
static int F_156 ( struct V_165 * V_135 , int V_282 )
{
struct V_53 * V_152 = V_135 -> V_152 -> V_27 ;
struct V_46 * V_47 = F_77 ( V_152 ) ;
struct V_283 * V_169 = & V_135 -> V_169 ;
struct V_284 * V_166 = & V_135 -> V_166 ;
struct V_98 * V_99 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_285 ] ,
. V_259 = V_169 ,
. V_260 = V_166 ,
. V_261 = V_135 -> V_185 -> V_236 ,
} ;
struct V_142 V_262 = {
. V_144 = V_47 -> V_80 ,
. V_139 = & V_140 ,
. V_145 = & V_286 ,
. V_147 = V_135 ,
. V_264 = V_265 ,
. V_177 = V_266 ,
} ;
int V_251 ;
F_49 ( & V_169 -> V_137 , & V_166 -> V_138 , 1 ) ;
F_148 ( & V_135 -> V_209 ) ;
V_135 -> V_237 = 0 ;
V_135 -> V_253 = 0 ;
V_135 -> V_254 = 0 ;
if ( V_282 )
V_262 . V_145 = & V_287 ;
V_99 = F_61 ( & V_262 ) ;
if ( F_62 ( V_99 ) )
return F_63 ( V_99 ) ;
V_251 = F_97 ( V_99 ) ;
if ( V_251 != 0 ) {
V_135 -> V_254 = 1 ;
F_149 () ;
} else
V_251 = V_135 -> V_253 ;
F_64 ( V_99 ) ;
return V_251 ;
}
static int F_132 ( struct V_165 * V_135 )
{
struct V_53 * V_152 = V_135 -> V_152 -> V_27 ;
struct V_284 * V_166 = & V_135 -> V_166 ;
int V_251 ;
V_251 = F_156 ( V_135 , 1 ) ;
if ( V_251 != 0 || ! V_135 -> V_237 )
return V_251 ;
F_157 ( F_77 ( V_152 ) , & V_135 -> V_167 ) ;
if ( V_166 -> V_280 & V_281 ) {
V_251 = F_147 ( V_135 ) ;
if ( V_251 != 0 )
return V_251 ;
}
return V_251 ;
}
static int F_158 ( struct V_165 * V_135 )
{
struct V_53 * V_152 = V_135 -> V_152 -> V_27 ;
struct V_46 * V_47 = F_77 ( V_152 ) ;
struct V_283 * V_169 = & V_135 -> V_169 ;
struct V_284 * V_166 = & V_135 -> V_166 ;
int V_251 ;
V_251 = F_156 ( V_135 , 0 ) ;
if ( ! V_135 -> V_237 )
return V_251 ;
if ( V_251 != 0 ) {
if ( V_251 == - V_7 &&
! ( V_169 -> V_188 & V_288 ) )
return - V_247 ;
return V_251 ;
}
F_157 ( V_47 , & V_135 -> V_167 ) ;
if ( V_169 -> V_188 & V_288 )
F_69 ( V_152 , & V_166 -> V_154 ) ;
if ( ( V_166 -> V_280 & V_289 ) == 0 )
V_47 -> V_83 &= ~ V_290 ;
if( V_166 -> V_280 & V_281 ) {
V_251 = F_147 ( V_135 ) ;
if ( V_251 != 0 )
return V_251 ;
}
if ( ! ( V_166 -> V_167 -> V_238 & V_239 ) )
F_159 ( V_47 , & V_166 -> V_187 , V_166 -> V_167 ) ;
return 0 ;
}
static int F_160 ( struct V_31 * V_32 )
{
unsigned int V_291 ;
int V_54 ;
for ( V_291 = V_292 ; V_291 != 0 ; V_291 -- ) {
V_54 = F_10 ( V_32 ) ;
if ( V_54 != 0 )
break;
if ( ! F_36 ( V_293 , & V_32 -> V_34 ) &&
! F_36 ( V_294 , & V_32 -> V_34 ) )
break;
F_161 ( V_32 ) ;
V_54 = - V_14 ;
}
return V_54 ;
}
static int F_162 ( struct V_46 * V_47 )
{
return F_160 ( V_47 -> V_31 ) ;
}
static int F_163 ( struct V_245 * V_246 , struct V_51 * V_52 )
{
struct V_165 * V_234 ;
int V_54 ;
V_234 = F_130 ( V_246 , V_52 ) ;
if ( F_62 ( V_234 ) )
return F_63 ( V_234 ) ;
V_54 = F_134 ( V_234 , V_52 ) ;
if ( V_54 == - V_250 )
F_164 ( V_246 -> V_17 ) ;
F_95 ( V_234 ) ;
return V_54 ;
}
static int F_165 ( struct V_245 * V_246 , struct V_51 * V_52 )
{
struct V_46 * V_47 = F_77 ( V_52 -> V_53 ) ;
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_163 ( V_246 , V_52 ) ;
switch ( V_1 ) {
default:
goto V_116;
case - V_77 :
case - V_78 :
F_16 ( V_47 , V_1 , & V_50 ) ;
V_1 = 0 ;
}
} while ( V_50 . V_55 );
V_116:
return V_1 ;
}
static int F_166 ( struct V_174 * V_175 , struct V_51 * V_52 )
{
struct V_245 * V_246 ;
int V_54 ;
V_246 = F_127 ( V_52 ) ;
if ( F_62 ( V_246 ) )
return F_63 ( V_246 ) ;
V_54 = F_165 ( V_246 , V_52 ) ;
F_140 ( V_246 ) ;
return V_54 ;
}
static void F_167 ( struct V_51 * V_52 )
{
struct V_46 * V_47 = F_77 ( V_52 -> V_53 ) ;
T_6 * V_208 = & V_52 -> V_208 ;
int V_251 ;
if ( F_36 ( V_225 , & V_52 -> V_177 ) == 0 )
return;
V_251 = F_168 ( V_47 , V_208 ) ;
if ( V_251 != V_115 ) {
if ( V_251 != - V_61 )
F_169 ( V_47 , V_208 ) ;
F_135 ( V_225 , & V_52 -> V_177 ) ;
}
}
static int F_170 ( struct V_51 * V_52 )
{
struct V_46 * V_47 = F_77 ( V_52 -> V_53 ) ;
T_6 * V_208 = & V_52 -> V_208 ;
int V_251 ;
if ( ( F_36 ( V_216 , & V_52 -> V_177 ) == 0 ) &&
( F_36 ( V_218 , & V_52 -> V_177 ) == 0 ) &&
( F_36 ( V_220 , & V_52 -> V_177 ) == 0 ) )
return - V_61 ;
V_251 = F_168 ( V_47 , V_208 ) ;
if ( V_251 != V_115 ) {
if ( V_251 != - V_61 )
F_169 ( V_47 , V_208 ) ;
F_135 ( V_216 , & V_52 -> V_177 ) ;
F_135 ( V_218 , & V_52 -> V_177 ) ;
F_135 ( V_220 , & V_52 -> V_177 ) ;
}
return V_251 ;
}
static int F_171 ( struct V_174 * V_175 , struct V_51 * V_52 )
{
int V_251 ;
F_167 ( V_52 ) ;
V_251 = F_170 ( V_52 ) ;
if ( V_251 != V_115 )
V_251 = F_166 ( V_175 , V_52 ) ;
return V_251 ;
}
static inline void F_172 ( struct V_165 * V_234 , struct V_178 * V_295 )
{
if ( ( V_234 -> V_166 . V_296 [ 1 ] & V_297 ) &&
! ( V_295 -> V_204 & V_298 ) )
V_295 -> V_204 |= V_299 ;
if ( ( V_234 -> V_166 . V_296 [ 1 ] & V_300 ) &&
! ( V_295 -> V_204 & V_301 ) )
V_295 -> V_204 |= V_302 ;
}
static int F_173 ( struct V_53 * V_152 ,
struct V_17 * V_17 ,
T_4 V_176 ,
int V_177 ,
struct V_178 * V_295 ,
struct V_261 * V_303 ,
struct V_51 * * V_33 ,
struct V_304 * * V_305 )
{
struct V_174 * V_175 ;
struct V_51 * V_52 = NULL ;
struct V_46 * V_47 = F_77 ( V_152 ) ;
struct V_165 * V_234 ;
int V_251 ;
V_251 = - V_240 ;
V_175 = F_174 ( V_47 , V_303 , V_306 ) ;
if ( V_175 == NULL ) {
F_2 ( L_28 ) ;
goto V_307;
}
V_251 = F_162 ( V_47 ) ;
if ( V_251 != 0 )
goto V_308;
if ( V_17 -> V_27 != NULL )
F_116 ( V_17 -> V_27 , V_176 ) ;
V_251 = - V_240 ;
V_234 = F_75 ( V_17 , V_175 , V_176 , V_177 , V_295 , V_306 ) ;
if ( V_234 == NULL )
goto V_308;
if ( V_305 && V_47 -> V_199 [ 2 ] & V_309 ) {
V_234 -> V_167 . V_310 = F_175 () ;
if ( ! V_234 -> V_167 . V_310 )
goto V_311;
V_234 -> V_169 . V_200 = & V_312 [ 0 ] ;
}
if ( V_17 -> V_27 != NULL )
V_234 -> V_52 = F_122 ( V_17 -> V_27 , V_175 ) ;
V_251 = F_158 ( V_234 ) ;
if ( V_251 != 0 )
goto V_311;
V_52 = F_120 ( V_234 ) ;
V_251 = F_63 ( V_52 ) ;
if ( F_62 ( V_52 ) )
goto V_311;
if ( V_47 -> V_83 & V_290 )
F_106 ( V_313 , & V_52 -> V_177 ) ;
if ( V_234 -> V_169 . V_188 & V_214 ) {
F_172 ( V_234 , V_295 ) ;
F_73 ( V_234 -> V_166 . V_167 ) ;
V_251 = F_176 ( V_52 -> V_53 , V_303 ,
V_234 -> V_166 . V_167 , V_295 ,
V_52 ) ;
if ( V_251 == 0 )
F_177 ( V_52 -> V_53 , V_295 ) ;
F_178 ( V_52 -> V_53 , V_234 -> V_166 . V_167 ) ;
}
if ( F_179 ( V_305 , V_234 -> V_167 . V_310 , V_47 ) )
* V_305 = V_234 -> V_167 . V_310 ;
else
F_86 ( V_234 -> V_167 . V_310 ) ;
V_234 -> V_167 . V_310 = NULL ;
F_95 ( V_234 ) ;
F_92 ( V_175 ) ;
* V_33 = V_52 ;
return 0 ;
V_311:
F_86 ( V_234 -> V_167 . V_310 ) ;
F_95 ( V_234 ) ;
V_308:
F_92 ( V_175 ) ;
V_307:
* V_33 = NULL ;
return V_251 ;
}
static struct V_51 * F_180 ( struct V_53 * V_152 ,
struct V_17 * V_17 ,
T_4 V_176 ,
int V_177 ,
struct V_178 * V_295 ,
struct V_261 * V_303 ,
struct V_304 * * V_305 )
{
struct V_49 V_50 = { } ;
struct V_51 * V_33 ;
int V_251 ;
V_176 &= V_57 | V_189 ;
do {
V_251 = F_173 ( V_152 , V_17 , V_176 , V_177 , V_295 , V_303 ,
& V_33 , V_305 ) ;
if ( V_251 == 0 )
break;
if ( V_251 == - V_314 ) {
F_181 ( L_5
L_29 ,
F_77 ( V_152 ) -> V_31 -> V_86 ) ;
V_50 . V_55 = 1 ;
continue;
}
if ( V_251 == - V_61 ) {
V_50 . V_55 = 1 ;
continue;
}
if ( V_251 == - V_129 ) {
V_50 . V_55 = 1 ;
continue;
}
V_33 = F_119 ( F_16 ( F_77 ( V_152 ) ,
V_251 , & V_50 ) ) ;
} while ( V_50 . V_55 );
return V_33 ;
}
static int F_182 ( struct V_53 * V_53 , struct V_261 * V_303 ,
struct V_315 * V_316 , struct V_178 * V_295 ,
struct V_51 * V_52 )
{
struct V_46 * V_47 = F_77 ( V_53 ) ;
struct V_317 V_318 = {
. V_187 = F_83 ( V_53 ) ,
. V_319 = V_295 ,
. V_47 = V_47 ,
. V_198 = V_47 -> V_199 ,
} ;
struct V_320 V_33 = {
. V_316 = V_316 ,
. V_47 = V_47 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_321 ] ,
. V_259 = & V_318 ,
. V_260 = & V_33 ,
. V_261 = V_303 ,
} ;
unsigned long V_87 = V_132 ;
int V_251 ;
F_73 ( V_316 ) ;
if ( V_52 != NULL ) {
F_183 ( & V_318 . V_208 , V_52 , V_189 ,
V_44 -> V_322 , V_44 -> V_323 ) ;
} else if ( F_184 ( & V_318 . V_208 , V_53 ,
V_189 ) ) {
} else
F_105 ( & V_318 . V_208 , & V_324 ) ;
V_251 = F_68 ( V_47 -> V_80 , V_47 , & V_140 , & V_318 . V_137 , & V_33 . V_138 , 1 ) ;
if ( V_251 == 0 && V_52 != NULL )
F_29 ( V_47 , V_87 ) ;
return V_251 ;
}
static int F_176 ( struct V_53 * V_53 , struct V_261 * V_303 ,
struct V_315 * V_316 , struct V_178 * V_295 ,
struct V_51 * V_52 )
{
struct V_46 * V_47 = F_77 ( V_53 ) ;
struct V_49 V_50 = {
. V_52 = V_52 ,
. V_53 = V_53 ,
} ;
int V_1 ;
do {
V_1 = F_182 ( V_53 , V_303 , V_316 , V_295 , V_52 ) ;
switch ( V_1 ) {
case - V_56 :
if ( V_52 && ! ( V_52 -> V_52 & V_189 ) ) {
V_1 = - V_325 ;
if ( V_295 -> V_204 & V_326 )
V_1 = - V_10 ;
goto V_116;
}
}
V_1 = F_16 ( V_47 , V_1 , & V_50 ) ;
} while ( V_50 . V_55 );
V_116:
return V_1 ;
}
static void F_185 ( void * V_135 )
{
struct V_327 * V_133 = V_135 ;
struct V_174 * V_175 = V_133 -> V_52 -> V_185 ;
struct V_210 * V_211 = V_133 -> V_52 -> V_53 -> V_328 ;
if ( V_133 -> V_329 )
F_186 ( V_133 -> V_52 -> V_53 ) ;
F_91 ( V_133 -> V_52 ) ;
F_90 ( V_133 -> V_318 . V_168 ) ;
F_92 ( V_175 ) ;
F_93 ( V_211 ) ;
F_86 ( V_133 ) ;
}
static void F_187 ( struct V_51 * V_52 ,
T_4 V_176 )
{
F_26 ( & V_52 -> V_185 -> V_229 ) ;
if ( ! ( V_176 & V_57 ) )
F_135 ( V_216 , & V_52 -> V_177 ) ;
if ( ! ( V_176 & V_189 ) )
F_135 ( V_218 , & V_52 -> V_177 ) ;
F_135 ( V_220 , & V_52 -> V_177 ) ;
F_28 ( & V_52 -> V_185 -> V_229 ) ;
}
static void F_188 ( struct V_98 * V_99 , void * V_135 )
{
struct V_327 * V_133 = V_135 ;
struct V_51 * V_52 = V_133 -> V_52 ;
struct V_46 * V_47 = F_77 ( V_133 -> V_53 ) ;
F_2 ( L_30 , V_13 ) ;
if ( ! F_45 ( V_99 , & V_133 -> V_33 . V_138 ) )
return;
switch ( V_99 -> V_149 ) {
case 0 :
if ( V_133 -> V_329 )
F_189 ( V_52 -> V_53 ,
V_133 -> V_330 ) ;
F_107 ( V_52 , & V_133 -> V_33 . V_208 , 0 ) ;
F_29 ( V_47 , V_133 -> V_87 ) ;
F_187 ( V_52 ,
V_133 -> V_318 . V_176 ) ;
break;
case - V_63 :
case - V_82 :
case - V_61 :
case - V_62 :
if ( V_133 -> V_318 . V_176 == 0 )
break;
default:
if ( F_190 ( V_99 , V_47 , V_52 ) == - V_129 )
F_191 ( V_99 ) ;
}
F_192 ( V_133 -> V_318 . V_168 ) ;
F_193 ( V_133 -> V_53 , V_133 -> V_33 . V_316 ) ;
F_2 ( L_31 , V_13 , V_99 -> V_149 ) ;
}
static void F_194 ( struct V_98 * V_99 , void * V_135 )
{
struct V_327 * V_133 = V_135 ;
struct V_51 * V_52 = V_133 -> V_52 ;
int V_331 = 0 ;
F_2 ( L_30 , V_13 ) ;
if ( F_151 ( V_133 -> V_318 . V_168 , V_99 ) != 0 )
return;
V_99 -> V_270 . V_256 = & V_257 [ V_332 ] ;
V_133 -> V_318 . V_176 = V_57 | V_189 ;
F_26 ( & V_52 -> V_185 -> V_229 ) ;
if ( V_52 -> V_221 == 0 ) {
if ( V_52 -> V_217 == 0 ) {
V_331 |= F_36 ( V_216 , & V_52 -> V_177 ) ;
V_331 |= F_36 ( V_220 , & V_52 -> V_177 ) ;
V_133 -> V_318 . V_176 &= ~ V_57 ;
}
if ( V_52 -> V_219 == 0 ) {
V_331 |= F_36 ( V_218 , & V_52 -> V_177 ) ;
V_331 |= F_36 ( V_220 , & V_52 -> V_177 ) ;
V_133 -> V_318 . V_176 &= ~ V_189 ;
}
}
F_28 ( & V_52 -> V_185 -> V_229 ) ;
if ( ! V_331 ) {
V_99 -> V_272 = NULL ;
goto V_116;
}
if ( V_133 -> V_318 . V_176 == 0 ) {
V_99 -> V_270 . V_256 = & V_257 [ V_333 ] ;
if ( V_133 -> V_329 &&
F_195 ( V_133 -> V_53 , & V_133 -> V_330 ) ) {
F_52 ( & F_77 ( V_133 -> V_53 ) -> V_334 ,
V_99 , NULL ) ;
goto V_116;
}
}
F_73 ( V_133 -> V_33 . V_316 ) ;
V_133 -> V_87 = V_132 ;
if ( F_54 ( F_77 ( V_133 -> V_53 ) ,
& V_133 -> V_318 . V_137 ,
& V_133 -> V_33 . V_138 ,
V_99 ) )
goto V_116;
F_57 ( V_99 ) ;
V_116:
F_2 ( L_32 , V_13 ) ;
}
int F_196 ( struct V_51 * V_52 , T_5 V_180 , int V_335 , bool V_329 )
{
struct V_46 * V_47 = F_77 ( V_52 -> V_53 ) ;
struct V_327 * V_133 ;
struct V_174 * V_175 = V_52 -> V_185 ;
struct V_98 * V_99 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_333 ] ,
. V_261 = V_52 -> V_185 -> V_236 ,
} ;
struct V_142 V_262 = {
. V_144 = V_47 -> V_80 ,
. V_139 = & V_140 ,
. V_145 = & V_336 ,
. V_264 = V_265 ,
. V_177 = V_266 ,
} ;
int V_251 = - V_240 ;
V_133 = F_78 ( sizeof( * V_133 ) , V_180 ) ;
if ( V_133 == NULL )
goto V_116;
F_49 ( & V_133 -> V_318 . V_137 , & V_133 -> V_33 . V_138 , 1 ) ;
V_133 -> V_53 = V_52 -> V_53 ;
V_133 -> V_52 = V_52 ;
V_133 -> V_318 . V_187 = F_83 ( V_52 -> V_53 ) ;
V_133 -> V_318 . V_208 = & V_52 -> V_226 ;
V_133 -> V_318 . V_168 = F_79 ( & V_52 -> V_185 -> V_182 , V_180 ) ;
if ( V_133 -> V_318 . V_168 == NULL )
goto V_337;
V_133 -> V_318 . V_176 = 0 ;
V_133 -> V_318 . V_198 = V_47 -> V_338 ;
V_133 -> V_33 . V_316 = & V_133 -> V_316 ;
V_133 -> V_33 . V_168 = V_133 -> V_318 . V_168 ;
V_133 -> V_33 . V_47 = V_47 ;
V_133 -> V_329 = V_329 ;
F_80 ( V_133 -> V_53 -> V_328 ) ;
V_140 . V_259 = & V_133 -> V_318 ;
V_140 . V_260 = & V_133 -> V_33 ;
V_262 . V_147 = V_133 ;
V_99 = F_61 ( & V_262 ) ;
if ( F_62 ( V_99 ) )
return F_63 ( V_99 ) ;
V_251 = 0 ;
if ( V_335 )
V_251 = F_98 ( V_99 ) ;
F_64 ( V_99 ) ;
return V_251 ;
V_337:
F_86 ( V_133 ) ;
V_116:
if ( V_329 )
F_186 ( V_52 -> V_53 ) ;
F_91 ( V_52 ) ;
F_92 ( V_175 ) ;
return V_251 ;
}
static struct V_53 *
F_197 ( struct V_53 * V_152 , struct V_245 * V_246 , int V_188 , struct V_178 * V_339 )
{
struct V_51 * V_52 ;
V_52 = F_180 ( V_152 , V_246 -> V_17 , V_246 -> V_212 , V_188 , V_339 ,
V_246 -> V_303 , & V_246 -> V_310 ) ;
if ( F_62 ( V_52 ) )
return F_198 ( V_52 ) ;
V_246 -> V_52 = V_52 ;
return F_199 ( V_52 -> V_53 ) ;
}
static void F_200 ( struct V_245 * V_246 , int V_340 )
{
if ( V_246 -> V_52 == NULL )
return;
if ( V_340 )
F_201 ( V_246 -> V_52 , V_246 -> V_212 ) ;
else
F_133 ( V_246 -> V_52 , V_246 -> V_212 ) ;
}
static int F_202 ( struct V_46 * V_47 , struct V_341 * V_342 )
{
struct V_343 args = {
. V_342 = V_342 ,
} ;
struct V_344 V_33 = {} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_345 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
int V_251 ;
V_251 = F_68 ( V_47 -> V_80 , V_47 , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
if ( V_251 == 0 ) {
memcpy ( V_47 -> V_199 , V_33 . V_199 , sizeof( V_47 -> V_199 ) ) ;
V_47 -> V_83 &= ~ ( V_346 | V_347 |
V_348 | V_349 |
V_350 | V_351 | V_352 |
V_353 | V_354 |
V_355 | V_356 ) ;
if ( V_33 . V_199 [ 0 ] & V_357 )
V_47 -> V_83 |= V_346 ;
if ( V_33 . V_358 != 0 )
V_47 -> V_83 |= V_347 ;
if ( V_33 . V_359 != 0 )
V_47 -> V_83 |= V_348 ;
if ( V_33 . V_199 [ 0 ] & V_26 )
V_47 -> V_83 |= V_349 ;
if ( V_33 . V_199 [ 1 ] & V_360 )
V_47 -> V_83 |= V_350 ;
if ( V_33 . V_199 [ 1 ] & V_361 )
V_47 -> V_83 |= V_351 ;
if ( V_33 . V_199 [ 1 ] & V_362 )
V_47 -> V_83 |= V_352 ;
if ( V_33 . V_199 [ 1 ] & V_363 )
V_47 -> V_83 |= V_353 ;
if ( V_33 . V_199 [ 1 ] & V_297 )
V_47 -> V_83 |= V_354 ;
if ( V_33 . V_199 [ 1 ] & V_364 )
V_47 -> V_83 |= V_355 ;
if ( V_33 . V_199 [ 1 ] & V_300 )
V_47 -> V_83 |= V_356 ;
memcpy ( V_47 -> V_338 , V_33 . V_199 , sizeof( V_47 -> V_338 ) ) ;
V_47 -> V_338 [ 0 ] &= V_365 | V_366 ;
V_47 -> V_338 [ 1 ] &= V_364 | V_300 ;
V_47 -> V_367 = V_33 . V_367 ;
V_47 -> V_368 = V_33 . V_368 ;
}
return V_251 ;
}
int F_203 ( struct V_46 * V_47 , struct V_341 * V_342 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_47 ,
F_202 ( V_47 , V_342 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_204 ( struct V_46 * V_47 , struct V_341 * V_342 ,
struct V_369 * V_370 )
{
struct V_371 args = {
. V_198 = V_201 ,
} ;
struct V_372 V_33 = {
. V_47 = V_47 ,
. V_316 = V_370 -> V_316 ,
. V_187 = V_342 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_373 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
F_73 ( V_370 -> V_316 ) ;
return F_68 ( V_47 -> V_80 , V_47 , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
}
static int F_205 ( struct V_46 * V_47 , struct V_341 * V_342 ,
struct V_369 * V_370 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_204 ( V_47 , V_342 , V_370 ) ;
switch ( V_1 ) {
case 0 :
case - V_4 :
goto V_116;
default:
V_1 = F_16 ( V_47 , V_1 , & V_50 ) ;
}
} while ( V_50 . V_55 );
V_116:
return V_1 ;
}
static int F_206 ( struct V_46 * V_47 , struct V_341 * V_342 ,
struct V_369 * V_370 , T_7 V_374 )
{
struct V_375 * V_376 ;
int V_54 ;
V_376 = F_207 ( V_374 , V_47 -> V_80 ) ;
if ( ! V_376 ) {
V_54 = - V_14 ;
goto V_116;
}
V_54 = F_205 ( V_47 , V_342 , V_370 ) ;
V_116:
return V_54 ;
}
static int F_208 ( struct V_46 * V_47 , struct V_341 * V_342 ,
struct V_369 * V_370 )
{
int V_377 , V_378 , V_251 = 0 ;
T_7 V_379 [ V_380 ] ;
V_378 = F_209 ( V_379 , F_210 ( V_379 ) ) ;
F_4 ( V_378 < 0 ) ;
for ( V_377 = 0 ; V_377 < V_378 ; V_377 ++ ) {
if ( V_379 [ V_377 ] == V_381 )
continue;
V_251 = F_206 ( V_47 , V_342 , V_370 , V_379 [ V_377 ] ) ;
if ( V_251 == - V_4 || V_251 == - V_10 )
continue;
break;
}
if ( V_251 == - V_10 )
V_251 = - V_5 ;
return V_251 ;
}
int F_211 ( struct V_46 * V_47 , struct V_341 * V_342 ,
struct V_369 * V_370 )
{
int V_382 = V_47 -> V_31 -> V_383 ;
int V_251 = F_205 ( V_47 , V_342 , V_370 ) ;
if ( ( V_251 == - V_4 ) && ! ( V_47 -> V_177 & V_384 ) )
V_251 = V_385 [ V_382 ] -> F_212 ( V_47 , V_342 , V_370 ) ;
if ( V_251 == 0 )
V_251 = F_203 ( V_47 , V_342 ) ;
if ( V_251 == 0 )
V_251 = F_213 ( V_47 , V_342 , V_370 ) ;
return F_1 ( V_251 ) ;
}
static int F_214 ( struct V_46 * V_47 , struct V_341 * V_386 ,
struct V_369 * V_370 )
{
int error ;
struct V_315 * V_316 = V_370 -> V_316 ;
error = F_203 ( V_47 , V_386 ) ;
if ( error < 0 ) {
F_2 ( L_33 , - error ) ;
return error ;
}
error = F_215 ( V_47 , V_386 , V_316 ) ;
if ( error < 0 ) {
F_2 ( L_34 , - error ) ;
return error ;
}
if ( V_316 -> V_238 & V_387 &&
! F_216 ( & V_47 -> V_388 , & V_316 -> V_388 ) )
memcpy ( & V_47 -> V_388 , & V_316 -> V_388 , sizeof( V_47 -> V_388 ) ) ;
return error ;
}
static int F_217 ( struct V_39 * V_80 , struct V_53 * V_152 ,
const struct V_389 * V_196 , struct V_315 * V_316 ,
struct V_341 * V_342 )
{
int V_251 = - V_240 ;
struct V_390 * V_390 = NULL ;
struct V_391 * V_392 = NULL ;
V_390 = F_218 ( V_306 ) ;
if ( V_390 == NULL )
goto V_116;
V_392 = F_219 ( sizeof( struct V_391 ) , V_306 ) ;
if ( V_392 == NULL )
goto V_116;
V_251 = F_220 ( V_80 , V_152 , V_196 , V_392 , V_390 ) ;
if ( V_251 != 0 )
goto V_116;
if ( F_216 ( & F_77 ( V_152 ) -> V_388 , & V_392 -> V_316 . V_388 ) ) {
F_2 ( L_35
L_36 , V_13 , V_196 -> V_196 ) ;
V_251 = - V_14 ;
goto V_116;
}
F_221 ( & V_392 -> V_316 ) ;
memcpy ( V_316 , & V_392 -> V_316 , sizeof( struct V_315 ) ) ;
memset ( V_342 , 0 , sizeof( struct V_341 ) ) ;
V_116:
if ( V_390 )
F_222 ( V_390 ) ;
F_86 ( V_392 ) ;
return V_251 ;
}
static int F_159 ( struct V_46 * V_47 , struct V_341 * V_342 , struct V_315 * V_316 )
{
struct V_393 args = {
. V_187 = V_342 ,
. V_198 = V_47 -> V_199 ,
} ;
struct V_394 V_33 = {
. V_316 = V_316 ,
. V_47 = V_47 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_395 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
F_73 ( V_316 ) ;
return F_68 ( V_47 -> V_80 , V_47 , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
}
static int F_215 ( struct V_46 * V_47 , struct V_341 * V_342 , struct V_315 * V_316 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_47 ,
F_159 ( V_47 , V_342 , V_316 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int
F_223 ( struct V_17 * V_17 , struct V_315 * V_316 ,
struct V_178 * V_295 )
{
struct V_53 * V_53 = V_17 -> V_27 ;
struct V_261 * V_303 = NULL ;
struct V_51 * V_52 = NULL ;
int V_251 ;
if ( F_224 ( V_53 ) )
F_225 ( V_53 ) ;
F_73 ( V_316 ) ;
if ( V_295 -> V_204 & V_326 )
V_295 -> V_204 &= ~ ( V_302 | V_396 | V_326 ) ;
if ( ( V_295 -> V_204 & ~ ( V_397 ) ) == 0 )
return 0 ;
if ( V_295 -> V_204 & V_397 ) {
struct V_245 * V_246 ;
V_246 = F_226 ( V_295 -> V_398 ) ;
if ( V_246 ) {
V_303 = V_246 -> V_303 ;
V_52 = V_246 -> V_52 ;
}
}
V_251 = F_176 ( V_53 , V_303 , V_316 , V_295 , V_52 ) ;
if ( V_251 == 0 )
F_177 ( V_53 , V_295 ) ;
return V_251 ;
}
static int F_227 ( struct V_39 * V_40 , struct V_53 * V_152 ,
const struct V_389 * V_196 , struct V_341 * V_342 ,
struct V_315 * V_316 )
{
struct V_46 * V_47 = F_77 ( V_152 ) ;
int V_251 ;
struct V_399 args = {
. V_198 = V_47 -> V_199 ,
. V_400 = F_83 ( V_152 ) ,
. V_196 = V_196 ,
} ;
struct V_372 V_33 = {
. V_47 = V_47 ,
. V_316 = V_316 ,
. V_187 = V_342 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_401 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
F_73 ( V_316 ) ;
F_2 ( L_37 , V_196 -> V_196 ) ;
V_251 = F_68 ( V_40 , V_47 , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
F_2 ( L_38 , V_251 ) ;
return V_251 ;
}
static void F_228 ( struct V_315 * V_316 )
{
V_316 -> V_238 |= V_402 | V_403 |
V_404 | V_405 ;
V_316 -> V_212 = V_277 | V_406 | V_407 ;
V_316 -> V_408 = 2 ;
}
static int F_229 ( struct V_39 * * V_40 , struct V_53 * V_152 ,
struct V_389 * V_196 , struct V_341 * V_342 ,
struct V_315 * V_316 )
{
struct V_49 V_50 = { } ;
struct V_39 * V_80 = * V_40 ;
int V_1 ;
do {
V_1 = F_227 ( V_80 , V_152 , V_196 , V_342 , V_316 ) ;
switch ( V_1 ) {
case - V_7 :
V_1 = - V_247 ;
goto V_116;
case - V_409 :
V_1 = F_217 ( V_80 , V_152 , V_196 , V_316 , V_342 ) ;
goto V_116;
case - V_4 :
V_1 = - V_5 ;
if ( V_80 != * V_40 )
goto V_116;
V_80 = F_230 ( V_80 , V_152 , V_196 ) ;
if ( F_62 ( V_80 ) )
return F_63 ( V_80 ) ;
V_50 . V_55 = 1 ;
break;
default:
V_1 = F_16 ( F_77 ( V_152 ) , V_1 , & V_50 ) ;
}
} while ( V_50 . V_55 );
V_116:
if ( V_1 == 0 )
* V_40 = V_80 ;
else if ( V_80 != * V_40 )
F_231 ( V_80 ) ;
return V_1 ;
}
static int F_232 ( struct V_53 * V_152 , struct V_389 * V_196 ,
struct V_341 * V_342 , struct V_315 * V_316 )
{
int V_251 ;
struct V_39 * V_80 = F_233 ( V_152 ) ;
V_251 = F_229 ( & V_80 , V_152 , V_196 , V_342 , V_316 ) ;
if ( V_80 != F_233 ( V_152 ) ) {
F_231 ( V_80 ) ;
F_228 ( V_316 ) ;
}
return V_251 ;
}
struct V_39 *
F_234 ( struct V_53 * V_152 , struct V_389 * V_196 ,
struct V_341 * V_342 , struct V_315 * V_316 )
{
int V_251 ;
struct V_39 * V_80 = F_235 ( F_233 ( V_152 ) ) ;
V_251 = F_229 ( & V_80 , V_152 , V_196 , V_342 , V_316 ) ;
if ( V_251 < 0 ) {
F_231 ( V_80 ) ;
return F_119 ( V_251 ) ;
}
return V_80 ;
}
static int F_236 ( struct V_53 * V_53 , struct V_410 * V_411 )
{
struct V_46 * V_47 = F_77 ( V_53 ) ;
struct V_412 args = {
. V_187 = F_83 ( V_53 ) ,
. V_198 = V_47 -> V_338 ,
} ;
struct V_413 V_33 = {
. V_47 = V_47 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_414 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
. V_261 = V_411 -> V_303 ,
} ;
int V_212 = V_411 -> V_415 ;
int V_251 ;
if ( V_212 & V_416 )
args . V_417 |= V_418 ;
if ( F_237 ( V_53 -> V_419 ) ) {
if ( V_212 & V_420 )
args . V_417 |= V_421 | V_422 | V_423 ;
if ( V_212 & V_424 )
args . V_417 |= V_425 ;
} else {
if ( V_212 & V_420 )
args . V_417 |= V_421 | V_422 ;
if ( V_212 & V_424 )
args . V_417 |= V_426 ;
}
V_33 . V_316 = F_238 () ;
if ( V_33 . V_316 == NULL )
return - V_240 ;
V_251 = F_68 ( V_47 -> V_80 , V_47 , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
if ( ! V_251 ) {
V_411 -> V_415 = 0 ;
if ( V_33 . V_417 & V_418 )
V_411 -> V_415 |= V_416 ;
if ( V_33 . V_417 & ( V_421 | V_422 | V_423 ) )
V_411 -> V_415 |= V_420 ;
if ( V_33 . V_417 & ( V_425 | V_426 ) )
V_411 -> V_415 |= V_424 ;
F_193 ( V_53 , V_33 . V_316 ) ;
}
F_239 ( V_33 . V_316 ) ;
return V_251 ;
}
static int F_240 ( struct V_53 * V_53 , struct V_410 * V_411 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_53 ) ,
F_236 ( V_53 , V_411 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_241 ( struct V_53 * V_53 , struct V_390 * V_390 ,
unsigned int V_30 , unsigned int V_427 )
{
struct V_428 args = {
. V_187 = F_83 ( V_53 ) ,
. V_30 = V_30 ,
. V_427 = V_427 ,
. V_23 = & V_390 ,
} ;
struct V_429 V_33 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_430 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
return F_68 ( F_77 ( V_53 ) -> V_80 , F_77 ( V_53 ) , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
}
static int F_242 ( struct V_53 * V_53 , struct V_390 * V_390 ,
unsigned int V_30 , unsigned int V_427 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_53 ) ,
F_241 ( V_53 , V_390 , V_30 , V_427 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int
F_243 ( struct V_53 * V_152 , struct V_17 * V_17 , struct V_178 * V_295 ,
int V_177 )
{
struct V_245 * V_246 ;
struct V_51 * V_52 ;
int V_251 = 0 ;
V_246 = F_244 ( V_17 , V_57 ) ;
if ( F_62 ( V_246 ) )
return F_63 ( V_246 ) ;
V_295 -> V_431 &= ~ F_245 () ;
V_52 = F_180 ( V_152 , V_17 , V_246 -> V_212 ,
V_177 , V_295 , V_246 -> V_303 ,
& V_246 -> V_310 ) ;
F_164 ( V_17 ) ;
if ( F_62 ( V_52 ) ) {
V_251 = F_63 ( V_52 ) ;
goto V_116;
}
F_246 ( V_17 , F_199 ( V_52 -> V_53 ) ) ;
F_247 ( V_17 , F_248 ( V_152 ) ) ;
V_246 -> V_52 = V_52 ;
V_116:
F_140 ( V_246 ) ;
return V_251 ;
}
static int F_249 ( struct V_53 * V_152 , struct V_389 * V_196 )
{
struct V_46 * V_47 = F_77 ( V_152 ) ;
struct V_432 args = {
. V_187 = F_83 ( V_152 ) ,
. V_196 = * V_196 ,
} ;
struct V_433 V_33 = {
. V_47 = V_47 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_434 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
int V_251 ;
V_251 = F_68 ( V_47 -> V_80 , V_47 , & V_140 , & args . V_137 , & V_33 . V_138 , 1 ) ;
if ( V_251 == 0 )
F_69 ( V_152 , & V_33 . V_154 ) ;
return V_251 ;
}
static int F_250 ( struct V_53 * V_152 , struct V_389 * V_196 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_152 ) ,
F_249 ( V_152 , V_196 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static void F_251 ( struct V_139 * V_140 , struct V_53 * V_152 )
{
struct V_46 * V_47 = F_77 ( V_152 ) ;
struct V_432 * args = V_140 -> V_259 ;
struct V_433 * V_33 = V_140 -> V_260 ;
V_33 -> V_47 = V_47 ;
V_140 -> V_256 = & V_257 [ V_434 ] ;
F_49 ( & args -> V_137 , & V_33 -> V_138 , 1 ) ;
}
static void F_252 ( struct V_98 * V_99 , struct V_435 * V_135 )
{
if ( F_54 ( F_77 ( V_135 -> V_152 ) ,
& V_135 -> args . V_137 ,
& V_135 -> V_33 . V_138 ,
V_99 ) )
return;
F_57 ( V_99 ) ;
}
static int F_253 ( struct V_98 * V_99 , struct V_53 * V_152 )
{
struct V_433 * V_33 = V_99 -> V_270 . V_260 ;
if ( ! F_45 ( V_99 , & V_33 -> V_138 ) )
return 0 ;
if ( F_190 ( V_99 , V_33 -> V_47 , NULL ) == - V_129 )
return 0 ;
F_69 ( V_152 , & V_33 -> V_154 ) ;
return 1 ;
}
static void F_254 ( struct V_139 * V_140 , struct V_53 * V_152 )
{
struct V_46 * V_47 = F_77 ( V_152 ) ;
struct V_436 * V_318 = V_140 -> V_259 ;
struct V_437 * V_33 = V_140 -> V_260 ;
V_140 -> V_256 = & V_257 [ V_438 ] ;
V_33 -> V_47 = V_47 ;
F_49 ( & V_318 -> V_137 , & V_33 -> V_138 , 1 ) ;
}
static void F_255 ( struct V_98 * V_99 , struct V_439 * V_135 )
{
if ( F_54 ( F_77 ( V_135 -> V_440 ) ,
& V_135 -> args . V_137 ,
& V_135 -> V_33 . V_138 ,
V_99 ) )
return;
F_57 ( V_99 ) ;
}
static int F_256 ( struct V_98 * V_99 , struct V_53 * V_440 ,
struct V_53 * V_441 )
{
struct V_437 * V_33 = V_99 -> V_270 . V_260 ;
if ( ! F_45 ( V_99 , & V_33 -> V_138 ) )
return 0 ;
if ( F_190 ( V_99 , V_33 -> V_47 , NULL ) == - V_129 )
return 0 ;
F_69 ( V_440 , & V_33 -> V_442 ) ;
F_69 ( V_441 , & V_33 -> V_443 ) ;
return 1 ;
}
static int F_257 ( struct V_53 * V_440 , struct V_389 * V_444 ,
struct V_53 * V_441 , struct V_389 * V_445 )
{
struct V_46 * V_47 = F_77 ( V_440 ) ;
struct V_436 V_318 = {
. V_440 = F_83 ( V_440 ) ,
. V_441 = F_83 ( V_441 ) ,
. V_444 = V_444 ,
. V_445 = V_445 ,
} ;
struct V_437 V_33 = {
. V_47 = V_47 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_438 ] ,
. V_259 = & V_318 ,
. V_260 = & V_33 ,
} ;
int V_251 = - V_240 ;
V_251 = F_68 ( V_47 -> V_80 , V_47 , & V_140 , & V_318 . V_137 , & V_33 . V_138 , 1 ) ;
if ( ! V_251 ) {
F_69 ( V_440 , & V_33 . V_442 ) ;
F_69 ( V_441 , & V_33 . V_443 ) ;
}
return V_251 ;
}
static int F_258 ( struct V_53 * V_440 , struct V_389 * V_444 ,
struct V_53 * V_441 , struct V_389 * V_445 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_440 ) ,
F_257 ( V_440 , V_444 ,
V_441 , V_445 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_259 ( struct V_53 * V_53 , struct V_53 * V_152 , struct V_389 * V_196 )
{
struct V_46 * V_47 = F_77 ( V_53 ) ;
struct V_446 V_318 = {
. V_187 = F_83 ( V_53 ) ,
. V_400 = F_83 ( V_152 ) ,
. V_196 = V_196 ,
. V_198 = V_47 -> V_199 ,
} ;
struct V_447 V_33 = {
. V_47 = V_47 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_448 ] ,
. V_259 = & V_318 ,
. V_260 = & V_33 ,
} ;
int V_251 = - V_240 ;
V_33 . V_316 = F_238 () ;
if ( V_33 . V_316 == NULL )
goto V_116;
V_251 = F_68 ( V_47 -> V_80 , V_47 , & V_140 , & V_318 . V_137 , & V_33 . V_138 , 1 ) ;
if ( ! V_251 ) {
F_69 ( V_152 , & V_33 . V_154 ) ;
F_178 ( V_53 , V_33 . V_316 ) ;
}
V_116:
F_239 ( V_33 . V_316 ) ;
return V_251 ;
}
static int F_260 ( struct V_53 * V_53 , struct V_53 * V_152 , struct V_389 * V_196 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_53 ) ,
F_259 ( V_53 , V_152 , V_196 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static struct V_449 * F_261 ( struct V_53 * V_152 ,
struct V_389 * V_196 , struct V_178 * V_295 , T_3 V_450 )
{
struct V_449 * V_135 ;
V_135 = F_78 ( sizeof( * V_135 ) , V_306 ) ;
if ( V_135 != NULL ) {
struct V_46 * V_47 = F_77 ( V_152 ) ;
V_135 -> V_140 . V_256 = & V_257 [ V_451 ] ;
V_135 -> V_140 . V_259 = & V_135 -> V_318 ;
V_135 -> V_140 . V_260 = & V_135 -> V_33 ;
V_135 -> V_318 . V_400 = F_83 ( V_152 ) ;
V_135 -> V_318 . V_47 = V_47 ;
V_135 -> V_318 . V_196 = V_196 ;
V_135 -> V_318 . V_179 = V_295 ;
V_135 -> V_318 . V_450 = V_450 ;
V_135 -> V_318 . V_198 = V_47 -> V_199 ;
V_135 -> V_33 . V_47 = V_47 ;
V_135 -> V_33 . V_187 = & V_135 -> V_187 ;
V_135 -> V_33 . V_316 = & V_135 -> V_316 ;
F_73 ( V_135 -> V_33 . V_316 ) ;
}
return V_135 ;
}
static int F_262 ( struct V_53 * V_152 , struct V_17 * V_17 , struct V_449 * V_135 )
{
int V_251 = F_68 ( F_77 ( V_152 ) -> V_80 , F_77 ( V_152 ) , & V_135 -> V_140 ,
& V_135 -> V_318 . V_137 , & V_135 -> V_33 . V_138 , 1 ) ;
if ( V_251 == 0 ) {
F_69 ( V_152 , & V_135 -> V_33 . V_452 ) ;
V_251 = F_263 ( V_17 , V_135 -> V_33 . V_187 , V_135 -> V_33 . V_316 ) ;
}
return V_251 ;
}
static void F_264 ( struct V_449 * V_135 )
{
F_86 ( V_135 ) ;
}
static int F_265 ( struct V_53 * V_152 , struct V_17 * V_17 ,
struct V_390 * V_390 , unsigned int V_378 , struct V_178 * V_295 )
{
struct V_449 * V_135 ;
int V_251 = - V_453 ;
if ( V_378 > V_454 )
goto V_116;
V_251 = - V_240 ;
V_135 = F_261 ( V_152 , & V_17 -> V_197 , V_295 , V_455 ) ;
if ( V_135 == NULL )
goto V_116;
V_135 -> V_140 . V_256 = & V_257 [ V_456 ] ;
V_135 -> V_318 . V_206 . V_457 . V_23 = & V_390 ;
V_135 -> V_318 . V_206 . V_457 . V_378 = V_378 ;
V_251 = F_262 ( V_152 , V_17 , V_135 ) ;
F_264 ( V_135 ) ;
V_116:
return V_251 ;
}
static int F_266 ( struct V_53 * V_152 , struct V_17 * V_17 ,
struct V_390 * V_390 , unsigned int V_378 , struct V_178 * V_295 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_152 ) ,
F_265 ( V_152 , V_17 , V_390 ,
V_378 , V_295 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_267 ( struct V_53 * V_152 , struct V_17 * V_17 ,
struct V_178 * V_295 )
{
struct V_449 * V_135 ;
int V_251 = - V_240 ;
V_135 = F_261 ( V_152 , & V_17 -> V_197 , V_295 , V_458 ) ;
if ( V_135 == NULL )
goto V_116;
V_251 = F_262 ( V_152 , V_17 , V_135 ) ;
F_264 ( V_135 ) ;
V_116:
return V_251 ;
}
static int F_268 ( struct V_53 * V_152 , struct V_17 * V_17 ,
struct V_178 * V_295 )
{
struct V_49 V_50 = { } ;
int V_1 ;
V_295 -> V_431 &= ~ F_245 () ;
do {
V_1 = F_16 ( F_77 ( V_152 ) ,
F_267 ( V_152 , V_17 , V_295 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_269 ( struct V_17 * V_17 , struct V_261 * V_303 ,
T_1 V_15 , struct V_390 * * V_23 , unsigned int V_22 , int V_459 )
{
struct V_53 * V_152 = V_17 -> V_27 ;
struct V_18 args = {
. V_187 = F_83 ( V_152 ) ,
. V_23 = V_23 ,
. V_30 = 0 ,
. V_22 = V_22 ,
. V_198 = F_77 ( V_17 -> V_27 ) -> V_199 ,
. V_459 = V_459 ,
} ;
struct V_460 V_33 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_461 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
. V_261 = V_303 ,
} ;
int V_251 ;
F_2 ( L_39 , V_13 ,
V_17 -> V_29 -> V_197 . V_196 ,
V_17 -> V_197 . V_196 ,
( unsigned long long ) V_15 ) ;
F_3 ( V_15 , F_70 ( V_152 ) -> V_462 , V_17 , & args ) ;
V_33 . V_30 = args . V_30 ;
V_251 = F_68 ( F_77 ( V_152 ) -> V_80 , F_77 ( V_152 ) , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
if ( V_251 >= 0 ) {
memcpy ( F_70 ( V_152 ) -> V_462 , V_33 . V_16 . V_135 , V_463 ) ;
V_251 += args . V_30 ;
}
F_270 ( V_152 ) ;
F_2 ( L_40 , V_13 , V_251 ) ;
return V_251 ;
}
static int F_271 ( struct V_17 * V_17 , struct V_261 * V_303 ,
T_1 V_15 , struct V_390 * * V_23 , unsigned int V_22 , int V_459 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_17 -> V_27 ) ,
F_269 ( V_17 , V_303 , V_15 ,
V_23 , V_22 , V_459 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_272 ( struct V_53 * V_152 , struct V_17 * V_17 ,
struct V_178 * V_295 , T_8 V_464 )
{
struct V_449 * V_135 ;
int V_212 = V_295 -> V_431 ;
int V_251 = - V_240 ;
F_4 ( ! ( V_295 -> V_204 & V_465 ) ) ;
F_4 ( ! F_273 ( V_212 ) && ! F_274 ( V_212 ) && ! F_275 ( V_212 ) && ! F_276 ( V_212 ) ) ;
V_135 = F_261 ( V_152 , & V_17 -> V_197 , V_295 , V_466 ) ;
if ( V_135 == NULL )
goto V_116;
if ( F_273 ( V_212 ) )
V_135 -> V_318 . V_450 = V_467 ;
else if ( F_274 ( V_212 ) ) {
V_135 -> V_318 . V_450 = V_468 ;
V_135 -> V_318 . V_206 . V_469 . V_470 = F_277 ( V_464 ) ;
V_135 -> V_318 . V_206 . V_469 . V_471 = F_278 ( V_464 ) ;
}
else if ( F_275 ( V_212 ) ) {
V_135 -> V_318 . V_450 = V_472 ;
V_135 -> V_318 . V_206 . V_469 . V_470 = F_277 ( V_464 ) ;
V_135 -> V_318 . V_206 . V_469 . V_471 = F_278 ( V_464 ) ;
}
V_251 = F_262 ( V_152 , V_17 , V_135 ) ;
F_264 ( V_135 ) ;
V_116:
return V_251 ;
}
static int F_279 ( struct V_53 * V_152 , struct V_17 * V_17 ,
struct V_178 * V_295 , T_8 V_464 )
{
struct V_49 V_50 = { } ;
int V_1 ;
V_295 -> V_431 &= ~ F_245 () ;
do {
V_1 = F_16 ( F_77 ( V_152 ) ,
F_272 ( V_152 , V_17 , V_295 , V_464 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_280 ( struct V_46 * V_47 , struct V_341 * V_342 ,
struct V_473 * V_474 )
{
struct V_475 args = {
. V_187 = V_342 ,
. V_198 = V_47 -> V_199 ,
} ;
struct V_476 V_33 = {
. V_474 = V_474 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_477 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
F_73 ( V_474 -> V_316 ) ;
return F_68 ( V_47 -> V_80 , V_47 , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
}
static int F_281 ( struct V_46 * V_47 , struct V_341 * V_342 , struct V_473 * V_474 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_47 ,
F_280 ( V_47 , V_342 , V_474 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_282 ( struct V_46 * V_47 , struct V_341 * V_342 ,
struct V_369 * V_478 )
{
struct V_479 args = {
. V_187 = V_342 ,
. V_198 = V_47 -> V_199 ,
} ;
struct V_480 V_33 = {
. V_478 = V_478 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_481 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
return F_68 ( V_47 -> V_80 , V_47 , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
}
static int F_213 ( struct V_46 * V_47 , struct V_341 * V_342 , struct V_369 * V_478 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_47 ,
F_282 ( V_47 , V_342 , V_478 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_283 ( struct V_46 * V_47 , struct V_341 * V_342 , struct V_369 * V_478 )
{
int error ;
F_73 ( V_478 -> V_316 ) ;
error = F_213 ( V_47 , V_342 , V_478 ) ;
if ( error == 0 )
F_284 ( V_47 , V_342 , V_478 -> V_482 ) ;
return error ;
}
static int F_285 ( struct V_46 * V_47 , struct V_341 * V_342 ,
struct V_483 * V_484 )
{
struct V_485 args = {
. V_187 = V_342 ,
. V_198 = V_47 -> V_199 ,
} ;
struct V_486 V_33 = {
. V_484 = V_484 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_487 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
if ( ( args . V_198 [ 0 ] & V_488 [ 0 ] ) == 0 ) {
memset ( V_484 , 0 , sizeof( * V_484 ) ) ;
return 0 ;
}
F_73 ( V_484 -> V_316 ) ;
return F_68 ( V_47 -> V_80 , V_47 , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
}
static int F_286 ( struct V_46 * V_47 , struct V_341 * V_342 ,
struct V_483 * V_484 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_47 ,
F_285 ( V_47 , V_342 , V_484 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
void F_287 ( struct V_489 * V_135 )
{
F_270 ( V_135 -> V_490 -> V_53 ) ;
}
static int F_288 ( struct V_98 * V_99 , struct V_489 * V_135 )
{
struct V_46 * V_47 = F_77 ( V_135 -> V_490 -> V_53 ) ;
if ( F_190 ( V_99 , V_47 , V_135 -> args . V_491 -> V_52 ) == - V_129 ) {
F_191 ( V_99 ) ;
return - V_129 ;
}
F_287 ( V_135 ) ;
if ( V_99 -> V_149 > 0 )
F_29 ( V_47 , V_135 -> V_87 ) ;
return 0 ;
}
static int F_289 ( struct V_98 * V_99 , struct V_489 * V_135 )
{
F_2 ( L_17 , V_13 ) ;
if ( ! F_45 ( V_99 , & V_135 -> V_33 . V_138 ) )
return - V_129 ;
return V_135 -> V_492 ? V_135 -> V_492 ( V_99 , V_135 ) :
F_288 ( V_99 , V_135 ) ;
}
static void F_290 ( struct V_489 * V_135 , struct V_139 * V_140 )
{
V_135 -> V_87 = V_132 ;
V_135 -> V_492 = F_288 ;
V_140 -> V_256 = & V_257 [ V_493 ] ;
F_49 ( & V_135 -> args . V_137 , & V_135 -> V_33 . V_138 , 0 ) ;
}
static void F_291 ( struct V_98 * V_99 , struct V_489 * V_135 )
{
if ( F_54 ( F_77 ( V_135 -> V_490 -> V_53 ) ,
& V_135 -> args . V_137 ,
& V_135 -> V_33 . V_138 ,
V_99 ) )
return;
F_57 ( V_99 ) ;
}
static int F_292 ( struct V_98 * V_99 , struct V_494 * V_135 )
{
struct V_53 * V_53 = V_135 -> V_490 -> V_53 ;
if ( F_190 ( V_99 , F_77 ( V_53 ) , V_135 -> args . V_491 -> V_52 ) == - V_129 ) {
F_191 ( V_99 ) ;
return - V_129 ;
}
if ( V_99 -> V_149 >= 0 ) {
F_29 ( F_77 ( V_53 ) , V_135 -> V_87 ) ;
F_293 ( V_53 , & V_135 -> V_316 ) ;
}
return 0 ;
}
static int F_294 ( struct V_98 * V_99 , struct V_494 * V_135 )
{
if ( ! F_45 ( V_99 , & V_135 -> V_33 . V_138 ) )
return - V_129 ;
return V_135 -> V_495 ? V_135 -> V_495 ( V_99 , V_135 ) :
F_292 ( V_99 , V_135 ) ;
}
static
bool F_295 ( const struct V_494 * V_135 )
{
const struct V_496 * V_497 = V_135 -> V_490 ;
if ( V_135 -> V_498 != NULL || V_497 -> V_499 != NULL )
return false ;
return F_17 ( V_497 -> V_53 , V_57 ) == 0 ;
}
static void F_296 ( struct V_494 * V_135 , struct V_139 * V_140 )
{
struct V_46 * V_47 = F_77 ( V_135 -> V_490 -> V_53 ) ;
if ( ! F_295 ( V_135 ) ) {
V_135 -> args . V_198 = NULL ;
V_135 -> V_33 . V_316 = NULL ;
} else
V_135 -> args . V_198 = V_47 -> V_338 ;
if ( ! V_135 -> V_495 )
V_135 -> V_495 = F_292 ;
V_135 -> V_33 . V_47 = V_47 ;
V_135 -> V_87 = V_132 ;
V_140 -> V_256 = & V_257 [ V_500 ] ;
F_49 ( & V_135 -> args . V_137 , & V_135 -> V_33 . V_138 , 1 ) ;
}
static void F_297 ( struct V_98 * V_99 , struct V_494 * V_135 )
{
if ( F_54 ( F_77 ( V_135 -> V_490 -> V_53 ) ,
& V_135 -> args . V_137 ,
& V_135 -> V_33 . V_138 ,
V_99 ) )
return;
F_57 ( V_99 ) ;
}
static void F_298 ( struct V_98 * V_99 , struct V_501 * V_135 )
{
if ( F_54 ( F_77 ( V_135 -> V_53 ) ,
& V_135 -> args . V_137 ,
& V_135 -> V_33 . V_138 ,
V_99 ) )
return;
F_57 ( V_99 ) ;
}
static int F_299 ( struct V_98 * V_99 , struct V_501 * V_135 )
{
struct V_53 * V_53 = V_135 -> V_53 ;
if ( F_190 ( V_99 , F_77 ( V_53 ) , NULL ) == - V_129 ) {
F_191 ( V_99 ) ;
return - V_129 ;
}
return 0 ;
}
static int F_300 ( struct V_98 * V_99 , struct V_501 * V_135 )
{
if ( ! F_45 ( V_99 , & V_135 -> V_33 . V_138 ) )
return - V_129 ;
return V_135 -> V_502 ( V_99 , V_135 ) ;
}
static void F_301 ( struct V_501 * V_135 , struct V_139 * V_140 )
{
struct V_46 * V_47 = F_77 ( V_135 -> V_53 ) ;
if ( V_135 -> V_502 == NULL )
V_135 -> V_502 = F_299 ;
V_135 -> V_33 . V_47 = V_47 ;
V_140 -> V_256 = & V_257 [ V_503 ] ;
F_49 ( & V_135 -> args . V_137 , & V_135 -> V_33 . V_138 , 1 ) ;
}
static void F_302 ( void * V_133 )
{
struct V_504 * V_135 = V_133 ;
struct V_31 * V_32 = V_135 -> V_80 ;
if ( F_303 ( & V_32 -> V_505 ) > 1 )
F_304 ( V_32 ) ;
F_305 ( V_32 ) ;
F_86 ( V_135 ) ;
}
static void F_306 ( struct V_98 * V_99 , void * V_133 )
{
struct V_504 * V_135 = V_133 ;
struct V_31 * V_32 = V_135 -> V_80 ;
unsigned long V_87 = V_135 -> V_87 ;
if ( V_99 -> V_149 < 0 ) {
if ( F_36 ( V_506 , & V_32 -> V_507 ) == 0 )
return;
if ( V_99 -> V_149 != V_508 ) {
F_21 ( V_32 ) ;
return;
}
F_307 ( V_32 ) ;
}
F_25 ( V_32 , V_87 ) ;
}
static int F_308 ( struct V_31 * V_32 , struct V_261 * V_303 , unsigned V_509 )
{
struct V_139 V_140 = {
. V_256 = & V_257 [ V_510 ] ,
. V_259 = V_32 ,
. V_261 = V_303 ,
} ;
struct V_504 * V_135 ;
if ( V_509 == 0 )
return 0 ;
if ( ! F_309 ( & V_32 -> V_505 ) )
return - V_14 ;
V_135 = F_219 ( sizeof( * V_135 ) , V_248 ) ;
if ( V_135 == NULL )
return - V_240 ;
V_135 -> V_80 = V_32 ;
V_135 -> V_87 = V_132 ;
return F_310 ( V_32 -> V_511 , & V_140 , V_512 ,
& V_513 , V_135 ) ;
}
static int F_311 ( struct V_31 * V_32 , struct V_261 * V_303 )
{
struct V_139 V_140 = {
. V_256 = & V_257 [ V_510 ] ,
. V_259 = V_32 ,
. V_261 = V_303 ,
} ;
unsigned long V_514 = V_132 ;
int V_251 ;
V_251 = F_67 ( V_32 -> V_511 , & V_140 , 0 ) ;
if ( V_251 < 0 )
return V_251 ;
F_25 ( V_32 , V_514 ) ;
return 0 ;
}
static inline int F_312 ( struct V_46 * V_47 )
{
return ( V_47 -> V_83 & V_346 )
&& ( V_47 -> V_367 & V_515 )
&& ( V_47 -> V_367 & V_516 ) ;
}
static int F_313 ( const void * V_517 , T_9 V_518 ,
struct V_390 * * V_23 , unsigned int * V_30 )
{
struct V_390 * V_519 , * * V_520 ;
int V_521 = 0 ;
T_9 V_378 ;
V_520 = V_23 ;
do {
V_378 = F_314 ( T_9 , V_522 , V_518 ) ;
V_519 = F_218 ( V_306 ) ;
if ( V_519 == NULL )
goto V_523;
memcpy ( F_315 ( V_519 ) , V_517 , V_378 ) ;
V_517 += V_378 ;
V_518 -= V_378 ;
* V_23 ++ = V_519 ;
V_521 ++ ;
} while ( V_518 != 0 );
return V_521 ;
V_523:
for(; V_521 > 0 ; V_521 -- )
F_222 ( V_520 [ V_521 - 1 ] ) ;
return - V_240 ;
}
static void F_316 ( struct V_53 * V_53 , struct V_524 * V_525 )
{
struct V_155 * V_156 = F_70 ( V_53 ) ;
F_26 ( & V_53 -> V_157 ) ;
F_86 ( V_156 -> V_526 ) ;
V_156 -> V_526 = V_525 ;
F_28 ( & V_53 -> V_157 ) ;
}
static void F_317 ( struct V_53 * V_53 )
{
F_316 ( V_53 , NULL ) ;
}
static inline T_10 F_318 ( struct V_53 * V_53 , char * V_517 , T_9 V_518 )
{
struct V_155 * V_156 = F_70 ( V_53 ) ;
struct V_524 * V_525 ;
int V_54 = - V_247 ;
F_26 ( & V_53 -> V_157 ) ;
V_525 = V_156 -> V_526 ;
if ( V_525 == NULL )
goto V_116;
if ( V_517 == NULL )
goto V_527;
if ( V_525 -> V_528 == 0 )
goto V_116;
V_54 = - V_529 ;
if ( V_525 -> V_378 > V_518 )
goto V_116;
memcpy ( V_517 , V_525 -> V_135 , V_525 -> V_378 ) ;
V_527:
V_54 = V_525 -> V_378 ;
V_116:
F_28 ( & V_53 -> V_157 ) ;
return V_54 ;
}
static void F_319 ( struct V_53 * V_53 , struct V_390 * * V_23 , T_9 V_30 , T_9 V_530 )
{
struct V_524 * V_525 ;
T_9 V_518 = sizeof( * V_525 ) + V_530 ;
if ( V_518 <= V_522 ) {
V_525 = F_219 ( V_518 , V_306 ) ;
if ( V_525 == NULL )
goto V_116;
V_525 -> V_528 = 1 ;
F_320 ( V_525 -> V_135 , V_23 , V_30 , V_530 ) ;
} else {
V_525 = F_219 ( sizeof( * V_525 ) , V_306 ) ;
if ( V_525 == NULL )
goto V_116;
V_525 -> V_528 = 0 ;
}
V_525 -> V_378 = V_530 ;
V_116:
F_316 ( V_53 , V_525 ) ;
}
static T_10 F_321 ( struct V_53 * V_53 , void * V_517 , T_9 V_518 )
{
struct V_390 * V_23 [ V_531 ] = { NULL , } ;
struct V_532 args = {
. V_187 = F_83 ( V_53 ) ,
. V_533 = V_23 ,
. V_530 = V_518 ,
} ;
struct V_534 V_33 = {
. V_530 = V_518 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_535 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
unsigned int V_536 = F_322 ( V_518 , V_522 ) ;
int V_54 = - V_240 , V_377 ;
if ( V_536 == 0 )
V_536 = 1 ;
if ( V_536 > F_210 ( V_23 ) )
return - V_529 ;
for ( V_377 = 0 ; V_377 < V_536 ; V_377 ++ ) {
V_23 [ V_377 ] = F_218 ( V_306 ) ;
if ( ! V_23 [ V_377 ] )
goto V_255;
}
V_33 . V_537 = F_218 ( V_306 ) ;
if ( ! V_33 . V_537 )
goto V_255;
args . V_530 = V_536 * V_522 ;
args . V_538 = 0 ;
F_2 ( L_41 ,
V_13 , V_517 , V_518 , V_536 , args . V_530 ) ;
V_54 = F_68 ( F_77 ( V_53 ) -> V_80 , F_77 ( V_53 ) ,
& V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
if ( V_54 )
goto V_255;
if ( V_33 . V_539 & V_540 ) {
if ( V_517 == NULL )
goto V_541;
V_54 = - V_529 ;
goto V_255;
}
F_319 ( V_53 , V_23 , V_33 . V_542 , V_33 . V_530 ) ;
if ( V_517 )
F_320 ( V_517 , V_23 , V_33 . V_542 , V_33 . V_530 ) ;
V_541:
V_54 = V_33 . V_530 ;
V_255:
for ( V_377 = 0 ; V_377 < V_536 ; V_377 ++ )
if ( V_23 [ V_377 ] )
F_222 ( V_23 [ V_377 ] ) ;
if ( V_33 . V_537 )
F_222 ( V_33 . V_537 ) ;
return V_54 ;
}
static T_10 F_323 ( struct V_53 * V_53 , void * V_517 , T_9 V_518 )
{
struct V_49 V_50 = { } ;
T_10 V_54 ;
do {
V_54 = F_321 ( V_53 , V_517 , V_518 ) ;
if ( V_54 >= 0 )
break;
V_54 = F_16 ( F_77 ( V_53 ) , V_54 , & V_50 ) ;
} while ( V_50 . V_55 );
return V_54 ;
}
static T_10 F_324 ( struct V_53 * V_53 , void * V_517 , T_9 V_518 )
{
struct V_46 * V_47 = F_77 ( V_53 ) ;
int V_54 ;
if ( ! F_312 ( V_47 ) )
return - V_543 ;
V_54 = F_325 ( V_47 , V_53 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( F_70 ( V_53 ) -> V_158 & V_544 )
F_326 ( V_53 ) ;
V_54 = F_318 ( V_53 , V_517 , V_518 ) ;
if ( V_54 != - V_247 )
return V_54 ;
return F_323 ( V_53 , V_517 , V_518 ) ;
}
static int F_327 ( struct V_53 * V_53 , const void * V_517 , T_9 V_518 )
{
struct V_46 * V_47 = F_77 ( V_53 ) ;
struct V_390 * V_23 [ V_531 ] ;
struct V_545 V_318 = {
. V_187 = F_83 ( V_53 ) ,
. V_533 = V_23 ,
. V_530 = V_518 ,
} ;
struct V_546 V_33 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_547 ] ,
. V_259 = & V_318 ,
. V_260 = & V_33 ,
} ;
unsigned int V_536 = F_322 ( V_518 , V_522 ) ;
int V_54 , V_377 ;
if ( ! F_312 ( V_47 ) )
return - V_543 ;
if ( V_536 > F_210 ( V_23 ) )
return - V_529 ;
V_377 = F_313 ( V_517 , V_518 , V_318 . V_533 , & V_318 . V_538 ) ;
if ( V_377 < 0 )
return V_377 ;
F_18 ( V_53 ) ;
V_54 = F_68 ( V_47 -> V_80 , V_47 , & V_140 , & V_318 . V_137 , & V_33 . V_138 , 1 ) ;
for (; V_377 > 0 ; V_377 -- )
F_328 ( V_23 [ V_377 - 1 ] ) ;
F_26 ( & V_53 -> V_157 ) ;
F_70 ( V_53 ) -> V_158 |= V_159 ;
F_28 ( & V_53 -> V_157 ) ;
F_329 ( V_53 ) ;
F_326 ( V_53 ) ;
return V_54 ;
}
static int F_330 ( struct V_53 * V_53 , const void * V_517 , T_9 V_518 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_53 ) ,
F_327 ( V_53 , V_517 , V_518 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int
F_190 ( struct V_98 * V_99 , const struct V_46 * V_47 , struct V_51 * V_52 )
{
struct V_31 * V_32 = V_47 -> V_31 ;
if ( V_99 -> V_149 >= 0 )
return 0 ;
switch( V_99 -> V_149 ) {
case - V_59 :
case - V_60 :
case - V_61 :
if ( V_52 == NULL )
break;
F_20 ( V_52 -> V_53 ) ;
case - V_56 :
if ( V_52 == NULL )
break;
F_19 ( V_47 , V_52 ) ;
goto V_58;
case - V_62 :
if ( V_52 != NULL )
F_19 ( V_47 , V_52 ) ;
case - V_63 :
case - V_64 :
F_21 ( V_32 ) ;
goto V_58;
#if F_22 ( V_65 )
case - V_66 :
case - V_67 :
case - V_68 :
case - V_70 :
case - V_69 :
case - V_71 :
case - V_72 :
F_2 ( L_42 , V_13 ,
V_99 -> V_149 ) ;
F_23 ( V_32 -> V_73 , V_99 -> V_149 ) ;
V_99 -> V_149 = 0 ;
return - V_129 ;
#endif
case - V_78 :
F_331 ( V_47 , V_548 ) ;
case - V_77 :
case - V_79 :
F_44 ( V_99 , V_43 ) ;
V_99 -> V_149 = 0 ;
return - V_129 ;
case - V_81 :
case - V_82 :
V_99 -> V_149 = 0 ;
return - V_129 ;
}
V_99 -> V_149 = F_1 ( V_99 -> V_149 ) ;
return 0 ;
V_58:
F_52 ( & V_32 -> V_549 , V_99 , NULL ) ;
if ( F_36 ( V_35 , & V_32 -> V_34 ) == 0 )
F_332 ( & V_32 -> V_549 , V_99 ) ;
V_99 -> V_149 = 0 ;
return - V_129 ;
}
static void F_333 ( const struct V_31 * V_32 ,
T_11 * V_550 )
{
T_2 V_205 [ 2 ] ;
if ( F_36 ( V_551 , & V_32 -> V_34 ) ) {
V_205 [ 0 ] = 0 ;
V_205 [ 1 ] = ( T_2 ) ( V_552 + 1 ) ;
} else {
struct V_553 * V_554 = F_334 ( V_32 -> V_555 , V_556 ) ;
V_205 [ 0 ] = ( T_2 ) V_554 -> V_557 . V_558 ;
V_205 [ 1 ] = ( T_2 ) V_554 -> V_557 . V_559 ;
}
memcpy ( V_550 -> V_135 , V_205 , sizeof( V_550 -> V_135 ) ) ;
}
int F_335 ( struct V_31 * V_32 , T_3 V_560 ,
unsigned short V_561 , struct V_261 * V_303 ,
struct V_562 * V_33 )
{
T_11 V_563 ;
struct V_564 V_565 = {
. V_563 = & V_563 ,
. V_566 = V_560 ,
. V_567 = V_32 -> V_568 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_569 ] ,
. V_259 = & V_565 ,
. V_260 = V_33 ,
. V_261 = V_303 ,
} ;
int V_251 ;
F_333 ( V_32 , & V_563 ) ;
F_112 () ;
V_565 . V_570 = F_336 ( V_565 . V_571 ,
sizeof( V_565 . V_571 ) , L_43 ,
V_32 -> V_572 ,
F_337 ( V_32 -> V_511 ,
V_573 ) ,
F_337 ( V_32 -> V_511 ,
V_574 ) ) ;
V_565 . V_575 = F_336 ( V_565 . V_576 ,
sizeof( V_565 . V_576 ) ,
F_337 ( V_32 -> V_511 ,
V_577 ) ) ;
F_115 () ;
V_565 . V_578 = F_336 ( V_565 . V_579 ,
sizeof( V_565 . V_579 ) , L_44 ,
V_32 -> V_572 , V_561 >> 8 , V_561 & 255 ) ;
F_2 ( L_45 ,
V_32 -> V_511 -> V_580 -> V_581 -> V_582 ,
V_565 . V_570 , V_565 . V_571 ) ;
V_251 = F_67 ( V_32 -> V_511 , & V_140 , V_583 ) ;
F_2 ( L_46 , V_251 ) ;
return V_251 ;
}
int F_338 ( struct V_31 * V_32 ,
struct V_562 * V_318 ,
struct V_261 * V_303 )
{
struct V_369 V_478 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_584 ] ,
. V_259 = V_318 ,
. V_260 = & V_478 ,
. V_261 = V_303 ,
} ;
unsigned long V_514 ;
int V_251 ;
F_2 ( L_47 ,
V_32 -> V_511 -> V_580 -> V_581 -> V_582 ,
V_32 -> V_191 ) ;
V_514 = V_132 ;
V_251 = F_67 ( V_32 -> V_511 , & V_140 , V_583 ) ;
if ( V_251 == 0 ) {
F_26 ( & V_32 -> V_88 ) ;
V_32 -> V_585 = V_478 . V_586 * V_75 ;
V_32 -> V_89 = V_514 ;
F_28 ( & V_32 -> V_88 ) ;
}
F_2 ( L_48 , V_251 ) ;
return V_251 ;
}
static void F_339 ( struct V_98 * V_99 , void * V_133 )
{
struct V_587 * V_135 = V_133 ;
if ( ! F_45 ( V_99 , & V_135 -> V_33 . V_138 ) )
return;
switch ( V_99 -> V_149 ) {
case - V_63 :
case - V_62 :
case 0 :
F_29 ( V_135 -> V_33 . V_47 , V_135 -> V_87 ) ;
break;
default:
if ( F_190 ( V_99 , V_135 -> V_33 . V_47 , NULL ) ==
- V_129 ) {
F_191 ( V_99 ) ;
return;
}
}
V_135 -> V_253 = V_99 -> V_149 ;
}
static void F_340 ( void * V_133 )
{
F_86 ( V_133 ) ;
}
static void F_341 ( struct V_98 * V_99 , void * V_135 )
{
struct V_587 * V_588 ;
V_588 = (struct V_587 * ) V_135 ;
if ( F_54 ( V_588 -> V_33 . V_47 ,
& V_588 -> args . V_137 ,
& V_588 -> V_33 . V_138 , V_99 ) )
return;
F_57 ( V_99 ) ;
}
static int F_342 ( struct V_53 * V_53 , struct V_261 * V_303 , const T_6 * V_208 , int V_589 )
{
struct V_587 * V_135 ;
struct V_46 * V_47 = F_77 ( V_53 ) ;
struct V_98 * V_99 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_590 ] ,
. V_261 = V_303 ,
} ;
struct V_142 V_262 = {
. V_144 = V_47 -> V_80 ,
. V_139 = & V_140 ,
. V_145 = & V_591 ,
. V_177 = V_266 ,
} ;
int V_251 = 0 ;
V_135 = F_78 ( sizeof( * V_135 ) , V_248 ) ;
if ( V_135 == NULL )
return - V_240 ;
F_49 ( & V_135 -> args . V_137 , & V_135 -> V_33 . V_138 , 1 ) ;
V_135 -> args . V_342 = & V_135 -> V_187 ;
V_135 -> args . V_208 = & V_135 -> V_208 ;
V_135 -> args . V_198 = V_47 -> V_338 ;
F_152 ( & V_135 -> V_187 , F_83 ( V_53 ) ) ;
F_105 ( & V_135 -> V_208 , V_208 ) ;
V_135 -> V_33 . V_316 = & V_135 -> V_316 ;
V_135 -> V_33 . V_47 = V_47 ;
F_73 ( V_135 -> V_33 . V_316 ) ;
V_135 -> V_87 = V_132 ;
V_135 -> V_253 = 0 ;
V_262 . V_147 = V_135 ;
V_140 . V_259 = & V_135 -> args ;
V_140 . V_260 = & V_135 -> V_33 ;
V_99 = F_61 ( & V_262 ) ;
if ( F_62 ( V_99 ) )
return F_63 ( V_99 ) ;
if ( ! V_589 )
goto V_116;
V_251 = F_97 ( V_99 ) ;
if ( V_251 != 0 )
goto V_116;
V_251 = V_135 -> V_253 ;
if ( V_251 == 0 )
F_293 ( V_53 , & V_135 -> V_316 ) ;
else
F_193 ( V_53 , & V_135 -> V_316 ) ;
V_116:
F_64 ( V_99 ) ;
return V_251 ;
}
int F_343 ( struct V_53 * V_53 , struct V_261 * V_303 , const T_6 * V_208 , int V_589 )
{
struct V_46 * V_47 = F_77 ( V_53 ) ;
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_342 ( V_53 , V_303 , V_208 , V_589 ) ;
switch ( V_1 ) {
case - V_63 :
case - V_62 :
case 0 :
return 0 ;
}
V_1 = F_16 ( V_47 , V_1 , & V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static unsigned long
F_344 ( unsigned long V_41 )
{
F_14 ( V_41 ) ;
V_41 <<= 1 ;
if ( V_41 > V_592 )
return V_592 ;
return V_41 ;
}
static int F_345 ( struct V_51 * V_52 , int V_593 , struct V_594 * V_595 )
{
struct V_53 * V_53 = V_52 -> V_53 ;
struct V_46 * V_47 = F_77 ( V_53 ) ;
struct V_31 * V_32 = V_47 -> V_31 ;
struct V_596 V_318 = {
. V_187 = F_83 ( V_53 ) ,
. V_597 = V_595 ,
} ;
struct V_598 V_33 = {
. V_599 = V_595 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_600 ] ,
. V_259 = & V_318 ,
. V_260 = & V_33 ,
. V_261 = V_52 -> V_185 -> V_236 ,
} ;
struct V_601 * V_602 ;
int V_251 ;
V_318 . V_603 . V_190 = V_32 -> V_191 ;
V_251 = F_346 ( V_52 , V_595 ) ;
if ( V_251 != 0 )
goto V_116;
V_602 = V_595 -> V_604 . V_605 . V_185 ;
V_318 . V_603 . V_192 = V_602 -> V_606 . V_195 ;
V_318 . V_603 . V_607 = V_47 -> V_607 ;
V_251 = F_68 ( V_47 -> V_80 , V_47 , & V_140 , & V_318 . V_137 , & V_33 . V_138 , 1 ) ;
switch ( V_251 ) {
case 0 :
V_595 -> V_608 = V_609 ;
break;
case - V_610 :
V_251 = 0 ;
}
V_595 -> V_611 -> V_612 ( V_595 ) ;
V_116:
return V_251 ;
}
static int F_347 ( struct V_51 * V_52 , int V_593 , struct V_594 * V_595 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_52 -> V_53 ) ,
F_345 ( V_52 , V_593 , V_595 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_348 ( struct V_613 * V_613 , struct V_594 * V_597 )
{
int V_33 = 0 ;
switch ( V_597 -> V_614 & ( V_615 | V_616 ) ) {
case V_615 :
V_33 = F_349 ( V_613 , V_597 ) ;
break;
case V_616 :
V_33 = F_350 ( V_613 , V_597 ) ;
break;
default:
F_351 () ;
}
return V_33 ;
}
static struct V_617 * F_352 ( struct V_594 * V_597 ,
struct V_245 * V_246 ,
struct V_601 * V_602 ,
struct V_618 * V_168 )
{
struct V_617 * V_21 ;
struct V_53 * V_53 = V_602 -> V_619 -> V_53 ;
V_21 = F_78 ( sizeof( * V_21 ) , V_248 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_318 . V_187 = F_83 ( V_53 ) ;
V_21 -> V_318 . V_597 = & V_21 -> V_597 ;
V_21 -> V_318 . V_168 = V_168 ;
V_21 -> V_33 . V_168 = V_168 ;
V_21 -> V_318 . V_208 = & V_602 -> V_620 ;
V_21 -> V_602 = V_602 ;
F_82 ( & V_602 -> V_621 ) ;
V_21 -> V_246 = F_129 ( V_246 ) ;
memcpy ( & V_21 -> V_597 , V_597 , sizeof( V_21 -> V_597 ) ) ;
V_21 -> V_47 = F_77 ( V_53 ) ;
return V_21 ;
}
static void F_353 ( void * V_135 )
{
struct V_617 * V_133 = V_135 ;
F_90 ( V_133 -> V_318 . V_168 ) ;
F_354 ( V_133 -> V_602 ) ;
F_140 ( V_133 -> V_246 ) ;
F_86 ( V_133 ) ;
}
static void F_355 ( struct V_98 * V_99 , void * V_135 )
{
struct V_617 * V_133 = V_135 ;
if ( ! F_45 ( V_99 , & V_133 -> V_33 . V_138 ) )
return;
switch ( V_99 -> V_149 ) {
case 0 :
F_105 ( & V_133 -> V_602 -> V_620 ,
& V_133 -> V_33 . V_208 ) ;
F_29 ( V_133 -> V_47 , V_133 -> V_87 ) ;
break;
case - V_61 :
case - V_82 :
case - V_63 :
case - V_62 :
break;
default:
if ( F_190 ( V_99 , V_133 -> V_47 , NULL ) == - V_129 )
F_191 ( V_99 ) ;
}
}
static void F_356 ( struct V_98 * V_99 , void * V_135 )
{
struct V_617 * V_133 = V_135 ;
if ( F_151 ( V_133 -> V_318 . V_168 , V_99 ) != 0 )
return;
if ( ( V_133 -> V_602 -> V_622 & V_623 ) == 0 ) {
V_99 -> V_272 = NULL ;
return;
}
V_133 -> V_87 = V_132 ;
if ( F_54 ( V_133 -> V_47 ,
& V_133 -> V_318 . V_137 ,
& V_133 -> V_33 . V_138 , V_99 ) )
return;
F_57 ( V_99 ) ;
}
static struct V_98 * F_357 ( struct V_594 * V_597 ,
struct V_245 * V_246 ,
struct V_601 * V_602 ,
struct V_618 * V_168 )
{
struct V_617 * V_135 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_624 ] ,
. V_261 = V_246 -> V_303 ,
} ;
struct V_142 V_262 = {
. V_144 = F_233 ( V_602 -> V_619 -> V_53 ) ,
. V_139 = & V_140 ,
. V_145 = & V_625 ,
. V_264 = V_265 ,
. V_177 = V_266 ,
} ;
V_597 -> V_608 = V_609 ;
V_135 = F_352 ( V_597 , V_246 , V_602 , V_168 ) ;
if ( V_135 == NULL ) {
F_90 ( V_168 ) ;
return F_119 ( - V_240 ) ;
}
F_49 ( & V_135 -> V_318 . V_137 , & V_135 -> V_33 . V_138 , 1 ) ;
V_140 . V_259 = & V_135 -> V_318 ;
V_140 . V_260 = & V_135 -> V_33 ;
V_262 . V_147 = V_135 ;
return F_61 ( & V_262 ) ;
}
static int F_358 ( struct V_51 * V_52 , int V_593 , struct V_594 * V_595 )
{
struct V_155 * V_156 = F_70 ( V_52 -> V_53 ) ;
struct V_618 * V_168 ;
struct V_601 * V_602 ;
struct V_98 * V_99 ;
int V_251 = 0 ;
unsigned char V_614 = V_595 -> V_614 ;
V_251 = F_346 ( V_52 , V_595 ) ;
V_595 -> V_614 |= V_626 ;
F_359 ( & V_156 -> V_627 ) ;
if ( F_348 ( V_595 -> V_628 , V_595 ) == - V_247 ) {
F_360 ( & V_156 -> V_627 ) ;
goto V_116;
}
F_360 ( & V_156 -> V_627 ) ;
if ( V_251 != 0 )
goto V_116;
if ( F_36 ( V_225 , & V_52 -> V_177 ) )
goto V_116;
V_602 = V_595 -> V_604 . V_605 . V_185 ;
V_168 = F_79 ( & V_602 -> V_606 , V_306 ) ;
V_251 = - V_240 ;
if ( V_168 == NULL )
goto V_116;
V_99 = F_357 ( V_595 , F_226 ( V_595 -> V_628 ) , V_602 , V_168 ) ;
V_251 = F_63 ( V_99 ) ;
if ( F_62 ( V_99 ) )
goto V_116;
V_251 = F_97 ( V_99 ) ;
F_64 ( V_99 ) ;
V_116:
V_595 -> V_614 = V_614 ;
return V_251 ;
}
static struct V_629 * F_361 ( struct V_594 * V_597 ,
struct V_245 * V_246 , struct V_601 * V_602 ,
T_5 V_180 )
{
struct V_629 * V_21 ;
struct V_53 * V_53 = V_602 -> V_619 -> V_53 ;
struct V_46 * V_47 = F_77 ( V_53 ) ;
V_21 = F_78 ( sizeof( * V_21 ) , V_180 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_318 . V_187 = F_83 ( V_53 ) ;
V_21 -> V_318 . V_597 = & V_21 -> V_597 ;
V_21 -> V_318 . V_630 = F_79 ( & V_602 -> V_619 -> V_185 -> V_182 , V_180 ) ;
if ( V_21 -> V_318 . V_630 == NULL )
goto V_255;
V_21 -> V_318 . V_631 = F_79 ( & V_602 -> V_606 , V_180 ) ;
if ( V_21 -> V_318 . V_631 == NULL )
goto V_632;
V_21 -> V_318 . V_633 = & V_602 -> V_620 ;
V_21 -> V_318 . V_603 . V_190 = V_47 -> V_31 -> V_191 ;
V_21 -> V_318 . V_603 . V_192 = V_602 -> V_606 . V_195 ;
V_21 -> V_318 . V_603 . V_607 = V_47 -> V_607 ;
V_21 -> V_33 . V_631 = V_21 -> V_318 . V_631 ;
V_21 -> V_602 = V_602 ;
V_21 -> V_47 = V_47 ;
F_82 ( & V_602 -> V_621 ) ;
V_21 -> V_246 = F_129 ( V_246 ) ;
memcpy ( & V_21 -> V_597 , V_597 , sizeof( V_21 -> V_597 ) ) ;
return V_21 ;
V_632:
F_90 ( V_21 -> V_318 . V_630 ) ;
V_255:
F_86 ( V_21 ) ;
return NULL ;
}
static void F_362 ( struct V_98 * V_99 , void * V_133 )
{
struct V_629 * V_135 = V_133 ;
struct V_51 * V_52 = V_135 -> V_602 -> V_619 ;
F_2 ( L_30 , V_13 ) ;
if ( F_151 ( V_135 -> V_318 . V_631 , V_99 ) != 0 )
return;
if ( ! ( V_135 -> V_318 . V_631 -> V_634 -> V_177 & V_635 ) ) {
if ( F_151 ( V_135 -> V_318 . V_630 , V_99 ) != 0 )
return;
V_135 -> V_318 . V_226 = & V_52 -> V_208 ;
V_135 -> V_318 . V_636 = 1 ;
V_135 -> V_33 . V_630 = V_135 -> V_318 . V_630 ;
} else
V_135 -> V_318 . V_636 = 0 ;
V_135 -> V_87 = V_132 ;
if ( F_54 ( V_135 -> V_47 ,
& V_135 -> V_318 . V_137 ,
& V_135 -> V_33 . V_138 , V_99 ) )
return;
F_57 ( V_99 ) ;
F_2 ( L_49 , V_13 , V_135 -> V_253 ) ;
}
static void F_363 ( struct V_98 * V_99 , void * V_133 )
{
F_34 ( V_99 , V_101 ) ;
F_362 ( V_99 , V_133 ) ;
}
static void F_364 ( struct V_98 * V_99 , void * V_133 )
{
struct V_629 * V_135 = V_133 ;
F_2 ( L_30 , V_13 ) ;
if ( ! F_45 ( V_99 , & V_135 -> V_33 . V_138 ) )
return;
V_135 -> V_253 = V_99 -> V_149 ;
if ( V_135 -> V_318 . V_636 != 0 ) {
if ( V_135 -> V_253 == 0 )
F_145 ( & V_135 -> V_602 -> V_606 , 0 ) ;
else
goto V_116;
}
if ( V_135 -> V_253 == 0 ) {
F_105 ( & V_135 -> V_602 -> V_620 , & V_135 -> V_33 . V_208 ) ;
V_135 -> V_602 -> V_622 |= V_623 ;
F_29 ( F_77 ( V_135 -> V_246 -> V_17 -> V_27 ) , V_135 -> V_87 ) ;
}
V_116:
F_2 ( L_31 , V_13 , V_135 -> V_253 ) ;
}
static void F_365 ( void * V_133 )
{
struct V_629 * V_135 = V_133 ;
F_2 ( L_30 , V_13 ) ;
F_90 ( V_135 -> V_318 . V_630 ) ;
if ( V_135 -> V_254 != 0 ) {
struct V_98 * V_99 ;
V_99 = F_357 ( & V_135 -> V_597 , V_135 -> V_246 , V_135 -> V_602 ,
V_135 -> V_318 . V_631 ) ;
if ( ! F_62 ( V_99 ) )
F_366 ( V_99 ) ;
F_2 ( L_50 , V_13 ) ;
} else
F_90 ( V_135 -> V_318 . V_631 ) ;
F_354 ( V_135 -> V_602 ) ;
F_140 ( V_135 -> V_246 ) ;
F_86 ( V_135 ) ;
F_2 ( L_32 , V_13 ) ;
}
static void F_367 ( struct V_46 * V_47 , struct V_601 * V_602 , int V_636 , int error )
{
switch ( error ) {
case - V_60 :
case - V_61 :
V_602 -> V_606 . V_177 &= ~ V_635 ;
if ( V_636 != 0 ||
( V_602 -> V_622 & V_623 ) != 0 )
F_19 ( V_47 , V_602 -> V_619 ) ;
break;
case - V_63 :
V_602 -> V_606 . V_177 &= ~ V_635 ;
case - V_62 :
F_21 ( V_47 -> V_31 ) ;
} ;
}
static int F_368 ( struct V_51 * V_52 , int V_593 , struct V_594 * V_597 , int V_637 )
{
struct V_629 * V_135 ;
struct V_98 * V_99 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_638 ] ,
. V_261 = V_52 -> V_185 -> V_236 ,
} ;
struct V_142 V_262 = {
. V_144 = F_233 ( V_52 -> V_53 ) ,
. V_139 = & V_140 ,
. V_145 = & V_639 ,
. V_264 = V_265 ,
. V_177 = V_266 ,
} ;
int V_54 ;
F_2 ( L_30 , V_13 ) ;
V_135 = F_361 ( V_597 , F_226 ( V_597 -> V_628 ) ,
V_597 -> V_604 . V_605 . V_185 ,
V_637 == V_640 ? V_306 : V_248 ) ;
if ( V_135 == NULL )
return - V_240 ;
if ( F_369 ( V_593 ) )
V_135 -> V_318 . V_641 = 1 ;
if ( V_637 > V_640 ) {
if ( V_637 == V_642 )
V_135 -> V_318 . V_643 = V_642 ;
V_262 . V_145 = & V_644 ;
}
F_49 ( & V_135 -> V_318 . V_137 , & V_135 -> V_33 . V_138 , 1 ) ;
V_140 . V_259 = & V_135 -> V_318 ;
V_140 . V_260 = & V_135 -> V_33 ;
V_262 . V_147 = V_135 ;
V_99 = F_61 ( & V_262 ) ;
if ( F_62 ( V_99 ) )
return F_63 ( V_99 ) ;
V_54 = F_97 ( V_99 ) ;
if ( V_54 == 0 ) {
V_54 = V_135 -> V_253 ;
if ( V_54 )
F_367 ( V_135 -> V_47 , V_135 -> V_602 ,
V_135 -> V_318 . V_636 , V_54 ) ;
} else
V_135 -> V_254 = 1 ;
F_64 ( V_99 ) ;
F_2 ( L_31 , V_13 , V_54 ) ;
return V_54 ;
}
static int F_370 ( struct V_51 * V_52 , struct V_594 * V_595 )
{
struct V_46 * V_47 = F_77 ( V_52 -> V_53 ) ;
struct V_49 V_50 = {
. V_53 = V_52 -> V_53 ,
} ;
int V_1 ;
do {
if ( F_36 ( V_225 , & V_52 -> V_177 ) != 0 )
return 0 ;
V_1 = F_368 ( V_52 , V_645 , V_595 , V_642 ) ;
if ( V_1 != - V_78 )
break;
F_16 ( V_47 , V_1 , & V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_371 ( struct V_51 * V_52 , struct V_594 * V_595 )
{
struct V_46 * V_47 = F_77 ( V_52 -> V_53 ) ;
struct V_49 V_50 = {
. V_53 = V_52 -> V_53 ,
} ;
int V_1 ;
V_1 = F_346 ( V_52 , V_595 ) ;
if ( V_1 != 0 )
return V_1 ;
do {
if ( F_36 ( V_225 , & V_52 -> V_177 ) != 0 )
return 0 ;
V_1 = F_368 ( V_52 , V_645 , V_595 , V_646 ) ;
switch ( V_1 ) {
default:
goto V_116;
case - V_77 :
case - V_78 :
F_16 ( V_47 , V_1 , & V_50 ) ;
V_1 = 0 ;
}
} while ( V_50 . V_55 );
V_116:
return V_1 ;
}
static int F_372 ( struct V_51 * V_52 )
{
int V_251 , V_54 = - V_61 ;
struct V_601 * V_602 ;
struct V_46 * V_47 = F_77 ( V_52 -> V_53 ) ;
F_128 (lsp, &state->lock_states, ls_locks) {
if ( V_602 -> V_622 & V_623 ) {
V_251 = F_168 ( V_47 , & V_602 -> V_620 ) ;
if ( V_251 != V_115 ) {
if ( V_251 != - V_61 )
F_169 ( V_47 ,
& V_602 -> V_620 ) ;
V_602 -> V_622 &= ~ V_623 ;
V_54 = V_251 ;
}
}
} ;
return V_54 ;
}
static int F_373 ( struct V_51 * V_52 , struct V_594 * V_595 )
{
int V_251 = V_115 ;
if ( F_36 ( V_647 , & V_52 -> V_177 ) )
V_251 = F_372 ( V_52 ) ;
if ( V_251 != V_115 )
V_251 = F_371 ( V_52 , V_595 ) ;
return V_251 ;
}
static int F_374 ( struct V_51 * V_52 , int V_593 , struct V_594 * V_595 )
{
struct V_155 * V_156 = F_70 ( V_52 -> V_53 ) ;
unsigned char V_614 = V_595 -> V_614 ;
int V_251 = - V_648 ;
if ( ( V_614 & V_615 ) &&
! F_36 ( V_313 , & V_52 -> V_177 ) )
goto V_116;
V_251 = F_346 ( V_52 , V_595 ) ;
if ( V_251 != 0 )
goto V_116;
V_595 -> V_614 |= V_649 ;
V_251 = F_348 ( V_595 -> V_628 , V_595 ) ;
if ( V_251 < 0 )
goto V_116;
F_359 ( & V_156 -> V_627 ) ;
if ( F_36 ( V_225 , & V_52 -> V_177 ) ) {
V_595 -> V_614 = V_614 & ~ V_650 ;
V_251 = F_348 ( V_595 -> V_628 , V_595 ) ;
goto V_651;
}
V_251 = F_368 ( V_52 , V_593 , V_595 , V_640 ) ;
if ( V_251 != 0 )
goto V_651;
V_595 -> V_614 = V_614 | V_650 ;
if ( F_348 ( V_595 -> V_628 , V_595 ) < 0 )
F_24 ( V_85 L_51
L_52 , V_13 ) ;
V_651:
F_360 ( & V_156 -> V_627 ) ;
V_116:
V_595 -> V_614 = V_614 ;
return V_251 ;
}
static int F_375 ( struct V_51 * V_52 , int V_593 , struct V_594 * V_595 )
{
struct V_49 V_50 = {
. V_52 = V_52 ,
. V_53 = V_52 -> V_53 ,
} ;
int V_1 ;
do {
V_1 = F_374 ( V_52 , V_593 , V_595 ) ;
if ( V_1 == - V_610 )
V_1 = - V_129 ;
V_1 = F_16 ( F_77 ( V_52 -> V_53 ) ,
V_1 , & V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int
F_376 ( struct V_613 * V_652 , int V_593 , struct V_594 * V_595 )
{
struct V_245 * V_246 ;
struct V_51 * V_52 ;
unsigned long V_41 = V_653 ;
int V_251 ;
V_246 = F_226 ( V_652 ) ;
V_52 = V_246 -> V_52 ;
if ( V_595 -> V_654 < 0 || V_595 -> V_655 < 0 )
return - V_8 ;
if ( F_377 ( V_593 ) ) {
if ( V_52 != NULL )
return F_347 ( V_52 , V_656 , V_595 ) ;
return 0 ;
}
if ( ! ( F_378 ( V_593 ) || F_369 ( V_593 ) ) )
return - V_8 ;
if ( V_595 -> V_608 == V_609 ) {
if ( V_52 != NULL )
return F_358 ( V_52 , V_593 , V_595 ) ;
return 0 ;
}
if ( V_52 == NULL )
return - V_648 ;
switch ( V_595 -> V_608 ) {
case V_657 :
if ( ! ( V_652 -> V_658 & V_57 ) )
return - V_325 ;
break;
case V_659 :
if ( ! ( V_652 -> V_658 & V_189 ) )
return - V_325 ;
}
do {
V_251 = F_375 ( V_52 , V_593 , V_595 ) ;
if ( ( V_251 != - V_129 ) || F_378 ( V_593 ) )
break;
V_41 = F_344 ( V_41 ) ;
V_251 = - V_45 ;
if ( F_379 () )
break;
} while( V_251 < 0 );
return V_251 ;
}
int F_380 ( struct V_51 * V_52 , struct V_594 * V_597 )
{
struct V_46 * V_47 = F_77 ( V_52 -> V_53 ) ;
struct V_49 V_50 = { } ;
int V_1 ;
V_1 = F_346 ( V_52 , V_597 ) ;
if ( V_1 != 0 )
goto V_116;
do {
V_1 = F_368 ( V_52 , V_645 , V_597 , V_640 ) ;
switch ( V_1 ) {
default:
F_24 ( V_660 L_53
L_54 , V_13 , V_1 ) ;
case 0 :
case - V_250 :
goto V_116;
case - V_62 :
F_19 ( V_47 , V_52 ) ;
case - V_64 :
case - V_63 :
F_21 ( V_47 -> V_31 ) ;
goto V_116;
case - V_66 :
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
F_23 ( V_47 -> V_31 -> V_73 , V_1 ) ;
goto V_116;
case - V_45 :
case - V_59 :
case - V_60 :
case - V_61 :
case - V_56 :
F_19 ( V_47 , V_52 ) ;
V_1 = 0 ;
goto V_116;
case - V_79 :
V_1 = 0 ;
goto V_116;
case - V_240 :
case - V_610 :
V_1 = 0 ;
goto V_116;
case - V_78 :
break;
}
V_1 = F_16 ( V_47 , V_1 , & V_50 ) ;
} while ( V_50 . V_55 );
V_116:
return V_1 ;
}
static void F_381 ( void * V_133 )
{
struct V_661 * V_135 = V_133 ;
F_382 ( V_135 -> V_47 , V_135 -> V_602 ) ;
F_86 ( V_133 ) ;
}
int F_383 ( struct V_601 * V_602 )
{
struct V_46 * V_47 = V_602 -> V_619 -> V_185 -> V_269 ;
struct V_661 * V_135 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_662 ] ,
} ;
if ( V_47 -> V_31 -> V_150 -> V_382 != 0 )
return - V_8 ;
V_135 = F_219 ( sizeof( * V_135 ) , V_248 ) ;
if ( ! V_135 )
return - V_240 ;
V_135 -> V_602 = V_602 ;
V_135 -> V_47 = V_47 ;
V_135 -> args . V_603 . V_190 = V_47 -> V_31 -> V_191 ;
V_135 -> args . V_603 . V_192 = V_602 -> V_606 . V_195 ;
V_135 -> args . V_603 . V_607 = V_47 -> V_607 ;
V_140 . V_259 = & V_135 -> args ;
F_310 ( V_47 -> V_80 , & V_140 , 0 , & V_663 , V_135 ) ;
return 0 ;
}
static int F_384 ( struct V_17 * V_17 , const char * V_664 ,
const void * V_517 , T_9 V_518 ,
int V_177 , int type )
{
if ( strcmp ( V_664 , L_55 ) != 0 )
return - V_8 ;
return F_330 ( V_17 -> V_27 , V_517 , V_518 ) ;
}
static int F_385 ( struct V_17 * V_17 , const char * V_664 ,
void * V_517 , T_9 V_518 , int type )
{
if ( strcmp ( V_664 , L_55 ) != 0 )
return - V_8 ;
return F_324 ( V_17 -> V_27 , V_517 , V_518 ) ;
}
static T_9 F_386 ( struct V_17 * V_17 , char * V_665 ,
T_9 V_666 , const char * V_196 ,
T_9 V_667 , int type )
{
T_9 V_378 = sizeof( V_668 ) ;
if ( ! F_312 ( F_77 ( V_17 -> V_27 ) ) )
return 0 ;
if ( V_665 && V_378 <= V_666 )
memcpy ( V_665 , V_668 , V_378 ) ;
return V_378 ;
}
static void F_221 ( struct V_315 * V_316 )
{
if ( ! ( ( ( V_316 -> V_238 & V_669 ) ||
( V_316 -> V_238 & V_670 ) ) &&
( V_316 -> V_238 & V_387 ) &&
( V_316 -> V_238 & V_671 ) ) )
return;
V_316 -> V_238 |= V_402 | V_403 |
V_404 | V_672 ;
V_316 -> V_212 = V_277 | V_406 | V_407 ;
V_316 -> V_408 = 2 ;
}
static int F_387 ( struct V_39 * V_80 , struct V_53 * V_152 ,
const struct V_389 * V_196 ,
struct V_391 * V_673 ,
struct V_390 * V_390 )
{
struct V_46 * V_47 = F_77 ( V_152 ) ;
T_3 V_198 [ 2 ] = {
[ 0 ] = V_674 | V_675 ,
} ;
struct V_676 args = {
. V_400 = F_83 ( V_152 ) ,
. V_196 = V_196 ,
. V_390 = V_390 ,
. V_198 = V_198 ,
} ;
struct V_677 V_33 = {
. V_673 = V_673 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_678 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
int V_251 ;
F_2 ( L_56 , V_13 ) ;
if ( F_77 ( V_152 ) -> V_199 [ 1 ] & V_679 )
V_198 [ 1 ] |= V_679 ;
else
V_198 [ 0 ] |= V_26 ;
F_73 ( & V_673 -> V_316 ) ;
V_673 -> V_47 = V_47 ;
V_673 -> V_680 = 0 ;
V_251 = F_68 ( V_80 , V_47 , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
F_2 ( L_57 , V_13 , V_251 ) ;
return V_251 ;
}
int F_220 ( struct V_39 * V_80 , struct V_53 * V_152 ,
const struct V_389 * V_196 ,
struct V_391 * V_673 ,
struct V_390 * V_390 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_152 ) ,
F_387 ( V_80 , V_152 , V_196 , V_673 , V_390 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_388 ( struct V_53 * V_152 , const struct V_389 * V_196 , struct V_681 * V_682 )
{
int V_251 ;
struct V_683 args = {
. V_400 = F_83 ( V_152 ) ,
. V_196 = V_196 ,
} ;
struct V_684 V_33 = {
. V_682 = V_682 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_685 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
F_2 ( L_58 , V_196 -> V_196 ) ;
V_251 = F_68 ( F_77 ( V_152 ) -> V_80 , F_77 ( V_152 ) , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
F_2 ( L_59 , V_251 ) ;
return V_251 ;
}
int F_389 ( struct V_53 * V_152 , const struct V_389 * V_196 ,
struct V_681 * V_682 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_152 ) ,
F_388 ( V_152 , V_196 , V_682 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_390 ( T_3 V_177 )
{
if ( V_177 & ~ V_686 )
goto V_687;
if ( ( V_177 & V_688 ) &&
( V_177 & V_689 ) )
goto V_687;
if ( ! ( V_177 & ( V_690 ) ) )
goto V_687;
return V_115 ;
V_687:
return - V_691 ;
}
static bool
F_391 ( struct V_692 * V_693 ,
struct V_692 * V_694 )
{
if ( V_693 -> V_695 == V_694 -> V_695 &&
memcmp ( V_693 -> V_696 , V_694 -> V_696 , V_693 -> V_695 ) == 0 )
return true ;
return false ;
}
int F_392 ( struct V_31 * V_32 , struct V_261 * V_303 )
{
int V_251 ;
struct V_697 V_33 ;
struct V_139 V_140 = {
. V_256 =
& V_257 [ V_698 ] ,
. V_259 = V_32 ,
. V_260 = & V_33 ,
. V_261 = V_303 ,
} ;
F_2 ( L_17 , V_13 ) ;
F_4 ( V_32 == NULL ) ;
V_33 . V_126 = F_78 ( sizeof( struct V_102 ) , V_248 ) ;
if ( F_393 ( V_33 . V_126 == NULL ) ) {
V_251 = - V_240 ;
goto V_116;
}
V_251 = F_67 ( V_32 -> V_511 , & V_140 , V_583 ) ;
if ( V_251 == 0 ) {
if ( memcmp ( V_33 . V_126 -> V_699 . V_135 ,
V_32 -> V_73 -> V_699 . V_135 , V_700 ) ) {
F_2 ( L_60 , V_13 ) ;
V_251 = - V_14 ;
goto V_701;
}
if ( V_33 . V_152 != V_702 ) {
F_2 ( L_61 ,
V_13 ) ;
V_251 = - V_14 ;
goto V_701;
}
if ( V_33 . V_703 ) {
F_2 ( L_62 ,
V_13 ) ;
V_251 = - V_14 ;
goto V_701;
}
}
V_701:
F_86 ( V_33 . V_126 ) ;
V_116:
F_2 ( L_63 , V_13 , V_251 ) ;
return V_251 ;
}
int F_394 ( struct V_31 * V_32 , struct V_261 * V_303 )
{
T_11 V_16 ;
struct V_704 args = {
. V_16 = & V_16 ,
. V_80 = V_32 ,
. V_177 = V_705 ,
} ;
struct V_706 V_33 = {
0
} ;
int V_251 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_707 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
. V_261 = V_303 ,
} ;
F_333 ( V_32 , & V_16 ) ;
args . V_708 = F_336 ( args . V_192 , sizeof( args . V_192 ) ,
L_64 ,
V_32 -> V_572 ,
V_32 -> V_511 -> V_709 ) ;
F_2 ( L_65 ,
V_32 -> V_511 -> V_580 -> V_581 -> V_582 ,
args . V_708 , args . V_192 ) ;
V_33 . V_710 = F_78 ( sizeof( struct V_711 ) ,
V_248 ) ;
if ( F_393 ( V_33 . V_710 == NULL ) ) {
V_251 = - V_240 ;
goto V_116;
}
V_33 . V_696 = F_78 ( sizeof( struct V_692 ) ,
V_248 ) ;
if ( F_393 ( V_33 . V_696 == NULL ) ) {
V_251 = - V_240 ;
goto V_712;
}
V_33 . V_713 = F_78 ( sizeof( struct V_714 ) , V_248 ) ;
if ( F_393 ( V_33 . V_713 == NULL ) ) {
V_251 = - V_240 ;
goto V_715;
}
V_251 = F_67 ( V_32 -> V_511 , & V_140 , V_583 ) ;
if ( V_251 == 0 )
V_251 = F_390 ( V_33 . V_177 ) ;
if ( V_251 == 0 ) {
V_32 -> V_191 = V_33 . V_190 ;
V_32 -> V_716 = ( V_33 . V_177 & ~ V_717 ) ;
if ( ! ( V_33 . V_177 & V_717 ) )
V_32 -> V_718 = V_33 . V_168 ;
F_86 ( V_32 -> V_719 ) ;
V_32 -> V_719 = V_33 . V_710 ;
V_33 . V_710 = NULL ;
F_86 ( V_32 -> V_720 ) ;
V_32 -> V_720 = V_33 . V_713 ;
if ( V_32 -> V_721 != NULL &&
! F_391 ( V_32 -> V_721 ,
V_33 . V_696 ) ) {
F_2 ( L_66 ,
V_13 ) ;
F_106 ( V_722 , & V_32 -> V_34 ) ;
F_86 ( V_32 -> V_721 ) ;
V_32 -> V_721 = NULL ;
}
if ( V_32 -> V_721 == NULL ) {
V_32 -> V_721 = V_33 . V_696 ;
goto V_116;
}
} else
F_86 ( V_33 . V_713 ) ;
V_712:
F_86 ( V_33 . V_710 ) ;
V_715:
F_86 ( V_33 . V_696 ) ;
V_116:
if ( V_32 -> V_720 != NULL )
F_2 ( L_67
L_68 ,
V_32 -> V_720 -> V_723 , V_32 -> V_720 -> V_196 ,
V_32 -> V_720 -> V_724 . V_725 ,
V_32 -> V_720 -> V_724 . V_726 ) ;
F_2 ( L_69 , V_251 ) ;
return V_251 ;
}
static int F_395 ( struct V_31 * V_32 ,
struct V_261 * V_303 )
{
struct V_139 V_140 = {
. V_256 = & V_257 [ V_727 ] ,
. V_259 = V_32 ,
. V_261 = V_303 ,
} ;
int V_251 ;
V_251 = F_67 ( V_32 -> V_511 , & V_140 , V_583 ) ;
if ( V_251 )
F_2 ( L_70
L_71 , V_251 , V_32 -> V_86 ) ;
return V_251 ;
}
static int F_396 ( struct V_31 * V_32 ,
struct V_261 * V_303 )
{
unsigned int V_291 ;
int V_54 ;
for ( V_291 = V_292 ; V_291 != 0 ; V_291 -- ) {
V_54 = F_395 ( V_32 , V_303 ) ;
switch ( V_54 ) {
case - V_78 :
case - V_728 :
F_397 ( 1 ) ;
break;
default:
return V_54 ;
}
}
return 0 ;
}
int F_398 ( struct V_31 * V_32 )
{
struct V_261 * V_303 ;
int V_54 = 0 ;
if ( V_32 -> V_150 -> V_382 < 1 )
goto V_116;
if ( V_32 -> V_716 == 0 )
goto V_116;
V_303 = F_399 ( V_32 ) ;
V_54 = F_396 ( V_32 , V_303 ) ;
if ( V_303 )
F_400 ( V_303 ) ;
switch ( V_54 ) {
case 0 :
case - V_64 :
V_32 -> V_716 = 0 ;
}
V_116:
return V_54 ;
}
static void F_401 ( struct V_98 * V_99 ,
void * V_133 )
{
int V_54 ;
struct V_729 * V_135 =
(struct V_729 * ) V_133 ;
F_2 ( L_17 , V_13 ) ;
F_34 ( V_99 , V_101 ) ;
V_54 = F_50 ( V_135 -> V_32 -> V_73 ,
& V_135 -> args -> V_730 ,
& V_135 -> V_33 -> V_731 , V_99 ) ;
F_4 ( V_54 == - V_129 ) ;
F_57 ( V_99 ) ;
F_2 ( L_72 , V_13 ) ;
}
static void F_402 ( struct V_98 * V_99 , void * V_133 )
{
struct V_729 * V_135 =
(struct V_729 * ) V_133 ;
F_2 ( L_17 , V_13 ) ;
if ( ! F_41 ( V_99 , & V_135 -> V_33 -> V_731 ) )
return;
switch ( V_99 -> V_149 ) {
case - V_78 :
case - V_77 :
F_2 ( L_73 , V_13 , V_99 -> V_149 ) ;
F_44 ( V_99 , V_42 ) ;
V_99 -> V_149 = 0 ;
case - V_81 :
F_191 ( V_99 ) ;
return;
}
F_2 ( L_72 , V_13 ) ;
}
int F_403 ( struct V_31 * V_32 , struct V_369 * V_478 )
{
struct V_98 * V_99 ;
struct V_732 args ;
struct V_733 V_33 = {
. V_734 = V_478 ,
} ;
struct V_729 V_135 = {
. args = & args ,
. V_33 = & V_33 ,
. V_32 = V_32 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_735 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
struct V_142 V_143 = {
. V_144 = V_32 -> V_511 ,
. V_139 = & V_140 ,
. V_145 = & V_736 ,
. V_147 = & V_135 ,
. V_177 = V_583 ,
} ;
int V_251 ;
F_49 ( & args . V_730 , & V_33 . V_731 , 0 ) ;
F_2 ( L_17 , V_13 ) ;
V_99 = F_61 ( & V_143 ) ;
if ( F_62 ( V_99 ) )
V_251 = F_63 ( V_99 ) ;
else {
V_251 = V_99 -> V_149 ;
F_64 ( V_99 ) ;
}
F_2 ( L_74 , V_13 , V_251 ) ;
return V_251 ;
}
static struct V_127 * F_404 ( T_3 V_96 , T_5 V_737 )
{
return F_405 ( V_96 , sizeof( struct V_127 ) , V_737 ) ;
}
static void F_406 ( struct V_90 * V_91 ,
struct V_127 * V_738 ,
T_3 V_96 ,
T_3 V_739 )
{
struct V_127 * V_740 = NULL ;
T_3 V_377 ;
F_26 ( & V_91 -> V_112 ) ;
if ( V_738 ) {
V_740 = V_91 -> V_113 ;
V_91 -> V_113 = V_738 ;
V_91 -> V_96 = V_96 ;
}
V_91 -> V_95 = - 1 ;
for ( V_377 = 0 ; V_377 < V_91 -> V_96 ; V_377 ++ )
V_91 -> V_113 [ V_377 ] . V_117 = V_739 ;
F_28 ( & V_91 -> V_112 ) ;
F_86 ( V_740 ) ;
}
static int F_407 ( struct V_90 * V_91 , T_3 V_741 ,
T_3 V_739 )
{
struct V_127 * V_738 = NULL ;
int V_54 = - V_240 ;
F_2 ( L_75 , V_13 ,
V_741 , V_91 -> V_96 ) ;
if ( V_741 != V_91 -> V_96 ) {
V_738 = F_404 ( V_741 , V_248 ) ;
if ( ! V_738 )
goto V_116;
}
V_54 = 0 ;
F_406 ( V_91 , V_738 , V_741 , V_739 ) ;
F_2 ( L_76 , V_13 ,
V_91 , V_91 -> V_113 , V_91 -> V_96 ) ;
V_116:
F_2 ( L_77 , V_13 , V_54 ) ;
return V_54 ;
}
static void F_408 ( struct V_102 * V_126 )
{
if ( V_126 -> V_106 . V_113 != NULL ) {
F_86 ( V_126 -> V_106 . V_113 ) ;
V_126 -> V_106 . V_113 = NULL ;
}
if ( V_126 -> V_108 . V_113 != NULL ) {
F_86 ( V_126 -> V_108 . V_113 ) ;
V_126 -> V_108 . V_113 = NULL ;
}
return;
}
static int F_409 ( struct V_102 * V_103 )
{
struct V_90 * V_91 ;
int V_251 ;
F_2 ( L_17 , V_13 ) ;
V_91 = & V_103 -> V_106 ;
V_251 = F_407 ( V_91 , V_103 -> V_742 . V_741 , 1 ) ;
if ( V_251 )
return V_251 ;
V_91 = & V_103 -> V_108 ;
V_251 = F_407 ( V_91 , V_103 -> V_743 . V_741 , 0 ) ;
if ( V_251 && V_91 -> V_113 == NULL )
F_408 ( V_103 ) ;
return V_251 ;
}
struct V_102 * F_410 ( struct V_31 * V_32 )
{
struct V_102 * V_126 ;
struct V_90 * V_91 ;
V_126 = F_78 ( sizeof( struct V_102 ) , V_248 ) ;
if ( ! V_126 )
return NULL ;
V_91 = & V_126 -> V_106 ;
V_91 -> V_95 = V_97 ;
F_411 ( & V_91 -> V_112 ) ;
F_412 ( & V_91 -> V_107 , L_78 ) ;
F_413 ( & V_91 -> F_38 ) ;
V_91 = & V_126 -> V_108 ;
V_91 -> V_95 = V_97 ;
F_411 ( & V_91 -> V_112 ) ;
F_414 ( & V_91 -> V_107 , L_79 ) ;
F_413 ( & V_91 -> F_38 ) ;
V_126 -> V_105 = 1 << V_744 ;
V_126 -> V_32 = V_32 ;
return V_126 ;
}
void F_415 ( struct V_102 * V_126 )
{
struct V_745 * V_746 ;
struct V_261 * V_303 ;
V_303 = F_399 ( V_126 -> V_32 ) ;
F_416 ( V_126 , V_303 ) ;
if ( V_303 )
F_400 ( V_303 ) ;
F_112 () ;
V_746 = F_113 ( V_126 -> V_32 -> V_511 -> V_747 ) ;
F_115 () ;
F_2 ( L_80 ,
V_13 , V_746 ) ;
F_417 ( V_746 , V_748 ) ;
F_408 ( V_126 ) ;
F_86 ( V_126 ) ;
}
static void F_418 ( struct V_749 * args )
{
struct V_102 * V_126 = args -> V_80 -> V_73 ;
unsigned int V_750 = V_126 -> V_742 . V_751 ,
V_752 = V_126 -> V_742 . V_753 ;
if ( V_750 == 0 )
V_750 = V_754 ;
if ( V_752 == 0 )
V_752 = V_754 ;
args -> V_742 . V_751 = V_750 ;
args -> V_742 . V_753 = V_752 ;
args -> V_742 . V_755 = V_756 ;
args -> V_742 . V_741 = V_757 ;
F_2 ( L_81
L_82 ,
V_13 ,
args -> V_742 . V_751 , args -> V_742 . V_753 ,
args -> V_742 . V_755 , args -> V_742 . V_741 ) ;
args -> V_743 . V_751 = V_522 ;
args -> V_743 . V_753 = V_522 ;
args -> V_743 . V_758 = 0 ;
args -> V_743 . V_755 = V_759 ;
args -> V_743 . V_741 = 1 ;
F_2 ( L_83
L_84 ,
V_13 ,
args -> V_743 . V_751 , args -> V_743 . V_753 ,
args -> V_743 . V_758 , args -> V_743 . V_755 ,
args -> V_743 . V_741 ) ;
}
static int F_419 ( struct V_749 * args , struct V_102 * V_126 )
{
struct V_760 * V_761 = & args -> V_742 ;
struct V_760 * V_762 = & V_126 -> V_742 ;
if ( V_762 -> V_753 > V_761 -> V_753 )
return - V_8 ;
if ( V_762 -> V_755 < V_761 -> V_755 )
return - V_8 ;
if ( V_762 -> V_741 == 0 )
return - V_8 ;
if ( V_762 -> V_741 > V_93 )
V_762 -> V_741 = V_93 ;
return 0 ;
}
static int F_420 ( struct V_749 * args , struct V_102 * V_126 )
{
struct V_760 * V_761 = & args -> V_743 ;
struct V_760 * V_762 = & V_126 -> V_743 ;
if ( V_762 -> V_751 > V_761 -> V_751 )
return - V_8 ;
if ( V_762 -> V_753 < V_761 -> V_753 )
return - V_8 ;
if ( V_762 -> V_758 > V_761 -> V_758 )
return - V_8 ;
if ( V_762 -> V_755 != V_761 -> V_755 )
return - V_8 ;
if ( V_762 -> V_741 != V_761 -> V_741 )
return - V_8 ;
return 0 ;
}
static int F_421 ( struct V_749 * args ,
struct V_102 * V_126 )
{
int V_54 ;
V_54 = F_419 ( args , V_126 ) ;
if ( V_54 )
return V_54 ;
return F_420 ( args , V_126 ) ;
}
static int F_422 ( struct V_31 * V_32 ,
struct V_261 * V_303 )
{
struct V_102 * V_126 = V_32 -> V_73 ;
struct V_749 args = {
. V_80 = V_32 ,
. V_763 = V_764 ,
} ;
struct V_765 V_33 = {
. V_80 = V_32 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_766 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
. V_261 = V_303 ,
} ;
int V_251 ;
F_418 ( & args ) ;
args . V_177 = ( V_767 | V_768 ) ;
V_251 = F_67 ( V_126 -> V_32 -> V_511 , & V_140 , V_583 ) ;
if ( ! V_251 )
V_251 = F_421 ( & args , V_126 ) ;
if ( ! V_251 ) {
V_32 -> V_718 ++ ;
}
return V_251 ;
}
int F_423 ( struct V_31 * V_32 , struct V_261 * V_303 )
{
int V_251 ;
unsigned * V_769 ;
struct V_102 * V_126 = V_32 -> V_73 ;
F_2 ( L_85 , V_13 , V_32 , V_126 ) ;
V_251 = F_422 ( V_32 , V_303 ) ;
if ( V_251 )
goto V_116;
V_251 = F_409 ( V_126 ) ;
F_2 ( L_86 , V_251 ) ;
if ( V_251 )
goto V_116;
V_769 = ( unsigned * ) & V_126 -> V_699 . V_135 [ 0 ] ;
F_2 ( L_87 , V_13 ,
V_32 -> V_718 , V_769 [ 0 ] , V_769 [ 1 ] , V_769 [ 2 ] , V_769 [ 3 ] ) ;
V_116:
F_2 ( L_72 , V_13 ) ;
return V_251 ;
}
int F_416 ( struct V_102 * V_126 ,
struct V_261 * V_303 )
{
struct V_139 V_140 = {
. V_256 = & V_257 [ V_770 ] ,
. V_259 = V_126 ,
. V_261 = V_303 ,
} ;
int V_251 = 0 ;
F_2 ( L_88 ) ;
if ( V_126 -> V_32 -> V_38 != V_771 )
return V_251 ;
V_251 = F_67 ( V_126 -> V_32 -> V_511 , & V_140 , V_583 ) ;
if ( V_251 )
F_2 ( L_89
L_90 , V_251 ) ;
F_2 ( L_91 ) ;
return V_251 ;
}
static int F_424 ( struct V_31 * V_32 )
{
int V_54 ;
if ( V_32 -> V_38 == V_772 ) {
V_54 = F_160 ( V_32 ) ;
if ( V_54 )
return V_54 ;
}
if ( V_32 -> V_38 < V_771 )
return - V_12 ;
F_136 () ;
return 0 ;
}
int F_425 ( struct V_46 * V_47 )
{
struct V_31 * V_32 = V_47 -> V_31 ;
struct V_102 * V_126 ;
unsigned int V_773 , V_774 ;
if ( ! F_426 ( V_32 ) )
return 0 ;
V_126 = V_32 -> V_73 ;
F_26 ( & V_32 -> V_88 ) ;
if ( F_427 ( V_744 , & V_126 -> V_105 ) ) {
V_773 = V_47 -> V_773 ;
if ( V_773 == 0 )
V_773 = V_754 ;
V_774 = V_47 -> V_774 ;
if ( V_774 == 0 )
V_774 = V_754 ;
V_126 -> V_742 . V_751 = V_774 + V_775 ;
V_126 -> V_742 . V_753 = V_773 + V_776 ;
}
F_28 ( & V_32 -> V_88 ) ;
return F_424 ( V_32 ) ;
}
int F_428 ( struct V_31 * V_32 , unsigned long V_586 )
{
struct V_102 * V_126 = V_32 -> V_73 ;
int V_54 ;
F_26 ( & V_32 -> V_88 ) ;
if ( F_427 ( V_744 , & V_126 -> V_105 ) ) {
V_32 -> V_585 = V_586 ;
V_32 -> V_89 = V_132 ;
}
F_28 ( & V_32 -> V_88 ) ;
V_54 = F_424 ( V_32 ) ;
if ( V_54 )
return V_54 ;
if ( ! F_429 ( V_32 ) )
return - V_777 ;
return 0 ;
}
static void F_430 ( void * V_135 )
{
struct V_778 * V_133 = V_135 ;
struct V_31 * V_32 = V_133 -> V_32 ;
if ( F_303 ( & V_32 -> V_505 ) > 1 )
F_304 ( V_32 ) ;
F_305 ( V_32 ) ;
F_86 ( V_133 ) ;
}
static int F_431 ( struct V_98 * V_99 , struct V_31 * V_32 )
{
switch( V_99 -> V_149 ) {
case - V_78 :
F_44 ( V_99 , V_43 ) ;
return - V_129 ;
default:
F_21 ( V_32 ) ;
}
return 0 ;
}
static void F_432 ( struct V_98 * V_99 , void * V_135 )
{
struct V_778 * V_133 = V_135 ;
struct V_31 * V_32 = V_133 -> V_32 ;
if ( ! F_41 ( V_99 , V_99 -> V_270 . V_260 ) )
return;
if ( V_99 -> V_149 < 0 ) {
F_2 ( L_92 , V_13 , V_99 -> V_149 ) ;
if ( F_303 ( & V_32 -> V_505 ) == 1 )
goto V_116;
if ( F_431 ( V_99 , V_32 ) == - V_129 ) {
F_191 ( V_99 ) ;
return;
}
}
F_2 ( L_93 , V_13 , V_99 -> V_270 . V_261 ) ;
V_116:
F_2 ( L_72 , V_13 ) ;
}
static void F_433 ( struct V_98 * V_99 , void * V_135 )
{
struct V_778 * V_133 = V_135 ;
struct V_31 * V_32 = V_133 -> V_32 ;
struct V_122 * args ;
struct V_109 * V_33 ;
args = V_99 -> V_270 . V_259 ;
V_33 = V_99 -> V_270 . V_260 ;
if ( F_50 ( V_32 -> V_73 , args , V_33 , V_99 ) )
return;
F_57 ( V_99 ) ;
}
static struct V_98 * F_434 ( struct V_31 * V_32 , struct V_261 * V_303 )
{
struct V_778 * V_133 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_779 ] ,
. V_261 = V_303 ,
} ;
struct V_142 V_262 = {
. V_144 = V_32 -> V_511 ,
. V_139 = & V_140 ,
. V_145 = & V_780 ,
. V_177 = V_266 | V_512 ,
} ;
if ( ! F_309 ( & V_32 -> V_505 ) )
return F_119 ( - V_14 ) ;
V_133 = F_78 ( sizeof( * V_133 ) , V_248 ) ;
if ( V_133 == NULL ) {
F_305 ( V_32 ) ;
return F_119 ( - V_240 ) ;
}
F_49 ( & V_133 -> args , & V_133 -> V_33 , 0 ) ;
V_140 . V_259 = & V_133 -> args ;
V_140 . V_260 = & V_133 -> V_33 ;
V_133 -> V_32 = V_32 ;
V_262 . V_147 = V_133 ;
return F_61 ( & V_262 ) ;
}
static int F_435 ( struct V_31 * V_32 , struct V_261 * V_303 , unsigned V_509 )
{
struct V_98 * V_99 ;
int V_54 = 0 ;
if ( ( V_509 & V_781 ) == 0 )
return 0 ;
V_99 = F_434 ( V_32 , V_303 ) ;
if ( F_62 ( V_99 ) )
V_54 = F_63 ( V_99 ) ;
else
F_366 ( V_99 ) ;
F_2 ( L_23 , V_13 , V_54 ) ;
return V_54 ;
}
static int F_436 ( struct V_31 * V_32 , struct V_261 * V_303 )
{
struct V_98 * V_99 ;
int V_54 ;
V_99 = F_434 ( V_32 , V_303 ) ;
if ( F_62 ( V_99 ) ) {
V_54 = F_63 ( V_99 ) ;
goto V_116;
}
V_54 = F_98 ( V_99 ) ;
if ( ! V_54 ) {
struct V_109 * V_33 = V_99 -> V_270 . V_260 ;
if ( V_99 -> V_149 == 0 )
F_437 ( V_32 , V_33 -> V_119 ) ;
V_54 = V_99 -> V_149 ;
}
F_64 ( V_99 ) ;
V_116:
F_2 ( L_23 , V_13 , V_54 ) ;
return V_54 ;
}
static void F_438 ( struct V_98 * V_99 , void * V_135 )
{
struct V_782 * V_133 = V_135 ;
F_34 ( V_99 , V_101 ) ;
if ( F_50 ( V_133 -> V_32 -> V_73 ,
& V_133 -> V_318 . V_137 ,
& V_133 -> V_33 . V_138 , V_99 ) )
return;
F_57 ( V_99 ) ;
}
static int F_439 ( struct V_98 * V_99 , struct V_31 * V_32 )
{
switch( V_99 -> V_149 ) {
case 0 :
case - V_783 :
case - V_784 :
break;
case - V_78 :
F_44 ( V_99 , V_43 ) ;
case - V_81 :
return - V_129 ;
default:
F_21 ( V_32 ) ;
}
return 0 ;
}
static void F_440 ( struct V_98 * V_99 , void * V_135 )
{
struct V_782 * V_133 = V_135 ;
struct V_31 * V_32 = V_133 -> V_32 ;
struct V_109 * V_33 = & V_133 -> V_33 . V_138 ;
F_2 ( L_17 , V_13 ) ;
if ( ! F_41 ( V_99 , V_33 ) )
return;
if ( F_439 ( V_99 , V_32 ) == - V_129 ) {
F_191 ( V_99 ) ;
return;
}
F_2 ( L_72 , V_13 ) ;
}
static void F_441 ( void * V_135 )
{
struct V_782 * V_133 = V_135 ;
F_86 ( V_133 ) ;
}
static int F_442 ( struct V_31 * V_32 )
{
struct V_782 * V_133 ;
struct V_98 * V_99 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_785 ] ,
} ;
struct V_142 V_262 = {
. V_144 = V_32 -> V_511 ,
. V_139 = & V_140 ,
. V_145 = & V_786 ,
. V_177 = V_266 ,
} ;
int V_251 = - V_240 ;
F_2 ( L_17 , V_13 ) ;
V_133 = F_78 ( sizeof( * V_133 ) , V_248 ) ;
if ( V_133 == NULL )
goto V_116;
V_133 -> V_32 = V_32 ;
V_133 -> V_318 . V_787 = 0 ;
F_49 ( & V_133 -> V_318 . V_137 , & V_133 -> V_33 . V_138 , 0 ) ;
V_140 . V_259 = & V_133 -> V_318 ;
V_140 . V_260 = & V_133 -> V_33 ;
V_262 . V_147 = V_133 ;
V_99 = F_61 ( & V_262 ) ;
if ( F_62 ( V_99 ) ) {
V_251 = F_63 ( V_99 ) ;
goto V_116;
}
V_251 = F_97 ( V_99 ) ;
if ( V_251 == 0 )
V_251 = V_99 -> V_149 ;
F_64 ( V_99 ) ;
return 0 ;
V_116:
F_2 ( L_23 , V_13 , V_251 ) ;
return V_251 ;
}
static void
F_443 ( struct V_98 * V_99 , void * V_133 )
{
struct V_788 * V_789 = V_133 ;
struct V_46 * V_47 = F_77 ( V_789 -> args . V_53 ) ;
F_2 ( L_17 , V_13 ) ;
if ( F_54 ( V_47 , & V_789 -> args . V_137 ,
& V_789 -> V_33 . V_138 , V_99 ) )
return;
if ( F_444 ( & V_789 -> args . V_208 ,
F_70 ( V_789 -> args . V_53 ) -> V_790 ,
V_789 -> args . V_246 -> V_52 ) ) {
F_445 ( V_99 , V_791 ) ;
return;
}
F_57 ( V_99 ) ;
}
static void F_446 ( struct V_98 * V_99 , void * V_133 )
{
struct V_788 * V_789 = V_133 ;
struct V_46 * V_47 = F_77 ( V_789 -> args . V_53 ) ;
F_2 ( L_17 , V_13 ) ;
if ( ! F_45 ( V_99 , & V_789 -> V_33 . V_138 ) )
return;
switch ( V_99 -> V_149 ) {
case 0 :
break;
case - V_792 :
case - V_793 :
V_99 -> V_149 = - V_78 ;
default:
if ( F_190 ( V_99 , V_47 , NULL ) == - V_129 ) {
F_191 ( V_99 ) ;
return;
}
}
F_2 ( L_72 , V_13 ) ;
}
static T_9 F_447 ( struct V_46 * V_47 )
{
T_3 V_753 = V_47 -> V_31 -> V_73 -> V_742 . V_753 ;
return F_448 ( 0 , V_753 ) ;
}
static void F_449 ( struct V_390 * * V_23 , T_9 V_794 )
{
int V_377 ;
if ( ! V_23 )
return;
for ( V_377 = 0 ; V_377 < V_794 ; V_377 ++ ) {
if ( ! V_23 [ V_377 ] )
break;
F_222 ( V_23 [ V_377 ] ) ;
}
F_86 ( V_23 ) ;
}
static struct V_390 * * F_450 ( T_9 V_794 , T_5 V_737 )
{
struct V_390 * * V_23 ;
int V_377 ;
V_23 = F_405 ( V_794 , sizeof( struct V_390 * ) , V_737 ) ;
if ( ! V_23 ) {
F_2 ( L_94 , V_13 , V_794 ) ;
return NULL ;
}
for ( V_377 = 0 ; V_377 < V_794 ; V_377 ++ ) {
V_23 [ V_377 ] = F_218 ( V_737 ) ;
if ( ! V_23 [ V_377 ] ) {
F_2 ( L_95 , V_13 ) ;
F_449 ( V_23 , V_794 ) ;
return NULL ;
}
}
return V_23 ;
}
static void F_451 ( void * V_133 )
{
struct V_788 * V_789 = V_133 ;
struct V_46 * V_47 = F_77 ( V_789 -> args . V_53 ) ;
T_9 V_795 = F_447 ( V_47 ) ;
F_2 ( L_17 , V_13 ) ;
F_449 ( V_789 -> args . V_790 . V_23 , V_795 ) ;
F_140 ( V_789 -> args . V_246 ) ;
F_86 ( V_133 ) ;
F_2 ( L_72 , V_13 ) ;
}
void F_452 ( struct V_788 * V_789 , T_5 V_737 )
{
struct V_46 * V_47 = F_77 ( V_789 -> args . V_53 ) ;
T_9 V_795 = F_447 ( V_47 ) ;
struct V_98 * V_99 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_796 ] ,
. V_259 = & V_789 -> args ,
. V_260 = & V_789 -> V_33 ,
} ;
struct V_142 V_262 = {
. V_144 = V_47 -> V_80 ,
. V_139 = & V_140 ,
. V_145 = & V_797 ,
. V_147 = V_789 ,
. V_177 = V_266 ,
} ;
int V_251 = 0 ;
F_2 ( L_17 , V_13 ) ;
V_789 -> args . V_790 . V_23 = F_450 ( V_795 , V_737 ) ;
if ( ! V_789 -> args . V_790 . V_23 ) {
F_451 ( V_789 ) ;
return;
}
V_789 -> args . V_790 . V_427 = V_795 * V_522 ;
V_789 -> V_33 . V_798 = & V_789 -> args . V_790 ;
V_789 -> V_33 . V_138 . V_111 = NULL ;
F_49 ( & V_789 -> args . V_137 , & V_789 -> V_33 . V_138 , 0 ) ;
V_99 = F_61 ( & V_262 ) ;
if ( F_62 ( V_99 ) )
return;
V_251 = F_97 ( V_99 ) ;
if ( V_251 == 0 )
V_251 = V_99 -> V_149 ;
if ( V_251 == 0 )
V_251 = F_453 ( V_789 ) ;
F_64 ( V_99 ) ;
F_2 ( L_23 , V_13 , V_251 ) ;
return;
}
static void
F_454 ( struct V_98 * V_99 , void * V_133 )
{
struct V_799 * V_800 = V_133 ;
F_2 ( L_17 , V_13 ) ;
if ( F_50 ( V_800 -> V_32 -> V_73 , & V_800 -> args . V_137 ,
& V_800 -> V_33 . V_138 , V_99 ) )
return;
F_57 ( V_99 ) ;
}
static void F_455 ( struct V_98 * V_99 , void * V_133 )
{
struct V_799 * V_800 = V_133 ;
struct V_46 * V_47 ;
struct V_801 * V_802 = V_800 -> args . V_790 ;
F_2 ( L_17 , V_13 ) ;
if ( ! F_45 ( V_99 , & V_800 -> V_33 . V_138 ) )
return;
V_47 = F_77 ( V_800 -> args . V_53 ) ;
if ( F_190 ( V_99 , V_47 , NULL ) == - V_129 ) {
F_191 ( V_99 ) ;
return;
}
F_26 ( & V_802 -> V_803 -> V_157 ) ;
if ( V_99 -> V_149 == 0 && V_800 -> V_33 . V_804 )
F_456 ( V_802 , & V_800 -> V_33 . V_208 , true ) ;
V_802 -> V_805 -- ;
F_28 ( & V_802 -> V_803 -> V_157 ) ;
F_2 ( L_72 , V_13 ) ;
}
static void F_457 ( void * V_133 )
{
struct V_799 * V_800 = V_133 ;
F_2 ( L_17 , V_13 ) ;
F_458 ( V_800 -> args . V_790 ) ;
F_86 ( V_133 ) ;
F_2 ( L_72 , V_13 ) ;
}
int F_459 ( struct V_799 * V_800 )
{
struct V_98 * V_99 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_806 ] ,
. V_259 = & V_800 -> args ,
. V_260 = & V_800 -> V_33 ,
} ;
struct V_142 V_262 = {
. V_144 = V_800 -> V_32 -> V_511 ,
. V_139 = & V_140 ,
. V_145 = & V_807 ,
. V_147 = V_800 ,
} ;
int V_251 ;
F_2 ( L_17 , V_13 ) ;
F_49 ( & V_800 -> args . V_137 , & V_800 -> V_33 . V_138 , 1 ) ;
V_99 = F_61 ( & V_262 ) ;
if ( F_62 ( V_99 ) )
return F_63 ( V_99 ) ;
V_251 = V_99 -> V_149 ;
F_2 ( L_23 , V_13 , V_251 ) ;
F_64 ( V_99 ) ;
return V_251 ;
}
static int F_460 ( struct V_46 * V_47 ,
const struct V_341 * V_187 ,
struct V_808 * V_809 )
{
struct V_810 args = {
. V_187 = V_187 ,
. V_811 = V_47 -> V_812 -> V_192 ,
} ;
struct V_813 V_33 = {
. V_809 = V_809 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_814 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
int V_251 ;
F_2 ( L_17 , V_13 ) ;
V_251 = F_68 ( V_47 -> V_80 , V_47 , & V_140 , & args . V_137 ,
& V_33 . V_138 , 0 ) ;
F_2 ( L_23 , V_13 , V_251 ) ;
return V_251 ;
}
int F_461 ( struct V_46 * V_47 ,
const struct V_341 * V_187 ,
struct V_808 * V_809 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_47 ,
F_460 ( V_47 , V_187 , V_809 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
F_2 ( L_96 , V_13 ,
V_1 , V_809 -> V_815 ) ;
return V_1 ;
}
static int
F_462 ( struct V_46 * V_47 , struct V_816 * V_817 )
{
struct V_818 args = {
. V_817 = V_817 ,
} ;
struct V_819 V_33 = {
. V_817 = V_817 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_820 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
int V_251 ;
F_2 ( L_17 , V_13 ) ;
V_251 = F_68 ( V_47 -> V_80 , V_47 , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
F_2 ( L_23 , V_13 , V_251 ) ;
return V_251 ;
}
int F_463 ( struct V_46 * V_47 , struct V_816 * V_817 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_47 ,
F_462 ( V_47 , V_817 ) ,
& V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static void F_464 ( struct V_98 * V_99 , void * V_133 )
{
struct V_821 * V_135 = V_133 ;
struct V_46 * V_47 = F_77 ( V_135 -> args . V_53 ) ;
if ( F_54 ( V_47 , & V_135 -> args . V_137 ,
& V_135 -> V_33 . V_138 , V_99 ) )
return;
F_57 ( V_99 ) ;
}
static void
F_465 ( struct V_98 * V_99 , void * V_133 )
{
struct V_821 * V_135 = V_133 ;
struct V_46 * V_47 = F_77 ( V_135 -> args . V_53 ) ;
if ( ! F_45 ( V_99 , & V_135 -> V_33 . V_138 ) )
return;
switch ( V_99 -> V_149 ) {
case - V_59 :
case - V_822 :
case - V_823 :
case - V_77 :
V_99 -> V_149 = 0 ;
break;
case 0 :
F_293 ( V_135 -> args . V_53 ,
V_135 -> V_33 . V_316 ) ;
break;
default:
if ( F_190 ( V_99 , V_47 , NULL ) == - V_129 ) {
F_191 ( V_99 ) ;
return;
}
}
}
static void F_466 ( void * V_133 )
{
struct V_821 * V_135 = V_133 ;
struct V_824 * V_825 , * V_826 ;
unsigned long * V_827 = & F_70 ( V_135 -> args . V_53 ) -> V_177 ;
F_467 ( V_135 ) ;
F_468 (lseg, tmp, &data->lseg_list, pls_lc_list) {
F_469 ( & V_825 -> V_828 ) ;
if ( F_427 ( V_829 ,
& V_825 -> V_830 ) )
F_470 ( V_825 ) ;
}
F_471 ( V_831 , V_827 ) ;
F_472 () ;
F_473 ( V_827 , V_831 ) ;
F_400 ( V_135 -> V_303 ) ;
F_86 ( V_135 ) ;
}
int
F_474 ( struct V_821 * V_135 , bool V_832 )
{
struct V_139 V_140 = {
. V_256 = & V_257 [ V_833 ] ,
. V_259 = & V_135 -> args ,
. V_260 = & V_135 -> V_33 ,
. V_261 = V_135 -> V_303 ,
} ;
struct V_142 V_262 = {
. V_99 = & V_135 -> V_99 ,
. V_144 = F_233 ( V_135 -> args . V_53 ) ,
. V_139 = & V_140 ,
. V_145 = & V_834 ,
. V_147 = V_135 ,
. V_177 = V_266 ,
} ;
struct V_98 * V_99 ;
int V_251 = 0 ;
F_2 ( L_97
L_98 ,
V_135 -> V_99 . V_835 , V_832 ,
V_135 -> args . V_836 ,
V_135 -> args . V_53 -> V_837 ) ;
F_49 ( & V_135 -> args . V_137 , & V_135 -> V_33 . V_138 , 1 ) ;
V_99 = F_61 ( & V_262 ) ;
if ( F_62 ( V_99 ) )
return F_63 ( V_99 ) ;
if ( V_832 == false )
goto V_116;
V_251 = F_97 ( V_99 ) ;
if ( V_251 != 0 )
goto V_116;
V_251 = V_99 -> V_149 ;
V_116:
F_2 ( L_99 , V_13 , V_251 ) ;
F_64 ( V_99 ) ;
return V_251 ;
}
static int
F_475 ( struct V_46 * V_47 , struct V_341 * V_342 ,
struct V_369 * V_370 , struct V_681 * V_682 )
{
struct V_838 args = {
. V_839 = V_840 ,
} ;
struct V_684 V_33 = {
. V_682 = V_682 ,
} ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_841 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
return F_68 ( V_47 -> V_80 , V_47 , & V_140 , & args . V_137 , & V_33 . V_138 , 0 ) ;
}
static int
F_476 ( struct V_46 * V_47 , struct V_341 * V_342 ,
struct V_369 * V_370 , struct V_681 * V_682 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_475 ( V_47 , V_342 , V_370 , V_682 ) ;
switch ( V_1 ) {
case 0 :
case - V_4 :
case - V_842 :
goto V_116;
default:
V_1 = F_16 ( V_47 , V_1 , & V_50 ) ;
}
} while ( V_50 . V_55 );
V_116:
return V_1 ;
}
static int
F_477 ( struct V_46 * V_47 , struct V_341 * V_342 ,
struct V_369 * V_370 )
{
int V_1 ;
struct V_390 * V_390 ;
T_7 V_374 ;
struct V_681 * V_682 ;
V_390 = F_218 ( V_306 ) ;
if ( ! V_390 ) {
V_1 = - V_240 ;
goto V_116;
}
V_682 = F_315 ( V_390 ) ;
V_1 = F_476 ( V_47 , V_342 , V_370 , V_682 ) ;
if ( V_1 == - V_4 || V_1 == - V_842 ) {
V_1 = F_208 ( V_47 , V_342 , V_370 ) ;
goto V_843;
}
if ( V_1 )
goto V_843;
V_374 = F_478 ( V_682 ) ;
if ( V_1 == 0 )
V_1 = F_206 ( V_47 , V_342 , V_370 , V_374 ) ;
V_843:
F_328 ( V_390 ) ;
if ( V_1 == - V_10 )
return - V_5 ;
V_116:
return V_1 ;
}
static int F_479 ( struct V_46 * V_47 , T_6 * V_208 )
{
int V_251 ;
struct V_844 args = {
. V_208 = V_208 ,
} ;
struct V_845 V_33 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_846 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
F_2 ( L_100 , V_208 ) ;
F_49 ( & args . V_137 , & V_33 . V_138 , 0 ) ;
V_251 = F_60 ( V_47 -> V_80 , V_47 , & V_140 , & args . V_137 , & V_33 . V_138 , 1 ) ;
if ( V_251 != V_115 ) {
F_2 ( L_101 , V_251 ) ;
return V_251 ;
}
F_2 ( L_102 , - V_33 . V_251 ) ;
return - V_33 . V_251 ;
}
static int F_168 ( struct V_46 * V_47 , T_6 * V_208 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_479 ( V_47 , V_208 ) ;
if ( V_1 != - V_78 )
break;
F_16 ( V_47 , V_1 , & V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static int F_480 ( struct V_46 * V_47 , T_6 * V_208 )
{
struct V_847 args = {
. V_208 = V_208 ,
} ;
struct V_848 V_33 ;
struct V_139 V_140 = {
. V_256 = & V_257 [ V_849 ] ,
. V_259 = & args ,
. V_260 = & V_33 ,
} ;
int V_251 ;
F_2 ( L_103 , V_208 ) ;
F_49 ( & args . V_137 , & V_33 . V_138 , 0 ) ;
V_251 = F_60 ( V_47 -> V_80 , V_47 , & V_140 ,
& args . V_137 , & V_33 . V_138 , 1 ) ;
F_2 ( L_104 , V_251 ) ;
return V_251 ;
}
static int F_169 ( struct V_46 * V_47 , T_6 * V_208 )
{
struct V_49 V_50 = { } ;
int V_1 ;
do {
V_1 = F_480 ( V_47 , V_208 ) ;
if ( V_1 != - V_78 )
break;
F_16 ( V_47 , V_1 , & V_50 ) ;
} while ( V_50 . V_55 );
return V_1 ;
}
static bool F_481 ( const T_6 * V_850 ,
const T_6 * V_851 )
{
if ( memcmp ( V_850 -> V_852 , V_851 -> V_852 , sizeof( V_850 -> V_852 ) ) != 0 )
return false ;
if ( V_850 -> V_168 == V_851 -> V_168 )
return true ;
if ( V_850 -> V_168 == 0 || V_851 -> V_168 == 0 )
return true ;
return false ;
}
static bool F_482 ( const T_6 * V_850 ,
const T_6 * V_851 )
{
return F_114 ( V_850 , V_851 ) ;
}
