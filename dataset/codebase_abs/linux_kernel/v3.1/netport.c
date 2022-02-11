static unsigned int F_1 ( T_1 V_1 )
{
return ( V_1 & ( V_2 - 1 ) ) ;
}
static struct V_3 * F_2 ( T_2 V_4 , T_1 V_1 )
{
unsigned int V_5 ;
struct V_3 * V_6 ;
V_5 = F_1 ( V_1 ) ;
F_3 (port, &sel_netport_hash[idx].list, list)
if ( V_6 -> V_7 . V_6 == V_1 && V_6 -> V_7 . V_4 == V_4 )
return V_6 ;
return NULL ;
}
static void F_4 ( struct V_3 * V_6 )
{
unsigned int V_5 ;
V_5 = F_1 ( V_6 -> V_7 . V_6 ) ;
F_5 ( & V_6 -> V_8 , & V_9 [ V_5 ] . V_8 ) ;
if ( V_9 [ V_5 ] . V_10 == V_11 ) {
struct V_3 * V_12 ;
V_12 = F_6 (
F_7 ( V_9 [ V_5 ] . V_8 . V_13 ) ,
struct V_3 , V_8 ) ;
F_8 ( & V_12 -> V_8 ) ;
F_9 ( V_12 , V_14 ) ;
} else
V_9 [ V_5 ] . V_10 ++ ;
}
static int F_10 ( T_2 V_4 , T_1 V_1 , T_3 * V_15 )
{
int V_16 = - V_17 ;
struct V_3 * V_6 ;
struct V_3 * V_18 = NULL ;
F_11 ( & V_19 ) ;
V_6 = F_2 ( V_4 , V_1 ) ;
if ( V_6 != NULL ) {
* V_15 = V_6 -> V_7 . V_15 ;
F_12 ( & V_19 ) ;
return 0 ;
}
V_18 = F_13 ( sizeof( * V_18 ) , V_20 ) ;
if ( V_18 == NULL )
goto V_21;
V_16 = F_14 ( V_4 , V_1 , V_15 ) ;
if ( V_16 != 0 )
goto V_21;
V_18 -> V_7 . V_6 = V_1 ;
V_18 -> V_7 . V_4 = V_4 ;
V_18 -> V_7 . V_15 = * V_15 ;
F_4 ( V_18 ) ;
V_21:
F_12 ( & V_19 ) ;
if ( F_15 ( V_16 ) ) {
F_16 ( V_22
L_1
L_2 ) ;
F_17 ( V_18 ) ;
}
return V_16 ;
}
int F_18 ( T_2 V_4 , T_1 V_1 , T_3 * V_15 )
{
struct V_3 * V_6 ;
F_19 () ;
V_6 = F_2 ( V_4 , V_1 ) ;
if ( V_6 != NULL ) {
* V_15 = V_6 -> V_7 . V_15 ;
F_20 () ;
return 0 ;
}
F_20 () ;
return F_10 ( V_4 , V_1 , V_15 ) ;
}
static void F_21 ( void )
{
unsigned int V_5 ;
struct V_3 * V_6 , * V_23 ;
F_11 ( & V_19 ) ;
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ ) {
F_22 (port, port_tmp,
&sel_netport_hash[idx].list, list) {
F_8 ( & V_6 -> V_8 ) ;
F_9 ( V_6 , V_14 ) ;
}
V_9 [ V_5 ] . V_10 = 0 ;
}
F_12 ( & V_19 ) ;
}
static int F_23 ( T_3 V_24 , T_3 V_25 , T_3 V_26 ,
T_1 V_27 , T_3 V_28 , T_3 * V_29 )
{
if ( V_24 == V_30 ) {
F_21 () ;
F_24 () ;
}
return 0 ;
}
static T_4 int F_25 ( void )
{
int V_31 ;
int V_16 ;
if ( ! V_32 )
return 0 ;
for ( V_31 = 0 ; V_31 < V_2 ; V_31 ++ ) {
F_26 ( & V_9 [ V_31 ] . V_8 ) ;
V_9 [ V_31 ] . V_10 = 0 ;
}
V_16 = F_27 ( F_23 , V_30 ,
V_33 , V_33 , V_34 , 0 ) ;
if ( V_16 != 0 )
F_28 ( L_3 , V_16 ) ;
return V_16 ;
}
