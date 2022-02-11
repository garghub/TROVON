static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 ) ;
}
static unsigned int F_4 ( T_1 V_6 )
{
return ( V_6 & ( V_7 - 1 ) ) ;
}
static unsigned int F_5 ( const struct V_8 * V_6 )
{
return ( V_6 -> V_9 [ 3 ] & ( V_7 - 1 ) ) ;
}
static struct V_3 * F_6 ( const void * V_6 , T_2 V_10 )
{
unsigned int V_11 ;
struct V_3 * V_4 ;
switch ( V_10 ) {
case V_12 :
V_11 = F_4 ( * ( T_1 * ) V_6 ) ;
break;
case V_13 :
V_11 = F_5 ( V_6 ) ;
break;
default:
F_7 () ;
return NULL ;
}
F_8 (node, &sel_netnode_hash[idx].list, list)
if ( V_4 -> V_14 . V_10 == V_10 )
switch ( V_10 ) {
case V_12 :
if ( V_4 -> V_14 . V_6 . V_15 == * ( T_1 * ) V_6 )
return V_4 ;
break;
case V_13 :
if ( F_9 ( & V_4 -> V_14 . V_6 . V_16 ,
V_6 ) )
return V_4 ;
break;
}
return NULL ;
}
static void F_10 ( struct V_3 * V_4 )
{
unsigned int V_11 ;
switch ( V_4 -> V_14 . V_10 ) {
case V_12 :
V_11 = F_4 ( V_4 -> V_14 . V_6 . V_15 ) ;
break;
case V_13 :
V_11 = F_5 ( & V_4 -> V_14 . V_6 . V_16 ) ;
break;
default:
F_7 () ;
}
F_11 ( & V_4 -> V_17 , & V_18 [ V_11 ] . V_17 ) ;
if ( V_18 [ V_11 ] . V_19 == V_20 ) {
struct V_3 * V_21 ;
V_21 = F_12 (
F_13 ( V_18 [ V_11 ] . V_17 . V_22 ) ,
struct V_3 , V_17 ) ;
F_14 ( & V_21 -> V_17 ) ;
F_15 ( & V_21 -> V_5 , F_1 ) ;
} else
V_18 [ V_11 ] . V_19 ++ ;
}
static int F_16 ( void * V_6 , T_2 V_10 , T_3 * V_23 )
{
int V_24 = - V_25 ;
struct V_3 * V_4 ;
struct V_3 * V_26 = NULL ;
F_17 ( & V_27 ) ;
V_4 = F_6 ( V_6 , V_10 ) ;
if ( V_4 != NULL ) {
* V_23 = V_4 -> V_14 . V_23 ;
F_18 ( & V_27 ) ;
return 0 ;
}
V_26 = F_19 ( sizeof( * V_26 ) , V_28 ) ;
if ( V_26 == NULL )
goto V_29;
switch ( V_10 ) {
case V_12 :
V_24 = F_20 ( V_12 ,
V_6 , sizeof( struct V_30 ) , V_23 ) ;
V_26 -> V_14 . V_6 . V_15 = * ( T_1 * ) V_6 ;
break;
case V_13 :
V_24 = F_20 ( V_13 ,
V_6 , sizeof( struct V_8 ) , V_23 ) ;
F_21 ( & V_26 -> V_14 . V_6 . V_16 , V_6 ) ;
break;
default:
F_7 () ;
}
if ( V_24 != 0 )
goto V_29;
V_26 -> V_14 . V_10 = V_10 ;
V_26 -> V_14 . V_23 = * V_23 ;
F_10 ( V_26 ) ;
V_29:
F_18 ( & V_27 ) ;
if ( F_22 ( V_24 ) ) {
F_23 ( V_31
L_1
L_2 ) ;
F_3 ( V_26 ) ;
}
return V_24 ;
}
int F_24 ( void * V_6 , T_2 V_10 , T_3 * V_23 )
{
struct V_3 * V_4 ;
F_25 () ;
V_4 = F_6 ( V_6 , V_10 ) ;
if ( V_4 != NULL ) {
* V_23 = V_4 -> V_14 . V_23 ;
F_26 () ;
return 0 ;
}
F_26 () ;
return F_16 ( V_6 , V_10 , V_23 ) ;
}
static void F_27 ( void )
{
unsigned int V_11 ;
struct V_3 * V_4 , * V_32 ;
F_17 ( & V_27 ) ;
for ( V_11 = 0 ; V_11 < V_7 ; V_11 ++ ) {
F_28 (node, node_tmp,
&sel_netnode_hash[idx].list, list) {
F_14 ( & V_4 -> V_17 ) ;
F_15 ( & V_4 -> V_5 , F_1 ) ;
}
V_18 [ V_11 ] . V_19 = 0 ;
}
F_18 ( & V_27 ) ;
}
static int F_29 ( T_3 V_33 , T_3 V_34 , T_3 V_35 ,
T_2 V_36 , T_3 V_37 , T_3 * V_38 )
{
if ( V_33 == V_39 ) {
F_27 () ;
F_30 () ;
}
return 0 ;
}
static T_4 int F_31 ( void )
{
int V_40 ;
int V_24 ;
if ( ! V_41 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_7 ; V_40 ++ ) {
F_32 ( & V_18 [ V_40 ] . V_17 ) ;
V_18 [ V_40 ] . V_19 = 0 ;
}
V_24 = F_33 ( F_29 , V_39 ,
V_42 , V_42 , V_43 , 0 ) ;
if ( V_24 != 0 )
F_34 ( L_3 , V_24 ) ;
return V_24 ;
}
