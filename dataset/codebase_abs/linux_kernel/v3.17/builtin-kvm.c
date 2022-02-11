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
if ( ! V_65 -> V_66 && F_5 ( V_2 ) ) {
struct V_46 * V_47 ;
V_47 = F_20 ( sizeof( * V_47 ) ) ;
if ( ! V_47 ) {
F_8 ( L_9 , V_67 ) ;
return NULL ;
}
V_47 -> V_40 = F_2 ( V_2 , V_4 , V_68 ) ;
V_65 -> V_66 = V_47 ;
}
return V_65 -> V_66 ;
}
static bool F_39 ( struct V_13 * V_14 ,
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
if ( V_14 -> V_25 -> V_69 ( V_2 , V_4 , & V_6 ) )
return F_24 ( V_14 , V_47 , & V_6 , V_4 -> time ) ;
if ( F_32 ( V_14 , V_2 , V_4 , & V_6 ) )
return F_33 ( V_14 , V_47 , & V_6 , V_4 ) ;
if ( V_14 -> V_25 -> V_70 ( V_2 , V_4 , & V_6 ) )
return F_35 ( V_14 , V_47 , & V_6 , V_4 ) ;
return true ;
}
static bool F_40 ( struct V_13 * V_14 )
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
static void F_41 ( struct V_74 * V_75 , struct V_33 * V_34 ,
T_2 V_76 , int V_39 )
{
struct V_77 * * V_78 = & V_75 -> V_77 ;
struct V_77 * V_79 = NULL ;
struct V_33 * V_80 ;
while ( * V_78 ) {
V_80 = F_42 ( * V_78 , struct V_33 , V_78 ) ;
V_79 = * V_78 ;
if ( V_76 ( V_34 , V_80 , V_39 ) )
V_78 = & ( * V_78 ) -> V_81 ;
else
V_78 = & ( * V_78 ) -> V_82 ;
}
F_43 ( & V_34 -> V_78 , V_79 , V_78 ) ;
F_44 ( & V_34 -> V_78 , V_75 ) ;
}
static void
F_45 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
int V_39 = V_14 -> V_60 ;
V_14 -> V_83 += F_46 ( V_34 , V_39 ) ;
V_14 -> V_84 += F_47 ( V_34 , V_39 ) ;
}
static bool F_48 ( struct V_33 * V_34 , int V_39 )
{
return ! ! F_46 ( V_34 , V_39 ) ;
}
static void F_49 ( struct V_13 * V_14 )
{
unsigned int V_28 ;
int V_39 = V_14 -> V_60 ;
struct V_33 * V_34 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
F_15 (event, &kvm->kvm_events_cache[i], hash_entry) {
if ( F_48 ( V_34 , V_39 ) ) {
F_45 ( V_14 , V_34 ) ;
F_41 ( & V_14 -> V_75 , V_34 ,
V_14 -> V_73 , V_39 ) ;
}
}
}
}
static struct V_33 * F_50 ( struct V_74 * V_75 )
{
struct V_77 * V_85 = F_51 ( V_75 ) ;
if ( ! V_85 )
return NULL ;
F_52 ( V_85 , V_75 ) ;
return F_42 ( V_85 , struct V_33 , V_78 ) ;
}
static void F_53 ( struct V_13 * V_14 )
{
int V_39 = V_14 -> V_60 ;
F_37 ( L_11 ) ;
if ( V_14 -> V_86 ) {
if ( V_14 -> V_87 . V_88 . V_89 )
F_37 ( L_12 ) ;
else if ( V_14 -> V_87 . V_88 . V_64 )
F_37 ( L_13 , V_14 -> V_87 . V_88 . V_64 ) ;
else
F_37 ( L_14 ) ;
}
if ( V_39 == - 1 )
F_37 ( L_15 ) ;
else
F_37 ( L_16 , V_39 ) ;
}
static void F_54 ( void )
{
char V_90 [ 64 ] ;
struct V_91 V_92 ;
struct V_93 V_94 ;
F_55 ( & V_92 , NULL ) ;
if ( localtime_r ( & V_92 . V_95 , & V_94 ) ) {
strftime ( V_90 , sizeof( V_90 ) , L_17 , & V_94 ) ;
F_37 ( L_18 , V_90 , V_92 . V_96 ) ;
} else
F_37 ( L_19 ) ;
return;
}
static void F_56 ( struct V_13 * V_14 )
{
char V_20 [ V_23 ] ;
struct V_33 * V_34 ;
int V_39 = V_14 -> V_60 ;
if ( V_14 -> V_86 ) {
puts ( V_97 ) ;
F_54 () ;
}
F_37 ( L_20 ) ;
F_53 ( V_14 ) ;
F_37 ( L_21 , V_23 , V_14 -> V_25 -> V_9 ) ;
F_37 ( L_22 , L_23 ) ;
F_37 ( L_24 , L_25 ) ;
F_37 ( L_24 , L_26 ) ;
F_37 ( L_22 , L_27 ) ;
F_37 ( L_22 , L_28 ) ;
F_37 ( L_29 , L_30 ) ;
F_37 ( L_20 ) ;
while ( ( V_34 = F_50 ( & V_14 -> V_75 ) ) ) {
T_1 V_98 , V_99 , V_100 , V_101 ;
V_98 = F_46 ( V_34 , V_39 ) ;
V_99 = F_47 ( V_34 , V_39 ) ;
V_100 = F_57 ( V_34 , V_39 ) ;
V_101 = F_58 ( V_34 , V_39 ) ;
V_14 -> V_25 -> V_62 ( V_14 , & V_34 -> V_6 , V_20 ) ;
F_37 ( L_21 , V_23 , V_20 ) ;
F_37 ( L_31 , ( unsigned long long ) V_98 ) ;
F_37 ( L_32 , ( double ) V_98 / V_14 -> V_83 * 100 ) ;
F_37 ( L_32 , ( double ) V_99 / V_14 -> V_84 * 100 ) ;
F_37 ( L_33 V_63 L_34 , V_101 / 1000 ) ;
F_37 ( L_33 V_63 L_34 , V_100 / 1000 ) ;
F_37 ( L_35 , ( double ) V_99 / V_98 / 1e3 ,
F_27 ( V_39 , V_34 ) ) ;
F_37 ( L_36 ) ;
}
F_37 ( L_37 V_63 L_38 ,
V_14 -> V_83 , V_14 -> V_84 / 1e3 ) ;
if ( V_14 -> V_102 )
F_37 ( L_39 V_63 L_20 , V_14 -> V_102 ) ;
}
static int F_59 ( struct V_103 * V_104 ,
union V_105 * V_34 V_12 ,
struct V_3 * V_4 V_12 ,
struct V_106 * V_106 V_12 )
{
struct V_13 * V_14 = F_42 ( V_104 , struct V_13 , V_104 ) ;
V_14 -> V_102 ++ ;
return 0 ;
}
static bool F_60 ( struct V_13 * V_14 ,
struct V_3 * V_4 )
{
if ( V_14 -> V_107 && F_61 ( V_14 -> V_107 , V_4 -> V_64 ) == NULL )
return true ;
return false ;
}
static int F_62 ( struct V_103 * V_104 ,
union V_105 * V_34 ,
struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_106 * V_106 )
{
struct V_65 * V_65 ;
struct V_13 * V_14 = F_42 ( V_104 , struct V_13 ,
V_104 ) ;
if ( F_60 ( V_14 , V_4 ) )
return 0 ;
V_65 = F_63 ( V_106 , V_4 -> V_64 , V_4 -> V_108 ) ;
if ( V_65 == NULL ) {
F_36 ( L_40 ,
V_34 -> V_109 . type ) ;
return - 1 ;
}
if ( ! F_39 ( V_14 , V_65 , V_2 , V_4 ) )
return - 1 ;
return 0 ;
}
static int F_64 ( struct V_13 * V_14 )
{
char V_110 [ 64 ] , * V_111 ;
int V_112 ;
if ( V_14 -> V_86 ) {
V_112 = F_65 ( V_110 , sizeof( V_110 ) ) ;
if ( V_112 != 0 ) {
F_8 ( L_41 ) ;
return V_112 ;
}
V_111 = V_110 ;
} else
V_111 = V_14 -> V_113 -> V_109 . V_114 . V_111 ;
if ( ! V_111 ) {
F_8 ( L_41 ) ;
return - V_115 ;
}
V_112 = F_66 ( V_14 , V_111 ) ;
if ( V_112 == - V_116 )
F_8 ( L_42 , V_111 ) ;
return V_112 ;
}
static bool F_67 ( int V_39 )
{
if ( V_39 != - 1 && V_39 < 0 ) {
F_8 ( L_43 , V_39 ) ;
return false ;
}
return true ;
}
static T_3 F_68 ( struct V_13 * V_14 , int V_117 ,
T_1 * V_118 )
{
union V_105 * V_34 ;
struct V_3 V_4 ;
T_3 V_119 = 0 ;
int V_112 ;
* V_118 = V_120 ;
while ( ( V_34 = F_69 ( V_14 -> V_121 , V_117 ) ) != NULL ) {
V_112 = F_70 ( V_14 -> V_121 , V_34 , & V_4 ) ;
if ( V_112 ) {
F_71 ( V_14 -> V_121 , V_117 ) ;
F_8 ( L_44 ) ;
return - 1 ;
}
V_112 = F_72 ( V_14 -> V_113 , V_34 , & V_4 , 0 ) ;
F_71 ( V_14 -> V_121 , V_117 ) ;
if ( V_112 ) {
F_8 ( L_45 , V_112 ) ;
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
static int F_73 ( struct V_13 * V_14 )
{
int V_28 , V_112 , V_123 = 0 ;
T_3 V_119 , V_124 = 0 ;
T_1 V_125 = V_120 , V_118 ;
for ( V_28 = 0 ; V_28 < V_14 -> V_121 -> V_126 ; V_28 ++ ) {
V_119 = F_68 ( V_14 , V_28 , & V_118 ) ;
if ( V_119 < 0 )
return - 1 ;
if ( V_118 < V_125 )
V_125 = V_118 ;
V_124 += V_119 ;
if ( V_119 == V_122 )
V_123 = 1 ;
}
if ( V_124 ) {
V_14 -> V_113 -> V_127 . V_128 = V_125 ;
V_112 = V_14 -> V_104 . V_129 ( & V_14 -> V_104 , NULL , V_14 -> V_113 ) ;
if ( V_112 ) {
if ( V_14 -> V_102 )
F_37 ( L_39 V_63 L_20 ,
V_14 -> V_102 ) ;
return V_112 ;
}
}
return V_123 ;
}
static void F_74 ( int T_4 V_12 )
{
V_130 = 1 ;
}
static int F_75 ( struct V_13 * V_14 )
{
struct V_131 V_132 ;
int V_133 = - 1 ;
V_14 -> V_134 = F_76 ( V_135 , V_136 ) ;
if ( V_14 -> V_134 < 0 ) {
F_8 ( L_46 ) ;
goto V_137;
}
V_132 . V_138 . V_95 = V_14 -> V_139 ;
V_132 . V_138 . V_140 = 0 ;
V_132 . V_141 . V_95 = V_14 -> V_139 ;
V_132 . V_141 . V_140 = 0 ;
if ( F_77 ( V_14 -> V_134 , 0 , & V_132 , NULL ) != 0 ) {
F_8 ( L_47 , V_142 ) ;
F_78 ( V_14 -> V_134 ) ;
goto V_137;
}
V_133 = 0 ;
V_137:
return V_133 ;
}
static int F_79 ( struct V_13 * V_14 )
{
T_5 V_143 ;
int V_133 ;
V_133 = F_80 ( V_14 -> V_134 , & V_143 , sizeof( T_5 ) ) ;
if ( V_133 < 0 ) {
if ( V_142 == V_144 )
return 0 ;
F_8 ( L_48 , V_142 ) ;
return - 1 ;
}
if ( V_133 != sizeof( T_5 ) ) {
F_8 ( L_49 ) ;
return - 1 ;
}
if ( V_143 != 1 )
F_36 ( L_50 V_63 L_36 , V_143 - 1 ) ;
F_49 ( V_14 ) ;
F_56 ( V_14 ) ;
F_14 ( V_14 -> V_30 ) ;
V_14 -> V_83 = 0 ;
V_14 -> V_84 = 0 ;
V_14 -> V_102 = 0 ;
return 0 ;
}
static int F_81 ( int V_145 )
{
long V_146 = 0 ;
V_146 = F_82 ( V_145 , V_147 ) ;
if ( V_146 < 0 ) {
F_8 ( L_51 , V_145 ) ;
return - 1 ;
}
if ( F_82 ( V_145 , V_148 , V_146 | V_149 ) < 0 ) {
F_8 ( L_52 , V_145 ) ;
return - 1 ;
}
return 0 ;
}
static
int F_83 ( struct V_150 * V_151 , struct V_150 * V_152 )
{
int V_143 ;
F_84 ( 0 , V_153 , V_151 ) ;
V_143 = getc ( V_154 ) ;
F_84 ( 0 , V_155 , V_152 ) ;
if ( V_143 == 'q' )
return 1 ;
return 0 ;
}
static int F_85 ( struct V_13 * V_14 )
{
struct V_156 * V_157 = NULL ;
int V_158 , V_159 , V_160 , V_112 = - V_115 ;
struct V_150 V_161 , V_162 ;
V_14 -> V_86 = true ;
V_160 = F_64 ( V_14 ) ;
if ( V_160 < 0 )
return V_160 ;
if ( ! F_67 ( V_14 -> V_60 ) ||
! F_40 ( V_14 ) ||
! F_11 ( V_14 ) ) {
goto V_137;
}
F_12 ( V_14 ) ;
F_86 ( 0 , & V_162 ) ;
V_161 = V_162 ;
V_161 . V_163 &= ~ ( V_164 | V_165 ) ;
V_161 . V_166 [ V_167 ] = 0 ;
V_161 . V_166 [ V_168 ] = 0 ;
signal ( V_169 , F_74 ) ;
signal ( V_170 , F_74 ) ;
V_158 = V_14 -> V_121 -> V_158 ;
V_157 = F_20 ( sizeof( struct V_156 ) * ( V_158 + 2 ) ) ;
if ( ! V_157 ) {
V_112 = - V_171 ;
goto V_137;
}
memcpy ( V_157 , V_14 -> V_121 -> V_156 ,
sizeof( struct V_156 ) * V_14 -> V_121 -> V_158 ) ;
if ( F_75 ( V_14 ) < 0 ) {
V_112 = - 1 ;
goto V_137;
}
V_157 [ V_158 ] . V_145 = V_14 -> V_134 ;
V_157 [ V_158 ] . V_172 = V_173 ;
V_158 ++ ;
V_157 [ V_158 ] . V_145 = fileno ( V_154 ) ;
V_157 [ V_158 ] . V_172 = V_173 ;
V_159 = V_158 ;
V_158 ++ ;
if ( F_81 ( fileno ( V_154 ) ) != 0 )
goto V_137;
F_87 ( V_14 -> V_121 ) ;
while ( ! V_130 ) {
int V_133 ;
V_133 = F_73 ( V_14 ) ;
if ( V_133 < 0 )
break;
V_112 = F_79 ( V_14 ) ;
if ( V_112 )
goto V_137;
if ( V_157 [ V_159 ] . V_174 & V_173 )
V_130 = F_83 ( & V_161 , & V_162 ) ;
if ( ! V_133 && ! V_130 )
V_112 = F_88 ( V_157 , V_158 , 100 ) ;
}
F_89 ( V_14 -> V_121 ) ;
if ( V_112 == 0 ) {
F_49 ( V_14 ) ;
F_56 ( V_14 ) ;
}
V_137:
if ( V_14 -> V_134 >= 0 )
F_78 ( V_14 -> V_134 ) ;
free ( V_157 ) ;
return V_112 ;
}
static int F_90 ( struct V_13 * V_14 )
{
int V_112 , V_133 = - 1 ;
struct V_1 * V_175 ;
struct V_176 * V_121 = V_14 -> V_121 ;
F_91 ( V_121 , & V_14 -> V_87 ) ;
F_92 (evlist, pos) {
struct V_177 * V_178 = & V_175 -> V_178 ;
F_93 ( V_175 , V_179 ) ;
F_93 ( V_175 , TIME ) ;
F_93 ( V_175 , V_180 ) ;
F_93 ( V_175 , V_181 ) ;
F_94 ( V_175 , V_182 ) ;
F_94 ( V_175 , V_183 ) ;
F_94 ( V_175 , V_184 ) ;
F_94 ( V_175 , V_185 ) ;
F_94 ( V_175 , V_186 ) ;
V_178 -> V_187 = 0 ;
V_178 -> V_188 = 0 ;
V_178 -> V_189 = 0 ;
V_178 -> V_190 = 1 ;
V_178 -> V_191 = 0 ;
V_178 -> V_192 = 1000 ;
V_178 -> V_193 = 1 ;
}
V_112 = F_95 ( V_121 ) ;
if ( V_112 < 0 ) {
printf ( L_53 , strerror ( V_142 ) ) ;
goto V_137;
}
if ( F_96 ( V_121 , V_14 -> V_87 . V_194 , false ) < 0 ) {
F_97 ( L_54 , strerror ( V_142 ) ) ;
F_98 ( V_121 ) ;
goto V_137;
}
V_133 = 0 ;
V_137:
return V_133 ;
}
static int F_99 ( struct V_13 * V_14 )
{
int V_160 ;
struct V_103 V_195 = {
. V_4 = F_62 ,
. V_188 = V_196 ,
. V_127 = true ,
} ;
struct V_197 V_198 = {
. V_199 = V_14 -> V_200 ,
. V_201 = V_202 ,
} ;
V_14 -> V_104 = V_195 ;
V_14 -> V_113 = F_100 ( & V_198 , false , & V_14 -> V_104 ) ;
if ( ! V_14 -> V_113 ) {
F_8 ( L_55 ) ;
return - V_115 ;
}
if ( ! F_101 ( V_14 -> V_113 , L_56 ) )
return - V_115 ;
V_160 = F_64 ( V_14 ) ;
if ( V_160 < 0 )
return V_160 ;
return F_102 ( V_14 -> V_113 , & V_14 -> V_104 ) ;
}
static int F_103 ( struct V_13 * V_14 )
{
if ( V_14 -> V_203 ) {
V_14 -> V_107 = F_104 ( V_14 -> V_203 ) ;
if ( V_14 -> V_107 == NULL ) {
F_8 ( L_57 ) ;
return - V_115 ;
}
}
return 0 ;
}
static int F_105 ( struct V_13 * V_14 )
{
int V_160 = - V_115 ;
int V_39 = V_14 -> V_60 ;
if ( F_103 ( V_14 ) != 0 )
goto exit;
if ( ! F_67 ( V_39 ) )
goto exit;
if ( ! F_40 ( V_14 ) )
goto exit;
if ( ! F_11 ( V_14 ) )
goto exit;
F_12 ( V_14 ) ;
F_106 () ;
V_160 = F_99 ( V_14 ) ;
if ( V_160 )
goto exit;
F_49 ( V_14 ) ;
F_56 ( V_14 ) ;
exit:
return V_160 ;
}
static int
F_107 ( struct V_13 * V_14 , int V_204 , const char * * V_205 )
{
unsigned int V_206 , V_28 , V_35 , V_207 ;
const char * * V_208 ;
const char * const V_209 [] = {
L_58 ,
L_59 ,
L_60 , L_61 ,
L_62 , L_63 ,
} ;
const char * const * V_210 ;
V_207 = 0 ;
for ( V_210 = V_211 ; * V_210 ; V_210 ++ )
V_207 ++ ;
V_206 = F_108 ( V_209 ) + V_204 + 2 +
2 * V_207 ;
V_208 = calloc ( V_206 + 1 , sizeof( char * ) ) ;
if ( V_208 == NULL )
return - V_171 ;
for ( V_28 = 0 ; V_28 < F_108 ( V_209 ) ; V_28 ++ )
V_208 [ V_28 ] = F_109 ( V_209 [ V_28 ] ) ;
for ( V_35 = 0 ; V_35 < V_207 ; V_35 ++ ) {
V_208 [ V_28 ++ ] = L_64 ;
V_208 [ V_28 ++ ] = F_109 ( V_211 [ V_35 ] ) ;
}
V_208 [ V_28 ++ ] = F_109 ( L_65 ) ;
V_208 [ V_28 ++ ] = F_109 ( V_14 -> V_200 ) ;
for ( V_35 = 1 ; V_35 < ( unsigned int ) V_204 ; V_35 ++ , V_28 ++ )
V_208 [ V_28 ] = V_205 [ V_35 ] ;
return F_110 ( V_28 , V_208 , NULL ) ;
}
static int
F_111 ( struct V_13 * V_14 , int V_204 , const char * * V_205 )
{
const struct V_212 V_213 [] = {
F_112 ( 0 , L_66 , & V_14 -> V_26 , L_67 ,
L_68
L_69 ) ,
F_113 ( 0 , L_70 , & V_14 -> V_60 ,
L_71 ) ,
F_112 ( 'k' , L_72 , & V_14 -> V_72 , L_73 ,
L_74
L_75 ) ,
F_112 ( 'p' , L_76 , & V_14 -> V_203 , L_76 ,
L_77 ) ,
F_114 ()
} ;
const char * const V_214 [] = {
L_78 ,
NULL
} ;
F_115 () ;
if ( V_204 ) {
V_204 = F_116 ( V_204 , V_205 ,
V_213 ,
V_214 , 0 ) ;
if ( V_204 )
F_117 ( V_214 ,
V_213 ) ;
}
return F_105 ( V_14 ) ;
}
static struct V_176 * F_118 ( void )
{
struct V_176 * V_121 ;
char * V_215 , * V_9 , * V_216 ;
int V_112 = - 1 ;
const char * const * V_210 ;
V_121 = F_119 () ;
if ( V_121 == NULL )
return NULL ;
for ( V_210 = V_211 ; * V_210 ; V_210 ++ ) {
V_215 = F_120 ( * V_210 ) ;
if ( V_215 == NULL )
goto V_137;
V_216 = V_215 ;
V_9 = strchr ( V_215 , ':' ) ;
if ( V_9 == NULL ) {
F_8 ( L_79 ,
* V_210 ) ;
free ( V_215 ) ;
goto V_137;
}
* V_9 = '\0' ;
V_9 ++ ;
if ( F_121 ( V_121 , V_216 , V_9 , NULL ) ) {
F_8 ( L_80 , * V_210 ) ;
free ( V_215 ) ;
goto V_137;
}
free ( V_215 ) ;
}
V_112 = 0 ;
V_137:
if ( V_112 ) {
F_122 ( V_121 ) ;
V_121 = NULL ;
}
return V_121 ;
}
static int F_123 ( struct V_13 * V_14 ,
int V_204 , const char * * V_205 )
{
char V_217 [ V_218 ] ;
int V_112 ;
const struct V_212 V_219 [] = {
F_112 ( 'p' , L_76 , & V_14 -> V_87 . V_88 . V_64 , L_76 ,
L_81 ) ,
F_124 ( 'm' , L_82 , & V_14 -> V_87 . V_194 , L_83 ,
L_84 ,
V_220 ) ,
F_125 ( 'v' , L_85 , & V_221 ,
L_86 ) ,
F_126 ( 'a' , L_87 , & V_14 -> V_87 . V_88 . V_89 ,
L_88 ) ,
F_127 ( 'd' , L_89 , & V_14 -> V_139 ,
L_90 ) ,
F_112 ( 0 , L_66 , & V_14 -> V_26 , L_67 ,
L_91 ) ,
F_113 ( 0 , L_70 , & V_14 -> V_60 ,
L_71 ) ,
F_112 ( 'k' , L_72 , & V_14 -> V_72 , L_73 ,
L_74
L_75 ) ,
F_128 ( 0 , L_92 , & V_14 -> V_61 ,
L_93
L_94
L_95 ) ,
F_114 ()
} ;
const char * const V_222 [] = {
L_96 ,
NULL
} ;
struct V_197 V_198 = {
. V_201 = V_223 ,
} ;
V_14 -> V_104 . V_4 = F_62 ;
V_14 -> V_104 . V_188 = V_196 ;
V_14 -> V_104 . exit = V_224 ;
V_14 -> V_104 . V_225 = V_226 ;
V_14 -> V_104 . V_227 = F_59 ;
V_14 -> V_104 . V_127 = true ;
F_129 ( & V_14 -> V_104 ) ;
V_14 -> V_139 = 1 ;
V_14 -> V_87 . V_228 = 1 ;
V_14 -> V_87 . V_194 = 512 ;
V_14 -> V_87 . V_88 . V_229 = false ;
V_14 -> V_87 . V_88 . V_230 = NULL ;
V_14 -> V_87 . V_88 . V_231 = V_232 ;
F_115 () ;
F_130 () ;
V_233 = 0 ;
F_131 ( false ) ;
if ( V_204 ) {
V_204 = F_116 ( V_204 , V_205 , V_219 ,
V_222 , 0 ) ;
if ( V_204 )
F_117 ( V_222 , V_219 ) ;
}
V_14 -> V_61 *= V_234 ;
V_112 = F_132 ( & V_14 -> V_87 . V_88 ) ;
if ( V_112 ) {
F_133 ( & V_14 -> V_87 . V_88 , V_112 , V_217 , V_218 ) ;
F_134 ( L_3 , V_217 ) ;
}
if ( F_135 ( & V_14 -> V_87 . V_88 ) )
V_14 -> V_87 . V_88 . V_89 = true ;
V_14 -> V_121 = F_118 () ;
if ( V_14 -> V_121 == NULL ) {
V_112 = - 1 ;
goto V_137;
}
V_235 . V_236 = V_14 -> V_121 -> V_237 ;
if ( F_136 ( V_14 -> V_121 , & V_14 -> V_87 . V_88 ) < 0 )
F_117 ( V_222 , V_219 ) ;
V_14 -> V_113 = F_100 ( & V_198 , false , & V_14 -> V_104 ) ;
if ( V_14 -> V_113 == NULL ) {
V_112 = - V_171 ;
goto V_137;
}
V_14 -> V_113 -> V_121 = V_14 -> V_121 ;
F_137 ( V_14 -> V_113 ) ;
F_138 ( & V_14 -> V_113 -> V_238 . V_239 , & V_14 -> V_87 . V_88 ,
V_14 -> V_121 -> V_240 , false ) ;
V_112 = F_90 ( V_14 ) ;
if ( V_112 )
goto V_137;
V_112 = F_85 ( V_14 ) ;
V_137:
F_139 ( 0 ) ;
if ( V_14 -> V_113 )
F_140 ( V_14 -> V_113 ) ;
V_14 -> V_113 = NULL ;
if ( V_14 -> V_121 )
F_122 ( V_14 -> V_121 ) ;
return V_112 ;
}
static void F_141 ( void )
{
printf ( L_97 ) ;
printf ( L_98 ) ;
printf ( L_99 ) ;
printf ( L_100 ) ;
printf ( L_101 ) ;
printf ( L_102 ) ;
}
static int F_142 ( const char * V_200 , int V_204 , const char * * V_205 )
{
struct V_13 V_14 = {
. V_200 = V_200 ,
. V_60 = - 1 ,
. V_26 = L_103 ,
. V_72 = L_104 ,
} ;
if ( V_204 == 1 ) {
F_141 () ;
goto V_241;
}
if ( ! strncmp ( V_205 [ 1 ] , L_105 , 3 ) )
return F_107 ( & V_14 , V_204 - 1 , V_205 + 1 ) ;
if ( ! strncmp ( V_205 [ 1 ] , L_106 , 3 ) )
return F_111 ( & V_14 , V_204 - 1 , V_205 + 1 ) ;
#ifdef F_143
if ( ! strncmp ( V_205 [ 1 ] , L_107 , 4 ) )
return F_123 ( & V_14 , V_204 - 1 , V_205 + 1 ) ;
#endif
V_241:
return F_144 ( V_204 , V_205 , NULL ) ;
}
static int F_145 ( const char * V_200 , int V_204 , const char * * V_205 )
{
int V_206 , V_28 = 0 , V_35 ;
const char * * V_208 ;
V_206 = V_204 + 2 ;
V_208 = calloc ( V_206 + 1 , sizeof( char * ) ) ;
V_208 [ V_28 ++ ] = F_120 ( L_58 ) ;
V_208 [ V_28 ++ ] = F_120 ( L_65 ) ;
V_208 [ V_28 ++ ] = F_120 ( V_200 ) ;
for ( V_35 = 1 ; V_35 < V_204 ; V_35 ++ , V_28 ++ )
V_208 [ V_28 ] = V_205 [ V_35 ] ;
F_22 ( V_28 != V_206 ) ;
return F_110 ( V_28 , V_208 , NULL ) ;
}
static int F_146 ( const char * V_200 , int V_204 , const char * * V_205 )
{
int V_206 , V_28 = 0 , V_35 ;
const char * * V_208 ;
V_206 = V_204 + 2 ;
V_208 = calloc ( V_206 + 1 , sizeof( char * ) ) ;
V_208 [ V_28 ++ ] = F_120 ( L_108 ) ;
V_208 [ V_28 ++ ] = F_120 ( L_109 ) ;
V_208 [ V_28 ++ ] = F_120 ( V_200 ) ;
for ( V_35 = 1 ; V_35 < V_204 ; V_35 ++ , V_28 ++ )
V_208 [ V_28 ] = V_205 [ V_35 ] ;
F_22 ( V_28 != V_206 ) ;
return F_147 ( V_28 , V_208 , NULL ) ;
}
static int
F_148 ( const char * V_200 , int V_204 , const char * * V_205 )
{
int V_206 , V_28 = 0 , V_35 ;
const char * * V_208 ;
V_206 = V_204 + 2 ;
V_208 = calloc ( V_206 + 1 , sizeof( char * ) ) ;
V_208 [ V_28 ++ ] = F_120 ( L_110 ) ;
V_208 [ V_28 ++ ] = F_120 ( L_109 ) ;
V_208 [ V_28 ++ ] = F_120 ( V_200 ) ;
for ( V_35 = 1 ; V_35 < V_204 ; V_35 ++ , V_28 ++ )
V_208 [ V_28 ] = V_205 [ V_35 ] ;
F_22 ( V_28 != V_206 ) ;
return F_149 ( V_28 , V_208 , NULL ) ;
}
int F_150 ( int V_204 , const char * * V_205 , const char * T_6 V_12 )
{
const char * V_200 = NULL ;
const struct V_212 V_242 [] = {
F_112 ( 'i' , L_111 , & V_200 , L_112 ,
L_113 ) ,
F_112 ( 'o' , L_114 , & V_200 , L_112 ,
L_115 ) ,
F_126 ( 0 , L_116 , & V_243 ,
L_117 ) ,
F_126 ( 0 , L_118 , & V_244 ,
L_119 ) ,
F_112 ( 0 , L_120 , & V_235 . V_245 , L_121 ,
L_122
L_123 ) ,
F_112 ( 0 , L_124 , & V_235 . V_246 ,
L_112 , L_125 ) ,
F_112 ( 0 , L_126 , & V_235 . V_247 ,
L_112 , L_127 ) ,
F_112 ( 0 , L_128 , & V_235 . V_248 ,
L_112 , L_129 ) ,
F_125 ( 'v' , L_85 , & V_221 ,
L_86 ) ,
F_114 ()
} ;
const char * const V_249 [] = { L_130 , L_58 , L_108 , L_131 ,
L_110 , L_132 , NULL } ;
const char * V_250 [] = { NULL , NULL } ;
V_244 = 0 ;
V_243 = 1 ;
V_204 = F_151 ( V_204 , V_205 , V_242 , V_249 , V_250 ,
V_251 ) ;
if ( ! V_204 )
F_117 ( V_250 , V_242 ) ;
if ( ! V_244 )
V_243 = 1 ;
if ( ! V_200 ) {
V_200 = F_152 () ;
if ( ! V_200 ) {
F_8 ( L_133 ) ;
return - V_171 ;
}
}
if ( ! strncmp ( V_205 [ 0 ] , L_105 , 3 ) )
return F_145 ( V_200 , V_204 , V_205 ) ;
else if ( ! strncmp ( V_205 [ 0 ] , L_106 , 3 ) )
return F_146 ( V_200 , V_204 , V_205 ) ;
else if ( ! strncmp ( V_205 [ 0 ] , L_131 , 4 ) )
return F_153 ( V_204 , V_205 , NULL ) ;
else if ( ! strncmp ( V_205 [ 0 ] , L_130 , 3 ) )
return F_154 ( V_204 , V_205 , NULL ) ;
else if ( ! strncmp ( V_205 [ 0 ] , L_110 , 12 ) )
return F_148 ( V_200 , V_204 , V_205 ) ;
#ifdef F_155
else if ( ! strncmp ( V_205 [ 0 ] , L_132 , 4 ) )
return F_142 ( V_200 , V_204 , V_205 ) ;
#endif
else
F_117 ( V_250 , V_242 ) ;
return 0 ;
}
