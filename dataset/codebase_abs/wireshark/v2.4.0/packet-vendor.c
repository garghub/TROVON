static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_4 V_4 )
{
int V_5 = 5 ;
T_5 type , V_6 ;
T_3 * V_7 ;
T_6 * V_8 ;
int V_9 ;
while ( V_5 < V_4 )
{
type = F_2 ( V_1 , V_5 ++ ) ;
V_6 = F_2 ( V_1 , V_5 ++ ) ;
switch ( type )
{
case V_10 :
F_3 ( V_3 , V_11 , V_1 ,
V_5 , V_6 , V_12 ) ;
break;
case V_13 :
V_7 =
F_4 ( V_3 , V_1 , V_5 , V_6 , V_14 , & V_8 , L_1 ) ;
V_9 = V_5 + V_6 ;
while ( V_5 < V_9 )
{
type = F_2 ( V_1 , V_5 ++ ) ;
V_6 = F_2 ( V_1 , V_5 ++ ) ;
switch ( type )
{
case V_15 :
if ( V_6 == 1 )
{
F_3 ( V_7 ,
V_16 , V_1 ,
V_5 , V_6 , V_12 ) ;
}
else
{
F_5 ( V_2 , V_8 , & V_17 , L_2 , V_6 ) ;
}
break;
case V_18 :
if ( V_6 != 4 )
{
F_3 ( V_7 ,
V_19 , V_1 ,
V_5 , V_6 , V_12 ) ;
}
else
{
F_5 ( V_2 , V_8 , & V_17 , L_2 , V_6 ) ;
}
break;
default:
F_5 ( V_2 , V_8 , & V_20 , L_3 , type ) ;
}
V_5 += V_6 ;
}
break;
case V_21 :
F_3 ( V_3 , V_22 , V_1 ,
V_5 , V_6 , V_23 | V_24 ) ;
}
V_5 += V_6 ;
}
}
static int
F_6 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_7 V_25 )
{
T_6 * V_26 ;
T_3 * V_27 ;
T_5 type ;
T_5 V_6 ;
T_8 V_28 ;
T_4 V_4 ;
V_4 = F_7 ( V_1 , 0 ) ;
V_26 = F_8 ( V_3 , V_29 , V_1 , 0 , - 1 ,
L_4 ) ;
V_27 = F_9 ( V_26 , V_30 ) ;
F_10 ( V_27 , V_31 , V_1 , 2 , 3 , V_12 , & V_28 ) ;
type = F_2 ( V_1 , 0 ) ;
if ( type != 0x08 )
F_5 ( V_2 , V_26 , & V_20 , L_3 , type ) ;
V_6 = F_2 ( V_1 , 1 ) ;
if ( V_6 != 3 )
F_5 ( V_2 , V_26 , & V_17 , L_2 , V_6 ) ;
switch ( V_28 )
{
case V_32 :
F_11 ( V_26 , L_5 ) ;
F_1 ( V_1 , V_2 , V_27 , V_4 ) ;
break;
default:
F_11 ( V_26 , L_6 ) ;
F_3 ( V_27 , V_33 , V_1 ,
0 , - 1 , V_24 ) ;
break;
}
return F_12 ( V_1 ) ;
}
void
F_13 ( void )
{
static T_9 V_34 [] = {
{ & V_31 ,
{ L_7 , L_8 ,
V_35 , V_36 , F_14 ( V_37 ) , 0x0 ,
L_9 , V_38 }
} ,
{ & V_33 ,
{ L_4 , L_10 ,
V_39 , V_40 , NULL , 0x0 ,
L_11 , V_38 }
} ,
{ & V_11 ,
{ L_12 , L_13 ,
V_41 , V_42 , NULL , 0x0 ,
NULL , V_38 }
} ,
#if 0
{&hf_docsis_vsif_cisco_ipprec,
{"IP Precedence Encodings", "docsis_vsif.cisco.ipprec",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
#endif
{ & V_16 ,
{ L_14 , L_15 ,
V_41 , V_42 , NULL , 0x0 ,
NULL , V_38 }
} ,
{ & V_19 ,
{ L_16 , L_17 ,
V_41 , V_42 , NULL , 0x0 ,
NULL , V_38 }
} ,
{ & V_22 ,
{ L_18 , L_19 ,
V_43 , V_40 , NULL , 0x0 ,
NULL , V_38 }
} ,
} ;
static T_4 * V_44 [] = {
& V_30 ,
& V_14 ,
} ;
T_10 * V_45 ;
static T_11 V_46 [] = {
{ & V_17 , { L_20 , V_47 , V_48 , L_21 , V_49 } } ,
{ & V_20 , { L_22 , V_50 , V_51 , L_23 , V_49 } } ,
} ;
V_29 =
F_15 ( L_24 ,
L_25 , L_26 ) ;
F_16 ( V_29 , V_34 , F_17 ( V_34 ) ) ;
F_18 ( V_44 , F_17 ( V_44 ) ) ;
V_45 = F_19 ( V_29 ) ;
F_20 ( V_45 , V_46 , F_17 ( V_46 ) ) ;
F_21 ( L_26 , F_6 , V_29 ) ;
}
void
F_22 ( void )
{
#if 0
dissector_handle_t docsis_vsif_handle;
docsis_vsif_handle = find_dissector ("docsis_vsif");
dissector_add_uint ("docsis", 0xFD, docsis_vsif_handle);
#endif
}
