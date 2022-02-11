void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 )
F_2 ( & V_2 -> V_9 [ V_7 ] ) ;
F_3 ( & V_2 -> V_10 ) ;
F_4 ( V_2 , V_4 , V_6 ) ;
F_5 ( & V_2 -> V_11 , 64 ) ;
V_2 -> V_12 . V_13 = - 1 ;
}
struct V_1 * F_6 ( void )
{
struct V_1 * V_2 = F_7 ( sizeof( * V_2 ) ) ;
if ( V_2 != NULL )
F_1 ( V_2 , NULL , NULL ) ;
return V_2 ;
}
struct V_1 * F_8 ( void )
{
struct V_1 * V_2 = F_6 () ;
if ( V_2 && F_9 ( V_2 ) ) {
F_10 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
V_2 -> V_16 = V_15 -> V_16 ;
V_2 -> V_17 = V_15 -> V_17 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel)
F_15 ( V_18 ) ;
F_11 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_14 * V_19 , * V_20 ;
F_17 (evlist, n, pos) {
F_18 ( & V_19 -> V_21 ) ;
F_19 ( V_19 ) ;
}
V_2 -> V_22 = 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_23 ) ;
F_22 ( & V_2 -> V_11 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 -> V_4 ) ;
F_26 ( V_2 -> V_6 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_6 = NULL ;
F_16 ( V_2 ) ;
F_20 ( V_2 ) ;
free ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 , struct V_14 * V_24 )
{
F_28 ( & V_24 -> V_21 , & V_2 -> V_10 ) ;
V_24 -> V_25 = V_2 -> V_22 ;
V_24 -> V_26 = ! V_24 -> V_25 ;
if ( ! V_2 -> V_22 ++ )
F_11 ( V_2 ) ;
}
void F_29 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
int V_22 )
{
bool V_29 = ! V_2 -> V_22 ;
F_30 ( V_28 , & V_2 -> V_10 ) ;
V_2 -> V_22 += V_22 ;
if ( V_29 )
F_11 ( V_2 ) ;
}
void F_31 ( struct V_27 * V_28 )
{
struct V_14 * V_18 , * V_30 ;
V_30 = F_32 ( V_28 -> V_31 , struct V_14 , V_21 ) ;
V_18 = F_32 ( V_28 -> V_32 , struct V_14 , V_21 ) ;
V_30 -> V_33 = V_18 -> V_25 - V_30 -> V_25 + 1 ;
F_33 (list, evsel) {
V_18 -> V_30 = V_30 ;
}
}
void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 ) {
V_2 -> V_34 = V_2 -> V_22 > 1 ? 1 : 0 ;
F_31 ( & V_2 -> V_10 ) ;
}
}
int F_9 ( struct V_1 * V_2 )
{
struct V_35 V_36 = {
. type = V_37 ,
. V_38 = V_39 ,
} ;
struct V_14 * V_18 ;
F_35 ( & V_36 ) ;
V_18 = F_36 ( & V_36 ) ;
if ( V_18 == NULL )
goto error;
V_18 -> V_40 = F_37 ( L_1 ) ;
if ( ! V_18 -> V_40 )
goto V_41;
F_27 ( V_2 , V_18 ) ;
return 0 ;
V_41:
F_19 ( V_18 ) ;
error:
return - V_42 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_35 * V_43 , T_1 V_44 )
{
struct V_14 * V_18 , * V_20 ;
F_39 ( V_45 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_44 ; V_7 ++ ) {
V_18 = F_40 ( V_43 + V_7 , V_2 -> V_22 + V_7 ) ;
if ( V_18 == NULL )
goto V_46;
F_28 ( & V_18 -> V_21 , & V_45 ) ;
}
F_29 ( V_2 , & V_45 , V_44 ) ;
return 0 ;
V_46:
F_41 (&head, n, evsel)
F_19 ( V_18 ) ;
return - 1 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_35 * V_43 , T_1 V_44 )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_44 ; V_7 ++ )
F_35 ( V_43 + V_7 ) ;
return F_38 ( V_2 , V_43 , V_44 ) ;
}
struct V_14 *
F_43 ( struct V_1 * V_2 , int V_47 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
if ( V_18 -> V_36 . type == V_48 &&
( int ) V_18 -> V_36 . V_38 == V_47 )
return V_18 ;
}
return NULL ;
}
struct V_14 *
F_44 ( struct V_1 * V_2 ,
const char * V_40 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
if ( ( V_18 -> V_36 . type == V_48 ) &&
( strcmp ( V_18 -> V_40 , V_40 ) == 0 ) )
return V_18 ;
}
return NULL ;
}
int F_45 ( struct V_1 * V_2 ,
const char * V_49 , const char * V_40 , void * V_50 )
{
struct V_14 * V_18 = F_46 ( V_49 , V_40 ) ;
if ( V_18 == NULL )
return - 1 ;
V_18 -> V_50 = V_50 ;
F_27 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
if ( V_18 -> V_51 )
return 1 ;
else
return F_48 ( V_2 -> V_6 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
int V_52 , V_53 ;
struct V_14 * V_19 ;
int V_54 = F_50 ( V_2 -> V_4 ) ;
int V_55 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_14 (evlist, pos) {
if ( ! F_51 ( V_19 ) || ! V_19 -> V_56 )
continue;
V_55 = F_47 ( V_2 , V_19 ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ )
F_52 ( F_53 ( V_19 , V_52 , V_53 ) ,
V_57 , 0 ) ;
}
}
}
void F_54 ( struct V_1 * V_2 )
{
int V_52 , V_53 ;
struct V_14 * V_19 ;
int V_54 = F_50 ( V_2 -> V_4 ) ;
int V_55 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_14 (evlist, pos) {
if ( ! F_51 ( V_19 ) || ! V_19 -> V_56 )
continue;
V_55 = F_47 ( V_2 , V_19 ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ )
F_52 ( F_53 ( V_19 , V_52 , V_53 ) ,
V_58 , 0 ) ;
}
}
}
int F_55 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
int V_52 , V_53 , V_59 ;
int V_54 = F_50 ( V_2 -> V_4 ) ;
int V_55 = F_47 ( V_2 , V_18 ) ;
if ( ! V_18 -> V_56 )
return 0 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
V_59 = F_52 ( F_53 ( V_18 , V_52 , V_53 ) ,
V_57 , 0 ) ;
if ( V_59 )
return V_59 ;
}
}
return 0 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
int V_52 , V_53 , V_59 ;
int V_54 = F_50 ( V_2 -> V_4 ) ;
int V_55 = F_47 ( V_2 , V_18 ) ;
if ( ! V_18 -> V_56 )
return - V_60 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
V_59 = F_52 ( F_53 ( V_18 , V_52 , V_53 ) ,
V_58 , 0 ) ;
if ( V_59 )
return V_59 ;
}
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_52 )
{
int V_53 , V_59 ;
int V_55 = F_47 ( V_2 , V_18 ) ;
if ( ! V_18 -> V_56 )
return - V_60 ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
V_59 = F_52 ( F_53 ( V_18 , V_52 , V_53 ) ,
V_58 , 0 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_53 )
{
int V_52 , V_59 ;
int V_54 = F_50 ( V_2 -> V_4 ) ;
if ( ! V_18 -> V_56 )
return - V_60 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
V_59 = F_52 ( F_53 ( V_18 , V_52 , V_53 ) , V_58 , 0 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
int F_59 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_25 )
{
bool V_61 = ! F_60 ( V_2 -> V_4 ) ;
if ( V_61 )
return F_57 ( V_2 , V_18 , V_25 ) ;
else
return F_58 ( V_2 , V_18 , V_25 ) ;
}
int F_61 ( struct V_1 * V_2 )
{
int V_54 = F_50 ( V_2 -> V_4 ) ;
int V_55 = F_48 ( V_2 -> V_6 ) ;
int V_62 = 0 ;
struct V_14 * V_18 ;
F_62 (evsel, &evlist->entries, node) {
if ( V_18 -> V_51 )
V_62 += V_54 ;
else
V_62 += V_54 * V_55 ;
}
if ( F_63 ( & V_2 -> V_11 ) < V_62 &&
F_64 ( & V_2 -> V_11 , V_62 ) < 0 )
return - V_42 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , int V_56 , int V_25 )
{
int V_19 = F_66 ( & V_2 -> V_11 , V_56 , V_63 | V_64 | V_65 ) ;
if ( V_19 >= 0 ) {
V_2 -> V_11 . V_66 [ V_19 ] . V_25 = V_25 ;
F_67 ( V_56 , V_67 , V_68 ) ;
}
return V_19 ;
}
int F_68 ( struct V_1 * V_2 , int V_56 )
{
return F_65 ( V_2 , V_56 , - 1 ) ;
}
static void F_69 ( struct V_69 * V_70 , int V_56 )
{
struct V_1 * V_2 = F_70 ( V_70 , struct V_1 , V_11 ) ;
F_71 ( V_2 , V_70 -> V_66 [ V_56 ] . V_25 ) ;
}
int F_72 ( struct V_1 * V_2 , short V_71 )
{
return F_73 ( & V_2 -> V_11 , V_71 ,
F_69 ) ;
}
int F_74 ( struct V_1 * V_2 , int V_72 )
{
return F_75 ( & V_2 -> V_11 , V_72 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_52 , int V_53 , T_2 V_47 )
{
int V_73 ;
struct V_74 * V_75 = F_77 ( V_18 , V_52 , V_53 ) ;
V_75 -> V_47 = V_47 ;
V_75 -> V_18 = V_18 ;
V_73 = F_78 ( V_75 -> V_47 , V_76 ) ;
F_79 ( & V_75 -> V_21 , & V_2 -> V_9 [ V_73 ] ) ;
}
void F_80 ( struct V_1 * V_2 , struct V_14 * V_18 ,
int V_52 , int V_53 , T_2 V_47 )
{
F_76 ( V_2 , V_18 , V_52 , V_53 , V_47 ) ;
V_18 -> V_47 [ V_18 -> V_77 ++ ] = V_47 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_52 , int V_53 , int V_56 )
{
T_2 V_78 [ 4 ] = { 0 , } ;
int V_79 = 1 ;
T_2 V_47 ;
int V_80 ;
V_80 = F_52 ( V_56 , V_81 , & V_47 ) ;
if ( ! V_80 )
goto V_82;
if ( V_83 != V_84 )
return - 1 ;
if ( F_82 ( V_2 ) & V_85 )
return - 1 ;
if ( ! ( V_18 -> V_36 . V_86 & V_87 ) ||
F_83 ( V_56 , & V_78 , sizeof( V_78 ) ) == - 1 )
return - 1 ;
if ( V_18 -> V_36 . V_86 & V_88 )
++ V_79 ;
if ( V_18 -> V_36 . V_86 & V_89 )
++ V_79 ;
V_47 = V_78 [ V_79 ] ;
V_82:
F_80 ( V_2 , V_18 , V_52 , V_53 , V_47 ) ;
return 0 ;
}
struct V_74 * F_84 ( struct V_1 * V_2 , T_2 V_47 )
{
struct V_90 * V_45 ;
struct V_74 * V_75 ;
int V_73 ;
V_73 = F_78 ( V_47 , V_76 ) ;
V_45 = & V_2 -> V_9 [ V_73 ] ;
F_85 (sid, head, node)
if ( V_75 -> V_47 == V_47 )
return V_75 ;
return NULL ;
}
struct V_14 * F_86 ( struct V_1 * V_2 , T_2 V_47 )
{
struct V_74 * V_75 ;
if ( V_2 -> V_22 == 1 )
return F_12 ( V_2 ) ;
V_75 = F_84 ( V_2 , V_47 ) ;
if ( V_75 )
return V_75 -> V_18 ;
if ( ! F_87 ( V_2 ) )
return F_12 ( V_2 ) ;
return NULL ;
}
static int F_88 ( struct V_1 * V_2 ,
union V_91 * V_92 , T_2 * V_47 )
{
const T_2 * V_93 = V_92 -> V_94 . V_93 ;
T_3 V_20 ;
V_20 = ( V_92 -> V_95 . V_96 - sizeof( V_92 -> V_95 ) ) >> 3 ;
if ( V_92 -> V_95 . type == V_97 ) {
if ( V_2 -> V_16 >= V_20 )
return - 1 ;
* V_47 = V_93 [ V_2 -> V_16 ] ;
} else {
if ( V_2 -> V_17 > V_20 )
return - 1 ;
V_20 -= V_2 -> V_17 ;
* V_47 = V_93 [ V_20 ] ;
}
return 0 ;
}
static struct V_14 * F_89 ( struct V_1 * V_2 ,
union V_91 * V_92 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
struct V_90 * V_45 ;
struct V_74 * V_75 ;
int V_73 ;
T_2 V_47 ;
if ( V_2 -> V_22 == 1 )
return V_15 ;
if ( ! V_15 -> V_36 . V_98 &&
V_92 -> V_95 . type != V_97 )
return V_15 ;
if ( F_88 ( V_2 , V_92 , & V_47 ) )
return NULL ;
if ( ! V_47 )
return V_15 ;
V_73 = F_78 ( V_47 , V_76 ) ;
V_45 = & V_2 -> V_9 [ V_73 ] ;
F_85 (sid, head, node) {
if ( V_75 -> V_47 == V_47 )
return V_75 -> V_18 ;
}
return NULL ;
}
union V_91 * F_90 ( struct V_1 * V_2 , int V_25 )
{
struct V_99 * V_100 = & V_2 -> V_23 [ V_25 ] ;
unsigned int V_45 = F_91 ( V_100 ) ;
unsigned int V_101 = V_100 -> V_32 ;
unsigned char * V_102 = V_100 -> V_103 + V_104 ;
union V_91 * V_92 = NULL ;
if ( V_2 -> V_105 ) {
int V_106 = V_45 - V_101 ;
if ( V_106 > V_100 -> V_107 / 2 || V_106 < 0 ) {
fprintf ( V_108 , L_2 ) ;
V_101 = V_45 ;
}
}
if ( V_101 != V_45 ) {
T_1 V_96 ;
V_92 = (union V_91 * ) & V_102 [ V_101 & V_100 -> V_107 ] ;
V_96 = V_92 -> V_95 . V_96 ;
if ( ( V_101 & V_100 -> V_107 ) + V_96 != ( ( V_101 + V_96 ) & V_100 -> V_107 ) ) {
unsigned int V_109 = V_101 ;
unsigned int V_110 = F_92 ( sizeof( * V_92 ) , V_96 ) , V_111 ;
void * V_112 = V_100 -> V_113 ;
do {
V_111 = F_92 ( V_100 -> V_107 + 1 - ( V_109 & V_100 -> V_107 ) , V_110 ) ;
memcpy ( V_112 , & V_102 [ V_109 & V_100 -> V_107 ] , V_111 ) ;
V_109 += V_111 ;
V_112 += V_111 ;
V_110 -= V_111 ;
} while ( V_110 );
V_92 = (union V_91 * ) V_100 -> V_113 ;
}
V_101 += V_96 ;
}
V_100 -> V_32 = V_101 ;
return V_92 ;
}
static bool F_93 ( struct V_99 * V_100 )
{
return F_91 ( V_100 ) != V_100 -> V_32 ;
}
static void F_94 ( struct V_1 * V_2 , int V_25 )
{
++ V_2 -> V_23 [ V_25 ] . V_114 ;
}
static void F_71 ( struct V_1 * V_2 , int V_25 )
{
F_95 ( V_2 -> V_23 [ V_25 ] . V_114 == 0 ) ;
if ( -- V_2 -> V_23 [ V_25 ] . V_114 == 0 )
F_96 ( V_2 , V_25 ) ;
}
void F_97 ( struct V_1 * V_2 , int V_25 )
{
struct V_99 * V_100 = & V_2 -> V_23 [ V_25 ] ;
if ( ! V_2 -> V_105 ) {
unsigned int V_101 = V_100 -> V_32 ;
F_98 ( V_100 , V_101 ) ;
}
if ( V_100 -> V_114 == 1 && F_93 ( V_100 ) )
F_71 ( V_2 , V_25 ) ;
}
static void F_96 ( struct V_1 * V_2 , int V_25 )
{
if ( V_2 -> V_23 [ V_25 ] . V_103 != NULL ) {
F_99 ( V_2 -> V_23 [ V_25 ] . V_103 , V_2 -> V_115 ) ;
V_2 -> V_23 [ V_25 ] . V_103 = NULL ;
V_2 -> V_23 [ V_25 ] . V_114 = 0 ;
}
}
void F_23 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_23 == NULL )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_116 ; V_7 ++ )
F_96 ( V_2 , V_7 ) ;
F_21 ( & V_2 -> V_23 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
V_2 -> V_116 = F_50 ( V_2 -> V_4 ) ;
if ( F_60 ( V_2 -> V_4 ) )
V_2 -> V_116 = F_48 ( V_2 -> V_6 ) ;
V_2 -> V_23 = F_7 ( V_2 -> V_116 * sizeof( struct V_99 ) ) ;
return V_2 -> V_23 != NULL ? 0 : - V_42 ;
}
static int F_101 ( struct V_1 * V_2 , int V_25 ,
struct V_117 * V_118 , int V_56 )
{
V_2 -> V_23 [ V_25 ] . V_114 = 2 ;
V_2 -> V_23 [ V_25 ] . V_32 = 0 ;
V_2 -> V_23 [ V_25 ] . V_107 = V_118 -> V_107 ;
V_2 -> V_23 [ V_25 ] . V_103 = V_23 ( NULL , V_2 -> V_115 , V_118 -> V_119 ,
V_120 , V_56 , 0 ) ;
if ( V_2 -> V_23 [ V_25 ] . V_103 == V_121 ) {
F_102 ( L_3 ,
V_83 ) ;
V_2 -> V_23 [ V_25 ] . V_103 = NULL ;
return - 1 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 , int V_25 ,
struct V_117 * V_118 , int V_52 ,
int V_53 , int * V_122 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
int V_56 ;
if ( V_18 -> V_51 && V_53 )
continue;
V_56 = F_53 ( V_18 , V_52 , V_53 ) ;
if ( * V_122 == - 1 ) {
* V_122 = V_56 ;
if ( F_101 ( V_2 , V_25 , V_118 , * V_122 ) < 0 )
return - 1 ;
} else {
if ( F_52 ( V_56 , V_123 , * V_122 ) != 0 )
return - 1 ;
F_94 ( V_2 , V_25 ) ;
}
if ( F_65 ( V_2 , V_56 , V_25 ) < 0 ) {
F_71 ( V_2 , V_25 ) ;
return - 1 ;
}
if ( ( V_18 -> V_36 . V_86 & V_87 ) &&
F_81 ( V_2 , V_18 , V_52 , V_53 , V_56 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
int V_52 , V_53 ;
int V_54 = F_50 ( V_2 -> V_4 ) ;
int V_55 = F_48 ( V_2 -> V_6 ) ;
F_102 ( L_4 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
int V_122 = - 1 ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
if ( F_103 ( V_2 , V_52 , V_118 , V_52 ,
V_53 , & V_122 ) )
goto V_124;
}
}
return 0 ;
V_124:
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ )
F_96 ( V_2 , V_52 ) ;
return - 1 ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
int V_53 ;
int V_55 = F_48 ( V_2 -> V_6 ) ;
F_102 ( L_5 ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
int V_122 = - 1 ;
if ( F_103 ( V_2 , V_53 , V_118 , 0 , V_53 ,
& V_122 ) )
goto V_124;
}
return 0 ;
V_124:
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ )
F_96 ( V_2 , V_53 ) ;
return - 1 ;
}
static T_1 F_106 ( unsigned long V_125 )
{
if ( V_125 == V_126 )
V_125 = ( 512 * 1024 ) / V_104 ;
else if ( ! F_107 ( V_125 ) )
return 0 ;
return ( V_125 + 1 ) * V_104 ;
}
static long F_108 ( const char * V_127 , unsigned long F_92 ,
unsigned long V_128 )
{
unsigned long V_125 , V_129 ;
static struct V_130 V_131 [] = {
{ . V_132 = 'B' , . V_133 = 1 } ,
{ . V_132 = 'K' , . V_133 = 1 << 10 } ,
{ . V_132 = 'M' , . V_133 = 1 << 20 } ,
{ . V_132 = 'G' , . V_133 = 1 << 30 } ,
{ . V_132 = 0 } ,
} ;
if ( V_127 == NULL )
return - V_60 ;
V_129 = F_109 ( V_127 , V_131 ) ;
if ( V_129 != ( unsigned long ) - 1 ) {
V_125 = F_110 ( V_129 , V_104 ) / V_104 ;
} else {
char * V_134 ;
V_125 = strtoul ( V_127 , & V_134 , 10 ) ;
if ( * V_134 != '\0' )
return - V_60 ;
}
if ( V_125 == 0 && F_92 == 0 ) {
} else if ( ! F_107 ( V_125 ) ) {
V_125 = F_111 ( V_125 ) ;
if ( ! V_125 )
return - V_60 ;
F_112 ( L_6 ,
V_125 * V_104 , V_125 ) ;
}
if ( V_125 > V_128 )
return - V_60 ;
return V_125 ;
}
int F_113 ( const struct V_135 * V_136 , const char * V_127 ,
int T_4 V_137 )
{
unsigned int * V_138 = V_136 -> V_139 ;
unsigned long V_128 = V_126 ;
long V_125 ;
if ( V_128 > V_140 / V_104 )
V_128 = V_140 / V_104 ;
V_125 = F_108 ( V_127 , 1 , V_128 ) ;
if ( V_125 < 0 ) {
F_114 ( L_7 ) ;
return - 1 ;
}
* V_138 = V_125 ;
return 0 ;
}
int F_115 ( struct V_1 * V_2 , unsigned int V_125 ,
bool V_105 )
{
struct V_14 * V_18 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
struct V_117 V_118 = {
. V_119 = V_141 | ( V_105 ? 0 : V_142 ) ,
} ;
if ( V_2 -> V_23 == NULL && F_100 ( V_2 ) < 0 )
return - V_42 ;
if ( V_2 -> V_11 . V_10 == NULL && F_61 ( V_2 ) < 0 )
return - V_42 ;
V_2 -> V_105 = V_105 ;
V_2 -> V_115 = F_106 ( V_125 ) ;
F_116 ( L_8 , V_2 -> V_115 ) ;
V_118 . V_107 = V_2 -> V_115 - V_104 - 1 ;
F_14 (evlist, evsel) {
if ( ( V_18 -> V_36 . V_86 & V_87 ) &&
V_18 -> V_143 == NULL &&
F_117 ( V_18 , F_50 ( V_4 ) , V_6 -> V_144 ) < 0 )
return - V_42 ;
}
if ( F_60 ( V_4 ) )
return F_105 ( V_2 , & V_118 ) ;
return F_104 ( V_2 , & V_118 ) ;
}
int F_118 ( struct V_1 * V_2 , struct V_145 * V_145 )
{
V_2 -> V_6 = F_119 ( V_145 -> V_13 , V_145 -> V_146 ,
V_145 -> V_147 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( F_120 ( V_145 ) )
V_2 -> V_4 = F_121 () ;
else
V_2 -> V_4 = F_122 ( V_145 -> V_148 ) ;
if ( V_2 -> V_4 == NULL )
goto V_149;
return 0 ;
V_149:
F_26 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
return - 1 ;
}
int F_123 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_59 = 0 ;
const int V_150 = F_50 ( V_2 -> V_4 ) ,
V_151 = F_48 ( V_2 -> V_6 ) ;
F_14 (evlist, evsel) {
if ( V_18 -> V_152 == NULL )
continue;
V_59 = F_124 ( V_18 , V_150 , V_151 , V_18 -> V_152 ) ;
if ( V_59 )
break;
}
return V_59 ;
}
int F_125 ( struct V_1 * V_2 , const char * V_152 )
{
struct V_14 * V_18 ;
int V_59 = 0 ;
const int V_150 = F_50 ( V_2 -> V_4 ) ,
V_151 = F_48 ( V_2 -> V_6 ) ;
F_14 (evlist, evsel) {
V_59 = F_124 ( V_18 , V_150 , V_151 , V_152 ) ;
if ( V_59 )
break;
}
return V_59 ;
}
bool F_126 ( struct V_1 * V_2 )
{
struct V_14 * V_19 ;
if ( V_2 -> V_22 == 1 )
return true ;
if ( V_2 -> V_16 < 0 || V_2 -> V_17 < 0 )
return false ;
F_14 (evlist, pos) {
if ( V_19 -> V_16 != V_2 -> V_16 ||
V_19 -> V_17 != V_2 -> V_17 )
return false ;
}
return true ;
}
T_2 F_127 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
if ( V_2 -> V_153 )
return V_2 -> V_153 ;
F_14 (evlist, evsel)
V_2 -> V_153 |= V_18 -> V_36 . V_154 ;
return V_2 -> V_153 ;
}
T_2 F_128 ( struct V_1 * V_2 )
{
V_2 -> V_153 = 0 ;
return F_127 ( V_2 ) ;
}
bool F_129 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) , * V_19 = V_15 ;
T_2 V_86 = V_15 -> V_36 . V_86 ;
T_2 V_154 = V_15 -> V_36 . V_154 ;
F_14 (evlist, pos) {
if ( V_86 != V_19 -> V_36 . V_86 )
return false ;
}
if ( ( V_154 & V_155 ) &&
! ( V_86 & V_87 ) ) {
return false ;
}
return true ;
}
T_2 F_82 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
return V_15 -> V_36 . V_86 ;
}
T_5 F_130 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
struct V_156 * V_102 ;
T_2 V_154 ;
T_5 V_96 = 0 ;
if ( ! V_15 -> V_36 . V_98 )
goto V_157;
V_154 = V_15 -> V_36 . V_154 ;
if ( V_154 & V_158 )
V_96 += sizeof( V_102 -> V_146 ) * 2 ;
if ( V_154 & V_159 )
V_96 += sizeof( V_102 -> time ) ;
if ( V_154 & V_160 )
V_96 += sizeof( V_102 -> V_47 ) ;
if ( V_154 & V_161 )
V_96 += sizeof( V_102 -> V_162 ) ;
if ( V_154 & V_163 )
V_96 += sizeof( V_102 -> V_52 ) * 2 ;
if ( V_154 & V_164 )
V_96 += sizeof( V_102 -> V_47 ) ;
V_157:
return V_96 ;
}
bool F_131 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) , * V_19 = V_15 ;
F_132 (evlist, pos) {
if ( V_15 -> V_36 . V_98 != V_19 -> V_36 . V_98 )
return false ;
}
return true ;
}
bool F_87 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
return V_15 -> V_36 . V_98 ;
}
void F_133 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
V_2 -> V_165 = V_18 ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_150 = F_50 ( V_2 -> V_4 ) ;
int V_151 = F_48 ( V_2 -> V_6 ) ;
int V_20 ;
F_134 (evlist, evsel) {
V_20 = V_18 -> V_4 ? V_18 -> V_4 -> V_144 : V_150 ;
F_135 ( V_18 , V_20 , V_151 ) ;
}
}
static int F_136 ( struct V_1 * V_2 )
{
int V_59 = - V_42 ;
V_2 -> V_4 = F_122 ( NULL ) ;
if ( V_2 -> V_4 == NULL )
goto V_157;
V_2 -> V_6 = F_137 () ;
if ( V_2 -> V_6 == NULL )
goto V_166;
V_59 = 0 ;
V_157:
return V_59 ;
V_166:
F_25 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
goto V_157;
}
int F_138 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_59 ;
if ( V_2 -> V_6 == NULL && V_2 -> V_4 == NULL ) {
V_59 = F_136 ( V_2 ) ;
if ( V_59 < 0 )
goto V_167;
}
F_13 ( V_2 ) ;
F_14 (evlist, evsel) {
V_59 = F_139 ( V_18 , V_2 -> V_4 , V_2 -> V_6 ) ;
if ( V_59 < 0 )
goto V_167;
}
return 0 ;
V_167:
F_24 ( V_2 ) ;
V_83 = - V_59 ;
return V_59 ;
}
int F_140 ( struct V_1 * V_2 , struct V_145 * V_145 ,
const char * V_168 [] , bool V_169 ,
void (* F_141)( int V_170 , T_6 * V_171 , void * V_172 ) )
{
int V_173 [ 2 ] , V_174 [ 2 ] ;
char V_175 ;
if ( F_142 ( V_173 ) < 0 ) {
perror ( L_9 ) ;
return - 1 ;
}
if ( F_142 ( V_174 ) < 0 ) {
perror ( L_10 ) ;
goto V_176;
}
V_2 -> V_12 . V_13 = F_143 () ;
if ( V_2 -> V_12 . V_13 < 0 ) {
perror ( L_11 ) ;
goto V_177;
}
if ( ! V_2 -> V_12 . V_13 ) {
int V_80 ;
if ( V_169 )
F_144 ( 2 , 1 ) ;
signal ( V_178 , V_179 ) ;
F_145 ( V_173 [ 0 ] ) ;
F_145 ( V_174 [ 1 ] ) ;
F_67 ( V_174 [ 0 ] , V_180 , V_181 ) ;
F_145 ( V_173 [ 1 ] ) ;
V_80 = F_83 ( V_174 [ 0 ] , & V_175 , 1 ) ;
if ( V_80 != 1 ) {
if ( V_80 == - 1 )
perror ( L_12 ) ;
exit ( V_80 ) ;
}
F_146 ( V_168 [ 0 ] , ( char * * ) V_168 ) ;
if ( F_141 ) {
union V_182 V_129 ;
V_129 . V_183 = V_83 ;
if ( F_147 ( F_148 () , V_184 , V_129 ) )
perror ( V_168 [ 0 ] ) ;
} else
perror ( V_168 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_141 ) {
struct V_185 V_186 = {
. V_187 = V_188 ,
. V_189 = F_141 ,
} ;
V_185 ( V_184 , & V_186 , NULL ) ;
}
if ( F_149 ( V_145 ) ) {
if ( V_2 -> V_6 == NULL ) {
fprintf ( V_108 , L_13 ,
V_190 , __LINE__ ) ;
goto V_177;
}
V_2 -> V_6 -> V_191 [ 0 ] = V_2 -> V_12 . V_13 ;
}
F_145 ( V_173 [ 1 ] ) ;
F_145 ( V_174 [ 0 ] ) ;
if ( F_83 ( V_173 [ 0 ] , & V_175 , 1 ) == - 1 ) {
perror ( L_12 ) ;
goto V_177;
}
F_67 ( V_174 [ 1 ] , V_180 , V_181 ) ;
V_2 -> V_12 . V_192 = V_174 [ 1 ] ;
F_145 ( V_173 [ 0 ] ) ;
return 0 ;
V_177:
F_145 ( V_174 [ 0 ] ) ;
F_145 ( V_174 [ 1 ] ) ;
V_176:
F_145 ( V_173 [ 0 ] ) ;
F_145 ( V_173 [ 1 ] ) ;
return - 1 ;
}
int F_150 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_192 > 0 ) {
char V_175 = 0 ;
int V_80 ;
V_80 = F_151 ( V_2 -> V_12 . V_192 , & V_175 , 1 ) ;
if ( V_80 < 0 )
perror ( L_14 ) ;
F_145 ( V_2 -> V_12 . V_192 ) ;
return V_80 ;
}
return 0 ;
}
int F_152 ( struct V_1 * V_2 , union V_91 * V_92 ,
struct V_156 * V_94 )
{
struct V_14 * V_18 = F_89 ( V_2 , V_92 ) ;
if ( ! V_18 )
return - V_193 ;
return F_153 ( V_18 , V_92 , V_94 ) ;
}
T_1 F_154 ( struct V_1 * V_2 , T_7 * V_194 )
{
struct V_14 * V_18 ;
T_1 V_195 = 0 ;
F_14 (evlist, evsel) {
V_195 += fprintf ( V_194 , L_15 , V_18 -> V_25 ? L_16 : L_17 ,
F_155 ( V_18 ) ) ;
}
return V_195 + fprintf ( V_194 , L_18 ) ;
}
int F_156 ( struct V_1 * V_2 V_137 ,
int V_59 , char * V_196 , T_1 V_96 )
{
char V_197 [ 128 ] ;
switch ( V_59 ) {
case V_198 :
F_157 ( V_196 , V_96 , L_19 ,
L_20
L_21
L_22
L_23 ) ;
break;
case V_199 :
F_157 ( V_196 , V_96 ,
L_24
L_25 ,
V_200 , V_200 ) ;
break;
default:
F_157 ( V_196 , V_96 , L_19 , F_158 ( V_59 , V_197 , sizeof( V_197 ) ) ) ;
break;
}
return 0 ;
}
int F_159 ( struct V_1 * V_2 V_137 ,
int V_59 , char * V_196 , T_1 V_96 )
{
int V_195 , V_139 ;
char V_197 [ V_201 ] , * V_202 = F_158 ( V_59 , V_197 , sizeof( V_197 ) ) ;
switch ( V_59 ) {
case V_199 :
case V_203 :
V_195 = F_157 ( V_196 , V_96 ,
L_26
L_27 , V_202 ) ;
V_139 = F_160 () ;
V_195 += F_157 ( V_196 + V_195 , V_96 - V_195 , L_28 ) ;
if ( V_139 >= 2 ) {
V_195 += F_157 ( V_196 + V_195 , V_96 - V_195 ,
L_29 ) ;
}
V_195 += F_157 ( V_196 + V_195 , V_96 - V_195 ,
L_30 ) ;
V_195 += F_157 ( V_196 + V_195 , V_96 - V_195 ,
L_31
L_32 , V_139 ) ;
break;
default:
F_157 ( V_196 , V_96 , L_19 , V_202 ) ;
break;
}
return 0 ;
}
void F_161 ( struct V_1 * V_2 ,
struct V_14 * V_204 )
{
struct V_14 * V_18 , * V_20 ;
F_39 ( V_205 ) ;
if ( V_204 == F_12 ( V_2 ) )
return;
F_17 (evlist, n, evsel) {
if ( V_18 -> V_30 == V_204 -> V_30 )
F_162 ( & V_18 -> V_21 , & V_205 ) ;
}
F_163 ( & V_205 , & V_2 -> V_10 ) ;
}
void F_164 ( struct V_1 * V_2 ,
struct V_14 * V_206 )
{
struct V_14 * V_18 ;
if ( V_206 -> V_26 )
return;
F_14 (evlist, evsel) {
if ( V_18 != V_206 )
V_18 -> V_26 = false ;
}
V_206 -> V_26 = true ;
}
