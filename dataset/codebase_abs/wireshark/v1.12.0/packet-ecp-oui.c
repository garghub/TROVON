static T_1
F_1 ( T_2 * V_1 , T_3 * T_4 V_2 , T_5 * V_3 , T_6 V_4 )
{
T_7 V_5 ;
T_7 V_6 ;
T_5 * V_7 = NULL ;
T_8 * V_8 = NULL ;
V_6 = F_2 ( V_1 , V_4 ) ;
V_5 = F_3 ( V_6 ) ;
if ( V_3 )
{
V_8 = F_4 ( V_3 , V_1 , V_4 , ( V_5 + 2 ) , L_1 ) ;
V_7 = F_5 ( V_8 , V_9 ) ;
}
F_6 ( V_7 , V_10 , V_1 , V_4 , 2 , V_11 ) ;
return - 1 ;
}
static T_1
F_7 ( T_2 * V_1 , T_3 * T_4 V_2 , T_5 * V_3 , T_6 V_4 )
{
T_9 V_12 ;
T_7 V_13 ;
T_6 V_14 = V_4 ;
const T_10 * V_15 = NULL ;
T_5 * V_16 = NULL ;
T_8 * V_8 = NULL ;
V_13 = F_2 ( V_1 , V_4 ) ;
if ( V_3 )
{
V_8 = F_4 ( V_3 , V_1 , V_14 , 2 , L_2 ,
V_13 , F_8 ( ( V_13 > 1 ) , L_3 , L_4 ) ) ;
V_16 = F_5 ( V_8 , V_9 ) ;
}
V_14 += 2 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
V_15 = F_9 ( V_1 , V_14 , 6 ) ;
if ( V_3 ) {
F_10 ( V_16 , V_17 , V_1 , V_14 , 6 , V_15 ) ;
}
V_14 += 6 ;
F_6 ( V_16 , V_18 , V_1 , V_14 , 2 , V_11 ) ;
V_14 += 2 ;
}
return V_14 - V_4 ;
}
static T_1
F_11 ( T_2 * V_1 , T_3 * T_4 V_2 , T_5 * V_3 , T_6 V_4 )
{
T_7 V_5 ;
T_7 V_19 ;
T_7 V_6 ;
T_6 V_14 = V_4 ;
T_6 V_20 ;
const char * V_21 ;
T_10 V_22 , V_23 ;
const char * V_24 ;
T_5 * V_25 = NULL ;
T_8 * V_8 = NULL ;
V_5 = 0 ;
V_6 = F_2 ( V_1 , V_4 ) ;
V_19 = F_3 ( V_6 ) ;
V_14 += 2 ;
V_20 = F_12 ( V_1 , ( V_14 ) ) ;
V_21 = F_13 ( V_20 , V_26 , L_5 ) ;
if ( strcmp ( V_21 , L_5 ) == 0 ) {
V_21 = F_14 ( V_20 ) ;
if( V_21 == NULL ) V_21 = L_5 ;
}
V_14 += 3 ;
V_22 = F_15 ( V_1 , V_14 ) ;
switch( V_20 ) {
case V_27 :
V_24 = F_16 ( V_22 , V_28 , L_6 ) ;
break;
default:
V_24 = L_5 ;
break;
}
if ( V_3 ) {
V_8 = F_4 ( V_3 , V_1 , V_4 , ( V_19 + 2 ) , L_7 ,
V_21 , V_24 ) ;
V_25 = F_5 ( V_8 , V_9 ) ;
}
V_14 ++ ;
F_6 ( V_25 , V_29 , V_1 , V_14 , 1 , V_11 ) ;
V_14 ++ ;
F_6 ( V_25 , V_30 , V_1 , V_14 , 1 , V_11 ) ;
V_14 ++ ;
F_6 ( V_25 , V_31 , V_1 , V_14 , 1 , V_11 ) ;
V_14 ++ ;
F_6 ( V_25 , V_32 , V_1 , V_14 , 3 , V_11 ) ;
V_14 += 3 ;
F_6 ( V_25 , V_33 , V_1 , V_14 , 1 , V_11 ) ;
V_14 += 1 ;
F_6 ( V_25 , V_34 , V_1 , V_14 , 16 , V_35 ) ;
V_14 += 16 ;
V_23 = F_15 ( V_1 , V_14 ) ;
F_6 ( V_25 , V_36 , V_1 , V_14 , 1 , V_11 ) ;
V_14 ++ ;
switch ( V_23 ) {
case V_37 :
case V_38 :
V_5 = F_7 ( V_1 , T_4 , V_25 , V_14 ) ;
break;
case V_39 :
break;
case V_40 :
break;
default:
break;
}
V_14 += V_5 ;
return V_14 - V_4 ;
}
T_1
F_17 ( T_2 * V_1 , T_3 * T_4 V_2 , T_5 * V_3 , T_6 V_4 )
{
T_7 V_5 ;
T_7 V_6 ;
T_5 * V_41 = NULL ;
T_8 * V_42 = NULL ;
V_6 = F_2 ( V_1 , V_4 ) ;
V_5 = F_3 ( V_6 ) ;
if ( V_3 )
{
V_42 = F_4 ( V_3 , V_1 , V_4 , ( V_5 + 2 ) , L_8 ) ;
V_41 = F_5 ( V_42 , V_43 ) ;
F_6 ( V_41 , V_44 , V_1 , V_4 , 2 , V_11 ) ;
F_6 ( V_41 , V_45 , V_1 , V_4 , 2 , V_11 ) ;
}
return - 1 ;
}
static void
F_18 ( T_2 * V_1 , T_3 * T_4 , T_5 * V_3 )
{
T_5 * V_46 = NULL ;
T_8 * V_8 = NULL ;
T_1 V_5 = 0 ;
T_6 V_4 = 0 ;
T_7 V_6 ;
T_10 V_47 ;
T_11 V_48 = FALSE ;
F_19 ( T_4 -> V_49 , V_50 , L_9 ) ;
if ( V_3 ) {
V_8 = F_6 ( V_3 , V_51 , V_1 , 0 , - 1 , V_35 ) ;
V_46 = F_5 ( V_8 , V_9 ) ;
}
F_6 ( V_46 , V_10 , V_1 , V_4 , 1 , V_11 ) ;
F_6 ( V_46 , V_52 , V_1 , V_4 + 1 , 1 , V_11 ) ;
F_6 ( V_46 , V_53 , V_1 , V_4 + 2 , 2 , V_11 ) ;
V_4 += 4 ;
while ( ! V_48 ) {
if ( ! F_20 ( V_1 , V_4 , 1 ) )
break;
V_6 = F_2 ( V_1 , V_4 ) ;
V_47 = F_21 ( V_6 ) ;
switch ( V_47 ) {
case V_54 :
V_5 = F_11 ( V_1 , T_4 , V_46 , V_4 ) ;
break;
case V_55 :
V_5 = F_17 ( V_1 , T_4 , V_46 , V_4 ) ;
break;
default:
V_5 = F_1 ( V_1 , T_4 , V_46 , V_4 ) ;
break;
}
V_4 += V_5 ;
if ( V_5 < 0 )
V_48 = TRUE ;
}
}
void F_22 ( void )
{
static T_12 V_56 = {
& V_57 ,
{ L_10 , L_11 , V_58 , V_59 ,
F_23 ( V_60 ) , 0x0 , NULL , V_61 } ,
} ;
static T_12 V_62 [] = {
{ & V_44 ,
{ L_12 , L_13 , V_58 , V_63 ,
NULL , V_64 , NULL , V_61 }
} ,
{ & V_45 ,
{ L_14 , L_15 , V_58 , V_63 ,
NULL , V_65 , NULL , V_61 }
} ,
{ & V_10 ,
{ L_16 , L_17 , V_66 , V_59 ,
F_23 ( V_67 ) , 0x0 , NULL , V_61 } ,
} ,
{ & V_52 ,
{ L_18 , L_19 , V_66 , V_59 ,
F_23 ( V_68 ) , 0x0 , NULL , V_61 } ,
} ,
{ & V_53 ,
{ L_20 , L_21 , V_58 , V_59 ,
NULL , 0x0 , NULL , V_61 } ,
} ,
#if 0
{ &hf_ecp_vdp_oui,
{ "Organization Unique Code", "ecp.vdp.oui", FT_UINT24, BASE_HEX,
VALS(tlv_oui_subtype_vals), 0x0, NULL, HFILL }
},
#endif
{ & V_29 ,
{ L_18 , L_22 , V_66 , V_59 ,
F_23 ( V_69 ) , 0x0 , NULL , V_61 } ,
} ,
{ & V_30 ,
{ L_23 , L_24 , V_66 , V_59 ,
F_23 ( V_70 ) , 0x0 , NULL , V_61 } ,
} ,
{ & V_31 ,
{ L_25 , L_26 , V_66 , V_59 ,
NULL , 0x0 , NULL , V_61 } ,
} ,
{ & V_32 ,
{ L_27 , L_28 , V_71 , V_59 ,
NULL , 0x0 , NULL , V_61 } ,
} ,
{ & V_33 ,
{ L_29 , L_30 , V_66 , V_59 ,
NULL , 0x0 , NULL , V_61 } ,
} ,
{ & V_34 ,
{ L_31 , L_32 , V_72 , V_73 ,
NULL , 0x0 , NULL , V_61 } ,
} ,
{ & V_36 ,
{ L_33 , L_34 , V_66 , V_59 ,
F_23 ( V_74 ) , 0x0 , NULL , V_61 } ,
} ,
{ & V_17 ,
{ L_35 , L_36 , V_75 , V_73 ,
NULL , 0x0 , NULL , V_61 }
} ,
{ & V_18 ,
{ L_37 , L_38 , V_58 , V_63 ,
NULL , 0x0 , NULL , V_61 }
} ,
} ;
static T_9 * V_76 [] = {
& V_9 ,
& V_43 ,
& V_77 ,
} ;
F_24 ( V_27 , L_11 ,
L_39 , & V_56 ) ;
V_51 = F_25 ( L_40 , L_9 , L_41 ) ;
F_26 ( V_51 , V_62 , F_27 ( V_62 ) ) ;
F_28 ( V_76 , F_27 ( V_76 ) ) ;
F_29 ( L_41 , F_18 , V_51 ) ;
}
void F_30 ( void )
{
static T_13 V_78 ;
V_78 = F_31 ( L_41 ) ;
F_32 ( L_11 , 0x0000 , V_78 ) ;
}
