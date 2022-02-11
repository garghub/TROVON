static inline T_1 F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 & 0xff ) | ( ( V_2 -> V_4 & 0xff ) << 8 ) |
( 0xcafe << 16 ) ;
}
int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 , T_1 type )
{
int V_9 , V_10 ;
const struct V_11 * V_12 ;
V_12 = V_13 ;
V_10 = F_3 ( V_13 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( type == V_12 [ V_9 ] . V_14 ) {
V_6 -> V_15 . V_16 = V_12 [ V_9 ] . V_17 ;
V_6 -> V_18 . V_16 = V_12 [ V_9 ] . V_19 ;
V_6 -> V_15 . V_20 = F_4 ( V_6 -> V_15 . V_16 ,
sizeof( T_1 ) , V_21 ) ;
if ( ! V_6 -> V_15 . V_20 )
return - V_22 ;
V_6 -> V_18 . V_20 = F_4 ( V_6 -> V_18 . V_16 ,
sizeof( T_1 ) , V_21 ) ;
if ( ! V_6 -> V_18 . V_20 ) {
F_5 ( V_6 -> V_15 . V_20 ) ;
V_6 -> V_15 . V_20 = NULL ;
return - V_22 ;
}
memset ( V_6 -> V_15 . V_20 , 0 , sizeof( T_1 ) * V_6 -> V_15 . V_16 ) ;
memset ( V_6 -> V_18 . V_20 , 0 , sizeof( T_1 ) * V_6 -> V_18 . V_16 ) ;
V_6 -> V_15 . V_20 [ 0 ] = type ;
break;
}
}
return 0 ;
}
void F_6 ( struct V_5 * V_14 )
{
F_5 ( V_14 -> V_15 . V_20 ) ;
V_14 -> V_15 . V_20 = NULL ;
F_5 ( V_14 -> V_18 . V_20 ) ;
V_14 -> V_18 . V_20 = NULL ;
}
static T_1
F_7 ( struct V_7 * V_8 )
{
T_1 V_18 ;
int V_23 = 0 , V_24 = 0 ;
do {
F_8 ( 1 ) ;
if ( ++ V_23 > V_25 )
return V_26 ;
V_18 = F_9 ( V_8 , V_27 , & V_24 ) ;
} while ( ! F_10 ( V_18 ) );
return V_18 ;
}
int F_11 ( struct V_7 * V_8 ,
struct V_5 * V_14 )
{
int V_9 , V_24 = 0 ;
T_1 V_18 ;
T_1 V_28 ;
struct V_29 * V_30 = V_8 -> V_30 ;
struct V_1 * V_2 = V_8 -> V_2 ;
const char * V_31 ;
V_28 = F_1 ( V_2 ) ;
if ( F_12 ( V_8 ) ) {
V_14 -> V_18 . V_20 [ 0 ] = V_32 ;
return V_14 -> V_18 . V_20 [ 0 ] ;
}
F_13 ( V_8 , V_33 , V_28 ) ;
for ( V_9 = 1 ; V_9 < V_34 ; V_9 ++ )
F_13 ( V_8 , F_14 ( V_9 ) , V_14 -> V_15 . V_20 [ V_9 ] ) ;
F_13 ( V_8 , V_27 ,
F_15 ( V_14 -> V_15 . V_20 [ 0 ] ) ) ;
V_18 = F_7 ( V_8 ) ;
if ( V_18 == V_26 ) {
F_16 ( & V_30 -> V_35 , L_1 ) ;
V_14 -> V_18 . V_20 [ 0 ] = V_32 ;
} else if ( V_18 == V_36 ) {
V_14 -> V_18 . V_20 [ 0 ] = F_9 ( V_8 , F_14 ( 1 ) , & V_24 ) ;
switch ( V_14 -> V_18 . V_20 [ 0 ] ) {
case V_37 :
V_31 = L_2 ;
break;
case V_38 :
case V_39 :
V_31 = L_3 ;
break;
case V_40 :
V_31 = L_4 ;
break;
case V_41 :
V_31 = L_5 ;
break;
case V_32 :
V_31 = L_6 ;
break;
default:
V_31 = L_7 ;
break;
}
F_16 ( & V_30 -> V_35 , V_31 , V_14 -> V_18 . V_20 [ 0 ] ) ;
F_17 ( V_8 , V_14 ) ;
} else if ( V_18 == V_42 )
V_14 -> V_18 . V_20 [ 0 ] = V_43 ;
for ( V_9 = 1 ; V_9 < V_14 -> V_18 . V_16 ; V_9 ++ )
V_14 -> V_18 . V_20 [ V_9 ] = F_9 ( V_8 , F_14 ( V_9 ) , & V_24 ) ;
F_18 ( V_8 ) ;
return V_14 -> V_18 . V_20 [ 0 ] ;
}
int F_19 ( struct V_7 * V_8 , T_1 V_44 )
{
struct V_5 V_14 ;
T_1 V_45 , V_46 , V_47 ;
char V_48 [ 12 ] ;
int V_24 = 0 ;
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
snprintf (drv_string, sizeof(drv_string), L_8.L_9%dL_9.L_9%dL_10Failed to set driver version in firmware\nL_11Failed to set mtu\nL_12Failed to create rx ctx in firmware%d\nL_13Rx Context[%d] Created, state 0x%x\nL_14Failed to destroy rx ctx in firmware\nL_15Tx Context[0x%x] Created, state 0x%x\nL_16Failed to create tx ctx in firmware%d\nL_17Failed to destroy tx ctx in firmware\nL_18Failed to %s interrupts %d\nL_19AddL_20DeleteL_21failed to configure interrupt for %d\nL_22Failed to get mac address%d\nL_23Failed to get nic info%d\nL_24Failed to set nic info%d\nL_25Failed to get PCI Info%d\nL_26%s: Invalid function count: total nic func[%x], total pci func[%x]\nL_27Failed to configure port mirroring for vNIC function %d on eSwitch %d\nL_28Configured port mirroring for vNIC function %d on eSwitch %d\nL_29Not privilege to query stats for func=%dL_30%s: Get mac stats failed, err=%d.\nL_31Invalid args func_esw %d port %d rx_ctx %d\nL_32Get eSwitch port config for vNIC function %d\nL_33Failed to get eswitch port config for vNIC function %d\nL_34Failed to configure eswitch for vNIC function %d\nL_35Configured eSwitch for vNIC function %d\n"
