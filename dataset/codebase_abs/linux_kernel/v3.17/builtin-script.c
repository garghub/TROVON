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
static void F_17 ( union V_71 * V_72 ,
struct V_58 * V_59 ,
struct V_73 * V_73 ,
struct V_60 * V_60 ,
struct V_15 * V_16 )
{
struct V_74 V_75 ;
printf ( L_30 V_76 , V_59 -> V_77 ) ;
if ( ! F_18 ( V_16 ) )
return;
F_19 ( V_72 , V_59 , V_73 , V_60 , & V_75 ) ;
if ( F_9 ( V_33 ) ) {
printf ( L_31 ) ;
if ( F_9 ( V_34 ) )
F_20 ( V_75 . V_78 , & V_75 , stdout ) ;
else
F_21 ( V_75 . V_78 , stdout ) ;
}
if ( F_9 ( V_35 ) ) {
printf ( L_32 ) ;
F_22 ( V_75 . V_79 , stdout ) ;
printf ( L_33 ) ;
}
}
static void F_23 ( union V_71 * V_72 ,
struct V_58 * V_59 ,
struct V_11 * V_12 ,
struct V_60 * V_60 ,
struct V_74 * V_75 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
bool V_80 = false ;
if ( F_9 ( V_23 ) ) {
unsigned int V_81 = V_3 [ V_16 -> type ] . V_47 ;
if ( V_28 . V_29 && V_59 -> V_82 ) {
printf ( L_34 ) ;
} else {
printf ( L_31 ) ;
if ( V_81 & V_52 ) {
V_80 = true ;
V_81 &= ~ V_52 ;
}
}
F_24 ( V_12 , V_59 , V_75 , V_81 ,
V_83 ) ;
}
if ( F_9 ( V_30 ) ||
( ( V_12 -> V_16 . V_13 & V_31 ) &&
! V_3 [ V_16 -> type ] . V_4 ) ) {
printf ( L_35 ) ;
F_17 ( V_72 , V_59 , V_75 -> V_73 , V_60 , V_16 ) ;
}
if ( V_80 )
F_25 ( V_75 -> V_79 , V_75 -> V_77 , L_36 , stdout ) ;
printf ( L_34 ) ;
}
static void F_26 ( union V_71 * V_72 , struct V_58 * V_59 ,
struct V_11 * V_12 , struct V_60 * V_60 ,
struct V_74 * V_75 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( V_3 [ V_16 -> type ] . V_18 == 0 )
return;
F_15 ( V_59 , V_60 , V_12 ) ;
if ( F_9 ( V_84 ) ) {
const char * V_17 = F_5 ( V_12 ) ;
printf ( L_37 , V_17 ? V_17 : L_38 ) ;
}
if ( F_27 ( V_16 ) ) {
F_23 ( V_72 , V_59 , V_12 , V_60 , V_75 ) ;
return;
}
if ( F_9 ( V_21 ) )
F_28 ( V_12 -> V_85 , V_59 -> V_68 ,
V_59 -> V_86 , V_59 -> V_87 ) ;
if ( F_9 ( V_30 ) )
F_17 ( V_72 , V_59 , V_75 -> V_73 , V_60 , V_16 ) ;
if ( F_9 ( V_23 ) ) {
if ( ! V_28 . V_29 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_24 ( V_12 , V_59 , V_75 ,
V_3 [ V_16 -> type ] . V_47 ,
V_83 ) ;
}
printf ( L_34 ) ;
}
static int F_29 ( const char * T_2 V_88 ,
int T_3 V_88 ,
const char * * T_4 V_88 )
{
return 0 ;
}
static int F_30 ( void )
{
return 0 ;
}
static int F_31 ( struct V_89 * V_89 V_88 ,
const char * T_5 V_88 )
{
return 0 ;
}
static void F_32 ( void )
{
F_33 () ;
F_34 () ;
V_90 = & V_91 ;
}
static int F_35 ( void )
{
F_7 ( L_39 ) ;
return V_90 -> V_92 () ;
}
static int F_36 ( struct V_93 * T_6 V_88 ,
union V_71 * V_72 ,
struct V_58 * V_59 ,
struct V_11 * V_12 ,
struct V_73 * V_73 )
{
struct V_74 V_75 ;
struct V_60 * V_60 = F_37 ( V_73 , V_59 -> V_66 ,
V_59 -> V_67 ) ;
if ( V_60 == NULL ) {
F_7 ( L_40 ,
V_72 -> V_94 . type ) ;
return - 1 ;
}
if ( V_95 ) {
if ( V_59 -> time < V_96 ) {
F_6 ( L_41 V_97
L_42 V_97 L_34 , V_96 ,
V_59 -> time ) ;
V_98 ++ ;
}
V_96 = V_59 -> time ;
return 0 ;
}
if ( F_38 ( V_72 , V_73 , & V_75 , V_59 ) < 0 ) {
F_6 ( L_40 ,
V_72 -> V_94 . type ) ;
return - 1 ;
}
if ( V_75 . V_99 )
return 0 ;
if ( V_100 && ! F_39 ( V_59 -> V_68 , V_101 ) )
return 0 ;
V_90 -> F_26 ( V_72 , V_59 , V_12 , V_60 , & V_75 ) ;
V_12 -> V_102 . V_103 . V_104 += V_59 -> V_105 ;
return 0 ;
}
static int F_40 ( struct V_93 * T_6 , union V_71 * V_72 ,
struct V_106 * * V_107 )
{
struct V_108 * V_109 = F_41 ( T_6 , struct V_108 , T_6 ) ;
struct V_106 * V_110 ;
struct V_11 * V_12 , * V_111 ;
int V_112 ;
V_112 = F_42 ( T_6 , V_72 , V_107 ) ;
if ( V_112 )
return V_112 ;
V_110 = * V_107 ;
V_12 = F_43 ( * V_107 ) ;
if ( V_12 -> V_16 . type >= V_2 )
return 0 ;
F_44 (evlist, pos) {
if ( V_111 -> V_16 . type == V_12 -> V_16 . type && V_111 != V_12 )
return 0 ;
}
F_11 ( & V_12 -> V_16 ) ;
return F_8 ( V_12 , V_109 -> V_20 ) ;
}
static int F_45 ( struct V_93 * T_6 ,
union V_71 * V_72 ,
struct V_58 * V_59 ,
struct V_73 * V_73 )
{
struct V_60 * V_60 ;
struct V_108 * T_2 = F_41 ( T_6 , struct V_108 , T_6 ) ;
struct V_19 * V_20 = T_2 -> V_20 ;
struct V_11 * V_12 = F_46 ( V_20 -> V_110 ) ;
int V_113 = - 1 ;
V_60 = F_37 ( V_73 , V_72 -> V_114 . V_66 , V_72 -> V_114 . V_67 ) ;
if ( V_60 == NULL ) {
F_7 ( L_43 ) ;
return - 1 ;
}
if ( F_47 ( T_6 , V_72 , V_59 , V_73 ) < 0 )
goto V_55;
if ( ! V_12 -> V_16 . V_115 ) {
V_59 -> V_68 = 0 ;
V_59 -> time = 0 ;
V_59 -> V_67 = V_72 -> V_114 . V_67 ;
V_59 -> V_66 = V_72 -> V_114 . V_66 ;
}
F_15 ( V_59 , V_60 , V_12 ) ;
F_48 ( V_72 , stdout ) ;
V_113 = 0 ;
V_55:
return V_113 ;
}
static int F_49 ( struct V_93 * T_6 ,
union V_71 * V_72 ,
struct V_58 * V_59 ,
struct V_73 * V_73 )
{
struct V_60 * V_60 ;
struct V_108 * T_2 = F_41 ( T_6 , struct V_108 , T_6 ) ;
struct V_19 * V_20 = T_2 -> V_20 ;
struct V_11 * V_12 = F_46 ( V_20 -> V_110 ) ;
if ( F_50 ( T_6 , V_72 , V_59 , V_73 ) < 0 )
return - 1 ;
V_60 = F_37 ( V_73 , V_72 -> V_116 . V_66 , V_72 -> V_116 . V_67 ) ;
if ( V_60 == NULL ) {
F_7 ( L_44 ) ;
return - 1 ;
}
if ( ! V_12 -> V_16 . V_115 ) {
V_59 -> V_68 = 0 ;
V_59 -> time = V_72 -> V_116 . time ;
V_59 -> V_67 = V_72 -> V_116 . V_67 ;
V_59 -> V_66 = V_72 -> V_116 . V_66 ;
}
F_15 ( V_59 , V_60 , V_12 ) ;
F_48 ( V_72 , stdout ) ;
return 0 ;
}
static int F_51 ( struct V_93 * T_6 ,
union V_71 * V_72 ,
struct V_58 * V_59 ,
struct V_73 * V_73 )
{
struct V_60 * V_60 ;
struct V_108 * T_2 = F_41 ( T_6 , struct V_108 , T_6 ) ;
struct V_19 * V_20 = T_2 -> V_20 ;
struct V_11 * V_12 = F_46 ( V_20 -> V_110 ) ;
V_60 = F_37 ( V_73 , V_72 -> V_116 . V_66 , V_72 -> V_116 . V_67 ) ;
if ( V_60 == NULL ) {
F_7 ( L_45 ) ;
return - 1 ;
}
if ( ! V_12 -> V_16 . V_115 ) {
V_59 -> V_68 = 0 ;
V_59 -> time = 0 ;
V_59 -> V_67 = V_72 -> V_114 . V_67 ;
V_59 -> V_66 = V_72 -> V_114 . V_66 ;
}
F_15 ( V_59 , V_60 , V_12 ) ;
F_48 ( V_72 , stdout ) ;
if ( F_52 ( T_6 , V_72 , V_59 , V_73 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_53 ( struct V_93 * T_6 ,
union V_71 * V_72 ,
struct V_58 * V_59 ,
struct V_73 * V_73 )
{
struct V_60 * V_60 ;
struct V_108 * T_2 = F_41 ( T_6 , struct V_108 , T_6 ) ;
struct V_19 * V_20 = T_2 -> V_20 ;
struct V_11 * V_12 = F_46 ( V_20 -> V_110 ) ;
if ( F_54 ( T_6 , V_72 , V_59 , V_73 ) < 0 )
return - 1 ;
V_60 = F_37 ( V_73 , V_72 -> V_117 . V_66 , V_72 -> V_117 . V_67 ) ;
if ( V_60 == NULL ) {
F_7 ( L_46 ) ;
return - 1 ;
}
if ( ! V_12 -> V_16 . V_115 ) {
V_59 -> V_68 = 0 ;
V_59 -> time = 0 ;
V_59 -> V_67 = V_72 -> V_117 . V_67 ;
V_59 -> V_66 = V_72 -> V_117 . V_66 ;
}
F_15 ( V_59 , V_60 , V_12 ) ;
F_48 ( V_72 , stdout ) ;
return 0 ;
}
static int F_55 ( struct V_93 * T_6 ,
union V_71 * V_72 ,
struct V_58 * V_59 ,
struct V_73 * V_73 )
{
struct V_60 * V_60 ;
struct V_108 * T_2 = F_41 ( T_6 , struct V_108 , T_6 ) ;
struct V_19 * V_20 = T_2 -> V_20 ;
struct V_11 * V_12 = F_46 ( V_20 -> V_110 ) ;
if ( F_56 ( T_6 , V_72 , V_59 , V_73 ) < 0 )
return - 1 ;
V_60 = F_37 ( V_73 , V_72 -> V_118 . V_66 , V_72 -> V_118 . V_67 ) ;
if ( V_60 == NULL ) {
F_7 ( L_47 ) ;
return - 1 ;
}
if ( ! V_12 -> V_16 . V_115 ) {
V_59 -> V_68 = 0 ;
V_59 -> time = 0 ;
V_59 -> V_67 = V_72 -> V_118 . V_67 ;
V_59 -> V_66 = V_72 -> V_118 . V_66 ;
}
F_15 ( V_59 , V_60 , V_12 ) ;
F_48 ( V_72 , stdout ) ;
return 0 ;
}
static void F_57 ( int T_7 V_88 )
{
V_119 = 1 ;
}
static int F_58 ( struct V_108 * T_2 )
{
int V_113 ;
signal ( V_120 , F_57 ) ;
if ( T_2 -> V_121 ) {
T_2 -> T_6 . V_114 = F_45 ;
T_2 -> T_6 . V_116 = F_49 ;
T_2 -> T_6 . exit = F_51 ;
}
if ( T_2 -> V_122 ) {
T_2 -> T_6 . V_117 = F_53 ;
T_2 -> T_6 . V_118 = F_55 ;
}
V_113 = F_59 ( T_2 -> V_20 , & T_2 -> T_6 ) ;
if ( V_95 )
F_6 ( L_48 V_97 L_34 , V_98 ) ;
return V_113 ;
}
static struct V_123 * F_60 ( const char * V_124 ,
struct V_90 * V_125 )
{
struct V_123 * V_126 = malloc ( sizeof( * V_126 ) + strlen ( V_124 ) + 1 ) ;
if ( V_126 != NULL ) {
strcpy ( V_126 -> V_124 , V_124 ) ;
V_126 -> V_125 = V_125 ;
}
return V_126 ;
}
static void F_61 ( struct V_123 * V_126 )
{
F_62 ( & V_126 -> V_127 , & V_128 ) ;
}
static struct V_123 * F_63 ( const char * V_124 )
{
struct V_123 * V_126 ;
F_64 (s, &script_specs, node)
if ( strcasecmp ( V_126 -> V_124 , V_124 ) == 0 )
return V_126 ;
return NULL ;
}
static struct V_123 * F_65 ( const char * V_124 ,
struct V_90 * V_125 )
{
struct V_123 * V_126 = F_63 ( V_124 ) ;
if ( V_126 )
return V_126 ;
V_126 = F_60 ( V_124 , V_125 ) ;
if ( ! V_126 )
return NULL ;
F_61 ( V_126 ) ;
return V_126 ;
}
int F_66 ( const char * V_124 , struct V_90 * V_125 )
{
struct V_123 * V_126 ;
V_126 = F_63 ( V_124 ) ;
if ( V_126 )
return - 1 ;
V_126 = F_65 ( V_124 , V_125 ) ;
if ( ! V_126 )
return - 1 ;
return 0 ;
}
static struct V_90 * F_67 ( const char * V_124 )
{
struct V_123 * V_126 = F_63 ( V_124 ) ;
if ( ! V_126 )
return NULL ;
return V_126 -> V_125 ;
}
static void F_68 ( void )
{
struct V_123 * V_126 ;
fprintf ( V_129 , L_34 ) ;
fprintf ( V_129 , L_49
L_50 ) ;
F_64 (s, &script_specs, node)
fprintf ( V_129 , L_51 , V_126 -> V_124 , V_126 -> V_125 -> V_130 ) ;
fprintf ( V_129 , L_34 ) ;
}
static int F_69 ( const struct V_131 * T_8 V_88 ,
const char * V_10 , int T_9 V_88 )
{
char V_124 [ V_132 ] ;
const char * T_2 , * V_133 ;
int V_134 ;
if ( strcmp ( V_10 , L_52 ) == 0 ) {
F_68 () ;
exit ( 0 ) ;
}
T_2 = strchr ( V_10 , ':' ) ;
if ( T_2 ) {
V_134 = T_2 - V_10 ;
if ( V_134 >= V_132 ) {
fprintf ( V_129 , L_53 ) ;
return - 1 ;
}
strncpy ( V_124 , V_10 , V_134 ) ;
V_124 [ V_134 ] = '\0' ;
V_90 = F_67 ( V_124 ) ;
if ( ! V_90 ) {
fprintf ( V_129 , L_53 ) ;
return - 1 ;
}
T_2 ++ ;
} else {
T_2 = V_10 ;
V_133 = strrchr ( T_2 , '.' ) ;
if ( ! V_133 ) {
fprintf ( V_129 , L_54 ) ;
return - 1 ;
}
V_90 = F_67 ( ++ V_133 ) ;
if ( ! V_90 ) {
fprintf ( V_129 , L_54 ) ;
return - 1 ;
}
}
V_135 = F_70 ( T_2 ) ;
return 0 ;
}
static int F_71 ( const struct V_131 * T_8 V_88 ,
const char * V_136 , int T_9 V_88 )
{
char * V_137 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_138 = 0 ;
char * V_10 = F_70 ( V_136 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_139 ;
V_137 = strchr ( V_10 , ':' ) ;
if ( V_137 ) {
* V_137 = '\0' ;
V_137 ++ ;
if ( ! strcmp ( V_10 , L_55 ) )
type = V_140 ;
else if ( ! strcmp ( V_10 , L_56 ) )
type = V_141 ;
else if ( ! strcmp ( V_10 , L_57 ) )
type = V_54 ;
else if ( ! strcmp ( V_10 , L_58 ) )
type = V_142 ;
else {
fprintf ( V_129 , L_59 ) ;
V_138 = - V_22 ;
goto V_55;
}
if ( V_3 [ type ] . V_4 )
F_72 ( L_60 ,
F_14 ( type ) ) ;
V_3 [ type ] . V_18 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_53 = false ;
} else {
V_137 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_129 ,
L_61 ) ;
V_138 = - V_22 ;
goto V_55;
}
if ( F_1 () )
F_72 ( L_62 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_18 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_53 = true ;
}
}
V_137 = strtok ( V_137 , L_63 ) ;
while ( V_137 ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_137 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 ) {
fprintf ( V_129 , L_64 ) ;
V_138 = - V_22 ;
goto V_55;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_143 & V_9 [ V_7 ] . V_6 ) {
F_72 ( L_65 ,
V_9 [ V_7 ] . V_10 , F_14 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_143 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_129 , L_66 ,
V_9 [ V_7 ] . V_10 , F_14 ( type ) ) ;
V_138 = - V_22 ;
goto V_55;
}
V_3 [ type ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
V_137 = strtok ( NULL , L_63 ) ;
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_18 == 0 ) {
F_7 ( L_67
L_68 , F_14 ( type ) ) ;
}
}
V_55:
free ( V_10 ) ;
return V_138 ;
}
static int F_73 ( const char * V_144 , const struct V_145 * V_146 )
{
char V_147 [ V_132 ] ;
struct V_148 V_149 ;
sprintf ( V_147 , L_69 , V_144 , V_146 -> V_150 ) ;
if ( V_148 ( V_147 , & V_149 ) )
return 0 ;
return F_74 ( V_149 . V_151 ) ;
}
static struct V_152 * F_75 ( const char * V_130 )
{
struct V_152 * V_126 = F_76 ( sizeof( * V_126 ) ) ;
if ( V_126 != NULL && V_130 )
V_126 -> V_130 = F_70 ( V_130 ) ;
return V_126 ;
}
static void F_77 ( struct V_152 * V_126 )
{
F_78 ( & V_126 -> V_130 ) ;
F_78 ( & V_126 -> V_153 ) ;
F_78 ( & V_126 -> args ) ;
free ( V_126 ) ;
}
static void F_79 ( struct V_152 * V_126 )
{
F_62 ( & V_126 -> V_127 , & V_154 ) ;
}
static struct V_152 * F_80 ( const char * V_130 )
{
struct V_152 * V_126 ;
F_64 (s, &script_descs, node)
if ( strcasecmp ( V_126 -> V_130 , V_130 ) == 0 )
return V_126 ;
return NULL ;
}
static struct V_152 * F_81 ( const char * V_130 )
{
struct V_152 * V_126 = F_80 ( V_130 ) ;
if ( V_126 )
return V_126 ;
V_126 = F_75 ( V_130 ) ;
if ( ! V_126 )
goto V_155;
F_79 ( V_126 ) ;
return V_126 ;
V_155:
F_77 ( V_126 ) ;
return NULL ;
}
static const char * F_82 ( const char * V_10 , const char * V_156 )
{
T_10 V_157 = strlen ( V_156 ) ;
const char * V_158 = V_10 ;
if ( strlen ( V_10 ) > V_157 ) {
V_158 = V_10 + strlen ( V_10 ) - V_157 ;
if ( ! strncmp ( V_158 , V_156 , V_157 ) )
return V_158 ;
}
return NULL ;
}
static int F_83 ( struct V_152 * V_159 , const char * V_160 )
{
char line [ V_161 ] , * V_158 ;
T_11 * V_162 ;
V_162 = fopen ( V_160 , L_70 ) ;
if ( ! V_162 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_162 ) ) {
V_158 = F_84 ( line ) ;
if ( strlen ( V_158 ) == 0 )
continue;
if ( * V_158 != '#' )
continue;
V_158 ++ ;
if ( strlen ( V_158 ) && * V_158 == '!' )
continue;
V_158 = F_84 ( V_158 ) ;
if ( strlen ( V_158 ) && V_158 [ strlen ( V_158 ) - 1 ] == '\n' )
V_158 [ strlen ( V_158 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_158 , L_71 , strlen ( L_71 ) ) ) {
V_158 += strlen ( L_71 ) ;
V_159 -> V_153 = F_70 ( F_84 ( V_158 ) ) ;
continue;
}
if ( ! strncmp ( V_158 , L_72 , strlen ( L_72 ) ) ) {
V_158 += strlen ( L_72 ) ;
V_159 -> args = F_70 ( F_84 ( V_158 ) ) ;
continue;
}
}
fclose ( V_162 ) ;
return 0 ;
}
static char * F_85 ( struct V_145 * V_163 , const char * V_156 )
{
char * V_164 , * V_10 ;
V_164 = F_70 ( V_163 -> V_150 ) ;
if ( ! V_164 )
return NULL ;
V_10 = ( char * ) F_82 ( V_164 , V_156 ) ;
if ( ! V_10 ) {
free ( V_164 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_164 ;
}
static int F_86 ( const struct V_131 * T_8 V_88 ,
const char * V_126 V_88 ,
int T_9 V_88 )
{
struct V_145 * V_165 , * V_166 , V_163 , V_167 ;
char V_168 [ V_169 ] ;
T_12 * V_170 , * V_171 ;
char V_172 [ V_169 ] ;
char V_173 [ V_169 ] ;
struct V_152 * V_159 ;
char V_174 [ V_161 ] ;
char * V_164 ;
snprintf ( V_168 , V_169 , L_73 , F_87 () ) ;
V_170 = F_88 ( V_168 ) ;
if ( ! V_170 )
return - 1 ;
F_89 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_173 , V_169 , L_74 , V_168 ,
V_167 . V_150 ) ;
V_171 = F_88 ( V_173 ) ;
if ( ! V_171 )
continue;
F_90 (lang_path, lang_dir, script_dirent, script_next) {
V_164 = F_85 ( & V_163 , V_175 ) ;
if ( V_164 ) {
V_159 = F_81 ( V_164 ) ;
snprintf ( V_172 , V_169 , L_69 ,
V_173 , V_163 . V_150 ) ;
F_83 ( V_159 , V_172 ) ;
free ( V_164 ) ;
}
}
}
fprintf ( stdout , L_75 ) ;
F_64 (desc, &script_descs, node) {
sprintf ( V_174 , L_76 , V_159 -> V_130 ,
V_159 -> args ? V_159 -> args : L_1 ) ;
fprintf ( stdout , L_77 , V_174 ,
V_159 -> V_153 ? V_159 -> V_153 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_91 ( char * V_176 , char * V_177 ,
struct V_19 * V_20 )
{
char V_160 [ V_169 ] , V_17 [ 128 ] ;
char line [ V_161 ] , * V_158 ;
struct V_11 * V_111 ;
int V_178 , V_134 ;
T_11 * V_162 ;
sprintf ( V_160 , L_78 , V_176 , V_177 ) ;
V_162 = fopen ( V_160 , L_70 ) ;
if ( ! V_162 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_162 ) ) {
V_158 = F_84 ( line ) ;
if ( * V_158 == '#' )
continue;
while ( strlen ( V_158 ) ) {
V_158 = strstr ( V_158 , L_79 ) ;
if ( ! V_158 )
break;
V_158 += 2 ;
V_158 = F_84 ( V_158 ) ;
V_134 = strcspn ( V_158 , L_80 ) ;
if ( ! V_134 )
break;
snprintf ( V_17 , V_134 + 1 , L_81 , V_158 ) ;
V_178 = 0 ;
F_44 (session->evlist, pos) {
if ( ! strcmp ( F_5 ( V_111 ) , V_17 ) ) {
V_178 = 1 ;
break;
}
}
if ( ! V_178 ) {
fclose ( V_162 ) ;
return - 1 ;
}
}
}
fclose ( V_162 ) ;
return 0 ;
}
int F_92 ( char * * V_179 , char * * V_180 )
{
struct V_145 * V_165 , * V_166 , V_163 , V_167 ;
char V_168 [ V_169 ] , V_173 [ V_169 ] ;
T_12 * V_170 , * V_171 ;
struct V_19 * V_20 ;
struct V_181 V_182 = {
. V_147 = V_183 ,
. V_184 = V_185 ,
} ;
char * V_186 ;
int V_7 = 0 ;
V_20 = F_93 ( & V_182 , false , NULL ) ;
if ( ! V_20 )
return - 1 ;
snprintf ( V_168 , V_169 , L_73 , F_87 () ) ;
V_170 = F_88 ( V_168 ) ;
if ( ! V_170 ) {
F_94 ( V_20 ) ;
return - 1 ;
}
F_89 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_173 , V_169 , L_69 , V_168 ,
V_167 . V_150 ) ;
#ifdef F_95
if ( strstr ( V_173 , L_82 ) )
continue;
#endif
#ifdef F_96
if ( strstr ( V_173 , L_83 ) )
continue;
#endif
V_171 = F_88 ( V_173 ) ;
if ( ! V_171 )
continue;
F_90 (lang_path, lang_dir, script_dirent, script_next) {
if ( strstr ( V_163 . V_150 , L_84 ) )
continue;
sprintf ( V_180 [ V_7 ] , L_69 , V_173 ,
V_163 . V_150 ) ;
V_186 = strchr ( V_163 . V_150 , '.' ) ;
snprintf ( V_179 [ V_7 ] ,
( V_186 - V_163 . V_150 ) + 1 ,
L_81 , V_163 . V_150 ) ;
if ( F_91 ( V_173 ,
V_179 [ V_7 ] , V_20 ) )
continue;
V_7 ++ ;
}
F_97 ( V_171 ) ;
}
F_97 ( V_170 ) ;
F_94 ( V_20 ) ;
return V_7 ;
}
static char * F_98 ( const char * V_164 , const char * V_156 )
{
struct V_145 * V_165 , * V_166 , V_163 , V_167 ;
char V_168 [ V_169 ] ;
char V_172 [ V_169 ] ;
T_12 * V_170 , * V_171 ;
char V_173 [ V_169 ] ;
char * V_187 ;
snprintf ( V_168 , V_169 , L_73 , F_87 () ) ;
V_170 = F_88 ( V_168 ) ;
if ( ! V_170 )
return NULL ;
F_89 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_173 , V_169 , L_74 , V_168 ,
V_167 . V_150 ) ;
V_171 = F_88 ( V_173 ) ;
if ( ! V_171 )
continue;
F_90 (lang_path, lang_dir, script_dirent, script_next) {
V_187 = F_85 ( & V_163 , V_156 ) ;
if ( V_187 && ! strcmp ( V_164 , V_187 ) ) {
free ( V_187 ) ;
F_97 ( V_171 ) ;
F_97 ( V_170 ) ;
snprintf ( V_172 , V_169 , L_69 ,
V_173 , V_163 . V_150 ) ;
return F_70 ( V_172 ) ;
}
free ( V_187 ) ;
}
F_97 ( V_171 ) ;
}
F_97 ( V_170 ) ;
return NULL ;
}
static bool F_99 ( const char * V_172 )
{
return F_82 ( V_172 , L_85 ) == NULL ? false : true ;
}
static int F_100 ( char * V_172 )
{
struct V_152 * V_159 ;
int V_188 = 0 ;
char * V_158 ;
V_159 = F_75 ( NULL ) ;
if ( F_83 ( V_159 , V_172 ) )
goto V_55;
if ( ! V_159 -> args )
goto V_55;
for ( V_158 = V_159 -> args ; * V_158 ; V_158 ++ )
if ( * V_158 == '<' )
V_188 ++ ;
V_55:
F_77 ( V_159 ) ;
return V_188 ;
}
static int F_101 ( int T_3 , const char * * T_4 )
{
char * * V_189 = malloc ( sizeof( const char * ) * T_3 ) ;
if ( ! V_189 ) {
F_6 ( L_86 ) ;
return - 1 ;
}
memcpy ( V_189 , T_4 , sizeof( const char * ) * T_3 ) ;
T_3 = F_102 ( T_3 , ( const char * * ) V_189 , V_190 ,
NULL , V_191 ) ;
free ( V_189 ) ;
V_192 = ( T_3 == 0 ) ;
return 0 ;
}
int F_103 ( int T_3 , const char * * T_4 , const char * T_13 V_88 )
{
bool V_193 = false ;
bool V_94 = false ;
bool V_194 = false ;
char * V_195 = NULL ;
char * V_196 = NULL ;
struct V_19 * V_20 ;
char * V_172 = NULL ;
const char * * V_189 ;
int V_7 , V_1 , V_112 ;
struct V_108 T_2 = {
. T_6 = {
. V_59 = F_36 ,
. V_117 = F_54 ,
. V_118 = F_56 ,
. V_114 = F_47 ,
. exit = F_52 ,
. V_116 = F_50 ,
. V_16 = F_40 ,
. V_197 = V_198 ,
. V_199 = V_200 ,
. V_201 = true ,
. V_202 = true ,
} ,
} ;
const struct V_131 V_203 [] = {
F_104 ( 'D' , L_87 , & V_204 ,
L_88 ) ,
F_105 ( 'v' , L_89 , & V_205 ,
L_90 ) ,
F_104 ( 'L' , L_91 , & V_65 ,
L_92 ) ,
F_106 ( 'l' , L_93 , NULL , NULL , L_94 ,
F_86 ) ,
F_107 ( 's' , L_95 , NULL , L_96 ,
L_97 ,
F_69 ) ,
F_108 ( 'g' , L_98 , & V_206 , L_52 ,
L_99 ) ,
F_108 ( 'i' , L_100 , & V_183 , L_101 , L_102 ) ,
F_104 ( 'd' , L_103 , & V_95 ,
L_104 ) ,
F_104 ( 0 , L_105 , & V_94 , L_106 ) ,
F_104 ( 0 , L_107 , & V_194 , L_108 ) ,
F_108 ( 'k' , L_109 , & V_28 . V_207 ,
L_101 , L_110 ) ,
F_108 ( 0 , L_111 , & V_28 . V_208 ,
L_101 , L_112 ) ,
F_104 ( 'G' , L_113 , & V_26 ,
L_114 ) ,
F_108 ( 0 , L_115 , & V_28 . V_209 , L_116 ,
L_117 ) ,
F_107 ( 'f' , L_118 , NULL , L_119 ,
L_120
L_121
L_122
L_123 , F_71 ) ,
F_104 ( 'a' , L_124 , & V_192 ,
L_125 ) ,
F_108 ( 'S' , L_126 , & V_28 . V_210 , L_127 ,
L_128 ) ,
F_108 ( 'C' , L_129 , & V_100 , L_129 , L_130 ) ,
F_108 ( 'c' , L_131 , & V_28 . V_211 , L_132 ,
L_133 ) ,
F_104 ( 'I' , L_134 , & V_193 ,
L_135 ) ,
F_104 ( '\0' , L_136 , & V_28 . V_212 ,
L_137 ) ,
F_104 ( '\0' , L_138 , & T_2 . V_121 ,
L_139 ) ,
F_104 ( '\0' , L_140 , & T_2 . V_122 ,
L_141 ) ,
F_109 ()
} ;
const char * const V_213 [] = {
L_142 ,
L_143 ,
L_144 ,
L_145 ,
L_146 ,
NULL
} ;
struct V_181 V_182 = {
. V_184 = V_185 ,
} ;
F_32 () ;
T_3 = F_102 ( T_3 , T_4 , V_203 , V_213 ,
V_191 ) ;
V_182 . V_147 = V_183 ;
if ( T_3 > 1 && ! strncmp ( T_4 [ 0 ] , L_147 , strlen ( L_147 ) ) ) {
V_195 = F_98 ( T_4 [ 1 ] , V_214 ) ;
if ( ! V_195 )
return F_110 ( T_3 , T_4 , NULL ) ;
}
if ( T_3 > 1 && ! strncmp ( T_4 [ 0 ] , L_148 , strlen ( L_148 ) ) ) {
V_196 = F_98 ( T_4 [ 1 ] , V_175 ) ;
if ( ! V_196 ) {
fprintf ( V_129 ,
L_149
L_150 ) ;
return - 1 ;
}
}
F_111 ( F_87 () ) ;
if ( T_3 && ! V_135 && ! V_195 && ! V_196 ) {
int V_215 [ 2 ] ;
int V_216 ;
T_14 V_66 ;
V_195 = F_98 ( T_4 [ 0 ] , V_214 ) ;
V_196 = F_98 ( T_4 [ 0 ] , V_175 ) ;
if ( ! V_195 && ! V_196 ) {
fprintf ( V_129 , L_151
L_152 , T_4 [ 0 ] ) ;
F_112 ( V_213 , V_203 ) ;
}
if ( F_99 ( T_4 [ 0 ] ) ) {
V_216 = T_3 - 1 ;
} else {
int V_217 ;
V_216 = F_100 ( V_196 ) ;
V_217 = ( T_3 - 1 ) - V_216 ;
if ( V_217 < 0 ) {
fprintf ( V_129 , L_153
L_154
L_155 , T_4 [ 0 ] ) ;
F_112 ( V_213 , V_203 ) ;
}
}
if ( F_113 ( V_215 ) < 0 ) {
perror ( L_156 ) ;
return - 1 ;
}
V_66 = V_116 () ;
if ( V_66 < 0 ) {
perror ( L_157 ) ;
return - 1 ;
}
if ( ! V_66 ) {
V_1 = 0 ;
F_114 ( V_215 [ 1 ] , 1 ) ;
F_115 ( V_215 [ 0 ] ) ;
if ( F_99 ( T_4 [ 0 ] ) ) {
V_192 = true ;
} else if ( ! V_192 ) {
if ( F_101 ( T_3 - V_216 , & T_4 [ V_216 ] ) != 0 ) {
V_112 = - 1 ;
goto V_55;
}
}
V_189 = malloc ( ( T_3 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_189 ) {
F_6 ( L_86 ) ;
V_112 = - V_139 ;
goto V_55;
}
V_189 [ V_1 ++ ] = L_158 ;
V_189 [ V_1 ++ ] = V_195 ;
if ( V_192 )
V_189 [ V_1 ++ ] = L_159 ;
V_189 [ V_1 ++ ] = L_160 ;
V_189 [ V_1 ++ ] = L_161 ;
V_189 [ V_1 ++ ] = L_162 ;
for ( V_7 = V_216 + 1 ; V_7 < T_3 ; V_7 ++ )
V_189 [ V_1 ++ ] = T_4 [ V_7 ] ;
V_189 [ V_1 ++ ] = NULL ;
F_116 ( L_158 , ( char * * ) V_189 ) ;
free ( V_189 ) ;
exit ( - 1 ) ;
}
F_114 ( V_215 [ 0 ] , 0 ) ;
F_115 ( V_215 [ 1 ] ) ;
V_189 = malloc ( ( T_3 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_189 ) {
F_6 ( L_86 ) ;
V_112 = - V_139 ;
goto V_55;
}
V_1 = 0 ;
V_189 [ V_1 ++ ] = L_158 ;
V_189 [ V_1 ++ ] = V_196 ;
for ( V_7 = 1 ; V_7 < V_216 + 1 ; V_7 ++ )
V_189 [ V_1 ++ ] = T_4 [ V_7 ] ;
V_189 [ V_1 ++ ] = L_163 ;
V_189 [ V_1 ++ ] = L_162 ;
V_189 [ V_1 ++ ] = NULL ;
F_116 ( L_158 , ( char * * ) V_189 ) ;
free ( V_189 ) ;
exit ( - 1 ) ;
}
if ( V_195 )
V_172 = V_195 ;
if ( V_196 )
V_172 = V_196 ;
if ( V_172 ) {
V_1 = 0 ;
if ( ! V_195 )
V_192 = false ;
else if ( ! V_192 ) {
if ( F_101 ( T_3 - 1 , & T_4 [ 1 ] ) != 0 ) {
V_112 = - 1 ;
goto V_55;
}
}
V_189 = malloc ( ( T_3 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_189 ) {
F_6 ( L_86 ) ;
V_112 = - V_139 ;
goto V_55;
}
V_189 [ V_1 ++ ] = L_158 ;
V_189 [ V_1 ++ ] = V_172 ;
if ( V_192 )
V_189 [ V_1 ++ ] = L_159 ;
for ( V_7 = 2 ; V_7 < T_3 ; V_7 ++ )
V_189 [ V_1 ++ ] = T_4 [ V_7 ] ;
V_189 [ V_1 ++ ] = NULL ;
F_116 ( L_158 , ( char * * ) V_189 ) ;
free ( V_189 ) ;
exit ( - 1 ) ;
}
if ( F_117 () < 0 )
return - 1 ;
if ( ! V_135 )
F_118 () ;
V_20 = F_93 ( & V_182 , false , & T_2 . T_6 ) ;
if ( V_20 == NULL )
return - V_139 ;
if ( V_94 || V_194 ) {
F_119 ( V_20 , stdout , V_193 ) ;
if ( V_194 )
return 0 ;
}
T_2 . V_20 = V_20 ;
if ( V_100 ) {
if ( F_120 ( V_20 , V_100 , V_101 ) )
return - 1 ;
}
if ( ! V_26 )
V_28 . V_29 = true ;
else
V_28 . V_29 = false ;
if ( V_206 ) {
struct V_148 V_218 ;
int V_219 ;
if ( F_1 () ) {
fprintf ( V_129 ,
L_164 ) ;
return - 1 ;
}
V_219 = F_121 ( V_182 . V_147 , V_220 ) ;
if ( V_219 < 0 ) {
perror ( L_165 ) ;
return - 1 ;
}
V_112 = F_122 ( V_219 , & V_218 ) ;
if ( V_112 < 0 ) {
perror ( L_166 ) ;
return - 1 ;
}
if ( ! V_218 . V_221 ) {
fprintf ( V_129 , L_167 ) ;
return 0 ;
}
V_90 = F_67 ( V_206 ) ;
if ( ! V_90 ) {
fprintf ( V_129 , L_53 ) ;
return - 1 ;
}
V_112 = V_90 -> V_222 ( V_20 -> V_223 . V_89 ,
L_168 ) ;
goto V_55;
}
if ( V_135 ) {
V_112 = V_90 -> V_224 ( V_135 , T_3 , T_4 ) ;
if ( V_112 )
goto V_55;
F_7 ( L_169 , V_135 ) ;
}
V_112 = F_12 ( V_20 ) ;
if ( V_112 < 0 )
goto V_55;
V_112 = F_58 ( & T_2 ) ;
F_94 ( V_20 ) ;
F_35 () ;
V_55:
return V_112 ;
}
