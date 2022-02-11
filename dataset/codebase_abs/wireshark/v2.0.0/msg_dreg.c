static void F_1 ( T_1 * V_1 , T_2 V_2 , T_3 * V_3 , T_4 V_4 , T_4 V_5 )
{
switch ( V_2 ) {
case V_6 :
F_2 ( V_1 , V_7 , V_3 , V_4 , 2 , V_8 ) ;
F_2 ( V_1 , V_9 , V_3 , V_4 + 2 , 1 , V_8 ) ;
F_2 ( V_1 , V_10 , V_3 , V_4 + 3 , 2 , V_8 ) ;
break;
case V_11 :
F_2 ( V_1 , V_12 , V_3 , V_4 , 1 , V_8 ) ;
break;
case V_13 :
F_2 ( V_1 , V_14 , V_3 , V_4 , 6 , V_15 ) ;
break;
case V_16 :
F_2 ( V_1 , V_17 , V_3 , V_4 , 1 , V_8 ) ;
F_2 ( V_1 , V_18 , V_3 , V_4 , 1 , V_8 ) ;
F_2 ( V_1 , V_19 , V_3 , V_4 , 1 , V_8 ) ;
F_2 ( V_1 , V_20 , V_3 , V_4 , 1 , V_8 ) ;
F_2 ( V_1 , V_21 , V_3 , V_4 , 1 , V_8 ) ;
F_2 ( V_1 , V_22 , V_3 , V_4 , 1 , V_8 ) ;
F_2 ( V_1 , V_23 , V_3 , V_4 , 1 , V_8 ) ;
F_2 ( V_1 , V_24 , V_3 , V_4 , 1 , V_8 ) ;
break;
case V_25 :
F_2 ( V_1 , V_26 , V_3 , V_4 , 2 , V_8 ) ;
break;
case V_27 :
F_2 ( V_1 , V_28 , V_3 , V_4 , 2 , V_8 ) ;
break;
default:
F_2 ( V_1 , V_29 , V_3 , V_4 , V_5 , V_15 ) ;
break;
}
}
void F_3 ( void )
{
static T_5 V_30 [] =
{
{
& V_24 ,
{
L_1 , L_2 ,
V_31 , V_32 , NULL , 0x80 , NULL , V_33
}
} ,
{
& V_34 ,
{
L_3 , L_4 ,
V_35 , V_36 , NULL , 0 , NULL , V_33
}
} ,
{
& V_26 ,
{
L_5 , L_6 ,
V_37 , V_32 , NULL , 0x0 , NULL , V_33
}
} ,
{
& V_14 ,
{
L_7 , L_8 ,
V_38 , V_36 , NULL , 0x0 , NULL , V_33
}
} ,
{
& V_7 ,
{
L_9 , L_10 ,
V_37 , V_32 , NULL , 0x0 , NULL , V_33
}
} ,
{
& V_28 ,
{
L_11 , L_12 ,
V_37 , V_32 , NULL , 0x0 , NULL , V_33
}
} ,
{
& V_10 ,
{
L_13 , L_14 ,
V_37 , V_32 , NULL , 0x0 , NULL , V_33
}
} ,
{
& V_9 ,
{
L_15 , L_16 ,
V_31 , V_32 , NULL , 0x0 , NULL , V_33
}
} ,
{
& V_12 ,
{
L_17 , L_18 ,
V_31 , V_32 , NULL , 0x0 , NULL , V_33
}
} ,
{
& V_23 ,
{
L_19 , L_20 ,
V_31 , V_32 , NULL , 0x40 , NULL , V_33
}
} ,
{
& V_20 ,
{
L_21 , L_22 ,
V_31 , V_32 , NULL , 0x08 , NULL , V_33
}
} ,
{
& V_18 ,
{
L_23 , L_24 ,
V_31 , V_32 , NULL , 0x02 , NULL , V_33
}
} ,
{
& V_19 ,
{
L_25 , L_26 ,
V_31 , V_32 , NULL , 0x04 , NULL , V_33
}
} ,
{
& V_17 ,
{
L_27 , L_28 ,
V_31 , V_32 , NULL , 0x01 , NULL , V_33
}
} ,
{
& V_22 ,
{
L_29 , L_30 ,
V_31 , V_32 , NULL , 0x20 , NULL , V_33
}
} ,
{
& V_21 ,
{
L_31 , L_32 ,
V_31 , V_32 , NULL , 0x10 , NULL , V_33
}
} ,
{
& V_39 ,
{
L_33 , L_34 ,
V_31 , V_32 , F_4 ( V_40 ) , 0x07 , NULL , V_33
}
} ,
{
& V_41 ,
{
L_33 , L_34 ,
V_31 , V_32 , F_4 ( V_42 ) , 0x07 , NULL , V_33
}
} ,
{
& V_43 ,
{
L_35 , L_36 ,
V_31 , V_32 , NULL , 0xF8 , NULL , V_33
}
} ,
{
& V_44 ,
{
L_37 , L_38 ,
V_31 , V_32 , F_4 ( V_45 ) , 0x03 , NULL , V_33
}
} ,
{
& V_46 ,
{
L_35 , L_39 ,
V_31 , V_32 , NULL , 0xFC , NULL , V_33
}
} ,
{
& V_29 ,
{
L_40 , L_41 ,
V_35 , V_36 , NULL , 0x00 , NULL , V_33
}
} ,
#if 0
{
&hf_ack_type_reserved,
{
"Reserved", "wmx.ack_type_reserved",
FT_UINT8, BASE_DEC, NULL, 0x03, NULL, HFILL
}
}
#endif
} ;
V_47 = F_5 (
L_42 ,
L_43 ,
L_44
) ;
F_6 ( V_47 , V_30 , F_7 ( V_30 ) ) ;
F_8 ( V_48 , F_7 ( V_48 ) ) ;
}
void F_9 ( void )
{
V_49 = F_5 (
L_45 ,
L_46 ,
L_47
) ;
}
static void F_10 ( T_3 * V_3 , T_6 * V_50 , T_1 * V_51 )
{
T_4 V_52 = 0 ;
T_4 V_4 ;
T_4 V_53 ;
T_7 * V_54 ;
T_1 * V_55 ;
T_1 * V_56 = NULL ;
T_8 V_57 ;
T_2 V_2 ;
T_2 V_5 ;
T_9 V_58 = FALSE ;
{
V_53 = F_11 ( V_3 ) ;
V_54 = F_12 ( V_51 , V_47 , V_3 , 0 , - 1 , L_48 ) ;
V_55 = F_13 ( V_54 , V_59 ) ;
F_2 ( V_55 , V_44 , V_3 , V_52 , 1 , V_8 ) ;
F_2 ( V_55 , V_46 , V_3 , V_52 , 1 , V_8 ) ;
V_52 ++ ;
while( V_52 < V_53 )
{
F_14 ( & V_57 , V_3 , V_52 ) ;
V_2 = F_15 ( & V_57 ) ;
V_5 = F_16 ( & V_57 ) ;
if( V_2 == - 1 || V_5 > V_60 || V_5 < 1 )
{
F_17 ( V_50 -> V_61 , V_62 , NULL , L_49 ) ;
F_2 ( V_55 , V_34 , V_3 , V_52 , ( V_53 - V_52 ) , V_15 ) ;
break;
}
V_4 = V_52 + F_18 ( & V_57 ) ;
switch ( V_2 ) {
case V_63 :
V_56 = F_19 ( & V_57 , V_59 , V_55 , V_47 , V_3 , V_52 , V_5 , L_50 ) ;
F_20 ( V_56 , V_3 , V_4 , V_5 ) ;
V_58 = TRUE ;
break;
case V_64 :
V_56 = F_19 ( & V_57 , V_59 , V_55 , V_47 , V_3 , V_52 , V_5 , L_51 ) ;
F_21 ( V_56 , V_3 , V_4 , V_5 ) ;
break;
default:
V_56 = F_19 ( & V_57 , V_59 , V_55 , V_47 , V_3 , V_52 , V_5 , L_52 ) ;
F_1 ( V_56 , V_2 , V_3 , V_4 , V_5 ) ;
break;
}
V_52 = V_5 + V_4 ;
}
if ( ! V_58 )
F_22 ( V_55 , L_53 ) ;
}
}
static void F_23 ( T_3 * V_3 , T_6 * V_50 , T_1 * V_51 )
{
T_4 V_52 = 0 ;
T_4 V_4 ;
T_4 V_53 ;
T_7 * V_65 ;
T_1 * V_66 ;
T_1 * V_56 = NULL ;
T_8 V_57 ;
T_2 V_2 ;
T_2 V_5 ;
T_9 V_58 = FALSE ;
{
V_53 = F_11 ( V_3 ) ;
V_65 = F_12 ( V_51 , V_49 , V_3 , 0 , - 1 , L_54 ) ;
V_66 = F_13 ( V_65 , V_59 ) ;
if ( V_67 )
F_2 ( V_66 , V_41 , V_3 , V_52 , 1 , V_8 ) ;
else
F_2 ( V_66 , V_39 , V_3 , V_52 , 1 , V_8 ) ;
F_2 ( V_66 , V_43 , V_3 , V_52 , 1 , V_8 ) ;
V_52 ++ ;
while( V_52 < V_53 )
{
F_14 ( & V_57 , V_3 , V_52 ) ;
V_2 = F_15 ( & V_57 ) ;
V_5 = F_16 ( & V_57 ) ;
if( V_2 == - 1 || V_5 > V_60 || V_5 < 1 )
{
F_17 ( V_50 -> V_61 , V_62 , NULL , L_55 ) ;
F_2 ( V_66 , V_34 , V_3 , V_52 , ( V_53 - V_52 ) , V_15 ) ;
break;
}
V_4 = V_52 + F_18 ( & V_57 ) ;
switch ( V_2 ) {
case V_63 :
V_56 = F_19 ( & V_57 , V_59 , V_66 , V_49 , V_3 , V_52 , V_5 , L_50 ) ;
F_20 ( V_56 , V_3 , V_4 , V_5 ) ;
V_58 = TRUE ;
break;
case V_64 :
V_56 = F_19 ( & V_57 , V_59 , V_66 , V_49 , V_3 , V_52 , V_5 , L_51 ) ;
F_21 ( V_56 , V_3 , V_4 , V_5 ) ;
break;
default:
V_56 = F_19 ( & V_57 , V_59 , V_66 , V_49 , V_3 , V_52 , V_5 , L_56 ) ;
F_1 ( V_56 , V_2 , V_3 , V_4 , V_5 ) ;
break;
}
V_52 = V_5 + V_4 ;
}
if ( ! V_58 )
F_22 ( V_66 , L_53 ) ;
}
}
void
F_24 ( void )
{
T_10 V_68 ;
V_68 = F_25 ( F_10 , V_47 ) ;
F_26 ( L_57 , V_69 , V_68 ) ;
V_68 = F_25 ( F_23 , V_49 ) ;
F_26 ( L_57 , V_70 , V_68 ) ;
}
