static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline T_1 F_3 ( T_2 V_4 )
{
return ( ( V_4 >> 8 ) ^ V_4 ) % V_5 ;
}
static struct V_6 *
F_4 ( struct V_1 * V_7 , T_2 V_4 )
{
struct V_8 * V_9 ;
struct V_6 * V_10 ;
V_9 = & V_7 -> V_11 [ F_3 ( V_4 ) ] ;
F_5 (inst, head, hlist) {
if ( V_10 -> V_4 == V_4 )
return V_10 ;
}
return NULL ;
}
static struct V_6 *
F_6 ( struct V_1 * V_7 , T_2 V_4 ,
int V_12 )
{
struct V_6 * V_10 ;
unsigned int V_13 ;
int V_14 ;
F_7 ( & V_7 -> V_15 ) ;
if ( F_4 ( V_7 , V_4 ) ) {
V_14 = - V_16 ;
goto V_17;
}
V_10 = F_8 ( sizeof( * V_10 ) , V_18 ) ;
if ( ! V_10 ) {
V_14 = - V_19 ;
goto V_17;
}
V_10 -> V_4 = V_4 ;
V_10 -> V_20 = V_12 ;
V_10 -> V_21 = V_22 ;
V_10 -> V_23 = V_24 ;
V_10 -> V_25 = V_26 ;
F_9 ( & V_10 -> V_27 ) ;
F_10 ( & V_10 -> V_28 ) ;
if ( ! F_11 ( V_29 ) ) {
V_14 = - V_30 ;
goto V_31;
}
V_13 = F_3 ( V_4 ) ;
F_12 ( & V_10 -> V_32 , & V_7 -> V_11 [ V_13 ] ) ;
F_13 ( & V_7 -> V_15 ) ;
return V_10 ;
V_31:
F_14 ( V_10 ) ;
V_17:
F_13 ( & V_7 -> V_15 ) ;
return F_15 ( V_14 ) ;
}
static void
F_16 ( struct V_33 * V_9 )
{
struct V_6 * V_10 = F_17 ( V_9 , struct V_6 ,
V_34 ) ;
F_18 ( V_10 , NULL , 0 ) ;
F_14 ( V_10 ) ;
F_19 ( V_29 ) ;
}
static void
F_20 ( struct V_6 * V_10 )
{
F_21 ( & V_10 -> V_32 ) ;
F_22 ( & V_10 -> V_34 , F_16 ) ;
}
static void
F_23 ( struct V_1 * V_7 , struct V_6 * V_10 )
{
F_7 ( & V_7 -> V_15 ) ;
F_20 ( V_10 ) ;
F_13 ( & V_7 -> V_15 ) ;
}
static inline void
F_24 ( struct V_6 * V_35 , struct V_36 * V_37 )
{
F_25 ( & V_37 -> V_38 , & V_35 -> V_28 ) ;
V_35 -> V_39 ++ ;
}
static void
F_26 ( struct V_6 * V_35 , struct V_36 * V_37 )
{
F_27 ( & V_37 -> V_38 ) ;
V_35 -> V_39 -- ;
}
static struct V_36 *
F_28 ( struct V_6 * V_35 , unsigned int V_40 )
{
struct V_36 * V_37 = NULL , * V_41 ;
F_29 ( & V_35 -> V_27 ) ;
F_30 (i, &queue->queue_list, list) {
if ( V_41 -> V_40 == V_40 ) {
V_37 = V_41 ;
break;
}
}
if ( V_37 )
F_26 ( V_35 , V_37 ) ;
F_31 ( & V_35 -> V_27 ) ;
return V_37 ;
}
static void
F_18 ( struct V_6 * V_35 , T_3 V_42 , unsigned long V_43 )
{
struct V_36 * V_37 , * V_44 ;
F_29 ( & V_35 -> V_27 ) ;
F_32 (entry, next, &queue->queue_list, list) {
if ( ! V_42 || V_42 ( V_37 , V_43 ) ) {
F_27 ( & V_37 -> V_38 ) ;
V_35 -> V_39 -- ;
F_33 ( V_37 , V_45 ) ;
}
}
F_31 ( & V_35 -> V_27 ) ;
}
static int
F_34 ( struct V_46 * V_47 , struct V_46 * V_48 ,
bool V_49 )
{
T_4 V_50 = 0 ;
if ( V_48 -> V_51 == V_52 )
V_50 = V_53 ;
else if ( V_49 )
V_50 = V_54 ;
if ( F_35 ( V_48 ) )
V_50 |= V_55 ;
return V_50 ? F_36 ( V_47 , V_56 , F_37 ( V_50 ) ) : 0 ;
}
static int F_38 ( struct V_46 * V_57 , struct V_58 * V_59 )
{
const struct V_60 * V_60 ;
if ( V_59 -> V_61 == V_62 )
return 0 ;
F_39 ( & V_59 -> V_63 ) ;
if ( V_59 -> V_64 && V_59 -> V_64 -> V_65 ) {
V_60 = V_59 -> V_64 -> V_65 -> V_66 ;
if ( F_36 ( V_57 , V_67 ,
F_37 ( F_40 ( & V_68 , V_60 -> V_69 ) ) ) )
goto V_70;
if ( F_36 ( V_57 , V_71 ,
F_37 ( F_41 ( & V_68 , V_60 -> V_72 ) ) ) )
goto V_70;
}
F_42 ( & V_59 -> V_63 ) ;
return 0 ;
V_70:
F_42 ( & V_59 -> V_63 ) ;
return - 1 ;
}
static struct V_46 *
F_43 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 ,
T_5 * * V_73 )
{
T_6 V_74 ;
T_6 V_75 = 0 , V_76 = 0 ;
unsigned int V_77 = 0 ;
struct V_46 * V_57 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
struct V_46 * V_86 = V_37 -> V_57 ;
struct V_87 * V_88 ;
struct V_87 * V_89 ;
struct V_90 * V_91 = NULL ;
enum V_92 V_93 ( V_94 ) ;
bool V_49 ;
V_74 = F_44 ( sizeof( struct V_84 ) )
+ F_45 ( sizeof( struct V_80 ) )
+ F_45 ( sizeof( V_95 ) )
+ F_45 ( sizeof( V_95 ) )
#ifdef F_46
+ F_45 ( sizeof( V_95 ) )
+ F_45 ( sizeof( V_95 ) )
#endif
+ F_45 ( sizeof( V_95 ) )
+ F_45 ( sizeof( struct V_96 ) )
+ F_45 ( sizeof( V_95 ) )
+ F_45 ( sizeof( V_95 ) ) ;
if ( V_86 -> V_97 . V_98 )
V_74 += F_45 ( sizeof( struct V_99 ) ) ;
if ( V_37 -> V_100 <= V_101 ||
( V_37 -> V_100 == V_102 && V_86 -> V_59 == NULL ) )
V_49 = ! F_47 ( V_86 ) ;
else
V_49 = false ;
V_89 = V_37 -> V_89 ;
switch ( (enum V_103 ) F_48 ( V_35 -> V_25 ) ) {
case V_104 :
case V_26 :
break;
case V_105 :
if ( ! ( V_35 -> V_50 & V_106 ) &&
V_86 -> V_51 == V_52 &&
F_49 ( V_86 ) )
return NULL ;
V_75 = F_48 ( V_35 -> V_23 ) ;
if ( V_75 > V_86 -> V_107 )
V_75 = V_86 -> V_107 ;
V_77 = F_50 ( V_86 ) ;
V_77 = F_51 (unsigned int, hlen, data_len) ;
V_74 += sizeof( struct V_78 ) + V_77 ;
V_76 = V_86 -> V_107 ;
break;
}
if ( V_35 -> V_50 & V_108 )
V_91 = F_52 ( V_86 , & V_74 , & V_94 ) ;
if ( V_35 -> V_50 & V_109 ) {
V_74 += ( F_45 ( sizeof( V_95 ) )
+ F_45 ( sizeof( V_95 ) ) ) ;
}
V_57 = F_53 ( V_2 , V_74 , V_35 -> V_20 ,
V_18 ) ;
if ( ! V_57 ) {
F_54 ( V_86 ) ;
return NULL ;
}
V_83 = F_55 ( V_57 , 0 , 0 ,
V_110 << 8 | V_111 ,
sizeof( struct V_84 ) , 0 ) ;
if ( ! V_83 ) {
F_54 ( V_86 ) ;
F_56 ( V_57 ) ;
return NULL ;
}
V_85 = F_57 ( V_83 ) ;
V_85 -> V_112 = V_37 -> V_113 ;
V_85 -> V_114 = V_115 ;
V_85 -> V_116 = F_58 ( V_35 -> V_4 ) ;
V_79 = F_59 ( V_57 , V_117 , sizeof( * V_81 ) ) ;
V_81 = F_60 ( V_79 ) ;
V_81 -> V_118 = V_86 -> V_119 ;
V_81 -> V_100 = V_37 -> V_100 ;
* V_73 = & V_81 -> V_120 ;
V_88 = V_37 -> V_88 ;
if ( V_88 ) {
#ifndef F_46
if ( F_36 ( V_57 , V_121 , F_37 ( V_88 -> V_122 ) ) )
goto V_70;
#else
if ( V_37 -> V_113 == V_123 ) {
if ( F_36 ( V_57 , V_124 ,
F_37 ( V_88 -> V_122 ) ) ||
F_36 ( V_57 , V_121 ,
F_37 ( F_61 ( V_88 ) -> V_125 -> V_126 -> V_122 ) ) )
goto V_70;
} else {
if ( F_36 ( V_57 , V_121 ,
F_37 ( V_88 -> V_122 ) ) )
goto V_70;
if ( V_86 -> V_127 && V_86 -> V_127 -> V_128 &&
F_36 ( V_57 , V_124 ,
F_37 ( V_86 -> V_127 -> V_128 -> V_122 ) ) )
goto V_70;
}
#endif
}
if ( V_89 ) {
#ifndef F_46
if ( F_36 ( V_57 , V_129 , F_37 ( V_89 -> V_122 ) ) )
goto V_70;
#else
if ( V_37 -> V_113 == V_123 ) {
if ( F_36 ( V_57 , V_130 ,
F_37 ( V_89 -> V_122 ) ) ||
F_36 ( V_57 , V_129 ,
F_37 ( F_61 ( V_89 ) -> V_125 -> V_126 -> V_122 ) ) )
goto V_70;
} else {
if ( F_36 ( V_57 , V_129 ,
F_37 ( V_89 -> V_122 ) ) )
goto V_70;
if ( V_86 -> V_127 && V_86 -> V_127 -> V_131 &&
F_36 ( V_57 , V_130 ,
F_37 ( V_86 -> V_127 -> V_131 -> V_122 ) ) )
goto V_70;
}
#endif
}
if ( V_86 -> V_132 &&
F_36 ( V_57 , V_133 , F_37 ( V_86 -> V_132 ) ) )
goto V_70;
if ( V_88 && V_86 -> V_126 &&
V_86 -> V_134 != V_86 -> V_135 ) {
struct V_96 V_136 ;
int V_107 ;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_107 = F_62 ( V_86 , V_136 . V_137 ) ;
if ( V_107 ) {
V_136 . V_138 = F_58 ( V_107 ) ;
if ( F_63 ( V_57 , V_139 , sizeof( V_136 ) , & V_136 ) )
goto V_70;
}
}
if ( V_86 -> V_97 . V_98 ) {
struct V_99 V_140 ;
struct V_141 V_142 = F_64 ( V_86 -> V_97 ) ;
V_140 . V_143 = F_65 ( V_142 . V_144 ) ;
V_140 . V_145 = F_65 ( V_142 . V_146 ) ;
if ( F_63 ( V_57 , V_147 , sizeof( V_140 ) , & V_140 ) )
goto V_70;
}
if ( ( V_35 -> V_50 & V_109 ) && V_86 -> V_59 &&
F_38 ( V_57 , V_86 -> V_59 ) < 0 )
goto V_70;
if ( V_91 && F_66 ( V_57 , V_91 , V_94 ) < 0 )
goto V_70;
if ( V_76 > V_75 &&
F_36 ( V_57 , V_148 , F_37 ( V_76 ) ) )
goto V_70;
if ( F_34 ( V_57 , V_86 , V_49 ) )
goto V_70;
if ( V_75 ) {
struct V_78 * V_79 ;
if ( F_67 ( V_57 ) < sizeof( * V_79 ) + V_77 )
goto V_70;
V_79 = (struct V_78 * ) F_68 ( V_57 , sizeof( * V_79 ) ) ;
V_79 -> V_149 = V_150 ;
V_79 -> V_151 = F_69 ( V_75 ) ;
if ( F_70 ( V_57 , V_86 , V_75 , V_77 ) )
goto V_70;
}
V_83 -> V_152 = V_57 -> V_107 ;
return V_57 ;
V_70:
F_54 ( V_86 ) ;
F_56 ( V_57 ) ;
F_71 ( L_1 ) ;
return NULL ;
}
static int
F_72 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 )
{
struct V_46 * V_153 ;
int V_14 = - V_154 ;
T_5 * V_73 ;
int V_155 = 0 ;
V_153 = F_43 ( V_2 , V_35 , V_37 , & V_73 ) ;
if ( V_153 == NULL ) {
V_14 = - V_19 ;
goto V_156;
}
F_29 ( & V_35 -> V_27 ) ;
if ( V_35 -> V_39 >= V_35 -> V_21 ) {
if ( V_35 -> V_50 & V_157 ) {
V_155 = 1 ;
V_14 = 0 ;
} else {
V_35 -> V_158 ++ ;
F_73 ( L_2 ,
V_35 -> V_39 ) ;
}
goto V_159;
}
V_37 -> V_40 = ++ V_35 -> V_160 ;
* V_73 = F_37 ( V_37 -> V_40 ) ;
V_14 = F_74 ( V_153 , V_2 , V_35 -> V_20 , V_161 ) ;
if ( V_14 < 0 ) {
V_35 -> V_162 ++ ;
goto V_163;
}
F_24 ( V_35 , V_37 ) ;
F_31 ( & V_35 -> V_27 ) ;
return 0 ;
V_159:
F_56 ( V_153 ) ;
V_163:
F_31 ( & V_35 -> V_27 ) ;
if ( V_155 )
F_33 ( V_37 , V_164 ) ;
V_156:
return V_14 ;
}
static struct V_36 *
F_75 ( struct V_36 * V_165 )
{
struct V_36 * V_37 = F_76 ( V_165 , V_165 -> V_74 , V_18 ) ;
if ( V_37 ) {
if ( F_77 ( V_37 ) )
return V_37 ;
F_14 ( V_37 ) ;
}
return NULL ;
}
static void F_78 ( struct V_46 * V_57 )
{
if ( V_57 -> V_127 )
F_79 ( V_57 , V_57 -> V_135 - V_57 -> V_134 ) ;
}
static void F_80 ( struct V_46 * V_57 )
{
if ( V_57 -> V_127 )
F_81 ( V_57 , V_57 -> V_135 - V_57 -> V_134 ) ;
}
static void F_82 ( struct V_36 * V_37 )
{
F_83 ( V_37 ) ;
F_14 ( V_37 ) ;
}
static int
F_84 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_46 * V_57 , struct V_36 * V_37 )
{
int V_166 = - V_19 ;
struct V_36 * V_167 ;
F_80 ( V_57 ) ;
if ( V_57 -> V_44 == NULL ) {
struct V_46 * V_168 = V_37 -> V_57 ;
V_37 -> V_57 = V_57 ;
V_166 = F_72 ( V_2 , V_35 , V_37 ) ;
if ( V_166 )
V_37 -> V_57 = V_168 ;
return V_166 ;
}
V_57 -> V_44 = NULL ;
V_167 = F_75 ( V_37 ) ;
if ( V_167 ) {
V_167 -> V_57 = V_57 ;
V_166 = F_72 ( V_2 , V_35 , V_167 ) ;
if ( V_166 )
F_82 ( V_167 ) ;
}
return V_166 ;
}
static int
F_85 ( struct V_36 * V_37 , unsigned int V_169 )
{
unsigned int V_170 ;
struct V_6 * V_35 ;
struct V_46 * V_57 , * V_171 ;
int V_14 = - V_154 ;
struct V_2 * V_2 = F_86 ( V_37 -> V_88 ?
V_37 -> V_88 : V_37 -> V_89 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_169 ) ;
if ( ! V_35 )
return - V_172 ;
if ( V_35 -> V_25 == V_26 )
return - V_173 ;
V_57 = V_37 -> V_57 ;
switch ( V_37 -> V_113 ) {
case V_174 :
V_57 -> V_119 = F_58 ( V_175 ) ;
break;
case V_176 :
V_57 -> V_119 = F_58 ( V_177 ) ;
break;
}
if ( ( V_35 -> V_50 & V_106 ) || ! F_35 ( V_57 ) )
return F_72 ( V_2 , V_35 , V_37 ) ;
F_78 ( V_57 ) ;
V_171 = F_87 ( V_57 , 0 ) ;
if ( F_88 ( V_171 ) )
goto V_178;
V_170 = 0 ;
V_14 = 0 ;
do {
struct V_46 * V_153 = V_171 -> V_44 ;
if ( V_14 == 0 )
V_14 = F_84 ( V_2 , V_35 ,
V_171 , V_37 ) ;
if ( V_14 == 0 )
V_170 ++ ;
else
F_56 ( V_171 ) ;
V_171 = V_153 ;
} while ( V_171 );
if ( V_170 ) {
if ( V_14 )
F_82 ( V_37 ) ;
F_56 ( V_57 ) ;
return 0 ;
}
V_178:
F_80 ( V_57 ) ;
return V_14 ;
}
static int
F_89 ( void * V_43 , int V_75 , struct V_36 * V_165 , int V_179 )
{
struct V_46 * V_153 ;
if ( V_179 < 0 ) {
if ( F_90 ( V_165 -> V_57 , V_75 ) )
return - V_19 ;
} else if ( V_179 > 0 ) {
if ( V_75 > 0xFFFF )
return - V_173 ;
if ( V_179 > F_67 ( V_165 -> V_57 ) ) {
V_153 = F_91 ( V_165 -> V_57 , F_92 ( V_165 -> V_57 ) ,
V_179 , V_18 ) ;
if ( ! V_153 ) {
F_93 ( V_180 L_3
L_4 ) ;
return - V_19 ;
}
F_56 ( V_165 -> V_57 ) ;
V_165 -> V_57 = V_153 ;
}
F_68 ( V_165 -> V_57 , V_179 ) ;
}
if ( ! F_94 ( V_165 -> V_57 , V_75 ) )
return - V_19 ;
F_95 ( V_165 -> V_57 , V_43 , V_75 ) ;
V_165 -> V_57 -> V_51 = V_181 ;
return 0 ;
}
static int
F_96 ( struct V_6 * V_35 ,
unsigned char V_182 , unsigned int V_183 )
{
int V_184 = 0 ;
F_29 ( & V_35 -> V_27 ) ;
switch ( V_182 ) {
case V_26 :
case V_104 :
V_35 -> V_25 = V_182 ;
V_35 -> V_23 = 0 ;
break;
case V_105 :
V_35 -> V_25 = V_182 ;
if ( V_183 == 0 || V_183 > V_24 )
V_35 -> V_23 = V_24 ;
else
V_35 -> V_23 = V_183 ;
break;
default:
V_184 = - V_173 ;
}
F_31 ( & V_35 -> V_27 ) ;
return V_184 ;
}
static int
F_97 ( struct V_36 * V_37 , unsigned long V_122 )
{
if ( V_37 -> V_88 )
if ( V_37 -> V_88 -> V_122 == V_122 )
return 1 ;
if ( V_37 -> V_89 )
if ( V_37 -> V_89 -> V_122 == V_122 )
return 1 ;
#ifdef F_46
if ( V_37 -> V_57 -> V_127 ) {
if ( V_37 -> V_57 -> V_127 -> V_128 &&
V_37 -> V_57 -> V_127 -> V_128 -> V_122 == V_122 )
return 1 ;
if ( V_37 -> V_57 -> V_127 -> V_131 &&
V_37 -> V_57 -> V_127 -> V_131 -> V_122 == V_122 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_98 ( struct V_2 * V_2 , int V_122 )
{
int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
F_99 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_97 , V_122 ) ;
}
F_100 () ;
}
static int
F_101 ( struct V_185 * V_186 ,
unsigned long V_187 , void * V_188 )
{
struct V_87 * V_126 = F_102 ( V_188 ) ;
if ( V_187 == V_189 )
F_98 ( F_86 ( V_126 ) , V_126 -> V_122 ) ;
return V_190 ;
}
static int
F_103 ( struct V_185 * V_186 ,
unsigned long V_187 , void * V_188 )
{
struct V_191 * V_192 = V_188 ;
struct V_1 * V_7 = F_1 ( V_192 -> V_2 ) ;
if ( V_187 == V_193 && V_192 -> V_119 == V_194 ) {
int V_41 ;
F_7 ( & V_7 -> V_15 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_195 * V_196 ;
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_104 (inst, t2, head, hlist) {
if ( V_192 -> V_12 == V_10 -> V_20 )
F_20 ( V_10 ) ;
}
}
F_13 ( & V_7 -> V_15 ) ;
}
return V_190 ;
}
static struct V_6 *
F_105 ( struct V_1 * V_7 , T_7 V_4 , int V_197 )
{
struct V_6 * V_35 ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
return F_15 ( - V_198 ) ;
if ( V_35 -> V_20 != V_197 )
return F_15 ( - V_199 ) ;
return V_35 ;
}
static struct V_200 *
F_106 ( const struct V_78 * const V_201 [] )
{
struct V_200 * V_202 ;
unsigned int V_203 ;
if ( ! V_201 [ V_204 ] )
return NULL ;
V_202 = F_60 ( V_201 [ V_204 ] ) ;
V_203 = F_107 ( V_202 -> V_203 ) & V_205 ;
if ( V_203 > V_206 || V_203 == V_207 )
return NULL ;
return V_202 ;
}
static int F_108 ( unsigned int V_40 , unsigned int V_208 )
{
return ( int ) ( V_40 - V_208 ) > 0 ;
}
static int
F_109 ( struct V_58 * V_209 , struct V_46 * V_57 ,
const struct V_82 * V_83 ,
const struct V_78 * const V_201 [] )
{
struct V_84 * V_85 = F_57 ( V_83 ) ;
struct V_36 * V_37 , * V_210 ;
unsigned int V_203 , V_211 ;
struct V_200 * V_202 ;
struct V_6 * V_35 ;
F_110 ( V_212 ) ;
T_7 V_4 = F_111 ( V_85 -> V_116 ) ;
struct V_2 * V_2 = F_112 ( V_209 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_105 ( V_7 , V_4 ,
F_113 ( V_57 ) . V_12 ) ;
if ( F_88 ( V_35 ) )
return F_114 ( V_35 ) ;
V_202 = F_106 ( V_201 ) ;
if ( ! V_202 )
return - V_173 ;
V_203 = F_107 ( V_202 -> V_203 ) ;
V_211 = F_107 ( V_202 -> V_40 ) ;
F_29 ( & V_35 -> V_27 ) ;
F_32 (entry, tmp, &queue->queue_list, list) {
if ( F_108 ( V_37 -> V_40 , V_211 ) )
break;
F_26 ( V_35 , V_37 ) ;
F_25 ( & V_37 -> V_38 , & V_212 ) ;
}
F_31 ( & V_35 -> V_27 ) ;
if ( F_115 ( & V_212 ) )
return - V_213 ;
F_32 (entry, tmp, &batch_list, list) {
if ( V_201 [ V_133 ] )
V_37 -> V_57 -> V_132 = F_107 ( F_116 ( V_201 [ V_133 ] ) ) ;
F_33 ( V_37 , V_203 ) ;
}
return 0 ;
}
static int
F_117 ( struct V_58 * V_209 , struct V_46 * V_57 ,
const struct V_82 * V_83 ,
const struct V_78 * const V_201 [] )
{
struct V_84 * V_85 = F_57 ( V_83 ) ;
T_2 V_4 = F_111 ( V_85 -> V_116 ) ;
struct V_200 * V_202 ;
struct V_6 * V_35 ;
unsigned int V_203 ;
struct V_36 * V_37 ;
enum V_92 V_93 ( V_94 ) ;
struct V_90 * V_91 = NULL ;
struct V_2 * V_2 = F_112 ( V_209 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
V_35 = F_105 ( V_7 , V_4 ,
F_113 ( V_57 ) . V_12 ) ;
if ( F_88 ( V_35 ) )
return F_114 ( V_35 ) ;
V_202 = F_106 ( V_201 ) ;
if ( ! V_202 )
return - V_173 ;
V_203 = F_107 ( V_202 -> V_203 ) ;
V_37 = F_28 ( V_35 , F_107 ( V_202 -> V_40 ) ) ;
if ( V_37 == NULL )
return - V_213 ;
if ( V_201 [ V_214 ] ) {
V_91 = F_118 ( V_37 -> V_57 , V_201 [ V_214 ] , & V_94 ) ;
if ( V_91 && V_201 [ V_215 ] ) {
F_119 ( V_91 , V_201 [ V_215 ] ,
F_113 ( V_57 ) . V_12 ,
F_120 ( V_83 ) ) ;
}
}
if ( V_201 [ V_150 ] ) {
T_7 V_216 = V_151 ( V_201 [ V_150 ] ) ;
int V_179 = V_216 - V_37 -> V_57 -> V_107 ;
if ( F_89 ( F_60 ( V_201 [ V_150 ] ) ,
V_216 , V_37 , V_179 ) < 0 )
V_203 = V_45 ;
if ( V_91 )
F_121 ( V_37 -> V_57 , V_91 , V_94 , V_179 ) ;
}
if ( V_201 [ V_133 ] )
V_37 -> V_57 -> V_132 = F_107 ( F_116 ( V_201 [ V_133 ] ) ) ;
F_33 ( V_37 , V_203 ) ;
return 0 ;
}
static int
F_122 ( struct V_58 * V_209 , struct V_46 * V_57 ,
const struct V_82 * V_83 ,
const struct V_78 * const V_201 [] )
{
return - V_217 ;
}
static int
F_123 ( struct V_58 * V_209 , struct V_46 * V_57 ,
const struct V_82 * V_83 ,
const struct V_78 * const V_201 [] )
{
struct V_84 * V_85 = F_57 ( V_83 ) ;
T_2 V_4 = F_111 ( V_85 -> V_116 ) ;
struct V_6 * V_35 ;
struct V_218 * V_219 = NULL ;
struct V_2 * V_2 = F_112 ( V_209 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
int V_166 = 0 ;
if ( V_201 [ V_220 ] ) {
V_219 = F_60 ( V_201 [ V_220 ] ) ;
switch ( V_219 -> V_221 ) {
case V_222 : return 0 ;
case V_223 : return 0 ;
}
}
F_99 () ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( V_35 && V_35 -> V_20 != F_113 ( V_57 ) . V_12 ) {
V_166 = - V_199 ;
goto V_163;
}
if ( V_219 != NULL ) {
switch ( V_219 -> V_221 ) {
case V_224 :
if ( V_35 ) {
V_166 = - V_225 ;
goto V_163;
}
V_35 = F_6 ( V_7 , V_4 ,
F_113 ( V_57 ) . V_12 ) ;
if ( F_88 ( V_35 ) ) {
V_166 = F_114 ( V_35 ) ;
goto V_163;
}
break;
case V_226 :
if ( ! V_35 ) {
V_166 = - V_198 ;
goto V_163;
}
F_23 ( V_7 , V_35 ) ;
break;
case V_222 :
case V_223 :
break;
default:
V_166 = - V_217 ;
break;
}
}
if ( V_201 [ V_227 ] ) {
struct V_228 * V_229 ;
if ( ! V_35 ) {
V_166 = - V_198 ;
goto V_163;
}
V_229 = F_60 ( V_201 [ V_227 ] ) ;
F_96 ( V_35 , V_229 -> V_25 ,
F_107 ( V_229 -> V_23 ) ) ;
}
if ( V_201 [ V_230 ] ) {
T_5 * V_21 ;
if ( ! V_35 ) {
V_166 = - V_198 ;
goto V_163;
}
V_21 = F_60 ( V_201 [ V_230 ] ) ;
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_21 = F_107 ( * V_21 ) ;
F_31 ( & V_35 -> V_27 ) ;
}
if ( V_201 [ V_231 ] ) {
T_4 V_50 , V_232 ;
if ( ! V_35 ) {
V_166 = - V_198 ;
goto V_163;
}
if ( ! V_201 [ V_233 ] ) {
V_166 = - V_173 ;
goto V_163;
}
V_50 = F_107 ( F_116 ( V_201 [ V_231 ] ) ) ;
V_232 = F_107 ( F_116 ( V_201 [ V_233 ] ) ) ;
if ( V_50 >= V_234 ) {
V_166 = - V_235 ;
goto V_163;
}
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_50 &= ~ V_232 ;
V_35 -> V_50 |= V_50 & V_232 ;
F_31 ( & V_35 -> V_27 ) ;
}
V_163:
F_100 () ;
return V_166 ;
}
static struct V_195 * F_124 ( struct V_236 * V_237 )
{
struct V_238 * V_239 = V_237 -> V_240 ;
struct V_2 * V_2 ;
struct V_1 * V_7 ;
if ( ! V_239 )
return NULL ;
V_2 = F_125 ( V_237 ) ;
V_7 = F_1 ( V_2 ) ;
for ( V_239 -> V_241 = 0 ; V_239 -> V_241 < V_5 ; V_239 -> V_241 ++ ) {
if ( ! F_126 ( & V_7 -> V_11 [ V_239 -> V_241 ] ) )
return V_7 -> V_11 [ V_239 -> V_241 ] . V_242 ;
}
return NULL ;
}
static struct V_195 * F_127 ( struct V_236 * V_237 , struct V_195 * V_13 )
{
struct V_238 * V_239 = V_237 -> V_240 ;
struct V_2 * V_2 = F_125 ( V_237 ) ;
V_13 = V_13 -> V_44 ;
while ( ! V_13 ) {
struct V_1 * V_7 ;
if ( ++ V_239 -> V_241 >= V_5 )
return NULL ;
V_7 = F_1 ( V_2 ) ;
V_13 = V_7 -> V_11 [ V_239 -> V_241 ] . V_242 ;
}
return V_13 ;
}
static struct V_195 * F_128 ( struct V_236 * V_237 , T_8 V_243 )
{
struct V_195 * V_9 ;
V_9 = F_124 ( V_237 ) ;
if ( V_9 )
while ( V_243 && ( V_9 = F_127 ( V_237 , V_9 ) ) )
V_243 -- ;
return V_243 ? NULL : V_9 ;
}
static void * F_129 ( struct V_236 * V_244 , T_8 * V_243 )
__acquires( nfnl_queue_pernet( seq_file_net( V_244 )
static void * F_130 ( struct V_236 * V_244 , void * V_245 , T_8 * V_243 )
{
( * V_243 ) ++ ;
return F_127 ( V_244 , V_245 ) ;
}
static void F_131 ( struct V_236 * V_244 , void * V_245 )
__releases( nfnl_queue_pernet( seq_file_net( V_244 )
static int F_132 ( struct V_236 * V_244 , void * V_245 )
{
const struct V_6 * V_10 = V_245 ;
return F_133 ( V_244 , L_5 ,
V_10 -> V_4 ,
V_10 -> V_20 , V_10 -> V_39 ,
V_10 -> V_25 , V_10 -> V_23 ,
V_10 -> V_158 , V_10 -> V_162 ,
V_10 -> V_160 , 1 ) ;
}
static int F_134 ( struct V_246 * V_246 , struct V_65 * V_65 )
{
return F_135 ( V_246 , V_65 , & V_247 ,
sizeof( struct V_238 ) ) ;
}
static int T_9 F_136 ( struct V_2 * V_2 )
{
unsigned int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ )
F_137 ( & V_7 -> V_11 [ V_41 ] ) ;
F_9 ( & V_7 -> V_15 ) ;
#ifdef F_138
if ( ! F_139 ( L_6 , 0440 ,
V_2 -> V_248 . V_249 , & V_250 ) )
return - V_19 ;
#endif
return 0 ;
}
static void T_10 F_140 ( struct V_2 * V_2 )
{
#ifdef F_138
F_141 ( L_6 , V_2 -> V_248 . V_249 ) ;
#endif
}
static int T_11 F_142 ( void )
{
int V_184 = - V_19 ;
F_143 ( & V_251 ) ;
V_184 = F_144 ( & V_252 ) ;
if ( V_184 < 0 ) {
F_145 ( L_7 ) ;
goto V_253;
}
V_184 = F_146 ( & V_254 ) ;
if ( V_184 < 0 ) {
F_145 ( L_8 ) ;
goto V_255;
}
F_147 ( & V_256 ) ;
F_148 ( & V_257 ) ;
return V_184 ;
V_255:
F_149 ( & V_252 ) ;
V_253:
F_150 ( & V_251 ) ;
return V_184 ;
}
static void T_12 F_151 ( void )
{
F_152 () ;
F_153 ( & V_256 ) ;
F_154 ( & V_254 ) ;
F_149 ( & V_252 ) ;
F_150 ( & V_251 ) ;
F_155 () ;
}
