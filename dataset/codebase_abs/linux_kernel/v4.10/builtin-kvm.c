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
V_20 , V_53 / V_65 ) ;
}
}
return F_31 ( V_34 , V_39 , V_53 ) ;
}
static
struct V_46 * F_38 ( struct V_66 * V_66 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! F_39 ( V_66 ) && F_5 ( V_2 ) ) {
struct V_46 * V_47 ;
V_47 = F_20 ( sizeof( * V_47 ) ) ;
if ( ! V_47 ) {
F_8 ( L_9 , V_67 ) ;
return NULL ;
}
V_47 -> V_40 = F_2 ( V_2 , V_4 ,
V_68 ) ;
F_40 ( V_66 , V_47 ) ;
}
return F_39 ( V_66 ) ;
}
static bool F_41 ( struct V_13 * V_14 ,
struct V_66 * V_66 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_46 * V_47 ;
struct V_5 V_6 = { . V_6 = V_44 ,
. V_22 = V_14 -> V_22 } ;
V_47 = F_38 ( V_66 , V_2 , V_4 ) ;
if ( ! V_47 )
return true ;
if ( ( V_14 -> V_60 != - 1 ) &&
( V_14 -> V_60 != V_47 -> V_40 ) )
return true ;
if ( V_14 -> V_25 -> V_69 ( V_2 , V_4 , & V_6 ) )
return F_24 ( V_14 , V_47 , & V_6 , V_4 -> time ) ;
if ( F_32 ( V_14 , V_2 , V_4 , & V_6 ) )
return F_33 ( V_14 , V_47 , & V_6 , V_4 ) ;
if ( V_14 -> V_25 -> V_70 ( V_2 , V_4 , & V_6 ) )
return F_35 ( V_14 , V_47 , & V_6 , V_4 ) ;
return true ;
}
static bool F_42 ( struct V_13 * V_14 )
{
int V_28 ;
for ( V_28 = 0 ; V_71 [ V_28 ] . V_9 ; V_28 ++ ) {
if ( ! strcmp ( V_71 [ V_28 ] . V_9 , V_14 -> V_72 ) ) {
V_14 -> V_73 = V_71 [ V_28 ] . V_6 ;
return true ;
}
}
F_8 ( L_10 , V_14 -> V_72 ) ;
return false ;
}
static void F_43 ( struct V_74 * V_75 , struct V_33 * V_34 ,
T_2 V_76 , int V_39 )
{
struct V_77 * * V_78 = & V_75 -> V_77 ;
struct V_77 * V_79 = NULL ;
struct V_33 * V_80 ;
while ( * V_78 ) {
V_80 = F_44 ( * V_78 , struct V_33 , V_78 ) ;
V_79 = * V_78 ;
if ( V_76 ( V_34 , V_80 , V_39 ) )
V_78 = & ( * V_78 ) -> V_81 ;
else
V_78 = & ( * V_78 ) -> V_82 ;
}
F_45 ( & V_34 -> V_78 , V_79 , V_78 ) ;
F_46 ( & V_34 -> V_78 , V_75 ) ;
}
static void
F_47 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
int V_39 = V_14 -> V_60 ;
V_14 -> V_83 += F_48 ( V_34 , V_39 ) ;
V_14 -> V_84 += F_49 ( V_34 , V_39 ) ;
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
F_43 ( & V_14 -> V_75 , V_34 ,
V_14 -> V_73 , V_39 ) ;
}
}
}
}
static struct V_33 * F_52 ( struct V_74 * V_75 )
{
struct V_77 * V_85 = F_53 ( V_75 ) ;
if ( ! V_85 )
return NULL ;
F_54 ( V_85 , V_75 ) ;
return F_44 ( V_85 , struct V_33 , V_78 ) ;
}
static void F_55 ( struct V_13 * V_14 )
{
int V_39 = V_14 -> V_60 ;
F_37 ( L_11 ) ;
if ( V_14 -> V_86 . V_87 . V_88 )
F_37 ( L_12 ) ;
else if ( V_14 -> V_86 . V_87 . V_64 )
F_37 ( L_13 , V_14 -> V_86 . V_87 . V_64 ) ;
else
F_37 ( L_14 ) ;
if ( V_39 == - 1 )
F_37 ( L_15 ) ;
else
F_37 ( L_16 , V_39 ) ;
}
static void F_56 ( void )
{
char V_89 [ 64 ] ;
struct V_90 V_91 ;
struct V_92 V_93 ;
F_57 ( & V_91 , NULL ) ;
if ( localtime_r ( & V_91 . V_94 , & V_93 ) ) {
strftime ( V_89 , sizeof( V_89 ) , L_17 , & V_93 ) ;
F_37 ( L_18 , V_89 , V_91 . V_95 ) ;
} else
F_37 ( L_19 ) ;
return;
}
static void F_58 ( struct V_13 * V_14 )
{
char V_20 [ V_23 ] ;
struct V_33 * V_34 ;
int V_39 = V_14 -> V_60 ;
if ( V_14 -> V_96 ) {
puts ( V_97 ) ;
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
while ( ( V_34 = F_52 ( & V_14 -> V_75 ) ) ) {
T_1 V_98 , V_99 , V_100 , V_101 ;
V_98 = F_48 ( V_34 , V_39 ) ;
V_99 = F_49 ( V_34 , V_39 ) ;
V_100 = F_59 ( V_34 , V_39 ) ;
V_101 = F_60 ( V_34 , V_39 ) ;
V_14 -> V_25 -> V_62 ( V_14 , & V_34 -> V_6 , V_20 ) ;
F_37 ( L_21 , V_23 , V_20 ) ;
F_37 ( L_32 , ( unsigned long long ) V_98 ) ;
F_37 ( L_33 , ( double ) V_98 / V_14 -> V_83 * 100 ) ;
F_37 ( L_33 , ( double ) V_99 / V_14 -> V_84 * 100 ) ;
F_37 ( L_34 , ( double ) V_101 / V_65 ) ;
F_37 ( L_34 , ( double ) V_100 / V_65 ) ;
F_37 ( L_35 , ( double ) V_99 / V_98 / V_65 ,
F_27 ( V_39 , V_34 ) ) ;
F_37 ( L_36 ) ;
}
F_37 ( L_37 V_63 L_38 ,
V_14 -> V_83 , V_14 -> V_84 / ( double ) V_65 ) ;
if ( V_14 -> V_102 )
F_37 ( L_39 V_63 L_20 , V_14 -> V_102 ) ;
}
static int F_61 ( struct V_103 * V_104 ,
union V_105 * V_34 V_12 ,
struct V_3 * V_4 V_12 ,
struct V_106 * V_106 V_12 )
{
struct V_13 * V_14 = F_44 ( V_104 , struct V_13 , V_104 ) ;
V_14 -> V_102 ++ ;
return 0 ;
}
static bool F_62 ( struct V_13 * V_14 ,
struct V_3 * V_4 )
{
if ( V_14 -> V_107 && F_63 ( V_14 -> V_107 , V_4 -> V_64 ) == NULL )
return true ;
return false ;
}
static int F_64 ( struct V_103 * V_104 ,
union V_105 * V_34 ,
struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_106 * V_106 )
{
int V_108 = 0 ;
struct V_66 * V_66 ;
struct V_13 * V_14 = F_44 ( V_104 , struct V_13 ,
V_104 ) ;
if ( F_62 ( V_14 , V_4 ) )
return 0 ;
V_66 = F_65 ( V_106 , V_4 -> V_64 , V_4 -> V_109 ) ;
if ( V_66 == NULL ) {
F_36 ( L_40 ,
V_34 -> V_110 . type ) ;
return - 1 ;
}
if ( ! F_41 ( V_14 , V_66 , V_2 , V_4 ) )
V_108 = - 1 ;
F_66 ( V_66 ) ;
return V_108 ;
}
static int F_67 ( struct V_13 * V_14 )
{
char V_111 [ 64 ] , * V_112 ;
int V_108 ;
if ( V_14 -> V_96 ) {
V_108 = F_68 ( V_111 , sizeof( V_111 ) ) ;
if ( V_108 != 0 ) {
F_8 ( L_41 ) ;
return V_108 ;
}
V_112 = V_111 ;
} else
V_112 = V_14 -> V_113 -> V_110 . V_114 . V_112 ;
if ( ! V_112 ) {
F_8 ( L_41 ) ;
return - V_115 ;
}
V_108 = F_69 ( V_14 , V_112 ) ;
if ( V_108 == - V_116 )
F_8 ( L_42 , V_112 ) ;
return V_108 ;
}
static bool F_70 ( int V_39 )
{
if ( V_39 != - 1 && V_39 < 0 ) {
F_8 ( L_43 , V_39 ) ;
return false ;
}
return true ;
}
static T_3 F_71 ( struct V_13 * V_14 , int V_117 ,
T_1 * V_118 )
{
union V_105 * V_34 ;
struct V_3 V_4 ;
T_3 V_119 = 0 ;
int V_108 ;
* V_118 = V_120 ;
while ( ( V_34 = F_72 ( V_14 -> V_121 , V_117 ) ) != NULL ) {
V_108 = F_73 ( V_14 -> V_121 , V_34 , & V_4 ) ;
if ( V_108 ) {
F_74 ( V_14 -> V_121 , V_117 ) ;
F_8 ( L_44 ) ;
return - 1 ;
}
V_108 = F_75 ( V_14 -> V_113 , V_34 , & V_4 , 0 ) ;
F_74 ( V_14 -> V_121 , V_117 ) ;
if ( V_108 ) {
F_8 ( L_45 , V_108 ) ;
return - 1 ;
}
if ( V_119 == 0 )
* V_118 = V_4 . time ;
V_119 ++ ;
if ( V_119 == V_122 )
break;
}
return V_119 ;
}
static int F_76 ( struct V_13 * V_14 )
{
int V_28 , V_108 , V_123 = 0 ;
T_3 V_119 , V_124 = 0 ;
T_1 V_125 = V_120 , V_118 ;
for ( V_28 = 0 ; V_28 < V_14 -> V_121 -> V_126 ; V_28 ++ ) {
V_119 = F_71 ( V_14 , V_28 , & V_118 ) ;
if ( V_119 < 0 )
return - 1 ;
if ( V_118 < V_125 )
V_125 = V_118 ;
V_124 += V_119 ;
if ( V_119 == V_122 )
V_123 = 1 ;
}
if ( V_124 ) {
struct V_127 * V_128 = & V_14 -> V_113 -> V_127 ;
V_128 -> V_129 = V_125 ;
V_108 = F_77 ( V_128 , V_130 ) ;
if ( V_108 ) {
if ( V_14 -> V_102 )
F_37 ( L_39 V_63 L_20 ,
V_14 -> V_102 ) ;
return V_108 ;
}
}
return V_123 ;
}
static void F_78 ( int T_4 V_12 )
{
V_131 = 1 ;
}
static int F_79 ( struct V_13 * V_14 )
{
struct V_132 V_133 ;
int V_134 = - 1 ;
V_14 -> V_135 = F_80 ( V_136 , V_137 ) ;
if ( V_14 -> V_135 < 0 ) {
F_8 ( L_46 ) ;
goto V_138;
}
V_133 . V_139 . V_94 = V_14 -> V_140 ;
V_133 . V_139 . V_141 = 0 ;
V_133 . V_142 . V_94 = V_14 -> V_140 ;
V_133 . V_142 . V_141 = 0 ;
if ( F_81 ( V_14 -> V_135 , 0 , & V_133 , NULL ) != 0 ) {
F_8 ( L_47 , V_143 ) ;
F_82 ( V_14 -> V_135 ) ;
goto V_138;
}
V_134 = 0 ;
V_138:
return V_134 ;
}
static int F_83 ( struct V_13 * V_14 )
{
T_5 V_144 ;
int V_134 ;
V_134 = F_84 ( V_14 -> V_135 , & V_144 , sizeof( T_5 ) ) ;
if ( V_134 < 0 ) {
if ( V_143 == V_145 )
return 0 ;
F_8 ( L_48 , V_143 ) ;
return - 1 ;
}
if ( V_134 != sizeof( T_5 ) ) {
F_8 ( L_49 ) ;
return - 1 ;
}
if ( V_144 != 1 )
F_36 ( L_50 V_63 L_36 , V_144 - 1 ) ;
F_51 ( V_14 ) ;
F_58 ( V_14 ) ;
F_14 ( V_14 -> V_30 ) ;
V_14 -> V_83 = 0 ;
V_14 -> V_84 = 0 ;
V_14 -> V_102 = 0 ;
return 0 ;
}
static int F_85 ( int V_146 )
{
long V_147 = 0 ;
V_147 = F_86 ( V_146 , V_148 ) ;
if ( V_147 < 0 ) {
F_8 ( L_51 , V_146 ) ;
return - 1 ;
}
if ( F_86 ( V_146 , V_149 , V_147 | V_150 ) < 0 ) {
F_8 ( L_52 , V_146 ) ;
return - 1 ;
}
return 0 ;
}
static int F_87 ( void )
{
int V_144 ;
V_144 = getc ( V_151 ) ;
if ( V_144 == 'q' )
return 1 ;
return 0 ;
}
static int F_88 ( struct V_13 * V_14 )
{
int V_152 , V_153 , V_108 = - V_115 ;
struct V_154 V_155 ;
V_14 -> V_96 = true ;
V_153 = F_67 ( V_14 ) ;
if ( V_153 < 0 )
return V_153 ;
if ( ! F_70 ( V_14 -> V_60 ) ||
! F_42 ( V_14 ) ||
! F_11 ( V_14 ) ) {
goto V_138;
}
F_89 ( & V_155 ) ;
F_12 ( V_14 ) ;
signal ( V_156 , F_78 ) ;
signal ( V_157 , F_78 ) ;
if ( F_79 ( V_14 ) < 0 ) {
V_108 = - 1 ;
goto V_138;
}
if ( F_90 ( V_14 -> V_121 , V_14 -> V_135 ) < 0 )
goto V_138;
V_152 = F_90 ( V_14 -> V_121 , fileno ( V_151 ) ) ;
if ( V_152 < 0 )
goto V_138;
if ( F_85 ( fileno ( V_151 ) ) != 0 )
goto V_138;
F_91 ( V_14 -> V_121 ) ;
while ( ! V_131 ) {
struct V_158 * V_159 = & V_14 -> V_121 -> V_160 ;
int V_134 ;
V_134 = F_76 ( V_14 ) ;
if ( V_134 < 0 )
break;
V_108 = F_83 ( V_14 ) ;
if ( V_108 )
goto V_138;
if ( V_159 -> V_161 [ V_152 ] . V_162 & V_163 )
V_131 = F_87 () ;
if ( ! V_134 && ! V_131 )
V_108 = F_92 ( V_159 , 100 ) ;
}
F_93 ( V_14 -> V_121 ) ;
if ( V_108 == 0 ) {
F_51 ( V_14 ) ;
F_58 ( V_14 ) ;
}
V_138:
if ( V_14 -> V_135 >= 0 )
F_82 ( V_14 -> V_135 ) ;
F_94 ( 0 , V_164 , & V_155 ) ;
return V_108 ;
}
static int F_95 ( struct V_13 * V_14 )
{
int V_108 , V_134 = - 1 ;
struct V_1 * V_165 ;
struct V_166 * V_121 = V_14 -> V_121 ;
char V_167 [ V_168 ] ;
F_96 ( V_121 , & V_14 -> V_86 , NULL ) ;
F_97 (evlist, pos) {
struct V_169 * V_170 = & V_165 -> V_170 ;
F_98 ( V_165 , V_171 ) ;
F_98 ( V_165 , TIME ) ;
F_98 ( V_165 , V_172 ) ;
F_98 ( V_165 , V_173 ) ;
F_99 ( V_165 , V_174 ) ;
F_99 ( V_165 , V_175 ) ;
F_99 ( V_165 , V_176 ) ;
F_99 ( V_165 , V_177 ) ;
F_99 ( V_165 , V_178 ) ;
V_170 -> V_179 = 0 ;
V_170 -> V_180 = 0 ;
V_170 -> V_181 = 0 ;
V_170 -> V_182 = 1 ;
V_170 -> V_183 = 0 ;
V_170 -> V_184 = 1000 ;
V_170 -> V_185 = 1 ;
}
V_108 = F_100 ( V_121 ) ;
if ( V_108 < 0 ) {
printf ( L_53 ,
F_101 ( V_143 , V_167 , sizeof( V_167 ) ) ) ;
goto V_138;
}
if ( F_102 ( V_121 , V_14 -> V_86 . V_186 , false ) < 0 ) {
F_103 ( L_54 ,
F_101 ( V_143 , V_167 , sizeof( V_167 ) ) ) ;
F_104 ( V_121 ) ;
goto V_138;
}
V_134 = 0 ;
V_138:
return V_134 ;
}
static int F_105 ( struct V_13 * V_14 )
{
int V_153 ;
struct V_103 V_187 = {
. V_4 = F_64 ,
. V_180 = V_188 ,
. V_127 = true ,
} ;
struct V_189 V_190 = {
. V_191 = V_14 -> V_192 ,
. V_193 = V_194 ,
. V_195 = V_14 -> V_195 ,
} ;
V_14 -> V_104 = V_187 ;
V_14 -> V_113 = F_106 ( & V_190 , false , & V_14 -> V_104 ) ;
if ( ! V_14 -> V_113 ) {
F_8 ( L_55 ) ;
return - 1 ;
}
F_107 ( & V_14 -> V_113 -> V_110 . V_114 ) ;
if ( ! F_108 ( V_14 -> V_113 , L_56 ) ) {
V_153 = - V_115 ;
goto V_196;
}
V_153 = F_67 ( V_14 ) ;
if ( V_153 < 0 )
goto V_196;
V_153 = F_109 ( V_14 -> V_113 ) ;
V_196:
F_110 ( V_14 -> V_113 ) ;
return V_153 ;
}
static int F_111 ( struct V_13 * V_14 )
{
if ( V_14 -> V_86 . V_87 . V_64 ) {
V_14 -> V_107 = F_112 ( V_14 -> V_86 . V_87 . V_64 ) ;
if ( V_14 -> V_107 == NULL ) {
F_8 ( L_57 ) ;
return - V_115 ;
}
}
return 0 ;
}
static int F_113 ( struct V_13 * V_14 )
{
int V_153 = - V_115 ;
int V_39 = V_14 -> V_60 ;
if ( F_111 ( V_14 ) != 0 )
goto exit;
if ( ! F_70 ( V_39 ) )
goto exit;
if ( ! F_42 ( V_14 ) )
goto exit;
if ( ! F_11 ( V_14 ) )
goto exit;
F_12 ( V_14 ) ;
F_114 () ;
V_153 = F_105 ( V_14 ) ;
if ( V_153 )
goto exit;
F_51 ( V_14 ) ;
F_58 ( V_14 ) ;
exit:
return V_153 ;
}
int __weak F_115 ( struct V_13 * V_14 V_12 )
{
return 0 ;
}
static int
F_116 ( struct V_13 * V_14 , int V_197 , const char * * V_198 )
{
unsigned int V_199 , V_28 , V_35 , V_200 ;
const char * * V_201 ;
const char * const V_202 [] = {
L_58 ,
L_59 ,
L_60 , L_61 ,
L_62 , L_63 ,
} ;
const char * const V_203 [] = {
L_64 ,
NULL
} ;
const char * const * V_204 ;
int V_153 ;
V_200 = 0 ;
V_153 = F_115 ( V_14 ) ;
if ( V_153 < 0 ) {
F_8 ( L_65 ) ;
return V_153 ;
}
for ( V_204 = V_205 ; * V_204 ; V_204 ++ )
V_200 ++ ;
V_199 = F_117 ( V_202 ) + V_197 + 2 +
2 * V_200 ;
V_201 = calloc ( V_199 + 1 , sizeof( char * ) ) ;
if ( V_201 == NULL )
return - V_206 ;
for ( V_28 = 0 ; V_28 < F_117 ( V_202 ) ; V_28 ++ )
V_201 [ V_28 ] = F_118 ( V_202 [ V_28 ] ) ;
for ( V_35 = 0 ; V_35 < V_200 ; V_35 ++ ) {
V_201 [ V_28 ++ ] = L_66 ;
V_201 [ V_28 ++ ] = F_118 ( V_205 [ V_35 ] ) ;
}
V_201 [ V_28 ++ ] = F_118 ( L_67 ) ;
V_201 [ V_28 ++ ] = F_118 ( V_14 -> V_192 ) ;
for ( V_35 = 1 ; V_35 < ( unsigned int ) V_197 ; V_35 ++ , V_28 ++ )
V_201 [ V_28 ] = V_198 [ V_35 ] ;
F_119 ( V_207 , 'e' , L_68 , V_208 ) ;
F_119 ( V_207 , 0 , L_69 , V_208 ) ;
F_119 ( V_207 , 'R' , L_70 , V_208 ) ;
F_119 ( V_207 , 'F' , L_71 , V_209 ) ;
F_119 ( V_207 , 0 , L_72 , V_209 ) ;
F_119 ( V_207 , 'g' , NULL , V_209 ) ;
F_119 ( V_207 , 0 , L_73 , V_209 ) ;
F_119 ( V_207 , 'd' , L_74 , V_209 ) ;
F_119 ( V_207 , 'T' , L_75 , V_209 ) ;
F_119 ( V_207 , 'P' , L_76 , V_209 ) ;
F_119 ( V_207 , 'n' , L_77 , V_209 ) ;
F_119 ( V_207 , 'N' , L_78 , V_209 ) ;
F_119 ( V_207 , 'B' , L_79 , V_209 ) ;
F_119 ( V_207 , 'G' , L_80 , V_209 ) ;
F_119 ( V_207 , 'b' , L_81 , V_209 ) ;
F_119 ( V_207 , 'j' , L_82 , V_209 ) ;
F_119 ( V_207 , 'W' , L_83 , V_209 ) ;
F_119 ( V_207 , 0 , L_84 , V_209 ) ;
V_210 = V_203 ;
return F_120 ( V_28 , V_201 , NULL ) ;
}
static int
F_121 ( struct V_13 * V_14 , int V_197 , const char * * V_198 )
{
const struct V_211 V_212 [] = {
F_122 ( 0 , L_68 , & V_14 -> V_26 , L_85 ,
L_86
L_87 ) ,
F_123 ( 0 , L_88 , & V_14 -> V_60 ,
L_89 ) ,
F_122 ( 'k' , L_90 , & V_14 -> V_72 , L_91 ,
L_92
L_93 ) ,
F_122 ( 'p' , L_94 , & V_14 -> V_86 . V_87 . V_64 , L_94 ,
L_95 ) ,
F_124 ( 'f' , L_96 , & V_14 -> V_195 , L_97 ) ,
F_125 ()
} ;
const char * const V_213 [] = {
L_98 ,
NULL
} ;
if ( V_197 ) {
V_197 = F_126 ( V_197 , V_198 ,
V_212 ,
V_213 , 0 ) ;
if ( V_197 )
F_127 ( V_213 ,
V_212 ) ;
}
if ( ! V_14 -> V_86 . V_87 . V_64 )
V_14 -> V_86 . V_87 . V_88 = true ;
return F_113 ( V_14 ) ;
}
static struct V_166 * F_128 ( void )
{
struct V_166 * V_121 ;
char * V_214 , * V_9 , * V_215 ;
int V_108 = - 1 ;
const char * const * V_204 ;
V_121 = F_129 () ;
if ( V_121 == NULL )
return NULL ;
for ( V_204 = V_205 ; * V_204 ; V_204 ++ ) {
V_214 = F_130 ( * V_204 ) ;
if ( V_214 == NULL )
goto V_138;
V_215 = V_214 ;
V_9 = strchr ( V_214 , ':' ) ;
if ( V_9 == NULL ) {
F_8 ( L_99 ,
* V_204 ) ;
free ( V_214 ) ;
goto V_138;
}
* V_9 = '\0' ;
V_9 ++ ;
if ( F_131 ( V_121 , V_215 , V_9 , NULL ) ) {
F_8 ( L_100 , * V_204 ) ;
free ( V_214 ) ;
goto V_138;
}
free ( V_214 ) ;
}
V_108 = 0 ;
V_138:
if ( V_108 ) {
F_132 ( V_121 ) ;
V_121 = NULL ;
}
return V_121 ;
}
static int F_133 ( struct V_13 * V_14 ,
int V_197 , const char * * V_198 )
{
char V_216 [ V_217 ] ;
int V_108 ;
const struct V_211 V_218 [] = {
F_122 ( 'p' , L_94 , & V_14 -> V_86 . V_87 . V_64 , L_94 ,
L_101 ) ,
F_134 ( 'm' , L_102 , & V_14 -> V_86 . V_186 , L_103 ,
L_104 ,
V_219 ) ,
F_135 ( 'v' , L_105 , & V_220 ,
L_106 ) ,
F_124 ( 'a' , L_107 , & V_14 -> V_86 . V_87 . V_88 ,
L_108 ) ,
F_136 ( 'd' , L_109 , & V_14 -> V_140 ,
L_110 ) ,
F_122 ( 0 , L_68 , & V_14 -> V_26 , L_85 ,
L_111
L_112 ) ,
F_123 ( 0 , L_88 , & V_14 -> V_60 ,
L_89 ) ,
F_122 ( 'k' , L_90 , & V_14 -> V_72 , L_91 ,
L_92
L_93 ) ,
F_137 ( 0 , L_113 , & V_14 -> V_61 ,
L_114
L_115
L_116 ) ,
F_136 ( 0 , L_117 , & V_14 -> V_86 . V_221 ,
L_118 ) ,
F_125 ()
} ;
const char * const V_222 [] = {
L_119 ,
NULL
} ;
struct V_189 V_190 = {
. V_193 = V_223 ,
} ;
V_14 -> V_104 . V_4 = F_64 ;
V_14 -> V_104 . V_180 = V_188 ;
V_14 -> V_104 . exit = V_224 ;
V_14 -> V_104 . V_225 = V_226 ;
V_14 -> V_104 . V_227 = F_61 ;
V_14 -> V_104 . V_127 = true ;
F_138 ( & V_14 -> V_104 ) ;
V_14 -> V_140 = 1 ;
V_14 -> V_86 . V_228 = 1 ;
V_14 -> V_86 . V_186 = 512 ;
V_14 -> V_86 . V_87 . V_229 = false ;
V_14 -> V_86 . V_87 . V_230 = NULL ;
V_14 -> V_86 . V_87 . V_231 = V_232 ;
V_14 -> V_86 . V_221 = 500 ;
F_107 ( NULL ) ;
F_139 () ;
V_233 = 0 ;
if ( V_197 ) {
V_197 = F_126 ( V_197 , V_198 , V_218 ,
V_222 , 0 ) ;
if ( V_197 )
F_127 ( V_222 , V_218 ) ;
}
V_14 -> V_61 *= V_65 ;
V_108 = F_140 ( & V_14 -> V_86 . V_87 ) ;
if ( V_108 ) {
F_141 ( & V_14 -> V_86 . V_87 , V_108 , V_216 , V_217 ) ;
F_142 ( L_3 , V_216 ) ;
}
if ( F_143 ( & V_14 -> V_86 . V_87 ) )
V_14 -> V_86 . V_87 . V_88 = true ;
V_108 = F_115 ( V_14 ) ;
if ( V_108 < 0 ) {
F_8 ( L_65 ) ;
return V_108 ;
}
V_14 -> V_121 = F_128 () ;
if ( V_14 -> V_121 == NULL ) {
V_108 = - 1 ;
goto V_138;
}
V_234 . V_235 = V_14 -> V_121 -> V_236 ;
if ( F_144 ( V_14 -> V_121 , & V_14 -> V_86 . V_87 ) < 0 )
F_127 ( V_222 , V_218 ) ;
V_14 -> V_113 = F_106 ( & V_190 , false , & V_14 -> V_104 ) ;
if ( V_14 -> V_113 == NULL ) {
V_108 = - 1 ;
goto V_138;
}
V_14 -> V_113 -> V_121 = V_14 -> V_121 ;
F_145 ( V_14 -> V_113 ) ;
F_146 ( & V_14 -> V_113 -> V_127 , true ) ;
F_147 ( & V_14 -> V_113 -> V_237 . V_238 , & V_14 -> V_86 . V_87 ,
V_14 -> V_121 -> V_239 , false , V_14 -> V_86 . V_221 ) ;
V_108 = F_95 ( V_14 ) ;
if ( V_108 )
goto V_138;
V_108 = F_88 ( V_14 ) ;
V_138:
F_110 ( V_14 -> V_113 ) ;
V_14 -> V_113 = NULL ;
F_132 ( V_14 -> V_121 ) ;
return V_108 ;
}
static void F_148 ( void )
{
printf ( L_120 ) ;
printf ( L_121 ) ;
printf ( L_122 ) ;
printf ( L_123 ) ;
printf ( L_124 ) ;
printf ( L_125 ) ;
}
static int F_149 ( const char * V_192 , int V_197 , const char * * V_198 )
{
struct V_13 V_14 = {
. V_192 = V_192 ,
. V_60 = - 1 ,
. V_26 = L_126 ,
. V_72 = L_127 ,
} ;
if ( V_197 == 1 ) {
F_148 () ;
goto V_240;
}
if ( ! strncmp ( V_198 [ 1 ] , L_128 , 3 ) )
return F_116 ( & V_14 , V_197 - 1 , V_198 + 1 ) ;
if ( ! strncmp ( V_198 [ 1 ] , L_129 , 3 ) )
return F_121 ( & V_14 , V_197 - 1 , V_198 + 1 ) ;
#ifdef F_150
if ( ! strncmp ( V_198 [ 1 ] , L_130 , 4 ) )
return F_133 ( & V_14 , V_197 - 1 , V_198 + 1 ) ;
#endif
V_240:
return F_151 ( V_197 , V_198 , NULL ) ;
}
static int F_152 ( const char * V_192 , int V_197 , const char * * V_198 )
{
int V_199 , V_28 = 0 , V_35 ;
const char * * V_201 ;
V_199 = V_197 + 2 ;
V_201 = calloc ( V_199 + 1 , sizeof( char * ) ) ;
V_201 [ V_28 ++ ] = F_130 ( L_58 ) ;
V_201 [ V_28 ++ ] = F_130 ( L_67 ) ;
V_201 [ V_28 ++ ] = F_130 ( V_192 ) ;
for ( V_35 = 1 ; V_35 < V_197 ; V_35 ++ , V_28 ++ )
V_201 [ V_28 ] = V_198 [ V_35 ] ;
F_22 ( V_28 != V_199 ) ;
return F_120 ( V_28 , V_201 , NULL ) ;
}
static int F_153 ( const char * V_192 , int V_197 , const char * * V_198 )
{
int V_199 , V_28 = 0 , V_35 ;
const char * * V_201 ;
V_199 = V_197 + 2 ;
V_201 = calloc ( V_199 + 1 , sizeof( char * ) ) ;
V_201 [ V_28 ++ ] = F_130 ( L_131 ) ;
V_201 [ V_28 ++ ] = F_130 ( L_132 ) ;
V_201 [ V_28 ++ ] = F_130 ( V_192 ) ;
for ( V_35 = 1 ; V_35 < V_197 ; V_35 ++ , V_28 ++ )
V_201 [ V_28 ] = V_198 [ V_35 ] ;
F_22 ( V_28 != V_199 ) ;
return F_154 ( V_28 , V_201 , NULL ) ;
}
static int
F_155 ( const char * V_192 , int V_197 , const char * * V_198 )
{
int V_199 , V_28 = 0 , V_35 ;
const char * * V_201 ;
V_199 = V_197 + 2 ;
V_201 = calloc ( V_199 + 1 , sizeof( char * ) ) ;
V_201 [ V_28 ++ ] = F_130 ( L_133 ) ;
V_201 [ V_28 ++ ] = F_130 ( L_132 ) ;
V_201 [ V_28 ++ ] = F_130 ( V_192 ) ;
for ( V_35 = 1 ; V_35 < V_197 ; V_35 ++ , V_28 ++ )
V_201 [ V_28 ] = V_198 [ V_35 ] ;
F_22 ( V_28 != V_199 ) ;
return F_156 ( V_28 , V_201 , NULL ) ;
}
int F_157 ( int V_197 , const char * * V_198 , const char * T_6 V_12 )
{
const char * V_192 = NULL ;
const struct V_211 V_241 [] = {
F_122 ( 'i' , L_134 , & V_192 , L_135 ,
L_136 ) ,
F_122 ( 'o' , L_137 , & V_192 , L_135 ,
L_138 ) ,
F_124 ( 0 , L_139 , & V_242 ,
L_140 ) ,
F_124 ( 0 , L_141 , & V_243 ,
L_142 ) ,
F_122 ( 0 , L_143 , & V_234 . V_244 , L_144 ,
L_145
L_146 ) ,
F_122 ( 0 , L_147 , & V_234 . V_245 ,
L_135 , L_148 ) ,
F_122 ( 0 , L_149 , & V_234 . V_246 ,
L_135 , L_150 ) ,
F_122 ( 0 , L_151 , & V_234 . V_247 ,
L_135 , L_152 ) ,
F_135 ( 'v' , L_105 , & V_220 ,
L_106 ) ,
F_125 ()
} ;
const char * const V_248 [] = { L_153 , L_58 , L_131 , L_154 ,
L_133 , L_155 , NULL } ;
const char * V_249 [] = { NULL , NULL } ;
V_243 = 0 ;
V_242 = 1 ;
V_197 = F_158 ( V_197 , V_198 , V_241 , V_248 , V_249 ,
V_250 ) ;
if ( ! V_197 )
F_127 ( V_249 , V_241 ) ;
if ( ! V_243 )
V_242 = 1 ;
if ( ! V_192 ) {
V_192 = F_159 () ;
if ( ! V_192 ) {
F_8 ( L_156 ) ;
return - V_206 ;
}
}
if ( ! strncmp ( V_198 [ 0 ] , L_128 , 3 ) )
return F_152 ( V_192 , V_197 , V_198 ) ;
else if ( ! strncmp ( V_198 [ 0 ] , L_129 , 3 ) )
return F_153 ( V_192 , V_197 , V_198 ) ;
else if ( ! strncmp ( V_198 [ 0 ] , L_154 , 4 ) )
return F_160 ( V_197 , V_198 , NULL ) ;
else if ( ! strncmp ( V_198 [ 0 ] , L_153 , 3 ) )
return F_161 ( V_197 , V_198 , NULL ) ;
else if ( ! strncmp ( V_198 [ 0 ] , L_133 , 12 ) )
return F_155 ( V_192 , V_197 , V_198 ) ;
#ifdef F_162
else if ( ! strncmp ( V_198 [ 0 ] , L_155 , 4 ) )
return F_149 ( V_192 , V_197 , V_198 ) ;
#endif
else
F_127 ( V_249 , V_241 ) ;
return 0 ;
}
