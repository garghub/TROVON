static T_1
F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , void * T_5 V_4 )
{
T_6 * V_5 ;
T_4 * V_6 ;
T_6 * V_7 ;
T_1 V_8 = 0 ;
T_7 V_9 ;
T_7 V_10 ;
T_7 V_11 ;
T_7 V_12 ;
T_7 V_13 ;
T_8 V_14 ;
V_5 = F_2 ( V_3 , V_15 , V_1 , V_8 , F_3 ( V_1 ) , V_16 ) ;
V_6 = F_4 ( V_5 , V_17 ) ;
F_5 ( V_2 -> V_18 , V_19 , L_1 ) ;
switch ( V_2 -> V_20 ) {
case V_21 :
F_5 ( V_2 -> V_18 , V_22 , L_2 ) ;
break;
case V_23 :
F_5 ( V_2 -> V_18 , V_22 , L_3 ) ;
break;
default:
F_5 ( V_2 -> V_18 , V_22 , L_4 ) ;
break;
}
V_7 = F_2 ( V_6 , V_24 , V_1 , V_8 , 1 , V_25 ) ;
V_9 = F_6 ( V_1 , V_8 ) ;
V_8 += 1 ;
F_7 ( V_2 -> V_18 , V_22 , L_5 , F_8 ( V_9 , V_26 , L_6 ) ) ;
if ( V_9 >= 0x11 && V_9 <= 0x20 ) {
F_9 ( V_7 , L_7 ) ;
F_10 ( V_2 -> V_18 , V_22 , L_7 ) ;
} else {
F_9 ( V_7 , L_8 ) ;
F_10 ( V_2 -> V_18 , V_22 , L_8 ) ;
}
if ( V_9 & 0x01 ) {
switch( V_9 ) {
case 0x01 :
case 0x03 :
case 0x05 :
case 0x07 :
V_7 = F_2 ( V_6 , V_27 , V_1 , V_8 , 2 , V_25 ) ;
V_11 = F_11 ( V_1 , V_8 ) ;
V_8 += 2 ;
F_7 ( V_2 -> V_18 , V_22 , L_9 , V_11 ) ;
if ( V_11 == 0xFFFF ) {
F_9 ( V_7 , L_10 ) ;
F_7 ( V_2 -> V_18 , V_22 , L_10 ) ;
} else if ( V_11 >= 0x0001 && V_11 <= 0xFEFF ) {
F_9 ( V_7 , L_11 ) ;
F_7 ( V_2 -> V_18 , V_22 , L_11 ) ;
} else if ( V_11 == 0x0000 ) {
F_9 ( V_7 , L_12 ) ;
F_10 ( V_2 -> V_18 , V_22 , L_12 ) ;
}
if ( V_9 != 0x07 && V_11 == 0xFFFF ) {
F_12 ( V_2 , V_7 , & V_28 ) ;
}
if ( V_9 == 0x01 ) {
V_7 = F_2 ( V_6 , V_29 , V_1 , V_8 , 1 , V_25 ) ;
V_12 = F_6 ( V_1 , V_8 ) ;
V_8 += 1 ;
if ( V_12 <= 0x7F ) {
F_9 ( V_7 , L_13 ) ;
} else {
F_9 ( V_7 , L_12 ) ;
}
F_2 ( V_6 , V_30 , V_1 , V_8 , 1 , V_25 ) ;
V_8 += 1 ;
}
break;
case 0x11 :
V_7 = F_2 ( V_6 , V_31 , V_1 , V_8 , 2 , V_25 ) ;
F_9 ( V_7 , L_14 ) ;
V_8 += 2 ;
break;
case 0x13 :
F_2 ( V_6 , V_32 , V_1 , V_8 , 1 , V_25 ) ;
V_8 += 1 ;
V_7 = F_2 ( V_6 , V_33 , V_1 , V_8 , 4 , V_25 ) ;
V_13 = F_13 ( V_1 , V_8 ) ;
if ( V_13 == 0xFFFFFFFF )
F_9 ( V_7 , L_15 ) ;
else
F_9 ( V_7 , L_16 ) ;
V_8 += 4 ;
V_7 = F_2 ( V_6 , V_34 , V_1 , V_8 , 8 , V_25 ) ;
V_14 = F_14 ( V_1 , V_8 ) ;
if ( V_14 == F_15 ( 0xFFFFFFFFFFFFFFFF ) )
F_9 ( V_7 , L_17 ) ;
else
F_9 ( V_7 , L_18 ) ;
V_8 += 8 ;
break;
case 0x15 :
V_7 = F_2 ( V_6 , V_33 , V_1 , V_8 , 4 , V_25 ) ;
F_9 ( V_7 , L_16 ) ;
V_8 += 4 ;
V_7 = F_2 ( V_6 , V_34 , V_1 , V_8 , 8 , V_25 ) ;
F_9 ( V_7 , L_18 ) ;
V_8 += 8 ;
V_7 = F_2 ( V_6 , V_35 , V_1 , V_8 , 2 , V_25 ) ;
F_9 ( V_7 , L_19 ) ;
V_8 += 2 ;
break;
}
} else {
F_2 ( V_6 , V_36 , V_1 , V_8 , 1 , V_25 ) ;
V_10 = F_6 ( V_1 , V_8 ) ;
V_8 += 1 ;
F_7 ( V_2 -> V_18 , V_22 , L_20 , F_8 ( V_10 , V_37 , L_21 ) ) ;
if ( V_9 >= 0x11 && V_9 <= 0x20 ) {
switch( V_9 ) {
case 0x12 :
V_7 = F_2 ( V_6 , V_38 , V_1 , V_8 , 1 , V_25 ) ;
F_9 ( V_7 , L_22 ) ;
V_8 += 1 ;
V_7 = F_2 ( V_6 , V_39 , V_1 , V_8 , 2 , V_25 ) ;
F_9 ( V_7 , L_23 ) ;
V_8 += 2 ;
V_7 = F_2 ( V_6 , V_40 , V_1 , V_8 , 2 , V_25 ) ;
F_9 ( V_7 , L_19 ) ;
V_8 += 2 ;
V_7 = F_2 ( V_6 , V_41 , V_1 , V_8 , 2 , V_25 ) ;
F_9 ( V_7 , L_14 ) ;
V_8 += 2 ;
break;
case 0x14 :
V_7 = F_2 ( V_6 , V_33 , V_1 , V_8 , 4 , V_25 ) ;
V_13 = F_13 ( V_1 , V_8 ) ;
if ( V_13 == 0xFFFFFFFF )
F_9 ( V_7 , L_15 ) ;
else
F_9 ( V_7 , L_16 ) ;
V_8 += 4 ;
V_7 = F_2 ( V_6 , V_34 , V_1 , V_8 , 8 , V_25 ) ;
V_14 = F_14 ( V_1 , V_8 ) ;
if ( V_14 == F_15 ( 0xFFFFFFFFFFFFFFFF ) )
F_9 ( V_7 , L_17 ) ;
else
F_9 ( V_7 , L_18 ) ;
V_8 += 8 ;
V_7 = F_2 ( V_6 , V_35 , V_1 , V_8 , 2 , V_25 ) ;
F_9 ( V_7 , L_19 ) ;
V_8 += 2 ;
break;
}
} else {
V_7 = F_2 ( V_6 , V_27 , V_1 , V_8 , 2 , V_25 ) ;
V_11 = F_11 ( V_1 , V_8 ) ;
V_8 += 2 ;
F_7 ( V_2 -> V_18 , V_22 , L_24 , V_11 ) ;
if ( V_11 == 0xFFFF ) {
F_9 ( V_7 , L_10 ) ;
F_10 ( V_2 -> V_18 , V_22 , L_10 ) ;
} else if ( V_11 >= 0x0001 && V_11 <= 0xFEFF ) {
F_9 ( V_7 , L_11 ) ;
F_10 ( V_2 -> V_18 , V_22 , L_11 ) ;
} else if ( V_11 == 0x0000 ) {
F_9 ( V_7 , L_12 ) ;
F_10 ( V_2 -> V_18 , V_22 , L_12 ) ;
}
if ( ( V_9 == 0x03 || V_9 == 0x05 || V_9 == 0x07 ) && F_16 ( V_1 , V_8 ) ) {
F_17 ( V_2 , V_7 , & V_42 ,
L_25 ) ;
} else if ( F_16 ( V_1 , V_8 ) ) {
V_7 = F_2 ( V_6 , V_43 , V_1 , V_8 , F_16 ( V_1 , V_8 ) , V_16 ) ;
if ( V_10 != 0x00 ) {
F_17 ( V_2 , V_7 , & V_42 ,
L_26 ) ;
}
V_8 += F_16 ( V_1 , V_8 ) ;
}
}
}
if ( F_16 ( V_1 , V_8 ) ) {
V_7 = F_2 ( V_6 , V_44 , V_1 , V_8 , F_16 ( V_1 , V_8 ) , V_16 ) ;
F_12 ( V_2 , V_7 , & V_45 ) ;
V_8 = F_18 ( V_1 ) ;
}
return V_8 ;
}
void
F_19 ( void )
{
T_9 * V_46 ;
T_10 * V_47 ;
static T_11 V_48 [] = {
{ & V_24 ,
{ L_27 , L_28 ,
V_49 , V_50 , F_20 ( V_26 ) , 0x0 ,
NULL , V_51 }
} ,
{ & V_36 ,
{ L_29 , L_30 ,
V_49 , V_50 , F_20 ( V_37 ) , 0x0 ,
NULL , V_51 }
} ,
{ & V_27 ,
{ L_31 , L_32 ,
V_52 , V_50 , NULL , 0x0 ,
NULL , V_51 }
} ,
{ & V_29 ,
{ L_33 , L_34 ,
V_49 , V_50 , NULL , 0x0 ,
NULL , V_51 }
} ,
{ & V_30 ,
{ L_35 , L_36 ,
V_49 , V_50 , NULL , 0x0 ,
NULL , V_51 }
} ,
{ & V_31 ,
{ L_37 , L_38 ,
V_52 , V_53 , NULL , 0x00 ,
NULL , V_51 }
} ,
{ & V_32 ,
{ L_39 , L_40 ,
V_49 , V_53 , NULL , 0x00 ,
NULL , V_51 }
} ,
{ & V_33 ,
{ L_41 , L_42 ,
V_54 , V_53 , NULL , 0x00 ,
NULL , V_51 }
} ,
{ & V_34 ,
{ L_43 , L_44 ,
V_55 , V_53 , NULL , 0x00 ,
NULL , V_51 }
} ,
{ & V_35 ,
{ L_45 , L_46 ,
V_52 , V_53 , NULL , 0x00 ,
NULL , V_51 }
} ,
{ & V_38 ,
{ L_47 , L_48 ,
V_49 , V_53 , NULL , 0x00 ,
NULL , V_51 }
} ,
{ & V_39 ,
{ L_49 , L_50 ,
V_52 , V_53 , NULL , 0x00 ,
NULL , V_51 }
} ,
{ & V_40 ,
{ L_51 , L_52 ,
V_52 , V_53 , NULL , 0x00 ,
NULL , V_51 }
} ,
{ & V_41 ,
{ L_53 , L_54 ,
V_52 , V_53 , NULL , 0x00 ,
NULL , V_51 }
} ,
{ & V_43 ,
{ L_55 , L_56 ,
V_56 , V_57 , NULL , 0x00 ,
NULL , V_51 }
} ,
{ & V_44 ,
{ L_57 , L_58 ,
V_58 , V_57 , NULL , 0x00 ,
NULL , V_51 }
} ,
} ;
static T_1 * V_59 [] = {
& V_17
} ;
static T_12 V_60 [] = {
{ & V_28 , { L_59 , V_61 , V_62 , L_60 , V_63 } } ,
{ & V_42 , { L_61 , V_61 , V_62 , L_62 , V_63 } } ,
{ & V_45 , { L_63 , V_61 , V_62 , L_64 , V_63 } } ,
} ;
V_15 = F_21 ( L_65 , L_66 , L_67 ) ;
V_64 = F_22 ( L_67 , F_1 , V_15 ) ;
F_23 ( V_15 , V_48 , F_24 ( V_48 ) ) ;
F_25 ( V_59 , F_24 ( V_59 ) ) ;
V_47 = F_26 ( V_15 ) ;
F_27 ( V_47 , V_60 , F_24 ( V_60 ) ) ;
V_46 = F_28 ( V_15 , NULL ) ;
F_29 ( V_46 , L_68 ,
L_69 ,
L_70 ) ;
}
void
F_30 ( void )
{
F_31 ( L_71 , L_72 , V_64 ) ;
F_31 ( L_71 , L_73 , V_64 ) ;
F_31 ( L_71 , L_74 , V_64 ) ;
F_31 ( L_71 , L_75 , V_64 ) ;
F_31 ( L_71 , L_76 , V_64 ) ;
F_32 ( L_77 , V_64 ) ;
F_32 ( L_78 , V_64 ) ;
}
