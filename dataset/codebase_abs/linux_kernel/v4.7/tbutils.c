T_1 F_1 ( void )
{
struct V_1 * V_2 ;
if ( V_3 ) {
V_4 = NULL ;
return ( V_5 ) ;
} else if ( V_6 . V_7 &&
( ! V_6 . V_2
|| ! V_8 ) ) {
( void ) F_2 ( V_9 ,
F_3 ( struct
V_10 ,
& V_2 ) ) ;
V_4 = V_2 ;
} else if ( V_6 . V_2 ) {
( void ) F_2 ( V_11 ,
F_3 ( struct
V_10 ,
& V_2 ) ) ;
V_4 = V_2 ;
}
return ( V_5 ) ;
}
void F_4 ( void )
{
if ( V_12 . V_13 != V_14 -> V_13 ||
V_12 . V_15 != V_14 -> V_15 ) {
F_5 ( ( V_16 ,
L_1
L_2 ) ) ;
F_6 ( 0 , & V_12 ) ;
F_6 ( 0 , V_14 ) ;
F_7 ( ( V_16 ,
L_3
L_4 ) ) ;
V_12 . V_13 = V_14 -> V_13 ;
V_12 . V_15 =
V_14 -> V_15 ;
}
}
struct V_10 * F_8 ( T_2 V_17 )
{
struct V_10 * V_18 ;
struct V_19 * V_20 ;
V_20 = & V_21 . V_22 [ V_17 ] ;
V_18 = F_9 ( V_20 -> V_13 ) ;
if ( ! V_18 ) {
F_7 ( ( V_16 , L_5 ,
V_20 -> V_13 ) ) ;
return ( NULL ) ;
}
memcpy ( V_18 , V_20 -> V_23 , V_20 -> V_13 ) ;
F_10 ( V_20 ) ;
F_11 ( & V_21 .
V_22 [ V_24 ] ,
F_12 ( V_18 ) ,
V_25 ,
V_18 ) ;
F_13 ( ( L_6 , V_18 -> V_13 ) ) ;
return ( V_18 ) ;
}
static T_3
F_14 ( T_4 * V_26 , T_2 V_27 )
{
T_5 V_28 ;
if ( V_27 == V_29 ) {
return ( ( T_3 )
( * F_15 ( T_2 , V_26 ) ) ) ;
} else {
F_16 ( & V_28 , V_26 ) ;
#if V_30 == 32
if ( V_28 > V_31 ) {
F_17 ( ( V_16 ,
L_7
L_8 ,
F_18 ( V_28 ) ) ) ;
}
#endif
return ( ( T_3 ) ( V_28 ) ) ;
}
}
T_1 T_6 F_19 ( T_3 V_32 )
{
struct V_33 * V_34 ;
T_2 V_27 ;
T_2 V_35 ;
T_2 V_36 ;
struct V_10 * V_37 ;
T_3 V_38 ;
T_2 V_13 ;
T_4 * V_26 ;
T_1 V_39 ;
T_2 V_17 ;
F_20 ( V_40 ) ;
V_34 = F_21 ( V_32 , sizeof( struct V_33 ) ) ;
if ( ! V_34 ) {
F_22 ( V_41 ) ;
}
F_6 ( V_32 ,
F_15 ( struct V_10 ,
V_34 ) ) ;
if ( ( V_34 -> V_42 > 1 ) &&
V_34 -> V_43 && ! V_44 ) {
V_38 = ( T_3 ) V_34 -> V_43 ;
V_27 = V_45 ;
} else {
V_38 = ( T_3 ) V_34 -> V_46 ;
V_27 = V_29 ;
}
F_23 ( V_34 , sizeof( struct V_33 ) ) ;
V_37 = F_21 ( V_38 , sizeof( struct V_10 ) ) ;
if ( ! V_37 ) {
F_22 ( V_41 ) ;
}
F_6 ( V_38 , V_37 ) ;
V_13 = V_37 -> V_13 ;
F_23 ( V_37 , sizeof( struct V_10 ) ) ;
if ( V_13 < ( sizeof( struct V_10 ) + V_27 ) ) {
F_5 ( ( V_16 ,
L_9 ,
V_13 ) ) ;
F_22 ( V_47 ) ;
}
V_37 = F_21 ( V_38 , V_13 ) ;
if ( ! V_37 ) {
F_22 ( V_41 ) ;
}
V_39 = F_24 ( V_37 , V_13 ) ;
if ( F_25 ( V_39 ) ) {
F_23 ( V_37 , V_13 ) ;
F_22 ( V_39 ) ;
}
V_36 = ( T_2 ) ( ( V_37 -> V_13 - sizeof( struct V_10 ) ) /
V_27 ) ;
V_26 = F_26 ( T_4 , V_37 , sizeof( struct V_10 ) ) ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_38 =
F_14 ( V_26 , V_27 ) ;
if ( ! V_38 ) {
goto V_48;
}
V_39 = F_27 ( V_38 ,
V_49 ,
FALSE , TRUE ,
& V_17 ) ;
if ( F_28 ( V_39 ) &&
F_29 ( & V_21 .
V_22 [ V_17 ] . V_50 ,
V_51 ) ) {
V_52 = V_17 ;
F_30 () ;
}
V_48:
V_26 += V_27 ;
}
F_23 ( V_37 , V_13 ) ;
F_22 ( V_5 ) ;
}
