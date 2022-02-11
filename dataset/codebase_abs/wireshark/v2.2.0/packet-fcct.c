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
T_7 V_37 ;
F_3 ( V_27 -> V_38 , V_39 , L_1 ) ;
F_4 ( V_26 , ( T_1 * ) & V_36 , V_34 , V_40 ) ;
V_36 . V_41 = F_5 ( V_26 , V_34 ++ ) ;
V_36 . V_33 = F_6 ( V_26 , V_34 ) ;
V_36 . V_42 = F_7 ( V_36 . V_42 ) ;
V_36 . V_43 = F_7 ( V_36 . V_43 ) ;
if ( V_36 . V_42 < V_44 ) {
F_8 ( V_27 -> V_38 , V_45 , L_2 ) ;
}
else if ( V_36 . V_42 == V_46 ) {
F_8 ( V_27 -> V_38 , V_45 , L_3 ) ;
}
else if ( V_36 . V_42 == V_47 ) {
F_9 ( V_27 -> V_38 , V_45 , L_4 ,
F_10 ( V_36 . V_48 , V_49 , L_5 ) ) ;
}
else {
F_8 ( V_27 -> V_38 , V_45 , L_6 ) ;
}
V_33 = V_36 . V_33 ;
V_33 = F_11 ( V_33 ) >> 8 ;
V_35 = F_1 ( V_36 . V_1 , V_36 . V_2 ) ;
if ( V_28 ) {
V_34 = 0 ;
V_30 = F_12 ( V_28 , V_50 , V_26 , 0 , V_40 ,
L_1 ) ;
V_31 = F_13 ( V_30 , V_51 ) ;
F_14 ( V_31 , V_52 , V_26 , V_34 ++ ,
sizeof ( T_1 ) , V_53 ) ;
F_15 ( & V_37 , V_54 , 3 , & V_33 ) ;
F_16 ( V_31 , V_55 , V_26 , V_34 , 3 ,
F_17 ( F_18 () , & V_37 ) ) ;
V_34 += 3 ;
F_14 ( V_31 , V_56 , V_26 , V_34 ++ ,
sizeof ( T_1 ) , V_53 ) ;
F_14 ( V_31 , V_57 , V_26 , V_34 ,
sizeof ( T_1 ) , V_53 ) ;
F_19 ( V_31 , V_58 , V_26 , V_34 ++ , 1 ,
V_35 ) ;
F_14 ( V_31 , V_59 , V_26 , V_34 ++ ,
sizeof ( T_1 ) , V_53 ) ;
}
V_32 = F_20 ( V_26 , 0 ) ;
if ( ! F_21 ( V_60 , V_35 , V_32 , V_27 ,
V_28 , TRUE , V_29 ) ) {
F_22 ( V_32 , V_27 , V_28 ) ;
}
return F_23 ( V_26 ) ;
}
void
F_24 ( void )
{
static T_8 V_61 [] = {
{ & V_52 ,
{ L_7 , L_8 , V_62 , V_63 , NULL , 0x0 , NULL , V_64 } } ,
{ & V_55 ,
{ L_9 , L_10 , V_65 , V_66 , NULL , 0x0 , NULL , V_64 } } ,
{ & V_56 ,
{ L_11 , L_12 , V_62 , V_67 , F_25 ( V_68 ) ,
0x0 , NULL , V_64 } } ,
{ & V_57 ,
{ L_13 , L_14 , V_62 , V_67 , NULL , 0x0 ,
NULL , V_64 } } ,
{ & V_58 ,
{ L_15 , L_16 , V_62 , V_67 ,
F_25 ( V_69 ) , 0x0 ,
L_17 , V_64 } } ,
{ & V_59 ,
{ L_18 , L_19 , V_62 , V_67 , NULL , 0x0 , NULL ,
V_64 } } ,
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
static T_9 * V_70 [] = {
& V_51 ,
& V_71 ,
} ;
V_50 = F_26 ( L_20 , L_1 , L_21 ) ;
F_27 ( V_50 , V_61 , F_28 ( V_61 ) ) ;
F_29 ( V_70 , F_28 ( V_70 ) ) ;
V_60 = F_30 ( L_16 ,
L_22 ,
V_50 , V_62 , V_67 ) ;
}
void
F_31 ( void )
{
T_10 V_72 ;
V_72 = F_32 ( F_2 , V_50 ) ;
F_33 ( L_23 , V_73 , V_72 ) ;
}
