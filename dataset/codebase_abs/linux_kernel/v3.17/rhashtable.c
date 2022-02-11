int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 () ;
}
static void * F_2 ( const struct V_1 * V_2 , const struct V_5 * V_6 )
{
return ( void * ) V_6 - V_2 -> V_3 . V_7 ;
}
static T_1 F_3 ( const struct V_1 * V_2 , const void * V_8 ,
T_1 V_9 , T_1 V_10 )
{
T_1 V_11 ;
V_11 = V_2 -> V_3 . V_12 ( V_8 , V_9 , V_2 -> V_3 . V_13 ) ;
return V_11 & ( V_10 - 1 ) ;
}
T_1 F_4 ( const struct V_1 * V_2 , const void * V_8 , T_1 V_9 )
{
struct V_14 * V_15 = F_5 ( V_2 -> V_15 , V_2 ) ;
return F_3 ( V_2 , V_8 , V_9 , V_15 -> V_16 ) ;
}
static T_1 F_6 ( const struct V_1 * V_2 , const void * V_17 , T_1 V_10 )
{
if ( F_7 ( ! V_2 -> V_3 . V_18 ) ) {
T_1 V_11 ;
V_11 = V_2 -> V_3 . F_6 ( V_17 , V_2 -> V_3 . V_13 ) ;
return V_11 & ( V_10 - 1 ) ;
}
return F_3 ( V_2 , V_17 + V_2 -> V_3 . V_19 , V_2 -> V_3 . V_18 , V_10 ) ;
}
T_1 F_8 ( const struct V_1 * V_2 , void * V_17 )
{
struct V_14 * V_15 = F_5 ( V_2 -> V_15 , V_2 ) ;
return F_6 ( V_2 , V_17 , V_15 -> V_16 ) ;
}
static T_1 F_9 ( const struct V_1 * V_2 ,
const struct V_5 * V_6 , T_1 V_10 )
{
return F_6 ( V_2 , F_2 ( V_2 , V_6 ) , V_10 ) ;
}
static struct V_14 * F_10 ( T_2 V_20 , T_3 V_21 )
{
struct V_14 * V_15 ;
T_2 V_16 ;
V_16 = sizeof( * V_15 ) + V_20 * sizeof( V_15 -> V_22 [ 0 ] ) ;
V_15 = F_11 ( V_16 , V_21 ) ;
if ( V_15 == NULL )
V_15 = F_12 ( V_16 ) ;
if ( V_15 == NULL )
return NULL ;
V_15 -> V_16 = V_20 ;
return V_15 ;
}
static void F_13 ( const struct V_14 * V_15 )
{
F_14 ( V_15 ) ;
}
bool F_15 ( const struct V_1 * V_2 , T_2 V_23 )
{
return V_2 -> V_24 > ( V_23 / 4 * 3 ) ;
}
bool F_16 ( const struct V_1 * V_2 , T_2 V_23 )
{
return V_2 -> V_24 < ( V_23 * 3 / 10 ) ;
}
static void F_17 ( const struct V_1 * V_2 ,
const struct V_14 * V_25 ,
struct V_14 * V_26 , T_2 V_27 )
{
struct V_5 * V_6 , * V_3 , * V_28 ;
unsigned int V_11 ;
V_3 = F_18 ( V_26 -> V_22 [ V_27 ] , V_2 ) ;
if ( ! V_3 )
return;
V_11 = F_9 ( V_2 , V_3 , V_25 -> V_16 ) ;
F_19 (he, p->next, ht) {
if ( F_9 ( V_2 , V_6 , V_25 -> V_16 ) != V_11 )
break;
V_3 = V_6 ;
}
F_20 ( V_26 -> V_22 [ V_27 ] , V_3 -> V_28 ) ;
V_28 = NULL ;
if ( V_6 ) {
F_19 (he, he->next, ht) {
if ( F_9 ( V_2 , V_6 , V_25 -> V_16 ) == V_11 ) {
V_28 = V_6 ;
break;
}
}
}
F_20 ( V_3 -> V_28 , V_28 ) ;
}
int F_21 ( struct V_1 * V_2 , T_3 V_21 )
{
struct V_14 * V_25 , * V_26 = F_18 ( V_2 -> V_15 , V_2 ) ;
struct V_5 * V_6 ;
unsigned int V_29 , V_11 ;
bool V_30 ;
F_22 ( V_2 ) ;
if ( V_2 -> V_3 . V_31 && V_2 -> V_32 >= V_2 -> V_3 . V_31 )
return 0 ;
V_25 = F_10 ( V_26 -> V_16 * 2 , V_21 ) ;
if ( V_25 == NULL )
return - V_33 ;
V_2 -> V_32 ++ ;
for ( V_29 = 0 ; V_29 < V_25 -> V_16 ; V_29 ++ ) {
V_11 = V_29 & ( V_26 -> V_16 - 1 ) ;
F_19 (he, old_tbl->buckets[h], ht) {
if ( F_9 ( V_2 , V_6 , V_25 -> V_16 ) == V_29 ) {
F_20 ( V_25 -> V_22 [ V_29 ] , V_6 ) ;
break;
}
}
}
F_23 ( V_2 -> V_15 , V_25 ) ;
do {
F_24 () ;
V_30 = true ;
for ( V_29 = 0 ; V_29 < V_26 -> V_16 ; V_29 ++ ) {
F_17 ( V_2 , V_25 , V_26 , V_29 ) ;
if ( V_26 -> V_22 [ V_29 ] != NULL )
V_30 = false ;
}
} while ( ! V_30 );
F_13 ( V_26 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 , T_3 V_21 )
{
struct V_14 * V_34 , * V_15 = F_18 ( V_2 -> V_15 , V_2 ) ;
struct V_5 T_4 * * V_35 ;
unsigned int V_29 ;
F_22 ( V_2 ) ;
if ( V_15 -> V_16 <= V_36 )
return 0 ;
V_34 = F_10 ( V_15 -> V_16 / 2 , V_21 ) ;
if ( V_34 == NULL )
return - V_33 ;
V_2 -> V_32 -- ;
for ( V_29 = 0 ; V_29 < V_34 -> V_16 ; V_29 ++ ) {
V_34 -> V_22 [ V_29 ] = V_15 -> V_22 [ V_29 ] ;
for ( V_35 = & V_34 -> V_22 [ V_29 ] ; * V_35 != NULL ;
V_35 = & F_18 ( * V_35 , V_2 ) -> V_28 )
;
F_20 ( * V_35 , V_15 -> V_22 [ V_29 + V_34 -> V_16 ] ) ;
}
F_23 ( V_2 -> V_15 , V_34 ) ;
F_24 () ;
F_13 ( V_15 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_2 , struct V_5 * V_37 ,
T_3 V_21 )
{
struct V_14 * V_15 = F_18 ( V_2 -> V_15 , V_2 ) ;
T_1 V_38 ;
F_22 ( V_2 ) ;
V_38 = F_9 ( V_2 , V_37 , V_15 -> V_16 ) ;
F_20 ( V_37 -> V_28 , V_15 -> V_22 [ V_38 ] ) ;
F_23 ( V_15 -> V_22 [ V_38 ] , V_37 ) ;
V_2 -> V_24 ++ ;
if ( V_2 -> V_3 . V_39 && V_2 -> V_3 . V_39 ( V_2 , V_15 -> V_16 ) )
F_21 ( V_2 , V_21 ) ;
}
void F_27 ( struct V_1 * V_2 , struct V_5 * V_37 ,
struct V_5 T_4 * * V_35 , T_3 V_21 )
{
struct V_14 * V_15 = F_18 ( V_2 -> V_15 , V_2 ) ;
F_22 ( V_2 ) ;
F_20 ( * V_35 , V_37 -> V_28 ) ;
V_2 -> V_24 -- ;
if ( V_2 -> V_3 . V_40 &&
V_2 -> V_3 . V_40 ( V_2 , V_15 -> V_16 ) )
F_25 ( V_2 , V_21 ) ;
}
bool F_28 ( struct V_1 * V_2 , struct V_5 * V_37 ,
T_3 V_21 )
{
struct V_14 * V_15 = F_18 ( V_2 -> V_15 , V_2 ) ;
struct V_5 T_4 * * V_35 ;
struct V_5 * V_6 ;
T_1 V_11 ;
F_22 ( V_2 ) ;
V_11 = F_9 ( V_2 , V_37 , V_15 -> V_16 ) ;
V_35 = & V_15 -> V_22 [ V_11 ] ;
F_19 (he, tbl->buckets[h], ht) {
if ( V_6 != V_37 ) {
V_35 = & V_6 -> V_28 ;
continue;
}
F_27 ( V_2 , V_6 , V_35 , V_21 ) ;
return true ;
}
return false ;
}
void * F_29 ( const struct V_1 * V_2 , const void * V_8 )
{
const struct V_14 * V_15 = F_5 ( V_2 -> V_15 , V_2 ) ;
struct V_5 * V_6 ;
T_1 V_11 ;
F_30 ( ! V_2 -> V_3 . V_18 ) ;
V_11 = F_3 ( V_2 , V_8 , V_2 -> V_3 . V_18 , V_15 -> V_16 ) ;
F_31 (he, tbl->buckets[h], ht) {
if ( memcmp ( F_2 ( V_2 , V_6 ) + V_2 -> V_3 . V_19 , V_8 ,
V_2 -> V_3 . V_18 ) )
continue;
return ( void * ) V_6 - V_2 -> V_3 . V_7 ;
}
return NULL ;
}
void * F_32 ( const struct V_1 * V_2 , T_1 V_38 ,
bool (* F_33)( void * , void * ) , void * V_41 )
{
const struct V_14 * V_15 = F_5 ( V_2 -> V_15 , V_2 ) ;
struct V_5 * V_6 ;
if ( F_7 ( V_38 >= V_15 -> V_16 ) )
return NULL ;
F_31 (he, tbl->buckets[hash], ht) {
if ( ! F_33 ( F_2 ( V_2 , V_6 ) , V_41 ) )
continue;
return ( void * ) V_6 - V_2 -> V_3 . V_7 ;
}
return NULL ;
}
static T_2 F_34 ( unsigned int V_42 )
{
return F_35 ( F_36 ( V_42 * 4 / 3 ) , V_36 ) ;
}
int F_37 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_14 * V_15 ;
T_2 V_16 ;
V_16 = V_45 ;
if ( ( V_44 -> V_18 && ! V_44 -> V_12 ) ||
( ! V_44 -> V_18 && ! V_44 -> F_6 ) )
return - V_46 ;
if ( V_44 -> V_47 )
V_16 = F_34 ( V_44 -> V_47 ) ;
V_15 = F_10 ( V_16 , V_48 ) ;
if ( V_15 == NULL )
return - V_33 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_32 = F_38 ( V_15 -> V_16 ) ;
memcpy ( & V_2 -> V_3 , V_44 , sizeof( * V_44 ) ) ;
F_20 ( V_2 -> V_15 , V_15 ) ;
if ( ! V_2 -> V_3 . V_13 )
F_39 ( & V_2 -> V_3 . V_13 , sizeof( V_2 -> V_3 . V_13 ) ) ;
return 0 ;
}
void F_40 ( const struct V_1 * V_2 )
{
F_13 ( V_2 -> V_15 ) ;
}
static int F_41 ( void )
{
return 1 ;
}
static int T_5 F_42 ( struct V_1 * V_2 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_49 * 2 ; V_29 ++ ) {
struct V_50 * V_37 ;
bool V_51 = ! ( V_29 % 2 ) ;
T_1 V_8 = V_29 ;
V_37 = F_29 ( V_2 , & V_8 ) ;
if ( V_51 && ! V_37 ) {
F_43 ( L_1 , V_8 ) ;
return - V_52 ;
} else if ( ! V_51 && V_37 ) {
F_43 ( L_2 ,
V_8 ) ;
return - V_53 ;
} else if ( V_51 && V_37 ) {
if ( V_37 -> V_17 != V_54 || V_37 -> V_55 != V_29 ) {
F_43 ( L_3 ,
V_37 -> V_17 , V_54 , V_37 -> V_55 , V_29 ) ;
return - V_46 ;
}
}
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
bool V_56 )
{
unsigned int V_57 , V_29 , V_58 = 0 ;
struct V_50 * V_37 ;
for ( V_29 = 0 ; V_29 < V_15 -> V_16 ; V_29 ++ ) {
V_57 = 0 ;
if ( ! V_56 )
F_45 ( L_4 , V_29 , V_15 -> V_16 ) ;
F_46 (obj, tbl->buckets[i], node) {
V_57 ++ ;
V_58 ++ ;
if ( ! V_56 )
F_47 ( L_5 , V_37 ) ;
}
if ( ! V_56 )
F_47 ( L_6 ,
V_29 , V_15 -> V_22 [ V_29 ] , V_57 ) ;
}
F_45 ( L_7 ,
V_58 , V_2 -> V_24 , V_49 ) ;
}
static int T_5 F_48 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_50 * V_37 , * V_28 ;
int V_59 ;
unsigned int V_29 ;
F_45 ( L_8 , V_49 ) ;
for ( V_29 = 0 ; V_29 < V_49 ; V_29 ++ ) {
struct V_50 * V_37 ;
V_37 = F_11 ( sizeof( * V_37 ) , V_48 ) ;
if ( ! V_37 ) {
V_59 = - V_33 ;
goto error;
}
V_37 -> V_17 = V_54 ;
V_37 -> V_55 = V_29 * 2 ;
F_26 ( V_2 , & V_37 -> V_60 , V_48 ) ;
}
F_49 () ;
V_15 = F_5 ( V_2 -> V_15 , V_2 ) ;
F_44 ( V_2 , V_15 , true ) ;
F_42 ( V_2 ) ;
F_50 () ;
for ( V_29 = 0 ; V_29 < V_61 ; V_29 ++ ) {
F_45 ( L_9 , V_29 ) ;
F_21 ( V_2 , V_48 ) ;
F_49 () ;
F_45 ( L_10 ) ;
F_42 ( V_2 ) ;
F_50 () ;
}
for ( V_29 = 0 ; V_29 < V_61 ; V_29 ++ ) {
F_45 ( L_11 , V_29 ) ;
F_25 ( V_2 , V_48 ) ;
F_49 () ;
F_45 ( L_10 ) ;
F_42 ( V_2 ) ;
F_50 () ;
}
F_45 ( L_12 , V_49 ) ;
for ( V_29 = 0 ; V_29 < V_49 ; V_29 ++ ) {
T_1 V_8 = V_29 * 2 ;
V_37 = F_29 ( V_2 , & V_8 ) ;
F_30 ( ! V_37 ) ;
F_28 ( V_2 , & V_37 -> V_60 , V_48 ) ;
F_51 ( V_37 ) ;
}
return 0 ;
error:
V_15 = F_5 ( V_2 -> V_15 , V_2 ) ;
for ( V_29 = 0 ; V_29 < V_15 -> V_16 ; V_29 ++ )
F_52 (obj, next, tbl->buckets[i], ht, node)
F_51 ( V_37 ) ;
return V_59 ;
}
static int T_5 F_53 ( void )
{
struct V_1 V_2 ;
struct V_43 V_44 = {
. V_47 = V_62 ,
. V_7 = F_54 ( struct V_50 , V_60 ) ,
. V_19 = F_54 ( struct V_50 , V_55 ) ,
. V_18 = sizeof( int ) ,
. V_12 = V_63 ,
. V_4 = & F_41 ,
. V_39 = F_15 ,
. V_40 = F_16 ,
} ;
int V_59 ;
F_45 ( L_13 ) ;
V_59 = F_37 ( & V_2 , & V_44 ) ;
if ( V_59 < 0 ) {
F_43 ( L_14 ,
V_59 ) ;
return V_59 ;
}
V_59 = F_48 ( & V_2 ) ;
F_40 ( & V_2 ) ;
return V_59 ;
}
