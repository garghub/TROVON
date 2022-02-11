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
} else if ( V_73 == V_78 && V_54 -> V_79 . V_80 ) {
F_4 ( L_2
L_3 ) ;
} else if ( V_73 == V_81 ) {
if ( ! V_54 -> V_64 &&
( V_49 -> V_65 || V_49 -> V_66 ) ) {
F_25 ( L_4
L_5 ) ;
V_54 -> V_64 = true ;
goto V_63;
} else if ( ! V_54 -> V_69 ) {
V_54 -> V_69 = true ;
if ( ! V_54 -> V_82 && ! V_54 -> V_83 && ! V_58 )
V_49 -> V_59 &= ~ V_60 ;
goto V_67;
}
}
if ( ( V_73 == V_84 || V_73 == V_85 )
&& V_49 -> type == V_86
&& V_49 -> V_87 == V_88 ) {
if ( V_89 )
F_26 ( L_6
L_7 ) ;
V_49 -> type = V_90 ;
V_49 -> V_87 = V_91 ;
if ( V_43 -> V_92 ) {
free ( V_43 -> V_92 ) ;
V_43 -> V_92 = NULL ;
}
goto V_70;
}
if ( V_73 == V_84 ) {
F_27 ( L_8 ,
F_28 ( V_43 ) ) ;
exit ( V_77 ) ;
}
printf ( L_9 ) ;
error ( L_10 ,
V_73 , strerror ( V_73 ) ) ;
#if F_29 ( V_93 ) || F_29 ( V_94 )
if ( V_49 -> type == V_86 && V_73 == V_95 )
F_4 ( L_11
L_12
L_13
L_14 ) ;
#endif
F_4 ( L_15 ) ;
}
}
if ( F_30 ( V_33 ) ) {
error ( L_16 , V_74 ,
strerror ( V_74 ) ) ;
exit ( - 1 ) ;
}
if ( F_31 ( V_33 , V_54 -> V_96 , false ) < 0 ) {
if ( V_74 == V_75 )
F_4 ( L_17
L_18
L_19
L_20
L_21 , V_54 -> V_96 ) ;
else if ( ! F_32 ( V_54 -> V_96 ) )
F_4 ( L_22 ) ;
F_4 ( L_23 , V_74 , strerror ( V_74 ) ) ;
}
if ( V_2 -> V_97 )
V_52 -> V_33 = V_33 ;
else {
if ( ! F_18 ( V_52 -> V_33 , V_33 ) ) {
fprintf ( V_98 , L_24 ) ;
exit ( - 1 ) ;
}
}
F_33 ( V_52 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_4 V_3 = F_35 ( V_2 -> V_7 , 0 , V_99 ) ;
if ( V_3 == 0 )
return 0 ;
V_2 -> V_52 -> V_62 = V_2 -> V_7 ;
return F_36 ( V_2 -> V_52 , V_2 -> V_100 ,
V_3 - V_2 -> V_100 ,
V_3 , & V_101 ) ;
}
static void F_37 ( int V_32 V_13 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
if ( ! V_2 -> V_54 . V_102 ) {
V_2 -> V_52 -> V_15 . V_103 += V_2 -> V_4 ;
if ( ! V_2 -> V_104 )
F_34 ( V_2 ) ;
F_38 ( V_2 -> V_52 , V_2 -> V_33 ,
V_2 -> V_7 , true ) ;
F_39 ( V_2 -> V_52 ) ;
F_40 ( V_2 -> V_33 ) ;
F_41 () ;
}
}
static void F_42 ( struct V_14 * V_14 , void * V_21 )
{
int V_73 ;
struct V_8 * V_9 = V_21 ;
if ( F_43 ( V_14 ) )
return;
V_73 = F_44 ( V_9 , F_5 ,
V_14 ) ;
if ( V_73 < 0 )
F_45 ( L_25
L_26 , V_14 -> V_35 ) ;
V_73 = F_46 ( V_9 , F_5 ,
V_14 , L_27 ) ;
if ( V_73 < 0 )
V_73 = F_46 ( V_9 , F_5 ,
V_14 , L_28 ) ;
if ( V_73 < 0 )
F_45 ( L_25
L_26 , V_14 -> V_35 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_2 -> V_33 -> V_106 ; V_105 ++ ) {
if ( V_2 -> V_33 -> V_107 [ V_105 ] . V_22 )
F_7 ( V_2 , & V_2 -> V_33 -> V_107 [ V_105 ] ) ;
}
if ( F_48 ( & V_2 -> V_52 -> V_15 , V_108 ) )
F_2 ( V_2 , & V_109 , sizeof( V_109 ) ) ;
}
static int F_49 ( struct V_1 * V_2 , int V_110 , const char * * V_111 )
{
struct V_112 V_113 ;
int V_114 ;
int V_73 , V_7 , V_115 ;
unsigned long V_116 = 0 ;
const bool V_117 = V_110 > 0 ;
struct V_14 * V_14 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_53 * V_54 = & V_2 -> V_54 ;
struct V_40 * V_118 = V_2 -> V_33 ;
const char * V_119 = V_2 -> V_119 ;
struct V_51 * V_52 ;
V_2 -> V_37 = V_111 [ 0 ] ;
V_2 -> V_23 = F_50 ( V_120 ) ;
F_51 ( F_11 , V_2 ) ;
signal ( V_27 , F_10 ) ;
signal ( V_121 , F_10 ) ;
signal ( V_38 , F_10 ) ;
if ( ! V_119 ) {
if ( ! F_52 ( V_122 , & V_113 ) && F_53 ( V_113 . V_123 ) )
V_54 -> V_102 = true ;
else
V_2 -> V_119 = V_119 = L_29 ;
}
if ( V_119 ) {
if ( ! strcmp ( V_119 , L_30 ) )
V_54 -> V_102 = true ;
else if ( ! V_112 ( V_119 , & V_113 ) && V_113 . V_124 ) {
if ( V_2 -> V_125 == V_126 ) {
char V_127 [ V_128 ] ;
snprintf ( V_127 , sizeof( V_127 ) , L_31 ,
V_119 ) ;
F_54 ( V_127 ) ;
rename ( V_119 , V_127 ) ;
}
} else if ( V_2 -> V_125 == V_129 ) {
V_2 -> V_125 = V_126 ;
}
}
V_114 = V_130 | V_131 ;
if ( V_2 -> V_125 == V_129 )
V_2 -> V_97 = 0 ;
else
V_114 |= V_132 ;
if ( V_54 -> V_102 )
V_7 = V_122 ;
else
V_7 = F_55 ( V_119 , V_114 , V_133 | V_134 ) ;
if ( V_7 < 0 ) {
perror ( L_32 ) ;
exit ( - 1 ) ;
}
V_2 -> V_7 = V_7 ;
V_52 = F_56 ( V_119 , V_135 ,
V_2 -> V_125 == V_126 , false , NULL ) ;
if ( V_52 == NULL ) {
F_45 ( L_33 ) ;
return - 1 ;
}
V_2 -> V_52 = V_52 ;
for ( V_115 = V_136 ; V_115 < V_137 ; V_115 ++ )
F_57 ( & V_52 -> V_15 , V_115 ) ;
if ( V_2 -> V_104 )
F_58 ( & V_52 -> V_15 , V_138 ) ;
if ( ! F_59 ( & V_118 -> V_46 ) )
F_58 ( & V_52 -> V_15 , V_108 ) ;
if ( ! V_2 -> V_54 . V_139 )
F_58 ( & V_52 -> V_15 , V_140 ) ;
if ( ! V_2 -> V_97 ) {
V_73 = F_60 ( V_52 , V_7 ) ;
if ( V_73 < 0 )
goto V_141;
}
if ( V_117 ) {
V_73 = F_61 ( V_118 , V_54 , V_111 ) ;
if ( V_73 < 0 ) {
F_45 ( L_34 ) ;
goto V_141;
}
}
F_21 ( V_2 ) ;
F_51 ( F_37 , V_2 ) ;
if ( V_54 -> V_102 ) {
V_73 = F_62 ( V_7 ) ;
if ( V_73 < 0 )
return V_73 ;
} else if ( V_2 -> V_97 ) {
V_73 = F_38 ( V_52 , V_118 ,
V_7 , false ) ;
if ( V_73 < 0 )
return V_73 ;
}
if ( ! V_2 -> V_104
&& ! F_48 ( & V_52 -> V_15 , V_138 ) ) {
F_45 ( L_35
L_36 ) ;
return - 1 ;
}
V_2 -> V_100 = F_35 ( V_7 , 0 , V_99 ) ;
V_14 = F_63 ( V_52 ) ;
if ( ! V_14 ) {
F_45 ( L_37 ) ;
return - 1 ;
}
if ( V_54 -> V_102 ) {
V_73 = F_64 ( V_9 , V_52 ,
F_5 ) ;
if ( V_73 < 0 ) {
F_45 ( L_38 ) ;
return V_73 ;
}
V_73 = F_65 ( V_9 , F_5 ,
V_14 ) ;
if ( V_73 < 0 ) {
F_45 ( L_39 ) ;
return V_73 ;
}
if ( F_59 ( & V_118 -> V_46 ) ) {
V_73 = F_66 ( V_9 , V_7 , V_118 ,
F_5 ) ;
if ( V_73 <= 0 ) {
F_45 ( L_40 ) ;
return V_73 ;
}
F_1 ( V_2 , V_73 ) ;
}
}
V_73 = F_46 ( V_9 , F_5 ,
V_14 , L_27 ) ;
if ( V_73 < 0 )
V_73 = F_46 ( V_9 , F_5 ,
V_14 , L_28 ) ;
if ( V_73 < 0 )
F_45 ( L_41
L_42
L_43 ) ;
V_73 = F_44 ( V_9 , F_5 ,
V_14 ) ;
if ( V_73 < 0 )
F_45 ( L_44
L_42
L_45 ) ;
if ( V_142 )
F_67 ( V_52 , V_9 ,
F_42 ) ;
if ( ! V_54 -> V_79 . V_143 )
F_68 ( V_9 , V_118 -> V_72 ,
F_5 ,
V_14 ) ;
else
F_69 ( V_9 , F_5 ,
V_14 ) ;
if ( V_2 -> V_144 ) {
struct V_145 V_146 ;
V_146 . V_147 = V_2 -> V_144 ;
if ( F_70 ( 0 , V_148 , & V_146 ) ) {
F_45 ( L_46 ) ;
exit ( - 1 ) ;
}
}
F_71 ( V_118 ) ;
if ( V_117 )
F_72 ( V_118 ) ;
for (; ; ) {
int V_149 = V_2 -> V_24 ;
F_47 ( V_2 ) ;
if ( V_149 == V_2 -> V_24 ) {
if ( V_29 )
break;
V_73 = F_73 ( V_118 -> V_150 , V_118 -> V_151 , - 1 ) ;
V_116 ++ ;
}
if ( V_29 )
F_74 ( V_118 ) ;
}
if ( V_152 || V_30 == V_38 )
return 0 ;
fprintf ( V_98 , L_47 , V_116 ) ;
fprintf ( V_98 ,
L_48 V_153 L_49 ,
( double ) V_2 -> V_4 / 1024.0 / 1024.0 ,
V_119 ,
V_2 -> V_4 / 24 ) ;
return 0 ;
V_141:
F_39 ( V_52 ) ;
return V_73 ;
}
static int
F_75 ( const struct V_154 * V_155 , const char * V_156 , int V_157 )
{
#define F_76 \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
T_5 * V_158 = ( T_5 * ) V_155 -> V_159 ;
const struct V_160 * V_161 ;
char * V_162 , * V_163 = NULL , * V_164 ;
int V_6 = - 1 ;
if ( V_157 )
return 0 ;
if ( * V_158 )
return - 1 ;
if ( V_156 ) {
V_162 = V_163 = F_77 ( V_156 ) ;
if ( ! V_162 )
return - 1 ;
for (; ; ) {
V_164 = strchr ( V_162 , ',' ) ;
if ( V_164 )
* V_164 = '\0' ;
for ( V_161 = V_165 ; V_161 -> V_92 ; V_161 ++ ) {
if ( ! strcasecmp ( V_162 , V_161 -> V_92 ) )
break;
}
if ( ! V_161 -> V_92 ) {
F_26 ( L_50
L_51 , V_162 ) ;
goto error;
}
* V_158 |= V_161 -> V_158 ;
if ( ! V_164 )
break;
V_162 = V_164 + 1 ;
}
}
V_6 = 0 ;
if ( ( * V_158 & ~ F_76 ) == 0 ) {
* V_158 = V_166 ;
}
error:
free ( V_163 ) ;
return V_6 ;
}
int F_78 ( int V_110 , const char * * V_111 , const char * T_6 V_13 )
{
int V_73 = - V_167 ;
struct V_42 * V_43 ;
struct V_40 * V_118 ;
struct V_1 * V_2 = & V_168 ;
char V_169 [ V_170 ] ;
V_118 = F_79 ( NULL , NULL ) ;
if ( V_118 == NULL )
return - V_167 ;
V_2 -> V_33 = V_118 ;
V_110 = F_80 ( V_110 , V_111 , V_171 , V_172 ,
V_173 ) ;
if ( ! V_110 && F_81 ( & V_2 -> V_54 . V_79 ) )
F_82 ( V_172 , V_171 ) ;
if ( V_2 -> V_174 && V_2 -> V_175 ) {
F_27 ( L_52
L_53 ) ;
F_82 ( V_172 , V_171 ) ;
} else if ( V_2 -> V_175 ) {
V_2 -> V_125 = V_129 ;
} else {
V_2 -> V_125 = V_126 ;
}
if ( V_176 && ! V_2 -> V_54 . V_79 . V_143 ) {
F_27 ( L_54
L_55 ) ;
F_82 ( V_172 , V_171 ) ;
}
F_83 () ;
if ( V_177 . V_178 )
F_84 (
L_56
L_57
L_58
L_59
L_60
L_61
L_62 ) ;
if ( V_2 -> V_179 || V_2 -> V_104 )
F_85 () ;
if ( V_118 -> V_45 == 0 &&
F_86 ( V_118 ) < 0 ) {
F_45 ( L_63 ) ;
goto V_180;
}
V_73 = F_87 ( & V_2 -> V_54 . V_79 ) ;
if ( V_73 ) {
F_88 ( & V_2 -> V_54 . V_79 , V_73 , V_169 , V_170 ) ;
F_26 ( L_64 , V_169 ) ;
}
V_73 = F_89 ( & V_2 -> V_54 . V_79 ) ;
if ( V_73 ) {
int V_181 = V_74 ;
F_88 ( & V_2 -> V_54 . V_79 , V_73 , V_169 , V_170 ) ;
F_27 ( L_64 , V_169 ) ;
V_73 = - V_181 ;
goto V_182;
}
V_73 = - V_167 ;
if ( F_90 ( V_118 , & V_2 -> V_54 . V_79 ) < 0 )
F_82 ( V_172 , V_171 ) ;
F_20 (pos, &evsel_list->entries, node) {
if ( F_91 ( V_43 -> V_49 . V_87 , F_28 ( V_43 ) ) )
goto V_182;
}
if ( V_2 -> V_54 . V_183 != V_184 )
V_2 -> V_54 . V_185 = V_2 -> V_54 . V_183 ;
if ( V_2 -> V_54 . V_186 != V_187 )
V_2 -> V_54 . V_188 = V_2 -> V_54 . V_186 ;
if ( V_2 -> V_54 . V_185 )
V_2 -> V_54 . V_188 = 0 ;
else if ( V_2 -> V_54 . V_188 ) {
V_2 -> V_54 . V_185 = V_2 -> V_54 . V_188 ;
} else {
F_27 ( L_65 ) ;
V_73 = - V_81 ;
goto V_182;
}
V_73 = F_49 ( & V_168 , V_110 , V_111 ) ;
V_182:
F_92 ( V_118 ) ;
V_180:
F_41 () ;
return V_73 ;
}
