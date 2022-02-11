static inline void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 )
{
V_2 -> V_5 = V_3 -> V_5 - V_4 -> V_5 ;
if ( V_3 -> V_6 < V_4 -> V_6 ) {
V_2 -> V_6 = V_3 -> V_6 + 1000000000L - V_4 -> V_6 ;
V_2 -> V_5 -- ;
} else {
V_2 -> V_6 = V_3 -> V_6 - V_4 -> V_6 ;
}
}
static void F_2 ( void )
{
F_3 ( V_7 ) ;
F_4 () ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
if ( V_12 . V_13 )
V_11 -> V_14 = V_15 |
V_16 ;
V_11 -> V_17 = ! V_18 ;
V_11 -> V_19 = 0 ;
if ( ! ( V_20 && V_21 . V_22 . V_23 ) )
V_11 -> V_24 = V_25 ;
if ( F_6 ( V_9 ) ) {
V_11 -> V_26 = 1 ;
if ( F_7 ( & V_27 ) && ! V_28 )
V_11 -> V_29 = 1 ;
}
if ( F_8 ( & V_27 ) )
return F_9 ( V_9 , F_10 ( V_9 ) ) ;
return F_11 ( V_9 , V_7 -> V_30 ) ;
}
static inline int F_12 ( struct V_8 * V_9 )
{
if ( F_13 ( V_9 , V_31 , V_32 ) ||
F_13 ( V_9 , V_31 , V_33 ) )
return 1 ;
return 0 ;
}
static int F_14 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_38 * T_2 V_35 ,
struct V_39 * V_39 V_35 )
{
if ( F_15 ( & V_21 . V_22 , V_37 , V_37 -> V_40 . V_41 ) < 0 ) {
F_16 ( L_1 ) ;
return - 1 ;
}
V_21 . V_42 += V_37 -> V_40 . V_41 ;
return 0 ;
}
static int F_17 ( T_3 V_43 , T_3 type )
{
return F_18 ( NULL , V_43 , type ,
F_14 ,
NULL ) ;
}
static int
F_19 ( struct V_8 * V_44 , T_4 V_45 , T_4 V_46 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 = F_20 ( V_44 , V_45 , V_46 ) ;
return F_21 ( NULL , V_45 , V_46 , V_50 -> V_51 , V_48 ,
F_14 , NULL ) ;
}
static int F_22 ( struct V_8 * V_44 )
{
int V_52 = F_23 ( V_7 -> V_30 ) ;
int V_53 = F_24 ( V_44 ) ;
int V_45 , V_46 ;
if ( ! V_44 -> V_54 )
return - V_55 ;
if ( V_44 -> V_56 )
V_52 = 1 ;
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ ) {
struct V_47 * V_48 ;
V_48 = F_25 ( V_44 -> V_57 , V_45 , V_46 ) ;
if ( F_26 ( V_44 , V_45 , V_46 , V_48 ) )
return - 1 ;
if ( V_20 ) {
if ( F_19 ( V_44 , V_45 , V_46 , V_48 ) ) {
F_16 ( L_2 ) ;
return - 1 ;
}
}
}
}
return 0 ;
}
static void F_27 ( bool V_58 )
{
struct V_8 * V_44 ;
F_28 (evsel_list, counter) {
if ( F_22 ( V_44 ) )
F_29 ( L_3 , V_44 -> V_59 ) ;
if ( F_30 ( & V_12 , V_44 ) )
F_31 ( L_4 , V_44 -> V_59 ) ;
if ( V_58 ) {
F_32 ( V_44 , F_24 ( V_44 ) ,
F_23 ( V_7 -> V_30 ) ) ;
}
}
}
static void F_33 ( void )
{
struct V_1 V_60 , V_61 ;
F_27 ( false ) ;
F_34 ( V_62 , & V_60 ) ;
F_1 ( & V_61 , & V_60 , & V_63 ) ;
if ( V_20 ) {
if ( F_35 ( V_61 . V_5 * V_64 + V_61 . V_6 , V_65 ) )
F_16 ( L_5 ) ;
}
F_36 ( & V_61 , 0 , NULL ) ;
}
static void F_37 ( void )
{
if ( V_28 )
F_38 ( V_28 * 1000 ) ;
if ( ! F_7 ( & V_27 ) || V_28 )
F_39 ( V_7 ) ;
}
static void F_40 ( int T_5 V_35 , T_6 * V_66 ,
void * T_7 V_35 )
{
V_67 = V_66 -> V_68 . V_69 ;
}
static bool F_41 ( struct V_8 * V_44 )
{
return V_44 -> V_70 && * V_44 -> V_70 ;
}
static bool F_42 ( struct V_8 * V_44 )
{
return V_44 -> V_13 != 1 ;
}
static int F_43 ( bool V_23 )
{
struct V_8 * V_44 ;
int V_71 ;
if ( V_23 ) {
V_71 = F_44 ( NULL , V_21 . V_72 ,
F_14 ) ;
if ( V_71 < 0 ) {
F_16 ( L_6 ) ;
return V_71 ;
}
}
F_28 (evsel_list, counter) {
if ( ! V_44 -> V_54 )
continue;
if ( F_41 ( V_44 ) ) {
V_71 = F_45 ( NULL , V_44 , F_14 ) ;
if ( V_71 < 0 ) {
F_16 ( L_7 ) ;
return V_71 ;
}
}
if ( F_42 ( V_44 ) ) {
V_71 = F_46 ( NULL , V_44 , F_14 ) ;
if ( V_71 < 0 ) {
F_16 ( L_8 ) ;
return V_71 ;
}
}
if ( V_44 -> V_73 ) {
V_71 = F_47 ( NULL , V_44 , F_14 ) ;
if ( V_71 < 0 ) {
F_16 ( L_8 ) ;
return V_71 ;
}
}
if ( V_23 ) {
V_71 = F_48 ( NULL , V_44 , F_14 ) ;
if ( V_71 < 0 ) {
F_16 ( L_9 ) ;
return V_71 ;
}
}
}
V_71 = F_49 ( NULL , V_7 -> V_30 ,
F_14 ,
NULL ) ;
if ( V_71 < 0 ) {
F_16 ( L_10 ) ;
return V_71 ;
}
V_71 = F_50 ( NULL , V_7 -> V_74 ,
F_14 , NULL ) ;
if ( V_71 < 0 ) {
F_16 ( L_10 ) ;
return V_71 ;
}
V_71 = F_51 ( NULL , & V_12 ,
F_14 , NULL ) ;
if ( V_71 < 0 ) {
F_16 ( L_11 ) ;
return V_71 ;
}
return 0 ;
}
static int F_52 ( struct V_8 * V_44 ,
struct V_75 * V_74 ,
struct V_76 * V_30 )
{
int V_45 , V_46 ;
for ( V_45 = 0 ; V_45 < V_74 -> V_77 ; V_45 ++ ) {
for ( V_46 = 0 ; V_46 < V_30 -> V_77 ; V_46 ++ ) {
int V_78 = F_53 ( V_44 , V_45 , V_46 ) ;
if ( F_54 ( V_7 , V_44 ,
V_45 , V_46 , V_78 ) < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_55 ( struct V_8 * V_44 )
{
struct V_75 * V_74 = V_44 -> V_74 ;
struct V_76 * V_30 = V_44 -> V_30 ;
if ( F_56 ( V_44 , V_74 -> V_77 , V_30 -> V_77 ) )
return - V_79 ;
return F_52 ( V_44 , V_74 , V_30 ) ;
}
static int F_57 ( int V_80 , const char * * V_81 )
{
int V_82 = V_12 . V_82 ;
char V_83 [ 512 ] ;
unsigned long long V_84 , V_85 ;
struct V_8 * V_44 ;
struct V_1 V_60 ;
T_8 V_86 ;
int V_87 = 0 ;
const bool V_88 = ( V_80 > 0 ) ;
bool V_23 = V_20 ? V_21 . V_22 . V_23 : false ;
if ( V_82 ) {
V_60 . V_5 = V_82 / 1000 ;
V_60 . V_6 = ( V_82 % 1000 ) * 1000000 ;
} else {
V_60 . V_5 = 1 ;
V_60 . V_6 = 0 ;
}
if ( V_88 ) {
if ( F_58 ( V_7 , & V_27 , V_81 , V_23 ,
F_40 ) < 0 ) {
perror ( L_12 ) ;
return - 1 ;
}
V_89 = V_7 -> V_90 . V_91 ;
}
if ( V_92 )
F_59 ( V_7 ) ;
F_28 (evsel_list, counter) {
if ( F_5 ( V_44 ) < 0 ) {
if ( V_93 == V_94 || V_93 == V_95 ||
V_93 == V_55 || V_93 == V_96 ||
V_93 == V_97 ) {
if ( V_98 )
F_60 ( L_13 ,
F_61 ( V_44 ) ) ;
V_44 -> V_54 = false ;
if ( ( V_44 -> V_99 != V_44 ) ||
! ( V_44 -> V_99 -> V_100 > 1 ) )
continue;
}
F_62 ( V_44 , & V_27 ,
V_93 , V_83 , sizeof( V_83 ) ) ;
F_63 ( L_14 , V_83 ) ;
if ( V_89 != - 1 )
F_64 ( V_89 , V_101 ) ;
return - 1 ;
}
V_44 -> V_54 = true ;
V_86 = strlen ( V_44 -> V_70 ) ;
if ( V_86 > V_102 )
V_102 = V_86 ;
if ( V_20 && F_55 ( V_44 ) )
return - 1 ;
}
if ( F_65 ( V_7 , & V_44 ) ) {
error ( L_15 ,
V_44 -> V_103 , F_61 ( V_44 ) , V_93 ,
F_66 ( V_93 , V_83 , sizeof( V_83 ) ) ) ;
return - 1 ;
}
if ( V_20 ) {
int V_71 , V_78 = F_67 ( & V_21 . V_22 ) ;
if ( V_23 ) {
V_71 = F_68 ( F_67 ( & V_21 . V_22 ) ) ;
} else {
V_71 = F_69 ( V_21 . V_72 , V_7 ,
V_78 , false ) ;
}
if ( V_71 < 0 )
return V_71 ;
V_71 = F_43 ( V_23 ) ;
if ( V_71 < 0 )
return V_71 ;
}
V_84 = F_70 () ;
F_34 ( V_62 , & V_63 ) ;
if ( V_88 ) {
F_71 ( V_7 ) ;
F_37 () ;
if ( V_82 ) {
while ( ! F_72 ( V_89 , & V_87 , V_104 ) ) {
F_73 ( & V_60 , NULL ) ;
F_33 () ;
}
}
F_74 ( & V_87 ) ;
if ( V_67 ) {
const char * V_105 = F_66 ( V_67 , V_83 , sizeof( V_83 ) ) ;
F_16 ( L_16 , V_105 ) ;
return - 1 ;
}
if ( F_75 ( V_87 ) )
F_76 ( F_77 ( V_87 ) , V_81 [ 0 ] ) ;
} else {
F_37 () ;
while ( ! V_106 ) {
F_73 ( & V_60 , NULL ) ;
if ( V_82 )
F_33 () ;
}
}
V_85 = F_70 () ;
F_78 ( & V_107 , V_85 - V_84 ) ;
F_27 ( true ) ;
return F_79 ( V_87 ) ;
}
static int F_80 ( int V_80 , const char * * V_81 )
{
int V_108 ;
if ( V_109 ) {
V_108 = system ( V_109 ) ;
if ( V_108 )
return V_108 ;
}
if ( V_110 )
F_81 () ;
V_108 = F_57 ( V_80 , V_81 ) ;
if ( V_108 )
return V_108 ;
if ( V_111 ) {
V_108 = system ( V_111 ) ;
if ( V_108 )
return V_108 ;
}
return V_108 ;
}
static void F_82 ( T_3 V_112 , T_3 V_113 )
{
if ( V_114 ) {
fprintf ( V_12 . V_115 , L_17 V_116 L_18 ,
V_117 ,
V_112 ,
V_117 ,
V_113 ? 100.0 * V_112 / V_113 : 100.0 ) ;
} else if ( V_112 != V_113 ) {
fprintf ( V_12 . V_115 , L_19 , 100.0 * V_112 / V_113 ) ;
}
}
static void F_83 ( double V_118 , double V_119 )
{
double V_120 = F_84 ( V_118 , V_119 ) ;
if ( V_114 )
fprintf ( V_12 . V_115 , L_20 , V_117 , V_120 ) ;
else if ( V_120 )
fprintf ( V_12 . V_115 , L_21 , V_120 ) ;
}
static void F_85 ( struct V_8 * V_9 , double V_119 )
{
struct V_121 * V_122 ;
if ( V_123 == 1 )
return;
V_122 = V_9 -> V_124 ;
F_83 ( F_86 ( & V_122 -> V_125 [ 0 ] ) , V_119 ) ;
}
static void F_87 ( struct V_8 * V_9 , int V_51 , int V_77 )
{
switch ( V_12 . V_126 ) {
case V_127 :
fprintf ( V_12 . V_115 , L_22 ,
F_88 ( V_51 ) ,
V_114 ? 0 : - 8 ,
F_89 ( V_51 ) ,
V_117 ,
V_114 ? 0 : 4 ,
V_77 ,
V_117 ) ;
break;
case V_128 :
fprintf ( V_12 . V_115 , L_23 ,
V_114 ? 0 : - 5 ,
V_51 ,
V_117 ,
V_114 ? 0 : 4 ,
V_77 ,
V_117 ) ;
break;
case V_129 :
fprintf ( V_12 . V_115 , L_24 ,
V_114 ? 0 : - 4 ,
F_10 ( V_9 ) -> V_130 [ V_51 ] , V_117 ) ;
break;
case V_131 :
fprintf ( V_12 . V_115 , L_25 ,
V_114 ? 0 : 16 ,
F_90 ( V_9 -> V_30 , V_51 ) ,
V_114 ? 0 : - 8 ,
F_91 ( V_9 -> V_30 , V_51 ) ,
V_117 ) ;
break;
case V_132 :
case V_133 :
default:
break;
}
}
static void F_92 ( int V_51 , int V_77 , struct V_8 * V_9 , double V_119 )
{
T_9 * V_115 = V_12 . V_115 ;
double V_134 = V_119 / 1e6 ;
const char * V_135 , * V_136 ;
char V_59 [ 25 ] ;
V_135 = V_114 ? L_26 : L_27 ;
V_136 = V_114 ? L_28 : L_29 ;
F_87 ( V_9 , V_51 , V_77 ) ;
F_93 ( V_59 , sizeof( V_59 ) , L_30 ,
F_61 ( V_9 ) , V_114 ? L_31 : L_32 ) ;
fprintf ( V_115 , V_135 , V_134 , V_117 ) ;
if ( V_114 )
fprintf ( V_115 , L_30 , V_9 -> V_70 , V_117 ) ;
else
fprintf ( V_115 , L_33 , V_102 , V_9 -> V_70 , V_117 ) ;
fprintf ( V_115 , V_136 , V_59 ) ;
if ( V_9 -> V_137 )
fprintf ( V_115 , L_30 , V_117 , V_9 -> V_137 -> V_59 ) ;
}
static void F_94 ( int V_51 , int V_77 , struct V_8 * V_9 , double V_119 )
{
T_9 * V_115 = V_12 . V_115 ;
double V_138 = V_9 -> V_13 ;
const char * V_139 ;
if ( V_114 ) {
V_139 = V_138 != 1.0 ? L_34 : L_35 ;
} else {
if ( V_140 )
V_139 = V_138 != 1.0 ? L_36 : L_37 ;
else
V_139 = V_138 != 1.0 ? L_38 : L_39 ;
}
F_87 ( V_9 , V_51 , V_77 ) ;
fprintf ( V_115 , V_139 , V_119 , V_117 ) ;
if ( V_9 -> V_70 )
fprintf ( V_115 , L_33 ,
V_114 ? 0 : V_102 ,
V_9 -> V_70 , V_117 ) ;
fprintf ( V_115 , L_40 , V_114 ? 0 : 25 , F_61 ( V_9 ) ) ;
if ( V_9 -> V_137 )
fprintf ( V_115 , L_30 , V_117 , V_9 -> V_137 -> V_59 ) ;
}
static void F_95 ( int V_51 , int V_77 , struct V_8 * V_44 , double V_141 )
{
int V_45 = F_89 ( V_51 ) ;
if ( V_12 . V_126 == V_132 )
V_45 = 0 ;
if ( F_12 ( V_44 ) )
F_92 ( V_51 , V_77 , V_44 , V_141 ) ;
else
F_94 ( V_51 , V_77 , V_44 , V_141 ) ;
if ( ! V_114 && ! V_12 . V_82 )
F_96 ( V_12 . V_115 , V_44 ,
V_141 , V_45 ,
V_12 . V_126 ) ;
}
static void F_97 ( char * V_142 )
{
T_9 * V_115 = V_12 . V_115 ;
struct V_8 * V_44 ;
int V_45 , V_143 , V_144 , V_51 , V_77 ;
double V_141 ;
T_3 V_113 , V_112 , V_145 ;
if ( ! ( V_146 || V_147 ) )
return;
for ( V_143 = 0 ; V_143 < V_146 -> V_77 ; V_143 ++ ) {
V_51 = V_146 -> V_130 [ V_143 ] ;
F_28 (evsel_list, counter) {
V_145 = V_113 = V_112 = 0 ;
V_77 = 0 ;
for ( V_45 = 0 ; V_45 < F_24 ( V_44 ) ; V_45 ++ ) {
V_144 = V_147 ( F_10 ( V_44 ) , V_45 ) ;
if ( V_144 != V_51 )
continue;
V_145 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_145 ;
V_113 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_113 ;
V_112 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_112 ;
V_77 ++ ;
}
if ( V_142 )
fprintf ( V_115 , L_28 , V_142 ) ;
if ( V_112 == 0 || V_113 == 0 ) {
F_87 ( V_44 , V_51 , V_77 ) ;
fprintf ( V_115 , L_41 ,
V_114 ? 0 : 18 ,
V_44 -> V_54 ? V_148 : V_149 ,
V_117 ) ;
fprintf ( V_115 , L_33 ,
V_114 ? 0 : V_102 ,
V_44 -> V_70 , V_117 ) ;
fprintf ( V_115 , L_42 ,
V_114 ? 0 : - 25 ,
F_61 ( V_44 ) ) ;
if ( V_44 -> V_137 )
fprintf ( V_115 , L_30 ,
V_117 , V_44 -> V_137 -> V_59 ) ;
F_82 ( V_112 , V_113 ) ;
fputc ( '\n' , V_115 ) ;
continue;
}
V_141 = V_145 * V_44 -> V_13 ;
F_95 ( V_51 , V_77 , V_44 , V_141 ) ;
if ( ! V_114 )
F_85 ( V_44 , 1.0 ) ;
F_82 ( V_112 , V_113 ) ;
fputc ( '\n' , V_115 ) ;
}
}
}
static void F_98 ( struct V_8 * V_44 , char * V_142 )
{
T_9 * V_115 = V_12 . V_115 ;
int V_52 = F_23 ( V_44 -> V_30 ) ;
int V_53 = F_99 ( V_44 -> V_74 ) ;
int V_45 , V_46 ;
double V_141 ;
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
T_3 V_113 = 0 , V_112 = 0 , V_145 = 0 ;
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ ) {
V_145 += F_25 ( V_44 -> V_57 , V_45 , V_46 ) -> V_145 ;
V_113 += F_25 ( V_44 -> V_57 , V_45 , V_46 ) -> V_113 ;
V_112 += F_25 ( V_44 -> V_57 , V_45 , V_46 ) -> V_112 ;
}
if ( V_142 )
fprintf ( V_115 , L_28 , V_142 ) ;
V_141 = V_145 * V_44 -> V_13 ;
F_95 ( V_46 , 0 , V_44 , V_141 ) ;
if ( ! V_114 )
F_85 ( V_44 , 1.0 ) ;
F_82 ( V_112 , V_113 ) ;
fputc ( '\n' , V_115 ) ;
}
}
static void F_100 ( struct V_8 * V_44 , char * V_142 )
{
T_9 * V_115 = V_12 . V_115 ;
struct V_121 * V_122 = V_44 -> V_124 ;
double V_119 = F_101 ( & V_122 -> V_125 [ 0 ] ) ;
int V_150 = V_44 -> V_57 -> V_150 ;
double V_141 ;
double V_151 , V_152 ;
V_151 = F_101 ( & V_122 -> V_125 [ 1 ] ) ;
V_152 = F_101 ( & V_122 -> V_125 [ 2 ] ) ;
if ( V_142 )
fprintf ( V_115 , L_28 , V_142 ) ;
if ( V_150 == - 1 || ! V_44 -> V_54 ) {
fprintf ( V_115 , L_41 ,
V_114 ? 0 : 18 ,
V_44 -> V_54 ? V_148 : V_149 ,
V_117 ) ;
fprintf ( V_115 , L_33 ,
V_114 ? 0 : V_102 ,
V_44 -> V_70 , V_117 ) ;
fprintf ( V_115 , L_42 ,
V_114 ? 0 : - 25 ,
F_61 ( V_44 ) ) ;
if ( V_44 -> V_137 )
fprintf ( V_115 , L_30 , V_117 , V_44 -> V_137 -> V_59 ) ;
F_82 ( V_152 , V_151 ) ;
fputc ( '\n' , V_115 ) ;
return;
}
V_141 = V_119 * V_44 -> V_13 ;
F_95 ( - 1 , 0 , V_44 , V_141 ) ;
F_85 ( V_44 , V_119 ) ;
F_82 ( V_152 , V_151 ) ;
fprintf ( V_115 , L_43 ) ;
}
static void F_102 ( struct V_8 * V_44 , char * V_142 )
{
T_9 * V_115 = V_12 . V_115 ;
T_3 V_113 , V_112 , V_145 ;
double V_141 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < F_24 ( V_44 ) ; V_45 ++ ) {
V_145 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_145 ;
V_113 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_113 ;
V_112 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_112 ;
if ( V_142 )
fprintf ( V_115 , L_28 , V_142 ) ;
if ( V_112 == 0 || V_113 == 0 ) {
fprintf ( V_115 , L_44 ,
V_114 ? 0 : - 4 ,
F_10 ( V_44 ) -> V_130 [ V_45 ] , V_117 ,
V_114 ? 0 : 18 ,
V_44 -> V_54 ? V_148 : V_149 ,
V_117 ) ;
fprintf ( V_115 , L_33 ,
V_114 ? 0 : V_102 ,
V_44 -> V_70 , V_117 ) ;
fprintf ( V_115 , L_42 ,
V_114 ? 0 : - 25 ,
F_61 ( V_44 ) ) ;
if ( V_44 -> V_137 )
fprintf ( V_115 , L_30 ,
V_117 , V_44 -> V_137 -> V_59 ) ;
F_82 ( V_112 , V_113 ) ;
fputc ( '\n' , V_115 ) ;
continue;
}
V_141 = V_145 * V_44 -> V_13 ;
F_95 ( V_45 , 0 , V_44 , V_141 ) ;
if ( ! V_114 )
F_85 ( V_44 , 1.0 ) ;
F_82 ( V_112 , V_113 ) ;
fputc ( '\n' , V_115 ) ;
}
}
static void F_103 ( char * V_142 , struct V_1 * V_60 )
{
T_9 * V_115 = V_12 . V_115 ;
static int V_153 ;
sprintf ( V_142 , L_45 , V_60 -> V_5 , V_60 -> V_6 , V_117 ) ;
if ( V_153 == 0 && ! V_114 ) {
switch ( V_12 . V_126 ) {
case V_128 :
fprintf ( V_115 , L_46 , V_102 , L_47 ) ;
break;
case V_127 :
fprintf ( V_115 , L_48 , V_102 , L_47 ) ;
break;
case V_129 :
fprintf ( V_115 , L_49 , V_102 , L_47 ) ;
break;
case V_131 :
fprintf ( V_115 , L_50 , V_102 , L_47 ) ;
break;
case V_132 :
default:
fprintf ( V_115 , L_51 , V_102 , L_47 ) ;
case V_133 :
break;
}
}
if ( ++ V_153 == 25 )
V_153 = 0 ;
}
static void F_104 ( int V_80 , const char * * V_81 )
{
T_9 * V_115 = V_12 . V_115 ;
int V_154 ;
fflush ( stdout ) ;
if ( ! V_114 ) {
fprintf ( V_115 , L_43 ) ;
fprintf ( V_115 , L_52 ) ;
if ( V_27 . V_56 )
fprintf ( V_115 , L_53 ) ;
else if ( V_27 . V_155 )
fprintf ( V_115 , L_54 , V_27 . V_155 ) ;
else if ( ! F_105 ( & V_27 ) ) {
fprintf ( V_115 , L_55 , V_81 ? V_81 [ 0 ] : L_56 ) ;
for ( V_154 = 1 ; V_81 && ( V_154 < V_80 ) ; V_154 ++ )
fprintf ( V_115 , L_57 , V_81 [ V_154 ] ) ;
} else if ( V_27 . V_91 )
fprintf ( V_115 , L_58 , V_27 . V_91 ) ;
else
fprintf ( V_115 , L_59 , V_27 . V_156 ) ;
fprintf ( V_115 , L_60 ) ;
if ( V_123 > 1 )
fprintf ( V_115 , L_61 , V_123 ) ;
fprintf ( V_115 , L_62 ) ;
}
}
static void F_106 ( void )
{
T_9 * V_115 = V_12 . V_115 ;
if ( ! V_157 )
fprintf ( V_115 , L_43 ) ;
fprintf ( V_115 , L_63 ,
F_101 ( & V_107 ) / 1e9 ) ;
if ( V_123 > 1 ) {
fprintf ( V_115 , L_64 ) ;
F_83 ( F_86 ( & V_107 ) ,
F_101 ( & V_107 ) ) ;
}
fprintf ( V_115 , L_65 ) ;
}
static void F_36 ( struct V_1 * V_60 , int V_80 , const char * * V_81 )
{
int V_82 = V_12 . V_82 ;
struct V_8 * V_44 ;
char V_158 [ 64 ] , * V_142 = NULL ;
if ( V_20 && V_21 . V_22 . V_23 )
return;
if ( V_82 )
F_103 ( V_142 = V_158 , V_60 ) ;
else
F_104 ( V_80 , V_81 ) ;
switch ( V_12 . V_126 ) {
case V_127 :
case V_128 :
F_97 ( V_142 ) ;
break;
case V_131 :
F_28 (evsel_list, counter)
F_98 ( V_44 , V_142 ) ;
break;
case V_132 :
F_28 (evsel_list, counter)
F_100 ( V_44 , V_142 ) ;
break;
case V_129 :
F_28 (evsel_list, counter)
F_102 ( V_44 , V_142 ) ;
break;
case V_133 :
default:
break;
}
if ( ! V_82 && ! V_114 )
F_106 () ;
fflush ( V_12 . V_115 ) ;
}
static void F_107 ( int T_5 )
{
if ( ( V_89 == - 1 ) || V_12 . V_82 )
V_106 = 1 ;
V_159 = T_5 ;
V_89 = - 1 ;
}
static void F_108 ( void )
{
T_10 V_160 , V_161 ;
F_109 ( & V_160 ) ;
F_110 ( & V_160 , V_162 ) ;
F_111 ( V_163 , & V_160 , & V_161 ) ;
if ( V_89 != - 1 )
F_64 ( V_89 , V_101 ) ;
F_111 ( V_164 , & V_161 , NULL ) ;
if ( V_159 == - 1 )
return;
signal ( V_159 , V_165 ) ;
F_64 ( F_112 () , V_159 ) ;
}
static int F_113 ( const struct V_166 * T_11 V_35 ,
const char * V_143 V_35 , int V_167 )
{
V_168 = V_167 ? 0 : 1 ;
return 0 ;
}
static int F_114 ( struct V_75 * V_130 , int V_45 )
{
return F_115 ( V_130 , V_45 , NULL ) ;
}
static int F_116 ( struct V_75 * V_130 , int V_45 )
{
return F_117 ( V_130 , V_45 , NULL ) ;
}
static int F_118 ( struct V_75 * V_130 )
{
int V_154 , V_169 = - 1 ;
for ( V_154 = 0 ; V_154 < V_130 -> V_77 ; V_154 ++ ) {
if ( V_130 -> V_130 [ V_154 ] > V_169 )
V_169 = V_130 -> V_130 [ V_154 ] ;
}
return V_169 ;
}
static int F_119 ( T_12 V_170 , struct V_75 * V_130 , int V_171 )
{
int V_45 ;
if ( V_171 >= V_130 -> V_77 )
return - 1 ;
V_45 = V_130 -> V_130 [ V_171 ] ;
if ( V_172 -> V_130 [ V_45 ] == - 1 )
V_172 -> V_130 [ V_45 ] = V_170 ( V_130 , V_171 ) ;
return V_172 -> V_130 [ V_45 ] ;
}
static int F_120 ( struct V_75 * V_130 , int V_171 )
{
return F_119 ( F_114 , V_130 , V_171 ) ;
}
static int F_121 ( struct V_75 * V_130 , int V_171 )
{
return F_119 ( F_116 , V_130 , V_171 ) ;
}
static int F_122 ( void )
{
int V_77 ;
switch ( V_12 . V_126 ) {
case V_128 :
if ( F_123 ( V_7 -> V_74 , & V_146 ) ) {
perror ( L_66 ) ;
return - 1 ;
}
V_147 = F_120 ;
break;
case V_127 :
if ( F_124 ( V_7 -> V_74 , & V_146 ) ) {
perror ( L_67 ) ;
return - 1 ;
}
V_147 = F_121 ;
break;
case V_129 :
case V_132 :
case V_131 :
case V_133 :
default:
break;
}
V_77 = F_118 ( V_7 -> V_74 ) ;
V_172 = F_125 ( V_77 + 1 ) ;
return V_172 ? 0 : - V_79 ;
}
static void F_126 ( void )
{
F_127 ( V_146 ) ;
F_127 ( V_172 ) ;
V_146 = NULL ;
V_172 = NULL ;
}
static inline int F_128 ( struct V_173 * V_174 , struct V_75 * V_130 , int V_171 )
{
int V_45 ;
if ( V_171 > V_130 -> V_77 )
return - 1 ;
V_45 = V_130 -> V_130 [ V_171 ] ;
if ( V_45 >= V_174 -> V_175 )
return - 1 ;
return V_45 ;
}
static int F_129 ( struct V_75 * V_130 , int V_171 , void * V_176 )
{
struct V_173 * V_174 = V_176 ;
int V_45 = F_128 ( V_174 , V_130 , V_171 ) ;
return V_45 == - 1 ? - 1 : V_174 -> V_45 [ V_45 ] . V_177 ;
}
static int F_130 ( struct V_75 * V_130 , int V_171 , void * V_176 )
{
struct V_173 * V_174 = V_176 ;
int V_178 = - 1 , V_45 = F_128 ( V_174 , V_130 , V_171 ) ;
if ( V_45 != - 1 ) {
int V_177 = V_174 -> V_45 [ V_45 ] . V_177 ;
V_178 = ( V_177 << 16 ) | ( V_174 -> V_45 [ V_45 ] . V_179 & 0xffff ) ;
}
return V_178 ;
}
static int F_131 ( struct V_173 * V_174 , struct V_75 * V_74 ,
struct V_75 * * V_180 )
{
return F_132 ( V_74 , V_180 , F_129 , V_174 ) ;
}
static int F_133 ( struct V_173 * V_174 , struct V_75 * V_74 ,
struct V_75 * * V_181 )
{
return F_132 ( V_74 , V_181 , F_130 , V_174 ) ;
}
static int F_134 ( struct V_75 * V_130 , int V_171 )
{
return F_129 ( V_130 , V_171 , & V_21 . V_72 -> V_40 . V_174 ) ;
}
static int F_135 ( struct V_75 * V_130 , int V_171 )
{
return F_130 ( V_130 , V_171 , & V_21 . V_72 -> V_40 . V_174 ) ;
}
static int F_136 ( struct V_21 * V_182 )
{
struct V_173 * V_174 = & V_182 -> V_72 -> V_40 . V_174 ;
switch ( V_12 . V_126 ) {
case V_128 :
if ( F_131 ( V_174 , V_7 -> V_74 , & V_146 ) ) {
perror ( L_66 ) ;
return - 1 ;
}
V_147 = F_134 ;
break;
case V_127 :
if ( F_133 ( V_174 , V_7 -> V_74 , & V_146 ) ) {
perror ( L_67 ) ;
return - 1 ;
}
V_147 = F_135 ;
break;
case V_129 :
case V_132 :
case V_131 :
case V_133 :
default:
break;
}
return 0 ;
}
static int F_137 ( void )
{
struct V_10 V_183 [] = {
{ . type = V_184 , . V_185 = V_186 } ,
{ . type = V_184 , . V_185 = V_187 } ,
{ . type = V_184 , . V_185 = V_188 } ,
{ . type = V_184 , . V_185 = V_189 } ,
{ . type = V_190 , . V_185 = V_191 } ,
{ . type = V_190 , . V_185 = V_192 } ,
{ . type = V_190 , . V_185 = V_193 } ,
{ . type = V_190 , . V_185 = V_194 } ,
{ . type = V_190 , . V_185 = V_195 } ,
{ . type = V_190 , . V_185 = V_196 } ,
} ;
struct V_10 V_197 [] = {
{ . type = V_198 ,
. V_185 =
V_199 << 0 |
( V_200 << 8 ) |
( V_201 << 16 ) } ,
{ . type = V_198 ,
. V_185 =
V_199 << 0 |
( V_200 << 8 ) |
( V_202 << 16 ) } ,
{ . type = V_198 ,
. V_185 =
V_203 << 0 |
( V_200 << 8 ) |
( V_201 << 16 ) } ,
{ . type = V_198 ,
. V_185 =
V_203 << 0 |
( V_200 << 8 ) |
( V_202 << 16 ) } ,
} ;
struct V_10 V_204 [] = {
{ . type = V_198 ,
. V_185 =
V_205 << 0 |
( V_200 << 8 ) |
( V_201 << 16 ) } ,
{ . type = V_198 ,
. V_185 =
V_205 << 0 |
( V_200 << 8 ) |
( V_202 << 16 ) } ,
{ . type = V_198 ,
. V_185 =
V_206 << 0 |
( V_200 << 8 ) |
( V_201 << 16 ) } ,
{ . type = V_198 ,
. V_185 =
V_206 << 0 |
( V_200 << 8 ) |
( V_202 << 16 ) } ,
{ . type = V_198 ,
. V_185 =
V_207 << 0 |
( V_200 << 8 ) |
( V_201 << 16 ) } ,
{ . type = V_198 ,
. V_185 =
V_207 << 0 |
( V_200 << 8 ) |
( V_202 << 16 ) } ,
} ;
struct V_10 V_208 [] = {
{ . type = V_198 ,
. V_185 =
V_199 << 0 |
( V_209 << 8 ) |
( V_201 << 16 ) } ,
{ . type = V_198 ,
. V_185 =
V_199 << 0 |
( V_209 << 8 ) |
( V_202 << 16 ) } ,
} ;
if ( V_157 )
return 0 ;
if ( V_210 ) {
int V_71 ;
if ( F_138 ( L_68 , L_69 ) &&
F_138 ( L_68 , L_70 ) )
V_71 = F_139 ( V_7 , V_211 , NULL ) ;
else
V_71 = F_139 ( V_7 , V_212 , NULL ) ;
if ( V_71 ) {
fprintf ( V_213 , L_71 ) ;
return - 1 ;
}
return 0 ;
}
if ( ! V_7 -> V_214 ) {
if ( F_140 ( V_7 , V_183 ) < 0 )
return - 1 ;
}
if ( V_215 < 1 )
return 0 ;
if ( F_140 ( V_7 , V_197 ) < 0 )
return - 1 ;
if ( V_215 < 2 )
return 0 ;
if ( F_140 ( V_7 , V_204 ) < 0 )
return - 1 ;
if ( V_215 < 3 )
return 0 ;
return F_140 ( V_7 , V_208 ) ;
}
static void F_141 ( struct V_216 * V_72 )
{
int V_217 ;
for ( V_217 = V_218 ; V_217 < V_219 ; V_217 ++ )
F_142 ( & V_72 -> V_40 , V_217 ) ;
F_143 ( & V_72 -> V_40 , V_220 ) ;
F_143 ( & V_72 -> V_40 , V_221 ) ;
F_143 ( & V_72 -> V_40 , V_222 ) ;
F_143 ( & V_72 -> V_40 , V_223 ) ;
}
static int F_144 ( int V_80 , const char * * V_81 )
{
struct V_216 * V_72 ;
struct V_224 * V_22 = & V_21 . V_22 ;
V_80 = F_145 ( V_80 , V_81 , V_225 , V_226 ,
V_227 ) ;
if ( V_228 )
V_22 -> V_229 = V_228 ;
if ( V_123 != 1 || V_230 ) {
F_16 ( L_72 ) ;
return - 1 ;
}
V_72 = F_146 ( V_22 , false , NULL ) ;
if ( V_72 == NULL ) {
F_16 ( L_73 ) ;
return - 1 ;
}
F_141 ( V_72 ) ;
V_72 -> V_231 = V_7 ;
V_21 . V_72 = V_72 ;
V_21 . V_232 = true ;
return V_80 ;
}
static int F_147 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_216 * V_72 )
{
struct V_233 * V_234 = & V_37 -> V_235 ;
struct V_8 * V_44 ;
struct V_1 V_236 , * V_60 = NULL ;
const char * * V_81 = V_72 -> V_40 . V_174 . V_237 ;
int V_80 = V_72 -> V_40 . V_174 . V_238 ;
F_28 (evsel_list, counter)
F_30 ( & V_12 , V_44 ) ;
if ( V_234 -> type == V_239 )
F_78 ( & V_107 , V_234 -> time ) ;
if ( V_12 . V_82 && V_234 -> time ) {
V_236 . V_5 = V_234 -> time / V_64 ;
V_236 . V_6 = V_234 -> time % V_64 ;
V_60 = & V_236 ;
}
F_36 ( V_60 , V_80 , V_81 ) ;
return 0 ;
}
static
int F_148 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_216 * V_72 V_35 )
{
struct V_21 * V_182 = F_149 ( T_1 , struct V_21 , T_1 ) ;
F_150 ( & V_12 , & V_37 -> V_12 ) ;
if ( F_151 ( V_182 -> V_74 ) ) {
if ( V_182 -> V_126 != V_133 )
F_31 ( L_74 ) ;
return 0 ;
}
if ( V_182 -> V_126 != V_133 )
V_12 . V_126 = V_182 -> V_126 ;
if ( V_21 . V_22 . V_23 )
F_122 () ;
else
F_136 ( V_182 ) ;
return 0 ;
}
static int F_152 ( struct V_21 * V_182 )
{
if ( ! V_182 -> V_74 || ! V_182 -> V_30 )
return 0 ;
if ( F_153 ( V_182 -> V_240 , L_75 ) )
return - V_94 ;
F_154 ( V_7 , V_182 -> V_74 , V_182 -> V_30 ) ;
if ( F_155 ( V_7 , true ) )
return - V_79 ;
V_182 -> V_240 = true ;
return 0 ;
}
static
int F_156 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_216 * V_72 V_35 )
{
struct V_21 * V_182 = F_149 ( T_1 , struct V_21 , T_1 ) ;
if ( V_182 -> V_30 ) {
F_31 ( L_76 ) ;
return 0 ;
}
V_182 -> V_30 = F_157 ( & V_37 -> V_76 ) ;
if ( ! V_182 -> V_30 )
return - V_79 ;
return F_152 ( V_182 ) ;
}
static
int F_158 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_216 * V_72 V_35 )
{
struct V_21 * V_182 = F_149 ( T_1 , struct V_21 , T_1 ) ;
struct V_75 * V_74 ;
if ( V_182 -> V_74 ) {
F_31 ( L_77 ) ;
return 0 ;
}
V_74 = F_159 ( & V_37 -> V_75 . V_176 ) ;
if ( ! V_74 )
return - V_79 ;
V_182 -> V_74 = V_74 ;
return F_152 ( V_182 ) ;
}
static int F_160 ( int V_80 , const char * * V_81 )
{
struct V_216 * V_72 ;
const struct V_166 V_241 [] = {
F_161 ( 'i' , L_78 , & V_242 , L_79 , L_80 ) ,
F_162 ( 0 , L_81 , & V_21 . V_126 ,
L_82 , V_128 ) ,
F_162 ( 0 , L_83 , & V_21 . V_126 ,
L_84 , V_127 ) ,
F_162 ( 'A' , L_85 , & V_21 . V_126 ,
L_86 , V_129 ) ,
F_163 ()
} ;
struct V_243 V_182 ;
int V_108 ;
V_80 = F_145 ( V_80 , V_81 , V_241 , V_244 , 0 ) ;
if ( ! V_242 || ! strlen ( V_242 ) ) {
if ( ! F_164 ( V_245 , & V_182 ) && F_165 ( V_182 . V_246 ) )
V_242 = L_87 ;
else
V_242 = L_88 ;
}
V_21 . V_22 . V_229 = V_242 ;
V_21 . V_22 . V_247 = V_248 ;
V_72 = F_146 ( & V_21 . V_22 , false , & V_21 . T_1 ) ;
if ( V_72 == NULL )
return - 1 ;
V_21 . V_72 = V_72 ;
V_12 . V_115 = V_213 ;
V_7 = V_72 -> V_231 ;
V_108 = F_166 ( V_72 ) ;
if ( V_108 )
return V_108 ;
F_167 ( V_72 ) ;
return 0 ;
}
int F_168 ( int V_80 , const char * * V_81 , const char * V_142 V_35 )
{
const char * const V_249 [] = {
L_89 ,
NULL
} ;
int V_87 = - V_94 , V_250 ;
const char * V_247 ;
T_9 * V_115 = V_213 ;
unsigned int V_82 ;
const char * const V_251 [] = { L_90 , L_91 } ;
setlocale ( V_252 , L_31 ) ;
V_7 = F_169 () ;
if ( V_7 == NULL )
return - V_79 ;
V_80 = F_170 ( V_80 , V_81 , V_225 , V_251 ,
( const char * * ) V_249 ,
V_227 ) ;
if ( V_117 ) {
V_114 = true ;
if ( ! strcmp ( V_117 , L_92 ) )
V_117 = L_93 ;
} else
V_117 = V_253 ;
if ( V_80 && ! strncmp ( V_81 [ 0 ] , L_94 , 3 ) ) {
V_80 = F_144 ( V_80 , V_81 ) ;
if ( V_80 < 0 )
return - 1 ;
} else if ( V_80 && ! strncmp ( V_81 [ 0 ] , L_95 , 3 ) )
return F_160 ( V_80 , V_81 ) ;
V_82 = V_12 . V_82 ;
if ( ! V_20 && V_228 && strcmp ( V_228 , L_87 ) )
V_115 = NULL ;
if ( V_228 && V_254 ) {
fprintf ( V_213 , L_96 ) ;
F_171 ( V_249 , V_225 , L_97 , 1 ) ;
F_171 ( NULL , V_225 , L_98 , 0 ) ;
goto V_255;
}
if ( V_254 < 0 ) {
fprintf ( V_213 , L_99 ) ;
F_171 ( V_249 , V_225 , L_98 , 0 ) ;
goto V_255;
}
if ( ! V_115 ) {
struct V_1 V_43 ;
V_247 = V_256 ? L_100 : L_101 ;
V_115 = fopen ( V_228 , V_247 ) ;
if ( ! V_115 ) {
perror ( L_102 ) ;
return - 1 ;
}
F_34 ( V_257 , & V_43 ) ;
fprintf ( V_115 , L_103 , ctime ( & V_43 . V_5 ) ) ;
} else if ( V_254 > 0 ) {
V_247 = V_256 ? L_100 : L_101 ;
V_115 = fdopen ( V_254 , V_247 ) ;
if ( ! V_115 ) {
perror ( L_104 ) ;
return - V_93 ;
}
}
V_12 . V_115 = V_115 ;
if ( V_114 ) {
if ( V_168 == 1 ) {
fprintf ( V_213 , L_105 ) ;
F_171 ( V_249 , V_225 , L_106 , 1 ) ;
F_171 ( NULL , V_225 , L_107 , 1 ) ;
goto V_255;
} else
V_140 = false ;
} else if ( V_168 == 0 )
V_140 = false ;
if ( ! V_80 && F_7 ( & V_27 ) )
F_172 ( V_249 , V_225 ) ;
if ( V_123 < 0 ) {
F_16 ( L_108 ) ;
F_171 ( V_249 , V_225 , L_109 , 1 ) ;
goto V_255;
} else if ( V_123 == 0 ) {
V_230 = true ;
V_123 = 1 ;
}
if ( ( V_12 . V_126 == V_131 ) && ! F_105 ( & V_27 ) ) {
fprintf ( V_213 , L_110
L_111 ) ;
F_171 ( NULL , V_225 , L_112 , 1 ) ;
F_171 ( NULL , V_225 , L_113 , 1 ) ;
goto V_255;
}
if ( ( ( V_12 . V_126 != V_132 &&
V_12 . V_126 != V_131 ) || V_258 ) &&
! F_8 ( & V_27 ) ) {
fprintf ( V_213 , L_114
L_115 ) ;
F_171 ( V_249 , V_225 , L_116 , 1 ) ;
F_171 ( NULL , V_225 , L_117 , 1 ) ;
F_171 ( NULL , V_225 , L_100 , 1 ) ;
goto V_255;
}
if ( F_137 () )
goto V_255;
F_173 ( & V_27 ) ;
if ( F_174 ( V_7 , & V_27 ) < 0 ) {
if ( F_105 ( & V_27 ) ) {
F_16 ( L_118 ) ;
F_171 ( V_249 , V_225 , L_112 , 1 ) ;
F_171 ( NULL , V_225 , L_113 , 1 ) ;
} else if ( F_8 ( & V_27 ) ) {
perror ( L_119 ) ;
F_171 ( V_249 , V_225 , L_120 , 1 ) ;
F_171 ( NULL , V_225 , L_100 , 1 ) ;
}
goto V_255;
}
if ( V_12 . V_126 == V_131 )
F_175 ( V_7 -> V_30 ) ;
if ( V_82 && V_82 < 100 ) {
if ( V_82 < 10 ) {
F_16 ( L_121 ) ;
F_171 ( V_249 , V_225 , L_122 , 1 ) ;
goto V_255;
} else
F_31 ( L_123
L_124
L_125 ) ;
}
if ( F_155 ( V_7 , V_82 ) )
goto V_255;
if ( F_122 () )
goto V_255;
atexit ( F_108 ) ;
if ( ! V_230 )
signal ( V_259 , F_107 ) ;
signal ( V_162 , F_107 ) ;
signal ( V_260 , F_107 ) ;
signal ( V_261 , F_107 ) ;
V_87 = 0 ;
for ( V_250 = 0 ; V_230 || V_250 < V_123 ; V_250 ++ ) {
if ( V_123 != 1 && V_98 )
fprintf ( V_115 , L_126 ,
V_250 + 1 ) ;
V_87 = F_80 ( V_80 , V_81 ) ;
if ( V_230 && V_87 != - 1 ) {
F_36 ( NULL , V_80 , V_81 ) ;
F_2 () ;
}
}
if ( ! V_230 && V_87 != - 1 && ! V_82 )
F_36 ( NULL , V_80 , V_81 ) ;
if ( V_20 ) {
int V_78 = F_67 ( & V_21 . V_22 ) ;
int V_71 = F_176 ( ( void * ) & V_21 ,
F_14 ,
& V_21 . V_72 -> V_262 . V_263 ) ;
if ( V_71 ) {
F_31 ( L_127
L_128 ) ;
}
if ( ! V_82 ) {
if ( F_35 ( V_107 . V_169 , V_264 ) )
F_16 ( L_5 ) ;
}
if ( ! V_21 . V_22 . V_23 ) {
V_21 . V_72 -> V_40 . V_265 += V_21 . V_42 ;
F_69 ( V_21 . V_72 , V_7 , V_78 , true ) ;
}
F_167 ( V_21 . V_72 ) ;
}
F_126 () ;
F_177 ( V_7 ) ;
V_255:
F_178 ( V_7 ) ;
return V_87 ;
}
