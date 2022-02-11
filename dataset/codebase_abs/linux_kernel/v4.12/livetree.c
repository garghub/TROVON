void F_1 ( struct V_1 * * V_2 , char * V_1 )
{
struct V_1 * V_3 ;
F_2 (*labels, new)
if ( F_3 ( V_3 -> V_1 , V_1 ) ) {
V_3 -> V_4 = 0 ;
return;
}
V_3 = xmalloc ( sizeof( * V_3 ) ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_1 = V_1 ;
V_3 -> V_5 = * V_2 ;
* V_2 = V_3 ;
}
void F_4 ( struct V_1 * * V_2 )
{
struct V_1 * V_1 ;
F_5 (*labels, label)
V_1 -> V_4 = 1 ;
}
struct V_6 * F_6 ( char * V_7 , struct V_8 V_9 )
{
struct V_6 * V_3 = xmalloc ( sizeof( * V_3 ) ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_7 = V_7 ;
V_3 -> V_9 = V_9 ;
return V_3 ;
}
struct V_6 * F_7 ( char * V_7 )
{
struct V_6 * V_3 = xmalloc ( sizeof( * V_3 ) ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_7 = V_7 ;
V_3 -> V_4 = 1 ;
return V_3 ;
}
struct V_6 * F_8 ( struct V_6 * V_10 , struct V_6 * V_11 )
{
assert ( V_10 -> V_5 == NULL ) ;
V_10 -> V_5 = V_11 ;
return V_10 ;
}
struct V_6 * F_9 ( struct V_6 * V_10 )
{
struct V_6 * V_12 = V_10 ;
struct V_6 * V_13 = NULL ;
struct V_6 * V_5 ;
while ( V_12 ) {
V_5 = V_12 -> V_5 ;
V_12 -> V_5 = V_13 ;
V_13 = V_12 ;
V_12 = V_5 ;
}
return V_13 ;
}
struct V_14 * F_10 ( struct V_6 * V_15 , struct V_14 * V_16 )
{
struct V_14 * V_3 = xmalloc ( sizeof( * V_3 ) ) ;
struct V_14 * V_17 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_15 = F_9 ( V_15 ) ;
V_3 -> V_16 = V_16 ;
F_11 (new, child) {
V_17 -> V_18 = V_3 ;
}
return V_3 ;
}
struct V_14 * F_12 ( void )
{
struct V_14 * V_3 = xmalloc ( sizeof( * V_3 ) ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_4 = 1 ;
return V_3 ;
}
struct V_14 * F_13 ( struct V_14 * V_14 , char * V_7 )
{
assert ( V_14 -> V_7 == NULL ) ;
V_14 -> V_7 = V_7 ;
return V_14 ;
}
struct V_14 * F_14 ( struct V_14 * V_19 , struct V_14 * V_20 )
{
struct V_6 * V_21 , * V_22 ;
struct V_14 * V_23 , * V_24 ;
struct V_1 * V_25 ;
V_19 -> V_4 = 0 ;
F_2 (new_node->labels, l)
F_1 ( & V_19 -> V_2 , V_25 -> V_1 ) ;
while ( V_20 -> V_15 ) {
V_21 = V_20 -> V_15 ;
V_20 -> V_15 = V_21 -> V_5 ;
V_21 -> V_5 = NULL ;
if ( V_21 -> V_4 ) {
F_15 ( V_19 , V_21 -> V_7 ) ;
free ( V_21 ) ;
continue;
}
F_16 (old_node, old_prop) {
if ( F_3 ( V_22 -> V_7 , V_21 -> V_7 ) ) {
F_2 (new_prop->labels, l)
F_1 ( & V_22 -> V_2 , V_25 -> V_1 ) ;
V_22 -> V_9 = V_21 -> V_9 ;
V_22 -> V_4 = 0 ;
free ( V_21 ) ;
V_21 = NULL ;
break;
}
}
if ( V_21 )
F_17 ( V_19 , V_21 ) ;
}
while ( V_20 -> V_16 ) {
V_23 = V_20 -> V_16 ;
V_20 -> V_16 = V_23 -> V_26 ;
V_23 -> V_18 = NULL ;
V_23 -> V_26 = NULL ;
if ( V_23 -> V_4 ) {
F_18 ( V_19 , V_23 -> V_7 ) ;
free ( V_23 ) ;
continue;
}
F_19 (old_node, old_child) {
if ( F_3 ( V_24 -> V_7 , V_23 -> V_7 ) ) {
F_14 ( V_24 , V_23 ) ;
V_23 = NULL ;
break;
}
}
if ( V_23 )
F_20 ( V_19 , V_23 ) ;
}
free ( V_20 ) ;
return V_19 ;
}
struct V_14 * F_21 ( struct V_14 * V_10 , struct V_14 * V_11 )
{
assert ( V_10 -> V_26 == NULL ) ;
V_10 -> V_26 = V_11 ;
return V_10 ;
}
void F_17 ( struct V_14 * V_14 , struct V_6 * V_27 )
{
struct V_6 * * V_12 ;
V_27 -> V_5 = NULL ;
V_12 = & V_14 -> V_15 ;
while ( * V_12 )
V_12 = & ( ( * V_12 ) -> V_5 ) ;
* V_12 = V_27 ;
}
void F_15 ( struct V_14 * V_14 , char * V_7 )
{
struct V_6 * V_27 = V_14 -> V_15 ;
while ( V_27 ) {
if ( F_3 ( V_27 -> V_7 , V_7 ) ) {
F_22 ( V_27 ) ;
return;
}
V_27 = V_27 -> V_5 ;
}
}
void F_22 ( struct V_6 * V_27 )
{
V_27 -> V_4 = 1 ;
F_4 ( & V_27 -> V_2 ) ;
}
void F_20 ( struct V_14 * V_18 , struct V_14 * V_17 )
{
struct V_14 * * V_12 ;
V_17 -> V_26 = NULL ;
V_17 -> V_18 = V_18 ;
V_12 = & V_18 -> V_16 ;
while ( * V_12 )
V_12 = & ( ( * V_12 ) -> V_26 ) ;
* V_12 = V_17 ;
}
void F_18 ( struct V_14 * V_18 , char * V_7 )
{
struct V_14 * V_14 = V_18 -> V_16 ;
while ( V_14 ) {
if ( F_3 ( V_14 -> V_7 , V_7 ) ) {
F_23 ( V_14 ) ;
return;
}
V_14 = V_14 -> V_26 ;
}
}
void F_23 ( struct V_14 * V_14 )
{
struct V_6 * V_27 ;
struct V_14 * V_17 ;
V_14 -> V_4 = 1 ;
F_11 (node, child)
F_23 ( V_17 ) ;
F_24 (node, prop)
F_22 ( V_27 ) ;
F_4 ( & V_14 -> V_2 ) ;
}
void F_25 ( struct V_14 * V_14 ,
char * V_7 , const void * V_8 , int V_28 )
{
struct V_8 V_29 ;
struct V_6 * V_12 ;
V_12 = F_26 ( V_14 , V_7 ) ;
if ( V_12 ) {
V_29 = F_27 ( V_12 -> V_9 , V_8 , V_28 ) ;
V_12 -> V_9 = V_29 ;
} else {
V_29 = F_27 ( V_30 , V_8 , V_28 ) ;
V_12 = F_6 ( V_7 , V_29 ) ;
F_17 ( V_14 , V_12 ) ;
}
}
struct V_31 * F_28 ( T_1 V_32 , T_1 V_33 )
{
struct V_31 * V_3 = xmalloc ( sizeof( * V_3 ) ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_32 = V_32 ;
V_3 -> V_33 = V_33 ;
return V_3 ;
}
struct V_31 * F_29 ( struct V_31 * V_10 ,
struct V_31 * V_11 )
{
assert ( V_10 -> V_5 == NULL ) ;
V_10 -> V_5 = V_11 ;
return V_10 ;
}
struct V_31 * F_30 ( struct V_31 * V_11 ,
struct V_31 * V_3 )
{
struct V_31 * V_34 ;
V_3 -> V_5 = NULL ;
if ( ! V_11 )
return V_3 ;
for ( V_34 = V_11 ; V_34 -> V_5 ; V_34 = V_34 -> V_5 )
;
V_34 -> V_5 = V_3 ;
return V_11 ;
}
struct V_35 * F_31 ( unsigned int V_36 ,
struct V_31 * V_37 ,
struct V_14 * V_38 , T_2 V_39 )
{
struct V_35 * V_40 ;
V_40 = xmalloc ( sizeof( * V_40 ) ) ;
V_40 -> V_36 = V_36 ;
V_40 -> V_37 = V_37 ;
V_40 -> V_41 = V_38 ;
V_40 -> V_39 = V_39 ;
return V_40 ;
}
const char * F_32 ( struct V_14 * V_14 )
{
if ( V_14 -> V_7 [ V_14 -> V_42 ] == '\0' )
return L_1 ;
else
return V_14 -> V_7 + V_14 -> V_42 + 1 ;
}
struct V_6 * F_26 ( struct V_14 * V_14 , const char * V_43 )
{
struct V_6 * V_27 ;
F_24 (node, prop)
if ( F_3 ( V_27 -> V_7 , V_43 ) )
return V_27 ;
return NULL ;
}
T_3 F_33 ( struct V_6 * V_27 )
{
assert ( V_27 -> V_9 . V_28 == sizeof( T_3 ) ) ;
return F_34 ( * ( ( V_44 * ) V_27 -> V_9 . V_9 ) ) ;
}
struct V_6 * F_35 ( struct V_14 * V_38 , const char * V_1 ,
struct V_14 * * V_14 )
{
struct V_6 * V_27 ;
struct V_14 * V_45 ;
* V_14 = V_38 ;
F_24 (tree, prop) {
struct V_1 * V_25 ;
F_5 (prop->labels, l)
if ( F_3 ( V_25 -> V_1 , V_1 ) )
return V_27 ;
}
F_11 (tree, c) {
V_27 = F_35 ( V_45 , V_1 , V_14 ) ;
if ( V_27 )
return V_27 ;
}
* V_14 = NULL ;
return NULL ;
}
struct V_46 * F_36 ( struct V_14 * V_38 , const char * V_1 ,
struct V_14 * * V_14 , struct V_6 * * V_27 )
{
struct V_46 * V_47 ;
struct V_6 * V_12 ;
struct V_14 * V_45 ;
* V_14 = V_38 ;
F_24 (tree, p) {
* V_27 = V_12 ;
V_47 = V_12 -> V_9 . V_48 ;
F_37 (m, LABEL)
if ( F_3 ( V_47 -> V_49 , V_1 ) )
return V_47 ;
}
F_11 (tree, c) {
V_47 = F_36 ( V_45 , V_1 , V_14 , V_27 ) ;
if ( V_47 )
return V_47 ;
}
* V_27 = NULL ;
* V_14 = NULL ;
return NULL ;
}
struct V_14 * F_38 ( struct V_14 * V_14 , const char * V_50 )
{
struct V_14 * V_17 ;
F_11 (node, child)
if ( F_3 ( V_17 -> V_7 , V_50 ) )
return V_17 ;
return NULL ;
}
struct V_14 * F_39 ( struct V_14 * V_38 , const char * V_51 )
{
const char * V_12 ;
struct V_14 * V_17 ;
if ( ! V_51 || ! ( * V_51 ) ) {
if ( V_38 -> V_4 )
return NULL ;
return V_38 ;
}
while ( V_51 [ 0 ] == '/' )
V_51 ++ ;
V_12 = strchr ( V_51 , '/' ) ;
F_11 (tree, child) {
if ( V_12 && F_40 ( V_51 , V_17 -> V_7 , V_12 - V_51 ) )
return F_39 ( V_17 , V_12 + 1 ) ;
else if ( ! V_12 && F_3 ( V_51 , V_17 -> V_7 ) )
return V_17 ;
}
return NULL ;
}
struct V_14 * F_41 ( struct V_14 * V_38 , const char * V_1 )
{
struct V_14 * V_17 , * V_14 ;
struct V_1 * V_25 ;
assert ( V_1 && ( strlen ( V_1 ) > 0 ) ) ;
F_5 (tree->labels, l)
if ( F_3 ( V_25 -> V_1 , V_1 ) )
return V_38 ;
F_11 (tree, child) {
V_14 = F_41 ( V_17 , V_1 ) ;
if ( V_14 )
return V_14 ;
}
return NULL ;
}
struct V_14 * F_42 ( struct V_14 * V_38 , T_3 V_52 )
{
struct V_14 * V_17 , * V_14 ;
assert ( ( V_52 != 0 ) && ( V_52 != - 1 ) ) ;
if ( V_38 -> V_52 == V_52 ) {
if ( V_38 -> V_4 )
return NULL ;
return V_38 ;
}
F_11 (tree, child) {
V_14 = F_42 ( V_17 , V_52 ) ;
if ( V_14 )
return V_14 ;
}
return NULL ;
}
struct V_14 * F_43 ( struct V_14 * V_38 , const char * V_49 )
{
if ( F_3 ( V_49 , L_2 ) )
return V_38 ;
else if ( V_49 [ 0 ] == '/' )
return F_39 ( V_38 , V_49 ) ;
else
return F_41 ( V_38 , V_49 ) ;
}
T_3 F_44 ( struct V_14 * V_53 , struct V_14 * V_14 )
{
static T_3 V_52 = 1 ;
if ( ( V_14 -> V_52 != 0 ) && ( V_14 -> V_52 != - 1 ) )
return V_14 -> V_52 ;
while ( F_42 ( V_53 , V_52 ) )
V_52 ++ ;
V_14 -> V_52 = V_52 ;
if ( ! F_26 ( V_14 , L_3 )
&& ( V_54 & V_55 ) )
F_17 ( V_14 ,
F_6 ( L_3 ,
F_45 ( V_30 , V_52 ) ) ) ;
if ( ! F_26 ( V_14 , L_4 )
&& ( V_54 & V_56 ) )
F_17 ( V_14 ,
F_6 ( L_4 ,
F_45 ( V_30 , V_52 ) ) ) ;
return V_14 -> V_52 ;
}
T_2 F_46 ( struct V_14 * V_38 )
{
struct V_14 * V_57 , * V_58 ;
struct V_6 * V_59 ;
V_57 = F_39 ( V_38 , L_5 ) ;
if ( ! V_57 )
return 0 ;
V_58 = V_57 -> V_16 ;
if ( ! V_58 )
return 0 ;
V_59 = F_26 ( V_58 , L_6 ) ;
if ( ! V_59 || ( V_59 -> V_9 . V_28 != sizeof( T_2 ) ) )
return 0 ;
return F_33 ( V_59 ) ;
}
static int F_47 ( const void * V_60 , const void * V_61 )
{
const struct V_31 * V_62 , * V_63 ;
V_62 = * ( ( const struct V_31 * const * ) V_60 ) ;
V_63 = * ( ( const struct V_31 * const * ) V_61 ) ;
if ( V_62 -> V_32 < V_63 -> V_32 )
return - 1 ;
else if ( V_62 -> V_32 > V_63 -> V_32 )
return 1 ;
else if ( V_62 -> V_33 < V_63 -> V_33 )
return - 1 ;
else if ( V_62 -> V_33 > V_63 -> V_33 )
return 1 ;
else
return 0 ;
}
static void F_48 ( struct V_35 * V_40 )
{
struct V_31 * V_64 , * * V_65 ;
int V_66 = 0 , V_67 = 0 ;
for ( V_64 = V_40 -> V_37 ;
V_64 ;
V_64 = V_64 -> V_5 )
V_66 ++ ;
if ( V_66 == 0 )
return;
V_65 = xmalloc ( V_66 * sizeof( * V_65 ) ) ;
for ( V_64 = V_40 -> V_37 ;
V_64 ;
V_64 = V_64 -> V_5 )
V_65 [ V_67 ++ ] = V_64 ;
qsort ( V_65 , V_66 , sizeof( * V_65 ) , F_47 ) ;
V_40 -> V_37 = V_65 [ 0 ] ;
for ( V_67 = 0 ; V_67 < ( V_66 - 1 ) ; V_67 ++ )
V_65 [ V_67 ] -> V_5 = V_65 [ V_67 + 1 ] ;
V_65 [ V_66 - 1 ] -> V_5 = NULL ;
free ( V_65 ) ;
}
static int F_49 ( const void * V_60 , const void * V_61 )
{
const struct V_6 * V_62 , * V_63 ;
V_62 = * ( ( const struct V_6 * const * ) V_60 ) ;
V_63 = * ( ( const struct V_6 * const * ) V_61 ) ;
return strcmp ( V_62 -> V_7 , V_63 -> V_7 ) ;
}
static void F_50 ( struct V_14 * V_14 )
{
int V_66 = 0 , V_67 = 0 ;
struct V_6 * V_27 , * * V_65 ;
F_16 (node, prop)
V_66 ++ ;
if ( V_66 == 0 )
return;
V_65 = xmalloc ( V_66 * sizeof( * V_65 ) ) ;
F_16 (node, prop)
V_65 [ V_67 ++ ] = V_27 ;
qsort ( V_65 , V_66 , sizeof( * V_65 ) , F_49 ) ;
V_14 -> V_15 = V_65 [ 0 ] ;
for ( V_67 = 0 ; V_67 < ( V_66 - 1 ) ; V_67 ++ )
V_65 [ V_67 ] -> V_5 = V_65 [ V_67 + 1 ] ;
V_65 [ V_66 - 1 ] -> V_5 = NULL ;
free ( V_65 ) ;
}
static int F_51 ( const void * V_60 , const void * V_61 )
{
const struct V_14 * V_62 , * V_63 ;
V_62 = * ( ( const struct V_14 * const * ) V_60 ) ;
V_63 = * ( ( const struct V_14 * const * ) V_61 ) ;
return strcmp ( V_62 -> V_7 , V_63 -> V_7 ) ;
}
static void F_52 ( struct V_14 * V_14 )
{
int V_66 = 0 , V_67 = 0 ;
struct V_14 * V_68 , * * V_65 ;
F_19 (node, subnode)
V_66 ++ ;
if ( V_66 == 0 )
return;
V_65 = xmalloc ( V_66 * sizeof( * V_65 ) ) ;
F_19 (node, subnode)
V_65 [ V_67 ++ ] = V_68 ;
qsort ( V_65 , V_66 , sizeof( * V_65 ) , F_51 ) ;
V_14 -> V_16 = V_65 [ 0 ] ;
for ( V_67 = 0 ; V_67 < ( V_66 - 1 ) ; V_67 ++ )
V_65 [ V_67 ] -> V_26 = V_65 [ V_67 + 1 ] ;
V_65 [ V_66 - 1 ] -> V_26 = NULL ;
free ( V_65 ) ;
}
static void F_53 ( struct V_14 * V_14 )
{
struct V_14 * V_45 ;
F_50 ( V_14 ) ;
F_52 ( V_14 ) ;
F_19 (node, c)
F_53 ( V_45 ) ;
}
void F_54 ( struct V_35 * V_40 )
{
F_48 ( V_40 ) ;
F_53 ( V_40 -> V_41 ) ;
}
static struct V_14 * F_55 ( struct V_14 * V_18 , char * V_7 )
{
struct V_14 * V_14 ;
V_14 = F_10 ( NULL , NULL ) ;
F_13 ( V_14 , F_56 ( V_7 ) ) ;
F_20 ( V_18 , V_14 ) ;
return V_14 ;
}
static struct V_14 * F_57 ( struct V_14 * V_41 , char * V_7 )
{
struct V_14 * V_69 ;
V_69 = F_38 ( V_41 , V_7 ) ;
if ( ! V_69 )
V_69 = F_55 ( V_41 , V_7 ) ;
if ( ! V_69 )
F_58 ( L_7 , V_7 ) ;
return V_69 ;
}
static bool F_59 ( struct V_35 * V_40 , struct V_14 * V_14 )
{
struct V_14 * V_45 ;
if ( V_14 -> V_2 )
return true ;
F_11 (node, c)
if ( F_59 ( V_40 , V_45 ) )
return true ;
return false ;
}
static void F_60 ( struct V_35 * V_40 ,
struct V_14 * V_69 , struct V_14 * V_14 ,
bool V_70 )
{
struct V_14 * V_41 = V_40 -> V_41 ;
struct V_14 * V_45 ;
struct V_6 * V_12 ;
struct V_1 * V_25 ;
if ( V_14 -> V_2 ) {
F_5 (node->labels, l) {
V_12 = F_26 ( V_69 , V_25 -> V_1 ) ;
if ( V_12 ) {
fprintf ( V_71 , L_8
L_9 , V_25 -> V_1 ,
V_69 -> V_7 ) ;
continue;
}
V_12 = F_6 ( V_25 -> V_1 ,
F_61 ( V_14 -> V_72 ,
strlen ( V_14 -> V_72 ) + 1 ) ) ;
F_17 ( V_69 , V_12 ) ;
}
if ( V_70 )
( void ) F_44 ( V_41 , V_14 ) ;
}
F_11 (node, c)
F_60 ( V_40 , V_69 , V_45 , V_70 ) ;
}
static bool F_62 ( struct V_35 * V_40 , struct V_14 * V_14 )
{
struct V_14 * V_45 ;
struct V_6 * V_27 ;
struct V_46 * V_47 ;
F_24 (node, prop) {
V_47 = V_27 -> V_9 . V_48 ;
F_37 (m, REF_PHANDLE) {
if ( ! F_43 ( V_40 -> V_41 , V_47 -> V_49 ) )
return true ;
}
}
F_11 (node, c) {
if ( F_62 ( V_40 , V_45 ) )
return true ;
}
return false ;
}
static void F_63 ( struct V_35 * V_40 , struct V_14 * V_73 ,
struct V_14 * V_14 , struct V_6 * V_27 ,
struct V_46 * V_47 )
{
char * V_74 ;
assert ( V_47 -> type == V_75 ) ;
if ( strchr ( V_14 -> V_72 , ':' ) || strchr ( V_27 -> V_7 , ':' ) )
F_58 ( L_10 ) ;
F_64 ( & V_74 , L_11 ,
V_14 -> V_72 , V_27 -> V_7 , V_47 -> V_76 ) ;
F_25 ( V_73 , V_47 -> V_49 , V_74 , strlen ( V_74 ) + 1 ) ;
free ( V_74 ) ;
}
static void F_65 ( struct V_35 * V_40 ,
struct V_14 * V_73 ,
struct V_14 * V_14 )
{
struct V_14 * V_41 = V_40 -> V_41 ;
struct V_14 * V_45 ;
struct V_6 * V_27 ;
struct V_46 * V_47 ;
struct V_14 * V_77 ;
F_24 (node, prop) {
V_47 = V_27 -> V_9 . V_48 ;
F_37 (m, REF_PHANDLE) {
V_77 = F_43 ( V_41 , V_47 -> V_49 ) ;
if ( ! V_77 )
F_63 ( V_40 , V_73 , V_14 , V_27 , V_47 ) ;
}
}
F_11 (node, c)
F_65 ( V_40 , V_73 , V_45 ) ;
}
static bool F_66 ( struct V_35 * V_40 , struct V_14 * V_14 )
{
struct V_14 * V_45 ;
struct V_6 * V_27 ;
struct V_46 * V_47 ;
F_24 (node, prop) {
V_47 = V_27 -> V_9 . V_48 ;
F_37 (m, REF_PHANDLE) {
if ( F_43 ( V_40 -> V_41 , V_47 -> V_49 ) )
return true ;
}
}
F_11 (node, c) {
if ( F_66 ( V_40 , V_45 ) )
return true ;
}
return false ;
}
static void F_67 ( struct V_35 * V_40 ,
struct V_14 * V_78 , struct V_14 * V_14 ,
struct V_6 * V_27 , struct V_46 * V_47 ,
struct V_14 * V_77 )
{
struct V_14 * V_79 , * V_80 ;
V_44 V_81 ;
char * * V_82 ;
int V_67 , V_83 ;
V_83 = 0 ;
for ( V_79 = V_14 ; V_79 ; V_79 = V_79 -> V_18 )
V_83 ++ ;
V_82 = xmalloc ( sizeof( * V_82 ) * V_83 ) ;
for ( V_79 = V_14 , V_67 = V_83 - 1 ; V_79 ; V_79 = V_79 -> V_18 , V_67 -- )
V_82 [ V_67 ] = V_79 -> V_7 ;
for ( V_79 = V_78 , V_67 = 1 ; V_67 < V_83 ; V_67 ++ , V_79 = V_80 ) {
V_80 = F_38 ( V_79 , V_82 [ V_67 ] ) ;
if ( ! V_80 )
V_80 = F_55 ( V_79 , V_82 [ V_67 ] ) ;
}
free ( V_82 ) ;
V_81 = F_68 ( V_47 -> V_76 ) ;
F_25 ( V_79 , V_27 -> V_7 , & V_81 , sizeof( V_81 ) ) ;
}
static void F_69 ( struct V_35 * V_40 ,
struct V_14 * V_78 ,
struct V_14 * V_14 )
{
struct V_14 * V_41 = V_40 -> V_41 ;
struct V_14 * V_45 ;
struct V_6 * V_27 ;
struct V_46 * V_47 ;
struct V_14 * V_77 ;
F_24 (node, prop) {
V_47 = V_27 -> V_9 . V_48 ;
F_37 (m, REF_PHANDLE) {
V_77 = F_43 ( V_41 , V_47 -> V_49 ) ;
if ( V_77 )
F_67 ( V_40 , V_78 , V_14 , V_27 , V_47 , V_77 ) ;
}
}
F_11 (node, c)
F_69 ( V_40 , V_78 , V_45 ) ;
}
void F_70 ( struct V_35 * V_40 , char * V_7 , bool V_70 )
{
if ( ! F_59 ( V_40 , V_40 -> V_41 ) )
return;
F_60 ( V_40 , F_57 ( V_40 -> V_41 , V_7 ) ,
V_40 -> V_41 , V_70 ) ;
}
void F_71 ( struct V_35 * V_40 , char * V_7 )
{
if ( ! F_62 ( V_40 , V_40 -> V_41 ) )
return;
F_65 ( V_40 , F_57 ( V_40 -> V_41 , V_7 ) ,
V_40 -> V_41 ) ;
}
void F_72 ( struct V_35 * V_40 , char * V_7 )
{
if ( ! F_66 ( V_40 , V_40 -> V_41 ) )
return;
F_69 ( V_40 , F_57 ( V_40 -> V_41 , V_7 ) ,
V_40 -> V_41 ) ;
}
