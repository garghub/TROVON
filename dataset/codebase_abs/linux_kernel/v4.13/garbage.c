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
void F_5 ( struct V_15 * V_16 , struct V_2 * V_17 )
{
struct V_1 * V_10 = F_1 ( V_17 ) ;
F_6 ( & V_18 ) ;
if ( V_10 ) {
struct V_19 * V_20 = F_7 ( V_10 ) ;
if ( F_8 ( & V_20 -> V_21 ) == 1 ) {
F_9 ( ! F_10 ( & V_20 -> V_22 ) ) ;
F_11 ( & V_20 -> V_22 , & V_23 ) ;
} else {
F_9 ( F_10 ( & V_20 -> V_22 ) ) ;
}
V_24 ++ ;
}
V_16 -> F_5 ++ ;
F_12 ( & V_18 ) ;
}
void F_13 ( struct V_15 * V_16 , struct V_2 * V_17 )
{
struct V_1 * V_10 = F_1 ( V_17 ) ;
F_6 ( & V_18 ) ;
if ( V_10 ) {
struct V_19 * V_20 = F_7 ( V_10 ) ;
F_9 ( ! F_14 ( & V_20 -> V_21 ) ) ;
F_9 ( F_10 ( & V_20 -> V_22 ) ) ;
if ( F_15 ( & V_20 -> V_21 ) )
F_16 ( & V_20 -> V_22 ) ;
V_24 -- ;
}
V_16 -> F_5 -- ;
F_12 ( & V_18 ) ;
}
static void F_17 ( struct V_1 * V_25 , void (* F_18)( struct V_19 * ) ,
struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_28 * V_30 ;
F_6 ( & V_25 -> V_31 . V_32 ) ;
F_19 (&x->sk_receive_queue, skb, next) {
if ( F_20 ( V_29 ) . V_17 ) {
bool V_33 = false ;
int V_34 = F_20 ( V_29 ) . V_17 -> V_35 ;
struct V_2 * * V_17 = F_20 ( V_29 ) . V_17 -> V_17 ;
while ( V_34 -- ) {
struct V_1 * V_11 = F_1 ( * V_17 ++ ) ;
if ( V_11 ) {
struct V_19 * V_20 = F_7 ( V_11 ) ;
if ( F_21 ( V_36 , & V_20 -> V_37 ) ) {
V_33 = true ;
F_18 ( V_20 ) ;
}
}
}
if ( V_33 && V_27 != NULL ) {
F_22 ( V_29 , & V_25 -> V_31 ) ;
F_23 ( V_27 , V_29 ) ;
}
}
}
F_12 ( & V_25 -> V_31 . V_32 ) ;
}
static void F_24 ( struct V_1 * V_25 , void (* F_18)( struct V_19 * ) ,
struct V_26 * V_27 )
{
if ( V_25 -> V_38 != V_39 ) {
F_17 ( V_25 , F_18 , V_27 ) ;
} else {
struct V_28 * V_29 ;
struct V_28 * V_30 ;
struct V_19 * V_20 ;
F_25 ( V_40 ) ;
F_6 ( & V_25 -> V_31 . V_32 ) ;
F_19 (&x->sk_receive_queue, skb, next) {
V_20 = F_7 ( V_29 -> V_11 ) ;
F_9 ( ! F_10 ( & V_20 -> V_22 ) ) ;
F_11 ( & V_20 -> V_22 , & V_40 ) ;
}
F_12 ( & V_25 -> V_31 . V_32 ) ;
while ( ! F_10 ( & V_40 ) ) {
V_20 = F_26 ( V_40 . V_30 , struct V_19 , V_22 ) ;
F_17 ( & V_20 -> V_11 , F_18 , V_27 ) ;
F_16 ( & V_20 -> V_22 ) ;
}
}
}
static void F_27 ( struct V_19 * V_41 )
{
F_28 ( & V_41 -> V_21 ) ;
}
static void F_29 ( struct V_19 * V_41 )
{
F_30 ( & V_41 -> V_21 ) ;
}
static void F_31 ( struct V_19 * V_20 )
{
F_30 ( & V_20 -> V_21 ) ;
if ( F_21 ( V_42 , & V_20 -> V_37 ) )
F_32 ( & V_20 -> V_22 , & V_43 ) ;
}
void F_33 ( void )
{
if ( V_24 > V_44 && ! V_45 )
F_34 () ;
F_35 ( V_46 , V_45 == false ) ;
}
void F_34 ( void )
{
struct V_19 * V_20 ;
struct V_19 * V_30 ;
struct V_26 V_27 ;
struct V_47 V_48 ;
F_25 ( V_49 ) ;
F_6 ( & V_18 ) ;
if ( V_45 )
goto V_50;
V_45 = true ;
F_36 (u, next, &gc_inflight_list, link) {
long V_51 ;
long V_52 ;
V_51 = F_37 ( V_20 -> V_11 . V_53 -> V_2 ) ;
V_52 = F_14 ( & V_20 -> V_21 ) ;
F_9 ( V_52 < 1 ) ;
F_9 ( V_51 < V_52 ) ;
if ( V_51 == V_52 ) {
F_32 ( & V_20 -> V_22 , & V_43 ) ;
F_38 ( V_36 , & V_20 -> V_37 ) ;
F_38 ( V_42 , & V_20 -> V_37 ) ;
}
}
F_39 (u, &gc_candidates, link)
F_24 ( & V_20 -> V_11 , F_27 , NULL ) ;
F_40 ( & V_48 , & V_43 ) ;
while ( V_48 . V_30 != & V_43 ) {
V_20 = F_26 ( V_48 . V_30 , struct V_19 , V_22 ) ;
F_41 ( & V_48 , & V_20 -> V_22 ) ;
if ( F_14 ( & V_20 -> V_21 ) > 0 ) {
F_32 ( & V_20 -> V_22 , & V_49 ) ;
F_42 ( V_42 , & V_20 -> V_37 ) ;
F_24 ( & V_20 -> V_11 , F_31 , NULL ) ;
}
}
F_43 ( & V_48 ) ;
F_44 ( & V_27 ) ;
F_39 (u, &gc_candidates, link)
F_24 ( & V_20 -> V_11 , F_29 , & V_27 ) ;
while ( ! F_10 ( & V_49 ) ) {
V_20 = F_26 ( V_49 . V_30 , struct V_19 , V_22 ) ;
F_42 ( V_36 , & V_20 -> V_37 ) ;
F_32 ( & V_20 -> V_22 , & V_23 ) ;
}
F_12 ( & V_18 ) ;
F_45 ( & V_27 ) ;
F_6 ( & V_18 ) ;
F_9 ( ! F_10 ( & V_43 ) ) ;
V_45 = false ;
F_46 ( & V_46 ) ;
V_50:
F_12 ( & V_18 ) ;
}
