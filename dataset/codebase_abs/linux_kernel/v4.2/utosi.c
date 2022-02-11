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
} else {
if ( V_11 -> V_12 & V_15 ) {
V_11 -> V_12 |= V_16 ;
} else {
V_11 -> V_12 &= ~ V_16 ;
}
}
V_11 = V_5 ;
}
F_5 ( V_3 ) ;
return ( V_9 ) ;
}
T_1 F_8 ( T_3 V_17 )
{
struct V_10 * V_18 ;
V_18 =
F_9 ( sizeof( struct V_10 ) ) ;
if ( ! V_18 ) {
return ( V_19 ) ;
}
V_18 -> V_14 = F_9 ( strlen ( V_17 ) + 1 ) ;
if ( ! V_18 -> V_14 ) {
F_7 ( V_18 ) ;
return ( V_19 ) ;
}
strcpy ( V_18 -> V_14 , V_17 ) ;
V_18 -> V_12 = V_13 ;
V_18 -> V_7 = V_5 ;
V_5 = V_18 ;
return ( V_9 ) ;
}
T_1 F_10 ( T_3 V_17 )
{
struct V_10 * V_20 ;
struct V_10 * V_11 ;
V_20 = V_11 = V_5 ;
while ( V_11 ) {
if ( ! strcmp ( V_17 , V_11 -> V_14 ) ) {
if ( V_11 -> V_12 & V_13 ) {
if ( V_20 == V_11 ) {
V_5 =
V_11 -> V_7 ;
} else {
V_20 -> V_7 =
V_11 -> V_7 ;
}
F_7 ( V_11 -> V_14 ) ;
F_7 ( V_11 ) ;
} else {
if ( V_11 -> V_12 & V_16 ) {
return ( V_21 ) ;
}
V_11 -> V_12 |= V_16 ;
}
return ( V_9 ) ;
}
V_20 = V_11 ;
V_11 = V_11 -> V_7 ;
}
return ( V_21 ) ;
}
T_1 F_11 ( T_4 V_22 )
{
struct V_10 * V_11 ;
V_11 = V_5 ;
while ( V_11 ) {
if ( ( ( V_11 -> V_12 & V_23 ) &&
( V_22 & V_24 ) ) ||
( ! ( V_11 -> V_12 & V_23 ) &&
( V_22 & V_25 ) ) ) {
if ( V_22 & V_26 ) {
V_11 -> V_12 |= V_16 ;
} else {
V_11 -> V_12 &= ~ V_16 ;
}
}
V_11 = V_11 -> V_7 ;
}
return ( V_9 ) ;
}
struct V_10 * F_12 ( T_3 V_17 )
{
struct V_10 * V_11 ;
V_11 = V_5 ;
while ( V_11 ) {
if ( ! strcmp ( V_17 , V_11 -> V_14 ) ) {
return ( V_11 ) ;
}
V_11 = V_11 -> V_7 ;
}
return ( NULL ) ;
}
T_1 F_13 ( struct V_27 * V_28 )
{
union V_29 * V_30 ;
union V_29 * V_31 ;
struct V_10 * V_18 ;
T_5 V_32 ;
T_1 V_1 ;
T_2 V_33 ;
F_14 ( V_34 ) ;
V_30 = V_28 -> V_35 [ 0 ] . V_36 ;
if ( ! V_30 || ( V_30 -> V_37 . type != V_38 ) ) {
F_15 ( V_39 ) ;
}
V_31 = F_16 ( V_40 ) ;
if ( ! V_31 ) {
F_15 ( V_19 ) ;
}
V_33 = 0 ;
V_1 = F_2 ( V_3 , V_4 ) ;
if ( F_3 ( V_1 ) ) {
F_17 ( V_31 ) ;
F_15 ( V_1 ) ;
}
V_18 = F_12 ( V_30 -> string . V_41 ) ;
if ( V_18 && ! ( V_18 -> V_12 & V_16 ) ) {
if ( V_18 -> V_42 > V_43 ) {
V_43 = V_18 -> V_42 ;
}
V_33 = V_44 ;
}
F_5 ( V_3 ) ;
V_32 = V_45 ;
if ( V_32 ) {
V_33 =
V_32 ( V_30 -> string . V_41 ,
V_33 ) ;
}
F_18 ( ( V_46 ,
L_1 ,
V_30 -> string . V_41 ,
V_33 == 0 ? L_2 : L_3 ) ) ;
V_31 -> integer . V_42 = V_33 ;
V_28 -> V_31 = V_31 ;
F_15 ( V_9 ) ;
}
