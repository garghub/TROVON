static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
const void * V_5 , T_2 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
int V_13 = 0 ;
int V_14 = F_2 () ;
bool V_15 = V_16 ;
if ( V_15 ) {
V_12 = V_17 -> V_12 ;
V_13 = F_3 () ;
V_10 = F_4 ( V_12 , V_18 ,
sizeof( * V_8 ) + V_6 ,
0 , V_13 ) ;
if ( ! V_10 )
return;
V_8 = F_5 ( V_10 ) ;
goto V_19;
}
if ( ! V_2 -> V_20 )
return;
V_8 = F_6 ( V_2 -> V_20 , sizeof( * V_8 ) + V_6 ) ;
if ( V_8 ) {
V_8 -> V_21 = V_22 | V_23 ;
V_8 -> time = F_7 ( F_8 () ) ;
V_19:
V_8 -> V_24 = V_2 -> V_25 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_26 = V_6 ;
memcpy ( ( void * ) V_8 + sizeof( * V_8 ) , V_5 , V_6 ) ;
if ( V_15 )
F_9 ( V_12 , V_10 , 0 , V_13 ) ;
}
}
static void F_10 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
V_28 -> V_29 = V_30 ;
F_1 ( V_2 , V_28 -> V_3 , V_31 , V_28 -> V_32 , sizeof( V_28 -> V_32 ) ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_33 V_34 ;
unsigned long V_35 ;
T_3 V_36 [ 2 ] ;
F_12 ( & V_34 ) ;
V_36 [ 0 ] = V_34 . V_37 ;
V_36 [ 1 ] = V_34 . V_38 ;
F_13 ( V_35 ) ;
F_1 ( V_2 , 0 , V_39 , V_36 , sizeof( V_36 ) ) ;
F_14 ( V_35 ) ;
}
void F_15 ( struct V_1 * V_2 , const char * V_40 , ... )
{
int V_41 ;
T_4 args ;
unsigned long V_35 ;
char * V_42 ;
if ( F_16 ( V_2 -> V_43 != V_44 &&
! V_16 ) )
return;
if ( ! ( V_2 -> V_45 & V_46 ) )
return;
F_13 ( V_35 ) ;
V_42 = F_17 ( V_2 -> V_47 , F_2 () ) ;
va_start ( args , V_40 ) ;
V_41 = F_18 ( V_42 , V_48 , V_40 , args ) ;
va_end ( args ) ;
F_1 ( V_2 , 0 , V_49 , V_42 , V_41 ) ;
F_14 ( V_35 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_3 V_50 , T_5 V_51 ,
T_1 V_3 )
{
if ( ( ( V_2 -> V_45 << V_52 ) & V_50 ) == 0 )
return 1 ;
if ( V_51 && ( V_51 < V_2 -> V_53 || V_51 > V_2 -> V_54 ) )
return 1 ;
if ( V_2 -> V_3 && V_3 != V_2 -> V_3 )
return 1 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , T_5 V_51 , int V_55 ,
int V_56 , T_3 V_50 , int error , int V_26 , void * V_57 )
{
struct V_27 * V_28 = V_58 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_7 * V_8 ;
unsigned long V_35 = 0 ;
unsigned long * V_59 ;
T_1 V_3 ;
int V_14 , V_13 = 0 ;
bool V_15 = V_16 ;
if ( F_16 ( V_2 -> V_43 != V_44 && ! V_15 ) )
return;
V_50 |= V_60 [ V_56 & V_61 ] ;
V_50 |= F_21 ( V_56 , V_62 ) ;
V_50 |= F_21 ( V_56 , V_63 ) ;
V_50 |= F_21 ( V_56 , V_64 ) ;
V_50 |= F_21 ( V_56 , V_65 ) ;
V_50 |= F_21 ( V_56 , V_66 ) ;
V_50 |= F_21 ( V_56 , V_67 ) ;
V_3 = V_28 -> V_3 ;
if ( F_19 ( V_2 , V_50 , V_51 , V_3 ) )
return;
V_14 = F_22 () ;
if ( V_15 ) {
F_23 ( V_58 ) ;
V_12 = V_17 -> V_12 ;
V_13 = F_3 () ;
V_10 = F_4 ( V_12 , V_18 ,
sizeof( * V_8 ) + V_26 ,
0 , V_13 ) ;
if ( ! V_10 )
return;
V_8 = F_5 ( V_10 ) ;
goto V_19;
}
F_13 ( V_35 ) ;
if ( F_16 ( V_28 -> V_29 != V_30 ) )
F_10 ( V_2 , V_28 ) ;
V_8 = F_6 ( V_2 -> V_20 , sizeof( * V_8 ) + V_26 ) ;
if ( V_8 ) {
V_59 = F_17 ( V_2 -> V_59 , V_14 ) ;
V_8 -> V_21 = V_22 | V_23 ;
V_8 -> V_59 = ++ ( * V_59 ) ;
V_8 -> time = F_7 ( F_8 () ) ;
V_19:
V_8 -> V_14 = V_14 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_51 = V_51 ;
V_8 -> V_55 = V_55 ;
V_8 -> V_4 = V_50 ;
V_8 -> V_24 = V_2 -> V_25 ;
V_8 -> error = error ;
V_8 -> V_26 = V_26 ;
if ( V_26 )
memcpy ( ( void * ) V_8 + sizeof( * V_8 ) , V_57 , V_26 ) ;
if ( V_15 ) {
F_9 ( V_12 , V_10 , 0 , V_13 ) ;
return;
}
}
F_14 ( V_35 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_68 ) ;
F_25 ( V_2 -> V_69 ) ;
F_26 ( V_2 -> V_20 ) ;
F_25 ( V_2 -> V_70 ) ;
F_27 ( V_2 -> V_59 ) ;
F_27 ( V_2 -> V_47 ) ;
F_28 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
if ( F_30 ( & V_71 ) )
F_31 () ;
}
int F_32 ( struct V_72 * V_73 )
{
struct V_1 * V_2 ;
V_2 = F_33 ( & V_73 -> V_1 , NULL ) ;
if ( ! V_2 )
return - V_74 ;
if ( V_2 -> V_43 != V_44 )
F_29 ( V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_75 * V_75 , struct V_76 * V_77 )
{
V_77 -> V_78 = V_75 -> V_79 ;
return 0 ;
}
static T_6 F_35 ( struct V_76 * V_77 , char T_7 * V_12 ,
T_2 V_80 , T_8 * V_81 )
{
struct V_1 * V_2 = V_77 -> V_78 ;
char V_42 [ 16 ] ;
snprintf ( V_42 , sizeof( V_42 ) , L_1 , F_36 ( & V_2 -> V_82 ) ) ;
return F_37 ( V_12 , V_80 , V_81 , V_42 , strlen ( V_42 ) ) ;
}
static int F_38 ( struct V_75 * V_75 , struct V_76 * V_77 )
{
V_77 -> V_78 = V_75 -> V_79 ;
return 0 ;
}
static T_6 F_39 ( struct V_76 * V_77 , const char T_7 * V_12 ,
T_2 V_80 , T_8 * V_81 )
{
char * V_83 ;
struct V_1 * V_2 ;
if ( V_80 >= V_48 )
return - V_74 ;
V_83 = F_40 ( V_80 + 1 , V_84 ) ;
if ( V_83 == NULL )
return - V_85 ;
if ( F_41 ( V_83 , V_12 , V_80 ) ) {
F_28 ( V_83 ) ;
return - V_86 ;
}
V_83 [ V_80 ] = '\0' ;
V_2 = V_77 -> V_78 ;
F_15 ( V_2 , L_2 , V_83 ) ;
F_28 ( V_83 ) ;
return V_80 ;
}
static int F_42 ( struct V_87 * V_42 , void * V_88 ,
void * V_89 , T_2 V_90 )
{
struct V_1 * V_2 ;
if ( ! F_43 ( V_42 ) )
return 1 ;
V_2 = V_42 -> V_91 -> V_78 ;
F_44 ( & V_2 -> V_82 ) ;
return 0 ;
}
static int F_45 ( struct V_92 * V_92 )
{
F_25 ( V_92 ) ;
return 0 ;
}
static struct V_92 * F_46 ( const char * V_93 ,
struct V_92 * V_94 ,
int V_95 ,
struct V_87 * V_42 ,
int * V_96 )
{
return F_47 ( V_93 , V_95 , V_94 , V_42 ,
& V_97 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
struct V_100 * V_101 = NULL ;
if ( V_99 )
V_101 = V_99 -> V_102 ;
if ( V_101 ) {
V_2 -> V_53 = V_101 -> V_103 ;
V_2 -> V_54 = V_101 -> V_103 + V_101 -> V_104 ;
} else {
V_2 -> V_53 = 0 ;
V_2 -> V_54 = - 1ULL ;
}
}
int F_49 ( struct V_72 * V_73 , char * V_105 , T_9 V_25 ,
struct V_98 * V_99 ,
struct V_106 * V_107 )
{
struct V_1 * V_108 , * V_2 = NULL ;
struct V_92 * V_70 = NULL ;
int V_109 , V_110 ;
if ( ! V_107 -> V_111 || ! V_107 -> V_112 )
return - V_74 ;
strncpy ( V_107 -> V_105 , V_105 , V_113 ) ;
V_107 -> V_105 [ V_113 - 1 ] = '\0' ;
for ( V_110 = 0 ; V_110 < strlen ( V_107 -> V_105 ) ; V_110 ++ )
if ( V_107 -> V_105 [ V_110 ] == '/' )
V_107 -> V_105 [ V_110 ] = '_' ;
V_2 = F_50 ( sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_109 = - V_85 ;
V_2 -> V_59 = F_51 (unsigned long) ;
if ( ! V_2 -> V_59 )
goto V_114;
V_2 -> V_47 = F_52 ( V_48 , F_53 ( char ) ) ;
if ( ! V_2 -> V_47 )
goto V_114;
V_109 = - V_115 ;
F_54 ( & V_116 ) ;
if ( ! V_117 ) {
V_117 = F_55 ( L_3 , NULL ) ;
if ( ! V_117 ) {
F_56 ( & V_116 ) ;
goto V_114;
}
}
F_56 ( & V_116 ) ;
V_70 = F_55 ( V_107 -> V_105 , V_117 ) ;
if ( ! V_70 )
goto V_114;
V_2 -> V_70 = V_70 ;
V_2 -> V_25 = V_25 ;
F_57 ( & V_2 -> V_82 , 0 ) ;
V_109 = - V_118 ;
V_2 -> V_69 = F_47 ( L_4 , 0444 , V_70 , V_2 ,
& V_119 ) ;
if ( ! V_2 -> V_69 )
goto V_114;
V_2 -> V_68 = F_47 ( L_5 , 0222 , V_70 , V_2 , & V_120 ) ;
if ( ! V_2 -> V_68 )
goto V_114;
V_2 -> V_20 = F_58 ( L_6 , V_70 , V_107 -> V_111 ,
V_107 -> V_112 , & V_121 , V_2 ) ;
if ( ! V_2 -> V_20 )
goto V_114;
V_2 -> V_45 = V_107 -> V_45 ;
if ( ! V_2 -> V_45 )
V_2 -> V_45 = ( V_122 ) - 1 ;
F_48 ( V_2 , V_99 ) ;
if ( V_107 -> V_53 )
V_2 -> V_53 = V_107 -> V_53 ;
if ( V_107 -> V_54 )
V_2 -> V_54 = V_107 -> V_54 ;
V_2 -> V_3 = V_107 -> V_3 ;
V_2 -> V_43 = V_123 ;
V_109 = - V_124 ;
V_108 = F_33 ( & V_73 -> V_1 , V_2 ) ;
if ( V_108 ) {
( void ) F_33 ( & V_73 -> V_1 , V_108 ) ;
goto V_114;
}
if ( F_59 ( & V_71 ) == 1 )
F_60 () ;
return 0 ;
V_114:
F_24 ( V_2 ) ;
return V_109 ;
}
int F_61 ( struct V_72 * V_73 , char * V_105 , T_9 V_25 ,
struct V_98 * V_99 ,
char T_7 * V_125 )
{
struct V_106 V_107 ;
int V_109 ;
V_109 = F_41 ( & V_107 , V_125 , sizeof( V_107 ) ) ;
if ( V_109 )
return - V_86 ;
V_109 = F_49 ( V_73 , V_105 , V_25 , V_99 , & V_107 ) ;
if ( V_109 )
return V_109 ;
if ( F_62 ( V_125 , & V_107 , sizeof( V_107 ) ) ) {
F_32 ( V_73 ) ;
return - V_86 ;
}
return 0 ;
}
static int F_63 ( struct V_72 * V_73 , char * V_105 ,
T_9 V_25 , struct V_98 * V_99 ,
char T_7 * V_125 )
{
struct V_106 V_107 ;
struct V_126 V_127 ;
int V_109 ;
if ( F_41 ( & V_127 , V_125 , sizeof( V_127 ) ) )
return - V_86 ;
V_107 = (struct V_106 ) {
. V_45 = V_127 . V_45 ,
. V_111 = V_127 . V_111 ,
. V_112 = V_127 . V_112 ,
. V_53 = V_127 . V_53 ,
. V_54 = V_127 . V_54 ,
. V_3 = V_127 . V_3 ,
} ;
memcpy ( & V_107 . V_105 , & V_127 . V_105 , 32 ) ;
V_109 = F_49 ( V_73 , V_105 , V_25 , V_99 , & V_107 ) ;
if ( V_109 )
return V_109 ;
if ( F_62 ( V_125 , & V_107 . V_105 , 32 ) ) {
F_32 ( V_73 ) ;
return - V_86 ;
}
return 0 ;
}
int F_64 ( struct V_72 * V_73 , int V_128 )
{
int V_109 ;
struct V_1 * V_2 = V_73 -> V_1 ;
if ( V_2 == NULL )
return - V_74 ;
V_109 = - V_74 ;
if ( V_128 ) {
if ( V_2 -> V_43 == V_123 ||
V_2 -> V_43 == V_129 ) {
V_30 ++ ;
F_65 () ;
V_2 -> V_43 = V_44 ;
F_11 ( V_2 ) ;
V_109 = 0 ;
}
} else {
if ( V_2 -> V_43 == V_44 ) {
V_2 -> V_43 = V_129 ;
F_66 ( V_2 -> V_20 ) ;
V_109 = 0 ;
}
}
return V_109 ;
}
int F_67 ( struct V_98 * V_99 , unsigned V_130 , char T_7 * V_125 )
{
struct V_72 * V_73 ;
int V_109 , V_128 = 0 ;
char V_131 [ V_132 ] ;
V_73 = F_68 ( V_99 ) ;
if ( ! V_73 )
return - V_133 ;
F_54 ( & V_99 -> V_134 ) ;
switch ( V_130 ) {
case V_135 :
F_69 ( V_99 , V_131 ) ;
V_109 = F_61 ( V_73 , V_131 , V_99 -> V_136 , V_99 , V_125 ) ;
break;
#if F_70 ( V_137 ) && F_70 ( V_138 )
case V_139 :
F_69 ( V_99 , V_131 ) ;
V_109 = F_63 ( V_73 , V_131 , V_99 -> V_136 , V_99 , V_125 ) ;
break;
#endif
case V_140 :
V_128 = 1 ;
case V_141 :
V_109 = F_64 ( V_73 , V_128 ) ;
break;
case V_142 :
V_109 = F_32 ( V_73 ) ;
break;
default:
V_109 = - V_143 ;
break;
}
F_56 ( & V_99 -> V_134 ) ;
return V_109 ;
}
void F_71 ( struct V_72 * V_73 )
{
if ( V_73 -> V_1 ) {
F_64 ( V_73 , 0 ) ;
F_32 ( V_73 ) ;
}
}
static void F_72 ( struct V_72 * V_73 , struct V_144 * V_145 ,
T_3 V_50 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
if ( F_73 ( ! V_2 ) )
return;
if ( V_145 -> V_146 == V_147 ) {
V_50 |= F_74 ( V_148 ) ;
F_20 ( V_2 , 0 , F_75 ( V_145 ) , V_145 -> V_149 ,
V_50 , V_145 -> V_150 , V_145 -> V_151 , V_145 -> V_130 ) ;
} else {
V_50 |= F_74 ( V_152 ) ;
F_20 ( V_2 , F_76 ( V_145 ) , F_75 ( V_145 ) ,
V_145 -> V_149 , V_50 , V_145 -> V_150 , 0 , NULL ) ;
}
}
static void F_77 ( void * V_153 ,
struct V_72 * V_73 , struct V_144 * V_145 )
{
F_72 ( V_73 , V_145 , V_154 ) ;
}
static void F_78 ( void * V_153 ,
struct V_72 * V_73 , struct V_144 * V_145 )
{
F_72 ( V_73 , V_145 , V_155 ) ;
}
static void F_79 ( void * V_153 ,
struct V_72 * V_73 , struct V_144 * V_145 )
{
F_72 ( V_73 , V_145 , V_156 ) ;
}
static void F_80 ( void * V_153 ,
struct V_72 * V_73 ,
struct V_144 * V_145 )
{
F_72 ( V_73 , V_145 , V_157 ) ;
}
static void F_81 ( void * V_153 ,
struct V_72 * V_73 ,
struct V_144 * V_145 )
{
F_72 ( V_73 , V_145 , V_158 ) ;
}
static void F_82 ( struct V_72 * V_73 , struct V_159 * V_159 ,
T_3 V_50 , int error )
{
struct V_1 * V_2 = V_73 -> V_1 ;
if ( F_73 ( ! V_2 ) )
return;
if ( ! error && ! F_83 ( V_159 , V_160 ) )
error = V_118 ;
F_20 ( V_2 , V_159 -> V_161 , V_159 -> V_162 , V_159 -> V_163 , V_50 ,
error , 0 , NULL ) ;
}
static void F_84 ( void * V_153 ,
struct V_72 * V_73 , struct V_159 * V_159 )
{
F_82 ( V_73 , V_159 , V_164 , 0 ) ;
}
static void F_85 ( void * V_153 ,
struct V_72 * V_73 , struct V_159 * V_159 ,
int error )
{
F_82 ( V_73 , V_159 , V_158 , error ) ;
}
static void F_86 ( void * V_153 ,
struct V_72 * V_73 ,
struct V_159 * V_159 )
{
F_82 ( V_73 , V_159 , V_165 , 0 ) ;
}
static void F_87 ( void * V_153 ,
struct V_72 * V_73 ,
struct V_159 * V_159 )
{
F_82 ( V_73 , V_159 , V_166 , 0 ) ;
}
static void F_88 ( void * V_153 ,
struct V_72 * V_73 , struct V_159 * V_159 )
{
F_82 ( V_73 , V_159 , V_167 , 0 ) ;
}
static void F_89 ( void * V_153 ,
struct V_72 * V_73 ,
struct V_159 * V_159 , int V_56 )
{
if ( V_159 )
F_82 ( V_73 , V_159 , V_168 , 0 ) ;
else {
struct V_1 * V_2 = V_73 -> V_1 ;
if ( V_2 )
F_20 ( V_2 , 0 , 0 , V_56 , V_168 , 0 , 0 , NULL ) ;
}
}
static void F_90 ( void * V_153 ,
struct V_72 * V_73 ,
struct V_159 * V_159 , int V_56 )
{
if ( V_159 )
F_82 ( V_73 , V_159 , V_169 , 0 ) ;
else {
struct V_1 * V_2 = V_73 -> V_1 ;
if ( V_2 )
F_20 ( V_2 , 0 , 0 , V_56 , V_169 ,
0 , 0 , NULL ) ;
}
}
static void F_91 ( void * V_153 , struct V_72 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
if ( V_2 )
F_20 ( V_2 , 0 , 0 , 0 , V_170 , 0 , 0 , NULL ) ;
}
static void F_92 ( void * V_153 , struct V_72 * V_73 ,
unsigned int V_171 , bool V_172 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
if ( V_2 ) {
T_10 V_173 = F_93 ( V_171 ) ;
T_3 V_50 ;
if ( V_172 )
V_50 = V_174 ;
else
V_50 = V_175 ;
F_20 ( V_2 , 0 , 0 , 0 , V_50 , 0 , sizeof( V_173 ) , & V_173 ) ;
}
}
static void F_94 ( void * V_153 ,
struct V_72 * V_73 , struct V_159 * V_159 ,
unsigned int V_176 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
if ( V_2 ) {
T_10 V_173 = F_93 ( V_176 ) ;
F_20 ( V_2 , V_159 -> V_161 , V_159 -> V_162 , V_159 -> V_163 ,
V_177 , ! F_83 ( V_159 , V_160 ) ,
sizeof( V_173 ) , & V_173 ) ;
}
}
static void F_95 ( void * V_153 ,
struct V_72 * V_73 , struct V_159 * V_159 ,
T_9 V_25 , T_5 V_178 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
struct V_179 V_180 ;
if ( F_73 ( ! V_2 ) )
return;
V_180 . V_181 = F_96 ( V_25 ) ;
V_180 . V_182 = F_96 ( V_159 -> V_183 -> V_136 ) ;
V_180 . V_184 = F_93 ( V_178 ) ;
F_20 ( V_2 , V_159 -> V_161 , V_159 -> V_162 , V_159 -> V_163 ,
V_185 , ! F_83 ( V_159 , V_160 ) ,
sizeof( V_180 ) , & V_180 ) ;
}
static void F_97 ( void * V_153 ,
struct V_72 * V_73 ,
struct V_144 * V_145 , T_9 V_25 ,
T_5 V_178 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
struct V_179 V_180 ;
if ( F_73 ( ! V_2 ) )
return;
V_180 . V_181 = F_96 ( V_25 ) ;
V_180 . V_182 = F_96 ( F_98 ( V_145 -> V_186 ) ) ;
V_180 . V_184 = F_93 ( V_178 ) ;
F_20 ( V_2 , F_76 ( V_145 ) , F_75 ( V_145 ) ,
F_99 ( V_145 ) , V_185 , ! ! V_145 -> V_150 ,
sizeof( V_180 ) , & V_180 ) ;
}
void F_100 ( struct V_72 * V_73 ,
struct V_144 * V_145 ,
void * V_5 , T_2 V_6 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
if ( F_73 ( ! V_2 ) )
return;
if ( V_145 -> V_146 == V_147 )
F_20 ( V_2 , 0 , F_75 ( V_145 ) , 0 ,
V_187 , V_145 -> V_150 , V_6 , V_5 ) ;
else
F_20 ( V_2 , F_76 ( V_145 ) , F_75 ( V_145 ) , 0 ,
V_187 , V_145 -> V_150 , V_6 , V_5 ) ;
}
static void F_60 ( void )
{
int V_109 ;
V_109 = F_101 ( F_77 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_103 ( F_78 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_104 ( F_79 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_105 ( F_80 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_106 ( F_81 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_107 ( F_84 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_108 ( F_85 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_109 ( F_86 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_110 ( F_87 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_111 ( F_88 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_112 ( F_89 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_113 ( F_90 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_114 ( F_91 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_115 ( F_92 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_116 ( F_94 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_117 ( F_95 , NULL ) ;
F_102 ( V_109 ) ;
V_109 = F_118 ( F_97 , NULL ) ;
F_102 ( V_109 ) ;
}
static void F_31 ( void )
{
F_119 ( F_97 , NULL ) ;
F_120 ( F_95 , NULL ) ;
F_121 ( F_94 , NULL ) ;
F_122 ( F_92 , NULL ) ;
F_123 ( F_91 , NULL ) ;
F_124 ( F_90 , NULL ) ;
F_125 ( F_89 , NULL ) ;
F_126 ( F_88 , NULL ) ;
F_127 ( F_87 , NULL ) ;
F_128 ( F_86 , NULL ) ;
F_129 ( F_85 , NULL ) ;
F_130 ( F_84 , NULL ) ;
F_131 ( F_81 , NULL ) ;
F_132 ( F_80 , NULL ) ;
F_133 ( F_79 , NULL ) ;
F_134 ( F_78 , NULL ) ;
F_135 ( F_77 , NULL ) ;
F_136 () ;
}
static void F_137 ( char * V_188 , const struct V_7 * V_8 )
{
int V_110 = 0 ;
int V_189 = V_8 -> V_4 >> V_52 ;
if ( V_8 -> V_4 == V_49 ) {
V_188 [ V_110 ++ ] = 'N' ;
goto V_190;
}
if ( V_189 & V_191 )
V_188 [ V_110 ++ ] = 'F' ;
if ( V_189 & V_192 )
V_188 [ V_110 ++ ] = 'D' ;
else if ( V_189 & V_193 )
V_188 [ V_110 ++ ] = 'W' ;
else if ( V_8 -> V_55 )
V_188 [ V_110 ++ ] = 'R' ;
else
V_188 [ V_110 ++ ] = 'N' ;
if ( V_189 & V_194 )
V_188 [ V_110 ++ ] = 'F' ;
if ( V_189 & V_195 )
V_188 [ V_110 ++ ] = 'A' ;
if ( V_189 & V_196 )
V_188 [ V_110 ++ ] = 'S' ;
if ( V_189 & V_197 )
V_188 [ V_110 ++ ] = 'M' ;
V_190:
V_188 [ V_110 ] = '\0' ;
}
static inline
const struct V_7 * F_138 ( const struct V_198 * V_199 )
{
return ( const struct V_7 * ) V_199 ;
}
static inline const void * F_139 ( const struct V_198 * V_199 )
{
return F_138 ( V_199 ) + 1 ;
}
static inline T_3 F_140 ( const struct V_198 * V_199 )
{
return F_138 ( V_199 ) -> V_4 ;
}
static inline T_3 F_141 ( const struct V_198 * V_199 )
{
return F_138 ( V_199 ) -> V_55 ;
}
static inline T_3 F_142 ( const struct V_198 * V_199 )
{
return F_138 ( V_199 ) -> V_55 >> 9 ;
}
static inline unsigned long long F_143 ( const struct V_198 * V_199 )
{
return F_138 ( V_199 ) -> V_51 ;
}
static inline T_11 F_144 ( const struct V_198 * V_199 )
{
return F_138 ( V_199 ) -> error ;
}
static T_12 F_145 ( const struct V_198 * V_199 )
{
const T_12 * V_200 = F_139 ( V_199 ) ;
return F_146 ( * V_200 ) ;
}
static void F_147 ( const struct V_198 * V_199 ,
struct V_179 * V_180 )
{
const struct V_179 * V_201 = F_139 ( V_199 ) ;
T_12 V_184 = V_201 -> V_184 ;
V_180 -> V_181 = F_148 ( V_201 -> V_181 ) ;
V_180 -> V_182 = F_148 ( V_201 -> V_182 ) ;
V_180 -> V_184 = F_146 ( V_184 ) ;
}
static int F_149 ( struct V_202 * V_203 , const char * V_204 )
{
char V_188 [ V_205 ] ;
unsigned long long V_206 = V_203 -> V_206 ;
unsigned long V_207 = F_150 ( V_206 , V_208 ) ;
unsigned V_209 = ( unsigned long ) V_206 ;
const struct V_7 * V_8 = F_138 ( V_203 -> V_199 ) ;
F_137 ( V_188 , V_8 ) ;
return F_151 ( & V_203 -> V_210 ,
L_7 ,
F_152 ( V_8 -> V_24 ) , F_153 ( V_8 -> V_24 ) , V_203 -> V_14 ,
V_209 , V_207 , V_203 -> V_199 -> V_3 , V_204 , V_188 ) ;
}
static int F_154 ( struct V_202 * V_203 , const char * V_204 )
{
char V_188 [ V_205 ] ;
const struct V_7 * V_8 = F_138 ( V_203 -> V_199 ) ;
F_137 ( V_188 , V_8 ) ;
return F_151 ( & V_203 -> V_210 , L_8 ,
F_152 ( V_8 -> V_24 ) , F_153 ( V_8 -> V_24 ) , V_204 , V_188 ) ;
}
static int F_155 ( struct V_211 * V_212 , const struct V_198 * V_199 )
{
const unsigned char * V_213 ;
int V_26 ;
int V_110 , V_214 , V_109 ;
V_213 = F_139 ( V_199 ) ;
V_26 = F_138 ( V_199 ) -> V_26 ;
if ( ! V_26 )
return 1 ;
for ( V_214 = V_26 - 1 ; V_214 >= 0 ; V_214 -- )
if ( V_213 [ V_214 ] )
break;
V_214 ++ ;
if ( ! F_156 ( V_212 , '(' ) )
return 0 ;
for ( V_110 = 0 ; V_110 < V_26 ; V_110 ++ ) {
V_109 = F_151 ( V_212 , L_9 ,
V_110 == 0 ? L_10 : L_11 , V_213 [ V_110 ] ) ;
if ( ! V_109 )
return V_109 ;
if ( V_110 == V_214 && V_214 != V_26 - 1 )
return F_157 ( V_212 , L_12 ) ;
}
return F_157 ( V_212 , L_13 ) ;
}
static int F_158 ( struct V_211 * V_212 , const struct V_198 * V_199 )
{
char V_130 [ V_215 ] ;
F_159 ( V_199 -> V_3 , V_130 ) ;
if ( F_140 ( V_199 ) & F_74 ( V_148 ) ) {
int V_109 ;
V_109 = F_151 ( V_212 , L_14 , F_141 ( V_199 ) ) ;
if ( ! V_109 )
return 0 ;
V_109 = F_155 ( V_212 , V_199 ) ;
if ( ! V_109 )
return 0 ;
return F_151 ( V_212 , L_15 , V_130 ) ;
} else {
if ( F_142 ( V_199 ) )
return F_151 ( V_212 , L_16 ,
F_143 ( V_199 ) , F_142 ( V_199 ) , V_130 ) ;
return F_151 ( V_212 , L_15 , V_130 ) ;
}
}
static int F_160 ( struct V_211 * V_212 ,
const struct V_198 * V_199 )
{
if ( F_140 ( V_199 ) & F_74 ( V_148 ) ) {
int V_109 ;
V_109 = F_155 ( V_212 , V_199 ) ;
if ( V_109 )
return F_151 ( V_212 , L_17 , F_144 ( V_199 ) ) ;
return 0 ;
} else {
if ( F_142 ( V_199 ) )
return F_151 ( V_212 , L_18 ,
F_143 ( V_199 ) ,
F_142 ( V_199 ) , F_144 ( V_199 ) ) ;
return F_151 ( V_212 , L_19 ,
F_143 ( V_199 ) , F_144 ( V_199 ) ) ;
}
}
static int F_161 ( struct V_211 * V_212 , const struct V_198 * V_199 )
{
struct V_179 V_180 = { . V_181 = 0 , } ;
F_147 ( V_199 , & V_180 ) ;
return F_151 ( V_212 , L_20 ,
F_143 ( V_199 ) , F_142 ( V_199 ) ,
F_152 ( V_180 . V_181 ) , F_153 ( V_180 . V_181 ) ,
( unsigned long long ) V_180 . V_184 ) ;
}
static int F_162 ( struct V_211 * V_212 , const struct V_198 * V_199 )
{
char V_130 [ V_215 ] ;
F_159 ( V_199 -> V_3 , V_130 ) ;
return F_151 ( V_212 , L_15 , V_130 ) ;
}
static int F_163 ( struct V_211 * V_212 , const struct V_198 * V_199 )
{
char V_130 [ V_215 ] ;
F_159 ( V_199 -> V_3 , V_130 ) ;
return F_151 ( V_212 , L_21 , V_130 , F_145 ( V_199 ) ) ;
}
static int F_164 ( struct V_211 * V_212 , const struct V_198 * V_199 )
{
char V_130 [ V_215 ] ;
F_159 ( V_199 -> V_3 , V_130 ) ;
return F_151 ( V_212 , L_22 , F_143 ( V_199 ) ,
F_145 ( V_199 ) , V_130 ) ;
}
static int F_165 ( struct V_211 * V_212 , const struct V_198 * V_199 )
{
int V_109 ;
const struct V_7 * V_8 = F_138 ( V_199 ) ;
V_109 = F_166 ( V_212 , V_8 + 1 , V_8 -> V_26 ) ;
if ( V_109 )
return F_156 ( V_212 , '\n' ) ;
return V_109 ;
}
static void F_167 ( struct V_216 * V_217 )
{
if ( ! ( V_218 . V_200 & V_219 ) )
return;
F_168 ( V_217 , L_23
L_24 ) ;
}
static void F_169 ( struct V_220 * V_221 )
{
V_16 = true ;
}
static int F_170 ( struct V_220 * V_221 )
{
V_17 = V_221 ;
F_169 ( V_221 ) ;
return 0 ;
}
static void F_171 ( struct V_220 * V_221 )
{
V_16 = false ;
}
static void F_172 ( struct V_220 * V_221 )
{
F_171 ( V_221 ) ;
}
static enum V_222 F_173 ( struct V_202 * V_203 ,
bool V_223 )
{
struct V_211 * V_212 = & V_203 -> V_210 ;
const struct V_7 * V_8 ;
V_122 V_50 ;
int V_109 ;
bool V_224 ;
T_13 * V_225 ;
V_8 = F_138 ( V_203 -> V_199 ) ;
V_50 = V_8 -> V_4 & ( ( 1 << V_52 ) - 1 ) ;
V_224 = ! ! ( V_226 & V_227 ) ;
V_225 = V_223 ? & F_149 : & F_154 ;
if ( V_8 -> V_4 == V_49 ) {
V_109 = V_225 ( V_203 , V_224 ? L_25 : L_26 ) ;
if ( V_109 )
V_109 = F_165 ( V_212 , V_203 -> V_199 ) ;
goto V_190;
}
if ( F_16 ( V_50 == 0 || V_50 >= F_174 ( V_228 ) ) )
V_109 = F_151 ( V_212 , L_27 , V_50 ) ;
else {
V_109 = V_225 ( V_203 , V_228 [ V_50 ] . V_204 [ V_224 ] ) ;
if ( V_109 )
V_109 = V_228 [ V_50 ] . F_175 ( V_212 , V_203 -> V_199 ) ;
}
V_190:
return V_109 ? V_229 : V_230 ;
}
static enum V_222 F_176 ( struct V_202 * V_203 ,
int V_35 , struct V_231 * V_10 )
{
return F_173 ( V_203 , false ) ;
}
static int F_177 ( struct V_202 * V_203 )
{
struct V_211 * V_212 = & V_203 -> V_210 ;
struct V_7 * V_8 = (struct V_7 * ) V_203 -> V_199 ;
const int V_232 = F_178 ( struct V_7 , V_51 ) ;
struct V_7 V_233 = {
. V_21 = V_22 | V_23 ,
. time = V_203 -> V_206 ,
} ;
if ( ! F_166 ( V_212 , & V_233 , V_232 ) )
return 0 ;
return F_166 ( V_212 , & V_8 -> V_51 ,
sizeof( V_233 ) - V_232 + V_8 -> V_26 ) ;
}
static enum V_222
F_179 ( struct V_202 * V_203 , int V_35 ,
struct V_231 * V_10 )
{
return F_177 ( V_203 ) ?
V_229 : V_230 ;
}
static enum V_222 F_180 ( struct V_202 * V_203 )
{
if ( ! ( V_218 . V_200 & V_219 ) )
return V_234 ;
return F_173 ( V_203 , true ) ;
}
static int F_181 ( T_3 V_235 , T_3 V_236 , int V_237 )
{
if ( V_236 == V_219 ) {
if ( V_237 )
V_226 &= ~ V_238 ;
else
V_226 |= V_238 ;
}
return 0 ;
}
static int T_14 F_182 ( void )
{
if ( ! F_183 ( & V_239 ) ) {
F_184 ( L_28 ) ;
return 1 ;
}
if ( F_185 ( & V_15 ) != 0 ) {
F_184 ( L_29 ) ;
F_186 ( & V_239 ) ;
return 1 ;
}
return 0 ;
}
static int F_187 ( struct V_72 * V_73 )
{
struct V_1 * V_2 ;
V_2 = F_33 ( & V_73 -> V_1 , NULL ) ;
if ( V_2 == NULL )
return - V_74 ;
if ( F_30 ( & V_71 ) )
F_31 () ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_188 ( struct V_72 * V_73 ,
struct V_98 * V_99 )
{
struct V_1 * V_108 , * V_2 = NULL ;
int V_109 = - V_85 ;
V_2 = F_50 ( sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_47 = F_52 ( V_48 , F_53 ( char ) ) ;
if ( ! V_2 -> V_47 )
goto V_240;
V_2 -> V_25 = V_99 -> V_136 ;
V_2 -> V_45 = ( V_122 ) - 1 ;
F_48 ( V_2 , V_99 ) ;
V_108 = F_33 ( & V_73 -> V_1 , V_2 ) ;
if ( V_108 != NULL ) {
( void ) F_33 ( & V_73 -> V_1 , V_108 ) ;
V_109 = - V_124 ;
goto V_240;
}
if ( F_59 ( & V_71 ) == 1 )
F_60 () ;
return 0 ;
V_240:
F_24 ( V_2 ) ;
return V_109 ;
}
static int F_189 ( const char * V_241 )
{
int V_110 ;
int V_242 = 0 ;
char * V_42 , * V_212 , * V_243 ;
V_42 = F_190 ( V_241 , V_84 ) ;
if ( V_42 == NULL )
return - V_85 ;
V_212 = F_191 ( V_42 ) ;
while ( 1 ) {
V_243 = F_192 ( & V_212 , L_30 ) ;
if ( V_243 == NULL )
break;
if ( * V_243 == '\0' )
continue;
for ( V_110 = 0 ; V_110 < F_174 ( V_244 ) ; V_110 ++ ) {
if ( strcasecmp ( V_243 , V_244 [ V_110 ] . V_241 ) == 0 ) {
V_242 |= V_244 [ V_110 ] . V_242 ;
break;
}
}
if ( V_110 == F_174 ( V_244 ) ) {
V_242 = - V_74 ;
break;
}
}
F_28 ( V_42 ) ;
return V_242 ;
}
static T_6 F_193 ( char * V_42 , int V_242 )
{
int V_110 ;
char * V_245 = V_42 ;
for ( V_110 = 0 ; V_110 < F_174 ( V_244 ) ; V_110 ++ ) {
if ( V_242 & V_244 [ V_110 ] . V_242 ) {
V_245 += sprintf ( V_245 , L_31 ,
( V_245 == V_42 ) ? L_10 : L_30 , V_244 [ V_110 ] . V_241 ) ;
}
}
* V_245 ++ = '\n' ;
return V_245 - V_42 ;
}
static struct V_72 * F_194 ( struct V_98 * V_99 )
{
if ( V_99 -> V_246 == NULL )
return NULL ;
return F_68 ( V_99 ) ;
}
static T_6 F_195 ( struct V_24 * V_25 ,
struct V_247 * V_248 ,
char * V_42 )
{
struct V_100 * V_245 = F_196 ( V_25 ) ;
struct V_72 * V_73 ;
struct V_98 * V_99 ;
T_6 V_109 = - V_133 ;
V_99 = F_197 ( F_198 ( V_245 ) ) ;
if ( V_99 == NULL )
goto V_190;
V_73 = F_194 ( V_99 ) ;
if ( V_73 == NULL )
goto V_249;
F_54 ( & V_99 -> V_134 ) ;
if ( V_248 == & V_250 ) {
V_109 = sprintf ( V_42 , L_1 , ! ! V_73 -> V_1 ) ;
goto V_251;
}
if ( V_73 -> V_1 == NULL )
V_109 = sprintf ( V_42 , L_32 ) ;
else if ( V_248 == & V_252 )
V_109 = F_193 ( V_42 , V_73 -> V_1 -> V_45 ) ;
else if ( V_248 == & V_253 )
V_109 = sprintf ( V_42 , L_1 , V_73 -> V_1 -> V_3 ) ;
else if ( V_248 == & V_254 )
V_109 = sprintf ( V_42 , L_33 , V_73 -> V_1 -> V_53 ) ;
else if ( V_248 == & V_255 )
V_109 = sprintf ( V_42 , L_33 , V_73 -> V_1 -> V_54 ) ;
V_251:
F_56 ( & V_99 -> V_134 ) ;
V_249:
F_199 ( V_99 ) ;
V_190:
return V_109 ;
}
static T_6 F_200 ( struct V_24 * V_25 ,
struct V_247 * V_248 ,
const char * V_42 , T_2 V_80 )
{
struct V_98 * V_99 ;
struct V_72 * V_73 ;
struct V_100 * V_245 ;
T_15 V_256 ;
T_6 V_109 = - V_74 ;
if ( V_80 == 0 )
goto V_190;
if ( V_248 == & V_252 ) {
if ( sscanf ( V_42 , L_34 , & V_256 ) != 1 ) {
V_109 = F_189 ( V_42 ) ;
if ( V_109 < 0 )
goto V_190;
V_256 = V_109 ;
}
} else if ( sscanf ( V_42 , L_35 , & V_256 ) != 1 )
goto V_190;
V_109 = - V_133 ;
V_245 = F_196 ( V_25 ) ;
V_99 = F_197 ( F_198 ( V_245 ) ) ;
if ( V_99 == NULL )
goto V_190;
V_73 = F_194 ( V_99 ) ;
if ( V_73 == NULL )
goto V_249;
F_54 ( & V_99 -> V_134 ) ;
if ( V_248 == & V_250 ) {
if ( V_256 )
V_109 = F_188 ( V_73 , V_99 ) ;
else
V_109 = F_187 ( V_73 ) ;
goto V_251;
}
V_109 = 0 ;
if ( V_73 -> V_1 == NULL )
V_109 = F_188 ( V_73 , V_99 ) ;
if ( V_109 == 0 ) {
if ( V_248 == & V_252 )
V_73 -> V_1 -> V_45 = V_256 ;
else if ( V_248 == & V_253 )
V_73 -> V_1 -> V_3 = V_256 ;
else if ( V_248 == & V_254 )
V_73 -> V_1 -> V_53 = V_256 ;
else if ( V_248 == & V_255 )
V_73 -> V_1 -> V_54 = V_256 ;
}
V_251:
F_56 ( & V_99 -> V_134 ) ;
V_249:
F_199 ( V_99 ) ;
V_190:
return V_109 ? V_109 : V_80 ;
}
int F_201 ( struct V_24 * V_25 )
{
return F_202 ( & V_25 -> V_257 , & V_258 ) ;
}
void F_203 ( struct V_24 * V_25 )
{
F_204 ( & V_25 -> V_257 , & V_258 ) ;
}
void F_205 ( char * V_42 , struct V_144 * V_145 )
{
int V_110 , V_214 ;
int V_6 = V_145 -> V_151 ;
unsigned char * V_130 = V_145 -> V_130 ;
if ( V_145 -> V_146 != V_147 ) {
V_42 [ 0 ] = '\0' ;
return;
}
for ( V_214 = V_6 - 1 ; V_214 >= 0 ; V_214 -- )
if ( V_130 [ V_214 ] )
break;
V_214 ++ ;
for ( V_110 = 0 ; V_110 < V_6 ; V_110 ++ ) {
V_42 += sprintf ( V_42 , L_9 , V_110 == 0 ? L_10 : L_11 , V_130 [ V_110 ] ) ;
if ( V_110 == V_214 && V_214 != V_6 - 1 ) {
sprintf ( V_42 , L_36 ) ;
break;
}
}
}
void F_206 ( char * V_188 , T_3 V_56 , int V_55 )
{
int V_110 = 0 ;
if ( V_56 & V_259 )
V_188 [ V_110 ++ ] = 'F' ;
if ( V_56 & V_61 )
V_188 [ V_110 ++ ] = 'W' ;
else if ( V_56 & V_260 )
V_188 [ V_110 ++ ] = 'D' ;
else if ( V_55 )
V_188 [ V_110 ++ ] = 'R' ;
else
V_188 [ V_110 ++ ] = 'N' ;
if ( V_56 & V_261 )
V_188 [ V_110 ++ ] = 'F' ;
if ( V_56 & V_262 )
V_188 [ V_110 ++ ] = 'A' ;
if ( V_56 & V_263 )
V_188 [ V_110 ++ ] = 'S' ;
if ( V_56 & V_264 )
V_188 [ V_110 ++ ] = 'M' ;
if ( V_56 & V_265 )
V_188 [ V_110 ++ ] = 'E' ;
V_188 [ V_110 ] = '\0' ;
}
