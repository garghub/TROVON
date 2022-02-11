T_1
F_1 ( T_1 V_1 , T_1 V_2 )
{
switch ( V_1 ) {
case V_3 :
return V_4 ;
case V_5 :
if ( V_2 == V_6 )
return V_7 ;
return V_8 ;
case V_9 :
if ( V_2 == V_10 )
return V_11 ;
else if ( V_2 == V_12 )
return V_13 ;
else if ( V_2 == V_14 )
return V_15 ;
else return V_8 ;
case V_16 :
if ( V_2 == V_17 )
return V_18 ;
return V_8 ;
case V_19 :
if ( V_2 == V_20 )
return V_21 ;
else if ( V_2 == V_22 )
return V_23 ;
return V_8 ;
case V_24 :
if ( V_2 == V_25 )
return ( V_24 ) ;
else return ( V_8 ) ;
default:
return V_8 ;
}
}
static int
F_2 ( T_2 * V_26 , T_3 * V_27 , T_4 * V_28 , void * V_29 )
{
T_5 * V_30 ;
T_4 * V_31 ;
T_2 * V_32 ;
int V_33 ,
V_34 = 0 ;
T_1 V_35 ;
T_6 V_36 ;
F_3 ( V_27 -> V_37 , V_38 , L_1 ) ;
F_4 ( V_26 , ( T_1 * ) & V_36 , V_34 , V_39 ) ;
V_36 . V_40 = F_5 ( V_26 , V_34 ++ ) ;
V_36 . V_33 = F_6 ( V_26 , V_34 ) ;
V_36 . V_41 = F_7 ( V_36 . V_41 ) ;
V_36 . V_42 = F_7 ( V_36 . V_42 ) ;
if ( V_36 . V_41 < V_43 ) {
F_8 ( V_27 -> V_37 , V_44 , L_2 ) ;
}
else if ( V_36 . V_41 == V_45 ) {
F_8 ( V_27 -> V_37 , V_44 , L_3 ) ;
}
else if ( V_36 . V_41 == V_46 ) {
F_9 ( V_27 -> V_37 , V_44 , L_4 ,
F_10 ( V_36 . V_47 , V_48 , L_5 ) ) ;
}
else {
F_8 ( V_27 -> V_37 , V_44 , L_6 ) ;
}
V_33 = V_36 . V_33 ;
V_33 = F_11 ( V_33 ) >> 8 ;
V_35 = F_1 ( V_36 . V_1 , V_36 . V_2 ) ;
if ( V_28 ) {
V_34 = 0 ;
V_30 = F_12 ( V_28 , V_49 , V_26 , 0 , V_39 ,
L_1 ) ;
V_31 = F_13 ( V_30 , V_50 ) ;
F_14 ( V_31 , V_51 , V_26 , V_34 ++ ,
sizeof ( T_1 ) , V_52 ) ;
F_15 ( V_31 , V_53 , V_26 , V_34 , 3 ,
F_16 ( ( T_1 * ) & V_33 ) ) ;
V_34 += 3 ;
F_14 ( V_31 , V_54 , V_26 , V_34 ++ ,
sizeof ( T_1 ) , V_52 ) ;
F_14 ( V_31 , V_55 , V_26 , V_34 ,
sizeof ( T_1 ) , V_52 ) ;
F_17 ( V_31 , V_56 , V_26 , V_34 ++ , 1 ,
V_35 ) ;
F_14 ( V_31 , V_57 , V_26 , V_34 ++ ,
sizeof ( T_1 ) , V_52 ) ;
}
V_32 = F_18 ( V_26 , 0 ) ;
if ( ! F_19 ( V_58 , V_35 , V_32 , V_27 ,
V_28 , TRUE , V_29 ) ) {
F_20 ( V_59 , V_32 , V_27 , V_28 ) ;
}
return F_21 ( V_26 ) ;
}
void
F_22 ( void )
{
static T_7 V_60 [] = {
{ & V_51 ,
{ L_7 , L_8 , V_61 , V_62 , NULL , 0x0 , NULL , V_63 } } ,
{ & V_53 ,
{ L_9 , L_10 , V_64 , V_65 , NULL , 0x0 , NULL , V_63 } } ,
{ & V_54 ,
{ L_11 , L_12 , V_61 , V_66 , F_23 ( V_67 ) ,
0x0 , NULL , V_63 } } ,
{ & V_55 ,
{ L_13 , L_14 , V_61 , V_66 , NULL , 0x0 ,
NULL , V_63 } } ,
{ & V_56 ,
{ L_15 , L_16 , V_61 , V_66 ,
F_23 ( V_68 ) , 0x0 ,
L_17 , V_63 } } ,
{ & V_57 ,
{ L_18 , L_19 , V_61 , V_66 , NULL , 0x0 , NULL ,
V_63 } } ,
#if 0
{ &hf_fcct_ext_said,
{"Auth SAID", "fcct.ext_said", FT_UINT32, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_fcct_ext_tid,
{"Transaction ID", "fcct.ext_tid", FT_UINT32, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_fcct_ext_reqname,
{"Requestor Port Name", "fcct.ext_reqnm", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_fcct_ext_tstamp,
{"Timestamp", "fcct.ext_tstamp", FT_BYTES, BASE_NONE, NULL, 0x0, NULL,
HFILL}},
{ &hf_fcct_ext_authblk,
{"Auth Hash Blk", "fcct.ext_authblk", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
#endif
} ;
static T_8 * V_69 [] = {
& V_50 ,
& V_70 ,
} ;
V_49 = F_24 ( L_20 , L_1 , L_21 ) ;
F_25 ( V_49 , V_60 , F_26 ( V_60 ) ) ;
F_27 ( V_69 , F_26 ( V_69 ) ) ;
V_58 = F_28 ( L_16 ,
L_22 ,
V_61 , V_66 ) ;
}
void
F_29 ( void )
{
T_9 V_71 ;
V_71 = F_30 ( F_2 , V_49 ) ;
F_31 ( L_23 , V_72 , V_71 ) ;
V_59 = F_32 ( L_24 ) ;
}
