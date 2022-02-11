static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
if ( F_2 ( V_2 -> V_5 -> V_6 , V_3 , V_4 ) < 0 ) {
F_3 ( L_1 ) ;
return - 1 ;
}
V_2 -> V_7 += V_4 ;
return 0 ;
}
static int F_4 ( struct V_8 * V_9 ,
union V_10 * V_11 ,
struct V_12 * T_2 V_13 ,
struct V_14 * V_14 V_13 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
return F_1 ( V_2 , V_11 , V_11 -> V_15 . V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
unsigned int V_18 = F_7 ( V_17 ) ;
unsigned int V_19 = V_17 -> V_20 ;
unsigned char * V_21 = V_17 -> V_22 + V_23 ;
unsigned long V_4 ;
void * V_24 ;
int V_25 = 0 ;
if ( V_19 == V_18 )
return 0 ;
V_2 -> V_26 ++ ;
V_4 = V_18 - V_19 ;
if ( ( V_19 & V_17 -> V_27 ) + V_4 != ( V_18 & V_17 -> V_27 ) ) {
V_24 = & V_21 [ V_19 & V_17 -> V_27 ] ;
V_4 = V_17 -> V_27 + 1 - ( V_19 & V_17 -> V_27 ) ;
V_19 += V_4 ;
if ( F_1 ( V_2 , V_24 , V_4 ) < 0 ) {
V_25 = - 1 ;
goto V_28;
}
}
V_24 = & V_21 [ V_19 & V_17 -> V_27 ] ;
V_4 = V_18 - V_19 ;
V_19 += V_4 ;
if ( F_1 ( V_2 , V_24 , V_4 ) < 0 ) {
V_25 = - 1 ;
goto V_28;
}
V_17 -> V_20 = V_19 ;
F_8 ( V_17 , V_19 ) ;
V_28:
return V_25 ;
}
static void F_9 ( int V_29 )
{
if ( V_29 == V_30 )
V_31 = 1 ;
else
V_32 = V_29 ;
V_33 = 1 ;
}
static void F_10 ( void )
{
if ( V_32 == - 1 )
return;
signal ( V_32 , V_34 ) ;
raise ( V_32 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
char V_35 [ 512 ] ;
struct V_36 * V_37 ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_41 * V_42 = & V_2 -> V_42 ;
int V_25 = 0 ;
F_12 ( V_39 , V_42 ) ;
F_13 (evlist, pos) {
V_43:
if ( F_14 ( V_37 , V_39 -> V_44 , V_39 -> V_45 ) < 0 ) {
if ( F_15 ( V_37 , V_46 , V_35 , sizeof( V_35 ) ) ) {
if ( V_47 )
F_16 ( L_2 , V_35 ) ;
goto V_43;
}
V_25 = - V_46 ;
F_17 ( V_37 , & V_42 -> V_48 ,
V_46 , V_35 , sizeof( V_35 ) ) ;
F_18 ( L_2 , V_35 ) ;
goto V_28;
}
}
if ( F_19 ( V_39 ) ) {
error ( L_3 , V_46 ,
strerror ( V_46 ) ) ;
V_25 = - 1 ;
goto V_28;
}
if ( F_20 ( V_39 , V_42 -> V_49 , false ) < 0 ) {
if ( V_46 == V_50 ) {
F_3 ( L_4
L_5
L_6
L_7
L_8 , V_42 -> V_49 ) ;
V_25 = - V_46 ;
} else {
F_3 ( L_9 , V_46 , strerror ( V_46 ) ) ;
V_25 = - V_46 ;
}
goto V_28;
}
V_5 -> V_39 = V_39 ;
F_21 ( V_5 ) ;
V_28:
return V_25 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_51 * V_6 = & V_2 -> V_6 ;
struct V_40 * V_5 = V_2 -> V_5 ;
T_3 V_52 = V_5 -> V_15 . V_53 ;
T_3 V_4 = F_23 ( V_6 -> V_54 , 0 , V_55 ) ;
if ( V_4 == 0 )
return 0 ;
return F_24 ( V_5 , V_52 ,
V_4 - V_52 ,
V_4 , & V_56 ) ;
}
static void F_25 ( struct V_14 * V_14 , void * V_21 )
{
int V_57 ;
struct V_8 * V_9 = V_21 ;
V_57 = F_26 ( V_9 , F_4 ,
V_14 ) ;
if ( V_57 < 0 )
F_3 ( L_10
L_11 , V_14 -> V_58 ) ;
V_57 = F_27 ( V_9 , F_4 ,
V_14 ) ;
if ( V_57 < 0 )
F_3 ( L_10
L_11 , V_14 -> V_58 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_3 V_7 = V_2 -> V_7 ;
int V_59 ;
int V_25 = 0 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_39 -> V_60 ; V_59 ++ ) {
if ( V_2 -> V_39 -> V_61 [ V_59 ] . V_22 ) {
if ( F_6 ( V_2 , & V_2 -> V_39 -> V_61 [ V_59 ] ) != 0 ) {
V_25 = - 1 ;
goto V_28;
}
}
}
if ( V_7 != V_2 -> V_7 )
V_25 = F_1 ( V_2 , & V_62 , sizeof( V_62 ) ) ;
V_28:
return V_25 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_40 * V_5 = V_2 -> V_5 ;
int V_63 ;
for ( V_63 = V_64 ; V_63 < V_65 ; V_63 ++ )
F_30 ( & V_5 -> V_15 , V_63 ) ;
if ( V_2 -> V_66 )
F_31 ( & V_5 -> V_15 , V_67 ) ;
if ( ! F_32 ( & V_2 -> V_39 -> V_68 ) )
F_31 ( & V_5 -> V_15 , V_69 ) ;
if ( ! V_2 -> V_42 . V_70 )
F_31 ( & V_5 -> V_15 , V_71 ) ;
}
static void F_33 ( int T_4 V_13 ,
T_5 * V_72 ,
void * T_6 V_13 )
{
V_73 = V_72 -> V_74 . V_75 ;
V_33 = 1 ;
V_31 = 1 ;
}
static int F_34 ( struct V_1 * V_2 , int V_76 , const char * * V_77 )
{
int V_57 ;
int V_78 = 0 ;
unsigned long V_79 = 0 ;
const bool V_80 = V_76 > 0 ;
struct V_14 * V_14 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_41 * V_42 = & V_2 -> V_42 ;
struct V_51 * V_6 = & V_2 -> V_6 ;
struct V_40 * V_5 ;
bool V_81 = false ;
V_2 -> V_82 = V_77 [ 0 ] ;
atexit ( F_10 ) ;
signal ( V_30 , F_9 ) ;
signal ( V_83 , F_9 ) ;
signal ( V_84 , F_9 ) ;
V_5 = F_35 ( V_6 , false , NULL ) ;
if ( V_5 == NULL ) {
F_3 ( L_12 ) ;
return - 1 ;
}
V_2 -> V_5 = V_5 ;
F_29 ( V_2 ) ;
if ( V_80 ) {
V_57 = F_36 ( V_2 -> V_39 , & V_42 -> V_48 ,
V_77 , V_6 -> V_85 ,
F_33 ) ;
if ( V_57 < 0 ) {
F_3 ( L_13 ) ;
V_78 = V_57 ;
goto V_86;
}
}
if ( F_11 ( V_2 ) != 0 ) {
V_57 = - 1 ;
goto V_87;
}
if ( ! V_2 -> V_39 -> V_88 )
F_31 ( & V_5 -> V_15 , V_89 ) ;
if ( V_6 -> V_85 ) {
V_57 = F_37 ( V_6 -> V_54 ) ;
if ( V_57 < 0 )
goto V_87;
} else {
V_57 = F_38 ( V_5 , V_2 -> V_39 ,
V_6 -> V_54 , false ) ;
if ( V_57 < 0 )
goto V_87;
}
if ( ! V_2 -> V_66
&& ! F_39 ( & V_5 -> V_15 , V_67 ) ) {
F_3 ( L_14
L_15 ) ;
V_57 = - 1 ;
goto V_87;
}
V_14 = & V_5 -> V_90 . V_91 ;
if ( V_6 -> V_85 ) {
V_57 = F_40 ( V_9 , V_5 ,
F_4 ) ;
if ( V_57 < 0 ) {
F_3 ( L_16 ) ;
goto V_87;
}
if ( F_32 ( & V_2 -> V_39 -> V_68 ) ) {
V_57 = F_41 ( V_9 , V_6 -> V_54 , V_2 -> V_39 ,
F_4 ) ;
if ( V_57 <= 0 ) {
F_3 ( L_17 ) ;
goto V_87;
}
V_2 -> V_7 += V_57 ;
}
}
V_57 = F_27 ( V_9 , F_4 ,
V_14 ) ;
if ( V_57 < 0 )
F_3 ( L_18
L_19
L_20 ) ;
V_57 = F_26 ( V_9 , F_4 ,
V_14 ) ;
if ( V_57 < 0 )
F_3 ( L_21
L_19
L_22 ) ;
if ( V_92 ) {
F_42 ( & V_5 -> V_90 ,
F_25 , V_9 ) ;
}
V_57 = F_43 ( V_14 , V_9 , & V_42 -> V_48 , V_2 -> V_39 -> V_45 ,
F_4 , V_42 -> V_93 ) ;
if ( V_57 != 0 )
goto V_87;
if ( V_2 -> V_94 ) {
struct V_95 V_96 ;
V_96 . V_97 = V_2 -> V_94 ;
if ( F_44 ( 0 , V_98 , & V_96 ) ) {
F_3 ( L_23 ) ;
V_57 = - 1 ;
goto V_87;
}
}
if ( ! F_45 ( & V_42 -> V_48 ) && ! V_42 -> V_99 )
F_46 ( V_2 -> V_39 ) ;
if ( V_80 )
F_47 ( V_2 -> V_39 ) ;
if ( V_42 -> V_99 ) {
F_48 ( V_42 -> V_99 * 1000 ) ;
F_46 ( V_2 -> V_39 ) ;
}
for (; ; ) {
int V_100 = V_2 -> V_26 ;
if ( F_28 ( V_2 ) < 0 ) {
V_57 = - 1 ;
goto V_87;
}
if ( V_100 == V_2 -> V_26 ) {
if ( V_33 )
break;
V_57 = F_49 ( V_2 -> V_39 -> V_101 , V_2 -> V_39 -> V_102 , - 1 ) ;
if ( V_57 > 0 || ( V_57 < 0 && V_46 == V_103 ) )
V_57 = 0 ;
V_79 ++ ;
}
if ( V_33 && ! V_81 && ! F_45 ( & V_42 -> V_48 ) ) {
F_50 ( V_2 -> V_39 ) ;
V_81 = true ;
}
}
if ( V_80 && V_73 ) {
char V_35 [ 512 ] ;
const char * V_104 = F_51 ( V_73 , V_35 , sizeof( V_35 ) ) ;
F_3 ( L_24 , V_104 ) ;
V_57 = - 1 ;
goto V_87;
}
if ( ! V_105 ) {
fprintf ( V_106 , L_25 , V_79 ) ;
fprintf ( V_106 ,
L_26 V_107 L_27 ,
( double ) V_2 -> V_7 / 1024.0 / 1024.0 ,
V_6 -> V_108 ,
V_2 -> V_7 / 24 ) ;
}
V_87:
if ( V_80 ) {
int V_109 ;
if ( ! V_31 )
F_52 ( V_2 -> V_39 -> V_110 . V_58 , V_84 ) ;
F_53 ( & V_109 ) ;
if ( V_57 < 0 )
V_78 = V_57 ;
else if ( F_54 ( V_109 ) )
V_78 = F_55 ( V_109 ) ;
else if ( F_56 ( V_109 ) )
V_32 = F_57 ( V_109 ) ;
} else
V_78 = V_57 ;
if ( ! V_57 && ! V_6 -> V_85 ) {
V_2 -> V_5 -> V_15 . V_111 += V_2 -> V_7 ;
if ( ! V_2 -> V_66 )
F_22 ( V_2 ) ;
F_38 ( V_2 -> V_5 , V_2 -> V_39 ,
V_6 -> V_54 , true ) ;
}
V_86:
F_58 ( V_5 ) ;
return V_78 ;
}
static int
F_59 ( const struct V_112 * V_113 , const char * V_114 , int V_115 )
{
#define F_60 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
T_7 * V_116 = ( T_7 * ) V_113 -> V_117 ;
const struct V_118 * V_119 ;
char * V_120 , * V_121 = NULL , * V_122 ;
int V_123 = - 1 ;
if ( V_115 )
return 0 ;
if ( * V_116 )
return - 1 ;
if ( V_114 ) {
V_120 = V_121 = F_61 ( V_114 ) ;
if ( ! V_120 )
return - 1 ;
for (; ; ) {
V_122 = strchr ( V_120 , ',' ) ;
if ( V_122 )
* V_122 = '\0' ;
for ( V_119 = V_124 ; V_119 -> V_125 ; V_119 ++ ) {
if ( ! strcasecmp ( V_120 , V_119 -> V_125 ) )
break;
}
if ( ! V_119 -> V_125 ) {
F_16 ( L_28
L_29 , V_120 ) ;
goto error;
}
* V_116 |= V_119 -> V_116 ;
if ( ! V_122 )
break;
V_120 = V_122 + 1 ;
}
}
V_123 = 0 ;
if ( ( * V_116 & ~ F_60 ) == 0 ) {
* V_116 = V_126 ;
}
error:
free ( V_121 ) ;
return V_123 ;
}
static int F_62 ( char * V_114 , unsigned long * V_127 )
{
char * V_128 ;
unsigned long V_4 ;
unsigned long V_129 = F_63 ( V_130 , sizeof( T_3 ) ) ;
V_4 = strtoul ( V_114 , & V_128 , 0 ) ;
do {
if ( * V_128 )
break;
V_4 = F_64 ( V_4 , sizeof( T_3 ) ) ;
if ( ! V_4 || V_4 > V_129 )
break;
* V_127 = V_4 ;
return 0 ;
} while ( 0 );
F_3 ( L_30 ,
V_129 , V_114 ) ;
return - 1 ;
}
int F_65 ( const char * V_131 , struct V_41 * V_42 )
{
char * V_132 , * V_125 , * V_133 = NULL ;
char * V_24 ;
int V_123 = - 1 ;
V_24 = malloc ( strlen ( V_131 ) + 1 ) ;
if ( ! V_24 )
return - V_134 ;
strcpy ( V_24 , V_131 ) ;
V_132 = strtok_r ( ( char * ) V_24 , L_31 , & V_133 ) ;
V_125 = V_132 ? : ( char * ) V_24 ;
do {
if ( ! strncmp ( V_125 , L_32 , sizeof( L_32 ) ) ) {
if ( ! strtok_r ( NULL , L_31 , & V_133 ) ) {
V_42 -> V_135 = V_136 ;
V_123 = 0 ;
} else
F_3 ( L_33
L_34 ) ;
break;
#ifdef F_66
} else if ( ! strncmp ( V_125 , L_35 , sizeof( L_35 ) ) ) {
const unsigned long V_137 = 8192 ;
V_123 = 0 ;
V_42 -> V_135 = V_138 ;
V_42 -> V_139 = V_137 ;
V_132 = strtok_r ( NULL , L_31 , & V_133 ) ;
if ( V_132 ) {
unsigned long V_4 = 0 ;
V_123 = F_62 ( V_132 , & V_4 ) ;
V_42 -> V_139 = V_4 ;
}
#endif
} else {
F_3 ( L_36
L_37 , V_131 ) ;
break;
}
} while ( 0 );
free ( V_24 ) ;
return V_123 ;
}
static void F_67 ( struct V_41 * V_42 )
{
static const char * V_114 [ V_140 ] = { L_38 , L_39 , L_40 } ;
F_68 ( L_41 , V_114 [ V_42 -> V_135 ] ) ;
if ( V_42 -> V_135 == V_138 )
F_68 ( L_42 ,
V_42 -> V_139 ) ;
}
int F_69 ( const struct V_112 * V_113 ,
const char * V_131 ,
int V_115 )
{
struct V_41 * V_42 = V_113 -> V_117 ;
int V_123 ;
V_42 -> V_141 = ! V_115 ;
if ( V_115 ) {
V_42 -> V_135 = V_142 ;
F_68 ( L_43 ) ;
return 0 ;
}
V_123 = F_65 ( V_131 , V_42 ) ;
if ( ! V_123 )
F_67 ( V_42 ) ;
return V_123 ;
}
int F_70 ( const struct V_112 * V_113 ,
const char * V_131 V_13 ,
int V_115 V_13 )
{
struct V_41 * V_42 = V_113 -> V_117 ;
V_42 -> V_141 = ! V_115 ;
if ( V_42 -> V_135 == V_142 )
V_42 -> V_135 = V_136 ;
F_67 ( V_42 ) ;
return 0 ;
}
static int F_71 ( const char * V_143 , const char * V_117 , void * V_144 )
{
struct V_1 * V_2 = V_144 ;
if ( ! strcmp ( V_143 , L_44 ) )
return F_65 ( V_117 , & V_2 -> V_42 ) ;
return F_72 ( V_143 , V_117 , V_144 ) ;
}
int F_73 ( int V_76 , const char * * V_77 , const char * T_8 V_13 )
{
int V_57 = - V_134 ;
struct V_1 * V_2 = & V_1 ;
char V_145 [ V_146 ] ;
V_2 -> V_39 = F_74 () ;
if ( V_2 -> V_39 == NULL )
return - V_134 ;
F_75 ( F_71 , V_2 ) ;
V_76 = F_76 ( V_76 , V_77 , V_147 , V_148 ,
V_149 ) ;
if ( ! V_76 && F_45 ( & V_2 -> V_42 . V_48 ) )
F_77 ( V_148 , V_147 ) ;
if ( V_150 && ! V_2 -> V_42 . V_48 . V_151 ) {
F_18 ( L_45
L_46 ) ;
F_77 ( V_148 , V_147 ) ;
}
F_78 () ;
if ( V_152 . V_153 )
F_79 (
L_47
L_48
L_49
L_50
L_51
L_52
L_53 ) ;
if ( V_2 -> V_154 || V_2 -> V_66 )
F_80 () ;
if ( V_2 -> V_39 -> V_155 == 0 &&
F_81 ( V_2 -> V_39 ) < 0 ) {
F_3 ( L_54 ) ;
goto V_156;
}
if ( V_2 -> V_42 . V_48 . V_157 && ! V_2 -> V_42 . V_158 )
V_2 -> V_42 . V_159 = true ;
V_57 = F_82 ( & V_2 -> V_42 . V_48 ) ;
if ( V_57 ) {
F_83 ( & V_2 -> V_42 . V_48 , V_57 , V_145 , V_146 ) ;
F_16 ( L_55 , V_145 ) ;
}
V_57 = F_84 ( & V_2 -> V_42 . V_48 ) ;
if ( V_57 ) {
int V_160 = V_46 ;
F_83 ( & V_2 -> V_42 . V_48 , V_57 , V_145 , V_146 ) ;
F_18 ( L_55 , V_145 ) ;
V_57 = - V_160 ;
goto V_156;
}
V_57 = - V_134 ;
if ( F_85 ( V_2 -> V_39 , & V_2 -> V_42 . V_48 ) < 0 )
F_77 ( V_148 , V_147 ) ;
if ( F_86 ( & V_2 -> V_42 ) ) {
V_57 = - V_161 ;
goto V_156;
}
V_57 = F_34 ( & V_1 , V_76 , V_77 ) ;
V_156:
F_87 ( V_2 -> V_39 ) ;
F_88 () ;
return V_57 ;
}
