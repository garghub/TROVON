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
T_7 V_77 = 0 , V_78 = 0 ;
unsigned int V_79 = 0 ;
struct V_46 * V_57 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
struct V_46 * V_88 = V_37 -> V_57 ;
struct V_89 * V_90 ;
struct V_89 * V_91 ;
struct V_92 * V_93 = NULL ;
enum V_94 V_95 ( V_96 ) ;
struct V_97 * V_98 ;
bool V_49 ;
char * V_71 = NULL ;
T_3 V_72 = 0 ;
V_76 = F_48 ( sizeof( struct V_86 ) )
+ F_49 ( sizeof( struct V_82 ) )
+ F_49 ( sizeof( V_99 ) )
+ F_49 ( sizeof( V_99 ) )
#if F_45 ( V_100 )
+ F_49 ( sizeof( V_99 ) )
+ F_49 ( sizeof( V_99 ) )
#endif
+ F_49 ( sizeof( V_99 ) )
+ F_49 ( sizeof( struct V_101 ) )
+ F_49 ( sizeof( V_99 ) )
+ F_49 ( sizeof( V_99 ) ) ;
if ( V_88 -> V_102 . V_103 )
V_76 += F_49 ( sizeof( struct V_104 ) ) ;
if ( V_37 -> V_105 . V_106 <= V_107 ||
( V_37 -> V_105 . V_106 == V_108 && V_88 -> V_59 == NULL ) )
V_49 = ! F_50 ( V_88 ) ;
else
V_49 = false ;
V_91 = V_37 -> V_105 . V_109 ;
switch ( (enum V_110 ) F_51 ( V_35 -> V_25 ) ) {
case V_111 :
case V_26 :
break;
case V_112 :
if ( ! ( V_35 -> V_50 & V_113 ) &&
V_88 -> V_51 == V_52 &&
F_52 ( V_88 ) )
return NULL ;
V_77 = F_51 ( V_35 -> V_23 ) ;
if ( V_77 > V_88 -> V_114 )
V_77 = V_88 -> V_114 ;
V_79 = F_53 ( V_88 ) ;
V_79 = F_54 (unsigned int, hlen, data_len) ;
V_76 += sizeof( struct V_80 ) + V_79 ;
V_78 = V_88 -> V_114 ;
break;
}
V_98 = F_55 ( V_97 ) ;
if ( V_35 -> V_50 & V_115 ) {
if ( V_98 != NULL ) {
V_93 = V_98 -> V_116 ( V_88 , & V_96 ) ;
if ( V_93 != NULL )
V_76 += V_98 -> V_117 ( V_93 ) ;
}
}
if ( V_35 -> V_50 & V_118 ) {
V_76 += ( F_49 ( sizeof( V_99 ) )
+ F_49 ( sizeof( V_99 ) ) ) ;
}
if ( ( V_35 -> V_50 & V_119 ) && V_88 -> V_59 ) {
V_72 = F_44 ( V_88 , & V_71 ) ;
if ( V_72 )
V_76 += F_49 ( V_72 ) ;
}
V_57 = F_56 ( V_76 , V_18 ) ;
if ( ! V_57 ) {
F_57 ( V_88 ) ;
return NULL ;
}
V_85 = F_58 ( V_57 , 0 , 0 ,
V_120 << 8 | V_121 ,
sizeof( struct V_86 ) , 0 ) ;
if ( ! V_85 ) {
F_57 ( V_88 ) ;
F_59 ( V_57 ) ;
return NULL ;
}
V_87 = F_60 ( V_85 ) ;
V_87 -> V_122 = V_37 -> V_105 . V_123 ;
V_87 -> V_124 = V_125 ;
V_87 -> V_126 = F_61 ( V_35 -> V_4 ) ;
V_81 = F_62 ( V_57 , V_127 , sizeof( * V_83 ) ) ;
V_83 = F_63 ( V_81 ) ;
V_83 -> V_128 = V_88 -> V_129 ;
V_83 -> V_106 = V_37 -> V_105 . V_106 ;
* V_75 = & V_83 -> V_130 ;
V_90 = V_37 -> V_105 . V_131 ;
if ( V_90 ) {
#if ! F_45 ( V_100 )
if ( F_36 ( V_57 , V_132 , F_37 ( V_90 -> V_133 ) ) )
goto V_68;
#else
if ( V_37 -> V_105 . V_123 == V_134 ) {
if ( F_36 ( V_57 , V_135 ,
F_37 ( V_90 -> V_133 ) ) ||
F_36 ( V_57 , V_132 ,
F_37 ( F_64 ( V_90 ) -> V_136 -> V_137 -> V_133 ) ) )
goto V_68;
} else {
int V_138 ;
if ( F_36 ( V_57 , V_132 ,
F_37 ( V_90 -> V_133 ) ) )
goto V_68;
V_138 = F_65 ( V_88 ) ;
if ( V_138 &&
F_36 ( V_57 , V_135 ,
F_37 ( V_138 ) ) )
goto V_68;
}
#endif
}
if ( V_91 ) {
#if ! F_45 ( V_100 )
if ( F_36 ( V_57 , V_139 , F_37 ( V_91 -> V_133 ) ) )
goto V_68;
#else
if ( V_37 -> V_105 . V_123 == V_134 ) {
if ( F_36 ( V_57 , V_140 ,
F_37 ( V_91 -> V_133 ) ) ||
F_36 ( V_57 , V_139 ,
F_37 ( F_64 ( V_91 ) -> V_136 -> V_137 -> V_133 ) ) )
goto V_68;
} else {
int V_141 ;
if ( F_36 ( V_57 , V_139 ,
F_37 ( V_91 -> V_133 ) ) )
goto V_68;
V_141 = F_66 ( V_88 ) ;
if ( V_141 &&
F_36 ( V_57 , V_140 ,
F_37 ( V_141 ) ) )
goto V_68;
}
#endif
}
if ( V_88 -> V_142 &&
F_36 ( V_57 , V_143 , F_37 ( V_88 -> V_142 ) ) )
goto V_68;
if ( V_90 && V_88 -> V_137 &&
V_88 -> V_144 != V_88 -> V_145 ) {
struct V_101 V_146 ;
int V_114 ;
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
V_114 = F_67 ( V_88 , V_146 . V_147 ) ;
if ( V_114 ) {
V_146 . V_148 = F_61 ( V_114 ) ;
if ( F_68 ( V_57 , V_149 , sizeof( V_146 ) , & V_146 ) )
goto V_68;
}
}
if ( V_88 -> V_102 . V_103 ) {
struct V_104 V_150 ;
struct V_151 V_152 = F_69 ( V_57 -> V_102 ) ;
V_150 . V_153 = F_70 ( V_152 . V_154 ) ;
V_150 . V_155 = F_70 ( V_152 . V_156 / V_157 ) ;
if ( F_68 ( V_57 , V_158 , sizeof( V_150 ) , & V_150 ) )
goto V_68;
}
if ( ( V_35 -> V_50 & V_118 ) && V_88 -> V_59 &&
F_38 ( V_57 , V_88 -> V_59 ) < 0 )
goto V_68;
if ( V_72 && F_68 ( V_57 , V_159 , V_72 , V_71 ) )
goto V_68;
if ( V_93 && V_98 -> V_160 ( V_57 , V_93 , V_96 , V_161 , V_162 ) < 0 )
goto V_68;
if ( V_78 > V_77 &&
F_36 ( V_57 , V_163 , F_37 ( V_78 ) ) )
goto V_68;
if ( F_34 ( V_57 , V_88 , V_49 ) )
goto V_68;
if ( V_77 ) {
struct V_80 * V_81 ;
if ( F_71 ( V_57 ) < sizeof( * V_81 ) + V_79 )
goto V_68;
V_81 = (struct V_80 * ) F_72 ( V_57 , sizeof( * V_81 ) ) ;
V_81 -> V_164 = V_165 ;
V_81 -> V_166 = F_73 ( V_77 ) ;
if ( F_74 ( V_57 , V_88 , V_77 , V_79 ) )
goto V_68;
}
V_85 -> V_167 = V_57 -> V_114 ;
return V_57 ;
V_68:
F_57 ( V_88 ) ;
F_59 ( V_57 ) ;
F_75 ( L_1 ) ;
return NULL ;
}
static int
F_76 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 )
{
struct V_46 * V_168 ;
int V_14 = - V_169 ;
T_6 * V_75 ;
int V_170 = 0 ;
V_168 = F_47 ( V_2 , V_35 , V_37 , & V_75 ) ;
if ( V_168 == NULL ) {
V_14 = - V_19 ;
goto V_171;
}
F_29 ( & V_35 -> V_27 ) ;
if ( V_35 -> V_39 >= V_35 -> V_21 ) {
if ( V_35 -> V_50 & V_172 ) {
V_170 = 1 ;
V_14 = 0 ;
} else {
V_35 -> V_173 ++ ;
F_77 ( L_2 ,
V_35 -> V_39 ) ;
}
goto V_174;
}
V_37 -> V_40 = ++ V_35 -> V_175 ;
* V_75 = F_37 ( V_37 -> V_40 ) ;
V_14 = F_78 ( V_168 , V_2 , V_35 -> V_20 , V_176 ) ;
if ( V_14 < 0 ) {
if ( V_35 -> V_50 & V_172 ) {
V_170 = 1 ;
V_14 = 0 ;
} else {
V_35 -> V_177 ++ ;
}
goto V_178;
}
F_24 ( V_35 , V_37 ) ;
F_31 ( & V_35 -> V_27 ) ;
return 0 ;
V_174:
F_59 ( V_168 ) ;
V_178:
F_31 ( & V_35 -> V_27 ) ;
if ( V_170 )
F_33 ( V_37 , V_179 ) ;
V_171:
return V_14 ;
}
static struct V_36 *
F_79 ( struct V_36 * V_180 )
{
struct V_36 * V_37 = F_80 ( V_180 , V_180 -> V_76 , V_18 ) ;
if ( V_37 )
F_81 ( V_37 ) ;
return V_37 ;
}
static void F_82 ( struct V_46 * V_57 )
{
if ( V_57 -> V_181 )
F_83 ( V_57 , V_57 -> V_145 - V_57 -> V_144 ) ;
}
static void F_84 ( struct V_46 * V_57 )
{
if ( V_57 -> V_181 )
F_85 ( V_57 , V_57 -> V_145 - V_57 -> V_144 ) ;
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
int V_182 = - V_19 ;
struct V_36 * V_183 ;
F_84 ( V_57 ) ;
if ( V_57 -> V_44 == NULL ) {
struct V_46 * V_184 = V_37 -> V_57 ;
V_37 -> V_57 = V_57 ;
V_182 = F_76 ( V_2 , V_35 , V_37 ) ;
if ( V_182 )
V_37 -> V_57 = V_184 ;
return V_182 ;
}
V_57 -> V_44 = NULL ;
V_183 = F_79 ( V_37 ) ;
if ( V_183 ) {
V_183 -> V_57 = V_57 ;
V_182 = F_76 ( V_2 , V_35 , V_183 ) ;
if ( V_182 )
F_86 ( V_183 ) ;
}
return V_182 ;
}
static int
F_89 ( struct V_36 * V_37 , unsigned int V_185 )
{
unsigned int V_186 ;
struct V_6 * V_35 ;
struct V_46 * V_57 , * V_187 ;
int V_14 = - V_169 ;
struct V_2 * V_2 = V_37 -> V_105 . V_2 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_185 ) ;
if ( ! V_35 )
return - V_188 ;
if ( V_35 -> V_25 == V_26 )
return - V_189 ;
V_57 = V_37 -> V_57 ;
switch ( V_37 -> V_105 . V_123 ) {
case V_190 :
V_57 -> V_129 = F_61 ( V_191 ) ;
break;
case V_192 :
V_57 -> V_129 = F_61 ( V_193 ) ;
break;
}
if ( ( V_35 -> V_50 & V_113 ) || ! F_35 ( V_57 ) )
return F_76 ( V_2 , V_35 , V_37 ) ;
F_82 ( V_57 ) ;
V_187 = F_90 ( V_57 , 0 ) ;
if ( F_91 ( V_187 ) )
goto V_194;
V_186 = 0 ;
V_14 = 0 ;
do {
struct V_46 * V_168 = V_187 -> V_44 ;
if ( V_14 == 0 )
V_14 = F_88 ( V_2 , V_35 ,
V_187 , V_37 ) ;
if ( V_14 == 0 )
V_186 ++ ;
else
F_59 ( V_187 ) ;
V_187 = V_168 ;
} while ( V_187 );
if ( V_186 ) {
if ( V_14 )
F_86 ( V_37 ) ;
F_59 ( V_57 ) ;
return 0 ;
}
V_194:
F_84 ( V_57 ) ;
return V_14 ;
}
static int
F_92 ( void * V_43 , int V_77 , struct V_36 * V_180 , int V_195 )
{
struct V_46 * V_168 ;
if ( V_195 < 0 ) {
if ( F_93 ( V_180 -> V_57 , V_77 ) )
return - V_19 ;
} else if ( V_195 > 0 ) {
if ( V_77 > 0xFFFF )
return - V_189 ;
if ( V_195 > F_71 ( V_180 -> V_57 ) ) {
V_168 = F_94 ( V_180 -> V_57 , F_95 ( V_180 -> V_57 ) ,
V_195 , V_18 ) ;
if ( ! V_168 ) {
F_96 ( V_196 L_3
L_4 ) ;
return - V_19 ;
}
F_59 ( V_180 -> V_57 ) ;
V_180 -> V_57 = V_168 ;
}
F_72 ( V_180 -> V_57 , V_195 ) ;
}
if ( ! F_97 ( V_180 -> V_57 , V_77 ) )
return - V_19 ;
F_98 ( V_180 -> V_57 , V_43 , V_77 ) ;
V_180 -> V_57 -> V_51 = V_197 ;
return 0 ;
}
static int
F_99 ( struct V_6 * V_35 ,
unsigned char V_198 , unsigned int V_199 )
{
int V_200 = 0 ;
F_29 ( & V_35 -> V_27 ) ;
switch ( V_198 ) {
case V_26 :
case V_111 :
V_35 -> V_25 = V_198 ;
V_35 -> V_23 = 0 ;
break;
case V_112 :
V_35 -> V_25 = V_198 ;
if ( V_199 == 0 || V_199 > V_24 )
V_35 -> V_23 = V_24 ;
else
V_35 -> V_23 = V_199 ;
break;
default:
V_200 = - V_189 ;
}
F_31 ( & V_35 -> V_27 ) ;
return V_200 ;
}
static int
F_100 ( struct V_36 * V_37 , unsigned long V_133 )
{
if ( V_37 -> V_105 . V_131 )
if ( V_37 -> V_105 . V_131 -> V_133 == V_133 )
return 1 ;
if ( V_37 -> V_105 . V_109 )
if ( V_37 -> V_105 . V_109 -> V_133 == V_133 )
return 1 ;
#if F_45 ( V_100 )
if ( V_37 -> V_57 -> V_181 ) {
int V_138 , V_141 ;
V_138 = F_65 ( V_37 -> V_57 ) ;
V_141 = F_66 ( V_37 -> V_57 ) ;
if ( V_138 == V_133 || V_141 == V_133 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_101 ( struct V_2 * V_2 , int V_133 )
{
int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
F_102 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_100 , V_133 ) ;
}
F_103 () ;
}
static int
F_104 ( struct V_201 * V_202 ,
unsigned long V_203 , void * V_204 )
{
struct V_89 * V_137 = F_105 ( V_204 ) ;
if ( V_203 == V_205 )
F_101 ( F_106 ( V_137 ) , V_137 -> V_133 ) ;
return V_206 ;
}
static int F_107 ( struct V_36 * V_37 , unsigned long V_207 )
{
return V_37 -> V_208 == (struct V_209 * ) V_207 ;
}
static void F_108 ( struct V_2 * V_2 , struct V_209 * V_106 )
{
struct V_1 * V_7 = F_1 ( V_2 ) ;
int V_41 ;
F_102 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_107 , ( unsigned long ) V_106 ) ;
}
F_103 () ;
}
static int
F_109 ( struct V_201 * V_202 ,
unsigned long V_203 , void * V_204 )
{
struct V_210 * V_211 = V_204 ;
struct V_1 * V_7 = F_1 ( V_211 -> V_2 ) ;
if ( V_203 == V_212 && V_211 -> V_129 == V_213 ) {
int V_41 ;
F_7 ( & V_7 -> V_15 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_214 * V_215 ;
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_110 (inst, t2, head, hlist) {
if ( V_211 -> V_12 == V_10 -> V_20 )
F_20 ( V_10 ) ;
}
}
F_13 ( & V_7 -> V_15 ) ;
}
return V_206 ;
}
static struct V_6 *
F_111 ( struct V_1 * V_7 , T_8 V_4 , T_3 V_216 )
{
struct V_6 * V_35 ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
return F_15 ( - V_217 ) ;
if ( V_35 -> V_20 != V_216 )
return F_15 ( - V_218 ) ;
return V_35 ;
}
static struct V_219 *
F_112 ( const struct V_80 * const V_220 [] )
{
struct V_219 * V_221 ;
unsigned int V_222 ;
if ( ! V_220 [ V_223 ] )
return NULL ;
V_221 = F_63 ( V_220 [ V_223 ] ) ;
V_222 = F_113 ( V_221 -> V_222 ) & V_224 ;
if ( V_222 > V_225 || V_222 == V_226 )
return NULL ;
return V_221 ;
}
static int F_114 ( unsigned int V_40 , unsigned int V_227 )
{
return ( int ) ( V_40 - V_227 ) > 0 ;
}
static int F_115 ( struct V_2 * V_2 , struct V_58 * V_228 ,
struct V_46 * V_57 ,
const struct V_84 * V_85 ,
const struct V_80 * const V_220 [] )
{
struct V_86 * V_87 = F_60 ( V_85 ) ;
struct V_36 * V_37 , * V_229 ;
unsigned int V_222 , V_230 ;
struct V_219 * V_221 ;
struct V_6 * V_35 ;
F_116 ( V_231 ) ;
T_8 V_4 = F_117 ( V_87 -> V_126 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_111 ( V_7 , V_4 ,
F_118 ( V_57 ) . V_12 ) ;
if ( F_119 ( V_35 ) )
return F_120 ( V_35 ) ;
V_221 = F_112 ( V_220 ) ;
if ( ! V_221 )
return - V_189 ;
V_222 = F_113 ( V_221 -> V_222 ) ;
V_230 = F_113 ( V_221 -> V_40 ) ;
F_29 ( & V_35 -> V_27 ) ;
F_32 (entry, tmp, &queue->queue_list, list) {
if ( F_114 ( V_37 -> V_40 , V_230 ) )
break;
F_26 ( V_35 , V_37 ) ;
F_25 ( & V_37 -> V_38 , & V_231 ) ;
}
F_31 ( & V_35 -> V_27 ) ;
if ( F_121 ( & V_231 ) )
return - V_232 ;
F_32 (entry, tmp, &batch_list, list) {
if ( V_220 [ V_143 ] )
V_37 -> V_57 -> V_142 = F_113 ( F_122 ( V_220 [ V_143 ] ) ) ;
F_33 ( V_37 , V_222 ) ;
}
return 0 ;
}
static struct V_92 * F_123 ( struct V_97 * V_98 ,
const struct V_84 * V_85 ,
const struct V_80 * const V_220 [] ,
struct V_36 * V_37 ,
enum V_94 * V_96 )
{
struct V_92 * V_93 ;
V_93 = V_98 -> V_116 ( V_37 -> V_57 , V_96 ) ;
if ( V_93 == NULL )
return NULL ;
if ( V_98 -> V_233 ( V_220 [ V_161 ] , V_93 ) < 0 )
return NULL ;
if ( V_220 [ V_234 ] )
V_98 -> V_235 ( V_220 [ V_234 ] , V_93 ,
F_118 ( V_37 -> V_57 ) . V_12 ,
F_124 ( V_85 ) ) ;
return V_93 ;
}
static int F_125 ( struct V_2 * V_2 , struct V_58 * V_228 ,
struct V_46 * V_57 ,
const struct V_84 * V_85 ,
const struct V_80 * const V_220 [] )
{
struct V_86 * V_87 = F_60 ( V_85 ) ;
T_2 V_4 = F_117 ( V_87 -> V_126 ) ;
struct V_219 * V_221 ;
struct V_6 * V_35 ;
unsigned int V_222 ;
struct V_36 * V_37 ;
enum V_94 V_95 ( V_96 ) ;
struct V_97 * V_98 ;
struct V_92 * V_93 = NULL ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
V_35 = F_111 ( V_7 , V_4 ,
F_118 ( V_57 ) . V_12 ) ;
if ( F_119 ( V_35 ) )
return F_120 ( V_35 ) ;
V_221 = F_112 ( V_220 ) ;
if ( ! V_221 )
return - V_189 ;
V_222 = F_113 ( V_221 -> V_222 ) ;
V_37 = F_28 ( V_35 , F_113 ( V_221 -> V_40 ) ) ;
if ( V_37 == NULL )
return - V_232 ;
V_98 = F_55 ( V_97 ) ;
if ( V_220 [ V_161 ] ) {
if ( V_98 != NULL )
V_93 = F_123 ( V_98 , V_85 , V_220 , V_37 , & V_96 ) ;
}
if ( V_220 [ V_165 ] ) {
T_8 V_236 = V_166 ( V_220 [ V_165 ] ) ;
int V_195 = V_236 - V_37 -> V_57 -> V_114 ;
if ( F_92 ( F_63 ( V_220 [ V_165 ] ) ,
V_236 , V_37 , V_195 ) < 0 )
V_222 = V_45 ;
if ( V_93 && V_195 )
V_98 -> V_237 ( V_37 -> V_57 , V_93 , V_96 , V_195 ) ;
}
if ( V_220 [ V_143 ] )
V_37 -> V_57 -> V_142 = F_113 ( F_122 ( V_220 [ V_143 ] ) ) ;
F_33 ( V_37 , V_222 ) ;
return 0 ;
}
static int F_126 ( struct V_2 * V_2 , struct V_58 * V_228 ,
struct V_46 * V_57 , const struct V_84 * V_85 ,
const struct V_80 * const V_220 [] )
{
return - V_238 ;
}
static int F_127 ( struct V_2 * V_2 , struct V_58 * V_228 ,
struct V_46 * V_57 , const struct V_84 * V_85 ,
const struct V_80 * const V_220 [] )
{
struct V_86 * V_87 = F_60 ( V_85 ) ;
T_2 V_4 = F_117 ( V_87 -> V_126 ) ;
struct V_6 * V_35 ;
struct V_239 * V_240 = NULL ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
T_5 V_50 = 0 , V_241 = 0 ;
int V_182 = 0 ;
if ( V_220 [ V_242 ] ) {
V_240 = F_63 ( V_220 [ V_242 ] ) ;
switch ( V_240 -> V_243 ) {
case V_244 : return 0 ;
case V_245 : return 0 ;
}
}
if ( V_220 [ V_246 ] ) {
if ( ! V_220 [ V_247 ] ) {
return - V_189 ;
}
V_50 = F_113 ( F_122 ( V_220 [ V_246 ] ) ) ;
V_241 = F_113 ( F_122 ( V_220 [ V_247 ] ) ) ;
if ( V_50 >= V_248 )
return - V_249 ;
#if ! F_45 ( V_73 )
if ( V_50 & V_241 & V_119 )
return - V_249 ;
#endif
if ( ( V_50 & V_241 & V_115 ) &&
! F_128 ( V_97 ) ) {
#ifdef F_129
F_130 ( V_120 ) ;
F_131 ( L_5 ) ;
F_132 ( V_120 ) ;
if ( F_128 ( V_97 ) )
return - V_30 ;
#endif
return - V_249 ;
}
}
F_102 () ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( V_35 && V_35 -> V_20 != F_118 ( V_57 ) . V_12 ) {
V_182 = - V_218 ;
goto V_178;
}
if ( V_240 != NULL ) {
switch ( V_240 -> V_243 ) {
case V_250 :
if ( V_35 ) {
V_182 = - V_251 ;
goto V_178;
}
V_35 = F_6 ( V_7 , V_4 ,
F_118 ( V_57 ) . V_12 ) ;
if ( F_119 ( V_35 ) ) {
V_182 = F_120 ( V_35 ) ;
goto V_178;
}
break;
case V_252 :
if ( ! V_35 ) {
V_182 = - V_217 ;
goto V_178;
}
F_23 ( V_7 , V_35 ) ;
goto V_178;
case V_244 :
case V_245 :
break;
default:
V_182 = - V_238 ;
goto V_178;
}
}
if ( ! V_35 ) {
V_182 = - V_217 ;
goto V_178;
}
if ( V_220 [ V_253 ] ) {
struct V_254 * V_255 =
F_63 ( V_220 [ V_253 ] ) ;
F_99 ( V_35 , V_255 -> V_25 ,
F_113 ( V_255 -> V_23 ) ) ;
}
if ( V_220 [ V_256 ] ) {
T_6 * V_21 = F_63 ( V_220 [ V_256 ] ) ;
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_21 = F_113 ( * V_21 ) ;
F_31 ( & V_35 -> V_27 ) ;
}
if ( V_220 [ V_246 ] ) {
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_50 &= ~ V_241 ;
V_35 -> V_50 |= V_50 & V_241 ;
F_31 ( & V_35 -> V_27 ) ;
}
V_178:
F_103 () ;
return V_182 ;
}
static struct V_214 * F_133 ( struct V_257 * V_258 )
{
struct V_259 * V_260 = V_258 -> V_261 ;
struct V_2 * V_2 ;
struct V_1 * V_7 ;
if ( ! V_260 )
return NULL ;
V_2 = F_134 ( V_258 ) ;
V_7 = F_1 ( V_2 ) ;
for ( V_260 -> V_262 = 0 ; V_260 -> V_262 < V_5 ; V_260 -> V_262 ++ ) {
if ( ! F_135 ( & V_7 -> V_11 [ V_260 -> V_262 ] ) )
return V_7 -> V_11 [ V_260 -> V_262 ] . V_263 ;
}
return NULL ;
}
static struct V_214 * F_136 ( struct V_257 * V_258 , struct V_214 * V_13 )
{
struct V_259 * V_260 = V_258 -> V_261 ;
struct V_2 * V_2 = F_134 ( V_258 ) ;
V_13 = V_13 -> V_44 ;
while ( ! V_13 ) {
struct V_1 * V_7 ;
if ( ++ V_260 -> V_262 >= V_5 )
return NULL ;
V_7 = F_1 ( V_2 ) ;
V_13 = V_7 -> V_11 [ V_260 -> V_262 ] . V_263 ;
}
return V_13 ;
}
static struct V_214 * F_137 ( struct V_257 * V_258 , T_9 V_264 )
{
struct V_214 * V_9 ;
V_9 = F_133 ( V_258 ) ;
if ( V_9 )
while ( V_264 && ( V_9 = F_136 ( V_258 , V_9 ) ) )
V_264 -- ;
return V_264 ? NULL : V_9 ;
}
static void * F_138 ( struct V_257 * V_265 , T_9 * V_264 )
__acquires( nfnl_queue_pernet( seq_file_net( V_265 )
static void * F_139 ( struct V_257 * V_265 , void * V_266 , T_9 * V_264 )
{
( * V_264 ) ++ ;
return F_136 ( V_265 , V_266 ) ;
}
static void F_140 ( struct V_257 * V_265 , void * V_266 )
__releases( nfnl_queue_pernet( seq_file_net( V_265 )
static int F_141 ( struct V_257 * V_265 , void * V_266 )
{
const struct V_6 * V_10 = V_266 ;
F_142 ( V_265 , L_6 ,
V_10 -> V_4 ,
V_10 -> V_20 , V_10 -> V_39 ,
V_10 -> V_25 , V_10 -> V_23 ,
V_10 -> V_173 , V_10 -> V_177 ,
V_10 -> V_175 , 1 ) ;
return 0 ;
}
static int F_143 ( struct V_267 * V_267 , struct V_63 * V_63 )
{
return F_144 ( V_267 , V_63 , & V_268 ,
sizeof( struct V_259 ) ) ;
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
V_2 -> V_269 . V_270 , & V_271 ) )
return - V_19 ;
#endif
return 0 ;
}
static void T_11 F_149 ( struct V_2 * V_2 )
{
#ifdef F_147
F_150 ( L_7 , V_2 -> V_269 . V_270 ) ;
#endif
}
static int T_12 F_151 ( void )
{
int V_200 ;
V_200 = F_152 ( & V_272 ) ;
if ( V_200 < 0 ) {
F_153 ( L_8 ) ;
goto V_109;
}
F_154 ( & V_273 ) ;
V_200 = F_155 ( & V_274 ) ;
if ( V_200 < 0 ) {
F_153 ( L_9 ) ;
goto V_275;
}
F_156 ( & V_276 ) ;
F_157 ( & V_277 ) ;
return V_200 ;
V_275:
F_158 ( & V_273 ) ;
F_159 ( & V_272 ) ;
V_109:
return V_200 ;
}
static void T_13 F_160 ( void )
{
F_161 () ;
F_162 ( & V_276 ) ;
F_163 ( & V_274 ) ;
F_158 ( & V_273 ) ;
F_159 ( & V_272 ) ;
F_164 () ;
}
