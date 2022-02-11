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
void F_7 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_8 ( V_2 ) ;
V_2 -> V_15 = V_14 -> V_15 ;
V_2 -> V_16 = V_14 -> V_16 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
F_10 (evsel, &evlist->entries, node)
F_11 ( V_17 ) ;
F_7 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_13 * V_18 , * V_19 ;
F_13 (pos, n, &evlist->entries, node) {
F_14 ( & V_18 -> V_20 ) ;
F_15 ( V_18 ) ;
}
V_2 -> V_21 = 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
free ( V_2 -> V_22 ) ;
free ( V_2 -> V_23 ) ;
V_2 -> V_22 = NULL ;
V_2 -> V_23 = NULL ;
}
void F_17 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
F_16 ( V_2 ) ;
free ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 , struct V_13 * V_24 )
{
F_19 ( & V_24 -> V_20 , & V_2 -> V_10 ) ;
if ( ! V_2 -> V_21 ++ )
F_7 ( V_2 ) ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
int V_21 )
{
bool V_27 = ! V_2 -> V_21 ;
F_21 ( V_26 , & V_2 -> V_10 ) ;
V_2 -> V_21 += V_21 ;
if ( V_27 )
F_7 ( V_2 ) ;
}
void F_22 ( struct V_25 * V_26 )
{
struct V_13 * V_17 , * V_28 ;
V_28 = F_23 ( V_26 -> V_29 , struct V_13 , V_20 ) ;
V_17 = F_23 ( V_26 -> V_30 , struct V_13 , V_20 ) ;
V_28 -> V_31 = V_17 -> V_32 - V_28 -> V_32 + 1 ;
F_10 (evsel, list, node) {
V_17 -> V_28 = V_28 ;
}
}
void F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 ) {
V_2 -> V_33 = V_2 -> V_21 > 1 ? 1 : 0 ;
F_22 ( & V_2 -> V_10 ) ;
}
}
int F_25 ( struct V_1 * V_2 )
{
struct V_34 V_35 = {
. type = V_36 ,
. V_37 = V_38 ,
} ;
struct V_13 * V_17 ;
F_26 ( & V_35 ) ;
V_17 = F_27 ( & V_35 , 0 ) ;
if ( V_17 == NULL )
goto error;
V_17 -> V_39 = F_28 ( L_1 ) ;
if ( ! V_17 -> V_39 )
goto V_40;
F_18 ( V_2 , V_17 ) ;
return 0 ;
V_40:
F_15 ( V_17 ) ;
error:
return - V_41 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_34 * V_42 , T_1 V_43 )
{
struct V_13 * V_17 , * V_19 ;
F_30 ( V_44 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_43 ; V_7 ++ ) {
V_17 = F_27 ( V_42 + V_7 , V_2 -> V_21 + V_7 ) ;
if ( V_17 == NULL )
goto V_45;
F_19 ( & V_17 -> V_20 , & V_44 ) ;
}
F_20 ( V_2 , & V_44 , V_43 ) ;
return 0 ;
V_45:
F_13 (evsel, n, &head, node)
F_15 ( V_17 ) ;
return - 1 ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_34 * V_42 , T_1 V_43 )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_43 ; V_7 ++ )
F_26 ( V_42 + V_7 ) ;
return F_29 ( V_2 , V_42 , V_43 ) ;
}
struct V_13 *
F_32 ( struct V_1 * V_2 , int V_46 )
{
struct V_13 * V_17 ;
F_10 (evsel, &evlist->entries, node) {
if ( V_17 -> V_35 . type == V_47 &&
( int ) V_17 -> V_35 . V_37 == V_46 )
return V_17 ;
}
return NULL ;
}
struct V_13 *
F_33 ( struct V_1 * V_2 ,
const char * V_39 )
{
struct V_13 * V_17 ;
F_10 (evsel, &evlist->entries, node) {
if ( ( V_17 -> V_35 . type == V_47 ) &&
( strcmp ( V_17 -> V_39 , V_39 ) == 0 ) )
return V_17 ;
}
return NULL ;
}
int F_34 ( struct V_1 * V_2 ,
const char * V_48 , const char * V_39 , void * V_49 )
{
struct V_13 * V_17 ;
V_17 = F_35 ( V_48 , V_39 , V_2 -> V_21 ) ;
if ( V_17 == NULL )
return - 1 ;
V_17 -> V_49 . V_50 = V_49 ;
F_18 ( V_2 , V_17 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
int V_51 , V_52 ;
struct V_13 * V_18 ;
int V_53 = F_37 ( V_2 -> V_4 ) ;
int V_54 = F_38 ( V_2 -> V_6 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
F_10 (pos, &evlist->entries, node) {
if ( ! F_39 ( V_18 ) || ! V_18 -> V_55 )
continue;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ )
F_40 ( F_41 ( V_18 , V_51 , V_52 ) ,
V_56 , 0 ) ;
}
}
}
void F_42 ( struct V_1 * V_2 )
{
int V_51 , V_52 ;
struct V_13 * V_18 ;
int V_53 = F_37 ( V_2 -> V_4 ) ;
int V_54 = F_38 ( V_2 -> V_6 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
F_10 (pos, &evlist->entries, node) {
if ( ! F_39 ( V_18 ) || ! V_18 -> V_55 )
continue;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ )
F_40 ( F_41 ( V_18 , V_51 , V_52 ) ,
V_57 , 0 ) ;
}
}
}
int F_43 ( struct V_1 * V_2 ,
struct V_13 * V_17 )
{
int V_51 , V_52 , V_58 ;
if ( ! V_17 -> V_55 )
return 0 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_4 -> V_59 ; V_51 ++ ) {
for ( V_52 = 0 ; V_52 < V_2 -> V_6 -> V_59 ; V_52 ++ ) {
V_58 = F_40 ( F_41 ( V_17 , V_51 , V_52 ) ,
V_56 , 0 ) ;
if ( V_58 )
return V_58 ;
}
}
return 0 ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_13 * V_17 )
{
int V_51 , V_52 , V_58 ;
if ( ! V_17 -> V_55 )
return - V_60 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_4 -> V_59 ; V_51 ++ ) {
for ( V_52 = 0 ; V_52 < V_2 -> V_6 -> V_59 ; V_52 ++ ) {
V_58 = F_40 ( F_41 ( V_17 , V_51 , V_52 ) ,
V_57 , 0 ) ;
if ( V_58 )
return V_58 ;
}
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_53 = F_37 ( V_2 -> V_4 ) ;
int V_54 = F_38 ( V_2 -> V_6 ) ;
int V_61 = V_53 * V_54 * V_2 -> V_21 ;
V_2 -> V_23 = malloc ( sizeof( struct V_23 ) * V_61 ) ;
return V_2 -> V_23 != NULL ? 0 : - V_41 ;
}
void F_46 ( struct V_1 * V_2 , int V_55 )
{
F_47 ( V_55 , V_62 , V_63 ) ;
V_2 -> V_23 [ V_2 -> V_64 ] . V_55 = V_55 ;
V_2 -> V_23 [ V_2 -> V_64 ] . V_65 = V_66 ;
V_2 -> V_64 ++ ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_13 * V_17 ,
int V_51 , int V_52 , T_2 V_46 )
{
int V_67 ;
struct V_68 * V_69 = F_49 ( V_17 , V_51 , V_52 ) ;
V_69 -> V_46 = V_46 ;
V_69 -> V_17 = V_17 ;
V_67 = F_50 ( V_69 -> V_46 , V_70 ) ;
F_51 ( & V_69 -> V_20 , & V_2 -> V_9 [ V_67 ] ) ;
}
void F_52 ( struct V_1 * V_2 , struct V_13 * V_17 ,
int V_51 , int V_52 , T_2 V_46 )
{
F_48 ( V_2 , V_17 , V_51 , V_52 , V_46 ) ;
V_17 -> V_46 [ V_17 -> V_71 ++ ] = V_46 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_13 * V_17 ,
int V_51 , int V_52 , int V_55 )
{
T_2 V_72 [ 4 ] = { 0 , } ;
int V_73 = 1 ;
T_2 V_46 ;
int V_74 ;
V_74 = F_40 ( V_55 , V_75 , & V_46 ) ;
if ( ! V_74 )
goto V_76;
if ( V_77 != V_78 )
return - 1 ;
if ( F_54 ( V_2 ) & V_79 )
return - 1 ;
if ( ! ( V_17 -> V_35 . V_80 & V_81 ) ||
F_55 ( V_55 , & V_72 , sizeof( V_72 ) ) == - 1 )
return - 1 ;
if ( V_17 -> V_35 . V_80 & V_82 )
++ V_73 ;
if ( V_17 -> V_35 . V_80 & V_83 )
++ V_73 ;
V_46 = V_72 [ V_73 ] ;
V_76:
F_52 ( V_2 , V_17 , V_51 , V_52 , V_46 ) ;
return 0 ;
}
struct V_68 * F_56 ( struct V_1 * V_2 , T_2 V_46 )
{
struct V_84 * V_44 ;
struct V_68 * V_69 ;
int V_67 ;
V_67 = F_50 ( V_46 , V_70 ) ;
V_44 = & V_2 -> V_9 [ V_67 ] ;
F_57 (sid, head, node)
if ( V_69 -> V_46 == V_46 )
return V_69 ;
return NULL ;
}
struct V_13 * F_58 ( struct V_1 * V_2 , T_2 V_46 )
{
struct V_68 * V_69 ;
if ( V_2 -> V_21 == 1 )
return F_8 ( V_2 ) ;
V_69 = F_56 ( V_2 , V_46 ) ;
if ( V_69 )
return V_69 -> V_17 ;
if ( ! F_59 ( V_2 ) )
return F_8 ( V_2 ) ;
return NULL ;
}
static int F_60 ( struct V_1 * V_2 ,
union V_85 * V_86 , T_2 * V_46 )
{
const T_2 * V_87 = V_86 -> V_88 . V_87 ;
T_3 V_19 ;
V_19 = ( V_86 -> V_89 . V_90 - sizeof( V_86 -> V_89 ) ) >> 3 ;
if ( V_86 -> V_89 . type == V_91 ) {
if ( V_2 -> V_15 >= V_19 )
return - 1 ;
* V_46 = V_87 [ V_2 -> V_15 ] ;
} else {
if ( V_2 -> V_16 > V_19 )
return - 1 ;
V_19 -= V_2 -> V_16 ;
* V_46 = V_87 [ V_19 ] ;
}
return 0 ;
}
static struct V_13 * F_61 ( struct V_1 * V_2 ,
union V_85 * V_86 )
{
struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_84 * V_44 ;
struct V_68 * V_69 ;
int V_67 ;
T_2 V_46 ;
if ( V_2 -> V_21 == 1 )
return V_14 ;
if ( ! V_14 -> V_35 . V_92 &&
V_86 -> V_89 . type != V_91 )
return V_14 ;
if ( F_60 ( V_2 , V_86 , & V_46 ) )
return NULL ;
if ( ! V_46 )
return V_14 ;
V_67 = F_50 ( V_46 , V_70 ) ;
V_44 = & V_2 -> V_9 [ V_67 ] ;
F_57 (sid, head, node) {
if ( V_69 -> V_46 == V_46 )
return V_69 -> V_17 ;
}
return NULL ;
}
union V_85 * F_62 ( struct V_1 * V_2 , int V_32 )
{
struct V_93 * V_94 = & V_2 -> V_22 [ V_32 ] ;
unsigned int V_44 = F_63 ( V_94 ) ;
unsigned int V_95 = V_94 -> V_30 ;
unsigned char * V_96 = V_94 -> V_97 + V_98 ;
union V_85 * V_86 = NULL ;
if ( V_2 -> V_99 ) {
int V_100 = V_44 - V_95 ;
if ( V_100 > V_94 -> V_101 / 2 || V_100 < 0 ) {
fprintf ( V_102 , L_2 ) ;
V_95 = V_44 ;
}
}
if ( V_95 != V_44 ) {
T_1 V_90 ;
V_86 = (union V_85 * ) & V_96 [ V_95 & V_94 -> V_101 ] ;
V_90 = V_86 -> V_89 . V_90 ;
if ( ( V_95 & V_94 -> V_101 ) + V_90 != ( ( V_95 + V_90 ) & V_94 -> V_101 ) ) {
unsigned int V_103 = V_95 ;
unsigned int V_104 = F_64 ( sizeof( * V_86 ) , V_90 ) , V_105 ;
void * V_106 = & V_94 -> V_107 ;
do {
V_105 = F_64 ( V_94 -> V_101 + 1 - ( V_103 & V_94 -> V_101 ) , V_104 ) ;
memcpy ( V_106 , & V_96 [ V_103 & V_94 -> V_101 ] , V_105 ) ;
V_103 += V_105 ;
V_106 += V_105 ;
V_104 -= V_105 ;
} while ( V_104 );
V_86 = & V_94 -> V_107 ;
}
V_95 += V_90 ;
}
V_94 -> V_30 = V_95 ;
return V_86 ;
}
void F_65 ( struct V_1 * V_2 , int V_32 )
{
if ( ! V_2 -> V_99 ) {
struct V_93 * V_94 = & V_2 -> V_22 [ V_32 ] ;
unsigned int V_95 = V_94 -> V_30 ;
F_66 ( V_94 , V_95 ) ;
}
}
static void F_67 ( struct V_1 * V_2 , int V_32 )
{
if ( V_2 -> V_22 [ V_32 ] . V_97 != NULL ) {
F_68 ( V_2 -> V_22 [ V_32 ] . V_97 , V_2 -> V_108 ) ;
V_2 -> V_22 [ V_32 ] . V_97 = NULL ;
}
}
void F_69 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_109 ; V_7 ++ )
F_67 ( V_2 , V_7 ) ;
free ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
}
static int F_70 ( struct V_1 * V_2 )
{
V_2 -> V_109 = F_37 ( V_2 -> V_4 ) ;
if ( F_71 ( V_2 -> V_4 ) )
V_2 -> V_109 = F_38 ( V_2 -> V_6 ) ;
V_2 -> V_22 = F_6 ( V_2 -> V_109 * sizeof( struct V_93 ) ) ;
return V_2 -> V_22 != NULL ? 0 : - V_41 ;
}
static int F_72 ( struct V_1 * V_2 ,
int V_32 , int V_110 , int V_101 , int V_55 )
{
V_2 -> V_22 [ V_32 ] . V_30 = 0 ;
V_2 -> V_22 [ V_32 ] . V_101 = V_101 ;
V_2 -> V_22 [ V_32 ] . V_97 = V_22 ( NULL , V_2 -> V_108 , V_110 ,
V_111 , V_55 , 0 ) ;
if ( V_2 -> V_22 [ V_32 ] . V_97 == V_112 ) {
V_2 -> V_22 [ V_32 ] . V_97 = NULL ;
return - 1 ;
}
F_46 ( V_2 , V_55 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , int V_110 , int V_101 )
{
struct V_13 * V_17 ;
int V_51 , V_52 ;
int V_53 = F_37 ( V_2 -> V_4 ) ;
int V_54 = F_38 ( V_2 -> V_6 ) ;
F_74 ( L_3 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
int V_113 = - 1 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_10 (evsel, &evlist->entries, node) {
int V_55 = F_41 ( V_17 , V_51 , V_52 ) ;
if ( V_113 == - 1 ) {
V_113 = V_55 ;
if ( F_72 ( V_2 , V_51 ,
V_110 , V_101 , V_113 ) < 0 )
goto V_114;
} else {
if ( F_40 ( V_55 , V_115 , V_113 ) != 0 )
goto V_114;
}
if ( ( V_17 -> V_35 . V_80 & V_81 ) &&
F_53 ( V_2 , V_17 , V_51 , V_52 , V_55 ) < 0 )
goto V_114;
}
}
}
return 0 ;
V_114:
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ )
F_67 ( V_2 , V_51 ) ;
return - 1 ;
}
static int F_75 ( struct V_1 * V_2 , int V_110 , int V_101 )
{
struct V_13 * V_17 ;
int V_52 ;
int V_54 = F_38 ( V_2 -> V_6 ) ;
F_74 ( L_4 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
int V_113 = - 1 ;
F_10 (evsel, &evlist->entries, node) {
int V_55 = F_41 ( V_17 , 0 , V_52 ) ;
if ( V_113 == - 1 ) {
V_113 = V_55 ;
if ( F_72 ( V_2 , V_52 ,
V_110 , V_101 , V_113 ) < 0 )
goto V_114;
} else {
if ( F_40 ( V_55 , V_115 , V_113 ) != 0 )
goto V_114;
}
if ( ( V_17 -> V_35 . V_80 & V_81 ) &&
F_53 ( V_2 , V_17 , 0 , V_52 , V_55 ) < 0 )
goto V_114;
}
}
return 0 ;
V_114:
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ )
F_67 ( V_2 , V_52 ) ;
return - 1 ;
}
int F_76 ( struct V_1 * V_2 , unsigned int V_116 ,
bool V_99 )
{
struct V_13 * V_17 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
int V_110 = V_117 | ( V_99 ? 0 : V_118 ) , V_101 ;
if ( V_116 == V_119 )
V_116 = ( 512 * 1024 ) / V_98 ;
else if ( ! F_77 ( V_116 ) )
return - V_60 ;
V_101 = V_116 * V_98 - 1 ;
if ( V_2 -> V_22 == NULL && F_70 ( V_2 ) < 0 )
return - V_41 ;
if ( V_2 -> V_23 == NULL && F_45 ( V_2 ) < 0 )
return - V_41 ;
V_2 -> V_99 = V_99 ;
V_2 -> V_108 = ( V_116 + 1 ) * V_98 ;
F_10 (evsel, &evlist->entries, node) {
if ( ( V_17 -> V_35 . V_80 & V_81 ) &&
V_17 -> V_120 == NULL &&
F_78 ( V_17 , F_37 ( V_4 ) , V_6 -> V_59 ) < 0 )
return - V_41 ;
}
if ( F_71 ( V_4 ) )
return F_75 ( V_2 , V_110 , V_101 ) ;
return F_73 ( V_2 , V_110 , V_101 ) ;
}
int F_79 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
V_2 -> V_6 = F_80 ( V_122 -> V_12 , V_122 -> V_123 ,
V_122 -> V_124 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( F_81 ( V_122 ) )
V_2 -> V_4 = F_82 () ;
else if ( ! F_83 ( V_122 ) && ! V_122 -> V_125 )
V_2 -> V_4 = F_82 () ;
else
V_2 -> V_4 = F_84 ( V_122 -> V_126 ) ;
if ( V_2 -> V_4 == NULL )
goto V_127;
return 0 ;
V_127:
F_85 ( V_2 -> V_6 ) ;
return - 1 ;
}
void F_86 ( struct V_1 * V_2 )
{
F_87 ( V_2 -> V_4 ) ;
F_85 ( V_2 -> V_6 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_6 = NULL ;
}
int F_88 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
int V_58 = 0 ;
const int V_128 = F_37 ( V_2 -> V_4 ) ,
V_129 = F_38 ( V_2 -> V_6 ) ;
F_10 (evsel, &evlist->entries, node) {
if ( V_17 -> V_130 == NULL )
continue;
V_58 = F_89 ( V_17 , V_128 , V_129 , V_17 -> V_130 ) ;
if ( V_58 )
break;
}
return V_58 ;
}
int F_90 ( struct V_1 * V_2 , const char * V_130 )
{
struct V_13 * V_17 ;
int V_58 = 0 ;
const int V_128 = F_37 ( V_2 -> V_4 ) ,
V_129 = F_38 ( V_2 -> V_6 ) ;
F_10 (evsel, &evlist->entries, node) {
V_58 = F_89 ( V_17 , V_128 , V_129 , V_130 ) ;
if ( V_58 )
break;
}
return V_58 ;
}
bool F_91 ( struct V_1 * V_2 )
{
struct V_13 * V_18 ;
if ( V_2 -> V_21 == 1 )
return true ;
if ( V_2 -> V_15 < 0 || V_2 -> V_16 < 0 )
return false ;
F_10 (pos, &evlist->entries, node) {
if ( V_18 -> V_15 != V_2 -> V_15 ||
V_18 -> V_16 != V_2 -> V_16 )
return false ;
}
return true ;
}
T_2 F_92 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
if ( V_2 -> V_131 )
return V_2 -> V_131 ;
F_10 (evsel, &evlist->entries, node)
V_2 -> V_131 |= V_17 -> V_35 . V_132 ;
return V_2 -> V_131 ;
}
T_2 F_93 ( struct V_1 * V_2 )
{
V_2 -> V_131 = 0 ;
return F_92 ( V_2 ) ;
}
bool F_94 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_8 ( V_2 ) , * V_18 = V_14 ;
T_2 V_80 = V_14 -> V_35 . V_80 ;
T_2 V_132 = V_14 -> V_35 . V_132 ;
F_95 (pos, &evlist->entries, node) {
if ( V_80 != V_18 -> V_35 . V_80 )
return false ;
}
if ( ( V_132 & V_133 ) &&
! ( V_80 & V_81 ) ) {
return false ;
}
return true ;
}
T_2 F_54 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_8 ( V_2 ) ;
return V_14 -> V_35 . V_80 ;
}
T_4 F_96 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_134 * V_96 ;
T_2 V_132 ;
T_4 V_90 = 0 ;
if ( ! V_14 -> V_35 . V_92 )
goto V_135;
V_132 = V_14 -> V_35 . V_132 ;
if ( V_132 & V_136 )
V_90 += sizeof( V_96 -> V_123 ) * 2 ;
if ( V_132 & V_137 )
V_90 += sizeof( V_96 -> time ) ;
if ( V_132 & V_138 )
V_90 += sizeof( V_96 -> V_46 ) ;
if ( V_132 & V_139 )
V_90 += sizeof( V_96 -> V_140 ) ;
if ( V_132 & V_141 )
V_90 += sizeof( V_96 -> V_51 ) * 2 ;
if ( V_132 & V_142 )
V_90 += sizeof( V_96 -> V_46 ) ;
V_135:
return V_90 ;
}
bool F_97 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_8 ( V_2 ) , * V_18 = V_14 ;
F_95 (pos, &evlist->entries, node) {
if ( V_14 -> V_35 . V_92 != V_18 -> V_35 . V_92 )
return false ;
}
return true ;
}
bool F_59 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_8 ( V_2 ) ;
return V_14 -> V_35 . V_92 ;
}
void F_98 ( struct V_1 * V_2 ,
struct V_13 * V_17 )
{
V_2 -> V_143 = V_17 ;
}
void F_99 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
int V_128 = F_37 ( V_2 -> V_4 ) ;
int V_129 = F_38 ( V_2 -> V_6 ) ;
F_100 (evsel, &evlist->entries, node)
F_101 ( V_17 , V_128 , V_129 ) ;
}
int F_102 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
int V_58 ;
F_9 ( V_2 ) ;
F_10 (evsel, &evlist->entries, node) {
V_58 = F_103 ( V_17 , V_2 -> V_4 , V_2 -> V_6 ) ;
if ( V_58 < 0 )
goto V_144;
}
return 0 ;
V_144:
F_99 ( V_2 ) ;
V_77 = - V_58 ;
return V_58 ;
}
int F_104 ( struct V_1 * V_2 ,
struct V_121 * V_122 ,
const char * V_145 [] , bool V_146 ,
bool V_147 )
{
int V_148 [ 2 ] , V_149 [ 2 ] ;
char V_150 ;
if ( F_105 ( V_148 ) < 0 ) {
perror ( L_5 ) ;
return - 1 ;
}
if ( F_105 ( V_149 ) < 0 ) {
perror ( L_6 ) ;
goto V_151;
}
V_2 -> V_11 . V_12 = F_106 () ;
if ( V_2 -> V_11 . V_12 < 0 ) {
perror ( L_7 ) ;
goto V_152;
}
if ( ! V_2 -> V_11 . V_12 ) {
if ( V_146 )
F_107 ( 2 , 1 ) ;
signal ( V_153 , V_154 ) ;
F_108 ( V_148 [ 0 ] ) ;
F_108 ( V_149 [ 1 ] ) ;
F_47 ( V_149 [ 0 ] , V_155 , V_156 ) ;
F_108 ( V_148 [ 1 ] ) ;
if ( F_55 ( V_149 [ 0 ] , & V_150 , 1 ) == - 1 )
perror ( L_8 ) ;
F_109 ( V_145 [ 0 ] , ( char * * ) V_145 ) ;
perror ( V_145 [ 0 ] ) ;
if ( V_147 )
F_110 ( F_111 () , V_157 ) ;
exit ( - 1 ) ;
}
if ( F_112 ( V_122 ) )
V_2 -> V_6 -> V_158 [ 0 ] = V_2 -> V_11 . V_12 ;
F_108 ( V_148 [ 1 ] ) ;
F_108 ( V_149 [ 0 ] ) ;
if ( F_55 ( V_148 [ 0 ] , & V_150 , 1 ) == - 1 ) {
perror ( L_8 ) ;
goto V_152;
}
F_47 ( V_149 [ 1 ] , V_155 , V_156 ) ;
V_2 -> V_11 . V_159 = V_149 [ 1 ] ;
F_108 ( V_148 [ 0 ] ) ;
return 0 ;
V_152:
F_108 ( V_149 [ 0 ] ) ;
F_108 ( V_149 [ 1 ] ) ;
V_151:
F_108 ( V_148 [ 0 ] ) ;
F_108 ( V_148 [ 1 ] ) ;
return - 1 ;
}
int F_113 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_159 > 0 ) {
char V_150 = 0 ;
int V_74 ;
V_74 = F_114 ( V_2 -> V_11 . V_159 , & V_150 , 1 ) ;
if ( V_74 < 0 )
perror ( L_9 ) ;
F_108 ( V_2 -> V_11 . V_159 ) ;
return V_74 ;
}
return 0 ;
}
int F_115 ( struct V_1 * V_2 , union V_85 * V_86 ,
struct V_134 * V_88 )
{
struct V_13 * V_17 = F_61 ( V_2 , V_86 ) ;
if ( ! V_17 )
return - V_160 ;
return F_116 ( V_17 , V_86 , V_88 ) ;
}
T_1 F_117 ( struct V_1 * V_2 , T_5 * V_161 )
{
struct V_13 * V_17 ;
T_1 V_162 = 0 ;
F_10 (evsel, &evlist->entries, node) {
V_162 += fprintf ( V_161 , L_10 , V_17 -> V_32 ? L_11 : L_12 ,
F_118 ( V_17 ) ) ;
}
return V_162 + fprintf ( V_161 , L_13 ) ; ;
}
