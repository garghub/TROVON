static void
F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 ,
T_2 V_5 , char * V_6 , T_1 V_7 )
{
T_1 V_8 ;
V_8 = ( T_1 ) ( V_4 * 8 ) ;
if ( V_4 > 31 ) {
if ( ! ( V_7 & V_9 ) ) {
F_2 ( ( V_10 ,
L_1
L_2 ,
V_6 , V_4 ,
( V_4 * 8 ) ) ) ;
}
V_8 = 255 ;
}
F_3 ( & V_2 -> V_5 , & V_5 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
}
static T_2
F_4 ( char * V_6 , T_3 V_13 , T_2 V_14 )
{
if ( ! V_14 ) {
return ( ( T_2 ) V_13 ) ;
}
if ( V_13 && ( V_14 != ( T_2 ) V_13 ) ) {
F_5 ( ( V_10 ,
L_3
L_4 ,
V_6 , V_13 ,
F_6 ( V_14 ) ,
V_15 ? 32 :
64 ) ) ;
if ( V_15 ) {
return ( ( T_2 ) V_13 ) ;
}
}
return ( V_14 ) ;
}
void F_7 ( T_3 V_16 )
{
T_3 V_17 ;
struct V_18 * V_19 ;
V_17 = V_20 . V_21 [ V_16 ] . V_17 ;
V_19 =
F_8 ( V_20 . V_21 [ V_16 ] .
V_5 , V_17 ) ;
if ( ! V_19 ) {
return;
}
( void ) F_9 ( V_19 , V_17 ) ;
F_10 ( V_19 , V_17 ) ;
F_11 ( V_19 , V_17 ) ;
F_12 ( ( V_22 ) V_23 . V_24 ,
V_25 , V_26 ) ;
if ( ! V_27 ) {
F_12 ( ( V_22 )
V_23 . V_28 , V_29 ,
V_30 ) ;
}
}
void F_10 ( struct V_18 * V_19 , T_3 V_17 )
{
if ( V_17 > sizeof( struct V_31 ) ) {
F_5 ( ( V_10 ,
L_5
L_6 ,
V_19 -> V_32 , V_17 ,
( T_3 ) sizeof( struct V_31 ) ) ) ;
}
F_13 ( & V_23 , 0 , sizeof( struct V_31 ) ) ;
F_14 ( & V_23 , V_19 ,
F_15 ( V_17 , sizeof( struct V_31 ) ) ) ;
V_27 = FALSE ;
if ( V_23 . V_7 & V_33 ) {
V_27 = TRUE ;
}
F_16 () ;
F_17 () ;
}
static void F_16 ( void )
{
char * V_34 ;
struct V_1 * V_14 ;
T_3 V_13 ;
T_1 V_17 ;
T_1 V_7 ;
T_3 V_35 ;
if ( V_23 . V_36 . V_17 <= V_37 ) {
V_23 . V_38 = 0 ;
V_23 . V_39 = 0 ;
V_23 . V_40 = 0 ;
V_23 . V_41 = 0 ;
}
V_23 . V_36 . V_17 = sizeof( struct V_31 ) ;
V_23 . V_28 = F_4 ( L_7 ,
V_23 . V_42 ,
V_23 . V_28 ) ;
V_23 . V_24 = F_4 ( L_8 ,
V_23 . V_43 ,
V_23 . V_24 ) ;
if ( V_27 ) {
return;
}
for ( V_35 = 0 ; V_35 < V_44 ; V_35 ++ ) {
V_13 = * F_18 ( T_3 ,
& V_23 ,
V_45 [ V_35 ] . V_13 ) ;
V_14 = F_18 ( struct V_1 ,
& V_23 ,
V_45 [ V_35 ] . V_14 ) ;
V_17 = * F_18 ( T_1 ,
& V_23 ,
V_45 [ V_35 ] . V_17 ) ;
V_34 = V_45 [ V_35 ] . V_34 ;
V_7 = V_45 [ V_35 ] . V_7 ;
if ( V_13 ) {
if ( ! V_14 -> V_5 ) {
F_1 ( V_14 ,
V_46 ,
* F_18 ( T_1 ,
& V_23 ,
V_45
[ V_35 ] .
V_17 ) ,
( T_2 ) V_13 ,
V_34 , V_7 ) ;
} else if ( V_14 -> V_5 != ( T_2 ) V_13 ) {
F_5 ( ( V_10 ,
L_9
L_4 ,
V_34 , V_13 ,
F_6
( V_14 -> V_5 ) ,
V_15
? 32 : 64 ) ) ;
if ( V_15 ) {
F_1 ( V_14 ,
V_46 ,
* F_18
( T_1 ,
& V_23 ,
V_45
[ V_35 ] .
V_17 ) ,
( T_2 )
V_13 ,
V_34 ,
V_7 ) ;
}
}
}
if ( V_14 -> V_5 &&
( F_19 ( V_17 ) <= V_47 ) &&
( V_14 -> V_8 != F_19 ( V_17 ) ) ) {
F_5 ( ( V_10 ,
L_10 ,
V_34 , F_19 ( V_17 ) ,
V_14 -> V_8 ) ) ;
}
if ( V_45 [ V_35 ] . V_7 & V_48 ) {
if ( ! V_14 -> V_5 || ! V_17 ) {
F_20 ( ( V_10 ,
L_11
L_12 ,
V_34 ,
F_6 ( V_14 ->
V_5 ) ,
V_17 ) ) ;
}
} else if ( V_45 [ V_35 ] . V_7 & V_49 ) {
if ( ( V_14 -> V_5 && ! V_17 ) ||
( ! V_14 -> V_5 && V_17 ) ) {
F_5 ( ( V_10 ,
L_13
L_12 ,
V_34 ,
F_6
( V_14 -> V_5 ) ,
V_17 ) ) ;
}
}
}
}
static void F_17 ( void )
{
struct V_1 * V_50 ;
struct V_1 * V_51 ;
T_1 V_52 ;
T_3 V_35 ;
if ( V_53 ) {
for ( V_35 = 0 ; V_35 < V_44 ; V_35 ++ ) {
V_50 =
F_18 ( struct V_1 ,
& V_23 ,
V_45 [ V_35 ] . V_14 ) ;
if ( ( V_50 -> V_5 ) &&
( V_45 [ V_35 ] . V_54 > 0 ) &&
( V_45 [ V_35 ] . V_54 !=
V_50 -> V_8 ) ) {
F_5 ( ( V_10 ,
L_14 ,
V_45 [ V_35 ] . V_34 ,
V_50 -> V_8 ,
V_45 [ V_35 ] .
V_54 ) ) ;
V_50 -> V_8 =
V_45 [ V_35 ] . V_54 ;
}
}
}
V_52 = ( T_1 )
F_21 ( V_23 . V_55 . V_8 ) ;
for ( V_35 = 0 ; V_35 < V_56 ; V_35 ++ ) {
V_51 =
F_18 ( struct V_1 , & V_23 ,
V_57 [ V_35 ] . V_58 ) ;
if ( V_51 -> V_5 ) {
F_1 ( V_57 [ V_35 ] .
V_59 , V_51 -> V_3 ,
V_52 ,
V_51 -> V_5 +
( V_57 [ V_35 ] .
V_60 *
V_52 ) ,
L_15 , 0 ) ;
}
}
}
