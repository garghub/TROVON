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
for ( V_52 = 0 ; V_52 < V_2 -> V_4 -> V_54 ; V_52 ++ ) {
F_9 (pos, &evlist->entries, node) {
if ( ! F_35 ( V_21 ) )
continue;
for ( V_53 = 0 ; V_53 < V_2 -> V_6 -> V_54 ; V_53 ++ )
F_36 ( F_37 ( V_21 , V_52 , V_53 ) ,
V_55 , 0 ) ;
}
}
}
void F_38 ( struct V_1 * V_2 )
{
int V_52 , V_53 ;
struct V_15 * V_21 ;
for ( V_52 = 0 ; V_52 < F_39 ( V_2 -> V_4 ) ; V_52 ++ ) {
F_9 (pos, &evlist->entries, node) {
if ( ! F_35 ( V_21 ) )
continue;
for ( V_53 = 0 ; V_53 < V_2 -> V_6 -> V_54 ; V_53 ++ )
F_36 ( F_37 ( V_21 , V_52 , V_53 ) ,
V_56 , 0 ) ;
}
}
}
static int F_40 ( struct V_1 * V_2 )
{
int V_57 = F_39 ( V_2 -> V_4 ) * V_2 -> V_6 -> V_54 * V_2 -> V_20 ;
V_2 -> V_25 = malloc ( sizeof( struct V_25 ) * V_57 ) ;
return V_2 -> V_25 != NULL ? 0 : - V_42 ;
}
void F_41 ( struct V_1 * V_2 , int V_58 )
{
F_42 ( V_58 , V_59 , V_60 ) ;
V_2 -> V_25 [ V_2 -> V_61 ] . V_58 = V_58 ;
V_2 -> V_25 [ V_2 -> V_61 ] . V_62 = V_63 ;
V_2 -> V_61 ++ ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_52 , int V_53 , T_2 V_47 )
{
int V_64 ;
struct V_65 * V_66 = F_44 ( V_16 , V_52 , V_53 ) ;
V_66 -> V_47 = V_47 ;
V_66 -> V_16 = V_16 ;
V_64 = F_45 ( V_66 -> V_47 , V_67 ) ;
F_46 ( & V_66 -> V_23 , & V_2 -> V_9 [ V_64 ] ) ;
}
void F_47 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_52 , int V_53 , T_2 V_47 )
{
F_43 ( V_2 , V_16 , V_52 , V_53 , V_47 ) ;
V_16 -> V_47 [ V_16 -> V_68 ++ ] = V_47 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_52 , int V_53 , int V_58 )
{
T_2 V_69 [ 4 ] = { 0 , } ;
int V_70 = 1 ;
if ( ! ( V_16 -> V_36 . V_71 & V_72 ) ||
F_49 ( V_58 , & V_69 , sizeof( V_69 ) ) == - 1 )
return - 1 ;
if ( V_16 -> V_36 . V_71 & V_73 )
++ V_70 ;
if ( V_16 -> V_36 . V_71 & V_74 )
++ V_70 ;
F_47 ( V_2 , V_16 , V_52 , V_53 , V_69 [ V_70 ] ) ;
return 0 ;
}
struct V_15 * F_50 ( struct V_1 * V_2 , T_2 V_47 )
{
struct V_75 * V_45 ;
struct V_65 * V_66 ;
int V_64 ;
if ( V_2 -> V_20 == 1 )
return F_51 ( V_2 ) ;
V_64 = F_45 ( V_47 , V_67 ) ;
V_45 = & V_2 -> V_9 [ V_64 ] ;
F_52 (sid, head, node)
if ( V_66 -> V_47 == V_47 )
return V_66 -> V_16 ;
if ( ! F_53 ( V_2 ) )
return F_51 ( V_2 ) ;
return NULL ;
}
union V_76 * F_54 ( struct V_1 * V_2 , int V_33 )
{
struct V_77 * V_78 = & V_2 -> V_24 [ V_33 ] ;
unsigned int V_45 = F_55 ( V_78 ) ;
unsigned int V_79 = V_78 -> V_31 ;
unsigned char * V_80 = V_78 -> V_81 + V_82 ;
union V_76 * V_83 = NULL ;
if ( V_2 -> V_84 ) {
int V_85 = V_45 - V_79 ;
if ( V_85 > V_78 -> V_86 / 2 || V_85 < 0 ) {
fprintf ( V_87 , L_2 ) ;
V_79 = V_45 ;
}
}
if ( V_79 != V_45 ) {
T_1 V_88 ;
V_83 = (union V_76 * ) & V_80 [ V_79 & V_78 -> V_86 ] ;
V_88 = V_83 -> V_89 . V_88 ;
if ( ( V_79 & V_78 -> V_86 ) + V_88 != ( ( V_79 + V_88 ) & V_78 -> V_86 ) ) {
unsigned int V_90 = V_79 ;
unsigned int V_91 = F_56 ( sizeof( * V_83 ) , V_88 ) , V_92 ;
void * V_93 = & V_78 -> V_94 ;
do {
V_92 = F_56 ( V_78 -> V_86 + 1 - ( V_90 & V_78 -> V_86 ) , V_91 ) ;
memcpy ( V_93 , & V_80 [ V_90 & V_78 -> V_86 ] , V_92 ) ;
V_90 += V_92 ;
V_93 += V_92 ;
V_91 -= V_92 ;
} while ( V_91 );
V_83 = & V_78 -> V_94 ;
}
V_79 += V_88 ;
}
V_78 -> V_31 = V_79 ;
if ( ! V_2 -> V_84 )
F_57 ( V_78 , V_79 ) ;
return V_83 ;
}
void F_58 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_95 ; V_7 ++ ) {
if ( V_2 -> V_24 [ V_7 ] . V_81 != NULL ) {
F_59 ( V_2 -> V_24 [ V_7 ] . V_81 , V_2 -> V_96 ) ;
V_2 -> V_24 [ V_7 ] . V_81 = NULL ;
}
}
free ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
}
static int F_60 ( struct V_1 * V_2 )
{
V_2 -> V_95 = F_39 ( V_2 -> V_4 ) ;
if ( F_61 ( V_2 -> V_4 ) )
V_2 -> V_95 = V_2 -> V_6 -> V_54 ;
V_2 -> V_24 = F_6 ( V_2 -> V_95 * sizeof( struct V_77 ) ) ;
return V_2 -> V_24 != NULL ? 0 : - V_42 ;
}
static int F_62 ( struct V_1 * V_2 ,
int V_33 , int V_97 , int V_86 , int V_58 )
{
V_2 -> V_24 [ V_33 ] . V_31 = 0 ;
V_2 -> V_24 [ V_33 ] . V_86 = V_86 ;
V_2 -> V_24 [ V_33 ] . V_81 = V_24 ( NULL , V_2 -> V_96 , V_97 ,
V_98 , V_58 , 0 ) ;
if ( V_2 -> V_24 [ V_33 ] . V_81 == V_99 ) {
V_2 -> V_24 [ V_33 ] . V_81 = NULL ;
return - 1 ;
}
F_41 ( V_2 , V_58 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , int V_97 , int V_86 )
{
struct V_15 * V_16 ;
int V_52 , V_53 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_4 -> V_54 ; V_52 ++ ) {
int V_100 = - 1 ;
for ( V_53 = 0 ; V_53 < V_2 -> V_6 -> V_54 ; V_53 ++ ) {
F_9 (evsel, &evlist->entries, node) {
int V_58 = F_37 ( V_16 , V_52 , V_53 ) ;
if ( V_100 == - 1 ) {
V_100 = V_58 ;
if ( F_62 ( V_2 , V_52 ,
V_97 , V_86 , V_100 ) < 0 )
goto V_101;
} else {
if ( F_36 ( V_58 , V_102 , V_100 ) != 0 )
goto V_101;
}
if ( ( V_16 -> V_36 . V_71 & V_72 ) &&
F_48 ( V_2 , V_16 , V_52 , V_53 , V_58 ) < 0 )
goto V_101;
}
}
}
return 0 ;
V_101:
for ( V_52 = 0 ; V_52 < V_2 -> V_4 -> V_54 ; V_52 ++ ) {
if ( V_2 -> V_24 [ V_52 ] . V_81 != NULL ) {
F_59 ( V_2 -> V_24 [ V_52 ] . V_81 , V_2 -> V_96 ) ;
V_2 -> V_24 [ V_52 ] . V_81 = NULL ;
}
}
return - 1 ;
}
static int F_64 ( struct V_1 * V_2 , int V_97 , int V_86 )
{
struct V_15 * V_16 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_2 -> V_6 -> V_54 ; V_53 ++ ) {
int V_100 = - 1 ;
F_9 (evsel, &evlist->entries, node) {
int V_58 = F_37 ( V_16 , 0 , V_53 ) ;
if ( V_100 == - 1 ) {
V_100 = V_58 ;
if ( F_62 ( V_2 , V_53 ,
V_97 , V_86 , V_100 ) < 0 )
goto V_101;
} else {
if ( F_36 ( V_58 , V_102 , V_100 ) != 0 )
goto V_101;
}
if ( ( V_16 -> V_36 . V_71 & V_72 ) &&
F_48 ( V_2 , V_16 , 0 , V_53 , V_58 ) < 0 )
goto V_101;
}
}
return 0 ;
V_101:
for ( V_53 = 0 ; V_53 < V_2 -> V_6 -> V_54 ; V_53 ++ ) {
if ( V_2 -> V_24 [ V_53 ] . V_81 != NULL ) {
F_59 ( V_2 -> V_24 [ V_53 ] . V_81 , V_2 -> V_96 ) ;
V_2 -> V_24 [ V_53 ] . V_81 = NULL ;
}
}
return - 1 ;
}
int F_65 ( struct V_1 * V_2 , unsigned int V_103 ,
bool V_84 )
{
struct V_15 * V_16 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
int V_97 = V_104 | ( V_84 ? 0 : V_105 ) , V_86 ;
if ( V_103 == V_106 )
V_103 = ( 512 * 1024 ) / V_82 ;
else if ( ! F_66 ( V_103 ) )
return - V_107 ;
V_86 = V_103 * V_82 - 1 ;
if ( V_2 -> V_24 == NULL && F_60 ( V_2 ) < 0 )
return - V_42 ;
if ( V_2 -> V_25 == NULL && F_40 ( V_2 ) < 0 )
return - V_42 ;
V_2 -> V_84 = V_84 ;
V_2 -> V_96 = ( V_103 + 1 ) * V_82 ;
F_9 (evsel, &evlist->entries, node) {
if ( ( V_16 -> V_36 . V_71 & V_72 ) &&
V_16 -> V_108 == NULL &&
F_67 ( V_16 , F_39 ( V_4 ) , V_6 -> V_54 ) < 0 )
return - V_42 ;
}
if ( F_61 ( V_4 ) )
return F_64 ( V_2 , V_97 , V_86 ) ;
return F_63 ( V_2 , V_97 , V_86 ) ;
}
int F_68 ( struct V_1 * V_2 ,
struct V_109 * V_110 )
{
V_2 -> V_6 = F_69 ( V_110 -> V_12 , V_110 -> V_111 ,
V_110 -> V_112 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( F_70 ( V_110 ) )
V_2 -> V_4 = F_71 () ;
else if ( ! F_72 ( V_110 ) && ! V_110 -> V_113 )
V_2 -> V_4 = F_71 () ;
else
V_2 -> V_4 = F_73 ( V_110 -> V_114 ) ;
if ( V_2 -> V_4 == NULL )
goto V_115;
return 0 ;
V_115:
F_74 ( V_2 -> V_6 ) ;
return - 1 ;
}
void F_75 ( struct V_1 * V_2 )
{
F_76 ( V_2 -> V_4 ) ;
F_74 ( V_2 -> V_6 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_6 = NULL ;
}
int F_77 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_116 = 0 ;
const int V_117 = F_39 ( V_2 -> V_4 ) ,
V_118 = V_2 -> V_6 -> V_54 ;
F_9 (evsel, &evlist->entries, node) {
if ( V_16 -> V_119 == NULL )
continue;
V_116 = F_78 ( V_16 , V_117 , V_118 , V_16 -> V_119 ) ;
if ( V_116 )
break;
}
return V_116 ;
}
int F_79 ( struct V_1 * V_2 , const char * V_119 )
{
struct V_15 * V_16 ;
int V_116 = 0 ;
const int V_117 = F_39 ( V_2 -> V_4 ) ,
V_118 = V_2 -> V_6 -> V_54 ;
F_9 (evsel, &evlist->entries, node) {
V_116 = F_78 ( V_16 , V_117 , V_118 , V_119 ) ;
if ( V_116 )
break;
}
return V_116 ;
}
bool F_80 ( struct V_1 * V_2 )
{
struct V_15 * V_120 = F_51 ( V_2 ) , * V_21 = V_120 ;
F_81 (pos, &evlist->entries, node) {
if ( V_120 -> V_36 . V_121 != V_21 -> V_36 . V_121 )
return false ;
}
return true ;
}
T_2 F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_120 = F_51 ( V_2 ) ;
return V_120 -> V_36 . V_121 ;
}
T_3 F_83 ( struct V_1 * V_2 )
{
struct V_15 * V_120 = F_51 ( V_2 ) ;
struct V_122 * V_80 ;
T_2 V_121 ;
T_3 V_88 = 0 ;
if ( ! V_120 -> V_36 . V_123 )
goto V_124;
V_121 = V_120 -> V_36 . V_121 ;
if ( V_121 & V_125 )
V_88 += sizeof( V_80 -> V_111 ) * 2 ;
if ( V_121 & V_126 )
V_88 += sizeof( V_80 -> time ) ;
if ( V_121 & V_127 )
V_88 += sizeof( V_80 -> V_47 ) ;
if ( V_121 & V_128 )
V_88 += sizeof( V_80 -> V_129 ) ;
if ( V_121 & V_130 )
V_88 += sizeof( V_80 -> V_52 ) * 2 ;
V_124:
return V_88 ;
}
bool F_84 ( struct V_1 * V_2 )
{
struct V_15 * V_120 = F_51 ( V_2 ) , * V_21 = V_120 ;
F_81 (pos, &evlist->entries, node) {
if ( V_120 -> V_36 . V_123 != V_21 -> V_36 . V_123 )
return false ;
}
return true ;
}
bool F_53 ( struct V_1 * V_2 )
{
struct V_15 * V_120 = F_51 ( V_2 ) ;
return V_120 -> V_36 . V_123 ;
}
void F_85 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
V_2 -> V_131 = V_16 ;
}
int F_86 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_116 , V_117 , V_118 ;
F_9 (evsel, &evlist->entries, node) {
V_116 = F_87 ( V_16 , V_2 -> V_4 , V_2 -> V_6 ) ;
if ( V_116 < 0 )
goto V_132;
}
return 0 ;
V_132:
V_117 = V_2 -> V_4 ? V_2 -> V_4 -> V_54 : 1 ;
V_118 = V_2 -> V_6 ? V_2 -> V_6 -> V_54 : 1 ;
F_88 (evsel, &evlist->entries, node)
F_89 ( V_16 , V_117 , V_118 ) ;
V_133 = - V_116 ;
return V_116 ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
const char * V_134 [] )
{
int V_135 [ 2 ] , V_136 [ 2 ] ;
char V_137 ;
if ( F_91 ( V_135 ) < 0 ) {
perror ( L_3 ) ;
return - 1 ;
}
if ( F_91 ( V_136 ) < 0 ) {
perror ( L_4 ) ;
goto V_138;
}
V_2 -> V_11 . V_12 = F_92 () ;
if ( V_2 -> V_11 . V_12 < 0 ) {
perror ( L_5 ) ;
goto V_139;
}
if ( ! V_2 -> V_11 . V_12 ) {
if ( V_14 -> V_140 )
F_93 ( 2 , 1 ) ;
F_94 ( V_135 [ 0 ] ) ;
F_94 ( V_136 [ 1 ] ) ;
F_42 ( V_136 [ 0 ] , V_141 , V_142 ) ;
F_95 ( L_6 , ( char * * ) V_134 ) ;
F_94 ( V_135 [ 1 ] ) ;
if ( F_49 ( V_136 [ 0 ] , & V_137 , 1 ) == - 1 )
perror ( L_7 ) ;
F_95 ( V_134 [ 0 ] , ( char * * ) V_134 ) ;
perror ( V_134 [ 0 ] ) ;
F_96 ( F_97 () , V_143 ) ;
exit ( - 1 ) ;
}
if ( F_98 ( & V_14 -> V_110 ) )
V_2 -> V_6 -> V_18 [ 0 ] = V_2 -> V_11 . V_12 ;
F_94 ( V_135 [ 1 ] ) ;
F_94 ( V_136 [ 0 ] ) ;
if ( F_49 ( V_135 [ 0 ] , & V_137 , 1 ) == - 1 ) {
perror ( L_7 ) ;
goto V_139;
}
V_2 -> V_11 . V_144 = V_136 [ 1 ] ;
F_94 ( V_135 [ 0 ] ) ;
return 0 ;
V_139:
F_94 ( V_136 [ 0 ] ) ;
F_94 ( V_136 [ 1 ] ) ;
V_138:
F_94 ( V_135 [ 0 ] ) ;
F_94 ( V_135 [ 1 ] ) ;
return - 1 ;
}
int F_99 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_144 > 0 ) {
return F_94 ( V_2 -> V_11 . V_144 ) ;
}
return 0 ;
}
int F_100 ( struct V_1 * V_2 , union V_76 * V_83 ,
struct V_122 * V_145 )
{
struct V_15 * V_16 = F_51 ( V_2 ) ;
return F_101 ( V_16 , V_83 , V_145 ) ;
}
T_1 F_102 ( struct V_1 * V_2 , T_4 * V_146 )
{
struct V_15 * V_16 ;
T_1 V_147 = 0 ;
F_9 (evsel, &evlist->entries, node) {
V_147 += fprintf ( V_146 , L_8 , V_16 -> V_33 ? L_9 : L_6 ,
F_103 ( V_16 ) ) ;
}
return V_147 + fprintf ( V_146 , L_10 ) ; ;
}
