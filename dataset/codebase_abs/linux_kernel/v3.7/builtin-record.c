static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 += V_3 ;
}
static int F_2 ( struct V_1 * V_2 , void * V_5 , T_1 V_3 )
{
while ( V_3 ) {
int V_6 = F_3 ( V_2 -> V_7 , V_5 , V_3 ) ;
if ( V_6 < 0 ) {
F_4 ( L_1 ) ;
return - 1 ;
}
V_3 -= V_6 ;
V_5 += V_6 ;
V_2 -> V_4 += V_6 ;
}
return 0 ;
}
static int F_5 ( struct V_8 * V_9 ,
union V_10 * V_11 ,
struct V_12 * T_2 V_13 ,
struct V_14 * V_14 V_13 )
{
struct V_1 * V_2 = F_6 ( V_9 , struct V_1 , V_9 ) ;
if ( F_2 ( V_2 , V_11 , V_11 -> V_15 . V_3 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
unsigned int V_18 = F_8 ( V_17 ) ;
unsigned int V_19 = V_17 -> V_20 ;
unsigned char * V_21 = V_17 -> V_22 + V_2 -> V_23 ;
unsigned long V_3 ;
void * V_5 ;
int V_24 = 0 ;
if ( V_19 == V_18 )
return 0 ;
V_2 -> V_25 ++ ;
V_3 = V_18 - V_19 ;
if ( ( V_19 & V_17 -> V_26 ) + V_3 != ( V_18 & V_17 -> V_26 ) ) {
V_5 = & V_21 [ V_19 & V_17 -> V_26 ] ;
V_3 = V_17 -> V_26 + 1 - ( V_19 & V_17 -> V_26 ) ;
V_19 += V_3 ;
if ( F_2 ( V_2 , V_5 , V_3 ) < 0 ) {
V_24 = - 1 ;
goto V_27;
}
}
V_5 = & V_21 [ V_19 & V_17 -> V_26 ] ;
V_3 = V_18 - V_19 ;
V_19 += V_3 ;
if ( F_2 ( V_2 , V_5 , V_3 ) < 0 ) {
V_24 = - 1 ;
goto V_27;
}
V_17 -> V_20 = V_19 ;
F_9 ( V_17 , V_19 ) ;
V_27:
return V_24 ;
}
static void F_10 ( int V_28 )
{
if ( V_28 == V_29 )
V_30 = 1 ;
V_31 = 1 ;
V_32 = V_28 ;
}
static void F_11 ( int T_3 V_13 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
int V_34 ;
if ( V_2 -> V_35 -> V_36 . V_37 > 0 ) {
if ( ! V_30 )
F_12 ( V_2 -> V_35 -> V_36 . V_37 , V_38 ) ;
F_13 ( & V_34 ) ;
if ( F_14 ( V_34 ) )
F_15 ( F_16 ( V_34 ) , V_2 -> V_39 ) ;
}
if ( V_32 == - 1 || V_32 == V_40 )
return;
signal ( V_32 , V_41 ) ;
F_12 ( F_17 () , V_32 ) ;
}
static bool F_18 ( struct V_42 * V_35 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 , * V_46 ;
if ( V_35 -> V_47 != V_43 -> V_47 )
return false ;
V_46 = F_19 ( V_43 ) ;
F_20 (pos, &evlist->entries, node) {
if ( memcmp ( & V_45 -> V_48 , & V_46 -> V_48 , sizeof( V_45 -> V_48 ) != 0 ) )
return false ;
V_46 = F_21 ( V_46 ) ;
}
return true ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
struct V_42 * V_35 = V_2 -> V_35 ;
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_51 * V_52 = & V_2 -> V_52 ;
int V_24 = 0 ;
F_23 ( V_35 , V_52 ) ;
if ( V_52 -> V_53 )
F_24 ( V_35 ) ;
F_20 (pos, &evlist->entries, node) {
struct V_54 * V_48 = & V_45 -> V_48 ;
bool V_55 = V_48 -> V_56 & V_57 ;
V_58:
if ( V_52 -> V_59 )
V_48 -> V_60 = V_48 -> V_61 = 0 ;
V_62:
V_48 -> V_63 = V_52 -> V_64 ? 0 : 1 ;
V_65:
if ( F_25 ( V_45 , V_35 -> V_66 , V_35 -> V_67 ) < 0 ) {
int V_68 = V_69 ;
if ( V_68 == V_70 || V_68 == V_71 ) {
F_26 () ;
V_24 = - V_68 ;
goto V_27;
} else if ( V_68 == V_72 && V_52 -> V_73 . V_74 ) {
F_4 ( L_2
L_3 ) ;
V_24 = - V_68 ;
goto V_27;
} else if ( V_68 == V_75 ) {
if ( ! V_52 -> V_59 &&
( V_48 -> V_60 || V_48 -> V_61 ) ) {
F_27 ( L_4
L_5 ) ;
V_52 -> V_59 = true ;
goto V_58;
} else if ( ! V_52 -> V_64 ) {
V_52 -> V_64 = true ;
if ( ! V_52 -> V_76 && ! V_52 -> V_77 && ! V_55 )
V_48 -> V_56 &= ~ V_57 ;
goto V_62;
}
}
if ( ( V_68 == V_78 || V_68 == V_79 )
&& V_48 -> type == V_80
&& V_48 -> V_81 == V_82 ) {
if ( V_83 )
F_28 ( L_6
L_7 ) ;
V_48 -> type = V_84 ;
V_48 -> V_81 = V_85 ;
if ( V_45 -> V_86 ) {
free ( V_45 -> V_86 ) ;
V_45 -> V_86 = NULL ;
}
goto V_65;
}
if ( V_68 == V_78 ) {
F_29 ( L_8 ,
F_30 ( V_45 ) ) ;
V_24 = - V_68 ;
goto V_27;
}
printf ( L_9 ) ;
error ( L_10
L_11
L_12 ,
V_68 , strerror ( V_68 ) , F_30 ( V_45 ) ) ;
#if F_31 ( V_87 ) || F_31 ( V_88 )
if ( V_48 -> type == V_80 &&
V_68 == V_89 ) {
F_4 ( L_13
L_14
L_15
L_16 ) ;
V_24 = - V_68 ;
goto V_27;
}
#endif
F_4 ( L_17 ) ;
V_24 = - V_68 ;
goto V_27;
}
}
if ( F_32 ( V_35 ) ) {
error ( L_18 , V_69 ,
strerror ( V_69 ) ) ;
V_24 = - 1 ;
goto V_27;
}
if ( F_33 ( V_35 , V_52 -> V_90 , false ) < 0 ) {
if ( V_69 == V_70 ) {
F_4 ( L_19
L_20
L_21
L_22
L_23 , V_52 -> V_90 ) ;
V_24 = - V_69 ;
} else if ( ! F_34 ( V_52 -> V_90 ) ) {
F_4 ( L_24 ) ;
V_24 = - V_75 ;
} else {
F_4 ( L_25 , V_69 , strerror ( V_69 ) ) ;
V_24 = - V_69 ;
}
goto V_27;
}
if ( V_2 -> V_91 )
V_50 -> V_35 = V_35 ;
else {
if ( ! F_18 ( V_50 -> V_35 , V_35 ) ) {
fprintf ( V_92 , L_26 ) ;
V_24 = - 1 ;
goto V_27;
}
}
F_35 ( V_50 ) ;
V_27:
return V_24 ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_4 V_3 = F_37 ( V_2 -> V_7 , 0 , V_93 ) ;
if ( V_3 == 0 )
return 0 ;
V_2 -> V_50 -> V_94 = V_2 -> V_7 ;
return F_38 ( V_2 -> V_50 , V_2 -> V_95 ,
V_3 - V_2 -> V_95 ,
V_3 , & V_96 ) ;
}
static void F_39 ( int V_34 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
if ( V_34 != 0 )
return;
if ( ! V_2 -> V_52 . V_97 ) {
V_2 -> V_50 -> V_15 . V_98 += V_2 -> V_4 ;
if ( ! V_2 -> V_99 )
F_36 ( V_2 ) ;
F_40 ( V_2 -> V_50 , V_2 -> V_35 ,
V_2 -> V_7 , true ) ;
F_41 ( V_2 -> V_50 ) ;
F_42 ( V_2 -> V_35 ) ;
F_43 () ;
}
}
static void F_44 ( struct V_14 * V_14 , void * V_21 )
{
int V_68 ;
struct V_8 * V_9 = V_21 ;
if ( F_45 ( V_14 ) )
return;
V_68 = F_46 ( V_9 , F_5 ,
V_14 ) ;
if ( V_68 < 0 )
F_4 ( L_27
L_28 , V_14 -> V_37 ) ;
V_68 = F_47 ( V_9 , F_5 ,
V_14 , L_29 ) ;
if ( V_68 < 0 )
V_68 = F_47 ( V_9 , F_5 ,
V_14 , L_30 ) ;
if ( V_68 < 0 )
F_4 ( L_27
L_28 , V_14 -> V_37 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_100 ;
int V_24 = 0 ;
for ( V_100 = 0 ; V_100 < V_2 -> V_35 -> V_101 ; V_100 ++ ) {
if ( V_2 -> V_35 -> V_102 [ V_100 ] . V_22 ) {
if ( F_7 ( V_2 , & V_2 -> V_35 -> V_102 [ V_100 ] ) != 0 ) {
V_24 = - 1 ;
goto V_27;
}
}
}
if ( F_49 ( & V_2 -> V_50 -> V_15 , V_103 ) )
V_24 = F_2 ( V_2 , & V_104 ,
sizeof( V_104 ) ) ;
V_27:
return V_24 ;
}
static int F_50 ( struct V_1 * V_2 , int V_105 , const char * * V_106 )
{
struct V_107 V_108 ;
int V_109 ;
int V_68 , V_7 , V_110 ;
unsigned long V_111 = 0 ;
const bool V_112 = V_105 > 0 ;
struct V_14 * V_14 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_51 * V_52 = & V_2 -> V_52 ;
struct V_42 * V_113 = V_2 -> V_35 ;
const char * V_114 = V_2 -> V_114 ;
struct V_49 * V_50 ;
V_2 -> V_39 = V_106 [ 0 ] ;
V_2 -> V_23 = F_51 ( V_115 ) ;
F_52 ( F_11 , V_2 ) ;
signal ( V_29 , F_10 ) ;
signal ( V_116 , F_10 ) ;
signal ( V_40 , F_10 ) ;
if ( ! V_114 ) {
if ( ! F_53 ( V_117 , & V_108 ) && F_54 ( V_108 . V_118 ) )
V_52 -> V_97 = true ;
else
V_2 -> V_114 = V_114 = L_31 ;
}
if ( V_114 ) {
if ( ! strcmp ( V_114 , L_32 ) )
V_52 -> V_97 = true ;
else if ( ! V_107 ( V_114 , & V_108 ) && V_108 . V_119 ) {
if ( V_2 -> V_120 == V_121 ) {
char V_122 [ V_123 ] ;
snprintf ( V_122 , sizeof( V_122 ) , L_33 ,
V_114 ) ;
F_55 ( V_122 ) ;
rename ( V_114 , V_122 ) ;
}
} else if ( V_2 -> V_120 == V_124 ) {
V_2 -> V_120 = V_121 ;
}
}
V_109 = V_125 | V_126 ;
if ( V_2 -> V_120 == V_124 )
V_2 -> V_91 = 0 ;
else
V_109 |= V_127 ;
if ( V_52 -> V_97 )
V_7 = V_117 ;
else
V_7 = F_56 ( V_114 , V_109 , V_128 | V_129 ) ;
if ( V_7 < 0 ) {
perror ( L_34 ) ;
return - 1 ;
}
V_2 -> V_7 = V_7 ;
V_50 = F_57 ( V_114 , V_130 ,
V_2 -> V_120 == V_121 , false , NULL ) ;
if ( V_50 == NULL ) {
F_4 ( L_35 ) ;
return - 1 ;
}
V_2 -> V_50 = V_50 ;
for ( V_110 = V_131 ; V_110 < V_132 ; V_110 ++ )
F_58 ( & V_50 -> V_15 , V_110 ) ;
if ( V_2 -> V_99 )
F_59 ( & V_50 -> V_15 , V_133 ) ;
if ( ! F_60 ( & V_113 -> V_134 ) )
F_59 ( & V_50 -> V_15 , V_103 ) ;
if ( ! V_2 -> V_52 . V_135 )
F_59 ( & V_50 -> V_15 , V_136 ) ;
if ( ! V_2 -> V_91 ) {
V_68 = F_61 ( V_50 , V_7 ) ;
if ( V_68 < 0 )
goto V_137;
}
if ( V_112 ) {
V_68 = F_62 ( V_113 , V_52 , V_106 ) ;
if ( V_68 < 0 ) {
F_4 ( L_36 ) ;
goto V_137;
}
}
if ( F_22 ( V_2 ) != 0 ) {
V_68 = - 1 ;
goto V_137;
}
F_52 ( F_39 , V_2 ) ;
if ( V_52 -> V_97 ) {
V_68 = F_63 ( V_7 ) ;
if ( V_68 < 0 )
goto V_137;
} else if ( V_2 -> V_91 ) {
V_68 = F_40 ( V_50 , V_113 ,
V_7 , false ) ;
if ( V_68 < 0 )
goto V_137;
}
if ( ! V_2 -> V_99
&& ! F_49 ( & V_50 -> V_15 , V_133 ) ) {
F_4 ( L_37
L_38 ) ;
V_68 = - 1 ;
goto V_137;
}
V_2 -> V_95 = F_37 ( V_7 , 0 , V_93 ) ;
V_14 = F_64 ( V_50 ) ;
if ( ! V_14 ) {
F_4 ( L_39 ) ;
V_68 = - 1 ;
goto V_137;
}
if ( V_52 -> V_97 ) {
V_68 = F_65 ( V_9 , V_50 ,
F_5 ) ;
if ( V_68 < 0 ) {
F_4 ( L_40 ) ;
goto V_137;
}
V_68 = F_66 ( V_9 , F_5 ,
V_14 ) ;
if ( V_68 < 0 ) {
F_4 ( L_41 ) ;
goto V_137;
}
if ( F_60 ( & V_113 -> V_134 ) ) {
V_68 = F_67 ( V_9 , V_7 , V_113 ,
F_5 ) ;
if ( V_68 <= 0 ) {
F_4 ( L_42 ) ;
goto V_137;
}
F_1 ( V_2 , V_68 ) ;
}
}
V_68 = F_47 ( V_9 , F_5 ,
V_14 , L_29 ) ;
if ( V_68 < 0 )
V_68 = F_47 ( V_9 , F_5 ,
V_14 , L_30 ) ;
if ( V_68 < 0 )
F_4 ( L_43
L_44
L_45 ) ;
V_68 = F_46 ( V_9 , F_5 ,
V_14 ) ;
if ( V_68 < 0 )
F_4 ( L_46
L_44
L_47 ) ;
if ( V_138 )
F_68 ( V_50 , V_9 ,
F_44 ) ;
if ( ! V_52 -> V_73 . V_139 )
V_68 = F_69 ( V_9 , V_113 -> V_67 ,
F_5 ,
V_14 ) ;
else
V_68 = F_70 ( V_9 , F_5 ,
V_14 ) ;
if ( V_68 != 0 )
goto V_137;
if ( V_2 -> V_140 ) {
struct V_141 V_142 ;
V_142 . V_143 = V_2 -> V_140 ;
if ( F_71 ( 0 , V_144 , & V_142 ) ) {
F_4 ( L_48 ) ;
V_68 = - 1 ;
goto V_137;
}
}
F_72 ( V_113 ) ;
if ( V_112 )
F_73 ( V_113 ) ;
for (; ; ) {
int V_145 = V_2 -> V_25 ;
if ( F_48 ( V_2 ) < 0 ) {
V_68 = - 1 ;
goto V_137;
}
if ( V_145 == V_2 -> V_25 ) {
if ( V_31 )
break;
V_68 = F_74 ( V_113 -> V_146 , V_113 -> V_147 , - 1 ) ;
V_111 ++ ;
}
if ( V_31 )
F_75 ( V_113 ) ;
}
if ( V_148 || V_32 == V_40 )
return 0 ;
fprintf ( V_92 , L_49 , V_111 ) ;
fprintf ( V_92 ,
L_50 V_149 L_51 ,
( double ) V_2 -> V_4 / 1024.0 / 1024.0 ,
V_114 ,
V_2 -> V_4 / 24 ) ;
return 0 ;
V_137:
F_41 ( V_50 ) ;
return V_68 ;
}
static int
F_76 ( const struct V_150 * V_151 , const char * V_152 , int V_153 )
{
#define F_77 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
T_5 * V_154 = ( T_5 * ) V_151 -> V_155 ;
const struct V_156 * V_157 ;
char * V_158 , * V_159 = NULL , * V_160 ;
int V_6 = - 1 ;
if ( V_153 )
return 0 ;
if ( * V_154 )
return - 1 ;
if ( V_152 ) {
V_158 = V_159 = F_78 ( V_152 ) ;
if ( ! V_158 )
return - 1 ;
for (; ; ) {
V_160 = strchr ( V_158 , ',' ) ;
if ( V_160 )
* V_160 = '\0' ;
for ( V_157 = V_161 ; V_157 -> V_86 ; V_157 ++ ) {
if ( ! strcasecmp ( V_158 , V_157 -> V_86 ) )
break;
}
if ( ! V_157 -> V_86 ) {
F_28 ( L_52
L_53 , V_158 ) ;
goto error;
}
* V_154 |= V_157 -> V_154 ;
if ( ! V_160 )
break;
V_158 = V_160 + 1 ;
}
}
V_6 = 0 ;
if ( ( * V_154 & ~ F_77 ) == 0 ) {
* V_154 = V_162 ;
}
error:
free ( V_159 ) ;
return V_6 ;
}
static int F_79 ( char * V_152 , unsigned long * V_163 )
{
char * V_164 ;
unsigned long V_3 ;
unsigned long V_165 = F_80 ( V_166 , sizeof( T_4 ) ) ;
V_3 = strtoul ( V_152 , & V_164 , 0 ) ;
do {
if ( * V_164 )
break;
V_3 = F_81 ( V_3 , sizeof( T_4 ) ) ;
if ( ! V_3 || V_3 > V_165 )
break;
* V_163 = V_3 ;
return 0 ;
} while ( 0 );
F_4 ( L_54 ,
V_165 , V_152 ) ;
return - 1 ;
}
static int
F_82 ( const struct V_150 * V_151 V_13 , const char * V_33 ,
int V_153 )
{
struct V_1 * V_2 = (struct V_1 * ) V_151 -> V_155 ;
char * V_167 , * V_86 , * V_168 = NULL ;
char * V_5 ;
int V_6 = - 1 ;
if ( V_153 )
return 0 ;
F_83 ( ! V_33 ) ;
V_5 = malloc ( strlen ( V_33 ) + 1 ) ;
if ( ! V_5 )
return - V_169 ;
strcpy ( V_5 , V_33 ) ;
V_167 = strtok_r ( ( char * ) V_5 , L_55 , & V_168 ) ;
V_86 = V_167 ? : ( char * ) V_5 ;
do {
if ( ! strncmp ( V_86 , L_56 , sizeof( L_56 ) ) ) {
if ( ! strtok_r ( NULL , L_55 , & V_168 ) ) {
V_2 -> V_52 . V_170 = V_171 ;
V_6 = 0 ;
} else
F_4 ( L_57
L_58 ) ;
break;
#ifdef F_84
} else if ( ! strncmp ( V_86 , L_59 , sizeof( L_59 ) ) ) {
const unsigned long V_172 = 8192 ;
V_6 = 0 ;
V_2 -> V_52 . V_170 = V_173 ;
V_2 -> V_52 . V_174 = V_172 ;
V_167 = strtok_r ( NULL , L_55 , & V_168 ) ;
if ( V_167 ) {
unsigned long V_3 = 0 ;
V_6 = F_79 ( V_167 , & V_3 ) ;
V_2 -> V_52 . V_174 = V_3 ;
}
if ( ! V_6 )
F_27 ( L_60 ,
V_2 -> V_52 . V_174 ) ;
#endif
} else {
F_4 ( L_61
L_62 , V_33 ) ;
break;
}
} while ( 0 );
free ( V_5 ) ;
if ( ! V_6 )
F_27 ( L_63 , V_2 -> V_52 . V_170 ) ;
return V_6 ;
}
int F_85 ( int V_105 , const char * * V_106 , const char * T_6 V_13 )
{
int V_68 = - V_169 ;
struct V_44 * V_45 ;
struct V_42 * V_113 ;
struct V_1 * V_2 = & V_175 ;
char V_176 [ V_177 ] ;
V_113 = F_86 ( NULL , NULL ) ;
if ( V_113 == NULL )
return - V_169 ;
V_2 -> V_35 = V_113 ;
V_105 = F_87 ( V_105 , V_106 , V_178 , V_179 ,
V_180 ) ;
if ( ! V_105 && F_88 ( & V_2 -> V_52 . V_73 ) )
F_89 ( V_179 , V_178 ) ;
if ( V_2 -> V_181 && V_2 -> V_182 ) {
F_29 ( L_64
L_65 ) ;
F_89 ( V_179 , V_178 ) ;
} else if ( V_2 -> V_182 ) {
V_2 -> V_120 = V_124 ;
} else {
V_2 -> V_120 = V_121 ;
}
if ( V_183 && ! V_2 -> V_52 . V_73 . V_139 ) {
F_29 ( L_66
L_67 ) ;
F_89 ( V_179 , V_178 ) ;
}
F_90 () ;
if ( V_184 . V_185 )
F_91 (
L_68
L_69
L_70
L_71
L_72
L_73
L_74 ) ;
if ( V_2 -> V_186 || V_2 -> V_99 )
F_92 () ;
if ( V_113 -> V_47 == 0 &&
F_93 ( V_113 ) < 0 ) {
F_4 ( L_75 ) ;
goto V_187;
}
V_68 = F_94 ( & V_2 -> V_52 . V_73 ) ;
if ( V_68 ) {
F_95 ( & V_2 -> V_52 . V_73 , V_68 , V_176 , V_177 ) ;
F_28 ( L_76 , V_176 ) ;
}
V_68 = F_96 ( & V_2 -> V_52 . V_73 ) ;
if ( V_68 ) {
int V_188 = V_69 ;
F_95 ( & V_2 -> V_52 . V_73 , V_68 , V_176 , V_177 ) ;
F_29 ( L_76 , V_176 ) ;
V_68 = - V_188 ;
goto V_189;
}
V_68 = - V_169 ;
if ( F_97 ( V_113 , & V_2 -> V_52 . V_73 ) < 0 )
F_89 ( V_179 , V_178 ) ;
F_20 (pos, &evsel_list->entries, node) {
if ( F_98 ( V_45 -> V_48 . V_81 , F_30 ( V_45 ) ) )
goto V_189;
}
if ( V_2 -> V_52 . V_190 != V_191 )
V_2 -> V_52 . V_192 = V_2 -> V_52 . V_190 ;
if ( V_2 -> V_52 . V_193 != V_194 )
V_2 -> V_52 . V_195 = V_2 -> V_52 . V_193 ;
if ( V_2 -> V_52 . V_192 )
V_2 -> V_52 . V_195 = 0 ;
else if ( V_2 -> V_52 . V_195 ) {
V_2 -> V_52 . V_192 = V_2 -> V_52 . V_195 ;
} else {
F_29 ( L_77 ) ;
V_68 = - V_75 ;
goto V_189;
}
V_68 = F_50 ( & V_175 , V_105 , V_106 ) ;
V_189:
F_99 ( V_113 ) ;
V_187:
F_43 () ;
return V_68 ;
}
