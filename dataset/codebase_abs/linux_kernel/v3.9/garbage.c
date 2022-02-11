struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_5 * V_5 = F_2 ( V_3 ) ;
if ( F_3 ( V_5 -> V_6 ) && ! ( V_3 -> V_7 & V_8 ) ) {
struct V_9 * V_1 = F_4 ( V_5 ) ;
struct V_1 * V_10 = V_1 -> V_11 ;
if ( V_10 && V_1 -> V_12 && V_1 -> V_12 -> V_13 == V_14 )
V_4 = V_10 ;
}
return V_4 ;
}
void F_5 ( struct V_2 * V_15 )
{
struct V_1 * V_10 = F_1 ( V_15 ) ;
if ( V_10 ) {
struct V_16 * V_17 = F_6 ( V_10 ) ;
F_7 ( & V_18 ) ;
if ( F_8 ( & V_17 -> V_19 ) == 1 ) {
F_9 ( ! F_10 ( & V_17 -> V_20 ) ) ;
F_11 ( & V_17 -> V_20 , & V_21 ) ;
} else {
F_9 ( F_10 ( & V_17 -> V_20 ) ) ;
}
V_22 ++ ;
F_12 ( & V_18 ) ;
}
}
void F_13 ( struct V_2 * V_15 )
{
struct V_1 * V_10 = F_1 ( V_15 ) ;
if ( V_10 ) {
struct V_16 * V_17 = F_6 ( V_10 ) ;
F_7 ( & V_18 ) ;
F_9 ( F_10 ( & V_17 -> V_20 ) ) ;
if ( F_14 ( & V_17 -> V_19 ) )
F_15 ( & V_17 -> V_20 ) ;
V_22 -- ;
F_12 ( & V_18 ) ;
}
}
static void F_16 ( struct V_1 * V_23 , void (* F_17)( struct V_16 * ) ,
struct V_24 * V_25 )
{
struct V_26 * V_27 ;
struct V_26 * V_28 ;
F_7 ( & V_23 -> V_29 . V_30 ) ;
F_18 (&x->sk_receive_queue, skb, next) {
if ( F_19 ( V_27 ) . V_15 ) {
bool V_31 = false ;
int V_32 = F_19 ( V_27 ) . V_15 -> V_33 ;
struct V_2 * * V_15 = F_19 ( V_27 ) . V_15 -> V_15 ;
while ( V_32 -- ) {
struct V_1 * V_11 = F_1 ( * V_15 ++ ) ;
if ( V_11 ) {
struct V_16 * V_17 = F_6 ( V_11 ) ;
if ( V_17 -> V_34 ) {
V_31 = true ;
F_17 ( V_17 ) ;
}
}
}
if ( V_31 && V_25 != NULL ) {
F_20 ( V_27 , & V_23 -> V_29 ) ;
F_21 ( V_25 , V_27 ) ;
}
}
}
F_12 ( & V_23 -> V_29 . V_30 ) ;
}
static void F_22 ( struct V_1 * V_23 , void (* F_17)( struct V_16 * ) ,
struct V_24 * V_25 )
{
if ( V_23 -> V_35 != V_36 )
F_16 ( V_23 , F_17 , V_25 ) ;
else {
struct V_26 * V_27 ;
struct V_26 * V_28 ;
struct V_16 * V_17 ;
F_23 ( V_37 ) ;
F_7 ( & V_23 -> V_29 . V_30 ) ;
F_18 (&x->sk_receive_queue, skb, next) {
V_17 = F_6 ( V_27 -> V_11 ) ;
F_9 ( ! F_10 ( & V_17 -> V_20 ) ) ;
F_11 ( & V_17 -> V_20 , & V_37 ) ;
}
F_12 ( & V_23 -> V_29 . V_30 ) ;
while ( ! F_10 ( & V_37 ) ) {
V_17 = F_24 ( V_37 . V_28 , struct V_16 , V_20 ) ;
F_16 ( & V_17 -> V_11 , F_17 , V_25 ) ;
F_15 ( & V_17 -> V_20 ) ;
}
}
}
static void F_25 ( struct V_16 * V_38 )
{
F_26 ( & V_38 -> V_19 ) ;
}
static void F_27 ( struct V_16 * V_38 )
{
F_28 ( & V_38 -> V_19 ) ;
}
static void F_29 ( struct V_16 * V_17 )
{
F_28 ( & V_17 -> V_19 ) ;
if ( V_17 -> V_39 )
F_30 ( & V_17 -> V_20 , & V_40 ) ;
}
void F_31 ( void )
{
if ( V_22 > V_41 && ! V_42 )
F_32 () ;
F_33 ( V_43 , V_42 == false ) ;
}
void F_32 ( void )
{
struct V_16 * V_17 ;
struct V_16 * V_28 ;
struct V_24 V_25 ;
struct V_44 V_45 ;
F_23 ( V_46 ) ;
F_7 ( & V_18 ) ;
if ( V_42 )
goto V_47;
V_42 = true ;
F_34 (u, next, &gc_inflight_list, link) {
long V_48 ;
long V_49 ;
V_48 = F_35 ( V_17 -> V_11 . V_50 -> V_2 ) ;
V_49 = F_36 ( & V_17 -> V_19 ) ;
F_9 ( V_49 < 1 ) ;
F_9 ( V_48 < V_49 ) ;
if ( V_48 == V_49 ) {
F_30 ( & V_17 -> V_20 , & V_40 ) ;
V_17 -> V_34 = 1 ;
V_17 -> V_39 = 1 ;
}
}
F_37 (u, &gc_candidates, link)
F_22 ( & V_17 -> V_11 , F_25 , NULL ) ;
F_38 ( & V_45 , & V_40 ) ;
while ( V_45 . V_28 != & V_40 ) {
V_17 = F_24 ( V_45 . V_28 , struct V_16 , V_20 ) ;
F_39 ( & V_45 , & V_17 -> V_20 ) ;
if ( F_36 ( & V_17 -> V_19 ) > 0 ) {
F_30 ( & V_17 -> V_20 , & V_46 ) ;
V_17 -> V_39 = 0 ;
F_22 ( & V_17 -> V_11 , F_29 , NULL ) ;
}
}
F_40 ( & V_45 ) ;
while ( ! F_10 ( & V_46 ) ) {
V_17 = F_24 ( V_46 . V_28 , struct V_16 , V_20 ) ;
V_17 -> V_34 = 0 ;
F_30 ( & V_17 -> V_20 , & V_21 ) ;
}
F_41 ( & V_25 ) ;
F_37 (u, &gc_candidates, link)
F_22 ( & V_17 -> V_11 , F_27 , & V_25 ) ;
F_12 ( & V_18 ) ;
F_42 ( & V_25 ) ;
F_7 ( & V_18 ) ;
F_9 ( ! F_10 ( & V_40 ) ) ;
V_42 = false ;
F_43 ( & V_43 ) ;
V_47:
F_12 ( & V_18 ) ;
}
