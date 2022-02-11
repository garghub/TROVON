T_1 F_1 ( void )
{
if ( V_1 ) {
V_2 = NULL ;
return ( V_3 ) ;
}
( void ) F_2 ( V_4 ,
F_3 ( struct
V_5 ,
& V_6 ) ) ;
( void ) F_2 ( V_7 ,
F_3 ( struct
V_5 ,
& V_8 ) ) ;
if ( V_8
&& ( ! V_6 || ! V_9 ) ) {
V_2 = V_8 ;
} else if ( V_6 ) {
V_2 = V_6 ;
}
return ( V_3 ) ;
}
T_2 F_4 ( void )
{
if ( V_10 . V_11 >= 4 ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
void F_5 ( void )
{
if ( V_12 . V_13 != V_14 -> V_13 ||
V_12 . V_15 != V_14 -> V_15 ) {
F_6 ( ( V_16 ,
L_1
L_2 ) ) ;
F_7 ( 0 , & V_12 ) ;
F_7 ( 0 , V_14 ) ;
F_8 ( ( V_16 ,
L_3
L_4 ) ) ;
V_12 . V_13 = V_14 -> V_13 ;
V_12 . V_15 =
V_14 -> V_15 ;
}
}
struct V_5 * F_9 ( T_3 V_17 )
{
struct V_5 * V_18 ;
struct V_19 * V_20 ;
V_20 = & V_10 . V_21 [ V_17 ] ;
V_18 = F_10 ( V_20 -> V_13 ) ;
if ( ! V_18 ) {
F_8 ( ( V_16 , L_5 ,
V_20 -> V_13 ) ) ;
return ( NULL ) ;
}
memcpy ( V_18 , V_20 -> V_22 , V_20 -> V_13 ) ;
F_11 ( V_20 ) ;
F_12 ( & V_10 .
V_21 [ V_23 ] ,
F_13 ( V_18 ) ,
V_24 ,
V_18 ) ;
F_14 ( ( V_16 ,
L_6 ,
V_18 -> V_13 ) ) ;
return ( V_18 ) ;
}
static T_4
F_15 ( T_2 * V_25 , T_3 V_26 )
{
T_5 V_27 ;
if ( V_26 == V_28 ) {
return ( ( T_4 )
( * F_16 ( T_3 , V_25 ) ) ) ;
} else {
F_17 ( & V_27 , V_25 ) ;
#if V_29 == 32
if ( V_27 > V_30 ) {
F_18 ( ( V_16 ,
L_7
L_8 ,
F_19 ( V_27 ) ) ) ;
}
#endif
return ( ( T_4 ) ( V_27 ) ) ;
}
}
T_1 T_6 F_20 ( T_4 V_31 )
{
struct V_32 * V_33 ;
T_3 V_26 ;
T_3 V_34 ;
T_3 V_35 ;
struct V_5 * V_36 ;
T_4 V_37 ;
T_3 V_13 ;
T_2 * V_25 ;
T_1 V_38 ;
T_3 V_17 ;
F_21 ( V_39 ) ;
V_33 = F_22 ( V_31 , sizeof( struct V_32 ) ) ;
if ( ! V_33 ) {
F_23 ( V_40 ) ;
}
F_7 ( V_31 ,
F_16 ( struct V_5 ,
V_33 ) ) ;
if ( ( V_33 -> V_41 > 1 ) &&
V_33 -> V_42 && ! V_43 ) {
V_37 = ( T_4 ) V_33 -> V_42 ;
V_26 = V_44 ;
} else {
V_37 = ( T_4 ) V_33 -> V_45 ;
V_26 = V_28 ;
}
F_24 ( V_33 , sizeof( struct V_32 ) ) ;
V_36 = F_22 ( V_37 , sizeof( struct V_5 ) ) ;
if ( ! V_36 ) {
F_23 ( V_40 ) ;
}
F_7 ( V_37 , V_36 ) ;
V_13 = V_36 -> V_13 ;
F_24 ( V_36 , sizeof( struct V_5 ) ) ;
if ( V_13 < ( sizeof( struct V_5 ) + V_26 ) ) {
F_6 ( ( V_16 ,
L_9 ,
V_13 ) ) ;
F_23 ( V_46 ) ;
}
V_36 = F_22 ( V_37 , V_13 ) ;
if ( ! V_36 ) {
F_23 ( V_40 ) ;
}
V_38 = F_25 ( V_36 , V_13 ) ;
if ( F_26 ( V_38 ) ) {
F_24 ( V_36 , V_13 ) ;
F_23 ( V_38 ) ;
}
V_35 = ( T_3 ) ( ( V_36 -> V_13 - sizeof( struct V_5 ) ) /
V_26 ) ;
V_25 = F_27 ( T_2 , V_36 , sizeof( struct V_5 ) ) ;
V_10 . V_11 = 3 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
V_37 =
F_15 ( V_25 , V_26 ) ;
if ( ! V_37 ) {
goto V_47;
}
V_38 = F_28 ( V_37 ,
V_48 ,
FALSE , TRUE ,
& V_17 ) ;
if ( F_29 ( V_38 ) &&
F_30 ( & V_10 .
V_21 [ V_17 ] . V_49 ,
V_50 ) ) {
F_31 ( V_17 ) ;
}
V_47:
V_25 += V_26 ;
}
F_24 ( V_36 , V_13 ) ;
F_23 ( V_3 ) ;
}
