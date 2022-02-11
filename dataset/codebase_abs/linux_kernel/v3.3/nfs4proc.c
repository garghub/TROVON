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
F_27 ( struct V_83 * V_84 , T_3 V_85 )
{
int V_86 = V_85 ;
F_4 ( V_86 < 0 || V_86 >= V_87 ) ;
F_28 ( V_86 , V_84 -> V_88 ) ;
if ( V_86 == V_84 -> V_89 ) {
V_86 = F_29 ( V_84 -> V_88 , V_84 -> V_90 ) ;
if ( V_86 < V_84 -> V_90 )
V_84 -> V_89 = V_86 ;
else
V_84 -> V_89 = - 1 ;
}
F_2 ( L_9 , V_9 ,
V_85 , V_84 -> V_89 ) ;
}
static void F_30 ( struct V_91 * V_92 )
{
struct V_93 * V_94 ;
if ( ! F_31 ( V_95 , & V_92 -> V_96 ) ) {
V_94 = F_32 ( & V_92 -> V_97 . V_98 ) ;
if ( V_94 )
F_33 ( V_94 , V_99 ) ;
return;
}
if ( V_92 -> V_97 . V_89 != - 1 )
return;
F_2 ( L_10 , V_9 ) ;
F_34 ( & V_92 -> V_97 . F_34 ) ;
}
void F_35 ( struct V_91 * V_92 )
{
if ( ! F_31 ( V_95 , & V_92 -> V_96 ) ||
V_92 -> V_100 . V_89 != - 1 )
return;
F_2 ( L_11 , V_9 ) ;
F_34 ( & V_92 -> V_100 . F_34 ) ;
}
static void F_36 ( struct V_101 * V_30 )
{
struct V_83 * V_84 ;
V_84 = & V_30 -> V_102 -> V_97 ;
if ( ! V_30 -> V_103 ) {
F_2 ( L_12 , V_9 ) ;
return;
}
F_23 ( & V_84 -> V_104 ) ;
F_27 ( V_84 , V_30 -> V_103 - V_84 -> V_105 ) ;
F_30 ( V_30 -> V_102 ) ;
F_25 ( & V_84 -> V_104 ) ;
V_30 -> V_103 = NULL ;
}
static int F_37 ( struct V_93 * V_94 , struct V_101 * V_30 )
{
unsigned long V_80 ;
struct V_28 * V_29 ;
if ( V_30 -> V_106 == 1 )
V_30 -> V_106 = V_107 ;
if ( ! F_38 ( V_94 ) )
goto V_108;
switch ( V_30 -> V_106 ) {
case 0 :
++ V_30 -> V_103 -> V_109 ;
V_80 = V_30 -> V_110 ;
V_29 = V_30 -> V_102 -> V_29 ;
F_22 ( V_29 , V_80 ) ;
if ( V_30 -> V_111 != 0 )
F_18 ( V_29 ) ;
break;
case - V_71 :
F_2 ( L_13 ,
V_9 ,
V_30 -> V_103 - V_30 -> V_102 -> V_97 . V_105 ,
V_30 -> V_103 -> V_109 ) ;
goto V_112;
default:
++ V_30 -> V_103 -> V_109 ;
}
V_108:
F_2 ( L_14 , V_9 , V_30 -> V_106 ) ;
F_36 ( V_30 ) ;
return 1 ;
V_112:
if ( ! F_39 ( V_94 ) )
goto V_108;
F_40 ( V_94 , V_39 ) ;
return 0 ;
}
static int F_41 ( struct V_93 * V_94 ,
struct V_101 * V_30 )
{
if ( V_30 -> V_102 == NULL )
return 1 ;
return F_37 ( V_94 , V_30 ) ;
}
static T_3
F_42 ( struct V_83 * V_84 )
{
int V_86 ;
T_3 V_113 = V_87 ;
F_43 ( ( T_3 ) V_87 != ( int ) V_87 ) ;
F_2 ( L_15 ,
V_9 , V_84 -> V_88 [ 0 ] , V_84 -> V_89 ,
V_84 -> V_90 ) ;
V_86 = F_44 ( V_84 -> V_88 , V_84 -> V_90 ) ;
if ( V_86 >= V_84 -> V_90 )
goto V_108;
F_45 ( V_86 , V_84 -> V_88 ) ;
if ( V_86 > V_84 -> V_89 )
V_84 -> V_89 = V_86 ;
V_113 = V_86 ;
V_108:
F_2 ( L_16 ,
V_9 , V_84 -> V_88 [ 0 ] , V_84 -> V_89 , V_113 ) ;
return V_113 ;
}
int F_46 ( struct V_91 * V_114 ,
struct V_115 * args ,
struct V_101 * V_30 ,
int V_116 ,
struct V_93 * V_94 )
{
struct V_117 * V_118 ;
struct V_83 * V_84 ;
T_3 V_86 ;
F_2 ( L_17 , V_9 ) ;
if ( V_30 -> V_103 != NULL )
return 0 ;
V_84 = & V_114 -> V_97 ;
F_23 ( & V_84 -> V_104 ) ;
if ( F_31 ( V_95 , & V_114 -> V_96 ) &&
! F_47 ( V_94 , V_99 ) ) {
F_48 ( & V_84 -> V_98 , V_94 , NULL ) ;
F_25 ( & V_84 -> V_104 ) ;
F_2 ( L_18 , V_9 ) ;
return - V_119 ;
}
if ( ! F_49 ( & V_84 -> V_98 ) &&
! F_47 ( V_94 , V_99 ) ) {
F_48 ( & V_84 -> V_98 , V_94 , NULL ) ;
F_25 ( & V_84 -> V_104 ) ;
F_2 ( L_19 , V_9 ) ;
return - V_119 ;
}
V_86 = F_42 ( V_84 ) ;
if ( V_86 == V_87 ) {
F_48 ( & V_84 -> V_98 , V_94 , NULL ) ;
F_25 ( & V_84 -> V_104 ) ;
F_2 ( L_20 , V_9 ) ;
return - V_119 ;
}
F_25 ( & V_84 -> V_104 ) ;
F_33 ( V_94 , V_120 ) ;
V_118 = V_84 -> V_105 + V_86 ;
args -> V_121 = V_114 ;
args -> V_122 = V_86 ;
args -> V_123 = V_116 ;
F_2 ( L_21 , V_9 , V_86 , V_118 -> V_109 ) ;
V_30 -> V_102 = V_114 ;
V_30 -> V_103 = V_118 ;
V_30 -> V_110 = V_124 ;
V_30 -> V_111 = 0 ;
V_30 -> V_106 = 1 ;
return 0 ;
}
int F_50 ( const struct V_42 * V_43 ,
struct V_115 * args ,
struct V_101 * V_30 ,
int V_116 ,
struct V_93 * V_94 )
{
struct V_91 * V_114 = F_51 ( V_43 ) ;
int V_49 = 0 ;
if ( V_114 == NULL ) {
args -> V_121 = NULL ;
V_30 -> V_102 = NULL ;
goto V_108;
}
F_2 ( L_22 ,
V_9 , V_114 -> V_29 , V_114 , V_30 -> V_103 ?
V_30 -> V_103 - V_114 -> V_97 . V_105 : - 1 ) ;
V_49 = F_46 ( V_114 , args , V_30 , V_116 ,
V_94 ) ;
V_108:
F_2 ( L_23 , V_9 , V_49 ) ;
return V_49 ;
}
static void F_52 ( struct V_93 * V_94 , void * V_125 )
{
struct V_126 * V_127 = V_125 ;
F_2 ( L_24 , V_9 , V_127 -> V_128 ) ;
if ( F_50 ( V_127 -> V_128 , V_127 -> V_129 ,
V_127 -> V_130 , V_127 -> V_116 , V_94 ) )
return;
F_53 ( V_94 ) ;
}
static void F_54 ( struct V_93 * V_94 , void * V_125 )
{
F_33 ( V_94 , V_99 ) ;
F_52 ( V_94 , V_125 ) ;
}
static void F_55 ( struct V_93 * V_94 , void * V_125 )
{
struct V_126 * V_127 = V_125 ;
F_37 ( V_94 , V_127 -> V_130 ) ;
}
static int F_56 ( struct V_35 * V_36 ,
struct V_42 * V_43 ,
struct V_131 * V_132 ,
struct V_115 * args ,
struct V_101 * V_30 ,
int V_116 ,
int V_133 )
{
int V_49 ;
struct V_93 * V_94 ;
struct V_126 V_127 = {
. V_128 = V_43 ,
. V_129 = args ,
. V_130 = V_30 ,
. V_116 = V_116 ,
} ;
struct V_134 V_135 = {
. V_136 = V_36 ,
. V_131 = V_132 ,
. V_137 = & V_138 ,
. V_139 = & V_127
} ;
V_30 -> V_103 = NULL ;
if ( V_133 )
V_135 . V_137 = & V_140 ;
V_94 = F_57 ( & V_135 ) ;
if ( F_58 ( V_94 ) )
V_49 = F_59 ( V_94 ) ;
else {
V_49 = V_94 -> V_141 ;
F_60 ( V_94 ) ;
}
return V_49 ;
}
int F_61 ( struct V_35 * V_36 ,
struct V_42 * V_43 ,
struct V_131 * V_132 ,
struct V_115 * args ,
struct V_101 * V_30 ,
int V_116 )
{
return F_56 ( V_36 , V_43 , V_132 , args , V_30 , V_116 , 0 ) ;
}
static int F_41 ( struct V_93 * V_94 ,
struct V_101 * V_30 )
{
return 1 ;
}
int F_62 ( struct V_35 * V_36 ,
struct V_42 * V_43 ,
struct V_131 * V_132 ,
struct V_115 * args ,
struct V_101 * V_30 ,
int V_116 )
{
args -> V_121 = V_30 -> V_102 = NULL ;
return F_63 ( V_36 , V_132 , 0 ) ;
}
static inline
int F_64 ( struct V_35 * V_36 ,
struct V_42 * V_43 ,
struct V_131 * V_132 ,
struct V_115 * args ,
struct V_101 * V_30 ,
int V_116 )
{
return V_43 -> V_28 -> V_142 -> V_143 ( V_36 , V_43 , V_132 ,
args , V_30 , V_116 ) ;
}
static void F_65 ( struct V_144 * V_145 , struct V_146 * V_147 )
{
struct V_148 * V_149 = F_66 ( V_145 ) ;
F_23 ( & V_145 -> V_150 ) ;
V_149 -> V_151 |= V_152 | V_153 | V_154 ;
if ( ! V_147 -> V_155 || V_147 -> V_156 != V_145 -> V_157 )
F_67 ( V_145 ) ;
V_145 -> V_157 = V_147 -> V_158 ;
F_25 ( & V_145 -> V_150 ) ;
}
static void F_68 ( struct V_159 * V_17 )
{
V_17 -> V_160 . V_161 = & V_17 -> V_161 ;
V_17 -> V_160 . V_162 = & V_17 -> V_162 ;
V_17 -> V_160 . V_163 = V_17 -> V_164 . V_163 ;
V_17 -> V_165 . V_163 = V_17 -> V_166 . V_163 ;
V_17 -> V_160 . V_43 = V_17 -> V_164 . V_43 ;
F_69 ( & V_17 -> V_161 ) ;
F_69 ( & V_17 -> V_162 ) ;
F_70 ( & V_17 -> V_161 , & V_17 -> V_167 , & V_17 -> V_168 ) ;
}
static struct V_159 * F_71 ( struct V_13 * V_13 ,
struct V_169 * V_170 , T_4 V_171 , int V_172 ,
const struct V_173 * V_174 ,
T_5 V_175 )
{
struct V_13 * V_176 = F_72 ( V_13 ) ;
struct V_144 * V_145 = V_176 -> V_24 ;
struct V_42 * V_43 = F_73 ( V_145 ) ;
struct V_159 * V_17 ;
V_17 = F_74 ( sizeof( * V_17 ) , V_175 ) ;
if ( V_17 == NULL )
goto V_1;
V_17 -> V_164 . V_163 = F_75 ( & V_170 -> V_177 , V_175 ) ;
if ( V_17 -> V_164 . V_163 == NULL )
goto V_178;
F_76 ( V_13 -> V_179 ) ;
V_17 -> V_13 = F_77 ( V_13 ) ;
V_17 -> V_145 = V_176 ;
V_17 -> V_180 = V_170 ;
F_78 ( & V_170 -> V_181 ) ;
V_17 -> V_164 . V_182 = F_79 ( V_145 ) ;
V_17 -> V_164 . V_183 = V_172 ;
V_17 -> V_164 . V_171 = V_171 & ( V_184 | V_185 ) ;
V_17 -> V_164 . V_186 = V_43 -> V_28 -> V_187 ;
V_17 -> V_164 . V_188 = V_170 -> V_189 . V_188 ;
V_17 -> V_164 . V_190 = & V_13 -> V_191 ;
V_17 -> V_164 . V_43 = V_43 ;
V_17 -> V_164 . V_192 = V_43 -> V_193 ;
V_17 -> V_164 . V_194 = V_43 -> V_195 ;
V_17 -> V_164 . V_196 = V_197 ;
if ( V_172 & V_198 ) {
T_6 * V_199 ;
V_17 -> V_164 . V_200 . V_174 = & V_17 -> V_174 ;
memcpy ( & V_17 -> V_174 , V_174 , sizeof( V_17 -> V_174 ) ) ;
V_199 = ( T_6 * ) V_17 -> V_164 . V_200 . V_12 . V_127 ;
V_199 [ 0 ] = V_124 ;
V_199 [ 1 ] = V_40 -> V_201 ;
}
V_17 -> V_166 . V_182 = & V_17 -> V_160 . V_182 ;
V_17 -> V_166 . V_202 = & V_17 -> V_160 . V_202 ;
V_17 -> V_166 . V_163 = V_17 -> V_164 . V_163 ;
F_68 ( V_17 ) ;
F_80 ( & V_17 -> V_203 ) ;
return V_17 ;
V_178:
F_81 ( V_17 ) ;
V_1:
F_82 ( V_176 ) ;
return NULL ;
}
static void F_83 ( struct V_203 * V_203 )
{
struct V_159 * V_17 = F_84 ( V_203 ,
struct V_159 , V_203 ) ;
struct V_204 * V_205 = V_17 -> V_13 -> V_179 ;
F_85 ( V_17 -> V_164 . V_163 ) ;
if ( V_17 -> V_48 != NULL )
F_86 ( V_17 -> V_48 ) ;
F_87 ( V_17 -> V_180 ) ;
F_82 ( V_17 -> V_145 ) ;
F_82 ( V_17 -> V_13 ) ;
F_88 ( V_205 ) ;
F_89 ( & V_17 -> V_161 ) ;
F_81 ( V_17 ) ;
}
static void F_90 ( struct V_159 * V_17 )
{
if ( V_17 != NULL )
F_91 ( & V_17 -> V_203 , F_83 ) ;
}
static int F_92 ( struct V_93 * V_94 )
{
int V_49 ;
V_49 = F_93 ( V_94 ) ;
return V_49 ;
}
static int F_94 ( struct V_47 * V_48 , T_4 V_206 , int V_207 )
{
int V_49 = 0 ;
if ( V_207 & V_208 )
goto V_108;
switch ( V_206 & ( V_184 | V_185 ) ) {
case V_184 :
V_49 |= F_31 ( V_209 , & V_48 -> V_172 ) != 0
&& V_48 -> V_210 != 0 ;
break;
case V_185 :
V_49 |= F_31 ( V_211 , & V_48 -> V_172 ) != 0
&& V_48 -> V_212 != 0 ;
break;
case V_184 | V_185 :
V_49 |= F_31 ( V_213 , & V_48 -> V_172 ) != 0
&& V_48 -> V_214 != 0 ;
}
V_108:
return V_49 ;
}
static int F_95 ( struct V_215 * V_216 , T_4 V_171 )
{
if ( V_216 == NULL )
return 0 ;
if ( ( V_216 -> type & V_171 ) != V_171 )
return 0 ;
if ( F_31 ( V_217 , & V_216 -> V_172 ) )
return 0 ;
F_96 ( V_216 ) ;
return 1 ;
}
static void F_97 ( struct V_47 * V_48 , T_4 V_171 )
{
switch ( V_171 ) {
case V_185 :
V_48 -> V_212 ++ ;
break;
case V_184 :
V_48 -> V_210 ++ ;
break;
case V_184 | V_185 :
V_48 -> V_214 ++ ;
}
F_98 ( V_48 , V_48 -> V_48 | V_171 ) ;
}
static void F_99 ( struct V_47 * V_48 , T_7 * V_202 , T_4 V_171 )
{
if ( F_31 ( V_218 , & V_48 -> V_172 ) == 0 )
memcpy ( V_48 -> V_202 . V_127 , V_202 -> V_127 , sizeof( V_48 -> V_202 . V_127 ) ) ;
memcpy ( V_48 -> V_219 . V_127 , V_202 -> V_127 , sizeof( V_48 -> V_219 . V_127 ) ) ;
switch ( V_171 ) {
case V_184 :
F_100 ( V_209 , & V_48 -> V_172 ) ;
break;
case V_185 :
F_100 ( V_211 , & V_48 -> V_172 ) ;
break;
case V_184 | V_185 :
F_100 ( V_213 , & V_48 -> V_172 ) ;
}
}
static void F_101 ( struct V_47 * V_48 , T_7 * V_202 , T_4 V_171 )
{
F_102 ( & V_48 -> V_220 ) ;
F_99 ( V_48 , V_202 , V_171 ) ;
F_103 ( & V_48 -> V_220 ) ;
}
static void F_104 ( struct V_47 * V_48 , T_7 * V_219 , const T_7 * V_221 , T_4 V_171 )
{
F_102 ( & V_48 -> V_220 ) ;
if ( V_221 != NULL ) {
memcpy ( V_48 -> V_202 . V_127 , V_221 -> V_127 , sizeof( V_48 -> V_202 . V_127 ) ) ;
F_100 ( V_218 , & V_48 -> V_172 ) ;
}
if ( V_219 != NULL )
F_99 ( V_48 , V_219 , V_171 ) ;
F_103 ( & V_48 -> V_220 ) ;
F_23 ( & V_48 -> V_180 -> V_222 ) ;
F_97 ( V_48 , V_171 ) ;
F_25 ( & V_48 -> V_180 -> V_222 ) ;
}
static int F_105 ( struct V_47 * V_48 , T_7 * V_219 , T_7 * V_216 , T_4 V_171 )
{
struct V_148 * V_149 = F_66 ( V_48 -> V_144 ) ;
struct V_215 * V_223 ;
int V_49 = 0 ;
V_171 &= ( V_184 | V_185 ) ;
F_106 () ;
V_223 = F_107 ( V_149 -> V_216 ) ;
if ( V_223 == NULL )
goto V_224;
F_23 ( & V_223 -> V_225 ) ;
if ( V_149 -> V_216 != V_223 ||
( V_223 -> type & V_171 ) != V_171 )
goto V_226;
if ( V_216 == NULL )
V_216 = & V_223 -> V_202 ;
else if ( memcmp ( V_223 -> V_202 . V_127 , V_216 -> V_127 , V_227 ) != 0 )
goto V_226;
F_96 ( V_223 ) ;
F_104 ( V_48 , V_219 , & V_223 -> V_202 , V_171 ) ;
V_49 = 1 ;
V_226:
F_25 ( & V_223 -> V_225 ) ;
V_224:
F_108 () ;
if ( ! V_49 && V_219 != NULL ) {
F_104 ( V_48 , V_219 , NULL , V_171 ) ;
V_49 = 1 ;
}
return V_49 ;
}
static void F_109 ( struct V_144 * V_144 , T_4 V_171 )
{
struct V_215 * V_216 ;
F_106 () ;
V_216 = F_107 ( F_66 ( V_144 ) -> V_216 ) ;
if ( V_216 == NULL || ( V_216 -> type & V_171 ) == V_171 ) {
F_108 () ;
return;
}
F_108 () ;
F_110 ( V_144 ) ;
}
static struct V_47 * F_111 ( struct V_159 * V_228 )
{
struct V_47 * V_48 = V_228 -> V_48 ;
struct V_148 * V_149 = F_66 ( V_48 -> V_144 ) ;
struct V_215 * V_216 ;
int V_207 = V_228 -> V_164 . V_183 & V_208 ;
T_4 V_171 = V_228 -> V_164 . V_171 ;
T_7 V_202 ;
int V_49 = - V_119 ;
for (; ; ) {
if ( F_94 ( V_48 , V_171 , V_207 ) ) {
F_23 ( & V_48 -> V_180 -> V_222 ) ;
if ( F_94 ( V_48 , V_171 , V_207 ) ) {
F_97 ( V_48 , V_171 ) ;
F_25 ( & V_48 -> V_180 -> V_222 ) ;
goto V_229;
}
F_25 ( & V_48 -> V_180 -> V_222 ) ;
}
F_106 () ;
V_216 = F_107 ( V_149 -> V_216 ) ;
if ( ! F_95 ( V_216 , V_171 ) ) {
F_108 () ;
break;
}
memcpy ( V_202 . V_127 , V_216 -> V_202 . V_127 , sizeof( V_202 . V_127 ) ) ;
F_108 () ;
V_49 = F_112 ( V_48 -> V_144 , V_48 -> V_180 -> V_230 , V_207 ) ;
if ( V_49 != 0 )
goto V_108;
V_49 = - V_119 ;
if ( F_105 ( V_48 , NULL , & V_202 , V_171 ) )
goto V_229;
}
V_108:
return F_113 ( V_49 ) ;
V_229:
F_78 ( & V_48 -> V_18 ) ;
return V_48 ;
}
static struct V_47 * F_114 ( struct V_159 * V_127 )
{
struct V_144 * V_144 ;
struct V_47 * V_48 = NULL ;
struct V_215 * V_216 ;
int V_49 ;
if ( ! V_127 -> V_231 ) {
V_48 = F_111 ( V_127 ) ;
goto V_108;
}
V_49 = - V_119 ;
if ( ! ( V_127 -> V_161 . V_232 & V_233 ) )
goto V_1;
V_144 = F_115 ( V_127 -> V_145 -> V_179 , & V_127 -> V_160 . V_182 , & V_127 -> V_161 ) ;
V_49 = F_59 ( V_144 ) ;
if ( F_58 ( V_144 ) )
goto V_1;
V_49 = - V_234 ;
V_48 = F_116 ( V_144 , V_127 -> V_180 ) ;
if ( V_48 == NULL )
goto V_235;
if ( V_127 -> V_160 . V_236 != 0 ) {
int V_237 = 0 ;
F_106 () ;
V_216 = F_107 ( F_66 ( V_144 ) -> V_216 ) ;
if ( V_216 )
V_237 = V_216 -> V_172 ;
F_108 () ;
if ( V_127 -> V_164 . V_196 == V_238 ) {
F_117 ( L_25
L_26
L_27 ,
F_118 ( V_144 ) -> V_239 ) ;
} else if ( ( V_237 & 1UL << V_217 ) == 0 )
F_119 ( V_48 -> V_144 ,
V_127 -> V_180 -> V_230 ,
& V_127 -> V_160 ) ;
else
F_120 ( V_48 -> V_144 ,
V_127 -> V_180 -> V_230 ,
& V_127 -> V_160 ) ;
}
F_105 ( V_48 , & V_127 -> V_160 . V_202 , NULL ,
V_127 -> V_164 . V_171 ) ;
F_121 ( V_144 ) ;
V_108:
return V_48 ;
V_235:
F_121 ( V_144 ) ;
V_1:
return F_113 ( V_49 ) ;
}
static struct V_240 * F_122 ( struct V_47 * V_48 )
{
struct V_148 * V_149 = F_66 ( V_48 -> V_144 ) ;
struct V_240 * V_241 ;
F_23 ( & V_48 -> V_144 -> V_150 ) ;
F_123 (ctx, &nfsi->open_files, list) {
if ( V_241 -> V_48 != V_48 )
continue;
F_124 ( V_241 ) ;
F_25 ( & V_48 -> V_144 -> V_150 ) ;
return V_241 ;
}
F_25 ( & V_48 -> V_144 -> V_150 ) ;
return F_113 ( - V_242 ) ;
}
static struct V_159 * F_125 ( struct V_240 * V_241 , struct V_47 * V_48 )
{
struct V_159 * V_228 ;
V_228 = F_71 ( V_241 -> V_13 , V_48 -> V_180 , 0 , 0 , NULL , V_243 ) ;
if ( V_228 == NULL )
return F_113 ( - V_234 ) ;
V_228 -> V_48 = V_48 ;
F_78 ( & V_48 -> V_18 ) ;
return V_228 ;
}
static int F_126 ( struct V_159 * V_228 , T_4 V_171 , struct V_47 * * V_30 )
{
struct V_47 * V_244 ;
int V_49 ;
V_228 -> V_164 . V_183 = 0 ;
V_228 -> V_164 . V_171 = V_171 ;
memset ( & V_228 -> V_160 , 0 , sizeof( V_228 -> V_160 ) ) ;
memset ( & V_228 -> V_165 , 0 , sizeof( V_228 -> V_165 ) ) ;
F_68 ( V_228 ) ;
V_49 = F_127 ( V_228 ) ;
if ( V_49 != 0 )
return V_49 ;
V_244 = F_114 ( V_228 ) ;
if ( F_58 ( V_244 ) )
return F_59 ( V_244 ) ;
F_128 ( V_244 , V_171 ) ;
* V_30 = V_244 ;
return 0 ;
}
static int F_129 ( struct V_159 * V_228 , struct V_47 * V_48 )
{
struct V_47 * V_244 ;
int V_49 ;
F_130 ( V_218 , & V_48 -> V_172 ) ;
F_131 () ;
if ( V_48 -> V_214 != 0 ) {
F_130 ( V_213 , & V_48 -> V_172 ) ;
V_49 = F_126 ( V_228 , V_184 | V_185 , & V_244 ) ;
if ( V_49 != 0 )
return V_49 ;
if ( V_244 != V_48 )
return - V_245 ;
}
if ( V_48 -> V_212 != 0 ) {
F_130 ( V_211 , & V_48 -> V_172 ) ;
V_49 = F_126 ( V_228 , V_185 , & V_244 ) ;
if ( V_49 != 0 )
return V_49 ;
if ( V_244 != V_48 )
return - V_245 ;
}
if ( V_48 -> V_210 != 0 ) {
F_130 ( V_209 , & V_48 -> V_172 ) ;
V_49 = F_126 ( V_228 , V_184 , & V_244 ) ;
if ( V_49 != 0 )
return V_49 ;
if ( V_244 != V_48 )
return - V_245 ;
}
if ( F_31 ( V_218 , & V_48 -> V_172 ) == 0 &&
memcmp ( V_48 -> V_202 . V_127 , V_48 -> V_219 . V_127 , sizeof( V_48 -> V_202 . V_127 ) ) != 0 ) {
F_102 ( & V_48 -> V_220 ) ;
if ( F_31 ( V_218 , & V_48 -> V_172 ) == 0 )
memcpy ( V_48 -> V_202 . V_127 , V_48 -> V_219 . V_127 , sizeof( V_48 -> V_202 . V_127 ) ) ;
F_103 ( & V_48 -> V_220 ) ;
}
return 0 ;
}
static int F_132 ( struct V_240 * V_241 , struct V_47 * V_48 )
{
struct V_215 * V_216 ;
struct V_159 * V_228 ;
T_4 V_236 = 0 ;
int V_246 ;
V_228 = F_125 ( V_241 , V_48 ) ;
if ( F_58 ( V_228 ) )
return F_59 ( V_228 ) ;
V_228 -> V_164 . V_196 = V_247 ;
V_228 -> V_164 . V_182 = F_79 ( V_48 -> V_144 ) ;
F_106 () ;
V_216 = F_107 ( F_66 ( V_48 -> V_144 ) -> V_216 ) ;
if ( V_216 != NULL && F_31 ( V_217 , & V_216 -> V_172 ) != 0 )
V_236 = V_216 -> type ;
F_108 () ;
V_228 -> V_164 . V_200 . V_236 = V_236 ;
V_246 = F_129 ( V_228 , V_48 ) ;
F_90 ( V_228 ) ;
return V_246 ;
}
static int F_133 ( struct V_240 * V_241 , struct V_47 * V_48 )
{
struct V_42 * V_43 = F_73 ( V_48 -> V_144 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_132 ( V_241 , V_48 ) ;
if ( V_1 != - V_71 )
break;
F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_134 ( struct V_169 * V_170 , struct V_47 * V_48 )
{
struct V_240 * V_241 ;
int V_49 ;
V_241 = F_122 ( V_48 ) ;
if ( F_58 ( V_241 ) )
return F_59 ( V_241 ) ;
V_49 = F_133 ( V_241 , V_48 ) ;
F_135 ( V_241 ) ;
return V_49 ;
}
static int F_136 ( struct V_240 * V_241 , struct V_47 * V_48 , const T_7 * V_202 )
{
struct V_159 * V_228 ;
int V_49 ;
V_228 = F_125 ( V_241 , V_48 ) ;
if ( F_58 ( V_228 ) )
return F_59 ( V_228 ) ;
V_228 -> V_164 . V_196 = V_238 ;
memcpy ( V_228 -> V_164 . V_200 . V_216 . V_127 , V_202 -> V_127 ,
sizeof( V_228 -> V_164 . V_200 . V_216 . V_127 ) ) ;
V_49 = F_129 ( V_228 , V_48 ) ;
F_90 ( V_228 ) ;
return V_49 ;
}
int F_137 ( struct V_240 * V_241 , struct V_47 * V_48 , const T_7 * V_202 )
{
struct V_45 V_46 = { } ;
struct V_42 * V_43 = F_73 ( V_48 -> V_144 ) ;
int V_1 ;
do {
V_1 = F_136 ( V_241 , V_48 , V_202 ) ;
switch ( V_1 ) {
case 0 :
case - V_242 :
case - V_245 :
goto V_108;
case - V_59 :
case - V_60 :
case - V_61 :
case - V_62 :
case - V_63 :
F_20 ( V_43 -> V_28 -> V_66 ) ;
goto V_108;
case - V_57 :
case - V_56 :
case - V_55 :
F_18 ( V_43 -> V_28 ) ;
goto V_108;
case - V_41 :
case - V_51 :
case - V_52 :
F_17 ( V_43 , V_48 ) ;
case - V_72 :
case - V_234 :
V_1 = 0 ;
goto V_108;
}
V_1 = F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
V_108:
return V_1 ;
}
static void F_138 ( struct V_93 * V_94 , void * V_125 )
{
struct V_159 * V_127 = V_125 ;
V_127 -> V_248 = V_94 -> V_141 ;
if ( V_127 -> V_248 == 0 ) {
memcpy ( V_127 -> V_160 . V_202 . V_127 , V_127 -> V_165 . V_202 . V_127 ,
sizeof( V_127 -> V_160 . V_202 . V_127 ) ) ;
F_139 ( & V_127 -> V_180 -> V_177 , 0 ) ;
F_26 ( V_127 -> V_160 . V_43 , V_127 -> V_80 ) ;
V_127 -> V_231 = 1 ;
}
}
static void F_140 ( void * V_125 )
{
struct V_159 * V_127 = V_125 ;
struct V_47 * V_48 = NULL ;
if ( V_127 -> V_249 == 0 )
goto V_250;
if ( ! V_127 -> V_231 )
goto V_250;
V_48 = F_114 ( V_127 ) ;
if ( ! F_58 ( V_48 ) )
F_128 ( V_48 , V_127 -> V_164 . V_171 ) ;
V_250:
F_90 ( V_127 ) ;
}
static int F_141 ( struct V_159 * V_127 )
{
struct V_42 * V_43 = F_73 ( V_127 -> V_145 -> V_24 ) ;
struct V_93 * V_94 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_253 ] ,
. V_254 = & V_127 -> V_166 ,
. V_255 = & V_127 -> V_165 ,
. V_256 = V_127 -> V_180 -> V_230 ,
} ;
struct V_134 V_257 = {
. V_136 = V_43 -> V_73 ,
. V_131 = & V_132 ,
. V_137 = & V_258 ,
. V_139 = V_127 ,
. V_259 = V_260 ,
. V_172 = V_261 ,
} ;
int V_246 ;
F_142 ( & V_127 -> V_203 ) ;
V_127 -> V_231 = 0 ;
V_127 -> V_248 = 0 ;
V_127 -> V_80 = V_124 ;
V_94 = F_57 ( & V_257 ) ;
if ( F_58 ( V_94 ) )
return F_59 ( V_94 ) ;
V_246 = F_92 ( V_94 ) ;
if ( V_246 != 0 ) {
V_127 -> V_249 = 1 ;
F_143 () ;
} else
V_246 = V_127 -> V_248 ;
F_60 ( V_94 ) ;
return V_246 ;
}
static void F_144 ( struct V_93 * V_94 , void * V_125 )
{
struct V_159 * V_127 = V_125 ;
struct V_169 * V_170 = V_127 -> V_180 ;
if ( F_145 ( V_127 -> V_164 . V_163 , V_94 ) != 0 )
return;
if ( V_127 -> V_48 != NULL ) {
struct V_215 * V_216 ;
if ( F_94 ( V_127 -> V_48 , V_127 -> V_164 . V_171 , V_127 -> V_164 . V_183 ) )
goto V_262;
F_106 () ;
V_216 = F_107 ( F_66 ( V_127 -> V_48 -> V_144 ) -> V_216 ) ;
if ( V_127 -> V_164 . V_196 != V_238 &&
F_95 ( V_216 , V_127 -> V_164 . V_171 ) )
goto V_263;
F_108 () ;
}
V_127 -> V_164 . V_188 = V_170 -> V_189 . V_188 ;
V_127 -> V_164 . V_186 = V_170 -> V_264 -> V_28 -> V_187 ;
if ( V_127 -> V_164 . V_196 == V_247 ) {
V_94 -> V_265 . V_251 = & V_252 [ V_266 ] ;
F_146 ( & V_127 -> V_160 . V_182 , V_127 -> V_164 . V_182 ) ;
}
V_127 -> V_80 = V_124 ;
if ( F_50 ( V_127 -> V_164 . V_43 ,
& V_127 -> V_164 . V_129 ,
& V_127 -> V_160 . V_130 , 1 , V_94 ) )
return;
F_53 ( V_94 ) ;
return;
V_263:
F_108 () ;
V_262:
V_94 -> V_267 = NULL ;
}
static void F_147 ( struct V_93 * V_94 , void * V_125 )
{
F_33 ( V_94 , V_99 ) ;
F_144 ( V_94 , V_125 ) ;
}
static void F_148 ( struct V_93 * V_94 , void * V_125 )
{
struct V_159 * V_127 = V_125 ;
V_127 -> V_248 = V_94 -> V_141 ;
if ( ! F_41 ( V_94 , & V_127 -> V_160 . V_130 ) )
return;
if ( V_94 -> V_141 == 0 ) {
switch ( V_127 -> V_160 . V_161 -> V_206 & V_268 ) {
case V_269 :
break;
case V_270 :
V_127 -> V_248 = - V_271 ;
break;
case V_272 :
V_127 -> V_248 = - V_273 ;
break;
default:
V_127 -> V_248 = - V_274 ;
}
F_26 ( V_127 -> V_160 . V_43 , V_127 -> V_80 ) ;
if ( ! ( V_127 -> V_160 . V_275 & V_276 ) )
F_139 ( & V_127 -> V_180 -> V_177 , 0 ) ;
}
V_127 -> V_231 = 1 ;
}
static void F_149 ( void * V_125 )
{
struct V_159 * V_127 = V_125 ;
struct V_47 * V_48 = NULL ;
if ( V_127 -> V_249 == 0 )
goto V_250;
if ( V_127 -> V_248 != 0 || ! V_127 -> V_231 )
goto V_250;
if ( V_127 -> V_160 . V_275 & V_276 )
goto V_250;
V_48 = F_114 ( V_127 ) ;
if ( ! F_58 ( V_48 ) )
F_128 ( V_48 , V_127 -> V_164 . V_171 ) ;
V_250:
F_90 ( V_127 ) ;
}
static int F_150 ( struct V_159 * V_127 , int V_277 )
{
struct V_144 * V_145 = V_127 -> V_145 -> V_24 ;
struct V_42 * V_43 = F_73 ( V_145 ) ;
struct V_278 * V_164 = & V_127 -> V_164 ;
struct V_279 * V_160 = & V_127 -> V_160 ;
struct V_93 * V_94 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_280 ] ,
. V_254 = V_164 ,
. V_255 = V_160 ,
. V_256 = V_127 -> V_180 -> V_230 ,
} ;
struct V_134 V_257 = {
. V_136 = V_43 -> V_73 ,
. V_131 = & V_132 ,
. V_137 = & V_281 ,
. V_139 = V_127 ,
. V_259 = V_260 ,
. V_172 = V_261 ,
} ;
int V_246 ;
F_142 ( & V_127 -> V_203 ) ;
V_127 -> V_231 = 0 ;
V_127 -> V_248 = 0 ;
V_127 -> V_249 = 0 ;
if ( V_277 )
V_257 . V_137 = & V_282 ;
V_94 = F_57 ( & V_257 ) ;
if ( F_58 ( V_94 ) )
return F_59 ( V_94 ) ;
V_246 = F_92 ( V_94 ) ;
if ( V_246 != 0 ) {
V_127 -> V_249 = 1 ;
F_143 () ;
} else
V_246 = V_127 -> V_248 ;
F_60 ( V_94 ) ;
return V_246 ;
}
static int F_127 ( struct V_159 * V_127 )
{
struct V_144 * V_145 = V_127 -> V_145 -> V_24 ;
struct V_279 * V_160 = & V_127 -> V_160 ;
int V_246 ;
V_246 = F_150 ( V_127 , 1 ) ;
if ( V_246 != 0 || ! V_127 -> V_231 )
return V_246 ;
F_151 ( F_73 ( V_145 ) , & V_127 -> V_161 ) ;
F_152 ( V_145 , V_160 -> V_162 ) ;
if ( V_160 -> V_275 & V_276 ) {
V_246 = F_141 ( V_127 ) ;
if ( V_246 != 0 )
return V_246 ;
}
return V_246 ;
}
static int F_153 ( struct V_159 * V_127 )
{
struct V_144 * V_145 = V_127 -> V_145 -> V_24 ;
struct V_42 * V_43 = F_73 ( V_145 ) ;
struct V_278 * V_164 = & V_127 -> V_164 ;
struct V_279 * V_160 = & V_127 -> V_160 ;
int V_246 ;
V_246 = F_150 ( V_127 , 0 ) ;
if ( ! V_127 -> V_231 )
return V_246 ;
if ( V_246 != 0 ) {
if ( V_246 == - V_7 &&
! ( V_164 -> V_183 & V_198 ) )
return - V_242 ;
return V_246 ;
}
F_151 ( V_43 , & V_127 -> V_161 ) ;
if ( V_164 -> V_183 & V_198 ) {
F_65 ( V_145 , & V_160 -> V_147 ) ;
F_154 ( V_145 , V_160 -> V_162 ) ;
} else
F_152 ( V_145 , V_160 -> V_162 ) ;
if ( ( V_160 -> V_275 & V_283 ) == 0 )
V_43 -> V_76 &= ~ V_284 ;
if( V_160 -> V_275 & V_276 ) {
V_246 = F_141 ( V_127 ) ;
if ( V_246 != 0 )
return V_246 ;
}
if ( ! ( V_160 -> V_161 -> V_232 & V_233 ) )
F_155 ( V_43 , & V_160 -> V_182 , V_160 -> V_161 ) ;
return 0 ;
}
static int F_156 ( struct V_28 * V_29 )
{
unsigned int V_285 ;
int V_49 ;
for ( V_285 = V_286 ; V_285 != 0 ; V_285 -- ) {
V_49 = F_10 ( V_29 ) ;
if ( V_49 != 0 )
break;
if ( ! F_31 ( V_287 , & V_29 -> V_31 ) &&
! F_31 ( V_288 , & V_29 -> V_31 ) )
break;
F_157 ( V_29 ) ;
V_49 = - V_10 ;
}
return V_49 ;
}
static int F_158 ( struct V_42 * V_43 )
{
return F_156 ( V_43 -> V_28 ) ;
}
static int F_159 ( struct V_240 * V_241 , struct V_47 * V_48 )
{
struct V_159 * V_228 ;
int V_49 ;
V_228 = F_125 ( V_241 , V_48 ) ;
if ( F_58 ( V_228 ) )
return F_59 ( V_228 ) ;
V_49 = F_129 ( V_228 , V_48 ) ;
if ( V_49 == - V_245 )
F_160 ( V_241 -> V_13 ) ;
F_90 ( V_228 ) ;
return V_49 ;
}
static int F_161 ( struct V_240 * V_241 , struct V_47 * V_48 )
{
struct V_42 * V_43 = F_73 ( V_48 -> V_144 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_159 ( V_241 , V_48 ) ;
switch ( V_1 ) {
default:
goto V_108;
case - V_70 :
case - V_71 :
F_16 ( V_43 , V_1 , & V_46 ) ;
V_1 = 0 ;
}
} while ( V_46 . V_50 );
V_108:
return V_1 ;
}
static int F_162 ( struct V_169 * V_170 , struct V_47 * V_48 )
{
struct V_240 * V_241 ;
int V_49 ;
V_241 = F_122 ( V_48 ) ;
if ( F_58 ( V_241 ) )
return F_59 ( V_241 ) ;
V_49 = F_161 ( V_241 , V_48 ) ;
F_135 ( V_241 ) ;
return V_49 ;
}
static int F_163 ( struct V_169 * V_170 , struct V_47 * V_48 )
{
int V_246 ;
struct V_42 * V_43 = F_73 ( V_48 -> V_144 ) ;
V_246 = F_164 ( V_43 , V_48 ) ;
if ( V_246 == V_107 )
return 0 ;
F_165 ( V_43 , V_48 ) ;
return F_162 ( V_170 , V_48 ) ;
}
static inline void F_166 ( struct V_159 * V_228 , struct V_173 * V_289 )
{
if ( ( V_228 -> V_160 . V_290 [ 1 ] & V_291 ) &&
! ( V_289 -> V_292 & V_293 ) )
V_289 -> V_292 |= V_294 ;
if ( ( V_228 -> V_160 . V_290 [ 1 ] & V_295 ) &&
! ( V_289 -> V_292 & V_296 ) )
V_289 -> V_292 |= V_297 ;
}
static int F_167 ( struct V_144 * V_145 , struct V_13 * V_13 , T_4 V_171 , int V_172 , struct V_173 * V_289 , struct V_256 * V_298 , struct V_47 * * V_30 )
{
struct V_169 * V_170 ;
struct V_47 * V_48 = NULL ;
struct V_42 * V_43 = F_73 ( V_145 ) ;
struct V_159 * V_228 ;
int V_246 ;
V_246 = - V_234 ;
if ( ! ( V_170 = F_168 ( V_43 , V_298 ) ) ) {
F_2 ( L_28 ) ;
goto V_299;
}
V_246 = F_158 ( V_43 ) ;
if ( V_246 != 0 )
goto V_300;
if ( V_13 -> V_24 != NULL )
F_109 ( V_13 -> V_24 , V_171 ) ;
V_246 = - V_234 ;
V_228 = F_71 ( V_13 , V_170 , V_171 , V_172 , V_289 , V_301 ) ;
if ( V_228 == NULL )
goto V_300;
if ( V_13 -> V_24 != NULL )
V_228 -> V_48 = F_116 ( V_13 -> V_24 , V_170 ) ;
V_246 = F_153 ( V_228 ) ;
if ( V_246 != 0 )
goto V_302;
V_48 = F_114 ( V_228 ) ;
V_246 = F_59 ( V_48 ) ;
if ( F_58 ( V_48 ) )
goto V_302;
if ( V_43 -> V_76 & V_284 )
F_100 ( V_303 , & V_48 -> V_172 ) ;
if ( V_228 -> V_164 . V_183 & V_208 ) {
F_166 ( V_228 , V_289 ) ;
F_69 ( V_228 -> V_160 . V_161 ) ;
V_246 = F_169 ( V_48 -> V_144 , V_298 ,
V_228 -> V_160 . V_161 , V_289 ,
V_48 ) ;
if ( V_246 == 0 )
F_170 ( V_48 -> V_144 , V_289 ) ;
F_154 ( V_48 -> V_144 , V_228 -> V_160 . V_161 ) ;
}
F_90 ( V_228 ) ;
F_87 ( V_170 ) ;
* V_30 = V_48 ;
return 0 ;
V_302:
F_90 ( V_228 ) ;
V_300:
F_87 ( V_170 ) ;
V_299:
* V_30 = NULL ;
return V_246 ;
}
static struct V_47 * F_171 ( struct V_144 * V_145 , struct V_13 * V_13 , T_4 V_171 , int V_172 , struct V_173 * V_289 , struct V_256 * V_298 )
{
struct V_45 V_46 = { } ;
struct V_47 * V_30 ;
int V_246 ;
do {
V_246 = F_167 ( V_145 , V_13 , V_171 , V_172 , V_289 , V_298 , & V_30 ) ;
if ( V_246 == 0 )
break;
if ( V_246 == - V_304 ) {
F_21 ( V_78 L_5
L_29 ,
F_73 ( V_145 ) -> V_28 -> V_79 ) ;
V_46 . V_50 = 1 ;
continue;
}
if ( V_246 == - V_52 ) {
V_46 . V_50 = 1 ;
continue;
}
if ( V_246 == - V_119 ) {
V_46 . V_50 = 1 ;
continue;
}
V_30 = F_113 ( F_16 ( F_73 ( V_145 ) ,
V_246 , & V_46 ) ) ;
} while ( V_46 . V_50 );
return V_30 ;
}
static int F_172 ( struct V_144 * V_144 , struct V_256 * V_298 ,
struct V_305 * V_306 , struct V_173 * V_289 ,
struct V_47 * V_48 )
{
struct V_42 * V_43 = F_73 ( V_144 ) ;
struct V_307 V_308 = {
. V_182 = F_79 ( V_144 ) ,
. V_309 = V_289 ,
. V_43 = V_43 ,
. V_192 = V_43 -> V_193 ,
} ;
struct V_310 V_30 = {
. V_306 = V_306 ,
. V_43 = V_43 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_311 ] ,
. V_254 = & V_308 ,
. V_255 = & V_30 ,
. V_256 = V_298 ,
} ;
unsigned long V_80 = V_124 ;
int V_246 ;
F_69 ( V_306 ) ;
if ( F_173 ( & V_308 . V_202 , V_144 ) ) {
} else if ( V_48 != NULL ) {
F_174 ( & V_308 . V_202 , V_48 , V_40 -> V_312 , V_40 -> V_313 ) ;
} else
memcpy ( & V_308 . V_202 , & V_314 , sizeof( V_308 . V_202 ) ) ;
V_246 = F_64 ( V_43 -> V_73 , V_43 , & V_132 , & V_308 . V_129 , & V_30 . V_130 , 1 ) ;
if ( V_246 == 0 && V_48 != NULL )
F_26 ( V_43 , V_80 ) ;
return V_246 ;
}
static int F_169 ( struct V_144 * V_144 , struct V_256 * V_298 ,
struct V_305 * V_306 , struct V_173 * V_289 ,
struct V_47 * V_48 )
{
struct V_42 * V_43 = F_73 ( V_144 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_172 ( V_144 , V_298 , V_306 , V_289 , V_48 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static void F_175 ( void * V_127 )
{
struct V_315 * V_125 = V_127 ;
struct V_169 * V_170 = V_125 -> V_48 -> V_180 ;
struct V_204 * V_205 = V_125 -> V_48 -> V_144 -> V_316 ;
if ( V_125 -> V_317 )
F_176 ( V_125 -> V_48 -> V_144 ) ;
F_86 ( V_125 -> V_48 ) ;
F_85 ( V_125 -> V_308 . V_163 ) ;
F_87 ( V_170 ) ;
F_88 ( V_205 ) ;
F_81 ( V_125 ) ;
}
static void F_177 ( struct V_47 * V_48 ,
T_4 V_171 )
{
F_23 ( & V_48 -> V_180 -> V_222 ) ;
if ( ! ( V_171 & V_184 ) )
F_130 ( V_209 , & V_48 -> V_172 ) ;
if ( ! ( V_171 & V_185 ) )
F_130 ( V_211 , & V_48 -> V_172 ) ;
F_130 ( V_213 , & V_48 -> V_172 ) ;
F_25 ( & V_48 -> V_180 -> V_222 ) ;
}
static void F_178 ( struct V_93 * V_94 , void * V_127 )
{
struct V_315 * V_125 = V_127 ;
struct V_47 * V_48 = V_125 -> V_48 ;
struct V_42 * V_43 = F_73 ( V_125 -> V_144 ) ;
if ( ! F_41 ( V_94 , & V_125 -> V_30 . V_130 ) )
return;
switch ( V_94 -> V_141 ) {
case 0 :
if ( V_125 -> V_317 )
F_179 ( V_48 -> V_144 ,
V_125 -> V_318 ) ;
F_101 ( V_48 , & V_125 -> V_30 . V_202 , 0 ) ;
F_26 ( V_43 , V_125 -> V_80 ) ;
F_177 ( V_48 ,
V_125 -> V_308 . V_171 ) ;
break;
case - V_56 :
case - V_75 :
case - V_52 :
case - V_55 :
if ( V_125 -> V_308 . V_171 == 0 )
break;
default:
if ( F_180 ( V_94 , V_43 , V_48 ) == - V_119 )
F_181 ( V_94 ) ;
}
F_182 ( V_125 -> V_308 . V_163 ) ;
F_152 ( V_125 -> V_144 , V_125 -> V_30 . V_306 ) ;
}
static void F_183 ( struct V_93 * V_94 , void * V_127 )
{
struct V_315 * V_125 = V_127 ;
struct V_47 * V_48 = V_125 -> V_48 ;
int V_319 = 0 ;
if ( F_145 ( V_125 -> V_308 . V_163 , V_94 ) != 0 )
return;
V_94 -> V_265 . V_251 = & V_252 [ V_320 ] ;
V_125 -> V_308 . V_171 = V_184 | V_185 ;
F_23 ( & V_48 -> V_180 -> V_222 ) ;
if ( V_48 -> V_214 == 0 ) {
if ( V_48 -> V_210 == 0 ) {
V_319 |= F_31 ( V_209 , & V_48 -> V_172 ) ;
V_319 |= F_31 ( V_213 , & V_48 -> V_172 ) ;
V_125 -> V_308 . V_171 &= ~ V_184 ;
}
if ( V_48 -> V_212 == 0 ) {
V_319 |= F_31 ( V_211 , & V_48 -> V_172 ) ;
V_319 |= F_31 ( V_213 , & V_48 -> V_172 ) ;
V_125 -> V_308 . V_171 &= ~ V_185 ;
}
}
F_25 ( & V_48 -> V_180 -> V_222 ) ;
if ( ! V_319 ) {
V_94 -> V_267 = NULL ;
return;
}
if ( V_125 -> V_308 . V_171 == 0 ) {
V_94 -> V_265 . V_251 = & V_252 [ V_321 ] ;
if ( V_125 -> V_317 &&
F_184 ( V_125 -> V_144 , & V_125 -> V_318 ) ) {
F_48 ( & F_73 ( V_125 -> V_144 ) -> V_322 ,
V_94 , NULL ) ;
return;
}
}
F_69 ( V_125 -> V_30 . V_306 ) ;
V_125 -> V_80 = V_124 ;
if ( F_50 ( F_73 ( V_125 -> V_144 ) ,
& V_125 -> V_308 . V_129 , & V_125 -> V_30 . V_130 ,
1 , V_94 ) )
return;
F_53 ( V_94 ) ;
}
int F_185 ( struct V_47 * V_48 , T_5 V_175 , int V_323 , bool V_317 )
{
struct V_42 * V_43 = F_73 ( V_48 -> V_144 ) ;
struct V_315 * V_125 ;
struct V_169 * V_170 = V_48 -> V_180 ;
struct V_93 * V_94 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_321 ] ,
. V_256 = V_48 -> V_180 -> V_230 ,
} ;
struct V_134 V_257 = {
. V_136 = V_43 -> V_73 ,
. V_131 = & V_132 ,
. V_137 = & V_324 ,
. V_259 = V_260 ,
. V_172 = V_261 ,
} ;
int V_246 = - V_234 ;
V_125 = F_74 ( sizeof( * V_125 ) , V_175 ) ;
if ( V_125 == NULL )
goto V_108;
V_125 -> V_144 = V_48 -> V_144 ;
V_125 -> V_48 = V_48 ;
V_125 -> V_308 . V_182 = F_79 ( V_48 -> V_144 ) ;
V_125 -> V_308 . V_202 = & V_48 -> V_219 ;
V_125 -> V_308 . V_163 = F_75 ( & V_48 -> V_180 -> V_177 , V_175 ) ;
if ( V_125 -> V_308 . V_163 == NULL )
goto V_325;
V_125 -> V_308 . V_171 = 0 ;
V_125 -> V_308 . V_192 = V_43 -> V_195 ;
V_125 -> V_30 . V_306 = & V_125 -> V_306 ;
V_125 -> V_30 . V_163 = V_125 -> V_308 . V_163 ;
V_125 -> V_30 . V_43 = V_43 ;
V_125 -> V_317 = V_317 ;
F_76 ( V_125 -> V_144 -> V_316 ) ;
V_132 . V_254 = & V_125 -> V_308 ;
V_132 . V_255 = & V_125 -> V_30 ;
V_257 . V_139 = V_125 ;
V_94 = F_57 ( & V_257 ) ;
if ( F_58 ( V_94 ) )
return F_59 ( V_94 ) ;
V_246 = 0 ;
if ( V_323 )
V_246 = F_93 ( V_94 ) ;
F_60 ( V_94 ) ;
return V_246 ;
V_325:
F_81 ( V_125 ) ;
V_108:
if ( V_317 )
F_176 ( V_48 -> V_144 ) ;
F_86 ( V_48 ) ;
F_87 ( V_170 ) ;
return V_246 ;
}
static struct V_144 *
F_186 ( struct V_144 * V_145 , struct V_240 * V_241 , int V_183 , struct V_173 * V_326 )
{
struct V_47 * V_48 ;
V_48 = F_171 ( V_145 , V_241 -> V_13 , V_241 -> V_206 , V_183 , V_326 , V_241 -> V_298 ) ;
if ( F_58 ( V_48 ) )
return F_187 ( V_48 ) ;
V_241 -> V_48 = V_48 ;
return F_188 ( V_48 -> V_144 ) ;
}
static void F_189 ( struct V_240 * V_241 , int V_327 )
{
if ( V_241 -> V_48 == NULL )
return;
if ( V_327 )
F_190 ( V_241 -> V_48 , V_241 -> V_206 ) ;
else
F_128 ( V_241 -> V_48 , V_241 -> V_206 ) ;
}
static int F_191 ( struct V_42 * V_43 , struct V_328 * V_329 )
{
struct V_330 args = {
. V_329 = V_329 ,
} ;
struct V_331 V_30 = {} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_332 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
int V_246 ;
V_246 = F_64 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
if ( V_246 == 0 ) {
memcpy ( V_43 -> V_193 , V_30 . V_193 , sizeof( V_43 -> V_193 ) ) ;
V_43 -> V_76 &= ~ ( V_333 | V_334 |
V_335 | V_336 |
V_337 | V_338 | V_339 |
V_340 | V_341 |
V_342 | V_343 ) ;
if ( V_30 . V_193 [ 0 ] & V_344 )
V_43 -> V_76 |= V_333 ;
if ( V_30 . V_345 != 0 )
V_43 -> V_76 |= V_334 ;
if ( V_30 . V_346 != 0 )
V_43 -> V_76 |= V_335 ;
if ( V_30 . V_193 [ 0 ] & V_23 )
V_43 -> V_76 |= V_336 ;
if ( V_30 . V_193 [ 1 ] & V_347 )
V_43 -> V_76 |= V_337 ;
if ( V_30 . V_193 [ 1 ] & V_348 )
V_43 -> V_76 |= V_338 ;
if ( V_30 . V_193 [ 1 ] & V_349 )
V_43 -> V_76 |= V_339 ;
if ( V_30 . V_193 [ 1 ] & V_350 )
V_43 -> V_76 |= V_340 ;
if ( V_30 . V_193 [ 1 ] & V_291 )
V_43 -> V_76 |= V_341 ;
if ( V_30 . V_193 [ 1 ] & V_351 )
V_43 -> V_76 |= V_342 ;
if ( V_30 . V_193 [ 1 ] & V_295 )
V_43 -> V_76 |= V_343 ;
memcpy ( V_43 -> V_195 , V_30 . V_193 , sizeof( V_43 -> V_195 ) ) ;
V_43 -> V_195 [ 0 ] &= V_352 | V_353 ;
V_43 -> V_195 [ 1 ] &= V_351 | V_295 ;
V_43 -> V_354 = V_30 . V_354 ;
}
return V_246 ;
}
int F_192 ( struct V_42 * V_43 , struct V_328 * V_329 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_191 ( V_43 , V_329 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_193 ( struct V_42 * V_43 , struct V_328 * V_329 ,
struct V_355 * V_356 )
{
struct V_357 args = {
. V_192 = V_358 ,
} ;
struct V_359 V_30 = {
. V_43 = V_43 ,
. V_306 = V_356 -> V_306 ,
. V_182 = V_329 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_360 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
F_69 ( V_356 -> V_306 ) ;
return F_64 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
}
static int F_194 ( struct V_42 * V_43 , struct V_328 * V_329 ,
struct V_355 * V_356 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_193 ( V_43 , V_329 , V_356 ) ;
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
static int F_195 ( struct V_42 * V_43 , struct V_328 * V_329 ,
struct V_355 * V_356 , T_8 V_361 )
{
struct V_362 * V_363 ;
int V_49 ;
V_363 = F_196 ( V_361 , V_43 -> V_73 ) ;
if ( ! V_363 ) {
V_49 = - V_10 ;
goto V_108;
}
V_49 = F_194 ( V_43 , V_329 , V_356 ) ;
V_108:
return V_49 ;
}
static int F_197 ( struct V_42 * V_43 , struct V_328 * V_329 ,
struct V_355 * V_356 )
{
int V_364 , V_365 , V_246 = 0 ;
T_8 V_366 [ V_367 ] ;
V_365 = F_198 ( & V_366 [ 0 ] ) ;
V_366 [ V_365 ] = V_368 ;
V_365 += 1 ;
for ( V_364 = 0 ; V_364 < V_365 ; V_364 ++ ) {
V_246 = F_195 ( V_43 , V_329 , V_356 , V_366 [ V_364 ] ) ;
if ( V_246 == - V_4 || V_246 == - V_369 )
continue;
break;
}
if ( V_246 == - V_369 )
V_246 = - V_5 ;
return V_246 ;
}
static int F_199 ( struct V_42 * V_43 , struct V_328 * V_329 ,
struct V_355 * V_356 )
{
int V_370 = V_43 -> V_28 -> V_371 ;
int V_246 = F_194 ( V_43 , V_329 , V_356 ) ;
if ( ( V_246 == - V_4 ) && ! ( V_43 -> V_172 & V_372 ) )
V_246 = V_373 [ V_370 ] -> F_200 ( V_43 , V_329 , V_356 ) ;
if ( V_246 == 0 )
V_246 = F_192 ( V_43 , V_329 ) ;
if ( V_246 == 0 )
V_246 = F_201 ( V_43 , V_329 , V_356 ) ;
return F_1 ( V_246 ) ;
}
static int F_202 ( struct V_144 * V_145 , const struct V_374 * V_190 ,
struct V_305 * V_306 , struct V_328 * V_329 )
{
int V_246 = - V_234 ;
struct V_375 * V_375 = NULL ;
struct V_376 * V_377 = NULL ;
V_375 = F_203 ( V_301 ) ;
if ( V_375 == NULL )
goto V_108;
V_377 = F_204 ( sizeof( struct V_376 ) , V_301 ) ;
if ( V_377 == NULL )
goto V_108;
V_246 = F_205 ( V_145 , V_190 , V_377 , V_375 ) ;
if ( V_246 != 0 )
goto V_108;
if ( F_206 ( & F_73 ( V_145 ) -> V_378 , & V_377 -> V_306 . V_378 ) ) {
F_2 ( L_30
L_31 , V_9 , V_190 -> V_190 ) ;
V_246 = - V_10 ;
goto V_108;
}
F_207 ( & V_377 -> V_306 ) ;
memcpy ( V_306 , & V_377 -> V_306 , sizeof( struct V_305 ) ) ;
memset ( V_329 , 0 , sizeof( struct V_328 ) ) ;
V_108:
if ( V_375 )
F_208 ( V_375 ) ;
F_81 ( V_377 ) ;
return V_246 ;
}
static int F_155 ( struct V_42 * V_43 , struct V_328 * V_329 , struct V_305 * V_306 )
{
struct V_379 args = {
. V_182 = V_329 ,
. V_192 = V_43 -> V_193 ,
} ;
struct V_380 V_30 = {
. V_306 = V_306 ,
. V_43 = V_43 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_381 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
F_69 ( V_306 ) ;
return F_64 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
}
static int F_209 ( struct V_42 * V_43 , struct V_328 * V_329 , struct V_305 * V_306 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_155 ( V_43 , V_329 , V_306 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_210 ( struct V_13 * V_13 , struct V_305 * V_306 ,
struct V_173 * V_289 )
{
struct V_144 * V_144 = V_13 -> V_24 ;
struct V_256 * V_298 = NULL ;
struct V_47 * V_48 = NULL ;
int V_246 ;
if ( F_211 ( V_144 ) )
F_212 ( V_144 ) ;
F_69 ( V_306 ) ;
if ( V_289 -> V_292 & V_382 ) {
struct V_240 * V_241 ;
V_241 = F_213 ( V_289 -> V_383 ) ;
if ( V_241 ) {
V_298 = V_241 -> V_298 ;
V_48 = V_241 -> V_48 ;
}
}
V_246 = F_169 ( V_144 , V_298 , V_306 , V_289 , V_48 ) ;
if ( V_246 == 0 )
F_170 ( V_144 , V_289 ) ;
return V_246 ;
}
static int F_214 ( struct V_35 * V_36 , struct V_144 * V_145 ,
const struct V_374 * V_190 , struct V_328 * V_329 ,
struct V_305 * V_306 )
{
struct V_42 * V_43 = F_73 ( V_145 ) ;
int V_246 ;
struct V_384 args = {
. V_192 = V_43 -> V_193 ,
. V_385 = F_79 ( V_145 ) ,
. V_190 = V_190 ,
} ;
struct V_359 V_30 = {
. V_43 = V_43 ,
. V_306 = V_306 ,
. V_182 = V_329 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_386 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
F_69 ( V_306 ) ;
F_2 ( L_32 , V_190 -> V_190 ) ;
V_246 = F_64 ( V_36 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
F_2 ( L_33 , V_246 ) ;
return V_246 ;
}
void F_215 ( struct V_305 * V_306 , struct V_328 * V_182 )
{
memset ( V_182 , 0 , sizeof( struct V_328 ) ) ;
V_306 -> V_378 . V_387 = 1 ;
V_306 -> V_232 |= V_388 | V_389 |
V_390 | V_391 | V_392 ;
V_306 -> V_206 = V_272 | V_393 | V_394 ;
V_306 -> V_395 = 2 ;
}
static int F_216 ( struct V_35 * V_36 , struct V_144 * V_145 , struct V_374 * V_190 ,
struct V_328 * V_329 , struct V_305 * V_306 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
int V_246 ;
V_246 = F_214 ( V_36 , V_145 , V_190 , V_329 , V_306 ) ;
switch ( V_246 ) {
case - V_7 :
return - V_242 ;
case - V_396 :
return F_202 ( V_145 , V_190 , V_306 , V_329 ) ;
case - V_4 :
F_215 ( V_306 , V_329 ) ;
}
V_1 = F_16 ( F_73 ( V_145 ) ,
V_246 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_217 ( struct V_144 * V_144 , struct V_397 * V_398 )
{
struct V_42 * V_43 = F_73 ( V_144 ) ;
struct V_399 args = {
. V_182 = F_79 ( V_144 ) ,
. V_192 = V_43 -> V_193 ,
} ;
struct V_400 V_30 = {
. V_43 = V_43 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_401 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
. V_256 = V_398 -> V_298 ,
} ;
int V_206 = V_398 -> V_402 ;
int V_246 ;
if ( V_206 & V_403 )
args . V_404 |= V_405 ;
if ( F_218 ( V_144 -> V_406 ) ) {
if ( V_206 & V_407 )
args . V_404 |= V_408 | V_409 | V_410 ;
if ( V_206 & V_411 )
args . V_404 |= V_412 ;
} else {
if ( V_206 & V_407 )
args . V_404 |= V_408 | V_409 ;
if ( V_206 & V_411 )
args . V_404 |= V_413 ;
}
V_30 . V_306 = F_219 () ;
if ( V_30 . V_306 == NULL )
return - V_234 ;
V_246 = F_64 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
if ( ! V_246 ) {
V_398 -> V_402 = 0 ;
if ( V_30 . V_404 & V_405 )
V_398 -> V_402 |= V_403 ;
if ( V_30 . V_404 & ( V_408 | V_409 | V_410 ) )
V_398 -> V_402 |= V_407 ;
if ( V_30 . V_404 & ( V_412 | V_413 ) )
V_398 -> V_402 |= V_411 ;
F_152 ( V_144 , V_30 . V_306 ) ;
}
F_220 ( V_30 . V_306 ) ;
return V_246 ;
}
static int F_221 ( struct V_144 * V_144 , struct V_397 * V_398 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_73 ( V_144 ) ,
F_217 ( V_144 , V_398 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_222 ( struct V_144 * V_144 , struct V_375 * V_375 ,
unsigned int V_27 , unsigned int V_414 )
{
struct V_415 args = {
. V_182 = F_79 ( V_144 ) ,
. V_27 = V_27 ,
. V_414 = V_414 ,
. V_19 = & V_375 ,
} ;
struct V_416 V_30 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_417 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
return F_64 ( F_73 ( V_144 ) -> V_73 , F_73 ( V_144 ) , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
}
static int F_223 ( struct V_144 * V_144 , struct V_375 * V_375 ,
unsigned int V_27 , unsigned int V_414 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_73 ( V_144 ) ,
F_222 ( V_144 , V_375 , V_27 , V_414 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_224 ( struct V_144 * V_145 , struct V_13 * V_13 , struct V_173 * V_289 ,
int V_172 , struct V_240 * V_241 )
{
struct V_13 * V_418 = V_13 ;
struct V_47 * V_48 ;
struct V_256 * V_298 = NULL ;
T_4 V_171 = 0 ;
int V_246 = 0 ;
if ( V_241 != NULL ) {
V_298 = V_241 -> V_298 ;
V_418 = V_241 -> V_13 ;
V_171 = V_241 -> V_206 ;
}
V_289 -> V_419 &= ~ F_225 () ;
V_48 = F_171 ( V_145 , V_418 , V_171 , V_172 , V_289 , V_298 ) ;
F_160 ( V_13 ) ;
if ( F_58 ( V_48 ) ) {
V_246 = F_59 ( V_48 ) ;
goto V_108;
}
F_226 ( V_13 , F_188 ( V_48 -> V_144 ) ) ;
F_227 ( V_13 , F_228 ( V_145 ) ) ;
if ( V_241 != NULL )
V_241 -> V_48 = V_48 ;
else
F_190 ( V_48 , V_171 ) ;
V_108:
return V_246 ;
}
static int F_229 ( struct V_144 * V_145 , struct V_374 * V_190 )
{
struct V_42 * V_43 = F_73 ( V_145 ) ;
struct V_420 args = {
. V_182 = F_79 ( V_145 ) ,
. V_190 . V_365 = V_190 -> V_365 ,
. V_190 . V_190 = V_190 -> V_190 ,
. V_192 = V_43 -> V_193 ,
} ;
struct V_421 V_30 = {
. V_43 = V_43 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_422 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
int V_246 = - V_234 ;
V_30 . V_162 = F_219 () ;
if ( V_30 . V_162 == NULL )
goto V_108;
V_246 = F_64 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 1 ) ;
if ( V_246 == 0 ) {
F_65 ( V_145 , & V_30 . V_147 ) ;
F_154 ( V_145 , V_30 . V_162 ) ;
}
F_220 ( V_30 . V_162 ) ;
V_108:
return V_246 ;
}
static int F_230 ( struct V_144 * V_145 , struct V_374 * V_190 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_73 ( V_145 ) ,
F_229 ( V_145 , V_190 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static void F_231 ( struct V_131 * V_132 , struct V_144 * V_145 )
{
struct V_42 * V_43 = F_73 ( V_145 ) ;
struct V_420 * args = V_132 -> V_254 ;
struct V_421 * V_30 = V_132 -> V_255 ;
args -> V_192 = V_43 -> V_195 ;
V_30 -> V_43 = V_43 ;
V_30 -> V_130 . V_103 = NULL ;
V_132 -> V_251 = & V_252 [ V_422 ] ;
}
static int F_232 ( struct V_93 * V_94 , struct V_144 * V_145 )
{
struct V_421 * V_30 = V_94 -> V_265 . V_255 ;
if ( ! F_41 ( V_94 , & V_30 -> V_130 ) )
return 0 ;
if ( F_180 ( V_94 , V_30 -> V_43 , NULL ) == - V_119 )
return 0 ;
F_65 ( V_145 , & V_30 -> V_147 ) ;
F_154 ( V_145 , V_30 -> V_162 ) ;
return 1 ;
}
static void F_233 ( struct V_131 * V_132 , struct V_144 * V_145 )
{
struct V_42 * V_43 = F_73 ( V_145 ) ;
struct V_423 * V_308 = V_132 -> V_254 ;
struct V_424 * V_30 = V_132 -> V_255 ;
V_132 -> V_251 = & V_252 [ V_425 ] ;
V_308 -> V_192 = V_43 -> V_193 ;
V_30 -> V_43 = V_43 ;
}
static int F_234 ( struct V_93 * V_94 , struct V_144 * V_426 ,
struct V_144 * V_427 )
{
struct V_424 * V_30 = V_94 -> V_265 . V_255 ;
if ( ! F_41 ( V_94 , & V_30 -> V_130 ) )
return 0 ;
if ( F_180 ( V_94 , V_30 -> V_43 , NULL ) == - V_119 )
return 0 ;
F_65 ( V_426 , & V_30 -> V_428 ) ;
F_154 ( V_426 , V_30 -> V_429 ) ;
F_65 ( V_427 , & V_30 -> V_430 ) ;
F_154 ( V_427 , V_30 -> V_431 ) ;
return 1 ;
}
static int F_235 ( struct V_144 * V_426 , struct V_374 * V_432 ,
struct V_144 * V_427 , struct V_374 * V_433 )
{
struct V_42 * V_43 = F_73 ( V_426 ) ;
struct V_423 V_308 = {
. V_426 = F_79 ( V_426 ) ,
. V_427 = F_79 ( V_427 ) ,
. V_432 = V_432 ,
. V_433 = V_433 ,
. V_192 = V_43 -> V_193 ,
} ;
struct V_424 V_30 = {
. V_43 = V_43 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_425 ] ,
. V_254 = & V_308 ,
. V_255 = & V_30 ,
} ;
int V_246 = - V_234 ;
V_30 . V_429 = F_219 () ;
V_30 . V_431 = F_219 () ;
if ( V_30 . V_429 == NULL || V_30 . V_431 == NULL )
goto V_108;
V_246 = F_64 ( V_43 -> V_73 , V_43 , & V_132 , & V_308 . V_129 , & V_30 . V_130 , 1 ) ;
if ( ! V_246 ) {
F_65 ( V_426 , & V_30 . V_428 ) ;
F_154 ( V_426 , V_30 . V_429 ) ;
F_65 ( V_427 , & V_30 . V_430 ) ;
F_154 ( V_427 , V_30 . V_431 ) ;
}
V_108:
F_220 ( V_30 . V_431 ) ;
F_220 ( V_30 . V_429 ) ;
return V_246 ;
}
static int F_236 ( struct V_144 * V_426 , struct V_374 * V_432 ,
struct V_144 * V_427 , struct V_374 * V_433 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_73 ( V_426 ) ,
F_235 ( V_426 , V_432 ,
V_427 , V_433 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_237 ( struct V_144 * V_144 , struct V_144 * V_145 , struct V_374 * V_190 )
{
struct V_42 * V_43 = F_73 ( V_144 ) ;
struct V_434 V_308 = {
. V_182 = F_79 ( V_144 ) ,
. V_385 = F_79 ( V_145 ) ,
. V_190 = V_190 ,
. V_192 = V_43 -> V_193 ,
} ;
struct V_435 V_30 = {
. V_43 = V_43 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_436 ] ,
. V_254 = & V_308 ,
. V_255 = & V_30 ,
} ;
int V_246 = - V_234 ;
V_30 . V_306 = F_219 () ;
V_30 . V_162 = F_219 () ;
if ( V_30 . V_306 == NULL || V_30 . V_162 == NULL )
goto V_108;
V_246 = F_64 ( V_43 -> V_73 , V_43 , & V_132 , & V_308 . V_129 , & V_30 . V_130 , 1 ) ;
if ( ! V_246 ) {
F_65 ( V_145 , & V_30 . V_147 ) ;
F_154 ( V_145 , V_30 . V_162 ) ;
F_154 ( V_144 , V_30 . V_306 ) ;
}
V_108:
F_220 ( V_30 . V_162 ) ;
F_220 ( V_30 . V_306 ) ;
return V_246 ;
}
static int F_238 ( struct V_144 * V_144 , struct V_144 * V_145 , struct V_374 * V_190 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_73 ( V_144 ) ,
F_237 ( V_144 , V_145 , V_190 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static struct V_437 * F_239 ( struct V_144 * V_145 ,
struct V_374 * V_190 , struct V_173 * V_289 , T_6 V_438 )
{
struct V_437 * V_127 ;
V_127 = F_74 ( sizeof( * V_127 ) , V_301 ) ;
if ( V_127 != NULL ) {
struct V_42 * V_43 = F_73 ( V_145 ) ;
V_127 -> V_132 . V_251 = & V_252 [ V_439 ] ;
V_127 -> V_132 . V_254 = & V_127 -> V_308 ;
V_127 -> V_132 . V_255 = & V_127 -> V_30 ;
V_127 -> V_308 . V_385 = F_79 ( V_145 ) ;
V_127 -> V_308 . V_43 = V_43 ;
V_127 -> V_308 . V_190 = V_190 ;
V_127 -> V_308 . V_174 = V_289 ;
V_127 -> V_308 . V_438 = V_438 ;
V_127 -> V_308 . V_192 = V_43 -> V_193 ;
V_127 -> V_30 . V_43 = V_43 ;
V_127 -> V_30 . V_182 = & V_127 -> V_182 ;
V_127 -> V_30 . V_306 = & V_127 -> V_306 ;
V_127 -> V_30 . V_440 = & V_127 -> V_440 ;
F_69 ( V_127 -> V_30 . V_306 ) ;
F_69 ( V_127 -> V_30 . V_440 ) ;
}
return V_127 ;
}
static int F_240 ( struct V_144 * V_145 , struct V_13 * V_13 , struct V_437 * V_127 )
{
int V_246 = F_64 ( F_73 ( V_145 ) -> V_73 , F_73 ( V_145 ) , & V_127 -> V_132 ,
& V_127 -> V_308 . V_129 , & V_127 -> V_30 . V_130 , 1 ) ;
if ( V_246 == 0 ) {
F_65 ( V_145 , & V_127 -> V_30 . V_441 ) ;
F_154 ( V_145 , V_127 -> V_30 . V_440 ) ;
V_246 = F_241 ( V_13 , V_127 -> V_30 . V_182 , V_127 -> V_30 . V_306 ) ;
}
return V_246 ;
}
static void F_242 ( struct V_437 * V_127 )
{
F_81 ( V_127 ) ;
}
static int F_243 ( struct V_144 * V_145 , struct V_13 * V_13 ,
struct V_375 * V_375 , unsigned int V_365 , struct V_173 * V_289 )
{
struct V_437 * V_127 ;
int V_246 = - V_442 ;
if ( V_365 > V_443 )
goto V_108;
V_246 = - V_234 ;
V_127 = F_239 ( V_145 , & V_13 -> V_191 , V_289 , V_444 ) ;
if ( V_127 == NULL )
goto V_108;
V_127 -> V_132 . V_251 = & V_252 [ V_445 ] ;
V_127 -> V_308 . V_200 . V_446 . V_19 = & V_375 ;
V_127 -> V_308 . V_200 . V_446 . V_365 = V_365 ;
V_246 = F_240 ( V_145 , V_13 , V_127 ) ;
F_242 ( V_127 ) ;
V_108:
return V_246 ;
}
static int F_244 ( struct V_144 * V_145 , struct V_13 * V_13 ,
struct V_375 * V_375 , unsigned int V_365 , struct V_173 * V_289 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_73 ( V_145 ) ,
F_243 ( V_145 , V_13 , V_375 ,
V_365 , V_289 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_245 ( struct V_144 * V_145 , struct V_13 * V_13 ,
struct V_173 * V_289 )
{
struct V_437 * V_127 ;
int V_246 = - V_234 ;
V_127 = F_239 ( V_145 , & V_13 -> V_191 , V_289 , V_447 ) ;
if ( V_127 == NULL )
goto V_108;
V_246 = F_240 ( V_145 , V_13 , V_127 ) ;
F_242 ( V_127 ) ;
V_108:
return V_246 ;
}
static int F_246 ( struct V_144 * V_145 , struct V_13 * V_13 ,
struct V_173 * V_289 )
{
struct V_45 V_46 = { } ;
int V_1 ;
V_289 -> V_419 &= ~ F_225 () ;
do {
V_1 = F_16 ( F_73 ( V_145 ) ,
F_245 ( V_145 , V_13 , V_289 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_247 ( struct V_13 * V_13 , struct V_256 * V_298 ,
T_1 V_11 , struct V_375 * * V_19 , unsigned int V_18 , int V_448 )
{
struct V_144 * V_145 = V_13 -> V_24 ;
struct V_14 args = {
. V_182 = F_79 ( V_145 ) ,
. V_19 = V_19 ,
. V_27 = 0 ,
. V_18 = V_18 ,
. V_192 = F_73 ( V_13 -> V_24 ) -> V_193 ,
. V_448 = V_448 ,
} ;
struct V_449 V_30 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_450 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
. V_256 = V_298 ,
} ;
int V_246 ;
F_2 ( L_34 , V_9 ,
V_13 -> V_26 -> V_191 . V_190 ,
V_13 -> V_191 . V_190 ,
( unsigned long long ) V_11 ) ;
F_3 ( V_11 , F_248 ( V_145 ) , V_13 , & args ) ;
V_30 . V_27 = args . V_27 ;
V_246 = F_64 ( F_73 ( V_145 ) -> V_73 , F_73 ( V_145 ) , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
if ( V_246 >= 0 ) {
memcpy ( F_248 ( V_145 ) , V_30 . V_12 . V_127 , V_451 ) ;
V_246 += args . V_27 ;
}
F_249 ( V_145 ) ;
F_2 ( L_35 , V_9 , V_246 ) ;
return V_246 ;
}
static int F_250 ( struct V_13 * V_13 , struct V_256 * V_298 ,
T_1 V_11 , struct V_375 * * V_19 , unsigned int V_18 , int V_448 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_73 ( V_13 -> V_24 ) ,
F_247 ( V_13 , V_298 , V_11 ,
V_19 , V_18 , V_448 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_251 ( struct V_144 * V_145 , struct V_13 * V_13 ,
struct V_173 * V_289 , T_9 V_452 )
{
struct V_437 * V_127 ;
int V_206 = V_289 -> V_419 ;
int V_246 = - V_234 ;
F_4 ( ! ( V_289 -> V_292 & V_453 ) ) ;
F_4 ( ! F_252 ( V_206 ) && ! F_253 ( V_206 ) && ! F_254 ( V_206 ) && ! F_255 ( V_206 ) ) ;
V_127 = F_239 ( V_145 , & V_13 -> V_191 , V_289 , V_454 ) ;
if ( V_127 == NULL )
goto V_108;
if ( F_252 ( V_206 ) )
V_127 -> V_308 . V_438 = V_455 ;
else if ( F_253 ( V_206 ) ) {
V_127 -> V_308 . V_438 = V_456 ;
V_127 -> V_308 . V_200 . V_457 . V_458 = F_256 ( V_452 ) ;
V_127 -> V_308 . V_200 . V_457 . V_459 = F_257 ( V_452 ) ;
}
else if ( F_254 ( V_206 ) ) {
V_127 -> V_308 . V_438 = V_460 ;
V_127 -> V_308 . V_200 . V_457 . V_458 = F_256 ( V_452 ) ;
V_127 -> V_308 . V_200 . V_457 . V_459 = F_257 ( V_452 ) ;
}
V_246 = F_240 ( V_145 , V_13 , V_127 ) ;
F_242 ( V_127 ) ;
V_108:
return V_246 ;
}
static int F_258 ( struct V_144 * V_145 , struct V_13 * V_13 ,
struct V_173 * V_289 , T_9 V_452 )
{
struct V_45 V_46 = { } ;
int V_1 ;
V_289 -> V_419 &= ~ F_225 () ;
do {
V_1 = F_16 ( F_73 ( V_145 ) ,
F_251 ( V_145 , V_13 , V_289 , V_452 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_259 ( struct V_42 * V_43 , struct V_328 * V_329 ,
struct V_461 * V_462 )
{
struct V_463 args = {
. V_182 = V_329 ,
. V_192 = V_43 -> V_193 ,
} ;
struct V_464 V_30 = {
. V_462 = V_462 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_465 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
F_69 ( V_462 -> V_306 ) ;
return F_64 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
}
static int F_260 ( struct V_42 * V_43 , struct V_328 * V_329 , struct V_461 * V_462 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_259 ( V_43 , V_329 , V_462 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_261 ( struct V_42 * V_43 , struct V_328 * V_329 ,
struct V_355 * V_466 )
{
struct V_467 args = {
. V_182 = V_329 ,
. V_192 = V_43 -> V_193 ,
} ;
struct V_468 V_30 = {
. V_466 = V_466 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_469 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
return F_64 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
}
static int F_201 ( struct V_42 * V_43 , struct V_328 * V_329 , struct V_355 * V_466 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_261 ( V_43 , V_329 , V_466 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_262 ( struct V_42 * V_43 , struct V_328 * V_329 , struct V_355 * V_466 )
{
F_69 ( V_466 -> V_306 ) ;
return F_201 ( V_43 , V_329 , V_466 ) ;
}
static int F_263 ( struct V_42 * V_43 , struct V_328 * V_329 ,
struct V_470 * V_471 )
{
struct V_472 args = {
. V_182 = V_329 ,
. V_192 = V_43 -> V_193 ,
} ;
struct V_473 V_30 = {
. V_471 = V_471 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_474 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
if ( ( args . V_192 [ 0 ] & V_475 [ 0 ] ) == 0 ) {
memset ( V_471 , 0 , sizeof( * V_471 ) ) ;
return 0 ;
}
F_69 ( V_471 -> V_306 ) ;
return F_64 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
}
static int F_264 ( struct V_42 * V_43 , struct V_328 * V_329 ,
struct V_470 * V_471 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_263 ( V_43 , V_329 , V_471 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
void F_265 ( struct V_476 * V_127 )
{
F_249 ( V_127 -> V_144 ) ;
}
static int F_266 ( struct V_93 * V_94 , struct V_476 * V_127 )
{
struct V_42 * V_43 = F_73 ( V_127 -> V_144 ) ;
if ( F_180 ( V_94 , V_43 , V_127 -> args . V_477 -> V_48 ) == - V_119 ) {
F_181 ( V_94 ) ;
return - V_119 ;
}
F_265 ( V_127 ) ;
if ( V_94 -> V_141 > 0 )
F_26 ( V_43 , V_127 -> V_80 ) ;
return 0 ;
}
static int F_267 ( struct V_93 * V_94 , struct V_476 * V_127 )
{
F_2 ( L_17 , V_9 ) ;
if ( ! F_41 ( V_94 , & V_127 -> V_30 . V_130 ) )
return - V_119 ;
return V_127 -> V_478 ? V_127 -> V_478 ( V_94 , V_127 ) :
F_266 ( V_94 , V_127 ) ;
}
static void F_268 ( struct V_476 * V_127 , struct V_131 * V_132 )
{
V_127 -> V_80 = V_124 ;
V_127 -> V_478 = F_266 ;
V_132 -> V_251 = & V_252 [ V_479 ] ;
}
void F_269 ( struct V_93 * V_94 , struct V_476 * V_127 )
{
F_2 ( L_36 , V_9 ) ;
F_270 ( V_127 -> V_480 ) ;
V_127 -> V_480 = NULL ;
V_127 -> args . V_481 = V_127 -> V_482 ;
V_127 -> V_483 = NULL ;
V_127 -> args . V_182 = F_79 ( V_127 -> V_144 ) ;
V_127 -> V_478 = F_266 ;
V_94 -> V_484 = V_127 -> V_485 ;
F_271 ( V_94 , F_118 ( V_127 -> V_144 ) ) ;
}
static int F_272 ( struct V_93 * V_94 , struct V_486 * V_127 )
{
struct V_144 * V_144 = V_127 -> V_144 ;
if ( F_180 ( V_94 , F_73 ( V_144 ) , V_127 -> args . V_477 -> V_48 ) == - V_119 ) {
F_181 ( V_94 ) ;
return - V_119 ;
}
if ( V_94 -> V_141 >= 0 ) {
F_26 ( F_73 ( V_144 ) , V_127 -> V_80 ) ;
F_273 ( V_144 , V_127 -> V_30 . V_306 ) ;
}
return 0 ;
}
static int F_274 ( struct V_93 * V_94 , struct V_486 * V_127 )
{
if ( ! F_41 ( V_94 , & V_127 -> V_30 . V_130 ) )
return - V_119 ;
return V_127 -> V_487 ? V_127 -> V_487 ( V_94 , V_127 ) :
F_272 ( V_94 , V_127 ) ;
}
void F_275 ( struct V_93 * V_94 , struct V_486 * V_127 )
{
F_2 ( L_36 , V_9 ) ;
F_270 ( V_127 -> V_480 ) ;
V_127 -> V_480 = NULL ;
V_127 -> V_483 = NULL ;
V_127 -> V_487 = F_272 ;
V_127 -> args . V_182 = F_79 ( V_127 -> V_144 ) ;
V_127 -> args . V_192 = V_127 -> V_30 . V_43 -> V_195 ;
V_127 -> args . V_481 = V_127 -> V_482 ;
V_127 -> V_30 . V_306 = & V_127 -> V_306 ;
V_94 -> V_484 = V_127 -> V_485 ;
F_271 ( V_94 , F_118 ( V_127 -> V_144 ) ) ;
}
static void F_276 ( struct V_486 * V_127 , struct V_131 * V_132 )
{
struct V_42 * V_43 = F_73 ( V_127 -> V_144 ) ;
if ( V_127 -> V_480 ) {
V_127 -> args . V_192 = NULL ;
V_127 -> V_30 . V_306 = NULL ;
} else
V_127 -> args . V_192 = V_43 -> V_195 ;
if ( ! V_127 -> V_487 )
V_127 -> V_487 = F_272 ;
V_127 -> V_30 . V_43 = V_43 ;
V_127 -> V_80 = V_124 ;
V_132 -> V_251 = & V_252 [ V_488 ] ;
}
static int F_277 ( struct V_93 * V_94 , struct V_486 * V_127 )
{
struct V_144 * V_144 = V_127 -> V_144 ;
if ( F_180 ( V_94 , F_73 ( V_144 ) , NULL ) == - V_119 ) {
F_181 ( V_94 ) ;
return - V_119 ;
}
F_152 ( V_144 , V_127 -> V_30 . V_306 ) ;
return 0 ;
}
static int F_278 ( struct V_93 * V_94 , struct V_486 * V_127 )
{
if ( ! F_41 ( V_94 , & V_127 -> V_30 . V_130 ) )
return - V_119 ;
return V_127 -> V_487 ( V_94 , V_127 ) ;
}
static void F_279 ( struct V_486 * V_127 , struct V_131 * V_132 )
{
struct V_42 * V_43 = F_73 ( V_127 -> V_144 ) ;
if ( V_127 -> V_480 ) {
V_127 -> args . V_192 = NULL ;
V_127 -> V_30 . V_306 = NULL ;
} else
V_127 -> args . V_192 = V_43 -> V_195 ;
if ( ! V_127 -> V_487 )
V_127 -> V_487 = F_277 ;
V_127 -> V_30 . V_43 = V_43 ;
V_132 -> V_251 = & V_252 [ V_489 ] ;
}
static void F_280 ( void * V_125 )
{
struct V_490 * V_127 = V_125 ;
struct V_28 * V_29 = V_127 -> V_73 ;
if ( F_281 ( & V_29 -> V_491 ) > 1 )
F_282 ( V_29 ) ;
F_283 ( V_29 ) ;
F_81 ( V_127 ) ;
}
static void F_284 ( struct V_93 * V_94 , void * V_125 )
{
struct V_490 * V_127 = V_125 ;
struct V_28 * V_29 = V_127 -> V_73 ;
unsigned long V_80 = V_127 -> V_80 ;
if ( V_94 -> V_141 < 0 ) {
if ( F_31 ( V_492 , & V_29 -> V_493 ) == 0 )
return;
if ( V_94 -> V_141 != V_494 ) {
F_18 ( V_29 ) ;
return;
}
F_285 ( V_29 ) ;
}
F_22 ( V_29 , V_80 ) ;
}
static int F_286 ( struct V_28 * V_29 , struct V_256 * V_298 , unsigned V_495 )
{
struct V_131 V_132 = {
. V_251 = & V_252 [ V_496 ] ,
. V_254 = V_29 ,
. V_256 = V_298 ,
} ;
struct V_490 * V_127 ;
if ( V_495 == 0 )
return 0 ;
if ( ! F_287 ( & V_29 -> V_491 ) )
return - V_10 ;
V_127 = F_204 ( sizeof( * V_127 ) , V_243 ) ;
if ( V_127 == NULL )
return - V_234 ;
V_127 -> V_73 = V_29 ;
V_127 -> V_80 = V_124 ;
return F_288 ( V_29 -> V_497 , & V_132 , V_498 ,
& V_499 , V_127 ) ;
}
static int F_289 ( struct V_28 * V_29 , struct V_256 * V_298 )
{
struct V_131 V_132 = {
. V_251 = & V_252 [ V_496 ] ,
. V_254 = V_29 ,
. V_256 = V_298 ,
} ;
unsigned long V_500 = V_124 ;
int V_246 ;
V_246 = F_63 ( V_29 -> V_497 , & V_132 , 0 ) ;
if ( V_246 < 0 )
return V_246 ;
F_22 ( V_29 , V_500 ) ;
return 0 ;
}
static inline int F_290 ( struct V_42 * V_43 )
{
return ( V_43 -> V_76 & V_333 )
&& ( V_43 -> V_354 & V_501 )
&& ( V_43 -> V_354 & V_502 ) ;
}
static int F_291 ( const void * V_503 , T_10 V_504 ,
struct V_375 * * V_19 , unsigned int * V_27 )
{
struct V_375 * V_505 , * * V_506 ;
int V_507 = 0 ;
T_10 V_365 ;
V_506 = V_19 ;
do {
V_365 = F_292 ( T_10 , V_508 , V_504 ) ;
V_505 = F_203 ( V_301 ) ;
if ( V_505 == NULL )
goto V_509;
memcpy ( F_293 ( V_505 ) , V_503 , V_365 ) ;
V_503 += V_365 ;
V_504 -= V_365 ;
* V_19 ++ = V_505 ;
V_507 ++ ;
} while ( V_504 != 0 );
return V_507 ;
V_509:
for(; V_507 > 0 ; V_507 -- )
F_208 ( V_506 [ V_507 - 1 ] ) ;
return - V_234 ;
}
static void F_294 ( struct V_144 * V_144 , struct V_510 * V_511 )
{
struct V_148 * V_149 = F_66 ( V_144 ) ;
F_23 ( & V_144 -> V_150 ) ;
F_81 ( V_149 -> V_512 ) ;
V_149 -> V_512 = V_511 ;
F_25 ( & V_144 -> V_150 ) ;
}
static void F_295 ( struct V_144 * V_144 )
{
F_294 ( V_144 , NULL ) ;
}
static inline T_11 F_296 ( struct V_144 * V_144 , char * V_503 , T_10 V_504 )
{
struct V_148 * V_149 = F_66 ( V_144 ) ;
struct V_510 * V_511 ;
int V_49 = - V_242 ;
F_23 ( & V_144 -> V_150 ) ;
V_511 = V_149 -> V_512 ;
if ( V_511 == NULL )
goto V_108;
if ( V_503 == NULL )
goto V_513;
if ( V_511 -> V_514 == 0 )
goto V_108;
V_49 = - V_515 ;
if ( V_511 -> V_365 > V_504 )
goto V_108;
memcpy ( V_503 , V_511 -> V_127 , V_511 -> V_365 ) ;
V_513:
V_49 = V_511 -> V_365 ;
V_108:
F_25 ( & V_144 -> V_150 ) ;
return V_49 ;
}
static void F_297 ( struct V_144 * V_144 , const char * V_503 , T_10 V_516 )
{
struct V_510 * V_511 ;
if ( V_503 && V_516 <= V_517 ) {
V_511 = F_204 ( sizeof( * V_511 ) + V_516 , V_301 ) ;
if ( V_511 == NULL )
goto V_108;
V_511 -> V_514 = 1 ;
memcpy ( V_511 -> V_127 , V_503 , V_516 ) ;
} else {
V_511 = F_204 ( sizeof( * V_511 ) , V_301 ) ;
if ( V_511 == NULL )
goto V_108;
V_511 -> V_514 = 0 ;
}
V_511 -> V_365 = V_516 ;
V_108:
F_294 ( V_144 , V_511 ) ;
}
static T_11 F_298 ( struct V_144 * V_144 , void * V_503 , T_10 V_504 )
{
struct V_375 * V_19 [ V_518 ] = { NULL , } ;
struct V_519 args = {
. V_182 = F_79 ( V_144 ) ,
. V_520 = V_19 ,
. V_516 = V_504 ,
} ;
struct V_521 V_30 = {
. V_516 = V_504 ,
} ;
void * V_522 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_523 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
int V_49 = - V_234 , V_524 , V_364 , V_516 = 0 ;
V_524 = ( V_504 + V_517 - 1 ) >> V_525 ;
if ( V_524 == 0 )
V_524 = 1 ;
for ( V_364 = 0 ; V_364 < V_524 ; V_364 ++ ) {
V_19 [ V_364 ] = F_203 ( V_301 ) ;
if ( ! V_19 [ V_364 ] )
goto V_250;
}
if ( V_524 > 1 ) {
V_30 . V_526 = F_203 ( V_301 ) ;
if ( ! V_30 . V_526 )
goto V_250;
}
args . V_516 = V_524 * V_517 ;
args . V_527 = 0 ;
if ( V_503 == NULL )
V_30 . V_528 |= V_529 ;
V_522 = F_293 ( V_19 [ 0 ] ) ;
F_2 ( L_37 ,
V_9 , V_503 , V_504 , V_524 , args . V_516 ) ;
V_49 = F_64 ( F_73 ( V_144 ) -> V_73 , F_73 ( V_144 ) ,
& V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
if ( V_49 )
goto V_250;
V_516 = V_30 . V_516 - V_30 . V_530 ;
if ( V_516 > args . V_516 )
F_297 ( V_144 , NULL , V_516 ) ;
else
F_297 ( V_144 , V_522 + V_30 . V_530 ,
V_516 ) ;
if ( V_503 ) {
V_49 = - V_515 ;
if ( V_516 > V_504 )
goto V_250;
F_299 ( V_503 , V_19 , V_30 . V_530 ,
V_30 . V_516 ) ;
}
V_49 = V_516 ;
V_250:
for ( V_364 = 0 ; V_364 < V_524 ; V_364 ++ )
if ( V_19 [ V_364 ] )
F_208 ( V_19 [ V_364 ] ) ;
if ( V_30 . V_526 )
F_208 ( V_30 . V_526 ) ;
return V_49 ;
}
static T_11 F_300 ( struct V_144 * V_144 , void * V_503 , T_10 V_504 )
{
struct V_45 V_46 = { } ;
T_11 V_49 ;
do {
V_49 = F_298 ( V_144 , V_503 , V_504 ) ;
if ( V_49 >= 0 )
break;
V_49 = F_16 ( F_73 ( V_144 ) , V_49 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_49 ;
}
static T_11 F_301 ( struct V_144 * V_144 , void * V_503 , T_10 V_504 )
{
struct V_42 * V_43 = F_73 ( V_144 ) ;
int V_49 ;
if ( ! F_290 ( V_43 ) )
return - V_531 ;
V_49 = F_302 ( V_43 , V_144 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( F_66 ( V_144 ) -> V_151 & V_532 )
F_303 ( V_144 ) ;
V_49 = F_296 ( V_144 , V_503 , V_504 ) ;
if ( V_49 != - V_242 )
return V_49 ;
return F_300 ( V_144 , V_503 , V_504 ) ;
}
static int F_304 ( struct V_144 * V_144 , const void * V_503 , T_10 V_504 )
{
struct V_42 * V_43 = F_73 ( V_144 ) ;
struct V_375 * V_19 [ V_518 ] ;
struct V_533 V_308 = {
. V_182 = F_79 ( V_144 ) ,
. V_520 = V_19 ,
. V_516 = V_504 ,
} ;
struct V_534 V_30 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_535 ] ,
. V_254 = & V_308 ,
. V_255 = & V_30 ,
} ;
int V_49 , V_364 ;
if ( ! F_290 ( V_43 ) )
return - V_531 ;
V_364 = F_291 ( V_503 , V_504 , V_308 . V_520 , & V_308 . V_527 ) ;
if ( V_364 < 0 )
return V_364 ;
F_110 ( V_144 ) ;
V_49 = F_64 ( V_43 -> V_73 , V_43 , & V_132 , & V_308 . V_129 , & V_30 . V_130 , 1 ) ;
for (; V_364 > 0 ; V_364 -- )
F_305 ( V_19 [ V_364 - 1 ] ) ;
F_23 ( & V_144 -> V_150 ) ;
F_66 ( V_144 ) -> V_151 |= V_152 ;
F_25 ( & V_144 -> V_150 ) ;
F_306 ( V_144 ) ;
F_303 ( V_144 ) ;
return V_49 ;
}
static int F_307 ( struct V_144 * V_144 , const void * V_503 , T_10 V_504 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_73 ( V_144 ) ,
F_304 ( V_144 , V_503 , V_504 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_180 ( struct V_93 * V_94 , const struct V_42 * V_43 , struct V_47 * V_48 )
{
struct V_28 * V_29 = V_43 -> V_28 ;
if ( V_94 -> V_141 >= 0 )
return 0 ;
switch( V_94 -> V_141 ) {
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
F_2 ( L_38 , V_9 ,
V_94 -> V_141 ) ;
F_20 ( V_29 -> V_66 ) ;
V_94 -> V_141 = 0 ;
return - V_119 ;
#endif
case - V_71 :
F_308 ( V_43 , V_536 ) ;
case - V_70 :
case - V_72 :
F_40 ( V_94 , V_39 ) ;
V_94 -> V_141 = 0 ;
return - V_119 ;
case - V_74 :
case - V_75 :
V_94 -> V_141 = 0 ;
return - V_119 ;
}
V_94 -> V_141 = F_1 ( V_94 -> V_141 ) ;
return 0 ;
V_54:
F_48 ( & V_29 -> V_537 , V_94 , NULL ) ;
if ( F_31 ( V_32 , & V_29 -> V_31 ) == 0 )
F_309 ( & V_29 -> V_537 , V_94 ) ;
V_94 -> V_141 = 0 ;
return - V_119 ;
}
int F_310 ( struct V_28 * V_29 , T_6 V_538 ,
unsigned short V_539 , struct V_256 * V_298 ,
struct V_540 * V_30 )
{
T_12 V_541 ;
struct V_542 V_543 = {
. V_541 = & V_541 ,
. V_544 = V_538 ,
. V_545 = V_29 -> V_546 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_547 ] ,
. V_254 = & V_543 ,
. V_255 = V_30 ,
. V_256 = V_298 ,
} ;
T_2 * V_17 ;
int V_285 = 0 ;
int V_246 ;
V_17 = ( T_2 * ) V_541 . V_127 ;
* V_17 ++ = F_6 ( ( T_6 ) V_29 -> V_548 . V_549 ) ;
* V_17 = F_6 ( ( T_6 ) V_29 -> V_548 . V_550 ) ;
for(; ; ) {
V_543 . V_551 = F_311 ( V_543 . V_552 ,
sizeof( V_543 . V_552 ) , L_39 ,
V_29 -> V_553 ,
F_312 ( V_29 -> V_497 ,
V_554 ) ,
F_312 ( V_29 -> V_497 ,
V_555 ) ,
V_29 -> V_497 -> V_556 -> V_557 -> V_558 ,
V_29 -> V_559 ) ;
V_543 . V_560 = F_311 ( V_543 . V_561 ,
sizeof( V_543 . V_561 ) ,
F_312 ( V_29 -> V_497 ,
V_562 ) ) ;
V_543 . V_563 = F_311 ( V_543 . V_564 ,
sizeof( V_543 . V_564 ) , L_40 ,
V_29 -> V_553 , V_539 >> 8 , V_539 & 255 ) ;
V_246 = F_63 ( V_29 -> V_497 , & V_132 , V_565 ) ;
if ( V_246 != - V_566 )
break;
if ( V_285 != 0 ) {
++ V_29 -> V_559 ;
break;
}
++ V_285 ;
F_313 ( V_29 -> V_567 / V_68 + 1 ) ;
}
return V_246 ;
}
int F_314 ( struct V_28 * V_29 ,
struct V_540 * V_308 ,
struct V_256 * V_298 )
{
struct V_355 V_466 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_568 ] ,
. V_254 = V_308 ,
. V_255 = & V_466 ,
. V_256 = V_298 ,
} ;
unsigned long V_500 ;
int V_246 ;
V_500 = V_124 ;
V_246 = F_63 ( V_29 -> V_497 , & V_132 , V_565 ) ;
if ( V_246 == 0 ) {
F_23 ( & V_29 -> V_81 ) ;
V_29 -> V_567 = V_466 . V_569 * V_68 ;
V_29 -> V_82 = V_500 ;
F_25 ( & V_29 -> V_81 ) ;
}
return V_246 ;
}
static void F_315 ( struct V_93 * V_94 , void * V_125 )
{
struct V_570 * V_127 = V_125 ;
if ( ! F_41 ( V_94 , & V_127 -> V_30 . V_130 ) )
return;
switch ( V_94 -> V_141 ) {
case - V_56 :
case - V_55 :
case 0 :
F_26 ( V_127 -> V_30 . V_43 , V_127 -> V_80 ) ;
break;
default:
if ( F_180 ( V_94 , V_127 -> V_30 . V_43 , NULL ) ==
- V_119 ) {
F_181 ( V_94 ) ;
return;
}
}
V_127 -> V_248 = V_94 -> V_141 ;
}
static void F_316 ( void * V_125 )
{
F_81 ( V_125 ) ;
}
static void F_317 ( struct V_93 * V_94 , void * V_127 )
{
struct V_570 * V_571 ;
V_571 = (struct V_570 * ) V_127 ;
if ( F_50 ( V_571 -> V_30 . V_43 ,
& V_571 -> args . V_129 ,
& V_571 -> V_30 . V_130 , 1 , V_94 ) )
return;
F_53 ( V_94 ) ;
}
static int F_318 ( struct V_144 * V_144 , struct V_256 * V_298 , const T_7 * V_202 , int V_572 )
{
struct V_570 * V_127 ;
struct V_42 * V_43 = F_73 ( V_144 ) ;
struct V_93 * V_94 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_573 ] ,
. V_256 = V_298 ,
} ;
struct V_134 V_257 = {
. V_136 = V_43 -> V_73 ,
. V_131 = & V_132 ,
. V_137 = & V_574 ,
. V_172 = V_261 ,
} ;
int V_246 = 0 ;
V_127 = F_74 ( sizeof( * V_127 ) , V_243 ) ;
if ( V_127 == NULL )
return - V_234 ;
V_127 -> args . V_329 = & V_127 -> V_182 ;
V_127 -> args . V_202 = & V_127 -> V_202 ;
V_127 -> args . V_192 = V_43 -> V_193 ;
F_146 ( & V_127 -> V_182 , F_79 ( V_144 ) ) ;
memcpy ( & V_127 -> V_202 , V_202 , sizeof( V_127 -> V_202 ) ) ;
V_127 -> V_30 . V_306 = & V_127 -> V_306 ;
V_127 -> V_30 . V_43 = V_43 ;
F_69 ( V_127 -> V_30 . V_306 ) ;
V_127 -> V_80 = V_124 ;
V_127 -> V_248 = 0 ;
V_257 . V_139 = V_127 ;
V_132 . V_254 = & V_127 -> args ;
V_132 . V_255 = & V_127 -> V_30 ;
V_94 = F_57 ( & V_257 ) ;
if ( F_58 ( V_94 ) )
return F_59 ( V_94 ) ;
if ( ! V_572 )
goto V_108;
V_246 = F_92 ( V_94 ) ;
if ( V_246 != 0 )
goto V_108;
V_246 = V_127 -> V_248 ;
if ( V_246 != 0 )
goto V_108;
F_152 ( V_144 , & V_127 -> V_306 ) ;
V_108:
F_60 ( V_94 ) ;
return V_246 ;
}
int F_319 ( struct V_144 * V_144 , struct V_256 * V_298 , const T_7 * V_202 , int V_572 )
{
struct V_42 * V_43 = F_73 ( V_144 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_318 ( V_144 , V_298 , V_202 , V_572 ) ;
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
F_320 ( unsigned long V_37 )
{
F_14 ( V_37 ) ;
V_37 <<= 1 ;
if ( V_37 > V_575 )
return V_575 ;
return V_37 ;
}
static int F_321 ( struct V_47 * V_48 , int V_576 , struct V_577 * V_578 )
{
struct V_144 * V_144 = V_48 -> V_144 ;
struct V_42 * V_43 = F_73 ( V_144 ) ;
struct V_28 * V_29 = V_43 -> V_28 ;
struct V_579 V_308 = {
. V_182 = F_79 ( V_144 ) ,
. V_580 = V_578 ,
} ;
struct V_581 V_30 = {
. V_582 = V_578 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_583 ] ,
. V_254 = & V_308 ,
. V_255 = & V_30 ,
. V_256 = V_48 -> V_180 -> V_230 ,
} ;
struct V_584 * V_585 ;
int V_246 ;
V_308 . V_586 . V_186 = V_29 -> V_187 ;
V_246 = F_322 ( V_48 , V_578 ) ;
if ( V_246 != 0 )
goto V_108;
V_585 = V_578 -> V_587 . V_588 . V_180 ;
V_308 . V_586 . V_188 = V_585 -> V_589 . V_188 ;
V_308 . V_586 . V_590 = V_43 -> V_590 ;
V_246 = F_64 ( V_43 -> V_73 , V_43 , & V_132 , & V_308 . V_129 , & V_30 . V_130 , 1 ) ;
switch ( V_246 ) {
case 0 :
V_578 -> V_591 = V_592 ;
break;
case - V_593 :
V_246 = 0 ;
}
V_578 -> V_594 -> V_595 ( V_578 ) ;
V_108:
return V_246 ;
}
static int F_323 ( struct V_47 * V_48 , int V_576 , struct V_577 * V_578 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_73 ( V_48 -> V_144 ) ,
F_321 ( V_48 , V_576 , V_578 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_324 ( struct V_596 * V_596 , struct V_577 * V_580 )
{
int V_30 = 0 ;
switch ( V_580 -> V_597 & ( V_598 | V_599 ) ) {
case V_598 :
V_30 = F_325 ( V_596 , V_580 ) ;
break;
case V_599 :
V_30 = F_326 ( V_596 , V_580 ) ;
break;
default:
F_327 () ;
}
return V_30 ;
}
static struct V_600 * F_328 ( struct V_577 * V_580 ,
struct V_240 * V_241 ,
struct V_584 * V_585 ,
struct V_601 * V_163 )
{
struct V_600 * V_17 ;
struct V_144 * V_144 = V_585 -> V_602 -> V_144 ;
V_17 = F_74 ( sizeof( * V_17 ) , V_243 ) ;
if ( V_17 == NULL )
return NULL ;
V_17 -> V_308 . V_182 = F_79 ( V_144 ) ;
V_17 -> V_308 . V_580 = & V_17 -> V_580 ;
V_17 -> V_308 . V_163 = V_163 ;
V_17 -> V_30 . V_163 = V_163 ;
V_17 -> V_308 . V_202 = & V_585 -> V_603 ;
V_17 -> V_585 = V_585 ;
F_78 ( & V_585 -> V_604 ) ;
V_17 -> V_241 = F_124 ( V_241 ) ;
memcpy ( & V_17 -> V_580 , V_580 , sizeof( V_17 -> V_580 ) ) ;
V_17 -> V_43 = F_73 ( V_144 ) ;
return V_17 ;
}
static void F_329 ( void * V_127 )
{
struct V_600 * V_125 = V_127 ;
F_85 ( V_125 -> V_308 . V_163 ) ;
F_330 ( V_125 -> V_585 ) ;
F_135 ( V_125 -> V_241 ) ;
F_81 ( V_125 ) ;
}
static void F_331 ( struct V_93 * V_94 , void * V_127 )
{
struct V_600 * V_125 = V_127 ;
if ( ! F_41 ( V_94 , & V_125 -> V_30 . V_130 ) )
return;
switch ( V_94 -> V_141 ) {
case 0 :
memcpy ( V_125 -> V_585 -> V_603 . V_127 ,
V_125 -> V_30 . V_202 . V_127 ,
sizeof( V_125 -> V_585 -> V_603 . V_127 ) ) ;
F_26 ( V_125 -> V_43 , V_125 -> V_80 ) ;
break;
case - V_52 :
case - V_75 :
case - V_56 :
case - V_55 :
break;
default:
if ( F_180 ( V_94 , V_125 -> V_43 , NULL ) == - V_119 )
F_181 ( V_94 ) ;
}
}
static void F_332 ( struct V_93 * V_94 , void * V_127 )
{
struct V_600 * V_125 = V_127 ;
if ( F_145 ( V_125 -> V_308 . V_163 , V_94 ) != 0 )
return;
if ( ( V_125 -> V_585 -> V_605 & V_606 ) == 0 ) {
V_94 -> V_267 = NULL ;
return;
}
V_125 -> V_80 = V_124 ;
if ( F_50 ( V_125 -> V_43 ,
& V_125 -> V_308 . V_129 ,
& V_125 -> V_30 . V_130 , 1 , V_94 ) )
return;
F_53 ( V_94 ) ;
}
static struct V_93 * F_333 ( struct V_577 * V_580 ,
struct V_240 * V_241 ,
struct V_584 * V_585 ,
struct V_601 * V_163 )
{
struct V_600 * V_127 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_607 ] ,
. V_256 = V_241 -> V_298 ,
} ;
struct V_134 V_257 = {
. V_136 = F_118 ( V_585 -> V_602 -> V_144 ) ,
. V_131 = & V_132 ,
. V_137 = & V_608 ,
. V_259 = V_260 ,
. V_172 = V_261 ,
} ;
V_580 -> V_591 = V_592 ;
V_127 = F_328 ( V_580 , V_241 , V_585 , V_163 ) ;
if ( V_127 == NULL ) {
F_85 ( V_163 ) ;
return F_113 ( - V_234 ) ;
}
V_132 . V_254 = & V_127 -> V_308 ;
V_132 . V_255 = & V_127 -> V_30 ;
V_257 . V_139 = V_127 ;
return F_57 ( & V_257 ) ;
}
static int F_334 ( struct V_47 * V_48 , int V_576 , struct V_577 * V_578 )
{
struct V_148 * V_149 = F_66 ( V_48 -> V_144 ) ;
struct V_601 * V_163 ;
struct V_584 * V_585 ;
struct V_93 * V_94 ;
int V_246 = 0 ;
unsigned char V_597 = V_578 -> V_597 ;
V_246 = F_322 ( V_48 , V_578 ) ;
V_578 -> V_597 |= V_609 ;
F_335 ( & V_149 -> V_610 ) ;
if ( F_324 ( V_578 -> V_611 , V_578 ) == - V_242 ) {
F_336 ( & V_149 -> V_610 ) ;
goto V_108;
}
F_336 ( & V_149 -> V_610 ) ;
if ( V_246 != 0 )
goto V_108;
if ( F_31 ( V_218 , & V_48 -> V_172 ) )
goto V_108;
V_585 = V_578 -> V_587 . V_588 . V_180 ;
V_163 = F_75 ( & V_585 -> V_612 , V_301 ) ;
V_246 = - V_234 ;
if ( V_163 == NULL )
goto V_108;
V_94 = F_333 ( V_578 , F_213 ( V_578 -> V_611 ) , V_585 , V_163 ) ;
V_246 = F_59 ( V_94 ) ;
if ( F_58 ( V_94 ) )
goto V_108;
V_246 = F_92 ( V_94 ) ;
F_60 ( V_94 ) ;
V_108:
V_578 -> V_597 = V_597 ;
return V_246 ;
}
static struct V_613 * F_337 ( struct V_577 * V_580 ,
struct V_240 * V_241 , struct V_584 * V_585 ,
T_5 V_175 )
{
struct V_613 * V_17 ;
struct V_144 * V_144 = V_585 -> V_602 -> V_144 ;
struct V_42 * V_43 = F_73 ( V_144 ) ;
V_17 = F_74 ( sizeof( * V_17 ) , V_175 ) ;
if ( V_17 == NULL )
return NULL ;
V_17 -> V_308 . V_182 = F_79 ( V_144 ) ;
V_17 -> V_308 . V_580 = & V_17 -> V_580 ;
V_17 -> V_308 . V_614 = F_75 ( & V_585 -> V_602 -> V_180 -> V_177 , V_175 ) ;
if ( V_17 -> V_308 . V_614 == NULL )
goto V_250;
V_17 -> V_308 . V_615 = F_75 ( & V_585 -> V_612 , V_175 ) ;
if ( V_17 -> V_308 . V_615 == NULL )
goto V_616;
V_17 -> V_308 . V_617 = & V_585 -> V_603 ;
V_17 -> V_308 . V_586 . V_186 = V_43 -> V_28 -> V_187 ;
V_17 -> V_308 . V_586 . V_188 = V_585 -> V_589 . V_188 ;
V_17 -> V_308 . V_586 . V_590 = V_43 -> V_590 ;
V_17 -> V_30 . V_615 = V_17 -> V_308 . V_615 ;
V_17 -> V_585 = V_585 ;
V_17 -> V_43 = V_43 ;
F_78 ( & V_585 -> V_604 ) ;
V_17 -> V_241 = F_124 ( V_241 ) ;
memcpy ( & V_17 -> V_580 , V_580 , sizeof( V_17 -> V_580 ) ) ;
return V_17 ;
V_616:
F_85 ( V_17 -> V_308 . V_614 ) ;
V_250:
F_81 ( V_17 ) ;
return NULL ;
}
static void F_338 ( struct V_93 * V_94 , void * V_125 )
{
struct V_613 * V_127 = V_125 ;
struct V_47 * V_48 = V_127 -> V_585 -> V_602 ;
F_2 ( L_41 , V_9 ) ;
if ( F_145 ( V_127 -> V_308 . V_615 , V_94 ) != 0 )
return;
if ( ! ( V_127 -> V_308 . V_615 -> V_618 -> V_172 & V_619 ) ) {
if ( F_145 ( V_127 -> V_308 . V_614 , V_94 ) != 0 )
return;
V_127 -> V_308 . V_219 = & V_48 -> V_202 ;
V_127 -> V_308 . V_620 = 1 ;
V_127 -> V_30 . V_614 = V_127 -> V_308 . V_614 ;
} else
V_127 -> V_308 . V_620 = 0 ;
V_127 -> V_80 = V_124 ;
if ( F_50 ( V_127 -> V_43 ,
& V_127 -> V_308 . V_129 ,
& V_127 -> V_30 . V_130 , 1 , V_94 ) )
return;
F_53 ( V_94 ) ;
F_2 ( L_42 , V_9 , V_127 -> V_248 ) ;
}
static void F_339 ( struct V_93 * V_94 , void * V_125 )
{
F_33 ( V_94 , V_99 ) ;
F_338 ( V_94 , V_125 ) ;
}
static void F_340 ( struct V_93 * V_94 , void * V_125 )
{
struct V_613 * V_127 = V_125 ;
F_2 ( L_41 , V_9 ) ;
if ( ! F_41 ( V_94 , & V_127 -> V_30 . V_130 ) )
return;
V_127 -> V_248 = V_94 -> V_141 ;
if ( V_127 -> V_308 . V_620 != 0 ) {
if ( V_127 -> V_248 == 0 )
F_139 ( & V_127 -> V_585 -> V_612 , 0 ) ;
else
goto V_108;
}
if ( V_127 -> V_248 == 0 ) {
memcpy ( V_127 -> V_585 -> V_603 . V_127 , V_127 -> V_30 . V_202 . V_127 ,
sizeof( V_127 -> V_585 -> V_603 . V_127 ) ) ;
V_127 -> V_585 -> V_605 |= V_606 ;
F_26 ( F_73 ( V_127 -> V_241 -> V_13 -> V_24 ) , V_127 -> V_80 ) ;
}
V_108:
F_2 ( L_43 , V_9 , V_127 -> V_248 ) ;
}
static void F_341 ( void * V_125 )
{
struct V_613 * V_127 = V_125 ;
F_2 ( L_41 , V_9 ) ;
F_85 ( V_127 -> V_308 . V_614 ) ;
if ( V_127 -> V_249 != 0 ) {
struct V_93 * V_94 ;
V_94 = F_333 ( & V_127 -> V_580 , V_127 -> V_241 , V_127 -> V_585 ,
V_127 -> V_308 . V_615 ) ;
if ( ! F_58 ( V_94 ) )
F_342 ( V_94 ) ;
F_2 ( L_44 , V_9 ) ;
} else
F_85 ( V_127 -> V_308 . V_615 ) ;
F_330 ( V_127 -> V_585 ) ;
F_135 ( V_127 -> V_241 ) ;
F_81 ( V_127 ) ;
F_2 ( L_45 , V_9 ) ;
}
static void F_343 ( struct V_42 * V_43 , struct V_584 * V_585 , int V_620 , int error )
{
switch ( error ) {
case - V_51 :
case - V_52 :
V_585 -> V_612 . V_172 &= ~ V_619 ;
if ( V_620 != 0 ||
( V_585 -> V_605 & V_606 ) != 0 )
F_17 ( V_43 , V_585 -> V_602 ) ;
break;
case - V_56 :
V_585 -> V_612 . V_172 &= ~ V_619 ;
case - V_55 :
F_18 ( V_43 -> V_28 ) ;
} ;
}
static int F_344 ( struct V_47 * V_48 , int V_576 , struct V_577 * V_580 , int V_621 )
{
struct V_613 * V_127 ;
struct V_93 * V_94 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_622 ] ,
. V_256 = V_48 -> V_180 -> V_230 ,
} ;
struct V_134 V_257 = {
. V_136 = F_118 ( V_48 -> V_144 ) ,
. V_131 = & V_132 ,
. V_137 = & V_623 ,
. V_259 = V_260 ,
. V_172 = V_261 ,
} ;
int V_49 ;
F_2 ( L_41 , V_9 ) ;
V_127 = F_337 ( V_580 , F_213 ( V_580 -> V_611 ) ,
V_580 -> V_587 . V_588 . V_180 ,
V_621 == V_624 ? V_301 : V_243 ) ;
if ( V_127 == NULL )
return - V_234 ;
if ( F_345 ( V_576 ) )
V_127 -> V_308 . V_625 = 1 ;
if ( V_621 > V_624 ) {
if ( V_621 == V_626 )
V_127 -> V_308 . V_627 = V_626 ;
V_257 . V_137 = & V_628 ;
}
V_132 . V_254 = & V_127 -> V_308 ;
V_132 . V_255 = & V_127 -> V_30 ;
V_257 . V_139 = V_127 ;
V_94 = F_57 ( & V_257 ) ;
if ( F_58 ( V_94 ) )
return F_59 ( V_94 ) ;
V_49 = F_92 ( V_94 ) ;
if ( V_49 == 0 ) {
V_49 = V_127 -> V_248 ;
if ( V_49 )
F_343 ( V_127 -> V_43 , V_127 -> V_585 ,
V_127 -> V_308 . V_620 , V_49 ) ;
} else
V_127 -> V_249 = 1 ;
F_60 ( V_94 ) ;
F_2 ( L_43 , V_9 , V_49 ) ;
return V_49 ;
}
static int F_346 ( struct V_47 * V_48 , struct V_577 * V_578 )
{
struct V_42 * V_43 = F_73 ( V_48 -> V_144 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
if ( F_31 ( V_218 , & V_48 -> V_172 ) != 0 )
return 0 ;
V_1 = F_344 ( V_48 , V_629 , V_578 , V_626 ) ;
if ( V_1 != - V_71 )
break;
F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_347 ( struct V_47 * V_48 , struct V_577 * V_578 )
{
struct V_42 * V_43 = F_73 ( V_48 -> V_144 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
V_1 = F_322 ( V_48 , V_578 ) ;
if ( V_1 != 0 )
return V_1 ;
do {
if ( F_31 ( V_218 , & V_48 -> V_172 ) != 0 )
return 0 ;
V_1 = F_344 ( V_48 , V_629 , V_578 , V_630 ) ;
switch ( V_1 ) {
default:
goto V_108;
case - V_70 :
case - V_71 :
F_16 ( V_43 , V_1 , & V_46 ) ;
V_1 = 0 ;
}
} while ( V_46 . V_50 );
V_108:
return V_1 ;
}
static int F_348 ( struct V_47 * V_48 , struct V_577 * V_578 )
{
int V_246 ;
struct V_42 * V_43 = F_73 ( V_48 -> V_144 ) ;
V_246 = F_164 ( V_43 , V_48 ) ;
if ( V_246 == V_107 )
return 0 ;
F_165 ( V_43 , V_48 ) ;
return F_347 ( V_48 , V_578 ) ;
}
static int F_349 ( struct V_47 * V_48 , int V_576 , struct V_577 * V_578 )
{
struct V_148 * V_149 = F_66 ( V_48 -> V_144 ) ;
unsigned char V_597 = V_578 -> V_597 ;
int V_246 = - V_631 ;
if ( ( V_597 & V_598 ) &&
! F_31 ( V_303 , & V_48 -> V_172 ) )
goto V_108;
V_246 = F_322 ( V_48 , V_578 ) ;
if ( V_246 != 0 )
goto V_108;
V_578 -> V_597 |= V_632 ;
V_246 = F_324 ( V_578 -> V_611 , V_578 ) ;
if ( V_246 < 0 )
goto V_108;
F_335 ( & V_149 -> V_610 ) ;
if ( F_31 ( V_218 , & V_48 -> V_172 ) ) {
V_578 -> V_597 = V_597 & ~ V_633 ;
V_246 = F_324 ( V_578 -> V_611 , V_578 ) ;
goto V_634;
}
V_246 = F_344 ( V_48 , V_576 , V_578 , V_624 ) ;
if ( V_246 != 0 )
goto V_634;
V_578 -> V_597 = V_597 | V_633 ;
if ( F_324 ( V_578 -> V_611 , V_578 ) < 0 )
F_21 ( V_78 L_46 , V_9 ) ;
V_634:
F_336 ( & V_149 -> V_610 ) ;
V_108:
V_578 -> V_597 = V_597 ;
return V_246 ;
}
static int F_350 ( struct V_47 * V_48 , int V_576 , struct V_577 * V_578 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_349 ( V_48 , V_576 , V_578 ) ;
if ( V_1 == - V_593 )
V_1 = - V_119 ;
V_1 = F_16 ( F_73 ( V_48 -> V_144 ) ,
V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_351 ( struct V_596 * V_635 , int V_576 , struct V_577 * V_578 )
{
struct V_240 * V_241 ;
struct V_47 * V_48 ;
unsigned long V_37 = V_636 ;
int V_246 ;
V_241 = F_213 ( V_635 ) ;
V_48 = V_241 -> V_48 ;
if ( V_578 -> V_637 < 0 || V_578 -> V_638 < 0 )
return - V_8 ;
if ( F_352 ( V_576 ) ) {
if ( V_48 != NULL )
return F_323 ( V_48 , V_639 , V_578 ) ;
return 0 ;
}
if ( ! ( F_353 ( V_576 ) || F_345 ( V_576 ) ) )
return - V_8 ;
if ( V_578 -> V_591 == V_592 ) {
if ( V_48 != NULL )
return F_334 ( V_48 , V_576 , V_578 ) ;
return 0 ;
}
if ( V_48 == NULL )
return - V_631 ;
do {
V_246 = F_350 ( V_48 , V_576 , V_578 ) ;
if ( ( V_246 != - V_119 ) || F_353 ( V_576 ) )
break;
V_37 = F_320 ( V_37 ) ;
V_246 = - V_41 ;
if ( F_354 () )
break;
} while( V_246 < 0 );
return V_246 ;
}
int F_355 ( struct V_47 * V_48 , struct V_577 * V_580 )
{
struct V_42 * V_43 = F_73 ( V_48 -> V_144 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
V_1 = F_322 ( V_48 , V_580 ) ;
if ( V_1 != 0 )
goto V_108;
do {
V_1 = F_344 ( V_48 , V_629 , V_580 , V_624 ) ;
switch ( V_1 ) {
default:
F_21 ( V_640 L_47 ,
V_9 , V_1 ) ;
case 0 :
case - V_245 :
goto V_108;
case - V_55 :
F_17 ( V_43 , V_48 ) ;
case - V_57 :
case - V_56 :
F_18 ( V_43 -> V_28 ) ;
goto V_108;
case - V_59 :
case - V_60 :
case - V_61 :
case - V_62 :
case - V_63 :
F_20 ( V_43 -> V_28 -> V_66 ) ;
goto V_108;
case - V_41 :
case - V_51 :
case - V_52 :
case - V_53 :
F_17 ( V_43 , V_48 ) ;
V_1 = 0 ;
goto V_108;
case - V_72 :
V_1 = 0 ;
goto V_108;
case - V_234 :
case - V_593 :
V_1 = 0 ;
goto V_108;
case - V_71 :
break;
}
V_1 = F_16 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_50 );
V_108:
return V_1 ;
}
static void F_356 ( void * V_125 )
{
F_81 ( V_125 ) ;
}
void F_357 ( const struct V_584 * V_585 )
{
struct V_42 * V_43 = V_585 -> V_602 -> V_180 -> V_264 ;
struct V_641 * args ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_642 ] ,
} ;
if ( V_43 -> V_28 -> V_142 -> V_370 != 0 )
return;
args = F_204 ( sizeof( * args ) , V_243 ) ;
if ( ! args )
return;
args -> V_586 . V_186 = V_43 -> V_28 -> V_187 ;
args -> V_586 . V_188 = V_585 -> V_589 . V_188 ;
args -> V_586 . V_590 = V_43 -> V_590 ;
V_132 . V_254 = args ;
F_288 ( V_43 -> V_73 , & V_132 , 0 , & V_643 , args ) ;
}
static int F_358 ( struct V_13 * V_13 , const char * V_644 ,
const void * V_503 , T_10 V_504 ,
int V_172 , int type )
{
if ( strcmp ( V_644 , L_48 ) != 0 )
return - V_8 ;
return F_307 ( V_13 -> V_24 , V_503 , V_504 ) ;
}
static int F_359 ( struct V_13 * V_13 , const char * V_644 ,
void * V_503 , T_10 V_504 , int type )
{
if ( strcmp ( V_644 , L_48 ) != 0 )
return - V_8 ;
return F_301 ( V_13 -> V_24 , V_503 , V_504 ) ;
}
static T_10 F_360 ( struct V_13 * V_13 , char * V_645 ,
T_10 V_646 , const char * V_190 ,
T_10 V_647 , int type )
{
T_10 V_365 = sizeof( V_648 ) ;
if ( ! F_290 ( F_73 ( V_13 -> V_24 ) ) )
return 0 ;
if ( V_645 && V_365 <= V_646 )
memcpy ( V_645 , V_648 , V_365 ) ;
return V_365 ;
}
static void F_207 ( struct V_305 * V_306 )
{
if ( ! ( ( ( V_306 -> V_232 & V_649 ) ||
( V_306 -> V_232 & V_650 ) ) &&
( V_306 -> V_232 & V_391 ) &&
( V_306 -> V_232 & V_651 ) ) )
return;
V_306 -> V_232 |= V_388 | V_389 |
V_390 ;
V_306 -> V_206 = V_272 | V_393 | V_394 ;
V_306 -> V_395 = 2 ;
}
int F_205 ( struct V_144 * V_145 , const struct V_374 * V_190 ,
struct V_376 * V_652 , struct V_375 * V_375 )
{
struct V_42 * V_43 = F_73 ( V_145 ) ;
T_6 V_192 [ 2 ] = {
[ 0 ] = V_653 | V_654 ,
} ;
struct V_655 args = {
. V_385 = F_79 ( V_145 ) ,
. V_190 = V_190 ,
. V_375 = V_375 ,
. V_192 = V_192 ,
} ;
struct V_656 V_30 = {
. V_652 = V_652 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_657 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
int V_246 ;
F_2 ( L_49 , V_9 ) ;
if ( F_73 ( V_145 ) -> V_193 [ 1 ] & V_658 )
V_192 [ 1 ] |= V_658 ;
else
V_192 [ 0 ] |= V_23 ;
F_69 ( & V_652 -> V_306 ) ;
V_652 -> V_43 = V_43 ;
V_652 -> V_659 = 0 ;
V_246 = F_64 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
F_2 ( L_50 , V_9 , V_246 ) ;
return V_246 ;
}
static int F_361 ( struct V_144 * V_145 , const struct V_374 * V_190 , struct V_660 * V_661 )
{
int V_246 ;
struct V_662 args = {
. V_385 = F_79 ( V_145 ) ,
. V_190 = V_190 ,
} ;
struct V_663 V_30 = {
. V_661 = V_661 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_664 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
F_2 ( L_51 , V_190 -> V_190 ) ;
V_246 = F_64 ( F_73 ( V_145 ) -> V_73 , F_73 ( V_145 ) , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
F_2 ( L_52 , V_246 ) ;
return V_246 ;
}
int F_362 ( struct V_144 * V_145 , const struct V_374 * V_190 , struct V_660 * V_661 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_73 ( V_145 ) ,
F_361 ( V_145 , V_190 , V_661 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_363 ( T_6 V_172 )
{
if ( V_172 & ~ V_665 )
goto V_666;
if ( ( V_172 & V_667 ) &&
( V_172 & V_668 ) )
goto V_666;
if ( ! ( V_172 & ( V_669 ) ) )
goto V_666;
return V_107 ;
V_666:
return - V_670 ;
}
static bool
F_364 ( struct V_671 * V_672 , struct V_671 * V_673 )
{
if ( V_672 -> V_674 == V_673 -> V_674 &&
memcmp ( V_672 -> V_671 , V_673 -> V_671 , V_672 -> V_674 ) == 0 )
return true ;
return false ;
}
int F_365 ( struct V_28 * V_29 , struct V_256 * V_298 )
{
T_12 V_12 ;
struct V_675 args = {
. V_73 = V_29 ,
. V_172 = V_676 ,
} ;
struct V_677 V_30 = {
. V_73 = V_29 ,
} ;
int V_246 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_678 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
. V_256 = V_298 ,
} ;
T_2 * V_17 ;
F_2 ( L_17 , V_9 ) ;
F_4 ( V_29 == NULL ) ;
V_17 = ( T_6 * ) V_12 . V_127 ;
* V_17 ++ = F_6 ( ( T_6 ) V_29 -> V_548 . V_549 ) ;
* V_17 = F_6 ( ( T_6 ) V_29 -> V_548 . V_550 ) ;
args . V_12 = & V_12 ;
args . V_679 = F_311 ( args . V_188 , sizeof( args . V_188 ) ,
L_53 ,
V_29 -> V_553 ,
F_366 () -> V_680 ,
F_366 () -> V_681 ,
V_29 -> V_497 -> V_556 -> V_682 ) ;
V_30 . V_671 = F_74 ( sizeof( struct V_671 ) , V_301 ) ;
if ( F_367 ( ! V_30 . V_671 ) ) {
V_246 = - V_234 ;
goto V_108;
}
V_246 = F_63 ( V_29 -> V_497 , & V_132 , V_565 ) ;
if ( ! V_246 )
V_246 = F_363 ( V_29 -> V_683 ) ;
if ( ! V_246 ) {
if ( V_29 -> V_671 &&
! F_364 ( V_29 -> V_671 ,
V_30 . V_671 ) ) {
F_2 ( L_54 ,
V_9 ) ;
F_100 ( V_684 , & V_29 -> V_31 ) ;
F_81 ( V_29 -> V_671 ) ;
V_29 -> V_671 = NULL ;
}
if ( ! V_29 -> V_671 ) {
V_29 -> V_671 = V_30 . V_671 ;
goto V_108;
}
}
F_81 ( V_30 . V_671 ) ;
V_108:
F_2 ( L_55 , V_9 , V_246 ) ;
return V_246 ;
}
static void F_368 ( struct V_93 * V_94 ,
void * V_125 )
{
int V_49 ;
struct V_685 * V_127 =
(struct V_685 * ) V_125 ;
F_2 ( L_17 , V_9 ) ;
F_33 ( V_94 , V_99 ) ;
V_49 = F_46 ( V_127 -> V_29 -> V_66 ,
& V_127 -> args -> V_686 ,
& V_127 -> V_30 -> V_687 , 0 , V_94 ) ;
F_4 ( V_49 == - V_119 ) ;
F_53 ( V_94 ) ;
F_2 ( L_56 , V_9 ) ;
}
static void F_369 ( struct V_93 * V_94 , void * V_125 )
{
struct V_685 * V_127 =
(struct V_685 * ) V_125 ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_37 ( V_94 , & V_127 -> V_30 -> V_687 ) )
return;
switch ( V_94 -> V_141 ) {
case - V_71 :
case - V_70 :
F_2 ( L_57 , V_9 , V_94 -> V_141 ) ;
F_40 ( V_94 , V_38 ) ;
V_94 -> V_141 = 0 ;
case - V_74 :
F_181 ( V_94 ) ;
return;
}
F_2 ( L_56 , V_9 ) ;
}
int F_370 ( struct V_28 * V_29 , struct V_355 * V_466 )
{
struct V_93 * V_94 ;
struct V_688 args ;
struct V_689 V_30 = {
. V_690 = V_466 ,
} ;
struct V_685 V_127 = {
. args = & args ,
. V_30 = & V_30 ,
. V_29 = V_29 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_691 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
struct V_134 V_135 = {
. V_136 = V_29 -> V_497 ,
. V_131 = & V_132 ,
. V_137 = & V_692 ,
. V_139 = & V_127 ,
. V_172 = V_565 ,
} ;
int V_246 ;
F_2 ( L_17 , V_9 ) ;
V_94 = F_57 ( & V_135 ) ;
if ( F_58 ( V_94 ) )
V_246 = F_59 ( V_94 ) ;
else {
V_246 = V_94 -> V_141 ;
F_60 ( V_94 ) ;
}
F_2 ( L_58 , V_9 , V_246 ) ;
return V_246 ;
}
static struct V_117 * F_371 ( T_6 V_90 , T_5 V_693 )
{
return F_372 ( V_90 , sizeof( struct V_117 ) , V_693 ) ;
}
static void F_373 ( struct V_83 * V_84 ,
struct V_117 * V_694 ,
T_6 V_90 ,
T_6 V_695 )
{
struct V_117 * V_696 = NULL ;
T_6 V_364 ;
F_23 ( & V_84 -> V_104 ) ;
if ( V_694 ) {
V_696 = V_84 -> V_105 ;
V_84 -> V_105 = V_694 ;
V_84 -> V_90 = V_90 ;
}
V_84 -> V_89 = - 1 ;
for ( V_364 = 0 ; V_364 < V_84 -> V_90 ; V_364 ++ )
V_84 -> V_105 [ V_364 ] . V_109 = V_695 ;
F_25 ( & V_84 -> V_104 ) ;
F_81 ( V_696 ) ;
}
static int F_374 ( struct V_83 * V_84 , T_6 V_697 ,
T_6 V_695 )
{
struct V_117 * V_694 = NULL ;
int V_49 = - V_234 ;
F_2 ( L_59 , V_9 ,
V_697 , V_84 -> V_90 ) ;
if ( V_697 != V_84 -> V_90 ) {
V_694 = F_371 ( V_697 , V_243 ) ;
if ( ! V_694 )
goto V_108;
}
V_49 = 0 ;
F_373 ( V_84 , V_694 , V_697 , V_695 ) ;
F_2 ( L_60 , V_9 ,
V_84 , V_84 -> V_105 , V_84 -> V_90 ) ;
V_108:
F_2 ( L_61 , V_9 , V_49 ) ;
return V_49 ;
}
static void F_375 ( struct V_91 * V_114 )
{
if ( V_114 -> V_97 . V_105 != NULL ) {
F_81 ( V_114 -> V_97 . V_105 ) ;
V_114 -> V_97 . V_105 = NULL ;
}
if ( V_114 -> V_100 . V_105 != NULL ) {
F_81 ( V_114 -> V_100 . V_105 ) ;
V_114 -> V_100 . V_105 = NULL ;
}
return;
}
static int F_376 ( struct V_91 * V_92 )
{
struct V_83 * V_84 ;
int V_246 ;
F_2 ( L_17 , V_9 ) ;
V_84 = & V_92 -> V_97 ;
V_246 = F_374 ( V_84 , V_92 -> V_698 . V_697 , 1 ) ;
if ( V_246 )
return V_246 ;
V_84 = & V_92 -> V_100 ;
V_246 = F_374 ( V_84 , V_92 -> V_699 . V_697 , 0 ) ;
if ( V_246 && V_84 -> V_105 == NULL )
F_375 ( V_92 ) ;
return V_246 ;
}
struct V_91 * F_377 ( struct V_28 * V_29 )
{
struct V_91 * V_114 ;
struct V_83 * V_84 ;
V_114 = F_74 ( sizeof( struct V_91 ) , V_243 ) ;
if ( ! V_114 )
return NULL ;
V_84 = & V_114 -> V_97 ;
V_84 -> V_89 = - 1 ;
F_378 ( & V_84 -> V_104 ) ;
F_379 ( & V_84 -> V_98 , L_62 ) ;
F_380 ( & V_84 -> F_34 ) ;
V_84 = & V_114 -> V_100 ;
V_84 -> V_89 = - 1 ;
F_378 ( & V_84 -> V_104 ) ;
F_381 ( & V_84 -> V_98 , L_63 ) ;
F_380 ( & V_84 -> F_34 ) ;
V_114 -> V_96 = 1 << V_700 ;
V_114 -> V_29 = V_29 ;
return V_114 ;
}
void F_382 ( struct V_91 * V_114 )
{
F_383 ( V_114 ) ;
F_2 ( L_64 ,
V_9 , V_114 -> V_29 -> V_497 -> V_701 ) ;
F_384 ( V_114 -> V_29 -> V_497 -> V_701 ,
V_702 ) ;
F_375 ( V_114 ) ;
F_81 ( V_114 ) ;
}
static void F_385 ( struct V_703 * args )
{
struct V_91 * V_114 = args -> V_73 -> V_66 ;
unsigned int V_704 = V_114 -> V_698 . V_705 ,
V_706 = V_114 -> V_698 . V_707 ;
if ( V_704 == 0 )
V_704 = V_708 ;
if ( V_706 == 0 )
V_706 = V_708 ;
args -> V_698 . V_705 = V_704 ;
args -> V_698 . V_707 = V_706 ;
args -> V_698 . V_709 = V_710 ;
args -> V_698 . V_697 = V_114 -> V_29 -> V_497 -> V_701 -> V_697 ;
F_2 ( L_65
L_66 ,
V_9 ,
args -> V_698 . V_705 , args -> V_698 . V_707 ,
args -> V_698 . V_709 , args -> V_698 . V_697 ) ;
args -> V_699 . V_705 = V_517 ;
args -> V_699 . V_707 = V_517 ;
args -> V_699 . V_711 = 0 ;
args -> V_699 . V_709 = V_712 ;
args -> V_699 . V_697 = 1 ;
F_2 ( L_67
L_68 ,
V_9 ,
args -> V_699 . V_705 , args -> V_699 . V_707 ,
args -> V_699 . V_711 , args -> V_699 . V_709 ,
args -> V_699 . V_697 ) ;
}
static int F_386 ( struct V_703 * args , struct V_91 * V_114 )
{
struct V_713 * V_714 = & args -> V_698 ;
struct V_713 * V_715 = & V_114 -> V_698 ;
if ( V_715 -> V_707 > V_714 -> V_707 )
return - V_8 ;
if ( V_715 -> V_709 < V_714 -> V_709 )
return - V_8 ;
if ( V_715 -> V_697 == 0 )
return - V_8 ;
return 0 ;
}
static int F_387 ( struct V_703 * args , struct V_91 * V_114 )
{
struct V_713 * V_714 = & args -> V_699 ;
struct V_713 * V_715 = & V_114 -> V_699 ;
if ( V_715 -> V_705 > V_714 -> V_705 )
return - V_8 ;
if ( V_715 -> V_707 < V_714 -> V_707 )
return - V_8 ;
if ( V_715 -> V_711 > V_714 -> V_711 )
return - V_8 ;
if ( V_715 -> V_709 == 0 )
return - V_8 ;
if ( V_715 -> V_697 == 0 )
return - V_8 ;
return 0 ;
}
static int F_388 ( struct V_703 * args ,
struct V_91 * V_114 )
{
int V_49 ;
V_49 = F_386 ( args , V_114 ) ;
if ( V_49 )
return V_49 ;
return F_387 ( args , V_114 ) ;
}
static int F_389 ( struct V_28 * V_29 )
{
struct V_91 * V_114 = V_29 -> V_66 ;
struct V_703 args = {
. V_73 = V_29 ,
. V_716 = V_717 ,
} ;
struct V_718 V_30 = {
. V_73 = V_29 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_719 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
int V_246 ;
F_385 ( & args ) ;
args . V_172 = ( V_720 | V_721 ) ;
V_246 = F_63 ( V_114 -> V_29 -> V_497 , & V_132 , V_565 ) ;
if ( ! V_246 )
V_246 = F_388 ( & args , V_114 ) ;
if ( ! V_246 ) {
V_29 -> V_722 ++ ;
}
return V_246 ;
}
int F_390 ( struct V_28 * V_29 )
{
int V_246 ;
unsigned * V_723 ;
struct V_91 * V_114 = V_29 -> V_66 ;
F_2 ( L_69 , V_9 , V_29 , V_114 ) ;
V_246 = F_389 ( V_29 ) ;
if ( V_246 )
goto V_108;
V_246 = F_376 ( V_114 ) ;
F_2 ( L_70 , V_246 ) ;
if ( V_246 )
goto V_108;
V_723 = ( unsigned * ) & V_114 -> V_724 . V_127 [ 0 ] ;
F_2 ( L_71 , V_9 ,
V_29 -> V_722 , V_723 [ 0 ] , V_723 [ 1 ] , V_723 [ 2 ] , V_723 [ 3 ] ) ;
V_108:
F_2 ( L_56 , V_9 ) ;
return V_246 ;
}
int F_383 ( struct V_91 * V_114 )
{
int V_246 = 0 ;
struct V_131 V_132 ;
F_2 ( L_72 ) ;
if ( V_114 -> V_29 -> V_725 != V_726 )
return V_246 ;
V_132 . V_251 = & V_252 [ V_727 ] ;
V_132 . V_254 = V_114 ;
V_132 . V_255 = NULL ;
V_132 . V_256 = NULL ;
V_246 = F_63 ( V_114 -> V_29 -> V_497 , & V_132 , V_565 ) ;
if ( V_246 )
F_21 ( V_78
L_73
L_74 , V_246 ) ;
F_2 ( L_75 ) ;
return V_246 ;
}
int F_391 ( struct V_42 * V_43 )
{
struct V_28 * V_29 = V_43 -> V_28 ;
struct V_91 * V_114 ;
unsigned int V_728 , V_729 ;
int V_49 ;
if ( ! F_392 ( V_29 ) )
return 0 ;
V_114 = V_29 -> V_66 ;
if ( ! F_393 ( V_700 , & V_114 -> V_96 ) )
return 0 ;
V_728 = V_43 -> V_728 ;
if ( V_728 == 0 )
V_728 = V_708 ;
V_729 = V_43 -> V_729 ;
if ( V_729 == 0 )
V_729 = V_708 ;
V_114 -> V_698 . V_705 = V_729 + V_730 ;
V_114 -> V_698 . V_707 = V_728 + V_731 ;
V_49 = F_158 ( V_43 ) ;
if ( ! V_49 )
V_49 = F_394 ( V_29 ) ;
return V_49 ;
}
int F_395 ( struct V_28 * V_29 )
{
struct V_91 * V_114 = V_29 -> V_66 ;
int V_49 ;
if ( ! F_393 ( V_700 , & V_114 -> V_96 ) )
return 0 ;
V_49 = F_156 ( V_29 ) ;
if ( ! V_49 )
if ( ! F_396 ( V_29 ) )
V_49 = - V_732 ;
if ( ! V_49 )
V_49 = F_394 ( V_29 ) ;
return V_49 ;
}
static void F_397 ( void * V_127 )
{
struct V_733 * V_125 = V_127 ;
struct V_28 * V_29 = V_125 -> V_29 ;
if ( F_281 ( & V_29 -> V_491 ) > 1 )
F_282 ( V_29 ) ;
F_283 ( V_29 ) ;
F_81 ( V_125 ) ;
}
static int F_398 ( struct V_93 * V_94 , struct V_28 * V_29 )
{
switch( V_94 -> V_141 ) {
case - V_71 :
F_40 ( V_94 , V_39 ) ;
return - V_119 ;
default:
F_18 ( V_29 ) ;
}
return 0 ;
}
static void F_399 ( struct V_93 * V_94 , void * V_127 )
{
struct V_733 * V_125 = V_127 ;
struct V_28 * V_29 = V_125 -> V_29 ;
if ( ! F_37 ( V_94 , V_94 -> V_265 . V_255 ) )
return;
if ( V_94 -> V_141 < 0 ) {
F_2 ( L_76 , V_9 , V_94 -> V_141 ) ;
if ( F_281 ( & V_29 -> V_491 ) == 1 )
goto V_108;
if ( F_398 ( V_94 , V_29 ) == - V_119 ) {
F_181 ( V_94 ) ;
return;
}
}
F_2 ( L_77 , V_9 , V_94 -> V_265 . V_256 ) ;
V_108:
F_2 ( L_56 , V_9 ) ;
}
static void F_400 ( struct V_93 * V_94 , void * V_127 )
{
struct V_733 * V_125 = V_127 ;
struct V_28 * V_29 = V_125 -> V_29 ;
struct V_115 * args ;
struct V_101 * V_30 ;
args = V_94 -> V_265 . V_254 ;
V_30 = V_94 -> V_265 . V_255 ;
if ( F_46 ( V_29 -> V_66 , args , V_30 , 0 , V_94 ) )
return;
F_53 ( V_94 ) ;
}
static struct V_93 * F_401 ( struct V_28 * V_29 , struct V_256 * V_298 )
{
struct V_733 * V_125 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_734 ] ,
. V_256 = V_298 ,
} ;
struct V_134 V_257 = {
. V_136 = V_29 -> V_497 ,
. V_131 = & V_132 ,
. V_137 = & V_735 ,
. V_172 = V_261 | V_498 ,
} ;
if ( ! F_287 ( & V_29 -> V_491 ) )
return F_113 ( - V_10 ) ;
V_125 = F_74 ( sizeof( * V_125 ) , V_243 ) ;
if ( V_125 == NULL ) {
F_283 ( V_29 ) ;
return F_113 ( - V_234 ) ;
}
V_132 . V_254 = & V_125 -> args ;
V_132 . V_255 = & V_125 -> V_30 ;
V_125 -> V_29 = V_29 ;
V_257 . V_139 = V_125 ;
return F_57 ( & V_257 ) ;
}
static int F_402 ( struct V_28 * V_29 , struct V_256 * V_298 , unsigned V_495 )
{
struct V_93 * V_94 ;
int V_49 = 0 ;
if ( ( V_495 & V_736 ) == 0 )
return 0 ;
V_94 = F_401 ( V_29 , V_298 ) ;
if ( F_58 ( V_94 ) )
V_49 = F_59 ( V_94 ) ;
else
F_342 ( V_94 ) ;
F_2 ( L_23 , V_9 , V_49 ) ;
return V_49 ;
}
static int F_403 ( struct V_28 * V_29 , struct V_256 * V_298 )
{
struct V_93 * V_94 ;
int V_49 ;
V_94 = F_401 ( V_29 , V_298 ) ;
if ( F_58 ( V_94 ) ) {
V_49 = F_59 ( V_94 ) ;
goto V_108;
}
V_49 = F_93 ( V_94 ) ;
if ( ! V_49 ) {
struct V_101 * V_30 = V_94 -> V_265 . V_255 ;
if ( V_94 -> V_141 == 0 )
F_404 ( V_29 , V_30 -> V_111 ) ;
V_49 = V_94 -> V_141 ;
}
F_60 ( V_94 ) ;
V_108:
F_2 ( L_23 , V_9 , V_49 ) ;
return V_49 ;
}
static void F_405 ( struct V_93 * V_94 , void * V_127 )
{
struct V_737 * V_125 = V_127 ;
F_33 ( V_94 , V_99 ) ;
if ( F_46 ( V_125 -> V_29 -> V_66 ,
& V_125 -> V_308 . V_129 ,
& V_125 -> V_30 . V_130 , 0 , V_94 ) )
return;
F_53 ( V_94 ) ;
}
static int F_406 ( struct V_93 * V_94 , struct V_28 * V_29 )
{
switch( V_94 -> V_141 ) {
case 0 :
case - V_738 :
case - V_739 :
break;
case - V_71 :
F_40 ( V_94 , V_39 ) ;
case - V_74 :
return - V_119 ;
default:
F_18 ( V_29 ) ;
}
return 0 ;
}
static void F_407 ( struct V_93 * V_94 , void * V_127 )
{
struct V_737 * V_125 = V_127 ;
struct V_28 * V_29 = V_125 -> V_29 ;
struct V_101 * V_30 = & V_125 -> V_30 . V_130 ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_37 ( V_94 , V_30 ) )
return;
if ( F_406 ( V_94 , V_29 ) == - V_119 ) {
F_181 ( V_94 ) ;
return;
}
F_2 ( L_56 , V_9 ) ;
}
static void F_408 ( void * V_127 )
{
struct V_737 * V_125 = V_127 ;
F_81 ( V_125 ) ;
}
static int F_409 ( struct V_28 * V_29 )
{
struct V_737 * V_125 ;
struct V_93 * V_94 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_740 ] ,
} ;
struct V_134 V_257 = {
. V_136 = V_29 -> V_497 ,
. V_131 = & V_132 ,
. V_137 = & V_741 ,
. V_172 = V_261 ,
} ;
int V_246 = - V_234 ;
F_2 ( L_17 , V_9 ) ;
V_125 = F_74 ( sizeof( * V_125 ) , V_243 ) ;
if ( V_125 == NULL )
goto V_108;
V_125 -> V_29 = V_29 ;
V_125 -> V_308 . V_742 = 0 ;
V_132 . V_254 = & V_125 -> V_308 ;
V_132 . V_255 = & V_125 -> V_30 ;
V_257 . V_139 = V_125 ;
V_94 = F_57 ( & V_257 ) ;
if ( F_58 ( V_94 ) ) {
V_246 = F_59 ( V_94 ) ;
goto V_108;
}
V_246 = F_92 ( V_94 ) ;
if ( V_246 == 0 )
V_246 = V_94 -> V_141 ;
F_60 ( V_94 ) ;
return 0 ;
V_108:
F_2 ( L_23 , V_9 , V_246 ) ;
return V_246 ;
}
static void
F_410 ( struct V_93 * V_94 , void * V_125 )
{
struct V_743 * V_744 = V_125 ;
struct V_42 * V_43 = F_73 ( V_744 -> args . V_144 ) ;
F_2 ( L_17 , V_9 ) ;
if ( F_50 ( V_43 , & V_744 -> args . V_129 ,
& V_744 -> V_30 . V_130 , 0 , V_94 ) )
return;
if ( F_411 ( & V_744 -> args . V_202 ,
F_66 ( V_744 -> args . V_144 ) -> V_745 ,
V_744 -> args . V_241 -> V_48 ) ) {
F_412 ( V_94 , V_746 ) ;
return;
}
F_53 ( V_94 ) ;
}
static void F_413 ( struct V_93 * V_94 , void * V_125 )
{
struct V_743 * V_744 = V_125 ;
struct V_42 * V_43 = F_73 ( V_744 -> args . V_144 ) ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_41 ( V_94 , & V_744 -> V_30 . V_130 ) )
return;
switch ( V_94 -> V_141 ) {
case 0 :
break;
case - V_747 :
case - V_748 :
V_94 -> V_141 = - V_71 ;
default:
if ( F_180 ( V_94 , V_43 , NULL ) == - V_119 ) {
F_181 ( V_94 ) ;
return;
}
}
F_2 ( L_56 , V_9 ) ;
}
static void F_414 ( void * V_125 )
{
struct V_743 * V_744 = V_125 ;
F_2 ( L_17 , V_9 ) ;
F_135 ( V_744 -> args . V_241 ) ;
F_81 ( V_125 ) ;
F_2 ( L_56 , V_9 ) ;
}
int F_415 ( struct V_743 * V_744 )
{
struct V_42 * V_43 = F_73 ( V_744 -> args . V_144 ) ;
struct V_93 * V_94 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_749 ] ,
. V_254 = & V_744 -> args ,
. V_255 = & V_744 -> V_30 ,
} ;
struct V_134 V_257 = {
. V_136 = V_43 -> V_73 ,
. V_131 = & V_132 ,
. V_137 = & V_750 ,
. V_139 = V_744 ,
. V_172 = V_261 ,
} ;
int V_246 = 0 ;
F_2 ( L_17 , V_9 ) ;
V_744 -> V_30 . V_751 = & V_744 -> args . V_745 ;
V_744 -> V_30 . V_130 . V_103 = NULL ;
V_94 = F_57 ( & V_257 ) ;
if ( F_58 ( V_94 ) )
return F_59 ( V_94 ) ;
V_246 = F_92 ( V_94 ) ;
if ( V_246 == 0 )
V_246 = V_94 -> V_141 ;
if ( V_246 == 0 )
V_246 = F_416 ( V_744 ) ;
F_60 ( V_94 ) ;
F_2 ( L_23 , V_9 , V_246 ) ;
return V_246 ;
}
static void
F_417 ( struct V_93 * V_94 , void * V_125 )
{
struct V_752 * V_753 = V_125 ;
F_2 ( L_17 , V_9 ) ;
if ( F_46 ( V_753 -> V_29 -> V_66 , & V_753 -> args . V_129 ,
& V_753 -> V_30 . V_130 , 0 , V_94 ) )
return;
F_53 ( V_94 ) ;
}
static void F_418 ( struct V_93 * V_94 , void * V_125 )
{
struct V_752 * V_753 = V_125 ;
struct V_42 * V_43 ;
struct V_754 * V_755 = V_753 -> args . V_745 ;
F_2 ( L_17 , V_9 ) ;
if ( ! F_41 ( V_94 , & V_753 -> V_30 . V_130 ) )
return;
V_43 = F_73 ( V_753 -> args . V_144 ) ;
if ( F_180 ( V_94 , V_43 , NULL ) == - V_119 ) {
F_181 ( V_94 ) ;
return;
}
F_23 ( & V_755 -> V_756 -> V_150 ) ;
if ( V_94 -> V_141 == 0 ) {
if ( V_753 -> V_30 . V_757 ) {
F_419 ( V_755 , & V_753 -> V_30 . V_202 , true ) ;
} else
F_4 ( ! F_420 ( & V_755 -> V_758 ) ) ;
}
V_755 -> V_759 -- ;
F_25 ( & V_755 -> V_756 -> V_150 ) ;
F_2 ( L_56 , V_9 ) ;
}
static void F_421 ( void * V_125 )
{
struct V_752 * V_753 = V_125 ;
F_2 ( L_17 , V_9 ) ;
F_422 ( V_753 -> args . V_745 ) ;
F_81 ( V_125 ) ;
F_2 ( L_56 , V_9 ) ;
}
int F_423 ( struct V_752 * V_753 )
{
struct V_93 * V_94 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_760 ] ,
. V_254 = & V_753 -> args ,
. V_255 = & V_753 -> V_30 ,
} ;
struct V_134 V_257 = {
. V_136 = V_753 -> V_29 -> V_497 ,
. V_131 = & V_132 ,
. V_137 = & V_761 ,
. V_139 = V_753 ,
} ;
int V_246 ;
F_2 ( L_17 , V_9 ) ;
V_94 = F_57 ( & V_257 ) ;
if ( F_58 ( V_94 ) )
return F_59 ( V_94 ) ;
V_246 = V_94 -> V_141 ;
F_2 ( L_23 , V_9 , V_246 ) ;
F_60 ( V_94 ) ;
return V_246 ;
}
static int F_424 ( struct V_42 * V_43 ,
const struct V_328 * V_182 ,
struct V_762 * V_763 )
{
struct V_764 args = {
. V_182 = V_182 ,
. V_765 = V_43 -> V_766 -> V_188 ,
} ;
struct V_767 V_30 = {
. V_763 = V_763 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_768 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
int V_246 ;
F_2 ( L_17 , V_9 ) ;
V_246 = F_64 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 ,
& V_30 . V_130 , 0 ) ;
F_2 ( L_23 , V_9 , V_246 ) ;
return V_246 ;
}
int F_425 ( struct V_42 * V_43 ,
const struct V_328 * V_182 ,
struct V_762 * V_763 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_424 ( V_43 , V_182 , V_763 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
F_2 ( L_78 , V_9 ,
V_1 , V_763 -> V_769 ) ;
return V_1 ;
}
static int
F_426 ( struct V_42 * V_43 , struct V_770 * V_771 )
{
struct V_772 args = {
. V_771 = V_771 ,
} ;
struct V_773 V_30 = {
. V_771 = V_771 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_774 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
int V_246 ;
F_2 ( L_17 , V_9 ) ;
V_246 = F_64 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
F_2 ( L_23 , V_9 , V_246 ) ;
return V_246 ;
}
int F_427 ( struct V_42 * V_43 , struct V_770 * V_771 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_426 ( V_43 , V_771 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static void F_428 ( struct V_93 * V_94 , void * V_125 )
{
struct V_775 * V_127 = V_125 ;
struct V_42 * V_43 = F_73 ( V_127 -> args . V_144 ) ;
if ( F_50 ( V_43 , & V_127 -> args . V_129 ,
& V_127 -> V_30 . V_130 , 1 , V_94 ) )
return;
F_53 ( V_94 ) ;
}
static void
F_429 ( struct V_93 * V_94 , void * V_125 )
{
struct V_775 * V_127 = V_125 ;
struct V_42 * V_43 = F_73 ( V_127 -> args . V_144 ) ;
if ( ! F_41 ( V_94 , & V_127 -> V_30 . V_130 ) )
return;
switch ( V_94 -> V_141 ) {
case V_776 :
case V_777 :
case V_778 :
case V_70 :
V_94 -> V_141 = 0 ;
}
if ( F_180 ( V_94 , V_43 , NULL ) == - V_119 ) {
F_181 ( V_94 ) ;
return;
}
if ( V_94 -> V_141 == 0 )
F_273 ( V_127 -> args . V_144 ,
V_127 -> V_30 . V_306 ) ;
}
static void F_430 ( void * V_125 )
{
struct V_775 * V_127 = V_125 ;
struct V_779 * V_480 , * V_780 ;
unsigned long * V_781 = & F_66 ( V_127 -> args . V_144 ) -> V_172 ;
F_431 ( V_127 ) ;
F_432 (lseg, tmp, &data->lseg_list, pls_lc_list) {
F_433 ( & V_480 -> V_782 ) ;
if ( F_393 ( V_783 ,
& V_480 -> V_784 ) )
F_270 ( V_480 ) ;
}
F_434 ( V_785 , V_781 ) ;
F_435 () ;
F_436 ( V_781 , V_785 ) ;
F_437 ( V_127 -> V_298 ) ;
F_81 ( V_127 ) ;
}
int
F_438 ( struct V_775 * V_127 , bool V_786 )
{
struct V_131 V_132 = {
. V_251 = & V_252 [ V_787 ] ,
. V_254 = & V_127 -> args ,
. V_255 = & V_127 -> V_30 ,
. V_256 = V_127 -> V_298 ,
} ;
struct V_134 V_257 = {
. V_94 = & V_127 -> V_94 ,
. V_136 = F_118 ( V_127 -> args . V_144 ) ,
. V_131 = & V_132 ,
. V_137 = & V_788 ,
. V_139 = V_127 ,
. V_172 = V_261 ,
} ;
struct V_93 * V_94 ;
int V_246 = 0 ;
F_2 ( L_79
L_80 ,
V_127 -> V_94 . V_789 , V_786 ,
V_127 -> args . V_790 ,
V_127 -> args . V_144 -> V_791 ) ;
V_94 = F_57 ( & V_257 ) ;
if ( F_58 ( V_94 ) )
return F_59 ( V_94 ) ;
if ( V_786 == false )
goto V_108;
V_246 = F_92 ( V_94 ) ;
if ( V_246 != 0 )
goto V_108;
V_246 = V_94 -> V_141 ;
V_108:
F_2 ( L_81 , V_9 , V_246 ) ;
F_60 ( V_94 ) ;
return V_246 ;
}
static int
F_439 ( struct V_42 * V_43 , struct V_328 * V_329 ,
struct V_355 * V_356 , struct V_660 * V_661 )
{
struct V_792 args = {
. V_793 = V_794 ,
} ;
struct V_663 V_30 = {
. V_661 = V_661 ,
} ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_795 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
return F_64 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 0 ) ;
}
static int
F_440 ( struct V_42 * V_43 , struct V_328 * V_329 ,
struct V_355 * V_356 , struct V_660 * V_661 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_439 ( V_43 , V_329 , V_356 , V_661 ) ;
switch ( V_1 ) {
case 0 :
case - V_4 :
case - V_796 :
break;
default:
V_1 = F_16 ( V_43 , V_1 , & V_46 ) ;
}
} while ( V_46 . V_50 );
return V_1 ;
}
static int
F_441 ( struct V_42 * V_43 , struct V_328 * V_329 ,
struct V_355 * V_356 )
{
int V_1 ;
struct V_375 * V_375 ;
T_8 V_361 ;
struct V_660 * V_661 ;
V_375 = F_203 ( V_301 ) ;
if ( ! V_375 ) {
V_1 = - V_234 ;
goto V_108;
}
V_661 = F_293 ( V_375 ) ;
V_1 = F_440 ( V_43 , V_329 , V_356 , V_661 ) ;
if ( V_1 == - V_4 || V_1 == - V_796 ) {
V_1 = F_197 ( V_43 , V_329 , V_356 ) ;
goto V_797;
}
if ( V_1 )
goto V_797;
V_361 = F_442 ( V_661 ) ;
if ( V_1 == 0 )
V_1 = F_195 ( V_43 , V_329 , V_356 , V_361 ) ;
V_797:
F_305 ( V_375 ) ;
if ( V_1 == - V_369 )
return - V_5 ;
V_108:
return V_1 ;
}
static int F_443 ( struct V_42 * V_43 , struct V_47 * V_48 )
{
int V_246 ;
struct V_798 args = {
. V_202 = & V_48 -> V_202 ,
} ;
struct V_799 V_30 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_800 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
args . V_129 . V_121 = V_30 . V_130 . V_102 = NULL ;
V_246 = F_56 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 0 , 1 ) ;
return V_246 ;
}
static int F_164 ( struct V_42 * V_43 , struct V_47 * V_48 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_443 ( V_43 , V_48 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
static int F_444 ( struct V_42 * V_43 , struct V_47 * V_48 )
{
int V_246 ;
struct V_801 args = {
. V_202 = & V_48 -> V_202 ,
} ;
struct V_802 V_30 ;
struct V_131 V_132 = {
. V_251 = & V_252 [ V_803 ] ,
. V_254 = & args ,
. V_255 = & V_30 ,
} ;
args . V_129 . V_121 = V_30 . V_130 . V_102 = NULL ;
V_246 = F_56 ( V_43 -> V_73 , V_43 , & V_132 , & args . V_129 , & V_30 . V_130 , 0 , 1 ) ;
return V_246 ;
}
static int F_165 ( struct V_42 * V_43 , struct V_47 * V_48 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_43 ,
F_444 ( V_43 , V_48 ) ,
& V_46 ) ;
} while ( V_46 . V_50 );
return V_1 ;
}
