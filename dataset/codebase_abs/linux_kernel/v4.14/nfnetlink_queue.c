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
static T_3 F_47 ( struct V_36 * V_37 )
{
struct V_46 * V_75 = V_37 -> V_57 ;
T_3 V_76 = 0 ;
if ( V_37 -> V_77 . V_78 != V_79 || ! F_48 ( V_75 ) )
return 0 ;
if ( F_49 ( V_75 ) )
V_76 += F_50 ( F_50 ( sizeof( V_80 ) ) +
F_50 ( sizeof( V_80 ) ) ) ;
if ( V_75 -> V_81 > V_75 -> V_82 )
V_76 += F_50 ( ( V_75 -> V_81 -
V_75 -> V_82 ) ) ;
return V_76 ;
}
static int F_51 ( struct V_36 * V_37 , struct V_46 * V_57 )
{
struct V_46 * V_75 = V_37 -> V_57 ;
if ( V_37 -> V_77 . V_78 != V_79 || ! F_48 ( V_75 ) )
return 0 ;
if ( F_49 ( V_75 ) ) {
struct V_83 * V_84 ;
V_84 = F_52 ( V_57 , V_85 | V_86 ) ;
if ( ! V_84 )
goto V_68;
if ( F_53 ( V_57 , V_87 , F_54 ( V_75 -> V_88 ) ) ||
F_53 ( V_57 , V_89 , V_75 -> V_90 ) )
goto V_68;
F_55 ( V_57 , V_84 ) ;
}
if ( V_75 -> V_82 < V_75 -> V_81 ) {
int V_91 = ( int ) ( V_75 -> V_81 - V_75 -> V_82 ) ;
if ( F_56 ( V_57 , V_92 , V_91 , F_57 ( V_75 ) ) )
goto V_68;
}
return 0 ;
V_68:
return - 1 ;
}
static struct V_46 *
F_58 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 ,
T_6 * * V_93 )
{
T_7 V_94 ;
T_7 V_95 = 0 , V_96 = 0 ;
unsigned int V_97 = 0 ;
struct V_46 * V_57 ;
struct V_83 * V_98 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_46 * V_75 = V_37 -> V_57 ;
struct V_105 * V_106 ;
struct V_105 * V_107 ;
struct V_108 * V_109 = NULL ;
enum V_110 V_111 ( V_112 ) ;
struct V_113 * V_114 ;
bool V_49 ;
char * V_71 = NULL ;
T_3 V_72 = 0 ;
V_94 = F_59 ( sizeof( struct V_103 ) )
+ F_50 ( sizeof( struct V_99 ) )
+ F_50 ( sizeof( V_115 ) )
+ F_50 ( sizeof( V_115 ) )
#if F_45 ( V_116 )
+ F_50 ( sizeof( V_115 ) )
+ F_50 ( sizeof( V_115 ) )
#endif
+ F_50 ( sizeof( V_115 ) )
+ F_50 ( sizeof( struct V_117 ) )
+ F_50 ( sizeof( V_115 ) )
+ F_50 ( sizeof( V_115 ) ) ;
if ( V_75 -> V_118 )
V_94 += F_50 ( sizeof( struct V_119 ) ) ;
V_94 += F_47 ( V_37 ) ;
if ( V_37 -> V_77 . V_120 <= V_121 ||
( V_37 -> V_77 . V_120 == V_122 && V_75 -> V_59 == NULL ) )
V_49 = ! F_60 ( V_75 ) ;
else
V_49 = false ;
V_107 = V_37 -> V_77 . V_123 ;
switch ( (enum V_124 ) F_61 ( V_35 -> V_25 ) ) {
case V_125 :
case V_26 :
break;
case V_126 :
if ( ! ( V_35 -> V_50 & V_127 ) &&
V_75 -> V_51 == V_52 &&
F_62 ( V_75 ) )
return NULL ;
V_95 = F_61 ( V_35 -> V_23 ) ;
if ( V_95 > V_75 -> V_91 )
V_95 = V_75 -> V_91 ;
V_97 = F_63 ( V_75 ) ;
V_97 = F_64 (unsigned int, hlen, data_len) ;
V_94 += sizeof( struct V_83 ) + V_97 ;
V_96 = V_75 -> V_91 ;
break;
}
V_114 = F_65 ( V_113 ) ;
if ( V_35 -> V_50 & V_128 ) {
if ( V_114 != NULL ) {
V_109 = V_114 -> V_129 ( V_75 , & V_112 ) ;
if ( V_109 != NULL )
V_94 += V_114 -> V_130 ( V_109 ) ;
}
}
if ( V_35 -> V_50 & V_131 ) {
V_94 += ( F_50 ( sizeof( V_115 ) )
+ F_50 ( sizeof( V_115 ) ) ) ;
}
if ( ( V_35 -> V_50 & V_132 ) && V_75 -> V_59 ) {
V_72 = F_44 ( V_75 , & V_71 ) ;
if ( V_72 )
V_94 += F_50 ( V_72 ) ;
}
V_57 = F_66 ( V_94 , V_18 ) ;
if ( ! V_57 ) {
F_67 ( V_75 ) ;
goto V_133;
}
V_102 = F_68 ( V_57 , 0 , 0 ,
F_69 ( V_134 , V_135 ) ,
sizeof( struct V_103 ) , 0 ) ;
if ( ! V_102 ) {
F_67 ( V_75 ) ;
F_70 ( V_57 ) ;
goto V_133;
}
V_104 = F_71 ( V_102 ) ;
V_104 -> V_136 = V_37 -> V_77 . V_78 ;
V_104 -> V_137 = V_138 ;
V_104 -> V_139 = F_54 ( V_35 -> V_4 ) ;
V_98 = F_72 ( V_57 , V_140 , sizeof( * V_100 ) ) ;
V_100 = F_73 ( V_98 ) ;
V_100 -> V_141 = V_75 -> V_142 ;
V_100 -> V_120 = V_37 -> V_77 . V_120 ;
* V_93 = & V_100 -> V_143 ;
V_106 = V_37 -> V_77 . V_144 ;
if ( V_106 ) {
#if ! F_45 ( V_116 )
if ( F_36 ( V_57 , V_145 , F_37 ( V_106 -> V_146 ) ) )
goto V_68;
#else
if ( V_37 -> V_77 . V_78 == V_79 ) {
if ( F_36 ( V_57 , V_147 ,
F_37 ( V_106 -> V_146 ) ) ||
F_36 ( V_57 , V_145 ,
F_37 ( F_74 ( V_106 ) -> V_148 -> V_149 -> V_146 ) ) )
goto V_68;
} else {
int V_150 ;
if ( F_36 ( V_57 , V_145 ,
F_37 ( V_106 -> V_146 ) ) )
goto V_68;
V_150 = F_75 ( V_75 ) ;
if ( V_150 &&
F_36 ( V_57 , V_147 ,
F_37 ( V_150 ) ) )
goto V_68;
}
#endif
}
if ( V_107 ) {
#if ! F_45 ( V_116 )
if ( F_36 ( V_57 , V_151 , F_37 ( V_107 -> V_146 ) ) )
goto V_68;
#else
if ( V_37 -> V_77 . V_78 == V_79 ) {
if ( F_36 ( V_57 , V_152 ,
F_37 ( V_107 -> V_146 ) ) ||
F_36 ( V_57 , V_151 ,
F_37 ( F_74 ( V_107 ) -> V_148 -> V_149 -> V_146 ) ) )
goto V_68;
} else {
int V_153 ;
if ( F_36 ( V_57 , V_151 ,
F_37 ( V_107 -> V_146 ) ) )
goto V_68;
V_153 = F_76 ( V_75 ) ;
if ( V_153 &&
F_36 ( V_57 , V_152 ,
F_37 ( V_153 ) ) )
goto V_68;
}
#endif
}
if ( V_75 -> V_154 &&
F_36 ( V_57 , V_155 , F_37 ( V_75 -> V_154 ) ) )
goto V_68;
if ( V_106 && V_75 -> V_149 &&
V_75 -> V_82 != V_75 -> V_81 ) {
struct V_117 V_156 ;
int V_91 ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_91 = F_77 ( V_75 , V_156 . V_157 ) ;
if ( V_91 ) {
V_156 . V_158 = F_54 ( V_91 ) ;
if ( F_56 ( V_57 , V_159 , sizeof( V_156 ) , & V_156 ) )
goto V_68;
}
}
if ( F_51 ( V_37 , V_57 ) < 0 )
goto V_68;
if ( V_75 -> V_118 ) {
struct V_119 V_160 ;
struct V_161 V_162 = F_78 ( V_75 -> V_118 ) ;
V_160 . V_163 = F_79 ( V_162 . V_164 ) ;
V_160 . V_165 = F_79 ( V_162 . V_166 / V_167 ) ;
if ( F_56 ( V_57 , V_168 , sizeof( V_160 ) , & V_160 ) )
goto V_68;
}
if ( ( V_35 -> V_50 & V_131 ) && V_75 -> V_59 &&
F_38 ( V_57 , V_75 -> V_59 ) < 0 )
goto V_68;
if ( V_72 && F_56 ( V_57 , V_169 , V_72 , V_71 ) )
goto V_68;
if ( V_109 && V_114 -> V_170 ( V_57 , V_109 , V_112 , V_171 , V_172 ) < 0 )
goto V_68;
if ( V_96 > V_95 &&
F_36 ( V_57 , V_173 , F_37 ( V_96 ) ) )
goto V_68;
if ( F_34 ( V_57 , V_75 , V_49 ) )
goto V_68;
if ( V_95 ) {
struct V_83 * V_98 ;
if ( F_80 ( V_57 ) < sizeof( * V_98 ) + V_97 )
goto V_68;
V_98 = F_81 ( V_57 , sizeof( * V_98 ) ) ;
V_98 -> V_174 = V_175 ;
V_98 -> V_176 = F_82 ( V_95 ) ;
if ( F_83 ( V_57 , V_75 , V_95 , V_97 ) )
goto V_68;
}
V_102 -> V_177 = V_57 -> V_91 ;
if ( V_72 )
F_84 ( V_71 , V_72 ) ;
return V_57 ;
V_68:
F_67 ( V_75 ) ;
F_70 ( V_57 ) ;
F_85 ( L_1 ) ;
V_133:
if ( V_72 )
F_84 ( V_71 , V_72 ) ;
return NULL ;
}
static bool F_86 ( const struct V_36 * V_37 )
{
#if F_45 ( V_178 )
static const unsigned long V_50 = V_179 | V_180 ;
const struct V_108 * V_109 = ( void * ) F_87 ( V_37 -> V_57 ) ;
if ( V_109 && ( ( V_109 -> V_181 & V_50 ) == V_180 ) )
return true ;
#endif
return false ;
}
static int
F_88 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 )
{
struct V_46 * V_182 ;
int V_14 = - V_183 ;
T_6 * V_93 ;
int V_184 = 0 ;
V_182 = F_58 ( V_2 , V_35 , V_37 , & V_93 ) ;
if ( V_182 == NULL ) {
V_14 = - V_19 ;
goto V_185;
}
F_29 ( & V_35 -> V_27 ) ;
if ( F_86 ( V_37 ) )
goto V_186;
if ( V_35 -> V_39 >= V_35 -> V_21 ) {
if ( V_35 -> V_50 & V_187 ) {
V_184 = 1 ;
V_14 = 0 ;
} else {
V_35 -> V_188 ++ ;
F_89 ( L_2 ,
V_35 -> V_39 ) ;
}
goto V_186;
}
V_37 -> V_40 = ++ V_35 -> V_189 ;
* V_93 = F_37 ( V_37 -> V_40 ) ;
V_14 = F_90 ( V_182 , V_2 , V_35 -> V_20 , V_190 ) ;
if ( V_14 < 0 ) {
if ( V_35 -> V_50 & V_187 ) {
V_184 = 1 ;
V_14 = 0 ;
} else {
V_35 -> V_191 ++ ;
}
goto V_192;
}
F_24 ( V_35 , V_37 ) ;
F_31 ( & V_35 -> V_27 ) ;
return 0 ;
V_186:
F_70 ( V_182 ) ;
V_192:
F_31 ( & V_35 -> V_27 ) ;
if ( V_184 )
F_33 ( V_37 , V_193 ) ;
V_185:
return V_14 ;
}
static struct V_36 *
F_91 ( struct V_36 * V_194 )
{
struct V_36 * V_37 = F_92 ( V_194 , V_194 -> V_94 , V_18 ) ;
if ( V_37 )
F_93 ( V_37 ) ;
return V_37 ;
}
static void F_94 ( struct V_46 * V_57 )
{
if ( V_57 -> V_195 )
F_95 ( V_57 , V_57 -> V_81 - V_57 -> V_82 ) ;
}
static void F_96 ( struct V_46 * V_57 )
{
if ( V_57 -> V_195 )
F_97 ( V_57 , V_57 -> V_81 - V_57 -> V_82 ) ;
}
static void F_98 ( struct V_36 * V_37 )
{
F_99 ( V_37 ) ;
F_14 ( V_37 ) ;
}
static int
F_100 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_46 * V_57 , struct V_36 * V_37 )
{
int V_196 = - V_19 ;
struct V_36 * V_197 ;
F_96 ( V_57 ) ;
if ( V_57 -> V_44 == NULL ) {
struct V_46 * V_198 = V_37 -> V_57 ;
V_37 -> V_57 = V_57 ;
V_196 = F_88 ( V_2 , V_35 , V_37 ) ;
if ( V_196 )
V_37 -> V_57 = V_198 ;
return V_196 ;
}
V_57 -> V_44 = NULL ;
V_197 = F_91 ( V_37 ) ;
if ( V_197 ) {
V_197 -> V_57 = V_57 ;
V_196 = F_88 ( V_2 , V_35 , V_197 ) ;
if ( V_196 )
F_98 ( V_197 ) ;
}
return V_196 ;
}
static int
F_101 ( struct V_36 * V_37 , unsigned int V_199 )
{
unsigned int V_200 ;
struct V_6 * V_35 ;
struct V_46 * V_57 , * V_201 ;
int V_14 = - V_183 ;
struct V_2 * V_2 = V_37 -> V_77 . V_2 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_199 ) ;
if ( ! V_35 )
return - V_202 ;
if ( V_35 -> V_25 == V_26 )
return - V_203 ;
V_57 = V_37 -> V_57 ;
switch ( V_37 -> V_77 . V_78 ) {
case V_204 :
V_57 -> V_142 = F_54 ( V_205 ) ;
break;
case V_206 :
V_57 -> V_142 = F_54 ( V_207 ) ;
break;
}
if ( ( V_35 -> V_50 & V_127 ) || ! F_35 ( V_57 ) )
return F_88 ( V_2 , V_35 , V_37 ) ;
F_94 ( V_57 ) ;
V_201 = F_102 ( V_57 , 0 ) ;
if ( F_103 ( V_201 ) )
goto V_208;
V_200 = 0 ;
V_14 = 0 ;
do {
struct V_46 * V_182 = V_201 -> V_44 ;
if ( V_14 == 0 )
V_14 = F_100 ( V_2 , V_35 ,
V_201 , V_37 ) ;
if ( V_14 == 0 )
V_200 ++ ;
else
F_70 ( V_201 ) ;
V_201 = V_182 ;
} while ( V_201 );
if ( V_200 ) {
if ( V_14 )
F_98 ( V_37 ) ;
F_70 ( V_57 ) ;
return 0 ;
}
V_208:
F_96 ( V_57 ) ;
return V_14 ;
}
static int
F_104 ( void * V_43 , int V_95 , struct V_36 * V_194 , int V_209 )
{
struct V_46 * V_182 ;
if ( V_209 < 0 ) {
if ( F_105 ( V_194 -> V_57 , V_95 ) )
return - V_19 ;
} else if ( V_209 > 0 ) {
if ( V_95 > 0xFFFF )
return - V_203 ;
if ( V_209 > F_80 ( V_194 -> V_57 ) ) {
V_182 = F_106 ( V_194 -> V_57 , F_107 ( V_194 -> V_57 ) ,
V_209 , V_18 ) ;
if ( ! V_182 ) {
F_108 ( V_210 L_3
L_4 ) ;
return - V_19 ;
}
F_70 ( V_194 -> V_57 ) ;
V_194 -> V_57 = V_182 ;
}
F_81 ( V_194 -> V_57 , V_209 ) ;
}
if ( ! F_109 ( V_194 -> V_57 , V_95 ) )
return - V_19 ;
F_110 ( V_194 -> V_57 , V_43 , V_95 ) ;
V_194 -> V_57 -> V_51 = V_211 ;
return 0 ;
}
static int
F_111 ( struct V_6 * V_35 ,
unsigned char V_212 , unsigned int V_213 )
{
int V_181 = 0 ;
F_29 ( & V_35 -> V_27 ) ;
switch ( V_212 ) {
case V_26 :
case V_125 :
V_35 -> V_25 = V_212 ;
V_35 -> V_23 = 0 ;
break;
case V_126 :
V_35 -> V_25 = V_212 ;
if ( V_213 == 0 || V_213 > V_24 )
V_35 -> V_23 = V_24 ;
else
V_35 -> V_23 = V_213 ;
break;
default:
V_181 = - V_203 ;
}
F_31 ( & V_35 -> V_27 ) ;
return V_181 ;
}
static int
F_112 ( struct V_36 * V_37 , unsigned long V_146 )
{
if ( V_37 -> V_77 . V_144 )
if ( V_37 -> V_77 . V_144 -> V_146 == V_146 )
return 1 ;
if ( V_37 -> V_77 . V_123 )
if ( V_37 -> V_77 . V_123 -> V_146 == V_146 )
return 1 ;
#if F_45 ( V_116 )
if ( V_37 -> V_57 -> V_195 ) {
int V_150 , V_153 ;
V_150 = F_75 ( V_37 -> V_57 ) ;
V_153 = F_76 ( V_37 -> V_57 ) ;
if ( V_150 == V_146 || V_153 == V_146 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_113 ( struct V_2 * V_2 , int V_146 )
{
int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
F_114 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_112 , V_146 ) ;
}
F_115 () ;
}
static int
F_116 ( struct V_214 * V_215 ,
unsigned long V_216 , void * V_217 )
{
struct V_105 * V_149 = F_117 ( V_217 ) ;
if ( V_216 == V_218 )
F_113 ( F_118 ( V_149 ) , V_149 -> V_146 ) ;
return V_219 ;
}
static unsigned int F_119 ( struct V_2 * V_2 )
{
struct V_1 * V_7 = F_1 ( V_2 ) ;
unsigned int V_220 = 0 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist) {
F_18 ( V_10 , NULL , 0 ) ;
V_220 ++ ;
}
}
return V_220 ;
}
static int
F_120 ( struct V_214 * V_215 ,
unsigned long V_216 , void * V_217 )
{
struct V_221 * V_222 = V_217 ;
struct V_1 * V_7 = F_1 ( V_222 -> V_2 ) ;
if ( V_216 == V_223 && V_222 -> V_142 == V_224 ) {
int V_41 ;
F_7 ( & V_7 -> V_15 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_225 * V_226 ;
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_121 (inst, t2, head, hlist) {
if ( V_222 -> V_12 == V_10 -> V_20 )
F_20 ( V_10 ) ;
}
}
F_13 ( & V_7 -> V_15 ) ;
}
return V_219 ;
}
static struct V_6 *
F_122 ( struct V_1 * V_7 , T_8 V_4 , T_3 V_227 )
{
struct V_6 * V_35 ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
return F_15 ( - V_228 ) ;
if ( V_35 -> V_20 != V_227 )
return F_15 ( - V_229 ) ;
return V_35 ;
}
static struct V_230 *
F_123 ( const struct V_83 * const V_231 [] )
{
struct V_230 * V_232 ;
unsigned int V_233 ;
if ( ! V_231 [ V_234 ] )
return NULL ;
V_232 = F_73 ( V_231 [ V_234 ] ) ;
V_233 = F_124 ( V_232 -> V_233 ) & V_235 ;
if ( V_233 > V_236 || V_233 == V_237 )
return NULL ;
return V_232 ;
}
static int F_125 ( unsigned int V_40 , unsigned int V_238 )
{
return ( int ) ( V_40 - V_238 ) > 0 ;
}
static int F_126 ( struct V_2 * V_2 , struct V_58 * V_239 ,
struct V_46 * V_57 ,
const struct V_101 * V_102 ,
const struct V_83 * const V_231 [] ,
struct V_240 * V_241 )
{
struct V_103 * V_104 = F_71 ( V_102 ) ;
struct V_36 * V_37 , * V_242 ;
unsigned int V_233 , V_243 ;
struct V_230 * V_232 ;
struct V_6 * V_35 ;
F_127 ( V_244 ) ;
T_8 V_4 = F_128 ( V_104 -> V_139 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_122 ( V_7 , V_4 ,
F_129 ( V_57 ) . V_12 ) ;
if ( F_130 ( V_35 ) )
return F_131 ( V_35 ) ;
V_232 = F_123 ( V_231 ) ;
if ( ! V_232 )
return - V_203 ;
V_233 = F_124 ( V_232 -> V_233 ) ;
V_243 = F_124 ( V_232 -> V_40 ) ;
F_29 ( & V_35 -> V_27 ) ;
F_32 (entry, tmp, &queue->queue_list, list) {
if ( F_125 ( V_37 -> V_40 , V_243 ) )
break;
F_26 ( V_35 , V_37 ) ;
F_25 ( & V_37 -> V_38 , & V_244 ) ;
}
F_31 ( & V_35 -> V_27 ) ;
if ( F_132 ( & V_244 ) )
return - V_245 ;
F_32 (entry, tmp, &batch_list, list) {
if ( V_231 [ V_155 ] )
V_37 -> V_57 -> V_154 = F_124 ( F_133 ( V_231 [ V_155 ] ) ) ;
F_33 ( V_37 , V_233 ) ;
}
return 0 ;
}
static struct V_108 * F_134 ( struct V_113 * V_114 ,
const struct V_101 * V_102 ,
const struct V_83 * const V_231 [] ,
struct V_36 * V_37 ,
enum V_110 * V_112 )
{
struct V_108 * V_109 ;
V_109 = V_114 -> V_129 ( V_37 -> V_57 , V_112 ) ;
if ( V_109 == NULL )
return NULL ;
if ( V_114 -> V_246 ( V_231 [ V_171 ] , V_109 ) < 0 )
return NULL ;
if ( V_231 [ V_247 ] )
V_114 -> V_248 ( V_231 [ V_247 ] , V_109 ,
F_129 ( V_37 -> V_57 ) . V_12 ,
F_135 ( V_102 ) ) ;
return V_109 ;
}
static int F_136 ( struct V_36 * V_37 ,
const struct V_83 * const V_231 [] )
{
if ( V_231 [ V_85 ] ) {
struct V_83 * V_249 [ V_250 + 1 ] ;
int V_14 ;
V_14 = F_137 ( V_249 , V_250 , V_231 [ V_85 ] ,
V_251 , NULL ) ;
if ( V_14 < 0 )
return V_14 ;
if ( ! V_249 [ V_87 ] || ! V_249 [ V_89 ] )
return - V_203 ;
V_37 -> V_57 -> V_88 = F_128 ( F_138 ( V_249 [ V_87 ] ) ) ;
V_37 -> V_57 -> V_90 = F_138 ( V_249 [ V_89 ] ) ;
}
if ( V_231 [ V_92 ] ) {
int V_252 = V_37 -> V_57 -> V_81 -
V_37 -> V_57 -> V_82 ;
if ( V_252 != V_176 ( V_231 [ V_92 ] ) )
return - V_203 ;
else if ( V_252 > 0 )
memcpy ( F_57 ( V_37 -> V_57 ) ,
F_73 ( V_231 [ V_92 ] ) ,
V_252 ) ;
}
return 0 ;
}
static int F_139 ( struct V_2 * V_2 , struct V_58 * V_239 ,
struct V_46 * V_57 ,
const struct V_101 * V_102 ,
const struct V_83 * const V_231 [] ,
struct V_240 * V_241 )
{
struct V_103 * V_104 = F_71 ( V_102 ) ;
T_2 V_4 = F_128 ( V_104 -> V_139 ) ;
struct V_230 * V_232 ;
struct V_6 * V_35 ;
unsigned int V_233 ;
struct V_36 * V_37 ;
enum V_110 V_111 ( V_112 ) ;
struct V_113 * V_114 ;
struct V_108 * V_109 = NULL ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
int V_14 ;
V_35 = F_122 ( V_7 , V_4 ,
F_129 ( V_57 ) . V_12 ) ;
if ( F_130 ( V_35 ) )
return F_131 ( V_35 ) ;
V_232 = F_123 ( V_231 ) ;
if ( ! V_232 )
return - V_203 ;
V_233 = F_124 ( V_232 -> V_233 ) ;
V_37 = F_28 ( V_35 , F_124 ( V_232 -> V_40 ) ) ;
if ( V_37 == NULL )
return - V_245 ;
V_114 = F_65 ( V_113 ) ;
if ( V_231 [ V_171 ] ) {
if ( V_114 != NULL )
V_109 = F_134 ( V_114 , V_102 , V_231 , V_37 , & V_112 ) ;
}
if ( V_37 -> V_77 . V_78 == V_79 ) {
V_14 = F_136 ( V_37 , V_231 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_231 [ V_175 ] ) {
T_8 V_253 = V_176 ( V_231 [ V_175 ] ) ;
int V_209 = V_253 - V_37 -> V_57 -> V_91 ;
if ( F_104 ( F_73 ( V_231 [ V_175 ] ) ,
V_253 , V_37 , V_209 ) < 0 )
V_233 = V_45 ;
if ( V_109 && V_209 )
V_114 -> V_254 ( V_37 -> V_57 , V_109 , V_112 , V_209 ) ;
}
if ( V_231 [ V_155 ] )
V_37 -> V_57 -> V_154 = F_124 ( F_133 ( V_231 [ V_155 ] ) ) ;
F_33 ( V_37 , V_233 ) ;
return 0 ;
}
static int F_140 ( struct V_2 * V_2 , struct V_58 * V_239 ,
struct V_46 * V_57 , const struct V_101 * V_102 ,
const struct V_83 * const V_231 [] ,
struct V_240 * V_241 )
{
return - V_255 ;
}
static int F_141 ( struct V_2 * V_2 , struct V_58 * V_239 ,
struct V_46 * V_57 , const struct V_101 * V_102 ,
const struct V_83 * const V_231 [] ,
struct V_240 * V_241 )
{
struct V_103 * V_104 = F_71 ( V_102 ) ;
T_2 V_4 = F_128 ( V_104 -> V_139 ) ;
struct V_6 * V_35 ;
struct V_256 * V_257 = NULL ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
T_5 V_50 = 0 , V_258 = 0 ;
int V_196 = 0 ;
if ( V_231 [ V_259 ] ) {
V_257 = F_73 ( V_231 [ V_259 ] ) ;
switch ( V_257 -> V_260 ) {
case V_261 : return 0 ;
case V_262 : return 0 ;
}
}
if ( V_231 [ V_263 ] ) {
if ( ! V_231 [ V_264 ] ) {
return - V_203 ;
}
V_50 = F_124 ( F_133 ( V_231 [ V_263 ] ) ) ;
V_258 = F_124 ( F_133 ( V_231 [ V_264 ] ) ) ;
if ( V_50 >= V_265 )
return - V_266 ;
#if ! F_45 ( V_73 )
if ( V_50 & V_258 & V_132 )
return - V_266 ;
#endif
if ( ( V_50 & V_258 & V_128 ) &&
! F_142 ( V_113 ) ) {
#ifdef F_143
F_144 ( V_134 ) ;
F_145 ( L_5 ) ;
F_146 ( V_134 ) ;
if ( F_142 ( V_113 ) )
return - V_30 ;
#endif
return - V_266 ;
}
}
F_114 () ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( V_35 && V_35 -> V_20 != F_129 ( V_57 ) . V_12 ) {
V_196 = - V_229 ;
goto V_192;
}
if ( V_257 != NULL ) {
switch ( V_257 -> V_260 ) {
case V_267 :
if ( V_35 ) {
V_196 = - V_268 ;
goto V_192;
}
V_35 = F_6 ( V_7 , V_4 ,
F_129 ( V_57 ) . V_12 ) ;
if ( F_130 ( V_35 ) ) {
V_196 = F_131 ( V_35 ) ;
goto V_192;
}
break;
case V_269 :
if ( ! V_35 ) {
V_196 = - V_228 ;
goto V_192;
}
F_23 ( V_7 , V_35 ) ;
goto V_192;
case V_261 :
case V_262 :
break;
default:
V_196 = - V_255 ;
goto V_192;
}
}
if ( ! V_35 ) {
V_196 = - V_228 ;
goto V_192;
}
if ( V_231 [ V_270 ] ) {
struct V_271 * V_272 =
F_73 ( V_231 [ V_270 ] ) ;
F_111 ( V_35 , V_272 -> V_25 ,
F_124 ( V_272 -> V_23 ) ) ;
}
if ( V_231 [ V_273 ] ) {
T_6 * V_21 = F_73 ( V_231 [ V_273 ] ) ;
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_21 = F_124 ( * V_21 ) ;
F_31 ( & V_35 -> V_27 ) ;
}
if ( V_231 [ V_263 ] ) {
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_50 &= ~ V_258 ;
V_35 -> V_50 |= V_50 & V_258 ;
F_31 ( & V_35 -> V_27 ) ;
}
V_192:
F_115 () ;
return V_196 ;
}
static struct V_225 * F_147 ( struct V_274 * V_275 )
{
struct V_276 * V_277 = V_275 -> V_278 ;
struct V_2 * V_2 ;
struct V_1 * V_7 ;
if ( ! V_277 )
return NULL ;
V_2 = F_148 ( V_275 ) ;
V_7 = F_1 ( V_2 ) ;
for ( V_277 -> V_279 = 0 ; V_277 -> V_279 < V_5 ; V_277 -> V_279 ++ ) {
if ( ! F_149 ( & V_7 -> V_11 [ V_277 -> V_279 ] ) )
return V_7 -> V_11 [ V_277 -> V_279 ] . V_280 ;
}
return NULL ;
}
static struct V_225 * F_150 ( struct V_274 * V_275 , struct V_225 * V_13 )
{
struct V_276 * V_277 = V_275 -> V_278 ;
struct V_2 * V_2 = F_148 ( V_275 ) ;
V_13 = V_13 -> V_44 ;
while ( ! V_13 ) {
struct V_1 * V_7 ;
if ( ++ V_277 -> V_279 >= V_5 )
return NULL ;
V_7 = F_1 ( V_2 ) ;
V_13 = V_7 -> V_11 [ V_277 -> V_279 ] . V_280 ;
}
return V_13 ;
}
static struct V_225 * F_151 ( struct V_274 * V_275 , T_9 V_281 )
{
struct V_225 * V_9 ;
V_9 = F_147 ( V_275 ) ;
if ( V_9 )
while ( V_281 && ( V_9 = F_150 ( V_275 , V_9 ) ) )
V_281 -- ;
return V_281 ? NULL : V_9 ;
}
static void * F_152 ( struct V_274 * V_282 , T_9 * V_281 )
__acquires( nfnl_queue_pernet( seq_file_net( V_282 )
static void * F_153 ( struct V_274 * V_282 , void * V_283 , T_9 * V_281 )
{
( * V_281 ) ++ ;
return F_150 ( V_282 , V_283 ) ;
}
static void F_154 ( struct V_274 * V_282 , void * V_283 )
__releases( nfnl_queue_pernet( seq_file_net( V_282 )
static int F_155 ( struct V_274 * V_282 , void * V_283 )
{
const struct V_6 * V_10 = V_283 ;
F_156 ( V_282 , L_6 ,
V_10 -> V_4 ,
V_10 -> V_20 , V_10 -> V_39 ,
V_10 -> V_25 , V_10 -> V_23 ,
V_10 -> V_188 , V_10 -> V_191 ,
V_10 -> V_189 , 1 ) ;
return 0 ;
}
static int F_157 ( struct V_284 * V_284 , struct V_63 * V_63 )
{
return F_158 ( V_284 , V_63 , & V_285 ,
sizeof( struct V_276 ) ) ;
}
static int T_10 F_159 ( struct V_2 * V_2 )
{
unsigned int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ )
F_160 ( & V_7 -> V_11 [ V_41 ] ) ;
F_9 ( & V_7 -> V_15 ) ;
#ifdef F_161
if ( ! F_162 ( L_7 , 0440 ,
V_2 -> V_286 . V_287 , & V_288 ) )
return - V_19 ;
#endif
F_163 ( V_2 , & V_289 ) ;
return 0 ;
}
static void T_11 F_164 ( struct V_2 * V_2 )
{
F_165 ( V_2 ) ;
#ifdef F_161
F_166 ( L_7 , V_2 -> V_286 . V_287 ) ;
#endif
}
static void F_167 ( struct V_290 * V_291 )
{
F_168 () ;
}
static int T_12 F_169 ( void )
{
int V_181 ;
V_181 = F_170 ( & V_292 ) ;
if ( V_181 < 0 ) {
F_171 ( L_8 ) ;
goto V_123;
}
F_172 ( & V_293 ) ;
V_181 = F_173 ( & V_294 ) ;
if ( V_181 < 0 ) {
F_171 ( L_9 ) ;
goto V_295;
}
V_181 = F_174 ( & V_296 ) ;
if ( V_181 < 0 ) {
F_171 ( L_10 ) ;
goto V_297;
}
return V_181 ;
V_297:
F_175 ( & V_294 ) ;
V_295:
F_176 ( & V_293 ) ;
F_177 ( & V_292 ) ;
V_123:
return V_181 ;
}
static void T_13 F_178 ( void )
{
F_179 ( & V_296 ) ;
F_175 ( & V_294 ) ;
F_176 ( & V_293 ) ;
F_177 ( & V_292 ) ;
F_180 () ;
}
