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
T_5 * V_14 ;
V_12 = F_2 ( V_1 , V_4 ) ;
V_14 = F_7 ( V_3 , V_1 , V_13 , 2 , V_8 , NULL ,
L_2 , V_12 , F_8 ( V_12 , L_3 , L_4 ) ) ;
V_13 += 2 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
F_5 ( V_14 , V_15 , V_1 , V_13 , 6 , V_16 ) ;
V_13 += 6 ;
F_5 ( V_14 , V_17 , V_1 , V_13 , 2 , V_10 ) ;
V_13 += 2 ;
}
return V_13 - V_4 ;
}
static T_1
F_9 ( T_2 * V_1 , T_3 * T_4 , T_5 * V_3 , T_6 V_4 )
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
V_19 = F_10 ( V_1 , ( V_13 ) ) ;
V_20 = F_11 ( V_19 , V_25 , L_5 ) ;
if ( strcmp ( V_20 , L_5 ) == 0 ) {
V_20 = F_12 ( V_19 ) ;
if( V_20 == NULL ) V_20 = L_5 ;
}
V_13 += 3 ;
V_21 = F_13 ( V_1 , V_13 ) ;
V_13 ++ ;
switch( V_19 ) {
case V_26 :
V_23 = F_14 ( V_21 , V_27 , L_6 ) ;
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
F_5 ( V_24 , V_33 , V_1 , V_13 , 16 , V_16 ) ;
V_13 += 16 ;
V_22 = F_13 ( V_1 , V_13 ) ;
F_5 ( V_24 , V_34 , V_1 , V_13 , 1 , V_10 ) ;
V_13 ++ ;
switch ( V_22 ) {
case V_35 :
case V_36 :
V_5 = F_6 ( V_1 , T_4 , V_24 , V_13 ) ;
break;
case V_37 :
break;
case V_38 :
break;
default:
break;
}
V_13 += V_5 ;
return V_13 - V_4 ;
}
static T_1
F_15 ( T_2 * V_1 , T_3 * T_4 V_2 , T_5 * V_3 , T_6 V_4 )
{
T_7 V_5 ;
T_7 V_6 ;
T_5 * V_39 ;
V_6 = F_2 ( V_1 , V_4 ) ;
V_5 = F_3 ( V_6 ) ;
if ( V_3 )
{
V_39 = F_4 ( V_3 , V_1 , V_4 , ( V_5 + 2 ) ,
V_40 , NULL , L_8 ) ;
F_5 ( V_39 , V_41 , V_1 , V_4 , 2 , V_10 ) ;
F_5 ( V_39 , V_42 , V_1 , V_4 , 2 , V_10 ) ;
}
return - 1 ;
}
static int
F_16 ( T_2 * V_1 , T_3 * T_4 , T_5 * V_3 , void * T_10 V_2 )
{
T_5 * V_43 ;
T_11 * V_44 ;
T_1 V_5 = 0 ;
T_6 V_4 = 0 ;
T_7 V_6 ;
T_9 V_45 ;
T_12 V_46 = FALSE ;
F_17 ( T_4 -> V_47 , V_48 , L_9 ) ;
V_44 = F_5 ( V_3 , V_49 , V_1 , 0 , - 1 , V_16 ) ;
V_43 = F_18 ( V_44 , V_8 ) ;
F_5 ( V_43 , V_9 , V_1 , V_4 , 1 , V_10 ) ;
F_5 ( V_43 , V_50 , V_1 , V_4 + 1 , 1 , V_10 ) ;
F_5 ( V_43 , V_51 , V_1 , V_4 + 2 , 2 , V_10 ) ;
V_4 += 4 ;
while ( ! V_46 ) {
if ( ! F_19 ( V_1 , V_4 , 1 ) )
break;
V_6 = F_2 ( V_1 , V_4 ) ;
V_45 = F_20 ( V_6 ) ;
switch ( V_45 ) {
case V_52 :
V_5 = F_9 ( V_1 , T_4 , V_43 , V_4 ) ;
break;
case V_53 :
V_5 = F_15 ( V_1 , T_4 , V_43 , V_4 ) ;
break;
default:
V_5 = F_1 ( V_1 , T_4 , V_43 , V_4 ) ;
break;
}
V_4 += V_5 ;
if ( V_5 < 0 )
V_46 = TRUE ;
}
return F_21 ( V_1 ) ;
}
void F_22 ( void )
{
static T_13 V_54 = {
& V_55 ,
{ L_10 , L_11 , V_56 , V_57 ,
F_23 ( V_58 ) , 0x0 , NULL , V_59 } ,
} ;
static T_13 V_60 [] = {
{ & V_41 ,
{ L_12 , L_13 , V_56 , V_61 ,
NULL , V_62 , NULL , V_59 }
} ,
{ & V_42 ,
{ L_14 , L_15 , V_56 , V_61 ,
NULL , V_63 , NULL , V_59 }
} ,
{ & V_9 ,
{ L_16 , L_17 , V_64 , V_57 ,
F_23 ( V_65 ) , 0x0 , NULL , V_59 } ,
} ,
{ & V_50 ,
{ L_18 , L_19 , V_64 , V_57 ,
F_23 ( V_66 ) , 0x0 , NULL , V_59 } ,
} ,
{ & V_51 ,
{ L_20 , L_21 , V_56 , V_57 ,
NULL , 0x0 , NULL , V_59 } ,
} ,
#if 0
{ &hf_ecp_vdp_oui,
{ "Organization Unique Code", "ecp.vdp.oui", FT_UINT24, BASE_HEX,
VALS(oui_vals), 0x0, NULL, HFILL }
},
#endif
{ & V_28 ,
{ L_18 , L_22 , V_64 , V_57 ,
F_23 ( V_67 ) , 0x0 , NULL , V_59 } ,
} ,
{ & V_29 ,
{ L_23 , L_24 , V_64 , V_57 ,
F_23 ( V_68 ) , 0x0 , NULL , V_59 } ,
} ,
{ & V_30 ,
{ L_25 , L_26 , V_64 , V_57 ,
NULL , 0x0 , NULL , V_59 } ,
} ,
{ & V_31 ,
{ L_27 , L_28 , V_69 , V_57 ,
NULL , 0x0 , NULL , V_59 } ,
} ,
{ & V_32 ,
{ L_29 , L_30 , V_64 , V_57 ,
NULL , 0x0 , NULL , V_59 } ,
} ,
{ & V_33 ,
{ L_31 , L_32 , V_70 , V_71 ,
NULL , 0x0 , NULL , V_59 } ,
} ,
{ & V_34 ,
{ L_33 , L_34 , V_64 , V_57 ,
F_23 ( V_72 ) , 0x0 , NULL , V_59 } ,
} ,
{ & V_15 ,
{ L_35 , L_36 , V_73 , V_71 ,
NULL , 0x0 , NULL , V_59 }
} ,
{ & V_17 ,
{ L_37 , L_38 , V_56 , V_61 ,
NULL , 0x0 , NULL , V_59 }
} ,
} ;
static T_8 * V_74 [] = {
& V_8 ,
& V_40 ,
& V_75 ,
} ;
V_49 = F_24 ( L_39 , L_9 , L_40 ) ;
F_25 ( V_49 , V_60 , F_26 ( V_60 ) ) ;
F_27 ( V_74 , F_26 ( V_74 ) ) ;
F_28 ( V_26 , L_11 ,
L_41 , & V_54 , V_49 ) ;
F_29 ( L_40 , F_16 , V_49 ) ;
}
void F_30 ( void )
{
static T_14 V_76 ;
V_76 = F_31 ( L_40 ) ;
F_32 ( L_11 , 0x0000 , V_76 ) ;
}
