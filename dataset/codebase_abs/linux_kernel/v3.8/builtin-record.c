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
struct V_53 * V_54 ;
struct V_51 * V_44 = V_12 -> V_44 ;
struct V_58 * V_59 = V_12 -> V_59 ;
struct V_60 * V_61 = & V_12 -> V_61 ;
int V_34 = 0 ;
if ( V_61 -> V_62 )
F_24 ( V_44 ) ;
F_25 ( V_44 , V_61 ) ;
F_21 (pos, &evlist->entries, node) {
struct V_63 * V_57 = & V_54 -> V_57 ;
bool V_64 = V_57 -> V_65 & V_66 ;
V_67:
if ( V_61 -> V_68 )
V_57 -> V_69 = V_57 -> V_70 = 0 ;
V_71:
V_57 -> V_72 = V_61 -> V_73 ? 0 : 1 ;
V_74:
if ( F_26 ( V_54 , V_44 -> V_75 , V_44 -> V_76 ) < 0 ) {
int V_77 = V_78 ;
if ( V_77 == V_79 || V_77 == V_80 ) {
F_27 () ;
V_34 = - V_77 ;
goto V_37;
} else if ( V_77 == V_81 && V_61 -> V_82 . V_83 ) {
F_5 ( L_2
L_3 ) ;
V_34 = - V_77 ;
goto V_37;
} else if ( V_77 == V_84 ) {
if ( ! V_61 -> V_68 &&
( V_57 -> V_69 || V_57 -> V_70 ) ) {
F_28 ( L_4
L_5 ) ;
V_61 -> V_68 = true ;
goto V_67;
} else if ( ! V_61 -> V_73 ) {
V_61 -> V_73 = true ;
if ( ! V_61 -> V_85 && ! V_61 -> V_86 && ! V_64 )
V_57 -> V_65 &= ~ V_66 ;
goto V_71;
}
}
if ( ( V_77 == V_87 || V_77 == V_88 )
&& V_57 -> type == V_89
&& V_57 -> V_90 == V_91 ) {
if ( V_92 )
F_29 ( L_6
L_7 ) ;
V_57 -> type = V_93 ;
V_57 -> V_90 = V_94 ;
if ( V_54 -> V_95 ) {
free ( V_54 -> V_95 ) ;
V_54 -> V_95 = NULL ;
}
goto V_74;
}
if ( V_77 == V_87 ) {
F_30 ( L_8 ,
F_31 ( V_54 ) ) ;
V_34 = - V_77 ;
goto V_37;
} else if ( ( V_77 == V_96 ) && ( V_57 -> V_97 ) ) {
F_30 ( L_9
L_10 ) ;
V_34 = - V_77 ;
goto V_37;
}
printf ( L_11 ) ;
error ( L_12
L_13
L_14 ,
V_77 , strerror ( V_77 ) , F_31 ( V_54 ) ) ;
#if F_32 ( V_98 ) || F_32 ( V_99 )
if ( V_57 -> type == V_89 &&
V_77 == V_96 ) {
F_5 ( L_15
L_16
L_17
L_18 ) ;
V_34 = - V_77 ;
goto V_37;
}
#endif
F_5 ( L_19 ) ;
V_34 = - V_77 ;
goto V_37;
}
}
if ( F_33 ( V_44 ) ) {
error ( L_20 , V_78 ,
strerror ( V_78 ) ) ;
V_34 = - 1 ;
goto V_37;
}
if ( F_34 ( V_44 , V_61 -> V_100 , false ) < 0 ) {
if ( V_78 == V_79 ) {
F_5 ( L_21
L_22
L_23
L_24
L_25 , V_61 -> V_100 ) ;
V_34 = - V_78 ;
} else if ( ! F_35 ( V_61 -> V_100 ) &&
( V_61 -> V_100 != V_101 ) ) {
F_5 ( L_26 ) ;
V_34 = - V_84 ;
} else {
F_5 ( L_27 , V_78 , strerror ( V_78 ) ) ;
V_34 = - V_78 ;
}
goto V_37;
}
if ( V_12 -> V_102 )
V_59 -> V_44 = V_44 ;
else {
if ( ! F_19 ( V_59 -> V_44 , V_44 ) ) {
fprintf ( V_103 , L_28 ) ;
V_34 = - 1 ;
goto V_37;
}
}
F_36 ( V_59 ) ;
V_37:
return V_34 ;
}
static int F_37 ( struct V_11 * V_12 )
{
T_5 V_13 = F_38 ( V_12 -> V_17 , 0 , V_104 ) ;
if ( V_13 == 0 )
return 0 ;
V_12 -> V_59 -> V_105 = V_12 -> V_17 ;
return F_39 ( V_12 -> V_59 , V_12 -> V_106 ,
V_13 - V_12 -> V_106 ,
V_13 , & V_107 ) ;
}
static void F_40 ( int V_43 , void * V_2 )
{
struct V_11 * V_12 = V_2 ;
if ( V_43 != 0 )
return;
if ( ! V_12 -> V_61 . V_108 ) {
V_12 -> V_59 -> V_25 . V_109 += V_12 -> V_14 ;
if ( ! V_12 -> V_110 )
F_37 ( V_12 ) ;
F_41 ( V_12 -> V_59 , V_12 -> V_44 ,
V_12 -> V_17 , true ) ;
F_42 ( V_12 -> V_59 ) ;
F_43 ( V_12 -> V_44 ) ;
F_44 () ;
}
}
static void F_45 ( struct V_24 * V_24 , void * V_31 )
{
int V_77 ;
struct V_18 * V_19 = V_31 ;
if ( F_46 ( V_24 ) )
return;
V_77 = F_47 ( V_19 , F_6 ,
V_24 ) ;
if ( V_77 < 0 )
F_5 ( L_29
L_30 , V_24 -> V_46 ) ;
V_77 = F_48 ( V_19 , F_6 ,
V_24 , L_31 ) ;
if ( V_77 < 0 )
V_77 = F_48 ( V_19 , F_6 ,
V_24 , L_32 ) ;
if ( V_77 < 0 )
F_5 ( L_29
L_30 , V_24 -> V_46 ) ;
}
static int F_49 ( struct V_11 * V_12 )
{
int V_9 ;
int V_34 = 0 ;
for ( V_9 = 0 ; V_9 < V_12 -> V_44 -> V_111 ; V_9 ++ ) {
if ( V_12 -> V_44 -> V_112 [ V_9 ] . V_32 ) {
if ( F_8 ( V_12 , & V_12 -> V_44 -> V_112 [ V_9 ] ) != 0 ) {
V_34 = - 1 ;
goto V_37;
}
}
}
if ( F_50 ( & V_12 -> V_59 -> V_25 , V_113 ) )
V_34 = F_3 ( V_12 , & V_114 ,
sizeof( V_114 ) ) ;
V_37:
return V_34 ;
}
static int F_51 ( struct V_11 * V_12 , int V_115 , const char * * V_116 )
{
struct V_117 V_118 ;
int V_119 ;
int V_77 , V_17 , V_120 ;
unsigned long V_121 = 0 ;
const bool V_122 = V_115 > 0 ;
struct V_24 * V_24 ;
struct V_18 * V_19 = & V_12 -> V_19 ;
struct V_60 * V_61 = & V_12 -> V_61 ;
struct V_51 * V_123 = V_12 -> V_44 ;
const char * V_124 = V_12 -> V_124 ;
struct V_58 * V_59 ;
bool V_125 = false ;
V_12 -> V_48 = V_116 [ 0 ] ;
V_12 -> V_33 = F_52 ( V_126 ) ;
F_1 ( F_12 , V_12 ) ;
signal ( V_39 , F_11 ) ;
signal ( V_127 , F_11 ) ;
signal ( V_49 , F_11 ) ;
if ( ! V_124 ) {
if ( ! F_53 ( V_128 , & V_118 ) && F_54 ( V_118 . V_129 ) )
V_61 -> V_108 = true ;
else
V_12 -> V_124 = V_124 = L_33 ;
}
if ( V_124 ) {
if ( ! strcmp ( V_124 , L_34 ) )
V_61 -> V_108 = true ;
else if ( ! V_117 ( V_124 , & V_118 ) && V_118 . V_130 ) {
if ( V_12 -> V_131 == V_132 ) {
char V_133 [ V_134 ] ;
snprintf ( V_133 , sizeof( V_133 ) , L_35 ,
V_124 ) ;
F_55 ( V_133 ) ;
rename ( V_124 , V_133 ) ;
}
} else if ( V_12 -> V_131 == V_135 ) {
V_12 -> V_131 = V_132 ;
}
}
V_119 = V_136 | V_137 ;
if ( V_12 -> V_131 == V_135 )
V_12 -> V_102 = 0 ;
else
V_119 |= V_138 ;
if ( V_61 -> V_108 )
V_17 = V_128 ;
else
V_17 = F_56 ( V_124 , V_119 , V_139 | V_140 ) ;
if ( V_17 < 0 ) {
perror ( L_36 ) ;
return - 1 ;
}
V_12 -> V_17 = V_17 ;
V_59 = F_57 ( V_124 , V_141 ,
V_12 -> V_131 == V_132 , false , NULL ) ;
if ( V_59 == NULL ) {
F_5 ( L_37 ) ;
return - 1 ;
}
V_12 -> V_59 = V_59 ;
for ( V_120 = V_142 ; V_120 < V_143 ; V_120 ++ )
F_58 ( & V_59 -> V_25 , V_120 ) ;
if ( V_12 -> V_110 )
F_59 ( & V_59 -> V_25 , V_144 ) ;
if ( ! F_60 ( & V_123 -> V_145 ) )
F_59 ( & V_59 -> V_25 , V_113 ) ;
if ( ! V_12 -> V_61 . V_146 )
F_59 ( & V_59 -> V_25 , V_147 ) ;
if ( ! V_12 -> V_102 ) {
V_77 = F_61 ( V_59 , V_17 ) ;
if ( V_77 < 0 )
goto V_148;
}
if ( V_122 ) {
V_77 = F_62 ( V_123 , V_61 , V_116 ) ;
if ( V_77 < 0 ) {
F_5 ( L_38 ) ;
goto V_148;
}
}
if ( F_23 ( V_12 ) != 0 ) {
V_77 = - 1 ;
goto V_148;
}
F_1 ( F_40 , V_12 ) ;
if ( V_61 -> V_108 ) {
V_77 = F_63 ( V_17 ) ;
if ( V_77 < 0 )
goto V_148;
} else if ( V_12 -> V_102 ) {
V_77 = F_41 ( V_59 , V_123 ,
V_17 , false ) ;
if ( V_77 < 0 )
goto V_148;
}
if ( ! V_12 -> V_110
&& ! F_50 ( & V_59 -> V_25 , V_144 ) ) {
F_5 ( L_39
L_40 ) ;
V_77 = - 1 ;
goto V_148;
}
V_12 -> V_106 = F_38 ( V_17 , 0 , V_104 ) ;
V_24 = F_64 ( V_59 ) ;
if ( ! V_24 ) {
F_5 ( L_41 ) ;
V_77 = - 1 ;
goto V_148;
}
if ( V_61 -> V_108 ) {
V_77 = F_65 ( V_19 , V_59 ,
F_6 ) ;
if ( V_77 < 0 ) {
F_5 ( L_42 ) ;
goto V_148;
}
V_77 = F_66 ( V_19 , F_6 ,
V_24 ) ;
if ( V_77 < 0 ) {
F_5 ( L_43 ) ;
goto V_148;
}
if ( F_60 ( & V_123 -> V_145 ) ) {
V_77 = F_67 ( V_19 , V_17 , V_123 ,
F_6 ) ;
if ( V_77 <= 0 ) {
F_5 ( L_44 ) ;
goto V_148;
}
F_2 ( V_12 , V_77 ) ;
}
}
V_77 = F_48 ( V_19 , F_6 ,
V_24 , L_31 ) ;
if ( V_77 < 0 )
V_77 = F_48 ( V_19 , F_6 ,
V_24 , L_32 ) ;
if ( V_77 < 0 )
F_5 ( L_45
L_46
L_47 ) ;
V_77 = F_47 ( V_19 , F_6 ,
V_24 ) ;
if ( V_77 < 0 )
F_5 ( L_48
L_46
L_49 ) ;
if ( V_149 )
F_68 ( V_59 , V_19 ,
F_45 ) ;
if ( ! V_61 -> V_82 . V_150 )
V_77 = F_69 ( V_19 , V_123 -> V_76 ,
F_6 ,
V_24 ) ;
else
V_77 = F_70 ( V_19 , F_6 ,
V_24 ) ;
if ( V_77 != 0 )
goto V_148;
if ( V_12 -> V_151 ) {
struct V_152 V_153 ;
V_153 . V_154 = V_12 -> V_151 ;
if ( F_71 ( 0 , V_155 , & V_153 ) ) {
F_5 ( L_50 ) ;
V_77 = - 1 ;
goto V_148;
}
}
if ( ! F_72 ( & V_61 -> V_82 ) )
F_73 ( V_123 ) ;
if ( V_122 )
F_74 ( V_123 ) ;
for (; ; ) {
int V_156 = V_12 -> V_35 ;
if ( F_49 ( V_12 ) < 0 ) {
V_77 = - 1 ;
goto V_148;
}
if ( V_156 == V_12 -> V_35 ) {
if ( V_41 )
break;
V_77 = F_75 ( V_123 -> V_157 , V_123 -> V_158 , - 1 ) ;
V_121 ++ ;
}
if ( V_41 && ! V_125 && ! F_72 ( & V_61 -> V_82 ) ) {
F_76 ( V_123 ) ;
V_125 = true ;
}
}
if ( V_159 || V_42 == V_49 )
return 0 ;
fprintf ( V_103 , L_51 , V_121 ) ;
fprintf ( V_103 ,
L_52 V_160 L_53 ,
( double ) V_12 -> V_14 / 1024.0 / 1024.0 ,
V_124 ,
V_12 -> V_14 / 24 ) ;
return 0 ;
V_148:
F_42 ( V_59 ) ;
return V_77 ;
}
static int
F_77 ( const struct V_161 * V_162 , const char * V_163 , int V_164 )
{
#define F_78 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
T_6 * V_165 = ( T_6 * ) V_162 -> V_166 ;
const struct V_167 * V_168 ;
char * V_169 , * V_170 = NULL , * V_171 ;
int V_16 = - 1 ;
if ( V_164 )
return 0 ;
if ( * V_165 )
return - 1 ;
if ( V_163 ) {
V_169 = V_170 = F_79 ( V_163 ) ;
if ( ! V_169 )
return - 1 ;
for (; ; ) {
V_171 = strchr ( V_169 , ',' ) ;
if ( V_171 )
* V_171 = '\0' ;
for ( V_168 = V_172 ; V_168 -> V_95 ; V_168 ++ ) {
if ( ! strcasecmp ( V_169 , V_168 -> V_95 ) )
break;
}
if ( ! V_168 -> V_95 ) {
F_29 ( L_54
L_55 , V_169 ) ;
goto error;
}
* V_165 |= V_168 -> V_165 ;
if ( ! V_171 )
break;
V_169 = V_171 + 1 ;
}
}
V_16 = 0 ;
if ( ( * V_165 & ~ F_78 ) == 0 ) {
* V_165 = V_173 ;
}
error:
free ( V_170 ) ;
return V_16 ;
}
static int F_80 ( char * V_163 , unsigned long * V_174 )
{
char * V_175 ;
unsigned long V_13 ;
unsigned long V_176 = F_81 ( V_177 , sizeof( T_5 ) ) ;
V_13 = strtoul ( V_163 , & V_175 , 0 ) ;
do {
if ( * V_175 )
break;
V_13 = F_82 ( V_13 , sizeof( T_5 ) ) ;
if ( ! V_13 || V_13 > V_176 )
break;
* V_174 = V_13 ;
return 0 ;
} while ( 0 );
F_5 ( L_56 ,
V_176 , V_163 ) ;
return - 1 ;
}
static int
F_83 ( const struct V_161 * V_162 V_23 , const char * V_2 ,
int V_164 )
{
struct V_11 * V_12 = (struct V_11 * ) V_162 -> V_166 ;
char * V_178 , * V_95 , * V_179 = NULL ;
char * V_15 ;
int V_16 = - 1 ;
if ( V_164 )
return 0 ;
F_84 ( ! V_2 ) ;
V_15 = malloc ( strlen ( V_2 ) + 1 ) ;
if ( ! V_15 )
return - V_5 ;
strcpy ( V_15 , V_2 ) ;
V_178 = strtok_r ( ( char * ) V_15 , L_57 , & V_179 ) ;
V_95 = V_178 ? : ( char * ) V_15 ;
do {
if ( ! strncmp ( V_95 , L_58 , sizeof( L_58 ) ) ) {
if ( ! strtok_r ( NULL , L_57 , & V_179 ) ) {
V_12 -> V_61 . V_180 = V_181 ;
V_16 = 0 ;
} else
F_5 ( L_59
L_60 ) ;
break;
#ifdef F_85
} else if ( ! strncmp ( V_95 , L_61 , sizeof( L_61 ) ) ) {
const unsigned long V_182 = 8192 ;
V_16 = 0 ;
V_12 -> V_61 . V_180 = V_183 ;
V_12 -> V_61 . V_184 = V_182 ;
V_178 = strtok_r ( NULL , L_57 , & V_179 ) ;
if ( V_178 ) {
unsigned long V_13 = 0 ;
V_16 = F_80 ( V_178 , & V_13 ) ;
V_12 -> V_61 . V_184 = V_13 ;
}
if ( ! V_16 )
F_28 ( L_62 ,
V_12 -> V_61 . V_184 ) ;
#endif
} else {
F_5 ( L_63
L_64 , V_2 ) ;
break;
}
} while ( 0 );
free ( V_15 ) ;
if ( ! V_16 )
F_28 ( L_65 , V_12 -> V_61 . V_180 ) ;
return V_16 ;
}
int F_86 ( int V_115 , const char * * V_116 , const char * T_7 V_23 )
{
int V_77 = - V_5 ;
struct V_53 * V_54 ;
struct V_51 * V_123 ;
struct V_11 * V_12 = & V_185 ;
char V_186 [ V_187 ] ;
V_123 = F_87 ( NULL , NULL ) ;
if ( V_123 == NULL )
return - V_5 ;
V_12 -> V_44 = V_123 ;
V_115 = F_88 ( V_115 , V_116 , V_188 , V_189 ,
V_190 ) ;
if ( ! V_115 && F_72 ( & V_12 -> V_61 . V_82 ) )
F_89 ( V_189 , V_188 ) ;
if ( V_12 -> V_191 && V_12 -> V_192 ) {
F_30 ( L_66
L_67 ) ;
F_89 ( V_189 , V_188 ) ;
} else if ( V_12 -> V_192 ) {
V_12 -> V_131 = V_135 ;
} else {
V_12 -> V_131 = V_132 ;
}
if ( V_193 && ! V_12 -> V_61 . V_82 . V_150 ) {
F_30 ( L_68
L_69 ) ;
F_89 ( V_189 , V_188 ) ;
}
F_90 () ;
if ( V_194 . V_195 )
F_91 (
L_70
L_71
L_72
L_73
L_74
L_75
L_76 ) ;
if ( V_12 -> V_196 || V_12 -> V_110 )
F_92 () ;
if ( V_123 -> V_56 == 0 &&
F_93 ( V_123 ) < 0 ) {
F_5 ( L_77 ) ;
goto V_197;
}
V_77 = F_94 ( & V_12 -> V_61 . V_82 ) ;
if ( V_77 ) {
F_95 ( & V_12 -> V_61 . V_82 , V_77 , V_186 , V_187 ) ;
F_29 ( L_78 , V_186 ) ;
}
V_77 = F_96 ( & V_12 -> V_61 . V_82 ) ;
if ( V_77 ) {
int V_198 = V_78 ;
F_95 ( & V_12 -> V_61 . V_82 , V_77 , V_186 , V_187 ) ;
F_30 ( L_78 , V_186 ) ;
V_77 = - V_198 ;
goto V_199;
}
V_77 = - V_5 ;
if ( F_97 ( V_123 , & V_12 -> V_61 . V_82 ) < 0 )
F_89 ( V_189 , V_188 ) ;
F_21 (pos, &evsel_list->entries, node) {
if ( F_98 ( V_54 -> V_57 . V_90 , F_31 ( V_54 ) ) )
goto V_199;
}
if ( V_12 -> V_61 . V_200 != V_201 )
V_12 -> V_61 . V_202 = V_12 -> V_61 . V_200 ;
if ( V_12 -> V_61 . V_203 != V_101 )
V_12 -> V_61 . V_204 = V_12 -> V_61 . V_203 ;
if ( V_12 -> V_61 . V_202 )
V_12 -> V_61 . V_204 = 0 ;
else if ( V_12 -> V_61 . V_204 ) {
V_12 -> V_61 . V_202 = V_12 -> V_61 . V_204 ;
} else {
F_30 ( L_79 ) ;
V_77 = - V_84 ;
goto V_199;
}
V_77 = F_51 ( & V_185 , V_115 , V_116 ) ;
V_199:
F_99 ( V_123 ) ;
V_197:
F_44 () ;
return V_77 ;
}
