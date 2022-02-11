static T_1
F_1 ( T_2 * V_1 , T_3 * T_4 V_2 , T_5 * V_3 , T_6 V_4 )
{
T_7 V_5 ;
T_7 V_6 ;
T_5 * V_7 ;
V_6 = F_2 ( V_1 , V_4 ) ;
V_5 = F_3 ( V_6 ) ;
V_7 = F_4 ( V_3 , V_1 , V_4 , ( V_5 + 2 ) , V_8 , NULL , L_1 ) ;
F_5 ( V_7 , V_9 , V_1 , V_4 , 2 , V_10 ) ;
return - 1 ;
}
static T_1
F_6 ( T_2 * V_1 , T_3 * T_4 V_2 , T_5 * V_3 , T_6 V_4 )
{
T_8 V_11 ;
T_7 V_12 ;
T_6 V_13 = V_4 ;
const T_9 * V_14 = NULL ;
T_5 * V_15 ;
V_12 = F_2 ( V_1 , V_4 ) ;
V_15 = F_7 ( V_3 , V_1 , V_13 , 2 , V_8 , NULL ,
L_2 , V_12 , F_8 ( ( V_12 > 1 ) , L_3 , L_4 ) ) ;
V_13 += 2 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
V_14 = F_9 ( V_1 , V_13 , 6 ) ;
if ( V_3 ) {
F_10 ( V_15 , V_16 , V_1 , V_13 , 6 , V_14 ) ;
}
V_13 += 6 ;
F_5 ( V_15 , V_17 , V_1 , V_13 , 2 , V_10 ) ;
V_13 += 2 ;
}
return V_13 - V_4 ;
}
static T_1
F_11 ( T_2 * V_1 , T_3 * T_4 V_2 , T_5 * V_3 , T_6 V_4 )
{
T_7 V_5 ;
T_7 V_18 ;
T_7 V_6 ;
T_6 V_13 = V_4 ;
T_6 V_19 ;
const char * V_20 ;
T_9 V_21 , V_22 ;
const char * V_23 ;
T_5 * V_24 ;
V_5 = 0 ;
V_6 = F_2 ( V_1 , V_4 ) ;
V_18 = F_3 ( V_6 ) ;
V_13 += 2 ;
V_19 = F_12 ( V_1 , ( V_13 ) ) ;
V_20 = F_13 ( V_19 , V_25 , L_5 ) ;
if ( strcmp ( V_20 , L_5 ) == 0 ) {
V_20 = F_14 ( V_19 ) ;
if( V_20 == NULL ) V_20 = L_5 ;
}
V_13 += 3 ;
V_21 = F_15 ( V_1 , V_13 ) ;
V_13 ++ ;
switch( V_19 ) {
case V_26 :
V_23 = F_16 ( V_21 , V_27 , L_6 ) ;
break;
default:
V_23 = L_5 ;
break;
}
V_24 = F_7 ( V_3 , V_1 , V_4 , ( V_18 + 2 ) , V_8 , NULL ,
L_7 , V_20 , V_23 ) ;
F_5 ( V_24 , V_28 , V_1 , V_13 , 1 , V_10 ) ;
V_13 ++ ;
F_5 ( V_24 , V_29 , V_1 , V_13 , 1 , V_10 ) ;
V_13 ++ ;
F_5 ( V_24 , V_30 , V_1 , V_13 , 1 , V_10 ) ;
V_13 ++ ;
F_5 ( V_24 , V_31 , V_1 , V_13 , 3 , V_10 ) ;
V_13 += 3 ;
F_5 ( V_24 , V_32 , V_1 , V_13 , 1 , V_10 ) ;
V_13 += 1 ;
F_5 ( V_24 , V_33 , V_1 , V_13 , 16 , V_34 ) ;
V_13 += 16 ;
V_22 = F_15 ( V_1 , V_13 ) ;
F_5 ( V_24 , V_35 , V_1 , V_13 , 1 , V_10 ) ;
V_13 ++ ;
switch ( V_22 ) {
case V_36 :
case V_37 :
V_5 = F_6 ( V_1 , T_4 , V_24 , V_13 ) ;
break;
case V_38 :
break;
case V_39 :
break;
default:
break;
}
V_13 += V_5 ;
return V_13 - V_4 ;
}
static T_1
F_17 ( T_2 * V_1 , T_3 * T_4 V_2 , T_5 * V_3 , T_6 V_4 )
{
T_7 V_5 ;
T_7 V_6 ;
T_5 * V_40 ;
V_6 = F_2 ( V_1 , V_4 ) ;
V_5 = F_3 ( V_6 ) ;
if ( V_3 )
{
V_40 = F_4 ( V_3 , V_1 , V_4 , ( V_5 + 2 ) ,
V_41 , NULL , L_8 ) ;
F_5 ( V_40 , V_42 , V_1 , V_4 , 2 , V_10 ) ;
F_5 ( V_40 , V_43 , V_1 , V_4 , 2 , V_10 ) ;
}
return - 1 ;
}
static void
F_18 ( T_2 * V_1 , T_3 * T_4 , T_5 * V_3 )
{
T_5 * V_44 ;
T_10 * V_45 ;
T_1 V_5 = 0 ;
T_6 V_4 = 0 ;
T_7 V_6 ;
T_9 V_46 ;
T_11 V_47 = FALSE ;
F_19 ( T_4 -> V_48 , V_49 , L_9 ) ;
V_45 = F_5 ( V_3 , V_50 , V_1 , 0 , - 1 , V_34 ) ;
V_44 = F_20 ( V_45 , V_8 ) ;
F_5 ( V_44 , V_9 , V_1 , V_4 , 1 , V_10 ) ;
F_5 ( V_44 , V_51 , V_1 , V_4 + 1 , 1 , V_10 ) ;
F_5 ( V_44 , V_52 , V_1 , V_4 + 2 , 2 , V_10 ) ;
V_4 += 4 ;
while ( ! V_47 ) {
if ( ! F_21 ( V_1 , V_4 , 1 ) )
break;
V_6 = F_2 ( V_1 , V_4 ) ;
V_46 = F_22 ( V_6 ) ;
switch ( V_46 ) {
case V_53 :
V_5 = F_11 ( V_1 , T_4 , V_44 , V_4 ) ;
break;
case V_54 :
V_5 = F_17 ( V_1 , T_4 , V_44 , V_4 ) ;
break;
default:
V_5 = F_1 ( V_1 , T_4 , V_44 , V_4 ) ;
break;
}
V_4 += V_5 ;
if ( V_5 < 0 )
V_47 = TRUE ;
}
}
void F_23 ( void )
{
static T_12 V_55 = {
& V_56 ,
{ L_10 , L_11 , V_57 , V_58 ,
F_24 ( V_59 ) , 0x0 , NULL , V_60 } ,
} ;
static T_12 V_61 [] = {
{ & V_42 ,
{ L_12 , L_13 , V_57 , V_62 ,
NULL , V_63 , NULL , V_60 }
} ,
{ & V_43 ,
{ L_14 , L_15 , V_57 , V_62 ,
NULL , V_64 , NULL , V_60 }
} ,
{ & V_9 ,
{ L_16 , L_17 , V_65 , V_58 ,
F_24 ( V_66 ) , 0x0 , NULL , V_60 } ,
} ,
{ & V_51 ,
{ L_18 , L_19 , V_65 , V_58 ,
F_24 ( V_67 ) , 0x0 , NULL , V_60 } ,
} ,
{ & V_52 ,
{ L_20 , L_21 , V_57 , V_58 ,
NULL , 0x0 , NULL , V_60 } ,
} ,
#if 0
{ &hf_ecp_vdp_oui,
{ "Organization Unique Code", "ecp.vdp.oui", FT_UINT24, BASE_HEX,
VALS(oui_vals), 0x0, NULL, HFILL }
},
#endif
{ & V_28 ,
{ L_18 , L_22 , V_65 , V_58 ,
F_24 ( V_68 ) , 0x0 , NULL , V_60 } ,
} ,
{ & V_29 ,
{ L_23 , L_24 , V_65 , V_58 ,
F_24 ( V_69 ) , 0x0 , NULL , V_60 } ,
} ,
{ & V_30 ,
{ L_25 , L_26 , V_65 , V_58 ,
NULL , 0x0 , NULL , V_60 } ,
} ,
{ & V_31 ,
{ L_27 , L_28 , V_70 , V_58 ,
NULL , 0x0 , NULL , V_60 } ,
} ,
{ & V_32 ,
{ L_29 , L_30 , V_65 , V_58 ,
NULL , 0x0 , NULL , V_60 } ,
} ,
{ & V_33 ,
{ L_31 , L_32 , V_71 , V_72 ,
NULL , 0x0 , NULL , V_60 } ,
} ,
{ & V_35 ,
{ L_33 , L_34 , V_65 , V_58 ,
F_24 ( V_73 ) , 0x0 , NULL , V_60 } ,
} ,
{ & V_16 ,
{ L_35 , L_36 , V_74 , V_72 ,
NULL , 0x0 , NULL , V_60 }
} ,
{ & V_17 ,
{ L_37 , L_38 , V_57 , V_62 ,
NULL , 0x0 , NULL , V_60 }
} ,
} ;
static T_8 * V_75 [] = {
& V_8 ,
& V_41 ,
& V_76 ,
} ;
F_25 ( V_26 , L_11 ,
L_39 , & V_55 ) ;
V_50 = F_26 ( L_40 , L_9 , L_41 ) ;
F_27 ( V_50 , V_61 , F_28 ( V_61 ) ) ;
F_29 ( V_75 , F_28 ( V_75 ) ) ;
F_30 ( L_41 , F_18 , V_50 ) ;
}
void F_31 ( void )
{
static T_13 V_77 ;
V_77 = F_32 ( L_41 ) ;
F_33 ( L_11 , 0x0000 , V_77 ) ;
}
