static void
F_1 ( void )
{
F_2 ( & V_1 ,
& V_2 ) ;
}
static void
F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static void
F_5 ( T_1 * V_3 , T_2 * V_4 , T_3 * V_5 ,
T_1 * V_6 )
{
T_2 * V_7 = NULL ;
T_4 * V_8 ;
T_1 * V_9 , * V_10 ;
T_5 V_11 , V_12 , V_13 ;
T_6 V_14 = F_6 ( V_4 ) ;
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
V_11 = F_7 ( V_4 , V_16 ++ ) ;
V_8 = F_8 ( V_3 , V_29 , V_4 , 0 , 1 , V_11 ) ;
V_10 = F_9 ( V_8 , V_30 ) ;
while ( V_16 < V_11 ) {
V_12 = F_7 ( V_4 , V_16 ++ ) ;
V_13 = F_7 ( V_4 , V_16 ++ ) ;
V_9 = F_8 ( V_10 , V_31 ,
V_4 , V_16 - 2 , 2 + V_13 , V_12 ) ;
switch ( V_12 ) {
case 0x00 :
if ( V_13 == 3 ) {
V_19 = F_7 ( V_4 , V_16 ++ ) ;
V_20 = F_7 ( V_4 , V_16 ++ ) ;
V_21 = F_7 ( V_4 , V_16 ++ ) ;
if ( V_20 > 1 )
V_17 = TRUE ;
F_10 ( V_9 ,
L_1 , V_19 , V_21 , V_20 ) ;
V_9 = F_9 ( V_9 ,
V_32 ) ;
F_8 ( V_9 ,
V_33 ,
V_4 , V_16 - 3 , 1 , V_19 ) ;
F_8 ( V_9 ,
V_34 ,
V_4 , V_16 - 2 , 1 , V_20 ) ;
F_8 ( V_9 ,
V_35 ,
V_4 , V_16 - 1 , 1 , V_21 ) ;
} else {
F_10 ( V_9 , L_2 ) ;
V_16 += V_13 ;
}
break;
case 0x08 :
if ( V_13 == 4 ) {
V_19 = F_11 ( V_4 , V_16 ) ; V_16 += 2 ;
V_20 = F_7 ( V_4 , V_16 ++ ) ;
V_21 = F_7 ( V_4 , V_16 ++ ) ;
if ( V_20 > 1 )
V_17 = TRUE ;
F_10 ( V_9 ,
L_1 , V_19 , V_21 , V_20 ) ;
V_9 = F_9 ( V_9 ,
V_32 ) ;
F_8 ( V_9 ,
V_33 ,
V_4 , V_16 - 4 , 2 , V_19 ) ;
F_8 ( V_9 ,
V_34 ,
V_4 , V_16 - 2 , 1 , V_20 ) ;
F_8 ( V_9 ,
V_35 ,
V_4 , V_16 - 1 , 1 , V_21 ) ;
} else {
F_10 ( V_9 , L_2 ) ;
V_16 += V_13 ;
}
break;
case 0x04 :
if ( V_13 == 2 ) {
V_27 = F_7 ( V_4 , V_16 ++ ) ;
V_26 = F_7 ( V_4 , V_16 ++ ) ;
F_10 ( V_9 ,
L_3 ,
V_26 , V_27 ) ;
V_9 = F_9 ( V_9 , V_32 ) ;
F_8 ( V_9 , V_36 ,
V_4 , V_16 - 2 , 1 , V_27 ) ;
F_8 ( V_9 , V_37 ,
V_4 , V_16 - 1 , 1 , V_26 ) ;
V_28 = TRUE ;
} else {
F_10 ( V_9 , L_2 ) ;
V_16 += V_13 ;
}
break;
case 0x05 :
if ( V_13 == 4 ) {
V_27 = F_11 ( V_4 , V_16 ) ; V_16 += 2 ;
V_26 = F_11 ( V_4 , V_16 ) ; V_16 += 2 ;
F_10 ( V_9 ,
L_3 ,
V_26 , V_27 ) ;
V_9 = F_9 ( V_9 , V_32 ) ;
F_8 ( V_9 , V_36 ,
V_4 , V_16 - 4 , 2 , V_27 ) ;
F_8 ( V_9 , V_37 ,
V_4 , V_16 - 2 , 2 , V_26 ) ;
V_28 = TRUE ;
} else {
F_10 ( V_9 , L_2 ) ;
V_16 += V_13 ;
}
break;
case 0x24 :
if ( V_13 == 1 ) {
V_9 = F_9 ( V_9 , V_32 ) ;
F_12 ( V_9 ,
V_38 ,
V_4 , V_16 ++ , 1 , V_39 ) ;
} else {
F_10 ( V_9 , L_2 ) ;
V_16 += V_13 ;
}
break;
case 0x25 :
if ( V_13 == 1 ) {
V_9 = F_9 ( V_9 , V_32 ) ;
F_12 ( V_9 ,
V_40 ,
V_4 , V_16 ++ , 1 , V_39 ) ;
} else {
F_10 ( V_9 , L_2 ) ;
V_16 += V_13 ;
}
break;
default:
V_16 += V_13 ;
break;
}
}
if ( F_13 ( V_4 , V_16 ) <= 0 )
return;
V_15 = V_14 - ( 1 + V_11 ) ;
if ( V_15 == 0 )
return;
if ( V_17 && V_21 != 0 && V_20 != 0 &&
F_14 ( V_4 , V_16 , V_15 ) ) {
V_23 = TRUE ;
V_22 = V_5 -> V_41 ;
V_5 -> V_41 = TRUE ;
V_18 = F_15 ( & V_1 ,
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
V_7 = F_16 ( V_4 , V_16 , V_5 ,
L_4 , V_18 , & V_42 ,
NULL , V_3 ) ;
if ( V_24 ) {
F_17 ( V_5 -> V_43 , V_44 ,
L_5 ) ;
} else {
F_18 ( V_5 -> V_43 , V_44 ,
L_6 , V_21 , V_20 ) ;
}
}
if ( ! V_7 )
V_7 = F_19 ( V_4 , V_16 ) ;
if ( V_7 ) {
if ( ( V_24 && V_5 -> V_45 == V_25 )
|| V_21 == 0 || ( V_21 == 1 && V_46 ) ) {
if ( V_28 ) {
T_8 V_47 = FALSE ;
if ( V_48 && F_20 ( V_5 -> V_43 ) ) {
V_47 = TRUE ;
F_21 ( V_5 -> V_43 , FALSE ) ;
}
if ( V_49 ) {
F_22 ( V_50 , V_7 , V_5 , V_6 ) ;
} else {
if ( ! F_23 ( V_51 , V_26 ,
V_7 , V_5 , V_6 ) ) {
if ( ! F_23 ( V_51 , V_27 ,
V_7 , V_5 , V_6 ) ) {
if ( V_3 ) {
F_12 ( V_3 , V_52 , V_7 , 0 , - 1 , V_53 ) ;
}
}
}
}
if ( V_47 )
F_21 ( V_5 -> V_43 , TRUE ) ;
} else {
F_12 ( V_3 , V_52 , V_7 , 0 , - 1 , V_53 ) ;
}
} else {
F_24 ( V_3 , V_52 , V_7 , 0 , - 1 ,
NULL , L_7 ,
V_21 , V_20 ) ;
}
}
if ( V_23 )
V_5 -> V_41 = V_22 ;
return;
}
static int
F_25 ( T_2 * V_4 , T_3 * V_5 , T_1 * V_10 , void * T_11 V_54 )
{
T_4 * V_8 ;
T_1 * V_9 ;
V_8 = F_12 ( V_10 , V_55 , V_4 , 0 , - 1 , V_53 ) ;
V_9 = F_9 ( V_8 , V_56 ) ;
F_5 ( V_9 , V_4 , V_5 , V_10 ) ;
return F_26 ( V_4 ) ;
}
void
F_27 ( void )
{
T_12 * V_57 ;
static T_13 V_58 [] = {
{ & V_31 ,
{ L_8 , L_9 ,
V_59 , V_60 , F_28 ( V_61 ) , 0x00 ,
L_10 ,
V_62
}
} ,
{ & V_29 ,
{ L_11 , L_12 ,
V_59 , V_63 , NULL , 0x00 ,
L_13 ,
V_62
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
{ L_14 , L_15 ,
V_64 , V_63 , NULL , 0x00 ,
L_16 ,
V_62
}
} ,
{ & V_34 ,
{ L_17 , L_18 ,
V_59 , V_63 , NULL , 0x00 ,
L_19 ,
V_62
}
} ,
{ & V_35 ,
{ L_20 , L_21 ,
V_59 , V_63 , NULL , 0x00 ,
L_22 ,
V_62
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
{ L_23 , L_24 ,
V_59 , V_63 , NULL , 0x00 ,
NULL ,
V_62
}
} ,
{ & V_36 ,
{ L_25 , L_26 ,
V_59 , V_63 , NULL , 0x00 ,
NULL ,
V_62
}
} ,
{ & V_38 ,
{ L_27 , L_28 ,
V_59 , V_63 ,
F_28 ( V_65 ) , 0x00 ,
NULL ,
V_62
}
} ,
{ & V_40 ,
{ L_27 , L_29 ,
V_59 , V_63 ,
F_28 ( V_66 ) , 0x00 ,
NULL ,
V_62
}
} ,
{ & V_67 ,
{ L_30 , L_31 ,
V_68 , V_69 , NULL , 0x00 ,
L_32 ,
V_62
}
} ,
{ & V_70 ,
{ L_33 , L_34 ,
V_71 , V_69 , NULL , 0x00 ,
L_35 ,
V_62
}
} ,
{ & V_72 ,
{ L_36 , L_37 ,
V_73 , V_69 , NULL , 0x0 ,
L_38 ,
V_62
}
} ,
{ & V_74 ,
{ L_39 ,
L_40 ,
V_73 , V_69 , NULL , 0x0 ,
L_41 ,
V_62
}
} ,
{ & V_75 ,
{ L_42 ,
L_43 ,
V_73 , V_69 , NULL , 0x0 ,
L_44 ,
V_62
}
} ,
{ & V_76 ,
{ L_45 ,
L_46 ,
V_73 , V_69 , NULL , 0x0 ,
L_47 ,
V_62
}
} ,
{ & V_77 ,
{ L_48 , L_49 ,
V_71 , V_69 , NULL , 0x00 ,
L_50 ,
V_62
}
} ,
{ & V_78 ,
{ L_51 , L_52 ,
V_79 , V_63 , NULL , 0x00 ,
NULL ,
V_62
}
} ,
{ & V_80 ,
{ L_53 ,
L_54 ,
V_71 , V_69 , NULL , 0x00 ,
L_55 ,
V_62
}
} ,
{ & V_81 ,
{ L_56 ,
L_57 ,
V_79 , V_63 , NULL , 0x00 ,
L_58 ,
V_62
}
} ,
{ & V_52 ,
{ L_59 ,
L_60 ,
V_82 , V_69 , NULL , 0x00 , NULL , V_62
}
} ,
} ;
static T_14 * V_83 [] = {
& V_56 ,
& V_30 ,
& V_32 ,
& V_84 ,
& V_85 ,
} ;
V_55 = F_29 (
L_61 ,
L_62 ,
L_63 ) ;
F_30 ( V_55 , V_58 , F_31 ( V_58 ) ) ;
F_32 ( V_83 , F_31 ( V_83 ) ) ;
V_51 = F_33 ( L_64 ,
L_65 , V_55 , V_64 , V_63 , V_86 ) ;
V_57 = F_34 ( V_55 , NULL ) ;
F_35 ( V_57 ,
L_66 ,
L_67 ,
L_68
L_69
L_70 ,
& V_49 ) ;
F_35 ( V_57 , L_71 ,
L_72 ,
L_73
L_74
L_75
L_76 ,
& V_46 ) ;
F_35 ( V_57 , L_77 ,
L_78 ,
L_79
L_80 ,
& V_48 ) ;
F_36 ( L_63 , F_25 , V_55 ) ;
F_37 ( F_1 ) ;
F_38 ( F_3 ) ;
}
void
F_39 ( void )
{
V_50 = F_40 ( L_81 , V_55 ) ;
F_41 ( V_50 ) ;
}
