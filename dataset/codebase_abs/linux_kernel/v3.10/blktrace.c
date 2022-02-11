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
static void F_10 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
V_29 -> V_30 = V_31 ;
F_1 ( V_2 , V_29 -> V_3 , V_32 , V_29 -> V_33 , sizeof( V_29 -> V_33 ) ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_34 V_35 ;
unsigned long V_36 ;
T_3 V_37 [ 2 ] ;
F_12 ( & V_35 ) ;
V_37 [ 0 ] = V_35 . V_38 ;
V_37 [ 1 ] = V_35 . V_39 ;
F_13 ( V_36 ) ;
F_1 ( V_2 , 0 , V_40 , V_37 , sizeof( V_37 ) ) ;
F_14 ( V_36 ) ;
}
void F_15 ( struct V_1 * V_2 , const char * V_41 , ... )
{
int V_42 ;
T_4 args ;
unsigned long V_36 ;
char * V_43 ;
if ( F_16 ( V_2 -> V_44 != V_45 &&
! V_16 ) )
return;
if ( ! ( V_2 -> V_46 & V_47 ) )
return;
F_13 ( V_36 ) ;
V_43 = F_17 ( V_2 -> V_48 ) ;
va_start ( args , V_41 ) ;
V_42 = F_18 ( V_43 , V_49 , V_41 , args ) ;
va_end ( args ) ;
F_1 ( V_2 , 0 , V_50 , V_43 , V_42 ) ;
F_14 ( V_36 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_3 V_51 , T_5 V_52 ,
T_1 V_3 )
{
if ( ( ( V_2 -> V_46 << V_53 ) & V_51 ) == 0 )
return 1 ;
if ( V_52 && ( V_52 < V_2 -> V_54 || V_52 > V_2 -> V_55 ) )
return 1 ;
if ( V_2 -> V_3 && V_3 != V_2 -> V_3 )
return 1 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , T_5 V_52 , int V_56 ,
int V_57 , T_3 V_51 , int error , int V_27 , void * V_58 )
{
struct V_28 * V_29 = V_59 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_7 * V_8 ;
unsigned long V_36 = 0 ;
unsigned long * V_60 ;
T_1 V_3 ;
int V_14 , V_13 = 0 ;
bool V_15 = V_16 ;
if ( F_16 ( V_2 -> V_44 != V_45 && ! V_15 ) )
return;
V_51 |= V_61 [ V_57 & V_62 ] ;
V_51 |= F_21 ( V_57 , V_63 ) ;
V_51 |= F_21 ( V_57 , V_64 ) ;
V_51 |= F_21 ( V_57 , V_65 ) ;
V_51 |= F_21 ( V_57 , V_66 ) ;
V_51 |= F_21 ( V_57 , V_67 ) ;
V_51 |= F_21 ( V_57 , V_68 ) ;
V_3 = V_29 -> V_3 ;
if ( F_19 ( V_2 , V_51 , V_52 , V_3 ) )
return;
V_14 = F_22 () ;
if ( V_15 ) {
F_23 ( V_59 ) ;
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
F_13 ( V_36 ) ;
if ( F_16 ( V_29 -> V_30 != V_31 ) )
F_10 ( V_2 , V_29 ) ;
V_8 = F_6 ( V_2 -> V_21 , sizeof( * V_8 ) + V_27 ) ;
if ( V_8 ) {
V_60 = F_24 ( V_2 -> V_60 , V_14 ) ;
V_8 -> V_22 = V_23 | V_24 ;
V_8 -> V_60 = ++ ( * V_60 ) ;
V_8 -> time = F_7 ( F_8 () ) ;
V_20:
V_8 -> V_14 = V_14 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_52 = V_52 ;
V_8 -> V_56 = V_56 ;
V_8 -> V_4 = V_51 ;
V_8 -> V_25 = V_2 -> V_26 ;
V_8 -> error = error ;
V_8 -> V_27 = V_27 ;
if ( V_27 )
memcpy ( ( void * ) V_8 + sizeof( * V_8 ) , V_58 , V_27 ) ;
if ( V_15 ) {
F_9 ( V_12 , V_10 , 0 , V_13 ) ;
return;
}
}
F_14 ( V_36 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_69 ) ;
F_26 ( V_2 -> V_70 ) ;
F_27 ( V_2 -> V_21 ) ;
F_26 ( V_2 -> V_71 ) ;
F_28 ( V_2 -> V_60 ) ;
F_28 ( V_2 -> V_48 ) ;
F_29 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
if ( F_31 ( & V_72 ) )
F_32 () ;
}
int F_33 ( struct V_73 * V_74 )
{
struct V_1 * V_2 ;
V_2 = F_34 ( & V_74 -> V_1 , NULL ) ;
if ( ! V_2 )
return - V_75 ;
if ( V_2 -> V_44 != V_45 )
F_30 ( V_2 ) ;
return 0 ;
}
static T_6 F_35 ( struct V_76 * V_77 , char T_7 * V_12 ,
T_2 V_78 , T_8 * V_79 )
{
struct V_1 * V_2 = V_77 -> V_80 ;
char V_43 [ 16 ] ;
snprintf ( V_43 , sizeof( V_43 ) , L_1 , F_36 ( & V_2 -> V_81 ) ) ;
return F_37 ( V_12 , V_78 , V_79 , V_43 , strlen ( V_43 ) ) ;
}
static T_6 F_38 ( struct V_76 * V_77 , const char T_7 * V_12 ,
T_2 V_78 , T_8 * V_79 )
{
char * V_82 ;
struct V_1 * V_2 ;
if ( V_78 >= V_49 )
return - V_75 ;
V_82 = F_39 ( V_78 + 1 , V_83 ) ;
if ( V_82 == NULL )
return - V_84 ;
if ( F_40 ( V_82 , V_12 , V_78 ) ) {
F_29 ( V_82 ) ;
return - V_85 ;
}
V_82 [ V_78 ] = '\0' ;
V_2 = V_77 -> V_80 ;
F_15 ( V_2 , L_2 , V_82 ) ;
F_29 ( V_82 ) ;
return V_78 ;
}
static int F_41 ( struct V_86 * V_43 , void * V_87 ,
void * V_88 , T_2 V_89 )
{
struct V_1 * V_2 ;
if ( ! F_42 ( V_43 ) )
return 1 ;
V_2 = V_43 -> V_90 -> V_80 ;
F_43 ( & V_2 -> V_81 ) ;
return 0 ;
}
static int F_44 ( struct V_91 * V_91 )
{
F_26 ( V_91 ) ;
return 0 ;
}
static struct V_91 * F_45 ( const char * V_92 ,
struct V_91 * V_93 ,
T_9 V_94 ,
struct V_86 * V_43 ,
int * V_95 )
{
return F_46 ( V_92 , V_94 , V_93 , V_43 ,
& V_96 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_97 * V_98 )
{
struct V_99 * V_100 = NULL ;
if ( V_98 )
V_100 = V_98 -> V_101 ;
if ( V_100 ) {
V_2 -> V_54 = V_100 -> V_102 ;
V_2 -> V_55 = V_100 -> V_102 + V_100 -> V_103 ;
} else {
V_2 -> V_54 = 0 ;
V_2 -> V_55 = - 1ULL ;
}
}
int F_48 ( struct V_73 * V_74 , char * V_104 , T_10 V_26 ,
struct V_97 * V_98 ,
struct V_105 * V_106 )
{
struct V_1 * V_107 , * V_2 = NULL ;
struct V_91 * V_71 = NULL ;
int V_108 , V_109 ;
if ( ! V_106 -> V_110 || ! V_106 -> V_111 )
return - V_75 ;
strncpy ( V_106 -> V_104 , V_104 , V_112 ) ;
V_106 -> V_104 [ V_112 - 1 ] = '\0' ;
for ( V_109 = 0 ; V_109 < strlen ( V_106 -> V_104 ) ; V_109 ++ )
if ( V_106 -> V_104 [ V_109 ] == '/' )
V_106 -> V_104 [ V_109 ] = '_' ;
V_2 = F_49 ( sizeof( * V_2 ) , V_83 ) ;
if ( ! V_2 )
return - V_84 ;
V_108 = - V_84 ;
V_2 -> V_60 = F_50 (unsigned long) ;
if ( ! V_2 -> V_60 )
goto V_113;
V_2 -> V_48 = F_51 ( V_49 , F_52 ( char ) ) ;
if ( ! V_2 -> V_48 )
goto V_113;
V_108 = - V_114 ;
F_53 ( & V_115 ) ;
if ( ! V_116 ) {
V_116 = F_54 ( L_3 , NULL ) ;
if ( ! V_116 ) {
F_55 ( & V_115 ) ;
goto V_113;
}
}
F_55 ( & V_115 ) ;
V_71 = F_54 ( V_106 -> V_104 , V_116 ) ;
if ( ! V_71 )
goto V_113;
V_2 -> V_71 = V_71 ;
V_2 -> V_26 = V_26 ;
F_56 ( & V_2 -> V_81 , 0 ) ;
V_108 = - V_117 ;
V_2 -> V_70 = F_46 ( L_4 , 0444 , V_71 , V_2 ,
& V_118 ) ;
if ( ! V_2 -> V_70 )
goto V_113;
V_2 -> V_69 = F_46 ( L_5 , 0222 , V_71 , V_2 , & V_119 ) ;
if ( ! V_2 -> V_69 )
goto V_113;
V_2 -> V_21 = F_57 ( L_6 , V_71 , V_106 -> V_110 ,
V_106 -> V_111 , & V_120 , V_2 ) ;
if ( ! V_2 -> V_21 )
goto V_113;
V_2 -> V_46 = V_106 -> V_46 ;
if ( ! V_2 -> V_46 )
V_2 -> V_46 = ( V_121 ) - 1 ;
F_47 ( V_2 , V_98 ) ;
if ( V_106 -> V_54 )
V_2 -> V_54 = V_106 -> V_54 ;
if ( V_106 -> V_55 )
V_2 -> V_55 = V_106 -> V_55 ;
V_2 -> V_3 = V_106 -> V_3 ;
V_2 -> V_44 = V_122 ;
V_108 = - V_123 ;
V_107 = F_34 ( & V_74 -> V_1 , V_2 ) ;
if ( V_107 ) {
( void ) F_34 ( & V_74 -> V_1 , V_107 ) ;
goto V_113;
}
if ( F_58 ( & V_72 ) == 1 )
F_59 () ;
return 0 ;
V_113:
F_25 ( V_2 ) ;
return V_108 ;
}
int F_60 ( struct V_73 * V_74 , char * V_104 , T_10 V_26 ,
struct V_97 * V_98 ,
char T_7 * V_124 )
{
struct V_105 V_106 ;
int V_108 ;
V_108 = F_40 ( & V_106 , V_124 , sizeof( V_106 ) ) ;
if ( V_108 )
return - V_85 ;
V_108 = F_48 ( V_74 , V_104 , V_26 , V_98 , & V_106 ) ;
if ( V_108 )
return V_108 ;
if ( F_61 ( V_124 , & V_106 , sizeof( V_106 ) ) ) {
F_33 ( V_74 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_62 ( struct V_73 * V_74 , char * V_104 ,
T_10 V_26 , struct V_97 * V_98 ,
char T_7 * V_124 )
{
struct V_105 V_106 ;
struct V_125 V_126 ;
int V_108 ;
if ( F_40 ( & V_126 , V_124 , sizeof( V_126 ) ) )
return - V_85 ;
V_106 = (struct V_105 ) {
. V_46 = V_126 . V_46 ,
. V_110 = V_126 . V_110 ,
. V_111 = V_126 . V_111 ,
. V_54 = V_126 . V_54 ,
. V_55 = V_126 . V_55 ,
. V_3 = V_126 . V_3 ,
} ;
memcpy ( & V_106 . V_104 , & V_126 . V_104 , 32 ) ;
V_108 = F_48 ( V_74 , V_104 , V_26 , V_98 , & V_106 ) ;
if ( V_108 )
return V_108 ;
if ( F_61 ( V_124 , & V_106 . V_104 , 32 ) ) {
F_33 ( V_74 ) ;
return - V_85 ;
}
return 0 ;
}
int F_63 ( struct V_73 * V_74 , int V_127 )
{
int V_108 ;
struct V_1 * V_2 = V_74 -> V_1 ;
if ( V_2 == NULL )
return - V_75 ;
V_108 = - V_75 ;
if ( V_127 ) {
if ( V_2 -> V_44 == V_122 ||
V_2 -> V_44 == V_128 ) {
V_31 ++ ;
F_64 () ;
V_2 -> V_44 = V_45 ;
F_11 ( V_2 ) ;
V_108 = 0 ;
}
} else {
if ( V_2 -> V_44 == V_45 ) {
V_2 -> V_44 = V_128 ;
F_65 ( V_2 -> V_21 ) ;
V_108 = 0 ;
}
}
return V_108 ;
}
int F_66 ( struct V_97 * V_98 , unsigned V_129 , char T_7 * V_124 )
{
struct V_73 * V_74 ;
int V_108 , V_127 = 0 ;
char V_130 [ V_131 ] ;
V_74 = F_67 ( V_98 ) ;
if ( ! V_74 )
return - V_132 ;
F_53 ( & V_98 -> V_133 ) ;
switch ( V_129 ) {
case V_134 :
F_68 ( V_98 , V_130 ) ;
V_108 = F_60 ( V_74 , V_130 , V_98 -> V_135 , V_98 , V_124 ) ;
break;
#if F_69 ( V_136 ) && F_69 ( V_137 )
case V_138 :
F_68 ( V_98 , V_130 ) ;
V_108 = F_62 ( V_74 , V_130 , V_98 -> V_135 , V_98 , V_124 ) ;
break;
#endif
case V_139 :
V_127 = 1 ;
case V_140 :
V_108 = F_63 ( V_74 , V_127 ) ;
break;
case V_141 :
V_108 = F_33 ( V_74 ) ;
break;
default:
V_108 = - V_142 ;
break;
}
F_55 ( & V_98 -> V_133 ) ;
return V_108 ;
}
void F_70 ( struct V_73 * V_74 )
{
if ( V_74 -> V_1 ) {
F_63 ( V_74 , 0 ) ;
F_33 ( V_74 ) ;
}
}
static void F_71 ( struct V_73 * V_74 , struct V_143 * V_144 ,
T_3 V_51 )
{
struct V_1 * V_2 = V_74 -> V_1 ;
if ( F_72 ( ! V_2 ) )
return;
if ( V_144 -> V_145 == V_146 ) {
V_51 |= F_73 ( V_147 ) ;
F_20 ( V_2 , 0 , F_74 ( V_144 ) , V_144 -> V_148 ,
V_51 , V_144 -> V_149 , V_144 -> V_150 , V_144 -> V_129 ) ;
} else {
V_51 |= F_73 ( V_151 ) ;
F_20 ( V_2 , F_75 ( V_144 ) , F_74 ( V_144 ) ,
V_144 -> V_148 , V_51 , V_144 -> V_149 , 0 , NULL ) ;
}
}
static void F_76 ( void * V_152 ,
struct V_73 * V_74 , struct V_143 * V_144 )
{
F_71 ( V_74 , V_144 , V_153 ) ;
}
static void F_77 ( void * V_152 ,
struct V_73 * V_74 , struct V_143 * V_144 )
{
F_71 ( V_74 , V_144 , V_154 ) ;
}
static void F_78 ( void * V_152 ,
struct V_73 * V_74 , struct V_143 * V_144 )
{
F_71 ( V_74 , V_144 , V_155 ) ;
}
static void F_79 ( void * V_152 ,
struct V_73 * V_74 ,
struct V_143 * V_144 )
{
F_71 ( V_74 , V_144 , V_156 ) ;
}
static void F_80 ( void * V_152 ,
struct V_73 * V_74 ,
struct V_143 * V_144 )
{
F_71 ( V_74 , V_144 , V_157 ) ;
}
static void F_81 ( struct V_73 * V_74 , struct V_158 * V_158 ,
T_3 V_51 , int error )
{
struct V_1 * V_2 = V_74 -> V_1 ;
if ( F_72 ( ! V_2 ) )
return;
if ( ! error && ! F_82 ( V_158 , V_159 ) )
error = V_117 ;
F_20 ( V_2 , V_158 -> V_160 , V_158 -> V_161 , V_158 -> V_162 , V_51 ,
error , 0 , NULL ) ;
}
static void F_83 ( void * V_152 ,
struct V_73 * V_74 , struct V_158 * V_158 )
{
F_81 ( V_74 , V_158 , V_163 , 0 ) ;
}
static void F_84 ( void * V_152 ,
struct V_73 * V_74 , struct V_158 * V_158 ,
int error )
{
F_81 ( V_74 , V_158 , V_157 , error ) ;
}
static void F_85 ( void * V_152 ,
struct V_73 * V_74 ,
struct V_143 * V_144 ,
struct V_158 * V_158 )
{
F_81 ( V_74 , V_158 , V_164 , 0 ) ;
}
static void F_86 ( void * V_152 ,
struct V_73 * V_74 ,
struct V_143 * V_144 ,
struct V_158 * V_158 )
{
F_81 ( V_74 , V_158 , V_165 , 0 ) ;
}
static void F_87 ( void * V_152 ,
struct V_73 * V_74 , struct V_158 * V_158 )
{
F_81 ( V_74 , V_158 , V_166 , 0 ) ;
}
static void F_88 ( void * V_152 ,
struct V_73 * V_74 ,
struct V_158 * V_158 , int V_57 )
{
if ( V_158 )
F_81 ( V_74 , V_158 , V_167 , 0 ) ;
else {
struct V_1 * V_2 = V_74 -> V_1 ;
if ( V_2 )
F_20 ( V_2 , 0 , 0 , V_57 , V_167 , 0 , 0 , NULL ) ;
}
}
static void F_89 ( void * V_152 ,
struct V_73 * V_74 ,
struct V_158 * V_158 , int V_57 )
{
if ( V_158 )
F_81 ( V_74 , V_158 , V_168 , 0 ) ;
else {
struct V_1 * V_2 = V_74 -> V_1 ;
if ( V_2 )
F_20 ( V_2 , 0 , 0 , V_57 , V_168 ,
0 , 0 , NULL ) ;
}
}
static void F_90 ( void * V_152 , struct V_73 * V_74 )
{
struct V_1 * V_2 = V_74 -> V_1 ;
if ( V_2 )
F_20 ( V_2 , 0 , 0 , 0 , V_169 , 0 , 0 , NULL ) ;
}
static void F_91 ( void * V_152 , struct V_73 * V_74 ,
unsigned int V_170 , bool V_171 )
{
struct V_1 * V_2 = V_74 -> V_1 ;
if ( V_2 ) {
T_11 V_172 = F_92 ( V_170 ) ;
T_3 V_51 ;
if ( V_171 )
V_51 = V_173 ;
else
V_51 = V_174 ;
F_20 ( V_2 , 0 , 0 , 0 , V_51 , 0 , sizeof( V_172 ) , & V_172 ) ;
}
}
static void F_93 ( void * V_152 ,
struct V_73 * V_74 , struct V_158 * V_158 ,
unsigned int V_175 )
{
struct V_1 * V_2 = V_74 -> V_1 ;
if ( V_2 ) {
T_11 V_172 = F_92 ( V_175 ) ;
F_20 ( V_2 , V_158 -> V_160 , V_158 -> V_161 , V_158 -> V_162 ,
V_176 , ! F_82 ( V_158 , V_159 ) ,
sizeof( V_172 ) , & V_172 ) ;
}
}
static void F_94 ( void * V_152 ,
struct V_73 * V_74 , struct V_158 * V_158 ,
T_10 V_26 , T_5 V_177 )
{
struct V_1 * V_2 = V_74 -> V_1 ;
struct V_178 V_179 ;
if ( F_72 ( ! V_2 ) )
return;
V_179 . V_180 = F_95 ( V_26 ) ;
V_179 . V_181 = F_95 ( V_158 -> V_182 -> V_135 ) ;
V_179 . V_183 = F_92 ( V_177 ) ;
F_20 ( V_2 , V_158 -> V_160 , V_158 -> V_161 , V_158 -> V_162 ,
V_184 , ! F_82 ( V_158 , V_159 ) ,
sizeof( V_179 ) , & V_179 ) ;
}
static void F_96 ( void * V_152 ,
struct V_73 * V_74 ,
struct V_143 * V_144 , T_10 V_26 ,
T_5 V_177 )
{
struct V_1 * V_2 = V_74 -> V_1 ;
struct V_178 V_179 ;
if ( F_72 ( ! V_2 ) )
return;
V_179 . V_180 = F_95 ( V_26 ) ;
V_179 . V_181 = F_95 ( F_97 ( V_144 -> V_185 ) ) ;
V_179 . V_183 = F_92 ( V_177 ) ;
F_20 ( V_2 , F_75 ( V_144 ) , F_74 ( V_144 ) ,
F_98 ( V_144 ) , V_184 , ! ! V_144 -> V_149 ,
sizeof( V_179 ) , & V_179 ) ;
}
void F_99 ( struct V_73 * V_74 ,
struct V_143 * V_144 ,
void * V_5 , T_2 V_6 )
{
struct V_1 * V_2 = V_74 -> V_1 ;
if ( F_72 ( ! V_2 ) )
return;
if ( V_144 -> V_145 == V_146 )
F_20 ( V_2 , 0 , F_74 ( V_144 ) , 0 ,
V_186 , V_144 -> V_149 , V_6 , V_5 ) ;
else
F_20 ( V_2 , F_75 ( V_144 ) , F_74 ( V_144 ) , 0 ,
V_186 , V_144 -> V_149 , V_6 , V_5 ) ;
}
static void F_59 ( void )
{
int V_108 ;
V_108 = F_100 ( F_76 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_102 ( F_77 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_103 ( F_78 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_104 ( F_79 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_105 ( F_80 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_106 ( F_83 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_107 ( F_84 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_108 ( F_85 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_109 ( F_86 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_110 ( F_87 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_111 ( F_88 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_112 ( F_89 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_113 ( F_90 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_114 ( F_91 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_115 ( F_93 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_116 ( F_94 , NULL ) ;
F_101 ( V_108 ) ;
V_108 = F_117 ( F_96 , NULL ) ;
F_101 ( V_108 ) ;
}
static void F_32 ( void )
{
F_118 ( F_96 , NULL ) ;
F_119 ( F_94 , NULL ) ;
F_120 ( F_93 , NULL ) ;
F_121 ( F_91 , NULL ) ;
F_122 ( F_90 , NULL ) ;
F_123 ( F_89 , NULL ) ;
F_124 ( F_88 , NULL ) ;
F_125 ( F_87 , NULL ) ;
F_126 ( F_86 , NULL ) ;
F_127 ( F_85 , NULL ) ;
F_128 ( F_84 , NULL ) ;
F_129 ( F_83 , NULL ) ;
F_130 ( F_80 , NULL ) ;
F_131 ( F_79 , NULL ) ;
F_132 ( F_78 , NULL ) ;
F_133 ( F_77 , NULL ) ;
F_134 ( F_76 , NULL ) ;
F_135 () ;
}
static void F_136 ( char * V_187 , const struct V_7 * V_8 )
{
int V_109 = 0 ;
int V_188 = V_8 -> V_4 >> V_53 ;
if ( V_8 -> V_4 == V_50 ) {
V_187 [ V_109 ++ ] = 'N' ;
goto V_189;
}
if ( V_188 & V_190 )
V_187 [ V_109 ++ ] = 'F' ;
if ( V_188 & V_191 )
V_187 [ V_109 ++ ] = 'D' ;
else if ( V_188 & V_192 )
V_187 [ V_109 ++ ] = 'W' ;
else if ( V_8 -> V_56 )
V_187 [ V_109 ++ ] = 'R' ;
else
V_187 [ V_109 ++ ] = 'N' ;
if ( V_188 & V_193 )
V_187 [ V_109 ++ ] = 'F' ;
if ( V_188 & V_194 )
V_187 [ V_109 ++ ] = 'A' ;
if ( V_188 & V_195 )
V_187 [ V_109 ++ ] = 'S' ;
if ( V_188 & V_196 )
V_187 [ V_109 ++ ] = 'M' ;
V_189:
V_187 [ V_109 ] = '\0' ;
}
static inline
const struct V_7 * F_137 ( const struct V_197 * V_198 )
{
return ( const struct V_7 * ) V_198 ;
}
static inline const void * F_138 ( const struct V_197 * V_198 )
{
return F_137 ( V_198 ) + 1 ;
}
static inline T_3 F_139 ( const struct V_197 * V_198 )
{
return F_137 ( V_198 ) -> V_4 ;
}
static inline T_3 F_140 ( const struct V_197 * V_198 )
{
return F_137 ( V_198 ) -> V_56 ;
}
static inline T_3 F_141 ( const struct V_197 * V_198 )
{
return F_137 ( V_198 ) -> V_56 >> 9 ;
}
static inline unsigned long long F_142 ( const struct V_197 * V_198 )
{
return F_137 ( V_198 ) -> V_52 ;
}
static inline T_12 F_143 ( const struct V_197 * V_198 )
{
return F_137 ( V_198 ) -> error ;
}
static T_13 F_144 ( const struct V_197 * V_198 )
{
const T_13 * V_199 = F_138 ( V_198 ) ;
return F_145 ( * V_199 ) ;
}
static void F_146 ( const struct V_197 * V_198 ,
struct V_178 * V_179 )
{
const struct V_178 * V_200 = F_138 ( V_198 ) ;
T_13 V_183 = V_200 -> V_183 ;
V_179 -> V_180 = F_147 ( V_200 -> V_180 ) ;
V_179 -> V_181 = F_147 ( V_200 -> V_181 ) ;
V_179 -> V_183 = F_145 ( V_183 ) ;
}
static int F_148 ( struct V_201 * V_202 , const char * V_203 )
{
char V_187 [ V_204 ] ;
unsigned long long V_205 = V_202 -> V_205 ;
unsigned long V_206 = F_149 ( V_205 , V_207 ) ;
unsigned V_208 = ( unsigned long ) V_205 ;
const struct V_7 * V_8 = F_137 ( V_202 -> V_198 ) ;
F_136 ( V_187 , V_8 ) ;
return F_150 ( & V_202 -> V_209 ,
L_7 ,
F_151 ( V_8 -> V_25 ) , F_152 ( V_8 -> V_25 ) , V_202 -> V_14 ,
V_208 , V_206 , V_202 -> V_198 -> V_3 , V_203 , V_187 ) ;
}
static int F_153 ( struct V_201 * V_202 , const char * V_203 )
{
char V_187 [ V_204 ] ;
const struct V_7 * V_8 = F_137 ( V_202 -> V_198 ) ;
F_136 ( V_187 , V_8 ) ;
return F_150 ( & V_202 -> V_209 , L_8 ,
F_151 ( V_8 -> V_25 ) , F_152 ( V_8 -> V_25 ) , V_203 , V_187 ) ;
}
static int F_154 ( struct V_210 * V_211 , const struct V_197 * V_198 )
{
const unsigned char * V_212 ;
int V_27 ;
int V_109 , V_213 , V_108 ;
V_212 = F_138 ( V_198 ) ;
V_27 = F_137 ( V_198 ) -> V_27 ;
if ( ! V_27 )
return 1 ;
for ( V_213 = V_27 - 1 ; V_213 >= 0 ; V_213 -- )
if ( V_212 [ V_213 ] )
break;
V_213 ++ ;
if ( ! F_155 ( V_211 , '(' ) )
return 0 ;
for ( V_109 = 0 ; V_109 < V_27 ; V_109 ++ ) {
V_108 = F_150 ( V_211 , L_9 ,
V_109 == 0 ? L_10 : L_11 , V_212 [ V_109 ] ) ;
if ( ! V_108 )
return V_108 ;
if ( V_109 == V_213 && V_213 != V_27 - 1 )
return F_156 ( V_211 , L_12 ) ;
}
return F_156 ( V_211 , L_13 ) ;
}
static int F_157 ( struct V_210 * V_211 , const struct V_197 * V_198 )
{
char V_129 [ V_214 ] ;
F_158 ( V_198 -> V_3 , V_129 ) ;
if ( F_139 ( V_198 ) & F_73 ( V_147 ) ) {
int V_108 ;
V_108 = F_150 ( V_211 , L_14 , F_140 ( V_198 ) ) ;
if ( ! V_108 )
return 0 ;
V_108 = F_154 ( V_211 , V_198 ) ;
if ( ! V_108 )
return 0 ;
return F_150 ( V_211 , L_15 , V_129 ) ;
} else {
if ( F_141 ( V_198 ) )
return F_150 ( V_211 , L_16 ,
F_142 ( V_198 ) , F_141 ( V_198 ) , V_129 ) ;
return F_150 ( V_211 , L_15 , V_129 ) ;
}
}
static int F_159 ( struct V_210 * V_211 ,
const struct V_197 * V_198 )
{
if ( F_139 ( V_198 ) & F_73 ( V_147 ) ) {
int V_108 ;
V_108 = F_154 ( V_211 , V_198 ) ;
if ( V_108 )
return F_150 ( V_211 , L_17 , F_143 ( V_198 ) ) ;
return 0 ;
} else {
if ( F_141 ( V_198 ) )
return F_150 ( V_211 , L_18 ,
F_142 ( V_198 ) ,
F_141 ( V_198 ) , F_143 ( V_198 ) ) ;
return F_150 ( V_211 , L_19 ,
F_142 ( V_198 ) , F_143 ( V_198 ) ) ;
}
}
static int F_160 ( struct V_210 * V_211 , const struct V_197 * V_198 )
{
struct V_178 V_179 = { . V_180 = 0 , } ;
F_146 ( V_198 , & V_179 ) ;
return F_150 ( V_211 , L_20 ,
F_142 ( V_198 ) , F_141 ( V_198 ) ,
F_151 ( V_179 . V_180 ) , F_152 ( V_179 . V_180 ) ,
( unsigned long long ) V_179 . V_183 ) ;
}
static int F_161 ( struct V_210 * V_211 , const struct V_197 * V_198 )
{
char V_129 [ V_214 ] ;
F_158 ( V_198 -> V_3 , V_129 ) ;
return F_150 ( V_211 , L_15 , V_129 ) ;
}
static int F_162 ( struct V_210 * V_211 , const struct V_197 * V_198 )
{
char V_129 [ V_214 ] ;
F_158 ( V_198 -> V_3 , V_129 ) ;
return F_150 ( V_211 , L_21 , V_129 , F_144 ( V_198 ) ) ;
}
static int F_163 ( struct V_210 * V_211 , const struct V_197 * V_198 )
{
char V_129 [ V_214 ] ;
F_158 ( V_198 -> V_3 , V_129 ) ;
return F_150 ( V_211 , L_22 , F_142 ( V_198 ) ,
F_144 ( V_198 ) , V_129 ) ;
}
static int F_164 ( struct V_210 * V_211 , const struct V_197 * V_198 )
{
int V_108 ;
const struct V_7 * V_8 = F_137 ( V_198 ) ;
V_108 = F_165 ( V_211 , V_8 + 1 , V_8 -> V_27 ) ;
if ( V_108 )
return F_155 ( V_211 , '\n' ) ;
return V_108 ;
}
static void F_166 ( struct V_215 * V_216 )
{
if ( ! ( V_217 . V_199 & V_218 ) )
return;
F_167 ( V_216 , L_23
L_24 ) ;
}
static void F_168 ( struct V_219 * V_220 )
{
V_16 = true ;
}
static int F_169 ( struct V_219 * V_220 )
{
V_17 = V_220 ;
F_168 ( V_220 ) ;
return 0 ;
}
static void F_170 ( struct V_219 * V_220 )
{
V_16 = false ;
}
static void F_171 ( struct V_219 * V_220 )
{
F_170 ( V_220 ) ;
}
static enum V_221 F_172 ( struct V_201 * V_202 ,
bool V_222 )
{
struct V_210 * V_211 = & V_202 -> V_209 ;
const struct V_7 * V_8 ;
V_121 V_51 ;
int V_108 ;
bool V_223 ;
T_14 * V_224 ;
V_8 = F_137 ( V_202 -> V_198 ) ;
V_51 = V_8 -> V_4 & ( ( 1 << V_53 ) - 1 ) ;
V_223 = ! ! ( V_225 & V_226 ) ;
V_224 = V_222 ? & F_148 : & F_153 ;
if ( V_8 -> V_4 == V_50 ) {
V_108 = V_224 ( V_202 , V_223 ? L_25 : L_26 ) ;
if ( V_108 )
V_108 = F_164 ( V_211 , V_202 -> V_198 ) ;
goto V_189;
}
if ( F_16 ( V_51 == 0 || V_51 >= F_173 ( V_227 ) ) )
V_108 = F_150 ( V_211 , L_27 , V_51 ) ;
else {
V_108 = V_224 ( V_202 , V_227 [ V_51 ] . V_203 [ V_223 ] ) ;
if ( V_108 )
V_108 = V_227 [ V_51 ] . F_174 ( V_211 , V_202 -> V_198 ) ;
}
V_189:
return V_108 ? V_228 : V_229 ;
}
static enum V_221 F_175 ( struct V_201 * V_202 ,
int V_36 , struct V_230 * V_10 )
{
return F_172 ( V_202 , false ) ;
}
static int F_176 ( struct V_201 * V_202 )
{
struct V_210 * V_211 = & V_202 -> V_209 ;
struct V_7 * V_8 = (struct V_7 * ) V_202 -> V_198 ;
const int V_231 = F_177 ( struct V_7 , V_52 ) ;
struct V_7 V_232 = {
. V_22 = V_23 | V_24 ,
. time = V_202 -> V_205 ,
} ;
if ( ! F_165 ( V_211 , & V_232 , V_231 ) )
return 0 ;
return F_165 ( V_211 , & V_8 -> V_52 ,
sizeof( V_232 ) - V_231 + V_8 -> V_27 ) ;
}
static enum V_221
F_178 ( struct V_201 * V_202 , int V_36 ,
struct V_230 * V_10 )
{
return F_176 ( V_202 ) ?
V_228 : V_229 ;
}
static enum V_221 F_179 ( struct V_201 * V_202 )
{
if ( ! ( V_217 . V_199 & V_218 ) )
return V_233 ;
return F_172 ( V_202 , true ) ;
}
static int F_180 ( T_3 V_234 , T_3 V_235 , int V_236 )
{
if ( V_235 == V_218 ) {
if ( V_236 )
V_225 &= ~ V_237 ;
else
V_225 |= V_237 ;
}
return 0 ;
}
static int T_15 F_181 ( void )
{
if ( ! F_182 ( & V_238 ) ) {
F_183 ( L_28 ) ;
return 1 ;
}
if ( F_184 ( & V_15 ) != 0 ) {
F_183 ( L_29 ) ;
F_185 ( & V_238 ) ;
return 1 ;
}
return 0 ;
}
static int F_186 ( struct V_73 * V_74 )
{
struct V_1 * V_2 ;
V_2 = F_34 ( & V_74 -> V_1 , NULL ) ;
if ( V_2 == NULL )
return - V_75 ;
if ( F_31 ( & V_72 ) )
F_32 () ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_187 ( struct V_73 * V_74 ,
struct V_97 * V_98 )
{
struct V_1 * V_107 , * V_2 = NULL ;
int V_108 = - V_84 ;
V_2 = F_49 ( sizeof( * V_2 ) , V_83 ) ;
if ( ! V_2 )
return - V_84 ;
V_2 -> V_48 = F_51 ( V_49 , F_52 ( char ) ) ;
if ( ! V_2 -> V_48 )
goto V_239;
V_2 -> V_26 = V_98 -> V_135 ;
V_2 -> V_46 = ( V_121 ) - 1 ;
F_47 ( V_2 , V_98 ) ;
V_107 = F_34 ( & V_74 -> V_1 , V_2 ) ;
if ( V_107 != NULL ) {
( void ) F_34 ( & V_74 -> V_1 , V_107 ) ;
V_108 = - V_123 ;
goto V_239;
}
if ( F_58 ( & V_72 ) == 1 )
F_59 () ;
return 0 ;
V_239:
F_25 ( V_2 ) ;
return V_108 ;
}
static int F_188 ( const char * V_240 )
{
int V_109 ;
int V_241 = 0 ;
char * V_43 , * V_211 , * V_242 ;
V_43 = F_189 ( V_240 , V_83 ) ;
if ( V_43 == NULL )
return - V_84 ;
V_211 = F_190 ( V_43 ) ;
while ( 1 ) {
V_242 = F_191 ( & V_211 , L_30 ) ;
if ( V_242 == NULL )
break;
if ( * V_242 == '\0' )
continue;
for ( V_109 = 0 ; V_109 < F_173 ( V_243 ) ; V_109 ++ ) {
if ( strcasecmp ( V_242 , V_243 [ V_109 ] . V_240 ) == 0 ) {
V_241 |= V_243 [ V_109 ] . V_241 ;
break;
}
}
if ( V_109 == F_173 ( V_243 ) ) {
V_241 = - V_75 ;
break;
}
}
F_29 ( V_43 ) ;
return V_241 ;
}
static T_6 F_192 ( char * V_43 , int V_241 )
{
int V_109 ;
char * V_244 = V_43 ;
for ( V_109 = 0 ; V_109 < F_173 ( V_243 ) ; V_109 ++ ) {
if ( V_241 & V_243 [ V_109 ] . V_241 ) {
V_244 += sprintf ( V_244 , L_31 ,
( V_244 == V_43 ) ? L_10 : L_30 , V_243 [ V_109 ] . V_240 ) ;
}
}
* V_244 ++ = '\n' ;
return V_244 - V_43 ;
}
static struct V_73 * F_193 ( struct V_97 * V_98 )
{
if ( V_98 -> V_245 == NULL )
return NULL ;
return F_67 ( V_98 ) ;
}
static T_6 F_194 ( struct V_25 * V_26 ,
struct V_246 * V_247 ,
char * V_43 )
{
struct V_99 * V_244 = F_195 ( V_26 ) ;
struct V_73 * V_74 ;
struct V_97 * V_98 ;
T_6 V_108 = - V_132 ;
V_98 = F_196 ( F_197 ( V_244 ) ) ;
if ( V_98 == NULL )
goto V_189;
V_74 = F_193 ( V_98 ) ;
if ( V_74 == NULL )
goto V_248;
F_53 ( & V_98 -> V_133 ) ;
if ( V_247 == & V_249 ) {
V_108 = sprintf ( V_43 , L_1 , ! ! V_74 -> V_1 ) ;
goto V_250;
}
if ( V_74 -> V_1 == NULL )
V_108 = sprintf ( V_43 , L_32 ) ;
else if ( V_247 == & V_251 )
V_108 = F_192 ( V_43 , V_74 -> V_1 -> V_46 ) ;
else if ( V_247 == & V_252 )
V_108 = sprintf ( V_43 , L_1 , V_74 -> V_1 -> V_3 ) ;
else if ( V_247 == & V_253 )
V_108 = sprintf ( V_43 , L_33 , V_74 -> V_1 -> V_54 ) ;
else if ( V_247 == & V_254 )
V_108 = sprintf ( V_43 , L_33 , V_74 -> V_1 -> V_55 ) ;
V_250:
F_55 ( & V_98 -> V_133 ) ;
V_248:
F_198 ( V_98 ) ;
V_189:
return V_108 ;
}
static T_6 F_199 ( struct V_25 * V_26 ,
struct V_246 * V_247 ,
const char * V_43 , T_2 V_78 )
{
struct V_97 * V_98 ;
struct V_73 * V_74 ;
struct V_99 * V_244 ;
T_16 V_255 ;
T_6 V_108 = - V_75 ;
if ( V_78 == 0 )
goto V_189;
if ( V_247 == & V_251 ) {
if ( sscanf ( V_43 , L_34 , & V_255 ) != 1 ) {
V_108 = F_188 ( V_43 ) ;
if ( V_108 < 0 )
goto V_189;
V_255 = V_108 ;
}
} else if ( sscanf ( V_43 , L_35 , & V_255 ) != 1 )
goto V_189;
V_108 = - V_132 ;
V_244 = F_195 ( V_26 ) ;
V_98 = F_196 ( F_197 ( V_244 ) ) ;
if ( V_98 == NULL )
goto V_189;
V_74 = F_193 ( V_98 ) ;
if ( V_74 == NULL )
goto V_248;
F_53 ( & V_98 -> V_133 ) ;
if ( V_247 == & V_249 ) {
if ( V_255 )
V_108 = F_187 ( V_74 , V_98 ) ;
else
V_108 = F_186 ( V_74 ) ;
goto V_250;
}
V_108 = 0 ;
if ( V_74 -> V_1 == NULL )
V_108 = F_187 ( V_74 , V_98 ) ;
if ( V_108 == 0 ) {
if ( V_247 == & V_251 )
V_74 -> V_1 -> V_46 = V_255 ;
else if ( V_247 == & V_252 )
V_74 -> V_1 -> V_3 = V_255 ;
else if ( V_247 == & V_253 )
V_74 -> V_1 -> V_54 = V_255 ;
else if ( V_247 == & V_254 )
V_74 -> V_1 -> V_55 = V_255 ;
}
V_250:
F_55 ( & V_98 -> V_133 ) ;
V_248:
F_198 ( V_98 ) ;
V_189:
return V_108 ? V_108 : V_78 ;
}
int F_200 ( struct V_25 * V_26 )
{
return F_201 ( & V_26 -> V_256 , & V_257 ) ;
}
void F_202 ( struct V_25 * V_26 )
{
F_203 ( & V_26 -> V_256 , & V_257 ) ;
}
void F_204 ( char * V_43 , struct V_143 * V_144 )
{
int V_109 , V_213 ;
int V_6 = V_144 -> V_150 ;
unsigned char * V_129 = V_144 -> V_129 ;
if ( V_144 -> V_145 != V_146 ) {
V_43 [ 0 ] = '\0' ;
return;
}
for ( V_213 = V_6 - 1 ; V_213 >= 0 ; V_213 -- )
if ( V_129 [ V_213 ] )
break;
V_213 ++ ;
for ( V_109 = 0 ; V_109 < V_6 ; V_109 ++ ) {
V_43 += sprintf ( V_43 , L_9 , V_109 == 0 ? L_10 : L_11 , V_129 [ V_109 ] ) ;
if ( V_109 == V_213 && V_213 != V_6 - 1 ) {
sprintf ( V_43 , L_36 ) ;
break;
}
}
}
void F_205 ( char * V_187 , T_3 V_57 , int V_56 )
{
int V_109 = 0 ;
if ( V_57 & V_258 )
V_187 [ V_109 ++ ] = 'F' ;
if ( V_57 & V_62 )
V_187 [ V_109 ++ ] = 'W' ;
else if ( V_57 & V_259 )
V_187 [ V_109 ++ ] = 'D' ;
else if ( V_56 )
V_187 [ V_109 ++ ] = 'R' ;
else
V_187 [ V_109 ++ ] = 'N' ;
if ( V_57 & V_260 )
V_187 [ V_109 ++ ] = 'F' ;
if ( V_57 & V_261 )
V_187 [ V_109 ++ ] = 'A' ;
if ( V_57 & V_262 )
V_187 [ V_109 ++ ] = 'S' ;
if ( V_57 & V_263 )
V_187 [ V_109 ++ ] = 'M' ;
if ( V_57 & V_264 )
V_187 [ V_109 ++ ] = 'E' ;
V_187 [ V_109 ] = '\0' ;
}
