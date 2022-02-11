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
V_13 , & V_6 ) ;
if ( F_4 ( V_9 ) ) {
F_5 ( V_9 ) ;
}
V_8 = V_6 -> string . V_8 + 1 ;
V_22 =
F_6 ( sizeof( struct V_3 ) +
( V_17 ) V_8 ) ;
if ( ! V_22 ) {
V_9 = V_18 ;
goto V_19;
}
V_22 -> string =
F_7 ( char , V_22 , sizeof( struct V_3 ) ) ;
strcpy ( V_22 -> string , V_6 -> string . V_21 ) ;
V_22 -> V_8 = V_8 ;
* V_4 = V_22 ;
V_19:
F_9 ( V_6 ) ;
F_5 ( V_9 ) ;
}
T_1
F_11 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
union V_5 * V_6 ;
struct V_3 * V_25 ;
T_2 V_8 ;
T_1 V_9 ;
F_2 ( V_26 ) ;
V_9 = F_3 ( V_2 , V_27 ,
V_12 | V_13 ,
& V_6 ) ;
if ( F_4 ( V_9 ) ) {
F_5 ( V_9 ) ;
}
if ( V_6 -> V_14 . type == V_15 ) {
V_8 = V_28 + 1 ;
} else {
V_8 = V_6 -> string . V_8 + 1 ;
}
V_25 =
F_6 ( sizeof( struct V_3 ) +
( V_17 ) V_8 ) ;
if ( ! V_25 ) {
V_9 = V_18 ;
goto V_19;
}
V_25 -> string =
F_7 ( char , V_25 , sizeof( struct V_3 ) ) ;
if ( V_6 -> V_14 . type == V_15 ) {
F_12 ( V_25 -> string , V_6 -> integer . V_20 ) ;
} else {
strcpy ( V_25 -> string , V_6 -> string . V_21 ) ;
}
V_25 -> V_8 = V_8 ;
* V_4 = V_25 ;
V_19:
F_9 ( V_6 ) ;
F_5 ( V_9 ) ;
}
T_1
F_13 ( struct V_1 * V_2 ,
struct V_29 * * V_30 )
{
union V_5 * * V_31 ;
union V_5 * V_6 ;
struct V_29 * V_32 ;
char * V_33 ;
T_2 V_34 ;
T_2 V_8 ;
T_2 V_35 ;
T_1 V_9 ;
T_2 V_36 ;
T_2 V_37 ;
F_2 ( V_38 ) ;
V_9 = F_3 ( V_2 , V_39 ,
V_12 | V_13
| V_40 , & V_6 ) ;
if ( F_4 ( V_9 ) ) {
F_5 ( V_9 ) ;
}
if ( V_6 -> V_14 . type == V_41 ) {
V_36 = V_6 -> V_42 . V_36 ;
V_31 = V_6 -> V_42 . V_43 ;
} else {
V_36 = 1 ;
V_31 = & V_6 ;
}
V_34 = 0 ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
switch ( V_31 [ V_37 ] -> V_14 . type ) {
case V_15 :
V_34 += V_16 ;
break;
case V_44 :
V_34 += V_31 [ V_37 ] -> string . V_8 + 1 ;
break;
default:
V_9 = V_45 ;
goto V_19;
}
}
V_35 = sizeof( struct V_29 ) +
( ( V_36 - 1 ) * sizeof( struct V_3 ) ) +
V_34 ;
V_32 = F_6 ( V_35 ) ;
if ( ! V_32 ) {
V_9 = V_18 ;
goto V_19;
}
V_33 = F_14 ( char , V_32 -> V_46 ) +
( ( V_17 ) V_36 * sizeof( struct V_3 ) ) ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
if ( V_31 [ V_37 ] -> V_14 . type == V_15 ) {
F_8 ( V_33 ,
V_31 [ V_37 ] -> integer .
V_20 ) ;
V_8 = V_16 ;
} else {
strcpy ( V_33 , V_31 [ V_37 ] -> string . V_21 ) ;
V_8 = V_31 [ V_37 ] -> string . V_8 + 1 ;
}
V_32 -> V_46 [ V_37 ] . string = V_33 ;
V_32 -> V_46 [ V_37 ] . V_8 = V_8 ;
V_33 += V_8 ;
}
V_32 -> V_36 = V_36 ;
V_32 -> V_47 = V_35 ;
* V_30 = V_32 ;
V_19:
F_9 ( V_6 ) ;
F_5 ( V_9 ) ;
}
T_1
F_15 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
union V_5 * V_6 ;
union V_5 * * V_48 ;
T_2 V_36 ;
struct V_3 * V_49 ;
T_2 V_8 ;
T_1 V_9 ;
T_3 V_50 [ 3 ] = { 0 , 0 , 0 } ;
F_2 ( V_51 ) ;
V_9 = F_3 ( V_2 , V_52 ,
V_40 , & V_6 ) ;
if ( F_4 ( V_9 ) ) {
F_5 ( V_9 ) ;
}
V_8 = V_53 ;
V_48 = V_6 -> V_42 . V_43 ;
V_36 = V_6 -> V_42 . V_36 ;
if ( V_6 -> V_14 . type == V_41 ) {
if ( V_36 > 0
&& V_48 [ 0 ] -> V_14 . type == V_15 ) {
V_50 [ 0 ] = ( T_3 ) V_48 [ 0 ] -> integer . V_20 ;
}
if ( V_36 > 1
&& V_48 [ 1 ] -> V_14 . type == V_15 ) {
V_50 [ 1 ] = ( T_3 ) V_48 [ 1 ] -> integer . V_20 ;
}
if ( V_36 > 2
&& V_48 [ 2 ] -> V_14 . type == V_15 ) {
V_50 [ 2 ] = ( T_3 ) V_48 [ 2 ] -> integer . V_20 ;
}
}
V_49 =
F_6 ( sizeof( struct V_3 ) +
( V_17 ) V_8 ) ;
if ( ! V_49 ) {
V_9 = V_18 ;
goto V_19;
}
V_49 -> string =
F_7 ( char , V_49 , sizeof( struct V_3 ) ) ;
F_16 ( V_49 -> string , V_50 ) ;
V_49 -> V_8 = V_8 ;
* V_4 = V_49 ;
V_19:
F_9 ( V_6 ) ;
F_5 ( V_9 ) ;
}
