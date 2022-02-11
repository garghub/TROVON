static void
F_1 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 )
{
T_5 * V_4 ;
T_4 * V_5 ;
T_6 type ;
T_6 V_6 ;
T_7 V_7 ;
T_8 V_8 ;
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
}
static void
F_10 ( T_1 * V_1 , T_4 * V_3 , T_8 V_8 )
{
int V_17 = 5 ;
T_6 type , V_6 ;
T_5 * V_18 ;
T_4 * V_19 ;
int V_20 ;
while ( V_17 < V_8 )
{
type = F_3 ( V_1 , V_17 ++ ) ;
V_6 = F_3 ( V_1 , V_17 ++ ) ;
switch ( type )
{
case V_21 :
F_8 ( V_3 , V_22 , V_1 ,
V_17 , V_6 , V_13 ) ;
break;
case V_23 :
V_18 =
F_11 ( V_3 , V_1 , V_17 , V_6 , L_4 ) ;
V_19 =
F_7 ( V_18 , V_24 ) ;
V_20 = V_17 + V_6 ;
while ( V_17 < V_20 )
{
type = F_3 ( V_1 , V_17 ++ ) ;
V_6 = F_3 ( V_1 , V_17 ++ ) ;
switch ( type )
{
case V_25 :
if ( V_6 != 1 )
F_4 ( V_9 ) ;
F_8 ( V_19 ,
V_26 , V_1 ,
V_17 , V_6 , V_13 ) ;
break;
case V_27 :
if ( V_6 != 4 )
F_4 ( V_9 ) ;
F_8 ( V_19 ,
V_28 , V_1 ,
V_17 , V_6 , V_13 ) ;
break;
default:
F_4 ( V_9 ) ;
}
V_17 += V_6 ;
}
break;
case V_29 :
F_8 ( V_3 , V_30 , V_1 ,
V_17 , V_6 , V_31 | V_16 ) ;
}
V_17 += V_6 ;
}
}
void
F_12 ( void )
{
static T_9 V_32 [] = {
{ & V_12 ,
{ L_5 , L_6 ,
V_33 , V_34 , F_13 ( V_35 ) , 0x0 ,
L_7 , V_36 }
} ,
{ & V_15 ,
{ L_1 , L_8 ,
V_37 , V_38 , NULL , 0x0 ,
L_9 , V_36 }
} ,
{ & V_22 ,
{ L_10 , L_11 ,
V_39 , V_40 , NULL , 0x0 ,
NULL , V_36 }
} ,
{ & V_41 ,
{ L_12 , L_13 ,
V_37 , V_38 , NULL , 0x0 ,
NULL , V_36 }
} ,
{ & V_26 ,
{ L_14 , L_15 ,
V_39 , V_40 , NULL , 0x0 ,
NULL , V_36 }
} ,
{ & V_28 ,
{ L_16 , L_17 ,
V_39 , V_40 , NULL , 0x0 ,
NULL , V_36 }
} ,
{ & V_30 ,
{ L_18 , L_19 ,
V_42 , V_38 , NULL , 0x0 ,
NULL , V_36 }
} ,
} ;
static T_8 * V_43 [] = {
& V_11 ,
& V_24 ,
} ;
V_10 =
F_14 ( L_20 ,
L_21 , L_22 ) ;
F_15 ( V_10 , V_32 , F_16 ( V_32 ) ) ;
F_17 ( V_43 , F_16 ( V_43 ) ) ;
F_18 ( L_22 , F_1 , V_10 ) ;
}
void
F_19 ( void )
{
#if 0
dissector_handle_t docsis_vsif_handle;
docsis_vsif_handle = find_dissector ("docsis_vsif");
dissector_add_uint ("docsis", 0xFD, docsis_vsif_handle);
#endif
}
