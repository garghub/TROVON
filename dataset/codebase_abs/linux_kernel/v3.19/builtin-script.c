static bool F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_4 )
return true ;
}
return false ;
}
static const char * F_2 ( enum V_5 V_6 )
{
int V_7 , V_8 = F_3 ( V_9 ) ;
const char * V_10 = L_1 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( V_9 [ V_7 ] . V_6 == V_6 ) {
V_10 = V_9 [ V_7 ] . V_10 ;
break;
}
}
return V_10 ;
}
static int F_4 ( struct V_11 * V_12 ,
T_1 V_13 , const char * V_14 ,
enum V_5 V_6 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
int type = V_16 -> type ;
const char * V_17 ;
if ( V_16 -> V_13 & V_13 )
return 0 ;
if ( V_3 [ type ] . V_4 ) {
V_17 = F_5 ( V_12 ) ;
F_6 ( L_2
L_3 ,
V_17 , V_14 , F_2 ( V_6 ) ) ;
return - 1 ;
}
V_3 [ type ] . V_18 &= ~ V_6 ;
V_17 = F_5 ( V_12 ) ;
F_7 ( L_2
L_4 ,
V_17 , V_14 , F_2 ( V_6 ) ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 ,
struct V_19 * V_20 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( F_9 ( V_21 ) &&
! F_10 ( V_20 , L_5 ) )
return - V_22 ;
if ( F_9 ( V_23 ) ) {
if ( F_4 ( V_12 , V_24 , L_6 ,
V_25 ) )
return - V_22 ;
}
if ( F_9 ( V_26 ) &&
F_4 ( V_12 , V_27 , L_7 ,
V_28 ) )
return - V_22 ;
if ( F_9 ( V_29 ) && ! F_9 ( V_23 ) && ! F_9 ( V_26 ) ) {
F_6 ( L_8
L_9
L_10 ) ;
return - V_22 ;
}
if ( F_9 ( V_30 ) && ! F_9 ( V_29 ) ) {
F_6 ( L_11
L_12 ) ;
return - V_22 ;
}
if ( F_9 ( V_31 ) && ! F_9 ( V_23 ) && ! F_9 ( V_26 ) ) {
F_6 ( L_13
L_9
L_14 ) ;
return - V_22 ;
}
if ( F_9 ( V_32 ) && ! F_9 ( V_23 ) ) {
F_6 ( L_15
L_16 ) ;
return - V_22 ;
}
if ( ( F_9 ( V_33 ) || F_9 ( V_34 ) ) &&
F_4 ( V_12 , V_35 , L_17 ,
V_36 | V_37 ) )
return - V_22 ;
if ( F_9 ( TIME ) &&
F_4 ( V_12 , V_38 , L_18 ,
V_39 ) )
return - V_22 ;
if ( F_9 ( V_40 ) &&
F_4 ( V_12 , V_41 , L_19 ,
V_42 ) )
return - V_22 ;
if ( F_9 ( V_43 ) &&
F_4 ( V_12 , V_44 , L_20 ,
V_45 ) )
return - V_22 ;
return 0 ;
}
static void F_11 ( struct V_15 * V_16 )
{
unsigned int type = V_16 -> type ;
V_3 [ type ] . V_46 = 0 ;
if ( F_9 ( V_23 ) )
V_3 [ type ] . V_46 |= V_47 ;
if ( F_9 ( V_29 ) )
V_3 [ type ] . V_46 |= V_48 ;
if ( F_9 ( V_31 ) )
V_3 [ type ] . V_46 |= V_49 ;
if ( F_9 ( V_30 ) )
V_3 [ type ] . V_46 |= V_50 ;
if ( F_9 ( V_32 ) )
V_3 [ type ] . V_46 |= V_51 ;
}
static int F_12 ( struct V_19 * V_20 )
{
int V_1 ;
struct V_11 * V_12 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_12 = F_13 ( V_20 , V_1 ) ;
if ( ! V_12 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_52 ) {
F_6 ( L_21
L_22 ,
F_14 ( V_1 ) ) ;
return - 1 ;
}
if ( V_12 && V_3 [ V_1 ] . V_18 &&
F_8 ( V_12 , V_20 ) )
return - 1 ;
if ( V_12 == NULL )
continue;
F_11 ( & V_12 -> V_16 ) ;
}
if ( ! V_53 ) {
bool V_54 = false ;
F_15 (session->evlist, evsel) {
if ( V_12 -> V_16 . V_13 & V_55 ) {
V_54 = true ;
break;
}
}
if ( ! V_54 )
V_56 . V_54 = false ;
}
if ( V_56 . V_54 &&
! V_3 [ V_57 ] . V_4 ) {
struct V_15 * V_16 ;
V_1 = V_57 ;
V_12 = F_13 ( V_20 , V_1 ) ;
if ( V_12 == NULL )
goto V_58;
V_16 = & V_12 -> V_16 ;
if ( V_16 -> V_13 & V_55 ) {
V_3 [ V_1 ] . V_18 |= V_25 ;
V_3 [ V_1 ] . V_18 |= V_59 ;
V_3 [ V_1 ] . V_18 |= V_60 ;
F_11 ( V_16 ) ;
}
}
V_58:
return 0 ;
}
static void F_16 ( struct V_61 * V_62 ,
struct V_63 * V_63 ,
struct V_11 * V_12 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
unsigned long V_64 ;
unsigned long V_65 ;
unsigned long long V_66 ;
if ( F_9 ( V_67 ) ) {
if ( V_68 )
printf ( L_23 , F_17 ( V_63 ) ) ;
else if ( F_9 ( V_23 ) && V_56 . V_54 )
printf ( L_24 , F_17 ( V_63 ) ) ;
else
printf ( L_25 , F_17 ( V_63 ) ) ;
}
if ( F_9 ( V_33 ) && F_9 ( V_34 ) )
printf ( L_26 , V_62 -> V_69 , V_62 -> V_70 ) ;
else if ( F_9 ( V_33 ) )
printf ( L_27 , V_62 -> V_69 ) ;
else if ( F_9 ( V_34 ) )
printf ( L_27 , V_62 -> V_70 ) ;
if ( F_9 ( V_40 ) ) {
if ( V_68 )
printf ( L_28 , V_62 -> V_71 ) ;
else
printf ( L_29 , V_62 -> V_71 ) ;
}
if ( F_9 ( TIME ) ) {
V_66 = V_62 -> time ;
V_64 = V_66 / V_72 ;
V_66 -= V_64 * V_72 ;
V_65 = V_66 / V_73 ;
printf ( L_30 , V_64 , V_65 ) ;
}
}
static void F_18 ( union V_74 * V_75 ,
struct V_61 * V_62 ,
struct V_63 * V_63 ,
struct V_15 * V_16 )
{
struct V_76 V_77 ;
printf ( L_31 V_78 , V_62 -> V_79 ) ;
if ( ! F_19 ( V_16 ) )
return;
F_20 ( V_75 , V_62 , V_63 , & V_77 ) ;
if ( F_9 ( V_29 ) ) {
printf ( L_32 ) ;
if ( F_9 ( V_30 ) )
F_21 ( V_77 . V_80 , & V_77 , stdout ) ;
else
F_22 ( V_77 . V_80 , stdout ) ;
}
if ( F_9 ( V_31 ) ) {
printf ( L_33 ) ;
F_23 ( V_77 . V_81 , stdout ) ;
printf ( L_34 ) ;
}
}
static void F_24 ( union V_74 * V_75 ,
struct V_61 * V_62 ,
struct V_11 * V_12 ,
struct V_63 * V_63 ,
struct V_76 * V_77 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
bool V_82 = false ;
if ( F_9 ( V_23 ) ) {
unsigned int V_83 = V_3 [ V_16 -> type ] . V_46 ;
if ( V_56 . V_54 && V_62 -> V_84 ) {
printf ( L_35 ) ;
} else {
printf ( L_32 ) ;
if ( V_83 & V_51 ) {
V_82 = true ;
V_83 &= ~ V_51 ;
}
}
F_25 ( V_12 , V_62 , V_77 , V_83 ,
V_85 ) ;
}
if ( F_9 ( V_26 ) ||
( ( V_12 -> V_16 . V_13 & V_27 ) &&
! V_3 [ V_16 -> type ] . V_4 ) ) {
printf ( L_36 ) ;
F_18 ( V_75 , V_62 , V_63 , V_16 ) ;
}
if ( V_82 )
F_26 ( V_77 -> V_81 , V_77 -> V_79 , L_37 , stdout ) ;
printf ( L_35 ) ;
}
static void F_27 ( union V_74 * V_75 , struct V_61 * V_62 ,
struct V_11 * V_12 , struct V_63 * V_63 ,
struct V_76 * V_77 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( V_3 [ V_16 -> type ] . V_18 == 0 )
return;
F_16 ( V_62 , V_63 , V_12 ) ;
if ( F_9 ( V_43 ) )
printf ( L_38 V_86 L_32 , V_62 -> V_87 ) ;
if ( F_9 ( V_88 ) ) {
const char * V_17 = F_5 ( V_12 ) ;
printf ( L_39 , V_17 ? V_17 : L_40 ) ;
}
if ( F_28 ( V_16 ) ) {
F_24 ( V_75 , V_62 , V_12 , V_63 , V_77 ) ;
return;
}
if ( F_9 ( V_21 ) )
F_29 ( V_12 -> V_89 , V_62 -> V_71 ,
V_62 -> V_90 , V_62 -> V_91 ) ;
if ( F_9 ( V_26 ) )
F_18 ( V_75 , V_62 , V_63 , V_16 ) ;
if ( F_9 ( V_23 ) ) {
if ( ! V_56 . V_54 )
printf ( L_32 ) ;
else
printf ( L_35 ) ;
F_25 ( V_12 , V_62 , V_77 ,
V_3 [ V_16 -> type ] . V_46 ,
V_85 ) ;
}
printf ( L_35 ) ;
}
static int F_30 ( const char * T_2 V_92 ,
int T_3 V_92 ,
const char * * T_4 V_92 )
{
return 0 ;
}
static int F_31 ( void )
{
return 0 ;
}
static int F_32 ( void )
{
return 0 ;
}
static int F_33 ( struct V_93 * V_93 V_92 ,
const char * T_5 V_92 )
{
return 0 ;
}
static void F_34 ( void )
{
F_35 () ;
F_36 () ;
V_94 = & V_95 ;
}
static int F_37 ( void )
{
return V_94 -> V_96 () ;
}
static int F_38 ( void )
{
F_7 ( L_41 ) ;
return V_94 -> V_97 () ;
}
static int F_39 ( struct V_98 * T_6 V_92 ,
union V_74 * V_75 ,
struct V_61 * V_62 ,
struct V_11 * V_12 ,
struct V_99 * V_99 )
{
struct V_76 V_77 ;
struct V_63 * V_63 = F_40 ( V_99 , V_62 -> V_69 ,
V_62 -> V_70 ) ;
if ( V_63 == NULL ) {
F_7 ( L_42 ,
V_75 -> V_100 . type ) ;
return - 1 ;
}
if ( V_101 ) {
if ( V_62 -> time < V_102 ) {
F_6 ( L_43 V_86
L_44 V_86 L_35 , V_102 ,
V_62 -> time ) ;
V_103 ++ ;
}
V_102 = V_62 -> time ;
return 0 ;
}
if ( F_41 ( V_75 , V_99 , & V_77 , V_62 ) < 0 ) {
F_6 ( L_42 ,
V_75 -> V_100 . type ) ;
return - 1 ;
}
if ( V_77 . V_104 )
return 0 ;
if ( V_105 && ! F_42 ( V_62 -> V_71 , V_106 ) )
return 0 ;
V_94 -> F_27 ( V_75 , V_62 , V_12 , V_63 , & V_77 ) ;
return 0 ;
}
static int F_43 ( struct V_98 * T_6 , union V_74 * V_75 ,
struct V_107 * * V_108 )
{
struct V_109 * V_110 = F_44 ( T_6 , struct V_109 , T_6 ) ;
struct V_107 * V_111 ;
struct V_11 * V_12 , * V_112 ;
int V_113 ;
V_113 = F_45 ( T_6 , V_75 , V_108 ) ;
if ( V_113 )
return V_113 ;
V_111 = * V_108 ;
V_12 = F_46 ( * V_108 ) ;
if ( V_12 -> V_16 . type >= V_2 )
return 0 ;
F_15 (evlist, pos) {
if ( V_112 -> V_16 . type == V_12 -> V_16 . type && V_112 != V_12 )
return 0 ;
}
F_11 ( & V_12 -> V_16 ) ;
return F_8 ( V_12 , V_110 -> V_20 ) ;
}
static int F_47 ( struct V_98 * T_6 ,
union V_74 * V_75 ,
struct V_61 * V_62 ,
struct V_99 * V_99 )
{
struct V_63 * V_63 ;
struct V_109 * T_2 = F_44 ( T_6 , struct V_109 , T_6 ) ;
struct V_19 * V_20 = T_2 -> V_20 ;
struct V_11 * V_12 = F_48 ( V_20 -> V_111 ) ;
int V_114 = - 1 ;
V_63 = F_40 ( V_99 , V_75 -> V_115 . V_69 , V_75 -> V_115 . V_70 ) ;
if ( V_63 == NULL ) {
F_7 ( L_45 ) ;
return - 1 ;
}
if ( F_49 ( T_6 , V_75 , V_62 , V_99 ) < 0 )
goto V_58;
if ( ! V_12 -> V_16 . V_116 ) {
V_62 -> V_71 = 0 ;
V_62 -> time = 0 ;
V_62 -> V_70 = V_75 -> V_115 . V_70 ;
V_62 -> V_69 = V_75 -> V_115 . V_69 ;
}
F_16 ( V_62 , V_63 , V_12 ) ;
F_50 ( V_75 , stdout ) ;
V_114 = 0 ;
V_58:
return V_114 ;
}
static int F_51 ( struct V_98 * T_6 ,
union V_74 * V_75 ,
struct V_61 * V_62 ,
struct V_99 * V_99 )
{
struct V_63 * V_63 ;
struct V_109 * T_2 = F_44 ( T_6 , struct V_109 , T_6 ) ;
struct V_19 * V_20 = T_2 -> V_20 ;
struct V_11 * V_12 = F_48 ( V_20 -> V_111 ) ;
if ( F_52 ( T_6 , V_75 , V_62 , V_99 ) < 0 )
return - 1 ;
V_63 = F_40 ( V_99 , V_75 -> V_117 . V_69 , V_75 -> V_117 . V_70 ) ;
if ( V_63 == NULL ) {
F_7 ( L_46 ) ;
return - 1 ;
}
if ( ! V_12 -> V_16 . V_116 ) {
V_62 -> V_71 = 0 ;
V_62 -> time = V_75 -> V_117 . time ;
V_62 -> V_70 = V_75 -> V_117 . V_70 ;
V_62 -> V_69 = V_75 -> V_117 . V_69 ;
}
F_16 ( V_62 , V_63 , V_12 ) ;
F_50 ( V_75 , stdout ) ;
return 0 ;
}
static int F_53 ( struct V_98 * T_6 ,
union V_74 * V_75 ,
struct V_61 * V_62 ,
struct V_99 * V_99 )
{
struct V_63 * V_63 ;
struct V_109 * T_2 = F_44 ( T_6 , struct V_109 , T_6 ) ;
struct V_19 * V_20 = T_2 -> V_20 ;
struct V_11 * V_12 = F_48 ( V_20 -> V_111 ) ;
V_63 = F_40 ( V_99 , V_75 -> V_117 . V_69 , V_75 -> V_117 . V_70 ) ;
if ( V_63 == NULL ) {
F_7 ( L_47 ) ;
return - 1 ;
}
if ( ! V_12 -> V_16 . V_116 ) {
V_62 -> V_71 = 0 ;
V_62 -> time = 0 ;
V_62 -> V_70 = V_75 -> V_115 . V_70 ;
V_62 -> V_69 = V_75 -> V_115 . V_69 ;
}
F_16 ( V_62 , V_63 , V_12 ) ;
F_50 ( V_75 , stdout ) ;
if ( F_54 ( T_6 , V_75 , V_62 , V_99 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_55 ( struct V_98 * T_6 ,
union V_74 * V_75 ,
struct V_61 * V_62 ,
struct V_99 * V_99 )
{
struct V_63 * V_63 ;
struct V_109 * T_2 = F_44 ( T_6 , struct V_109 , T_6 ) ;
struct V_19 * V_20 = T_2 -> V_20 ;
struct V_11 * V_12 = F_48 ( V_20 -> V_111 ) ;
if ( F_56 ( T_6 , V_75 , V_62 , V_99 ) < 0 )
return - 1 ;
V_63 = F_40 ( V_99 , V_75 -> V_118 . V_69 , V_75 -> V_118 . V_70 ) ;
if ( V_63 == NULL ) {
F_7 ( L_48 ) ;
return - 1 ;
}
if ( ! V_12 -> V_16 . V_116 ) {
V_62 -> V_71 = 0 ;
V_62 -> time = 0 ;
V_62 -> V_70 = V_75 -> V_118 . V_70 ;
V_62 -> V_69 = V_75 -> V_118 . V_69 ;
}
F_16 ( V_62 , V_63 , V_12 ) ;
F_50 ( V_75 , stdout ) ;
return 0 ;
}
static int F_57 ( struct V_98 * T_6 ,
union V_74 * V_75 ,
struct V_61 * V_62 ,
struct V_99 * V_99 )
{
struct V_63 * V_63 ;
struct V_109 * T_2 = F_44 ( T_6 , struct V_109 , T_6 ) ;
struct V_19 * V_20 = T_2 -> V_20 ;
struct V_11 * V_12 = F_48 ( V_20 -> V_111 ) ;
if ( F_58 ( T_6 , V_75 , V_62 , V_99 ) < 0 )
return - 1 ;
V_63 = F_40 ( V_99 , V_75 -> V_119 . V_69 , V_75 -> V_119 . V_70 ) ;
if ( V_63 == NULL ) {
F_7 ( L_49 ) ;
return - 1 ;
}
if ( ! V_12 -> V_16 . V_116 ) {
V_62 -> V_71 = 0 ;
V_62 -> time = 0 ;
V_62 -> V_70 = V_75 -> V_119 . V_70 ;
V_62 -> V_69 = V_75 -> V_119 . V_69 ;
}
F_16 ( V_62 , V_63 , V_12 ) ;
F_50 ( V_75 , stdout ) ;
return 0 ;
}
static void F_59 ( int T_7 V_92 )
{
V_120 = 1 ;
}
static int F_60 ( struct V_109 * T_2 )
{
int V_114 ;
signal ( V_121 , F_59 ) ;
if ( T_2 -> V_122 ) {
T_2 -> T_6 . V_115 = F_47 ;
T_2 -> T_6 . V_117 = F_51 ;
T_2 -> T_6 . exit = F_53 ;
}
if ( T_2 -> V_123 ) {
T_2 -> T_6 . V_118 = F_55 ;
T_2 -> T_6 . V_119 = F_57 ;
}
V_114 = F_61 ( T_2 -> V_20 , & T_2 -> T_6 ) ;
if ( V_101 )
F_6 ( L_50 V_86 L_35 , V_103 ) ;
return V_114 ;
}
static struct V_124 * F_62 ( const char * V_125 ,
struct V_94 * V_126 )
{
struct V_124 * V_127 = malloc ( sizeof( * V_127 ) + strlen ( V_125 ) + 1 ) ;
if ( V_127 != NULL ) {
strcpy ( V_127 -> V_125 , V_125 ) ;
V_127 -> V_126 = V_126 ;
}
return V_127 ;
}
static void F_63 ( struct V_124 * V_127 )
{
F_64 ( & V_127 -> V_128 , & V_129 ) ;
}
static struct V_124 * F_65 ( const char * V_125 )
{
struct V_124 * V_127 ;
F_66 (s, &script_specs, node)
if ( strcasecmp ( V_127 -> V_125 , V_125 ) == 0 )
return V_127 ;
return NULL ;
}
static struct V_124 * F_67 ( const char * V_125 ,
struct V_94 * V_126 )
{
struct V_124 * V_127 = F_65 ( V_125 ) ;
if ( V_127 )
return V_127 ;
V_127 = F_62 ( V_125 , V_126 ) ;
if ( ! V_127 )
return NULL ;
F_63 ( V_127 ) ;
return V_127 ;
}
int F_68 ( const char * V_125 , struct V_94 * V_126 )
{
struct V_124 * V_127 ;
V_127 = F_65 ( V_125 ) ;
if ( V_127 )
return - 1 ;
V_127 = F_67 ( V_125 , V_126 ) ;
if ( ! V_127 )
return - 1 ;
return 0 ;
}
static struct V_94 * F_69 ( const char * V_125 )
{
struct V_124 * V_127 = F_65 ( V_125 ) ;
if ( ! V_127 )
return NULL ;
return V_127 -> V_126 ;
}
static void F_70 ( void )
{
struct V_124 * V_127 ;
fprintf ( V_130 , L_35 ) ;
fprintf ( V_130 , L_51
L_52 ) ;
F_66 (s, &script_specs, node)
fprintf ( V_130 , L_53 , V_127 -> V_125 , V_127 -> V_126 -> V_131 ) ;
fprintf ( V_130 , L_35 ) ;
}
static int F_71 ( const struct V_132 * T_8 V_92 ,
const char * V_10 , int T_9 V_92 )
{
char V_125 [ V_133 ] ;
const char * T_2 , * V_134 ;
int V_135 ;
if ( strcmp ( V_10 , L_54 ) == 0 ) {
F_70 () ;
exit ( 0 ) ;
}
T_2 = strchr ( V_10 , ':' ) ;
if ( T_2 ) {
V_135 = T_2 - V_10 ;
if ( V_135 >= V_133 ) {
fprintf ( V_130 , L_55 ) ;
return - 1 ;
}
strncpy ( V_125 , V_10 , V_135 ) ;
V_125 [ V_135 ] = '\0' ;
V_94 = F_69 ( V_125 ) ;
if ( ! V_94 ) {
fprintf ( V_130 , L_55 ) ;
return - 1 ;
}
T_2 ++ ;
} else {
T_2 = V_10 ;
V_134 = strrchr ( T_2 , '.' ) ;
if ( ! V_134 ) {
fprintf ( V_130 , L_56 ) ;
return - 1 ;
}
V_94 = F_69 ( ++ V_134 ) ;
if ( ! V_94 ) {
fprintf ( V_130 , L_56 ) ;
return - 1 ;
}
}
V_136 = F_72 ( T_2 ) ;
return 0 ;
}
static int F_73 ( const struct V_132 * T_8 V_92 ,
const char * V_137 , int T_9 V_92 )
{
char * V_138 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_139 = 0 ;
char * V_10 = F_72 ( V_137 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_140 ;
V_138 = strchr ( V_10 , ':' ) ;
if ( V_138 ) {
* V_138 = '\0' ;
V_138 ++ ;
if ( ! strcmp ( V_10 , L_57 ) )
type = V_141 ;
else if ( ! strcmp ( V_10 , L_58 ) )
type = V_142 ;
else if ( ! strcmp ( V_10 , L_59 ) )
type = V_57 ;
else if ( ! strcmp ( V_10 , L_60 ) )
type = V_143 ;
else {
fprintf ( V_130 , L_61 ) ;
V_139 = - V_22 ;
goto V_58;
}
if ( V_3 [ type ] . V_4 )
F_74 ( L_62 ,
F_14 ( type ) ) ;
V_3 [ type ] . V_18 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_52 = false ;
} else {
V_138 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_130 ,
L_63 ) ;
V_139 = - V_22 ;
goto V_58;
}
if ( F_1 () )
F_74 ( L_64 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_18 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_52 = true ;
}
}
V_138 = strtok ( V_138 , L_65 ) ;
while ( V_138 ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_138 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 ) {
fprintf ( V_130 , L_66 ) ;
V_139 = - V_22 ;
goto V_58;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_144 & V_9 [ V_7 ] . V_6 ) {
F_74 ( L_67 ,
V_9 [ V_7 ] . V_10 , F_14 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_144 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_130 , L_68 ,
V_9 [ V_7 ] . V_10 , F_14 ( type ) ) ;
V_139 = - V_22 ;
goto V_58;
}
V_3 [ type ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
V_138 = strtok ( NULL , L_65 ) ;
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_18 == 0 ) {
F_7 ( L_69
L_70 , F_14 ( type ) ) ;
}
}
V_58:
free ( V_10 ) ;
return V_139 ;
}
static int F_75 ( const char * V_145 , const struct V_146 * V_147 )
{
char V_148 [ V_133 ] ;
struct V_149 V_150 ;
sprintf ( V_148 , L_71 , V_145 , V_147 -> V_151 ) ;
if ( V_149 ( V_148 , & V_150 ) )
return 0 ;
return F_76 ( V_150 . V_152 ) ;
}
static struct V_153 * F_77 ( const char * V_131 )
{
struct V_153 * V_127 = F_78 ( sizeof( * V_127 ) ) ;
if ( V_127 != NULL && V_131 )
V_127 -> V_131 = F_72 ( V_131 ) ;
return V_127 ;
}
static void F_79 ( struct V_153 * V_127 )
{
F_80 ( & V_127 -> V_131 ) ;
F_80 ( & V_127 -> V_154 ) ;
F_80 ( & V_127 -> args ) ;
free ( V_127 ) ;
}
static void F_81 ( struct V_153 * V_127 )
{
F_64 ( & V_127 -> V_128 , & V_155 ) ;
}
static struct V_153 * F_82 ( const char * V_131 )
{
struct V_153 * V_127 ;
F_66 (s, &script_descs, node)
if ( strcasecmp ( V_127 -> V_131 , V_131 ) == 0 )
return V_127 ;
return NULL ;
}
static struct V_153 * F_83 ( const char * V_131 )
{
struct V_153 * V_127 = F_82 ( V_131 ) ;
if ( V_127 )
return V_127 ;
V_127 = F_77 ( V_131 ) ;
if ( ! V_127 )
goto V_156;
F_81 ( V_127 ) ;
return V_127 ;
V_156:
F_79 ( V_127 ) ;
return NULL ;
}
static const char * F_84 ( const char * V_10 , const char * V_157 )
{
T_10 V_158 = strlen ( V_157 ) ;
const char * V_159 = V_10 ;
if ( strlen ( V_10 ) > V_158 ) {
V_159 = V_10 + strlen ( V_10 ) - V_158 ;
if ( ! strncmp ( V_159 , V_157 , V_158 ) )
return V_159 ;
}
return NULL ;
}
static int F_85 ( struct V_153 * V_160 , const char * V_161 )
{
char line [ V_162 ] , * V_159 ;
T_11 * V_163 ;
V_163 = fopen ( V_161 , L_72 ) ;
if ( ! V_163 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_163 ) ) {
V_159 = F_86 ( line ) ;
if ( strlen ( V_159 ) == 0 )
continue;
if ( * V_159 != '#' )
continue;
V_159 ++ ;
if ( strlen ( V_159 ) && * V_159 == '!' )
continue;
V_159 = F_86 ( V_159 ) ;
if ( strlen ( V_159 ) && V_159 [ strlen ( V_159 ) - 1 ] == '\n' )
V_159 [ strlen ( V_159 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_159 , L_73 , strlen ( L_73 ) ) ) {
V_159 += strlen ( L_73 ) ;
V_160 -> V_154 = F_72 ( F_86 ( V_159 ) ) ;
continue;
}
if ( ! strncmp ( V_159 , L_74 , strlen ( L_74 ) ) ) {
V_159 += strlen ( L_74 ) ;
V_160 -> args = F_72 ( F_86 ( V_159 ) ) ;
continue;
}
}
fclose ( V_163 ) ;
return 0 ;
}
static char * F_87 ( struct V_146 * V_164 , const char * V_157 )
{
char * V_165 , * V_10 ;
V_165 = F_72 ( V_164 -> V_151 ) ;
if ( ! V_165 )
return NULL ;
V_10 = ( char * ) F_84 ( V_165 , V_157 ) ;
if ( ! V_10 ) {
free ( V_165 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_165 ;
}
static int F_88 ( const struct V_132 * T_8 V_92 ,
const char * V_127 V_92 ,
int T_9 V_92 )
{
struct V_146 * V_166 , * V_167 , V_164 , V_168 ;
char V_169 [ V_170 ] ;
T_12 * V_171 , * V_172 ;
char V_173 [ V_170 ] ;
char V_174 [ V_170 ] ;
struct V_153 * V_160 ;
char V_175 [ V_162 ] ;
char * V_165 ;
snprintf ( V_169 , V_170 , L_75 , F_89 () ) ;
V_171 = F_90 ( V_169 ) ;
if ( ! V_171 )
return - 1 ;
F_91 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_174 , V_170 , L_76 , V_169 ,
V_168 . V_151 ) ;
V_172 = F_90 ( V_174 ) ;
if ( ! V_172 )
continue;
F_92 (lang_path, lang_dir, script_dirent, script_next) {
V_165 = F_87 ( & V_164 , V_176 ) ;
if ( V_165 ) {
V_160 = F_83 ( V_165 ) ;
snprintf ( V_173 , V_170 , L_71 ,
V_174 , V_164 . V_151 ) ;
F_85 ( V_160 , V_173 ) ;
free ( V_165 ) ;
}
}
}
fprintf ( stdout , L_77 ) ;
F_66 (desc, &script_descs, node) {
sprintf ( V_175 , L_78 , V_160 -> V_131 ,
V_160 -> args ? V_160 -> args : L_1 ) ;
fprintf ( stdout , L_79 , V_175 ,
V_160 -> V_154 ? V_160 -> V_154 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_93 ( char * V_177 , char * V_178 ,
struct V_19 * V_20 )
{
char V_161 [ V_170 ] , V_17 [ 128 ] ;
char line [ V_162 ] , * V_159 ;
struct V_11 * V_112 ;
int V_179 , V_135 ;
T_11 * V_163 ;
sprintf ( V_161 , L_80 , V_177 , V_178 ) ;
V_163 = fopen ( V_161 , L_72 ) ;
if ( ! V_163 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_163 ) ) {
V_159 = F_86 ( line ) ;
if ( * V_159 == '#' )
continue;
while ( strlen ( V_159 ) ) {
V_159 = strstr ( V_159 , L_81 ) ;
if ( ! V_159 )
break;
V_159 += 2 ;
V_159 = F_86 ( V_159 ) ;
V_135 = strcspn ( V_159 , L_82 ) ;
if ( ! V_135 )
break;
snprintf ( V_17 , V_135 + 1 , L_83 , V_159 ) ;
V_179 = 0 ;
F_15 (session->evlist, pos) {
if ( ! strcmp ( F_5 ( V_112 ) , V_17 ) ) {
V_179 = 1 ;
break;
}
}
if ( ! V_179 ) {
fclose ( V_163 ) ;
return - 1 ;
}
}
}
fclose ( V_163 ) ;
return 0 ;
}
int F_94 ( char * * V_180 , char * * V_181 )
{
struct V_146 * V_166 , * V_167 , V_164 , V_168 ;
char V_169 [ V_170 ] , V_174 [ V_170 ] ;
T_12 * V_171 , * V_172 ;
struct V_19 * V_20 ;
struct V_182 V_183 = {
. V_148 = V_184 ,
. V_185 = V_186 ,
} ;
char * V_187 ;
int V_7 = 0 ;
V_20 = F_95 ( & V_183 , false , NULL ) ;
if ( ! V_20 )
return - 1 ;
snprintf ( V_169 , V_170 , L_75 , F_89 () ) ;
V_171 = F_90 ( V_169 ) ;
if ( ! V_171 ) {
F_96 ( V_20 ) ;
return - 1 ;
}
F_91 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_174 , V_170 , L_71 , V_169 ,
V_168 . V_151 ) ;
#ifdef F_97
if ( strstr ( V_174 , L_84 ) )
continue;
#endif
#ifdef F_98
if ( strstr ( V_174 , L_85 ) )
continue;
#endif
V_172 = F_90 ( V_174 ) ;
if ( ! V_172 )
continue;
F_92 (lang_path, lang_dir, script_dirent, script_next) {
if ( strstr ( V_164 . V_151 , L_86 ) )
continue;
sprintf ( V_181 [ V_7 ] , L_71 , V_174 ,
V_164 . V_151 ) ;
V_187 = strchr ( V_164 . V_151 , '.' ) ;
snprintf ( V_180 [ V_7 ] ,
( V_187 - V_164 . V_151 ) + 1 ,
L_83 , V_164 . V_151 ) ;
if ( F_93 ( V_174 ,
V_180 [ V_7 ] , V_20 ) )
continue;
V_7 ++ ;
}
F_99 ( V_172 ) ;
}
F_99 ( V_171 ) ;
F_96 ( V_20 ) ;
return V_7 ;
}
static char * F_100 ( const char * V_165 , const char * V_157 )
{
struct V_146 * V_166 , * V_167 , V_164 , V_168 ;
char V_169 [ V_170 ] ;
char V_173 [ V_170 ] ;
T_12 * V_171 , * V_172 ;
char V_174 [ V_170 ] ;
char * V_188 ;
snprintf ( V_169 , V_170 , L_75 , F_89 () ) ;
V_171 = F_90 ( V_169 ) ;
if ( ! V_171 )
return NULL ;
F_91 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_174 , V_170 , L_76 , V_169 ,
V_168 . V_151 ) ;
V_172 = F_90 ( V_174 ) ;
if ( ! V_172 )
continue;
F_92 (lang_path, lang_dir, script_dirent, script_next) {
V_188 = F_87 ( & V_164 , V_157 ) ;
if ( V_188 && ! strcmp ( V_165 , V_188 ) ) {
free ( V_188 ) ;
F_99 ( V_172 ) ;
F_99 ( V_171 ) ;
snprintf ( V_173 , V_170 , L_71 ,
V_174 , V_164 . V_151 ) ;
return F_72 ( V_173 ) ;
}
free ( V_188 ) ;
}
F_99 ( V_172 ) ;
}
F_99 ( V_171 ) ;
return NULL ;
}
static bool F_101 ( const char * V_173 )
{
return F_84 ( V_173 , L_87 ) == NULL ? false : true ;
}
static int F_102 ( char * V_173 )
{
struct V_153 * V_160 ;
int V_189 = 0 ;
char * V_159 ;
V_160 = F_77 ( NULL ) ;
if ( F_85 ( V_160 , V_173 ) )
goto V_58;
if ( ! V_160 -> args )
goto V_58;
for ( V_159 = V_160 -> args ; * V_159 ; V_159 ++ )
if ( * V_159 == '<' )
V_189 ++ ;
V_58:
F_79 ( V_160 ) ;
return V_189 ;
}
static int F_103 ( int T_3 , const char * * T_4 )
{
char * * V_190 = malloc ( sizeof( const char * ) * T_3 ) ;
if ( ! V_190 ) {
F_6 ( L_88 ) ;
return - 1 ;
}
memcpy ( V_190 , T_4 , sizeof( const char * ) * T_3 ) ;
T_3 = F_104 ( T_3 , ( const char * * ) V_190 , V_191 ,
NULL , V_192 ) ;
free ( V_190 ) ;
V_193 = ( T_3 == 0 ) ;
return 0 ;
}
int F_105 ( int T_3 , const char * * T_4 , const char * T_13 V_92 )
{
bool V_194 = false ;
bool V_100 = false ;
bool V_195 = false ;
bool V_196 = false ;
char * V_197 = NULL ;
char * V_198 = NULL ;
struct V_19 * V_20 ;
char * V_173 = NULL ;
const char * * V_190 ;
int V_7 , V_1 , V_113 = 0 ;
struct V_109 T_2 = {
. T_6 = {
. V_62 = F_39 ,
. V_118 = F_56 ,
. V_119 = F_58 ,
. V_115 = F_49 ,
. exit = F_54 ,
. V_117 = F_52 ,
. V_16 = F_43 ,
. V_199 = V_200 ,
. V_201 = V_202 ,
. V_203 = true ,
. V_204 = true ,
} ,
} ;
const struct V_132 V_205 [] = {
F_106 ( 'D' , L_89 , & V_206 ,
L_90 ) ,
F_107 ( 'v' , L_91 , & V_207 ,
L_92 ) ,
F_106 ( 'L' , L_93 , & V_68 ,
L_94 ) ,
F_108 ( 'l' , L_95 , NULL , NULL , L_96 ,
F_88 ) ,
F_109 ( 's' , L_97 , NULL , L_98 ,
L_99 ,
F_71 ) ,
F_110 ( 'g' , L_100 , & V_208 , L_54 ,
L_101 ) ,
F_110 ( 'i' , L_102 , & V_184 , L_103 , L_104 ) ,
F_106 ( 'd' , L_105 , & V_101 ,
L_106 ) ,
F_106 ( 0 , L_107 , & V_100 , L_108 ) ,
F_106 ( 0 , L_109 , & V_195 , L_110 ) ,
F_110 ( 'k' , L_111 , & V_56 . V_209 ,
L_103 , L_112 ) ,
F_110 ( 0 , L_113 , & V_56 . V_210 ,
L_103 , L_114 ) ,
F_106 ( 'G' , L_115 , & V_53 ,
L_116 ) ,
F_110 ( 0 , L_117 , & V_56 . V_211 , L_118 ,
L_119 ) ,
F_109 ( 'f' , L_120 , NULL , L_121 ,
L_122
L_123
L_124
L_125 , F_73 ) ,
F_106 ( 'a' , L_126 , & V_193 ,
L_127 ) ,
F_110 ( 'S' , L_128 , & V_56 . V_212 , L_129 ,
L_130 ) ,
F_110 ( 'C' , L_131 , & V_105 , L_131 , L_132 ) ,
F_110 ( 'c' , L_133 , & V_56 . V_213 , L_134 ,
L_135 ) ,
F_106 ( 'I' , L_136 , & V_194 ,
L_137 ) ,
F_106 ( '\0' , L_138 , & V_56 . V_214 ,
L_139 ) ,
F_106 ( '\0' , L_140 , & T_2 . V_122 ,
L_141 ) ,
F_106 ( '\0' , L_142 , & T_2 . V_123 ,
L_143 ) ,
F_111 ()
} ;
const char * const V_215 [] = {
L_144 ,
L_145 ,
L_146 ,
L_147 ,
L_148 ,
NULL
} ;
struct V_182 V_183 = {
. V_185 = V_186 ,
} ;
F_34 () ;
T_3 = F_104 ( T_3 , T_4 , V_205 , V_215 ,
V_192 ) ;
V_183 . V_148 = V_184 ;
if ( T_3 > 1 && ! strncmp ( T_4 [ 0 ] , L_149 , strlen ( L_149 ) ) ) {
V_197 = F_100 ( T_4 [ 1 ] , V_216 ) ;
if ( ! V_197 )
return F_112 ( T_3 , T_4 , NULL ) ;
}
if ( T_3 > 1 && ! strncmp ( T_4 [ 0 ] , L_150 , strlen ( L_150 ) ) ) {
V_198 = F_100 ( T_4 [ 1 ] , V_176 ) ;
if ( ! V_198 ) {
fprintf ( V_130 ,
L_151
L_152 ) ;
return - 1 ;
}
}
F_113 ( F_89 () ) ;
if ( T_3 && ! V_136 && ! V_197 && ! V_198 ) {
int V_217 [ 2 ] ;
int V_218 ;
T_14 V_69 ;
V_197 = F_100 ( T_4 [ 0 ] , V_216 ) ;
V_198 = F_100 ( T_4 [ 0 ] , V_176 ) ;
if ( ! V_197 && ! V_198 ) {
fprintf ( V_130 , L_153
L_154 , T_4 [ 0 ] ) ;
F_114 ( V_215 , V_205 ) ;
}
if ( F_101 ( T_4 [ 0 ] ) ) {
V_218 = T_3 - 1 ;
} else {
int V_219 ;
V_218 = F_102 ( V_198 ) ;
V_219 = ( T_3 - 1 ) - V_218 ;
if ( V_219 < 0 ) {
fprintf ( V_130 , L_155
L_156
L_157 , T_4 [ 0 ] ) ;
F_114 ( V_215 , V_205 ) ;
}
}
if ( F_115 ( V_217 ) < 0 ) {
perror ( L_158 ) ;
return - 1 ;
}
V_69 = V_117 () ;
if ( V_69 < 0 ) {
perror ( L_159 ) ;
return - 1 ;
}
if ( ! V_69 ) {
V_1 = 0 ;
F_116 ( V_217 [ 1 ] , 1 ) ;
F_117 ( V_217 [ 0 ] ) ;
if ( F_101 ( T_4 [ 0 ] ) ) {
V_193 = true ;
} else if ( ! V_193 ) {
if ( F_103 ( T_3 - V_218 , & T_4 [ V_218 ] ) != 0 ) {
V_113 = - 1 ;
goto V_58;
}
}
V_190 = malloc ( ( T_3 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_190 ) {
F_6 ( L_88 ) ;
V_113 = - V_140 ;
goto V_58;
}
V_190 [ V_1 ++ ] = L_160 ;
V_190 [ V_1 ++ ] = V_197 ;
if ( V_193 )
V_190 [ V_1 ++ ] = L_161 ;
V_190 [ V_1 ++ ] = L_162 ;
V_190 [ V_1 ++ ] = L_163 ;
V_190 [ V_1 ++ ] = L_164 ;
for ( V_7 = V_218 + 1 ; V_7 < T_3 ; V_7 ++ )
V_190 [ V_1 ++ ] = T_4 [ V_7 ] ;
V_190 [ V_1 ++ ] = NULL ;
F_118 ( L_160 , ( char * * ) V_190 ) ;
free ( V_190 ) ;
exit ( - 1 ) ;
}
F_116 ( V_217 [ 0 ] , 0 ) ;
F_117 ( V_217 [ 1 ] ) ;
V_190 = malloc ( ( T_3 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_190 ) {
F_6 ( L_88 ) ;
V_113 = - V_140 ;
goto V_58;
}
V_1 = 0 ;
V_190 [ V_1 ++ ] = L_160 ;
V_190 [ V_1 ++ ] = V_198 ;
for ( V_7 = 1 ; V_7 < V_218 + 1 ; V_7 ++ )
V_190 [ V_1 ++ ] = T_4 [ V_7 ] ;
V_190 [ V_1 ++ ] = L_165 ;
V_190 [ V_1 ++ ] = L_164 ;
V_190 [ V_1 ++ ] = NULL ;
F_118 ( L_160 , ( char * * ) V_190 ) ;
free ( V_190 ) ;
exit ( - 1 ) ;
}
if ( V_197 )
V_173 = V_197 ;
if ( V_198 )
V_173 = V_198 ;
if ( V_173 ) {
V_1 = 0 ;
if ( ! V_197 )
V_193 = false ;
else if ( ! V_193 ) {
if ( F_103 ( T_3 - 1 , & T_4 [ 1 ] ) != 0 ) {
V_113 = - 1 ;
goto V_58;
}
}
V_190 = malloc ( ( T_3 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_190 ) {
F_6 ( L_88 ) ;
V_113 = - V_140 ;
goto V_58;
}
V_190 [ V_1 ++ ] = L_160 ;
V_190 [ V_1 ++ ] = V_173 ;
if ( V_193 )
V_190 [ V_1 ++ ] = L_161 ;
for ( V_7 = 2 ; V_7 < T_3 ; V_7 ++ )
V_190 [ V_1 ++ ] = T_4 [ V_7 ] ;
V_190 [ V_1 ++ ] = NULL ;
F_118 ( L_160 , ( char * * ) V_190 ) ;
free ( V_190 ) ;
exit ( - 1 ) ;
}
if ( ! V_136 )
F_119 () ;
V_20 = F_95 ( & V_183 , false , & T_2 . T_6 ) ;
if ( V_20 == NULL )
return - 1 ;
if ( V_100 || V_195 ) {
F_120 ( V_20 , stdout , V_194 ) ;
if ( V_195 )
goto V_220;
}
if ( F_121 ( & V_20 -> V_100 . V_221 ) < 0 )
goto V_220;
T_2 . V_20 = V_20 ;
if ( V_105 ) {
V_113 = F_122 ( V_20 , V_105 , V_106 ) ;
if ( V_113 < 0 )
goto V_220;
}
if ( ! V_53 )
V_56 . V_54 = true ;
else
V_56 . V_54 = false ;
if ( V_208 ) {
struct V_149 V_222 ;
int V_223 ;
if ( F_1 () ) {
fprintf ( V_130 ,
L_166 ) ;
V_113 = - V_22 ;
goto V_220;
}
V_223 = F_123 ( V_183 . V_148 , V_224 ) ;
if ( V_223 < 0 ) {
V_113 = - V_225 ;
perror ( L_167 ) ;
goto V_220;
}
V_113 = F_124 ( V_223 , & V_222 ) ;
if ( V_113 < 0 ) {
perror ( L_168 ) ;
goto V_220;
}
if ( ! V_222 . V_226 ) {
fprintf ( V_130 , L_169 ) ;
goto V_220;
}
V_94 = F_69 ( V_208 ) ;
if ( ! V_94 ) {
fprintf ( V_130 , L_55 ) ;
V_113 = - V_227 ;
goto V_220;
}
V_113 = V_94 -> V_228 ( V_20 -> V_229 . V_93 ,
L_170 ) ;
goto V_220;
}
if ( V_136 ) {
V_113 = V_94 -> V_230 ( V_136 , T_3 , T_4 ) ;
if ( V_113 )
goto V_220;
F_7 ( L_171 , V_136 ) ;
V_196 = true ;
}
V_113 = F_12 ( V_20 ) ;
if ( V_113 < 0 )
goto V_220;
V_113 = F_60 ( & T_2 ) ;
F_37 () ;
V_220:
F_96 ( V_20 ) ;
if ( V_196 )
F_38 () ;
V_58:
return V_113 ;
}
