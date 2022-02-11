static T_1
F_1 ( T_2 V_1 ,
struct V_2 * V_3 ,
struct V_4 * * V_5 )
{
T_1 V_6 ;
struct V_4 * V_7 ;
F_2 ( V_8 ) ;
if ( ! V_1 ) {
F_3 ( V_9 ) ;
}
V_7 = F_4 ( V_1 ) ;
if ( ! V_7 ) {
F_3 ( V_9 ) ;
}
if ( V_7 -> type != V_10 ) {
F_3 ( V_11 ) ;
}
V_6 = F_5 ( V_3 ) ;
if ( F_6 ( V_6 ) ) {
F_3 ( V_6 ) ;
}
* V_5 = V_7 ;
F_3 ( V_12 ) ;
}
T_1
F_7 ( T_2 V_1 ,
struct V_2 * V_13 )
{
T_1 V_6 ;
struct V_4 * V_7 ;
F_2 ( F_7 ) ;
V_6 = F_1 ( V_1 , V_13 , & V_7 ) ;
if ( F_6 ( V_6 ) ) {
F_3 ( V_6 ) ;
}
V_6 = F_8 ( V_7 , V_13 ) ;
F_3 ( V_6 ) ;
}
T_1
F_9 ( T_2 V_1 ,
struct V_2 * V_13 )
{
T_1 V_6 ;
struct V_4 * V_7 ;
F_2 ( F_9 ) ;
V_6 = F_1 ( V_1 , V_13 , & V_7 ) ;
if ( F_6 ( V_6 ) ) {
F_3 ( V_6 ) ;
}
V_6 = F_10 ( V_7 , V_13 ) ;
F_3 ( V_6 ) ;
}
T_1
F_11 ( T_2 V_1 ,
struct V_2 * V_13 )
{
T_1 V_6 ;
struct V_4 * V_7 ;
F_2 ( F_11 ) ;
V_6 = F_1 ( V_1 , V_13 , & V_7 ) ;
if ( F_6 ( V_6 ) ) {
F_3 ( V_6 ) ;
}
V_6 = F_12 ( V_7 , V_13 ) ;
F_3 ( V_6 ) ;
}
T_1
F_13 ( T_2 V_1 ,
struct V_2 * V_14 )
{
T_1 V_6 ;
struct V_4 * V_7 ;
F_2 ( F_13 ) ;
if ( ( ! V_14 ) || ( ! V_14 -> V_15 ) || ( ! V_14 -> V_16 ) ) {
F_3 ( V_9 ) ;
}
V_6 = F_1 ( V_1 , V_14 , & V_7 ) ;
if ( F_6 ( V_6 ) ) {
F_3 ( V_6 ) ;
}
V_6 = F_14 ( V_7 , V_14 ) ;
F_3 ( V_6 ) ;
}
T_1
F_15 ( T_2 V_1 ,
struct V_2 * V_13 )
{
T_1 V_6 ;
struct V_4 * V_7 ;
F_2 ( F_15 ) ;
V_6 = F_1 ( V_1 , V_13 , & V_7 ) ;
if ( F_6 ( V_6 ) ) {
F_3 ( V_6 ) ;
}
V_6 = F_16 ( V_7 , V_13 ) ;
F_3 ( V_6 ) ;
}
T_1
F_17 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
if ( ! V_18 || ! V_20 ) {
return ( V_9 ) ;
}
switch ( V_18 -> type ) {
case V_25 :
V_22 =
F_18 ( struct V_21 ,
& V_18 -> V_26 ) ;
F_19 ( V_20 , V_22 ) ;
break;
case V_27 :
V_24 =
F_18 ( struct V_23 ,
& V_18 -> V_26 ) ;
F_19 ( V_20 , V_24 ) ;
break;
case V_28 :
F_20 ( V_20 , & V_18 -> V_26 ,
sizeof( struct V_19 ) ) ;
break;
default:
return ( V_9 ) ;
}
return ( V_12 ) ;
}
T_1
F_21 ( T_2 V_1 ,
char * V_29 ,
struct V_30 * V_31 ,
struct V_2 * V_13 )
{
struct V_32 V_33 ;
T_1 V_6 ;
if ( ! V_31 || ! V_13 ) {
return ( V_9 ) ;
}
V_33 . V_31 = V_31 ;
V_33 . V_3 = V_13 ;
V_33 . V_6 = V_34 ;
V_6 =
F_22 ( V_1 , V_29 ,
V_35 , & V_33 ) ;
if ( F_6 ( V_6 ) ) {
return ( V_6 ) ;
}
return ( V_33 . V_6 ) ;
}
static T_1
V_35 ( struct V_17 * V_18 , void * V_36 )
{
struct V_32 * V_33 = V_36 ;
struct V_37 * V_38 ;
struct V_2 * V_3 ;
T_1 V_6 ;
if ( V_18 -> type != V_39 ) {
return ( V_12 ) ;
}
V_38 = & V_18 -> V_26 . V_40 ;
if ( ( V_38 -> V_41 < ( V_42 + 1 ) ) ||
( V_38 -> V_43 != V_33 -> V_31 -> V_44 ) ||
( F_23 ( V_38 -> V_31 , V_33 -> V_31 -> V_26 , V_42 ) ) ) {
return ( V_12 ) ;
}
V_3 = V_33 -> V_3 ;
V_6 = F_24 ( V_3 , V_18 -> V_16 ) ;
if ( F_6 ( V_6 ) ) {
return ( V_6 ) ;
}
F_20 ( V_3 -> V_15 , V_18 , V_18 -> V_16 ) ;
V_3 -> V_16 = V_18 -> V_16 ;
V_33 -> V_6 = V_12 ;
return ( V_45 ) ;
}
T_1
F_25 ( struct V_2 * V_3 ,
T_3 V_46 ,
void * V_36 )
{
T_1 V_6 = V_12 ;
struct V_17 * V_18 ;
struct V_17 * V_47 ;
F_2 ( F_25 ) ;
if ( ! V_3 || ! V_3 -> V_15 || ! V_46 ) {
F_3 ( V_9 ) ;
}
V_18 = F_18 ( struct V_17 , V_3 -> V_15 ) ;
V_47 =
F_26 ( struct V_17 , V_3 -> V_15 , V_3 -> V_16 ) ;
while ( V_18 < V_47 ) {
if ( V_18 -> type > V_48 ) {
V_6 = V_49 ;
break;
}
V_6 = V_46 ( V_18 , V_36 ) ;
if ( F_6 ( V_6 ) ) {
if ( V_6 == V_45 ) {
V_6 = V_12 ;
}
break;
}
if ( V_18 -> type == V_50 ) {
break;
}
V_18 = F_27 ( V_18 ) ;
}
F_3 ( V_6 ) ;
}
T_1
F_22 ( T_2 V_1 ,
char * V_29 ,
T_3 V_46 , void * V_36 )
{
T_1 V_6 ;
struct V_2 V_3 ;
F_2 ( F_22 ) ;
if ( ! V_1 || ! V_46 || ! V_29 ||
( ! F_28 ( V_29 , V_51 ) &&
! F_28 ( V_29 , V_52 ) &&
! F_28 ( V_29 , V_53 ) ) ) {
F_3 ( V_9 ) ;
}
V_3 . V_16 = V_54 ;
V_6 = F_29 ( V_1 , V_29 , & V_3 ) ;
if ( F_6 ( V_6 ) ) {
F_3 ( V_6 ) ;
}
V_6 = F_25 ( & V_3 , V_46 , V_36 ) ;
F_30 ( V_3 . V_15 ) ;
F_3 ( V_6 ) ;
}
