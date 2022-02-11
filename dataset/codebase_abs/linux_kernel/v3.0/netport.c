static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 ) ;
}
static unsigned int F_4 ( T_1 V_6 )
{
return ( V_6 & ( V_7 - 1 ) ) ;
}
static struct V_3 * F_5 ( T_2 V_8 , T_1 V_6 )
{
unsigned int V_9 ;
struct V_3 * V_4 ;
V_9 = F_4 ( V_6 ) ;
F_6 (port, &sel_netport_hash[idx].list, list)
if ( V_4 -> V_10 . V_4 == V_6 && V_4 -> V_10 . V_8 == V_8 )
return V_4 ;
return NULL ;
}
static void F_7 ( struct V_3 * V_4 )
{
unsigned int V_9 ;
V_9 = F_4 ( V_4 -> V_10 . V_4 ) ;
F_8 ( & V_4 -> V_11 , & V_12 [ V_9 ] . V_11 ) ;
if ( V_12 [ V_9 ] . V_13 == V_14 ) {
struct V_3 * V_15 ;
V_15 = F_9 (
F_10 ( V_12 [ V_9 ] . V_11 . V_16 ) ,
struct V_3 , V_11 ) ;
F_11 ( & V_15 -> V_11 ) ;
F_12 ( & V_15 -> V_5 , F_1 ) ;
} else
V_12 [ V_9 ] . V_13 ++ ;
}
static int F_13 ( T_2 V_8 , T_1 V_6 , T_3 * V_17 )
{
int V_18 = - V_19 ;
struct V_3 * V_4 ;
struct V_3 * V_20 = NULL ;
F_14 ( & V_21 ) ;
V_4 = F_5 ( V_8 , V_6 ) ;
if ( V_4 != NULL ) {
* V_17 = V_4 -> V_10 . V_17 ;
F_15 ( & V_21 ) ;
return 0 ;
}
V_20 = F_16 ( sizeof( * V_20 ) , V_22 ) ;
if ( V_20 == NULL )
goto V_23;
V_18 = F_17 ( V_8 , V_6 , V_17 ) ;
if ( V_18 != 0 )
goto V_23;
V_20 -> V_10 . V_4 = V_6 ;
V_20 -> V_10 . V_8 = V_8 ;
V_20 -> V_10 . V_17 = * V_17 ;
F_7 ( V_20 ) ;
V_23:
F_15 ( & V_21 ) ;
if ( F_18 ( V_18 ) ) {
F_19 ( V_24
L_1
L_2 ) ;
F_3 ( V_20 ) ;
}
return V_18 ;
}
int F_20 ( T_2 V_8 , T_1 V_6 , T_3 * V_17 )
{
struct V_3 * V_4 ;
F_21 () ;
V_4 = F_5 ( V_8 , V_6 ) ;
if ( V_4 != NULL ) {
* V_17 = V_4 -> V_10 . V_17 ;
F_22 () ;
return 0 ;
}
F_22 () ;
return F_13 ( V_8 , V_6 , V_17 ) ;
}
static void F_23 ( void )
{
unsigned int V_9 ;
struct V_3 * V_4 , * V_25 ;
F_14 ( & V_21 ) ;
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ ) {
F_24 (port, port_tmp,
&sel_netport_hash[idx].list, list) {
F_11 ( & V_4 -> V_11 ) ;
F_12 ( & V_4 -> V_5 , F_1 ) ;
}
V_12 [ V_9 ] . V_13 = 0 ;
}
F_15 ( & V_21 ) ;
}
static int F_25 ( T_3 V_26 , T_3 V_27 , T_3 V_28 ,
T_1 V_29 , T_3 V_30 , T_3 * V_31 )
{
if ( V_26 == V_32 ) {
F_23 () ;
F_26 () ;
}
return 0 ;
}
static T_4 int F_27 ( void )
{
int V_33 ;
int V_18 ;
if ( ! V_34 )
return 0 ;
for ( V_33 = 0 ; V_33 < V_7 ; V_33 ++ ) {
F_28 ( & V_12 [ V_33 ] . V_11 ) ;
V_12 [ V_33 ] . V_13 = 0 ;
}
V_18 = F_29 ( F_25 , V_32 ,
V_35 , V_35 , V_36 , 0 ) ;
if ( V_18 != 0 )
F_30 ( L_3 , V_18 ) ;
return V_18 ;
}
