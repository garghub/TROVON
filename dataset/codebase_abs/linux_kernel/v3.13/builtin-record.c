static int F_1 ( T_1 V_1 , void * V_2 )
{
if ( V_3 == V_4 )
return - V_5 ;
else if ( V_3 == 0 )
atexit ( V_6 ) ;
V_7 [ V_3 ] = V_1 ;
V_8 [ V_3 ++ ] = V_2 ;
return 0 ;
}
static void V_6 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_3 ; V_9 ++ )
V_7 [ V_9 ] ( V_10 , V_8 [ V_9 ] ) ;
}
static int F_2 ( struct V_11 * V_12 , void * V_13 , T_2 V_14 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
while ( V_14 ) {
T_3 V_17 = F_3 ( V_16 -> V_18 , V_13 , V_14 ) ;
if ( V_17 < 0 ) {
F_4 ( L_1 ) ;
return - 1 ;
}
V_14 -= V_17 ;
V_13 += V_17 ;
V_12 -> V_19 += V_17 ;
}
return 0 ;
}
static int F_5 ( struct V_11 * V_12 , void * V_13 , T_2 V_14 )
{
return F_2 ( V_12 , V_13 , V_14 ) ;
}
static int F_6 ( struct V_20 * V_21 ,
union V_22 * V_23 ,
struct V_24 * T_4 V_25 ,
struct V_26 * V_26 V_25 )
{
struct V_11 * V_12 = F_7 ( V_21 , struct V_11 , V_21 ) ;
if ( F_5 ( V_12 , V_23 , V_23 -> V_27 . V_14 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 ,
struct V_28 * V_29 )
{
unsigned int V_30 = F_9 ( V_29 ) ;
unsigned int V_31 = V_29 -> V_32 ;
unsigned char * V_33 = V_29 -> V_34 + V_35 ;
unsigned long V_14 ;
void * V_13 ;
int V_36 = 0 ;
if ( V_31 == V_30 )
return 0 ;
V_12 -> V_37 ++ ;
V_14 = V_30 - V_31 ;
if ( ( V_31 & V_29 -> V_38 ) + V_14 != ( V_30 & V_29 -> V_38 ) ) {
V_13 = & V_33 [ V_31 & V_29 -> V_38 ] ;
V_14 = V_29 -> V_38 + 1 - ( V_31 & V_29 -> V_38 ) ;
V_31 += V_14 ;
if ( F_5 ( V_12 , V_13 , V_14 ) < 0 ) {
V_36 = - 1 ;
goto V_39;
}
}
V_13 = & V_33 [ V_31 & V_29 -> V_38 ] ;
V_14 = V_30 - V_31 ;
V_31 += V_14 ;
if ( F_5 ( V_12 , V_13 , V_14 ) < 0 ) {
V_36 = - 1 ;
goto V_39;
}
V_29 -> V_32 = V_31 ;
F_10 ( V_29 , V_31 ) ;
V_39:
return V_36 ;
}
static void F_11 ( int V_40 )
{
if ( V_40 == V_41 )
V_42 = 1 ;
V_43 = 1 ;
V_44 = V_40 ;
}
static void F_12 ( int T_5 V_25 , void * V_2 )
{
struct V_11 * V_12 = V_2 ;
int V_45 ;
if ( V_12 -> V_46 -> V_47 . V_48 > 0 ) {
if ( ! V_42 )
F_13 ( V_12 -> V_46 -> V_47 . V_48 , V_49 ) ;
F_14 ( & V_45 ) ;
if ( F_15 ( V_45 ) )
F_16 ( F_17 ( V_45 ) , V_12 -> V_50 ) ;
}
if ( V_44 == - 1 || V_44 == V_51 )
return;
signal ( V_44 , V_52 ) ;
}
static int F_18 ( struct V_11 * V_12 )
{
char V_53 [ 512 ] ;
struct V_54 * V_55 ;
struct V_56 * V_46 = V_12 -> V_46 ;
struct V_57 * V_58 = V_12 -> V_58 ;
struct V_59 * V_60 = & V_12 -> V_60 ;
int V_36 = 0 ;
F_19 ( V_46 , V_60 ) ;
F_20 (pos, &evlist->entries, node) {
V_61:
if ( F_21 ( V_55 , V_46 -> V_62 , V_46 -> V_63 ) < 0 ) {
if ( F_22 ( V_55 , V_64 , V_53 , sizeof( V_53 ) ) ) {
if ( V_65 )
F_23 ( L_2 , V_53 ) ;
goto V_61;
}
V_36 = - V_64 ;
F_24 ( V_55 , & V_60 -> V_66 ,
V_64 , V_53 , sizeof( V_53 ) ) ;
F_25 ( L_2 , V_53 ) ;
goto V_39;
}
}
if ( F_26 ( V_46 ) ) {
error ( L_3 , V_64 ,
strerror ( V_64 ) ) ;
V_36 = - 1 ;
goto V_39;
}
if ( F_27 ( V_46 , V_60 -> V_67 , false ) < 0 ) {
if ( V_64 == V_68 ) {
F_4 ( L_4
L_5
L_6
L_7
L_8 , V_60 -> V_67 ) ;
V_36 = - V_64 ;
} else {
F_4 ( L_9 , V_64 , strerror ( V_64 ) ) ;
V_36 = - V_64 ;
}
goto V_39;
}
V_58 -> V_46 = V_46 ;
F_28 ( V_58 ) ;
V_39:
return V_36 ;
}
static int F_29 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
struct V_57 * V_58 = V_12 -> V_58 ;
T_6 V_69 = V_58 -> V_27 . V_70 ;
T_6 V_14 = F_30 ( V_16 -> V_18 , 0 , V_71 ) ;
if ( V_14 == 0 )
return 0 ;
return F_31 ( V_58 , V_69 ,
V_14 - V_69 ,
V_14 , & V_72 ) ;
}
static void F_32 ( int V_45 , void * V_2 )
{
struct V_11 * V_12 = V_2 ;
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( V_45 != 0 )
return;
if ( ! V_16 -> V_73 ) {
V_12 -> V_58 -> V_27 . V_74 += V_12 -> V_19 ;
if ( ! V_12 -> V_75 )
F_29 ( V_12 ) ;
F_33 ( V_12 -> V_58 , V_12 -> V_46 ,
V_16 -> V_18 , true ) ;
F_34 ( V_12 -> V_58 ) ;
F_35 ( V_12 -> V_46 ) ;
F_36 () ;
}
}
static void F_37 ( struct V_26 * V_26 , void * V_33 )
{
int V_76 ;
struct V_20 * V_21 = V_33 ;
V_76 = F_38 ( V_21 , F_6 ,
V_26 ) ;
if ( V_76 < 0 )
F_4 ( L_10
L_11 , V_26 -> V_48 ) ;
V_76 = F_39 ( V_21 , F_6 ,
V_26 , L_12 ) ;
if ( V_76 < 0 )
V_76 = F_39 ( V_21 , F_6 ,
V_26 , L_13 ) ;
if ( V_76 < 0 )
F_4 ( L_10
L_11 , V_26 -> V_48 ) ;
}
static int F_40 ( struct V_11 * V_12 )
{
int V_9 ;
int V_36 = 0 ;
for ( V_9 = 0 ; V_9 < V_12 -> V_46 -> V_77 ; V_9 ++ ) {
if ( V_12 -> V_46 -> V_78 [ V_9 ] . V_34 ) {
if ( F_8 ( V_12 , & V_12 -> V_46 -> V_78 [ V_9 ] ) != 0 ) {
V_36 = - 1 ;
goto V_39;
}
}
}
if ( F_41 ( & V_12 -> V_58 -> V_27 , V_79 ) )
V_36 = F_5 ( V_12 , & V_80 ,
sizeof( V_80 ) ) ;
V_39:
return V_36 ;
}
static void F_42 ( struct V_11 * V_12 )
{
struct V_56 * V_81 = V_12 -> V_46 ;
struct V_57 * V_58 = V_12 -> V_58 ;
int V_82 ;
for ( V_82 = V_83 ; V_82 < V_84 ; V_82 ++ )
F_43 ( & V_58 -> V_27 , V_82 ) ;
if ( V_12 -> V_75 )
F_44 ( & V_58 -> V_27 , V_85 ) ;
if ( ! F_45 ( & V_81 -> V_86 ) )
F_44 ( & V_58 -> V_27 , V_79 ) ;
if ( ! V_12 -> V_60 . V_87 )
F_44 ( & V_58 -> V_27 , V_88 ) ;
}
static int F_46 ( struct V_11 * V_12 , int V_89 , const char * * V_90 )
{
int V_76 ;
unsigned long V_91 = 0 ;
const bool V_92 = V_89 > 0 ;
struct V_26 * V_26 ;
struct V_20 * V_21 = & V_12 -> V_21 ;
struct V_59 * V_60 = & V_12 -> V_60 ;
struct V_56 * V_81 = V_12 -> V_46 ;
struct V_15 * V_16 = & V_12 -> V_16 ;
struct V_57 * V_58 ;
bool V_93 = false ;
V_12 -> V_50 = V_90 [ 0 ] ;
F_1 ( F_12 , V_12 ) ;
signal ( V_41 , F_11 ) ;
signal ( V_94 , F_11 ) ;
signal ( V_51 , F_11 ) ;
signal ( V_49 , F_11 ) ;
V_58 = F_47 ( V_16 , false , NULL ) ;
if ( V_58 == NULL ) {
F_4 ( L_14 ) ;
return - 1 ;
}
V_12 -> V_58 = V_58 ;
F_42 ( V_12 ) ;
if ( V_92 ) {
V_76 = F_48 ( V_81 , & V_60 -> V_66 ,
V_90 , V_16 -> V_73 ,
true ) ;
if ( V_76 < 0 ) {
F_4 ( L_15 ) ;
goto V_95;
}
}
if ( F_18 ( V_12 ) != 0 ) {
V_76 = - 1 ;
goto V_95;
}
if ( ! V_81 -> V_96 )
F_44 ( & V_58 -> V_27 , V_97 ) ;
F_1 ( F_32 , V_12 ) ;
if ( V_16 -> V_73 ) {
V_76 = F_49 ( V_16 -> V_18 ) ;
if ( V_76 < 0 )
goto V_95;
} else {
V_76 = F_33 ( V_58 , V_81 ,
V_16 -> V_18 , false ) ;
if ( V_76 < 0 )
goto V_95;
}
if ( ! V_12 -> V_75
&& ! F_41 ( & V_58 -> V_27 , V_85 ) ) {
F_4 ( L_16
L_17 ) ;
V_76 = - 1 ;
goto V_95;
}
V_26 = & V_58 -> V_98 . V_99 ;
if ( V_16 -> V_73 ) {
V_76 = F_50 ( V_21 , V_58 ,
F_6 ) ;
if ( V_76 < 0 ) {
F_4 ( L_18 ) ;
goto V_95;
}
if ( F_45 ( & V_81 -> V_86 ) ) {
V_76 = F_51 ( V_21 , V_16 -> V_18 , V_81 ,
F_6 ) ;
if ( V_76 <= 0 ) {
F_4 ( L_19 ) ;
goto V_95;
}
V_12 -> V_19 += V_76 ;
}
}
V_76 = F_39 ( V_21 , F_6 ,
V_26 , L_12 ) ;
if ( V_76 < 0 )
V_76 = F_39 ( V_21 , F_6 ,
V_26 , L_13 ) ;
if ( V_76 < 0 )
F_4 ( L_20
L_21
L_22 ) ;
V_76 = F_38 ( V_21 , F_6 ,
V_26 ) ;
if ( V_76 < 0 )
F_4 ( L_23
L_21
L_24 ) ;
if ( V_100 ) {
F_52 ( & V_58 -> V_98 ,
F_37 , V_21 ) ;
}
V_76 = F_53 ( V_26 , V_21 , & V_60 -> V_66 , V_81 -> V_63 ,
F_6 , V_60 -> V_101 ) ;
if ( V_76 != 0 )
goto V_95;
if ( V_12 -> V_102 ) {
struct V_103 V_104 ;
V_104 . V_105 = V_12 -> V_102 ;
if ( F_54 ( 0 , V_106 , & V_104 ) ) {
F_4 ( L_25 ) ;
V_76 = - 1 ;
goto V_95;
}
}
if ( ! F_55 ( & V_60 -> V_66 ) )
F_56 ( V_81 ) ;
if ( V_92 )
F_57 ( V_81 ) ;
for (; ; ) {
int V_107 = V_12 -> V_37 ;
if ( F_40 ( V_12 ) < 0 ) {
V_76 = - 1 ;
goto V_95;
}
if ( V_107 == V_12 -> V_37 ) {
if ( V_43 )
break;
V_76 = F_58 ( V_81 -> V_108 , V_81 -> V_109 , - 1 ) ;
V_91 ++ ;
}
if ( V_43 && ! V_93 && ! F_55 ( & V_60 -> V_66 ) ) {
F_59 ( V_81 ) ;
V_93 = true ;
}
}
if ( V_110 || V_44 == V_51 )
return 0 ;
fprintf ( V_111 , L_26 , V_91 ) ;
fprintf ( V_111 ,
L_27 V_112 L_28 ,
( double ) V_12 -> V_19 / 1024.0 / 1024.0 ,
V_16 -> V_113 ,
V_12 -> V_19 / 24 ) ;
return 0 ;
V_95:
F_34 ( V_58 ) ;
return V_76 ;
}
static int
F_60 ( const struct V_114 * V_115 , const char * V_116 , int V_117 )
{
#define F_61 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
T_7 * V_118 = ( T_7 * ) V_115 -> V_119 ;
const struct V_120 * V_121 ;
char * V_122 , * V_123 = NULL , * V_124 ;
int V_17 = - 1 ;
if ( V_117 )
return 0 ;
if ( * V_118 )
return - 1 ;
if ( V_116 ) {
V_122 = V_123 = F_62 ( V_116 ) ;
if ( ! V_122 )
return - 1 ;
for (; ; ) {
V_124 = strchr ( V_122 , ',' ) ;
if ( V_124 )
* V_124 = '\0' ;
for ( V_121 = V_125 ; V_121 -> V_126 ; V_121 ++ ) {
if ( ! strcasecmp ( V_122 , V_121 -> V_126 ) )
break;
}
if ( ! V_121 -> V_126 ) {
F_23 ( L_29
L_30 , V_122 ) ;
goto error;
}
* V_118 |= V_121 -> V_118 ;
if ( ! V_124 )
break;
V_122 = V_124 + 1 ;
}
}
V_17 = 0 ;
if ( ( * V_118 & ~ F_61 ) == 0 ) {
* V_118 = V_127 ;
}
error:
free ( V_123 ) ;
return V_17 ;
}
static int F_63 ( char * V_116 , unsigned long * V_128 )
{
char * V_129 ;
unsigned long V_14 ;
unsigned long V_130 = F_64 ( V_131 , sizeof( T_6 ) ) ;
V_14 = strtoul ( V_116 , & V_129 , 0 ) ;
do {
if ( * V_129 )
break;
V_14 = F_65 ( V_14 , sizeof( T_6 ) ) ;
if ( ! V_14 || V_14 > V_130 )
break;
* V_128 = V_14 ;
return 0 ;
} while ( 0 );
F_4 ( L_31 ,
V_130 , V_116 ) ;
return - 1 ;
}
int F_66 ( const char * V_2 , struct V_59 * V_60 )
{
char * V_132 , * V_126 , * V_133 = NULL ;
char * V_13 ;
int V_17 = - 1 ;
V_13 = malloc ( strlen ( V_2 ) + 1 ) ;
if ( ! V_13 )
return - V_5 ;
strcpy ( V_13 , V_2 ) ;
V_132 = strtok_r ( ( char * ) V_13 , L_32 , & V_133 ) ;
V_126 = V_132 ? : ( char * ) V_13 ;
do {
if ( ! strncmp ( V_126 , L_33 , sizeof( L_33 ) ) ) {
if ( ! strtok_r ( NULL , L_32 , & V_133 ) ) {
V_60 -> V_134 = V_135 ;
V_17 = 0 ;
} else
F_4 ( L_34
L_35 ) ;
break;
#ifdef F_67
} else if ( ! strncmp ( V_126 , L_36 , sizeof( L_36 ) ) ) {
const unsigned long V_136 = 8192 ;
V_17 = 0 ;
V_60 -> V_134 = V_137 ;
V_60 -> V_138 = V_136 ;
V_132 = strtok_r ( NULL , L_32 , & V_133 ) ;
if ( V_132 ) {
unsigned long V_14 = 0 ;
V_17 = F_63 ( V_132 , & V_14 ) ;
V_60 -> V_138 = V_14 ;
}
#endif
} else {
F_4 ( L_37
L_38 , V_2 ) ;
break;
}
} while ( 0 );
free ( V_13 ) ;
return V_17 ;
}
static void F_68 ( struct V_59 * V_60 )
{
F_69 ( L_39 , V_60 -> V_134 ) ;
if ( V_60 -> V_134 == V_137 )
F_69 ( L_40 ,
V_60 -> V_138 ) ;
}
int F_70 ( const struct V_114 * V_115 ,
const char * V_2 ,
int V_117 )
{
struct V_59 * V_60 = V_115 -> V_119 ;
int V_17 ;
if ( V_117 ) {
V_60 -> V_134 = V_139 ;
F_69 ( L_41 ) ;
return 0 ;
}
V_17 = F_66 ( V_2 , V_60 ) ;
if ( ! V_17 )
F_68 ( V_60 ) ;
return V_17 ;
}
int F_71 ( const struct V_114 * V_115 ,
const char * V_2 V_25 ,
int V_117 V_25 )
{
struct V_59 * V_60 = V_115 -> V_119 ;
if ( V_60 -> V_134 == V_139 )
V_60 -> V_134 = V_135 ;
F_68 ( V_60 ) ;
return 0 ;
}
int F_72 ( int V_89 , const char * * V_90 , const char * T_8 V_25 )
{
int V_76 = - V_5 ;
struct V_56 * V_81 ;
struct V_11 * V_12 = & V_140 ;
char V_141 [ V_142 ] ;
V_81 = F_73 () ;
if ( V_81 == NULL )
return - V_5 ;
V_12 -> V_46 = V_81 ;
V_89 = F_74 ( V_89 , V_90 , V_143 , V_144 ,
V_145 ) ;
if ( ! V_89 && F_55 ( & V_12 -> V_60 . V_66 ) )
F_75 ( V_144 , V_143 ) ;
if ( V_146 && ! V_12 -> V_60 . V_66 . V_147 ) {
F_25 ( L_42
L_43 ) ;
F_75 ( V_144 , V_143 ) ;
}
F_76 () ;
if ( V_148 . V_149 )
F_77 (
L_44
L_45
L_46
L_47
L_48
L_49
L_50 ) ;
if ( V_12 -> V_150 || V_12 -> V_75 )
F_78 () ;
if ( V_81 -> V_151 == 0 &&
F_79 ( V_81 ) < 0 ) {
F_4 ( L_51 ) ;
goto V_152;
}
V_76 = F_80 ( & V_12 -> V_60 . V_66 ) ;
if ( V_76 ) {
F_81 ( & V_12 -> V_60 . V_66 , V_76 , V_141 , V_142 ) ;
F_23 ( L_52 , V_141 ) ;
}
V_76 = F_82 ( & V_12 -> V_60 . V_66 ) ;
if ( V_76 ) {
int V_153 = V_64 ;
F_81 ( & V_12 -> V_60 . V_66 , V_76 , V_141 , V_142 ) ;
F_25 ( L_52 , V_141 ) ;
V_76 = - V_153 ;
goto V_152;
}
V_76 = - V_5 ;
if ( F_83 ( V_81 , & V_12 -> V_60 . V_66 ) < 0 )
F_75 ( V_144 , V_143 ) ;
if ( F_84 ( & V_12 -> V_60 ) ) {
V_76 = - V_154 ;
goto V_155;
}
V_76 = F_46 ( & V_140 , V_89 , V_90 ) ;
F_85 ( V_81 ) ;
F_86 ( V_81 ) ;
V_155:
F_87 ( V_81 ) ;
V_152:
F_36 () ;
return V_76 ;
}
