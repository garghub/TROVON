static unsigned int F_1 ( const struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
unsigned int V_5 ;
V_5 = F_2 ( V_2 -> V_2 , V_4 , V_6 ) ;
return V_5 & ( V_3 - 1 ) ;
}
static bool F_3 ( const struct V_7 * V_8 ,
const struct V_1 * V_9 ,
struct V_1 * V_2 )
{
const struct V_10 * V_11 = F_4 ( V_8 ) ;
const struct V_12 * V_13 = F_5 ( V_11 -> V_13 ) ;
const struct V_14 * V_15 ;
unsigned int V_5 ;
V_5 = F_1 ( V_9 , V_13 -> V_16 , V_8 -> V_17 ) ;
F_6 (he, tbl->buckets[h]) {
if ( F_7 ( & V_15 -> V_9 , V_9 , V_8 -> V_17 ) )
continue;
if ( V_8 -> V_18 & V_19 )
F_8 ( V_2 , V_15 -> V_2 ) ;
return true ;
}
return false ;
}
static void F_9 ( const struct V_12 * V_13 )
{
if ( F_10 ( V_13 ) )
F_11 ( V_13 ) ;
else
F_12 ( V_13 ) ;
}
static struct V_12 * F_13 ( unsigned int V_20 )
{
struct V_12 * V_13 ;
T_1 V_16 ;
V_16 = sizeof( * V_13 ) + V_20 * sizeof( V_13 -> V_21 [ 0 ] ) ;
V_13 = F_14 ( V_16 , V_22 | V_23 | V_24 ) ;
if ( V_13 == NULL )
V_13 = F_15 ( V_16 ) ;
if ( V_13 == NULL )
return NULL ;
V_13 -> V_16 = V_20 ;
return V_13 ;
}
static void F_16 ( const struct V_7 * V_8 ,
const struct V_12 * V_25 ,
struct V_12 * V_13 , unsigned int V_26 )
{
struct V_14 * V_15 , * V_27 , * V_28 ;
unsigned int V_5 ;
V_15 = F_17 ( V_13 -> V_21 [ V_26 ] ) ;
if ( V_15 == NULL )
return;
V_5 = F_1 ( & V_15 -> V_9 , V_25 -> V_16 , V_8 -> V_17 ) ;
V_27 = V_15 ;
F_18 (he, he->next) {
if ( F_1 ( & V_15 -> V_9 , V_25 -> V_16 , V_8 -> V_17 ) != V_5 )
break;
V_27 = V_15 ;
}
F_19 ( V_13 -> V_21 [ V_26 ] , V_27 -> V_28 ) ;
if ( V_15 == NULL )
return;
V_28 = NULL ;
F_18 (he, he->next) {
if ( F_1 ( & V_15 -> V_9 , V_25 -> V_16 , V_8 -> V_17 ) != V_5 )
continue;
V_28 = V_15 ;
break;
}
F_19 ( V_27 -> V_28 , V_28 ) ;
}
static int F_20 ( const struct V_7 * V_8 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_17 ( V_11 -> V_13 ) , * V_25 ;
struct V_14 * V_15 ;
unsigned int V_29 , V_5 ;
bool V_30 ;
V_25 = F_13 ( V_13 -> V_16 * 2 ) ;
if ( V_25 == NULL )
return - V_31 ;
for ( V_29 = 0 ; V_29 < V_25 -> V_16 ; V_29 ++ ) {
V_5 = V_29 < V_13 -> V_16 ? V_29 : V_29 - V_13 -> V_16 ;
F_18 (he, tbl->buckets[h]) {
if ( F_1 ( & V_15 -> V_9 , V_25 -> V_16 , V_8 -> V_17 ) != V_29 )
continue;
F_19 ( V_25 -> V_21 [ V_29 ] , V_15 ) ;
break;
}
}
V_25 -> V_32 = V_13 -> V_32 ;
F_21 ( V_11 -> V_13 , V_25 ) ;
do {
F_22 () ;
V_30 = true ;
for ( V_29 = 0 ; V_29 < V_13 -> V_16 ; V_29 ++ ) {
F_16 ( V_8 , V_25 , V_13 , V_29 ) ;
if ( V_13 -> V_21 [ V_29 ] != NULL )
V_30 = false ;
}
} while ( ! V_30 );
F_9 ( V_13 ) ;
return 0 ;
}
static int F_23 ( const struct V_7 * V_8 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_17 ( V_11 -> V_13 ) , * V_25 ;
struct V_14 T_2 * * V_33 ;
unsigned int V_29 ;
V_25 = F_13 ( V_13 -> V_16 / 2 ) ;
if ( V_25 == NULL )
return - V_31 ;
for ( V_29 = 0 ; V_29 < V_25 -> V_16 ; V_29 ++ ) {
V_25 -> V_21 [ V_29 ] = V_13 -> V_21 [ V_29 ] ;
for ( V_33 = & V_25 -> V_21 [ V_29 ] ; * V_33 != NULL ;
V_33 = & F_17 ( * V_33 ) -> V_28 )
;
F_19 ( * V_33 , V_13 -> V_21 [ V_29 + V_25 -> V_16 ] ) ;
}
V_25 -> V_32 = V_13 -> V_32 ;
F_21 ( V_11 -> V_13 , V_25 ) ;
F_22 () ;
F_9 ( V_13 ) ;
return 0 ;
}
static int F_24 ( const struct V_7 * V_8 ,
const struct V_34 * V_35 )
{
struct V_10 * V_11 = F_4 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_11 -> V_13 ) ;
struct V_14 * V_15 ;
unsigned int V_16 , V_5 ;
if ( V_35 -> V_18 != 0 )
return - V_36 ;
V_16 = sizeof( * V_15 ) ;
if ( V_8 -> V_18 & V_19 )
V_16 += sizeof( V_15 -> V_2 [ 0 ] ) ;
V_15 = F_14 ( V_16 , V_22 ) ;
if ( V_15 == NULL )
return - V_31 ;
F_8 ( & V_15 -> V_9 , & V_35 -> V_9 ) ;
if ( V_8 -> V_18 & V_19 )
F_8 ( V_15 -> V_2 , & V_35 -> V_2 ) ;
V_5 = F_1 ( & V_15 -> V_9 , V_13 -> V_16 , V_8 -> V_17 ) ;
F_19 ( V_15 -> V_28 , V_13 -> V_21 [ V_5 ] ) ;
F_21 ( V_13 -> V_21 [ V_5 ] , V_15 ) ;
V_13 -> V_32 ++ ;
if ( V_13 -> V_32 > V_13 -> V_16 / 4 * 3 )
F_20 ( V_8 , V_11 ) ;
return 0 ;
}
static void F_25 ( const struct V_7 * V_8 ,
struct V_14 * V_15 )
{
F_26 ( & V_15 -> V_9 , V_37 ) ;
if ( V_8 -> V_18 & V_19 )
F_26 ( V_15 -> V_2 , V_8 -> V_38 ) ;
F_12 ( V_15 ) ;
}
static void F_27 ( const struct V_7 * V_8 ,
const struct V_34 * V_35 )
{
struct V_10 * V_11 = F_4 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_11 -> V_13 ) ;
struct V_14 * V_15 , T_2 * * V_33 ;
V_33 = V_35 -> V_39 ;
V_15 = F_17 ( ( * V_33 ) ) ;
F_19 ( * V_33 , V_15 -> V_28 ) ;
F_22 () ;
F_12 ( V_15 ) ;
V_13 -> V_32 -- ;
if ( V_13 -> V_32 < V_13 -> V_16 * 3 / 10 &&
V_13 -> V_16 > V_40 )
F_23 ( V_8 , V_11 ) ;
}
static int F_28 ( const struct V_7 * V_8 , struct V_34 * V_35 )
{
const struct V_10 * V_11 = F_4 ( V_8 ) ;
const struct V_12 * V_13 = F_17 ( V_11 -> V_13 ) ;
struct V_14 T_2 * const * V_33 ;
struct V_14 * V_15 ;
unsigned int V_5 ;
V_5 = F_1 ( & V_35 -> V_9 , V_13 -> V_16 , V_8 -> V_17 ) ;
V_33 = & V_13 -> V_21 [ V_5 ] ;
F_18 (he, tbl->buckets[h]) {
if ( F_7 ( & V_15 -> V_9 , & V_35 -> V_9 , V_8 -> V_17 ) ) {
V_33 = & V_15 -> V_28 ;
continue;
}
V_35 -> V_39 = ( void * ) V_33 ;
V_35 -> V_18 = 0 ;
if ( V_8 -> V_18 & V_19 )
F_8 ( & V_35 -> V_2 , V_15 -> V_2 ) ;
return 0 ;
}
return - V_41 ;
}
static void F_29 ( const struct V_42 * V_43 , const struct V_7 * V_8 ,
struct V_44 * V_45 )
{
const struct V_10 * V_11 = F_4 ( V_8 ) ;
const struct V_12 * V_13 = F_17 ( V_11 -> V_13 ) ;
const struct V_14 * V_15 ;
struct V_34 V_35 ;
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_13 -> V_16 ; V_29 ++ ) {
F_18 (he, tbl->buckets[i]) {
if ( V_45 -> V_46 < V_45 -> V_47 )
goto V_48;
memcpy ( & V_35 . V_9 , & V_15 -> V_9 , sizeof( V_35 . V_9 ) ) ;
if ( V_8 -> V_18 & V_19 )
memcpy ( & V_35 . V_2 , V_15 -> V_2 , sizeof( V_35 . V_2 ) ) ;
V_35 . V_18 = 0 ;
V_45 -> V_49 = V_45 -> V_50 ( V_43 , V_8 , V_45 , & V_35 ) ;
if ( V_45 -> V_49 < 0 )
return;
V_48:
V_45 -> V_46 ++ ;
}
}
}
static unsigned int F_30 ( const struct V_51 * const V_52 [] )
{
return sizeof( struct V_10 ) ;
}
static int F_31 ( const struct V_7 * V_8 ,
const struct V_51 * const V_53 [] )
{
struct V_10 * V_11 = F_4 ( V_8 ) ;
struct V_12 * V_13 ;
if ( F_32 ( ! V_54 ) ) {
F_33 ( & V_6 , 4 ) ;
V_54 = true ;
}
V_13 = F_13 ( V_40 ) ;
if ( V_13 == NULL )
return - V_31 ;
F_19 ( V_11 -> V_13 , V_13 ) ;
return 0 ;
}
static void F_34 ( const struct V_7 * V_8 )
{
const struct V_10 * V_11 = F_4 ( V_8 ) ;
const struct V_12 * V_13 = F_17 ( V_11 -> V_13 ) ;
struct V_14 * V_15 , * V_28 ;
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_13 -> V_16 ; V_29 ++ ) {
for ( V_15 = F_17 ( V_13 -> V_21 [ V_29 ] ) ; V_15 != NULL ;
V_15 = V_28 ) {
V_28 = F_17 ( V_15 -> V_28 ) ;
F_25 ( V_8 , V_15 ) ;
}
}
F_12 ( V_13 ) ;
}
static int T_3 F_35 ( void )
{
return F_36 ( & V_55 ) ;
}
static void T_4 F_37 ( void )
{
F_38 ( & V_55 ) ;
}
