static void F_1 ( T_1 V_1 )
{
V_2 += V_1 ;
}
static void F_2 ( void * V_3 , T_1 V_1 )
{
while ( V_1 ) {
int V_4 = F_3 ( V_5 , V_3 , V_1 ) ;
if ( V_4 < 0 )
F_4 ( L_1 ) ;
V_1 -= V_4 ;
V_3 += V_4 ;
V_2 += V_4 ;
}
}
static int F_5 ( union V_6 * V_7 ,
struct V_8 * T_2 V_9 ,
struct V_10 * T_3 V_9 )
{
F_2 ( V_7 , V_7 -> V_11 . V_1 ) ;
return 0 ;
}
static void F_6 ( struct V_12 * V_13 )
{
unsigned int V_14 = F_7 ( V_13 ) ;
unsigned int V_15 = V_13 -> V_16 ;
unsigned char * V_17 = V_13 -> V_18 + V_19 ;
unsigned long V_1 ;
void * V_3 ;
if ( V_15 == V_14 )
return;
V_20 ++ ;
V_1 = V_14 - V_15 ;
if ( ( V_15 & V_13 -> V_21 ) + V_1 != ( V_14 & V_13 -> V_21 ) ) {
V_3 = & V_17 [ V_15 & V_13 -> V_21 ] ;
V_1 = V_13 -> V_21 + 1 - ( V_15 & V_13 -> V_21 ) ;
V_15 += V_1 ;
F_2 ( V_3 , V_1 ) ;
}
V_3 = & V_17 [ V_15 & V_13 -> V_21 ] ;
V_1 = V_14 - V_15 ;
V_15 += V_1 ;
F_2 ( V_3 , V_1 ) ;
V_13 -> V_16 = V_15 ;
F_8 ( V_13 , V_15 ) ;
}
static void F_9 ( int V_22 )
{
if ( V_22 == V_23 )
V_24 = 1 ;
V_25 = 1 ;
V_26 = V_22 ;
}
static void F_10 ( void )
{
int V_27 ;
if ( V_28 > 0 ) {
if ( ! V_24 )
F_11 ( V_28 , V_29 ) ;
F_12 ( & V_27 ) ;
if ( F_13 ( V_27 ) )
F_14 ( F_15 ( V_27 ) , V_30 ) ;
}
if ( V_26 == - 1 || V_26 == V_31 )
return;
signal ( V_26 , V_32 ) ;
F_11 ( F_16 () , V_26 ) ;
}
static void F_17 ( struct V_33 * V_34 , struct V_35 * V_36 )
{
struct V_37 * V_38 = & V_34 -> V_38 ;
int V_39 = ! V_34 -> V_40 ;
V_38 -> V_41 = 1 ;
V_38 -> V_42 = ! V_43 ;
V_38 -> V_44 = V_45 |
V_46 |
V_47 ;
V_38 -> V_48 |= V_49 | V_50 ;
if ( V_36 -> V_51 > 1 )
V_38 -> V_48 |= V_52 ;
if ( ! V_38 -> V_53 || ( V_54 != V_55 &&
V_56 != V_57 ) ) {
if ( V_58 ) {
V_38 -> V_48 |= V_59 ;
V_38 -> V_58 = 1 ;
V_38 -> V_60 = V_58 ;
} else {
V_38 -> V_53 = V_61 ;
}
}
if ( V_62 )
V_38 -> V_60 = 0 ;
if ( V_63 )
V_38 -> V_63 = 1 ;
if ( V_64 ) {
V_38 -> V_48 |= V_65 ;
V_38 -> V_66 = V_39 ;
}
if ( V_67 )
V_38 -> V_48 |= V_68 ;
if ( V_69 )
V_38 -> V_48 |= V_70 ;
if ( V_71 &&
( V_72 || V_69 || ! V_43 || V_73 ) )
V_38 -> V_48 |= V_74 ;
if ( V_75 ) {
V_38 -> V_48 |= V_74 ;
V_38 -> V_48 |= V_76 ;
V_38 -> V_48 |= V_70 ;
}
if ( V_77 ) {
V_38 -> V_78 = 0 ;
V_38 -> V_79 = 1 ;
}
V_38 -> V_80 = V_39 ;
V_38 -> V_81 = V_39 ;
if ( V_82 == - 1 && V_83 == - 1 && ! V_69 ) {
V_38 -> V_41 = 1 ;
V_38 -> V_84 = 1 ;
}
}
static bool F_18 ( struct V_35 * V_36 ,
struct V_35 * V_85 )
{
struct V_33 * V_86 , * V_87 ;
if ( V_36 -> V_51 != V_85 -> V_51 )
return false ;
V_87 = F_19 ( V_85 -> V_88 . V_89 , struct V_33 , V_90 ) ;
F_20 (pos, &evlist->entries, node) {
if ( memcmp ( & V_86 -> V_38 , & V_87 -> V_38 , sizeof( V_86 -> V_38 ) != 0 ) )
return false ;
V_87 = F_19 ( V_87 -> V_90 . V_89 , struct V_33 , V_90 ) ;
}
return true ;
}
static void F_21 ( struct V_35 * V_36 )
{
struct V_33 * V_86 , * V_91 ;
if ( V_36 -> V_92 -> V_93 [ 0 ] < 0 )
V_43 = true ;
V_91 = F_19 ( V_36 -> V_88 . V_89 , struct V_33 , V_90 ) ;
F_20 (pos, &evlist->entries, node) {
struct V_37 * V_38 = & V_86 -> V_38 ;
struct V_94 * V_95 = NULL ;
bool V_96 = V_38 -> V_48 & V_74 ;
if ( V_97 && V_86 != V_91 )
V_95 = V_91 -> V_98 ;
F_17 ( V_86 , V_36 ) ;
V_99:
V_38 -> V_100 = V_71 ? 1 : 0 ;
V_101:
if ( F_22 ( V_86 , V_36 -> V_92 , V_36 -> V_102 , V_97 ,
V_95 ) < 0 ) {
int V_103 = V_104 ;
if ( V_103 == V_105 || V_103 == V_106 ) {
F_23 () ;
exit ( V_107 ) ;
} else if ( V_103 == V_108 && V_73 ) {
F_4 ( L_2
L_3 ) ;
} else if ( V_103 == V_109 && V_71 ) {
V_71 = false ;
if ( ! V_72 && ! V_75 && ! V_96 )
V_38 -> V_48 &= ~ V_74 ;
goto V_99;
}
if ( V_38 -> type == V_110
&& V_38 -> V_111 == V_112 ) {
if ( V_113 )
F_24 ( L_4
L_5 ) ;
V_38 -> type = V_114 ;
V_38 -> V_111 = V_115 ;
goto V_101;
}
if ( V_103 == V_116 ) {
F_24 ( L_6 ,
F_25 ( V_86 ) ) ;
exit ( V_107 ) ;
}
printf ( L_7 ) ;
error ( L_8 ,
V_103 , strerror ( V_103 ) ) ;
#if F_26 ( V_117 ) || F_26 ( V_118 )
if ( V_38 -> type == V_110 && V_103 == V_119 )
F_4 ( L_9
L_10
L_11
L_12 ) ;
#endif
F_4 ( L_13 ) ;
}
}
if ( F_27 ( V_36 ) ) {
error ( L_14 , V_104 ,
strerror ( V_104 ) ) ;
exit ( - 1 ) ;
}
if ( F_28 ( V_36 , V_120 , false ) < 0 )
F_4 ( L_15 , V_104 , strerror ( V_104 ) ) ;
if ( V_121 )
V_122 -> V_36 = V_36 ;
else {
if ( ! F_18 ( V_122 -> V_36 , V_36 ) ) {
fprintf ( V_123 , L_16 ) ;
exit ( - 1 ) ;
}
}
F_29 ( V_122 ) ;
}
static int F_30 ( void )
{
T_4 V_1 = F_31 ( V_5 , 0 , V_124 ) ;
if ( V_1 == 0 )
return 0 ;
V_122 -> V_98 = V_5 ;
return F_32 ( V_122 , V_125 ,
V_1 - V_125 ,
V_1 , & V_126 ) ;
}
static void F_33 ( void )
{
if ( ! V_127 ) {
V_122 -> V_11 . V_128 += V_2 ;
if ( ! V_129 )
F_30 () ;
F_34 ( V_122 , V_130 , V_5 , true ) ;
F_35 ( V_122 ) ;
F_36 ( V_130 ) ;
F_37 () ;
}
}
static void F_38 ( struct V_131 * V_131 , void * V_17 )
{
int V_103 ;
struct V_10 * V_132 = V_17 ;
if ( F_39 ( V_131 ) )
return;
V_103 = F_40 ( F_5 ,
V_132 , V_131 ) ;
if ( V_103 < 0 )
F_41 ( L_17
L_18 , V_131 -> V_133 ) ;
V_103 = F_42 ( F_5 ,
V_132 , V_131 , L_19 ) ;
if ( V_103 < 0 )
V_103 = F_42 ( F_5 ,
V_132 , V_131 ,
L_20 ) ;
if ( V_103 < 0 )
F_41 ( L_17
L_18 , V_131 -> V_133 ) ;
}
static void F_43 ( void )
{
int V_134 ;
for ( V_134 = 0 ; V_134 < V_130 -> V_135 ; V_134 ++ ) {
if ( V_130 -> V_80 [ V_134 ] . V_18 )
F_6 ( & V_130 -> V_80 [ V_134 ] ) ;
}
if ( F_44 ( & V_122 -> V_11 , V_136 ) )
F_2 ( & V_137 , sizeof( V_137 ) ) ;
}
static int F_45 ( int V_138 , const char * * V_139 )
{
struct V_140 V_141 ;
int V_142 ;
int V_103 ;
unsigned long V_143 = 0 ;
int V_144 [ 2 ] , V_145 [ 2 ] ;
const bool V_146 = V_138 > 0 ;
char V_3 ;
struct V_131 * V_131 ;
V_30 = V_139 [ 0 ] ;
V_19 = F_46 ( V_147 ) ;
atexit ( F_10 ) ;
signal ( V_23 , F_9 ) ;
signal ( V_148 , F_9 ) ;
signal ( V_31 , F_9 ) ;
if ( V_146 && ( F_47 ( V_144 ) < 0 || F_47 ( V_145 ) < 0 ) ) {
perror ( L_21 ) ;
exit ( - 1 ) ;
}
if ( ! V_149 ) {
if ( ! F_48 ( V_150 , & V_141 ) && F_49 ( V_141 . V_151 ) )
V_127 = 1 ;
else
V_149 = L_22 ;
}
if ( V_149 ) {
if ( ! strcmp ( V_149 , L_23 ) )
V_127 = 1 ;
else if ( ! V_140 ( V_149 , & V_141 ) && V_141 . V_152 ) {
if ( V_153 == V_154 ) {
char V_155 [ V_156 ] ;
snprintf ( V_155 , sizeof( V_155 ) , L_24 ,
V_149 ) ;
F_50 ( V_155 ) ;
rename ( V_149 , V_155 ) ;
}
} else if ( V_153 == V_157 ) {
V_153 = V_154 ;
}
}
V_142 = V_158 | V_159 ;
if ( V_153 == V_157 )
V_121 = 0 ;
else
V_142 |= V_160 ;
if ( V_127 )
V_5 = V_150 ;
else
V_5 = F_51 ( V_149 , V_142 , V_161 | V_162 ) ;
if ( V_5 < 0 ) {
perror ( L_25 ) ;
exit ( - 1 ) ;
}
V_122 = F_52 ( V_149 , V_163 ,
V_153 == V_154 , false , NULL ) ;
if ( V_122 == NULL ) {
F_41 ( L_26 ) ;
return - 1 ;
}
if ( ! V_129 )
F_53 ( & V_122 -> V_11 , V_164 ) ;
if ( ! V_121 ) {
V_103 = F_54 ( V_122 , V_5 ) ;
if ( V_103 < 0 )
goto V_165;
}
if ( F_55 ( & V_130 -> V_88 ) )
F_53 ( & V_122 -> V_11 , V_136 ) ;
F_53 ( & V_122 -> V_11 , V_166 ) ;
F_53 ( & V_122 -> V_11 , V_167 ) ;
F_53 ( & V_122 -> V_11 , V_168 ) ;
F_53 ( & V_122 -> V_11 , V_169 ) ;
F_53 ( & V_122 -> V_11 , V_170 ) ;
F_53 ( & V_122 -> V_11 , V_171 ) ;
F_53 ( & V_122 -> V_11 , V_172 ) ;
F_53 ( & V_122 -> V_11 , V_173 ) ;
F_53 ( & V_122 -> V_11 , V_174 ) ;
F_53 ( & V_122 -> V_11 , V_175 ) ;
F_53 ( & V_122 -> V_11 , V_176 ) ;
F_53 ( & V_122 -> V_11 , V_177 ) ;
if ( V_120 == V_55 )
V_120 = ( 512 * 1024 ) / V_19 ;
if ( V_146 ) {
V_28 = F_56 () ;
if ( V_28 < 0 ) {
perror ( L_27 ) ;
exit ( - 1 ) ;
}
if ( ! V_28 ) {
if ( V_127 )
F_57 ( 2 , 1 ) ;
F_58 ( V_144 [ 0 ] ) ;
F_58 ( V_145 [ 1 ] ) ;
F_59 ( V_145 [ 0 ] , V_178 , V_179 ) ;
F_60 ( L_28 , ( char * * ) V_139 ) ;
F_58 ( V_144 [ 1 ] ) ;
if ( F_61 ( V_145 [ 0 ] , & V_3 , 1 ) == - 1 )
perror ( L_29 ) ;
F_60 ( V_139 [ 0 ] , ( char * * ) V_139 ) ;
perror ( V_139 [ 0 ] ) ;
F_11 ( F_62 () , V_31 ) ;
exit ( - 1 ) ;
}
if ( ! V_69 && V_83 == - 1 && V_82 == - 1 )
V_130 -> V_102 -> V_93 [ 0 ] = V_28 ;
F_58 ( V_144 [ 1 ] ) ;
F_58 ( V_145 [ 0 ] ) ;
if ( F_61 ( V_144 [ 0 ] , & V_3 , 1 ) == - 1 ) {
perror ( L_29 ) ;
exit ( - 1 ) ;
}
F_58 ( V_144 [ 0 ] ) ;
}
F_21 ( V_130 ) ;
atexit ( F_33 ) ;
if ( V_127 ) {
V_103 = F_63 ( V_5 ) ;
if ( V_103 < 0 )
return V_103 ;
} else if ( V_121 ) {
V_103 = F_34 ( V_122 , V_130 ,
V_5 , false ) ;
if ( V_103 < 0 )
return V_103 ;
}
V_125 = F_31 ( V_5 , 0 , V_124 ) ;
if ( V_127 ) {
V_103 = F_64 ( V_122 ,
F_5 ) ;
if ( V_103 < 0 ) {
F_41 ( L_30 ) ;
return V_103 ;
}
V_103 = F_65 ( F_5 ,
V_122 ) ;
if ( V_103 < 0 ) {
F_41 ( L_31 ) ;
return V_103 ;
}
if ( F_55 ( & V_130 -> V_88 ) ) {
V_103 = F_66 ( V_5 , V_130 ,
F_5 ,
V_122 ) ;
if ( V_103 <= 0 ) {
F_41 ( L_32 ) ;
return V_103 ;
}
F_1 ( V_103 ) ;
}
}
V_131 = F_67 ( V_122 ) ;
if ( ! V_131 ) {
F_41 ( L_33 ) ;
return - 1 ;
}
V_103 = F_42 ( F_5 ,
V_122 , V_131 , L_19 ) ;
if ( V_103 < 0 )
V_103 = F_42 ( F_5 ,
V_122 , V_131 , L_20 ) ;
if ( V_103 < 0 )
F_41 ( L_34
L_35
L_36 ) ;
V_103 = F_40 ( F_5 ,
V_122 , V_131 ) ;
if ( V_103 < 0 )
F_41 ( L_37
L_35
L_38 ) ;
if ( V_180 )
F_68 ( V_122 ,
F_38 ) ;
if ( ! V_69 )
F_69 ( V_130 -> V_102 ,
F_5 ,
V_122 ) ;
else
F_70 ( F_5 ,
V_122 ) ;
if ( V_181 ) {
struct V_182 V_183 ;
V_183 . V_184 = V_181 ;
if ( F_71 ( 0 , V_185 , & V_183 ) ) {
F_41 ( L_39 ) ;
exit ( - 1 ) ;
}
}
F_72 ( V_130 ) ;
if ( V_146 )
F_58 ( V_145 [ 1 ] ) ;
for (; ; ) {
int V_186 = V_20 ;
F_43 () ;
if ( V_186 == V_20 ) {
if ( V_25 )
break;
V_103 = F_73 ( V_130 -> V_187 , V_130 -> V_188 , - 1 ) ;
V_143 ++ ;
}
if ( V_25 )
F_74 ( V_130 ) ;
}
if ( V_189 || V_26 == V_31 )
return 0 ;
fprintf ( V_123 , L_40 , V_143 ) ;
fprintf ( V_123 ,
L_41 V_190 L_42 ,
( double ) V_2 / 1024.0 / 1024.0 ,
V_149 ,
V_2 / 24 ) ;
return 0 ;
V_165:
F_35 ( V_122 ) ;
return V_103 ;
}
int F_75 ( int V_138 , const char * * V_139 , const char * T_5 V_9 )
{
int V_103 = - V_191 ;
struct V_33 * V_86 ;
F_76 ( V_138 , V_139 ) ;
V_130 = F_77 ( NULL , NULL ) ;
if ( V_130 == NULL )
return - V_191 ;
V_138 = F_78 ( V_138 , V_139 , V_192 , V_193 ,
V_194 ) ;
if ( ! V_138 && V_82 == - 1 && V_83 == - 1 &&
! V_69 && ! V_73 )
F_79 ( V_193 , V_192 ) ;
if ( V_195 && V_196 ) {
fprintf ( V_123 , L_43
L_44 ) ;
F_79 ( V_193 , V_192 ) ;
} else if ( V_196 ) {
V_153 = V_157 ;
} else {
V_153 = V_154 ;
}
if ( V_197 && ! V_69 ) {
fprintf ( V_123 , L_45
L_46 ) ;
F_79 ( V_193 , V_192 ) ;
}
F_80 () ;
if ( V_198 . V_199 )
F_81 (
L_47
L_48
L_49
L_50
L_51
L_52
L_53 ) ;
if ( V_200 || V_129 )
F_82 () ;
if ( V_130 -> V_51 == 0 &&
F_83 ( V_130 ) < 0 ) {
F_41 ( L_54 ) ;
goto V_201;
}
if ( V_82 != - 1 )
V_83 = V_82 ;
if ( F_84 ( V_130 , V_82 ,
V_83 , V_73 ) < 0 )
F_79 ( V_193 , V_192 ) ;
F_20 (pos, &evsel_list->entries, node) {
if ( F_85 ( V_86 , V_130 -> V_92 -> V_202 ,
V_130 -> V_102 -> V_202 ) < 0 )
goto V_203;
if ( F_86 ( V_86 -> V_38 . V_111 , F_25 ( V_86 ) ) )
goto V_203;
}
if ( F_87 ( V_130 ) < 0 )
goto V_203;
if ( V_56 != V_57 )
V_61 = V_56 ;
if ( V_54 != V_55 )
V_58 = V_54 ;
if ( V_61 )
V_58 = 0 ;
else if ( V_58 ) {
V_61 = V_58 ;
} else {
fprintf ( V_123 , L_55 ) ;
V_103 = - V_109 ;
goto V_203;
}
V_103 = F_45 ( V_138 , V_139 ) ;
V_203:
F_88 ( V_130 ) ;
V_201:
F_37 () ;
return V_103 ;
}
