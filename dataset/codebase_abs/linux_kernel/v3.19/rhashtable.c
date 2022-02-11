int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 ( V_2 -> V_3 . V_5 ) ;
}
static void * F_2 ( const struct V_1 * V_2 , const struct V_6 * V_7 )
{
return ( void * ) V_7 - V_2 -> V_3 . V_8 ;
}
static T_1 F_3 ( const struct V_1 * V_2 , const void * V_9 ,
T_1 V_10 , T_1 V_11 )
{
T_1 V_12 ;
V_12 = V_2 -> V_3 . V_13 ( V_9 , V_10 , V_2 -> V_3 . V_14 ) ;
return V_12 & ( V_11 - 1 ) ;
}
T_1 F_4 ( const struct V_1 * V_2 , const void * V_9 , T_1 V_10 )
{
struct V_15 * V_16 = F_5 ( V_2 -> V_16 , V_2 ) ;
return F_3 ( V_2 , V_9 , V_10 , V_16 -> V_17 ) ;
}
static T_1 F_6 ( const struct V_1 * V_2 , const void * V_18 , T_1 V_11 )
{
if ( F_7 ( ! V_2 -> V_3 . V_19 ) ) {
T_1 V_12 ;
V_12 = V_2 -> V_3 . F_6 ( V_18 , V_2 -> V_3 . V_14 ) ;
return V_12 & ( V_11 - 1 ) ;
}
return F_3 ( V_2 , V_18 + V_2 -> V_3 . V_20 , V_2 -> V_3 . V_19 , V_11 ) ;
}
T_1 F_8 ( const struct V_1 * V_2 , void * V_18 )
{
struct V_15 * V_16 = F_5 ( V_2 -> V_16 , V_2 ) ;
return F_6 ( V_2 , V_18 , V_16 -> V_17 ) ;
}
static T_1 F_9 ( const struct V_1 * V_2 ,
const struct V_6 * V_7 , T_1 V_11 )
{
return F_6 ( V_2 , F_2 ( V_2 , V_7 ) , V_11 ) ;
}
static struct V_15 * F_10 ( T_2 V_21 )
{
struct V_15 * V_16 ;
T_2 V_17 ;
V_17 = sizeof( * V_16 ) + V_21 * sizeof( V_16 -> V_22 [ 0 ] ) ;
V_16 = F_11 ( V_17 , V_23 | V_24 ) ;
if ( V_16 == NULL )
V_16 = F_12 ( V_17 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_17 = V_21 ;
return V_16 ;
}
static void F_13 ( const struct V_15 * V_16 )
{
F_14 ( V_16 ) ;
}
bool F_15 ( const struct V_1 * V_2 , T_2 V_25 )
{
return V_2 -> V_26 > ( V_25 / 4 * 3 ) ;
}
bool F_16 ( const struct V_1 * V_2 , T_2 V_25 )
{
return V_2 -> V_26 < ( V_25 * 3 / 10 ) ;
}
static void F_17 ( const struct V_1 * V_2 ,
const struct V_15 * V_27 ,
struct V_15 * V_28 , T_2 V_29 )
{
struct V_6 * V_7 , * V_3 , * V_30 ;
unsigned int V_12 ;
V_3 = F_18 ( V_28 -> V_22 [ V_29 ] , V_2 ) ;
if ( ! V_3 )
return;
V_12 = F_9 ( V_2 , V_3 , V_27 -> V_17 ) ;
F_19 (he, p->next, ht) {
if ( F_9 ( V_2 , V_7 , V_27 -> V_17 ) != V_12 )
break;
V_3 = V_7 ;
}
F_20 ( V_28 -> V_22 [ V_29 ] , V_3 -> V_30 ) ;
V_30 = NULL ;
if ( V_7 ) {
F_19 (he, he->next, ht) {
if ( F_9 ( V_2 , V_7 , V_27 -> V_17 ) == V_12 ) {
V_30 = V_7 ;
break;
}
}
}
F_20 ( V_3 -> V_30 , V_30 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_15 * V_27 , * V_28 = F_18 ( V_2 -> V_16 , V_2 ) ;
struct V_6 * V_7 ;
unsigned int V_31 , V_12 ;
bool V_32 ;
F_22 ( V_2 ) ;
if ( V_2 -> V_3 . V_33 && V_2 -> V_34 >= V_2 -> V_3 . V_33 )
return 0 ;
V_27 = F_10 ( V_28 -> V_17 * 2 ) ;
if ( V_27 == NULL )
return - V_35 ;
V_2 -> V_34 ++ ;
for ( V_31 = 0 ; V_31 < V_27 -> V_17 ; V_31 ++ ) {
V_12 = V_31 & ( V_28 -> V_17 - 1 ) ;
F_19 (he, old_tbl->buckets[h], ht) {
if ( F_9 ( V_2 , V_7 , V_27 -> V_17 ) == V_31 ) {
F_20 ( V_27 -> V_22 [ V_31 ] , V_7 ) ;
break;
}
}
}
F_23 ( V_2 -> V_16 , V_27 ) ;
do {
F_24 () ;
V_32 = true ;
for ( V_31 = 0 ; V_31 < V_28 -> V_17 ; V_31 ++ ) {
F_17 ( V_2 , V_27 , V_28 , V_31 ) ;
if ( V_28 -> V_22 [ V_31 ] != NULL )
V_32 = false ;
}
} while ( ! V_32 );
F_13 ( V_28 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_15 * V_36 , * V_16 = F_18 ( V_2 -> V_16 , V_2 ) ;
struct V_6 T_3 * * V_37 ;
unsigned int V_31 ;
F_22 ( V_2 ) ;
if ( V_2 -> V_34 <= V_2 -> V_3 . V_38 )
return 0 ;
V_36 = F_10 ( V_16 -> V_17 / 2 ) ;
if ( V_36 == NULL )
return - V_35 ;
V_2 -> V_34 -- ;
for ( V_31 = 0 ; V_31 < V_36 -> V_17 ; V_31 ++ ) {
V_36 -> V_22 [ V_31 ] = V_16 -> V_22 [ V_31 ] ;
for ( V_37 = & V_36 -> V_22 [ V_31 ] ; * V_37 != NULL ;
V_37 = & F_18 ( * V_37 , V_2 ) -> V_30 )
;
F_20 ( * V_37 , V_16 -> V_22 [ V_31 + V_36 -> V_17 ] ) ;
}
F_23 ( V_2 -> V_16 , V_36 ) ;
F_24 () ;
F_13 ( V_16 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_2 , struct V_6 * V_39 )
{
struct V_15 * V_16 = F_18 ( V_2 -> V_16 , V_2 ) ;
T_1 V_40 ;
F_22 ( V_2 ) ;
V_40 = F_9 ( V_2 , V_39 , V_16 -> V_17 ) ;
F_20 ( V_39 -> V_30 , V_16 -> V_22 [ V_40 ] ) ;
F_23 ( V_16 -> V_22 [ V_40 ] , V_39 ) ;
V_2 -> V_26 ++ ;
if ( V_2 -> V_3 . V_41 && V_2 -> V_3 . V_41 ( V_2 , V_16 -> V_17 ) )
F_21 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 , struct V_6 * V_39 ,
struct V_6 T_3 * * V_37 )
{
struct V_15 * V_16 = F_18 ( V_2 -> V_16 , V_2 ) ;
F_22 ( V_2 ) ;
F_20 ( * V_37 , V_39 -> V_30 ) ;
V_2 -> V_26 -- ;
if ( V_2 -> V_3 . V_42 &&
V_2 -> V_3 . V_42 ( V_2 , V_16 -> V_17 ) )
F_25 ( V_2 ) ;
}
bool F_28 ( struct V_1 * V_2 , struct V_6 * V_39 )
{
struct V_15 * V_16 = F_18 ( V_2 -> V_16 , V_2 ) ;
struct V_6 T_3 * * V_37 ;
struct V_6 * V_7 ;
T_1 V_12 ;
F_22 ( V_2 ) ;
V_12 = F_9 ( V_2 , V_39 , V_16 -> V_17 ) ;
V_37 = & V_16 -> V_22 [ V_12 ] ;
F_19 (he, tbl->buckets[h], ht) {
if ( V_7 != V_39 ) {
V_37 = & V_7 -> V_30 ;
continue;
}
F_27 ( V_2 , V_7 , V_37 ) ;
return true ;
}
return false ;
}
void * F_29 ( const struct V_1 * V_2 , const void * V_9 )
{
const struct V_15 * V_16 = F_5 ( V_2 -> V_16 , V_2 ) ;
struct V_6 * V_7 ;
T_1 V_12 ;
F_30 ( ! V_2 -> V_3 . V_19 ) ;
V_12 = F_3 ( V_2 , V_9 , V_2 -> V_3 . V_19 , V_16 -> V_17 ) ;
F_31 (he, tbl->buckets[h], ht) {
if ( memcmp ( F_2 ( V_2 , V_7 ) + V_2 -> V_3 . V_20 , V_9 ,
V_2 -> V_3 . V_19 ) )
continue;
return ( void * ) V_7 - V_2 -> V_3 . V_8 ;
}
return NULL ;
}
void * F_32 ( const struct V_1 * V_2 , T_1 V_40 ,
bool (* F_33)( void * , void * ) , void * V_43 )
{
const struct V_15 * V_16 = F_5 ( V_2 -> V_16 , V_2 ) ;
struct V_6 * V_7 ;
if ( F_7 ( V_40 >= V_16 -> V_17 ) )
return NULL ;
F_31 (he, tbl->buckets[hash], ht) {
if ( ! F_33 ( F_2 ( V_2 , V_7 ) , V_43 ) )
continue;
return ( void * ) V_7 - V_2 -> V_3 . V_8 ;
}
return NULL ;
}
static T_2 F_34 ( struct V_44 * V_45 )
{
return F_35 ( F_36 ( V_45 -> V_46 * 4 / 3 ) ,
1UL << V_45 -> V_38 ) ;
}
int F_37 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_15 * V_16 ;
T_2 V_17 ;
V_17 = V_47 ;
if ( ( V_45 -> V_19 && ! V_45 -> V_13 ) ||
( ! V_45 -> V_19 && ! V_45 -> F_6 ) )
return - V_48 ;
V_45 -> V_38 = F_38 ( T_2 , V_45 -> V_38 ,
F_39 ( V_49 ) ) ;
if ( V_45 -> V_46 )
V_17 = F_34 ( V_45 ) ;
V_16 = F_10 ( V_17 ) ;
if ( V_16 == NULL )
return - V_35 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_34 = F_39 ( V_16 -> V_17 ) ;
memcpy ( & V_2 -> V_3 , V_45 , sizeof( * V_45 ) ) ;
F_20 ( V_2 -> V_16 , V_16 ) ;
if ( ! V_2 -> V_3 . V_14 )
F_40 ( & V_2 -> V_3 . V_14 , sizeof( V_2 -> V_3 . V_14 ) ) ;
return 0 ;
}
void F_41 ( const struct V_1 * V_2 )
{
F_13 ( V_2 -> V_16 ) ;
}
static int F_42 ( void * V_5 )
{
return 1 ;
}
static int T_4 F_43 ( struct V_1 * V_2 )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_50 * 2 ; V_31 ++ ) {
struct V_51 * V_39 ;
bool V_52 = ! ( V_31 % 2 ) ;
T_1 V_9 = V_31 ;
V_39 = F_29 ( V_2 , & V_9 ) ;
if ( V_52 && ! V_39 ) {
F_44 ( L_1 , V_9 ) ;
return - V_53 ;
} else if ( ! V_52 && V_39 ) {
F_44 ( L_2 ,
V_9 ) ;
return - V_54 ;
} else if ( V_52 && V_39 ) {
if ( V_39 -> V_18 != V_55 || V_39 -> V_56 != V_31 ) {
F_44 ( L_3 ,
V_39 -> V_18 , V_55 , V_39 -> V_56 , V_31 ) ;
return - V_48 ;
}
}
}
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , bool V_57 )
{
unsigned int V_58 , V_59 , V_31 , V_60 = 0 ;
struct V_51 * V_39 ;
struct V_15 * V_16 ;
V_16 = F_5 ( V_2 -> V_16 , V_2 ) ;
for ( V_31 = 0 ; V_31 < V_16 -> V_17 ; V_31 ++ ) {
V_59 = V_58 = 0 ;
if ( ! V_57 )
F_46 ( L_4 , V_31 , V_16 -> V_17 ) ;
F_47 (obj, tbl->buckets[i], node) {
V_58 ++ ;
V_60 ++ ;
if ( ! V_57 )
F_48 ( L_5 , V_39 ) ;
}
F_47 (obj, tbl->buckets[i], node)
V_59 ++ ;
if ( V_59 != V_58 )
F_44 ( L_6 ,
V_58 , V_59 ) ;
if ( ! V_57 )
F_48 ( L_7 ,
V_31 , V_16 -> V_22 [ V_31 ] , V_58 ) ;
}
F_46 ( L_8 ,
V_60 , V_2 -> V_26 , V_50 ) ;
if ( V_60 != V_2 -> V_26 || V_60 != V_50 )
F_44 ( L_9 ) ;
}
static int T_4 F_49 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_51 * V_39 , * V_30 ;
int V_61 ;
unsigned int V_31 ;
F_46 ( L_10 , V_50 ) ;
for ( V_31 = 0 ; V_31 < V_50 ; V_31 ++ ) {
struct V_51 * V_39 ;
V_39 = F_11 ( sizeof( * V_39 ) , V_23 ) ;
if ( ! V_39 ) {
V_61 = - V_35 ;
goto error;
}
V_39 -> V_18 = V_55 ;
V_39 -> V_56 = V_31 * 2 ;
F_26 ( V_2 , & V_39 -> V_62 ) ;
}
F_50 () ;
F_45 ( V_2 , true ) ;
F_43 ( V_2 ) ;
F_51 () ;
for ( V_31 = 0 ; V_31 < V_63 ; V_31 ++ ) {
F_46 ( L_11 , V_31 ) ;
F_21 ( V_2 ) ;
F_50 () ;
F_46 ( L_12 ) ;
F_43 ( V_2 ) ;
F_51 () ;
}
for ( V_31 = 0 ; V_31 < V_63 ; V_31 ++ ) {
F_46 ( L_13 , V_31 ) ;
F_25 ( V_2 ) ;
F_50 () ;
F_46 ( L_12 ) ;
F_43 ( V_2 ) ;
F_51 () ;
}
F_50 () ;
F_45 ( V_2 , true ) ;
F_51 () ;
F_46 ( L_14 , V_50 ) ;
for ( V_31 = 0 ; V_31 < V_50 ; V_31 ++ ) {
T_1 V_9 = V_31 * 2 ;
V_39 = F_29 ( V_2 , & V_9 ) ;
F_30 ( ! V_39 ) ;
F_28 ( V_2 , & V_39 -> V_62 ) ;
F_52 ( V_39 ) ;
}
return 0 ;
error:
V_16 = F_5 ( V_2 -> V_16 , V_2 ) ;
for ( V_31 = 0 ; V_31 < V_16 -> V_17 ; V_31 ++ )
F_53 (obj, next, tbl->buckets[i], ht, node)
F_52 ( V_39 ) ;
return V_61 ;
}
static int T_4 F_54 ( void )
{
struct V_1 V_2 ;
struct V_44 V_45 = {
. V_46 = V_64 ,
. V_8 = F_55 ( struct V_51 , V_62 ) ,
. V_20 = F_55 ( struct V_51 , V_56 ) ,
. V_19 = sizeof( int ) ,
. V_13 = V_65 ,
#ifdef F_56
. V_4 = & F_42 ,
#endif
. V_41 = F_15 ,
. V_42 = F_16 ,
} ;
int V_61 ;
F_46 ( L_15 ) ;
V_61 = F_37 ( & V_2 , & V_45 ) ;
if ( V_61 < 0 ) {
F_44 ( L_16 ,
V_61 ) ;
return V_61 ;
}
V_61 = F_49 ( & V_2 ) ;
F_41 ( & V_2 ) ;
return V_61 ;
}
