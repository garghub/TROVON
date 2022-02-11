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
goto V_19;
case V_20 :
V_8 = V_9 ;
goto V_19;
default:
F_8 ( ( V_21 , L_2 ,
V_2 -> V_11 ) ) ;
V_8 = V_22 ;
goto V_19;
}
V_19:
F_9 ( V_8 ) ;
}
T_1 F_10 ( struct V_1 * V_2 )
{
union V_3 * * V_4 = & V_2 -> V_5 [ 0 ] ;
union V_3 * V_23 = NULL ;
char * V_24 = NULL ;
T_1 V_8 = V_9 ;
T_2 V_25 ;
T_3 V_26 ;
F_2 ( V_27 ,
F_3 ( V_2 -> V_11 ) ) ;
switch ( V_2 -> V_11 ) {
case V_28 :
V_23 = F_11 ( ( V_4 [ 0 ] ) ->
V_29 . type ) ;
if ( ! V_23 ) {
V_8 = V_30 ;
goto V_19;
}
V_25 = V_4 [ 1 ] -> integer . V_15 ;
V_26 = ( T_3 ) V_4 [ 2 ] -> integer . V_15 ;
if ( V_25 >= V_4 [ 0 ] -> string . V_26 ) {
V_26 = 0 ;
}
else if ( ( V_25 + V_26 ) > V_4 [ 0 ] -> string . V_26 ) {
V_26 = ( T_3 ) V_4 [ 0 ] -> string . V_26 -
( T_3 ) V_25 ;
}
switch ( ( V_4 [ 0 ] ) -> V_29 . type ) {
case V_31 :
V_24 = F_12 ( ( T_3 ) V_26 + 1 ) ;
if ( ! V_24 ) {
V_8 = V_30 ;
goto V_19;
}
break;
case V_32 :
if ( V_26 > 0 ) {
V_24 = F_12 ( V_26 ) ;
if ( ! V_24 ) {
V_8 = V_30 ;
goto V_19;
}
}
break;
default:
V_8 = V_33 ;
goto V_19;
}
if ( V_24 ) {
F_13 ( V_24 , V_4 [ 0 ] -> string . V_34 + V_25 ,
V_26 ) ;
}
V_23 -> string . V_34 = V_24 ;
V_23 -> string . V_26 = ( V_14 ) V_26 ;
V_23 -> V_24 . V_35 |= V_36 ;
break;
default:
F_8 ( ( V_21 , L_2 ,
V_2 -> V_11 ) ) ;
V_8 = V_22 ;
goto V_19;
}
V_8 = F_14 ( V_23 , V_4 [ 3 ] , V_2 ) ;
V_19:
if ( F_15 ( V_8 ) || V_2 -> V_37 ) {
F_16 ( V_23 ) ;
V_2 -> V_37 = NULL ;
}
else {
V_2 -> V_37 = V_23 ;
}
F_9 ( V_8 ) ;
}
