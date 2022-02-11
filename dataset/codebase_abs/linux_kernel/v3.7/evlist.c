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
struct V_1 * F_5 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( sizeof( * V_2 ) ) ;
if ( V_2 != NULL )
F_1 ( V_2 , V_4 , V_6 ) ;
return V_2 ;
}
void F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 , * V_17 ;
if ( V_2 -> V_4 -> V_18 [ 0 ] < 0 )
V_14 -> V_19 = true ;
V_17 = F_8 ( V_2 ) ;
F_9 (evsel, &evlist->entries, node) {
F_10 ( V_16 , V_14 , V_17 ) ;
if ( V_2 -> V_20 > 1 )
V_16 -> V_21 . V_22 |= V_23 ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_15 * V_24 , * V_25 ;
F_12 (pos, n, &evlist->entries, node) {
F_13 ( & V_24 -> V_26 ) ;
F_14 ( V_24 ) ;
}
V_2 -> V_20 = 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
free ( V_2 -> V_27 ) ;
free ( V_2 -> V_28 ) ;
V_2 -> V_27 = NULL ;
V_2 -> V_28 = NULL ;
}
void F_16 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_15 ( V_2 ) ;
free ( V_2 ) ;
}
void F_17 ( struct V_1 * V_2 , struct V_15 * V_29 )
{
F_18 ( & V_29 -> V_26 , & V_2 -> V_10 ) ;
++ V_2 -> V_20 ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
int V_20 )
{
F_20 ( V_31 , & V_2 -> V_10 ) ;
V_2 -> V_20 += V_20 ;
}
void F_21 ( struct V_30 * V_31 )
{
struct V_15 * V_16 , * V_32 ;
V_32 = F_22 ( V_31 -> V_33 , struct V_15 , V_26 ) ;
V_32 -> V_32 = NULL ;
F_9 (evsel, list, node) {
if ( V_16 != V_32 )
V_16 -> V_32 = V_32 ;
}
}
void F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_20 )
F_21 ( & V_2 -> V_10 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_34 V_21 = {
. type = V_35 ,
. V_36 = V_37 ,
} ;
struct V_15 * V_16 ;
F_25 ( & V_21 ) ;
V_16 = F_26 ( & V_21 , 0 ) ;
if ( V_16 == NULL )
goto error;
V_16 -> V_38 = F_27 ( L_1 ) ;
if ( ! V_16 -> V_38 )
goto V_39;
F_17 ( V_2 , V_16 ) ;
return 0 ;
V_39:
F_14 ( V_16 ) ;
error:
return - V_40 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_34 * V_41 , T_1 V_42 )
{
struct V_15 * V_16 , * V_25 ;
F_29 ( V_43 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_42 ; V_7 ++ ) {
V_16 = F_26 ( V_41 + V_7 , V_2 -> V_20 + V_7 ) ;
if ( V_16 == NULL )
goto V_44;
F_18 ( & V_16 -> V_26 , & V_43 ) ;
}
F_19 ( V_2 , & V_43 , V_42 ) ;
return 0 ;
V_44:
F_12 (evsel, n, &head, node)
F_14 ( V_16 ) ;
return - 1 ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_34 * V_41 , T_1 V_42 )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_42 ; V_7 ++ )
F_25 ( V_41 + V_7 ) ;
return F_28 ( V_2 , V_41 , V_42 ) ;
}
struct V_15 *
F_31 ( struct V_1 * V_2 , int V_45 )
{
struct V_15 * V_16 ;
F_9 (evsel, &evlist->entries, node) {
if ( V_16 -> V_21 . type == V_46 &&
( int ) V_16 -> V_21 . V_36 == V_45 )
return V_16 ;
}
return NULL ;
}
int F_32 ( struct V_1 * V_2 ,
const char * V_47 , const char * V_38 , void * V_48 )
{
struct V_15 * V_16 ;
V_16 = F_33 ( V_47 , V_38 , V_2 -> V_20 ) ;
if ( V_16 == NULL )
return - 1 ;
V_16 -> V_48 . V_49 = V_48 ;
F_17 ( V_2 , V_16 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
int V_50 , V_51 ;
struct V_15 * V_24 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_4 -> V_52 ; V_50 ++ ) {
F_9 (pos, &evlist->entries, node) {
for ( V_51 = 0 ; V_51 < V_2 -> V_6 -> V_52 ; V_51 ++ )
F_35 ( F_36 ( V_24 , V_50 , V_51 ) ,
V_53 , 0 ) ;
}
}
}
void F_37 ( struct V_1 * V_2 )
{
int V_50 , V_51 ;
struct V_15 * V_24 ;
for ( V_50 = 0 ; V_50 < F_38 ( V_2 -> V_4 ) ; V_50 ++ ) {
F_9 (pos, &evlist->entries, node) {
for ( V_51 = 0 ; V_51 < V_2 -> V_6 -> V_52 ; V_51 ++ )
F_35 ( F_36 ( V_24 , V_50 , V_51 ) ,
V_54 , 0 ) ;
}
}
}
static int F_39 ( struct V_1 * V_2 )
{
int V_55 = F_38 ( V_2 -> V_4 ) * V_2 -> V_6 -> V_52 * V_2 -> V_20 ;
V_2 -> V_28 = malloc ( sizeof( struct V_28 ) * V_55 ) ;
return V_2 -> V_28 != NULL ? 0 : - V_40 ;
}
void F_40 ( struct V_1 * V_2 , int V_56 )
{
F_41 ( V_56 , V_57 , V_58 ) ;
V_2 -> V_28 [ V_2 -> V_59 ] . V_56 = V_56 ;
V_2 -> V_28 [ V_2 -> V_59 ] . V_60 = V_61 ;
V_2 -> V_59 ++ ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_50 , int V_51 , T_2 V_45 )
{
int V_62 ;
struct V_63 * V_64 = F_43 ( V_16 , V_50 , V_51 ) ;
V_64 -> V_45 = V_45 ;
V_64 -> V_16 = V_16 ;
V_62 = F_44 ( V_64 -> V_45 , V_65 ) ;
F_45 ( & V_64 -> V_26 , & V_2 -> V_9 [ V_62 ] ) ;
}
void F_46 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_50 , int V_51 , T_2 V_45 )
{
F_42 ( V_2 , V_16 , V_50 , V_51 , V_45 ) ;
V_16 -> V_45 [ V_16 -> V_66 ++ ] = V_45 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_50 , int V_51 , int V_56 )
{
T_2 V_67 [ 4 ] = { 0 , } ;
int V_68 = 1 ;
if ( ! ( V_16 -> V_21 . V_69 & V_70 ) ||
F_48 ( V_56 , & V_67 , sizeof( V_67 ) ) == - 1 )
return - 1 ;
if ( V_16 -> V_21 . V_69 & V_71 )
++ V_68 ;
if ( V_16 -> V_21 . V_69 & V_72 )
++ V_68 ;
F_46 ( V_2 , V_16 , V_50 , V_51 , V_67 [ V_68 ] ) ;
return 0 ;
}
struct V_15 * F_49 ( struct V_1 * V_2 , T_2 V_45 )
{
struct V_73 * V_43 ;
struct V_74 * V_24 ;
struct V_63 * V_64 ;
int V_62 ;
if ( V_2 -> V_20 == 1 )
return F_8 ( V_2 ) ;
V_62 = F_44 ( V_45 , V_65 ) ;
V_43 = & V_2 -> V_9 [ V_62 ] ;
F_50 (sid, pos, head, node)
if ( V_64 -> V_45 == V_45 )
return V_64 -> V_16 ;
if ( ! F_51 ( V_2 ) )
return F_8 ( V_2 ) ;
return NULL ;
}
union V_75 * F_52 ( struct V_1 * V_2 , int V_76 )
{
unsigned int V_77 = F_53 ( V_78 ) ;
struct V_79 * V_80 = & V_2 -> V_27 [ V_76 ] ;
unsigned int V_43 = F_54 ( V_80 ) ;
unsigned int V_81 = V_80 -> V_82 ;
unsigned char * V_83 = V_80 -> V_84 + V_77 ;
union V_75 * V_85 = NULL ;
if ( V_2 -> V_86 ) {
int V_87 = V_43 - V_81 ;
if ( V_87 > V_80 -> V_88 / 2 || V_87 < 0 ) {
fprintf ( V_89 , L_2 ) ;
V_81 = V_43 ;
}
}
if ( V_81 != V_43 ) {
T_1 V_90 ;
V_85 = (union V_75 * ) & V_83 [ V_81 & V_80 -> V_88 ] ;
V_90 = V_85 -> V_91 . V_90 ;
if ( ( V_81 & V_80 -> V_88 ) + V_90 != ( ( V_81 + V_90 ) & V_80 -> V_88 ) ) {
unsigned int V_92 = V_81 ;
unsigned int V_93 = F_55 ( sizeof( * V_85 ) , V_90 ) , V_94 ;
void * V_95 = & V_2 -> V_96 ;
do {
V_94 = F_55 ( V_80 -> V_88 + 1 - ( V_92 & V_80 -> V_88 ) , V_93 ) ;
memcpy ( V_95 , & V_83 [ V_92 & V_80 -> V_88 ] , V_94 ) ;
V_92 += V_94 ;
V_95 += V_94 ;
V_93 -= V_94 ;
} while ( V_93 );
V_85 = & V_2 -> V_96 ;
}
V_81 += V_90 ;
}
V_80 -> V_82 = V_81 ;
if ( ! V_2 -> V_86 )
F_56 ( V_80 , V_81 ) ;
return V_85 ;
}
void F_57 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_97 ; V_7 ++ ) {
if ( V_2 -> V_27 [ V_7 ] . V_84 != NULL ) {
F_58 ( V_2 -> V_27 [ V_7 ] . V_84 , V_2 -> V_98 ) ;
V_2 -> V_27 [ V_7 ] . V_84 = NULL ;
}
}
free ( V_2 -> V_27 ) ;
V_2 -> V_27 = NULL ;
}
static int F_59 ( struct V_1 * V_2 )
{
V_2 -> V_97 = F_38 ( V_2 -> V_4 ) ;
if ( F_60 ( V_2 -> V_4 ) )
V_2 -> V_97 = V_2 -> V_6 -> V_52 ;
V_2 -> V_27 = F_6 ( V_2 -> V_97 * sizeof( struct V_79 ) ) ;
return V_2 -> V_27 != NULL ? 0 : - V_40 ;
}
static int F_61 ( struct V_1 * V_2 ,
int V_76 , int V_99 , int V_88 , int V_56 )
{
V_2 -> V_27 [ V_76 ] . V_82 = 0 ;
V_2 -> V_27 [ V_76 ] . V_88 = V_88 ;
V_2 -> V_27 [ V_76 ] . V_84 = V_27 ( NULL , V_2 -> V_98 , V_99 ,
V_100 , V_56 , 0 ) ;
if ( V_2 -> V_27 [ V_76 ] . V_84 == V_101 ) {
V_2 -> V_27 [ V_76 ] . V_84 = NULL ;
return - 1 ;
}
F_40 ( V_2 , V_56 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , int V_99 , int V_88 )
{
struct V_15 * V_16 ;
int V_50 , V_51 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_4 -> V_52 ; V_50 ++ ) {
int V_102 = - 1 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_6 -> V_52 ; V_51 ++ ) {
F_9 (evsel, &evlist->entries, node) {
int V_56 = F_36 ( V_16 , V_50 , V_51 ) ;
if ( V_102 == - 1 ) {
V_102 = V_56 ;
if ( F_61 ( V_2 , V_50 ,
V_99 , V_88 , V_102 ) < 0 )
goto V_103;
} else {
if ( F_35 ( V_56 , V_104 , V_102 ) != 0 )
goto V_103;
}
if ( ( V_16 -> V_21 . V_69 & V_70 ) &&
F_47 ( V_2 , V_16 , V_50 , V_51 , V_56 ) < 0 )
goto V_103;
}
}
}
return 0 ;
V_103:
for ( V_50 = 0 ; V_50 < V_2 -> V_4 -> V_52 ; V_50 ++ ) {
if ( V_2 -> V_27 [ V_50 ] . V_84 != NULL ) {
F_58 ( V_2 -> V_27 [ V_50 ] . V_84 , V_2 -> V_98 ) ;
V_2 -> V_27 [ V_50 ] . V_84 = NULL ;
}
}
return - 1 ;
}
static int F_63 ( struct V_1 * V_2 , int V_99 , int V_88 )
{
struct V_15 * V_16 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_6 -> V_52 ; V_51 ++ ) {
int V_102 = - 1 ;
F_9 (evsel, &evlist->entries, node) {
int V_56 = F_36 ( V_16 , 0 , V_51 ) ;
if ( V_102 == - 1 ) {
V_102 = V_56 ;
if ( F_61 ( V_2 , V_51 ,
V_99 , V_88 , V_102 ) < 0 )
goto V_103;
} else {
if ( F_35 ( V_56 , V_104 , V_102 ) != 0 )
goto V_103;
}
if ( ( V_16 -> V_21 . V_69 & V_70 ) &&
F_47 ( V_2 , V_16 , 0 , V_51 , V_56 ) < 0 )
goto V_103;
}
}
return 0 ;
V_103:
for ( V_51 = 0 ; V_51 < V_2 -> V_6 -> V_52 ; V_51 ++ ) {
if ( V_2 -> V_27 [ V_51 ] . V_84 != NULL ) {
F_58 ( V_2 -> V_27 [ V_51 ] . V_84 , V_2 -> V_98 ) ;
V_2 -> V_27 [ V_51 ] . V_84 = NULL ;
}
}
return - 1 ;
}
int F_64 ( struct V_1 * V_2 , unsigned int V_105 ,
bool V_86 )
{
unsigned int V_77 = F_53 ( V_78 ) ;
struct V_15 * V_16 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
int V_99 = V_106 | ( V_86 ? 0 : V_107 ) , V_88 ;
if ( V_105 == V_108 )
V_105 = ( 512 * 1024 ) / V_77 ;
else if ( ! F_65 ( V_105 ) )
return - V_109 ;
V_88 = V_105 * V_77 - 1 ;
if ( V_2 -> V_27 == NULL && F_59 ( V_2 ) < 0 )
return - V_40 ;
if ( V_2 -> V_28 == NULL && F_39 ( V_2 ) < 0 )
return - V_40 ;
V_2 -> V_86 = V_86 ;
V_2 -> V_98 = ( V_105 + 1 ) * V_77 ;
F_9 (evsel, &evlist->entries, node) {
if ( ( V_16 -> V_21 . V_69 & V_70 ) &&
V_16 -> V_110 == NULL &&
F_66 ( V_16 , F_38 ( V_4 ) , V_6 -> V_52 ) < 0 )
return - V_40 ;
}
if ( F_60 ( V_4 ) )
return F_63 ( V_2 , V_99 , V_88 ) ;
return F_62 ( V_2 , V_99 , V_88 ) ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
V_2 -> V_6 = F_68 ( V_112 -> V_12 , V_112 -> V_113 ,
V_112 -> V_114 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( F_69 ( V_112 ) )
V_2 -> V_4 = F_70 () ;
else if ( ! F_71 ( V_112 ) && ! V_112 -> V_115 )
V_2 -> V_4 = F_70 () ;
else
V_2 -> V_4 = F_72 ( V_112 -> V_116 ) ;
if ( V_2 -> V_4 == NULL )
goto V_117;
return 0 ;
V_117:
F_73 ( V_2 -> V_6 ) ;
return - 1 ;
}
void F_74 ( struct V_1 * V_2 )
{
F_75 ( V_2 -> V_4 ) ;
F_73 ( V_2 -> V_6 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_6 = NULL ;
}
int F_76 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_118 = 0 ;
const int V_119 = F_38 ( V_2 -> V_4 ) ,
V_120 = V_2 -> V_6 -> V_52 ;
F_9 (evsel, &evlist->entries, node) {
if ( V_16 -> V_121 == NULL )
continue;
V_118 = F_77 ( V_16 , V_119 , V_120 , V_16 -> V_121 ) ;
if ( V_118 )
break;
}
return V_118 ;
}
int F_78 ( struct V_1 * V_2 , const char * V_121 )
{
struct V_15 * V_16 ;
int V_118 = 0 ;
const int V_119 = F_38 ( V_2 -> V_4 ) ,
V_120 = V_2 -> V_6 -> V_52 ;
F_9 (evsel, &evlist->entries, node) {
V_118 = F_77 ( V_16 , V_119 , V_120 , V_121 ) ;
if ( V_118 )
break;
}
return V_118 ;
}
bool F_79 ( struct V_1 * V_2 )
{
struct V_15 * V_17 = F_8 ( V_2 ) , * V_24 = V_17 ;
F_80 (pos, &evlist->entries, node) {
if ( V_17 -> V_21 . V_22 != V_24 -> V_21 . V_22 )
return false ;
}
return true ;
}
T_2 F_81 ( struct V_1 * V_2 )
{
struct V_15 * V_17 = F_8 ( V_2 ) ;
return V_17 -> V_21 . V_22 ;
}
T_3 F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_17 = F_8 ( V_2 ) ;
struct V_122 * V_83 ;
T_2 V_22 ;
T_3 V_90 = 0 ;
if ( ! V_17 -> V_21 . V_123 )
goto V_124;
V_22 = V_17 -> V_21 . V_22 ;
if ( V_22 & V_125 )
V_90 += sizeof( V_83 -> V_113 ) * 2 ;
if ( V_22 & V_126 )
V_90 += sizeof( V_83 -> time ) ;
if ( V_22 & V_23 )
V_90 += sizeof( V_83 -> V_45 ) ;
if ( V_22 & V_127 )
V_90 += sizeof( V_83 -> V_128 ) ;
if ( V_22 & V_129 )
V_90 += sizeof( V_83 -> V_50 ) * 2 ;
V_124:
return V_90 ;
}
bool F_83 ( struct V_1 * V_2 )
{
struct V_15 * V_17 = F_8 ( V_2 ) , * V_24 = V_17 ;
F_80 (pos, &evlist->entries, node) {
if ( V_17 -> V_21 . V_123 != V_24 -> V_21 . V_123 )
return false ;
}
return true ;
}
bool F_51 ( struct V_1 * V_2 )
{
struct V_15 * V_17 = F_8 ( V_2 ) ;
return V_17 -> V_21 . V_123 ;
}
void F_84 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
V_2 -> V_130 = V_16 ;
}
int F_85 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_118 , V_119 , V_120 ;
F_9 (evsel, &evlist->entries, node) {
V_118 = F_86 ( V_16 , V_2 -> V_4 , V_2 -> V_6 ) ;
if ( V_118 < 0 )
goto V_131;
}
return 0 ;
V_131:
V_119 = V_2 -> V_4 ? V_2 -> V_4 -> V_52 : 1 ;
V_120 = V_2 -> V_6 ? V_2 -> V_6 -> V_52 : 1 ;
F_87 (evsel, &evlist->entries, node)
F_88 ( V_16 , V_119 , V_120 ) ;
V_132 = - V_118 ;
return V_118 ;
}
int F_89 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
const char * V_133 [] )
{
int V_134 [ 2 ] , V_135 [ 2 ] ;
char V_136 ;
if ( F_90 ( V_134 ) < 0 ) {
perror ( L_3 ) ;
return - 1 ;
}
if ( F_90 ( V_135 ) < 0 ) {
perror ( L_4 ) ;
goto V_137;
}
V_2 -> V_11 . V_12 = F_91 () ;
if ( V_2 -> V_11 . V_12 < 0 ) {
perror ( L_5 ) ;
goto V_138;
}
if ( ! V_2 -> V_11 . V_12 ) {
if ( V_14 -> V_139 )
F_92 ( 2 , 1 ) ;
F_93 ( V_134 [ 0 ] ) ;
F_93 ( V_135 [ 1 ] ) ;
F_41 ( V_135 [ 0 ] , V_140 , V_141 ) ;
F_94 ( L_6 , ( char * * ) V_133 ) ;
F_93 ( V_134 [ 1 ] ) ;
if ( F_48 ( V_135 [ 0 ] , & V_136 , 1 ) == - 1 )
perror ( L_7 ) ;
F_94 ( V_133 [ 0 ] , ( char * * ) V_133 ) ;
perror ( V_133 [ 0 ] ) ;
F_95 ( F_96 () , V_142 ) ;
exit ( - 1 ) ;
}
if ( F_97 ( & V_14 -> V_112 ) )
V_2 -> V_6 -> V_18 [ 0 ] = V_2 -> V_11 . V_12 ;
F_93 ( V_134 [ 1 ] ) ;
F_93 ( V_135 [ 0 ] ) ;
if ( F_48 ( V_134 [ 0 ] , & V_136 , 1 ) == - 1 ) {
perror ( L_7 ) ;
goto V_138;
}
V_2 -> V_11 . V_143 = V_135 [ 1 ] ;
F_93 ( V_134 [ 0 ] ) ;
return 0 ;
V_138:
F_93 ( V_135 [ 0 ] ) ;
F_93 ( V_135 [ 1 ] ) ;
V_137:
F_93 ( V_134 [ 0 ] ) ;
F_93 ( V_134 [ 1 ] ) ;
return - 1 ;
}
int F_98 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_143 > 0 ) {
return F_93 ( V_2 -> V_11 . V_143 ) ;
}
return 0 ;
}
int F_99 ( struct V_1 * V_2 , union V_75 * V_85 ,
struct V_122 * V_144 )
{
struct V_15 * V_16 = F_8 ( V_2 ) ;
return F_100 ( V_16 , V_85 , V_144 ) ;
}
T_1 F_101 ( struct V_1 * V_2 , T_4 * V_145 )
{
struct V_15 * V_16 ;
T_1 V_146 = 0 ;
F_9 (evsel, &evlist->entries, node) {
V_146 += fprintf ( V_145 , L_8 , V_16 -> V_76 ? L_9 : L_6 ,
F_102 ( V_16 ) ) ;
}
return V_146 + fprintf ( V_145 , L_10 ) ; ;
}
