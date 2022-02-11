static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
V_6 -> V_7 = 0 ;
V_6 -> V_6 = F_2 ( V_2 , V_4 , L_1 ) ;
}
static bool F_3 ( struct V_1 * V_2 )
{
return ! strcmp ( V_2 -> V_8 , L_2 ) ;
}
static bool F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
if ( F_3 ( V_2 ) ) {
F_1 ( V_2 , V_4 , V_6 ) ;
return true ;
}
return false ;
}
static bool F_5 ( struct V_1 * V_2 )
{
return ! strcmp ( V_2 -> V_8 , L_3 ) ;
}
static bool F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 V_9 ,
struct V_5 * V_6 V_9 )
{
return F_5 ( V_2 ) ;
}
static const char * F_7 ( struct V_10 * V_11 , T_1 V_12 )
{
int V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_11 -> V_17 ;
while ( V_13 -- ) {
if ( V_16 -> V_12 == V_12 )
return V_16 -> V_18 ;
V_16 ++ ;
}
F_8 ( L_4 ,
( unsigned long long ) V_12 , V_11 -> V_19 ) ;
return L_5 ;
}
static void F_9 ( struct V_10 * V_11 ,
struct V_5 * V_6 ,
char V_20 [ 20 ] )
{
const char * V_21 = F_7 ( V_11 , V_6 -> V_6 ) ;
F_10 ( V_20 , 20 , L_6 , V_21 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
V_6 -> V_6 = F_2 ( V_2 , V_4 , L_7 ) ;
V_6 -> V_7 = F_2 ( V_2 , V_4 , L_8 ) ;
}
static bool F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
if ( F_3 ( V_2 ) )
return true ;
if ( ! strcmp ( V_2 -> V_8 , L_9 ) &&
F_2 ( V_2 , V_4 , L_8 ) == V_22 ) {
F_11 ( V_2 , V_4 , V_6 ) ;
return true ;
}
return false ;
}
static bool F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( F_5 ( V_2 ) )
return true ;
if ( ! strcmp ( V_2 -> V_8 , L_9 ) &&
F_2 ( V_2 , V_4 , L_8 ) == V_23 ) {
F_11 ( V_2 , V_4 , V_6 ) ;
return true ;
}
return false ;
}
static void F_14 ( struct V_10 * V_11 V_9 ,
struct V_5 * V_6 ,
char V_20 [ 20 ] )
{
F_10 ( V_20 , 20 , L_10 , ( unsigned long ) V_6 -> V_6 ,
V_6 -> V_7 == V_22 ? L_11 : L_12 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
V_6 -> V_6 = F_2 ( V_2 , V_4 , L_13 ) ;
V_6 -> V_7 = F_2 ( V_2 , V_4 , L_14 ) ;
}
static bool F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! strcmp ( V_2 -> V_8 , L_15 ) ) {
F_15 ( V_2 , V_4 , V_6 ) ;
return true ;
}
return false ;
}
static bool F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 V_9 ,
struct V_5 * V_6 V_9 )
{
return F_5 ( V_2 ) ;
}
static void F_18 ( struct V_10 * V_11 V_9 ,
struct V_5 * V_6 ,
char V_20 [ 20 ] )
{
F_10 ( V_20 , 20 , L_16 , ( unsigned long long ) V_6 -> V_6 ,
V_6 -> V_7 ? L_17 : L_18 ) ;
}
static bool F_19 ( struct V_10 * V_11 )
{
bool V_24 = true ;
if ( ! strcmp ( V_11 -> V_25 , L_19 ) )
V_11 -> V_26 = & V_27 ;
else if ( ! strcmp ( V_11 -> V_25 , L_20 ) )
V_11 -> V_26 = & V_28 ;
else if ( ! strcmp ( V_11 -> V_25 , L_21 ) )
V_11 -> V_26 = & V_29 ;
else {
F_8 ( L_22 , V_11 -> V_25 ) ;
V_24 = false ;
}
return V_24 ;
}
static void F_20 ( struct V_10 * V_11 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_30 ; V_13 ++ )
F_21 ( & V_11 -> V_31 [ V_13 ] ) ;
}
static void F_22 ( struct V_32 * V_31 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 ;
unsigned int V_13 ;
int V_36 ;
for ( V_13 = 0 ; V_13 < V_30 ; V_13 ++ ) {
V_33 = & V_31 [ V_13 ] ;
F_23 (event, head, hash_entry) {
V_35 -> V_37 . time = 0 ;
F_24 ( & V_35 -> V_37 . V_38 ) ;
for ( V_36 = 0 ; V_36 < V_35 -> V_39 ; ++ V_36 ) {
V_35 -> V_40 [ V_36 ] . time = 0 ;
F_24 ( & V_35 -> V_40 [ V_36 ] . V_38 ) ;
}
}
}
}
static int F_25 ( T_1 V_6 )
{
return V_6 & ( V_30 - 1 ) ;
}
static bool F_26 ( struct V_34 * V_35 , int V_41 )
{
int V_42 = V_35 -> V_39 ;
void * V_43 ;
if ( V_41 < V_35 -> V_39 )
return true ;
while ( V_35 -> V_39 <= V_41 )
V_35 -> V_39 += V_44 ;
V_43 = V_35 -> V_40 ;
V_35 -> V_40 = realloc ( V_35 -> V_40 ,
V_35 -> V_39 * sizeof( * V_35 -> V_40 ) ) ;
if ( ! V_35 -> V_40 ) {
free ( V_43 ) ;
F_8 ( L_23 ) ;
return false ;
}
memset ( V_35 -> V_40 + V_42 , 0 ,
( V_35 -> V_39 - V_42 ) * sizeof( * V_35 -> V_40 ) ) ;
return true ;
}
static struct V_34 * F_27 ( struct V_5 * V_6 )
{
struct V_34 * V_35 ;
V_35 = F_28 ( sizeof( * V_35 ) ) ;
if ( ! V_35 ) {
F_8 ( L_23 ) ;
return NULL ;
}
V_35 -> V_6 = * V_6 ;
return V_35 ;
}
static struct V_34 * F_29 ( struct V_10 * V_11 ,
struct V_5 * V_6 )
{
struct V_34 * V_35 ;
struct V_32 * V_33 ;
F_30 ( V_6 -> V_6 == V_45 ) ;
V_33 = & V_11 -> V_31 [ F_25 ( V_6 -> V_6 ) ] ;
F_23 (event, head, hash_entry) {
if ( V_35 -> V_6 . V_6 == V_6 -> V_6 && V_35 -> V_6 . V_7 == V_6 -> V_7 )
return V_35 ;
}
V_35 = F_27 ( V_6 ) ;
if ( ! V_35 )
return NULL ;
F_31 ( & V_35 -> V_46 , V_33 ) ;
return V_35 ;
}
static bool F_32 ( struct V_10 * V_11 ,
struct V_47 * V_48 ,
struct V_5 * V_6 , T_1 V_49 )
{
struct V_34 * V_35 = NULL ;
if ( V_6 -> V_6 != V_45 )
V_35 = F_29 ( V_11 , V_6 ) ;
V_48 -> V_50 = V_35 ;
V_48 -> V_51 = V_49 ;
return true ;
}
static void
F_33 ( struct V_52 * V_53 , T_1 V_54 )
{
V_53 -> time += V_54 ;
F_34 ( & V_53 -> V_38 , V_54 ) ;
}
static double F_35 ( int V_41 , struct V_34 * V_35 )
{
struct V_52 * V_53 = & V_35 -> V_37 ;
if ( V_41 != - 1 )
V_53 = & V_35 -> V_40 [ V_41 ] ;
return F_36 ( F_37 ( & V_53 -> V_38 ) ,
F_38 ( & V_53 -> V_38 ) ) ;
}
static bool F_39 ( struct V_34 * V_35 , int V_41 ,
T_1 V_54 )
{
if ( V_41 == - 1 ) {
F_33 ( & V_35 -> V_37 , V_54 ) ;
return true ;
}
if ( ! F_26 ( V_35 , V_41 ) )
return false ;
F_33 ( & V_35 -> V_40 [ V_41 ] , V_54 ) ;
return true ;
}
static bool F_40 ( struct V_10 * V_11 ,
struct V_47 * V_48 ,
struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_34 * V_35 ;
T_1 V_55 , V_54 ;
int V_40 ;
if ( V_11 -> V_56 == - 1 )
V_40 = - 1 ;
else
V_40 = V_48 -> V_41 ;
V_35 = V_48 -> V_50 ;
V_55 = V_48 -> V_51 ;
if ( ! V_55 )
return true ;
if ( ! V_35 && V_6 -> V_6 == V_45 )
return true ;
if ( ! V_35 )
V_35 = F_29 ( V_11 , V_6 ) ;
if ( ! V_35 )
return false ;
V_48 -> V_50 = NULL ;
V_48 -> V_51 = 0 ;
if ( V_4 -> time < V_55 ) {
F_41 ( L_24 ) ;
return true ;
}
V_54 = V_4 -> time - V_55 ;
if ( V_11 -> V_57 && V_54 > V_11 -> V_57 ) {
char V_20 [ 32 ] ;
V_11 -> V_26 -> V_58 ( V_11 , & V_35 -> V_6 , V_20 ) ;
if ( strcmp ( V_20 , L_25 ) ) {
F_42 ( L_26 V_59 L_27 V_59 L_28 ,
V_4 -> time , V_4 -> V_60 , V_48 -> V_41 ,
V_20 , V_54 / 1000 ) ;
}
}
return F_39 ( V_35 , V_40 , V_54 ) ;
}
static
struct V_47 * F_43 ( struct V_61 * V_61 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_61 -> V_62 && F_5 ( V_2 ) ) {
struct V_47 * V_48 ;
V_48 = F_28 ( sizeof( * V_48 ) ) ;
if ( ! V_48 ) {
F_8 ( L_29 , V_63 ) ;
return NULL ;
}
V_48 -> V_41 = F_2 ( V_2 , V_4 , L_30 ) ;
V_61 -> V_62 = V_48 ;
}
return V_61 -> V_62 ;
}
static bool F_44 ( struct V_10 * V_11 ,
struct V_61 * V_61 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_47 * V_48 ;
struct V_5 V_6 = { . V_6 = V_45 } ;
V_48 = F_43 ( V_61 , V_2 , V_4 ) ;
if ( ! V_48 )
return true ;
if ( ( V_11 -> V_56 != - 1 ) &&
( V_11 -> V_56 != V_48 -> V_41 ) )
return true ;
if ( V_11 -> V_26 -> V_64 ( V_2 , V_4 , & V_6 ) )
return F_32 ( V_11 , V_48 , & V_6 , V_4 -> time ) ;
if ( V_11 -> V_26 -> V_65 ( V_2 , V_4 , & V_6 ) )
return F_40 ( V_11 , V_48 , & V_6 , V_4 ) ;
return true ;
}
static bool F_45 ( struct V_10 * V_11 )
{
int V_13 ;
for ( V_13 = 0 ; V_66 [ V_13 ] . V_8 ; V_13 ++ ) {
if ( ! strcmp ( V_66 [ V_13 ] . V_8 , V_11 -> V_67 ) ) {
V_11 -> V_68 = V_66 [ V_13 ] . V_6 ;
return true ;
}
}
F_8 ( L_31 , V_11 -> V_67 ) ;
return false ;
}
static void F_46 ( struct V_69 * V_70 , struct V_34 * V_35 ,
T_2 V_71 , int V_40 )
{
struct V_72 * * V_73 = & V_70 -> V_72 ;
struct V_72 * V_74 = NULL ;
struct V_34 * V_75 ;
while ( * V_73 ) {
V_75 = F_47 ( * V_73 , struct V_34 , V_73 ) ;
V_74 = * V_73 ;
if ( V_71 ( V_35 , V_75 , V_40 ) )
V_73 = & ( * V_73 ) -> V_76 ;
else
V_73 = & ( * V_73 ) -> V_77 ;
}
F_48 ( & V_35 -> V_73 , V_74 , V_73 ) ;
F_49 ( & V_35 -> V_73 , V_70 ) ;
}
static void
F_50 ( struct V_10 * V_11 , struct V_34 * V_35 )
{
int V_40 = V_11 -> V_56 ;
V_11 -> V_78 += F_51 ( V_35 , V_40 ) ;
V_11 -> V_79 += F_52 ( V_35 , V_40 ) ;
}
static bool F_53 ( struct V_34 * V_35 , int V_40 )
{
return ! ! F_51 ( V_35 , V_40 ) ;
}
static void F_54 ( struct V_10 * V_11 )
{
unsigned int V_13 ;
int V_40 = V_11 -> V_56 ;
struct V_34 * V_35 ;
for ( V_13 = 0 ; V_13 < V_30 ; V_13 ++ ) {
F_23 (event, &kvm->kvm_events_cache[i], hash_entry) {
if ( F_53 ( V_35 , V_40 ) ) {
F_50 ( V_11 , V_35 ) ;
F_46 ( & V_11 -> V_70 , V_35 ,
V_11 -> V_68 , V_40 ) ;
}
}
}
}
static struct V_34 * F_55 ( struct V_69 * V_70 )
{
struct V_72 * V_80 = F_56 ( V_70 ) ;
if ( ! V_80 )
return NULL ;
F_57 ( V_80 , V_70 ) ;
return F_47 ( V_80 , struct V_34 , V_73 ) ;
}
static void F_58 ( struct V_10 * V_11 )
{
int V_40 = V_11 -> V_56 ;
F_42 ( L_32 ) ;
if ( V_11 -> V_81 ) {
if ( V_11 -> V_82 . V_83 . V_84 )
F_42 ( L_33 ) ;
else if ( V_11 -> V_82 . V_83 . V_60 )
F_42 ( L_34 , V_11 -> V_82 . V_83 . V_60 ) ;
else
F_42 ( L_35 ) ;
}
if ( V_40 == - 1 )
F_42 ( L_36 ) ;
else
F_42 ( L_37 , V_40 ) ;
}
static void F_59 ( void )
{
char V_85 [ 64 ] ;
struct V_86 V_87 ;
struct V_88 V_89 ;
F_60 ( & V_87 , NULL ) ;
if ( localtime_r ( & V_87 . V_90 , & V_89 ) ) {
strftime ( V_85 , sizeof( V_85 ) , L_38 , & V_89 ) ;
F_42 ( L_39 , V_85 , V_87 . V_91 ) ;
} else
F_42 ( L_40 ) ;
return;
}
static void F_61 ( struct V_10 * V_11 )
{
char V_20 [ 20 ] ;
struct V_34 * V_35 ;
int V_40 = V_11 -> V_56 ;
if ( V_11 -> V_81 ) {
puts ( V_92 ) ;
F_59 () ;
}
F_42 ( L_41 ) ;
F_58 ( V_11 ) ;
F_42 ( L_42 , V_11 -> V_26 -> V_8 ) ;
F_42 ( L_43 , L_44 ) ;
F_42 ( L_45 , L_46 ) ;
F_42 ( L_45 , L_47 ) ;
F_42 ( L_43 , L_48 ) ;
F_42 ( L_43 , L_49 ) ;
F_42 ( L_50 , L_51 ) ;
F_42 ( L_41 ) ;
while ( ( V_35 = F_55 ( & V_11 -> V_70 ) ) ) {
T_1 V_93 , V_94 , V_95 , V_96 ;
V_93 = F_51 ( V_35 , V_40 ) ;
V_94 = F_52 ( V_35 , V_40 ) ;
V_95 = F_62 ( V_35 , V_40 ) ;
V_96 = F_63 ( V_35 , V_40 ) ;
V_11 -> V_26 -> V_58 ( V_11 , & V_35 -> V_6 , V_20 ) ;
F_42 ( L_42 , V_20 ) ;
F_42 ( L_52 , ( unsigned long long ) V_93 ) ;
F_42 ( L_53 , ( double ) V_93 / V_11 -> V_78 * 100 ) ;
F_42 ( L_53 , ( double ) V_94 / V_11 -> V_79 * 100 ) ;
F_42 ( L_54 V_59 L_55 , V_96 / 1000 ) ;
F_42 ( L_54 V_59 L_55 , V_95 / 1000 ) ;
F_42 ( L_56 , ( double ) V_94 / V_93 / 1e3 ,
F_35 ( V_40 , V_35 ) ) ;
F_42 ( L_57 ) ;
}
F_42 ( L_58 V_59 L_59 ,
V_11 -> V_78 , V_11 -> V_79 / 1e3 ) ;
if ( V_11 -> V_97 )
F_42 ( L_60 V_59 L_41 , V_11 -> V_97 ) ;
}
static int F_64 ( struct V_98 * V_99 ,
union V_100 * V_35 V_9 ,
struct V_3 * V_4 V_9 ,
struct V_101 * V_101 V_9 )
{
struct V_10 * V_11 = F_47 ( V_99 , struct V_10 , V_99 ) ;
V_11 -> V_97 ++ ;
return 0 ;
}
static bool F_65 ( struct V_10 * V_11 ,
struct V_3 * V_4 )
{
if ( V_11 -> V_102 && F_66 ( V_11 -> V_102 , V_4 -> V_60 ) == NULL )
return true ;
return false ;
}
static int F_67 ( struct V_98 * V_99 ,
union V_100 * V_35 ,
struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_101 * V_101 )
{
struct V_61 * V_61 ;
struct V_10 * V_11 = F_47 ( V_99 , struct V_10 ,
V_99 ) ;
if ( F_65 ( V_11 , V_4 ) )
return 0 ;
V_61 = F_68 ( V_101 , V_4 -> V_60 , V_4 -> V_103 ) ;
if ( V_61 == NULL ) {
F_41 ( L_61 ,
V_35 -> V_104 . type ) ;
return - 1 ;
}
if ( ! F_44 ( V_11 , V_61 , V_2 , V_4 ) )
return - 1 ;
return 0 ;
}
static int F_69 ( struct V_10 * V_11 )
{
char V_105 [ 64 ] , * V_106 ;
int V_107 , V_108 ;
if ( V_11 -> V_81 ) {
V_107 = F_70 ( V_105 , sizeof( V_105 ) ) ;
if ( V_107 != 0 ) {
F_8 ( L_62 ) ;
return V_107 ;
}
V_106 = V_105 ;
} else
V_106 = V_11 -> V_109 -> V_104 . V_110 . V_106 ;
if ( strstr ( V_106 , L_63 ) )
V_108 = 1 ;
else if ( strstr ( V_106 , L_64 ) )
V_108 = 0 ;
else {
F_8 ( L_65 , V_106 ) ;
return - V_111 ;
}
if ( V_108 == 1 ) {
V_11 -> V_17 = V_112 ;
V_11 -> V_14 = F_71 ( V_112 ) ;
V_11 -> V_19 = L_66 ;
}
return 0 ;
}
static bool F_72 ( int V_40 )
{
if ( V_40 != - 1 && V_40 < 0 ) {
F_8 ( L_67 , V_40 ) ;
return false ;
}
return true ;
}
static T_3 F_73 ( struct V_10 * V_11 , int V_113 ,
T_1 * V_114 )
{
union V_100 * V_35 ;
struct V_3 V_4 ;
T_3 V_115 = 0 ;
int V_107 ;
* V_114 = V_116 ;
while ( ( V_35 = F_74 ( V_11 -> V_117 , V_113 ) ) != NULL ) {
V_107 = F_75 ( V_11 -> V_117 , V_35 , & V_4 ) ;
if ( V_107 ) {
F_76 ( V_11 -> V_117 , V_113 ) ;
F_8 ( L_68 ) ;
return - 1 ;
}
V_107 = F_77 ( V_11 -> V_109 , V_35 , & V_4 , 0 ) ;
F_76 ( V_11 -> V_117 , V_113 ) ;
if ( V_107 ) {
F_8 ( L_69 , V_107 ) ;
return - 1 ;
}
if ( V_115 == 0 )
* V_114 = V_4 . time ;
V_115 ++ ;
if ( V_115 == V_118 )
break;
}
return V_115 ;
}
static int F_78 ( struct V_10 * V_11 )
{
int V_13 , V_107 , V_119 = 0 ;
T_3 V_115 , V_120 = 0 ;
T_1 V_121 = V_116 , V_114 ;
for ( V_13 = 0 ; V_13 < V_11 -> V_117 -> V_122 ; V_13 ++ ) {
V_115 = F_73 ( V_11 , V_13 , & V_114 ) ;
if ( V_115 < 0 )
return - 1 ;
if ( V_114 < V_121 )
V_121 = V_114 ;
V_120 += V_115 ;
if ( V_115 == V_118 )
V_119 = 1 ;
}
if ( V_120 ) {
V_11 -> V_109 -> V_123 . V_124 = V_121 ;
V_107 = V_11 -> V_99 . V_125 ( & V_11 -> V_99 , NULL , V_11 -> V_109 ) ;
if ( V_107 ) {
if ( V_11 -> V_97 )
F_42 ( L_60 V_59 L_41 ,
V_11 -> V_97 ) ;
return V_107 ;
}
}
return V_119 ;
}
static void F_79 ( int T_4 V_9 )
{
V_126 = 1 ;
}
static int F_80 ( struct V_10 * V_11 )
{
struct V_127 V_128 ;
int V_129 = - 1 ;
V_11 -> V_130 = F_81 ( V_131 , V_132 ) ;
if ( V_11 -> V_130 < 0 ) {
F_8 ( L_70 ) ;
goto V_133;
}
V_128 . V_134 . V_90 = V_11 -> V_135 ;
V_128 . V_134 . V_136 = 0 ;
V_128 . V_137 . V_90 = V_11 -> V_135 ;
V_128 . V_137 . V_136 = 0 ;
if ( F_82 ( V_11 -> V_130 , 0 , & V_128 , NULL ) != 0 ) {
F_8 ( L_71 , V_138 ) ;
F_83 ( V_11 -> V_130 ) ;
goto V_133;
}
V_129 = 0 ;
V_133:
return V_129 ;
}
static int F_84 ( struct V_10 * V_11 )
{
T_5 V_139 ;
int V_129 ;
V_129 = F_85 ( V_11 -> V_130 , & V_139 , sizeof( T_5 ) ) ;
if ( V_129 < 0 ) {
if ( V_138 == V_140 )
return 0 ;
F_8 ( L_72 , V_138 ) ;
return - 1 ;
}
if ( V_129 != sizeof( T_5 ) ) {
F_8 ( L_73 ) ;
return - 1 ;
}
if ( V_139 != 1 )
F_41 ( L_74 V_59 L_57 , V_139 - 1 ) ;
F_54 ( V_11 ) ;
F_61 ( V_11 ) ;
F_22 ( V_11 -> V_31 ) ;
V_11 -> V_78 = 0 ;
V_11 -> V_79 = 0 ;
V_11 -> V_97 = 0 ;
return 0 ;
}
static int F_86 ( int V_141 )
{
long V_142 = 0 ;
V_142 = F_87 ( V_141 , V_143 ) ;
if ( V_142 < 0 ) {
F_8 ( L_75 , V_141 ) ;
return - 1 ;
}
if ( F_87 ( V_141 , V_144 , V_142 | V_145 ) < 0 ) {
F_8 ( L_76 , V_141 ) ;
return - 1 ;
}
return 0 ;
}
static
int F_88 ( struct V_146 * V_147 , struct V_146 * V_148 )
{
int V_139 ;
F_89 ( 0 , V_149 , V_147 ) ;
V_139 = getc ( V_150 ) ;
F_89 ( 0 , V_151 , V_148 ) ;
if ( V_139 == 'q' )
return 1 ;
return 0 ;
}
static int F_90 ( struct V_10 * V_11 )
{
struct V_152 * V_153 = NULL ;
int V_154 , V_155 , V_24 , V_107 = - V_156 ;
struct V_146 V_157 , V_158 ;
V_11 -> V_81 = true ;
V_24 = F_69 ( V_11 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( ! F_72 ( V_11 -> V_56 ) ||
! F_45 ( V_11 ) ||
! F_19 ( V_11 ) ) {
goto V_133;
}
F_20 ( V_11 ) ;
F_91 ( 0 , & V_158 ) ;
V_157 = V_158 ;
V_157 . V_159 &= ~ ( V_160 | V_161 ) ;
V_157 . V_162 [ V_163 ] = 0 ;
V_157 . V_162 [ V_164 ] = 0 ;
signal ( V_165 , F_79 ) ;
signal ( V_166 , F_79 ) ;
V_154 = V_11 -> V_117 -> V_154 ;
V_153 = F_28 ( sizeof( struct V_152 ) * ( V_154 + 2 ) ) ;
if ( ! V_153 ) {
V_107 = - V_167 ;
goto V_133;
}
memcpy ( V_153 , V_11 -> V_117 -> V_152 ,
sizeof( struct V_152 ) * V_11 -> V_117 -> V_154 ) ;
if ( F_80 ( V_11 ) < 0 ) {
V_107 = - 1 ;
goto V_133;
}
V_153 [ V_154 ] . V_141 = V_11 -> V_130 ;
V_153 [ V_154 ] . V_168 = V_169 ;
V_154 ++ ;
V_153 [ V_154 ] . V_141 = fileno ( V_150 ) ;
V_153 [ V_154 ] . V_168 = V_169 ;
V_155 = V_154 ;
V_154 ++ ;
if ( F_86 ( fileno ( V_150 ) ) != 0 )
goto V_133;
F_92 ( V_11 -> V_117 ) ;
while ( ! V_126 ) {
int V_129 ;
V_129 = F_78 ( V_11 ) ;
if ( V_129 < 0 )
break;
V_107 = F_84 ( V_11 ) ;
if ( V_107 )
goto V_133;
if ( V_153 [ V_155 ] . V_170 & V_169 )
V_126 = F_88 ( & V_157 , & V_158 ) ;
if ( ! V_129 && ! V_126 )
V_107 = F_93 ( V_153 , V_154 , 100 ) ;
}
F_94 ( V_11 -> V_117 ) ;
if ( V_107 == 0 ) {
F_54 ( V_11 ) ;
F_61 ( V_11 ) ;
}
V_133:
if ( V_11 -> V_130 >= 0 )
F_83 ( V_11 -> V_130 ) ;
if ( V_153 )
free ( V_153 ) ;
return V_107 ;
}
static int F_95 ( struct V_10 * V_11 )
{
int V_107 , V_129 = - 1 ;
struct V_1 * V_171 ;
struct V_172 * V_117 = V_11 -> V_117 ;
F_96 ( V_117 , & V_11 -> V_82 ) ;
F_23 (pos, &evlist->entries, node) {
struct V_173 * V_174 = & V_171 -> V_174 ;
F_97 ( V_171 , V_175 ) ;
F_97 ( V_171 , TIME ) ;
F_97 ( V_171 , V_176 ) ;
F_97 ( V_171 , V_177 ) ;
F_98 ( V_171 , V_178 ) ;
F_98 ( V_171 , V_179 ) ;
F_98 ( V_171 , V_180 ) ;
F_98 ( V_171 , V_181 ) ;
F_98 ( V_171 , V_182 ) ;
V_174 -> V_183 = 0 ;
V_174 -> V_184 = 0 ;
V_174 -> V_185 = 0 ;
V_174 -> V_186 = 1 ;
V_174 -> V_187 = 0 ;
V_174 -> V_188 = 1000 ;
V_174 -> V_189 = 1 ;
}
V_107 = F_99 ( V_117 ) ;
if ( V_107 < 0 ) {
printf ( L_77 , strerror ( V_138 ) ) ;
goto V_133;
}
if ( F_100 ( V_117 , V_11 -> V_82 . V_190 , false ) < 0 ) {
F_101 ( L_78 , strerror ( V_138 ) ) ;
F_102 ( V_117 ) ;
goto V_133;
}
V_129 = 0 ;
V_133:
return V_129 ;
}
static int F_103 ( struct V_10 * V_11 )
{
int V_24 ;
struct V_98 V_191 = {
. V_4 = F_67 ,
. V_184 = V_192 ,
. V_123 = true ,
} ;
V_11 -> V_99 = V_191 ;
V_11 -> V_109 = F_104 ( V_11 -> V_193 , V_194 , 0 , false ,
& V_11 -> V_99 ) ;
if ( ! V_11 -> V_109 ) {
F_8 ( L_79 ) ;
return - V_156 ;
}
if ( ! F_105 ( V_11 -> V_109 , L_80 ) )
return - V_156 ;
V_24 = F_69 ( V_11 ) ;
if ( V_24 < 0 )
return V_24 ;
return F_106 ( V_11 -> V_109 , & V_11 -> V_99 ) ;
}
static int F_107 ( struct V_10 * V_11 )
{
if ( V_11 -> V_195 ) {
V_11 -> V_102 = F_108 ( V_11 -> V_195 ) ;
if ( V_11 -> V_102 == NULL ) {
F_8 ( L_81 ) ;
return - V_156 ;
}
}
return 0 ;
}
static int F_109 ( struct V_10 * V_11 )
{
int V_24 = - V_156 ;
int V_40 = V_11 -> V_56 ;
if ( F_107 ( V_11 ) != 0 )
goto exit;
if ( ! F_72 ( V_40 ) )
goto exit;
if ( ! F_45 ( V_11 ) )
goto exit;
if ( ! F_19 ( V_11 ) )
goto exit;
F_20 ( V_11 ) ;
F_110 () ;
V_24 = F_103 ( V_11 ) ;
if ( V_24 )
goto exit;
F_54 ( V_11 ) ;
F_61 ( V_11 ) ;
exit:
return V_24 ;
}
static int
F_111 ( struct V_10 * V_11 , int V_196 , const char * * V_197 )
{
unsigned int V_198 , V_13 , V_36 ;
const char * * V_199 ;
const char * const V_200 [] = {
L_82 ,
L_83 ,
L_84 , L_85 ,
L_86 , L_87 ,
} ;
V_198 = F_71 ( V_200 ) + V_196 + 2 +
2 * F_71 ( V_201 ) ;
V_199 = calloc ( V_198 + 1 , sizeof( char * ) ) ;
if ( V_199 == NULL )
return - V_167 ;
for ( V_13 = 0 ; V_13 < F_71 ( V_200 ) ; V_13 ++ )
V_199 [ V_13 ] = F_112 ( V_200 [ V_13 ] ) ;
for ( V_36 = 0 ; V_36 < F_71 ( V_201 ) ; V_36 ++ ) {
V_199 [ V_13 ++ ] = L_88 ;
V_199 [ V_13 ++ ] = F_112 ( V_201 [ V_36 ] ) ;
}
V_199 [ V_13 ++ ] = F_112 ( L_89 ) ;
V_199 [ V_13 ++ ] = F_112 ( V_11 -> V_193 ) ;
for ( V_36 = 1 ; V_36 < ( unsigned int ) V_196 ; V_36 ++ , V_13 ++ )
V_199 [ V_13 ] = V_197 [ V_36 ] ;
return F_113 ( V_13 , V_199 , NULL ) ;
}
static int
F_114 ( struct V_10 * V_11 , int V_196 , const char * * V_197 )
{
const struct V_202 V_203 [] = {
F_115 ( 0 , L_90 , & V_11 -> V_25 , L_91 ,
L_92 ) ,
F_116 ( 0 , L_93 , & V_11 -> V_56 ,
L_94 ) ,
F_115 ( 'k' , L_95 , & V_11 -> V_67 , L_96 ,
L_97
L_98 ) ,
F_115 ( 'p' , L_99 , & V_11 -> V_195 , L_99 ,
L_100 ) ,
F_117 ()
} ;
const char * const V_204 [] = {
L_101 ,
NULL
} ;
F_118 () ;
if ( V_196 ) {
V_196 = F_119 ( V_196 , V_197 ,
V_203 ,
V_204 , 0 ) ;
if ( V_196 )
F_120 ( V_204 ,
V_203 ) ;
}
return F_109 ( V_11 ) ;
}
static struct V_172 * F_121 ( void )
{
struct V_172 * V_117 ;
char * V_205 , * V_8 , * V_206 ;
unsigned int V_36 ;
int V_107 = - 1 ;
V_117 = F_122 () ;
if ( V_117 == NULL )
return NULL ;
for ( V_36 = 0 ; V_36 < F_71 ( V_201 ) ; V_36 ++ ) {
V_205 = F_123 ( V_201 [ V_36 ] ) ;
if ( V_205 == NULL )
goto V_133;
V_206 = V_205 ;
V_8 = strchr ( V_205 , ':' ) ;
if ( V_8 == NULL ) {
F_8 ( L_102 ,
V_201 [ V_36 ] ) ;
free ( V_205 ) ;
goto V_133;
}
* V_8 = '\0' ;
V_8 ++ ;
if ( F_124 ( V_117 , V_206 , V_8 , NULL ) ) {
F_8 ( L_103 , V_201 [ V_36 ] ) ;
free ( V_205 ) ;
goto V_133;
}
free ( V_205 ) ;
}
V_107 = 0 ;
V_133:
if ( V_107 ) {
F_125 ( V_117 ) ;
V_117 = NULL ;
}
return V_117 ;
}
static int F_126 ( struct V_10 * V_11 ,
int V_196 , const char * * V_197 )
{
char V_207 [ V_208 ] ;
int V_107 ;
const struct V_202 V_209 [] = {
F_115 ( 'p' , L_99 , & V_11 -> V_82 . V_83 . V_60 , L_99 ,
L_104 ) ,
F_127 ( 'm' , L_105 , & V_11 -> V_82 . V_190 ,
L_106 ) ,
F_128 ( 'v' , L_107 , & V_210 ,
L_108 ) ,
F_129 ( 'a' , L_109 , & V_11 -> V_82 . V_83 . V_84 ,
L_110 ) ,
F_127 ( 'd' , L_111 , & V_11 -> V_135 ,
L_112 ) ,
F_115 ( 0 , L_90 , & V_11 -> V_25 , L_91 ,
L_92 ) ,
F_116 ( 0 , L_93 , & V_11 -> V_56 ,
L_94 ) ,
F_115 ( 'k' , L_95 , & V_11 -> V_67 , L_96 ,
L_97
L_98 ) ,
F_130 ( 0 , L_113 , & V_11 -> V_57 ,
L_114 ) ,
F_117 ()
} ;
const char * const V_211 [] = {
L_115 ,
NULL
} ;
V_11 -> V_99 . V_4 = F_67 ;
V_11 -> V_99 . V_184 = V_192 ;
V_11 -> V_99 . exit = V_212 ;
V_11 -> V_99 . V_213 = V_214 ;
V_11 -> V_99 . V_215 = F_64 ;
V_11 -> V_99 . V_123 = true ;
F_131 ( & V_11 -> V_99 ) ;
V_11 -> V_135 = 1 ;
V_11 -> V_82 . V_216 = 1 ;
V_11 -> V_82 . V_190 = 512 ;
V_11 -> V_82 . V_83 . V_217 = false ;
V_11 -> V_82 . V_83 . V_218 = NULL ;
V_11 -> V_82 . V_83 . V_219 = V_220 ;
F_118 () ;
F_132 () ;
V_221 = 0 ;
F_133 ( false ) ;
if ( V_196 ) {
V_196 = F_119 ( V_196 , V_197 , V_209 ,
V_211 , 0 ) ;
if ( V_196 )
F_120 ( V_211 , V_209 ) ;
}
V_11 -> V_57 *= V_222 ;
V_107 = F_134 ( & V_11 -> V_82 . V_83 ) ;
if ( V_107 ) {
F_135 ( & V_11 -> V_82 . V_83 , V_107 , V_207 , V_208 ) ;
F_136 ( L_6 , V_207 ) ;
}
if ( F_137 ( & V_11 -> V_82 . V_83 ) )
V_11 -> V_82 . V_83 . V_84 = true ;
V_11 -> V_117 = F_121 () ;
if ( V_11 -> V_117 == NULL ) {
V_107 = - 1 ;
goto V_133;
}
V_223 . V_224 = V_11 -> V_117 -> V_225 ;
if ( F_138 ( V_11 -> V_117 , & V_11 -> V_82 . V_83 ) < 0 )
F_120 ( V_211 , V_209 ) ;
V_11 -> V_109 = F_104 ( NULL , V_226 , false , false , & V_11 -> V_99 ) ;
if ( V_11 -> V_109 == NULL ) {
V_107 = - V_167 ;
goto V_133;
}
V_11 -> V_109 -> V_117 = V_11 -> V_117 ;
F_139 ( V_11 -> V_109 ) ;
if ( F_140 ( & V_11 -> V_82 . V_83 ) )
F_141 ( & V_11 -> V_99 ,
V_11 -> V_117 -> V_227 ,
V_228 ,
& V_11 -> V_109 -> V_229 . V_230 ) ;
else
F_142 ( & V_11 -> V_99 , V_228 ,
& V_11 -> V_109 -> V_229 . V_230 ) ;
V_107 = F_95 ( V_11 ) ;
if ( V_107 )
goto V_133;
V_107 = F_90 ( V_11 ) ;
V_133:
F_143 ( 0 ) ;
if ( V_11 -> V_109 )
F_144 ( V_11 -> V_109 ) ;
V_11 -> V_109 = NULL ;
if ( V_11 -> V_117 ) {
F_145 ( V_11 -> V_117 ) ;
F_125 ( V_11 -> V_117 ) ;
}
return V_107 ;
}
static void F_146 ( void )
{
printf ( L_116 ) ;
printf ( L_117 ) ;
printf ( L_118 ) ;
printf ( L_119 ) ;
printf ( L_120 ) ;
printf ( L_121 ) ;
}
static int F_147 ( const char * V_193 , int V_196 , const char * * V_197 )
{
struct V_10 V_11 = {
. V_193 = V_193 ,
. V_56 = - 1 ,
. V_25 = L_19 ,
. V_67 = L_122 ,
. V_17 = V_231 ,
. V_14 = F_71 ( V_231 ) ,
. V_19 = L_123 ,
} ;
if ( V_196 == 1 ) {
F_146 () ;
goto V_232;
}
if ( ! strncmp ( V_197 [ 1 ] , L_124 , 3 ) )
return F_111 ( & V_11 , V_196 - 1 , V_197 + 1 ) ;
if ( ! strncmp ( V_197 [ 1 ] , L_125 , 3 ) )
return F_114 ( & V_11 , V_196 - 1 , V_197 + 1 ) ;
if ( ! strncmp ( V_197 [ 1 ] , L_126 , 4 ) )
return F_126 ( & V_11 , V_196 - 1 , V_197 + 1 ) ;
V_232:
return F_148 ( V_196 , V_197 , NULL ) ;
}
static int F_149 ( const char * V_193 , int V_196 , const char * * V_197 )
{
int V_198 , V_13 = 0 , V_36 ;
const char * * V_199 ;
V_198 = V_196 + 2 ;
V_199 = calloc ( V_198 + 1 , sizeof( char * ) ) ;
V_199 [ V_13 ++ ] = F_123 ( L_82 ) ;
V_199 [ V_13 ++ ] = F_123 ( L_89 ) ;
V_199 [ V_13 ++ ] = F_123 ( V_193 ) ;
for ( V_36 = 1 ; V_36 < V_196 ; V_36 ++ , V_13 ++ )
V_199 [ V_13 ] = V_197 [ V_36 ] ;
F_30 ( V_13 != V_198 ) ;
return F_113 ( V_13 , V_199 , NULL ) ;
}
static int F_150 ( const char * V_193 , int V_196 , const char * * V_197 )
{
int V_198 , V_13 = 0 , V_36 ;
const char * * V_199 ;
V_198 = V_196 + 2 ;
V_199 = calloc ( V_198 + 1 , sizeof( char * ) ) ;
V_199 [ V_13 ++ ] = F_123 ( L_127 ) ;
V_199 [ V_13 ++ ] = F_123 ( L_128 ) ;
V_199 [ V_13 ++ ] = F_123 ( V_193 ) ;
for ( V_36 = 1 ; V_36 < V_196 ; V_36 ++ , V_13 ++ )
V_199 [ V_13 ] = V_197 [ V_36 ] ;
F_30 ( V_13 != V_198 ) ;
return F_151 ( V_13 , V_199 , NULL ) ;
}
static int
F_152 ( const char * V_193 , int V_196 , const char * * V_197 )
{
int V_198 , V_13 = 0 , V_36 ;
const char * * V_199 ;
V_198 = V_196 + 2 ;
V_199 = calloc ( V_198 + 1 , sizeof( char * ) ) ;
V_199 [ V_13 ++ ] = F_123 ( L_129 ) ;
V_199 [ V_13 ++ ] = F_123 ( L_128 ) ;
V_199 [ V_13 ++ ] = F_123 ( V_193 ) ;
for ( V_36 = 1 ; V_36 < V_196 ; V_36 ++ , V_13 ++ )
V_199 [ V_13 ] = V_197 [ V_36 ] ;
F_30 ( V_13 != V_198 ) ;
return F_153 ( V_13 , V_199 , NULL ) ;
}
int F_154 ( int V_196 , const char * * V_197 , const char * T_6 V_9 )
{
const char * V_193 = NULL ;
const struct V_202 V_233 [] = {
F_115 ( 'i' , L_130 , & V_193 , L_131 ,
L_132 ) ,
F_115 ( 'o' , L_133 , & V_193 , L_131 ,
L_134 ) ,
F_129 ( 0 , L_135 , & V_234 ,
L_136 ) ,
F_129 ( 0 , L_137 , & V_235 ,
L_138 ) ,
F_115 ( 0 , L_139 , & V_223 . V_236 , L_140 ,
L_141
L_142 ) ,
F_115 ( 0 , L_143 , & V_223 . V_237 ,
L_131 , L_144 ) ,
F_115 ( 0 , L_145 , & V_223 . V_238 ,
L_131 , L_146 ) ,
F_115 ( 0 , L_147 , & V_223 . V_239 ,
L_131 , L_148 ) ,
F_117 ()
} ;
const char * const V_240 [] = {
L_149 ,
NULL
} ;
V_235 = 0 ;
V_234 = 1 ;
V_196 = F_119 ( V_196 , V_197 , V_233 , V_240 ,
V_241 ) ;
if ( ! V_196 )
F_120 ( V_240 , V_233 ) ;
if ( ! V_235 )
V_234 = 1 ;
if ( ! V_193 ) {
if ( V_235 && ! V_234 )
V_193 = F_123 ( L_150 ) ;
else if ( ! V_235 && V_234 )
V_193 = F_123 ( L_151 ) ;
else
V_193 = F_123 ( L_152 ) ;
if ( ! V_193 ) {
F_8 ( L_153 ) ;
return - V_167 ;
}
}
if ( ! strncmp ( V_197 [ 0 ] , L_124 , 3 ) )
return F_149 ( V_193 , V_196 , V_197 ) ;
else if ( ! strncmp ( V_197 [ 0 ] , L_125 , 3 ) )
return F_150 ( V_193 , V_196 , V_197 ) ;
else if ( ! strncmp ( V_197 [ 0 ] , L_154 , 4 ) )
return F_155 ( V_196 , V_197 , NULL ) ;
else if ( ! strncmp ( V_197 [ 0 ] , L_155 , 3 ) )
return F_156 ( V_196 , V_197 , NULL ) ;
else if ( ! strncmp ( V_197 [ 0 ] , L_129 , 12 ) )
return F_152 ( V_193 , V_196 , V_197 ) ;
#if F_157 ( V_242 ) || F_157 ( V_243 )
else if ( ! strncmp ( V_197 [ 0 ] , L_156 , 4 ) )
return F_147 ( V_193 , V_196 , V_197 ) ;
#endif
else
F_120 ( V_240 , V_233 ) ;
return 0 ;
}
