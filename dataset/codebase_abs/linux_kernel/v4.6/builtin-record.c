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
if ( V_70 )
V_28 = - V_70 ;
else
V_28 = - V_78 ;
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
struct V_62 * V_79 ,
struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_29 ++ ;
return F_39 ( V_9 , V_11 , T_2 , V_79 , V_14 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_42 * V_6 = & V_2 -> V_6 ;
struct V_65 * V_5 = V_2 -> V_5 ;
if ( V_6 -> V_4 == 0 )
return 0 ;
V_80 . V_81 = true ;
if ( V_2 -> V_82 )
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
L_12 , V_14 -> V_83 ) ;
V_47 = F_44 ( V_9 , F_4 ,
V_14 ) ;
if ( V_47 < 0 )
F_3 ( L_11
L_12 , V_14 -> V_83 ) ;
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
V_28 = F_1 ( V_2 , & V_84 , sizeof( V_84 ) ) ;
V_31:
return V_28 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_65 * V_5 = V_2 -> V_5 ;
int V_85 ;
for ( V_85 = V_86 ; V_85 < V_87 ; V_85 ++ )
F_47 ( & V_5 -> V_15 , V_85 ) ;
if ( V_2 -> V_88 )
F_48 ( & V_5 -> V_15 , V_89 ) ;
if ( ! F_49 ( & V_2 -> V_19 -> V_90 ) )
F_48 ( & V_5 -> V_15 , V_91 ) ;
if ( ! V_2 -> V_54 . V_92 )
F_48 ( & V_5 -> V_15 , V_93 ) ;
if ( ! V_2 -> V_54 . V_94 )
F_48 ( & V_5 -> V_15 , V_95 ) ;
F_48 ( & V_5 -> V_15 , V_96 ) ;
}
static void
F_50 ( struct V_1 * V_2 )
{
struct V_42 * V_6 = & V_2 -> V_6 ;
int V_46 = F_13 ( V_6 ) ;
if ( V_6 -> V_97 )
return;
V_2 -> V_5 -> V_15 . V_98 += V_2 -> V_7 ;
V_6 -> V_4 = F_14 ( F_13 ( V_6 ) , 0 , V_48 ) ;
if ( ! V_2 -> V_88 ) {
F_40 ( V_2 ) ;
if ( V_2 -> V_82 )
F_51 ( V_2 -> V_5 ) ;
}
F_52 ( V_2 -> V_5 , V_2 -> V_19 , V_46 , true ) ;
return;
}
static void F_53 ( int T_6 V_13 ,
T_7 * V_99 ,
void * T_8 V_13 )
{
V_100 = V_99 -> V_101 . V_102 ;
V_36 = 1 ;
V_34 = 1 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_65 * V_5 = V_2 -> V_5 ;
struct V_14 * V_14 = & V_5 -> V_103 . V_104 ;
struct V_42 * V_6 = & V_2 -> V_6 ;
struct V_66 * V_54 = & V_2 -> V_54 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_46 = F_13 ( V_6 ) ;
int V_47 = 0 ;
if ( V_6 -> V_97 ) {
V_47 = F_55 ( V_9 , V_5 ,
F_4 ) ;
if ( V_47 < 0 ) {
F_3 ( L_13 ) ;
goto V_31;
}
if ( F_49 ( & V_2 -> V_19 -> V_90 ) ) {
V_47 = F_56 ( V_9 , V_46 , V_2 -> V_19 ,
F_4 ) ;
if ( V_47 <= 0 ) {
F_3 ( L_14 ) ;
goto V_31;
}
V_2 -> V_7 += V_47 ;
}
}
if ( V_2 -> V_54 . V_94 ) {
V_47 = F_57 ( V_2 -> V_53 , V_9 ,
V_5 , F_4 ) ;
if ( V_47 )
goto V_31;
}
V_47 = F_44 ( V_9 , F_4 ,
V_14 ) ;
F_58 ( V_47 < 0 , L_15
L_16
L_17 ) ;
V_47 = F_43 ( V_9 , F_4 ,
V_14 ) ;
F_58 ( V_47 < 0 , L_18
L_16
L_19 ) ;
if ( V_105 ) {
F_59 ( & V_5 -> V_103 ,
F_42 , V_9 ) ;
}
V_47 = F_60 ( V_14 , V_9 , & V_54 -> V_72 , V_2 -> V_19 -> V_69 ,
F_4 , V_54 -> V_106 ,
V_54 -> V_107 ) ;
V_31:
return V_47 ;
}
static int F_61 ( struct V_1 * V_2 , int V_108 , const char * * V_109 )
{
int V_47 ;
int V_110 = 0 ;
unsigned long V_111 = 0 ;
const bool V_112 = V_108 > 0 ;
struct V_14 * V_14 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_66 * V_54 = & V_2 -> V_54 ;
struct V_42 * V_6 = & V_2 -> V_6 ;
struct V_65 * V_5 ;
bool V_113 = false , V_114 = false ;
int V_46 ;
V_2 -> V_115 = V_109 [ 0 ] ;
atexit ( F_10 ) ;
signal ( V_33 , F_9 ) ;
signal ( V_116 , F_9 ) ;
signal ( V_117 , F_9 ) ;
if ( V_2 -> V_54 . V_76 )
signal ( V_118 , V_119 ) ;
else
signal ( V_118 , V_120 ) ;
V_5 = F_62 ( V_6 , false , V_9 ) ;
if ( V_5 == NULL ) {
F_3 ( L_20 ) ;
return - 1 ;
}
V_46 = F_13 ( V_6 ) ;
V_2 -> V_5 = V_5 ;
F_46 ( V_2 ) ;
if ( V_112 ) {
V_47 = F_63 ( V_2 -> V_19 , & V_54 -> V_72 ,
V_109 , V_6 -> V_97 ,
F_53 ) ;
if ( V_47 < 0 ) {
F_3 ( L_21 ) ;
V_110 = V_47 ;
goto V_121;
}
}
if ( F_25 ( V_2 ) != 0 ) {
V_47 = - 1 ;
goto V_122;
}
V_47 = F_64 () ;
if ( V_47 ) {
char V_123 [ V_124 ] ;
F_65 ( V_47 , V_123 , sizeof( V_123 ) ) ;
F_3 ( L_22 ,
V_123 ) ;
goto V_122;
}
if ( V_2 -> V_9 . V_125 && ! F_66 ( V_2 -> V_19 ) ) {
F_67 ( L_23 ) ;
V_2 -> V_9 . V_125 = false ;
}
if ( ! V_2 -> V_19 -> V_126 )
F_48 ( & V_5 -> V_15 , V_127 ) ;
if ( V_6 -> V_97 ) {
V_47 = F_68 ( V_46 ) ;
if ( V_47 < 0 )
goto V_122;
} else {
V_47 = F_52 ( V_5 , V_2 -> V_19 , V_46 , false ) ;
if ( V_47 < 0 )
goto V_122;
}
if ( ! V_2 -> V_88
&& ! F_69 ( & V_5 -> V_15 , V_89 ) ) {
F_3 ( L_24
L_25 ) ;
V_47 = - 1 ;
goto V_122;
}
V_14 = & V_5 -> V_103 . V_104 ;
V_47 = F_54 ( V_2 ) ;
if ( V_47 < 0 )
goto V_122;
if ( V_2 -> V_128 ) {
struct V_129 V_130 ;
V_130 . V_131 = V_2 -> V_128 ;
if ( F_70 ( 0 , V_132 , & V_130 ) ) {
F_3 ( L_26 ) ;
V_47 = - 1 ;
goto V_122;
}
}
if ( ! F_71 ( & V_54 -> V_72 ) && ! V_54 -> V_133 )
F_72 ( V_2 -> V_19 ) ;
if ( V_112 ) {
union V_10 * V_11 ;
V_11 = malloc ( sizeof( V_11 -> V_134 ) + V_14 -> V_135 ) ;
if ( V_11 == NULL ) {
V_47 = - V_136 ;
goto V_122;
}
F_73 ( V_9 , V_11 ,
V_2 -> V_19 -> V_137 . V_83 ,
F_4 ,
V_14 ) ;
free ( V_11 ) ;
F_74 ( V_2 -> V_19 ) ;
}
if ( V_54 -> V_133 ) {
F_75 ( V_54 -> V_133 * 1000 ) ;
F_72 ( V_2 -> V_19 ) ;
}
V_59 = 1 ;
for (; ; ) {
unsigned long long V_138 = V_2 -> V_29 ;
if ( F_45 ( V_2 ) < 0 ) {
V_59 = 0 ;
V_47 = - 1 ;
goto V_122;
}
if ( V_139 ) {
V_139 = 0 ;
if ( ! V_58 )
F_21 ( V_2 ) ;
if ( V_58 ) {
F_3 ( L_27 ) ;
V_47 = - 1 ;
goto V_122;
}
}
if ( V_138 == V_2 -> V_29 ) {
if ( V_36 || V_114 )
break;
V_47 = F_76 ( V_2 -> V_19 , - 1 ) ;
if ( V_47 > 0 || ( V_47 < 0 && V_70 == V_140 ) )
V_47 = 0 ;
V_111 ++ ;
if ( F_77 ( V_2 -> V_19 , V_141 | V_142 ) == 0 )
V_114 = true ;
}
if ( V_36 && ! V_113 && ! F_71 ( & V_54 -> V_72 ) ) {
V_59 = 0 ;
F_78 ( V_2 -> V_19 ) ;
V_113 = true ;
}
}
V_59 = 0 ;
if ( V_112 && V_100 ) {
char V_61 [ V_143 ] ;
const char * V_144 = F_35 ( V_100 , V_61 , sizeof( V_61 ) ) ;
F_3 ( L_28 , V_144 ) ;
V_47 = - 1 ;
goto V_122;
}
if ( ! V_145 )
fprintf ( V_146 , L_29 , V_111 ) ;
V_122:
if ( V_112 ) {
int V_147 ;
if ( ! V_34 )
F_79 ( V_2 -> V_19 -> V_137 . V_83 , V_117 ) ;
F_80 ( & V_147 ) ;
if ( V_47 < 0 )
V_110 = V_47 ;
else if ( F_81 ( V_147 ) )
V_110 = F_82 ( V_147 ) ;
else if ( F_83 ( V_147 ) )
V_35 = F_84 ( V_147 ) ;
} else
V_110 = V_47 ;
V_2 -> V_29 = 0 ;
if ( ! V_47 )
F_50 ( V_2 ) ;
if ( ! V_47 && ! V_145 ) {
char V_29 [ 128 ] ;
if ( V_2 -> V_29 && ! V_2 -> V_54 . V_94 )
F_85 ( V_29 , sizeof( V_29 ) ,
L_30 V_148 L_31 , V_2 -> V_29 ) ;
else
V_29 [ 0 ] = '\0' ;
fprintf ( V_146 , L_32 ,
F_86 ( V_6 ) / 1024.0 / 1024.0 ,
V_6 -> V_149 , V_29 ) ;
}
V_121:
F_87 ( V_5 ) ;
return V_110 ;
}
static void F_88 ( void )
{
static const char * V_150 [ V_151 ] = { L_33 , L_34 , L_35 , L_36 } ;
F_22 ( L_37 , V_150 [ V_152 . V_153 ] ) ;
if ( V_152 . V_153 == V_154 )
F_22 ( L_38 ,
V_152 . V_155 ) ;
}
int F_89 ( const struct V_156 * V_157 ,
const char * V_158 ,
int V_159 )
{
int V_52 ;
struct V_66 * V_1 = (struct V_66 * ) V_157 -> V_160 ;
V_1 -> V_161 = true ;
V_152 . V_162 = ! V_159 ;
if ( V_159 ) {
V_152 . V_153 = V_163 ;
F_22 ( L_39 ) ;
return 0 ;
}
V_52 = F_90 ( V_158 , & V_152 ) ;
if ( ! V_52 ) {
if ( V_152 . V_153 == V_154 )
V_1 -> V_106 = true ;
F_88 () ;
}
return V_52 ;
}
int F_91 ( const struct V_156 * V_157 ,
const char * V_158 V_13 ,
int V_159 V_13 )
{
struct V_66 * V_1 = (struct V_66 * ) V_157 -> V_160 ;
V_1 -> V_161 = true ;
V_152 . V_162 = true ;
if ( V_152 . V_153 == V_163 )
V_152 . V_153 = V_164 ;
F_88 () ;
return 0 ;
}
static int F_92 ( const char * V_165 , const char * V_160 , void * V_166 )
{
struct V_1 * V_2 = V_166 ;
if ( ! strcmp ( V_165 , L_40 ) ) {
if ( ! strcmp ( V_160 , L_41 ) )
V_2 -> V_167 = false ;
else if ( ! strcmp ( V_160 , L_42 ) )
V_2 -> V_167 = true ;
else if ( ! strcmp ( V_160 , L_43 ) )
V_2 -> V_88 = true ;
else
return - 1 ;
return 0 ;
}
if ( ! strcmp ( V_165 , L_44 ) )
V_165 = L_45 ;
return F_93 ( V_165 , V_160 , V_166 ) ;
}
static int F_94 ( const struct V_156 * V_157 , const char * V_150 , int V_159 )
{
struct V_66 * V_54 = (struct V_66 * ) V_157 -> V_160 ;
const struct V_168 * V_169 ;
const char * V_170 = V_150 ;
if ( V_159 ) {
V_54 -> V_171 = 0 ;
return 0 ;
}
if ( ! V_150 )
return 0 ;
if ( V_54 -> V_171 )
return - 1 ;
V_54 -> V_171 = true ;
if ( sscanf ( V_150 , L_46 , & V_54 -> V_172 ) == 1 )
return 0 ;
if ( ! strncasecmp ( V_150 , L_47 , 6 ) )
V_150 += 6 ;
for ( V_169 = V_173 ; V_169 -> V_174 ; V_169 ++ ) {
if ( ! strcasecmp ( V_150 , V_169 -> V_174 ) ) {
V_54 -> V_172 = V_169 -> V_172 ;
return 0 ;
}
}
V_54 -> V_171 = false ;
F_30 ( L_48 , V_170 ) ;
return - 1 ;
}
static int F_95 ( const struct V_156 * V_157 ,
const char * V_150 ,
int V_159 V_13 )
{
struct V_66 * V_54 = V_157 -> V_160 ;
char * V_175 , * V_176 ;
unsigned int V_74 ;
int V_52 ;
if ( ! V_150 )
return - V_78 ;
V_175 = F_96 ( V_150 ) ;
if ( ! V_175 )
return - V_136 ;
V_176 = strchr ( V_175 , ',' ) ;
if ( V_176 )
* V_176 = '\0' ;
if ( * V_175 ) {
V_52 = F_97 ( & V_74 , V_175 ) ;
if ( V_52 )
goto V_177;
V_54 -> V_74 = V_74 ;
}
if ( ! V_176 ) {
V_52 = 0 ;
goto V_177;
}
V_52 = F_97 ( & V_74 , V_176 + 1 ) ;
if ( V_52 )
goto V_177;
V_54 -> V_75 = V_74 ;
V_177:
free ( V_175 ) ;
return V_52 ;
}
int F_98 ( int V_108 , const char * * V_109 , const char * T_9 V_13 )
{
int V_47 ;
struct V_1 * V_2 = & V_1 ;
char V_123 [ V_124 ] ;
#ifndef F_99
# define F_100 ( V_175 , T_10 , T_11 ) set_option_nobuild(record_options, s, l, "NO_LIBBPF=1", c)
F_100 ( '\0' , L_49 , true ) ;
F_100 ( '\0' , L_50 , true ) ;
# undef F_100
#endif
#ifndef F_101
# if ! F_102 ( V_178 )
# define F_103 "NO_DWARF=1"
# elif ! F_102 ( F_99 )
# define F_103 "NO_LIBBPF=1"
# else
# define F_103 "this architecture doesn't support BPF prologue"
# endif
# define F_100 ( V_175 , T_10 , T_11 ) set_option_nobuild(record_options, s, l, REASON, c)
F_100 ( '\0' , L_51 , true ) ;
# undef F_100
# undef F_103
#endif
V_2 -> V_19 = F_104 () ;
if ( V_2 -> V_19 == NULL )
return - V_136 ;
F_105 ( F_92 , V_2 ) ;
V_108 = F_106 ( V_108 , V_109 , V_179 , V_180 ,
V_181 ) ;
if ( ! V_108 && F_71 ( & V_2 -> V_54 . V_72 ) )
F_107 ( V_180 , V_179 ) ;
if ( V_182 && ! V_2 -> V_54 . V_72 . V_183 ) {
F_108 ( V_180 , V_179 ,
L_52 ) ;
}
if ( V_2 -> V_54 . V_184 &&
! F_109 () ) {
F_32 ( L_53 ) ;
F_110 ( V_180 , V_179 , L_54 , 0 ) ;
return - V_78 ;
}
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = F_111 ( V_2 -> V_19 , & V_47 ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_112 ( V_2 -> V_53 , & V_2 -> V_54 ,
V_2 -> V_54 . V_185 ) ;
if ( V_47 )
return V_47 ;
V_47 = - V_136 ;
F_113 ( NULL ) ;
if ( V_80 . V_186 )
F_67 (
L_55
L_56
L_57
L_58
L_59
L_60
L_61 ) ;
if ( V_2 -> V_167 || V_2 -> V_88 )
F_114 () ;
if ( V_2 -> V_19 -> V_187 == 0 &&
F_115 ( V_2 -> V_19 ) < 0 ) {
F_3 ( L_62 ) ;
goto V_188;
}
if ( V_2 -> V_54 . V_72 . V_189 && ! V_2 -> V_54 . V_190 )
V_2 -> V_54 . V_191 = true ;
V_47 = F_116 ( & V_2 -> V_54 . V_72 ) ;
if ( V_47 ) {
F_117 ( & V_2 -> V_54 . V_72 , V_47 , V_123 , V_124 ) ;
F_30 ( L_63 , V_123 ) ;
}
V_47 = F_118 ( & V_2 -> V_54 . V_72 ) ;
if ( V_47 ) {
int V_192 = V_70 ;
F_117 ( & V_2 -> V_54 . V_72 , V_47 , V_123 , V_124 ) ;
F_32 ( L_63 , V_123 ) ;
V_47 = - V_192 ;
goto V_188;
}
V_47 = - V_136 ;
if ( F_119 ( V_2 -> V_19 , & V_2 -> V_54 . V_72 ) < 0 )
F_107 ( V_180 , V_179 ) ;
V_47 = F_120 ( V_2 -> V_53 , V_2 -> V_19 , & V_2 -> V_54 ) ;
if ( V_47 )
goto V_188;
if ( V_2 -> V_54 . V_94 )
V_2 -> V_82 = true ;
if ( F_121 ( & V_2 -> V_54 ) ) {
V_47 = - V_78 ;
goto V_188;
}
V_47 = F_61 ( & V_1 , V_108 , V_109 ) ;
V_188:
F_122 ( V_2 -> V_19 ) ;
F_123 () ;
F_124 ( V_2 -> V_53 ) ;
return V_47 ;
}
static void V_119 ( int V_32 V_13 )
{
if ( ! V_59 )
return;
V_59 = 0 ;
V_58 = F_24 ( V_1 . V_53 ) ;
V_139 = 1 ;
}
