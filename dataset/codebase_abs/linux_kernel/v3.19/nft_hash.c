static bool F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_8 * V_9 ;
V_9 = F_3 ( V_7 , V_4 ) ;
if ( V_9 && V_2 -> V_10 & V_11 )
F_4 ( V_5 , V_9 -> V_5 ) ;
return ! ! V_9 ;
}
static int F_5 ( const struct V_1 * V_2 ,
const struct V_12 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
unsigned int V_14 ;
if ( V_13 -> V_10 != 0 )
return - V_15 ;
V_14 = sizeof( * V_9 ) ;
if ( V_2 -> V_10 & V_11 )
V_14 += sizeof( V_9 -> V_5 [ 0 ] ) ;
V_9 = F_6 ( V_14 , V_16 ) ;
if ( V_9 == NULL )
return - V_17 ;
F_4 ( & V_9 -> V_4 , & V_13 -> V_4 ) ;
if ( V_2 -> V_10 & V_11 )
F_4 ( V_9 -> V_5 , & V_13 -> V_5 ) ;
F_7 ( V_7 , & V_9 -> V_18 ) ;
return 0 ;
}
static void F_8 ( const struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_9 ( & V_9 -> V_4 , V_19 ) ;
if ( V_2 -> V_10 & V_11 )
F_9 ( V_9 -> V_5 , V_2 -> V_20 ) ;
F_10 ( V_9 ) ;
}
static void F_11 ( const struct V_1 * V_2 ,
const struct V_12 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_21 * V_9 , V_22 * * V_23 ;
V_23 = V_13 -> V_24 ;
V_9 = F_12 ( ( * V_23 ) , V_7 ) ;
F_13 ( V_7 , V_9 , V_23 ) ;
F_14 () ;
F_10 ( V_9 ) ;
}
static int F_15 ( const struct V_1 * V_2 , struct V_12 * V_13 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_25 * V_26 = F_16 ( V_7 -> V_26 , V_7 ) ;
struct V_21 V_22 * const * V_23 ;
struct V_8 * V_9 ;
T_1 V_27 ;
V_27 = F_17 ( V_7 , & V_13 -> V_4 , V_2 -> V_28 ) ;
V_23 = & V_26 -> V_29 [ V_27 ] ;
F_18 (he, tbl->buckets[h], node) {
if ( F_19 ( & V_9 -> V_4 , & V_13 -> V_4 , V_2 -> V_28 ) ) {
V_23 = & V_9 -> V_18 . V_30 ;
continue;
}
V_13 -> V_24 = ( void * ) V_23 ;
V_13 -> V_10 = 0 ;
if ( V_2 -> V_10 & V_11 )
F_4 ( & V_13 -> V_5 , V_9 -> V_5 ) ;
return 0 ;
}
return - V_31 ;
}
static void F_20 ( const struct V_32 * V_33 , const struct V_1 * V_2 ,
struct V_34 * V_35 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_25 * V_26 ;
const struct V_8 * V_9 ;
struct V_12 V_13 ;
unsigned int V_36 ;
V_26 = F_16 ( V_7 -> V_26 , V_7 ) ;
for ( V_36 = 0 ; V_36 < V_26 -> V_14 ; V_36 ++ ) {
F_18 (he, tbl->buckets[i], node) {
if ( V_35 -> V_37 < V_35 -> V_38 )
goto V_39;
memcpy ( & V_13 . V_4 , & V_9 -> V_4 , sizeof( V_13 . V_4 ) ) ;
if ( V_2 -> V_10 & V_11 )
memcpy ( & V_13 . V_5 , V_9 -> V_5 , sizeof( V_13 . V_5 ) ) ;
V_13 . V_10 = 0 ;
V_35 -> V_40 = V_35 -> V_41 ( V_33 , V_2 , V_35 , & V_13 ) ;
if ( V_35 -> V_40 < 0 )
return;
V_39:
V_35 -> V_37 ++ ;
}
}
}
static unsigned int F_21 ( const struct V_42 * const V_43 [] )
{
return sizeof( struct V_6 ) ;
}
static int F_22 ( void * V_44 )
{
return F_23 ( V_45 ) ;
}
static int F_24 ( const struct V_1 * V_2 ,
const struct V_46 * V_47 ,
const struct V_42 * const V_48 [] )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_49 V_50 = {
. V_51 = V_47 -> V_14 ? : V_52 ,
. V_53 = F_25 ( struct V_8 , V_18 ) ,
. V_54 = F_25 ( struct V_8 , V_4 ) ,
. V_55 = V_2 -> V_28 ,
. V_56 = V_57 ,
. V_58 = V_59 ,
. V_60 = V_61 ,
#ifdef F_26
. V_62 = F_22 ,
#endif
} ;
return F_27 ( V_7 , & V_50 ) ;
}
static void F_28 ( const struct V_1 * V_2 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_25 * V_26 = V_7 -> V_26 ;
struct V_8 * V_9 , * V_30 ;
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < V_26 -> V_14 ; V_36 ++ ) {
for ( V_9 = F_29 ( V_26 -> V_29 [ V_36 ] , struct V_8 , V_18 ) ;
V_9 != NULL ; V_9 = V_30 ) {
V_30 = F_29 ( V_9 -> V_18 . V_30 , struct V_8 , V_18 ) ;
F_8 ( V_2 , V_9 ) ;
}
}
F_30 ( V_7 ) ;
}
static bool F_31 ( const struct V_46 * V_47 , T_1 V_63 ,
struct V_64 * V_65 )
{
unsigned int V_66 ;
V_66 = sizeof( struct V_8 ) ;
if ( V_63 & V_11 )
V_66 += F_32 ( struct V_8 , V_5 [ 0 ] ) ;
if ( V_47 -> V_14 ) {
V_65 -> V_14 = sizeof( struct V_6 ) +
F_33 ( V_47 -> V_14 * 4 / 3 ) *
sizeof( struct V_8 * ) +
V_47 -> V_14 * V_66 ;
} else {
V_65 -> V_14 = V_66 + 2 * sizeof( struct V_8 * ) ;
}
V_65 -> V_67 = V_68 ;
return true ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_69 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_69 ) ;
}
