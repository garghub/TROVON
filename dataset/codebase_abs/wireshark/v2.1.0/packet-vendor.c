static int
F_1 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , void * T_5 V_2 )
{
T_6 * V_4 ;
T_4 * V_5 ;
T_7 type ;
T_7 V_6 ;
T_8 V_7 ;
T_9 V_8 ;
V_8 = F_2 ( V_1 , 0 ) ;
type = F_3 ( V_1 , 0 ) ;
if ( type != 0x08 )
{
F_4 ( V_9 ) ;
}
V_6 = F_3 ( V_1 , 1 ) ;
if ( V_6 != 3 )
{
F_4 ( V_9 ) ;
}
V_7 = F_5 ( V_1 , 2 ) ;
if ( V_3 )
{
V_4 =
F_6 ( V_3 , V_10 , V_1 , 0 , - 1 ,
L_1 ) ;
V_5 = F_7 ( V_4 , V_11 ) ;
F_8 ( V_5 , V_12 , V_1 , 2 , 3 , V_13 ) ;
switch ( V_7 )
{
case V_14 :
F_9 ( V_4 , L_2 ) ;
F_10 ( V_1 , V_5 , V_8 ) ;
break;
default:
F_9 ( V_4 , L_3 ) ;
F_8 ( V_5 , V_15 , V_1 ,
0 , - 1 , V_16 ) ;
break;
}
}
return F_11 ( V_1 ) ;
}
static void
F_10 ( T_1 * V_1 , T_4 * V_3 , T_9 V_8 )
{
int V_17 = 5 ;
T_7 type , V_6 ;
T_4 * V_18 ;
int V_19 ;
while ( V_17 < V_8 )
{
type = F_3 ( V_1 , V_17 ++ ) ;
V_6 = F_3 ( V_1 , V_17 ++ ) ;
switch ( type )
{
case V_20 :
F_8 ( V_3 , V_21 , V_1 ,
V_17 , V_6 , V_13 ) ;
break;
case V_22 :
V_18 =
F_12 ( V_3 , V_1 , V_17 , V_6 , V_23 , NULL , L_4 ) ;
V_19 = V_17 + V_6 ;
while ( V_17 < V_19 )
{
type = F_3 ( V_1 , V_17 ++ ) ;
V_6 = F_3 ( V_1 , V_17 ++ ) ;
switch ( type )
{
case V_24 :
if ( V_6 != 1 )
F_4 ( V_9 ) ;
F_8 ( V_18 ,
V_25 , V_1 ,
V_17 , V_6 , V_13 ) ;
break;
case V_26 :
if ( V_6 != 4 )
F_4 ( V_9 ) ;
F_8 ( V_18 ,
V_27 , V_1 ,
V_17 , V_6 , V_13 ) ;
break;
default:
F_4 ( V_9 ) ;
}
V_17 += V_6 ;
}
break;
case V_28 :
F_8 ( V_3 , V_29 , V_1 ,
V_17 , V_6 , V_30 | V_16 ) ;
}
V_17 += V_6 ;
}
}
void
F_13 ( void )
{
static T_10 V_31 [] = {
{ & V_12 ,
{ L_5 , L_6 ,
V_32 , V_33 , F_14 ( V_34 ) , 0x0 ,
L_7 , V_35 }
} ,
{ & V_15 ,
{ L_1 , L_8 ,
V_36 , V_37 , NULL , 0x0 ,
L_9 , V_35 }
} ,
{ & V_21 ,
{ L_10 , L_11 ,
V_38 , V_39 , NULL , 0x0 ,
NULL , V_35 }
} ,
#if 0
{&hf_docsis_vsif_cisco_ipprec,
{"IP Precedence Encodings", "docsis_vsif.cisco.ipprec",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
#endif
{ & V_25 ,
{ L_12 , L_13 ,
V_38 , V_39 , NULL , 0x0 ,
NULL , V_35 }
} ,
{ & V_27 ,
{ L_14 , L_15 ,
V_38 , V_39 , NULL , 0x0 ,
NULL , V_35 }
} ,
{ & V_29 ,
{ L_16 , L_17 ,
V_40 , V_37 , NULL , 0x0 ,
NULL , V_35 }
} ,
} ;
static T_9 * V_41 [] = {
& V_11 ,
& V_23 ,
} ;
V_10 =
F_15 ( L_18 ,
L_19 , L_20 ) ;
F_16 ( V_10 , V_31 , F_17 ( V_31 ) ) ;
F_18 ( V_41 , F_17 ( V_41 ) ) ;
F_19 ( L_20 , F_1 , V_10 ) ;
}
void
F_20 ( void )
{
#if 0
dissector_handle_t docsis_vsif_handle;
docsis_vsif_handle = find_dissector ("docsis_vsif");
dissector_add_uint ("docsis", 0xFD, docsis_vsif_handle);
#endif
}
