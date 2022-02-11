static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
T_6 * V_6 ;
T_3 * V_7 ;
T_1 * V_8 ;
T_7 type ;
F_2 ( V_2 -> V_9 , V_10 , L_1 ) ;
F_3 ( V_2 -> V_9 , V_11 ) ;
F_4 ( & V_2 -> V_12 , V_13 , 6 , V_1 , 6 ) ;
F_5 ( & V_2 -> V_14 , & V_2 -> V_12 ) ;
F_4 ( & V_2 -> V_15 , V_13 , 6 , V_1 , 0 ) ;
F_5 ( & V_2 -> V_16 , & V_2 -> V_15 ) ;
if ( V_3 )
{
V_6 =
F_6 ( V_3 , V_17 , V_1 , 0 , 20 ,
L_2 ) ;
V_7 = F_7 ( V_6 , V_18 ) ;
F_8 ( V_7 , V_19 , V_1 , 0 , 6 ,
V_20 ) ;
F_8 ( V_7 , V_21 , V_1 , 6 , 6 ,
V_20 ) ;
F_8 ( V_7 , V_22 , V_1 , 12 , 2 ,
V_23 ) ;
F_8 ( V_7 , V_24 , V_1 , 14 , 1 ,
V_23 ) ;
F_8 ( V_7 , V_25 , V_1 , 15 , 1 ,
V_23 ) ;
F_8 ( V_7 , V_26 , V_1 , 16 , 1 ,
V_23 ) ;
F_8 ( V_7 , V_27 , V_1 , 17 , 1 ,
V_23 ) ;
F_8 ( V_7 , V_28 , V_1 , 18 , 1 ,
V_23 ) ;
F_8 ( V_7 , V_29 , V_1 , 19 , 1 ,
V_23 ) ;
}
type = F_9 ( V_1 , 18 ) ;
V_5 = F_10 ( V_1 , 12 ) ;
V_8 = F_11 ( V_1 , 20 , V_5 - 6 ) ;
if ( ! F_12 ( V_30 , type , V_8 , V_2 , V_3 ) )
F_13 ( V_8 , V_2 , V_3 ) ;
return F_14 ( V_1 ) ;
}
void
F_15 ( void )
{
static T_8 V_31 [] = {
{ & V_19 ,
{ L_3 , L_4 ,
V_32 , V_33 , NULL , 0x0 ,
NULL , V_34 }
} ,
{ & V_21 ,
{ L_5 , L_6 ,
V_32 , V_33 , NULL , 0x0 ,
NULL , V_34 }
} ,
{ & V_22 ,
{ L_7 , L_8 ,
V_35 , V_36 , NULL , 0x0 ,
L_9 , V_34 }
} ,
{ & V_24 ,
{ L_10 , L_11 ,
V_37 , V_38 , NULL , 0x0 ,
L_12 , V_34 }
} ,
{ & V_25 ,
{ L_13 , L_14 ,
V_37 , V_38 , NULL , 0x0 ,
L_15 , V_34 }
} ,
{ & V_26 ,
{ L_16 , L_17 ,
V_37 , V_38 , NULL , 0x0 ,
L_18 , V_34 }
} ,
{ & V_27 ,
{ L_19 , L_20 ,
V_37 , V_36 , NULL , 0x0 ,
NULL , V_34 }
} ,
{ & V_28 ,
{ L_21 , L_22 ,
V_37 , V_36 , F_16 ( V_39 ) , 0x0 ,
NULL , V_34 }
} ,
{ & V_29 ,
{ L_23 , L_24 ,
V_37 , V_36 , NULL , 0x0 ,
L_25 , V_34 }
} ,
} ;
static T_9 * V_40 [] = {
& V_18 ,
& V_41 ,
} ;
V_17 = F_17 ( L_26 ,
L_27 ,
L_28 ) ;
F_18 ( V_17 , V_31 , F_19 ( V_31 ) ) ;
F_20 ( V_40 , F_19 ( V_40 ) ) ;
V_30 = F_21 ( L_28 ,
L_26 , V_17 ,
V_37 , V_36 , V_42 ) ;
F_22 ( L_28 , F_1 , V_17 ) ;
}
void
F_23 ( void )
{
#if 0
dissector_handle_t docsis_mgmt_handle;
docsis_mgmt_handle = find_dissector ("docsis_mgmt");
dissector_add_uint ("docsis", 0x03, docsis_mgmt_handle);
#endif
}
