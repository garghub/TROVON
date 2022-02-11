struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_5 * V_5 = V_3 -> V_6 . V_7 -> V_8 ;
if ( F_2 ( V_5 -> V_9 ) && ! ( V_3 -> V_10 & V_11 ) ) {
struct V_12 * V_1 = F_3 ( V_5 ) ;
struct V_1 * V_13 = V_1 -> V_14 ;
if ( V_13 && V_1 -> V_15 && V_1 -> V_15 -> V_16 == V_17 )
V_4 = V_13 ;
}
return V_4 ;
}
void F_4 ( struct V_2 * V_18 )
{
struct V_1 * V_13 = F_1 ( V_18 ) ;
if ( V_13 ) {
struct V_19 * V_20 = F_5 ( V_13 ) ;
F_6 ( & V_21 ) ;
if ( F_7 ( & V_20 -> V_22 ) == 1 ) {
F_8 ( ! F_9 ( & V_20 -> V_23 ) ) ;
F_10 ( & V_20 -> V_23 , & V_24 ) ;
} else {
F_8 ( F_9 ( & V_20 -> V_23 ) ) ;
}
V_25 ++ ;
F_11 ( & V_21 ) ;
}
}
void F_12 ( struct V_2 * V_18 )
{
struct V_1 * V_13 = F_1 ( V_18 ) ;
if ( V_13 ) {
struct V_19 * V_20 = F_5 ( V_13 ) ;
F_6 ( & V_21 ) ;
F_8 ( F_9 ( & V_20 -> V_23 ) ) ;
if ( F_13 ( & V_20 -> V_22 ) )
F_14 ( & V_20 -> V_23 ) ;
V_25 -- ;
F_11 ( & V_21 ) ;
}
}
static void F_15 ( struct V_1 * V_26 , void (* F_16)( struct V_19 * ) ,
struct V_27 * V_28 )
{
struct V_29 * V_30 ;
struct V_29 * V_31 ;
F_6 ( & V_26 -> V_32 . V_33 ) ;
F_17 (&x->sk_receive_queue, skb, next) {
if ( F_18 ( V_30 ) . V_18 ) {
bool V_34 = false ;
int V_35 = F_18 ( V_30 ) . V_18 -> V_36 ;
struct V_2 * * V_18 = F_18 ( V_30 ) . V_18 -> V_18 ;
while ( V_35 -- ) {
struct V_1 * V_14 = F_1 ( * V_18 ++ ) ;
if ( V_14 ) {
struct V_19 * V_20 = F_5 ( V_14 ) ;
if ( V_20 -> V_37 ) {
V_34 = true ;
F_16 ( V_20 ) ;
}
}
}
if ( V_34 && V_28 != NULL ) {
F_19 ( V_30 , & V_26 -> V_32 ) ;
F_20 ( V_28 , V_30 ) ;
}
}
}
F_11 ( & V_26 -> V_32 . V_33 ) ;
}
static void F_21 ( struct V_1 * V_26 , void (* F_16)( struct V_19 * ) ,
struct V_27 * V_28 )
{
if ( V_26 -> V_38 != V_39 )
F_15 ( V_26 , F_16 , V_28 ) ;
else {
struct V_29 * V_30 ;
struct V_29 * V_31 ;
struct V_19 * V_20 ;
F_22 ( V_40 ) ;
F_6 ( & V_26 -> V_32 . V_33 ) ;
F_17 (&x->sk_receive_queue, skb, next) {
V_20 = F_5 ( V_30 -> V_14 ) ;
F_8 ( ! F_9 ( & V_20 -> V_23 ) ) ;
F_10 ( & V_20 -> V_23 , & V_40 ) ;
}
F_11 ( & V_26 -> V_32 . V_33 ) ;
while ( ! F_9 ( & V_40 ) ) {
V_20 = F_23 ( V_40 . V_31 , struct V_19 , V_23 ) ;
F_15 ( & V_20 -> V_14 , F_16 , V_28 ) ;
F_14 ( & V_20 -> V_23 ) ;
}
}
}
static void F_24 ( struct V_19 * V_41 )
{
F_25 ( & V_41 -> V_22 ) ;
}
static void F_26 ( struct V_19 * V_41 )
{
F_27 ( & V_41 -> V_22 ) ;
}
static void F_28 ( struct V_19 * V_20 )
{
F_27 ( & V_20 -> V_22 ) ;
if ( V_20 -> V_42 )
F_29 ( & V_20 -> V_23 , & V_43 ) ;
}
void F_30 ( void )
{
if ( V_25 > V_44 && ! V_45 )
F_31 () ;
F_32 ( V_46 , V_45 == false ) ;
}
void F_31 ( void )
{
struct V_19 * V_20 ;
struct V_19 * V_31 ;
struct V_27 V_28 ;
struct V_47 V_48 ;
F_22 ( V_49 ) ;
F_6 ( & V_21 ) ;
if ( V_45 )
goto V_50;
V_45 = true ;
F_33 (u, next, &gc_inflight_list, link) {
long V_51 ;
long V_52 ;
V_51 = F_34 ( V_20 -> V_14 . V_53 -> V_2 ) ;
V_52 = F_35 ( & V_20 -> V_22 ) ;
F_8 ( V_52 < 1 ) ;
F_8 ( V_51 < V_52 ) ;
if ( V_51 == V_52 ) {
F_29 ( & V_20 -> V_23 , & V_43 ) ;
V_20 -> V_37 = 1 ;
V_20 -> V_42 = 1 ;
}
}
F_36 (u, &gc_candidates, link)
F_21 ( & V_20 -> V_14 , F_24 , NULL ) ;
F_37 ( & V_48 , & V_43 ) ;
while ( V_48 . V_31 != & V_43 ) {
V_20 = F_23 ( V_48 . V_31 , struct V_19 , V_23 ) ;
F_38 ( & V_48 , & V_20 -> V_23 ) ;
if ( F_35 ( & V_20 -> V_22 ) > 0 ) {
F_29 ( & V_20 -> V_23 , & V_49 ) ;
V_20 -> V_42 = 0 ;
F_21 ( & V_20 -> V_14 , F_28 , NULL ) ;
}
}
F_39 ( & V_48 ) ;
while ( ! F_9 ( & V_49 ) ) {
V_20 = F_23 ( V_49 . V_31 , struct V_19 , V_23 ) ;
V_20 -> V_37 = 0 ;
F_29 ( & V_20 -> V_23 , & V_24 ) ;
}
F_40 ( & V_28 ) ;
F_36 (u, &gc_candidates, link)
F_21 ( & V_20 -> V_14 , F_26 , & V_28 ) ;
F_11 ( & V_21 ) ;
F_41 ( & V_28 ) ;
F_6 ( & V_21 ) ;
F_8 ( ! F_9 ( & V_43 ) ) ;
V_45 = false ;
F_42 ( & V_46 ) ;
V_50:
F_11 ( & V_21 ) ;
}
