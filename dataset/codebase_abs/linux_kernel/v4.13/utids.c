T_1
F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
union V_5 * V_6 ;
struct V_3 * V_7 ;
T_2 V_8 ;
T_1 V_9 ;
F_2 ( V_10 ) ;
V_9 = F_3 ( V_2 , V_11 ,
V_12 | V_13 ,
& V_6 ) ;
if ( F_4 ( V_9 ) ) {
F_5 ( V_9 ) ;
}
if ( V_6 -> V_14 . type == V_15 ) {
V_8 = V_16 ;
} else {
V_8 = V_6 -> string . V_8 + 1 ;
}
V_7 =
F_6 ( sizeof( struct V_3 ) +
( V_17 ) V_8 ) ;
if ( ! V_7 ) {
V_9 = V_18 ;
goto V_19;
}
V_7 -> string =
F_7 ( char , V_7 , sizeof( struct V_3 ) ) ;
if ( V_6 -> V_14 . type == V_15 ) {
F_8 ( V_7 -> string , V_6 -> integer . V_20 ) ;
} else {
strcpy ( V_7 -> string , V_6 -> string . V_21 ) ;
}
V_7 -> V_8 = V_8 ;
* V_4 = V_7 ;
V_19:
F_9 ( V_6 ) ;
F_5 ( V_9 ) ;
}
T_1
F_10 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
union V_5 * V_6 ;
struct V_3 * V_22 ;
T_2 V_8 ;
T_1 V_9 ;
F_2 ( V_23 ) ;
V_9 = F_3 ( V_2 , V_24 ,
V_12 | V_13 ,
& V_6 ) ;
if ( F_4 ( V_9 ) ) {
F_5 ( V_9 ) ;
}
if ( V_6 -> V_14 . type == V_15 ) {
V_8 = V_25 + 1 ;
} else {
V_8 = V_6 -> string . V_8 + 1 ;
}
V_22 =
F_6 ( sizeof( struct V_3 ) +
( V_17 ) V_8 ) ;
if ( ! V_22 ) {
V_9 = V_18 ;
goto V_19;
}
V_22 -> string =
F_7 ( char , V_22 , sizeof( struct V_3 ) ) ;
if ( V_6 -> V_14 . type == V_15 ) {
F_11 ( V_22 -> string , V_6 -> integer . V_20 ) ;
} else {
strcpy ( V_22 -> string , V_6 -> string . V_21 ) ;
}
V_22 -> V_8 = V_8 ;
* V_4 = V_22 ;
V_19:
F_9 ( V_6 ) ;
F_5 ( V_9 ) ;
}
T_1
F_12 ( struct V_1 * V_2 ,
struct V_26 * * V_27 )
{
union V_5 * * V_28 ;
union V_5 * V_6 ;
struct V_26 * V_29 ;
char * V_30 ;
T_2 V_31 ;
T_2 V_8 ;
T_2 V_32 ;
T_1 V_9 ;
T_2 V_33 ;
T_2 V_34 ;
F_2 ( V_35 ) ;
V_9 = F_3 ( V_2 , V_36 ,
V_12 | V_13
| V_37 , & V_6 ) ;
if ( F_4 ( V_9 ) ) {
F_5 ( V_9 ) ;
}
if ( V_6 -> V_14 . type == V_38 ) {
V_33 = V_6 -> V_39 . V_33 ;
V_28 = V_6 -> V_39 . V_40 ;
} else {
V_33 = 1 ;
V_28 = & V_6 ;
}
V_31 = 0 ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ ) {
switch ( V_28 [ V_34 ] -> V_14 . type ) {
case V_15 :
V_31 += V_16 ;
break;
case V_41 :
V_31 += V_28 [ V_34 ] -> string . V_8 + 1 ;
break;
default:
V_9 = V_42 ;
goto V_19;
}
}
V_32 = sizeof( struct V_26 ) +
( ( V_33 - 1 ) * sizeof( struct V_3 ) ) +
V_31 ;
V_29 = F_6 ( V_32 ) ;
if ( ! V_29 ) {
V_9 = V_18 ;
goto V_19;
}
V_30 = F_13 ( char , V_29 -> V_43 ) +
( ( V_17 ) V_33 * sizeof( struct V_3 ) ) ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ ) {
if ( V_28 [ V_34 ] -> V_14 . type == V_15 ) {
F_8 ( V_30 ,
V_28 [ V_34 ] -> integer .
V_20 ) ;
V_8 = V_16 ;
} else {
strcpy ( V_30 , V_28 [ V_34 ] -> string . V_21 ) ;
V_8 = V_28 [ V_34 ] -> string . V_8 + 1 ;
}
V_29 -> V_43 [ V_34 ] . string = V_30 ;
V_29 -> V_43 [ V_34 ] . V_8 = V_8 ;
V_30 += V_8 ;
}
V_29 -> V_33 = V_33 ;
V_29 -> V_44 = V_32 ;
* V_27 = V_29 ;
V_19:
F_9 ( V_6 ) ;
F_5 ( V_9 ) ;
}
T_1
F_14 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
union V_5 * V_6 ;
union V_5 * * V_45 ;
T_2 V_33 ;
struct V_3 * V_46 ;
T_2 V_8 ;
T_1 V_9 ;
T_3 V_47 [ 3 ] = { 0 , 0 , 0 } ;
F_2 ( V_48 ) ;
V_9 = F_3 ( V_2 , V_49 ,
V_37 , & V_6 ) ;
if ( F_4 ( V_9 ) ) {
F_5 ( V_9 ) ;
}
V_8 = V_50 ;
V_45 = V_6 -> V_39 . V_40 ;
V_33 = V_6 -> V_39 . V_33 ;
if ( V_6 -> V_14 . type == V_38 ) {
if ( V_33 > 0
&& V_45 [ 0 ] -> V_14 . type == V_15 ) {
V_47 [ 0 ] = ( T_3 ) V_45 [ 0 ] -> integer . V_20 ;
}
if ( V_33 > 1
&& V_45 [ 1 ] -> V_14 . type == V_15 ) {
V_47 [ 1 ] = ( T_3 ) V_45 [ 1 ] -> integer . V_20 ;
}
if ( V_33 > 2
&& V_45 [ 2 ] -> V_14 . type == V_15 ) {
V_47 [ 2 ] = ( T_3 ) V_45 [ 2 ] -> integer . V_20 ;
}
}
V_46 =
F_6 ( sizeof( struct V_3 ) +
( V_17 ) V_8 ) ;
if ( ! V_46 ) {
V_9 = V_18 ;
goto V_19;
}
V_46 -> string =
F_7 ( char , V_46 , sizeof( struct V_3 ) ) ;
F_15 ( V_46 -> string , V_47 ) ;
V_46 -> V_8 = V_8 ;
* V_4 = V_46 ;
V_19:
F_9 ( V_6 ) ;
F_5 ( V_9 ) ;
}
