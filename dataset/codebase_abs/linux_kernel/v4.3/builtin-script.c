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
if ( F_11 ( V_49 ) &&
F_8 ( V_12 , V_50 , L_21 ,
V_51 ) )
return - V_25 ;
return 0 ;
}
static void F_13 ( struct V_16 * V_17 )
{
unsigned int type = V_17 -> type ;
V_3 [ type ] . V_52 = 0 ;
if ( F_11 ( V_26 ) )
V_3 [ type ] . V_52 |= V_53 ;
if ( F_11 ( V_32 ) )
V_3 [ type ] . V_52 |= V_54 ;
if ( F_11 ( V_34 ) )
V_3 [ type ] . V_52 |= V_55 ;
if ( F_11 ( V_33 ) )
V_3 [ type ] . V_52 |= V_56 ;
if ( F_11 ( V_35 ) )
V_3 [ type ] . V_52 |= V_57 ;
}
static int F_14 ( struct V_20 * V_21 )
{
int V_1 ;
struct V_11 * V_12 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_12 = F_15 ( V_21 , V_1 ) ;
if ( ! V_12 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_58 ) {
F_6 ( L_22
L_23 ,
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
if ( ! V_59 ) {
bool V_60 = false ;
F_17 (session->evlist, evsel) {
if ( V_12 -> V_17 . V_13 & V_61 ) {
V_60 = true ;
break;
}
}
if ( ! V_60 )
V_62 . V_60 = false ;
}
if ( V_62 . V_60 &&
! V_3 [ V_63 ] . V_4 ) {
struct V_16 * V_17 ;
V_1 = V_63 ;
V_12 = F_15 ( V_21 , V_1 ) ;
if ( V_12 == NULL )
goto V_64;
V_17 = & V_12 -> V_17 ;
if ( V_17 -> V_13 & V_61 ) {
V_3 [ V_1 ] . V_19 |= V_28 ;
V_3 [ V_1 ] . V_19 |= V_65 ;
V_3 [ V_1 ] . V_19 |= V_66 ;
F_13 ( V_17 ) ;
}
}
V_64:
return 0 ;
}
static void F_18 ( union V_67 * T_2 V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_71 V_68 ,
struct V_16 * V_17 )
{
struct V_72 * V_73 = & V_70 -> V_74 ;
T_3 V_75 = V_17 -> V_76 ;
unsigned V_7 = 0 , V_77 ;
if ( ! V_73 )
return;
F_19 (r, (unsigned long *) &mask, sizeof(mask) * 8 ) {
T_1 V_78 = V_73 -> V_73 [ V_7 ++ ] ;
printf ( L_24 V_79 L_25 , F_20 ( V_77 ) , V_78 ) ;
}
}
static void F_21 ( struct V_69 * V_70 ,
struct V_71 * V_71 ,
struct V_11 * V_12 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
unsigned long V_80 ;
unsigned long V_81 ;
unsigned long long V_82 ;
if ( F_11 ( V_83 ) ) {
if ( V_84 )
printf ( L_26 , F_22 ( V_71 ) ) ;
else if ( F_11 ( V_26 ) && V_62 . V_60 )
printf ( L_27 , F_22 ( V_71 ) ) ;
else
printf ( L_28 , F_22 ( V_71 ) ) ;
}
if ( F_11 ( V_36 ) && F_11 ( V_37 ) )
printf ( L_29 , V_70 -> V_85 , V_70 -> V_86 ) ;
else if ( F_11 ( V_36 ) )
printf ( L_30 , V_70 -> V_85 ) ;
else if ( F_11 ( V_37 ) )
printf ( L_30 , V_70 -> V_86 ) ;
if ( F_11 ( V_43 ) ) {
if ( V_84 )
printf ( L_31 , V_70 -> V_87 ) ;
else
printf ( L_32 , V_70 -> V_87 ) ;
}
if ( F_11 ( TIME ) ) {
V_82 = V_70 -> time ;
V_80 = V_82 / V_88 ;
V_82 -= V_80 * V_88 ;
V_81 = V_82 / V_89 ;
printf ( L_33 , V_80 , V_81 ) ;
}
}
static void F_23 ( union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_71 * V_71 ,
struct V_16 * V_17 )
{
struct V_90 V_91 ;
printf ( L_34 V_79 , V_70 -> V_92 ) ;
if ( ! F_24 ( V_17 ) )
return;
F_25 ( T_2 , V_70 , V_71 , & V_91 ) ;
if ( F_11 ( V_32 ) ) {
printf ( L_25 ) ;
if ( F_11 ( V_33 ) )
F_26 ( V_91 . V_93 , & V_91 , stdout ) ;
else
F_27 ( V_91 . V_93 , stdout ) ;
}
if ( F_11 ( V_34 ) ) {
printf ( L_35 ) ;
F_28 ( V_91 . V_94 , stdout ) ;
printf ( L_36 ) ;
}
}
static void F_29 ( union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_11 * V_12 ,
struct V_71 * V_71 ,
struct V_90 * V_91 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
bool V_95 = false ;
if ( F_11 ( V_26 ) ) {
unsigned int V_96 = V_3 [ V_17 -> type ] . V_52 ;
if ( V_62 . V_60 && V_70 -> V_97 ) {
printf ( L_37 ) ;
} else {
printf ( L_25 ) ;
if ( V_96 & V_57 ) {
V_95 = true ;
V_96 &= ~ V_57 ;
}
}
F_30 ( V_12 , V_70 , V_91 , V_96 ,
V_98 ) ;
}
if ( F_11 ( V_29 ) ||
( ( V_12 -> V_17 . V_13 & V_30 ) &&
! V_3 [ V_17 -> type ] . V_4 ) ) {
printf ( L_38 ) ;
F_23 ( T_2 , V_70 , V_71 , V_17 ) ;
}
if ( V_95 )
F_31 ( V_91 -> V_94 , V_91 -> V_92 , L_39 , stdout ) ;
printf ( L_37 ) ;
}
static void F_32 ( T_4 V_99 )
{
const char * V_100 = V_101 ;
const int V_102 = strlen ( V_101 ) ;
char V_10 [ 33 ] ;
int V_7 , V_103 = 0 ;
for ( V_7 = 0 ; V_7 < V_102 ; V_7 ++ , V_99 >>= 1 ) {
if ( V_99 & 1 )
V_10 [ V_103 ++ ] = V_100 [ V_7 ] ;
}
for (; V_7 < 32 ; V_7 ++ , V_99 >>= 1 ) {
if ( V_99 & 1 )
V_10 [ V_103 ++ ] = '?' ;
}
V_10 [ V_103 ] = 0 ;
printf ( L_40 , V_10 ) ;
}
static void F_33 ( union V_67 * T_2 , struct V_69 * V_70 ,
struct V_11 * V_12 , struct V_90 * V_91 )
{
struct V_71 * V_71 = V_91 -> V_71 ;
struct V_16 * V_17 = & V_12 -> V_17 ;
if ( V_3 [ V_17 -> type ] . V_19 == 0 )
return;
F_21 ( V_70 , V_71 , V_12 ) ;
if ( F_11 ( V_46 ) )
printf ( L_41 V_104 L_25 , V_70 -> V_105 ) ;
if ( F_11 ( V_106 ) ) {
const char * V_18 = F_5 ( V_12 ) ;
printf ( L_42 , V_18 ? V_18 : L_43 ) ;
}
if ( V_107 )
F_32 ( V_70 -> V_99 ) ;
if ( F_34 ( V_17 ) ) {
F_29 ( T_2 , V_70 , V_12 , V_71 , V_91 ) ;
return;
}
if ( F_11 ( V_24 ) )
F_35 ( V_12 -> V_108 , V_70 -> V_87 ,
V_70 -> V_109 , V_70 -> V_110 ) ;
if ( F_11 ( V_29 ) )
F_23 ( T_2 , V_70 , V_71 , V_17 ) ;
if ( F_11 ( V_26 ) ) {
if ( ! V_62 . V_60 )
printf ( L_25 ) ;
else
printf ( L_37 ) ;
F_30 ( V_12 , V_70 , V_91 ,
V_3 [ V_17 -> type ] . V_52 ,
V_98 ) ;
}
if ( F_11 ( V_49 ) )
F_18 ( T_2 , V_70 , V_71 , V_17 ) ;
printf ( L_37 ) ;
}
static int F_36 ( const char * T_5 V_68 ,
int T_6 V_68 ,
const char * * T_7 V_68 )
{
return 0 ;
}
static int F_37 ( void )
{
return 0 ;
}
static int F_38 ( void )
{
return 0 ;
}
static int F_39 ( struct V_111 * V_111 V_68 ,
const char * T_8 V_68 )
{
return 0 ;
}
static void F_40 ( void )
{
F_41 () ;
F_42 () ;
V_112 = & V_113 ;
}
static int F_43 ( void )
{
return V_112 -> V_114 () ;
}
static int F_44 ( void )
{
F_7 ( L_44 ) ;
return V_112 -> V_115 () ;
}
static int F_45 ( struct V_116 * T_9 V_68 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_11 * V_12 ,
struct V_117 * V_117 )
{
struct V_90 V_91 ;
if ( V_118 ) {
if ( V_70 -> time < V_119 ) {
F_6 ( L_45 V_104
L_46 V_104 L_37 , V_119 ,
V_70 -> time ) ;
V_120 ++ ;
}
V_119 = V_70 -> time ;
return 0 ;
}
if ( F_46 ( T_2 , V_117 , & V_91 , V_70 ) < 0 ) {
F_6 ( L_47 ,
T_2 -> V_22 . type ) ;
return - 1 ;
}
if ( V_91 . V_121 )
goto V_122;
if ( V_123 && ! F_47 ( V_70 -> V_87 , V_124 ) )
goto V_122;
V_112 -> F_33 ( T_2 , V_70 , V_12 , & V_91 ) ;
V_122:
F_48 ( & V_91 ) ;
return 0 ;
}
static int F_49 ( struct V_116 * T_9 , union V_67 * T_2 ,
struct V_125 * * V_126 )
{
struct V_127 * V_128 = F_50 ( T_9 , struct V_127 , T_9 ) ;
struct V_125 * V_129 ;
struct V_11 * V_12 , * V_103 ;
int V_130 ;
V_130 = F_51 ( T_9 , T_2 , V_126 ) ;
if ( V_130 )
return V_130 ;
V_129 = * V_126 ;
V_12 = F_52 ( * V_126 ) ;
if ( V_12 -> V_17 . type >= V_2 )
return 0 ;
F_17 (evlist, pos) {
if ( V_103 -> V_17 . type == V_12 -> V_17 . type && V_103 != V_12 )
return 0 ;
}
F_13 ( & V_12 -> V_17 ) ;
return F_9 ( V_12 , V_128 -> V_21 ) ;
}
static int F_53 ( struct V_116 * T_9 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_117 * V_117 )
{
struct V_71 * V_71 ;
struct V_127 * T_5 = F_50 ( T_9 , struct V_127 , T_9 ) ;
struct V_20 * V_21 = T_5 -> V_21 ;
struct V_11 * V_12 = F_54 ( V_21 -> V_129 , V_70 -> V_131 ) ;
int V_132 = - 1 ;
V_71 = F_55 ( V_117 , T_2 -> V_133 . V_85 , T_2 -> V_133 . V_86 ) ;
if ( V_71 == NULL ) {
F_7 ( L_48 ) ;
return - 1 ;
}
if ( F_56 ( T_9 , T_2 , V_70 , V_117 ) < 0 )
goto V_64;
if ( ! V_12 -> V_17 . V_134 ) {
V_70 -> V_87 = 0 ;
V_70 -> time = 0 ;
V_70 -> V_86 = T_2 -> V_133 . V_86 ;
V_70 -> V_85 = T_2 -> V_133 . V_85 ;
}
F_21 ( V_70 , V_71 , V_12 ) ;
F_57 ( T_2 , stdout ) ;
V_132 = 0 ;
V_64:
F_58 ( V_71 ) ;
return V_132 ;
}
static int F_59 ( struct V_116 * T_9 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_117 * V_117 )
{
struct V_71 * V_71 ;
struct V_127 * T_5 = F_50 ( T_9 , struct V_127 , T_9 ) ;
struct V_20 * V_21 = T_5 -> V_21 ;
struct V_11 * V_12 = F_54 ( V_21 -> V_129 , V_70 -> V_131 ) ;
if ( F_60 ( T_9 , T_2 , V_70 , V_117 ) < 0 )
return - 1 ;
V_71 = F_55 ( V_117 , T_2 -> V_135 . V_85 , T_2 -> V_135 . V_86 ) ;
if ( V_71 == NULL ) {
F_7 ( L_49 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_134 ) {
V_70 -> V_87 = 0 ;
V_70 -> time = T_2 -> V_135 . time ;
V_70 -> V_86 = T_2 -> V_135 . V_86 ;
V_70 -> V_85 = T_2 -> V_135 . V_85 ;
}
F_21 ( V_70 , V_71 , V_12 ) ;
F_57 ( T_2 , stdout ) ;
F_58 ( V_71 ) ;
return 0 ;
}
static int F_61 ( struct V_116 * T_9 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_117 * V_117 )
{
int V_130 = 0 ;
struct V_71 * V_71 ;
struct V_127 * T_5 = F_50 ( T_9 , struct V_127 , T_9 ) ;
struct V_20 * V_21 = T_5 -> V_21 ;
struct V_11 * V_12 = F_54 ( V_21 -> V_129 , V_70 -> V_131 ) ;
V_71 = F_55 ( V_117 , T_2 -> V_135 . V_85 , T_2 -> V_135 . V_86 ) ;
if ( V_71 == NULL ) {
F_7 ( L_50 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_134 ) {
V_70 -> V_87 = 0 ;
V_70 -> time = 0 ;
V_70 -> V_86 = T_2 -> V_135 . V_86 ;
V_70 -> V_85 = T_2 -> V_135 . V_85 ;
}
F_21 ( V_70 , V_71 , V_12 ) ;
F_57 ( T_2 , stdout ) ;
if ( F_62 ( T_9 , T_2 , V_70 , V_117 ) < 0 )
V_130 = - 1 ;
F_58 ( V_71 ) ;
return V_130 ;
}
static int F_63 ( struct V_116 * T_9 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_117 * V_117 )
{
struct V_71 * V_71 ;
struct V_127 * T_5 = F_50 ( T_9 , struct V_127 , T_9 ) ;
struct V_20 * V_21 = T_5 -> V_21 ;
struct V_11 * V_12 = F_54 ( V_21 -> V_129 , V_70 -> V_131 ) ;
if ( F_64 ( T_9 , T_2 , V_70 , V_117 ) < 0 )
return - 1 ;
V_71 = F_55 ( V_117 , T_2 -> V_136 . V_85 , T_2 -> V_136 . V_86 ) ;
if ( V_71 == NULL ) {
F_7 ( L_51 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_134 ) {
V_70 -> V_87 = 0 ;
V_70 -> time = 0 ;
V_70 -> V_86 = T_2 -> V_136 . V_86 ;
V_70 -> V_85 = T_2 -> V_136 . V_85 ;
}
F_21 ( V_70 , V_71 , V_12 ) ;
F_57 ( T_2 , stdout ) ;
F_58 ( V_71 ) ;
return 0 ;
}
static int F_65 ( struct V_116 * T_9 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_117 * V_117 )
{
struct V_71 * V_71 ;
struct V_127 * T_5 = F_50 ( T_9 , struct V_127 , T_9 ) ;
struct V_20 * V_21 = T_5 -> V_21 ;
struct V_11 * V_12 = F_54 ( V_21 -> V_129 , V_70 -> V_131 ) ;
if ( F_66 ( T_9 , T_2 , V_70 , V_117 ) < 0 )
return - 1 ;
V_71 = F_55 ( V_117 , T_2 -> V_137 . V_85 , T_2 -> V_137 . V_86 ) ;
if ( V_71 == NULL ) {
F_7 ( L_52 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_134 ) {
V_70 -> V_87 = 0 ;
V_70 -> time = 0 ;
V_70 -> V_86 = T_2 -> V_137 . V_86 ;
V_70 -> V_85 = T_2 -> V_137 . V_85 ;
}
F_21 ( V_70 , V_71 , V_12 ) ;
F_57 ( T_2 , stdout ) ;
F_58 ( V_71 ) ;
return 0 ;
}
static int F_67 ( struct V_116 * T_9 ,
union V_67 * T_2 ,
struct V_69 * V_70 ,
struct V_117 * V_117 )
{
struct V_71 * V_71 ;
struct V_127 * T_5 = F_50 ( T_9 , struct V_127 , T_9 ) ;
struct V_20 * V_21 = T_5 -> V_21 ;
struct V_11 * V_12 = F_54 ( V_21 -> V_129 , V_70 -> V_131 ) ;
if ( F_68 ( T_9 , T_2 , V_70 , V_117 ) < 0 )
return - 1 ;
V_71 = F_55 ( V_117 , V_70 -> V_85 ,
V_70 -> V_86 ) ;
if ( V_71 == NULL ) {
F_7 ( L_53 ) ;
return - 1 ;
}
F_21 ( V_70 , V_71 , V_12 ) ;
F_57 ( T_2 , stdout ) ;
F_58 ( V_71 ) ;
return 0 ;
}
static void F_69 ( int T_10 V_68 )
{
V_138 = 1 ;
}
static int F_70 ( struct V_127 * T_5 )
{
int V_132 ;
signal ( V_139 , F_69 ) ;
if ( T_5 -> V_140 ) {
T_5 -> T_9 . V_133 = F_53 ;
T_5 -> T_9 . V_135 = F_59 ;
T_5 -> T_9 . exit = F_61 ;
}
if ( T_5 -> V_141 ) {
T_5 -> T_9 . V_136 = F_63 ;
T_5 -> T_9 . V_137 = F_65 ;
}
if ( T_5 -> V_142 )
T_5 -> T_9 . V_143 = F_67 ;
V_132 = F_71 ( T_5 -> V_21 ) ;
if ( V_118 )
F_6 ( L_54 V_104 L_37 , V_120 ) ;
return V_132 ;
}
static struct V_144 * F_72 ( const char * V_145 ,
struct V_112 * V_146 )
{
struct V_144 * V_147 = malloc ( sizeof( * V_147 ) + strlen ( V_145 ) + 1 ) ;
if ( V_147 != NULL ) {
strcpy ( V_147 -> V_145 , V_145 ) ;
V_147 -> V_146 = V_146 ;
}
return V_147 ;
}
static void F_73 ( struct V_144 * V_147 )
{
F_74 ( & V_147 -> V_148 , & V_149 ) ;
}
static struct V_144 * F_75 ( const char * V_145 )
{
struct V_144 * V_147 ;
F_76 (s, &script_specs, node)
if ( strcasecmp ( V_147 -> V_145 , V_145 ) == 0 )
return V_147 ;
return NULL ;
}
static struct V_144 * F_77 ( const char * V_145 ,
struct V_112 * V_146 )
{
struct V_144 * V_147 = F_75 ( V_145 ) ;
if ( V_147 )
return V_147 ;
V_147 = F_72 ( V_145 , V_146 ) ;
if ( ! V_147 )
return NULL ;
F_73 ( V_147 ) ;
return V_147 ;
}
int F_78 ( const char * V_145 , struct V_112 * V_146 )
{
struct V_144 * V_147 ;
V_147 = F_75 ( V_145 ) ;
if ( V_147 )
return - 1 ;
V_147 = F_77 ( V_145 , V_146 ) ;
if ( ! V_147 )
return - 1 ;
return 0 ;
}
static struct V_112 * F_79 ( const char * V_145 )
{
struct V_144 * V_147 = F_75 ( V_145 ) ;
if ( ! V_147 )
return NULL ;
return V_147 -> V_146 ;
}
static void F_80 ( void )
{
struct V_144 * V_147 ;
fprintf ( V_150 , L_37 ) ;
fprintf ( V_150 , L_55
L_56 ) ;
F_76 (s, &script_specs, node)
fprintf ( V_150 , L_57 , V_147 -> V_145 , V_147 -> V_146 -> V_151 ) ;
fprintf ( V_150 , L_37 ) ;
}
static int F_81 ( const struct V_152 * T_11 V_68 ,
const char * V_10 , int T_12 V_68 )
{
char V_145 [ V_153 ] ;
const char * T_5 , * V_154 ;
int V_155 ;
if ( strcmp ( V_10 , L_58 ) == 0 ) {
F_80 () ;
exit ( 0 ) ;
}
T_5 = strchr ( V_10 , ':' ) ;
if ( T_5 ) {
V_155 = T_5 - V_10 ;
if ( V_155 >= V_153 ) {
fprintf ( V_150 , L_59 ) ;
return - 1 ;
}
strncpy ( V_145 , V_10 , V_155 ) ;
V_145 [ V_155 ] = '\0' ;
V_112 = F_79 ( V_145 ) ;
if ( ! V_112 ) {
fprintf ( V_150 , L_59 ) ;
return - 1 ;
}
T_5 ++ ;
} else {
T_5 = V_10 ;
V_154 = strrchr ( T_5 , '.' ) ;
if ( ! V_154 ) {
fprintf ( V_150 , L_60 ) ;
return - 1 ;
}
V_112 = F_79 ( ++ V_154 ) ;
if ( ! V_112 ) {
fprintf ( V_150 , L_60 ) ;
return - 1 ;
}
}
V_156 = F_82 ( T_5 ) ;
return 0 ;
}
static int F_83 ( const struct V_152 * T_11 V_68 ,
const char * V_157 , int T_12 V_68 )
{
char * V_158 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_159 = 0 ;
char * V_10 = F_82 ( V_157 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_160 ;
V_158 = strchr ( V_10 , ':' ) ;
if ( V_158 ) {
* V_158 = '\0' ;
V_158 ++ ;
if ( ! strcmp ( V_10 , L_61 ) )
type = V_161 ;
else if ( ! strcmp ( V_10 , L_62 ) )
type = V_162 ;
else if ( ! strcmp ( V_10 , L_63 ) )
type = V_63 ;
else if ( ! strcmp ( V_10 , L_64 ) )
type = V_163 ;
else {
fprintf ( V_150 , L_65 ) ;
V_159 = - V_25 ;
goto V_64;
}
if ( V_3 [ type ] . V_4 )
F_84 ( L_66 ,
F_16 ( type ) ) ;
V_3 [ type ] . V_19 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_58 = false ;
} else {
V_158 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_150 ,
L_67 ) ;
V_159 = - V_25 ;
goto V_64;
}
if ( F_1 () )
F_84 ( L_68 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_19 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_58 = true ;
}
}
for ( V_158 = strtok ( V_158 , L_69 ) ; V_158 ; V_158 = strtok ( NULL , L_69 ) ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_158 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 && strcmp ( V_158 , L_70 ) == 0 ) {
V_107 = true ;
continue;
}
if ( V_7 == V_8 ) {
fprintf ( V_150 , L_71 ) ;
V_159 = - V_25 ;
goto V_64;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_164 & V_9 [ V_7 ] . V_6 ) {
F_84 ( L_72 ,
V_9 [ V_7 ] . V_10 , F_16 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_164 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_150 , L_73 ,
V_9 [ V_7 ] . V_10 , F_16 ( type ) ) ;
V_159 = - V_25 ;
goto V_64;
}
V_3 [ type ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_19 == 0 ) {
F_7 ( L_74
L_75 , F_16 ( type ) ) ;
}
}
V_64:
free ( V_10 ) ;
return V_159 ;
}
static int F_85 ( const char * V_165 , const struct V_166 * V_167 )
{
char V_168 [ V_153 ] ;
struct V_169 V_170 ;
sprintf ( V_168 , L_76 , V_165 , V_167 -> V_171 ) ;
if ( V_169 ( V_168 , & V_170 ) )
return 0 ;
return F_86 ( V_170 . V_172 ) ;
}
static struct V_173 * F_87 ( const char * V_151 )
{
struct V_173 * V_147 = F_88 ( sizeof( * V_147 ) ) ;
if ( V_147 != NULL && V_151 )
V_147 -> V_151 = F_82 ( V_151 ) ;
return V_147 ;
}
static void F_89 ( struct V_173 * V_147 )
{
F_90 ( & V_147 -> V_151 ) ;
F_90 ( & V_147 -> V_174 ) ;
F_90 ( & V_147 -> args ) ;
free ( V_147 ) ;
}
static void F_91 ( struct V_173 * V_147 )
{
F_74 ( & V_147 -> V_148 , & V_175 ) ;
}
static struct V_173 * F_92 ( const char * V_151 )
{
struct V_173 * V_147 ;
F_76 (s, &script_descs, node)
if ( strcasecmp ( V_147 -> V_151 , V_151 ) == 0 )
return V_147 ;
return NULL ;
}
static struct V_173 * F_93 ( const char * V_151 )
{
struct V_173 * V_147 = F_92 ( V_151 ) ;
if ( V_147 )
return V_147 ;
V_147 = F_87 ( V_151 ) ;
if ( ! V_147 )
goto V_176;
F_91 ( V_147 ) ;
return V_147 ;
V_176:
F_89 ( V_147 ) ;
return NULL ;
}
static const char * F_94 ( const char * V_10 , const char * V_177 )
{
T_13 V_178 = strlen ( V_177 ) ;
const char * V_179 = V_10 ;
if ( strlen ( V_10 ) > V_178 ) {
V_179 = V_10 + strlen ( V_10 ) - V_178 ;
if ( ! strncmp ( V_179 , V_177 , V_178 ) )
return V_179 ;
}
return NULL ;
}
static int F_95 ( struct V_173 * V_180 , const char * V_181 )
{
char line [ V_182 ] , * V_179 ;
T_14 * V_183 ;
V_183 = fopen ( V_181 , L_77 ) ;
if ( ! V_183 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_183 ) ) {
V_179 = F_96 ( line ) ;
if ( strlen ( V_179 ) == 0 )
continue;
if ( * V_179 != '#' )
continue;
V_179 ++ ;
if ( strlen ( V_179 ) && * V_179 == '!' )
continue;
V_179 = F_96 ( V_179 ) ;
if ( strlen ( V_179 ) && V_179 [ strlen ( V_179 ) - 1 ] == '\n' )
V_179 [ strlen ( V_179 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_179 , L_78 , strlen ( L_78 ) ) ) {
V_179 += strlen ( L_78 ) ;
V_180 -> V_174 = F_82 ( F_96 ( V_179 ) ) ;
continue;
}
if ( ! strncmp ( V_179 , L_79 , strlen ( L_79 ) ) ) {
V_179 += strlen ( L_79 ) ;
V_180 -> args = F_82 ( F_96 ( V_179 ) ) ;
continue;
}
}
fclose ( V_183 ) ;
return 0 ;
}
static char * F_97 ( struct V_166 * V_184 , const char * V_177 )
{
char * V_185 , * V_10 ;
V_185 = F_82 ( V_184 -> V_171 ) ;
if ( ! V_185 )
return NULL ;
V_10 = ( char * ) F_94 ( V_185 , V_177 ) ;
if ( ! V_10 ) {
free ( V_185 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_185 ;
}
static int F_98 ( const struct V_152 * T_11 V_68 ,
const char * V_147 V_68 ,
int T_12 V_68 )
{
struct V_166 * V_186 , * V_187 , V_184 , V_188 ;
char V_189 [ V_190 ] ;
T_15 * V_191 , * V_192 ;
char V_193 [ V_190 ] ;
char V_194 [ V_190 ] ;
struct V_173 * V_180 ;
char V_195 [ V_182 ] ;
char * V_185 ;
snprintf ( V_189 , V_190 , L_80 , F_99 () ) ;
V_191 = F_100 ( V_189 ) ;
if ( ! V_191 )
return - 1 ;
F_101 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_194 , V_190 , L_81 , V_189 ,
V_188 . V_171 ) ;
V_192 = F_100 ( V_194 ) ;
if ( ! V_192 )
continue;
F_102 (lang_path, lang_dir, script_dirent, script_next) {
V_185 = F_97 ( & V_184 , V_196 ) ;
if ( V_185 ) {
V_180 = F_93 ( V_185 ) ;
snprintf ( V_193 , V_190 , L_76 ,
V_194 , V_184 . V_171 ) ;
F_95 ( V_180 , V_193 ) ;
free ( V_185 ) ;
}
}
}
fprintf ( stdout , L_82 ) ;
F_76 (desc, &script_descs, node) {
sprintf ( V_195 , L_83 , V_180 -> V_151 ,
V_180 -> args ? V_180 -> args : L_1 ) ;
fprintf ( stdout , L_84 , V_195 ,
V_180 -> V_174 ? V_180 -> V_174 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_103 ( char * V_197 , char * V_198 ,
struct V_20 * V_21 )
{
char V_181 [ V_190 ] , V_18 [ 128 ] ;
char line [ V_182 ] , * V_179 ;
struct V_11 * V_103 ;
int V_199 , V_155 ;
T_14 * V_183 ;
sprintf ( V_181 , L_85 , V_197 , V_198 ) ;
V_183 = fopen ( V_181 , L_77 ) ;
if ( ! V_183 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_183 ) ) {
V_179 = F_96 ( line ) ;
if ( * V_179 == '#' )
continue;
while ( strlen ( V_179 ) ) {
V_179 = strstr ( V_179 , L_86 ) ;
if ( ! V_179 )
break;
V_179 += 2 ;
V_179 = F_96 ( V_179 ) ;
V_155 = strcspn ( V_179 , L_87 ) ;
if ( ! V_155 )
break;
snprintf ( V_18 , V_155 + 1 , L_88 , V_179 ) ;
V_199 = 0 ;
F_17 (session->evlist, pos) {
if ( ! strcmp ( F_5 ( V_103 ) , V_18 ) ) {
V_199 = 1 ;
break;
}
}
if ( ! V_199 ) {
fclose ( V_183 ) ;
return - 1 ;
}
}
}
fclose ( V_183 ) ;
return 0 ;
}
int F_104 ( char * * V_200 , char * * V_201 )
{
struct V_166 * V_186 , * V_187 , V_184 , V_188 ;
char V_189 [ V_190 ] , V_194 [ V_190 ] ;
T_15 * V_191 , * V_192 ;
struct V_20 * V_21 ;
struct V_202 V_203 = {
. V_168 = V_204 ,
. V_205 = V_206 ,
} ;
char * V_207 ;
int V_7 = 0 ;
V_21 = F_105 ( & V_203 , false , NULL ) ;
if ( ! V_21 )
return - 1 ;
snprintf ( V_189 , V_190 , L_80 , F_99 () ) ;
V_191 = F_100 ( V_189 ) ;
if ( ! V_191 ) {
F_106 ( V_21 ) ;
return - 1 ;
}
F_101 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_194 , V_190 , L_76 , V_189 ,
V_188 . V_171 ) ;
#ifdef F_107
if ( strstr ( V_194 , L_89 ) )
continue;
#endif
#ifdef F_108
if ( strstr ( V_194 , L_90 ) )
continue;
#endif
V_192 = F_100 ( V_194 ) ;
if ( ! V_192 )
continue;
F_102 (lang_path, lang_dir, script_dirent, script_next) {
if ( strstr ( V_184 . V_171 , L_91 ) )
continue;
sprintf ( V_201 [ V_7 ] , L_76 , V_194 ,
V_184 . V_171 ) ;
V_207 = strchr ( V_184 . V_171 , '.' ) ;
snprintf ( V_200 [ V_7 ] ,
( V_207 - V_184 . V_171 ) + 1 ,
L_88 , V_184 . V_171 ) ;
if ( F_103 ( V_194 ,
V_200 [ V_7 ] , V_21 ) )
continue;
V_7 ++ ;
}
F_109 ( V_192 ) ;
}
F_109 ( V_191 ) ;
F_106 ( V_21 ) ;
return V_7 ;
}
static char * F_110 ( const char * V_185 , const char * V_177 )
{
struct V_166 * V_186 , * V_187 , V_184 , V_188 ;
char V_189 [ V_190 ] ;
char V_193 [ V_190 ] ;
T_15 * V_191 , * V_192 ;
char V_194 [ V_190 ] ;
char * V_208 ;
snprintf ( V_189 , V_190 , L_80 , F_99 () ) ;
V_191 = F_100 ( V_189 ) ;
if ( ! V_191 )
return NULL ;
F_101 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_194 , V_190 , L_81 , V_189 ,
V_188 . V_171 ) ;
V_192 = F_100 ( V_194 ) ;
if ( ! V_192 )
continue;
F_102 (lang_path, lang_dir, script_dirent, script_next) {
V_208 = F_97 ( & V_184 , V_177 ) ;
if ( V_208 && ! strcmp ( V_185 , V_208 ) ) {
free ( V_208 ) ;
F_109 ( V_192 ) ;
F_109 ( V_191 ) ;
snprintf ( V_193 , V_190 , L_76 ,
V_194 , V_184 . V_171 ) ;
return F_82 ( V_193 ) ;
}
free ( V_208 ) ;
}
F_109 ( V_192 ) ;
}
F_109 ( V_191 ) ;
return NULL ;
}
static bool F_111 ( const char * V_193 )
{
return F_94 ( V_193 , L_92 ) == NULL ? false : true ;
}
static int F_112 ( char * V_193 )
{
struct V_173 * V_180 ;
int V_209 = 0 ;
char * V_179 ;
V_180 = F_87 ( NULL ) ;
if ( F_95 ( V_180 , V_193 ) )
goto V_64;
if ( ! V_180 -> args )
goto V_64;
for ( V_179 = V_180 -> args ; * V_179 ; V_179 ++ )
if ( * V_179 == '<' )
V_209 ++ ;
V_64:
F_89 ( V_180 ) ;
return V_209 ;
}
static int F_113 ( int T_6 , const char * * T_7 )
{
char * * V_210 = malloc ( sizeof( const char * ) * T_6 ) ;
if ( ! V_210 ) {
F_6 ( L_93 ) ;
return - 1 ;
}
memcpy ( V_210 , T_7 , sizeof( const char * ) * T_6 ) ;
T_6 = F_114 ( T_6 , ( const char * * ) V_210 , V_211 ,
NULL , V_212 ) ;
free ( V_210 ) ;
V_213 = ( T_6 == 0 ) ;
return 0 ;
}
static void F_115 ( struct V_127 * T_5 )
{
struct V_20 * V_21 = T_5 -> V_21 ;
T_1 V_13 = F_116 ( V_21 -> V_129 ) ;
if ( V_62 . V_60 || V_62 . V_214 ) {
if ( ( V_13 & V_215 ) &&
( V_13 & V_216 ) )
V_217 . V_218 = V_219 ;
else if ( V_13 & V_220 )
V_217 . V_218 = V_221 ;
else
V_217 . V_218 = V_222 ;
}
}
int F_117 ( int T_6 , const char * * T_7 , const char * T_16 V_68 )
{
bool V_223 = false ;
bool V_22 = false ;
bool V_224 = false ;
bool V_225 = false ;
char * V_226 = NULL ;
char * V_227 = NULL ;
struct V_20 * V_21 ;
struct V_228 V_228 = { . V_229 = false , } ;
char * V_193 = NULL ;
const char * * V_210 ;
int V_7 , V_1 , V_130 = 0 ;
struct V_127 T_5 = {
. T_9 = {
. V_70 = F_45 ,
. V_136 = F_64 ,
. V_137 = F_66 ,
. V_133 = F_56 ,
. exit = F_62 ,
. V_135 = F_60 ,
. V_17 = F_49 ,
. V_230 = V_231 ,
. V_232 = V_233 ,
. V_234 = V_235 ,
. V_236 = V_237 ,
. V_238 = V_239 ,
. V_240 = V_241 ,
. V_242 = true ,
. V_243 = true ,
} ,
} ;
struct V_202 V_203 = {
. V_205 = V_206 ,
} ;
const struct V_152 V_244 [] = {
F_118 ( 'D' , L_94 , & V_245 ,
L_95 ) ,
F_119 ( 'v' , L_96 , & V_246 ,
L_97 ) ,
F_118 ( 'L' , L_98 , & V_84 ,
L_99 ) ,
F_120 ( 'l' , L_100 , NULL , NULL , L_101 ,
F_98 ) ,
F_121 ( 's' , L_102 , NULL , L_103 ,
L_104 ,
F_81 ) ,
F_122 ( 'g' , L_105 , & V_247 , L_58 ,
L_106 ) ,
F_122 ( 'i' , L_107 , & V_204 , L_108 , L_109 ) ,
F_118 ( 'd' , L_110 , & V_118 ,
L_111 ) ,
F_118 ( 0 , L_112 , & V_22 , L_113 ) ,
F_118 ( 0 , L_114 , & V_224 , L_115 ) ,
F_122 ( 'k' , L_116 , & V_62 . V_248 ,
L_108 , L_117 ) ,
F_122 ( 0 , L_118 , & V_62 . V_249 ,
L_108 , L_119 ) ,
F_118 ( 'G' , L_120 , & V_59 ,
L_121 ) ,
F_122 ( 0 , L_122 , & V_62 . V_250 , L_123 ,
L_124 ) ,
F_121 ( 'F' , L_125 , NULL , L_126 ,
L_127
L_128
L_129
L_130 , F_83 ) ,
F_118 ( 'a' , L_131 , & V_213 ,
L_132 ) ,
F_122 ( 'S' , L_133 , & V_62 . V_251 , L_134 ,
L_135 ) ,
F_122 ( 'C' , L_136 , & V_123 , L_136 , L_137 ) ,
F_122 ( 'c' , L_138 , & V_62 . V_252 , L_139 ,
L_140 ) ,
F_122 ( 0 , L_141 , & V_62 . V_253 , L_142 ,
L_143 ) ,
F_122 ( 0 , L_144 , & V_62 . V_254 , L_145 ,
L_146 ) ,
F_118 ( 'I' , L_147 , & V_223 ,
L_148 ) ,
F_118 ( '\0' , L_149 , & V_62 . V_255 ,
L_150 ) ,
F_118 ( '\0' , L_151 , & T_5 . V_140 ,
L_152 ) ,
F_118 ( '\0' , L_153 , & T_5 . V_141 ,
L_154 ) ,
F_118 ( '\0' , L_155 , & T_5 . V_142 ,
L_156 ) ,
F_118 ( 'f' , L_157 , & V_203 . V_256 , L_158 ) ,
F_123 ( 0 , L_159 , & V_228 , NULL , L_160 ,
L_161 ,
V_257 ) ,
F_118 ( 0 , L_162 , & V_258 ,
L_163 ) ,
F_118 ( 0 , L_164 , & V_62 . V_259 ,
L_165 ) ,
F_118 ( 0 , L_166 , & V_62 . V_260 ,
L_167 ) ,
F_124 ()
} ;
const char * const V_261 [] = { L_168 , L_169 , NULL } ;
const char * V_262 [] = {
L_170 ,
L_171 ,
L_172 ,
L_173 ,
L_174 ,
NULL
} ;
F_40 () ;
T_6 = F_125 ( T_6 , T_7 , V_244 , V_261 , V_262 ,
V_212 ) ;
V_203 . V_168 = V_204 ;
if ( T_6 > 1 && ! strncmp ( T_7 [ 0 ] , L_175 , strlen ( L_175 ) ) ) {
V_226 = F_110 ( T_7 [ 1 ] , V_263 ) ;
if ( ! V_226 )
return F_126 ( T_6 , T_7 , NULL ) ;
}
if ( T_6 > 1 && ! strncmp ( T_7 [ 0 ] , L_176 , strlen ( L_176 ) ) ) {
V_227 = F_110 ( T_7 [ 1 ] , V_196 ) ;
if ( ! V_227 ) {
fprintf ( V_150 ,
L_177
L_178 ) ;
return - 1 ;
}
}
F_127 ( F_99 () ) ;
if ( T_6 && ! V_156 && ! V_226 && ! V_227 ) {
int V_264 [ 2 ] ;
int V_265 ;
T_17 V_85 ;
V_226 = F_110 ( T_7 [ 0 ] , V_263 ) ;
V_227 = F_110 ( T_7 [ 0 ] , V_196 ) ;
if ( ! V_226 && ! V_227 ) {
fprintf ( V_150 , L_179
L_180 , T_7 [ 0 ] ) ;
F_128 ( V_262 , V_244 ) ;
}
if ( F_111 ( T_7 [ 0 ] ) ) {
V_265 = T_6 - 1 ;
} else {
int V_266 ;
V_265 = F_112 ( V_227 ) ;
V_266 = ( T_6 - 1 ) - V_265 ;
if ( V_266 < 0 ) {
fprintf ( V_150 , L_181
L_182
L_183 , T_7 [ 0 ] ) ;
F_128 ( V_262 , V_244 ) ;
}
}
if ( F_129 ( V_264 ) < 0 ) {
perror ( L_184 ) ;
return - 1 ;
}
V_85 = V_135 () ;
if ( V_85 < 0 ) {
perror ( L_185 ) ;
return - 1 ;
}
if ( ! V_85 ) {
V_1 = 0 ;
F_130 ( V_264 [ 1 ] , 1 ) ;
F_131 ( V_264 [ 0 ] ) ;
if ( F_111 ( T_7 [ 0 ] ) ) {
V_213 = true ;
} else if ( ! V_213 ) {
if ( F_113 ( T_6 - V_265 , & T_7 [ V_265 ] ) != 0 ) {
V_130 = - 1 ;
goto V_64;
}
}
V_210 = malloc ( ( T_6 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_210 ) {
F_6 ( L_93 ) ;
V_130 = - V_160 ;
goto V_64;
}
V_210 [ V_1 ++ ] = L_186 ;
V_210 [ V_1 ++ ] = V_226 ;
if ( V_213 )
V_210 [ V_1 ++ ] = L_187 ;
V_210 [ V_1 ++ ] = L_188 ;
V_210 [ V_1 ++ ] = L_189 ;
V_210 [ V_1 ++ ] = L_190 ;
for ( V_7 = V_265 + 1 ; V_7 < T_6 ; V_7 ++ )
V_210 [ V_1 ++ ] = T_7 [ V_7 ] ;
V_210 [ V_1 ++ ] = NULL ;
F_132 ( L_186 , ( char * * ) V_210 ) ;
free ( V_210 ) ;
exit ( - 1 ) ;
}
F_130 ( V_264 [ 0 ] , 0 ) ;
F_131 ( V_264 [ 1 ] ) ;
V_210 = malloc ( ( T_6 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_210 ) {
F_6 ( L_93 ) ;
V_130 = - V_160 ;
goto V_64;
}
V_1 = 0 ;
V_210 [ V_1 ++ ] = L_186 ;
V_210 [ V_1 ++ ] = V_227 ;
for ( V_7 = 1 ; V_7 < V_265 + 1 ; V_7 ++ )
V_210 [ V_1 ++ ] = T_7 [ V_7 ] ;
V_210 [ V_1 ++ ] = L_191 ;
V_210 [ V_1 ++ ] = L_190 ;
V_210 [ V_1 ++ ] = NULL ;
F_132 ( L_186 , ( char * * ) V_210 ) ;
free ( V_210 ) ;
exit ( - 1 ) ;
}
if ( V_226 )
V_193 = V_226 ;
if ( V_227 )
V_193 = V_227 ;
if ( V_193 ) {
V_1 = 0 ;
if ( ! V_226 )
V_213 = false ;
else if ( ! V_213 ) {
if ( F_113 ( T_6 - 1 , & T_7 [ 1 ] ) != 0 ) {
V_130 = - 1 ;
goto V_64;
}
}
V_210 = malloc ( ( T_6 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_210 ) {
F_6 ( L_93 ) ;
V_130 = - V_160 ;
goto V_64;
}
V_210 [ V_1 ++ ] = L_186 ;
V_210 [ V_1 ++ ] = V_193 ;
if ( V_213 )
V_210 [ V_1 ++ ] = L_187 ;
for ( V_7 = 2 ; V_7 < T_6 ; V_7 ++ )
V_210 [ V_1 ++ ] = T_7 [ V_7 ] ;
V_210 [ V_1 ++ ] = NULL ;
F_132 ( L_186 , ( char * * ) V_210 ) ;
free ( V_210 ) ;
exit ( - 1 ) ;
}
if ( ! V_156 )
F_133 () ;
V_21 = F_105 ( & V_203 , false , & T_5 . T_9 ) ;
if ( V_21 == NULL )
return - 1 ;
if ( V_22 || V_224 ) {
F_134 ( V_21 , stdout , V_223 ) ;
if ( V_224 )
goto V_267;
}
if ( F_135 ( & V_21 -> V_22 . V_268 ) < 0 )
goto V_267;
T_5 . V_21 = V_21 ;
F_115 ( & T_5 ) ;
V_21 -> V_228 = & V_228 ;
if ( V_123 ) {
V_130 = F_136 ( V_21 , V_123 , V_124 ) ;
if ( V_130 < 0 )
goto V_267;
}
if ( ! V_59 )
V_62 . V_60 = true ;
else
V_62 . V_60 = false ;
if ( V_21 -> V_269 . V_111 &&
F_137 ( V_21 -> V_269 . V_111 ,
V_270 ,
& V_21 -> V_271 . V_272 ) < 0 ) {
F_6 ( L_192 , V_273 ) ;
return - 1 ;
}
if ( V_247 ) {
struct V_169 V_274 ;
int V_275 ;
if ( F_1 () ) {
fprintf ( V_150 ,
L_193 ) ;
V_130 = - V_25 ;
goto V_267;
}
V_275 = F_138 ( V_203 . V_168 , V_276 ) ;
if ( V_275 < 0 ) {
V_130 = - V_277 ;
perror ( L_194 ) ;
goto V_267;
}
V_130 = F_139 ( V_275 , & V_274 ) ;
if ( V_130 < 0 ) {
perror ( L_195 ) ;
goto V_267;
}
if ( ! V_274 . V_278 ) {
fprintf ( V_150 , L_196 ) ;
goto V_267;
}
V_112 = F_79 ( V_247 ) ;
if ( ! V_112 ) {
fprintf ( V_150 , L_59 ) ;
V_130 = - V_279 ;
goto V_267;
}
V_130 = V_112 -> V_280 ( V_21 -> V_269 . V_111 ,
L_197 ) ;
goto V_267;
}
if ( V_156 ) {
V_130 = V_112 -> V_281 ( V_156 , T_6 , T_7 ) ;
if ( V_130 )
goto V_267;
F_7 ( L_198 , V_156 ) ;
V_225 = true ;
}
V_130 = F_14 ( V_21 ) ;
if ( V_130 < 0 )
goto V_267;
V_130 = F_70 ( & T_5 ) ;
F_43 () ;
V_267:
F_106 ( V_21 ) ;
if ( V_225 )
F_44 () ;
V_64:
return V_130 ;
}
