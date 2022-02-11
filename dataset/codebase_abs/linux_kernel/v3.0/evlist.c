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
return - V_25 ;
F_13 ( V_2 , V_24 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_26 = V_2 -> V_4 -> V_27 * V_2 -> V_6 -> V_27 * V_2 -> V_15 ;
V_2 -> V_17 = malloc ( sizeof( struct V_17 ) * V_26 ) ;
return V_2 -> V_17 != NULL ? 0 : - V_25 ;
}
void F_18 ( struct V_1 * V_2 , int V_28 )
{
F_19 ( V_28 , V_29 , V_30 ) ;
V_2 -> V_17 [ V_2 -> V_31 ] . V_28 = V_28 ;
V_2 -> V_17 [ V_2 -> V_31 ] . V_32 = V_33 ;
V_2 -> V_31 ++ ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_11 * V_24 ,
int V_34 , int V_35 , T_1 V_36 )
{
int V_37 ;
struct V_38 * V_39 = F_21 ( V_24 , V_34 , V_35 ) ;
V_39 -> V_36 = V_36 ;
V_39 -> V_24 = V_24 ;
V_37 = F_22 ( V_39 -> V_36 , V_40 ) ;
F_23 ( & V_39 -> V_14 , & V_2 -> V_9 [ V_37 ] ) ;
}
void F_24 ( struct V_1 * V_2 , struct V_11 * V_24 ,
int V_34 , int V_35 , T_1 V_36 )
{
F_20 ( V_2 , V_24 , V_34 , V_35 , V_36 ) ;
V_24 -> V_36 [ V_24 -> V_41 ++ ] = V_36 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_11 * V_24 ,
int V_34 , int V_35 , int V_28 )
{
T_1 V_42 [ 4 ] = { 0 , } ;
int V_43 = 1 ;
if ( ! ( V_24 -> V_20 . V_44 & V_45 ) ||
F_26 ( V_28 , & V_42 , sizeof( V_42 ) ) == - 1 )
return - 1 ;
if ( V_24 -> V_20 . V_44 & V_46 )
++ V_43 ;
if ( V_24 -> V_20 . V_44 & V_47 )
++ V_43 ;
F_24 ( V_2 , V_24 , V_34 , V_35 , V_42 [ V_43 ] ) ;
return 0 ;
}
struct V_11 * F_27 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_48 * V_49 ;
struct V_50 * V_12 ;
struct V_38 * V_39 ;
int V_37 ;
if ( V_2 -> V_15 == 1 )
return F_28 ( V_2 -> V_10 . V_51 , struct V_11 , V_14 ) ;
V_37 = F_22 ( V_36 , V_40 ) ;
V_49 = & V_2 -> V_9 [ V_37 ] ;
F_29 (sid, pos, head, node)
if ( V_39 -> V_36 == V_36 )
return V_39 -> V_24 ;
return NULL ;
}
union V_52 * F_30 ( struct V_1 * V_2 , int V_53 )
{
unsigned int V_54 = F_31 ( V_55 ) ;
struct V_56 * V_57 = & V_2 -> V_16 [ V_53 ] ;
unsigned int V_49 = F_32 ( V_57 ) ;
unsigned int V_58 = V_57 -> V_59 ;
unsigned char * V_60 = V_57 -> V_61 + V_54 ;
union V_52 * V_62 = NULL ;
if ( V_2 -> V_63 ) {
int V_64 = V_49 - V_58 ;
if ( V_64 > V_57 -> V_65 / 2 || V_64 < 0 ) {
fprintf ( V_66 , L_1 ) ;
V_58 = V_49 ;
}
}
if ( V_58 != V_49 ) {
T_2 V_67 ;
V_62 = (union V_52 * ) & V_60 [ V_58 & V_57 -> V_65 ] ;
V_67 = V_62 -> V_68 . V_67 ;
if ( ( V_58 & V_57 -> V_65 ) + V_67 != ( ( V_58 + V_67 ) & V_57 -> V_65 ) ) {
unsigned int V_69 = V_58 ;
unsigned int V_70 = F_33 ( sizeof( * V_62 ) , V_67 ) , V_71 ;
void * V_72 = & V_2 -> V_73 ;
do {
V_71 = F_33 ( V_57 -> V_65 + 1 - ( V_69 & V_57 -> V_65 ) , V_70 ) ;
memcpy ( V_72 , & V_60 [ V_69 & V_57 -> V_65 ] , V_71 ) ;
V_69 += V_71 ;
V_72 += V_71 ;
V_70 -= V_71 ;
} while ( V_70 );
V_62 = & V_2 -> V_73 ;
}
V_58 += V_67 ;
}
V_57 -> V_59 = V_58 ;
if ( ! V_2 -> V_63 )
F_34 ( V_57 , V_58 ) ;
return V_62 ;
}
void F_35 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_74 ; V_7 ++ ) {
if ( V_2 -> V_16 [ V_7 ] . V_61 != NULL ) {
F_36 ( V_2 -> V_16 [ V_7 ] . V_61 , V_2 -> V_75 ) ;
V_2 -> V_16 [ V_7 ] . V_61 = NULL ;
}
}
free ( V_2 -> V_16 ) ;
V_2 -> V_16 = NULL ;
}
int F_37 ( struct V_1 * V_2 )
{
V_2 -> V_74 = V_2 -> V_4 -> V_27 ;
if ( V_2 -> V_4 -> V_76 [ 0 ] == - 1 )
V_2 -> V_74 = V_2 -> V_6 -> V_27 ;
V_2 -> V_16 = F_6 ( V_2 -> V_74 * sizeof( struct V_56 ) ) ;
return V_2 -> V_16 != NULL ? 0 : - V_25 ;
}
static int F_38 ( struct V_1 * V_2 ,
int V_53 , int V_77 , int V_65 , int V_28 )
{
V_2 -> V_16 [ V_53 ] . V_59 = 0 ;
V_2 -> V_16 [ V_53 ] . V_65 = V_65 ;
V_2 -> V_16 [ V_53 ] . V_61 = V_16 ( NULL , V_2 -> V_75 , V_77 ,
V_78 , V_28 , 0 ) ;
if ( V_2 -> V_16 [ V_53 ] . V_61 == V_79 )
return - 1 ;
F_18 ( V_2 , V_28 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_77 , int V_65 )
{
struct V_11 * V_24 ;
int V_34 , V_35 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_4 -> V_27 ; V_34 ++ ) {
int V_80 = - 1 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_6 -> V_27 ; V_35 ++ ) {
F_40 (evsel, &evlist->entries, node) {
int V_28 = F_41 ( V_24 , V_34 , V_35 ) ;
if ( V_80 == - 1 ) {
V_80 = V_28 ;
if ( F_38 ( V_2 , V_34 ,
V_77 , V_65 , V_80 ) < 0 )
goto V_81;
} else {
if ( F_42 ( V_28 , V_82 , V_80 ) != 0 )
goto V_81;
}
if ( ( V_24 -> V_20 . V_44 & V_45 ) &&
F_25 ( V_2 , V_24 , V_34 , V_35 , V_28 ) < 0 )
goto V_81;
}
}
}
return 0 ;
V_81:
for ( V_34 = 0 ; V_34 < V_2 -> V_4 -> V_27 ; V_34 ++ ) {
if ( V_2 -> V_16 [ V_34 ] . V_61 != NULL ) {
F_36 ( V_2 -> V_16 [ V_34 ] . V_61 , V_2 -> V_75 ) ;
V_2 -> V_16 [ V_34 ] . V_61 = NULL ;
}
}
return - 1 ;
}
static int F_43 ( struct V_1 * V_2 , int V_77 , int V_65 )
{
struct V_11 * V_24 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_6 -> V_27 ; V_35 ++ ) {
int V_80 = - 1 ;
F_40 (evsel, &evlist->entries, node) {
int V_28 = F_41 ( V_24 , 0 , V_35 ) ;
if ( V_80 == - 1 ) {
V_80 = V_28 ;
if ( F_38 ( V_2 , V_35 ,
V_77 , V_65 , V_80 ) < 0 )
goto V_81;
} else {
if ( F_42 ( V_28 , V_82 , V_80 ) != 0 )
goto V_81;
}
if ( ( V_24 -> V_20 . V_44 & V_45 ) &&
F_25 ( V_2 , V_24 , 0 , V_35 , V_28 ) < 0 )
goto V_81;
}
}
return 0 ;
V_81:
for ( V_35 = 0 ; V_35 < V_2 -> V_6 -> V_27 ; V_35 ++ ) {
if ( V_2 -> V_16 [ V_35 ] . V_61 != NULL ) {
F_36 ( V_2 -> V_16 [ V_35 ] . V_61 , V_2 -> V_75 ) ;
V_2 -> V_16 [ V_35 ] . V_61 = NULL ;
}
}
return - 1 ;
}
int F_44 ( struct V_1 * V_2 , int V_83 , bool V_63 )
{
unsigned int V_54 = F_31 ( V_55 ) ;
int V_65 = V_83 * V_54 - 1 ;
struct V_11 * V_24 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
int V_77 = V_84 | ( V_63 ? 0 : V_85 ) ;
if ( V_2 -> V_16 == NULL && F_37 ( V_2 ) < 0 )
return - V_25 ;
if ( V_2 -> V_17 == NULL && F_17 ( V_2 ) < 0 )
return - V_25 ;
V_2 -> V_63 = V_63 ;
V_2 -> V_75 = ( V_83 + 1 ) * V_54 ;
F_40 (evsel, &evlist->entries, node) {
if ( ( V_24 -> V_20 . V_44 & V_45 ) &&
V_24 -> V_86 == NULL &&
F_45 ( V_24 , V_4 -> V_27 , V_6 -> V_27 ) < 0 )
return - V_25 ;
}
if ( V_2 -> V_4 -> V_76 [ 0 ] == - 1 )
return F_43 ( V_2 , V_77 , V_65 ) ;
return F_39 ( V_2 , V_77 , V_65 ) ;
}
int F_46 ( struct V_1 * V_2 , T_3 V_87 ,
T_3 V_88 , const char * V_89 )
{
V_2 -> V_6 = F_47 ( V_87 , V_88 ) ;
if ( V_2 -> V_6 == NULL )
return - 1 ;
if ( V_89 == NULL && V_88 != - 1 )
V_2 -> V_4 = F_48 () ;
else
V_2 -> V_4 = F_49 ( V_89 ) ;
if ( V_2 -> V_4 == NULL )
goto V_90;
return 0 ;
V_90:
F_50 ( V_2 -> V_6 ) ;
return - 1 ;
}
void F_51 ( struct V_1 * V_2 )
{
F_52 ( V_2 -> V_4 ) ;
F_50 ( V_2 -> V_6 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_6 = NULL ;
}
int F_53 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_2 -> V_6 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
struct V_11 * V_24 ;
char * V_91 ;
int V_35 ;
int V_34 ;
int V_92 ;
int V_28 ;
F_40 (evsel, &evlist->entries, node) {
V_91 = V_24 -> V_91 ;
if ( ! V_91 )
continue;
for ( V_34 = 0 ; V_34 < V_4 -> V_27 ; V_34 ++ ) {
for ( V_35 = 0 ; V_35 < V_6 -> V_27 ; V_35 ++ ) {
V_28 = F_41 ( V_24 , V_34 , V_35 ) ;
V_92 = F_42 ( V_28 , V_93 , V_91 ) ;
if ( V_92 )
return V_92 ;
}
}
}
return 0 ;
}
bool F_54 ( const struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_94 ;
V_12 = V_94 = F_28 ( V_2 -> V_10 . V_51 , struct V_11 , V_14 ) ;
F_55 (pos, &evlist->entries, node) {
if ( V_94 -> V_20 . V_95 != V_12 -> V_20 . V_95 )
return false ;
}
return true ;
}
T_1 F_56 ( const struct V_1 * V_2 )
{
struct V_11 * V_94 ;
V_94 = F_28 ( V_2 -> V_10 . V_51 , struct V_11 , V_14 ) ;
return V_94 -> V_20 . V_95 ;
}
bool F_57 ( const struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_94 ;
V_12 = V_94 = F_28 ( V_2 -> V_10 . V_51 , struct V_11 , V_14 ) ;
F_55 (pos, &evlist->entries, node) {
if ( V_94 -> V_20 . V_96 != V_12 -> V_20 . V_96 )
return false ;
}
return true ;
}
bool F_58 ( const struct V_1 * V_2 )
{
struct V_11 * V_94 ;
V_94 = F_28 ( V_2 -> V_10 . V_51 , struct V_11 , V_14 ) ;
return V_94 -> V_20 . V_96 ;
}
