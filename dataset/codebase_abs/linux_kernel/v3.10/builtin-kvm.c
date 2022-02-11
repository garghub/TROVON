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
static int F_22 ( T_1 V_6 )
{
return V_6 & ( V_30 - 1 ) ;
}
static bool F_23 ( struct V_32 * V_33 , int V_34 )
{
int V_35 = V_33 -> V_36 ;
if ( V_34 < V_33 -> V_36 )
return true ;
while ( V_33 -> V_36 <= V_34 )
V_33 -> V_36 += V_37 ;
V_33 -> V_38 = realloc ( V_33 -> V_38 ,
V_33 -> V_36 * sizeof( * V_33 -> V_38 ) ) ;
if ( ! V_33 -> V_38 ) {
F_8 ( L_23 ) ;
return false ;
}
memset ( V_33 -> V_38 + V_35 , 0 ,
( V_33 -> V_36 - V_35 ) * sizeof( * V_33 -> V_38 ) ) ;
return true ;
}
static struct V_32 * F_24 ( struct V_5 * V_6 )
{
struct V_32 * V_33 ;
V_33 = F_25 ( sizeof( * V_33 ) ) ;
if ( ! V_33 ) {
F_8 ( L_23 ) ;
return NULL ;
}
V_33 -> V_6 = * V_6 ;
return V_33 ;
}
static struct V_32 * F_26 ( struct V_10 * V_11 ,
struct V_5 * V_6 )
{
struct V_32 * V_33 ;
struct V_39 * V_40 ;
F_27 ( V_6 -> V_6 == V_41 ) ;
V_40 = & V_11 -> V_31 [ F_22 ( V_6 -> V_6 ) ] ;
F_28 (event, head, hash_entry) {
if ( V_33 -> V_6 . V_6 == V_6 -> V_6 && V_33 -> V_6 . V_7 == V_6 -> V_7 )
return V_33 ;
}
V_33 = F_24 ( V_6 ) ;
if ( ! V_33 )
return NULL ;
F_29 ( & V_33 -> V_42 , V_40 ) ;
return V_33 ;
}
static bool F_30 ( struct V_10 * V_11 ,
struct V_43 * V_44 ,
struct V_5 * V_6 , T_1 V_45 )
{
struct V_32 * V_33 = NULL ;
if ( V_6 -> V_6 != V_41 )
V_33 = F_26 ( V_11 , V_6 ) ;
V_44 -> V_46 = V_33 ;
V_44 -> V_47 = V_45 ;
return true ;
}
static void
F_31 ( struct V_48 * V_49 , T_1 V_50 )
{
V_49 -> time += V_50 ;
F_32 ( & V_49 -> V_51 , V_50 ) ;
}
static double F_33 ( int V_34 , struct V_32 * V_33 )
{
struct V_48 * V_49 = & V_33 -> V_52 ;
if ( V_34 != - 1 )
V_49 = & V_33 -> V_38 [ V_34 ] ;
return F_34 ( F_35 ( & V_49 -> V_51 ) ,
F_36 ( & V_49 -> V_51 ) ) ;
}
static bool F_37 ( struct V_32 * V_33 , int V_34 ,
T_1 V_50 )
{
if ( V_34 == - 1 ) {
F_31 ( & V_33 -> V_52 , V_50 ) ;
return true ;
}
if ( ! F_23 ( V_33 , V_34 ) )
return false ;
F_31 ( & V_33 -> V_38 [ V_34 ] , V_50 ) ;
return true ;
}
static bool F_38 ( struct V_10 * V_11 ,
struct V_43 * V_44 ,
struct V_5 * V_6 ,
T_1 V_45 )
{
struct V_32 * V_33 ;
T_1 V_53 , V_50 ;
int V_38 ;
if ( V_11 -> V_54 == - 1 )
V_38 = - 1 ;
else
V_38 = V_44 -> V_34 ;
V_33 = V_44 -> V_46 ;
V_53 = V_44 -> V_47 ;
if ( ! V_53 )
return true ;
if ( ! V_33 && V_6 -> V_6 == V_41 )
return true ;
if ( ! V_33 )
V_33 = F_26 ( V_11 , V_6 ) ;
if ( ! V_33 )
return false ;
V_44 -> V_46 = NULL ;
V_44 -> V_47 = 0 ;
F_27 ( V_45 < V_53 ) ;
V_50 = V_45 - V_53 ;
return F_37 ( V_33 , V_38 , V_50 ) ;
}
static
struct V_43 * F_39 ( struct V_55 * V_55 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_55 -> V_56 && F_5 ( V_2 ) ) {
struct V_43 * V_44 ;
V_44 = F_25 ( sizeof( * V_44 ) ) ;
if ( ! V_44 ) {
F_8 ( L_24 , V_57 ) ;
return NULL ;
}
V_44 -> V_34 = F_2 ( V_2 , V_4 , L_25 ) ;
V_55 -> V_56 = V_44 ;
}
return V_55 -> V_56 ;
}
static bool F_40 ( struct V_10 * V_11 ,
struct V_55 * V_55 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_43 * V_44 ;
struct V_5 V_6 = { . V_6 = V_41 } ;
V_44 = F_39 ( V_55 , V_2 , V_4 ) ;
if ( ! V_44 )
return true ;
if ( ( V_11 -> V_54 != - 1 ) &&
( V_11 -> V_54 != V_44 -> V_34 ) )
return true ;
if ( V_11 -> V_26 -> V_58 ( V_2 , V_4 , & V_6 ) )
return F_30 ( V_11 , V_44 , & V_6 , V_4 -> time ) ;
if ( V_11 -> V_26 -> V_59 ( V_2 , V_4 , & V_6 ) )
return F_38 ( V_11 , V_44 , & V_6 , V_4 -> time ) ;
return true ;
}
static bool F_41 ( struct V_10 * V_11 )
{
int V_13 ;
for ( V_13 = 0 ; V_60 [ V_13 ] . V_8 ; V_13 ++ ) {
if ( ! strcmp ( V_60 [ V_13 ] . V_8 , V_11 -> V_61 ) ) {
V_11 -> V_62 = V_60 [ V_13 ] . V_6 ;
return true ;
}
}
F_8 ( L_26 , V_11 -> V_61 ) ;
return false ;
}
static void F_42 ( struct V_63 * V_64 , struct V_32 * V_33 ,
T_2 V_65 , int V_38 )
{
struct V_66 * * V_67 = & V_64 -> V_66 ;
struct V_66 * V_68 = NULL ;
struct V_32 * V_69 ;
while ( * V_67 ) {
V_69 = F_43 ( * V_67 , struct V_32 , V_67 ) ;
V_68 = * V_67 ;
if ( V_65 ( V_33 , V_69 , V_38 ) )
V_67 = & ( * V_67 ) -> V_70 ;
else
V_67 = & ( * V_67 ) -> V_71 ;
}
F_44 ( & V_33 -> V_67 , V_68 , V_67 ) ;
F_45 ( & V_33 -> V_67 , V_64 ) ;
}
static void
F_46 ( struct V_10 * V_11 , struct V_32 * V_33 )
{
int V_38 = V_11 -> V_54 ;
V_11 -> V_72 += F_47 ( V_33 , V_38 ) ;
V_11 -> V_73 += F_48 ( V_33 , V_38 ) ;
}
static bool F_49 ( struct V_32 * V_33 , int V_38 )
{
return ! ! F_47 ( V_33 , V_38 ) ;
}
static void F_50 ( struct V_10 * V_11 )
{
unsigned int V_13 ;
int V_38 = V_11 -> V_54 ;
struct V_32 * V_33 ;
for ( V_13 = 0 ; V_13 < V_30 ; V_13 ++ ) {
F_28 (event, &kvm->kvm_events_cache[i], hash_entry) {
if ( F_49 ( V_33 , V_38 ) ) {
F_46 ( V_11 , V_33 ) ;
F_42 ( & V_11 -> V_64 , V_33 ,
V_11 -> V_62 , V_38 ) ;
}
}
}
}
static struct V_32 * F_51 ( struct V_63 * V_64 )
{
struct V_66 * V_74 = F_52 ( V_64 ) ;
if ( ! V_74 )
return NULL ;
F_53 ( V_74 , V_64 ) ;
return F_43 ( V_74 , struct V_32 , V_67 ) ;
}
static void F_54 ( int V_38 )
{
F_55 ( L_27 ) ;
if ( V_38 == - 1 )
F_55 ( L_28 ) ;
else
F_55 ( L_29 , V_38 ) ;
}
static void F_56 ( struct V_10 * V_11 )
{
char V_20 [ 20 ] ;
struct V_32 * V_33 ;
int V_38 = V_11 -> V_54 ;
F_55 ( L_30 ) ;
F_54 ( V_38 ) ;
F_55 ( L_31 , V_11 -> V_26 -> V_8 ) ;
F_55 ( L_32 , L_33 ) ;
F_55 ( L_34 , L_35 ) ;
F_55 ( L_34 , L_36 ) ;
F_55 ( L_37 , L_38 ) ;
F_55 ( L_30 ) ;
while ( ( V_33 = F_51 ( & V_11 -> V_64 ) ) ) {
T_1 V_75 , V_76 ;
V_75 = F_47 ( V_33 , V_38 ) ;
V_76 = F_48 ( V_33 , V_38 ) ;
V_11 -> V_26 -> V_77 ( V_11 , & V_33 -> V_6 , V_20 ) ;
F_55 ( L_31 , V_20 ) ;
F_55 ( L_39 , ( unsigned long long ) V_75 ) ;
F_55 ( L_40 , ( double ) V_75 / V_11 -> V_72 * 100 ) ;
F_55 ( L_40 , ( double ) V_76 / V_11 -> V_73 * 100 ) ;
F_55 ( L_41 , ( double ) V_76 / V_75 / 1e3 ,
F_33 ( V_38 , V_33 ) ) ;
F_55 ( L_42 ) ;
}
F_55 ( L_43 V_78 L_44 ,
V_11 -> V_72 , V_11 -> V_73 / 1e3 ) ;
}
static int F_57 ( struct V_79 * V_80 ,
union V_81 * V_33 ,
struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_82 * V_82 )
{
struct V_55 * V_55 = F_58 ( V_82 , V_4 -> V_83 ) ;
struct V_10 * V_11 = F_43 ( V_80 , struct V_10 ,
V_80 ) ;
if ( V_55 == NULL ) {
F_59 ( L_45 ,
V_33 -> V_84 . type ) ;
return - 1 ;
}
if ( ! F_40 ( V_11 , V_55 , V_2 , V_4 ) )
return - 1 ;
return 0 ;
}
static int F_60 ( struct V_85 * V_86 )
{
char * V_87 = V_86 -> V_84 . V_88 . V_87 ;
int V_89 ;
if ( strstr ( V_87 , L_46 ) )
V_89 = 1 ;
else if ( strstr ( V_87 , L_47 ) )
V_89 = 0 ;
else {
F_8 ( L_48 , V_87 ) ;
V_89 = - V_90 ;
}
return V_89 ;
}
static int F_61 ( struct V_10 * V_11 )
{
int V_24 ;
struct V_79 V_91 = {
. V_4 = F_57 ,
. V_92 = V_93 ,
. V_94 = true ,
} ;
V_11 -> V_80 = V_91 ;
V_11 -> V_86 = F_62 ( V_11 -> V_95 , V_96 , 0 , false ,
& V_11 -> V_80 ) ;
if ( ! V_11 -> V_86 ) {
F_8 ( L_49 ) ;
return - V_97 ;
}
if ( ! F_63 ( V_11 -> V_86 , L_50 ) )
return - V_97 ;
V_24 = F_60 ( V_11 -> V_86 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == 1 ) {
V_11 -> V_17 = V_98 ;
V_11 -> V_14 = F_64 ( V_98 ) ;
V_11 -> V_19 = L_51 ;
}
return F_65 ( V_11 -> V_86 , & V_11 -> V_80 ) ;
}
static bool F_66 ( int V_38 )
{
if ( V_38 != - 1 && V_38 < 0 ) {
F_8 ( L_52 , V_38 ) ;
return false ;
}
return true ;
}
static int F_67 ( struct V_10 * V_11 )
{
int V_24 = - V_97 ;
int V_38 = V_11 -> V_54 ;
if ( ! F_66 ( V_38 ) )
goto exit;
if ( ! F_41 ( V_11 ) )
goto exit;
if ( ! F_19 ( V_11 ) )
goto exit;
F_20 ( V_11 ) ;
F_68 () ;
V_24 = F_61 ( V_11 ) ;
if ( V_24 )
goto exit;
F_50 ( V_11 ) ;
F_56 ( V_11 ) ;
exit:
return V_24 ;
}
static int
F_69 ( struct V_10 * V_11 , int V_99 , const char * * V_100 )
{
unsigned int V_101 , V_13 , V_102 ;
const char * * V_103 ;
V_101 = F_64 ( V_104 ) + V_99 + 2 ;
V_103 = calloc ( V_101 + 1 , sizeof( char * ) ) ;
if ( V_103 == NULL )
return - V_105 ;
for ( V_13 = 0 ; V_13 < F_64 ( V_104 ) ; V_13 ++ )
V_103 [ V_13 ] = F_70 ( V_104 [ V_13 ] ) ;
V_103 [ V_13 ++ ] = F_70 ( L_53 ) ;
V_103 [ V_13 ++ ] = F_70 ( V_11 -> V_95 ) ;
for ( V_102 = 1 ; V_102 < ( unsigned int ) V_99 ; V_102 ++ , V_13 ++ )
V_103 [ V_13 ] = V_100 [ V_102 ] ;
return F_71 ( V_13 , V_103 , NULL ) ;
}
static int
F_72 ( struct V_10 * V_11 , int V_99 , const char * * V_100 )
{
const struct V_106 V_107 [] = {
F_73 ( 0 , L_54 , & V_11 -> V_25 , L_55 ,
L_56 ) ,
F_74 ( 0 , L_57 , & V_11 -> V_54 ,
L_58 ) ,
F_73 ( 'k' , L_59 , & V_11 -> V_61 , L_60 ,
L_61
L_62 ) ,
F_75 ()
} ;
const char * const V_108 [] = {
L_63 ,
NULL
} ;
F_76 () ;
if ( V_99 ) {
V_99 = F_77 ( V_99 , V_100 ,
V_107 ,
V_108 , 0 ) ;
if ( V_99 )
F_78 ( V_108 ,
V_107 ) ;
}
return F_67 ( V_11 ) ;
}
static void F_79 ( void )
{
printf ( L_64 ) ;
printf ( L_65 ) ;
printf ( L_66 ) ;
printf ( L_67 ) ;
printf ( L_68 ) ;
}
static int F_80 ( const char * V_95 , int V_99 , const char * * V_100 )
{
struct V_10 V_11 = {
. V_95 = V_95 ,
. V_54 = - 1 ,
. V_25 = L_19 ,
. V_61 = L_69 ,
. V_17 = V_109 ,
. V_14 = F_64 ( V_109 ) ,
. V_19 = L_70 ,
} ;
if ( V_99 == 1 ) {
F_79 () ;
goto V_110;
}
if ( ! strncmp ( V_100 [ 1 ] , L_71 , 3 ) )
return F_69 ( & V_11 , V_99 - 1 , V_100 + 1 ) ;
if ( ! strncmp ( V_100 [ 1 ] , L_72 , 3 ) )
return F_72 ( & V_11 , V_99 - 1 , V_100 + 1 ) ;
V_110:
return F_81 ( V_99 , V_100 , NULL ) ;
}
static int F_82 ( const char * V_95 , int V_99 , const char * * V_100 )
{
int V_101 , V_13 = 0 , V_102 ;
const char * * V_103 ;
V_101 = V_99 + 2 ;
V_103 = calloc ( V_101 + 1 , sizeof( char * ) ) ;
V_103 [ V_13 ++ ] = F_83 ( L_73 ) ;
V_103 [ V_13 ++ ] = F_83 ( L_53 ) ;
V_103 [ V_13 ++ ] = F_83 ( V_95 ) ;
for ( V_102 = 1 ; V_102 < V_99 ; V_102 ++ , V_13 ++ )
V_103 [ V_13 ] = V_100 [ V_102 ] ;
F_27 ( V_13 != V_101 ) ;
return F_71 ( V_13 , V_103 , NULL ) ;
}
static int F_84 ( const char * V_95 , int V_99 , const char * * V_100 )
{
int V_101 , V_13 = 0 , V_102 ;
const char * * V_103 ;
V_101 = V_99 + 2 ;
V_103 = calloc ( V_101 + 1 , sizeof( char * ) ) ;
V_103 [ V_13 ++ ] = F_83 ( L_74 ) ;
V_103 [ V_13 ++ ] = F_83 ( L_75 ) ;
V_103 [ V_13 ++ ] = F_83 ( V_95 ) ;
for ( V_102 = 1 ; V_102 < V_99 ; V_102 ++ , V_13 ++ )
V_103 [ V_13 ] = V_100 [ V_102 ] ;
F_27 ( V_13 != V_101 ) ;
return F_85 ( V_13 , V_103 , NULL ) ;
}
static int
F_86 ( const char * V_95 , int V_99 , const char * * V_100 )
{
int V_101 , V_13 = 0 , V_102 ;
const char * * V_103 ;
V_101 = V_99 + 2 ;
V_103 = calloc ( V_101 + 1 , sizeof( char * ) ) ;
V_103 [ V_13 ++ ] = F_83 ( L_76 ) ;
V_103 [ V_13 ++ ] = F_83 ( L_75 ) ;
V_103 [ V_13 ++ ] = F_83 ( V_95 ) ;
for ( V_102 = 1 ; V_102 < V_99 ; V_102 ++ , V_13 ++ )
V_103 [ V_13 ] = V_100 [ V_102 ] ;
F_27 ( V_13 != V_101 ) ;
return F_87 ( V_13 , V_103 , NULL ) ;
}
int F_88 ( int V_99 , const char * * V_100 , const char * T_3 V_9 )
{
const char * V_95 = NULL ;
const struct V_106 V_111 [] = {
F_73 ( 'i' , L_77 , & V_95 , L_78 ,
L_79 ) ,
F_73 ( 'o' , L_80 , & V_95 , L_78 ,
L_81 ) ,
F_89 ( 0 , L_82 , & V_112 ,
L_83 ) ,
F_89 ( 0 , L_84 , & V_113 ,
L_85 ) ,
F_73 ( 0 , L_86 , & V_114 . V_115 , L_87 ,
L_88
L_89 ) ,
F_73 ( 0 , L_90 , & V_114 . V_116 ,
L_78 , L_91 ) ,
F_73 ( 0 , L_92 , & V_114 . V_117 ,
L_78 , L_93 ) ,
F_73 ( 0 , L_94 , & V_114 . V_118 ,
L_78 , L_95 ) ,
F_75 ()
} ;
const char * const V_119 [] = {
L_96 ,
NULL
} ;
V_113 = 0 ;
V_112 = 1 ;
V_99 = F_77 ( V_99 , V_100 , V_111 , V_119 ,
V_120 ) ;
if ( ! V_99 )
F_78 ( V_119 , V_111 ) ;
if ( ! V_113 )
V_112 = 1 ;
if ( ! V_95 ) {
if ( V_113 && ! V_112 )
V_95 = F_83 ( L_97 ) ;
else if ( ! V_113 && V_112 )
V_95 = F_83 ( L_98 ) ;
else
V_95 = F_83 ( L_99 ) ;
if ( ! V_95 ) {
F_8 ( L_100 ) ;
return - V_105 ;
}
}
if ( ! strncmp ( V_100 [ 0 ] , L_71 , 3 ) )
return F_82 ( V_95 , V_99 , V_100 ) ;
else if ( ! strncmp ( V_100 [ 0 ] , L_72 , 3 ) )
return F_84 ( V_95 , V_99 , V_100 ) ;
else if ( ! strncmp ( V_100 [ 0 ] , L_101 , 4 ) )
return F_90 ( V_99 , V_100 , NULL ) ;
else if ( ! strncmp ( V_100 [ 0 ] , L_102 , 3 ) )
return F_91 ( V_99 , V_100 , NULL ) ;
else if ( ! strncmp ( V_100 [ 0 ] , L_76 , 12 ) )
return F_86 ( V_95 , V_99 , V_100 ) ;
#if F_92 ( V_121 ) || F_92 ( V_122 )
else if ( ! strncmp ( V_100 [ 0 ] , L_103 , 4 ) )
return F_80 ( V_95 , V_99 , V_100 ) ;
#endif
else
F_78 ( V_119 , V_111 ) ;
return 0 ;
}
