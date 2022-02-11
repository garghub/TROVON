static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_1 * V_4 ;
T_3 * V_5 , * V_6 ;
volatile int V_7 = 0 ;
T_4 V_8 ;
void * V_9 ;
F_2 ( V_2 -> V_10 , V_11 , L_1 ) ;
F_2 ( V_2 -> V_10 , V_12 , L_2 ) ;
V_6 = NULL ;
while( F_3 ( V_1 , V_7 ) > 0 ) {
V_5 = F_4 ( V_3 , V_13 , V_1 , V_7 , 28 , V_14 ) ;
V_6 = F_5 ( V_5 , V_15 ) ;
F_4 ( V_6 , V_16 , V_1 , V_7 , 2 , V_17 ) ;
V_7 += 2 ;
F_4 ( V_6 , V_18 , V_1 , V_7 , 7 , V_14 ) ;
V_7 += 7 ;
F_4 ( V_6 , V_19 , V_1 , V_7 , 1 , V_17 ) ;
V_7 += 1 ;
F_4 ( V_6 , V_20 , V_1 , V_7 , 6 , V_14 ) ;
V_7 += 6 ;
F_4 ( V_6 , V_21 , V_1 , V_7 , 2 , V_17 ) ;
V_7 += 2 ;
V_8 = F_6 ( V_1 , V_7 ) ;
F_4 ( V_6 , V_22 , V_1 , V_7 , 2 , V_17 ) ;
V_7 += 2 ;
F_4 ( V_6 , V_23 , V_1 , V_7 , 8 , V_14 ) ;
V_7 += 8 ;
V_4 = F_7 ( V_1 , V_7 , V_8 , V_8 ) ;
V_9 = V_2 -> V_24 ;
F_8 {
F_9 ( V_25 , V_4 , V_2 , V_3 ) ;
} F_10 (BoundsError, ReportedBoundsError) {
F_11 ( V_2 , NULL ,
V_26 , V_27 ,
L_3 ) ;
V_2 -> V_24 = V_9 ;
F_12 ( V_2 -> V_10 , V_12 ,
L_4 ) ;
F_13 ( V_2 -> V_10 , V_12 ) ;
#if 0
wlan_tvb = tvb_new_subset(tvb, offset, capturelen, capturelen);
proto_tree_add_text(cwids_tree, wlan_tvb, offset, capturelen,
"[Malformed or short IEEE80211 subpacket]");
#else
F_7 ( V_1 , V_7 , V_8 , V_8 ) ;
#endif
;
} V_28 ;
V_7 += V_8 ;
}
}
void
F_14 ( void )
{
static T_5 V_29 [] = {
{ & V_16 ,
{ L_5 , L_6 , V_30 , V_31 , NULL ,
0x0 , L_7 , V_32 } } ,
{ & V_18 ,
{ L_8 , L_9 , V_33 , V_34 , NULL ,
0x0 , L_10 , V_32 } } ,
{ & V_19 ,
{ L_11 , L_12 , V_35 , V_31 , NULL ,
0x0 , L_13 , V_32 } } ,
{ & V_20 ,
{ L_14 , L_15 , V_33 , V_34 , NULL ,
0x0 , L_16 , V_32 } } ,
{ & V_21 ,
{ L_17 , L_18 , V_30 , V_31 , NULL ,
0x0 , L_19 , V_32 } } ,
{ & V_22 ,
{ L_20 , L_21 , V_30 , V_31 , NULL ,
0x0 , L_22 , V_32 } } ,
{ & V_23 ,
{ L_23 , L_24 , V_33 , V_34 , NULL ,
0x0 , L_25 , V_32 } } ,
} ;
static T_6 * V_36 [] = {
& V_15 ,
} ;
T_7 * V_37 ;
V_13 = F_15 ( L_26 , L_1 , L_27 ) ;
F_16 ( V_13 , V_29 , F_17 ( V_29 ) ) ;
F_18 ( V_36 , F_17 ( V_36 ) ) ;
V_37 = F_19 ( V_13 , V_38 ) ;
F_20 ( V_37 , L_28 ,
L_29 ,
L_30 ,
10 , & V_39 ) ;
}
void
V_38 ( void )
{
static T_8 V_40 ;
static T_9 V_41 ;
static T_10 V_42 = FALSE ;
if ( ! V_42 ) {
V_40 = F_21 ( F_1 , V_13 ) ;
F_22 ( L_28 , V_40 ) ;
V_25 = F_23 ( L_31 ) ;
V_42 = TRUE ;
} else {
if ( V_41 != 0 ) {
F_24 ( L_28 , V_41 , V_40 ) ;
}
}
if ( V_39 != 0 ) {
F_25 ( L_28 , V_39 , V_40 ) ;
}
V_41 = V_39 ;
}
