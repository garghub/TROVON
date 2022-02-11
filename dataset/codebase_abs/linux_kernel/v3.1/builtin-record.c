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
V_23 = 1 ;
V_24 = V_22 ;
}
static void F_10 ( void )
{
if ( V_25 > 0 )
F_11 ( V_25 , V_26 ) ;
if ( V_24 == - 1 || V_24 == V_27 )
return;
signal ( V_24 , V_28 ) ;
F_11 ( F_12 () , V_24 ) ;
}
static void F_13 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_33 * V_34 = & V_30 -> V_34 ;
int V_35 = ! V_30 -> V_36 ;
V_34 -> V_37 = 1 ;
V_34 -> V_38 = ! V_39 ;
V_34 -> V_40 = V_41 |
V_42 |
V_43 ;
V_34 -> V_44 |= V_45 | V_46 ;
if ( V_32 -> V_47 > 1 )
V_34 -> V_44 |= V_48 ;
if ( ! V_34 -> V_49 || ( V_50 != V_51 &&
V_52 != V_53 ) ) {
if ( V_54 ) {
V_34 -> V_44 |= V_55 ;
V_34 -> V_54 = 1 ;
V_34 -> V_56 = V_54 ;
} else {
V_34 -> V_49 = V_57 ;
}
}
if ( V_58 )
V_34 -> V_56 = 0 ;
if ( V_59 )
V_34 -> V_59 = 1 ;
if ( V_60 ) {
V_34 -> V_44 |= V_61 ;
V_34 -> V_62 = V_35 ;
}
if ( V_63 )
V_34 -> V_44 |= V_64 ;
if ( V_65 )
V_34 -> V_44 |= V_66 ;
if ( V_67 &&
( V_68 || V_65 || ! V_39 || V_69 ) )
V_34 -> V_44 |= V_70 ;
if ( V_71 ) {
V_34 -> V_44 |= V_70 ;
V_34 -> V_44 |= V_72 ;
V_34 -> V_44 |= V_66 ;
}
if ( V_73 ) {
V_34 -> V_74 = 0 ;
V_34 -> V_75 = 1 ;
}
V_34 -> V_76 = V_35 ;
V_34 -> V_77 = V_35 ;
if ( V_78 == - 1 && V_79 == - 1 && ! V_65 ) {
V_34 -> V_37 = 1 ;
V_34 -> V_80 = 1 ;
}
}
static bool F_14 ( struct V_31 * V_32 ,
struct V_31 * V_81 )
{
struct V_29 * V_82 , * V_83 ;
if ( V_32 -> V_47 != V_81 -> V_47 )
return false ;
V_83 = F_15 ( V_81 -> V_84 . V_85 , struct V_29 , V_86 ) ;
F_16 (pos, &evlist->entries, node) {
if ( memcmp ( & V_82 -> V_34 , & V_83 -> V_34 , sizeof( V_82 -> V_34 ) != 0 ) )
return false ;
V_83 = F_15 ( V_83 -> V_86 . V_85 , struct V_29 , V_86 ) ;
}
return true ;
}
static void F_17 ( struct V_31 * V_32 )
{
struct V_29 * V_82 ;
if ( V_32 -> V_87 -> V_88 [ 0 ] < 0 )
V_39 = true ;
F_16 (pos, &evlist->entries, node) {
struct V_33 * V_34 = & V_82 -> V_34 ;
bool V_89 = V_34 -> V_44 & V_70 ;
F_13 ( V_82 , V_32 ) ;
V_90:
V_34 -> V_91 = V_67 ? 1 : 0 ;
V_92:
if ( F_18 ( V_82 , V_32 -> V_87 , V_32 -> V_93 , V_94 ) < 0 ) {
int V_95 = V_96 ;
if ( V_95 == V_97 || V_95 == V_98 ) {
F_19 () ;
exit ( V_99 ) ;
} else if ( V_95 == V_100 && V_69 ) {
F_4 ( L_2
L_3 ) ;
} else if ( V_95 == V_101 && V_67 ) {
V_67 = false ;
if ( ! V_68 && ! V_71 && ! V_89 )
V_34 -> V_44 &= ~ V_70 ;
goto V_90;
}
if ( V_34 -> type == V_102
&& V_34 -> V_103 == V_104 ) {
if ( V_105 )
F_20 ( L_4
L_5 ) ;
V_34 -> type = V_106 ;
V_34 -> V_103 = V_107 ;
goto V_92;
}
if ( V_95 == V_108 ) {
F_20 ( L_6 ,
F_21 ( V_82 ) ) ;
exit ( V_99 ) ;
}
printf ( L_7 ) ;
error ( L_8 ,
V_95 , strerror ( V_95 ) ) ;
#if F_22 ( V_109 ) || F_22 ( V_110 )
if ( V_34 -> type == V_102 && V_95 == V_111 )
F_4 ( L_9
L_10
L_11
L_12 ) ;
#endif
F_4 ( L_13 ) ;
}
}
if ( F_23 ( V_32 ) ) {
error ( L_14 , V_96 ,
strerror ( V_96 ) ) ;
exit ( - 1 ) ;
}
if ( F_24 ( V_32 , V_112 , false ) < 0 )
F_4 ( L_15 , V_96 , strerror ( V_96 ) ) ;
if ( V_113 )
V_114 -> V_32 = V_32 ;
else {
if ( ! F_14 ( V_114 -> V_32 , V_32 ) ) {
fprintf ( V_115 , L_16 ) ;
exit ( - 1 ) ;
}
}
F_25 ( V_114 ) ;
}
static int F_26 ( void )
{
T_4 V_1 = F_27 ( V_5 , 0 , V_116 ) ;
if ( V_1 == 0 )
return 0 ;
V_114 -> V_117 = V_5 ;
return F_28 ( V_114 , V_118 ,
V_1 - V_118 ,
V_1 , & V_119 ) ;
}
static void F_29 ( void )
{
if ( ! V_120 ) {
V_114 -> V_11 . V_121 += V_2 ;
if ( ! V_122 )
F_26 () ;
F_30 ( V_114 , V_123 , V_5 , true ) ;
F_31 ( V_114 ) ;
F_32 ( V_123 ) ;
F_33 () ;
}
}
static void F_34 ( struct V_124 * V_124 , void * V_17 )
{
int V_95 ;
struct V_10 * V_125 = V_17 ;
if ( F_35 ( V_124 ) )
return;
V_95 = F_36 ( F_5 ,
V_125 , V_124 ) ;
if ( V_95 < 0 )
F_37 ( L_17
L_18 , V_124 -> V_126 ) ;
V_95 = F_38 ( F_5 ,
V_125 , V_124 , L_19 ) ;
if ( V_95 < 0 )
V_95 = F_38 ( F_5 ,
V_125 , V_124 ,
L_20 ) ;
if ( V_95 < 0 )
F_37 ( L_17
L_18 , V_124 -> V_126 ) ;
}
static void F_39 ( void )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_123 -> V_128 ; V_127 ++ ) {
if ( V_123 -> V_76 [ V_127 ] . V_18 )
F_6 ( & V_123 -> V_76 [ V_127 ] ) ;
}
if ( F_40 ( & V_114 -> V_11 , V_129 ) )
F_2 ( & V_130 , sizeof( V_130 ) ) ;
}
static int F_41 ( int V_131 , const char * * V_132 )
{
struct V_133 V_134 ;
int V_135 ;
int V_95 ;
unsigned long V_136 = 0 ;
int V_137 [ 2 ] , V_138 [ 2 ] ;
const bool V_139 = V_131 > 0 ;
char V_3 ;
struct V_124 * V_124 ;
V_19 = F_42 ( V_140 ) ;
atexit ( F_10 ) ;
signal ( V_141 , F_9 ) ;
signal ( V_142 , F_9 ) ;
signal ( V_27 , F_9 ) ;
if ( V_139 && ( F_43 ( V_137 ) < 0 || F_43 ( V_138 ) < 0 ) ) {
perror ( L_21 ) ;
exit ( - 1 ) ;
}
if ( ! V_143 ) {
if ( ! F_44 ( V_144 , & V_134 ) && F_45 ( V_134 . V_145 ) )
V_120 = 1 ;
else
V_143 = L_22 ;
}
if ( V_143 ) {
if ( ! strcmp ( V_143 , L_23 ) )
V_120 = 1 ;
else if ( ! V_133 ( V_143 , & V_134 ) && V_134 . V_146 ) {
if ( V_147 == V_148 ) {
char V_149 [ V_150 ] ;
snprintf ( V_149 , sizeof( V_149 ) , L_24 ,
V_143 ) ;
F_46 ( V_149 ) ;
rename ( V_143 , V_149 ) ;
}
} else if ( V_147 == V_151 ) {
V_147 = V_148 ;
}
}
V_135 = V_152 | V_153 ;
if ( V_147 == V_151 )
V_113 = 0 ;
else
V_135 |= V_154 ;
if ( V_120 )
V_5 = V_144 ;
else
V_5 = F_47 ( V_143 , V_135 , V_155 | V_156 ) ;
if ( V_5 < 0 ) {
perror ( L_25 ) ;
exit ( - 1 ) ;
}
V_114 = F_48 ( V_143 , V_157 ,
V_147 == V_148 , false , NULL ) ;
if ( V_114 == NULL ) {
F_37 ( L_26 ) ;
return - 1 ;
}
if ( ! V_122 )
F_49 ( & V_114 -> V_11 , V_158 ) ;
if ( ! V_113 ) {
V_95 = F_50 ( V_114 , V_5 ) ;
if ( V_95 < 0 )
goto V_159;
}
if ( F_51 ( & V_123 -> V_84 ) )
F_49 ( & V_114 -> V_11 , V_129 ) ;
if ( V_112 == V_51 )
V_112 = ( 512 * 1024 ) / V_19 ;
if ( V_139 ) {
V_25 = F_52 () ;
if ( V_25 < 0 ) {
perror ( L_27 ) ;
exit ( - 1 ) ;
}
if ( ! V_25 ) {
if ( V_120 )
F_53 ( 2 , 1 ) ;
F_54 ( V_137 [ 0 ] ) ;
F_54 ( V_138 [ 1 ] ) ;
F_55 ( V_138 [ 0 ] , V_160 , V_161 ) ;
F_56 ( L_28 , ( char * * ) V_132 ) ;
F_54 ( V_137 [ 1 ] ) ;
if ( F_57 ( V_138 [ 0 ] , & V_3 , 1 ) == - 1 )
perror ( L_29 ) ;
F_56 ( V_132 [ 0 ] , ( char * * ) V_132 ) ;
perror ( V_132 [ 0 ] ) ;
F_11 ( F_58 () , V_27 ) ;
exit ( - 1 ) ;
}
if ( ! V_65 && V_79 == - 1 && V_78 == - 1 )
V_123 -> V_93 -> V_88 [ 0 ] = V_25 ;
F_54 ( V_137 [ 1 ] ) ;
F_54 ( V_138 [ 0 ] ) ;
if ( F_57 ( V_137 [ 0 ] , & V_3 , 1 ) == - 1 ) {
perror ( L_29 ) ;
exit ( - 1 ) ;
}
F_54 ( V_137 [ 0 ] ) ;
}
F_17 ( V_123 ) ;
atexit ( F_29 ) ;
if ( V_120 ) {
V_95 = F_59 ( V_5 ) ;
if ( V_95 < 0 )
return V_95 ;
} else if ( V_113 ) {
V_95 = F_30 ( V_114 , V_123 ,
V_5 , false ) ;
if ( V_95 < 0 )
return V_95 ;
}
V_118 = F_27 ( V_5 , 0 , V_116 ) ;
if ( V_120 ) {
V_95 = F_60 ( V_114 ,
F_5 ) ;
if ( V_95 < 0 ) {
F_37 ( L_30 ) ;
return V_95 ;
}
V_95 = F_61 ( F_5 ,
V_114 ) ;
if ( V_95 < 0 ) {
F_37 ( L_31 ) ;
return V_95 ;
}
if ( F_51 ( & V_123 -> V_84 ) ) {
V_95 = F_62 ( V_5 , V_123 ,
F_5 ,
V_114 ) ;
if ( V_95 <= 0 ) {
F_37 ( L_32 ) ;
return V_95 ;
}
F_1 ( V_95 ) ;
}
}
V_124 = F_63 ( V_114 ) ;
if ( ! V_124 ) {
F_37 ( L_33 ) ;
return - 1 ;
}
V_95 = F_38 ( F_5 ,
V_114 , V_124 , L_19 ) ;
if ( V_95 < 0 )
V_95 = F_38 ( F_5 ,
V_114 , V_124 , L_20 ) ;
if ( V_95 < 0 )
F_37 ( L_34
L_35
L_36 ) ;
V_95 = F_36 ( F_5 ,
V_114 , V_124 ) ;
if ( V_95 < 0 )
F_37 ( L_37
L_35
L_38 ) ;
if ( V_162 )
F_64 ( V_114 ,
F_34 ) ;
if ( ! V_65 )
F_65 ( V_123 -> V_93 ,
F_5 ,
V_114 ) ;
else
F_66 ( F_5 ,
V_114 ) ;
if ( V_163 ) {
struct V_164 V_165 ;
V_165 . V_166 = V_163 ;
if ( F_67 ( 0 , V_167 , & V_165 ) ) {
F_37 ( L_39 ) ;
exit ( - 1 ) ;
}
}
F_68 ( V_123 ) ;
if ( V_139 )
F_54 ( V_138 [ 1 ] ) ;
for (; ; ) {
int V_168 = V_20 ;
F_39 () ;
if ( V_168 == V_20 ) {
if ( V_23 )
break;
V_95 = F_69 ( V_123 -> V_169 , V_123 -> V_170 , - 1 ) ;
V_136 ++ ;
}
if ( V_23 )
F_70 ( V_123 ) ;
}
if ( V_171 || V_24 == V_27 )
return 0 ;
fprintf ( V_115 , L_40 , V_136 ) ;
fprintf ( V_115 ,
L_41 V_172 L_42 ,
( double ) V_2 / 1024.0 / 1024.0 ,
V_143 ,
V_2 / 24 ) ;
return 0 ;
V_159:
F_31 ( V_114 ) ;
return V_95 ;
}
int F_71 ( int V_131 , const char * * V_132 , const char * T_5 V_9 )
{
int V_95 = - V_173 ;
struct V_29 * V_82 ;
V_123 = F_72 ( NULL , NULL ) ;
if ( V_123 == NULL )
return - V_173 ;
V_131 = F_73 ( V_131 , V_132 , V_174 , V_175 ,
V_176 ) ;
if ( ! V_131 && V_78 == - 1 && V_79 == - 1 &&
! V_65 && ! V_69 )
F_74 ( V_175 , V_174 ) ;
if ( V_177 && V_178 ) {
fprintf ( V_115 , L_43
L_44 ) ;
F_74 ( V_175 , V_174 ) ;
} else if ( V_178 ) {
V_147 = V_151 ;
} else {
V_147 = V_148 ;
}
if ( V_179 && ! V_65 ) {
fprintf ( V_115 , L_45
L_46 ) ;
F_74 ( V_175 , V_174 ) ;
}
F_75 () ;
if ( V_180 . V_181 )
F_76 (
L_47
L_48
L_49
L_50
L_51
L_52
L_53 ) ;
if ( V_182 || V_122 )
F_77 () ;
if ( V_123 -> V_47 == 0 &&
F_78 ( V_123 ) < 0 ) {
F_37 ( L_54 ) ;
goto V_183;
}
if ( V_78 != - 1 )
V_79 = V_78 ;
if ( F_79 ( V_123 , V_78 ,
V_79 , V_69 ) < 0 )
F_74 ( V_175 , V_174 ) ;
F_16 (pos, &evsel_list->entries, node) {
if ( F_80 ( V_82 , V_123 -> V_87 -> V_184 ,
V_123 -> V_93 -> V_184 ) < 0 )
goto V_185;
if ( F_81 ( V_82 -> V_34 . V_103 , F_21 ( V_82 ) ) )
goto V_185;
}
if ( F_82 ( V_123 ) < 0 )
goto V_185;
if ( V_52 != V_53 )
V_57 = V_52 ;
if ( V_50 != V_51 )
V_54 = V_50 ;
if ( V_57 )
V_54 = 0 ;
else if ( V_54 ) {
V_57 = V_54 ;
} else {
fprintf ( V_115 , L_55 ) ;
V_95 = - V_101 ;
goto V_185;
}
V_95 = F_41 ( V_131 , V_132 ) ;
V_185:
F_83 ( V_123 ) ;
V_183:
F_33 () ;
return V_95 ;
}
