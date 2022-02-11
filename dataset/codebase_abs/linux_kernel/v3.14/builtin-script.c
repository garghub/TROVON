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
if ( ! V_26 &&
! ( V_16 -> V_13 & V_27 ) )
V_28 . V_29 = false ;
}
if ( F_9 ( V_30 ) &&
F_4 ( V_12 , V_31 , L_7 ,
V_32 ) )
return - V_22 ;
if ( F_9 ( V_33 ) && ! F_9 ( V_23 ) && ! F_9 ( V_30 ) ) {
F_6 ( L_8
L_9
L_10 ) ;
return - V_22 ;
}
if ( F_9 ( V_34 ) && ! F_9 ( V_33 ) ) {
F_6 ( L_11
L_12 ) ;
return - V_22 ;
}
if ( F_9 ( V_35 ) && ! F_9 ( V_23 ) && ! F_9 ( V_30 ) ) {
F_6 ( L_13
L_9
L_14 ) ;
return - V_22 ;
}
if ( F_9 ( V_36 ) && ! F_9 ( V_23 ) ) {
F_6 ( L_15
L_16 ) ;
return - V_22 ;
}
if ( ( F_9 ( V_37 ) || F_9 ( V_38 ) ) &&
F_4 ( V_12 , V_39 , L_17 ,
V_40 | V_41 ) )
return - V_22 ;
if ( F_9 ( TIME ) &&
F_4 ( V_12 , V_42 , L_18 ,
V_43 ) )
return - V_22 ;
if ( F_9 ( V_44 ) &&
F_4 ( V_12 , V_45 , L_19 ,
V_46 ) )
return - V_22 ;
return 0 ;
}
static void F_11 ( struct V_15 * V_16 )
{
unsigned int type = V_16 -> type ;
V_3 [ type ] . V_47 = 0 ;
if ( F_9 ( V_23 ) )
V_3 [ type ] . V_47 |= V_48 ;
if ( F_9 ( V_33 ) )
V_3 [ type ] . V_47 |= V_49 ;
if ( F_9 ( V_35 ) )
V_3 [ type ] . V_47 |= V_50 ;
if ( F_9 ( V_34 ) )
V_3 [ type ] . V_47 |= V_51 ;
if ( F_9 ( V_36 ) )
V_3 [ type ] . V_47 |= V_52 ;
}
static int F_12 ( struct V_19 * V_20 )
{
int V_1 ;
struct V_11 * V_12 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_12 = F_13 ( V_20 , V_1 ) ;
if ( ! V_12 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_53 ) {
F_6 ( L_20
L_21 ,
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
if ( V_28 . V_29 &&
! V_3 [ V_54 ] . V_4 ) {
struct V_15 * V_16 ;
V_1 = V_54 ;
V_12 = F_13 ( V_20 , V_1 ) ;
if ( V_12 == NULL )
goto V_55;
V_16 = & V_12 -> V_16 ;
if ( V_16 -> V_13 & V_27 ) {
V_3 [ V_1 ] . V_18 |= V_25 ;
V_3 [ V_1 ] . V_18 |= V_56 ;
V_3 [ V_1 ] . V_18 |= V_57 ;
F_11 ( V_16 ) ;
}
}
V_55:
return 0 ;
}
static void F_15 ( struct V_58 * V_59 ,
struct V_60 * V_60 ,
struct V_11 * V_12 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
unsigned long V_61 ;
unsigned long V_62 ;
unsigned long long V_63 ;
if ( F_9 ( V_64 ) ) {
if ( V_65 )
printf ( L_22 , F_16 ( V_60 ) ) ;
else if ( F_9 ( V_23 ) && V_28 . V_29 )
printf ( L_23 , F_16 ( V_60 ) ) ;
else
printf ( L_24 , F_16 ( V_60 ) ) ;
}
if ( F_9 ( V_37 ) && F_9 ( V_38 ) )
printf ( L_25 , V_59 -> V_66 , V_59 -> V_67 ) ;
else if ( F_9 ( V_37 ) )
printf ( L_26 , V_59 -> V_66 ) ;
else if ( F_9 ( V_38 ) )
printf ( L_26 , V_59 -> V_67 ) ;
if ( F_9 ( V_44 ) ) {
if ( V_65 )
printf ( L_27 , V_59 -> V_68 ) ;
else
printf ( L_28 , V_59 -> V_68 ) ;
}
if ( F_9 ( TIME ) ) {
V_63 = V_59 -> time ;
V_61 = V_63 / V_69 ;
V_63 -= V_61 * V_69 ;
V_62 = V_63 / V_70 ;
printf ( L_29 , V_61 , V_62 ) ;
}
}
static bool F_17 ( struct V_15 * V_16 )
{
return ( ( V_16 -> type == V_71 ) &&
( V_16 -> V_72 & V_73 ) &&
( V_16 -> V_74 == 1 ) ) ;
}
static bool F_18 ( struct V_15 * V_16 )
{
if ( ( V_16 -> type == V_75 ) &&
( ( V_16 -> V_72 == V_76 ) ||
( V_16 -> V_72 == V_77 ) ||
( V_16 -> V_72 == V_78 ) ) )
return true ;
if ( F_17 ( V_16 ) )
return true ;
return false ;
}
static void F_19 ( union V_79 * V_80 ,
struct V_58 * V_59 ,
struct V_81 * V_81 ,
struct V_60 * V_60 ,
struct V_15 * V_16 )
{
struct V_82 V_83 ;
T_2 V_84 = V_80 -> V_85 . V_86 & V_87 ;
printf ( L_30 V_88 , V_59 -> V_89 ) ;
if ( ! F_18 ( V_16 ) )
return;
F_20 ( V_60 , V_81 , V_84 , V_90 ,
V_59 -> V_89 , & V_83 ) ;
if ( ! V_83 . V_91 )
F_20 ( V_60 , V_81 , V_84 , V_92 ,
V_59 -> V_89 , & V_83 ) ;
V_83 . V_68 = V_59 -> V_68 ;
V_83 . V_93 = NULL ;
if ( V_83 . V_91 )
V_83 . V_93 = F_21 ( V_83 . V_91 , V_83 . V_89 , NULL ) ;
if ( F_9 ( V_33 ) ) {
printf ( L_31 ) ;
if ( F_9 ( V_34 ) )
F_22 ( V_83 . V_93 , & V_83 , stdout ) ;
else
F_23 ( V_83 . V_93 , stdout ) ;
}
if ( F_9 ( V_35 ) ) {
printf ( L_32 ) ;
F_24 ( V_83 . V_91 , stdout ) ;
printf ( L_33 ) ;
}
}
static void F_25 ( union V_79 * V_80 ,
struct V_58 * V_59 ,
struct V_11 * V_12 ,
struct V_60 * V_60 ,
struct V_82 * V_83 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( F_9 ( V_23 ) ) {
if ( ! V_28 . V_29 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_26 ( V_12 , V_59 , V_83 ,
V_3 [ V_16 -> type ] . V_47 ,
V_94 ) ;
}
printf ( L_35 ) ;
if ( F_9 ( V_30 ) ||
( ( V_12 -> V_16 . V_13 & V_31 ) &&
! V_3 [ V_16 -> type ] . V_4 ) )
F_19 ( V_80 , V_59 , V_83 -> V_81 , V_60 , V_16 ) ;
printf ( L_34 ) ;
}
static void F_27 ( union V_79 * V_80 , struct V_58 * V_59 ,
struct V_11 * V_12 , struct V_60 * V_60 ,
struct V_82 * V_83 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( V_3 [ V_16 -> type ] . V_18 == 0 )
return;
F_15 ( V_59 , V_60 , V_12 ) ;
if ( F_9 ( V_95 ) ) {
const char * V_17 = F_5 ( V_12 ) ;
printf ( L_36 , V_17 ? V_17 : L_37 ) ;
}
if ( F_17 ( V_16 ) ) {
F_25 ( V_80 , V_59 , V_12 , V_60 , V_83 ) ;
return;
}
if ( F_9 ( V_21 ) )
F_28 ( V_12 -> V_96 , V_59 -> V_68 ,
V_59 -> V_97 , V_59 -> V_98 ) ;
if ( F_9 ( V_30 ) )
F_19 ( V_80 , V_59 , V_83 -> V_81 , V_60 , V_16 ) ;
if ( F_9 ( V_23 ) ) {
if ( ! V_28 . V_29 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_26 ( V_12 , V_59 , V_83 ,
V_3 [ V_16 -> type ] . V_47 ,
V_94 ) ;
}
printf ( L_34 ) ;
}
static int F_29 ( const char * T_3 V_99 ,
int T_4 V_99 ,
const char * * T_5 V_99 )
{
return 0 ;
}
static int F_30 ( void )
{
return 0 ;
}
static int F_31 ( struct V_100 * V_100 V_99 ,
const char * T_6 V_99 )
{
return 0 ;
}
static void F_32 ( void )
{
F_33 () ;
F_34 () ;
V_101 = & V_102 ;
}
static int F_35 ( void )
{
F_7 ( L_38 ) ;
return V_101 -> V_103 () ;
}
static int F_36 ( struct V_104 * T_7 V_99 ,
union V_79 * V_80 ,
struct V_58 * V_59 ,
struct V_11 * V_12 ,
struct V_81 * V_81 )
{
struct V_82 V_83 ;
struct V_60 * V_60 = F_37 ( V_81 , V_59 -> V_66 ,
V_59 -> V_67 ) ;
if ( V_60 == NULL ) {
F_7 ( L_39 ,
V_80 -> V_85 . type ) ;
return - 1 ;
}
if ( V_105 ) {
if ( V_59 -> time < V_106 ) {
F_6 ( L_40 V_107
L_41 V_107 L_34 , V_106 ,
V_59 -> time ) ;
V_108 ++ ;
}
V_106 = V_59 -> time ;
return 0 ;
}
if ( F_38 ( V_80 , V_81 , & V_83 , V_59 ) < 0 ) {
F_6 ( L_39 ,
V_80 -> V_85 . type ) ;
return - 1 ;
}
if ( V_83 . V_109 )
return 0 ;
if ( V_110 && ! F_39 ( V_59 -> V_68 , V_111 ) )
return 0 ;
V_101 -> F_27 ( V_80 , V_59 , V_12 , V_60 , & V_83 ) ;
V_12 -> V_112 . V_113 . V_114 += V_59 -> V_115 ;
return 0 ;
}
static int F_40 ( struct V_104 * T_7 , union V_79 * V_80 ,
struct V_116 * * V_117 )
{
struct V_118 * V_119 = F_41 ( T_7 , struct V_118 , T_7 ) ;
struct V_116 * V_120 ;
struct V_11 * V_12 , * V_121 ;
int V_122 ;
V_122 = F_42 ( T_7 , V_80 , V_117 ) ;
if ( V_122 )
return V_122 ;
V_120 = * V_117 ;
V_12 = F_43 ( * V_117 ) ;
if ( V_12 -> V_16 . type >= V_2 )
return 0 ;
F_44 (evlist, pos) {
if ( V_121 -> V_16 . type == V_12 -> V_16 . type && V_121 != V_12 )
return 0 ;
}
F_11 ( & V_12 -> V_16 ) ;
return F_8 ( V_12 , V_119 -> V_20 ) ;
}
static int F_45 ( struct V_104 * T_7 ,
union V_79 * V_80 ,
struct V_58 * V_59 ,
struct V_81 * V_81 )
{
struct V_60 * V_60 ;
struct V_118 * T_3 = F_41 ( T_7 , struct V_118 , T_7 ) ;
struct V_19 * V_20 = T_3 -> V_20 ;
struct V_11 * V_12 = F_46 ( V_20 -> V_120 ) ;
int V_123 = - 1 ;
V_60 = F_37 ( V_81 , V_80 -> V_124 . V_66 , V_80 -> V_124 . V_67 ) ;
if ( V_60 == NULL ) {
F_7 ( L_42 ) ;
return - 1 ;
}
if ( F_47 ( T_7 , V_80 , V_59 , V_81 ) < 0 )
goto V_55;
if ( ! V_12 -> V_16 . V_125 ) {
V_59 -> V_68 = 0 ;
V_59 -> time = 0 ;
V_59 -> V_67 = V_80 -> V_124 . V_67 ;
V_59 -> V_66 = V_80 -> V_124 . V_66 ;
}
F_15 ( V_59 , V_60 , V_12 ) ;
F_48 ( V_80 , stdout ) ;
V_123 = 0 ;
V_55:
return V_123 ;
}
static int F_49 ( struct V_104 * T_7 ,
union V_79 * V_80 ,
struct V_58 * V_59 ,
struct V_81 * V_81 )
{
struct V_60 * V_60 ;
struct V_118 * T_3 = F_41 ( T_7 , struct V_118 , T_7 ) ;
struct V_19 * V_20 = T_3 -> V_20 ;
struct V_11 * V_12 = F_46 ( V_20 -> V_120 ) ;
if ( F_50 ( T_7 , V_80 , V_59 , V_81 ) < 0 )
return - 1 ;
V_60 = F_37 ( V_81 , V_80 -> V_126 . V_66 , V_80 -> V_126 . V_67 ) ;
if ( V_60 == NULL ) {
F_7 ( L_43 ) ;
return - 1 ;
}
if ( ! V_12 -> V_16 . V_125 ) {
V_59 -> V_68 = 0 ;
V_59 -> time = V_80 -> V_126 . time ;
V_59 -> V_67 = V_80 -> V_126 . V_67 ;
V_59 -> V_66 = V_80 -> V_126 . V_66 ;
}
F_15 ( V_59 , V_60 , V_12 ) ;
F_48 ( V_80 , stdout ) ;
return 0 ;
}
static int F_51 ( struct V_104 * T_7 ,
union V_79 * V_80 ,
struct V_58 * V_59 ,
struct V_81 * V_81 )
{
struct V_60 * V_60 ;
struct V_118 * T_3 = F_41 ( T_7 , struct V_118 , T_7 ) ;
struct V_19 * V_20 = T_3 -> V_20 ;
struct V_11 * V_12 = F_46 ( V_20 -> V_120 ) ;
V_60 = F_37 ( V_81 , V_80 -> V_126 . V_66 , V_80 -> V_126 . V_67 ) ;
if ( V_60 == NULL ) {
F_7 ( L_44 ) ;
return - 1 ;
}
if ( ! V_12 -> V_16 . V_125 ) {
V_59 -> V_68 = 0 ;
V_59 -> time = 0 ;
V_59 -> V_67 = V_80 -> V_124 . V_67 ;
V_59 -> V_66 = V_80 -> V_124 . V_66 ;
}
F_15 ( V_59 , V_60 , V_12 ) ;
F_48 ( V_80 , stdout ) ;
if ( F_52 ( T_7 , V_80 , V_59 , V_81 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_53 ( struct V_104 * T_7 ,
union V_79 * V_80 ,
struct V_58 * V_59 ,
struct V_81 * V_81 )
{
struct V_60 * V_60 ;
struct V_118 * T_3 = F_41 ( T_7 , struct V_118 , T_7 ) ;
struct V_19 * V_20 = T_3 -> V_20 ;
struct V_11 * V_12 = F_46 ( V_20 -> V_120 ) ;
if ( F_54 ( T_7 , V_80 , V_59 , V_81 ) < 0 )
return - 1 ;
V_60 = F_37 ( V_81 , V_80 -> V_127 . V_66 , V_80 -> V_127 . V_67 ) ;
if ( V_60 == NULL ) {
F_7 ( L_45 ) ;
return - 1 ;
}
if ( ! V_12 -> V_16 . V_125 ) {
V_59 -> V_68 = 0 ;
V_59 -> time = 0 ;
V_59 -> V_67 = V_80 -> V_127 . V_67 ;
V_59 -> V_66 = V_80 -> V_127 . V_66 ;
}
F_15 ( V_59 , V_60 , V_12 ) ;
F_48 ( V_80 , stdout ) ;
return 0 ;
}
static int F_55 ( struct V_104 * T_7 ,
union V_79 * V_80 ,
struct V_58 * V_59 ,
struct V_81 * V_81 )
{
struct V_60 * V_60 ;
struct V_118 * T_3 = F_41 ( T_7 , struct V_118 , T_7 ) ;
struct V_19 * V_20 = T_3 -> V_20 ;
struct V_11 * V_12 = F_46 ( V_20 -> V_120 ) ;
if ( F_56 ( T_7 , V_80 , V_59 , V_81 ) < 0 )
return - 1 ;
V_60 = F_37 ( V_81 , V_80 -> V_128 . V_66 , V_80 -> V_128 . V_67 ) ;
if ( V_60 == NULL ) {
F_7 ( L_46 ) ;
return - 1 ;
}
if ( ! V_12 -> V_16 . V_125 ) {
V_59 -> V_68 = 0 ;
V_59 -> time = 0 ;
V_59 -> V_67 = V_80 -> V_128 . V_67 ;
V_59 -> V_66 = V_80 -> V_128 . V_66 ;
}
F_15 ( V_59 , V_60 , V_12 ) ;
F_48 ( V_80 , stdout ) ;
return 0 ;
}
static void F_57 ( int T_8 V_99 )
{
V_129 = 1 ;
}
static int F_58 ( struct V_118 * T_3 )
{
int V_123 ;
signal ( V_130 , F_57 ) ;
if ( T_3 -> V_131 ) {
T_3 -> T_7 . V_124 = F_45 ;
T_3 -> T_7 . V_126 = F_49 ;
T_3 -> T_7 . exit = F_51 ;
}
if ( T_3 -> V_132 ) {
T_3 -> T_7 . V_127 = F_53 ;
T_3 -> T_7 . V_128 = F_55 ;
}
V_123 = F_59 ( T_3 -> V_20 , & T_3 -> T_7 ) ;
if ( V_105 )
F_6 ( L_47 V_107 L_34 , V_108 ) ;
return V_123 ;
}
static struct V_133 * F_60 ( const char * V_134 ,
struct V_101 * V_135 )
{
struct V_133 * V_136 = malloc ( sizeof( * V_136 ) + strlen ( V_134 ) + 1 ) ;
if ( V_136 != NULL ) {
strcpy ( V_136 -> V_134 , V_134 ) ;
V_136 -> V_135 = V_135 ;
}
return V_136 ;
}
static void F_61 ( struct V_133 * V_136 )
{
F_62 ( & V_136 -> V_137 , & V_138 ) ;
}
static struct V_133 * F_63 ( const char * V_134 )
{
struct V_133 * V_136 ;
F_64 (s, &script_specs, node)
if ( strcasecmp ( V_136 -> V_134 , V_134 ) == 0 )
return V_136 ;
return NULL ;
}
static struct V_133 * F_65 ( const char * V_134 ,
struct V_101 * V_135 )
{
struct V_133 * V_136 = F_63 ( V_134 ) ;
if ( V_136 )
return V_136 ;
V_136 = F_60 ( V_134 , V_135 ) ;
if ( ! V_136 )
return NULL ;
F_61 ( V_136 ) ;
return V_136 ;
}
int F_66 ( const char * V_134 , struct V_101 * V_135 )
{
struct V_133 * V_136 ;
V_136 = F_63 ( V_134 ) ;
if ( V_136 )
return - 1 ;
V_136 = F_65 ( V_134 , V_135 ) ;
if ( ! V_136 )
return - 1 ;
return 0 ;
}
static struct V_101 * F_67 ( const char * V_134 )
{
struct V_133 * V_136 = F_63 ( V_134 ) ;
if ( ! V_136 )
return NULL ;
return V_136 -> V_135 ;
}
static void F_68 ( void )
{
struct V_133 * V_136 ;
fprintf ( V_139 , L_34 ) ;
fprintf ( V_139 , L_48
L_49 ) ;
F_64 (s, &script_specs, node)
fprintf ( V_139 , L_50 , V_136 -> V_134 , V_136 -> V_135 -> V_140 ) ;
fprintf ( V_139 , L_34 ) ;
}
static int F_69 ( const struct V_141 * T_9 V_99 ,
const char * V_10 , int T_10 V_99 )
{
char V_134 [ V_142 ] ;
const char * T_3 , * V_143 ;
int V_144 ;
if ( strcmp ( V_10 , L_51 ) == 0 ) {
F_68 () ;
exit ( 0 ) ;
}
T_3 = strchr ( V_10 , ':' ) ;
if ( T_3 ) {
V_144 = T_3 - V_10 ;
if ( V_144 >= V_142 ) {
fprintf ( V_139 , L_52 ) ;
return - 1 ;
}
strncpy ( V_134 , V_10 , V_144 ) ;
V_134 [ V_144 ] = '\0' ;
V_101 = F_67 ( V_134 ) ;
if ( ! V_101 ) {
fprintf ( V_139 , L_52 ) ;
return - 1 ;
}
T_3 ++ ;
} else {
T_3 = V_10 ;
V_143 = strrchr ( T_3 , '.' ) ;
if ( ! V_143 ) {
fprintf ( V_139 , L_53 ) ;
return - 1 ;
}
V_101 = F_67 ( ++ V_143 ) ;
if ( ! V_101 ) {
fprintf ( V_139 , L_53 ) ;
return - 1 ;
}
}
V_145 = F_70 ( T_3 ) ;
return 0 ;
}
static int F_71 ( const struct V_141 * T_9 V_99 ,
const char * V_146 , int T_10 V_99 )
{
char * V_147 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_148 = 0 ;
char * V_10 = F_70 ( V_146 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_149 ;
V_147 = strchr ( V_10 , ':' ) ;
if ( V_147 ) {
* V_147 = '\0' ;
V_147 ++ ;
if ( ! strcmp ( V_10 , L_54 ) )
type = V_71 ;
else if ( ! strcmp ( V_10 , L_55 ) )
type = V_75 ;
else if ( ! strcmp ( V_10 , L_56 ) )
type = V_54 ;
else if ( ! strcmp ( V_10 , L_57 ) )
type = V_150 ;
else {
fprintf ( V_139 , L_58 ) ;
V_148 = - V_22 ;
goto V_55;
}
if ( V_3 [ type ] . V_4 )
F_72 ( L_59 ,
F_14 ( type ) ) ;
V_3 [ type ] . V_18 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_53 = false ;
} else {
V_147 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_139 ,
L_60 ) ;
V_148 = - V_22 ;
goto V_55;
}
if ( F_1 () )
F_72 ( L_61 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_18 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_53 = true ;
}
}
V_147 = strtok ( V_147 , L_62 ) ;
while ( V_147 ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_147 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 ) {
fprintf ( V_139 , L_63 ) ;
V_148 = - V_22 ;
goto V_55;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_151 & V_9 [ V_7 ] . V_6 ) {
F_72 ( L_64 ,
V_9 [ V_7 ] . V_10 , F_14 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_151 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_139 , L_65 ,
V_9 [ V_7 ] . V_10 , F_14 ( type ) ) ;
V_148 = - V_22 ;
goto V_55;
}
V_3 [ type ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
V_147 = strtok ( NULL , L_62 ) ;
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_18 == 0 ) {
F_7 ( L_66
L_67 , F_14 ( type ) ) ;
}
}
V_55:
free ( V_10 ) ;
return V_148 ;
}
static int F_73 ( const char * V_152 , const struct V_153 * V_154 )
{
char V_155 [ V_142 ] ;
struct V_156 V_157 ;
sprintf ( V_155 , L_68 , V_152 , V_154 -> V_158 ) ;
if ( V_156 ( V_155 , & V_157 ) )
return 0 ;
return F_74 ( V_157 . V_159 ) ;
}
static struct V_160 * F_75 ( const char * V_140 )
{
struct V_160 * V_136 = F_76 ( sizeof( * V_136 ) ) ;
if ( V_136 != NULL && V_140 )
V_136 -> V_140 = F_70 ( V_140 ) ;
return V_136 ;
}
static void F_77 ( struct V_160 * V_136 )
{
F_78 ( & V_136 -> V_140 ) ;
F_78 ( & V_136 -> V_161 ) ;
F_78 ( & V_136 -> args ) ;
free ( V_136 ) ;
}
static void F_79 ( struct V_160 * V_136 )
{
F_62 ( & V_136 -> V_137 , & V_162 ) ;
}
static struct V_160 * F_80 ( const char * V_140 )
{
struct V_160 * V_136 ;
F_64 (s, &script_descs, node)
if ( strcasecmp ( V_136 -> V_140 , V_140 ) == 0 )
return V_136 ;
return NULL ;
}
static struct V_160 * F_81 ( const char * V_140 )
{
struct V_160 * V_136 = F_80 ( V_140 ) ;
if ( V_136 )
return V_136 ;
V_136 = F_75 ( V_140 ) ;
if ( ! V_136 )
goto V_163;
F_79 ( V_136 ) ;
return V_136 ;
V_163:
F_77 ( V_136 ) ;
return NULL ;
}
static const char * F_82 ( const char * V_10 , const char * V_164 )
{
T_11 V_165 = strlen ( V_164 ) ;
const char * V_166 = V_10 ;
if ( strlen ( V_10 ) > V_165 ) {
V_166 = V_10 + strlen ( V_10 ) - V_165 ;
if ( ! strncmp ( V_166 , V_164 , V_165 ) )
return V_166 ;
}
return NULL ;
}
static int F_83 ( struct V_160 * V_167 , const char * V_168 )
{
char line [ V_169 ] , * V_166 ;
T_12 * V_170 ;
V_170 = fopen ( V_168 , L_69 ) ;
if ( ! V_170 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_170 ) ) {
V_166 = F_84 ( line ) ;
if ( strlen ( V_166 ) == 0 )
continue;
if ( * V_166 != '#' )
continue;
V_166 ++ ;
if ( strlen ( V_166 ) && * V_166 == '!' )
continue;
V_166 = F_84 ( V_166 ) ;
if ( strlen ( V_166 ) && V_166 [ strlen ( V_166 ) - 1 ] == '\n' )
V_166 [ strlen ( V_166 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_166 , L_70 , strlen ( L_70 ) ) ) {
V_166 += strlen ( L_70 ) ;
V_167 -> V_161 = F_70 ( F_84 ( V_166 ) ) ;
continue;
}
if ( ! strncmp ( V_166 , L_71 , strlen ( L_71 ) ) ) {
V_166 += strlen ( L_71 ) ;
V_167 -> args = F_70 ( F_84 ( V_166 ) ) ;
continue;
}
}
fclose ( V_170 ) ;
return 0 ;
}
static char * F_85 ( struct V_153 * V_171 , const char * V_164 )
{
char * V_172 , * V_10 ;
V_172 = F_70 ( V_171 -> V_158 ) ;
if ( ! V_172 )
return NULL ;
V_10 = ( char * ) F_82 ( V_172 , V_164 ) ;
if ( ! V_10 ) {
free ( V_172 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_172 ;
}
static int F_86 ( const struct V_141 * T_9 V_99 ,
const char * V_136 V_99 ,
int T_10 V_99 )
{
struct V_153 * V_173 , * V_174 , V_171 , V_175 ;
char V_176 [ V_177 ] ;
T_13 * V_178 , * V_179 ;
char V_180 [ V_177 ] ;
char V_181 [ V_177 ] ;
struct V_160 * V_167 ;
char V_182 [ V_169 ] ;
char * V_172 ;
snprintf ( V_176 , V_177 , L_72 , F_87 () ) ;
V_178 = F_88 ( V_176 ) ;
if ( ! V_178 )
return - 1 ;
F_89 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_181 , V_177 , L_73 , V_176 ,
V_175 . V_158 ) ;
V_179 = F_88 ( V_181 ) ;
if ( ! V_179 )
continue;
F_90 (lang_path, lang_dir, script_dirent, script_next) {
V_172 = F_85 ( & V_171 , V_183 ) ;
if ( V_172 ) {
V_167 = F_81 ( V_172 ) ;
snprintf ( V_180 , V_177 , L_68 ,
V_181 , V_171 . V_158 ) ;
F_83 ( V_167 , V_180 ) ;
free ( V_172 ) ;
}
}
}
fprintf ( stdout , L_74 ) ;
F_64 (desc, &script_descs, node) {
sprintf ( V_182 , L_75 , V_167 -> V_140 ,
V_167 -> args ? V_167 -> args : L_1 ) ;
fprintf ( stdout , L_76 , V_182 ,
V_167 -> V_161 ? V_167 -> V_161 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_91 ( char * V_184 , char * V_185 ,
struct V_19 * V_20 )
{
char V_168 [ V_177 ] , V_17 [ 128 ] ;
char line [ V_169 ] , * V_166 ;
struct V_11 * V_121 ;
int V_186 , V_144 ;
T_12 * V_170 ;
sprintf ( V_168 , L_77 , V_184 , V_185 ) ;
V_170 = fopen ( V_168 , L_69 ) ;
if ( ! V_170 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_170 ) ) {
V_166 = F_84 ( line ) ;
if ( * V_166 == '#' )
continue;
while ( strlen ( V_166 ) ) {
V_166 = strstr ( V_166 , L_78 ) ;
if ( ! V_166 )
break;
V_166 += 2 ;
V_166 = F_84 ( V_166 ) ;
V_144 = strcspn ( V_166 , L_79 ) ;
if ( ! V_144 )
break;
snprintf ( V_17 , V_144 + 1 , L_80 , V_166 ) ;
V_186 = 0 ;
F_44 (session->evlist, pos) {
if ( ! strcmp ( F_5 ( V_121 ) , V_17 ) ) {
V_186 = 1 ;
break;
}
}
if ( ! V_186 ) {
fclose ( V_170 ) ;
return - 1 ;
}
}
}
fclose ( V_170 ) ;
return 0 ;
}
int F_92 ( char * * V_187 , char * * V_188 )
{
struct V_153 * V_173 , * V_174 , V_171 , V_175 ;
char V_176 [ V_177 ] , V_181 [ V_177 ] ;
T_13 * V_178 , * V_179 ;
struct V_19 * V_20 ;
struct V_189 V_190 = {
. V_155 = V_191 ,
. V_192 = V_193 ,
} ;
char * V_194 ;
int V_7 = 0 ;
V_20 = F_93 ( & V_190 , false , NULL ) ;
if ( ! V_20 )
return - 1 ;
snprintf ( V_176 , V_177 , L_72 , F_87 () ) ;
V_178 = F_88 ( V_176 ) ;
if ( ! V_178 ) {
F_94 ( V_20 ) ;
return - 1 ;
}
F_89 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_181 , V_177 , L_68 , V_176 ,
V_175 . V_158 ) ;
#ifdef F_95
if ( strstr ( V_181 , L_81 ) )
continue;
#endif
#ifdef F_96
if ( strstr ( V_181 , L_82 ) )
continue;
#endif
V_179 = F_88 ( V_181 ) ;
if ( ! V_179 )
continue;
F_90 (lang_path, lang_dir, script_dirent, script_next) {
if ( strstr ( V_171 . V_158 , L_83 ) )
continue;
sprintf ( V_188 [ V_7 ] , L_68 , V_181 ,
V_171 . V_158 ) ;
V_194 = strchr ( V_171 . V_158 , '.' ) ;
snprintf ( V_187 [ V_7 ] ,
( V_194 - V_171 . V_158 ) + 1 ,
L_80 , V_171 . V_158 ) ;
if ( F_91 ( V_181 ,
V_187 [ V_7 ] , V_20 ) )
continue;
V_7 ++ ;
}
F_97 ( V_179 ) ;
}
F_97 ( V_178 ) ;
F_94 ( V_20 ) ;
return V_7 ;
}
static char * F_98 ( const char * V_172 , const char * V_164 )
{
struct V_153 * V_173 , * V_174 , V_171 , V_175 ;
char V_176 [ V_177 ] ;
char V_180 [ V_177 ] ;
T_13 * V_178 , * V_179 ;
char V_181 [ V_177 ] ;
char * V_195 ;
snprintf ( V_176 , V_177 , L_72 , F_87 () ) ;
V_178 = F_88 ( V_176 ) ;
if ( ! V_178 )
return NULL ;
F_89 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_181 , V_177 , L_73 , V_176 ,
V_175 . V_158 ) ;
V_179 = F_88 ( V_181 ) ;
if ( ! V_179 )
continue;
F_90 (lang_path, lang_dir, script_dirent, script_next) {
V_195 = F_85 ( & V_171 , V_164 ) ;
if ( V_195 && ! strcmp ( V_172 , V_195 ) ) {
free ( V_195 ) ;
F_97 ( V_179 ) ;
F_97 ( V_178 ) ;
snprintf ( V_180 , V_177 , L_68 ,
V_181 , V_171 . V_158 ) ;
return F_70 ( V_180 ) ;
}
free ( V_195 ) ;
}
F_97 ( V_179 ) ;
}
F_97 ( V_178 ) ;
return NULL ;
}
static bool F_99 ( const char * V_180 )
{
return F_82 ( V_180 , L_84 ) == NULL ? false : true ;
}
static int F_100 ( char * V_180 )
{
struct V_160 * V_167 ;
int V_196 = 0 ;
char * V_166 ;
V_167 = F_75 ( NULL ) ;
if ( F_83 ( V_167 , V_180 ) )
goto V_55;
if ( ! V_167 -> args )
goto V_55;
for ( V_166 = V_167 -> args ; * V_166 ; V_166 ++ )
if ( * V_166 == '<' )
V_196 ++ ;
V_55:
F_77 ( V_167 ) ;
return V_196 ;
}
static int F_101 ( int T_4 , const char * * T_5 )
{
char * * V_197 = malloc ( sizeof( const char * ) * T_4 ) ;
if ( ! V_197 ) {
F_6 ( L_85 ) ;
return - 1 ;
}
memcpy ( V_197 , T_5 , sizeof( const char * ) * T_4 ) ;
T_4 = F_102 ( T_4 , ( const char * * ) V_197 , V_198 ,
NULL , V_199 ) ;
free ( V_197 ) ;
V_200 = ( T_4 == 0 ) ;
return 0 ;
}
int F_103 ( int T_4 , const char * * T_5 , const char * T_14 V_99 )
{
bool V_201 = false ;
bool V_85 = false ;
bool V_202 = false ;
char * V_203 = NULL ;
char * V_204 = NULL ;
struct V_19 * V_20 ;
char * V_180 = NULL ;
const char * * V_197 ;
int V_7 , V_1 , V_122 ;
struct V_118 T_3 = {
. T_7 = {
. V_59 = F_36 ,
. V_127 = F_54 ,
. V_128 = F_56 ,
. V_124 = F_47 ,
. exit = F_52 ,
. V_126 = F_50 ,
. V_16 = F_40 ,
. V_205 = V_206 ,
. V_207 = V_208 ,
. V_209 = true ,
. V_210 = true ,
} ,
} ;
const struct V_141 V_211 [] = {
F_104 ( 'D' , L_86 , & V_212 ,
L_87 ) ,
F_105 ( 'v' , L_88 , & V_213 ,
L_89 ) ,
F_104 ( 'L' , L_90 , & V_65 ,
L_91 ) ,
F_106 ( 'l' , L_92 , NULL , NULL , L_93 ,
F_86 ) ,
F_107 ( 's' , L_94 , NULL , L_95 ,
L_96 ,
F_69 ) ,
F_108 ( 'g' , L_97 , & V_214 , L_51 ,
L_98 ) ,
F_108 ( 'i' , L_99 , & V_191 , L_100 , L_101 ) ,
F_104 ( 'd' , L_102 , & V_105 ,
L_103 ) ,
F_104 ( 0 , L_104 , & V_85 , L_105 ) ,
F_104 ( 0 , L_106 , & V_202 , L_107 ) ,
F_108 ( 'k' , L_108 , & V_28 . V_215 ,
L_100 , L_109 ) ,
F_108 ( 0 , L_110 , & V_28 . V_216 ,
L_100 , L_111 ) ,
F_104 ( 'G' , L_112 , & V_26 ,
L_113 ) ,
F_108 ( 0 , L_114 , & V_28 . V_217 , L_115 ,
L_116 ) ,
F_107 ( 'f' , L_117 , NULL , L_118 ,
L_119
L_120
L_121
L_122 , F_71 ) ,
F_104 ( 'a' , L_123 , & V_200 ,
L_124 ) ,
F_108 ( 'S' , L_125 , & V_28 . V_218 , L_126 ,
L_127 ) ,
F_108 ( 'C' , L_128 , & V_110 , L_128 , L_129 ) ,
F_108 ( 'c' , L_130 , & V_28 . V_219 , L_131 ,
L_132 ) ,
F_104 ( 'I' , L_133 , & V_201 ,
L_134 ) ,
F_104 ( '\0' , L_135 , & V_28 . V_220 ,
L_136 ) ,
F_104 ( '\0' , L_137 , & T_3 . V_131 ,
L_138 ) ,
F_104 ( '\0' , L_139 , & T_3 . V_132 ,
L_140 ) ,
F_109 ()
} ;
const char * const V_221 [] = {
L_141 ,
L_142 ,
L_143 ,
L_144 ,
L_145 ,
NULL
} ;
struct V_189 V_190 = {
. V_192 = V_193 ,
} ;
F_32 () ;
T_4 = F_102 ( T_4 , T_5 , V_211 , V_221 ,
V_199 ) ;
V_190 . V_155 = V_191 ;
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_146 , strlen ( L_146 ) ) ) {
V_203 = F_98 ( T_5 [ 1 ] , V_222 ) ;
if ( ! V_203 )
return F_110 ( T_4 , T_5 , NULL ) ;
}
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_147 , strlen ( L_147 ) ) ) {
V_204 = F_98 ( T_5 [ 1 ] , V_183 ) ;
if ( ! V_204 ) {
fprintf ( V_139 ,
L_148
L_149 ) ;
return - 1 ;
}
}
F_111 ( F_87 () ) ;
if ( T_4 && ! V_145 && ! V_203 && ! V_204 ) {
int V_223 [ 2 ] ;
int V_224 ;
T_15 V_66 ;
V_203 = F_98 ( T_5 [ 0 ] , V_222 ) ;
V_204 = F_98 ( T_5 [ 0 ] , V_183 ) ;
if ( ! V_203 && ! V_204 ) {
fprintf ( V_139 , L_150
L_151 , T_5 [ 0 ] ) ;
F_112 ( V_221 , V_211 ) ;
}
if ( F_99 ( T_5 [ 0 ] ) ) {
V_224 = T_4 - 1 ;
} else {
int V_225 ;
V_224 = F_100 ( V_204 ) ;
V_225 = ( T_4 - 1 ) - V_224 ;
if ( V_225 < 0 ) {
fprintf ( V_139 , L_152
L_153
L_154 , T_5 [ 0 ] ) ;
F_112 ( V_221 , V_211 ) ;
}
}
if ( F_113 ( V_223 ) < 0 ) {
perror ( L_155 ) ;
return - 1 ;
}
V_66 = V_126 () ;
if ( V_66 < 0 ) {
perror ( L_156 ) ;
return - 1 ;
}
if ( ! V_66 ) {
V_1 = 0 ;
F_114 ( V_223 [ 1 ] , 1 ) ;
F_115 ( V_223 [ 0 ] ) ;
if ( F_99 ( T_5 [ 0 ] ) ) {
V_200 = true ;
} else if ( ! V_200 ) {
if ( F_101 ( T_4 - V_224 , & T_5 [ V_224 ] ) != 0 ) {
V_122 = - 1 ;
goto V_55;
}
}
V_197 = malloc ( ( T_4 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_197 ) {
F_6 ( L_85 ) ;
V_122 = - V_149 ;
goto V_55;
}
V_197 [ V_1 ++ ] = L_157 ;
V_197 [ V_1 ++ ] = V_203 ;
if ( V_200 )
V_197 [ V_1 ++ ] = L_158 ;
V_197 [ V_1 ++ ] = L_159 ;
V_197 [ V_1 ++ ] = L_160 ;
V_197 [ V_1 ++ ] = L_161 ;
for ( V_7 = V_224 + 1 ; V_7 < T_4 ; V_7 ++ )
V_197 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_197 [ V_1 ++ ] = NULL ;
F_116 ( L_157 , ( char * * ) V_197 ) ;
free ( V_197 ) ;
exit ( - 1 ) ;
}
F_114 ( V_223 [ 0 ] , 0 ) ;
F_115 ( V_223 [ 1 ] ) ;
V_197 = malloc ( ( T_4 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_197 ) {
F_6 ( L_85 ) ;
V_122 = - V_149 ;
goto V_55;
}
V_1 = 0 ;
V_197 [ V_1 ++ ] = L_157 ;
V_197 [ V_1 ++ ] = V_204 ;
for ( V_7 = 1 ; V_7 < V_224 + 1 ; V_7 ++ )
V_197 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_197 [ V_1 ++ ] = L_162 ;
V_197 [ V_1 ++ ] = L_161 ;
V_197 [ V_1 ++ ] = NULL ;
F_116 ( L_157 , ( char * * ) V_197 ) ;
free ( V_197 ) ;
exit ( - 1 ) ;
}
if ( V_203 )
V_180 = V_203 ;
if ( V_204 )
V_180 = V_204 ;
if ( V_180 ) {
V_1 = 0 ;
if ( ! V_203 )
V_200 = false ;
else if ( ! V_200 ) {
if ( F_101 ( T_4 - 1 , & T_5 [ 1 ] ) != 0 ) {
V_122 = - 1 ;
goto V_55;
}
}
V_197 = malloc ( ( T_4 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_197 ) {
F_6 ( L_85 ) ;
V_122 = - V_149 ;
goto V_55;
}
V_197 [ V_1 ++ ] = L_157 ;
V_197 [ V_1 ++ ] = V_180 ;
if ( V_200 )
V_197 [ V_1 ++ ] = L_158 ;
for ( V_7 = 2 ; V_7 < T_4 ; V_7 ++ )
V_197 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_197 [ V_1 ++ ] = NULL ;
F_116 ( L_157 , ( char * * ) V_197 ) ;
free ( V_197 ) ;
exit ( - 1 ) ;
}
if ( F_117 () < 0 )
return - 1 ;
if ( ! V_145 )
F_118 () ;
V_20 = F_93 ( & V_190 , false , & T_3 . T_7 ) ;
if ( V_20 == NULL )
return - V_149 ;
if ( V_85 || V_202 ) {
F_119 ( V_20 , stdout , V_201 ) ;
if ( V_202 )
return 0 ;
}
T_3 . V_20 = V_20 ;
if ( V_110 ) {
if ( F_120 ( V_20 , V_110 , V_111 ) )
return - 1 ;
}
if ( ! V_26 )
V_28 . V_29 = true ;
else
V_28 . V_29 = false ;
if ( V_214 ) {
struct V_156 V_226 ;
int V_227 ;
if ( F_1 () ) {
fprintf ( V_139 ,
L_163 ) ;
return - 1 ;
}
V_227 = F_121 ( V_190 . V_155 , V_228 ) ;
if ( V_227 < 0 ) {
perror ( L_164 ) ;
return - 1 ;
}
V_122 = F_122 ( V_227 , & V_226 ) ;
if ( V_122 < 0 ) {
perror ( L_165 ) ;
return - 1 ;
}
if ( ! V_226 . V_229 ) {
fprintf ( V_139 , L_166 ) ;
return 0 ;
}
V_101 = F_67 ( V_214 ) ;
if ( ! V_101 ) {
fprintf ( V_139 , L_52 ) ;
return - 1 ;
}
V_122 = V_101 -> V_230 ( V_20 -> V_231 . V_100 ,
L_167 ) ;
goto V_55;
}
if ( V_145 ) {
V_122 = V_101 -> V_232 ( V_145 , T_4 , T_5 ) ;
if ( V_122 )
goto V_55;
F_7 ( L_168 , V_145 ) ;
}
V_122 = F_12 ( V_20 ) ;
if ( V_122 < 0 )
goto V_55;
V_122 = F_58 ( & T_3 ) ;
F_94 ( V_20 ) ;
F_35 () ;
V_55:
return V_122 ;
}
