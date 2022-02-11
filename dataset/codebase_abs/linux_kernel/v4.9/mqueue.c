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
}
V_16 -> V_18 = V_10 -> V_19 ;
F_13 ( & V_16 -> V_12 , V_14 , V_13 ) ;
F_14 ( & V_16 -> V_12 , & V_11 -> V_17 ) ;
V_20:
V_11 -> V_27 . V_28 ++ ;
V_11 -> V_29 += V_10 -> V_30 ;
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
if ( V_11 -> V_27 . V_28 ) {
F_17 ( L_1
L_2
L_3 ) ;
V_11 -> V_27 . V_28 = 0 ;
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
F_21 ( V_16 ) ;
} else {
V_11 -> V_23 = V_16 ;
}
}
}
V_11 -> V_27 . V_28 -- ;
V_11 -> V_29 -= V_10 -> V_30 ;
return V_10 ;
}
static struct V_2 * F_24 ( struct V_33 * V_34 ,
struct V_4 * V_35 , T_1 V_36 ,
struct V_37 * V_27 )
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
V_2 -> V_46 = V_2 -> V_47 = V_2 -> V_48 = F_30 ( V_2 ) ;
if ( F_31 ( V_36 ) ) {
struct V_1 * V_11 ;
unsigned long V_49 , V_50 ;
V_2 -> V_51 = & V_52 ;
V_2 -> V_53 = V_54 ;
V_11 = F_1 ( V_2 ) ;
F_32 ( & V_11 -> V_55 ) ;
F_33 ( & V_11 -> V_56 ) ;
F_12 ( & V_11 -> V_57 [ 0 ] . V_58 ) ;
F_12 ( & V_11 -> V_57 [ 1 ] . V_58 ) ;
V_11 -> V_59 = NULL ;
V_11 -> V_60 = NULL ;
V_11 -> V_29 = 0 ;
V_11 -> V_61 = NULL ;
V_11 -> V_17 = V_62 ;
V_11 -> V_23 = NULL ;
memset ( & V_11 -> V_27 , 0 , sizeof( V_11 -> V_27 ) ) ;
V_11 -> V_27 . V_63 = F_34 ( V_35 -> V_64 ,
V_35 -> V_65 ) ;
V_11 -> V_27 . V_66 = F_34 ( V_35 -> V_67 ,
V_35 -> V_68 ) ;
if ( V_27 ) {
V_11 -> V_27 . V_63 = V_27 -> V_63 ;
V_11 -> V_27 . V_66 = V_27 -> V_66 ;
}
V_50 = V_11 -> V_27 . V_63 * sizeof( struct V_9 ) +
F_35 (unsigned int, info->attr.mq_maxmsg, MQ_PRIO_MAX) *
sizeof( struct V_15 ) ;
V_49 = V_50 + ( V_11 -> V_27 . V_63 *
V_11 -> V_27 . V_66 ) ;
F_6 ( & V_8 ) ;
if ( V_39 -> V_49 + V_49 < V_39 -> V_49 ||
V_39 -> V_49 + V_49 > F_36 ( V_69 ) ) {
F_7 ( & V_8 ) ;
V_40 = - V_70 ;
goto V_71;
}
V_39 -> V_49 += V_49 ;
F_7 ( & V_8 ) ;
V_11 -> V_61 = F_37 ( V_39 ) ;
} else if ( F_38 ( V_36 ) ) {
F_39 ( V_2 ) ;
V_2 -> V_53 = 2 * V_72 ;
V_2 -> V_73 = & V_74 ;
V_2 -> V_51 = & V_75 ;
}
return V_2 ;
V_71:
F_40 ( V_2 ) ;
V_41:
return F_41 ( V_40 ) ;
}
static int F_42 ( struct V_33 * V_34 , void * V_76 , int V_77 )
{
struct V_2 * V_2 ;
struct V_4 * V_7 = V_34 -> V_6 ;
V_34 -> V_78 |= V_79 | V_80 ;
V_34 -> V_81 = V_82 ;
V_34 -> V_83 = V_84 ;
V_34 -> V_85 = V_86 ;
V_34 -> V_87 = & V_88 ;
V_2 = F_24 ( V_34 , V_7 , V_89 | V_90 | V_91 , NULL ) ;
if ( F_43 ( V_2 ) )
return F_44 ( V_2 ) ;
V_34 -> V_92 = F_45 ( V_2 ) ;
if ( ! V_34 -> V_92 )
return - V_25 ;
return 0 ;
}
static struct V_93 * F_46 ( struct V_94 * V_95 ,
int V_96 , const char * V_97 ,
void * V_76 )
{
struct V_4 * V_7 ;
if ( V_96 & V_98 ) {
V_7 = V_76 ;
V_76 = NULL ;
} else {
V_7 = V_99 -> V_100 -> V_35 ;
}
return F_47 ( V_95 , V_96 , V_76 , V_7 , V_7 -> V_101 , F_42 ) ;
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
struct V_38 * V_61 ;
unsigned long V_49 , V_50 ;
struct V_4 * V_35 ;
struct V_9 * V_10 ;
F_57 ( V_2 ) ;
if ( F_38 ( V_2 -> V_43 ) )
return;
V_35 = F_5 ( V_2 ) ;
V_11 = F_1 ( V_2 ) ;
F_6 ( & V_11 -> V_55 ) ;
while ( ( V_10 = F_16 ( V_11 ) ) != NULL )
F_58 ( V_10 ) ;
F_21 ( V_11 -> V_23 ) ;
F_7 ( & V_11 -> V_55 ) ;
V_50 = V_11 -> V_27 . V_63 * sizeof( struct V_9 ) +
F_35 (unsigned int, info->attr.mq_maxmsg, MQ_PRIO_MAX) *
sizeof( struct V_15 ) ;
V_49 = V_50 + ( V_11 -> V_27 . V_63 *
V_11 -> V_27 . V_66 ) ;
V_61 = V_11 -> V_61 ;
if ( V_61 ) {
F_6 ( & V_8 ) ;
V_61 -> V_49 -= V_49 ;
if ( V_35 )
V_35 -> V_109 -- ;
F_7 ( & V_8 ) ;
F_59 ( V_61 ) ;
}
if ( V_35 )
F_60 ( V_35 ) ;
}
static int F_61 ( struct V_2 * V_110 , struct V_93 * V_93 ,
T_1 V_36 , bool V_111 )
{
struct V_2 * V_2 ;
struct V_37 * V_27 = V_93 -> V_112 ;
int error ;
struct V_4 * V_35 ;
F_6 ( & V_8 ) ;
V_35 = F_3 ( V_110 ) ;
if ( ! V_35 ) {
error = - V_113 ;
goto V_114;
}
if ( V_35 -> V_109 >= V_35 -> V_115 &&
! F_62 ( V_116 ) ) {
error = - V_117 ;
goto V_114;
}
V_35 -> V_109 ++ ;
F_7 ( & V_8 ) ;
V_2 = F_24 ( V_110 -> V_5 , V_35 , V_36 , V_27 ) ;
if ( F_43 ( V_2 ) ) {
error = F_44 ( V_2 ) ;
F_6 ( & V_8 ) ;
V_35 -> V_109 -- ;
goto V_114;
}
F_60 ( V_35 ) ;
V_110 -> V_53 += V_72 ;
V_110 -> V_47 = V_110 -> V_46 = V_110 -> V_48 = F_30 ( V_110 ) ;
F_63 ( V_93 , V_2 ) ;
F_64 ( V_93 ) ;
return 0 ;
V_114:
F_7 ( & V_8 ) ;
if ( V_35 )
F_60 ( V_35 ) ;
return error ;
}
static int F_65 ( struct V_2 * V_110 , struct V_93 * V_93 )
{
struct V_2 * V_2 = F_66 ( V_93 ) ;
V_110 -> V_47 = V_110 -> V_46 = V_110 -> V_48 = F_30 ( V_110 ) ;
V_110 -> V_53 -= V_72 ;
F_67 ( V_2 ) ;
F_68 ( V_93 ) ;
return 0 ;
}
static T_2 F_69 ( struct V_118 * V_119 , char T_3 * V_120 ,
T_4 V_121 , T_5 * V_122 )
{
struct V_1 * V_11 = F_1 ( F_70 ( V_119 ) ) ;
char V_123 [ V_54 ] ;
T_2 V_40 ;
F_6 ( & V_11 -> V_55 ) ;
snprintf ( V_123 , sizeof( V_123 ) ,
L_6 ,
V_11 -> V_29 ,
V_11 -> V_59 ? V_11 -> V_124 . V_125 : 0 ,
( V_11 -> V_59 &&
V_11 -> V_124 . V_125 == V_126 ) ?
V_11 -> V_124 . V_127 : 0 ,
F_71 ( V_11 -> V_59 ) ) ;
F_7 ( & V_11 -> V_55 ) ;
V_123 [ sizeof( V_123 ) - 1 ] = '\0' ;
V_40 = F_72 ( V_120 , V_121 , V_122 , V_123 ,
strlen ( V_123 ) ) ;
if ( V_40 <= 0 )
return V_40 ;
F_70 ( V_119 ) -> V_48 = F_70 ( V_119 ) -> V_47 = F_30 ( F_70 ( V_119 ) ) ;
return V_40 ;
}
static int F_73 ( struct V_118 * V_119 , T_6 V_128 )
{
struct V_1 * V_11 = F_1 ( F_70 ( V_119 ) ) ;
F_6 ( & V_11 -> V_55 ) ;
if ( F_74 ( V_99 ) == V_11 -> V_59 )
F_75 ( V_11 ) ;
F_7 ( & V_11 -> V_55 ) ;
return 0 ;
}
static unsigned int F_76 ( struct V_118 * V_119 , struct V_129 * V_130 )
{
struct V_1 * V_11 = F_1 ( F_70 ( V_119 ) ) ;
int V_131 = 0 ;
F_77 ( V_119 , & V_11 -> V_56 , V_130 ) ;
F_6 ( & V_11 -> V_55 ) ;
if ( V_11 -> V_27 . V_28 )
V_131 = V_132 | V_133 ;
if ( V_11 -> V_27 . V_28 < V_11 -> V_27 . V_63 )
V_131 |= V_134 | V_135 ;
F_7 ( & V_11 -> V_55 ) ;
return V_131 ;
}
static void F_78 ( struct V_1 * V_11 , int V_136 ,
struct V_137 * V_138 )
{
struct V_137 * V_139 ;
V_138 -> V_140 = V_99 ;
F_79 (walk, &info->e_wait_q[sr].list, list) {
if ( V_139 -> V_140 -> V_141 <= V_99 -> V_141 ) {
F_15 ( & V_138 -> V_58 , & V_139 -> V_58 ) ;
return;
}
}
F_15 ( & V_138 -> V_58 , & V_11 -> V_57 [ V_136 ] . V_58 ) ;
}
static int F_80 ( struct V_1 * V_11 , int V_136 ,
T_7 * V_142 , struct V_137 * V_138 )
{
int V_131 ;
signed long time ;
F_78 ( V_11 , V_136 , V_138 ) ;
for (; ; ) {
F_81 ( V_143 ) ;
F_7 ( & V_11 -> V_55 ) ;
time = F_82 ( V_142 , 0 ,
V_144 , V_145 ) ;
if ( V_138 -> V_146 == V_147 ) {
V_131 = 0 ;
goto V_148;
}
F_6 ( & V_11 -> V_55 ) ;
if ( V_138 -> V_146 == V_147 ) {
V_131 = 0 ;
goto V_114;
}
if ( F_83 ( V_99 ) ) {
V_131 = - V_149 ;
break;
}
if ( time == 0 ) {
V_131 = - V_150 ;
break;
}
}
F_23 ( & V_138 -> V_58 ) ;
V_114:
F_7 ( & V_11 -> V_55 ) ;
V_148:
return V_131 ;
}
static struct V_137 * F_84 (
struct V_1 * V_11 , int V_136 )
{
struct V_151 * V_152 ;
V_152 = V_11 -> V_57 [ V_136 ] . V_58 . V_153 ;
if ( V_152 == & V_11 -> V_57 [ V_136 ] . V_58 )
return NULL ;
return F_85 ( V_152 , struct V_137 , V_58 ) ;
}
static inline void F_86 ( struct V_154 * V_155 , char V_156 )
{
( ( char * ) V_155 -> V_76 ) [ V_157 - 1 ] = V_156 ;
}
static void F_87 ( struct V_1 * V_11 )
{
if ( V_11 -> V_59 &&
V_11 -> V_27 . V_28 == 1 ) {
struct V_158 V_159 ;
switch ( V_11 -> V_124 . V_125 ) {
case V_160 :
break;
case V_126 :
V_159 . V_161 = V_11 -> V_124 . V_127 ;
V_159 . V_162 = 0 ;
V_159 . V_163 = V_164 ;
V_159 . V_165 = V_11 -> V_124 . V_166 ;
F_88 () ;
V_159 . V_167 = F_89 ( V_99 ,
F_90 ( V_11 -> V_59 ) ) ;
V_159 . V_168 = F_91 ( V_11 -> V_60 , F_92 () ) ;
F_93 () ;
F_94 ( V_11 -> V_124 . V_127 ,
& V_159 , V_11 -> V_59 ) ;
break;
case V_169 :
F_86 ( V_11 -> V_170 , V_171 ) ;
F_95 ( V_11 -> V_172 , V_11 -> V_170 ) ;
break;
}
F_96 ( V_11 -> V_59 ) ;
F_97 ( V_11 -> V_60 ) ;
V_11 -> V_59 = NULL ;
V_11 -> V_60 = NULL ;
}
F_98 ( & V_11 -> V_56 ) ;
}
static int F_99 ( const struct V_173 T_3 * V_174 ,
T_7 * V_175 , struct V_173 * V_176 )
{
if ( F_100 ( V_176 , V_174 , sizeof( struct V_173 ) ) )
return - V_177 ;
if ( ! F_101 ( V_176 ) )
return - V_178 ;
* V_175 = F_102 ( * V_176 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_11 )
{
if ( V_11 -> V_59 != NULL &&
V_11 -> V_124 . V_125 == V_169 ) {
F_86 ( V_11 -> V_170 , V_179 ) ;
F_95 ( V_11 -> V_172 , V_11 -> V_170 ) ;
}
F_96 ( V_11 -> V_59 ) ;
F_97 ( V_11 -> V_60 ) ;
V_11 -> V_59 = NULL ;
V_11 -> V_60 = NULL ;
}
static int F_103 ( struct V_4 * V_35 , struct V_37 * V_27 )
{
int V_50 ;
unsigned long V_180 ;
if ( V_27 -> V_63 <= 0 || V_27 -> V_66 <= 0 )
return - V_178 ;
if ( F_62 ( V_116 ) ) {
if ( V_27 -> V_63 > V_181 ||
V_27 -> V_66 > V_182 )
return - V_178 ;
} else {
if ( V_27 -> V_63 > V_35 -> V_64 ||
V_27 -> V_66 > V_35 -> V_67 )
return - V_178 ;
}
if ( V_27 -> V_66 > V_183 / V_27 -> V_63 )
return - V_184 ;
V_50 = V_27 -> V_63 * sizeof( struct V_9 ) +
F_35 (unsigned int, attr->mq_maxmsg, MQ_PRIO_MAX) *
sizeof( struct V_15 ) ;
V_180 = V_27 -> V_63 * V_27 -> V_66 ;
if ( V_180 + V_50 < V_180 )
return - V_184 ;
return 0 ;
}
static struct V_118 * F_104 ( struct V_4 * V_35 , struct V_2 * V_110 ,
struct V_185 * V_185 , int V_186 , T_1 V_36 ,
struct V_37 * V_27 )
{
const struct V_187 * V_187 = F_105 () ;
int V_40 ;
if ( V_27 ) {
V_40 = F_103 ( V_35 , V_27 ) ;
if ( V_40 )
return F_41 ( V_40 ) ;
V_185 -> V_93 -> V_112 = V_27 ;
} else {
struct V_37 V_188 ;
V_188 . V_63 = F_34 ( V_35 -> V_64 ,
V_35 -> V_65 ) ;
V_188 . V_66 = F_34 ( V_35 -> V_67 ,
V_35 -> V_68 ) ;
V_40 = F_103 ( V_35 , & V_188 ) ;
if ( V_40 )
return F_41 ( V_40 ) ;
}
V_36 &= ~ F_106 () ;
V_40 = F_107 ( V_110 , V_185 -> V_93 , V_36 , true ) ;
V_185 -> V_93 -> V_112 = NULL ;
if ( V_40 )
return F_41 ( V_40 ) ;
return F_108 ( V_185 , V_186 , V_187 ) ;
}
static struct V_118 * F_109 ( struct V_185 * V_185 , int V_186 )
{
static const int V_189 [ V_190 ] = { V_191 , V_192 ,
V_191 | V_192 } ;
int V_193 ;
if ( ( V_186 & V_190 ) == ( V_194 | V_195 ) )
return F_41 ( - V_178 ) ;
V_193 = V_189 [ V_186 & V_190 ] ;
if ( F_110 ( F_66 ( V_185 -> V_93 ) , V_193 ) )
return F_41 ( - V_113 ) ;
return F_108 ( V_185 , V_186 , F_105 () ) ;
}
static inline void F_111 ( struct V_196 * V_197 ,
struct V_1 * V_11 ,
struct V_9 * V_198 ,
struct V_137 * V_199 )
{
V_199 -> V_10 = V_198 ;
F_23 ( & V_199 -> V_58 ) ;
F_112 ( V_197 , V_199 -> V_140 ) ;
V_199 -> V_146 = V_147 ;
}
static inline void F_113 ( struct V_196 * V_197 ,
struct V_1 * V_11 )
{
struct V_137 * V_200 = F_84 ( V_11 , V_201 ) ;
if ( ! V_200 ) {
F_114 ( & V_11 -> V_56 ) ;
return;
}
if ( F_8 ( V_200 -> V_10 , V_11 ) )
return;
F_23 ( & V_200 -> V_58 ) ;
F_112 ( V_197 , V_200 -> V_140 ) ;
V_200 -> V_146 = V_147 ;
}
int F_115 ( struct V_4 * V_7 )
{
V_7 -> V_109 = 0 ;
V_7 -> V_115 = V_202 ;
V_7 -> V_64 = V_203 ;
V_7 -> V_67 = V_204 ;
V_7 -> V_65 = V_205 ;
V_7 -> V_68 = V_206 ;
V_7 -> V_207 = F_116 ( & V_208 , V_7 ) ;
if ( F_43 ( V_7 -> V_207 ) ) {
int V_41 = F_44 ( V_7 -> V_207 ) ;
V_7 -> V_207 = NULL ;
return V_41 ;
}
return 0 ;
}
void F_117 ( struct V_4 * V_7 )
{
V_7 -> V_207 -> V_209 -> V_6 = NULL ;
}
void F_118 ( struct V_4 * V_7 )
{
F_119 ( V_7 -> V_207 ) ;
}
static int T_8 F_120 ( void )
{
int error ;
V_104 = F_121 ( L_7 ,
sizeof( struct V_1 ) , 0 ,
V_210 | V_211 , F_48 ) ;
if ( V_104 == NULL )
return - V_25 ;
V_212 = F_122 () ;
error = F_123 ( & V_208 ) ;
if ( error )
goto V_213;
F_32 ( & V_8 ) ;
error = F_115 ( & V_214 ) ;
if ( error )
goto V_215;
return 0 ;
V_215:
F_124 ( & V_208 ) ;
V_213:
if ( V_212 )
F_125 ( V_212 ) ;
F_126 ( V_104 ) ;
return error ;
}
