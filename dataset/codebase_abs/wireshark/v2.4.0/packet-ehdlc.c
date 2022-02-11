static T_1 F_1 ( T_1 V_1 )
{
if ( V_1 < 12 )
return V_1 ;
else
return 60 + ( V_1 - 12 ) ;
}
static T_1 F_2 ( T_1 V_2 )
{
switch ( V_2 ) {
case 1 :
case 6 :
return 1 ;
default:
return 0 ;
}
}
static T_1 F_3 ( T_1 V_2 )
{
switch ( V_2 ) {
case 0 :
case 1 :
return 0 ;
case 2 :
return 10 ;
case 3 :
return 11 ;
case 4 :
return 12 ;
case 5 :
case 6 :
return 62 ;
case 7 :
default:
return 0 ;
}
}
static int
F_4 ( T_2 * V_3 , T_3 * V_4 , T_4 V_5 , T_4 V_6 )
{
T_4 V_7 = V_5 ;
T_5 * V_8 ;
T_2 * V_9 ;
V_8 = F_5 ( V_3 , V_10 ,
V_4 , V_7 , V_6 , V_11 ) ;
V_9 = F_6 ( V_8 , V_12 ) ;
F_5 ( V_9 , V_13 , V_4 , V_7 ++ , 1 , V_11 ) ;
F_5 ( V_9 , V_14 , V_4 , V_7 ++ , 1 , V_11 ) ;
F_5 ( V_9 , V_15 , V_4 , V_7 , 2 , V_16 ) ;
V_7 += 2 ;
while ( F_7 ( V_4 , V_7 ) >= 2 ) {
T_1 V_17 = F_8 ( V_4 , V_7 ++ ) ;
T_1 V_18 = F_8 ( V_4 , V_7 ++ ) ;
switch ( V_17 ) {
case 0x07 :
F_5 ( V_9 , V_19 , V_4 ,
V_7 , V_18 , V_11 ) ;
break;
case 0x08 :
F_5 ( V_9 , V_20 , V_4 ,
V_7 , V_18 , V_11 ) ;
break;
case 0x09 :
F_5 ( V_9 , V_21 , V_4 ,
V_7 , V_18 , V_11 ) ;
break;
}
V_7 += V_18 ;
}
return V_7 - V_5 ;
}
static int
F_9 ( T_3 * V_4 , T_6 * V_22 , T_2 * V_3 , void * T_7 V_23 )
{
int V_7 = 4 ;
F_10 ( V_22 -> V_24 , V_25 , L_1 ) ;
F_11 ( V_22 -> V_24 , V_26 ) ;
while ( F_7 ( V_4 , V_7 ) > 0 ) {
T_5 * V_8 = NULL ;
T_2 * V_27 = NULL ;
T_8 V_6 , V_28 ;
T_1 V_2 , V_1 , V_29 , V_30 , V_31 ;
T_3 * V_32 ;
T_8 V_33 ;
T_9 V_34 = FALSE , V_35 = TRUE ;
T_10 V_36 = 2 ;
V_28 = F_12 ( V_4 , V_7 , V_16 ) ;
V_6 = V_28 & 0x1FF ;
V_2 = V_28 >> 13 ;
V_29 = F_3 ( V_2 ) ;
V_31 = F_2 ( V_2 ) ;
V_1 = ( V_28 >> 9 ) & 0xF ;
V_30 = F_1 ( V_1 ) ;
if ( V_3 ) {
V_8 = F_13 ( V_3 , V_37 ,
V_4 , V_7 , F_14 ( V_6 , F_15 ( V_4 , V_7 ) ) ,
L_2 ) ;
V_27 = F_6 ( V_8 , V_38 ) ;
F_5 ( V_27 , V_39 ,
V_4 , V_7 , 1 , V_16 ) ;
F_5 ( V_27 , V_40 ,
V_4 , V_7 , 1 , V_16 ) ;
F_16 ( V_27 , V_41 ,
V_4 , V_7 , 1 , V_31 ) ;
F_16 ( V_27 , V_42 ,
V_4 , V_7 , 1 , V_29 ) ;
F_16 ( V_27 , V_43 ,
V_4 , V_7 , 1 , V_30 ) ;
F_5 ( V_27 , V_44 ,
V_4 , V_7 , 2 , V_16 ) ;
}
if ( V_29 == 10 || V_29 == 11 ) {
V_32 = F_17 ( V_4 , V_7 + 2 , V_6 - 2 ) ;
F_18 ( V_45 [ V_46 ] , V_32 , V_22 , V_3 ) ;
V_7 += V_6 ;
continue;
} else if ( V_29 == 12 ) {
V_32 = F_17 ( V_4 , V_7 + 2 , V_6 - 2 ) ;
F_18 ( V_45 [ V_47 ] , V_32 , V_22 , V_3 ) ;
V_7 += V_6 ;
continue;
}
V_33 = F_19 ( V_4 , V_7 + 2 , V_22 , V_27 , V_48 ,
V_49 , & V_50 , & V_51 ,
NULL , NULL , V_34 , V_35 , FALSE ) ;
V_36 += F_20 ( V_33 , V_35 ) ;
if ( F_21 ( V_33 ) ) {
V_32 = F_17 ( V_4 , V_7 + V_36 ,
V_6 - V_36 ) ;
switch ( V_29 ) {
case 0 :
if ( V_6 <= 4 )
break;
F_18 ( V_45 [ V_52 ] , V_32 , V_22 , V_3 ) ;
break;
case 62 :
if ( V_6 <= 4 )
break;
F_18 ( V_45 [ V_53 ] , V_32 , V_22 , V_3 ) ;
break;
default:
F_18 ( V_45 [ V_54 ] , V_32 , V_22 , V_3 ) ;
break;
}
} else if ( V_33 == ( V_55 | V_56 ) ) {
F_4 ( V_27 , V_4 , V_7 + V_36 ,
V_6 - V_36 ) ;
}
if ( V_6 == 0 )
V_6 = 1 ;
V_7 += V_6 ;
}
return F_22 ( V_4 ) ;
}
void
F_23 ( void )
{
static T_11 V_57 [] = {
{ & V_44 ,
{ L_3 , L_4 ,
V_58 , V_59 , NULL , 0x1FF ,
L_5 , V_60 }
} ,
{ & V_39 ,
{ L_6 , L_7 ,
V_61 , V_59 , NULL , 0xE0 ,
NULL , V_60 }
} ,
{ & V_40 ,
{ L_8 , L_9 ,
V_61 , V_59 , NULL , 0x1E ,
NULL , V_60 }
} ,
{ & V_42 ,
{ L_10 , L_11 ,
V_61 , V_59 , NULL , 0 ,
NULL , V_60 }
} ,
{ & V_43 ,
{ L_12 , L_13 ,
V_61 , V_59 , NULL , 0 ,
NULL , V_60 }
} ,
{ & V_41 ,
{ L_14 , L_15 ,
V_61 , V_59 , NULL , 0 ,
NULL , V_60 }
} ,
{ & V_10 ,
{ L_16 , L_17 ,
V_62 , V_63 , NULL , 0 ,
NULL , V_60 }
} ,
{ & V_19 ,
{ L_18 , L_19 ,
V_61 , V_59 , NULL , 0 ,
NULL , V_60 }
} ,
{ & V_20 ,
{ L_20 , L_21 ,
V_61 , V_59 , NULL , 0 ,
NULL , V_60 }
} ,
{ & V_21 ,
{ L_22 , L_23 ,
V_61 , V_59 , NULL , 0 ,
NULL , V_60 }
} ,
{ & V_13 ,
{ L_24 , L_25 ,
V_61 , V_64 , NULL , 0 ,
NULL , V_60 }
} ,
{ & V_14 ,
{ L_26 , L_27 ,
V_61 , V_64 , NULL , 0 ,
NULL , V_60 }
} ,
{ & V_15 ,
{ L_28 , L_29 ,
V_58 , V_59 , NULL , 0 ,
NULL , V_60 }
} ,
{ & V_48 ,
{ L_30 , L_31 ,
V_58 , V_64 , NULL , 0 ,
NULL , V_60 }
} ,
{ & V_65 ,
{ L_32 , L_33 ,
V_58 , V_59 , NULL , V_66 ,
NULL , V_60 }
} ,
{ & V_67 ,
{ L_34 , L_35 ,
V_58 , V_59 , NULL , V_68 ,
NULL , V_60 }
} ,
{ & V_69 ,
{ L_36 , L_37 ,
V_70 , 8 , F_24 ( & V_71 ) , V_72 ,
NULL , V_60 }
} ,
{ & V_73 ,
{ L_36 , L_37 ,
V_70 , 16 , F_24 ( & V_71 ) , V_74 ,
NULL , V_60 }
} ,
{ & V_75 ,
{ L_38 , L_39 ,
V_70 , 8 , F_24 ( & V_71 ) , V_72 ,
NULL , V_60 }
} ,
{ & V_76 ,
{ L_38 , L_39 ,
V_70 , 16 , F_24 ( & V_71 ) , V_74 ,
NULL , V_60 }
} ,
{ & V_77 ,
{ L_40 , L_41 ,
V_58 , V_64 , F_25 ( V_78 ) , V_79 ,
NULL , V_60 }
} ,
{ & V_80 ,
{ L_42 , L_43 ,
V_61 , V_64 , F_25 ( V_81 ) , V_82 ,
NULL , V_60 }
} ,
{ & V_83 ,
{ L_44 , L_45 ,
V_61 , V_64 , F_25 ( V_84 ) , V_82 ,
NULL , V_60 }
} ,
{ & V_85 ,
{ L_46 , L_47 ,
V_58 , V_64 , F_25 ( V_86 ) , V_87 ,
NULL , V_60 }
} ,
{ & V_88 ,
{ L_46 , L_47 ,
V_61 , V_64 , F_25 ( V_86 ) , V_89 ,
NULL , V_60 }
} ,
{ & V_90 ,
{ L_46 , L_47 ,
V_58 , V_64 , F_25 ( V_86 ) , V_89 ,
NULL , V_60 }
} ,
} ;
static T_10 * V_91 [] = {
& V_38 ,
& V_12 ,
& V_49 ,
} ;
V_37 =
F_26 ( L_48 ,
L_49 , L_50 ) ;
F_27 ( V_37 , V_57 , F_28 ( V_57 ) ) ;
F_29 ( V_91 , F_28 ( V_91 ) ) ;
V_92 = F_30 ( L_50 , F_9 , V_37 ) ;
}
void
F_31 ( void )
{
V_45 [ V_52 ] = F_32 ( L_51 , V_37 ) ;
V_45 [ V_53 ] = F_32 ( L_52 , V_37 ) ;
V_45 [ V_46 ] = F_32 ( L_53 , V_37 ) ;
V_45 [ V_47 ] = F_32 ( L_54 , V_37 ) ;
V_45 [ V_54 ] = F_33 ( L_55 ) ;
F_34 ( L_56 , V_93 , V_92 ) ;
}
