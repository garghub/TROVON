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
V_17 -> V_19 = V_15 ;
V_17 -> V_20 = V_21 ;
F_13 ( ( V_13 ,
L_6 ,
V_15 -> V_10 ) ) ;
return ( V_15 ) ;
}
void
F_14 ( T_4 V_22 ,
char * V_23 , T_3 V_14 )
{
struct V_6 * V_24 ;
struct V_6 * V_25 ;
struct V_16 * V_17 ;
if ( ! V_22 ) {
F_8 ( ( V_13 ,
L_7 ,
V_23 ) ) ;
return;
}
V_24 = F_15 ( V_22 , sizeof( struct V_6 ) ) ;
if ( ! V_24 ) {
F_8 ( ( V_13 ,
L_8 ,
V_23 , F_16 ( void , V_22 ) ) ) ;
return;
}
if ( V_23 && ! F_17 ( V_24 -> V_23 , V_23 ) ) {
F_6 ( ( V_13 ,
L_9 ,
* F_16 ( T_3 , V_24 -> V_23 ) ,
V_23 ) ) ;
goto V_26;
}
V_17 = & V_7 . V_18 [ V_14 ] ;
V_17 -> V_22 = V_22 ;
V_17 -> V_19 = NULL ;
V_17 -> V_10 = V_24 -> V_10 ;
V_17 -> V_20 = V_27 ;
F_18 ( V_17 -> V_23 . V_28 , V_24 -> V_23 ) ;
V_25 = F_19 ( V_24 , V_17 ) ;
if ( ! V_25 ) {
V_25 = V_24 ;
}
F_7 ( V_17 -> V_22 , V_25 ) ;
if ( V_14 == V_29 ) {
F_20 ( V_25 -> V_30 ) ;
}
if ( V_25 != V_24 ) {
F_12 ( V_17 ) ;
}
V_26:
F_21 ( V_24 , sizeof( struct V_6 ) ) ;
}
static T_4
F_22 ( T_2 * V_31 , T_3 V_32 )
{
T_5 V_33 ;
if ( V_32 == V_34 ) {
return ( ( T_4 )
( * F_16 ( T_3 , V_31 ) ) ) ;
} else {
F_23 ( & V_33 , V_31 ) ;
#if V_35 == 32
if ( V_33 > V_36 ) {
F_24 ( ( V_13 ,
L_10
L_11 ,
F_25 ( V_33 ) ) ) ;
}
#endif
return ( ( T_4 ) ( V_33 ) ) ;
}
}
static T_1 F_26 ( T_4 V_37 )
{
struct V_6 * V_24 ;
T_2 * V_38 ;
T_4 V_22 ;
T_3 V_10 ;
T_3 V_39 ;
T_1 V_1 ;
T_3 V_40 ;
V_24 =
F_15 ( V_37 , sizeof( struct V_6 ) ) ;
if ( ! V_24 ) {
return ( V_41 ) ;
}
V_10 = V_24 -> V_10 ;
F_21 ( V_24 , sizeof( struct V_6 ) ) ;
if ( V_10 < ( sizeof( struct V_6 ) + V_42 ) ) {
return ( V_43 ) ;
}
V_24 = F_15 ( V_37 , V_10 ) ;
if ( ! V_24 ) {
return ( V_41 ) ;
}
V_1 = V_4 ;
V_38 = F_27 ( T_2 , V_24 , sizeof( struct V_6 ) ) ;
V_39 = ( T_3 ) ( ( V_24 -> V_10 - sizeof( struct V_6 ) ) /
V_42 ) ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_22 =
F_22 ( V_38 ,
V_42 ) ;
if ( ! V_22 ) {
V_1 = V_44 ;
break;
}
V_38 += V_42 ;
}
F_21 ( V_24 , V_10 ) ;
return ( V_1 ) ;
}
T_1 T_6 F_28 ( T_4 V_45 )
{
struct V_46 * V_47 ;
T_3 V_32 ;
T_3 V_40 ;
T_3 V_48 ;
struct V_6 * V_24 ;
T_4 V_22 ;
T_4 V_49 ;
T_3 V_10 ;
T_2 * V_31 ;
T_1 V_1 ;
F_29 ( V_50 ) ;
V_47 = F_15 ( V_45 , sizeof( struct V_46 ) ) ;
if ( ! V_47 ) {
F_30 ( V_41 ) ;
}
F_7 ( V_45 ,
F_16 ( struct V_6 ,
V_47 ) ) ;
if ( ( V_47 -> V_30 > 1 ) &&
V_47 -> V_51 && ! V_52 ) {
V_22 = ( T_4 ) V_47 -> V_51 ;
V_49 =
( T_4 ) V_47 -> V_53 ;
V_32 = V_42 ;
} else {
V_22 = ( T_4 ) V_47 -> V_53 ;
V_49 = V_22 ;
V_32 = V_34 ;
}
F_21 ( V_47 , sizeof( struct V_46 ) ) ;
if ( V_32 == V_42 ) {
V_1 = F_26 ( V_22 ) ;
if ( F_31 ( V_1 ) ) {
F_24 ( ( V_13 ,
L_12 ,
F_32 ( V_1 ) ) ) ;
V_22 = V_49 ;
V_32 = V_34 ;
}
}
V_24 = F_15 ( V_22 , sizeof( struct V_6 ) ) ;
if ( ! V_24 ) {
F_30 ( V_41 ) ;
}
F_7 ( V_22 , V_24 ) ;
V_10 = V_24 -> V_10 ;
F_21 ( V_24 , sizeof( struct V_6 ) ) ;
if ( V_10 < ( sizeof( struct V_6 ) + V_32 ) ) {
F_6 ( ( V_13 ,
L_13 ,
V_10 ) ) ;
F_30 ( V_43 ) ;
}
V_24 = F_15 ( V_22 , V_10 ) ;
if ( ! V_24 ) {
F_30 ( V_41 ) ;
}
V_1 = F_33 ( V_24 , V_10 ) ;
if ( F_31 ( V_1 ) ) {
F_21 ( V_24 , V_10 ) ;
F_30 ( V_1 ) ;
}
V_48 = ( T_3 ) ( ( V_24 -> V_10 - sizeof( struct V_6 ) ) /
V_32 ) ;
V_31 = F_27 ( T_2 , V_24 , sizeof( struct V_6 ) ) ;
V_7 . V_8 = 2 ;
for ( V_40 = 0 ; V_40 < V_48 ; V_40 ++ ) {
if ( V_7 . V_8 >=
V_7 . V_54 ) {
V_1 = F_34 () ;
if ( F_31 ( V_1 ) ) {
F_35 ( ( V_13 ,
L_14 ,
( unsigned ) ( V_48 -
( V_7 .
V_8 -
2 ) ) ) ) ;
break;
}
}
V_7 . V_18 [ V_7 .
V_8 ] . V_22 =
F_22 ( V_31 , V_32 ) ;
V_31 += V_32 ;
V_7 . V_8 ++ ;
}
F_21 ( V_24 , V_10 ) ;
for ( V_40 = 2 ; V_40 < V_7 . V_8 ; V_40 ++ ) {
F_14 ( V_7 . V_18 [ V_40 ] .
V_22 , NULL , V_40 ) ;
if ( F_17
( & V_7 . V_18 [ V_40 ] . V_23 ,
V_55 ) ) {
F_36 ( V_40 ) ;
}
}
F_30 ( V_4 ) ;
}
