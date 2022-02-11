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
struct V_15 * V_16 ;
if ( V_2 -> V_4 -> V_17 [ 0 ] < 0 )
V_14 -> V_18 = true ;
F_8 (evsel, &evlist->entries, node) {
F_9 ( V_16 , V_14 ) ;
if ( V_2 -> V_19 > 1 )
V_16 -> V_20 . V_21 |= V_22 ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_15 * V_23 , * V_24 ;
F_11 (pos, n, &evlist->entries, node) {
F_12 ( & V_23 -> V_25 ) ;
F_13 ( V_23 ) ;
}
V_2 -> V_19 = 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
free ( V_2 -> V_26 ) ;
free ( V_2 -> V_27 ) ;
V_2 -> V_26 = NULL ;
V_2 -> V_27 = NULL ;
}
void F_15 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_14 ( V_2 ) ;
free ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 , struct V_15 * V_28 )
{
F_17 ( & V_28 -> V_25 , & V_2 -> V_10 ) ;
++ V_2 -> V_19 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
int V_19 )
{
F_19 ( V_30 , & V_2 -> V_10 ) ;
V_2 -> V_19 += V_19 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_31 V_20 = {
. type = V_32 ,
. V_33 = V_34 ,
} ;
struct V_15 * V_16 ;
F_21 ( & V_20 ) ;
V_16 = F_22 ( & V_20 , 0 ) ;
if ( V_16 == NULL )
goto error;
V_16 -> V_35 = F_23 ( L_1 ) ;
if ( ! V_16 -> V_35 )
goto V_36;
F_16 ( V_2 , V_16 ) ;
return 0 ;
V_36:
F_13 ( V_16 ) ;
error:
return - V_37 ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_31 * V_38 , T_1 V_39 )
{
struct V_15 * V_16 , * V_24 ;
F_25 ( V_40 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_39 ; V_7 ++ ) {
V_16 = F_22 ( V_38 + V_7 , V_2 -> V_19 + V_7 ) ;
if ( V_16 == NULL )
goto V_41;
F_17 ( & V_16 -> V_25 , & V_40 ) ;
}
F_18 ( V_2 , & V_40 , V_39 ) ;
return 0 ;
V_41:
F_11 (evsel, n, &head, node)
F_13 ( V_16 ) ;
return - 1 ;
}
static int F_26 ( const char * V_42 )
{
char * V_43 , * V_44 ;
int V_45 = - 1 , V_46 ;
if ( F_27 ( & V_43 , L_2 , V_47 , V_42 ) < 0 )
return - 1 ;
V_44 = strrchr ( V_43 , ':' ) ;
if ( V_44 != NULL )
* V_44 = '/' ;
V_46 = F_28 ( V_43 , V_48 ) ;
if ( V_46 >= 0 ) {
char V_49 [ 16 ] ;
if ( F_29 ( V_46 , V_49 , sizeof( V_49 ) ) > 0 )
V_45 = atoi ( V_49 ) ;
F_30 ( V_46 ) ;
}
free ( V_43 ) ;
return V_45 ;
}
int F_31 ( struct V_1 * V_2 ,
const char * V_50 [] ,
T_1 V_51 )
{
int V_45 ;
T_1 V_7 ;
struct V_31 * V_38 = F_6 ( V_51 * sizeof( * V_38 ) ) ;
if ( V_38 == NULL )
return - 1 ;
for ( V_7 = 0 ; V_7 < V_51 ; V_7 ++ ) {
V_45 = F_26 ( V_50 [ V_7 ] ) ;
if ( V_45 < 0 )
goto V_52;
V_38 [ V_7 ] . type = V_53 ;
V_38 [ V_7 ] . V_33 = V_45 ;
V_38 [ V_7 ] . V_21 = ( V_54 | V_55 |
V_56 ) ;
V_38 [ V_7 ] . V_57 = 1 ;
}
V_45 = F_24 ( V_2 , V_38 , V_51 ) ;
V_52:
free ( V_38 ) ;
return V_45 ;
}
static struct V_15 *
F_32 ( struct V_1 * V_2 , int V_49 )
{
struct V_15 * V_16 ;
F_8 (evsel, &evlist->entries, node) {
if ( V_16 -> V_20 . type == V_53 &&
( int ) V_16 -> V_20 . V_33 == V_49 )
return V_16 ;
}
return NULL ;
}
int F_33 ( struct V_1 * V_2 ,
const struct V_58 * V_59 ,
T_1 V_60 )
{
struct V_15 * V_16 ;
int V_45 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_60 ; V_7 ++ ) {
V_45 = F_26 ( V_59 [ V_7 ] . V_35 ) ;
if ( V_45 < 0 )
goto V_61;
V_16 = F_32 ( V_2 , V_45 ) ;
if ( V_16 == NULL )
continue;
V_45 = - V_62 ;
if ( V_16 -> V_63 . V_64 != NULL )
goto V_61;
V_16 -> V_63 . V_64 = V_59 [ V_7 ] . V_63 ;
}
V_45 = 0 ;
V_61:
return V_45 ;
}
void F_34 ( struct V_1 * V_2 )
{
int V_65 , V_66 ;
struct V_15 * V_23 ;
for ( V_65 = 0 ; V_65 < V_2 -> V_4 -> V_67 ; V_65 ++ ) {
F_8 (pos, &evlist->entries, node) {
for ( V_66 = 0 ; V_66 < V_2 -> V_6 -> V_67 ; V_66 ++ )
F_35 ( F_36 ( V_23 , V_65 , V_66 ) , V_68 ) ;
}
}
}
void F_37 ( struct V_1 * V_2 )
{
int V_65 , V_66 ;
struct V_15 * V_23 ;
for ( V_65 = 0 ; V_65 < V_2 -> V_4 -> V_67 ; V_65 ++ ) {
F_8 (pos, &evlist->entries, node) {
for ( V_66 = 0 ; V_66 < V_2 -> V_6 -> V_67 ; V_66 ++ )
F_35 ( F_36 ( V_23 , V_65 , V_66 ) , V_69 ) ;
}
}
}
static int F_38 ( struct V_1 * V_2 )
{
int V_70 = V_2 -> V_4 -> V_67 * V_2 -> V_6 -> V_67 * V_2 -> V_19 ;
V_2 -> V_27 = malloc ( sizeof( struct V_27 ) * V_70 ) ;
return V_2 -> V_27 != NULL ? 0 : - V_37 ;
}
void F_39 ( struct V_1 * V_2 , int V_46 )
{
F_40 ( V_46 , V_71 , V_72 ) ;
V_2 -> V_27 [ V_2 -> V_73 ] . V_46 = V_46 ;
V_2 -> V_27 [ V_2 -> V_73 ] . V_74 = V_75 ;
V_2 -> V_73 ++ ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_65 , int V_66 , T_2 V_49 )
{
int V_76 ;
struct V_77 * V_78 = F_42 ( V_16 , V_65 , V_66 ) ;
V_78 -> V_49 = V_49 ;
V_78 -> V_16 = V_16 ;
V_76 = F_43 ( V_78 -> V_49 , V_79 ) ;
F_44 ( & V_78 -> V_25 , & V_2 -> V_9 [ V_76 ] ) ;
}
void F_45 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_65 , int V_66 , T_2 V_49 )
{
F_41 ( V_2 , V_16 , V_65 , V_66 , V_49 ) ;
V_16 -> V_49 [ V_16 -> V_80 ++ ] = V_49 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_65 , int V_66 , int V_46 )
{
T_2 V_81 [ 4 ] = { 0 , } ;
int V_82 = 1 ;
if ( ! ( V_16 -> V_20 . V_83 & V_84 ) ||
F_29 ( V_46 , & V_81 , sizeof( V_81 ) ) == - 1 )
return - 1 ;
if ( V_16 -> V_20 . V_83 & V_85 )
++ V_82 ;
if ( V_16 -> V_20 . V_83 & V_86 )
++ V_82 ;
F_45 ( V_2 , V_16 , V_65 , V_66 , V_81 [ V_82 ] ) ;
return 0 ;
}
struct V_15 * F_47 ( struct V_1 * V_2 , T_2 V_49 )
{
struct V_87 * V_40 ;
struct V_88 * V_23 ;
struct V_77 * V_78 ;
int V_76 ;
if ( V_2 -> V_19 == 1 )
return F_48 ( V_2 -> V_10 . V_89 , struct V_15 , V_25 ) ;
V_76 = F_43 ( V_49 , V_79 ) ;
V_40 = & V_2 -> V_9 [ V_76 ] ;
F_49 (sid, pos, head, node)
if ( V_78 -> V_49 == V_49 )
return V_78 -> V_16 ;
if ( ! F_50 ( V_2 ) )
return F_48 ( V_2 -> V_10 . V_89 , struct V_15 , V_25 ) ;
return NULL ;
}
union V_90 * F_51 ( struct V_1 * V_2 , int V_91 )
{
unsigned int V_92 = F_52 ( V_93 ) ;
struct V_94 * V_95 = & V_2 -> V_26 [ V_91 ] ;
unsigned int V_40 = F_53 ( V_95 ) ;
unsigned int V_96 = V_95 -> V_97 ;
unsigned char * V_98 = V_95 -> V_99 + V_92 ;
union V_90 * V_100 = NULL ;
if ( V_2 -> V_101 ) {
int V_102 = V_40 - V_96 ;
if ( V_102 > V_95 -> V_103 / 2 || V_102 < 0 ) {
fprintf ( V_104 , L_3 ) ;
V_96 = V_40 ;
}
}
if ( V_96 != V_40 ) {
T_1 V_105 ;
V_100 = (union V_90 * ) & V_98 [ V_96 & V_95 -> V_103 ] ;
V_105 = V_100 -> V_106 . V_105 ;
if ( ( V_96 & V_95 -> V_103 ) + V_105 != ( ( V_96 + V_105 ) & V_95 -> V_103 ) ) {
unsigned int V_107 = V_96 ;
unsigned int V_108 = F_54 ( sizeof( * V_100 ) , V_105 ) , V_109 ;
void * V_110 = & V_2 -> V_111 ;
do {
V_109 = F_54 ( V_95 -> V_103 + 1 - ( V_107 & V_95 -> V_103 ) , V_108 ) ;
memcpy ( V_110 , & V_98 [ V_107 & V_95 -> V_103 ] , V_109 ) ;
V_107 += V_109 ;
V_110 += V_109 ;
V_108 -= V_109 ;
} while ( V_108 );
V_100 = & V_2 -> V_111 ;
}
V_96 += V_105 ;
}
V_95 -> V_97 = V_96 ;
if ( ! V_2 -> V_101 )
F_55 ( V_95 , V_96 ) ;
return V_100 ;
}
void F_56 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_112 ; V_7 ++ ) {
if ( V_2 -> V_26 [ V_7 ] . V_99 != NULL ) {
F_57 ( V_2 -> V_26 [ V_7 ] . V_99 , V_2 -> V_113 ) ;
V_2 -> V_26 [ V_7 ] . V_99 = NULL ;
}
}
free ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
static int F_58 ( struct V_1 * V_2 )
{
V_2 -> V_112 = V_2 -> V_4 -> V_67 ;
if ( V_2 -> V_4 -> V_17 [ 0 ] == - 1 )
V_2 -> V_112 = V_2 -> V_6 -> V_67 ;
V_2 -> V_26 = F_6 ( V_2 -> V_112 * sizeof( struct V_94 ) ) ;
return V_2 -> V_26 != NULL ? 0 : - V_37 ;
}
static int F_59 ( struct V_1 * V_2 ,
int V_91 , int V_114 , int V_103 , int V_46 )
{
V_2 -> V_26 [ V_91 ] . V_97 = 0 ;
V_2 -> V_26 [ V_91 ] . V_103 = V_103 ;
V_2 -> V_26 [ V_91 ] . V_99 = V_26 ( NULL , V_2 -> V_113 , V_114 ,
V_115 , V_46 , 0 ) ;
if ( V_2 -> V_26 [ V_91 ] . V_99 == V_116 ) {
V_2 -> V_26 [ V_91 ] . V_99 = NULL ;
return - 1 ;
}
F_39 ( V_2 , V_46 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , int V_114 , int V_103 )
{
struct V_15 * V_16 ;
int V_65 , V_66 ;
for ( V_65 = 0 ; V_65 < V_2 -> V_4 -> V_67 ; V_65 ++ ) {
int V_117 = - 1 ;
for ( V_66 = 0 ; V_66 < V_2 -> V_6 -> V_67 ; V_66 ++ ) {
F_8 (evsel, &evlist->entries, node) {
int V_46 = F_36 ( V_16 , V_65 , V_66 ) ;
if ( V_117 == - 1 ) {
V_117 = V_46 ;
if ( F_59 ( V_2 , V_65 ,
V_114 , V_103 , V_117 ) < 0 )
goto V_118;
} else {
if ( F_35 ( V_46 , V_119 , V_117 ) != 0 )
goto V_118;
}
if ( ( V_16 -> V_20 . V_83 & V_84 ) &&
F_46 ( V_2 , V_16 , V_65 , V_66 , V_46 ) < 0 )
goto V_118;
}
}
}
return 0 ;
V_118:
for ( V_65 = 0 ; V_65 < V_2 -> V_4 -> V_67 ; V_65 ++ ) {
if ( V_2 -> V_26 [ V_65 ] . V_99 != NULL ) {
F_57 ( V_2 -> V_26 [ V_65 ] . V_99 , V_2 -> V_113 ) ;
V_2 -> V_26 [ V_65 ] . V_99 = NULL ;
}
}
return - 1 ;
}
static int F_61 ( struct V_1 * V_2 , int V_114 , int V_103 )
{
struct V_15 * V_16 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_2 -> V_6 -> V_67 ; V_66 ++ ) {
int V_117 = - 1 ;
F_8 (evsel, &evlist->entries, node) {
int V_46 = F_36 ( V_16 , 0 , V_66 ) ;
if ( V_117 == - 1 ) {
V_117 = V_46 ;
if ( F_59 ( V_2 , V_66 ,
V_114 , V_103 , V_117 ) < 0 )
goto V_118;
} else {
if ( F_35 ( V_46 , V_119 , V_117 ) != 0 )
goto V_118;
}
if ( ( V_16 -> V_20 . V_83 & V_84 ) &&
F_46 ( V_2 , V_16 , 0 , V_66 , V_46 ) < 0 )
goto V_118;
}
}
return 0 ;
V_118:
for ( V_66 = 0 ; V_66 < V_2 -> V_6 -> V_67 ; V_66 ++ ) {
if ( V_2 -> V_26 [ V_66 ] . V_99 != NULL ) {
F_57 ( V_2 -> V_26 [ V_66 ] . V_99 , V_2 -> V_113 ) ;
V_2 -> V_26 [ V_66 ] . V_99 = NULL ;
}
}
return - 1 ;
}
int F_62 ( struct V_1 * V_2 , unsigned int V_120 ,
bool V_101 )
{
unsigned int V_92 = F_52 ( V_93 ) ;
struct V_15 * V_16 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
int V_114 = V_121 | ( V_101 ? 0 : V_122 ) , V_103 ;
if ( V_120 == V_123 )
V_120 = ( 512 * 1024 ) / V_92 ;
else if ( ! F_63 ( V_120 ) )
return - V_124 ;
V_103 = V_120 * V_92 - 1 ;
if ( V_2 -> V_26 == NULL && F_58 ( V_2 ) < 0 )
return - V_37 ;
if ( V_2 -> V_27 == NULL && F_38 ( V_2 ) < 0 )
return - V_37 ;
V_2 -> V_101 = V_101 ;
V_2 -> V_113 = ( V_120 + 1 ) * V_92 ;
F_8 (evsel, &evlist->entries, node) {
if ( ( V_16 -> V_20 . V_83 & V_84 ) &&
V_16 -> V_125 == NULL &&
F_64 ( V_16 , V_4 -> V_67 , V_6 -> V_67 ) < 0 )
return - V_37 ;
}
if ( V_2 -> V_4 -> V_17 [ 0 ] == - 1 )
return F_61 ( V_2 , V_114 , V_103 ) ;
return F_60 ( V_2 , V_114 , V_103 ) ;
}
int F_65 ( struct V_1 * V_2 , T_3 V_126 ,
T_3 V_127 , const char * V_128 )
{
V_2 -> V_6 = F_66 ( V_126 , V_127 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( V_128 == NULL && V_127 != - 1 )
V_2 -> V_4 = F_67 () ;
else
V_2 -> V_4 = F_68 ( V_128 ) ;
if ( V_2 -> V_4 == NULL )
goto V_129;
return 0 ;
V_129:
F_69 ( V_2 -> V_6 ) ;
return - 1 ;
}
void F_70 ( struct V_1 * V_2 )
{
F_71 ( V_2 -> V_4 ) ;
F_69 ( V_2 -> V_6 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_6 = NULL ;
}
int F_72 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_2 -> V_6 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 ;
char * V_130 ;
int V_66 ;
int V_65 ;
int V_45 ;
int V_46 ;
F_8 (evsel, &evlist->entries, node) {
V_130 = V_16 -> V_130 ;
if ( ! V_130 )
continue;
for ( V_65 = 0 ; V_65 < V_4 -> V_67 ; V_65 ++ ) {
for ( V_66 = 0 ; V_66 < V_6 -> V_67 ; V_66 ++ ) {
V_46 = F_36 ( V_16 , V_65 , V_66 ) ;
V_45 = F_35 ( V_46 , V_131 , V_130 ) ;
if ( V_45 )
return V_45 ;
}
}
}
return 0 ;
}
bool F_73 ( const struct V_1 * V_2 )
{
struct V_15 * V_23 , * V_132 ;
V_23 = V_132 = F_48 ( V_2 -> V_10 . V_89 , struct V_15 , V_25 ) ;
F_74 (pos, &evlist->entries, node) {
if ( V_132 -> V_20 . V_21 != V_23 -> V_20 . V_21 )
return false ;
}
return true ;
}
T_2 F_75 ( const struct V_1 * V_2 )
{
struct V_15 * V_132 ;
V_132 = F_48 ( V_2 -> V_10 . V_89 , struct V_15 , V_25 ) ;
return V_132 -> V_20 . V_21 ;
}
T_4 F_76 ( const struct V_1 * V_2 )
{
struct V_15 * V_132 ;
struct V_133 * V_98 ;
T_2 V_21 ;
T_4 V_105 = 0 ;
V_132 = F_48 ( V_2 -> V_10 . V_89 , struct V_15 , V_25 ) ;
if ( ! V_132 -> V_20 . V_134 )
goto V_61;
V_21 = V_132 -> V_20 . V_21 ;
if ( V_21 & V_135 )
V_105 += sizeof( V_98 -> V_136 ) * 2 ;
if ( V_21 & V_55 )
V_105 += sizeof( V_98 -> time ) ;
if ( V_21 & V_22 )
V_105 += sizeof( V_98 -> V_49 ) ;
if ( V_21 & V_137 )
V_105 += sizeof( V_98 -> V_138 ) ;
if ( V_21 & V_56 )
V_105 += sizeof( V_98 -> V_65 ) * 2 ;
V_61:
return V_105 ;
}
bool F_77 ( const struct V_1 * V_2 )
{
struct V_15 * V_23 , * V_132 ;
V_23 = V_132 = F_48 ( V_2 -> V_10 . V_89 , struct V_15 , V_25 ) ;
F_74 (pos, &evlist->entries, node) {
if ( V_132 -> V_20 . V_134 != V_23 -> V_20 . V_134 )
return false ;
}
return true ;
}
bool F_50 ( const struct V_1 * V_2 )
{
struct V_15 * V_132 ;
V_132 = F_48 ( V_2 -> V_10 . V_89 , struct V_15 , V_25 ) ;
return V_132 -> V_20 . V_134 ;
}
void F_78 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
V_2 -> V_139 = V_16 ;
}
int F_79 ( struct V_1 * V_2 , bool V_140 )
{
struct V_15 * V_16 , * V_132 ;
int V_45 , V_141 , V_142 ;
V_132 = F_48 ( V_2 -> V_10 . V_89 , struct V_15 , V_25 ) ;
F_8 (evsel, &evlist->entries, node) {
struct V_143 * V_144 = NULL ;
if ( V_140 && V_16 != V_132 )
V_144 = V_132 -> V_46 ;
V_45 = F_80 ( V_16 , V_2 -> V_4 , V_2 -> V_6 ,
V_140 , V_144 ) ;
if ( V_45 < 0 )
goto V_145;
}
return 0 ;
V_145:
V_141 = V_2 -> V_4 ? V_2 -> V_4 -> V_67 : 1 ;
V_142 = V_2 -> V_6 ? V_2 -> V_6 -> V_67 : 1 ;
F_81 (evsel, &evlist->entries, node)
F_82 ( V_16 , V_141 , V_142 ) ;
return V_45 ;
}
int F_83 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
const char * V_146 [] )
{
int V_147 [ 2 ] , V_148 [ 2 ] ;
char V_149 ;
if ( F_84 ( V_147 ) < 0 ) {
perror ( L_4 ) ;
return - 1 ;
}
if ( F_84 ( V_148 ) < 0 ) {
perror ( L_5 ) ;
goto V_150;
}
V_2 -> V_11 . V_12 = F_85 () ;
if ( V_2 -> V_11 . V_12 < 0 ) {
perror ( L_6 ) ;
goto V_151;
}
if ( ! V_2 -> V_11 . V_12 ) {
if ( V_14 -> V_152 )
F_86 ( 2 , 1 ) ;
F_30 ( V_147 [ 0 ] ) ;
F_30 ( V_148 [ 1 ] ) ;
F_40 ( V_148 [ 0 ] , V_153 , V_154 ) ;
F_87 ( L_7 , ( char * * ) V_146 ) ;
F_30 ( V_147 [ 1 ] ) ;
if ( F_29 ( V_148 [ 0 ] , & V_149 , 1 ) == - 1 )
perror ( L_8 ) ;
F_87 ( V_146 [ 0 ] , ( char * * ) V_146 ) ;
perror ( V_146 [ 0 ] ) ;
F_88 ( F_89 () , V_155 ) ;
exit ( - 1 ) ;
}
if ( ! V_14 -> V_156 && V_14 -> V_127 == - 1 && V_14 -> V_126 == - 1 )
V_2 -> V_6 -> V_17 [ 0 ] = V_2 -> V_11 . V_12 ;
F_30 ( V_147 [ 1 ] ) ;
F_30 ( V_148 [ 0 ] ) ;
if ( F_29 ( V_147 [ 0 ] , & V_149 , 1 ) == - 1 ) {
perror ( L_8 ) ;
goto V_151;
}
V_2 -> V_11 . V_157 = V_148 [ 1 ] ;
F_30 ( V_147 [ 0 ] ) ;
return 0 ;
V_151:
F_30 ( V_148 [ 0 ] ) ;
F_30 ( V_148 [ 1 ] ) ;
V_150:
F_30 ( V_147 [ 0 ] ) ;
F_30 ( V_147 [ 1 ] ) ;
return - 1 ;
}
int F_90 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_157 > 0 ) {
return F_30 ( V_2 -> V_11 . V_157 ) ;
}
return 0 ;
}
