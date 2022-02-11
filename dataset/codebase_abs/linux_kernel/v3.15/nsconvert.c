T_1
F_1 ( union V_1 * V_2 ,
union V_1 * * V_3 )
{
union V_1 * V_4 ;
T_1 V_5 ;
T_2 V_6 = 0 ;
T_3 V_7 ;
switch ( V_2 -> V_8 . type ) {
case V_9 :
V_5 = F_2 ( V_2 -> string . V_10 ,
V_11 , & V_6 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
break;
case V_12 :
if ( V_2 -> V_13 . V_14 > 8 ) {
return ( V_15 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 . V_14 ; V_7 ++ ) {
V_6 |=
( ( T_2 ) V_2 -> V_13 .
V_10 [ V_7 ] << ( V_7 * 8 ) ) ;
}
break;
default:
return ( V_15 ) ;
}
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 ) {
return ( V_16 ) ;
}
* V_3 = V_4 ;
return ( V_17 ) ;
}
T_1
F_5 ( union V_1 * V_2 ,
union V_1 * * V_3 )
{
union V_1 * V_4 ;
T_4 V_14 ;
T_1 V_5 ;
switch ( V_2 -> V_8 . type ) {
case V_18 :
if ( V_2 -> integer . V_6 == 0 ) {
V_4 = F_6 ( 0 ) ;
if ( ! V_4 ) {
return ( V_16 ) ;
}
} else {
V_5 =
F_7 ( V_2 ,
& V_4 ,
V_19 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
}
break;
case V_12 :
V_14 = 0 ;
while ( ( V_14 < V_2 -> V_13 . V_14 ) &&
( V_2 -> V_13 . V_10 [ V_14 ] ) ) {
V_14 ++ ;
}
V_4 = F_6 ( V_14 ) ;
if ( ! V_4 ) {
return ( V_16 ) ;
}
F_8 ( V_4 -> string . V_10 ,
V_2 -> V_13 . V_10 , V_14 ) ;
break;
default:
return ( V_15 ) ;
}
* V_3 = V_4 ;
return ( V_17 ) ;
}
T_1
F_9 ( union V_1 * V_2 ,
union V_1 * * V_3 )
{
union V_1 * V_4 ;
T_1 V_5 ;
union V_1 * * V_20 ;
T_3 * V_21 ;
T_3 V_22 ;
T_3 V_7 ;
switch ( V_2 -> V_8 . type ) {
case V_18 :
V_5 =
F_10 ( V_2 , & V_4 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
break;
case V_9 :
V_4 =
F_11 ( V_2 -> string .
V_14 ) ;
if ( ! V_4 ) {
return ( V_16 ) ;
}
F_8 ( V_4 -> V_13 . V_10 ,
V_2 -> string . V_10 ,
V_2 -> string . V_14 ) ;
break;
case V_23 :
V_20 = V_2 -> V_24 . V_20 ;
V_22 = V_2 -> V_24 . V_22 ;
for ( V_7 = 0 ; V_7 < V_22 ; V_7 ++ ) {
if ( ( ! * V_20 ) ||
( ( * V_20 ) -> V_8 . type != V_18 ) ) {
return ( V_15 ) ;
}
V_20 ++ ;
}
V_4 = F_11 ( F_12 ( V_22 ) ) ;
if ( ! V_4 ) {
return ( V_16 ) ;
}
V_20 = V_2 -> V_24 . V_20 ;
V_21 = F_13 ( T_3 , V_4 -> V_13 . V_10 ) ;
for ( V_7 = 0 ; V_7 < V_22 ; V_7 ++ ) {
* V_21 = ( T_3 ) ( * V_20 ) -> integer . V_6 ;
V_21 ++ ;
V_20 ++ ;
}
break;
default:
return ( V_15 ) ;
}
* V_3 = V_4 ;
return ( V_17 ) ;
}
T_1
F_14 ( union V_1 * V_2 ,
union V_1 * * V_3 )
{
union V_1 * V_4 ;
char * V_25 ;
T_5 * V_26 ;
T_3 V_27 ;
T_3 V_7 ;
if ( ! V_2 ) {
return ( V_17 ) ;
}
if ( V_2 -> V_8 . type == V_12 ) {
if ( V_2 -> V_13 . V_14 < 2 ) {
return ( V_28 ) ;
}
* V_3 = NULL ;
return ( V_17 ) ;
}
V_25 = V_2 -> string . V_10 ;
V_27 = ( V_2 -> string . V_14 * 2 ) + 2 ;
V_4 = F_11 ( V_27 ) ;
if ( ! V_4 ) {
return ( V_16 ) ;
}
V_26 = F_13 ( T_5 , V_4 -> V_13 . V_10 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> string . V_14 ; V_7 ++ ) {
V_26 [ V_7 ] = ( T_5 ) V_25 [ V_7 ] ;
}
* V_3 = V_4 ;
return ( V_17 ) ;
}
T_1
F_15 ( union V_1 * V_2 ,
union V_1 * * V_3 )
{
union V_1 * V_4 ;
T_6 * V_13 ;
if ( V_2 ) {
switch ( V_2 -> V_8 . type ) {
case V_18 :
if ( V_2 -> integer . V_6 ) {
return ( V_15 ) ;
}
break;
case V_12 :
if ( V_2 -> V_13 . V_14 ) {
* V_3 = NULL ;
return ( V_17 ) ;
}
break;
case V_9 :
default:
return ( V_15 ) ;
}
}
V_4 = F_11 ( 2 ) ;
if ( ! V_4 ) {
return ( V_16 ) ;
}
V_13 = F_13 ( T_6 , V_4 -> V_13 . V_10 ) ;
V_13 [ 0 ] = ( V_29 | V_30 ) ;
V_13 [ 1 ] = 0x00 ;
* V_3 = V_4 ;
return ( V_17 ) ;
}
