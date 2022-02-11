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
static struct V_160 * F_70 ( struct V_168 * V_168 ,
struct V_169 * V_170 , T_4 V_171 , int V_172 ,
const struct V_173 * V_174 ,
T_5 V_175 )
{
struct V_13 * V_176 = F_71 ( V_168 -> V_13 ) ;
struct V_145 * V_146 = V_176 -> V_24 ;
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_160 * V_17 ;
V_17 = F_73 ( sizeof( * V_17 ) , V_175 ) ;
if ( V_17 == NULL )
goto V_1;
V_17 -> V_165 . V_164 = F_74 ( & V_170 -> V_177 , V_175 ) ;
if ( V_17 -> V_165 . V_164 == NULL )
goto V_178;
F_75 ( V_168 ) ;
V_17 -> V_168 = * V_168 ;
V_17 -> V_146 = V_176 ;
V_17 -> V_179 = V_170 ;
F_76 ( & V_170 -> V_180 ) ;
V_17 -> V_165 . V_181 = F_77 ( V_146 ) ;
V_17 -> V_165 . V_182 = V_172 ;
V_17 -> V_165 . V_171 = V_171 & ( V_183 | V_184 ) ;
V_17 -> V_165 . V_185 = V_43 -> V_28 -> V_186 ;
V_17 -> V_165 . V_187 = V_170 -> V_188 . V_187 ;
V_17 -> V_165 . V_189 = & V_17 -> V_168 . V_13 -> V_190 ;
V_17 -> V_165 . V_43 = V_43 ;
V_17 -> V_165 . V_191 = V_43 -> V_192 ;
V_17 -> V_165 . V_193 = V_194 ;
if ( V_172 & V_195 ) {
T_6 * V_196 ;
V_17 -> V_165 . V_197 . V_174 = & V_17 -> V_174 ;
memcpy ( & V_17 -> V_174 , V_174 , sizeof( V_17 -> V_174 ) ) ;
V_196 = ( T_6 * ) V_17 -> V_165 . V_197 . V_12 . V_128 ;
V_196 [ 0 ] = V_125 ;
V_196 [ 1 ] = V_40 -> V_198 ;
}
V_17 -> V_167 . V_181 = & V_17 -> V_161 . V_181 ;
V_17 -> V_167 . V_199 = & V_17 -> V_161 . V_199 ;
V_17 -> V_167 . V_164 = V_17 -> V_165 . V_164 ;
F_68 ( V_17 ) ;
F_78 ( & V_17 -> V_200 ) ;
return V_17 ;
V_178:
F_79 ( V_17 ) ;
V_1:
F_80 ( V_176 ) ;
return NULL ;
}
static void F_81 ( struct V_200 * V_200 )
{
struct V_160 * V_17 = F_82 ( V_200 ,
struct V_160 , V_200 ) ;
F_83 ( V_17 -> V_165 . V_164 ) ;
if ( V_17 -> V_48 != NULL )
F_84 ( V_17 -> V_48 ) ;
F_85 ( V_17 -> V_179 ) ;
F_80 ( V_17 -> V_146 ) ;
F_86 ( & V_17 -> V_168 ) ;
F_79 ( V_17 ) ;
}
static void F_87 ( struct V_160 * V_17 )
{
if ( V_17 != NULL )
F_88 ( & V_17 -> V_200 , F_81 ) ;
}
static int F_89 ( struct V_96 * V_97 )
{
int V_49 ;
V_49 = F_90 ( V_97 ) ;
return V_49 ;
}
static int F_91 ( struct V_47 * V_48 , T_4 V_201 , int V_202 )
{
int V_49 = 0 ;
if ( V_202 & V_203 )
goto V_110;
switch ( V_201 & ( V_183 | V_184 ) ) {
case V_183 :
V_49 |= F_31 ( V_204 , & V_48 -> V_172 ) != 0
&& V_48 -> V_205 != 0 ;
break;
case V_184 :
V_49 |= F_31 ( V_206 , & V_48 -> V_172 ) != 0
&& V_48 -> V_207 != 0 ;
break;
case V_183 | V_184 :
V_49 |= F_31 ( V_208 , & V_48 -> V_172 ) != 0
&& V_48 -> V_209 != 0 ;
}
V_110:
return V_49 ;
}
static int F_92 ( struct V_210 * V_211 , T_4 V_171 )
{
if ( ( V_211 -> type & V_171 ) != V_171 )
return 0 ;
if ( F_31 ( V_212 , & V_211 -> V_172 ) )
return 0 ;
F_93 ( V_211 ) ;
return 1 ;
}
static void F_94 ( struct V_47 * V_48 , T_4 V_171 )
{
switch ( V_171 ) {
case V_184 :
V_48 -> V_207 ++ ;
break;
case V_183 :
V_48 -> V_205 ++ ;
break;
case V_183 | V_184 :
V_48 -> V_209 ++ ;
}
F_95 ( V_48 , V_48 -> V_48 | V_171 ) ;
}
static void F_96 ( struct V_47 * V_48 , T_7 * V_199 , T_4 V_171 )
{
if ( F_31 ( V_213 , & V_48 -> V_172 ) == 0 )
memcpy ( V_48 -> V_199 . V_128 , V_199 -> V_128 , sizeof( V_48 -> V_199 . V_128 ) ) ;
memcpy ( V_48 -> V_214 . V_128 , V_199 -> V_128 , sizeof( V_48 -> V_214 . V_128 ) ) ;
switch ( V_171 ) {
case V_183 :
F_97 ( V_204 , & V_48 -> V_172 ) ;
break;
case V_184 :
F_97 ( V_206 , & V_48 -> V_172 ) ;
break;
case V_183 | V_184 :
F_97 ( V_208 , & V_48 -> V_172 ) ;
}
}
static void F_98 ( struct V_47 * V_48 , T_7 * V_199 , T_4 V_171 )
{
F_99 ( & V_48 -> V_215 ) ;
F_96 ( V_48 , V_199 , V_171 ) ;
F_100 ( & V_48 -> V_215 ) ;
}
static void F_101 ( struct V_47 * V_48 , T_7 * V_214 , const T_7 * V_216 , T_4 V_171 )
{
F_99 ( & V_48 -> V_215 ) ;
if ( V_216 != NULL ) {
memcpy ( V_48 -> V_199 . V_128 , V_216 -> V_128 , sizeof( V_48 -> V_199 . V_128 ) ) ;
F_97 ( V_213 , & V_48 -> V_172 ) ;
}
if ( V_214 != NULL )
F_96 ( V_48 , V_214 , V_171 ) ;
F_100 ( & V_48 -> V_215 ) ;
F_23 ( & V_48 -> V_179 -> V_217 ) ;
F_94 ( V_48 , V_171 ) ;
F_25 ( & V_48 -> V_179 -> V_217 ) ;
}
static int F_102 ( struct V_47 * V_48 , T_7 * V_214 , T_7 * V_211 , T_4 V_171 )
{
struct V_149 * V_150 = F_66 ( V_48 -> V_145 ) ;
struct V_210 * V_218 ;
int V_49 = 0 ;
V_171 &= ( V_183 | V_184 ) ;
F_103 () ;
V_218 = F_104 ( V_150 -> V_211 ) ;
if ( V_218 == NULL )
goto V_219;
F_23 ( & V_218 -> V_220 ) ;
if ( V_150 -> V_211 != V_218 ||
( V_218 -> type & V_171 ) != V_171 )
goto V_221;
if ( V_211 == NULL )
V_211 = & V_218 -> V_199 ;
else if ( memcmp ( V_218 -> V_199 . V_128 , V_211 -> V_128 , V_222 ) != 0 )
goto V_221;
F_93 ( V_218 ) ;
F_101 ( V_48 , V_214 , & V_218 -> V_199 , V_171 ) ;
V_49 = 1 ;
V_221:
F_25 ( & V_218 -> V_220 ) ;
V_219:
F_105 () ;
if ( ! V_49 && V_214 != NULL ) {
F_101 ( V_48 , V_214 , NULL , V_171 ) ;
V_49 = 1 ;
}
return V_49 ;
}
static void F_106 ( struct V_145 * V_145 , T_4 V_171 )
{
struct V_210 * V_211 ;
F_103 () ;
V_211 = F_104 ( F_66 ( V_145 ) -> V_211 ) ;
if ( V_211 == NULL || ( V_211 -> type & V_171 ) == V_171 ) {
F_105 () ;
return;
}
F_105 () ;
F_107 ( V_145 ) ;
}
static struct V_47 * F_108 ( struct V_160 * V_223 )
{
struct V_47 * V_48 = V_223 -> V_48 ;
struct V_149 * V_150 = F_66 ( V_48 -> V_145 ) ;
struct V_210 * V_211 ;
int V_202 = V_223 -> V_165 . V_182 & V_203 ;
T_4 V_171 = V_223 -> V_165 . V_171 ;
T_7 V_199 ;
int V_49 = - V_120 ;
for (; ; ) {
if ( F_91 ( V_48 , V_171 , V_202 ) ) {
F_23 ( & V_48 -> V_179 -> V_217 ) ;
if ( F_91 ( V_48 , V_171 , V_202 ) ) {
F_94 ( V_48 , V_171 ) ;
F_25 ( & V_48 -> V_179 -> V_217 ) ;
goto V_224;
}
F_25 ( & V_48 -> V_179 -> V_217 ) ;
}
F_103 () ;
V_211 = F_104 ( V_150 -> V_211 ) ;
if ( V_211 == NULL ||
! F_92 ( V_211 , V_171 ) ) {
F_105 () ;
break;
}
memcpy ( V_199 . V_128 , V_211 -> V_199 . V_128 , sizeof( V_199 . V_128 ) ) ;
F_105 () ;
V_49 = F_109 ( V_48 -> V_145 , V_48 -> V_179 -> V_225 , V_202 ) ;
if ( V_49 != 0 )
goto V_110;
V_49 = - V_120 ;
if ( F_102 ( V_48 , NULL , & V_199 , V_171 ) )
goto V_224;
}
V_110:
return F_110 ( V_49 ) ;
V_224:
F_76 ( & V_48 -> V_18 ) ;
return V_48 ;
}
static struct V_47 * F_111 ( struct V_160 * V_128 )
{
struct V_145 * V_145 ;
struct V_47 * V_48 = NULL ;
struct V_210 * V_211 ;
int V_49 ;
if ( ! V_128 -> V_226 ) {
V_48 = F_108 ( V_128 ) ;
goto V_110;
}
V_49 = - V_120 ;
if ( ! ( V_128 -> V_162 . V_227 & V_228 ) )
goto V_1;
V_145 = F_112 ( V_128 -> V_146 -> V_229 , & V_128 -> V_161 . V_181 , & V_128 -> V_162 ) ;
V_49 = F_59 ( V_145 ) ;
if ( F_58 ( V_145 ) )
goto V_1;
V_49 = - V_230 ;
V_48 = F_113 ( V_145 , V_128 -> V_179 ) ;
if ( V_48 == NULL )
goto V_231;
if ( V_128 -> V_161 . V_232 != 0 ) {
int V_233 = 0 ;
F_103 () ;
V_211 = F_104 ( F_66 ( V_145 ) -> V_211 ) ;
if ( V_211 )
V_233 = V_211 -> V_172 ;
F_105 () ;
if ( ( V_233 & 1UL << V_212 ) == 0 )
F_114 ( V_48 -> V_145 ,
V_128 -> V_179 -> V_225 ,
& V_128 -> V_161 ) ;
else
F_115 ( V_48 -> V_145 ,
V_128 -> V_179 -> V_225 ,
& V_128 -> V_161 ) ;
}
F_102 ( V_48 , & V_128 -> V_161 . V_199 , NULL ,
V_128 -> V_165 . V_171 ) ;
F_116 ( V_145 ) ;
V_110:
return V_48 ;
V_231:
F_116 ( V_145 ) ;
V_1:
return F_110 ( V_49 ) ;
}
static struct V_234 * F_117 ( struct V_47 * V_48 )
{
struct V_149 * V_150 = F_66 ( V_48 -> V_145 ) ;
struct V_234 * V_235 ;
F_23 ( & V_48 -> V_145 -> V_151 ) ;
F_118 (ctx, &nfsi->open_files, list) {
if ( V_235 -> V_48 != V_48 )
continue;
F_119 ( V_235 ) ;
F_25 ( & V_48 -> V_145 -> V_151 ) ;
return V_235 ;
}
F_25 ( & V_48 -> V_145 -> V_151 ) ;
return F_110 ( - V_236 ) ;
}
static struct V_160 * F_120 ( struct V_234 * V_235 , struct V_47 * V_48 )
{
struct V_160 * V_223 ;
V_223 = F_70 ( & V_235 -> V_168 , V_48 -> V_179 , 0 , 0 , NULL , V_237 ) ;
if ( V_223 == NULL )
return F_110 ( - V_230 ) ;
V_223 -> V_48 = V_48 ;
F_76 ( & V_48 -> V_18 ) ;
return V_223 ;
}
static int F_121 ( struct V_160 * V_223 , T_4 V_171 , struct V_47 * * V_30 )
{
struct V_47 * V_238 ;
int V_49 ;
V_223 -> V_165 . V_182 = 0 ;
V_223 -> V_165 . V_171 = V_171 ;
memset ( & V_223 -> V_161 , 0 , sizeof( V_223 -> V_161 ) ) ;
memset ( & V_223 -> V_166 , 0 , sizeof( V_223 -> V_166 ) ) ;
F_68 ( V_223 ) ;
V_49 = F_122 ( V_223 ) ;
if ( V_49 != 0 )
return V_49 ;
V_238 = F_111 ( V_223 ) ;
if ( F_58 ( V_238 ) )
return F_59 ( V_238 ) ;
F_123 ( & V_223 -> V_168 , V_238 , V_171 ) ;
* V_30 = V_238 ;
return 0 ;
}
static int F_124 ( struct V_160 * V_223 , struct V_47 * V_48 )
{
struct V_47 * V_238 ;
int V_49 ;
F_125 ( V_213 , & V_48 -> V_172 ) ;
F_126 () ;
if ( V_48 -> V_209 != 0 ) {
F_125 ( V_208 , & V_48 -> V_172 ) ;
V_49 = F_121 ( V_223 , V_183 | V_184 , & V_238 ) ;
if ( V_49 != 0 )
return V_49 ;
if ( V_238 != V_48 )
return - V_239 ;
}
if ( V_48 -> V_207 != 0 ) {
F_125 ( V_206 , & V_48 -> V_172 ) ;
V_49 = F_121 ( V_223 , V_184 , & V_238 ) ;
if ( V_49 != 0 )
return V_49 ;
if ( V_238 != V_48 )
return - V_239 ;
}
if ( V_48 -> V_205 != 0 ) {
F_125 ( V_204 , & V_48 -> V_172 ) ;
V_49 = F_121 ( V_223 , V_183 , & V_238 ) ;
if ( V_49 != 0 )
return V_49 ;
if ( V_238 != V_48 )
return - V_239 ;
}
if ( F_31 ( V_213 , & V_48 -> V_172 ) == 0 &&
memcmp ( V_48 -> V_199 . V_128 , V_48 -> V_214 . V_128 , sizeof( V_48 -> V_199 . V_128 ) ) != 0 ) {
F_99 ( & V_48 -> V_215 ) ;
if ( F_31 ( V_213 , & V_48 -> V_172 ) == 0 )
memcpy ( V_48 -> V_199 . V_128 , V_48 -> V_214 . V_128 , sizeof( V_48 -> V_199 . V_128 ) ) ;
F_100 ( & V_48 -> V_215 ) ;
}
return 0 ;
}
static int F_127 ( struct V_234 * V_235 , struct V_47 * V_48 )
{
struct V_210 * V_211 ;
struct V_160 * V_223 ;
T_4 V_232 = 0 ;
int V_240 ;
V_223 = F_120 ( V_235 , V_48 ) ;
if ( F_58 ( V_223 ) )
return F_59 ( V_223 ) ;
V_223 -> V_165 . V_193 = V_241 ;
V_223 -> V_165 . V_181 = F_77 ( V_48 -> V_145 ) ;
F_103 () ;
V_211 = F_104 ( F_66 ( V_48 -> V_145 ) -> V_211 ) ;
if ( V_211 != NULL && F_31 ( V_212 , & V_211 -> V_172 ) != 0 )
V_232 = V_211 -> type ;
F_105 () ;
V_223 -> V_165 . V_197 . V_232 = V_232 ;
V_240 = F_124 ( V_223 , V_48 ) ;
F_87 ( V_223 ) ;
return V_240 ;
}
static int F_128 ( struct V_234 * V_235 , struct V_47 * V_48 )
{
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_127 ( V_235 , V_48 ) ;
if ( V_1 != - V_71 )
break;
F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_129 ( struct V_169 * V_170 , struct V_47 * V_48 )
{
struct V_234 * V_235 ;
int V_49 ;
V_235 = F_117 ( V_48 ) ;
if ( F_58 ( V_235 ) )
return F_59 ( V_235 ) ;
V_49 = F_128 ( V_235 , V_48 ) ;
F_130 ( V_235 ) ;
return V_49 ;
}
static int F_131 ( struct V_234 * V_235 , struct V_47 * V_48 , const T_7 * V_199 )
{
struct V_160 * V_223 ;
int V_49 ;
V_223 = F_120 ( V_235 , V_48 ) ;
if ( F_58 ( V_223 ) )
return F_59 ( V_223 ) ;
V_223 -> V_165 . V_193 = V_242 ;
memcpy ( V_223 -> V_165 . V_197 . V_211 . V_128 , V_199 -> V_128 ,
sizeof( V_223 -> V_165 . V_197 . V_211 . V_128 ) ) ;
V_49 = F_124 ( V_223 , V_48 ) ;
F_87 ( V_223 ) ;
return V_49 ;
}
int F_132 ( struct V_234 * V_235 , struct V_47 * V_48 , const T_7 * V_199 )
{
struct V_45 V_46 = { } ;
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
int V_1 ;
do {
V_1 = F_131 ( V_235 , V_48 , V_199 ) ;
switch ( V_1 ) {
case 0 :
case - V_236 :
case - V_239 :
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
case - V_230 :
V_1 = 0 ;
goto V_110;
}
V_1 = F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
V_110:
return V_1 ;
}
static void F_133 ( struct V_96 * V_97 , void * V_126 )
{
struct V_160 * V_128 = V_126 ;
V_128 -> V_243 = V_97 -> V_142 ;
if ( V_128 -> V_243 == 0 ) {
memcpy ( V_128 -> V_161 . V_199 . V_128 , V_128 -> V_166 . V_199 . V_128 ,
sizeof( V_128 -> V_161 . V_199 . V_128 ) ) ;
F_134 ( & V_128 -> V_179 -> V_177 , 0 ) ;
F_26 ( V_128 -> V_161 . V_43 , V_128 -> V_80 ) ;
V_128 -> V_226 = 1 ;
}
}
static void F_135 ( void * V_126 )
{
struct V_160 * V_128 = V_126 ;
struct V_47 * V_48 = NULL ;
if ( V_128 -> V_244 == 0 )
goto V_245;
if ( ! V_128 -> V_226 )
goto V_245;
V_48 = F_111 ( V_128 ) ;
if ( ! F_58 ( V_48 ) )
F_123 ( & V_128 -> V_168 , V_48 , V_128 -> V_165 . V_171 ) ;
V_245:
F_87 ( V_128 ) ;
}
static int F_136 ( struct V_160 * V_128 )
{
struct V_42 * V_43 = F_72 ( V_128 -> V_146 -> V_24 ) ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_248 ] ,
. V_249 = & V_128 -> V_167 ,
. V_250 = & V_128 -> V_166 ,
. V_251 = V_128 -> V_179 -> V_225 ,
} ;
struct V_135 V_252 = {
. V_137 = V_43 -> V_73 ,
. V_132 = & V_133 ,
. V_138 = & V_253 ,
. V_140 = V_128 ,
. V_254 = V_255 ,
. V_172 = V_256 ,
} ;
int V_240 ;
F_137 ( & V_128 -> V_200 ) ;
V_128 -> V_226 = 0 ;
V_128 -> V_243 = 0 ;
V_128 -> V_80 = V_125 ;
V_97 = F_57 ( & V_252 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
V_240 = F_89 ( V_97 ) ;
if ( V_240 != 0 ) {
V_128 -> V_244 = 1 ;
F_138 () ;
} else
V_240 = V_128 -> V_243 ;
F_60 ( V_97 ) ;
return V_240 ;
}
static void F_139 ( struct V_96 * V_97 , void * V_126 )
{
struct V_160 * V_128 = V_126 ;
struct V_169 * V_170 = V_128 -> V_179 ;
if ( F_140 ( V_128 -> V_165 . V_164 , V_97 ) != 0 )
return;
if ( V_128 -> V_48 != NULL ) {
struct V_210 * V_211 ;
if ( F_91 ( V_128 -> V_48 , V_128 -> V_165 . V_171 , V_128 -> V_165 . V_182 ) )
goto V_257;
F_103 () ;
V_211 = F_104 ( F_66 ( V_128 -> V_48 -> V_145 ) -> V_211 ) ;
if ( V_211 != NULL &&
F_31 ( V_212 , & V_211 -> V_172 ) == 0 ) {
F_105 () ;
goto V_257;
}
F_105 () ;
}
V_128 -> V_165 . V_187 = V_170 -> V_188 . V_187 ;
V_128 -> V_165 . V_185 = V_170 -> V_258 -> V_28 -> V_186 ;
if ( V_128 -> V_165 . V_193 == V_241 ) {
V_97 -> V_259 . V_246 = & V_247 [ V_260 ] ;
F_141 ( & V_128 -> V_161 . V_181 , V_128 -> V_165 . V_181 ) ;
}
V_128 -> V_80 = V_125 ;
if ( F_50 ( V_128 -> V_165 . V_43 ,
& V_128 -> V_165 . V_130 ,
& V_128 -> V_161 . V_131 , 1 , V_97 ) )
return;
F_53 ( V_97 ) ;
return;
V_257:
V_97 -> V_261 = NULL ;
}
static void F_142 ( struct V_96 * V_97 , void * V_126 )
{
F_33 ( V_97 , V_102 ) ;
F_139 ( V_97 , V_126 ) ;
}
static void F_143 ( struct V_96 * V_97 , void * V_126 )
{
struct V_160 * V_128 = V_126 ;
V_128 -> V_243 = V_97 -> V_142 ;
if ( ! F_41 ( V_97 , & V_128 -> V_161 . V_131 ) )
return;
if ( V_97 -> V_142 == 0 ) {
switch ( V_128 -> V_161 . V_162 -> V_201 & V_262 ) {
case V_263 :
break;
case V_264 :
V_128 -> V_243 = - V_265 ;
break;
case V_266 :
V_128 -> V_243 = - V_267 ;
break;
default:
V_128 -> V_243 = - V_268 ;
}
F_26 ( V_128 -> V_161 . V_43 , V_128 -> V_80 ) ;
if ( ! ( V_128 -> V_161 . V_269 & V_270 ) )
F_134 ( & V_128 -> V_179 -> V_177 , 0 ) ;
}
V_128 -> V_226 = 1 ;
}
static void F_144 ( void * V_126 )
{
struct V_160 * V_128 = V_126 ;
struct V_47 * V_48 = NULL ;
if ( V_128 -> V_244 == 0 )
goto V_245;
if ( V_128 -> V_243 != 0 || ! V_128 -> V_226 )
goto V_245;
if ( V_128 -> V_161 . V_269 & V_270 )
goto V_245;
V_48 = F_111 ( V_128 ) ;
if ( ! F_58 ( V_48 ) )
F_123 ( & V_128 -> V_168 , V_48 , V_128 -> V_165 . V_171 ) ;
V_245:
F_87 ( V_128 ) ;
}
static int F_145 ( struct V_160 * V_128 , int V_271 )
{
struct V_145 * V_146 = V_128 -> V_146 -> V_24 ;
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_272 * V_165 = & V_128 -> V_165 ;
struct V_273 * V_161 = & V_128 -> V_161 ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_274 ] ,
. V_249 = V_165 ,
. V_250 = V_161 ,
. V_251 = V_128 -> V_179 -> V_225 ,
} ;
struct V_135 V_252 = {
. V_137 = V_43 -> V_73 ,
. V_132 = & V_133 ,
. V_138 = & V_275 ,
. V_140 = V_128 ,
. V_254 = V_255 ,
. V_172 = V_256 ,
} ;
int V_240 ;
F_137 ( & V_128 -> V_200 ) ;
V_128 -> V_226 = 0 ;
V_128 -> V_243 = 0 ;
V_128 -> V_244 = 0 ;
if ( V_271 )
V_252 . V_138 = & V_276 ;
V_97 = F_57 ( & V_252 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
V_240 = F_89 ( V_97 ) ;
if ( V_240 != 0 ) {
V_128 -> V_244 = 1 ;
F_138 () ;
} else
V_240 = V_128 -> V_243 ;
F_60 ( V_97 ) ;
return V_240 ;
}
static int F_122 ( struct V_160 * V_128 )
{
struct V_145 * V_146 = V_128 -> V_146 -> V_24 ;
struct V_273 * V_161 = & V_128 -> V_161 ;
int V_240 ;
V_240 = F_145 ( V_128 , 1 ) ;
if ( V_240 != 0 || ! V_128 -> V_226 )
return V_240 ;
F_146 ( V_146 , V_161 -> V_163 ) ;
if ( V_161 -> V_269 & V_270 ) {
V_240 = F_136 ( V_128 ) ;
if ( V_240 != 0 )
return V_240 ;
}
return V_240 ;
}
static int F_147 ( struct V_160 * V_128 )
{
struct V_145 * V_146 = V_128 -> V_146 -> V_24 ;
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_272 * V_165 = & V_128 -> V_165 ;
struct V_273 * V_161 = & V_128 -> V_161 ;
int V_240 ;
V_240 = F_145 ( V_128 , 0 ) ;
if ( V_240 != 0 || ! V_128 -> V_226 )
return V_240 ;
if ( V_165 -> V_182 & V_195 ) {
F_65 ( V_146 , & V_161 -> V_148 ) ;
F_148 ( V_146 , V_161 -> V_163 ) ;
} else
F_146 ( V_146 , V_161 -> V_163 ) ;
if ( ( V_161 -> V_269 & V_277 ) == 0 )
V_43 -> V_76 &= ~ V_278 ;
if( V_161 -> V_269 & V_270 ) {
V_240 = F_136 ( V_128 ) ;
if ( V_240 != 0 )
return V_240 ;
}
if ( ! ( V_161 -> V_162 -> V_227 & V_228 ) )
F_149 ( V_43 , & V_161 -> V_181 , V_161 -> V_162 ) ;
return 0 ;
}
static int F_150 ( struct V_28 * V_29 )
{
unsigned int V_279 ;
int V_49 ;
for ( V_279 = V_280 ; V_279 != 0 ; V_279 -- ) {
V_49 = F_10 ( V_29 ) ;
if ( V_49 != 0 )
break;
if ( ! F_31 ( V_281 , & V_29 -> V_31 ) &&
! F_31 ( V_282 , & V_29 -> V_31 ) )
break;
F_151 ( V_29 ) ;
V_49 = - V_10 ;
}
return V_49 ;
}
static int F_152 ( struct V_42 * V_43 )
{
return F_150 ( V_43 -> V_28 ) ;
}
static int F_153 ( struct V_234 * V_235 , struct V_47 * V_48 )
{
struct V_160 * V_223 ;
int V_49 ;
V_223 = F_120 ( V_235 , V_48 ) ;
if ( F_58 ( V_223 ) )
return F_59 ( V_223 ) ;
V_49 = F_124 ( V_223 , V_48 ) ;
if ( V_49 == - V_239 )
F_154 ( V_235 -> V_168 . V_13 ) ;
F_87 ( V_223 ) ;
return V_49 ;
}
static int F_155 ( struct V_234 * V_235 , struct V_47 * V_48 )
{
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_153 ( V_235 , V_48 ) ;
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
static int F_156 ( struct V_169 * V_170 , struct V_47 * V_48 )
{
struct V_234 * V_235 ;
int V_49 ;
V_235 = F_117 ( V_48 ) ;
if ( F_58 ( V_235 ) )
return F_59 ( V_235 ) ;
V_49 = F_155 ( V_235 , V_48 ) ;
F_130 ( V_235 ) ;
return V_49 ;
}
static inline void F_157 ( struct V_160 * V_223 , struct V_173 * V_283 )
{
if ( ( V_223 -> V_161 . V_284 [ 1 ] & V_285 ) &&
! ( V_283 -> V_286 & V_287 ) )
V_283 -> V_286 |= V_288 ;
if ( ( V_223 -> V_161 . V_284 [ 1 ] & V_289 ) &&
! ( V_283 -> V_286 & V_290 ) )
V_283 -> V_286 |= V_291 ;
}
static int F_158 ( struct V_145 * V_146 , struct V_168 * V_168 , T_4 V_171 , int V_172 , struct V_173 * V_283 , struct V_251 * V_292 , struct V_47 * * V_30 )
{
struct V_169 * V_170 ;
struct V_47 * V_48 = NULL ;
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_160 * V_223 ;
int V_240 ;
V_240 = - V_230 ;
if ( ! ( V_170 = F_159 ( V_43 , V_292 ) ) ) {
F_2 ( L_25 ) ;
goto V_293;
}
V_240 = F_152 ( V_43 ) ;
if ( V_240 != 0 )
goto V_294;
if ( V_168 -> V_13 -> V_24 != NULL )
F_106 ( V_168 -> V_13 -> V_24 , V_171 ) ;
V_240 = - V_230 ;
V_223 = F_70 ( V_168 , V_170 , V_171 , V_172 , V_283 , V_295 ) ;
if ( V_223 == NULL )
goto V_294;
if ( V_168 -> V_13 -> V_24 != NULL )
V_223 -> V_48 = F_113 ( V_168 -> V_13 -> V_24 , V_170 ) ;
V_240 = F_147 ( V_223 ) ;
if ( V_240 != 0 )
goto V_296;
V_48 = F_111 ( V_223 ) ;
V_240 = F_59 ( V_48 ) ;
if ( F_58 ( V_48 ) )
goto V_296;
if ( V_43 -> V_76 & V_278 )
F_97 ( V_297 , & V_48 -> V_172 ) ;
if ( V_223 -> V_165 . V_182 & V_203 ) {
F_157 ( V_223 , V_283 ) ;
F_69 ( V_223 -> V_161 . V_162 ) ;
V_240 = F_160 ( V_48 -> V_145 , V_292 ,
V_223 -> V_161 . V_162 , V_283 ,
V_48 ) ;
if ( V_240 == 0 )
F_161 ( V_48 -> V_145 , V_283 ) ;
F_148 ( V_48 -> V_145 , V_223 -> V_161 . V_162 ) ;
}
F_87 ( V_223 ) ;
F_85 ( V_170 ) ;
* V_30 = V_48 ;
return 0 ;
V_296:
F_87 ( V_223 ) ;
V_294:
F_85 ( V_170 ) ;
V_293:
* V_30 = NULL ;
return V_240 ;
}
static struct V_47 * F_162 ( struct V_145 * V_146 , struct V_168 * V_168 , T_4 V_171 , int V_172 , struct V_173 * V_283 , struct V_251 * V_292 )
{
struct V_45 V_46 = { } ;
struct V_47 * V_30 ;
int V_240 ;
do {
V_240 = F_158 ( V_146 , V_168 , V_171 , V_172 , V_283 , V_292 , & V_30 ) ;
if ( V_240 == 0 )
break;
if ( V_240 == - V_298 ) {
F_21 ( V_78 L_5
L_26 ,
F_72 ( V_146 ) -> V_28 -> V_79 ) ;
V_46 . V_50 = 1 ;
continue;
}
if ( V_240 == - V_52 ) {
V_46 . V_50 = 1 ;
continue;
}
if ( V_240 == - V_120 ) {
V_46 . V_50 = 1 ;
continue;
}
V_30 = F_110 ( F_16 ( F_72 ( V_146 ) ,
V_240 , & V_46 ) ) ;
} while ( V_46 . V_50 );
return V_30 ;
}
static int F_163 ( struct V_145 * V_145 , struct V_251 * V_292 ,
struct V_299 * V_300 , struct V_173 * V_283 ,
struct V_47 * V_48 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_301 V_302 = {
. V_181 = F_77 ( V_145 ) ,
. V_303 = V_283 ,
. V_43 = V_43 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_304 V_30 = {
. V_300 = V_300 ,
. V_43 = V_43 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_305 ] ,
. V_249 = & V_302 ,
. V_250 = & V_30 ,
. V_251 = V_292 ,
} ;
unsigned long V_80 = V_125 ;
int V_240 ;
F_69 ( V_300 ) ;
if ( F_164 ( & V_302 . V_199 , V_145 ) ) {
} else if ( V_48 != NULL ) {
F_165 ( & V_302 . V_199 , V_48 , V_40 -> V_306 , V_40 -> V_307 ) ;
} else
memcpy ( & V_302 . V_199 , & V_308 , sizeof( V_302 . V_199 ) ) ;
V_240 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & V_302 . V_130 , & V_30 . V_131 , 1 ) ;
if ( V_240 == 0 && V_48 != NULL )
F_26 ( V_43 , V_80 ) ;
return V_240 ;
}
static int F_160 ( struct V_145 * V_145 , struct V_251 * V_292 ,
struct V_299 * V_300 , struct V_173 * V_283 ,
struct V_47 * V_48 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_163 ( V_145 , V_292 , V_300 , V_283 , V_48 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static void F_166 ( void * V_128 )
{
struct V_309 * V_126 = V_128 ;
struct V_169 * V_170 = V_126 -> V_48 -> V_179 ;
if ( V_126 -> V_310 )
F_167 ( V_126 -> V_48 -> V_145 ) ;
F_84 ( V_126 -> V_48 ) ;
F_83 ( V_126 -> V_302 . V_164 ) ;
F_85 ( V_170 ) ;
F_86 ( & V_126 -> V_168 ) ;
F_79 ( V_126 ) ;
}
static void F_168 ( struct V_47 * V_48 ,
T_4 V_171 )
{
F_23 ( & V_48 -> V_179 -> V_217 ) ;
if ( ! ( V_171 & V_183 ) )
F_125 ( V_204 , & V_48 -> V_172 ) ;
if ( ! ( V_171 & V_184 ) )
F_125 ( V_206 , & V_48 -> V_172 ) ;
F_125 ( V_208 , & V_48 -> V_172 ) ;
F_25 ( & V_48 -> V_179 -> V_217 ) ;
}
static void F_169 ( struct V_96 * V_97 , void * V_128 )
{
struct V_309 * V_126 = V_128 ;
struct V_47 * V_48 = V_126 -> V_48 ;
struct V_42 * V_43 = F_72 ( V_126 -> V_145 ) ;
if ( ! F_41 ( V_97 , & V_126 -> V_30 . V_131 ) )
return;
switch ( V_97 -> V_142 ) {
case 0 :
if ( V_126 -> V_310 )
F_170 ( V_48 -> V_145 ,
V_126 -> V_311 ) ;
F_98 ( V_48 , & V_126 -> V_30 . V_199 , 0 ) ;
F_26 ( V_43 , V_126 -> V_80 ) ;
F_168 ( V_48 ,
V_126 -> V_302 . V_171 ) ;
break;
case - V_56 :
case - V_75 :
case - V_52 :
case - V_55 :
if ( V_126 -> V_302 . V_171 == 0 )
break;
default:
if ( F_171 ( V_97 , V_43 , V_48 ) == - V_120 )
F_172 ( V_97 ) ;
}
F_173 ( V_126 -> V_302 . V_164 ) ;
F_146 ( V_126 -> V_145 , V_126 -> V_30 . V_300 ) ;
}
static void F_174 ( struct V_96 * V_97 , void * V_128 )
{
struct V_309 * V_126 = V_128 ;
struct V_47 * V_48 = V_126 -> V_48 ;
int V_312 = 0 ;
if ( F_140 ( V_126 -> V_302 . V_164 , V_97 ) != 0 )
return;
V_97 -> V_259 . V_246 = & V_247 [ V_313 ] ;
V_126 -> V_302 . V_171 = V_183 | V_184 ;
F_23 ( & V_48 -> V_179 -> V_217 ) ;
if ( V_48 -> V_209 == 0 ) {
if ( V_48 -> V_205 == 0 ) {
V_312 |= F_31 ( V_204 , & V_48 -> V_172 ) ;
V_312 |= F_31 ( V_208 , & V_48 -> V_172 ) ;
V_126 -> V_302 . V_171 &= ~ V_183 ;
}
if ( V_48 -> V_207 == 0 ) {
V_312 |= F_31 ( V_206 , & V_48 -> V_172 ) ;
V_312 |= F_31 ( V_208 , & V_48 -> V_172 ) ;
V_126 -> V_302 . V_171 &= ~ V_184 ;
}
}
F_25 ( & V_48 -> V_179 -> V_217 ) ;
if ( ! V_312 ) {
V_97 -> V_261 = NULL ;
return;
}
if ( V_126 -> V_302 . V_171 == 0 ) {
V_97 -> V_259 . V_246 = & V_247 [ V_314 ] ;
if ( V_126 -> V_310 &&
F_175 ( V_126 -> V_145 , & V_126 -> V_311 ) ) {
F_48 ( & F_72 ( V_126 -> V_145 ) -> V_315 ,
V_97 , NULL ) ;
return;
}
}
F_69 ( V_126 -> V_30 . V_300 ) ;
V_126 -> V_80 = V_125 ;
if ( F_50 ( F_72 ( V_126 -> V_145 ) ,
& V_126 -> V_302 . V_130 , & V_126 -> V_30 . V_131 ,
1 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
int F_176 ( struct V_168 * V_168 , struct V_47 * V_48 , T_5 V_175 , int V_316 , bool V_310 )
{
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
struct V_309 * V_126 ;
struct V_169 * V_170 = V_48 -> V_179 ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_314 ] ,
. V_251 = V_48 -> V_179 -> V_225 ,
} ;
struct V_135 V_252 = {
. V_137 = V_43 -> V_73 ,
. V_132 = & V_133 ,
. V_138 = & V_317 ,
. V_254 = V_255 ,
. V_172 = V_256 ,
} ;
int V_240 = - V_230 ;
V_126 = F_73 ( sizeof( * V_126 ) , V_175 ) ;
if ( V_126 == NULL )
goto V_110;
V_126 -> V_145 = V_48 -> V_145 ;
V_126 -> V_48 = V_48 ;
V_126 -> V_302 . V_181 = F_77 ( V_48 -> V_145 ) ;
V_126 -> V_302 . V_199 = & V_48 -> V_214 ;
V_126 -> V_302 . V_164 = F_74 ( & V_48 -> V_179 -> V_177 , V_175 ) ;
if ( V_126 -> V_302 . V_164 == NULL )
goto V_318;
V_126 -> V_302 . V_171 = 0 ;
V_126 -> V_302 . V_191 = V_43 -> V_319 ;
V_126 -> V_30 . V_300 = & V_126 -> V_300 ;
V_126 -> V_30 . V_164 = V_126 -> V_302 . V_164 ;
V_126 -> V_30 . V_43 = V_43 ;
V_126 -> V_310 = V_310 ;
F_75 ( V_168 ) ;
V_126 -> V_168 = * V_168 ;
V_133 . V_249 = & V_126 -> V_302 ;
V_133 . V_250 = & V_126 -> V_30 ;
V_252 . V_140 = V_126 ;
V_97 = F_57 ( & V_252 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
V_240 = 0 ;
if ( V_316 )
V_240 = F_90 ( V_97 ) ;
F_60 ( V_97 ) ;
return V_240 ;
V_318:
F_79 ( V_126 ) ;
V_110:
if ( V_310 )
F_167 ( V_48 -> V_145 ) ;
F_84 ( V_48 ) ;
F_85 ( V_170 ) ;
return V_240 ;
}
static struct V_145 *
F_177 ( struct V_145 * V_146 , struct V_234 * V_235 , int V_182 , struct V_173 * V_320 )
{
struct V_47 * V_48 ;
V_48 = F_162 ( V_146 , & V_235 -> V_168 , V_235 -> V_201 , V_182 , V_320 , V_235 -> V_292 ) ;
if ( F_58 ( V_48 ) )
return F_178 ( V_48 ) ;
V_235 -> V_48 = V_48 ;
return F_179 ( V_48 -> V_145 ) ;
}
static void F_180 ( struct V_234 * V_235 , int V_321 )
{
if ( V_235 -> V_48 == NULL )
return;
if ( V_321 )
F_181 ( & V_235 -> V_168 , V_235 -> V_48 , V_235 -> V_201 ) ;
else
F_123 ( & V_235 -> V_168 , V_235 -> V_48 , V_235 -> V_201 ) ;
}
static int F_182 ( struct V_42 * V_43 , struct V_322 * V_323 )
{
struct V_324 args = {
. V_323 = V_323 ,
} ;
struct V_325 V_30 = {} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_326 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
int V_240 ;
V_240 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
if ( V_240 == 0 ) {
memcpy ( V_43 -> V_192 , V_30 . V_192 , sizeof( V_43 -> V_192 ) ) ;
V_43 -> V_76 &= ~ ( V_327 | V_328 |
V_329 | V_330 |
V_331 | V_332 | V_333 |
V_334 | V_335 |
V_336 | V_337 ) ;
if ( V_30 . V_192 [ 0 ] & V_338 )
V_43 -> V_76 |= V_327 ;
if ( V_30 . V_339 != 0 )
V_43 -> V_76 |= V_328 ;
if ( V_30 . V_340 != 0 )
V_43 -> V_76 |= V_329 ;
if ( V_30 . V_192 [ 0 ] & V_23 )
V_43 -> V_76 |= V_330 ;
if ( V_30 . V_192 [ 1 ] & V_341 )
V_43 -> V_76 |= V_331 ;
if ( V_30 . V_192 [ 1 ] & V_342 )
V_43 -> V_76 |= V_332 ;
if ( V_30 . V_192 [ 1 ] & V_343 )
V_43 -> V_76 |= V_333 ;
if ( V_30 . V_192 [ 1 ] & V_344 )
V_43 -> V_76 |= V_334 ;
if ( V_30 . V_192 [ 1 ] & V_285 )
V_43 -> V_76 |= V_335 ;
if ( V_30 . V_192 [ 1 ] & V_345 )
V_43 -> V_76 |= V_336 ;
if ( V_30 . V_192 [ 1 ] & V_289 )
V_43 -> V_76 |= V_337 ;
memcpy ( V_43 -> V_319 , V_30 . V_192 , sizeof( V_43 -> V_319 ) ) ;
V_43 -> V_319 [ 0 ] &= V_346 | V_347 ;
V_43 -> V_319 [ 1 ] &= V_345 | V_289 ;
V_43 -> V_348 = V_30 . V_348 ;
}
return V_240 ;
}
int F_183 ( struct V_42 * V_43 , struct V_322 * V_323 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_182 ( V_43 , V_323 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_184 ( struct V_42 * V_43 , struct V_322 * V_323 ,
struct V_349 * V_350 )
{
struct V_351 args = {
. V_191 = V_352 ,
} ;
struct V_353 V_30 = {
. V_43 = V_43 ,
. V_300 = V_350 -> V_300 ,
. V_181 = V_323 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_354 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
F_69 ( V_350 -> V_300 ) ;
return F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
}
static int F_185 ( struct V_42 * V_43 , struct V_322 * V_323 ,
struct V_349 * V_350 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_184 ( V_43 , V_323 , V_350 ) ;
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
static int F_186 ( struct V_42 * V_43 , struct V_322 * V_323 ,
struct V_349 * V_350 , T_8 V_355 )
{
struct V_356 * V_357 ;
int V_49 ;
V_357 = F_187 ( V_355 , V_43 -> V_73 ) ;
if ( ! V_357 ) {
V_49 = - V_10 ;
goto V_110;
}
V_49 = F_185 ( V_43 , V_323 , V_350 ) ;
V_110:
return V_49 ;
}
static int F_188 ( struct V_42 * V_43 , struct V_322 * V_323 ,
struct V_349 * V_350 )
{
int V_358 , V_359 , V_240 = 0 ;
T_8 V_360 [ V_361 ] ;
V_359 = F_189 ( & V_360 [ 0 ] ) ;
V_360 [ V_359 ] = V_362 ;
V_359 += 1 ;
for ( V_358 = 0 ; V_358 < V_359 ; V_358 ++ ) {
V_240 = F_186 ( V_43 , V_323 , V_350 , V_360 [ V_358 ] ) ;
if ( V_240 == - V_4 || V_240 == - V_363 )
continue;
break;
}
if ( V_240 == - V_363 )
V_240 = - V_5 ;
return V_240 ;
}
static int F_190 ( struct V_42 * V_43 , struct V_322 * V_323 ,
struct V_349 * V_350 )
{
int V_240 = F_185 ( V_43 , V_323 , V_350 ) ;
if ( ( V_240 == - V_4 ) && ! ( V_43 -> V_172 & V_364 ) )
V_240 = F_188 ( V_43 , V_323 , V_350 ) ;
if ( V_240 == 0 )
V_240 = F_183 ( V_43 , V_323 ) ;
if ( V_240 == 0 )
V_240 = F_191 ( V_43 , V_323 , V_350 ) ;
return F_1 ( V_240 ) ;
}
static int F_192 ( struct V_145 * V_146 , const struct V_365 * V_189 ,
struct V_299 * V_300 , struct V_322 * V_323 )
{
int V_240 = - V_230 ;
struct V_366 * V_366 = NULL ;
struct V_367 * V_368 = NULL ;
V_366 = F_193 ( V_295 ) ;
if ( V_366 == NULL )
goto V_110;
V_368 = F_194 ( sizeof( struct V_367 ) , V_295 ) ;
if ( V_368 == NULL )
goto V_110;
V_240 = F_195 ( V_146 , V_189 , V_368 , V_366 ) ;
if ( V_240 != 0 )
goto V_110;
if ( F_196 ( & F_72 ( V_146 ) -> V_369 , & V_368 -> V_300 . V_369 ) ) {
F_2 ( L_27
L_28 , V_9 , V_189 -> V_189 ) ;
V_240 = - V_10 ;
goto V_110;
}
F_197 ( & V_368 -> V_300 ) ;
memcpy ( V_300 , & V_368 -> V_300 , sizeof( struct V_299 ) ) ;
memset ( V_323 , 0 , sizeof( struct V_322 ) ) ;
V_110:
if ( V_366 )
F_198 ( V_366 ) ;
F_79 ( V_368 ) ;
return V_240 ;
}
static int F_149 ( struct V_42 * V_43 , struct V_322 * V_323 , struct V_299 * V_300 )
{
struct V_370 args = {
. V_181 = V_323 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_371 V_30 = {
. V_300 = V_300 ,
. V_43 = V_43 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_372 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
F_69 ( V_300 ) ;
return F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
}
static int F_199 ( struct V_42 * V_43 , struct V_322 * V_323 , struct V_299 * V_300 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_149 ( V_43 , V_323 , V_300 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_200 ( struct V_13 * V_13 , struct V_299 * V_300 ,
struct V_173 * V_283 )
{
struct V_145 * V_145 = V_13 -> V_24 ;
struct V_251 * V_292 = NULL ;
struct V_47 * V_48 = NULL ;
int V_240 ;
if ( F_201 ( V_145 ) )
F_202 ( V_145 ) ;
F_69 ( V_300 ) ;
if ( V_283 -> V_286 & V_373 ) {
struct V_234 * V_235 ;
V_235 = F_203 ( V_283 -> V_374 ) ;
if ( V_235 ) {
V_292 = V_235 -> V_292 ;
V_48 = V_235 -> V_48 ;
}
}
V_240 = F_160 ( V_145 , V_292 , V_300 , V_283 , V_48 ) ;
if ( V_240 == 0 )
F_161 ( V_145 , V_283 ) ;
return V_240 ;
}
static int F_204 ( struct V_35 * V_36 , struct V_42 * V_43 ,
const struct V_322 * V_375 , const struct V_365 * V_189 ,
struct V_322 * V_323 , struct V_299 * V_300 )
{
int V_240 ;
struct V_376 args = {
. V_191 = V_43 -> V_192 ,
. V_377 = V_375 ,
. V_189 = V_189 ,
} ;
struct V_353 V_30 = {
. V_43 = V_43 ,
. V_300 = V_300 ,
. V_181 = V_323 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_378 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
F_69 ( V_300 ) ;
F_2 ( L_29 , V_189 -> V_189 ) ;
V_240 = F_64 ( V_36 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
F_2 ( L_30 , V_240 ) ;
return V_240 ;
}
static int F_205 ( struct V_42 * V_43 , struct V_322 * V_375 ,
struct V_365 * V_189 , struct V_322 * V_323 ,
struct V_299 * V_300 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_204 ( V_43 -> V_73 , V_43 , V_375 , V_189 , V_323 , V_300 ) ;
if ( V_1 == - V_379 ) {
V_1 = - V_380 ;
break;
}
V_1 = F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_206 ( struct V_35 * V_36 , struct V_145 * V_146 ,
const struct V_365 * V_189 , struct V_322 * V_323 ,
struct V_299 * V_300 )
{
int V_240 ;
F_2 ( L_31 , V_189 -> V_189 ) ;
V_240 = F_204 ( V_36 , F_72 ( V_146 ) , F_77 ( V_146 ) , V_189 , V_323 , V_300 ) ;
if ( V_240 == - V_379 )
V_240 = F_192 ( V_146 , V_189 , V_300 , V_323 ) ;
F_2 ( L_32 , V_240 ) ;
return V_240 ;
}
void F_207 ( struct V_299 * V_300 , struct V_322 * V_181 )
{
memset ( V_181 , 0 , sizeof( struct V_322 ) ) ;
V_300 -> V_369 . V_381 = 1 ;
V_300 -> V_227 |= V_382 | V_383 |
V_384 | V_385 | V_386 ;
V_300 -> V_201 = V_266 | V_387 | V_388 ;
V_300 -> V_389 = 2 ;
}
static int F_208 ( struct V_35 * V_36 , struct V_145 * V_146 , struct V_365 * V_189 ,
struct V_322 * V_323 , struct V_299 * V_300 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_146 ) ,
F_206 ( V_36 , V_146 , V_189 , V_323 , V_300 ) ,
& V_46 ) ;
if ( V_1 == - V_5 )
F_207 ( V_300 , V_323 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_209 ( struct V_145 * V_145 , struct V_390 * V_391 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_392 args = {
. V_181 = F_77 ( V_145 ) ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_393 V_30 = {
. V_43 = V_43 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_394 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
. V_251 = V_391 -> V_292 ,
} ;
int V_201 = V_391 -> V_395 ;
int V_240 ;
if ( V_201 & V_396 )
args . V_397 |= V_398 ;
if ( F_210 ( V_145 -> V_399 ) ) {
if ( V_201 & V_400 )
args . V_397 |= V_401 | V_402 | V_403 ;
if ( V_201 & V_404 )
args . V_397 |= V_405 ;
} else {
if ( V_201 & V_400 )
args . V_397 |= V_401 | V_402 ;
if ( V_201 & V_404 )
args . V_397 |= V_406 ;
}
V_30 . V_300 = F_211 () ;
if ( V_30 . V_300 == NULL )
return - V_230 ;
V_240 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
if ( ! V_240 ) {
V_391 -> V_395 = 0 ;
if ( V_30 . V_397 & V_398 )
V_391 -> V_395 |= V_396 ;
if ( V_30 . V_397 & ( V_401 | V_402 | V_403 ) )
V_391 -> V_395 |= V_400 ;
if ( V_30 . V_397 & ( V_405 | V_406 ) )
V_391 -> V_395 |= V_404 ;
F_146 ( V_145 , V_30 . V_300 ) ;
}
F_212 ( V_30 . V_300 ) ;
return V_240 ;
}
static int F_213 ( struct V_145 * V_145 , struct V_390 * V_391 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_145 ) ,
F_209 ( V_145 , V_391 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_214 ( struct V_145 * V_145 , struct V_366 * V_366 ,
unsigned int V_27 , unsigned int V_407 )
{
struct V_408 args = {
. V_181 = F_77 ( V_145 ) ,
. V_27 = V_27 ,
. V_407 = V_407 ,
. V_19 = & V_366 ,
} ;
struct V_409 V_30 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_410 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
return F_64 ( F_72 ( V_145 ) -> V_73 , F_72 ( V_145 ) , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
}
static int F_215 ( struct V_145 * V_145 , struct V_366 * V_366 ,
unsigned int V_27 , unsigned int V_407 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_145 ) ,
F_214 ( V_145 , V_366 , V_27 , V_407 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_216 ( struct V_145 * V_146 , struct V_13 * V_13 , struct V_173 * V_283 ,
int V_172 , struct V_234 * V_235 )
{
struct V_168 V_411 = {
. V_13 = V_13 ,
} ;
struct V_168 * V_168 = & V_411 ;
struct V_47 * V_48 ;
struct V_251 * V_292 = NULL ;
T_4 V_171 = 0 ;
int V_240 = 0 ;
if ( V_235 != NULL ) {
V_292 = V_235 -> V_292 ;
V_168 = & V_235 -> V_168 ;
V_171 = V_235 -> V_201 ;
}
V_283 -> V_412 &= ~ F_217 () ;
V_48 = F_162 ( V_146 , V_168 , V_171 , V_172 , V_283 , V_292 ) ;
F_154 ( V_13 ) ;
if ( F_58 ( V_48 ) ) {
V_240 = F_59 ( V_48 ) ;
goto V_110;
}
F_218 ( V_13 , F_179 ( V_48 -> V_145 ) ) ;
F_219 ( V_13 , F_220 ( V_146 ) ) ;
if ( V_235 != NULL )
V_235 -> V_48 = V_48 ;
else
F_181 ( V_168 , V_48 , V_171 ) ;
V_110:
return V_240 ;
}
static int F_221 ( struct V_145 * V_146 , struct V_365 * V_189 )
{
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_413 args = {
. V_181 = F_77 ( V_146 ) ,
. V_189 . V_359 = V_189 -> V_359 ,
. V_189 . V_189 = V_189 -> V_189 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_414 V_30 = {
. V_43 = V_43 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_415 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
int V_240 = - V_230 ;
V_30 . V_163 = F_211 () ;
if ( V_30 . V_163 == NULL )
goto V_110;
V_240 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 1 ) ;
if ( V_240 == 0 ) {
F_65 ( V_146 , & V_30 . V_148 ) ;
F_148 ( V_146 , V_30 . V_163 ) ;
}
F_212 ( V_30 . V_163 ) ;
V_110:
return V_240 ;
}
static int F_222 ( struct V_145 * V_146 , struct V_365 * V_189 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_146 ) ,
F_221 ( V_146 , V_189 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static void F_223 ( struct V_132 * V_133 , struct V_145 * V_146 )
{
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_413 * args = V_133 -> V_249 ;
struct V_414 * V_30 = V_133 -> V_250 ;
args -> V_191 = V_43 -> V_319 ;
V_30 -> V_43 = V_43 ;
V_30 -> V_131 . V_106 = NULL ;
V_133 -> V_246 = & V_247 [ V_415 ] ;
}
static int F_224 ( struct V_96 * V_97 , struct V_145 * V_146 )
{
struct V_414 * V_30 = V_97 -> V_259 . V_250 ;
if ( ! F_41 ( V_97 , & V_30 -> V_131 ) )
return 0 ;
if ( F_171 ( V_97 , V_30 -> V_43 , NULL ) == - V_120 )
return 0 ;
F_65 ( V_146 , & V_30 -> V_148 ) ;
F_148 ( V_146 , V_30 -> V_163 ) ;
return 1 ;
}
static void F_225 ( struct V_132 * V_133 , struct V_145 * V_146 )
{
struct V_42 * V_43 = F_72 ( V_146 ) ;
struct V_416 * V_302 = V_133 -> V_249 ;
struct V_417 * V_30 = V_133 -> V_250 ;
V_133 -> V_246 = & V_247 [ V_418 ] ;
V_302 -> V_191 = V_43 -> V_192 ;
V_30 -> V_43 = V_43 ;
}
static int F_226 ( struct V_96 * V_97 , struct V_145 * V_419 ,
struct V_145 * V_420 )
{
struct V_417 * V_30 = V_97 -> V_259 . V_250 ;
if ( ! F_41 ( V_97 , & V_30 -> V_131 ) )
return 0 ;
if ( F_171 ( V_97 , V_30 -> V_43 , NULL ) == - V_120 )
return 0 ;
F_65 ( V_419 , & V_30 -> V_421 ) ;
F_148 ( V_419 , V_30 -> V_422 ) ;
F_65 ( V_420 , & V_30 -> V_423 ) ;
F_148 ( V_420 , V_30 -> V_424 ) ;
return 1 ;
}
static int F_227 ( struct V_145 * V_419 , struct V_365 * V_425 ,
struct V_145 * V_420 , struct V_365 * V_426 )
{
struct V_42 * V_43 = F_72 ( V_419 ) ;
struct V_416 V_302 = {
. V_419 = F_77 ( V_419 ) ,
. V_420 = F_77 ( V_420 ) ,
. V_425 = V_425 ,
. V_426 = V_426 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_417 V_30 = {
. V_43 = V_43 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_418 ] ,
. V_249 = & V_302 ,
. V_250 = & V_30 ,
} ;
int V_240 = - V_230 ;
V_30 . V_422 = F_211 () ;
V_30 . V_424 = F_211 () ;
if ( V_30 . V_422 == NULL || V_30 . V_424 == NULL )
goto V_110;
V_240 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & V_302 . V_130 , & V_30 . V_131 , 1 ) ;
if ( ! V_240 ) {
F_65 ( V_419 , & V_30 . V_421 ) ;
F_148 ( V_419 , V_30 . V_422 ) ;
F_65 ( V_420 , & V_30 . V_423 ) ;
F_148 ( V_420 , V_30 . V_424 ) ;
}
V_110:
F_212 ( V_30 . V_424 ) ;
F_212 ( V_30 . V_422 ) ;
return V_240 ;
}
static int F_228 ( struct V_145 * V_419 , struct V_365 * V_425 ,
struct V_145 * V_420 , struct V_365 * V_426 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_419 ) ,
F_227 ( V_419 , V_425 ,
V_420 , V_426 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_229 ( struct V_145 * V_145 , struct V_145 * V_146 , struct V_365 * V_189 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_427 V_302 = {
. V_181 = F_77 ( V_145 ) ,
. V_377 = F_77 ( V_146 ) ,
. V_189 = V_189 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_428 V_30 = {
. V_43 = V_43 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_429 ] ,
. V_249 = & V_302 ,
. V_250 = & V_30 ,
} ;
int V_240 = - V_230 ;
V_30 . V_300 = F_211 () ;
V_30 . V_163 = F_211 () ;
if ( V_30 . V_300 == NULL || V_30 . V_163 == NULL )
goto V_110;
V_240 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & V_302 . V_130 , & V_30 . V_131 , 1 ) ;
if ( ! V_240 ) {
F_65 ( V_146 , & V_30 . V_148 ) ;
F_148 ( V_146 , V_30 . V_163 ) ;
F_148 ( V_145 , V_30 . V_300 ) ;
}
V_110:
F_212 ( V_30 . V_163 ) ;
F_212 ( V_30 . V_300 ) ;
return V_240 ;
}
static int F_230 ( struct V_145 * V_145 , struct V_145 * V_146 , struct V_365 * V_189 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_145 ) ,
F_229 ( V_145 , V_146 , V_189 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static struct V_430 * F_231 ( struct V_145 * V_146 ,
struct V_365 * V_189 , struct V_173 * V_283 , T_6 V_431 )
{
struct V_430 * V_128 ;
V_128 = F_73 ( sizeof( * V_128 ) , V_295 ) ;
if ( V_128 != NULL ) {
struct V_42 * V_43 = F_72 ( V_146 ) ;
V_128 -> V_133 . V_246 = & V_247 [ V_432 ] ;
V_128 -> V_133 . V_249 = & V_128 -> V_302 ;
V_128 -> V_133 . V_250 = & V_128 -> V_30 ;
V_128 -> V_302 . V_377 = F_77 ( V_146 ) ;
V_128 -> V_302 . V_43 = V_43 ;
V_128 -> V_302 . V_189 = V_189 ;
V_128 -> V_302 . V_174 = V_283 ;
V_128 -> V_302 . V_431 = V_431 ;
V_128 -> V_302 . V_191 = V_43 -> V_192 ;
V_128 -> V_30 . V_43 = V_43 ;
V_128 -> V_30 . V_181 = & V_128 -> V_181 ;
V_128 -> V_30 . V_300 = & V_128 -> V_300 ;
V_128 -> V_30 . V_433 = & V_128 -> V_433 ;
F_69 ( V_128 -> V_30 . V_300 ) ;
F_69 ( V_128 -> V_30 . V_433 ) ;
}
return V_128 ;
}
static int F_232 ( struct V_145 * V_146 , struct V_13 * V_13 , struct V_430 * V_128 )
{
int V_240 = F_64 ( F_72 ( V_146 ) -> V_73 , F_72 ( V_146 ) , & V_128 -> V_133 ,
& V_128 -> V_302 . V_130 , & V_128 -> V_30 . V_131 , 1 ) ;
if ( V_240 == 0 ) {
F_65 ( V_146 , & V_128 -> V_30 . V_434 ) ;
F_148 ( V_146 , V_128 -> V_30 . V_433 ) ;
V_240 = F_233 ( V_13 , V_128 -> V_30 . V_181 , V_128 -> V_30 . V_300 ) ;
}
return V_240 ;
}
static void F_234 ( struct V_430 * V_128 )
{
F_79 ( V_128 ) ;
}
static int F_235 ( struct V_145 * V_146 , struct V_13 * V_13 ,
struct V_366 * V_366 , unsigned int V_359 , struct V_173 * V_283 )
{
struct V_430 * V_128 ;
int V_240 = - V_435 ;
if ( V_359 > V_436 )
goto V_110;
V_240 = - V_230 ;
V_128 = F_231 ( V_146 , & V_13 -> V_190 , V_283 , V_437 ) ;
if ( V_128 == NULL )
goto V_110;
V_128 -> V_133 . V_246 = & V_247 [ V_438 ] ;
V_128 -> V_302 . V_197 . V_439 . V_19 = & V_366 ;
V_128 -> V_302 . V_197 . V_439 . V_359 = V_359 ;
V_240 = F_232 ( V_146 , V_13 , V_128 ) ;
F_234 ( V_128 ) ;
V_110:
return V_240 ;
}
static int F_236 ( struct V_145 * V_146 , struct V_13 * V_13 ,
struct V_366 * V_366 , unsigned int V_359 , struct V_173 * V_283 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_146 ) ,
F_235 ( V_146 , V_13 , V_366 ,
V_359 , V_283 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_237 ( struct V_145 * V_146 , struct V_13 * V_13 ,
struct V_173 * V_283 )
{
struct V_430 * V_128 ;
int V_240 = - V_230 ;
V_128 = F_231 ( V_146 , & V_13 -> V_190 , V_283 , V_440 ) ;
if ( V_128 == NULL )
goto V_110;
V_240 = F_232 ( V_146 , V_13 , V_128 ) ;
F_234 ( V_128 ) ;
V_110:
return V_240 ;
}
static int F_238 ( struct V_145 * V_146 , struct V_13 * V_13 ,
struct V_173 * V_283 )
{
struct V_45 V_46 = { } ;
int V_1 ;
V_283 -> V_412 &= ~ F_217 () ;
do {
V_1 = F_16 ( F_72 ( V_146 ) ,
F_237 ( V_146 , V_13 , V_283 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_239 ( struct V_13 * V_13 , struct V_251 * V_292 ,
T_1 V_11 , struct V_366 * * V_19 , unsigned int V_18 , int V_441 )
{
struct V_145 * V_146 = V_13 -> V_24 ;
struct V_14 args = {
. V_181 = F_77 ( V_146 ) ,
. V_19 = V_19 ,
. V_27 = 0 ,
. V_18 = V_18 ,
. V_191 = F_72 ( V_13 -> V_24 ) -> V_192 ,
. V_441 = V_441 ,
} ;
struct V_442 V_30 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_443 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
. V_251 = V_292 ,
} ;
int V_240 ;
F_2 ( L_33 , V_9 ,
V_13 -> V_26 -> V_190 . V_189 ,
V_13 -> V_190 . V_189 ,
( unsigned long long ) V_11 ) ;
F_3 ( V_11 , F_240 ( V_146 ) , V_13 , & args ) ;
V_30 . V_27 = args . V_27 ;
V_240 = F_64 ( F_72 ( V_146 ) -> V_73 , F_72 ( V_146 ) , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
if ( V_240 >= 0 ) {
memcpy ( F_240 ( V_146 ) , V_30 . V_12 . V_128 , V_444 ) ;
V_240 += args . V_27 ;
}
F_241 ( V_146 ) ;
F_2 ( L_34 , V_9 , V_240 ) ;
return V_240 ;
}
static int F_242 ( struct V_13 * V_13 , struct V_251 * V_292 ,
T_1 V_11 , struct V_366 * * V_19 , unsigned int V_18 , int V_441 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_13 -> V_24 ) ,
F_239 ( V_13 , V_292 , V_11 ,
V_19 , V_18 , V_441 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_243 ( struct V_145 * V_146 , struct V_13 * V_13 ,
struct V_173 * V_283 , T_9 V_445 )
{
struct V_430 * V_128 ;
int V_201 = V_283 -> V_412 ;
int V_240 = - V_230 ;
F_4 ( ! ( V_283 -> V_286 & V_446 ) ) ;
F_4 ( ! F_244 ( V_201 ) && ! F_245 ( V_201 ) && ! F_246 ( V_201 ) && ! F_247 ( V_201 ) ) ;
V_128 = F_231 ( V_146 , & V_13 -> V_190 , V_283 , V_447 ) ;
if ( V_128 == NULL )
goto V_110;
if ( F_244 ( V_201 ) )
V_128 -> V_302 . V_431 = V_448 ;
else if ( F_245 ( V_201 ) ) {
V_128 -> V_302 . V_431 = V_449 ;
V_128 -> V_302 . V_197 . V_450 . V_451 = F_248 ( V_445 ) ;
V_128 -> V_302 . V_197 . V_450 . V_452 = F_249 ( V_445 ) ;
}
else if ( F_246 ( V_201 ) ) {
V_128 -> V_302 . V_431 = V_453 ;
V_128 -> V_302 . V_197 . V_450 . V_451 = F_248 ( V_445 ) ;
V_128 -> V_302 . V_197 . V_450 . V_452 = F_249 ( V_445 ) ;
}
V_240 = F_232 ( V_146 , V_13 , V_128 ) ;
F_234 ( V_128 ) ;
V_110:
return V_240 ;
}
static int F_250 ( struct V_145 * V_146 , struct V_13 * V_13 ,
struct V_173 * V_283 , T_9 V_445 )
{
struct V_45 V_46 = { } ;
int V_1 ;
V_283 -> V_412 &= ~ F_217 () ;
do {
V_1 = F_16 ( F_72 ( V_146 ) ,
F_243 ( V_146 , V_13 , V_283 , V_445 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_251 ( struct V_42 * V_43 , struct V_322 * V_323 ,
struct V_454 * V_455 )
{
struct V_456 args = {
. V_181 = V_323 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_457 V_30 = {
. V_455 = V_455 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_458 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
F_69 ( V_455 -> V_300 ) ;
return F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
}
static int F_252 ( struct V_42 * V_43 , struct V_322 * V_323 , struct V_454 * V_455 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_251 ( V_43 , V_323 , V_455 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_253 ( struct V_42 * V_43 , struct V_322 * V_323 ,
struct V_349 * V_459 )
{
struct V_460 args = {
. V_181 = V_323 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_461 V_30 = {
. V_459 = V_459 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_462 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
return F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
}
static int F_191 ( struct V_42 * V_43 , struct V_322 * V_323 , struct V_349 * V_459 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_253 ( V_43 , V_323 , V_459 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_254 ( struct V_42 * V_43 , struct V_322 * V_323 , struct V_349 * V_459 )
{
F_69 ( V_459 -> V_300 ) ;
return F_191 ( V_43 , V_323 , V_459 ) ;
}
static int F_255 ( struct V_42 * V_43 , struct V_322 * V_323 ,
struct V_463 * V_464 )
{
struct V_465 args = {
. V_181 = V_323 ,
. V_191 = V_43 -> V_192 ,
} ;
struct V_466 V_30 = {
. V_464 = V_464 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_467 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
if ( ( args . V_191 [ 0 ] & V_468 [ 0 ] ) == 0 ) {
memset ( V_464 , 0 , sizeof( * V_464 ) ) ;
return 0 ;
}
F_69 ( V_464 -> V_300 ) ;
return F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
}
static int F_256 ( struct V_42 * V_43 , struct V_322 * V_323 ,
struct V_463 * V_464 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_255 ( V_43 , V_323 , V_464 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
void F_257 ( struct V_469 * V_128 )
{
F_241 ( V_128 -> V_145 ) ;
}
static int F_258 ( struct V_96 * V_97 , struct V_469 * V_128 )
{
struct V_42 * V_43 = F_72 ( V_128 -> V_145 ) ;
if ( F_171 ( V_97 , V_43 , V_128 -> args . V_470 -> V_48 ) == - V_120 ) {
F_259 ( V_97 , V_43 -> V_28 ) ;
return - V_120 ;
}
F_257 ( V_128 ) ;
if ( V_97 -> V_142 > 0 )
F_26 ( V_43 , V_128 -> V_80 ) ;
return 0 ;
}
static int F_260 ( struct V_96 * V_97 , struct V_469 * V_128 )
{
F_2 ( L_17 , V_9 ) ;
if ( ! F_41 ( V_97 , & V_128 -> V_30 . V_131 ) )
return - V_120 ;
return V_128 -> V_471 ? V_128 -> V_471 ( V_97 , V_128 ) :
F_258 ( V_97 , V_128 ) ;
}
static void F_261 ( struct V_469 * V_128 , struct V_132 * V_133 )
{
V_128 -> V_80 = V_125 ;
V_128 -> V_471 = F_258 ;
V_133 -> V_246 = & V_247 [ V_472 ] ;
}
void F_262 ( struct V_96 * V_97 , struct V_469 * V_128 )
{
F_2 ( L_35 , V_9 ) ;
F_263 ( V_128 -> V_473 ) ;
V_128 -> V_473 = NULL ;
V_128 -> args . V_474 = V_128 -> V_475 ;
V_128 -> V_476 = NULL ;
V_128 -> args . V_181 = F_77 ( V_128 -> V_145 ) ;
V_128 -> V_471 = F_258 ;
V_97 -> V_477 = V_128 -> V_478 ;
F_264 ( V_97 , F_265 ( V_128 -> V_145 ) ) ;
}
static int F_266 ( struct V_96 * V_97 , struct V_479 * V_128 )
{
struct V_145 * V_145 = V_128 -> V_145 ;
if ( F_171 ( V_97 , F_72 ( V_145 ) , V_128 -> args . V_470 -> V_48 ) == - V_120 ) {
F_259 ( V_97 , F_72 ( V_145 ) -> V_28 ) ;
return - V_120 ;
}
if ( V_97 -> V_142 >= 0 ) {
F_26 ( F_72 ( V_145 ) , V_128 -> V_80 ) ;
F_267 ( V_145 , V_128 -> V_30 . V_300 ) ;
}
return 0 ;
}
static int F_268 ( struct V_96 * V_97 , struct V_479 * V_128 )
{
if ( ! F_41 ( V_97 , & V_128 -> V_30 . V_131 ) )
return - V_120 ;
return V_128 -> V_480 ? V_128 -> V_480 ( V_97 , V_128 ) :
F_266 ( V_97 , V_128 ) ;
}
void F_269 ( struct V_96 * V_97 , struct V_479 * V_128 )
{
F_2 ( L_35 , V_9 ) ;
F_263 ( V_128 -> V_473 ) ;
V_128 -> V_473 = NULL ;
V_128 -> V_476 = NULL ;
V_128 -> V_480 = F_266 ;
V_128 -> args . V_181 = F_77 ( V_128 -> V_145 ) ;
V_128 -> args . V_191 = V_128 -> V_30 . V_43 -> V_319 ;
V_128 -> args . V_474 = V_128 -> V_475 ;
V_128 -> V_30 . V_300 = & V_128 -> V_300 ;
V_97 -> V_477 = V_128 -> V_478 ;
F_264 ( V_97 , F_265 ( V_128 -> V_145 ) ) ;
}
static void F_270 ( struct V_479 * V_128 , struct V_132 * V_133 )
{
struct V_42 * V_43 = F_72 ( V_128 -> V_145 ) ;
if ( V_128 -> V_473 ) {
V_128 -> args . V_191 = NULL ;
V_128 -> V_30 . V_300 = NULL ;
} else
V_128 -> args . V_191 = V_43 -> V_319 ;
if ( ! V_128 -> V_480 )
V_128 -> V_480 = F_266 ;
V_128 -> V_30 . V_43 = V_43 ;
V_128 -> V_80 = V_125 ;
V_133 -> V_246 = & V_247 [ V_481 ] ;
}
static int F_271 ( struct V_96 * V_97 , struct V_479 * V_128 )
{
struct V_145 * V_145 = V_128 -> V_145 ;
if ( F_171 ( V_97 , F_72 ( V_145 ) , NULL ) == - V_120 ) {
F_259 ( V_97 , F_72 ( V_145 ) -> V_28 ) ;
return - V_120 ;
}
F_146 ( V_145 , V_128 -> V_30 . V_300 ) ;
return 0 ;
}
static int F_272 ( struct V_96 * V_97 , struct V_479 * V_128 )
{
if ( ! F_41 ( V_97 , & V_128 -> V_30 . V_131 ) )
return - V_120 ;
return V_128 -> V_480 ( V_97 , V_128 ) ;
}
static void F_273 ( struct V_479 * V_128 , struct V_132 * V_133 )
{
struct V_42 * V_43 = F_72 ( V_128 -> V_145 ) ;
if ( V_128 -> V_473 ) {
V_128 -> args . V_191 = NULL ;
V_128 -> V_30 . V_300 = NULL ;
} else
V_128 -> args . V_191 = V_43 -> V_319 ;
if ( ! V_128 -> V_480 )
V_128 -> V_480 = F_271 ;
V_128 -> V_30 . V_43 = V_43 ;
V_133 -> V_246 = & V_247 [ V_482 ] ;
}
static void F_274 ( void * V_126 )
{
struct V_483 * V_128 = V_126 ;
struct V_28 * V_29 = V_128 -> V_73 ;
if ( F_275 ( & V_29 -> V_484 ) > 1 )
F_276 ( V_29 ) ;
F_277 ( V_29 ) ;
F_79 ( V_128 ) ;
}
static void F_278 ( struct V_96 * V_97 , void * V_126 )
{
struct V_483 * V_128 = V_126 ;
struct V_28 * V_29 = V_128 -> V_73 ;
unsigned long V_80 = V_128 -> V_80 ;
if ( V_97 -> V_142 < 0 ) {
if ( F_31 ( V_485 , & V_29 -> V_486 ) != 0 )
F_18 ( V_29 ) ;
return;
}
F_22 ( V_29 , V_80 ) ;
}
int F_279 ( struct V_28 * V_29 , struct V_251 * V_292 )
{
struct V_132 V_133 = {
. V_246 = & V_247 [ V_487 ] ,
. V_249 = V_29 ,
. V_251 = V_292 ,
} ;
struct V_483 * V_128 ;
if ( ! F_280 ( & V_29 -> V_484 ) )
return - V_10 ;
V_128 = F_194 ( sizeof( * V_128 ) , V_295 ) ;
if ( V_128 == NULL )
return - V_230 ;
V_128 -> V_73 = V_29 ;
V_128 -> V_80 = V_125 ;
return F_281 ( V_29 -> V_488 , & V_133 , V_489 ,
& V_490 , V_128 ) ;
}
int F_282 ( struct V_28 * V_29 , struct V_251 * V_292 )
{
struct V_132 V_133 = {
. V_246 = & V_247 [ V_487 ] ,
. V_249 = V_29 ,
. V_251 = V_292 ,
} ;
unsigned long V_491 = V_125 ;
int V_240 ;
V_240 = F_63 ( V_29 -> V_488 , & V_133 , 0 ) ;
if ( V_240 < 0 )
return V_240 ;
F_22 ( V_29 , V_491 ) ;
return 0 ;
}
static inline int F_283 ( struct V_42 * V_43 )
{
return ( V_43 -> V_76 & V_327 )
&& ( V_43 -> V_348 & V_492 )
&& ( V_43 -> V_348 & V_493 ) ;
}
static void F_284 ( const void * V_494 , T_10 V_495 ,
struct V_366 * * V_19 , unsigned int * V_27 )
{
const void * V_17 = V_494 ;
* V_27 = F_285 ( V_494 ) ;
V_17 -= * V_27 ;
while ( V_17 < V_494 + V_495 ) {
* ( V_19 ++ ) = F_286 ( V_17 ) ;
V_17 += V_496 ;
}
}
static int F_287 ( const void * V_494 , T_10 V_495 ,
struct V_366 * * V_19 , unsigned int * V_27 )
{
struct V_366 * V_497 , * * V_498 ;
int V_499 = 0 ;
T_10 V_359 ;
V_498 = V_19 ;
do {
V_359 = F_288 ( T_10 , V_496 , V_495 ) ;
V_497 = F_193 ( V_295 ) ;
if ( V_497 == NULL )
goto V_500;
memcpy ( F_289 ( V_497 ) , V_494 , V_359 ) ;
V_494 += V_359 ;
V_495 -= V_359 ;
* V_19 ++ = V_497 ;
V_499 ++ ;
} while ( V_495 != 0 );
return V_499 ;
V_500:
for(; V_499 > 0 ; V_499 -- )
F_198 ( V_498 [ V_499 - 1 ] ) ;
return - V_230 ;
}
static void F_290 ( struct V_145 * V_145 , struct V_501 * V_502 )
{
struct V_149 * V_150 = F_66 ( V_145 ) ;
F_23 ( & V_145 -> V_151 ) ;
F_79 ( V_150 -> V_503 ) ;
V_150 -> V_503 = V_502 ;
F_25 ( & V_145 -> V_151 ) ;
}
static void F_291 ( struct V_145 * V_145 )
{
F_290 ( V_145 , NULL ) ;
}
static inline T_11 F_292 ( struct V_145 * V_145 , char * V_494 , T_10 V_495 )
{
struct V_149 * V_150 = F_66 ( V_145 ) ;
struct V_501 * V_502 ;
int V_49 = - V_236 ;
F_23 ( & V_145 -> V_151 ) ;
V_502 = V_150 -> V_503 ;
if ( V_502 == NULL )
goto V_110;
if ( V_494 == NULL )
goto V_504;
if ( V_502 -> V_505 == 0 )
goto V_110;
V_49 = - V_506 ;
if ( V_502 -> V_359 > V_495 )
goto V_110;
memcpy ( V_494 , V_502 -> V_128 , V_502 -> V_359 ) ;
V_504:
V_49 = V_502 -> V_359 ;
V_110:
F_25 ( & V_145 -> V_151 ) ;
return V_49 ;
}
static void F_293 ( struct V_145 * V_145 , const char * V_494 , T_10 V_507 )
{
struct V_501 * V_502 ;
if ( V_494 && V_507 <= V_508 ) {
V_502 = F_194 ( sizeof( * V_502 ) + V_507 , V_295 ) ;
if ( V_502 == NULL )
goto V_110;
V_502 -> V_505 = 1 ;
memcpy ( V_502 -> V_128 , V_494 , V_507 ) ;
} else {
V_502 = F_194 ( sizeof( * V_502 ) , V_295 ) ;
if ( V_502 == NULL )
goto V_110;
V_502 -> V_505 = 0 ;
}
V_502 -> V_359 = V_507 ;
V_110:
F_290 ( V_145 , V_502 ) ;
}
static T_11 F_294 ( struct V_145 * V_145 , void * V_494 , T_10 V_495 )
{
struct V_366 * V_19 [ V_509 ] ;
struct V_510 args = {
. V_181 = F_77 ( V_145 ) ,
. V_511 = V_19 ,
. V_507 = V_495 ,
} ;
struct V_512 V_30 = {
. V_507 = V_495 ,
} ;
void * V_513 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_514 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
struct V_366 * V_515 = NULL ;
int V_49 ;
if ( V_495 < V_508 ) {
V_515 = F_193 ( V_295 ) ;
V_513 = F_289 ( V_515 ) ;
if ( V_515 == NULL )
return - V_230 ;
args . V_511 [ 0 ] = V_515 ;
args . V_516 = 0 ;
args . V_507 = V_508 ;
} else {
V_513 = V_494 ;
F_284 ( V_494 , V_495 , args . V_511 , & args . V_516 ) ;
}
V_49 = F_64 ( F_72 ( V_145 ) -> V_73 , F_72 ( V_145 ) , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
if ( V_49 )
goto V_245;
if ( V_30 . V_507 > args . V_507 )
F_293 ( V_145 , NULL , V_30 . V_507 ) ;
else
F_293 ( V_145 , V_513 , V_30 . V_507 ) ;
if ( V_494 ) {
V_49 = - V_506 ;
if ( V_30 . V_507 > V_495 )
goto V_245;
if ( V_515 )
memcpy ( V_494 , V_513 , V_30 . V_507 ) ;
}
V_49 = V_30 . V_507 ;
V_245:
if ( V_515 )
F_198 ( V_515 ) ;
return V_49 ;
}
static T_11 F_295 ( struct V_145 * V_145 , void * V_494 , T_10 V_495 )
{
struct V_45 V_46 = { } ;
T_11 V_49 ;
do {
V_49 = F_294 ( V_145 , V_494 , V_495 ) ;
if ( V_49 >= 0 )
break;
V_49 = F_16 ( F_72 ( V_145 ) , V_49 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_49 ;
}
static T_11 F_296 ( struct V_145 * V_145 , void * V_494 , T_10 V_495 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
int V_49 ;
if ( ! F_283 ( V_43 ) )
return - V_517 ;
V_49 = F_297 ( V_43 , V_145 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( F_66 ( V_145 ) -> V_152 & V_518 )
F_298 ( V_145 ) ;
V_49 = F_292 ( V_145 , V_494 , V_495 ) ;
if ( V_49 != - V_236 )
return V_49 ;
return F_295 ( V_145 , V_494 , V_495 ) ;
}
static int F_299 ( struct V_145 * V_145 , const void * V_494 , T_10 V_495 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_366 * V_19 [ V_509 ] ;
struct V_519 V_302 = {
. V_181 = F_77 ( V_145 ) ,
. V_511 = V_19 ,
. V_507 = V_495 ,
} ;
struct V_520 V_30 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_521 ] ,
. V_249 = & V_302 ,
. V_250 = & V_30 ,
} ;
int V_49 , V_358 ;
if ( ! F_283 ( V_43 ) )
return - V_517 ;
V_358 = F_287 ( V_494 , V_495 , V_302 . V_511 , & V_302 . V_516 ) ;
if ( V_358 < 0 )
return V_358 ;
F_107 ( V_145 ) ;
V_49 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & V_302 . V_130 , & V_30 . V_131 , 1 ) ;
for (; V_358 > 0 ; V_358 -- )
F_300 ( V_19 [ V_358 - 1 ] ) ;
F_23 ( & V_145 -> V_151 ) ;
F_66 ( V_145 ) -> V_152 |= V_153 ;
F_25 ( & V_145 -> V_151 ) ;
F_301 ( V_145 ) ;
F_298 ( V_145 ) ;
return V_49 ;
}
static int F_302 ( struct V_145 * V_145 , const void * V_494 , T_10 V_495 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_145 ) ,
F_299 ( V_145 , V_494 , V_495 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_171 ( struct V_96 * V_97 , const struct V_42 * V_43 , struct V_47 * V_48 )
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
F_303 ( V_43 , V_522 ) ;
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
F_48 ( & V_29 -> V_523 , V_97 , NULL ) ;
if ( F_31 ( V_32 , & V_29 -> V_31 ) == 0 )
F_304 ( & V_29 -> V_523 , V_97 ) ;
V_97 -> V_142 = 0 ;
return - V_120 ;
}
int F_305 ( struct V_28 * V_29 , T_6 V_524 ,
unsigned short V_525 , struct V_251 * V_292 ,
struct V_526 * V_30 )
{
T_12 V_527 ;
struct V_528 V_529 = {
. V_527 = & V_527 ,
. V_530 = V_524 ,
. V_531 = V_29 -> V_532 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_533 ] ,
. V_249 = & V_529 ,
. V_250 = V_30 ,
. V_251 = V_292 ,
} ;
T_2 * V_17 ;
int V_279 = 0 ;
int V_240 ;
V_17 = ( T_2 * ) V_527 . V_128 ;
* V_17 ++ = F_6 ( ( T_6 ) V_29 -> V_534 . V_535 ) ;
* V_17 = F_6 ( ( T_6 ) V_29 -> V_534 . V_536 ) ;
for(; ; ) {
V_529 . V_537 = F_306 ( V_529 . V_538 ,
sizeof( V_529 . V_538 ) , L_37 ,
V_29 -> V_539 ,
F_307 ( V_29 -> V_488 ,
V_540 ) ,
F_307 ( V_29 -> V_488 ,
V_541 ) ,
V_29 -> V_488 -> V_542 -> V_543 -> V_544 ,
V_29 -> V_545 ) ;
V_529 . V_546 = F_306 ( V_529 . V_547 ,
sizeof( V_529 . V_547 ) ,
F_307 ( V_29 -> V_488 ,
V_548 ) ) ;
V_529 . V_549 = F_306 ( V_529 . V_550 ,
sizeof( V_529 . V_550 ) , L_38 ,
V_29 -> V_539 , V_525 >> 8 , V_525 & 255 ) ;
V_240 = F_63 ( V_29 -> V_488 , & V_133 , V_551 ) ;
if ( V_240 != - V_552 )
break;
if ( V_279 != 0 ) {
++ V_29 -> V_545 ;
break;
}
++ V_279 ;
F_308 ( V_29 -> V_553 / V_68 + 1 ) ;
}
return V_240 ;
}
int F_309 ( struct V_28 * V_29 ,
struct V_526 * V_302 ,
struct V_251 * V_292 )
{
struct V_349 V_459 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_554 ] ,
. V_249 = V_302 ,
. V_250 = & V_459 ,
. V_251 = V_292 ,
} ;
unsigned long V_491 ;
int V_240 ;
V_491 = V_125 ;
V_240 = F_63 ( V_29 -> V_488 , & V_133 , V_551 ) ;
if ( V_240 == 0 ) {
F_23 ( & V_29 -> V_81 ) ;
V_29 -> V_553 = V_459 . V_555 * V_68 ;
V_29 -> V_82 = V_491 ;
F_25 ( & V_29 -> V_81 ) ;
}
return V_240 ;
}
static void F_310 ( struct V_96 * V_97 , void * V_126 )
{
struct V_556 * V_128 = V_126 ;
if ( ! F_41 ( V_97 , & V_128 -> V_30 . V_131 ) )
return;
switch ( V_97 -> V_142 ) {
case - V_56 :
case - V_55 :
case 0 :
F_26 ( V_128 -> V_30 . V_43 , V_128 -> V_80 ) ;
break;
default:
if ( F_171 ( V_97 , V_128 -> V_30 . V_43 , NULL ) ==
- V_120 ) {
F_259 ( V_97 , V_128 -> V_30 . V_43 -> V_28 ) ;
return;
}
}
V_128 -> V_243 = V_97 -> V_142 ;
}
static void F_311 ( void * V_126 )
{
F_79 ( V_126 ) ;
}
static void F_312 ( struct V_96 * V_97 , void * V_128 )
{
struct V_556 * V_557 ;
V_557 = (struct V_556 * ) V_128 ;
if ( F_50 ( V_557 -> V_30 . V_43 ,
& V_557 -> args . V_130 ,
& V_557 -> V_30 . V_131 , 1 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
static int F_313 ( struct V_145 * V_145 , struct V_251 * V_292 , const T_7 * V_199 , int V_558 )
{
struct V_556 * V_128 ;
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_559 ] ,
. V_251 = V_292 ,
} ;
struct V_135 V_252 = {
. V_137 = V_43 -> V_73 ,
. V_132 = & V_133 ,
. V_138 = & V_560 ,
. V_172 = V_256 ,
} ;
int V_240 = 0 ;
V_128 = F_73 ( sizeof( * V_128 ) , V_237 ) ;
if ( V_128 == NULL )
return - V_230 ;
V_128 -> args . V_323 = & V_128 -> V_181 ;
V_128 -> args . V_199 = & V_128 -> V_199 ;
V_128 -> args . V_191 = V_43 -> V_192 ;
F_141 ( & V_128 -> V_181 , F_77 ( V_145 ) ) ;
memcpy ( & V_128 -> V_199 , V_199 , sizeof( V_128 -> V_199 ) ) ;
V_128 -> V_30 . V_300 = & V_128 -> V_300 ;
V_128 -> V_30 . V_43 = V_43 ;
F_69 ( V_128 -> V_30 . V_300 ) ;
V_128 -> V_80 = V_125 ;
V_128 -> V_243 = 0 ;
V_252 . V_140 = V_128 ;
V_133 . V_249 = & V_128 -> args ;
V_133 . V_250 = & V_128 -> V_30 ;
V_97 = F_57 ( & V_252 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
if ( ! V_558 )
goto V_110;
V_240 = F_89 ( V_97 ) ;
if ( V_240 != 0 )
goto V_110;
V_240 = V_128 -> V_243 ;
if ( V_240 != 0 )
goto V_110;
F_146 ( V_145 , & V_128 -> V_300 ) ;
V_110:
F_60 ( V_97 ) ;
return V_240 ;
}
int F_314 ( struct V_145 * V_145 , struct V_251 * V_292 , const T_7 * V_199 , int V_558 )
{
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_313 ( V_145 , V_292 , V_199 , V_558 ) ;
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
F_315 ( unsigned long V_37 )
{
F_14 ( V_37 ) ;
V_37 <<= 1 ;
if ( V_37 > V_561 )
return V_561 ;
return V_37 ;
}
static int F_316 ( struct V_47 * V_48 , int V_562 , struct V_563 * V_564 )
{
struct V_145 * V_145 = V_48 -> V_145 ;
struct V_42 * V_43 = F_72 ( V_145 ) ;
struct V_28 * V_29 = V_43 -> V_28 ;
struct V_565 V_302 = {
. V_181 = F_77 ( V_145 ) ,
. V_566 = V_564 ,
} ;
struct V_567 V_30 = {
. V_568 = V_564 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_569 ] ,
. V_249 = & V_302 ,
. V_250 = & V_30 ,
. V_251 = V_48 -> V_179 -> V_225 ,
} ;
struct V_570 * V_571 ;
int V_240 ;
V_302 . V_572 . V_185 = V_29 -> V_186 ;
V_240 = F_317 ( V_48 , V_564 ) ;
if ( V_240 != 0 )
goto V_110;
V_571 = V_564 -> V_573 . V_574 . V_179 ;
V_302 . V_572 . V_187 = V_571 -> V_575 . V_187 ;
V_302 . V_572 . V_576 = V_43 -> V_576 ;
V_240 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & V_302 . V_130 , & V_30 . V_131 , 1 ) ;
switch ( V_240 ) {
case 0 :
V_564 -> V_577 = V_578 ;
break;
case - V_579 :
V_240 = 0 ;
}
V_564 -> V_580 -> V_581 ( V_564 ) ;
V_110:
return V_240 ;
}
static int F_318 ( struct V_47 * V_48 , int V_562 , struct V_563 * V_564 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_48 -> V_145 ) ,
F_316 ( V_48 , V_562 , V_564 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_319 ( struct V_582 * V_582 , struct V_563 * V_566 )
{
int V_30 = 0 ;
switch ( V_566 -> V_583 & ( V_584 | V_585 ) ) {
case V_584 :
V_30 = F_320 ( V_582 , V_566 ) ;
break;
case V_585 :
V_30 = F_321 ( V_582 , V_566 ) ;
break;
default:
F_322 () ;
}
return V_30 ;
}
static struct V_586 * F_323 ( struct V_563 * V_566 ,
struct V_234 * V_235 ,
struct V_570 * V_571 ,
struct V_587 * V_164 )
{
struct V_586 * V_17 ;
struct V_145 * V_145 = V_571 -> V_588 -> V_145 ;
V_17 = F_73 ( sizeof( * V_17 ) , V_237 ) ;
if ( V_17 == NULL )
return NULL ;
V_17 -> V_302 . V_181 = F_77 ( V_145 ) ;
V_17 -> V_302 . V_566 = & V_17 -> V_566 ;
V_17 -> V_302 . V_164 = V_164 ;
V_17 -> V_30 . V_164 = V_164 ;
V_17 -> V_302 . V_199 = & V_571 -> V_589 ;
V_17 -> V_571 = V_571 ;
F_76 ( & V_571 -> V_590 ) ;
V_17 -> V_235 = F_119 ( V_235 ) ;
memcpy ( & V_17 -> V_566 , V_566 , sizeof( V_17 -> V_566 ) ) ;
V_17 -> V_43 = F_72 ( V_145 ) ;
return V_17 ;
}
static void F_324 ( void * V_128 )
{
struct V_586 * V_126 = V_128 ;
F_83 ( V_126 -> V_302 . V_164 ) ;
F_325 ( V_126 -> V_571 ) ;
F_130 ( V_126 -> V_235 ) ;
F_79 ( V_126 ) ;
}
static void F_326 ( struct V_96 * V_97 , void * V_128 )
{
struct V_586 * V_126 = V_128 ;
if ( ! F_41 ( V_97 , & V_126 -> V_30 . V_131 ) )
return;
switch ( V_97 -> V_142 ) {
case 0 :
memcpy ( V_126 -> V_571 -> V_589 . V_128 ,
V_126 -> V_30 . V_199 . V_128 ,
sizeof( V_126 -> V_571 -> V_589 . V_128 ) ) ;
F_26 ( V_126 -> V_43 , V_126 -> V_80 ) ;
break;
case - V_52 :
case - V_75 :
case - V_56 :
case - V_55 :
break;
default:
if ( F_171 ( V_97 , V_126 -> V_43 , NULL ) == - V_120 )
F_259 ( V_97 ,
V_126 -> V_43 -> V_28 ) ;
}
}
static void F_327 ( struct V_96 * V_97 , void * V_128 )
{
struct V_586 * V_126 = V_128 ;
if ( F_140 ( V_126 -> V_302 . V_164 , V_97 ) != 0 )
return;
if ( ( V_126 -> V_571 -> V_591 & V_592 ) == 0 ) {
V_97 -> V_261 = NULL ;
return;
}
V_126 -> V_80 = V_125 ;
if ( F_50 ( V_126 -> V_43 ,
& V_126 -> V_302 . V_130 ,
& V_126 -> V_30 . V_131 , 1 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
static struct V_96 * F_328 ( struct V_563 * V_566 ,
struct V_234 * V_235 ,
struct V_570 * V_571 ,
struct V_587 * V_164 )
{
struct V_586 * V_128 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_593 ] ,
. V_251 = V_235 -> V_292 ,
} ;
struct V_135 V_252 = {
. V_137 = F_265 ( V_571 -> V_588 -> V_145 ) ,
. V_132 = & V_133 ,
. V_138 = & V_594 ,
. V_254 = V_255 ,
. V_172 = V_256 ,
} ;
V_566 -> V_577 = V_578 ;
V_128 = F_323 ( V_566 , V_235 , V_571 , V_164 ) ;
if ( V_128 == NULL ) {
F_83 ( V_164 ) ;
return F_110 ( - V_230 ) ;
}
V_133 . V_249 = & V_128 -> V_302 ;
V_133 . V_250 = & V_128 -> V_30 ;
V_252 . V_140 = V_128 ;
return F_57 ( & V_252 ) ;
}
static int F_329 ( struct V_47 * V_48 , int V_562 , struct V_563 * V_564 )
{
struct V_149 * V_150 = F_66 ( V_48 -> V_145 ) ;
struct V_587 * V_164 ;
struct V_570 * V_571 ;
struct V_96 * V_97 ;
int V_240 = 0 ;
unsigned char V_583 = V_564 -> V_583 ;
V_240 = F_317 ( V_48 , V_564 ) ;
V_564 -> V_583 |= V_595 ;
F_330 ( & V_150 -> V_596 ) ;
if ( F_319 ( V_564 -> V_597 , V_564 ) == - V_236 ) {
F_331 ( & V_150 -> V_596 ) ;
goto V_110;
}
F_331 ( & V_150 -> V_596 ) ;
if ( V_240 != 0 )
goto V_110;
if ( F_31 ( V_213 , & V_48 -> V_172 ) )
goto V_110;
V_571 = V_564 -> V_573 . V_574 . V_179 ;
V_164 = F_74 ( & V_571 -> V_598 , V_295 ) ;
V_240 = - V_230 ;
if ( V_164 == NULL )
goto V_110;
V_97 = F_328 ( V_564 , F_203 ( V_564 -> V_597 ) , V_571 , V_164 ) ;
V_240 = F_59 ( V_97 ) ;
if ( F_58 ( V_97 ) )
goto V_110;
V_240 = F_89 ( V_97 ) ;
F_60 ( V_97 ) ;
V_110:
V_564 -> V_583 = V_583 ;
return V_240 ;
}
static struct V_599 * F_332 ( struct V_563 * V_566 ,
struct V_234 * V_235 , struct V_570 * V_571 ,
T_5 V_175 )
{
struct V_599 * V_17 ;
struct V_145 * V_145 = V_571 -> V_588 -> V_145 ;
struct V_42 * V_43 = F_72 ( V_145 ) ;
V_17 = F_73 ( sizeof( * V_17 ) , V_175 ) ;
if ( V_17 == NULL )
return NULL ;
V_17 -> V_302 . V_181 = F_77 ( V_145 ) ;
V_17 -> V_302 . V_566 = & V_17 -> V_566 ;
V_17 -> V_302 . V_600 = F_74 ( & V_571 -> V_588 -> V_179 -> V_177 , V_175 ) ;
if ( V_17 -> V_302 . V_600 == NULL )
goto V_245;
V_17 -> V_302 . V_601 = F_74 ( & V_571 -> V_598 , V_175 ) ;
if ( V_17 -> V_302 . V_601 == NULL )
goto V_602;
V_17 -> V_302 . V_603 = & V_571 -> V_589 ;
V_17 -> V_302 . V_572 . V_185 = V_43 -> V_28 -> V_186 ;
V_17 -> V_302 . V_572 . V_187 = V_571 -> V_575 . V_187 ;
V_17 -> V_302 . V_572 . V_576 = V_43 -> V_576 ;
V_17 -> V_30 . V_601 = V_17 -> V_302 . V_601 ;
V_17 -> V_571 = V_571 ;
V_17 -> V_43 = V_43 ;
F_76 ( & V_571 -> V_590 ) ;
V_17 -> V_235 = F_119 ( V_235 ) ;
memcpy ( & V_17 -> V_566 , V_566 , sizeof( V_17 -> V_566 ) ) ;
return V_17 ;
V_602:
F_83 ( V_17 -> V_302 . V_600 ) ;
V_245:
F_79 ( V_17 ) ;
return NULL ;
}
static void F_333 ( struct V_96 * V_97 , void * V_126 )
{
struct V_599 * V_128 = V_126 ;
struct V_47 * V_48 = V_128 -> V_571 -> V_588 ;
F_2 ( L_39 , V_9 ) ;
if ( F_140 ( V_128 -> V_302 . V_601 , V_97 ) != 0 )
return;
if ( ! ( V_128 -> V_302 . V_601 -> V_604 -> V_172 & V_605 ) ) {
if ( F_140 ( V_128 -> V_302 . V_600 , V_97 ) != 0 )
return;
V_128 -> V_302 . V_214 = & V_48 -> V_199 ;
V_128 -> V_302 . V_606 = 1 ;
V_128 -> V_30 . V_600 = V_128 -> V_302 . V_600 ;
} else
V_128 -> V_302 . V_606 = 0 ;
V_128 -> V_80 = V_125 ;
if ( F_50 ( V_128 -> V_43 ,
& V_128 -> V_302 . V_130 ,
& V_128 -> V_30 . V_131 , 1 , V_97 ) )
return;
F_53 ( V_97 ) ;
F_2 ( L_40 , V_9 , V_128 -> V_243 ) ;
}
static void F_334 ( struct V_96 * V_97 , void * V_126 )
{
F_33 ( V_97 , V_102 ) ;
F_333 ( V_97 , V_126 ) ;
}
static void F_335 ( struct V_96 * V_97 , void * V_126 )
{
struct V_599 * V_128 = V_126 ;
F_2 ( L_39 , V_9 ) ;
if ( ! F_41 ( V_97 , & V_128 -> V_30 . V_131 ) )
return;
V_128 -> V_243 = V_97 -> V_142 ;
if ( V_128 -> V_302 . V_606 != 0 ) {
if ( V_128 -> V_243 == 0 )
F_134 ( & V_128 -> V_571 -> V_598 , 0 ) ;
else
goto V_110;
}
if ( V_128 -> V_243 == 0 ) {
memcpy ( V_128 -> V_571 -> V_589 . V_128 , V_128 -> V_30 . V_199 . V_128 ,
sizeof( V_128 -> V_571 -> V_589 . V_128 ) ) ;
V_128 -> V_571 -> V_591 |= V_592 ;
F_26 ( F_72 ( V_128 -> V_235 -> V_168 . V_13 -> V_24 ) , V_128 -> V_80 ) ;
}
V_110:
F_2 ( L_41 , V_9 , V_128 -> V_243 ) ;
}
static void F_336 ( void * V_126 )
{
struct V_599 * V_128 = V_126 ;
F_2 ( L_39 , V_9 ) ;
F_83 ( V_128 -> V_302 . V_600 ) ;
if ( V_128 -> V_244 != 0 ) {
struct V_96 * V_97 ;
V_97 = F_328 ( & V_128 -> V_566 , V_128 -> V_235 , V_128 -> V_571 ,
V_128 -> V_302 . V_601 ) ;
if ( ! F_58 ( V_97 ) )
F_337 ( V_97 ) ;
F_2 ( L_42 , V_9 ) ;
} else
F_83 ( V_128 -> V_302 . V_601 ) ;
F_325 ( V_128 -> V_571 ) ;
F_130 ( V_128 -> V_235 ) ;
F_79 ( V_128 ) ;
F_2 ( L_43 , V_9 ) ;
}
static void F_338 ( struct V_42 * V_43 , struct V_570 * V_571 , int V_606 , int error )
{
switch ( error ) {
case - V_51 :
case - V_52 :
V_571 -> V_598 . V_172 &= ~ V_605 ;
if ( V_606 != 0 ||
( V_571 -> V_591 & V_592 ) != 0 )
F_17 ( V_43 , V_571 -> V_588 ) ;
break;
case - V_56 :
V_571 -> V_598 . V_172 &= ~ V_605 ;
case - V_55 :
F_18 ( V_43 -> V_28 ) ;
} ;
}
static int F_339 ( struct V_47 * V_48 , int V_562 , struct V_563 * V_566 , int V_607 )
{
struct V_599 * V_128 ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_608 ] ,
. V_251 = V_48 -> V_179 -> V_225 ,
} ;
struct V_135 V_252 = {
. V_137 = F_265 ( V_48 -> V_145 ) ,
. V_132 = & V_133 ,
. V_138 = & V_609 ,
. V_254 = V_255 ,
. V_172 = V_256 ,
} ;
int V_49 ;
F_2 ( L_39 , V_9 ) ;
V_128 = F_332 ( V_566 , F_203 ( V_566 -> V_597 ) ,
V_566 -> V_573 . V_574 . V_179 ,
V_607 == V_610 ? V_295 : V_237 ) ;
if ( V_128 == NULL )
return - V_230 ;
if ( F_340 ( V_562 ) )
V_128 -> V_302 . V_611 = 1 ;
if ( V_607 > V_610 ) {
if ( V_607 == V_612 )
V_128 -> V_302 . V_613 = V_612 ;
V_252 . V_138 = & V_614 ;
}
V_133 . V_249 = & V_128 -> V_302 ;
V_133 . V_250 = & V_128 -> V_30 ;
V_252 . V_140 = V_128 ;
V_97 = F_57 ( & V_252 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
V_49 = F_89 ( V_97 ) ;
if ( V_49 == 0 ) {
V_49 = V_128 -> V_243 ;
if ( V_49 )
F_338 ( V_128 -> V_43 , V_128 -> V_571 ,
V_128 -> V_302 . V_606 , V_49 ) ;
} else
V_128 -> V_244 = 1 ;
F_60 ( V_97 ) ;
F_2 ( L_41 , V_9 , V_49 ) ;
return V_49 ;
}
static int F_341 ( struct V_47 * V_48 , struct V_563 * V_564 )
{
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
if ( F_31 ( V_213 , & V_48 -> V_172 ) != 0 )
return 0 ;
V_1 = F_339 ( V_48 , V_615 , V_564 , V_612 ) ;
if ( V_1 != - V_71 )
break;
F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_342 ( struct V_47 * V_48 , struct V_563 * V_564 )
{
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
V_1 = F_317 ( V_48 , V_564 ) ;
if ( V_1 != 0 )
return V_1 ;
do {
if ( F_31 ( V_213 , & V_48 -> V_172 ) != 0 )
return 0 ;
V_1 = F_339 ( V_48 , V_615 , V_564 , V_616 ) ;
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
static int F_343 ( struct V_47 * V_48 , int V_562 , struct V_563 * V_564 )
{
struct V_149 * V_150 = F_66 ( V_48 -> V_145 ) ;
unsigned char V_583 = V_564 -> V_583 ;
int V_240 = - V_617 ;
if ( ( V_583 & V_584 ) &&
! F_31 ( V_297 , & V_48 -> V_172 ) )
goto V_110;
V_240 = F_317 ( V_48 , V_564 ) ;
if ( V_240 != 0 )
goto V_110;
V_564 -> V_583 |= V_618 ;
V_240 = F_319 ( V_564 -> V_597 , V_564 ) ;
if ( V_240 < 0 )
goto V_110;
F_330 ( & V_150 -> V_596 ) ;
if ( F_31 ( V_213 , & V_48 -> V_172 ) ) {
V_564 -> V_583 = V_583 & ~ V_619 ;
V_240 = F_319 ( V_564 -> V_597 , V_564 ) ;
goto V_620;
}
V_240 = F_339 ( V_48 , V_562 , V_564 , V_610 ) ;
if ( V_240 != 0 )
goto V_620;
V_564 -> V_583 = V_583 | V_619 ;
if ( F_319 ( V_564 -> V_597 , V_564 ) < 0 )
F_21 ( V_78 L_44 , V_9 ) ;
V_620:
F_331 ( & V_150 -> V_596 ) ;
V_110:
V_564 -> V_583 = V_583 ;
return V_240 ;
}
static int F_344 ( struct V_47 * V_48 , int V_562 , struct V_563 * V_564 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_343 ( V_48 , V_562 , V_564 ) ;
if ( V_1 == - V_579 )
V_1 = - V_120 ;
V_1 = F_16 ( F_72 ( V_48 -> V_145 ) ,
V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_345 ( struct V_582 * V_621 , int V_562 , struct V_563 * V_564 )
{
struct V_234 * V_235 ;
struct V_47 * V_48 ;
unsigned long V_37 = V_622 ;
int V_240 ;
V_235 = F_203 ( V_621 ) ;
V_48 = V_235 -> V_48 ;
if ( V_564 -> V_623 < 0 || V_564 -> V_624 < 0 )
return - V_8 ;
if ( F_346 ( V_562 ) ) {
if ( V_48 != NULL )
return F_318 ( V_48 , V_625 , V_564 ) ;
return 0 ;
}
if ( ! ( F_347 ( V_562 ) || F_340 ( V_562 ) ) )
return - V_8 ;
if ( V_564 -> V_577 == V_578 ) {
if ( V_48 != NULL )
return F_329 ( V_48 , V_562 , V_564 ) ;
return 0 ;
}
if ( V_48 == NULL )
return - V_617 ;
do {
V_240 = F_344 ( V_48 , V_562 , V_564 ) ;
if ( ( V_240 != - V_120 ) || F_347 ( V_562 ) )
break;
V_37 = F_315 ( V_37 ) ;
V_240 = - V_41 ;
if ( F_348 () )
break;
} while( V_240 < 0 );
return V_240 ;
}
int F_349 ( struct V_47 * V_48 , struct V_563 * V_566 )
{
struct V_42 * V_43 = F_72 ( V_48 -> V_145 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
V_1 = F_317 ( V_48 , V_566 ) ;
if ( V_1 != 0 )
goto V_110;
do {
V_1 = F_339 ( V_48 , V_615 , V_566 , V_610 ) ;
switch ( V_1 ) {
default:
F_21 ( V_626 L_45 ,
V_9 , V_1 ) ;
case 0 :
case - V_239 :
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
case - V_230 :
case - V_579 :
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
static void F_350 ( void * V_126 )
{
F_79 ( V_126 ) ;
}
void F_351 ( const struct V_570 * V_571 )
{
struct V_42 * V_43 = V_571 -> V_588 -> V_179 -> V_258 ;
struct V_627 * args ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_628 ] ,
} ;
if ( V_43 -> V_28 -> V_143 -> V_629 != 0 )
return;
args = F_194 ( sizeof( * args ) , V_237 ) ;
if ( ! args )
return;
args -> V_572 . V_185 = V_43 -> V_28 -> V_186 ;
args -> V_572 . V_187 = V_571 -> V_575 . V_187 ;
args -> V_572 . V_576 = V_43 -> V_576 ;
V_133 . V_249 = args ;
F_281 ( V_43 -> V_73 , & V_133 , 0 , & V_630 , args ) ;
}
static int F_352 ( struct V_13 * V_13 , const char * V_631 ,
const void * V_494 , T_10 V_495 ,
int V_172 , int type )
{
if ( strcmp ( V_631 , L_46 ) != 0 )
return - V_8 ;
return F_302 ( V_13 -> V_24 , V_494 , V_495 ) ;
}
static int F_353 ( struct V_13 * V_13 , const char * V_631 ,
void * V_494 , T_10 V_495 , int type )
{
if ( strcmp ( V_631 , L_46 ) != 0 )
return - V_8 ;
return F_296 ( V_13 -> V_24 , V_494 , V_495 ) ;
}
static T_10 F_354 ( struct V_13 * V_13 , char * V_632 ,
T_10 V_633 , const char * V_189 ,
T_10 V_634 , int type )
{
T_10 V_359 = sizeof( V_635 ) ;
if ( ! F_283 ( F_72 ( V_13 -> V_24 ) ) )
return 0 ;
if ( V_632 && V_359 <= V_633 )
memcpy ( V_632 , V_635 , V_359 ) ;
return V_359 ;
}
static void F_197 ( struct V_299 * V_300 )
{
if ( ! ( ( ( V_300 -> V_227 & V_636 ) ||
( V_300 -> V_227 & V_637 ) ) &&
( V_300 -> V_227 & V_385 ) &&
( V_300 -> V_227 & V_638 ) ) )
return;
V_300 -> V_227 |= V_382 | V_383 |
V_384 ;
V_300 -> V_201 = V_266 | V_387 | V_388 ;
V_300 -> V_389 = 2 ;
}
int F_195 ( struct V_145 * V_146 , const struct V_365 * V_189 ,
struct V_367 * V_639 , struct V_366 * V_366 )
{
struct V_42 * V_43 = F_72 ( V_146 ) ;
T_6 V_191 [ 2 ] = {
[ 0 ] = V_640 | V_641 ,
} ;
struct V_642 args = {
. V_377 = F_77 ( V_146 ) ,
. V_189 = V_189 ,
. V_366 = V_366 ,
. V_191 = V_191 ,
} ;
struct V_643 V_30 = {
. V_639 = V_639 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_644 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
int V_240 ;
F_2 ( L_47 , V_9 ) ;
if ( F_72 ( V_146 ) -> V_192 [ 1 ] & V_645 )
V_191 [ 1 ] |= V_645 ;
else
V_191 [ 0 ] |= V_23 ;
F_69 ( & V_639 -> V_300 ) ;
V_639 -> V_43 = V_43 ;
V_639 -> V_646 = 0 ;
V_240 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
F_2 ( L_48 , V_9 , V_240 ) ;
return V_240 ;
}
static int F_355 ( struct V_145 * V_146 , const struct V_365 * V_189 , struct V_647 * V_648 )
{
int V_240 ;
struct V_649 args = {
. V_377 = F_77 ( V_146 ) ,
. V_189 = V_189 ,
} ;
struct V_650 V_30 = {
. V_648 = V_648 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_651 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
F_2 ( L_49 , V_189 -> V_189 ) ;
V_240 = F_64 ( F_72 ( V_146 ) -> V_73 , F_72 ( V_146 ) , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
F_2 ( L_50 , V_240 ) ;
return V_240 ;
}
int F_356 ( struct V_145 * V_146 , const struct V_365 * V_189 , struct V_647 * V_648 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_72 ( V_146 ) ,
F_355 ( V_146 , V_189 , V_648 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_357 ( T_6 V_172 )
{
if ( V_172 & ~ V_652 )
goto V_653;
if ( ( V_172 & V_654 ) &&
( V_172 & V_655 ) )
goto V_653;
if ( ! ( V_172 & ( V_656 ) ) )
goto V_653;
return V_109 ;
V_653:
return - V_657 ;
}
int F_358 ( struct V_28 * V_29 , struct V_251 * V_292 )
{
T_12 V_12 ;
struct V_658 args = {
. V_73 = V_29 ,
. V_172 = V_659 ,
} ;
struct V_660 V_30 = {
. V_73 = V_29 ,
} ;
int V_240 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_661 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
. V_251 = V_292 ,
} ;
T_2 * V_17 ;
F_2 ( L_17 , V_9 ) ;
F_4 ( V_29 == NULL ) ;
V_17 = ( T_6 * ) V_12 . V_128 ;
* V_17 ++ = F_6 ( ( T_6 ) V_29 -> V_534 . V_535 ) ;
* V_17 = F_6 ( ( T_6 ) V_29 -> V_534 . V_536 ) ;
args . V_12 = & V_12 ;
args . V_662 = F_306 ( args . V_187 , sizeof( args . V_187 ) ,
L_51 ,
V_29 -> V_539 ,
F_359 () -> V_663 ,
F_359 () -> V_664 ,
V_29 -> V_488 -> V_542 -> V_665 ) ;
V_240 = F_63 ( V_29 -> V_488 , & V_133 , V_551 ) ;
if ( ! V_240 )
V_240 = F_357 ( V_29 -> V_666 ) ;
F_2 ( L_52 , V_9 , V_240 ) ;
return V_240 ;
}
static void F_360 ( struct V_96 * V_97 ,
void * V_126 )
{
int V_49 ;
struct V_667 * V_128 =
(struct V_667 * ) V_126 ;
F_2 ( L_17 , V_9 ) ;
F_33 ( V_97 , V_102 ) ;
V_49 = F_46 ( V_128 -> V_29 -> V_66 ,
& V_128 -> args -> V_668 ,
& V_128 -> V_30 -> V_669 , 0 , V_97 ) ;
F_4 ( V_49 == - V_120 ) ;
F_53 ( V_97 ) ;
F_2 ( L_53 , V_9 ) ;
}
static void F_361 ( struct V_96 * V_97 , void * V_126 )
{
struct V_667 * V_128 =
(struct V_667 * ) V_126 ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_37 ( V_97 , & V_128 -> V_30 -> V_669 ) )
return;
switch ( V_97 -> V_142 ) {
case - V_71 :
case - V_70 :
F_2 ( L_54 , V_9 , V_97 -> V_142 ) ;
F_40 ( V_97 , V_38 ) ;
V_97 -> V_142 = 0 ;
case - V_74 :
F_259 ( V_97 , V_128 -> V_29 ) ;
return;
}
F_2 ( L_53 , V_9 ) ;
}
int F_362 ( struct V_28 * V_29 , struct V_349 * V_459 )
{
struct V_96 * V_97 ;
struct V_670 args ;
struct V_671 V_30 = {
. V_672 = V_459 ,
} ;
struct V_667 V_128 = {
. args = & args ,
. V_30 = & V_30 ,
. V_29 = V_29 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_673 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
struct V_135 V_136 = {
. V_137 = V_29 -> V_488 ,
. V_132 = & V_133 ,
. V_138 = & V_674 ,
. V_140 = & V_128 ,
. V_172 = V_551 ,
} ;
int V_240 ;
F_2 ( L_17 , V_9 ) ;
V_97 = F_57 ( & V_136 ) ;
if ( F_58 ( V_97 ) )
V_240 = F_59 ( V_97 ) ;
else {
V_240 = V_97 -> V_142 ;
F_60 ( V_97 ) ;
}
F_2 ( L_55 , V_9 , V_240 ) ;
return V_240 ;
}
static int F_363 ( struct V_83 * V_84 , T_6 V_675 ,
int V_676 )
{
struct V_85 * V_677 = NULL ;
int V_358 ;
int V_49 = 0 ;
F_2 ( L_56 , V_9 ,
V_675 , V_84 -> V_93 ) ;
if ( V_675 != V_84 -> V_93 ) {
V_49 = - V_230 ;
V_677 = F_194 ( V_675 * sizeof( struct V_85 ) ,
V_237 ) ;
if ( ! V_677 )
goto V_110;
V_49 = 0 ;
F_79 ( V_84 -> V_88 ) ;
}
F_23 ( & V_84 -> V_107 ) ;
if ( V_677 ) {
V_84 -> V_88 = V_677 ;
V_84 -> V_93 = V_675 ;
}
for ( V_358 = 0 ; V_358 < V_84 -> V_93 ; ++ V_358 )
V_84 -> V_88 [ V_358 ] . V_111 = V_676 ;
F_25 ( & V_84 -> V_107 ) ;
F_2 ( L_57 , V_9 ,
V_84 , V_84 -> V_88 , V_84 -> V_93 ) ;
V_110:
F_2 ( L_58 , V_9 , V_49 ) ;
return V_49 ;
}
static int F_364 ( struct V_94 * V_116 )
{
int V_240 ;
V_240 = F_363 ( & V_116 -> V_100 ,
V_116 -> V_678 . V_675 , 1 ) ;
if ( V_240 )
return V_240 ;
V_240 = F_363 ( & V_116 -> V_103 ,
V_116 -> V_679 . V_675 , 0 ) ;
return V_240 ;
}
static void F_365 ( struct V_94 * V_116 )
{
if ( V_116 -> V_100 . V_88 != NULL ) {
F_79 ( V_116 -> V_100 . V_88 ) ;
V_116 -> V_100 . V_88 = NULL ;
}
if ( V_116 -> V_103 . V_88 != NULL ) {
F_79 ( V_116 -> V_103 . V_88 ) ;
V_116 -> V_103 . V_88 = NULL ;
}
return;
}
static int F_366 ( struct V_83 * V_84 ,
int V_93 , int V_676 )
{
struct V_85 * V_119 ;
int V_49 = - V_230 ;
F_4 ( V_93 > V_90 ) ;
F_2 ( L_59 , V_9 , V_93 ) ;
V_119 = F_367 ( V_93 , sizeof( struct V_85 ) , V_237 ) ;
if ( ! V_119 )
goto V_110;
V_49 = 0 ;
F_23 ( & V_84 -> V_107 ) ;
V_84 -> V_93 = V_93 ;
V_84 -> V_88 = V_119 ;
V_84 -> V_92 = - 1 ;
F_25 ( & V_84 -> V_107 ) ;
F_2 ( L_57 , V_9 ,
V_84 , V_84 -> V_88 , V_84 -> V_93 ) ;
V_110:
F_2 ( L_58 , V_9 , V_49 ) ;
return V_49 ;
}
static int F_368 ( struct V_94 * V_116 )
{
struct V_83 * V_84 ;
int V_240 = 0 ;
V_84 = & V_116 -> V_100 ;
if ( V_84 -> V_88 == NULL ) {
V_240 = F_366 ( V_84 ,
V_116 -> V_678 . V_675 , 1 ) ;
if ( V_240 )
return V_240 ;
}
V_84 = & V_116 -> V_103 ;
if ( V_84 -> V_88 == NULL ) {
V_240 = F_366 ( V_84 ,
V_116 -> V_679 . V_675 , 0 ) ;
if ( V_240 )
F_365 ( V_116 ) ;
}
return V_240 ;
}
struct V_94 * F_369 ( struct V_28 * V_29 )
{
struct V_94 * V_116 ;
struct V_83 * V_84 ;
V_116 = F_73 ( sizeof( struct V_94 ) , V_237 ) ;
if ( ! V_116 )
return NULL ;
V_84 = & V_116 -> V_100 ;
V_84 -> V_92 = - 1 ;
F_370 ( & V_84 -> V_107 ) ;
F_371 ( & V_84 -> V_101 , L_60 ) ;
F_372 ( & V_84 -> F_34 ) ;
V_84 = & V_116 -> V_103 ;
V_84 -> V_92 = - 1 ;
F_370 ( & V_84 -> V_107 ) ;
F_373 ( & V_84 -> V_101 , L_61 ) ;
F_372 ( & V_84 -> F_34 ) ;
V_116 -> V_99 = 1 << V_680 ;
V_116 -> V_29 = V_29 ;
return V_116 ;
}
void F_374 ( struct V_94 * V_116 )
{
F_375 ( V_116 ) ;
F_2 ( L_62 ,
V_9 , V_116 -> V_29 -> V_488 -> V_681 ) ;
F_376 ( V_116 -> V_29 -> V_488 -> V_681 ,
V_682 ) ;
F_365 ( V_116 ) ;
F_79 ( V_116 ) ;
}
static void F_377 ( struct V_683 * args )
{
struct V_94 * V_116 = args -> V_73 -> V_66 ;
unsigned int V_684 = V_116 -> V_678 . V_685 ,
V_686 = V_116 -> V_678 . V_687 ;
if ( V_684 == 0 )
V_684 = V_688 ;
if ( V_686 == 0 )
V_686 = V_688 ;
args -> V_678 . V_685 = V_684 ;
args -> V_678 . V_687 = V_686 ;
args -> V_678 . V_689 = V_690 ;
args -> V_678 . V_675 = V_116 -> V_29 -> V_488 -> V_681 -> V_675 ;
F_2 ( L_63
L_64 ,
V_9 ,
args -> V_678 . V_685 , args -> V_678 . V_687 ,
args -> V_678 . V_689 , args -> V_678 . V_675 ) ;
args -> V_679 . V_685 = V_508 ;
args -> V_679 . V_687 = V_508 ;
args -> V_679 . V_691 = 0 ;
args -> V_679 . V_689 = V_692 ;
args -> V_679 . V_675 = 1 ;
F_2 ( L_65
L_66 ,
V_9 ,
args -> V_679 . V_685 , args -> V_679 . V_687 ,
args -> V_679 . V_691 , args -> V_679 . V_689 ,
args -> V_679 . V_675 ) ;
}
static int F_378 ( struct V_683 * args , struct V_94 * V_116 )
{
struct V_693 * V_694 = & args -> V_678 ;
struct V_693 * V_695 = & V_116 -> V_678 ;
if ( V_695 -> V_687 > V_694 -> V_687 )
return - V_8 ;
if ( V_695 -> V_689 < V_694 -> V_689 )
return - V_8 ;
if ( V_695 -> V_675 == 0 )
return - V_8 ;
return 0 ;
}
static int F_379 ( struct V_683 * args , struct V_94 * V_116 )
{
struct V_693 * V_694 = & args -> V_679 ;
struct V_693 * V_695 = & V_116 -> V_679 ;
if ( V_695 -> V_685 > V_694 -> V_685 )
return - V_8 ;
if ( V_695 -> V_687 < V_694 -> V_687 )
return - V_8 ;
if ( V_695 -> V_691 > V_694 -> V_691 )
return - V_8 ;
if ( V_695 -> V_689 == 0 )
return - V_8 ;
if ( V_695 -> V_675 == 0 )
return - V_8 ;
return 0 ;
}
static int F_380 ( struct V_683 * args ,
struct V_94 * V_116 )
{
int V_49 ;
V_49 = F_378 ( args , V_116 ) ;
if ( V_49 )
return V_49 ;
return F_379 ( args , V_116 ) ;
}
static int F_381 ( struct V_28 * V_29 )
{
struct V_94 * V_116 = V_29 -> V_66 ;
struct V_683 args = {
. V_73 = V_29 ,
. V_696 = V_697 ,
} ;
struct V_698 V_30 = {
. V_73 = V_29 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_699 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
int V_240 ;
F_377 ( & args ) ;
args . V_172 = ( V_700 | V_701 ) ;
V_240 = F_63 ( V_116 -> V_29 -> V_488 , & V_133 , V_551 ) ;
if ( ! V_240 )
V_240 = F_380 ( & args , V_116 ) ;
if ( ! V_240 ) {
V_29 -> V_702 ++ ;
}
return V_240 ;
}
int F_382 ( struct V_28 * V_29 )
{
int V_240 ;
unsigned * V_703 ;
struct V_94 * V_116 = V_29 -> V_66 ;
F_2 ( L_67 , V_9 , V_29 , V_116 ) ;
V_240 = F_381 ( V_29 ) ;
if ( V_240 )
goto V_110;
V_240 = F_368 ( V_116 ) ;
F_2 ( L_68 , V_240 ) ;
if ( V_240 )
goto V_110;
V_240 = F_364 ( V_116 ) ;
F_2 ( L_69 , V_240 ) ;
if ( V_240 )
goto V_110;
V_703 = ( unsigned * ) & V_116 -> V_704 . V_128 [ 0 ] ;
F_2 ( L_70 , V_9 ,
V_29 -> V_702 , V_703 [ 0 ] , V_703 [ 1 ] , V_703 [ 2 ] , V_703 [ 3 ] ) ;
V_110:
F_2 ( L_53 , V_9 ) ;
return V_240 ;
}
int F_375 ( struct V_94 * V_116 )
{
int V_240 = 0 ;
struct V_132 V_133 ;
F_2 ( L_71 ) ;
if ( V_116 -> V_29 -> V_705 != V_706 )
return V_240 ;
V_133 . V_246 = & V_247 [ V_707 ] ;
V_133 . V_249 = V_116 ;
V_133 . V_250 = NULL ;
V_133 . V_251 = NULL ;
V_240 = F_63 ( V_116 -> V_29 -> V_488 , & V_133 , V_551 ) ;
if ( V_240 )
F_21 ( V_78
L_72
L_73 , V_240 ) ;
F_2 ( L_74 ) ;
return V_240 ;
}
int F_383 ( struct V_42 * V_43 )
{
struct V_28 * V_29 = V_43 -> V_28 ;
struct V_94 * V_116 ;
unsigned int V_708 , V_709 ;
int V_49 ;
if ( ! F_384 ( V_29 ) )
return 0 ;
V_116 = V_29 -> V_66 ;
if ( ! F_385 ( V_680 , & V_116 -> V_99 ) )
return 0 ;
V_708 = V_43 -> V_708 ;
if ( V_708 == 0 )
V_708 = V_688 ;
V_709 = V_43 -> V_709 ;
if ( V_709 == 0 )
V_709 = V_688 ;
V_116 -> V_678 . V_685 = V_709 + V_710 ;
V_116 -> V_678 . V_687 = V_708 + V_711 ;
V_49 = F_152 ( V_43 ) ;
if ( ! V_49 )
V_49 = F_386 ( V_29 ) ;
return V_49 ;
}
int F_387 ( struct V_28 * V_29 )
{
struct V_94 * V_116 = V_29 -> V_66 ;
int V_49 ;
if ( ! F_385 ( V_680 , & V_116 -> V_99 ) )
return 0 ;
V_49 = F_150 ( V_29 ) ;
if ( ! V_49 )
if ( ! F_388 ( V_29 ) )
V_49 = - V_712 ;
if ( ! V_49 )
V_49 = F_386 ( V_29 ) ;
return V_49 ;
}
static void F_389 ( void * V_128 )
{
struct V_713 * V_126 = V_128 ;
struct V_28 * V_29 = V_126 -> V_29 ;
if ( F_275 ( & V_29 -> V_484 ) > 1 )
F_276 ( V_29 ) ;
F_277 ( V_29 ) ;
F_79 ( V_126 ) ;
}
static int F_390 ( struct V_96 * V_97 , struct V_28 * V_29 )
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
static void F_391 ( struct V_96 * V_97 , void * V_128 )
{
struct V_713 * V_126 = V_128 ;
struct V_28 * V_29 = V_126 -> V_29 ;
if ( ! F_37 ( V_97 , V_97 -> V_259 . V_250 ) )
return;
if ( V_97 -> V_142 < 0 ) {
F_2 ( L_75 , V_9 , V_97 -> V_142 ) ;
if ( F_275 ( & V_29 -> V_484 ) == 1 )
goto V_110;
if ( F_390 ( V_97 , V_29 ) == - V_120 ) {
F_172 ( V_97 ) ;
return;
}
}
F_2 ( L_76 , V_9 , V_97 -> V_259 . V_251 ) ;
V_110:
F_2 ( L_53 , V_9 ) ;
}
static void F_392 ( struct V_96 * V_97 , void * V_128 )
{
struct V_713 * V_126 = V_128 ;
struct V_28 * V_29 = V_126 -> V_29 ;
struct V_117 * args ;
struct V_104 * V_30 ;
args = V_97 -> V_259 . V_249 ;
V_30 = V_97 -> V_259 . V_250 ;
if ( F_46 ( V_29 -> V_66 , args , V_30 , 0 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
static struct V_96 * F_393 ( struct V_28 * V_29 , struct V_251 * V_292 )
{
struct V_713 * V_126 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_714 ] ,
. V_251 = V_292 ,
} ;
struct V_135 V_252 = {
. V_137 = V_29 -> V_488 ,
. V_132 = & V_133 ,
. V_138 = & V_715 ,
. V_172 = V_256 | V_489 ,
} ;
if ( ! F_280 ( & V_29 -> V_484 ) )
return F_110 ( - V_10 ) ;
V_126 = F_73 ( sizeof( * V_126 ) , V_237 ) ;
if ( V_126 == NULL ) {
F_277 ( V_29 ) ;
return F_110 ( - V_230 ) ;
}
V_133 . V_249 = & V_126 -> args ;
V_133 . V_250 = & V_126 -> V_30 ;
V_126 -> V_29 = V_29 ;
V_252 . V_140 = V_126 ;
return F_57 ( & V_252 ) ;
}
static int F_394 ( struct V_28 * V_29 , struct V_251 * V_292 )
{
struct V_96 * V_97 ;
int V_49 = 0 ;
V_97 = F_393 ( V_29 , V_292 ) ;
if ( F_58 ( V_97 ) )
V_49 = F_59 ( V_97 ) ;
else
F_337 ( V_97 ) ;
F_2 ( L_23 , V_9 , V_49 ) ;
return V_49 ;
}
static int F_395 ( struct V_28 * V_29 , struct V_251 * V_292 )
{
struct V_96 * V_97 ;
int V_49 ;
V_97 = F_393 ( V_29 , V_292 ) ;
if ( F_58 ( V_97 ) ) {
V_49 = F_59 ( V_97 ) ;
goto V_110;
}
V_49 = F_90 ( V_97 ) ;
if ( ! V_49 ) {
struct V_104 * V_30 = V_97 -> V_259 . V_250 ;
if ( V_97 -> V_142 == 0 )
F_396 ( V_29 , V_30 -> V_113 ) ;
V_49 = V_97 -> V_142 ;
}
F_60 ( V_97 ) ;
V_110:
F_2 ( L_23 , V_9 , V_49 ) ;
return V_49 ;
}
static void F_397 ( struct V_96 * V_97 , void * V_128 )
{
struct V_716 * V_126 = V_128 ;
F_33 ( V_97 , V_102 ) ;
if ( F_46 ( V_126 -> V_29 -> V_66 ,
& V_126 -> V_302 . V_130 ,
& V_126 -> V_30 . V_131 , 0 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
static int F_398 ( struct V_96 * V_97 , struct V_28 * V_29 )
{
switch( V_97 -> V_142 ) {
case 0 :
case - V_717 :
case - V_718 :
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
static void F_399 ( struct V_96 * V_97 , void * V_128 )
{
struct V_716 * V_126 = V_128 ;
struct V_28 * V_29 = V_126 -> V_29 ;
struct V_104 * V_30 = & V_126 -> V_30 . V_131 ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_37 ( V_97 , V_30 ) )
return;
if ( F_398 ( V_97 , V_29 ) == - V_120 ) {
F_172 ( V_97 ) ;
return;
}
F_2 ( L_53 , V_9 ) ;
}
static void F_400 ( void * V_128 )
{
struct V_716 * V_126 = V_128 ;
F_79 ( V_126 ) ;
}
static int F_401 ( struct V_28 * V_29 )
{
struct V_716 * V_126 ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_719 ] ,
} ;
struct V_135 V_252 = {
. V_137 = V_29 -> V_488 ,
. V_132 = & V_133 ,
. V_138 = & V_720 ,
. V_172 = V_256 ,
} ;
int V_240 = - V_230 ;
F_2 ( L_17 , V_9 ) ;
V_126 = F_73 ( sizeof( * V_126 ) , V_237 ) ;
if ( V_126 == NULL )
goto V_110;
V_126 -> V_29 = V_29 ;
V_126 -> V_302 . V_721 = 0 ;
V_133 . V_249 = & V_126 -> V_302 ;
V_133 . V_250 = & V_126 -> V_30 ;
V_252 . V_140 = V_126 ;
V_97 = F_57 ( & V_252 ) ;
if ( F_58 ( V_97 ) ) {
V_240 = F_59 ( V_97 ) ;
goto V_110;
}
V_240 = F_89 ( V_97 ) ;
if ( V_240 == 0 )
V_240 = V_97 -> V_142 ;
F_60 ( V_97 ) ;
return 0 ;
V_110:
F_2 ( L_23 , V_9 , V_240 ) ;
return V_240 ;
}
static void
F_402 ( struct V_96 * V_97 , void * V_126 )
{
struct V_722 * V_723 = V_126 ;
struct V_42 * V_43 = F_72 ( V_723 -> args . V_145 ) ;
F_2 ( L_17 , V_9 ) ;
if ( F_50 ( V_43 , & V_723 -> args . V_130 ,
& V_723 -> V_30 . V_131 , 0 , V_97 ) )
return;
if ( F_403 ( & V_723 -> args . V_199 ,
F_66 ( V_723 -> args . V_145 ) -> V_724 ,
V_723 -> args . V_235 -> V_48 ) ) {
F_404 ( V_97 , V_725 ) ;
return;
}
F_53 ( V_97 ) ;
}
static void F_405 ( struct V_96 * V_97 , void * V_126 )
{
struct V_722 * V_723 = V_126 ;
struct V_42 * V_43 = F_72 ( V_723 -> args . V_145 ) ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_41 ( V_97 , & V_723 -> V_30 . V_131 ) )
return;
switch ( V_97 -> V_142 ) {
case 0 :
break;
case - V_726 :
case - V_727 :
V_97 -> V_142 = - V_71 ;
default:
if ( F_171 ( V_97 , V_43 , NULL ) == - V_120 ) {
F_172 ( V_97 ) ;
return;
}
}
F_2 ( L_53 , V_9 ) ;
}
static void F_406 ( void * V_126 )
{
struct V_722 * V_723 = V_126 ;
F_2 ( L_17 , V_9 ) ;
F_130 ( V_723 -> args . V_235 ) ;
F_79 ( V_126 ) ;
F_2 ( L_53 , V_9 ) ;
}
int F_407 ( struct V_722 * V_723 )
{
struct V_42 * V_43 = F_72 ( V_723 -> args . V_145 ) ;
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_728 ] ,
. V_249 = & V_723 -> args ,
. V_250 = & V_723 -> V_30 ,
} ;
struct V_135 V_252 = {
. V_137 = V_43 -> V_73 ,
. V_132 = & V_133 ,
. V_138 = & V_729 ,
. V_140 = V_723 ,
. V_172 = V_256 ,
} ;
int V_240 = 0 ;
F_2 ( L_17 , V_9 ) ;
V_723 -> V_30 . V_730 = & V_723 -> args . V_724 ;
V_723 -> V_30 . V_131 . V_106 = NULL ;
V_97 = F_57 ( & V_252 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
V_240 = F_89 ( V_97 ) ;
if ( V_240 == 0 )
V_240 = V_97 -> V_142 ;
if ( V_240 == 0 )
V_240 = F_408 ( V_723 ) ;
F_60 ( V_97 ) ;
F_2 ( L_23 , V_9 , V_240 ) ;
return V_240 ;
}
static void
F_409 ( struct V_96 * V_97 , void * V_126 )
{
struct V_731 * V_732 = V_126 ;
F_2 ( L_17 , V_9 ) ;
if ( F_46 ( V_732 -> V_29 -> V_66 , & V_732 -> args . V_130 ,
& V_732 -> V_30 . V_131 , 0 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
static void F_410 ( struct V_96 * V_97 , void * V_126 )
{
struct V_731 * V_732 = V_126 ;
struct V_42 * V_43 ;
struct V_733 * V_734 = F_66 ( V_732 -> args . V_145 ) -> V_724 ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_41 ( V_97 , & V_732 -> V_30 . V_131 ) )
return;
V_43 = F_72 ( V_732 -> args . V_145 ) ;
if ( F_171 ( V_97 , V_43 , NULL ) == - V_120 ) {
F_259 ( V_97 , V_732 -> V_29 ) ;
return;
}
F_23 ( & V_734 -> V_735 -> V_151 ) ;
if ( V_97 -> V_142 == 0 ) {
if ( V_732 -> V_30 . V_736 ) {
F_411 ( V_734 , & V_732 -> V_30 . V_199 , true ) ;
} else
F_4 ( ! F_412 ( & V_734 -> V_737 ) ) ;
}
V_734 -> V_738 -- ;
F_25 ( & V_734 -> V_735 -> V_151 ) ;
F_2 ( L_53 , V_9 ) ;
}
static void F_413 ( void * V_126 )
{
struct V_731 * V_732 = V_126 ;
F_2 ( L_17 , V_9 ) ;
F_414 ( F_66 ( V_732 -> args . V_145 ) -> V_724 ) ;
F_79 ( V_126 ) ;
F_2 ( L_53 , V_9 ) ;
}
int F_415 ( struct V_731 * V_732 )
{
struct V_96 * V_97 ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_739 ] ,
. V_249 = & V_732 -> args ,
. V_250 = & V_732 -> V_30 ,
} ;
struct V_135 V_252 = {
. V_137 = V_732 -> V_29 -> V_488 ,
. V_132 = & V_133 ,
. V_138 = & V_740 ,
. V_140 = V_732 ,
} ;
int V_240 ;
F_2 ( L_17 , V_9 ) ;
V_97 = F_57 ( & V_252 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
V_240 = V_97 -> V_142 ;
F_2 ( L_23 , V_9 , V_240 ) ;
F_60 ( V_97 ) ;
return V_240 ;
}
static int
F_416 ( struct V_42 * V_43 , struct V_741 * V_742 )
{
struct V_743 args = {
. V_742 = V_742 ,
} ;
struct V_744 V_30 = {
. V_742 = V_742 ,
} ;
struct V_132 V_133 = {
. V_246 = & V_247 [ V_745 ] ,
. V_249 = & args ,
. V_250 = & V_30 ,
} ;
int V_240 ;
F_2 ( L_17 , V_9 ) ;
V_240 = F_64 ( V_43 -> V_73 , V_43 , & V_133 , & args . V_130 , & V_30 . V_131 , 0 ) ;
F_2 ( L_23 , V_9 , V_240 ) ;
return V_240 ;
}
int F_417 ( struct V_42 * V_43 , struct V_741 * V_742 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_416 ( V_43 , V_742 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static void F_418 ( struct V_96 * V_97 , void * V_126 )
{
struct V_746 * V_128 = V_126 ;
struct V_42 * V_43 = F_72 ( V_128 -> args . V_145 ) ;
if ( F_50 ( V_43 , & V_128 -> args . V_130 ,
& V_128 -> V_30 . V_131 , 1 , V_97 ) )
return;
F_53 ( V_97 ) ;
}
static void
F_419 ( struct V_96 * V_97 , void * V_126 )
{
struct V_746 * V_128 = V_126 ;
struct V_42 * V_43 = F_72 ( V_128 -> args . V_145 ) ;
if ( ! F_41 ( V_97 , & V_128 -> V_30 . V_131 ) )
return;
switch ( V_97 -> V_142 ) {
case V_747 :
case V_748 :
case V_749 :
case V_70 :
V_97 -> V_142 = 0 ;
}
if ( F_171 ( V_97 , V_43 , NULL ) == - V_120 ) {
F_259 ( V_97 , V_43 -> V_28 ) ;
return;
}
if ( V_97 -> V_142 == 0 )
F_267 ( V_128 -> args . V_145 ,
V_128 -> V_30 . V_300 ) ;
}
static void F_420 ( void * V_126 )
{
struct V_746 * V_128 = V_126 ;
F_263 ( V_128 -> V_473 ) ;
F_421 ( V_128 -> V_292 ) ;
F_79 ( V_128 ) ;
}
int
F_422 ( struct V_746 * V_128 , bool V_750 )
{
struct V_132 V_133 = {
. V_246 = & V_247 [ V_751 ] ,
. V_249 = & V_128 -> args ,
. V_250 = & V_128 -> V_30 ,
. V_251 = V_128 -> V_292 ,
} ;
struct V_135 V_252 = {
. V_97 = & V_128 -> V_97 ,
. V_137 = F_265 ( V_128 -> args . V_145 ) ,
. V_132 = & V_133 ,
. V_138 = & V_752 ,
. V_140 = V_128 ,
. V_172 = V_256 ,
} ;
struct V_96 * V_97 ;
int V_240 = 0 ;
F_2 ( L_77
L_78 ,
V_128 -> V_97 . V_753 , V_750 ,
V_128 -> args . V_754 ,
V_128 -> args . V_145 -> V_755 ) ;
V_97 = F_57 ( & V_252 ) ;
if ( F_58 ( V_97 ) )
return F_59 ( V_97 ) ;
if ( V_750 == false )
goto V_110;
V_240 = F_89 ( V_97 ) ;
if ( V_240 != 0 )
goto V_110;
V_240 = V_97 -> V_142 ;
V_110:
F_2 ( L_79 , V_9 , V_240 ) ;
F_60 ( V_97 ) ;
return V_240 ;
}
