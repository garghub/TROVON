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
__releases( &info->lock
static struct V_137 * F_81 (
struct V_1 * V_11 , int V_136 )
{
struct V_143 * V_144 ;
V_144 = V_11 -> V_57 [ V_136 ] . V_58 . V_145 ;
if ( V_144 == & V_11 -> V_57 [ V_136 ] . V_58 )
return NULL ;
return F_82 ( V_144 , struct V_137 , V_58 ) ;
}
static inline void F_83 ( struct V_146 * V_147 , char V_148 )
{
( ( char * ) V_147 -> V_76 ) [ V_149 - 1 ] = V_148 ;
}
static void F_84 ( struct V_1 * V_11 )
{
if ( V_11 -> V_59 &&
V_11 -> V_27 . V_28 == 1 ) {
struct V_150 V_151 ;
switch ( V_11 -> V_124 . V_125 ) {
case V_152 :
break;
case V_126 :
V_151 . V_153 = V_11 -> V_124 . V_127 ;
V_151 . V_154 = 0 ;
V_151 . V_155 = V_156 ;
V_151 . V_157 = V_11 -> V_124 . V_158 ;
F_85 () ;
V_151 . V_159 = F_86 ( V_99 ,
F_87 ( V_11 -> V_59 ) ) ;
V_151 . V_160 = F_88 ( V_11 -> V_60 , F_89 () ) ;
F_90 () ;
F_91 ( V_11 -> V_124 . V_127 ,
& V_151 , V_11 -> V_59 ) ;
break;
case V_161 :
F_83 ( V_11 -> V_162 , V_163 ) ;
F_92 ( V_11 -> V_164 , V_11 -> V_162 ) ;
break;
}
F_93 ( V_11 -> V_59 ) ;
F_94 ( V_11 -> V_60 ) ;
V_11 -> V_59 = NULL ;
V_11 -> V_60 = NULL ;
}
F_95 ( & V_11 -> V_56 ) ;
}
static int F_96 ( const struct V_165 T_3 * V_166 ,
T_7 * V_167 , struct V_165 * V_168 )
{
if ( F_97 ( V_168 , V_166 , sizeof( struct V_165 ) ) )
return - V_169 ;
if ( ! F_98 ( V_168 ) )
return - V_170 ;
* V_167 = F_99 ( * V_168 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_11 )
{
if ( V_11 -> V_59 != NULL &&
V_11 -> V_124 . V_125 == V_161 ) {
F_83 ( V_11 -> V_162 , V_171 ) ;
F_92 ( V_11 -> V_164 , V_11 -> V_162 ) ;
}
F_93 ( V_11 -> V_59 ) ;
F_94 ( V_11 -> V_60 ) ;
V_11 -> V_59 = NULL ;
V_11 -> V_60 = NULL ;
}
static int F_100 ( struct V_4 * V_35 , struct V_37 * V_27 )
{
int V_50 ;
unsigned long V_172 ;
if ( V_27 -> V_63 <= 0 || V_27 -> V_66 <= 0 )
return - V_170 ;
if ( F_62 ( V_116 ) ) {
if ( V_27 -> V_63 > V_173 ||
V_27 -> V_66 > V_174 )
return - V_170 ;
} else {
if ( V_27 -> V_63 > V_35 -> V_64 ||
V_27 -> V_66 > V_35 -> V_67 )
return - V_170 ;
}
if ( V_27 -> V_66 > V_175 / V_27 -> V_63 )
return - V_176 ;
V_50 = V_27 -> V_63 * sizeof( struct V_9 ) +
F_35 (unsigned int, attr->mq_maxmsg, MQ_PRIO_MAX) *
sizeof( struct V_15 ) ;
V_172 = V_27 -> V_63 * V_27 -> V_66 ;
if ( V_172 + V_50 < V_172 )
return - V_176 ;
return 0 ;
}
static struct V_118 * F_101 ( struct V_4 * V_35 , struct V_2 * V_110 ,
struct V_177 * V_177 , int V_178 , T_1 V_36 ,
struct V_37 * V_27 )
{
const struct V_179 * V_179 = F_102 () ;
int V_40 ;
if ( V_27 ) {
V_40 = F_100 ( V_35 , V_27 ) ;
if ( V_40 )
return F_41 ( V_40 ) ;
V_177 -> V_93 -> V_112 = V_27 ;
} else {
struct V_37 V_180 ;
V_180 . V_63 = F_34 ( V_35 -> V_64 ,
V_35 -> V_65 ) ;
V_180 . V_66 = F_34 ( V_35 -> V_67 ,
V_35 -> V_68 ) ;
V_40 = F_100 ( V_35 , & V_180 ) ;
if ( V_40 )
return F_41 ( V_40 ) ;
}
V_36 &= ~ F_103 () ;
V_40 = F_104 ( V_110 , V_177 -> V_93 , V_36 , true ) ;
V_177 -> V_93 -> V_112 = NULL ;
if ( V_40 )
return F_41 ( V_40 ) ;
return F_105 ( V_177 , V_178 , V_179 ) ;
}
static struct V_118 * F_106 ( struct V_177 * V_177 , int V_178 )
{
static const int V_181 [ V_182 ] = { V_183 , V_184 ,
V_183 | V_184 } ;
int V_185 ;
if ( ( V_178 & V_182 ) == ( V_186 | V_187 ) )
return F_41 ( - V_170 ) ;
V_185 = V_181 [ V_178 & V_182 ] ;
if ( F_107 ( F_66 ( V_177 -> V_93 ) , V_185 ) )
return F_41 ( - V_113 ) ;
return F_105 ( V_177 , V_178 , F_102 () ) ;
}
static inline void F_108 ( struct V_188 * V_189 ,
struct V_1 * V_11 ,
struct V_9 * V_190 ,
struct V_137 * V_191 )
{
V_191 -> V_10 = V_190 ;
F_23 ( & V_191 -> V_58 ) ;
F_109 ( V_189 , V_191 -> V_140 ) ;
V_191 -> V_192 = V_193 ;
}
static inline void F_110 ( struct V_188 * V_189 ,
struct V_1 * V_11 )
{
struct V_137 * V_194 = F_81 ( V_11 , V_195 ) ;
if ( ! V_194 ) {
F_111 ( & V_11 -> V_56 ) ;
return;
}
if ( F_8 ( V_194 -> V_10 , V_11 ) )
return;
F_23 ( & V_194 -> V_58 ) ;
F_109 ( V_189 , V_194 -> V_140 ) ;
V_194 -> V_192 = V_193 ;
}
int F_112 ( struct V_4 * V_7 )
{
V_7 -> V_109 = 0 ;
V_7 -> V_115 = V_196 ;
V_7 -> V_64 = V_197 ;
V_7 -> V_67 = V_198 ;
V_7 -> V_65 = V_199 ;
V_7 -> V_68 = V_200 ;
V_7 -> V_201 = F_113 ( & V_202 , V_7 ) ;
if ( F_43 ( V_7 -> V_201 ) ) {
int V_41 = F_44 ( V_7 -> V_201 ) ;
V_7 -> V_201 = NULL ;
return V_41 ;
}
return 0 ;
}
void F_114 ( struct V_4 * V_7 )
{
V_7 -> V_201 -> V_203 -> V_6 = NULL ;
}
void F_115 ( struct V_4 * V_7 )
{
F_116 ( V_7 -> V_201 ) ;
}
static int T_8 F_117 ( void )
{
int error ;
V_104 = F_118 ( L_7 ,
sizeof( struct V_1 ) , 0 ,
V_204 | V_205 , F_48 ) ;
if ( V_104 == NULL )
return - V_25 ;
V_206 = F_119 () ;
error = F_120 ( & V_202 ) ;
if ( error )
goto V_207;
F_32 ( & V_8 ) ;
error = F_112 ( & V_208 ) ;
if ( error )
goto V_209;
return 0 ;
V_209:
F_121 ( & V_202 ) ;
V_207:
if ( V_206 )
F_122 ( V_206 ) ;
F_123 ( V_104 ) ;
return error ;
}
