static T_1 F_1 ( T_1 * V_1 , T_2 V_2 )
{
T_2 V_3 ;
T_1 V_4 = 0 ;
if ( ! V_1 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
V_4 += V_1 [ V_3 ] ;
return ( T_1 ) ( 0 - V_4 ) ;
}
static T_3 F_2 ( struct V_5 * V_6 )
{
T_2 V_7 ;
T_1 V_3 ;
if ( ! V_6 -> V_8 . V_9 ) {
F_3 ( L_1 ) ;
return - V_10 ;
}
V_7 = F_4 ( V_11 ) ;
if ( ( V_7 & V_12 ) == 0 ) {
F_3 ( L_2 ) ;
return - V_10 ;
}
for ( V_3 = 0 ; V_3 < V_13 ; V_3 ++ ) {
V_7 = F_4 ( V_11 ) ;
if ( ! ( V_7 & V_14 ) )
break;
F_5 ( 1 ) ;
}
if ( V_3 == V_13 ) {
F_3 ( L_3 ) ;
return - V_10 ;
}
return 0 ;
}
bool F_6 ( struct V_5 * V_6 )
{
T_2 V_15 = F_4 ( V_16 ) ;
return ( V_15 & V_17 ) ==
( V_18 << V_19 ) ;
}
bool F_7 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = & V_6 -> V_22 ;
T_2 * V_1 = ( T_2 * ) & V_6 -> V_22 ;
T_2 V_23 ;
T_3 V_24 , V_25 , V_26 ;
T_1 V_3 , V_27 ;
V_6 -> V_8 . V_28 = true ;
if ( ! V_6 -> V_8 . V_29 . V_30 ( V_6 ) ) {
V_6 -> V_8 . V_28 = false ;
return V_6 -> V_8 . V_28 ;
}
V_24 = F_2 ( V_6 ) ;
if ( V_24 ) {
V_6 -> V_8 . V_28 = false ;
return V_6 -> V_8 . V_28 ;
}
V_27 = V_31 >> 2 ;
V_23 = V_32 >> 2 ;
for ( V_3 = 0 ; V_3 < V_27 ; V_3 ++ )
* ( V_1 + V_3 ) = F_8 ( V_6 , V_33 ,
V_23 + V_3 ) ;
V_25 = V_21 -> V_34 ;
V_21 -> V_34 = 0 ;
V_26 = F_1 ( ( T_1 * ) V_21 ,
V_31 ) ;
if ( ( V_25 != V_26 ) || ( V_21 -> V_35 != V_36 ) ) {
V_6 -> V_8 . V_28 = true ;
return V_6 -> V_8 . V_28 ;
}
if ( ! ( V_21 -> V_37 & V_38 ) )
V_6 -> V_8 . V_28 = false ;
return V_6 -> V_8 . V_28 ;
}
static T_3 F_9 ( struct V_5 * V_6 ,
struct V_39 * V_21 )
{
T_4 V_3 , V_2 = sizeof( struct V_39 ) ;
V_21 -> V_34 = F_1 ( ( T_1 * ) V_21 , V_2 ) ;
V_2 >>= 2 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
F_10 ( V_6 , V_33 , V_3 , * ( ( T_2 * ) V_21 + V_3 ) ) ;
F_11 () ;
}
return 0 ;
}
static T_3 F_12 ( struct V_5 * V_6 , T_1 * V_1 ,
T_4 V_2 , T_4 V_23 , T_1 * V_4 )
{
T_1 * V_40 ;
T_1 * V_41 = V_1 ;
T_2 V_42 = 0 ;
T_4 V_43 , V_3 , V_44 , V_45 ;
if ( V_2 == 0 || V_23 + V_2 > V_46 )
return - V_47 ;
V_40 = ( T_1 * ) & V_42 ;
V_45 = V_23 & 0x3 ;
V_23 >>= 2 ;
if ( V_45 ) {
V_42 = F_8 ( V_6 , V_33 , V_23 ) ;
for ( V_44 = V_45 ; V_44 < sizeof( T_2 ) ; V_44 ++ ) {
* ( V_40 + V_44 ) = * V_41 ++ ;
* V_4 += * ( V_40 + V_44 ) ;
}
F_10 ( V_6 , V_33 , V_23 , V_42 ) ;
V_2 -= V_44 - V_45 ;
V_23 ++ ;
}
V_43 = V_2 & 0x3 ;
V_2 -= V_43 ;
V_2 >>= 2 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
for ( V_44 = 0 ; V_44 < sizeof( T_2 ) ; V_44 ++ ) {
* ( V_40 + V_44 ) = * V_41 ++ ;
* V_4 += * ( V_40 + V_44 ) ;
}
F_10 ( V_6 , V_33 , V_23 + V_3 , V_42 ) ;
}
if ( V_43 ) {
for ( V_44 = 0 ; V_44 < sizeof( T_2 ) ; V_44 ++ ) {
if ( V_44 < V_43 )
* ( V_40 + V_44 ) = * V_41 ++ ;
else
* ( V_40 + V_44 ) = 0 ;
* V_4 += * ( V_40 + V_44 ) ;
}
F_10 ( V_6 , V_33 , V_23 + V_3 , V_42 ) ;
}
return 0 ;
}
T_3 F_13 ( struct V_5 * V_6 , T_1 * V_1 , T_4 V_2 )
{
struct V_39 V_21 ;
T_3 V_24 ;
T_2 V_7 ;
V_21 . V_48 = V_49 ;
V_21 . V_50 = V_2 ;
V_21 . V_51 = 0 ;
V_21 . V_52 = 0 ;
V_21 . V_34 = 0 ;
V_24 = F_2 ( V_6 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_12 ( V_6 , V_1 , V_2 ,
sizeof( V_21 ) , & ( V_21 . V_34 ) ) ;
if ( V_24 )
return V_24 ;
V_24 = F_9 ( V_6 , & V_21 ) ;
if ( V_24 )
return V_24 ;
V_7 = F_4 ( V_11 ) ;
F_14 ( V_11 , V_7 | V_14 ) ;
return 0 ;
}
bool F_15 ( struct V_5 * V_6 )
{
T_2 V_53 ;
T_2 V_15 , V_54 ;
V_53 = F_4 ( V_55 ) ;
if ( ! ( V_53 & V_56 ) )
return false ;
if ( V_6 -> V_8 . V_57 ) {
V_15 = F_4 ( V_16 ) ;
V_54 = F_4 ( V_58 ) ;
if ( ! ( V_54 & V_59 ) &&
( ( V_15 & V_17 ) ==
( V_60 << V_19 ) ) )
return true ;
} else if ( ( V_6 -> V_8 . type == V_61 ) ||
( V_6 -> V_8 . type == V_62 ) ) {
T_4 V_42 ;
V_54 = F_4 ( V_58 ) ;
F_16 ( V_6 , V_63 , 1 , & V_42 ) ;
if ( ! ( V_54 & V_59 ) &&
( ( V_42 & V_64 ) ==
( V_60 << 13 ) ) )
return true ;
} else if ( ( V_53 & V_65 ) &&
! ( V_53 & V_66 ) ) {
return true ;
}
return false ;
}
