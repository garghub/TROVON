static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 ,
T_4 V_4 )
{
T_5 * V_5 ;
T_6 * V_6 ;
T_7 * V_7 ;
T_8 V_8 ;
T_9 V_9 ;
T_10 V_10 ;
V_9 = ( V_2 -> V_11 == V_2 -> V_12 ) ;
V_8 = F_2 ( V_1 , V_4 + 4 ) ;
V_10 = F_3 ( V_1 , V_4 + 6 ) ;
V_5 = F_4 ( V_2 ) ;
V_6 = ( T_6 * ) F_5 ( V_5 , V_13 ) ;
if ( ! V_6 ) {
V_6 = F_6 ( F_7 () , T_6 ) ;
V_6 -> V_14 = F_8 ( F_7 () , V_15 , V_16 ) ;
F_9 ( V_5 , V_13 , V_6 ) ;
}
if ( ! V_2 -> V_17 -> V_18 . V_19 ) {
if ( V_9 ) {
V_7 = F_6 ( F_7 () , T_7 ) ;
V_7 -> V_20 = V_2 -> V_17 -> V_21 ;
V_7 -> V_22 = 0 ;
V_7 -> V_23 = V_2 -> V_17 -> V_24 ;
V_7 -> V_25 = V_8 ;
V_7 -> V_26 = V_10 ;
F_10 ( V_6 -> V_14 , F_11 ( ( V_27 ) V_8 ) , ( void * ) V_7 ) ;
} else {
V_7 = ( T_7 * ) F_12 ( V_6 -> V_14 , F_11 ( ( V_27 ) V_8 ) ) ;
if ( V_7 ) {
if ( V_7 -> V_22 == 0 )
V_7 -> V_22 = V_2 -> V_17 -> V_21 ;
}
}
} else {
V_7 = ( T_7 * ) F_12 ( V_6 -> V_14 , F_11 ( ( V_27 ) V_8 ) ) ;
}
if ( V_3 && V_7 ) {
if ( V_9 ) {
if ( V_7 -> V_22 ) {
T_11 * V_28 ;
V_28 = F_13 ( V_3 , V_29 ,
V_1 , 0 , 0 , V_7 -> V_22 ) ;
F_14 ( V_28 ) ;
}
} else {
if ( V_7 -> V_20 ) {
T_11 * V_28 ;
T_12 V_30 ;
V_28 = F_13 ( V_3 , V_31 ,
V_1 , 0 , 0 , V_7 -> V_20 ) ;
F_14 ( V_28 ) ;
F_15 ( & V_30 , & V_2 -> V_17 -> V_24 , & V_7 -> V_23 ) ;
V_28 = F_16 ( V_3 , V_32 , V_1 , 0 , 0 , & V_30 ) ;
F_14 ( V_28 ) ;
}
}
}
}
static int
F_17 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_33 , void * T_13 V_34 )
{
T_11 * V_35 ;
T_3 * V_3 = NULL ;
T_4 V_4 = 0 ;
T_4 V_36 ;
T_10 V_10 ;
T_9 V_9 ;
V_9 = ( V_2 -> V_11 == V_2 -> V_12 ) ;
V_10 = F_3 ( V_1 , 6 ) ;
F_18 ( V_2 -> V_37 , V_38 , V_39 ) ;
F_19 ( V_2 -> V_37 , V_40 , V_9 ? L_1 : L_2 ) ;
F_20 ( V_2 -> V_37 , V_40 , F_21 ( V_10 ,
V_41 , L_3 ) ) ;
V_35 = F_22 ( V_33 , V_13 , V_1 , V_4 , - 1 , V_42 ) ;
V_3 = F_23 ( V_35 , V_43 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
if ( V_33 ) {
F_22 ( V_3 , V_44 , V_1 , V_4 , 2 ,
V_45 ) ;
V_4 += 2 ;
V_36 = F_3 ( V_1 , V_4 ) ;
F_22 ( V_3 , V_46 , V_1 , V_4 , 1 ,
V_42 ) ;
V_4 += 1 ;
F_22 ( V_3 , V_47 , V_1 , V_4 , 1 ,
V_42 ) ;
V_4 += 1 ;
F_22 ( V_3 , V_48 , V_1 , V_4 , 2 ,
V_49 ) ;
V_4 += 2 ;
F_22 ( V_3 , V_50 , V_1 , V_4 , 1 ,
V_42 ) ;
V_4 += 1 ;
if ( V_9 ) {
switch ( V_10 ) {
case 0x20 :
F_22 ( V_3 , V_51 , V_1 , V_4 , 7 ,
V_42 ) ;
V_4 += 7 ;
break;
default:
F_22 ( V_3 , V_52 , V_1 , V_4 , V_36 - 8 ,
V_42 ) ;
V_4 += ( V_36 - 8 ) ;
break;
}
} else {
switch ( V_10 ) {
default:
F_22 ( V_3 , V_53 , V_1 ,
V_4 , V_36 - 8 , V_42 ) ;
V_4 += ( V_36 - 8 ) ;
break;
}
}
if ( V_4 < V_36 - 1 ) {
F_22 ( V_3 , V_54 , V_1 , V_4 ,
V_36 - 1 - V_4 , V_42 ) ;
V_4 += V_36 - 1 - V_4 ;
}
F_22 ( V_3 , V_55 , V_1 , V_4 , 1 ,
V_45 ) ;
V_4 += 1 ;
}
return V_4 ;
}
static T_9
F_24 ( T_1 * V_1 )
{
if ( F_25 ( V_1 ) < 8
|| F_26 ( V_1 , 0 ) != 0x55BB
) {
return FALSE ;
}
return TRUE ;
}
static V_27
F_27 ( T_2 * V_2 V_34 , T_1 * V_1 , int V_4 , void * T_13 V_34 )
{
return F_3 ( V_1 , V_4 + 2 ) ;
}
static int
F_28 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_33 , void * T_13 V_34 )
{
if ( ! F_24 ( V_1 ) ) {
return 0 ;
}
F_29 ( V_1 , V_2 , V_33 , V_56 , 8 ,
F_27 , F_17 , T_13 ) ;
return F_25 ( V_1 ) ;
}
void
F_30 ( void )
{
static T_14 V_57 [] = {
{ & V_44 ,
{ L_4 , L_5 , V_58 , V_59 , NULL ,
0x0 , NULL , V_60 } } ,
{ & V_46 ,
{ L_6 , L_7 , V_61 , V_59 , NULL ,
0x0 , NULL , V_60 } } ,
{ & V_47 ,
{ L_8 , L_9 , V_61 , V_59 , NULL ,
0x0 , NULL , V_60 } } ,
{ & V_48 ,
{ L_10 , L_11 , V_58 , V_62 , NULL ,
0x0 , NULL , V_60 } } ,
{ & V_50 ,
{ L_12 , L_13 , V_61 , V_59 , F_31 ( V_41 ) ,
0x0 , NULL , V_60 } } ,
{ & V_55 ,
{ L_14 , L_15 , V_61 , V_59 , NULL ,
0x0 , NULL , V_60 } } ,
#if 0
{ &hf_djiuav_cmd04_unknown,
{ "C04 Unknown", "djiuav.cmd04.unknown", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_djiuav_resp04_unknown,
{ "R04 Unknown", "djiuav.resp04.unknown", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
#endif
{ & V_51 ,
{ L_16 , L_17 , V_63 , V_64 , NULL ,
0x0 , NULL , V_60 } } ,
#if 0
{ &hf_djiuav_resp20_unknown,
{ "R20 Unknown", "djiuav.resp04.unknown", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
#endif
{ & V_52 ,
{ L_18 , L_19 , V_63 , V_64 , NULL ,
0x0 , NULL , V_60 } } ,
{ & V_53 ,
{ L_20 , L_21 , V_63 , V_64 , NULL ,
0x0 , NULL , V_60 } } ,
{ & V_54 ,
{ L_22 , L_23 , V_63 , V_64 , NULL ,
0x0 , NULL , V_60 } } ,
{ & V_29 ,
{ L_24 , L_25 , V_65 , V_64 , NULL ,
0x0 , L_26 , V_60 } } ,
{ & V_31 ,
{ L_27 , L_28 ,
V_65 , V_64 , NULL ,
0x0 , L_29 , V_60 } } ,
{ & V_32 ,
{ L_30 , L_31 ,
V_66 , V_64 , NULL ,
0x0 , L_32 , V_60 } } ,
} ;
static T_15 * V_67 [] = {
& V_43 ,
} ;
T_16 * V_68 ;
V_13 = F_32 ( V_69 , V_39 , L_33 ) ;
F_33 ( V_13 , V_57 , F_34 ( V_57 ) ) ;
F_35 ( V_67 , F_34 ( V_67 ) ) ;
V_68 = F_36 ( V_13 , NULL ) ;
F_37 ( V_68 , L_34 ,
L_35 ,
L_36
L_37 ,
& V_56 ) ;
}
void
F_38 ( void )
{
T_17 V_70 ;
V_70 = F_39 ( F_28 , V_13 ) ;
F_40 ( L_38 , V_71 , V_70 ) ;
}
