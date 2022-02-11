static const char * F_1 ( void )
{
const char * V_1 ;
if ( V_2 && ! V_3 )
V_1 = F_2 ( L_1 ) ;
else if ( ! V_2 && V_3 )
V_1 = F_2 ( L_2 ) ;
else
V_1 = F_2 ( L_3 ) ;
return V_1 ;
}
void F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
V_9 -> V_10 = 0 ;
V_9 -> V_9 = F_4 ( V_5 , V_7 , V_11 ) ;
}
bool F_5 ( struct V_4 * V_5 )
{
return ! strcmp ( V_5 -> V_12 , V_13 ) ;
}
bool F_6 ( struct V_4 * V_5 ,
struct V_6 * V_7 , struct V_8 * V_9 )
{
if ( F_5 ( V_5 ) ) {
F_3 ( V_5 , V_7 , V_9 ) ;
return true ;
}
return false ;
}
bool F_7 ( struct V_4 * V_5 )
{
return ! strcmp ( V_5 -> V_12 , V_14 ) ;
}
bool F_8 ( struct V_4 * V_5 ,
struct V_6 * V_7 V_15 ,
struct V_8 * V_9 V_15 )
{
return F_7 ( V_5 ) ;
}
static const char * F_9 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
T_1 V_20 )
{
while ( V_19 -> V_21 != NULL ) {
if ( V_19 -> V_20 == V_20 )
return V_19 -> V_21 ;
V_19 ++ ;
}
F_10 ( L_4 ,
( unsigned long long ) V_20 , V_17 -> V_22 ) ;
return L_5 ;
}
void F_11 ( struct V_16 * V_17 ,
struct V_8 * V_9 ,
char * V_23 )
{
const char * V_24 = F_9 ( V_17 , V_9 -> V_25 ,
V_9 -> V_9 ) ;
F_12 ( V_23 , V_26 , L_6 , V_24 ) ;
}
static bool F_13 ( struct V_16 * V_17 )
{
struct V_27 * V_28 = V_27 ;
for ( V_28 = V_27 ; V_28 -> V_12 ; V_28 ++ ) {
if ( ! strcmp ( V_28 -> V_12 , V_17 -> V_29 ) ) {
V_17 -> V_28 = V_28 -> V_30 ;
return true ;
}
}
return false ;
}
static void F_14 ( struct V_16 * V_17 )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ )
F_15 ( & V_17 -> V_33 [ V_31 ] ) ;
}
static void F_16 ( struct V_34 * V_33 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 ;
unsigned int V_31 ;
int V_38 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_35 = & V_33 [ V_31 ] ;
F_17 (event, head, hash_entry) {
V_37 -> V_39 . time = 0 ;
F_18 ( & V_37 -> V_39 . V_40 ) ;
for ( V_38 = 0 ; V_38 < V_37 -> V_41 ; ++ V_38 ) {
V_37 -> V_42 [ V_38 ] . time = 0 ;
F_18 ( & V_37 -> V_42 [ V_38 ] . V_40 ) ;
}
}
}
}
static int F_19 ( T_1 V_9 )
{
return V_9 & ( V_32 - 1 ) ;
}
static bool F_20 ( struct V_36 * V_37 , int V_43 )
{
int V_44 = V_37 -> V_41 ;
void * V_45 ;
if ( V_43 < V_37 -> V_41 )
return true ;
while ( V_37 -> V_41 <= V_43 )
V_37 -> V_41 += V_46 ;
V_45 = V_37 -> V_42 ;
V_37 -> V_42 = realloc ( V_37 -> V_42 ,
V_37 -> V_41 * sizeof( * V_37 -> V_42 ) ) ;
if ( ! V_37 -> V_42 ) {
free ( V_45 ) ;
F_10 ( L_7 ) ;
return false ;
}
memset ( V_37 -> V_42 + V_44 , 0 ,
( V_37 -> V_41 - V_44 ) * sizeof( * V_37 -> V_42 ) ) ;
return true ;
}
static struct V_36 * F_21 ( struct V_8 * V_9 )
{
struct V_36 * V_37 ;
V_37 = F_22 ( sizeof( * V_37 ) ) ;
if ( ! V_37 ) {
F_10 ( L_7 ) ;
return NULL ;
}
V_37 -> V_9 = * V_9 ;
F_18 ( & V_37 -> V_39 . V_40 ) ;
return V_37 ;
}
static struct V_36 * F_23 ( struct V_16 * V_17 ,
struct V_8 * V_9 )
{
struct V_36 * V_37 ;
struct V_34 * V_35 ;
F_24 ( V_9 -> V_9 == V_47 ) ;
V_35 = & V_17 -> V_33 [ F_19 ( V_9 -> V_9 ) ] ;
F_17 (event, head, hash_entry) {
if ( V_37 -> V_9 . V_9 == V_9 -> V_9 && V_37 -> V_9 . V_10 == V_9 -> V_10 )
return V_37 ;
}
V_37 = F_21 ( V_9 ) ;
if ( ! V_37 )
return NULL ;
F_25 ( & V_37 -> V_48 , V_35 ) ;
return V_37 ;
}
static bool F_26 ( struct V_16 * V_17 ,
struct V_49 * V_50 ,
struct V_8 * V_9 , T_1 V_51 )
{
struct V_36 * V_37 = NULL ;
if ( V_9 -> V_9 != V_47 )
V_37 = F_23 ( V_17 , V_9 ) ;
V_50 -> V_52 = V_37 ;
V_50 -> V_53 = V_51 ;
return true ;
}
static void
F_27 ( struct V_54 * V_55 , T_1 V_56 )
{
V_55 -> time += V_56 ;
F_28 ( & V_55 -> V_40 , V_56 ) ;
}
static double F_29 ( int V_43 , struct V_36 * V_37 )
{
struct V_54 * V_55 = & V_37 -> V_39 ;
if ( V_43 != - 1 )
V_55 = & V_37 -> V_42 [ V_43 ] ;
return F_30 ( F_31 ( & V_55 -> V_40 ) ,
F_32 ( & V_55 -> V_40 ) ) ;
}
static bool F_33 ( struct V_36 * V_37 , int V_43 ,
T_1 V_56 )
{
if ( V_43 == - 1 ) {
F_27 ( & V_37 -> V_39 , V_56 ) ;
return true ;
}
if ( ! F_20 ( V_37 , V_43 ) )
return false ;
F_27 ( & V_37 -> V_42 [ V_43 ] , V_56 ) ;
return true ;
}
static bool F_34 ( struct V_16 * V_17 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_57 * V_58 ;
V_58 = V_17 -> V_28 -> V_58 ;
if ( ! V_58 )
return false ;
for (; V_58 -> V_12 ; V_58 ++ ) {
if ( ! strcmp ( V_5 -> V_12 , V_58 -> V_12 ) ) {
V_58 -> V_59 ( V_5 , V_7 , V_9 ) ;
return true ;
}
}
return false ;
}
static bool F_35 ( struct V_16 * V_17 ,
struct V_49 * V_50 ,
struct V_8 * V_9 ,
struct V_6 * V_7 V_15 )
{
struct V_36 * V_37 = NULL ;
if ( V_9 -> V_9 != V_47 )
V_37 = F_23 ( V_17 , V_9 ) ;
V_50 -> V_52 = V_37 ;
return true ;
}
static bool F_36 ( const char * V_37 )
{
const char * const * V_60 ;
for ( V_60 = V_61 ; * V_60 ; V_60 ++ )
if ( ! strcmp ( V_37 , * V_60 ) )
return true ;
return false ;
}
static bool F_37 ( struct V_16 * V_17 ,
struct V_49 * V_50 ,
struct V_8 * V_9 ,
struct V_6 * V_7 )
{
struct V_36 * V_37 ;
T_1 V_62 , V_56 ;
int V_42 ;
if ( V_17 -> V_63 == - 1 )
V_42 = - 1 ;
else
V_42 = V_50 -> V_43 ;
V_37 = V_50 -> V_52 ;
V_62 = V_50 -> V_53 ;
if ( ! V_62 )
return true ;
if ( ! V_37 && V_9 -> V_9 == V_47 )
return true ;
if ( ! V_37 )
V_37 = F_23 ( V_17 , V_9 ) ;
if ( ! V_37 )
return false ;
V_50 -> V_52 = NULL ;
V_50 -> V_53 = 0 ;
if ( V_7 -> time < V_62 ) {
F_38 ( L_8 ) ;
return true ;
}
V_56 = V_7 -> time - V_62 ;
if ( V_17 -> V_64 && V_56 > V_17 -> V_64 ) {
char V_23 [ V_26 ] ;
V_17 -> V_28 -> V_65 ( V_17 , & V_37 -> V_9 , V_23 ) ;
if ( ! F_36 ( V_23 ) ) {
F_39 ( L_9 V_66 L_10 V_66 L_11 ,
V_7 -> time , V_7 -> V_67 , V_50 -> V_43 ,
V_23 , V_56 / V_68 ) ;
}
}
return F_33 ( V_37 , V_42 , V_56 ) ;
}
static
struct V_49 * F_40 ( struct V_69 * V_69 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
if ( ! F_41 ( V_69 ) && F_7 ( V_5 ) ) {
struct V_49 * V_50 ;
V_50 = F_22 ( sizeof( * V_50 ) ) ;
if ( ! V_50 ) {
F_10 ( L_12 , V_70 ) ;
return NULL ;
}
V_50 -> V_43 = F_4 ( V_5 , V_7 ,
V_71 ) ;
F_42 ( V_69 , V_50 ) ;
}
return F_41 ( V_69 ) ;
}
static bool F_43 ( struct V_16 * V_17 ,
struct V_69 * V_69 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_49 * V_50 ;
struct V_8 V_9 = { . V_9 = V_47 ,
. V_25 = V_17 -> V_25 } ;
V_50 = F_40 ( V_69 , V_5 , V_7 ) ;
if ( ! V_50 )
return true ;
if ( ( V_17 -> V_63 != - 1 ) &&
( V_17 -> V_63 != V_50 -> V_43 ) )
return true ;
if ( V_17 -> V_28 -> V_72 ( V_5 , V_7 , & V_9 ) )
return F_26 ( V_17 , V_50 , & V_9 , V_7 -> time ) ;
if ( F_34 ( V_17 , V_5 , V_7 , & V_9 ) )
return F_35 ( V_17 , V_50 , & V_9 , V_7 ) ;
if ( V_17 -> V_28 -> V_73 ( V_5 , V_7 , & V_9 ) )
return F_37 ( V_17 , V_50 , & V_9 , V_7 ) ;
return true ;
}
static bool F_44 ( struct V_16 * V_17 )
{
int V_31 ;
for ( V_31 = 0 ; V_74 [ V_31 ] . V_12 ; V_31 ++ ) {
if ( ! strcmp ( V_74 [ V_31 ] . V_12 , V_17 -> V_75 ) ) {
V_17 -> V_76 = V_74 [ V_31 ] . V_9 ;
return true ;
}
}
F_10 ( L_13 , V_17 -> V_75 ) ;
return false ;
}
static void F_45 ( struct V_77 * V_78 , struct V_36 * V_37 ,
T_2 V_79 , int V_42 )
{
struct V_80 * * V_81 = & V_78 -> V_80 ;
struct V_80 * V_82 = NULL ;
struct V_36 * V_83 ;
while ( * V_81 ) {
V_83 = F_46 ( * V_81 , struct V_36 , V_81 ) ;
V_82 = * V_81 ;
if ( V_79 ( V_37 , V_83 , V_42 ) )
V_81 = & ( * V_81 ) -> V_84 ;
else
V_81 = & ( * V_81 ) -> V_85 ;
}
F_47 ( & V_37 -> V_81 , V_82 , V_81 ) ;
F_48 ( & V_37 -> V_81 , V_78 ) ;
}
static void
F_49 ( struct V_16 * V_17 , struct V_36 * V_37 )
{
int V_42 = V_17 -> V_63 ;
V_17 -> V_86 += F_50 ( V_37 , V_42 ) ;
V_17 -> V_87 += F_51 ( V_37 , V_42 ) ;
}
static bool F_52 ( struct V_36 * V_37 , int V_42 )
{
return ! ! F_50 ( V_37 , V_42 ) ;
}
static void F_53 ( struct V_16 * V_17 )
{
unsigned int V_31 ;
int V_42 = V_17 -> V_63 ;
struct V_36 * V_37 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
F_17 (event, &kvm->kvm_events_cache[i], hash_entry) {
if ( F_52 ( V_37 , V_42 ) ) {
F_49 ( V_17 , V_37 ) ;
F_45 ( & V_17 -> V_78 , V_37 ,
V_17 -> V_76 , V_42 ) ;
}
}
}
}
static struct V_36 * F_54 ( struct V_77 * V_78 )
{
struct V_80 * V_88 = F_55 ( V_78 ) ;
if ( ! V_88 )
return NULL ;
F_56 ( V_88 , V_78 ) ;
return F_46 ( V_88 , struct V_36 , V_81 ) ;
}
static void F_57 ( struct V_16 * V_17 )
{
int V_42 = V_17 -> V_63 ;
F_39 ( L_14 ) ;
if ( V_17 -> V_89 . V_90 . V_91 )
F_39 ( L_15 ) ;
else if ( V_17 -> V_89 . V_90 . V_67 )
F_39 ( L_16 , V_17 -> V_89 . V_90 . V_67 ) ;
else
F_39 ( L_17 ) ;
if ( V_42 == - 1 )
F_39 ( L_18 ) ;
else
F_39 ( L_19 , V_42 ) ;
}
static void F_58 ( void )
{
char V_92 [ 64 ] ;
struct V_93 V_94 ;
struct V_95 V_96 ;
F_59 ( & V_94 , NULL ) ;
if ( localtime_r ( & V_94 . V_97 , & V_96 ) ) {
strftime ( V_92 , sizeof( V_92 ) , L_20 , & V_96 ) ;
F_39 ( L_21 , V_92 , V_94 . V_98 ) ;
} else
F_39 ( L_22 ) ;
return;
}
static void F_60 ( struct V_16 * V_17 )
{
char V_23 [ V_26 ] ;
struct V_36 * V_37 ;
int V_42 = V_17 -> V_63 ;
if ( V_17 -> V_99 ) {
puts ( V_100 ) ;
F_58 () ;
}
F_39 ( L_23 ) ;
F_57 ( V_17 ) ;
F_39 ( L_24 , V_26 , V_17 -> V_28 -> V_12 ) ;
F_39 ( L_25 , L_26 ) ;
F_39 ( L_27 , L_28 ) ;
F_39 ( L_27 , L_29 ) ;
F_39 ( L_30 , L_31 ) ;
F_39 ( L_30 , L_32 ) ;
F_39 ( L_33 , L_34 ) ;
F_39 ( L_23 ) ;
while ( ( V_37 = F_54 ( & V_17 -> V_78 ) ) ) {
T_1 V_101 , V_102 , V_103 , V_104 ;
V_101 = F_50 ( V_37 , V_42 ) ;
V_102 = F_51 ( V_37 , V_42 ) ;
V_103 = F_61 ( V_37 , V_42 ) ;
V_104 = F_62 ( V_37 , V_42 ) ;
V_17 -> V_28 -> V_65 ( V_17 , & V_37 -> V_9 , V_23 ) ;
F_39 ( L_24 , V_26 , V_23 ) ;
F_39 ( L_35 , ( unsigned long long ) V_101 ) ;
F_39 ( L_36 , ( double ) V_101 / V_17 -> V_86 * 100 ) ;
F_39 ( L_36 , ( double ) V_102 / V_17 -> V_87 * 100 ) ;
F_39 ( L_37 , ( double ) V_104 / V_68 ) ;
F_39 ( L_37 , ( double ) V_103 / V_68 ) ;
F_39 ( L_38 , ( double ) V_102 / V_101 / V_68 ,
F_29 ( V_42 , V_37 ) ) ;
F_39 ( L_39 ) ;
}
F_39 ( L_40 V_66 L_41 ,
V_17 -> V_86 , V_17 -> V_87 / ( double ) V_68 ) ;
if ( V_17 -> V_105 )
F_39 ( L_42 V_66 L_23 , V_17 -> V_105 ) ;
}
static int F_63 ( struct V_106 * V_107 ,
union V_108 * V_37 V_15 ,
struct V_6 * V_7 V_15 ,
struct V_109 * V_109 V_15 )
{
struct V_16 * V_17 = F_46 ( V_107 , struct V_16 , V_107 ) ;
V_17 -> V_105 ++ ;
return 0 ;
}
static bool F_64 ( struct V_16 * V_17 ,
struct V_6 * V_7 )
{
if ( V_17 -> V_110 && F_65 ( V_17 -> V_110 , V_7 -> V_67 ) == NULL )
return true ;
return false ;
}
static int F_66 ( struct V_106 * V_107 ,
union V_108 * V_37 ,
struct V_6 * V_7 ,
struct V_4 * V_5 ,
struct V_109 * V_109 )
{
int V_111 = 0 ;
struct V_69 * V_69 ;
struct V_16 * V_17 = F_46 ( V_107 , struct V_16 ,
V_107 ) ;
if ( F_64 ( V_17 , V_7 ) )
return 0 ;
V_69 = F_67 ( V_109 , V_7 -> V_67 , V_7 -> V_112 ) ;
if ( V_69 == NULL ) {
F_38 ( L_43 ,
V_37 -> V_113 . type ) ;
return - 1 ;
}
if ( ! F_43 ( V_17 , V_69 , V_5 , V_7 ) )
V_111 = - 1 ;
F_68 ( V_69 ) ;
return V_111 ;
}
static int F_69 ( struct V_16 * V_17 )
{
char V_114 [ 64 ] , * V_115 ;
int V_111 ;
if ( V_17 -> V_99 ) {
V_111 = F_70 ( V_114 , sizeof( V_114 ) ) ;
if ( V_111 != 0 ) {
F_10 ( L_44 ) ;
return V_111 ;
}
V_115 = V_114 ;
} else
V_115 = V_17 -> V_116 -> V_113 . V_117 . V_115 ;
if ( ! V_115 ) {
F_10 ( L_44 ) ;
return - V_118 ;
}
V_111 = F_71 ( V_17 , V_115 ) ;
if ( V_111 == - V_119 )
F_10 ( L_45 , V_115 ) ;
return V_111 ;
}
static bool F_72 ( int V_42 )
{
if ( V_42 != - 1 && V_42 < 0 ) {
F_10 ( L_46 , V_42 ) ;
return false ;
}
return true ;
}
static T_3 F_73 ( struct V_16 * V_17 , int V_120 ,
T_1 * V_121 )
{
union V_108 * V_37 ;
struct V_6 V_7 ;
T_3 V_122 = 0 ;
int V_111 ;
* V_121 = V_123 ;
while ( ( V_37 = F_74 ( V_17 -> V_124 , V_120 ) ) != NULL ) {
V_111 = F_75 ( V_17 -> V_124 , V_37 , & V_7 ) ;
if ( V_111 ) {
F_76 ( V_17 -> V_124 , V_120 ) ;
F_10 ( L_47 ) ;
return - 1 ;
}
V_111 = F_77 ( V_17 -> V_116 , V_37 , & V_7 , 0 ) ;
F_76 ( V_17 -> V_124 , V_120 ) ;
if ( V_111 ) {
F_10 ( L_48 , V_111 ) ;
return - 1 ;
}
if ( V_122 == 0 )
* V_121 = V_7 . time ;
V_122 ++ ;
if ( V_122 == V_125 )
break;
}
return V_122 ;
}
static int F_78 ( struct V_16 * V_17 )
{
int V_31 , V_111 , V_126 = 0 ;
T_3 V_122 , V_127 = 0 ;
T_1 V_128 = V_123 , V_121 ;
for ( V_31 = 0 ; V_31 < V_17 -> V_124 -> V_129 ; V_31 ++ ) {
V_122 = F_73 ( V_17 , V_31 , & V_121 ) ;
if ( V_122 < 0 )
return - 1 ;
if ( V_121 < V_128 )
V_128 = V_121 ;
V_127 += V_122 ;
if ( V_122 == V_125 )
V_126 = 1 ;
}
if ( V_127 ) {
struct V_130 * V_131 = & V_17 -> V_116 -> V_130 ;
V_131 -> V_132 = V_128 ;
V_111 = F_79 ( V_131 , V_133 ) ;
if ( V_111 ) {
if ( V_17 -> V_105 )
F_39 ( L_42 V_66 L_23 ,
V_17 -> V_105 ) ;
return V_111 ;
}
}
return V_126 ;
}
static void F_80 ( int T_4 V_15 )
{
V_134 = 1 ;
}
static int F_81 ( struct V_16 * V_17 )
{
struct V_135 V_136 ;
int V_137 = - 1 ;
V_17 -> V_138 = F_82 ( V_139 , V_140 ) ;
if ( V_17 -> V_138 < 0 ) {
F_10 ( L_49 ) ;
goto V_141;
}
V_136 . V_142 . V_97 = V_17 -> V_143 ;
V_136 . V_142 . V_144 = 0 ;
V_136 . V_145 . V_97 = V_17 -> V_143 ;
V_136 . V_145 . V_144 = 0 ;
if ( F_83 ( V_17 -> V_138 , 0 , & V_136 , NULL ) != 0 ) {
F_10 ( L_50 , V_146 ) ;
F_84 ( V_17 -> V_138 ) ;
goto V_141;
}
V_137 = 0 ;
V_141:
return V_137 ;
}
static int F_85 ( struct V_16 * V_17 )
{
T_5 V_147 ;
int V_137 ;
V_137 = F_86 ( V_17 -> V_138 , & V_147 , sizeof( T_5 ) ) ;
if ( V_137 < 0 ) {
if ( V_146 == V_148 )
return 0 ;
F_10 ( L_51 , V_146 ) ;
return - 1 ;
}
if ( V_137 != sizeof( T_5 ) ) {
F_10 ( L_52 ) ;
return - 1 ;
}
if ( V_147 != 1 )
F_38 ( L_53 V_66 L_39 , V_147 - 1 ) ;
F_53 ( V_17 ) ;
F_60 ( V_17 ) ;
F_16 ( V_17 -> V_33 ) ;
V_17 -> V_86 = 0 ;
V_17 -> V_87 = 0 ;
V_17 -> V_105 = 0 ;
return 0 ;
}
static int F_87 ( int V_149 )
{
long V_150 = 0 ;
V_150 = F_88 ( V_149 , V_151 ) ;
if ( V_150 < 0 ) {
F_10 ( L_54 , V_149 ) ;
return - 1 ;
}
if ( F_88 ( V_149 , V_152 , V_150 | V_153 ) < 0 ) {
F_10 ( L_55 , V_149 ) ;
return - 1 ;
}
return 0 ;
}
static int F_89 ( void )
{
int V_147 ;
V_147 = getc ( V_154 ) ;
if ( V_147 == 'q' )
return 1 ;
return 0 ;
}
static int F_90 ( struct V_16 * V_17 )
{
int V_155 , V_156 , V_111 = - V_118 ;
struct V_157 V_158 ;
V_17 -> V_99 = true ;
V_156 = F_69 ( V_17 ) ;
if ( V_156 < 0 )
return V_156 ;
if ( ! F_72 ( V_17 -> V_63 ) ||
! F_44 ( V_17 ) ||
! F_13 ( V_17 ) ) {
goto V_141;
}
F_91 ( & V_158 ) ;
F_14 ( V_17 ) ;
signal ( V_159 , F_80 ) ;
signal ( V_160 , F_80 ) ;
if ( F_81 ( V_17 ) < 0 ) {
V_111 = - 1 ;
goto V_141;
}
if ( F_92 ( V_17 -> V_124 , V_17 -> V_138 ) < 0 )
goto V_141;
V_155 = F_92 ( V_17 -> V_124 , fileno ( V_154 ) ) ;
if ( V_155 < 0 )
goto V_141;
if ( F_87 ( fileno ( V_154 ) ) != 0 )
goto V_141;
F_93 ( V_17 -> V_124 ) ;
while ( ! V_134 ) {
struct V_161 * V_162 = & V_17 -> V_124 -> V_163 ;
int V_137 ;
V_137 = F_78 ( V_17 ) ;
if ( V_137 < 0 )
break;
V_111 = F_85 ( V_17 ) ;
if ( V_111 )
goto V_141;
if ( V_162 -> V_164 [ V_155 ] . V_165 & V_166 )
V_134 = F_89 () ;
if ( ! V_137 && ! V_134 )
V_111 = F_94 ( V_162 , 100 ) ;
}
F_95 ( V_17 -> V_124 ) ;
if ( V_111 == 0 ) {
F_53 ( V_17 ) ;
F_60 ( V_17 ) ;
}
V_141:
if ( V_17 -> V_138 >= 0 )
F_84 ( V_17 -> V_138 ) ;
F_96 ( 0 , V_167 , & V_158 ) ;
return V_111 ;
}
static int F_97 ( struct V_16 * V_17 )
{
int V_111 , V_137 = - 1 ;
struct V_4 * V_168 ;
struct V_169 * V_124 = V_17 -> V_124 ;
char V_170 [ V_171 ] ;
F_98 ( V_124 , & V_17 -> V_89 , NULL ) ;
F_99 (evlist, pos) {
struct V_172 * V_173 = & V_168 -> V_173 ;
F_100 ( V_168 , V_174 ) ;
F_100 ( V_168 , TIME ) ;
F_100 ( V_168 , V_175 ) ;
F_100 ( V_168 , V_176 ) ;
F_101 ( V_168 , V_177 ) ;
F_101 ( V_168 , V_178 ) ;
F_101 ( V_168 , V_179 ) ;
F_101 ( V_168 , V_180 ) ;
F_101 ( V_168 , V_181 ) ;
V_173 -> V_182 = 0 ;
V_173 -> V_183 = 0 ;
V_173 -> V_184 = 0 ;
V_173 -> V_185 = 1 ;
V_173 -> V_186 = 0 ;
V_173 -> V_187 = 1000 ;
V_173 -> V_188 = 1 ;
}
V_111 = F_102 ( V_124 ) ;
if ( V_111 < 0 ) {
printf ( L_56 ,
F_103 ( V_146 , V_170 , sizeof( V_170 ) ) ) ;
goto V_141;
}
if ( F_104 ( V_124 , V_17 -> V_89 . V_189 , false ) < 0 ) {
F_105 ( L_57 ,
F_103 ( V_146 , V_170 , sizeof( V_170 ) ) ) ;
F_106 ( V_124 ) ;
goto V_141;
}
V_137 = 0 ;
V_141:
return V_137 ;
}
static int F_107 ( struct V_16 * V_17 )
{
int V_156 ;
struct V_106 V_190 = {
. V_7 = F_66 ,
. V_183 = V_191 ,
. V_192 = V_193 ,
. V_130 = true ,
} ;
struct V_194 V_195 = {
. V_196 = V_17 -> V_197 ,
. V_198 = V_199 ,
. V_200 = V_17 -> V_200 ,
} ;
V_17 -> V_107 = V_190 ;
V_17 -> V_116 = F_108 ( & V_195 , false , & V_17 -> V_107 ) ;
if ( ! V_17 -> V_116 ) {
F_10 ( L_58 ) ;
return - 1 ;
}
F_109 ( & V_17 -> V_116 -> V_113 . V_117 ) ;
if ( ! F_110 ( V_17 -> V_116 , L_59 ) ) {
V_156 = - V_118 ;
goto V_201;
}
V_156 = F_69 ( V_17 ) ;
if ( V_156 < 0 )
goto V_201;
V_156 = F_111 ( V_17 -> V_116 ) ;
V_201:
F_112 ( V_17 -> V_116 ) ;
return V_156 ;
}
static int F_113 ( struct V_16 * V_17 )
{
if ( V_17 -> V_89 . V_90 . V_67 ) {
V_17 -> V_110 = F_114 ( V_17 -> V_89 . V_90 . V_67 ) ;
if ( V_17 -> V_110 == NULL ) {
F_10 ( L_60 ) ;
return - V_118 ;
}
}
return 0 ;
}
static int F_115 ( struct V_16 * V_17 )
{
int V_156 = - V_118 ;
int V_42 = V_17 -> V_63 ;
if ( F_113 ( V_17 ) != 0 )
goto exit;
if ( ! F_72 ( V_42 ) )
goto exit;
if ( ! F_44 ( V_17 ) )
goto exit;
if ( ! F_13 ( V_17 ) )
goto exit;
F_14 ( V_17 ) ;
F_116 () ;
V_156 = F_107 ( V_17 ) ;
if ( V_156 )
goto exit;
F_53 ( V_17 ) ;
F_60 ( V_17 ) ;
exit:
return V_156 ;
}
int __weak F_117 ( struct V_16 * V_17 V_15 )
{
return 0 ;
}
static int
F_118 ( struct V_16 * V_17 , int V_202 , const char * * V_203 )
{
unsigned int V_204 , V_31 , V_38 , V_205 ;
const char * * V_206 ;
const char * const V_207 [] = {
L_61 ,
L_62 ,
L_63 , L_64 ,
L_65 , L_66 ,
} ;
const char * const V_208 [] = {
L_67 ,
NULL
} ;
const char * const * V_209 ;
int V_156 ;
V_205 = 0 ;
V_156 = F_117 ( V_17 ) ;
if ( V_156 < 0 ) {
F_10 ( L_68 ) ;
return V_156 ;
}
for ( V_209 = V_210 ; * V_209 ; V_209 ++ )
V_205 ++ ;
V_204 = F_119 ( V_207 ) + V_202 + 2 +
2 * V_205 ;
V_206 = calloc ( V_204 + 1 , sizeof( char * ) ) ;
if ( V_206 == NULL )
return - V_211 ;
for ( V_31 = 0 ; V_31 < F_119 ( V_207 ) ; V_31 ++ )
V_206 [ V_31 ] = F_120 ( V_207 [ V_31 ] ) ;
for ( V_38 = 0 ; V_38 < V_205 ; V_38 ++ ) {
V_206 [ V_31 ++ ] = L_69 ;
V_206 [ V_31 ++ ] = F_120 ( V_210 [ V_38 ] ) ;
}
V_206 [ V_31 ++ ] = F_120 ( L_70 ) ;
V_206 [ V_31 ++ ] = F_120 ( V_17 -> V_197 ) ;
for ( V_38 = 1 ; V_38 < ( unsigned int ) V_202 ; V_38 ++ , V_31 ++ )
V_206 [ V_31 ] = V_203 [ V_38 ] ;
F_121 ( V_212 , 'e' , L_71 , V_213 ) ;
F_121 ( V_212 , 0 , L_72 , V_213 ) ;
F_121 ( V_212 , 'R' , L_73 , V_213 ) ;
F_121 ( V_212 , 'F' , L_74 , V_214 ) ;
F_121 ( V_212 , 0 , L_75 , V_214 ) ;
F_121 ( V_212 , 'g' , NULL , V_214 ) ;
F_121 ( V_212 , 0 , L_76 , V_214 ) ;
F_121 ( V_212 , 'd' , L_77 , V_214 ) ;
F_121 ( V_212 , 'T' , L_78 , V_214 ) ;
F_121 ( V_212 , 'P' , L_79 , V_214 ) ;
F_121 ( V_212 , 'n' , L_80 , V_214 ) ;
F_121 ( V_212 , 'N' , L_81 , V_214 ) ;
F_121 ( V_212 , 'B' , L_82 , V_214 ) ;
F_121 ( V_212 , 'G' , L_83 , V_214 ) ;
F_121 ( V_212 , 'b' , L_84 , V_214 ) ;
F_121 ( V_212 , 'j' , L_85 , V_214 ) ;
F_121 ( V_212 , 'W' , L_86 , V_214 ) ;
F_121 ( V_212 , 0 , L_87 , V_214 ) ;
V_215 = V_208 ;
return F_122 ( V_31 , V_206 ) ;
}
static int
F_123 ( struct V_16 * V_17 , int V_202 , const char * * V_203 )
{
const struct V_216 V_217 [] = {
F_124 ( 0 , L_71 , & V_17 -> V_29 , L_88 ,
L_89
L_90 ) ,
F_125 ( 0 , L_91 , & V_17 -> V_63 ,
L_92 ) ,
F_124 ( 'k' , L_93 , & V_17 -> V_75 , L_94 ,
L_95
L_96 ) ,
F_124 ( 'p' , L_97 , & V_17 -> V_89 . V_90 . V_67 , L_97 ,
L_98 ) ,
F_126 ( 'f' , L_99 , & V_17 -> V_200 , L_100 ) ,
F_127 ()
} ;
const char * const V_218 [] = {
L_101 ,
NULL
} ;
if ( V_202 ) {
V_202 = F_128 ( V_202 , V_203 ,
V_217 ,
V_218 , 0 ) ;
if ( V_202 )
F_129 ( V_218 ,
V_217 ) ;
}
if ( ! V_17 -> V_89 . V_90 . V_67 )
V_17 -> V_89 . V_90 . V_91 = true ;
return F_115 ( V_17 ) ;
}
static struct V_169 * F_130 ( void )
{
struct V_169 * V_124 ;
char * V_219 , * V_12 , * V_220 ;
int V_111 = - 1 ;
const char * const * V_209 ;
V_124 = F_131 () ;
if ( V_124 == NULL )
return NULL ;
for ( V_209 = V_210 ; * V_209 ; V_209 ++ ) {
V_219 = F_2 ( * V_209 ) ;
if ( V_219 == NULL )
goto V_141;
V_220 = V_219 ;
V_12 = strchr ( V_219 , ':' ) ;
if ( V_12 == NULL ) {
F_10 ( L_102 ,
* V_209 ) ;
free ( V_219 ) ;
goto V_141;
}
* V_12 = '\0' ;
V_12 ++ ;
if ( F_132 ( V_124 , V_220 , V_12 , NULL ) ) {
F_10 ( L_103 , * V_209 ) ;
free ( V_219 ) ;
goto V_141;
}
free ( V_219 ) ;
}
V_111 = 0 ;
V_141:
if ( V_111 ) {
F_133 ( V_124 ) ;
V_124 = NULL ;
}
return V_124 ;
}
static int F_134 ( struct V_16 * V_17 ,
int V_202 , const char * * V_203 )
{
char V_221 [ V_222 ] ;
int V_111 ;
const struct V_216 V_223 [] = {
F_124 ( 'p' , L_97 , & V_17 -> V_89 . V_90 . V_67 , L_97 ,
L_104 ) ,
F_135 ( 'm' , L_105 , & V_17 -> V_89 . V_189 , L_106 ,
L_107 ,
V_224 ) ,
F_136 ( 'v' , L_108 , & V_225 ,
L_109 ) ,
F_126 ( 'a' , L_110 , & V_17 -> V_89 . V_90 . V_91 ,
L_111 ) ,
F_137 ( 'd' , L_112 , & V_17 -> V_143 ,
L_113 ) ,
F_124 ( 0 , L_71 , & V_17 -> V_29 , L_88 ,
L_114
L_115 ) ,
F_125 ( 0 , L_91 , & V_17 -> V_63 ,
L_92 ) ,
F_124 ( 'k' , L_93 , & V_17 -> V_75 , L_94 ,
L_95
L_96 ) ,
F_138 ( 0 , L_116 , & V_17 -> V_64 ,
L_117
L_118
L_119 ) ,
F_137 ( 0 , L_120 , & V_17 -> V_89 . V_226 ,
L_121 ) ,
F_127 ()
} ;
const char * const V_227 [] = {
L_122 ,
NULL
} ;
struct V_194 V_195 = {
. V_198 = V_228 ,
} ;
V_17 -> V_107 . V_7 = F_66 ;
V_17 -> V_107 . V_183 = V_191 ;
V_17 -> V_107 . exit = V_229 ;
V_17 -> V_107 . V_230 = V_231 ;
V_17 -> V_107 . V_232 = F_63 ;
V_17 -> V_107 . V_192 = V_193 ;
V_17 -> V_107 . V_130 = true ;
F_139 ( & V_17 -> V_107 ) ;
V_17 -> V_143 = 1 ;
V_17 -> V_89 . V_233 = 1 ;
V_17 -> V_89 . V_189 = 512 ;
V_17 -> V_89 . V_90 . V_234 = false ;
V_17 -> V_89 . V_90 . V_235 = NULL ;
V_17 -> V_89 . V_90 . V_236 = V_237 ;
V_17 -> V_89 . V_226 = 500 ;
F_109 ( NULL ) ;
F_140 () ;
V_238 = 0 ;
if ( V_202 ) {
V_202 = F_128 ( V_202 , V_203 , V_223 ,
V_227 , 0 ) ;
if ( V_202 )
F_129 ( V_227 , V_223 ) ;
}
V_17 -> V_64 *= V_68 ;
V_111 = F_141 ( & V_17 -> V_89 . V_90 ) ;
if ( V_111 ) {
F_142 ( & V_17 -> V_89 . V_90 , V_111 , V_221 , V_222 ) ;
F_143 ( L_6 , V_221 ) ;
}
if ( F_144 ( & V_17 -> V_89 . V_90 ) )
V_17 -> V_89 . V_90 . V_91 = true ;
V_111 = F_117 ( V_17 ) ;
if ( V_111 < 0 ) {
F_10 ( L_68 ) ;
return V_111 ;
}
V_17 -> V_124 = F_130 () ;
if ( V_17 -> V_124 == NULL ) {
V_111 = - 1 ;
goto V_141;
}
V_239 . V_240 = V_17 -> V_124 -> V_241 ;
if ( F_145 ( V_17 -> V_124 , & V_17 -> V_89 . V_90 ) < 0 )
F_129 ( V_227 , V_223 ) ;
V_17 -> V_116 = F_108 ( & V_195 , false , & V_17 -> V_107 ) ;
if ( V_17 -> V_116 == NULL ) {
V_111 = - 1 ;
goto V_141;
}
V_17 -> V_116 -> V_124 = V_17 -> V_124 ;
F_146 ( V_17 -> V_116 ) ;
F_147 ( & V_17 -> V_116 -> V_130 , true ) ;
F_148 ( & V_17 -> V_116 -> V_242 . V_243 , & V_17 -> V_89 . V_90 ,
V_17 -> V_124 -> V_244 , false , V_17 -> V_89 . V_226 ) ;
V_111 = F_97 ( V_17 ) ;
if ( V_111 )
goto V_141;
V_111 = F_90 ( V_17 ) ;
V_141:
F_112 ( V_17 -> V_116 ) ;
V_17 -> V_116 = NULL ;
F_133 ( V_17 -> V_124 ) ;
return V_111 ;
}
static void F_149 ( void )
{
printf ( L_123 ) ;
printf ( L_124 ) ;
printf ( L_125 ) ;
printf ( L_126 ) ;
printf ( L_127 ) ;
printf ( L_128 ) ;
}
static int F_150 ( const char * V_197 , int V_202 , const char * * V_203 )
{
struct V_16 V_17 = {
. V_197 = V_197 ,
. V_63 = - 1 ,
. V_29 = L_129 ,
. V_75 = L_130 ,
} ;
if ( V_202 == 1 ) {
F_149 () ;
goto V_245;
}
if ( ! strncmp ( V_203 [ 1 ] , L_131 , 3 ) )
return F_118 ( & V_17 , V_202 - 1 , V_203 + 1 ) ;
if ( ! strncmp ( V_203 [ 1 ] , L_132 , 3 ) )
return F_123 ( & V_17 , V_202 - 1 , V_203 + 1 ) ;
#ifdef F_151
if ( ! strncmp ( V_203 [ 1 ] , L_133 , 4 ) )
return F_134 ( & V_17 , V_202 - 1 , V_203 + 1 ) ;
#endif
V_245:
return F_152 ( V_202 , V_203 ) ;
}
static int F_153 ( const char * V_197 , int V_202 , const char * * V_203 )
{
int V_204 , V_31 = 0 , V_38 ;
const char * * V_206 ;
V_204 = V_202 + 2 ;
V_206 = calloc ( V_204 + 1 , sizeof( char * ) ) ;
V_206 [ V_31 ++ ] = F_2 ( L_61 ) ;
V_206 [ V_31 ++ ] = F_2 ( L_70 ) ;
V_206 [ V_31 ++ ] = F_2 ( V_197 ) ;
for ( V_38 = 1 ; V_38 < V_202 ; V_38 ++ , V_31 ++ )
V_206 [ V_31 ] = V_203 [ V_38 ] ;
F_24 ( V_31 != V_204 ) ;
return F_122 ( V_31 , V_206 ) ;
}
static int F_154 ( const char * V_197 , int V_202 , const char * * V_203 )
{
int V_204 , V_31 = 0 , V_38 ;
const char * * V_206 ;
V_204 = V_202 + 2 ;
V_206 = calloc ( V_204 + 1 , sizeof( char * ) ) ;
V_206 [ V_31 ++ ] = F_2 ( L_134 ) ;
V_206 [ V_31 ++ ] = F_2 ( L_135 ) ;
V_206 [ V_31 ++ ] = F_2 ( V_197 ) ;
for ( V_38 = 1 ; V_38 < V_202 ; V_38 ++ , V_31 ++ )
V_206 [ V_31 ] = V_203 [ V_38 ] ;
F_24 ( V_31 != V_204 ) ;
return F_155 ( V_31 , V_206 ) ;
}
static int
F_156 ( const char * V_197 , int V_202 , const char * * V_203 )
{
int V_204 , V_31 = 0 , V_38 ;
const char * * V_206 ;
V_204 = V_202 + 2 ;
V_206 = calloc ( V_204 + 1 , sizeof( char * ) ) ;
V_206 [ V_31 ++ ] = F_2 ( L_136 ) ;
V_206 [ V_31 ++ ] = F_2 ( L_135 ) ;
V_206 [ V_31 ++ ] = F_2 ( V_197 ) ;
for ( V_38 = 1 ; V_38 < V_202 ; V_38 ++ , V_31 ++ )
V_206 [ V_31 ] = V_203 [ V_38 ] ;
F_24 ( V_31 != V_204 ) ;
return F_157 ( V_31 , V_206 ) ;
}
int F_158 ( int V_202 , const char * * V_203 )
{
const char * V_197 = NULL ;
const struct V_216 V_246 [] = {
F_124 ( 'i' , L_137 , & V_197 , L_138 ,
L_139 ) ,
F_124 ( 'o' , L_140 , & V_197 , L_138 ,
L_141 ) ,
F_126 ( 0 , L_142 , & V_3 ,
L_143 ) ,
F_126 ( 0 , L_144 , & V_2 ,
L_145 ) ,
F_124 ( 0 , L_146 , & V_239 . V_247 , L_147 ,
L_148
L_149 ) ,
F_124 ( 0 , L_150 , & V_239 . V_248 ,
L_138 , L_151 ) ,
F_124 ( 0 , L_152 , & V_239 . V_249 ,
L_138 , L_153 ) ,
F_124 ( 0 , L_154 , & V_239 . V_250 ,
L_138 , L_155 ) ,
F_136 ( 'v' , L_108 , & V_225 ,
L_109 ) ,
F_127 ()
} ;
const char * const V_251 [] = { L_156 , L_61 , L_134 , L_157 ,
L_136 , L_158 , NULL } ;
const char * V_252 [] = { NULL , NULL } ;
V_2 = 0 ;
V_3 = 1 ;
V_202 = F_159 ( V_202 , V_203 , V_246 , V_251 , V_252 ,
V_253 ) ;
if ( ! V_202 )
F_129 ( V_252 , V_246 ) ;
if ( ! V_2 )
V_3 = 1 ;
if ( ! V_197 ) {
V_197 = F_1 () ;
if ( ! V_197 ) {
F_10 ( L_159 ) ;
return - V_211 ;
}
}
if ( ! strncmp ( V_203 [ 0 ] , L_131 , 3 ) )
return F_153 ( V_197 , V_202 , V_203 ) ;
else if ( ! strncmp ( V_203 [ 0 ] , L_132 , 3 ) )
return F_154 ( V_197 , V_202 , V_203 ) ;
else if ( ! strncmp ( V_203 [ 0 ] , L_157 , 4 ) )
return F_160 ( V_202 , V_203 ) ;
else if ( ! strncmp ( V_203 [ 0 ] , L_156 , 3 ) )
return F_161 ( V_202 , V_203 ) ;
else if ( ! strncmp ( V_203 [ 0 ] , L_136 , 12 ) )
return F_156 ( V_197 , V_202 , V_203 ) ;
#ifdef F_162
else if ( ! strncmp ( V_203 [ 0 ] , L_158 , 4 ) )
return F_150 ( V_197 , V_202 , V_203 ) ;
#endif
else
F_129 ( V_252 , V_246 ) ;
return 0 ;
}
