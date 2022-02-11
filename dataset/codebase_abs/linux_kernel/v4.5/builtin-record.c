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
static int F_6 ( struct V_1 * V_2 , int V_16 )
{
struct V_17 * V_18 = & V_2 -> V_19 -> V_20 [ V_16 ] ;
T_3 V_21 = F_7 ( V_18 ) ;
T_3 V_22 = V_18 -> V_23 ;
unsigned char * V_24 = V_18 -> V_25 + V_26 ;
unsigned long V_4 ;
void * V_27 ;
int V_28 = 0 ;
if ( V_22 == V_21 )
return 0 ;
V_2 -> V_29 ++ ;
V_4 = V_21 - V_22 ;
if ( ( V_22 & V_18 -> V_30 ) + V_4 != ( V_21 & V_18 -> V_30 ) ) {
V_27 = & V_24 [ V_22 & V_18 -> V_30 ] ;
V_4 = V_18 -> V_30 + 1 - ( V_22 & V_18 -> V_30 ) ;
V_22 += V_4 ;
if ( F_1 ( V_2 , V_27 , V_4 ) < 0 ) {
V_28 = - 1 ;
goto V_31;
}
}
V_27 = & V_24 [ V_22 & V_18 -> V_30 ] ;
V_4 = V_21 - V_22 ;
V_22 += V_4 ;
if ( F_1 ( V_2 , V_27 , V_4 ) < 0 ) {
V_28 = - 1 ;
goto V_31;
}
V_18 -> V_23 = V_22 ;
F_8 ( V_2 -> V_19 , V_16 ) ;
V_31:
return V_28 ;
}
static void F_9 ( int V_32 )
{
if ( V_32 == V_33 )
V_34 = 1 ;
else
V_35 = V_32 ;
V_36 = 1 ;
}
static void F_10 ( void )
{
if ( V_35 == - 1 )
return;
signal ( V_35 , V_37 ) ;
raise ( V_35 ) ;
}
static int F_11 ( struct V_8 * V_9 ,
union V_10 * V_11 , void * V_38 ,
T_1 V_39 , void * V_40 , T_1 V_41 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
struct V_42 * V_6 = & V_2 -> V_6 ;
T_1 V_43 ;
T_4 V_44 [ 8 ] = { 0 } ;
if ( ! F_12 ( V_6 ) ) {
T_5 V_45 ;
int V_46 = F_13 ( V_6 ) ;
int V_47 ;
V_45 = F_14 ( V_46 , 0 , V_48 ) ;
if ( V_45 == - 1 )
return - 1 ;
V_47 = F_15 ( & V_2 -> V_5 -> V_49 ,
V_11 , V_45 ) ;
if ( V_47 )
return V_47 ;
}
V_43 = ( V_39 + V_41 ) & 7 ;
if ( V_43 )
V_43 = 8 - V_43 ;
F_1 ( V_2 , V_11 , V_11 -> V_15 . V_4 ) ;
F_1 ( V_2 , V_38 , V_39 ) ;
if ( V_41 )
F_1 ( V_2 , V_40 , V_41 ) ;
F_1 ( V_2 , & V_44 , V_43 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
int V_52 ;
V_52 = F_17 ( V_51 , V_2 -> V_53 , & V_2 -> V_9 ,
F_11 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( V_52 )
V_2 -> V_29 ++ ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
int V_52 ;
V_52 = F_19 ( V_51 , V_2 -> V_53 , & V_2 -> V_9 ,
F_11 ,
V_2 -> V_54 . V_55 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( V_52 )
V_2 -> V_29 ++ ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_56 ;
int V_28 = 0 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_19 -> V_57 ; V_56 ++ ) {
struct V_50 * V_51 =
& V_2 -> V_19 -> V_20 [ V_56 ] . V_50 ;
if ( ! V_51 -> V_25 )
continue;
if ( F_18 ( V_2 , V_51 ) != 0 ) {
V_28 = - 1 ;
goto V_31;
}
}
V_31:
return V_28 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( L_2 ) ;
if ( F_20 ( V_2 ) < 0 ) {
V_58 = - 1 ;
} else {
V_58 = F_23 ( V_2 -> V_53 ) ;
if ( ! V_58 )
V_59 = 1 ;
}
}
static inline
int F_16 ( struct V_1 * V_2 V_13 ,
struct V_50 * V_51 V_13 )
{
return 0 ;
}
static inline
void F_21 ( struct V_1 * V_2 V_13 )
{
}
static inline
int F_24 ( struct V_60 * V_53 V_13 )
{
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
char V_61 [ 512 ] ;
struct V_62 * V_63 ;
struct V_64 * V_19 = V_2 -> V_19 ;
struct V_65 * V_5 = V_2 -> V_5 ;
struct V_66 * V_54 = & V_2 -> V_54 ;
int V_28 = 0 ;
F_26 ( V_19 , V_54 ) ;
F_27 (evlist, pos) {
V_67:
if ( F_28 ( V_63 , V_63 -> V_68 , V_63 -> V_69 ) < 0 ) {
if ( F_29 ( V_63 , V_70 , V_61 , sizeof( V_61 ) ) ) {
if ( V_71 )
F_30 ( L_3 , V_61 ) ;
goto V_67;
}
V_28 = - V_70 ;
F_31 ( V_63 , & V_54 -> V_72 ,
V_70 , V_61 , sizeof( V_61 ) ) ;
F_32 ( L_3 , V_61 ) ;
goto V_31;
}
}
if ( F_33 ( V_19 , & V_63 ) ) {
error ( L_4 ,
V_63 -> V_73 , F_34 ( V_63 ) , V_70 ,
F_35 ( V_70 , V_61 , sizeof( V_61 ) ) ) ;
V_28 = - 1 ;
goto V_31;
}
if ( F_36 ( V_19 , V_54 -> V_74 , false ,
V_54 -> V_75 ,
V_54 -> V_76 ) < 0 ) {
if ( V_70 == V_77 ) {
F_3 ( L_5
L_6
L_7
L_8
L_9 ,
V_54 -> V_74 , V_54 -> V_75 ) ;
V_28 = - V_70 ;
} else {
F_3 ( L_10 , V_70 ,
F_35 ( V_70 , V_61 , sizeof( V_61 ) ) ) ;
V_28 = - V_70 ;
}
goto V_31;
}
V_5 -> V_19 = V_19 ;
F_37 ( V_5 ) ;
V_31:
return V_28 ;
}
static int F_38 ( struct V_8 * V_9 ,
union V_10 * V_11 ,
struct V_12 * T_2 ,
struct V_62 * V_78 ,
struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_29 ++ ;
return F_39 ( V_9 , V_11 , T_2 , V_78 , V_14 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_42 * V_6 = & V_2 -> V_6 ;
struct V_65 * V_5 = V_2 -> V_5 ;
if ( V_6 -> V_4 == 0 )
return 0 ;
V_79 . V_80 = true ;
if ( V_2 -> V_81 )
V_2 -> V_9 . T_2 = NULL ;
return F_41 ( V_5 ) ;
}
static void F_42 ( struct V_14 * V_14 , void * V_24 )
{
int V_47 ;
struct V_8 * V_9 = V_24 ;
V_47 = F_43 ( V_9 , F_4 ,
V_14 ) ;
if ( V_47 < 0 )
F_3 ( L_11
L_12 , V_14 -> V_82 ) ;
V_47 = F_44 ( V_9 , F_4 ,
V_14 ) ;
if ( V_47 < 0 )
F_3 ( L_11
L_12 , V_14 -> V_82 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
T_3 V_7 = V_2 -> V_7 ;
int V_56 ;
int V_28 = 0 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_19 -> V_57 ; V_56 ++ ) {
struct V_50 * V_51 = & V_2 -> V_19 -> V_20 [ V_56 ] . V_50 ;
if ( V_2 -> V_19 -> V_20 [ V_56 ] . V_25 ) {
if ( F_6 ( V_2 , V_56 ) != 0 ) {
V_28 = - 1 ;
goto V_31;
}
}
if ( V_51 -> V_25 && ! V_2 -> V_54 . V_76 &&
F_16 ( V_2 , V_51 ) != 0 ) {
V_28 = - 1 ;
goto V_31;
}
}
if ( V_7 != V_2 -> V_7 )
V_28 = F_1 ( V_2 , & V_83 , sizeof( V_83 ) ) ;
V_31:
return V_28 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_65 * V_5 = V_2 -> V_5 ;
int V_84 ;
for ( V_84 = V_85 ; V_84 < V_86 ; V_84 ++ )
F_47 ( & V_5 -> V_15 , V_84 ) ;
if ( V_2 -> V_87 )
F_48 ( & V_5 -> V_15 , V_88 ) ;
if ( ! F_49 ( & V_2 -> V_19 -> V_89 ) )
F_48 ( & V_5 -> V_15 , V_90 ) ;
if ( ! V_2 -> V_54 . V_91 )
F_48 ( & V_5 -> V_15 , V_92 ) ;
if ( ! V_2 -> V_54 . V_93 )
F_48 ( & V_5 -> V_15 , V_94 ) ;
F_48 ( & V_5 -> V_15 , V_95 ) ;
}
static void F_50 ( int T_6 V_13 ,
T_7 * V_96 ,
void * T_8 V_13 )
{
V_97 = V_96 -> V_98 . V_99 ;
V_36 = 1 ;
V_34 = 1 ;
}
static int F_51 ( struct V_1 * V_2 , int V_100 , const char * * V_101 )
{
int V_47 ;
int V_102 = 0 ;
unsigned long V_103 = 0 ;
const bool V_104 = V_100 > 0 ;
struct V_14 * V_14 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_66 * V_54 = & V_2 -> V_54 ;
struct V_42 * V_6 = & V_2 -> V_6 ;
struct V_65 * V_5 ;
bool V_105 = false , V_106 = false ;
int V_46 ;
V_2 -> V_107 = V_101 [ 0 ] ;
atexit ( F_10 ) ;
signal ( V_33 , F_9 ) ;
signal ( V_108 , F_9 ) ;
signal ( V_109 , F_9 ) ;
if ( V_2 -> V_54 . V_76 )
signal ( V_110 , V_111 ) ;
else
signal ( V_110 , V_112 ) ;
V_5 = F_52 ( V_6 , false , V_9 ) ;
if ( V_5 == NULL ) {
F_3 ( L_13 ) ;
return - 1 ;
}
V_46 = F_13 ( V_6 ) ;
V_2 -> V_5 = V_5 ;
F_46 ( V_2 ) ;
if ( V_104 ) {
V_47 = F_53 ( V_2 -> V_19 , & V_54 -> V_72 ,
V_101 , V_6 -> V_113 ,
F_50 ) ;
if ( V_47 < 0 ) {
F_3 ( L_14 ) ;
V_102 = V_47 ;
goto V_114;
}
}
if ( F_25 ( V_2 ) != 0 ) {
V_47 = - 1 ;
goto V_115;
}
if ( V_2 -> V_9 . V_116 && ! F_54 ( V_2 -> V_19 ) ) {
F_55 ( L_15 ) ;
V_2 -> V_9 . V_116 = false ;
}
if ( ! V_2 -> V_19 -> V_117 )
F_48 ( & V_5 -> V_15 , V_118 ) ;
if ( V_6 -> V_113 ) {
V_47 = F_56 ( V_46 ) ;
if ( V_47 < 0 )
goto V_115;
} else {
V_47 = F_57 ( V_5 , V_2 -> V_19 , V_46 , false ) ;
if ( V_47 < 0 )
goto V_115;
}
if ( ! V_2 -> V_87
&& ! F_58 ( & V_5 -> V_15 , V_88 ) ) {
F_3 ( L_16
L_17 ) ;
V_47 = - 1 ;
goto V_115;
}
V_14 = & V_5 -> V_119 . V_120 ;
if ( V_6 -> V_113 ) {
V_47 = F_59 ( V_9 , V_5 ,
F_4 ) ;
if ( V_47 < 0 ) {
F_3 ( L_18 ) ;
goto V_115;
}
if ( F_49 ( & V_2 -> V_19 -> V_89 ) ) {
V_47 = F_60 ( V_9 , V_46 , V_2 -> V_19 ,
F_4 ) ;
if ( V_47 <= 0 ) {
F_3 ( L_19 ) ;
goto V_115;
}
V_2 -> V_7 += V_47 ;
}
}
if ( V_2 -> V_54 . V_93 ) {
V_47 = F_61 ( V_2 -> V_53 , V_9 ,
V_5 , F_4 ) ;
if ( V_47 )
goto V_114;
}
V_47 = F_44 ( V_9 , F_4 ,
V_14 ) ;
if ( V_47 < 0 )
F_3 ( L_20
L_21
L_22 ) ;
V_47 = F_43 ( V_9 , F_4 ,
V_14 ) ;
if ( V_47 < 0 )
F_3 ( L_23
L_21
L_24 ) ;
if ( V_121 ) {
F_62 ( & V_5 -> V_119 ,
F_42 , V_9 ) ;
}
V_47 = F_63 ( V_14 , V_9 , & V_54 -> V_72 , V_2 -> V_19 -> V_69 ,
F_4 , V_54 -> V_122 ,
V_54 -> V_123 ) ;
if ( V_47 != 0 )
goto V_115;
if ( V_2 -> V_124 ) {
struct V_125 V_126 ;
V_126 . V_127 = V_2 -> V_124 ;
if ( F_64 ( 0 , V_128 , & V_126 ) ) {
F_3 ( L_25 ) ;
V_47 = - 1 ;
goto V_115;
}
}
if ( ! F_65 ( & V_54 -> V_72 ) && ! V_54 -> V_129 )
F_66 ( V_2 -> V_19 ) ;
if ( V_104 ) {
union V_10 * V_11 ;
V_11 = malloc ( sizeof( V_11 -> V_130 ) + V_14 -> V_131 ) ;
if ( V_11 == NULL ) {
V_47 = - V_132 ;
goto V_115;
}
F_67 ( V_9 , V_11 ,
V_2 -> V_19 -> V_133 . V_82 ,
F_4 ,
V_14 ) ;
free ( V_11 ) ;
F_68 ( V_2 -> V_19 ) ;
}
if ( V_54 -> V_129 ) {
F_69 ( V_54 -> V_129 * 1000 ) ;
F_66 ( V_2 -> V_19 ) ;
}
V_59 = 1 ;
for (; ; ) {
unsigned long long V_134 = V_2 -> V_29 ;
if ( F_45 ( V_2 ) < 0 ) {
V_59 = 0 ;
V_47 = - 1 ;
goto V_115;
}
if ( V_135 ) {
V_135 = 0 ;
if ( ! V_58 )
F_21 ( V_2 ) ;
if ( V_58 ) {
F_3 ( L_26 ) ;
V_47 = - 1 ;
goto V_115;
}
}
if ( V_134 == V_2 -> V_29 ) {
if ( V_36 || V_106 )
break;
V_47 = F_70 ( V_2 -> V_19 , - 1 ) ;
if ( V_47 > 0 || ( V_47 < 0 && V_70 == V_136 ) )
V_47 = 0 ;
V_103 ++ ;
if ( F_71 ( V_2 -> V_19 , V_137 | V_138 ) == 0 )
V_106 = true ;
}
if ( V_36 && ! V_105 && ! F_65 ( & V_54 -> V_72 ) ) {
V_59 = 0 ;
F_72 ( V_2 -> V_19 ) ;
V_105 = true ;
}
}
V_59 = 0 ;
if ( V_104 && V_97 ) {
char V_61 [ V_139 ] ;
const char * V_140 = F_35 ( V_97 , V_61 , sizeof( V_61 ) ) ;
F_3 ( L_27 , V_140 ) ;
V_47 = - 1 ;
goto V_115;
}
if ( ! V_141 )
fprintf ( V_142 , L_28 , V_103 ) ;
V_115:
if ( V_104 ) {
int V_143 ;
if ( ! V_34 )
F_73 ( V_2 -> V_19 -> V_133 . V_82 , V_109 ) ;
F_74 ( & V_143 ) ;
if ( V_47 < 0 )
V_102 = V_47 ;
else if ( F_75 ( V_143 ) )
V_102 = F_76 ( V_143 ) ;
else if ( F_77 ( V_143 ) )
V_35 = F_78 ( V_143 ) ;
} else
V_102 = V_47 ;
V_2 -> V_29 = 0 ;
if ( ! V_47 && ! V_6 -> V_113 ) {
V_2 -> V_5 -> V_15 . V_144 += V_2 -> V_7 ;
V_6 -> V_4 = F_14 ( F_13 ( V_6 ) , 0 , V_48 ) ;
if ( ! V_2 -> V_87 ) {
F_40 ( V_2 ) ;
if ( V_2 -> V_81 )
F_79 ( V_2 -> V_5 ) ;
}
F_57 ( V_2 -> V_5 , V_2 -> V_19 , V_46 , true ) ;
}
if ( ! V_47 && ! V_141 ) {
char V_29 [ 128 ] ;
if ( V_2 -> V_29 && ! V_2 -> V_54 . V_93 )
F_80 ( V_29 , sizeof( V_29 ) ,
L_29 V_145 L_30 , V_2 -> V_29 ) ;
else
V_29 [ 0 ] = '\0' ;
fprintf ( V_142 , L_31 ,
F_81 ( V_6 ) / 1024.0 / 1024.0 ,
V_6 -> V_146 , V_29 ) ;
}
V_114:
F_82 ( V_5 ) ;
return V_102 ;
}
static void F_83 ( void )
{
static const char * V_147 [ V_148 ] = { L_32 , L_33 , L_34 , L_35 } ;
F_22 ( L_36 , V_147 [ V_149 . V_150 ] ) ;
if ( V_149 . V_150 == V_151 )
F_22 ( L_37 ,
V_149 . V_152 ) ;
}
int F_84 ( const struct V_153 * V_154 ,
const char * V_155 ,
int V_156 )
{
int V_52 ;
struct V_66 * V_1 = (struct V_66 * ) V_154 -> V_157 ;
V_1 -> V_158 = true ;
V_149 . V_159 = ! V_156 ;
if ( V_156 ) {
V_149 . V_150 = V_160 ;
F_22 ( L_38 ) ;
return 0 ;
}
V_52 = F_85 ( V_155 , & V_149 ) ;
if ( ! V_52 ) {
if ( V_149 . V_150 == V_151 )
V_1 -> V_122 = true ;
F_83 () ;
}
return V_52 ;
}
int F_86 ( const struct V_153 * V_154 ,
const char * V_155 V_13 ,
int V_156 V_13 )
{
struct V_66 * V_1 = (struct V_66 * ) V_154 -> V_157 ;
V_1 -> V_158 = true ;
V_149 . V_159 = true ;
if ( V_149 . V_150 == V_160 )
V_149 . V_150 = V_161 ;
F_83 () ;
return 0 ;
}
static int F_87 ( const char * V_162 , const char * V_157 , void * V_163 )
{
struct V_1 * V_2 = V_163 ;
if ( ! strcmp ( V_162 , L_39 ) ) {
if ( ! strcmp ( V_157 , L_40 ) )
V_2 -> V_164 = false ;
else if ( ! strcmp ( V_157 , L_41 ) )
V_2 -> V_164 = true ;
else if ( ! strcmp ( V_157 , L_42 ) )
V_2 -> V_87 = true ;
else
return - 1 ;
return 0 ;
}
if ( ! strcmp ( V_162 , L_43 ) )
V_162 = L_44 ;
return F_88 ( V_162 , V_157 , V_163 ) ;
}
static int F_89 ( const struct V_153 * V_154 , const char * V_147 , int V_156 )
{
struct V_66 * V_54 = (struct V_66 * ) V_154 -> V_157 ;
const struct V_165 * V_166 ;
const char * V_167 = V_147 ;
if ( V_156 ) {
V_54 -> V_168 = 0 ;
return 0 ;
}
if ( ! V_147 )
return 0 ;
if ( V_54 -> V_168 )
return - 1 ;
V_54 -> V_168 = true ;
if ( sscanf ( V_147 , L_45 , & V_54 -> V_169 ) == 1 )
return 0 ;
if ( ! strncasecmp ( V_147 , L_46 , 6 ) )
V_147 += 6 ;
for ( V_166 = V_170 ; V_166 -> V_171 ; V_166 ++ ) {
if ( ! strcasecmp ( V_147 , V_166 -> V_171 ) ) {
V_54 -> V_169 = V_166 -> V_169 ;
return 0 ;
}
}
V_54 -> V_168 = false ;
F_30 ( L_47 , V_167 ) ;
return - 1 ;
}
static int F_90 ( const struct V_153 * V_154 ,
const char * V_147 ,
int V_156 V_13 )
{
struct V_66 * V_54 = V_154 -> V_157 ;
char * V_172 , * V_173 ;
unsigned int V_74 ;
int V_52 ;
if ( ! V_147 )
return - V_174 ;
V_172 = F_91 ( V_147 ) ;
if ( ! V_172 )
return - V_132 ;
V_173 = strchr ( V_172 , ',' ) ;
if ( V_173 )
* V_173 = '\0' ;
if ( * V_172 ) {
V_52 = F_92 ( & V_74 , V_172 ) ;
if ( V_52 )
goto V_175;
V_54 -> V_74 = V_74 ;
}
if ( ! V_173 ) {
V_52 = 0 ;
goto V_175;
}
V_52 = F_92 ( & V_74 , V_173 + 1 ) ;
if ( V_52 )
goto V_175;
V_54 -> V_75 = V_74 ;
V_175:
free ( V_172 ) ;
return V_52 ;
}
int F_93 ( int V_100 , const char * * V_101 , const char * T_9 V_13 )
{
int V_47 ;
struct V_1 * V_2 = & V_1 ;
char V_176 [ V_177 ] ;
#ifndef F_94
# define F_95 ( V_172 , T_10 , T_11 ) set_option_nobuild(record_options, s, l, "NO_LIBBPF=1", c)
F_95 ( '\0' , L_48 , true ) ;
F_95 ( '\0' , L_49 , true ) ;
# undef F_95
#endif
#ifndef F_96
# if ! F_97 ( V_178 )
# define F_98 "NO_DWARF=1"
# elif ! F_97 ( F_94 )
# define F_98 "NO_LIBBPF=1"
# else
# define F_98 "this architecture doesn't support BPF prologue"
# endif
# define F_95 ( V_172 , T_10 , T_11 ) set_option_nobuild(record_options, s, l, REASON, c)
F_95 ( '\0' , L_50 , true ) ;
# undef F_95
# undef F_98
#endif
V_2 -> V_19 = F_99 () ;
if ( V_2 -> V_19 == NULL )
return - V_132 ;
F_100 ( F_87 , V_2 ) ;
V_100 = F_101 ( V_100 , V_101 , V_179 , V_180 ,
V_181 ) ;
if ( ! V_100 && F_65 ( & V_2 -> V_54 . V_72 ) )
F_102 ( V_180 , V_179 ) ;
if ( V_182 && ! V_2 -> V_54 . V_72 . V_183 ) {
F_103 ( V_180 , V_179 ,
L_51 ) ;
}
if ( V_2 -> V_54 . V_184 &&
! F_104 () ) {
F_32 ( L_52 ) ;
F_105 ( V_180 , V_179 , L_53 , 0 ) ;
return - V_174 ;
}
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = F_106 ( V_2 -> V_19 , & V_47 ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_107 ( V_2 -> V_53 , & V_2 -> V_54 ,
V_2 -> V_54 . V_185 ) ;
if ( V_47 )
return V_47 ;
V_47 = - V_132 ;
F_108 ( NULL ) ;
if ( V_79 . V_186 )
F_55 (
L_54
L_55
L_56
L_57
L_58
L_59
L_60 ) ;
if ( V_2 -> V_164 || V_2 -> V_87 )
F_109 () ;
if ( V_2 -> V_19 -> V_187 == 0 &&
F_110 ( V_2 -> V_19 ) < 0 ) {
F_3 ( L_61 ) ;
goto V_188;
}
if ( V_2 -> V_54 . V_72 . V_189 && ! V_2 -> V_54 . V_190 )
V_2 -> V_54 . V_191 = true ;
V_47 = F_111 ( & V_2 -> V_54 . V_72 ) ;
if ( V_47 ) {
F_112 ( & V_2 -> V_54 . V_72 , V_47 , V_176 , V_177 ) ;
F_30 ( L_62 , V_176 ) ;
}
V_47 = F_113 ( & V_2 -> V_54 . V_72 ) ;
if ( V_47 ) {
int V_192 = V_70 ;
F_112 ( & V_2 -> V_54 . V_72 , V_47 , V_176 , V_177 ) ;
F_32 ( L_62 , V_176 ) ;
V_47 = - V_192 ;
goto V_188;
}
V_47 = - V_132 ;
if ( F_114 ( V_2 -> V_19 , & V_2 -> V_54 . V_72 ) < 0 )
F_102 ( V_180 , V_179 ) ;
V_47 = F_115 ( V_2 -> V_53 , V_2 -> V_19 , & V_2 -> V_54 ) ;
if ( V_47 )
goto V_188;
if ( V_2 -> V_54 . V_93 )
V_2 -> V_81 = true ;
if ( F_116 ( & V_2 -> V_54 ) ) {
V_47 = - V_174 ;
goto V_188;
}
V_47 = F_51 ( & V_1 , V_100 , V_101 ) ;
V_188:
F_117 ( V_2 -> V_19 ) ;
F_118 () ;
F_119 ( V_2 -> V_53 ) ;
return V_47 ;
}
static void V_111 ( int V_32 V_13 )
{
if ( ! V_59 )
return;
V_59 = 0 ;
V_58 = F_24 ( V_1 . V_53 ) ;
V_135 = 1 ;
}
