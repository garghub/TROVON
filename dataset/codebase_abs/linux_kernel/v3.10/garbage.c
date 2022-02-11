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
if ( F_20 ( V_34 , & V_17 -> V_35 ) ) {
V_31 = true ;
F_17 ( V_17 ) ;
}
}
}
if ( V_31 && V_25 != NULL ) {
F_21 ( V_27 , & V_23 -> V_29 ) ;
F_22 ( V_25 , V_27 ) ;
}
}
}
F_12 ( & V_23 -> V_29 . V_30 ) ;
}
static void F_23 ( struct V_1 * V_23 , void (* F_17)( struct V_16 * ) ,
struct V_24 * V_25 )
{
if ( V_23 -> V_36 != V_37 )
F_16 ( V_23 , F_17 , V_25 ) ;
else {
struct V_26 * V_27 ;
struct V_26 * V_28 ;
struct V_16 * V_17 ;
F_24 ( V_38 ) ;
F_7 ( & V_23 -> V_29 . V_30 ) ;
F_18 (&x->sk_receive_queue, skb, next) {
V_17 = F_6 ( V_27 -> V_11 ) ;
F_9 ( ! F_10 ( & V_17 -> V_20 ) ) ;
F_11 ( & V_17 -> V_20 , & V_38 ) ;
}
F_12 ( & V_23 -> V_29 . V_30 ) ;
while ( ! F_10 ( & V_38 ) ) {
V_17 = F_25 ( V_38 . V_28 , struct V_16 , V_20 ) ;
F_16 ( & V_17 -> V_11 , F_17 , V_25 ) ;
F_15 ( & V_17 -> V_20 ) ;
}
}
}
static void F_26 ( struct V_16 * V_39 )
{
F_27 ( & V_39 -> V_19 ) ;
}
static void F_28 ( struct V_16 * V_39 )
{
F_29 ( & V_39 -> V_19 ) ;
}
static void F_30 ( struct V_16 * V_17 )
{
F_29 ( & V_17 -> V_19 ) ;
if ( F_20 ( V_40 , & V_17 -> V_35 ) )
F_31 ( & V_17 -> V_20 , & V_41 ) ;
}
void F_32 ( void )
{
if ( V_22 > V_42 && ! V_43 )
F_33 () ;
F_34 ( V_44 , V_43 == false ) ;
}
void F_33 ( void )
{
struct V_16 * V_17 ;
struct V_16 * V_28 ;
struct V_24 V_25 ;
struct V_45 V_46 ;
F_24 ( V_47 ) ;
F_7 ( & V_18 ) ;
if ( V_43 )
goto V_48;
V_43 = true ;
F_35 (u, next, &gc_inflight_list, link) {
long V_49 ;
long V_50 ;
V_49 = F_36 ( V_17 -> V_11 . V_51 -> V_2 ) ;
V_50 = F_37 ( & V_17 -> V_19 ) ;
F_9 ( V_50 < 1 ) ;
F_9 ( V_49 < V_50 ) ;
if ( V_49 == V_50 ) {
F_31 ( & V_17 -> V_20 , & V_41 ) ;
F_38 ( V_34 , & V_17 -> V_35 ) ;
F_38 ( V_40 , & V_17 -> V_35 ) ;
}
}
F_39 (u, &gc_candidates, link)
F_23 ( & V_17 -> V_11 , F_26 , NULL ) ;
F_40 ( & V_46 , & V_41 ) ;
while ( V_46 . V_28 != & V_41 ) {
V_17 = F_25 ( V_46 . V_28 , struct V_16 , V_20 ) ;
F_41 ( & V_46 , & V_17 -> V_20 ) ;
if ( F_37 ( & V_17 -> V_19 ) > 0 ) {
F_31 ( & V_17 -> V_20 , & V_47 ) ;
F_42 ( V_40 , & V_17 -> V_35 ) ;
F_23 ( & V_17 -> V_11 , F_30 , NULL ) ;
}
}
F_43 ( & V_46 ) ;
while ( ! F_10 ( & V_47 ) ) {
V_17 = F_25 ( V_47 . V_28 , struct V_16 , V_20 ) ;
F_42 ( V_34 , & V_17 -> V_35 ) ;
F_31 ( & V_17 -> V_20 , & V_21 ) ;
}
F_44 ( & V_25 ) ;
F_39 (u, &gc_candidates, link)
F_23 ( & V_17 -> V_11 , F_28 , & V_25 ) ;
F_12 ( & V_18 ) ;
F_45 ( & V_25 ) ;
F_7 ( & V_18 ) ;
F_9 ( ! F_10 ( & V_41 ) ) ;
V_43 = false ;
F_46 ( & V_44 ) ;
V_48:
F_12 ( & V_18 ) ;
}
