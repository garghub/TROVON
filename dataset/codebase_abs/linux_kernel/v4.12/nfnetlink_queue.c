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
V_98 = (struct V_83 * ) F_81 ( V_57 , sizeof( * V_98 ) ) ;
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
static int
F_86 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 )
{
struct V_46 * V_178 ;
int V_14 = - V_179 ;
T_6 * V_93 ;
int V_180 = 0 ;
V_178 = F_58 ( V_2 , V_35 , V_37 , & V_93 ) ;
if ( V_178 == NULL ) {
V_14 = - V_19 ;
goto V_181;
}
F_29 ( & V_35 -> V_27 ) ;
if ( V_35 -> V_39 >= V_35 -> V_21 ) {
if ( V_35 -> V_50 & V_182 ) {
V_180 = 1 ;
V_14 = 0 ;
} else {
V_35 -> V_183 ++ ;
F_87 ( L_2 ,
V_35 -> V_39 ) ;
}
goto V_184;
}
V_37 -> V_40 = ++ V_35 -> V_185 ;
* V_93 = F_37 ( V_37 -> V_40 ) ;
V_14 = F_88 ( V_178 , V_2 , V_35 -> V_20 , V_186 ) ;
if ( V_14 < 0 ) {
if ( V_35 -> V_50 & V_182 ) {
V_180 = 1 ;
V_14 = 0 ;
} else {
V_35 -> V_187 ++ ;
}
goto V_188;
}
F_24 ( V_35 , V_37 ) ;
F_31 ( & V_35 -> V_27 ) ;
return 0 ;
V_184:
F_70 ( V_178 ) ;
V_188:
F_31 ( & V_35 -> V_27 ) ;
if ( V_180 )
F_33 ( V_37 , V_189 ) ;
V_181:
return V_14 ;
}
static struct V_36 *
F_89 ( struct V_36 * V_190 )
{
struct V_36 * V_37 = F_90 ( V_190 , V_190 -> V_94 , V_18 ) ;
if ( V_37 )
F_91 ( V_37 ) ;
return V_37 ;
}
static void F_92 ( struct V_46 * V_57 )
{
if ( V_57 -> V_191 )
F_93 ( V_57 , V_57 -> V_81 - V_57 -> V_82 ) ;
}
static void F_94 ( struct V_46 * V_57 )
{
if ( V_57 -> V_191 )
F_95 ( V_57 , V_57 -> V_81 - V_57 -> V_82 ) ;
}
static void F_96 ( struct V_36 * V_37 )
{
F_97 ( V_37 ) ;
F_14 ( V_37 ) ;
}
static int
F_98 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_46 * V_57 , struct V_36 * V_37 )
{
int V_192 = - V_19 ;
struct V_36 * V_193 ;
F_94 ( V_57 ) ;
if ( V_57 -> V_44 == NULL ) {
struct V_46 * V_194 = V_37 -> V_57 ;
V_37 -> V_57 = V_57 ;
V_192 = F_86 ( V_2 , V_35 , V_37 ) ;
if ( V_192 )
V_37 -> V_57 = V_194 ;
return V_192 ;
}
V_57 -> V_44 = NULL ;
V_193 = F_89 ( V_37 ) ;
if ( V_193 ) {
V_193 -> V_57 = V_57 ;
V_192 = F_86 ( V_2 , V_35 , V_193 ) ;
if ( V_192 )
F_96 ( V_193 ) ;
}
return V_192 ;
}
static int
F_99 ( struct V_36 * V_37 , unsigned int V_195 )
{
unsigned int V_196 ;
struct V_6 * V_35 ;
struct V_46 * V_57 , * V_197 ;
int V_14 = - V_179 ;
struct V_2 * V_2 = V_37 -> V_77 . V_2 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_195 ) ;
if ( ! V_35 )
return - V_198 ;
if ( V_35 -> V_25 == V_26 )
return - V_199 ;
V_57 = V_37 -> V_57 ;
switch ( V_37 -> V_77 . V_78 ) {
case V_200 :
V_57 -> V_142 = F_54 ( V_201 ) ;
break;
case V_202 :
V_57 -> V_142 = F_54 ( V_203 ) ;
break;
}
if ( ( V_35 -> V_50 & V_127 ) || ! F_35 ( V_57 ) )
return F_86 ( V_2 , V_35 , V_37 ) ;
F_92 ( V_57 ) ;
V_197 = F_100 ( V_57 , 0 ) ;
if ( F_101 ( V_197 ) )
goto V_204;
V_196 = 0 ;
V_14 = 0 ;
do {
struct V_46 * V_178 = V_197 -> V_44 ;
if ( V_14 == 0 )
V_14 = F_98 ( V_2 , V_35 ,
V_197 , V_37 ) ;
if ( V_14 == 0 )
V_196 ++ ;
else
F_70 ( V_197 ) ;
V_197 = V_178 ;
} while ( V_197 );
if ( V_196 ) {
if ( V_14 )
F_96 ( V_37 ) ;
F_70 ( V_57 ) ;
return 0 ;
}
V_204:
F_94 ( V_57 ) ;
return V_14 ;
}
static int
F_102 ( void * V_43 , int V_95 , struct V_36 * V_190 , int V_205 )
{
struct V_46 * V_178 ;
if ( V_205 < 0 ) {
if ( F_103 ( V_190 -> V_57 , V_95 ) )
return - V_19 ;
} else if ( V_205 > 0 ) {
if ( V_95 > 0xFFFF )
return - V_199 ;
if ( V_205 > F_80 ( V_190 -> V_57 ) ) {
V_178 = F_104 ( V_190 -> V_57 , F_105 ( V_190 -> V_57 ) ,
V_205 , V_18 ) ;
if ( ! V_178 ) {
F_106 ( V_206 L_3
L_4 ) ;
return - V_19 ;
}
F_70 ( V_190 -> V_57 ) ;
V_190 -> V_57 = V_178 ;
}
F_81 ( V_190 -> V_57 , V_205 ) ;
}
if ( ! F_107 ( V_190 -> V_57 , V_95 ) )
return - V_19 ;
F_108 ( V_190 -> V_57 , V_43 , V_95 ) ;
V_190 -> V_57 -> V_51 = V_207 ;
return 0 ;
}
static int
F_109 ( struct V_6 * V_35 ,
unsigned char V_208 , unsigned int V_209 )
{
int V_210 = 0 ;
F_29 ( & V_35 -> V_27 ) ;
switch ( V_208 ) {
case V_26 :
case V_125 :
V_35 -> V_25 = V_208 ;
V_35 -> V_23 = 0 ;
break;
case V_126 :
V_35 -> V_25 = V_208 ;
if ( V_209 == 0 || V_209 > V_24 )
V_35 -> V_23 = V_24 ;
else
V_35 -> V_23 = V_209 ;
break;
default:
V_210 = - V_199 ;
}
F_31 ( & V_35 -> V_27 ) ;
return V_210 ;
}
static int
F_110 ( struct V_36 * V_37 , unsigned long V_146 )
{
if ( V_37 -> V_77 . V_144 )
if ( V_37 -> V_77 . V_144 -> V_146 == V_146 )
return 1 ;
if ( V_37 -> V_77 . V_123 )
if ( V_37 -> V_77 . V_123 -> V_146 == V_146 )
return 1 ;
#if F_45 ( V_116 )
if ( V_37 -> V_57 -> V_191 ) {
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
F_111 ( struct V_2 * V_2 , int V_146 )
{
int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
F_112 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_110 , V_146 ) ;
}
F_113 () ;
}
static int
F_114 ( struct V_211 * V_212 ,
unsigned long V_213 , void * V_214 )
{
struct V_105 * V_149 = F_115 ( V_214 ) ;
if ( V_213 == V_215 )
F_111 ( F_116 ( V_149 ) , V_149 -> V_146 ) ;
return V_216 ;
}
static unsigned int F_117 ( struct V_2 * V_2 )
{
struct V_1 * V_7 = F_1 ( V_2 ) ;
unsigned int V_217 = 0 ;
int V_41 ;
F_112 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist) {
F_18 ( V_10 , NULL , 0 ) ;
V_217 ++ ;
}
}
F_113 () ;
return V_217 ;
}
static int
F_118 ( struct V_211 * V_212 ,
unsigned long V_213 , void * V_214 )
{
struct V_218 * V_219 = V_214 ;
struct V_1 * V_7 = F_1 ( V_219 -> V_2 ) ;
if ( V_213 == V_220 && V_219 -> V_142 == V_221 ) {
int V_41 ;
F_7 ( & V_7 -> V_15 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_222 * V_223 ;
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_119 (inst, t2, head, hlist) {
if ( V_219 -> V_12 == V_10 -> V_20 )
F_20 ( V_10 ) ;
}
}
F_13 ( & V_7 -> V_15 ) ;
}
return V_216 ;
}
static struct V_6 *
F_120 ( struct V_1 * V_7 , T_8 V_4 , T_3 V_224 )
{
struct V_6 * V_35 ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
return F_15 ( - V_225 ) ;
if ( V_35 -> V_20 != V_224 )
return F_15 ( - V_226 ) ;
return V_35 ;
}
static struct V_227 *
F_121 ( const struct V_83 * const V_228 [] )
{
struct V_227 * V_229 ;
unsigned int V_230 ;
if ( ! V_228 [ V_231 ] )
return NULL ;
V_229 = F_73 ( V_228 [ V_231 ] ) ;
V_230 = F_122 ( V_229 -> V_230 ) & V_232 ;
if ( V_230 > V_233 || V_230 == V_234 )
return NULL ;
return V_229 ;
}
static int F_123 ( unsigned int V_40 , unsigned int V_235 )
{
return ( int ) ( V_40 - V_235 ) > 0 ;
}
static int F_124 ( struct V_2 * V_2 , struct V_58 * V_236 ,
struct V_46 * V_57 ,
const struct V_101 * V_102 ,
const struct V_83 * const V_228 [] )
{
struct V_103 * V_104 = F_71 ( V_102 ) ;
struct V_36 * V_37 , * V_237 ;
unsigned int V_230 , V_238 ;
struct V_227 * V_229 ;
struct V_6 * V_35 ;
F_125 ( V_239 ) ;
T_8 V_4 = F_126 ( V_104 -> V_139 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_120 ( V_7 , V_4 ,
F_127 ( V_57 ) . V_12 ) ;
if ( F_128 ( V_35 ) )
return F_129 ( V_35 ) ;
V_229 = F_121 ( V_228 ) ;
if ( ! V_229 )
return - V_199 ;
V_230 = F_122 ( V_229 -> V_230 ) ;
V_238 = F_122 ( V_229 -> V_40 ) ;
F_29 ( & V_35 -> V_27 ) ;
F_32 (entry, tmp, &queue->queue_list, list) {
if ( F_123 ( V_37 -> V_40 , V_238 ) )
break;
F_26 ( V_35 , V_37 ) ;
F_25 ( & V_37 -> V_38 , & V_239 ) ;
}
F_31 ( & V_35 -> V_27 ) ;
if ( F_130 ( & V_239 ) )
return - V_240 ;
F_32 (entry, tmp, &batch_list, list) {
if ( V_228 [ V_155 ] )
V_37 -> V_57 -> V_154 = F_122 ( F_131 ( V_228 [ V_155 ] ) ) ;
F_33 ( V_37 , V_230 ) ;
}
return 0 ;
}
static struct V_108 * F_132 ( struct V_113 * V_114 ,
const struct V_101 * V_102 ,
const struct V_83 * const V_228 [] ,
struct V_36 * V_37 ,
enum V_110 * V_112 )
{
struct V_108 * V_109 ;
V_109 = V_114 -> V_129 ( V_37 -> V_57 , V_112 ) ;
if ( V_109 == NULL )
return NULL ;
if ( V_114 -> V_241 ( V_228 [ V_171 ] , V_109 ) < 0 )
return NULL ;
if ( V_228 [ V_242 ] )
V_114 -> V_243 ( V_228 [ V_242 ] , V_109 ,
F_127 ( V_37 -> V_57 ) . V_12 ,
F_133 ( V_102 ) ) ;
return V_109 ;
}
static int F_134 ( struct V_36 * V_37 ,
const struct V_83 * const V_228 [] )
{
if ( V_228 [ V_85 ] ) {
struct V_83 * V_244 [ V_245 + 1 ] ;
int V_14 ;
V_14 = F_135 ( V_244 , V_245 , V_228 [ V_85 ] ,
V_246 , NULL ) ;
if ( V_14 < 0 )
return V_14 ;
if ( ! V_244 [ V_87 ] || ! V_244 [ V_89 ] )
return - V_199 ;
V_37 -> V_57 -> V_88 = F_126 ( F_136 ( V_244 [ V_87 ] ) ) ;
V_37 -> V_57 -> V_90 = F_136 ( V_244 [ V_89 ] ) ;
}
if ( V_228 [ V_92 ] ) {
int V_247 = V_37 -> V_57 -> V_81 -
V_37 -> V_57 -> V_82 ;
if ( V_247 != V_176 ( V_228 [ V_92 ] ) )
return - V_199 ;
else if ( V_247 > 0 )
memcpy ( F_57 ( V_37 -> V_57 ) ,
F_73 ( V_228 [ V_92 ] ) ,
V_247 ) ;
}
return 0 ;
}
static int F_137 ( struct V_2 * V_2 , struct V_58 * V_236 ,
struct V_46 * V_57 ,
const struct V_101 * V_102 ,
const struct V_83 * const V_228 [] )
{
struct V_103 * V_104 = F_71 ( V_102 ) ;
T_2 V_4 = F_126 ( V_104 -> V_139 ) ;
struct V_227 * V_229 ;
struct V_6 * V_35 ;
unsigned int V_230 ;
struct V_36 * V_37 ;
enum V_110 V_111 ( V_112 ) ;
struct V_113 * V_114 ;
struct V_108 * V_109 = NULL ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
int V_14 ;
V_35 = F_120 ( V_7 , V_4 ,
F_127 ( V_57 ) . V_12 ) ;
if ( F_128 ( V_35 ) )
return F_129 ( V_35 ) ;
V_229 = F_121 ( V_228 ) ;
if ( ! V_229 )
return - V_199 ;
V_230 = F_122 ( V_229 -> V_230 ) ;
V_37 = F_28 ( V_35 , F_122 ( V_229 -> V_40 ) ) ;
if ( V_37 == NULL )
return - V_240 ;
V_114 = F_65 ( V_113 ) ;
if ( V_228 [ V_171 ] ) {
if ( V_114 != NULL )
V_109 = F_132 ( V_114 , V_102 , V_228 , V_37 , & V_112 ) ;
}
if ( V_37 -> V_77 . V_78 == V_79 ) {
V_14 = F_134 ( V_37 , V_228 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_228 [ V_175 ] ) {
T_8 V_248 = V_176 ( V_228 [ V_175 ] ) ;
int V_205 = V_248 - V_37 -> V_57 -> V_91 ;
if ( F_102 ( F_73 ( V_228 [ V_175 ] ) ,
V_248 , V_37 , V_205 ) < 0 )
V_230 = V_45 ;
if ( V_109 && V_205 )
V_114 -> V_249 ( V_37 -> V_57 , V_109 , V_112 , V_205 ) ;
}
if ( V_228 [ V_155 ] )
V_37 -> V_57 -> V_154 = F_122 ( F_131 ( V_228 [ V_155 ] ) ) ;
F_33 ( V_37 , V_230 ) ;
return 0 ;
}
static int F_138 ( struct V_2 * V_2 , struct V_58 * V_236 ,
struct V_46 * V_57 , const struct V_101 * V_102 ,
const struct V_83 * const V_228 [] )
{
return - V_250 ;
}
static int F_139 ( struct V_2 * V_2 , struct V_58 * V_236 ,
struct V_46 * V_57 , const struct V_101 * V_102 ,
const struct V_83 * const V_228 [] )
{
struct V_103 * V_104 = F_71 ( V_102 ) ;
T_2 V_4 = F_126 ( V_104 -> V_139 ) ;
struct V_6 * V_35 ;
struct V_251 * V_252 = NULL ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
T_5 V_50 = 0 , V_253 = 0 ;
int V_192 = 0 ;
if ( V_228 [ V_254 ] ) {
V_252 = F_73 ( V_228 [ V_254 ] ) ;
switch ( V_252 -> V_255 ) {
case V_256 : return 0 ;
case V_257 : return 0 ;
}
}
if ( V_228 [ V_258 ] ) {
if ( ! V_228 [ V_259 ] ) {
return - V_199 ;
}
V_50 = F_122 ( F_131 ( V_228 [ V_258 ] ) ) ;
V_253 = F_122 ( F_131 ( V_228 [ V_259 ] ) ) ;
if ( V_50 >= V_260 )
return - V_261 ;
#if ! F_45 ( V_73 )
if ( V_50 & V_253 & V_132 )
return - V_261 ;
#endif
if ( ( V_50 & V_253 & V_128 ) &&
! F_140 ( V_113 ) ) {
#ifdef F_141
F_142 ( V_134 ) ;
F_143 ( L_5 ) ;
F_144 ( V_134 ) ;
if ( F_140 ( V_113 ) )
return - V_30 ;
#endif
return - V_261 ;
}
}
F_112 () ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( V_35 && V_35 -> V_20 != F_127 ( V_57 ) . V_12 ) {
V_192 = - V_226 ;
goto V_188;
}
if ( V_252 != NULL ) {
switch ( V_252 -> V_255 ) {
case V_262 :
if ( V_35 ) {
V_192 = - V_263 ;
goto V_188;
}
V_35 = F_6 ( V_7 , V_4 ,
F_127 ( V_57 ) . V_12 ) ;
if ( F_128 ( V_35 ) ) {
V_192 = F_129 ( V_35 ) ;
goto V_188;
}
break;
case V_264 :
if ( ! V_35 ) {
V_192 = - V_225 ;
goto V_188;
}
F_23 ( V_7 , V_35 ) ;
goto V_188;
case V_256 :
case V_257 :
break;
default:
V_192 = - V_250 ;
goto V_188;
}
}
if ( ! V_35 ) {
V_192 = - V_225 ;
goto V_188;
}
if ( V_228 [ V_265 ] ) {
struct V_266 * V_267 =
F_73 ( V_228 [ V_265 ] ) ;
F_109 ( V_35 , V_267 -> V_25 ,
F_122 ( V_267 -> V_23 ) ) ;
}
if ( V_228 [ V_268 ] ) {
T_6 * V_21 = F_73 ( V_228 [ V_268 ] ) ;
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_21 = F_122 ( * V_21 ) ;
F_31 ( & V_35 -> V_27 ) ;
}
if ( V_228 [ V_258 ] ) {
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_50 &= ~ V_253 ;
V_35 -> V_50 |= V_50 & V_253 ;
F_31 ( & V_35 -> V_27 ) ;
}
V_188:
F_113 () ;
return V_192 ;
}
static struct V_222 * F_145 ( struct V_269 * V_270 )
{
struct V_271 * V_272 = V_270 -> V_273 ;
struct V_2 * V_2 ;
struct V_1 * V_7 ;
if ( ! V_272 )
return NULL ;
V_2 = F_146 ( V_270 ) ;
V_7 = F_1 ( V_2 ) ;
for ( V_272 -> V_274 = 0 ; V_272 -> V_274 < V_5 ; V_272 -> V_274 ++ ) {
if ( ! F_147 ( & V_7 -> V_11 [ V_272 -> V_274 ] ) )
return V_7 -> V_11 [ V_272 -> V_274 ] . V_275 ;
}
return NULL ;
}
static struct V_222 * F_148 ( struct V_269 * V_270 , struct V_222 * V_13 )
{
struct V_271 * V_272 = V_270 -> V_273 ;
struct V_2 * V_2 = F_146 ( V_270 ) ;
V_13 = V_13 -> V_44 ;
while ( ! V_13 ) {
struct V_1 * V_7 ;
if ( ++ V_272 -> V_274 >= V_5 )
return NULL ;
V_7 = F_1 ( V_2 ) ;
V_13 = V_7 -> V_11 [ V_272 -> V_274 ] . V_275 ;
}
return V_13 ;
}
static struct V_222 * F_149 ( struct V_269 * V_270 , T_9 V_276 )
{
struct V_222 * V_9 ;
V_9 = F_145 ( V_270 ) ;
if ( V_9 )
while ( V_276 && ( V_9 = F_148 ( V_270 , V_9 ) ) )
V_276 -- ;
return V_276 ? NULL : V_9 ;
}
static void * F_150 ( struct V_269 * V_277 , T_9 * V_276 )
__acquires( nfnl_queue_pernet( seq_file_net( V_277 )
static void * F_151 ( struct V_269 * V_277 , void * V_278 , T_9 * V_276 )
{
( * V_276 ) ++ ;
return F_148 ( V_277 , V_278 ) ;
}
static void F_152 ( struct V_269 * V_277 , void * V_278 )
__releases( nfnl_queue_pernet( seq_file_net( V_277 )
static int F_153 ( struct V_269 * V_277 , void * V_278 )
{
const struct V_6 * V_10 = V_278 ;
F_154 ( V_277 , L_6 ,
V_10 -> V_4 ,
V_10 -> V_20 , V_10 -> V_39 ,
V_10 -> V_25 , V_10 -> V_23 ,
V_10 -> V_183 , V_10 -> V_187 ,
V_10 -> V_185 , 1 ) ;
return 0 ;
}
static int F_155 ( struct V_279 * V_279 , struct V_63 * V_63 )
{
return F_156 ( V_279 , V_63 , & V_280 ,
sizeof( struct V_271 ) ) ;
}
static int T_10 F_157 ( struct V_2 * V_2 )
{
unsigned int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ )
F_158 ( & V_7 -> V_11 [ V_41 ] ) ;
F_9 ( & V_7 -> V_15 ) ;
#ifdef F_159
if ( ! F_160 ( L_7 , 0440 ,
V_2 -> V_281 . V_282 , & V_283 ) )
return - V_19 ;
#endif
F_161 ( V_2 , & V_284 ) ;
return 0 ;
}
static void T_11 F_162 ( struct V_2 * V_2 )
{
F_163 ( V_2 ) ;
#ifdef F_159
F_164 ( L_7 , V_2 -> V_281 . V_282 ) ;
#endif
}
static void F_165 ( struct V_285 * V_286 )
{
F_166 () ;
}
static int T_12 F_167 ( void )
{
int V_210 ;
V_210 = F_168 ( & V_287 ) ;
if ( V_210 < 0 ) {
F_169 ( L_8 ) ;
goto V_123;
}
F_170 ( & V_288 ) ;
V_210 = F_171 ( & V_289 ) ;
if ( V_210 < 0 ) {
F_169 ( L_9 ) ;
goto V_290;
}
V_210 = F_172 ( & V_291 ) ;
if ( V_210 < 0 ) {
F_169 ( L_10 ) ;
goto V_292;
}
return V_210 ;
V_292:
F_173 ( & V_289 ) ;
V_290:
F_174 ( & V_288 ) ;
F_175 ( & V_287 ) ;
V_123:
return V_210 ;
}
static void T_13 F_176 ( void )
{
F_177 ( & V_291 ) ;
F_173 ( & V_289 ) ;
F_174 ( & V_288 ) ;
F_175 ( & V_287 ) ;
F_178 () ;
}
