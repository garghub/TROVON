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
void F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 ;
if ( V_14 -> V_17 )
F_8 ( V_2 ) ;
if ( V_2 -> V_4 -> V_18 [ 0 ] < 0 )
V_14 -> V_19 = true ;
F_9 (evsel, &evlist->entries, node) {
F_10 ( V_16 , V_14 ) ;
if ( V_2 -> V_20 > 1 )
F_11 ( V_16 ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_15 * V_21 , * V_22 ;
F_13 (pos, n, &evlist->entries, node) {
F_14 ( & V_21 -> V_23 ) ;
F_15 ( V_21 ) ;
}
V_2 -> V_20 = 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
free ( V_2 -> V_24 ) ;
free ( V_2 -> V_25 ) ;
V_2 -> V_24 = NULL ;
V_2 -> V_25 = NULL ;
}
void F_17 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
F_16 ( V_2 ) ;
free ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 , struct V_15 * V_26 )
{
F_19 ( & V_26 -> V_23 , & V_2 -> V_10 ) ;
++ V_2 -> V_20 ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
int V_20 )
{
F_21 ( V_28 , & V_2 -> V_10 ) ;
V_2 -> V_20 += V_20 ;
}
void F_22 ( struct V_27 * V_28 )
{
struct V_15 * V_16 , * V_29 ;
V_29 = F_23 ( V_28 -> V_30 , struct V_15 , V_23 ) ;
V_16 = F_23 ( V_28 -> V_31 , struct V_15 , V_23 ) ;
V_29 -> V_32 = V_16 -> V_33 - V_29 -> V_33 + 1 ;
F_9 (evsel, list, node) {
V_16 -> V_29 = V_29 ;
}
}
void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_20 ) {
V_2 -> V_34 = V_2 -> V_20 > 1 ? 1 : 0 ;
F_22 ( & V_2 -> V_10 ) ;
}
}
int F_24 ( struct V_1 * V_2 )
{
struct V_35 V_36 = {
. type = V_37 ,
. V_38 = V_39 ,
} ;
struct V_15 * V_16 ;
F_25 ( & V_36 ) ;
V_16 = F_26 ( & V_36 , 0 ) ;
if ( V_16 == NULL )
goto error;
V_16 -> V_40 = F_27 ( L_1 ) ;
if ( ! V_16 -> V_40 )
goto V_41;
F_18 ( V_2 , V_16 ) ;
return 0 ;
V_41:
F_15 ( V_16 ) ;
error:
return - V_42 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_35 * V_43 , T_1 V_44 )
{
struct V_15 * V_16 , * V_22 ;
F_29 ( V_45 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_44 ; V_7 ++ ) {
V_16 = F_26 ( V_43 + V_7 , V_2 -> V_20 + V_7 ) ;
if ( V_16 == NULL )
goto V_46;
F_19 ( & V_16 -> V_23 , & V_45 ) ;
}
F_20 ( V_2 , & V_45 , V_44 ) ;
return 0 ;
V_46:
F_13 (evsel, n, &head, node)
F_15 ( V_16 ) ;
return - 1 ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_35 * V_43 , T_1 V_44 )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_44 ; V_7 ++ )
F_25 ( V_43 + V_7 ) ;
return F_28 ( V_2 , V_43 , V_44 ) ;
}
struct V_15 *
F_31 ( struct V_1 * V_2 , int V_47 )
{
struct V_15 * V_16 ;
F_9 (evsel, &evlist->entries, node) {
if ( V_16 -> V_36 . type == V_48 &&
( int ) V_16 -> V_36 . V_38 == V_47 )
return V_16 ;
}
return NULL ;
}
int F_32 ( struct V_1 * V_2 ,
const char * V_49 , const char * V_40 , void * V_50 )
{
struct V_15 * V_16 ;
V_16 = F_33 ( V_49 , V_40 , V_2 -> V_20 ) ;
if ( V_16 == NULL )
return - 1 ;
V_16 -> V_50 . V_51 = V_50 ;
F_18 ( V_2 , V_16 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
int V_52 , V_53 ;
struct V_15 * V_21 ;
int V_54 = F_35 ( V_2 -> V_4 ) ;
int V_55 = F_36 ( V_2 -> V_6 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_9 (pos, &evlist->entries, node) {
if ( ! F_37 ( V_21 ) )
continue;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ )
F_38 ( F_39 ( V_21 , V_52 , V_53 ) ,
V_56 , 0 ) ;
}
}
}
void F_40 ( struct V_1 * V_2 )
{
int V_52 , V_53 ;
struct V_15 * V_21 ;
int V_54 = F_35 ( V_2 -> V_4 ) ;
int V_55 = F_36 ( V_2 -> V_6 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_9 (pos, &evlist->entries, node) {
if ( ! F_37 ( V_21 ) )
continue;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ )
F_38 ( F_39 ( V_21 , V_52 , V_53 ) ,
V_57 , 0 ) ;
}
}
}
static int F_41 ( struct V_1 * V_2 )
{
int V_54 = F_35 ( V_2 -> V_4 ) ;
int V_55 = F_36 ( V_2 -> V_6 ) ;
int V_58 = V_54 * V_55 * V_2 -> V_20 ;
V_2 -> V_25 = malloc ( sizeof( struct V_25 ) * V_58 ) ;
return V_2 -> V_25 != NULL ? 0 : - V_42 ;
}
void F_42 ( struct V_1 * V_2 , int V_59 )
{
F_43 ( V_59 , V_60 , V_61 ) ;
V_2 -> V_25 [ V_2 -> V_62 ] . V_59 = V_59 ;
V_2 -> V_25 [ V_2 -> V_62 ] . V_63 = V_64 ;
V_2 -> V_62 ++ ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_52 , int V_53 , T_2 V_47 )
{
int V_65 ;
struct V_66 * V_67 = F_45 ( V_16 , V_52 , V_53 ) ;
V_67 -> V_47 = V_47 ;
V_67 -> V_16 = V_16 ;
V_65 = F_46 ( V_67 -> V_47 , V_68 ) ;
F_47 ( & V_67 -> V_23 , & V_2 -> V_9 [ V_65 ] ) ;
}
void F_48 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_52 , int V_53 , T_2 V_47 )
{
F_44 ( V_2 , V_16 , V_52 , V_53 , V_47 ) ;
V_16 -> V_47 [ V_16 -> V_69 ++ ] = V_47 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_52 , int V_53 , int V_59 )
{
T_2 V_70 [ 4 ] = { 0 , } ;
int V_71 = 1 ;
if ( ! ( V_16 -> V_36 . V_72 & V_73 ) ||
F_50 ( V_59 , & V_70 , sizeof( V_70 ) ) == - 1 )
return - 1 ;
if ( V_16 -> V_36 . V_72 & V_74 )
++ V_71 ;
if ( V_16 -> V_36 . V_72 & V_75 )
++ V_71 ;
F_48 ( V_2 , V_16 , V_52 , V_53 , V_70 [ V_71 ] ) ;
return 0 ;
}
struct V_15 * F_51 ( struct V_1 * V_2 , T_2 V_47 )
{
struct V_76 * V_45 ;
struct V_66 * V_67 ;
int V_65 ;
if ( V_2 -> V_20 == 1 )
return F_52 ( V_2 ) ;
V_65 = F_46 ( V_47 , V_68 ) ;
V_45 = & V_2 -> V_9 [ V_65 ] ;
F_53 (sid, head, node)
if ( V_67 -> V_47 == V_47 )
return V_67 -> V_16 ;
if ( ! F_54 ( V_2 ) )
return F_52 ( V_2 ) ;
return NULL ;
}
union V_77 * F_55 ( struct V_1 * V_2 , int V_33 )
{
struct V_78 * V_79 = & V_2 -> V_24 [ V_33 ] ;
unsigned int V_45 = F_56 ( V_79 ) ;
unsigned int V_80 = V_79 -> V_31 ;
unsigned char * V_81 = V_79 -> V_82 + V_83 ;
union V_77 * V_84 = NULL ;
if ( V_2 -> V_85 ) {
int V_86 = V_45 - V_80 ;
if ( V_86 > V_79 -> V_87 / 2 || V_86 < 0 ) {
fprintf ( V_88 , L_2 ) ;
V_80 = V_45 ;
}
}
if ( V_80 != V_45 ) {
T_1 V_89 ;
V_84 = (union V_77 * ) & V_81 [ V_80 & V_79 -> V_87 ] ;
V_89 = V_84 -> V_90 . V_89 ;
if ( ( V_80 & V_79 -> V_87 ) + V_89 != ( ( V_80 + V_89 ) & V_79 -> V_87 ) ) {
unsigned int V_91 = V_80 ;
unsigned int V_92 = F_57 ( sizeof( * V_84 ) , V_89 ) , V_93 ;
void * V_94 = & V_79 -> V_95 ;
do {
V_93 = F_57 ( V_79 -> V_87 + 1 - ( V_91 & V_79 -> V_87 ) , V_92 ) ;
memcpy ( V_94 , & V_81 [ V_91 & V_79 -> V_87 ] , V_93 ) ;
V_91 += V_93 ;
V_94 += V_93 ;
V_92 -= V_93 ;
} while ( V_92 );
V_84 = & V_79 -> V_95 ;
}
V_80 += V_89 ;
}
V_79 -> V_31 = V_80 ;
if ( ! V_2 -> V_85 )
F_58 ( V_79 , V_80 ) ;
return V_84 ;
}
void F_59 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_96 ; V_7 ++ ) {
if ( V_2 -> V_24 [ V_7 ] . V_82 != NULL ) {
F_60 ( V_2 -> V_24 [ V_7 ] . V_82 , V_2 -> V_97 ) ;
V_2 -> V_24 [ V_7 ] . V_82 = NULL ;
}
}
free ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
}
static int F_61 ( struct V_1 * V_2 )
{
V_2 -> V_96 = F_35 ( V_2 -> V_4 ) ;
if ( F_62 ( V_2 -> V_4 ) )
V_2 -> V_96 = F_36 ( V_2 -> V_6 ) ;
V_2 -> V_24 = F_6 ( V_2 -> V_96 * sizeof( struct V_78 ) ) ;
return V_2 -> V_24 != NULL ? 0 : - V_42 ;
}
static int F_63 ( struct V_1 * V_2 ,
int V_33 , int V_98 , int V_87 , int V_59 )
{
V_2 -> V_24 [ V_33 ] . V_31 = 0 ;
V_2 -> V_24 [ V_33 ] . V_87 = V_87 ;
V_2 -> V_24 [ V_33 ] . V_82 = V_24 ( NULL , V_2 -> V_97 , V_98 ,
V_99 , V_59 , 0 ) ;
if ( V_2 -> V_24 [ V_33 ] . V_82 == V_100 ) {
V_2 -> V_24 [ V_33 ] . V_82 = NULL ;
return - 1 ;
}
F_42 ( V_2 , V_59 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , int V_98 , int V_87 )
{
struct V_15 * V_16 ;
int V_52 , V_53 ;
int V_54 = F_35 ( V_2 -> V_4 ) ;
int V_55 = F_36 ( V_2 -> V_6 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
int V_101 = - 1 ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
F_9 (evsel, &evlist->entries, node) {
int V_59 = F_39 ( V_16 , V_52 , V_53 ) ;
if ( V_101 == - 1 ) {
V_101 = V_59 ;
if ( F_63 ( V_2 , V_52 ,
V_98 , V_87 , V_101 ) < 0 )
goto V_102;
} else {
if ( F_38 ( V_59 , V_103 , V_101 ) != 0 )
goto V_102;
}
if ( ( V_16 -> V_36 . V_72 & V_73 ) &&
F_49 ( V_2 , V_16 , V_52 , V_53 , V_59 ) < 0 )
goto V_102;
}
}
}
return 0 ;
V_102:
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
if ( V_2 -> V_24 [ V_52 ] . V_82 != NULL ) {
F_60 ( V_2 -> V_24 [ V_52 ] . V_82 , V_2 -> V_97 ) ;
V_2 -> V_24 [ V_52 ] . V_82 = NULL ;
}
}
return - 1 ;
}
static int F_65 ( struct V_1 * V_2 , int V_98 , int V_87 )
{
struct V_15 * V_16 ;
int V_53 ;
int V_55 = F_36 ( V_2 -> V_6 ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
int V_101 = - 1 ;
F_9 (evsel, &evlist->entries, node) {
int V_59 = F_39 ( V_16 , 0 , V_53 ) ;
if ( V_101 == - 1 ) {
V_101 = V_59 ;
if ( F_63 ( V_2 , V_53 ,
V_98 , V_87 , V_101 ) < 0 )
goto V_102;
} else {
if ( F_38 ( V_59 , V_103 , V_101 ) != 0 )
goto V_102;
}
if ( ( V_16 -> V_36 . V_72 & V_73 ) &&
F_49 ( V_2 , V_16 , 0 , V_53 , V_59 ) < 0 )
goto V_102;
}
}
return 0 ;
V_102:
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
if ( V_2 -> V_24 [ V_53 ] . V_82 != NULL ) {
F_60 ( V_2 -> V_24 [ V_53 ] . V_82 , V_2 -> V_97 ) ;
V_2 -> V_24 [ V_53 ] . V_82 = NULL ;
}
}
return - 1 ;
}
int F_66 ( struct V_1 * V_2 , unsigned int V_104 ,
bool V_85 )
{
struct V_15 * V_16 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
int V_98 = V_105 | ( V_85 ? 0 : V_106 ) , V_87 ;
if ( V_104 == V_107 )
V_104 = ( 512 * 1024 ) / V_83 ;
else if ( ! F_67 ( V_104 ) )
return - V_108 ;
V_87 = V_104 * V_83 - 1 ;
if ( V_2 -> V_24 == NULL && F_61 ( V_2 ) < 0 )
return - V_42 ;
if ( V_2 -> V_25 == NULL && F_41 ( V_2 ) < 0 )
return - V_42 ;
V_2 -> V_85 = V_85 ;
V_2 -> V_97 = ( V_104 + 1 ) * V_83 ;
F_9 (evsel, &evlist->entries, node) {
if ( ( V_16 -> V_36 . V_72 & V_73 ) &&
V_16 -> V_109 == NULL &&
F_68 ( V_16 , F_35 ( V_4 ) , V_6 -> V_110 ) < 0 )
return - V_42 ;
}
if ( F_62 ( V_4 ) )
return F_65 ( V_2 , V_98 , V_87 ) ;
return F_64 ( V_2 , V_98 , V_87 ) ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
V_2 -> V_6 = F_70 ( V_112 -> V_12 , V_112 -> V_113 ,
V_112 -> V_114 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( F_71 ( V_112 ) )
V_2 -> V_4 = F_72 () ;
else if ( ! F_73 ( V_112 ) && ! V_112 -> V_115 )
V_2 -> V_4 = F_72 () ;
else
V_2 -> V_4 = F_74 ( V_112 -> V_116 ) ;
if ( V_2 -> V_4 == NULL )
goto V_117;
return 0 ;
V_117:
F_75 ( V_2 -> V_6 ) ;
return - 1 ;
}
void F_76 ( struct V_1 * V_2 )
{
F_77 ( V_2 -> V_4 ) ;
F_75 ( V_2 -> V_6 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_6 = NULL ;
}
int F_78 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_118 = 0 ;
const int V_119 = F_35 ( V_2 -> V_4 ) ,
V_120 = F_36 ( V_2 -> V_6 ) ;
F_9 (evsel, &evlist->entries, node) {
if ( V_16 -> V_121 == NULL )
continue;
V_118 = F_79 ( V_16 , V_119 , V_120 , V_16 -> V_121 ) ;
if ( V_118 )
break;
}
return V_118 ;
}
int F_80 ( struct V_1 * V_2 , const char * V_121 )
{
struct V_15 * V_16 ;
int V_118 = 0 ;
const int V_119 = F_35 ( V_2 -> V_4 ) ,
V_120 = F_36 ( V_2 -> V_6 ) ;
F_9 (evsel, &evlist->entries, node) {
V_118 = F_79 ( V_16 , V_119 , V_120 , V_121 ) ;
if ( V_118 )
break;
}
return V_118 ;
}
bool F_81 ( struct V_1 * V_2 )
{
struct V_15 * V_122 = F_52 ( V_2 ) , * V_21 = V_122 ;
F_82 (pos, &evlist->entries, node) {
if ( V_122 -> V_36 . V_123 != V_21 -> V_36 . V_123 )
return false ;
}
return true ;
}
T_2 F_83 ( struct V_1 * V_2 )
{
struct V_15 * V_122 = F_52 ( V_2 ) ;
return V_122 -> V_36 . V_123 ;
}
T_3 F_84 ( struct V_1 * V_2 )
{
struct V_15 * V_122 = F_52 ( V_2 ) ;
struct V_124 * V_81 ;
T_2 V_123 ;
T_3 V_89 = 0 ;
if ( ! V_122 -> V_36 . V_125 )
goto V_126;
V_123 = V_122 -> V_36 . V_123 ;
if ( V_123 & V_127 )
V_89 += sizeof( V_81 -> V_113 ) * 2 ;
if ( V_123 & V_128 )
V_89 += sizeof( V_81 -> time ) ;
if ( V_123 & V_129 )
V_89 += sizeof( V_81 -> V_47 ) ;
if ( V_123 & V_130 )
V_89 += sizeof( V_81 -> V_131 ) ;
if ( V_123 & V_132 )
V_89 += sizeof( V_81 -> V_52 ) * 2 ;
V_126:
return V_89 ;
}
bool F_85 ( struct V_1 * V_2 )
{
struct V_15 * V_122 = F_52 ( V_2 ) , * V_21 = V_122 ;
F_82 (pos, &evlist->entries, node) {
if ( V_122 -> V_36 . V_125 != V_21 -> V_36 . V_125 )
return false ;
}
return true ;
}
bool F_54 ( struct V_1 * V_2 )
{
struct V_15 * V_122 = F_52 ( V_2 ) ;
return V_122 -> V_36 . V_125 ;
}
void F_86 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
V_2 -> V_133 = V_16 ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_119 = F_35 ( V_2 -> V_4 ) ;
int V_120 = F_36 ( V_2 -> V_6 ) ;
F_88 (evsel, &evlist->entries, node)
F_89 ( V_16 , V_119 , V_120 ) ;
}
int F_90 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_118 ;
F_9 (evsel, &evlist->entries, node) {
V_118 = F_91 ( V_16 , V_2 -> V_4 , V_2 -> V_6 ) ;
if ( V_118 < 0 )
goto V_134;
}
return 0 ;
V_134:
F_87 ( V_2 ) ;
V_135 = - V_118 ;
return V_118 ;
}
int F_92 ( struct V_1 * V_2 ,
struct V_111 * V_112 ,
const char * V_136 [] , bool V_137 ,
bool V_138 )
{
int V_139 [ 2 ] , V_140 [ 2 ] ;
char V_141 ;
if ( F_93 ( V_139 ) < 0 ) {
perror ( L_3 ) ;
return - 1 ;
}
if ( F_93 ( V_140 ) < 0 ) {
perror ( L_4 ) ;
goto V_142;
}
V_2 -> V_11 . V_12 = F_94 () ;
if ( V_2 -> V_11 . V_12 < 0 ) {
perror ( L_5 ) ;
goto V_143;
}
if ( ! V_2 -> V_11 . V_12 ) {
if ( V_137 )
F_95 ( 2 , 1 ) ;
signal ( V_144 , V_145 ) ;
F_96 ( V_139 [ 0 ] ) ;
F_96 ( V_140 [ 1 ] ) ;
F_43 ( V_140 [ 0 ] , V_146 , V_147 ) ;
F_97 ( L_6 , ( char * * ) V_136 ) ;
F_96 ( V_139 [ 1 ] ) ;
if ( F_50 ( V_140 [ 0 ] , & V_141 , 1 ) == - 1 )
perror ( L_7 ) ;
F_97 ( V_136 [ 0 ] , ( char * * ) V_136 ) ;
perror ( V_136 [ 0 ] ) ;
if ( V_138 )
F_98 ( F_99 () , V_148 ) ;
exit ( - 1 ) ;
}
if ( F_100 ( V_112 ) )
V_2 -> V_6 -> V_18 [ 0 ] = V_2 -> V_11 . V_12 ;
F_96 ( V_139 [ 1 ] ) ;
F_96 ( V_140 [ 0 ] ) ;
if ( F_50 ( V_139 [ 0 ] , & V_141 , 1 ) == - 1 ) {
perror ( L_7 ) ;
goto V_143;
}
F_43 ( V_140 [ 1 ] , V_146 , V_147 ) ;
V_2 -> V_11 . V_149 = V_140 [ 1 ] ;
F_96 ( V_139 [ 0 ] ) ;
return 0 ;
V_143:
F_96 ( V_140 [ 0 ] ) ;
F_96 ( V_140 [ 1 ] ) ;
V_142:
F_96 ( V_139 [ 0 ] ) ;
F_96 ( V_139 [ 1 ] ) ;
return - 1 ;
}
int F_101 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_149 > 0 ) {
char V_141 ;
int V_150 ;
V_150 = F_102 ( V_2 -> V_11 . V_149 , & V_141 , 1 ) ;
if ( V_150 < 0 )
perror ( L_8 ) ;
F_96 ( V_2 -> V_11 . V_149 ) ;
return V_150 ;
}
return 0 ;
}
int F_103 ( struct V_1 * V_2 , union V_77 * V_84 ,
struct V_124 * V_151 )
{
struct V_15 * V_16 = F_52 ( V_2 ) ;
return F_104 ( V_16 , V_84 , V_151 ) ;
}
T_1 F_105 ( struct V_1 * V_2 , T_4 * V_152 )
{
struct V_15 * V_16 ;
T_1 V_153 = 0 ;
F_9 (evsel, &evlist->entries, node) {
V_153 += fprintf ( V_152 , L_9 , V_16 -> V_33 ? L_10 : L_6 ,
F_106 ( V_16 ) ) ;
}
return V_153 + fprintf ( V_152 , L_11 ) ; ;
}
