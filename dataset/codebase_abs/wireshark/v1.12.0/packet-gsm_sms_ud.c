static void
F_1 ( void )
{
F_2 ( & V_1 ,
& V_2 ) ;
}
static void
F_3 ( T_1 * V_3 , T_2 * V_4 , T_3 * V_5 ,
T_1 * V_6 )
{
T_2 * V_7 = NULL ;
T_4 * V_8 ;
T_1 * V_9 , * V_10 ;
T_5 V_11 , V_12 , V_13 ;
T_6 V_14 = F_4 ( V_4 ) ;
T_6 V_15 ;
T_7 V_16 = 0 ;
T_8 V_17 = FALSE ;
T_9 * V_18 = NULL ;
T_10 V_19 = 0 ;
T_10 V_20 = 0 ;
T_10 V_21 = 0 ;
T_8 V_22 = FALSE ;
T_8 V_23 = FALSE ;
T_8 V_24 = FALSE ;
T_7 V_25 = 0 ;
T_10 V_26 = 0 ;
T_10 V_27 = 0 ;
T_8 V_28 = FALSE ;
V_11 = F_5 ( V_4 , V_16 ++ ) ;
V_8 = F_6 ( V_3 , V_29 , V_4 , 0 , 1 , V_11 ) ;
V_10 = F_7 ( V_8 , V_30 ) ;
while ( V_16 < V_11 ) {
V_12 = F_5 ( V_4 , V_16 ++ ) ;
V_13 = F_5 ( V_4 , V_16 ++ ) ;
V_9 = F_6 ( V_10 , V_31 ,
V_4 , V_16 - 2 , 2 + V_13 , V_12 ) ;
switch ( V_12 ) {
case 0x00 :
if ( V_13 == 3 ) {
V_19 = F_5 ( V_4 , V_16 ++ ) ;
V_20 = F_5 ( V_4 , V_16 ++ ) ;
V_21 = F_5 ( V_4 , V_16 ++ ) ;
if ( V_20 > 1 )
V_17 = TRUE ;
F_8 ( V_9 ,
L_1 , V_19 , V_21 , V_20 ) ;
V_9 = F_7 ( V_9 ,
V_32 ) ;
F_6 ( V_9 ,
V_33 ,
V_4 , V_16 - 3 , 1 , V_19 ) ;
F_6 ( V_9 ,
V_34 ,
V_4 , V_16 - 2 , 1 , V_20 ) ;
F_6 ( V_9 ,
V_35 ,
V_4 , V_16 - 1 , 1 , V_21 ) ;
} else {
F_8 ( V_9 , L_2 ) ;
V_16 += V_13 ;
}
break;
case 0x08 :
if ( V_13 == 4 ) {
V_19 = F_9 ( V_4 , V_16 ) ; V_16 += 2 ;
V_20 = F_5 ( V_4 , V_16 ++ ) ;
V_21 = F_5 ( V_4 , V_16 ++ ) ;
if ( V_20 > 1 )
V_17 = TRUE ;
F_8 ( V_9 ,
L_1 , V_19 , V_21 , V_20 ) ;
V_9 = F_7 ( V_9 ,
V_32 ) ;
F_6 ( V_9 ,
V_33 ,
V_4 , V_16 - 4 , 2 , V_19 ) ;
F_6 ( V_9 ,
V_34 ,
V_4 , V_16 - 2 , 1 , V_20 ) ;
F_6 ( V_9 ,
V_35 ,
V_4 , V_16 - 1 , 1 , V_21 ) ;
} else {
F_8 ( V_9 , L_2 ) ;
V_16 += V_13 ;
}
break;
case 0x04 :
if ( V_13 == 2 ) {
V_27 = F_5 ( V_4 , V_16 ++ ) ;
V_26 = F_5 ( V_4 , V_16 ++ ) ;
F_8 ( V_9 ,
L_3 ,
V_26 , V_27 ) ;
V_9 = F_7 ( V_9 , V_32 ) ;
F_6 ( V_9 , V_36 ,
V_4 , V_16 - 2 , 1 , V_27 ) ;
F_6 ( V_9 , V_37 ,
V_4 , V_16 - 1 , 1 , V_26 ) ;
V_28 = TRUE ;
} else {
F_8 ( V_9 , L_2 ) ;
V_16 += V_13 ;
}
break;
case 0x05 :
if ( V_13 == 4 ) {
V_27 = F_9 ( V_4 , V_16 ) ; V_16 += 2 ;
V_26 = F_9 ( V_4 , V_16 ) ; V_16 += 2 ;
F_8 ( V_9 ,
L_3 ,
V_26 , V_27 ) ;
V_9 = F_7 ( V_9 , V_32 ) ;
F_6 ( V_9 , V_36 ,
V_4 , V_16 - 4 , 2 , V_27 ) ;
F_6 ( V_9 , V_37 ,
V_4 , V_16 - 2 , 2 , V_26 ) ;
V_28 = TRUE ;
} else {
F_8 ( V_9 , L_2 ) ;
V_16 += V_13 ;
}
break;
default:
V_16 += V_13 ;
break;
}
}
if ( F_10 ( V_4 , V_16 ) <= 0 )
return;
V_15 = V_14 - ( 1 + V_11 ) ;
if ( V_15 == 0 )
return;
if ( V_17 && V_21 != 0 && V_20 != 0 &&
F_11 ( V_4 , V_16 , V_15 ) ) {
V_23 = TRUE ;
V_22 = V_5 -> V_38 ;
V_5 -> V_38 = TRUE ;
V_18 = F_12 ( & V_1 ,
V_4 , V_16 ,
V_5 ,
V_19 ,
NULL ,
V_21 - 1 ,
V_15 ,
( V_21 != V_20 ) ) ;
if ( V_18 ) {
V_24 = TRUE ;
V_25 = V_18 -> V_25 ;
}
V_7 = F_13 ( V_4 , V_16 , V_5 ,
L_4 , V_18 , & V_39 ,
NULL , V_3 ) ;
if ( V_24 ) {
F_14 ( V_5 -> V_40 , V_41 ,
L_5 ) ;
} else {
F_15 ( V_5 -> V_40 , V_41 ,
L_6 , V_21 , V_20 ) ;
}
}
if ( ! V_7 )
V_7 = F_16 ( V_4 , V_16 ) ;
if ( V_7 ) {
if ( ( V_24 && V_5 -> V_42 -> V_43 == V_25 )
|| V_21 == 0 || ( V_21 == 1 && V_44 ) ) {
if ( V_28 ) {
T_8 V_45 = FALSE ;
if ( V_46 && F_17 ( V_5 -> V_40 ) ) {
V_45 = TRUE ;
F_18 ( V_5 -> V_40 , FALSE ) ;
}
if ( V_47 ) {
F_19 ( V_48 , V_7 , V_5 , V_6 ) ;
} else {
if ( ! F_20 ( V_49 , V_26 ,
V_7 , V_5 , V_6 ) ) {
if ( ! F_20 ( V_49 , V_27 ,
V_7 , V_5 , V_6 ) ) {
if ( V_3 ) {
F_21 ( V_3 , V_7 , 0 , - 1 ,
L_7 ) ;
}
}
}
}
if ( V_45 )
F_18 ( V_5 -> V_40 , TRUE ) ;
} else {
F_21 ( V_3 , V_7 , 0 , - 1 ,
L_7 ) ;
}
} else {
F_21 ( V_3 , V_7 , 0 , - 1 ,
L_8 ,
V_21 , V_20 ) ;
}
}
if ( V_23 )
V_5 -> V_38 = V_22 ;
return;
}
static void
F_22 ( T_2 * V_4 , T_3 * V_5 , T_1 * V_10 )
{
T_4 * V_8 ;
T_1 * V_9 ;
V_8 = F_23 ( V_10 , V_50 , V_4 , 0 , - 1 , V_51 ) ;
V_9 = F_7 ( V_8 , V_52 ) ;
F_3 ( V_9 , V_4 , V_5 , V_10 ) ;
}
void
F_24 ( void )
{
T_11 * V_53 ;
static T_12 V_54 [] = {
{ & V_31 ,
{ L_9 , L_10 ,
V_55 , V_56 , F_25 ( V_57 ) , 0x00 ,
L_11 ,
V_58
}
} ,
{ & V_29 ,
{ L_12 , L_13 ,
V_55 , V_59 , NULL , 0x00 ,
L_14 ,
V_58
}
} ,
#if 0
{ &hf_gsm_sms_udh_multiple_messages,
{ "Multiple messages UDH", "gsm_sms_ud.udh.mm",
FT_NONE, BASE_NONE, NULL, 0x00,
"Multiple messages User Data Header",
HFILL
}
},
#endif
{ & V_33 ,
{ L_15 , L_16 ,
V_60 , V_59 , NULL , 0x00 ,
L_17 ,
V_58
}
} ,
{ & V_34 ,
{ L_18 , L_19 ,
V_55 , V_59 , NULL , 0x00 ,
L_20 ,
V_58
}
} ,
{ & V_35 ,
{ L_21 , L_22 ,
V_55 , V_59 , NULL , 0x00 ,
L_23 ,
V_58
}
} ,
#if 0
{ &hf_gsm_sms_udh_ports,
{ "Port number UDH", "gsm_sms_ud.udh.ports",
FT_NONE, BASE_NONE, NULL, 0x00,
"Port number User Data Header",
HFILL
}
},
#endif
{ & V_37 ,
{ L_24 , L_25 ,
V_55 , V_59 , NULL , 0x00 ,
NULL ,
V_58
}
} ,
{ & V_36 ,
{ L_26 , L_27 ,
V_55 , V_59 , NULL , 0x00 ,
NULL ,
V_58
}
} ,
{ & V_61 ,
{ L_28 , L_29 ,
V_62 , V_63 , NULL , 0x00 ,
L_30 ,
V_58
}
} ,
{ & V_64 ,
{ L_31 , L_32 ,
V_65 , V_63 , NULL , 0x00 ,
L_33 ,
V_58
}
} ,
{ & V_66 ,
{ L_34 , L_35 ,
V_67 , V_63 , NULL , 0x0 ,
L_36 ,
V_58
}
} ,
{ & V_68 ,
{ L_37 ,
L_38 ,
V_67 , V_63 , NULL , 0x0 ,
L_39 ,
V_58
}
} ,
{ & V_69 ,
{ L_40 ,
L_41 ,
V_67 , V_63 , NULL , 0x0 ,
L_42 ,
V_58
}
} ,
{ & V_70 ,
{ L_43 ,
L_44 ,
V_67 , V_63 , NULL , 0x0 ,
L_45 ,
V_58
}
} ,
{ & V_71 ,
{ L_46 , L_47 ,
V_65 , V_63 , NULL , 0x00 ,
L_48 ,
V_58
}
} ,
{ & V_72 ,
{ L_49 , L_50 ,
V_73 , V_59 , NULL , 0x00 ,
NULL ,
V_58
}
} ,
{ & V_74 ,
{ L_51 ,
L_52 ,
V_65 , V_63 , NULL , 0x00 ,
L_53 ,
V_58
}
} ,
{ & V_75 ,
{ L_54 ,
L_55 ,
V_73 , V_59 , NULL , 0x00 ,
L_56 ,
V_58
}
} ,
} ;
static T_13 * V_76 [] = {
& V_52 ,
& V_30 ,
& V_32 ,
& V_77 ,
& V_78 ,
} ;
V_50 = F_26 (
L_57 ,
L_58 ,
L_59 ) ;
F_27 ( V_50 , V_54 , F_28 ( V_54 ) ) ;
F_29 ( V_76 , F_28 ( V_76 ) ) ;
V_49 = F_30 ( L_60 ,
L_61 , V_60 , V_59 ) ;
V_53 = F_31 ( V_50 , NULL ) ;
F_32 ( V_53 ,
L_62 ,
L_63 ,
L_64
L_65
L_66 ,
& V_47 ) ;
F_32 ( V_53 , L_67 ,
L_68 ,
L_69
L_70
L_71
L_72 ,
& V_44 ) ;
F_32 ( V_53 , L_73 ,
L_74 ,
L_75
L_76 ,
& V_46 ) ;
F_33 ( L_59 , F_22 , V_50 ) ;
F_34 ( F_1 ) ;
}
void
F_35 ( void )
{
V_48 = F_36 ( L_77 ) ;
F_37 ( V_48 ) ;
}
