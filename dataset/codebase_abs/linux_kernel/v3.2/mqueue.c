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
struct V_29 * V_30 = V_31 ;
unsigned long V_32 , V_33 ;
V_2 -> V_34 = & V_35 ;
V_2 -> V_36 = V_37 ;
V_28 = F_1 ( V_2 ) ;
F_15 ( & V_28 -> V_38 ) ;
F_16 ( & V_28 -> V_39 ) ;
F_17 ( & V_28 -> V_40 [ 0 ] . V_41 ) ;
F_17 ( & V_28 -> V_40 [ 1 ] . V_41 ) ;
V_28 -> V_42 = NULL ;
V_28 -> V_43 = 0 ;
V_28 -> V_44 = NULL ;
memset ( & V_28 -> V_14 , 0 , sizeof( V_28 -> V_14 ) ) ;
V_28 -> V_14 . V_45 = V_11 -> V_46 ;
V_28 -> V_14 . V_47 = V_11 -> V_48 ;
if ( V_14 ) {
V_28 -> V_14 . V_45 = V_14 -> V_45 ;
V_28 -> V_14 . V_47 = V_14 -> V_47 ;
}
V_33 = V_28 -> V_14 . V_45 * sizeof( struct V_49 * ) ;
V_28 -> V_50 = F_18 ( V_33 , V_51 ) ;
if ( ! V_28 -> V_50 )
goto V_52;
V_32 = ( V_33 +
( V_28 -> V_14 . V_45 * V_28 -> V_14 . V_47 ) ) ;
F_6 ( & V_8 ) ;
if ( V_16 -> V_32 + V_32 < V_16 -> V_32 ||
V_16 -> V_32 + V_32 > F_19 ( V_30 , V_53 ) ) {
F_7 ( & V_8 ) ;
V_17 = - V_54 ;
goto V_52;
}
V_16 -> V_32 += V_32 ;
F_7 ( & V_8 ) ;
V_28 -> V_44 = F_20 ( V_16 ) ;
} else if ( F_21 ( V_12 ) ) {
F_22 ( V_2 ) ;
V_2 -> V_36 = 2 * V_55 ;
V_2 -> V_56 = & V_57 ;
V_2 -> V_34 = & V_58 ;
}
return V_2 ;
V_52:
F_23 ( V_2 ) ;
V_19:
return F_24 ( V_17 ) ;
}
static int F_25 ( struct V_9 * V_10 , void * V_59 , int V_60 )
{
struct V_2 * V_2 ;
struct V_4 * V_7 = V_59 ;
int error ;
V_10 -> V_61 = V_62 ;
V_10 -> V_63 = V_64 ;
V_10 -> V_65 = V_66 ;
V_10 -> V_67 = & V_68 ;
V_2 = F_8 ( V_10 , V_7 , V_69 | V_70 | V_71 ,
NULL ) ;
if ( F_26 ( V_2 ) ) {
error = F_27 ( V_2 ) ;
goto V_72;
}
V_10 -> V_73 = F_28 ( V_2 ) ;
if ( ! V_10 -> V_73 ) {
F_23 ( V_2 ) ;
error = - V_18 ;
goto V_72;
}
error = 0 ;
V_72:
return error ;
}
static struct V_74 * F_29 ( struct V_75 * V_76 ,
int V_77 , const char * V_78 ,
void * V_59 )
{
if ( ! ( V_77 & V_79 ) )
V_59 = V_31 -> V_80 -> V_11 ;
return F_30 ( V_76 , V_77 , V_59 , F_25 ) ;
}
static void F_31 ( void * V_81 )
{
struct V_1 * V_30 = (struct V_1 * ) V_81 ;
F_32 ( & V_30 -> V_3 ) ;
}
static struct V_2 * F_33 ( struct V_9 * V_10 )
{
struct V_1 * V_82 ;
V_82 = F_34 ( V_83 , V_51 ) ;
if ( ! V_82 )
return NULL ;
return & V_82 -> V_3 ;
}
static void F_35 ( struct V_84 * V_85 )
{
struct V_2 * V_2 = F_2 ( V_85 , struct V_2 , V_86 ) ;
F_17 ( & V_2 -> V_87 ) ;
F_36 ( V_83 , F_1 ( V_2 ) ) ;
}
static void F_37 ( struct V_2 * V_2 )
{
F_38 ( & V_2 -> V_86 , F_35 ) ;
}
static void F_39 ( struct V_2 * V_2 )
{
struct V_1 * V_28 ;
struct V_15 * V_44 ;
unsigned long V_32 ;
int V_88 ;
struct V_4 * V_11 ;
F_40 ( V_2 ) ;
if ( F_21 ( V_2 -> V_21 ) )
return;
V_11 = F_5 ( V_2 ) ;
V_28 = F_1 ( V_2 ) ;
F_6 ( & V_28 -> V_38 ) ;
for ( V_88 = 0 ; V_88 < V_28 -> V_14 . V_89 ; V_88 ++ )
F_41 ( V_28 -> V_50 [ V_88 ] ) ;
F_42 ( V_28 -> V_50 ) ;
F_7 ( & V_28 -> V_38 ) ;
V_32 = V_28 -> V_14 . V_45 * ( sizeof( struct V_49 * )
+ V_28 -> V_14 . V_47 ) ;
V_44 = V_28 -> V_44 ;
if ( V_44 ) {
F_6 ( & V_8 ) ;
V_44 -> V_32 -= V_32 ;
if ( V_11 )
V_11 -> V_90 -- ;
F_7 ( & V_8 ) ;
F_43 ( V_44 ) ;
}
if ( V_11 )
F_44 ( V_11 ) ;
}
static int F_45 ( struct V_2 * V_91 , struct V_74 * V_74 ,
int V_12 , struct V_92 * V_93 )
{
struct V_2 * V_2 ;
struct V_13 * V_14 = V_74 -> V_94 ;
int error ;
struct V_4 * V_11 ;
F_6 ( & V_8 ) ;
V_11 = F_3 ( V_91 ) ;
if ( ! V_11 ) {
error = - V_95 ;
goto V_96;
}
if ( V_11 -> V_90 >= V_11 -> V_97 &&
! F_46 ( V_98 ) ) {
error = - V_99 ;
goto V_96;
}
V_11 -> V_90 ++ ;
F_7 ( & V_8 ) ;
V_2 = F_8 ( V_91 -> V_5 , V_11 , V_12 , V_14 ) ;
if ( F_26 ( V_2 ) ) {
error = F_27 ( V_2 ) ;
F_6 ( & V_8 ) ;
V_11 -> V_90 -- ;
goto V_96;
}
F_44 ( V_11 ) ;
V_91 -> V_36 += V_55 ;
V_91 -> V_25 = V_91 -> V_24 = V_91 -> V_26 = V_27 ;
F_47 ( V_74 , V_2 ) ;
F_48 ( V_74 ) ;
return 0 ;
V_96:
F_7 ( & V_8 ) ;
if ( V_11 )
F_44 ( V_11 ) ;
return error ;
}
static int F_49 ( struct V_2 * V_91 , struct V_74 * V_74 )
{
struct V_2 * V_2 = V_74 -> V_100 ;
V_91 -> V_25 = V_91 -> V_24 = V_91 -> V_26 = V_27 ;
V_91 -> V_36 -= V_55 ;
F_50 ( V_2 ) ;
F_51 ( V_74 ) ;
return 0 ;
}
static T_1 F_52 ( struct V_101 * V_102 , char T_2 * V_103 ,
T_3 V_104 , T_4 * V_105 )
{
struct V_1 * V_28 = F_1 ( V_102 -> V_106 . V_74 -> V_100 ) ;
char V_107 [ V_37 ] ;
T_1 V_17 ;
F_6 ( & V_28 -> V_38 ) ;
snprintf ( V_107 , sizeof( V_107 ) ,
L_1 ,
V_28 -> V_43 ,
V_28 -> V_42 ? V_28 -> V_108 . V_109 : 0 ,
( V_28 -> V_42 &&
V_28 -> V_108 . V_109 == V_110 ) ?
V_28 -> V_108 . V_111 : 0 ,
F_53 ( V_28 -> V_42 ) ) ;
F_7 ( & V_28 -> V_38 ) ;
V_107 [ sizeof( V_107 ) - 1 ] = '\0' ;
V_17 = F_54 ( V_103 , V_104 , V_105 , V_107 ,
strlen ( V_107 ) ) ;
if ( V_17 <= 0 )
return V_17 ;
V_102 -> V_106 . V_74 -> V_100 -> V_26 = V_102 -> V_106 . V_74 -> V_100 -> V_25 = V_27 ;
return V_17 ;
}
static int F_55 ( struct V_101 * V_102 , T_5 V_112 )
{
struct V_1 * V_28 = F_1 ( V_102 -> V_106 . V_74 -> V_100 ) ;
F_6 ( & V_28 -> V_38 ) ;
if ( F_56 ( V_31 ) == V_28 -> V_42 )
F_57 ( V_28 ) ;
F_7 ( & V_28 -> V_38 ) ;
return 0 ;
}
static unsigned int F_58 ( struct V_101 * V_102 , struct V_113 * V_114 )
{
struct V_1 * V_28 = F_1 ( V_102 -> V_106 . V_74 -> V_100 ) ;
int V_115 = 0 ;
F_59 ( V_102 , & V_28 -> V_39 , V_114 ) ;
F_6 ( & V_28 -> V_38 ) ;
if ( V_28 -> V_14 . V_89 )
V_115 = V_116 | V_117 ;
if ( V_28 -> V_14 . V_89 < V_28 -> V_14 . V_45 )
V_115 |= V_118 | V_119 ;
F_7 ( & V_28 -> V_38 ) ;
return V_115 ;
}
static void F_60 ( struct V_1 * V_28 , int V_120 ,
struct V_121 * V_122 )
{
struct V_121 * V_123 ;
V_122 -> V_124 = V_31 ;
F_61 (walk, &info->e_wait_q[sr].list, list) {
if ( V_123 -> V_124 -> V_125 <= V_31 -> V_125 ) {
F_62 ( & V_122 -> V_41 , & V_123 -> V_41 ) ;
return;
}
}
F_62 ( & V_122 -> V_41 , & V_28 -> V_40 [ V_120 ] . V_41 ) ;
}
static int F_63 ( struct V_1 * V_28 , int V_120 ,
T_6 * V_126 , struct V_121 * V_122 )
{
int V_115 ;
signed long time ;
F_60 ( V_28 , V_120 , V_122 ) ;
for (; ; ) {
F_64 ( V_127 ) ;
F_7 ( & V_28 -> V_38 ) ;
time = F_65 ( V_126 , 0 ,
V_128 , V_129 ) ;
while ( V_122 -> V_130 == V_131 )
F_66 () ;
if ( V_122 -> V_130 == V_132 ) {
V_115 = 0 ;
goto V_72;
}
F_6 ( & V_28 -> V_38 ) ;
if ( V_122 -> V_130 == V_132 ) {
V_115 = 0 ;
goto V_96;
}
if ( F_67 ( V_31 ) ) {
V_115 = - V_133 ;
break;
}
if ( time == 0 ) {
V_115 = - V_134 ;
break;
}
}
F_68 ( & V_122 -> V_41 ) ;
V_96:
F_7 ( & V_28 -> V_38 ) ;
V_72:
return V_115 ;
}
static struct V_121 * F_69 (
struct V_1 * V_28 , int V_120 )
{
struct V_135 * V_136 ;
V_136 = V_28 -> V_40 [ V_120 ] . V_41 . V_137 ;
if ( V_136 == & V_28 -> V_40 [ V_120 ] . V_41 )
return NULL ;
return F_70 ( V_136 , struct V_121 , V_41 ) ;
}
static void F_71 ( struct V_49 * V_136 , struct V_1 * V_28 )
{
int V_138 ;
V_138 = V_28 -> V_14 . V_89 - 1 ;
while ( V_138 >= 0 && V_28 -> V_50 [ V_138 ] -> V_139 >= V_136 -> V_139 ) {
V_28 -> V_50 [ V_138 + 1 ] = V_28 -> V_50 [ V_138 ] ;
V_138 -- ;
}
V_28 -> V_14 . V_89 ++ ;
V_28 -> V_43 += V_136 -> V_140 ;
V_28 -> V_50 [ V_138 + 1 ] = V_136 ;
}
static inline struct V_49 * F_72 ( struct V_1 * V_28 )
{
V_28 -> V_43 -= V_28 -> V_50 [ -- V_28 -> V_14 . V_89 ] -> V_140 ;
return V_28 -> V_50 [ V_28 -> V_14 . V_89 ] ;
}
static inline void F_73 ( struct V_141 * V_142 , char V_143 )
{
( ( char * ) V_142 -> V_59 ) [ V_144 - 1 ] = V_143 ;
}
static void F_74 ( struct V_1 * V_28 )
{
if ( V_28 -> V_42 &&
V_28 -> V_14 . V_89 == 1 ) {
struct V_145 V_146 ;
switch ( V_28 -> V_108 . V_109 ) {
case V_147 :
break;
case V_110 :
V_146 . V_148 = V_28 -> V_108 . V_111 ;
V_146 . V_149 = 0 ;
V_146 . V_150 = V_151 ;
V_146 . V_152 = V_28 -> V_108 . V_153 ;
V_146 . V_154 = F_75 ( V_31 ,
F_76 ( V_28 -> V_42 ) ) ;
V_146 . V_155 = F_77 () ;
F_78 ( V_28 -> V_108 . V_111 ,
& V_146 , V_28 -> V_42 ) ;
break;
case V_156 :
F_73 ( V_28 -> V_157 , V_158 ) ;
F_79 ( V_28 -> V_159 , V_28 -> V_157 ) ;
break;
}
F_80 ( V_28 -> V_42 ) ;
V_28 -> V_42 = NULL ;
}
F_81 ( & V_28 -> V_39 ) ;
}
static int F_82 ( const struct V_160 T_2 * V_161 ,
T_6 * V_162 , struct V_160 * V_163 )
{
if ( F_83 ( V_163 , V_161 , sizeof( struct V_160 ) ) )
return - V_164 ;
if ( ! F_84 ( V_163 ) )
return - V_165 ;
* V_162 = F_85 ( * V_163 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_28 )
{
if ( V_28 -> V_42 != NULL &&
V_28 -> V_108 . V_109 == V_156 ) {
F_73 ( V_28 -> V_157 , V_166 ) ;
F_79 ( V_28 -> V_159 , V_28 -> V_157 ) ;
}
F_80 ( V_28 -> V_42 ) ;
V_28 -> V_42 = NULL ;
}
static int F_86 ( struct V_4 * V_11 , struct V_13 * V_14 )
{
if ( V_14 -> V_45 <= 0 || V_14 -> V_47 <= 0 )
return 0 ;
if ( F_46 ( V_98 ) ) {
if ( V_14 -> V_45 > V_167 )
return 0 ;
} else {
if ( V_14 -> V_45 > V_11 -> V_46 ||
V_14 -> V_47 > V_11 -> V_48 )
return 0 ;
}
if ( V_14 -> V_47 > V_168 / V_14 -> V_45 )
return 0 ;
if ( ( unsigned long ) ( V_14 -> V_45 * ( V_14 -> V_47
+ sizeof ( struct V_49 * ) ) ) <
( unsigned long ) ( V_14 -> V_45 * V_14 -> V_47 ) )
return 0 ;
return 1 ;
}
static struct V_101 * F_87 ( struct V_4 * V_11 , struct V_74 * V_91 ,
struct V_74 * V_74 , int V_169 , T_7 V_12 ,
struct V_13 * V_14 )
{
const struct V_170 * V_170 = F_88 () ;
struct V_101 * V_171 ;
int V_17 ;
if ( V_14 ) {
if ( ! F_86 ( V_11 , V_14 ) ) {
V_17 = - V_165 ;
goto V_72;
}
V_74 -> V_94 = V_14 ;
}
V_12 &= ~ F_89 () ;
V_17 = F_90 ( V_11 -> V_172 ) ;
if ( V_17 )
goto V_72;
V_17 = F_91 ( V_91 -> V_100 , V_74 , V_12 , NULL ) ;
V_74 -> V_94 = NULL ;
if ( V_17 )
goto V_173;
V_171 = F_92 ( V_74 , V_11 -> V_172 , V_169 , V_170 ) ;
F_93 ( V_11 -> V_172 ) ;
return V_171 ;
V_173:
F_93 ( V_11 -> V_172 ) ;
V_72:
F_51 ( V_74 ) ;
F_94 ( V_11 -> V_172 ) ;
return F_24 ( V_17 ) ;
}
static struct V_101 * F_95 ( struct V_4 * V_11 ,
struct V_74 * V_74 , int V_169 )
{
int V_17 ;
const struct V_170 * V_170 = F_88 () ;
static const int V_174 [ V_175 ] = { V_176 , V_177 ,
V_176 | V_177 } ;
if ( ( V_169 & V_175 ) == ( V_178 | V_179 ) ) {
V_17 = - V_165 ;
goto V_19;
}
if ( F_96 ( V_74 -> V_100 , V_174 [ V_169 & V_175 ] ) ) {
V_17 = - V_95 ;
goto V_19;
}
return F_92 ( V_74 , V_11 -> V_172 , V_169 , V_170 ) ;
V_19:
F_51 ( V_74 ) ;
F_94 ( V_11 -> V_172 ) ;
return F_24 ( V_17 ) ;
}
static inline void F_97 ( struct V_1 * V_28 ,
struct V_49 * V_180 ,
struct V_121 * V_181 )
{
V_181 -> V_182 = V_180 ;
F_68 ( & V_181 -> V_41 ) ;
V_181 -> V_130 = V_131 ;
F_98 ( V_181 -> V_124 ) ;
F_99 () ;
V_181 -> V_130 = V_132 ;
}
static inline void F_100 ( struct V_1 * V_28 )
{
struct V_121 * V_183 = F_69 ( V_28 , V_184 ) ;
if ( ! V_183 ) {
F_101 ( & V_28 -> V_39 ) ;
return;
}
F_71 ( V_183 -> V_182 , V_28 ) ;
F_68 ( & V_183 -> V_41 ) ;
V_183 -> V_130 = V_131 ;
F_98 ( V_183 -> V_124 ) ;
F_99 () ;
V_183 -> V_130 = V_132 ;
}
int F_102 ( struct V_4 * V_7 )
{
V_7 -> V_90 = 0 ;
V_7 -> V_97 = V_185 ;
V_7 -> V_46 = V_186 ;
V_7 -> V_48 = V_187 ;
V_7 -> V_172 = F_103 ( & V_188 , V_7 ) ;
if ( F_26 ( V_7 -> V_172 ) ) {
int V_19 = F_27 ( V_7 -> V_172 ) ;
V_7 -> V_172 = NULL ;
return V_19 ;
}
return 0 ;
}
void F_104 ( struct V_4 * V_7 )
{
V_7 -> V_172 -> V_189 -> V_6 = NULL ;
}
void F_105 ( struct V_4 * V_7 )
{
F_106 ( V_7 -> V_172 ) ;
}
static int T_8 F_107 ( void )
{
int error ;
V_83 = F_108 ( L_2 ,
sizeof( struct V_1 ) , 0 ,
V_190 , F_31 ) ;
if ( V_83 == NULL )
return - V_18 ;
V_191 = F_109 () ;
error = F_110 ( & V_188 ) ;
if ( error )
goto V_192;
F_15 ( & V_8 ) ;
error = F_102 ( & V_193 ) ;
if ( error )
goto V_194;
return 0 ;
V_194:
F_111 ( & V_188 ) ;
V_192:
if ( V_191 )
F_112 ( V_191 ) ;
F_113 ( V_83 ) ;
return error ;
}
