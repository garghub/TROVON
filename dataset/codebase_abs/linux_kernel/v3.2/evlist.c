void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 )
F_2 ( & V_2 -> V_9 [ V_7 ] ) ;
F_3 ( & V_2 -> V_10 ) ;
F_4 ( V_2 , V_4 , V_6 ) ;
}
struct V_1 * F_5 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( sizeof( * V_2 ) ) ;
if ( V_2 != NULL )
F_1 ( V_2 , V_4 , V_6 ) ;
return V_2 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_13 ;
F_8 (pos, n, &evlist->entries, node) {
F_9 ( & V_12 -> V_14 ) ;
F_10 ( V_12 ) ;
}
V_2 -> V_15 = 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
free ( V_2 -> V_16 ) ;
free ( V_2 -> V_17 ) ;
V_2 -> V_16 = NULL ;
V_2 -> V_17 = NULL ;
}
void F_12 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_11 ( V_2 ) ;
free ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 , struct V_11 * V_18 )
{
F_14 ( & V_18 -> V_14 , & V_2 -> V_10 ) ;
++ V_2 -> V_15 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_19 V_20 = {
. type = V_21 ,
. V_22 = V_23 ,
} ;
struct V_11 * V_24 = F_16 ( & V_20 , 0 ) ;
if ( V_24 == NULL )
goto error;
V_24 -> V_25 = F_17 ( L_1 ) ;
if ( ! V_24 -> V_25 )
goto V_26;
F_13 ( V_2 , V_24 ) ;
return 0 ;
V_26:
F_10 ( V_24 ) ;
error:
return - V_27 ;
}
void F_18 ( struct V_1 * V_2 )
{
int V_28 , V_29 ;
struct V_11 * V_12 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_4 -> V_30 ; V_28 ++ ) {
F_19 (pos, &evlist->entries, node) {
for ( V_29 = 0 ; V_29 < V_2 -> V_6 -> V_30 ; V_29 ++ )
F_20 ( F_21 ( V_12 , V_28 , V_29 ) , V_31 ) ;
}
}
}
void F_22 ( struct V_1 * V_2 )
{
int V_28 , V_29 ;
struct V_11 * V_12 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_4 -> V_30 ; V_28 ++ ) {
F_19 (pos, &evlist->entries, node) {
for ( V_29 = 0 ; V_29 < V_2 -> V_6 -> V_30 ; V_29 ++ )
F_20 ( F_21 ( V_12 , V_28 , V_29 ) , V_32 ) ;
}
}
}
int F_23 ( struct V_1 * V_2 )
{
int V_33 = V_2 -> V_4 -> V_30 * V_2 -> V_6 -> V_30 * V_2 -> V_15 ;
V_2 -> V_17 = malloc ( sizeof( struct V_17 ) * V_33 ) ;
return V_2 -> V_17 != NULL ? 0 : - V_27 ;
}
void F_24 ( struct V_1 * V_2 , int V_34 )
{
F_25 ( V_34 , V_35 , V_36 ) ;
V_2 -> V_17 [ V_2 -> V_37 ] . V_34 = V_34 ;
V_2 -> V_17 [ V_2 -> V_37 ] . V_38 = V_39 ;
V_2 -> V_37 ++ ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_11 * V_24 ,
int V_28 , int V_29 , T_1 V_40 )
{
int V_41 ;
struct V_42 * V_43 = F_27 ( V_24 , V_28 , V_29 ) ;
V_43 -> V_40 = V_40 ;
V_43 -> V_24 = V_24 ;
V_41 = F_28 ( V_43 -> V_40 , V_44 ) ;
F_29 ( & V_43 -> V_14 , & V_2 -> V_9 [ V_41 ] ) ;
}
void F_30 ( struct V_1 * V_2 , struct V_11 * V_24 ,
int V_28 , int V_29 , T_1 V_40 )
{
F_26 ( V_2 , V_24 , V_28 , V_29 , V_40 ) ;
V_24 -> V_40 [ V_24 -> V_45 ++ ] = V_40 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_11 * V_24 ,
int V_28 , int V_29 , int V_34 )
{
T_1 V_46 [ 4 ] = { 0 , } ;
int V_47 = 1 ;
if ( ! ( V_24 -> V_20 . V_48 & V_49 ) ||
F_32 ( V_34 , & V_46 , sizeof( V_46 ) ) == - 1 )
return - 1 ;
if ( V_24 -> V_20 . V_48 & V_50 )
++ V_47 ;
if ( V_24 -> V_20 . V_48 & V_51 )
++ V_47 ;
F_30 ( V_2 , V_24 , V_28 , V_29 , V_46 [ V_47 ] ) ;
return 0 ;
}
struct V_11 * F_33 ( struct V_1 * V_2 , T_1 V_40 )
{
struct V_52 * V_53 ;
struct V_54 * V_12 ;
struct V_42 * V_43 ;
int V_41 ;
if ( V_2 -> V_15 == 1 )
return F_34 ( V_2 -> V_10 . V_55 , struct V_11 , V_14 ) ;
V_41 = F_28 ( V_40 , V_44 ) ;
V_53 = & V_2 -> V_9 [ V_41 ] ;
F_35 (sid, pos, head, node)
if ( V_43 -> V_40 == V_40 )
return V_43 -> V_24 ;
return NULL ;
}
union V_56 * F_36 ( struct V_1 * V_2 , int V_57 )
{
unsigned int V_58 = F_37 ( V_59 ) ;
struct V_60 * V_61 = & V_2 -> V_16 [ V_57 ] ;
unsigned int V_53 = F_38 ( V_61 ) ;
unsigned int V_62 = V_61 -> V_63 ;
unsigned char * V_64 = V_61 -> V_65 + V_58 ;
union V_56 * V_66 = NULL ;
if ( V_2 -> V_67 ) {
int V_68 = V_53 - V_62 ;
if ( V_68 > V_61 -> V_69 / 2 || V_68 < 0 ) {
fprintf ( V_70 , L_2 ) ;
V_62 = V_53 ;
}
}
if ( V_62 != V_53 ) {
T_2 V_71 ;
V_66 = (union V_56 * ) & V_64 [ V_62 & V_61 -> V_69 ] ;
V_71 = V_66 -> V_72 . V_71 ;
if ( ( V_62 & V_61 -> V_69 ) + V_71 != ( ( V_62 + V_71 ) & V_61 -> V_69 ) ) {
unsigned int V_73 = V_62 ;
unsigned int V_74 = F_39 ( sizeof( * V_66 ) , V_71 ) , V_75 ;
void * V_76 = & V_2 -> V_77 ;
do {
V_75 = F_39 ( V_61 -> V_69 + 1 - ( V_73 & V_61 -> V_69 ) , V_74 ) ;
memcpy ( V_76 , & V_64 [ V_73 & V_61 -> V_69 ] , V_75 ) ;
V_73 += V_75 ;
V_76 += V_75 ;
V_74 -= V_75 ;
} while ( V_74 );
V_66 = & V_2 -> V_77 ;
}
V_62 += V_71 ;
}
V_61 -> V_63 = V_62 ;
if ( ! V_2 -> V_67 )
F_40 ( V_61 , V_62 ) ;
return V_66 ;
}
void F_41 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_78 ; V_7 ++ ) {
if ( V_2 -> V_16 [ V_7 ] . V_65 != NULL ) {
F_42 ( V_2 -> V_16 [ V_7 ] . V_65 , V_2 -> V_79 ) ;
V_2 -> V_16 [ V_7 ] . V_65 = NULL ;
}
}
free ( V_2 -> V_16 ) ;
V_2 -> V_16 = NULL ;
}
int F_43 ( struct V_1 * V_2 )
{
V_2 -> V_78 = V_2 -> V_4 -> V_30 ;
if ( V_2 -> V_4 -> V_80 [ 0 ] == - 1 )
V_2 -> V_78 = V_2 -> V_6 -> V_30 ;
V_2 -> V_16 = F_6 ( V_2 -> V_78 * sizeof( struct V_60 ) ) ;
return V_2 -> V_16 != NULL ? 0 : - V_27 ;
}
static int F_44 ( struct V_1 * V_2 ,
int V_57 , int V_81 , int V_69 , int V_34 )
{
V_2 -> V_16 [ V_57 ] . V_63 = 0 ;
V_2 -> V_16 [ V_57 ] . V_69 = V_69 ;
V_2 -> V_16 [ V_57 ] . V_65 = V_16 ( NULL , V_2 -> V_79 , V_81 ,
V_82 , V_34 , 0 ) ;
if ( V_2 -> V_16 [ V_57 ] . V_65 == V_83 )
return - 1 ;
F_24 ( V_2 , V_34 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , int V_81 , int V_69 )
{
struct V_11 * V_24 ;
int V_28 , V_29 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_4 -> V_30 ; V_28 ++ ) {
int V_84 = - 1 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_6 -> V_30 ; V_29 ++ ) {
F_19 (evsel, &evlist->entries, node) {
int V_34 = F_21 ( V_24 , V_28 , V_29 ) ;
if ( V_84 == - 1 ) {
V_84 = V_34 ;
if ( F_44 ( V_2 , V_28 ,
V_81 , V_69 , V_84 ) < 0 )
goto V_85;
} else {
if ( F_20 ( V_34 , V_86 , V_84 ) != 0 )
goto V_85;
}
if ( ( V_24 -> V_20 . V_48 & V_49 ) &&
F_31 ( V_2 , V_24 , V_28 , V_29 , V_34 ) < 0 )
goto V_85;
}
}
}
return 0 ;
V_85:
for ( V_28 = 0 ; V_28 < V_2 -> V_4 -> V_30 ; V_28 ++ ) {
if ( V_2 -> V_16 [ V_28 ] . V_65 != NULL ) {
F_42 ( V_2 -> V_16 [ V_28 ] . V_65 , V_2 -> V_79 ) ;
V_2 -> V_16 [ V_28 ] . V_65 = NULL ;
}
}
return - 1 ;
}
static int F_46 ( struct V_1 * V_2 , int V_81 , int V_69 )
{
struct V_11 * V_24 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_6 -> V_30 ; V_29 ++ ) {
int V_84 = - 1 ;
F_19 (evsel, &evlist->entries, node) {
int V_34 = F_21 ( V_24 , 0 , V_29 ) ;
if ( V_84 == - 1 ) {
V_84 = V_34 ;
if ( F_44 ( V_2 , V_29 ,
V_81 , V_69 , V_84 ) < 0 )
goto V_85;
} else {
if ( F_20 ( V_34 , V_86 , V_84 ) != 0 )
goto V_85;
}
if ( ( V_24 -> V_20 . V_48 & V_49 ) &&
F_31 ( V_2 , V_24 , 0 , V_29 , V_34 ) < 0 )
goto V_85;
}
}
return 0 ;
V_85:
for ( V_29 = 0 ; V_29 < V_2 -> V_6 -> V_30 ; V_29 ++ ) {
if ( V_2 -> V_16 [ V_29 ] . V_65 != NULL ) {
F_42 ( V_2 -> V_16 [ V_29 ] . V_65 , V_2 -> V_79 ) ;
V_2 -> V_16 [ V_29 ] . V_65 = NULL ;
}
}
return - 1 ;
}
int F_47 ( struct V_1 * V_2 , int V_87 , bool V_67 )
{
unsigned int V_58 = F_37 ( V_59 ) ;
int V_69 = V_87 * V_58 - 1 ;
struct V_11 * V_24 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
int V_81 = V_88 | ( V_67 ? 0 : V_89 ) ;
if ( V_2 -> V_16 == NULL && F_43 ( V_2 ) < 0 )
return - V_27 ;
if ( V_2 -> V_17 == NULL && F_23 ( V_2 ) < 0 )
return - V_27 ;
V_2 -> V_67 = V_67 ;
V_2 -> V_79 = ( V_87 + 1 ) * V_58 ;
F_19 (evsel, &evlist->entries, node) {
if ( ( V_24 -> V_20 . V_48 & V_49 ) &&
V_24 -> V_90 == NULL &&
F_48 ( V_24 , V_4 -> V_30 , V_6 -> V_30 ) < 0 )
return - V_27 ;
}
if ( V_2 -> V_4 -> V_80 [ 0 ] == - 1 )
return F_46 ( V_2 , V_81 , V_69 ) ;
return F_45 ( V_2 , V_81 , V_69 ) ;
}
int F_49 ( struct V_1 * V_2 , T_3 V_91 ,
T_3 V_92 , const char * V_93 )
{
V_2 -> V_6 = F_50 ( V_91 , V_92 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( V_93 == NULL && V_92 != - 1 )
V_2 -> V_4 = F_51 () ;
else
V_2 -> V_4 = F_52 ( V_93 ) ;
if ( V_2 -> V_4 == NULL )
goto V_94;
return 0 ;
V_94:
F_53 ( V_2 -> V_6 ) ;
return - 1 ;
}
void F_54 ( struct V_1 * V_2 )
{
F_55 ( V_2 -> V_4 ) ;
F_53 ( V_2 -> V_6 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_6 = NULL ;
}
int F_56 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_2 -> V_6 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
struct V_11 * V_24 ;
char * V_95 ;
int V_29 ;
int V_28 ;
int V_96 ;
int V_34 ;
F_19 (evsel, &evlist->entries, node) {
V_95 = V_24 -> V_95 ;
if ( ! V_95 )
continue;
for ( V_28 = 0 ; V_28 < V_4 -> V_30 ; V_28 ++ ) {
for ( V_29 = 0 ; V_29 < V_6 -> V_30 ; V_29 ++ ) {
V_34 = F_21 ( V_24 , V_28 , V_29 ) ;
V_96 = F_20 ( V_34 , V_97 , V_95 ) ;
if ( V_96 )
return V_96 ;
}
}
}
return 0 ;
}
bool F_57 ( const struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_98 ;
V_12 = V_98 = F_34 ( V_2 -> V_10 . V_55 , struct V_11 , V_14 ) ;
F_58 (pos, &evlist->entries, node) {
if ( V_98 -> V_20 . V_99 != V_12 -> V_20 . V_99 )
return false ;
}
return true ;
}
T_1 F_59 ( const struct V_1 * V_2 )
{
struct V_11 * V_98 ;
V_98 = F_34 ( V_2 -> V_10 . V_55 , struct V_11 , V_14 ) ;
return V_98 -> V_20 . V_99 ;
}
bool F_60 ( const struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_98 ;
V_12 = V_98 = F_34 ( V_2 -> V_10 . V_55 , struct V_11 , V_14 ) ;
F_58 (pos, &evlist->entries, node) {
if ( V_98 -> V_20 . V_100 != V_12 -> V_20 . V_100 )
return false ;
}
return true ;
}
bool F_61 ( const struct V_1 * V_2 )
{
struct V_11 * V_98 ;
V_98 = F_34 ( V_2 -> V_10 . V_55 , struct V_11 , V_14 ) ;
return V_98 -> V_20 . V_100 ;
}
void F_62 ( struct V_1 * V_2 ,
struct V_11 * V_24 )
{
V_2 -> V_101 = V_24 ;
}
int F_63 ( struct V_1 * V_2 , bool V_102 )
{
struct V_11 * V_24 , * V_98 ;
int V_96 , V_103 , V_104 ;
V_98 = F_34 ( V_2 -> V_10 . V_55 , struct V_11 , V_14 ) ;
F_19 (evsel, &evlist->entries, node) {
struct V_105 * V_106 = NULL ;
if ( V_102 && V_24 != V_98 )
V_106 = V_98 -> V_34 ;
V_96 = F_64 ( V_24 , V_2 -> V_4 , V_2 -> V_6 ,
V_102 , V_106 ) ;
if ( V_96 < 0 )
goto V_107;
}
return 0 ;
V_107:
V_103 = V_2 -> V_4 ? V_2 -> V_4 -> V_30 : 1 ;
V_104 = V_2 -> V_6 ? V_2 -> V_6 -> V_30 : 1 ;
F_65 (evsel, &evlist->entries, node)
F_66 ( V_24 , V_103 , V_104 ) ;
return V_96 ;
}
