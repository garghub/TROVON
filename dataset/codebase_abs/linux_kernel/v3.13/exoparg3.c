T_1 F_1 ( struct V_1 * V_2 )
{
union V_3 * * V_4 = & V_2 -> V_5 [ 0 ] ;
struct V_6 * V_7 ;
T_1 V_8 = V_9 ;
F_2 ( V_10 ,
F_3 ( V_2 -> V_11 ) ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
F_4 ( ( V_13 ,
L_1 ,
( V_14 ) V_4 [ 0 ] -> integer . V_15 ,
( V_14 ) V_4 [ 1 ] -> integer . V_15 ,
( V_14 ) V_4 [ 2 ] -> integer . V_15 ) ) ;
V_7 = F_5 ( sizeof( struct V_6 ) ) ;
if ( V_7 ) {
V_7 -> type = ( V_14 ) V_4 [ 0 ] -> integer . V_15 ;
V_7 -> V_16 = ( V_14 ) V_4 [ 1 ] -> integer . V_15 ;
V_7 -> V_17 = ( V_14 ) V_4 [ 2 ] -> integer . V_15 ;
}
V_8 = F_6 ( V_18 , V_7 ) ;
F_7 ( V_7 ) ;
break;
default:
F_8 ( ( V_19 , L_2 ,
V_2 -> V_11 ) ) ;
V_8 = V_20 ;
goto V_21;
}
V_21:
F_9 ( V_8 ) ;
}
T_1 F_10 ( struct V_1 * V_2 )
{
union V_3 * * V_4 = & V_2 -> V_5 [ 0 ] ;
union V_3 * V_22 = NULL ;
char * V_23 = NULL ;
T_1 V_8 = V_9 ;
T_2 V_24 ;
T_3 V_25 ;
F_2 ( V_26 ,
F_3 ( V_2 -> V_11 ) ) ;
switch ( V_2 -> V_11 ) {
case V_27 :
V_22 = F_11 ( ( V_4 [ 0 ] ) ->
V_28 . type ) ;
if ( ! V_22 ) {
V_8 = V_29 ;
goto V_21;
}
V_24 = V_4 [ 1 ] -> integer . V_15 ;
V_25 = ( T_3 ) V_4 [ 2 ] -> integer . V_15 ;
if ( V_24 >= V_4 [ 0 ] -> string . V_25 ) {
V_25 = 0 ;
}
else if ( ( V_24 + V_25 ) > V_4 [ 0 ] -> string . V_25 ) {
V_25 = ( T_3 ) V_4 [ 0 ] -> string . V_25 -
( T_3 ) V_24 ;
}
switch ( ( V_4 [ 0 ] ) -> V_28 . type ) {
case V_30 :
V_23 = F_12 ( ( T_3 ) V_25 + 1 ) ;
if ( ! V_23 ) {
V_8 = V_29 ;
goto V_21;
}
break;
case V_31 :
if ( V_25 > 0 ) {
V_23 = F_12 ( V_25 ) ;
if ( ! V_23 ) {
V_8 = V_29 ;
goto V_21;
}
}
break;
default:
V_8 = V_32 ;
goto V_21;
}
if ( V_23 ) {
F_13 ( V_23 , V_4 [ 0 ] -> string . V_33 + V_24 ,
V_25 ) ;
}
V_22 -> string . V_33 = V_23 ;
V_22 -> string . V_25 = ( V_14 ) V_25 ;
V_22 -> V_23 . V_34 |= V_35 ;
break;
default:
F_8 ( ( V_19 , L_2 ,
V_2 -> V_11 ) ) ;
V_8 = V_20 ;
goto V_21;
}
V_8 = F_14 ( V_22 , V_4 [ 3 ] , V_2 ) ;
V_21:
if ( F_15 ( V_8 ) || V_2 -> V_36 ) {
F_16 ( V_22 ) ;
V_2 -> V_36 = NULL ;
}
else {
V_2 -> V_36 = V_22 ;
}
F_9 ( V_8 ) ;
}
