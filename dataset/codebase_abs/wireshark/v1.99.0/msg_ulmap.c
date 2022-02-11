void F_1 ( void )
{
V_1 = 0 ;
V_2 = 0 ;
V_3 = 0 ;
V_4 = 0 ;
V_5 = 0 ;
}
static T_1 F_2 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_13 ;
V_10 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_14 , NULL , L_1 ) ;
F_5 ( V_11 , 4 , L_2 ) ;
F_5 ( V_13 , 4 , L_3 ) ;
if ( ( V_13 & 1 ) == 1 ) {
F_5 ( V_11 , 2 , L_4 ) ;
F_5 ( V_11 , 2 , L_5 ) ;
}
return ( V_10 - V_7 ) ;
}
static T_1 F_6 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
V_10 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_15 , NULL , L_6 ) ;
F_5 ( V_11 , 2 , L_7 ) ;
F_5 ( V_4 , 2 , L_8 ) ;
return ( V_10 - V_7 ) ;
}
static T_1 F_7 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_16 ;
V_10 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_8 ( V_7 , V_8 ) , V_17 , NULL , L_9 ) ;
V_10 += F_9 ( V_12 , V_10 , V_8 , V_9 , V_5 ) ;
F_5 ( V_16 , 1 , L_10 ) ;
if ( V_16 == 1 ) {
V_10 += F_2 ( V_12 , V_10 , V_8 , V_9 ) ;
}
F_5 ( V_11 , 4 , L_11 ) ;
F_5 ( V_11 , 2 , L_12 ) ;
F_5 ( V_11 , 10 , L_13 ) ;
F_5 ( V_11 , 4 , L_14 ) ;
F_5 ( V_11 , 1 , L_15 ) ;
F_5 ( V_11 , 1 , L_16 ) ;
F_5 ( V_11 , 1 , L_17 ) ;
#if 0
if (include_cor2_changes)
{
data = TVB_BIT_BITS(bit, tvb, 16);
generic_item = proto_tree_add_text(tree, tvb, BITHI(bit,16), "CRC-16: 0x%04x",data);
calculated_crc = wimax_mac_calc_crc16((guint8 *)tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
if (data != calculated_crc)
{
proto_item_append_text(generic_item, " - incorrect! (should be: 0x%x)", calculated_crc);
}
bit += 16;
}
#endif
return ( V_10 - V_7 ) ;
}
static T_1 F_10 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_16 ;
V_10 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_18 , NULL , L_18 ) ;
V_10 += F_9 ( V_12 , V_10 , V_8 , V_9 , V_5 ) ;
F_5 ( V_16 , 1 , L_10 ) ;
if ( V_16 == 1 ) {
V_10 += F_2 ( V_12 , V_10 , V_8 , V_9 ) ;
}
F_5 ( V_11 , 4 , L_19 ) ;
F_5 ( V_11 , 4 , L_20 ) ;
F_5 ( V_11 , 2 , L_21 ) ;
F_5 ( V_11 , 4 , L_22 ) ;
F_5 ( V_11 , 1 , L_15 ) ;
F_5 ( V_11 , 1 , L_16 ) ;
F_5 ( V_11 , 3 , L_17 ) ;
#if 0
if (include_cor2_changes)
{
data = TVB_BIT_BITS(bit, tvb, 16);
generic_item = proto_tree_add_text(tree, tvb, BITHI(bit,16), "CRC-16: 0x%04x",data);
calculated_crc = wimax_mac_calc_crc16((guint8 *)tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
if (data != calculated_crc)
{
proto_item_append_text(generic_item, " - incorrect! (should be: 0x%x)", calculated_crc);
}
bit += 16;
}
#endif
return ( V_10 - V_7 ) ;
}
static T_1 F_11 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_16 ;
V_10 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_19 , NULL , L_23 ) ;
V_10 += F_9 ( V_12 , V_10 , V_8 , V_9 , V_5 ) ;
F_5 ( V_16 , 1 , L_10 ) ;
if ( V_16 == 1 ) {
V_10 += F_2 ( V_12 , V_10 , V_8 , V_9 ) ;
}
F_5 ( V_11 , 4 , L_11 ) ;
F_5 ( V_11 , 2 , L_12 ) ;
F_5 ( V_11 , 10 , L_13 ) ;
F_5 ( V_11 , 2 , L_21 ) ;
F_5 ( V_11 , 4 , L_14 ) ;
F_5 ( V_11 , 1 , L_15 ) ;
F_5 ( V_11 , 1 , L_16 ) ;
F_5 ( V_11 , 3 , L_17 ) ;
#if 0
if (include_cor2_changes)
{
data = TVB_BIT_BITS(bit, tvb, 16);
generic_item = proto_tree_add_text(tree, tvb, BITHI(bit,16), "CRC-16: 0x%04x",data);
calculated_crc = wimax_mac_calc_crc16((guint8 *)tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
if (data != calculated_crc)
{
proto_item_append_text(generic_item, " - incorrect! (should be: 0x%x)", calculated_crc);
}
bit += 16;
}
#endif
return ( V_10 - V_7 ) ;
}
static T_1 F_12 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_20 , V_21 , V_22 , V_23 ;
V_10 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_24 , NULL , L_24 ) ;
F_5 ( V_20 , 1 , L_25 ) ;
F_5 ( V_21 , 1 , L_26 ) ;
F_5 ( V_22 , 1 , L_27 ) ;
if ( V_20 == 0 ) {
V_10 += F_9 ( V_12 , V_10 , V_8 , V_9 , V_5 ) ;
if ( V_21 ) {
V_10 += F_6 ( V_12 , V_10 , V_8 , V_9 ) ;
}
} else {
F_5 ( V_11 , 1 , L_7 ) ;
}
F_5 ( V_11 , 10 , L_13 ) ;
for ( V_23 = 0 ; V_23 < V_4 ; V_23 ++ ) {
if ( V_20 == 1 ) {
V_10 += F_9 ( V_12 , V_10 , V_8 , V_9 , V_5 ) ;
}
F_5 ( V_11 , 4 , L_11 ) ;
F_5 ( V_11 , 2 , L_12 ) ;
if ( V_22 == 0 ) {
F_5 ( V_11 , 4 , L_14 ) ;
F_5 ( V_11 , 1 , L_15 ) ;
}
}
#if 0
if (include_cor2_changes)
{
data = TVB_BIT_BITS(bit, tvb, 16);
generic_item = proto_tree_add_text(tree, tvb, BITHI(bit,16), "CRC-16: 0x%04x",data);
calculated_crc = wimax_mac_calc_crc16((guint8 *)tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
if (data != calculated_crc)
{
proto_item_append_text(generic_item, " - incorrect! (should be: 0x%x)", calculated_crc);
}
bit += 16;
}
#endif
return ( V_10 - V_7 ) ;
}
static T_1 F_13 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_20 , V_21 , V_22 , V_23 ;
V_10 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_25 , NULL , L_28 ) ;
F_5 ( V_20 , 1 , L_25 ) ;
F_5 ( V_21 , 1 , L_29 ) ;
F_5 ( V_22 , 1 , L_27 ) ;
if ( V_20 == 0 ) {
V_10 += F_9 ( V_12 , V_10 , V_8 , V_9 , V_5 ) ;
if ( V_21 ) {
V_10 += F_6 ( V_12 , V_10 , V_8 , V_9 ) ;
}
} else {
F_5 ( V_11 , 1 , L_7 ) ;
}
F_5 ( V_11 , 4 , L_20 ) ;
for ( V_23 = 0 ; V_23 < V_4 ; V_23 ++ ) {
if ( V_20 == 1 ) {
V_10 += F_9 ( V_12 , V_10 , V_8 , V_9 , V_5 ) ;
}
F_5 ( V_11 , 4 , L_19 ) ;
if ( V_22 == 0 ) {
F_5 ( V_11 , 2 , L_21 ) ;
F_5 ( V_11 , 4 , L_14 ) ;
F_5 ( V_11 , 1 , L_15 ) ;
}
}
#if 0
if (include_cor2_changes)
{
data = TVB_BIT_BITS(bit, tvb, 16);
generic_item = proto_tree_add_text(tree, tvb, BITHI(bit,16), "CRC-16: 0x%04x",data);
calculated_crc = wimax_mac_calc_crc16((guint8 *)tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
if (data != calculated_crc)
{
proto_item_append_text(generic_item, " - incorrect! (should be: 0x%x)", calculated_crc);
}
bit += 16;
}
#endif
return ( V_10 - V_7 ) ;
}
static T_1 F_14 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_20 , V_21 , V_22 , V_23 ;
V_10 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_26 , NULL , L_30 ) ;
F_5 ( V_20 , 1 , L_25 ) ;
F_5 ( V_21 , 1 , L_29 ) ;
F_5 ( V_22 , 1 , L_27 ) ;
if ( V_20 == 0 ) {
V_10 += F_9 ( V_12 , V_10 , V_8 , V_9 , V_5 ) ;
if ( V_21 ) {
V_10 += F_6 ( V_12 , V_10 , V_8 , V_9 ) ;
}
} else {
F_5 ( V_11 , 1 , L_7 ) ;
}
F_5 ( V_11 , 10 , L_13 ) ;
for ( V_23 = 0 ; V_23 < V_4 ; V_23 ++ ) {
if ( V_20 == 1 ) {
V_10 += F_9 ( V_12 , V_10 , V_8 , V_9 , V_5 ) ;
}
F_5 ( V_11 , 4 , L_11 ) ;
F_5 ( V_11 , 2 , L_12 ) ;
if ( V_22 == 0 ) {
F_5 ( V_11 , 4 , L_14 ) ;
F_5 ( V_11 , 1 , L_15 ) ;
F_5 ( V_11 , 2 , L_21 ) ;
}
}
#if 0
if (include_cor2_changes)
{
data = TVB_BIT_BITS(bit, tvb, 16);
generic_item = proto_tree_add_text(tree, tvb, BITHI(bit,16), "CRC-16: 0x%04x",data);
calculated_crc = wimax_mac_calc_crc16((guint8 *)tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
if (data != calculated_crc)
{
proto_item_append_text(generic_item, " - incorrect! (should be: 0x%x)", calculated_crc);
}
bit += 16;
}
#endif
return ( V_10 - V_7 ) ;
}
static T_1 F_15 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_22 , V_27 , V_28 ;
V_10 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_29 , NULL , L_31 ) ;
F_5 ( V_27 , 2 , L_32 ) ;
F_5 ( V_11 , 10 , L_13 ) ;
F_5 ( V_28 , 1 , L_33 ) ;
if ( V_28 == 1 ) {
F_5 ( V_11 , 8 , L_34 ) ;
}
V_10 += F_9 ( V_12 , V_10 , V_8 , V_9 , V_5 ) ;
F_5 ( V_22 , 1 , L_27 ) ;
if ( V_27 == 0 ) {
F_5 ( V_11 , 4 , L_11 ) ;
F_5 ( V_11 , 2 , L_12 ) ;
}
if ( V_22 == 0 ) {
F_5 ( V_11 , 4 , L_14 ) ;
}
#if 0
if (include_cor2_changes)
{
data = TVB_BIT_BITS(bit, tvb, 16);
generic_item = proto_tree_add_text(tree, tvb, BITHI(bit,16), "CRC-16: 0x%04x",data);
calculated_crc = wimax_mac_calc_crc16((guint8 *)tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
if (data != calculated_crc)
{
proto_item_append_text(generic_item, " - incorrect! (should be: 0x%x)", calculated_crc);
}
bit += 16;
}
#endif
return ( V_10 - V_7 ) ;
}
static T_1 F_16 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_30 ;
T_1 V_11 ;
T_4 * V_12 ;
V_30 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_31 , NULL , L_35 ) ;
F_17 ( V_11 , 1 , L_36 ) ;
F_17 ( V_11 , 1 , L_2 ) ;
F_17 ( V_11 , 2 , L_37 ) ;
F_17 ( V_11 , 2 , L_38 ) ;
return V_30 ;
}
static T_1 F_18 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_32 , V_33 ;
const T_1 V_34 [ 4 ] = { 2 , 2 , 3 , 6 } ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_35 , NULL , L_39 ) ;
F_5 ( V_11 , 4 , L_40 ) ;
F_5 ( V_11 , 8 , L_2 ) ;
F_5 ( V_11 , 2 , L_41 ) ;
V_33 = V_34 [ V_11 ] ;
F_5 ( V_11 , 6 , L_13 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
V_11 = F_20 ( V_10 , V_9 , 16 ) ;
F_21 ( V_12 , V_9 , F_8 ( V_10 , 16 ) , L_42 , V_32 , V_11 ) ;
V_10 += 16 ;
V_11 = F_20 ( V_10 , V_9 , 4 ) ;
F_21 ( V_12 , V_9 , F_8 ( V_10 , 4 ) , L_43 , V_32 , V_11 ) ;
V_10 += 4 ;
V_11 = F_20 ( V_10 , V_9 , 2 ) ;
F_21 ( V_12 , V_9 , F_8 ( V_10 , 2 ) , L_44 , V_32 , V_11 ) ;
V_10 += 2 ;
}
if ( V_33 == 3 ) {
F_5 ( V_11 , 4 , L_45 ) ;
}
return F_22 ( V_10 ) ;
}
static T_1 F_23 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_36 , NULL , L_46 ) ;
F_5 ( V_11 , 4 , L_36 ) ;
F_5 ( V_11 , 4 , L_2 ) ;
F_5 ( V_11 , 2 , L_47 ) ;
F_5 ( V_11 , 7 , L_48 ) ;
F_5 ( V_11 , 8 , L_49 ) ;
F_5 ( V_11 , 8 , L_50 ) ;
F_5 ( V_11 , 2 , L_51 ) ;
F_5 ( V_11 , 1 , L_52 ) ;
F_5 ( V_11 , 4 , L_17 ) ;
return F_22 ( V_10 ) ;
}
static T_1 F_24 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_1 V_37 ;
T_4 * V_12 ;
T_1 V_38 , V_39 , V_40 , V_41 , V_42 , V_43 , V_44 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_45 , NULL , L_53 ) ;
F_5 ( V_11 , 4 , L_36 ) ;
F_5 ( V_11 , 4 , L_2 ) ;
V_37 = V_10 + F_25 ( V_11 ) ;
if ( V_1 == 0 ) {
F_21 ( V_12 , V_9 , F_8 ( V_10 , 1 ) , L_54 ) ;
} else {
V_11 = F_26 ( V_10 , V_9 , V_1 ) ;
F_21 ( V_12 , V_9 , F_8 ( V_10 , V_1 ) , L_55 , V_11 , V_1 ) ;
V_10 += V_1 ;
}
F_5 ( V_11 , 6 , L_56 ) ;
F_5 ( V_11 , 2 , L_57 ) ;
F_5 ( V_11 , 3 , L_58 ) ;
F_5 ( V_11 , 3 , L_59 ) ;
F_5 ( V_38 , 1 , L_60 ) ;
if ( V_38 )
{
F_5 ( V_40 , 2 , L_61 ) ;
F_5 ( V_39 , 1 , L_62 ) ;
if ( V_39 == 0 ) {
F_5 ( V_11 , 1 , L_63 ) ;
}
else {
F_5 ( V_41 , 3 , L_64 ) ;
F_5 ( V_11 , 2 , L_65 ) ;
F_5 ( V_11 , 2 , L_66 ) ;
if ( V_41 == 0 || V_41 == 1 ) {
F_5 ( V_42 , 1 , L_67 ) ;
if ( V_42 == 1 ) {
F_5 ( V_11 , 6 , L_68 ) ;
}
}
F_5 ( V_11 , 1 , L_69 ) ;
}
if ( V_40 == 0 ) {
F_5 ( V_43 , 1 , L_70 ) ;
if ( V_43 == 1 ) {
F_5 ( V_11 , 4 , L_71 ) ;
}
}
}
F_5 ( V_11 , 2 , L_72 ) ;
V_44 = V_37 - V_10 ;
if ( V_44 ) {
F_21 ( V_12 , V_9 , F_8 ( V_10 , V_44 ) , L_73 , V_44 ) ;
V_10 += V_44 ;
}
return F_22 ( V_10 ) ;
}
static T_1 F_27 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_46 , NULL , L_74 ) ;
F_5 ( V_11 , 4 , L_36 ) ;
F_5 ( V_11 , 4 , L_2 ) ;
F_5 ( V_11 , 7 , L_49 ) ;
F_5 ( V_11 , 2 , L_47 ) ;
F_5 ( V_11 , 7 , L_48 ) ;
F_5 ( V_11 , 2 , L_75 ) ;
F_5 ( V_11 , 1 , L_76 ) ;
F_5 ( V_11 , 1 , L_77 ) ;
F_5 ( V_11 , 4 , L_17 ) ;
return F_22 ( V_10 ) ;
}
static T_1 F_28 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_47 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_48 , NULL , L_78 ) ;
F_5 ( V_11 , 4 , L_36 ) ;
F_5 ( V_11 , 4 , L_2 ) ;
F_5 ( V_47 , 1 , L_79 ) ;
if ( V_47 == 0 ) {
F_5 ( V_11 , 4 , L_80 ) ;
} else {
F_5 ( V_11 , 4 , L_81 ) ;
}
F_5 ( V_11 , 1 , L_82 ) ;
F_5 ( V_11 , 2 , L_83 ) ;
return F_22 ( V_10 ) ;
}
static T_1 F_29 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_30 ;
T_1 V_11 ;
T_4 * V_12 ;
V_30 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_49 , NULL , L_84 ) ;
F_17 ( V_11 , 1 , L_36 ) ;
F_17 ( V_11 , 1 , L_2 ) ;
F_21 ( V_12 , V_9 , F_4 ( V_30 , V_8 - 2 ) , L_85 ) ;
return V_30 ;
}
static T_1 F_30 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_50 , NULL , L_86 ) ;
V_8 = F_19 ( V_8 ) ;
F_5 ( V_11 , 4 , L_36 ) ;
F_5 ( V_11 , 4 , L_2 ) ;
F_5 ( V_11 , 2 , L_87 ) ;
F_5 ( V_11 , 6 , L_17 ) ;
while ( V_10 < ( V_8 - 7 ) ) {
F_5 ( V_11 , 3 , L_88 ) ;
F_5 ( V_11 , 3 , L_89 ) ;
F_5 ( V_11 , 2 , L_90 ) ;
}
return F_22 ( V_10 ) ;
}
static T_1 F_31 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_51 , NULL , L_91 ) ;
F_5 ( V_11 , 4 , L_36 ) ;
F_5 ( V_11 , 4 , L_2 ) ;
F_5 ( V_11 , 4 , L_11 ) ;
F_5 ( V_11 , 2 , L_92 ) ;
F_5 ( V_11 , 7 , L_48 ) ;
F_5 ( V_11 , 8 , L_49 ) ;
F_5 ( V_11 , 6 , L_93 ) ;
F_5 ( V_11 , 10 , L_13 ) ;
F_5 ( V_11 , 2 , L_94 ) ;
F_5 ( V_11 , 1 , L_17 ) ;
return F_22 ( V_10 ) ;
}
static T_1 F_32 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_52 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_53 , NULL , L_95 ) ;
F_5 ( V_11 , 4 , L_36 ) ;
F_5 ( V_11 , 4 , L_2 ) ;
F_5 ( V_52 , 1 , L_96 ) ;
F_5 ( V_11 , 7 , L_17 ) ;
if ( V_52 == 1 ) {
F_5 ( V_11 , 8 , L_97 ) ;
} else {
F_21 ( V_12 , V_9 , F_8 ( V_10 , 48 ) , L_98 ) ;
V_10 += 48 ;
}
F_5 ( V_11 , 4 , L_11 ) ;
F_5 ( V_11 , 10 , L_13 ) ;
F_5 ( V_11 , 2 , L_94 ) ;
return F_22 ( V_10 ) ;
}
static T_1 F_33 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_54 , NULL , L_99 ) ;
F_5 ( V_11 , 4 , L_36 ) ;
F_5 ( V_11 , 4 , L_2 ) ;
F_5 ( V_11 , 8 , L_49 ) ;
F_5 ( V_11 , 7 , L_93 ) ;
F_5 ( V_11 , 1 , L_17 ) ;
return F_22 ( V_10 ) ;
}
static T_1 F_34 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_23 , V_55 , V_56 ;
T_5 V_44 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_57 , NULL , L_100 ) ;
F_5 ( V_11 , 4 , L_40 ) ;
F_5 ( V_11 , 8 , L_2 ) ;
if ( V_1 == 0 ) {
F_21 ( V_12 , V_9 , F_8 ( V_10 , 1 ) , L_54 ) ;
} else {
V_11 = F_26 ( V_10 , V_9 , V_1 ) ;
F_21 ( V_12 , V_9 , F_8 ( V_10 , V_1 ) , L_55 , V_11 , V_1 ) ;
V_10 += V_1 ;
}
F_5 ( V_11 , 3 , L_57 ) ;
F_5 ( V_11 , 3 , L_58 ) ;
F_5 ( V_11 , 3 , L_59 ) ;
F_5 ( V_55 , 4 , L_101 ) ;
V_55 += 1 ;
for ( V_23 = 0 ; V_23 < V_55 ; V_23 ++ ) {
F_5 ( V_11 , 3 , L_61 ) ;
F_5 ( V_11 , 6 , L_102 ) ;
F_5 ( V_11 , 3 , L_103 ) ;
F_5 ( V_11 , 1 , L_104 ) ;
}
F_5 ( V_56 , 1 , L_105 ) ;
if ( V_56 == 1 ) {
F_5 ( V_11 , 3 , L_106 ) ;
}
V_44 = F_35 ( V_10 , 8 ) ;
if ( V_44 ) {
F_21 ( V_12 , V_9 , F_8 ( V_10 , V_44 ) , L_73 , V_44 ) ;
V_10 += V_44 ;
}
return F_22 ( V_10 ) ;
}
static T_1 F_36 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_30 ;
T_1 V_11 ;
T_4 * V_12 ;
V_30 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_58 , NULL , L_107 ) ;
F_17 ( V_11 , 1 , L_40 ) ;
F_17 ( V_11 , 2 , L_2 ) ;
F_21 ( V_12 , V_9 , F_4 ( V_30 , V_8 - 3 ) , L_85 ) ;
return V_30 ;
}
static T_1 F_37 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_30 ;
T_1 V_11 ;
T_4 * V_12 ;
V_30 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_59 , NULL , L_108 ) ;
F_17 ( V_11 , 1 , L_40 ) ;
F_17 ( V_11 , 2 , L_2 ) ;
F_21 ( V_12 , V_9 , F_4 ( V_30 , V_8 - 3 ) , L_85 ) ;
return V_30 ;
}
static T_1 F_38 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_60 , V_61 , V_62 , V_44 ;
T_1 V_23 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_63 , NULL , L_109 ) ;
F_5 ( V_11 , 4 , L_40 ) ;
F_5 ( V_11 , 8 , L_2 ) ;
F_5 ( V_60 , 4 , L_110 ) ;
for ( V_23 = 0 ; V_23 < V_60 ; V_23 ++ ) {
F_5 ( V_11 , 12 , L_111 ) ;
F_5 ( V_61 , 2 , L_112 ) ;
if ( V_61 == 1 ) {
F_5 ( V_11 , 3 , L_113 ) ;
F_5 ( V_11 , 3 , L_114 ) ;
F_5 ( V_11 , 2 , L_17 ) ;
}
if ( V_61 == 0 || V_61 == 1 ) {
F_5 ( V_11 , 1 , L_115 ) ;
F_5 ( V_62 , 1 , L_116 ) ;
if ( V_62 == 1 ) {
if ( V_1 == 0 ) {
F_21 ( V_12 , V_9 , F_8 ( V_10 , 1 ) , L_54 ) ;
} else {
V_11 = F_26 ( V_10 , V_9 , V_1 ) ;
F_21 ( V_12 , V_9 , F_8 ( V_10 , V_1 ) ,
L_55 , V_11 , V_1 ) ;
V_10 += V_1 ;
}
F_5 ( V_11 , 6 , L_117 ) ;
F_5 ( V_11 , 2 , L_118 ) ;
F_5 ( V_11 , 3 , L_58 ) ;
F_5 ( V_11 , 3 , L_119 ) ;
F_5 ( V_11 , 2 , L_120 ) ;
V_44 = F_35 ( V_10 , 8 ) ;
if ( V_44 ) {
F_21 ( V_12 , V_9 , F_8 ( V_10 , V_44 ) , L_121 , V_44 ) ;
}
}
} else {
F_5 ( V_11 , 2 , L_17 ) ;
}
}
F_5 ( V_11 , 4 , L_17 ) ;
return F_22 ( V_10 ) ;
}
static T_1 F_39 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_64 , V_65 , V_66 , V_67 , V_44 , V_68 , V_69 , V_70 , V_71 ;
T_1 V_23 , V_32 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_72 , NULL , L_122 ) ;
F_5 ( V_11 , 4 , L_40 ) ;
F_5 ( V_11 , 8 , L_2 ) ;
F_5 ( V_64 , 1 , L_123 ) ;
F_5 ( V_65 , 1 , L_124 ) ;
F_5 ( V_66 , 1 , L_125 ) ;
if ( V_66 == 0 ) {
F_5 ( V_11 , 1 , L_126 ) ;
F_5 ( V_11 , 2 , L_17 ) ;
} else {
F_5 ( V_11 , 3 , L_17 ) ;
}
F_5 ( V_67 , 2 , L_127 ) ;
if ( V_64 == 0 ) {
F_5 ( V_69 , 3 , L_128 ) ;
F_5 ( V_11 , 1 , L_17 ) ;
for ( V_23 = 0 ; V_23 < V_69 ; V_23 ++ ) {
F_5 ( V_68 , 1 , L_129 ) ;
if ( V_68 == 0 ) {
F_5 ( V_11 , 3 , L_130 ) ;
F_5 ( V_11 , 1 , L_17 ) ;
} else {
F_5 ( V_11 , 3 , L_131 ) ;
F_5 ( V_11 , 1 , L_132 ) ;
}
F_5 ( V_11 , 3 , L_133 ) ;
F_5 ( V_70 , 7 , L_134 ) ;
F_5 ( V_11 , 1 , L_17 ) ;
for ( V_32 = 0 ; V_32 < V_70 ; V_32 ++ ) {
F_5 ( V_11 , 12 , L_135 ) ;
F_5 ( V_11 , 2 , L_136 ) ;
F_5 ( V_11 , 1 , L_137 ) ;
F_5 ( V_11 , 1 , L_138 ) ;
F_5 ( V_71 , 1 , L_139 ) ;
if ( V_71 == 1 ) {
F_5 ( V_11 , 12 , L_140 ) ;
F_5 ( V_11 , 2 , L_17 ) ;
} else {
F_5 ( V_11 , 7 , L_141 ) ;
F_5 ( V_11 , 7 , L_142 ) ;
}
if ( V_66 == 1 ) {
F_5 ( V_11 , 1 , L_126 ) ;
} else {
F_5 ( V_11 , 1 , L_17 ) ;
}
if ( V_68 == 0 ) {
F_5 ( V_11 , 5 , L_143 ) ;
} else {
F_5 ( V_11 , 6 , L_144 ) ;
if ( V_67 == 1 ) {
F_5 ( V_11 , 1 , L_145 ) ;
F_5 ( V_11 , 2 , L_17 ) ;
} else {
F_5 ( V_11 , 3 , L_17 ) ;
}
}
F_5 ( V_11 , 3 , L_146 ) ;
}
}
} else {
F_5 ( V_11 , 3 , L_47 ) ;
F_5 ( V_11 , 6 , L_147 ) ;
F_5 ( V_69 , 3 , L_148 ) ;
for ( V_23 = 0 ; V_23 < V_69 ; V_23 ++ ) {
F_5 ( V_70 , 7 , L_134 ) ;
F_5 ( V_11 , 1 , L_17 ) ;
for ( V_32 = 0 ; V_32 < V_70 ; V_32 ++ ) {
F_5 ( V_11 , 12 , L_149 ) ;
if ( V_66 ) {
F_5 ( V_11 , 1 , L_126 ) ;
F_5 ( V_11 , 3 , L_17 ) ;
}
F_5 ( V_11 , 7 , L_93 ) ;
F_5 ( V_11 , 1 , L_137 ) ;
F_5 ( V_11 , 3 , L_150 ) ;
F_5 ( V_11 , 3 , L_146 ) ;
F_5 ( V_11 , 2 , L_151 ) ;
}
}
}
V_44 = F_35 ( V_10 , 8 ) ;
if ( V_44 ) {
F_21 ( V_12 , V_9 , F_8 ( V_10 , V_44 ) , L_73 , V_44 ) ;
V_10 += V_44 ;
}
return F_22 ( V_10 ) ;
}
static T_1 F_40 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_30 ;
T_1 V_11 ;
T_4 * V_12 ;
V_30 = V_7 ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_73 , NULL , L_152 ) ;
F_17 ( V_11 , 1 , L_40 ) ;
F_17 ( V_11 , 2 , L_2 ) ;
F_21 ( V_12 , V_9 , F_4 ( V_30 , V_8 - 3 ) , L_85 ) ;
return V_30 ;
}
static T_1 F_41 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_74 ;
T_1 V_75 ;
T_1 V_44 , V_76 , V_77 , V_78 ;
T_1 V_23 ;
V_10 = F_19 ( V_7 ) ;
V_74 = F_19 ( V_8 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_79 , NULL , L_153 ) ;
F_5 ( V_11 , 4 , L_40 ) ;
F_5 ( V_11 , 8 , L_2 ) ;
F_5 ( V_5 , 2 , L_154 ) ;
F_5 ( V_11 , 2 , L_17 ) ;
V_75 = V_10 + V_74 - 16 - 4 ;
while ( V_10 < V_75 ) {
F_5 ( V_76 , 3 , L_155 ) ;
F_5 ( V_77 , 1 , L_156 ) ;
if ( V_77 == 1 ) {
F_5 ( V_11 , 8 , L_157 ) ;
F_5 ( V_11 , 7 , L_93 ) ;
F_5 ( V_11 , 1 , L_17 ) ;
}
F_5 ( V_78 , 4 , L_158 ) ;
V_78 ++ ;
for ( V_23 = 0 ; V_23 < V_78 ; V_23 ++ ) {
if ( V_76 == 0 ) {
V_10 += F_7 ( V_12 , V_10 , V_74 , V_9 ) ;
} else if ( V_76 == 1 ) {
V_10 += F_10 ( V_12 , V_10 , V_74 , V_9 ) ;
} else if ( V_76 == 2 ) {
V_10 += F_11 ( V_12 , V_10 , V_74 , V_9 ) ;
} else if ( V_76 == 3 ) {
V_10 += F_12 ( V_12 , V_10 , V_74 , V_9 ) ;
} else if ( V_76 == 4 ) {
V_10 += F_13 ( V_12 , V_10 , V_74 , V_9 ) ;
} else if ( V_76 == 5 ) {
V_10 += F_14 ( V_12 , V_10 , V_74 , V_9 ) ;
} else if ( V_76 == 6 ) {
V_10 += F_15 ( V_12 , V_10 , V_74 , V_9 ) ;
}
}
}
V_44 = F_19 ( V_7 ) + V_74 - V_10 ;
if ( V_44 ) {
F_21 ( V_12 , V_9 , F_8 ( V_10 , V_44 ) , L_73 , V_44 ) ;
V_10 += V_44 ;
}
return F_22 ( V_10 ) ;
}
static T_1 F_42 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_80 , NULL , L_159 ) ;
F_5 ( V_11 , 4 , L_40 ) ;
F_5 ( V_11 , 8 , L_2 ) ;
F_5 ( V_11 , 8 , L_160 ) ;
F_5 ( V_11 , 7 , L_161 ) ;
F_5 ( V_11 , 5 , L_162 ) ;
F_5 ( V_11 , 4 , L_163 ) ;
return F_22 ( V_10 ) ;
}
static T_1 F_43 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_81 , V_44 , V_82 , V_83 , V_84 , V_85 ;
T_1 V_86 = 0 ;
T_1 V_87 , V_88 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_89 , NULL , L_164 ) ;
F_5 ( V_11 , 4 , L_40 ) ;
F_5 ( V_11 , 8 , L_2 ) ;
F_5 ( V_5 , 2 , L_154 ) ;
F_5 ( V_81 , 4 , L_165 ) ;
F_5 ( V_11 , 2 , L_17 ) ;
for ( V_87 = 0 ; V_87 < V_81 ; V_87 ++ ) {
F_5 ( V_11 , 12 , L_166 ) ;
F_5 ( V_11 , 10 , L_167 ) ;
F_5 ( V_82 , 3 , L_168 ) ;
F_5 ( V_11 , 3 , L_17 ) ;
for ( V_88 = 0 ; V_88 < V_82 ; V_88 ++ ) {
V_10 += F_9 ( V_12 , V_10 , V_8 , V_9 , V_5 ) ;
F_5 ( V_83 , 2 , L_169 ) ;
F_5 ( V_85 , 1 , L_170 ) ;
F_5 ( V_84 , 1 , L_82 ) ;
if ( V_86 ) {
F_5 ( V_11 , 4 , L_171 ) ;
}
if ( V_84 ) {
F_5 ( V_11 , 2 , L_5 ) ;
F_5 ( V_11 , 2 , L_17 ) ;
}
if ( V_83 == 0 ) {
F_5 ( V_11 , 4 , L_172 ) ;
F_5 ( V_11 , 2 , L_12 ) ;
F_5 ( V_11 , 2 , L_17 ) ;
}
if ( V_83 == 1 ) {
F_5 ( V_11 , 4 , L_172 ) ;
F_5 ( V_11 , 2 , L_12 ) ;
F_5 ( V_11 , 4 , L_14 ) ;
F_5 ( V_11 , 1 , L_15 ) ;
F_5 ( V_11 , 1 , L_17 ) ;
}
if ( V_83 == 2 ) {
F_5 ( V_11 , 4 , L_19 ) ;
F_5 ( V_11 , 4 , L_20 ) ;
F_5 ( V_11 , 2 , L_21 ) ;
F_5 ( V_11 , 4 , L_14 ) ;
F_5 ( V_11 , 1 , L_15 ) ;
F_5 ( V_11 , 1 , L_17 ) ;
}
if ( V_83 == 3 ) {
F_5 ( V_11 , 4 , L_172 ) ;
F_5 ( V_11 , 2 , L_12 ) ;
F_5 ( V_11 , 2 , L_21 ) ;
F_5 ( V_11 , 4 , L_14 ) ;
F_5 ( V_11 , 1 , L_15 ) ;
F_5 ( V_11 , 3 , L_17 ) ;
}
if ( V_85 ) {
F_5 ( V_11 , 8 , L_173 ) ;
}
}
}
V_44 = F_35 ( V_10 , 8 ) ;
if ( V_44 ) {
F_21 ( V_12 , V_9 , F_8 ( V_10 , V_44 ) , L_73 , V_44 ) ;
V_10 += V_44 ;
}
return F_22 ( V_10 ) ;
}
static T_1 F_44 ( T_2 * V_6 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
T_1 V_90 , V_91 , V_44 , V_92 ;
T_1 V_23 ;
V_10 = F_19 ( V_7 ) ;
V_12 = F_3 ( V_6 , V_9 , F_4 ( V_7 , V_8 ) , V_93 , NULL , L_174 ) ;
F_5 ( V_11 , 4 , L_40 ) ;
F_5 ( V_11 , 8 , L_2 ) ;
F_5 ( V_90 , 4 , L_175 ) ;
F_5 ( V_91 , 1 , L_176 ) ;
F_5 ( V_11 , 3 , L_17 ) ;
for ( V_23 = 0 ; V_23 < V_90 ; V_23 ++ ) {
F_5 ( V_11 , 16 , L_177 ) ;
F_5 ( V_92 , 3 , L_178 ) ;
if ( V_92 != 0 ) {
F_5 ( V_11 , 4 , L_179 ) ;
F_5 ( V_11 , 3 , L_180 ) ;
F_5 ( V_11 , 2 , L_57 ) ;
if ( V_91 == 1 ) {
F_5 ( V_11 , 4 , L_11 ) ;
F_5 ( V_11 , 8 , L_160 ) ;
F_5 ( V_11 , 7 , L_93 ) ;
F_5 ( V_11 , 3 , L_13 ) ;
F_5 ( V_11 , 2 , L_94 ) ;
}
}
}
V_44 = F_35 ( V_10 , 8 ) ;
if ( V_44 ) {
F_21 ( V_12 , V_9 , F_8 ( V_10 , V_44 ) , L_73 , V_44 ) ;
V_10 += V_44 ;
}
return F_22 ( V_10 ) ;
}
T_1 F_45 ( T_2 * V_94 , T_1 V_7 , T_1 V_8 V_95 , T_3 * V_9 )
{
T_4 * V_96 ;
T_2 * V_12 ;
T_1 V_97 ;
T_1 V_98 , V_99 , V_100 , V_101 , V_102 ;
T_5 V_103 ;
T_5 V_11 ;
T_6 V_104 ;
V_97 = V_7 ;
V_103 = F_46 ( V_97 , V_9 ) ;
V_98 = F_47 ( V_97 + 4 , V_9 ) ;
if ( V_98 == 0 )
{
V_12 = F_3 ( V_94 , V_9 , F_4 ( V_97 , 5 + 8 ) , V_105 , NULL , L_181 ) ;
F_48 ( V_12 , V_106 , V_9 , F_4 ( V_97 , 4 ) , V_103 ) ;
V_97 += 4 ;
F_48 ( V_12 , V_107 , V_9 , F_4 ( V_97 , 1 ) , V_98 ) ;
V_97 += 1 ;
V_11 = F_49 ( V_97 , V_9 ) ;
F_48 ( V_12 , V_108 , V_9 , F_4 ( V_97 , 8 ) , V_11 ) ;
F_48 ( V_12 , V_109 , V_9 , F_4 ( V_97 , 8 ) , V_11 ) ;
F_48 ( V_12 , V_110 , V_9 , F_4 ( V_97 , 8 ) , V_11 ) ;
F_48 ( V_12 , V_111 , V_9 , F_4 ( V_97 , 8 ) , V_11 ) ;
F_48 ( V_12 , V_112 , V_9 , F_4 ( V_97 , 8 ) , V_11 ) ;
V_97 += 8 ;
}
else if ( V_98 == 11 )
{
V_100 = F_47 ( 5 + V_97 , V_9 ) ;
V_101 = F_50 ( 5 + V_97 + 1 , V_9 ) ;
V_12 = F_51 ( V_94 , V_9 , F_4 ( V_97 , 5 + 3 + V_101 * 2 ) , V_113 , NULL , L_182 , V_98 ) ;
F_48 ( V_12 , V_106 , V_9 , F_4 ( V_97 , 4 ) , V_103 ) ;
V_97 += 4 ;
F_48 ( V_12 , V_107 , V_9 , F_4 ( V_97 , 1 ) , V_98 ) ;
V_97 += 1 ;
#if 0
proto_tree_add_uint(tree, hf_ulmap_uiuc11_ext, tvb, NIBHI(nibble, 1), ext2_uiuc);
nibble += 1;
proto_tree_add_uint(tree, hf_ulmap_uiuc11_len, tvb, NIBHI(nibble, 2), len);
nibble += 2;
#endif
V_101 = 3 + F_52 ( V_101 ) ;
switch ( V_100 ) {
case 0x00 :
V_97 = F_34 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x01 :
V_97 = F_36 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x02 :
V_97 = F_37 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x03 :
V_97 = F_38 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x04 :
V_97 = F_39 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x06 :
V_97 = F_40 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x07 :
V_97 = F_41 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x08 :
V_97 = F_42 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x0e :
V_97 = F_43 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x0f :
V_97 = F_44 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
default:
F_21 ( V_12 , V_9 , F_4 ( V_97 , V_101 ) , L_183 , V_100 ) ;
V_97 += V_101 ;
break;
}
}
else if ( V_98 == 12 )
{
V_12 = F_3 ( V_94 , V_9 , F_4 ( V_97 , 5 + 8 ) , V_114 , NULL , L_184 ) ;
F_48 ( V_12 , V_106 , V_9 , F_4 ( V_97 , 4 ) , V_103 ) ;
V_97 += 4 ;
F_48 ( V_12 , V_107 , V_9 , F_4 ( V_97 , 1 ) , V_98 ) ;
V_97 += 1 ;
V_104 = F_49 ( V_97 , V_9 ) ;
F_48 ( V_12 , V_115 , V_9 , F_4 ( V_97 , 8 ) , V_104 ) ;
F_48 ( V_12 , V_116 , V_9 , F_4 ( V_97 , 8 ) , V_104 ) ;
F_48 ( V_12 , V_117 , V_9 , F_4 ( V_97 , 8 ) , V_104 ) ;
F_48 ( V_12 , V_118 , V_9 , F_4 ( V_97 , 8 ) , V_104 ) ;
F_48 ( V_12 , V_119 , V_9 , F_4 ( V_97 , 8 ) , V_104 ) ;
F_48 ( V_12 , V_120 , V_9 , F_4 ( V_97 , 8 ) , V_104 ) ;
V_97 += 8 ;
}
else if ( V_98 == 13 )
{
V_12 = F_3 ( V_94 , V_9 , F_4 ( V_97 , 5 + 8 ) , V_121 , NULL , L_185 ) ;
F_48 ( V_12 , V_106 , V_9 , F_4 ( V_97 , 4 ) , V_103 ) ;
V_97 += 4 ;
F_48 ( V_12 , V_107 , V_9 , F_4 ( V_97 , 1 ) , V_98 ) ;
V_97 += 1 ;
V_11 = F_49 ( V_97 , V_9 ) ;
F_48 ( V_12 , V_122 , V_9 , F_4 ( V_97 , 8 ) , V_11 ) ;
F_48 ( V_12 , V_123 , V_9 , F_4 ( V_97 , 8 ) , V_11 ) ;
F_48 ( V_12 , V_124 , V_9 , F_4 ( V_97 , 8 ) , V_11 ) ;
F_48 ( V_12 , V_125 , V_9 , F_4 ( V_97 , 8 ) , V_11 ) ;
F_48 ( V_12 , V_126 , V_9 , F_4 ( V_97 , 8 ) , V_11 ) ;
F_48 ( V_12 , V_127 , V_9 , F_4 ( V_97 , 8 ) , V_11 ) ;
F_48 ( V_12 , V_128 , V_9 , F_4 ( V_97 , 8 ) , V_11 ) ;
V_97 += 8 ;
}
else if ( V_98 == 14 )
{
V_12 = F_3 ( V_94 , V_9 , F_4 ( V_97 , 5 + 10 ) , V_129 , & V_96 , L_186 ) ;
F_48 ( V_12 , V_106 , V_9 , F_4 ( V_97 , 4 ) , V_103 ) ;
V_97 += 4 ;
F_48 ( V_12 , V_107 , V_9 , F_4 ( V_97 , 1 ) , V_98 ) ;
V_97 += 1 ;
V_11 = F_46 ( V_97 , V_9 ) ;
F_48 ( V_12 , V_130 , V_9 , F_4 ( V_97 , 2 ) , V_11 ) ;
F_48 ( V_12 , V_131 , V_9 , F_4 ( V_97 + 1 , 2 ) , V_11 ) ;
F_48 ( V_12 , V_132 , V_9 , F_4 ( V_97 + 2 , 1 ) , V_11 ) ;
F_48 ( V_12 , V_133 , V_9 , F_4 ( V_97 + 3 , 1 ) , V_11 ) ;
V_97 += 4 ;
V_11 = F_50 ( V_97 , V_9 ) ;
F_48 ( V_12 , V_134 , V_9 , F_4 ( V_97 , 2 ) , V_11 ) ;
F_53 ( V_96 , L_187 , V_11 ) ;
V_97 += 2 ;
V_11 = F_50 ( V_97 , V_9 ) ;
F_48 ( V_12 , V_135 , V_9 , F_4 ( V_97 , 2 ) , V_11 ) ;
F_53 ( V_96 , L_187 , V_11 ) ;
V_97 += 2 ;
V_11 = F_50 ( V_97 , V_9 ) ;
F_48 ( V_12 , V_136 , V_9 , F_4 ( V_97 , 2 ) , V_11 ) ;
F_53 ( V_96 , L_187 , V_11 >> 1 ) ;
F_48 ( V_12 , V_137 , V_9 , F_4 ( V_97 + 1 , 1 ) , V_11 ) ;
V_97 += 2 ;
}
else if ( V_98 == 15 )
{
V_99 = F_47 ( 5 + V_97 , V_9 ) ;
V_101 = F_47 ( 5 + V_97 + 1 , V_9 ) ;
V_12 = F_51 ( V_94 , V_9 , F_4 ( V_97 , 5 + 2 + V_101 * 2 ) , V_138 , NULL , L_188 , V_98 ) ;
F_48 ( V_12 , V_106 , V_9 , F_4 ( V_97 , 4 ) , V_103 ) ;
V_97 += 4 ;
F_48 ( V_12 , V_107 , V_9 , F_4 ( V_97 , 1 ) , V_98 ) ;
V_97 += 1 ;
#if 0
ti = proto_tree_add_uint(tree, hf_ulmap_uiuc11_ext, tvb, NIBHI(nibble,1), ext_uiuc);
nibble += 1;
proto_tree_add_uint(tree, hf_ulmap_uiuc11_len, tvb, NIBHI(nibble,1), len);
nibble += 1;
#endif
V_101 = 2 + F_52 ( V_101 ) ;
switch ( V_99 ) {
case 0x00 :
V_97 = F_16 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x01 :
V_97 = F_18 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x02 :
V_97 = F_23 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x03 :
V_97 = F_24 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x04 :
V_97 = F_27 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x05 :
V_97 = F_28 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x06 :
V_97 = F_29 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x07 :
V_97 = F_30 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x08 :
V_97 = F_31 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x09 :
V_97 = F_32 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
case 0x0a :
V_97 = F_33 ( V_12 , V_97 , V_101 , V_9 ) ;
break;
default:
F_21 ( V_12 , V_9 , F_4 ( V_97 , V_101 ) , L_189 , V_99 ) ;
V_97 += V_101 ;
break;
}
}
else
{
V_102 = 0 ;
V_101 = 3 ;
if ( V_102 ) V_101 += 3 ;
V_12 = F_3 ( V_94 , V_9 , F_4 ( V_97 , 5 + V_101 ) , V_139 , NULL , L_190 ) ;
F_48 ( V_12 , V_106 , V_9 , F_4 ( V_97 , 4 ) , V_103 ) ;
V_97 += 4 ;
F_48 ( V_12 , V_107 , V_9 , F_4 ( V_97 , 1 ) , V_98 ) ;
V_97 += 1 ;
V_11 = F_46 ( V_97 , V_9 ) ;
F_48 ( V_12 , V_140 , V_9 , F_4 ( V_97 , 3 ) , V_11 ) ;
F_48 ( V_12 , V_141 , V_9 , F_4 ( V_97 + 2 , 1 ) , V_11 ) ;
V_97 += 3 ;
if ( V_102 ) {
V_11 = F_54 ( V_97 , V_9 ) ;
F_21 ( V_12 , V_9 , F_4 ( V_97 , 3 ) , L_191 , V_11 ) ;
V_97 += 3 ;
}
}
return ( V_97 - V_7 ) ;
}
static void F_55 ( T_3 * V_9 , T_7 * T_8 V_95 , T_2 * V_12 )
{
T_5 V_7 = 0 ;
T_5 V_8 ;
T_5 V_30 , V_44 ;
T_4 * V_96 = NULL ;
T_2 * V_142 = NULL ;
T_2 * V_94 = NULL ;
T_5 V_143 ;
V_143 = F_56 ( V_9 ) ;
V_96 = F_57 ( V_12 , V_144 , V_9 , V_7 , - 1 , L_192 ) ;
V_142 = F_58 ( V_96 , V_145 ) ;
F_59 ( V_142 , V_146 , V_9 , V_7 , 1 , V_147 ) ;
V_7 ++ ;
F_59 ( V_142 , V_148 , V_9 , V_7 , 1 , V_147 ) ;
V_7 ++ ;
F_59 ( V_142 , V_149 , V_9 , V_7 , 4 , V_147 ) ;
V_7 += 4 ;
F_59 ( V_142 , V_150 , V_9 , V_7 , 1 , V_147 ) ;
V_7 ++ ;
V_8 = V_143 - V_7 ;
V_94 = F_51 ( V_142 , V_9 , V_7 , V_8 , V_151 , NULL , L_193 , V_8 ) ;
V_30 = F_52 ( V_7 ) ;
while ( V_30 < ( ( V_143 * 2 ) - 1 ) ) {
V_30 += F_45 ( V_94 , V_30 , V_143 * 2 , V_9 ) ;
}
V_44 = F_60 ( V_30 ) ;
if ( V_44 ) {
F_21 ( V_142 , V_9 , F_4 ( V_30 , 1 ) , L_194 ) ;
V_30 ++ ;
}
}
T_1 F_61 ( T_2 * V_152 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_30 ;
T_5 V_11 ;
T_4 * V_96 = NULL ;
T_2 * V_12 = NULL ;
T_2 * V_94 = NULL ;
V_30 = V_7 ;
V_96 = F_57 ( V_152 , V_144 , V_9 , F_4 ( V_7 , V_8 - V_7 ) , L_195 , F_62 ( V_8 - V_7 ) ) ;
V_12 = F_58 ( V_96 , V_153 ) ;
V_11 = F_50 ( V_30 , V_9 ) ;
F_48 ( V_12 , V_148 , V_9 , F_4 ( V_30 , 2 ) , V_11 ) ;
V_30 += 2 ;
V_11 = F_49 ( V_30 , V_9 ) ;
F_48 ( V_12 , V_149 , V_9 , F_4 ( V_30 , 8 ) , V_11 ) ;
V_30 += 8 ;
V_11 = F_50 ( V_30 , V_9 ) ;
F_48 ( V_12 , V_150 , V_9 , F_4 ( V_30 , 2 ) , V_11 ) ;
V_30 += 2 ;
V_94 = F_51 ( V_12 , V_9 , F_4 ( V_30 , V_8 - V_30 ) , V_154 , NULL , L_193 , F_62 ( V_8 - V_30 ) ) ;
while ( V_30 < V_8 - 1 ) {
V_30 += F_45 ( V_94 , V_30 , V_8 - V_30 , V_9 ) ;
}
if ( V_30 & 1 ) {
F_21 ( V_12 , V_9 , F_4 ( V_30 , 1 ) , L_196 ) ;
V_30 ++ ;
}
return V_8 ;
}
T_1 F_63 ( T_2 * V_152 , T_1 V_7 , T_1 V_8 , T_3 * V_9 )
{
T_1 V_10 ;
T_5 V_11 ;
T_2 * V_12 ;
T_1 V_155 , V_156 , V_157 , V_158 , V_159 , V_160 ;
V_10 = V_7 ;
V_12 = F_3 ( V_152 , V_9 , F_8 ( V_10 , V_8 ) , V_161 , NULL , L_197 ) ;
F_5 ( V_155 , 1 , L_198 ) ;
F_5 ( V_156 , 1 , L_199 ) ;
F_5 ( V_157 , 1 , L_200 ) ;
F_5 ( V_158 , 1 , L_201 ) ;
F_5 ( V_159 , 1 , L_202 ) ;
F_5 ( V_160 , 2 , L_203 ) ;
F_5 ( V_11 , 2 , L_169 ) ;
if ( V_155 ) {
F_5 ( V_11 , 2 , L_47 ) ;
F_5 ( V_11 , 7 , L_48 ) ;
F_5 ( V_11 , 2 , L_204 ) ;
F_5 ( V_11 , 5 , L_45 ) ;
}
if ( V_156 ) {
F_5 ( V_11 , 8 , L_205 ) ;
F_5 ( V_11 , 8 , L_206 ) ;
}
if ( V_157 ) {
F_5 ( V_11 , 8 , L_207 ) ;
V_11 = F_64 ( V_10 , V_9 , 32 ) ;
F_21 ( V_12 , V_9 , F_8 ( V_10 , 32 ) , L_208 , V_11 ) ;
V_10 += 32 ;
}
if ( V_158 ) {
F_5 ( V_11 , 1 , L_209 ) ;
F_5 ( V_11 , 4 , L_210 ) ;
F_5 ( V_11 , 1 , L_82 ) ;
V_11 = F_65 ( V_10 , V_9 , 22 ) ;
F_21 ( V_12 , V_9 , F_8 ( V_10 , 22 ) , L_211 , V_11 ) ;
V_10 += 22 ;
}
if ( V_159 ) {
F_5 ( V_11 , 8 , L_37 ) ;
}
F_5 ( V_11 , 3 , L_212 ) ;
F_5 ( V_11 , 12 , L_213 ) ;
F_5 ( V_11 , 10 , L_214 ) ;
F_5 ( V_11 , 4 , L_215 ) ;
if ( V_2 ) {
F_5 ( V_11 , 4 , L_14 ) ;
F_5 ( V_11 , 1 , L_15 ) ;
F_5 ( V_11 , 3 , L_17 ) ;
if ( V_3 ) {
F_5 ( V_11 , 4 , L_20 ) ;
F_5 ( V_11 , 2 , L_21 ) ;
F_5 ( V_11 , 2 , L_17 ) ;
}
}
F_5 ( V_11 , 2 , L_12 ) ;
return ( V_10 - V_7 ) ;
}
void F_66 ( void )
{
static T_9 V_162 [] =
{
#if 0
{
&hf_ulmap_fch_expected,
{
"FCH Expected", "wmx.ulmap.fch.expected",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
#endif
#if 0
{
&hf_ulmap_ie,
{
"UL-MAP IE", "wmx.ulmap.ie",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
#endif
{
& V_106 ,
{
L_216 , L_217 ,
V_163 , V_164 , NULL , 0x0 , NULL , V_165
}
} ,
{
& V_107 ,
{
L_11 , L_218 ,
V_166 , V_164 , NULL , 0x0 , NULL , V_165
}
} ,
{
& V_150 ,
{
L_219 , L_220 ,
V_166 , V_164 , NULL , 0x0 , NULL , V_165
}
} ,
{
& V_146 ,
{
L_17 , L_221 ,
V_166 , V_164 , NULL , 0x0 , NULL , V_165
}
} ,
{
& V_149 ,
{
L_222 , L_223 ,
V_163 , V_164 , NULL , 0x0 , NULL , V_165
}
} ,
{
& V_148 ,
{
L_207 , L_224 ,
V_166 , V_164 , NULL , 0x0 , NULL , V_165
}
} ,
{
& V_111 ,
{
L_225 , L_226 ,
V_163 , V_164 , NULL , 0x000003f8 , NULL , V_165
}
} ,
{
& V_110 ,
{
L_227 , L_228 ,
V_163 , V_164 , NULL , 0x0001fc00 , NULL , V_165
}
} ,
{
& V_112 ,
{
L_17 , L_229 ,
V_163 , V_164 , NULL , 0x00000007 , NULL , V_165
}
} ,
{
& V_109 ,
{
L_93 , L_230 ,
V_163 , V_164 , NULL , 0x00fe0000 , NULL , V_165
}
} ,
{
& V_108 ,
{
L_49 , L_231 ,
V_163 , V_164 , NULL , 0xff000000 , NULL , V_165
}
} ,
#if 0
{
&hf_ulmap_uiuc11_data,
{
"Data", "wmx.ulmap.uiuc11.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_ulmap_uiuc11_ext,
{
"Extended 2 UIUC", "wmx.ulmap.uiuc11.ext",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_ulmap_uiuc11_len,
{
"Length", "wmx.ulmap.uiuc11.len",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
#endif
{
& V_120 ,
{
L_232 , L_233 ,
V_163 , V_164 , NULL , 0x00000001 , NULL , V_165
}
} ,
{
& V_140 ,
{
L_13 , L_234 ,
V_167 , V_164 , NULL , 0xFFc0 , NULL , V_165
}
} ,
{
& V_119 ,
{
L_235 , L_236 ,
V_163 , V_164 , NULL , 0x00000006 , NULL , V_165
}
} ,
{
& V_118 ,
{
L_163 , L_237 ,
V_163 , V_164 , NULL , 0x000003F8 , NULL , V_165
}
} ,
{
& V_117 ,
{
L_162 , L_238 ,
V_163 , V_164 , NULL , 0x0001Fc00 , NULL , V_165
}
} ,
{
& V_141 ,
{
L_239 , L_240 ,
V_167 , V_164 , NULL , 0x0030 , NULL , V_165
}
} ,
{
& V_116 ,
{
L_161 , L_241 ,
V_163 , V_164 , NULL , 0x00Fe0000 , NULL , V_165
}
} ,
{
& V_115 ,
{
L_160 , L_242 ,
V_163 , V_164 , NULL , 0xFF000000 , NULL , V_165
}
} ,
{
& V_125 ,
{
L_243 , L_244 ,
V_163 , V_164 , NULL , 0x000003f8 , NULL , V_165
}
} ,
{
& V_124 ,
{
L_227 , L_245 ,
V_163 , V_164 , NULL , 0x0001fc00 , NULL , V_165
}
} ,
{
& V_126 ,
{
L_246 , L_247 ,
V_163 , V_164 , NULL , 0x00000004 , NULL , V_165
}
} ,
{
& V_128 ,
{
L_17 , L_248 ,
V_163 , V_164 , NULL , 0x00000001 , NULL , V_165
}
} ,
{
& V_123 ,
{
L_93 , L_249 ,
V_163 , V_164 , NULL , 0x00fe0000 , NULL , V_165
}
} ,
{
& V_122 ,
{
L_49 , L_250 ,
V_163 , V_164 , NULL , 0xff000000 , NULL , V_165
}
} ,
{
& V_127 ,
{
L_251 , L_252 ,
V_163 , V_164 , NULL , 0x00000002 , NULL , V_165
}
} ,
{
& V_137 ,
{
L_253 , L_254 ,
V_166 , V_164 , NULL , 0x01 , NULL , V_165
}
} ,
{
& V_134 ,
{
L_255 , L_256 ,
V_166 , V_164 , NULL , 0x0 , NULL , V_165
}
} ,
{
& V_130 ,
{
L_13 , L_257 ,
V_167 , V_164 , NULL , 0xfc00 , NULL , V_165
}
} ,
{
& V_133 ,
{
L_258 , L_259 ,
V_167 , V_164 , NULL , 0x000F , NULL , V_165
}
} ,
{
& V_132 ,
{
L_12 , L_260 ,
V_167 , V_164 , NULL , 0x0030 , NULL , V_165
}
} ,
{
& V_136 ,
{
L_261 , L_262 ,
V_166 , V_164 , NULL , 0xfe , NULL , V_165
}
} ,
{
& V_135 ,
{
L_263 , L_264 ,
V_166 , V_164 , NULL , 0x0 , NULL , V_165
}
} ,
{
& V_131 ,
{
L_11 , L_265 ,
V_167 , V_164 , NULL , 0x03c0 , NULL , V_165
}
} ,
#if 0
{
&hf_ulmap_uiuc15_data,
{
"Data", "wmx.ulmap.uiuc15.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_ulmap_uiuc15_ext,
{
"Extended UIUC", "wmx.ulmap.uiuc15.ext",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_ulmap_uiuc15_len,
{
"Length", "wmx.ulmap.uiuc15.len",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
}
#endif
} ;
static T_1 * V_168 [] =
{
& V_145 ,
& V_151 ,
& V_105 ,
& V_114 ,
& V_139 ,
& V_121 ,
& V_129 ,
& V_113 ,
& V_138 ,
& V_31 ,
& V_36 ,
& V_46 ,
& V_35 ,
& V_49 ,
& V_45 ,
& V_48 ,
& V_54 ,
& V_57 ,
& V_51 ,
& V_58 ,
& V_59 ,
& V_73 ,
& V_50 ,
& V_53 ,
& V_63 ,
& V_79 ,
& V_17 ,
& V_18 ,
& V_19 ,
& V_24 ,
& V_25 ,
& V_26 ,
& V_29 ,
& V_14 ,
& V_15 ,
& V_80 ,
& V_89 ,
& V_93 ,
& V_153 ,
& V_154 ,
& V_161 ,
& V_72 ,
} ;
V_144 = F_67 (
L_266 ,
L_267 ,
L_268
) ;
F_68 ( V_144 , V_162 , F_69 ( V_162 ) ) ;
F_70 ( V_168 , F_69 ( V_168 ) ) ;
}
void F_71 ( void )
{
T_10 V_169 ;
V_169 = F_72 ( F_55 , V_144 ) ;
F_73 ( L_269 , V_170 , V_169 ) ;
}
