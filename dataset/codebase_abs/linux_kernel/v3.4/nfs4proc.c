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
default:
F_2 ( L_1 ,
V_9 , - V_1 ) ;
break;
}
return - V_10 ;
}
static void F_3 ( T_1 V_11 , T_2 * V_12 , struct V_13 * V_13 ,
struct V_14 * V_15 )
{
T_2 * V_16 , * V_17 ;
F_4 ( V_15 -> V_18 < 80 ) ;
if ( V_11 > 2 ) {
V_15 -> V_11 = V_11 ;
memcpy ( & V_15 -> V_12 , V_12 , sizeof( V_15 -> V_12 ) ) ;
return;
}
V_15 -> V_11 = 0 ;
memset ( & V_15 -> V_12 , 0 , sizeof( V_15 -> V_12 ) ) ;
if ( V_11 == 2 )
return;
V_16 = V_17 = F_5 ( * V_15 -> V_19 ) ;
if ( V_11 == 0 ) {
* V_17 ++ = V_20 ;
* V_17 ++ = V_21 ;
* V_17 ++ = V_20 ;
* V_17 ++ = V_20 ;
memcpy ( V_17 , L_2 , 4 ) ;
V_17 ++ ;
* V_17 ++ = V_20 ;
* V_17 ++ = F_6 ( V_22 ) ;
* V_17 ++ = F_6 ( 8 ) ;
V_17 = F_7 ( V_17 , F_8 ( V_13 -> V_23 ) ) ;
}
* V_17 ++ = V_20 ;
* V_17 ++ = V_21 ;
* V_17 ++ = V_24 ;
* V_17 ++ = V_24 ;
memcpy ( V_17 , L_3 , 4 ) ;
V_17 ++ ;
* V_17 ++ = V_20 ;
* V_17 ++ = F_6 ( V_22 ) ;
* V_17 ++ = F_6 ( 8 ) ;
V_17 = F_7 ( V_17 , F_8 ( V_13 -> V_25 -> V_23 ) ) ;
V_15 -> V_26 = ( char * ) V_17 - ( char * ) V_16 ;
V_15 -> V_18 -= V_15 -> V_26 ;
F_9 ( V_16 ) ;
}
static int F_10 ( struct V_27 * V_28 )
{
int V_29 ;
F_11 () ;
V_29 = F_12 ( & V_28 -> V_30 , V_31 ,
V_32 , V_33 ) ;
return V_29 ;
}
static int F_13 ( struct V_34 * V_35 , long * V_36 )
{
int V_29 = 0 ;
F_11 () ;
if ( * V_36 <= 0 )
* V_36 = V_37 ;
if ( * V_36 > V_38 )
* V_36 = V_38 ;
F_14 ( * V_36 ) ;
if ( F_15 ( V_39 ) )
V_29 = - V_40 ;
* V_36 <<= 1 ;
return V_29 ;
}
static int F_16 ( struct V_41 * V_42 , int V_43 , struct V_44 * V_45 )
{
struct V_27 * V_28 = V_42 -> V_27 ;
struct V_46 * V_47 = V_45 -> V_47 ;
struct V_48 * V_48 = V_45 -> V_48 ;
int V_49 = V_43 ;
V_45 -> V_50 = 0 ;
switch( V_43 ) {
case 0 :
return 0 ;
case - V_51 :
if ( V_48 && F_17 ( V_48 , V_52 ) ) {
F_18 ( V_48 ) ;
V_45 -> V_50 = 1 ;
return 0 ;
}
if ( V_47 == NULL )
break;
F_19 ( V_42 , V_47 ) ;
goto V_53;
case - V_54 :
case - V_55 :
case - V_56 :
if ( V_47 == NULL )
break;
F_20 ( V_47 -> V_48 ) ;
F_19 ( V_42 , V_47 ) ;
goto V_53;
case - V_57 :
if ( V_47 != NULL )
F_19 ( V_42 , V_47 ) ;
case - V_58 :
case - V_59 :
F_21 ( V_28 ) ;
goto V_53;
#if F_22 ( V_60 )
case - V_61 :
case - V_62 :
case - V_63 :
case - V_64 :
case - V_65 :
case - V_66 :
case - V_67 :
F_2 ( L_4 , V_9 ,
V_43 ) ;
F_23 ( V_28 -> V_68 ) ;
V_45 -> V_50 = 1 ;
break;
#endif
case - V_69 :
if ( V_45 -> V_36 > V_70 ) {
V_49 = - V_71 ;
break;
}
case - V_72 :
case - V_73 :
case - V_74 :
V_49 = F_13 ( V_42 -> V_75 , & V_45 -> V_36 ) ;
if ( V_49 != 0 )
break;
case - V_76 :
case - V_77 :
V_45 -> V_50 = 1 ;
break;
case - V_6 :
case - V_7 :
if ( V_42 -> V_78 & V_79 ) {
V_42 -> V_78 &= ~ V_79 ;
V_45 -> V_50 = 1 ;
F_24 ( V_80 L_5
L_6
L_7
L_8 ,
V_42 -> V_27 -> V_81 ) ;
}
}
return F_1 ( V_49 ) ;
V_53:
V_49 = F_10 ( V_28 ) ;
if ( V_49 == 0 )
V_45 -> V_50 = 1 ;
return V_49 ;
}
static void F_25 ( struct V_27 * V_28 , unsigned long V_82 )
{
F_26 ( & V_28 -> V_83 ) ;
if ( F_27 ( V_28 -> V_84 , V_82 ) )
V_28 -> V_84 = V_82 ;
F_28 ( & V_28 -> V_83 ) ;
}
static void F_29 ( const struct V_41 * V_42 , unsigned long V_82 )
{
F_25 ( V_42 -> V_27 , V_82 ) ;
}
static void
F_30 ( struct V_85 * V_86 , T_3 V_87 )
{
F_4 ( V_87 >= V_88 ) ;
F_31 ( V_87 , V_86 -> V_89 ) ;
if ( V_87 == V_86 -> V_90 ) {
V_87 = F_32 ( V_86 -> V_89 , V_86 -> V_91 ) ;
if ( V_87 < V_86 -> V_91 )
V_86 -> V_90 = V_87 ;
else
V_86 -> V_90 = V_92 ;
}
F_2 ( L_9 , V_9 ,
V_87 , V_86 -> V_90 ) ;
}
bool F_33 ( struct V_93 * V_94 , void * V_95 )
{
F_34 ( V_94 , V_96 ) ;
return true ;
}
static void F_35 ( struct V_97 * V_98 )
{
if ( ! F_36 ( V_99 , & V_98 -> V_100 ) ) {
F_37 ( & V_98 -> V_101 . V_102 ,
F_33 , NULL ) ;
return;
}
if ( V_98 -> V_101 . V_90 != V_92 )
return;
F_2 ( L_10 , V_9 ) ;
F_38 ( & V_98 -> V_101 . F_38 ) ;
}
void F_39 ( struct V_97 * V_98 )
{
if ( ! F_36 ( V_99 , & V_98 -> V_100 ) ||
V_98 -> V_103 . V_90 != V_92 )
return;
F_2 ( L_11 , V_9 ) ;
F_38 ( & V_98 -> V_103 . F_38 ) ;
}
static void F_40 ( struct V_104 * V_29 )
{
struct V_85 * V_86 ;
V_86 = & V_29 -> V_105 -> V_101 ;
if ( ! V_29 -> V_106 ) {
F_2 ( L_12 , V_9 ) ;
return;
}
F_26 ( & V_86 -> V_107 ) ;
F_30 ( V_86 , V_29 -> V_106 - V_86 -> V_108 ) ;
F_35 ( V_29 -> V_105 ) ;
F_28 ( & V_86 -> V_107 ) ;
V_29 -> V_106 = NULL ;
}
static int F_41 ( struct V_93 * V_94 , struct V_104 * V_29 )
{
unsigned long V_82 ;
struct V_27 * V_28 ;
if ( V_29 -> V_109 == 1 )
V_29 -> V_109 = V_110 ;
if ( ! F_42 ( V_94 ) )
goto V_111;
switch ( V_29 -> V_109 ) {
case 0 :
++ V_29 -> V_106 -> V_112 ;
V_82 = V_29 -> V_113 ;
V_28 = V_29 -> V_105 -> V_28 ;
F_25 ( V_28 , V_82 ) ;
if ( V_29 -> V_114 != 0 )
F_21 ( V_28 ) ;
break;
case - V_73 :
F_2 ( L_13 ,
V_9 ,
V_29 -> V_106 - V_29 -> V_105 -> V_101 . V_108 ,
V_29 -> V_106 -> V_112 ) ;
goto V_115;
default:
++ V_29 -> V_106 -> V_112 ;
}
V_111:
F_2 ( L_14 , V_9 , V_29 -> V_109 ) ;
F_40 ( V_29 ) ;
return 1 ;
V_115:
if ( ! F_43 ( V_94 ) )
goto V_111;
F_44 ( V_94 , V_38 ) ;
return 0 ;
}
static int F_45 ( struct V_93 * V_94 ,
struct V_104 * V_29 )
{
if ( V_29 -> V_105 == NULL )
return 1 ;
return F_41 ( V_94 , V_29 ) ;
}
static T_3
F_46 ( struct V_85 * V_86 )
{
T_3 V_87 ;
T_3 V_116 = V_92 ;
F_2 ( L_15 ,
V_9 , V_86 -> V_89 [ 0 ] , V_86 -> V_90 ,
V_86 -> V_91 ) ;
V_87 = F_47 ( V_86 -> V_89 , V_86 -> V_91 ) ;
if ( V_87 >= V_86 -> V_91 )
goto V_111;
F_48 ( V_87 , V_86 -> V_89 ) ;
if ( V_87 > V_86 -> V_90 ||
V_86 -> V_90 == V_92 )
V_86 -> V_90 = V_87 ;
V_116 = V_87 ;
V_111:
F_2 ( L_16 ,
V_9 , V_86 -> V_89 [ 0 ] , V_86 -> V_90 , V_116 ) ;
return V_116 ;
}
static void F_49 ( struct V_117 * args ,
struct V_104 * V_29 , int V_118 )
{
args -> V_119 = NULL ;
args -> V_120 = 0 ;
if ( V_118 )
args -> V_120 = 1 ;
V_29 -> V_105 = NULL ;
V_29 -> V_106 = NULL ;
}
int F_50 ( struct V_97 * V_121 ,
struct V_117 * args ,
struct V_104 * V_29 ,
struct V_93 * V_94 )
{
struct V_122 * V_123 ;
struct V_85 * V_86 ;
T_3 V_87 ;
F_2 ( L_17 , V_9 ) ;
if ( V_29 -> V_106 != NULL )
return 0 ;
V_86 = & V_121 -> V_101 ;
F_26 ( & V_86 -> V_107 ) ;
if ( F_36 ( V_99 , & V_121 -> V_100 ) &&
! F_51 ( V_94 , V_96 ) ) {
F_52 ( & V_86 -> V_102 , V_94 , NULL ) ;
F_28 ( & V_86 -> V_107 ) ;
F_2 ( L_18 , V_9 ) ;
return - V_124 ;
}
if ( ! F_53 ( & V_86 -> V_102 ) &&
! F_51 ( V_94 , V_96 ) ) {
F_52 ( & V_86 -> V_102 , V_94 , NULL ) ;
F_28 ( & V_86 -> V_107 ) ;
F_2 ( L_19 , V_9 ) ;
return - V_124 ;
}
V_87 = F_46 ( V_86 ) ;
if ( V_87 == V_92 ) {
F_52 ( & V_86 -> V_102 , V_94 , NULL ) ;
F_28 ( & V_86 -> V_107 ) ;
F_2 ( L_20 , V_9 ) ;
return - V_124 ;
}
F_28 ( & V_86 -> V_107 ) ;
F_34 ( V_94 , V_125 ) ;
V_123 = V_86 -> V_108 + V_87 ;
args -> V_119 = V_121 ;
args -> V_126 = V_87 ;
F_2 ( L_21 , V_9 , V_87 , V_123 -> V_112 ) ;
V_29 -> V_105 = V_121 ;
V_29 -> V_106 = V_123 ;
V_29 -> V_113 = V_127 ;
V_29 -> V_114 = 0 ;
V_29 -> V_109 = 1 ;
return 0 ;
}
int F_54 ( const struct V_41 * V_42 ,
struct V_117 * args ,
struct V_104 * V_29 ,
struct V_93 * V_94 )
{
struct V_97 * V_121 = F_55 ( V_42 ) ;
int V_49 = 0 ;
if ( V_121 == NULL )
goto V_111;
F_2 ( L_22 ,
V_9 , V_121 -> V_28 , V_121 , V_29 -> V_106 ?
V_29 -> V_106 - V_121 -> V_101 . V_108 : - 1 ) ;
V_49 = F_50 ( V_121 , args , V_29 , V_94 ) ;
V_111:
F_2 ( L_23 , V_9 , V_49 ) ;
return V_49 ;
}
static void F_56 ( struct V_93 * V_94 , void * V_128 )
{
struct V_129 * V_130 = V_128 ;
F_2 ( L_24 , V_9 , V_130 -> V_131 ) ;
if ( F_54 ( V_130 -> V_131 , V_130 -> V_132 ,
V_130 -> V_133 , V_94 ) )
return;
F_57 ( V_94 ) ;
}
static void F_58 ( struct V_93 * V_94 , void * V_128 )
{
F_34 ( V_94 , V_96 ) ;
F_56 ( V_94 , V_128 ) ;
}
static void F_59 ( struct V_93 * V_94 , void * V_128 )
{
struct V_129 * V_130 = V_128 ;
F_41 ( V_94 , V_130 -> V_133 ) ;
}
static int F_60 ( struct V_34 * V_35 ,
struct V_41 * V_42 ,
struct V_134 * V_135 ,
struct V_117 * args ,
struct V_104 * V_29 ,
int V_136 )
{
int V_49 ;
struct V_93 * V_94 ;
struct V_129 V_130 = {
. V_131 = V_42 ,
. V_132 = args ,
. V_133 = V_29 ,
} ;
struct V_137 V_138 = {
. V_139 = V_35 ,
. V_134 = V_135 ,
. V_140 = & V_141 ,
. V_142 = & V_130
} ;
if ( V_136 )
V_138 . V_140 = & V_143 ;
V_94 = F_61 ( & V_138 ) ;
if ( F_62 ( V_94 ) )
V_49 = F_63 ( V_94 ) ;
else {
V_49 = V_94 -> V_144 ;
F_64 ( V_94 ) ;
}
return V_49 ;
}
int F_65 ( struct V_34 * V_35 ,
struct V_41 * V_42 ,
struct V_134 * V_135 ,
struct V_117 * args ,
struct V_104 * V_29 ,
int V_118 )
{
F_49 ( args , V_29 , V_118 ) ;
return F_60 ( V_35 , V_42 , V_135 , args , V_29 , 0 ) ;
}
static inline
void F_49 ( struct V_117 * args ,
struct V_104 * V_29 , int V_118 )
{
}
static int F_45 ( struct V_93 * V_94 ,
struct V_104 * V_29 )
{
return 1 ;
}
int F_66 ( struct V_34 * V_35 ,
struct V_41 * V_42 ,
struct V_134 * V_135 ,
struct V_117 * args ,
struct V_104 * V_29 ,
int V_118 )
{
F_49 ( args , V_29 , V_118 ) ;
return F_67 ( V_35 , V_135 , 0 ) ;
}
static inline
int F_68 ( struct V_34 * V_35 ,
struct V_41 * V_42 ,
struct V_134 * V_135 ,
struct V_117 * args ,
struct V_104 * V_29 ,
int V_118 )
{
return V_42 -> V_27 -> V_145 -> V_146 ( V_35 , V_42 , V_135 ,
args , V_29 , V_118 ) ;
}
static void F_69 ( struct V_48 * V_147 , struct V_148 * V_149 )
{
struct V_150 * V_151 = F_70 ( V_147 ) ;
F_26 ( & V_147 -> V_152 ) ;
V_151 -> V_153 |= V_154 | V_155 | V_156 ;
if ( ! V_149 -> V_157 || V_149 -> V_158 != V_147 -> V_159 )
F_71 ( V_147 ) ;
V_147 -> V_159 = V_149 -> V_160 ;
F_28 ( & V_147 -> V_152 ) ;
}
static void F_72 ( struct V_161 * V_17 )
{
V_17 -> V_162 . V_163 = & V_17 -> V_163 ;
V_17 -> V_162 . V_164 = & V_17 -> V_164 ;
V_17 -> V_162 . V_165 = V_17 -> V_166 . V_165 ;
V_17 -> V_167 . V_165 = V_17 -> V_168 . V_165 ;
V_17 -> V_162 . V_42 = V_17 -> V_166 . V_42 ;
F_73 ( & V_17 -> V_163 ) ;
F_73 ( & V_17 -> V_164 ) ;
F_74 ( & V_17 -> V_163 , & V_17 -> V_169 , & V_17 -> V_170 ) ;
}
static struct V_161 * F_75 ( struct V_13 * V_13 ,
struct V_171 * V_172 , T_4 V_173 , int V_174 ,
const struct V_175 * V_176 ,
T_5 V_177 )
{
struct V_13 * V_178 = F_76 ( V_13 ) ;
struct V_48 * V_147 = V_178 -> V_23 ;
struct V_41 * V_42 = F_77 ( V_147 ) ;
struct V_161 * V_17 ;
V_17 = F_78 ( sizeof( * V_17 ) , V_177 ) ;
if ( V_17 == NULL )
goto V_1;
V_17 -> V_166 . V_165 = F_79 ( & V_172 -> V_179 , V_177 ) ;
if ( V_17 -> V_166 . V_165 == NULL )
goto V_180;
F_80 ( V_13 -> V_181 ) ;
V_17 -> V_13 = F_81 ( V_13 ) ;
V_17 -> V_147 = V_178 ;
V_17 -> V_182 = V_172 ;
F_82 ( & V_172 -> V_183 ) ;
V_17 -> V_166 . V_184 = F_83 ( V_147 ) ;
V_17 -> V_166 . V_185 = V_174 ;
V_17 -> V_166 . V_173 = V_173 & ( V_52 | V_186 ) ;
V_17 -> V_166 . V_187 = V_42 -> V_27 -> V_188 ;
V_17 -> V_166 . V_189 . V_190 = F_84 ( V_172 -> V_179 . V_190 ) ;
V_17 -> V_166 . V_189 . V_191 = V_172 -> V_179 . V_192 ;
V_17 -> V_166 . V_193 = & V_13 -> V_194 ;
V_17 -> V_166 . V_42 = V_42 ;
V_17 -> V_166 . V_195 = V_42 -> V_196 ;
V_17 -> V_166 . V_197 = V_42 -> V_198 ;
V_17 -> V_166 . V_199 = V_200 ;
if ( V_176 != NULL && V_176 -> V_201 != 0 ) {
T_2 V_202 [ 2 ] ;
V_17 -> V_166 . V_203 . V_176 = & V_17 -> V_176 ;
memcpy ( & V_17 -> V_176 , V_176 , sizeof( V_17 -> V_176 ) ) ;
V_202 [ 0 ] = V_127 ;
V_202 [ 1 ] = V_39 -> V_204 ;
memcpy ( V_17 -> V_166 . V_203 . V_12 . V_130 , V_202 ,
sizeof( V_17 -> V_166 . V_203 . V_12 . V_130 ) ) ;
}
V_17 -> V_168 . V_184 = & V_17 -> V_162 . V_184 ;
V_17 -> V_168 . V_205 = & V_17 -> V_162 . V_205 ;
V_17 -> V_168 . V_165 = V_17 -> V_166 . V_165 ;
F_72 ( V_17 ) ;
F_85 ( & V_17 -> V_206 ) ;
return V_17 ;
V_180:
F_86 ( V_17 ) ;
V_1:
F_87 ( V_178 ) ;
return NULL ;
}
static void F_88 ( struct V_206 * V_206 )
{
struct V_161 * V_17 = F_89 ( V_206 ,
struct V_161 , V_206 ) ;
struct V_207 * V_208 = V_17 -> V_13 -> V_181 ;
F_90 ( V_17 -> V_166 . V_165 ) ;
if ( V_17 -> V_47 != NULL )
F_91 ( V_17 -> V_47 ) ;
F_92 ( V_17 -> V_182 ) ;
F_87 ( V_17 -> V_147 ) ;
F_87 ( V_17 -> V_13 ) ;
F_93 ( V_208 ) ;
F_94 ( & V_17 -> V_163 ) ;
F_86 ( V_17 ) ;
}
static void F_95 ( struct V_161 * V_17 )
{
if ( V_17 != NULL )
F_96 ( & V_17 -> V_206 , F_88 ) ;
}
static int F_97 ( struct V_93 * V_94 )
{
int V_49 ;
V_49 = F_98 ( V_94 ) ;
return V_49 ;
}
static int F_99 ( struct V_46 * V_47 , T_4 V_209 , int V_210 )
{
int V_49 = 0 ;
if ( V_210 & ( V_211 | V_212 ) )
goto V_111;
switch ( V_209 & ( V_52 | V_186 ) ) {
case V_52 :
V_49 |= F_36 ( V_213 , & V_47 -> V_174 ) != 0
&& V_47 -> V_214 != 0 ;
break;
case V_186 :
V_49 |= F_36 ( V_215 , & V_47 -> V_174 ) != 0
&& V_47 -> V_216 != 0 ;
break;
case V_52 | V_186 :
V_49 |= F_36 ( V_217 , & V_47 -> V_174 ) != 0
&& V_47 -> V_218 != 0 ;
}
V_111:
return V_49 ;
}
static int F_100 ( struct V_219 * V_220 , T_4 V_173 )
{
if ( V_220 == NULL )
return 0 ;
if ( ( V_220 -> type & V_173 ) != V_173 )
return 0 ;
if ( F_36 ( V_221 , & V_220 -> V_174 ) )
return 0 ;
F_101 ( V_220 ) ;
return 1 ;
}
static void F_102 ( struct V_46 * V_47 , T_4 V_173 )
{
switch ( V_173 ) {
case V_186 :
V_47 -> V_216 ++ ;
break;
case V_52 :
V_47 -> V_214 ++ ;
break;
case V_52 | V_186 :
V_47 -> V_218 ++ ;
}
F_103 ( V_47 , V_47 -> V_47 | V_173 ) ;
}
static void F_104 ( struct V_46 * V_47 , T_6 * V_205 , T_4 V_173 )
{
if ( F_36 ( V_222 , & V_47 -> V_174 ) == 0 )
F_105 ( & V_47 -> V_205 , V_205 ) ;
F_105 ( & V_47 -> V_223 , V_205 ) ;
switch ( V_173 ) {
case V_52 :
F_106 ( V_213 , & V_47 -> V_174 ) ;
break;
case V_186 :
F_106 ( V_215 , & V_47 -> V_174 ) ;
break;
case V_52 | V_186 :
F_106 ( V_217 , & V_47 -> V_174 ) ;
}
}
static void F_107 ( struct V_46 * V_47 , T_6 * V_205 , T_4 V_173 )
{
F_108 ( & V_47 -> V_224 ) ;
F_104 ( V_47 , V_205 , V_173 ) ;
F_109 ( & V_47 -> V_224 ) ;
}
static void F_110 ( struct V_46 * V_47 , T_6 * V_223 , const T_6 * V_225 , T_4 V_173 )
{
F_108 ( & V_47 -> V_224 ) ;
if ( V_225 != NULL ) {
F_105 ( & V_47 -> V_205 , V_225 ) ;
F_106 ( V_222 , & V_47 -> V_174 ) ;
}
if ( V_223 != NULL )
F_104 ( V_47 , V_223 , V_173 ) ;
F_109 ( & V_47 -> V_224 ) ;
F_26 ( & V_47 -> V_182 -> V_226 ) ;
F_102 ( V_47 , V_173 ) ;
F_28 ( & V_47 -> V_182 -> V_226 ) ;
}
static int F_111 ( struct V_46 * V_47 , T_6 * V_223 , T_6 * V_220 , T_4 V_173 )
{
struct V_150 * V_151 = F_70 ( V_47 -> V_48 ) ;
struct V_219 * V_227 ;
int V_49 = 0 ;
V_173 &= ( V_52 | V_186 ) ;
F_112 () ;
V_227 = F_113 ( V_151 -> V_220 ) ;
if ( V_227 == NULL )
goto V_228;
F_26 ( & V_227 -> V_229 ) ;
if ( V_151 -> V_220 != V_227 ||
( V_227 -> type & V_173 ) != V_173 )
goto V_230;
if ( V_220 == NULL )
V_220 = & V_227 -> V_205 ;
else if ( ! F_114 ( & V_227 -> V_205 , V_220 ) )
goto V_230;
F_101 ( V_227 ) ;
F_110 ( V_47 , V_223 , & V_227 -> V_205 , V_173 ) ;
V_49 = 1 ;
V_230:
F_28 ( & V_227 -> V_229 ) ;
V_228:
F_115 () ;
if ( ! V_49 && V_223 != NULL ) {
F_110 ( V_47 , V_223 , NULL , V_173 ) ;
V_49 = 1 ;
}
return V_49 ;
}
static void F_116 ( struct V_48 * V_48 , T_4 V_173 )
{
struct V_219 * V_220 ;
F_112 () ;
V_220 = F_113 ( F_70 ( V_48 ) -> V_220 ) ;
if ( V_220 == NULL || ( V_220 -> type & V_173 ) == V_173 ) {
F_115 () ;
return;
}
F_115 () ;
F_18 ( V_48 ) ;
}
static struct V_46 * F_117 ( struct V_161 * V_231 )
{
struct V_46 * V_47 = V_231 -> V_47 ;
struct V_150 * V_151 = F_70 ( V_47 -> V_48 ) ;
struct V_219 * V_220 ;
int V_210 = V_231 -> V_166 . V_185 & ( V_211 | V_212 ) ;
T_4 V_173 = V_231 -> V_166 . V_173 ;
T_6 V_205 ;
int V_49 = - V_124 ;
for (; ; ) {
if ( F_99 ( V_47 , V_173 , V_210 ) ) {
F_26 ( & V_47 -> V_182 -> V_226 ) ;
if ( F_99 ( V_47 , V_173 , V_210 ) ) {
F_102 ( V_47 , V_173 ) ;
F_28 ( & V_47 -> V_182 -> V_226 ) ;
goto V_232;
}
F_28 ( & V_47 -> V_182 -> V_226 ) ;
}
F_112 () ;
V_220 = F_113 ( V_151 -> V_220 ) ;
if ( ! F_100 ( V_220 , V_173 ) ) {
F_115 () ;
break;
}
F_105 ( & V_205 , & V_220 -> V_205 ) ;
F_115 () ;
V_49 = F_118 ( V_47 -> V_48 , V_47 -> V_182 -> V_233 , V_210 ) ;
if ( V_49 != 0 )
goto V_111;
V_49 = - V_124 ;
if ( F_111 ( V_47 , NULL , & V_205 , V_173 ) )
goto V_232;
}
V_111:
return F_119 ( V_49 ) ;
V_232:
F_82 ( & V_47 -> V_18 ) ;
return V_47 ;
}
static struct V_46 * F_120 ( struct V_161 * V_130 )
{
struct V_48 * V_48 ;
struct V_46 * V_47 = NULL ;
struct V_219 * V_220 ;
int V_49 ;
if ( ! V_130 -> V_234 ) {
V_47 = F_117 ( V_130 ) ;
goto V_111;
}
V_49 = - V_124 ;
if ( ! ( V_130 -> V_163 . V_235 & V_236 ) )
goto V_1;
V_48 = F_121 ( V_130 -> V_147 -> V_181 , & V_130 -> V_162 . V_184 , & V_130 -> V_163 ) ;
V_49 = F_63 ( V_48 ) ;
if ( F_62 ( V_48 ) )
goto V_1;
V_49 = - V_237 ;
V_47 = F_122 ( V_48 , V_130 -> V_182 ) ;
if ( V_47 == NULL )
goto V_238;
if ( V_130 -> V_162 . V_239 != 0 ) {
struct V_27 * V_28 = F_77 ( V_48 ) -> V_27 ;
int V_240 = 0 ;
F_112 () ;
V_220 = F_113 ( F_70 ( V_48 ) -> V_220 ) ;
if ( V_220 )
V_240 = V_220 -> V_174 ;
F_115 () ;
if ( V_130 -> V_166 . V_199 == V_241 ) {
F_123 ( L_25
L_26
L_27 ,
V_28 -> V_81 ) ;
} else if ( ( V_240 & 1UL << V_221 ) == 0 )
F_124 ( V_47 -> V_48 ,
V_130 -> V_182 -> V_233 ,
& V_130 -> V_162 ) ;
else
F_125 ( V_47 -> V_48 ,
V_130 -> V_182 -> V_233 ,
& V_130 -> V_162 ) ;
}
F_111 ( V_47 , & V_130 -> V_162 . V_205 , NULL ,
V_130 -> V_166 . V_173 ) ;
F_126 ( V_48 ) ;
V_111:
return V_47 ;
V_238:
F_126 ( V_48 ) ;
V_1:
return F_119 ( V_49 ) ;
}
static struct V_242 * F_127 ( struct V_46 * V_47 )
{
struct V_150 * V_151 = F_70 ( V_47 -> V_48 ) ;
struct V_242 * V_243 ;
F_26 ( & V_47 -> V_48 -> V_152 ) ;
F_128 (ctx, &nfsi->open_files, list) {
if ( V_243 -> V_47 != V_47 )
continue;
F_129 ( V_243 ) ;
F_28 ( & V_47 -> V_48 -> V_152 ) ;
return V_243 ;
}
F_28 ( & V_47 -> V_48 -> V_152 ) ;
return F_119 ( - V_244 ) ;
}
static struct V_161 * F_130 ( struct V_242 * V_243 , struct V_46 * V_47 )
{
struct V_161 * V_231 ;
V_231 = F_75 ( V_243 -> V_13 , V_47 -> V_182 , 0 , 0 , NULL , V_245 ) ;
if ( V_231 == NULL )
return F_119 ( - V_237 ) ;
V_231 -> V_47 = V_47 ;
F_82 ( & V_47 -> V_18 ) ;
return V_231 ;
}
static int F_131 ( struct V_161 * V_231 , T_4 V_173 , struct V_46 * * V_29 )
{
struct V_46 * V_246 ;
int V_49 ;
V_231 -> V_166 . V_185 = 0 ;
V_231 -> V_166 . V_173 = V_173 ;
memset ( & V_231 -> V_162 , 0 , sizeof( V_231 -> V_162 ) ) ;
memset ( & V_231 -> V_167 , 0 , sizeof( V_231 -> V_167 ) ) ;
F_72 ( V_231 ) ;
V_49 = F_132 ( V_231 ) ;
if ( V_49 != 0 )
return V_49 ;
V_246 = F_120 ( V_231 ) ;
if ( F_62 ( V_246 ) )
return F_63 ( V_246 ) ;
F_133 ( V_246 , V_173 ) ;
* V_29 = V_246 ;
return 0 ;
}
static int F_134 ( struct V_161 * V_231 , struct V_46 * V_47 )
{
struct V_46 * V_246 ;
int V_49 ;
F_135 ( V_222 , & V_47 -> V_174 ) ;
F_136 () ;
if ( V_47 -> V_218 != 0 ) {
F_135 ( V_217 , & V_47 -> V_174 ) ;
V_49 = F_131 ( V_231 , V_52 | V_186 , & V_246 ) ;
if ( V_49 != 0 )
return V_49 ;
if ( V_246 != V_47 )
return - V_247 ;
}
if ( V_47 -> V_216 != 0 ) {
F_135 ( V_215 , & V_47 -> V_174 ) ;
V_49 = F_131 ( V_231 , V_186 , & V_246 ) ;
if ( V_49 != 0 )
return V_49 ;
if ( V_246 != V_47 )
return - V_247 ;
}
if ( V_47 -> V_214 != 0 ) {
F_135 ( V_213 , & V_47 -> V_174 ) ;
V_49 = F_131 ( V_231 , V_52 , & V_246 ) ;
if ( V_49 != 0 )
return V_49 ;
if ( V_246 != V_47 )
return - V_247 ;
}
if ( F_36 ( V_222 , & V_47 -> V_174 ) == 0 &&
! F_114 ( & V_47 -> V_205 , & V_47 -> V_223 ) ) {
F_108 ( & V_47 -> V_224 ) ;
if ( F_36 ( V_222 , & V_47 -> V_174 ) == 0 )
F_105 ( & V_47 -> V_205 , & V_47 -> V_223 ) ;
F_109 ( & V_47 -> V_224 ) ;
}
return 0 ;
}
static int F_137 ( struct V_242 * V_243 , struct V_46 * V_47 )
{
struct V_219 * V_220 ;
struct V_161 * V_231 ;
T_4 V_239 = 0 ;
int V_248 ;
V_231 = F_130 ( V_243 , V_47 ) ;
if ( F_62 ( V_231 ) )
return F_63 ( V_231 ) ;
V_231 -> V_166 . V_199 = V_249 ;
V_231 -> V_166 . V_184 = F_83 ( V_47 -> V_48 ) ;
F_112 () ;
V_220 = F_113 ( F_70 ( V_47 -> V_48 ) -> V_220 ) ;
if ( V_220 != NULL && F_36 ( V_221 , & V_220 -> V_174 ) != 0 )
V_239 = V_220 -> type ;
F_115 () ;
V_231 -> V_166 . V_203 . V_239 = V_239 ;
V_248 = F_134 ( V_231 , V_47 ) ;
F_95 ( V_231 ) ;
return V_248 ;
}
static int F_138 ( struct V_242 * V_243 , struct V_46 * V_47 )
{
struct V_41 * V_42 = F_77 ( V_47 -> V_48 ) ;
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_137 ( V_243 , V_47 ) ;
if ( V_1 != - V_73 )
break;
F_16 ( V_42 , V_1 , & V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_139 ( struct V_171 * V_172 , struct V_46 * V_47 )
{
struct V_242 * V_243 ;
int V_49 ;
V_243 = F_127 ( V_47 ) ;
if ( F_62 ( V_243 ) )
return F_63 ( V_243 ) ;
V_49 = F_138 ( V_243 , V_47 ) ;
F_140 ( V_243 ) ;
return V_49 ;
}
static int F_141 ( struct V_242 * V_243 , struct V_46 * V_47 , const T_6 * V_205 )
{
struct V_161 * V_231 ;
int V_49 ;
V_231 = F_130 ( V_243 , V_47 ) ;
if ( F_62 ( V_231 ) )
return F_63 ( V_231 ) ;
V_231 -> V_166 . V_199 = V_241 ;
F_105 ( & V_231 -> V_166 . V_203 . V_220 , V_205 ) ;
V_49 = F_134 ( V_231 , V_47 ) ;
F_95 ( V_231 ) ;
return V_49 ;
}
int F_142 ( struct V_242 * V_243 , struct V_46 * V_47 , const T_6 * V_205 )
{
struct V_44 V_45 = { } ;
struct V_41 * V_42 = F_77 ( V_47 -> V_48 ) ;
int V_1 ;
do {
V_1 = F_141 ( V_243 , V_47 , V_205 ) ;
switch ( V_1 ) {
case 0 :
case - V_244 :
case - V_247 :
goto V_111;
case - V_61 :
case - V_62 :
case - V_63 :
case - V_64 :
case - V_65 :
F_23 ( V_42 -> V_27 -> V_68 ) ;
goto V_111;
case - V_59 :
case - V_58 :
case - V_57 :
F_21 ( V_42 -> V_27 ) ;
goto V_111;
case - V_40 :
case - V_54 :
case - V_55 :
case - V_56 :
F_143 ( V_47 -> V_48 ,
V_205 ) ;
F_19 ( V_42 , V_47 ) ;
case - V_74 :
case - V_237 :
V_1 = 0 ;
goto V_111;
}
V_1 = F_16 ( V_42 , V_1 , & V_45 ) ;
} while ( V_45 . V_50 );
V_111:
return V_1 ;
}
static void F_144 ( struct V_93 * V_94 , void * V_128 )
{
struct V_161 * V_130 = V_128 ;
V_130 -> V_250 = V_94 -> V_144 ;
if ( V_130 -> V_250 == 0 ) {
F_105 ( & V_130 -> V_162 . V_205 , & V_130 -> V_167 . V_205 ) ;
F_145 ( & V_130 -> V_182 -> V_179 , 0 ) ;
F_29 ( V_130 -> V_162 . V_42 , V_130 -> V_82 ) ;
V_130 -> V_234 = 1 ;
}
}
static void F_146 ( void * V_128 )
{
struct V_161 * V_130 = V_128 ;
struct V_46 * V_47 = NULL ;
if ( V_130 -> V_251 == 0 )
goto V_252;
if ( ! V_130 -> V_234 )
goto V_252;
V_47 = F_120 ( V_130 ) ;
if ( ! F_62 ( V_47 ) )
F_133 ( V_47 , V_130 -> V_166 . V_173 ) ;
V_252:
F_95 ( V_130 ) ;
}
static int F_147 ( struct V_161 * V_130 )
{
struct V_41 * V_42 = F_77 ( V_130 -> V_147 -> V_23 ) ;
struct V_93 * V_94 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_255 ] ,
. V_256 = & V_130 -> V_168 ,
. V_257 = & V_130 -> V_167 ,
. V_258 = V_130 -> V_182 -> V_233 ,
} ;
struct V_137 V_259 = {
. V_139 = V_42 -> V_75 ,
. V_134 = & V_135 ,
. V_140 = & V_260 ,
. V_142 = V_130 ,
. V_261 = V_262 ,
. V_174 = V_263 ,
} ;
int V_248 ;
F_148 ( & V_130 -> V_206 ) ;
V_130 -> V_234 = 0 ;
V_130 -> V_250 = 0 ;
V_130 -> V_82 = V_127 ;
V_94 = F_61 ( & V_259 ) ;
if ( F_62 ( V_94 ) )
return F_63 ( V_94 ) ;
V_248 = F_97 ( V_94 ) ;
if ( V_248 != 0 ) {
V_130 -> V_251 = 1 ;
F_149 () ;
} else
V_248 = V_130 -> V_250 ;
F_64 ( V_94 ) ;
return V_248 ;
}
static void F_150 ( struct V_93 * V_94 , void * V_128 )
{
struct V_161 * V_130 = V_128 ;
struct V_171 * V_172 = V_130 -> V_182 ;
if ( F_151 ( V_130 -> V_166 . V_165 , V_94 ) != 0 )
return;
if ( V_130 -> V_47 != NULL ) {
struct V_219 * V_220 ;
if ( F_99 ( V_130 -> V_47 , V_130 -> V_166 . V_173 , V_130 -> V_166 . V_185 ) )
goto V_264;
F_112 () ;
V_220 = F_113 ( F_70 ( V_130 -> V_47 -> V_48 ) -> V_220 ) ;
if ( V_130 -> V_166 . V_199 != V_241 &&
F_100 ( V_220 , V_130 -> V_166 . V_173 ) )
goto V_265;
F_115 () ;
}
V_130 -> V_166 . V_187 = V_172 -> V_266 -> V_27 -> V_188 ;
if ( V_130 -> V_166 . V_199 == V_249 ) {
V_94 -> V_267 . V_253 = & V_254 [ V_268 ] ;
F_152 ( & V_130 -> V_162 . V_184 , V_130 -> V_166 . V_184 ) ;
}
V_130 -> V_82 = V_127 ;
if ( F_54 ( V_130 -> V_166 . V_42 ,
& V_130 -> V_166 . V_132 ,
& V_130 -> V_162 . V_133 , V_94 ) )
return;
F_57 ( V_94 ) ;
return;
V_265:
F_115 () ;
V_264:
V_94 -> V_269 = NULL ;
}
static void F_153 ( struct V_93 * V_94 , void * V_128 )
{
F_34 ( V_94 , V_96 ) ;
F_150 ( V_94 , V_128 ) ;
}
static void F_154 ( struct V_93 * V_94 , void * V_128 )
{
struct V_161 * V_130 = V_128 ;
V_130 -> V_250 = V_94 -> V_144 ;
if ( ! F_45 ( V_94 , & V_130 -> V_162 . V_133 ) )
return;
if ( V_94 -> V_144 == 0 ) {
switch ( V_130 -> V_162 . V_163 -> V_209 & V_270 ) {
case V_271 :
break;
case V_272 :
V_130 -> V_250 = - V_273 ;
break;
case V_274 :
V_130 -> V_250 = - V_275 ;
break;
default:
V_130 -> V_250 = - V_276 ;
}
F_29 ( V_130 -> V_162 . V_42 , V_130 -> V_82 ) ;
if ( ! ( V_130 -> V_162 . V_277 & V_278 ) )
F_145 ( & V_130 -> V_182 -> V_179 , 0 ) ;
}
V_130 -> V_234 = 1 ;
}
static void F_155 ( void * V_128 )
{
struct V_161 * V_130 = V_128 ;
struct V_46 * V_47 = NULL ;
if ( V_130 -> V_251 == 0 )
goto V_252;
if ( V_130 -> V_250 != 0 || ! V_130 -> V_234 )
goto V_252;
if ( V_130 -> V_162 . V_277 & V_278 )
goto V_252;
V_47 = F_120 ( V_130 ) ;
if ( ! F_62 ( V_47 ) )
F_133 ( V_47 , V_130 -> V_166 . V_173 ) ;
V_252:
F_95 ( V_130 ) ;
}
static int F_156 ( struct V_161 * V_130 , int V_279 )
{
struct V_48 * V_147 = V_130 -> V_147 -> V_23 ;
struct V_41 * V_42 = F_77 ( V_147 ) ;
struct V_280 * V_166 = & V_130 -> V_166 ;
struct V_281 * V_162 = & V_130 -> V_162 ;
struct V_93 * V_94 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_282 ] ,
. V_256 = V_166 ,
. V_257 = V_162 ,
. V_258 = V_130 -> V_182 -> V_233 ,
} ;
struct V_137 V_259 = {
. V_139 = V_42 -> V_75 ,
. V_134 = & V_135 ,
. V_140 = & V_283 ,
. V_142 = V_130 ,
. V_261 = V_262 ,
. V_174 = V_263 ,
} ;
int V_248 ;
F_49 ( & V_166 -> V_132 , & V_162 -> V_133 , 1 ) ;
F_148 ( & V_130 -> V_206 ) ;
V_130 -> V_234 = 0 ;
V_130 -> V_250 = 0 ;
V_130 -> V_251 = 0 ;
if ( V_279 )
V_259 . V_140 = & V_284 ;
V_94 = F_61 ( & V_259 ) ;
if ( F_62 ( V_94 ) )
return F_63 ( V_94 ) ;
V_248 = F_97 ( V_94 ) ;
if ( V_248 != 0 ) {
V_130 -> V_251 = 1 ;
F_149 () ;
} else
V_248 = V_130 -> V_250 ;
F_64 ( V_94 ) ;
return V_248 ;
}
static int F_132 ( struct V_161 * V_130 )
{
struct V_48 * V_147 = V_130 -> V_147 -> V_23 ;
struct V_281 * V_162 = & V_130 -> V_162 ;
int V_248 ;
V_248 = F_156 ( V_130 , 1 ) ;
if ( V_248 != 0 || ! V_130 -> V_234 )
return V_248 ;
F_157 ( F_77 ( V_147 ) , & V_130 -> V_163 ) ;
F_158 ( V_147 , V_162 -> V_164 ) ;
if ( V_162 -> V_277 & V_278 ) {
V_248 = F_147 ( V_130 ) ;
if ( V_248 != 0 )
return V_248 ;
}
return V_248 ;
}
static int F_159 ( struct V_161 * V_130 )
{
struct V_48 * V_147 = V_130 -> V_147 -> V_23 ;
struct V_41 * V_42 = F_77 ( V_147 ) ;
struct V_280 * V_166 = & V_130 -> V_166 ;
struct V_281 * V_162 = & V_130 -> V_162 ;
int V_248 ;
V_248 = F_156 ( V_130 , 0 ) ;
if ( ! V_130 -> V_234 )
return V_248 ;
if ( V_248 != 0 ) {
if ( V_248 == - V_7 &&
! ( V_166 -> V_185 & V_285 ) )
return - V_244 ;
return V_248 ;
}
F_157 ( V_42 , & V_130 -> V_163 ) ;
if ( V_166 -> V_185 & V_285 ) {
F_69 ( V_147 , & V_162 -> V_149 ) ;
F_160 ( V_147 , V_162 -> V_164 ) ;
} else
F_158 ( V_147 , V_162 -> V_164 ) ;
if ( ( V_162 -> V_277 & V_286 ) == 0 )
V_42 -> V_78 &= ~ V_287 ;
if( V_162 -> V_277 & V_278 ) {
V_248 = F_147 ( V_130 ) ;
if ( V_248 != 0 )
return V_248 ;
}
if ( ! ( V_162 -> V_163 -> V_235 & V_236 ) )
F_161 ( V_42 , & V_162 -> V_184 , V_162 -> V_163 ) ;
return 0 ;
}
static int F_162 ( struct V_27 * V_28 )
{
unsigned int V_288 ;
int V_49 ;
for ( V_288 = V_289 ; V_288 != 0 ; V_288 -- ) {
V_49 = F_10 ( V_28 ) ;
if ( V_49 != 0 )
break;
if ( ! F_36 ( V_290 , & V_28 -> V_30 ) &&
! F_36 ( V_291 , & V_28 -> V_30 ) )
break;
F_163 ( V_28 ) ;
V_49 = - V_10 ;
}
return V_49 ;
}
static int F_164 ( struct V_41 * V_42 )
{
return F_162 ( V_42 -> V_27 ) ;
}
static int F_165 ( struct V_242 * V_243 , struct V_46 * V_47 )
{
struct V_161 * V_231 ;
int V_49 ;
V_231 = F_130 ( V_243 , V_47 ) ;
if ( F_62 ( V_231 ) )
return F_63 ( V_231 ) ;
V_49 = F_134 ( V_231 , V_47 ) ;
if ( V_49 == - V_247 )
F_166 ( V_243 -> V_13 ) ;
F_95 ( V_231 ) ;
return V_49 ;
}
static int F_167 ( struct V_242 * V_243 , struct V_46 * V_47 )
{
struct V_41 * V_42 = F_77 ( V_47 -> V_48 ) ;
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_165 ( V_243 , V_47 ) ;
switch ( V_1 ) {
default:
goto V_111;
case - V_72 :
case - V_73 :
F_16 ( V_42 , V_1 , & V_45 ) ;
V_1 = 0 ;
}
} while ( V_45 . V_50 );
V_111:
return V_1 ;
}
static int F_168 ( struct V_171 * V_172 , struct V_46 * V_47 )
{
struct V_242 * V_243 ;
int V_49 ;
V_243 = F_127 ( V_47 ) ;
if ( F_62 ( V_243 ) )
return F_63 ( V_243 ) ;
V_49 = F_167 ( V_243 , V_47 ) ;
F_140 ( V_243 ) ;
return V_49 ;
}
static int F_169 ( struct V_46 * V_47 , T_6 * V_205 , unsigned int V_174 )
{
int V_248 = V_110 ;
struct V_41 * V_42 = F_77 ( V_47 -> V_48 ) ;
if ( V_47 -> V_174 & V_174 ) {
V_248 = F_170 ( V_42 , V_205 ) ;
if ( V_248 != V_110 ) {
F_171 ( V_42 , V_205 ) ;
V_47 -> V_174 &= ~ V_174 ;
}
}
return V_248 ;
}
static int F_172 ( struct V_171 * V_172 , struct V_46 * V_47 )
{
int V_292 , V_293 ;
int V_294 = 1 << V_222 ;
int V_185 = ( 1 << V_213 ) | ( 1 << V_215 ) | ( 1 << V_217 ) ;
V_292 = F_169 ( V_47 , & V_47 -> V_205 , V_294 ) ;
V_293 = F_169 ( V_47 , & V_47 -> V_223 , V_185 ) ;
if ( ( V_292 == V_110 ) && ( V_293 == V_110 ) )
return V_110 ;
return F_168 ( V_172 , V_47 ) ;
}
static inline void F_173 ( struct V_161 * V_231 , struct V_175 * V_295 )
{
if ( ( V_231 -> V_162 . V_296 [ 1 ] & V_297 ) &&
! ( V_295 -> V_201 & V_298 ) )
V_295 -> V_201 |= V_299 ;
if ( ( V_231 -> V_162 . V_296 [ 1 ] & V_300 ) &&
! ( V_295 -> V_201 & V_301 ) )
V_295 -> V_201 |= V_302 ;
}
static int F_174 ( struct V_48 * V_147 , struct V_13 * V_13 , T_4 V_173 , int V_174 , struct V_175 * V_295 , struct V_258 * V_303 , struct V_46 * * V_29 )
{
struct V_171 * V_172 ;
struct V_46 * V_47 = NULL ;
struct V_41 * V_42 = F_77 ( V_147 ) ;
struct V_161 * V_231 ;
int V_248 ;
V_248 = - V_237 ;
V_172 = F_175 ( V_42 , V_303 , V_304 ) ;
if ( V_172 == NULL ) {
F_2 ( L_28 ) ;
goto V_305;
}
V_248 = F_164 ( V_42 ) ;
if ( V_248 != 0 )
goto V_306;
if ( V_13 -> V_23 != NULL )
F_116 ( V_13 -> V_23 , V_173 ) ;
V_248 = - V_237 ;
V_231 = F_75 ( V_13 , V_172 , V_173 , V_174 , V_295 , V_304 ) ;
if ( V_231 == NULL )
goto V_306;
if ( V_13 -> V_23 != NULL )
V_231 -> V_47 = F_122 ( V_13 -> V_23 , V_172 ) ;
V_248 = F_159 ( V_231 ) ;
if ( V_248 != 0 )
goto V_307;
V_47 = F_120 ( V_231 ) ;
V_248 = F_63 ( V_47 ) ;
if ( F_62 ( V_47 ) )
goto V_307;
if ( V_42 -> V_78 & V_287 )
F_106 ( V_308 , & V_47 -> V_174 ) ;
if ( V_231 -> V_166 . V_185 & V_211 ) {
F_173 ( V_231 , V_295 ) ;
F_73 ( V_231 -> V_162 . V_163 ) ;
V_248 = F_176 ( V_47 -> V_48 , V_303 ,
V_231 -> V_162 . V_163 , V_295 ,
V_47 ) ;
if ( V_248 == 0 )
F_177 ( V_47 -> V_48 , V_295 ) ;
F_160 ( V_47 -> V_48 , V_231 -> V_162 . V_163 ) ;
}
F_95 ( V_231 ) ;
F_92 ( V_172 ) ;
* V_29 = V_47 ;
return 0 ;
V_307:
F_95 ( V_231 ) ;
V_306:
F_92 ( V_172 ) ;
V_305:
* V_29 = NULL ;
return V_248 ;
}
static struct V_46 * F_178 ( struct V_48 * V_147 , struct V_13 * V_13 , T_4 V_173 , int V_174 , struct V_175 * V_295 , struct V_258 * V_303 )
{
struct V_44 V_45 = { } ;
struct V_46 * V_29 ;
int V_248 ;
do {
V_248 = F_174 ( V_147 , V_13 , V_173 , V_174 , V_295 , V_303 , & V_29 ) ;
if ( V_248 == 0 )
break;
if ( V_248 == - V_309 ) {
F_179 ( L_5
L_29 ,
F_77 ( V_147 ) -> V_27 -> V_81 ) ;
V_45 . V_50 = 1 ;
continue;
}
if ( V_248 == - V_56 ) {
V_45 . V_50 = 1 ;
continue;
}
if ( V_248 == - V_124 ) {
V_45 . V_50 = 1 ;
continue;
}
V_29 = F_119 ( F_16 ( F_77 ( V_147 ) ,
V_248 , & V_45 ) ) ;
} while ( V_45 . V_50 );
return V_29 ;
}
static int F_180 ( struct V_48 * V_48 , struct V_258 * V_303 ,
struct V_310 * V_311 , struct V_175 * V_295 ,
struct V_46 * V_47 )
{
struct V_41 * V_42 = F_77 ( V_48 ) ;
struct V_312 V_313 = {
. V_184 = F_83 ( V_48 ) ,
. V_314 = V_295 ,
. V_42 = V_42 ,
. V_195 = V_42 -> V_196 ,
} ;
struct V_315 V_29 = {
. V_311 = V_311 ,
. V_42 = V_42 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_316 ] ,
. V_256 = & V_313 ,
. V_257 = & V_29 ,
. V_258 = V_303 ,
} ;
unsigned long V_82 = V_127 ;
int V_248 ;
F_73 ( V_311 ) ;
if ( V_47 != NULL ) {
F_181 ( & V_313 . V_205 , V_47 , V_186 ,
V_39 -> V_317 , V_39 -> V_318 ) ;
} else if ( F_182 ( & V_313 . V_205 , V_48 ,
V_186 ) ) {
} else
F_105 ( & V_313 . V_205 , & V_319 ) ;
V_248 = F_68 ( V_42 -> V_75 , V_42 , & V_135 , & V_313 . V_132 , & V_29 . V_133 , 1 ) ;
if ( V_248 == 0 && V_47 != NULL )
F_29 ( V_42 , V_82 ) ;
return V_248 ;
}
static int F_176 ( struct V_48 * V_48 , struct V_258 * V_303 ,
struct V_310 * V_311 , struct V_175 * V_295 ,
struct V_46 * V_47 )
{
struct V_41 * V_42 = F_77 ( V_48 ) ;
struct V_44 V_45 = {
. V_47 = V_47 ,
. V_48 = V_48 ,
} ;
int V_1 ;
do {
V_1 = F_180 ( V_48 , V_303 , V_311 , V_295 , V_47 ) ;
switch ( V_1 ) {
case - V_51 :
if ( V_47 && ! ( V_47 -> V_47 & V_186 ) ) {
V_1 = - V_320 ;
if ( V_295 -> V_201 & V_321 )
V_1 = - V_322 ;
goto V_111;
}
}
V_1 = F_16 ( V_42 , V_1 , & V_45 ) ;
} while ( V_45 . V_50 );
V_111:
return V_1 ;
}
static void F_183 ( void * V_130 )
{
struct V_323 * V_128 = V_130 ;
struct V_171 * V_172 = V_128 -> V_47 -> V_182 ;
struct V_207 * V_208 = V_128 -> V_47 -> V_48 -> V_324 ;
if ( V_128 -> V_325 )
F_184 ( V_128 -> V_47 -> V_48 ) ;
F_91 ( V_128 -> V_47 ) ;
F_90 ( V_128 -> V_313 . V_165 ) ;
F_92 ( V_172 ) ;
F_93 ( V_208 ) ;
F_86 ( V_128 ) ;
}
static void F_185 ( struct V_46 * V_47 ,
T_4 V_173 )
{
F_26 ( & V_47 -> V_182 -> V_226 ) ;
if ( ! ( V_173 & V_52 ) )
F_135 ( V_213 , & V_47 -> V_174 ) ;
if ( ! ( V_173 & V_186 ) )
F_135 ( V_215 , & V_47 -> V_174 ) ;
F_135 ( V_217 , & V_47 -> V_174 ) ;
F_28 ( & V_47 -> V_182 -> V_226 ) ;
}
static void F_186 ( struct V_93 * V_94 , void * V_130 )
{
struct V_323 * V_128 = V_130 ;
struct V_46 * V_47 = V_128 -> V_47 ;
struct V_41 * V_42 = F_77 ( V_128 -> V_48 ) ;
F_2 ( L_30 , V_9 ) ;
if ( ! F_45 ( V_94 , & V_128 -> V_29 . V_133 ) )
return;
switch ( V_94 -> V_144 ) {
case 0 :
if ( V_128 -> V_325 )
F_187 ( V_47 -> V_48 ,
V_128 -> V_326 ) ;
F_107 ( V_47 , & V_128 -> V_29 . V_205 , 0 ) ;
F_29 ( V_42 , V_128 -> V_82 ) ;
F_185 ( V_47 ,
V_128 -> V_313 . V_173 ) ;
break;
case - V_58 :
case - V_77 :
case - V_56 :
case - V_57 :
if ( V_128 -> V_313 . V_173 == 0 )
break;
default:
if ( F_188 ( V_94 , V_42 , V_47 ) == - V_124 )
F_189 ( V_94 ) ;
}
F_190 ( V_128 -> V_313 . V_165 ) ;
F_158 ( V_128 -> V_48 , V_128 -> V_29 . V_311 ) ;
F_2 ( L_31 , V_9 , V_94 -> V_144 ) ;
}
static void F_191 ( struct V_93 * V_94 , void * V_130 )
{
struct V_323 * V_128 = V_130 ;
struct V_46 * V_47 = V_128 -> V_47 ;
int V_327 = 0 ;
F_2 ( L_30 , V_9 ) ;
if ( F_151 ( V_128 -> V_313 . V_165 , V_94 ) != 0 )
return;
V_94 -> V_267 . V_253 = & V_254 [ V_328 ] ;
V_128 -> V_313 . V_173 = V_52 | V_186 ;
F_26 ( & V_47 -> V_182 -> V_226 ) ;
if ( V_47 -> V_218 == 0 ) {
if ( V_47 -> V_214 == 0 ) {
V_327 |= F_36 ( V_213 , & V_47 -> V_174 ) ;
V_327 |= F_36 ( V_217 , & V_47 -> V_174 ) ;
V_128 -> V_313 . V_173 &= ~ V_52 ;
}
if ( V_47 -> V_216 == 0 ) {
V_327 |= F_36 ( V_215 , & V_47 -> V_174 ) ;
V_327 |= F_36 ( V_217 , & V_47 -> V_174 ) ;
V_128 -> V_313 . V_173 &= ~ V_186 ;
}
}
F_28 ( & V_47 -> V_182 -> V_226 ) ;
if ( ! V_327 ) {
V_94 -> V_269 = NULL ;
goto V_111;
}
if ( V_128 -> V_313 . V_173 == 0 ) {
V_94 -> V_267 . V_253 = & V_254 [ V_329 ] ;
if ( V_128 -> V_325 &&
F_192 ( V_128 -> V_48 , & V_128 -> V_326 ) ) {
F_52 ( & F_77 ( V_128 -> V_48 ) -> V_330 ,
V_94 , NULL ) ;
goto V_111;
}
}
F_73 ( V_128 -> V_29 . V_311 ) ;
V_128 -> V_82 = V_127 ;
if ( F_54 ( F_77 ( V_128 -> V_48 ) ,
& V_128 -> V_313 . V_132 ,
& V_128 -> V_29 . V_133 ,
V_94 ) )
goto V_111;
F_57 ( V_94 ) ;
V_111:
F_2 ( L_32 , V_9 ) ;
}
int F_193 ( struct V_46 * V_47 , T_5 V_177 , int V_331 , bool V_325 )
{
struct V_41 * V_42 = F_77 ( V_47 -> V_48 ) ;
struct V_323 * V_128 ;
struct V_171 * V_172 = V_47 -> V_182 ;
struct V_93 * V_94 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_329 ] ,
. V_258 = V_47 -> V_182 -> V_233 ,
} ;
struct V_137 V_259 = {
. V_139 = V_42 -> V_75 ,
. V_134 = & V_135 ,
. V_140 = & V_332 ,
. V_261 = V_262 ,
. V_174 = V_263 ,
} ;
int V_248 = - V_237 ;
V_128 = F_78 ( sizeof( * V_128 ) , V_177 ) ;
if ( V_128 == NULL )
goto V_111;
F_49 ( & V_128 -> V_313 . V_132 , & V_128 -> V_29 . V_133 , 1 ) ;
V_128 -> V_48 = V_47 -> V_48 ;
V_128 -> V_47 = V_47 ;
V_128 -> V_313 . V_184 = F_83 ( V_47 -> V_48 ) ;
V_128 -> V_313 . V_205 = & V_47 -> V_223 ;
V_128 -> V_313 . V_165 = F_79 ( & V_47 -> V_182 -> V_179 , V_177 ) ;
if ( V_128 -> V_313 . V_165 == NULL )
goto V_333;
V_128 -> V_313 . V_173 = 0 ;
V_128 -> V_313 . V_195 = V_42 -> V_198 ;
V_128 -> V_29 . V_311 = & V_128 -> V_311 ;
V_128 -> V_29 . V_165 = V_128 -> V_313 . V_165 ;
V_128 -> V_29 . V_42 = V_42 ;
V_128 -> V_325 = V_325 ;
F_80 ( V_128 -> V_48 -> V_324 ) ;
V_135 . V_256 = & V_128 -> V_313 ;
V_135 . V_257 = & V_128 -> V_29 ;
V_259 . V_142 = V_128 ;
V_94 = F_61 ( & V_259 ) ;
if ( F_62 ( V_94 ) )
return F_63 ( V_94 ) ;
V_248 = 0 ;
if ( V_331 )
V_248 = F_98 ( V_94 ) ;
F_64 ( V_94 ) ;
return V_248 ;
V_333:
F_86 ( V_128 ) ;
V_111:
if ( V_325 )
F_184 ( V_47 -> V_48 ) ;
F_91 ( V_47 ) ;
F_92 ( V_172 ) ;
return V_248 ;
}
static struct V_48 *
F_194 ( struct V_48 * V_147 , struct V_242 * V_243 , int V_185 , struct V_175 * V_334 )
{
struct V_46 * V_47 ;
V_47 = F_178 ( V_147 , V_243 -> V_13 , V_243 -> V_209 , V_185 , V_334 , V_243 -> V_303 ) ;
if ( F_62 ( V_47 ) )
return F_195 ( V_47 ) ;
V_243 -> V_47 = V_47 ;
return F_196 ( V_47 -> V_48 ) ;
}
static void F_197 ( struct V_242 * V_243 , int V_335 )
{
if ( V_243 -> V_47 == NULL )
return;
if ( V_335 )
F_198 ( V_243 -> V_47 , V_243 -> V_209 ) ;
else
F_133 ( V_243 -> V_47 , V_243 -> V_209 ) ;
}
static int F_199 ( struct V_41 * V_42 , struct V_336 * V_337 )
{
struct V_338 args = {
. V_337 = V_337 ,
} ;
struct V_339 V_29 = {} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_340 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
int V_248 ;
V_248 = F_68 ( V_42 -> V_75 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
if ( V_248 == 0 ) {
memcpy ( V_42 -> V_196 , V_29 . V_196 , sizeof( V_42 -> V_196 ) ) ;
V_42 -> V_78 &= ~ ( V_341 | V_342 |
V_343 | V_344 |
V_345 | V_346 | V_347 |
V_348 | V_349 |
V_350 | V_351 ) ;
if ( V_29 . V_196 [ 0 ] & V_352 )
V_42 -> V_78 |= V_341 ;
if ( V_29 . V_353 != 0 )
V_42 -> V_78 |= V_342 ;
if ( V_29 . V_354 != 0 )
V_42 -> V_78 |= V_343 ;
if ( V_29 . V_196 [ 0 ] & V_22 )
V_42 -> V_78 |= V_344 ;
if ( V_29 . V_196 [ 1 ] & V_355 )
V_42 -> V_78 |= V_345 ;
if ( V_29 . V_196 [ 1 ] & V_356 )
V_42 -> V_78 |= V_346 ;
if ( V_29 . V_196 [ 1 ] & V_357 )
V_42 -> V_78 |= V_347 ;
if ( V_29 . V_196 [ 1 ] & V_358 )
V_42 -> V_78 |= V_348 ;
if ( V_29 . V_196 [ 1 ] & V_297 )
V_42 -> V_78 |= V_349 ;
if ( V_29 . V_196 [ 1 ] & V_359 )
V_42 -> V_78 |= V_350 ;
if ( V_29 . V_196 [ 1 ] & V_300 )
V_42 -> V_78 |= V_351 ;
memcpy ( V_42 -> V_198 , V_29 . V_196 , sizeof( V_42 -> V_198 ) ) ;
V_42 -> V_198 [ 0 ] &= V_360 | V_361 ;
V_42 -> V_198 [ 1 ] &= V_359 | V_300 ;
V_42 -> V_362 = V_29 . V_362 ;
V_42 -> V_363 = V_29 . V_363 ;
}
return V_248 ;
}
int F_200 ( struct V_41 * V_42 , struct V_336 * V_337 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_42 ,
F_199 ( V_42 , V_337 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_201 ( struct V_41 * V_42 , struct V_336 * V_337 ,
struct V_364 * V_365 )
{
struct V_366 args = {
. V_195 = V_367 ,
} ;
struct V_368 V_29 = {
. V_42 = V_42 ,
. V_311 = V_365 -> V_311 ,
. V_184 = V_337 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_369 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
F_73 ( V_365 -> V_311 ) ;
return F_68 ( V_42 -> V_75 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
}
static int F_202 ( struct V_41 * V_42 , struct V_336 * V_337 ,
struct V_364 * V_365 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_201 ( V_42 , V_337 , V_365 ) ;
switch ( V_1 ) {
case 0 :
case - V_4 :
goto V_111;
default:
V_1 = F_16 ( V_42 , V_1 , & V_45 ) ;
}
} while ( V_45 . V_50 );
V_111:
return V_1 ;
}
static int F_203 ( struct V_41 * V_42 , struct V_336 * V_337 ,
struct V_364 * V_365 , T_7 V_370 )
{
struct V_371 * V_372 ;
int V_49 ;
V_372 = F_204 ( V_370 , V_42 -> V_75 ) ;
if ( ! V_372 ) {
V_49 = - V_10 ;
goto V_111;
}
V_49 = F_202 ( V_42 , V_337 , V_365 ) ;
V_111:
return V_49 ;
}
static int F_205 ( struct V_41 * V_42 , struct V_336 * V_337 ,
struct V_364 * V_365 )
{
int V_373 , V_374 , V_248 = 0 ;
T_7 V_375 [ V_376 ] ;
V_374 = F_206 ( & V_375 [ 0 ] ) ;
V_375 [ V_374 ] = V_377 ;
V_374 += 1 ;
for ( V_373 = 0 ; V_373 < V_374 ; V_373 ++ ) {
V_248 = F_203 ( V_42 , V_337 , V_365 , V_375 [ V_373 ] ) ;
if ( V_248 == - V_4 || V_248 == - V_322 )
continue;
break;
}
if ( V_248 == - V_322 )
V_248 = - V_5 ;
return V_248 ;
}
static int F_207 ( struct V_41 * V_42 , struct V_336 * V_337 ,
struct V_364 * V_365 )
{
int V_378 = V_42 -> V_27 -> V_379 ;
int V_248 = F_202 ( V_42 , V_337 , V_365 ) ;
if ( ( V_248 == - V_4 ) && ! ( V_42 -> V_174 & V_380 ) )
V_248 = V_381 [ V_378 ] -> F_208 ( V_42 , V_337 , V_365 ) ;
if ( V_248 == 0 )
V_248 = F_200 ( V_42 , V_337 ) ;
if ( V_248 == 0 )
V_248 = F_209 ( V_42 , V_337 , V_365 ) ;
return F_1 ( V_248 ) ;
}
static int F_210 ( struct V_34 * V_75 , struct V_48 * V_147 ,
const struct V_382 * V_193 , struct V_310 * V_311 ,
struct V_336 * V_337 )
{
int V_248 = - V_237 ;
struct V_383 * V_383 = NULL ;
struct V_384 * V_385 = NULL ;
V_383 = F_211 ( V_304 ) ;
if ( V_383 == NULL )
goto V_111;
V_385 = F_212 ( sizeof( struct V_384 ) , V_304 ) ;
if ( V_385 == NULL )
goto V_111;
V_248 = F_213 ( V_75 , V_147 , V_193 , V_385 , V_383 ) ;
if ( V_248 != 0 )
goto V_111;
if ( F_214 ( & F_77 ( V_147 ) -> V_386 , & V_385 -> V_311 . V_386 ) ) {
F_2 ( L_33
L_34 , V_9 , V_193 -> V_193 ) ;
V_248 = - V_10 ;
goto V_111;
}
F_215 ( & V_385 -> V_311 ) ;
memcpy ( V_311 , & V_385 -> V_311 , sizeof( struct V_310 ) ) ;
memset ( V_337 , 0 , sizeof( struct V_336 ) ) ;
V_111:
if ( V_383 )
F_216 ( V_383 ) ;
F_86 ( V_385 ) ;
return V_248 ;
}
static int F_161 ( struct V_41 * V_42 , struct V_336 * V_337 , struct V_310 * V_311 )
{
struct V_387 args = {
. V_184 = V_337 ,
. V_195 = V_42 -> V_196 ,
} ;
struct V_388 V_29 = {
. V_311 = V_311 ,
. V_42 = V_42 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_389 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
F_73 ( V_311 ) ;
return F_68 ( V_42 -> V_75 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
}
static int F_217 ( struct V_41 * V_42 , struct V_336 * V_337 , struct V_310 * V_311 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_42 ,
F_161 ( V_42 , V_337 , V_311 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int
F_218 ( struct V_13 * V_13 , struct V_310 * V_311 ,
struct V_175 * V_295 )
{
struct V_48 * V_48 = V_13 -> V_23 ;
struct V_258 * V_303 = NULL ;
struct V_46 * V_47 = NULL ;
int V_248 ;
if ( F_219 ( V_48 ) )
F_220 ( V_48 ) ;
F_73 ( V_311 ) ;
if ( V_295 -> V_201 & V_390 ) {
struct V_242 * V_243 ;
V_243 = F_221 ( V_295 -> V_391 ) ;
if ( V_243 ) {
V_303 = V_243 -> V_303 ;
V_47 = V_243 -> V_47 ;
}
}
if ( V_295 -> V_201 & V_321 )
V_295 -> V_201 &= ~ ( V_302 | V_392 | V_321 ) ;
V_248 = F_176 ( V_48 , V_303 , V_311 , V_295 , V_47 ) ;
if ( V_248 == 0 )
F_177 ( V_48 , V_295 ) ;
return V_248 ;
}
static int F_222 ( struct V_34 * V_35 , struct V_48 * V_147 ,
const struct V_382 * V_193 , struct V_336 * V_337 ,
struct V_310 * V_311 )
{
struct V_41 * V_42 = F_77 ( V_147 ) ;
int V_248 ;
struct V_393 args = {
. V_195 = V_42 -> V_196 ,
. V_394 = F_83 ( V_147 ) ,
. V_193 = V_193 ,
} ;
struct V_368 V_29 = {
. V_42 = V_42 ,
. V_311 = V_311 ,
. V_184 = V_337 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_395 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
F_73 ( V_311 ) ;
F_2 ( L_35 , V_193 -> V_193 ) ;
V_248 = F_68 ( V_35 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
F_2 ( L_36 , V_248 ) ;
return V_248 ;
}
static void F_223 ( struct V_310 * V_311 )
{
V_311 -> V_235 |= V_396 | V_397 |
V_398 | V_399 ;
V_311 -> V_209 = V_274 | V_400 | V_401 ;
V_311 -> V_402 = 2 ;
}
static int F_224 ( struct V_34 * * V_35 , struct V_48 * V_147 ,
struct V_382 * V_193 , struct V_336 * V_337 ,
struct V_310 * V_311 )
{
struct V_44 V_45 = { } ;
struct V_34 * V_75 = * V_35 ;
int V_1 ;
do {
V_1 = F_222 ( V_75 , V_147 , V_193 , V_337 , V_311 ) ;
switch ( V_1 ) {
case - V_7 :
V_1 = - V_244 ;
goto V_111;
case - V_403 :
V_1 = F_210 ( V_75 , V_147 , V_193 , V_311 , V_337 ) ;
goto V_111;
case - V_4 :
V_1 = - V_5 ;
if ( V_75 != * V_35 )
goto V_111;
V_75 = F_225 ( V_75 , V_147 , V_193 ) ;
if ( F_62 ( V_75 ) )
return F_63 ( V_75 ) ;
V_45 . V_50 = 1 ;
break;
default:
V_1 = F_16 ( F_77 ( V_147 ) , V_1 , & V_45 ) ;
}
} while ( V_45 . V_50 );
V_111:
if ( V_1 == 0 )
* V_35 = V_75 ;
else if ( V_75 != * V_35 )
F_226 ( V_75 ) ;
return V_1 ;
}
static int F_227 ( struct V_34 * V_35 , struct V_48 * V_147 , struct V_382 * V_193 ,
struct V_336 * V_337 , struct V_310 * V_311 )
{
int V_248 ;
struct V_34 * V_75 = F_228 ( V_147 ) ;
V_248 = F_224 ( & V_75 , V_147 , V_193 , V_337 , V_311 ) ;
if ( V_75 != F_228 ( V_147 ) ) {
F_226 ( V_75 ) ;
F_223 ( V_311 ) ;
}
return V_248 ;
}
struct V_34 *
F_229 ( struct V_48 * V_147 , struct V_382 * V_193 ,
struct V_336 * V_337 , struct V_310 * V_311 )
{
int V_248 ;
struct V_34 * V_75 = F_230 ( F_228 ( V_147 ) ) ;
V_248 = F_224 ( & V_75 , V_147 , V_193 , V_337 , V_311 ) ;
if ( V_248 < 0 ) {
F_226 ( V_75 ) ;
return F_119 ( V_248 ) ;
}
return V_75 ;
}
static int F_231 ( struct V_48 * V_48 , struct V_404 * V_405 )
{
struct V_41 * V_42 = F_77 ( V_48 ) ;
struct V_406 args = {
. V_184 = F_83 ( V_48 ) ,
. V_195 = V_42 -> V_198 ,
} ;
struct V_407 V_29 = {
. V_42 = V_42 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_408 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
. V_258 = V_405 -> V_303 ,
} ;
int V_209 = V_405 -> V_409 ;
int V_248 ;
if ( V_209 & V_410 )
args . V_411 |= V_412 ;
if ( F_232 ( V_48 -> V_413 ) ) {
if ( V_209 & V_414 )
args . V_411 |= V_415 | V_416 | V_417 ;
if ( V_209 & V_418 )
args . V_411 |= V_419 ;
} else {
if ( V_209 & V_414 )
args . V_411 |= V_415 | V_416 ;
if ( V_209 & V_418 )
args . V_411 |= V_420 ;
}
V_29 . V_311 = F_233 () ;
if ( V_29 . V_311 == NULL )
return - V_237 ;
V_248 = F_68 ( V_42 -> V_75 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
if ( ! V_248 ) {
V_405 -> V_409 = 0 ;
if ( V_29 . V_411 & V_412 )
V_405 -> V_409 |= V_410 ;
if ( V_29 . V_411 & ( V_415 | V_416 | V_417 ) )
V_405 -> V_409 |= V_414 ;
if ( V_29 . V_411 & ( V_419 | V_420 ) )
V_405 -> V_409 |= V_418 ;
F_158 ( V_48 , V_29 . V_311 ) ;
}
F_234 ( V_29 . V_311 ) ;
return V_248 ;
}
static int F_235 ( struct V_48 * V_48 , struct V_404 * V_405 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_48 ) ,
F_231 ( V_48 , V_405 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_236 ( struct V_48 * V_48 , struct V_383 * V_383 ,
unsigned int V_26 , unsigned int V_421 )
{
struct V_422 args = {
. V_184 = F_83 ( V_48 ) ,
. V_26 = V_26 ,
. V_421 = V_421 ,
. V_19 = & V_383 ,
} ;
struct V_423 V_29 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_424 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
return F_68 ( F_77 ( V_48 ) -> V_75 , F_77 ( V_48 ) , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
}
static int F_237 ( struct V_48 * V_48 , struct V_383 * V_383 ,
unsigned int V_26 , unsigned int V_421 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_48 ) ,
F_236 ( V_48 , V_383 , V_26 , V_421 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int
F_238 ( struct V_48 * V_147 , struct V_13 * V_13 , struct V_175 * V_295 ,
int V_174 , struct V_242 * V_243 )
{
struct V_13 * V_425 = V_13 ;
struct V_46 * V_47 ;
struct V_258 * V_303 = NULL ;
T_4 V_173 = 0 ;
int V_248 = 0 ;
if ( V_243 != NULL ) {
V_303 = V_243 -> V_303 ;
V_425 = V_243 -> V_13 ;
V_173 = V_243 -> V_209 ;
}
V_295 -> V_426 &= ~ F_239 () ;
V_47 = F_178 ( V_147 , V_425 , V_173 , V_174 , V_295 , V_303 ) ;
F_166 ( V_13 ) ;
if ( F_62 ( V_47 ) ) {
V_248 = F_63 ( V_47 ) ;
goto V_111;
}
F_240 ( V_13 , F_196 ( V_47 -> V_48 ) ) ;
F_241 ( V_13 , F_242 ( V_147 ) ) ;
if ( V_243 != NULL )
V_243 -> V_47 = V_47 ;
else
F_198 ( V_47 , V_173 ) ;
V_111:
return V_248 ;
}
static int F_243 ( struct V_48 * V_147 , struct V_382 * V_193 )
{
struct V_41 * V_42 = F_77 ( V_147 ) ;
struct V_427 args = {
. V_184 = F_83 ( V_147 ) ,
. V_193 . V_374 = V_193 -> V_374 ,
. V_193 . V_193 = V_193 -> V_193 ,
. V_195 = V_42 -> V_196 ,
} ;
struct V_428 V_29 = {
. V_42 = V_42 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_429 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
int V_248 = - V_237 ;
V_29 . V_164 = F_233 () ;
if ( V_29 . V_164 == NULL )
goto V_111;
V_248 = F_68 ( V_42 -> V_75 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 1 ) ;
if ( V_248 == 0 ) {
F_69 ( V_147 , & V_29 . V_149 ) ;
F_160 ( V_147 , V_29 . V_164 ) ;
}
F_234 ( V_29 . V_164 ) ;
V_111:
return V_248 ;
}
static int F_244 ( struct V_48 * V_147 , struct V_382 * V_193 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_147 ) ,
F_243 ( V_147 , V_193 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static void F_245 ( struct V_134 * V_135 , struct V_48 * V_147 )
{
struct V_41 * V_42 = F_77 ( V_147 ) ;
struct V_427 * args = V_135 -> V_256 ;
struct V_428 * V_29 = V_135 -> V_257 ;
args -> V_195 = V_42 -> V_198 ;
V_29 -> V_42 = V_42 ;
V_135 -> V_253 = & V_254 [ V_429 ] ;
F_49 ( & args -> V_132 , & V_29 -> V_133 , 1 ) ;
}
static void F_246 ( struct V_93 * V_94 , struct V_430 * V_130 )
{
if ( F_54 ( F_77 ( V_130 -> V_147 ) ,
& V_130 -> args . V_132 ,
& V_130 -> V_29 . V_133 ,
V_94 ) )
return;
F_57 ( V_94 ) ;
}
static int F_247 ( struct V_93 * V_94 , struct V_48 * V_147 )
{
struct V_428 * V_29 = V_94 -> V_267 . V_257 ;
if ( ! F_45 ( V_94 , & V_29 -> V_133 ) )
return 0 ;
if ( F_188 ( V_94 , V_29 -> V_42 , NULL ) == - V_124 )
return 0 ;
F_69 ( V_147 , & V_29 -> V_149 ) ;
F_160 ( V_147 , V_29 -> V_164 ) ;
return 1 ;
}
static void F_248 ( struct V_134 * V_135 , struct V_48 * V_147 )
{
struct V_41 * V_42 = F_77 ( V_147 ) ;
struct V_431 * V_313 = V_135 -> V_256 ;
struct V_432 * V_29 = V_135 -> V_257 ;
V_135 -> V_253 = & V_254 [ V_433 ] ;
V_313 -> V_195 = V_42 -> V_196 ;
V_29 -> V_42 = V_42 ;
F_49 ( & V_313 -> V_132 , & V_29 -> V_133 , 1 ) ;
}
static void F_249 ( struct V_93 * V_94 , struct V_434 * V_130 )
{
if ( F_54 ( F_77 ( V_130 -> V_435 ) ,
& V_130 -> args . V_132 ,
& V_130 -> V_29 . V_133 ,
V_94 ) )
return;
F_57 ( V_94 ) ;
}
static int F_250 ( struct V_93 * V_94 , struct V_48 * V_435 ,
struct V_48 * V_436 )
{
struct V_432 * V_29 = V_94 -> V_267 . V_257 ;
if ( ! F_45 ( V_94 , & V_29 -> V_133 ) )
return 0 ;
if ( F_188 ( V_94 , V_29 -> V_42 , NULL ) == - V_124 )
return 0 ;
F_69 ( V_435 , & V_29 -> V_437 ) ;
F_160 ( V_435 , V_29 -> V_438 ) ;
F_69 ( V_436 , & V_29 -> V_439 ) ;
F_160 ( V_436 , V_29 -> V_440 ) ;
return 1 ;
}
static int F_251 ( struct V_48 * V_435 , struct V_382 * V_441 ,
struct V_48 * V_436 , struct V_382 * V_442 )
{
struct V_41 * V_42 = F_77 ( V_435 ) ;
struct V_431 V_313 = {
. V_435 = F_83 ( V_435 ) ,
. V_436 = F_83 ( V_436 ) ,
. V_441 = V_441 ,
. V_442 = V_442 ,
. V_195 = V_42 -> V_196 ,
} ;
struct V_432 V_29 = {
. V_42 = V_42 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_433 ] ,
. V_256 = & V_313 ,
. V_257 = & V_29 ,
} ;
int V_248 = - V_237 ;
V_29 . V_438 = F_233 () ;
V_29 . V_440 = F_233 () ;
if ( V_29 . V_438 == NULL || V_29 . V_440 == NULL )
goto V_111;
V_248 = F_68 ( V_42 -> V_75 , V_42 , & V_135 , & V_313 . V_132 , & V_29 . V_133 , 1 ) ;
if ( ! V_248 ) {
F_69 ( V_435 , & V_29 . V_437 ) ;
F_160 ( V_435 , V_29 . V_438 ) ;
F_69 ( V_436 , & V_29 . V_439 ) ;
F_160 ( V_436 , V_29 . V_440 ) ;
}
V_111:
F_234 ( V_29 . V_440 ) ;
F_234 ( V_29 . V_438 ) ;
return V_248 ;
}
static int F_252 ( struct V_48 * V_435 , struct V_382 * V_441 ,
struct V_48 * V_436 , struct V_382 * V_442 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_435 ) ,
F_251 ( V_435 , V_441 ,
V_436 , V_442 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_253 ( struct V_48 * V_48 , struct V_48 * V_147 , struct V_382 * V_193 )
{
struct V_41 * V_42 = F_77 ( V_48 ) ;
struct V_443 V_313 = {
. V_184 = F_83 ( V_48 ) ,
. V_394 = F_83 ( V_147 ) ,
. V_193 = V_193 ,
. V_195 = V_42 -> V_196 ,
} ;
struct V_444 V_29 = {
. V_42 = V_42 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_445 ] ,
. V_256 = & V_313 ,
. V_257 = & V_29 ,
} ;
int V_248 = - V_237 ;
V_29 . V_311 = F_233 () ;
V_29 . V_164 = F_233 () ;
if ( V_29 . V_311 == NULL || V_29 . V_164 == NULL )
goto V_111;
V_248 = F_68 ( V_42 -> V_75 , V_42 , & V_135 , & V_313 . V_132 , & V_29 . V_133 , 1 ) ;
if ( ! V_248 ) {
F_69 ( V_147 , & V_29 . V_149 ) ;
F_160 ( V_147 , V_29 . V_164 ) ;
F_160 ( V_48 , V_29 . V_311 ) ;
}
V_111:
F_234 ( V_29 . V_164 ) ;
F_234 ( V_29 . V_311 ) ;
return V_248 ;
}
static int F_254 ( struct V_48 * V_48 , struct V_48 * V_147 , struct V_382 * V_193 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_48 ) ,
F_253 ( V_48 , V_147 , V_193 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static struct V_446 * F_255 ( struct V_48 * V_147 ,
struct V_382 * V_193 , struct V_175 * V_295 , T_3 V_447 )
{
struct V_446 * V_130 ;
V_130 = F_78 ( sizeof( * V_130 ) , V_304 ) ;
if ( V_130 != NULL ) {
struct V_41 * V_42 = F_77 ( V_147 ) ;
V_130 -> V_135 . V_253 = & V_254 [ V_448 ] ;
V_130 -> V_135 . V_256 = & V_130 -> V_313 ;
V_130 -> V_135 . V_257 = & V_130 -> V_29 ;
V_130 -> V_313 . V_394 = F_83 ( V_147 ) ;
V_130 -> V_313 . V_42 = V_42 ;
V_130 -> V_313 . V_193 = V_193 ;
V_130 -> V_313 . V_176 = V_295 ;
V_130 -> V_313 . V_447 = V_447 ;
V_130 -> V_313 . V_195 = V_42 -> V_196 ;
V_130 -> V_29 . V_42 = V_42 ;
V_130 -> V_29 . V_184 = & V_130 -> V_184 ;
V_130 -> V_29 . V_311 = & V_130 -> V_311 ;
V_130 -> V_29 . V_449 = & V_130 -> V_449 ;
F_73 ( V_130 -> V_29 . V_311 ) ;
F_73 ( V_130 -> V_29 . V_449 ) ;
}
return V_130 ;
}
static int F_256 ( struct V_48 * V_147 , struct V_13 * V_13 , struct V_446 * V_130 )
{
int V_248 = F_68 ( F_77 ( V_147 ) -> V_75 , F_77 ( V_147 ) , & V_130 -> V_135 ,
& V_130 -> V_313 . V_132 , & V_130 -> V_29 . V_133 , 1 ) ;
if ( V_248 == 0 ) {
F_69 ( V_147 , & V_130 -> V_29 . V_450 ) ;
F_160 ( V_147 , V_130 -> V_29 . V_449 ) ;
V_248 = F_257 ( V_13 , V_130 -> V_29 . V_184 , V_130 -> V_29 . V_311 ) ;
}
return V_248 ;
}
static void F_258 ( struct V_446 * V_130 )
{
F_86 ( V_130 ) ;
}
static int F_259 ( struct V_48 * V_147 , struct V_13 * V_13 ,
struct V_383 * V_383 , unsigned int V_374 , struct V_175 * V_295 )
{
struct V_446 * V_130 ;
int V_248 = - V_451 ;
if ( V_374 > V_452 )
goto V_111;
V_248 = - V_237 ;
V_130 = F_255 ( V_147 , & V_13 -> V_194 , V_295 , V_453 ) ;
if ( V_130 == NULL )
goto V_111;
V_130 -> V_135 . V_253 = & V_254 [ V_454 ] ;
V_130 -> V_313 . V_203 . V_455 . V_19 = & V_383 ;
V_130 -> V_313 . V_203 . V_455 . V_374 = V_374 ;
V_248 = F_256 ( V_147 , V_13 , V_130 ) ;
F_258 ( V_130 ) ;
V_111:
return V_248 ;
}
static int F_260 ( struct V_48 * V_147 , struct V_13 * V_13 ,
struct V_383 * V_383 , unsigned int V_374 , struct V_175 * V_295 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_147 ) ,
F_259 ( V_147 , V_13 , V_383 ,
V_374 , V_295 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_261 ( struct V_48 * V_147 , struct V_13 * V_13 ,
struct V_175 * V_295 )
{
struct V_446 * V_130 ;
int V_248 = - V_237 ;
V_130 = F_255 ( V_147 , & V_13 -> V_194 , V_295 , V_456 ) ;
if ( V_130 == NULL )
goto V_111;
V_248 = F_256 ( V_147 , V_13 , V_130 ) ;
F_258 ( V_130 ) ;
V_111:
return V_248 ;
}
static int F_262 ( struct V_48 * V_147 , struct V_13 * V_13 ,
struct V_175 * V_295 )
{
struct V_44 V_45 = { } ;
int V_1 ;
V_295 -> V_426 &= ~ F_239 () ;
do {
V_1 = F_16 ( F_77 ( V_147 ) ,
F_261 ( V_147 , V_13 , V_295 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_263 ( struct V_13 * V_13 , struct V_258 * V_303 ,
T_1 V_11 , struct V_383 * * V_19 , unsigned int V_18 , int V_457 )
{
struct V_48 * V_147 = V_13 -> V_23 ;
struct V_14 args = {
. V_184 = F_83 ( V_147 ) ,
. V_19 = V_19 ,
. V_26 = 0 ,
. V_18 = V_18 ,
. V_195 = F_77 ( V_13 -> V_23 ) -> V_196 ,
. V_457 = V_457 ,
} ;
struct V_458 V_29 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_459 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
. V_258 = V_303 ,
} ;
int V_248 ;
F_2 ( L_37 , V_9 ,
V_13 -> V_25 -> V_194 . V_193 ,
V_13 -> V_194 . V_193 ,
( unsigned long long ) V_11 ) ;
F_3 ( V_11 , F_264 ( V_147 ) , V_13 , & args ) ;
V_29 . V_26 = args . V_26 ;
V_248 = F_68 ( F_77 ( V_147 ) -> V_75 , F_77 ( V_147 ) , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
if ( V_248 >= 0 ) {
memcpy ( F_264 ( V_147 ) , V_29 . V_12 . V_130 , V_460 ) ;
V_248 += args . V_26 ;
}
F_265 ( V_147 ) ;
F_2 ( L_38 , V_9 , V_248 ) ;
return V_248 ;
}
static int F_266 ( struct V_13 * V_13 , struct V_258 * V_303 ,
T_1 V_11 , struct V_383 * * V_19 , unsigned int V_18 , int V_457 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_13 -> V_23 ) ,
F_263 ( V_13 , V_303 , V_11 ,
V_19 , V_18 , V_457 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_267 ( struct V_48 * V_147 , struct V_13 * V_13 ,
struct V_175 * V_295 , T_8 V_461 )
{
struct V_446 * V_130 ;
int V_209 = V_295 -> V_426 ;
int V_248 = - V_237 ;
F_4 ( ! ( V_295 -> V_201 & V_462 ) ) ;
F_4 ( ! F_268 ( V_209 ) && ! F_269 ( V_209 ) && ! F_270 ( V_209 ) && ! F_271 ( V_209 ) ) ;
V_130 = F_255 ( V_147 , & V_13 -> V_194 , V_295 , V_463 ) ;
if ( V_130 == NULL )
goto V_111;
if ( F_268 ( V_209 ) )
V_130 -> V_313 . V_447 = V_464 ;
else if ( F_269 ( V_209 ) ) {
V_130 -> V_313 . V_447 = V_465 ;
V_130 -> V_313 . V_203 . V_466 . V_467 = F_272 ( V_461 ) ;
V_130 -> V_313 . V_203 . V_466 . V_468 = F_273 ( V_461 ) ;
}
else if ( F_270 ( V_209 ) ) {
V_130 -> V_313 . V_447 = V_469 ;
V_130 -> V_313 . V_203 . V_466 . V_467 = F_272 ( V_461 ) ;
V_130 -> V_313 . V_203 . V_466 . V_468 = F_273 ( V_461 ) ;
}
V_248 = F_256 ( V_147 , V_13 , V_130 ) ;
F_258 ( V_130 ) ;
V_111:
return V_248 ;
}
static int F_274 ( struct V_48 * V_147 , struct V_13 * V_13 ,
struct V_175 * V_295 , T_8 V_461 )
{
struct V_44 V_45 = { } ;
int V_1 ;
V_295 -> V_426 &= ~ F_239 () ;
do {
V_1 = F_16 ( F_77 ( V_147 ) ,
F_267 ( V_147 , V_13 , V_295 , V_461 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_275 ( struct V_41 * V_42 , struct V_336 * V_337 ,
struct V_470 * V_471 )
{
struct V_472 args = {
. V_184 = V_337 ,
. V_195 = V_42 -> V_196 ,
} ;
struct V_473 V_29 = {
. V_471 = V_471 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_474 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
F_73 ( V_471 -> V_311 ) ;
return F_68 ( V_42 -> V_75 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
}
static int F_276 ( struct V_41 * V_42 , struct V_336 * V_337 , struct V_470 * V_471 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_42 ,
F_275 ( V_42 , V_337 , V_471 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_277 ( struct V_41 * V_42 , struct V_336 * V_337 ,
struct V_364 * V_475 )
{
struct V_476 args = {
. V_184 = V_337 ,
. V_195 = V_42 -> V_196 ,
} ;
struct V_477 V_29 = {
. V_475 = V_475 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_478 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
return F_68 ( V_42 -> V_75 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
}
static int F_209 ( struct V_41 * V_42 , struct V_336 * V_337 , struct V_364 * V_475 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_42 ,
F_277 ( V_42 , V_337 , V_475 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_278 ( struct V_41 * V_42 , struct V_336 * V_337 , struct V_364 * V_475 )
{
F_73 ( V_475 -> V_311 ) ;
return F_209 ( V_42 , V_337 , V_475 ) ;
}
static int F_279 ( struct V_41 * V_42 , struct V_336 * V_337 ,
struct V_479 * V_480 )
{
struct V_481 args = {
. V_184 = V_337 ,
. V_195 = V_42 -> V_196 ,
} ;
struct V_482 V_29 = {
. V_480 = V_480 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_483 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
if ( ( args . V_195 [ 0 ] & V_484 [ 0 ] ) == 0 ) {
memset ( V_480 , 0 , sizeof( * V_480 ) ) ;
return 0 ;
}
F_73 ( V_480 -> V_311 ) ;
return F_68 ( V_42 -> V_75 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
}
static int F_280 ( struct V_41 * V_42 , struct V_336 * V_337 ,
struct V_479 * V_480 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_42 ,
F_279 ( V_42 , V_337 , V_480 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
void F_281 ( struct V_485 * V_130 )
{
F_265 ( V_130 -> V_48 ) ;
}
static int F_282 ( struct V_93 * V_94 , struct V_485 * V_130 )
{
struct V_41 * V_42 = F_77 ( V_130 -> V_48 ) ;
if ( F_188 ( V_94 , V_42 , V_130 -> args . V_486 -> V_47 ) == - V_124 ) {
F_189 ( V_94 ) ;
return - V_124 ;
}
F_281 ( V_130 ) ;
if ( V_94 -> V_144 > 0 )
F_29 ( V_42 , V_130 -> V_82 ) ;
return 0 ;
}
static int F_283 ( struct V_93 * V_94 , struct V_485 * V_130 )
{
F_2 ( L_17 , V_9 ) ;
if ( ! F_45 ( V_94 , & V_130 -> V_29 . V_133 ) )
return - V_124 ;
return V_130 -> V_487 ? V_130 -> V_487 ( V_94 , V_130 ) :
F_282 ( V_94 , V_130 ) ;
}
static void F_284 ( struct V_485 * V_130 , struct V_134 * V_135 )
{
V_130 -> V_82 = V_127 ;
V_130 -> V_487 = F_282 ;
V_135 -> V_253 = & V_254 [ V_488 ] ;
F_49 ( & V_130 -> args . V_132 , & V_130 -> V_29 . V_133 , 0 ) ;
}
static void F_285 ( struct V_93 * V_94 , struct V_485 * V_130 )
{
if ( F_54 ( F_77 ( V_130 -> V_48 ) ,
& V_130 -> args . V_132 ,
& V_130 -> V_29 . V_133 ,
V_94 ) )
return;
F_57 ( V_94 ) ;
}
void F_286 ( struct V_93 * V_94 , struct V_485 * V_130 )
{
F_2 ( L_39 , V_9 ) ;
F_287 ( V_130 -> V_489 ) ;
V_130 -> V_489 = NULL ;
V_130 -> args . V_490 = V_130 -> V_491 ;
V_130 -> V_492 = NULL ;
V_130 -> args . V_184 = F_83 ( V_130 -> V_48 ) ;
V_130 -> V_487 = F_282 ;
V_94 -> V_493 = V_130 -> V_494 ;
F_288 ( V_94 , F_228 ( V_130 -> V_48 ) ) ;
}
static int F_289 ( struct V_93 * V_94 , struct V_495 * V_130 )
{
struct V_48 * V_48 = V_130 -> V_48 ;
if ( F_188 ( V_94 , F_77 ( V_48 ) , V_130 -> args . V_486 -> V_47 ) == - V_124 ) {
F_189 ( V_94 ) ;
return - V_124 ;
}
if ( V_94 -> V_144 >= 0 ) {
F_29 ( F_77 ( V_48 ) , V_130 -> V_82 ) ;
F_290 ( V_48 , V_130 -> V_29 . V_311 ) ;
}
return 0 ;
}
static int F_291 ( struct V_93 * V_94 , struct V_495 * V_130 )
{
if ( ! F_45 ( V_94 , & V_130 -> V_29 . V_133 ) )
return - V_124 ;
return V_130 -> V_496 ? V_130 -> V_496 ( V_94 , V_130 ) :
F_289 ( V_94 , V_130 ) ;
}
void F_292 ( struct V_93 * V_94 , struct V_495 * V_130 )
{
F_2 ( L_39 , V_9 ) ;
F_287 ( V_130 -> V_489 ) ;
V_130 -> V_489 = NULL ;
V_130 -> V_492 = NULL ;
V_130 -> V_496 = F_289 ;
V_130 -> args . V_184 = F_83 ( V_130 -> V_48 ) ;
V_130 -> args . V_195 = V_130 -> V_29 . V_42 -> V_198 ;
V_130 -> args . V_490 = V_130 -> V_491 ;
V_130 -> V_29 . V_311 = & V_130 -> V_311 ;
V_94 -> V_493 = V_130 -> V_494 ;
F_288 ( V_94 , F_228 ( V_130 -> V_48 ) ) ;
}
static void F_293 ( struct V_495 * V_130 , struct V_134 * V_135 )
{
struct V_41 * V_42 = F_77 ( V_130 -> V_48 ) ;
if ( V_130 -> V_489 ) {
V_130 -> args . V_195 = NULL ;
V_130 -> V_29 . V_311 = NULL ;
} else
V_130 -> args . V_195 = V_42 -> V_198 ;
if ( ! V_130 -> V_496 )
V_130 -> V_496 = F_289 ;
V_130 -> V_29 . V_42 = V_42 ;
V_130 -> V_82 = V_127 ;
V_135 -> V_253 = & V_254 [ V_497 ] ;
F_49 ( & V_130 -> args . V_132 , & V_130 -> V_29 . V_133 , 1 ) ;
}
static void F_294 ( struct V_93 * V_94 , struct V_495 * V_130 )
{
if ( F_54 ( F_77 ( V_130 -> V_48 ) ,
& V_130 -> args . V_132 ,
& V_130 -> V_29 . V_133 ,
V_94 ) )
return;
F_57 ( V_94 ) ;
}
static int F_295 ( struct V_93 * V_94 , struct V_495 * V_130 )
{
struct V_48 * V_48 = V_130 -> V_48 ;
if ( F_188 ( V_94 , F_77 ( V_48 ) , NULL ) == - V_124 ) {
F_189 ( V_94 ) ;
return - V_124 ;
}
F_158 ( V_48 , V_130 -> V_29 . V_311 ) ;
return 0 ;
}
static int F_296 ( struct V_93 * V_94 , struct V_495 * V_130 )
{
if ( ! F_45 ( V_94 , & V_130 -> V_29 . V_133 ) )
return - V_124 ;
return V_130 -> V_496 ( V_94 , V_130 ) ;
}
static void F_297 ( struct V_495 * V_130 , struct V_134 * V_135 )
{
struct V_41 * V_42 = F_77 ( V_130 -> V_48 ) ;
if ( V_130 -> V_489 ) {
V_130 -> args . V_195 = NULL ;
V_130 -> V_29 . V_311 = NULL ;
} else
V_130 -> args . V_195 = V_42 -> V_198 ;
if ( ! V_130 -> V_496 )
V_130 -> V_496 = F_295 ;
V_130 -> V_29 . V_42 = V_42 ;
V_135 -> V_253 = & V_254 [ V_498 ] ;
F_49 ( & V_130 -> args . V_132 , & V_130 -> V_29 . V_133 , 1 ) ;
}
static void F_298 ( void * V_128 )
{
struct V_499 * V_130 = V_128 ;
struct V_27 * V_28 = V_130 -> V_75 ;
if ( F_299 ( & V_28 -> V_500 ) > 1 )
F_300 ( V_28 ) ;
F_301 ( V_28 ) ;
F_86 ( V_130 ) ;
}
static void F_302 ( struct V_93 * V_94 , void * V_128 )
{
struct V_499 * V_130 = V_128 ;
struct V_27 * V_28 = V_130 -> V_75 ;
unsigned long V_82 = V_130 -> V_82 ;
if ( V_94 -> V_144 < 0 ) {
if ( F_36 ( V_501 , & V_28 -> V_502 ) == 0 )
return;
if ( V_94 -> V_144 != V_503 ) {
F_21 ( V_28 ) ;
return;
}
F_303 ( V_28 ) ;
}
F_25 ( V_28 , V_82 ) ;
}
static int F_304 ( struct V_27 * V_28 , struct V_258 * V_303 , unsigned V_504 )
{
struct V_134 V_135 = {
. V_253 = & V_254 [ V_505 ] ,
. V_256 = V_28 ,
. V_258 = V_303 ,
} ;
struct V_499 * V_130 ;
if ( V_504 == 0 )
return 0 ;
if ( ! F_305 ( & V_28 -> V_500 ) )
return - V_10 ;
V_130 = F_212 ( sizeof( * V_130 ) , V_245 ) ;
if ( V_130 == NULL )
return - V_237 ;
V_130 -> V_75 = V_28 ;
V_130 -> V_82 = V_127 ;
return F_306 ( V_28 -> V_506 , & V_135 , V_507 ,
& V_508 , V_130 ) ;
}
static int F_307 ( struct V_27 * V_28 , struct V_258 * V_303 )
{
struct V_134 V_135 = {
. V_253 = & V_254 [ V_505 ] ,
. V_256 = V_28 ,
. V_258 = V_303 ,
} ;
unsigned long V_509 = V_127 ;
int V_248 ;
V_248 = F_67 ( V_28 -> V_506 , & V_135 , 0 ) ;
if ( V_248 < 0 )
return V_248 ;
F_25 ( V_28 , V_509 ) ;
return 0 ;
}
static inline int F_308 ( struct V_41 * V_42 )
{
return ( V_42 -> V_78 & V_341 )
&& ( V_42 -> V_362 & V_510 )
&& ( V_42 -> V_362 & V_511 ) ;
}
static int F_309 ( const void * V_512 , T_9 V_513 ,
struct V_383 * * V_19 , unsigned int * V_26 )
{
struct V_383 * V_514 , * * V_515 ;
int V_516 = 0 ;
T_9 V_374 ;
V_515 = V_19 ;
do {
V_374 = F_310 ( T_9 , V_517 , V_513 ) ;
V_514 = F_211 ( V_304 ) ;
if ( V_514 == NULL )
goto V_518;
memcpy ( F_311 ( V_514 ) , V_512 , V_374 ) ;
V_512 += V_374 ;
V_513 -= V_374 ;
* V_19 ++ = V_514 ;
V_516 ++ ;
} while ( V_513 != 0 );
return V_516 ;
V_518:
for(; V_516 > 0 ; V_516 -- )
F_216 ( V_515 [ V_516 - 1 ] ) ;
return - V_237 ;
}
static void F_312 ( struct V_48 * V_48 , struct V_519 * V_520 )
{
struct V_150 * V_151 = F_70 ( V_48 ) ;
F_26 ( & V_48 -> V_152 ) ;
F_86 ( V_151 -> V_521 ) ;
V_151 -> V_521 = V_520 ;
F_28 ( & V_48 -> V_152 ) ;
}
static void F_313 ( struct V_48 * V_48 )
{
F_312 ( V_48 , NULL ) ;
}
static inline T_10 F_314 ( struct V_48 * V_48 , char * V_512 , T_9 V_513 )
{
struct V_150 * V_151 = F_70 ( V_48 ) ;
struct V_519 * V_520 ;
int V_49 = - V_244 ;
F_26 ( & V_48 -> V_152 ) ;
V_520 = V_151 -> V_521 ;
if ( V_520 == NULL )
goto V_111;
if ( V_512 == NULL )
goto V_522;
if ( V_520 -> V_523 == 0 )
goto V_111;
V_49 = - V_524 ;
if ( V_520 -> V_374 > V_513 )
goto V_111;
memcpy ( V_512 , V_520 -> V_130 , V_520 -> V_374 ) ;
V_522:
V_49 = V_520 -> V_374 ;
V_111:
F_28 ( & V_48 -> V_152 ) ;
return V_49 ;
}
static void F_315 ( struct V_48 * V_48 , struct V_383 * * V_19 , T_9 V_26 , T_9 V_525 )
{
struct V_519 * V_520 ;
if ( V_19 && V_525 <= V_526 ) {
V_520 = F_212 ( sizeof( * V_520 ) + V_525 , V_304 ) ;
if ( V_520 == NULL )
goto V_111;
V_520 -> V_523 = 1 ;
F_316 ( V_520 -> V_130 , V_19 , V_26 , V_525 ) ;
} else {
V_520 = F_212 ( sizeof( * V_520 ) , V_304 ) ;
if ( V_520 == NULL )
goto V_111;
V_520 -> V_523 = 0 ;
}
V_520 -> V_374 = V_525 ;
V_111:
F_312 ( V_48 , V_520 ) ;
}
static T_10 F_317 ( struct V_48 * V_48 , void * V_512 , T_9 V_513 )
{
struct V_383 * V_19 [ V_527 ] = { NULL , } ;
struct V_528 args = {
. V_184 = F_83 ( V_48 ) ,
. V_529 = V_19 ,
. V_525 = V_513 ,
} ;
struct V_530 V_29 = {
. V_525 = V_513 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_531 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
int V_49 = - V_237 , V_532 , V_373 , V_525 = 0 ;
V_532 = ( V_513 + V_526 - 1 ) >> V_533 ;
if ( V_532 == 0 )
V_532 = 1 ;
V_532 ++ ;
for ( V_373 = 0 ; V_373 < V_532 ; V_373 ++ ) {
V_19 [ V_373 ] = F_211 ( V_304 ) ;
if ( ! V_19 [ V_373 ] )
goto V_252;
}
V_29 . V_534 = F_211 ( V_304 ) ;
if ( ! V_29 . V_534 )
goto V_252;
args . V_525 = V_532 * V_526 ;
args . V_535 = 0 ;
if ( V_512 == NULL )
V_29 . V_536 |= V_537 ;
F_2 ( L_40 ,
V_9 , V_512 , V_513 , V_532 , args . V_525 ) ;
V_49 = F_68 ( F_77 ( V_48 ) -> V_75 , F_77 ( V_48 ) ,
& V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
if ( V_49 )
goto V_252;
V_525 = V_29 . V_525 - V_29 . V_538 ;
if ( V_525 > args . V_525 )
F_315 ( V_48 , NULL , 0 , V_525 ) ;
else
F_315 ( V_48 , V_19 , V_29 . V_538 ,
V_525 ) ;
if ( V_512 ) {
V_49 = - V_524 ;
if ( V_525 > V_513 )
goto V_252;
F_316 ( V_512 , V_19 , V_29 . V_538 ,
V_525 ) ;
}
V_49 = V_525 ;
V_252:
for ( V_373 = 0 ; V_373 < V_532 ; V_373 ++ )
if ( V_19 [ V_373 ] )
F_216 ( V_19 [ V_373 ] ) ;
if ( V_29 . V_534 )
F_216 ( V_29 . V_534 ) ;
return V_49 ;
}
static T_10 F_318 ( struct V_48 * V_48 , void * V_512 , T_9 V_513 )
{
struct V_44 V_45 = { } ;
T_10 V_49 ;
do {
V_49 = F_317 ( V_48 , V_512 , V_513 ) ;
if ( V_49 >= 0 )
break;
V_49 = F_16 ( F_77 ( V_48 ) , V_49 , & V_45 ) ;
} while ( V_45 . V_50 );
return V_49 ;
}
static T_10 F_319 ( struct V_48 * V_48 , void * V_512 , T_9 V_513 )
{
struct V_41 * V_42 = F_77 ( V_48 ) ;
int V_49 ;
if ( ! F_308 ( V_42 ) )
return - V_539 ;
V_49 = F_320 ( V_42 , V_48 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( F_70 ( V_48 ) -> V_153 & V_540 )
F_321 ( V_48 ) ;
V_49 = F_314 ( V_48 , V_512 , V_513 ) ;
if ( V_49 != - V_244 )
return V_49 ;
return F_318 ( V_48 , V_512 , V_513 ) ;
}
static int F_322 ( struct V_48 * V_48 , const void * V_512 , T_9 V_513 )
{
struct V_41 * V_42 = F_77 ( V_48 ) ;
struct V_383 * V_19 [ V_527 ] ;
struct V_541 V_313 = {
. V_184 = F_83 ( V_48 ) ,
. V_529 = V_19 ,
. V_525 = V_513 ,
} ;
struct V_542 V_29 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_543 ] ,
. V_256 = & V_313 ,
. V_257 = & V_29 ,
} ;
int V_49 , V_373 ;
if ( ! F_308 ( V_42 ) )
return - V_539 ;
V_373 = F_309 ( V_512 , V_513 , V_313 . V_529 , & V_313 . V_535 ) ;
if ( V_373 < 0 )
return V_373 ;
F_18 ( V_48 ) ;
V_49 = F_68 ( V_42 -> V_75 , V_42 , & V_135 , & V_313 . V_132 , & V_29 . V_133 , 1 ) ;
for (; V_373 > 0 ; V_373 -- )
F_323 ( V_19 [ V_373 - 1 ] ) ;
F_26 ( & V_48 -> V_152 ) ;
F_70 ( V_48 ) -> V_153 |= V_154 ;
F_28 ( & V_48 -> V_152 ) ;
F_324 ( V_48 ) ;
F_321 ( V_48 ) ;
return V_49 ;
}
static int F_325 ( struct V_48 * V_48 , const void * V_512 , T_9 V_513 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_48 ) ,
F_322 ( V_48 , V_512 , V_513 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int
F_188 ( struct V_93 * V_94 , const struct V_41 * V_42 , struct V_46 * V_47 )
{
struct V_27 * V_28 = V_42 -> V_27 ;
if ( V_94 -> V_144 >= 0 )
return 0 ;
switch( V_94 -> V_144 ) {
case - V_54 :
case - V_55 :
case - V_56 :
if ( V_47 == NULL )
break;
F_20 ( V_47 -> V_48 ) ;
case - V_51 :
if ( V_47 == NULL )
break;
F_19 ( V_42 , V_47 ) ;
goto V_53;
case - V_57 :
if ( V_47 != NULL )
F_19 ( V_42 , V_47 ) ;
case - V_58 :
case - V_59 :
F_21 ( V_28 ) ;
goto V_53;
#if F_22 ( V_60 )
case - V_61 :
case - V_62 :
case - V_63 :
case - V_65 :
case - V_64 :
case - V_66 :
case - V_67 :
F_2 ( L_41 , V_9 ,
V_94 -> V_144 ) ;
F_23 ( V_28 -> V_68 ) ;
V_94 -> V_144 = 0 ;
return - V_124 ;
#endif
case - V_73 :
F_326 ( V_42 , V_544 ) ;
case - V_72 :
case - V_74 :
F_44 ( V_94 , V_38 ) ;
V_94 -> V_144 = 0 ;
return - V_124 ;
case - V_76 :
case - V_77 :
V_94 -> V_144 = 0 ;
return - V_124 ;
}
V_94 -> V_144 = F_1 ( V_94 -> V_144 ) ;
return 0 ;
V_53:
F_52 ( & V_28 -> V_545 , V_94 , NULL ) ;
if ( F_36 ( V_31 , & V_28 -> V_30 ) == 0 )
F_327 ( & V_28 -> V_545 , V_94 ) ;
V_94 -> V_144 = 0 ;
return - V_124 ;
}
static void F_328 ( struct V_27 * V_28 ,
T_11 * V_546 )
{
T_2 V_202 [ 2 ] ;
V_202 [ 0 ] = F_6 ( ( T_3 ) V_28 -> V_547 . V_548 ) ;
V_202 [ 1 ] = F_6 ( ( T_3 ) V_28 -> V_547 . V_549 ) ;
memcpy ( V_546 -> V_130 , V_202 , sizeof( V_546 -> V_130 ) ) ;
}
int F_329 ( struct V_27 * V_28 , T_3 V_550 ,
unsigned short V_551 , struct V_258 * V_303 ,
struct V_552 * V_29 )
{
T_11 V_553 ;
struct V_554 V_555 = {
. V_553 = & V_553 ,
. V_556 = V_550 ,
. V_557 = V_28 -> V_558 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_559 ] ,
. V_256 = & V_555 ,
. V_257 = V_29 ,
. V_258 = V_303 ,
} ;
int V_288 = 0 ;
int V_248 ;
F_328 ( V_28 , & V_553 ) ;
for(; ; ) {
F_112 () ;
V_555 . V_560 = F_330 ( V_555 . V_561 ,
sizeof( V_555 . V_561 ) , L_42 ,
V_28 -> V_562 ,
F_331 ( V_28 -> V_506 ,
V_563 ) ,
F_331 ( V_28 -> V_506 ,
V_564 ) ,
V_28 -> V_506 -> V_565 -> V_566 -> V_567 ,
V_28 -> V_568 ) ;
V_555 . V_569 = F_330 ( V_555 . V_570 ,
sizeof( V_555 . V_570 ) ,
F_331 ( V_28 -> V_506 ,
V_571 ) ) ;
V_555 . V_572 = F_330 ( V_555 . V_573 ,
sizeof( V_555 . V_573 ) , L_43 ,
V_28 -> V_562 , V_551 >> 8 , V_551 & 255 ) ;
F_115 () ;
V_248 = F_67 ( V_28 -> V_506 , & V_135 , V_574 ) ;
if ( V_248 != - V_575 )
break;
if ( V_288 != 0 ) {
++ V_28 -> V_568 ;
break;
}
++ V_288 ;
F_332 ( V_28 -> V_576 / V_70 + 1 ) ;
}
return V_248 ;
}
int F_333 ( struct V_27 * V_28 ,
struct V_552 * V_313 ,
struct V_258 * V_303 )
{
struct V_364 V_475 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_577 ] ,
. V_256 = V_313 ,
. V_257 = & V_475 ,
. V_258 = V_303 ,
} ;
unsigned long V_509 ;
int V_248 ;
V_509 = V_127 ;
V_248 = F_67 ( V_28 -> V_506 , & V_135 , V_574 ) ;
if ( V_248 == 0 ) {
F_26 ( & V_28 -> V_83 ) ;
V_28 -> V_576 = V_475 . V_578 * V_70 ;
V_28 -> V_84 = V_509 ;
F_28 ( & V_28 -> V_83 ) ;
}
return V_248 ;
}
static void F_334 ( struct V_93 * V_94 , void * V_128 )
{
struct V_579 * V_130 = V_128 ;
if ( ! F_45 ( V_94 , & V_130 -> V_29 . V_133 ) )
return;
switch ( V_94 -> V_144 ) {
case - V_58 :
case - V_57 :
case 0 :
F_29 ( V_130 -> V_29 . V_42 , V_130 -> V_82 ) ;
break;
default:
if ( F_188 ( V_94 , V_130 -> V_29 . V_42 , NULL ) ==
- V_124 ) {
F_189 ( V_94 ) ;
return;
}
}
V_130 -> V_250 = V_94 -> V_144 ;
}
static void F_335 ( void * V_128 )
{
F_86 ( V_128 ) ;
}
static void F_336 ( struct V_93 * V_94 , void * V_130 )
{
struct V_579 * V_580 ;
V_580 = (struct V_579 * ) V_130 ;
if ( F_54 ( V_580 -> V_29 . V_42 ,
& V_580 -> args . V_132 ,
& V_580 -> V_29 . V_133 , V_94 ) )
return;
F_57 ( V_94 ) ;
}
static int F_337 ( struct V_48 * V_48 , struct V_258 * V_303 , const T_6 * V_205 , int V_581 )
{
struct V_579 * V_130 ;
struct V_41 * V_42 = F_77 ( V_48 ) ;
struct V_93 * V_94 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_582 ] ,
. V_258 = V_303 ,
} ;
struct V_137 V_259 = {
. V_139 = V_42 -> V_75 ,
. V_134 = & V_135 ,
. V_140 = & V_583 ,
. V_174 = V_263 ,
} ;
int V_248 = 0 ;
V_130 = F_78 ( sizeof( * V_130 ) , V_245 ) ;
if ( V_130 == NULL )
return - V_237 ;
F_49 ( & V_130 -> args . V_132 , & V_130 -> V_29 . V_133 , 1 ) ;
V_130 -> args . V_337 = & V_130 -> V_184 ;
V_130 -> args . V_205 = & V_130 -> V_205 ;
V_130 -> args . V_195 = V_42 -> V_196 ;
F_152 ( & V_130 -> V_184 , F_83 ( V_48 ) ) ;
F_105 ( & V_130 -> V_205 , V_205 ) ;
V_130 -> V_29 . V_311 = & V_130 -> V_311 ;
V_130 -> V_29 . V_42 = V_42 ;
F_73 ( V_130 -> V_29 . V_311 ) ;
V_130 -> V_82 = V_127 ;
V_130 -> V_250 = 0 ;
V_259 . V_142 = V_130 ;
V_135 . V_256 = & V_130 -> args ;
V_135 . V_257 = & V_130 -> V_29 ;
V_94 = F_61 ( & V_259 ) ;
if ( F_62 ( V_94 ) )
return F_63 ( V_94 ) ;
if ( ! V_581 )
goto V_111;
V_248 = F_97 ( V_94 ) ;
if ( V_248 != 0 )
goto V_111;
V_248 = V_130 -> V_250 ;
if ( V_248 != 0 )
goto V_111;
F_158 ( V_48 , & V_130 -> V_311 ) ;
V_111:
F_64 ( V_94 ) ;
return V_248 ;
}
int F_338 ( struct V_48 * V_48 , struct V_258 * V_303 , const T_6 * V_205 , int V_581 )
{
struct V_41 * V_42 = F_77 ( V_48 ) ;
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_337 ( V_48 , V_303 , V_205 , V_581 ) ;
switch ( V_1 ) {
case - V_58 :
case - V_57 :
case 0 :
return 0 ;
}
V_1 = F_16 ( V_42 , V_1 , & V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static unsigned long
F_339 ( unsigned long V_36 )
{
F_14 ( V_36 ) ;
V_36 <<= 1 ;
if ( V_36 > V_584 )
return V_584 ;
return V_36 ;
}
static int F_340 ( struct V_46 * V_47 , int V_585 , struct V_586 * V_587 )
{
struct V_48 * V_48 = V_47 -> V_48 ;
struct V_41 * V_42 = F_77 ( V_48 ) ;
struct V_27 * V_28 = V_42 -> V_27 ;
struct V_588 V_313 = {
. V_184 = F_83 ( V_48 ) ,
. V_589 = V_587 ,
} ;
struct V_590 V_29 = {
. V_591 = V_587 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_592 ] ,
. V_256 = & V_313 ,
. V_257 = & V_29 ,
. V_258 = V_47 -> V_182 -> V_233 ,
} ;
struct V_593 * V_594 ;
int V_248 ;
V_313 . V_595 . V_187 = V_28 -> V_188 ;
V_248 = F_341 ( V_47 , V_587 ) ;
if ( V_248 != 0 )
goto V_111;
V_594 = V_587 -> V_596 . V_597 . V_182 ;
V_313 . V_595 . V_189 = V_594 -> V_598 . V_192 ;
V_313 . V_595 . V_599 = V_42 -> V_599 ;
V_248 = F_68 ( V_42 -> V_75 , V_42 , & V_135 , & V_313 . V_132 , & V_29 . V_133 , 1 ) ;
switch ( V_248 ) {
case 0 :
V_587 -> V_600 = V_601 ;
break;
case - V_602 :
V_248 = 0 ;
}
V_587 -> V_603 -> V_604 ( V_587 ) ;
V_111:
return V_248 ;
}
static int F_342 ( struct V_46 * V_47 , int V_585 , struct V_586 * V_587 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_47 -> V_48 ) ,
F_340 ( V_47 , V_585 , V_587 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_343 ( struct V_605 * V_605 , struct V_586 * V_589 )
{
int V_29 = 0 ;
switch ( V_589 -> V_606 & ( V_607 | V_608 ) ) {
case V_607 :
V_29 = F_344 ( V_605 , V_589 ) ;
break;
case V_608 :
V_29 = F_345 ( V_605 , V_589 ) ;
break;
default:
F_346 () ;
}
return V_29 ;
}
static struct V_609 * F_347 ( struct V_586 * V_589 ,
struct V_242 * V_243 ,
struct V_593 * V_594 ,
struct V_610 * V_165 )
{
struct V_609 * V_17 ;
struct V_48 * V_48 = V_594 -> V_611 -> V_48 ;
V_17 = F_78 ( sizeof( * V_17 ) , V_245 ) ;
if ( V_17 == NULL )
return NULL ;
V_17 -> V_313 . V_184 = F_83 ( V_48 ) ;
V_17 -> V_313 . V_589 = & V_17 -> V_589 ;
V_17 -> V_313 . V_165 = V_165 ;
V_17 -> V_29 . V_165 = V_165 ;
V_17 -> V_313 . V_205 = & V_594 -> V_612 ;
V_17 -> V_594 = V_594 ;
F_82 ( & V_594 -> V_613 ) ;
V_17 -> V_243 = F_129 ( V_243 ) ;
memcpy ( & V_17 -> V_589 , V_589 , sizeof( V_17 -> V_589 ) ) ;
V_17 -> V_42 = F_77 ( V_48 ) ;
return V_17 ;
}
static void F_348 ( void * V_130 )
{
struct V_609 * V_128 = V_130 ;
F_90 ( V_128 -> V_313 . V_165 ) ;
F_349 ( V_128 -> V_594 ) ;
F_140 ( V_128 -> V_243 ) ;
F_86 ( V_128 ) ;
}
static void F_350 ( struct V_93 * V_94 , void * V_130 )
{
struct V_609 * V_128 = V_130 ;
if ( ! F_45 ( V_94 , & V_128 -> V_29 . V_133 ) )
return;
switch ( V_94 -> V_144 ) {
case 0 :
F_105 ( & V_128 -> V_594 -> V_612 ,
& V_128 -> V_29 . V_205 ) ;
F_29 ( V_128 -> V_42 , V_128 -> V_82 ) ;
break;
case - V_56 :
case - V_77 :
case - V_58 :
case - V_57 :
break;
default:
if ( F_188 ( V_94 , V_128 -> V_42 , NULL ) == - V_124 )
F_189 ( V_94 ) ;
}
}
static void F_351 ( struct V_93 * V_94 , void * V_130 )
{
struct V_609 * V_128 = V_130 ;
if ( F_151 ( V_128 -> V_313 . V_165 , V_94 ) != 0 )
return;
if ( ( V_128 -> V_594 -> V_614 & V_615 ) == 0 ) {
V_94 -> V_269 = NULL ;
return;
}
V_128 -> V_82 = V_127 ;
if ( F_54 ( V_128 -> V_42 ,
& V_128 -> V_313 . V_132 ,
& V_128 -> V_29 . V_133 , V_94 ) )
return;
F_57 ( V_94 ) ;
}
static struct V_93 * F_352 ( struct V_586 * V_589 ,
struct V_242 * V_243 ,
struct V_593 * V_594 ,
struct V_610 * V_165 )
{
struct V_609 * V_130 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_616 ] ,
. V_258 = V_243 -> V_303 ,
} ;
struct V_137 V_259 = {
. V_139 = F_228 ( V_594 -> V_611 -> V_48 ) ,
. V_134 = & V_135 ,
. V_140 = & V_617 ,
. V_261 = V_262 ,
. V_174 = V_263 ,
} ;
V_589 -> V_600 = V_601 ;
V_130 = F_347 ( V_589 , V_243 , V_594 , V_165 ) ;
if ( V_130 == NULL ) {
F_90 ( V_165 ) ;
return F_119 ( - V_237 ) ;
}
F_49 ( & V_130 -> V_313 . V_132 , & V_130 -> V_29 . V_133 , 1 ) ;
V_135 . V_256 = & V_130 -> V_313 ;
V_135 . V_257 = & V_130 -> V_29 ;
V_259 . V_142 = V_130 ;
return F_61 ( & V_259 ) ;
}
static int F_353 ( struct V_46 * V_47 , int V_585 , struct V_586 * V_587 )
{
struct V_150 * V_151 = F_70 ( V_47 -> V_48 ) ;
struct V_610 * V_165 ;
struct V_593 * V_594 ;
struct V_93 * V_94 ;
int V_248 = 0 ;
unsigned char V_606 = V_587 -> V_606 ;
V_248 = F_341 ( V_47 , V_587 ) ;
V_587 -> V_606 |= V_618 ;
F_354 ( & V_151 -> V_619 ) ;
if ( F_343 ( V_587 -> V_620 , V_587 ) == - V_244 ) {
F_355 ( & V_151 -> V_619 ) ;
goto V_111;
}
F_355 ( & V_151 -> V_619 ) ;
if ( V_248 != 0 )
goto V_111;
if ( F_36 ( V_222 , & V_47 -> V_174 ) )
goto V_111;
V_594 = V_587 -> V_596 . V_597 . V_182 ;
V_165 = F_79 ( & V_594 -> V_598 , V_304 ) ;
V_248 = - V_237 ;
if ( V_165 == NULL )
goto V_111;
V_94 = F_352 ( V_587 , F_221 ( V_587 -> V_620 ) , V_594 , V_165 ) ;
V_248 = F_63 ( V_94 ) ;
if ( F_62 ( V_94 ) )
goto V_111;
V_248 = F_97 ( V_94 ) ;
F_64 ( V_94 ) ;
V_111:
V_587 -> V_606 = V_606 ;
return V_248 ;
}
static struct V_621 * F_356 ( struct V_586 * V_589 ,
struct V_242 * V_243 , struct V_593 * V_594 ,
T_5 V_177 )
{
struct V_621 * V_17 ;
struct V_48 * V_48 = V_594 -> V_611 -> V_48 ;
struct V_41 * V_42 = F_77 ( V_48 ) ;
V_17 = F_78 ( sizeof( * V_17 ) , V_177 ) ;
if ( V_17 == NULL )
return NULL ;
V_17 -> V_313 . V_184 = F_83 ( V_48 ) ;
V_17 -> V_313 . V_589 = & V_17 -> V_589 ;
V_17 -> V_313 . V_622 = F_79 ( & V_594 -> V_611 -> V_182 -> V_179 , V_177 ) ;
if ( V_17 -> V_313 . V_622 == NULL )
goto V_252;
V_17 -> V_313 . V_623 = F_79 ( & V_594 -> V_598 , V_177 ) ;
if ( V_17 -> V_313 . V_623 == NULL )
goto V_624;
V_17 -> V_313 . V_625 = & V_594 -> V_612 ;
V_17 -> V_313 . V_595 . V_187 = V_42 -> V_27 -> V_188 ;
V_17 -> V_313 . V_595 . V_189 = V_594 -> V_598 . V_192 ;
V_17 -> V_313 . V_595 . V_599 = V_42 -> V_599 ;
V_17 -> V_29 . V_623 = V_17 -> V_313 . V_623 ;
V_17 -> V_594 = V_594 ;
V_17 -> V_42 = V_42 ;
F_82 ( & V_594 -> V_613 ) ;
V_17 -> V_243 = F_129 ( V_243 ) ;
memcpy ( & V_17 -> V_589 , V_589 , sizeof( V_17 -> V_589 ) ) ;
return V_17 ;
V_624:
F_90 ( V_17 -> V_313 . V_622 ) ;
V_252:
F_86 ( V_17 ) ;
return NULL ;
}
static void F_357 ( struct V_93 * V_94 , void * V_128 )
{
struct V_621 * V_130 = V_128 ;
struct V_46 * V_47 = V_130 -> V_594 -> V_611 ;
F_2 ( L_30 , V_9 ) ;
if ( F_151 ( V_130 -> V_313 . V_623 , V_94 ) != 0 )
return;
if ( ! ( V_130 -> V_313 . V_623 -> V_626 -> V_174 & V_627 ) ) {
if ( F_151 ( V_130 -> V_313 . V_622 , V_94 ) != 0 )
return;
V_130 -> V_313 . V_223 = & V_47 -> V_205 ;
V_130 -> V_313 . V_628 = 1 ;
V_130 -> V_29 . V_622 = V_130 -> V_313 . V_622 ;
} else
V_130 -> V_313 . V_628 = 0 ;
V_130 -> V_82 = V_127 ;
if ( F_54 ( V_130 -> V_42 ,
& V_130 -> V_313 . V_132 ,
& V_130 -> V_29 . V_133 , V_94 ) )
return;
F_57 ( V_94 ) ;
F_2 ( L_44 , V_9 , V_130 -> V_250 ) ;
}
static void F_358 ( struct V_93 * V_94 , void * V_128 )
{
F_34 ( V_94 , V_96 ) ;
F_357 ( V_94 , V_128 ) ;
}
static void F_359 ( struct V_93 * V_94 , void * V_128 )
{
struct V_621 * V_130 = V_128 ;
F_2 ( L_30 , V_9 ) ;
if ( ! F_45 ( V_94 , & V_130 -> V_29 . V_133 ) )
return;
V_130 -> V_250 = V_94 -> V_144 ;
if ( V_130 -> V_313 . V_628 != 0 ) {
if ( V_130 -> V_250 == 0 )
F_145 ( & V_130 -> V_594 -> V_598 , 0 ) ;
else
goto V_111;
}
if ( V_130 -> V_250 == 0 ) {
F_105 ( & V_130 -> V_594 -> V_612 , & V_130 -> V_29 . V_205 ) ;
V_130 -> V_594 -> V_614 |= V_615 ;
F_29 ( F_77 ( V_130 -> V_243 -> V_13 -> V_23 ) , V_130 -> V_82 ) ;
}
V_111:
F_2 ( L_31 , V_9 , V_130 -> V_250 ) ;
}
static void F_360 ( void * V_128 )
{
struct V_621 * V_130 = V_128 ;
F_2 ( L_30 , V_9 ) ;
F_90 ( V_130 -> V_313 . V_622 ) ;
if ( V_130 -> V_251 != 0 ) {
struct V_93 * V_94 ;
V_94 = F_352 ( & V_130 -> V_589 , V_130 -> V_243 , V_130 -> V_594 ,
V_130 -> V_313 . V_623 ) ;
if ( ! F_62 ( V_94 ) )
F_361 ( V_94 ) ;
F_2 ( L_45 , V_9 ) ;
} else
F_90 ( V_130 -> V_313 . V_623 ) ;
F_349 ( V_130 -> V_594 ) ;
F_140 ( V_130 -> V_243 ) ;
F_86 ( V_130 ) ;
F_2 ( L_32 , V_9 ) ;
}
static void F_362 ( struct V_41 * V_42 , struct V_593 * V_594 , int V_628 , int error )
{
switch ( error ) {
case - V_55 :
case - V_56 :
V_594 -> V_598 . V_174 &= ~ V_627 ;
if ( V_628 != 0 ||
( V_594 -> V_614 & V_615 ) != 0 )
F_19 ( V_42 , V_594 -> V_611 ) ;
break;
case - V_58 :
V_594 -> V_598 . V_174 &= ~ V_627 ;
case - V_57 :
F_21 ( V_42 -> V_27 ) ;
} ;
}
static int F_363 ( struct V_46 * V_47 , int V_585 , struct V_586 * V_589 , int V_629 )
{
struct V_621 * V_130 ;
struct V_93 * V_94 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_630 ] ,
. V_258 = V_47 -> V_182 -> V_233 ,
} ;
struct V_137 V_259 = {
. V_139 = F_228 ( V_47 -> V_48 ) ,
. V_134 = & V_135 ,
. V_140 = & V_631 ,
. V_261 = V_262 ,
. V_174 = V_263 ,
} ;
int V_49 ;
F_2 ( L_30 , V_9 ) ;
V_130 = F_356 ( V_589 , F_221 ( V_589 -> V_620 ) ,
V_589 -> V_596 . V_597 . V_182 ,
V_629 == V_632 ? V_304 : V_245 ) ;
if ( V_130 == NULL )
return - V_237 ;
if ( F_364 ( V_585 ) )
V_130 -> V_313 . V_633 = 1 ;
if ( V_629 > V_632 ) {
if ( V_629 == V_634 )
V_130 -> V_313 . V_635 = V_634 ;
V_259 . V_140 = & V_636 ;
}
F_49 ( & V_130 -> V_313 . V_132 , & V_130 -> V_29 . V_133 , 1 ) ;
V_135 . V_256 = & V_130 -> V_313 ;
V_135 . V_257 = & V_130 -> V_29 ;
V_259 . V_142 = V_130 ;
V_94 = F_61 ( & V_259 ) ;
if ( F_62 ( V_94 ) )
return F_63 ( V_94 ) ;
V_49 = F_97 ( V_94 ) ;
if ( V_49 == 0 ) {
V_49 = V_130 -> V_250 ;
if ( V_49 )
F_362 ( V_130 -> V_42 , V_130 -> V_594 ,
V_130 -> V_313 . V_628 , V_49 ) ;
} else
V_130 -> V_251 = 1 ;
F_64 ( V_94 ) ;
F_2 ( L_31 , V_9 , V_49 ) ;
return V_49 ;
}
static int F_365 ( struct V_46 * V_47 , struct V_586 * V_587 )
{
struct V_41 * V_42 = F_77 ( V_47 -> V_48 ) ;
struct V_44 V_45 = {
. V_48 = V_47 -> V_48 ,
} ;
int V_1 ;
do {
if ( F_36 ( V_222 , & V_47 -> V_174 ) != 0 )
return 0 ;
V_1 = F_363 ( V_47 , V_637 , V_587 , V_634 ) ;
if ( V_1 != - V_73 )
break;
F_16 ( V_42 , V_1 , & V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_366 ( struct V_46 * V_47 , struct V_586 * V_587 )
{
struct V_41 * V_42 = F_77 ( V_47 -> V_48 ) ;
struct V_44 V_45 = {
. V_48 = V_47 -> V_48 ,
} ;
int V_1 ;
V_1 = F_341 ( V_47 , V_587 ) ;
if ( V_1 != 0 )
return V_1 ;
do {
if ( F_36 ( V_222 , & V_47 -> V_174 ) != 0 )
return 0 ;
V_1 = F_363 ( V_47 , V_637 , V_587 , V_638 ) ;
switch ( V_1 ) {
default:
goto V_111;
case - V_72 :
case - V_73 :
F_16 ( V_42 , V_1 , & V_45 ) ;
V_1 = 0 ;
}
} while ( V_45 . V_50 );
V_111:
return V_1 ;
}
static int F_367 ( struct V_46 * V_47 )
{
int V_248 , V_49 = V_110 ;
struct V_593 * V_594 ;
struct V_41 * V_42 = F_77 ( V_47 -> V_48 ) ;
F_128 (lsp, &state->lock_states, ls_locks) {
if ( V_594 -> V_614 & V_615 ) {
V_248 = F_170 ( V_42 , & V_594 -> V_612 ) ;
if ( V_248 != V_110 ) {
F_171 ( V_42 , & V_594 -> V_612 ) ;
V_594 -> V_614 &= ~ V_615 ;
V_49 = V_248 ;
}
}
} ;
return V_49 ;
}
static int F_368 ( struct V_46 * V_47 , struct V_586 * V_587 )
{
int V_248 = V_110 ;
if ( F_36 ( V_639 , & V_47 -> V_174 ) )
V_248 = F_367 ( V_47 ) ;
if ( V_248 == V_110 )
return V_248 ;
return F_366 ( V_47 , V_587 ) ;
}
static int F_369 ( struct V_46 * V_47 , int V_585 , struct V_586 * V_587 )
{
struct V_150 * V_151 = F_70 ( V_47 -> V_48 ) ;
unsigned char V_606 = V_587 -> V_606 ;
int V_248 = - V_640 ;
if ( ( V_606 & V_607 ) &&
! F_36 ( V_308 , & V_47 -> V_174 ) )
goto V_111;
V_248 = F_341 ( V_47 , V_587 ) ;
if ( V_248 != 0 )
goto V_111;
V_587 -> V_606 |= V_641 ;
V_248 = F_343 ( V_587 -> V_620 , V_587 ) ;
if ( V_248 < 0 )
goto V_111;
F_354 ( & V_151 -> V_619 ) ;
if ( F_36 ( V_222 , & V_47 -> V_174 ) ) {
V_587 -> V_606 = V_606 & ~ V_642 ;
V_248 = F_343 ( V_587 -> V_620 , V_587 ) ;
goto V_643;
}
V_248 = F_363 ( V_47 , V_585 , V_587 , V_632 ) ;
if ( V_248 != 0 )
goto V_643;
V_587 -> V_606 = V_606 | V_642 ;
if ( F_343 ( V_587 -> V_620 , V_587 ) < 0 )
F_24 ( V_80 L_46
L_47 , V_9 ) ;
V_643:
F_355 ( & V_151 -> V_619 ) ;
V_111:
V_587 -> V_606 = V_606 ;
return V_248 ;
}
static int F_370 ( struct V_46 * V_47 , int V_585 , struct V_586 * V_587 )
{
struct V_44 V_45 = {
. V_47 = V_47 ,
. V_48 = V_47 -> V_48 ,
} ;
int V_1 ;
do {
V_1 = F_369 ( V_47 , V_585 , V_587 ) ;
if ( V_1 == - V_602 )
V_1 = - V_124 ;
V_1 = F_16 ( F_77 ( V_47 -> V_48 ) ,
V_1 , & V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int
F_371 ( struct V_605 * V_644 , int V_585 , struct V_586 * V_587 )
{
struct V_242 * V_243 ;
struct V_46 * V_47 ;
unsigned long V_36 = V_645 ;
int V_248 ;
V_243 = F_221 ( V_644 ) ;
V_47 = V_243 -> V_47 ;
if ( V_587 -> V_646 < 0 || V_587 -> V_647 < 0 )
return - V_8 ;
if ( F_372 ( V_585 ) ) {
if ( V_47 != NULL )
return F_342 ( V_47 , V_648 , V_587 ) ;
return 0 ;
}
if ( ! ( F_373 ( V_585 ) || F_364 ( V_585 ) ) )
return - V_8 ;
if ( V_587 -> V_600 == V_601 ) {
if ( V_47 != NULL )
return F_353 ( V_47 , V_585 , V_587 ) ;
return 0 ;
}
if ( V_47 == NULL )
return - V_640 ;
switch ( V_587 -> V_600 & ( V_649 | V_650 | V_601 ) ) {
case V_649 :
if ( ! ( V_644 -> V_651 & V_52 ) )
return - V_320 ;
break;
case V_650 :
if ( ! ( V_644 -> V_651 & V_186 ) )
return - V_320 ;
}
do {
V_248 = F_370 ( V_47 , V_585 , V_587 ) ;
if ( ( V_248 != - V_124 ) || F_373 ( V_585 ) )
break;
V_36 = F_339 ( V_36 ) ;
V_248 = - V_40 ;
if ( F_374 () )
break;
} while( V_248 < 0 );
return V_248 ;
}
int F_375 ( struct V_46 * V_47 , struct V_586 * V_589 )
{
struct V_41 * V_42 = F_77 ( V_47 -> V_48 ) ;
struct V_44 V_45 = { } ;
int V_1 ;
V_1 = F_341 ( V_47 , V_589 ) ;
if ( V_1 != 0 )
goto V_111;
do {
V_1 = F_363 ( V_47 , V_637 , V_589 , V_632 ) ;
switch ( V_1 ) {
default:
F_24 ( V_652 L_48
L_49 , V_9 , V_1 ) ;
case 0 :
case - V_247 :
goto V_111;
case - V_57 :
F_19 ( V_42 , V_47 ) ;
case - V_59 :
case - V_58 :
F_21 ( V_42 -> V_27 ) ;
goto V_111;
case - V_61 :
case - V_62 :
case - V_63 :
case - V_64 :
case - V_65 :
F_23 ( V_42 -> V_27 -> V_68 ) ;
goto V_111;
case - V_40 :
case - V_54 :
case - V_55 :
case - V_56 :
case - V_51 :
F_19 ( V_42 , V_47 ) ;
V_1 = 0 ;
goto V_111;
case - V_74 :
V_1 = 0 ;
goto V_111;
case - V_237 :
case - V_602 :
V_1 = 0 ;
goto V_111;
case - V_73 :
break;
}
V_1 = F_16 ( V_42 , V_1 , & V_45 ) ;
} while ( V_45 . V_50 );
V_111:
return V_1 ;
}
static void F_376 ( void * V_128 )
{
struct V_653 * V_130 = V_128 ;
F_377 ( V_130 -> V_42 , V_130 -> V_594 ) ;
F_86 ( V_128 ) ;
}
int F_378 ( struct V_593 * V_594 )
{
struct V_41 * V_42 = V_594 -> V_611 -> V_182 -> V_266 ;
struct V_653 * V_130 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_654 ] ,
} ;
if ( V_42 -> V_27 -> V_145 -> V_378 != 0 )
return - V_8 ;
V_130 = F_212 ( sizeof( * V_130 ) , V_245 ) ;
if ( ! V_130 )
return - V_237 ;
V_130 -> V_594 = V_594 ;
V_130 -> V_42 = V_42 ;
V_130 -> args . V_595 . V_187 = V_42 -> V_27 -> V_188 ;
V_130 -> args . V_595 . V_189 = V_594 -> V_598 . V_192 ;
V_130 -> args . V_595 . V_599 = V_42 -> V_599 ;
V_135 . V_256 = & V_130 -> args ;
F_306 ( V_42 -> V_75 , & V_135 , 0 , & V_655 , V_130 ) ;
return 0 ;
}
static int F_379 ( struct V_13 * V_13 , const char * V_656 ,
const void * V_512 , T_9 V_513 ,
int V_174 , int type )
{
if ( strcmp ( V_656 , L_50 ) != 0 )
return - V_8 ;
return F_325 ( V_13 -> V_23 , V_512 , V_513 ) ;
}
static int F_380 ( struct V_13 * V_13 , const char * V_656 ,
void * V_512 , T_9 V_513 , int type )
{
if ( strcmp ( V_656 , L_50 ) != 0 )
return - V_8 ;
return F_319 ( V_13 -> V_23 , V_512 , V_513 ) ;
}
static T_9 F_381 ( struct V_13 * V_13 , char * V_657 ,
T_9 V_658 , const char * V_193 ,
T_9 V_659 , int type )
{
T_9 V_374 = sizeof( V_660 ) ;
if ( ! F_308 ( F_77 ( V_13 -> V_23 ) ) )
return 0 ;
if ( V_657 && V_374 <= V_658 )
memcpy ( V_657 , V_660 , V_374 ) ;
return V_374 ;
}
static void F_215 ( struct V_310 * V_311 )
{
if ( ! ( ( ( V_311 -> V_235 & V_661 ) ||
( V_311 -> V_235 & V_662 ) ) &&
( V_311 -> V_235 & V_663 ) &&
( V_311 -> V_235 & V_664 ) ) )
return;
V_311 -> V_235 |= V_396 | V_397 |
V_398 | V_665 ;
V_311 -> V_209 = V_274 | V_400 | V_401 ;
V_311 -> V_402 = 2 ;
}
static int F_382 ( struct V_34 * V_75 , struct V_48 * V_147 ,
const struct V_382 * V_193 ,
struct V_384 * V_666 ,
struct V_383 * V_383 )
{
struct V_41 * V_42 = F_77 ( V_147 ) ;
T_3 V_195 [ 2 ] = {
[ 0 ] = V_667 | V_668 ,
} ;
struct V_669 args = {
. V_394 = F_83 ( V_147 ) ,
. V_193 = V_193 ,
. V_383 = V_383 ,
. V_195 = V_195 ,
} ;
struct V_670 V_29 = {
. V_666 = V_666 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_671 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
int V_248 ;
F_2 ( L_51 , V_9 ) ;
if ( F_77 ( V_147 ) -> V_196 [ 1 ] & V_672 )
V_195 [ 1 ] |= V_672 ;
else
V_195 [ 0 ] |= V_22 ;
F_73 ( & V_666 -> V_311 ) ;
V_666 -> V_42 = V_42 ;
V_666 -> V_673 = 0 ;
V_248 = F_68 ( V_75 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
F_2 ( L_52 , V_9 , V_248 ) ;
return V_248 ;
}
int F_213 ( struct V_34 * V_75 , struct V_48 * V_147 ,
const struct V_382 * V_193 ,
struct V_384 * V_666 ,
struct V_383 * V_383 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_147 ) ,
F_382 ( V_75 , V_147 , V_193 , V_666 , V_383 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_383 ( struct V_48 * V_147 , const struct V_382 * V_193 , struct V_674 * V_675 )
{
int V_248 ;
struct V_676 args = {
. V_394 = F_83 ( V_147 ) ,
. V_193 = V_193 ,
} ;
struct V_677 V_29 = {
. V_675 = V_675 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_678 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
F_2 ( L_53 , V_193 -> V_193 ) ;
V_248 = F_68 ( F_77 ( V_147 ) -> V_75 , F_77 ( V_147 ) , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
F_2 ( L_54 , V_248 ) ;
return V_248 ;
}
int F_384 ( struct V_48 * V_147 , const struct V_382 * V_193 ,
struct V_674 * V_675 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_147 ) ,
F_383 ( V_147 , V_193 , V_675 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_385 ( T_3 V_174 )
{
if ( V_174 & ~ V_679 )
goto V_680;
if ( ( V_174 & V_681 ) &&
( V_174 & V_682 ) )
goto V_680;
if ( ! ( V_174 & ( V_683 ) ) )
goto V_680;
return V_110 ;
V_680:
return - V_684 ;
}
static bool
F_386 ( struct V_685 * V_686 , struct V_685 * V_687 )
{
if ( V_686 -> V_688 == V_687 -> V_688 &&
memcmp ( V_686 -> V_685 , V_687 -> V_685 , V_686 -> V_688 ) == 0 )
return true ;
return false ;
}
int F_387 ( struct V_27 * V_28 , struct V_258 * V_303 )
{
T_11 V_12 ;
struct V_689 args = {
. V_12 = & V_12 ,
. V_75 = V_28 ,
. V_174 = V_690 ,
} ;
struct V_691 V_29 = {
. V_75 = V_28 ,
} ;
int V_248 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_692 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
. V_258 = V_303 ,
} ;
F_2 ( L_17 , V_9 ) ;
F_4 ( V_28 == NULL ) ;
F_328 ( V_28 , & V_12 ) ;
args . V_693 = F_330 ( args . V_189 , sizeof( args . V_189 ) ,
L_55 ,
V_28 -> V_562 ,
V_28 -> V_506 -> V_694 ,
V_28 -> V_506 -> V_565 -> V_695 ) ;
V_29 . V_685 = F_78 ( sizeof( struct V_685 ) , V_304 ) ;
if ( F_388 ( ! V_29 . V_685 ) ) {
V_248 = - V_237 ;
goto V_111;
}
V_29 . V_696 = F_78 ( sizeof( struct V_697 ) , V_304 ) ;
if ( F_388 ( ! V_29 . V_696 ) ) {
V_248 = - V_237 ;
goto V_698;
}
V_248 = F_67 ( V_28 -> V_506 , & V_135 , V_574 ) ;
if ( ! V_248 )
V_248 = F_385 ( V_28 -> V_699 ) ;
if ( ! V_248 ) {
F_86 ( V_28 -> V_696 ) ;
V_28 -> V_696 = V_29 . V_696 ;
} else
F_86 ( V_29 . V_696 ) ;
if ( ! V_248 ) {
if ( V_28 -> V_685 &&
! F_386 ( V_28 -> V_685 ,
V_29 . V_685 ) ) {
F_2 ( L_56 ,
V_9 ) ;
F_106 ( V_700 , & V_28 -> V_30 ) ;
F_86 ( V_28 -> V_685 ) ;
V_28 -> V_685 = NULL ;
}
if ( ! V_28 -> V_685 ) {
V_28 -> V_685 = V_29 . V_685 ;
goto V_111;
}
}
V_698:
F_86 ( V_29 . V_685 ) ;
V_111:
if ( V_28 -> V_696 )
F_2 ( L_57
L_58 ,
V_9 , V_28 -> V_696 -> V_701 , V_28 -> V_696 -> V_193 ,
V_28 -> V_696 -> V_702 . V_703 ,
V_28 -> V_696 -> V_702 . V_704 ) ;
F_2 ( L_59 , V_9 , V_248 ) ;
return V_248 ;
}
static void F_389 ( struct V_93 * V_94 ,
void * V_128 )
{
int V_49 ;
struct V_705 * V_130 =
(struct V_705 * ) V_128 ;
F_2 ( L_17 , V_9 ) ;
F_34 ( V_94 , V_96 ) ;
V_49 = F_50 ( V_130 -> V_28 -> V_68 ,
& V_130 -> args -> V_706 ,
& V_130 -> V_29 -> V_707 , V_94 ) ;
F_4 ( V_49 == - V_124 ) ;
F_57 ( V_94 ) ;
F_2 ( L_60 , V_9 ) ;
}
static void F_390 ( struct V_93 * V_94 , void * V_128 )
{
struct V_705 * V_130 =
(struct V_705 * ) V_128 ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_41 ( V_94 , & V_130 -> V_29 -> V_707 ) )
return;
switch ( V_94 -> V_144 ) {
case - V_73 :
case - V_72 :
F_2 ( L_61 , V_9 , V_94 -> V_144 ) ;
F_44 ( V_94 , V_37 ) ;
V_94 -> V_144 = 0 ;
case - V_76 :
F_189 ( V_94 ) ;
return;
}
F_2 ( L_60 , V_9 ) ;
}
int F_391 ( struct V_27 * V_28 , struct V_364 * V_475 )
{
struct V_93 * V_94 ;
struct V_708 args ;
struct V_709 V_29 = {
. V_710 = V_475 ,
} ;
struct V_705 V_130 = {
. args = & args ,
. V_29 = & V_29 ,
. V_28 = V_28 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_711 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
struct V_137 V_138 = {
. V_139 = V_28 -> V_506 ,
. V_134 = & V_135 ,
. V_140 = & V_712 ,
. V_142 = & V_130 ,
. V_174 = V_574 ,
} ;
int V_248 ;
F_49 ( & args . V_706 , & V_29 . V_707 , 0 ) ;
F_2 ( L_17 , V_9 ) ;
V_94 = F_61 ( & V_138 ) ;
if ( F_62 ( V_94 ) )
V_248 = F_63 ( V_94 ) ;
else {
V_248 = V_94 -> V_144 ;
F_64 ( V_94 ) ;
}
F_2 ( L_62 , V_9 , V_248 ) ;
return V_248 ;
}
static struct V_122 * F_392 ( T_3 V_91 , T_5 V_713 )
{
return F_393 ( V_91 , sizeof( struct V_122 ) , V_713 ) ;
}
static void F_394 ( struct V_85 * V_86 ,
struct V_122 * V_714 ,
T_3 V_91 ,
T_3 V_715 )
{
struct V_122 * V_716 = NULL ;
T_3 V_373 ;
F_26 ( & V_86 -> V_107 ) ;
if ( V_714 ) {
V_716 = V_86 -> V_108 ;
V_86 -> V_108 = V_714 ;
V_86 -> V_91 = V_91 ;
}
V_86 -> V_90 = - 1 ;
for ( V_373 = 0 ; V_373 < V_86 -> V_91 ; V_373 ++ )
V_86 -> V_108 [ V_373 ] . V_112 = V_715 ;
F_28 ( & V_86 -> V_107 ) ;
F_86 ( V_716 ) ;
}
static int F_395 ( struct V_85 * V_86 , T_3 V_717 ,
T_3 V_715 )
{
struct V_122 * V_714 = NULL ;
int V_49 = - V_237 ;
F_2 ( L_63 , V_9 ,
V_717 , V_86 -> V_91 ) ;
if ( V_717 != V_86 -> V_91 ) {
V_714 = F_392 ( V_717 , V_245 ) ;
if ( ! V_714 )
goto V_111;
}
V_49 = 0 ;
F_394 ( V_86 , V_714 , V_717 , V_715 ) ;
F_2 ( L_64 , V_9 ,
V_86 , V_86 -> V_108 , V_86 -> V_91 ) ;
V_111:
F_2 ( L_65 , V_9 , V_49 ) ;
return V_49 ;
}
static void F_396 ( struct V_97 * V_121 )
{
if ( V_121 -> V_101 . V_108 != NULL ) {
F_86 ( V_121 -> V_101 . V_108 ) ;
V_121 -> V_101 . V_108 = NULL ;
}
if ( V_121 -> V_103 . V_108 != NULL ) {
F_86 ( V_121 -> V_103 . V_108 ) ;
V_121 -> V_103 . V_108 = NULL ;
}
return;
}
static int F_397 ( struct V_97 * V_98 )
{
struct V_85 * V_86 ;
int V_248 ;
F_2 ( L_17 , V_9 ) ;
V_86 = & V_98 -> V_101 ;
V_248 = F_395 ( V_86 , V_98 -> V_718 . V_717 , 1 ) ;
if ( V_248 )
return V_248 ;
V_86 = & V_98 -> V_103 ;
V_248 = F_395 ( V_86 , V_98 -> V_719 . V_717 , 0 ) ;
if ( V_248 && V_86 -> V_108 == NULL )
F_396 ( V_98 ) ;
return V_248 ;
}
struct V_97 * F_398 ( struct V_27 * V_28 )
{
struct V_97 * V_121 ;
struct V_85 * V_86 ;
V_121 = F_78 ( sizeof( struct V_97 ) , V_245 ) ;
if ( ! V_121 )
return NULL ;
V_86 = & V_121 -> V_101 ;
V_86 -> V_90 = V_92 ;
F_399 ( & V_86 -> V_107 ) ;
F_400 ( & V_86 -> V_102 , L_66 ) ;
F_401 ( & V_86 -> F_38 ) ;
V_86 = & V_121 -> V_103 ;
V_86 -> V_90 = V_92 ;
F_399 ( & V_86 -> V_107 ) ;
F_402 ( & V_86 -> V_102 , L_67 ) ;
F_401 ( & V_86 -> F_38 ) ;
V_121 -> V_100 = 1 << V_720 ;
V_121 -> V_28 = V_28 ;
return V_121 ;
}
void F_403 ( struct V_97 * V_121 )
{
struct V_721 * V_722 ;
F_404 ( V_121 ) ;
F_112 () ;
V_722 = F_113 ( V_121 -> V_28 -> V_506 -> V_723 ) ;
F_115 () ;
F_2 ( L_68 ,
V_9 , V_722 ) ;
F_405 ( V_722 , V_724 ) ;
F_396 ( V_121 ) ;
F_86 ( V_121 ) ;
}
static void F_406 ( struct V_725 * args )
{
struct V_97 * V_121 = args -> V_75 -> V_68 ;
unsigned int V_726 = V_121 -> V_718 . V_727 ,
V_728 = V_121 -> V_718 . V_729 ;
if ( V_726 == 0 )
V_726 = V_730 ;
if ( V_728 == 0 )
V_728 = V_730 ;
args -> V_718 . V_727 = V_726 ;
args -> V_718 . V_729 = V_728 ;
args -> V_718 . V_731 = V_732 ;
args -> V_718 . V_717 = V_733 ;
F_2 ( L_69
L_70 ,
V_9 ,
args -> V_718 . V_727 , args -> V_718 . V_729 ,
args -> V_718 . V_731 , args -> V_718 . V_717 ) ;
args -> V_719 . V_727 = V_526 ;
args -> V_719 . V_729 = V_526 ;
args -> V_719 . V_734 = 0 ;
args -> V_719 . V_731 = V_735 ;
args -> V_719 . V_717 = 1 ;
F_2 ( L_71
L_72 ,
V_9 ,
args -> V_719 . V_727 , args -> V_719 . V_729 ,
args -> V_719 . V_734 , args -> V_719 . V_731 ,
args -> V_719 . V_717 ) ;
}
static int F_407 ( struct V_725 * args , struct V_97 * V_121 )
{
struct V_736 * V_737 = & args -> V_718 ;
struct V_736 * V_738 = & V_121 -> V_718 ;
if ( V_738 -> V_729 > V_737 -> V_729 )
return - V_8 ;
if ( V_738 -> V_731 < V_737 -> V_731 )
return - V_8 ;
if ( V_738 -> V_717 == 0 )
return - V_8 ;
if ( V_738 -> V_717 > V_88 )
V_738 -> V_717 = V_88 ;
return 0 ;
}
static int F_408 ( struct V_725 * args , struct V_97 * V_121 )
{
struct V_736 * V_737 = & args -> V_719 ;
struct V_736 * V_738 = & V_121 -> V_719 ;
if ( V_738 -> V_727 > V_737 -> V_727 )
return - V_8 ;
if ( V_738 -> V_729 < V_737 -> V_729 )
return - V_8 ;
if ( V_738 -> V_734 > V_737 -> V_734 )
return - V_8 ;
if ( V_738 -> V_731 != V_737 -> V_731 )
return - V_8 ;
if ( V_738 -> V_717 != V_737 -> V_717 )
return - V_8 ;
return 0 ;
}
static int F_409 ( struct V_725 * args ,
struct V_97 * V_121 )
{
int V_49 ;
V_49 = F_407 ( args , V_121 ) ;
if ( V_49 )
return V_49 ;
return F_408 ( args , V_121 ) ;
}
static int F_410 ( struct V_27 * V_28 )
{
struct V_97 * V_121 = V_28 -> V_68 ;
struct V_725 args = {
. V_75 = V_28 ,
. V_739 = V_740 ,
} ;
struct V_741 V_29 = {
. V_75 = V_28 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_742 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
int V_248 ;
F_406 ( & args ) ;
args . V_174 = ( V_743 | V_744 ) ;
V_248 = F_67 ( V_121 -> V_28 -> V_506 , & V_135 , V_574 ) ;
if ( ! V_248 )
V_248 = F_409 ( & args , V_121 ) ;
if ( ! V_248 ) {
V_28 -> V_745 ++ ;
}
return V_248 ;
}
int F_411 ( struct V_27 * V_28 )
{
int V_248 ;
unsigned * V_746 ;
struct V_97 * V_121 = V_28 -> V_68 ;
F_2 ( L_73 , V_9 , V_28 , V_121 ) ;
V_248 = F_410 ( V_28 ) ;
if ( V_248 )
goto V_111;
V_248 = F_397 ( V_121 ) ;
F_2 ( L_74 , V_248 ) ;
if ( V_248 )
goto V_111;
V_746 = ( unsigned * ) & V_121 -> V_747 . V_130 [ 0 ] ;
F_2 ( L_75 , V_9 ,
V_28 -> V_745 , V_746 [ 0 ] , V_746 [ 1 ] , V_746 [ 2 ] , V_746 [ 3 ] ) ;
V_111:
F_2 ( L_60 , V_9 ) ;
return V_248 ;
}
int F_404 ( struct V_97 * V_121 )
{
int V_248 = 0 ;
struct V_134 V_135 ;
F_2 ( L_76 ) ;
if ( V_121 -> V_28 -> V_748 != V_749 )
return V_248 ;
V_135 . V_253 = & V_254 [ V_750 ] ;
V_135 . V_256 = V_121 ;
V_135 . V_257 = NULL ;
V_135 . V_258 = NULL ;
V_248 = F_67 ( V_121 -> V_28 -> V_506 , & V_135 , V_574 ) ;
if ( V_248 )
F_24 ( V_80
L_77
L_78 , V_248 ) ;
F_2 ( L_79 ) ;
return V_248 ;
}
int F_412 ( struct V_41 * V_42 )
{
struct V_27 * V_28 = V_42 -> V_27 ;
struct V_97 * V_121 ;
unsigned int V_751 , V_752 ;
int V_49 ;
if ( ! F_413 ( V_28 ) )
return 0 ;
V_121 = V_28 -> V_68 ;
if ( ! F_414 ( V_720 , & V_121 -> V_100 ) )
return 0 ;
V_751 = V_42 -> V_751 ;
if ( V_751 == 0 )
V_751 = V_730 ;
V_752 = V_42 -> V_752 ;
if ( V_752 == 0 )
V_752 = V_730 ;
V_121 -> V_718 . V_727 = V_752 + V_753 ;
V_121 -> V_718 . V_729 = V_751 + V_754 ;
V_49 = F_164 ( V_42 ) ;
if ( ! V_49 )
V_49 = F_415 ( V_28 ) ;
return V_49 ;
}
int F_416 ( struct V_27 * V_28 )
{
struct V_97 * V_121 = V_28 -> V_68 ;
int V_49 ;
if ( ! F_414 ( V_720 , & V_121 -> V_100 ) )
return 0 ;
V_49 = F_162 ( V_28 ) ;
if ( ! V_49 )
if ( ! F_417 ( V_28 ) )
V_49 = - V_755 ;
if ( ! V_49 )
V_49 = F_415 ( V_28 ) ;
return V_49 ;
}
static void F_418 ( void * V_130 )
{
struct V_756 * V_128 = V_130 ;
struct V_27 * V_28 = V_128 -> V_28 ;
if ( F_299 ( & V_28 -> V_500 ) > 1 )
F_300 ( V_28 ) ;
F_301 ( V_28 ) ;
F_86 ( V_128 ) ;
}
static int F_419 ( struct V_93 * V_94 , struct V_27 * V_28 )
{
switch( V_94 -> V_144 ) {
case - V_73 :
F_44 ( V_94 , V_38 ) ;
return - V_124 ;
default:
F_21 ( V_28 ) ;
}
return 0 ;
}
static void F_420 ( struct V_93 * V_94 , void * V_130 )
{
struct V_756 * V_128 = V_130 ;
struct V_27 * V_28 = V_128 -> V_28 ;
if ( ! F_41 ( V_94 , V_94 -> V_267 . V_257 ) )
return;
if ( V_94 -> V_144 < 0 ) {
F_2 ( L_80 , V_9 , V_94 -> V_144 ) ;
if ( F_299 ( & V_28 -> V_500 ) == 1 )
goto V_111;
if ( F_419 ( V_94 , V_28 ) == - V_124 ) {
F_189 ( V_94 ) ;
return;
}
}
F_2 ( L_81 , V_9 , V_94 -> V_267 . V_258 ) ;
V_111:
F_2 ( L_60 , V_9 ) ;
}
static void F_421 ( struct V_93 * V_94 , void * V_130 )
{
struct V_756 * V_128 = V_130 ;
struct V_27 * V_28 = V_128 -> V_28 ;
struct V_117 * args ;
struct V_104 * V_29 ;
args = V_94 -> V_267 . V_256 ;
V_29 = V_94 -> V_267 . V_257 ;
if ( F_50 ( V_28 -> V_68 , args , V_29 , V_94 ) )
return;
F_57 ( V_94 ) ;
}
static struct V_93 * F_422 ( struct V_27 * V_28 , struct V_258 * V_303 )
{
struct V_756 * V_128 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_757 ] ,
. V_258 = V_303 ,
} ;
struct V_137 V_259 = {
. V_139 = V_28 -> V_506 ,
. V_134 = & V_135 ,
. V_140 = & V_758 ,
. V_174 = V_263 | V_507 ,
} ;
if ( ! F_305 ( & V_28 -> V_500 ) )
return F_119 ( - V_10 ) ;
V_128 = F_78 ( sizeof( * V_128 ) , V_245 ) ;
if ( V_128 == NULL ) {
F_301 ( V_28 ) ;
return F_119 ( - V_237 ) ;
}
F_49 ( & V_128 -> args , & V_128 -> V_29 , 0 ) ;
V_135 . V_256 = & V_128 -> args ;
V_135 . V_257 = & V_128 -> V_29 ;
V_128 -> V_28 = V_28 ;
V_259 . V_142 = V_128 ;
return F_61 ( & V_259 ) ;
}
static int F_423 ( struct V_27 * V_28 , struct V_258 * V_303 , unsigned V_504 )
{
struct V_93 * V_94 ;
int V_49 = 0 ;
if ( ( V_504 & V_759 ) == 0 )
return 0 ;
V_94 = F_422 ( V_28 , V_303 ) ;
if ( F_62 ( V_94 ) )
V_49 = F_63 ( V_94 ) ;
else
F_361 ( V_94 ) ;
F_2 ( L_23 , V_9 , V_49 ) ;
return V_49 ;
}
static int F_424 ( struct V_27 * V_28 , struct V_258 * V_303 )
{
struct V_93 * V_94 ;
int V_49 ;
V_94 = F_422 ( V_28 , V_303 ) ;
if ( F_62 ( V_94 ) ) {
V_49 = F_63 ( V_94 ) ;
goto V_111;
}
V_49 = F_98 ( V_94 ) ;
if ( ! V_49 ) {
struct V_104 * V_29 = V_94 -> V_267 . V_257 ;
if ( V_94 -> V_144 == 0 )
F_425 ( V_28 , V_29 -> V_114 ) ;
V_49 = V_94 -> V_144 ;
}
F_64 ( V_94 ) ;
V_111:
F_2 ( L_23 , V_9 , V_49 ) ;
return V_49 ;
}
static void F_426 ( struct V_93 * V_94 , void * V_130 )
{
struct V_760 * V_128 = V_130 ;
F_34 ( V_94 , V_96 ) ;
if ( F_50 ( V_128 -> V_28 -> V_68 ,
& V_128 -> V_313 . V_132 ,
& V_128 -> V_29 . V_133 , V_94 ) )
return;
F_57 ( V_94 ) ;
}
static int F_427 ( struct V_93 * V_94 , struct V_27 * V_28 )
{
switch( V_94 -> V_144 ) {
case 0 :
case - V_761 :
case - V_762 :
break;
case - V_73 :
F_44 ( V_94 , V_38 ) ;
case - V_76 :
return - V_124 ;
default:
F_21 ( V_28 ) ;
}
return 0 ;
}
static void F_428 ( struct V_93 * V_94 , void * V_130 )
{
struct V_760 * V_128 = V_130 ;
struct V_27 * V_28 = V_128 -> V_28 ;
struct V_104 * V_29 = & V_128 -> V_29 . V_133 ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_41 ( V_94 , V_29 ) )
return;
if ( F_427 ( V_94 , V_28 ) == - V_124 ) {
F_189 ( V_94 ) ;
return;
}
F_2 ( L_60 , V_9 ) ;
}
static void F_429 ( void * V_130 )
{
struct V_760 * V_128 = V_130 ;
F_86 ( V_128 ) ;
}
static int F_430 ( struct V_27 * V_28 )
{
struct V_760 * V_128 ;
struct V_93 * V_94 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_763 ] ,
} ;
struct V_137 V_259 = {
. V_139 = V_28 -> V_506 ,
. V_134 = & V_135 ,
. V_140 = & V_764 ,
. V_174 = V_263 ,
} ;
int V_248 = - V_237 ;
F_2 ( L_17 , V_9 ) ;
V_128 = F_78 ( sizeof( * V_128 ) , V_245 ) ;
if ( V_128 == NULL )
goto V_111;
V_128 -> V_28 = V_28 ;
V_128 -> V_313 . V_765 = 0 ;
F_49 ( & V_128 -> V_313 . V_132 , & V_128 -> V_29 . V_133 , 0 ) ;
V_135 . V_256 = & V_128 -> V_313 ;
V_135 . V_257 = & V_128 -> V_29 ;
V_259 . V_142 = V_128 ;
V_94 = F_61 ( & V_259 ) ;
if ( F_62 ( V_94 ) ) {
V_248 = F_63 ( V_94 ) ;
goto V_111;
}
V_248 = F_97 ( V_94 ) ;
if ( V_248 == 0 )
V_248 = V_94 -> V_144 ;
F_64 ( V_94 ) ;
return 0 ;
V_111:
F_2 ( L_23 , V_9 , V_248 ) ;
return V_248 ;
}
static void
F_431 ( struct V_93 * V_94 , void * V_128 )
{
struct V_766 * V_767 = V_128 ;
struct V_41 * V_42 = F_77 ( V_767 -> args . V_48 ) ;
F_2 ( L_17 , V_9 ) ;
if ( F_54 ( V_42 , & V_767 -> args . V_132 ,
& V_767 -> V_29 . V_133 , V_94 ) )
return;
if ( F_432 ( & V_767 -> args . V_205 ,
F_70 ( V_767 -> args . V_48 ) -> V_768 ,
V_767 -> args . V_243 -> V_47 ) ) {
F_433 ( V_94 , V_769 ) ;
return;
}
F_57 ( V_94 ) ;
}
static void F_434 ( struct V_93 * V_94 , void * V_128 )
{
struct V_766 * V_767 = V_128 ;
struct V_41 * V_42 = F_77 ( V_767 -> args . V_48 ) ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_45 ( V_94 , & V_767 -> V_29 . V_133 ) )
return;
switch ( V_94 -> V_144 ) {
case 0 :
break;
case - V_770 :
case - V_771 :
V_94 -> V_144 = - V_73 ;
default:
if ( F_188 ( V_94 , V_42 , NULL ) == - V_124 ) {
F_189 ( V_94 ) ;
return;
}
}
F_2 ( L_60 , V_9 ) ;
}
static void F_435 ( void * V_128 )
{
struct V_766 * V_767 = V_128 ;
F_2 ( L_17 , V_9 ) ;
F_140 ( V_767 -> args . V_243 ) ;
F_86 ( V_128 ) ;
F_2 ( L_60 , V_9 ) ;
}
int F_436 ( struct V_766 * V_767 )
{
struct V_41 * V_42 = F_77 ( V_767 -> args . V_48 ) ;
struct V_93 * V_94 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_772 ] ,
. V_256 = & V_767 -> args ,
. V_257 = & V_767 -> V_29 ,
} ;
struct V_137 V_259 = {
. V_139 = V_42 -> V_75 ,
. V_134 = & V_135 ,
. V_140 = & V_773 ,
. V_142 = V_767 ,
. V_174 = V_263 ,
} ;
int V_248 = 0 ;
F_2 ( L_17 , V_9 ) ;
V_767 -> V_29 . V_774 = & V_767 -> args . V_768 ;
V_767 -> V_29 . V_133 . V_106 = NULL ;
F_49 ( & V_767 -> args . V_132 , & V_767 -> V_29 . V_133 , 0 ) ;
V_94 = F_61 ( & V_259 ) ;
if ( F_62 ( V_94 ) )
return F_63 ( V_94 ) ;
V_248 = F_97 ( V_94 ) ;
if ( V_248 == 0 )
V_248 = V_94 -> V_144 ;
if ( V_248 == 0 )
V_248 = F_437 ( V_767 ) ;
F_64 ( V_94 ) ;
F_2 ( L_23 , V_9 , V_248 ) ;
return V_248 ;
}
static void
F_438 ( struct V_93 * V_94 , void * V_128 )
{
struct V_775 * V_776 = V_128 ;
F_2 ( L_17 , V_9 ) ;
if ( F_50 ( V_776 -> V_28 -> V_68 , & V_776 -> args . V_132 ,
& V_776 -> V_29 . V_133 , V_94 ) )
return;
F_57 ( V_94 ) ;
}
static void F_439 ( struct V_93 * V_94 , void * V_128 )
{
struct V_775 * V_776 = V_128 ;
struct V_41 * V_42 ;
struct V_777 * V_778 = V_776 -> args . V_768 ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_45 ( V_94 , & V_776 -> V_29 . V_133 ) )
return;
V_42 = F_77 ( V_776 -> args . V_48 ) ;
if ( F_188 ( V_94 , V_42 , NULL ) == - V_124 ) {
F_189 ( V_94 ) ;
return;
}
F_26 ( & V_778 -> V_779 -> V_152 ) ;
if ( V_94 -> V_144 == 0 ) {
if ( V_776 -> V_29 . V_780 ) {
F_440 ( V_778 , & V_776 -> V_29 . V_205 , true ) ;
} else
F_4 ( ! F_441 ( & V_778 -> V_781 ) ) ;
}
V_778 -> V_782 -- ;
F_28 ( & V_778 -> V_779 -> V_152 ) ;
F_2 ( L_60 , V_9 ) ;
}
static void F_442 ( void * V_128 )
{
struct V_775 * V_776 = V_128 ;
F_2 ( L_17 , V_9 ) ;
F_443 ( V_776 -> args . V_768 ) ;
F_86 ( V_128 ) ;
F_2 ( L_60 , V_9 ) ;
}
int F_444 ( struct V_775 * V_776 )
{
struct V_93 * V_94 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_783 ] ,
. V_256 = & V_776 -> args ,
. V_257 = & V_776 -> V_29 ,
} ;
struct V_137 V_259 = {
. V_139 = V_776 -> V_28 -> V_506 ,
. V_134 = & V_135 ,
. V_140 = & V_784 ,
. V_142 = V_776 ,
} ;
int V_248 ;
F_2 ( L_17 , V_9 ) ;
F_49 ( & V_776 -> args . V_132 , & V_776 -> V_29 . V_133 , 1 ) ;
V_94 = F_61 ( & V_259 ) ;
if ( F_62 ( V_94 ) )
return F_63 ( V_94 ) ;
V_248 = V_94 -> V_144 ;
F_2 ( L_23 , V_9 , V_248 ) ;
F_64 ( V_94 ) ;
return V_248 ;
}
static int F_445 ( struct V_41 * V_42 ,
const struct V_336 * V_184 ,
struct V_785 * V_786 )
{
struct V_787 args = {
. V_184 = V_184 ,
. V_788 = V_42 -> V_789 -> V_189 ,
} ;
struct V_790 V_29 = {
. V_786 = V_786 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_791 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
int V_248 ;
F_2 ( L_17 , V_9 ) ;
V_248 = F_68 ( V_42 -> V_75 , V_42 , & V_135 , & args . V_132 ,
& V_29 . V_133 , 0 ) ;
F_2 ( L_23 , V_9 , V_248 ) ;
return V_248 ;
}
int F_446 ( struct V_41 * V_42 ,
const struct V_336 * V_184 ,
struct V_785 * V_786 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_42 ,
F_445 ( V_42 , V_184 , V_786 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
F_2 ( L_82 , V_9 ,
V_1 , V_786 -> V_792 ) ;
return V_1 ;
}
static int
F_447 ( struct V_41 * V_42 , struct V_793 * V_794 )
{
struct V_795 args = {
. V_794 = V_794 ,
} ;
struct V_796 V_29 = {
. V_794 = V_794 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_797 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
int V_248 ;
F_2 ( L_17 , V_9 ) ;
V_248 = F_68 ( V_42 -> V_75 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
F_2 ( L_23 , V_9 , V_248 ) ;
return V_248 ;
}
int F_448 ( struct V_41 * V_42 , struct V_793 * V_794 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_42 ,
F_447 ( V_42 , V_794 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static void F_449 ( struct V_93 * V_94 , void * V_128 )
{
struct V_798 * V_130 = V_128 ;
struct V_41 * V_42 = F_77 ( V_130 -> args . V_48 ) ;
if ( F_54 ( V_42 , & V_130 -> args . V_132 ,
& V_130 -> V_29 . V_133 , V_94 ) )
return;
F_57 ( V_94 ) ;
}
static void
F_450 ( struct V_93 * V_94 , void * V_128 )
{
struct V_798 * V_130 = V_128 ;
struct V_41 * V_42 = F_77 ( V_130 -> args . V_48 ) ;
if ( ! F_45 ( V_94 , & V_130 -> V_29 . V_133 ) )
return;
switch ( V_94 -> V_144 ) {
case - V_54 :
case - V_799 :
case - V_800 :
case - V_72 :
V_94 -> V_144 = 0 ;
break;
case 0 :
F_290 ( V_130 -> args . V_48 ,
V_130 -> V_29 . V_311 ) ;
break;
default:
if ( F_188 ( V_94 , V_42 , NULL ) == - V_124 ) {
F_189 ( V_94 ) ;
return;
}
}
}
static void F_451 ( void * V_128 )
{
struct V_798 * V_130 = V_128 ;
struct V_801 * V_489 , * V_802 ;
unsigned long * V_803 = & F_70 ( V_130 -> args . V_48 ) -> V_174 ;
F_452 ( V_130 ) ;
F_453 (lseg, tmp, &data->lseg_list, pls_lc_list) {
F_454 ( & V_489 -> V_804 ) ;
if ( F_414 ( V_805 ,
& V_489 -> V_806 ) )
F_287 ( V_489 ) ;
}
F_455 ( V_807 , V_803 ) ;
F_456 () ;
F_457 ( V_803 , V_807 ) ;
F_458 ( V_130 -> V_303 ) ;
F_86 ( V_130 ) ;
}
int
F_459 ( struct V_798 * V_130 , bool V_808 )
{
struct V_134 V_135 = {
. V_253 = & V_254 [ V_809 ] ,
. V_256 = & V_130 -> args ,
. V_257 = & V_130 -> V_29 ,
. V_258 = V_130 -> V_303 ,
} ;
struct V_137 V_259 = {
. V_94 = & V_130 -> V_94 ,
. V_139 = F_228 ( V_130 -> args . V_48 ) ,
. V_134 = & V_135 ,
. V_140 = & V_810 ,
. V_142 = V_130 ,
. V_174 = V_263 ,
} ;
struct V_93 * V_94 ;
int V_248 = 0 ;
F_2 ( L_83
L_84 ,
V_130 -> V_94 . V_811 , V_808 ,
V_130 -> args . V_812 ,
V_130 -> args . V_48 -> V_813 ) ;
F_49 ( & V_130 -> args . V_132 , & V_130 -> V_29 . V_133 , 1 ) ;
V_94 = F_61 ( & V_259 ) ;
if ( F_62 ( V_94 ) )
return F_63 ( V_94 ) ;
if ( V_808 == false )
goto V_111;
V_248 = F_97 ( V_94 ) ;
if ( V_248 != 0 )
goto V_111;
V_248 = V_94 -> V_144 ;
V_111:
F_2 ( L_85 , V_9 , V_248 ) ;
F_64 ( V_94 ) ;
return V_248 ;
}
static int
F_460 ( struct V_41 * V_42 , struct V_336 * V_337 ,
struct V_364 * V_365 , struct V_674 * V_675 )
{
struct V_814 args = {
. V_815 = V_816 ,
} ;
struct V_677 V_29 = {
. V_675 = V_675 ,
} ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_817 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
return F_68 ( V_42 -> V_75 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 0 ) ;
}
static int
F_461 ( struct V_41 * V_42 , struct V_336 * V_337 ,
struct V_364 * V_365 , struct V_674 * V_675 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_460 ( V_42 , V_337 , V_365 , V_675 ) ;
switch ( V_1 ) {
case 0 :
case - V_4 :
case - V_818 :
goto V_111;
default:
V_1 = F_16 ( V_42 , V_1 , & V_45 ) ;
}
} while ( V_45 . V_50 );
V_111:
return V_1 ;
}
static int
F_462 ( struct V_41 * V_42 , struct V_336 * V_337 ,
struct V_364 * V_365 )
{
int V_1 ;
struct V_383 * V_383 ;
T_7 V_370 ;
struct V_674 * V_675 ;
V_383 = F_211 ( V_304 ) ;
if ( ! V_383 ) {
V_1 = - V_237 ;
goto V_111;
}
V_675 = F_311 ( V_383 ) ;
V_1 = F_461 ( V_42 , V_337 , V_365 , V_675 ) ;
if ( V_1 == - V_4 || V_1 == - V_818 ) {
V_1 = F_205 ( V_42 , V_337 , V_365 ) ;
goto V_819;
}
if ( V_1 )
goto V_819;
V_370 = F_463 ( V_675 ) ;
if ( V_1 == 0 )
V_1 = F_203 ( V_42 , V_337 , V_365 , V_370 ) ;
V_819:
F_323 ( V_383 ) ;
if ( V_1 == - V_322 )
return - V_5 ;
V_111:
return V_1 ;
}
static int F_464 ( struct V_41 * V_42 , T_6 * V_205 )
{
int V_248 ;
struct V_820 args = {
. V_205 = V_205 ,
} ;
struct V_821 V_29 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_822 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
F_49 ( & args . V_132 , & V_29 . V_133 , 0 ) ;
V_248 = F_60 ( V_42 -> V_75 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 1 ) ;
if ( V_248 == V_110 )
return V_29 . V_248 ;
return V_248 ;
}
static int F_170 ( struct V_41 * V_42 , T_6 * V_205 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_42 ,
F_464 ( V_42 , V_205 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static int F_465 ( struct V_41 * V_42 , T_6 * V_205 )
{
struct V_823 args = {
. V_205 = V_205 ,
} ;
struct V_824 V_29 ;
struct V_134 V_135 = {
. V_253 = & V_254 [ V_825 ] ,
. V_256 = & args ,
. V_257 = & V_29 ,
} ;
F_49 ( & args . V_132 , & V_29 . V_133 , 0 ) ;
return F_60 ( V_42 -> V_75 , V_42 , & V_135 , & args . V_132 , & V_29 . V_133 , 1 ) ;
}
static int F_171 ( struct V_41 * V_42 , T_6 * V_205 )
{
struct V_44 V_45 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_42 ,
F_465 ( V_42 , V_205 ) ,
& V_45 ) ;
} while ( V_45 . V_50 );
return V_1 ;
}
static bool F_466 ( const T_6 * V_826 ,
const T_6 * V_827 )
{
if ( memcmp ( V_826 -> V_828 , V_827 -> V_828 , sizeof( V_826 -> V_828 ) ) != 0 )
return false ;
if ( V_826 -> V_165 == V_827 -> V_165 )
return true ;
if ( V_826 -> V_165 == 0 || V_827 -> V_165 == 0 )
return true ;
return false ;
}
static bool F_467 ( const T_6 * V_826 ,
const T_6 * V_827 )
{
return F_114 ( V_826 , V_827 ) ;
}
