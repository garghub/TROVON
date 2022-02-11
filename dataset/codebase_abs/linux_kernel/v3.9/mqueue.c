static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_2 * V_2 )
{
return F_4 ( V_2 -> V_5 -> V_6 ) ;
}
static struct V_4 * F_5 ( struct V_2 * V_2 )
{
struct V_4 * V_7 ;
F_6 ( & V_8 ) ;
V_7 = F_3 ( V_2 ) ;
F_7 ( & V_8 ) ;
return V_7 ;
}
static int F_8 ( struct V_9 * V_10 , struct V_1 * V_11 )
{
struct V_12 * * V_13 , * V_14 = NULL ;
struct V_15 * V_16 ;
V_13 = & V_11 -> V_17 . V_12 ;
while ( * V_13 ) {
V_14 = * V_13 ;
V_16 = F_9 ( V_14 , struct V_15 , V_12 ) ;
if ( F_10 ( V_16 -> V_18 == V_10 -> V_19 ) )
goto V_20;
else if ( V_10 -> V_19 < V_16 -> V_18 )
V_13 = & ( * V_13 ) -> V_21 ;
else
V_13 = & ( * V_13 ) -> V_22 ;
}
if ( V_11 -> V_23 ) {
V_16 = V_11 -> V_23 ;
V_11 -> V_23 = NULL ;
} else {
V_16 = F_11 ( sizeof( * V_16 ) , V_24 ) ;
if ( ! V_16 )
return - V_25 ;
F_12 ( & V_16 -> V_26 ) ;
V_11 -> V_27 += sizeof( * V_16 ) ;
}
V_16 -> V_18 = V_10 -> V_19 ;
F_13 ( & V_16 -> V_12 , V_14 , V_13 ) ;
F_14 ( & V_16 -> V_12 , & V_11 -> V_17 ) ;
V_20:
V_11 -> V_28 . V_29 ++ ;
V_11 -> V_27 += V_10 -> V_30 ;
F_15 ( & V_10 -> V_31 , & V_16 -> V_26 ) ;
return 0 ;
}
static inline struct V_9 * F_16 ( struct V_1 * V_11 )
{
struct V_12 * * V_13 , * V_14 = NULL ;
struct V_15 * V_16 ;
struct V_9 * V_10 ;
V_32:
V_13 = & V_11 -> V_17 . V_12 ;
while ( * V_13 ) {
V_14 = * V_13 ;
V_13 = & ( * V_13 ) -> V_22 ;
}
if ( ! V_14 ) {
if ( V_11 -> V_28 . V_29 ) {
F_17 ( L_1
L_2
L_3 ) ;
V_11 -> V_28 . V_29 = 0 ;
}
return NULL ;
}
V_16 = F_9 ( V_14 , struct V_15 , V_12 ) ;
if ( F_18 ( F_19 ( & V_16 -> V_26 ) ) ) {
F_17 ( L_1
L_4
L_5 ) ;
F_20 ( & V_16 -> V_12 , & V_11 -> V_17 ) ;
if ( V_11 -> V_23 ) {
V_11 -> V_27 -= sizeof( * V_16 ) ;
F_21 ( V_16 ) ;
} else {
V_11 -> V_23 = V_16 ;
}
goto V_32;
} else {
V_10 = F_22 ( & V_16 -> V_26 ,
struct V_9 , V_31 ) ;
F_23 ( & V_10 -> V_31 ) ;
if ( F_19 ( & V_16 -> V_26 ) ) {
F_20 ( & V_16 -> V_12 , & V_11 -> V_17 ) ;
if ( V_11 -> V_23 ) {
V_11 -> V_27 -= sizeof( * V_16 ) ;
F_21 ( V_16 ) ;
} else {
V_11 -> V_23 = V_16 ;
}
}
}
V_11 -> V_28 . V_29 -- ;
V_11 -> V_27 -= V_10 -> V_30 ;
return V_10 ;
}
static struct V_2 * F_24 ( struct V_33 * V_34 ,
struct V_4 * V_35 , T_1 V_36 ,
struct V_37 * V_28 )
{
struct V_38 * V_39 = F_25 () ;
struct V_2 * V_2 ;
int V_40 = - V_25 ;
V_2 = F_26 ( V_34 ) ;
if ( ! V_2 )
goto V_41;
V_2 -> V_42 = F_27 () ;
V_2 -> V_43 = V_36 ;
V_2 -> V_44 = F_28 () ;
V_2 -> V_45 = F_29 () ;
V_2 -> V_46 = V_2 -> V_47 = V_2 -> V_48 = V_49 ;
if ( F_30 ( V_36 ) ) {
struct V_1 * V_11 ;
unsigned long V_50 , V_51 ;
V_2 -> V_52 = & V_53 ;
V_2 -> V_54 = V_55 ;
V_11 = F_1 ( V_2 ) ;
F_31 ( & V_11 -> V_56 ) ;
F_32 ( & V_11 -> V_57 ) ;
F_12 ( & V_11 -> V_58 [ 0 ] . V_59 ) ;
F_12 ( & V_11 -> V_58 [ 1 ] . V_59 ) ;
V_11 -> V_60 = NULL ;
V_11 -> V_61 = NULL ;
V_11 -> V_27 = 0 ;
V_11 -> V_62 = NULL ;
V_11 -> V_17 = V_63 ;
V_11 -> V_23 = NULL ;
memset ( & V_11 -> V_28 , 0 , sizeof( V_11 -> V_28 ) ) ;
V_11 -> V_28 . V_64 = F_33 ( V_35 -> V_65 ,
V_35 -> V_66 ) ;
V_11 -> V_28 . V_67 = F_33 ( V_35 -> V_68 ,
V_35 -> V_69 ) ;
if ( V_28 ) {
V_11 -> V_28 . V_64 = V_28 -> V_64 ;
V_11 -> V_28 . V_67 = V_28 -> V_67 ;
}
V_51 = V_11 -> V_28 . V_64 * sizeof( struct V_9 ) +
F_34 (unsigned int, info->attr.mq_maxmsg, MQ_PRIO_MAX) *
sizeof( struct V_15 ) ;
V_50 = V_51 + ( V_11 -> V_28 . V_64 *
V_11 -> V_28 . V_67 ) ;
F_6 ( & V_8 ) ;
if ( V_39 -> V_50 + V_50 < V_39 -> V_50 ||
V_39 -> V_50 + V_50 > F_35 ( V_70 ) ) {
F_7 ( & V_8 ) ;
V_40 = - V_71 ;
goto V_72;
}
V_39 -> V_50 += V_50 ;
F_7 ( & V_8 ) ;
V_11 -> V_62 = F_36 ( V_39 ) ;
} else if ( F_37 ( V_36 ) ) {
F_38 ( V_2 ) ;
V_2 -> V_54 = 2 * V_73 ;
V_2 -> V_74 = & V_75 ;
V_2 -> V_52 = & V_76 ;
}
return V_2 ;
V_72:
F_39 ( V_2 ) ;
V_41:
return F_40 ( V_40 ) ;
}
static int F_41 ( struct V_33 * V_34 , void * V_77 , int V_78 )
{
struct V_2 * V_2 ;
struct V_4 * V_7 = V_77 ;
V_34 -> V_79 = V_80 ;
V_34 -> V_81 = V_82 ;
V_34 -> V_83 = V_84 ;
V_34 -> V_85 = & V_86 ;
V_2 = F_24 ( V_34 , V_7 , V_87 | V_88 | V_89 , NULL ) ;
if ( F_42 ( V_2 ) )
return F_43 ( V_2 ) ;
V_34 -> V_90 = F_44 ( V_2 ) ;
if ( ! V_34 -> V_90 )
return - V_25 ;
return 0 ;
}
static struct V_91 * F_45 ( struct V_92 * V_93 ,
int V_94 , const char * V_95 ,
void * V_77 )
{
if ( ! ( V_94 & V_96 ) ) {
struct V_4 * V_7 = V_97 -> V_98 -> V_35 ;
if ( ! F_46 ( V_7 -> V_99 , V_100 ) )
return F_40 ( - V_101 ) ;
V_77 = V_7 ;
}
return F_47 ( V_93 , V_94 , V_77 , F_41 ) ;
}
static void F_48 ( void * V_102 )
{
struct V_1 * V_13 = (struct V_1 * ) V_102 ;
F_49 ( & V_13 -> V_3 ) ;
}
static struct V_2 * F_50 ( struct V_33 * V_34 )
{
struct V_1 * V_103 ;
V_103 = F_51 ( V_104 , V_105 ) ;
if ( ! V_103 )
return NULL ;
return & V_103 -> V_3 ;
}
static void F_52 ( struct V_106 * V_107 )
{
struct V_2 * V_2 = F_2 ( V_107 , struct V_2 , V_108 ) ;
F_53 ( V_104 , F_1 ( V_2 ) ) ;
}
static void F_54 ( struct V_2 * V_2 )
{
F_55 ( & V_2 -> V_108 , F_52 ) ;
}
static void F_56 ( struct V_2 * V_2 )
{
struct V_1 * V_11 ;
struct V_38 * V_62 ;
unsigned long V_50 , V_51 ;
struct V_4 * V_35 ;
struct V_9 * V_10 ;
F_57 ( V_2 ) ;
if ( F_37 ( V_2 -> V_43 ) )
return;
V_35 = F_5 ( V_2 ) ;
V_11 = F_1 ( V_2 ) ;
F_6 ( & V_11 -> V_56 ) ;
while ( ( V_10 = F_16 ( V_11 ) ) != NULL )
F_58 ( V_10 ) ;
F_21 ( V_11 -> V_23 ) ;
F_7 ( & V_11 -> V_56 ) ;
V_51 = V_11 -> V_28 . V_64 * sizeof( struct V_9 ) +
F_34 (unsigned int, info->attr.mq_maxmsg, MQ_PRIO_MAX) *
sizeof( struct V_15 ) ;
V_50 = V_51 + ( V_11 -> V_28 . V_64 *
V_11 -> V_28 . V_67 ) ;
V_62 = V_11 -> V_62 ;
if ( V_62 ) {
F_6 ( & V_8 ) ;
V_62 -> V_50 -= V_50 ;
if ( V_35 )
V_35 -> V_109 -- ;
F_7 ( & V_8 ) ;
F_59 ( V_62 ) ;
}
if ( V_35 )
F_60 ( V_35 ) ;
}
static int F_61 ( struct V_2 * V_110 , struct V_91 * V_91 ,
T_1 V_36 , bool V_111 )
{
struct V_2 * V_2 ;
struct V_37 * V_28 = V_91 -> V_112 ;
int error ;
struct V_4 * V_35 ;
F_6 ( & V_8 ) ;
V_35 = F_3 ( V_110 ) ;
if ( ! V_35 ) {
error = - V_113 ;
goto V_114;
}
if ( V_35 -> V_109 >= V_115 ||
( V_35 -> V_109 >= V_35 -> V_116 &&
! F_62 ( V_117 ) ) ) {
error = - V_118 ;
goto V_114;
}
V_35 -> V_109 ++ ;
F_7 ( & V_8 ) ;
V_2 = F_24 ( V_110 -> V_5 , V_35 , V_36 , V_28 ) ;
if ( F_42 ( V_2 ) ) {
error = F_43 ( V_2 ) ;
F_6 ( & V_8 ) ;
V_35 -> V_109 -- ;
goto V_114;
}
F_60 ( V_35 ) ;
V_110 -> V_54 += V_73 ;
V_110 -> V_47 = V_110 -> V_46 = V_110 -> V_48 = V_49 ;
F_63 ( V_91 , V_2 ) ;
F_64 ( V_91 ) ;
return 0 ;
V_114:
F_7 ( & V_8 ) ;
if ( V_35 )
F_60 ( V_35 ) ;
return error ;
}
static int F_65 ( struct V_2 * V_110 , struct V_91 * V_91 )
{
struct V_2 * V_2 = V_91 -> V_119 ;
V_110 -> V_47 = V_110 -> V_46 = V_110 -> V_48 = V_49 ;
V_110 -> V_54 -= V_73 ;
F_66 ( V_2 ) ;
F_67 ( V_91 ) ;
return 0 ;
}
static T_2 F_68 ( struct V_120 * V_121 , char T_3 * V_122 ,
T_4 V_123 , T_5 * V_124 )
{
struct V_1 * V_11 = F_1 ( F_69 ( V_121 ) ) ;
char V_125 [ V_55 ] ;
T_2 V_40 ;
F_6 ( & V_11 -> V_56 ) ;
snprintf ( V_125 , sizeof( V_125 ) ,
L_6 ,
V_11 -> V_27 ,
V_11 -> V_60 ? V_11 -> V_126 . V_127 : 0 ,
( V_11 -> V_60 &&
V_11 -> V_126 . V_127 == V_128 ) ?
V_11 -> V_126 . V_129 : 0 ,
F_70 ( V_11 -> V_60 ) ) ;
F_7 ( & V_11 -> V_56 ) ;
V_125 [ sizeof( V_125 ) - 1 ] = '\0' ;
V_40 = F_71 ( V_122 , V_123 , V_124 , V_125 ,
strlen ( V_125 ) ) ;
if ( V_40 <= 0 )
return V_40 ;
F_69 ( V_121 ) -> V_48 = F_69 ( V_121 ) -> V_47 = V_49 ;
return V_40 ;
}
static int F_72 ( struct V_120 * V_121 , T_6 V_130 )
{
struct V_1 * V_11 = F_1 ( F_69 ( V_121 ) ) ;
F_6 ( & V_11 -> V_56 ) ;
if ( F_73 ( V_97 ) == V_11 -> V_60 )
F_74 ( V_11 ) ;
F_7 ( & V_11 -> V_56 ) ;
return 0 ;
}
static unsigned int F_75 ( struct V_120 * V_121 , struct V_131 * V_132 )
{
struct V_1 * V_11 = F_1 ( F_69 ( V_121 ) ) ;
int V_133 = 0 ;
F_76 ( V_121 , & V_11 -> V_57 , V_132 ) ;
F_6 ( & V_11 -> V_56 ) ;
if ( V_11 -> V_28 . V_29 )
V_133 = V_134 | V_135 ;
if ( V_11 -> V_28 . V_29 < V_11 -> V_28 . V_64 )
V_133 |= V_136 | V_137 ;
F_7 ( & V_11 -> V_56 ) ;
return V_133 ;
}
static void F_77 ( struct V_1 * V_11 , int V_138 ,
struct V_139 * V_140 )
{
struct V_139 * V_141 ;
V_140 -> V_142 = V_97 ;
F_78 (walk, &info->e_wait_q[sr].list, list) {
if ( V_141 -> V_142 -> V_143 <= V_97 -> V_143 ) {
F_15 ( & V_140 -> V_59 , & V_141 -> V_59 ) ;
return;
}
}
F_15 ( & V_140 -> V_59 , & V_11 -> V_58 [ V_138 ] . V_59 ) ;
}
static int F_79 ( struct V_1 * V_11 , int V_138 ,
T_7 * V_144 , struct V_139 * V_140 )
{
int V_133 ;
signed long time ;
F_77 ( V_11 , V_138 , V_140 ) ;
for (; ; ) {
F_80 ( V_145 ) ;
F_7 ( & V_11 -> V_56 ) ;
time = F_81 ( V_144 , 0 ,
V_146 , V_147 ) ;
while ( V_140 -> V_148 == V_149 )
F_82 () ;
if ( V_140 -> V_148 == V_150 ) {
V_133 = 0 ;
goto V_151;
}
F_6 ( & V_11 -> V_56 ) ;
if ( V_140 -> V_148 == V_150 ) {
V_133 = 0 ;
goto V_114;
}
if ( F_83 ( V_97 ) ) {
V_133 = - V_152 ;
break;
}
if ( time == 0 ) {
V_133 = - V_153 ;
break;
}
}
F_23 ( & V_140 -> V_59 ) ;
V_114:
F_7 ( & V_11 -> V_56 ) ;
V_151:
return V_133 ;
}
static struct V_139 * F_84 (
struct V_1 * V_11 , int V_138 )
{
struct V_154 * V_155 ;
V_155 = V_11 -> V_58 [ V_138 ] . V_59 . V_156 ;
if ( V_155 == & V_11 -> V_58 [ V_138 ] . V_59 )
return NULL ;
return F_85 ( V_155 , struct V_139 , V_59 ) ;
}
static inline void F_86 ( struct V_157 * V_158 , char V_159 )
{
( ( char * ) V_158 -> V_77 ) [ V_160 - 1 ] = V_159 ;
}
static void F_87 ( struct V_1 * V_11 )
{
if ( V_11 -> V_60 &&
V_11 -> V_28 . V_29 == 1 ) {
struct V_161 V_162 ;
switch ( V_11 -> V_126 . V_127 ) {
case V_163 :
break;
case V_128 :
V_162 . V_164 = V_11 -> V_126 . V_129 ;
V_162 . V_165 = 0 ;
V_162 . V_166 = V_167 ;
V_162 . V_168 = V_11 -> V_126 . V_169 ;
F_88 () ;
V_162 . V_170 = F_89 ( V_97 ,
F_90 ( V_11 -> V_60 ) ) ;
V_162 . V_171 = F_91 ( V_11 -> V_61 , F_92 () ) ;
F_93 () ;
F_94 ( V_11 -> V_126 . V_129 ,
& V_162 , V_11 -> V_60 ) ;
break;
case V_172 :
F_86 ( V_11 -> V_173 , V_174 ) ;
F_95 ( V_11 -> V_175 , V_11 -> V_173 ) ;
break;
}
F_96 ( V_11 -> V_60 ) ;
F_97 ( V_11 -> V_61 ) ;
V_11 -> V_60 = NULL ;
V_11 -> V_61 = NULL ;
}
F_98 ( & V_11 -> V_57 ) ;
}
static int F_99 ( const struct V_176 T_3 * V_177 ,
T_7 * V_178 , struct V_176 * V_179 )
{
if ( F_100 ( V_179 , V_177 , sizeof( struct V_176 ) ) )
return - V_180 ;
if ( ! F_101 ( V_179 ) )
return - V_181 ;
* V_178 = F_102 ( * V_179 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_11 )
{
if ( V_11 -> V_60 != NULL &&
V_11 -> V_126 . V_127 == V_172 ) {
F_86 ( V_11 -> V_173 , V_182 ) ;
F_95 ( V_11 -> V_175 , V_11 -> V_173 ) ;
}
F_96 ( V_11 -> V_60 ) ;
F_97 ( V_11 -> V_61 ) ;
V_11 -> V_60 = NULL ;
V_11 -> V_61 = NULL ;
}
static int F_103 ( struct V_4 * V_35 , struct V_37 * V_28 )
{
int V_51 ;
unsigned long V_183 ;
if ( V_28 -> V_64 <= 0 || V_28 -> V_67 <= 0 )
return - V_181 ;
if ( F_62 ( V_117 ) ) {
if ( V_28 -> V_64 > V_184 ||
V_28 -> V_67 > V_185 )
return - V_181 ;
} else {
if ( V_28 -> V_64 > V_35 -> V_65 ||
V_28 -> V_67 > V_35 -> V_68 )
return - V_181 ;
}
if ( V_28 -> V_67 > V_186 / V_28 -> V_64 )
return - V_187 ;
V_51 = V_28 -> V_64 * sizeof( struct V_9 ) +
F_34 (unsigned int, attr->mq_maxmsg, MQ_PRIO_MAX) *
sizeof( struct V_15 ) ;
V_183 = V_28 -> V_64 * V_28 -> V_67 ;
if ( V_183 + V_51 < V_183 )
return - V_187 ;
return 0 ;
}
static struct V_120 * F_104 ( struct V_4 * V_35 , struct V_2 * V_110 ,
struct V_188 * V_188 , int V_189 , T_1 V_36 ,
struct V_37 * V_28 )
{
const struct V_190 * V_190 = F_105 () ;
int V_40 ;
if ( V_28 ) {
V_40 = F_103 ( V_35 , V_28 ) ;
if ( V_40 )
return F_40 ( V_40 ) ;
V_188 -> V_91 -> V_112 = V_28 ;
} else {
struct V_37 V_191 ;
V_191 . V_64 = F_33 ( V_35 -> V_65 ,
V_35 -> V_66 ) ;
V_191 . V_67 = F_33 ( V_35 -> V_68 ,
V_35 -> V_69 ) ;
V_40 = F_103 ( V_35 , & V_191 ) ;
if ( V_40 )
return F_40 ( V_40 ) ;
}
V_36 &= ~ F_106 () ;
V_40 = F_107 ( V_110 , V_188 -> V_91 , V_36 , true ) ;
V_188 -> V_91 -> V_112 = NULL ;
if ( V_40 )
return F_40 ( V_40 ) ;
return F_108 ( V_188 , V_189 , V_190 ) ;
}
static struct V_120 * F_109 ( struct V_188 * V_188 , int V_189 )
{
static const int V_192 [ V_193 ] = { V_194 , V_195 ,
V_194 | V_195 } ;
int V_196 ;
if ( ( V_189 & V_193 ) == ( V_197 | V_198 ) )
return F_40 ( - V_181 ) ;
V_196 = V_192 [ V_189 & V_193 ] ;
if ( F_110 ( V_188 -> V_91 -> V_119 , V_196 ) )
return F_40 ( - V_113 ) ;
return F_108 ( V_188 , V_189 , F_105 () ) ;
}
static inline void F_111 ( struct V_1 * V_11 ,
struct V_9 * V_199 ,
struct V_139 * V_200 )
{
V_200 -> V_10 = V_199 ;
F_23 ( & V_200 -> V_59 ) ;
V_200 -> V_148 = V_149 ;
F_112 ( V_200 -> V_142 ) ;
F_113 () ;
V_200 -> V_148 = V_150 ;
}
static inline void F_114 ( struct V_1 * V_11 )
{
struct V_139 * V_201 = F_84 ( V_11 , V_202 ) ;
if ( ! V_201 ) {
F_115 ( & V_11 -> V_57 ) ;
return;
}
if ( F_8 ( V_201 -> V_10 , V_11 ) )
return;
F_23 ( & V_201 -> V_59 ) ;
V_201 -> V_148 = V_149 ;
F_112 ( V_201 -> V_142 ) ;
F_113 () ;
V_201 -> V_148 = V_150 ;
}
int F_116 ( struct V_4 * V_7 )
{
V_7 -> V_109 = 0 ;
V_7 -> V_116 = V_203 ;
V_7 -> V_65 = V_204 ;
V_7 -> V_68 = V_205 ;
V_7 -> V_66 = V_206 ;
V_7 -> V_69 = V_207 ;
V_7 -> V_208 = F_117 ( & V_209 , V_7 ) ;
if ( F_42 ( V_7 -> V_208 ) ) {
int V_41 = F_43 ( V_7 -> V_208 ) ;
V_7 -> V_208 = NULL ;
return V_41 ;
}
return 0 ;
}
void F_118 ( struct V_4 * V_7 )
{
V_7 -> V_208 -> V_210 -> V_6 = NULL ;
}
void F_119 ( struct V_4 * V_7 )
{
F_120 ( V_7 -> V_208 ) ;
}
static int T_8 F_121 ( void )
{
int error ;
V_104 = F_122 ( L_7 ,
sizeof( struct V_1 ) , 0 ,
V_211 , F_48 ) ;
if ( V_104 == NULL )
return - V_25 ;
V_212 = F_123 () ;
error = F_124 ( & V_209 ) ;
if ( error )
goto V_213;
F_31 ( & V_8 ) ;
error = F_116 ( & V_214 ) ;
if ( error )
goto V_215;
return 0 ;
V_215:
F_125 ( & V_209 ) ;
V_213:
if ( V_212 )
F_126 ( V_212 ) ;
F_127 ( V_104 ) ;
return error ;
}
