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
return & V_4 -> V_15 ;
case V_16 :
if ( V_8 >= V_17 )
return NULL ;
return & V_4 -> V_18 [ V_8 ] ;
case V_19 :
if ( V_8 >= V_20 )
return NULL ;
return & V_4 -> V_21 [ V_8 ] ;
default:
return NULL ;
}
return NULL ;
}
static void F_4 ( struct V_1 * V_4 ,
enum V_7 type ,
T_1 V_8 )
{
struct V_6 * V_22 =
F_3 ( V_4 , type , V_8 ) ;
if ( ! V_22 )
return;
F_5 ( V_22 -> V_23 ) ;
V_22 -> V_23 = NULL ;
V_22 -> V_24 = 0 ;
}
void F_6 ( struct V_1 * V_4 )
{
int V_25 ;
if ( ! V_4 )
return;
F_4 ( V_4 , V_10 , 0 ) ;
F_4 ( V_4 , V_12 , 0 ) ;
F_4 ( V_4 , V_14 , 0 ) ;
for ( V_25 = 0 ; V_25 < V_17 ; V_25 ++ )
F_4 ( V_4 , V_16 , V_25 ) ;
for ( V_25 = 0 ; V_25 < V_20 ; V_25 ++ )
F_4 ( V_4 , V_19 , V_25 ) ;
F_5 ( V_4 ) ;
}
int F_7 ( struct V_1 * V_4 , struct V_26 * V_27 ,
T_2 V_28 )
{
struct V_29 * V_30 =
(struct V_29 * ) V_27 -> V_23 ;
enum V_7 type = F_8 ( V_30 -> type ) ;
T_1 V_24 = F_8 ( V_30 -> V_31 ) ;
struct V_6 * V_22 ;
T_1 V_8 = 0 ;
if ( ! V_4 )
return - V_32 ;
if ( type == V_16 ||
type == V_19 )
V_8 = F_9 ( ( V_33 * ) V_30 -> V_23 ) ;
V_22 = F_3 ( V_4 , type , V_8 ) ;
if ( ! V_22 )
return - V_32 ;
F_5 ( V_22 -> V_23 ) ;
V_22 -> V_23 = F_10 ( V_30 -> V_23 , V_24 , V_28 ) ;
if ( ! V_22 -> V_23 ) {
V_22 -> V_24 = 0 ;
return - V_34 ;
}
V_22 -> V_24 = V_24 ;
if ( type == V_14 ) {
V_4 -> V_35 =
F_11 ( ( V_36 * ) V_30 -> V_23 ) ;
V_4 -> V_37 =
( V_24 - V_38 ) / V_4 -> V_35 ;
}
F_12 ( V_4 -> V_3 ,
L_1 ,
V_39 , __LINE__ , type , V_24 ) ;
return 0 ;
}
static int F_13 ( T_1 V_40 )
{
if ( V_40 <= 14 ||
( 36 <= V_40 && V_40 <= 64 && V_40 % 4 == 0 ) ||
( 100 <= V_40 && V_40 <= 140 && V_40 % 4 == 0 ) ||
( 145 <= V_40 && V_40 <= 165 && V_40 % 4 == 1 ) )
return 1 ;
return 0 ;
}
static T_3 F_14 ( T_1 V_40 )
{
if ( F_15 ( ! F_13 ( V_40 ) ) )
return 0xff ;
if ( V_40 <= 14 )
return V_40 - 1 ;
if ( V_40 <= 64 )
return ( V_40 + 20 ) / 4 ;
if ( V_40 <= 140 )
return ( V_40 - 12 ) / 4 ;
return ( V_40 - 13 ) / 4 ;
}
static T_1 F_16 ( T_1 V_40 )
{
if ( F_15 ( ! F_13 ( V_40 ) ) )
return 0xff ;
if ( 1 <= V_40 && V_40 <= 14 )
return 0 ;
if ( 36 <= V_40 && V_40 <= 64 )
return 1 ;
if ( 100 <= V_40 && V_40 <= 140 )
return 2 ;
return 3 ;
}
static T_1 F_17 ( struct V_1 * V_4 , T_1 V_40 )
{
struct V_41 * V_42 ;
int V_25 ;
T_3 V_43 = F_14 ( V_40 ) ;
if ( V_43 == 0xff )
return 0xff ;
for ( V_25 = 0 ; V_25 < V_20 ; V_25 ++ ) {
V_42 = ( void * ) V_4 -> V_21 [ V_25 ] . V_23 ;
if ( ! V_42 )
return 0xff ;
if ( F_8 ( V_42 -> V_44 ) >= V_43 )
return V_25 ;
}
return 0xff ;
}
static
int F_18 ( struct V_1 * V_4 ,
T_4 type , T_3 * * V_23 , T_1 * V_24 , T_1 V_40 )
{
struct V_6 * V_22 ;
T_4 V_35 ;
T_4 V_37 ;
T_1 V_45 = 0 ;
T_1 V_46 ;
if ( ! V_4 )
return - V_32 ;
if ( type == V_16 )
V_45 = F_16 ( V_40 ) ;
else if ( type == V_19 )
V_45 = F_17 ( V_4 , V_40 ) ;
V_22 = F_3 ( V_4 , type , V_45 ) ;
if ( ! V_22 )
return - V_32 ;
if ( type == V_14 ) {
V_46 = F_14 ( V_40 ) ;
V_35 = V_4 -> V_35 ;
V_37 = V_4 -> V_37 ;
if ( V_46 >= V_35 ) {
F_19 ( V_4 -> V_3 , L_2 ,
V_40 ) ;
return - V_32 ;
}
* V_23 = V_22 -> V_23 + V_38 + V_46 * V_37 ;
* V_24 = V_37 ;
} else {
* V_23 = V_22 -> V_23 ;
* V_24 = V_22 -> V_24 ;
}
F_12 ( V_4 -> V_3 ,
L_3 ,
V_39 , __LINE__ , type , * V_24 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_4 , T_1 type ,
T_1 V_31 , void * V_23 )
{
struct V_47 V_48 ;
struct V_49 V_50 = {
. V_51 = V_52 ,
. V_53 = V_54 ,
} ;
F_12 ( V_4 -> V_3 ,
L_4 ,
type , V_31 ) ;
V_48 . type = F_21 ( type ) ;
V_48 . V_31 = F_21 ( V_31 ) ;
V_50 . V_23 [ 0 ] = & V_48 ;
V_50 . V_55 [ 0 ] = sizeof( struct V_47 ) ;
V_50 . V_23 [ 1 ] = V_23 ;
V_50 . V_55 [ 1 ] = V_31 ;
V_50 . V_56 [ 1 ] = V_57 ;
return F_22 ( V_4 -> V_3 , & V_50 ) ;
}
static int F_23 (
struct V_1 * V_4 ,
enum V_7 type ,
T_3 V_58 )
{
T_1 V_25 ;
int V_59 ;
struct V_6 * V_22 ;
for ( V_25 = 0 ; V_25 < V_58 ; V_25 ++ ) {
V_22 = F_3 ( V_4 ,
type ,
V_25 ) ;
if ( ! V_22 )
return - V_32 ;
V_59 = F_20 ( V_4 ,
type ,
V_22 -> V_24 ,
V_22 -> V_23 ) ;
if ( V_59 ) {
F_19 ( V_4 -> V_3 ,
L_5 ,
type , V_25 , V_59 ) ;
return V_59 ;
}
F_12 ( V_4 -> V_3 ,
L_6 ,
type , V_25 ) ;
}
return 0 ;
}
int F_24 ( struct V_1 * V_4 )
{
T_3 * V_23 = NULL ;
T_1 V_24 = 0 ;
int V_59 ;
F_12 ( V_4 -> V_3 ,
L_7 ) ;
V_59 = F_18 ( V_4 , V_10 ,
& V_23 , & V_24 , 0 ) ;
if ( V_59 ) {
F_19 ( V_4 -> V_3 , L_8 ) ;
return V_59 ;
}
V_59 = F_20 ( V_4 , V_10 , V_24 , V_23 ) ;
if ( V_59 ) {
F_19 ( V_4 -> V_3 ,
L_9 ) ;
return V_59 ;
}
V_59 = F_18 ( V_4 , V_12 ,
& V_23 , & V_24 , 0 ) ;
if ( V_59 ) {
F_19 ( V_4 -> V_3 ,
L_10 ) ;
return V_59 ;
}
V_59 = F_20 ( V_4 , V_12 , V_24 , V_23 ) ;
if ( V_59 ) {
F_19 ( V_4 -> V_3 ,
L_11 ) ;
return V_59 ;
}
V_59 = F_23 ( V_4 ,
V_16 ,
V_17 ) ;
if ( V_59 ) {
F_19 ( V_4 -> V_3 ,
L_12 ) ;
return V_59 ;
}
V_59 = F_23 ( V_4 ,
V_19 ,
V_20 ) ;
if ( V_59 ) {
F_19 ( V_4 -> V_3 ,
L_13 ) ;
return V_59 ;
}
F_12 ( V_4 -> V_3 ,
L_14 ) ;
return 0 ;
}
