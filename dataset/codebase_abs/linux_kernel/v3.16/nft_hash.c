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
F_10 ( V_13 ) ;
}
static unsigned int F_11 ( unsigned int V_20 )
{
return F_12 ( F_13 ( V_20 * 4 / 3 ) , V_21 ) ;
}
static struct V_12 * F_14 ( unsigned int V_22 )
{
struct V_12 * V_13 ;
T_1 V_16 ;
V_16 = sizeof( * V_13 ) + V_22 * sizeof( V_13 -> V_23 [ 0 ] ) ;
V_13 = F_15 ( V_16 , V_24 | V_25 | V_26 ) ;
if ( V_13 == NULL )
V_13 = F_16 ( V_16 ) ;
if ( V_13 == NULL )
return NULL ;
V_13 -> V_16 = V_22 ;
return V_13 ;
}
static void F_17 ( const struct V_7 * V_8 ,
const struct V_12 * V_27 ,
struct V_12 * V_13 , unsigned int V_28 )
{
struct V_14 * V_15 , * V_29 , * V_30 ;
unsigned int V_5 ;
V_15 = F_18 ( V_13 -> V_23 [ V_28 ] ) ;
if ( V_15 == NULL )
return;
V_5 = F_1 ( & V_15 -> V_9 , V_27 -> V_16 , V_8 -> V_17 ) ;
V_29 = V_15 ;
F_19 (he, he->next) {
if ( F_1 ( & V_15 -> V_9 , V_27 -> V_16 , V_8 -> V_17 ) != V_5 )
break;
V_29 = V_15 ;
}
F_20 ( V_13 -> V_23 [ V_28 ] , V_29 -> V_30 ) ;
if ( V_15 == NULL )
return;
V_30 = NULL ;
F_19 (he, he->next) {
if ( F_1 ( & V_15 -> V_9 , V_27 -> V_16 , V_8 -> V_17 ) != V_5 )
continue;
V_30 = V_15 ;
break;
}
F_20 ( V_29 -> V_30 , V_30 ) ;
}
static int F_21 ( const struct V_7 * V_8 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_18 ( V_11 -> V_13 ) , * V_27 ;
struct V_14 * V_15 ;
unsigned int V_31 , V_5 ;
bool V_32 ;
V_27 = F_14 ( V_13 -> V_16 * 2 ) ;
if ( V_27 == NULL )
return - V_33 ;
for ( V_31 = 0 ; V_31 < V_27 -> V_16 ; V_31 ++ ) {
V_5 = V_31 < V_13 -> V_16 ? V_31 : V_31 - V_13 -> V_16 ;
F_19 (he, tbl->buckets[h]) {
if ( F_1 ( & V_15 -> V_9 , V_27 -> V_16 , V_8 -> V_17 ) != V_31 )
continue;
F_20 ( V_27 -> V_23 [ V_31 ] , V_15 ) ;
break;
}
}
F_22 ( V_11 -> V_13 , V_27 ) ;
do {
F_23 () ;
V_32 = true ;
for ( V_31 = 0 ; V_31 < V_13 -> V_16 ; V_31 ++ ) {
F_17 ( V_8 , V_27 , V_13 , V_31 ) ;
if ( V_13 -> V_23 [ V_31 ] != NULL )
V_32 = false ;
}
} while ( ! V_32 );
F_9 ( V_13 ) ;
return 0 ;
}
static int F_24 ( const struct V_7 * V_8 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_18 ( V_11 -> V_13 ) , * V_27 ;
struct V_14 T_2 * * V_34 ;
unsigned int V_31 ;
V_27 = F_14 ( V_13 -> V_16 / 2 ) ;
if ( V_27 == NULL )
return - V_33 ;
for ( V_31 = 0 ; V_31 < V_27 -> V_16 ; V_31 ++ ) {
V_27 -> V_23 [ V_31 ] = V_13 -> V_23 [ V_31 ] ;
for ( V_34 = & V_27 -> V_23 [ V_31 ] ; * V_34 != NULL ;
V_34 = & F_18 ( * V_34 ) -> V_30 )
;
F_20 ( * V_34 , V_13 -> V_23 [ V_31 + V_27 -> V_16 ] ) ;
}
F_22 ( V_11 -> V_13 , V_27 ) ;
F_23 () ;
F_9 ( V_13 ) ;
return 0 ;
}
static int F_25 ( const struct V_7 * V_8 ,
const struct V_35 * V_36 )
{
struct V_10 * V_11 = F_4 ( V_8 ) ;
struct V_12 * V_13 = F_18 ( V_11 -> V_13 ) ;
struct V_14 * V_15 ;
unsigned int V_16 , V_5 ;
if ( V_36 -> V_18 != 0 )
return - V_37 ;
V_16 = sizeof( * V_15 ) ;
if ( V_8 -> V_18 & V_19 )
V_16 += sizeof( V_15 -> V_2 [ 0 ] ) ;
V_15 = F_15 ( V_16 , V_24 ) ;
if ( V_15 == NULL )
return - V_33 ;
F_8 ( & V_15 -> V_9 , & V_36 -> V_9 ) ;
if ( V_8 -> V_18 & V_19 )
F_8 ( V_15 -> V_2 , & V_36 -> V_2 ) ;
V_5 = F_1 ( & V_15 -> V_9 , V_13 -> V_16 , V_8 -> V_17 ) ;
F_20 ( V_15 -> V_30 , V_13 -> V_23 [ V_5 ] ) ;
F_22 ( V_13 -> V_23 [ V_5 ] , V_15 ) ;
if ( V_8 -> V_38 + 1 > V_13 -> V_16 / 4 * 3 )
F_21 ( V_8 , V_11 ) ;
return 0 ;
}
static void F_26 ( const struct V_7 * V_8 ,
struct V_14 * V_15 )
{
F_27 ( & V_15 -> V_9 , V_39 ) ;
if ( V_8 -> V_18 & V_19 )
F_27 ( V_15 -> V_2 , V_8 -> V_40 ) ;
F_28 ( V_15 ) ;
}
static void F_29 ( const struct V_7 * V_8 ,
const struct V_35 * V_36 )
{
struct V_10 * V_11 = F_4 ( V_8 ) ;
struct V_12 * V_13 = F_18 ( V_11 -> V_13 ) ;
struct V_14 * V_15 , T_2 * * V_34 ;
V_34 = V_36 -> V_41 ;
V_15 = F_18 ( ( * V_34 ) ) ;
F_20 ( * V_34 , V_15 -> V_30 ) ;
F_23 () ;
F_28 ( V_15 ) ;
if ( V_8 -> V_38 - 1 < V_13 -> V_16 * 3 / 10 &&
V_13 -> V_16 > V_21 )
F_24 ( V_8 , V_11 ) ;
}
static int F_30 ( const struct V_7 * V_8 , struct V_35 * V_36 )
{
const struct V_10 * V_11 = F_4 ( V_8 ) ;
const struct V_12 * V_13 = F_18 ( V_11 -> V_13 ) ;
struct V_14 T_2 * const * V_34 ;
struct V_14 * V_15 ;
unsigned int V_5 ;
V_5 = F_1 ( & V_36 -> V_9 , V_13 -> V_16 , V_8 -> V_17 ) ;
V_34 = & V_13 -> V_23 [ V_5 ] ;
F_19 (he, tbl->buckets[h]) {
if ( F_7 ( & V_15 -> V_9 , & V_36 -> V_9 , V_8 -> V_17 ) ) {
V_34 = & V_15 -> V_30 ;
continue;
}
V_36 -> V_41 = ( void * ) V_34 ;
V_36 -> V_18 = 0 ;
if ( V_8 -> V_18 & V_19 )
F_8 ( & V_36 -> V_2 , V_15 -> V_2 ) ;
return 0 ;
}
return - V_42 ;
}
static void F_31 ( const struct V_43 * V_44 , const struct V_7 * V_8 ,
struct V_45 * V_46 )
{
const struct V_10 * V_11 = F_4 ( V_8 ) ;
const struct V_12 * V_13 = F_18 ( V_11 -> V_13 ) ;
const struct V_14 * V_15 ;
struct V_35 V_36 ;
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_13 -> V_16 ; V_31 ++ ) {
F_19 (he, tbl->buckets[i]) {
if ( V_46 -> V_47 < V_46 -> V_48 )
goto V_49;
memcpy ( & V_36 . V_9 , & V_15 -> V_9 , sizeof( V_36 . V_9 ) ) ;
if ( V_8 -> V_18 & V_19 )
memcpy ( & V_36 . V_2 , V_15 -> V_2 , sizeof( V_36 . V_2 ) ) ;
V_36 . V_18 = 0 ;
V_46 -> V_50 = V_46 -> V_51 ( V_44 , V_8 , V_46 , & V_36 ) ;
if ( V_46 -> V_50 < 0 )
return;
V_49:
V_46 -> V_47 ++ ;
}
}
}
static unsigned int F_32 ( const struct V_52 * const V_53 [] )
{
return sizeof( struct V_10 ) ;
}
static int F_33 ( const struct V_7 * V_8 ,
const struct V_54 * V_55 ,
const struct V_52 * const V_56 [] )
{
struct V_10 * V_11 = F_4 ( V_8 ) ;
struct V_12 * V_13 ;
unsigned int V_16 ;
if ( F_34 ( ! V_57 ) ) {
F_35 ( & V_6 , 4 ) ;
V_57 = true ;
}
V_16 = V_21 ;
if ( V_55 -> V_16 )
V_16 = F_11 ( V_55 -> V_16 ) ;
V_13 = F_14 ( V_16 ) ;
if ( V_13 == NULL )
return - V_33 ;
F_20 ( V_11 -> V_13 , V_13 ) ;
return 0 ;
}
static void F_36 ( const struct V_7 * V_8 )
{
const struct V_10 * V_11 = F_4 ( V_8 ) ;
const struct V_12 * V_13 = F_18 ( V_11 -> V_13 ) ;
struct V_14 * V_15 , * V_30 ;
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_13 -> V_16 ; V_31 ++ ) {
for ( V_15 = F_18 ( V_13 -> V_23 [ V_31 ] ) ; V_15 != NULL ;
V_15 = V_30 ) {
V_30 = F_18 ( V_15 -> V_30 ) ;
F_26 ( V_8 , V_15 ) ;
}
}
F_28 ( V_13 ) ;
}
static bool F_37 ( const struct V_54 * V_55 , T_3 V_58 ,
struct V_59 * V_60 )
{
unsigned int V_61 ;
V_61 = sizeof( struct V_14 ) ;
if ( V_58 & V_19 )
V_61 += F_38 ( struct V_14 , V_2 [ 0 ] ) ;
if ( V_55 -> V_16 ) {
V_60 -> V_16 = sizeof( struct V_10 ) +
F_11 ( V_55 -> V_16 ) *
sizeof( struct V_14 * ) +
V_55 -> V_16 * V_61 ;
} else {
V_60 -> V_16 = V_61 + 2 * sizeof( struct V_14 * ) ;
}
V_60 -> V_62 = V_63 ;
return true ;
}
static int T_4 F_39 ( void )
{
return F_40 ( & V_64 ) ;
}
static void T_5 F_41 ( void )
{
F_42 ( & V_64 ) ;
}
