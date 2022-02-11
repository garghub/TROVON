T_1 F_1 ( void )
{
T_2 V_1 ;
( void ) F_2 ( V_2 , V_3 ) ;
V_4 = V_5 ;
for ( V_1 = 0 ;
V_1 < ( F_3 ( V_5 ) - 1 ) ;
V_1 ++ ) {
V_5 [ V_1 ] . V_6 =
& V_5 [ ( V_7 ) V_1 + 1 ] ;
}
F_4 ( V_2 ) ;
return ( V_8 ) ;
}
void F_5 ( void )
{
struct V_9 * V_10 ;
( void ) F_2 ( V_2 , V_3 ) ;
V_10 = V_4 ;
while ( V_10 ) {
V_4 = V_10 -> V_6 ;
if ( V_10 -> V_11 & V_12 ) {
F_6 ( V_10 -> V_13 ) ;
F_6 ( V_10 ) ;
}
V_10 = V_4 ;
}
F_4 ( V_2 ) ;
}
T_1 F_7 ( T_3 V_14 )
{
struct V_9 * V_15 ;
V_15 =
F_8 ( sizeof( struct V_9 ) ) ;
if ( ! V_15 ) {
return ( V_16 ) ;
}
V_15 -> V_13 =
F_8 ( F_9 ( V_14 ) + 1 ) ;
if ( ! V_15 -> V_13 ) {
F_6 ( V_15 ) ;
return ( V_16 ) ;
}
F_10 ( V_15 -> V_13 , V_14 ) ;
V_15 -> V_11 = V_12 ;
V_15 -> V_6 = V_4 ;
V_4 = V_15 ;
return ( V_8 ) ;
}
T_1 F_11 ( T_3 V_14 )
{
struct V_9 * V_17 ;
struct V_9 * V_10 ;
V_17 = V_10 = V_4 ;
while ( V_10 ) {
if ( ! F_12 ( V_14 , V_10 -> V_13 ) ) {
if ( V_10 -> V_11 & V_12 ) {
if ( V_17 == V_10 ) {
V_4 =
V_10 -> V_6 ;
} else {
V_17 -> V_6 =
V_10 -> V_6 ;
}
F_6 ( V_10 -> V_13 ) ;
F_6 ( V_10 ) ;
} else {
if ( V_10 -> V_11 & V_18 ) {
return ( V_19 ) ;
}
V_10 -> V_11 |= V_18 ;
}
return ( V_8 ) ;
}
V_17 = V_10 ;
V_10 = V_10 -> V_6 ;
}
return ( V_19 ) ;
}
struct V_9 * F_13 ( T_3 V_14 )
{
struct V_9 * V_10 ;
V_10 = V_4 ;
while ( V_10 ) {
if ( ! F_12 ( V_14 , V_10 -> V_13 ) ) {
return ( V_10 ) ;
}
V_10 = V_10 -> V_6 ;
}
return ( NULL ) ;
}
T_1 F_14 ( struct V_20 * V_21 )
{
union V_22 * V_23 ;
union V_22 * V_24 ;
struct V_9 * V_15 ;
T_4 V_25 ;
T_2 V_26 ;
F_15 ( V_27 ) ;
V_23 = V_21 -> V_28 [ 0 ] . V_29 ;
if ( ! V_23 || ( V_23 -> V_30 . type != V_31 ) ) {
F_16 ( V_32 ) ;
}
V_24 = F_17 ( V_33 ) ;
if ( ! V_24 ) {
F_16 ( V_16 ) ;
}
V_26 = 0 ;
( void ) F_2 ( V_2 , V_3 ) ;
V_15 = F_13 ( V_23 -> string . V_34 ) ;
if ( V_15 && ! ( V_15 -> V_11 & V_18 ) ) {
if ( V_15 -> V_35 > V_36 ) {
V_36 = V_15 -> V_35 ;
}
V_26 = V_37 ;
}
F_4 ( V_2 ) ;
V_25 = V_38 ;
if ( V_25 ) {
V_26 =
V_25 ( V_23 -> string . V_34 ,
V_26 ) ;
}
F_18 ( ( V_39 ,
L_1 ,
V_23 -> string . V_34 ,
V_26 == 0 ? L_2 : L_3 ) ) ;
V_24 -> integer . V_35 = V_26 ;
V_21 -> V_24 = V_24 ;
F_16 ( V_8 ) ;
}
