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
F_21 ( L_2 , V_27 -> V_39 ) ;
if ( V_38 ) {
F_23 ( V_27 , F_16 ( V_27 ) ,
F_15 ( V_7 -> V_23 ) ) ;
}
}
}
static void F_24 ( void )
{
struct V_1 V_40 , V_41 ;
F_19 ( false ) ;
F_25 ( V_42 , & V_40 ) ;
F_1 ( & V_41 , & V_40 , & V_43 ) ;
F_26 ( & V_41 , 0 , NULL ) ;
}
static void F_27 ( void )
{
struct V_8 * V_27 ;
if ( V_21 ) {
const int V_29 = F_28 ( V_7 -> V_44 ) ,
V_28 = F_15 ( V_7 -> V_23 ) ;
F_29 ( V_21 * 1000 ) ;
F_20 (evsel_list, counter)
F_30 ( V_27 , V_29 , V_28 ) ;
}
}
static void F_31 ( int T_1 V_45 , T_2 * V_46 ,
void * T_3 V_45 )
{
V_47 = V_46 -> V_48 . V_49 ;
}
static int F_32 ( int V_50 , const char * * V_51 )
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
if ( F_33 ( V_7 , & V_19 , V_51 , false ,
F_31 ) < 0 ) {
perror ( L_3 ) ;
return - 1 ;
}
V_59 = V_7 -> V_60 . V_61 ;
}
if ( V_62 )
F_34 ( V_7 ) ;
F_20 (evsel_list, counter) {
if ( F_5 ( V_27 ) < 0 ) {
if ( V_63 == V_64 || V_63 == V_65 ||
V_63 == V_33 || V_63 == V_66 ||
V_63 == V_67 ) {
if ( V_68 )
F_35 ( L_4 ,
F_36 ( V_27 ) ) ;
V_27 -> V_32 = false ;
if ( ( V_27 -> V_69 != V_27 ) ||
! ( V_27 -> V_69 -> V_70 > 1 ) )
continue;
}
F_37 ( V_27 , & V_19 ,
V_63 , V_53 , sizeof( V_53 ) ) ;
F_38 ( L_5 , V_53 ) ;
if ( V_59 != - 1 )
F_39 ( V_59 , V_71 ) ;
return - 1 ;
}
V_27 -> V_32 = true ;
V_56 = strlen ( V_27 -> V_72 ) ;
if ( V_56 > V_73 )
V_73 = V_56 ;
}
if ( F_40 ( V_7 , & V_27 ) ) {
error ( L_6 ,
V_27 -> V_74 , F_36 ( V_27 ) , V_63 ,
F_41 ( V_63 , V_53 , sizeof( V_53 ) ) ) ;
return - 1 ;
}
V_54 = F_42 () ;
F_25 ( V_42 , & V_43 ) ;
if ( V_58 ) {
F_43 ( V_7 ) ;
F_27 () ;
if ( V_52 ) {
while ( ! F_44 ( V_59 , & V_57 , V_75 ) ) {
F_45 ( & V_40 , NULL ) ;
F_24 () ;
}
}
F_46 ( & V_57 ) ;
if ( V_47 ) {
const char * V_76 = F_41 ( V_47 , V_53 , sizeof( V_53 ) ) ;
F_47 ( L_7 , V_76 ) ;
return - 1 ;
}
if ( F_48 ( V_57 ) )
F_49 ( F_50 ( V_57 ) , V_51 [ 0 ] ) ;
} else {
F_27 () ;
while ( ! V_77 ) {
F_45 ( & V_40 , NULL ) ;
if ( V_52 )
F_24 () ;
}
}
V_55 = F_42 () ;
F_51 ( & V_78 , V_55 - V_54 ) ;
F_19 ( true ) ;
return F_52 ( V_57 ) ;
}
static int F_53 ( int V_50 , const char * * V_51 )
{
int V_79 ;
if ( V_80 ) {
V_79 = system ( V_80 ) ;
if ( V_79 )
return V_79 ;
}
if ( V_81 )
F_54 () ;
V_79 = F_32 ( V_50 , V_51 ) ;
if ( V_79 )
return V_79 ;
if ( V_82 ) {
V_79 = system ( V_82 ) ;
if ( V_79 )
return V_79 ;
}
return V_79 ;
}
static void F_55 ( T_5 V_83 , T_5 V_84 )
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
static void F_56 ( double V_89 , double V_90 )
{
double V_91 = F_57 ( V_89 , V_90 ) ;
if ( V_85 )
fprintf ( V_12 . V_86 , L_11 , V_88 , V_91 ) ;
else if ( V_91 )
fprintf ( V_12 . V_86 , L_12 , V_91 ) ;
}
static void F_58 ( struct V_8 * V_9 , double V_90 )
{
struct V_92 * V_93 ;
if ( V_94 == 1 )
return;
V_93 = V_9 -> V_95 ;
F_56 ( F_59 ( & V_93 -> V_96 [ 0 ] ) , V_90 ) ;
}
static void F_60 ( struct V_8 * V_9 , int V_97 , int V_98 )
{
switch ( V_12 . V_99 ) {
case V_100 :
fprintf ( V_12 . V_86 , L_13 ,
F_61 ( V_97 ) ,
V_85 ? 0 : - 8 ,
F_62 ( V_97 ) ,
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
F_63 ( V_9 -> V_23 , V_97 ) ,
V_85 ? 0 : - 8 ,
F_64 ( V_9 -> V_23 , V_97 ) ,
V_88 ) ;
break;
case V_105 :
default:
break;
}
}
static void F_65 ( int V_97 , int V_98 , struct V_8 * V_9 , double V_90 )
{
T_6 * V_86 = V_12 . V_86 ;
double V_106 = V_90 / 1e6 ;
const char * V_107 , * V_108 ;
char V_39 [ 25 ] ;
V_107 = V_85 ? L_17 : L_18 ;
V_108 = V_85 ? L_19 : L_20 ;
F_60 ( V_9 , V_97 , V_98 ) ;
F_66 ( V_39 , sizeof( V_39 ) , L_21 ,
F_36 ( V_9 ) , V_85 ? L_22 : L_23 ) ;
fprintf ( V_86 , V_107 , V_106 , V_88 ) ;
if ( V_85 )
fprintf ( V_86 , L_21 , V_9 -> V_72 , V_88 ) ;
else
fprintf ( V_86 , L_24 , V_73 , V_9 -> V_72 , V_88 ) ;
fprintf ( V_86 , V_108 , V_39 ) ;
if ( V_9 -> V_109 )
fprintf ( V_86 , L_21 , V_88 , V_9 -> V_109 -> V_39 ) ;
if ( V_85 || V_12 . V_52 )
return;
if ( F_13 ( V_9 , V_24 , V_26 ) )
fprintf ( V_86 , L_25 ,
V_90 / F_67 ( & V_78 ) ) ;
else
fprintf ( V_86 , L_26 ) ;
}
static void F_68 ( int V_97 , int V_98 , struct V_8 * V_9 , double V_90 )
{
T_6 * V_86 = V_12 . V_86 ;
double V_110 = V_9 -> V_13 ;
const char * V_111 ;
int V_30 = F_62 ( V_97 ) ;
if ( V_85 ) {
V_111 = V_110 != 1.0 ? L_27 : L_28 ;
} else {
if ( V_112 )
V_111 = V_110 != 1.0 ? L_29 : L_30 ;
else
V_111 = V_110 != 1.0 ? L_31 : L_32 ;
}
F_60 ( V_9 , V_97 , V_98 ) ;
if ( V_12 . V_99 == V_105 )
V_30 = 0 ;
fprintf ( V_86 , V_111 , V_90 , V_88 ) ;
if ( V_9 -> V_72 )
fprintf ( V_86 , L_24 ,
V_85 ? 0 : V_73 ,
V_9 -> V_72 , V_88 ) ;
fprintf ( V_86 , L_33 , V_85 ? 0 : 25 , F_36 ( V_9 ) ) ;
if ( V_9 -> V_109 )
fprintf ( V_86 , L_21 , V_88 , V_9 -> V_109 -> V_39 ) ;
if ( V_85 || V_12 . V_52 )
return;
F_69 ( V_86 , V_9 , V_90 , V_30 ,
V_12 . V_99 ) ;
}
static void F_70 ( char * V_113 )
{
T_6 * V_86 = V_12 . V_86 ;
struct V_8 * V_27 ;
int V_30 , V_114 , V_115 , V_97 , V_98 ;
double V_116 ;
T_5 V_84 , V_83 , V_117 ;
if ( ! ( V_118 || V_119 ) )
return;
for ( V_114 = 0 ; V_114 < V_118 -> V_98 ; V_114 ++ ) {
V_97 = V_118 -> V_103 [ V_114 ] ;
F_20 (evsel_list, counter) {
V_117 = V_84 = V_83 = 0 ;
V_98 = 0 ;
for ( V_30 = 0 ; V_30 < F_16 ( V_27 ) ; V_30 ++ ) {
V_115 = V_119 ( F_8 ( V_27 ) , V_30 ) ;
if ( V_115 != V_97 )
continue;
V_117 += F_17 ( V_27 -> V_37 , V_30 , 0 ) -> V_117 ;
V_84 += F_17 ( V_27 -> V_37 , V_30 , 0 ) -> V_84 ;
V_83 += F_17 ( V_27 -> V_37 , V_30 , 0 ) -> V_83 ;
V_98 ++ ;
}
if ( V_113 )
fprintf ( V_86 , L_19 , V_113 ) ;
if ( V_83 == 0 || V_84 == 0 ) {
F_60 ( V_27 , V_97 , V_98 ) ;
fprintf ( V_86 , L_34 ,
V_85 ? 0 : 18 ,
V_27 -> V_32 ? V_120 : V_121 ,
V_88 ) ;
fprintf ( V_86 , L_24 ,
V_85 ? 0 : V_73 ,
V_27 -> V_72 , V_88 ) ;
fprintf ( V_86 , L_35 ,
V_85 ? 0 : - 25 ,
F_36 ( V_27 ) ) ;
if ( V_27 -> V_109 )
fprintf ( V_86 , L_21 ,
V_88 , V_27 -> V_109 -> V_39 ) ;
F_55 ( V_83 , V_84 ) ;
fputc ( '\n' , V_86 ) ;
continue;
}
V_116 = V_117 * V_27 -> V_13 ;
if ( F_12 ( V_27 ) )
F_65 ( V_97 , V_98 , V_27 , V_116 ) ;
else
F_68 ( V_97 , V_98 , V_27 , V_116 ) ;
if ( ! V_85 )
F_58 ( V_27 , 1.0 ) ;
F_55 ( V_83 , V_84 ) ;
fputc ( '\n' , V_86 ) ;
}
}
}
static void F_71 ( struct V_8 * V_27 , char * V_113 )
{
T_6 * V_86 = V_12 . V_86 ;
int V_28 = F_15 ( V_27 -> V_23 ) ;
int V_29 = F_28 ( V_27 -> V_44 ) ;
int V_30 , V_31 ;
double V_116 ;
for ( V_31 = 0 ; V_31 < V_28 ; V_31 ++ ) {
T_5 V_84 = 0 , V_83 = 0 , V_117 = 0 ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
V_117 += F_17 ( V_27 -> V_37 , V_30 , V_31 ) -> V_117 ;
V_84 += F_17 ( V_27 -> V_37 , V_30 , V_31 ) -> V_84 ;
V_83 += F_17 ( V_27 -> V_37 , V_30 , V_31 ) -> V_83 ;
}
if ( V_113 )
fprintf ( V_86 , L_19 , V_113 ) ;
V_116 = V_117 * V_27 -> V_13 ;
if ( F_12 ( V_27 ) )
F_65 ( V_31 , 0 , V_27 , V_116 ) ;
else
F_68 ( V_31 , 0 , V_27 , V_116 ) ;
if ( ! V_85 )
F_58 ( V_27 , 1.0 ) ;
F_55 ( V_83 , V_84 ) ;
fputc ( '\n' , V_86 ) ;
}
}
static void F_72 ( struct V_8 * V_27 , char * V_113 )
{
T_6 * V_86 = V_12 . V_86 ;
struct V_92 * V_93 = V_27 -> V_95 ;
double V_90 = F_67 ( & V_93 -> V_96 [ 0 ] ) ;
int V_122 = V_27 -> V_37 -> V_122 ;
double V_116 ;
double V_123 , V_124 ;
V_123 = F_67 ( & V_93 -> V_96 [ 1 ] ) ;
V_124 = F_67 ( & V_93 -> V_96 [ 2 ] ) ;
if ( V_113 )
fprintf ( V_86 , L_19 , V_113 ) ;
if ( V_122 == - 1 || ! V_27 -> V_32 ) {
fprintf ( V_86 , L_34 ,
V_85 ? 0 : 18 ,
V_27 -> V_32 ? V_120 : V_121 ,
V_88 ) ;
fprintf ( V_86 , L_24 ,
V_85 ? 0 : V_73 ,
V_27 -> V_72 , V_88 ) ;
fprintf ( V_86 , L_35 ,
V_85 ? 0 : - 25 ,
F_36 ( V_27 ) ) ;
if ( V_27 -> V_109 )
fprintf ( V_86 , L_21 , V_88 , V_27 -> V_109 -> V_39 ) ;
F_55 ( V_124 , V_123 ) ;
fputc ( '\n' , V_86 ) ;
return;
}
V_116 = V_90 * V_27 -> V_13 ;
if ( F_12 ( V_27 ) )
F_65 ( - 1 , 0 , V_27 , V_116 ) ;
else
F_68 ( - 1 , 0 , V_27 , V_116 ) ;
F_58 ( V_27 , V_90 ) ;
F_55 ( V_124 , V_123 ) ;
fprintf ( V_86 , L_36 ) ;
}
static void F_73 ( struct V_8 * V_27 , char * V_113 )
{
T_6 * V_86 = V_12 . V_86 ;
T_5 V_84 , V_83 , V_117 ;
double V_116 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < F_16 ( V_27 ) ; V_30 ++ ) {
V_117 = F_17 ( V_27 -> V_37 , V_30 , 0 ) -> V_117 ;
V_84 = F_17 ( V_27 -> V_37 , V_30 , 0 ) -> V_84 ;
V_83 = F_17 ( V_27 -> V_37 , V_30 , 0 ) -> V_83 ;
if ( V_113 )
fprintf ( V_86 , L_19 , V_113 ) ;
if ( V_83 == 0 || V_84 == 0 ) {
fprintf ( V_86 , L_37 ,
V_85 ? 0 : - 4 ,
F_8 ( V_27 ) -> V_103 [ V_30 ] , V_88 ,
V_85 ? 0 : 18 ,
V_27 -> V_32 ? V_120 : V_121 ,
V_88 ) ;
fprintf ( V_86 , L_24 ,
V_85 ? 0 : V_73 ,
V_27 -> V_72 , V_88 ) ;
fprintf ( V_86 , L_35 ,
V_85 ? 0 : - 25 ,
F_36 ( V_27 ) ) ;
if ( V_27 -> V_109 )
fprintf ( V_86 , L_21 ,
V_88 , V_27 -> V_109 -> V_39 ) ;
F_55 ( V_83 , V_84 ) ;
fputc ( '\n' , V_86 ) ;
continue;
}
V_116 = V_117 * V_27 -> V_13 ;
if ( F_12 ( V_27 ) )
F_65 ( V_30 , 0 , V_27 , V_116 ) ;
else
F_68 ( V_30 , 0 , V_27 , V_116 ) ;
if ( ! V_85 )
F_58 ( V_27 , 1.0 ) ;
F_55 ( V_83 , V_84 ) ;
fputc ( '\n' , V_86 ) ;
}
}
static void F_74 ( char * V_113 , struct V_1 * V_40 )
{
T_6 * V_86 = V_12 . V_86 ;
static int V_125 ;
sprintf ( V_113 , L_38 , V_40 -> V_5 , V_40 -> V_6 , V_88 ) ;
if ( V_125 == 0 && ! V_85 ) {
switch ( V_12 . V_99 ) {
case V_101 :
fprintf ( V_86 , L_39 , V_73 , L_40 ) ;
break;
case V_100 :
fprintf ( V_86 , L_41 , V_73 , L_40 ) ;
break;
case V_102 :
fprintf ( V_86 , L_42 , V_73 , L_40 ) ;
break;
case V_104 :
fprintf ( V_86 , L_43 , V_73 , L_40 ) ;
break;
case V_105 :
default:
fprintf ( V_86 , L_44 , V_73 , L_40 ) ;
}
}
if ( ++ V_125 == 25 )
V_125 = 0 ;
}
static void F_75 ( int V_50 , const char * * V_51 )
{
T_6 * V_86 = V_12 . V_86 ;
int V_126 ;
fflush ( stdout ) ;
if ( ! V_85 ) {
fprintf ( V_86 , L_36 ) ;
fprintf ( V_86 , L_45 ) ;
if ( V_19 . V_34 )
fprintf ( V_86 , L_46 ) ;
else if ( V_19 . V_127 )
fprintf ( V_86 , L_47 , V_19 . V_127 ) ;
else if ( ! F_9 ( & V_19 ) ) {
fprintf ( V_86 , L_48 , V_51 [ 0 ] ) ;
for ( V_126 = 1 ; V_126 < V_50 ; V_126 ++ )
fprintf ( V_86 , L_49 , V_51 [ V_126 ] ) ;
} else if ( V_19 . V_61 )
fprintf ( V_86 , L_50 , V_19 . V_61 ) ;
else
fprintf ( V_86 , L_51 , V_19 . V_128 ) ;
fprintf ( V_86 , L_52 ) ;
if ( V_94 > 1 )
fprintf ( V_86 , L_53 , V_94 ) ;
fprintf ( V_86 , L_54 ) ;
}
}
static void F_76 ( void )
{
T_6 * V_86 = V_12 . V_86 ;
if ( ! V_129 )
fprintf ( V_86 , L_36 ) ;
fprintf ( V_86 , L_55 ,
F_67 ( & V_78 ) / 1e9 ) ;
if ( V_94 > 1 ) {
fprintf ( V_86 , L_56 ) ;
F_56 ( F_59 ( & V_78 ) ,
F_67 ( & V_78 ) ) ;
}
fprintf ( V_86 , L_57 ) ;
}
static void F_26 ( struct V_1 * V_40 , int V_50 , const char * * V_51 )
{
int V_52 = V_12 . V_52 ;
struct V_8 * V_27 ;
char V_130 [ 64 ] , * V_113 = NULL ;
if ( V_52 )
F_74 ( V_113 = V_130 , V_40 ) ;
else
F_75 ( V_50 , V_51 ) ;
switch ( V_12 . V_99 ) {
case V_100 :
case V_101 :
F_70 ( V_113 ) ;
break;
case V_104 :
F_20 (evsel_list, counter)
F_71 ( V_27 , V_113 ) ;
break;
case V_105 :
F_20 (evsel_list, counter)
F_72 ( V_27 , V_113 ) ;
break;
case V_102 :
F_20 (evsel_list, counter)
F_73 ( V_27 , V_113 ) ;
break;
default:
break;
}
if ( ! V_52 && ! V_85 )
F_76 () ;
fflush ( V_12 . V_86 ) ;
}
static void F_77 ( int T_1 )
{
if ( ( V_59 == - 1 ) || V_12 . V_52 )
V_77 = 1 ;
V_131 = T_1 ;
V_59 = - 1 ;
}
static void F_78 ( void )
{
T_7 V_132 , V_133 ;
F_79 ( & V_132 ) ;
F_80 ( & V_132 , V_134 ) ;
F_81 ( V_135 , & V_132 , & V_133 ) ;
if ( V_59 != - 1 )
F_39 ( V_59 , V_71 ) ;
F_81 ( V_136 , & V_133 , NULL ) ;
if ( V_131 == - 1 )
return;
signal ( V_131 , V_137 ) ;
F_39 ( F_82 () , V_131 ) ;
}
static int F_83 ( const struct V_138 * T_8 V_45 ,
const char * V_114 V_45 , int V_139 )
{
V_140 = V_139 ? 0 : 1 ;
return 0 ;
}
static int F_84 ( void )
{
switch ( V_12 . V_99 ) {
case V_101 :
if ( F_85 ( V_7 -> V_44 , & V_118 ) ) {
perror ( L_58 ) ;
return - 1 ;
}
V_119 = V_141 ;
break;
case V_100 :
if ( F_86 ( V_7 -> V_44 , & V_118 ) ) {
perror ( L_59 ) ;
return - 1 ;
}
V_119 = V_142 ;
break;
case V_102 :
case V_105 :
case V_104 :
default:
break;
}
return 0 ;
}
static int F_87 ( void )
{
struct V_10 V_143 [] = {
{ . type = V_144 , . V_145 = V_146 } ,
{ . type = V_144 , . V_145 = V_147 } ,
{ . type = V_144 , . V_145 = V_148 } ,
{ . type = V_144 , . V_145 = V_149 } ,
{ . type = V_150 , . V_145 = V_151 } ,
{ . type = V_150 , . V_145 = V_152 } ,
{ . type = V_150 , . V_145 = V_153 } ,
{ . type = V_150 , . V_145 = V_154 } ,
{ . type = V_150 , . V_145 = V_155 } ,
{ . type = V_150 , . V_145 = V_156 } ,
} ;
struct V_10 V_157 [] = {
{ . type = V_158 ,
. V_145 =
V_159 << 0 |
( V_160 << 8 ) |
( V_161 << 16 ) } ,
{ . type = V_158 ,
. V_145 =
V_159 << 0 |
( V_160 << 8 ) |
( V_162 << 16 ) } ,
{ . type = V_158 ,
. V_145 =
V_163 << 0 |
( V_160 << 8 ) |
( V_161 << 16 ) } ,
{ . type = V_158 ,
. V_145 =
V_163 << 0 |
( V_160 << 8 ) |
( V_162 << 16 ) } ,
} ;
struct V_10 V_164 [] = {
{ . type = V_158 ,
. V_145 =
V_165 << 0 |
( V_160 << 8 ) |
( V_161 << 16 ) } ,
{ . type = V_158 ,
. V_145 =
V_165 << 0 |
( V_160 << 8 ) |
( V_162 << 16 ) } ,
{ . type = V_158 ,
. V_145 =
V_166 << 0 |
( V_160 << 8 ) |
( V_161 << 16 ) } ,
{ . type = V_158 ,
. V_145 =
V_166 << 0 |
( V_160 << 8 ) |
( V_162 << 16 ) } ,
{ . type = V_158 ,
. V_145 =
V_167 << 0 |
( V_160 << 8 ) |
( V_161 << 16 ) } ,
{ . type = V_158 ,
. V_145 =
V_167 << 0 |
( V_160 << 8 ) |
( V_162 << 16 ) } ,
} ;
struct V_10 V_168 [] = {
{ . type = V_158 ,
. V_145 =
V_159 << 0 |
( V_169 << 8 ) |
( V_161 << 16 ) } ,
{ . type = V_158 ,
. V_145 =
V_159 << 0 |
( V_169 << 8 ) |
( V_162 << 16 ) } ,
} ;
if ( V_129 )
return 0 ;
if ( V_170 ) {
int V_171 ;
if ( F_88 ( L_60 , L_61 ) &&
F_88 ( L_60 , L_62 ) )
V_171 = F_89 ( V_7 , V_172 , NULL ) ;
else
V_171 = F_89 ( V_7 , V_173 , NULL ) ;
if ( V_171 ) {
fprintf ( V_174 , L_63 ) ;
return - 1 ;
}
return 0 ;
}
if ( ! V_7 -> V_175 ) {
if ( F_90 ( V_7 , V_143 ) < 0 )
return - 1 ;
}
if ( V_176 < 1 )
return 0 ;
if ( F_90 ( V_7 , V_157 ) < 0 )
return - 1 ;
if ( V_176 < 2 )
return 0 ;
if ( F_90 ( V_7 , V_164 ) < 0 )
return - 1 ;
if ( V_176 < 3 )
return 0 ;
return F_90 ( V_7 , V_168 ) ;
}
int F_91 ( int V_50 , const char * * V_51 , const char * V_113 V_45 )
{
bool V_177 = false ;
int V_178 = 0 ;
const char * V_179 = NULL ;
const struct V_138 V_180 [] = {
F_92 ( 'T' , L_64 , & V_170 ,
L_65 ) ,
F_93 ( 'e' , L_66 , & V_7 , L_66 ,
L_67 ,
V_181 ) ,
F_93 ( 0 , L_68 , & V_7 , L_68 ,
L_69 , V_182 ) ,
F_92 ( 'i' , L_70 , & V_18 ,
L_71 ) ,
F_94 ( 'p' , L_72 , & V_19 . V_61 , L_72 ,
L_73 ) ,
F_94 ( 't' , L_74 , & V_19 . V_128 , L_74 ,
L_75 ) ,
F_92 ( 'a' , L_76 , & V_19 . V_34 ,
L_77 ) ,
F_92 ( 'g' , L_78 , & V_62 ,
L_79 ) ,
F_92 ( 'c' , L_80 , & V_12 . V_13 , L_81 ) ,
F_95 ( 'v' , L_82 , & V_68 ,
L_83 ) ,
F_96 ( 'r' , L_84 , & V_94 ,
L_85 ) ,
F_92 ( 'n' , L_86 , & V_129 ,
L_87 ) ,
F_95 ( 'd' , L_88 , & V_176 ,
L_89 ) ,
F_92 ( 'S' , L_90 , & V_81 ,
L_91 ) ,
F_97 ( 'B' , L_92 , NULL , NULL ,
L_93 ,
F_83 ) ,
F_94 ( 'C' , L_60 , & V_19 . V_127 , L_60 ,
L_94 ) ,
F_98 ( 'A' , L_95 , & V_12 . V_99 ,
L_96 , V_102 ) ,
F_94 ( 'x' , L_97 , & V_88 , L_98 ,
L_99 ) ,
F_93 ( 'G' , L_100 , & V_7 , L_101 ,
L_102 , V_183 ) ,
F_94 ( 'o' , L_103 , & V_179 , L_104 , L_105 ) ,
F_92 ( 0 , L_106 , & V_177 , L_107 ) ,
F_96 ( 0 , L_108 , & V_178 ,
L_109 ) ,
F_94 ( 0 , L_110 , & V_80 , L_111 ,
L_112 ) ,
F_94 ( 0 , L_113 , & V_82 , L_111 ,
L_114 ) ,
F_99 ( 'I' , L_115 , & V_12 . V_52 ,
L_116 ) ,
F_98 ( 0 , L_117 , & V_12 . V_99 ,
L_118 , V_101 ) ,
F_98 ( 0 , L_119 , & V_12 . V_99 ,
L_120 , V_100 ) ,
F_98 ( 0 , L_121 , & V_12 . V_99 ,
L_122 , V_104 ) ,
F_99 ( 'D' , L_123 , & V_21 ,
L_124 ) ,
F_100 ()
} ;
const char * const V_184 [] = {
L_125 ,
NULL
} ;
int V_57 = - V_64 , V_185 ;
const char * V_186 ;
T_6 * V_86 = V_174 ;
unsigned int V_52 ;
setlocale ( V_187 , L_22 ) ;
V_7 = F_101 () ;
if ( V_7 == NULL )
return - V_188 ;
V_50 = F_102 ( V_50 , V_51 , V_180 , V_184 ,
V_189 ) ;
V_52 = V_12 . V_52 ;
if ( V_179 && strcmp ( V_179 , L_126 ) )
V_86 = NULL ;
if ( V_179 && V_178 ) {
fprintf ( V_174 , L_127 ) ;
F_103 ( V_184 , V_180 , L_128 , 1 ) ;
F_103 ( NULL , V_180 , L_108 , 0 ) ;
goto V_190;
}
if ( V_178 < 0 ) {
fprintf ( V_174 , L_129 ) ;
F_103 ( V_184 , V_180 , L_108 , 0 ) ;
goto V_190;
}
if ( ! V_86 ) {
struct V_1 V_191 ;
V_186 = V_177 ? L_130 : L_131 ;
V_86 = fopen ( V_179 , V_186 ) ;
if ( ! V_86 ) {
perror ( L_132 ) ;
return - 1 ;
}
F_25 ( V_192 , & V_191 ) ;
fprintf ( V_86 , L_133 , ctime ( & V_191 . V_5 ) ) ;
} else if ( V_178 > 0 ) {
V_186 = V_177 ? L_130 : L_131 ;
V_86 = fdopen ( V_178 , V_186 ) ;
if ( ! V_86 ) {
perror ( L_134 ) ;
return - V_63 ;
}
}
V_12 . V_86 = V_86 ;
if ( V_88 ) {
V_85 = true ;
if ( ! strcmp ( V_88 , L_135 ) )
V_88 = L_136 ;
} else
V_88 = V_193 ;
if ( V_85 ) {
if ( V_140 == 1 ) {
fprintf ( V_174 , L_137 ) ;
F_103 ( V_184 , V_180 , L_138 , 1 ) ;
F_103 ( NULL , V_180 , L_139 , 1 ) ;
goto V_190;
} else
V_112 = false ;
} else if ( V_140 == 0 )
V_112 = false ;
if ( ! V_50 && F_104 ( & V_19 ) )
F_105 ( V_184 , V_180 ) ;
if ( V_94 < 0 ) {
F_47 ( L_140 ) ;
F_103 ( V_184 , V_180 , L_141 , 1 ) ;
goto V_190;
} else if ( V_94 == 0 ) {
V_194 = true ;
V_94 = 1 ;
}
if ( ( V_12 . V_99 == V_104 ) && ! F_9 ( & V_19 ) ) {
fprintf ( V_174 , L_142
L_143 ) ;
F_103 ( NULL , V_180 , L_144 , 1 ) ;
F_103 ( NULL , V_180 , L_145 , 1 ) ;
goto V_190;
}
if ( ( ( V_12 . V_99 != V_105 &&
V_12 . V_99 != V_104 ) || V_195 ) &&
! F_6 ( & V_19 ) ) {
fprintf ( V_174 , L_146
L_147 ) ;
F_103 ( V_184 , V_180 , L_148 , 1 ) ;
F_103 ( NULL , V_180 , L_149 , 1 ) ;
F_103 ( NULL , V_180 , L_130 , 1 ) ;
goto V_190;
}
if ( F_87 () )
goto V_190;
F_106 ( & V_19 ) ;
if ( F_107 ( V_7 , & V_19 ) < 0 ) {
if ( F_9 ( & V_19 ) ) {
F_47 ( L_150 ) ;
F_103 ( V_184 , V_180 , L_144 , 1 ) ;
F_103 ( NULL , V_180 , L_145 , 1 ) ;
} else if ( F_6 ( & V_19 ) ) {
perror ( L_151 ) ;
F_103 ( V_184 , V_180 , L_152 , 1 ) ;
F_103 ( NULL , V_180 , L_130 , 1 ) ;
}
goto V_190;
}
if ( V_12 . V_99 == V_104 )
F_108 ( V_7 -> V_23 ) ;
if ( V_52 && V_52 < 100 ) {
F_47 ( L_153 ) ;
F_103 ( V_184 , V_180 , L_154 , 1 ) ;
goto V_190;
}
if ( F_109 ( V_7 , V_52 ) )
goto V_190;
if ( F_84 () )
goto V_190;
atexit ( F_78 ) ;
if ( ! V_194 )
signal ( V_196 , F_77 ) ;
signal ( V_134 , F_77 ) ;
signal ( V_197 , F_77 ) ;
signal ( V_198 , F_77 ) ;
V_57 = 0 ;
for ( V_185 = 0 ; V_194 || V_185 < V_94 ; V_185 ++ ) {
if ( V_94 != 1 && V_68 )
fprintf ( V_86 , L_155 ,
V_185 + 1 ) ;
V_57 = F_53 ( V_50 , V_51 ) ;
if ( V_194 && V_57 != - 1 ) {
F_26 ( NULL , V_50 , V_51 ) ;
F_2 () ;
}
}
if ( ! V_194 && V_57 != - 1 && ! V_52 )
F_26 ( NULL , V_50 , V_51 ) ;
F_110 ( V_7 ) ;
V_190:
F_111 ( V_7 ) ;
return V_57 ;
}
