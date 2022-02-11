static int
F_1 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_3 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_4 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 19 "../../asn1/smrse/smrse.cnf"
char * V_2 , V_3 [ 21 ] ;
T_11 V_4 , V_5 ;
T_12 V_6 ;
T_1 V_7 , V_8 ;
T_13 V_9 ;
T_11 V_10 ;
static char V_11 [ 16 ] = { '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'A' , 'B' , 'C' , 'D' , 'E' , 'F' } ;
V_5 = T_5 ;
T_5 = F_5 ( T_7 -> V_12 , T_9 , T_4 , T_5 , & V_6 , & V_7 , & V_9 ) ;
T_5 = F_6 ( T_7 -> V_12 , T_9 , T_4 , T_5 , & V_10 , & V_8 ) ;
if( V_10 > 10 ) {
V_10 = 10 ;
}
V_2 = V_3 ;
for( V_4 = 0 ; V_4 < V_10 ; V_4 ++ ) {
* V_2 ++ = V_11 [ F_7 ( T_4 , T_5 ) & 0x0f ] ;
* V_2 ++ = V_11 [ ( F_7 ( T_4 , T_5 ) >> 4 ) & 0x0f ] ;
T_5 ++ ;
}
* V_2 = 0 ;
F_8 ( T_9 , V_13 , T_4 , V_5 , T_5 - V_5 , V_3 ) ;
return T_5 ;
return T_5 ;
}
static int
F_9 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_10 ( T_7 , T_9 , T_4 , T_5 ,
V_14 , T_10 , V_15 ,
NULL ) ;
return T_5 ;
}
static int
F_11 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_16 , T_10 , V_17 ) ;
return T_5 ;
}
static int
F_13 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_14 ( T_2 , V_18 ,
T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_15 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_19 , T_10 , V_20 ) ;
return T_5 ;
}
static int
F_16 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_17 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_18 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_21 , T_10 , V_22 ) ;
return T_5 ;
}
static int
F_19 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_20 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_23 , T_10 , V_24 ) ;
return T_5 ;
}
static int
F_21 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_25 , T_10 , V_26 ) ;
return T_5 ;
}
static int
F_22 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_23 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 , NULL ) ;
return T_5 ;
}
static int
F_24 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_25 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_17 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_26 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_27 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_27 , T_10 , V_28 ) ;
return T_5 ;
}
static int
F_28 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_29 , T_10 , V_30 ) ;
return T_5 ;
}
static int
F_29 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_31 , T_10 , V_32 ) ;
return T_5 ;
}
static int
F_30 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_31 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_33 , T_10 , V_34 ) ;
return T_5 ;
}
static int
F_32 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_35 , T_10 , V_36 ) ;
return T_5 ;
}
static int
F_33 ( T_3 * T_4 , T_14 * V_12 , T_8 * V_37 , void * T_15 V_1 )
{
T_16 * V_38 = NULL ;
T_8 * T_9 = NULL ;
T_17 V_39 , V_9 ;
int T_5 = 0 ;
T_6 V_40 ;
F_34 ( & V_40 , V_41 , TRUE , V_12 ) ;
V_39 = F_7 ( T_4 , 0 ) ;
V_9 = F_7 ( T_4 , 3 ) ;
if( V_39 != 126 )
return 0 ;
if( ( V_9 < 1 ) || ( V_9 > 11 ) )
return 0 ;
if( V_37 ) {
V_38 = F_35 ( V_37 , V_42 , T_4 , 0 , - 1 , V_43 ) ;
T_9 = F_36 ( V_38 , V_44 ) ;
}
F_37 ( V_12 -> V_45 , V_46 , L_1 ) ;
F_38 ( V_12 -> V_45 , V_47 , F_39 ( V_9 , V_48 , L_2 ) ) ;
F_35 ( T_9 , V_49 , T_4 , 0 , 1 , V_50 ) ;
F_35 ( T_9 , V_51 , T_4 , 1 , 2 , V_50 ) ;
F_35 ( T_9 , V_52 , T_4 , 3 , 1 , V_50 ) ;
switch( V_9 ) {
case 1 :
case 2 :
T_5 = 4 ;
break;
case 3 :
T_5 = F_15 ( FALSE , T_4 , 4 , & V_40 , T_9 , - 1 ) ;
break;
case 4 :
T_5 = F_18 ( FALSE , T_4 , 4 , & V_40 , T_9 , - 1 ) ;
break;
case 5 :
T_5 = F_20 ( FALSE , T_4 , 4 , & V_40 , T_9 , - 1 ) ;
break;
case 6 :
T_5 = F_21 ( FALSE , T_4 , 4 , & V_40 , T_9 , - 1 ) ;
break;
case 7 :
T_5 = F_27 ( FALSE , T_4 , 4 , & V_40 , T_9 , - 1 ) ;
break;
case 8 :
T_5 = F_28 ( FALSE , T_4 , 4 , & V_40 , T_9 , - 1 ) ;
break;
case 9 :
T_5 = F_29 ( FALSE , T_4 , 4 , & V_40 , T_9 , - 1 ) ;
break;
case 10 :
T_5 = F_31 ( FALSE , T_4 , 4 , & V_40 , T_9 , - 1 ) ;
break;
case 11 :
T_5 = F_32 ( FALSE , T_4 , 4 , & V_40 , T_9 , - 1 ) ;
break;
}
return T_5 ;
}
void F_40 ( void ) {
static T_18 V_53 [] = {
{ & V_49 , {
L_3 , L_4 , V_54 , V_55 ,
NULL , 0 , L_5 , V_56 } } ,
{ & V_52 , {
L_6 , L_7 , V_54 , V_55 ,
F_41 ( V_48 ) , 0 , NULL , V_56 } } ,
{ & V_51 , {
L_8 , L_9 , V_57 , V_55 ,
NULL , 0 , L_10 , V_56 } } ,
{ & V_13 ,
{ L_11 , L_12 ,
V_58 , V_59 , NULL , 0 ,
L_13 , V_56 } } ,
#line 1 "../../asn1/smrse/packet-smrse-hfarr.c"
{ & V_60 ,
{ L_14 , L_15 ,
V_61 , V_59 , NULL , 0 ,
L_16 , V_56 } } ,
{ & V_62 ,
{ L_17 , L_18 ,
V_58 , V_59 , NULL , 0 ,
NULL , V_56 } } ,
{ & V_63 ,
{ L_19 , L_20 ,
V_64 , V_55 , F_41 ( V_65 ) , 0 ,
NULL , V_56 } } ,
{ & V_66 ,
{ L_21 , L_22 ,
V_64 , V_55 , F_41 ( V_67 ) , 0 ,
NULL , V_56 } } ,
{ & V_68 ,
{ L_23 , L_24 ,
V_69 , V_55 , F_41 ( V_70 ) , 0 ,
NULL , V_56 } } ,
{ & V_71 ,
{ L_25 , L_26 ,
V_72 , V_59 , NULL , 0 ,
L_27 , V_56 } } ,
{ & V_73 ,
{ L_28 , L_29 ,
V_64 , V_55 , F_41 ( V_74 ) , 0 ,
L_30 , V_56 } } ,
{ & V_75 ,
{ L_31 , L_32 ,
V_76 , V_59 , NULL , 0 ,
L_33 , V_56 } } ,
{ & V_77 ,
{ L_34 , L_35 ,
V_76 , V_59 , NULL , 0 ,
L_33 , V_56 } } ,
{ & V_78 ,
{ L_36 , L_37 ,
V_69 , V_55 , NULL , 0 ,
L_38 , V_56 } } ,
{ & V_79 ,
{ L_39 , L_40 ,
V_61 , V_59 , NULL , 0 ,
L_16 , V_56 } } ,
{ & V_80 ,
{ L_41 , L_42 ,
V_61 , V_59 , NULL , 0 ,
L_16 , V_56 } } ,
{ & V_81 ,
{ L_43 , L_44 ,
V_72 , V_59 , NULL , 0 ,
L_45 , V_56 } } ,
{ & V_82 ,
{ L_46 , L_47 ,
V_61 , V_59 , NULL , 0 ,
L_16 , V_56 } } ,
{ & V_83 ,
{ L_48 , L_49 ,
V_69 , V_55 , NULL , 0 ,
L_50 , V_56 } } ,
{ & V_84 ,
{ L_51 , L_52 ,
V_69 , V_55 , NULL , 0 ,
L_38 , V_56 } } ,
{ & V_85 ,
{ L_53 , L_54 ,
V_61 , V_59 , NULL , 0 ,
L_16 , V_56 } } ,
{ & V_86 ,
{ L_55 , L_56 ,
V_72 , V_59 , NULL , 0 ,
L_45 , V_56 } } ,
{ & V_87 ,
{ L_57 , L_58 ,
V_61 , V_59 , NULL , 0 ,
L_16 , V_56 } } ,
{ & V_88 ,
{ L_59 , L_60 ,
V_72 , V_59 , NULL , 0 ,
L_61 , V_56 } } ,
{ & V_89 ,
{ L_62 , L_63 ,
V_69 , V_55 , NULL , 0 ,
L_38 , V_56 } } ,
{ & V_90 ,
{ L_64 , L_65 ,
V_64 , V_55 , F_41 ( V_91 ) , 0 ,
NULL , V_56 } } ,
{ & V_92 ,
{ L_66 , L_67 ,
V_76 , V_59 , NULL , 0 ,
L_33 , V_56 } } ,
{ & V_93 ,
{ L_68 , L_69 ,
V_61 , V_59 , NULL , 0 ,
L_16 , V_56 } } ,
{ & V_94 ,
{ L_70 , L_71 ,
V_72 , V_59 , NULL , 0 ,
L_45 , V_56 } } ,
{ & V_95 ,
{ L_72 , L_73 ,
V_61 , V_59 , NULL , 0 ,
L_16 , V_56 } } ,
#line 159 "../../asn1/smrse/packet-smrse-template.c"
} ;
static T_19 * V_96 [] = {
& V_44 ,
#line 1 "../../asn1/smrse/packet-smrse-ettarr.c"
& V_20 ,
& V_17 ,
& V_15 ,
& V_22 ,
& V_24 ,
& V_26 ,
& V_28 ,
& V_30 ,
& V_32 ,
& V_34 ,
& V_36 ,
#line 165 "../../asn1/smrse/packet-smrse-template.c"
} ;
V_42 = F_42 ( V_97 , V_98 , V_99 ) ;
F_43 ( V_42 , V_53 , F_44 ( V_53 ) ) ;
F_45 ( V_96 , F_44 ( V_96 ) ) ;
}
void F_46 ( void ) {
T_20 V_100 ;
V_100 = F_47 ( F_33 , V_42 ) ;
F_48 ( L_74 , V_101 , V_100 ) ;
}
