static inline bool F_1 ( int V_1 )
{
if ( V_1 && ( V_1 != - V_2 ) && ( V_1 != - V_3 ) )
return false ;
return true ;
}
static struct V_4 * F_2 (
struct V_4 * V_5 , struct V_4 * * V_6 )
{
struct V_7 * V_8 ;
struct V_4 * V_9 = NULL , * V_10 ;
* V_6 = NULL ;
V_8 = F_3 ( V_11 . V_8 ) ;
V_10 = V_5 ;
F_4 (tmp, &cpu_queue->cmds, entry) {
if ( V_5 -> V_12 != V_10 -> V_12 )
continue;
V_9 = V_10 ;
break;
}
if ( V_8 -> V_6 != & V_8 -> V_13 ) {
if ( V_8 -> V_6 == & V_5 -> V_14 )
V_8 -> V_6 = V_5 -> V_14 . V_15 ;
* V_6 = F_5 ( V_8 -> V_6 ,
struct V_4 , V_14 ) ;
V_8 -> V_6 = V_8 -> V_6 -> V_15 ;
if ( V_8 -> V_6 == & V_5 -> V_14 )
V_8 -> V_6 = V_5 -> V_14 . V_15 ;
}
V_8 -> V_16 -- ;
F_6 ( & V_5 -> V_14 ) ;
return V_9 ;
}
static void F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_20 =
F_5 ( V_18 , struct V_19 , V_18 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
struct V_4 * V_9 , * V_15 , * V_6 ;
struct V_21 * V_22 = V_5 -> V_22 ;
struct V_23 * V_24 = F_8 ( V_22 -> V_12 ) ;
int V_25 , V_26 ;
V_25 = F_9 () ;
if ( V_20 -> V_1 == - V_2 ) {
if ( V_5 -> V_26 == - V_3 ) {
V_5 -> V_26 = - V_2 ;
V_22 -> V_27 ( V_22 , - V_2 ) ;
}
goto V_28;
}
V_9 = F_2 ( V_5 , & V_6 ) ;
if ( V_6 ) {
V_6 -> V_26 = - V_2 ;
V_6 -> V_22 -> V_27 ( V_6 -> V_22 , - V_2 ) ;
}
if ( V_5 -> V_26 == - V_3 )
V_22 -> V_27 ( V_22 , - V_2 ) ;
V_26 = V_20 -> V_1 ;
if ( V_24 -> V_27 )
V_26 = V_24 -> V_27 ( V_22 , V_26 ) ;
V_22 -> V_27 ( V_22 , V_26 ) ;
while ( V_9 ) {
V_26 = F_10 ( V_9 -> V_29 ) ;
if ( F_1 ( V_26 ) )
break;
V_9 -> V_22 -> V_27 ( V_9 -> V_22 , V_26 ) ;
V_15 = F_2 ( V_9 , & V_6 ) ;
if ( V_6 ) {
V_6 -> V_26 = - V_2 ;
V_6 -> V_22 -> V_27 ( V_6 -> V_22 , - V_2 ) ;
}
F_11 ( V_9 ) ;
V_9 = V_15 ;
}
F_11 ( V_5 ) ;
V_28:
F_12 () ;
V_27 ( & V_20 -> V_30 ) ;
}
static void F_13 ( void * V_31 , int V_1 )
{
struct V_4 * V_5 = V_31 ;
struct V_19 V_20 ;
F_14 ( & V_20 . V_18 , F_7 ) ;
F_15 ( & V_20 . V_30 ) ;
V_20 . V_5 = V_5 ;
V_20 . V_1 = V_1 ;
F_16 ( V_5 -> V_25 , & V_20 . V_18 ) ;
F_17 ( & V_20 . V_30 ) ;
}
static int F_18 ( struct V_4 * V_5 )
{
struct V_7 * V_8 ;
struct V_4 * V_32 = NULL , * V_10 ;
int V_25 , V_26 ;
V_25 = F_9 () ;
V_5 -> V_25 = V_25 ;
V_8 = F_3 ( V_11 . V_8 ) ;
if ( V_8 -> V_16 >= V_33 ) {
V_26 = - V_3 ;
if ( ! ( V_5 -> V_29 -> V_34 & V_35 ) )
goto V_28;
}
F_19 (tmp, &cpu_queue->cmds, entry) {
if ( V_5 -> V_12 != V_10 -> V_12 )
continue;
V_32 = V_10 ;
break;
}
V_26 = - V_2 ;
if ( ! V_32 ) {
V_26 = F_10 ( V_5 -> V_29 ) ;
if ( ! F_1 ( V_26 ) )
goto V_28;
}
if ( V_8 -> V_16 >= V_33 ) {
V_26 = - V_3 ;
if ( V_8 -> V_6 == & V_8 -> V_13 )
V_8 -> V_6 = & V_5 -> V_14 ;
}
V_5 -> V_26 = V_26 ;
V_8 -> V_16 ++ ;
F_20 ( & V_5 -> V_14 , & V_8 -> V_13 ) ;
V_28:
F_12 () ;
return V_26 ;
}
int F_21 ( struct V_21 * V_22 ,
struct V_36 * V_29 )
{
struct V_4 * V_5 ;
T_1 V_37 ;
int V_26 ;
V_37 = V_22 -> V_34 & V_38 ? V_39 : V_40 ;
V_5 = F_22 ( sizeof( * V_5 ) , V_37 ) ;
if ( ! V_5 )
return - V_41 ;
V_5 -> V_29 = V_29 ;
V_5 -> V_22 = V_22 ;
V_5 -> V_12 = V_22 -> V_12 ;
V_29 -> V_42 = F_13 ;
V_29 -> V_31 = V_5 ;
if ( V_22 -> V_34 & V_43 )
V_29 -> V_34 |= V_35 ;
else
V_29 -> V_34 &= ~ V_35 ;
V_26 = F_18 ( V_5 ) ;
if ( ! F_1 ( V_26 ) )
F_11 ( V_5 ) ;
return V_26 ;
}
struct V_44 * F_23 ( struct V_45 * V_46 ,
struct V_44 * V_47 )
{
struct V_44 * V_48 , * V_49 = NULL ;
for ( V_48 = V_46 -> V_50 ; V_48 ; V_48 = F_24 ( V_48 ) )
if ( ! F_25 ( V_48 ) )
break;
F_26 ( ! V_48 ) ;
for (; V_48 && V_47 ; V_48 = F_24 ( V_48 ) , V_47 = F_24 ( V_47 ) ) {
F_27 ( V_48 , F_25 ( V_47 ) , V_47 -> V_51 ,
V_47 -> V_52 ) ;
V_49 = V_48 ;
}
F_26 ( V_47 ) ;
return V_49 ;
}
static int F_28 ( void )
{
int V_26 ;
V_26 = F_29 ( & V_53 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_30 ( & V_54 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_31 ( & V_53 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_32 ( & V_54 ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static void F_33 ( void )
{
struct V_55 * V_56 , * V_57 ;
struct V_58 * V_59 , * V_60 ;
F_34 (ahash_alg, ahash_tmp, &hash_algs, entry) {
F_35 ( & V_56 -> V_61 ) ;
F_6 ( & V_56 -> V_14 ) ;
F_11 ( V_56 ) ;
}
F_34 (ablk_alg, ablk_tmp, &cipher_algs, entry) {
F_36 ( & V_59 -> V_61 ) ;
F_6 ( & V_59 -> V_14 ) ;
F_11 ( V_59 ) ;
}
}
static int F_37 ( void )
{
struct V_7 * V_8 ;
int V_25 ;
V_11 . V_8 = F_38 ( struct V_7 ) ;
if ( ! V_11 . V_8 )
return - V_41 ;
F_39 (cpu) {
V_8 = F_40 ( V_11 . V_8 , V_25 ) ;
F_41 ( & V_8 -> V_13 ) ;
V_8 -> V_6 = & V_8 -> V_13 ;
V_8 -> V_16 = 0 ;
}
return 0 ;
}
static void F_42 ( void )
{
struct V_7 * V_8 ;
int V_25 ;
F_39 (cpu) {
V_8 = F_40 ( V_11 . V_8 , V_25 ) ;
F_26 ( ! F_43 ( & V_8 -> V_13 ) ) ;
}
F_44 ( V_11 . V_8 ) ;
}
static int F_45 ( void )
{
int V_26 ;
V_26 = F_37 () ;
if ( V_26 )
return V_26 ;
V_26 = F_28 () ;
if ( V_26 ) {
F_33 () ;
F_42 () ;
}
return V_26 ;
}
static void F_46 ( void )
{
F_33 () ;
F_42 () ;
}
