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
int F_27 ( struct V_1 * V_2 ,
struct V_33 * V_40 , T_1 V_41 )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_41 ; V_7 ++ )
F_22 ( V_40 + V_7 ) ;
return F_25 ( V_2 , V_40 , V_41 ) ;
}
static int F_28 ( const char * V_44 )
{
char * V_45 , * V_46 ;
int V_47 = - 1 , V_48 ;
if ( F_29 ( & V_45 , L_2 , V_49 , V_44 ) < 0 )
return - 1 ;
V_46 = strrchr ( V_45 , ':' ) ;
if ( V_46 != NULL )
* V_46 = '/' ;
V_48 = F_30 ( V_45 , V_50 ) ;
if ( V_48 >= 0 ) {
char V_51 [ 16 ] ;
if ( F_31 ( V_48 , V_51 , sizeof( V_51 ) ) > 0 )
V_47 = atoi ( V_51 ) ;
F_32 ( V_48 ) ;
}
free ( V_45 ) ;
return V_47 ;
}
int F_33 ( struct V_1 * V_2 ,
const char * V_52 [] ,
T_1 V_53 )
{
int V_47 ;
T_1 V_7 ;
struct V_33 * V_40 = F_6 ( V_53 * sizeof( * V_40 ) ) ;
if ( V_40 == NULL )
return - 1 ;
for ( V_7 = 0 ; V_7 < V_53 ; V_7 ++ ) {
V_47 = F_28 ( V_52 [ V_7 ] ) ;
if ( V_47 < 0 )
goto V_54;
V_40 [ V_7 ] . type = V_55 ;
V_40 [ V_7 ] . V_35 = V_47 ;
V_40 [ V_7 ] . V_24 = ( V_56 | V_57 |
V_58 | V_59 ) ;
V_40 [ V_7 ] . V_60 = 1 ;
}
V_47 = F_25 ( V_2 , V_40 , V_53 ) ;
V_54:
free ( V_40 ) ;
return V_47 ;
}
struct V_15 *
F_34 ( struct V_1 * V_2 , int V_51 )
{
struct V_15 * V_16 ;
F_9 (evsel, &evlist->entries, node) {
if ( V_16 -> V_23 . type == V_55 &&
( int ) V_16 -> V_23 . V_35 == V_51 )
return V_16 ;
}
return NULL ;
}
int F_35 ( struct V_1 * V_2 ,
const struct V_61 * V_62 ,
T_1 V_63 )
{
struct V_15 * V_16 ;
int V_47 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_63 ; V_7 ++ ) {
V_47 = F_28 ( V_62 [ V_7 ] . V_37 ) ;
if ( V_47 < 0 )
goto V_64;
V_16 = F_34 ( V_2 , V_47 ) ;
if ( V_16 == NULL )
continue;
V_47 = - V_65 ;
if ( V_16 -> V_66 . V_67 != NULL )
goto V_64;
V_16 -> V_66 . V_67 = V_62 [ V_7 ] . V_66 ;
}
V_47 = 0 ;
V_64:
return V_47 ;
}
void F_36 ( struct V_1 * V_2 )
{
int V_68 , V_69 ;
struct V_15 * V_26 ;
for ( V_68 = 0 ; V_68 < V_2 -> V_4 -> V_70 ; V_68 ++ ) {
F_9 (pos, &evlist->entries, node) {
for ( V_69 = 0 ; V_69 < V_2 -> V_6 -> V_70 ; V_69 ++ )
F_37 ( F_38 ( V_26 , V_68 , V_69 ) ,
V_71 , 0 ) ;
}
}
}
void F_39 ( struct V_1 * V_2 )
{
int V_68 , V_69 ;
struct V_15 * V_26 ;
for ( V_68 = 0 ; V_68 < V_2 -> V_4 -> V_70 ; V_68 ++ ) {
F_9 (pos, &evlist->entries, node) {
for ( V_69 = 0 ; V_69 < V_2 -> V_6 -> V_70 ; V_69 ++ )
F_37 ( F_38 ( V_26 , V_68 , V_69 ) ,
V_72 , 0 ) ;
}
}
}
static int F_40 ( struct V_1 * V_2 )
{
int V_73 = V_2 -> V_4 -> V_70 * V_2 -> V_6 -> V_70 * V_2 -> V_22 ;
V_2 -> V_29 = malloc ( sizeof( struct V_29 ) * V_73 ) ;
return V_2 -> V_29 != NULL ? 0 : - V_39 ;
}
void F_41 ( struct V_1 * V_2 , int V_48 )
{
F_42 ( V_48 , V_74 , V_75 ) ;
V_2 -> V_29 [ V_2 -> V_76 ] . V_48 = V_48 ;
V_2 -> V_29 [ V_2 -> V_76 ] . V_77 = V_78 ;
V_2 -> V_76 ++ ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_68 , int V_69 , T_2 V_51 )
{
int V_79 ;
struct V_80 * V_81 = F_44 ( V_16 , V_68 , V_69 ) ;
V_81 -> V_51 = V_51 ;
V_81 -> V_16 = V_16 ;
V_79 = F_45 ( V_81 -> V_51 , V_82 ) ;
F_46 ( & V_81 -> V_21 , & V_2 -> V_9 [ V_79 ] ) ;
}
void F_47 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_68 , int V_69 , T_2 V_51 )
{
F_43 ( V_2 , V_16 , V_68 , V_69 , V_51 ) ;
V_16 -> V_51 [ V_16 -> V_83 ++ ] = V_51 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_68 , int V_69 , int V_48 )
{
T_2 V_84 [ 4 ] = { 0 , } ;
int V_85 = 1 ;
if ( ! ( V_16 -> V_23 . V_86 & V_87 ) ||
F_31 ( V_48 , & V_84 , sizeof( V_84 ) ) == - 1 )
return - 1 ;
if ( V_16 -> V_23 . V_86 & V_88 )
++ V_85 ;
if ( V_16 -> V_23 . V_86 & V_89 )
++ V_85 ;
F_47 ( V_2 , V_16 , V_68 , V_69 , V_84 [ V_85 ] ) ;
return 0 ;
}
struct V_15 * F_49 ( struct V_1 * V_2 , T_2 V_51 )
{
struct V_90 * V_42 ;
struct V_91 * V_26 ;
struct V_80 * V_81 ;
int V_79 ;
if ( V_2 -> V_22 == 1 )
return F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
V_79 = F_45 ( V_51 , V_82 ) ;
V_42 = & V_2 -> V_9 [ V_79 ] ;
F_50 (sid, pos, head, node)
if ( V_81 -> V_51 == V_51 )
return V_81 -> V_16 ;
if ( ! F_51 ( V_2 ) )
return F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
return NULL ;
}
union V_92 * F_52 ( struct V_1 * V_2 , int V_93 )
{
unsigned int V_94 = F_53 ( V_95 ) ;
struct V_96 * V_97 = & V_2 -> V_28 [ V_93 ] ;
unsigned int V_42 = F_54 ( V_97 ) ;
unsigned int V_98 = V_97 -> V_99 ;
unsigned char * V_100 = V_97 -> V_101 + V_94 ;
union V_92 * V_102 = NULL ;
if ( V_2 -> V_103 ) {
int V_104 = V_42 - V_98 ;
if ( V_104 > V_97 -> V_105 / 2 || V_104 < 0 ) {
fprintf ( V_106 , L_3 ) ;
V_98 = V_42 ;
}
}
if ( V_98 != V_42 ) {
T_1 V_107 ;
V_102 = (union V_92 * ) & V_100 [ V_98 & V_97 -> V_105 ] ;
V_107 = V_102 -> V_108 . V_107 ;
if ( ( V_98 & V_97 -> V_105 ) + V_107 != ( ( V_98 + V_107 ) & V_97 -> V_105 ) ) {
unsigned int V_109 = V_98 ;
unsigned int V_110 = F_55 ( sizeof( * V_102 ) , V_107 ) , V_111 ;
void * V_112 = & V_2 -> V_113 ;
do {
V_111 = F_55 ( V_97 -> V_105 + 1 - ( V_109 & V_97 -> V_105 ) , V_110 ) ;
memcpy ( V_112 , & V_100 [ V_109 & V_97 -> V_105 ] , V_111 ) ;
V_109 += V_111 ;
V_112 += V_111 ;
V_110 -= V_111 ;
} while ( V_110 );
V_102 = & V_2 -> V_113 ;
}
V_98 += V_107 ;
}
V_97 -> V_99 = V_98 ;
if ( ! V_2 -> V_103 )
F_56 ( V_97 , V_98 ) ;
return V_102 ;
}
void F_57 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_114 ; V_7 ++ ) {
if ( V_2 -> V_28 [ V_7 ] . V_101 != NULL ) {
F_58 ( V_2 -> V_28 [ V_7 ] . V_101 , V_2 -> V_115 ) ;
V_2 -> V_28 [ V_7 ] . V_101 = NULL ;
}
}
free ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
}
static int F_59 ( struct V_1 * V_2 )
{
V_2 -> V_114 = V_2 -> V_4 -> V_70 ;
if ( V_2 -> V_4 -> V_18 [ 0 ] == - 1 )
V_2 -> V_114 = V_2 -> V_6 -> V_70 ;
V_2 -> V_28 = F_6 ( V_2 -> V_114 * sizeof( struct V_96 ) ) ;
return V_2 -> V_28 != NULL ? 0 : - V_39 ;
}
static int F_60 ( struct V_1 * V_2 ,
int V_93 , int V_116 , int V_105 , int V_48 )
{
V_2 -> V_28 [ V_93 ] . V_99 = 0 ;
V_2 -> V_28 [ V_93 ] . V_105 = V_105 ;
V_2 -> V_28 [ V_93 ] . V_101 = V_28 ( NULL , V_2 -> V_115 , V_116 ,
V_117 , V_48 , 0 ) ;
if ( V_2 -> V_28 [ V_93 ] . V_101 == V_118 ) {
V_2 -> V_28 [ V_93 ] . V_101 = NULL ;
return - 1 ;
}
F_41 ( V_2 , V_48 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , int V_116 , int V_105 )
{
struct V_15 * V_16 ;
int V_68 , V_69 ;
for ( V_68 = 0 ; V_68 < V_2 -> V_4 -> V_70 ; V_68 ++ ) {
int V_119 = - 1 ;
for ( V_69 = 0 ; V_69 < V_2 -> V_6 -> V_70 ; V_69 ++ ) {
F_9 (evsel, &evlist->entries, node) {
int V_48 = F_38 ( V_16 , V_68 , V_69 ) ;
if ( V_119 == - 1 ) {
V_119 = V_48 ;
if ( F_60 ( V_2 , V_68 ,
V_116 , V_105 , V_119 ) < 0 )
goto V_120;
} else {
if ( F_37 ( V_48 , V_121 , V_119 ) != 0 )
goto V_120;
}
if ( ( V_16 -> V_23 . V_86 & V_87 ) &&
F_48 ( V_2 , V_16 , V_68 , V_69 , V_48 ) < 0 )
goto V_120;
}
}
}
return 0 ;
V_120:
for ( V_68 = 0 ; V_68 < V_2 -> V_4 -> V_70 ; V_68 ++ ) {
if ( V_2 -> V_28 [ V_68 ] . V_101 != NULL ) {
F_58 ( V_2 -> V_28 [ V_68 ] . V_101 , V_2 -> V_115 ) ;
V_2 -> V_28 [ V_68 ] . V_101 = NULL ;
}
}
return - 1 ;
}
static int F_62 ( struct V_1 * V_2 , int V_116 , int V_105 )
{
struct V_15 * V_16 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_2 -> V_6 -> V_70 ; V_69 ++ ) {
int V_119 = - 1 ;
F_9 (evsel, &evlist->entries, node) {
int V_48 = F_38 ( V_16 , 0 , V_69 ) ;
if ( V_119 == - 1 ) {
V_119 = V_48 ;
if ( F_60 ( V_2 , V_69 ,
V_116 , V_105 , V_119 ) < 0 )
goto V_120;
} else {
if ( F_37 ( V_48 , V_121 , V_119 ) != 0 )
goto V_120;
}
if ( ( V_16 -> V_23 . V_86 & V_87 ) &&
F_48 ( V_2 , V_16 , 0 , V_69 , V_48 ) < 0 )
goto V_120;
}
}
return 0 ;
V_120:
for ( V_69 = 0 ; V_69 < V_2 -> V_6 -> V_70 ; V_69 ++ ) {
if ( V_2 -> V_28 [ V_69 ] . V_101 != NULL ) {
F_58 ( V_2 -> V_28 [ V_69 ] . V_101 , V_2 -> V_115 ) ;
V_2 -> V_28 [ V_69 ] . V_101 = NULL ;
}
}
return - 1 ;
}
int F_63 ( struct V_1 * V_2 , unsigned int V_122 ,
bool V_103 )
{
unsigned int V_94 = F_53 ( V_95 ) ;
struct V_15 * V_16 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
int V_116 = V_123 | ( V_103 ? 0 : V_124 ) , V_105 ;
if ( V_122 == V_125 )
V_122 = ( 512 * 1024 ) / V_94 ;
else if ( ! F_64 ( V_122 ) )
return - V_126 ;
V_105 = V_122 * V_94 - 1 ;
if ( V_2 -> V_28 == NULL && F_59 ( V_2 ) < 0 )
return - V_39 ;
if ( V_2 -> V_29 == NULL && F_40 ( V_2 ) < 0 )
return - V_39 ;
V_2 -> V_103 = V_103 ;
V_2 -> V_115 = ( V_122 + 1 ) * V_94 ;
F_9 (evsel, &evlist->entries, node) {
if ( ( V_16 -> V_23 . V_86 & V_87 ) &&
V_16 -> V_127 == NULL &&
F_65 ( V_16 , V_4 -> V_70 , V_6 -> V_70 ) < 0 )
return - V_39 ;
}
if ( V_2 -> V_4 -> V_18 [ 0 ] == - 1 )
return F_62 ( V_2 , V_116 , V_105 ) ;
return F_61 ( V_2 , V_116 , V_105 ) ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_128 * V_129 )
{
V_2 -> V_6 = F_67 ( V_129 -> V_12 , V_129 -> V_130 ,
V_129 -> V_131 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( F_68 ( V_129 ) )
V_2 -> V_4 = F_69 () ;
else if ( ! F_70 ( V_129 ) && ! V_129 -> V_132 )
V_2 -> V_4 = F_69 () ;
else
V_2 -> V_4 = F_71 ( V_129 -> V_133 ) ;
if ( V_2 -> V_4 == NULL )
goto V_134;
return 0 ;
V_134:
F_72 ( V_2 -> V_6 ) ;
return - 1 ;
}
void F_73 ( struct V_1 * V_2 )
{
F_74 ( V_2 -> V_4 ) ;
F_72 ( V_2 -> V_6 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_6 = NULL ;
}
int F_75 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_2 -> V_6 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 ;
char * V_135 ;
int V_69 ;
int V_68 ;
int V_47 ;
int V_48 ;
F_9 (evsel, &evlist->entries, node) {
V_135 = V_16 -> V_135 ;
if ( ! V_135 )
continue;
for ( V_68 = 0 ; V_68 < V_4 -> V_70 ; V_68 ++ ) {
for ( V_69 = 0 ; V_69 < V_6 -> V_70 ; V_69 ++ ) {
V_48 = F_38 ( V_16 , V_68 , V_69 ) ;
V_47 = F_37 ( V_48 , V_136 , V_135 ) ;
if ( V_47 )
return V_47 ;
}
}
}
return 0 ;
}
bool F_76 ( const struct V_1 * V_2 )
{
struct V_15 * V_26 , * V_17 ;
V_26 = V_17 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
F_77 (pos, &evlist->entries, node) {
if ( V_17 -> V_23 . V_24 != V_26 -> V_23 . V_24 )
return false ;
}
return true ;
}
T_2 F_78 ( const struct V_1 * V_2 )
{
struct V_15 * V_17 ;
V_17 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
return V_17 -> V_23 . V_24 ;
}
T_3 F_79 ( const struct V_1 * V_2 )
{
struct V_15 * V_17 ;
struct V_137 * V_100 ;
T_2 V_24 ;
T_3 V_107 = 0 ;
V_17 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
if ( ! V_17 -> V_23 . V_138 )
goto V_64;
V_24 = V_17 -> V_23 . V_24 ;
if ( V_24 & V_139 )
V_107 += sizeof( V_100 -> V_130 ) * 2 ;
if ( V_24 & V_57 )
V_107 += sizeof( V_100 -> time ) ;
if ( V_24 & V_25 )
V_107 += sizeof( V_100 -> V_51 ) ;
if ( V_24 & V_140 )
V_107 += sizeof( V_100 -> V_141 ) ;
if ( V_24 & V_58 )
V_107 += sizeof( V_100 -> V_68 ) * 2 ;
V_64:
return V_107 ;
}
bool F_80 ( const struct V_1 * V_2 )
{
struct V_15 * V_26 , * V_17 ;
V_26 = V_17 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
F_77 (pos, &evlist->entries, node) {
if ( V_17 -> V_23 . V_138 != V_26 -> V_23 . V_138 )
return false ;
}
return true ;
}
bool F_51 ( const struct V_1 * V_2 )
{
struct V_15 * V_17 ;
V_17 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
return V_17 -> V_23 . V_138 ;
}
void F_81 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
V_2 -> V_142 = V_16 ;
}
int F_82 ( struct V_1 * V_2 , bool V_143 )
{
struct V_15 * V_16 , * V_17 ;
int V_47 , V_144 , V_145 ;
V_17 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
F_9 (evsel, &evlist->entries, node) {
struct V_146 * V_147 = NULL ;
if ( V_143 && V_16 != V_17 )
V_147 = V_17 -> V_48 ;
V_47 = F_83 ( V_16 , V_2 -> V_4 , V_2 -> V_6 ,
V_143 , V_147 ) ;
if ( V_47 < 0 )
goto V_148;
}
return 0 ;
V_148:
V_144 = V_2 -> V_4 ? V_2 -> V_4 -> V_70 : 1 ;
V_145 = V_2 -> V_6 ? V_2 -> V_6 -> V_70 : 1 ;
F_84 (evsel, &evlist->entries, node)
F_85 ( V_16 , V_144 , V_145 ) ;
V_149 = - V_47 ;
return V_47 ;
}
int F_86 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
const char * V_150 [] )
{
int V_151 [ 2 ] , V_152 [ 2 ] ;
char V_153 ;
if ( F_87 ( V_151 ) < 0 ) {
perror ( L_4 ) ;
return - 1 ;
}
if ( F_87 ( V_152 ) < 0 ) {
perror ( L_5 ) ;
goto V_154;
}
V_2 -> V_11 . V_12 = F_88 () ;
if ( V_2 -> V_11 . V_12 < 0 ) {
perror ( L_6 ) ;
goto V_155;
}
if ( ! V_2 -> V_11 . V_12 ) {
if ( V_14 -> V_156 )
F_89 ( 2 , 1 ) ;
F_32 ( V_151 [ 0 ] ) ;
F_32 ( V_152 [ 1 ] ) ;
F_42 ( V_152 [ 0 ] , V_157 , V_158 ) ;
F_90 ( L_7 , ( char * * ) V_150 ) ;
F_32 ( V_151 [ 1 ] ) ;
if ( F_31 ( V_152 [ 0 ] , & V_153 , 1 ) == - 1 )
perror ( L_8 ) ;
F_90 ( V_150 [ 0 ] , ( char * * ) V_150 ) ;
perror ( V_150 [ 0 ] ) ;
F_91 ( F_92 () , V_159 ) ;
exit ( - 1 ) ;
}
if ( F_93 ( & V_14 -> V_129 ) )
V_2 -> V_6 -> V_18 [ 0 ] = V_2 -> V_11 . V_12 ;
F_32 ( V_151 [ 1 ] ) ;
F_32 ( V_152 [ 0 ] ) ;
if ( F_31 ( V_151 [ 0 ] , & V_153 , 1 ) == - 1 ) {
perror ( L_8 ) ;
goto V_155;
}
V_2 -> V_11 . V_160 = V_152 [ 1 ] ;
F_32 ( V_151 [ 0 ] ) ;
return 0 ;
V_155:
F_32 ( V_152 [ 0 ] ) ;
F_32 ( V_152 [ 1 ] ) ;
V_154:
F_32 ( V_151 [ 0 ] ) ;
F_32 ( V_151 [ 1 ] ) ;
return - 1 ;
}
int F_94 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_160 > 0 ) {
return F_32 ( V_2 -> V_11 . V_160 ) ;
}
return 0 ;
}
int F_95 ( struct V_1 * V_2 , union V_92 * V_102 ,
struct V_137 * V_161 , bool V_162 )
{
struct V_15 * V_163 = F_8 ( V_2 -> V_10 . V_20 , struct V_15 , V_21 ) ;
return F_96 ( V_163 , V_102 , V_161 , V_162 ) ;
}
