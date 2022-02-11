void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
V_6 -> V_7 = 0 ;
V_6 -> V_6 = F_2 ( V_2 , V_4 , V_8 ) ;
}
bool F_3 ( struct V_1 * V_2 )
{
return ! strcmp ( V_2 -> V_9 , V_10 ) ;
}
bool F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
if ( F_3 ( V_2 ) ) {
F_1 ( V_2 , V_4 , V_6 ) ;
return true ;
}
return false ;
}
bool F_5 ( struct V_1 * V_2 )
{
return ! strcmp ( V_2 -> V_9 , V_11 ) ;
}
bool F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 V_12 ,
struct V_5 * V_6 V_12 )
{
return F_5 ( V_2 ) ;
}
static const char * F_7 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
T_1 V_17 )
{
while ( V_16 -> V_18 != NULL ) {
if ( V_16 -> V_17 == V_17 )
return V_16 -> V_18 ;
V_16 ++ ;
}
F_8 ( L_1 ,
( unsigned long long ) V_17 , V_14 -> V_19 ) ;
return L_2 ;
}
void F_9 ( struct V_13 * V_14 ,
struct V_5 * V_6 ,
char * V_20 )
{
const char * V_21 = F_7 ( V_14 , V_6 -> V_22 ,
V_6 -> V_6 ) ;
F_10 ( V_20 , V_23 , L_3 , V_21 ) ;
}
static bool F_11 ( struct V_13 * V_14 )
{
struct V_24 * V_25 = V_24 ;
for ( V_25 = V_24 ; V_25 -> V_9 ; V_25 ++ ) {
if ( ! strcmp ( V_25 -> V_9 , V_14 -> V_26 ) ) {
V_14 -> V_25 = V_25 -> V_27 ;
return true ;
}
}
return false ;
}
static void F_12 ( struct V_13 * V_14 )
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ )
F_13 ( & V_14 -> V_30 [ V_28 ] ) ;
}
static void F_14 ( struct V_31 * V_30 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
unsigned int V_28 ;
int V_35 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
V_32 = & V_30 [ V_28 ] ;
F_15 (event, head, hash_entry) {
V_34 -> V_36 . time = 0 ;
F_16 ( & V_34 -> V_36 . V_37 ) ;
for ( V_35 = 0 ; V_35 < V_34 -> V_38 ; ++ V_35 ) {
V_34 -> V_39 [ V_35 ] . time = 0 ;
F_16 ( & V_34 -> V_39 [ V_35 ] . V_37 ) ;
}
}
}
}
static int F_17 ( T_1 V_6 )
{
return V_6 & ( V_29 - 1 ) ;
}
static bool F_18 ( struct V_33 * V_34 , int V_40 )
{
int V_41 = V_34 -> V_38 ;
void * V_42 ;
if ( V_40 < V_34 -> V_38 )
return true ;
while ( V_34 -> V_38 <= V_40 )
V_34 -> V_38 += V_43 ;
V_42 = V_34 -> V_39 ;
V_34 -> V_39 = realloc ( V_34 -> V_39 ,
V_34 -> V_38 * sizeof( * V_34 -> V_39 ) ) ;
if ( ! V_34 -> V_39 ) {
free ( V_42 ) ;
F_8 ( L_4 ) ;
return false ;
}
memset ( V_34 -> V_39 + V_41 , 0 ,
( V_34 -> V_38 - V_41 ) * sizeof( * V_34 -> V_39 ) ) ;
return true ;
}
static struct V_33 * F_19 ( struct V_5 * V_6 )
{
struct V_33 * V_34 ;
V_34 = F_20 ( sizeof( * V_34 ) ) ;
if ( ! V_34 ) {
F_8 ( L_4 ) ;
return NULL ;
}
V_34 -> V_6 = * V_6 ;
F_16 ( & V_34 -> V_36 . V_37 ) ;
return V_34 ;
}
static struct V_33 * F_21 ( struct V_13 * V_14 ,
struct V_5 * V_6 )
{
struct V_33 * V_34 ;
struct V_31 * V_32 ;
F_22 ( V_6 -> V_6 == V_44 ) ;
V_32 = & V_14 -> V_30 [ F_17 ( V_6 -> V_6 ) ] ;
F_15 (event, head, hash_entry) {
if ( V_34 -> V_6 . V_6 == V_6 -> V_6 && V_34 -> V_6 . V_7 == V_6 -> V_7 )
return V_34 ;
}
V_34 = F_19 ( V_6 ) ;
if ( ! V_34 )
return NULL ;
F_23 ( & V_34 -> V_45 , V_32 ) ;
return V_34 ;
}
static bool F_24 ( struct V_13 * V_14 ,
struct V_46 * V_47 ,
struct V_5 * V_6 , T_1 V_48 )
{
struct V_33 * V_34 = NULL ;
if ( V_6 -> V_6 != V_44 )
V_34 = F_21 ( V_14 , V_6 ) ;
V_47 -> V_49 = V_34 ;
V_47 -> V_50 = V_48 ;
return true ;
}
static void
F_25 ( struct V_51 * V_52 , T_1 V_53 )
{
V_52 -> time += V_53 ;
F_26 ( & V_52 -> V_37 , V_53 ) ;
}
static double F_27 ( int V_40 , struct V_33 * V_34 )
{
struct V_51 * V_52 = & V_34 -> V_36 ;
if ( V_40 != - 1 )
V_52 = & V_34 -> V_39 [ V_40 ] ;
return F_28 ( F_29 ( & V_52 -> V_37 ) ,
F_30 ( & V_52 -> V_37 ) ) ;
}
static bool F_31 ( struct V_33 * V_34 , int V_40 ,
T_1 V_53 )
{
if ( V_40 == - 1 ) {
F_25 ( & V_34 -> V_36 , V_53 ) ;
return true ;
}
if ( ! F_18 ( V_34 , V_40 ) )
return false ;
F_25 ( & V_34 -> V_39 [ V_40 ] , V_53 ) ;
return true ;
}
static bool F_32 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_54 * V_55 ;
V_55 = V_14 -> V_25 -> V_55 ;
if ( ! V_55 )
return false ;
for (; V_55 -> V_9 ; V_55 ++ ) {
if ( ! strcmp ( V_2 -> V_9 , V_55 -> V_9 ) ) {
V_55 -> V_56 ( V_2 , V_4 , V_6 ) ;
return true ;
}
}
return false ;
}
static bool F_33 ( struct V_13 * V_14 ,
struct V_46 * V_47 ,
struct V_5 * V_6 ,
struct V_3 * V_4 V_12 )
{
struct V_33 * V_34 = NULL ;
if ( V_6 -> V_6 != V_44 )
V_34 = F_21 ( V_14 , V_6 ) ;
V_47 -> V_49 = V_34 ;
return true ;
}
static bool F_34 ( const char * V_34 )
{
const char * const * V_57 ;
for ( V_57 = V_58 ; * V_57 ; V_57 ++ )
if ( ! strcmp ( V_34 , * V_57 ) )
return true ;
return false ;
}
static bool F_35 ( struct V_13 * V_14 ,
struct V_46 * V_47 ,
struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_33 * V_34 ;
T_1 V_59 , V_53 ;
int V_39 ;
if ( V_14 -> V_60 == - 1 )
V_39 = - 1 ;
else
V_39 = V_47 -> V_40 ;
V_34 = V_47 -> V_49 ;
V_59 = V_47 -> V_50 ;
if ( ! V_59 )
return true ;
if ( ! V_34 && V_6 -> V_6 == V_44 )
return true ;
if ( ! V_34 )
V_34 = F_21 ( V_14 , V_6 ) ;
if ( ! V_34 )
return false ;
V_47 -> V_49 = NULL ;
V_47 -> V_50 = 0 ;
if ( V_4 -> time < V_59 ) {
F_36 ( L_5 ) ;
return true ;
}
V_53 = V_4 -> time - V_59 ;
if ( V_14 -> V_61 && V_53 > V_14 -> V_61 ) {
char V_20 [ V_23 ] ;
V_14 -> V_25 -> V_62 ( V_14 , & V_34 -> V_6 , V_20 ) ;
if ( ! F_34 ( V_20 ) ) {
F_37 ( L_6 V_63 L_7 V_63 L_8 ,
V_4 -> time , V_4 -> V_64 , V_47 -> V_40 ,
V_20 , V_53 / 1000 ) ;
}
}
return F_31 ( V_34 , V_39 , V_53 ) ;
}
static
struct V_46 * F_38 ( struct V_65 * V_65 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! F_39 ( V_65 ) && F_5 ( V_2 ) ) {
struct V_46 * V_47 ;
V_47 = F_20 ( sizeof( * V_47 ) ) ;
if ( ! V_47 ) {
F_8 ( L_9 , V_66 ) ;
return NULL ;
}
V_47 -> V_40 = F_2 ( V_2 , V_4 , V_67 ) ;
F_40 ( V_65 , V_47 ) ;
}
return F_39 ( V_65 ) ;
}
static bool F_41 ( struct V_13 * V_14 ,
struct V_65 * V_65 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_46 * V_47 ;
struct V_5 V_6 = { . V_6 = V_44 ,
. V_22 = V_14 -> V_22 } ;
V_47 = F_38 ( V_65 , V_2 , V_4 ) ;
if ( ! V_47 )
return true ;
if ( ( V_14 -> V_60 != - 1 ) &&
( V_14 -> V_60 != V_47 -> V_40 ) )
return true ;
if ( V_14 -> V_25 -> V_68 ( V_2 , V_4 , & V_6 ) )
return F_24 ( V_14 , V_47 , & V_6 , V_4 -> time ) ;
if ( F_32 ( V_14 , V_2 , V_4 , & V_6 ) )
return F_33 ( V_14 , V_47 , & V_6 , V_4 ) ;
if ( V_14 -> V_25 -> V_69 ( V_2 , V_4 , & V_6 ) )
return F_35 ( V_14 , V_47 , & V_6 , V_4 ) ;
return true ;
}
static bool F_42 ( struct V_13 * V_14 )
{
int V_28 ;
for ( V_28 = 0 ; V_70 [ V_28 ] . V_9 ; V_28 ++ ) {
if ( ! strcmp ( V_70 [ V_28 ] . V_9 , V_14 -> V_71 ) ) {
V_14 -> V_72 = V_70 [ V_28 ] . V_6 ;
return true ;
}
}
F_8 ( L_10 , V_14 -> V_71 ) ;
return false ;
}
static void F_43 ( struct V_73 * V_74 , struct V_33 * V_34 ,
T_2 V_75 , int V_39 )
{
struct V_76 * * V_77 = & V_74 -> V_76 ;
struct V_76 * V_78 = NULL ;
struct V_33 * V_79 ;
while ( * V_77 ) {
V_79 = F_44 ( * V_77 , struct V_33 , V_77 ) ;
V_78 = * V_77 ;
if ( V_75 ( V_34 , V_79 , V_39 ) )
V_77 = & ( * V_77 ) -> V_80 ;
else
V_77 = & ( * V_77 ) -> V_81 ;
}
F_45 ( & V_34 -> V_77 , V_78 , V_77 ) ;
F_46 ( & V_34 -> V_77 , V_74 ) ;
}
static void
F_47 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
int V_39 = V_14 -> V_60 ;
V_14 -> V_82 += F_48 ( V_34 , V_39 ) ;
V_14 -> V_83 += F_49 ( V_34 , V_39 ) ;
}
static bool F_50 ( struct V_33 * V_34 , int V_39 )
{
return ! ! F_48 ( V_34 , V_39 ) ;
}
static void F_51 ( struct V_13 * V_14 )
{
unsigned int V_28 ;
int V_39 = V_14 -> V_60 ;
struct V_33 * V_34 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
F_15 (event, &kvm->kvm_events_cache[i], hash_entry) {
if ( F_50 ( V_34 , V_39 ) ) {
F_47 ( V_14 , V_34 ) ;
F_43 ( & V_14 -> V_74 , V_34 ,
V_14 -> V_72 , V_39 ) ;
}
}
}
}
static struct V_33 * F_52 ( struct V_73 * V_74 )
{
struct V_76 * V_84 = F_53 ( V_74 ) ;
if ( ! V_84 )
return NULL ;
F_54 ( V_84 , V_74 ) ;
return F_44 ( V_84 , struct V_33 , V_77 ) ;
}
static void F_55 ( struct V_13 * V_14 )
{
int V_39 = V_14 -> V_60 ;
F_37 ( L_11 ) ;
if ( V_14 -> V_85 . V_86 . V_87 )
F_37 ( L_12 ) ;
else if ( V_14 -> V_85 . V_86 . V_64 )
F_37 ( L_13 , V_14 -> V_85 . V_86 . V_64 ) ;
else
F_37 ( L_14 ) ;
if ( V_39 == - 1 )
F_37 ( L_15 ) ;
else
F_37 ( L_16 , V_39 ) ;
}
static void F_56 ( void )
{
char V_88 [ 64 ] ;
struct V_89 V_90 ;
struct V_91 V_92 ;
F_57 ( & V_90 , NULL ) ;
if ( localtime_r ( & V_90 . V_93 , & V_92 ) ) {
strftime ( V_88 , sizeof( V_88 ) , L_17 , & V_92 ) ;
F_37 ( L_18 , V_88 , V_90 . V_94 ) ;
} else
F_37 ( L_19 ) ;
return;
}
static void F_58 ( struct V_13 * V_14 )
{
char V_20 [ V_23 ] ;
struct V_33 * V_34 ;
int V_39 = V_14 -> V_60 ;
if ( V_14 -> V_95 ) {
puts ( V_96 ) ;
F_56 () ;
}
F_37 ( L_20 ) ;
F_55 ( V_14 ) ;
F_37 ( L_21 , V_23 , V_14 -> V_25 -> V_9 ) ;
F_37 ( L_22 , L_23 ) ;
F_37 ( L_24 , L_25 ) ;
F_37 ( L_24 , L_26 ) ;
F_37 ( L_27 , L_28 ) ;
F_37 ( L_27 , L_29 ) ;
F_37 ( L_30 , L_31 ) ;
F_37 ( L_20 ) ;
while ( ( V_34 = F_52 ( & V_14 -> V_74 ) ) ) {
T_1 V_97 , V_98 , V_99 , V_100 ;
V_97 = F_48 ( V_34 , V_39 ) ;
V_98 = F_49 ( V_34 , V_39 ) ;
V_99 = F_59 ( V_34 , V_39 ) ;
V_100 = F_60 ( V_34 , V_39 ) ;
V_14 -> V_25 -> V_62 ( V_14 , & V_34 -> V_6 , V_20 ) ;
F_37 ( L_21 , V_23 , V_20 ) ;
F_37 ( L_32 , ( unsigned long long ) V_97 ) ;
F_37 ( L_33 , ( double ) V_97 / V_14 -> V_82 * 100 ) ;
F_37 ( L_33 , ( double ) V_98 / V_14 -> V_83 * 100 ) ;
F_37 ( L_34 , ( double ) V_100 / 1e3 ) ;
F_37 ( L_34 , ( double ) V_99 / 1e3 ) ;
F_37 ( L_35 , ( double ) V_98 / V_97 / 1e3 ,
F_27 ( V_39 , V_34 ) ) ;
F_37 ( L_36 ) ;
}
F_37 ( L_37 V_63 L_38 ,
V_14 -> V_82 , V_14 -> V_83 / 1e3 ) ;
if ( V_14 -> V_101 )
F_37 ( L_39 V_63 L_20 , V_14 -> V_101 ) ;
}
static int F_61 ( struct V_102 * V_103 ,
union V_104 * V_34 V_12 ,
struct V_3 * V_4 V_12 ,
struct V_105 * V_105 V_12 )
{
struct V_13 * V_14 = F_44 ( V_103 , struct V_13 , V_103 ) ;
V_14 -> V_101 ++ ;
return 0 ;
}
static bool F_62 ( struct V_13 * V_14 ,
struct V_3 * V_4 )
{
if ( V_14 -> V_106 && F_63 ( V_14 -> V_106 , V_4 -> V_64 ) == NULL )
return true ;
return false ;
}
static int F_64 ( struct V_102 * V_103 ,
union V_104 * V_34 ,
struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_105 * V_105 )
{
struct V_65 * V_65 ;
struct V_13 * V_14 = F_44 ( V_103 , struct V_13 ,
V_103 ) ;
if ( F_62 ( V_14 , V_4 ) )
return 0 ;
V_65 = F_65 ( V_105 , V_4 -> V_64 , V_4 -> V_107 ) ;
if ( V_65 == NULL ) {
F_36 ( L_40 ,
V_34 -> V_108 . type ) ;
return - 1 ;
}
if ( ! F_41 ( V_14 , V_65 , V_2 , V_4 ) )
return - 1 ;
return 0 ;
}
static int F_66 ( struct V_13 * V_14 )
{
char V_109 [ 64 ] , * V_110 ;
int V_111 ;
if ( V_14 -> V_95 ) {
V_111 = F_67 ( V_109 , sizeof( V_109 ) ) ;
if ( V_111 != 0 ) {
F_8 ( L_41 ) ;
return V_111 ;
}
V_110 = V_109 ;
} else
V_110 = V_14 -> V_112 -> V_108 . V_113 . V_110 ;
if ( ! V_110 ) {
F_8 ( L_41 ) ;
return - V_114 ;
}
V_111 = F_68 ( V_14 , V_110 ) ;
if ( V_111 == - V_115 )
F_8 ( L_42 , V_110 ) ;
return V_111 ;
}
static bool F_69 ( int V_39 )
{
if ( V_39 != - 1 && V_39 < 0 ) {
F_8 ( L_43 , V_39 ) ;
return false ;
}
return true ;
}
static T_3 F_70 ( struct V_13 * V_14 , int V_116 ,
T_1 * V_117 )
{
union V_104 * V_34 ;
struct V_3 V_4 ;
T_3 V_118 = 0 ;
int V_111 ;
* V_117 = V_119 ;
while ( ( V_34 = F_71 ( V_14 -> V_120 , V_116 ) ) != NULL ) {
V_111 = F_72 ( V_14 -> V_120 , V_34 , & V_4 ) ;
if ( V_111 ) {
F_73 ( V_14 -> V_120 , V_116 ) ;
F_8 ( L_44 ) ;
return - 1 ;
}
V_111 = F_74 ( V_14 -> V_112 , V_34 , & V_14 -> V_103 , & V_4 , 0 ) ;
F_73 ( V_14 -> V_120 , V_116 ) ;
if ( V_111 ) {
F_8 ( L_45 , V_111 ) ;
return - 1 ;
}
if ( V_118 == 0 )
* V_117 = V_4 . time ;
V_118 ++ ;
if ( V_118 == V_121 )
break;
}
return V_118 ;
}
static int F_75 ( struct V_13 * V_14 )
{
int V_28 , V_111 , V_122 = 0 ;
T_3 V_118 , V_123 = 0 ;
T_1 V_124 = V_119 , V_117 ;
for ( V_28 = 0 ; V_28 < V_14 -> V_120 -> V_125 ; V_28 ++ ) {
V_118 = F_70 ( V_14 , V_28 , & V_117 ) ;
if ( V_118 < 0 )
return - 1 ;
if ( V_117 < V_124 )
V_124 = V_117 ;
V_123 += V_118 ;
if ( V_118 == V_121 )
V_122 = 1 ;
}
if ( V_123 ) {
V_14 -> V_112 -> V_126 . V_127 = V_124 ;
V_111 = V_14 -> V_103 . V_128 ( & V_14 -> V_103 , NULL , V_14 -> V_112 ) ;
if ( V_111 ) {
if ( V_14 -> V_101 )
F_37 ( L_39 V_63 L_20 ,
V_14 -> V_101 ) ;
return V_111 ;
}
}
return V_122 ;
}
static void F_76 ( int T_4 V_12 )
{
V_129 = 1 ;
}
static int F_77 ( struct V_13 * V_14 )
{
struct V_130 V_131 ;
int V_132 = - 1 ;
V_14 -> V_133 = F_78 ( V_134 , V_135 ) ;
if ( V_14 -> V_133 < 0 ) {
F_8 ( L_46 ) ;
goto V_136;
}
V_131 . V_137 . V_93 = V_14 -> V_138 ;
V_131 . V_137 . V_139 = 0 ;
V_131 . V_140 . V_93 = V_14 -> V_138 ;
V_131 . V_140 . V_139 = 0 ;
if ( F_79 ( V_14 -> V_133 , 0 , & V_131 , NULL ) != 0 ) {
F_8 ( L_47 , V_141 ) ;
F_80 ( V_14 -> V_133 ) ;
goto V_136;
}
V_132 = 0 ;
V_136:
return V_132 ;
}
static int F_81 ( struct V_13 * V_14 )
{
T_5 V_142 ;
int V_132 ;
V_132 = F_82 ( V_14 -> V_133 , & V_142 , sizeof( T_5 ) ) ;
if ( V_132 < 0 ) {
if ( V_141 == V_143 )
return 0 ;
F_8 ( L_48 , V_141 ) ;
return - 1 ;
}
if ( V_132 != sizeof( T_5 ) ) {
F_8 ( L_49 ) ;
return - 1 ;
}
if ( V_142 != 1 )
F_36 ( L_50 V_63 L_36 , V_142 - 1 ) ;
F_51 ( V_14 ) ;
F_58 ( V_14 ) ;
F_14 ( V_14 -> V_30 ) ;
V_14 -> V_82 = 0 ;
V_14 -> V_83 = 0 ;
V_14 -> V_101 = 0 ;
return 0 ;
}
static int F_83 ( int V_144 )
{
long V_145 = 0 ;
V_145 = F_84 ( V_144 , V_146 ) ;
if ( V_145 < 0 ) {
F_8 ( L_51 , V_144 ) ;
return - 1 ;
}
if ( F_84 ( V_144 , V_147 , V_145 | V_148 ) < 0 ) {
F_8 ( L_52 , V_144 ) ;
return - 1 ;
}
return 0 ;
}
static int F_85 ( void )
{
int V_142 ;
V_142 = getc ( V_149 ) ;
if ( V_142 == 'q' )
return 1 ;
return 0 ;
}
static int F_86 ( struct V_13 * V_14 )
{
int V_150 , V_151 , V_111 = - V_114 ;
struct V_152 V_153 ;
V_14 -> V_95 = true ;
V_151 = F_66 ( V_14 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( ! F_69 ( V_14 -> V_60 ) ||
! F_42 ( V_14 ) ||
! F_11 ( V_14 ) ) {
goto V_136;
}
F_87 ( & V_153 ) ;
F_12 ( V_14 ) ;
signal ( V_154 , F_76 ) ;
signal ( V_155 , F_76 ) ;
if ( F_77 ( V_14 ) < 0 ) {
V_111 = - 1 ;
goto V_136;
}
if ( F_88 ( V_14 -> V_120 , V_14 -> V_133 ) < 0 )
goto V_136;
V_150 = F_88 ( V_14 -> V_120 , fileno ( V_149 ) ) ;
if ( V_150 < 0 )
goto V_136;
if ( F_83 ( fileno ( V_149 ) ) != 0 )
goto V_136;
F_89 ( V_14 -> V_120 ) ;
while ( ! V_129 ) {
struct V_156 * V_157 = & V_14 -> V_120 -> V_158 ;
int V_132 ;
V_132 = F_75 ( V_14 ) ;
if ( V_132 < 0 )
break;
V_111 = F_81 ( V_14 ) ;
if ( V_111 )
goto V_136;
if ( V_157 -> V_159 [ V_150 ] . V_160 & V_161 )
V_129 = F_85 () ;
if ( ! V_132 && ! V_129 )
V_111 = F_90 ( V_157 , 100 ) ;
}
F_91 ( V_14 -> V_120 ) ;
if ( V_111 == 0 ) {
F_51 ( V_14 ) ;
F_58 ( V_14 ) ;
}
V_136:
if ( V_14 -> V_133 >= 0 )
F_80 ( V_14 -> V_133 ) ;
F_92 ( 0 , V_162 , & V_153 ) ;
return V_111 ;
}
static int F_93 ( struct V_13 * V_14 )
{
int V_111 , V_132 = - 1 ;
struct V_1 * V_163 ;
struct V_164 * V_120 = V_14 -> V_120 ;
char V_165 [ V_166 ] ;
F_94 ( V_120 , & V_14 -> V_85 ) ;
F_95 (evlist, pos) {
struct V_167 * V_168 = & V_163 -> V_168 ;
F_96 ( V_163 , V_169 ) ;
F_96 ( V_163 , TIME ) ;
F_96 ( V_163 , V_170 ) ;
F_96 ( V_163 , V_171 ) ;
F_97 ( V_163 , V_172 ) ;
F_97 ( V_163 , V_173 ) ;
F_97 ( V_163 , V_174 ) ;
F_97 ( V_163 , V_175 ) ;
F_97 ( V_163 , V_176 ) ;
V_168 -> V_177 = 0 ;
V_168 -> V_178 = 0 ;
V_168 -> V_179 = 0 ;
V_168 -> V_180 = 1 ;
V_168 -> V_181 = 0 ;
V_168 -> V_182 = 1000 ;
V_168 -> V_183 = 1 ;
}
V_111 = F_98 ( V_120 ) ;
if ( V_111 < 0 ) {
printf ( L_53 ,
F_99 ( V_141 , V_165 , sizeof( V_165 ) ) ) ;
goto V_136;
}
if ( F_100 ( V_120 , V_14 -> V_85 . V_184 , false ) < 0 ) {
F_101 ( L_54 ,
F_99 ( V_141 , V_165 , sizeof( V_165 ) ) ) ;
F_102 ( V_120 ) ;
goto V_136;
}
V_132 = 0 ;
V_136:
return V_132 ;
}
static int F_103 ( struct V_13 * V_14 )
{
int V_151 ;
struct V_102 V_185 = {
. V_4 = F_64 ,
. V_178 = V_186 ,
. V_126 = true ,
} ;
struct V_187 V_188 = {
. V_189 = V_14 -> V_190 ,
. V_191 = V_192 ,
} ;
V_14 -> V_103 = V_185 ;
V_14 -> V_112 = F_104 ( & V_188 , false , & V_14 -> V_103 ) ;
if ( ! V_14 -> V_112 ) {
F_8 ( L_55 ) ;
return - 1 ;
}
F_105 ( & V_14 -> V_112 -> V_108 . V_113 ) ;
if ( ! F_106 ( V_14 -> V_112 , L_56 ) )
return - V_114 ;
V_151 = F_66 ( V_14 ) ;
if ( V_151 < 0 )
return V_151 ;
return F_107 ( V_14 -> V_112 , & V_14 -> V_103 ) ;
}
static int F_108 ( struct V_13 * V_14 )
{
if ( V_14 -> V_85 . V_86 . V_64 ) {
V_14 -> V_106 = F_109 ( V_14 -> V_85 . V_86 . V_64 ) ;
if ( V_14 -> V_106 == NULL ) {
F_8 ( L_57 ) ;
return - V_114 ;
}
}
return 0 ;
}
static int F_110 ( struct V_13 * V_14 )
{
int V_151 = - V_114 ;
int V_39 = V_14 -> V_60 ;
if ( F_108 ( V_14 ) != 0 )
goto exit;
if ( ! F_69 ( V_39 ) )
goto exit;
if ( ! F_42 ( V_14 ) )
goto exit;
if ( ! F_11 ( V_14 ) )
goto exit;
F_12 ( V_14 ) ;
F_111 () ;
V_151 = F_103 ( V_14 ) ;
if ( V_151 )
goto exit;
F_51 ( V_14 ) ;
F_58 ( V_14 ) ;
exit:
return V_151 ;
}
static int
F_112 ( struct V_13 * V_14 , int V_193 , const char * * V_194 )
{
unsigned int V_195 , V_28 , V_35 , V_196 ;
const char * * V_197 ;
const char * const V_198 [] = {
L_58 ,
L_59 ,
L_60 , L_61 ,
L_62 , L_63 ,
} ;
const char * const * V_199 ;
V_196 = 0 ;
for ( V_199 = V_200 ; * V_199 ; V_199 ++ )
V_196 ++ ;
V_195 = F_113 ( V_198 ) + V_193 + 2 +
2 * V_196 ;
V_197 = calloc ( V_195 + 1 , sizeof( char * ) ) ;
if ( V_197 == NULL )
return - V_201 ;
for ( V_28 = 0 ; V_28 < F_113 ( V_198 ) ; V_28 ++ )
V_197 [ V_28 ] = F_114 ( V_198 [ V_28 ] ) ;
for ( V_35 = 0 ; V_35 < V_196 ; V_35 ++ ) {
V_197 [ V_28 ++ ] = L_64 ;
V_197 [ V_28 ++ ] = F_114 ( V_200 [ V_35 ] ) ;
}
V_197 [ V_28 ++ ] = F_114 ( L_65 ) ;
V_197 [ V_28 ++ ] = F_114 ( V_14 -> V_190 ) ;
for ( V_35 = 1 ; V_35 < ( unsigned int ) V_193 ; V_35 ++ , V_28 ++ )
V_197 [ V_28 ] = V_194 [ V_35 ] ;
return F_115 ( V_28 , V_197 , NULL ) ;
}
static int
F_116 ( struct V_13 * V_14 , int V_193 , const char * * V_194 )
{
const struct V_202 V_203 [] = {
F_117 ( 0 , L_66 , & V_14 -> V_26 , L_67 ,
L_68
L_69 ) ,
F_118 ( 0 , L_70 , & V_14 -> V_60 ,
L_71 ) ,
F_117 ( 'k' , L_72 , & V_14 -> V_71 , L_73 ,
L_74
L_75 ) ,
F_117 ( 'p' , L_76 , & V_14 -> V_85 . V_86 . V_64 , L_76 ,
L_77 ) ,
F_119 ()
} ;
const char * const V_204 [] = {
L_78 ,
NULL
} ;
if ( V_193 ) {
V_193 = F_120 ( V_193 , V_194 ,
V_203 ,
V_204 , 0 ) ;
if ( V_193 )
F_121 ( V_204 ,
V_203 ) ;
}
if ( ! V_14 -> V_85 . V_86 . V_64 )
V_14 -> V_85 . V_86 . V_87 = true ;
return F_110 ( V_14 ) ;
}
static struct V_164 * F_122 ( void )
{
struct V_164 * V_120 ;
char * V_205 , * V_9 , * V_206 ;
int V_111 = - 1 ;
const char * const * V_199 ;
V_120 = F_123 () ;
if ( V_120 == NULL )
return NULL ;
for ( V_199 = V_200 ; * V_199 ; V_199 ++ ) {
V_205 = F_124 ( * V_199 ) ;
if ( V_205 == NULL )
goto V_136;
V_206 = V_205 ;
V_9 = strchr ( V_205 , ':' ) ;
if ( V_9 == NULL ) {
F_8 ( L_79 ,
* V_199 ) ;
free ( V_205 ) ;
goto V_136;
}
* V_9 = '\0' ;
V_9 ++ ;
if ( F_125 ( V_120 , V_206 , V_9 , NULL ) ) {
F_8 ( L_80 , * V_199 ) ;
free ( V_205 ) ;
goto V_136;
}
free ( V_205 ) ;
}
V_111 = 0 ;
V_136:
if ( V_111 ) {
F_126 ( V_120 ) ;
V_120 = NULL ;
}
return V_120 ;
}
static int F_127 ( struct V_13 * V_14 ,
int V_193 , const char * * V_194 )
{
char V_207 [ V_208 ] ;
int V_111 ;
const struct V_202 V_209 [] = {
F_117 ( 'p' , L_76 , & V_14 -> V_85 . V_86 . V_64 , L_76 ,
L_81 ) ,
F_128 ( 'm' , L_82 , & V_14 -> V_85 . V_184 , L_83 ,
L_84 ,
V_210 ) ,
F_129 ( 'v' , L_85 , & V_211 ,
L_86 ) ,
F_130 ( 'a' , L_87 , & V_14 -> V_85 . V_86 . V_87 ,
L_88 ) ,
F_131 ( 'd' , L_89 , & V_14 -> V_138 ,
L_90 ) ,
F_117 ( 0 , L_66 , & V_14 -> V_26 , L_67 ,
L_91 ) ,
F_118 ( 0 , L_70 , & V_14 -> V_60 ,
L_71 ) ,
F_117 ( 'k' , L_72 , & V_14 -> V_71 , L_73 ,
L_74
L_75 ) ,
F_132 ( 0 , L_92 , & V_14 -> V_61 ,
L_93
L_94
L_95 ) ,
F_119 ()
} ;
const char * const V_212 [] = {
L_96 ,
NULL
} ;
struct V_187 V_188 = {
. V_191 = V_213 ,
} ;
V_14 -> V_103 . V_4 = F_64 ;
V_14 -> V_103 . V_178 = V_186 ;
V_14 -> V_103 . exit = V_214 ;
V_14 -> V_103 . V_215 = V_216 ;
V_14 -> V_103 . V_217 = F_61 ;
V_14 -> V_103 . V_126 = true ;
F_133 ( & V_14 -> V_103 ) ;
V_14 -> V_138 = 1 ;
V_14 -> V_85 . V_218 = 1 ;
V_14 -> V_85 . V_184 = 512 ;
V_14 -> V_85 . V_86 . V_219 = false ;
V_14 -> V_85 . V_86 . V_220 = NULL ;
V_14 -> V_85 . V_86 . V_221 = V_222 ;
F_105 ( NULL ) ;
F_134 () ;
V_223 = 0 ;
F_135 ( false ) ;
if ( V_193 ) {
V_193 = F_120 ( V_193 , V_194 , V_209 ,
V_212 , 0 ) ;
if ( V_193 )
F_121 ( V_212 , V_209 ) ;
}
V_14 -> V_61 *= V_224 ;
V_111 = F_136 ( & V_14 -> V_85 . V_86 ) ;
if ( V_111 ) {
F_137 ( & V_14 -> V_85 . V_86 , V_111 , V_207 , V_208 ) ;
F_138 ( L_3 , V_207 ) ;
}
if ( F_139 ( & V_14 -> V_85 . V_86 ) )
V_14 -> V_85 . V_86 . V_87 = true ;
V_14 -> V_120 = F_122 () ;
if ( V_14 -> V_120 == NULL ) {
V_111 = - 1 ;
goto V_136;
}
V_225 . V_226 = V_14 -> V_120 -> V_227 ;
if ( F_140 ( V_14 -> V_120 , & V_14 -> V_85 . V_86 ) < 0 )
F_121 ( V_212 , V_209 ) ;
V_14 -> V_112 = F_104 ( & V_188 , false , & V_14 -> V_103 ) ;
if ( V_14 -> V_112 == NULL ) {
V_111 = - 1 ;
goto V_136;
}
V_14 -> V_112 -> V_120 = V_14 -> V_120 ;
F_141 ( V_14 -> V_112 ) ;
F_142 ( & V_14 -> V_112 -> V_126 , true ) ;
F_143 ( & V_14 -> V_112 -> V_228 . V_229 , & V_14 -> V_85 . V_86 ,
V_14 -> V_120 -> V_230 , false ) ;
V_111 = F_93 ( V_14 ) ;
if ( V_111 )
goto V_136;
V_111 = F_86 ( V_14 ) ;
V_136:
F_144 ( 0 ) ;
if ( V_14 -> V_112 )
F_145 ( V_14 -> V_112 ) ;
V_14 -> V_112 = NULL ;
if ( V_14 -> V_120 )
F_126 ( V_14 -> V_120 ) ;
return V_111 ;
}
static void F_146 ( void )
{
printf ( L_97 ) ;
printf ( L_98 ) ;
printf ( L_99 ) ;
printf ( L_100 ) ;
printf ( L_101 ) ;
printf ( L_102 ) ;
}
static int F_147 ( const char * V_190 , int V_193 , const char * * V_194 )
{
struct V_13 V_14 = {
. V_190 = V_190 ,
. V_60 = - 1 ,
. V_26 = L_103 ,
. V_71 = L_104 ,
} ;
if ( V_193 == 1 ) {
F_146 () ;
goto V_231;
}
if ( ! strncmp ( V_194 [ 1 ] , L_105 , 3 ) )
return F_112 ( & V_14 , V_193 - 1 , V_194 + 1 ) ;
if ( ! strncmp ( V_194 [ 1 ] , L_106 , 3 ) )
return F_116 ( & V_14 , V_193 - 1 , V_194 + 1 ) ;
#ifdef F_148
if ( ! strncmp ( V_194 [ 1 ] , L_107 , 4 ) )
return F_127 ( & V_14 , V_193 - 1 , V_194 + 1 ) ;
#endif
V_231:
return F_149 ( V_193 , V_194 , NULL ) ;
}
static int F_150 ( const char * V_190 , int V_193 , const char * * V_194 )
{
int V_195 , V_28 = 0 , V_35 ;
const char * * V_197 ;
V_195 = V_193 + 2 ;
V_197 = calloc ( V_195 + 1 , sizeof( char * ) ) ;
V_197 [ V_28 ++ ] = F_124 ( L_58 ) ;
V_197 [ V_28 ++ ] = F_124 ( L_65 ) ;
V_197 [ V_28 ++ ] = F_124 ( V_190 ) ;
for ( V_35 = 1 ; V_35 < V_193 ; V_35 ++ , V_28 ++ )
V_197 [ V_28 ] = V_194 [ V_35 ] ;
F_22 ( V_28 != V_195 ) ;
return F_115 ( V_28 , V_197 , NULL ) ;
}
static int F_151 ( const char * V_190 , int V_193 , const char * * V_194 )
{
int V_195 , V_28 = 0 , V_35 ;
const char * * V_197 ;
V_195 = V_193 + 2 ;
V_197 = calloc ( V_195 + 1 , sizeof( char * ) ) ;
V_197 [ V_28 ++ ] = F_124 ( L_108 ) ;
V_197 [ V_28 ++ ] = F_124 ( L_109 ) ;
V_197 [ V_28 ++ ] = F_124 ( V_190 ) ;
for ( V_35 = 1 ; V_35 < V_193 ; V_35 ++ , V_28 ++ )
V_197 [ V_28 ] = V_194 [ V_35 ] ;
F_22 ( V_28 != V_195 ) ;
return F_152 ( V_28 , V_197 , NULL ) ;
}
static int
F_153 ( const char * V_190 , int V_193 , const char * * V_194 )
{
int V_195 , V_28 = 0 , V_35 ;
const char * * V_197 ;
V_195 = V_193 + 2 ;
V_197 = calloc ( V_195 + 1 , sizeof( char * ) ) ;
V_197 [ V_28 ++ ] = F_124 ( L_110 ) ;
V_197 [ V_28 ++ ] = F_124 ( L_109 ) ;
V_197 [ V_28 ++ ] = F_124 ( V_190 ) ;
for ( V_35 = 1 ; V_35 < V_193 ; V_35 ++ , V_28 ++ )
V_197 [ V_28 ] = V_194 [ V_35 ] ;
F_22 ( V_28 != V_195 ) ;
return F_154 ( V_28 , V_197 , NULL ) ;
}
int F_155 ( int V_193 , const char * * V_194 , const char * T_6 V_12 )
{
const char * V_190 = NULL ;
const struct V_202 V_232 [] = {
F_117 ( 'i' , L_111 , & V_190 , L_112 ,
L_113 ) ,
F_117 ( 'o' , L_114 , & V_190 , L_112 ,
L_115 ) ,
F_130 ( 0 , L_116 , & V_233 ,
L_117 ) ,
F_130 ( 0 , L_118 , & V_234 ,
L_119 ) ,
F_117 ( 0 , L_120 , & V_225 . V_235 , L_121 ,
L_122
L_123 ) ,
F_117 ( 0 , L_124 , & V_225 . V_236 ,
L_112 , L_125 ) ,
F_117 ( 0 , L_126 , & V_225 . V_237 ,
L_112 , L_127 ) ,
F_117 ( 0 , L_128 , & V_225 . V_238 ,
L_112 , L_129 ) ,
F_129 ( 'v' , L_85 , & V_211 ,
L_86 ) ,
F_119 ()
} ;
const char * const V_239 [] = { L_130 , L_58 , L_108 , L_131 ,
L_110 , L_132 , NULL } ;
const char * V_240 [] = { NULL , NULL } ;
V_234 = 0 ;
V_233 = 1 ;
V_193 = F_156 ( V_193 , V_194 , V_232 , V_239 , V_240 ,
V_241 ) ;
if ( ! V_193 )
F_121 ( V_240 , V_232 ) ;
if ( ! V_234 )
V_233 = 1 ;
if ( ! V_190 ) {
V_190 = F_157 () ;
if ( ! V_190 ) {
F_8 ( L_133 ) ;
return - V_201 ;
}
}
if ( ! strncmp ( V_194 [ 0 ] , L_105 , 3 ) )
return F_150 ( V_190 , V_193 , V_194 ) ;
else if ( ! strncmp ( V_194 [ 0 ] , L_106 , 3 ) )
return F_151 ( V_190 , V_193 , V_194 ) ;
else if ( ! strncmp ( V_194 [ 0 ] , L_131 , 4 ) )
return F_158 ( V_193 , V_194 , NULL ) ;
else if ( ! strncmp ( V_194 [ 0 ] , L_130 , 3 ) )
return F_159 ( V_193 , V_194 , NULL ) ;
else if ( ! strncmp ( V_194 [ 0 ] , L_110 , 12 ) )
return F_153 ( V_190 , V_193 , V_194 ) ;
#ifdef F_160
else if ( ! strncmp ( V_194 [ 0 ] , L_132 , 4 ) )
return F_147 ( V_190 , V_193 , V_194 ) ;
#endif
else
F_121 ( V_240 , V_232 ) ;
return 0 ;
}
