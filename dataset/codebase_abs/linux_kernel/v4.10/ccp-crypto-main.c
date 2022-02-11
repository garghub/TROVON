static inline bool F_1 ( int V_1 )
{
if ( V_1 && ( V_1 != - V_2 ) && ( V_1 != - V_3 ) )
return false ;
return true ;
}
static struct V_4 * F_2 (
struct V_4 * V_5 , struct V_4 * * V_6 )
{
struct V_4 * V_7 = NULL , * V_8 ;
unsigned long V_9 ;
* V_6 = NULL ;
F_3 ( & V_10 , V_9 ) ;
V_8 = V_5 ;
F_4 (tmp, &req_queue.cmds, entry) {
if ( V_5 -> V_11 != V_8 -> V_11 )
continue;
V_7 = V_8 ;
break;
}
if ( V_12 . V_6 != & V_12 . V_13 ) {
if ( V_12 . V_6 == & V_5 -> V_14 )
V_12 . V_6 = V_5 -> V_14 . V_15 ;
* V_6 = F_5 ( V_12 . V_6 ,
struct V_4 , V_14 ) ;
V_12 . V_6 = V_12 . V_6 -> V_15 ;
if ( V_12 . V_6 == & V_5 -> V_14 )
V_12 . V_6 = V_5 -> V_14 . V_15 ;
}
V_12 . V_16 -- ;
F_6 ( & V_5 -> V_14 ) ;
F_7 ( & V_10 , V_9 ) ;
return V_7 ;
}
static void F_8 ( void * V_17 , int V_1 )
{
struct V_4 * V_5 = V_17 ;
struct V_4 * V_7 , * V_15 , * V_6 ;
struct V_18 * V_19 = V_5 -> V_19 ;
struct V_20 * V_21 = F_9 ( V_19 -> V_11 ) ;
int V_22 ;
if ( V_1 == - V_2 ) {
if ( V_5 -> V_22 == - V_3 ) {
V_5 -> V_22 = - V_2 ;
V_19 -> V_23 ( V_19 , - V_2 ) ;
}
return;
}
V_7 = F_2 ( V_5 , & V_6 ) ;
if ( V_6 ) {
V_6 -> V_22 = - V_2 ;
V_6 -> V_19 -> V_23 ( V_6 -> V_19 , - V_2 ) ;
}
if ( V_5 -> V_22 == - V_3 )
V_19 -> V_23 ( V_19 , - V_2 ) ;
V_22 = V_1 ;
if ( V_21 -> V_23 )
V_22 = V_21 -> V_23 ( V_19 , V_22 ) ;
V_19 -> V_23 ( V_19 , V_22 ) ;
while ( V_7 ) {
V_7 -> V_24 -> V_9 |= V_25 ;
V_22 = F_10 ( V_7 -> V_24 ) ;
if ( F_1 ( V_22 ) )
break;
V_21 = F_9 ( V_7 -> V_19 -> V_11 ) ;
if ( V_21 -> V_23 )
V_22 = V_21 -> V_23 ( V_7 -> V_19 , V_22 ) ;
V_7 -> V_19 -> V_23 ( V_7 -> V_19 , V_22 ) ;
V_15 = F_2 ( V_7 , & V_6 ) ;
if ( V_6 ) {
V_6 -> V_22 = - V_2 ;
V_6 -> V_19 -> V_23 ( V_6 -> V_19 , - V_2 ) ;
}
F_11 ( V_7 ) ;
V_7 = V_15 ;
}
F_11 ( V_5 ) ;
}
static int F_12 ( struct V_4 * V_5 )
{
struct V_4 * V_26 = NULL , * V_8 ;
unsigned long V_9 ;
bool V_27 = true ;
int V_22 ;
F_3 ( & V_10 , V_9 ) ;
if ( V_12 . V_16 >= V_28 ) {
V_22 = - V_3 ;
if ( ! ( V_5 -> V_24 -> V_9 & V_25 ) )
goto V_29;
}
F_13 (tmp, &req_queue.cmds, entry) {
if ( V_5 -> V_11 != V_8 -> V_11 )
continue;
V_26 = V_8 ;
break;
}
V_22 = - V_2 ;
if ( ! V_26 ) {
V_22 = F_10 ( V_5 -> V_24 ) ;
if ( ! F_1 ( V_22 ) )
goto V_29;
if ( ( V_22 == - V_3 ) &&
! ( V_5 -> V_24 -> V_9 & V_25 ) )
goto V_29;
}
if ( V_12 . V_16 >= V_28 ) {
V_22 = - V_3 ;
if ( V_12 . V_6 == & V_12 . V_13 )
V_12 . V_6 = & V_5 -> V_14 ;
}
V_5 -> V_22 = V_22 ;
V_12 . V_16 ++ ;
F_14 ( & V_5 -> V_14 , & V_12 . V_13 ) ;
V_27 = false ;
V_29:
F_7 ( & V_10 , V_9 ) ;
if ( V_27 )
F_11 ( V_5 ) ;
return V_22 ;
}
int F_15 ( struct V_18 * V_19 ,
struct V_30 * V_24 )
{
struct V_4 * V_5 ;
T_1 V_31 ;
V_31 = V_19 -> V_9 & V_32 ? V_33 : V_34 ;
V_5 = F_16 ( sizeof( * V_5 ) , V_31 ) ;
if ( ! V_5 )
return - V_35 ;
V_5 -> V_24 = V_24 ;
V_5 -> V_19 = V_19 ;
V_5 -> V_11 = V_19 -> V_11 ;
V_24 -> V_36 = F_8 ;
V_24 -> V_17 = V_5 ;
if ( V_19 -> V_9 & V_37 )
V_24 -> V_9 |= V_25 ;
else
V_24 -> V_9 &= ~ V_25 ;
return F_12 ( V_5 ) ;
}
struct V_38 * F_17 ( struct V_39 * V_40 ,
struct V_38 * V_41 )
{
struct V_38 * V_42 , * V_43 = NULL ;
for ( V_42 = V_40 -> V_44 ; V_42 ; V_42 = F_18 ( V_42 ) )
if ( ! F_19 ( V_42 ) )
break;
if ( F_20 ( ! V_42 ) )
return NULL ;
for (; V_42 && V_41 ; V_42 = F_18 ( V_42 ) , V_41 = F_18 ( V_41 ) ) {
F_21 ( V_42 , F_19 ( V_41 ) , V_41 -> V_45 ,
V_41 -> V_46 ) ;
V_43 = V_42 ;
}
if ( F_20 ( V_41 ) )
return NULL ;
return V_43 ;
}
static int F_22 ( void )
{
int V_22 ;
if ( ! V_47 ) {
V_22 = F_23 ( & V_48 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_24 ( & V_49 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_25 ( & V_48 ) ;
if ( V_22 )
return V_22 ;
}
if ( ! V_50 ) {
V_22 = F_26 ( & V_49 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static void F_27 ( void )
{
struct V_51 * V_52 , * V_53 ;
struct V_54 * V_55 , * V_56 ;
F_28 (ahash_alg, ahash_tmp, &hash_algs, entry) {
F_29 ( & V_52 -> V_57 ) ;
F_6 ( & V_52 -> V_14 ) ;
F_11 ( V_52 ) ;
}
F_28 (ablk_alg, ablk_tmp, &cipher_algs, entry) {
F_30 ( & V_55 -> V_57 ) ;
F_6 ( & V_55 -> V_14 ) ;
F_11 ( V_55 ) ;
}
}
static int F_31 ( void )
{
int V_22 ;
V_22 = F_32 () ;
if ( V_22 )
return V_22 ;
F_33 ( & V_10 ) ;
F_34 ( & V_12 . V_13 ) ;
V_12 . V_6 = & V_12 . V_13 ;
V_12 . V_16 = 0 ;
V_22 = F_22 () ;
if ( V_22 )
F_27 () ;
return V_22 ;
}
static void F_35 ( void )
{
F_27 () ;
}
