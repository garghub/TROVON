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
F_14 (evlist, evsel) {
if ( V_18 -> V_51 )
V_62 += V_54 ;
else
V_62 += V_54 * V_55 ;
}
if ( F_62 ( & V_2 -> V_11 ) < V_62 &&
F_63 ( & V_2 -> V_11 , V_62 ) < 0 )
return - V_42 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , int V_56 , int V_25 )
{
int V_19 = F_65 ( & V_2 -> V_11 , V_56 , V_63 | V_64 | V_65 ) ;
if ( V_19 >= 0 ) {
V_2 -> V_11 . V_66 [ V_19 ] . V_25 = V_25 ;
F_66 ( V_56 , V_67 , V_68 ) ;
}
return V_19 ;
}
int F_67 ( struct V_1 * V_2 , int V_56 )
{
return F_64 ( V_2 , V_56 , - 1 ) ;
}
static void F_68 ( struct V_69 * V_70 , int V_56 )
{
struct V_1 * V_2 = F_69 ( V_70 , struct V_1 , V_11 ) ;
F_70 ( V_2 , V_70 -> V_66 [ V_56 ] . V_25 ) ;
}
int F_71 ( struct V_1 * V_2 , short V_71 )
{
return F_72 ( & V_2 -> V_11 , V_71 ,
F_68 ) ;
}
int F_73 ( struct V_1 * V_2 , int V_72 )
{
return F_74 ( & V_2 -> V_11 , V_72 ) ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_52 , int V_53 , T_2 V_47 )
{
int V_73 ;
struct V_74 * V_75 = F_76 ( V_18 , V_52 , V_53 ) ;
V_75 -> V_47 = V_47 ;
V_75 -> V_18 = V_18 ;
V_73 = F_77 ( V_75 -> V_47 , V_76 ) ;
F_78 ( & V_75 -> V_21 , & V_2 -> V_9 [ V_73 ] ) ;
}
void F_79 ( struct V_1 * V_2 , struct V_14 * V_18 ,
int V_52 , int V_53 , T_2 V_47 )
{
F_75 ( V_2 , V_18 , V_52 , V_53 , V_47 ) ;
V_18 -> V_47 [ V_18 -> V_77 ++ ] = V_47 ;
}
static int F_80 ( struct V_1 * V_2 ,
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
if ( F_81 ( V_2 ) & V_85 )
return - 1 ;
if ( ! ( V_18 -> V_36 . V_86 & V_87 ) ||
F_82 ( V_56 , & V_78 , sizeof( V_78 ) ) == - 1 )
return - 1 ;
if ( V_18 -> V_36 . V_86 & V_88 )
++ V_79 ;
if ( V_18 -> V_36 . V_86 & V_89 )
++ V_79 ;
V_47 = V_78 [ V_79 ] ;
V_82:
F_79 ( V_2 , V_18 , V_52 , V_53 , V_47 ) ;
return 0 ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_25 , int V_52 ,
int V_53 )
{
struct V_74 * V_75 = F_76 ( V_18 , V_52 , V_53 ) ;
V_75 -> V_25 = V_25 ;
if ( V_2 -> V_4 && V_52 >= 0 )
V_75 -> V_52 = V_2 -> V_4 -> V_90 [ V_52 ] ;
else
V_75 -> V_52 = - 1 ;
if ( ! V_18 -> V_51 && V_2 -> V_6 && V_53 >= 0 )
V_75 -> V_91 = V_2 -> V_6 -> V_90 [ V_53 ] ;
else
V_75 -> V_91 = - 1 ;
}
struct V_74 * F_84 ( struct V_1 * V_2 , T_2 V_47 )
{
struct V_92 * V_45 ;
struct V_74 * V_75 ;
int V_73 ;
V_73 = F_77 ( V_47 , V_76 ) ;
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
union V_93 * V_94 , T_2 * V_47 )
{
const T_2 * V_95 = V_94 -> V_96 . V_95 ;
T_3 V_20 ;
V_20 = ( V_94 -> V_97 . V_98 - sizeof( V_94 -> V_97 ) ) >> 3 ;
if ( V_94 -> V_97 . type == V_99 ) {
if ( V_2 -> V_16 >= V_20 )
return - 1 ;
* V_47 = V_95 [ V_2 -> V_16 ] ;
} else {
if ( V_2 -> V_17 > V_20 )
return - 1 ;
V_20 -= V_2 -> V_17 ;
* V_47 = V_95 [ V_20 ] ;
}
return 0 ;
}
static struct V_14 * F_89 ( struct V_1 * V_2 ,
union V_93 * V_94 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
struct V_92 * V_45 ;
struct V_74 * V_75 ;
int V_73 ;
T_2 V_47 ;
if ( V_2 -> V_22 == 1 )
return V_15 ;
if ( ! V_15 -> V_36 . V_100 &&
V_94 -> V_97 . type != V_99 )
return V_15 ;
if ( F_88 ( V_2 , V_94 , & V_47 ) )
return NULL ;
if ( ! V_47 )
return V_15 ;
V_73 = F_77 ( V_47 , V_76 ) ;
V_45 = & V_2 -> V_9 [ V_73 ] ;
F_85 (sid, head, node) {
if ( V_75 -> V_47 == V_47 )
return V_75 -> V_18 ;
}
return NULL ;
}
union V_93 * F_90 ( struct V_1 * V_2 , int V_25 )
{
struct V_101 * V_102 = & V_2 -> V_23 [ V_25 ] ;
unsigned int V_45 = F_91 ( V_102 ) ;
unsigned int V_103 = V_102 -> V_32 ;
unsigned char * V_104 = V_102 -> V_105 + V_106 ;
union V_93 * V_94 = NULL ;
if ( V_2 -> V_107 ) {
int V_108 = V_45 - V_103 ;
if ( V_108 > V_102 -> V_109 / 2 || V_108 < 0 ) {
fprintf ( V_110 , L_2 ) ;
V_103 = V_45 ;
}
}
if ( V_103 != V_45 ) {
T_1 V_98 ;
V_94 = (union V_93 * ) & V_104 [ V_103 & V_102 -> V_109 ] ;
V_98 = V_94 -> V_97 . V_98 ;
if ( ( V_103 & V_102 -> V_109 ) + V_98 != ( ( V_103 + V_98 ) & V_102 -> V_109 ) ) {
unsigned int V_111 = V_103 ;
unsigned int V_112 = F_92 ( sizeof( * V_94 ) , V_98 ) , V_113 ;
void * V_114 = V_102 -> V_115 ;
do {
V_113 = F_92 ( V_102 -> V_109 + 1 - ( V_111 & V_102 -> V_109 ) , V_112 ) ;
memcpy ( V_114 , & V_104 [ V_111 & V_102 -> V_109 ] , V_113 ) ;
V_111 += V_113 ;
V_114 += V_113 ;
V_112 -= V_113 ;
} while ( V_112 );
V_94 = (union V_93 * ) V_102 -> V_115 ;
}
V_103 += V_98 ;
}
V_102 -> V_32 = V_103 ;
return V_94 ;
}
static bool F_93 ( struct V_101 * V_102 )
{
return F_91 ( V_102 ) != V_102 -> V_32 ;
}
static void F_94 ( struct V_1 * V_2 , int V_25 )
{
++ V_2 -> V_23 [ V_25 ] . V_116 ;
}
static void F_70 ( struct V_1 * V_2 , int V_25 )
{
F_95 ( V_2 -> V_23 [ V_25 ] . V_116 == 0 ) ;
if ( -- V_2 -> V_23 [ V_25 ] . V_116 == 0 )
F_96 ( V_2 , V_25 ) ;
}
void F_97 ( struct V_1 * V_2 , int V_25 )
{
struct V_101 * V_102 = & V_2 -> V_23 [ V_25 ] ;
if ( ! V_2 -> V_107 ) {
unsigned int V_103 = V_102 -> V_32 ;
F_98 ( V_102 , V_103 ) ;
}
if ( V_102 -> V_116 == 1 && F_93 ( V_102 ) )
F_70 ( V_2 , V_25 ) ;
}
static void F_96 ( struct V_1 * V_2 , int V_25 )
{
if ( V_2 -> V_23 [ V_25 ] . V_105 != NULL ) {
F_99 ( V_2 -> V_23 [ V_25 ] . V_105 , V_2 -> V_117 ) ;
V_2 -> V_23 [ V_25 ] . V_105 = NULL ;
V_2 -> V_23 [ V_25 ] . V_116 = 0 ;
}
}
void F_23 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_23 == NULL )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_118 ; V_7 ++ )
F_96 ( V_2 , V_7 ) ;
F_21 ( & V_2 -> V_23 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
V_2 -> V_118 = F_50 ( V_2 -> V_4 ) ;
if ( F_60 ( V_2 -> V_4 ) )
V_2 -> V_118 = F_48 ( V_2 -> V_6 ) ;
V_2 -> V_23 = F_7 ( V_2 -> V_118 * sizeof( struct V_101 ) ) ;
return V_2 -> V_23 != NULL ? 0 : - V_42 ;
}
static int F_101 ( struct V_1 * V_2 , int V_25 ,
struct V_119 * V_120 , int V_56 )
{
V_2 -> V_23 [ V_25 ] . V_116 = 2 ;
V_2 -> V_23 [ V_25 ] . V_32 = 0 ;
V_2 -> V_23 [ V_25 ] . V_109 = V_120 -> V_109 ;
V_2 -> V_23 [ V_25 ] . V_105 = V_23 ( NULL , V_2 -> V_117 , V_120 -> V_121 ,
V_122 , V_56 , 0 ) ;
if ( V_2 -> V_23 [ V_25 ] . V_105 == V_123 ) {
F_102 ( L_3 ,
V_83 ) ;
V_2 -> V_23 [ V_25 ] . V_105 = NULL ;
return - 1 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 , int V_25 ,
struct V_119 * V_120 , int V_52 ,
int V_53 , int * V_124 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
int V_56 ;
if ( V_18 -> V_51 && V_53 )
continue;
V_56 = F_53 ( V_18 , V_52 , V_53 ) ;
if ( * V_124 == - 1 ) {
* V_124 = V_56 ;
if ( F_101 ( V_2 , V_25 , V_120 , * V_124 ) < 0 )
return - 1 ;
} else {
if ( F_52 ( V_56 , V_125 , * V_124 ) != 0 )
return - 1 ;
F_94 ( V_2 , V_25 ) ;
}
if ( ! V_18 -> V_51 &&
F_64 ( V_2 , V_56 , V_25 ) < 0 ) {
F_70 ( V_2 , V_25 ) ;
return - 1 ;
}
if ( V_18 -> V_36 . V_86 & V_87 ) {
if ( F_80 ( V_2 , V_18 , V_52 , V_53 ,
V_56 ) < 0 )
return - 1 ;
F_83 ( V_2 , V_18 , V_25 , V_52 ,
V_53 ) ;
}
}
return 0 ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
int V_52 , V_53 ;
int V_54 = F_50 ( V_2 -> V_4 ) ;
int V_55 = F_48 ( V_2 -> V_6 ) ;
F_102 ( L_4 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
int V_124 = - 1 ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
if ( F_103 ( V_2 , V_52 , V_120 , V_52 ,
V_53 , & V_124 ) )
goto V_126;
}
}
return 0 ;
V_126:
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ )
F_96 ( V_2 , V_52 ) ;
return - 1 ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
int V_53 ;
int V_55 = F_48 ( V_2 -> V_6 ) ;
F_102 ( L_5 ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
int V_124 = - 1 ;
if ( F_103 ( V_2 , V_53 , V_120 , 0 , V_53 ,
& V_124 ) )
goto V_126;
}
return 0 ;
V_126:
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ )
F_96 ( V_2 , V_53 ) ;
return - 1 ;
}
static T_1 F_106 ( unsigned long V_127 )
{
if ( V_127 == V_128 ) {
int V_129 ;
if ( F_107 ( L_6 , & V_129 ) < 0 ) {
V_129 = 512 ;
} else {
V_129 -= ( V_106 / 1024 ) ;
}
V_127 = ( V_129 * 1024 ) / V_106 ;
if ( ! F_108 ( V_127 ) )
V_127 = F_109 ( V_127 ) ;
} else if ( ! F_108 ( V_127 ) )
return 0 ;
return ( V_127 + 1 ) * V_106 ;
}
static long F_110 ( const char * V_130 , unsigned long F_92 ,
unsigned long V_129 )
{
unsigned long V_127 , V_131 ;
static struct V_132 V_133 [] = {
{ . V_134 = 'B' , . V_135 = 1 } ,
{ . V_134 = 'K' , . V_135 = 1 << 10 } ,
{ . V_134 = 'M' , . V_135 = 1 << 20 } ,
{ . V_134 = 'G' , . V_135 = 1 << 30 } ,
{ . V_134 = 0 } ,
} ;
if ( V_130 == NULL )
return - V_60 ;
V_131 = F_111 ( V_130 , V_133 ) ;
if ( V_131 != ( unsigned long ) - 1 ) {
V_127 = F_112 ( V_131 , V_106 ) / V_106 ;
} else {
char * V_136 ;
V_127 = strtoul ( V_130 , & V_136 , 10 ) ;
if ( * V_136 != '\0' )
return - V_60 ;
}
if ( V_127 == 0 && F_92 == 0 ) {
} else if ( ! F_108 ( V_127 ) ) {
V_127 = F_113 ( V_127 ) ;
if ( ! V_127 )
return - V_60 ;
F_114 ( L_7 ,
V_127 * V_106 , V_127 ) ;
}
if ( V_127 > V_129 )
return - V_60 ;
return V_127 ;
}
int F_115 ( const struct V_137 * V_138 , const char * V_130 ,
int T_4 V_139 )
{
unsigned int * V_140 = V_138 -> V_141 ;
unsigned long V_129 = V_128 ;
long V_127 ;
if ( V_129 > V_142 / V_106 )
V_129 = V_142 / V_106 ;
V_127 = F_110 ( V_130 , 1 , V_129 ) ;
if ( V_127 < 0 ) {
F_116 ( L_8 ) ;
return - 1 ;
}
* V_140 = V_127 ;
return 0 ;
}
int F_117 ( struct V_1 * V_2 , unsigned int V_127 ,
bool V_107 )
{
struct V_14 * V_18 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
struct V_119 V_120 = {
. V_121 = V_143 | ( V_107 ? 0 : V_144 ) ,
} ;
if ( V_2 -> V_23 == NULL && F_100 ( V_2 ) < 0 )
return - V_42 ;
if ( V_2 -> V_11 . V_10 == NULL && F_61 ( V_2 ) < 0 )
return - V_42 ;
V_2 -> V_107 = V_107 ;
V_2 -> V_117 = F_106 ( V_127 ) ;
F_118 ( L_9 , V_2 -> V_117 ) ;
V_120 . V_109 = V_2 -> V_117 - V_106 - 1 ;
F_14 (evlist, evsel) {
if ( ( V_18 -> V_36 . V_86 & V_87 ) &&
V_18 -> V_145 == NULL &&
F_119 ( V_18 , F_50 ( V_4 ) , V_6 -> V_146 ) < 0 )
return - V_42 ;
}
if ( F_60 ( V_4 ) )
return F_105 ( V_2 , & V_120 ) ;
return F_104 ( V_2 , & V_120 ) ;
}
int F_120 ( struct V_1 * V_2 , struct V_147 * V_147 )
{
V_2 -> V_6 = F_121 ( V_147 -> V_13 , V_147 -> V_91 ,
V_147 -> V_148 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( F_122 ( V_147 ) )
V_2 -> V_4 = F_123 () ;
else
V_2 -> V_4 = F_124 ( V_147 -> V_149 ) ;
if ( V_2 -> V_4 == NULL )
goto V_150;
return 0 ;
V_150:
F_26 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
return - 1 ;
}
int F_125 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_59 = 0 ;
const int V_151 = F_50 ( V_2 -> V_4 ) ,
V_152 = F_48 ( V_2 -> V_6 ) ;
F_14 (evlist, evsel) {
if ( V_18 -> V_153 == NULL )
continue;
V_59 = F_126 ( V_18 , V_151 , V_152 , V_18 -> V_153 ) ;
if ( V_59 )
break;
}
return V_59 ;
}
int F_127 ( struct V_1 * V_2 , const char * V_153 )
{
struct V_14 * V_18 ;
int V_59 = 0 ;
const int V_151 = F_50 ( V_2 -> V_4 ) ,
V_152 = F_48 ( V_2 -> V_6 ) ;
F_14 (evlist, evsel) {
V_59 = F_126 ( V_18 , V_151 , V_152 , V_153 ) ;
if ( V_59 )
break;
}
return V_59 ;
}
bool F_128 ( struct V_1 * V_2 )
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
T_2 F_129 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
if ( V_2 -> V_154 )
return V_2 -> V_154 ;
F_14 (evlist, evsel)
V_2 -> V_154 |= V_18 -> V_36 . V_155 ;
return V_2 -> V_154 ;
}
T_2 F_130 ( struct V_1 * V_2 )
{
V_2 -> V_154 = 0 ;
return F_129 ( V_2 ) ;
}
bool F_131 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) , * V_19 = V_15 ;
T_2 V_86 = V_15 -> V_36 . V_86 ;
T_2 V_155 = V_15 -> V_36 . V_155 ;
F_14 (evlist, pos) {
if ( V_86 != V_19 -> V_36 . V_86 )
return false ;
}
if ( ( V_155 & V_156 ) &&
! ( V_86 & V_87 ) ) {
return false ;
}
return true ;
}
T_2 F_81 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
return V_15 -> V_36 . V_86 ;
}
T_5 F_132 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
struct V_157 * V_104 ;
T_2 V_155 ;
T_5 V_98 = 0 ;
if ( ! V_15 -> V_36 . V_100 )
goto V_158;
V_155 = V_15 -> V_36 . V_155 ;
if ( V_155 & V_159 )
V_98 += sizeof( V_104 -> V_91 ) * 2 ;
if ( V_155 & V_160 )
V_98 += sizeof( V_104 -> time ) ;
if ( V_155 & V_161 )
V_98 += sizeof( V_104 -> V_47 ) ;
if ( V_155 & V_162 )
V_98 += sizeof( V_104 -> V_163 ) ;
if ( V_155 & V_164 )
V_98 += sizeof( V_104 -> V_52 ) * 2 ;
if ( V_155 & V_165 )
V_98 += sizeof( V_104 -> V_47 ) ;
V_158:
return V_98 ;
}
bool F_133 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) , * V_19 = V_15 ;
F_134 (evlist, pos) {
if ( V_15 -> V_36 . V_100 != V_19 -> V_36 . V_100 )
return false ;
}
return true ;
}
bool F_87 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
return V_15 -> V_36 . V_100 ;
}
void F_135 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
V_2 -> V_166 = V_18 ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_151 = F_50 ( V_2 -> V_4 ) ;
int V_152 = F_48 ( V_2 -> V_6 ) ;
int V_20 ;
F_136 (evlist, evsel) {
V_20 = V_18 -> V_4 ? V_18 -> V_4 -> V_146 : V_151 ;
F_137 ( V_18 , V_20 , V_152 ) ;
}
}
static int F_138 ( struct V_1 * V_2 )
{
int V_59 = - V_42 ;
V_2 -> V_4 = F_124 ( NULL ) ;
if ( V_2 -> V_4 == NULL )
goto V_158;
V_2 -> V_6 = F_139 () ;
if ( V_2 -> V_6 == NULL )
goto V_167;
V_59 = 0 ;
V_158:
return V_59 ;
V_167:
F_25 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
goto V_158;
}
int F_140 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_59 ;
if ( V_2 -> V_6 == NULL && V_2 -> V_4 == NULL ) {
V_59 = F_138 ( V_2 ) ;
if ( V_59 < 0 )
goto V_168;
}
F_13 ( V_2 ) ;
F_14 (evlist, evsel) {
V_59 = F_141 ( V_18 , V_2 -> V_4 , V_2 -> V_6 ) ;
if ( V_59 < 0 )
goto V_168;
}
return 0 ;
V_168:
F_24 ( V_2 ) ;
V_83 = - V_59 ;
return V_59 ;
}
int F_142 ( struct V_1 * V_2 , struct V_147 * V_147 ,
const char * V_169 [] , bool V_170 ,
void (* F_143)( int V_171 , T_6 * V_172 , void * V_173 ) )
{
int V_174 [ 2 ] , V_175 [ 2 ] ;
char V_176 ;
if ( F_144 ( V_174 ) < 0 ) {
perror ( L_10 ) ;
return - 1 ;
}
if ( F_144 ( V_175 ) < 0 ) {
perror ( L_11 ) ;
goto V_177;
}
V_2 -> V_12 . V_13 = F_145 () ;
if ( V_2 -> V_12 . V_13 < 0 ) {
perror ( L_12 ) ;
goto V_178;
}
if ( ! V_2 -> V_12 . V_13 ) {
int V_80 ;
if ( V_170 )
F_146 ( 2 , 1 ) ;
signal ( V_179 , V_180 ) ;
F_147 ( V_174 [ 0 ] ) ;
F_147 ( V_175 [ 1 ] ) ;
F_66 ( V_175 [ 0 ] , V_181 , V_182 ) ;
F_147 ( V_174 [ 1 ] ) ;
V_80 = F_82 ( V_175 [ 0 ] , & V_176 , 1 ) ;
if ( V_80 != 1 ) {
if ( V_80 == - 1 )
perror ( L_13 ) ;
exit ( V_80 ) ;
}
F_148 ( V_169 [ 0 ] , ( char * * ) V_169 ) ;
if ( F_143 ) {
union V_183 V_131 ;
V_131 . V_184 = V_83 ;
if ( F_149 ( F_150 () , V_185 , V_131 ) )
perror ( V_169 [ 0 ] ) ;
} else
perror ( V_169 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_143 ) {
struct V_186 V_187 = {
. V_188 = V_189 ,
. V_190 = F_143 ,
} ;
V_186 ( V_185 , & V_187 , NULL ) ;
}
if ( F_151 ( V_147 ) ) {
if ( V_2 -> V_6 == NULL ) {
fprintf ( V_110 , L_14 ,
V_191 , __LINE__ ) ;
goto V_178;
}
V_2 -> V_6 -> V_90 [ 0 ] = V_2 -> V_12 . V_13 ;
}
F_147 ( V_174 [ 1 ] ) ;
F_147 ( V_175 [ 0 ] ) ;
if ( F_82 ( V_174 [ 0 ] , & V_176 , 1 ) == - 1 ) {
perror ( L_13 ) ;
goto V_178;
}
F_66 ( V_175 [ 1 ] , V_181 , V_182 ) ;
V_2 -> V_12 . V_192 = V_175 [ 1 ] ;
F_147 ( V_174 [ 0 ] ) ;
return 0 ;
V_178:
F_147 ( V_175 [ 0 ] ) ;
F_147 ( V_175 [ 1 ] ) ;
V_177:
F_147 ( V_174 [ 0 ] ) ;
F_147 ( V_174 [ 1 ] ) ;
return - 1 ;
}
int F_152 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_192 > 0 ) {
char V_176 = 0 ;
int V_80 ;
V_80 = F_153 ( V_2 -> V_12 . V_192 , & V_176 , 1 ) ;
if ( V_80 < 0 )
perror ( L_15 ) ;
F_147 ( V_2 -> V_12 . V_192 ) ;
return V_80 ;
}
return 0 ;
}
int F_154 ( struct V_1 * V_2 , union V_93 * V_94 ,
struct V_157 * V_96 )
{
struct V_14 * V_18 = F_89 ( V_2 , V_94 ) ;
if ( ! V_18 )
return - V_193 ;
return F_155 ( V_18 , V_94 , V_96 ) ;
}
T_1 F_156 ( struct V_1 * V_2 , T_7 * V_194 )
{
struct V_14 * V_18 ;
T_1 V_195 = 0 ;
F_14 (evlist, evsel) {
V_195 += fprintf ( V_194 , L_16 , V_18 -> V_25 ? L_17 : L_18 ,
F_157 ( V_18 ) ) ;
}
return V_195 + fprintf ( V_194 , L_19 ) ;
}
int F_158 ( struct V_1 * V_2 V_139 ,
int V_59 , char * V_196 , T_1 V_98 )
{
int V_195 , V_141 ;
char V_197 [ V_198 ] , * V_199 = F_159 ( V_59 , V_197 , sizeof( V_197 ) ) ;
switch ( V_59 ) {
case V_200 :
case V_201 :
V_195 = F_160 ( V_196 , V_98 ,
L_20
L_21 , V_199 ) ;
V_141 = F_161 () ;
V_195 += F_160 ( V_196 + V_195 , V_98 - V_195 , L_22 ) ;
if ( V_141 >= 2 ) {
V_195 += F_160 ( V_196 + V_195 , V_98 - V_195 ,
L_23 ) ;
}
V_195 += F_160 ( V_196 + V_195 , V_98 - V_195 ,
L_24 ) ;
V_195 += F_160 ( V_196 + V_195 , V_98 - V_195 ,
L_25
L_26 , V_141 ) ;
break;
default:
F_160 ( V_196 , V_98 , L_27 , V_199 ) ;
break;
}
return 0 ;
}
int F_162 ( struct V_1 * V_2 , int V_59 , char * V_196 , T_1 V_98 )
{
char V_197 [ V_198 ] , * V_199 = F_159 ( V_59 , V_197 , sizeof( V_197 ) ) ;
int V_202 = V_2 -> V_117 / 1024 , V_203 , V_195 = 0 ;
switch ( V_59 ) {
case V_201 :
F_107 ( L_6 , & V_203 ) ;
V_195 += F_160 ( V_196 + V_195 , V_98 - V_195 ,
L_20
L_28
L_29 ,
V_199 , V_203 , V_202 ) ;
if ( V_202 >= V_203 ) {
V_195 += F_160 ( V_196 + V_195 , V_98 - V_195 ,
L_30 ,
V_203 + V_202 ) ;
}
V_195 += F_160 ( V_196 + V_195 , V_98 - V_195 ,
L_31 ) ;
break;
default:
F_160 ( V_196 , V_98 , L_27 , V_199 ) ;
break;
}
return 0 ;
}
void F_163 ( struct V_1 * V_2 ,
struct V_14 * V_204 )
{
struct V_14 * V_18 , * V_20 ;
F_39 ( V_205 ) ;
if ( V_204 == F_12 ( V_2 ) )
return;
F_17 (evlist, n, evsel) {
if ( V_18 -> V_30 == V_204 -> V_30 )
F_164 ( & V_18 -> V_21 , & V_205 ) ;
}
F_165 ( & V_205 , & V_2 -> V_10 ) ;
}
void F_166 ( struct V_1 * V_2 ,
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
