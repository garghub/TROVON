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
V_19 -> V_2 = NULL ;
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
static void F_27 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
if ( ! V_18 -> V_24 || V_2 -> V_25 ) {
F_25 ( V_18 -> V_4 ) ;
V_18 -> V_4 = F_28 ( V_2 -> V_4 ) ;
} else if ( V_18 -> V_4 != V_18 -> V_24 ) {
F_25 ( V_18 -> V_4 ) ;
V_18 -> V_4 = F_28 ( V_18 -> V_24 ) ;
}
F_26 ( V_18 -> V_6 ) ;
V_18 -> V_6 = F_29 ( V_2 -> V_6 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel)
F_27 ( V_2 , V_18 ) ;
}
void F_31 ( struct V_1 * V_2 , struct V_14 * V_26 )
{
V_26 -> V_2 = V_2 ;
F_32 ( & V_26 -> V_21 , & V_2 -> V_10 ) ;
V_26 -> V_27 = V_2 -> V_22 ;
V_26 -> V_28 = ! V_26 -> V_27 ;
if ( ! V_2 -> V_22 ++ )
F_11 ( V_2 ) ;
F_27 ( V_2 , V_26 ) ;
}
void F_33 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_14 * V_18 , * V_31 ;
F_34 (list, temp, evsel) {
F_18 ( & V_18 -> V_21 ) ;
F_31 ( V_2 , V_18 ) ;
}
}
void F_35 ( struct V_29 * V_30 )
{
struct V_14 * V_18 , * V_32 ;
V_32 = F_36 ( V_30 -> V_33 , struct V_14 , V_21 ) ;
V_18 = F_36 ( V_30 -> V_34 , struct V_14 , V_21 ) ;
V_32 -> V_35 = V_18 -> V_27 - V_32 -> V_27 + 1 ;
F_37 (list, evsel) {
V_18 -> V_32 = V_32 ;
}
}
void F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 ) {
V_2 -> V_36 = V_2 -> V_22 > 1 ? 1 : 0 ;
F_35 ( & V_2 -> V_10 ) ;
}
}
int F_9 ( struct V_1 * V_2 )
{
struct V_37 V_38 = {
. type = V_39 ,
. V_40 = V_41 ,
} ;
struct V_14 * V_18 ;
F_39 ( & V_38 ) ;
V_18 = F_40 ( & V_38 ) ;
if ( V_18 == NULL )
goto error;
V_18 -> V_42 = F_41 ( L_1 ) ;
if ( ! V_18 -> V_42 )
goto V_43;
F_31 ( V_2 , V_18 ) ;
return 0 ;
V_43:
F_19 ( V_18 ) ;
error:
return - V_44 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_37 * V_45 , T_1 V_46 )
{
struct V_14 * V_18 , * V_20 ;
F_43 ( V_47 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_46 ; V_7 ++ ) {
V_18 = F_44 ( V_45 + V_7 , V_2 -> V_22 + V_7 ) ;
if ( V_18 == NULL )
goto V_48;
F_32 ( & V_18 -> V_21 , & V_47 ) ;
}
F_33 ( V_2 , & V_47 ) ;
return 0 ;
V_48:
F_34 (&head, n, evsel)
F_19 ( V_18 ) ;
return - 1 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_37 * V_45 , T_1 V_46 )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_46 ; V_7 ++ )
F_39 ( V_45 + V_7 ) ;
return F_42 ( V_2 , V_45 , V_46 ) ;
}
struct V_14 *
F_46 ( struct V_1 * V_2 , int V_49 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
if ( V_18 -> V_38 . type == V_50 &&
( int ) V_18 -> V_38 . V_40 == V_49 )
return V_18 ;
}
return NULL ;
}
struct V_14 *
F_47 ( struct V_1 * V_2 ,
const char * V_42 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
if ( ( V_18 -> V_38 . type == V_50 ) &&
( strcmp ( V_18 -> V_42 , V_42 ) == 0 ) )
return V_18 ;
}
return NULL ;
}
int F_48 ( struct V_1 * V_2 ,
const char * V_51 , const char * V_42 , void * V_52 )
{
struct V_14 * V_18 = F_49 ( V_51 , V_42 ) ;
if ( V_18 == NULL )
return - 1 ;
V_18 -> V_52 = V_52 ;
F_31 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
if ( V_18 -> V_53 )
return 1 ;
else
return F_51 ( V_2 -> V_6 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
int V_54 , V_55 ;
struct V_14 * V_19 ;
int V_56 = F_53 ( V_2 -> V_4 ) ;
int V_57 ;
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ ) {
F_14 (evlist, pos) {
if ( ! F_54 ( V_19 ) || ! V_19 -> V_58 )
continue;
V_57 = F_50 ( V_2 , V_19 ) ;
for ( V_55 = 0 ; V_55 < V_57 ; V_55 ++ )
F_55 ( F_56 ( V_19 , V_54 , V_55 ) ,
V_59 , 0 ) ;
}
}
V_2 -> V_60 = false ;
}
void F_57 ( struct V_1 * V_2 )
{
int V_54 , V_55 ;
struct V_14 * V_19 ;
int V_56 = F_53 ( V_2 -> V_4 ) ;
int V_57 ;
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ ) {
F_14 (evlist, pos) {
if ( ! F_54 ( V_19 ) || ! V_19 -> V_58 )
continue;
V_57 = F_50 ( V_2 , V_19 ) ;
for ( V_55 = 0 ; V_55 < V_57 ; V_55 ++ )
F_55 ( F_56 ( V_19 , V_54 , V_55 ) ,
V_61 , 0 ) ;
}
}
V_2 -> V_60 = true ;
}
void F_58 ( struct V_1 * V_2 )
{
( V_2 -> V_60 ? F_52 : F_57 ) ( V_2 ) ;
}
int F_59 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
int V_54 , V_55 , V_62 ;
int V_56 = F_53 ( V_2 -> V_4 ) ;
int V_57 = F_50 ( V_2 , V_18 ) ;
if ( ! V_18 -> V_58 )
return 0 ;
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ ) {
for ( V_55 = 0 ; V_55 < V_57 ; V_55 ++ ) {
V_62 = F_55 ( F_56 ( V_18 , V_54 , V_55 ) ,
V_59 , 0 ) ;
if ( V_62 )
return V_62 ;
}
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
int V_54 , V_55 , V_62 ;
int V_56 = F_53 ( V_2 -> V_4 ) ;
int V_57 = F_50 ( V_2 , V_18 ) ;
if ( ! V_18 -> V_58 )
return - V_63 ;
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ ) {
for ( V_55 = 0 ; V_55 < V_57 ; V_55 ++ ) {
V_62 = F_55 ( F_56 ( V_18 , V_54 , V_55 ) ,
V_61 , 0 ) ;
if ( V_62 )
return V_62 ;
}
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_54 )
{
int V_55 , V_62 ;
int V_57 = F_50 ( V_2 , V_18 ) ;
if ( ! V_18 -> V_58 )
return - V_63 ;
for ( V_55 = 0 ; V_55 < V_57 ; V_55 ++ ) {
V_62 = F_55 ( F_56 ( V_18 , V_54 , V_55 ) ,
V_61 , 0 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_55 )
{
int V_54 , V_62 ;
int V_56 = F_53 ( V_2 -> V_4 ) ;
if ( ! V_18 -> V_58 )
return - V_63 ;
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ ) {
V_62 = F_55 ( F_56 ( V_18 , V_54 , V_55 ) , V_61 , 0 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_27 )
{
bool V_64 = ! F_64 ( V_2 -> V_4 ) ;
if ( V_64 )
return F_61 ( V_2 , V_18 , V_27 ) ;
else
return F_62 ( V_2 , V_18 , V_27 ) ;
}
int F_65 ( struct V_1 * V_2 )
{
int V_56 = F_53 ( V_2 -> V_4 ) ;
int V_57 = F_51 ( V_2 -> V_6 ) ;
int V_65 = 0 ;
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
if ( V_18 -> V_53 )
V_65 += V_56 ;
else
V_65 += V_56 * V_57 ;
}
if ( F_66 ( & V_2 -> V_11 ) < V_65 &&
F_67 ( & V_2 -> V_11 , V_65 ) < 0 )
return - V_44 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , int V_58 , int V_27 )
{
int V_19 = F_69 ( & V_2 -> V_11 , V_58 , V_66 | V_67 | V_68 ) ;
if ( V_19 >= 0 ) {
V_2 -> V_11 . V_69 [ V_19 ] . V_27 = V_27 ;
F_70 ( V_58 , V_70 , V_71 ) ;
}
return V_19 ;
}
int F_71 ( struct V_1 * V_2 , int V_58 )
{
return F_68 ( V_2 , V_58 , - 1 ) ;
}
static void F_72 ( struct V_72 * V_73 , int V_58 )
{
struct V_1 * V_2 = F_73 ( V_73 , struct V_1 , V_11 ) ;
F_74 ( V_2 , V_73 -> V_69 [ V_58 ] . V_27 ) ;
}
int F_75 ( struct V_1 * V_2 , short V_74 )
{
return F_76 ( & V_2 -> V_11 , V_74 ,
F_72 ) ;
}
int F_77 ( struct V_1 * V_2 , int V_75 )
{
return F_78 ( & V_2 -> V_11 , V_75 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_54 , int V_55 , T_2 V_49 )
{
int V_76 ;
struct V_77 * V_78 = F_80 ( V_18 , V_54 , V_55 ) ;
V_78 -> V_49 = V_49 ;
V_78 -> V_18 = V_18 ;
V_76 = F_81 ( V_78 -> V_49 , V_79 ) ;
F_82 ( & V_78 -> V_21 , & V_2 -> V_9 [ V_76 ] ) ;
}
void F_83 ( struct V_1 * V_2 , struct V_14 * V_18 ,
int V_54 , int V_55 , T_2 V_49 )
{
F_79 ( V_2 , V_18 , V_54 , V_55 , V_49 ) ;
V_18 -> V_49 [ V_18 -> V_80 ++ ] = V_49 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_54 , int V_55 , int V_58 )
{
T_2 V_81 [ 4 ] = { 0 , } ;
int V_82 = 1 ;
T_2 V_49 ;
int V_83 ;
V_83 = F_55 ( V_58 , V_84 , & V_49 ) ;
if ( ! V_83 )
goto V_85;
if ( V_86 != V_87 )
return - 1 ;
if ( F_85 ( V_2 ) & V_88 )
return - 1 ;
if ( ! ( V_18 -> V_38 . V_89 & V_90 ) ||
F_86 ( V_58 , & V_81 , sizeof( V_81 ) ) == - 1 )
return - 1 ;
if ( V_18 -> V_38 . V_89 & V_91 )
++ V_82 ;
if ( V_18 -> V_38 . V_89 & V_92 )
++ V_82 ;
V_49 = V_81 [ V_82 ] ;
V_85:
F_83 ( V_2 , V_18 , V_54 , V_55 , V_49 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_27 , int V_54 ,
int V_55 )
{
struct V_77 * V_78 = F_80 ( V_18 , V_54 , V_55 ) ;
V_78 -> V_27 = V_27 ;
if ( V_2 -> V_4 && V_54 >= 0 )
V_78 -> V_54 = V_2 -> V_4 -> V_93 [ V_54 ] ;
else
V_78 -> V_54 = - 1 ;
if ( ! V_18 -> V_53 && V_2 -> V_6 && V_55 >= 0 )
V_78 -> V_94 = F_88 ( V_2 -> V_6 , V_55 ) ;
else
V_78 -> V_94 = - 1 ;
}
struct V_77 * F_89 ( struct V_1 * V_2 , T_2 V_49 )
{
struct V_95 * V_47 ;
struct V_77 * V_78 ;
int V_76 ;
V_76 = F_81 ( V_49 , V_79 ) ;
V_47 = & V_2 -> V_9 [ V_76 ] ;
F_90 (sid, head, node)
if ( V_78 -> V_49 == V_49 )
return V_78 ;
return NULL ;
}
struct V_14 * F_91 ( struct V_1 * V_2 , T_2 V_49 )
{
struct V_77 * V_78 ;
if ( V_2 -> V_22 == 1 || ! V_49 )
return F_12 ( V_2 ) ;
V_78 = F_89 ( V_2 , V_49 ) ;
if ( V_78 )
return V_78 -> V_18 ;
if ( ! F_92 ( V_2 ) )
return F_12 ( V_2 ) ;
return NULL ;
}
static int F_93 ( struct V_1 * V_2 ,
union V_96 * V_97 , T_2 * V_49 )
{
const T_2 * V_98 = V_97 -> V_99 . V_98 ;
T_3 V_20 ;
V_20 = ( V_97 -> V_100 . V_101 - sizeof( V_97 -> V_100 ) ) >> 3 ;
if ( V_97 -> V_100 . type == V_102 ) {
if ( V_2 -> V_16 >= V_20 )
return - 1 ;
* V_49 = V_98 [ V_2 -> V_16 ] ;
} else {
if ( V_2 -> V_17 > V_20 )
return - 1 ;
V_20 -= V_2 -> V_17 ;
* V_49 = V_98 [ V_20 ] ;
}
return 0 ;
}
static struct V_14 * F_94 ( struct V_1 * V_2 ,
union V_96 * V_97 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
struct V_95 * V_47 ;
struct V_77 * V_78 ;
int V_76 ;
T_2 V_49 ;
if ( V_2 -> V_22 == 1 )
return V_15 ;
if ( ! V_15 -> V_38 . V_103 &&
V_97 -> V_100 . type != V_102 )
return V_15 ;
if ( F_93 ( V_2 , V_97 , & V_49 ) )
return NULL ;
if ( ! V_49 )
return V_15 ;
V_76 = F_81 ( V_49 , V_79 ) ;
V_47 = & V_2 -> V_9 [ V_76 ] ;
F_90 (sid, head, node) {
if ( V_78 -> V_49 == V_49 )
return V_78 -> V_18 ;
}
return NULL ;
}
union V_96 * F_95 ( struct V_1 * V_2 , int V_27 )
{
struct V_104 * V_105 = & V_2 -> V_23 [ V_27 ] ;
T_2 V_47 ;
T_2 V_106 = V_105 -> V_34 ;
unsigned char * V_107 = V_105 -> V_108 + V_109 ;
union V_96 * V_97 = NULL ;
if ( ! F_96 ( & V_105 -> V_110 ) )
return NULL ;
V_47 = F_97 ( V_105 ) ;
if ( V_2 -> V_111 ) {
int V_112 = V_47 - V_106 ;
if ( V_112 > V_105 -> V_113 / 2 || V_112 < 0 ) {
fprintf ( V_114 , L_2 ) ;
V_106 = V_47 ;
}
}
if ( V_106 != V_47 ) {
T_1 V_101 ;
V_97 = (union V_96 * ) & V_107 [ V_106 & V_105 -> V_113 ] ;
V_101 = V_97 -> V_100 . V_101 ;
if ( ( V_106 & V_105 -> V_113 ) + V_101 != ( ( V_106 + V_101 ) & V_105 -> V_113 ) ) {
unsigned int V_115 = V_106 ;
unsigned int V_116 = F_98 ( sizeof( * V_97 ) , V_101 ) , V_117 ;
void * V_118 = V_105 -> V_119 ;
do {
V_117 = F_98 ( V_105 -> V_113 + 1 - ( V_115 & V_105 -> V_113 ) , V_116 ) ;
memcpy ( V_118 , & V_107 [ V_115 & V_105 -> V_113 ] , V_117 ) ;
V_115 += V_117 ;
V_118 += V_117 ;
V_116 -= V_117 ;
} while ( V_116 );
V_97 = (union V_96 * ) V_105 -> V_119 ;
}
V_106 += V_101 ;
}
V_105 -> V_34 = V_106 ;
return V_97 ;
}
static bool F_99 ( struct V_104 * V_105 )
{
return F_97 ( V_105 ) == V_105 -> V_34 && ! V_105 -> V_120 . V_108 ;
}
static void F_100 ( struct V_1 * V_2 , int V_27 )
{
F_101 ( & V_2 -> V_23 [ V_27 ] . V_110 ) ;
}
static void F_74 ( struct V_1 * V_2 , int V_27 )
{
F_102 ( F_96 ( & V_2 -> V_23 [ V_27 ] . V_110 ) == 0 ) ;
if ( F_103 ( & V_2 -> V_23 [ V_27 ] . V_110 ) )
F_104 ( V_2 , V_27 ) ;
}
void F_105 ( struct V_1 * V_2 , int V_27 )
{
struct V_104 * V_105 = & V_2 -> V_23 [ V_27 ] ;
if ( ! V_2 -> V_111 ) {
T_2 V_106 = V_105 -> V_34 ;
F_106 ( V_105 , V_106 ) ;
}
if ( F_96 ( & V_105 -> V_110 ) == 1 && F_99 ( V_105 ) )
F_74 ( V_2 , V_27 ) ;
}
int __weak F_107 ( struct V_120 * T_4 V_121 ,
struct V_122 * T_5 V_121 ,
void * T_6 V_121 ,
int V_58 V_121 )
{
return 0 ;
}
void __weak F_108 ( struct V_120 * T_4 V_121 )
{
}
void __weak F_109 (
struct V_122 * T_5 V_121 ,
T_7 T_8 V_121 ,
unsigned int T_9 V_121 ,
bool T_10 V_121 )
{
}
void __weak F_110 (
struct V_122 * T_5 V_121 ,
struct V_1 * V_2 V_121 ,
int V_27 V_121 ,
bool T_11 V_121 )
{
}
static void F_104 ( struct V_1 * V_2 , int V_27 )
{
if ( V_2 -> V_23 [ V_27 ] . V_108 != NULL ) {
F_111 ( V_2 -> V_23 [ V_27 ] . V_108 , V_2 -> V_123 ) ;
V_2 -> V_23 [ V_27 ] . V_108 = NULL ;
F_112 ( & V_2 -> V_23 [ V_27 ] . V_110 , 0 ) ;
}
F_108 ( & V_2 -> V_23 [ V_27 ] . V_120 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_23 == NULL )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_124 ; V_7 ++ )
F_104 ( V_2 , V_7 ) ;
F_21 ( & V_2 -> V_23 ) ;
}
static int F_113 ( struct V_1 * V_2 )
{
V_2 -> V_124 = F_53 ( V_2 -> V_4 ) ;
if ( F_64 ( V_2 -> V_4 ) )
V_2 -> V_124 = F_51 ( V_2 -> V_6 ) ;
V_2 -> V_23 = F_7 ( V_2 -> V_124 * sizeof( struct V_104 ) ) ;
return V_2 -> V_23 != NULL ? 0 : - V_44 ;
}
static int F_114 ( struct V_1 * V_2 , int V_27 ,
struct V_125 * T_5 , int V_58 )
{
F_112 ( & V_2 -> V_23 [ V_27 ] . V_110 , 2 ) ;
V_2 -> V_23 [ V_27 ] . V_34 = 0 ;
V_2 -> V_23 [ V_27 ] . V_113 = T_5 -> V_113 ;
V_2 -> V_23 [ V_27 ] . V_108 = V_23 ( NULL , V_2 -> V_123 , T_5 -> V_126 ,
V_127 , V_58 , 0 ) ;
if ( V_2 -> V_23 [ V_27 ] . V_108 == V_128 ) {
F_115 ( L_3 ,
V_86 ) ;
V_2 -> V_23 [ V_27 ] . V_108 = NULL ;
return - 1 ;
}
if ( F_107 ( & V_2 -> V_23 [ V_27 ] . V_120 ,
& T_5 -> V_129 , V_2 -> V_23 [ V_27 ] . V_108 , V_58 ) )
return - 1 ;
return 0 ;
}
static int F_116 ( struct V_1 * V_2 , int V_27 ,
struct V_125 * T_5 , int V_54 ,
int V_55 , int * V_130 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
int V_58 ;
if ( V_18 -> V_53 && V_55 )
continue;
V_58 = F_56 ( V_18 , V_54 , V_55 ) ;
if ( * V_130 == - 1 ) {
* V_130 = V_58 ;
if ( F_114 ( V_2 , V_27 , T_5 , * V_130 ) < 0 )
return - 1 ;
} else {
if ( F_55 ( V_58 , V_131 , * V_130 ) != 0 )
return - 1 ;
F_100 ( V_2 , V_27 ) ;
}
if ( ! V_18 -> V_53 &&
F_68 ( V_2 , V_58 , V_27 ) < 0 ) {
F_74 ( V_2 , V_27 ) ;
return - 1 ;
}
if ( V_18 -> V_38 . V_89 & V_90 ) {
if ( F_84 ( V_2 , V_18 , V_54 , V_55 ,
V_58 ) < 0 )
return - 1 ;
F_87 ( V_2 , V_18 , V_27 , V_54 ,
V_55 ) ;
}
}
return 0 ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_125 * T_5 )
{
int V_54 , V_55 ;
int V_56 = F_53 ( V_2 -> V_4 ) ;
int V_57 = F_51 ( V_2 -> V_6 ) ;
F_115 ( L_4 ) ;
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ ) {
int V_130 = - 1 ;
F_110 ( & T_5 -> V_129 , V_2 , V_54 ,
true ) ;
for ( V_55 = 0 ; V_55 < V_57 ; V_55 ++ ) {
if ( F_116 ( V_2 , V_54 , T_5 , V_54 ,
V_55 , & V_130 ) )
goto V_132;
}
}
return 0 ;
V_132:
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ )
F_104 ( V_2 , V_54 ) ;
return - 1 ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_125 * T_5 )
{
int V_55 ;
int V_57 = F_51 ( V_2 -> V_6 ) ;
F_115 ( L_5 ) ;
for ( V_55 = 0 ; V_55 < V_57 ; V_55 ++ ) {
int V_130 = - 1 ;
F_110 ( & T_5 -> V_129 , V_2 , V_55 ,
false ) ;
if ( F_116 ( V_2 , V_55 , T_5 , 0 , V_55 ,
& V_130 ) )
goto V_132;
}
return 0 ;
V_132:
for ( V_55 = 0 ; V_55 < V_57 ; V_55 ++ )
F_104 ( V_2 , V_55 ) ;
return - 1 ;
}
static T_1 F_119 ( unsigned long V_133 )
{
if ( V_133 == V_134 ) {
int V_135 ;
if ( F_120 ( L_6 , & V_135 ) < 0 ) {
V_135 = 512 ;
} else {
V_135 -= ( V_109 / 1024 ) ;
}
V_133 = ( V_135 * 1024 ) / V_109 ;
if ( ! F_121 ( V_133 ) )
V_133 = F_122 ( V_133 ) ;
} else if ( ! F_121 ( V_133 ) )
return 0 ;
return ( V_133 + 1 ) * V_109 ;
}
static long F_123 ( const char * V_136 , unsigned long F_98 ,
unsigned long V_135 )
{
unsigned long V_133 , V_137 ;
static struct V_138 V_139 [] = {
{ . V_140 = 'B' , . V_141 = 1 } ,
{ . V_140 = 'K' , . V_141 = 1 << 10 } ,
{ . V_140 = 'M' , . V_141 = 1 << 20 } ,
{ . V_140 = 'G' , . V_141 = 1 << 30 } ,
{ . V_140 = 0 } ,
} ;
if ( V_136 == NULL )
return - V_63 ;
V_137 = F_124 ( V_136 , V_139 ) ;
if ( V_137 != ( unsigned long ) - 1 ) {
V_133 = F_125 ( V_137 , V_109 ) / V_109 ;
} else {
char * V_142 ;
V_133 = strtoul ( V_136 , & V_142 , 10 ) ;
if ( * V_142 != '\0' )
return - V_63 ;
}
if ( V_133 == 0 && F_98 == 0 ) {
} else if ( ! F_121 ( V_133 ) ) {
V_133 = F_126 ( V_133 ) ;
if ( ! V_133 )
return - V_63 ;
F_127 ( L_7 ,
V_133 * V_109 , V_133 ) ;
}
if ( V_133 > V_135 )
return - V_63 ;
return V_133 ;
}
int F_128 ( unsigned int * V_143 , const char * V_136 )
{
unsigned long V_135 = V_134 ;
long V_133 ;
if ( V_135 > V_144 / V_109 )
V_135 = V_144 / V_109 ;
V_133 = F_123 ( V_136 , 1 , V_135 ) ;
if ( V_133 < 0 ) {
F_129 ( L_8 ) ;
return - 1 ;
}
* V_143 = V_133 ;
return 0 ;
}
int F_130 ( const struct V_145 * V_146 , const char * V_136 ,
int T_12 V_121 )
{
return F_128 ( V_146 -> V_147 , V_136 ) ;
}
int F_131 ( struct V_1 * V_2 , unsigned int V_133 ,
bool V_111 , unsigned int T_9 ,
bool T_10 )
{
struct V_14 * V_18 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
struct V_125 T_5 = {
. V_126 = V_148 | ( V_111 ? 0 : V_149 ) ,
} ;
if ( V_2 -> V_23 == NULL && F_113 ( V_2 ) < 0 )
return - V_44 ;
if ( V_2 -> V_11 . V_10 == NULL && F_65 ( V_2 ) < 0 )
return - V_44 ;
V_2 -> V_111 = V_111 ;
V_2 -> V_123 = F_119 ( V_133 ) ;
F_132 ( L_9 , V_2 -> V_123 ) ;
T_5 . V_113 = V_2 -> V_123 - V_109 - 1 ;
F_109 ( & T_5 . V_129 , V_2 -> V_123 ,
T_9 , T_10 ) ;
F_14 (evlist, evsel) {
if ( ( V_18 -> V_38 . V_89 & V_90 ) &&
V_18 -> V_150 == NULL &&
F_133 ( V_18 , F_53 ( V_4 ) , V_6 -> V_151 ) < 0 )
return - V_44 ;
}
if ( F_64 ( V_4 ) )
return F_118 ( V_2 , & T_5 ) ;
return F_117 ( V_2 , & T_5 ) ;
}
int F_134 ( struct V_1 * V_2 , unsigned int V_133 ,
bool V_111 )
{
return F_131 ( V_2 , V_133 , V_111 , 0 , false ) ;
}
int F_135 ( struct V_1 * V_2 , struct V_152 * V_152 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_6 = F_136 ( V_152 -> V_13 , V_152 -> V_94 , V_152 -> V_153 ) ;
if ( ! V_6 )
return - 1 ;
if ( F_137 ( V_152 ) )
V_4 = F_138 () ;
else
V_4 = F_139 ( V_152 -> V_154 ) ;
if ( ! V_4 )
goto V_155;
V_2 -> V_25 = ! ! V_152 -> V_154 ;
F_4 ( V_2 , V_4 , V_6 ) ;
return 0 ;
V_155:
F_26 ( V_6 ) ;
return - 1 ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( V_4 != V_2 -> V_4 ) {
F_25 ( V_2 -> V_4 ) ;
V_2 -> V_4 = V_4 ;
}
if ( V_6 != V_2 -> V_6 ) {
F_26 ( V_2 -> V_6 ) ;
V_2 -> V_6 = V_6 ;
}
F_30 ( V_2 ) ;
}
int F_140 ( struct V_1 * V_2 , struct V_14 * * V_156 )
{
struct V_14 * V_18 ;
int V_62 = 0 ;
const int V_157 = F_53 ( V_2 -> V_4 ) ,
V_158 = F_51 ( V_2 -> V_6 ) ;
F_14 (evlist, evsel) {
if ( V_18 -> V_159 == NULL )
continue;
V_62 = F_141 ( V_18 , V_157 , V_158 , V_18 -> V_159 ) ;
if ( V_62 ) {
* V_156 = V_18 ;
break;
}
}
return V_62 ;
}
int F_142 ( struct V_1 * V_2 , const char * V_159 )
{
struct V_14 * V_18 ;
int V_62 = 0 ;
F_14 (evlist, evsel) {
V_62 = F_143 ( V_18 , V_159 ) ;
if ( V_62 )
break;
}
return V_62 ;
}
int F_144 ( struct V_1 * V_2 , T_1 V_160 , T_13 * V_161 )
{
char * V_159 ;
int V_83 = - 1 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_160 ; ++ V_7 ) {
if ( V_7 == 0 ) {
if ( F_145 ( & V_159 , L_10 , V_161 [ V_7 ] ) < 0 )
return - 1 ;
} else {
char * V_162 ;
if ( F_145 ( & V_162 , L_11 , V_159 , V_161 [ V_7 ] ) < 0 )
goto V_163;
free ( V_159 ) ;
V_159 = V_162 ;
}
}
V_83 = F_142 ( V_2 , V_159 ) ;
V_163:
free ( V_159 ) ;
return V_83 ;
}
int F_146 ( struct V_1 * V_2 , T_13 V_13 )
{
return F_144 ( V_2 , 1 , & V_13 ) ;
}
bool F_147 ( struct V_1 * V_2 )
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
T_2 F_148 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
if ( V_2 -> V_164 )
return V_2 -> V_164 ;
F_14 (evlist, evsel)
V_2 -> V_164 |= V_18 -> V_38 . V_165 ;
return V_2 -> V_164 ;
}
T_2 F_149 ( struct V_1 * V_2 )
{
V_2 -> V_164 = 0 ;
return F_148 ( V_2 ) ;
}
T_2 F_150 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
T_2 V_166 = 0 ;
F_14 (evlist, evsel)
V_166 |= V_18 -> V_38 . V_167 ;
return V_166 ;
}
bool F_151 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) , * V_19 = V_15 ;
T_2 V_89 = V_15 -> V_38 . V_89 ;
T_2 V_165 = V_15 -> V_38 . V_165 ;
F_14 (evlist, pos) {
if ( V_89 != V_19 -> V_38 . V_89 )
return false ;
}
if ( ( V_165 & V_168 ) &&
! ( V_89 & V_90 ) ) {
return false ;
}
return true ;
}
T_2 F_85 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
return V_15 -> V_38 . V_89 ;
}
T_14 F_152 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
struct V_169 * V_107 ;
T_2 V_165 ;
T_14 V_101 = 0 ;
if ( ! V_15 -> V_38 . V_103 )
goto V_170;
V_165 = V_15 -> V_38 . V_165 ;
if ( V_165 & V_171 )
V_101 += sizeof( V_107 -> V_94 ) * 2 ;
if ( V_165 & V_172 )
V_101 += sizeof( V_107 -> time ) ;
if ( V_165 & V_173 )
V_101 += sizeof( V_107 -> V_49 ) ;
if ( V_165 & V_174 )
V_101 += sizeof( V_107 -> V_175 ) ;
if ( V_165 & V_176 )
V_101 += sizeof( V_107 -> V_54 ) * 2 ;
if ( V_165 & V_177 )
V_101 += sizeof( V_107 -> V_49 ) ;
V_170:
return V_101 ;
}
bool F_153 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) , * V_19 = V_15 ;
F_154 (evlist, pos) {
if ( V_15 -> V_38 . V_103 != V_19 -> V_38 . V_103 )
return false ;
}
return true ;
}
bool F_92 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
return V_15 -> V_38 . V_103 ;
}
void F_155 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
V_2 -> V_178 = V_18 ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_157 = F_53 ( V_2 -> V_4 ) ;
int V_158 = F_51 ( V_2 -> V_6 ) ;
int V_20 ;
F_156 (evlist, evsel) {
V_20 = V_18 -> V_4 ? V_18 -> V_4 -> V_151 : V_157 ;
F_157 ( V_18 , V_20 , V_158 ) ;
}
}
static int F_158 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_62 = - V_44 ;
V_4 = F_139 ( NULL ) ;
if ( ! V_4 )
goto V_170;
V_6 = F_159 () ;
if ( ! V_6 )
goto V_179;
F_4 ( V_2 , V_4 , V_6 ) ;
V_170:
return V_62 ;
V_179:
F_25 ( V_4 ) ;
goto V_170;
}
int F_160 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_62 ;
if ( V_2 -> V_6 == NULL && V_2 -> V_4 == NULL ) {
V_62 = F_158 ( V_2 ) ;
if ( V_62 < 0 )
goto V_180;
}
F_13 ( V_2 ) ;
F_14 (evlist, evsel) {
V_62 = F_161 ( V_18 , V_2 -> V_4 , V_2 -> V_6 ) ;
if ( V_62 < 0 )
goto V_180;
}
return 0 ;
V_180:
F_24 ( V_2 ) ;
V_86 = - V_62 ;
return V_62 ;
}
int F_162 ( struct V_1 * V_2 , struct V_152 * V_152 ,
const char * V_181 [] , bool V_182 ,
void (* F_163)( int V_183 , T_15 * V_184 , void * V_185 ) )
{
int V_186 [ 2 ] , V_187 [ 2 ] ;
char V_188 ;
if ( F_164 ( V_186 ) < 0 ) {
perror ( L_12 ) ;
return - 1 ;
}
if ( F_164 ( V_187 ) < 0 ) {
perror ( L_13 ) ;
goto V_189;
}
V_2 -> V_12 . V_13 = F_165 () ;
if ( V_2 -> V_12 . V_13 < 0 ) {
perror ( L_14 ) ;
goto V_190;
}
if ( ! V_2 -> V_12 . V_13 ) {
int V_83 ;
if ( V_182 )
F_166 ( 2 , 1 ) ;
signal ( V_191 , V_192 ) ;
F_167 ( V_186 [ 0 ] ) ;
F_167 ( V_187 [ 1 ] ) ;
F_70 ( V_187 [ 0 ] , V_193 , V_194 ) ;
F_167 ( V_186 [ 1 ] ) ;
V_83 = F_86 ( V_187 [ 0 ] , & V_188 , 1 ) ;
if ( V_83 != 1 ) {
if ( V_83 == - 1 )
perror ( L_15 ) ;
exit ( V_83 ) ;
}
F_168 ( V_181 [ 0 ] , ( char * * ) V_181 ) ;
if ( F_163 ) {
union V_195 V_137 ;
V_137 . V_196 = V_86 ;
if ( F_169 ( F_170 () , V_197 , V_137 ) )
perror ( V_181 [ 0 ] ) ;
} else
perror ( V_181 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_163 ) {
struct V_198 V_199 = {
. V_200 = V_201 ,
. V_202 = F_163 ,
} ;
V_198 ( V_197 , & V_199 , NULL ) ;
}
if ( F_171 ( V_152 ) ) {
if ( V_2 -> V_6 == NULL ) {
fprintf ( V_114 , L_16 ,
V_203 , __LINE__ ) ;
goto V_190;
}
F_172 ( V_2 -> V_6 , 0 , V_2 -> V_12 . V_13 ) ;
}
F_167 ( V_186 [ 1 ] ) ;
F_167 ( V_187 [ 0 ] ) ;
if ( F_86 ( V_186 [ 0 ] , & V_188 , 1 ) == - 1 ) {
perror ( L_15 ) ;
goto V_190;
}
F_70 ( V_187 [ 1 ] , V_193 , V_194 ) ;
V_2 -> V_12 . V_204 = V_187 [ 1 ] ;
F_167 ( V_186 [ 0 ] ) ;
return 0 ;
V_190:
F_167 ( V_187 [ 0 ] ) ;
F_167 ( V_187 [ 1 ] ) ;
V_189:
F_167 ( V_186 [ 0 ] ) ;
F_167 ( V_186 [ 1 ] ) ;
return - 1 ;
}
int F_173 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_204 > 0 ) {
char V_188 = 0 ;
int V_83 ;
V_83 = F_174 ( V_2 -> V_12 . V_204 , & V_188 , 1 ) ;
if ( V_83 < 0 )
perror ( L_17 ) ;
F_167 ( V_2 -> V_12 . V_204 ) ;
return V_83 ;
}
return 0 ;
}
int F_175 ( struct V_1 * V_2 , union V_96 * V_97 ,
struct V_169 * V_99 )
{
struct V_14 * V_18 = F_94 ( V_2 , V_97 ) ;
if ( ! V_18 )
return - V_205 ;
return F_176 ( V_18 , V_97 , V_99 ) ;
}
T_1 F_177 ( struct V_1 * V_2 , T_16 * V_206 )
{
struct V_14 * V_18 ;
T_1 V_207 = 0 ;
F_14 (evlist, evsel) {
V_207 += fprintf ( V_206 , L_18 , V_18 -> V_27 ? L_19 : L_20 ,
F_178 ( V_18 ) ) ;
}
return V_207 + fprintf ( V_206 , L_21 ) ;
}
int F_179 ( struct V_1 * V_2 V_121 ,
int V_62 , char * V_208 , T_1 V_101 )
{
int V_207 , V_147 ;
char V_209 [ V_210 ] , * V_211 = F_180 ( V_62 , V_209 , sizeof( V_209 ) ) ;
switch ( V_62 ) {
case V_212 :
case V_213 :
V_207 = F_181 ( V_208 , V_101 ,
L_22
L_23 , V_211 ) ;
V_147 = F_182 () ;
V_207 += F_181 ( V_208 + V_207 , V_101 - V_207 , L_24 ) ;
if ( V_147 >= 2 ) {
V_207 += F_181 ( V_208 + V_207 , V_101 - V_207 ,
L_25 ) ;
}
V_207 += F_181 ( V_208 + V_207 , V_101 - V_207 ,
L_26 ) ;
V_207 += F_181 ( V_208 + V_207 , V_101 - V_207 ,
L_27
L_28 , V_147 ) ;
break;
default:
F_181 ( V_208 , V_101 , L_29 , V_211 ) ;
break;
}
return 0 ;
}
int F_183 ( struct V_1 * V_2 , int V_62 , char * V_208 , T_1 V_101 )
{
char V_209 [ V_210 ] , * V_211 = F_180 ( V_62 , V_209 , sizeof( V_209 ) ) ;
int V_214 = V_2 -> V_123 / 1024 , V_215 , V_207 = 0 ;
switch ( V_62 ) {
case V_213 :
F_120 ( L_6 , & V_215 ) ;
V_207 += F_181 ( V_208 + V_207 , V_101 - V_207 ,
L_22
L_30
L_31 ,
V_211 , V_215 , V_214 ) ;
if ( V_214 >= V_215 ) {
V_207 += F_181 ( V_208 + V_207 , V_101 - V_207 ,
L_32 ,
V_215 + V_214 ) ;
}
V_207 += F_181 ( V_208 + V_207 , V_101 - V_207 ,
L_33 ) ;
break;
default:
F_181 ( V_208 , V_101 , L_29 , V_211 ) ;
break;
}
return 0 ;
}
void F_184 ( struct V_1 * V_2 ,
struct V_14 * V_216 )
{
struct V_14 * V_18 , * V_20 ;
F_43 ( V_217 ) ;
if ( V_216 == F_12 ( V_2 ) )
return;
F_17 (evlist, n, evsel) {
if ( V_18 -> V_32 == V_216 -> V_32 )
F_185 ( & V_18 -> V_21 , & V_217 ) ;
}
F_186 ( & V_217 , & V_2 -> V_10 ) ;
}
void F_187 ( struct V_1 * V_2 ,
struct V_14 * V_218 )
{
struct V_14 * V_18 ;
if ( V_218 -> V_28 )
return;
F_14 (evlist, evsel) {
if ( V_18 != V_218 )
V_18 -> V_28 = false ;
}
V_218 -> V_28 = true ;
}
