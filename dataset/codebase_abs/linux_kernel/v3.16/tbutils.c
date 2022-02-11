T_1 F_1 ( void )
{
T_1 V_1 ;
if ( V_2 ) {
V_3 = NULL ;
return ( V_4 ) ;
}
V_1 = F_2 ( V_5 ,
F_3 ( struct
V_6 ,
& V_3 ) ) ;
return ( V_1 ) ;
}
T_2 F_4 ( void )
{
if ( V_7 . V_8 >= 3 ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
void F_5 ( void )
{
if ( V_9 . V_10 != V_11 -> V_10 ||
V_9 . V_12 != V_11 -> V_12 ) {
F_6 ( ( V_13 ,
L_1
L_2 ) ) ;
F_7 ( 0 , & V_9 ) ;
F_7 ( 0 , V_11 ) ;
F_8 ( ( V_13 ,
L_3
L_4 ) ) ;
V_9 . V_10 = V_11 -> V_10 ;
V_9 . V_12 =
V_11 -> V_12 ;
}
}
struct V_6 * F_9 ( T_3 V_14 )
{
struct V_6 * V_15 ;
struct V_16 * V_17 ;
V_17 = & V_7 . V_18 [ V_14 ] ;
V_15 = F_10 ( V_17 -> V_10 ) ;
if ( ! V_15 ) {
F_8 ( ( V_13 , L_5 ,
V_17 -> V_10 ) ) ;
return ( NULL ) ;
}
F_11 ( V_15 , V_17 -> V_19 , V_17 -> V_10 ) ;
F_12 ( V_17 ) ;
F_13 ( & V_7 .
V_18 [ V_20 ] ,
F_14 ( V_15 ) ,
V_21 ,
V_15 ) ;
F_15 ( ( V_13 ,
L_6 ,
V_15 -> V_10 ) ) ;
return ( V_15 ) ;
}
static T_4
F_16 ( T_2 * V_22 , T_3 V_23 )
{
T_5 V_24 ;
if ( V_23 == V_25 ) {
return ( ( T_4 )
( * F_17 ( T_3 , V_22 ) ) ) ;
} else {
F_18 ( & V_24 , V_22 ) ;
#if V_26 == 32
if ( V_24 > V_27 ) {
F_19 ( ( V_13 ,
L_7
L_8 ,
F_20 ( V_24 ) ) ) ;
}
#endif
return ( ( T_4 ) ( V_24 ) ) ;
}
}
T_1 T_6 F_21 ( T_4 V_28 )
{
struct V_29 * V_30 ;
T_3 V_23 ;
T_3 V_31 ;
T_3 V_32 ;
struct V_6 * V_33 ;
T_4 V_34 ;
T_3 V_10 ;
T_2 * V_22 ;
T_1 V_1 ;
T_3 V_14 ;
F_22 ( V_35 ) ;
V_30 = F_23 ( V_28 , sizeof( struct V_29 ) ) ;
if ( ! V_30 ) {
F_24 ( V_36 ) ;
}
F_7 ( V_28 ,
F_17 ( struct V_6 ,
V_30 ) ) ;
if ( ( V_30 -> V_37 > 1 ) &&
V_30 -> V_38 && ! V_39 ) {
V_34 = ( T_4 ) V_30 -> V_38 ;
V_23 = V_40 ;
} else {
V_34 = ( T_4 ) V_30 -> V_41 ;
V_23 = V_25 ;
}
F_25 ( V_30 , sizeof( struct V_29 ) ) ;
V_33 = F_23 ( V_34 , sizeof( struct V_6 ) ) ;
if ( ! V_33 ) {
F_24 ( V_36 ) ;
}
F_7 ( V_34 , V_33 ) ;
V_10 = V_33 -> V_10 ;
F_25 ( V_33 , sizeof( struct V_6 ) ) ;
if ( V_10 < ( sizeof( struct V_6 ) + V_23 ) ) {
F_6 ( ( V_13 ,
L_9 ,
V_10 ) ) ;
F_24 ( V_42 ) ;
}
V_33 = F_23 ( V_34 , V_10 ) ;
if ( ! V_33 ) {
F_24 ( V_36 ) ;
}
V_1 = F_26 ( V_33 , V_10 ) ;
if ( F_27 ( V_1 ) ) {
F_25 ( V_33 , V_10 ) ;
F_24 ( V_1 ) ;
}
V_32 = ( T_3 ) ( ( V_33 -> V_10 - sizeof( struct V_6 ) ) /
V_23 ) ;
V_22 = F_28 ( T_2 , V_33 , sizeof( struct V_6 ) ) ;
V_7 . V_8 = 2 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_34 =
F_16 ( V_22 , V_23 ) ;
if ( ! V_34 ) {
goto V_43;
}
V_1 = F_29 ( V_34 ,
V_44 ,
FALSE , TRUE ,
& V_14 ) ;
if ( F_30 ( V_1 ) &&
F_31 ( & V_7 .
V_18 [ V_14 ] . V_45 ,
V_46 ) ) {
F_32 ( V_14 ) ;
}
V_43:
V_22 += V_23 ;
}
F_25 ( V_33 , V_10 ) ;
F_24 ( V_4 ) ;
}
