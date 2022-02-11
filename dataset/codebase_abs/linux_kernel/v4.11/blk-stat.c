static void F_1 ( struct V_1 * V_2 )
{
const T_1 V_3 = F_2 ( V_2 -> V_3 ) ;
const T_1 V_4 = F_2 ( V_2 -> V_4 ) ;
if ( ! V_3 )
return;
if ( ! V_4 )
V_2 -> V_5 = F_3 ( V_2 -> V_6 , V_3 ) ;
else {
V_2 -> V_5 = F_3 ( ( V_2 -> V_5 * V_4 ) +
V_2 -> V_6 ,
V_3 + V_4 ) ;
}
V_2 -> V_4 += V_3 ;
V_2 -> V_3 = V_2 -> V_6 = 0 ;
}
static void F_4 ( struct V_1 * V_7 , struct V_1 * V_8 )
{
F_1 ( V_8 ) ;
if ( ! V_8 -> V_4 )
return;
V_7 -> V_9 = V_9 ( V_7 -> V_9 , V_8 -> V_9 ) ;
V_7 -> V_10 = V_10 ( V_7 -> V_10 , V_8 -> V_10 ) ;
if ( ! V_7 -> V_4 )
V_7 -> V_5 = V_8 -> V_5 ;
else {
V_7 -> V_5 = F_3 ( ( V_8 -> V_5 * V_8 -> V_4 ) +
( V_7 -> V_5 * V_7 -> V_4 ) ,
V_7 -> V_4 + V_8 -> V_4 ) ;
}
V_7 -> V_4 += V_8 -> V_4 ;
}
static void F_5 ( struct V_11 * V_12 , struct V_1 * V_7 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
T_2 V_17 = 0 ;
int V_18 , V_19 , V_20 ;
F_6 ( & V_7 [ V_21 ] ) ;
F_6 ( & V_7 [ V_22 ] ) ;
V_20 = 0 ;
do {
T_2 V_23 = 0 ;
F_7 (q, hctx, i) {
F_8 (hctx, ctx, j) {
F_1 ( & V_16 -> V_2 [ V_21 ] ) ;
F_1 ( & V_16 -> V_2 [ V_22 ] ) ;
if ( ! V_16 -> V_2 [ V_21 ] . V_4 &&
! V_16 -> V_2 [ V_22 ] . V_4 )
continue;
if ( V_16 -> V_2 [ V_21 ] . time > V_23 )
V_23 = V_16 -> V_2 [ V_21 ] . time ;
if ( V_16 -> V_2 [ V_22 ] . time > V_23 )
V_23 = V_16 -> V_2 [ V_22 ] . time ;
}
}
if ( ! V_23 )
break;
if ( V_23 > V_17 )
V_17 = V_23 ;
F_7 (q, hctx, i) {
F_8 (hctx, ctx, j) {
if ( V_16 -> V_2 [ V_21 ] . time == V_23 ) {
F_4 ( & V_7 [ V_21 ] ,
& V_16 -> V_2 [ V_21 ] ) ;
V_20 ++ ;
}
if ( V_16 -> V_2 [ V_22 ] . time == V_23 ) {
F_4 ( & V_7 [ V_22 ] ,
& V_16 -> V_2 [ V_22 ] ) ;
V_20 ++ ;
}
}
}
} while ( ! V_20 );
V_7 [ V_21 ] . time = V_7 [ V_22 ] . time = V_17 ;
}
void F_9 ( struct V_11 * V_12 , struct V_1 * V_7 )
{
if ( V_12 -> V_24 )
F_5 ( V_12 , V_7 ) ;
else {
F_1 ( & V_12 -> V_25 [ V_21 ] ) ;
F_1 ( & V_12 -> V_25 [ V_22 ] ) ;
memcpy ( & V_7 [ V_21 ] , & V_12 -> V_25 [ V_21 ] ,
sizeof( struct V_1 ) ) ;
memcpy ( & V_7 [ V_22 ] , & V_12 -> V_25 [ V_22 ] ,
sizeof( struct V_1 ) ) ;
}
}
void F_10 ( struct V_13 * V_14 , struct V_1 * V_7 )
{
struct V_15 * V_16 ;
unsigned int V_18 , V_20 ;
V_20 = 0 ;
do {
T_2 V_23 = 0 ;
F_8 (hctx, ctx, i) {
F_1 ( & V_16 -> V_2 [ V_21 ] ) ;
F_1 ( & V_16 -> V_2 [ V_22 ] ) ;
if ( ! V_16 -> V_2 [ V_21 ] . V_4 &&
! V_16 -> V_2 [ V_22 ] . V_4 )
continue;
if ( V_16 -> V_2 [ V_21 ] . time > V_23 )
V_23 = V_16 -> V_2 [ V_21 ] . time ;
if ( V_16 -> V_2 [ V_22 ] . time > V_23 )
V_23 = V_16 -> V_2 [ V_22 ] . time ;
}
if ( ! V_23 )
break;
F_8 (hctx, ctx, i) {
if ( V_16 -> V_2 [ V_21 ] . time == V_23 ) {
F_4 ( & V_7 [ V_21 ] ,
& V_16 -> V_2 [ V_21 ] ) ;
V_20 ++ ;
}
if ( V_16 -> V_2 [ V_22 ] . time == V_23 ) {
F_4 ( & V_7 [ V_22 ] ,
& V_16 -> V_2 [ V_22 ] ) ;
V_20 ++ ;
}
}
} while ( ! V_20 );
}
static void F_11 ( struct V_1 * V_2 , T_3 V_26 )
{
V_2 -> V_9 = - 1ULL ;
V_2 -> V_10 = V_2 -> V_4 = V_2 -> V_5 = 0 ;
V_2 -> V_6 = V_2 -> V_3 = 0 ;
V_2 -> time = V_26 & V_27 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_11 ( V_2 , F_12 ( F_13 () ) ) ;
}
static bool F_14 ( struct V_1 * V_2 , T_3 V_28 )
{
return ( V_28 & V_27 ) == ( V_2 -> time & V_27 ) ;
}
bool F_15 ( struct V_1 * V_2 )
{
return F_14 ( V_2 , F_12 ( F_13 () ) ) ;
}
void F_16 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
T_3 V_28 , V_31 ;
V_28 = F_17 ( F_12 ( F_13 () ) ) ;
if ( V_28 < F_18 ( & V_30 -> V_32 ) )
return;
if ( ! F_14 ( V_2 , V_28 ) )
F_11 ( V_2 , V_28 ) ;
V_31 = V_28 - F_18 ( & V_30 -> V_32 ) ;
if ( V_31 > V_2 -> V_10 )
V_2 -> V_10 = V_31 ;
if ( V_31 < V_2 -> V_9 )
V_2 -> V_9 = V_31 ;
if ( V_2 -> V_6 + V_31 < V_2 -> V_6 ||
V_2 -> V_3 + 1 == V_33 )
F_1 ( V_2 ) ;
V_2 -> V_6 += V_31 ;
V_2 -> V_3 ++ ;
}
void F_19 ( struct V_11 * V_12 )
{
if ( V_12 -> V_24 ) {
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_18 , V_19 ;
F_7 (q, hctx, i) {
F_8 (hctx, ctx, j) {
F_6 ( & V_16 -> V_2 [ V_21 ] ) ;
F_6 ( & V_16 -> V_2 [ V_22 ] ) ;
}
}
} else {
F_6 ( & V_12 -> V_25 [ V_21 ] ) ;
F_6 ( & V_12 -> V_25 [ V_22 ] ) ;
}
}
void F_20 ( struct V_34 * V_2 )
{
V_2 -> time = ( V_2 -> time & V_35 ) |
( F_12 ( F_13 () ) & V_36 ) ;
}
bool F_21 ( struct V_11 * V_12 )
{
if ( ! F_22 ( V_37 , & V_12 -> V_38 ) ) {
F_23 ( V_37 , & V_12 -> V_38 ) ;
return false ;
}
return true ;
}
