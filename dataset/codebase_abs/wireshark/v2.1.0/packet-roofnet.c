static void F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 = F_2 ( V_1 , V_2 , * V_3 ) ;
F_3 ( V_4 , V_5 , 1 , V_6 ) ;
F_3 ( V_4 , V_7 , 1 , V_6 ) ;
F_3 ( V_4 , V_8 , 1 , V_6 ) ;
F_3 ( V_4 , V_9 , 1 , V_6 ) ;
F_3 ( V_4 , V_10 , 2 , V_6 ) ;
F_3 ( V_4 , V_11 , 2 , V_6 ) ;
F_3 ( V_4 , V_12 , 2 , V_6 ) ;
F_3 ( V_4 , V_13 , 2 , V_6 ) ;
F_3 ( V_4 , V_14 , 4 , V_6 ) ;
F_3 ( V_4 , V_15 , 4 , V_6 ) ;
* V_3 = F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
}
static void F_6 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_3 V_16 )
{
T_1 * V_17 = NULL ;
T_4 * V_4 = NULL ;
T_5 V_18 = 0 ;
T_5 V_19 = 0 ;
V_18 = F_7 ( V_2 , * V_3 + V_20 ) ;
V_19 = F_7 ( V_2 , * V_3 + V_21 ) ;
V_17 = F_8 ( V_1 , V_2 , * V_3 , V_22 ,
V_23 , NULL , L_1 ,
V_16 ,
F_9 ( V_18 ) ,
F_9 ( V_19 ) ) ;
F_10 ( V_17 , V_24 , V_2 , * V_3 , 4 , V_18 ) ;
* V_3 += 4 ;
V_4 = F_2 ( V_17 , V_2 , * V_3 ) ;
F_3 ( V_4 , V_25 , 4 , V_6 ) ;
F_3 ( V_4 , V_26 , 4 , V_6 ) ;
F_3 ( V_4 , V_27 , 4 , V_6 ) ;
F_3 ( V_4 , V_28 , 4 , V_6 ) ;
* V_3 = F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
F_10 ( V_17 , V_29 , V_2 , * V_3 , 4 , V_19 ) ;
}
static void F_11 ( T_1 * V_1 , T_2 * V_2 , T_6 * V_30 , T_7 V_3 )
{
T_8 V_31 = 0 ;
T_8 V_32 = 0 ;
V_31 = F_12 ( V_2 , V_33 ) ;
V_32 = F_13 ( V_2 , V_3 ) ;
if ( V_31 < V_32 )
F_14 ( V_1 , V_30 , & V_34 , V_2 , V_3 , V_31 ,
L_2 ,
V_32 , V_31 ) ;
if ( V_31 == 0 )
return;
F_15 ( V_35 , F_16 ( V_2 , V_3 ) , V_30 , V_1 ) ;
}
static int F_17 ( T_2 * V_2 , T_6 * V_30 , T_1 * V_1 , void * T_9 V_36 )
{
T_10 * V_37 ;
T_1 * V_38 ;
T_3 V_3 = 0 ;
T_11 V_39 = 0 ;
T_11 V_40 = 0 ;
T_11 V_41 = 1 ;
F_18 ( V_30 -> V_42 , V_43 , L_3 ) ;
V_39 = F_19 ( V_2 , V_44 ) ;
F_20 ( V_30 -> V_42 , V_45 , L_4 ,
F_21 ( V_39 , V_46 , L_5 ) ) ;
V_37 = F_22 ( V_1 , V_47 , V_2 , V_3 , - 1 , V_48 ) ;
V_38 = F_23 ( V_37 , V_49 ) ;
F_1 ( V_38 , V_2 , & V_3 ) ;
V_40 = F_19 ( V_2 , V_50 ) ;
if ( ( V_40 * 6 * 4 ) + V_51 > V_52 ) {
F_24 ( V_30 , V_37 , & V_53 , L_6 , V_40 ) ;
return F_25 ( V_2 ) ;
}
for (; V_40 > 0 ; V_40 -- ) {
if ( F_13 ( V_2 , V_3 ) < V_54 )
return V_3 ;
F_6 ( V_38 , V_2 , & V_3 , V_41 ++ ) ;
}
F_11 ( V_1 , V_2 , V_30 , V_3 + 4 ) ;
return F_25 ( V_2 ) ;
}
void F_26 ( void )
{
static T_12 V_55 [] = {
{ & V_5 ,
{ L_7 , L_8 ,
V_56 , V_57 , NULL , 0x0 , L_9 , V_58 }
} ,
{ & V_7 ,
{ L_10 , L_11 ,
V_56 , V_57 , F_27 ( V_46 ) , 0x0 , L_12 , V_58 }
} ,
{ & V_8 ,
{ L_13 , L_14 ,
V_56 , V_57 , NULL , 0x0 , L_15 , V_58 }
} ,
{ & V_9 ,
{ L_16 , L_17 ,
V_56 , V_57 , NULL , 0x0 , L_18 , V_58 }
} ,
{ & V_10 ,
{ L_19 , L_20 ,
V_59 , V_57 , NULL , 0x0 , L_21 , V_58 }
} ,
{ & V_11 ,
{ L_22 , L_23 ,
V_59 , V_57 , NULL , 0x0 , L_24 , V_58 }
} ,
{ & V_12 ,
{ L_25 , L_26 ,
V_59 , V_57 , F_27 ( V_60 ) , 0x0 , L_27 , V_58 }
} ,
{ & V_13 ,
{ L_28 , L_29 ,
V_59 , V_57 , NULL , 0x0 , L_30 , V_58 }
} ,
{ & V_14 ,
{ L_31 , L_32 ,
V_61 , V_62 , NULL , 0x0 , L_33 , V_58 }
} ,
{ & V_15 ,
{ L_34 , L_35 ,
V_63 , V_57 , NULL , 0x0 , L_36 , V_58 }
} ,
#if 0
{ &hf_roofnet_links,
{ "Links", "roofnet.links",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
#endif
{ & V_24 ,
{ L_37 , L_38 ,
V_61 , V_62 , NULL , 0x0 , L_39 , V_58 }
} ,
{ & V_25 ,
{ L_40 , L_41 ,
V_63 , V_57 , NULL , 0x0 , NULL , V_58 }
} ,
{ & V_26 ,
{ L_42 , L_43 ,
V_63 , V_57 , NULL , 0x0 , L_44 , V_58 }
} ,
{ & V_27 ,
{ L_34 , L_45 ,
V_63 , V_57 , NULL , 0x0 , L_46 , V_58 }
} ,
{ & V_28 ,
{ L_47 , L_48 ,
V_63 , V_57 , NULL , 0x0 , L_49 , V_58 }
} ,
{ & V_29 ,
{ L_50 , L_51 ,
V_61 , V_62 , NULL , 0x0 , L_52 , V_58 }
}
} ;
static T_7 * V_64 [] = {
& V_49 ,
& V_23
} ;
static T_13 V_65 [] = {
{ & V_53 , { L_53 , V_66 , V_67 , L_54 , V_68 } } ,
{ & V_34 , { L_55 , V_66 , V_67 , L_56 , V_68 } } ,
} ;
T_14 * V_69 ;
V_47 = F_28 (
L_57 ,
L_3 ,
L_58
) ;
F_29 ( V_47 , V_55 , F_30 ( V_55 ) ) ;
F_31 ( V_64 , F_30 ( V_64 ) ) ;
V_69 = F_32 ( V_47 ) ;
F_33 ( V_69 , V_65 , F_30 ( V_65 ) ) ;
}
void F_34 ( void )
{
T_15 V_70 ;
V_35 = F_35 ( L_59 , V_47 ) ;
V_70 = F_36 ( F_17 , V_47 ) ;
F_37 ( L_60 , 0x0641 , V_70 ) ;
F_37 ( L_60 , 0x0643 , V_70 ) ;
F_37 ( L_60 , 0x0644 , V_70 ) ;
F_37 ( L_60 , 0x0645 , V_70 ) ;
}
