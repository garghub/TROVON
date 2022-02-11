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
V_12 = V_17 -> V_18 . V_12 ;
V_13 = F_3 () ;
V_10 = F_4 ( V_12 , V_19 ,
sizeof( * V_8 ) + V_6 ,
0 , V_13 ) ;
if ( ! V_10 )
return;
V_8 = F_5 ( V_10 ) ;
goto V_20;
}
if ( ! V_2 -> V_21 )
return;
V_8 = F_6 ( V_2 -> V_21 , sizeof( * V_8 ) + V_6 ) ;
if ( V_8 ) {
V_8 -> V_22 = V_23 | V_24 ;
V_8 -> time = F_7 ( F_8 () ) ;
V_20:
V_8 -> V_25 = V_2 -> V_26 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_27 = V_6 ;
memcpy ( ( void * ) V_8 + sizeof( * V_8 ) , V_5 , V_6 ) ;
if ( V_15 )
F_9 ( V_12 , V_10 , 0 , V_13 ) ;
}
}
static void F_10 ( struct V_28 * V_29 )
{
unsigned long V_30 ;
struct V_1 * V_2 ;
V_29 -> V_31 = V_32 ;
F_11 ( & V_33 , V_30 ) ;
F_12 (bt, &running_trace_list, running_list) {
F_1 ( V_2 , V_29 -> V_3 , V_34 , V_29 -> V_35 ,
sizeof( V_29 -> V_35 ) ) ;
}
F_13 ( & V_33 , V_30 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_36 V_37 ;
unsigned long V_30 ;
T_3 V_38 [ 2 ] ;
F_15 ( & V_37 ) ;
V_38 [ 0 ] = V_37 . V_39 ;
V_38 [ 1 ] = V_37 . V_40 ;
F_16 ( V_30 ) ;
F_1 ( V_2 , 0 , V_41 , V_38 , sizeof( V_38 ) ) ;
F_17 ( V_30 ) ;
}
void F_18 ( struct V_1 * V_2 , const char * V_42 , ... )
{
int V_43 ;
T_4 args ;
unsigned long V_30 ;
char * V_44 ;
if ( F_19 ( V_2 -> V_45 != V_46 &&
! V_16 ) )
return;
if ( ! ( V_2 -> V_47 & V_48 ) )
return;
F_16 ( V_30 ) ;
V_44 = F_20 ( V_2 -> V_49 ) ;
va_start ( args , V_42 ) ;
V_43 = F_21 ( V_44 , V_50 , V_42 , args ) ;
va_end ( args ) ;
F_1 ( V_2 , 0 , V_51 , V_44 , V_43 ) ;
F_17 ( V_30 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_3 V_52 , T_5 V_53 ,
T_1 V_3 )
{
if ( ( ( V_2 -> V_47 << V_54 ) & V_52 ) == 0 )
return 1 ;
if ( V_53 && ( V_53 < V_2 -> V_55 || V_53 > V_2 -> V_56 ) )
return 1 ;
if ( V_2 -> V_3 && V_3 != V_2 -> V_3 )
return 1 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , T_5 V_53 , int V_57 ,
int V_58 , T_3 V_52 , int error , int V_27 , void * V_59 )
{
struct V_28 * V_29 = V_60 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_7 * V_8 ;
unsigned long V_30 = 0 ;
unsigned long * V_61 ;
T_1 V_3 ;
int V_14 , V_13 = 0 ;
bool V_15 = V_16 ;
if ( F_19 ( V_2 -> V_45 != V_46 && ! V_15 ) )
return;
V_52 |= V_62 [ V_58 & V_63 ] ;
V_52 |= F_24 ( V_58 , V_64 ) ;
V_52 |= F_24 ( V_58 , V_65 ) ;
V_52 |= F_24 ( V_58 , V_66 ) ;
V_52 |= F_24 ( V_58 , V_67 ) ;
V_52 |= F_24 ( V_58 , V_68 ) ;
V_52 |= F_24 ( V_58 , V_69 ) ;
V_3 = V_29 -> V_3 ;
if ( F_22 ( V_2 , V_52 , V_53 , V_3 ) )
return;
V_14 = F_25 () ;
if ( V_15 ) {
F_26 ( V_60 ) ;
V_12 = V_17 -> V_18 . V_12 ;
V_13 = F_3 () ;
V_10 = F_4 ( V_12 , V_19 ,
sizeof( * V_8 ) + V_27 ,
0 , V_13 ) ;
if ( ! V_10 )
return;
V_8 = F_5 ( V_10 ) ;
goto V_20;
}
if ( F_19 ( V_29 -> V_31 != V_32 ) )
F_10 ( V_29 ) ;
F_16 ( V_30 ) ;
V_8 = F_6 ( V_2 -> V_21 , sizeof( * V_8 ) + V_27 ) ;
if ( V_8 ) {
V_61 = F_27 ( V_2 -> V_61 , V_14 ) ;
V_8 -> V_22 = V_23 | V_24 ;
V_8 -> V_61 = ++ ( * V_61 ) ;
V_8 -> time = F_7 ( F_8 () ) ;
V_20:
V_8 -> V_14 = V_14 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_53 = V_53 ;
V_8 -> V_57 = V_57 ;
V_8 -> V_4 = V_52 ;
V_8 -> V_25 = V_2 -> V_26 ;
V_8 -> error = error ;
V_8 -> V_27 = V_27 ;
if ( V_27 )
memcpy ( ( void * ) V_8 + sizeof( * V_8 ) , V_59 , V_27 ) ;
if ( V_15 ) {
F_9 ( V_12 , V_10 , 0 , V_13 ) ;
return;
}
}
F_17 ( V_30 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_70 ) ;
F_29 ( V_2 -> V_71 ) ;
F_30 ( V_2 -> V_21 ) ;
F_29 ( V_2 -> V_72 ) ;
F_31 ( V_2 -> V_61 ) ;
F_31 ( V_2 -> V_49 ) ;
F_32 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
if ( F_34 ( & V_73 ) )
F_35 () ;
}
int F_36 ( struct V_74 * V_75 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( & V_75 -> V_1 , NULL ) ;
if ( ! V_2 )
return - V_76 ;
if ( V_2 -> V_45 != V_46 )
F_33 ( V_2 ) ;
return 0 ;
}
static T_6 F_38 ( struct V_77 * V_78 , char T_7 * V_12 ,
T_2 V_79 , T_8 * V_80 )
{
struct V_1 * V_2 = V_78 -> V_81 ;
char V_44 [ 16 ] ;
snprintf ( V_44 , sizeof( V_44 ) , L_1 , F_39 ( & V_2 -> V_82 ) ) ;
return F_40 ( V_12 , V_79 , V_80 , V_44 , strlen ( V_44 ) ) ;
}
static T_6 F_41 ( struct V_77 * V_78 , const char T_7 * V_12 ,
T_2 V_79 , T_8 * V_80 )
{
char * V_83 ;
struct V_1 * V_2 ;
if ( V_79 >= V_50 )
return - V_76 ;
V_83 = F_42 ( V_79 + 1 , V_84 ) ;
if ( V_83 == NULL )
return - V_85 ;
if ( F_43 ( V_83 , V_12 , V_79 ) ) {
F_32 ( V_83 ) ;
return - V_86 ;
}
V_83 [ V_79 ] = '\0' ;
V_2 = V_78 -> V_81 ;
F_18 ( V_2 , L_2 , V_83 ) ;
F_32 ( V_83 ) ;
return V_79 ;
}
static int F_44 ( struct V_87 * V_44 , void * V_88 ,
void * V_89 , T_2 V_90 )
{
struct V_1 * V_2 ;
if ( ! F_45 ( V_44 ) )
return 1 ;
V_2 = V_44 -> V_91 -> V_81 ;
F_46 ( & V_2 -> V_82 ) ;
return 0 ;
}
static int F_47 ( struct V_92 * V_92 )
{
F_29 ( V_92 ) ;
return 0 ;
}
static struct V_92 * F_48 ( const char * V_93 ,
struct V_92 * V_94 ,
T_9 V_95 ,
struct V_87 * V_44 ,
int * V_96 )
{
return F_49 ( V_93 , V_95 , V_94 , V_44 ,
& V_97 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
struct V_100 * V_101 = NULL ;
if ( V_99 )
V_101 = V_99 -> V_102 ;
if ( V_101 ) {
V_2 -> V_55 = V_101 -> V_103 ;
V_2 -> V_56 = V_101 -> V_103 + V_101 -> V_104 ;
} else {
V_2 -> V_55 = 0 ;
V_2 -> V_56 = - 1ULL ;
}
}
int F_51 ( struct V_74 * V_75 , char * V_105 , T_10 V_26 ,
struct V_98 * V_99 ,
struct V_106 * V_107 )
{
struct V_1 * V_108 , * V_2 = NULL ;
struct V_92 * V_72 = NULL ;
int V_109 , V_110 ;
if ( ! V_107 -> V_111 || ! V_107 -> V_112 )
return - V_76 ;
strncpy ( V_107 -> V_105 , V_105 , V_113 ) ;
V_107 -> V_105 [ V_113 - 1 ] = '\0' ;
for ( V_110 = 0 ; V_110 < strlen ( V_107 -> V_105 ) ; V_110 ++ )
if ( V_107 -> V_105 [ V_110 ] == '/' )
V_107 -> V_105 [ V_110 ] = '_' ;
V_2 = F_52 ( sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_109 = - V_85 ;
V_2 -> V_61 = F_53 (unsigned long) ;
if ( ! V_2 -> V_61 )
goto V_114;
V_2 -> V_49 = F_54 ( V_50 , F_55 ( char ) ) ;
if ( ! V_2 -> V_49 )
goto V_114;
V_109 = - V_115 ;
F_56 ( & V_116 ) ;
if ( ! V_117 ) {
V_117 = F_57 ( L_3 , NULL ) ;
if ( ! V_117 ) {
F_58 ( & V_116 ) ;
goto V_114;
}
}
F_58 ( & V_116 ) ;
V_72 = F_57 ( V_107 -> V_105 , V_117 ) ;
if ( ! V_72 )
goto V_114;
V_2 -> V_72 = V_72 ;
V_2 -> V_26 = V_26 ;
F_59 ( & V_2 -> V_82 , 0 ) ;
F_60 ( & V_2 -> V_118 ) ;
V_109 = - V_119 ;
V_2 -> V_71 = F_49 ( L_4 , 0444 , V_72 , V_2 ,
& V_120 ) ;
if ( ! V_2 -> V_71 )
goto V_114;
V_2 -> V_70 = F_49 ( L_5 , 0222 , V_72 , V_2 , & V_121 ) ;
if ( ! V_2 -> V_70 )
goto V_114;
V_2 -> V_21 = F_61 ( L_6 , V_72 , V_107 -> V_111 ,
V_107 -> V_112 , & V_122 , V_2 ) ;
if ( ! V_2 -> V_21 )
goto V_114;
V_2 -> V_47 = V_107 -> V_47 ;
if ( ! V_2 -> V_47 )
V_2 -> V_47 = ( V_123 ) - 1 ;
F_50 ( V_2 , V_99 ) ;
if ( V_107 -> V_55 )
V_2 -> V_55 = V_107 -> V_55 ;
if ( V_107 -> V_56 )
V_2 -> V_56 = V_107 -> V_56 ;
V_2 -> V_3 = V_107 -> V_3 ;
V_2 -> V_45 = V_124 ;
V_109 = - V_125 ;
V_108 = F_37 ( & V_75 -> V_1 , V_2 ) ;
if ( V_108 ) {
( void ) F_37 ( & V_75 -> V_1 , V_108 ) ;
goto V_114;
}
if ( F_62 ( & V_73 ) == 1 )
F_63 () ;
return 0 ;
V_114:
F_28 ( V_2 ) ;
return V_109 ;
}
int F_64 ( struct V_74 * V_75 , char * V_105 , T_10 V_26 ,
struct V_98 * V_99 ,
char T_7 * V_126 )
{
struct V_106 V_107 ;
int V_109 ;
V_109 = F_43 ( & V_107 , V_126 , sizeof( V_107 ) ) ;
if ( V_109 )
return - V_86 ;
V_109 = F_51 ( V_75 , V_105 , V_26 , V_99 , & V_107 ) ;
if ( V_109 )
return V_109 ;
if ( F_65 ( V_126 , & V_107 , sizeof( V_107 ) ) ) {
F_36 ( V_75 ) ;
return - V_86 ;
}
return 0 ;
}
static int F_66 ( struct V_74 * V_75 , char * V_105 ,
T_10 V_26 , struct V_98 * V_99 ,
char T_7 * V_126 )
{
struct V_106 V_107 ;
struct V_127 V_128 ;
int V_109 ;
if ( F_43 ( & V_128 , V_126 , sizeof( V_128 ) ) )
return - V_86 ;
V_107 = (struct V_106 ) {
. V_47 = V_128 . V_47 ,
. V_111 = V_128 . V_111 ,
. V_112 = V_128 . V_112 ,
. V_55 = V_128 . V_55 ,
. V_56 = V_128 . V_56 ,
. V_3 = V_128 . V_3 ,
} ;
V_109 = F_51 ( V_75 , V_105 , V_26 , V_99 , & V_107 ) ;
if ( V_109 )
return V_109 ;
if ( F_65 ( V_126 , & V_107 . V_105 , F_67 ( V_107 . V_105 ) ) ) {
F_36 ( V_75 ) ;
return - V_86 ;
}
return 0 ;
}
int F_68 ( struct V_74 * V_75 , int V_129 )
{
int V_109 ;
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 == NULL )
return - V_76 ;
V_109 = - V_76 ;
if ( V_129 ) {
if ( V_2 -> V_45 == V_124 ||
V_2 -> V_45 == V_130 ) {
V_32 ++ ;
F_69 () ;
V_2 -> V_45 = V_46 ;
F_70 ( & V_33 ) ;
F_71 ( & V_2 -> V_118 , & V_131 ) ;
F_72 ( & V_33 ) ;
F_14 ( V_2 ) ;
V_109 = 0 ;
}
} else {
if ( V_2 -> V_45 == V_46 ) {
V_2 -> V_45 = V_130 ;
F_70 ( & V_33 ) ;
F_73 ( & V_2 -> V_118 ) ;
F_72 ( & V_33 ) ;
F_74 ( V_2 -> V_21 ) ;
V_109 = 0 ;
}
}
return V_109 ;
}
int F_75 ( struct V_98 * V_99 , unsigned V_132 , char T_7 * V_126 )
{
struct V_74 * V_75 ;
int V_109 , V_129 = 0 ;
char V_133 [ V_134 ] ;
V_75 = F_76 ( V_99 ) ;
if ( ! V_75 )
return - V_135 ;
F_56 ( & V_99 -> V_136 ) ;
switch ( V_132 ) {
case V_137 :
F_77 ( V_99 , V_133 ) ;
V_109 = F_64 ( V_75 , V_133 , V_99 -> V_138 , V_99 , V_126 ) ;
break;
#if F_78 ( V_139 ) && F_78 ( V_140 )
case V_141 :
F_77 ( V_99 , V_133 ) ;
V_109 = F_66 ( V_75 , V_133 , V_99 -> V_138 , V_99 , V_126 ) ;
break;
#endif
case V_142 :
V_129 = 1 ;
case V_143 :
V_109 = F_68 ( V_75 , V_129 ) ;
break;
case V_144 :
V_109 = F_36 ( V_75 ) ;
break;
default:
V_109 = - V_145 ;
break;
}
F_58 ( & V_99 -> V_136 ) ;
return V_109 ;
}
void F_79 ( struct V_74 * V_75 )
{
if ( V_75 -> V_1 ) {
F_68 ( V_75 , 0 ) ;
F_36 ( V_75 ) ;
}
}
static void F_80 ( struct V_74 * V_75 , struct V_146 * V_147 ,
T_3 V_52 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( F_81 ( ! V_2 ) )
return;
if ( V_147 -> V_148 == V_149 ) {
V_52 |= F_82 ( V_150 ) ;
F_23 ( V_2 , 0 , F_83 ( V_147 ) , V_147 -> V_151 ,
V_52 , V_147 -> V_152 , V_147 -> V_153 , V_147 -> V_132 ) ;
} else {
V_52 |= F_82 ( V_154 ) ;
F_23 ( V_2 , F_84 ( V_147 ) , F_83 ( V_147 ) ,
V_147 -> V_151 , V_52 , V_147 -> V_152 , 0 , NULL ) ;
}
}
static void F_85 ( void * V_155 ,
struct V_74 * V_75 , struct V_146 * V_147 )
{
F_80 ( V_75 , V_147 , V_156 ) ;
}
static void F_86 ( void * V_155 ,
struct V_74 * V_75 , struct V_146 * V_147 )
{
F_80 ( V_75 , V_147 , V_157 ) ;
}
static void F_87 ( void * V_155 ,
struct V_74 * V_75 , struct V_146 * V_147 )
{
F_80 ( V_75 , V_147 , V_158 ) ;
}
static void F_88 ( void * V_155 ,
struct V_74 * V_75 ,
struct V_146 * V_147 )
{
F_80 ( V_75 , V_147 , V_159 ) ;
}
static void F_89 ( void * V_155 ,
struct V_74 * V_75 ,
struct V_146 * V_147 )
{
F_80 ( V_75 , V_147 , V_160 ) ;
}
static void F_90 ( struct V_74 * V_75 , struct V_161 * V_161 ,
T_3 V_52 , int error )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( F_81 ( ! V_2 ) )
return;
if ( ! error && ! F_91 ( V_161 , V_162 ) )
error = V_119 ;
F_23 ( V_2 , V_161 -> V_163 , V_161 -> V_164 , V_161 -> V_165 , V_52 ,
error , 0 , NULL ) ;
}
static void F_92 ( void * V_155 ,
struct V_74 * V_75 , struct V_161 * V_161 )
{
F_90 ( V_75 , V_161 , V_166 , 0 ) ;
}
static void F_93 ( void * V_155 ,
struct V_74 * V_75 , struct V_161 * V_161 ,
int error )
{
F_90 ( V_75 , V_161 , V_160 , error ) ;
}
static void F_94 ( void * V_155 ,
struct V_74 * V_75 ,
struct V_146 * V_147 ,
struct V_161 * V_161 )
{
F_90 ( V_75 , V_161 , V_167 , 0 ) ;
}
static void F_95 ( void * V_155 ,
struct V_74 * V_75 ,
struct V_146 * V_147 ,
struct V_161 * V_161 )
{
F_90 ( V_75 , V_161 , V_168 , 0 ) ;
}
static void F_96 ( void * V_155 ,
struct V_74 * V_75 , struct V_161 * V_161 )
{
F_90 ( V_75 , V_161 , V_169 , 0 ) ;
}
static void F_97 ( void * V_155 ,
struct V_74 * V_75 ,
struct V_161 * V_161 , int V_58 )
{
if ( V_161 )
F_90 ( V_75 , V_161 , V_170 , 0 ) ;
else {
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , V_58 , V_170 , 0 , 0 , NULL ) ;
}
}
static void F_98 ( void * V_155 ,
struct V_74 * V_75 ,
struct V_161 * V_161 , int V_58 )
{
if ( V_161 )
F_90 ( V_75 , V_161 , V_171 , 0 ) ;
else {
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , V_58 , V_171 ,
0 , 0 , NULL ) ;
}
}
static void F_99 ( void * V_155 , struct V_74 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , 0 , V_172 , 0 , 0 , NULL ) ;
}
static void F_100 ( void * V_155 , struct V_74 * V_75 ,
unsigned int V_173 , bool V_174 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 ) {
T_11 V_175 = F_101 ( V_173 ) ;
T_3 V_52 ;
if ( V_174 )
V_52 = V_176 ;
else
V_52 = V_177 ;
F_23 ( V_2 , 0 , 0 , 0 , V_52 , 0 , sizeof( V_175 ) , & V_175 ) ;
}
}
static void F_102 ( void * V_155 ,
struct V_74 * V_75 , struct V_161 * V_161 ,
unsigned int V_178 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 ) {
T_11 V_175 = F_101 ( V_178 ) ;
F_23 ( V_2 , V_161 -> V_163 , V_161 -> V_164 , V_161 -> V_165 ,
V_179 , ! F_91 ( V_161 , V_162 ) ,
sizeof( V_175 ) , & V_175 ) ;
}
}
static void F_103 ( void * V_155 ,
struct V_74 * V_75 , struct V_161 * V_161 ,
T_10 V_26 , T_5 V_180 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
struct V_181 V_182 ;
if ( F_81 ( ! V_2 ) )
return;
V_182 . V_183 = F_104 ( V_26 ) ;
V_182 . V_184 = F_104 ( V_161 -> V_185 -> V_138 ) ;
V_182 . V_186 = F_101 ( V_180 ) ;
F_23 ( V_2 , V_161 -> V_163 , V_161 -> V_164 , V_161 -> V_165 ,
V_187 , ! F_91 ( V_161 , V_162 ) ,
sizeof( V_182 ) , & V_182 ) ;
}
static void F_105 ( void * V_155 ,
struct V_74 * V_75 ,
struct V_146 * V_147 , T_10 V_26 ,
T_5 V_180 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
struct V_181 V_182 ;
if ( F_81 ( ! V_2 ) )
return;
V_182 . V_183 = F_104 ( V_26 ) ;
V_182 . V_184 = F_104 ( F_106 ( V_147 -> V_188 ) ) ;
V_182 . V_186 = F_101 ( V_180 ) ;
F_23 ( V_2 , F_84 ( V_147 ) , F_83 ( V_147 ) ,
F_107 ( V_147 ) , V_187 , ! ! V_147 -> V_152 ,
sizeof( V_182 ) , & V_182 ) ;
}
void F_108 ( struct V_74 * V_75 ,
struct V_146 * V_147 ,
void * V_5 , T_2 V_6 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( F_81 ( ! V_2 ) )
return;
if ( V_147 -> V_148 == V_149 )
F_23 ( V_2 , 0 , F_83 ( V_147 ) , 0 ,
V_189 , V_147 -> V_152 , V_6 , V_5 ) ;
else
F_23 ( V_2 , F_84 ( V_147 ) , F_83 ( V_147 ) , 0 ,
V_189 , V_147 -> V_152 , V_6 , V_5 ) ;
}
static void F_63 ( void )
{
int V_109 ;
V_109 = F_109 ( F_85 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_111 ( F_86 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_112 ( F_87 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_113 ( F_88 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_114 ( F_89 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_115 ( F_92 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_116 ( F_93 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_117 ( F_94 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_118 ( F_95 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_119 ( F_96 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_120 ( F_97 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_121 ( F_98 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_122 ( F_99 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_123 ( F_100 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_124 ( F_102 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_125 ( F_103 , NULL ) ;
F_110 ( V_109 ) ;
V_109 = F_126 ( F_105 , NULL ) ;
F_110 ( V_109 ) ;
}
static void F_35 ( void )
{
F_127 ( F_105 , NULL ) ;
F_128 ( F_103 , NULL ) ;
F_129 ( F_102 , NULL ) ;
F_130 ( F_100 , NULL ) ;
F_131 ( F_99 , NULL ) ;
F_132 ( F_98 , NULL ) ;
F_133 ( F_97 , NULL ) ;
F_134 ( F_96 , NULL ) ;
F_135 ( F_95 , NULL ) ;
F_136 ( F_94 , NULL ) ;
F_137 ( F_93 , NULL ) ;
F_138 ( F_92 , NULL ) ;
F_139 ( F_89 , NULL ) ;
F_140 ( F_88 , NULL ) ;
F_141 ( F_87 , NULL ) ;
F_142 ( F_86 , NULL ) ;
F_143 ( F_85 , NULL ) ;
F_144 () ;
}
static void F_145 ( char * V_190 , const struct V_7 * V_8 )
{
int V_110 = 0 ;
int V_191 = V_8 -> V_4 >> V_54 ;
if ( V_8 -> V_4 == V_51 ) {
V_190 [ V_110 ++ ] = 'N' ;
goto V_192;
}
if ( V_191 & V_193 )
V_190 [ V_110 ++ ] = 'F' ;
if ( V_191 & V_194 )
V_190 [ V_110 ++ ] = 'D' ;
else if ( V_191 & V_195 )
V_190 [ V_110 ++ ] = 'W' ;
else if ( V_8 -> V_57 )
V_190 [ V_110 ++ ] = 'R' ;
else
V_190 [ V_110 ++ ] = 'N' ;
if ( V_191 & V_196 )
V_190 [ V_110 ++ ] = 'F' ;
if ( V_191 & V_197 )
V_190 [ V_110 ++ ] = 'A' ;
if ( V_191 & V_198 )
V_190 [ V_110 ++ ] = 'S' ;
if ( V_191 & V_199 )
V_190 [ V_110 ++ ] = 'M' ;
V_192:
V_190 [ V_110 ] = '\0' ;
}
static inline
const struct V_7 * F_146 ( const struct V_200 * V_201 )
{
return ( const struct V_7 * ) V_201 ;
}
static inline const void * F_147 ( const struct V_200 * V_201 )
{
return F_146 ( V_201 ) + 1 ;
}
static inline T_3 F_148 ( const struct V_200 * V_201 )
{
return F_146 ( V_201 ) -> V_4 ;
}
static inline T_3 F_149 ( const struct V_200 * V_201 )
{
return F_146 ( V_201 ) -> V_57 ;
}
static inline T_3 F_150 ( const struct V_200 * V_201 )
{
return F_146 ( V_201 ) -> V_57 >> 9 ;
}
static inline unsigned long long F_151 ( const struct V_200 * V_201 )
{
return F_146 ( V_201 ) -> V_53 ;
}
static inline T_12 F_152 ( const struct V_200 * V_201 )
{
return F_146 ( V_201 ) -> error ;
}
static T_13 F_153 ( const struct V_200 * V_201 )
{
const T_13 * V_202 = F_147 ( V_201 ) ;
return F_154 ( * V_202 ) ;
}
static void F_155 ( const struct V_200 * V_201 ,
struct V_181 * V_182 )
{
const struct V_181 * V_203 = F_147 ( V_201 ) ;
T_13 V_186 = V_203 -> V_186 ;
V_182 -> V_183 = F_156 ( V_203 -> V_183 ) ;
V_182 -> V_184 = F_156 ( V_203 -> V_184 ) ;
V_182 -> V_186 = F_154 ( V_186 ) ;
}
static int F_157 ( struct V_204 * V_205 , const char * V_206 )
{
char V_190 [ V_207 ] ;
unsigned long long V_208 = V_205 -> V_208 ;
unsigned long V_209 = F_158 ( V_208 , V_210 ) ;
unsigned V_211 = ( unsigned long ) V_208 ;
const struct V_7 * V_8 = F_146 ( V_205 -> V_201 ) ;
F_145 ( V_190 , V_8 ) ;
return F_159 ( & V_205 -> V_212 ,
L_7 ,
F_160 ( V_8 -> V_25 ) , F_161 ( V_8 -> V_25 ) , V_205 -> V_14 ,
V_211 , V_209 , V_205 -> V_201 -> V_3 , V_206 , V_190 ) ;
}
static int F_162 ( struct V_204 * V_205 , const char * V_206 )
{
char V_190 [ V_207 ] ;
const struct V_7 * V_8 = F_146 ( V_205 -> V_201 ) ;
F_145 ( V_190 , V_8 ) ;
return F_159 ( & V_205 -> V_212 , L_8 ,
F_160 ( V_8 -> V_25 ) , F_161 ( V_8 -> V_25 ) , V_206 , V_190 ) ;
}
static int F_163 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
const unsigned char * V_215 ;
int V_27 ;
int V_110 , V_216 , V_109 ;
V_215 = F_147 ( V_201 ) ;
V_27 = F_146 ( V_201 ) -> V_27 ;
if ( ! V_27 )
return 1 ;
for ( V_216 = V_27 - 1 ; V_216 >= 0 ; V_216 -- )
if ( V_215 [ V_216 ] )
break;
V_216 ++ ;
if ( ! F_164 ( V_214 , '(' ) )
return 0 ;
for ( V_110 = 0 ; V_110 < V_27 ; V_110 ++ ) {
V_109 = F_159 ( V_214 , L_9 ,
V_110 == 0 ? L_10 : L_11 , V_215 [ V_110 ] ) ;
if ( ! V_109 )
return V_109 ;
if ( V_110 == V_216 && V_216 != V_27 - 1 )
return F_165 ( V_214 , L_12 ) ;
}
return F_165 ( V_214 , L_13 ) ;
}
static int F_166 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
char V_132 [ V_217 ] ;
F_167 ( V_201 -> V_3 , V_132 ) ;
if ( F_148 ( V_201 ) & F_82 ( V_150 ) ) {
int V_109 ;
V_109 = F_159 ( V_214 , L_14 , F_149 ( V_201 ) ) ;
if ( ! V_109 )
return 0 ;
V_109 = F_163 ( V_214 , V_201 ) ;
if ( ! V_109 )
return 0 ;
return F_159 ( V_214 , L_15 , V_132 ) ;
} else {
if ( F_150 ( V_201 ) )
return F_159 ( V_214 , L_16 ,
F_151 ( V_201 ) , F_150 ( V_201 ) , V_132 ) ;
return F_159 ( V_214 , L_15 , V_132 ) ;
}
}
static int F_168 ( struct V_213 * V_214 ,
const struct V_200 * V_201 )
{
if ( F_148 ( V_201 ) & F_82 ( V_150 ) ) {
int V_109 ;
V_109 = F_163 ( V_214 , V_201 ) ;
if ( V_109 )
return F_159 ( V_214 , L_17 , F_152 ( V_201 ) ) ;
return 0 ;
} else {
if ( F_150 ( V_201 ) )
return F_159 ( V_214 , L_18 ,
F_151 ( V_201 ) ,
F_150 ( V_201 ) , F_152 ( V_201 ) ) ;
return F_159 ( V_214 , L_19 ,
F_151 ( V_201 ) , F_152 ( V_201 ) ) ;
}
}
static int F_169 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
struct V_181 V_182 = { . V_183 = 0 , } ;
F_155 ( V_201 , & V_182 ) ;
return F_159 ( V_214 , L_20 ,
F_151 ( V_201 ) , F_150 ( V_201 ) ,
F_160 ( V_182 . V_183 ) , F_161 ( V_182 . V_183 ) ,
( unsigned long long ) V_182 . V_186 ) ;
}
static int F_170 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
char V_132 [ V_217 ] ;
F_167 ( V_201 -> V_3 , V_132 ) ;
return F_159 ( V_214 , L_15 , V_132 ) ;
}
static int F_171 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
char V_132 [ V_217 ] ;
F_167 ( V_201 -> V_3 , V_132 ) ;
return F_159 ( V_214 , L_21 , V_132 , F_153 ( V_201 ) ) ;
}
static int F_172 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
char V_132 [ V_217 ] ;
F_167 ( V_201 -> V_3 , V_132 ) ;
return F_159 ( V_214 , L_22 , F_151 ( V_201 ) ,
F_153 ( V_201 ) , V_132 ) ;
}
static int F_173 ( struct V_213 * V_214 , const struct V_200 * V_201 )
{
int V_109 ;
const struct V_7 * V_8 = F_146 ( V_201 ) ;
V_109 = F_174 ( V_214 , V_8 + 1 , V_8 -> V_27 ) ;
if ( V_109 )
return F_164 ( V_214 , '\n' ) ;
return V_109 ;
}
static void F_175 ( struct V_218 * V_219 )
{
if ( ! ( V_220 . V_202 & V_221 ) )
return;
F_176 ( V_219 , L_23
L_24 ) ;
}
static void F_177 ( struct V_222 * V_223 )
{
V_16 = true ;
}
static int F_178 ( struct V_222 * V_223 )
{
V_17 = V_223 ;
F_177 ( V_223 ) ;
return 0 ;
}
static void F_179 ( struct V_222 * V_223 )
{
V_16 = false ;
}
static void F_180 ( struct V_222 * V_223 )
{
F_179 ( V_223 ) ;
}
static enum V_224 F_181 ( struct V_204 * V_205 ,
bool V_225 )
{
struct V_213 * V_214 = & V_205 -> V_212 ;
const struct V_7 * V_8 ;
V_123 V_52 ;
int V_109 ;
bool V_226 ;
T_14 * V_227 ;
V_8 = F_146 ( V_205 -> V_201 ) ;
V_52 = V_8 -> V_4 & ( ( 1 << V_54 ) - 1 ) ;
V_226 = ! ! ( V_228 & V_229 ) ;
V_227 = V_225 ? & F_157 : & F_162 ;
if ( V_8 -> V_4 == V_51 ) {
V_109 = V_227 ( V_205 , V_226 ? L_25 : L_26 ) ;
if ( V_109 )
V_109 = F_173 ( V_214 , V_205 -> V_201 ) ;
goto V_192;
}
if ( F_19 ( V_52 == 0 || V_52 >= F_67 ( V_230 ) ) )
V_109 = F_159 ( V_214 , L_27 , V_52 ) ;
else {
V_109 = V_227 ( V_205 , V_230 [ V_52 ] . V_206 [ V_226 ] ) ;
if ( V_109 )
V_109 = V_230 [ V_52 ] . F_182 ( V_214 , V_205 -> V_201 ) ;
}
V_192:
return V_109 ? V_231 : V_232 ;
}
static enum V_224 F_183 ( struct V_204 * V_205 ,
int V_30 , struct V_233 * V_10 )
{
return F_181 ( V_205 , false ) ;
}
static int F_184 ( struct V_204 * V_205 )
{
struct V_213 * V_214 = & V_205 -> V_212 ;
struct V_7 * V_8 = (struct V_7 * ) V_205 -> V_201 ;
const int V_234 = F_185 ( struct V_7 , V_53 ) ;
struct V_7 V_235 = {
. V_22 = V_23 | V_24 ,
. time = V_205 -> V_208 ,
} ;
if ( ! F_174 ( V_214 , & V_235 , V_234 ) )
return 0 ;
return F_174 ( V_214 , & V_8 -> V_53 ,
sizeof( V_235 ) - V_234 + V_8 -> V_27 ) ;
}
static enum V_224
F_186 ( struct V_204 * V_205 , int V_30 ,
struct V_233 * V_10 )
{
return F_184 ( V_205 ) ?
V_231 : V_232 ;
}
static enum V_224 F_187 ( struct V_204 * V_205 )
{
if ( ! ( V_220 . V_202 & V_221 ) )
return V_236 ;
return F_181 ( V_205 , true ) ;
}
static int F_188 ( T_3 V_237 , T_3 V_238 , int V_239 )
{
if ( V_238 == V_221 ) {
if ( V_239 )
V_228 &= ~ V_240 ;
else
V_228 |= V_240 ;
}
return 0 ;
}
static int T_15 F_189 ( void )
{
if ( ! F_190 ( & V_241 ) ) {
F_191 ( L_28 ) ;
return 1 ;
}
if ( F_192 ( & V_15 ) != 0 ) {
F_191 ( L_29 ) ;
F_193 ( & V_241 ) ;
return 1 ;
}
return 0 ;
}
static int F_194 ( struct V_74 * V_75 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( & V_75 -> V_1 , NULL ) ;
if ( V_2 == NULL )
return - V_76 ;
if ( F_34 ( & V_73 ) )
F_35 () ;
F_70 ( & V_33 ) ;
F_195 ( & V_2 -> V_118 ) ;
F_72 ( & V_33 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_196 ( struct V_74 * V_75 ,
struct V_98 * V_99 )
{
struct V_1 * V_108 , * V_2 = NULL ;
int V_109 = - V_85 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_49 = F_54 ( V_50 , F_55 ( char ) ) ;
if ( ! V_2 -> V_49 )
goto V_242;
V_2 -> V_26 = V_99 -> V_138 ;
V_2 -> V_47 = ( V_123 ) - 1 ;
F_50 ( V_2 , V_99 ) ;
V_108 = F_37 ( & V_75 -> V_1 , V_2 ) ;
if ( V_108 != NULL ) {
( void ) F_37 ( & V_75 -> V_1 , V_108 ) ;
V_109 = - V_125 ;
goto V_242;
}
if ( F_62 ( & V_73 ) == 1 )
F_63 () ;
return 0 ;
V_242:
F_28 ( V_2 ) ;
return V_109 ;
}
static int F_197 ( const char * V_243 )
{
int V_110 ;
int V_244 = 0 ;
char * V_44 , * V_214 , * V_245 ;
V_44 = F_198 ( V_243 , V_84 ) ;
if ( V_44 == NULL )
return - V_85 ;
V_214 = F_199 ( V_44 ) ;
while ( 1 ) {
V_245 = F_200 ( & V_214 , L_30 ) ;
if ( V_245 == NULL )
break;
if ( * V_245 == '\0' )
continue;
for ( V_110 = 0 ; V_110 < F_67 ( V_246 ) ; V_110 ++ ) {
if ( strcasecmp ( V_245 , V_246 [ V_110 ] . V_243 ) == 0 ) {
V_244 |= V_246 [ V_110 ] . V_244 ;
break;
}
}
if ( V_110 == F_67 ( V_246 ) ) {
V_244 = - V_76 ;
break;
}
}
F_32 ( V_44 ) ;
return V_244 ;
}
static T_6 F_201 ( char * V_44 , int V_244 )
{
int V_110 ;
char * V_247 = V_44 ;
for ( V_110 = 0 ; V_110 < F_67 ( V_246 ) ; V_110 ++ ) {
if ( V_244 & V_246 [ V_110 ] . V_244 ) {
V_247 += sprintf ( V_247 , L_31 ,
( V_247 == V_44 ) ? L_10 : L_30 , V_246 [ V_110 ] . V_243 ) ;
}
}
* V_247 ++ = '\n' ;
return V_247 - V_44 ;
}
static struct V_74 * F_202 ( struct V_98 * V_99 )
{
if ( V_99 -> V_248 == NULL )
return NULL ;
return F_76 ( V_99 ) ;
}
static T_6 F_203 ( struct V_25 * V_26 ,
struct V_249 * V_250 ,
char * V_44 )
{
struct V_100 * V_247 = F_204 ( V_26 ) ;
struct V_74 * V_75 ;
struct V_98 * V_99 ;
T_6 V_109 = - V_135 ;
V_99 = F_205 ( F_206 ( V_247 ) ) ;
if ( V_99 == NULL )
goto V_192;
V_75 = F_202 ( V_99 ) ;
if ( V_75 == NULL )
goto V_251;
F_56 ( & V_99 -> V_136 ) ;
if ( V_250 == & V_252 ) {
V_109 = sprintf ( V_44 , L_1 , ! ! V_75 -> V_1 ) ;
goto V_253;
}
if ( V_75 -> V_1 == NULL )
V_109 = sprintf ( V_44 , L_32 ) ;
else if ( V_250 == & V_254 )
V_109 = F_201 ( V_44 , V_75 -> V_1 -> V_47 ) ;
else if ( V_250 == & V_255 )
V_109 = sprintf ( V_44 , L_1 , V_75 -> V_1 -> V_3 ) ;
else if ( V_250 == & V_256 )
V_109 = sprintf ( V_44 , L_33 , V_75 -> V_1 -> V_55 ) ;
else if ( V_250 == & V_257 )
V_109 = sprintf ( V_44 , L_33 , V_75 -> V_1 -> V_56 ) ;
V_253:
F_58 ( & V_99 -> V_136 ) ;
V_251:
F_207 ( V_99 ) ;
V_192:
return V_109 ;
}
static T_6 F_208 ( struct V_25 * V_26 ,
struct V_249 * V_250 ,
const char * V_44 , T_2 V_79 )
{
struct V_98 * V_99 ;
struct V_74 * V_75 ;
struct V_100 * V_247 ;
T_16 V_258 ;
T_6 V_109 = - V_76 ;
if ( V_79 == 0 )
goto V_192;
if ( V_250 == & V_254 ) {
if ( sscanf ( V_44 , L_34 , & V_258 ) != 1 ) {
V_109 = F_197 ( V_44 ) ;
if ( V_109 < 0 )
goto V_192;
V_258 = V_109 ;
}
} else if ( sscanf ( V_44 , L_35 , & V_258 ) != 1 )
goto V_192;
V_109 = - V_135 ;
V_247 = F_204 ( V_26 ) ;
V_99 = F_205 ( F_206 ( V_247 ) ) ;
if ( V_99 == NULL )
goto V_192;
V_75 = F_202 ( V_99 ) ;
if ( V_75 == NULL )
goto V_251;
F_56 ( & V_99 -> V_136 ) ;
if ( V_250 == & V_252 ) {
if ( V_258 )
V_109 = F_196 ( V_75 , V_99 ) ;
else
V_109 = F_194 ( V_75 ) ;
goto V_253;
}
V_109 = 0 ;
if ( V_75 -> V_1 == NULL )
V_109 = F_196 ( V_75 , V_99 ) ;
if ( V_109 == 0 ) {
if ( V_250 == & V_254 )
V_75 -> V_1 -> V_47 = V_258 ;
else if ( V_250 == & V_255 )
V_75 -> V_1 -> V_3 = V_258 ;
else if ( V_250 == & V_256 )
V_75 -> V_1 -> V_55 = V_258 ;
else if ( V_250 == & V_257 )
V_75 -> V_1 -> V_56 = V_258 ;
}
V_253:
F_58 ( & V_99 -> V_136 ) ;
V_251:
F_207 ( V_99 ) ;
V_192:
return V_109 ? V_109 : V_79 ;
}
int F_209 ( struct V_25 * V_26 )
{
return F_210 ( & V_26 -> V_259 , & V_260 ) ;
}
void F_211 ( struct V_25 * V_26 )
{
F_212 ( & V_26 -> V_259 , & V_260 ) ;
}
void F_213 ( char * V_44 , struct V_146 * V_147 )
{
int V_110 , V_216 ;
int V_6 = V_147 -> V_153 ;
unsigned char * V_132 = V_147 -> V_132 ;
if ( V_147 -> V_148 != V_149 ) {
V_44 [ 0 ] = '\0' ;
return;
}
for ( V_216 = V_6 - 1 ; V_216 >= 0 ; V_216 -- )
if ( V_132 [ V_216 ] )
break;
V_216 ++ ;
for ( V_110 = 0 ; V_110 < V_6 ; V_110 ++ ) {
V_44 += sprintf ( V_44 , L_9 , V_110 == 0 ? L_10 : L_11 , V_132 [ V_110 ] ) ;
if ( V_110 == V_216 && V_216 != V_6 - 1 ) {
sprintf ( V_44 , L_36 ) ;
break;
}
}
}
void F_214 ( char * V_190 , T_3 V_58 , int V_57 )
{
int V_110 = 0 ;
if ( V_58 & V_261 )
V_190 [ V_110 ++ ] = 'F' ;
if ( V_58 & V_63 )
V_190 [ V_110 ++ ] = 'W' ;
else if ( V_58 & V_262 )
V_190 [ V_110 ++ ] = 'D' ;
else if ( V_57 )
V_190 [ V_110 ++ ] = 'R' ;
else
V_190 [ V_110 ++ ] = 'N' ;
if ( V_58 & V_263 )
V_190 [ V_110 ++ ] = 'F' ;
if ( V_58 & V_264 )
V_190 [ V_110 ++ ] = 'A' ;
if ( V_58 & V_265 )
V_190 [ V_110 ++ ] = 'S' ;
if ( V_58 & V_266 )
V_190 [ V_110 ++ ] = 'M' ;
if ( V_58 & V_267 )
V_190 [ V_110 ++ ] = 'E' ;
V_190 [ V_110 ] = '\0' ;
}
