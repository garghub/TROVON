void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 )
F_2 ( & V_2 -> V_9 [ V_7 ] ) ;
F_3 ( & V_2 -> V_10 ) ;
F_4 ( V_2 , V_4 , V_6 ) ;
V_2 -> V_11 . V_12 = - 1 ;
}
struct V_1 * F_5 ( void )
{
struct V_1 * V_2 = F_6 ( sizeof( * V_2 ) ) ;
if ( V_2 != NULL )
F_1 ( V_2 , NULL , NULL ) ;
return V_2 ;
}
struct V_1 * F_7 ( void )
{
struct V_1 * V_2 = F_5 () ;
if ( V_2 && F_8 ( V_2 ) ) {
F_9 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
V_2 -> V_15 = V_14 -> V_15 ;
V_2 -> V_16 = V_14 -> V_16 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
F_13 (evlist, evsel)
F_14 ( V_17 ) ;
F_10 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_13 * V_18 , * V_19 ;
F_16 (evlist, n, pos) {
F_17 ( & V_18 -> V_20 ) ;
F_18 ( V_18 ) ;
}
V_2 -> V_21 = 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_22 ) ;
F_20 ( & V_2 -> V_23 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 -> V_4 ) ;
F_24 ( V_2 -> V_6 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_6 = NULL ;
F_15 ( V_2 ) ;
F_19 ( V_2 ) ;
free ( V_2 ) ;
}
void F_25 ( struct V_1 * V_2 , struct V_13 * V_24 )
{
F_26 ( & V_24 -> V_20 , & V_2 -> V_10 ) ;
V_24 -> V_25 = V_2 -> V_21 ;
if ( ! V_2 -> V_21 ++ )
F_10 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
int V_21 )
{
bool V_28 = ! V_2 -> V_21 ;
F_28 ( V_27 , & V_2 -> V_10 ) ;
V_2 -> V_21 += V_21 ;
if ( V_28 )
F_10 ( V_2 ) ;
}
void F_29 ( struct V_26 * V_27 )
{
struct V_13 * V_17 , * V_29 ;
V_29 = F_30 ( V_27 -> V_30 , struct V_13 , V_20 ) ;
V_17 = F_30 ( V_27 -> V_31 , struct V_13 , V_20 ) ;
V_29 -> V_32 = V_17 -> V_25 - V_29 -> V_25 + 1 ;
F_31 (list, evsel) {
V_17 -> V_29 = V_29 ;
}
}
void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 ) {
V_2 -> V_33 = V_2 -> V_21 > 1 ? 1 : 0 ;
F_29 ( & V_2 -> V_10 ) ;
}
}
int F_8 ( struct V_1 * V_2 )
{
struct V_34 V_35 = {
. type = V_36 ,
. V_37 = V_38 ,
} ;
struct V_13 * V_17 ;
F_33 ( & V_35 ) ;
V_17 = F_34 ( & V_35 ) ;
if ( V_17 == NULL )
goto error;
V_17 -> V_39 = F_35 ( L_1 ) ;
if ( ! V_17 -> V_39 )
goto V_40;
F_25 ( V_2 , V_17 ) ;
return 0 ;
V_40:
F_18 ( V_17 ) ;
error:
return - V_41 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_34 * V_42 , T_1 V_43 )
{
struct V_13 * V_17 , * V_19 ;
F_37 ( V_44 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_43 ; V_7 ++ ) {
V_17 = F_38 ( V_42 + V_7 , V_2 -> V_21 + V_7 ) ;
if ( V_17 == NULL )
goto V_45;
F_26 ( & V_17 -> V_20 , & V_44 ) ;
}
F_27 ( V_2 , & V_44 , V_43 ) ;
return 0 ;
V_45:
F_39 (&head, n, evsel)
F_18 ( V_17 ) ;
return - 1 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_34 * V_42 , T_1 V_43 )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_43 ; V_7 ++ )
F_33 ( V_42 + V_7 ) ;
return F_36 ( V_2 , V_42 , V_43 ) ;
}
struct V_13 *
F_41 ( struct V_1 * V_2 , int V_46 )
{
struct V_13 * V_17 ;
F_13 (evlist, evsel) {
if ( V_17 -> V_35 . type == V_47 &&
( int ) V_17 -> V_35 . V_37 == V_46 )
return V_17 ;
}
return NULL ;
}
struct V_13 *
F_42 ( struct V_1 * V_2 ,
const char * V_39 )
{
struct V_13 * V_17 ;
F_13 (evlist, evsel) {
if ( ( V_17 -> V_35 . type == V_47 ) &&
( strcmp ( V_17 -> V_39 , V_39 ) == 0 ) )
return V_17 ;
}
return NULL ;
}
int F_43 ( struct V_1 * V_2 ,
const char * V_48 , const char * V_39 , void * V_49 )
{
struct V_13 * V_17 = F_44 ( V_48 , V_39 ) ;
if ( V_17 == NULL )
return - 1 ;
V_17 -> V_49 = V_49 ;
F_25 ( V_2 , V_17 ) ;
return 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
int V_50 , V_51 ;
struct V_13 * V_18 ;
int V_52 = F_46 ( V_2 -> V_4 ) ;
int V_53 = F_47 ( V_2 -> V_6 ) ;
for ( V_50 = 0 ; V_50 < V_52 ; V_50 ++ ) {
F_13 (evlist, pos) {
if ( ! F_48 ( V_18 ) || ! V_18 -> V_54 )
continue;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ )
F_49 ( F_50 ( V_18 , V_50 , V_51 ) ,
V_55 , 0 ) ;
}
}
}
void F_51 ( struct V_1 * V_2 )
{
int V_50 , V_51 ;
struct V_13 * V_18 ;
int V_52 = F_46 ( V_2 -> V_4 ) ;
int V_53 = F_47 ( V_2 -> V_6 ) ;
for ( V_50 = 0 ; V_50 < V_52 ; V_50 ++ ) {
F_13 (evlist, pos) {
if ( ! F_48 ( V_18 ) || ! V_18 -> V_54 )
continue;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ )
F_49 ( F_50 ( V_18 , V_50 , V_51 ) ,
V_56 , 0 ) ;
}
}
}
int F_52 ( struct V_1 * V_2 ,
struct V_13 * V_17 )
{
int V_50 , V_51 , V_57 ;
if ( ! V_17 -> V_54 )
return 0 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_4 -> V_58 ; V_50 ++ ) {
for ( V_51 = 0 ; V_51 < V_2 -> V_6 -> V_58 ; V_51 ++ ) {
V_57 = F_49 ( F_50 ( V_17 , V_50 , V_51 ) ,
V_55 , 0 ) ;
if ( V_57 )
return V_57 ;
}
}
return 0 ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_13 * V_17 )
{
int V_50 , V_51 , V_57 ;
if ( ! V_17 -> V_54 )
return - V_59 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_4 -> V_58 ; V_50 ++ ) {
for ( V_51 = 0 ; V_51 < V_2 -> V_6 -> V_58 ; V_51 ++ ) {
V_57 = F_49 ( F_50 ( V_17 , V_50 , V_51 ) ,
V_56 , 0 ) ;
if ( V_57 )
return V_57 ;
}
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_52 = F_46 ( V_2 -> V_4 ) ;
int V_53 = F_47 ( V_2 -> V_6 ) ;
int V_60 = V_52 * V_53 * V_2 -> V_21 ;
V_2 -> V_23 = malloc ( sizeof( struct V_23 ) * V_60 ) ;
return V_2 -> V_23 != NULL ? 0 : - V_41 ;
}
void F_55 ( struct V_1 * V_2 , int V_54 )
{
F_56 ( V_54 , V_61 , V_62 ) ;
V_2 -> V_23 [ V_2 -> V_63 ] . V_54 = V_54 ;
V_2 -> V_23 [ V_2 -> V_63 ] . V_64 = V_65 ;
V_2 -> V_63 ++ ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_13 * V_17 ,
int V_50 , int V_51 , T_2 V_46 )
{
int V_66 ;
struct V_67 * V_68 = F_58 ( V_17 , V_50 , V_51 ) ;
V_68 -> V_46 = V_46 ;
V_68 -> V_17 = V_17 ;
V_66 = F_59 ( V_68 -> V_46 , V_69 ) ;
F_60 ( & V_68 -> V_20 , & V_2 -> V_9 [ V_66 ] ) ;
}
void F_61 ( struct V_1 * V_2 , struct V_13 * V_17 ,
int V_50 , int V_51 , T_2 V_46 )
{
F_57 ( V_2 , V_17 , V_50 , V_51 , V_46 ) ;
V_17 -> V_46 [ V_17 -> V_70 ++ ] = V_46 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_13 * V_17 ,
int V_50 , int V_51 , int V_54 )
{
T_2 V_71 [ 4 ] = { 0 , } ;
int V_72 = 1 ;
T_2 V_46 ;
int V_73 ;
V_73 = F_49 ( V_54 , V_74 , & V_46 ) ;
if ( ! V_73 )
goto V_75;
if ( V_76 != V_77 )
return - 1 ;
if ( F_63 ( V_2 ) & V_78 )
return - 1 ;
if ( ! ( V_17 -> V_35 . V_79 & V_80 ) ||
F_64 ( V_54 , & V_71 , sizeof( V_71 ) ) == - 1 )
return - 1 ;
if ( V_17 -> V_35 . V_79 & V_81 )
++ V_72 ;
if ( V_17 -> V_35 . V_79 & V_82 )
++ V_72 ;
V_46 = V_71 [ V_72 ] ;
V_75:
F_61 ( V_2 , V_17 , V_50 , V_51 , V_46 ) ;
return 0 ;
}
struct V_67 * F_65 ( struct V_1 * V_2 , T_2 V_46 )
{
struct V_83 * V_44 ;
struct V_67 * V_68 ;
int V_66 ;
V_66 = F_59 ( V_46 , V_69 ) ;
V_44 = & V_2 -> V_9 [ V_66 ] ;
F_66 (sid, head, node)
if ( V_68 -> V_46 == V_46 )
return V_68 ;
return NULL ;
}
struct V_13 * F_67 ( struct V_1 * V_2 , T_2 V_46 )
{
struct V_67 * V_68 ;
if ( V_2 -> V_21 == 1 )
return F_11 ( V_2 ) ;
V_68 = F_65 ( V_2 , V_46 ) ;
if ( V_68 )
return V_68 -> V_17 ;
if ( ! F_68 ( V_2 ) )
return F_11 ( V_2 ) ;
return NULL ;
}
static int F_69 ( struct V_1 * V_2 ,
union V_84 * V_85 , T_2 * V_46 )
{
const T_2 * V_86 = V_85 -> V_87 . V_86 ;
T_3 V_19 ;
V_19 = ( V_85 -> V_88 . V_89 - sizeof( V_85 -> V_88 ) ) >> 3 ;
if ( V_85 -> V_88 . type == V_90 ) {
if ( V_2 -> V_15 >= V_19 )
return - 1 ;
* V_46 = V_86 [ V_2 -> V_15 ] ;
} else {
if ( V_2 -> V_16 > V_19 )
return - 1 ;
V_19 -= V_2 -> V_16 ;
* V_46 = V_86 [ V_19 ] ;
}
return 0 ;
}
static struct V_13 * F_70 ( struct V_1 * V_2 ,
union V_84 * V_85 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
struct V_83 * V_44 ;
struct V_67 * V_68 ;
int V_66 ;
T_2 V_46 ;
if ( V_2 -> V_21 == 1 )
return V_14 ;
if ( ! V_14 -> V_35 . V_91 &&
V_85 -> V_88 . type != V_90 )
return V_14 ;
if ( F_69 ( V_2 , V_85 , & V_46 ) )
return NULL ;
if ( ! V_46 )
return V_14 ;
V_66 = F_59 ( V_46 , V_69 ) ;
V_44 = & V_2 -> V_9 [ V_66 ] ;
F_66 (sid, head, node) {
if ( V_68 -> V_46 == V_46 )
return V_68 -> V_17 ;
}
return NULL ;
}
union V_84 * F_71 ( struct V_1 * V_2 , int V_25 )
{
struct V_92 * V_93 = & V_2 -> V_22 [ V_25 ] ;
unsigned int V_44 = F_72 ( V_93 ) ;
unsigned int V_94 = V_93 -> V_31 ;
unsigned char * V_95 = V_93 -> V_96 + V_97 ;
union V_84 * V_85 = NULL ;
if ( V_2 -> V_98 ) {
int V_99 = V_44 - V_94 ;
if ( V_99 > V_93 -> V_100 / 2 || V_99 < 0 ) {
fprintf ( V_101 , L_2 ) ;
V_94 = V_44 ;
}
}
if ( V_94 != V_44 ) {
T_1 V_89 ;
V_85 = (union V_84 * ) & V_95 [ V_94 & V_93 -> V_100 ] ;
V_89 = V_85 -> V_88 . V_89 ;
if ( ( V_94 & V_93 -> V_100 ) + V_89 != ( ( V_94 + V_89 ) & V_93 -> V_100 ) ) {
unsigned int V_102 = V_94 ;
unsigned int V_103 = F_73 ( sizeof( * V_85 ) , V_89 ) , V_104 ;
void * V_105 = V_93 -> V_106 ;
do {
V_104 = F_73 ( V_93 -> V_100 + 1 - ( V_102 & V_93 -> V_100 ) , V_103 ) ;
memcpy ( V_105 , & V_95 [ V_102 & V_93 -> V_100 ] , V_104 ) ;
V_102 += V_104 ;
V_105 += V_104 ;
V_103 -= V_104 ;
} while ( V_103 );
V_85 = (union V_84 * ) V_93 -> V_106 ;
}
V_94 += V_89 ;
}
V_93 -> V_31 = V_94 ;
return V_85 ;
}
void F_74 ( struct V_1 * V_2 , int V_25 )
{
if ( ! V_2 -> V_98 ) {
struct V_92 * V_93 = & V_2 -> V_22 [ V_25 ] ;
unsigned int V_94 = V_93 -> V_31 ;
F_75 ( V_93 , V_94 ) ;
}
}
static void F_76 ( struct V_1 * V_2 , int V_25 )
{
if ( V_2 -> V_22 [ V_25 ] . V_96 != NULL ) {
F_77 ( V_2 -> V_22 [ V_25 ] . V_96 , V_2 -> V_107 ) ;
V_2 -> V_22 [ V_25 ] . V_96 = NULL ;
}
}
void F_21 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_22 == NULL )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_108 ; V_7 ++ )
F_76 ( V_2 , V_7 ) ;
F_20 ( & V_2 -> V_22 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
V_2 -> V_108 = F_46 ( V_2 -> V_4 ) ;
if ( F_79 ( V_2 -> V_4 ) )
V_2 -> V_108 = F_47 ( V_2 -> V_6 ) ;
V_2 -> V_22 = F_6 ( V_2 -> V_108 * sizeof( struct V_92 ) ) ;
return V_2 -> V_22 != NULL ? 0 : - V_41 ;
}
static int F_80 ( struct V_1 * V_2 ,
int V_25 , int V_109 , int V_100 , int V_54 )
{
V_2 -> V_22 [ V_25 ] . V_31 = 0 ;
V_2 -> V_22 [ V_25 ] . V_100 = V_100 ;
V_2 -> V_22 [ V_25 ] . V_96 = V_22 ( NULL , V_2 -> V_107 , V_109 ,
V_110 , V_54 , 0 ) ;
if ( V_2 -> V_22 [ V_25 ] . V_96 == V_111 ) {
F_81 ( L_3 ,
V_76 ) ;
V_2 -> V_22 [ V_25 ] . V_96 = NULL ;
return - 1 ;
}
F_55 ( V_2 , V_54 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , int V_25 ,
int V_109 , int V_100 , int V_50 , int V_51 ,
int * V_112 )
{
struct V_13 * V_17 ;
F_13 (evlist, evsel) {
int V_54 = F_50 ( V_17 , V_50 , V_51 ) ;
if ( * V_112 == - 1 ) {
* V_112 = V_54 ;
if ( F_80 ( V_2 , V_25 , V_109 , V_100 ,
* V_112 ) < 0 )
return - 1 ;
} else {
if ( F_49 ( V_54 , V_113 , * V_112 ) != 0 )
return - 1 ;
}
if ( ( V_17 -> V_35 . V_79 & V_80 ) &&
F_62 ( V_2 , V_17 , V_50 , V_51 , V_54 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , int V_109 ,
int V_100 )
{
int V_50 , V_51 ;
int V_52 = F_46 ( V_2 -> V_4 ) ;
int V_53 = F_47 ( V_2 -> V_6 ) ;
F_81 ( L_4 ) ;
for ( V_50 = 0 ; V_50 < V_52 ; V_50 ++ ) {
int V_112 = - 1 ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
if ( F_82 ( V_2 , V_50 , V_109 , V_100 ,
V_50 , V_51 , & V_112 ) )
goto V_114;
}
}
return 0 ;
V_114:
for ( V_50 = 0 ; V_50 < V_52 ; V_50 ++ )
F_76 ( V_2 , V_50 ) ;
return - 1 ;
}
static int F_84 ( struct V_1 * V_2 , int V_109 ,
int V_100 )
{
int V_51 ;
int V_53 = F_47 ( V_2 -> V_6 ) ;
F_81 ( L_5 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
int V_112 = - 1 ;
if ( F_82 ( V_2 , V_51 , V_109 , V_100 , 0 ,
V_51 , & V_112 ) )
goto V_114;
}
return 0 ;
V_114:
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ )
F_76 ( V_2 , V_51 ) ;
return - 1 ;
}
static T_1 F_85 ( unsigned long V_115 )
{
if ( V_115 == V_116 )
V_115 = ( 512 * 1024 ) / V_97 ;
else if ( ! F_86 ( V_115 ) )
return 0 ;
return ( V_115 + 1 ) * V_97 ;
}
static long F_87 ( const char * V_117 , unsigned long F_73 ,
unsigned long V_118 )
{
unsigned long V_115 , V_119 ;
static struct V_120 V_121 [] = {
{ . V_122 = 'B' , . V_123 = 1 } ,
{ . V_122 = 'K' , . V_123 = 1 << 10 } ,
{ . V_122 = 'M' , . V_123 = 1 << 20 } ,
{ . V_122 = 'G' , . V_123 = 1 << 30 } ,
{ . V_122 = 0 } ,
} ;
if ( V_117 == NULL )
return - V_59 ;
V_119 = F_88 ( V_117 , V_121 ) ;
if ( V_119 != ( unsigned long ) - 1 ) {
V_115 = F_89 ( V_119 , V_97 ) / V_97 ;
} else {
char * V_124 ;
V_115 = strtoul ( V_117 , & V_124 , 10 ) ;
if ( * V_124 != '\0' )
return - V_59 ;
}
if ( V_115 == 0 && F_73 == 0 ) {
} else if ( ! F_86 ( V_115 ) ) {
V_115 = F_90 ( V_115 ) ;
if ( ! V_115 )
return - V_59 ;
F_91 ( L_6 ,
V_115 * V_97 , V_115 ) ;
}
if ( V_115 > V_118 )
return - V_59 ;
return V_115 ;
}
int F_92 ( const struct V_125 * V_126 , const char * V_117 ,
int T_4 V_127 )
{
unsigned int * V_128 = V_126 -> V_129 ;
unsigned long V_118 = V_116 ;
long V_115 ;
if ( V_118 > V_130 / V_97 )
V_118 = V_130 / V_97 ;
V_115 = F_87 ( V_117 , 1 , V_118 ) ;
if ( V_115 < 0 ) {
F_93 ( L_7 ) ;
return - 1 ;
}
* V_128 = V_115 ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 , unsigned int V_115 ,
bool V_98 )
{
struct V_13 * V_17 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
int V_109 = V_131 | ( V_98 ? 0 : V_132 ) , V_100 ;
if ( V_2 -> V_22 == NULL && F_78 ( V_2 ) < 0 )
return - V_41 ;
if ( V_2 -> V_23 == NULL && F_54 ( V_2 ) < 0 )
return - V_41 ;
V_2 -> V_98 = V_98 ;
V_2 -> V_107 = F_85 ( V_115 ) ;
F_95 ( L_8 , V_2 -> V_107 ) ;
V_100 = V_2 -> V_107 - V_97 - 1 ;
F_13 (evlist, evsel) {
if ( ( V_17 -> V_35 . V_79 & V_80 ) &&
V_17 -> V_133 == NULL &&
F_96 ( V_17 , F_46 ( V_4 ) , V_6 -> V_58 ) < 0 )
return - V_41 ;
}
if ( F_79 ( V_4 ) )
return F_84 ( V_2 , V_109 , V_100 ) ;
return F_83 ( V_2 , V_109 , V_100 ) ;
}
int F_97 ( struct V_1 * V_2 , struct V_134 * V_134 )
{
V_2 -> V_6 = F_98 ( V_134 -> V_12 , V_134 -> V_135 ,
V_134 -> V_136 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( F_99 ( V_134 ) )
V_2 -> V_4 = F_100 () ;
else
V_2 -> V_4 = F_101 ( V_134 -> V_137 ) ;
if ( V_2 -> V_4 == NULL )
goto V_138;
return 0 ;
V_138:
F_24 ( V_2 -> V_6 ) ;
return - 1 ;
}
int F_102 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
int V_57 = 0 ;
const int V_139 = F_46 ( V_2 -> V_4 ) ,
V_140 = F_47 ( V_2 -> V_6 ) ;
F_13 (evlist, evsel) {
if ( V_17 -> V_141 == NULL )
continue;
V_57 = F_103 ( V_17 , V_139 , V_140 , V_17 -> V_141 ) ;
if ( V_57 )
break;
}
return V_57 ;
}
int F_104 ( struct V_1 * V_2 , const char * V_141 )
{
struct V_13 * V_17 ;
int V_57 = 0 ;
const int V_139 = F_46 ( V_2 -> V_4 ) ,
V_140 = F_47 ( V_2 -> V_6 ) ;
F_13 (evlist, evsel) {
V_57 = F_103 ( V_17 , V_139 , V_140 , V_141 ) ;
if ( V_57 )
break;
}
return V_57 ;
}
bool F_105 ( struct V_1 * V_2 )
{
struct V_13 * V_18 ;
if ( V_2 -> V_21 == 1 )
return true ;
if ( V_2 -> V_15 < 0 || V_2 -> V_16 < 0 )
return false ;
F_13 (evlist, pos) {
if ( V_18 -> V_15 != V_2 -> V_15 ||
V_18 -> V_16 != V_2 -> V_16 )
return false ;
}
return true ;
}
T_2 F_106 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
if ( V_2 -> V_142 )
return V_2 -> V_142 ;
F_13 (evlist, evsel)
V_2 -> V_142 |= V_17 -> V_35 . V_143 ;
return V_2 -> V_142 ;
}
T_2 F_107 ( struct V_1 * V_2 )
{
V_2 -> V_142 = 0 ;
return F_106 ( V_2 ) ;
}
bool F_108 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_11 ( V_2 ) , * V_18 = V_14 ;
T_2 V_79 = V_14 -> V_35 . V_79 ;
T_2 V_143 = V_14 -> V_35 . V_143 ;
F_13 (evlist, pos) {
if ( V_79 != V_18 -> V_35 . V_79 )
return false ;
}
if ( ( V_143 & V_144 ) &&
! ( V_79 & V_80 ) ) {
return false ;
}
return true ;
}
T_2 F_63 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
return V_14 -> V_35 . V_79 ;
}
T_5 F_109 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
struct V_145 * V_95 ;
T_2 V_143 ;
T_5 V_89 = 0 ;
if ( ! V_14 -> V_35 . V_91 )
goto V_146;
V_143 = V_14 -> V_35 . V_143 ;
if ( V_143 & V_147 )
V_89 += sizeof( V_95 -> V_135 ) * 2 ;
if ( V_143 & V_148 )
V_89 += sizeof( V_95 -> time ) ;
if ( V_143 & V_149 )
V_89 += sizeof( V_95 -> V_46 ) ;
if ( V_143 & V_150 )
V_89 += sizeof( V_95 -> V_151 ) ;
if ( V_143 & V_152 )
V_89 += sizeof( V_95 -> V_50 ) * 2 ;
if ( V_143 & V_153 )
V_89 += sizeof( V_95 -> V_46 ) ;
V_146:
return V_89 ;
}
bool F_110 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_11 ( V_2 ) , * V_18 = V_14 ;
F_111 (evlist, pos) {
if ( V_14 -> V_35 . V_91 != V_18 -> V_35 . V_91 )
return false ;
}
return true ;
}
bool F_68 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
return V_14 -> V_35 . V_91 ;
}
void F_112 ( struct V_1 * V_2 ,
struct V_13 * V_17 )
{
V_2 -> V_154 = V_17 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
int V_139 = F_46 ( V_2 -> V_4 ) ;
int V_140 = F_47 ( V_2 -> V_6 ) ;
int V_19 ;
F_113 (evlist, evsel) {
V_19 = V_17 -> V_4 ? V_17 -> V_4 -> V_58 : V_139 ;
F_114 ( V_17 , V_19 , V_140 ) ;
}
}
int F_115 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
int V_57 ;
F_12 ( V_2 ) ;
F_13 (evlist, evsel) {
V_57 = F_116 ( V_17 , V_2 -> V_4 , V_2 -> V_6 ) ;
if ( V_57 < 0 )
goto V_155;
}
return 0 ;
V_155:
F_22 ( V_2 ) ;
V_76 = - V_57 ;
return V_57 ;
}
int F_117 ( struct V_1 * V_2 , struct V_134 * V_134 ,
const char * V_156 [] , bool V_157 ,
void (* F_118)( int V_158 , T_6 * V_159 , void * V_160 ) )
{
int V_161 [ 2 ] , V_162 [ 2 ] ;
char V_163 ;
if ( F_119 ( V_161 ) < 0 ) {
perror ( L_9 ) ;
return - 1 ;
}
if ( F_119 ( V_162 ) < 0 ) {
perror ( L_10 ) ;
goto V_164;
}
V_2 -> V_11 . V_12 = F_120 () ;
if ( V_2 -> V_11 . V_12 < 0 ) {
perror ( L_11 ) ;
goto V_165;
}
if ( ! V_2 -> V_11 . V_12 ) {
if ( V_157 )
F_121 ( 2 , 1 ) ;
signal ( V_166 , V_167 ) ;
F_122 ( V_161 [ 0 ] ) ;
F_122 ( V_162 [ 1 ] ) ;
F_56 ( V_162 [ 0 ] , V_168 , V_169 ) ;
F_122 ( V_161 [ 1 ] ) ;
if ( F_64 ( V_162 [ 0 ] , & V_163 , 1 ) == - 1 )
perror ( L_12 ) ;
F_123 ( V_156 [ 0 ] , ( char * * ) V_156 ) ;
if ( F_118 ) {
union V_170 V_119 ;
V_119 . V_171 = V_76 ;
if ( F_124 ( F_125 () , V_172 , V_119 ) )
perror ( V_156 [ 0 ] ) ;
} else
perror ( V_156 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_118 ) {
struct V_173 V_174 = {
. V_175 = V_176 ,
. V_177 = F_118 ,
} ;
V_173 ( V_172 , & V_174 , NULL ) ;
}
if ( F_126 ( V_134 ) )
V_2 -> V_6 -> V_178 [ 0 ] = V_2 -> V_11 . V_12 ;
F_122 ( V_161 [ 1 ] ) ;
F_122 ( V_162 [ 0 ] ) ;
if ( F_64 ( V_161 [ 0 ] , & V_163 , 1 ) == - 1 ) {
perror ( L_12 ) ;
goto V_165;
}
F_56 ( V_162 [ 1 ] , V_168 , V_169 ) ;
V_2 -> V_11 . V_179 = V_162 [ 1 ] ;
F_122 ( V_161 [ 0 ] ) ;
return 0 ;
V_165:
F_122 ( V_162 [ 0 ] ) ;
F_122 ( V_162 [ 1 ] ) ;
V_164:
F_122 ( V_161 [ 0 ] ) ;
F_122 ( V_161 [ 1 ] ) ;
return - 1 ;
}
int F_127 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_179 > 0 ) {
char V_163 = 0 ;
int V_73 ;
V_73 = F_128 ( V_2 -> V_11 . V_179 , & V_163 , 1 ) ;
if ( V_73 < 0 )
perror ( L_13 ) ;
F_122 ( V_2 -> V_11 . V_179 ) ;
return V_73 ;
}
return 0 ;
}
int F_129 ( struct V_1 * V_2 , union V_84 * V_85 ,
struct V_145 * V_87 )
{
struct V_13 * V_17 = F_70 ( V_2 , V_85 ) ;
if ( ! V_17 )
return - V_180 ;
return F_130 ( V_17 , V_85 , V_87 ) ;
}
T_1 F_131 ( struct V_1 * V_2 , T_7 * V_181 )
{
struct V_13 * V_17 ;
T_1 V_182 = 0 ;
F_13 (evlist, evsel) {
V_182 += fprintf ( V_181 , L_14 , V_17 -> V_25 ? L_15 : L_16 ,
F_132 ( V_17 ) ) ;
}
return V_182 + fprintf ( V_181 , L_17 ) ;
}
int F_133 ( struct V_1 * V_2 V_127 ,
int V_57 , char * V_183 , T_1 V_89 )
{
char V_184 [ 128 ] ;
switch ( V_57 ) {
case V_185 :
F_134 ( V_183 , V_89 , L_18 ,
L_19
L_20
L_21
L_22 ) ;
break;
case V_186 :
F_134 ( V_183 , V_89 ,
L_23
L_24 ,
V_187 , V_187 ) ;
break;
default:
F_134 ( V_183 , V_89 , L_18 , F_135 ( V_57 , V_184 , sizeof( V_184 ) ) ) ;
break;
}
return 0 ;
}
int F_136 ( struct V_1 * V_2 V_127 ,
int V_57 , char * V_183 , T_1 V_89 )
{
int V_182 , V_129 ;
char V_184 [ 128 ] , * V_188 = F_135 ( V_57 , V_184 , sizeof( V_184 ) ) ;
switch ( V_57 ) {
case V_186 :
case V_189 :
V_182 = F_134 ( V_183 , V_89 ,
L_25
L_26 , V_188 ) ;
V_129 = F_137 () ;
V_182 += F_134 ( V_183 + V_182 , V_89 - V_182 , L_27 ) ;
if ( V_129 >= 2 ) {
V_182 += F_134 ( V_183 + V_182 , V_89 - V_182 ,
L_28 ) ;
}
V_182 += F_134 ( V_183 + V_182 , V_89 - V_182 ,
L_29 ) ;
V_182 += F_134 ( V_183 + V_182 , V_89 - V_182 ,
L_30 , V_129 ) ;
break;
default:
F_134 ( V_183 , V_89 , L_18 , V_188 ) ;
break;
}
return 0 ;
}
void F_138 ( struct V_1 * V_2 ,
struct V_13 * V_190 )
{
struct V_13 * V_17 , * V_19 ;
F_37 ( V_191 ) ;
if ( V_190 == F_11 ( V_2 ) )
return;
F_16 (evlist, n, evsel) {
if ( V_17 -> V_29 == V_190 -> V_29 )
F_139 ( & V_17 -> V_20 , & V_191 ) ;
}
F_140 ( & V_191 , & V_2 -> V_10 ) ;
}
