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
F_12 ( & V_16 -> V_12 ) ;
F_13 ( & V_16 -> V_26 ) ;
V_11 -> V_27 += sizeof( * V_16 ) ;
}
V_16 -> V_18 = V_10 -> V_19 ;
F_14 ( & V_16 -> V_12 , V_14 , V_13 ) ;
F_15 ( & V_16 -> V_12 , & V_11 -> V_17 ) ;
V_20:
V_11 -> V_28 . V_29 ++ ;
V_11 -> V_27 += V_10 -> V_30 ;
F_16 ( & V_10 -> V_31 , & V_16 -> V_26 ) ;
return 0 ;
}
static inline struct V_9 * F_17 ( struct V_1 * V_11 )
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
F_18 ( L_1
L_2
L_3 ) ;
V_11 -> V_28 . V_29 = 0 ;
}
return NULL ;
}
V_16 = F_9 ( V_14 , struct V_15 , V_12 ) ;
if ( F_19 ( F_20 ( & V_16 -> V_26 ) ) ) {
F_18 ( L_1
L_4
L_5 ) ;
F_21 ( & V_16 -> V_12 , & V_11 -> V_17 ) ;
if ( V_11 -> V_23 ) {
V_11 -> V_27 -= sizeof( * V_16 ) ;
F_22 ( V_16 ) ;
} else {
V_11 -> V_23 = V_16 ;
}
goto V_32;
} else {
V_10 = F_23 ( & V_16 -> V_26 ,
struct V_9 , V_31 ) ;
F_24 ( & V_10 -> V_31 ) ;
if ( F_20 ( & V_16 -> V_26 ) ) {
F_21 ( & V_16 -> V_12 , & V_11 -> V_17 ) ;
if ( V_11 -> V_23 ) {
V_11 -> V_27 -= sizeof( * V_16 ) ;
F_22 ( V_16 ) ;
} else {
V_11 -> V_23 = V_16 ;
}
}
}
V_11 -> V_28 . V_29 -- ;
V_11 -> V_27 -= V_10 -> V_30 ;
return V_10 ;
}
static struct V_2 * F_25 ( struct V_33 * V_34 ,
struct V_4 * V_35 , T_1 V_36 ,
struct V_37 * V_28 )
{
struct V_38 * V_39 = F_26 () ;
struct V_2 * V_2 ;
int V_40 = - V_25 ;
V_2 = F_27 ( V_34 ) ;
if ( ! V_2 )
goto V_41;
V_2 -> V_42 = F_28 () ;
V_2 -> V_43 = V_36 ;
V_2 -> V_44 = F_29 () ;
V_2 -> V_45 = F_30 () ;
V_2 -> V_46 = V_2 -> V_47 = V_2 -> V_48 = V_49 ;
if ( F_31 ( V_36 ) ) {
struct V_1 * V_11 ;
unsigned long V_50 , V_51 ;
V_2 -> V_52 = & V_53 ;
V_2 -> V_54 = V_55 ;
V_11 = F_1 ( V_2 ) ;
F_32 ( & V_11 -> V_56 ) ;
F_33 ( & V_11 -> V_57 ) ;
F_13 ( & V_11 -> V_58 [ 0 ] . V_59 ) ;
F_13 ( & V_11 -> V_58 [ 1 ] . V_59 ) ;
V_11 -> V_60 = NULL ;
V_11 -> V_61 = NULL ;
V_11 -> V_27 = 0 ;
V_11 -> V_62 = NULL ;
V_11 -> V_17 = V_63 ;
V_11 -> V_23 = NULL ;
memset ( & V_11 -> V_28 , 0 , sizeof( V_11 -> V_28 ) ) ;
V_11 -> V_28 . V_64 = F_34 ( V_35 -> V_65 ,
V_35 -> V_66 ) ;
V_11 -> V_28 . V_67 = F_34 ( V_35 -> V_68 ,
V_35 -> V_69 ) ;
if ( V_28 ) {
V_11 -> V_28 . V_64 = V_28 -> V_64 ;
V_11 -> V_28 . V_67 = V_28 -> V_67 ;
}
V_51 = V_11 -> V_28 . V_64 * sizeof( struct V_9 ) +
F_35 (unsigned int, info->attr.mq_maxmsg, MQ_PRIO_MAX) *
sizeof( struct V_15 ) ;
V_50 = V_51 + ( V_11 -> V_28 . V_64 *
V_11 -> V_28 . V_67 ) ;
F_6 ( & V_8 ) ;
if ( V_39 -> V_50 + V_50 < V_39 -> V_50 ||
V_39 -> V_50 + V_50 > F_36 ( V_70 ) ) {
F_7 ( & V_8 ) ;
V_40 = - V_71 ;
goto V_72;
}
V_39 -> V_50 += V_50 ;
F_7 ( & V_8 ) ;
V_11 -> V_62 = F_37 ( V_39 ) ;
} else if ( F_38 ( V_36 ) ) {
F_39 ( V_2 ) ;
V_2 -> V_54 = 2 * V_73 ;
V_2 -> V_74 = & V_75 ;
V_2 -> V_52 = & V_76 ;
}
return V_2 ;
V_72:
F_40 ( V_2 ) ;
V_41:
return F_41 ( V_40 ) ;
}
static int F_42 ( struct V_33 * V_34 , void * V_77 , int V_78 )
{
struct V_2 * V_2 ;
struct V_4 * V_7 = V_77 ;
V_34 -> V_79 = V_80 ;
V_34 -> V_81 = V_82 ;
V_34 -> V_83 = V_84 ;
V_34 -> V_85 = & V_86 ;
V_2 = F_25 ( V_34 , V_7 , V_87 | V_88 | V_89 , NULL ) ;
if ( F_43 ( V_2 ) )
return F_44 ( V_2 ) ;
V_34 -> V_90 = F_45 ( V_2 ) ;
if ( ! V_34 -> V_90 )
return - V_25 ;
return 0 ;
}
static struct V_91 * F_46 ( struct V_92 * V_93 ,
int V_94 , const char * V_95 ,
void * V_77 )
{
if ( ! ( V_94 & V_96 ) )
V_77 = V_97 -> V_98 -> V_35 ;
return F_47 ( V_93 , V_94 , V_77 , F_42 ) ;
}
static void F_48 ( void * V_99 )
{
struct V_1 * V_13 = (struct V_1 * ) V_99 ;
F_49 ( & V_13 -> V_3 ) ;
}
static struct V_2 * F_50 ( struct V_33 * V_34 )
{
struct V_1 * V_100 ;
V_100 = F_51 ( V_101 , V_102 ) ;
if ( ! V_100 )
return NULL ;
return & V_100 -> V_3 ;
}
static void F_52 ( struct V_103 * V_104 )
{
struct V_2 * V_2 = F_2 ( V_104 , struct V_2 , V_105 ) ;
F_53 ( V_101 , F_1 ( V_2 ) ) ;
}
static void F_54 ( struct V_2 * V_2 )
{
F_55 ( & V_2 -> V_105 , F_52 ) ;
}
static void F_56 ( struct V_2 * V_2 )
{
struct V_1 * V_11 ;
struct V_38 * V_62 ;
unsigned long V_50 , V_51 ;
struct V_4 * V_35 ;
struct V_9 * V_10 ;
F_57 ( V_2 ) ;
if ( F_38 ( V_2 -> V_43 ) )
return;
V_35 = F_5 ( V_2 ) ;
V_11 = F_1 ( V_2 ) ;
F_6 ( & V_11 -> V_56 ) ;
while ( ( V_10 = F_17 ( V_11 ) ) != NULL )
F_58 ( V_10 ) ;
F_22 ( V_11 -> V_23 ) ;
F_7 ( & V_11 -> V_56 ) ;
V_51 = V_11 -> V_28 . V_64 * sizeof( struct V_9 ) +
F_35 (unsigned int, info->attr.mq_maxmsg, MQ_PRIO_MAX) *
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
F_59 ( V_62 ) ;
}
if ( V_35 )
F_60 ( V_35 ) ;
}
static int F_61 ( struct V_2 * V_107 , struct V_91 * V_91 ,
T_1 V_36 , struct V_108 * V_109 )
{
struct V_2 * V_2 ;
struct V_37 * V_28 = V_91 -> V_110 ;
int error ;
struct V_4 * V_35 ;
F_6 ( & V_8 ) ;
V_35 = F_3 ( V_107 ) ;
if ( ! V_35 ) {
error = - V_111 ;
goto V_112;
}
if ( V_35 -> V_106 >= V_113 ||
( V_35 -> V_106 >= V_35 -> V_114 &&
! F_62 ( V_115 ) ) ) {
error = - V_116 ;
goto V_112;
}
V_35 -> V_106 ++ ;
F_7 ( & V_8 ) ;
V_2 = F_25 ( V_107 -> V_5 , V_35 , V_36 , V_28 ) ;
if ( F_43 ( V_2 ) ) {
error = F_44 ( V_2 ) ;
F_6 ( & V_8 ) ;
V_35 -> V_106 -- ;
goto V_112;
}
F_60 ( V_35 ) ;
V_107 -> V_54 += V_73 ;
V_107 -> V_47 = V_107 -> V_46 = V_107 -> V_48 = V_49 ;
F_63 ( V_91 , V_2 ) ;
F_64 ( V_91 ) ;
return 0 ;
V_112:
F_7 ( & V_8 ) ;
if ( V_35 )
F_60 ( V_35 ) ;
return error ;
}
static int F_65 ( struct V_2 * V_107 , struct V_91 * V_91 )
{
struct V_2 * V_2 = V_91 -> V_117 ;
V_107 -> V_47 = V_107 -> V_46 = V_107 -> V_48 = V_49 ;
V_107 -> V_54 -= V_73 ;
F_66 ( V_2 ) ;
F_67 ( V_91 ) ;
return 0 ;
}
static T_2 F_68 ( struct V_118 * V_119 , char T_3 * V_120 ,
T_4 V_121 , T_5 * V_122 )
{
struct V_1 * V_11 = F_1 ( V_119 -> V_123 . V_91 -> V_117 ) ;
char V_124 [ V_55 ] ;
T_2 V_40 ;
F_6 ( & V_11 -> V_56 ) ;
snprintf ( V_124 , sizeof( V_124 ) ,
L_6 ,
V_11 -> V_27 ,
V_11 -> V_60 ? V_11 -> V_125 . V_126 : 0 ,
( V_11 -> V_60 &&
V_11 -> V_125 . V_126 == V_127 ) ?
V_11 -> V_125 . V_128 : 0 ,
F_69 ( V_11 -> V_60 ) ) ;
F_7 ( & V_11 -> V_56 ) ;
V_124 [ sizeof( V_124 ) - 1 ] = '\0' ;
V_40 = F_70 ( V_120 , V_121 , V_122 , V_124 ,
strlen ( V_124 ) ) ;
if ( V_40 <= 0 )
return V_40 ;
V_119 -> V_123 . V_91 -> V_117 -> V_48 = V_119 -> V_123 . V_91 -> V_117 -> V_47 = V_49 ;
return V_40 ;
}
static int F_71 ( struct V_118 * V_119 , T_6 V_129 )
{
struct V_1 * V_11 = F_1 ( V_119 -> V_123 . V_91 -> V_117 ) ;
F_6 ( & V_11 -> V_56 ) ;
if ( F_72 ( V_97 ) == V_11 -> V_60 )
F_73 ( V_11 ) ;
F_7 ( & V_11 -> V_56 ) ;
return 0 ;
}
static unsigned int F_74 ( struct V_118 * V_119 , struct V_130 * V_131 )
{
struct V_1 * V_11 = F_1 ( V_119 -> V_123 . V_91 -> V_117 ) ;
int V_132 = 0 ;
F_75 ( V_119 , & V_11 -> V_57 , V_131 ) ;
F_6 ( & V_11 -> V_56 ) ;
if ( V_11 -> V_28 . V_29 )
V_132 = V_133 | V_134 ;
if ( V_11 -> V_28 . V_29 < V_11 -> V_28 . V_64 )
V_132 |= V_135 | V_136 ;
F_7 ( & V_11 -> V_56 ) ;
return V_132 ;
}
static void F_76 ( struct V_1 * V_11 , int V_137 ,
struct V_138 * V_139 )
{
struct V_138 * V_140 ;
V_139 -> V_141 = V_97 ;
F_77 (walk, &info->e_wait_q[sr].list, list) {
if ( V_140 -> V_141 -> V_142 <= V_97 -> V_142 ) {
F_16 ( & V_139 -> V_59 , & V_140 -> V_59 ) ;
return;
}
}
F_16 ( & V_139 -> V_59 , & V_11 -> V_58 [ V_137 ] . V_59 ) ;
}
static int F_78 ( struct V_1 * V_11 , int V_137 ,
T_7 * V_143 , struct V_138 * V_139 )
{
int V_132 ;
signed long time ;
F_76 ( V_11 , V_137 , V_139 ) ;
for (; ; ) {
F_79 ( V_144 ) ;
F_7 ( & V_11 -> V_56 ) ;
time = F_80 ( V_143 , 0 ,
V_145 , V_146 ) ;
while ( V_139 -> V_147 == V_148 )
F_81 () ;
if ( V_139 -> V_147 == V_149 ) {
V_132 = 0 ;
goto V_150;
}
F_6 ( & V_11 -> V_56 ) ;
if ( V_139 -> V_147 == V_149 ) {
V_132 = 0 ;
goto V_112;
}
if ( F_82 ( V_97 ) ) {
V_132 = - V_151 ;
break;
}
if ( time == 0 ) {
V_132 = - V_152 ;
break;
}
}
F_24 ( & V_139 -> V_59 ) ;
V_112:
F_7 ( & V_11 -> V_56 ) ;
V_150:
return V_132 ;
}
static struct V_138 * F_83 (
struct V_1 * V_11 , int V_137 )
{
struct V_153 * V_154 ;
V_154 = V_11 -> V_58 [ V_137 ] . V_59 . V_155 ;
if ( V_154 == & V_11 -> V_58 [ V_137 ] . V_59 )
return NULL ;
return F_84 ( V_154 , struct V_138 , V_59 ) ;
}
static inline void F_85 ( struct V_156 * V_157 , char V_158 )
{
( ( char * ) V_157 -> V_77 ) [ V_159 - 1 ] = V_158 ;
}
static void F_86 ( struct V_1 * V_11 )
{
if ( V_11 -> V_60 &&
V_11 -> V_28 . V_29 == 1 ) {
struct V_160 V_161 ;
switch ( V_11 -> V_125 . V_126 ) {
case V_162 :
break;
case V_127 :
V_161 . V_163 = V_11 -> V_125 . V_128 ;
V_161 . V_164 = 0 ;
V_161 . V_165 = V_166 ;
V_161 . V_167 = V_11 -> V_125 . V_168 ;
F_87 () ;
V_161 . V_169 = F_88 ( V_97 ,
F_89 ( V_11 -> V_60 ) ) ;
V_161 . V_170 = F_90 ( V_11 -> V_61 , F_91 () ) ;
F_92 () ;
F_93 ( V_11 -> V_125 . V_128 ,
& V_161 , V_11 -> V_60 ) ;
break;
case V_171 :
F_85 ( V_11 -> V_172 , V_173 ) ;
F_94 ( V_11 -> V_174 , V_11 -> V_172 ) ;
break;
}
F_95 ( V_11 -> V_60 ) ;
F_96 ( V_11 -> V_61 ) ;
V_11 -> V_60 = NULL ;
V_11 -> V_61 = NULL ;
}
F_97 ( & V_11 -> V_57 ) ;
}
static int F_98 ( const struct V_175 T_3 * V_176 ,
T_7 * V_177 , struct V_175 * V_178 )
{
if ( F_99 ( V_178 , V_176 , sizeof( struct V_175 ) ) )
return - V_179 ;
if ( ! F_100 ( V_178 ) )
return - V_180 ;
* V_177 = F_101 ( * V_178 ) ;
return 0 ;
}
static void F_73 ( struct V_1 * V_11 )
{
if ( V_11 -> V_60 != NULL &&
V_11 -> V_125 . V_126 == V_171 ) {
F_85 ( V_11 -> V_172 , V_181 ) ;
F_94 ( V_11 -> V_174 , V_11 -> V_172 ) ;
}
F_95 ( V_11 -> V_60 ) ;
F_96 ( V_11 -> V_61 ) ;
V_11 -> V_60 = NULL ;
V_11 -> V_61 = NULL ;
}
static int F_102 ( struct V_4 * V_35 , struct V_37 * V_28 )
{
int V_51 ;
unsigned long V_182 ;
if ( V_28 -> V_64 <= 0 || V_28 -> V_67 <= 0 )
return - V_180 ;
if ( F_62 ( V_115 ) ) {
if ( V_28 -> V_64 > V_183 ||
V_28 -> V_67 > V_184 )
return - V_180 ;
} else {
if ( V_28 -> V_64 > V_35 -> V_65 ||
V_28 -> V_67 > V_35 -> V_68 )
return - V_180 ;
}
if ( V_28 -> V_67 > V_185 / V_28 -> V_64 )
return - V_186 ;
V_51 = V_28 -> V_64 * sizeof( struct V_9 ) +
F_35 (unsigned int, attr->mq_maxmsg, MQ_PRIO_MAX) *
sizeof( struct V_15 ) ;
V_182 = V_28 -> V_64 * V_28 -> V_67 ;
if ( V_182 + V_51 < V_182 )
return - V_186 ;
return 0 ;
}
static struct V_118 * F_103 ( struct V_4 * V_35 , struct V_91 * V_107 ,
struct V_91 * V_91 , int V_187 , T_1 V_36 ,
struct V_37 * V_28 )
{
const struct V_188 * V_188 = F_104 () ;
struct V_118 * V_189 ;
int V_40 ;
if ( V_28 ) {
V_40 = F_102 ( V_35 , V_28 ) ;
if ( V_40 )
goto V_150;
V_91 -> V_110 = V_28 ;
} else {
struct V_37 V_190 ;
V_190 . V_64 = F_34 ( V_35 -> V_65 ,
V_35 -> V_66 ) ;
V_190 . V_67 = F_34 ( V_35 -> V_68 ,
V_35 -> V_69 ) ;
V_40 = F_102 ( V_35 , & V_190 ) ;
if ( V_40 )
goto V_150;
}
V_36 &= ~ F_105 () ;
V_40 = F_106 ( V_35 -> V_191 ) ;
if ( V_40 )
goto V_150;
V_40 = F_107 ( V_107 -> V_117 , V_91 , V_36 , NULL ) ;
V_91 -> V_110 = NULL ;
if ( V_40 )
goto V_192;
V_189 = F_108 ( V_91 , V_35 -> V_191 , V_187 , V_188 ) ;
F_109 ( V_35 -> V_191 ) ;
return V_189 ;
V_192:
F_109 ( V_35 -> V_191 ) ;
V_150:
F_67 ( V_91 ) ;
F_110 ( V_35 -> V_191 ) ;
return F_41 ( V_40 ) ;
}
static struct V_118 * F_111 ( struct V_4 * V_35 ,
struct V_91 * V_91 , int V_187 )
{
int V_40 ;
const struct V_188 * V_188 = F_104 () ;
static const int V_193 [ V_194 ] = { V_195 , V_196 ,
V_195 | V_196 } ;
if ( ( V_187 & V_194 ) == ( V_197 | V_198 ) ) {
V_40 = - V_180 ;
goto V_41;
}
if ( F_112 ( V_91 -> V_117 , V_193 [ V_187 & V_194 ] ) ) {
V_40 = - V_111 ;
goto V_41;
}
return F_108 ( V_91 , V_35 -> V_191 , V_187 , V_188 ) ;
V_41:
F_67 ( V_91 ) ;
F_110 ( V_35 -> V_191 ) ;
return F_41 ( V_40 ) ;
}
static inline void F_113 ( struct V_1 * V_11 ,
struct V_9 * V_199 ,
struct V_138 * V_200 )
{
V_200 -> V_10 = V_199 ;
F_24 ( & V_200 -> V_59 ) ;
V_200 -> V_147 = V_148 ;
F_114 ( V_200 -> V_141 ) ;
F_115 () ;
V_200 -> V_147 = V_149 ;
}
static inline void F_116 ( struct V_1 * V_11 )
{
struct V_138 * V_201 = F_83 ( V_11 , V_202 ) ;
if ( ! V_201 ) {
F_117 ( & V_11 -> V_57 ) ;
return;
}
if ( F_8 ( V_201 -> V_10 , V_11 ) )
return;
F_24 ( & V_201 -> V_59 ) ;
V_201 -> V_147 = V_148 ;
F_114 ( V_201 -> V_141 ) ;
F_115 () ;
V_201 -> V_147 = V_149 ;
}
int F_118 ( struct V_4 * V_7 )
{
V_7 -> V_106 = 0 ;
V_7 -> V_114 = V_203 ;
V_7 -> V_65 = V_204 ;
V_7 -> V_68 = V_205 ;
V_7 -> V_66 = V_206 ;
V_7 -> V_69 = V_207 ;
V_7 -> V_191 = F_119 ( & V_208 , V_7 ) ;
if ( F_43 ( V_7 -> V_191 ) ) {
int V_41 = F_44 ( V_7 -> V_191 ) ;
V_7 -> V_191 = NULL ;
return V_41 ;
}
return 0 ;
}
void F_120 ( struct V_4 * V_7 )
{
V_7 -> V_191 -> V_209 -> V_6 = NULL ;
}
void F_121 ( struct V_4 * V_7 )
{
F_122 ( V_7 -> V_191 ) ;
}
static int T_8 F_123 ( void )
{
int error ;
V_101 = F_124 ( L_7 ,
sizeof( struct V_1 ) , 0 ,
V_210 , F_48 ) ;
if ( V_101 == NULL )
return - V_25 ;
V_211 = F_125 () ;
error = F_126 ( & V_208 ) ;
if ( error )
goto V_212;
F_32 ( & V_8 ) ;
error = F_118 ( & V_213 ) ;
if ( error )
goto V_214;
return 0 ;
V_214:
F_127 ( & V_208 ) ;
V_212:
if ( V_211 )
F_128 ( V_211 ) ;
F_129 ( V_101 ) ;
return error ;
}
