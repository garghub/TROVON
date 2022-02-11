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
V_17 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
F_9 (evsel, &evlist->entries, node) {
F_10 ( V_16 , V_14 , V_17 ) ;
if ( V_2 -> V_22 > 1 )
V_16 -> V_23 . V_24 |= V_25 ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_15 * V_26 , * V_27 ;
F_12 (pos, n, &evlist->entries, node) {
F_13 ( & V_26 -> V_21 ) ;
F_14 ( V_26 ) ;
}
V_2 -> V_22 = 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
free ( V_2 -> V_28 ) ;
free ( V_2 -> V_29 ) ;
V_2 -> V_28 = NULL ;
V_2 -> V_29 = NULL ;
}
void F_16 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_15 ( V_2 ) ;
free ( V_2 ) ;
}
void F_17 ( struct V_1 * V_2 , struct V_15 * V_30 )
{
F_18 ( & V_30 -> V_21 , & V_2 -> V_10 ) ;
++ V_2 -> V_22 ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
int V_22 )
{
F_20 ( V_32 , & V_2 -> V_10 ) ;
V_2 -> V_22 += V_22 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_33 V_23 = {
. type = V_34 ,
. V_35 = V_36 ,
} ;
struct V_15 * V_16 ;
F_22 ( & V_23 ) ;
V_16 = F_23 ( & V_23 , 0 ) ;
if ( V_16 == NULL )
goto error;
V_16 -> V_37 = F_24 ( L_1 ) ;
if ( ! V_16 -> V_37 )
goto V_38;
F_17 ( V_2 , V_16 ) ;
return 0 ;
V_38:
F_14 ( V_16 ) ;
error:
return - V_39 ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_33 * V_40 , T_1 V_41 )
{
struct V_15 * V_16 , * V_27 ;
F_26 ( V_42 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_41 ; V_7 ++ ) {
V_16 = F_23 ( V_40 + V_7 , V_2 -> V_22 + V_7 ) ;
if ( V_16 == NULL )
goto V_43;
F_18 ( & V_16 -> V_21 , & V_42 ) ;
}
F_19 ( V_2 , & V_42 , V_41 ) ;
return 0 ;
V_43:
F_12 (evsel, n, &head, node)
F_14 ( V_16 ) ;
return - 1 ;
}
static int F_27 ( const char * V_44 )
{
char * V_45 , * V_46 ;
int V_47 = - 1 , V_48 ;
if ( F_28 ( & V_45 , L_2 , V_49 , V_44 ) < 0 )
return - 1 ;
V_46 = strrchr ( V_45 , ':' ) ;
if ( V_46 != NULL )
* V_46 = '/' ;
V_48 = F_29 ( V_45 , V_50 ) ;
if ( V_48 >= 0 ) {
char V_51 [ 16 ] ;
if ( F_30 ( V_48 , V_51 , sizeof( V_51 ) ) > 0 )
V_47 = atoi ( V_51 ) ;
F_31 ( V_48 ) ;
}
free ( V_45 ) ;
return V_47 ;
}
int F_32 ( struct V_1 * V_2 ,
const char * V_52 [] ,
T_1 V_53 )
{
int V_47 ;
T_1 V_7 ;
struct V_33 * V_40 = F_6 ( V_53 * sizeof( * V_40 ) ) ;
if ( V_40 == NULL )
return - 1 ;
for ( V_7 = 0 ; V_7 < V_53 ; V_7 ++ ) {
V_47 = F_27 ( V_52 [ V_7 ] ) ;
if ( V_47 < 0 )
goto V_54;
V_40 [ V_7 ] . type = V_55 ;
V_40 [ V_7 ] . V_35 = V_47 ;
V_40 [ V_7 ] . V_24 = ( V_56 | V_57 |
V_58 ) ;
V_40 [ V_7 ] . V_59 = 1 ;
}
V_47 = F_25 ( V_2 , V_40 , V_53 ) ;
V_54:
free ( V_40 ) ;
return V_47 ;
}
static struct V_15 *
F_33 ( struct V_1 * V_2 , int V_51 )
{
struct V_15 * V_16 ;
F_9 (evsel, &evlist->entries, node) {
if ( V_16 -> V_23 . type == V_55 &&
( int ) V_16 -> V_23 . V_35 == V_51 )
return V_16 ;
}
return NULL ;
}
int F_34 ( struct V_1 * V_2 ,
const struct V_60 * V_61 ,
T_1 V_62 )
{
struct V_15 * V_16 ;
int V_47 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_62 ; V_7 ++ ) {
V_47 = F_27 ( V_61 [ V_7 ] . V_37 ) ;
if ( V_47 < 0 )
goto V_63;
V_16 = F_33 ( V_2 , V_47 ) ;
if ( V_16 == NULL )
continue;
V_47 = - V_64 ;
if ( V_16 -> V_65 . V_66 != NULL )
goto V_63;
V_16 -> V_65 . V_66 = V_61 [ V_7 ] . V_65 ;
}
V_47 = 0 ;
V_63:
return V_47 ;
}
void F_35 ( struct V_1 * V_2 )
{
int V_67 , V_68 ;
struct V_15 * V_26 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_4 -> V_69 ; V_67 ++ ) {
F_9 (pos, &evlist->entries, node) {
for ( V_68 = 0 ; V_68 < V_2 -> V_6 -> V_69 ; V_68 ++ )
F_36 ( F_37 ( V_26 , V_67 , V_68 ) , V_70 ) ;
}
}
}
void F_38 ( struct V_1 * V_2 )
{
int V_67 , V_68 ;
struct V_15 * V_26 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_4 -> V_69 ; V_67 ++ ) {
F_9 (pos, &evlist->entries, node) {
for ( V_68 = 0 ; V_68 < V_2 -> V_6 -> V_69 ; V_68 ++ )
F_36 ( F_37 ( V_26 , V_67 , V_68 ) , V_71 ) ;
}
}
}
static int F_39 ( struct V_1 * V_2 )
{
int V_72 = V_2 -> V_4 -> V_69 * V_2 -> V_6 -> V_69 * V_2 -> V_22 ;
V_2 -> V_29 = malloc ( sizeof( struct V_29 ) * V_72 ) ;
return V_2 -> V_29 != NULL ? 0 : - V_39 ;
}
void F_40 ( struct V_1 * V_2 , int V_48 )
{
F_41 ( V_48 , V_73 , V_74 ) ;
V_2 -> V_29 [ V_2 -> V_75 ] . V_48 = V_48 ;
V_2 -> V_29 [ V_2 -> V_75 ] . V_76 = V_77 ;
V_2 -> V_75 ++ ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_67 , int V_68 , T_2 V_51 )
{
int V_78 ;
struct V_79 * V_80 = F_43 ( V_16 , V_67 , V_68 ) ;
V_80 -> V_51 = V_51 ;
V_80 -> V_16 = V_16 ;
V_78 = F_44 ( V_80 -> V_51 , V_81 ) ;
F_45 ( & V_80 -> V_21 , & V_2 -> V_9 [ V_78 ] ) ;
}
void F_46 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_67 , int V_68 , T_2 V_51 )
{
F_42 ( V_2 , V_16 , V_67 , V_68 , V_51 ) ;
V_16 -> V_51 [ V_16 -> V_82 ++ ] = V_51 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_67 , int V_68 , int V_48 )
{
T_2 V_83 [ 4 ] = { 0 , } ;
int V_84 = 1 ;
if ( ! ( V_16 -> V_23 . V_85 & V_86 ) ||
F_30 ( V_48 , & V_83 , sizeof( V_83 ) ) == - 1 )
return - 1 ;
if ( V_16 -> V_23 . V_85 & V_87 )
++ V_84 ;
if ( V_16 -> V_23 . V_85 & V_88 )
++ V_84 ;
F_46 ( V_2 , V_16 , V_67 , V_68 , V_83 [ V_84 ] ) ;
return 0 ;
}
struct V_15 * F_48 ( struct V_1 * V_2 , T_2 V_51 )
{
struct V_89 * V_42 ;
struct V_90 * V_26 ;
struct V_79 * V_80 ;
int V_78 ;
if ( V_2 -> V_22 == 1 )
return F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
V_78 = F_44 ( V_51 , V_81 ) ;
V_42 = & V_2 -> V_9 [ V_78 ] ;
F_49 (sid, pos, head, node)
if ( V_80 -> V_51 == V_51 )
return V_80 -> V_16 ;
if ( ! F_50 ( V_2 ) )
return F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
return NULL ;
}
union V_91 * F_51 ( struct V_1 * V_2 , int V_92 )
{
unsigned int V_93 = F_52 ( V_94 ) ;
struct V_95 * V_96 = & V_2 -> V_28 [ V_92 ] ;
unsigned int V_42 = F_53 ( V_96 ) ;
unsigned int V_97 = V_96 -> V_98 ;
unsigned char * V_99 = V_96 -> V_100 + V_93 ;
union V_91 * V_101 = NULL ;
if ( V_2 -> V_102 ) {
int V_103 = V_42 - V_97 ;
if ( V_103 > V_96 -> V_104 / 2 || V_103 < 0 ) {
fprintf ( V_105 , L_3 ) ;
V_97 = V_42 ;
}
}
if ( V_97 != V_42 ) {
T_1 V_106 ;
V_101 = (union V_91 * ) & V_99 [ V_97 & V_96 -> V_104 ] ;
V_106 = V_101 -> V_107 . V_106 ;
if ( ( V_97 & V_96 -> V_104 ) + V_106 != ( ( V_97 + V_106 ) & V_96 -> V_104 ) ) {
unsigned int V_108 = V_97 ;
unsigned int V_109 = F_54 ( sizeof( * V_101 ) , V_106 ) , V_110 ;
void * V_111 = & V_2 -> V_112 ;
do {
V_110 = F_54 ( V_96 -> V_104 + 1 - ( V_108 & V_96 -> V_104 ) , V_109 ) ;
memcpy ( V_111 , & V_99 [ V_108 & V_96 -> V_104 ] , V_110 ) ;
V_108 += V_110 ;
V_111 += V_110 ;
V_109 -= V_110 ;
} while ( V_109 );
V_101 = & V_2 -> V_112 ;
}
V_97 += V_106 ;
}
V_96 -> V_98 = V_97 ;
if ( ! V_2 -> V_102 )
F_55 ( V_96 , V_97 ) ;
return V_101 ;
}
void F_56 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_113 ; V_7 ++ ) {
if ( V_2 -> V_28 [ V_7 ] . V_100 != NULL ) {
F_57 ( V_2 -> V_28 [ V_7 ] . V_100 , V_2 -> V_114 ) ;
V_2 -> V_28 [ V_7 ] . V_100 = NULL ;
}
}
free ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
}
static int F_58 ( struct V_1 * V_2 )
{
V_2 -> V_113 = V_2 -> V_4 -> V_69 ;
if ( V_2 -> V_4 -> V_18 [ 0 ] == - 1 )
V_2 -> V_113 = V_2 -> V_6 -> V_69 ;
V_2 -> V_28 = F_6 ( V_2 -> V_113 * sizeof( struct V_95 ) ) ;
return V_2 -> V_28 != NULL ? 0 : - V_39 ;
}
static int F_59 ( struct V_1 * V_2 ,
int V_92 , int V_115 , int V_104 , int V_48 )
{
V_2 -> V_28 [ V_92 ] . V_98 = 0 ;
V_2 -> V_28 [ V_92 ] . V_104 = V_104 ;
V_2 -> V_28 [ V_92 ] . V_100 = V_28 ( NULL , V_2 -> V_114 , V_115 ,
V_116 , V_48 , 0 ) ;
if ( V_2 -> V_28 [ V_92 ] . V_100 == V_117 ) {
V_2 -> V_28 [ V_92 ] . V_100 = NULL ;
return - 1 ;
}
F_40 ( V_2 , V_48 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , int V_115 , int V_104 )
{
struct V_15 * V_16 ;
int V_67 , V_68 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_4 -> V_69 ; V_67 ++ ) {
int V_118 = - 1 ;
for ( V_68 = 0 ; V_68 < V_2 -> V_6 -> V_69 ; V_68 ++ ) {
F_9 (evsel, &evlist->entries, node) {
int V_48 = F_37 ( V_16 , V_67 , V_68 ) ;
if ( V_118 == - 1 ) {
V_118 = V_48 ;
if ( F_59 ( V_2 , V_67 ,
V_115 , V_104 , V_118 ) < 0 )
goto V_119;
} else {
if ( F_36 ( V_48 , V_120 , V_118 ) != 0 )
goto V_119;
}
if ( ( V_16 -> V_23 . V_85 & V_86 ) &&
F_47 ( V_2 , V_16 , V_67 , V_68 , V_48 ) < 0 )
goto V_119;
}
}
}
return 0 ;
V_119:
for ( V_67 = 0 ; V_67 < V_2 -> V_4 -> V_69 ; V_67 ++ ) {
if ( V_2 -> V_28 [ V_67 ] . V_100 != NULL ) {
F_57 ( V_2 -> V_28 [ V_67 ] . V_100 , V_2 -> V_114 ) ;
V_2 -> V_28 [ V_67 ] . V_100 = NULL ;
}
}
return - 1 ;
}
static int F_61 ( struct V_1 * V_2 , int V_115 , int V_104 )
{
struct V_15 * V_16 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_2 -> V_6 -> V_69 ; V_68 ++ ) {
int V_118 = - 1 ;
F_9 (evsel, &evlist->entries, node) {
int V_48 = F_37 ( V_16 , 0 , V_68 ) ;
if ( V_118 == - 1 ) {
V_118 = V_48 ;
if ( F_59 ( V_2 , V_68 ,
V_115 , V_104 , V_118 ) < 0 )
goto V_119;
} else {
if ( F_36 ( V_48 , V_120 , V_118 ) != 0 )
goto V_119;
}
if ( ( V_16 -> V_23 . V_85 & V_86 ) &&
F_47 ( V_2 , V_16 , 0 , V_68 , V_48 ) < 0 )
goto V_119;
}
}
return 0 ;
V_119:
for ( V_68 = 0 ; V_68 < V_2 -> V_6 -> V_69 ; V_68 ++ ) {
if ( V_2 -> V_28 [ V_68 ] . V_100 != NULL ) {
F_57 ( V_2 -> V_28 [ V_68 ] . V_100 , V_2 -> V_114 ) ;
V_2 -> V_28 [ V_68 ] . V_100 = NULL ;
}
}
return - 1 ;
}
int F_62 ( struct V_1 * V_2 , unsigned int V_121 ,
bool V_102 )
{
unsigned int V_93 = F_52 ( V_94 ) ;
struct V_15 * V_16 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
int V_115 = V_122 | ( V_102 ? 0 : V_123 ) , V_104 ;
if ( V_121 == V_124 )
V_121 = ( 512 * 1024 ) / V_93 ;
else if ( ! F_63 ( V_121 ) )
return - V_125 ;
V_104 = V_121 * V_93 - 1 ;
if ( V_2 -> V_28 == NULL && F_58 ( V_2 ) < 0 )
return - V_39 ;
if ( V_2 -> V_29 == NULL && F_39 ( V_2 ) < 0 )
return - V_39 ;
V_2 -> V_102 = V_102 ;
V_2 -> V_114 = ( V_121 + 1 ) * V_93 ;
F_9 (evsel, &evlist->entries, node) {
if ( ( V_16 -> V_23 . V_85 & V_86 ) &&
V_16 -> V_126 == NULL &&
F_64 ( V_16 , V_4 -> V_69 , V_6 -> V_69 ) < 0 )
return - V_39 ;
}
if ( V_2 -> V_4 -> V_18 [ 0 ] == - 1 )
return F_61 ( V_2 , V_115 , V_104 ) ;
return F_60 ( V_2 , V_115 , V_104 ) ;
}
int F_65 ( struct V_1 * V_2 , const char * V_127 ,
const char * V_128 , T_3 V_129 , const char * V_130 )
{
V_2 -> V_6 = F_66 ( V_127 , V_128 , V_129 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( V_129 != V_124 || ( V_130 == NULL && V_128 ) )
V_2 -> V_4 = F_67 () ;
else
V_2 -> V_4 = F_68 ( V_130 ) ;
if ( V_2 -> V_4 == NULL )
goto V_131;
return 0 ;
V_131:
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
char * V_132 ;
int V_68 ;
int V_67 ;
int V_47 ;
int V_48 ;
F_9 (evsel, &evlist->entries, node) {
V_132 = V_16 -> V_132 ;
if ( ! V_132 )
continue;
for ( V_67 = 0 ; V_67 < V_4 -> V_69 ; V_67 ++ ) {
for ( V_68 = 0 ; V_68 < V_6 -> V_69 ; V_68 ++ ) {
V_48 = F_37 ( V_16 , V_67 , V_68 ) ;
V_47 = F_36 ( V_48 , V_133 , V_132 ) ;
if ( V_47 )
return V_47 ;
}
}
}
return 0 ;
}
bool F_73 ( const struct V_1 * V_2 )
{
struct V_15 * V_26 , * V_17 ;
V_26 = V_17 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
F_74 (pos, &evlist->entries, node) {
if ( V_17 -> V_23 . V_24 != V_26 -> V_23 . V_24 )
return false ;
}
return true ;
}
T_2 F_75 ( const struct V_1 * V_2 )
{
struct V_15 * V_17 ;
V_17 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
return V_17 -> V_23 . V_24 ;
}
T_4 F_76 ( const struct V_1 * V_2 )
{
struct V_15 * V_17 ;
struct V_134 * V_99 ;
T_2 V_24 ;
T_4 V_106 = 0 ;
V_17 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
if ( ! V_17 -> V_23 . V_135 )
goto V_63;
V_24 = V_17 -> V_23 . V_24 ;
if ( V_24 & V_136 )
V_106 += sizeof( V_99 -> V_137 ) * 2 ;
if ( V_24 & V_57 )
V_106 += sizeof( V_99 -> time ) ;
if ( V_24 & V_25 )
V_106 += sizeof( V_99 -> V_51 ) ;
if ( V_24 & V_138 )
V_106 += sizeof( V_99 -> V_139 ) ;
if ( V_24 & V_58 )
V_106 += sizeof( V_99 -> V_67 ) * 2 ;
V_63:
return V_106 ;
}
bool F_77 ( const struct V_1 * V_2 )
{
struct V_15 * V_26 , * V_17 ;
V_26 = V_17 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
F_74 (pos, &evlist->entries, node) {
if ( V_17 -> V_23 . V_135 != V_26 -> V_23 . V_135 )
return false ;
}
return true ;
}
bool F_50 ( const struct V_1 * V_2 )
{
struct V_15 * V_17 ;
V_17 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
return V_17 -> V_23 . V_135 ;
}
void F_78 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
V_2 -> V_140 = V_16 ;
}
int F_79 ( struct V_1 * V_2 , bool V_141 )
{
struct V_15 * V_16 , * V_17 ;
int V_47 , V_142 , V_143 ;
V_17 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
F_9 (evsel, &evlist->entries, node) {
struct V_144 * V_145 = NULL ;
if ( V_141 && V_16 != V_17 )
V_145 = V_17 -> V_48 ;
V_47 = F_80 ( V_16 , V_2 -> V_4 , V_2 -> V_6 ,
V_141 , V_145 ) ;
if ( V_47 < 0 )
goto V_146;
}
return 0 ;
V_146:
V_142 = V_2 -> V_4 ? V_2 -> V_4 -> V_69 : 1 ;
V_143 = V_2 -> V_6 ? V_2 -> V_6 -> V_69 : 1 ;
F_81 (evsel, &evlist->entries, node)
F_82 ( V_16 , V_142 , V_143 ) ;
V_147 = - V_47 ;
return V_47 ;
}
int F_83 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
const char * V_148 [] )
{
int V_149 [ 2 ] , V_150 [ 2 ] ;
char V_151 ;
if ( F_84 ( V_149 ) < 0 ) {
perror ( L_4 ) ;
return - 1 ;
}
if ( F_84 ( V_150 ) < 0 ) {
perror ( L_5 ) ;
goto V_152;
}
V_2 -> V_11 . V_12 = F_85 () ;
if ( V_2 -> V_11 . V_12 < 0 ) {
perror ( L_6 ) ;
goto V_153;
}
if ( ! V_2 -> V_11 . V_12 ) {
if ( V_14 -> V_154 )
F_86 ( 2 , 1 ) ;
F_31 ( V_149 [ 0 ] ) ;
F_31 ( V_150 [ 1 ] ) ;
F_41 ( V_150 [ 0 ] , V_155 , V_156 ) ;
F_87 ( L_7 , ( char * * ) V_148 ) ;
F_31 ( V_149 [ 1 ] ) ;
if ( F_30 ( V_150 [ 0 ] , & V_151 , 1 ) == - 1 )
perror ( L_8 ) ;
F_87 ( V_148 [ 0 ] , ( char * * ) V_148 ) ;
perror ( V_148 [ 0 ] ) ;
F_88 ( F_89 () , V_157 ) ;
exit ( - 1 ) ;
}
if ( ! V_14 -> V_158 && ! V_14 -> V_128 && ! V_14 -> V_127 )
V_2 -> V_6 -> V_18 [ 0 ] = V_2 -> V_11 . V_12 ;
F_31 ( V_149 [ 1 ] ) ;
F_31 ( V_150 [ 0 ] ) ;
if ( F_30 ( V_149 [ 0 ] , & V_151 , 1 ) == - 1 ) {
perror ( L_8 ) ;
goto V_153;
}
V_2 -> V_11 . V_159 = V_150 [ 1 ] ;
F_31 ( V_149 [ 0 ] ) ;
return 0 ;
V_153:
F_31 ( V_150 [ 0 ] ) ;
F_31 ( V_150 [ 1 ] ) ;
V_152:
F_31 ( V_149 [ 0 ] ) ;
F_31 ( V_149 [ 1 ] ) ;
return - 1 ;
}
int F_90 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_159 > 0 ) {
return F_31 ( V_2 -> V_11 . V_159 ) ;
}
return 0 ;
}
