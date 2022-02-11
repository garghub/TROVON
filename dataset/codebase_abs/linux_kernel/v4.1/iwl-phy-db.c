struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( sizeof( struct V_1 ) ,
V_5 ) ;
if ( ! V_4 )
return V_4 ;
V_4 -> V_3 = V_3 ;
return V_4 ;
}
static struct V_6 *
F_3 ( struct V_1 * V_4 ,
enum V_7 type ,
T_1 V_8 )
{
if ( ! V_4 || type >= V_9 )
return NULL ;
switch ( type ) {
case V_10 :
return & V_4 -> V_11 ;
case V_12 :
return & V_4 -> V_13 ;
case V_14 :
if ( V_8 >= V_15 )
return NULL ;
return & V_4 -> V_16 [ V_8 ] ;
case V_17 :
if ( V_8 >= V_18 )
return NULL ;
return & V_4 -> V_19 [ V_8 ] ;
default:
return NULL ;
}
return NULL ;
}
static void F_4 ( struct V_1 * V_4 ,
enum V_7 type ,
T_1 V_8 )
{
struct V_6 * V_20 =
F_3 ( V_4 , type , V_8 ) ;
if ( ! V_20 )
return;
F_5 ( V_20 -> V_21 ) ;
V_20 -> V_21 = NULL ;
V_20 -> V_22 = 0 ;
}
void F_6 ( struct V_1 * V_4 )
{
int V_23 ;
if ( ! V_4 )
return;
F_4 ( V_4 , V_10 , 0 ) ;
F_4 ( V_4 , V_12 , 0 ) ;
for ( V_23 = 0 ; V_23 < V_15 ; V_23 ++ )
F_4 ( V_4 , V_14 , V_23 ) ;
for ( V_23 = 0 ; V_23 < V_18 ; V_23 ++ )
F_4 ( V_4 , V_17 , V_23 ) ;
F_5 ( V_4 ) ;
}
int F_7 ( struct V_1 * V_4 , struct V_24 * V_25 ,
T_2 V_26 )
{
struct V_27 * V_28 =
(struct V_27 * ) V_25 -> V_21 ;
enum V_7 type = F_8 ( V_28 -> type ) ;
T_1 V_22 = F_8 ( V_28 -> V_29 ) ;
struct V_6 * V_20 ;
T_1 V_8 = 0 ;
if ( ! V_4 )
return - V_30 ;
if ( type == V_14 ||
type == V_17 )
V_8 = F_9 ( ( V_31 * ) V_28 -> V_21 ) ;
V_20 = F_3 ( V_4 , type , V_8 ) ;
if ( ! V_20 )
return - V_30 ;
F_5 ( V_20 -> V_21 ) ;
V_20 -> V_21 = F_10 ( V_28 -> V_21 , V_22 , V_26 ) ;
if ( ! V_20 -> V_21 ) {
V_20 -> V_22 = 0 ;
return - V_32 ;
}
V_20 -> V_22 = V_22 ;
F_11 ( V_4 -> V_3 ,
L_1 ,
V_33 , __LINE__ , type , V_22 ) ;
return 0 ;
}
static int F_12 ( T_1 V_34 )
{
if ( V_34 <= 14 ||
( 36 <= V_34 && V_34 <= 64 && V_34 % 4 == 0 ) ||
( 100 <= V_34 && V_34 <= 140 && V_34 % 4 == 0 ) ||
( 145 <= V_34 && V_34 <= 165 && V_34 % 4 == 1 ) )
return 1 ;
return 0 ;
}
static T_3 F_13 ( T_1 V_34 )
{
if ( F_14 ( ! F_12 ( V_34 ) ) )
return 0xff ;
if ( V_34 <= 14 )
return V_34 - 1 ;
if ( V_34 <= 64 )
return ( V_34 + 20 ) / 4 ;
if ( V_34 <= 140 )
return ( V_34 - 12 ) / 4 ;
return ( V_34 - 13 ) / 4 ;
}
static T_1 F_15 ( T_1 V_34 )
{
if ( F_14 ( ! F_12 ( V_34 ) ) )
return 0xff ;
if ( 1 <= V_34 && V_34 <= 14 )
return 0 ;
if ( 36 <= V_34 && V_34 <= 64 )
return 1 ;
if ( 100 <= V_34 && V_34 <= 140 )
return 2 ;
return 3 ;
}
static T_1 F_16 ( struct V_1 * V_4 , T_1 V_34 )
{
struct V_35 * V_36 ;
int V_23 ;
T_3 V_37 = F_13 ( V_34 ) ;
if ( V_37 == 0xff )
return 0xff ;
for ( V_23 = 0 ; V_23 < V_18 ; V_23 ++ ) {
V_36 = ( void * ) V_4 -> V_19 [ V_23 ] . V_21 ;
if ( ! V_36 )
return 0xff ;
if ( F_8 ( V_36 -> V_38 ) >= V_37 )
return V_23 ;
}
return 0xff ;
}
static
int F_17 ( struct V_1 * V_4 ,
T_4 type , T_3 * * V_21 , T_1 * V_22 , T_1 V_34 )
{
struct V_6 * V_20 ;
T_1 V_39 = 0 ;
if ( ! V_4 )
return - V_30 ;
if ( type == V_14 )
V_39 = F_15 ( V_34 ) ;
else if ( type == V_17 )
V_39 = F_16 ( V_4 , V_34 ) ;
V_20 = F_3 ( V_4 , type , V_39 ) ;
if ( ! V_20 )
return - V_30 ;
* V_21 = V_20 -> V_21 ;
* V_22 = V_20 -> V_22 ;
F_11 ( V_4 -> V_3 ,
L_2 ,
V_33 , __LINE__ , type , * V_22 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_4 , T_1 type ,
T_1 V_29 , void * V_21 )
{
struct V_40 V_41 ;
struct V_42 V_43 = {
. V_44 = V_45 ,
} ;
F_11 ( V_4 -> V_3 ,
L_3 ,
type , V_29 ) ;
V_41 . type = F_19 ( type ) ;
V_41 . V_29 = F_19 ( V_29 ) ;
V_43 . V_21 [ 0 ] = & V_41 ;
V_43 . V_46 [ 0 ] = sizeof( struct V_40 ) ;
V_43 . V_21 [ 1 ] = V_21 ;
V_43 . V_46 [ 1 ] = V_29 ;
V_43 . V_47 [ 1 ] = V_48 ;
return F_20 ( V_4 -> V_3 , & V_43 ) ;
}
static int F_21 (
struct V_1 * V_4 ,
enum V_7 type ,
T_3 V_49 )
{
T_1 V_23 ;
int V_50 ;
struct V_6 * V_20 ;
for ( V_23 = 0 ; V_23 < V_49 ; V_23 ++ ) {
V_20 = F_3 ( V_4 ,
type ,
V_23 ) ;
if ( ! V_20 )
return - V_30 ;
if ( ! V_20 -> V_22 )
continue;
V_50 = F_18 ( V_4 ,
type ,
V_20 -> V_22 ,
V_20 -> V_21 ) ;
if ( V_50 ) {
F_22 ( V_4 -> V_3 ,
L_4 ,
type , V_23 , V_50 ) ;
return V_50 ;
}
F_11 ( V_4 -> V_3 ,
L_5 ,
type , V_23 ) ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_4 )
{
T_3 * V_21 = NULL ;
T_1 V_22 = 0 ;
int V_50 ;
F_11 ( V_4 -> V_3 ,
L_6 ) ;
V_50 = F_17 ( V_4 , V_10 ,
& V_21 , & V_22 , 0 ) ;
if ( V_50 ) {
F_22 ( V_4 -> V_3 , L_7 ) ;
return V_50 ;
}
V_50 = F_18 ( V_4 , V_10 , V_22 , V_21 ) ;
if ( V_50 ) {
F_22 ( V_4 -> V_3 ,
L_8 ) ;
return V_50 ;
}
V_50 = F_17 ( V_4 , V_12 ,
& V_21 , & V_22 , 0 ) ;
if ( V_50 ) {
F_22 ( V_4 -> V_3 ,
L_9 ) ;
return V_50 ;
}
V_50 = F_18 ( V_4 , V_12 , V_22 , V_21 ) ;
if ( V_50 ) {
F_22 ( V_4 -> V_3 ,
L_10 ) ;
return V_50 ;
}
V_50 = F_21 ( V_4 ,
V_14 ,
V_15 ) ;
if ( V_50 ) {
F_22 ( V_4 -> V_3 ,
L_11 ) ;
return V_50 ;
}
V_50 = F_21 ( V_4 ,
V_17 ,
V_18 ) ;
if ( V_50 ) {
F_22 ( V_4 -> V_3 ,
L_12 ) ;
return V_50 ;
}
F_11 ( V_4 -> V_3 ,
L_13 ) ;
return 0 ;
}
