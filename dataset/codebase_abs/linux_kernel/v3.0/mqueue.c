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
struct V_4 * V_11 , int V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_9 () ;
struct V_2 * V_2 ;
V_2 = F_10 ( V_10 ) ;
if ( V_2 ) {
V_2 -> V_17 = F_11 () ;
V_2 -> V_18 = V_12 ;
V_2 -> V_19 = F_12 () ;
V_2 -> V_20 = F_13 () ;
V_2 -> V_21 = V_2 -> V_22 = V_2 -> V_23 =
V_24 ;
if ( F_14 ( V_12 ) ) {
struct V_1 * V_25 ;
struct V_26 * V_27 = V_28 ;
unsigned long V_29 , V_30 ;
V_2 -> V_31 = & V_32 ;
V_2 -> V_33 = V_34 ;
V_25 = F_1 ( V_2 ) ;
F_15 ( & V_25 -> V_35 ) ;
F_16 ( & V_25 -> V_36 ) ;
F_17 ( & V_25 -> V_37 [ 0 ] . V_38 ) ;
F_17 ( & V_25 -> V_37 [ 1 ] . V_38 ) ;
V_25 -> V_39 = NULL ;
V_25 -> V_40 = 0 ;
V_25 -> V_41 = NULL ;
memset ( & V_25 -> V_14 , 0 , sizeof( V_25 -> V_14 ) ) ;
V_25 -> V_14 . V_42 = V_11 -> V_43 ;
V_25 -> V_14 . V_44 = V_11 -> V_45 ;
if ( V_14 ) {
V_25 -> V_14 . V_42 = V_14 -> V_42 ;
V_25 -> V_14 . V_44 = V_14 -> V_44 ;
}
V_30 = V_25 -> V_14 . V_42 * sizeof( struct V_46 * ) ;
V_25 -> V_47 = F_18 ( V_30 , V_48 ) ;
if ( ! V_25 -> V_47 )
goto V_49;
V_29 = ( V_30 +
( V_25 -> V_14 . V_42 * V_25 -> V_14 . V_44 ) ) ;
F_6 ( & V_8 ) ;
if ( V_16 -> V_29 + V_29 < V_16 -> V_29 ||
V_16 -> V_29 + V_29 >
F_19 ( V_27 , V_50 ) ) {
F_7 ( & V_8 ) ;
goto V_49;
}
V_16 -> V_29 += V_29 ;
F_7 ( & V_8 ) ;
V_25 -> V_41 = F_20 ( V_16 ) ;
} else if ( F_21 ( V_12 ) ) {
F_22 ( V_2 ) ;
V_2 -> V_33 = 2 * V_51 ;
V_2 -> V_52 = & V_53 ;
V_2 -> V_31 = & V_54 ;
}
}
return V_2 ;
V_49:
F_23 ( V_2 ) ;
return NULL ;
}
static int F_24 ( struct V_9 * V_10 , void * V_55 , int V_56 )
{
struct V_2 * V_2 ;
struct V_4 * V_7 = V_55 ;
int error ;
V_10 -> V_57 = V_58 ;
V_10 -> V_59 = V_60 ;
V_10 -> V_61 = V_62 ;
V_10 -> V_63 = & V_64 ;
V_2 = F_8 ( V_10 , V_7 , V_65 | V_66 | V_67 ,
NULL ) ;
if ( ! V_2 ) {
error = - V_68 ;
goto V_69;
}
V_10 -> V_70 = F_25 ( V_2 ) ;
if ( ! V_10 -> V_70 ) {
F_23 ( V_2 ) ;
error = - V_68 ;
goto V_69;
}
error = 0 ;
V_69:
return error ;
}
static struct V_71 * F_26 ( struct V_72 * V_73 ,
int V_74 , const char * V_75 ,
void * V_55 )
{
if ( ! ( V_74 & V_76 ) )
V_55 = V_28 -> V_77 -> V_11 ;
return F_27 ( V_73 , V_74 , V_55 , F_24 ) ;
}
static void F_28 ( void * V_78 )
{
struct V_1 * V_27 = (struct V_1 * ) V_78 ;
F_29 ( & V_27 -> V_3 ) ;
}
static struct V_2 * F_30 ( struct V_9 * V_10 )
{
struct V_1 * V_79 ;
V_79 = F_31 ( V_80 , V_48 ) ;
if ( ! V_79 )
return NULL ;
return & V_79 -> V_3 ;
}
static void F_32 ( struct V_81 * V_82 )
{
struct V_2 * V_2 = F_2 ( V_82 , struct V_2 , V_83 ) ;
F_17 ( & V_2 -> V_84 ) ;
F_33 ( V_80 , F_1 ( V_2 ) ) ;
}
static void F_34 ( struct V_2 * V_2 )
{
F_35 ( & V_2 -> V_83 , F_32 ) ;
}
static void F_36 ( struct V_2 * V_2 )
{
struct V_1 * V_25 ;
struct V_15 * V_41 ;
unsigned long V_29 ;
int V_85 ;
struct V_4 * V_11 ;
F_37 ( V_2 ) ;
if ( F_21 ( V_2 -> V_18 ) )
return;
V_11 = F_5 ( V_2 ) ;
V_25 = F_1 ( V_2 ) ;
F_6 ( & V_25 -> V_35 ) ;
for ( V_85 = 0 ; V_85 < V_25 -> V_14 . V_86 ; V_85 ++ )
F_38 ( V_25 -> V_47 [ V_85 ] ) ;
F_39 ( V_25 -> V_47 ) ;
F_7 ( & V_25 -> V_35 ) ;
V_29 = V_25 -> V_14 . V_42 * ( sizeof( struct V_46 * )
+ V_25 -> V_14 . V_44 ) ;
V_41 = V_25 -> V_41 ;
if ( V_41 ) {
F_6 ( & V_8 ) ;
V_41 -> V_29 -= V_29 ;
if ( V_11 )
V_11 -> V_87 -- ;
F_7 ( & V_8 ) ;
F_40 ( V_41 ) ;
}
if ( V_11 )
F_41 ( V_11 ) ;
}
static int F_42 ( struct V_2 * V_88 , struct V_71 * V_71 ,
int V_12 , struct V_89 * V_90 )
{
struct V_2 * V_2 ;
struct V_13 * V_14 = V_71 -> V_91 ;
int error ;
struct V_4 * V_11 ;
F_6 ( & V_8 ) ;
V_11 = F_3 ( V_88 ) ;
if ( ! V_11 ) {
error = - V_92 ;
goto V_93;
}
if ( V_11 -> V_87 >= V_11 -> V_94 &&
! F_43 ( V_95 ) ) {
error = - V_96 ;
goto V_93;
}
V_11 -> V_87 ++ ;
F_7 ( & V_8 ) ;
V_2 = F_8 ( V_88 -> V_5 , V_11 , V_12 , V_14 ) ;
if ( ! V_2 ) {
error = - V_68 ;
F_6 ( & V_8 ) ;
V_11 -> V_87 -- ;
goto V_93;
}
F_41 ( V_11 ) ;
V_88 -> V_33 += V_51 ;
V_88 -> V_22 = V_88 -> V_21 = V_88 -> V_23 = V_24 ;
F_44 ( V_71 , V_2 ) ;
F_45 ( V_71 ) ;
return 0 ;
V_93:
F_7 ( & V_8 ) ;
if ( V_11 )
F_41 ( V_11 ) ;
return error ;
}
static int F_46 ( struct V_2 * V_88 , struct V_71 * V_71 )
{
struct V_2 * V_2 = V_71 -> V_97 ;
V_88 -> V_22 = V_88 -> V_21 = V_88 -> V_23 = V_24 ;
V_88 -> V_33 -= V_51 ;
F_47 ( V_2 ) ;
F_48 ( V_71 ) ;
return 0 ;
}
static T_1 F_49 ( struct V_98 * V_99 , char T_2 * V_100 ,
T_3 V_101 , T_4 * V_102 )
{
struct V_1 * V_25 = F_1 ( V_99 -> V_103 . V_71 -> V_97 ) ;
char V_104 [ V_34 ] ;
T_1 V_105 ;
F_6 ( & V_25 -> V_35 ) ;
snprintf ( V_104 , sizeof( V_104 ) ,
L_1 ,
V_25 -> V_40 ,
V_25 -> V_39 ? V_25 -> V_106 . V_107 : 0 ,
( V_25 -> V_39 &&
V_25 -> V_106 . V_107 == V_108 ) ?
V_25 -> V_106 . V_109 : 0 ,
F_50 ( V_25 -> V_39 ) ) ;
F_7 ( & V_25 -> V_35 ) ;
V_104 [ sizeof( V_104 ) - 1 ] = '\0' ;
V_105 = F_51 ( V_100 , V_101 , V_102 , V_104 ,
strlen ( V_104 ) ) ;
if ( V_105 <= 0 )
return V_105 ;
V_99 -> V_103 . V_71 -> V_97 -> V_23 = V_99 -> V_103 . V_71 -> V_97 -> V_22 = V_24 ;
return V_105 ;
}
static int F_52 ( struct V_98 * V_99 , T_5 V_110 )
{
struct V_1 * V_25 = F_1 ( V_99 -> V_103 . V_71 -> V_97 ) ;
F_6 ( & V_25 -> V_35 ) ;
if ( F_53 ( V_28 ) == V_25 -> V_39 )
F_54 ( V_25 ) ;
F_7 ( & V_25 -> V_35 ) ;
return 0 ;
}
static unsigned int F_55 ( struct V_98 * V_99 , struct V_111 * V_112 )
{
struct V_1 * V_25 = F_1 ( V_99 -> V_103 . V_71 -> V_97 ) ;
int V_113 = 0 ;
F_56 ( V_99 , & V_25 -> V_36 , V_112 ) ;
F_6 ( & V_25 -> V_35 ) ;
if ( V_25 -> V_14 . V_86 )
V_113 = V_114 | V_115 ;
if ( V_25 -> V_14 . V_86 < V_25 -> V_14 . V_42 )
V_113 |= V_116 | V_117 ;
F_7 ( & V_25 -> V_35 ) ;
return V_113 ;
}
static void F_57 ( struct V_1 * V_25 , int V_118 ,
struct V_119 * V_120 )
{
struct V_119 * V_121 ;
V_120 -> V_122 = V_28 ;
F_58 (walk, &info->e_wait_q[sr].list, list) {
if ( V_121 -> V_122 -> V_123 <= V_28 -> V_123 ) {
F_59 ( & V_120 -> V_38 , & V_121 -> V_38 ) ;
return;
}
}
F_59 ( & V_120 -> V_38 , & V_25 -> V_37 [ V_118 ] . V_38 ) ;
}
static int F_60 ( struct V_1 * V_25 , int V_118 ,
T_6 * V_124 , struct V_119 * V_120 )
{
int V_113 ;
signed long time ;
F_57 ( V_25 , V_118 , V_120 ) ;
for (; ; ) {
F_61 ( V_125 ) ;
F_7 ( & V_25 -> V_35 ) ;
time = F_62 ( V_124 ,
V_126 , 0 , V_127 ) ;
while ( V_120 -> V_128 == V_129 )
F_63 () ;
if ( V_120 -> V_128 == V_130 ) {
V_113 = 0 ;
goto V_69;
}
F_6 ( & V_25 -> V_35 ) ;
if ( V_120 -> V_128 == V_130 ) {
V_113 = 0 ;
goto V_93;
}
if ( F_64 ( V_28 ) ) {
V_113 = - V_131 ;
break;
}
if ( time == 0 ) {
V_113 = - V_132 ;
break;
}
}
F_65 ( & V_120 -> V_38 ) ;
V_93:
F_7 ( & V_25 -> V_35 ) ;
V_69:
return V_113 ;
}
static struct V_119 * F_66 (
struct V_1 * V_25 , int V_118 )
{
struct V_133 * V_134 ;
V_134 = V_25 -> V_37 [ V_118 ] . V_38 . V_135 ;
if ( V_134 == & V_25 -> V_37 [ V_118 ] . V_38 )
return NULL ;
return F_67 ( V_134 , struct V_119 , V_38 ) ;
}
static void F_68 ( struct V_46 * V_134 , struct V_1 * V_25 )
{
int V_136 ;
V_136 = V_25 -> V_14 . V_86 - 1 ;
while ( V_136 >= 0 && V_25 -> V_47 [ V_136 ] -> V_137 >= V_134 -> V_137 ) {
V_25 -> V_47 [ V_136 + 1 ] = V_25 -> V_47 [ V_136 ] ;
V_136 -- ;
}
V_25 -> V_14 . V_86 ++ ;
V_25 -> V_40 += V_134 -> V_138 ;
V_25 -> V_47 [ V_136 + 1 ] = V_134 ;
}
static inline struct V_46 * F_69 ( struct V_1 * V_25 )
{
V_25 -> V_40 -= V_25 -> V_47 [ -- V_25 -> V_14 . V_86 ] -> V_138 ;
return V_25 -> V_47 [ V_25 -> V_14 . V_86 ] ;
}
static inline void F_70 ( struct V_139 * V_140 , char V_141 )
{
( ( char * ) V_140 -> V_55 ) [ V_142 - 1 ] = V_141 ;
}
static void F_71 ( struct V_1 * V_25 )
{
if ( V_25 -> V_39 &&
V_25 -> V_14 . V_86 == 1 ) {
struct V_143 V_144 ;
switch ( V_25 -> V_106 . V_107 ) {
case V_145 :
break;
case V_108 :
V_144 . V_146 = V_25 -> V_106 . V_109 ;
V_144 . V_147 = 0 ;
V_144 . V_148 = V_149 ;
V_144 . V_150 = V_25 -> V_106 . V_151 ;
V_144 . V_152 = F_72 ( V_28 ,
F_73 ( V_25 -> V_39 ) ) ;
V_144 . V_153 = F_74 () ;
F_75 ( V_25 -> V_106 . V_109 ,
& V_144 , V_25 -> V_39 ) ;
break;
case V_154 :
F_70 ( V_25 -> V_155 , V_156 ) ;
F_76 ( V_25 -> V_157 , V_25 -> V_155 ) ;
break;
}
F_77 ( V_25 -> V_39 ) ;
V_25 -> V_39 = NULL ;
}
F_78 ( & V_25 -> V_36 ) ;
}
static int F_79 ( const struct V_158 T_2 * V_159 ,
T_6 * V_160 , struct V_158 * V_161 )
{
if ( F_80 ( V_161 , V_159 , sizeof( struct V_158 ) ) )
return - V_162 ;
if ( ! F_81 ( V_161 ) )
return - V_163 ;
* V_160 = F_82 ( * V_161 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_25 )
{
if ( V_25 -> V_39 != NULL &&
V_25 -> V_106 . V_107 == V_154 ) {
F_70 ( V_25 -> V_155 , V_164 ) ;
F_76 ( V_25 -> V_157 , V_25 -> V_155 ) ;
}
F_77 ( V_25 -> V_39 ) ;
V_25 -> V_39 = NULL ;
}
static int F_83 ( struct V_4 * V_11 , struct V_13 * V_14 )
{
if ( V_14 -> V_42 <= 0 || V_14 -> V_44 <= 0 )
return 0 ;
if ( F_43 ( V_95 ) ) {
if ( V_14 -> V_42 > V_165 )
return 0 ;
} else {
if ( V_14 -> V_42 > V_11 -> V_43 ||
V_14 -> V_44 > V_11 -> V_45 )
return 0 ;
}
if ( V_14 -> V_44 > V_166 / V_14 -> V_42 )
return 0 ;
if ( ( unsigned long ) ( V_14 -> V_42 * ( V_14 -> V_44
+ sizeof ( struct V_46 * ) ) ) <
( unsigned long ) ( V_14 -> V_42 * V_14 -> V_44 ) )
return 0 ;
return 1 ;
}
static struct V_98 * F_84 ( struct V_4 * V_11 , struct V_71 * V_88 ,
struct V_71 * V_71 , int V_167 , T_7 V_12 ,
struct V_13 * V_14 )
{
const struct V_168 * V_168 = F_85 () ;
struct V_98 * V_169 ;
int V_105 ;
if ( V_14 ) {
if ( ! F_83 ( V_11 , V_14 ) ) {
V_105 = - V_163 ;
goto V_69;
}
V_71 -> V_91 = V_14 ;
}
V_12 &= ~ F_86 () ;
V_105 = F_87 ( V_11 -> V_170 ) ;
if ( V_105 )
goto V_69;
V_105 = F_88 ( V_88 -> V_97 , V_71 , V_12 , NULL ) ;
V_71 -> V_91 = NULL ;
if ( V_105 )
goto V_171;
V_169 = F_89 ( V_71 , V_11 -> V_170 , V_167 , V_168 ) ;
F_90 ( V_11 -> V_170 ) ;
return V_169 ;
V_171:
F_90 ( V_11 -> V_170 ) ;
V_69:
F_48 ( V_71 ) ;
F_91 ( V_11 -> V_170 ) ;
return F_92 ( V_105 ) ;
}
static struct V_98 * F_93 ( struct V_4 * V_11 ,
struct V_71 * V_71 , int V_167 )
{
int V_105 ;
const struct V_168 * V_168 = F_85 () ;
static const int V_172 [ V_173 ] = { V_174 , V_175 ,
V_174 | V_175 } ;
if ( ( V_167 & V_173 ) == ( V_176 | V_177 ) ) {
V_105 = - V_163 ;
goto V_178;
}
if ( F_94 ( V_71 -> V_97 , V_172 [ V_167 & V_173 ] ) ) {
V_105 = - V_92 ;
goto V_178;
}
return F_89 ( V_71 , V_11 -> V_170 , V_167 , V_168 ) ;
V_178:
F_48 ( V_71 ) ;
F_91 ( V_11 -> V_170 ) ;
return F_92 ( V_105 ) ;
}
static inline void F_95 ( struct V_1 * V_25 ,
struct V_46 * V_179 ,
struct V_119 * V_180 )
{
V_180 -> V_181 = V_179 ;
F_65 ( & V_180 -> V_38 ) ;
V_180 -> V_128 = V_129 ;
F_96 ( V_180 -> V_122 ) ;
F_97 () ;
V_180 -> V_128 = V_130 ;
}
static inline void F_98 ( struct V_1 * V_25 )
{
struct V_119 * V_182 = F_66 ( V_25 , V_183 ) ;
if ( ! V_182 ) {
F_99 ( & V_25 -> V_36 ) ;
return;
}
F_68 ( V_182 -> V_181 , V_25 ) ;
F_65 ( & V_182 -> V_38 ) ;
V_182 -> V_128 = V_129 ;
F_96 ( V_182 -> V_122 ) ;
F_97 () ;
V_182 -> V_128 = V_130 ;
}
int F_100 ( struct V_4 * V_7 )
{
V_7 -> V_87 = 0 ;
V_7 -> V_94 = V_184 ;
V_7 -> V_43 = V_185 ;
V_7 -> V_45 = V_186 ;
V_7 -> V_170 = F_101 ( & V_187 , V_7 ) ;
if ( F_102 ( V_7 -> V_170 ) ) {
int V_178 = F_103 ( V_7 -> V_170 ) ;
V_7 -> V_170 = NULL ;
return V_178 ;
}
return 0 ;
}
void F_104 ( struct V_4 * V_7 )
{
V_7 -> V_170 -> V_188 -> V_6 = NULL ;
}
void F_105 ( struct V_4 * V_7 )
{
F_91 ( V_7 -> V_170 ) ;
}
static int T_8 F_106 ( void )
{
int error ;
V_80 = F_107 ( L_2 ,
sizeof( struct V_1 ) , 0 ,
V_189 , F_28 ) ;
if ( V_80 == NULL )
return - V_68 ;
V_190 = F_108 () ;
error = F_109 ( & V_187 ) ;
if ( error )
goto V_191;
F_15 ( & V_8 ) ;
V_192 . V_170 = F_101 ( & V_187 , & V_192 ) ;
if ( F_102 ( V_192 . V_170 ) ) {
error = F_103 ( V_192 . V_170 ) ;
goto V_193;
}
return 0 ;
V_193:
F_110 ( & V_187 ) ;
V_191:
if ( V_190 )
F_111 ( V_190 ) ;
F_112 ( V_80 ) ;
return error ;
}
