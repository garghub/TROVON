static int
F_1 ( T_1 * V_1 , int V_2 , T_2 * T_3 V_3 , T_4 * V_4 )
{
T_5 V_5 ;
V_5 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_6 , V_1 , V_2 , 2 , V_7 ) ;
V_2 += 2 ;
switch ( V_5 ) {
case 0x0000 :
break;
default:
break;
}
return V_2 ;
}
static int
F_4 ( T_1 * V_1 , int V_2 , T_2 * T_3 V_3 , T_4 * V_4 )
{
F_3 ( V_4 , V_8 , V_1 , V_2 , 2 , V_7 ) ;
V_2 += 2 ;
F_3 ( V_4 , V_9 , V_1 , V_2 , 2 , V_7 ) ;
V_2 += 2 ;
return V_2 ;
}
static int
F_5 ( T_1 * V_1 , int V_2 , T_2 * T_3 V_3 , T_4 * V_4 , T_5 V_10 )
{
T_6 * V_11 ;
T_4 * V_12 ;
V_11 = F_6 ( V_4 ,
V_13 , V_1 ,
V_2 , 3 ,
L_1 , V_10 ) ;
V_12 = F_7 ( V_11 , V_14 ) ;
F_3 ( V_12 , V_15 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
F_3 ( V_12 , V_16 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
F_3 ( V_12 , V_17 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
return V_2 ;
}
static int
F_8 ( T_1 * V_1 , int V_2 , T_2 * T_3 , T_4 * V_4 )
{
T_5 V_18 ;
T_5 V_10 = 1 ;
T_6 * V_19 ;
T_4 * V_20 ;
F_3 ( V_4 , V_8 , V_1 , V_2 , 2 , V_7 ) ;
V_2 += 2 ;
F_3 ( V_4 , V_9 , V_1 , V_2 , 2 , V_7 ) ;
V_2 += 2 ;
V_18 = F_9 ( V_1 , V_2 ) ;
V_19 = F_6 ( V_4 ,
V_21 , V_1 ,
V_2 , V_18 ,
L_2 ) ;
V_20 = F_7 ( V_19 , V_22 ) ;
while ( F_9 ( V_1 , V_2 ) >= 3 ) {
V_2 = F_5 ( V_1 , V_2 , T_3 , V_20 , V_10 ) ;
V_10 += 1 ;
}
return V_2 ;
}
static int
F_10 ( T_1 * V_1 , int V_2 , T_2 * T_3 , T_4 * V_4 )
{
T_5 V_18 ;
T_5 V_10 = 1 ;
T_6 * V_19 ;
T_4 * V_20 ;
V_18 = F_9 ( V_1 , V_2 ) ;
V_19 = F_6 ( V_4 ,
V_21 , V_1 ,
V_2 , V_18 ,
L_2 ) ;
V_20 = F_7 ( V_19 , V_22 ) ;
while ( F_9 ( V_1 , V_2 ) >= 3 ) {
V_2 = F_5 ( V_1 , V_2 , T_3 , V_20 , V_10 ) ;
V_10 += 1 ;
}
return V_2 ;
}
static int
F_11 ( T_1 * V_1 V_3 , int V_2 , T_2 * T_3 V_3 , T_4 * V_4 V_3 )
{
return V_2 ;
}
static int
F_12 ( T_1 * V_1 , int V_2 , T_2 * T_3 V_3 , T_4 * V_4 )
{
F_3 ( V_4 , V_15 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
return V_2 ;
}
static int
F_13 ( T_1 * V_1 , int V_2 , T_2 * T_3 V_3 , T_4 * V_4 )
{
T_6 * V_23 ;
T_4 * V_24 ;
F_3 ( V_4 , V_15 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
F_3 ( V_4 , V_25 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
F_3 ( V_4 , V_26 , V_1 , V_2 , 4 , V_7 ) ;
V_2 += 4 ;
F_3 ( V_4 , V_27 , V_1 , V_2 , 4 , V_7 ) ;
V_2 += 4 ;
F_3 ( V_4 , V_28 , V_1 , V_2 , 4 , V_7 ) ;
V_2 += 4 ;
V_23 = F_6 ( V_4 ,
V_29 , V_1 ,
V_2 , 2 ,
L_3 ) ;
V_24 = F_7 ( V_23 , V_30 ) ;
F_3 ( V_24 , V_31 , V_1 , V_2 , 2 , V_7 ) ;
V_2 += 2 ;
F_3 ( V_4 , V_32 , V_1 , V_2 , 2 , V_7 ) ;
V_2 += 2 ;
return V_2 ;
}
static int
F_14 ( T_1 * V_1 , int V_2 , T_2 * T_3 V_3 , T_4 * V_4 )
{
F_3 ( V_4 , V_15 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
return V_2 ;
}
static int
F_15 ( T_1 * V_1 , int V_2 , T_2 * T_3 V_3 , T_4 * V_4 )
{
F_3 ( V_4 , V_33 , V_1 , V_2 , F_9 ( V_1 , V_2 ) , V_34 ) ;
return F_16 ( V_1 ) ;
}
static int
F_17 ( T_1 * V_1 , int V_2 , T_2 * T_3 , T_4 * V_4 )
{
F_3 ( V_4 , V_15 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
F_3 ( V_4 , V_25 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
V_2 = F_15 ( V_1 , V_2 , T_3 , V_4 ) ;
return V_2 ;
}
static int
F_18 ( T_1 * V_1 , int V_2 , T_2 * T_3 , T_4 * V_4 )
{
F_3 ( V_4 , V_35 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
F_3 ( V_4 , V_36 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
V_2 = F_15 ( V_1 , V_2 , T_3 , V_4 ) ;
return V_2 ;
}
static int
F_19 ( T_1 * V_1 , int V_2 , T_2 * T_3 V_3 , T_4 * V_4 )
{
F_3 ( V_4 , V_35 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
F_3 ( V_4 , V_36 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
F_3 ( V_4 , V_25 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
return V_2 ;
}
static int
F_20 ( T_1 * V_1 , int V_2 , T_2 * T_3 V_3 , T_4 * V_4 )
{
F_3 ( V_4 , V_35 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
F_3 ( V_4 , V_36 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
return V_2 ;
}
static int
F_21 ( T_1 * V_1 , int V_2 , T_2 * T_3 V_3 , T_4 * V_4 )
{
F_3 ( V_4 , V_35 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
F_3 ( V_4 , V_36 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
F_3 ( V_4 , V_17 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
return V_2 ;
}
static int
F_22 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_4 , void * T_7 V_3 )
{
int V_2 = 0 ;
T_4 * V_37 = NULL ;
T_5 V_18 ;
T_6 * V_38 ;
T_4 * V_39 ;
T_8 V_40 ;
T_5 V_41 ;
F_23 ( T_3 -> V_42 , V_43 , L_4 ) ;
switch ( T_3 -> V_44 ) {
case V_45 :
F_24 ( T_3 -> V_42 , V_46 , L_5 ) ;
break;
case V_47 :
F_24 ( T_3 -> V_42 , V_46 , L_6 ) ;
break;
default:
F_25 ( T_3 -> V_42 , V_46 , L_7 ,
T_3 -> V_44 ) ;
break;
}
if ( V_4 ) {
T_6 * V_48 ;
V_48 = F_3 ( V_4 , V_49 , V_1 , V_2 , - 1 , V_34 ) ;
V_37 = F_7 ( V_48 , V_50 ) ;
}
V_18 = F_9 ( V_1 , V_2 ) ;
V_38 = F_6 ( V_37 ,
V_51 , V_1 ,
V_2 , V_18 ,
L_8 ) ;
V_39 = F_7 ( V_38 , V_52 ) ;
V_40 = F_26 ( V_1 , V_2 ) ;
F_3 ( V_39 , V_53 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
F_3 ( V_39 , V_54 , V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
V_41 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_39 , V_55 , V_1 , V_2 , 2 , V_7 ) ;
F_27 ( V_38 , V_41 + 4 ) ;
V_2 += 2 ;
switch( V_40 ) {
case 0x01 :
V_2 = F_1 ( V_1 , V_2 , T_3 , V_39 ) ;
break;
case 0x02 :
V_2 = F_4 ( V_1 , V_2 , T_3 , V_39 ) ;
break;
case 0x03 :
V_2 = F_8 ( V_1 , V_2 , T_3 , V_39 ) ;
break;
case 0x04 :
V_2 = F_10 ( V_1 , V_2 , T_3 , V_39 ) ;
break;
case 0x05 :
V_2 = F_11 ( V_1 , V_2 , T_3 , V_39 ) ;
break;
case 0x06 :
V_2 = F_12 ( V_1 , V_2 , T_3 , V_39 ) ;
break;
case 0x07 :
V_2 = F_13 ( V_1 , V_2 , T_3 , V_39 ) ;
break;
case 0x08 :
V_2 = F_14 ( V_1 , V_2 , T_3 , V_39 ) ;
break;
case 0x09 :
V_2 = F_17 ( V_1 , V_2 , T_3 , V_39 ) ;
break;
case 0x0A :
V_2 = F_18 ( V_1 , V_2 , T_3 , V_39 ) ;
break;
case 0x0B :
V_2 = F_19 ( V_1 , V_2 , T_3 , V_39 ) ;
break;
case 0x0c :
V_2 = F_20 ( V_1 , V_2 , T_3 , V_39 ) ;
break;
case 0x0d :
V_2 = F_21 ( V_1 , V_2 , T_3 , V_39 ) ;
break;
default:
F_3 ( V_39 , V_56 , V_1 , V_2 , - 1 , V_34 ) ;
V_2 = F_16 ( V_1 ) ;
break;
}
F_28 ( V_38 , L_9 , F_29 ( V_40 , V_57 , L_10 ) ) ;
F_30 ( T_3 -> V_42 , V_46 , F_29 ( V_40 , V_57 , L_10 ) ) ;
return V_2 ;
}
void
F_31 ( void )
{
static T_9 V_58 [] = {
{ & V_51 ,
{ L_11 , L_12 ,
V_59 , V_60 , NULL , 0x0 ,
L_13 , V_61 }
} ,
{ & V_53 ,
{ L_14 , L_15 ,
V_62 , V_63 , F_32 ( V_57 ) , 0x0 ,
L_16 , V_61 }
} ,
{ & V_54 ,
{ L_17 , L_18 ,
V_62 , V_63 , NULL , 0x0 ,
L_19 , V_61 }
} ,
{ & V_55 ,
{ L_20 , L_21 ,
V_62 , V_64 , NULL , 0x0 ,
L_22 , V_61 }
} ,
{ & V_56 ,
{ L_23 , L_24 ,
V_59 , V_60 , NULL , 0x0 ,
L_25 , V_61 }
} ,
{ & V_6 ,
{ L_26 , L_27 ,
V_65 , V_63 , F_32 ( V_66 ) , 0x0 ,
NULL , V_61 }
} ,
{ & V_8 ,
{ L_28 , L_29 ,
V_65 , V_63 , NULL , 0x0 ,
L_30 , V_61 }
} ,
{ & V_9 ,
{ L_31 , L_32 ,
V_65 , V_63 , NULL , 0x0 ,
L_33 , V_61 }
} ,
{ & V_13 ,
{ L_34 , L_35 ,
V_59 , V_60 , NULL , 0x0 ,
NULL , V_61 }
} ,
{ & V_21 ,
{ L_2 , L_36 ,
V_59 , V_60 , NULL , 0x0 ,
NULL , V_61 }
} ,
{ & V_35 ,
{ L_37 , L_38 ,
V_62 , V_64 , NULL , 0x0 ,
NULL , V_61 }
} ,
{ & V_36 ,
{ L_39 , L_40 ,
V_62 , V_64 , NULL , 0x0 ,
NULL , V_61 }
} ,
{ & V_15 ,
{ L_41 , L_42 ,
V_62 , V_64 , NULL , 0x0 ,
NULL , V_61 }
} ,
{ & V_16 ,
{ L_43 , L_44 ,
V_62 , V_64 , F_32 ( V_67 ) , 0x0 ,
NULL , V_61 }
} ,
{ & V_17 ,
{ L_45 , L_46 ,
V_62 , V_64 , F_32 ( V_68 ) , 0x0 ,
NULL , V_61 }
} ,
{ & V_25 ,
{ L_47 , L_48 ,
V_62 , V_64 , F_32 ( V_69 ) , 0x0 ,
NULL , V_61 }
} ,
#if 0
{ &hf_btamp_create_status,
{ "Status", "btamp.create_status",
FT_UINT8, BASE_DEC, VALS(create_status_vals), 0x0,
NULL, HFILL }
},
{ &hf_btamp_disc_status,
{ "Status", "btamp.disc_status",
FT_UINT8, BASE_DEC, VALS(disc_status_vals), 0x0,
NULL, HFILL }
},
#endif
{ & V_29 ,
{ L_49 , L_50 ,
V_59 , V_60 , NULL , 0x0 ,
NULL , V_61 }
} ,
{ & V_31 ,
{ L_51 , L_52 ,
V_70 , 16 , NULL , 0x01 ,
NULL , V_61 }
} ,
{ & V_26 ,
{ L_53 , L_54 ,
V_71 , V_63 , NULL , 0x0 ,
NULL , V_61 }
} ,
{ & V_27 ,
{ L_55 , L_56 ,
V_71 , V_63 , NULL , 0x0 ,
NULL , V_61 }
} ,
{ & V_28 ,
{ L_57 , L_58 ,
V_71 , V_63 , NULL , 0x0 ,
NULL , V_61 }
} ,
{ & V_32 ,
{ L_59 , L_60 ,
V_65 , V_63 , NULL , 0x0 ,
NULL , V_61 }
} ,
{ & V_33 ,
{ L_61 , L_62 ,
V_72 , V_60 , NULL , 0x0 ,
NULL , V_61 }
} ,
} ;
static T_10 * V_73 [] = {
& V_50 ,
& V_52 ,
& V_30 ,
& V_14 ,
& V_22 ,
} ;
V_49 = F_33 ( L_63 , L_64 , L_65 ) ;
F_34 ( L_65 , F_22 , V_49 ) ;
F_35 ( V_49 , V_58 , F_36 ( V_58 ) ) ;
F_37 ( V_73 , F_36 ( V_73 ) ) ;
}
void
F_38 ( void )
{
T_11 V_74 ;
V_74 = F_39 ( L_65 ) ;
F_40 ( L_66 , V_75 , V_74 ) ;
}
