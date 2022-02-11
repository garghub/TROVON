static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 += V_3 ;
}
static void F_2 ( struct V_1 * V_2 , void * V_5 , T_1 V_3 )
{
while ( V_3 ) {
int V_6 = F_3 ( V_2 -> V_7 , V_5 , V_3 ) ;
if ( V_6 < 0 )
F_4 ( L_1 ) ;
V_3 -= V_6 ;
V_5 += V_6 ;
V_2 -> V_4 += V_6 ;
}
}
static int F_5 ( struct V_8 * V_9 ,
union V_10 * V_11 ,
struct V_12 * T_2 V_13 ,
struct V_14 * V_14 V_13 )
{
struct V_1 * V_2 = F_6 ( V_9 , struct V_1 , V_9 ) ;
F_2 ( V_2 , V_11 , V_11 -> V_15 . V_3 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
unsigned int V_18 = F_8 ( V_17 ) ;
unsigned int V_19 = V_17 -> V_20 ;
unsigned char * V_21 = V_17 -> V_22 + V_2 -> V_23 ;
unsigned long V_3 ;
void * V_5 ;
if ( V_19 == V_18 )
return;
V_2 -> V_24 ++ ;
V_3 = V_18 - V_19 ;
if ( ( V_19 & V_17 -> V_25 ) + V_3 != ( V_18 & V_17 -> V_25 ) ) {
V_5 = & V_21 [ V_19 & V_17 -> V_25 ] ;
V_3 = V_17 -> V_25 + 1 - ( V_19 & V_17 -> V_25 ) ;
V_19 += V_3 ;
F_2 ( V_2 , V_5 , V_3 ) ;
}
V_5 = & V_21 [ V_19 & V_17 -> V_25 ] ;
V_3 = V_18 - V_19 ;
V_19 += V_3 ;
F_2 ( V_2 , V_5 , V_3 ) ;
V_17 -> V_20 = V_19 ;
F_9 ( V_17 , V_19 ) ;
}
static void F_10 ( int V_26 )
{
if ( V_26 == V_27 )
V_28 = 1 ;
V_29 = 1 ;
V_30 = V_26 ;
}
static void F_11 ( int T_3 V_13 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
int V_32 ;
if ( V_2 -> V_33 -> V_34 . V_35 > 0 ) {
if ( ! V_28 )
F_12 ( V_2 -> V_33 -> V_34 . V_35 , V_36 ) ;
F_13 ( & V_32 ) ;
if ( F_14 ( V_32 ) )
F_15 ( F_16 ( V_32 ) , V_2 -> V_37 ) ;
}
if ( V_30 == - 1 || V_30 == V_38 )
return;
signal ( V_30 , V_39 ) ;
F_12 ( F_17 () , V_30 ) ;
}
static bool F_18 ( struct V_40 * V_33 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 , * V_44 ;
if ( V_33 -> V_45 != V_41 -> V_45 )
return false ;
V_44 = F_19 ( V_41 -> V_46 . V_47 , struct V_42 , V_48 ) ;
F_20 (pos, &evlist->entries, node) {
if ( memcmp ( & V_43 -> V_49 , & V_44 -> V_49 , sizeof( V_43 -> V_49 ) != 0 ) )
return false ;
V_44 = F_19 ( V_44 -> V_48 . V_47 , struct V_42 , V_48 ) ;
}
return true ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_42 * V_43 , * V_50 ;
struct V_40 * V_33 = V_2 -> V_33 ;
struct V_51 * V_52 = V_2 -> V_52 ;
struct V_53 * V_54 = & V_2 -> V_54 ;
V_50 = F_19 ( V_33 -> V_46 . V_47 , struct V_42 , V_48 ) ;
F_22 ( V_33 , V_54 ) ;
F_20 (pos, &evlist->entries, node) {
struct V_55 * V_49 = & V_43 -> V_49 ;
struct V_56 * V_57 = NULL ;
bool V_58 = V_49 -> V_59 & V_60 ;
if ( V_54 -> V_61 && V_43 != V_50 )
V_57 = V_50 -> V_62 ;
V_63:
if ( V_54 -> V_64 )
V_49 -> V_65 = V_49 -> V_66 = 0 ;
V_67:
V_49 -> V_68 = V_54 -> V_69 ? 0 : 1 ;
V_70:
if ( F_23 ( V_43 , V_33 -> V_71 , V_33 -> V_72 ,
V_54 -> V_61 , V_57 ) < 0 ) {
int V_73 = V_74 ;
if ( V_73 == V_75 || V_73 == V_76 ) {
F_24 () ;
exit ( V_77 ) ;
} else if ( V_73 == V_78 && V_54 -> V_79 ) {
F_4 ( L_2
L_3 ) ;
} else if ( V_73 == V_80 ) {
if ( ! V_54 -> V_64 &&
( V_49 -> V_65 || V_49 -> V_66 ) ) {
F_25 ( L_4
L_5 ) ;
V_54 -> V_64 = true ;
goto V_63;
} else if ( ! V_54 -> V_69 ) {
V_54 -> V_69 = true ;
if ( ! V_54 -> V_81 && ! V_54 -> V_82 && ! V_58 )
V_49 -> V_59 &= ~ V_60 ;
goto V_67;
}
}
if ( V_49 -> type == V_83
&& V_49 -> V_84 == V_85 ) {
if ( V_86 )
F_26 ( L_6
L_7 ) ;
V_49 -> type = V_87 ;
V_49 -> V_84 = V_88 ;
goto V_70;
}
if ( V_73 == V_89 ) {
F_26 ( L_8 ,
F_27 ( V_43 ) ) ;
exit ( V_77 ) ;
}
printf ( L_9 ) ;
error ( L_10 ,
V_73 , strerror ( V_73 ) ) ;
#if F_28 ( V_90 ) || F_28 ( V_91 )
if ( V_49 -> type == V_83 && V_73 == V_92 )
F_4 ( L_11
L_12
L_13
L_14 ) ;
#endif
F_4 ( L_15 ) ;
}
}
if ( F_29 ( V_33 ) ) {
error ( L_16 , V_74 ,
strerror ( V_74 ) ) ;
exit ( - 1 ) ;
}
if ( F_30 ( V_33 , V_54 -> V_93 , false ) < 0 ) {
if ( V_74 == V_75 )
F_4 ( L_17
L_18
L_19
L_20
L_21 , V_54 -> V_93 ) ;
else if ( ! F_31 ( V_54 -> V_93 ) )
F_4 ( L_22 ) ;
F_4 ( L_23 , V_74 , strerror ( V_74 ) ) ;
}
if ( V_2 -> V_94 )
V_52 -> V_33 = V_33 ;
else {
if ( ! F_18 ( V_52 -> V_33 , V_33 ) ) {
fprintf ( V_95 , L_24 ) ;
exit ( - 1 ) ;
}
}
F_32 ( V_52 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
T_4 V_3 = F_34 ( V_2 -> V_7 , 0 , V_96 ) ;
if ( V_3 == 0 )
return 0 ;
V_2 -> V_52 -> V_62 = V_2 -> V_7 ;
return F_35 ( V_2 -> V_52 , V_2 -> V_97 ,
V_3 - V_2 -> V_97 ,
V_3 , & V_98 ) ;
}
static void F_36 ( int V_32 V_13 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
if ( ! V_2 -> V_54 . V_99 ) {
V_2 -> V_52 -> V_15 . V_100 += V_2 -> V_4 ;
if ( ! V_2 -> V_101 )
F_33 ( V_2 ) ;
F_37 ( V_2 -> V_52 , V_2 -> V_33 ,
V_2 -> V_7 , true ) ;
F_38 ( V_2 -> V_52 ) ;
F_39 ( V_2 -> V_33 ) ;
F_40 () ;
}
}
static void F_41 ( struct V_14 * V_14 , void * V_21 )
{
int V_73 ;
struct V_8 * V_9 = V_21 ;
if ( F_42 ( V_14 ) )
return;
V_73 = F_43 ( V_9 , F_5 ,
V_14 ) ;
if ( V_73 < 0 )
F_44 ( L_25
L_26 , V_14 -> V_35 ) ;
V_73 = F_45 ( V_9 , F_5 ,
V_14 , L_27 ) ;
if ( V_73 < 0 )
V_73 = F_45 ( V_9 , F_5 ,
V_14 , L_28 ) ;
if ( V_73 < 0 )
F_44 ( L_25
L_26 , V_14 -> V_35 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_2 -> V_33 -> V_103 ; V_102 ++ ) {
if ( V_2 -> V_33 -> V_104 [ V_102 ] . V_22 )
F_7 ( V_2 , & V_2 -> V_33 -> V_104 [ V_102 ] ) ;
}
if ( F_47 ( & V_2 -> V_52 -> V_15 , V_105 ) )
F_2 ( V_2 , & V_106 , sizeof( V_106 ) ) ;
}
static int F_48 ( struct V_1 * V_2 , int V_107 , const char * * V_108 )
{
struct V_109 V_110 ;
int V_111 ;
int V_73 , V_7 , V_112 ;
unsigned long V_113 = 0 ;
const bool V_114 = V_107 > 0 ;
struct V_14 * V_14 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_53 * V_54 = & V_2 -> V_54 ;
struct V_40 * V_115 = V_2 -> V_33 ;
const char * V_116 = V_2 -> V_116 ;
struct V_51 * V_52 ;
V_2 -> V_37 = V_108 [ 0 ] ;
V_2 -> V_23 = F_49 ( V_117 ) ;
F_50 ( F_11 , V_2 ) ;
signal ( V_27 , F_10 ) ;
signal ( V_118 , F_10 ) ;
signal ( V_38 , F_10 ) ;
if ( ! V_116 ) {
if ( ! F_51 ( V_119 , & V_110 ) && F_52 ( V_110 . V_120 ) )
V_54 -> V_99 = true ;
else
V_2 -> V_116 = V_116 = L_29 ;
}
if ( V_116 ) {
if ( ! strcmp ( V_116 , L_30 ) )
V_54 -> V_99 = true ;
else if ( ! V_109 ( V_116 , & V_110 ) && V_110 . V_121 ) {
if ( V_2 -> V_122 == V_123 ) {
char V_124 [ V_125 ] ;
snprintf ( V_124 , sizeof( V_124 ) , L_31 ,
V_116 ) ;
F_53 ( V_124 ) ;
rename ( V_116 , V_124 ) ;
}
} else if ( V_2 -> V_122 == V_126 ) {
V_2 -> V_122 = V_123 ;
}
}
V_111 = V_127 | V_128 ;
if ( V_2 -> V_122 == V_126 )
V_2 -> V_94 = 0 ;
else
V_111 |= V_129 ;
if ( V_54 -> V_99 )
V_7 = V_119 ;
else
V_7 = F_54 ( V_116 , V_111 , V_130 | V_131 ) ;
if ( V_7 < 0 ) {
perror ( L_32 ) ;
exit ( - 1 ) ;
}
V_2 -> V_7 = V_7 ;
V_52 = F_55 ( V_116 , V_132 ,
V_2 -> V_122 == V_123 , false , NULL ) ;
if ( V_52 == NULL ) {
F_44 ( L_33 ) ;
return - 1 ;
}
V_2 -> V_52 = V_52 ;
for ( V_112 = V_133 ; V_112 < V_134 ; V_112 ++ )
F_56 ( & V_52 -> V_15 , V_112 ) ;
if ( V_2 -> V_101 )
F_57 ( & V_52 -> V_15 , V_135 ) ;
if ( ! F_58 ( & V_115 -> V_46 ) )
F_57 ( & V_52 -> V_15 , V_105 ) ;
if ( ! V_2 -> V_54 . V_136 )
F_57 ( & V_52 -> V_15 , V_137 ) ;
if ( ! V_2 -> V_94 ) {
V_73 = F_59 ( V_52 , V_7 ) ;
if ( V_73 < 0 )
goto V_138;
}
if ( V_114 ) {
V_73 = F_60 ( V_115 , V_54 , V_108 ) ;
if ( V_73 < 0 ) {
F_44 ( L_34 ) ;
goto V_138;
}
}
F_21 ( V_2 ) ;
F_50 ( F_36 , V_2 ) ;
if ( V_54 -> V_99 ) {
V_73 = F_61 ( V_7 ) ;
if ( V_73 < 0 )
return V_73 ;
} else if ( V_2 -> V_94 ) {
V_73 = F_37 ( V_52 , V_115 ,
V_7 , false ) ;
if ( V_73 < 0 )
return V_73 ;
}
if ( ! V_2 -> V_101
&& ! F_47 ( & V_52 -> V_15 , V_135 ) ) {
F_44 ( L_35
L_36 ) ;
return - 1 ;
}
V_2 -> V_97 = F_34 ( V_7 , 0 , V_96 ) ;
V_14 = F_62 ( V_52 ) ;
if ( ! V_14 ) {
F_44 ( L_37 ) ;
return - 1 ;
}
if ( V_54 -> V_99 ) {
V_73 = F_63 ( V_9 , V_52 ,
F_5 ) ;
if ( V_73 < 0 ) {
F_44 ( L_38 ) ;
return V_73 ;
}
V_73 = F_64 ( V_9 , F_5 ,
V_14 ) ;
if ( V_73 < 0 ) {
F_44 ( L_39 ) ;
return V_73 ;
}
if ( F_58 ( & V_115 -> V_46 ) ) {
V_73 = F_65 ( V_9 , V_7 , V_115 ,
F_5 ) ;
if ( V_73 <= 0 ) {
F_44 ( L_40 ) ;
return V_73 ;
}
F_1 ( V_2 , V_73 ) ;
}
}
V_73 = F_45 ( V_9 , F_5 ,
V_14 , L_27 ) ;
if ( V_73 < 0 )
V_73 = F_45 ( V_9 , F_5 ,
V_14 , L_28 ) ;
if ( V_73 < 0 )
F_44 ( L_41
L_42
L_43 ) ;
V_73 = F_43 ( V_9 , F_5 ,
V_14 ) ;
if ( V_73 < 0 )
F_44 ( L_44
L_42
L_45 ) ;
if ( V_139 )
F_66 ( V_52 , V_9 ,
F_41 ) ;
if ( ! V_54 -> V_140 )
F_67 ( V_9 , V_115 -> V_72 ,
F_5 ,
V_14 ) ;
else
F_68 ( V_9 , F_5 ,
V_14 ) ;
if ( V_2 -> V_141 ) {
struct V_142 V_143 ;
V_143 . V_144 = V_2 -> V_141 ;
if ( F_69 ( 0 , V_145 , & V_143 ) ) {
F_44 ( L_46 ) ;
exit ( - 1 ) ;
}
}
F_70 ( V_115 ) ;
if ( V_114 )
F_71 ( V_115 ) ;
for (; ; ) {
int V_146 = V_2 -> V_24 ;
F_46 ( V_2 ) ;
if ( V_146 == V_2 -> V_24 ) {
if ( V_29 )
break;
V_73 = F_72 ( V_115 -> V_147 , V_115 -> V_148 , - 1 ) ;
V_113 ++ ;
}
if ( V_29 )
F_73 ( V_115 ) ;
}
if ( V_149 || V_30 == V_38 )
return 0 ;
fprintf ( V_95 , L_47 , V_113 ) ;
fprintf ( V_95 ,
L_48 V_150 L_49 ,
( double ) V_2 -> V_4 / 1024.0 / 1024.0 ,
V_116 ,
V_2 -> V_4 / 24 ) ;
return 0 ;
V_138:
F_38 ( V_52 ) ;
return V_73 ;
}
static int
F_74 ( const struct V_151 * V_152 , const char * V_153 , int V_154 )
{
#define F_75 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
T_5 * V_155 = ( T_5 * ) V_152 -> V_156 ;
const struct V_157 * V_158 ;
char * V_159 , * V_160 = NULL , * V_161 ;
int V_6 = - 1 ;
if ( V_154 )
return 0 ;
if ( * V_155 )
return - 1 ;
if ( V_153 ) {
V_159 = V_160 = F_76 ( V_153 ) ;
if ( ! V_159 )
return - 1 ;
for (; ; ) {
V_161 = strchr ( V_159 , ',' ) ;
if ( V_161 )
* V_161 = '\0' ;
for ( V_158 = V_162 ; V_158 -> V_163 ; V_158 ++ ) {
if ( ! strcasecmp ( V_159 , V_158 -> V_163 ) )
break;
}
if ( ! V_158 -> V_163 ) {
F_26 ( L_50
L_51 , V_159 ) ;
goto error;
}
* V_155 |= V_158 -> V_155 ;
if ( ! V_161 )
break;
V_159 = V_161 + 1 ;
}
}
V_6 = 0 ;
if ( ( * V_155 & ~ F_75 ) == 0 ) {
* V_155 = V_164 ;
}
error:
free ( V_160 ) ;
return V_6 ;
}
int F_77 ( int V_107 , const char * * V_108 , const char * T_6 V_13 )
{
int V_73 = - V_165 ;
struct V_42 * V_43 ;
struct V_40 * V_115 ;
struct V_1 * V_2 = & V_166 ;
F_78 ( V_107 , V_108 ) ;
V_115 = F_79 ( NULL , NULL ) ;
if ( V_115 == NULL )
return - V_165 ;
V_2 -> V_33 = V_115 ;
V_107 = F_80 ( V_107 , V_108 , V_167 , V_168 ,
V_169 ) ;
if ( ! V_107 && ! V_2 -> V_54 . V_170 && ! V_2 -> V_54 . V_171 &&
! V_2 -> V_54 . V_140 && ! V_2 -> V_54 . V_79 && ! V_2 -> V_172 )
F_81 ( V_168 , V_167 ) ;
if ( V_2 -> V_173 && V_2 -> V_174 ) {
fprintf ( V_95 , L_52
L_53 ) ;
F_81 ( V_168 , V_167 ) ;
} else if ( V_2 -> V_174 ) {
V_2 -> V_122 = V_126 ;
} else {
V_2 -> V_122 = V_123 ;
}
if ( V_175 && ! V_2 -> V_54 . V_140 ) {
fprintf ( V_95 , L_54
L_55 ) ;
F_81 ( V_168 , V_167 ) ;
}
F_82 () ;
if ( V_176 . V_177 )
F_83 (
L_56
L_57
L_58
L_59
L_60
L_61
L_62 ) ;
if ( V_2 -> V_178 || V_2 -> V_101 )
F_84 () ;
if ( V_115 -> V_45 == 0 &&
F_85 ( V_115 ) < 0 ) {
F_44 ( L_63 ) ;
goto V_179;
}
V_2 -> V_54 . V_180 = F_86 ( V_2 -> V_172 , V_2 -> V_54 . V_171 ,
V_2 -> V_54 . V_170 ) ;
if ( V_2 -> V_172 != NULL && V_2 -> V_54 . V_180 == V_181 - 1 )
goto V_182;
if ( V_2 -> V_54 . V_170 )
V_2 -> V_54 . V_171 = V_2 -> V_54 . V_170 ;
if ( F_87 ( V_115 , V_2 -> V_54 . V_170 ,
V_2 -> V_54 . V_171 , V_2 -> V_54 . V_180 ,
V_2 -> V_54 . V_79 ) < 0 )
F_81 ( V_168 , V_167 ) ;
F_20 (pos, &evsel_list->entries, node) {
if ( F_88 ( V_43 -> V_49 . V_84 , F_27 ( V_43 ) ) )
goto V_182;
}
if ( V_2 -> V_54 . V_183 != V_184 )
V_2 -> V_54 . V_185 = V_2 -> V_54 . V_183 ;
if ( V_2 -> V_54 . V_186 != V_181 )
V_2 -> V_54 . V_187 = V_2 -> V_54 . V_186 ;
if ( V_2 -> V_54 . V_185 )
V_2 -> V_54 . V_187 = 0 ;
else if ( V_2 -> V_54 . V_187 ) {
V_2 -> V_54 . V_185 = V_2 -> V_54 . V_187 ;
} else {
fprintf ( V_95 , L_64 ) ;
V_73 = - V_80 ;
goto V_182;
}
V_73 = F_48 ( & V_166 , V_107 , V_108 ) ;
V_182:
F_89 ( V_115 ) ;
V_179:
F_40 () ;
return V_73 ;
}
