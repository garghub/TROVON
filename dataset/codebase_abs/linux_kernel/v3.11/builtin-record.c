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
static void F_2 ( struct V_11 * V_12 , T_2 V_13 )
{
V_12 -> V_14 += V_13 ;
}
static int F_3 ( struct V_11 * V_12 , void * V_15 , T_2 V_13 )
{
while ( V_13 ) {
int V_16 = F_4 ( V_12 -> V_17 , V_15 , V_13 ) ;
if ( V_16 < 0 ) {
F_5 ( L_1 ) ;
return - 1 ;
}
V_13 -= V_16 ;
V_15 += V_16 ;
V_12 -> V_14 += V_16 ;
}
return 0 ;
}
static int F_6 ( struct V_18 * V_19 ,
union V_20 * V_21 ,
struct V_22 * T_3 V_23 ,
struct V_24 * V_24 V_23 )
{
struct V_11 * V_12 = F_7 ( V_19 , struct V_11 , V_19 ) ;
if ( F_3 ( V_12 , V_21 , V_21 -> V_25 . V_13 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 ,
struct V_26 * V_27 )
{
unsigned int V_28 = F_9 ( V_27 ) ;
unsigned int V_29 = V_27 -> V_30 ;
unsigned char * V_31 = V_27 -> V_32 + V_12 -> V_33 ;
unsigned long V_13 ;
void * V_15 ;
int V_34 = 0 ;
if ( V_29 == V_28 )
return 0 ;
V_12 -> V_35 ++ ;
V_13 = V_28 - V_29 ;
if ( ( V_29 & V_27 -> V_36 ) + V_13 != ( V_28 & V_27 -> V_36 ) ) {
V_15 = & V_31 [ V_29 & V_27 -> V_36 ] ;
V_13 = V_27 -> V_36 + 1 - ( V_29 & V_27 -> V_36 ) ;
V_29 += V_13 ;
if ( F_3 ( V_12 , V_15 , V_13 ) < 0 ) {
V_34 = - 1 ;
goto V_37;
}
}
V_15 = & V_31 [ V_29 & V_27 -> V_36 ] ;
V_13 = V_28 - V_29 ;
V_29 += V_13 ;
if ( F_3 ( V_12 , V_15 , V_13 ) < 0 ) {
V_34 = - 1 ;
goto V_37;
}
V_27 -> V_30 = V_29 ;
F_10 ( V_27 , V_29 ) ;
V_37:
return V_34 ;
}
static void F_11 ( int V_38 )
{
if ( V_38 == V_39 )
V_40 = 1 ;
V_41 = 1 ;
V_42 = V_38 ;
}
static void F_12 ( int T_4 V_23 , void * V_2 )
{
struct V_11 * V_12 = V_2 ;
int V_43 ;
if ( V_12 -> V_44 -> V_45 . V_46 > 0 ) {
if ( ! V_40 )
F_13 ( V_12 -> V_44 -> V_45 . V_46 , V_47 ) ;
F_14 ( & V_43 ) ;
if ( F_15 ( V_43 ) )
F_16 ( F_17 ( V_43 ) , V_12 -> V_48 ) ;
}
if ( V_42 == - 1 || V_42 == V_49 )
return;
signal ( V_42 , V_50 ) ;
}
static int F_18 ( struct V_11 * V_12 )
{
char V_51 [ 512 ] ;
struct V_52 * V_53 ;
struct V_54 * V_44 = V_12 -> V_44 ;
struct V_55 * V_56 = V_12 -> V_56 ;
struct V_57 * V_58 = & V_12 -> V_58 ;
int V_34 = 0 ;
F_19 ( V_44 , V_58 ) ;
F_20 (pos, &evlist->entries, node) {
V_59:
if ( F_21 ( V_53 , V_44 -> V_60 , V_44 -> V_61 ) < 0 ) {
if ( F_22 ( V_53 , V_62 , V_51 , sizeof( V_51 ) ) ) {
if ( V_63 )
F_23 ( L_2 , V_51 ) ;
goto V_59;
}
V_34 = - V_62 ;
F_24 ( V_53 , & V_58 -> V_64 ,
V_62 , V_51 , sizeof( V_51 ) ) ;
F_25 ( L_2 , V_51 ) ;
goto V_37;
}
}
if ( F_26 ( V_44 ) ) {
error ( L_3 , V_62 ,
strerror ( V_62 ) ) ;
V_34 = - 1 ;
goto V_37;
}
if ( F_27 ( V_44 , V_58 -> V_65 , false ) < 0 ) {
if ( V_62 == V_66 ) {
F_5 ( L_4
L_5
L_6
L_7
L_8 , V_58 -> V_65 ) ;
V_34 = - V_62 ;
} else if ( ! F_28 ( V_58 -> V_65 ) &&
( V_58 -> V_65 != V_67 ) ) {
F_5 ( L_9 ) ;
V_34 = - V_68 ;
} else {
F_5 ( L_10 , V_62 , strerror ( V_62 ) ) ;
V_34 = - V_62 ;
}
goto V_37;
}
V_56 -> V_44 = V_44 ;
F_29 ( V_56 ) ;
V_37:
return V_34 ;
}
static int F_30 ( struct V_11 * V_12 )
{
T_5 V_13 = F_31 ( V_12 -> V_17 , 0 , V_69 ) ;
if ( V_13 == 0 )
return 0 ;
V_12 -> V_56 -> V_70 = V_12 -> V_17 ;
return F_32 ( V_12 -> V_56 , V_12 -> V_71 ,
V_13 - V_12 -> V_71 ,
V_13 , & V_72 ) ;
}
static void F_33 ( int V_43 , void * V_2 )
{
struct V_11 * V_12 = V_2 ;
if ( V_43 != 0 )
return;
if ( ! V_12 -> V_58 . V_73 ) {
V_12 -> V_56 -> V_25 . V_74 += V_12 -> V_14 ;
if ( ! V_12 -> V_75 )
F_30 ( V_12 ) ;
F_34 ( V_12 -> V_56 , V_12 -> V_44 ,
V_12 -> V_17 , true ) ;
F_35 ( V_12 -> V_56 ) ;
F_36 ( V_12 -> V_44 ) ;
F_37 () ;
}
}
static void F_38 ( struct V_24 * V_24 , void * V_31 )
{
int V_76 ;
struct V_18 * V_19 = V_31 ;
V_76 = F_39 ( V_19 , F_6 ,
V_24 ) ;
if ( V_76 < 0 )
F_5 ( L_11
L_12 , V_24 -> V_46 ) ;
V_76 = F_40 ( V_19 , F_6 ,
V_24 , L_13 ) ;
if ( V_76 < 0 )
V_76 = F_40 ( V_19 , F_6 ,
V_24 , L_14 ) ;
if ( V_76 < 0 )
F_5 ( L_11
L_12 , V_24 -> V_46 ) ;
}
static int F_41 ( struct V_11 * V_12 )
{
int V_9 ;
int V_34 = 0 ;
for ( V_9 = 0 ; V_9 < V_12 -> V_44 -> V_77 ; V_9 ++ ) {
if ( V_12 -> V_44 -> V_78 [ V_9 ] . V_32 ) {
if ( F_8 ( V_12 , & V_12 -> V_44 -> V_78 [ V_9 ] ) != 0 ) {
V_34 = - 1 ;
goto V_37;
}
}
}
if ( F_42 ( & V_12 -> V_56 -> V_25 , V_79 ) )
V_34 = F_3 ( V_12 , & V_80 ,
sizeof( V_80 ) ) ;
V_37:
return V_34 ;
}
static int F_43 ( struct V_11 * V_12 , int V_81 , const char * * V_82 )
{
struct V_83 V_84 ;
int V_85 ;
int V_76 , V_17 , V_86 ;
unsigned long V_87 = 0 ;
const bool V_88 = V_81 > 0 ;
struct V_24 * V_24 ;
struct V_18 * V_19 = & V_12 -> V_19 ;
struct V_57 * V_58 = & V_12 -> V_58 ;
struct V_54 * V_89 = V_12 -> V_44 ;
const char * V_90 = V_12 -> V_90 ;
struct V_55 * V_56 ;
bool V_91 = false ;
V_12 -> V_48 = V_82 [ 0 ] ;
V_12 -> V_33 = F_44 ( V_92 ) ;
F_1 ( F_12 , V_12 ) ;
signal ( V_39 , F_11 ) ;
signal ( V_93 , F_11 ) ;
signal ( V_49 , F_11 ) ;
signal ( V_47 , F_11 ) ;
if ( ! V_90 ) {
if ( ! F_45 ( V_94 , & V_84 ) && F_46 ( V_84 . V_95 ) )
V_58 -> V_73 = true ;
else
V_12 -> V_90 = V_90 = L_15 ;
}
if ( V_90 ) {
if ( ! strcmp ( V_90 , L_16 ) )
V_58 -> V_73 = true ;
else if ( ! V_83 ( V_90 , & V_84 ) && V_84 . V_96 ) {
char V_97 [ V_98 ] ;
snprintf ( V_97 , sizeof( V_97 ) , L_17 ,
V_90 ) ;
F_47 ( V_97 ) ;
rename ( V_90 , V_97 ) ;
}
}
V_85 = V_99 | V_100 | V_101 ;
if ( V_58 -> V_73 )
V_17 = V_94 ;
else
V_17 = F_48 ( V_90 , V_85 , V_102 | V_103 ) ;
if ( V_17 < 0 ) {
perror ( L_18 ) ;
return - 1 ;
}
V_12 -> V_17 = V_17 ;
V_56 = F_49 ( V_90 , V_104 ,
true , false , NULL ) ;
if ( V_56 == NULL ) {
F_5 ( L_19 ) ;
return - 1 ;
}
V_12 -> V_56 = V_56 ;
for ( V_86 = V_105 ; V_86 < V_106 ; V_86 ++ )
F_50 ( & V_56 -> V_25 , V_86 ) ;
if ( V_12 -> V_75 )
F_51 ( & V_56 -> V_25 , V_107 ) ;
if ( ! F_52 ( & V_89 -> V_108 ) )
F_51 ( & V_56 -> V_25 , V_79 ) ;
if ( ! V_12 -> V_58 . V_109 )
F_51 ( & V_56 -> V_25 , V_110 ) ;
if ( V_88 ) {
V_76 = F_53 ( V_89 , & V_58 -> V_64 ,
V_82 , V_58 -> V_73 ,
true ) ;
if ( V_76 < 0 ) {
F_5 ( L_20 ) ;
goto V_111;
}
}
if ( F_18 ( V_12 ) != 0 ) {
V_76 = - 1 ;
goto V_111;
}
if ( ! V_89 -> V_112 )
F_51 ( & V_56 -> V_25 , V_113 ) ;
F_1 ( F_33 , V_12 ) ;
if ( V_58 -> V_73 ) {
V_76 = F_54 ( V_17 ) ;
if ( V_76 < 0 )
goto V_111;
} else {
V_76 = F_34 ( V_56 , V_89 ,
V_17 , false ) ;
if ( V_76 < 0 )
goto V_111;
}
if ( ! V_12 -> V_75
&& ! F_42 ( & V_56 -> V_25 , V_107 ) ) {
F_5 ( L_21
L_22 ) ;
V_76 = - 1 ;
goto V_111;
}
V_12 -> V_71 = F_31 ( V_17 , 0 , V_69 ) ;
V_24 = & V_56 -> V_114 . V_115 ;
if ( V_58 -> V_73 ) {
V_76 = F_55 ( V_19 , V_56 ,
F_6 ) ;
if ( V_76 < 0 ) {
F_5 ( L_23 ) ;
goto V_111;
}
V_76 = F_56 ( V_19 , F_6 ,
V_24 ) ;
if ( V_76 < 0 ) {
F_5 ( L_24 ) ;
goto V_111;
}
if ( F_52 ( & V_89 -> V_108 ) ) {
V_76 = F_57 ( V_19 , V_17 , V_89 ,
F_6 ) ;
if ( V_76 <= 0 ) {
F_5 ( L_25 ) ;
goto V_111;
}
F_2 ( V_12 , V_76 ) ;
}
}
V_76 = F_40 ( V_19 , F_6 ,
V_24 , L_13 ) ;
if ( V_76 < 0 )
V_76 = F_40 ( V_19 , F_6 ,
V_24 , L_14 ) ;
if ( V_76 < 0 )
F_5 ( L_26
L_27
L_28 ) ;
V_76 = F_39 ( V_19 , F_6 ,
V_24 ) ;
if ( V_76 < 0 )
F_5 ( L_29
L_27
L_30 ) ;
if ( V_116 ) {
F_58 ( & V_56 -> V_114 ,
F_38 , V_19 ) ;
}
if ( F_59 ( & V_58 -> V_64 ) )
V_76 = F_60 ( V_19 , V_89 -> V_61 ,
F_6 ,
V_24 ) ;
else if ( F_61 ( & V_58 -> V_64 ) )
V_76 = F_62 ( V_19 , F_6 ,
V_24 ) ;
else
V_76 = 0 ;
if ( V_76 != 0 )
goto V_111;
if ( V_12 -> V_117 ) {
struct V_118 V_119 ;
V_119 . V_120 = V_12 -> V_117 ;
if ( F_63 ( 0 , V_121 , & V_119 ) ) {
F_5 ( L_31 ) ;
V_76 = - 1 ;
goto V_111;
}
}
if ( ! F_64 ( & V_58 -> V_64 ) )
F_65 ( V_89 ) ;
if ( V_88 )
F_66 ( V_89 ) ;
for (; ; ) {
int V_122 = V_12 -> V_35 ;
if ( F_41 ( V_12 ) < 0 ) {
V_76 = - 1 ;
goto V_111;
}
if ( V_122 == V_12 -> V_35 ) {
if ( V_41 )
break;
V_76 = F_67 ( V_89 -> V_123 , V_89 -> V_124 , - 1 ) ;
V_87 ++ ;
}
if ( V_41 && ! V_91 && ! F_64 ( & V_58 -> V_64 ) ) {
F_68 ( V_89 ) ;
V_91 = true ;
}
}
if ( V_125 || V_42 == V_49 )
return 0 ;
fprintf ( V_126 , L_32 , V_87 ) ;
fprintf ( V_126 ,
L_33 V_127 L_34 ,
( double ) V_12 -> V_14 / 1024.0 / 1024.0 ,
V_90 ,
V_12 -> V_14 / 24 ) ;
return 0 ;
V_111:
F_35 ( V_56 ) ;
return V_76 ;
}
static int
F_69 ( const struct V_128 * V_129 , const char * V_130 , int V_131 )
{
#define F_70 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
T_6 * V_132 = ( T_6 * ) V_129 -> V_133 ;
const struct V_134 * V_135 ;
char * V_136 , * V_137 = NULL , * V_138 ;
int V_16 = - 1 ;
if ( V_131 )
return 0 ;
if ( * V_132 )
return - 1 ;
if ( V_130 ) {
V_136 = V_137 = F_71 ( V_130 ) ;
if ( ! V_136 )
return - 1 ;
for (; ; ) {
V_138 = strchr ( V_136 , ',' ) ;
if ( V_138 )
* V_138 = '\0' ;
for ( V_135 = V_139 ; V_135 -> V_140 ; V_135 ++ ) {
if ( ! strcasecmp ( V_136 , V_135 -> V_140 ) )
break;
}
if ( ! V_135 -> V_140 ) {
F_23 ( L_35
L_36 , V_136 ) ;
goto error;
}
* V_132 |= V_135 -> V_132 ;
if ( ! V_138 )
break;
V_136 = V_138 + 1 ;
}
}
V_16 = 0 ;
if ( ( * V_132 & ~ F_70 ) == 0 ) {
* V_132 = V_141 ;
}
error:
free ( V_137 ) ;
return V_16 ;
}
static int F_72 ( char * V_130 , unsigned long * V_142 )
{
char * V_143 ;
unsigned long V_13 ;
unsigned long V_144 = F_73 ( V_145 , sizeof( T_5 ) ) ;
V_13 = strtoul ( V_130 , & V_143 , 0 ) ;
do {
if ( * V_143 )
break;
V_13 = F_74 ( V_13 , sizeof( T_5 ) ) ;
if ( ! V_13 || V_13 > V_144 )
break;
* V_142 = V_13 ;
return 0 ;
} while ( 0 );
F_5 ( L_37 ,
V_144 , V_130 ) ;
return - 1 ;
}
int F_75 ( const struct V_128 * V_129 ,
const char * V_2 , int V_131 )
{
struct V_57 * V_58 = V_129 -> V_133 ;
char * V_146 , * V_140 , * V_147 = NULL ;
char * V_15 ;
int V_16 = - 1 ;
if ( V_131 )
return 0 ;
F_76 ( ! V_2 ) ;
V_15 = malloc ( strlen ( V_2 ) + 1 ) ;
if ( ! V_15 )
return - V_5 ;
strcpy ( V_15 , V_2 ) ;
V_146 = strtok_r ( ( char * ) V_15 , L_38 , & V_147 ) ;
V_140 = V_146 ? : ( char * ) V_15 ;
do {
if ( ! strncmp ( V_140 , L_39 , sizeof( L_39 ) ) ) {
if ( ! strtok_r ( NULL , L_38 , & V_147 ) ) {
V_58 -> V_148 = V_149 ;
V_16 = 0 ;
} else
F_5 ( L_40
L_41 ) ;
break;
#ifdef F_77
} else if ( ! strncmp ( V_140 , L_42 , sizeof( L_42 ) ) ) {
const unsigned long V_150 = 8192 ;
V_16 = 0 ;
V_58 -> V_148 = V_151 ;
V_58 -> V_152 = V_150 ;
V_146 = strtok_r ( NULL , L_38 , & V_147 ) ;
if ( V_146 ) {
unsigned long V_13 = 0 ;
V_16 = F_72 ( V_146 , & V_13 ) ;
V_58 -> V_152 = V_13 ;
}
if ( ! V_16 )
F_78 ( L_43 ,
V_58 -> V_152 ) ;
#endif
} else {
F_5 ( L_44
L_45 , V_2 ) ;
break;
}
} while ( 0 );
free ( V_15 ) ;
if ( ! V_16 )
F_78 ( L_46 , V_58 -> V_148 ) ;
return V_16 ;
}
int F_79 ( int V_81 , const char * * V_82 , const char * T_7 V_23 )
{
int V_76 = - V_5 ;
struct V_52 * V_53 ;
struct V_54 * V_89 ;
struct V_11 * V_12 = & V_153 ;
char V_154 [ V_155 ] ;
V_89 = F_80 () ;
if ( V_89 == NULL )
return - V_5 ;
V_12 -> V_44 = V_89 ;
V_81 = F_81 ( V_81 , V_82 , V_156 , V_157 ,
V_158 ) ;
if ( ! V_81 && F_64 ( & V_12 -> V_58 . V_64 ) )
F_82 ( V_157 , V_156 ) ;
if ( V_159 && ! V_12 -> V_58 . V_64 . V_160 ) {
F_25 ( L_47
L_48 ) ;
F_82 ( V_157 , V_156 ) ;
}
F_83 () ;
if ( V_161 . V_162 )
F_84 (
L_49
L_50
L_51
L_52
L_53
L_54
L_55 ) ;
if ( V_12 -> V_163 || V_12 -> V_75 )
F_85 () ;
if ( V_89 -> V_164 == 0 &&
F_86 ( V_89 ) < 0 ) {
F_5 ( L_56 ) ;
goto V_165;
}
V_76 = F_87 ( & V_12 -> V_58 . V_64 ) ;
if ( V_76 ) {
F_88 ( & V_12 -> V_58 . V_64 , V_76 , V_154 , V_155 ) ;
F_23 ( L_57 , V_154 ) ;
}
V_76 = F_89 ( & V_12 -> V_58 . V_64 ) ;
if ( V_76 ) {
int V_166 = V_62 ;
F_88 ( & V_12 -> V_58 . V_64 , V_76 , V_154 , V_155 ) ;
F_25 ( L_57 , V_154 ) ;
V_76 = - V_166 ;
goto V_165;
}
V_76 = - V_5 ;
if ( F_90 ( V_89 , & V_12 -> V_58 . V_64 ) < 0 )
F_82 ( V_157 , V_156 ) ;
F_20 (pos, &evsel_list->entries, node) {
if ( F_91 ( V_53 -> V_167 . V_168 , F_92 ( V_53 ) ) )
goto V_169;
}
if ( V_12 -> V_58 . V_170 != V_171 )
V_12 -> V_58 . V_172 = V_12 -> V_58 . V_170 ;
if ( V_12 -> V_58 . V_173 != V_67 )
V_12 -> V_58 . V_174 = V_12 -> V_58 . V_173 ;
if ( V_12 -> V_58 . V_172 )
V_12 -> V_58 . V_174 = 0 ;
else if ( V_12 -> V_58 . V_174 ) {
V_12 -> V_58 . V_172 = V_12 -> V_58 . V_174 ;
} else {
F_25 ( L_58 ) ;
V_76 = - V_68 ;
goto V_169;
}
V_76 = F_43 ( & V_153 , V_81 , V_82 ) ;
F_93 ( V_89 ) ;
F_94 ( V_89 ) ;
V_169:
F_95 ( V_89 ) ;
V_165:
F_37 () ;
return V_76 ;
}
