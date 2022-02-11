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
enum V_5 V_6 ,
bool V_15 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
int type = V_17 -> type ;
const char * V_18 ;
if ( V_17 -> V_13 & V_13 )
return 0 ;
if ( V_3 [ type ] . V_4 ) {
if ( V_15 )
return 0 ;
V_18 = F_5 ( V_12 ) ;
F_6 ( L_2
L_3 ,
V_18 , V_14 , F_2 ( V_6 ) ) ;
return - 1 ;
}
V_3 [ type ] . V_19 &= ~ V_6 ;
V_18 = F_5 ( V_12 ) ;
F_7 ( L_2
L_4 ,
V_18 , V_14 , F_2 ( V_6 ) ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 ,
T_1 V_13 , const char * V_14 ,
enum V_5 V_6 )
{
return F_4 ( V_12 , V_13 , V_14 , V_6 ,
false ) ;
}
static int F_9 ( struct V_11 * V_12 ,
struct V_20 * V_21 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
bool V_15 ;
V_15 = F_10 ( & V_21 -> V_22 ,
V_23 ) ;
if ( F_11 ( V_24 ) &&
! F_12 ( V_21 , L_5 ) )
return - V_25 ;
if ( F_11 ( V_26 ) ) {
if ( F_8 ( V_12 , V_27 , L_6 ,
V_28 ) )
return - V_25 ;
}
if ( F_11 ( V_29 ) &&
F_4 ( V_12 , V_30 , L_7 ,
V_31 , V_15 ) )
return - V_25 ;
if ( F_11 ( V_32 ) && ! F_11 ( V_26 ) && ! F_11 ( V_29 ) ) {
F_6 ( L_8
L_9
L_10 ) ;
return - V_25 ;
}
if ( F_11 ( V_33 ) && ! F_11 ( V_32 ) ) {
F_6 ( L_11
L_12 ) ;
return - V_25 ;
}
if ( F_11 ( V_34 ) && ! F_11 ( V_26 ) && ! F_11 ( V_29 ) ) {
F_6 ( L_13
L_9
L_14 ) ;
return - V_25 ;
}
if ( F_11 ( V_35 ) && ! F_11 ( V_26 ) ) {
F_6 ( L_15
L_16 ) ;
return - V_25 ;
}
if ( ( F_11 ( V_36 ) || F_11 ( V_37 ) ) &&
F_8 ( V_12 , V_38 , L_17 ,
V_39 | V_40 ) )
return - V_25 ;
if ( F_11 ( TIME ) &&
F_8 ( V_12 , V_41 , L_18 ,
V_42 ) )
return - V_25 ;
if ( F_11 ( V_43 ) &&
F_4 ( V_12 , V_44 , L_19 ,
V_45 , V_15 ) )
return - V_25 ;
if ( F_11 ( V_46 ) &&
F_8 ( V_12 , V_47 , L_20 ,
V_48 ) )
return - V_25 ;
return 0 ;
}
static void F_13 ( struct V_16 * V_17 )
{
unsigned int type = V_17 -> type ;
V_3 [ type ] . V_49 = 0 ;
if ( F_11 ( V_26 ) )
V_3 [ type ] . V_49 |= V_50 ;
if ( F_11 ( V_32 ) )
V_3 [ type ] . V_49 |= V_51 ;
if ( F_11 ( V_34 ) )
V_3 [ type ] . V_49 |= V_52 ;
if ( F_11 ( V_33 ) )
V_3 [ type ] . V_49 |= V_53 ;
if ( F_11 ( V_35 ) )
V_3 [ type ] . V_49 |= V_54 ;
}
static int F_14 ( struct V_20 * V_21 )
{
int V_1 ;
struct V_11 * V_12 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_12 = F_15 ( V_21 , V_1 ) ;
if ( ! V_12 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_55 ) {
F_6 ( L_21
L_22 ,
F_16 ( V_1 ) ) ;
return - 1 ;
}
if ( V_12 && V_3 [ V_1 ] . V_19 &&
F_9 ( V_12 , V_21 ) )
return - 1 ;
if ( V_12 == NULL )
continue;
F_13 ( & V_12 -> V_17 ) ;
}
if ( ! V_56 ) {
bool V_57 = false ;
F_17 (session->evlist, evsel) {
if ( V_12 -> V_17 . V_13 & V_58 ) {
V_57 = true ;
break;
}
}
if ( ! V_57 )
V_59 . V_57 = false ;
}
if ( V_59 . V_57 &&
! V_3 [ V_60 ] . V_4 ) {
struct V_16 * V_17 ;
V_1 = V_60 ;
V_12 = F_15 ( V_21 , V_1 ) ;
if ( V_12 == NULL )
goto V_61;
V_17 = & V_12 -> V_17 ;
if ( V_17 -> V_13 & V_58 ) {
V_3 [ V_1 ] . V_19 |= V_28 ;
V_3 [ V_1 ] . V_19 |= V_62 ;
V_3 [ V_1 ] . V_19 |= V_63 ;
F_13 ( V_17 ) ;
}
}
V_61:
return 0 ;
}
static void F_18 ( struct V_64 * V_65 ,
struct V_66 * V_66 ,
struct V_11 * V_12 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
unsigned long V_67 ;
unsigned long V_68 ;
unsigned long long V_69 ;
if ( F_11 ( V_70 ) ) {
if ( V_71 )
printf ( L_23 , F_19 ( V_66 ) ) ;
else if ( F_11 ( V_26 ) && V_59 . V_57 )
printf ( L_24 , F_19 ( V_66 ) ) ;
else
printf ( L_25 , F_19 ( V_66 ) ) ;
}
if ( F_11 ( V_36 ) && F_11 ( V_37 ) )
printf ( L_26 , V_65 -> V_72 , V_65 -> V_73 ) ;
else if ( F_11 ( V_36 ) )
printf ( L_27 , V_65 -> V_72 ) ;
else if ( F_11 ( V_37 ) )
printf ( L_27 , V_65 -> V_73 ) ;
if ( F_11 ( V_43 ) ) {
if ( V_71 )
printf ( L_28 , V_65 -> V_74 ) ;
else
printf ( L_29 , V_65 -> V_74 ) ;
}
if ( F_11 ( TIME ) ) {
V_69 = V_65 -> time ;
V_67 = V_69 / V_75 ;
V_69 -= V_67 * V_75 ;
V_68 = V_69 / V_76 ;
printf ( L_30 , V_67 , V_68 ) ;
}
}
static void F_20 ( union V_77 * V_78 ,
struct V_64 * V_65 ,
struct V_66 * V_66 ,
struct V_16 * V_17 )
{
struct V_79 V_80 ;
printf ( L_31 V_81 , V_65 -> V_82 ) ;
if ( ! F_21 ( V_17 ) )
return;
F_22 ( V_78 , V_65 , V_66 , & V_80 ) ;
if ( F_11 ( V_32 ) ) {
printf ( L_32 ) ;
if ( F_11 ( V_33 ) )
F_23 ( V_80 . V_83 , & V_80 , stdout ) ;
else
F_24 ( V_80 . V_83 , stdout ) ;
}
if ( F_11 ( V_34 ) ) {
printf ( L_33 ) ;
F_25 ( V_80 . V_84 , stdout ) ;
printf ( L_34 ) ;
}
}
static void F_26 ( union V_77 * V_78 ,
struct V_64 * V_65 ,
struct V_11 * V_12 ,
struct V_66 * V_66 ,
struct V_79 * V_80 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
bool V_85 = false ;
if ( F_11 ( V_26 ) ) {
unsigned int V_86 = V_3 [ V_17 -> type ] . V_49 ;
if ( V_59 . V_57 && V_65 -> V_87 ) {
printf ( L_35 ) ;
} else {
printf ( L_32 ) ;
if ( V_86 & V_54 ) {
V_85 = true ;
V_86 &= ~ V_54 ;
}
}
F_27 ( V_12 , V_65 , V_80 , V_86 ,
V_88 ) ;
}
if ( F_11 ( V_29 ) ||
( ( V_12 -> V_17 . V_13 & V_30 ) &&
! V_3 [ V_17 -> type ] . V_4 ) ) {
printf ( L_36 ) ;
F_20 ( V_78 , V_65 , V_66 , V_17 ) ;
}
if ( V_85 )
F_28 ( V_80 -> V_84 , V_80 -> V_82 , L_37 , stdout ) ;
printf ( L_35 ) ;
}
static void F_29 ( T_2 V_89 )
{
const char * V_90 = V_91 ;
const int V_92 = strlen ( V_91 ) ;
char V_10 [ 33 ] ;
int V_7 , V_93 = 0 ;
for ( V_7 = 0 ; V_7 < V_92 ; V_7 ++ , V_89 >>= 1 ) {
if ( V_89 & 1 )
V_10 [ V_93 ++ ] = V_90 [ V_7 ] ;
}
for (; V_7 < 32 ; V_7 ++ , V_89 >>= 1 ) {
if ( V_89 & 1 )
V_10 [ V_93 ++ ] = '?' ;
}
V_10 [ V_93 ] = 0 ;
printf ( L_38 , V_10 ) ;
}
static void F_30 ( union V_77 * V_78 , struct V_64 * V_65 ,
struct V_11 * V_12 , struct V_79 * V_80 )
{
struct V_66 * V_66 = V_80 -> V_66 ;
struct V_16 * V_17 = & V_12 -> V_17 ;
if ( V_3 [ V_17 -> type ] . V_19 == 0 )
return;
F_18 ( V_65 , V_66 , V_12 ) ;
if ( F_11 ( V_46 ) )
printf ( L_39 V_94 L_32 , V_65 -> V_95 ) ;
if ( F_11 ( V_96 ) ) {
const char * V_18 = F_5 ( V_12 ) ;
printf ( L_40 , V_18 ? V_18 : L_41 ) ;
}
if ( V_97 )
F_29 ( V_65 -> V_89 ) ;
if ( F_31 ( V_17 ) ) {
F_26 ( V_78 , V_65 , V_12 , V_66 , V_80 ) ;
return;
}
if ( F_11 ( V_24 ) )
F_32 ( V_12 -> V_98 , V_65 -> V_74 ,
V_65 -> V_99 , V_65 -> V_100 ) ;
if ( F_11 ( V_29 ) )
F_20 ( V_78 , V_65 , V_66 , V_17 ) ;
if ( F_11 ( V_26 ) ) {
if ( ! V_59 . V_57 )
printf ( L_32 ) ;
else
printf ( L_35 ) ;
F_27 ( V_12 , V_65 , V_80 ,
V_3 [ V_17 -> type ] . V_49 ,
V_88 ) ;
}
printf ( L_35 ) ;
}
static int F_33 ( const char * T_3 V_101 ,
int T_4 V_101 ,
const char * * T_5 V_101 )
{
return 0 ;
}
static int F_34 ( void )
{
return 0 ;
}
static int F_35 ( void )
{
return 0 ;
}
static int F_36 ( struct V_102 * V_102 V_101 ,
const char * T_6 V_101 )
{
return 0 ;
}
static void F_37 ( void )
{
F_38 () ;
F_39 () ;
V_103 = & V_104 ;
}
static int F_40 ( void )
{
return V_103 -> V_105 () ;
}
static int F_41 ( void )
{
F_7 ( L_42 ) ;
return V_103 -> V_106 () ;
}
static int F_42 ( struct V_107 * T_7 V_101 ,
union V_77 * V_78 ,
struct V_64 * V_65 ,
struct V_11 * V_12 ,
struct V_108 * V_108 )
{
struct V_79 V_80 ;
if ( V_109 ) {
if ( V_65 -> time < V_110 ) {
F_6 ( L_43 V_94
L_44 V_94 L_35 , V_110 ,
V_65 -> time ) ;
V_111 ++ ;
}
V_110 = V_65 -> time ;
return 0 ;
}
if ( F_43 ( V_78 , V_108 , & V_80 , V_65 ) < 0 ) {
F_6 ( L_45 ,
V_78 -> V_22 . type ) ;
return - 1 ;
}
if ( V_80 . V_112 )
goto V_113;
if ( V_114 && ! F_44 ( V_65 -> V_74 , V_115 ) )
goto V_113;
V_103 -> F_30 ( V_78 , V_65 , V_12 , & V_80 ) ;
V_113:
F_45 ( & V_80 ) ;
return 0 ;
}
static int F_46 ( struct V_107 * T_7 , union V_77 * V_78 ,
struct V_116 * * V_117 )
{
struct V_118 * V_119 = F_47 ( T_7 , struct V_118 , T_7 ) ;
struct V_116 * V_120 ;
struct V_11 * V_12 , * V_93 ;
int V_121 ;
V_121 = F_48 ( T_7 , V_78 , V_117 ) ;
if ( V_121 )
return V_121 ;
V_120 = * V_117 ;
V_12 = F_49 ( * V_117 ) ;
if ( V_12 -> V_17 . type >= V_2 )
return 0 ;
F_17 (evlist, pos) {
if ( V_93 -> V_17 . type == V_12 -> V_17 . type && V_93 != V_12 )
return 0 ;
}
F_13 ( & V_12 -> V_17 ) ;
return F_9 ( V_12 , V_119 -> V_21 ) ;
}
static int F_50 ( struct V_107 * T_7 ,
union V_77 * V_78 ,
struct V_64 * V_65 ,
struct V_108 * V_108 )
{
struct V_66 * V_66 ;
struct V_118 * T_3 = F_47 ( T_7 , struct V_118 , T_7 ) ;
struct V_20 * V_21 = T_3 -> V_21 ;
struct V_11 * V_12 = F_51 ( V_21 -> V_120 ) ;
int V_122 = - 1 ;
V_66 = F_52 ( V_108 , V_78 -> V_123 . V_72 , V_78 -> V_123 . V_73 ) ;
if ( V_66 == NULL ) {
F_7 ( L_46 ) ;
return - 1 ;
}
if ( F_53 ( T_7 , V_78 , V_65 , V_108 ) < 0 )
goto V_61;
if ( ! V_12 -> V_17 . V_124 ) {
V_65 -> V_74 = 0 ;
V_65 -> time = 0 ;
V_65 -> V_73 = V_78 -> V_123 . V_73 ;
V_65 -> V_72 = V_78 -> V_123 . V_72 ;
}
F_18 ( V_65 , V_66 , V_12 ) ;
F_54 ( V_78 , stdout ) ;
V_122 = 0 ;
V_61:
F_55 ( V_66 ) ;
return V_122 ;
}
static int F_56 ( struct V_107 * T_7 ,
union V_77 * V_78 ,
struct V_64 * V_65 ,
struct V_108 * V_108 )
{
struct V_66 * V_66 ;
struct V_118 * T_3 = F_47 ( T_7 , struct V_118 , T_7 ) ;
struct V_20 * V_21 = T_3 -> V_21 ;
struct V_11 * V_12 = F_51 ( V_21 -> V_120 ) ;
if ( F_57 ( T_7 , V_78 , V_65 , V_108 ) < 0 )
return - 1 ;
V_66 = F_52 ( V_108 , V_78 -> V_125 . V_72 , V_78 -> V_125 . V_73 ) ;
if ( V_66 == NULL ) {
F_7 ( L_47 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_124 ) {
V_65 -> V_74 = 0 ;
V_65 -> time = V_78 -> V_125 . time ;
V_65 -> V_73 = V_78 -> V_125 . V_73 ;
V_65 -> V_72 = V_78 -> V_125 . V_72 ;
}
F_18 ( V_65 , V_66 , V_12 ) ;
F_54 ( V_78 , stdout ) ;
F_55 ( V_66 ) ;
return 0 ;
}
static int F_58 ( struct V_107 * T_7 ,
union V_77 * V_78 ,
struct V_64 * V_65 ,
struct V_108 * V_108 )
{
int V_121 = 0 ;
struct V_66 * V_66 ;
struct V_118 * T_3 = F_47 ( T_7 , struct V_118 , T_7 ) ;
struct V_20 * V_21 = T_3 -> V_21 ;
struct V_11 * V_12 = F_51 ( V_21 -> V_120 ) ;
V_66 = F_52 ( V_108 , V_78 -> V_125 . V_72 , V_78 -> V_125 . V_73 ) ;
if ( V_66 == NULL ) {
F_7 ( L_48 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_124 ) {
V_65 -> V_74 = 0 ;
V_65 -> time = 0 ;
V_65 -> V_73 = V_78 -> V_123 . V_73 ;
V_65 -> V_72 = V_78 -> V_123 . V_72 ;
}
F_18 ( V_65 , V_66 , V_12 ) ;
F_54 ( V_78 , stdout ) ;
if ( F_59 ( T_7 , V_78 , V_65 , V_108 ) < 0 )
V_121 = - 1 ;
F_55 ( V_66 ) ;
return V_121 ;
}
static int F_60 ( struct V_107 * T_7 ,
union V_77 * V_78 ,
struct V_64 * V_65 ,
struct V_108 * V_108 )
{
struct V_66 * V_66 ;
struct V_118 * T_3 = F_47 ( T_7 , struct V_118 , T_7 ) ;
struct V_20 * V_21 = T_3 -> V_21 ;
struct V_11 * V_12 = F_51 ( V_21 -> V_120 ) ;
if ( F_61 ( T_7 , V_78 , V_65 , V_108 ) < 0 )
return - 1 ;
V_66 = F_52 ( V_108 , V_78 -> V_126 . V_72 , V_78 -> V_126 . V_73 ) ;
if ( V_66 == NULL ) {
F_7 ( L_49 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_124 ) {
V_65 -> V_74 = 0 ;
V_65 -> time = 0 ;
V_65 -> V_73 = V_78 -> V_126 . V_73 ;
V_65 -> V_72 = V_78 -> V_126 . V_72 ;
}
F_18 ( V_65 , V_66 , V_12 ) ;
F_54 ( V_78 , stdout ) ;
F_55 ( V_66 ) ;
return 0 ;
}
static int F_62 ( struct V_107 * T_7 ,
union V_77 * V_78 ,
struct V_64 * V_65 ,
struct V_108 * V_108 )
{
struct V_66 * V_66 ;
struct V_118 * T_3 = F_47 ( T_7 , struct V_118 , T_7 ) ;
struct V_20 * V_21 = T_3 -> V_21 ;
struct V_11 * V_12 = F_51 ( V_21 -> V_120 ) ;
if ( F_63 ( T_7 , V_78 , V_65 , V_108 ) < 0 )
return - 1 ;
V_66 = F_52 ( V_108 , V_78 -> V_127 . V_72 , V_78 -> V_127 . V_73 ) ;
if ( V_66 == NULL ) {
F_7 ( L_50 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_124 ) {
V_65 -> V_74 = 0 ;
V_65 -> time = 0 ;
V_65 -> V_73 = V_78 -> V_127 . V_73 ;
V_65 -> V_72 = V_78 -> V_127 . V_72 ;
}
F_18 ( V_65 , V_66 , V_12 ) ;
F_54 ( V_78 , stdout ) ;
F_55 ( V_66 ) ;
return 0 ;
}
static void F_64 ( int T_8 V_101 )
{
V_128 = 1 ;
}
static int F_65 ( struct V_118 * T_3 )
{
int V_122 ;
signal ( V_129 , F_64 ) ;
if ( T_3 -> V_130 ) {
T_3 -> T_7 . V_123 = F_50 ;
T_3 -> T_7 . V_125 = F_56 ;
T_3 -> T_7 . exit = F_58 ;
}
if ( T_3 -> V_131 ) {
T_3 -> T_7 . V_126 = F_60 ;
T_3 -> T_7 . V_127 = F_62 ;
}
V_122 = F_66 ( T_3 -> V_21 ) ;
if ( V_109 )
F_6 ( L_51 V_94 L_35 , V_111 ) ;
return V_122 ;
}
static struct V_132 * F_67 ( const char * V_133 ,
struct V_103 * V_134 )
{
struct V_132 * V_135 = malloc ( sizeof( * V_135 ) + strlen ( V_133 ) + 1 ) ;
if ( V_135 != NULL ) {
strcpy ( V_135 -> V_133 , V_133 ) ;
V_135 -> V_134 = V_134 ;
}
return V_135 ;
}
static void F_68 ( struct V_132 * V_135 )
{
F_69 ( & V_135 -> V_136 , & V_137 ) ;
}
static struct V_132 * F_70 ( const char * V_133 )
{
struct V_132 * V_135 ;
F_71 (s, &script_specs, node)
if ( strcasecmp ( V_135 -> V_133 , V_133 ) == 0 )
return V_135 ;
return NULL ;
}
static struct V_132 * F_72 ( const char * V_133 ,
struct V_103 * V_134 )
{
struct V_132 * V_135 = F_70 ( V_133 ) ;
if ( V_135 )
return V_135 ;
V_135 = F_67 ( V_133 , V_134 ) ;
if ( ! V_135 )
return NULL ;
F_68 ( V_135 ) ;
return V_135 ;
}
int F_73 ( const char * V_133 , struct V_103 * V_134 )
{
struct V_132 * V_135 ;
V_135 = F_70 ( V_133 ) ;
if ( V_135 )
return - 1 ;
V_135 = F_72 ( V_133 , V_134 ) ;
if ( ! V_135 )
return - 1 ;
return 0 ;
}
static struct V_103 * F_74 ( const char * V_133 )
{
struct V_132 * V_135 = F_70 ( V_133 ) ;
if ( ! V_135 )
return NULL ;
return V_135 -> V_134 ;
}
static void F_75 ( void )
{
struct V_132 * V_135 ;
fprintf ( V_138 , L_35 ) ;
fprintf ( V_138 , L_52
L_53 ) ;
F_71 (s, &script_specs, node)
fprintf ( V_138 , L_54 , V_135 -> V_133 , V_135 -> V_134 -> V_139 ) ;
fprintf ( V_138 , L_35 ) ;
}
static int F_76 ( const struct V_140 * T_9 V_101 ,
const char * V_10 , int T_10 V_101 )
{
char V_133 [ V_141 ] ;
const char * T_3 , * V_142 ;
int V_143 ;
if ( strcmp ( V_10 , L_55 ) == 0 ) {
F_75 () ;
exit ( 0 ) ;
}
T_3 = strchr ( V_10 , ':' ) ;
if ( T_3 ) {
V_143 = T_3 - V_10 ;
if ( V_143 >= V_141 ) {
fprintf ( V_138 , L_56 ) ;
return - 1 ;
}
strncpy ( V_133 , V_10 , V_143 ) ;
V_133 [ V_143 ] = '\0' ;
V_103 = F_74 ( V_133 ) ;
if ( ! V_103 ) {
fprintf ( V_138 , L_56 ) ;
return - 1 ;
}
T_3 ++ ;
} else {
T_3 = V_10 ;
V_142 = strrchr ( T_3 , '.' ) ;
if ( ! V_142 ) {
fprintf ( V_138 , L_57 ) ;
return - 1 ;
}
V_103 = F_74 ( ++ V_142 ) ;
if ( ! V_103 ) {
fprintf ( V_138 , L_57 ) ;
return - 1 ;
}
}
V_144 = F_77 ( T_3 ) ;
return 0 ;
}
static int F_78 ( const struct V_140 * T_9 V_101 ,
const char * V_145 , int T_10 V_101 )
{
char * V_146 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_147 = 0 ;
char * V_10 = F_77 ( V_145 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_148 ;
V_146 = strchr ( V_10 , ':' ) ;
if ( V_146 ) {
* V_146 = '\0' ;
V_146 ++ ;
if ( ! strcmp ( V_10 , L_58 ) )
type = V_149 ;
else if ( ! strcmp ( V_10 , L_59 ) )
type = V_150 ;
else if ( ! strcmp ( V_10 , L_60 ) )
type = V_60 ;
else if ( ! strcmp ( V_10 , L_61 ) )
type = V_151 ;
else {
fprintf ( V_138 , L_62 ) ;
V_147 = - V_25 ;
goto V_61;
}
if ( V_3 [ type ] . V_4 )
F_79 ( L_63 ,
F_16 ( type ) ) ;
V_3 [ type ] . V_19 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_55 = false ;
} else {
V_146 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_138 ,
L_64 ) ;
V_147 = - V_25 ;
goto V_61;
}
if ( F_1 () )
F_79 ( L_65 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_19 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_55 = true ;
}
}
for ( V_146 = strtok ( V_146 , L_66 ) ; V_146 ; V_146 = strtok ( NULL , L_66 ) ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_146 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 && strcmp ( V_146 , L_67 ) == 0 ) {
V_97 = true ;
continue;
}
if ( V_7 == V_8 ) {
fprintf ( V_138 , L_68 ) ;
V_147 = - V_25 ;
goto V_61;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_152 & V_9 [ V_7 ] . V_6 ) {
F_79 ( L_69 ,
V_9 [ V_7 ] . V_10 , F_16 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_152 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_138 , L_70 ,
V_9 [ V_7 ] . V_10 , F_16 ( type ) ) ;
V_147 = - V_25 ;
goto V_61;
}
V_3 [ type ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_19 == 0 ) {
F_7 ( L_71
L_72 , F_16 ( type ) ) ;
}
}
V_61:
free ( V_10 ) ;
return V_147 ;
}
static int F_80 ( const char * V_153 , const struct V_154 * V_155 )
{
char V_156 [ V_141 ] ;
struct V_157 V_158 ;
sprintf ( V_156 , L_73 , V_153 , V_155 -> V_159 ) ;
if ( V_157 ( V_156 , & V_158 ) )
return 0 ;
return F_81 ( V_158 . V_160 ) ;
}
static struct V_161 * F_82 ( const char * V_139 )
{
struct V_161 * V_135 = F_83 ( sizeof( * V_135 ) ) ;
if ( V_135 != NULL && V_139 )
V_135 -> V_139 = F_77 ( V_139 ) ;
return V_135 ;
}
static void F_84 ( struct V_161 * V_135 )
{
F_85 ( & V_135 -> V_139 ) ;
F_85 ( & V_135 -> V_162 ) ;
F_85 ( & V_135 -> args ) ;
free ( V_135 ) ;
}
static void F_86 ( struct V_161 * V_135 )
{
F_69 ( & V_135 -> V_136 , & V_163 ) ;
}
static struct V_161 * F_87 ( const char * V_139 )
{
struct V_161 * V_135 ;
F_71 (s, &script_descs, node)
if ( strcasecmp ( V_135 -> V_139 , V_139 ) == 0 )
return V_135 ;
return NULL ;
}
static struct V_161 * F_88 ( const char * V_139 )
{
struct V_161 * V_135 = F_87 ( V_139 ) ;
if ( V_135 )
return V_135 ;
V_135 = F_82 ( V_139 ) ;
if ( ! V_135 )
goto V_164;
F_86 ( V_135 ) ;
return V_135 ;
V_164:
F_84 ( V_135 ) ;
return NULL ;
}
static const char * F_89 ( const char * V_10 , const char * V_165 )
{
T_11 V_166 = strlen ( V_165 ) ;
const char * V_167 = V_10 ;
if ( strlen ( V_10 ) > V_166 ) {
V_167 = V_10 + strlen ( V_10 ) - V_166 ;
if ( ! strncmp ( V_167 , V_165 , V_166 ) )
return V_167 ;
}
return NULL ;
}
static int F_90 ( struct V_161 * V_168 , const char * V_169 )
{
char line [ V_170 ] , * V_167 ;
T_12 * V_171 ;
V_171 = fopen ( V_169 , L_74 ) ;
if ( ! V_171 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_171 ) ) {
V_167 = F_91 ( line ) ;
if ( strlen ( V_167 ) == 0 )
continue;
if ( * V_167 != '#' )
continue;
V_167 ++ ;
if ( strlen ( V_167 ) && * V_167 == '!' )
continue;
V_167 = F_91 ( V_167 ) ;
if ( strlen ( V_167 ) && V_167 [ strlen ( V_167 ) - 1 ] == '\n' )
V_167 [ strlen ( V_167 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_167 , L_75 , strlen ( L_75 ) ) ) {
V_167 += strlen ( L_75 ) ;
V_168 -> V_162 = F_77 ( F_91 ( V_167 ) ) ;
continue;
}
if ( ! strncmp ( V_167 , L_76 , strlen ( L_76 ) ) ) {
V_167 += strlen ( L_76 ) ;
V_168 -> args = F_77 ( F_91 ( V_167 ) ) ;
continue;
}
}
fclose ( V_171 ) ;
return 0 ;
}
static char * F_92 ( struct V_154 * V_172 , const char * V_165 )
{
char * V_173 , * V_10 ;
V_173 = F_77 ( V_172 -> V_159 ) ;
if ( ! V_173 )
return NULL ;
V_10 = ( char * ) F_89 ( V_173 , V_165 ) ;
if ( ! V_10 ) {
free ( V_173 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_173 ;
}
static int F_93 ( const struct V_140 * T_9 V_101 ,
const char * V_135 V_101 ,
int T_10 V_101 )
{
struct V_154 * V_174 , * V_175 , V_172 , V_176 ;
char V_177 [ V_178 ] ;
T_13 * V_179 , * V_180 ;
char V_181 [ V_178 ] ;
char V_182 [ V_178 ] ;
struct V_161 * V_168 ;
char V_183 [ V_170 ] ;
char * V_173 ;
snprintf ( V_177 , V_178 , L_77 , F_94 () ) ;
V_179 = F_95 ( V_177 ) ;
if ( ! V_179 )
return - 1 ;
F_96 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_182 , V_178 , L_78 , V_177 ,
V_176 . V_159 ) ;
V_180 = F_95 ( V_182 ) ;
if ( ! V_180 )
continue;
F_97 (lang_path, lang_dir, script_dirent, script_next) {
V_173 = F_92 ( & V_172 , V_184 ) ;
if ( V_173 ) {
V_168 = F_88 ( V_173 ) ;
snprintf ( V_181 , V_178 , L_73 ,
V_182 , V_172 . V_159 ) ;
F_90 ( V_168 , V_181 ) ;
free ( V_173 ) ;
}
}
}
fprintf ( stdout , L_79 ) ;
F_71 (desc, &script_descs, node) {
sprintf ( V_183 , L_80 , V_168 -> V_139 ,
V_168 -> args ? V_168 -> args : L_1 ) ;
fprintf ( stdout , L_81 , V_183 ,
V_168 -> V_162 ? V_168 -> V_162 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_98 ( char * V_185 , char * V_186 ,
struct V_20 * V_21 )
{
char V_169 [ V_178 ] , V_18 [ 128 ] ;
char line [ V_170 ] , * V_167 ;
struct V_11 * V_93 ;
int V_187 , V_143 ;
T_12 * V_171 ;
sprintf ( V_169 , L_82 , V_185 , V_186 ) ;
V_171 = fopen ( V_169 , L_74 ) ;
if ( ! V_171 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_171 ) ) {
V_167 = F_91 ( line ) ;
if ( * V_167 == '#' )
continue;
while ( strlen ( V_167 ) ) {
V_167 = strstr ( V_167 , L_83 ) ;
if ( ! V_167 )
break;
V_167 += 2 ;
V_167 = F_91 ( V_167 ) ;
V_143 = strcspn ( V_167 , L_84 ) ;
if ( ! V_143 )
break;
snprintf ( V_18 , V_143 + 1 , L_85 , V_167 ) ;
V_187 = 0 ;
F_17 (session->evlist, pos) {
if ( ! strcmp ( F_5 ( V_93 ) , V_18 ) ) {
V_187 = 1 ;
break;
}
}
if ( ! V_187 ) {
fclose ( V_171 ) ;
return - 1 ;
}
}
}
fclose ( V_171 ) ;
return 0 ;
}
int F_99 ( char * * V_188 , char * * V_189 )
{
struct V_154 * V_174 , * V_175 , V_172 , V_176 ;
char V_177 [ V_178 ] , V_182 [ V_178 ] ;
T_13 * V_179 , * V_180 ;
struct V_20 * V_21 ;
struct V_190 V_191 = {
. V_156 = V_192 ,
. V_193 = V_194 ,
} ;
char * V_195 ;
int V_7 = 0 ;
V_21 = F_100 ( & V_191 , false , NULL ) ;
if ( ! V_21 )
return - 1 ;
snprintf ( V_177 , V_178 , L_77 , F_94 () ) ;
V_179 = F_95 ( V_177 ) ;
if ( ! V_179 ) {
F_101 ( V_21 ) ;
return - 1 ;
}
F_96 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_182 , V_178 , L_73 , V_177 ,
V_176 . V_159 ) ;
#ifdef F_102
if ( strstr ( V_182 , L_86 ) )
continue;
#endif
#ifdef F_103
if ( strstr ( V_182 , L_87 ) )
continue;
#endif
V_180 = F_95 ( V_182 ) ;
if ( ! V_180 )
continue;
F_97 (lang_path, lang_dir, script_dirent, script_next) {
if ( strstr ( V_172 . V_159 , L_88 ) )
continue;
sprintf ( V_189 [ V_7 ] , L_73 , V_182 ,
V_172 . V_159 ) ;
V_195 = strchr ( V_172 . V_159 , '.' ) ;
snprintf ( V_188 [ V_7 ] ,
( V_195 - V_172 . V_159 ) + 1 ,
L_85 , V_172 . V_159 ) ;
if ( F_98 ( V_182 ,
V_188 [ V_7 ] , V_21 ) )
continue;
V_7 ++ ;
}
F_104 ( V_180 ) ;
}
F_104 ( V_179 ) ;
F_101 ( V_21 ) ;
return V_7 ;
}
static char * F_105 ( const char * V_173 , const char * V_165 )
{
struct V_154 * V_174 , * V_175 , V_172 , V_176 ;
char V_177 [ V_178 ] ;
char V_181 [ V_178 ] ;
T_13 * V_179 , * V_180 ;
char V_182 [ V_178 ] ;
char * V_196 ;
snprintf ( V_177 , V_178 , L_77 , F_94 () ) ;
V_179 = F_95 ( V_177 ) ;
if ( ! V_179 )
return NULL ;
F_96 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_182 , V_178 , L_78 , V_177 ,
V_176 . V_159 ) ;
V_180 = F_95 ( V_182 ) ;
if ( ! V_180 )
continue;
F_97 (lang_path, lang_dir, script_dirent, script_next) {
V_196 = F_92 ( & V_172 , V_165 ) ;
if ( V_196 && ! strcmp ( V_173 , V_196 ) ) {
free ( V_196 ) ;
F_104 ( V_180 ) ;
F_104 ( V_179 ) ;
snprintf ( V_181 , V_178 , L_73 ,
V_182 , V_172 . V_159 ) ;
return F_77 ( V_181 ) ;
}
free ( V_196 ) ;
}
F_104 ( V_180 ) ;
}
F_104 ( V_179 ) ;
return NULL ;
}
static bool F_106 ( const char * V_181 )
{
return F_89 ( V_181 , L_89 ) == NULL ? false : true ;
}
static int F_107 ( char * V_181 )
{
struct V_161 * V_168 ;
int V_197 = 0 ;
char * V_167 ;
V_168 = F_82 ( NULL ) ;
if ( F_90 ( V_168 , V_181 ) )
goto V_61;
if ( ! V_168 -> args )
goto V_61;
for ( V_167 = V_168 -> args ; * V_167 ; V_167 ++ )
if ( * V_167 == '<' )
V_197 ++ ;
V_61:
F_84 ( V_168 ) ;
return V_197 ;
}
static int F_108 ( int T_4 , const char * * T_5 )
{
char * * V_198 = malloc ( sizeof( const char * ) * T_4 ) ;
if ( ! V_198 ) {
F_6 ( L_90 ) ;
return - 1 ;
}
memcpy ( V_198 , T_5 , sizeof( const char * ) * T_4 ) ;
T_4 = F_109 ( T_4 , ( const char * * ) V_198 , V_199 ,
NULL , V_200 ) ;
free ( V_198 ) ;
V_201 = ( T_4 == 0 ) ;
return 0 ;
}
int F_110 ( int T_4 , const char * * T_5 , const char * T_14 V_101 )
{
bool V_202 = false ;
bool V_22 = false ;
bool V_203 = false ;
bool V_204 = false ;
char * V_205 = NULL ;
char * V_206 = NULL ;
struct V_20 * V_21 ;
struct V_207 V_207 = { . V_208 = false , } ;
char * V_181 = NULL ;
const char * * V_198 ;
int V_7 , V_1 , V_121 = 0 ;
struct V_118 T_3 = {
. T_7 = {
. V_65 = F_42 ,
. V_126 = F_61 ,
. V_127 = F_63 ,
. V_123 = F_53 ,
. exit = F_59 ,
. V_125 = F_57 ,
. V_17 = F_46 ,
. V_209 = V_210 ,
. V_211 = V_212 ,
. V_213 = V_214 ,
. V_215 = V_216 ,
. V_217 = V_218 ,
. V_219 = V_220 ,
. V_221 = true ,
. V_222 = true ,
} ,
} ;
struct V_190 V_191 = {
. V_193 = V_194 ,
} ;
const struct V_140 V_223 [] = {
F_111 ( 'D' , L_91 , & V_224 ,
L_92 ) ,
F_112 ( 'v' , L_93 , & V_225 ,
L_94 ) ,
F_111 ( 'L' , L_95 , & V_71 ,
L_96 ) ,
F_113 ( 'l' , L_97 , NULL , NULL , L_98 ,
F_93 ) ,
F_114 ( 's' , L_99 , NULL , L_100 ,
L_101 ,
F_76 ) ,
F_115 ( 'g' , L_102 , & V_226 , L_55 ,
L_103 ) ,
F_115 ( 'i' , L_104 , & V_192 , L_105 , L_106 ) ,
F_111 ( 'd' , L_107 , & V_109 ,
L_108 ) ,
F_111 ( 0 , L_109 , & V_22 , L_110 ) ,
F_111 ( 0 , L_111 , & V_203 , L_112 ) ,
F_115 ( 'k' , L_113 , & V_59 . V_227 ,
L_105 , L_114 ) ,
F_115 ( 0 , L_115 , & V_59 . V_228 ,
L_105 , L_116 ) ,
F_111 ( 'G' , L_117 , & V_56 ,
L_118 ) ,
F_115 ( 0 , L_119 , & V_59 . V_229 , L_120 ,
L_121 ) ,
F_114 ( 'F' , L_122 , NULL , L_123 ,
L_124
L_125
L_126
L_127 , F_78 ) ,
F_111 ( 'a' , L_128 , & V_201 ,
L_129 ) ,
F_115 ( 'S' , L_130 , & V_59 . V_230 , L_131 ,
L_132 ) ,
F_115 ( 'C' , L_133 , & V_114 , L_133 , L_134 ) ,
F_115 ( 'c' , L_135 , & V_59 . V_231 , L_136 ,
L_137 ) ,
F_115 ( 0 , L_138 , & V_59 . V_232 , L_139 ,
L_140 ) ,
F_115 ( 0 , L_141 , & V_59 . V_233 , L_142 ,
L_143 ) ,
F_111 ( 'I' , L_144 , & V_202 ,
L_145 ) ,
F_111 ( '\0' , L_146 , & V_59 . V_234 ,
L_147 ) ,
F_111 ( '\0' , L_148 , & T_3 . V_130 ,
L_149 ) ,
F_111 ( '\0' , L_150 , & T_3 . V_131 ,
L_151 ) ,
F_111 ( 'f' , L_152 , & V_191 . V_235 , L_153 ) ,
F_116 ( 0 , L_154 , & V_207 , NULL , L_155 ,
L_156 ,
V_236 ) ,
F_117 ()
} ;
const char * const V_237 [] = { L_157 , L_158 , NULL } ;
const char * V_238 [] = {
L_159 ,
L_160 ,
L_161 ,
L_162 ,
L_163 ,
NULL
} ;
F_37 () ;
T_4 = F_118 ( T_4 , T_5 , V_223 , V_237 , V_238 ,
V_200 ) ;
V_191 . V_156 = V_192 ;
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_164 , strlen ( L_164 ) ) ) {
V_205 = F_105 ( T_5 [ 1 ] , V_239 ) ;
if ( ! V_205 )
return F_119 ( T_4 , T_5 , NULL ) ;
}
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_165 , strlen ( L_165 ) ) ) {
V_206 = F_105 ( T_5 [ 1 ] , V_184 ) ;
if ( ! V_206 ) {
fprintf ( V_138 ,
L_166
L_167 ) ;
return - 1 ;
}
}
F_120 ( F_94 () ) ;
if ( T_4 && ! V_144 && ! V_205 && ! V_206 ) {
int V_240 [ 2 ] ;
int V_241 ;
T_15 V_72 ;
V_205 = F_105 ( T_5 [ 0 ] , V_239 ) ;
V_206 = F_105 ( T_5 [ 0 ] , V_184 ) ;
if ( ! V_205 && ! V_206 ) {
fprintf ( V_138 , L_168
L_169 , T_5 [ 0 ] ) ;
F_121 ( V_238 , V_223 ) ;
}
if ( F_106 ( T_5 [ 0 ] ) ) {
V_241 = T_4 - 1 ;
} else {
int V_242 ;
V_241 = F_107 ( V_206 ) ;
V_242 = ( T_4 - 1 ) - V_241 ;
if ( V_242 < 0 ) {
fprintf ( V_138 , L_170
L_171
L_172 , T_5 [ 0 ] ) ;
F_121 ( V_238 , V_223 ) ;
}
}
if ( F_122 ( V_240 ) < 0 ) {
perror ( L_173 ) ;
return - 1 ;
}
V_72 = V_125 () ;
if ( V_72 < 0 ) {
perror ( L_174 ) ;
return - 1 ;
}
if ( ! V_72 ) {
V_1 = 0 ;
F_123 ( V_240 [ 1 ] , 1 ) ;
F_124 ( V_240 [ 0 ] ) ;
if ( F_106 ( T_5 [ 0 ] ) ) {
V_201 = true ;
} else if ( ! V_201 ) {
if ( F_108 ( T_4 - V_241 , & T_5 [ V_241 ] ) != 0 ) {
V_121 = - 1 ;
goto V_61;
}
}
V_198 = malloc ( ( T_4 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_198 ) {
F_6 ( L_90 ) ;
V_121 = - V_148 ;
goto V_61;
}
V_198 [ V_1 ++ ] = L_175 ;
V_198 [ V_1 ++ ] = V_205 ;
if ( V_201 )
V_198 [ V_1 ++ ] = L_176 ;
V_198 [ V_1 ++ ] = L_177 ;
V_198 [ V_1 ++ ] = L_178 ;
V_198 [ V_1 ++ ] = L_179 ;
for ( V_7 = V_241 + 1 ; V_7 < T_4 ; V_7 ++ )
V_198 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_198 [ V_1 ++ ] = NULL ;
F_125 ( L_175 , ( char * * ) V_198 ) ;
free ( V_198 ) ;
exit ( - 1 ) ;
}
F_123 ( V_240 [ 0 ] , 0 ) ;
F_124 ( V_240 [ 1 ] ) ;
V_198 = malloc ( ( T_4 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_198 ) {
F_6 ( L_90 ) ;
V_121 = - V_148 ;
goto V_61;
}
V_1 = 0 ;
V_198 [ V_1 ++ ] = L_175 ;
V_198 [ V_1 ++ ] = V_206 ;
for ( V_7 = 1 ; V_7 < V_241 + 1 ; V_7 ++ )
V_198 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_198 [ V_1 ++ ] = L_180 ;
V_198 [ V_1 ++ ] = L_179 ;
V_198 [ V_1 ++ ] = NULL ;
F_125 ( L_175 , ( char * * ) V_198 ) ;
free ( V_198 ) ;
exit ( - 1 ) ;
}
if ( V_205 )
V_181 = V_205 ;
if ( V_206 )
V_181 = V_206 ;
if ( V_181 ) {
V_1 = 0 ;
if ( ! V_205 )
V_201 = false ;
else if ( ! V_201 ) {
if ( F_108 ( T_4 - 1 , & T_5 [ 1 ] ) != 0 ) {
V_121 = - 1 ;
goto V_61;
}
}
V_198 = malloc ( ( T_4 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_198 ) {
F_6 ( L_90 ) ;
V_121 = - V_148 ;
goto V_61;
}
V_198 [ V_1 ++ ] = L_175 ;
V_198 [ V_1 ++ ] = V_181 ;
if ( V_201 )
V_198 [ V_1 ++ ] = L_176 ;
for ( V_7 = 2 ; V_7 < T_4 ; V_7 ++ )
V_198 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_198 [ V_1 ++ ] = NULL ;
F_125 ( L_175 , ( char * * ) V_198 ) ;
free ( V_198 ) ;
exit ( - 1 ) ;
}
if ( ! V_144 )
F_126 () ;
V_21 = F_100 ( & V_191 , false , & T_3 . T_7 ) ;
if ( V_21 == NULL )
return - 1 ;
if ( V_22 || V_203 ) {
F_127 ( V_21 , stdout , V_202 ) ;
if ( V_203 )
goto V_243;
}
if ( F_128 ( & V_21 -> V_22 . V_244 ) < 0 )
goto V_243;
T_3 . V_21 = V_21 ;
V_21 -> V_207 = & V_207 ;
if ( V_114 ) {
V_121 = F_129 ( V_21 , V_114 , V_115 ) ;
if ( V_121 < 0 )
goto V_243;
}
if ( ! V_56 )
V_59 . V_57 = true ;
else
V_59 . V_57 = false ;
if ( V_226 ) {
struct V_157 V_245 ;
int V_246 ;
if ( F_1 () ) {
fprintf ( V_138 ,
L_181 ) ;
V_121 = - V_25 ;
goto V_243;
}
V_246 = F_130 ( V_191 . V_156 , V_247 ) ;
if ( V_246 < 0 ) {
V_121 = - V_248 ;
perror ( L_182 ) ;
goto V_243;
}
V_121 = F_131 ( V_246 , & V_245 ) ;
if ( V_121 < 0 ) {
perror ( L_183 ) ;
goto V_243;
}
if ( ! V_245 . V_249 ) {
fprintf ( V_138 , L_184 ) ;
goto V_243;
}
V_103 = F_74 ( V_226 ) ;
if ( ! V_103 ) {
fprintf ( V_138 , L_56 ) ;
V_121 = - V_250 ;
goto V_243;
}
V_121 = V_103 -> V_251 ( V_21 -> V_252 . V_102 ,
L_185 ) ;
goto V_243;
}
if ( V_144 ) {
V_121 = V_103 -> V_253 ( V_144 , T_4 , T_5 ) ;
if ( V_121 )
goto V_243;
F_7 ( L_186 , V_144 ) ;
V_204 = true ;
}
V_121 = F_14 ( V_21 ) ;
if ( V_121 < 0 )
goto V_243;
V_121 = F_65 ( & T_3 ) ;
F_40 () ;
V_243:
F_101 ( V_21 ) ;
if ( V_204 )
F_41 () ;
V_61:
return V_121 ;
}
