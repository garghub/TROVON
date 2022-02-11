static inline struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
return & V_3 -> V_5 [ F_2 ( V_4 , V_3 -> V_6 ) ] ;
}
int F_3 ( struct V_2 * V_3 , T_2 V_7 , T_1 V_4 ,
T_3 V_8 , bool V_9 )
{
struct V_10 * V_11 , * V_12 ;
struct V_13 * V_14 ;
struct V_1 * V_15 ;
if ( V_3 -> V_16 >= V_3 -> V_17 )
F_4 ( & V_3 -> V_18 ) ;
if ( V_3 -> V_16 >= 2 * V_3 -> V_17 )
F_5 ( V_3 , V_19 ) ;
V_11 = F_6 ( V_20 , V_7 ) ;
if ( ! V_11 )
return - V_21 ;
F_7 ( & V_11 -> V_22 ) ;
F_8 ( & V_11 -> V_23 , 1 ) ;
V_11 -> V_24 = V_4 ;
V_11 -> V_25 = V_8 ;
V_11 -> V_26 = V_9 ;
V_15 = F_1 ( V_3 , V_4 ) ;
F_9 ( V_15 ) ;
F_10 (dup, dup_node, head, e_hash_list) {
if ( V_12 -> V_24 == V_4 && V_12 -> V_25 == V_8 ) {
F_11 ( V_15 ) ;
F_12 ( V_20 , V_11 ) ;
return - V_27 ;
}
}
F_13 ( & V_11 -> V_28 , V_15 ) ;
F_11 ( V_15 ) ;
F_14 ( & V_3 -> V_29 ) ;
F_15 ( & V_11 -> V_22 , & V_3 -> V_30 ) ;
F_16 ( & V_11 -> V_23 ) ;
V_3 -> V_16 ++ ;
F_17 ( & V_3 -> V_29 ) ;
return 0 ;
}
void F_18 ( struct V_10 * V_11 )
{
F_12 ( V_20 , V_11 ) ;
}
static struct V_10 * F_19 ( struct V_2 * V_3 ,
struct V_10 * V_11 ,
T_1 V_4 )
{
struct V_10 * V_31 = V_11 ;
struct V_13 * V_32 ;
struct V_1 * V_15 ;
V_15 = F_1 ( V_3 , V_4 ) ;
F_9 ( V_15 ) ;
if ( V_11 && ! F_20 ( & V_11 -> V_28 ) )
V_32 = V_11 -> V_28 . V_33 ;
else
V_32 = F_21 ( V_15 ) ;
while ( V_32 ) {
V_11 = F_22 ( V_32 , struct V_10 ,
V_28 ) ;
if ( V_11 -> V_24 == V_4 && V_11 -> V_26 ) {
F_16 ( & V_11 -> V_23 ) ;
goto V_34;
}
V_32 = V_32 -> V_33 ;
}
V_11 = NULL ;
V_34:
F_11 ( V_15 ) ;
if ( V_31 )
F_23 ( V_3 , V_31 ) ;
return V_11 ;
}
struct V_10 * F_24 ( struct V_2 * V_3 ,
T_1 V_4 )
{
return F_19 ( V_3 , NULL , V_4 ) ;
}
struct V_10 * F_25 ( struct V_2 * V_3 ,
struct V_10 * V_11 )
{
return F_19 ( V_3 , V_11 , V_11 -> V_24 ) ;
}
struct V_10 * F_26 ( struct V_2 * V_3 , T_1 V_4 ,
T_3 V_8 )
{
struct V_13 * V_32 ;
struct V_1 * V_15 ;
struct V_10 * V_11 ;
V_15 = F_1 ( V_3 , V_4 ) ;
F_9 ( V_15 ) ;
F_10 (entry, node, head, e_hash_list) {
if ( V_11 -> V_24 == V_4 && V_11 -> V_25 == V_8 ) {
F_16 ( & V_11 -> V_23 ) ;
goto V_34;
}
}
V_11 = NULL ;
V_34:
F_11 ( V_15 ) ;
return V_11 ;
}
void F_27 ( struct V_2 * V_3 , T_1 V_4 , T_3 V_8 )
{
struct V_13 * V_32 ;
struct V_1 * V_15 ;
struct V_10 * V_11 ;
V_15 = F_1 ( V_3 , V_4 ) ;
F_9 ( V_15 ) ;
F_10 (entry, node, head, e_hash_list) {
if ( V_11 -> V_24 == V_4 && V_11 -> V_25 == V_8 ) {
F_28 ( & V_11 -> V_28 ) ;
F_11 ( V_15 ) ;
F_14 ( & V_3 -> V_29 ) ;
if ( ! F_29 ( & V_11 -> V_22 ) ) {
F_30 ( & V_11 -> V_22 ) ;
V_3 -> V_16 -- ;
F_31 ( & V_11 -> V_23 ) ;
}
F_17 ( & V_3 -> V_29 ) ;
F_23 ( V_3 , V_11 ) ;
return;
}
}
F_11 ( V_15 ) ;
}
void F_32 ( struct V_2 * V_3 ,
struct V_10 * V_11 )
{
V_11 -> V_35 = 1 ;
}
static unsigned long F_33 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_2 * V_3 = F_34 ( V_37 , struct V_2 ,
V_40 ) ;
return V_3 -> V_16 ;
}
static unsigned long F_5 ( struct V_2 * V_3 ,
unsigned long V_41 )
{
struct V_10 * V_11 ;
struct V_1 * V_15 ;
unsigned long V_42 = 0 ;
F_14 ( & V_3 -> V_29 ) ;
while ( V_41 -- && ! F_29 ( & V_3 -> V_30 ) ) {
V_11 = F_35 ( & V_3 -> V_30 ,
struct V_10 , V_22 ) ;
if ( V_11 -> V_35 ) {
V_11 -> V_35 = 0 ;
F_36 ( & V_11 -> V_22 , & V_3 -> V_30 ) ;
continue;
}
F_30 ( & V_11 -> V_22 ) ;
V_3 -> V_16 -- ;
F_17 ( & V_3 -> V_29 ) ;
V_15 = F_1 ( V_3 , V_11 -> V_24 ) ;
F_9 ( V_15 ) ;
if ( ! F_20 ( & V_11 -> V_28 ) ) {
F_28 ( & V_11 -> V_28 ) ;
F_31 ( & V_11 -> V_23 ) ;
}
F_11 ( V_15 ) ;
if ( F_23 ( V_3 , V_11 ) )
V_42 ++ ;
F_37 () ;
F_14 ( & V_3 -> V_29 ) ;
}
F_17 ( & V_3 -> V_29 ) ;
return V_42 ;
}
static unsigned long F_38 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_2 * V_3 = F_34 ( V_37 , struct V_2 ,
V_40 ) ;
return F_5 ( V_3 , V_39 -> V_41 ) ;
}
static void F_39 ( struct V_43 * V_44 )
{
struct V_2 * V_3 = F_34 ( V_44 , struct V_2 ,
V_18 ) ;
F_5 ( V_3 , V_3 -> V_17 / V_45 ) ;
}
struct V_2 * F_40 ( int V_46 )
{
struct V_2 * V_3 ;
unsigned long V_47 = 1UL << V_46 ;
unsigned long V_48 ;
V_3 = F_41 ( sizeof( struct V_2 ) , V_49 ) ;
if ( ! V_3 )
goto V_50;
V_3 -> V_6 = V_46 ;
V_3 -> V_17 = V_47 << 4 ;
F_7 ( & V_3 -> V_30 ) ;
F_42 ( & V_3 -> V_29 ) ;
V_3 -> V_5 = F_43 ( V_47 * sizeof( struct V_1 ) ,
V_49 ) ;
if ( ! V_3 -> V_5 ) {
F_44 ( V_3 ) ;
goto V_50;
}
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ )
F_45 ( & V_3 -> V_5 [ V_48 ] ) ;
V_3 -> V_40 . V_51 = F_33 ;
V_3 -> V_40 . V_52 = F_38 ;
V_3 -> V_40 . V_53 = V_54 ;
if ( F_46 ( & V_3 -> V_40 ) ) {
F_44 ( V_3 -> V_5 ) ;
F_44 ( V_3 ) ;
goto V_50;
}
F_47 ( & V_3 -> V_18 , F_39 ) ;
return V_3 ;
V_50:
return NULL ;
}
void F_48 ( struct V_2 * V_3 )
{
struct V_10 * V_11 , * V_33 ;
F_49 ( & V_3 -> V_40 ) ;
F_50 (entry, next, &cache->c_list, e_list) {
if ( ! F_20 ( & V_11 -> V_28 ) ) {
F_28 ( & V_11 -> V_28 ) ;
F_31 ( & V_11 -> V_23 ) ;
} else
F_51 ( 1 ) ;
F_52 ( & V_11 -> V_22 ) ;
F_51 ( F_53 ( & V_11 -> V_23 ) != 1 ) ;
F_23 ( V_3 , V_11 ) ;
}
F_44 ( V_3 -> V_5 ) ;
F_44 ( V_3 ) ;
}
static int T_4 F_54 ( void )
{
V_20 = F_55 ( L_1 ,
sizeof( struct V_10 ) , 0 ,
V_55 | V_56 , NULL ) ;
if ( ! V_20 )
return - V_21 ;
return 0 ;
}
static void T_5 F_56 ( void )
{
F_57 ( V_20 ) ;
}
