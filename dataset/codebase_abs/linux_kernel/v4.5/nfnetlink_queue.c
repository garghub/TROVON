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
F_6 ( struct V_1 * V_7 , T_2 V_4 , T_3 V_12 )
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
F_18 ( struct V_6 * V_35 , T_4 V_42 , unsigned long V_43 )
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
T_5 V_50 = 0 ;
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
if ( ! F_39 ( V_59 ) )
return 0 ;
F_40 ( & V_59 -> V_61 ) ;
if ( V_59 -> V_62 && V_59 -> V_62 -> V_63 ) {
V_60 = V_59 -> V_62 -> V_63 -> V_64 ;
if ( F_36 ( V_57 , V_65 ,
F_37 ( F_41 ( & V_66 , V_60 -> V_67 ) ) ) )
goto V_68;
if ( F_36 ( V_57 , V_69 ,
F_37 ( F_42 ( & V_66 , V_60 -> V_70 ) ) ) )
goto V_68;
}
F_43 ( & V_59 -> V_61 ) ;
return 0 ;
V_68:
F_43 ( & V_59 -> V_61 ) ;
return - 1 ;
}
static T_3 F_44 ( struct V_46 * V_57 , char * * V_71 )
{
T_3 V_72 = 0 ;
#if F_45 ( V_73 )
if ( ! V_57 || ! F_39 ( V_57 -> V_59 ) )
return 0 ;
F_40 ( & V_57 -> V_59 -> V_61 ) ;
if ( V_57 -> V_74 )
F_46 ( V_57 -> V_74 , V_71 , & V_72 ) ;
F_43 ( & V_57 -> V_59 -> V_61 ) ;
#endif
return V_72 ;
}
static struct V_46 *
F_47 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 ,
T_6 * * V_75 )
{
T_7 V_76 ;
T_7 V_77 = 0 , V_78 = 0 , V_79 = 0 ;
unsigned int V_80 = 0 ;
struct V_46 * V_57 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
struct V_46 * V_89 = V_37 -> V_57 ;
struct V_90 * V_91 ;
struct V_90 * V_92 ;
struct V_93 * V_94 = NULL ;
enum V_95 V_96 ( V_97 ) ;
struct V_98 * V_99 ;
bool V_49 ;
char * V_71 = NULL ;
T_3 V_72 = 0 ;
V_76 = F_48 ( sizeof( struct V_87 ) )
+ F_49 ( sizeof( struct V_83 ) )
+ F_49 ( sizeof( V_100 ) )
+ F_49 ( sizeof( V_100 ) )
#if F_45 ( V_101 )
+ F_49 ( sizeof( V_100 ) )
+ F_49 ( sizeof( V_100 ) )
#endif
+ F_49 ( sizeof( V_100 ) )
+ F_49 ( sizeof( struct V_102 ) )
+ F_49 ( sizeof( V_100 ) )
+ F_49 ( sizeof( V_100 ) ) ;
if ( V_89 -> V_103 . V_104 )
V_76 += F_49 ( sizeof( struct V_105 ) ) ;
if ( V_37 -> V_106 . V_107 <= V_108 ||
( V_37 -> V_106 . V_107 == V_109 && V_89 -> V_59 == NULL ) )
V_49 = ! F_50 ( V_89 ) ;
else
V_49 = false ;
V_92 = V_37 -> V_106 . V_110 ;
switch ( (enum V_111 ) F_51 ( V_35 -> V_25 ) ) {
case V_112 :
case V_26 :
break;
case V_113 :
if ( ! ( V_35 -> V_50 & V_114 ) &&
V_89 -> V_51 == V_52 &&
F_52 ( V_89 ) )
return NULL ;
V_77 = F_51 ( V_35 -> V_23 ) ;
if ( V_77 > V_89 -> V_115 )
V_77 = V_89 -> V_115 ;
V_80 = F_53 ( V_89 ) ;
V_80 = F_54 (unsigned int, hlen, data_len) ;
V_76 += sizeof( struct V_81 ) + V_80 ;
V_78 = V_89 -> V_115 ;
V_79 = V_77 - V_80 ;
break;
}
V_99 = F_55 ( V_98 ) ;
if ( V_35 -> V_50 & V_116 ) {
if ( V_99 != NULL ) {
V_94 = V_99 -> V_117 ( V_89 , & V_97 ) ;
if ( V_94 != NULL )
V_76 += V_99 -> V_118 ( V_94 ) ;
}
}
if ( V_35 -> V_50 & V_119 ) {
V_76 += ( F_49 ( sizeof( V_100 ) )
+ F_49 ( sizeof( V_100 ) ) ) ;
}
if ( ( V_35 -> V_50 & V_120 ) && V_89 -> V_59 ) {
V_72 = F_44 ( V_89 , & V_71 ) ;
if ( V_72 )
V_76 += F_49 ( V_72 ) ;
}
V_57 = F_56 ( V_2 -> V_121 , V_76 , V_79 , V_35 -> V_20 ,
V_18 ) ;
if ( ! V_57 ) {
F_57 ( V_89 ) ;
return NULL ;
}
V_86 = F_58 ( V_57 , 0 , 0 ,
V_122 << 8 | V_123 ,
sizeof( struct V_87 ) , 0 ) ;
if ( ! V_86 ) {
F_57 ( V_89 ) ;
F_59 ( V_57 ) ;
return NULL ;
}
V_88 = F_60 ( V_86 ) ;
V_88 -> V_124 = V_37 -> V_106 . V_125 ;
V_88 -> V_126 = V_127 ;
V_88 -> V_128 = F_61 ( V_35 -> V_4 ) ;
V_82 = F_62 ( V_57 , V_129 , sizeof( * V_84 ) ) ;
V_84 = F_63 ( V_82 ) ;
V_84 -> V_130 = V_89 -> V_131 ;
V_84 -> V_107 = V_37 -> V_106 . V_107 ;
* V_75 = & V_84 -> V_132 ;
V_91 = V_37 -> V_106 . V_133 ;
if ( V_91 ) {
#if ! F_45 ( V_101 )
if ( F_36 ( V_57 , V_134 , F_37 ( V_91 -> V_135 ) ) )
goto V_68;
#else
if ( V_37 -> V_106 . V_125 == V_136 ) {
if ( F_36 ( V_57 , V_137 ,
F_37 ( V_91 -> V_135 ) ) ||
F_36 ( V_57 , V_134 ,
F_37 ( F_64 ( V_91 ) -> V_138 -> V_139 -> V_135 ) ) )
goto V_68;
} else {
int V_140 ;
if ( F_36 ( V_57 , V_134 ,
F_37 ( V_91 -> V_135 ) ) )
goto V_68;
V_140 = F_65 ( V_89 ) ;
if ( V_140 &&
F_36 ( V_57 , V_137 ,
F_37 ( V_140 ) ) )
goto V_68;
}
#endif
}
if ( V_92 ) {
#if ! F_45 ( V_101 )
if ( F_36 ( V_57 , V_141 , F_37 ( V_92 -> V_135 ) ) )
goto V_68;
#else
if ( V_37 -> V_106 . V_125 == V_136 ) {
if ( F_36 ( V_57 , V_142 ,
F_37 ( V_92 -> V_135 ) ) ||
F_36 ( V_57 , V_141 ,
F_37 ( F_64 ( V_92 ) -> V_138 -> V_139 -> V_135 ) ) )
goto V_68;
} else {
int V_143 ;
if ( F_36 ( V_57 , V_141 ,
F_37 ( V_92 -> V_135 ) ) )
goto V_68;
V_143 = F_66 ( V_89 ) ;
if ( V_143 &&
F_36 ( V_57 , V_142 ,
F_37 ( V_143 ) ) )
goto V_68;
}
#endif
}
if ( V_89 -> V_144 &&
F_36 ( V_57 , V_145 , F_37 ( V_89 -> V_144 ) ) )
goto V_68;
if ( V_91 && V_89 -> V_139 &&
V_89 -> V_146 != V_89 -> V_147 ) {
struct V_102 V_148 ;
int V_115 ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_115 = F_67 ( V_89 , V_148 . V_149 ) ;
if ( V_115 ) {
V_148 . V_150 = F_61 ( V_115 ) ;
if ( F_68 ( V_57 , V_151 , sizeof( V_148 ) , & V_148 ) )
goto V_68;
}
}
if ( V_89 -> V_103 . V_104 ) {
struct V_105 V_152 ;
struct V_153 V_154 = F_69 ( V_57 -> V_103 ) ;
V_152 . V_155 = F_70 ( V_154 . V_156 ) ;
V_152 . V_157 = F_70 ( V_154 . V_158 / V_159 ) ;
if ( F_68 ( V_57 , V_160 , sizeof( V_152 ) , & V_152 ) )
goto V_68;
}
if ( ( V_35 -> V_50 & V_119 ) && V_89 -> V_59 &&
F_38 ( V_57 , V_89 -> V_59 ) < 0 )
goto V_68;
if ( V_72 && F_68 ( V_57 , V_161 , V_72 , V_71 ) )
goto V_68;
if ( V_94 && V_99 -> V_162 ( V_57 , V_94 , V_97 , V_163 , V_164 ) < 0 )
goto V_68;
if ( V_78 > V_77 &&
F_36 ( V_57 , V_165 , F_37 ( V_78 ) ) )
goto V_68;
if ( F_34 ( V_57 , V_89 , V_49 ) )
goto V_68;
if ( V_77 ) {
struct V_81 * V_82 ;
if ( F_71 ( V_57 ) < sizeof( * V_82 ) + V_80 )
goto V_68;
V_82 = (struct V_81 * ) F_72 ( V_57 , sizeof( * V_82 ) ) ;
V_82 -> V_166 = V_167 ;
V_82 -> V_168 = F_73 ( V_77 ) ;
if ( F_74 ( V_57 , V_89 , V_77 , V_80 ) )
goto V_68;
}
V_86 -> V_169 = V_57 -> V_115 ;
return V_57 ;
V_68:
F_57 ( V_89 ) ;
F_59 ( V_57 ) ;
F_75 ( L_1 ) ;
return NULL ;
}
static int
F_76 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 )
{
struct V_46 * V_170 ;
int V_14 = - V_171 ;
T_6 * V_75 ;
int V_172 = 0 ;
V_170 = F_47 ( V_2 , V_35 , V_37 , & V_75 ) ;
if ( V_170 == NULL ) {
V_14 = - V_19 ;
goto V_173;
}
F_29 ( & V_35 -> V_27 ) ;
if ( V_35 -> V_39 >= V_35 -> V_21 ) {
if ( V_35 -> V_50 & V_174 ) {
V_172 = 1 ;
V_14 = 0 ;
} else {
V_35 -> V_175 ++ ;
F_77 ( L_2 ,
V_35 -> V_39 ) ;
}
goto V_176;
}
V_37 -> V_40 = ++ V_35 -> V_177 ;
* V_75 = F_37 ( V_37 -> V_40 ) ;
V_14 = F_78 ( V_170 , V_2 , V_35 -> V_20 , V_178 ) ;
if ( V_14 < 0 ) {
V_35 -> V_179 ++ ;
goto V_180;
}
F_24 ( V_35 , V_37 ) ;
F_31 ( & V_35 -> V_27 ) ;
return 0 ;
V_176:
F_59 ( V_170 ) ;
V_180:
F_31 ( & V_35 -> V_27 ) ;
if ( V_172 )
F_33 ( V_37 , V_181 ) ;
V_173:
return V_14 ;
}
static struct V_36 *
F_79 ( struct V_36 * V_182 )
{
struct V_36 * V_37 = F_80 ( V_182 , V_182 -> V_76 , V_18 ) ;
if ( V_37 )
F_81 ( V_37 ) ;
return V_37 ;
}
static void F_82 ( struct V_46 * V_57 )
{
if ( V_57 -> V_183 )
F_83 ( V_57 , V_57 -> V_147 - V_57 -> V_146 ) ;
}
static void F_84 ( struct V_46 * V_57 )
{
if ( V_57 -> V_183 )
F_85 ( V_57 , V_57 -> V_147 - V_57 -> V_146 ) ;
}
static void F_86 ( struct V_36 * V_37 )
{
F_87 ( V_37 ) ;
F_14 ( V_37 ) ;
}
static int
F_88 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_46 * V_57 , struct V_36 * V_37 )
{
int V_184 = - V_19 ;
struct V_36 * V_185 ;
F_84 ( V_57 ) ;
if ( V_57 -> V_44 == NULL ) {
struct V_46 * V_186 = V_37 -> V_57 ;
V_37 -> V_57 = V_57 ;
V_184 = F_76 ( V_2 , V_35 , V_37 ) ;
if ( V_184 )
V_37 -> V_57 = V_186 ;
return V_184 ;
}
V_57 -> V_44 = NULL ;
V_185 = F_79 ( V_37 ) ;
if ( V_185 ) {
V_185 -> V_57 = V_57 ;
V_184 = F_76 ( V_2 , V_35 , V_185 ) ;
if ( V_184 )
F_86 ( V_185 ) ;
}
return V_184 ;
}
static int
F_89 ( struct V_36 * V_37 , unsigned int V_187 )
{
unsigned int V_188 ;
struct V_6 * V_35 ;
struct V_46 * V_57 , * V_189 ;
int V_14 = - V_171 ;
struct V_2 * V_2 = V_37 -> V_106 . V_2 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_187 ) ;
if ( ! V_35 )
return - V_190 ;
if ( V_35 -> V_25 == V_26 )
return - V_191 ;
V_57 = V_37 -> V_57 ;
switch ( V_37 -> V_106 . V_125 ) {
case V_192 :
V_57 -> V_131 = F_61 ( V_193 ) ;
break;
case V_194 :
V_57 -> V_131 = F_61 ( V_195 ) ;
break;
}
if ( ( V_35 -> V_50 & V_114 ) || ! F_35 ( V_57 ) )
return F_76 ( V_2 , V_35 , V_37 ) ;
F_82 ( V_57 ) ;
V_189 = F_90 ( V_57 , 0 ) ;
if ( F_91 ( V_189 ) )
goto V_196;
V_188 = 0 ;
V_14 = 0 ;
do {
struct V_46 * V_170 = V_189 -> V_44 ;
if ( V_14 == 0 )
V_14 = F_88 ( V_2 , V_35 ,
V_189 , V_37 ) ;
if ( V_14 == 0 )
V_188 ++ ;
else
F_59 ( V_189 ) ;
V_189 = V_170 ;
} while ( V_189 );
if ( V_188 ) {
if ( V_14 )
F_86 ( V_37 ) ;
F_59 ( V_57 ) ;
return 0 ;
}
V_196:
F_84 ( V_57 ) ;
return V_14 ;
}
static int
F_92 ( void * V_43 , int V_77 , struct V_36 * V_182 , int V_197 )
{
struct V_46 * V_170 ;
if ( V_197 < 0 ) {
if ( F_93 ( V_182 -> V_57 , V_77 ) )
return - V_19 ;
} else if ( V_197 > 0 ) {
if ( V_77 > 0xFFFF )
return - V_191 ;
if ( V_197 > F_71 ( V_182 -> V_57 ) ) {
V_170 = F_94 ( V_182 -> V_57 , F_95 ( V_182 -> V_57 ) ,
V_197 , V_18 ) ;
if ( ! V_170 ) {
F_96 ( V_198 L_3
L_4 ) ;
return - V_19 ;
}
F_59 ( V_182 -> V_57 ) ;
V_182 -> V_57 = V_170 ;
}
F_72 ( V_182 -> V_57 , V_197 ) ;
}
if ( ! F_97 ( V_182 -> V_57 , V_77 ) )
return - V_19 ;
F_98 ( V_182 -> V_57 , V_43 , V_77 ) ;
V_182 -> V_57 -> V_51 = V_199 ;
return 0 ;
}
static int
F_99 ( struct V_6 * V_35 ,
unsigned char V_200 , unsigned int V_201 )
{
int V_202 = 0 ;
F_29 ( & V_35 -> V_27 ) ;
switch ( V_200 ) {
case V_26 :
case V_112 :
V_35 -> V_25 = V_200 ;
V_35 -> V_23 = 0 ;
break;
case V_113 :
V_35 -> V_25 = V_200 ;
if ( V_201 == 0 || V_201 > V_24 )
V_35 -> V_23 = V_24 ;
else
V_35 -> V_23 = V_201 ;
break;
default:
V_202 = - V_191 ;
}
F_31 ( & V_35 -> V_27 ) ;
return V_202 ;
}
static int
F_100 ( struct V_36 * V_37 , unsigned long V_135 )
{
if ( V_37 -> V_106 . V_133 )
if ( V_37 -> V_106 . V_133 -> V_135 == V_135 )
return 1 ;
if ( V_37 -> V_106 . V_110 )
if ( V_37 -> V_106 . V_110 -> V_135 == V_135 )
return 1 ;
#if F_45 ( V_101 )
if ( V_37 -> V_57 -> V_183 ) {
int V_140 , V_143 ;
V_140 = F_65 ( V_37 -> V_57 ) ;
V_143 = F_66 ( V_37 -> V_57 ) ;
if ( V_140 == V_135 || V_143 == V_135 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_101 ( struct V_2 * V_2 , int V_135 )
{
int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
F_102 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_100 , V_135 ) ;
}
F_103 () ;
}
static int
F_104 ( struct V_203 * V_204 ,
unsigned long V_205 , void * V_206 )
{
struct V_90 * V_139 = F_105 ( V_206 ) ;
if ( V_205 == V_207 )
F_101 ( F_106 ( V_139 ) , V_139 -> V_135 ) ;
return V_208 ;
}
static int F_107 ( struct V_36 * V_37 , unsigned long V_209 )
{
return V_37 -> V_210 == (struct V_211 * ) V_209 ;
}
static void F_108 ( struct V_2 * V_2 , struct V_211 * V_107 )
{
struct V_1 * V_7 = F_1 ( V_2 ) ;
int V_41 ;
F_102 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_107 , ( unsigned long ) V_107 ) ;
}
F_103 () ;
}
static int
F_109 ( struct V_203 * V_204 ,
unsigned long V_205 , void * V_206 )
{
struct V_212 * V_213 = V_206 ;
struct V_1 * V_7 = F_1 ( V_213 -> V_2 ) ;
if ( V_205 == V_214 && V_213 -> V_131 == V_215 ) {
int V_41 ;
F_7 ( & V_7 -> V_15 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_216 * V_217 ;
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_110 (inst, t2, head, hlist) {
if ( V_213 -> V_12 == V_10 -> V_20 )
F_20 ( V_10 ) ;
}
}
F_13 ( & V_7 -> V_15 ) ;
}
return V_208 ;
}
static struct V_6 *
F_111 ( struct V_1 * V_7 , T_8 V_4 , T_3 V_218 )
{
struct V_6 * V_35 ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
return F_15 ( - V_219 ) ;
if ( V_35 -> V_20 != V_218 )
return F_15 ( - V_220 ) ;
return V_35 ;
}
static struct V_221 *
F_112 ( const struct V_81 * const V_222 [] )
{
struct V_221 * V_223 ;
unsigned int V_224 ;
if ( ! V_222 [ V_225 ] )
return NULL ;
V_223 = F_63 ( V_222 [ V_225 ] ) ;
V_224 = F_113 ( V_223 -> V_224 ) & V_226 ;
if ( V_224 > V_227 || V_224 == V_228 )
return NULL ;
return V_223 ;
}
static int F_114 ( unsigned int V_40 , unsigned int V_229 )
{
return ( int ) ( V_40 - V_229 ) > 0 ;
}
static int F_115 ( struct V_2 * V_2 , struct V_58 * V_230 ,
struct V_46 * V_57 ,
const struct V_85 * V_86 ,
const struct V_81 * const V_222 [] )
{
struct V_87 * V_88 = F_60 ( V_86 ) ;
struct V_36 * V_37 , * V_231 ;
unsigned int V_224 , V_232 ;
struct V_221 * V_223 ;
struct V_6 * V_35 ;
F_116 ( V_233 ) ;
T_8 V_4 = F_117 ( V_88 -> V_128 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_111 ( V_7 , V_4 ,
F_118 ( V_57 ) . V_12 ) ;
if ( F_119 ( V_35 ) )
return F_120 ( V_35 ) ;
V_223 = F_112 ( V_222 ) ;
if ( ! V_223 )
return - V_191 ;
V_224 = F_113 ( V_223 -> V_224 ) ;
V_232 = F_113 ( V_223 -> V_40 ) ;
F_29 ( & V_35 -> V_27 ) ;
F_32 (entry, tmp, &queue->queue_list, list) {
if ( F_114 ( V_37 -> V_40 , V_232 ) )
break;
F_26 ( V_35 , V_37 ) ;
F_25 ( & V_37 -> V_38 , & V_233 ) ;
}
F_31 ( & V_35 -> V_27 ) ;
if ( F_121 ( & V_233 ) )
return - V_234 ;
F_32 (entry, tmp, &batch_list, list) {
if ( V_222 [ V_145 ] )
V_37 -> V_57 -> V_144 = F_113 ( F_122 ( V_222 [ V_145 ] ) ) ;
F_33 ( V_37 , V_224 ) ;
}
return 0 ;
}
static struct V_93 * F_123 ( struct V_98 * V_99 ,
const struct V_85 * V_86 ,
const struct V_81 * const V_222 [] ,
struct V_36 * V_37 ,
enum V_95 * V_97 )
{
struct V_93 * V_94 ;
V_94 = V_99 -> V_117 ( V_37 -> V_57 , V_97 ) ;
if ( V_94 == NULL )
return NULL ;
if ( V_99 -> V_235 ( V_222 [ V_163 ] , V_94 ) < 0 )
return NULL ;
if ( V_222 [ V_236 ] )
V_99 -> V_237 ( V_222 [ V_236 ] , V_94 ,
F_118 ( V_37 -> V_57 ) . V_12 ,
F_124 ( V_86 ) ) ;
return V_94 ;
}
static int F_125 ( struct V_2 * V_2 , struct V_58 * V_230 ,
struct V_46 * V_57 ,
const struct V_85 * V_86 ,
const struct V_81 * const V_222 [] )
{
struct V_87 * V_88 = F_60 ( V_86 ) ;
T_2 V_4 = F_117 ( V_88 -> V_128 ) ;
struct V_221 * V_223 ;
struct V_6 * V_35 ;
unsigned int V_224 ;
struct V_36 * V_37 ;
enum V_95 V_96 ( V_97 ) ;
struct V_98 * V_99 ;
struct V_93 * V_94 = NULL ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
V_35 = F_111 ( V_7 , V_4 ,
F_118 ( V_57 ) . V_12 ) ;
if ( F_119 ( V_35 ) )
return F_120 ( V_35 ) ;
V_223 = F_112 ( V_222 ) ;
if ( ! V_223 )
return - V_191 ;
V_224 = F_113 ( V_223 -> V_224 ) ;
V_37 = F_28 ( V_35 , F_113 ( V_223 -> V_40 ) ) ;
if ( V_37 == NULL )
return - V_234 ;
V_99 = F_55 ( V_98 ) ;
if ( V_222 [ V_163 ] ) {
if ( V_99 != NULL )
V_94 = F_123 ( V_99 , V_86 , V_222 , V_37 , & V_97 ) ;
}
if ( V_222 [ V_167 ] ) {
T_8 V_238 = V_168 ( V_222 [ V_167 ] ) ;
int V_197 = V_238 - V_37 -> V_57 -> V_115 ;
if ( F_92 ( F_63 ( V_222 [ V_167 ] ) ,
V_238 , V_37 , V_197 ) < 0 )
V_224 = V_45 ;
if ( V_94 && V_197 )
V_99 -> V_239 ( V_37 -> V_57 , V_94 , V_97 , V_197 ) ;
}
if ( V_222 [ V_145 ] )
V_37 -> V_57 -> V_144 = F_113 ( F_122 ( V_222 [ V_145 ] ) ) ;
F_33 ( V_37 , V_224 ) ;
return 0 ;
}
static int F_126 ( struct V_2 * V_2 , struct V_58 * V_230 ,
struct V_46 * V_57 , const struct V_85 * V_86 ,
const struct V_81 * const V_222 [] )
{
return - V_240 ;
}
static int F_127 ( struct V_2 * V_2 , struct V_58 * V_230 ,
struct V_46 * V_57 , const struct V_85 * V_86 ,
const struct V_81 * const V_222 [] )
{
struct V_87 * V_88 = F_60 ( V_86 ) ;
T_2 V_4 = F_117 ( V_88 -> V_128 ) ;
struct V_6 * V_35 ;
struct V_241 * V_242 = NULL ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
T_5 V_50 = 0 , V_243 = 0 ;
int V_184 = 0 ;
if ( V_222 [ V_244 ] ) {
V_242 = F_63 ( V_222 [ V_244 ] ) ;
switch ( V_242 -> V_245 ) {
case V_246 : return 0 ;
case V_247 : return 0 ;
}
}
if ( V_222 [ V_248 ] ) {
if ( ! V_222 [ V_249 ] ) {
return - V_191 ;
}
V_50 = F_113 ( F_122 ( V_222 [ V_248 ] ) ) ;
V_243 = F_113 ( F_122 ( V_222 [ V_249 ] ) ) ;
if ( V_50 >= V_250 )
return - V_251 ;
#if ! F_45 ( V_73 )
if ( V_50 & V_243 & V_120 )
return - V_251 ;
#endif
if ( ( V_50 & V_243 & V_116 ) &&
! F_128 ( V_98 ) ) {
#ifdef F_129
F_130 ( V_122 ) ;
F_131 ( L_5 ) ;
F_132 ( V_122 ) ;
if ( F_128 ( V_98 ) )
return - V_30 ;
#endif
return - V_251 ;
}
}
F_102 () ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( V_35 && V_35 -> V_20 != F_118 ( V_57 ) . V_12 ) {
V_184 = - V_220 ;
goto V_180;
}
if ( V_242 != NULL ) {
switch ( V_242 -> V_245 ) {
case V_252 :
if ( V_35 ) {
V_184 = - V_253 ;
goto V_180;
}
V_35 = F_6 ( V_7 , V_4 ,
F_118 ( V_57 ) . V_12 ) ;
if ( F_119 ( V_35 ) ) {
V_184 = F_120 ( V_35 ) ;
goto V_180;
}
break;
case V_254 :
if ( ! V_35 ) {
V_184 = - V_219 ;
goto V_180;
}
F_23 ( V_7 , V_35 ) ;
goto V_180;
case V_246 :
case V_247 :
break;
default:
V_184 = - V_240 ;
goto V_180;
}
}
if ( ! V_35 ) {
V_184 = - V_219 ;
goto V_180;
}
if ( V_222 [ V_255 ] ) {
struct V_256 * V_257 =
F_63 ( V_222 [ V_255 ] ) ;
F_99 ( V_35 , V_257 -> V_25 ,
F_113 ( V_257 -> V_23 ) ) ;
}
if ( V_222 [ V_258 ] ) {
T_6 * V_21 = F_63 ( V_222 [ V_258 ] ) ;
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_21 = F_113 ( * V_21 ) ;
F_31 ( & V_35 -> V_27 ) ;
}
if ( V_222 [ V_248 ] ) {
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_50 &= ~ V_243 ;
V_35 -> V_50 |= V_50 & V_243 ;
F_31 ( & V_35 -> V_27 ) ;
}
V_180:
F_103 () ;
return V_184 ;
}
static struct V_216 * F_133 ( struct V_259 * V_260 )
{
struct V_261 * V_262 = V_260 -> V_263 ;
struct V_2 * V_2 ;
struct V_1 * V_7 ;
if ( ! V_262 )
return NULL ;
V_2 = F_134 ( V_260 ) ;
V_7 = F_1 ( V_2 ) ;
for ( V_262 -> V_264 = 0 ; V_262 -> V_264 < V_5 ; V_262 -> V_264 ++ ) {
if ( ! F_135 ( & V_7 -> V_11 [ V_262 -> V_264 ] ) )
return V_7 -> V_11 [ V_262 -> V_264 ] . V_265 ;
}
return NULL ;
}
static struct V_216 * F_136 ( struct V_259 * V_260 , struct V_216 * V_13 )
{
struct V_261 * V_262 = V_260 -> V_263 ;
struct V_2 * V_2 = F_134 ( V_260 ) ;
V_13 = V_13 -> V_44 ;
while ( ! V_13 ) {
struct V_1 * V_7 ;
if ( ++ V_262 -> V_264 >= V_5 )
return NULL ;
V_7 = F_1 ( V_2 ) ;
V_13 = V_7 -> V_11 [ V_262 -> V_264 ] . V_265 ;
}
return V_13 ;
}
static struct V_216 * F_137 ( struct V_259 * V_260 , T_9 V_266 )
{
struct V_216 * V_9 ;
V_9 = F_133 ( V_260 ) ;
if ( V_9 )
while ( V_266 && ( V_9 = F_136 ( V_260 , V_9 ) ) )
V_266 -- ;
return V_266 ? NULL : V_9 ;
}
static void * F_138 ( struct V_259 * V_267 , T_9 * V_266 )
__acquires( nfnl_queue_pernet( seq_file_net( V_267 )
static void * F_139 ( struct V_259 * V_267 , void * V_268 , T_9 * V_266 )
{
( * V_266 ) ++ ;
return F_136 ( V_267 , V_268 ) ;
}
static void F_140 ( struct V_259 * V_267 , void * V_268 )
__releases( nfnl_queue_pernet( seq_file_net( V_267 )
static int F_141 ( struct V_259 * V_267 , void * V_268 )
{
const struct V_6 * V_10 = V_268 ;
F_142 ( V_267 , L_6 ,
V_10 -> V_4 ,
V_10 -> V_20 , V_10 -> V_39 ,
V_10 -> V_25 , V_10 -> V_23 ,
V_10 -> V_175 , V_10 -> V_179 ,
V_10 -> V_177 , 1 ) ;
return 0 ;
}
static int F_143 ( struct V_269 * V_269 , struct V_63 * V_63 )
{
return F_144 ( V_269 , V_63 , & V_270 ,
sizeof( struct V_261 ) ) ;
}
static int T_10 F_145 ( struct V_2 * V_2 )
{
unsigned int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ )
F_146 ( & V_7 -> V_11 [ V_41 ] ) ;
F_9 ( & V_7 -> V_15 ) ;
#ifdef F_147
if ( ! F_148 ( L_7 , 0440 ,
V_2 -> V_271 . V_272 , & V_273 ) )
return - V_19 ;
#endif
return 0 ;
}
static void T_11 F_149 ( struct V_2 * V_2 )
{
#ifdef F_147
F_150 ( L_7 , V_2 -> V_271 . V_272 ) ;
#endif
}
static int T_12 F_151 ( void )
{
int V_202 ;
V_202 = F_152 ( & V_274 ) ;
if ( V_202 < 0 ) {
F_153 ( L_8 ) ;
goto V_110;
}
F_154 ( & V_275 ) ;
V_202 = F_155 ( & V_276 ) ;
if ( V_202 < 0 ) {
F_153 ( L_9 ) ;
goto V_277;
}
F_156 ( & V_278 ) ;
F_157 ( & V_279 ) ;
return V_202 ;
V_277:
F_158 ( & V_275 ) ;
F_159 ( & V_274 ) ;
V_110:
return V_202 ;
}
static void T_13 F_160 ( void )
{
F_161 () ;
F_162 ( & V_278 ) ;
F_163 ( & V_276 ) ;
F_158 ( & V_275 ) ;
F_159 ( & V_274 ) ;
F_164 () ;
}
