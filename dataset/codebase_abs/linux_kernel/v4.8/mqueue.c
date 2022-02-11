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
V_11 -> V_29 = 0 ;
V_11 -> V_62 = NULL ;
V_11 -> V_17 = V_63 ;
V_11 -> V_23 = NULL ;
memset ( & V_11 -> V_27 , 0 , sizeof( V_11 -> V_27 ) ) ;
V_11 -> V_27 . V_64 = F_33 ( V_35 -> V_65 ,
V_35 -> V_66 ) ;
V_11 -> V_27 . V_67 = F_33 ( V_35 -> V_68 ,
V_35 -> V_69 ) ;
if ( V_27 ) {
V_11 -> V_27 . V_64 = V_27 -> V_64 ;
V_11 -> V_27 . V_67 = V_27 -> V_67 ;
}
V_51 = V_11 -> V_27 . V_64 * sizeof( struct V_9 ) +
F_34 (unsigned int, info->attr.mq_maxmsg, MQ_PRIO_MAX) *
sizeof( struct V_15 ) ;
V_50 = V_51 + ( V_11 -> V_27 . V_64 *
V_11 -> V_27 . V_67 ) ;
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
struct V_4 * V_7 = V_34 -> V_6 ;
V_34 -> V_79 |= V_80 | V_81 ;
V_34 -> V_82 = V_83 ;
V_34 -> V_84 = V_85 ;
V_34 -> V_86 = V_87 ;
V_34 -> V_88 = & V_89 ;
V_2 = F_24 ( V_34 , V_7 , V_90 | V_91 | V_92 , NULL ) ;
if ( F_42 ( V_2 ) )
return F_43 ( V_2 ) ;
V_34 -> V_93 = F_44 ( V_2 ) ;
if ( ! V_34 -> V_93 )
return - V_25 ;
return 0 ;
}
static struct V_94 * F_45 ( struct V_95 * V_96 ,
int V_97 , const char * V_98 ,
void * V_77 )
{
struct V_4 * V_7 ;
if ( V_97 & V_99 ) {
V_7 = V_77 ;
V_77 = NULL ;
} else {
V_7 = V_100 -> V_101 -> V_35 ;
}
return F_46 ( V_96 , V_97 , V_77 , V_7 , V_7 -> V_102 , F_41 ) ;
}
static void F_47 ( void * V_103 )
{
struct V_1 * V_13 = (struct V_1 * ) V_103 ;
F_48 ( & V_13 -> V_3 ) ;
}
static struct V_2 * F_49 ( struct V_33 * V_34 )
{
struct V_1 * V_104 ;
V_104 = F_50 ( V_105 , V_106 ) ;
if ( ! V_104 )
return NULL ;
return & V_104 -> V_3 ;
}
static void F_51 ( struct V_107 * V_108 )
{
struct V_2 * V_2 = F_2 ( V_108 , struct V_2 , V_109 ) ;
F_52 ( V_105 , F_1 ( V_2 ) ) ;
}
static void F_53 ( struct V_2 * V_2 )
{
F_54 ( & V_2 -> V_109 , F_51 ) ;
}
static void F_55 ( struct V_2 * V_2 )
{
struct V_1 * V_11 ;
struct V_38 * V_62 ;
unsigned long V_50 , V_51 ;
struct V_4 * V_35 ;
struct V_9 * V_10 ;
F_56 ( V_2 ) ;
if ( F_37 ( V_2 -> V_43 ) )
return;
V_35 = F_5 ( V_2 ) ;
V_11 = F_1 ( V_2 ) ;
F_6 ( & V_11 -> V_56 ) ;
while ( ( V_10 = F_16 ( V_11 ) ) != NULL )
F_57 ( V_10 ) ;
F_21 ( V_11 -> V_23 ) ;
F_7 ( & V_11 -> V_56 ) ;
V_51 = V_11 -> V_27 . V_64 * sizeof( struct V_9 ) +
F_34 (unsigned int, info->attr.mq_maxmsg, MQ_PRIO_MAX) *
sizeof( struct V_15 ) ;
V_50 = V_51 + ( V_11 -> V_27 . V_64 *
V_11 -> V_27 . V_67 ) ;
V_62 = V_11 -> V_62 ;
if ( V_62 ) {
F_6 ( & V_8 ) ;
V_62 -> V_50 -= V_50 ;
if ( V_35 )
V_35 -> V_110 -- ;
F_7 ( & V_8 ) ;
F_58 ( V_62 ) ;
}
if ( V_35 )
F_59 ( V_35 ) ;
}
static int F_60 ( struct V_2 * V_111 , struct V_94 * V_94 ,
T_1 V_36 , bool V_112 )
{
struct V_2 * V_2 ;
struct V_37 * V_27 = V_94 -> V_113 ;
int error ;
struct V_4 * V_35 ;
F_6 ( & V_8 ) ;
V_35 = F_3 ( V_111 ) ;
if ( ! V_35 ) {
error = - V_114 ;
goto V_115;
}
if ( V_35 -> V_110 >= V_35 -> V_116 &&
! F_61 ( V_117 ) ) {
error = - V_118 ;
goto V_115;
}
V_35 -> V_110 ++ ;
F_7 ( & V_8 ) ;
V_2 = F_24 ( V_111 -> V_5 , V_35 , V_36 , V_27 ) ;
if ( F_42 ( V_2 ) ) {
error = F_43 ( V_2 ) ;
F_6 ( & V_8 ) ;
V_35 -> V_110 -- ;
goto V_115;
}
F_59 ( V_35 ) ;
V_111 -> V_54 += V_73 ;
V_111 -> V_47 = V_111 -> V_46 = V_111 -> V_48 = V_49 ;
F_62 ( V_94 , V_2 ) ;
F_63 ( V_94 ) ;
return 0 ;
V_115:
F_7 ( & V_8 ) ;
if ( V_35 )
F_59 ( V_35 ) ;
return error ;
}
static int F_64 ( struct V_2 * V_111 , struct V_94 * V_94 )
{
struct V_2 * V_2 = F_65 ( V_94 ) ;
V_111 -> V_47 = V_111 -> V_46 = V_111 -> V_48 = V_49 ;
V_111 -> V_54 -= V_73 ;
F_66 ( V_2 ) ;
F_67 ( V_94 ) ;
return 0 ;
}
static T_2 F_68 ( struct V_119 * V_120 , char T_3 * V_121 ,
T_4 V_122 , T_5 * V_123 )
{
struct V_1 * V_11 = F_1 ( F_69 ( V_120 ) ) ;
char V_124 [ V_55 ] ;
T_2 V_40 ;
F_6 ( & V_11 -> V_56 ) ;
snprintf ( V_124 , sizeof( V_124 ) ,
L_6 ,
V_11 -> V_29 ,
V_11 -> V_60 ? V_11 -> V_125 . V_126 : 0 ,
( V_11 -> V_60 &&
V_11 -> V_125 . V_126 == V_127 ) ?
V_11 -> V_125 . V_128 : 0 ,
F_70 ( V_11 -> V_60 ) ) ;
F_7 ( & V_11 -> V_56 ) ;
V_124 [ sizeof( V_124 ) - 1 ] = '\0' ;
V_40 = F_71 ( V_121 , V_122 , V_123 , V_124 ,
strlen ( V_124 ) ) ;
if ( V_40 <= 0 )
return V_40 ;
F_69 ( V_120 ) -> V_48 = F_69 ( V_120 ) -> V_47 = V_49 ;
return V_40 ;
}
static int F_72 ( struct V_119 * V_120 , T_6 V_129 )
{
struct V_1 * V_11 = F_1 ( F_69 ( V_120 ) ) ;
F_6 ( & V_11 -> V_56 ) ;
if ( F_73 ( V_100 ) == V_11 -> V_60 )
F_74 ( V_11 ) ;
F_7 ( & V_11 -> V_56 ) ;
return 0 ;
}
static unsigned int F_75 ( struct V_119 * V_120 , struct V_130 * V_131 )
{
struct V_1 * V_11 = F_1 ( F_69 ( V_120 ) ) ;
int V_132 = 0 ;
F_76 ( V_120 , & V_11 -> V_57 , V_131 ) ;
F_6 ( & V_11 -> V_56 ) ;
if ( V_11 -> V_27 . V_28 )
V_132 = V_133 | V_134 ;
if ( V_11 -> V_27 . V_28 < V_11 -> V_27 . V_64 )
V_132 |= V_135 | V_136 ;
F_7 ( & V_11 -> V_56 ) ;
return V_132 ;
}
static void F_77 ( struct V_1 * V_11 , int V_137 ,
struct V_138 * V_139 )
{
struct V_138 * V_140 ;
V_139 -> V_141 = V_100 ;
F_78 (walk, &info->e_wait_q[sr].list, list) {
if ( V_140 -> V_141 -> V_142 <= V_100 -> V_142 ) {
F_15 ( & V_139 -> V_59 , & V_140 -> V_59 ) ;
return;
}
}
F_15 ( & V_139 -> V_59 , & V_11 -> V_58 [ V_137 ] . V_59 ) ;
}
static int F_79 ( struct V_1 * V_11 , int V_137 ,
T_7 * V_143 , struct V_138 * V_139 )
{
int V_132 ;
signed long time ;
F_77 ( V_11 , V_137 , V_139 ) ;
for (; ; ) {
F_80 ( V_144 ) ;
F_7 ( & V_11 -> V_56 ) ;
time = F_81 ( V_143 , 0 ,
V_145 , V_146 ) ;
if ( V_139 -> V_147 == V_148 ) {
V_132 = 0 ;
goto V_149;
}
F_6 ( & V_11 -> V_56 ) ;
if ( V_139 -> V_147 == V_148 ) {
V_132 = 0 ;
goto V_115;
}
if ( F_82 ( V_100 ) ) {
V_132 = - V_150 ;
break;
}
if ( time == 0 ) {
V_132 = - V_151 ;
break;
}
}
F_23 ( & V_139 -> V_59 ) ;
V_115:
F_7 ( & V_11 -> V_56 ) ;
V_149:
return V_132 ;
}
static struct V_138 * F_83 (
struct V_1 * V_11 , int V_137 )
{
struct V_152 * V_153 ;
V_153 = V_11 -> V_58 [ V_137 ] . V_59 . V_154 ;
if ( V_153 == & V_11 -> V_58 [ V_137 ] . V_59 )
return NULL ;
return F_84 ( V_153 , struct V_138 , V_59 ) ;
}
static inline void F_85 ( struct V_155 * V_156 , char V_157 )
{
( ( char * ) V_156 -> V_77 ) [ V_158 - 1 ] = V_157 ;
}
static void F_86 ( struct V_1 * V_11 )
{
if ( V_11 -> V_60 &&
V_11 -> V_27 . V_28 == 1 ) {
struct V_159 V_160 ;
switch ( V_11 -> V_125 . V_126 ) {
case V_161 :
break;
case V_127 :
V_160 . V_162 = V_11 -> V_125 . V_128 ;
V_160 . V_163 = 0 ;
V_160 . V_164 = V_165 ;
V_160 . V_166 = V_11 -> V_125 . V_167 ;
F_87 () ;
V_160 . V_168 = F_88 ( V_100 ,
F_89 ( V_11 -> V_60 ) ) ;
V_160 . V_169 = F_90 ( V_11 -> V_61 , F_91 () ) ;
F_92 () ;
F_93 ( V_11 -> V_125 . V_128 ,
& V_160 , V_11 -> V_60 ) ;
break;
case V_170 :
F_85 ( V_11 -> V_171 , V_172 ) ;
F_94 ( V_11 -> V_173 , V_11 -> V_171 ) ;
break;
}
F_95 ( V_11 -> V_60 ) ;
F_96 ( V_11 -> V_61 ) ;
V_11 -> V_60 = NULL ;
V_11 -> V_61 = NULL ;
}
F_97 ( & V_11 -> V_57 ) ;
}
static int F_98 ( const struct V_174 T_3 * V_175 ,
T_7 * V_176 , struct V_174 * V_177 )
{
if ( F_99 ( V_177 , V_175 , sizeof( struct V_174 ) ) )
return - V_178 ;
if ( ! F_100 ( V_177 ) )
return - V_179 ;
* V_176 = F_101 ( * V_177 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_11 )
{
if ( V_11 -> V_60 != NULL &&
V_11 -> V_125 . V_126 == V_170 ) {
F_85 ( V_11 -> V_171 , V_180 ) ;
F_94 ( V_11 -> V_173 , V_11 -> V_171 ) ;
}
F_95 ( V_11 -> V_60 ) ;
F_96 ( V_11 -> V_61 ) ;
V_11 -> V_60 = NULL ;
V_11 -> V_61 = NULL ;
}
static int F_102 ( struct V_4 * V_35 , struct V_37 * V_27 )
{
int V_51 ;
unsigned long V_181 ;
if ( V_27 -> V_64 <= 0 || V_27 -> V_67 <= 0 )
return - V_179 ;
if ( F_61 ( V_117 ) ) {
if ( V_27 -> V_64 > V_182 ||
V_27 -> V_67 > V_183 )
return - V_179 ;
} else {
if ( V_27 -> V_64 > V_35 -> V_65 ||
V_27 -> V_67 > V_35 -> V_68 )
return - V_179 ;
}
if ( V_27 -> V_67 > V_184 / V_27 -> V_64 )
return - V_185 ;
V_51 = V_27 -> V_64 * sizeof( struct V_9 ) +
F_34 (unsigned int, attr->mq_maxmsg, MQ_PRIO_MAX) *
sizeof( struct V_15 ) ;
V_181 = V_27 -> V_64 * V_27 -> V_67 ;
if ( V_181 + V_51 < V_181 )
return - V_185 ;
return 0 ;
}
static struct V_119 * F_103 ( struct V_4 * V_35 , struct V_2 * V_111 ,
struct V_186 * V_186 , int V_187 , T_1 V_36 ,
struct V_37 * V_27 )
{
const struct V_188 * V_188 = F_104 () ;
int V_40 ;
if ( V_27 ) {
V_40 = F_102 ( V_35 , V_27 ) ;
if ( V_40 )
return F_40 ( V_40 ) ;
V_186 -> V_94 -> V_113 = V_27 ;
} else {
struct V_37 V_189 ;
V_189 . V_64 = F_33 ( V_35 -> V_65 ,
V_35 -> V_66 ) ;
V_189 . V_67 = F_33 ( V_35 -> V_68 ,
V_35 -> V_69 ) ;
V_40 = F_102 ( V_35 , & V_189 ) ;
if ( V_40 )
return F_40 ( V_40 ) ;
}
V_36 &= ~ F_105 () ;
V_40 = F_106 ( V_111 , V_186 -> V_94 , V_36 , true ) ;
V_186 -> V_94 -> V_113 = NULL ;
if ( V_40 )
return F_40 ( V_40 ) ;
return F_107 ( V_186 , V_187 , V_188 ) ;
}
static struct V_119 * F_108 ( struct V_186 * V_186 , int V_187 )
{
static const int V_190 [ V_191 ] = { V_192 , V_193 ,
V_192 | V_193 } ;
int V_194 ;
if ( ( V_187 & V_191 ) == ( V_195 | V_196 ) )
return F_40 ( - V_179 ) ;
V_194 = V_190 [ V_187 & V_191 ] ;
if ( F_109 ( F_65 ( V_186 -> V_94 ) , V_194 ) )
return F_40 ( - V_114 ) ;
return F_107 ( V_186 , V_187 , F_104 () ) ;
}
static inline void F_110 ( struct V_197 * V_198 ,
struct V_1 * V_11 ,
struct V_9 * V_199 ,
struct V_138 * V_200 )
{
V_200 -> V_10 = V_199 ;
F_23 ( & V_200 -> V_59 ) ;
F_111 ( V_198 , V_200 -> V_141 ) ;
V_200 -> V_147 = V_148 ;
}
static inline void F_112 ( struct V_197 * V_198 ,
struct V_1 * V_11 )
{
struct V_138 * V_201 = F_83 ( V_11 , V_202 ) ;
if ( ! V_201 ) {
F_113 ( & V_11 -> V_57 ) ;
return;
}
if ( F_8 ( V_201 -> V_10 , V_11 ) )
return;
F_23 ( & V_201 -> V_59 ) ;
F_111 ( V_198 , V_201 -> V_141 ) ;
V_201 -> V_147 = V_148 ;
}
int F_114 ( struct V_4 * V_7 )
{
V_7 -> V_110 = 0 ;
V_7 -> V_116 = V_203 ;
V_7 -> V_65 = V_204 ;
V_7 -> V_68 = V_205 ;
V_7 -> V_66 = V_206 ;
V_7 -> V_69 = V_207 ;
V_7 -> V_208 = F_115 ( & V_209 , V_7 ) ;
if ( F_42 ( V_7 -> V_208 ) ) {
int V_41 = F_43 ( V_7 -> V_208 ) ;
V_7 -> V_208 = NULL ;
return V_41 ;
}
return 0 ;
}
void F_116 ( struct V_4 * V_7 )
{
V_7 -> V_208 -> V_210 -> V_6 = NULL ;
}
void F_117 ( struct V_4 * V_7 )
{
F_118 ( V_7 -> V_208 ) ;
}
static int T_8 F_119 ( void )
{
int error ;
V_105 = F_120 ( L_7 ,
sizeof( struct V_1 ) , 0 ,
V_211 | V_212 , F_47 ) ;
if ( V_105 == NULL )
return - V_25 ;
V_213 = F_121 () ;
error = F_122 ( & V_209 ) ;
if ( error )
goto V_214;
F_31 ( & V_8 ) ;
error = F_114 ( & V_215 ) ;
if ( error )
goto V_216;
return 0 ;
V_216:
F_123 ( & V_209 ) ;
V_214:
if ( V_213 )
F_124 ( V_213 ) ;
F_125 ( V_105 ) ;
return error ;
}
