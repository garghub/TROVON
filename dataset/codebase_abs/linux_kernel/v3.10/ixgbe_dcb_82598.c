T_1 F_1 ( struct V_1 * V_2 ,
T_2 * V_3 ,
T_2 * V_4 ,
T_3 * V_5 )
{
T_4 V_6 = 0 ;
T_4 V_7 = 0 ;
T_4 V_8 = 0 ;
T_3 V_9 = 0 ;
V_6 = F_2 ( V_2 , V_10 ) | V_11 ;
F_3 ( V_2 , V_10 , V_6 ) ;
V_6 = F_2 ( V_2 , V_12 ) ;
V_6 &= ~ V_13 ;
V_6 |= V_14 ;
V_6 |= V_15 ;
F_3 ( V_2 , V_12 , V_6 ) ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
V_7 = V_3 [ V_9 ] ;
V_8 = V_4 [ V_9 ] ;
V_6 = V_7 | ( V_8 << V_17 ) ;
if ( V_5 [ V_9 ] == V_18 )
V_6 |= V_19 ;
F_3 ( V_2 , F_4 ( V_9 ) , V_6 ) ;
}
V_6 = F_2 ( V_2 , V_20 ) ;
V_6 |= V_21 ;
V_6 |= V_22 ;
V_6 |= V_23 ;
F_3 ( V_2 , V_20 , V_6 ) ;
V_6 = F_2 ( V_2 , V_24 ) ;
V_6 &= ~ V_25 ;
F_3 ( V_2 , V_24 , V_6 ) ;
return 0 ;
}
T_1 F_5 ( struct V_1 * V_2 ,
T_2 * V_3 ,
T_2 * V_4 ,
T_3 * V_26 ,
T_3 * V_5 )
{
T_4 V_6 , V_27 ;
T_3 V_9 ;
V_6 = F_2 ( V_2 , V_28 ) ;
V_6 &= ~ V_29 ;
V_6 |= ( V_30 | V_31 ) ;
V_6 |= V_32 ;
V_6 |= ( 0x4 << V_33 ) ;
F_3 ( V_2 , V_28 , V_6 ) ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
V_27 = V_4 [ V_9 ] ;
V_6 = V_27 << V_34 ;
V_6 |= V_3 [ V_9 ] ;
V_6 |= ( T_4 ) ( V_26 [ V_9 ] ) << V_35 ;
if ( V_5 [ V_9 ] == V_36 )
V_6 |= V_37 ;
if ( V_5 [ V_9 ] == V_18 )
V_6 |= V_38 ;
F_3 ( V_2 , F_6 ( V_9 ) , V_6 ) ;
}
return 0 ;
}
T_1 F_7 ( struct V_1 * V_2 ,
T_2 * V_3 ,
T_2 * V_4 ,
T_3 * V_26 ,
T_3 * V_5 )
{
T_4 V_6 ;
T_3 V_9 ;
V_6 = F_2 ( V_2 , V_39 ) ;
V_6 &= ~ V_40 ;
V_6 |= ( V_41 | V_42 ) ;
F_3 ( V_2 , V_39 , V_6 ) ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
V_6 = V_3 [ V_9 ] ;
V_6 |= ( T_4 ) ( V_4 [ V_9 ] ) << V_43 ;
V_6 |= ( T_4 ) ( V_26 [ V_9 ] ) << V_44 ;
if ( V_5 [ V_9 ] == V_36 )
V_6 |= V_45 ;
if ( V_5 [ V_9 ] == V_18 )
V_6 |= V_46 ;
F_3 ( V_2 , F_8 ( V_9 ) , V_6 ) ;
}
V_6 = F_2 ( V_2 , V_47 ) ;
V_6 |= V_48 ;
F_3 ( V_2 , V_47 , V_6 ) ;
return 0 ;
}
T_1 F_9 ( struct V_1 * V_2 , T_3 V_49 )
{
T_4 V_50 , V_6 ;
T_3 V_9 ;
V_6 = F_2 ( V_2 , V_12 ) ;
V_6 &= ~ V_51 ;
V_6 |= V_52 ;
F_3 ( V_2 , V_12 , V_6 ) ;
V_6 = F_2 ( V_2 , V_53 ) ;
V_6 &= ~ ( V_54 | V_55 ) ;
if ( V_49 )
V_6 |= V_54 ;
F_3 ( V_2 , V_53 , V_6 ) ;
V_50 = ( V_2 -> V_56 . V_57 << 10 ) | V_58 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
if ( ! ( V_49 & ( 1 << V_9 ) ) ) {
F_3 ( V_2 , F_10 ( V_9 ) , 0 ) ;
F_3 ( V_2 , F_11 ( V_9 ) , 0 ) ;
continue;
}
V_6 = ( V_2 -> V_56 . V_59 [ V_9 ] << 10 ) | V_60 ;
F_3 ( V_2 , F_10 ( V_9 ) , V_50 ) ;
F_3 ( V_2 , F_11 ( V_9 ) , V_6 ) ;
}
V_6 = V_2 -> V_56 . V_61 * 0x00010001 ;
for ( V_9 = 0 ; V_9 < ( V_16 / 2 ) ; V_9 ++ )
F_3 ( V_2 , F_12 ( V_9 ) , V_6 ) ;
F_3 ( V_2 , V_62 , V_2 -> V_56 . V_61 / 2 ) ;
return 0 ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
T_4 V_6 = 0 ;
T_3 V_9 = 0 ;
T_3 V_63 = 0 ;
for ( V_9 = 0 , V_63 = 0 ; V_9 < 15 && V_63 < 8 ; V_9 = V_9 + 2 , V_63 ++ ) {
V_6 = F_2 ( V_2 , F_14 ( V_9 ) ) ;
V_6 |= ( ( 0x1010101 ) * V_63 ) ;
F_3 ( V_2 , F_14 ( V_9 ) , V_6 ) ;
V_6 = F_2 ( V_2 , F_14 ( V_9 + 1 ) ) ;
V_6 |= ( ( 0x1010101 ) * V_63 ) ;
F_3 ( V_2 , F_14 ( V_9 + 1 ) , V_6 ) ;
}
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_6 = F_2 ( V_2 , F_15 ( V_9 ) ) ;
V_6 |= ( ( 0x1010101 ) * V_9 ) ;
F_3 ( V_2 , F_15 ( V_9 ) , V_6 ) ;
}
return 0 ;
}
T_1 F_16 ( struct V_1 * V_2 , T_3 V_49 , T_2 * V_3 ,
T_2 * V_4 , T_3 * V_26 , T_3 * V_5 )
{
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
F_5 ( V_2 , V_3 , V_4 ,
V_26 , V_5 ) ;
F_7 ( V_2 , V_3 , V_4 ,
V_26 , V_5 ) ;
F_9 ( V_2 , V_49 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
