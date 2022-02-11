static inline T_1 F_1 ( T_2 V_1 )
{
return ( ( V_1 >> 8 ) | V_1 ) % V_2 ;
}
static struct V_3 *
F_2 ( T_2 V_1 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_3 * V_8 ;
V_5 = & V_9 [ F_1 ( V_1 ) ] ;
F_3 (inst, pos, head, hlist) {
if ( V_8 -> V_1 == V_1 )
return V_8 ;
}
return NULL ;
}
static struct V_3 *
F_4 ( T_2 V_1 , int V_10 )
{
struct V_3 * V_8 ;
unsigned int V_11 ;
int V_12 ;
F_5 ( & V_13 ) ;
if ( F_2 ( V_1 ) ) {
V_12 = - V_14 ;
goto V_15;
}
V_8 = F_6 ( sizeof( * V_8 ) , V_16 ) ;
if ( ! V_8 ) {
V_12 = - V_17 ;
goto V_15;
}
V_8 -> V_1 = V_1 ;
V_8 -> V_18 = V_10 ;
V_8 -> V_19 = V_20 ;
V_8 -> V_21 = 0xfffff ;
V_8 -> V_22 = V_23 ;
F_7 ( & V_8 -> V_24 ) ;
F_8 ( & V_8 -> V_25 ) ;
if ( ! F_9 ( V_26 ) ) {
V_12 = - V_27 ;
goto V_28;
}
V_11 = F_1 ( V_1 ) ;
F_10 ( & V_8 -> V_29 , & V_9 [ V_11 ] ) ;
F_11 ( & V_13 ) ;
return V_8 ;
V_28:
F_12 ( V_8 ) ;
V_15:
F_11 ( & V_13 ) ;
return F_13 ( V_12 ) ;
}
static void
F_14 ( struct V_30 * V_5 )
{
struct V_3 * V_8 = F_15 ( V_5 , struct V_3 ,
V_31 ) ;
F_16 ( V_8 , NULL , 0 ) ;
F_12 ( V_8 ) ;
F_17 ( V_26 ) ;
}
static void
F_18 ( struct V_3 * V_8 )
{
F_19 ( & V_8 -> V_29 ) ;
F_20 ( & V_8 -> V_31 , F_14 ) ;
}
static void
F_21 ( struct V_3 * V_8 )
{
F_5 ( & V_13 ) ;
F_18 ( V_8 ) ;
F_11 ( & V_13 ) ;
}
static inline void
F_22 ( struct V_3 * V_32 , struct V_33 * V_34 )
{
F_23 ( & V_34 -> V_35 , & V_32 -> V_25 ) ;
V_32 -> V_36 ++ ;
}
static struct V_33 *
F_24 ( struct V_3 * V_32 , unsigned int V_37 )
{
struct V_33 * V_34 = NULL , * V_38 ;
F_25 ( & V_32 -> V_24 ) ;
F_26 (i, &queue->queue_list, list) {
if ( V_38 -> V_37 == V_37 ) {
V_34 = V_38 ;
break;
}
}
if ( V_34 ) {
F_27 ( & V_34 -> V_35 ) ;
V_32 -> V_36 -- ;
}
F_28 ( & V_32 -> V_24 ) ;
return V_34 ;
}
static void
F_16 ( struct V_3 * V_32 , T_3 V_39 , unsigned long V_40 )
{
struct V_33 * V_34 , * V_41 ;
F_25 ( & V_32 -> V_24 ) ;
F_29 (entry, next, &queue->queue_list, list) {
if ( ! V_39 || V_39 ( V_34 , V_40 ) ) {
F_27 ( & V_34 -> V_35 ) ;
V_32 -> V_36 -- ;
F_30 ( V_34 , V_42 ) ;
}
}
F_28 ( & V_32 -> V_24 ) ;
}
static struct V_43 *
F_31 ( struct V_3 * V_32 ,
struct V_33 * V_34 )
{
T_4 V_44 ;
T_5 V_45 ;
T_5 V_46 = 0 ;
struct V_43 * V_47 ;
struct V_48 V_49 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_43 * V_54 = V_34 -> V_47 ;
struct V_55 * V_56 ;
struct V_55 * V_57 ;
V_45 = F_32 ( sizeof( struct V_52 ) )
+ F_33 ( sizeof( struct V_48 ) )
+ F_33 ( sizeof( V_58 ) )
+ F_33 ( sizeof( V_58 ) )
#ifdef F_34
+ F_33 ( sizeof( V_58 ) )
+ F_33 ( sizeof( V_58 ) )
#endif
+ F_33 ( sizeof( V_58 ) )
+ F_33 ( sizeof( struct V_59 ) )
+ F_33 ( sizeof( struct V_60 ) ) ;
V_57 = V_34 -> V_57 ;
switch ( (enum V_61 ) F_35 ( V_32 -> V_22 ) ) {
case V_62 :
case V_23 :
break;
case V_63 :
if ( V_54 -> V_64 == V_65 &&
F_36 ( V_54 ) )
return NULL ;
V_46 = F_35 ( V_32 -> V_21 ) ;
if ( V_46 == 0 || V_46 > V_54 -> V_66 )
V_46 = V_54 -> V_66 ;
V_45 += F_33 ( V_46 ) ;
break;
}
V_47 = F_37 ( V_45 , V_16 ) ;
if ( ! V_47 )
goto V_67;
V_44 = V_47 -> V_68 ;
V_51 = F_38 ( V_47 , 0 , 0 ,
V_69 << 8 | V_70 ,
sizeof( struct V_52 ) ) ;
V_53 = F_39 ( V_51 ) ;
V_53 -> V_71 = V_34 -> V_72 ;
V_53 -> V_73 = V_74 ;
V_53 -> V_75 = F_40 ( V_32 -> V_1 ) ;
V_34 -> V_37 = F_41 ( & V_32 -> V_76 ) ;
V_49 . V_77 = F_42 ( V_34 -> V_37 ) ;
V_49 . V_78 = V_54 -> V_79 ;
V_49 . V_80 = V_34 -> V_80 ;
F_43 ( V_47 , V_81 , sizeof( V_49 ) , & V_49 ) ;
V_56 = V_34 -> V_56 ;
if ( V_56 ) {
#ifndef F_34
F_44 ( V_47 , V_82 , F_42 ( V_56 -> V_83 ) ) ;
#else
if ( V_34 -> V_72 == V_84 ) {
F_44 ( V_47 , V_85 ,
F_42 ( V_56 -> V_83 ) ) ;
F_44 ( V_47 , V_82 ,
F_42 ( F_45 ( V_56 ) -> V_86 -> V_87 -> V_83 ) ) ;
} else {
F_44 ( V_47 , V_82 ,
F_42 ( V_56 -> V_83 ) ) ;
if ( V_54 -> V_88 && V_54 -> V_88 -> V_89 )
F_44 ( V_47 , V_85 ,
F_42 ( V_54 -> V_88 -> V_89 -> V_83 ) ) ;
}
#endif
}
if ( V_57 ) {
#ifndef F_34
F_44 ( V_47 , V_90 , F_42 ( V_57 -> V_83 ) ) ;
#else
if ( V_34 -> V_72 == V_84 ) {
F_44 ( V_47 , V_91 ,
F_42 ( V_57 -> V_83 ) ) ;
F_44 ( V_47 , V_90 ,
F_42 ( F_45 ( V_57 ) -> V_86 -> V_87 -> V_83 ) ) ;
} else {
F_44 ( V_47 , V_90 ,
F_42 ( V_57 -> V_83 ) ) ;
if ( V_54 -> V_88 && V_54 -> V_88 -> V_92 )
F_44 ( V_47 , V_91 ,
F_42 ( V_54 -> V_88 -> V_92 -> V_83 ) ) ;
}
#endif
}
if ( V_54 -> V_93 )
F_44 ( V_47 , V_94 , F_42 ( V_54 -> V_93 ) ) ;
if ( V_56 && V_54 -> V_87 &&
V_54 -> V_95 != V_54 -> V_96 ) {
struct V_59 V_97 ;
int V_66 = F_46 ( V_54 , V_97 . V_98 ) ;
if ( V_66 ) {
V_97 . V_99 = F_40 ( V_66 ) ;
F_43 ( V_47 , V_100 , sizeof( V_97 ) , & V_97 ) ;
}
}
if ( V_54 -> V_101 . V_102 ) {
struct V_60 V_103 ;
struct V_104 V_105 = F_47 ( V_54 -> V_101 ) ;
V_103 . V_106 = F_48 ( V_105 . V_107 ) ;
V_103 . V_108 = F_48 ( V_105 . V_109 ) ;
F_43 ( V_47 , V_110 , sizeof( V_103 ) , & V_103 ) ;
}
if ( V_46 ) {
struct V_111 * V_112 ;
int V_113 = F_49 ( V_46 ) ;
if ( F_50 ( V_47 ) < F_33 ( V_46 ) ) {
F_51 ( V_114 L_1 ) ;
goto V_67;
}
V_112 = (struct V_111 * ) F_52 ( V_47 , F_33 ( V_46 ) ) ;
V_112 -> V_115 = V_116 ;
V_112 -> V_117 = V_113 ;
if ( F_53 ( V_54 , 0 , F_54 ( V_112 ) , V_46 ) )
F_55 () ;
}
V_51 -> V_118 = V_47 -> V_68 - V_44 ;
return V_47 ;
V_67:
V_119:
if ( V_47 )
F_56 ( V_47 ) ;
if ( F_57 () )
F_51 ( V_120 L_2 ) ;
return NULL ;
}
static int
F_58 ( struct V_33 * V_34 , unsigned int V_121 )
{
struct V_43 * V_122 ;
struct V_3 * V_32 ;
int V_12 = - V_123 ;
V_32 = F_2 ( V_121 ) ;
if ( ! V_32 ) {
V_12 = - V_124 ;
goto V_125;
}
if ( V_32 -> V_22 == V_23 ) {
V_12 = - V_126 ;
goto V_125;
}
V_122 = F_31 ( V_32 , V_34 ) ;
if ( V_122 == NULL ) {
V_12 = - V_17 ;
goto V_125;
}
F_25 ( & V_32 -> V_24 ) ;
if ( ! V_32 -> V_18 ) {
V_12 = - V_126 ;
goto V_127;
}
if ( V_32 -> V_36 >= V_32 -> V_19 ) {
V_32 -> V_128 ++ ;
if ( F_57 () )
F_51 ( V_114 L_3
L_4 ,
V_32 -> V_36 ) ;
goto V_127;
}
V_12 = F_59 ( V_122 , & V_129 , V_32 -> V_18 , V_130 ) ;
if ( V_12 < 0 ) {
V_32 -> V_131 ++ ;
goto V_132;
}
F_22 ( V_32 , V_34 ) ;
F_28 ( & V_32 -> V_24 ) ;
return 0 ;
V_127:
F_56 ( V_122 ) ;
V_132:
F_28 ( & V_32 -> V_24 ) ;
V_125:
return V_12 ;
}
static int
F_60 ( void * V_40 , int V_46 , struct V_33 * V_133 )
{
struct V_43 * V_122 ;
int V_134 ;
V_134 = V_46 - V_133 -> V_47 -> V_66 ;
if ( V_134 < 0 ) {
if ( F_61 ( V_133 -> V_47 , V_46 ) )
return - V_17 ;
} else if ( V_134 > 0 ) {
if ( V_46 > 0xFFFF )
return - V_126 ;
if ( V_134 > F_50 ( V_133 -> V_47 ) ) {
V_122 = F_62 ( V_133 -> V_47 , F_63 ( V_133 -> V_47 ) ,
V_134 , V_16 ) ;
if ( ! V_122 ) {
F_51 ( V_114 L_5
L_6 ) ;
return - V_17 ;
}
F_56 ( V_133 -> V_47 ) ;
V_133 -> V_47 = V_122 ;
}
F_52 ( V_133 -> V_47 , V_134 ) ;
}
if ( ! F_64 ( V_133 -> V_47 , V_46 ) )
return - V_17 ;
F_65 ( V_133 -> V_47 , V_40 , V_46 ) ;
V_133 -> V_47 -> V_64 = V_135 ;
return 0 ;
}
static int
F_66 ( struct V_3 * V_32 ,
unsigned char V_136 , unsigned int V_137 )
{
int V_138 = 0 ;
F_25 ( & V_32 -> V_24 ) ;
switch ( V_136 ) {
case V_23 :
case V_62 :
V_32 -> V_22 = V_136 ;
V_32 -> V_21 = 0 ;
break;
case V_63 :
V_32 -> V_22 = V_136 ;
if ( V_137 > 0xffff )
V_32 -> V_21 = 0xffff ;
else
V_32 -> V_21 = V_137 ;
break;
default:
V_138 = - V_126 ;
}
F_28 ( & V_32 -> V_24 ) ;
return V_138 ;
}
static int
F_67 ( struct V_33 * V_34 , unsigned long V_83 )
{
if ( V_34 -> V_56 )
if ( V_34 -> V_56 -> V_83 == V_83 )
return 1 ;
if ( V_34 -> V_57 )
if ( V_34 -> V_57 -> V_83 == V_83 )
return 1 ;
#ifdef F_34
if ( V_34 -> V_47 -> V_88 ) {
if ( V_34 -> V_47 -> V_88 -> V_89 &&
V_34 -> V_47 -> V_88 -> V_89 -> V_83 == V_83 )
return 1 ;
if ( V_34 -> V_47 -> V_88 -> V_92 &&
V_34 -> V_47 -> V_88 -> V_92 -> V_83 == V_83 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_68 ( int V_83 )
{
int V_38 ;
F_69 () ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
struct V_6 * V_139 ;
struct V_3 * V_8 ;
struct V_4 * V_5 = & V_9 [ V_38 ] ;
F_3 (inst, tmp, head, hlist)
F_16 ( V_8 , F_67 , V_83 ) ;
}
F_70 () ;
}
static int
F_71 ( struct V_140 * V_141 ,
unsigned long V_142 , void * V_143 )
{
struct V_55 * V_87 = V_143 ;
if ( ! F_72 ( F_73 ( V_87 ) , & V_129 ) )
return V_144 ;
if ( V_142 == V_145 )
F_68 ( V_87 -> V_83 ) ;
return V_144 ;
}
static int
F_74 ( struct V_140 * V_141 ,
unsigned long V_142 , void * V_143 )
{
struct V_146 * V_147 = V_143 ;
if ( V_142 == V_148 && V_147 -> V_79 == V_149 ) {
int V_38 ;
F_5 ( & V_13 ) ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
struct V_6 * V_139 , * V_150 ;
struct V_3 * V_8 ;
struct V_4 * V_5 = & V_9 [ V_38 ] ;
F_75 (inst, tmp, t2, head, hlist) {
if ( ( V_147 -> V_151 == & V_129 ) &&
( V_147 -> V_10 == V_8 -> V_18 ) )
F_18 ( V_8 ) ;
}
}
F_11 ( & V_13 ) ;
}
return V_144 ;
}
static int
F_76 ( struct V_152 * V_153 , struct V_43 * V_47 ,
const struct V_50 * V_51 ,
const struct V_111 * const V_154 [] )
{
struct V_52 * V_53 = F_39 ( V_51 ) ;
T_2 V_1 = F_77 ( V_53 -> V_75 ) ;
struct V_155 * V_156 ;
struct V_3 * V_32 ;
unsigned int V_157 ;
struct V_33 * V_34 ;
int V_12 ;
F_69 () ;
V_32 = F_2 ( V_1 ) ;
if ( ! V_32 ) {
V_12 = - V_158 ;
goto V_132;
}
if ( V_32 -> V_18 != F_78 ( V_47 ) . V_10 ) {
V_12 = - V_159 ;
goto V_132;
}
if ( ! V_154 [ V_160 ] ) {
V_12 = - V_126 ;
goto V_132;
}
V_156 = F_54 ( V_154 [ V_160 ] ) ;
V_157 = F_79 ( V_156 -> V_157 ) ;
if ( ( V_157 & V_161 ) > V_162 ) {
V_12 = - V_126 ;
goto V_132;
}
V_34 = F_24 ( V_32 , F_79 ( V_156 -> V_37 ) ) ;
if ( V_34 == NULL ) {
V_12 = - V_163 ;
goto V_132;
}
F_70 () ;
if ( V_154 [ V_116 ] ) {
if ( F_60 ( F_54 ( V_154 [ V_116 ] ) ,
V_117 ( V_154 [ V_116 ] ) , V_34 ) < 0 )
V_157 = V_42 ;
}
if ( V_154 [ V_94 ] )
V_34 -> V_47 -> V_93 = F_79 ( F_80 ( V_154 [ V_94 ] ) ) ;
F_30 ( V_34 , V_157 ) ;
return 0 ;
V_132:
F_70 () ;
return V_12 ;
}
static int
F_81 ( struct V_152 * V_153 , struct V_43 * V_47 ,
const struct V_50 * V_51 ,
const struct V_111 * const V_154 [] )
{
return - V_164 ;
}
static int
F_82 ( struct V_152 * V_153 , struct V_43 * V_47 ,
const struct V_50 * V_51 ,
const struct V_111 * const V_154 [] )
{
struct V_52 * V_53 = F_39 ( V_51 ) ;
T_2 V_1 = F_77 ( V_53 -> V_75 ) ;
struct V_3 * V_32 ;
struct V_165 * V_166 = NULL ;
int V_167 = 0 ;
if ( V_154 [ V_168 ] ) {
V_166 = F_54 ( V_154 [ V_168 ] ) ;
switch ( V_166 -> V_169 ) {
case V_170 :
return F_83 ( F_77 ( V_166 -> V_72 ) ,
& V_171 ) ;
case V_172 :
return F_84 ( F_77 ( V_166 -> V_72 ) ,
& V_171 ) ;
}
}
F_69 () ;
V_32 = F_2 ( V_1 ) ;
if ( V_32 && V_32 -> V_18 != F_78 ( V_47 ) . V_10 ) {
V_167 = - V_159 ;
goto V_132;
}
if ( V_166 != NULL ) {
switch ( V_166 -> V_169 ) {
case V_173 :
if ( V_32 ) {
V_167 = - V_174 ;
goto V_132;
}
V_32 = F_4 ( V_1 , F_78 ( V_47 ) . V_10 ) ;
if ( F_85 ( V_32 ) ) {
V_167 = F_86 ( V_32 ) ;
goto V_132;
}
break;
case V_175 :
if ( ! V_32 ) {
V_167 = - V_158 ;
goto V_132;
}
F_21 ( V_32 ) ;
break;
case V_170 :
case V_172 :
break;
default:
V_167 = - V_164 ;
break;
}
}
if ( V_154 [ V_176 ] ) {
struct V_177 * V_178 ;
if ( ! V_32 ) {
V_167 = - V_158 ;
goto V_132;
}
V_178 = F_54 ( V_154 [ V_176 ] ) ;
F_66 ( V_32 , V_178 -> V_22 ,
F_79 ( V_178 -> V_21 ) ) ;
}
if ( V_154 [ V_179 ] ) {
T_6 * V_19 ;
if ( ! V_32 ) {
V_167 = - V_158 ;
goto V_132;
}
V_19 = F_54 ( V_154 [ V_179 ] ) ;
F_25 ( & V_32 -> V_24 ) ;
V_32 -> V_19 = F_79 ( * V_19 ) ;
F_28 ( & V_32 -> V_24 ) ;
}
V_132:
F_70 () ;
return V_167 ;
}
static struct V_6 * F_87 ( struct V_180 * V_181 )
{
struct V_182 * V_183 = V_181 -> V_184 ;
if ( ! V_183 )
return NULL ;
for ( V_183 -> V_185 = 0 ; V_183 -> V_185 < V_2 ; V_183 -> V_185 ++ ) {
if ( ! F_88 ( & V_9 [ V_183 -> V_185 ] ) )
return V_9 [ V_183 -> V_185 ] . V_186 ;
}
return NULL ;
}
static struct V_6 * F_89 ( struct V_180 * V_181 , struct V_6 * V_11 )
{
struct V_182 * V_183 = V_181 -> V_184 ;
V_11 = V_11 -> V_41 ;
while ( ! V_11 ) {
if ( ++ V_183 -> V_185 >= V_2 )
return NULL ;
V_11 = V_9 [ V_183 -> V_185 ] . V_186 ;
}
return V_11 ;
}
static struct V_6 * F_90 ( struct V_180 * V_181 , T_7 V_7 )
{
struct V_6 * V_5 ;
V_5 = F_87 ( V_181 ) ;
if ( V_5 )
while ( V_7 && ( V_5 = F_89 ( V_181 , V_5 ) ) )
V_7 -- ;
return V_7 ? NULL : V_5 ;
}
static void * F_91 ( struct V_180 * V_181 , T_7 * V_7 )
__acquires( V_13 )
{
F_5 ( & V_13 ) ;
return F_90 ( V_181 , * V_7 ) ;
}
static void * F_92 ( struct V_180 * V_187 , void * V_188 , T_7 * V_7 )
{
( * V_7 ) ++ ;
return F_89 ( V_187 , V_188 ) ;
}
static void F_93 ( struct V_180 * V_187 , void * V_188 )
__releases( V_13 )
{
F_11 ( & V_13 ) ;
}
static int F_94 ( struct V_180 * V_187 , void * V_188 )
{
const struct V_3 * V_8 = V_188 ;
return F_95 ( V_187 , L_7 ,
V_8 -> V_1 ,
V_8 -> V_18 , V_8 -> V_36 ,
V_8 -> V_22 , V_8 -> V_21 ,
V_8 -> V_128 , V_8 -> V_131 ,
F_96 ( & V_8 -> V_76 ) , 1 ) ;
}
static int F_97 ( struct V_189 * V_189 , struct V_190 * V_190 )
{
return F_98 ( V_190 , & V_191 ,
sizeof( struct V_182 ) ) ;
}
static int T_8 F_99 ( void )
{
int V_38 , V_138 = - V_17 ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ )
F_100 ( & V_9 [ V_38 ] ) ;
F_101 ( & V_192 ) ;
V_138 = F_102 ( & V_193 ) ;
if ( V_138 < 0 ) {
F_51 ( V_120 L_8 ) ;
goto V_194;
}
#ifdef F_103
if ( ! F_104 ( L_9 , 0440 ,
V_195 , & V_196 ) )
goto V_197;
#endif
F_105 ( & V_198 ) ;
return V_138 ;
#ifdef F_103
V_197:
F_106 ( & V_193 ) ;
#endif
V_194:
F_107 ( & V_192 ) ;
return V_138 ;
}
static void T_9 F_108 ( void )
{
F_109 ( & V_171 ) ;
F_110 ( & V_198 ) ;
#ifdef F_103
F_111 ( L_9 , V_195 ) ;
#endif
F_106 ( & V_193 ) ;
F_107 ( & V_192 ) ;
F_112 () ;
}
