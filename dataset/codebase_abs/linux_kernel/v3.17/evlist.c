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
static int F_80 ( struct V_1 * V_2 , int V_25 ,
struct V_109 * V_110 , int V_54 )
{
V_2 -> V_22 [ V_25 ] . V_31 = 0 ;
V_2 -> V_22 [ V_25 ] . V_100 = V_110 -> V_100 ;
V_2 -> V_22 [ V_25 ] . V_96 = V_22 ( NULL , V_2 -> V_107 , V_110 -> V_111 ,
V_112 , V_54 , 0 ) ;
if ( V_2 -> V_22 [ V_25 ] . V_96 == V_113 ) {
F_81 ( L_3 ,
V_76 ) ;
V_2 -> V_22 [ V_25 ] . V_96 = NULL ;
return - 1 ;
}
F_55 ( V_2 , V_54 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , int V_25 ,
struct V_109 * V_110 , int V_50 ,
int V_51 , int * V_114 )
{
struct V_13 * V_17 ;
F_13 (evlist, evsel) {
int V_54 = F_50 ( V_17 , V_50 , V_51 ) ;
if ( * V_114 == - 1 ) {
* V_114 = V_54 ;
if ( F_80 ( V_2 , V_25 , V_110 , * V_114 ) < 0 )
return - 1 ;
} else {
if ( F_49 ( V_54 , V_115 , * V_114 ) != 0 )
return - 1 ;
}
if ( ( V_17 -> V_35 . V_79 & V_80 ) &&
F_62 ( V_2 , V_17 , V_50 , V_51 , V_54 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_109 * V_110 )
{
int V_50 , V_51 ;
int V_52 = F_46 ( V_2 -> V_4 ) ;
int V_53 = F_47 ( V_2 -> V_6 ) ;
F_81 ( L_4 ) ;
for ( V_50 = 0 ; V_50 < V_52 ; V_50 ++ ) {
int V_114 = - 1 ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
if ( F_82 ( V_2 , V_50 , V_110 , V_50 ,
V_51 , & V_114 ) )
goto V_116;
}
}
return 0 ;
V_116:
for ( V_50 = 0 ; V_50 < V_52 ; V_50 ++ )
F_76 ( V_2 , V_50 ) ;
return - 1 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_109 * V_110 )
{
int V_51 ;
int V_53 = F_47 ( V_2 -> V_6 ) ;
F_81 ( L_5 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
int V_114 = - 1 ;
if ( F_82 ( V_2 , V_51 , V_110 , 0 , V_51 ,
& V_114 ) )
goto V_116;
}
return 0 ;
V_116:
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ )
F_76 ( V_2 , V_51 ) ;
return - 1 ;
}
static T_1 F_85 ( unsigned long V_117 )
{
if ( V_117 == V_118 )
V_117 = ( 512 * 1024 ) / V_97 ;
else if ( ! F_86 ( V_117 ) )
return 0 ;
return ( V_117 + 1 ) * V_97 ;
}
static long F_87 ( const char * V_119 , unsigned long F_73 ,
unsigned long V_120 )
{
unsigned long V_117 , V_121 ;
static struct V_122 V_123 [] = {
{ . V_124 = 'B' , . V_125 = 1 } ,
{ . V_124 = 'K' , . V_125 = 1 << 10 } ,
{ . V_124 = 'M' , . V_125 = 1 << 20 } ,
{ . V_124 = 'G' , . V_125 = 1 << 30 } ,
{ . V_124 = 0 } ,
} ;
if ( V_119 == NULL )
return - V_59 ;
V_121 = F_88 ( V_119 , V_123 ) ;
if ( V_121 != ( unsigned long ) - 1 ) {
V_117 = F_89 ( V_121 , V_97 ) / V_97 ;
} else {
char * V_126 ;
V_117 = strtoul ( V_119 , & V_126 , 10 ) ;
if ( * V_126 != '\0' )
return - V_59 ;
}
if ( V_117 == 0 && F_73 == 0 ) {
} else if ( ! F_86 ( V_117 ) ) {
V_117 = F_90 ( V_117 ) ;
if ( ! V_117 )
return - V_59 ;
F_91 ( L_6 ,
V_117 * V_97 , V_117 ) ;
}
if ( V_117 > V_120 )
return - V_59 ;
return V_117 ;
}
int F_92 ( const struct V_127 * V_128 , const char * V_119 ,
int T_4 V_129 )
{
unsigned int * V_130 = V_128 -> V_131 ;
unsigned long V_120 = V_118 ;
long V_117 ;
if ( V_120 > V_132 / V_97 )
V_120 = V_132 / V_97 ;
V_117 = F_87 ( V_119 , 1 , V_120 ) ;
if ( V_117 < 0 ) {
F_93 ( L_7 ) ;
return - 1 ;
}
* V_130 = V_117 ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 , unsigned int V_117 ,
bool V_98 )
{
struct V_13 * V_17 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
struct V_109 V_110 = {
. V_111 = V_133 | ( V_98 ? 0 : V_134 ) ,
} ;
if ( V_2 -> V_22 == NULL && F_78 ( V_2 ) < 0 )
return - V_41 ;
if ( V_2 -> V_23 == NULL && F_54 ( V_2 ) < 0 )
return - V_41 ;
V_2 -> V_98 = V_98 ;
V_2 -> V_107 = F_85 ( V_117 ) ;
F_95 ( L_8 , V_2 -> V_107 ) ;
V_110 . V_100 = V_2 -> V_107 - V_97 - 1 ;
F_13 (evlist, evsel) {
if ( ( V_17 -> V_35 . V_79 & V_80 ) &&
V_17 -> V_135 == NULL &&
F_96 ( V_17 , F_46 ( V_4 ) , V_6 -> V_58 ) < 0 )
return - V_41 ;
}
if ( F_79 ( V_4 ) )
return F_84 ( V_2 , & V_110 ) ;
return F_83 ( V_2 , & V_110 ) ;
}
int F_97 ( struct V_1 * V_2 , struct V_136 * V_136 )
{
V_2 -> V_6 = F_98 ( V_136 -> V_12 , V_136 -> V_137 ,
V_136 -> V_138 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( F_99 ( V_136 ) )
V_2 -> V_4 = F_100 () ;
else
V_2 -> V_4 = F_101 ( V_136 -> V_139 ) ;
if ( V_2 -> V_4 == NULL )
goto V_140;
return 0 ;
V_140:
F_24 ( V_2 -> V_6 ) ;
return - 1 ;
}
int F_102 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
int V_57 = 0 ;
const int V_141 = F_46 ( V_2 -> V_4 ) ,
V_142 = F_47 ( V_2 -> V_6 ) ;
F_13 (evlist, evsel) {
if ( V_17 -> V_143 == NULL )
continue;
V_57 = F_103 ( V_17 , V_141 , V_142 , V_17 -> V_143 ) ;
if ( V_57 )
break;
}
return V_57 ;
}
int F_104 ( struct V_1 * V_2 , const char * V_143 )
{
struct V_13 * V_17 ;
int V_57 = 0 ;
const int V_141 = F_46 ( V_2 -> V_4 ) ,
V_142 = F_47 ( V_2 -> V_6 ) ;
F_13 (evlist, evsel) {
V_57 = F_103 ( V_17 , V_141 , V_142 , V_143 ) ;
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
if ( V_2 -> V_144 )
return V_2 -> V_144 ;
F_13 (evlist, evsel)
V_2 -> V_144 |= V_17 -> V_35 . V_145 ;
return V_2 -> V_144 ;
}
T_2 F_107 ( struct V_1 * V_2 )
{
V_2 -> V_144 = 0 ;
return F_106 ( V_2 ) ;
}
bool F_108 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_11 ( V_2 ) , * V_18 = V_14 ;
T_2 V_79 = V_14 -> V_35 . V_79 ;
T_2 V_145 = V_14 -> V_35 . V_145 ;
F_13 (evlist, pos) {
if ( V_79 != V_18 -> V_35 . V_79 )
return false ;
}
if ( ( V_145 & V_146 ) &&
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
struct V_147 * V_95 ;
T_2 V_145 ;
T_5 V_89 = 0 ;
if ( ! V_14 -> V_35 . V_91 )
goto V_148;
V_145 = V_14 -> V_35 . V_145 ;
if ( V_145 & V_149 )
V_89 += sizeof( V_95 -> V_137 ) * 2 ;
if ( V_145 & V_150 )
V_89 += sizeof( V_95 -> time ) ;
if ( V_145 & V_151 )
V_89 += sizeof( V_95 -> V_46 ) ;
if ( V_145 & V_152 )
V_89 += sizeof( V_95 -> V_153 ) ;
if ( V_145 & V_154 )
V_89 += sizeof( V_95 -> V_50 ) * 2 ;
if ( V_145 & V_155 )
V_89 += sizeof( V_95 -> V_46 ) ;
V_148:
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
V_2 -> V_156 = V_17 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
int V_141 = F_46 ( V_2 -> V_4 ) ;
int V_142 = F_47 ( V_2 -> V_6 ) ;
int V_19 ;
F_113 (evlist, evsel) {
V_19 = V_17 -> V_4 ? V_17 -> V_4 -> V_58 : V_141 ;
F_114 ( V_17 , V_19 , V_142 ) ;
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
goto V_157;
}
return 0 ;
V_157:
F_22 ( V_2 ) ;
V_76 = - V_57 ;
return V_57 ;
}
int F_117 ( struct V_1 * V_2 , struct V_136 * V_136 ,
const char * V_158 [] , bool V_159 ,
void (* F_118)( int V_160 , T_6 * V_161 , void * V_162 ) )
{
int V_163 [ 2 ] , V_164 [ 2 ] ;
char V_165 ;
if ( F_119 ( V_163 ) < 0 ) {
perror ( L_9 ) ;
return - 1 ;
}
if ( F_119 ( V_164 ) < 0 ) {
perror ( L_10 ) ;
goto V_166;
}
V_2 -> V_11 . V_12 = F_120 () ;
if ( V_2 -> V_11 . V_12 < 0 ) {
perror ( L_11 ) ;
goto V_167;
}
if ( ! V_2 -> V_11 . V_12 ) {
if ( V_159 )
F_121 ( 2 , 1 ) ;
signal ( V_168 , V_169 ) ;
F_122 ( V_163 [ 0 ] ) ;
F_122 ( V_164 [ 1 ] ) ;
F_56 ( V_164 [ 0 ] , V_170 , V_171 ) ;
F_122 ( V_163 [ 1 ] ) ;
if ( F_64 ( V_164 [ 0 ] , & V_165 , 1 ) == - 1 )
perror ( L_12 ) ;
F_123 ( V_158 [ 0 ] , ( char * * ) V_158 ) ;
if ( F_118 ) {
union V_172 V_121 ;
V_121 . V_173 = V_76 ;
if ( F_124 ( F_125 () , V_174 , V_121 ) )
perror ( V_158 [ 0 ] ) ;
} else
perror ( V_158 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_118 ) {
struct V_175 V_176 = {
. V_177 = V_178 ,
. V_179 = F_118 ,
} ;
V_175 ( V_174 , & V_176 , NULL ) ;
}
if ( F_126 ( V_136 ) )
V_2 -> V_6 -> V_180 [ 0 ] = V_2 -> V_11 . V_12 ;
F_122 ( V_163 [ 1 ] ) ;
F_122 ( V_164 [ 0 ] ) ;
if ( F_64 ( V_163 [ 0 ] , & V_165 , 1 ) == - 1 ) {
perror ( L_12 ) ;
goto V_167;
}
F_56 ( V_164 [ 1 ] , V_170 , V_171 ) ;
V_2 -> V_11 . V_181 = V_164 [ 1 ] ;
F_122 ( V_163 [ 0 ] ) ;
return 0 ;
V_167:
F_122 ( V_164 [ 0 ] ) ;
F_122 ( V_164 [ 1 ] ) ;
V_166:
F_122 ( V_163 [ 0 ] ) ;
F_122 ( V_163 [ 1 ] ) ;
return - 1 ;
}
int F_127 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_181 > 0 ) {
char V_165 = 0 ;
int V_73 ;
V_73 = F_128 ( V_2 -> V_11 . V_181 , & V_165 , 1 ) ;
if ( V_73 < 0 )
perror ( L_13 ) ;
F_122 ( V_2 -> V_11 . V_181 ) ;
return V_73 ;
}
return 0 ;
}
int F_129 ( struct V_1 * V_2 , union V_84 * V_85 ,
struct V_147 * V_87 )
{
struct V_13 * V_17 = F_70 ( V_2 , V_85 ) ;
if ( ! V_17 )
return - V_182 ;
return F_130 ( V_17 , V_85 , V_87 ) ;
}
T_1 F_131 ( struct V_1 * V_2 , T_7 * V_183 )
{
struct V_13 * V_17 ;
T_1 V_184 = 0 ;
F_13 (evlist, evsel) {
V_184 += fprintf ( V_183 , L_14 , V_17 -> V_25 ? L_15 : L_16 ,
F_132 ( V_17 ) ) ;
}
return V_184 + fprintf ( V_183 , L_17 ) ;
}
int F_133 ( struct V_1 * V_2 V_129 ,
int V_57 , char * V_185 , T_1 V_89 )
{
char V_186 [ 128 ] ;
switch ( V_57 ) {
case V_187 :
F_134 ( V_185 , V_89 , L_18 ,
L_19
L_20
L_21
L_22 ) ;
break;
case V_188 :
F_134 ( V_185 , V_89 ,
L_23
L_24 ,
V_189 , V_189 ) ;
break;
default:
F_134 ( V_185 , V_89 , L_18 , F_135 ( V_57 , V_186 , sizeof( V_186 ) ) ) ;
break;
}
return 0 ;
}
int F_136 ( struct V_1 * V_2 V_129 ,
int V_57 , char * V_185 , T_1 V_89 )
{
int V_184 , V_131 ;
char V_186 [ 128 ] , * V_190 = F_135 ( V_57 , V_186 , sizeof( V_186 ) ) ;
switch ( V_57 ) {
case V_188 :
case V_191 :
V_184 = F_134 ( V_185 , V_89 ,
L_25
L_26 , V_190 ) ;
V_131 = F_137 () ;
V_184 += F_134 ( V_185 + V_184 , V_89 - V_184 , L_27 ) ;
if ( V_131 >= 2 ) {
V_184 += F_134 ( V_185 + V_184 , V_89 - V_184 ,
L_28 ) ;
}
V_184 += F_134 ( V_185 + V_184 , V_89 - V_184 ,
L_29 ) ;
V_184 += F_134 ( V_185 + V_184 , V_89 - V_184 ,
L_30
L_31 , V_131 ) ;
break;
default:
F_134 ( V_185 , V_89 , L_18 , V_190 ) ;
break;
}
return 0 ;
}
void F_138 ( struct V_1 * V_2 ,
struct V_13 * V_192 )
{
struct V_13 * V_17 , * V_19 ;
F_37 ( V_193 ) ;
if ( V_192 == F_11 ( V_2 ) )
return;
F_16 (evlist, n, evsel) {
if ( V_17 -> V_29 == V_192 -> V_29 )
F_139 ( & V_17 -> V_20 , & V_193 ) ;
}
F_140 ( & V_193 , & V_2 -> V_10 ) ;
}
