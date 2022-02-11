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
if ( ! strcmp ( V_27 -> V_7 , V_7 ) ) {
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
if ( ! strcmp ( V_14 -> V_7 , V_7 ) ) {
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
struct V_28 * F_25 ( T_1 V_29 , T_1 V_30 )
{
struct V_28 * V_3 = xmalloc ( sizeof( * V_3 ) ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_31 . V_29 = V_29 ;
V_3 -> V_31 . V_30 = V_30 ;
return V_3 ;
}
struct V_28 * F_26 ( struct V_28 * V_10 ,
struct V_28 * V_11 )
{
assert ( V_10 -> V_5 == NULL ) ;
V_10 -> V_5 = V_11 ;
return V_10 ;
}
struct V_28 * F_27 ( struct V_28 * V_11 ,
struct V_28 * V_3 )
{
struct V_28 * V_32 ;
V_3 -> V_5 = NULL ;
if ( ! V_11 )
return V_3 ;
for ( V_32 = V_11 ; V_32 -> V_5 ; V_32 = V_32 -> V_5 )
;
V_32 -> V_5 = V_3 ;
return V_11 ;
}
struct V_33 * F_28 ( struct V_28 * V_34 ,
struct V_14 * V_35 , T_2 V_36 )
{
struct V_33 * V_37 ;
V_37 = xmalloc ( sizeof( * V_37 ) ) ;
V_37 -> V_34 = V_34 ;
V_37 -> V_38 = V_35 ;
V_37 -> V_36 = V_36 ;
return V_37 ;
}
const char * F_29 ( struct V_14 * V_14 )
{
if ( V_14 -> V_7 [ V_14 -> V_39 ] == '\0' )
return L_1 ;
else
return V_14 -> V_7 + V_14 -> V_39 + 1 ;
}
struct V_6 * F_30 ( struct V_14 * V_14 , const char * V_40 )
{
struct V_6 * V_27 ;
F_24 (node, prop)
if ( F_3 ( V_27 -> V_7 , V_40 ) )
return V_27 ;
return NULL ;
}
T_3 F_31 ( struct V_6 * V_27 )
{
assert ( V_27 -> V_9 . V_41 == sizeof( T_3 ) ) ;
return F_32 ( * ( ( T_3 * ) V_27 -> V_9 . V_9 ) ) ;
}
struct V_6 * F_33 ( struct V_14 * V_35 , const char * V_1 ,
struct V_14 * * V_14 )
{
struct V_6 * V_27 ;
struct V_14 * V_42 ;
* V_14 = V_35 ;
F_24 (tree, prop) {
struct V_1 * V_25 ;
F_5 (prop->labels, l)
if ( F_3 ( V_25 -> V_1 , V_1 ) )
return V_27 ;
}
F_11 (tree, c) {
V_27 = F_33 ( V_42 , V_1 , V_14 ) ;
if ( V_27 )
return V_27 ;
}
* V_14 = NULL ;
return NULL ;
}
struct V_43 * F_34 ( struct V_14 * V_35 , const char * V_1 ,
struct V_14 * * V_14 , struct V_6 * * V_27 )
{
struct V_43 * V_44 ;
struct V_6 * V_12 ;
struct V_14 * V_42 ;
* V_14 = V_35 ;
F_24 (tree, p) {
* V_27 = V_12 ;
V_44 = V_12 -> V_9 . V_45 ;
F_35 (m, LABEL)
if ( F_3 ( V_44 -> V_46 , V_1 ) )
return V_44 ;
}
F_11 (tree, c) {
V_44 = F_34 ( V_42 , V_1 , V_14 , V_27 ) ;
if ( V_44 )
return V_44 ;
}
* V_27 = NULL ;
* V_14 = NULL ;
return NULL ;
}
struct V_14 * F_36 ( struct V_14 * V_14 , const char * V_47 )
{
struct V_14 * V_17 ;
F_11 (node, child)
if ( F_3 ( V_17 -> V_7 , V_47 ) )
return V_17 ;
return NULL ;
}
struct V_14 * F_37 ( struct V_14 * V_35 , const char * V_48 )
{
const char * V_12 ;
struct V_14 * V_17 ;
if ( ! V_48 || ! ( * V_48 ) ) {
if ( V_35 -> V_4 )
return NULL ;
return V_35 ;
}
while ( V_48 [ 0 ] == '/' )
V_48 ++ ;
V_12 = strchr ( V_48 , '/' ) ;
F_11 (tree, child) {
if ( V_12 && F_38 ( V_48 , V_17 -> V_7 , V_12 - V_48 ) )
return F_37 ( V_17 , V_12 + 1 ) ;
else if ( ! V_12 && F_3 ( V_48 , V_17 -> V_7 ) )
return V_17 ;
}
return NULL ;
}
struct V_14 * F_39 ( struct V_14 * V_35 , const char * V_1 )
{
struct V_14 * V_17 , * V_14 ;
struct V_1 * V_25 ;
assert ( V_1 && ( strlen ( V_1 ) > 0 ) ) ;
F_5 (tree->labels, l)
if ( F_3 ( V_25 -> V_1 , V_1 ) )
return V_35 ;
F_11 (tree, child) {
V_14 = F_39 ( V_17 , V_1 ) ;
if ( V_14 )
return V_14 ;
}
return NULL ;
}
struct V_14 * F_40 ( struct V_14 * V_35 , T_3 V_49 )
{
struct V_14 * V_17 , * V_14 ;
assert ( ( V_49 != 0 ) && ( V_49 != - 1 ) ) ;
if ( V_35 -> V_49 == V_49 ) {
if ( V_35 -> V_4 )
return NULL ;
return V_35 ;
}
F_11 (tree, child) {
V_14 = F_40 ( V_17 , V_49 ) ;
if ( V_14 )
return V_14 ;
}
return NULL ;
}
struct V_14 * F_41 ( struct V_14 * V_35 , const char * V_46 )
{
if ( F_3 ( V_46 , L_2 ) )
return V_35 ;
else if ( V_46 [ 0 ] == '/' )
return F_37 ( V_35 , V_46 ) ;
else
return F_39 ( V_35 , V_46 ) ;
}
T_3 F_42 ( struct V_14 * V_50 , struct V_14 * V_14 )
{
static T_3 V_49 = 1 ;
if ( ( V_14 -> V_49 != 0 ) && ( V_14 -> V_49 != - 1 ) )
return V_14 -> V_49 ;
while ( F_40 ( V_50 , V_49 ) )
V_49 ++ ;
V_14 -> V_49 = V_49 ;
if ( ! F_30 ( V_14 , L_3 )
&& ( V_51 & V_52 ) )
F_17 ( V_14 ,
F_6 ( L_3 ,
F_43 ( V_53 , V_49 ) ) ) ;
if ( ! F_30 ( V_14 , L_4 )
&& ( V_51 & V_54 ) )
F_17 ( V_14 ,
F_6 ( L_4 ,
F_43 ( V_53 , V_49 ) ) ) ;
return V_14 -> V_49 ;
}
T_2 F_44 ( struct V_14 * V_35 )
{
struct V_14 * V_55 , * V_56 ;
struct V_6 * V_57 ;
V_55 = F_37 ( V_35 , L_5 ) ;
if ( ! V_55 )
return 0 ;
V_56 = V_55 -> V_16 ;
if ( ! V_56 )
return 0 ;
V_57 = F_30 ( V_56 , L_6 ) ;
if ( ! V_57 || ( V_57 -> V_9 . V_41 != sizeof( T_2 ) ) )
return 0 ;
return F_31 ( V_57 ) ;
}
static int F_45 ( const void * V_58 , const void * V_59 )
{
const struct V_28 * V_60 , * V_61 ;
V_60 = * ( ( const struct V_28 * const * ) V_58 ) ;
V_61 = * ( ( const struct V_28 * const * ) V_59 ) ;
if ( V_60 -> V_31 . V_29 < V_61 -> V_31 . V_29 )
return - 1 ;
else if ( V_60 -> V_31 . V_29 > V_61 -> V_31 . V_29 )
return 1 ;
else if ( V_60 -> V_31 . V_30 < V_61 -> V_31 . V_30 )
return - 1 ;
else if ( V_60 -> V_31 . V_30 > V_61 -> V_31 . V_30 )
return 1 ;
else
return 0 ;
}
static void F_46 ( struct V_33 * V_37 )
{
struct V_28 * V_62 , * * V_63 ;
int V_64 = 0 , V_65 = 0 ;
for ( V_62 = V_37 -> V_34 ;
V_62 ;
V_62 = V_62 -> V_5 )
V_64 ++ ;
if ( V_64 == 0 )
return;
V_63 = xmalloc ( V_64 * sizeof( * V_63 ) ) ;
for ( V_62 = V_37 -> V_34 ;
V_62 ;
V_62 = V_62 -> V_5 )
V_63 [ V_65 ++ ] = V_62 ;
qsort ( V_63 , V_64 , sizeof( * V_63 ) , F_45 ) ;
V_37 -> V_34 = V_63 [ 0 ] ;
for ( V_65 = 0 ; V_65 < ( V_64 - 1 ) ; V_65 ++ )
V_63 [ V_65 ] -> V_5 = V_63 [ V_65 + 1 ] ;
V_63 [ V_64 - 1 ] -> V_5 = NULL ;
free ( V_63 ) ;
}
static int F_47 ( const void * V_58 , const void * V_59 )
{
const struct V_6 * V_60 , * V_61 ;
V_60 = * ( ( const struct V_6 * const * ) V_58 ) ;
V_61 = * ( ( const struct V_6 * const * ) V_59 ) ;
return strcmp ( V_60 -> V_7 , V_61 -> V_7 ) ;
}
static void F_48 ( struct V_14 * V_14 )
{
int V_64 = 0 , V_65 = 0 ;
struct V_6 * V_27 , * * V_63 ;
F_16 (node, prop)
V_64 ++ ;
if ( V_64 == 0 )
return;
V_63 = xmalloc ( V_64 * sizeof( * V_63 ) ) ;
F_16 (node, prop)
V_63 [ V_65 ++ ] = V_27 ;
qsort ( V_63 , V_64 , sizeof( * V_63 ) , F_47 ) ;
V_14 -> V_15 = V_63 [ 0 ] ;
for ( V_65 = 0 ; V_65 < ( V_64 - 1 ) ; V_65 ++ )
V_63 [ V_65 ] -> V_5 = V_63 [ V_65 + 1 ] ;
V_63 [ V_64 - 1 ] -> V_5 = NULL ;
free ( V_63 ) ;
}
static int F_49 ( const void * V_58 , const void * V_59 )
{
const struct V_14 * V_60 , * V_61 ;
V_60 = * ( ( const struct V_14 * const * ) V_58 ) ;
V_61 = * ( ( const struct V_14 * const * ) V_59 ) ;
return strcmp ( V_60 -> V_7 , V_61 -> V_7 ) ;
}
static void F_50 ( struct V_14 * V_14 )
{
int V_64 = 0 , V_65 = 0 ;
struct V_14 * V_66 , * * V_63 ;
F_19 (node, subnode)
V_64 ++ ;
if ( V_64 == 0 )
return;
V_63 = xmalloc ( V_64 * sizeof( * V_63 ) ) ;
F_19 (node, subnode)
V_63 [ V_65 ++ ] = V_66 ;
qsort ( V_63 , V_64 , sizeof( * V_63 ) , F_49 ) ;
V_14 -> V_16 = V_63 [ 0 ] ;
for ( V_65 = 0 ; V_65 < ( V_64 - 1 ) ; V_65 ++ )
V_63 [ V_65 ] -> V_26 = V_63 [ V_65 + 1 ] ;
V_63 [ V_64 - 1 ] -> V_26 = NULL ;
free ( V_63 ) ;
}
static void F_51 ( struct V_14 * V_14 )
{
struct V_14 * V_42 ;
F_48 ( V_14 ) ;
F_50 ( V_14 ) ;
F_19 (node, c)
F_51 ( V_42 ) ;
}
void F_52 ( struct V_33 * V_37 )
{
F_46 ( V_37 ) ;
F_51 ( V_37 -> V_38 ) ;
}
