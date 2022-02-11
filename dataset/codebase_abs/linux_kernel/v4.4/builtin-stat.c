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
if ( F_6 ( & V_19 ) )
return F_7 ( V_9 , F_8 ( V_9 ) ) ;
if ( ! F_9 ( & V_19 ) && F_10 ( V_9 ) ) {
V_11 -> V_20 = 1 ;
if ( ! V_21 )
V_11 -> V_22 = 1 ;
}
return F_11 ( V_9 , V_7 -> V_23 ) ;
}
static inline int F_12 ( struct V_8 * V_9 )
{
if ( F_13 ( V_9 , V_24 , V_25 ) ||
F_13 ( V_9 , V_24 , V_26 ) )
return 1 ;
return 0 ;
}
static int F_14 ( struct V_8 * V_27 )
{
int V_28 = F_15 ( V_7 -> V_23 ) ;
int V_29 = F_16 ( V_27 ) ;
int V_30 , V_31 ;
if ( ! V_27 -> V_32 )
return - V_33 ;
if ( V_27 -> V_34 )
V_28 = 1 ;
for ( V_31 = 0 ; V_31 < V_28 ; V_31 ++ ) {
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
struct V_35 * V_36 ;
V_36 = F_17 ( V_27 -> V_37 , V_30 , V_31 ) ;
if ( F_18 ( V_27 , V_30 , V_31 , V_36 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_19 ( bool V_38 )
{
struct V_8 * V_27 ;
F_20 (evsel_list, counter) {
if ( F_14 ( V_27 ) )
F_21 ( L_1 , V_27 -> V_39 ) ;
if ( F_22 ( & V_12 , V_27 ) )
F_23 ( L_2 , V_27 -> V_39 ) ;
if ( V_38 ) {
F_24 ( V_27 , F_16 ( V_27 ) ,
F_15 ( V_7 -> V_23 ) ) ;
}
}
}
static void F_25 ( void )
{
struct V_1 V_40 , V_41 ;
F_19 ( false ) ;
F_26 ( V_42 , & V_40 ) ;
F_1 ( & V_41 , & V_40 , & V_43 ) ;
F_27 ( & V_41 , 0 , NULL ) ;
}
static void F_28 ( void )
{
struct V_8 * V_27 ;
if ( V_21 ) {
const int V_29 = F_29 ( V_7 -> V_44 ) ,
V_28 = F_15 ( V_7 -> V_23 ) ;
F_30 ( V_21 * 1000 ) ;
F_20 (evsel_list, counter)
F_31 ( V_27 , V_29 , V_28 ) ;
}
}
static void F_32 ( int T_1 V_45 , T_2 * V_46 ,
void * T_3 V_45 )
{
V_47 = V_46 -> V_48 . V_49 ;
}
static int F_33 ( int V_50 , const char * * V_51 )
{
int V_52 = V_12 . V_52 ;
char V_53 [ 512 ] ;
unsigned long long V_54 , V_55 ;
struct V_8 * V_27 ;
struct V_1 V_40 ;
T_4 V_56 ;
int V_57 = 0 ;
const bool V_58 = ( V_50 > 0 ) ;
if ( V_52 ) {
V_40 . V_5 = V_52 / 1000 ;
V_40 . V_6 = ( V_52 % 1000 ) * 1000000 ;
} else {
V_40 . V_5 = 1 ;
V_40 . V_6 = 0 ;
}
if ( V_58 ) {
if ( F_34 ( V_7 , & V_19 , V_51 , false ,
F_32 ) < 0 ) {
perror ( L_3 ) ;
return - 1 ;
}
V_59 = V_7 -> V_60 . V_61 ;
}
if ( V_62 )
F_35 ( V_7 ) ;
F_20 (evsel_list, counter) {
if ( F_5 ( V_27 ) < 0 ) {
if ( V_63 == V_64 || V_63 == V_65 ||
V_63 == V_33 || V_63 == V_66 ||
V_63 == V_67 ) {
if ( V_68 )
F_36 ( L_4 ,
F_37 ( V_27 ) ) ;
V_27 -> V_32 = false ;
if ( ( V_27 -> V_69 != V_27 ) ||
! ( V_27 -> V_69 -> V_70 > 1 ) )
continue;
}
F_38 ( V_27 , & V_19 ,
V_63 , V_53 , sizeof( V_53 ) ) ;
F_39 ( L_5 , V_53 ) ;
if ( V_59 != - 1 )
F_40 ( V_59 , V_71 ) ;
return - 1 ;
}
V_27 -> V_32 = true ;
V_56 = strlen ( V_27 -> V_72 ) ;
if ( V_56 > V_73 )
V_73 = V_56 ;
}
if ( F_41 ( V_7 , & V_27 ) ) {
error ( L_6 ,
V_27 -> V_74 , F_37 ( V_27 ) , V_63 ,
F_42 ( V_63 , V_53 , sizeof( V_53 ) ) ) ;
return - 1 ;
}
V_54 = F_43 () ;
F_26 ( V_42 , & V_43 ) ;
if ( V_58 ) {
F_44 ( V_7 ) ;
F_28 () ;
if ( V_52 ) {
while ( ! F_45 ( V_59 , & V_57 , V_75 ) ) {
F_46 ( & V_40 , NULL ) ;
F_25 () ;
}
}
F_47 ( & V_57 ) ;
if ( V_47 ) {
const char * V_76 = F_42 ( V_47 , V_53 , sizeof( V_53 ) ) ;
F_48 ( L_7 , V_76 ) ;
return - 1 ;
}
if ( F_49 ( V_57 ) )
F_50 ( F_51 ( V_57 ) , V_51 [ 0 ] ) ;
} else {
F_28 () ;
while ( ! V_77 ) {
F_46 ( & V_40 , NULL ) ;
if ( V_52 )
F_25 () ;
}
}
V_55 = F_43 () ;
F_52 ( & V_78 , V_55 - V_54 ) ;
F_19 ( true ) ;
return F_53 ( V_57 ) ;
}
static int F_54 ( int V_50 , const char * * V_51 )
{
int V_79 ;
if ( V_80 ) {
V_79 = system ( V_80 ) ;
if ( V_79 )
return V_79 ;
}
if ( V_81 )
F_55 () ;
V_79 = F_33 ( V_50 , V_51 ) ;
if ( V_79 )
return V_79 ;
if ( V_82 ) {
V_79 = system ( V_82 ) ;
if ( V_79 )
return V_79 ;
}
return V_79 ;
}
static void F_56 ( T_5 V_83 , T_5 V_84 )
{
if ( V_85 ) {
fprintf ( V_12 . V_86 , L_8 V_87 L_9 ,
V_88 ,
V_83 ,
V_88 ,
V_84 ? 100.0 * V_83 / V_84 : 100.0 ) ;
} else if ( V_83 != V_84 ) {
fprintf ( V_12 . V_86 , L_10 , 100.0 * V_83 / V_84 ) ;
}
}
static void F_57 ( double V_89 , double V_90 )
{
double V_91 = F_58 ( V_89 , V_90 ) ;
if ( V_85 )
fprintf ( V_12 . V_86 , L_11 , V_88 , V_91 ) ;
else if ( V_91 )
fprintf ( V_12 . V_86 , L_12 , V_91 ) ;
}
static void F_59 ( struct V_8 * V_9 , double V_90 )
{
struct V_92 * V_93 ;
if ( V_94 == 1 )
return;
V_93 = V_9 -> V_95 ;
F_57 ( F_60 ( & V_93 -> V_96 [ 0 ] ) , V_90 ) ;
}
static void F_61 ( struct V_8 * V_9 , int V_97 , int V_98 )
{
switch ( V_12 . V_99 ) {
case V_100 :
fprintf ( V_12 . V_86 , L_13 ,
F_62 ( V_97 ) ,
V_85 ? 0 : - 8 ,
F_63 ( V_97 ) ,
V_88 ,
V_85 ? 0 : 4 ,
V_98 ,
V_88 ) ;
break;
case V_101 :
fprintf ( V_12 . V_86 , L_14 ,
V_85 ? 0 : - 5 ,
V_97 ,
V_88 ,
V_85 ? 0 : 4 ,
V_98 ,
V_88 ) ;
break;
case V_102 :
fprintf ( V_12 . V_86 , L_15 ,
V_85 ? 0 : - 4 ,
F_8 ( V_9 ) -> V_103 [ V_97 ] , V_88 ) ;
break;
case V_104 :
fprintf ( V_12 . V_86 , L_16 ,
V_85 ? 0 : 16 ,
F_64 ( V_9 -> V_23 , V_97 ) ,
V_85 ? 0 : - 8 ,
F_65 ( V_9 -> V_23 , V_97 ) ,
V_88 ) ;
break;
case V_105 :
case V_106 :
default:
break;
}
}
static void F_66 ( int V_97 , int V_98 , struct V_8 * V_9 , double V_90 )
{
T_6 * V_86 = V_12 . V_86 ;
double V_107 = V_90 / 1e6 ;
const char * V_108 , * V_109 ;
char V_39 [ 25 ] ;
V_108 = V_85 ? L_17 : L_18 ;
V_109 = V_85 ? L_19 : L_20 ;
F_61 ( V_9 , V_97 , V_98 ) ;
F_67 ( V_39 , sizeof( V_39 ) , L_21 ,
F_37 ( V_9 ) , V_85 ? L_22 : L_23 ) ;
fprintf ( V_86 , V_108 , V_107 , V_88 ) ;
if ( V_85 )
fprintf ( V_86 , L_21 , V_9 -> V_72 , V_88 ) ;
else
fprintf ( V_86 , L_24 , V_73 , V_9 -> V_72 , V_88 ) ;
fprintf ( V_86 , V_109 , V_39 ) ;
if ( V_9 -> V_110 )
fprintf ( V_86 , L_21 , V_88 , V_9 -> V_110 -> V_39 ) ;
}
static void F_68 ( int V_97 , int V_98 , struct V_8 * V_9 , double V_90 )
{
T_6 * V_86 = V_12 . V_86 ;
double V_111 = V_9 -> V_13 ;
const char * V_112 ;
if ( V_85 ) {
V_112 = V_111 != 1.0 ? L_25 : L_26 ;
} else {
if ( V_113 )
V_112 = V_111 != 1.0 ? L_27 : L_28 ;
else
V_112 = V_111 != 1.0 ? L_29 : L_30 ;
}
F_61 ( V_9 , V_97 , V_98 ) ;
fprintf ( V_86 , V_112 , V_90 , V_88 ) ;
if ( V_9 -> V_72 )
fprintf ( V_86 , L_24 ,
V_85 ? 0 : V_73 ,
V_9 -> V_72 , V_88 ) ;
fprintf ( V_86 , L_31 , V_85 ? 0 : 25 , F_37 ( V_9 ) ) ;
if ( V_9 -> V_110 )
fprintf ( V_86 , L_21 , V_88 , V_9 -> V_110 -> V_39 ) ;
}
static void F_69 ( int V_97 , int V_98 , struct V_8 * V_27 , double V_114 )
{
int V_30 = F_63 ( V_97 ) ;
if ( V_12 . V_99 == V_105 )
V_30 = 0 ;
if ( F_12 ( V_27 ) )
F_66 ( V_97 , V_98 , V_27 , V_114 ) ;
else
F_68 ( V_97 , V_98 , V_27 , V_114 ) ;
if ( ! V_85 && ! V_12 . V_52 )
F_70 ( V_12 . V_86 , V_27 ,
V_114 , V_30 ,
V_12 . V_99 ) ;
}
static void F_71 ( char * V_115 )
{
T_6 * V_86 = V_12 . V_86 ;
struct V_8 * V_27 ;
int V_30 , V_116 , V_117 , V_97 , V_98 ;
double V_114 ;
T_5 V_84 , V_83 , V_118 ;
if ( ! ( V_119 || V_120 ) )
return;
for ( V_116 = 0 ; V_116 < V_119 -> V_98 ; V_116 ++ ) {
V_97 = V_119 -> V_103 [ V_116 ] ;
F_20 (evsel_list, counter) {
V_118 = V_84 = V_83 = 0 ;
V_98 = 0 ;
for ( V_30 = 0 ; V_30 < F_16 ( V_27 ) ; V_30 ++ ) {
V_117 = V_120 ( F_8 ( V_27 ) , V_30 ) ;
if ( V_117 != V_97 )
continue;
V_118 += F_17 ( V_27 -> V_37 , V_30 , 0 ) -> V_118 ;
V_84 += F_17 ( V_27 -> V_37 , V_30 , 0 ) -> V_84 ;
V_83 += F_17 ( V_27 -> V_37 , V_30 , 0 ) -> V_83 ;
V_98 ++ ;
}
if ( V_115 )
fprintf ( V_86 , L_19 , V_115 ) ;
if ( V_83 == 0 || V_84 == 0 ) {
F_61 ( V_27 , V_97 , V_98 ) ;
fprintf ( V_86 , L_32 ,
V_85 ? 0 : 18 ,
V_27 -> V_32 ? V_121 : V_122 ,
V_88 ) ;
fprintf ( V_86 , L_24 ,
V_85 ? 0 : V_73 ,
V_27 -> V_72 , V_88 ) ;
fprintf ( V_86 , L_33 ,
V_85 ? 0 : - 25 ,
F_37 ( V_27 ) ) ;
if ( V_27 -> V_110 )
fprintf ( V_86 , L_21 ,
V_88 , V_27 -> V_110 -> V_39 ) ;
F_56 ( V_83 , V_84 ) ;
fputc ( '\n' , V_86 ) ;
continue;
}
V_114 = V_118 * V_27 -> V_13 ;
F_69 ( V_97 , V_98 , V_27 , V_114 ) ;
if ( ! V_85 )
F_59 ( V_27 , 1.0 ) ;
F_56 ( V_83 , V_84 ) ;
fputc ( '\n' , V_86 ) ;
}
}
}
static void F_72 ( struct V_8 * V_27 , char * V_115 )
{
T_6 * V_86 = V_12 . V_86 ;
int V_28 = F_15 ( V_27 -> V_23 ) ;
int V_29 = F_29 ( V_27 -> V_44 ) ;
int V_30 , V_31 ;
double V_114 ;
for ( V_31 = 0 ; V_31 < V_28 ; V_31 ++ ) {
T_5 V_84 = 0 , V_83 = 0 , V_118 = 0 ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
V_118 += F_17 ( V_27 -> V_37 , V_30 , V_31 ) -> V_118 ;
V_84 += F_17 ( V_27 -> V_37 , V_30 , V_31 ) -> V_84 ;
V_83 += F_17 ( V_27 -> V_37 , V_30 , V_31 ) -> V_83 ;
}
if ( V_115 )
fprintf ( V_86 , L_19 , V_115 ) ;
V_114 = V_118 * V_27 -> V_13 ;
F_69 ( V_31 , 0 , V_27 , V_114 ) ;
if ( ! V_85 )
F_59 ( V_27 , 1.0 ) ;
F_56 ( V_83 , V_84 ) ;
fputc ( '\n' , V_86 ) ;
}
}
static void F_73 ( struct V_8 * V_27 , char * V_115 )
{
T_6 * V_86 = V_12 . V_86 ;
struct V_92 * V_93 = V_27 -> V_95 ;
double V_90 = F_74 ( & V_93 -> V_96 [ 0 ] ) ;
int V_123 = V_27 -> V_37 -> V_123 ;
double V_114 ;
double V_124 , V_125 ;
V_124 = F_74 ( & V_93 -> V_96 [ 1 ] ) ;
V_125 = F_74 ( & V_93 -> V_96 [ 2 ] ) ;
if ( V_115 )
fprintf ( V_86 , L_19 , V_115 ) ;
if ( V_123 == - 1 || ! V_27 -> V_32 ) {
fprintf ( V_86 , L_32 ,
V_85 ? 0 : 18 ,
V_27 -> V_32 ? V_121 : V_122 ,
V_88 ) ;
fprintf ( V_86 , L_24 ,
V_85 ? 0 : V_73 ,
V_27 -> V_72 , V_88 ) ;
fprintf ( V_86 , L_33 ,
V_85 ? 0 : - 25 ,
F_37 ( V_27 ) ) ;
if ( V_27 -> V_110 )
fprintf ( V_86 , L_21 , V_88 , V_27 -> V_110 -> V_39 ) ;
F_56 ( V_125 , V_124 ) ;
fputc ( '\n' , V_86 ) ;
return;
}
V_114 = V_90 * V_27 -> V_13 ;
F_69 ( - 1 , 0 , V_27 , V_114 ) ;
F_59 ( V_27 , V_90 ) ;
F_56 ( V_125 , V_124 ) ;
fprintf ( V_86 , L_34 ) ;
}
static void F_75 ( struct V_8 * V_27 , char * V_115 )
{
T_6 * V_86 = V_12 . V_86 ;
T_5 V_84 , V_83 , V_118 ;
double V_114 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < F_16 ( V_27 ) ; V_30 ++ ) {
V_118 = F_17 ( V_27 -> V_37 , V_30 , 0 ) -> V_118 ;
V_84 = F_17 ( V_27 -> V_37 , V_30 , 0 ) -> V_84 ;
V_83 = F_17 ( V_27 -> V_37 , V_30 , 0 ) -> V_83 ;
if ( V_115 )
fprintf ( V_86 , L_19 , V_115 ) ;
if ( V_83 == 0 || V_84 == 0 ) {
fprintf ( V_86 , L_35 ,
V_85 ? 0 : - 4 ,
F_8 ( V_27 ) -> V_103 [ V_30 ] , V_88 ,
V_85 ? 0 : 18 ,
V_27 -> V_32 ? V_121 : V_122 ,
V_88 ) ;
fprintf ( V_86 , L_24 ,
V_85 ? 0 : V_73 ,
V_27 -> V_72 , V_88 ) ;
fprintf ( V_86 , L_33 ,
V_85 ? 0 : - 25 ,
F_37 ( V_27 ) ) ;
if ( V_27 -> V_110 )
fprintf ( V_86 , L_21 ,
V_88 , V_27 -> V_110 -> V_39 ) ;
F_56 ( V_83 , V_84 ) ;
fputc ( '\n' , V_86 ) ;
continue;
}
V_114 = V_118 * V_27 -> V_13 ;
F_69 ( V_30 , 0 , V_27 , V_114 ) ;
if ( ! V_85 )
F_59 ( V_27 , 1.0 ) ;
F_56 ( V_83 , V_84 ) ;
fputc ( '\n' , V_86 ) ;
}
}
static void F_76 ( char * V_115 , struct V_1 * V_40 )
{
T_6 * V_86 = V_12 . V_86 ;
static int V_126 ;
sprintf ( V_115 , L_36 , V_40 -> V_5 , V_40 -> V_6 , V_88 ) ;
if ( V_126 == 0 && ! V_85 ) {
switch ( V_12 . V_99 ) {
case V_101 :
fprintf ( V_86 , L_37 , V_73 , L_38 ) ;
break;
case V_100 :
fprintf ( V_86 , L_39 , V_73 , L_38 ) ;
break;
case V_102 :
fprintf ( V_86 , L_40 , V_73 , L_38 ) ;
break;
case V_104 :
fprintf ( V_86 , L_41 , V_73 , L_38 ) ;
break;
case V_105 :
default:
fprintf ( V_86 , L_42 , V_73 , L_38 ) ;
case V_106 :
break;
}
}
if ( ++ V_126 == 25 )
V_126 = 0 ;
}
static void F_77 ( int V_50 , const char * * V_51 )
{
T_6 * V_86 = V_12 . V_86 ;
int V_127 ;
fflush ( stdout ) ;
if ( ! V_85 ) {
fprintf ( V_86 , L_34 ) ;
fprintf ( V_86 , L_43 ) ;
if ( V_19 . V_34 )
fprintf ( V_86 , L_44 ) ;
else if ( V_19 . V_128 )
fprintf ( V_86 , L_45 , V_19 . V_128 ) ;
else if ( ! F_9 ( & V_19 ) ) {
fprintf ( V_86 , L_46 , V_51 [ 0 ] ) ;
for ( V_127 = 1 ; V_127 < V_50 ; V_127 ++ )
fprintf ( V_86 , L_47 , V_51 [ V_127 ] ) ;
} else if ( V_19 . V_61 )
fprintf ( V_86 , L_48 , V_19 . V_61 ) ;
else
fprintf ( V_86 , L_49 , V_19 . V_129 ) ;
fprintf ( V_86 , L_50 ) ;
if ( V_94 > 1 )
fprintf ( V_86 , L_51 , V_94 ) ;
fprintf ( V_86 , L_52 ) ;
}
}
static void F_78 ( void )
{
T_6 * V_86 = V_12 . V_86 ;
if ( ! V_130 )
fprintf ( V_86 , L_34 ) ;
fprintf ( V_86 , L_53 ,
F_74 ( & V_78 ) / 1e9 ) ;
if ( V_94 > 1 ) {
fprintf ( V_86 , L_54 ) ;
F_57 ( F_60 ( & V_78 ) ,
F_74 ( & V_78 ) ) ;
}
fprintf ( V_86 , L_55 ) ;
}
static void F_27 ( struct V_1 * V_40 , int V_50 , const char * * V_51 )
{
int V_52 = V_12 . V_52 ;
struct V_8 * V_27 ;
char V_131 [ 64 ] , * V_115 = NULL ;
if ( V_52 )
F_76 ( V_115 = V_131 , V_40 ) ;
else
F_77 ( V_50 , V_51 ) ;
switch ( V_12 . V_99 ) {
case V_100 :
case V_101 :
F_71 ( V_115 ) ;
break;
case V_104 :
F_20 (evsel_list, counter)
F_72 ( V_27 , V_115 ) ;
break;
case V_105 :
F_20 (evsel_list, counter)
F_73 ( V_27 , V_115 ) ;
break;
case V_102 :
F_20 (evsel_list, counter)
F_75 ( V_27 , V_115 ) ;
break;
case V_106 :
default:
break;
}
if ( ! V_52 && ! V_85 )
F_78 () ;
fflush ( V_12 . V_86 ) ;
}
static void F_79 ( int T_1 )
{
if ( ( V_59 == - 1 ) || V_12 . V_52 )
V_77 = 1 ;
V_132 = T_1 ;
V_59 = - 1 ;
}
static void F_80 ( void )
{
T_7 V_133 , V_134 ;
F_81 ( & V_133 ) ;
F_82 ( & V_133 , V_135 ) ;
F_83 ( V_136 , & V_133 , & V_134 ) ;
if ( V_59 != - 1 )
F_40 ( V_59 , V_71 ) ;
F_83 ( V_137 , & V_134 , NULL ) ;
if ( V_132 == - 1 )
return;
signal ( V_132 , V_138 ) ;
F_40 ( F_84 () , V_132 ) ;
}
static int F_85 ( const struct V_139 * T_8 V_45 ,
const char * V_116 V_45 , int V_140 )
{
V_141 = V_140 ? 0 : 1 ;
return 0 ;
}
static int F_86 ( struct V_142 * V_103 , int V_30 )
{
return F_87 ( V_103 , V_30 , NULL ) ;
}
static int F_88 ( struct V_142 * V_103 , int V_30 )
{
return F_89 ( V_103 , V_30 , NULL ) ;
}
static int F_90 ( struct V_142 * V_103 )
{
int V_127 , V_143 = - 1 ;
for ( V_127 = 0 ; V_127 < V_103 -> V_98 ; V_127 ++ ) {
if ( V_103 -> V_103 [ V_127 ] > V_143 )
V_143 = V_103 -> V_103 [ V_127 ] ;
}
return V_143 ;
}
static int F_91 ( T_9 V_144 , struct V_142 * V_103 , int V_145 )
{
int V_30 ;
if ( V_145 >= V_103 -> V_98 )
return - 1 ;
V_30 = V_103 -> V_103 [ V_145 ] ;
if ( V_146 -> V_103 [ V_30 ] == - 1 )
V_146 -> V_103 [ V_30 ] = V_144 ( V_103 , V_145 ) ;
return V_146 -> V_103 [ V_30 ] ;
}
static int F_92 ( struct V_142 * V_103 , int V_145 )
{
return F_91 ( F_86 , V_103 , V_145 ) ;
}
static int F_93 ( struct V_142 * V_103 , int V_145 )
{
return F_91 ( F_88 , V_103 , V_145 ) ;
}
static int F_94 ( void )
{
int V_98 ;
switch ( V_12 . V_99 ) {
case V_101 :
if ( F_95 ( V_7 -> V_44 , & V_119 ) ) {
perror ( L_56 ) ;
return - 1 ;
}
V_120 = F_92 ;
break;
case V_100 :
if ( F_96 ( V_7 -> V_44 , & V_119 ) ) {
perror ( L_57 ) ;
return - 1 ;
}
V_120 = F_93 ;
break;
case V_102 :
case V_105 :
case V_104 :
case V_106 :
default:
break;
}
V_98 = F_90 ( V_7 -> V_44 ) ;
V_146 = F_97 ( V_98 + 1 ) ;
return V_146 ? 0 : - V_147 ;
}
static int F_98 ( void )
{
struct V_10 V_148 [] = {
{ . type = V_149 , . V_150 = V_151 } ,
{ . type = V_149 , . V_150 = V_152 } ,
{ . type = V_149 , . V_150 = V_153 } ,
{ . type = V_149 , . V_150 = V_154 } ,
{ . type = V_155 , . V_150 = V_156 } ,
{ . type = V_155 , . V_150 = V_157 } ,
{ . type = V_155 , . V_150 = V_158 } ,
{ . type = V_155 , . V_150 = V_159 } ,
{ . type = V_155 , . V_150 = V_160 } ,
{ . type = V_155 , . V_150 = V_161 } ,
} ;
struct V_10 V_162 [] = {
{ . type = V_163 ,
. V_150 =
V_164 << 0 |
( V_165 << 8 ) |
( V_166 << 16 ) } ,
{ . type = V_163 ,
. V_150 =
V_164 << 0 |
( V_165 << 8 ) |
( V_167 << 16 ) } ,
{ . type = V_163 ,
. V_150 =
V_168 << 0 |
( V_165 << 8 ) |
( V_166 << 16 ) } ,
{ . type = V_163 ,
. V_150 =
V_168 << 0 |
( V_165 << 8 ) |
( V_167 << 16 ) } ,
} ;
struct V_10 V_169 [] = {
{ . type = V_163 ,
. V_150 =
V_170 << 0 |
( V_165 << 8 ) |
( V_166 << 16 ) } ,
{ . type = V_163 ,
. V_150 =
V_170 << 0 |
( V_165 << 8 ) |
( V_167 << 16 ) } ,
{ . type = V_163 ,
. V_150 =
V_171 << 0 |
( V_165 << 8 ) |
( V_166 << 16 ) } ,
{ . type = V_163 ,
. V_150 =
V_171 << 0 |
( V_165 << 8 ) |
( V_167 << 16 ) } ,
{ . type = V_163 ,
. V_150 =
V_172 << 0 |
( V_165 << 8 ) |
( V_166 << 16 ) } ,
{ . type = V_163 ,
. V_150 =
V_172 << 0 |
( V_165 << 8 ) |
( V_167 << 16 ) } ,
} ;
struct V_10 V_173 [] = {
{ . type = V_163 ,
. V_150 =
V_164 << 0 |
( V_174 << 8 ) |
( V_166 << 16 ) } ,
{ . type = V_163 ,
. V_150 =
V_164 << 0 |
( V_174 << 8 ) |
( V_167 << 16 ) } ,
} ;
if ( V_130 )
return 0 ;
if ( V_175 ) {
int V_176 ;
if ( F_99 ( L_58 , L_59 ) &&
F_99 ( L_58 , L_60 ) )
V_176 = F_100 ( V_7 , V_177 , NULL ) ;
else
V_176 = F_100 ( V_7 , V_178 , NULL ) ;
if ( V_176 ) {
fprintf ( V_179 , L_61 ) ;
return - 1 ;
}
return 0 ;
}
if ( ! V_7 -> V_180 ) {
if ( F_101 ( V_7 , V_148 ) < 0 )
return - 1 ;
}
if ( V_181 < 1 )
return 0 ;
if ( F_101 ( V_7 , V_162 ) < 0 )
return - 1 ;
if ( V_181 < 2 )
return 0 ;
if ( F_101 ( V_7 , V_169 ) < 0 )
return - 1 ;
if ( V_181 < 3 )
return 0 ;
return F_101 ( V_7 , V_173 ) ;
}
int F_102 ( int V_50 , const char * * V_51 , const char * V_115 V_45 )
{
const char * const V_182 [] = {
L_62 ,
NULL
} ;
int V_57 = - V_64 , V_183 ;
const char * V_184 ;
T_6 * V_86 = V_179 ;
unsigned int V_52 ;
setlocale ( V_185 , L_22 ) ;
V_7 = F_103 () ;
if ( V_7 == NULL )
return - V_147 ;
V_50 = F_104 ( V_50 , V_51 , V_186 , V_182 ,
V_187 ) ;
V_52 = V_12 . V_52 ;
if ( V_188 && strcmp ( V_188 , L_63 ) )
V_86 = NULL ;
if ( V_188 && V_189 ) {
fprintf ( V_179 , L_64 ) ;
F_105 ( V_182 , V_186 , L_65 , 1 ) ;
F_105 ( NULL , V_186 , L_66 , 0 ) ;
goto V_190;
}
if ( V_189 < 0 ) {
fprintf ( V_179 , L_67 ) ;
F_105 ( V_182 , V_186 , L_66 , 0 ) ;
goto V_190;
}
if ( ! V_86 ) {
struct V_1 V_191 ;
V_184 = V_192 ? L_68 : L_69 ;
V_86 = fopen ( V_188 , V_184 ) ;
if ( ! V_86 ) {
perror ( L_70 ) ;
return - 1 ;
}
F_26 ( V_193 , & V_191 ) ;
fprintf ( V_86 , L_71 , ctime ( & V_191 . V_5 ) ) ;
} else if ( V_189 > 0 ) {
V_184 = V_192 ? L_68 : L_69 ;
V_86 = fdopen ( V_189 , V_184 ) ;
if ( ! V_86 ) {
perror ( L_72 ) ;
return - V_63 ;
}
}
V_12 . V_86 = V_86 ;
if ( V_88 ) {
V_85 = true ;
if ( ! strcmp ( V_88 , L_73 ) )
V_88 = L_74 ;
} else
V_88 = V_194 ;
if ( V_85 ) {
if ( V_141 == 1 ) {
fprintf ( V_179 , L_75 ) ;
F_105 ( V_182 , V_186 , L_76 , 1 ) ;
F_105 ( NULL , V_186 , L_77 , 1 ) ;
goto V_190;
} else
V_113 = false ;
} else if ( V_141 == 0 )
V_113 = false ;
if ( ! V_50 && F_106 ( & V_19 ) )
F_107 ( V_182 , V_186 ) ;
if ( V_94 < 0 ) {
F_48 ( L_78 ) ;
F_105 ( V_182 , V_186 , L_79 , 1 ) ;
goto V_190;
} else if ( V_94 == 0 ) {
V_195 = true ;
V_94 = 1 ;
}
if ( ( V_12 . V_99 == V_104 ) && ! F_9 ( & V_19 ) ) {
fprintf ( V_179 , L_80
L_81 ) ;
F_105 ( NULL , V_186 , L_82 , 1 ) ;
F_105 ( NULL , V_186 , L_83 , 1 ) ;
goto V_190;
}
if ( ( ( V_12 . V_99 != V_105 &&
V_12 . V_99 != V_104 ) || V_196 ) &&
! F_6 ( & V_19 ) ) {
fprintf ( V_179 , L_84
L_85 ) ;
F_105 ( V_182 , V_186 , L_86 , 1 ) ;
F_105 ( NULL , V_186 , L_87 , 1 ) ;
F_105 ( NULL , V_186 , L_68 , 1 ) ;
goto V_190;
}
if ( F_98 () )
goto V_190;
F_108 ( & V_19 ) ;
if ( F_109 ( V_7 , & V_19 ) < 0 ) {
if ( F_9 ( & V_19 ) ) {
F_48 ( L_88 ) ;
F_105 ( V_182 , V_186 , L_82 , 1 ) ;
F_105 ( NULL , V_186 , L_83 , 1 ) ;
} else if ( F_6 ( & V_19 ) ) {
perror ( L_89 ) ;
F_105 ( V_182 , V_186 , L_90 , 1 ) ;
F_105 ( NULL , V_186 , L_68 , 1 ) ;
}
goto V_190;
}
if ( V_12 . V_99 == V_104 )
F_110 ( V_7 -> V_23 ) ;
if ( V_52 && V_52 < 100 ) {
if ( V_52 < 10 ) {
F_48 ( L_91 ) ;
F_105 ( V_182 , V_186 , L_92 , 1 ) ;
goto V_190;
} else
F_23 ( L_93
L_94
L_95 ) ;
}
if ( F_111 ( V_7 , V_52 ) )
goto V_190;
if ( F_94 () )
goto V_190;
atexit ( F_80 ) ;
if ( ! V_195 )
signal ( V_197 , F_79 ) ;
signal ( V_135 , F_79 ) ;
signal ( V_198 , F_79 ) ;
signal ( V_199 , F_79 ) ;
V_57 = 0 ;
for ( V_183 = 0 ; V_195 || V_183 < V_94 ; V_183 ++ ) {
if ( V_94 != 1 && V_68 )
fprintf ( V_86 , L_96 ,
V_183 + 1 ) ;
V_57 = F_54 ( V_50 , V_51 ) ;
if ( V_195 && V_57 != - 1 ) {
F_27 ( NULL , V_50 , V_51 ) ;
F_2 () ;
}
}
if ( ! V_195 && V_57 != - 1 && ! V_52 )
F_27 ( NULL , V_50 , V_51 ) ;
F_112 ( V_7 ) ;
V_190:
F_113 ( V_7 ) ;
return V_57 ;
}
