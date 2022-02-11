void F_1 ( struct V_1 * * V_2 , char * V_1 )
{
struct V_1 * V_3 ;
F_2 (*labels, new)
if ( F_3 ( V_3 -> V_1 , V_1 ) )
return;
V_3 = xmalloc ( sizeof( * V_3 ) ) ;
V_3 -> V_1 = V_1 ;
V_3 -> V_4 = * V_2 ;
* V_2 = V_3 ;
}
struct V_5 * F_4 ( char * V_6 , struct V_7 V_8 )
{
struct V_5 * V_3 = xmalloc ( sizeof( * V_3 ) ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_8 = V_8 ;
return V_3 ;
}
struct V_5 * F_5 ( struct V_5 * V_9 , struct V_5 * V_10 )
{
assert ( V_9 -> V_4 == NULL ) ;
V_9 -> V_4 = V_10 ;
return V_9 ;
}
struct V_5 * F_6 ( struct V_5 * V_9 )
{
struct V_5 * V_11 = V_9 ;
struct V_5 * V_12 = NULL ;
struct V_5 * V_4 ;
while ( V_11 ) {
V_4 = V_11 -> V_4 ;
V_11 -> V_4 = V_12 ;
V_12 = V_11 ;
V_11 = V_4 ;
}
return V_12 ;
}
struct V_13 * F_7 ( struct V_5 * V_14 , struct V_13 * V_15 )
{
struct V_13 * V_3 = xmalloc ( sizeof( * V_3 ) ) ;
struct V_13 * V_16 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_14 = F_6 ( V_14 ) ;
V_3 -> V_15 = V_15 ;
F_8 (new, child) {
V_16 -> V_17 = V_3 ;
}
return V_3 ;
}
struct V_13 * F_9 ( struct V_13 * V_13 , char * V_6 )
{
assert ( V_13 -> V_6 == NULL ) ;
V_13 -> V_6 = V_6 ;
return V_13 ;
}
struct V_13 * F_10 ( struct V_13 * V_18 , struct V_13 * V_19 )
{
struct V_5 * V_20 , * V_21 ;
struct V_13 * V_22 , * V_23 ;
struct V_1 * V_24 ;
F_2 (new_node->labels, l)
F_1 ( & V_18 -> V_2 , V_24 -> V_1 ) ;
while ( V_19 -> V_14 ) {
V_20 = V_19 -> V_14 ;
V_19 -> V_14 = V_20 -> V_4 ;
V_20 -> V_4 = NULL ;
F_11 (old_node, old_prop) {
if ( F_3 ( V_21 -> V_6 , V_20 -> V_6 ) ) {
F_2 (new_prop->labels, l)
F_1 ( & V_21 -> V_2 , V_24 -> V_1 ) ;
V_21 -> V_8 = V_20 -> V_8 ;
free ( V_20 ) ;
V_20 = NULL ;
break;
}
}
if ( V_20 )
F_12 ( V_18 , V_20 ) ;
}
while ( V_19 -> V_15 ) {
V_22 = V_19 -> V_15 ;
V_19 -> V_15 = V_22 -> V_25 ;
V_22 -> V_17 = NULL ;
V_22 -> V_25 = NULL ;
F_8 (old_node, old_child) {
if ( F_3 ( V_23 -> V_6 , V_22 -> V_6 ) ) {
F_10 ( V_23 , V_22 ) ;
V_22 = NULL ;
break;
}
}
if ( V_22 )
F_13 ( V_18 , V_22 ) ;
}
free ( V_19 ) ;
return V_18 ;
}
struct V_13 * F_14 ( struct V_13 * V_9 , struct V_13 * V_10 )
{
assert ( V_9 -> V_25 == NULL ) ;
V_9 -> V_25 = V_10 ;
return V_9 ;
}
void F_12 ( struct V_13 * V_13 , struct V_5 * V_26 )
{
struct V_5 * * V_11 ;
V_26 -> V_4 = NULL ;
V_11 = & V_13 -> V_14 ;
while ( * V_11 )
V_11 = & ( ( * V_11 ) -> V_4 ) ;
* V_11 = V_26 ;
}
void F_13 ( struct V_13 * V_17 , struct V_13 * V_16 )
{
struct V_13 * * V_11 ;
V_16 -> V_25 = NULL ;
V_16 -> V_17 = V_17 ;
V_11 = & V_17 -> V_15 ;
while ( * V_11 )
V_11 = & ( ( * V_11 ) -> V_25 ) ;
* V_11 = V_16 ;
}
struct V_27 * F_15 ( T_1 V_28 , T_1 V_29 )
{
struct V_27 * V_3 = xmalloc ( sizeof( * V_3 ) ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_30 . V_28 = V_28 ;
V_3 -> V_30 . V_29 = V_29 ;
return V_3 ;
}
struct V_27 * F_16 ( struct V_27 * V_9 ,
struct V_27 * V_10 )
{
assert ( V_9 -> V_4 == NULL ) ;
V_9 -> V_4 = V_10 ;
return V_9 ;
}
struct V_27 * F_17 ( struct V_27 * V_10 ,
struct V_27 * V_3 )
{
struct V_27 * V_31 ;
V_3 -> V_4 = NULL ;
if ( ! V_10 )
return V_3 ;
for ( V_31 = V_10 ; V_31 -> V_4 ; V_31 = V_31 -> V_4 )
;
V_31 -> V_4 = V_3 ;
return V_10 ;
}
struct V_32 * F_18 ( struct V_27 * V_33 ,
struct V_13 * V_34 , T_2 V_35 )
{
struct V_32 * V_36 ;
V_36 = xmalloc ( sizeof( * V_36 ) ) ;
V_36 -> V_33 = V_33 ;
V_36 -> V_37 = V_34 ;
V_36 -> V_35 = V_35 ;
return V_36 ;
}
const char * F_19 ( struct V_13 * V_13 )
{
if ( V_13 -> V_6 [ V_13 -> V_38 ] == '\0' )
return L_1 ;
else
return V_13 -> V_6 + V_13 -> V_38 + 1 ;
}
struct V_5 * F_20 ( struct V_13 * V_13 , const char * V_39 )
{
struct V_5 * V_26 ;
F_11 (node, prop)
if ( F_3 ( V_26 -> V_6 , V_39 ) )
return V_26 ;
return NULL ;
}
T_3 F_21 ( struct V_5 * V_26 )
{
assert ( V_26 -> V_8 . V_40 == sizeof( T_3 ) ) ;
return F_22 ( * ( ( T_3 * ) V_26 -> V_8 . V_8 ) ) ;
}
struct V_5 * F_23 ( struct V_13 * V_34 , const char * V_1 ,
struct V_13 * * V_13 )
{
struct V_5 * V_26 ;
struct V_13 * V_41 ;
* V_13 = V_34 ;
F_11 (tree, prop) {
struct V_1 * V_24 ;
F_2 (prop->labels, l)
if ( F_3 ( V_24 -> V_1 , V_1 ) )
return V_26 ;
}
F_8 (tree, c) {
V_26 = F_23 ( V_41 , V_1 , V_13 ) ;
if ( V_26 )
return V_26 ;
}
* V_13 = NULL ;
return NULL ;
}
struct V_42 * F_24 ( struct V_13 * V_34 , const char * V_1 ,
struct V_13 * * V_13 , struct V_5 * * V_26 )
{
struct V_42 * V_43 ;
struct V_5 * V_11 ;
struct V_13 * V_41 ;
* V_13 = V_34 ;
F_11 (tree, p) {
* V_26 = V_11 ;
V_43 = V_11 -> V_8 . V_44 ;
F_25 (m, LABEL)
if ( F_3 ( V_43 -> V_45 , V_1 ) )
return V_43 ;
}
F_8 (tree, c) {
V_43 = F_24 ( V_41 , V_1 , V_13 , V_26 ) ;
if ( V_43 )
return V_43 ;
}
* V_26 = NULL ;
* V_13 = NULL ;
return NULL ;
}
struct V_13 * F_26 ( struct V_13 * V_13 , const char * V_46 )
{
struct V_13 * V_16 ;
F_8 (node, child)
if ( F_3 ( V_16 -> V_6 , V_46 ) )
return V_16 ;
return NULL ;
}
struct V_13 * F_27 ( struct V_13 * V_34 , const char * V_47 )
{
const char * V_11 ;
struct V_13 * V_16 ;
if ( ! V_47 || ! ( * V_47 ) )
return V_34 ;
while ( V_47 [ 0 ] == '/' )
V_47 ++ ;
V_11 = strchr ( V_47 , '/' ) ;
F_8 (tree, child) {
if ( V_11 && F_28 ( V_47 , V_16 -> V_6 , V_11 - V_47 ) )
return F_27 ( V_16 , V_11 + 1 ) ;
else if ( ! V_11 && F_3 ( V_47 , V_16 -> V_6 ) )
return V_16 ;
}
return NULL ;
}
struct V_13 * F_29 ( struct V_13 * V_34 , const char * V_1 )
{
struct V_13 * V_16 , * V_13 ;
struct V_1 * V_24 ;
assert ( V_1 && ( strlen ( V_1 ) > 0 ) ) ;
F_2 (tree->labels, l)
if ( F_3 ( V_24 -> V_1 , V_1 ) )
return V_34 ;
F_8 (tree, child) {
V_13 = F_29 ( V_16 , V_1 ) ;
if ( V_13 )
return V_13 ;
}
return NULL ;
}
struct V_13 * F_30 ( struct V_13 * V_34 , T_3 V_48 )
{
struct V_13 * V_16 , * V_13 ;
assert ( ( V_48 != 0 ) && ( V_48 != - 1 ) ) ;
if ( V_34 -> V_48 == V_48 )
return V_34 ;
F_8 (tree, child) {
V_13 = F_30 ( V_16 , V_48 ) ;
if ( V_13 )
return V_13 ;
}
return NULL ;
}
struct V_13 * F_31 ( struct V_13 * V_34 , const char * V_45 )
{
if ( V_45 [ 0 ] == '/' )
return F_27 ( V_34 , V_45 ) ;
else
return F_29 ( V_34 , V_45 ) ;
}
T_3 F_32 ( struct V_13 * V_49 , struct V_13 * V_13 )
{
static T_3 V_48 = 1 ;
if ( ( V_13 -> V_48 != 0 ) && ( V_13 -> V_48 != - 1 ) )
return V_13 -> V_48 ;
while ( F_30 ( V_49 , V_48 ) )
V_48 ++ ;
V_13 -> V_48 = V_48 ;
if ( ! F_20 ( V_13 , L_2 )
&& ( V_50 & V_51 ) )
F_12 ( V_13 ,
F_4 ( L_2 ,
F_33 ( V_52 , V_48 ) ) ) ;
if ( ! F_20 ( V_13 , L_3 )
&& ( V_50 & V_53 ) )
F_12 ( V_13 ,
F_4 ( L_3 ,
F_33 ( V_52 , V_48 ) ) ) ;
return V_13 -> V_48 ;
}
T_2 F_34 ( struct V_13 * V_34 )
{
struct V_13 * V_54 , * V_55 ;
struct V_5 * V_56 ;
V_54 = F_27 ( V_34 , L_4 ) ;
if ( ! V_54 )
return 0 ;
V_55 = V_54 -> V_15 ;
if ( ! V_55 )
return 0 ;
V_56 = F_20 ( V_55 , L_5 ) ;
if ( ! V_56 || ( V_56 -> V_8 . V_40 != sizeof( T_2 ) ) )
return 0 ;
return F_21 ( V_56 ) ;
}
static int F_35 ( const void * V_57 , const void * V_58 )
{
const struct V_27 * V_59 , * V_60 ;
V_59 = * ( ( const struct V_27 * const * ) V_57 ) ;
V_60 = * ( ( const struct V_27 * const * ) V_58 ) ;
if ( V_59 -> V_30 . V_28 < V_60 -> V_30 . V_28 )
return - 1 ;
else if ( V_59 -> V_30 . V_28 > V_60 -> V_30 . V_28 )
return 1 ;
else if ( V_59 -> V_30 . V_29 < V_60 -> V_30 . V_29 )
return - 1 ;
else if ( V_59 -> V_30 . V_29 > V_60 -> V_30 . V_29 )
return 1 ;
else
return 0 ;
}
static void F_36 ( struct V_32 * V_36 )
{
struct V_27 * V_61 , * * V_62 ;
int V_63 = 0 , V_64 = 0 ;
for ( V_61 = V_36 -> V_33 ;
V_61 ;
V_61 = V_61 -> V_4 )
V_63 ++ ;
if ( V_63 == 0 )
return;
V_62 = xmalloc ( V_63 * sizeof( * V_62 ) ) ;
for ( V_61 = V_36 -> V_33 ;
V_61 ;
V_61 = V_61 -> V_4 )
V_62 [ V_64 ++ ] = V_61 ;
qsort ( V_62 , V_63 , sizeof( * V_62 ) , F_35 ) ;
V_36 -> V_33 = V_62 [ 0 ] ;
for ( V_64 = 0 ; V_64 < ( V_63 - 1 ) ; V_64 ++ )
V_62 [ V_64 ] -> V_4 = V_62 [ V_64 + 1 ] ;
V_62 [ V_63 - 1 ] -> V_4 = NULL ;
free ( V_62 ) ;
}
static int F_37 ( const void * V_57 , const void * V_58 )
{
const struct V_5 * V_59 , * V_60 ;
V_59 = * ( ( const struct V_5 * const * ) V_57 ) ;
V_60 = * ( ( const struct V_5 * const * ) V_58 ) ;
return strcmp ( V_59 -> V_6 , V_60 -> V_6 ) ;
}
static void F_38 ( struct V_13 * V_13 )
{
int V_63 = 0 , V_64 = 0 ;
struct V_5 * V_26 , * * V_62 ;
F_11 (node, prop)
V_63 ++ ;
if ( V_63 == 0 )
return;
V_62 = xmalloc ( V_63 * sizeof( * V_62 ) ) ;
F_11 (node, prop)
V_62 [ V_64 ++ ] = V_26 ;
qsort ( V_62 , V_63 , sizeof( * V_62 ) , F_37 ) ;
V_13 -> V_14 = V_62 [ 0 ] ;
for ( V_64 = 0 ; V_64 < ( V_63 - 1 ) ; V_64 ++ )
V_62 [ V_64 ] -> V_4 = V_62 [ V_64 + 1 ] ;
V_62 [ V_63 - 1 ] -> V_4 = NULL ;
free ( V_62 ) ;
}
static int F_39 ( const void * V_57 , const void * V_58 )
{
const struct V_13 * V_59 , * V_60 ;
V_59 = * ( ( const struct V_13 * const * ) V_57 ) ;
V_60 = * ( ( const struct V_13 * const * ) V_58 ) ;
return strcmp ( V_59 -> V_6 , V_60 -> V_6 ) ;
}
static void F_40 ( struct V_13 * V_13 )
{
int V_63 = 0 , V_64 = 0 ;
struct V_13 * V_65 , * * V_62 ;
F_8 (node, subnode)
V_63 ++ ;
if ( V_63 == 0 )
return;
V_62 = xmalloc ( V_63 * sizeof( * V_62 ) ) ;
F_8 (node, subnode)
V_62 [ V_64 ++ ] = V_65 ;
qsort ( V_62 , V_63 , sizeof( * V_62 ) , F_39 ) ;
V_13 -> V_15 = V_62 [ 0 ] ;
for ( V_64 = 0 ; V_64 < ( V_63 - 1 ) ; V_64 ++ )
V_62 [ V_64 ] -> V_25 = V_62 [ V_64 + 1 ] ;
V_62 [ V_63 - 1 ] -> V_25 = NULL ;
free ( V_62 ) ;
}
static void F_41 ( struct V_13 * V_13 )
{
struct V_13 * V_41 ;
F_38 ( V_13 ) ;
F_40 ( V_13 ) ;
F_8 (node, c)
F_41 ( V_41 ) ;
}
void F_42 ( struct V_32 * V_36 )
{
F_36 ( V_36 ) ;
F_41 ( V_36 -> V_37 ) ;
}
