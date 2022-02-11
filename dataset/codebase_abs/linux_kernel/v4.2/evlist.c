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
V_2 -> V_58 = false ;
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
V_59 , 0 ) ;
}
}
V_2 -> V_58 = true ;
}
void F_55 ( struct V_1 * V_2 )
{
( V_2 -> V_58 ? F_49 : F_54 ) ( V_2 ) ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
int V_52 , V_53 , V_60 ;
int V_54 = F_50 ( V_2 -> V_4 ) ;
int V_55 = F_47 ( V_2 , V_18 ) ;
if ( ! V_18 -> V_56 )
return 0 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
V_60 = F_52 ( F_53 ( V_18 , V_52 , V_53 ) ,
V_57 , 0 ) ;
if ( V_60 )
return V_60 ;
}
}
return 0 ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
int V_52 , V_53 , V_60 ;
int V_54 = F_50 ( V_2 -> V_4 ) ;
int V_55 = F_47 ( V_2 , V_18 ) ;
if ( ! V_18 -> V_56 )
return - V_61 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
V_60 = F_52 ( F_53 ( V_18 , V_52 , V_53 ) ,
V_59 , 0 ) ;
if ( V_60 )
return V_60 ;
}
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_52 )
{
int V_53 , V_60 ;
int V_55 = F_47 ( V_2 , V_18 ) ;
if ( ! V_18 -> V_56 )
return - V_61 ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
V_60 = F_52 ( F_53 ( V_18 , V_52 , V_53 ) ,
V_59 , 0 ) ;
if ( V_60 )
return V_60 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_53 )
{
int V_52 , V_60 ;
int V_54 = F_50 ( V_2 -> V_4 ) ;
if ( ! V_18 -> V_56 )
return - V_61 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
V_60 = F_52 ( F_53 ( V_18 , V_52 , V_53 ) , V_59 , 0 ) ;
if ( V_60 )
return V_60 ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_25 )
{
bool V_62 = ! F_61 ( V_2 -> V_4 ) ;
if ( V_62 )
return F_58 ( V_2 , V_18 , V_25 ) ;
else
return F_59 ( V_2 , V_18 , V_25 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
int V_54 = F_50 ( V_2 -> V_4 ) ;
int V_55 = F_48 ( V_2 -> V_6 ) ;
int V_63 = 0 ;
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
if ( V_18 -> V_51 )
V_63 += V_54 ;
else
V_63 += V_54 * V_55 ;
}
if ( F_63 ( & V_2 -> V_11 ) < V_63 &&
F_64 ( & V_2 -> V_11 , V_63 ) < 0 )
return - V_42 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , int V_56 , int V_25 )
{
int V_19 = F_66 ( & V_2 -> V_11 , V_56 , V_64 | V_65 | V_66 ) ;
if ( V_19 >= 0 ) {
V_2 -> V_11 . V_67 [ V_19 ] . V_25 = V_25 ;
F_67 ( V_56 , V_68 , V_69 ) ;
}
return V_19 ;
}
int F_68 ( struct V_1 * V_2 , int V_56 )
{
return F_65 ( V_2 , V_56 , - 1 ) ;
}
static void F_69 ( struct V_70 * V_71 , int V_56 )
{
struct V_1 * V_2 = F_70 ( V_71 , struct V_1 , V_11 ) ;
F_71 ( V_2 , V_71 -> V_67 [ V_56 ] . V_25 ) ;
}
int F_72 ( struct V_1 * V_2 , short V_72 )
{
return F_73 ( & V_2 -> V_11 , V_72 ,
F_69 ) ;
}
int F_74 ( struct V_1 * V_2 , int V_73 )
{
return F_75 ( & V_2 -> V_11 , V_73 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_52 , int V_53 , T_2 V_47 )
{
int V_74 ;
struct V_75 * V_76 = F_77 ( V_18 , V_52 , V_53 ) ;
V_76 -> V_47 = V_47 ;
V_76 -> V_18 = V_18 ;
V_74 = F_78 ( V_76 -> V_47 , V_77 ) ;
F_79 ( & V_76 -> V_21 , & V_2 -> V_9 [ V_74 ] ) ;
}
void F_80 ( struct V_1 * V_2 , struct V_14 * V_18 ,
int V_52 , int V_53 , T_2 V_47 )
{
F_76 ( V_2 , V_18 , V_52 , V_53 , V_47 ) ;
V_18 -> V_47 [ V_18 -> V_78 ++ ] = V_47 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_52 , int V_53 , int V_56 )
{
T_2 V_79 [ 4 ] = { 0 , } ;
int V_80 = 1 ;
T_2 V_47 ;
int V_81 ;
V_81 = F_52 ( V_56 , V_82 , & V_47 ) ;
if ( ! V_81 )
goto V_83;
if ( V_84 != V_85 )
return - 1 ;
if ( F_82 ( V_2 ) & V_86 )
return - 1 ;
if ( ! ( V_18 -> V_36 . V_87 & V_88 ) ||
F_83 ( V_56 , & V_79 , sizeof( V_79 ) ) == - 1 )
return - 1 ;
if ( V_18 -> V_36 . V_87 & V_89 )
++ V_80 ;
if ( V_18 -> V_36 . V_87 & V_90 )
++ V_80 ;
V_47 = V_79 [ V_80 ] ;
V_83:
F_80 ( V_2 , V_18 , V_52 , V_53 , V_47 ) ;
return 0 ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_25 , int V_52 ,
int V_53 )
{
struct V_75 * V_76 = F_77 ( V_18 , V_52 , V_53 ) ;
V_76 -> V_25 = V_25 ;
if ( V_2 -> V_4 && V_52 >= 0 )
V_76 -> V_52 = V_2 -> V_4 -> V_91 [ V_52 ] ;
else
V_76 -> V_52 = - 1 ;
if ( ! V_18 -> V_51 && V_2 -> V_6 && V_53 >= 0 )
V_76 -> V_92 = F_85 ( V_2 -> V_6 , V_53 ) ;
else
V_76 -> V_92 = - 1 ;
}
struct V_75 * F_86 ( struct V_1 * V_2 , T_2 V_47 )
{
struct V_93 * V_45 ;
struct V_75 * V_76 ;
int V_74 ;
V_74 = F_78 ( V_47 , V_77 ) ;
V_45 = & V_2 -> V_9 [ V_74 ] ;
F_87 (sid, head, node)
if ( V_76 -> V_47 == V_47 )
return V_76 ;
return NULL ;
}
struct V_14 * F_88 ( struct V_1 * V_2 , T_2 V_47 )
{
struct V_75 * V_76 ;
if ( V_2 -> V_22 == 1 )
return F_12 ( V_2 ) ;
V_76 = F_86 ( V_2 , V_47 ) ;
if ( V_76 )
return V_76 -> V_18 ;
if ( ! F_89 ( V_2 ) )
return F_12 ( V_2 ) ;
return NULL ;
}
static int F_90 ( struct V_1 * V_2 ,
union V_94 * V_95 , T_2 * V_47 )
{
const T_2 * V_96 = V_95 -> V_97 . V_96 ;
T_3 V_20 ;
V_20 = ( V_95 -> V_98 . V_99 - sizeof( V_95 -> V_98 ) ) >> 3 ;
if ( V_95 -> V_98 . type == V_100 ) {
if ( V_2 -> V_16 >= V_20 )
return - 1 ;
* V_47 = V_96 [ V_2 -> V_16 ] ;
} else {
if ( V_2 -> V_17 > V_20 )
return - 1 ;
V_20 -= V_2 -> V_17 ;
* V_47 = V_96 [ V_20 ] ;
}
return 0 ;
}
static struct V_14 * F_91 ( struct V_1 * V_2 ,
union V_94 * V_95 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
struct V_93 * V_45 ;
struct V_75 * V_76 ;
int V_74 ;
T_2 V_47 ;
if ( V_2 -> V_22 == 1 )
return V_15 ;
if ( ! V_15 -> V_36 . V_101 &&
V_95 -> V_98 . type != V_100 )
return V_15 ;
if ( F_90 ( V_2 , V_95 , & V_47 ) )
return NULL ;
if ( ! V_47 )
return V_15 ;
V_74 = F_78 ( V_47 , V_77 ) ;
V_45 = & V_2 -> V_9 [ V_74 ] ;
F_87 (sid, head, node) {
if ( V_76 -> V_47 == V_47 )
return V_76 -> V_18 ;
}
return NULL ;
}
union V_94 * F_92 ( struct V_1 * V_2 , int V_25 )
{
struct V_102 * V_103 = & V_2 -> V_23 [ V_25 ] ;
T_2 V_45 ;
T_2 V_104 = V_103 -> V_32 ;
unsigned char * V_105 = V_103 -> V_106 + V_107 ;
union V_94 * V_95 = NULL ;
if ( ! F_93 ( & V_103 -> V_108 ) )
return NULL ;
V_45 = F_94 ( V_103 ) ;
if ( V_2 -> V_109 ) {
int V_110 = V_45 - V_104 ;
if ( V_110 > V_103 -> V_111 / 2 || V_110 < 0 ) {
fprintf ( V_112 , L_2 ) ;
V_104 = V_45 ;
}
}
if ( V_104 != V_45 ) {
T_1 V_99 ;
V_95 = (union V_94 * ) & V_105 [ V_104 & V_103 -> V_111 ] ;
V_99 = V_95 -> V_98 . V_99 ;
if ( ( V_104 & V_103 -> V_111 ) + V_99 != ( ( V_104 + V_99 ) & V_103 -> V_111 ) ) {
unsigned int V_113 = V_104 ;
unsigned int V_114 = F_95 ( sizeof( * V_95 ) , V_99 ) , V_115 ;
void * V_116 = V_103 -> V_117 ;
do {
V_115 = F_95 ( V_103 -> V_111 + 1 - ( V_113 & V_103 -> V_111 ) , V_114 ) ;
memcpy ( V_116 , & V_105 [ V_113 & V_103 -> V_111 ] , V_115 ) ;
V_113 += V_115 ;
V_116 += V_115 ;
V_114 -= V_115 ;
} while ( V_114 );
V_95 = (union V_94 * ) V_103 -> V_117 ;
}
V_104 += V_99 ;
}
V_103 -> V_32 = V_104 ;
return V_95 ;
}
static bool F_96 ( struct V_102 * V_103 )
{
return F_94 ( V_103 ) == V_103 -> V_32 && ! V_103 -> V_118 . V_106 ;
}
static void F_97 ( struct V_1 * V_2 , int V_25 )
{
F_98 ( & V_2 -> V_23 [ V_25 ] . V_108 ) ;
}
static void F_71 ( struct V_1 * V_2 , int V_25 )
{
F_99 ( F_93 ( & V_2 -> V_23 [ V_25 ] . V_108 ) == 0 ) ;
if ( F_100 ( & V_2 -> V_23 [ V_25 ] . V_108 ) )
F_101 ( V_2 , V_25 ) ;
}
void F_102 ( struct V_1 * V_2 , int V_25 )
{
struct V_102 * V_103 = & V_2 -> V_23 [ V_25 ] ;
if ( ! V_2 -> V_109 ) {
T_2 V_104 = V_103 -> V_32 ;
F_103 ( V_103 , V_104 ) ;
}
if ( F_93 ( & V_103 -> V_108 ) == 1 && F_96 ( V_103 ) )
F_71 ( V_2 , V_25 ) ;
}
int __weak F_104 ( struct V_118 * T_4 V_119 ,
struct V_120 * T_5 V_119 ,
void * T_6 V_119 ,
int V_56 V_119 )
{
return 0 ;
}
void __weak F_105 ( struct V_118 * T_4 V_119 )
{
}
void __weak F_106 (
struct V_120 * T_5 V_119 ,
T_7 T_8 V_119 ,
unsigned int T_9 V_119 ,
bool T_10 V_119 )
{
}
void __weak F_107 (
struct V_120 * T_5 V_119 ,
struct V_1 * V_2 V_119 ,
int V_25 V_119 ,
bool T_11 V_119 )
{
}
static void F_101 ( struct V_1 * V_2 , int V_25 )
{
if ( V_2 -> V_23 [ V_25 ] . V_106 != NULL ) {
F_108 ( V_2 -> V_23 [ V_25 ] . V_106 , V_2 -> V_121 ) ;
V_2 -> V_23 [ V_25 ] . V_106 = NULL ;
F_109 ( & V_2 -> V_23 [ V_25 ] . V_108 , 0 ) ;
}
F_105 ( & V_2 -> V_23 [ V_25 ] . V_118 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_23 == NULL )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_122 ; V_7 ++ )
F_101 ( V_2 , V_7 ) ;
F_21 ( & V_2 -> V_23 ) ;
}
static int F_110 ( struct V_1 * V_2 )
{
V_2 -> V_122 = F_50 ( V_2 -> V_4 ) ;
if ( F_61 ( V_2 -> V_4 ) )
V_2 -> V_122 = F_48 ( V_2 -> V_6 ) ;
V_2 -> V_23 = F_7 ( V_2 -> V_122 * sizeof( struct V_102 ) ) ;
return V_2 -> V_23 != NULL ? 0 : - V_42 ;
}
static int F_111 ( struct V_1 * V_2 , int V_25 ,
struct V_123 * T_5 , int V_56 )
{
F_109 ( & V_2 -> V_23 [ V_25 ] . V_108 , 2 ) ;
V_2 -> V_23 [ V_25 ] . V_32 = 0 ;
V_2 -> V_23 [ V_25 ] . V_111 = T_5 -> V_111 ;
V_2 -> V_23 [ V_25 ] . V_106 = V_23 ( NULL , V_2 -> V_121 , T_5 -> V_124 ,
V_125 , V_56 , 0 ) ;
if ( V_2 -> V_23 [ V_25 ] . V_106 == V_126 ) {
F_112 ( L_3 ,
V_84 ) ;
V_2 -> V_23 [ V_25 ] . V_106 = NULL ;
return - 1 ;
}
if ( F_104 ( & V_2 -> V_23 [ V_25 ] . V_118 ,
& T_5 -> V_127 , V_2 -> V_23 [ V_25 ] . V_106 , V_56 ) )
return - 1 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 , int V_25 ,
struct V_123 * T_5 , int V_52 ,
int V_53 , int * V_128 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
int V_56 ;
if ( V_18 -> V_51 && V_53 )
continue;
V_56 = F_53 ( V_18 , V_52 , V_53 ) ;
if ( * V_128 == - 1 ) {
* V_128 = V_56 ;
if ( F_111 ( V_2 , V_25 , T_5 , * V_128 ) < 0 )
return - 1 ;
} else {
if ( F_52 ( V_56 , V_129 , * V_128 ) != 0 )
return - 1 ;
F_97 ( V_2 , V_25 ) ;
}
if ( ! V_18 -> V_51 &&
F_65 ( V_2 , V_56 , V_25 ) < 0 ) {
F_71 ( V_2 , V_25 ) ;
return - 1 ;
}
if ( V_18 -> V_36 . V_87 & V_88 ) {
if ( F_81 ( V_2 , V_18 , V_52 , V_53 ,
V_56 ) < 0 )
return - 1 ;
F_84 ( V_2 , V_18 , V_25 , V_52 ,
V_53 ) ;
}
}
return 0 ;
}
static int F_114 ( struct V_1 * V_2 ,
struct V_123 * T_5 )
{
int V_52 , V_53 ;
int V_54 = F_50 ( V_2 -> V_4 ) ;
int V_55 = F_48 ( V_2 -> V_6 ) ;
F_112 ( L_4 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
int V_128 = - 1 ;
F_107 ( & T_5 -> V_127 , V_2 , V_52 ,
true ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
if ( F_113 ( V_2 , V_52 , T_5 , V_52 ,
V_53 , & V_128 ) )
goto V_130;
}
}
return 0 ;
V_130:
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ )
F_101 ( V_2 , V_52 ) ;
return - 1 ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_123 * T_5 )
{
int V_53 ;
int V_55 = F_48 ( V_2 -> V_6 ) ;
F_112 ( L_5 ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
int V_128 = - 1 ;
F_107 ( & T_5 -> V_127 , V_2 , V_53 ,
false ) ;
if ( F_113 ( V_2 , V_53 , T_5 , 0 , V_53 ,
& V_128 ) )
goto V_130;
}
return 0 ;
V_130:
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ )
F_101 ( V_2 , V_53 ) ;
return - 1 ;
}
static T_1 F_116 ( unsigned long V_131 )
{
if ( V_131 == V_132 ) {
int V_133 ;
if ( F_117 ( L_6 , & V_133 ) < 0 ) {
V_133 = 512 ;
} else {
V_133 -= ( V_107 / 1024 ) ;
}
V_131 = ( V_133 * 1024 ) / V_107 ;
if ( ! F_118 ( V_131 ) )
V_131 = F_119 ( V_131 ) ;
} else if ( ! F_118 ( V_131 ) )
return 0 ;
return ( V_131 + 1 ) * V_107 ;
}
static long F_120 ( const char * V_134 , unsigned long F_95 ,
unsigned long V_133 )
{
unsigned long V_131 , V_135 ;
static struct V_136 V_137 [] = {
{ . V_138 = 'B' , . V_139 = 1 } ,
{ . V_138 = 'K' , . V_139 = 1 << 10 } ,
{ . V_138 = 'M' , . V_139 = 1 << 20 } ,
{ . V_138 = 'G' , . V_139 = 1 << 30 } ,
{ . V_138 = 0 } ,
} ;
if ( V_134 == NULL )
return - V_61 ;
V_135 = F_121 ( V_134 , V_137 ) ;
if ( V_135 != ( unsigned long ) - 1 ) {
V_131 = F_122 ( V_135 , V_107 ) / V_107 ;
} else {
char * V_140 ;
V_131 = strtoul ( V_134 , & V_140 , 10 ) ;
if ( * V_140 != '\0' )
return - V_61 ;
}
if ( V_131 == 0 && F_95 == 0 ) {
} else if ( ! F_118 ( V_131 ) ) {
V_131 = F_123 ( V_131 ) ;
if ( ! V_131 )
return - V_61 ;
F_124 ( L_7 ,
V_131 * V_107 , V_131 ) ;
}
if ( V_131 > V_133 )
return - V_61 ;
return V_131 ;
}
int F_125 ( unsigned int * V_141 , const char * V_134 )
{
unsigned long V_133 = V_132 ;
long V_131 ;
if ( V_133 > V_142 / V_107 )
V_133 = V_142 / V_107 ;
V_131 = F_120 ( V_134 , 1 , V_133 ) ;
if ( V_131 < 0 ) {
F_126 ( L_8 ) ;
return - 1 ;
}
* V_141 = V_131 ;
return 0 ;
}
int F_127 ( const struct V_143 * V_144 , const char * V_134 ,
int T_12 V_119 )
{
return F_125 ( V_144 -> V_145 , V_134 ) ;
}
int F_128 ( struct V_1 * V_2 , unsigned int V_131 ,
bool V_109 , unsigned int T_9 ,
bool T_10 )
{
struct V_14 * V_18 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
struct V_123 T_5 = {
. V_124 = V_146 | ( V_109 ? 0 : V_147 ) ,
} ;
if ( V_2 -> V_23 == NULL && F_110 ( V_2 ) < 0 )
return - V_42 ;
if ( V_2 -> V_11 . V_10 == NULL && F_62 ( V_2 ) < 0 )
return - V_42 ;
V_2 -> V_109 = V_109 ;
V_2 -> V_121 = F_116 ( V_131 ) ;
F_129 ( L_9 , V_2 -> V_121 ) ;
T_5 . V_111 = V_2 -> V_121 - V_107 - 1 ;
F_106 ( & T_5 . V_127 , V_2 -> V_121 ,
T_9 , T_10 ) ;
F_14 (evlist, evsel) {
if ( ( V_18 -> V_36 . V_87 & V_88 ) &&
V_18 -> V_148 == NULL &&
F_130 ( V_18 , F_50 ( V_4 ) , V_6 -> V_149 ) < 0 )
return - V_42 ;
}
if ( F_61 ( V_4 ) )
return F_115 ( V_2 , & T_5 ) ;
return F_114 ( V_2 , & T_5 ) ;
}
int F_131 ( struct V_1 * V_2 , unsigned int V_131 ,
bool V_109 )
{
return F_128 ( V_2 , V_131 , V_109 , 0 , false ) ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_150 * V_150 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
if ( V_18 -> V_4 && V_150 -> V_151 )
F_25 ( V_18 -> V_4 ) ;
if ( ! V_18 -> V_4 || V_150 -> V_151 )
V_18 -> V_4 = F_133 ( V_2 -> V_4 ) ;
V_18 -> V_6 = F_134 ( V_2 -> V_6 ) ;
if ( ! V_18 -> V_4 || ! V_18 -> V_6 )
return - V_42 ;
}
return 0 ;
}
int F_135 ( struct V_1 * V_2 , struct V_150 * V_150 )
{
V_2 -> V_6 = F_136 ( V_150 -> V_13 , V_150 -> V_92 ,
V_150 -> V_152 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( F_137 ( V_150 ) )
V_2 -> V_4 = F_138 () ;
else
V_2 -> V_4 = F_139 ( V_150 -> V_151 ) ;
if ( V_2 -> V_4 == NULL )
goto V_153;
return F_132 ( V_2 , V_150 ) ;
V_153:
F_26 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
return - 1 ;
}
int F_140 ( struct V_1 * V_2 , struct V_14 * * V_154 )
{
struct V_14 * V_18 ;
int V_60 = 0 ;
const int V_155 = F_50 ( V_2 -> V_4 ) ,
V_156 = F_48 ( V_2 -> V_6 ) ;
F_14 (evlist, evsel) {
if ( V_18 -> V_157 == NULL )
continue;
V_60 = F_141 ( V_18 , V_155 , V_156 , V_18 -> V_157 ) ;
if ( V_60 ) {
* V_154 = V_18 ;
break;
}
}
return V_60 ;
}
int F_142 ( struct V_1 * V_2 , const char * V_157 )
{
struct V_14 * V_18 ;
int V_60 = 0 ;
const int V_155 = F_50 ( V_2 -> V_4 ) ,
V_156 = F_48 ( V_2 -> V_6 ) ;
F_14 (evlist, evsel) {
V_60 = F_141 ( V_18 , V_155 , V_156 , V_157 ) ;
if ( V_60 )
break;
}
return V_60 ;
}
int F_143 ( struct V_1 * V_2 , T_1 V_158 , T_13 * V_159 )
{
char * V_157 ;
int V_81 = - 1 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_158 ; ++ V_7 ) {
if ( V_7 == 0 ) {
if ( F_144 ( & V_157 , L_10 , V_159 [ V_7 ] ) < 0 )
return - 1 ;
} else {
char * V_160 ;
if ( F_144 ( & V_160 , L_11 , V_157 , V_159 [ V_7 ] ) < 0 )
goto V_161;
free ( V_157 ) ;
V_157 = V_160 ;
}
}
V_81 = F_142 ( V_2 , V_157 ) ;
V_161:
free ( V_157 ) ;
return V_81 ;
}
int F_145 ( struct V_1 * V_2 , T_13 V_13 )
{
return F_143 ( V_2 , 1 , & V_13 ) ;
}
bool F_146 ( struct V_1 * V_2 )
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
T_2 F_147 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
if ( V_2 -> V_162 )
return V_2 -> V_162 ;
F_14 (evlist, evsel)
V_2 -> V_162 |= V_18 -> V_36 . V_163 ;
return V_2 -> V_162 ;
}
T_2 F_148 ( struct V_1 * V_2 )
{
V_2 -> V_162 = 0 ;
return F_147 ( V_2 ) ;
}
bool F_149 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) , * V_19 = V_15 ;
T_2 V_87 = V_15 -> V_36 . V_87 ;
T_2 V_163 = V_15 -> V_36 . V_163 ;
F_14 (evlist, pos) {
if ( V_87 != V_19 -> V_36 . V_87 )
return false ;
}
if ( ( V_163 & V_164 ) &&
! ( V_87 & V_88 ) ) {
return false ;
}
return true ;
}
T_2 F_82 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
return V_15 -> V_36 . V_87 ;
}
T_14 F_150 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
struct V_165 * V_105 ;
T_2 V_163 ;
T_14 V_99 = 0 ;
if ( ! V_15 -> V_36 . V_101 )
goto V_166;
V_163 = V_15 -> V_36 . V_163 ;
if ( V_163 & V_167 )
V_99 += sizeof( V_105 -> V_92 ) * 2 ;
if ( V_163 & V_168 )
V_99 += sizeof( V_105 -> time ) ;
if ( V_163 & V_169 )
V_99 += sizeof( V_105 -> V_47 ) ;
if ( V_163 & V_170 )
V_99 += sizeof( V_105 -> V_171 ) ;
if ( V_163 & V_172 )
V_99 += sizeof( V_105 -> V_52 ) * 2 ;
if ( V_163 & V_173 )
V_99 += sizeof( V_105 -> V_47 ) ;
V_166:
return V_99 ;
}
bool F_151 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) , * V_19 = V_15 ;
F_152 (evlist, pos) {
if ( V_15 -> V_36 . V_101 != V_19 -> V_36 . V_101 )
return false ;
}
return true ;
}
bool F_89 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
return V_15 -> V_36 . V_101 ;
}
void F_153 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
V_2 -> V_174 = V_18 ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_155 = F_50 ( V_2 -> V_4 ) ;
int V_156 = F_48 ( V_2 -> V_6 ) ;
int V_20 ;
F_154 (evlist, evsel) {
V_20 = V_18 -> V_4 ? V_18 -> V_4 -> V_149 : V_155 ;
F_155 ( V_18 , V_20 , V_156 ) ;
}
}
static int F_156 ( struct V_1 * V_2 )
{
int V_60 = - V_42 ;
V_2 -> V_4 = F_139 ( NULL ) ;
if ( V_2 -> V_4 == NULL )
goto V_166;
V_2 -> V_6 = F_157 () ;
if ( V_2 -> V_6 == NULL )
goto V_175;
V_60 = 0 ;
V_166:
return V_60 ;
V_175:
F_25 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
goto V_166;
}
int F_158 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_60 ;
if ( V_2 -> V_6 == NULL && V_2 -> V_4 == NULL ) {
V_60 = F_156 ( V_2 ) ;
if ( V_60 < 0 )
goto V_176;
}
F_13 ( V_2 ) ;
F_14 (evlist, evsel) {
V_60 = F_159 ( V_18 , V_2 -> V_4 , V_2 -> V_6 ) ;
if ( V_60 < 0 )
goto V_176;
}
return 0 ;
V_176:
F_24 ( V_2 ) ;
V_84 = - V_60 ;
return V_60 ;
}
int F_160 ( struct V_1 * V_2 , struct V_150 * V_150 ,
const char * V_177 [] , bool V_178 ,
void (* F_161)( int V_179 , T_15 * V_180 , void * V_181 ) )
{
int V_182 [ 2 ] , V_183 [ 2 ] ;
char V_184 ;
if ( F_162 ( V_182 ) < 0 ) {
perror ( L_12 ) ;
return - 1 ;
}
if ( F_162 ( V_183 ) < 0 ) {
perror ( L_13 ) ;
goto V_185;
}
V_2 -> V_12 . V_13 = F_163 () ;
if ( V_2 -> V_12 . V_13 < 0 ) {
perror ( L_14 ) ;
goto V_186;
}
if ( ! V_2 -> V_12 . V_13 ) {
int V_81 ;
if ( V_178 )
F_164 ( 2 , 1 ) ;
signal ( V_187 , V_188 ) ;
F_165 ( V_182 [ 0 ] ) ;
F_165 ( V_183 [ 1 ] ) ;
F_67 ( V_183 [ 0 ] , V_189 , V_190 ) ;
F_165 ( V_182 [ 1 ] ) ;
V_81 = F_83 ( V_183 [ 0 ] , & V_184 , 1 ) ;
if ( V_81 != 1 ) {
if ( V_81 == - 1 )
perror ( L_15 ) ;
exit ( V_81 ) ;
}
F_166 ( V_177 [ 0 ] , ( char * * ) V_177 ) ;
if ( F_161 ) {
union V_191 V_135 ;
V_135 . V_192 = V_84 ;
if ( F_167 ( F_168 () , V_193 , V_135 ) )
perror ( V_177 [ 0 ] ) ;
} else
perror ( V_177 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_161 ) {
struct V_194 V_195 = {
. V_196 = V_197 ,
. V_198 = F_161 ,
} ;
V_194 ( V_193 , & V_195 , NULL ) ;
}
if ( F_169 ( V_150 ) ) {
if ( V_2 -> V_6 == NULL ) {
fprintf ( V_112 , L_16 ,
V_199 , __LINE__ ) ;
goto V_186;
}
F_170 ( V_2 -> V_6 , 0 , V_2 -> V_12 . V_13 ) ;
}
F_165 ( V_182 [ 1 ] ) ;
F_165 ( V_183 [ 0 ] ) ;
if ( F_83 ( V_182 [ 0 ] , & V_184 , 1 ) == - 1 ) {
perror ( L_15 ) ;
goto V_186;
}
F_67 ( V_183 [ 1 ] , V_189 , V_190 ) ;
V_2 -> V_12 . V_200 = V_183 [ 1 ] ;
F_165 ( V_182 [ 0 ] ) ;
return 0 ;
V_186:
F_165 ( V_183 [ 0 ] ) ;
F_165 ( V_183 [ 1 ] ) ;
V_185:
F_165 ( V_182 [ 0 ] ) ;
F_165 ( V_182 [ 1 ] ) ;
return - 1 ;
}
int F_171 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_200 > 0 ) {
char V_184 = 0 ;
int V_81 ;
V_81 = F_172 ( V_2 -> V_12 . V_200 , & V_184 , 1 ) ;
if ( V_81 < 0 )
perror ( L_17 ) ;
F_165 ( V_2 -> V_12 . V_200 ) ;
return V_81 ;
}
return 0 ;
}
int F_173 ( struct V_1 * V_2 , union V_94 * V_95 ,
struct V_165 * V_97 )
{
struct V_14 * V_18 = F_91 ( V_2 , V_95 ) ;
if ( ! V_18 )
return - V_201 ;
return F_174 ( V_18 , V_95 , V_97 ) ;
}
T_1 F_175 ( struct V_1 * V_2 , T_16 * V_202 )
{
struct V_14 * V_18 ;
T_1 V_203 = 0 ;
F_14 (evlist, evsel) {
V_203 += fprintf ( V_202 , L_18 , V_18 -> V_25 ? L_19 : L_20 ,
F_176 ( V_18 ) ) ;
}
return V_203 + fprintf ( V_202 , L_21 ) ;
}
int F_177 ( struct V_1 * V_2 V_119 ,
int V_60 , char * V_204 , T_1 V_99 )
{
int V_203 , V_145 ;
char V_205 [ V_206 ] , * V_207 = F_178 ( V_60 , V_205 , sizeof( V_205 ) ) ;
switch ( V_60 ) {
case V_208 :
case V_209 :
V_203 = F_179 ( V_204 , V_99 ,
L_22
L_23 , V_207 ) ;
V_145 = F_180 () ;
V_203 += F_179 ( V_204 + V_203 , V_99 - V_203 , L_24 ) ;
if ( V_145 >= 2 ) {
V_203 += F_179 ( V_204 + V_203 , V_99 - V_203 ,
L_25 ) ;
}
V_203 += F_179 ( V_204 + V_203 , V_99 - V_203 ,
L_26 ) ;
V_203 += F_179 ( V_204 + V_203 , V_99 - V_203 ,
L_27
L_28 , V_145 ) ;
break;
default:
F_179 ( V_204 , V_99 , L_29 , V_207 ) ;
break;
}
return 0 ;
}
int F_181 ( struct V_1 * V_2 , int V_60 , char * V_204 , T_1 V_99 )
{
char V_205 [ V_206 ] , * V_207 = F_178 ( V_60 , V_205 , sizeof( V_205 ) ) ;
int V_210 = V_2 -> V_121 / 1024 , V_211 , V_203 = 0 ;
switch ( V_60 ) {
case V_209 :
F_117 ( L_6 , & V_211 ) ;
V_203 += F_179 ( V_204 + V_203 , V_99 - V_203 ,
L_22
L_30
L_31 ,
V_207 , V_211 , V_210 ) ;
if ( V_210 >= V_211 ) {
V_203 += F_179 ( V_204 + V_203 , V_99 - V_203 ,
L_32 ,
V_211 + V_210 ) ;
}
V_203 += F_179 ( V_204 + V_203 , V_99 - V_203 ,
L_33 ) ;
break;
default:
F_179 ( V_204 , V_99 , L_29 , V_207 ) ;
break;
}
return 0 ;
}
void F_182 ( struct V_1 * V_2 ,
struct V_14 * V_212 )
{
struct V_14 * V_18 , * V_20 ;
F_39 ( V_213 ) ;
if ( V_212 == F_12 ( V_2 ) )
return;
F_17 (evlist, n, evsel) {
if ( V_18 -> V_30 == V_212 -> V_30 )
F_183 ( & V_18 -> V_21 , & V_213 ) ;
}
F_184 ( & V_213 , & V_2 -> V_10 ) ;
}
void F_185 ( struct V_1 * V_2 ,
struct V_14 * V_214 )
{
struct V_14 * V_18 ;
if ( V_214 -> V_26 )
return;
F_14 (evlist, evsel) {
if ( V_18 != V_214 )
V_18 -> V_26 = false ;
}
V_214 -> V_26 = true ;
}
