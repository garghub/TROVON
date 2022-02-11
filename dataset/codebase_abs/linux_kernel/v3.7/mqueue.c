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
if ( ! ( V_94 & V_96 ) )
V_77 = V_97 -> V_98 -> V_35 ;
return F_46 ( V_93 , V_94 , V_77 , F_41 ) ;
}
static void F_47 ( void * V_99 )
{
struct V_1 * V_13 = (struct V_1 * ) V_99 ;
F_48 ( & V_13 -> V_3 ) ;
}
static struct V_2 * F_49 ( struct V_33 * V_34 )
{
struct V_1 * V_100 ;
V_100 = F_50 ( V_101 , V_102 ) ;
if ( ! V_100 )
return NULL ;
return & V_100 -> V_3 ;
}
static void F_51 ( struct V_103 * V_104 )
{
struct V_2 * V_2 = F_2 ( V_104 , struct V_2 , V_105 ) ;
F_52 ( V_101 , F_1 ( V_2 ) ) ;
}
static void F_53 ( struct V_2 * V_2 )
{
F_54 ( & V_2 -> V_105 , F_51 ) ;
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
V_35 -> V_106 -- ;
F_7 ( & V_8 ) ;
F_58 ( V_62 ) ;
}
if ( V_35 )
F_59 ( V_35 ) ;
}
static int F_60 ( struct V_2 * V_107 , struct V_91 * V_91 ,
T_1 V_36 , bool V_108 )
{
struct V_2 * V_2 ;
struct V_37 * V_28 = V_91 -> V_109 ;
int error ;
struct V_4 * V_35 ;
F_6 ( & V_8 ) ;
V_35 = F_3 ( V_107 ) ;
if ( ! V_35 ) {
error = - V_110 ;
goto V_111;
}
if ( V_35 -> V_106 >= V_112 ||
( V_35 -> V_106 >= V_35 -> V_113 &&
! F_61 ( V_114 ) ) ) {
error = - V_115 ;
goto V_111;
}
V_35 -> V_106 ++ ;
F_7 ( & V_8 ) ;
V_2 = F_24 ( V_107 -> V_5 , V_35 , V_36 , V_28 ) ;
if ( F_42 ( V_2 ) ) {
error = F_43 ( V_2 ) ;
F_6 ( & V_8 ) ;
V_35 -> V_106 -- ;
goto V_111;
}
F_59 ( V_35 ) ;
V_107 -> V_54 += V_73 ;
V_107 -> V_47 = V_107 -> V_46 = V_107 -> V_48 = V_49 ;
F_62 ( V_91 , V_2 ) ;
F_63 ( V_91 ) ;
return 0 ;
V_111:
F_7 ( & V_8 ) ;
if ( V_35 )
F_59 ( V_35 ) ;
return error ;
}
static int F_64 ( struct V_2 * V_107 , struct V_91 * V_91 )
{
struct V_2 * V_2 = V_91 -> V_116 ;
V_107 -> V_47 = V_107 -> V_46 = V_107 -> V_48 = V_49 ;
V_107 -> V_54 -= V_73 ;
F_65 ( V_2 ) ;
F_66 ( V_91 ) ;
return 0 ;
}
static T_2 F_67 ( struct V_117 * V_118 , char T_3 * V_119 ,
T_4 V_120 , T_5 * V_121 )
{
struct V_1 * V_11 = F_1 ( V_118 -> V_122 . V_91 -> V_116 ) ;
char V_123 [ V_55 ] ;
T_2 V_40 ;
F_6 ( & V_11 -> V_56 ) ;
snprintf ( V_123 , sizeof( V_123 ) ,
L_6 ,
V_11 -> V_27 ,
V_11 -> V_60 ? V_11 -> V_124 . V_125 : 0 ,
( V_11 -> V_60 &&
V_11 -> V_124 . V_125 == V_126 ) ?
V_11 -> V_124 . V_127 : 0 ,
F_68 ( V_11 -> V_60 ) ) ;
F_7 ( & V_11 -> V_56 ) ;
V_123 [ sizeof( V_123 ) - 1 ] = '\0' ;
V_40 = F_69 ( V_119 , V_120 , V_121 , V_123 ,
strlen ( V_123 ) ) ;
if ( V_40 <= 0 )
return V_40 ;
V_118 -> V_122 . V_91 -> V_116 -> V_48 = V_118 -> V_122 . V_91 -> V_116 -> V_47 = V_49 ;
return V_40 ;
}
static int F_70 ( struct V_117 * V_118 , T_6 V_128 )
{
struct V_1 * V_11 = F_1 ( V_118 -> V_122 . V_91 -> V_116 ) ;
F_6 ( & V_11 -> V_56 ) ;
if ( F_71 ( V_97 ) == V_11 -> V_60 )
F_72 ( V_11 ) ;
F_7 ( & V_11 -> V_56 ) ;
return 0 ;
}
static unsigned int F_73 ( struct V_117 * V_118 , struct V_129 * V_130 )
{
struct V_1 * V_11 = F_1 ( V_118 -> V_122 . V_91 -> V_116 ) ;
int V_131 = 0 ;
F_74 ( V_118 , & V_11 -> V_57 , V_130 ) ;
F_6 ( & V_11 -> V_56 ) ;
if ( V_11 -> V_28 . V_29 )
V_131 = V_132 | V_133 ;
if ( V_11 -> V_28 . V_29 < V_11 -> V_28 . V_64 )
V_131 |= V_134 | V_135 ;
F_7 ( & V_11 -> V_56 ) ;
return V_131 ;
}
static void F_75 ( struct V_1 * V_11 , int V_136 ,
struct V_137 * V_138 )
{
struct V_137 * V_139 ;
V_138 -> V_140 = V_97 ;
F_76 (walk, &info->e_wait_q[sr].list, list) {
if ( V_139 -> V_140 -> V_141 <= V_97 -> V_141 ) {
F_15 ( & V_138 -> V_59 , & V_139 -> V_59 ) ;
return;
}
}
F_15 ( & V_138 -> V_59 , & V_11 -> V_58 [ V_136 ] . V_59 ) ;
}
static int F_77 ( struct V_1 * V_11 , int V_136 ,
T_7 * V_142 , struct V_137 * V_138 )
{
int V_131 ;
signed long time ;
F_75 ( V_11 , V_136 , V_138 ) ;
for (; ; ) {
F_78 ( V_143 ) ;
F_7 ( & V_11 -> V_56 ) ;
time = F_79 ( V_142 , 0 ,
V_144 , V_145 ) ;
while ( V_138 -> V_146 == V_147 )
F_80 () ;
if ( V_138 -> V_146 == V_148 ) {
V_131 = 0 ;
goto V_149;
}
F_6 ( & V_11 -> V_56 ) ;
if ( V_138 -> V_146 == V_148 ) {
V_131 = 0 ;
goto V_111;
}
if ( F_81 ( V_97 ) ) {
V_131 = - V_150 ;
break;
}
if ( time == 0 ) {
V_131 = - V_151 ;
break;
}
}
F_23 ( & V_138 -> V_59 ) ;
V_111:
F_7 ( & V_11 -> V_56 ) ;
V_149:
return V_131 ;
}
static struct V_137 * F_82 (
struct V_1 * V_11 , int V_136 )
{
struct V_152 * V_153 ;
V_153 = V_11 -> V_58 [ V_136 ] . V_59 . V_154 ;
if ( V_153 == & V_11 -> V_58 [ V_136 ] . V_59 )
return NULL ;
return F_83 ( V_153 , struct V_137 , V_59 ) ;
}
static inline void F_84 ( struct V_155 * V_156 , char V_157 )
{
( ( char * ) V_156 -> V_77 ) [ V_158 - 1 ] = V_157 ;
}
static void F_85 ( struct V_1 * V_11 )
{
if ( V_11 -> V_60 &&
V_11 -> V_28 . V_29 == 1 ) {
struct V_159 V_160 ;
switch ( V_11 -> V_124 . V_125 ) {
case V_161 :
break;
case V_126 :
V_160 . V_162 = V_11 -> V_124 . V_127 ;
V_160 . V_163 = 0 ;
V_160 . V_164 = V_165 ;
V_160 . V_166 = V_11 -> V_124 . V_167 ;
F_86 () ;
V_160 . V_168 = F_87 ( V_97 ,
F_88 ( V_11 -> V_60 ) ) ;
V_160 . V_169 = F_89 ( V_11 -> V_61 , F_90 () ) ;
F_91 () ;
F_92 ( V_11 -> V_124 . V_127 ,
& V_160 , V_11 -> V_60 ) ;
break;
case V_170 :
F_84 ( V_11 -> V_171 , V_172 ) ;
F_93 ( V_11 -> V_173 , V_11 -> V_171 ) ;
break;
}
F_94 ( V_11 -> V_60 ) ;
F_95 ( V_11 -> V_61 ) ;
V_11 -> V_60 = NULL ;
V_11 -> V_61 = NULL ;
}
F_96 ( & V_11 -> V_57 ) ;
}
static int F_97 ( const struct V_174 T_3 * V_175 ,
T_7 * V_176 , struct V_174 * V_177 )
{
if ( F_98 ( V_177 , V_175 , sizeof( struct V_174 ) ) )
return - V_178 ;
if ( ! F_99 ( V_177 ) )
return - V_179 ;
* V_176 = F_100 ( * V_177 ) ;
return 0 ;
}
static void F_72 ( struct V_1 * V_11 )
{
if ( V_11 -> V_60 != NULL &&
V_11 -> V_124 . V_125 == V_170 ) {
F_84 ( V_11 -> V_171 , V_180 ) ;
F_93 ( V_11 -> V_173 , V_11 -> V_171 ) ;
}
F_94 ( V_11 -> V_60 ) ;
F_95 ( V_11 -> V_61 ) ;
V_11 -> V_60 = NULL ;
V_11 -> V_61 = NULL ;
}
static int F_101 ( struct V_4 * V_35 , struct V_37 * V_28 )
{
int V_51 ;
unsigned long V_181 ;
if ( V_28 -> V_64 <= 0 || V_28 -> V_67 <= 0 )
return - V_179 ;
if ( F_61 ( V_114 ) ) {
if ( V_28 -> V_64 > V_182 ||
V_28 -> V_67 > V_183 )
return - V_179 ;
} else {
if ( V_28 -> V_64 > V_35 -> V_65 ||
V_28 -> V_67 > V_35 -> V_68 )
return - V_179 ;
}
if ( V_28 -> V_67 > V_184 / V_28 -> V_64 )
return - V_185 ;
V_51 = V_28 -> V_64 * sizeof( struct V_9 ) +
F_34 (unsigned int, attr->mq_maxmsg, MQ_PRIO_MAX) *
sizeof( struct V_15 ) ;
V_181 = V_28 -> V_64 * V_28 -> V_67 ;
if ( V_181 + V_51 < V_181 )
return - V_185 ;
return 0 ;
}
static struct V_117 * F_102 ( struct V_4 * V_35 , struct V_2 * V_107 ,
struct V_186 * V_186 , int V_187 , T_1 V_36 ,
struct V_37 * V_28 )
{
const struct V_188 * V_188 = F_103 () ;
int V_40 ;
if ( V_28 ) {
V_40 = F_101 ( V_35 , V_28 ) ;
if ( V_40 )
return F_40 ( V_40 ) ;
V_186 -> V_91 -> V_109 = V_28 ;
} else {
struct V_37 V_189 ;
V_189 . V_64 = F_33 ( V_35 -> V_65 ,
V_35 -> V_66 ) ;
V_189 . V_67 = F_33 ( V_35 -> V_68 ,
V_35 -> V_69 ) ;
V_40 = F_101 ( V_35 , & V_189 ) ;
if ( V_40 )
return F_40 ( V_40 ) ;
}
V_36 &= ~ F_104 () ;
V_40 = F_105 ( V_107 , V_186 -> V_91 , V_36 , true ) ;
V_186 -> V_91 -> V_109 = NULL ;
if ( V_40 )
return F_40 ( V_40 ) ;
return F_106 ( V_186 , V_187 , V_188 ) ;
}
static struct V_117 * F_107 ( struct V_186 * V_186 , int V_187 )
{
static const int V_190 [ V_191 ] = { V_192 , V_193 ,
V_192 | V_193 } ;
int V_194 ;
if ( ( V_187 & V_191 ) == ( V_195 | V_196 ) )
return F_40 ( - V_179 ) ;
V_194 = V_190 [ V_187 & V_191 ] ;
if ( F_108 ( V_186 -> V_91 -> V_116 , V_194 ) )
return F_40 ( - V_110 ) ;
return F_106 ( V_186 , V_187 , F_103 () ) ;
}
static inline void F_109 ( struct V_1 * V_11 ,
struct V_9 * V_197 ,
struct V_137 * V_198 )
{
V_198 -> V_10 = V_197 ;
F_23 ( & V_198 -> V_59 ) ;
V_198 -> V_146 = V_147 ;
F_110 ( V_198 -> V_140 ) ;
F_111 () ;
V_198 -> V_146 = V_148 ;
}
static inline void F_112 ( struct V_1 * V_11 )
{
struct V_137 * V_199 = F_82 ( V_11 , V_200 ) ;
if ( ! V_199 ) {
F_113 ( & V_11 -> V_57 ) ;
return;
}
if ( F_8 ( V_199 -> V_10 , V_11 ) )
return;
F_23 ( & V_199 -> V_59 ) ;
V_199 -> V_146 = V_147 ;
F_110 ( V_199 -> V_140 ) ;
F_111 () ;
V_199 -> V_146 = V_148 ;
}
int F_114 ( struct V_4 * V_7 )
{
V_7 -> V_106 = 0 ;
V_7 -> V_113 = V_201 ;
V_7 -> V_65 = V_202 ;
V_7 -> V_68 = V_203 ;
V_7 -> V_66 = V_204 ;
V_7 -> V_69 = V_205 ;
V_7 -> V_206 = F_115 ( & V_207 , V_7 ) ;
if ( F_42 ( V_7 -> V_206 ) ) {
int V_41 = F_43 ( V_7 -> V_206 ) ;
V_7 -> V_206 = NULL ;
return V_41 ;
}
return 0 ;
}
void F_116 ( struct V_4 * V_7 )
{
V_7 -> V_206 -> V_208 -> V_6 = NULL ;
}
void F_117 ( struct V_4 * V_7 )
{
F_118 ( V_7 -> V_206 ) ;
}
static int T_8 F_119 ( void )
{
int error ;
V_101 = F_120 ( L_7 ,
sizeof( struct V_1 ) , 0 ,
V_209 , F_47 ) ;
if ( V_101 == NULL )
return - V_25 ;
V_210 = F_121 () ;
error = F_122 ( & V_207 ) ;
if ( error )
goto V_211;
F_31 ( & V_8 ) ;
error = F_114 ( & V_212 ) ;
if ( error )
goto V_213;
return 0 ;
V_213:
F_123 ( & V_207 ) ;
V_211:
if ( V_210 )
F_124 ( V_210 ) ;
F_125 ( V_101 ) ;
return error ;
}
