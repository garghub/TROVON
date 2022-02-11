static inline T_1 F_1 ( const struct V_1 * V_2 , int V_3 )
{
return ( ( ( V_4 ) V_2 + V_3 ) & ( V_5 - 1 ) ) ;
}
static inline struct V_6 * F_2 ( const struct V_1 * V_2 ,
int V_3 )
{
int V_7 = F_1 ( V_2 , V_3 ) ;
struct V_6 * V_8 ;
F_3 (netif, &sel_netif_hash[idx], list)
if ( F_4 ( V_8 -> V_9 . V_2 , V_2 ) &&
V_8 -> V_9 . V_3 == V_3 )
return V_8 ;
return NULL ;
}
static int F_5 ( struct V_6 * V_8 )
{
int V_7 ;
if ( V_10 >= V_11 )
return - V_12 ;
V_7 = F_1 ( V_8 -> V_9 . V_2 , V_8 -> V_9 . V_3 ) ;
F_6 ( & V_8 -> V_13 , & V_14 [ V_7 ] ) ;
V_10 ++ ;
return 0 ;
}
static void F_7 ( struct V_6 * V_8 )
{
F_8 ( & V_8 -> V_13 ) ;
V_10 -- ;
F_9 ( V_8 , V_15 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 , T_1 * V_16 )
{
int V_17 ;
struct V_6 * V_8 ;
struct V_6 * V_18 = NULL ;
struct V_19 * V_20 ;
V_20 = F_11 ( V_2 , V_3 ) ;
if ( F_12 ( V_20 == NULL ) ) {
F_13 ( V_21
L_1
L_2 , V_3 ) ;
return - V_22 ;
}
F_14 ( & V_23 ) ;
V_8 = F_2 ( V_2 , V_3 ) ;
if ( V_8 != NULL ) {
* V_16 = V_8 -> V_9 . V_16 ;
V_17 = 0 ;
goto V_24;
}
V_18 = F_15 ( sizeof( * V_18 ) , V_25 ) ;
if ( V_18 == NULL ) {
V_17 = - V_26 ;
goto V_24;
}
V_17 = F_16 ( V_20 -> V_27 , & V_18 -> V_9 . V_16 ) ;
if ( V_17 != 0 )
goto V_24;
V_18 -> V_9 . V_2 = V_2 ;
V_18 -> V_9 . V_3 = V_3 ;
V_17 = F_5 ( V_18 ) ;
if ( V_17 != 0 )
goto V_24;
* V_16 = V_18 -> V_9 . V_16 ;
V_24:
F_17 ( & V_23 ) ;
F_18 ( V_20 ) ;
if ( F_12 ( V_17 ) ) {
F_13 ( V_21
L_1
L_3 ,
V_3 ) ;
F_19 ( V_18 ) ;
}
return V_17 ;
}
int F_20 ( struct V_1 * V_2 , int V_3 , T_1 * V_16 )
{
struct V_6 * V_8 ;
F_21 () ;
V_8 = F_2 ( V_2 , V_3 ) ;
if ( F_22 ( V_8 != NULL ) ) {
* V_16 = V_8 -> V_9 . V_16 ;
F_23 () ;
return 0 ;
}
F_23 () ;
return F_10 ( V_2 , V_3 , V_16 ) ;
}
static void F_24 ( const struct V_1 * V_2 , int V_3 )
{
struct V_6 * V_8 ;
F_21 () ;
F_14 ( & V_23 ) ;
V_8 = F_2 ( V_2 , V_3 ) ;
if ( V_8 )
F_7 ( V_8 ) ;
F_17 ( & V_23 ) ;
F_23 () ;
}
void F_25 ( void )
{
int V_7 ;
struct V_6 * V_8 ;
F_14 ( & V_23 ) ;
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ )
F_26 (netif, &sel_netif_hash[idx], list)
F_7 ( V_8 ) ;
F_17 ( & V_23 ) ;
}
static int F_27 ( struct V_28 * V_29 ,
unsigned long V_30 , void * V_31 )
{
struct V_19 * V_20 = F_28 ( V_31 ) ;
if ( V_30 == V_32 )
F_24 ( F_29 ( V_20 ) , V_20 -> V_3 ) ;
return V_33 ;
}
static T_2 int F_30 ( void )
{
int V_34 ;
if ( ! V_35 )
return 0 ;
for ( V_34 = 0 ; V_34 < V_5 ; V_34 ++ )
F_31 ( & V_14 [ V_34 ] ) ;
F_32 ( & V_36 ) ;
return 0 ;
}
