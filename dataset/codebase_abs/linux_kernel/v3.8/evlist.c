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
void F_18 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
int V_19 )
{
F_19 ( V_30 , & V_2 -> V_10 ) ;
V_2 -> V_19 += V_19 ;
}
void F_20 ( struct V_29 * V_30 )
{
struct V_15 * V_16 , * V_31 ;
V_31 = F_21 ( V_30 -> V_32 , struct V_15 , V_25 ) ;
V_31 -> V_31 = NULL ;
F_8 (evsel, list, node) {
if ( V_16 != V_31 )
V_16 -> V_31 = V_31 ;
}
}
void F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 )
F_20 ( & V_2 -> V_10 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_33 V_20 = {
. type = V_34 ,
. V_35 = V_36 ,
} ;
struct V_15 * V_16 ;
F_24 ( & V_20 ) ;
V_16 = F_25 ( & V_20 , 0 ) ;
if ( V_16 == NULL )
goto error;
V_16 -> V_37 = F_26 ( L_1 ) ;
if ( ! V_16 -> V_37 )
goto V_38;
F_16 ( V_2 , V_16 ) ;
return 0 ;
V_38:
F_13 ( V_16 ) ;
error:
return - V_39 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_33 * V_40 , T_1 V_41 )
{
struct V_15 * V_16 , * V_24 ;
F_28 ( V_42 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_41 ; V_7 ++ ) {
V_16 = F_25 ( V_40 + V_7 , V_2 -> V_19 + V_7 ) ;
if ( V_16 == NULL )
goto V_43;
F_17 ( & V_16 -> V_25 , & V_42 ) ;
}
F_18 ( V_2 , & V_42 , V_41 ) ;
return 0 ;
V_43:
F_11 (evsel, n, &head, node)
F_13 ( V_16 ) ;
return - 1 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_33 * V_40 , T_1 V_41 )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_41 ; V_7 ++ )
F_24 ( V_40 + V_7 ) ;
return F_27 ( V_2 , V_40 , V_41 ) ;
}
struct V_15 *
F_30 ( struct V_1 * V_2 , int V_44 )
{
struct V_15 * V_16 ;
F_8 (evsel, &evlist->entries, node) {
if ( V_16 -> V_20 . type == V_45 &&
( int ) V_16 -> V_20 . V_35 == V_44 )
return V_16 ;
}
return NULL ;
}
int F_31 ( struct V_1 * V_2 ,
const char * V_46 , const char * V_37 , void * V_47 )
{
struct V_15 * V_16 ;
V_16 = F_32 ( V_46 , V_37 , V_2 -> V_19 ) ;
if ( V_16 == NULL )
return - 1 ;
V_16 -> V_47 . V_48 = V_47 ;
F_16 ( V_2 , V_16 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
int V_49 , V_50 ;
struct V_15 * V_23 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_4 -> V_51 ; V_49 ++ ) {
F_8 (pos, &evlist->entries, node) {
if ( F_34 ( V_23 ) )
continue;
for ( V_50 = 0 ; V_50 < V_2 -> V_6 -> V_51 ; V_50 ++ )
F_35 ( F_36 ( V_23 , V_49 , V_50 ) ,
V_52 , 0 ) ;
}
}
}
void F_37 ( struct V_1 * V_2 )
{
int V_49 , V_50 ;
struct V_15 * V_23 ;
for ( V_49 = 0 ; V_49 < F_38 ( V_2 -> V_4 ) ; V_49 ++ ) {
F_8 (pos, &evlist->entries, node) {
if ( F_34 ( V_23 ) )
continue;
for ( V_50 = 0 ; V_50 < V_2 -> V_6 -> V_51 ; V_50 ++ )
F_35 ( F_36 ( V_23 , V_49 , V_50 ) ,
V_53 , 0 ) ;
}
}
}
static int F_39 ( struct V_1 * V_2 )
{
int V_54 = F_38 ( V_2 -> V_4 ) * V_2 -> V_6 -> V_51 * V_2 -> V_19 ;
V_2 -> V_27 = malloc ( sizeof( struct V_27 ) * V_54 ) ;
return V_2 -> V_27 != NULL ? 0 : - V_39 ;
}
void F_40 ( struct V_1 * V_2 , int V_55 )
{
F_41 ( V_55 , V_56 , V_57 ) ;
V_2 -> V_27 [ V_2 -> V_58 ] . V_55 = V_55 ;
V_2 -> V_27 [ V_2 -> V_58 ] . V_59 = V_60 ;
V_2 -> V_58 ++ ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_49 , int V_50 , T_2 V_44 )
{
int V_61 ;
struct V_62 * V_63 = F_43 ( V_16 , V_49 , V_50 ) ;
V_63 -> V_44 = V_44 ;
V_63 -> V_16 = V_16 ;
V_61 = F_44 ( V_63 -> V_44 , V_64 ) ;
F_45 ( & V_63 -> V_25 , & V_2 -> V_9 [ V_61 ] ) ;
}
void F_46 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_49 , int V_50 , T_2 V_44 )
{
F_42 ( V_2 , V_16 , V_49 , V_50 , V_44 ) ;
V_16 -> V_44 [ V_16 -> V_65 ++ ] = V_44 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_49 , int V_50 , int V_55 )
{
T_2 V_66 [ 4 ] = { 0 , } ;
int V_67 = 1 ;
if ( ! ( V_16 -> V_20 . V_68 & V_69 ) ||
F_48 ( V_55 , & V_66 , sizeof( V_66 ) ) == - 1 )
return - 1 ;
if ( V_16 -> V_20 . V_68 & V_70 )
++ V_67 ;
if ( V_16 -> V_20 . V_68 & V_71 )
++ V_67 ;
F_46 ( V_2 , V_16 , V_49 , V_50 , V_66 [ V_67 ] ) ;
return 0 ;
}
struct V_15 * F_49 ( struct V_1 * V_2 , T_2 V_44 )
{
struct V_72 * V_42 ;
struct V_73 * V_23 ;
struct V_62 * V_63 ;
int V_61 ;
if ( V_2 -> V_19 == 1 )
return F_50 ( V_2 ) ;
V_61 = F_44 ( V_44 , V_64 ) ;
V_42 = & V_2 -> V_9 [ V_61 ] ;
F_51 (sid, pos, head, node)
if ( V_63 -> V_44 == V_44 )
return V_63 -> V_16 ;
if ( ! F_52 ( V_2 ) )
return F_50 ( V_2 ) ;
return NULL ;
}
union V_74 * F_53 ( struct V_1 * V_2 , int V_75 )
{
struct V_76 * V_77 = & V_2 -> V_26 [ V_75 ] ;
unsigned int V_42 = F_54 ( V_77 ) ;
unsigned int V_78 = V_77 -> V_79 ;
unsigned char * V_80 = V_77 -> V_81 + V_82 ;
union V_74 * V_83 = NULL ;
if ( V_2 -> V_84 ) {
int V_85 = V_42 - V_78 ;
if ( V_85 > V_77 -> V_86 / 2 || V_85 < 0 ) {
fprintf ( V_87 , L_2 ) ;
V_78 = V_42 ;
}
}
if ( V_78 != V_42 ) {
T_1 V_88 ;
V_83 = (union V_74 * ) & V_80 [ V_78 & V_77 -> V_86 ] ;
V_88 = V_83 -> V_89 . V_88 ;
if ( ( V_78 & V_77 -> V_86 ) + V_88 != ( ( V_78 + V_88 ) & V_77 -> V_86 ) ) {
unsigned int V_90 = V_78 ;
unsigned int V_91 = F_55 ( sizeof( * V_83 ) , V_88 ) , V_92 ;
void * V_93 = & V_2 -> V_94 ;
do {
V_92 = F_55 ( V_77 -> V_86 + 1 - ( V_90 & V_77 -> V_86 ) , V_91 ) ;
memcpy ( V_93 , & V_80 [ V_90 & V_77 -> V_86 ] , V_92 ) ;
V_90 += V_92 ;
V_93 += V_92 ;
V_91 -= V_92 ;
} while ( V_91 );
V_83 = & V_2 -> V_94 ;
}
V_78 += V_88 ;
}
V_77 -> V_79 = V_78 ;
if ( ! V_2 -> V_84 )
F_56 ( V_77 , V_78 ) ;
return V_83 ;
}
void F_57 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_95 ; V_7 ++ ) {
if ( V_2 -> V_26 [ V_7 ] . V_81 != NULL ) {
F_58 ( V_2 -> V_26 [ V_7 ] . V_81 , V_2 -> V_96 ) ;
V_2 -> V_26 [ V_7 ] . V_81 = NULL ;
}
}
free ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
static int F_59 ( struct V_1 * V_2 )
{
V_2 -> V_95 = F_38 ( V_2 -> V_4 ) ;
if ( F_60 ( V_2 -> V_4 ) )
V_2 -> V_95 = V_2 -> V_6 -> V_51 ;
V_2 -> V_26 = F_6 ( V_2 -> V_95 * sizeof( struct V_76 ) ) ;
return V_2 -> V_26 != NULL ? 0 : - V_39 ;
}
static int F_61 ( struct V_1 * V_2 ,
int V_75 , int V_97 , int V_86 , int V_55 )
{
V_2 -> V_26 [ V_75 ] . V_79 = 0 ;
V_2 -> V_26 [ V_75 ] . V_86 = V_86 ;
V_2 -> V_26 [ V_75 ] . V_81 = V_26 ( NULL , V_2 -> V_96 , V_97 ,
V_98 , V_55 , 0 ) ;
if ( V_2 -> V_26 [ V_75 ] . V_81 == V_99 ) {
V_2 -> V_26 [ V_75 ] . V_81 = NULL ;
return - 1 ;
}
F_40 ( V_2 , V_55 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , int V_97 , int V_86 )
{
struct V_15 * V_16 ;
int V_49 , V_50 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_4 -> V_51 ; V_49 ++ ) {
int V_100 = - 1 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_6 -> V_51 ; V_50 ++ ) {
F_8 (evsel, &evlist->entries, node) {
int V_55 = F_36 ( V_16 , V_49 , V_50 ) ;
if ( V_100 == - 1 ) {
V_100 = V_55 ;
if ( F_61 ( V_2 , V_49 ,
V_97 , V_86 , V_100 ) < 0 )
goto V_101;
} else {
if ( F_35 ( V_55 , V_102 , V_100 ) != 0 )
goto V_101;
}
if ( ( V_16 -> V_20 . V_68 & V_69 ) &&
F_47 ( V_2 , V_16 , V_49 , V_50 , V_55 ) < 0 )
goto V_101;
}
}
}
return 0 ;
V_101:
for ( V_49 = 0 ; V_49 < V_2 -> V_4 -> V_51 ; V_49 ++ ) {
if ( V_2 -> V_26 [ V_49 ] . V_81 != NULL ) {
F_58 ( V_2 -> V_26 [ V_49 ] . V_81 , V_2 -> V_96 ) ;
V_2 -> V_26 [ V_49 ] . V_81 = NULL ;
}
}
return - 1 ;
}
static int F_63 ( struct V_1 * V_2 , int V_97 , int V_86 )
{
struct V_15 * V_16 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_6 -> V_51 ; V_50 ++ ) {
int V_100 = - 1 ;
F_8 (evsel, &evlist->entries, node) {
int V_55 = F_36 ( V_16 , 0 , V_50 ) ;
if ( V_100 == - 1 ) {
V_100 = V_55 ;
if ( F_61 ( V_2 , V_50 ,
V_97 , V_86 , V_100 ) < 0 )
goto V_101;
} else {
if ( F_35 ( V_55 , V_102 , V_100 ) != 0 )
goto V_101;
}
if ( ( V_16 -> V_20 . V_68 & V_69 ) &&
F_47 ( V_2 , V_16 , 0 , V_50 , V_55 ) < 0 )
goto V_101;
}
}
return 0 ;
V_101:
for ( V_50 = 0 ; V_50 < V_2 -> V_6 -> V_51 ; V_50 ++ ) {
if ( V_2 -> V_26 [ V_50 ] . V_81 != NULL ) {
F_58 ( V_2 -> V_26 [ V_50 ] . V_81 , V_2 -> V_96 ) ;
V_2 -> V_26 [ V_50 ] . V_81 = NULL ;
}
}
return - 1 ;
}
int F_64 ( struct V_1 * V_2 , unsigned int V_103 ,
bool V_84 )
{
struct V_15 * V_16 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
int V_97 = V_104 | ( V_84 ? 0 : V_105 ) , V_86 ;
if ( V_103 == V_106 )
V_103 = ( 512 * 1024 ) / V_82 ;
else if ( ! F_65 ( V_103 ) )
return - V_107 ;
V_86 = V_103 * V_82 - 1 ;
if ( V_2 -> V_26 == NULL && F_59 ( V_2 ) < 0 )
return - V_39 ;
if ( V_2 -> V_27 == NULL && F_39 ( V_2 ) < 0 )
return - V_39 ;
V_2 -> V_84 = V_84 ;
V_2 -> V_96 = ( V_103 + 1 ) * V_82 ;
F_8 (evsel, &evlist->entries, node) {
if ( ( V_16 -> V_20 . V_68 & V_69 ) &&
V_16 -> V_108 == NULL &&
F_66 ( V_16 , F_38 ( V_4 ) , V_6 -> V_51 ) < 0 )
return - V_39 ;
}
if ( F_60 ( V_4 ) )
return F_63 ( V_2 , V_97 , V_86 ) ;
return F_62 ( V_2 , V_97 , V_86 ) ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_109 * V_110 )
{
V_2 -> V_6 = F_68 ( V_110 -> V_12 , V_110 -> V_111 ,
V_110 -> V_112 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( F_69 ( V_110 ) )
V_2 -> V_4 = F_70 () ;
else if ( ! F_71 ( V_110 ) && ! V_110 -> V_113 )
V_2 -> V_4 = F_70 () ;
else
V_2 -> V_4 = F_72 ( V_110 -> V_114 ) ;
if ( V_2 -> V_4 == NULL )
goto V_115;
return 0 ;
V_115:
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
int V_116 = 0 ;
const int V_117 = F_38 ( V_2 -> V_4 ) ,
V_118 = V_2 -> V_6 -> V_51 ;
F_8 (evsel, &evlist->entries, node) {
if ( V_16 -> V_119 == NULL )
continue;
V_116 = F_77 ( V_16 , V_117 , V_118 , V_16 -> V_119 ) ;
if ( V_116 )
break;
}
return V_116 ;
}
int F_78 ( struct V_1 * V_2 , const char * V_119 )
{
struct V_15 * V_16 ;
int V_116 = 0 ;
const int V_117 = F_38 ( V_2 -> V_4 ) ,
V_118 = V_2 -> V_6 -> V_51 ;
F_8 (evsel, &evlist->entries, node) {
V_116 = F_77 ( V_16 , V_117 , V_118 , V_119 ) ;
if ( V_116 )
break;
}
return V_116 ;
}
bool F_79 ( struct V_1 * V_2 )
{
struct V_15 * V_120 = F_50 ( V_2 ) , * V_23 = V_120 ;
F_80 (pos, &evlist->entries, node) {
if ( V_120 -> V_20 . V_21 != V_23 -> V_20 . V_21 )
return false ;
}
return true ;
}
T_2 F_81 ( struct V_1 * V_2 )
{
struct V_15 * V_120 = F_50 ( V_2 ) ;
return V_120 -> V_20 . V_21 ;
}
T_3 F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_120 = F_50 ( V_2 ) ;
struct V_121 * V_80 ;
T_2 V_21 ;
T_3 V_88 = 0 ;
if ( ! V_120 -> V_20 . V_122 )
goto V_123;
V_21 = V_120 -> V_20 . V_21 ;
if ( V_21 & V_124 )
V_88 += sizeof( V_80 -> V_111 ) * 2 ;
if ( V_21 & V_125 )
V_88 += sizeof( V_80 -> time ) ;
if ( V_21 & V_22 )
V_88 += sizeof( V_80 -> V_44 ) ;
if ( V_21 & V_126 )
V_88 += sizeof( V_80 -> V_127 ) ;
if ( V_21 & V_128 )
V_88 += sizeof( V_80 -> V_49 ) * 2 ;
V_123:
return V_88 ;
}
bool F_83 ( struct V_1 * V_2 )
{
struct V_15 * V_120 = F_50 ( V_2 ) , * V_23 = V_120 ;
F_80 (pos, &evlist->entries, node) {
if ( V_120 -> V_20 . V_122 != V_23 -> V_20 . V_122 )
return false ;
}
return true ;
}
bool F_52 ( struct V_1 * V_2 )
{
struct V_15 * V_120 = F_50 ( V_2 ) ;
return V_120 -> V_20 . V_122 ;
}
void F_84 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
V_2 -> V_129 = V_16 ;
}
int F_85 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_116 , V_117 , V_118 ;
F_8 (evsel, &evlist->entries, node) {
V_116 = F_86 ( V_16 , V_2 -> V_4 , V_2 -> V_6 ) ;
if ( V_116 < 0 )
goto V_130;
}
return 0 ;
V_130:
V_117 = V_2 -> V_4 ? V_2 -> V_4 -> V_51 : 1 ;
V_118 = V_2 -> V_6 ? V_2 -> V_6 -> V_51 : 1 ;
F_87 (evsel, &evlist->entries, node)
F_88 ( V_16 , V_117 , V_118 ) ;
V_131 = - V_116 ;
return V_116 ;
}
int F_89 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
const char * V_132 [] )
{
int V_133 [ 2 ] , V_134 [ 2 ] ;
char V_135 ;
if ( F_90 ( V_133 ) < 0 ) {
perror ( L_3 ) ;
return - 1 ;
}
if ( F_90 ( V_134 ) < 0 ) {
perror ( L_4 ) ;
goto V_136;
}
V_2 -> V_11 . V_12 = F_91 () ;
if ( V_2 -> V_11 . V_12 < 0 ) {
perror ( L_5 ) ;
goto V_137;
}
if ( ! V_2 -> V_11 . V_12 ) {
if ( V_14 -> V_138 )
F_92 ( 2 , 1 ) ;
F_93 ( V_133 [ 0 ] ) ;
F_93 ( V_134 [ 1 ] ) ;
F_41 ( V_134 [ 0 ] , V_139 , V_140 ) ;
F_94 ( L_6 , ( char * * ) V_132 ) ;
F_93 ( V_133 [ 1 ] ) ;
if ( F_48 ( V_134 [ 0 ] , & V_135 , 1 ) == - 1 )
perror ( L_7 ) ;
F_94 ( V_132 [ 0 ] , ( char * * ) V_132 ) ;
perror ( V_132 [ 0 ] ) ;
F_95 ( F_96 () , V_141 ) ;
exit ( - 1 ) ;
}
if ( F_97 ( & V_14 -> V_110 ) )
V_2 -> V_6 -> V_17 [ 0 ] = V_2 -> V_11 . V_12 ;
F_93 ( V_133 [ 1 ] ) ;
F_93 ( V_134 [ 0 ] ) ;
if ( F_48 ( V_133 [ 0 ] , & V_135 , 1 ) == - 1 ) {
perror ( L_7 ) ;
goto V_137;
}
V_2 -> V_11 . V_142 = V_134 [ 1 ] ;
F_93 ( V_133 [ 0 ] ) ;
return 0 ;
V_137:
F_93 ( V_134 [ 0 ] ) ;
F_93 ( V_134 [ 1 ] ) ;
V_136:
F_93 ( V_133 [ 0 ] ) ;
F_93 ( V_133 [ 1 ] ) ;
return - 1 ;
}
int F_98 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_142 > 0 ) {
return F_93 ( V_2 -> V_11 . V_142 ) ;
}
return 0 ;
}
int F_99 ( struct V_1 * V_2 , union V_74 * V_83 ,
struct V_121 * V_143 )
{
struct V_15 * V_16 = F_50 ( V_2 ) ;
return F_100 ( V_16 , V_83 , V_143 ) ;
}
T_1 F_101 ( struct V_1 * V_2 , T_4 * V_144 )
{
struct V_15 * V_16 ;
T_1 V_145 = 0 ;
F_8 (evsel, &evlist->entries, node) {
V_145 += fprintf ( V_144 , L_8 , V_16 -> V_75 ? L_9 : L_6 ,
F_102 ( V_16 ) ) ;
}
return V_145 + fprintf ( V_144 , L_10 ) ; ;
}
