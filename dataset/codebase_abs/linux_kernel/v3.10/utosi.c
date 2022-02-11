T_1 F_1 ( void )
{
T_1 V_1 ;
T_2 V_2 ;
V_1 = F_2 ( V_3 , V_4 ) ;
if ( F_3 ( V_1 ) ) {
return ( V_1 ) ;
}
V_5 = V_6 ;
for ( V_2 = 0 ;
V_2 < ( F_4 ( V_6 ) - 1 ) ;
V_2 ++ ) {
V_6 [ V_2 ] . V_7 =
& V_6 [ ( V_8 ) V_2 + 1 ] ;
}
F_5 ( V_3 ) ;
return ( V_9 ) ;
}
T_1 F_6 ( void )
{
T_1 V_1 ;
struct V_10 * V_11 ;
V_1 = F_2 ( V_3 , V_4 ) ;
if ( F_3 ( V_1 ) ) {
return ( V_1 ) ;
}
V_11 = V_5 ;
while ( V_11 ) {
V_5 = V_11 -> V_7 ;
if ( V_11 -> V_12 & V_13 ) {
F_7 ( V_11 -> V_14 ) ;
F_7 ( V_11 ) ;
}
V_11 = V_5 ;
}
F_5 ( V_3 ) ;
return ( V_9 ) ;
}
T_1 F_8 ( T_3 V_15 )
{
struct V_10 * V_16 ;
V_16 =
F_9 ( sizeof( struct V_10 ) ) ;
if ( ! V_16 ) {
return ( V_17 ) ;
}
V_16 -> V_14 =
F_9 ( F_10 ( V_15 ) + 1 ) ;
if ( ! V_16 -> V_14 ) {
F_7 ( V_16 ) ;
return ( V_17 ) ;
}
F_11 ( V_16 -> V_14 , V_15 ) ;
V_16 -> V_12 = V_13 ;
V_16 -> V_7 = V_5 ;
V_5 = V_16 ;
return ( V_9 ) ;
}
T_1 F_12 ( T_3 V_15 )
{
struct V_10 * V_18 ;
struct V_10 * V_11 ;
V_18 = V_11 = V_5 ;
while ( V_11 ) {
if ( ! F_13 ( V_15 , V_11 -> V_14 ) ) {
if ( V_11 -> V_12 & V_13 ) {
if ( V_18 == V_11 ) {
V_5 =
V_11 -> V_7 ;
} else {
V_18 -> V_7 =
V_11 -> V_7 ;
}
F_7 ( V_11 -> V_14 ) ;
F_7 ( V_11 ) ;
} else {
if ( V_11 -> V_12 & V_19 ) {
return ( V_20 ) ;
}
V_11 -> V_12 |= V_19 ;
}
return ( V_9 ) ;
}
V_18 = V_11 ;
V_11 = V_11 -> V_7 ;
}
return ( V_20 ) ;
}
struct V_10 * F_14 ( T_3 V_15 )
{
struct V_10 * V_11 ;
V_11 = V_5 ;
while ( V_11 ) {
if ( ! F_13 ( V_15 , V_11 -> V_14 ) ) {
return ( V_11 ) ;
}
V_11 = V_11 -> V_7 ;
}
return ( NULL ) ;
}
T_1 F_15 ( struct V_21 * V_22 )
{
union V_23 * V_24 ;
union V_23 * V_25 ;
struct V_10 * V_16 ;
T_4 V_26 ;
T_1 V_1 ;
T_2 V_27 ;
F_16 ( V_28 ) ;
V_24 = V_22 -> V_29 [ 0 ] . V_30 ;
if ( ! V_24 || ( V_24 -> V_31 . type != V_32 ) ) {
F_17 ( V_33 ) ;
}
V_25 = F_18 ( V_34 ) ;
if ( ! V_25 ) {
F_17 ( V_17 ) ;
}
V_27 = 0 ;
V_1 = F_2 ( V_3 , V_4 ) ;
if ( F_3 ( V_1 ) ) {
F_19 ( V_25 ) ;
F_17 ( V_1 ) ;
}
V_16 = F_14 ( V_24 -> string . V_35 ) ;
if ( V_16 && ! ( V_16 -> V_12 & V_19 ) ) {
if ( V_16 -> V_36 > V_37 ) {
V_37 = V_16 -> V_36 ;
}
V_27 = V_38 ;
}
F_5 ( V_3 ) ;
V_26 = V_39 ;
if ( V_26 ) {
V_27 =
V_26 ( V_24 -> string . V_35 ,
V_27 ) ;
}
F_20 ( ( V_40 ,
L_1 ,
V_24 -> string . V_35 ,
V_27 == 0 ? L_2 : L_3 ) ) ;
V_25 -> integer . V_36 = V_27 ;
V_22 -> V_25 = V_25 ;
F_17 ( V_9 ) ;
}
