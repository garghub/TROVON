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
if ( V_12 )
V_11 -> V_13 = V_14 |
V_15 ;
V_11 -> V_16 = ! V_17 ;
if ( F_6 ( & V_18 ) )
return F_7 ( V_9 , F_8 ( V_9 ) ) ;
if ( ! F_9 ( & V_18 ) && F_10 ( V_9 ) ) {
V_11 -> V_19 = 1 ;
if ( ! V_20 )
V_11 -> V_21 = 1 ;
}
return F_11 ( V_9 , V_7 -> V_22 ) ;
}
static inline int F_12 ( struct V_8 * V_9 )
{
if ( F_13 ( V_9 , V_23 , V_24 ) ||
F_13 ( V_9 , V_23 , V_25 ) )
return 1 ;
return 0 ;
}
static void F_14 ( struct V_8 * V_26 )
{
if ( V_26 -> V_27 )
memset ( V_26 -> V_27 , 0 , V_28 ) ;
}
static int F_15 ( struct V_8 * V_26 , int V_29 , bool * V_30 )
{
unsigned long * V_31 = V_26 -> V_27 ;
struct V_32 * V_33 = F_8 ( V_26 ) ;
int V_34 ;
* V_30 = false ;
if ( ! V_26 -> V_35 )
return 0 ;
if ( F_16 ( V_33 ) )
return 0 ;
if ( ! V_31 ) {
V_31 = F_17 ( V_28 ) ;
if ( ! V_31 )
return - V_36 ;
V_26 -> V_27 = V_31 ;
}
V_34 = F_18 ( V_33 , V_29 ) ;
if ( V_34 < 0 )
return - 1 ;
* V_30 = F_19 ( V_34 , V_31 ) == 1 ;
return 0 ;
}
static int
F_20 ( struct V_8 * V_9 , int V_29 , int V_37 ,
struct V_38 * V_39 )
{
struct V_38 * V_40 = & V_9 -> V_41 -> V_40 ;
static struct V_38 V_42 ;
bool V_30 = false ;
if ( F_15 ( V_9 , V_29 , & V_30 ) ) {
F_21 ( L_1 ) ;
return - 1 ;
}
if ( V_30 )
V_39 = & V_42 ;
switch ( V_43 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
if ( ! V_9 -> V_48 )
F_22 ( V_9 , V_29 , V_37 , V_39 ) ;
F_23 ( V_39 , V_12 , NULL ) ;
if ( V_43 == V_47 )
F_24 ( V_9 , V_39 -> V_49 , V_29 ) ;
break;
case V_50 :
V_40 -> V_51 += V_39 -> V_51 ;
if ( V_12 ) {
V_40 -> V_52 += V_39 -> V_52 ;
V_40 -> V_53 += V_39 -> V_53 ;
}
default:
break;
}
return 0 ;
}
static int F_25 ( struct V_8 * V_26 )
{
int V_54 = F_26 ( V_26 -> V_22 ) ;
int V_55 = F_27 ( V_26 ) ;
int V_29 , V_37 ;
if ( V_26 -> V_56 )
V_54 = 1 ;
for ( V_37 = 0 ; V_37 < V_54 ; V_37 ++ ) {
for ( V_29 = 0 ; V_29 < V_55 ; V_29 ++ ) {
if ( F_20 ( V_26 , V_29 , V_37 ,
F_28 ( V_26 -> V_41 , V_29 , V_37 ) ) )
return - 1 ;
}
}
return 0 ;
}
static int F_29 ( struct V_8 * V_26 )
{
struct V_38 * V_40 = & V_26 -> V_41 -> V_40 ;
struct V_57 * V_58 = V_26 -> V_59 ;
T_1 * V_39 = V_26 -> V_41 -> V_40 . V_49 ;
int V_60 , V_61 ;
V_40 -> V_51 = V_40 -> V_52 = V_40 -> V_53 = 0 ;
F_30 ( V_58 -> V_62 ) ;
if ( V_26 -> V_35 )
F_14 ( V_26 ) ;
V_61 = F_25 ( V_26 ) ;
if ( V_61 )
return V_61 ;
if ( V_43 != V_50 )
return 0 ;
if ( ! V_26 -> V_48 )
F_22 ( V_26 , - 1 , - 1 , V_40 ) ;
F_23 ( V_40 , V_12 , & V_26 -> V_41 -> V_63 ) ;
for ( V_60 = 0 ; V_60 < 3 ; V_60 ++ )
F_31 ( & V_58 -> V_62 [ V_60 ] , V_39 [ V_60 ] ) ;
if ( V_64 ) {
fprintf ( V_65 , L_2 V_66 L_3 V_66 L_3 V_66 L_4 ,
F_32 ( V_26 ) , V_39 [ 0 ] , V_39 [ 1 ] , V_39 [ 2 ] ) ;
}
F_24 ( V_26 , V_39 , 0 ) ;
return 0 ;
}
static int F_33 ( struct V_8 * V_26 )
{
int V_54 = F_26 ( V_7 -> V_22 ) ;
int V_55 = F_27 ( V_26 ) ;
int V_29 , V_37 ;
if ( ! V_26 -> V_67 )
return - V_68 ;
if ( V_26 -> V_56 )
V_54 = 1 ;
for ( V_37 = 0 ; V_37 < V_54 ; V_37 ++ ) {
for ( V_29 = 0 ; V_29 < V_55 ; V_29 ++ ) {
struct V_38 * V_39 ;
V_39 = F_28 ( V_26 -> V_41 , V_29 , V_37 ) ;
if ( F_34 ( V_26 , V_29 , V_37 , V_39 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_35 ( bool V_69 )
{
struct V_8 * V_26 ;
F_36 (evsel_list, counter) {
if ( F_33 ( V_26 ) )
F_37 ( L_5 , V_26 -> V_70 ) ;
if ( F_29 ( V_26 ) )
F_37 ( L_6 , V_26 -> V_70 ) ;
if ( V_69 ) {
F_38 ( V_26 , F_27 ( V_26 ) ,
F_26 ( V_7 -> V_22 ) ) ;
}
}
}
static void F_39 ( void )
{
struct V_1 V_71 , V_72 ;
F_35 ( false ) ;
F_40 ( V_73 , & V_71 ) ;
F_1 ( & V_72 , & V_71 , & V_74 ) ;
F_41 ( & V_72 , 0 , NULL ) ;
}
static void F_42 ( void )
{
struct V_8 * V_26 ;
if ( V_20 ) {
const int V_55 = F_43 ( V_7 -> V_33 ) ,
V_54 = F_26 ( V_7 -> V_22 ) ;
F_44 ( V_20 * 1000 ) ;
F_36 (evsel_list, counter)
F_45 ( V_26 , V_55 , V_54 ) ;
}
}
static void F_46 ( int T_2 V_75 , T_3 * V_76 ,
void * T_4 V_75 )
{
V_77 = V_76 -> V_78 . V_79 ;
}
static int F_47 ( int V_80 , const char * * V_81 )
{
char V_82 [ 512 ] ;
unsigned long long V_83 , V_84 ;
struct V_8 * V_26 ;
struct V_1 V_71 ;
T_5 V_85 ;
int V_86 = 0 ;
const bool V_87 = ( V_80 > 0 ) ;
if ( V_88 ) {
V_71 . V_5 = V_88 / 1000 ;
V_71 . V_6 = ( V_88 % 1000 ) * 1000000 ;
} else {
V_71 . V_5 = 1 ;
V_71 . V_6 = 0 ;
}
if ( V_87 ) {
if ( F_48 ( V_7 , & V_18 , V_81 , false ,
F_46 ) < 0 ) {
perror ( L_7 ) ;
return - 1 ;
}
V_89 = V_7 -> V_90 . V_91 ;
}
if ( V_92 )
F_49 ( V_7 ) ;
F_36 (evsel_list, counter) {
if ( F_5 ( V_26 ) < 0 ) {
if ( V_93 == V_94 || V_93 == V_95 ||
V_93 == V_68 || V_93 == V_96 ||
V_93 == V_97 ) {
if ( V_64 )
F_50 ( L_8 ,
F_32 ( V_26 ) ) ;
V_26 -> V_67 = false ;
if ( ( V_26 -> V_98 != V_26 ) ||
! ( V_26 -> V_98 -> V_99 > 1 ) )
continue;
}
F_51 ( V_26 , & V_18 ,
V_93 , V_82 , sizeof( V_82 ) ) ;
F_52 ( L_9 , V_82 ) ;
if ( V_89 != - 1 )
F_53 ( V_89 , V_100 ) ;
return - 1 ;
}
V_26 -> V_67 = true ;
V_85 = strlen ( V_26 -> V_101 ) ;
if ( V_85 > V_102 )
V_102 = V_85 ;
}
if ( F_54 ( V_7 , & V_26 ) ) {
error ( L_10 ,
V_26 -> V_103 , F_32 ( V_26 ) , V_93 ,
F_55 ( V_93 , V_82 , sizeof( V_82 ) ) ) ;
return - 1 ;
}
V_83 = F_56 () ;
F_40 ( V_73 , & V_74 ) ;
if ( V_87 ) {
F_57 ( V_7 ) ;
F_42 () ;
if ( V_88 ) {
while ( ! F_58 ( V_89 , & V_86 , V_104 ) ) {
F_59 ( & V_71 , NULL ) ;
F_39 () ;
}
}
F_60 ( & V_86 ) ;
if ( V_77 ) {
const char * V_105 = F_55 ( V_77 , V_82 , sizeof( V_82 ) ) ;
F_21 ( L_11 , V_105 ) ;
return - 1 ;
}
if ( F_61 ( V_86 ) )
F_62 ( F_63 ( V_86 ) , V_81 [ 0 ] ) ;
} else {
F_42 () ;
while ( ! V_106 ) {
F_59 ( & V_71 , NULL ) ;
if ( V_88 )
F_39 () ;
}
}
V_84 = F_56 () ;
F_31 ( & V_107 , V_84 - V_83 ) ;
F_35 ( true ) ;
return F_64 ( V_86 ) ;
}
static int F_65 ( int V_80 , const char * * V_81 )
{
int V_61 ;
if ( V_108 ) {
V_61 = system ( V_108 ) ;
if ( V_61 )
return V_61 ;
}
if ( V_109 )
F_66 () ;
V_61 = F_47 ( V_80 , V_81 ) ;
if ( V_61 )
return V_61 ;
if ( V_110 ) {
V_61 = system ( V_110 ) ;
if ( V_61 )
return V_61 ;
}
return V_61 ;
}
static void F_67 ( T_1 V_53 , T_1 V_52 )
{
if ( V_111 ) {
fprintf ( V_65 , L_12 V_66 L_13 ,
V_112 ,
V_53 ,
V_112 ,
V_52 ? 100.0 * V_53 / V_52 : 100.0 ) ;
} else if ( V_53 != V_52 ) {
fprintf ( V_65 , L_14 , 100.0 * V_53 / V_52 ) ;
}
}
static void F_68 ( double V_113 , double V_114 )
{
double V_115 = F_69 ( V_113 , V_114 ) ;
if ( V_111 )
fprintf ( V_65 , L_15 , V_112 , V_115 ) ;
else if ( V_115 )
fprintf ( V_65 , L_16 , V_115 ) ;
}
static void F_70 ( struct V_8 * V_9 , double V_114 )
{
struct V_57 * V_58 ;
if ( V_116 == 1 )
return;
V_58 = V_9 -> V_59 ;
F_68 ( F_71 ( & V_58 -> V_62 [ 0 ] ) , V_114 ) ;
}
static void F_72 ( struct V_8 * V_9 , int V_117 , int V_118 )
{
switch ( V_43 ) {
case V_45 :
fprintf ( V_65 , L_17 ,
F_73 ( V_117 ) ,
V_111 ? 0 : - 8 ,
F_74 ( V_117 ) ,
V_112 ,
V_111 ? 0 : 4 ,
V_118 ,
V_112 ) ;
break;
case V_46 :
fprintf ( V_65 , L_18 ,
V_111 ? 0 : - 5 ,
V_117 ,
V_112 ,
V_111 ? 0 : 4 ,
V_118 ,
V_112 ) ;
break;
case V_47 :
fprintf ( V_65 , L_19 ,
V_111 ? 0 : - 4 ,
F_8 ( V_9 ) -> V_119 [ V_117 ] , V_112 ) ;
break;
case V_44 :
fprintf ( V_65 , L_20 ,
V_111 ? 0 : 16 ,
F_75 ( V_9 -> V_22 , V_117 ) ,
V_111 ? 0 : - 8 ,
F_76 ( V_9 -> V_22 , V_117 ) ,
V_112 ) ;
break;
case V_50 :
default:
break;
}
}
static void F_77 ( int V_117 , int V_118 , struct V_8 * V_9 , double V_114 )
{
double V_120 = V_114 / 1e6 ;
const char * V_121 , * V_122 ;
char V_70 [ 25 ] ;
V_121 = V_111 ? L_21 : L_22 ;
V_122 = V_111 ? L_23 : L_24 ;
F_72 ( V_9 , V_117 , V_118 ) ;
F_78 ( V_70 , sizeof( V_70 ) , L_25 ,
F_32 ( V_9 ) , V_111 ? L_26 : L_27 ) ;
fprintf ( V_65 , V_121 , V_120 , V_112 ) ;
if ( V_111 )
fprintf ( V_65 , L_25 , V_9 -> V_101 , V_112 ) ;
else
fprintf ( V_65 , L_28 , V_102 , V_9 -> V_101 , V_112 ) ;
fprintf ( V_65 , V_122 , V_70 ) ;
if ( V_9 -> V_123 )
fprintf ( V_65 , L_25 , V_112 , V_9 -> V_123 -> V_70 ) ;
if ( V_111 || V_88 )
return;
if ( F_13 ( V_9 , V_23 , V_25 ) )
fprintf ( V_65 , L_29 ,
V_114 / F_79 ( & V_107 ) ) ;
else
fprintf ( V_65 , L_30 ) ;
}
static void F_80 ( int V_117 , int V_118 , struct V_8 * V_9 , double V_114 )
{
double V_124 = V_9 -> V_12 ;
const char * V_125 ;
int V_29 = F_74 ( V_117 ) ;
if ( V_111 ) {
V_125 = V_124 != 1.0 ? L_31 : L_32 ;
} else {
if ( V_126 )
V_125 = V_124 != 1.0 ? L_33 : L_34 ;
else
V_125 = V_124 != 1.0 ? L_35 : L_36 ;
}
F_72 ( V_9 , V_117 , V_118 ) ;
if ( V_43 == V_50 )
V_29 = 0 ;
fprintf ( V_65 , V_125 , V_114 , V_112 ) ;
if ( V_9 -> V_101 )
fprintf ( V_65 , L_28 ,
V_111 ? 0 : V_102 ,
V_9 -> V_101 , V_112 ) ;
fprintf ( V_65 , L_37 , V_111 ? 0 : 25 , F_32 ( V_9 ) ) ;
if ( V_9 -> V_123 )
fprintf ( V_65 , L_25 , V_112 , V_9 -> V_123 -> V_70 ) ;
if ( V_111 || V_88 )
return;
F_81 ( V_65 , V_9 , V_114 , V_29 , V_43 ) ;
}
static void F_82 ( char * V_127 )
{
struct V_8 * V_26 ;
int V_29 , V_128 , V_34 , V_129 , V_117 , V_118 ;
double V_130 ;
T_1 V_52 , V_53 , V_51 ;
if ( ! ( V_131 || V_132 ) )
return;
for ( V_34 = 0 ; V_34 < V_131 -> V_118 ; V_34 ++ ) {
V_117 = V_131 -> V_119 [ V_34 ] ;
F_36 (evsel_list, counter) {
V_51 = V_52 = V_53 = 0 ;
V_118 = 0 ;
for ( V_29 = 0 ; V_29 < F_27 ( V_26 ) ; V_29 ++ ) {
V_128 = F_8 ( V_26 ) -> V_119 [ V_29 ] ;
V_129 = V_132 ( V_7 -> V_33 , V_128 ) ;
if ( V_129 != V_117 )
continue;
V_51 += F_28 ( V_26 -> V_41 , V_29 , 0 ) -> V_51 ;
V_52 += F_28 ( V_26 -> V_41 , V_29 , 0 ) -> V_52 ;
V_53 += F_28 ( V_26 -> V_41 , V_29 , 0 ) -> V_53 ;
V_118 ++ ;
}
if ( V_127 )
fprintf ( V_65 , L_23 , V_127 ) ;
if ( V_53 == 0 || V_52 == 0 ) {
F_72 ( V_26 , V_117 , V_118 ) ;
fprintf ( V_65 , L_38 ,
V_111 ? 0 : 18 ,
V_26 -> V_67 ? V_133 : V_134 ,
V_112 ) ;
fprintf ( V_65 , L_28 ,
V_111 ? 0 : V_102 ,
V_26 -> V_101 , V_112 ) ;
fprintf ( V_65 , L_39 ,
V_111 ? 0 : - 25 ,
F_32 ( V_26 ) ) ;
if ( V_26 -> V_123 )
fprintf ( V_65 , L_25 ,
V_112 , V_26 -> V_123 -> V_70 ) ;
F_67 ( V_53 , V_52 ) ;
fputc ( '\n' , V_65 ) ;
continue;
}
V_130 = V_51 * V_26 -> V_12 ;
if ( F_12 ( V_26 ) )
F_77 ( V_117 , V_118 , V_26 , V_130 ) ;
else
F_80 ( V_117 , V_118 , V_26 , V_130 ) ;
if ( ! V_111 )
F_70 ( V_26 , 1.0 ) ;
F_67 ( V_53 , V_52 ) ;
fputc ( '\n' , V_65 ) ;
}
}
}
static void F_83 ( struct V_8 * V_26 , char * V_127 )
{
int V_54 = F_26 ( V_26 -> V_22 ) ;
int V_55 = F_43 ( V_26 -> V_33 ) ;
int V_29 , V_37 ;
double V_130 ;
for ( V_37 = 0 ; V_37 < V_54 ; V_37 ++ ) {
T_1 V_52 = 0 , V_53 = 0 , V_51 = 0 ;
for ( V_29 = 0 ; V_29 < V_55 ; V_29 ++ ) {
V_51 += F_28 ( V_26 -> V_41 , V_29 , V_37 ) -> V_51 ;
V_52 += F_28 ( V_26 -> V_41 , V_29 , V_37 ) -> V_52 ;
V_53 += F_28 ( V_26 -> V_41 , V_29 , V_37 ) -> V_53 ;
}
if ( V_127 )
fprintf ( V_65 , L_23 , V_127 ) ;
V_130 = V_51 * V_26 -> V_12 ;
if ( F_12 ( V_26 ) )
F_77 ( V_37 , 0 , V_26 , V_130 ) ;
else
F_80 ( V_37 , 0 , V_26 , V_130 ) ;
if ( ! V_111 )
F_70 ( V_26 , 1.0 ) ;
F_67 ( V_53 , V_52 ) ;
fputc ( '\n' , V_65 ) ;
}
}
static void F_84 ( struct V_8 * V_26 , char * V_127 )
{
struct V_57 * V_58 = V_26 -> V_59 ;
double V_114 = F_79 ( & V_58 -> V_62 [ 0 ] ) ;
int V_63 = V_26 -> V_41 -> V_63 ;
double V_130 ;
double V_135 , V_136 ;
V_135 = F_79 ( & V_58 -> V_62 [ 1 ] ) ;
V_136 = F_79 ( & V_58 -> V_62 [ 2 ] ) ;
if ( V_127 )
fprintf ( V_65 , L_23 , V_127 ) ;
if ( V_63 == - 1 || ! V_26 -> V_67 ) {
fprintf ( V_65 , L_38 ,
V_111 ? 0 : 18 ,
V_26 -> V_67 ? V_133 : V_134 ,
V_112 ) ;
fprintf ( V_65 , L_28 ,
V_111 ? 0 : V_102 ,
V_26 -> V_101 , V_112 ) ;
fprintf ( V_65 , L_39 ,
V_111 ? 0 : - 25 ,
F_32 ( V_26 ) ) ;
if ( V_26 -> V_123 )
fprintf ( V_65 , L_25 , V_112 , V_26 -> V_123 -> V_70 ) ;
F_67 ( V_136 , V_135 ) ;
fputc ( '\n' , V_65 ) ;
return;
}
V_130 = V_114 * V_26 -> V_12 ;
if ( F_12 ( V_26 ) )
F_77 ( - 1 , 0 , V_26 , V_130 ) ;
else
F_80 ( - 1 , 0 , V_26 , V_130 ) ;
F_70 ( V_26 , V_114 ) ;
F_67 ( V_136 , V_135 ) ;
fprintf ( V_65 , L_4 ) ;
}
static void F_85 ( struct V_8 * V_26 , char * V_127 )
{
T_1 V_52 , V_53 , V_51 ;
double V_130 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < F_27 ( V_26 ) ; V_29 ++ ) {
V_51 = F_28 ( V_26 -> V_41 , V_29 , 0 ) -> V_51 ;
V_52 = F_28 ( V_26 -> V_41 , V_29 , 0 ) -> V_52 ;
V_53 = F_28 ( V_26 -> V_41 , V_29 , 0 ) -> V_53 ;
if ( V_127 )
fprintf ( V_65 , L_23 , V_127 ) ;
if ( V_53 == 0 || V_52 == 0 ) {
fprintf ( V_65 , L_40 ,
V_111 ? 0 : - 4 ,
F_8 ( V_26 ) -> V_119 [ V_29 ] , V_112 ,
V_111 ? 0 : 18 ,
V_26 -> V_67 ? V_133 : V_134 ,
V_112 ) ;
fprintf ( V_65 , L_28 ,
V_111 ? 0 : V_102 ,
V_26 -> V_101 , V_112 ) ;
fprintf ( V_65 , L_39 ,
V_111 ? 0 : - 25 ,
F_32 ( V_26 ) ) ;
if ( V_26 -> V_123 )
fprintf ( V_65 , L_25 ,
V_112 , V_26 -> V_123 -> V_70 ) ;
F_67 ( V_53 , V_52 ) ;
fputc ( '\n' , V_65 ) ;
continue;
}
V_130 = V_51 * V_26 -> V_12 ;
if ( F_12 ( V_26 ) )
F_77 ( V_29 , 0 , V_26 , V_130 ) ;
else
F_80 ( V_29 , 0 , V_26 , V_130 ) ;
if ( ! V_111 )
F_70 ( V_26 , 1.0 ) ;
F_67 ( V_53 , V_52 ) ;
fputc ( '\n' , V_65 ) ;
}
}
static void F_86 ( char * V_127 , struct V_1 * V_71 )
{
static int V_137 ;
sprintf ( V_127 , L_41 , V_71 -> V_5 , V_71 -> V_6 , V_112 ) ;
if ( V_137 == 0 && ! V_111 ) {
switch ( V_43 ) {
case V_46 :
fprintf ( V_65 , L_42 , V_102 , L_43 ) ;
break;
case V_45 :
fprintf ( V_65 , L_44 , V_102 , L_43 ) ;
break;
case V_47 :
fprintf ( V_65 , L_45 , V_102 , L_43 ) ;
break;
case V_44 :
fprintf ( V_65 , L_46 , V_102 , L_43 ) ;
break;
case V_50 :
default:
fprintf ( V_65 , L_47 , V_102 , L_43 ) ;
}
}
if ( ++ V_137 == 25 )
V_137 = 0 ;
}
static void F_87 ( int V_80 , const char * * V_81 )
{
int V_60 ;
fflush ( stdout ) ;
if ( ! V_111 ) {
fprintf ( V_65 , L_4 ) ;
fprintf ( V_65 , L_48 ) ;
if ( V_18 . V_56 )
fprintf ( V_65 , L_49 ) ;
else if ( V_18 . V_138 )
fprintf ( V_65 , L_50 , V_18 . V_138 ) ;
else if ( ! F_9 ( & V_18 ) ) {
fprintf ( V_65 , L_51 , V_81 [ 0 ] ) ;
for ( V_60 = 1 ; V_60 < V_80 ; V_60 ++ )
fprintf ( V_65 , L_52 , V_81 [ V_60 ] ) ;
} else if ( V_18 . V_91 )
fprintf ( V_65 , L_53 , V_18 . V_91 ) ;
else
fprintf ( V_65 , L_54 , V_18 . V_139 ) ;
fprintf ( V_65 , L_55 ) ;
if ( V_116 > 1 )
fprintf ( V_65 , L_56 , V_116 ) ;
fprintf ( V_65 , L_57 ) ;
}
}
static void F_88 ( void )
{
if ( ! V_140 )
fprintf ( V_65 , L_4 ) ;
fprintf ( V_65 , L_58 ,
F_79 ( & V_107 ) / 1e9 ) ;
if ( V_116 > 1 ) {
fprintf ( V_65 , L_59 ) ;
F_68 ( F_71 ( & V_107 ) ,
F_79 ( & V_107 ) ) ;
}
fprintf ( V_65 , L_60 ) ;
}
static void F_41 ( struct V_1 * V_71 , int V_80 , const char * * V_81 )
{
struct V_8 * V_26 ;
char V_141 [ 64 ] , * V_127 = NULL ;
if ( V_88 )
F_86 ( V_127 = V_141 , V_71 ) ;
else
F_87 ( V_80 , V_81 ) ;
switch ( V_43 ) {
case V_45 :
case V_46 :
F_82 ( V_127 ) ;
break;
case V_44 :
F_36 (evsel_list, counter)
F_83 ( V_26 , V_127 ) ;
break;
case V_50 :
F_36 (evsel_list, counter)
F_84 ( V_26 , V_127 ) ;
break;
case V_47 :
F_36 (evsel_list, counter)
F_85 ( V_26 , V_127 ) ;
break;
default:
break;
}
if ( ! V_88 && ! V_111 )
F_88 () ;
fflush ( V_65 ) ;
}
static void F_89 ( int T_2 )
{
if ( ( V_89 == - 1 ) || V_88 )
V_106 = 1 ;
V_142 = T_2 ;
V_89 = - 1 ;
}
static void F_90 ( void )
{
T_6 V_143 , V_144 ;
F_91 ( & V_143 ) ;
F_92 ( & V_143 , V_145 ) ;
F_93 ( V_146 , & V_143 , & V_144 ) ;
if ( V_89 != - 1 )
F_53 ( V_89 , V_100 ) ;
F_93 ( V_147 , & V_144 , NULL ) ;
if ( V_142 == - 1 )
return;
signal ( V_142 , V_148 ) ;
F_53 ( F_94 () , V_142 ) ;
}
static int F_95 ( const struct V_149 * T_7 V_75 ,
const char * V_34 V_75 , int V_150 )
{
V_151 = V_150 ? 0 : 1 ;
return 0 ;
}
static int F_96 ( void )
{
switch ( V_43 ) {
case V_46 :
if ( F_97 ( V_7 -> V_33 , & V_131 ) ) {
perror ( L_61 ) ;
return - 1 ;
}
V_132 = F_18 ;
break;
case V_45 :
if ( F_98 ( V_7 -> V_33 , & V_131 ) ) {
perror ( L_62 ) ;
return - 1 ;
}
V_132 = V_152 ;
break;
case V_47 :
case V_50 :
case V_44 :
default:
break;
}
return 0 ;
}
static int F_99 ( void )
{
struct V_10 V_153 [] = {
{ . type = V_154 , . V_155 = V_156 } ,
{ . type = V_154 , . V_155 = V_157 } ,
{ . type = V_154 , . V_155 = V_158 } ,
{ . type = V_154 , . V_155 = V_159 } ,
{ . type = V_160 , . V_155 = V_161 } ,
{ . type = V_160 , . V_155 = V_162 } ,
{ . type = V_160 , . V_155 = V_163 } ,
{ . type = V_160 , . V_155 = V_164 } ,
{ . type = V_160 , . V_155 = V_165 } ,
{ . type = V_160 , . V_155 = V_166 } ,
} ;
struct V_10 V_167 [] = {
{ . type = V_168 ,
. V_155 =
V_169 << 0 |
( V_170 << 8 ) |
( V_171 << 16 ) } ,
{ . type = V_168 ,
. V_155 =
V_169 << 0 |
( V_170 << 8 ) |
( V_172 << 16 ) } ,
{ . type = V_168 ,
. V_155 =
V_173 << 0 |
( V_170 << 8 ) |
( V_171 << 16 ) } ,
{ . type = V_168 ,
. V_155 =
V_173 << 0 |
( V_170 << 8 ) |
( V_172 << 16 ) } ,
} ;
struct V_10 V_174 [] = {
{ . type = V_168 ,
. V_155 =
V_175 << 0 |
( V_170 << 8 ) |
( V_171 << 16 ) } ,
{ . type = V_168 ,
. V_155 =
V_175 << 0 |
( V_170 << 8 ) |
( V_172 << 16 ) } ,
{ . type = V_168 ,
. V_155 =
V_176 << 0 |
( V_170 << 8 ) |
( V_171 << 16 ) } ,
{ . type = V_168 ,
. V_155 =
V_176 << 0 |
( V_170 << 8 ) |
( V_172 << 16 ) } ,
{ . type = V_168 ,
. V_155 =
V_177 << 0 |
( V_170 << 8 ) |
( V_171 << 16 ) } ,
{ . type = V_168 ,
. V_155 =
V_177 << 0 |
( V_170 << 8 ) |
( V_172 << 16 ) } ,
} ;
struct V_10 V_178 [] = {
{ . type = V_168 ,
. V_155 =
V_169 << 0 |
( V_179 << 8 ) |
( V_171 << 16 ) } ,
{ . type = V_168 ,
. V_155 =
V_169 << 0 |
( V_179 << 8 ) |
( V_172 << 16 ) } ,
} ;
if ( V_140 )
return 0 ;
if ( V_180 ) {
int V_181 ;
if ( F_100 ( L_63 , L_64 ) &&
F_100 ( L_63 , L_65 ) )
V_181 = F_101 ( V_7 , V_182 , NULL ) ;
else
V_181 = F_101 ( V_7 , V_183 , NULL ) ;
if ( V_181 ) {
fprintf ( V_184 , L_66 ) ;
return - 1 ;
}
return 0 ;
}
if ( ! V_7 -> V_185 ) {
if ( F_102 ( V_7 , V_153 ) < 0 )
return - 1 ;
}
if ( V_186 < 1 )
return 0 ;
if ( F_102 ( V_7 , V_167 ) < 0 )
return - 1 ;
if ( V_186 < 2 )
return 0 ;
if ( F_102 ( V_7 , V_174 ) < 0 )
return - 1 ;
if ( V_186 < 3 )
return 0 ;
return F_102 ( V_7 , V_178 ) ;
}
int F_103 ( int V_80 , const char * * V_81 , const char * V_127 V_75 )
{
bool V_187 = false ;
int V_188 = 0 ;
const char * V_189 = NULL ;
const struct V_149 V_190 [] = {
F_104 ( 'T' , L_67 , & V_180 ,
L_68 ) ,
F_105 ( 'e' , L_69 , & V_7 , L_69 ,
L_70 ,
V_191 ) ,
F_105 ( 0 , L_71 , & V_7 , L_71 ,
L_72 , V_192 ) ,
F_104 ( 'i' , L_73 , & V_17 ,
L_74 ) ,
F_106 ( 'p' , L_75 , & V_18 . V_91 , L_75 ,
L_76 ) ,
F_106 ( 't' , L_77 , & V_18 . V_139 , L_77 ,
L_78 ) ,
F_104 ( 'a' , L_79 , & V_18 . V_56 ,
L_80 ) ,
F_104 ( 'g' , L_81 , & V_92 ,
L_82 ) ,
F_104 ( 'c' , L_83 , & V_12 , L_84 ) ,
F_107 ( 'v' , L_85 , & V_64 ,
L_86 ) ,
F_108 ( 'r' , L_87 , & V_116 ,
L_88 ) ,
F_104 ( 'n' , L_89 , & V_140 ,
L_90 ) ,
F_107 ( 'd' , L_91 , & V_186 ,
L_92 ) ,
F_104 ( 'S' , L_93 , & V_109 ,
L_94 ) ,
F_109 ( 'B' , L_95 , NULL , NULL ,
L_96 ,
F_95 ) ,
F_106 ( 'C' , L_63 , & V_18 . V_138 , L_63 ,
L_97 ) ,
F_110 ( 'A' , L_98 , & V_43 ,
L_99 , V_47 ) ,
F_106 ( 'x' , L_100 , & V_112 , L_101 ,
L_102 ) ,
F_105 ( 'G' , L_103 , & V_7 , L_104 ,
L_105 , V_193 ) ,
F_106 ( 'o' , L_106 , & V_189 , L_107 , L_108 ) ,
F_104 ( 0 , L_109 , & V_187 , L_110 ) ,
F_108 ( 0 , L_111 , & V_188 ,
L_112 ) ,
F_106 ( 0 , L_113 , & V_108 , L_114 ,
L_115 ) ,
F_106 ( 0 , L_116 , & V_110 , L_114 ,
L_117 ) ,
F_111 ( 'I' , L_118 , & V_88 ,
L_119 ) ,
F_110 ( 0 , L_120 , & V_43 ,
L_121 , V_46 ) ,
F_110 ( 0 , L_122 , & V_43 ,
L_123 , V_45 ) ,
F_110 ( 0 , L_124 , & V_43 ,
L_125 , V_44 ) ,
F_111 ( 'D' , L_126 , & V_20 ,
L_127 ) ,
F_112 ()
} ;
const char * const V_194 [] = {
L_128 ,
NULL
} ;
int V_86 = - V_94 , V_195 ;
const char * V_196 ;
setlocale ( V_197 , L_26 ) ;
V_7 = F_113 () ;
if ( V_7 == NULL )
return - V_36 ;
V_80 = F_114 ( V_80 , V_81 , V_190 , V_194 ,
V_198 ) ;
V_65 = V_184 ;
if ( V_189 && strcmp ( V_189 , L_129 ) )
V_65 = NULL ;
if ( V_189 && V_188 ) {
fprintf ( V_184 , L_130 ) ;
F_115 ( V_194 , V_190 , L_131 , 1 ) ;
F_115 ( NULL , V_190 , L_111 , 0 ) ;
goto V_199;
}
if ( V_188 < 0 ) {
fprintf ( V_184 , L_132 ) ;
F_115 ( V_194 , V_190 , L_111 , 0 ) ;
goto V_199;
}
if ( ! V_65 ) {
struct V_1 V_200 ;
V_196 = V_187 ? L_133 : L_134 ;
V_65 = fopen ( V_189 , V_196 ) ;
if ( ! V_65 ) {
perror ( L_135 ) ;
return - 1 ;
}
F_40 ( V_201 , & V_200 ) ;
fprintf ( V_65 , L_136 , ctime ( & V_200 . V_5 ) ) ;
} else if ( V_188 > 0 ) {
V_196 = V_187 ? L_133 : L_134 ;
V_65 = fdopen ( V_188 , V_196 ) ;
if ( ! V_65 ) {
perror ( L_137 ) ;
return - V_93 ;
}
}
if ( V_112 ) {
V_111 = true ;
if ( ! strcmp ( V_112 , L_138 ) )
V_112 = L_139 ;
} else
V_112 = V_202 ;
if ( V_111 ) {
if ( V_151 == 1 ) {
fprintf ( V_184 , L_140 ) ;
F_115 ( V_194 , V_190 , L_141 , 1 ) ;
F_115 ( NULL , V_190 , L_142 , 1 ) ;
goto V_199;
} else
V_126 = false ;
} else if ( V_151 == 0 )
V_126 = false ;
if ( ! V_80 && F_116 ( & V_18 ) )
F_117 ( V_194 , V_190 ) ;
if ( V_116 < 0 ) {
F_21 ( L_143 ) ;
F_115 ( V_194 , V_190 , L_144 , 1 ) ;
goto V_199;
} else if ( V_116 == 0 ) {
V_203 = true ;
V_116 = 1 ;
}
if ( ( V_43 == V_44 ) && ! F_9 ( & V_18 ) ) {
fprintf ( V_184 , L_145
L_146 ) ;
F_115 ( NULL , V_190 , L_147 , 1 ) ;
F_115 ( NULL , V_190 , L_148 , 1 ) ;
goto V_199;
}
if ( ( ( V_43 != V_50 && V_43 != V_44 ) || V_204 ) &&
! F_6 ( & V_18 ) ) {
fprintf ( V_184 , L_149
L_150 ) ;
F_115 ( V_194 , V_190 , L_151 , 1 ) ;
F_115 ( NULL , V_190 , L_152 , 1 ) ;
F_115 ( NULL , V_190 , L_133 , 1 ) ;
goto V_199;
}
if ( F_99 () )
goto V_199;
F_118 ( & V_18 ) ;
if ( F_119 ( V_7 , & V_18 ) < 0 ) {
if ( F_9 ( & V_18 ) ) {
F_21 ( L_153 ) ;
F_115 ( V_194 , V_190 , L_147 , 1 ) ;
F_115 ( NULL , V_190 , L_148 , 1 ) ;
} else if ( F_6 ( & V_18 ) ) {
perror ( L_154 ) ;
F_115 ( V_194 , V_190 , L_155 , 1 ) ;
F_115 ( NULL , V_190 , L_133 , 1 ) ;
}
goto V_199;
}
if ( V_43 == V_44 )
F_120 ( V_7 -> V_22 ) ;
if ( V_88 && V_88 < 100 ) {
F_21 ( L_156 ) ;
F_115 ( V_194 , V_190 , L_157 , 1 ) ;
goto V_199;
}
if ( F_121 ( V_7 , V_88 ) )
goto V_199;
if ( F_96 () )
goto V_199;
atexit ( F_90 ) ;
if ( ! V_203 )
signal ( V_205 , F_89 ) ;
signal ( V_145 , F_89 ) ;
signal ( V_206 , F_89 ) ;
signal ( V_207 , F_89 ) ;
V_86 = 0 ;
for ( V_195 = 0 ; V_203 || V_195 < V_116 ; V_195 ++ ) {
if ( V_116 != 1 && V_64 )
fprintf ( V_65 , L_158 ,
V_195 + 1 ) ;
V_86 = F_65 ( V_80 , V_81 ) ;
if ( V_203 && V_86 != - 1 ) {
F_41 ( NULL , V_80 , V_81 ) ;
F_2 () ;
}
}
if ( ! V_203 && V_86 != - 1 && ! V_88 )
F_41 ( NULL , V_80 , V_81 ) ;
F_122 ( V_7 ) ;
V_199:
F_123 ( V_7 ) ;
return V_86 ;
}
