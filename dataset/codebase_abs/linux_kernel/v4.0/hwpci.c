T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 , T_2 V_4 )
{
T_1 V_5 ;
struct V_6 * V_7 = NULL ;
F_2 ( V_8 ) ;
if ( ! V_2 ) {
F_3 ( V_9 ) ;
}
V_5 =
F_4 ( V_3 , V_4 , & V_7 ) ;
if ( F_5 ( V_5 ) ) {
V_5 = F_6 ( V_2 , V_7 ) ;
F_7 ( V_7 ) ;
}
F_3 ( V_5 ) ;
}
static T_1
F_4 ( T_2 V_3 ,
T_2 V_4 ,
struct V_6 * * V_10 )
{
T_2 V_11 ;
T_2 V_12 ;
T_1 V_5 ;
struct V_6 * V_13 ;
struct V_6 * V_7 = NULL ;
V_11 = V_4 ;
while ( 1 ) {
V_5 = F_8 ( V_11 , & V_12 ) ;
if ( F_9 ( V_5 ) ) {
F_7 ( * V_10 ) ;
return ( V_5 ) ;
}
if ( V_12 == V_3 ) {
* V_10 = V_7 ;
return ( V_14 ) ;
}
V_13 = F_10 ( sizeof( struct V_6 ) ) ;
if ( ! V_13 ) {
F_7 ( * V_10 ) ;
return ( V_15 ) ;
}
V_13 -> V_16 = V_7 ;
V_13 -> V_17 = V_12 ;
V_7 = V_13 ;
V_11 = V_12 ;
}
}
static T_1
F_6 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_1 V_5 = V_14 ;
struct V_6 * V_18 ;
T_3 V_19 ;
T_4 V_20 = TRUE ;
F_11 ( V_21 ) ;
F_12 ( ( V_22 ,
L_1 ,
V_2 -> V_23 , V_2 -> V_24 , V_2 -> V_17 ,
V_2 -> V_25 ) ) ;
V_19 = V_2 -> V_24 ;
V_18 = V_7 ;
while ( V_18 ) {
V_5 = F_13 ( V_2 , V_18 -> V_17 ,
& V_19 , & V_20 ) ;
if ( F_9 ( V_5 ) ) {
return ( V_5 ) ;
}
V_18 = V_18 -> V_16 ;
}
F_12 ( ( V_22 ,
L_2
L_3 ,
V_2 -> V_23 , V_2 -> V_24 , V_2 -> V_17 ,
V_2 -> V_25 , V_5 , V_19 , V_20 ) ) ;
return ( V_14 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
struct V_6 * V_16 ;
struct V_6 * V_26 ;
V_16 = V_7 ;
while ( V_16 ) {
V_26 = V_16 ;
V_16 = V_26 -> V_16 ;
F_14 ( V_26 ) ;
}
}
static T_1
F_13 ( struct V_1 * V_2 ,
T_2 V_27 ,
T_3 * V_19 , T_4 * V_20 )
{
T_1 V_5 ;
T_5 V_28 ;
T_6 V_29 ;
T_6 V_30 ;
V_5 = F_15 ( V_27 , & V_28 ) ;
if ( F_9 ( V_5 ) ) {
return ( V_5 ) ;
}
if ( V_28 != V_31 ) {
return ( V_14 ) ;
}
V_5 = F_16 ( V_32 ,
V_27 , & V_29 ) ;
if ( F_9 ( V_5 ) ) {
return ( V_14 ) ;
}
V_2 -> V_17 = F_17 ( F_18 ( V_29 ) ) ;
V_2 -> V_25 = F_19 ( F_18 ( V_29 ) ) ;
if ( * V_20 ) {
V_2 -> V_24 = * V_19 ;
}
* V_20 = FALSE ;
V_5 = F_20 ( V_2 ,
V_33 ,
& V_30 , 8 ) ;
if ( F_9 ( V_5 ) ) {
return ( V_5 ) ;
}
V_30 &= V_34 ;
if ( ( V_30 != V_35 ) &&
( V_30 != V_36 ) ) {
return ( V_14 ) ;
}
V_5 = F_20 ( V_2 ,
V_37 ,
& V_30 , 8 ) ;
if ( F_9 ( V_5 ) ) {
return ( V_5 ) ;
}
* V_20 = TRUE ;
V_2 -> V_24 = ( T_3 ) V_30 ;
V_5 = F_20 ( V_2 ,
V_38 ,
& V_30 , 8 ) ;
if ( F_9 ( V_5 ) ) {
return ( V_5 ) ;
}
* V_19 = ( T_3 ) V_30 ;
return ( V_14 ) ;
}
