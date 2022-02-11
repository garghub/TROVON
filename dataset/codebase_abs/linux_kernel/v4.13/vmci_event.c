int T_1 F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
F_2 ( & V_3 [ V_1 ] ) ;
return V_4 ;
}
void F_3 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ ) {
struct V_6 * V_7 , * V_8 ;
F_4 (cur, p2, &subscriber_array[e], node) {
F_5 ( L_1 ) ;
F_6 ( & V_7 -> V_9 ) ;
F_7 ( V_7 ) ;
}
}
}
static struct V_6 * F_8 ( T_2 V_10 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ ) {
struct V_6 * V_7 ;
F_9 (cur, &subscriber_array[e], node) {
if ( V_7 -> V_11 == V_10 )
return V_7 ;
}
}
return NULL ;
}
static void F_10 ( struct V_12 * V_13 )
{
struct V_6 * V_7 ;
struct V_14 * V_15 ;
F_11 () ;
V_15 = & V_3 [ V_13 -> V_16 . V_17 ] ;
F_12 (cur, subscriber_list, node) {
V_7 -> V_18 ( V_7 -> V_11 , & V_13 -> V_16 ,
V_7 -> V_19 ) ;
}
F_13 () ;
}
int F_14 ( struct V_20 * V_21 )
{
struct V_12 * V_13 = (struct V_12 * ) V_21 ;
if ( V_21 -> V_22 < sizeof( T_2 ) ||
V_21 -> V_22 > sizeof( struct V_23 ) )
return V_24 ;
if ( ! F_15 ( V_13 -> V_16 . V_17 ) )
return V_25 ;
F_10 ( V_13 ) ;
return V_4 ;
}
int F_16 ( T_2 V_17 ,
T_3 V_18 ,
void * V_19 ,
T_2 * V_26 )
{
struct V_6 * V_27 ;
int V_28 ;
int V_29 ;
bool V_30 = false ;
if ( ! V_26 ) {
F_17 ( L_2 , V_31 ) ;
return V_24 ;
}
if ( ! F_15 ( V_17 ) || ! V_18 ) {
F_17 ( L_3 ,
V_31 , V_17 , V_18 , V_19 ) ;
return V_24 ;
}
V_27 = F_18 ( sizeof( * V_27 ) , V_32 ) ;
if ( ! V_27 )
return V_33 ;
V_27 -> V_11 = V_2 ;
V_27 -> V_17 = V_17 ;
V_27 -> V_18 = V_18 ;
V_27 -> V_19 = V_19 ;
F_2 ( & V_27 -> V_9 ) ;
F_19 ( & V_34 ) ;
for ( V_28 = 0 ; V_28 < V_35 ; V_28 ++ ) {
static T_2 V_36 ;
if ( ! F_8 ( ++ V_36 ) ) {
V_27 -> V_11 = V_36 ;
V_30 = true ;
break;
}
}
if ( V_30 ) {
F_20 ( & V_27 -> V_9 , & V_3 [ V_17 ] ) ;
V_29 = V_4 ;
} else {
V_29 = V_37 ;
}
F_21 ( & V_34 ) ;
* V_26 = V_27 -> V_11 ;
return V_29 ;
}
int F_22 ( T_2 V_10 )
{
struct V_6 * V_38 ;
F_19 ( & V_34 ) ;
V_38 = F_8 ( V_10 ) ;
if ( V_38 )
F_23 ( & V_38 -> V_9 ) ;
F_21 ( & V_34 ) ;
if ( ! V_38 )
return V_39 ;
F_24 () ;
F_7 ( V_38 ) ;
return V_4 ;
}
