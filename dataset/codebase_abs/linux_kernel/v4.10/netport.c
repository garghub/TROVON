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
F_7 (
V_9 [ V_5 ] . V_8 . V_13 ,
F_8 ( & V_14 ) ) ,
struct V_3 , V_8 ) ;
F_9 ( & V_12 -> V_8 ) ;
F_10 ( V_12 , V_15 ) ;
} else
V_9 [ V_5 ] . V_10 ++ ;
}
static int F_11 ( T_2 V_4 , T_1 V_1 , T_3 * V_16 )
{
int V_17 = - V_18 ;
struct V_3 * V_6 ;
struct V_3 * V_19 = NULL ;
F_12 ( & V_14 ) ;
V_6 = F_2 ( V_4 , V_1 ) ;
if ( V_6 != NULL ) {
* V_16 = V_6 -> V_7 . V_16 ;
F_13 ( & V_14 ) ;
return 0 ;
}
V_19 = F_14 ( sizeof( * V_19 ) , V_20 ) ;
if ( V_19 == NULL )
goto V_21;
V_17 = F_15 ( V_4 , V_1 , V_16 ) ;
if ( V_17 != 0 )
goto V_21;
V_19 -> V_7 . V_6 = V_1 ;
V_19 -> V_7 . V_4 = V_4 ;
V_19 -> V_7 . V_16 = * V_16 ;
F_4 ( V_19 ) ;
V_21:
F_13 ( & V_14 ) ;
if ( F_16 ( V_17 ) ) {
F_17 ( V_22
L_1
L_2 ) ;
F_18 ( V_19 ) ;
}
return V_17 ;
}
int F_19 ( T_2 V_4 , T_1 V_1 , T_3 * V_16 )
{
struct V_3 * V_6 ;
F_20 () ;
V_6 = F_2 ( V_4 , V_1 ) ;
if ( V_6 != NULL ) {
* V_16 = V_6 -> V_7 . V_16 ;
F_21 () ;
return 0 ;
}
F_21 () ;
return F_11 ( V_4 , V_1 , V_16 ) ;
}
void F_22 ( void )
{
unsigned int V_5 ;
struct V_3 * V_6 , * V_23 ;
F_12 ( & V_14 ) ;
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ ) {
F_23 (port, port_tmp,
&sel_netport_hash[idx].list, list) {
F_9 ( & V_6 -> V_8 ) ;
F_10 ( V_6 , V_15 ) ;
}
V_9 [ V_5 ] . V_10 = 0 ;
}
F_13 ( & V_14 ) ;
}
static T_4 int F_24 ( void )
{
int V_24 ;
if ( ! V_25 )
return 0 ;
for ( V_24 = 0 ; V_24 < V_2 ; V_24 ++ ) {
F_25 ( & V_9 [ V_24 ] . V_8 ) ;
V_9 [ V_24 ] . V_10 = 0 ;
}
return 0 ;
}
