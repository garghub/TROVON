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
F_13 ( F_18 () , V_42 ) ;
}
static bool F_19 ( struct V_51 * V_44 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 , * V_55 ;
if ( V_44 -> V_56 != V_52 -> V_56 )
return false ;
V_55 = F_20 ( V_52 ) ;
F_21 (pos, &evlist->entries, node) {
if ( memcmp ( & V_54 -> V_57 , & V_55 -> V_57 , sizeof( V_54 -> V_57 ) != 0 ) )
return false ;
V_55 = F_22 ( V_55 ) ;
}
return true ;
}
static int F_23 ( struct V_11 * V_12 )
{
char V_58 [ 512 ] ;
struct V_53 * V_54 ;
struct V_51 * V_44 = V_12 -> V_44 ;
struct V_59 * V_60 = V_12 -> V_60 ;
struct V_61 * V_62 = & V_12 -> V_62 ;
int V_34 = 0 ;
F_24 ( V_44 , V_62 ) ;
F_21 (pos, &evlist->entries, node) {
V_63:
if ( F_25 ( V_54 , V_44 -> V_64 , V_44 -> V_65 ) < 0 ) {
if ( F_26 ( V_54 , V_66 , V_58 , sizeof( V_58 ) ) ) {
if ( V_67 )
F_27 ( L_2 , V_58 ) ;
goto V_63;
}
V_34 = - V_66 ;
F_28 ( V_54 , & V_62 -> V_68 ,
V_66 , V_58 , sizeof( V_58 ) ) ;
F_29 ( L_2 , V_58 ) ;
goto V_37;
}
}
if ( F_30 ( V_44 ) ) {
error ( L_3 , V_66 ,
strerror ( V_66 ) ) ;
V_34 = - 1 ;
goto V_37;
}
if ( F_31 ( V_44 , V_62 -> V_69 , false ) < 0 ) {
if ( V_66 == V_70 ) {
F_5 ( L_4
L_5
L_6
L_7
L_8 , V_62 -> V_69 ) ;
V_34 = - V_66 ;
} else if ( ! F_32 ( V_62 -> V_69 ) &&
( V_62 -> V_69 != V_71 ) ) {
F_5 ( L_9 ) ;
V_34 = - V_72 ;
} else {
F_5 ( L_10 , V_66 , strerror ( V_66 ) ) ;
V_34 = - V_66 ;
}
goto V_37;
}
if ( V_12 -> V_73 )
V_60 -> V_44 = V_44 ;
else {
if ( ! F_19 ( V_60 -> V_44 , V_44 ) ) {
fprintf ( V_74 , L_11 ) ;
V_34 = - 1 ;
goto V_37;
}
}
F_33 ( V_60 ) ;
V_37:
return V_34 ;
}
static int F_34 ( struct V_11 * V_12 )
{
T_5 V_13 = F_35 ( V_12 -> V_17 , 0 , V_75 ) ;
if ( V_13 == 0 )
return 0 ;
V_12 -> V_60 -> V_76 = V_12 -> V_17 ;
return F_36 ( V_12 -> V_60 , V_12 -> V_77 ,
V_13 - V_12 -> V_77 ,
V_13 , & V_78 ) ;
}
static void F_37 ( int V_43 , void * V_2 )
{
struct V_11 * V_12 = V_2 ;
if ( V_43 != 0 )
return;
if ( ! V_12 -> V_62 . V_79 ) {
V_12 -> V_60 -> V_25 . V_80 += V_12 -> V_14 ;
if ( ! V_12 -> V_81 )
F_34 ( V_12 ) ;
F_38 ( V_12 -> V_60 , V_12 -> V_44 ,
V_12 -> V_17 , true ) ;
F_39 ( V_12 -> V_60 ) ;
F_40 ( V_12 -> V_44 ) ;
F_41 () ;
}
}
static void F_42 ( struct V_24 * V_24 , void * V_31 )
{
int V_82 ;
struct V_18 * V_19 = V_31 ;
V_82 = F_43 ( V_19 , F_6 ,
V_24 ) ;
if ( V_82 < 0 )
F_5 ( L_12
L_13 , V_24 -> V_46 ) ;
V_82 = F_44 ( V_19 , F_6 ,
V_24 , L_14 ) ;
if ( V_82 < 0 )
V_82 = F_44 ( V_19 , F_6 ,
V_24 , L_15 ) ;
if ( V_82 < 0 )
F_5 ( L_12
L_13 , V_24 -> V_46 ) ;
}
static int F_45 ( struct V_11 * V_12 )
{
int V_9 ;
int V_34 = 0 ;
for ( V_9 = 0 ; V_9 < V_12 -> V_44 -> V_83 ; V_9 ++ ) {
if ( V_12 -> V_44 -> V_84 [ V_9 ] . V_32 ) {
if ( F_8 ( V_12 , & V_12 -> V_44 -> V_84 [ V_9 ] ) != 0 ) {
V_34 = - 1 ;
goto V_37;
}
}
}
if ( F_46 ( & V_12 -> V_60 -> V_25 , V_85 ) )
V_34 = F_3 ( V_12 , & V_86 ,
sizeof( V_86 ) ) ;
V_37:
return V_34 ;
}
static int F_47 ( struct V_11 * V_12 , int V_87 , const char * * V_88 )
{
struct V_89 V_90 ;
int V_91 ;
int V_82 , V_17 , V_92 ;
unsigned long V_93 = 0 ;
const bool V_94 = V_87 > 0 ;
struct V_24 * V_24 ;
struct V_18 * V_19 = & V_12 -> V_19 ;
struct V_61 * V_62 = & V_12 -> V_62 ;
struct V_51 * V_95 = V_12 -> V_44 ;
const char * V_96 = V_12 -> V_96 ;
struct V_59 * V_60 ;
bool V_97 = false ;
V_12 -> V_48 = V_88 [ 0 ] ;
V_12 -> V_33 = F_48 ( V_98 ) ;
F_1 ( F_12 , V_12 ) ;
signal ( V_39 , F_11 ) ;
signal ( V_99 , F_11 ) ;
signal ( V_49 , F_11 ) ;
if ( ! V_96 ) {
if ( ! F_49 ( V_100 , & V_90 ) && F_50 ( V_90 . V_101 ) )
V_62 -> V_79 = true ;
else
V_12 -> V_96 = V_96 = L_16 ;
}
if ( V_96 ) {
if ( ! strcmp ( V_96 , L_17 ) )
V_62 -> V_79 = true ;
else if ( ! V_89 ( V_96 , & V_90 ) && V_90 . V_102 ) {
if ( V_12 -> V_103 == V_104 ) {
char V_105 [ V_106 ] ;
snprintf ( V_105 , sizeof( V_105 ) , L_18 ,
V_96 ) ;
F_51 ( V_105 ) ;
rename ( V_96 , V_105 ) ;
}
} else if ( V_12 -> V_103 == V_107 ) {
V_12 -> V_103 = V_104 ;
}
}
V_91 = V_108 | V_109 ;
if ( V_12 -> V_103 == V_107 )
V_12 -> V_73 = 0 ;
else
V_91 |= V_110 ;
if ( V_62 -> V_79 )
V_17 = V_100 ;
else
V_17 = F_52 ( V_96 , V_91 , V_111 | V_112 ) ;
if ( V_17 < 0 ) {
perror ( L_19 ) ;
return - 1 ;
}
V_12 -> V_17 = V_17 ;
V_60 = F_53 ( V_96 , V_113 ,
V_12 -> V_103 == V_104 , false , NULL ) ;
if ( V_60 == NULL ) {
F_5 ( L_20 ) ;
return - 1 ;
}
V_12 -> V_60 = V_60 ;
for ( V_92 = V_114 ; V_92 < V_115 ; V_92 ++ )
F_54 ( & V_60 -> V_25 , V_92 ) ;
if ( V_12 -> V_81 )
F_55 ( & V_60 -> V_25 , V_116 ) ;
if ( ! F_56 ( & V_95 -> V_117 ) )
F_55 ( & V_60 -> V_25 , V_85 ) ;
if ( ! V_12 -> V_62 . V_118 )
F_55 ( & V_60 -> V_25 , V_119 ) ;
if ( ! V_12 -> V_73 ) {
V_82 = F_57 ( V_60 , V_17 ) ;
if ( V_82 < 0 )
goto V_120;
}
if ( V_94 ) {
V_82 = F_58 ( V_95 , & V_62 -> V_68 ,
V_88 , V_62 -> V_79 ,
true ) ;
if ( V_82 < 0 ) {
F_5 ( L_21 ) ;
goto V_120;
}
}
if ( F_23 ( V_12 ) != 0 ) {
V_82 = - 1 ;
goto V_120;
}
if ( ! V_95 -> V_121 )
F_55 ( & V_60 -> V_25 , V_122 ) ;
F_1 ( F_37 , V_12 ) ;
if ( V_62 -> V_79 ) {
V_82 = F_59 ( V_17 ) ;
if ( V_82 < 0 )
goto V_120;
} else if ( V_12 -> V_73 ) {
V_82 = F_38 ( V_60 , V_95 ,
V_17 , false ) ;
if ( V_82 < 0 )
goto V_120;
}
if ( ! V_12 -> V_81
&& ! F_46 ( & V_60 -> V_25 , V_116 ) ) {
F_5 ( L_22
L_23 ) ;
V_82 = - 1 ;
goto V_120;
}
V_12 -> V_77 = F_35 ( V_17 , 0 , V_75 ) ;
V_24 = & V_60 -> V_123 . V_124 ;
if ( V_62 -> V_79 ) {
V_82 = F_60 ( V_19 , V_60 ,
F_6 ) ;
if ( V_82 < 0 ) {
F_5 ( L_24 ) ;
goto V_120;
}
V_82 = F_61 ( V_19 , F_6 ,
V_24 ) ;
if ( V_82 < 0 ) {
F_5 ( L_25 ) ;
goto V_120;
}
if ( F_56 ( & V_95 -> V_117 ) ) {
V_82 = F_62 ( V_19 , V_17 , V_95 ,
F_6 ) ;
if ( V_82 <= 0 ) {
F_5 ( L_26 ) ;
goto V_120;
}
F_2 ( V_12 , V_82 ) ;
}
}
V_82 = F_44 ( V_19 , F_6 ,
V_24 , L_14 ) ;
if ( V_82 < 0 )
V_82 = F_44 ( V_19 , F_6 ,
V_24 , L_15 ) ;
if ( V_82 < 0 )
F_5 ( L_27
L_28
L_29 ) ;
V_82 = F_43 ( V_19 , F_6 ,
V_24 ) ;
if ( V_82 < 0 )
F_5 ( L_30
L_28
L_31 ) ;
if ( V_125 ) {
F_63 ( & V_60 -> V_123 ,
F_42 , V_19 ) ;
}
if ( F_64 ( & V_62 -> V_68 ) )
V_82 = F_65 ( V_19 , V_95 -> V_65 ,
F_6 ,
V_24 ) ;
else if ( F_66 ( & V_62 -> V_68 ) )
V_82 = F_67 ( V_19 , F_6 ,
V_24 ) ;
else
V_82 = 0 ;
if ( V_82 != 0 )
goto V_120;
if ( V_12 -> V_126 ) {
struct V_127 V_128 ;
V_128 . V_129 = V_12 -> V_126 ;
if ( F_68 ( 0 , V_130 , & V_128 ) ) {
F_5 ( L_32 ) ;
V_82 = - 1 ;
goto V_120;
}
}
if ( ! F_69 ( & V_62 -> V_68 ) )
F_70 ( V_95 ) ;
if ( V_94 )
F_71 ( V_95 ) ;
for (; ; ) {
int V_131 = V_12 -> V_35 ;
if ( F_45 ( V_12 ) < 0 ) {
V_82 = - 1 ;
goto V_120;
}
if ( V_131 == V_12 -> V_35 ) {
if ( V_41 )
break;
V_82 = F_72 ( V_95 -> V_132 , V_95 -> V_133 , - 1 ) ;
V_93 ++ ;
}
if ( V_41 && ! V_97 && ! F_69 ( & V_62 -> V_68 ) ) {
F_73 ( V_95 ) ;
V_97 = true ;
}
}
if ( V_134 || V_42 == V_49 )
return 0 ;
fprintf ( V_74 , L_33 , V_93 ) ;
fprintf ( V_74 ,
L_34 V_135 L_35 ,
( double ) V_12 -> V_14 / 1024.0 / 1024.0 ,
V_96 ,
V_12 -> V_14 / 24 ) ;
return 0 ;
V_120:
F_39 ( V_60 ) ;
return V_82 ;
}
static int
F_74 ( const struct V_136 * V_137 , const char * V_138 , int V_139 )
{
#define F_75 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
T_6 * V_140 = ( T_6 * ) V_137 -> V_141 ;
const struct V_142 * V_143 ;
char * V_144 , * V_145 = NULL , * V_146 ;
int V_16 = - 1 ;
if ( V_139 )
return 0 ;
if ( * V_140 )
return - 1 ;
if ( V_138 ) {
V_144 = V_145 = F_76 ( V_138 ) ;
if ( ! V_144 )
return - 1 ;
for (; ; ) {
V_146 = strchr ( V_144 , ',' ) ;
if ( V_146 )
* V_146 = '\0' ;
for ( V_143 = V_147 ; V_143 -> V_148 ; V_143 ++ ) {
if ( ! strcasecmp ( V_144 , V_143 -> V_148 ) )
break;
}
if ( ! V_143 -> V_148 ) {
F_27 ( L_36
L_37 , V_144 ) ;
goto error;
}
* V_140 |= V_143 -> V_140 ;
if ( ! V_146 )
break;
V_144 = V_146 + 1 ;
}
}
V_16 = 0 ;
if ( ( * V_140 & ~ F_75 ) == 0 ) {
* V_140 = V_149 ;
}
error:
free ( V_145 ) ;
return V_16 ;
}
static int F_77 ( char * V_138 , unsigned long * V_150 )
{
char * V_151 ;
unsigned long V_13 ;
unsigned long V_152 = F_78 ( V_153 , sizeof( T_5 ) ) ;
V_13 = strtoul ( V_138 , & V_151 , 0 ) ;
do {
if ( * V_151 )
break;
V_13 = F_79 ( V_13 , sizeof( T_5 ) ) ;
if ( ! V_13 || V_13 > V_152 )
break;
* V_150 = V_13 ;
return 0 ;
} while ( 0 );
F_5 ( L_38 ,
V_152 , V_138 ) ;
return - 1 ;
}
int F_80 ( const struct V_136 * V_137 ,
const char * V_2 , int V_139 )
{
struct V_61 * V_62 = V_137 -> V_141 ;
char * V_154 , * V_148 , * V_155 = NULL ;
char * V_15 ;
int V_16 = - 1 ;
if ( V_139 )
return 0 ;
F_81 ( ! V_2 ) ;
V_15 = malloc ( strlen ( V_2 ) + 1 ) ;
if ( ! V_15 )
return - V_5 ;
strcpy ( V_15 , V_2 ) ;
V_154 = strtok_r ( ( char * ) V_15 , L_39 , & V_155 ) ;
V_148 = V_154 ? : ( char * ) V_15 ;
do {
if ( ! strncmp ( V_148 , L_40 , sizeof( L_40 ) ) ) {
if ( ! strtok_r ( NULL , L_39 , & V_155 ) ) {
V_62 -> V_156 = V_157 ;
V_16 = 0 ;
} else
F_5 ( L_41
L_42 ) ;
break;
#ifdef F_82
} else if ( ! strncmp ( V_148 , L_43 , sizeof( L_43 ) ) ) {
const unsigned long V_158 = 8192 ;
V_16 = 0 ;
V_62 -> V_156 = V_159 ;
V_62 -> V_160 = V_158 ;
V_154 = strtok_r ( NULL , L_39 , & V_155 ) ;
if ( V_154 ) {
unsigned long V_13 = 0 ;
V_16 = F_77 ( V_154 , & V_13 ) ;
V_62 -> V_160 = V_13 ;
}
if ( ! V_16 )
F_83 ( L_44 ,
V_62 -> V_160 ) ;
#endif
} else {
F_5 ( L_45
L_46 , V_2 ) ;
break;
}
} while ( 0 );
free ( V_15 ) ;
if ( ! V_16 )
F_83 ( L_47 , V_62 -> V_156 ) ;
return V_16 ;
}
int F_84 ( int V_87 , const char * * V_88 , const char * T_7 V_23 )
{
int V_82 = - V_5 ;
struct V_53 * V_54 ;
struct V_51 * V_95 ;
struct V_11 * V_12 = & V_161 ;
char V_162 [ V_163 ] ;
V_95 = F_85 () ;
if ( V_95 == NULL )
return - V_5 ;
V_12 -> V_44 = V_95 ;
V_87 = F_86 ( V_87 , V_88 , V_164 , V_165 ,
V_166 ) ;
if ( ! V_87 && F_69 ( & V_12 -> V_62 . V_68 ) )
F_87 ( V_165 , V_164 ) ;
if ( V_12 -> V_167 && V_12 -> V_168 ) {
F_29 ( L_48
L_49 ) ;
F_87 ( V_165 , V_164 ) ;
} else if ( V_12 -> V_168 ) {
V_12 -> V_103 = V_107 ;
} else {
V_12 -> V_103 = V_104 ;
}
if ( V_169 && ! V_12 -> V_62 . V_68 . V_170 ) {
F_29 ( L_50
L_51 ) ;
F_87 ( V_165 , V_164 ) ;
}
F_88 () ;
if ( V_171 . V_172 )
F_89 (
L_52
L_53
L_54
L_55
L_56
L_57
L_58 ) ;
if ( V_12 -> V_173 || V_12 -> V_81 )
F_90 () ;
if ( V_95 -> V_56 == 0 &&
F_91 ( V_95 ) < 0 ) {
F_5 ( L_59 ) ;
goto V_174;
}
V_82 = F_92 ( & V_12 -> V_62 . V_68 ) ;
if ( V_82 ) {
F_93 ( & V_12 -> V_62 . V_68 , V_82 , V_162 , V_163 ) ;
F_27 ( L_60 , V_162 ) ;
}
V_82 = F_94 ( & V_12 -> V_62 . V_68 ) ;
if ( V_82 ) {
int V_175 = V_66 ;
F_93 ( & V_12 -> V_62 . V_68 , V_82 , V_162 , V_163 ) ;
F_29 ( L_60 , V_162 ) ;
V_82 = - V_175 ;
goto V_174;
}
V_82 = - V_5 ;
if ( F_95 ( V_95 , & V_12 -> V_62 . V_68 ) < 0 )
F_87 ( V_165 , V_164 ) ;
F_21 (pos, &evsel_list->entries, node) {
if ( F_96 ( V_54 -> V_57 . V_176 , F_97 ( V_54 ) ) )
goto V_177;
}
if ( V_12 -> V_62 . V_178 != V_179 )
V_12 -> V_62 . V_180 = V_12 -> V_62 . V_178 ;
if ( V_12 -> V_62 . V_181 != V_71 )
V_12 -> V_62 . V_182 = V_12 -> V_62 . V_181 ;
if ( V_12 -> V_62 . V_180 )
V_12 -> V_62 . V_182 = 0 ;
else if ( V_12 -> V_62 . V_182 ) {
V_12 -> V_62 . V_180 = V_12 -> V_62 . V_182 ;
} else {
F_29 ( L_61 ) ;
V_82 = - V_72 ;
goto V_177;
}
V_82 = F_47 ( & V_161 , V_87 , V_88 ) ;
F_98 ( V_95 ) ;
F_99 ( V_95 ) ;
V_177:
F_100 ( V_95 ) ;
V_174:
F_41 () ;
return V_82 ;
}
