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
V_16 = V_17 = F_5 ( * V_15 -> V_19 , V_20 ) ;
if ( V_11 == 0 ) {
* V_17 ++ = V_21 ;
* V_17 ++ = V_22 ;
* V_17 ++ = V_21 ;
* V_17 ++ = V_21 ;
memcpy ( V_17 , L_2 , 4 ) ;
V_17 ++ ;
* V_17 ++ = V_21 ;
* V_17 ++ = F_6 ( V_23 ) ;
* V_17 ++ = F_6 ( 8 ) ;
V_17 = F_7 ( V_17 , F_8 ( V_13 -> V_24 ) ) ;
}
* V_17 ++ = V_21 ;
* V_17 ++ = V_22 ;
* V_17 ++ = V_25 ;
* V_17 ++ = V_25 ;
memcpy ( V_17 , L_3 , 4 ) ;
V_17 ++ ;
* V_17 ++ = V_21 ;
* V_17 ++ = F_6 ( V_23 ) ;
* V_17 ++ = F_6 ( 8 ) ;
V_17 = F_7 ( V_17 , F_8 ( V_13 -> V_26 -> V_24 ) ) ;
V_15 -> V_27 = ( char * ) V_17 - ( char * ) V_16 ;
V_15 -> V_18 -= V_15 -> V_27 ;
F_9 ( V_16 , V_20 ) ;
}
static int F_10 ( struct V_28 * V_29 )
{
int V_30 ;
F_11 () ;
V_30 = F_12 ( & V_29 -> V_31 , V_32 ,
V_33 , V_34 ) ;
return V_30 ;
}
static int F_13 ( struct V_35 * V_36 , long * V_37 )
{
int V_30 = 0 ;
F_11 () ;
if ( * V_37 <= 0 )
* V_37 = V_38 ;
if ( * V_37 > V_39 )
* V_37 = V_39 ;
F_14 ( * V_37 ) ;
if ( F_15 ( V_40 ) )
V_30 = - V_41 ;
* V_37 <<= 1 ;
return V_30 ;
}
static int F_16 ( struct V_42 * V_43 , int V_44 , struct V_45 * V_46 )
{
struct V_28 * V_29 = V_43 -> V_28 ;
struct V_47 * V_48 = V_46 -> V_48 ;
int V_49 = V_44 ;
V_46 -> V_50 = 0 ;
switch( V_44 ) {
case 0 :
return 0 ;
case - V_51 :
case - V_52 :
case - V_53 :
if ( V_48 == NULL )
break;
F_17 ( V_43 , V_48 ) ;
goto V_54;
case - V_55 :
if ( V_48 != NULL )
F_17 ( V_43 , V_48 ) ;
case - V_56 :
case - V_57 :
F_18 ( V_29 ) ;
goto V_54;
#if F_19 ( V_58 )
case - V_59 :
case - V_60 :
case - V_61 :
case - V_62 :
case - V_63 :
case - V_64 :
case - V_65 :
F_2 ( L_4 , V_9 ,
V_44 ) ;
F_20 ( V_29 -> V_66 ) ;
V_46 -> V_50 = 1 ;
break;
#endif
case - V_67 :
if ( V_46 -> V_37 > V_68 ) {
V_49 = - V_69 ;
break;
}
case - V_70 :
case - V_71 :
case - V_72 :
V_49 = F_13 ( V_43 -> V_73 , & V_46 -> V_37 ) ;
if ( V_49 != 0 )
break;
case - V_74 :
case - V_75 :
V_46 -> V_50 = 1 ;
break;
case - V_6 :
case - V_7 :
if ( V_43 -> V_76 & V_77 ) {
V_43 -> V_76 &= ~ V_77 ;
V_46 -> V_50 = 1 ;
F_21 ( V_78 L_5
L_6
L_7
L_8 ,
V_43 -> V_28 -> V_79 ) ;
}
}
return F_1 ( V_49 ) ;
V_54:
V_49 = F_10 ( V_29 ) ;
if ( V_49 == 0 )
V_46 -> V_50 = 1 ;
return V_49 ;
}
static void F_22 ( struct V_28 * V_29 , unsigned long V_80 )
{
F_23 ( & V_29 -> V_81 ) ;
if ( F_24 ( V_29 -> V_82 , V_80 ) )
V_29 -> V_82 = V_80 ;
F_25 ( & V_29 -> V_81 ) ;
}
static void F_26 ( const struct V_42 * V_43 , unsigned long V_80 )
{
F_22 ( V_43 -> V_28 , V_80 ) ;
}
static void
F_27 ( struct V_83 * V_84 , struct V_85 * V_86 )
{
int V_87 = V_86 - V_84 -> V_88 ;
int V_89 = V_87 ;
F_4 ( V_89 < 0 || V_89 >= V_90 ) ;
F_28 ( V_89 , V_84 -> V_91 ) ;
if ( V_89 == V_84 -> V_92 ) {
V_89 = F_29 ( V_84 -> V_91 , V_84 -> V_93 ) ;
if ( V_89 < V_84 -> V_93 )
V_84 -> V_92 = V_89 ;
else
V_84 -> V_92 = - 1 ;
}
F_2 ( L_9 , V_9 ,
V_87 , V_84 -> V_92 ) ;
}
static void F_30 ( struct V_94 * V_95 )
{
struct V_96 * V_97 ;
if ( ! F_31 ( V_98 , & V_95 -> V_99 ) ) {
V_97 = F_32 ( & V_95 -> V_100 . V_101 ) ;
if ( V_97 )
F_33 ( V_97 , V_102 ) ;
return;
}
if ( V_95 -> V_100 . V_92 != - 1 )
return;
F_2 ( L_10 , V_9 ) ;
F_34 ( & V_95 -> V_100 . F_34 ) ;
}
void F_35 ( struct V_94 * V_95 )
{
if ( ! F_31 ( V_98 , & V_95 -> V_99 ) ||
V_95 -> V_103 . V_92 != - 1 )
return;
F_2 ( L_11 , V_9 ) ;
F_34 ( & V_95 -> V_103 . F_34 ) ;
}
static void F_36 ( struct V_104 * V_30 )
{
struct V_83 * V_84 ;
V_84 = & V_30 -> V_105 -> V_100 ;
if ( ! V_30 -> V_106 ) {
F_2 ( L_12 , V_9 ) ;
return;
}
F_23 ( & V_84 -> V_107 ) ;
F_27 ( V_84 , V_30 -> V_106 ) ;
F_30 ( V_30 -> V_105 ) ;
F_25 ( & V_84 -> V_107 ) ;
V_30 -> V_106 = NULL ;
}
static int F_37 ( struct V_96 * V_97 , struct V_104 * V_30 )
{
unsigned long V_80 ;
struct V_28 * V_29 ;
if ( V_30 -> V_108 == 1 )
V_30 -> V_108 = V_109 ;
if ( ! F_38 ( V_97 ) )
goto V_110;
switch ( V_30 -> V_108 ) {
case 0 :
++ V_30 -> V_106 -> V_111 ;
V_80 = V_30 -> V_112 ;
V_29 = V_30 -> V_105 -> V_29 ;
F_22 ( V_29 , V_80 ) ;
if ( V_30 -> V_113 != 0 )
F_18 ( V_29 ) ;
break;
case - V_71 :
F_2 ( L_13 ,
V_9 ,
V_30 -> V_106 - V_30 -> V_105 -> V_100 . V_88 ,
V_30 -> V_106 -> V_111 ) ;
goto V_114;
default:
++ V_30 -> V_106 -> V_111 ;
}
V_110:
F_2 ( L_14 , V_9 , V_30 -> V_108 ) ;
F_36 ( V_30 ) ;
return 1 ;
V_114:
if ( ! F_39 ( V_97 ) )
goto V_110;
F_40 ( V_97 , V_39 ) ;
return 0 ;
}
static int F_41 ( struct V_96 * V_97 ,
struct V_104 * V_30 )
{
if ( V_30 -> V_105 == NULL )
return 1 ;
return F_37 ( V_97 , V_30 ) ;
}
static T_3
F_42 ( struct V_83 * V_84 )
{
int V_89 ;
T_3 V_115 = V_90 ;
F_43 ( ( T_3 ) V_90 != ( int ) V_90 ) ;
F_2 ( L_15 ,
V_9 , V_84 -> V_91 [ 0 ] , V_84 -> V_92 ,
V_84 -> V_93 ) ;
V_89 = F_44 ( V_84 -> V_91 , V_84 -> V_93 ) ;
if ( V_89 >= V_84 -> V_93 )
goto V_110;
F_45 ( V_89 , V_84 -> V_91 ) ;
if ( V_89 > V_84 -> V_92 )
V_84 -> V_92 = V_89 ;
V_115 = V_89 ;
V_110:
F_2 ( L_16 ,
V_9 , V_84 -> V_91 [ 0 ] , V_84 -> V_92 , V_115 ) ;
return V_115 ;
}
int F_46 ( struct V_94 * V_116 ,
struct V_117 * args ,
struct V_104 * V_30 ,
int V_118 ,
struct V_96 * V_97 )
{
struct V_85 * V_119 ;
struct V_83 * V_84 ;
T_3 V_89 ;
F_2 ( L_17 , V_9 ) ;
if ( V_30 -> V_106 != NULL )
return 0 ;
V_84 = & V_116 -> V_100 ;
F_23 ( & V_84 -> V_107 ) ;
if ( F_31 ( V_98 , & V_116 -> V_99 ) &&
! F_47 ( V_97 , V_102 ) ) {
F_48 ( & V_84 -> V_101 , V_97 , NULL ) ;
F_25 ( & V_84 -> V_107 ) ;
F_2 ( L_18 , V_9 ) ;
return - V_120 ;
}
if ( ! F_49 ( & V_84 -> V_101 ) &&
! F_47 ( V_97 , V_102 ) ) {
F_48 ( & V_84 -> V_101 , V_97 , NULL ) ;
F_25 ( & V_84 -> V_107 ) ;
F_2 ( L_19 , V_9 ) ;
return - V_120 ;
}
V_89 = F_42 ( V_84 ) ;
if ( V_89 == V_90 ) {
F_48 ( & V_84 -> V_101 , V_97 , NULL ) ;
F_25 ( & V_84 -> V_107 ) ;
F_2 ( L_20 , V_9 ) ;
return - V_120 ;
}
F_25 ( & V_84 -> V_107 ) ;
F_33 ( V_97 , V_121 ) ;
V_119 = V_84 -> V_88 + V_89 ;
args -> V_122 = V_116 ;
args -> V_123 = V_89 ;
args -> V_124 = V_118 ;
F_2 ( L_21 , V_9 , V_89 , V_119 -> V_111 ) ;
V_30 -> V_105 = V_116 ;
V_30 -> V_106 = V_119 ;
V_30 -> V_112 = V_125 ;
V_30 -> V_113 = 0 ;
V_30 -> V_108 = 1 ;
return 0 ;
}
int F_50 ( const struct V_42 * V_43 ,
struct V_117 * args ,
struct V_104 * V_30 ,
int V_118 ,
struct V_96 * V_97 )
{
struct V_94 * V_116 = F_51 ( V_43 ) ;
int V_49 = 0 ;
if ( V_116 == NULL ) {
args -> V_122 = NULL ;
V_30 -> V_105 = NULL ;
goto V_110;
}
F_2 ( L_22 ,
V_9 , V_116 -> V_29 , V_116 , V_30 -> V_106 ?
V_30 -> V_106 - V_116 -> V_100 . V_88 : - 1 ) ;
V_49 = F_46 ( V_116 , args , V_30 , V_118 ,
V_97 ) ;
V_110:
F_2 ( L_23 , V_9 , V_49 ) ;
return V_49 ;
}
static void F_52 ( struct V_96 * V_97 , void * V_126 )
{
struct V_127 * V_128 = V_126 ;
F_2 ( L_24 , V_9 , V_128 -> V_129 ) ;
if ( F_50 ( V_128 -> V_129 , V_128 -> V_130 ,
V_128 -> V_131 , V_128 -> V_118 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
static void F_54 ( struct V_96 * V_97 , void * V_126 )
{
F_33 ( V_97 , V_102 ) ;
F_52 ( V_97 , V_126 ) ;
}
static void F_55 ( struct V_96 * V_97 , void * V_126 )
{
struct V_127 * V_128 = V_126 ;
F_37 ( V_97 , V_128 -> V_131 ) ;
}
static int F_56 ( struct V_35 * V_36 ,
struct V_42 * V_43 ,
struct V_132 * V_133 ,
struct V_117 * args ,
struct V_104 * V_30 ,
int V_118 ,
int V_134 )
{
int V_49 ;
struct V_96 * V_97 ;
struct V_127 V_128 = {
. V_129 = V_43 ,
. V_130 = args ,
. V_131 = V_30 ,
. V_118 = V_118 ,
} ;
struct V_135 V_136 = {
. V_137 = V_36 ,
. V_132 = V_133 ,
. V_138 = & V_139 ,
. V_140 = & V_128
} ;
V_30 -> V_106 = NULL ;
if ( V_134 )
V_136 . V_138 = & V_141 ;
V_97 = F_57 ( & V_136 ) ;
if ( F_58 ( V_97 ) )
V_49 = F_59 ( V_97 ) ;
else {
V_49 = V_97 -> V_142 ;
F_60 ( V_97 ) ;
}
return V_49 ;
}
int F_61 ( struct V_35 * V_36 ,
struct V_42 * V_43 ,
struct V_132 * V_133 ,
struct V_117 * args ,
struct V_104 * V_30 ,
int V_118 )
{
return F_56 ( V_36 , V_43 , V_133 , args , V_30 , V_118 , 0 ) ;
}
static int F_41 ( struct V_96 * V_97 ,
struct V_104 * V_30 )
{
return 1 ;
}
int F_62 ( struct V_35 * V_36 ,
struct V_42 * V_43 ,
struct V_132 * V_133 ,
struct V_117 * args ,
struct V_104 * V_30 ,
int V_118 )
{
args -> V_122 = V_30 -> V_105 = NULL ;
return F_63 ( V_36 , V_133 , 0 ) ;
}
static inline
int F_64 ( struct V_35 * V_36 ,
struct V_42 * V_43 ,
struct V_132 * V_133 ,
struct V_117 * args ,
struct V_104 * V_30 ,
int V_118 )
{
return V_43 -> V_28 -> V_143 -> V_144 ( V_36 , V_43 , V_133 ,
args , V_30 , V_118 ) ;
}
static void F_65 ( struct V_145 * V_146 , struct V_147 * V_148 )
{
struct V_149 * V_150 = F_66 ( V_146 ) ;
F_23 ( & V_146 -> V_151 ) ;
V_150 -> V_152 |= V_153 | V_154 | V_155 ;
if ( ! V_148 -> V_156 || V_148 -> V_157 != V_150 -> V_158 )
F_67 ( V_146 ) ;
V_150 -> V_158 = V_148 -> V_159 ;
F_25 ( & V_146 -> V_151 ) ;
}
static void F_68 ( struct V_160 * V_17 )
{
V_17 -> V_161 . V_162 = & V_17 -> V_162 ;
V_17 -> V_161 . V_163 = & V_17 -> V_163 ;
V_17 -> V_161 . V_164 = V_17 -> V_165 . V_164 ;
V_17 -> V_166 . V_164 = V_17 -> V_167 . V_164 ;
V_17 -> V_161 . V_43 = V_17 -> V_165 . V_43 ;
F_69 ( & V_17 -> V_162 ) ;
F_69 ( & V_17 -> V_163 ) ;
}
static struct V_160 * F_70 ( struct V_13 * V_13 ,
struct V_168 * V_169 , T_4 V_170 , int V_171 ,
const struct V_172 * V_173 ,
T_5 V_174 )
{
struct V_13 * V_175 = F_71 ( V_13 ) ;
struct V_145 * V_146 = V_175 -> V_24 ;
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_160 * V_17 ;
V_17 = F_73 ( sizeof( * V_17 ) , V_174 ) ;
if ( V_17 == NULL )
goto V_1;
V_17 -> V_165 . V_164 = F_74 ( & V_169 -> V_176 , V_174 ) ;
if ( V_17 -> V_165 . V_164 == NULL )
goto V_177;
F_75 ( V_13 -> V_178 ) ;
V_17 -> V_13 = F_76 ( V_13 ) ;
V_17 -> V_146 = V_175 ;
V_17 -> V_179 = V_169 ;
F_77 ( & V_169 -> V_180 ) ;
V_17 -> V_165 . V_181 = F_78 ( V_146 ) ;
V_17 -> V_165 . V_182 = V_171 ;
V_17 -> V_165 . V_170 = V_170 & ( V_183 | V_184 ) ;
V_17 -> V_165 . V_185 = V_43 -> V_28 -> V_186 ;
V_17 -> V_165 . V_187 = V_169 -> V_188 . V_187 ;
V_17 -> V_165 . V_189 = & V_13 -> V_190 ;
V_17 -> V_165 . V_43 = V_43 ;
V_17 -> V_165 . V_191 = V_43 -> V_192 ;
V_17 -> V_165 . V_193 = V_194 ;
if ( V_171 & V_195 ) {
T_6 * V_196 ;
V_17 -> V_165 . V_197 . V_173 = & V_17 -> V_173 ;
memcpy ( & V_17 -> V_173 , V_173 , sizeof( V_17 -> V_173 ) ) ;
V_196 = ( T_6 * ) V_17 -> V_165 . V_197 . V_12 . V_128 ;
V_196 [ 0 ] = V_125 ;
V_196 [ 1 ] = V_40 -> V_198 ;
}
V_17 -> V_167 . V_181 = & V_17 -> V_161 . V_181 ;
V_17 -> V_167 . V_199 = & V_17 -> V_161 . V_199 ;
V_17 -> V_167 . V_164 = V_17 -> V_165 . V_164 ;
F_68 ( V_17 ) ;
F_79 ( & V_17 -> V_200 ) ;
return V_17 ;
V_177:
F_80 ( V_17 ) ;
V_1:
F_81 ( V_175 ) ;
return NULL ;
}
static void F_82 ( struct V_200 * V_200 )
{
struct V_160 * V_17 = F_83 ( V_200 ,
struct V_160 , V_200 ) ;
struct V_201 * V_202 = V_17 -> V_13 -> V_178 ;
F_84 ( V_17 -> V_165 . V_164 ) ;
if ( V_17 -> V_48 != NULL )
F_85 ( V_17 -> V_48 ) ;
F_86 ( V_17 -> V_179 ) ;
F_81 ( V_17 -> V_146 ) ;
F_81 ( V_17 -> V_13 ) ;
F_87 ( V_202 ) ;
F_80 ( V_17 ) ;
}
static void F_88 ( struct V_160 * V_17 )
{
if ( V_17 != NULL )
F_89 ( & V_17 -> V_200 , F_82 ) ;
}
static int F_90 ( struct V_96 * V_97 )
{
int V_49 ;
V_49 = F_91 ( V_97 ) ;
return V_49 ;
}
static int F_92 ( struct V_47 * V_48 , T_4 V_203 , int V_204 )
{
int V_49 = 0 ;
if ( V_204 & V_205 )
goto V_110;
switch ( V_203 & ( V_183 | V_184 ) ) {
case V_183 :
V_49 |= F_31 ( V_206 , & V_48 -> V_171 ) != 0
&& V_48 -> V_207 != 0 ;
break;
case V_184 :
V_49 |= F_31 ( V_208 , & V_48 -> V_171 ) != 0
&& V_48 -> V_209 != 0 ;
break;
case V_183 | V_184 :
V_49 |= F_31 ( V_210 , & V_48 -> V_171 ) != 0
&& V_48 -> V_211 != 0 ;
}
V_110:
return V_49 ;
}
static int F_93 ( struct V_212 * V_213 , T_4 V_170 )
{
if ( ( V_213 -> type & V_170 ) != V_170 )
return 0 ;
if ( F_31 ( V_214 , & V_213 -> V_171 ) )
return 0 ;
F_94 ( V_213 ) ;
return 1 ;
}
static void F_95 ( struct V_47 * V_48 , T_4 V_170 )
{
switch ( V_170 ) {
case V_184 :
V_48 -> V_209 ++ ;
break;
case V_183 :
V_48 -> V_207 ++ ;
break;
case V_183 | V_184 :
V_48 -> V_211 ++ ;
}
F_96 ( V_48 , V_48 -> V_48 | V_170 ) ;
}
static void F_97 ( struct V_47 * V_48 , T_7 * V_199 , T_4 V_170 )
{
if ( F_31 ( V_215 , & V_48 -> V_171 ) == 0 )
memcpy ( V_48 -> V_199 . V_128 , V_199 -> V_128 , sizeof( V_48 -> V_199 . V_128 ) ) ;
memcpy ( V_48 -> V_216 . V_128 , V_199 -> V_128 , sizeof( V_48 -> V_216 . V_128 ) ) ;
switch ( V_170 ) {
case V_183 :
F_98 ( V_206 , & V_48 -> V_171 ) ;
break;
case V_184 :
F_98 ( V_208 , & V_48 -> V_171 ) ;
break;
case V_183 | V_184 :
F_98 ( V_210 , & V_48 -> V_171 ) ;
}
}
static void F_99 ( struct V_47 * V_48 , T_7 * V_199 , T_4 V_170 )
{
F_100 ( & V_48 -> V_217 ) ;
F_97 ( V_48 , V_199 , V_170 ) ;
F_101 ( & V_48 -> V_217 ) ;
}
static void F_102 ( struct V_47 * V_48 , T_7 * V_216 , const T_7 * V_218 , T_4 V_170 )
{
F_100 ( & V_48 -> V_217 ) ;
if ( V_218 != NULL ) {
memcpy ( V_48 -> V_199 . V_128 , V_218 -> V_128 , sizeof( V_48 -> V_199 . V_128 ) ) ;
F_98 ( V_215 , & V_48 -> V_171 ) ;
}
if ( V_216 != NULL )
F_97 ( V_48 , V_216 , V_170 ) ;
F_101 ( & V_48 -> V_217 ) ;
F_23 ( & V_48 -> V_179 -> V_219 ) ;
F_95 ( V_48 , V_170 ) ;
F_25 ( & V_48 -> V_179 -> V_219 ) ;
}
static int F_103 ( struct V_47 * V_48 , T_7 * V_216 , T_7 * V_213 , T_4 V_170 )
{
struct V_149 * V_150 = F_66 ( V_48 -> V_145 ) ;
struct V_212 * V_220 ;
int V_49 = 0 ;
V_170 &= ( V_183 | V_184 ) ;
F_104 () ;
V_220 = F_105 ( V_150 -> V_213 ) ;
if ( V_220 == NULL )
goto V_221;
F_23 ( & V_220 -> V_222 ) ;
if ( V_150 -> V_213 != V_220 ||
( V_220 -> type & V_170 ) != V_170 )
goto V_223;
if ( V_213 == NULL )
V_213 = & V_220 -> V_199 ;
else if ( memcmp ( V_220 -> V_199 . V_128 , V_213 -> V_128 , V_224 ) != 0 )
goto V_223;
F_94 ( V_220 ) ;
F_102 ( V_48 , V_216 , & V_220 -> V_199 , V_170 ) ;
V_49 = 1 ;
V_223:
F_25 ( & V_220 -> V_222 ) ;
V_221:
F_106 () ;
if ( ! V_49 && V_216 != NULL ) {
F_102 ( V_48 , V_216 , NULL , V_170 ) ;
V_49 = 1 ;
}
return V_49 ;
}
static void F_107 ( struct V_145 * V_145 , T_4 V_170 )
{
struct V_212 * V_213 ;
F_104 () ;
V_213 = F_105 ( F_66 ( V_145 ) -> V_213 ) ;
if ( V_213 == NULL || ( V_213 -> type & V_170 ) == V_170 ) {
F_106 () ;
return;
}
F_106 () ;
F_108 ( V_145 ) ;
}
static struct V_47 * F_109 ( struct V_160 * V_225 )
{
struct V_47 * V_48 = V_225 -> V_48 ;
struct V_149 * V_150 = F_66 ( V_48 -> V_145 ) ;
struct V_212 * V_213 ;
int V_204 = V_225 -> V_165 . V_182 & V_205 ;
T_4 V_170 = V_225 -> V_165 . V_170 ;
T_7 V_199 ;
int V_49 = - V_120 ;
for (; ; ) {
if ( F_92 ( V_48 , V_170 , V_204 ) ) {
F_23 ( & V_48 -> V_179 -> V_219 ) ;
if ( F_92 ( V_48 , V_170 , V_204 ) ) {
F_95 ( V_48 , V_170 ) ;
F_25 ( & V_48 -> V_179 -> V_219 ) ;
goto V_226;
}
F_25 ( & V_48 -> V_179 -> V_219 ) ;
}
F_104 () ;
V_213 = F_105 ( V_150 -> V_213 ) ;
if ( V_213 == NULL ||
! F_93 ( V_213 , V_170 ) ) {
F_106 () ;
break;
}
memcpy ( V_199 . V_128 , V_213 -> V_199 . V_128 , sizeof( V_199 . V_128 ) ) ;
F_106 () ;
V_49 = F_110 ( V_48 -> V_145 , V_48 -> V_179 -> V_227 , V_204 ) ;
if ( V_49 != 0 )
goto V_110;
V_49 = - V_120 ;
if ( F_103 ( V_48 , NULL , & V_199 , V_170 ) )
goto V_226;
}
V_110:
return F_111 ( V_49 ) ;
V_226:
F_77 ( & V_48 -> V_18 ) ;
return V_48 ;
}
static struct V_47 * F_112 ( struct V_160 * V_128 )
{
struct V_145 * V_145 ;
struct V_47 * V_48 = NULL ;
struct V_212 * V_213 ;
int V_49 ;
if ( ! V_128 -> V_228 ) {
V_48 = F_109 ( V_128 ) ;
goto V_110;
}
V_49 = - V_120 ;
if ( ! ( V_128 -> V_162 . V_229 & V_230 ) )
goto V_1;
V_145 = F_113 ( V_128 -> V_146 -> V_178 , & V_128 -> V_161 . V_181 , & V_128 -> V_162 ) ;
V_49 = F_59 ( V_145 ) ;
if ( F_58 ( V_145 ) )
goto V_1;
V_49 = - V_231 ;
V_48 = F_114 ( V_145 , V_128 -> V_179 ) ;
if ( V_48 == NULL )
goto V_232;
if ( V_128 -> V_161 . V_233 != 0 ) {
int V_234 = 0 ;
F_104 () ;
V_213 = F_105 ( F_66 ( V_145 ) -> V_213 ) ;
if ( V_213 )
V_234 = V_213 -> V_171 ;
F_106 () ;
if ( ( V_234 & 1UL << V_214 ) == 0 )
F_115 ( V_48 -> V_145 ,
V_128 -> V_179 -> V_227 ,
& V_128 -> V_161 ) ;
else
F_116 ( V_48 -> V_145 ,
V_128 -> V_179 -> V_227 ,
& V_128 -> V_161 ) ;
}
F_103 ( V_48 , & V_128 -> V_161 . V_199 , NULL ,
V_128 -> V_165 . V_170 ) ;
F_117 ( V_145 ) ;
V_110:
return V_48 ;
V_232:
F_117 ( V_145 ) ;
V_1:
return F_111 ( V_49 ) ;
}
static struct V_235 * F_118 ( struct V_47 * V_48 )
{
struct V_149 * V_150 = F_66 ( V_48 -> V_145 ) ;
struct V_235 * V_236 ;
F_23 ( & V_48 -> V_145 -> V_151 ) ;
F_119 (ctx, &nfsi->open_files, list) {
if ( V_236 -> V_48 != V_48 )
continue;
F_120 ( V_236 ) ;
F_25 ( & V_48 -> V_145 -> V_151 ) ;
return V_236 ;
}
F_25 ( & V_48 -> V_145 -> V_151 ) ;
return F_111 ( - V_237 ) ;
}
static struct V_160 * F_121 ( struct V_235 * V_236 , struct V_47 * V_48 )
{
struct V_160 * V_225 ;
V_225 = F_70 ( V_236 -> V_13 , V_48 -> V_179 , 0 , 0 , NULL , V_238 ) ;
if ( V_225 == NULL )
return F_111 ( - V_231 ) ;
V_225 -> V_48 = V_48 ;
F_77 ( & V_48 -> V_18 ) ;
return V_225 ;
}
static int F_122 ( struct V_160 * V_225 , T_4 V_170 , struct V_47 * * V_30 )
{
struct V_47 * V_239 ;
int V_49 ;
V_225 -> V_165 . V_182 = 0 ;
V_225 -> V_165 . V_170 = V_170 ;
memset ( & V_225 -> V_161 , 0 , sizeof( V_225 -> V_161 ) ) ;
memset ( & V_225 -> V_166 , 0 , sizeof( V_225 -> V_166 ) ) ;
F_68 ( V_225 ) ;
V_49 = F_123 ( V_225 ) ;
if ( V_49 != 0 )
return V_49 ;
V_239 = F_112 ( V_225 ) ;
if ( F_58 ( V_239 ) )
return F_59 ( V_239 ) ;
F_124 ( V_239 , V_170 ) ;
* V_30 = V_239 ;
return 0 ;
}
static int F_125 ( struct V_160 * V_225 , struct V_47 * V_48 )
{
struct V_47 * V_239 ;
int V_49 ;
F_126 ( V_215 , & V_48 -> V_171 ) ;
F_127 () ;
if ( V_48 -> V_211 != 0 ) {
F_126 ( V_210 , & V_48 -> V_171 ) ;
V_49 = F_122 ( V_225 , V_183 | V_184 , & V_239 ) ;
if ( V_49 != 0 )
return V_49 ;
if ( V_239 != V_48 )
return - V_240 ;
}
if ( V_48 -> V_209 != 0 ) {
F_126 ( V_208 , & V_48 -> V_171 ) ;
V_49 = F_122 ( V_225 , V_184 , & V_239 ) ;
if ( V_49 != 0 )
return V_49 ;
if ( V_239 != V_48 )
return - V_240 ;
}
if ( V_48 -> V_207 != 0 ) {
F_126 ( V_206 , & V_48 -> V_171 ) ;
V_49 = F_122 ( V_225 , V_183 , & V_239 ) ;
if ( V_49 != 0 )
return V_49 ;
if ( V_239 != V_48 )
return - V_240 ;
}
if ( F_31 ( V_215 , & V_48 -> V_171 ) == 0 &&
memcmp ( V_48 -> V_199 . V_128 , V_48 -> V_216 . V_128 , sizeof( V_48 -> V_199 . V_128 ) ) != 0 ) {
F_100 ( & V_48 -> V_217 ) ;
if ( F_31 ( V_215 , & V_48 -> V_171 ) == 0 )
memcpy ( V_48 -> V_199 . V_128 , V_48 -> V_216 . V_128 , sizeof( V_48 -> V_199 . V_128 ) ) ;
F_101 ( & V_48 -> V_217 ) ;
}
return 0 ;
}
static int F_128 ( struct V_235 * V_236 , struct V_47 * V_48 )
{
struct V_212 * V_213 ;
struct V_160 * V_225 ;
T_4 V_233 = 0 ;
int V_241 ;
V_225 = F_121 ( V_236 , V_48 ) ;
if ( F_58 ( V_225 ) )
return F_59 ( V_225 ) ;
V_225 -> V_165 . V_193 = V_242 ;
V_225 -> V_165 . V_181 = F_78 ( V_48 -> V_145 ) ;
F_104 () ;
V_213 = F_105 ( F_66 ( V_48 -> V_145 ) -> V_213 ) ;
if ( V_213 != NULL && F_31 ( V_214 , & V_213 -> V_171 ) != 0 )
V_233 = V_213 -> type ;
F_106 () ;
V_225 -> V_165 . V_197 . V_233 = V_233 ;
V_241 = F_125 ( V_225 , V_48 ) ;
F_88 ( V_225 ) ;
return V_241 ;
}
static int F_129 ( struct V_235 * V_236 , struct V_47 * V_48 )
{
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_128 ( V_236 , V_48 ) ;
if ( V_1 != - V_71 )
break;
F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_130 ( struct V_168 * V_169 , struct V_47 * V_48 )
{
struct V_235 * V_236 ;
int V_49 ;
V_236 = F_118 ( V_48 ) ;
if ( F_58 ( V_236 ) )
return F_59 ( V_236 ) ;
V_49 = F_129 ( V_236 , V_48 ) ;
F_131 ( V_236 ) ;
return V_49 ;
}
static int F_132 ( struct V_235 * V_236 , struct V_47 * V_48 , const T_7 * V_199 )
{
struct V_160 * V_225 ;
int V_49 ;
V_225 = F_121 ( V_236 , V_48 ) ;
if ( F_58 ( V_225 ) )
return F_59 ( V_225 ) ;
V_225 -> V_165 . V_193 = V_243 ;
memcpy ( V_225 -> V_165 . V_197 . V_213 . V_128 , V_199 -> V_128 ,
sizeof( V_225 -> V_165 . V_197 . V_213 . V_128 ) ) ;
V_49 = F_125 ( V_225 , V_48 ) ;
F_88 ( V_225 ) ;
return V_49 ;
}
int F_133 ( struct V_235 * V_236 , struct V_47 * V_48 , const T_7 * V_199 )
{
struct V_45 V_46 = { } ;
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
int V_1 ;
do {
V_1 = F_132 ( V_236 , V_48 , V_199 ) ;
switch ( V_1 ) {
case 0 :
case - V_237 :
case - V_240 :
goto V_110;
case - V_59 :
case - V_60 :
case - V_61 :
case - V_62 :
case - V_63 :
F_20 ( V_43 -> V_28 -> V_66 ) ;
goto V_110;
case - V_57 :
case - V_56 :
case - V_55 :
F_18 ( V_43 -> V_28 ) ;
goto V_110;
case - V_41 :
case - V_51 :
case - V_52 :
F_17 ( V_43 , V_48 ) ;
case - V_72 :
case - V_231 :
V_1 = 0 ;
goto V_110;
}
V_1 = F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
V_110:
return V_1 ;
}
static void F_134 ( struct V_96 * V_97 , void * V_126 )
{
struct V_160 * V_128 = V_126 ;
V_128 -> V_244 = V_97 -> V_142 ;
if ( V_128 -> V_244 == 0 ) {
memcpy ( V_128 -> V_161 . V_199 . V_128 , V_128 -> V_166 . V_199 . V_128 ,
sizeof( V_128 -> V_161 . V_199 . V_128 ) ) ;
F_135 ( & V_128 -> V_179 -> V_176 , 0 ) ;
F_26 ( V_128 -> V_161 . V_43 , V_128 -> V_80 ) ;
V_128 -> V_228 = 1 ;
}
}
static void F_136 ( void * V_126 )
{
struct V_160 * V_128 = V_126 ;
struct V_47 * V_48 = NULL ;
if ( V_128 -> V_245 == 0 )
goto V_246;
if ( ! V_128 -> V_228 )
goto V_246;
V_48 = F_112 ( V_128 ) ;
if ( ! F_58 ( V_48 ) )
F_124 ( V_48 , V_128 -> V_165 . V_170 ) ;
V_246:
F_88 ( V_128 ) ;
}
static int F_137 ( struct V_160 * V_128 )
{
struct V_42 * V_43 = F_72 ( V_128 -> V_146 -> V_24 ) ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_249 ] ,
. V_250 = & V_128 -> V_167 ,
. V_251 = & V_128 -> V_166 ,
. V_252 = V_128 -> V_179 -> V_227 ,
} ;
struct V_135 V_253 = {
. V_137 = V_43 -> V_73 ,
. V_132 = & V_133 ,
. V_138 = & V_254 ,
. V_140 = V_128 ,
. V_255 = V_256 ,
. V_171 = V_257 ,
} ;
int V_241 ;
F_138 ( & V_128 -> V_200 ) ;
V_128 -> V_228 = 0 ;
V_128 -> V_244 = 0 ;
V_128 -> V_80 = V_125 ;
V_97 = F_57 ( & V_253 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
V_241 = F_90 ( V_97 ) ;
if ( V_241 != 0 ) {
V_128 -> V_245 = 1 ;
F_139 () ;
} else
V_241 = V_128 -> V_244 ;
F_60 ( V_97 ) ;
return V_241 ;
}
static void F_140 ( struct V_96 * V_97 , void * V_126 )
{
struct V_160 * V_128 = V_126 ;
struct V_168 * V_169 = V_128 -> V_179 ;
if ( F_141 ( V_128 -> V_165 . V_164 , V_97 ) != 0 )
return;
if ( V_128 -> V_48 != NULL ) {
struct V_212 * V_213 ;
if ( F_92 ( V_128 -> V_48 , V_128 -> V_165 . V_170 , V_128 -> V_165 . V_182 ) )
goto V_258;
F_104 () ;
V_213 = F_105 ( F_66 ( V_128 -> V_48 -> V_145 ) -> V_213 ) ;
if ( V_213 != NULL &&
F_31 ( V_214 , & V_213 -> V_171 ) == 0 ) {
F_106 () ;
goto V_258;
}
F_106 () ;
}
V_128 -> V_165 . V_187 = V_169 -> V_188 . V_187 ;
V_128 -> V_165 . V_185 = V_169 -> V_259 -> V_28 -> V_186 ;
if ( V_128 -> V_165 . V_193 == V_242 ) {
V_97 -> V_260 . V_247 = & V_248 [ V_261 ] ;
F_142 ( & V_128 -> V_161 . V_181 , V_128 -> V_165 . V_181 ) ;
}
V_128 -> V_80 = V_125 ;
if ( F_50 ( V_128 -> V_165 . V_43 ,
& V_128 -> V_165 . V_130 ,
& V_128 -> V_161 . V_131 , 1 , V_97 ) )
return;
F_53 ( V_97 ) ;
return;
V_258:
V_97 -> V_262 = NULL ;
}
static void F_143 ( struct V_96 * V_97 , void * V_126 )
{
F_33 ( V_97 , V_102 ) ;
F_140 ( V_97 , V_126 ) ;
}
static void F_144 ( struct V_96 * V_97 , void * V_126 )
{
struct V_160 * V_128 = V_126 ;
V_128 -> V_244 = V_97 -> V_142 ;
if ( ! F_41 ( V_97 , & V_128 -> V_161 . V_131 ) )
return;
if ( V_97 -> V_142 == 0 ) {
switch ( V_128 -> V_161 . V_162 -> V_203 & V_263 ) {
case V_264 :
break;
case V_265 :
V_128 -> V_244 = - V_266 ;
break;
case V_267 :
V_128 -> V_244 = - V_268 ;
break;
default:
V_128 -> V_244 = - V_269 ;
}
F_26 ( V_128 -> V_161 . V_43 , V_128 -> V_80 ) ;
if ( ! ( V_128 -> V_161 . V_270 & V_271 ) )
F_135 ( & V_128 -> V_179 -> V_176 , 0 ) ;
}
V_128 -> V_228 = 1 ;
}
static void F_145 ( void * V_126 )
{
struct V_160 * V_128 = V_126 ;
struct V_47 * V_48 = NULL ;
if ( V_128 -> V_245 == 0 )
goto V_246;
if ( V_128 -> V_244 != 0 || ! V_128 -> V_228 )
goto V_246;
if ( V_128 -> V_161 . V_270 & V_271 )
goto V_246;
V_48 = F_112 ( V_128 ) ;
if ( ! F_58 ( V_48 ) )
F_124 ( V_48 , V_128 -> V_165 . V_170 ) ;
V_246:
F_88 ( V_128 ) ;
}
static int F_146 ( struct V_160 * V_128 , int V_272 )
{
struct V_145 * V_146 = V_128 -> V_146 -> V_24 ;
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_273 * V_165 = & V_128 -> V_165 ;
struct V_274 * V_161 = & V_128 -> V_161 ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_275 ] ,
. V_250 = V_165 ,
. V_251 = V_161 ,
. V_252 = V_128 -> V_179 -> V_227 ,
} ;
struct V_135 V_253 = {
. V_137 = V_43 -> V_73 ,
. V_132 = & V_133 ,
. V_138 = & V_276 ,
. V_140 = V_128 ,
. V_255 = V_256 ,
. V_171 = V_257 ,
} ;
int V_241 ;
F_138 ( & V_128 -> V_200 ) ;
V_128 -> V_228 = 0 ;
V_128 -> V_244 = 0 ;
V_128 -> V_245 = 0 ;
if ( V_272 )
V_253 . V_138 = & V_277 ;
V_97 = F_57 ( & V_253 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
V_241 = F_90 ( V_97 ) ;
if ( V_241 != 0 ) {
V_128 -> V_245 = 1 ;
F_139 () ;
} else
V_241 = V_128 -> V_244 ;
F_60 ( V_97 ) ;
return V_241 ;
}
static int F_123 ( struct V_160 * V_128 )
{
struct V_145 * V_146 = V_128 -> V_146 -> V_24 ;
struct V_274 * V_161 = & V_128 -> V_161 ;
int V_241 ;
V_241 = F_146 ( V_128 , 1 ) ;
if ( V_241 != 0 || ! V_128 -> V_228 )
return V_241 ;
F_147 ( V_146 , V_161 -> V_163 ) ;
if ( V_161 -> V_270 & V_271 ) {
V_241 = F_137 ( V_128 ) ;
if ( V_241 != 0 )
return V_241 ;
}
return V_241 ;
}
static int F_148 ( struct V_160 * V_128 )
{
struct V_145 * V_146 = V_128 -> V_146 -> V_24 ;
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_273 * V_165 = & V_128 -> V_165 ;
struct V_274 * V_161 = & V_128 -> V_161 ;
int V_241 ;
V_241 = F_146 ( V_128 , 0 ) ;
if ( V_241 != 0 || ! V_128 -> V_228 )
return V_241 ;
if ( V_165 -> V_182 & V_195 ) {
F_65 ( V_146 , & V_161 -> V_148 ) ;
F_149 ( V_146 , V_161 -> V_163 ) ;
} else
F_147 ( V_146 , V_161 -> V_163 ) ;
if ( ( V_161 -> V_270 & V_278 ) == 0 )
V_43 -> V_76 &= ~ V_279 ;
if( V_161 -> V_270 & V_271 ) {
V_241 = F_137 ( V_128 ) ;
if ( V_241 != 0 )
return V_241 ;
}
if ( ! ( V_161 -> V_162 -> V_229 & V_230 ) )
F_150 ( V_43 , & V_161 -> V_181 , V_161 -> V_162 ) ;
return 0 ;
}
static int F_151 ( struct V_28 * V_29 )
{
unsigned int V_280 ;
int V_49 ;
for ( V_280 = V_281 ; V_280 != 0 ; V_280 -- ) {
V_49 = F_10 ( V_29 ) ;
if ( V_49 != 0 )
break;
if ( ! F_31 ( V_282 , & V_29 -> V_31 ) &&
! F_31 ( V_283 , & V_29 -> V_31 ) )
break;
F_152 ( V_29 ) ;
V_49 = - V_10 ;
}
return V_49 ;
}
static int F_153 ( struct V_42 * V_43 )
{
return F_151 ( V_43 -> V_28 ) ;
}
static int F_154 ( struct V_235 * V_236 , struct V_47 * V_48 )
{
struct V_160 * V_225 ;
int V_49 ;
V_225 = F_121 ( V_236 , V_48 ) ;
if ( F_58 ( V_225 ) )
return F_59 ( V_225 ) ;
V_49 = F_125 ( V_225 , V_48 ) ;
if ( V_49 == - V_240 )
F_155 ( V_236 -> V_13 ) ;
F_88 ( V_225 ) ;
return V_49 ;
}
static int F_156 ( struct V_235 * V_236 , struct V_47 * V_48 )
{
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_154 ( V_236 , V_48 ) ;
switch ( V_1 ) {
default:
goto V_110;
case - V_70 :
case - V_71 :
F_16 ( V_43 , V_1 , & V_46 ) ;
V_1 = 0 ;
}
} while ( V_46 . V_50 );
V_110:
return V_1 ;
}
static int F_157 ( struct V_168 * V_169 , struct V_47 * V_48 )
{
struct V_235 * V_236 ;
int V_49 ;
V_236 = F_118 ( V_48 ) ;
if ( F_58 ( V_236 ) )
return F_59 ( V_236 ) ;
V_49 = F_156 ( V_236 , V_48 ) ;
F_131 ( V_236 ) ;
return V_49 ;
}
static int F_158 ( struct V_168 * V_169 , struct V_47 * V_48 )
{
int V_241 ;
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
V_241 = F_159 ( V_43 , V_48 ) ;
if ( V_241 == V_109 )
return 0 ;
F_160 ( V_43 , V_48 ) ;
return F_157 ( V_169 , V_48 ) ;
}
static inline void F_161 ( struct V_160 * V_225 , struct V_172 * V_284 )
{
if ( ( V_225 -> V_161 . V_285 [ 1 ] & V_286 ) &&
! ( V_284 -> V_287 & V_288 ) )
V_284 -> V_287 |= V_289 ;
if ( ( V_225 -> V_161 . V_285 [ 1 ] & V_290 ) &&
! ( V_284 -> V_287 & V_291 ) )
V_284 -> V_287 |= V_292 ;
}
static int F_162 ( struct V_145 * V_146 , struct V_13 * V_13 , T_4 V_170 , int V_171 , struct V_172 * V_284 , struct V_252 * V_293 , struct V_47 * * V_30 )
{
struct V_168 * V_169 ;
struct V_47 * V_48 = NULL ;
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_160 * V_225 ;
int V_241 ;
V_241 = - V_231 ;
if ( ! ( V_169 = F_163 ( V_43 , V_293 ) ) ) {
F_2 ( L_25 ) ;
goto V_294;
}
V_241 = F_153 ( V_43 ) ;
if ( V_241 != 0 )
goto V_295;
if ( V_13 -> V_24 != NULL )
F_107 ( V_13 -> V_24 , V_170 ) ;
V_241 = - V_231 ;
V_225 = F_70 ( V_13 , V_169 , V_170 , V_171 , V_284 , V_296 ) ;
if ( V_225 == NULL )
goto V_295;
if ( V_13 -> V_24 != NULL )
V_225 -> V_48 = F_114 ( V_13 -> V_24 , V_169 ) ;
V_241 = F_148 ( V_225 ) ;
if ( V_241 != 0 )
goto V_297;
V_48 = F_112 ( V_225 ) ;
V_241 = F_59 ( V_48 ) ;
if ( F_58 ( V_48 ) )
goto V_297;
if ( V_43 -> V_76 & V_279 )
F_98 ( V_298 , & V_48 -> V_171 ) ;
if ( V_225 -> V_165 . V_182 & V_205 ) {
F_161 ( V_225 , V_284 ) ;
F_69 ( V_225 -> V_161 . V_162 ) ;
V_241 = F_164 ( V_48 -> V_145 , V_293 ,
V_225 -> V_161 . V_162 , V_284 ,
V_48 ) ;
if ( V_241 == 0 )
F_165 ( V_48 -> V_145 , V_284 ) ;
F_149 ( V_48 -> V_145 , V_225 -> V_161 . V_162 ) ;
}
F_88 ( V_225 ) ;
F_86 ( V_169 ) ;
* V_30 = V_48 ;
return 0 ;
V_297:
F_88 ( V_225 ) ;
V_295:
F_86 ( V_169 ) ;
V_294:
* V_30 = NULL ;
return V_241 ;
}
static struct V_47 * F_166 ( struct V_145 * V_146 , struct V_13 * V_13 , T_4 V_170 , int V_171 , struct V_172 * V_284 , struct V_252 * V_293 )
{
struct V_45 V_46 = { } ;
struct V_47 * V_30 ;
int V_241 ;
do {
V_241 = F_162 ( V_146 , V_13 , V_170 , V_171 , V_284 , V_293 , & V_30 ) ;
if ( V_241 == 0 )
break;
if ( V_241 == - V_299 ) {
F_21 ( V_78 L_5
L_26 ,
F_72 ( V_146 ) -> V_28 -> V_79 ) ;
V_46 . V_50 = 1 ;
continue;
}
if ( V_241 == - V_52 ) {
V_46 . V_50 = 1 ;
continue;
}
if ( V_241 == - V_120 ) {
V_46 . V_50 = 1 ;
continue;
}
V_30 = F_111 ( F_16 ( F_72 ( V_146 ) ,
V_241 , & V_46 ) ) ;
} while ( V_46 . V_50 );
return V_30 ;
}
static int F_167 ( struct V_145 * V_145 , struct V_252 * V_293 ,
struct V_300 * V_301 , struct V_172 * V_284 ,
struct V_47 * V_48 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_302 V_303 = {
. V_181 = F_78 ( V_145 ) ,
. V_304 = V_284 ,
. V_43 = V_43 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_305 V_30 = {
. V_301 = V_301 ,
. V_43 = V_43 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_306 ] ,
. V_250 = & V_303 ,
. V_251 = & V_30 ,
. V_252 = V_293 ,
} ;
unsigned long V_80 = V_125 ;
int V_241 ;
F_69 ( V_301 ) ;
if ( F_168 ( & V_303 . V_199 , V_145 ) ) {
} else if ( V_48 != NULL ) {
F_169 ( & V_303 . V_199 , V_48 , V_40 -> V_307 , V_40 -> V_308 ) ;
} else
memcpy ( & V_303 . V_199 , & V_309 , sizeof( V_303 . V_199 ) ) ;
V_241 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & V_303 . V_130 , & V_30 . V_131 , 1 ) ;
if ( V_241 == 0 && V_48 != NULL )
F_26 ( V_43 , V_80 ) ;
return V_241 ;
}
static int F_164 ( struct V_145 * V_145 , struct V_252 * V_293 ,
struct V_300 * V_301 , struct V_172 * V_284 ,
struct V_47 * V_48 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_167 ( V_145 , V_293 , V_301 , V_284 , V_48 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static void F_170 ( void * V_128 )
{
struct V_310 * V_126 = V_128 ;
struct V_168 * V_169 = V_126 -> V_48 -> V_179 ;
struct V_201 * V_202 = V_126 -> V_48 -> V_145 -> V_311 ;
if ( V_126 -> V_312 )
F_171 ( V_126 -> V_48 -> V_145 ) ;
F_85 ( V_126 -> V_48 ) ;
F_84 ( V_126 -> V_303 . V_164 ) ;
F_86 ( V_169 ) ;
F_87 ( V_202 ) ;
F_80 ( V_126 ) ;
}
static void F_172 ( struct V_47 * V_48 ,
T_4 V_170 )
{
F_23 ( & V_48 -> V_179 -> V_219 ) ;
if ( ! ( V_170 & V_183 ) )
F_126 ( V_206 , & V_48 -> V_171 ) ;
if ( ! ( V_170 & V_184 ) )
F_126 ( V_208 , & V_48 -> V_171 ) ;
F_126 ( V_210 , & V_48 -> V_171 ) ;
F_25 ( & V_48 -> V_179 -> V_219 ) ;
}
static void F_173 ( struct V_96 * V_97 , void * V_128 )
{
struct V_310 * V_126 = V_128 ;
struct V_47 * V_48 = V_126 -> V_48 ;
struct V_42 * V_43 = F_72 ( V_126 -> V_145 ) ;
if ( ! F_41 ( V_97 , & V_126 -> V_30 . V_131 ) )
return;
switch ( V_97 -> V_142 ) {
case 0 :
if ( V_126 -> V_312 )
F_174 ( V_48 -> V_145 ,
V_126 -> V_313 ) ;
F_99 ( V_48 , & V_126 -> V_30 . V_199 , 0 ) ;
F_26 ( V_43 , V_126 -> V_80 ) ;
F_172 ( V_48 ,
V_126 -> V_303 . V_170 ) ;
break;
case - V_56 :
case - V_75 :
case - V_52 :
case - V_55 :
if ( V_126 -> V_303 . V_170 == 0 )
break;
default:
if ( F_175 ( V_97 , V_43 , V_48 ) == - V_120 )
F_176 ( V_97 ) ;
}
F_177 ( V_126 -> V_303 . V_164 ) ;
F_147 ( V_126 -> V_145 , V_126 -> V_30 . V_301 ) ;
}
static void F_178 ( struct V_96 * V_97 , void * V_128 )
{
struct V_310 * V_126 = V_128 ;
struct V_47 * V_48 = V_126 -> V_48 ;
int V_314 = 0 ;
if ( F_141 ( V_126 -> V_303 . V_164 , V_97 ) != 0 )
return;
V_97 -> V_260 . V_247 = & V_248 [ V_315 ] ;
V_126 -> V_303 . V_170 = V_183 | V_184 ;
F_23 ( & V_48 -> V_179 -> V_219 ) ;
if ( V_48 -> V_211 == 0 ) {
if ( V_48 -> V_207 == 0 ) {
V_314 |= F_31 ( V_206 , & V_48 -> V_171 ) ;
V_314 |= F_31 ( V_210 , & V_48 -> V_171 ) ;
V_126 -> V_303 . V_170 &= ~ V_183 ;
}
if ( V_48 -> V_209 == 0 ) {
V_314 |= F_31 ( V_208 , & V_48 -> V_171 ) ;
V_314 |= F_31 ( V_210 , & V_48 -> V_171 ) ;
V_126 -> V_303 . V_170 &= ~ V_184 ;
}
}
F_25 ( & V_48 -> V_179 -> V_219 ) ;
if ( ! V_314 ) {
V_97 -> V_262 = NULL ;
return;
}
if ( V_126 -> V_303 . V_170 == 0 ) {
V_97 -> V_260 . V_247 = & V_248 [ V_316 ] ;
if ( V_126 -> V_312 &&
F_179 ( V_126 -> V_145 , & V_126 -> V_313 ) ) {
F_48 ( & F_72 ( V_126 -> V_145 ) -> V_317 ,
V_97 , NULL ) ;
return;
}
}
F_69 ( V_126 -> V_30 . V_301 ) ;
V_126 -> V_80 = V_125 ;
if ( F_50 ( F_72 ( V_126 -> V_145 ) ,
& V_126 -> V_303 . V_130 , & V_126 -> V_30 . V_131 ,
1 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
int F_180 ( struct V_47 * V_48 , T_5 V_174 , int V_318 , bool V_312 )
{
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
struct V_310 * V_126 ;
struct V_168 * V_169 = V_48 -> V_179 ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_316 ] ,
. V_252 = V_48 -> V_179 -> V_227 ,
} ;
struct V_135 V_253 = {
. V_137 = V_43 -> V_73 ,
. V_132 = & V_133 ,
. V_138 = & V_319 ,
. V_255 = V_256 ,
. V_171 = V_257 ,
} ;
int V_241 = - V_231 ;
V_126 = F_73 ( sizeof( * V_126 ) , V_174 ) ;
if ( V_126 == NULL )
goto V_110;
V_126 -> V_145 = V_48 -> V_145 ;
V_126 -> V_48 = V_48 ;
V_126 -> V_303 . V_181 = F_78 ( V_48 -> V_145 ) ;
V_126 -> V_303 . V_199 = & V_48 -> V_216 ;
V_126 -> V_303 . V_164 = F_74 ( & V_48 -> V_179 -> V_176 , V_174 ) ;
if ( V_126 -> V_303 . V_164 == NULL )
goto V_320;
V_126 -> V_303 . V_170 = 0 ;
V_126 -> V_303 . V_191 = V_43 -> V_321 ;
V_126 -> V_30 . V_301 = & V_126 -> V_301 ;
V_126 -> V_30 . V_164 = V_126 -> V_303 . V_164 ;
V_126 -> V_30 . V_43 = V_43 ;
V_126 -> V_312 = V_312 ;
F_75 ( V_126 -> V_145 -> V_311 ) ;
V_133 . V_250 = & V_126 -> V_303 ;
V_133 . V_251 = & V_126 -> V_30 ;
V_253 . V_140 = V_126 ;
V_97 = F_57 ( & V_253 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
V_241 = 0 ;
if ( V_318 )
V_241 = F_91 ( V_97 ) ;
F_60 ( V_97 ) ;
return V_241 ;
V_320:
F_80 ( V_126 ) ;
V_110:
if ( V_312 )
F_171 ( V_48 -> V_145 ) ;
F_85 ( V_48 ) ;
F_86 ( V_169 ) ;
return V_241 ;
}
static struct V_145 *
F_181 ( struct V_145 * V_146 , struct V_235 * V_236 , int V_182 , struct V_172 * V_322 )
{
struct V_47 * V_48 ;
V_48 = F_166 ( V_146 , V_236 -> V_13 , V_236 -> V_203 , V_182 , V_322 , V_236 -> V_293 ) ;
if ( F_58 ( V_48 ) )
return F_182 ( V_48 ) ;
V_236 -> V_48 = V_48 ;
return F_183 ( V_48 -> V_145 ) ;
}
static void F_184 ( struct V_235 * V_236 , int V_323 )
{
if ( V_236 -> V_48 == NULL )
return;
if ( V_323 )
F_185 ( V_236 -> V_48 , V_236 -> V_203 ) ;
else
F_124 ( V_236 -> V_48 , V_236 -> V_203 ) ;
}
static int F_186 ( struct V_42 * V_43 , struct V_324 * V_325 )
{
struct V_326 args = {
. V_325 = V_325 ,
} ;
struct V_327 V_30 = {} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_328 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
int V_241 ;
V_241 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
if ( V_241 == 0 ) {
memcpy ( V_43 -> V_192 , V_30 . V_192 , sizeof( V_43 -> V_192 ) ) ;
V_43 -> V_76 &= ~ ( V_329 | V_330 |
V_331 | V_332 |
V_333 | V_334 | V_335 |
V_336 | V_337 |
V_338 | V_339 ) ;
if ( V_30 . V_192 [ 0 ] & V_340 )
V_43 -> V_76 |= V_329 ;
if ( V_30 . V_341 != 0 )
V_43 -> V_76 |= V_330 ;
if ( V_30 . V_342 != 0 )
V_43 -> V_76 |= V_331 ;
if ( V_30 . V_192 [ 0 ] & V_23 )
V_43 -> V_76 |= V_332 ;
if ( V_30 . V_192 [ 1 ] & V_343 )
V_43 -> V_76 |= V_333 ;
if ( V_30 . V_192 [ 1 ] & V_344 )
V_43 -> V_76 |= V_334 ;
if ( V_30 . V_192 [ 1 ] & V_345 )
V_43 -> V_76 |= V_335 ;
if ( V_30 . V_192 [ 1 ] & V_346 )
V_43 -> V_76 |= V_336 ;
if ( V_30 . V_192 [ 1 ] & V_286 )
V_43 -> V_76 |= V_337 ;
if ( V_30 . V_192 [ 1 ] & V_347 )
V_43 -> V_76 |= V_338 ;
if ( V_30 . V_192 [ 1 ] & V_290 )
V_43 -> V_76 |= V_339 ;
memcpy ( V_43 -> V_321 , V_30 . V_192 , sizeof( V_43 -> V_321 ) ) ;
V_43 -> V_321 [ 0 ] &= V_348 | V_349 ;
V_43 -> V_321 [ 1 ] &= V_347 | V_290 ;
V_43 -> V_350 = V_30 . V_350 ;
}
return V_241 ;
}
int F_187 ( struct V_42 * V_43 , struct V_324 * V_325 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_186 ( V_43 , V_325 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_188 ( struct V_42 * V_43 , struct V_324 * V_325 ,
struct V_351 * V_352 )
{
struct V_353 args = {
. V_191 = V_354 ,
} ;
struct V_355 V_30 = {
. V_43 = V_43 ,
. V_301 = V_352 -> V_301 ,
. V_181 = V_325 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_356 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
F_69 ( V_352 -> V_301 ) ;
return F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
}
static int F_189 ( struct V_42 * V_43 , struct V_324 * V_325 ,
struct V_351 * V_352 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_188 ( V_43 , V_325 , V_352 ) ;
switch ( V_1 ) {
case 0 :
case - V_4 :
break;
default:
V_1 = F_16 ( V_43 , V_1 , & V_46 ) ;
}
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_190 ( struct V_42 * V_43 , struct V_324 * V_325 ,
struct V_351 * V_352 , T_8 V_357 )
{
struct V_358 * V_359 ;
int V_49 ;
V_359 = F_191 ( V_357 , V_43 -> V_73 ) ;
if ( ! V_359 ) {
V_49 = - V_10 ;
goto V_110;
}
V_49 = F_189 ( V_43 , V_325 , V_352 ) ;
V_110:
return V_49 ;
}
static int F_192 ( struct V_42 * V_43 , struct V_324 * V_325 ,
struct V_351 * V_352 )
{
int V_360 , V_361 , V_241 = 0 ;
T_8 V_362 [ V_363 ] ;
V_361 = F_193 ( & V_362 [ 0 ] ) ;
V_362 [ V_361 ] = V_364 ;
V_361 += 1 ;
for ( V_360 = 0 ; V_360 < V_361 ; V_360 ++ ) {
V_241 = F_190 ( V_43 , V_325 , V_352 , V_362 [ V_360 ] ) ;
if ( V_241 == - V_4 || V_241 == - V_365 )
continue;
break;
}
if ( V_241 == - V_365 )
V_241 = - V_5 ;
return V_241 ;
}
static int F_194 ( struct V_42 * V_43 , struct V_324 * V_325 ,
struct V_351 * V_352 )
{
int V_366 = V_43 -> V_28 -> V_367 ;
int V_241 = F_189 ( V_43 , V_325 , V_352 ) ;
if ( ( V_241 == - V_4 ) && ! ( V_43 -> V_171 & V_368 ) )
V_241 = V_369 [ V_366 ] -> F_195 ( V_43 , V_325 , V_352 ) ;
if ( V_241 == 0 )
V_241 = F_187 ( V_43 , V_325 ) ;
if ( V_241 == 0 )
V_241 = F_196 ( V_43 , V_325 , V_352 ) ;
return F_1 ( V_241 ) ;
}
static int F_197 ( struct V_145 * V_146 , const struct V_370 * V_189 ,
struct V_300 * V_301 , struct V_324 * V_325 )
{
int V_241 = - V_231 ;
struct V_371 * V_371 = NULL ;
struct V_372 * V_373 = NULL ;
V_371 = F_198 ( V_296 ) ;
if ( V_371 == NULL )
goto V_110;
V_373 = F_199 ( sizeof( struct V_372 ) , V_296 ) ;
if ( V_373 == NULL )
goto V_110;
V_241 = F_200 ( V_146 , V_189 , V_373 , V_371 ) ;
if ( V_241 != 0 )
goto V_110;
if ( F_201 ( & F_72 ( V_146 ) -> V_374 , & V_373 -> V_301 . V_374 ) ) {
F_2 ( L_27
L_28 , V_9 , V_189 -> V_189 ) ;
V_241 = - V_10 ;
goto V_110;
}
F_202 ( & V_373 -> V_301 ) ;
memcpy ( V_301 , & V_373 -> V_301 , sizeof( struct V_300 ) ) ;
memset ( V_325 , 0 , sizeof( struct V_324 ) ) ;
V_110:
if ( V_371 )
F_203 ( V_371 ) ;
F_80 ( V_373 ) ;
return V_241 ;
}
static int F_150 ( struct V_42 * V_43 , struct V_324 * V_325 , struct V_300 * V_301 )
{
struct V_375 args = {
. V_181 = V_325 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_376 V_30 = {
. V_301 = V_301 ,
. V_43 = V_43 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_377 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
F_69 ( V_301 ) ;
return F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
}
static int F_204 ( struct V_42 * V_43 , struct V_324 * V_325 , struct V_300 * V_301 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_150 ( V_43 , V_325 , V_301 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_205 ( struct V_13 * V_13 , struct V_300 * V_301 ,
struct V_172 * V_284 )
{
struct V_145 * V_145 = V_13 -> V_24 ;
struct V_252 * V_293 = NULL ;
struct V_47 * V_48 = NULL ;
int V_241 ;
if ( F_206 ( V_145 ) )
F_207 ( V_145 ) ;
F_69 ( V_301 ) ;
if ( V_284 -> V_287 & V_378 ) {
struct V_235 * V_236 ;
V_236 = F_208 ( V_284 -> V_379 ) ;
if ( V_236 ) {
V_293 = V_236 -> V_293 ;
V_48 = V_236 -> V_48 ;
}
}
V_241 = F_164 ( V_145 , V_293 , V_301 , V_284 , V_48 ) ;
if ( V_241 == 0 )
F_165 ( V_145 , V_284 ) ;
return V_241 ;
}
static int F_209 ( struct V_35 * V_36 , struct V_42 * V_43 ,
const struct V_324 * V_380 , const struct V_370 * V_189 ,
struct V_324 * V_325 , struct V_300 * V_301 )
{
int V_241 ;
struct V_381 args = {
. V_191 = V_43 -> V_192 ,
. V_382 = V_380 ,
. V_189 = V_189 ,
} ;
struct V_355 V_30 = {
. V_43 = V_43 ,
. V_301 = V_301 ,
. V_181 = V_325 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_383 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
F_69 ( V_301 ) ;
F_2 ( L_29 , V_189 -> V_189 ) ;
V_241 = F_64 ( V_36 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
F_2 ( L_30 , V_241 ) ;
return V_241 ;
}
static int F_210 ( struct V_42 * V_43 , struct V_324 * V_380 ,
struct V_370 * V_189 , struct V_324 * V_325 ,
struct V_300 * V_301 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_209 ( V_43 -> V_73 , V_43 , V_380 , V_189 , V_325 , V_301 ) ;
if ( V_1 == - V_384 ) {
V_1 = - V_385 ;
break;
}
V_1 = F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_211 ( struct V_35 * V_36 , struct V_145 * V_146 ,
const struct V_370 * V_189 , struct V_324 * V_325 ,
struct V_300 * V_301 )
{
int V_241 ;
F_2 ( L_31 , V_189 -> V_189 ) ;
V_241 = F_209 ( V_36 , F_72 ( V_146 ) , F_78 ( V_146 ) , V_189 , V_325 , V_301 ) ;
if ( V_241 == - V_384 )
V_241 = F_197 ( V_146 , V_189 , V_301 , V_325 ) ;
F_2 ( L_32 , V_241 ) ;
return V_241 ;
}
void F_212 ( struct V_300 * V_301 , struct V_324 * V_181 )
{
memset ( V_181 , 0 , sizeof( struct V_324 ) ) ;
V_301 -> V_374 . V_386 = 1 ;
V_301 -> V_229 |= V_387 | V_388 |
V_389 | V_390 | V_391 ;
V_301 -> V_203 = V_267 | V_392 | V_393 ;
V_301 -> V_394 = 2 ;
}
static int F_213 ( struct V_35 * V_36 , struct V_145 * V_146 , struct V_370 * V_189 ,
struct V_324 * V_325 , struct V_300 * V_301 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_146 ) ,
F_211 ( V_36 , V_146 , V_189 , V_325 , V_301 ) ,
& V_46 ) ;
if ( V_1 == - V_5 )
F_212 ( V_301 , V_325 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_214 ( struct V_145 * V_145 , struct V_395 * V_396 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_397 args = {
. V_181 = F_78 ( V_145 ) ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_398 V_30 = {
. V_43 = V_43 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_399 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
. V_252 = V_396 -> V_293 ,
} ;
int V_203 = V_396 -> V_400 ;
int V_241 ;
if ( V_203 & V_401 )
args . V_402 |= V_403 ;
if ( F_215 ( V_145 -> V_404 ) ) {
if ( V_203 & V_405 )
args . V_402 |= V_406 | V_407 | V_408 ;
if ( V_203 & V_409 )
args . V_402 |= V_410 ;
} else {
if ( V_203 & V_405 )
args . V_402 |= V_406 | V_407 ;
if ( V_203 & V_409 )
args . V_402 |= V_411 ;
}
V_30 . V_301 = F_216 () ;
if ( V_30 . V_301 == NULL )
return - V_231 ;
V_241 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
if ( ! V_241 ) {
V_396 -> V_400 = 0 ;
if ( V_30 . V_402 & V_403 )
V_396 -> V_400 |= V_401 ;
if ( V_30 . V_402 & ( V_406 | V_407 | V_408 ) )
V_396 -> V_400 |= V_405 ;
if ( V_30 . V_402 & ( V_410 | V_411 ) )
V_396 -> V_400 |= V_409 ;
F_147 ( V_145 , V_30 . V_301 ) ;
}
F_217 ( V_30 . V_301 ) ;
return V_241 ;
}
static int F_218 ( struct V_145 * V_145 , struct V_395 * V_396 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_145 ) ,
F_214 ( V_145 , V_396 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_219 ( struct V_145 * V_145 , struct V_371 * V_371 ,
unsigned int V_27 , unsigned int V_412 )
{
struct V_413 args = {
. V_181 = F_78 ( V_145 ) ,
. V_27 = V_27 ,
. V_412 = V_412 ,
. V_19 = & V_371 ,
} ;
struct V_414 V_30 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_415 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
return F_64 ( F_72 ( V_145 ) -> V_73 , F_72 ( V_145 ) , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
}
static int F_220 ( struct V_145 * V_145 , struct V_371 * V_371 ,
unsigned int V_27 , unsigned int V_412 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_145 ) ,
F_219 ( V_145 , V_371 , V_27 , V_412 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_221 ( struct V_145 * V_146 , struct V_13 * V_13 , struct V_172 * V_284 ,
int V_171 , struct V_235 * V_236 )
{
struct V_13 * V_416 = V_13 ;
struct V_47 * V_48 ;
struct V_252 * V_293 = NULL ;
T_4 V_170 = 0 ;
int V_241 = 0 ;
if ( V_236 != NULL ) {
V_293 = V_236 -> V_293 ;
V_416 = V_236 -> V_13 ;
V_170 = V_236 -> V_203 ;
}
V_284 -> V_417 &= ~ F_222 () ;
V_48 = F_166 ( V_146 , V_416 , V_170 , V_171 , V_284 , V_293 ) ;
F_155 ( V_13 ) ;
if ( F_58 ( V_48 ) ) {
V_241 = F_59 ( V_48 ) ;
goto V_110;
}
F_223 ( V_13 , F_183 ( V_48 -> V_145 ) ) ;
F_224 ( V_13 , F_225 ( V_146 ) ) ;
if ( V_236 != NULL )
V_236 -> V_48 = V_48 ;
else
F_185 ( V_48 , V_170 ) ;
V_110:
return V_241 ;
}
static int F_226 ( struct V_145 * V_146 , struct V_370 * V_189 )
{
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_418 args = {
. V_181 = F_78 ( V_146 ) ,
. V_189 . V_361 = V_189 -> V_361 ,
. V_189 . V_189 = V_189 -> V_189 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_419 V_30 = {
. V_43 = V_43 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_420 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
int V_241 = - V_231 ;
V_30 . V_163 = F_216 () ;
if ( V_30 . V_163 == NULL )
goto V_110;
V_241 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 1 ) ;
if ( V_241 == 0 ) {
F_65 ( V_146 , & V_30 . V_148 ) ;
F_149 ( V_146 , V_30 . V_163 ) ;
}
F_217 ( V_30 . V_163 ) ;
V_110:
return V_241 ;
}
static int F_227 ( struct V_145 * V_146 , struct V_370 * V_189 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_146 ) ,
F_226 ( V_146 , V_189 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static void F_228 ( struct V_132 * V_133 , struct V_145 * V_146 )
{
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_418 * args = V_133 -> V_250 ;
struct V_419 * V_30 = V_133 -> V_251 ;
args -> V_191 = V_43 -> V_321 ;
V_30 -> V_43 = V_43 ;
V_30 -> V_131 . V_106 = NULL ;
V_133 -> V_247 = & V_248 [ V_420 ] ;
}
static int F_229 ( struct V_96 * V_97 , struct V_145 * V_146 )
{
struct V_419 * V_30 = V_97 -> V_260 . V_251 ;
if ( ! F_41 ( V_97 , & V_30 -> V_131 ) )
return 0 ;
if ( F_175 ( V_97 , V_30 -> V_43 , NULL ) == - V_120 )
return 0 ;
F_65 ( V_146 , & V_30 -> V_148 ) ;
F_149 ( V_146 , V_30 -> V_163 ) ;
return 1 ;
}
static void F_230 ( struct V_132 * V_133 , struct V_145 * V_146 )
{
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_421 * V_303 = V_133 -> V_250 ;
struct V_422 * V_30 = V_133 -> V_251 ;
V_133 -> V_247 = & V_248 [ V_423 ] ;
V_303 -> V_191 = V_43 -> V_192 ;
V_30 -> V_43 = V_43 ;
}
static int F_231 ( struct V_96 * V_97 , struct V_145 * V_424 ,
struct V_145 * V_425 )
{
struct V_422 * V_30 = V_97 -> V_260 . V_251 ;
if ( ! F_41 ( V_97 , & V_30 -> V_131 ) )
return 0 ;
if ( F_175 ( V_97 , V_30 -> V_43 , NULL ) == - V_120 )
return 0 ;
F_65 ( V_424 , & V_30 -> V_426 ) ;
F_149 ( V_424 , V_30 -> V_427 ) ;
F_65 ( V_425 , & V_30 -> V_428 ) ;
F_149 ( V_425 , V_30 -> V_429 ) ;
return 1 ;
}
static int F_232 ( struct V_145 * V_424 , struct V_370 * V_430 ,
struct V_145 * V_425 , struct V_370 * V_431 )
{
struct V_42 * V_43 = F_72 ( V_424 ) ;
struct V_421 V_303 = {
. V_424 = F_78 ( V_424 ) ,
. V_425 = F_78 ( V_425 ) ,
. V_430 = V_430 ,
. V_431 = V_431 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_422 V_30 = {
. V_43 = V_43 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_423 ] ,
. V_250 = & V_303 ,
. V_251 = & V_30 ,
} ;
int V_241 = - V_231 ;
V_30 . V_427 = F_216 () ;
V_30 . V_429 = F_216 () ;
if ( V_30 . V_427 == NULL || V_30 . V_429 == NULL )
goto V_110;
V_241 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & V_303 . V_130 , & V_30 . V_131 , 1 ) ;
if ( ! V_241 ) {
F_65 ( V_424 , & V_30 . V_426 ) ;
F_149 ( V_424 , V_30 . V_427 ) ;
F_65 ( V_425 , & V_30 . V_428 ) ;
F_149 ( V_425 , V_30 . V_429 ) ;
}
V_110:
F_217 ( V_30 . V_429 ) ;
F_217 ( V_30 . V_427 ) ;
return V_241 ;
}
static int F_233 ( struct V_145 * V_424 , struct V_370 * V_430 ,
struct V_145 * V_425 , struct V_370 * V_431 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_424 ) ,
F_232 ( V_424 , V_430 ,
V_425 , V_431 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_234 ( struct V_145 * V_145 , struct V_145 * V_146 , struct V_370 * V_189 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_432 V_303 = {
. V_181 = F_78 ( V_145 ) ,
. V_382 = F_78 ( V_146 ) ,
. V_189 = V_189 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_433 V_30 = {
. V_43 = V_43 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_434 ] ,
. V_250 = & V_303 ,
. V_251 = & V_30 ,
} ;
int V_241 = - V_231 ;
V_30 . V_301 = F_216 () ;
V_30 . V_163 = F_216 () ;
if ( V_30 . V_301 == NULL || V_30 . V_163 == NULL )
goto V_110;
V_241 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & V_303 . V_130 , & V_30 . V_131 , 1 ) ;
if ( ! V_241 ) {
F_65 ( V_146 , & V_30 . V_148 ) ;
F_149 ( V_146 , V_30 . V_163 ) ;
F_149 ( V_145 , V_30 . V_301 ) ;
}
V_110:
F_217 ( V_30 . V_163 ) ;
F_217 ( V_30 . V_301 ) ;
return V_241 ;
}
static int F_235 ( struct V_145 * V_145 , struct V_145 * V_146 , struct V_370 * V_189 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_145 ) ,
F_234 ( V_145 , V_146 , V_189 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static struct V_435 * F_236 ( struct V_145 * V_146 ,
struct V_370 * V_189 , struct V_172 * V_284 , T_6 V_436 )
{
struct V_435 * V_128 ;
V_128 = F_73 ( sizeof( * V_128 ) , V_296 ) ;
if ( V_128 != NULL ) {
struct V_42 * V_43 = F_72 ( V_146 ) ;
V_128 -> V_133 . V_247 = & V_248 [ V_437 ] ;
V_128 -> V_133 . V_250 = & V_128 -> V_303 ;
V_128 -> V_133 . V_251 = & V_128 -> V_30 ;
V_128 -> V_303 . V_382 = F_78 ( V_146 ) ;
V_128 -> V_303 . V_43 = V_43 ;
V_128 -> V_303 . V_189 = V_189 ;
V_128 -> V_303 . V_173 = V_284 ;
V_128 -> V_303 . V_436 = V_436 ;
V_128 -> V_303 . V_191 = V_43 -> V_192 ;
V_128 -> V_30 . V_43 = V_43 ;
V_128 -> V_30 . V_181 = & V_128 -> V_181 ;
V_128 -> V_30 . V_301 = & V_128 -> V_301 ;
V_128 -> V_30 . V_438 = & V_128 -> V_438 ;
F_69 ( V_128 -> V_30 . V_301 ) ;
F_69 ( V_128 -> V_30 . V_438 ) ;
}
return V_128 ;
}
static int F_237 ( struct V_145 * V_146 , struct V_13 * V_13 , struct V_435 * V_128 )
{
int V_241 = F_64 ( F_72 ( V_146 ) -> V_73 , F_72 ( V_146 ) , & V_128 -> V_133 ,
& V_128 -> V_303 . V_130 , & V_128 -> V_30 . V_131 , 1 ) ;
if ( V_241 == 0 ) {
F_65 ( V_146 , & V_128 -> V_30 . V_439 ) ;
F_149 ( V_146 , V_128 -> V_30 . V_438 ) ;
V_241 = F_238 ( V_13 , V_128 -> V_30 . V_181 , V_128 -> V_30 . V_301 ) ;
}
return V_241 ;
}
static void F_239 ( struct V_435 * V_128 )
{
F_80 ( V_128 ) ;
}
static int F_240 ( struct V_145 * V_146 , struct V_13 * V_13 ,
struct V_371 * V_371 , unsigned int V_361 , struct V_172 * V_284 )
{
struct V_435 * V_128 ;
int V_241 = - V_440 ;
if ( V_361 > V_441 )
goto V_110;
V_241 = - V_231 ;
V_128 = F_236 ( V_146 , & V_13 -> V_190 , V_284 , V_442 ) ;
if ( V_128 == NULL )
goto V_110;
V_128 -> V_133 . V_247 = & V_248 [ V_443 ] ;
V_128 -> V_303 . V_197 . V_444 . V_19 = & V_371 ;
V_128 -> V_303 . V_197 . V_444 . V_361 = V_361 ;
V_241 = F_237 ( V_146 , V_13 , V_128 ) ;
F_239 ( V_128 ) ;
V_110:
return V_241 ;
}
static int F_241 ( struct V_145 * V_146 , struct V_13 * V_13 ,
struct V_371 * V_371 , unsigned int V_361 , struct V_172 * V_284 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_146 ) ,
F_240 ( V_146 , V_13 , V_371 ,
V_361 , V_284 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_242 ( struct V_145 * V_146 , struct V_13 * V_13 ,
struct V_172 * V_284 )
{
struct V_435 * V_128 ;
int V_241 = - V_231 ;
V_128 = F_236 ( V_146 , & V_13 -> V_190 , V_284 , V_445 ) ;
if ( V_128 == NULL )
goto V_110;
V_241 = F_237 ( V_146 , V_13 , V_128 ) ;
F_239 ( V_128 ) ;
V_110:
return V_241 ;
}
static int F_243 ( struct V_145 * V_146 , struct V_13 * V_13 ,
struct V_172 * V_284 )
{
struct V_45 V_46 = { } ;
int V_1 ;
V_284 -> V_417 &= ~ F_222 () ;
do {
V_1 = F_16 ( F_72 ( V_146 ) ,
F_242 ( V_146 , V_13 , V_284 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_244 ( struct V_13 * V_13 , struct V_252 * V_293 ,
T_1 V_11 , struct V_371 * * V_19 , unsigned int V_18 , int V_446 )
{
struct V_145 * V_146 = V_13 -> V_24 ;
struct V_14 args = {
. V_181 = F_78 ( V_146 ) ,
. V_19 = V_19 ,
. V_27 = 0 ,
. V_18 = V_18 ,
. V_191 = F_72 ( V_13 -> V_24 ) -> V_192 ,
. V_446 = V_446 ,
} ;
struct V_447 V_30 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_448 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
. V_252 = V_293 ,
} ;
int V_241 ;
F_2 ( L_33 , V_9 ,
V_13 -> V_26 -> V_190 . V_189 ,
V_13 -> V_190 . V_189 ,
( unsigned long long ) V_11 ) ;
F_3 ( V_11 , F_245 ( V_146 ) , V_13 , & args ) ;
V_30 . V_27 = args . V_27 ;
V_241 = F_64 ( F_72 ( V_146 ) -> V_73 , F_72 ( V_146 ) , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
if ( V_241 >= 0 ) {
memcpy ( F_245 ( V_146 ) , V_30 . V_12 . V_128 , V_449 ) ;
V_241 += args . V_27 ;
}
F_246 ( V_146 ) ;
F_2 ( L_34 , V_9 , V_241 ) ;
return V_241 ;
}
static int F_247 ( struct V_13 * V_13 , struct V_252 * V_293 ,
T_1 V_11 , struct V_371 * * V_19 , unsigned int V_18 , int V_446 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_13 -> V_24 ) ,
F_244 ( V_13 , V_293 , V_11 ,
V_19 , V_18 , V_446 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_248 ( struct V_145 * V_146 , struct V_13 * V_13 ,
struct V_172 * V_284 , T_9 V_450 )
{
struct V_435 * V_128 ;
int V_203 = V_284 -> V_417 ;
int V_241 = - V_231 ;
F_4 ( ! ( V_284 -> V_287 & V_451 ) ) ;
F_4 ( ! F_249 ( V_203 ) && ! F_250 ( V_203 ) && ! F_251 ( V_203 ) && ! F_252 ( V_203 ) ) ;
V_128 = F_236 ( V_146 , & V_13 -> V_190 , V_284 , V_452 ) ;
if ( V_128 == NULL )
goto V_110;
if ( F_249 ( V_203 ) )
V_128 -> V_303 . V_436 = V_453 ;
else if ( F_250 ( V_203 ) ) {
V_128 -> V_303 . V_436 = V_454 ;
V_128 -> V_303 . V_197 . V_455 . V_456 = F_253 ( V_450 ) ;
V_128 -> V_303 . V_197 . V_455 . V_457 = F_254 ( V_450 ) ;
}
else if ( F_251 ( V_203 ) ) {
V_128 -> V_303 . V_436 = V_458 ;
V_128 -> V_303 . V_197 . V_455 . V_456 = F_253 ( V_450 ) ;
V_128 -> V_303 . V_197 . V_455 . V_457 = F_254 ( V_450 ) ;
}
V_241 = F_237 ( V_146 , V_13 , V_128 ) ;
F_239 ( V_128 ) ;
V_110:
return V_241 ;
}
static int F_255 ( struct V_145 * V_146 , struct V_13 * V_13 ,
struct V_172 * V_284 , T_9 V_450 )
{
struct V_45 V_46 = { } ;
int V_1 ;
V_284 -> V_417 &= ~ F_222 () ;
do {
V_1 = F_16 ( F_72 ( V_146 ) ,
F_248 ( V_146 , V_13 , V_284 , V_450 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_256 ( struct V_42 * V_43 , struct V_324 * V_325 ,
struct V_459 * V_460 )
{
struct V_461 args = {
. V_181 = V_325 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_462 V_30 = {
. V_460 = V_460 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_463 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
F_69 ( V_460 -> V_301 ) ;
return F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
}
static int F_257 ( struct V_42 * V_43 , struct V_324 * V_325 , struct V_459 * V_460 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_256 ( V_43 , V_325 , V_460 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_258 ( struct V_42 * V_43 , struct V_324 * V_325 ,
struct V_351 * V_464 )
{
struct V_465 args = {
. V_181 = V_325 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_466 V_30 = {
. V_464 = V_464 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_467 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
return F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
}
static int F_196 ( struct V_42 * V_43 , struct V_324 * V_325 , struct V_351 * V_464 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_258 ( V_43 , V_325 , V_464 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_259 ( struct V_42 * V_43 , struct V_324 * V_325 , struct V_351 * V_464 )
{
F_69 ( V_464 -> V_301 ) ;
return F_196 ( V_43 , V_325 , V_464 ) ;
}
static int F_260 ( struct V_42 * V_43 , struct V_324 * V_325 ,
struct V_468 * V_469 )
{
struct V_470 args = {
. V_181 = V_325 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_471 V_30 = {
. V_469 = V_469 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_472 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
if ( ( args . V_191 [ 0 ] & V_473 [ 0 ] ) == 0 ) {
memset ( V_469 , 0 , sizeof( * V_469 ) ) ;
return 0 ;
}
F_69 ( V_469 -> V_301 ) ;
return F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
}
static int F_261 ( struct V_42 * V_43 , struct V_324 * V_325 ,
struct V_468 * V_469 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_260 ( V_43 , V_325 , V_469 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
void F_262 ( struct V_474 * V_128 )
{
F_246 ( V_128 -> V_145 ) ;
}
static int F_263 ( struct V_96 * V_97 , struct V_474 * V_128 )
{
struct V_42 * V_43 = F_72 ( V_128 -> V_145 ) ;
if ( F_175 ( V_97 , V_43 , V_128 -> args . V_475 -> V_48 ) == - V_120 ) {
F_264 ( V_97 , V_43 -> V_28 ) ;
return - V_120 ;
}
F_262 ( V_128 ) ;
if ( V_97 -> V_142 > 0 )
F_26 ( V_43 , V_128 -> V_80 ) ;
return 0 ;
}
static int F_265 ( struct V_96 * V_97 , struct V_474 * V_128 )
{
F_2 ( L_17 , V_9 ) ;
if ( ! F_41 ( V_97 , & V_128 -> V_30 . V_131 ) )
return - V_120 ;
return V_128 -> V_476 ? V_128 -> V_476 ( V_97 , V_128 ) :
F_263 ( V_97 , V_128 ) ;
}
static void F_266 ( struct V_474 * V_128 , struct V_132 * V_133 )
{
V_128 -> V_80 = V_125 ;
V_128 -> V_476 = F_263 ;
V_133 -> V_247 = & V_248 [ V_477 ] ;
}
void F_267 ( struct V_96 * V_97 , struct V_474 * V_128 )
{
F_2 ( L_35 , V_9 ) ;
F_268 ( V_128 -> V_478 ) ;
V_128 -> V_478 = NULL ;
V_128 -> args . V_479 = V_128 -> V_480 ;
V_128 -> V_481 = NULL ;
V_128 -> args . V_181 = F_78 ( V_128 -> V_145 ) ;
V_128 -> V_476 = F_263 ;
V_97 -> V_482 = V_128 -> V_483 ;
F_269 ( V_97 , F_270 ( V_128 -> V_145 ) ) ;
}
static int F_271 ( struct V_96 * V_97 , struct V_484 * V_128 )
{
struct V_145 * V_145 = V_128 -> V_145 ;
if ( F_175 ( V_97 , F_72 ( V_145 ) , V_128 -> args . V_475 -> V_48 ) == - V_120 ) {
F_264 ( V_97 , F_72 ( V_145 ) -> V_28 ) ;
return - V_120 ;
}
if ( V_97 -> V_142 >= 0 ) {
F_26 ( F_72 ( V_145 ) , V_128 -> V_80 ) ;
F_272 ( V_145 , V_128 -> V_30 . V_301 ) ;
}
return 0 ;
}
static int F_273 ( struct V_96 * V_97 , struct V_484 * V_128 )
{
if ( ! F_41 ( V_97 , & V_128 -> V_30 . V_131 ) )
return - V_120 ;
return V_128 -> V_485 ? V_128 -> V_485 ( V_97 , V_128 ) :
F_271 ( V_97 , V_128 ) ;
}
void F_274 ( struct V_96 * V_97 , struct V_484 * V_128 )
{
F_2 ( L_35 , V_9 ) ;
F_268 ( V_128 -> V_478 ) ;
V_128 -> V_478 = NULL ;
V_128 -> V_481 = NULL ;
V_128 -> V_485 = F_271 ;
V_128 -> args . V_181 = F_78 ( V_128 -> V_145 ) ;
V_128 -> args . V_191 = V_128 -> V_30 . V_43 -> V_321 ;
V_128 -> args . V_479 = V_128 -> V_480 ;
V_128 -> V_30 . V_301 = & V_128 -> V_301 ;
V_97 -> V_482 = V_128 -> V_483 ;
F_269 ( V_97 , F_270 ( V_128 -> V_145 ) ) ;
}
static void F_275 ( struct V_484 * V_128 , struct V_132 * V_133 )
{
struct V_42 * V_43 = F_72 ( V_128 -> V_145 ) ;
if ( V_128 -> V_478 ) {
V_128 -> args . V_191 = NULL ;
V_128 -> V_30 . V_301 = NULL ;
} else
V_128 -> args . V_191 = V_43 -> V_321 ;
if ( ! V_128 -> V_485 )
V_128 -> V_485 = F_271 ;
V_128 -> V_30 . V_43 = V_43 ;
V_128 -> V_80 = V_125 ;
V_133 -> V_247 = & V_248 [ V_486 ] ;
}
static int F_276 ( struct V_96 * V_97 , struct V_484 * V_128 )
{
struct V_145 * V_145 = V_128 -> V_145 ;
if ( F_175 ( V_97 , F_72 ( V_145 ) , NULL ) == - V_120 ) {
F_264 ( V_97 , F_72 ( V_145 ) -> V_28 ) ;
return - V_120 ;
}
F_147 ( V_145 , V_128 -> V_30 . V_301 ) ;
return 0 ;
}
static int F_277 ( struct V_96 * V_97 , struct V_484 * V_128 )
{
if ( ! F_41 ( V_97 , & V_128 -> V_30 . V_131 ) )
return - V_120 ;
return V_128 -> V_485 ( V_97 , V_128 ) ;
}
static void F_278 ( struct V_484 * V_128 , struct V_132 * V_133 )
{
struct V_42 * V_43 = F_72 ( V_128 -> V_145 ) ;
if ( V_128 -> V_478 ) {
V_128 -> args . V_191 = NULL ;
V_128 -> V_30 . V_301 = NULL ;
} else
V_128 -> args . V_191 = V_43 -> V_321 ;
if ( ! V_128 -> V_485 )
V_128 -> V_485 = F_276 ;
V_128 -> V_30 . V_43 = V_43 ;
V_133 -> V_247 = & V_248 [ V_487 ] ;
}
static void F_279 ( void * V_126 )
{
struct V_488 * V_128 = V_126 ;
struct V_28 * V_29 = V_128 -> V_73 ;
if ( F_280 ( & V_29 -> V_489 ) > 1 )
F_281 ( V_29 ) ;
F_282 ( V_29 ) ;
F_80 ( V_128 ) ;
}
static void F_283 ( struct V_96 * V_97 , void * V_126 )
{
struct V_488 * V_128 = V_126 ;
struct V_28 * V_29 = V_128 -> V_73 ;
unsigned long V_80 = V_128 -> V_80 ;
if ( V_97 -> V_142 < 0 ) {
if ( F_31 ( V_490 , & V_29 -> V_491 ) == 0 )
return;
if ( V_97 -> V_142 != V_492 ) {
F_18 ( V_29 ) ;
return;
}
F_284 ( V_29 ) ;
}
F_22 ( V_29 , V_80 ) ;
}
static int F_285 ( struct V_28 * V_29 , struct V_252 * V_293 , unsigned V_493 )
{
struct V_132 V_133 = {
. V_247 = & V_248 [ V_494 ] ,
. V_250 = V_29 ,
. V_252 = V_293 ,
} ;
struct V_488 * V_128 ;
if ( V_493 == 0 )
return 0 ;
if ( ! F_286 ( & V_29 -> V_489 ) )
return - V_10 ;
V_128 = F_199 ( sizeof( * V_128 ) , V_238 ) ;
if ( V_128 == NULL )
return - V_231 ;
V_128 -> V_73 = V_29 ;
V_128 -> V_80 = V_125 ;
return F_287 ( V_29 -> V_495 , & V_133 , V_496 ,
& V_497 , V_128 ) ;
}
static int F_288 ( struct V_28 * V_29 , struct V_252 * V_293 )
{
struct V_132 V_133 = {
. V_247 = & V_248 [ V_494 ] ,
. V_250 = V_29 ,
. V_252 = V_293 ,
} ;
unsigned long V_498 = V_125 ;
int V_241 ;
V_241 = F_63 ( V_29 -> V_495 , & V_133 , 0 ) ;
if ( V_241 < 0 )
return V_241 ;
F_22 ( V_29 , V_498 ) ;
return 0 ;
}
static inline int F_289 ( struct V_42 * V_43 )
{
return ( V_43 -> V_76 & V_329 )
&& ( V_43 -> V_350 & V_499 )
&& ( V_43 -> V_350 & V_500 ) ;
}
static void F_290 ( const void * V_501 , T_10 V_502 ,
struct V_371 * * V_19 , unsigned int * V_27 )
{
const void * V_17 = V_501 ;
* V_27 = F_291 ( V_501 ) ;
V_17 -= * V_27 ;
while ( V_17 < V_501 + V_502 ) {
* ( V_19 ++ ) = F_292 ( V_17 ) ;
V_17 += V_503 ;
}
}
static int F_293 ( const void * V_501 , T_10 V_502 ,
struct V_371 * * V_19 , unsigned int * V_27 )
{
struct V_371 * V_504 , * * V_505 ;
int V_506 = 0 ;
T_10 V_361 ;
V_505 = V_19 ;
do {
V_361 = F_294 ( T_10 , V_503 , V_502 ) ;
V_504 = F_198 ( V_296 ) ;
if ( V_504 == NULL )
goto V_507;
memcpy ( F_295 ( V_504 ) , V_501 , V_361 ) ;
V_501 += V_361 ;
V_502 -= V_361 ;
* V_19 ++ = V_504 ;
V_506 ++ ;
} while ( V_502 != 0 );
return V_506 ;
V_507:
for(; V_506 > 0 ; V_506 -- )
F_203 ( V_505 [ V_506 - 1 ] ) ;
return - V_231 ;
}
static void F_296 ( struct V_145 * V_145 , struct V_508 * V_509 )
{
struct V_149 * V_150 = F_66 ( V_145 ) ;
F_23 ( & V_145 -> V_151 ) ;
F_80 ( V_150 -> V_510 ) ;
V_150 -> V_510 = V_509 ;
F_25 ( & V_145 -> V_151 ) ;
}
static void F_297 ( struct V_145 * V_145 )
{
F_296 ( V_145 , NULL ) ;
}
static inline T_11 F_298 ( struct V_145 * V_145 , char * V_501 , T_10 V_502 )
{
struct V_149 * V_150 = F_66 ( V_145 ) ;
struct V_508 * V_509 ;
int V_49 = - V_237 ;
F_23 ( & V_145 -> V_151 ) ;
V_509 = V_150 -> V_510 ;
if ( V_509 == NULL )
goto V_110;
if ( V_501 == NULL )
goto V_511;
if ( V_509 -> V_512 == 0 )
goto V_110;
V_49 = - V_513 ;
if ( V_509 -> V_361 > V_502 )
goto V_110;
memcpy ( V_501 , V_509 -> V_128 , V_509 -> V_361 ) ;
V_511:
V_49 = V_509 -> V_361 ;
V_110:
F_25 ( & V_145 -> V_151 ) ;
return V_49 ;
}
static void F_299 ( struct V_145 * V_145 , const char * V_501 , T_10 V_514 )
{
struct V_508 * V_509 ;
if ( V_501 && V_514 <= V_515 ) {
V_509 = F_199 ( sizeof( * V_509 ) + V_514 , V_296 ) ;
if ( V_509 == NULL )
goto V_110;
V_509 -> V_512 = 1 ;
memcpy ( V_509 -> V_128 , V_501 , V_514 ) ;
} else {
V_509 = F_199 ( sizeof( * V_509 ) , V_296 ) ;
if ( V_509 == NULL )
goto V_110;
V_509 -> V_512 = 0 ;
}
V_509 -> V_361 = V_514 ;
V_110:
F_296 ( V_145 , V_509 ) ;
}
static T_11 F_300 ( struct V_145 * V_145 , void * V_501 , T_10 V_502 )
{
struct V_371 * V_19 [ V_516 ] ;
struct V_517 args = {
. V_181 = F_78 ( V_145 ) ,
. V_518 = V_19 ,
. V_514 = V_502 ,
} ;
struct V_519 V_30 = {
. V_514 = V_502 ,
} ;
void * V_520 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_521 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
struct V_371 * V_522 = NULL ;
int V_49 ;
if ( V_502 < V_515 ) {
V_522 = F_198 ( V_296 ) ;
V_520 = F_295 ( V_522 ) ;
if ( V_522 == NULL )
return - V_231 ;
args . V_518 [ 0 ] = V_522 ;
args . V_523 = 0 ;
args . V_514 = V_515 ;
} else {
V_520 = V_501 ;
F_290 ( V_501 , V_502 , args . V_518 , & args . V_523 ) ;
}
V_49 = F_64 ( F_72 ( V_145 ) -> V_73 , F_72 ( V_145 ) , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
if ( V_49 )
goto V_246;
if ( V_30 . V_514 > args . V_514 )
F_299 ( V_145 , NULL , V_30 . V_514 ) ;
else
F_299 ( V_145 , V_520 , V_30 . V_514 ) ;
if ( V_501 ) {
V_49 = - V_513 ;
if ( V_30 . V_514 > V_502 )
goto V_246;
if ( V_522 )
memcpy ( V_501 , V_520 , V_30 . V_514 ) ;
}
V_49 = V_30 . V_514 ;
V_246:
if ( V_522 )
F_203 ( V_522 ) ;
return V_49 ;
}
static T_11 F_301 ( struct V_145 * V_145 , void * V_501 , T_10 V_502 )
{
struct V_45 V_46 = { } ;
T_11 V_49 ;
do {
V_49 = F_300 ( V_145 , V_501 , V_502 ) ;
if ( V_49 >= 0 )
break;
V_49 = F_16 ( F_72 ( V_145 ) , V_49 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_49 ;
}
static T_11 F_302 ( struct V_145 * V_145 , void * V_501 , T_10 V_502 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
int V_49 ;
if ( ! F_289 ( V_43 ) )
return - V_524 ;
V_49 = F_303 ( V_43 , V_145 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( F_66 ( V_145 ) -> V_152 & V_525 )
F_304 ( V_145 ) ;
V_49 = F_298 ( V_145 , V_501 , V_502 ) ;
if ( V_49 != - V_237 )
return V_49 ;
return F_301 ( V_145 , V_501 , V_502 ) ;
}
static int F_305 ( struct V_145 * V_145 , const void * V_501 , T_10 V_502 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_371 * V_19 [ V_516 ] ;
struct V_526 V_303 = {
. V_181 = F_78 ( V_145 ) ,
. V_518 = V_19 ,
. V_514 = V_502 ,
} ;
struct V_527 V_30 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_528 ] ,
. V_250 = & V_303 ,
. V_251 = & V_30 ,
} ;
int V_49 , V_360 ;
if ( ! F_289 ( V_43 ) )
return - V_524 ;
V_360 = F_293 ( V_501 , V_502 , V_303 . V_518 , & V_303 . V_523 ) ;
if ( V_360 < 0 )
return V_360 ;
F_108 ( V_145 ) ;
V_49 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & V_303 . V_130 , & V_30 . V_131 , 1 ) ;
for (; V_360 > 0 ; V_360 -- )
F_306 ( V_19 [ V_360 - 1 ] ) ;
F_23 ( & V_145 -> V_151 ) ;
F_66 ( V_145 ) -> V_152 |= V_153 ;
F_25 ( & V_145 -> V_151 ) ;
F_307 ( V_145 ) ;
F_304 ( V_145 ) ;
return V_49 ;
}
static int F_308 ( struct V_145 * V_145 , const void * V_501 , T_10 V_502 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_145 ) ,
F_305 ( V_145 , V_501 , V_502 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_175 ( struct V_96 * V_97 , const struct V_42 * V_43 , struct V_47 * V_48 )
{
struct V_28 * V_29 = V_43 -> V_28 ;
if ( V_97 -> V_142 >= 0 )
return 0 ;
switch( V_97 -> V_142 ) {
case - V_51 :
case - V_52 :
case - V_53 :
if ( V_48 == NULL )
break;
F_17 ( V_43 , V_48 ) ;
goto V_54;
case - V_55 :
if ( V_48 != NULL )
F_17 ( V_43 , V_48 ) ;
case - V_56 :
case - V_57 :
F_18 ( V_29 ) ;
goto V_54;
#if F_19 ( V_58 )
case - V_59 :
case - V_60 :
case - V_61 :
case - V_63 :
case - V_62 :
case - V_64 :
case - V_65 :
F_2 ( L_36 , V_9 ,
V_97 -> V_142 ) ;
F_20 ( V_29 -> V_66 ) ;
V_97 -> V_142 = 0 ;
return - V_120 ;
#endif
case - V_71 :
F_309 ( V_43 , V_529 ) ;
case - V_70 :
case - V_72 :
F_40 ( V_97 , V_39 ) ;
V_97 -> V_142 = 0 ;
return - V_120 ;
case - V_74 :
case - V_75 :
V_97 -> V_142 = 0 ;
return - V_120 ;
}
V_97 -> V_142 = F_1 ( V_97 -> V_142 ) ;
return 0 ;
V_54:
F_48 ( & V_29 -> V_530 , V_97 , NULL ) ;
if ( F_31 ( V_32 , & V_29 -> V_31 ) == 0 )
F_310 ( & V_29 -> V_530 , V_97 ) ;
V_97 -> V_142 = 0 ;
return - V_120 ;
}
int F_311 ( struct V_28 * V_29 , T_6 V_531 ,
unsigned short V_532 , struct V_252 * V_293 ,
struct V_533 * V_30 )
{
T_12 V_534 ;
struct V_535 V_536 = {
. V_534 = & V_534 ,
. V_537 = V_531 ,
. V_538 = V_29 -> V_539 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_540 ] ,
. V_250 = & V_536 ,
. V_251 = V_30 ,
. V_252 = V_293 ,
} ;
T_2 * V_17 ;
int V_280 = 0 ;
int V_241 ;
V_17 = ( T_2 * ) V_534 . V_128 ;
* V_17 ++ = F_6 ( ( T_6 ) V_29 -> V_541 . V_542 ) ;
* V_17 = F_6 ( ( T_6 ) V_29 -> V_541 . V_543 ) ;
for(; ; ) {
V_536 . V_544 = F_312 ( V_536 . V_545 ,
sizeof( V_536 . V_545 ) , L_37 ,
V_29 -> V_546 ,
F_313 ( V_29 -> V_495 ,
V_547 ) ,
F_313 ( V_29 -> V_495 ,
V_548 ) ,
V_29 -> V_495 -> V_549 -> V_550 -> V_551 ,
V_29 -> V_552 ) ;
V_536 . V_553 = F_312 ( V_536 . V_554 ,
sizeof( V_536 . V_554 ) ,
F_313 ( V_29 -> V_495 ,
V_555 ) ) ;
V_536 . V_556 = F_312 ( V_536 . V_557 ,
sizeof( V_536 . V_557 ) , L_38 ,
V_29 -> V_546 , V_532 >> 8 , V_532 & 255 ) ;
V_241 = F_63 ( V_29 -> V_495 , & V_133 , V_558 ) ;
if ( V_241 != - V_559 )
break;
if ( V_280 != 0 ) {
++ V_29 -> V_552 ;
break;
}
++ V_280 ;
F_314 ( V_29 -> V_560 / V_68 + 1 ) ;
}
return V_241 ;
}
int F_315 ( struct V_28 * V_29 ,
struct V_533 * V_303 ,
struct V_252 * V_293 )
{
struct V_351 V_464 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_561 ] ,
. V_250 = V_303 ,
. V_251 = & V_464 ,
. V_252 = V_293 ,
} ;
unsigned long V_498 ;
int V_241 ;
V_498 = V_125 ;
V_241 = F_63 ( V_29 -> V_495 , & V_133 , V_558 ) ;
if ( V_241 == 0 ) {
F_23 ( & V_29 -> V_81 ) ;
V_29 -> V_560 = V_464 . V_562 * V_68 ;
V_29 -> V_82 = V_498 ;
F_25 ( & V_29 -> V_81 ) ;
}
return V_241 ;
}
static void F_316 ( struct V_96 * V_97 , void * V_126 )
{
struct V_563 * V_128 = V_126 ;
if ( ! F_41 ( V_97 , & V_128 -> V_30 . V_131 ) )
return;
switch ( V_97 -> V_142 ) {
case - V_56 :
case - V_55 :
case 0 :
F_26 ( V_128 -> V_30 . V_43 , V_128 -> V_80 ) ;
break;
default:
if ( F_175 ( V_97 , V_128 -> V_30 . V_43 , NULL ) ==
- V_120 ) {
F_264 ( V_97 , V_128 -> V_30 . V_43 -> V_28 ) ;
return;
}
}
V_128 -> V_244 = V_97 -> V_142 ;
}
static void F_317 ( void * V_126 )
{
F_80 ( V_126 ) ;
}
static void F_318 ( struct V_96 * V_97 , void * V_128 )
{
struct V_563 * V_564 ;
V_564 = (struct V_563 * ) V_128 ;
if ( F_50 ( V_564 -> V_30 . V_43 ,
& V_564 -> args . V_130 ,
& V_564 -> V_30 . V_131 , 1 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
static int F_319 ( struct V_145 * V_145 , struct V_252 * V_293 , const T_7 * V_199 , int V_565 )
{
struct V_563 * V_128 ;
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_566 ] ,
. V_252 = V_293 ,
} ;
struct V_135 V_253 = {
. V_137 = V_43 -> V_73 ,
. V_132 = & V_133 ,
. V_138 = & V_567 ,
. V_171 = V_257 ,
} ;
int V_241 = 0 ;
V_128 = F_73 ( sizeof( * V_128 ) , V_238 ) ;
if ( V_128 == NULL )
return - V_231 ;
V_128 -> args . V_325 = & V_128 -> V_181 ;
V_128 -> args . V_199 = & V_128 -> V_199 ;
V_128 -> args . V_191 = V_43 -> V_192 ;
F_142 ( & V_128 -> V_181 , F_78 ( V_145 ) ) ;
memcpy ( & V_128 -> V_199 , V_199 , sizeof( V_128 -> V_199 ) ) ;
V_128 -> V_30 . V_301 = & V_128 -> V_301 ;
V_128 -> V_30 . V_43 = V_43 ;
F_69 ( V_128 -> V_30 . V_301 ) ;
V_128 -> V_80 = V_125 ;
V_128 -> V_244 = 0 ;
V_253 . V_140 = V_128 ;
V_133 . V_250 = & V_128 -> args ;
V_133 . V_251 = & V_128 -> V_30 ;
V_97 = F_57 ( & V_253 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
if ( ! V_565 )
goto V_110;
V_241 = F_90 ( V_97 ) ;
if ( V_241 != 0 )
goto V_110;
V_241 = V_128 -> V_244 ;
if ( V_241 != 0 )
goto V_110;
F_147 ( V_145 , & V_128 -> V_301 ) ;
V_110:
F_60 ( V_97 ) ;
return V_241 ;
}
int F_320 ( struct V_145 * V_145 , struct V_252 * V_293 , const T_7 * V_199 , int V_565 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_319 ( V_145 , V_293 , V_199 , V_565 ) ;
switch ( V_1 ) {
case - V_56 :
case - V_55 :
case 0 :
return 0 ;
}
V_1 = F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static unsigned long
F_321 ( unsigned long V_37 )
{
F_14 ( V_37 ) ;
V_37 <<= 1 ;
if ( V_37 > V_568 )
return V_568 ;
return V_37 ;
}
static int F_322 ( struct V_47 * V_48 , int V_569 , struct V_570 * V_571 )
{
struct V_145 * V_145 = V_48 -> V_145 ;
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_28 * V_29 = V_43 -> V_28 ;
struct V_572 V_303 = {
. V_181 = F_78 ( V_145 ) ,
. V_573 = V_571 ,
} ;
struct V_574 V_30 = {
. V_575 = V_571 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_576 ] ,
. V_250 = & V_303 ,
. V_251 = & V_30 ,
. V_252 = V_48 -> V_179 -> V_227 ,
} ;
struct V_577 * V_578 ;
int V_241 ;
V_303 . V_579 . V_185 = V_29 -> V_186 ;
V_241 = F_323 ( V_48 , V_571 ) ;
if ( V_241 != 0 )
goto V_110;
V_578 = V_571 -> V_580 . V_581 . V_179 ;
V_303 . V_579 . V_187 = V_578 -> V_582 . V_187 ;
V_303 . V_579 . V_583 = V_43 -> V_583 ;
V_241 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & V_303 . V_130 , & V_30 . V_131 , 1 ) ;
switch ( V_241 ) {
case 0 :
V_571 -> V_584 = V_585 ;
break;
case - V_586 :
V_241 = 0 ;
}
V_571 -> V_587 -> V_588 ( V_571 ) ;
V_110:
return V_241 ;
}
static int F_324 ( struct V_47 * V_48 , int V_569 , struct V_570 * V_571 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_48 -> V_145 ) ,
F_322 ( V_48 , V_569 , V_571 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_325 ( struct V_589 * V_589 , struct V_570 * V_573 )
{
int V_30 = 0 ;
switch ( V_573 -> V_590 & ( V_591 | V_592 ) ) {
case V_591 :
V_30 = F_326 ( V_589 , V_573 ) ;
break;
case V_592 :
V_30 = F_327 ( V_589 , V_573 ) ;
break;
default:
F_328 () ;
}
return V_30 ;
}
static struct V_593 * F_329 ( struct V_570 * V_573 ,
struct V_235 * V_236 ,
struct V_577 * V_578 ,
struct V_594 * V_164 )
{
struct V_593 * V_17 ;
struct V_145 * V_145 = V_578 -> V_595 -> V_145 ;
V_17 = F_73 ( sizeof( * V_17 ) , V_238 ) ;
if ( V_17 == NULL )
return NULL ;
V_17 -> V_303 . V_181 = F_78 ( V_145 ) ;
V_17 -> V_303 . V_573 = & V_17 -> V_573 ;
V_17 -> V_303 . V_164 = V_164 ;
V_17 -> V_30 . V_164 = V_164 ;
V_17 -> V_303 . V_199 = & V_578 -> V_596 ;
V_17 -> V_578 = V_578 ;
F_77 ( & V_578 -> V_597 ) ;
V_17 -> V_236 = F_120 ( V_236 ) ;
memcpy ( & V_17 -> V_573 , V_573 , sizeof( V_17 -> V_573 ) ) ;
V_17 -> V_43 = F_72 ( V_145 ) ;
return V_17 ;
}
static void F_330 ( void * V_128 )
{
struct V_593 * V_126 = V_128 ;
F_84 ( V_126 -> V_303 . V_164 ) ;
F_331 ( V_126 -> V_578 ) ;
F_131 ( V_126 -> V_236 ) ;
F_80 ( V_126 ) ;
}
static void F_332 ( struct V_96 * V_97 , void * V_128 )
{
struct V_593 * V_126 = V_128 ;
if ( ! F_41 ( V_97 , & V_126 -> V_30 . V_131 ) )
return;
switch ( V_97 -> V_142 ) {
case 0 :
memcpy ( V_126 -> V_578 -> V_596 . V_128 ,
V_126 -> V_30 . V_199 . V_128 ,
sizeof( V_126 -> V_578 -> V_596 . V_128 ) ) ;
F_26 ( V_126 -> V_43 , V_126 -> V_80 ) ;
break;
case - V_52 :
case - V_75 :
case - V_56 :
case - V_55 :
break;
default:
if ( F_175 ( V_97 , V_126 -> V_43 , NULL ) == - V_120 )
F_264 ( V_97 ,
V_126 -> V_43 -> V_28 ) ;
}
}
static void F_333 ( struct V_96 * V_97 , void * V_128 )
{
struct V_593 * V_126 = V_128 ;
if ( F_141 ( V_126 -> V_303 . V_164 , V_97 ) != 0 )
return;
if ( ( V_126 -> V_578 -> V_598 & V_599 ) == 0 ) {
V_97 -> V_262 = NULL ;
return;
}
V_126 -> V_80 = V_125 ;
if ( F_50 ( V_126 -> V_43 ,
& V_126 -> V_303 . V_130 ,
& V_126 -> V_30 . V_131 , 1 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
static struct V_96 * F_334 ( struct V_570 * V_573 ,
struct V_235 * V_236 ,
struct V_577 * V_578 ,
struct V_594 * V_164 )
{
struct V_593 * V_128 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_600 ] ,
. V_252 = V_236 -> V_293 ,
} ;
struct V_135 V_253 = {
. V_137 = F_270 ( V_578 -> V_595 -> V_145 ) ,
. V_132 = & V_133 ,
. V_138 = & V_601 ,
. V_255 = V_256 ,
. V_171 = V_257 ,
} ;
V_573 -> V_584 = V_585 ;
V_128 = F_329 ( V_573 , V_236 , V_578 , V_164 ) ;
if ( V_128 == NULL ) {
F_84 ( V_164 ) ;
return F_111 ( - V_231 ) ;
}
V_133 . V_250 = & V_128 -> V_303 ;
V_133 . V_251 = & V_128 -> V_30 ;
V_253 . V_140 = V_128 ;
return F_57 ( & V_253 ) ;
}
static int F_335 ( struct V_47 * V_48 , int V_569 , struct V_570 * V_571 )
{
struct V_149 * V_150 = F_66 ( V_48 -> V_145 ) ;
struct V_594 * V_164 ;
struct V_577 * V_578 ;
struct V_96 * V_97 ;
int V_241 = 0 ;
unsigned char V_590 = V_571 -> V_590 ;
V_241 = F_323 ( V_48 , V_571 ) ;
V_571 -> V_590 |= V_602 ;
F_336 ( & V_150 -> V_603 ) ;
if ( F_325 ( V_571 -> V_604 , V_571 ) == - V_237 ) {
F_337 ( & V_150 -> V_603 ) ;
goto V_110;
}
F_337 ( & V_150 -> V_603 ) ;
if ( V_241 != 0 )
goto V_110;
if ( F_31 ( V_215 , & V_48 -> V_171 ) )
goto V_110;
V_578 = V_571 -> V_580 . V_581 . V_179 ;
V_164 = F_74 ( & V_578 -> V_605 , V_296 ) ;
V_241 = - V_231 ;
if ( V_164 == NULL )
goto V_110;
V_97 = F_334 ( V_571 , F_208 ( V_571 -> V_604 ) , V_578 , V_164 ) ;
V_241 = F_59 ( V_97 ) ;
if ( F_58 ( V_97 ) )
goto V_110;
V_241 = F_90 ( V_97 ) ;
F_60 ( V_97 ) ;
V_110:
V_571 -> V_590 = V_590 ;
return V_241 ;
}
static struct V_606 * F_338 ( struct V_570 * V_573 ,
struct V_235 * V_236 , struct V_577 * V_578 ,
T_5 V_174 )
{
struct V_606 * V_17 ;
struct V_145 * V_145 = V_578 -> V_595 -> V_145 ;
struct V_42 * V_43 = F_72 ( V_145 ) ;
V_17 = F_73 ( sizeof( * V_17 ) , V_174 ) ;
if ( V_17 == NULL )
return NULL ;
V_17 -> V_303 . V_181 = F_78 ( V_145 ) ;
V_17 -> V_303 . V_573 = & V_17 -> V_573 ;
V_17 -> V_303 . V_607 = F_74 ( & V_578 -> V_595 -> V_179 -> V_176 , V_174 ) ;
if ( V_17 -> V_303 . V_607 == NULL )
goto V_246;
V_17 -> V_303 . V_608 = F_74 ( & V_578 -> V_605 , V_174 ) ;
if ( V_17 -> V_303 . V_608 == NULL )
goto V_609;
V_17 -> V_303 . V_610 = & V_578 -> V_596 ;
V_17 -> V_303 . V_579 . V_185 = V_43 -> V_28 -> V_186 ;
V_17 -> V_303 . V_579 . V_187 = V_578 -> V_582 . V_187 ;
V_17 -> V_303 . V_579 . V_583 = V_43 -> V_583 ;
V_17 -> V_30 . V_608 = V_17 -> V_303 . V_608 ;
V_17 -> V_578 = V_578 ;
V_17 -> V_43 = V_43 ;
F_77 ( & V_578 -> V_597 ) ;
V_17 -> V_236 = F_120 ( V_236 ) ;
memcpy ( & V_17 -> V_573 , V_573 , sizeof( V_17 -> V_573 ) ) ;
return V_17 ;
V_609:
F_84 ( V_17 -> V_303 . V_607 ) ;
V_246:
F_80 ( V_17 ) ;
return NULL ;
}
static void F_339 ( struct V_96 * V_97 , void * V_126 )
{
struct V_606 * V_128 = V_126 ;
struct V_47 * V_48 = V_128 -> V_578 -> V_595 ;
F_2 ( L_39 , V_9 ) ;
if ( F_141 ( V_128 -> V_303 . V_608 , V_97 ) != 0 )
return;
if ( ! ( V_128 -> V_303 . V_608 -> V_611 -> V_171 & V_612 ) ) {
if ( F_141 ( V_128 -> V_303 . V_607 , V_97 ) != 0 )
return;
V_128 -> V_303 . V_216 = & V_48 -> V_199 ;
V_128 -> V_303 . V_613 = 1 ;
V_128 -> V_30 . V_607 = V_128 -> V_303 . V_607 ;
} else
V_128 -> V_303 . V_613 = 0 ;
V_128 -> V_80 = V_125 ;
if ( F_50 ( V_128 -> V_43 ,
& V_128 -> V_303 . V_130 ,
& V_128 -> V_30 . V_131 , 1 , V_97 ) )
return;
F_53 ( V_97 ) ;
F_2 ( L_40 , V_9 , V_128 -> V_244 ) ;
}
static void F_340 ( struct V_96 * V_97 , void * V_126 )
{
F_33 ( V_97 , V_102 ) ;
F_339 ( V_97 , V_126 ) ;
}
static void F_341 ( struct V_96 * V_97 , void * V_126 )
{
struct V_606 * V_128 = V_126 ;
F_2 ( L_39 , V_9 ) ;
if ( ! F_41 ( V_97 , & V_128 -> V_30 . V_131 ) )
return;
V_128 -> V_244 = V_97 -> V_142 ;
if ( V_128 -> V_303 . V_613 != 0 ) {
if ( V_128 -> V_244 == 0 )
F_135 ( & V_128 -> V_578 -> V_605 , 0 ) ;
else
goto V_110;
}
if ( V_128 -> V_244 == 0 ) {
memcpy ( V_128 -> V_578 -> V_596 . V_128 , V_128 -> V_30 . V_199 . V_128 ,
sizeof( V_128 -> V_578 -> V_596 . V_128 ) ) ;
V_128 -> V_578 -> V_598 |= V_599 ;
F_26 ( F_72 ( V_128 -> V_236 -> V_13 -> V_24 ) , V_128 -> V_80 ) ;
}
V_110:
F_2 ( L_41 , V_9 , V_128 -> V_244 ) ;
}
static void F_342 ( void * V_126 )
{
struct V_606 * V_128 = V_126 ;
F_2 ( L_39 , V_9 ) ;
F_84 ( V_128 -> V_303 . V_607 ) ;
if ( V_128 -> V_245 != 0 ) {
struct V_96 * V_97 ;
V_97 = F_334 ( & V_128 -> V_573 , V_128 -> V_236 , V_128 -> V_578 ,
V_128 -> V_303 . V_608 ) ;
if ( ! F_58 ( V_97 ) )
F_343 ( V_97 ) ;
F_2 ( L_42 , V_9 ) ;
} else
F_84 ( V_128 -> V_303 . V_608 ) ;
F_331 ( V_128 -> V_578 ) ;
F_131 ( V_128 -> V_236 ) ;
F_80 ( V_128 ) ;
F_2 ( L_43 , V_9 ) ;
}
static void F_344 ( struct V_42 * V_43 , struct V_577 * V_578 , int V_613 , int error )
{
switch ( error ) {
case - V_51 :
case - V_52 :
V_578 -> V_605 . V_171 &= ~ V_612 ;
if ( V_613 != 0 ||
( V_578 -> V_598 & V_599 ) != 0 )
F_17 ( V_43 , V_578 -> V_595 ) ;
break;
case - V_56 :
V_578 -> V_605 . V_171 &= ~ V_612 ;
case - V_55 :
F_18 ( V_43 -> V_28 ) ;
} ;
}
static int F_345 ( struct V_47 * V_48 , int V_569 , struct V_570 * V_573 , int V_614 )
{
struct V_606 * V_128 ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_615 ] ,
. V_252 = V_48 -> V_179 -> V_227 ,
} ;
struct V_135 V_253 = {
. V_137 = F_270 ( V_48 -> V_145 ) ,
. V_132 = & V_133 ,
. V_138 = & V_616 ,
. V_255 = V_256 ,
. V_171 = V_257 ,
} ;
int V_49 ;
F_2 ( L_39 , V_9 ) ;
V_128 = F_338 ( V_573 , F_208 ( V_573 -> V_604 ) ,
V_573 -> V_580 . V_581 . V_179 ,
V_614 == V_617 ? V_296 : V_238 ) ;
if ( V_128 == NULL )
return - V_231 ;
if ( F_346 ( V_569 ) )
V_128 -> V_303 . V_618 = 1 ;
if ( V_614 > V_617 ) {
if ( V_614 == V_619 )
V_128 -> V_303 . V_620 = V_619 ;
V_253 . V_138 = & V_621 ;
}
V_133 . V_250 = & V_128 -> V_303 ;
V_133 . V_251 = & V_128 -> V_30 ;
V_253 . V_140 = V_128 ;
V_97 = F_57 ( & V_253 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
V_49 = F_90 ( V_97 ) ;
if ( V_49 == 0 ) {
V_49 = V_128 -> V_244 ;
if ( V_49 )
F_344 ( V_128 -> V_43 , V_128 -> V_578 ,
V_128 -> V_303 . V_613 , V_49 ) ;
} else
V_128 -> V_245 = 1 ;
F_60 ( V_97 ) ;
F_2 ( L_41 , V_9 , V_49 ) ;
return V_49 ;
}
static int F_347 ( struct V_47 * V_48 , struct V_570 * V_571 )
{
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
if ( F_31 ( V_215 , & V_48 -> V_171 ) != 0 )
return 0 ;
V_1 = F_345 ( V_48 , V_622 , V_571 , V_619 ) ;
if ( V_1 != - V_71 )
break;
F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_348 ( struct V_47 * V_48 , struct V_570 * V_571 )
{
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
V_1 = F_323 ( V_48 , V_571 ) ;
if ( V_1 != 0 )
return V_1 ;
do {
if ( F_31 ( V_215 , & V_48 -> V_171 ) != 0 )
return 0 ;
V_1 = F_345 ( V_48 , V_622 , V_571 , V_623 ) ;
switch ( V_1 ) {
default:
goto V_110;
case - V_70 :
case - V_71 :
F_16 ( V_43 , V_1 , & V_46 ) ;
V_1 = 0 ;
}
} while ( V_46 . V_50 );
V_110:
return V_1 ;
}
static int F_349 ( struct V_47 * V_48 , struct V_570 * V_571 )
{
int V_241 ;
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
V_241 = F_159 ( V_43 , V_48 ) ;
if ( V_241 == V_109 )
return 0 ;
F_160 ( V_43 , V_48 ) ;
return F_348 ( V_48 , V_571 ) ;
}
static int F_350 ( struct V_47 * V_48 , int V_569 , struct V_570 * V_571 )
{
struct V_149 * V_150 = F_66 ( V_48 -> V_145 ) ;
unsigned char V_590 = V_571 -> V_590 ;
int V_241 = - V_624 ;
if ( ( V_590 & V_591 ) &&
! F_31 ( V_298 , & V_48 -> V_171 ) )
goto V_110;
V_241 = F_323 ( V_48 , V_571 ) ;
if ( V_241 != 0 )
goto V_110;
V_571 -> V_590 |= V_625 ;
V_241 = F_325 ( V_571 -> V_604 , V_571 ) ;
if ( V_241 < 0 )
goto V_110;
F_336 ( & V_150 -> V_603 ) ;
if ( F_31 ( V_215 , & V_48 -> V_171 ) ) {
V_571 -> V_590 = V_590 & ~ V_626 ;
V_241 = F_325 ( V_571 -> V_604 , V_571 ) ;
goto V_627;
}
V_241 = F_345 ( V_48 , V_569 , V_571 , V_617 ) ;
if ( V_241 != 0 )
goto V_627;
V_571 -> V_590 = V_590 | V_626 ;
if ( F_325 ( V_571 -> V_604 , V_571 ) < 0 )
F_21 ( V_78 L_44 , V_9 ) ;
V_627:
F_337 ( & V_150 -> V_603 ) ;
V_110:
V_571 -> V_590 = V_590 ;
return V_241 ;
}
static int F_351 ( struct V_47 * V_48 , int V_569 , struct V_570 * V_571 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_350 ( V_48 , V_569 , V_571 ) ;
if ( V_1 == - V_586 )
V_1 = - V_120 ;
V_1 = F_16 ( F_72 ( V_48 -> V_145 ) ,
V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_352 ( struct V_589 * V_628 , int V_569 , struct V_570 * V_571 )
{
struct V_235 * V_236 ;
struct V_47 * V_48 ;
unsigned long V_37 = V_629 ;
int V_241 ;
V_236 = F_208 ( V_628 ) ;
V_48 = V_236 -> V_48 ;
if ( V_571 -> V_630 < 0 || V_571 -> V_631 < 0 )
return - V_8 ;
if ( F_353 ( V_569 ) ) {
if ( V_48 != NULL )
return F_324 ( V_48 , V_632 , V_571 ) ;
return 0 ;
}
if ( ! ( F_354 ( V_569 ) || F_346 ( V_569 ) ) )
return - V_8 ;
if ( V_571 -> V_584 == V_585 ) {
if ( V_48 != NULL )
return F_335 ( V_48 , V_569 , V_571 ) ;
return 0 ;
}
if ( V_48 == NULL )
return - V_624 ;
do {
V_241 = F_351 ( V_48 , V_569 , V_571 ) ;
if ( ( V_241 != - V_120 ) || F_354 ( V_569 ) )
break;
V_37 = F_321 ( V_37 ) ;
V_241 = - V_41 ;
if ( F_355 () )
break;
} while( V_241 < 0 );
return V_241 ;
}
int F_356 ( struct V_47 * V_48 , struct V_570 * V_573 )
{
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
V_1 = F_323 ( V_48 , V_573 ) ;
if ( V_1 != 0 )
goto V_110;
do {
V_1 = F_345 ( V_48 , V_622 , V_573 , V_617 ) ;
switch ( V_1 ) {
default:
F_21 ( V_633 L_45 ,
V_9 , V_1 ) ;
case 0 :
case - V_240 :
goto V_110;
case - V_55 :
F_17 ( V_43 , V_48 ) ;
case - V_57 :
case - V_56 :
F_18 ( V_43 -> V_28 ) ;
goto V_110;
case - V_59 :
case - V_60 :
case - V_61 :
case - V_62 :
case - V_63 :
F_20 ( V_43 -> V_28 -> V_66 ) ;
goto V_110;
case - V_41 :
case - V_51 :
case - V_52 :
case - V_53 :
F_17 ( V_43 , V_48 ) ;
V_1 = 0 ;
goto V_110;
case - V_72 :
V_1 = 0 ;
goto V_110;
case - V_231 :
case - V_586 :
V_1 = 0 ;
goto V_110;
case - V_71 :
break;
}
V_1 = F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
V_110:
return V_1 ;
}
static void F_357 ( void * V_126 )
{
F_80 ( V_126 ) ;
}
void F_358 ( const struct V_577 * V_578 )
{
struct V_42 * V_43 = V_578 -> V_595 -> V_179 -> V_259 ;
struct V_634 * args ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_635 ] ,
} ;
if ( V_43 -> V_28 -> V_143 -> V_366 != 0 )
return;
args = F_199 ( sizeof( * args ) , V_238 ) ;
if ( ! args )
return;
args -> V_579 . V_185 = V_43 -> V_28 -> V_186 ;
args -> V_579 . V_187 = V_578 -> V_582 . V_187 ;
args -> V_579 . V_583 = V_43 -> V_583 ;
V_133 . V_250 = args ;
F_287 ( V_43 -> V_73 , & V_133 , 0 , & V_636 , args ) ;
}
static int F_359 ( struct V_13 * V_13 , const char * V_637 ,
const void * V_501 , T_10 V_502 ,
int V_171 , int type )
{
if ( strcmp ( V_637 , L_46 ) != 0 )
return - V_8 ;
return F_308 ( V_13 -> V_24 , V_501 , V_502 ) ;
}
static int F_360 ( struct V_13 * V_13 , const char * V_637 ,
void * V_501 , T_10 V_502 , int type )
{
if ( strcmp ( V_637 , L_46 ) != 0 )
return - V_8 ;
return F_302 ( V_13 -> V_24 , V_501 , V_502 ) ;
}
static T_10 F_361 ( struct V_13 * V_13 , char * V_638 ,
T_10 V_639 , const char * V_189 ,
T_10 V_640 , int type )
{
T_10 V_361 = sizeof( V_641 ) ;
if ( ! F_289 ( F_72 ( V_13 -> V_24 ) ) )
return 0 ;
if ( V_638 && V_361 <= V_639 )
memcpy ( V_638 , V_641 , V_361 ) ;
return V_361 ;
}
static void F_202 ( struct V_300 * V_301 )
{
if ( ! ( ( ( V_301 -> V_229 & V_642 ) ||
( V_301 -> V_229 & V_643 ) ) &&
( V_301 -> V_229 & V_390 ) &&
( V_301 -> V_229 & V_644 ) ) )
return;
V_301 -> V_229 |= V_387 | V_388 |
V_389 ;
V_301 -> V_203 = V_267 | V_392 | V_393 ;
V_301 -> V_394 = 2 ;
}
int F_200 ( struct V_145 * V_146 , const struct V_370 * V_189 ,
struct V_372 * V_645 , struct V_371 * V_371 )
{
struct V_42 * V_43 = F_72 ( V_146 ) ;
T_6 V_191 [ 2 ] = {
[ 0 ] = V_646 | V_647 ,
} ;
struct V_648 args = {
. V_382 = F_78 ( V_146 ) ,
. V_189 = V_189 ,
. V_371 = V_371 ,
. V_191 = V_191 ,
} ;
struct V_649 V_30 = {
. V_645 = V_645 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_650 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
int V_241 ;
F_2 ( L_47 , V_9 ) ;
if ( F_72 ( V_146 ) -> V_192 [ 1 ] & V_651 )
V_191 [ 1 ] |= V_651 ;
else
V_191 [ 0 ] |= V_23 ;
F_69 ( & V_645 -> V_301 ) ;
V_645 -> V_43 = V_43 ;
V_645 -> V_652 = 0 ;
V_241 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
F_2 ( L_48 , V_9 , V_241 ) ;
return V_241 ;
}
static int F_362 ( struct V_145 * V_146 , const struct V_370 * V_189 , struct V_653 * V_654 )
{
int V_241 ;
struct V_655 args = {
. V_382 = F_78 ( V_146 ) ,
. V_189 = V_189 ,
} ;
struct V_656 V_30 = {
. V_654 = V_654 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_657 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
F_2 ( L_49 , V_189 -> V_189 ) ;
V_241 = F_64 ( F_72 ( V_146 ) -> V_73 , F_72 ( V_146 ) , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
F_2 ( L_50 , V_241 ) ;
return V_241 ;
}
int F_363 ( struct V_145 * V_146 , const struct V_370 * V_189 , struct V_653 * V_654 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_146 ) ,
F_362 ( V_146 , V_189 , V_654 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_364 ( T_6 V_171 )
{
if ( V_171 & ~ V_658 )
goto V_659;
if ( ( V_171 & V_660 ) &&
( V_171 & V_661 ) )
goto V_659;
if ( ! ( V_171 & ( V_662 ) ) )
goto V_659;
return V_109 ;
V_659:
return - V_663 ;
}
static bool
F_365 ( struct V_664 * V_665 , struct V_664 * V_666 )
{
if ( V_665 -> V_667 == V_666 -> V_667 &&
memcmp ( V_665 -> V_664 , V_666 -> V_664 , V_665 -> V_667 ) == 0 )
return true ;
return false ;
}
int F_366 ( struct V_28 * V_29 , struct V_252 * V_293 )
{
T_12 V_12 ;
struct V_668 args = {
. V_73 = V_29 ,
. V_171 = V_669 ,
} ;
struct V_670 V_30 = {
. V_73 = V_29 ,
} ;
int V_241 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_671 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
. V_252 = V_293 ,
} ;
T_2 * V_17 ;
F_2 ( L_17 , V_9 ) ;
F_4 ( V_29 == NULL ) ;
V_17 = ( T_6 * ) V_12 . V_128 ;
* V_17 ++ = F_6 ( ( T_6 ) V_29 -> V_541 . V_542 ) ;
* V_17 = F_6 ( ( T_6 ) V_29 -> V_541 . V_543 ) ;
args . V_12 = & V_12 ;
args . V_672 = F_312 ( args . V_187 , sizeof( args . V_187 ) ,
L_51 ,
V_29 -> V_546 ,
F_367 () -> V_673 ,
F_367 () -> V_674 ,
V_29 -> V_495 -> V_549 -> V_675 ) ;
V_30 . V_664 = F_73 ( sizeof( struct V_664 ) , V_296 ) ;
if ( F_368 ( ! V_30 . V_664 ) )
return - V_231 ;
V_241 = F_63 ( V_29 -> V_495 , & V_133 , V_558 ) ;
if ( ! V_241 )
V_241 = F_364 ( V_29 -> V_676 ) ;
if ( ! V_241 ) {
if ( V_29 -> V_664 &&
! F_365 ( V_29 -> V_664 ,
V_30 . V_664 ) ) {
F_2 ( L_52 ,
V_9 ) ;
F_98 ( V_677 , & V_29 -> V_31 ) ;
F_80 ( V_29 -> V_664 ) ;
V_29 -> V_664 = NULL ;
}
if ( ! V_29 -> V_664 )
V_29 -> V_664 = V_30 . V_664 ;
else
F_80 ( V_30 . V_664 ) ;
}
F_2 ( L_53 , V_9 , V_241 ) ;
return V_241 ;
}
static void F_369 ( struct V_96 * V_97 ,
void * V_126 )
{
int V_49 ;
struct V_678 * V_128 =
(struct V_678 * ) V_126 ;
F_2 ( L_17 , V_9 ) ;
F_33 ( V_97 , V_102 ) ;
V_49 = F_46 ( V_128 -> V_29 -> V_66 ,
& V_128 -> args -> V_679 ,
& V_128 -> V_30 -> V_680 , 0 , V_97 ) ;
F_4 ( V_49 == - V_120 ) ;
F_53 ( V_97 ) ;
F_2 ( L_54 , V_9 ) ;
}
static void F_370 ( struct V_96 * V_97 , void * V_126 )
{
struct V_678 * V_128 =
(struct V_678 * ) V_126 ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_37 ( V_97 , & V_128 -> V_30 -> V_680 ) )
return;
switch ( V_97 -> V_142 ) {
case - V_71 :
case - V_70 :
F_2 ( L_55 , V_9 , V_97 -> V_142 ) ;
F_40 ( V_97 , V_38 ) ;
V_97 -> V_142 = 0 ;
case - V_74 :
F_264 ( V_97 , V_128 -> V_29 ) ;
return;
}
F_2 ( L_54 , V_9 ) ;
}
int F_371 ( struct V_28 * V_29 , struct V_351 * V_464 )
{
struct V_96 * V_97 ;
struct V_681 args ;
struct V_682 V_30 = {
. V_683 = V_464 ,
} ;
struct V_678 V_128 = {
. args = & args ,
. V_30 = & V_30 ,
. V_29 = V_29 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_684 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
struct V_135 V_136 = {
. V_137 = V_29 -> V_495 ,
. V_132 = & V_133 ,
. V_138 = & V_685 ,
. V_140 = & V_128 ,
. V_171 = V_558 ,
} ;
int V_241 ;
F_2 ( L_17 , V_9 ) ;
V_97 = F_57 ( & V_136 ) ;
if ( F_58 ( V_97 ) )
V_241 = F_59 ( V_97 ) ;
else {
V_241 = V_97 -> V_142 ;
F_60 ( V_97 ) ;
}
F_2 ( L_56 , V_9 , V_241 ) ;
return V_241 ;
}
static int F_372 ( struct V_83 * V_84 , T_6 V_686 ,
int V_687 )
{
struct V_85 * V_688 = NULL ;
int V_360 ;
int V_49 = 0 ;
F_2 ( L_57 , V_9 ,
V_686 , V_84 -> V_93 ) ;
if ( V_686 != V_84 -> V_93 ) {
V_49 = - V_231 ;
V_688 = F_199 ( V_686 * sizeof( struct V_85 ) ,
V_238 ) ;
if ( ! V_688 )
goto V_110;
V_49 = 0 ;
F_80 ( V_84 -> V_88 ) ;
}
F_23 ( & V_84 -> V_107 ) ;
if ( V_688 ) {
V_84 -> V_88 = V_688 ;
V_84 -> V_93 = V_686 ;
}
for ( V_360 = 0 ; V_360 < V_84 -> V_93 ; ++ V_360 )
V_84 -> V_88 [ V_360 ] . V_111 = V_687 ;
F_25 ( & V_84 -> V_107 ) ;
F_2 ( L_58 , V_9 ,
V_84 , V_84 -> V_88 , V_84 -> V_93 ) ;
V_110:
F_2 ( L_59 , V_9 , V_49 ) ;
return V_49 ;
}
static int F_373 ( struct V_94 * V_116 )
{
int V_241 ;
V_241 = F_372 ( & V_116 -> V_100 ,
V_116 -> V_689 . V_686 , 1 ) ;
if ( V_241 )
return V_241 ;
V_241 = F_372 ( & V_116 -> V_103 ,
V_116 -> V_690 . V_686 , 0 ) ;
return V_241 ;
}
static void F_374 ( struct V_94 * V_116 )
{
if ( V_116 -> V_100 . V_88 != NULL ) {
F_80 ( V_116 -> V_100 . V_88 ) ;
V_116 -> V_100 . V_88 = NULL ;
}
if ( V_116 -> V_103 . V_88 != NULL ) {
F_80 ( V_116 -> V_103 . V_88 ) ;
V_116 -> V_103 . V_88 = NULL ;
}
return;
}
static int F_375 ( struct V_83 * V_84 ,
int V_93 , int V_687 )
{
struct V_85 * V_119 ;
int V_49 = - V_231 ;
F_4 ( V_93 > V_90 ) ;
F_2 ( L_60 , V_9 , V_93 ) ;
V_119 = F_376 ( V_93 , sizeof( struct V_85 ) , V_238 ) ;
if ( ! V_119 )
goto V_110;
V_49 = 0 ;
F_23 ( & V_84 -> V_107 ) ;
V_84 -> V_93 = V_93 ;
V_84 -> V_88 = V_119 ;
V_84 -> V_92 = - 1 ;
F_25 ( & V_84 -> V_107 ) ;
F_2 ( L_58 , V_9 ,
V_84 , V_84 -> V_88 , V_84 -> V_93 ) ;
V_110:
F_2 ( L_59 , V_9 , V_49 ) ;
return V_49 ;
}
static int F_377 ( struct V_94 * V_116 )
{
struct V_83 * V_84 ;
int V_241 = 0 ;
V_84 = & V_116 -> V_100 ;
if ( V_84 -> V_88 == NULL ) {
V_241 = F_375 ( V_84 ,
V_116 -> V_689 . V_686 , 1 ) ;
if ( V_241 )
return V_241 ;
}
V_84 = & V_116 -> V_103 ;
if ( V_84 -> V_88 == NULL ) {
V_241 = F_375 ( V_84 ,
V_116 -> V_690 . V_686 , 0 ) ;
if ( V_241 )
F_374 ( V_116 ) ;
}
return V_241 ;
}
struct V_94 * F_378 ( struct V_28 * V_29 )
{
struct V_94 * V_116 ;
struct V_83 * V_84 ;
V_116 = F_73 ( sizeof( struct V_94 ) , V_238 ) ;
if ( ! V_116 )
return NULL ;
V_84 = & V_116 -> V_100 ;
V_84 -> V_92 = - 1 ;
F_379 ( & V_84 -> V_107 ) ;
F_380 ( & V_84 -> V_101 , L_61 ) ;
F_381 ( & V_84 -> F_34 ) ;
V_84 = & V_116 -> V_103 ;
V_84 -> V_92 = - 1 ;
F_379 ( & V_84 -> V_107 ) ;
F_382 ( & V_84 -> V_101 , L_62 ) ;
F_381 ( & V_84 -> F_34 ) ;
V_116 -> V_99 = 1 << V_691 ;
V_116 -> V_29 = V_29 ;
return V_116 ;
}
void F_383 ( struct V_94 * V_116 )
{
F_384 ( V_116 ) ;
F_2 ( L_63 ,
V_9 , V_116 -> V_29 -> V_495 -> V_692 ) ;
F_385 ( V_116 -> V_29 -> V_495 -> V_692 ,
V_693 ) ;
F_374 ( V_116 ) ;
F_80 ( V_116 ) ;
}
static void F_386 ( struct V_694 * args )
{
struct V_94 * V_116 = args -> V_73 -> V_66 ;
unsigned int V_695 = V_116 -> V_689 . V_696 ,
V_697 = V_116 -> V_689 . V_698 ;
if ( V_695 == 0 )
V_695 = V_699 ;
if ( V_697 == 0 )
V_697 = V_699 ;
args -> V_689 . V_696 = V_695 ;
args -> V_689 . V_698 = V_697 ;
args -> V_689 . V_700 = V_701 ;
args -> V_689 . V_686 = V_116 -> V_29 -> V_495 -> V_692 -> V_686 ;
F_2 ( L_64
L_65 ,
V_9 ,
args -> V_689 . V_696 , args -> V_689 . V_698 ,
args -> V_689 . V_700 , args -> V_689 . V_686 ) ;
args -> V_690 . V_696 = V_515 ;
args -> V_690 . V_698 = V_515 ;
args -> V_690 . V_702 = 0 ;
args -> V_690 . V_700 = V_703 ;
args -> V_690 . V_686 = 1 ;
F_2 ( L_66
L_67 ,
V_9 ,
args -> V_690 . V_696 , args -> V_690 . V_698 ,
args -> V_690 . V_702 , args -> V_690 . V_700 ,
args -> V_690 . V_686 ) ;
}
static int F_387 ( struct V_694 * args , struct V_94 * V_116 )
{
struct V_704 * V_705 = & args -> V_689 ;
struct V_704 * V_706 = & V_116 -> V_689 ;
if ( V_706 -> V_698 > V_705 -> V_698 )
return - V_8 ;
if ( V_706 -> V_700 < V_705 -> V_700 )
return - V_8 ;
if ( V_706 -> V_686 == 0 )
return - V_8 ;
return 0 ;
}
static int F_388 ( struct V_694 * args , struct V_94 * V_116 )
{
struct V_704 * V_705 = & args -> V_690 ;
struct V_704 * V_706 = & V_116 -> V_690 ;
if ( V_706 -> V_696 > V_705 -> V_696 )
return - V_8 ;
if ( V_706 -> V_698 < V_705 -> V_698 )
return - V_8 ;
if ( V_706 -> V_702 > V_705 -> V_702 )
return - V_8 ;
if ( V_706 -> V_700 == 0 )
return - V_8 ;
if ( V_706 -> V_686 == 0 )
return - V_8 ;
return 0 ;
}
static int F_389 ( struct V_694 * args ,
struct V_94 * V_116 )
{
int V_49 ;
V_49 = F_387 ( args , V_116 ) ;
if ( V_49 )
return V_49 ;
return F_388 ( args , V_116 ) ;
}
static int F_390 ( struct V_28 * V_29 )
{
struct V_94 * V_116 = V_29 -> V_66 ;
struct V_694 args = {
. V_73 = V_29 ,
. V_707 = V_708 ,
} ;
struct V_709 V_30 = {
. V_73 = V_29 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_710 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
int V_241 ;
F_386 ( & args ) ;
args . V_171 = ( V_711 | V_712 ) ;
V_241 = F_63 ( V_116 -> V_29 -> V_495 , & V_133 , V_558 ) ;
if ( ! V_241 )
V_241 = F_389 ( & args , V_116 ) ;
if ( ! V_241 ) {
V_29 -> V_713 ++ ;
}
return V_241 ;
}
int F_391 ( struct V_28 * V_29 )
{
int V_241 ;
unsigned * V_714 ;
struct V_94 * V_116 = V_29 -> V_66 ;
F_2 ( L_68 , V_9 , V_29 , V_116 ) ;
V_241 = F_390 ( V_29 ) ;
if ( V_241 )
goto V_110;
V_241 = F_377 ( V_116 ) ;
F_2 ( L_69 , V_241 ) ;
if ( V_241 )
goto V_110;
V_241 = F_373 ( V_116 ) ;
F_2 ( L_70 , V_241 ) ;
if ( V_241 )
goto V_110;
V_714 = ( unsigned * ) & V_116 -> V_715 . V_128 [ 0 ] ;
F_2 ( L_71 , V_9 ,
V_29 -> V_713 , V_714 [ 0 ] , V_714 [ 1 ] , V_714 [ 2 ] , V_714 [ 3 ] ) ;
V_110:
F_2 ( L_54 , V_9 ) ;
return V_241 ;
}
int F_384 ( struct V_94 * V_116 )
{
int V_241 = 0 ;
struct V_132 V_133 ;
F_2 ( L_72 ) ;
if ( V_116 -> V_29 -> V_716 != V_717 )
return V_241 ;
V_133 . V_247 = & V_248 [ V_718 ] ;
V_133 . V_250 = V_116 ;
V_133 . V_251 = NULL ;
V_133 . V_252 = NULL ;
V_241 = F_63 ( V_116 -> V_29 -> V_495 , & V_133 , V_558 ) ;
if ( V_241 )
F_21 ( V_78
L_73
L_74 , V_241 ) ;
F_2 ( L_75 ) ;
return V_241 ;
}
int F_392 ( struct V_42 * V_43 )
{
struct V_28 * V_29 = V_43 -> V_28 ;
struct V_94 * V_116 ;
unsigned int V_719 , V_720 ;
int V_49 ;
if ( ! F_393 ( V_29 ) )
return 0 ;
V_116 = V_29 -> V_66 ;
if ( ! F_394 ( V_691 , & V_116 -> V_99 ) )
return 0 ;
V_719 = V_43 -> V_719 ;
if ( V_719 == 0 )
V_719 = V_699 ;
V_720 = V_43 -> V_720 ;
if ( V_720 == 0 )
V_720 = V_699 ;
V_116 -> V_689 . V_696 = V_720 + V_721 ;
V_116 -> V_689 . V_698 = V_719 + V_722 ;
V_49 = F_153 ( V_43 ) ;
if ( ! V_49 )
V_49 = F_395 ( V_29 ) ;
return V_49 ;
}
int F_396 ( struct V_28 * V_29 )
{
struct V_94 * V_116 = V_29 -> V_66 ;
int V_49 ;
if ( ! F_394 ( V_691 , & V_116 -> V_99 ) )
return 0 ;
V_49 = F_151 ( V_29 ) ;
if ( ! V_49 )
if ( ! F_397 ( V_29 ) )
V_49 = - V_723 ;
if ( ! V_49 )
V_49 = F_395 ( V_29 ) ;
return V_49 ;
}
static void F_398 ( void * V_128 )
{
struct V_724 * V_126 = V_128 ;
struct V_28 * V_29 = V_126 -> V_29 ;
if ( F_280 ( & V_29 -> V_489 ) > 1 )
F_281 ( V_29 ) ;
F_282 ( V_29 ) ;
F_80 ( V_126 ) ;
}
static int F_399 ( struct V_96 * V_97 , struct V_28 * V_29 )
{
switch( V_97 -> V_142 ) {
case - V_71 :
F_40 ( V_97 , V_39 ) ;
return - V_120 ;
default:
F_18 ( V_29 ) ;
}
return 0 ;
}
static void F_400 ( struct V_96 * V_97 , void * V_128 )
{
struct V_724 * V_126 = V_128 ;
struct V_28 * V_29 = V_126 -> V_29 ;
if ( ! F_37 ( V_97 , V_97 -> V_260 . V_251 ) )
return;
if ( V_97 -> V_142 < 0 ) {
F_2 ( L_76 , V_9 , V_97 -> V_142 ) ;
if ( F_280 ( & V_29 -> V_489 ) == 1 )
goto V_110;
if ( F_399 ( V_97 , V_29 ) == - V_120 ) {
F_176 ( V_97 ) ;
return;
}
}
F_2 ( L_77 , V_9 , V_97 -> V_260 . V_252 ) ;
V_110:
F_2 ( L_54 , V_9 ) ;
}
static void F_401 ( struct V_96 * V_97 , void * V_128 )
{
struct V_724 * V_126 = V_128 ;
struct V_28 * V_29 = V_126 -> V_29 ;
struct V_117 * args ;
struct V_104 * V_30 ;
args = V_97 -> V_260 . V_250 ;
V_30 = V_97 -> V_260 . V_251 ;
if ( F_46 ( V_29 -> V_66 , args , V_30 , 0 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
static struct V_96 * F_402 ( struct V_28 * V_29 , struct V_252 * V_293 )
{
struct V_724 * V_126 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_725 ] ,
. V_252 = V_293 ,
} ;
struct V_135 V_253 = {
. V_137 = V_29 -> V_495 ,
. V_132 = & V_133 ,
. V_138 = & V_726 ,
. V_171 = V_257 | V_496 ,
} ;
if ( ! F_286 ( & V_29 -> V_489 ) )
return F_111 ( - V_10 ) ;
V_126 = F_73 ( sizeof( * V_126 ) , V_238 ) ;
if ( V_126 == NULL ) {
F_282 ( V_29 ) ;
return F_111 ( - V_231 ) ;
}
V_133 . V_250 = & V_126 -> args ;
V_133 . V_251 = & V_126 -> V_30 ;
V_126 -> V_29 = V_29 ;
V_253 . V_140 = V_126 ;
return F_57 ( & V_253 ) ;
}
static int F_403 ( struct V_28 * V_29 , struct V_252 * V_293 , unsigned V_493 )
{
struct V_96 * V_97 ;
int V_49 = 0 ;
if ( ( V_493 & V_727 ) == 0 )
return 0 ;
V_97 = F_402 ( V_29 , V_293 ) ;
if ( F_58 ( V_97 ) )
V_49 = F_59 ( V_97 ) ;
else
F_343 ( V_97 ) ;
F_2 ( L_23 , V_9 , V_49 ) ;
return V_49 ;
}
static int F_404 ( struct V_28 * V_29 , struct V_252 * V_293 )
{
struct V_96 * V_97 ;
int V_49 ;
V_97 = F_402 ( V_29 , V_293 ) ;
if ( F_58 ( V_97 ) ) {
V_49 = F_59 ( V_97 ) ;
goto V_110;
}
V_49 = F_91 ( V_97 ) ;
if ( ! V_49 ) {
struct V_104 * V_30 = V_97 -> V_260 . V_251 ;
if ( V_97 -> V_142 == 0 )
F_405 ( V_29 , V_30 -> V_113 ) ;
V_49 = V_97 -> V_142 ;
}
F_60 ( V_97 ) ;
V_110:
F_2 ( L_23 , V_9 , V_49 ) ;
return V_49 ;
}
static void F_406 ( struct V_96 * V_97 , void * V_128 )
{
struct V_728 * V_126 = V_128 ;
F_33 ( V_97 , V_102 ) ;
if ( F_46 ( V_126 -> V_29 -> V_66 ,
& V_126 -> V_303 . V_130 ,
& V_126 -> V_30 . V_131 , 0 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
static int F_407 ( struct V_96 * V_97 , struct V_28 * V_29 )
{
switch( V_97 -> V_142 ) {
case 0 :
case - V_729 :
case - V_730 :
break;
case - V_71 :
F_40 ( V_97 , V_39 ) ;
case - V_74 :
return - V_120 ;
default:
F_18 ( V_29 ) ;
}
return 0 ;
}
static void F_408 ( struct V_96 * V_97 , void * V_128 )
{
struct V_728 * V_126 = V_128 ;
struct V_28 * V_29 = V_126 -> V_29 ;
struct V_104 * V_30 = & V_126 -> V_30 . V_131 ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_37 ( V_97 , V_30 ) )
return;
if ( F_407 ( V_97 , V_29 ) == - V_120 ) {
F_176 ( V_97 ) ;
return;
}
F_2 ( L_54 , V_9 ) ;
}
static void F_409 ( void * V_128 )
{
struct V_728 * V_126 = V_128 ;
F_80 ( V_126 ) ;
}
static int F_410 ( struct V_28 * V_29 )
{
struct V_728 * V_126 ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_731 ] ,
} ;
struct V_135 V_253 = {
. V_137 = V_29 -> V_495 ,
. V_132 = & V_133 ,
. V_138 = & V_732 ,
. V_171 = V_257 ,
} ;
int V_241 = - V_231 ;
F_2 ( L_17 , V_9 ) ;
V_126 = F_73 ( sizeof( * V_126 ) , V_238 ) ;
if ( V_126 == NULL )
goto V_110;
V_126 -> V_29 = V_29 ;
V_126 -> V_303 . V_733 = 0 ;
V_133 . V_250 = & V_126 -> V_303 ;
V_133 . V_251 = & V_126 -> V_30 ;
V_253 . V_140 = V_126 ;
V_97 = F_57 ( & V_253 ) ;
if ( F_58 ( V_97 ) ) {
V_241 = F_59 ( V_97 ) ;
goto V_110;
}
V_241 = F_90 ( V_97 ) ;
if ( V_241 == 0 )
V_241 = V_97 -> V_142 ;
F_60 ( V_97 ) ;
return 0 ;
V_110:
F_2 ( L_23 , V_9 , V_241 ) ;
return V_241 ;
}
static void
F_411 ( struct V_96 * V_97 , void * V_126 )
{
struct V_734 * V_735 = V_126 ;
struct V_42 * V_43 = F_72 ( V_735 -> args . V_145 ) ;
F_2 ( L_17 , V_9 ) ;
if ( F_50 ( V_43 , & V_735 -> args . V_130 ,
& V_735 -> V_30 . V_131 , 0 , V_97 ) )
return;
if ( F_412 ( & V_735 -> args . V_199 ,
F_66 ( V_735 -> args . V_145 ) -> V_736 ,
V_735 -> args . V_236 -> V_48 ) ) {
F_413 ( V_97 , V_737 ) ;
return;
}
F_53 ( V_97 ) ;
}
static void F_414 ( struct V_96 * V_97 , void * V_126 )
{
struct V_734 * V_735 = V_126 ;
struct V_42 * V_43 = F_72 ( V_735 -> args . V_145 ) ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_41 ( V_97 , & V_735 -> V_30 . V_131 ) )
return;
switch ( V_97 -> V_142 ) {
case 0 :
break;
case - V_738 :
case - V_739 :
V_97 -> V_142 = - V_71 ;
default:
if ( F_175 ( V_97 , V_43 , NULL ) == - V_120 ) {
F_176 ( V_97 ) ;
return;
}
}
F_2 ( L_54 , V_9 ) ;
}
static void F_415 ( void * V_126 )
{
struct V_734 * V_735 = V_126 ;
F_2 ( L_17 , V_9 ) ;
F_131 ( V_735 -> args . V_236 ) ;
F_80 ( V_126 ) ;
F_2 ( L_54 , V_9 ) ;
}
int F_416 ( struct V_734 * V_735 )
{
struct V_42 * V_43 = F_72 ( V_735 -> args . V_145 ) ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_740 ] ,
. V_250 = & V_735 -> args ,
. V_251 = & V_735 -> V_30 ,
} ;
struct V_135 V_253 = {
. V_137 = V_43 -> V_73 ,
. V_132 = & V_133 ,
. V_138 = & V_741 ,
. V_140 = V_735 ,
. V_171 = V_257 ,
} ;
int V_241 = 0 ;
F_2 ( L_17 , V_9 ) ;
V_735 -> V_30 . V_742 = & V_735 -> args . V_736 ;
V_735 -> V_30 . V_131 . V_106 = NULL ;
V_97 = F_57 ( & V_253 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
V_241 = F_90 ( V_97 ) ;
if ( V_241 == 0 )
V_241 = V_97 -> V_142 ;
if ( V_241 == 0 )
V_241 = F_417 ( V_735 ) ;
F_60 ( V_97 ) ;
F_2 ( L_23 , V_9 , V_241 ) ;
return V_241 ;
}
static void
F_418 ( struct V_96 * V_97 , void * V_126 )
{
struct V_743 * V_744 = V_126 ;
F_2 ( L_17 , V_9 ) ;
if ( F_46 ( V_744 -> V_29 -> V_66 , & V_744 -> args . V_130 ,
& V_744 -> V_30 . V_131 , 0 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
static void F_419 ( struct V_96 * V_97 , void * V_126 )
{
struct V_743 * V_744 = V_126 ;
struct V_42 * V_43 ;
struct V_745 * V_746 = V_744 -> args . V_736 ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_41 ( V_97 , & V_744 -> V_30 . V_131 ) )
return;
V_43 = F_72 ( V_744 -> args . V_145 ) ;
if ( F_175 ( V_97 , V_43 , NULL ) == - V_120 ) {
F_264 ( V_97 , V_744 -> V_29 ) ;
return;
}
F_23 ( & V_746 -> V_747 -> V_151 ) ;
if ( V_97 -> V_142 == 0 ) {
if ( V_744 -> V_30 . V_748 ) {
F_420 ( V_746 , & V_744 -> V_30 . V_199 , true ) ;
} else
F_4 ( ! F_421 ( & V_746 -> V_749 ) ) ;
}
V_746 -> V_750 -- ;
F_25 ( & V_746 -> V_747 -> V_151 ) ;
F_2 ( L_54 , V_9 ) ;
}
static void F_422 ( void * V_126 )
{
struct V_743 * V_744 = V_126 ;
F_2 ( L_17 , V_9 ) ;
F_423 ( V_744 -> args . V_736 ) ;
F_80 ( V_126 ) ;
F_2 ( L_54 , V_9 ) ;
}
int F_424 ( struct V_743 * V_744 )
{
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_751 ] ,
. V_250 = & V_744 -> args ,
. V_251 = & V_744 -> V_30 ,
} ;
struct V_135 V_253 = {
. V_137 = V_744 -> V_29 -> V_495 ,
. V_132 = & V_133 ,
. V_138 = & V_752 ,
. V_140 = V_744 ,
} ;
int V_241 ;
F_2 ( L_17 , V_9 ) ;
V_97 = F_57 ( & V_253 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
V_241 = V_97 -> V_142 ;
F_2 ( L_23 , V_9 , V_241 ) ;
F_60 ( V_97 ) ;
return V_241 ;
}
static int F_425 ( struct V_42 * V_43 ,
const struct V_324 * V_181 ,
struct V_753 * V_754 )
{
struct V_755 args = {
. V_181 = V_181 ,
. V_756 = V_43 -> V_757 -> V_187 ,
} ;
struct V_758 V_30 = {
. V_754 = V_754 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_759 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
int V_241 ;
F_2 ( L_17 , V_9 ) ;
V_241 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 ,
& V_30 . V_131 , 0 ) ;
F_2 ( L_23 , V_9 , V_241 ) ;
return V_241 ;
}
int F_426 ( struct V_42 * V_43 ,
const struct V_324 * V_181 ,
struct V_753 * V_754 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_425 ( V_43 , V_181 , V_754 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
F_2 ( L_78 , V_9 ,
V_1 , V_754 -> V_760 ) ;
return V_1 ;
}
static int
F_427 ( struct V_42 * V_43 , struct V_761 * V_762 )
{
struct V_763 args = {
. V_762 = V_762 ,
} ;
struct V_764 V_30 = {
. V_762 = V_762 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_765 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
int V_241 ;
F_2 ( L_17 , V_9 ) ;
V_241 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
F_2 ( L_23 , V_9 , V_241 ) ;
return V_241 ;
}
int F_428 ( struct V_42 * V_43 , struct V_761 * V_762 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_427 ( V_43 , V_762 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static void F_429 ( struct V_96 * V_97 , void * V_126 )
{
struct V_766 * V_128 = V_126 ;
struct V_42 * V_43 = F_72 ( V_128 -> args . V_145 ) ;
if ( F_50 ( V_43 , & V_128 -> args . V_130 ,
& V_128 -> V_30 . V_131 , 1 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
static void
F_430 ( struct V_96 * V_97 , void * V_126 )
{
struct V_766 * V_128 = V_126 ;
struct V_42 * V_43 = F_72 ( V_128 -> args . V_145 ) ;
if ( ! F_41 ( V_97 , & V_128 -> V_30 . V_131 ) )
return;
switch ( V_97 -> V_142 ) {
case V_767 :
case V_768 :
case V_769 :
case V_70 :
V_97 -> V_142 = 0 ;
}
if ( F_175 ( V_97 , V_43 , NULL ) == - V_120 ) {
F_264 ( V_97 , V_43 -> V_28 ) ;
return;
}
if ( V_97 -> V_142 == 0 )
F_272 ( V_128 -> args . V_145 ,
V_128 -> V_30 . V_301 ) ;
}
static void F_431 ( void * V_126 )
{
struct V_766 * V_128 = V_126 ;
struct V_770 * V_478 , * V_771 ;
F_432 ( V_128 ) ;
F_433 (lseg, tmp, &data->lseg_list, pls_lc_list) {
F_434 ( & V_478 -> V_772 ) ;
if ( F_394 ( V_773 ,
& V_478 -> V_774 ) )
F_268 ( V_478 ) ;
}
F_435 ( V_128 -> V_293 ) ;
F_80 ( V_128 ) ;
}
int
F_436 ( struct V_766 * V_128 , bool V_775 )
{
struct V_132 V_133 = {
. V_247 = & V_248 [ V_776 ] ,
. V_250 = & V_128 -> args ,
. V_251 = & V_128 -> V_30 ,
. V_252 = V_128 -> V_293 ,
} ;
struct V_135 V_253 = {
. V_97 = & V_128 -> V_97 ,
. V_137 = F_270 ( V_128 -> args . V_145 ) ,
. V_132 = & V_133 ,
. V_138 = & V_777 ,
. V_140 = V_128 ,
. V_171 = V_257 ,
} ;
struct V_96 * V_97 ;
int V_241 = 0 ;
F_2 ( L_79
L_80 ,
V_128 -> V_97 . V_778 , V_775 ,
V_128 -> args . V_779 ,
V_128 -> args . V_145 -> V_780 ) ;
V_97 = F_57 ( & V_253 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
if ( V_775 == false )
goto V_110;
V_241 = F_90 ( V_97 ) ;
if ( V_241 != 0 )
goto V_110;
V_241 = V_97 -> V_142 ;
V_110:
F_2 ( L_81 , V_9 , V_241 ) ;
F_60 ( V_97 ) ;
return V_241 ;
}
static int
F_437 ( struct V_42 * V_43 , struct V_324 * V_325 ,
struct V_351 * V_352 , struct V_653 * V_654 )
{
struct V_781 args = {
. V_782 = V_783 ,
} ;
struct V_656 V_30 = {
. V_654 = V_654 ,
} ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_784 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
return F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
}
static int
F_438 ( struct V_42 * V_43 , struct V_324 * V_325 ,
struct V_351 * V_352 , struct V_653 * V_654 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_437 ( V_43 , V_325 , V_352 , V_654 ) ;
switch ( V_1 ) {
case 0 :
case - V_4 :
case - V_785 :
break;
default:
V_1 = F_16 ( V_43 , V_1 , & V_46 ) ;
}
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_439 ( struct V_42 * V_43 , struct V_324 * V_325 ,
struct V_351 * V_352 )
{
int V_1 ;
struct V_371 * V_371 ;
T_8 V_357 ;
struct V_653 * V_654 ;
V_371 = F_198 ( V_296 ) ;
if ( ! V_371 ) {
V_1 = - V_231 ;
goto V_110;
}
V_654 = F_295 ( V_371 ) ;
V_1 = F_438 ( V_43 , V_325 , V_352 , V_654 ) ;
if ( V_1 == - V_4 || V_1 == - V_785 ) {
V_1 = F_192 ( V_43 , V_325 , V_352 ) ;
goto V_786;
}
if ( V_1 )
goto V_786;
V_357 = F_440 ( V_654 ) ;
if ( V_1 == 0 )
V_1 = F_190 ( V_43 , V_325 , V_352 , V_357 ) ;
V_786:
F_306 ( V_371 ) ;
if ( V_1 == - V_365 )
return - V_5 ;
V_110:
return V_1 ;
}
static int F_441 ( struct V_42 * V_43 , struct V_47 * V_48 )
{
int V_241 ;
struct V_787 args = {
. V_199 = & V_48 -> V_199 ,
} ;
struct V_788 V_30 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_789 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
args . V_130 . V_122 = V_30 . V_131 . V_105 = NULL ;
V_241 = F_56 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 , 1 ) ;
return V_241 ;
}
static int F_159 ( struct V_42 * V_43 , struct V_47 * V_48 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_441 ( V_43 , V_48 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_442 ( struct V_42 * V_43 , struct V_47 * V_48 )
{
int V_241 ;
struct V_790 args = {
. V_199 = & V_48 -> V_199 ,
} ;
struct V_791 V_30 ;
struct V_132 V_133 = {
. V_247 = & V_248 [ V_792 ] ,
. V_250 = & args ,
. V_251 = & V_30 ,
} ;
args . V_130 . V_122 = V_30 . V_131 . V_105 = NULL ;
V_241 = F_56 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 , 1 ) ;
return V_241 ;
}
static int F_160 ( struct V_42 * V_43 , struct V_47 * V_48 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_442 ( V_43 , V_48 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
