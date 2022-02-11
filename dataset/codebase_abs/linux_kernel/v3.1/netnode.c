static unsigned int F_1 ( T_1 V_1 )
{
return ( V_1 & ( V_2 - 1 ) ) ;
}
static unsigned int F_2 ( const struct V_3 * V_1 )
{
return ( V_1 -> V_4 [ 3 ] & ( V_2 - 1 ) ) ;
}
static struct V_5 * F_3 ( const void * V_1 , T_2 V_6 )
{
unsigned int V_7 ;
struct V_5 * V_8 ;
switch ( V_6 ) {
case V_9 :
V_7 = F_1 ( * ( T_1 * ) V_1 ) ;
break;
case V_10 :
V_7 = F_2 ( V_1 ) ;
break;
default:
F_4 () ;
return NULL ;
}
F_5 (node, &sel_netnode_hash[idx].list, list)
if ( V_8 -> V_11 . V_6 == V_6 )
switch ( V_6 ) {
case V_9 :
if ( V_8 -> V_11 . V_1 . V_12 == * ( T_1 * ) V_1 )
return V_8 ;
break;
case V_10 :
if ( F_6 ( & V_8 -> V_11 . V_1 . V_13 ,
V_1 ) )
return V_8 ;
break;
}
return NULL ;
}
static void F_7 ( struct V_5 * V_8 )
{
unsigned int V_7 ;
switch ( V_8 -> V_11 . V_6 ) {
case V_9 :
V_7 = F_1 ( V_8 -> V_11 . V_1 . V_12 ) ;
break;
case V_10 :
V_7 = F_2 ( & V_8 -> V_11 . V_1 . V_13 ) ;
break;
default:
F_4 () ;
}
F_8 ( & V_8 -> V_14 , & V_15 [ V_7 ] . V_14 ) ;
if ( V_15 [ V_7 ] . V_16 == V_17 ) {
struct V_5 * V_18 ;
V_18 = F_9 (
F_10 ( V_15 [ V_7 ] . V_14 . V_19 ) ,
struct V_5 , V_14 ) ;
F_11 ( & V_18 -> V_14 ) ;
F_12 ( V_18 , V_20 ) ;
} else
V_15 [ V_7 ] . V_16 ++ ;
}
static int F_13 ( void * V_1 , T_2 V_6 , T_3 * V_21 )
{
int V_22 = - V_23 ;
struct V_5 * V_8 ;
struct V_5 * V_24 = NULL ;
F_14 ( & V_25 ) ;
V_8 = F_3 ( V_1 , V_6 ) ;
if ( V_8 != NULL ) {
* V_21 = V_8 -> V_11 . V_21 ;
F_15 ( & V_25 ) ;
return 0 ;
}
V_24 = F_16 ( sizeof( * V_24 ) , V_26 ) ;
if ( V_24 == NULL )
goto V_27;
switch ( V_6 ) {
case V_9 :
V_22 = F_17 ( V_9 ,
V_1 , sizeof( struct V_28 ) , V_21 ) ;
V_24 -> V_11 . V_1 . V_12 = * ( T_1 * ) V_1 ;
break;
case V_10 :
V_22 = F_17 ( V_10 ,
V_1 , sizeof( struct V_3 ) , V_21 ) ;
F_18 ( & V_24 -> V_11 . V_1 . V_13 , V_1 ) ;
break;
default:
F_4 () ;
}
if ( V_22 != 0 )
goto V_27;
V_24 -> V_11 . V_6 = V_6 ;
V_24 -> V_11 . V_21 = * V_21 ;
F_7 ( V_24 ) ;
V_27:
F_15 ( & V_25 ) ;
if ( F_19 ( V_22 ) ) {
F_20 ( V_29
L_1
L_2 ) ;
F_21 ( V_24 ) ;
}
return V_22 ;
}
int F_22 ( void * V_1 , T_2 V_6 , T_3 * V_21 )
{
struct V_5 * V_8 ;
F_23 () ;
V_8 = F_3 ( V_1 , V_6 ) ;
if ( V_8 != NULL ) {
* V_21 = V_8 -> V_11 . V_21 ;
F_24 () ;
return 0 ;
}
F_24 () ;
return F_13 ( V_1 , V_6 , V_21 ) ;
}
static void F_25 ( void )
{
unsigned int V_7 ;
struct V_5 * V_8 , * V_30 ;
F_14 ( & V_25 ) ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
F_26 (node, node_tmp,
&sel_netnode_hash[idx].list, list) {
F_11 ( & V_8 -> V_14 ) ;
F_12 ( V_8 , V_20 ) ;
}
V_15 [ V_7 ] . V_16 = 0 ;
}
F_15 ( & V_25 ) ;
}
static int F_27 ( T_3 V_31 , T_3 V_32 , T_3 V_33 ,
T_2 V_34 , T_3 V_35 , T_3 * V_36 )
{
if ( V_31 == V_37 ) {
F_25 () ;
F_28 () ;
}
return 0 ;
}
static T_4 int F_29 ( void )
{
int V_38 ;
int V_22 ;
if ( ! V_39 )
return 0 ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
F_30 ( & V_15 [ V_38 ] . V_14 ) ;
V_15 [ V_38 ] . V_16 = 0 ;
}
V_22 = F_31 ( F_27 , V_37 ,
V_40 , V_40 , V_41 , 0 ) ;
if ( V_22 != 0 )
F_32 ( L_3 , V_22 ) ;
return V_22 ;
}
