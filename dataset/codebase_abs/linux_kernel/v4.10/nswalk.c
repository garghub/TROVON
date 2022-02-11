struct V_1 * F_1 ( struct V_1
* V_2 ,
struct V_1
* V_3 )
{
F_2 () ;
if ( ! V_3 ) {
return ( V_2 -> V_4 ) ;
}
return ( V_3 -> V_5 ) ;
}
struct V_1 * F_3 ( T_1 type ,
struct
V_1
* V_2 ,
struct
V_1
* V_3 )
{
struct V_1 * V_6 = NULL ;
F_2 () ;
V_6 = F_1 ( V_2 , V_3 ) ;
if ( type == V_7 ) {
return ( V_6 ) ;
}
while ( V_6 ) {
if ( V_6 -> type == type ) {
return ( V_6 ) ;
}
V_6 = V_6 -> V_5 ;
}
return ( NULL ) ;
}
T_2
F_4 ( T_1 type ,
T_3 V_8 ,
T_4 V_9 ,
T_4 V_10 ,
T_5 V_11 ,
T_5 V_12 ,
void * V_13 , void * * V_14 )
{
T_2 V_15 ;
T_2 V_16 ;
struct V_1 * V_3 ;
struct V_1 * V_2 ;
T_1 V_17 ;
T_4 V_18 ;
T_6 V_19 = FALSE ;
F_5 ( V_20 ) ;
if ( V_8 == V_21 ) {
V_8 = V_22 ;
}
V_2 = V_8 ;
V_3 = F_1 ( V_2 , NULL ) ;
V_17 = V_7 ;
V_18 = 1 ;
while ( V_18 > 0 && V_3 ) {
V_15 = V_23 ;
if ( type != V_7 ) {
V_17 = V_3 -> type ;
}
if ( ( V_3 -> V_10 & V_24 ) &&
! ( V_10 & V_25 ) ) {
V_15 = V_26 ;
}
else if ( V_17 == type ) {
if ( V_10 & V_27 ) {
V_16 =
F_6 ( V_28 ) ;
if ( F_7 ( V_16 ) ) {
F_8 ( V_16 ) ;
}
}
if ( ! V_19 ) {
if ( V_11 ) {
V_15 =
V_11 ( V_3 ,
V_18 , V_13 ,
V_14 ) ;
}
} else {
if ( V_12 ) {
V_15 =
V_12 ( V_3 ,
V_18 , V_13 ,
V_14 ) ;
}
}
if ( V_10 & V_27 ) {
V_16 =
F_9 ( V_28 ) ;
if ( F_7 ( V_16 ) ) {
F_8 ( V_16 ) ;
}
}
switch ( V_15 ) {
case V_23 :
case V_26 :
break;
case V_29 :
F_8 ( V_23 ) ;
default:
F_8 ( V_15 ) ;
}
}
if ( ! V_19 &&
( V_18 < V_9 ) && ( V_15 != V_26 ) ) {
if ( V_3 -> V_4 ) {
V_18 ++ ;
V_2 = V_3 ;
V_3 =
F_1 ( V_2 , NULL ) ;
continue;
}
}
if ( ! V_19 ) {
V_19 = TRUE ;
continue;
}
V_3 = F_1 ( V_2 , V_3 ) ;
if ( V_3 ) {
V_19 = FALSE ;
}
else {
V_18 -- ;
V_3 = V_2 ;
V_2 = V_2 -> V_30 ;
V_19 = TRUE ;
}
}
F_8 ( V_23 ) ;
}
