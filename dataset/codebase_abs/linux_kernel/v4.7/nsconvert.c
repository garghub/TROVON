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
V_11 ,
V_12 , & V_6 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
break;
case V_13 :
if ( V_2 -> V_14 . V_15 > 8 ) {
return ( V_16 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_14 . V_15 ; V_7 ++ ) {
V_6 |= ( ( T_2 )
V_2 -> V_14 . V_10 [ V_7 ] << ( V_7 *
8 ) ) ;
}
break;
default:
return ( V_16 ) ;
}
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 ) {
return ( V_17 ) ;
}
* V_3 = V_4 ;
return ( V_18 ) ;
}
T_1
F_5 ( union V_1 * V_2 ,
union V_1 * * V_3 )
{
union V_1 * V_4 ;
T_4 V_15 ;
T_1 V_5 ;
switch ( V_2 -> V_8 . type ) {
case V_19 :
if ( V_2 -> integer . V_6 == 0 ) {
V_4 = F_6 ( 0 ) ;
if ( ! V_4 ) {
return ( V_17 ) ;
}
} else {
V_5 = F_7 ( V_2 ,
& V_4 ,
V_20 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
}
break;
case V_13 :
V_15 = 0 ;
while ( ( V_15 < V_2 -> V_14 . V_15 ) &&
( V_2 -> V_14 . V_10 [ V_15 ] ) ) {
V_15 ++ ;
}
V_4 = F_6 ( V_15 ) ;
if ( ! V_4 ) {
return ( V_17 ) ;
}
memcpy ( V_4 -> string . V_10 ,
V_2 -> V_14 . V_10 , V_15 ) ;
break;
default:
return ( V_16 ) ;
}
* V_3 = V_4 ;
return ( V_18 ) ;
}
T_1
F_8 ( union V_1 * V_2 ,
union V_1 * * V_3 )
{
union V_1 * V_4 ;
T_1 V_5 ;
union V_1 * * V_21 ;
T_3 * V_22 ;
T_3 V_23 ;
T_3 V_7 ;
switch ( V_2 -> V_8 . type ) {
case V_19 :
V_5 =
F_9 ( V_2 , & V_4 ) ;
if ( F_3 ( V_5 ) ) {
return ( V_5 ) ;
}
break;
case V_9 :
V_4 = F_10
( V_2 -> string . V_15 ) ;
if ( ! V_4 ) {
return ( V_17 ) ;
}
memcpy ( V_4 -> V_14 . V_10 ,
V_2 -> string . V_10 ,
V_2 -> string . V_15 ) ;
break;
case V_24 :
V_21 = V_2 -> V_25 . V_21 ;
V_23 = V_2 -> V_25 . V_23 ;
for ( V_7 = 0 ; V_7 < V_23 ; V_7 ++ ) {
if ( ( ! * V_21 ) ||
( ( * V_21 ) -> V_8 . type != V_19 ) ) {
return ( V_16 ) ;
}
V_21 ++ ;
}
V_4 = F_10 ( F_11 ( V_23 ) ) ;
if ( ! V_4 ) {
return ( V_17 ) ;
}
V_21 = V_2 -> V_25 . V_21 ;
V_22 = F_12 ( T_3 , V_4 -> V_14 . V_10 ) ;
for ( V_7 = 0 ; V_7 < V_23 ; V_7 ++ ) {
* V_22 = ( T_3 ) ( * V_21 ) -> integer . V_6 ;
V_22 ++ ;
V_21 ++ ;
}
break;
default:
return ( V_16 ) ;
}
* V_3 = V_4 ;
return ( V_18 ) ;
}
T_1
F_13 ( struct V_26 * V_27 ,
union V_1 * V_2 ,
union V_1 * * V_3 )
{
union V_1 * V_4 ;
char * V_28 ;
T_5 * V_29 ;
T_3 V_30 ;
T_3 V_7 ;
if ( ! V_2 ) {
return ( V_18 ) ;
}
if ( V_2 -> V_8 . type == V_13 ) {
if ( V_2 -> V_14 . V_15 < 2 ) {
return ( V_31 ) ;
}
* V_3 = NULL ;
return ( V_18 ) ;
}
V_28 = V_2 -> string . V_10 ;
V_30 = ( V_2 -> string . V_15 * 2 ) + 2 ;
V_4 = F_10 ( V_30 ) ;
if ( ! V_4 ) {
return ( V_17 ) ;
}
V_29 = F_12 ( T_5 , V_4 -> V_14 . V_10 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> string . V_15 ; V_7 ++ ) {
V_29 [ V_7 ] = ( T_5 ) V_28 [ V_7 ] ;
}
* V_3 = V_4 ;
return ( V_18 ) ;
}
T_1
F_14 ( struct V_26 * V_27 ,
union V_1 * V_2 ,
union V_1 * * V_3 )
{
union V_1 * V_4 ;
T_6 * V_14 ;
if ( V_2 ) {
switch ( V_2 -> V_8 . type ) {
case V_19 :
if ( V_2 -> integer . V_6 ) {
return ( V_16 ) ;
}
break;
case V_13 :
if ( V_2 -> V_14 . V_15 ) {
* V_3 = NULL ;
return ( V_18 ) ;
}
break;
case V_9 :
default:
return ( V_16 ) ;
}
}
V_4 = F_10 ( 2 ) ;
if ( ! V_4 ) {
return ( V_17 ) ;
}
V_14 = F_12 ( T_6 , V_4 -> V_14 . V_10 ) ;
V_14 [ 0 ] = ( V_32 | V_33 ) ;
V_14 [ 1 ] = 0x00 ;
* V_3 = V_4 ;
return ( V_18 ) ;
}
T_1
F_15 ( struct V_26 * V_27 ,
union V_1 * V_2 ,
union V_1 * * V_3 )
{
union V_1 * V_4 = NULL ;
T_1 V_5 ;
struct V_26 * V_34 ;
union V_35 V_36 ;
char * V_37 ;
F_16 ( V_38 ) ;
V_5 =
F_17 ( V_2 -> string . V_10 , & V_37 ) ;
if ( F_3 ( V_5 ) ) {
F_18 ( V_5 ) ;
}
V_36 . V_27 . V_34 =
F_12 ( struct V_26 , V_27 ) ;
V_5 =
F_19 ( & V_36 , V_37 , V_39 , V_40 ,
V_41 | V_42 ,
NULL , & V_34 ) ;
if ( F_3 ( V_5 ) ) {
F_20 ( V_2 -> string . V_10 , V_5 ) ;
goto V_43;
}
V_4 = F_21 ( V_44 ) ;
if ( ! V_4 ) {
V_5 = V_17 ;
goto V_43;
}
V_4 -> V_45 . V_34 = V_34 ;
V_4 -> V_45 . V_46 = V_34 -> V_46 ;
V_4 -> V_45 . V_47 = V_48 ;
F_22 ( V_34 -> V_46 ) ;
V_43:
F_23 ( V_37 ) ;
* V_3 = V_4 ;
return ( V_18 ) ;
}
