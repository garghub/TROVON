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
static struct V_2 * F_8 ( struct V_9 * V_10 ,
struct V_4 * V_11 , T_1 V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 () ;
struct V_2 * V_2 ;
int V_17 = - V_18 ;
V_2 = F_10 ( V_10 ) ;
if ( ! V_2 )
goto V_19;
V_2 -> V_20 = F_11 () ;
V_2 -> V_21 = V_12 ;
V_2 -> V_22 = F_12 () ;
V_2 -> V_23 = F_13 () ;
V_2 -> V_24 = V_2 -> V_25 = V_2 -> V_26 = V_27 ;
if ( F_14 ( V_12 ) ) {
struct V_1 * V_28 ;
unsigned long V_29 , V_30 ;
V_2 -> V_31 = & V_32 ;
V_2 -> V_33 = V_34 ;
V_28 = F_1 ( V_2 ) ;
F_15 ( & V_28 -> V_35 ) ;
F_16 ( & V_28 -> V_36 ) ;
F_17 ( & V_28 -> V_37 [ 0 ] . V_38 ) ;
F_17 ( & V_28 -> V_37 [ 1 ] . V_38 ) ;
V_28 -> V_39 = NULL ;
V_28 -> V_40 = 0 ;
V_28 -> V_41 = NULL ;
memset ( & V_28 -> V_14 , 0 , sizeof( V_28 -> V_14 ) ) ;
V_28 -> V_14 . V_42 = V_11 -> V_43 ;
V_28 -> V_14 . V_44 = V_11 -> V_45 ;
if ( V_14 ) {
V_28 -> V_14 . V_42 = V_14 -> V_42 ;
V_28 -> V_14 . V_44 = V_14 -> V_44 ;
}
V_30 = V_28 -> V_14 . V_42 * sizeof( struct V_46 * ) ;
V_28 -> V_47 = F_18 ( V_30 , V_48 ) ;
if ( ! V_28 -> V_47 )
goto V_49;
V_29 = ( V_30 +
( V_28 -> V_14 . V_42 * V_28 -> V_14 . V_44 ) ) ;
F_6 ( & V_8 ) ;
if ( V_16 -> V_29 + V_29 < V_16 -> V_29 ||
V_16 -> V_29 + V_29 > F_19 ( V_50 ) ) {
F_7 ( & V_8 ) ;
V_17 = - V_51 ;
goto V_49;
}
V_16 -> V_29 += V_29 ;
F_7 ( & V_8 ) ;
V_28 -> V_41 = F_20 ( V_16 ) ;
} else if ( F_21 ( V_12 ) ) {
F_22 ( V_2 ) ;
V_2 -> V_33 = 2 * V_52 ;
V_2 -> V_53 = & V_54 ;
V_2 -> V_31 = & V_55 ;
}
return V_2 ;
V_49:
F_23 ( V_2 ) ;
V_19:
return F_24 ( V_17 ) ;
}
static int F_25 ( struct V_9 * V_10 , void * V_56 , int V_57 )
{
struct V_2 * V_2 ;
struct V_4 * V_7 = V_56 ;
int error ;
V_10 -> V_58 = V_59 ;
V_10 -> V_60 = V_61 ;
V_10 -> V_62 = V_63 ;
V_10 -> V_64 = & V_65 ;
V_2 = F_8 ( V_10 , V_7 , V_66 | V_67 | V_68 ,
NULL ) ;
if ( F_26 ( V_2 ) ) {
error = F_27 ( V_2 ) ;
goto V_69;
}
V_10 -> V_70 = F_28 ( V_2 ) ;
if ( ! V_10 -> V_70 ) {
F_23 ( V_2 ) ;
error = - V_18 ;
goto V_69;
}
error = 0 ;
V_69:
return error ;
}
static struct V_71 * F_29 ( struct V_72 * V_73 ,
int V_74 , const char * V_75 ,
void * V_56 )
{
if ( ! ( V_74 & V_76 ) )
V_56 = V_77 -> V_78 -> V_11 ;
return F_30 ( V_73 , V_74 , V_56 , F_25 ) ;
}
static void F_31 ( void * V_79 )
{
struct V_1 * V_80 = (struct V_1 * ) V_79 ;
F_32 ( & V_80 -> V_3 ) ;
}
static struct V_2 * F_33 ( struct V_9 * V_10 )
{
struct V_1 * V_81 ;
V_81 = F_34 ( V_82 , V_48 ) ;
if ( ! V_81 )
return NULL ;
return & V_81 -> V_3 ;
}
static void F_35 ( struct V_83 * V_84 )
{
struct V_2 * V_2 = F_2 ( V_84 , struct V_2 , V_85 ) ;
F_36 ( V_82 , F_1 ( V_2 ) ) ;
}
static void F_37 ( struct V_2 * V_2 )
{
F_38 ( & V_2 -> V_85 , F_35 ) ;
}
static void F_39 ( struct V_2 * V_2 )
{
struct V_1 * V_28 ;
struct V_15 * V_41 ;
unsigned long V_29 ;
int V_86 ;
struct V_4 * V_11 ;
F_40 ( V_2 ) ;
if ( F_21 ( V_2 -> V_21 ) )
return;
V_11 = F_5 ( V_2 ) ;
V_28 = F_1 ( V_2 ) ;
F_6 ( & V_28 -> V_35 ) ;
for ( V_86 = 0 ; V_86 < V_28 -> V_14 . V_87 ; V_86 ++ )
F_41 ( V_28 -> V_47 [ V_86 ] ) ;
F_42 ( V_28 -> V_47 ) ;
F_7 ( & V_28 -> V_35 ) ;
V_29 = V_28 -> V_14 . V_42 * ( sizeof( struct V_46 * )
+ V_28 -> V_14 . V_44 ) ;
V_41 = V_28 -> V_41 ;
if ( V_41 ) {
F_6 ( & V_8 ) ;
V_41 -> V_29 -= V_29 ;
if ( V_11 )
V_11 -> V_88 -- ;
F_7 ( & V_8 ) ;
F_43 ( V_41 ) ;
}
if ( V_11 )
F_44 ( V_11 ) ;
}
static int F_45 ( struct V_2 * V_89 , struct V_71 * V_71 ,
T_1 V_12 , struct V_90 * V_91 )
{
struct V_2 * V_2 ;
struct V_13 * V_14 = V_71 -> V_92 ;
int error ;
struct V_4 * V_11 ;
F_6 ( & V_8 ) ;
V_11 = F_3 ( V_89 ) ;
if ( ! V_11 ) {
error = - V_93 ;
goto V_94;
}
if ( V_11 -> V_88 >= V_11 -> V_95 &&
! F_46 ( V_96 ) ) {
error = - V_97 ;
goto V_94;
}
V_11 -> V_88 ++ ;
F_7 ( & V_8 ) ;
V_2 = F_8 ( V_89 -> V_5 , V_11 , V_12 , V_14 ) ;
if ( F_26 ( V_2 ) ) {
error = F_27 ( V_2 ) ;
F_6 ( & V_8 ) ;
V_11 -> V_88 -- ;
goto V_94;
}
F_44 ( V_11 ) ;
V_89 -> V_33 += V_52 ;
V_89 -> V_25 = V_89 -> V_24 = V_89 -> V_26 = V_27 ;
F_47 ( V_71 , V_2 ) ;
F_48 ( V_71 ) ;
return 0 ;
V_94:
F_7 ( & V_8 ) ;
if ( V_11 )
F_44 ( V_11 ) ;
return error ;
}
static int F_49 ( struct V_2 * V_89 , struct V_71 * V_71 )
{
struct V_2 * V_2 = V_71 -> V_98 ;
V_89 -> V_25 = V_89 -> V_24 = V_89 -> V_26 = V_27 ;
V_89 -> V_33 -= V_52 ;
F_50 ( V_2 ) ;
F_51 ( V_71 ) ;
return 0 ;
}
static T_2 F_52 ( struct V_99 * V_100 , char T_3 * V_101 ,
T_4 V_102 , T_5 * V_103 )
{
struct V_1 * V_28 = F_1 ( V_100 -> V_104 . V_71 -> V_98 ) ;
char V_105 [ V_34 ] ;
T_2 V_17 ;
F_6 ( & V_28 -> V_35 ) ;
snprintf ( V_105 , sizeof( V_105 ) ,
L_1 ,
V_28 -> V_40 ,
V_28 -> V_39 ? V_28 -> V_106 . V_107 : 0 ,
( V_28 -> V_39 &&
V_28 -> V_106 . V_107 == V_108 ) ?
V_28 -> V_106 . V_109 : 0 ,
F_53 ( V_28 -> V_39 ) ) ;
F_7 ( & V_28 -> V_35 ) ;
V_105 [ sizeof( V_105 ) - 1 ] = '\0' ;
V_17 = F_54 ( V_101 , V_102 , V_103 , V_105 ,
strlen ( V_105 ) ) ;
if ( V_17 <= 0 )
return V_17 ;
V_100 -> V_104 . V_71 -> V_98 -> V_26 = V_100 -> V_104 . V_71 -> V_98 -> V_25 = V_27 ;
return V_17 ;
}
static int F_55 ( struct V_99 * V_100 , T_6 V_110 )
{
struct V_1 * V_28 = F_1 ( V_100 -> V_104 . V_71 -> V_98 ) ;
F_6 ( & V_28 -> V_35 ) ;
if ( F_56 ( V_77 ) == V_28 -> V_39 )
F_57 ( V_28 ) ;
F_7 ( & V_28 -> V_35 ) ;
return 0 ;
}
static unsigned int F_58 ( struct V_99 * V_100 , struct V_111 * V_112 )
{
struct V_1 * V_28 = F_1 ( V_100 -> V_104 . V_71 -> V_98 ) ;
int V_113 = 0 ;
F_59 ( V_100 , & V_28 -> V_36 , V_112 ) ;
F_6 ( & V_28 -> V_35 ) ;
if ( V_28 -> V_14 . V_87 )
V_113 = V_114 | V_115 ;
if ( V_28 -> V_14 . V_87 < V_28 -> V_14 . V_42 )
V_113 |= V_116 | V_117 ;
F_7 ( & V_28 -> V_35 ) ;
return V_113 ;
}
static void F_60 ( struct V_1 * V_28 , int V_118 ,
struct V_119 * V_120 )
{
struct V_119 * V_121 ;
V_120 -> V_122 = V_77 ;
F_61 (walk, &info->e_wait_q[sr].list, list) {
if ( V_121 -> V_122 -> V_123 <= V_77 -> V_123 ) {
F_62 ( & V_120 -> V_38 , & V_121 -> V_38 ) ;
return;
}
}
F_62 ( & V_120 -> V_38 , & V_28 -> V_37 [ V_118 ] . V_38 ) ;
}
static int F_63 ( struct V_1 * V_28 , int V_118 ,
T_7 * V_124 , struct V_119 * V_120 )
{
int V_113 ;
signed long time ;
F_60 ( V_28 , V_118 , V_120 ) ;
for (; ; ) {
F_64 ( V_125 ) ;
F_7 ( & V_28 -> V_35 ) ;
time = F_65 ( V_124 , 0 ,
V_126 , V_127 ) ;
while ( V_120 -> V_128 == V_129 )
F_66 () ;
if ( V_120 -> V_128 == V_130 ) {
V_113 = 0 ;
goto V_69;
}
F_6 ( & V_28 -> V_35 ) ;
if ( V_120 -> V_128 == V_130 ) {
V_113 = 0 ;
goto V_94;
}
if ( F_67 ( V_77 ) ) {
V_113 = - V_131 ;
break;
}
if ( time == 0 ) {
V_113 = - V_132 ;
break;
}
}
F_68 ( & V_120 -> V_38 ) ;
V_94:
F_7 ( & V_28 -> V_35 ) ;
V_69:
return V_113 ;
}
static struct V_119 * F_69 (
struct V_1 * V_28 , int V_118 )
{
struct V_133 * V_134 ;
V_134 = V_28 -> V_37 [ V_118 ] . V_38 . V_135 ;
if ( V_134 == & V_28 -> V_37 [ V_118 ] . V_38 )
return NULL ;
return F_70 ( V_134 , struct V_119 , V_38 ) ;
}
static void F_71 ( struct V_46 * V_134 , struct V_1 * V_28 )
{
int V_136 ;
V_136 = V_28 -> V_14 . V_87 - 1 ;
while ( V_136 >= 0 && V_28 -> V_47 [ V_136 ] -> V_137 >= V_134 -> V_137 ) {
V_28 -> V_47 [ V_136 + 1 ] = V_28 -> V_47 [ V_136 ] ;
V_136 -- ;
}
V_28 -> V_14 . V_87 ++ ;
V_28 -> V_40 += V_134 -> V_138 ;
V_28 -> V_47 [ V_136 + 1 ] = V_134 ;
}
static inline struct V_46 * F_72 ( struct V_1 * V_28 )
{
V_28 -> V_40 -= V_28 -> V_47 [ -- V_28 -> V_14 . V_87 ] -> V_138 ;
return V_28 -> V_47 [ V_28 -> V_14 . V_87 ] ;
}
static inline void F_73 ( struct V_139 * V_140 , char V_141 )
{
( ( char * ) V_140 -> V_56 ) [ V_142 - 1 ] = V_141 ;
}
static void F_74 ( struct V_1 * V_28 )
{
if ( V_28 -> V_39 &&
V_28 -> V_14 . V_87 == 1 ) {
struct V_143 V_144 ;
switch ( V_28 -> V_106 . V_107 ) {
case V_145 :
break;
case V_108 :
V_144 . V_146 = V_28 -> V_106 . V_109 ;
V_144 . V_147 = 0 ;
V_144 . V_148 = V_149 ;
V_144 . V_150 = V_28 -> V_106 . V_151 ;
F_75 () ;
V_144 . V_152 = F_76 ( V_77 ,
F_77 ( V_28 -> V_39 ) ) ;
V_144 . V_153 = F_78 ( V_28 -> V_41 -> V_154 ,
F_79 () , F_80 () ) ;
F_81 () ;
F_82 ( V_28 -> V_106 . V_109 ,
& V_144 , V_28 -> V_39 ) ;
break;
case V_155 :
F_73 ( V_28 -> V_156 , V_157 ) ;
F_83 ( V_28 -> V_158 , V_28 -> V_156 ) ;
break;
}
F_84 ( V_28 -> V_39 ) ;
V_28 -> V_39 = NULL ;
}
F_85 ( & V_28 -> V_36 ) ;
}
static int F_86 ( const struct V_159 T_3 * V_160 ,
T_7 * V_161 , struct V_159 * V_162 )
{
if ( F_87 ( V_162 , V_160 , sizeof( struct V_159 ) ) )
return - V_163 ;
if ( ! F_88 ( V_162 ) )
return - V_164 ;
* V_161 = F_89 ( * V_162 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_28 )
{
if ( V_28 -> V_39 != NULL &&
V_28 -> V_106 . V_107 == V_155 ) {
F_73 ( V_28 -> V_156 , V_165 ) ;
F_83 ( V_28 -> V_158 , V_28 -> V_156 ) ;
}
F_84 ( V_28 -> V_39 ) ;
V_28 -> V_39 = NULL ;
}
static int F_90 ( struct V_4 * V_11 , struct V_13 * V_14 )
{
if ( V_14 -> V_42 <= 0 || V_14 -> V_44 <= 0 )
return 0 ;
if ( F_46 ( V_96 ) ) {
if ( V_14 -> V_42 > V_166 )
return 0 ;
} else {
if ( V_14 -> V_42 > V_11 -> V_43 ||
V_14 -> V_44 > V_11 -> V_45 )
return 0 ;
}
if ( V_14 -> V_44 > V_167 / V_14 -> V_42 )
return 0 ;
if ( ( unsigned long ) ( V_14 -> V_42 * ( V_14 -> V_44
+ sizeof ( struct V_46 * ) ) ) <
( unsigned long ) ( V_14 -> V_42 * V_14 -> V_44 ) )
return 0 ;
return 1 ;
}
static struct V_99 * F_91 ( struct V_4 * V_11 , struct V_71 * V_89 ,
struct V_71 * V_71 , int V_168 , T_1 V_12 ,
struct V_13 * V_14 )
{
const struct V_169 * V_169 = F_79 () ;
struct V_99 * V_170 ;
int V_17 ;
if ( V_14 ) {
if ( ! F_90 ( V_11 , V_14 ) ) {
V_17 = - V_164 ;
goto V_69;
}
V_71 -> V_92 = V_14 ;
}
V_12 &= ~ F_92 () ;
V_17 = F_93 ( V_11 -> V_171 ) ;
if ( V_17 )
goto V_69;
V_17 = F_94 ( V_89 -> V_98 , V_71 , V_12 , NULL ) ;
V_71 -> V_92 = NULL ;
if ( V_17 )
goto V_172;
V_170 = F_95 ( V_71 , V_11 -> V_171 , V_168 , V_169 ) ;
F_96 ( V_11 -> V_171 ) ;
return V_170 ;
V_172:
F_96 ( V_11 -> V_171 ) ;
V_69:
F_51 ( V_71 ) ;
F_97 ( V_11 -> V_171 ) ;
return F_24 ( V_17 ) ;
}
static struct V_99 * F_98 ( struct V_4 * V_11 ,
struct V_71 * V_71 , int V_168 )
{
int V_17 ;
const struct V_169 * V_169 = F_79 () ;
static const int V_173 [ V_174 ] = { V_175 , V_176 ,
V_175 | V_176 } ;
if ( ( V_168 & V_174 ) == ( V_177 | V_178 ) ) {
V_17 = - V_164 ;
goto V_19;
}
if ( F_99 ( V_71 -> V_98 , V_173 [ V_168 & V_174 ] ) ) {
V_17 = - V_93 ;
goto V_19;
}
return F_95 ( V_71 , V_11 -> V_171 , V_168 , V_169 ) ;
V_19:
F_51 ( V_71 ) ;
F_97 ( V_11 -> V_171 ) ;
return F_24 ( V_17 ) ;
}
static inline void F_100 ( struct V_1 * V_28 ,
struct V_46 * V_179 ,
struct V_119 * V_180 )
{
V_180 -> V_181 = V_179 ;
F_68 ( & V_180 -> V_38 ) ;
V_180 -> V_128 = V_129 ;
F_101 ( V_180 -> V_122 ) ;
F_102 () ;
V_180 -> V_128 = V_130 ;
}
static inline void F_103 ( struct V_1 * V_28 )
{
struct V_119 * V_182 = F_69 ( V_28 , V_183 ) ;
if ( ! V_182 ) {
F_104 ( & V_28 -> V_36 ) ;
return;
}
F_71 ( V_182 -> V_181 , V_28 ) ;
F_68 ( & V_182 -> V_38 ) ;
V_182 -> V_128 = V_129 ;
F_101 ( V_182 -> V_122 ) ;
F_102 () ;
V_182 -> V_128 = V_130 ;
}
int F_105 ( struct V_4 * V_7 )
{
V_7 -> V_88 = 0 ;
V_7 -> V_95 = V_184 ;
V_7 -> V_43 = V_185 ;
V_7 -> V_45 = V_186 ;
V_7 -> V_171 = F_106 ( & V_187 , V_7 ) ;
if ( F_26 ( V_7 -> V_171 ) ) {
int V_19 = F_27 ( V_7 -> V_171 ) ;
V_7 -> V_171 = NULL ;
return V_19 ;
}
return 0 ;
}
void F_107 ( struct V_4 * V_7 )
{
V_7 -> V_171 -> V_188 -> V_6 = NULL ;
}
void F_108 ( struct V_4 * V_7 )
{
F_109 ( V_7 -> V_171 ) ;
}
static int T_8 F_110 ( void )
{
int error ;
V_82 = F_111 ( L_2 ,
sizeof( struct V_1 ) , 0 ,
V_189 , F_31 ) ;
if ( V_82 == NULL )
return - V_18 ;
V_190 = F_112 () ;
error = F_113 ( & V_187 ) ;
if ( error )
goto V_191;
F_15 ( & V_8 ) ;
error = F_105 ( & V_192 ) ;
if ( error )
goto V_193;
return 0 ;
V_193:
F_114 ( & V_187 ) ;
V_191:
if ( V_190 )
F_115 ( V_190 ) ;
F_116 ( V_82 ) ;
return error ;
}
