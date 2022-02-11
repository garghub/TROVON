static inline T_1 F_1 ( int V_1 )
{
return ( V_1 & ( V_2 - 1 ) ) ;
}
static inline struct V_3 * F_2 ( int V_1 )
{
int V_4 = F_1 ( V_1 ) ;
struct V_3 * V_5 ;
F_3 (netif, &sel_netif_hash[idx], list)
if ( F_4 ( V_5 -> V_6 . V_1 == V_1 ) )
return V_5 ;
return NULL ;
}
static int F_5 ( struct V_3 * V_5 )
{
int V_4 ;
if ( V_7 >= V_8 )
return - V_9 ;
V_4 = F_1 ( V_5 -> V_6 . V_1 ) ;
F_6 ( & V_5 -> V_10 , & V_11 [ V_4 ] ) ;
V_7 ++ ;
return 0 ;
}
static void F_7 ( struct V_3 * V_5 )
{
F_8 ( & V_5 -> V_10 ) ;
V_7 -- ;
F_9 ( V_5 , V_12 ) ;
}
static int F_10 ( int V_1 , T_1 * V_13 )
{
int V_14 ;
struct V_3 * V_5 ;
struct V_3 * V_15 = NULL ;
struct V_16 * V_17 ;
V_17 = F_11 ( & V_18 , V_1 ) ;
if ( F_12 ( V_17 == NULL ) ) {
F_13 ( V_19
L_1
L_2 , V_1 ) ;
return - V_20 ;
}
F_14 ( & V_21 ) ;
V_5 = F_2 ( V_1 ) ;
if ( V_5 != NULL ) {
* V_13 = V_5 -> V_6 . V_13 ;
V_14 = 0 ;
goto V_22;
}
V_15 = F_15 ( sizeof( * V_15 ) , V_23 ) ;
if ( V_15 == NULL ) {
V_14 = - V_24 ;
goto V_22;
}
V_14 = F_16 ( V_17 -> V_25 , & V_15 -> V_6 . V_13 ) ;
if ( V_14 != 0 )
goto V_22;
V_15 -> V_6 . V_1 = V_1 ;
V_14 = F_5 ( V_15 ) ;
if ( V_14 != 0 )
goto V_22;
* V_13 = V_15 -> V_6 . V_13 ;
V_22:
F_17 ( & V_21 ) ;
F_18 ( V_17 ) ;
if ( F_12 ( V_14 ) ) {
F_13 ( V_19
L_1
L_3 ,
V_1 ) ;
F_19 ( V_15 ) ;
}
return V_14 ;
}
int F_20 ( int V_1 , T_1 * V_13 )
{
struct V_3 * V_5 ;
F_21 () ;
V_5 = F_2 ( V_1 ) ;
if ( F_4 ( V_5 != NULL ) ) {
* V_13 = V_5 -> V_6 . V_13 ;
F_22 () ;
return 0 ;
}
F_22 () ;
return F_10 ( V_1 , V_13 ) ;
}
static void F_23 ( int V_1 )
{
struct V_3 * V_5 ;
F_21 () ;
F_14 ( & V_21 ) ;
V_5 = F_2 ( V_1 ) ;
if ( V_5 )
F_7 ( V_5 ) ;
F_17 ( & V_21 ) ;
F_22 () ;
}
static void F_24 ( void )
{
int V_4 ;
struct V_3 * V_5 ;
F_14 ( & V_21 ) ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ )
F_25 (netif, &sel_netif_hash[idx], list)
F_7 ( V_5 ) ;
F_17 ( & V_21 ) ;
}
static int F_26 ( T_1 V_26 )
{
if ( V_26 == V_27 ) {
F_24 () ;
F_27 () ;
}
return 0 ;
}
static int F_28 ( struct V_28 * V_29 ,
unsigned long V_26 , void * V_30 )
{
struct V_16 * V_17 = V_30 ;
if ( F_29 ( V_17 ) != & V_18 )
return V_31 ;
if ( V_26 == V_32 )
F_23 ( V_17 -> V_1 ) ;
return V_31 ;
}
static T_2 int F_30 ( void )
{
int V_33 , V_34 ;
if ( ! V_35 )
return 0 ;
for ( V_33 = 0 ; V_33 < V_2 ; V_33 ++ )
F_31 ( & V_11 [ V_33 ] ) ;
F_32 ( & V_36 ) ;
V_34 = F_33 ( F_26 , V_27 ) ;
if ( V_34 )
F_34 ( L_4 , V_34 ) ;
return V_34 ;
}
