static void
F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 , T_3 * V_4 , int V_5 ) {
T_4 V_6 ;
T_5 V_7 ;
T_6 V_8 ;
T_7 V_9 ;
int V_10 , V_11 ;
int V_12 ;
T_1 * V_13 ;
V_12 = V_2 + V_5 ;
F_2 ( V_4 , V_14 , V_1 , V_2 , 1 , V_15 ) ;
V_2 ++ ;
while ( V_2 < V_12 ) {
V_10 = V_2 ;
V_2 = F_3 ( V_1 , V_2 , & V_6 , & V_7 , & V_8 ) ;
V_2 = F_4 ( V_1 , V_2 , & V_9 , NULL ) ;
V_11 = V_2 + V_9 ;
V_13 = F_5 ( V_1 , V_10 , V_11 - V_10 ) ;
switch ( V_6 ) {
case V_16 :
switch ( V_8 ) {
case 10 :
F_6 ( V_13 , V_3 , V_4 , NULL ) ;
break;
case 18 :
F_7 ( V_13 , V_3 , V_4 , NULL ) ;
break;
case 11 :
F_8 ( V_13 , V_3 , V_4 , NULL ) ;
break;
case 1 :
case 2 :
case 3 :
case 4 :
V_17 . V_18 = 1 ;
F_9 ( V_19 , V_13 , V_3 , V_4 , & V_17 ) ;
break;
case 12 :
case 14 :
case 15 :
case 17 :
V_2 = F_10 ( V_3 , V_4 , V_1 , V_10 , NULL , NULL , NULL ) ;
V_2 = F_11 ( V_3 , V_4 , V_1 , V_2 , NULL , NULL ) ;
F_12 ( V_4 , V_3 , & V_20 , V_1 , V_2 , V_9 ) ;
break;
default:
V_2 = F_10 ( V_3 , V_4 , V_1 , V_10 , NULL , NULL , NULL ) ;
V_2 = F_11 ( V_3 , V_4 , V_1 , V_2 , NULL , NULL ) ;
F_12 ( V_4 , V_3 , & V_21 , V_1 , V_2 , V_9 ) ;
}
break;
case V_22 :
switch ( V_8 ) {
case 0 :
case 1 :
case 2 :
case 3 :
case 4 :
V_2 = F_10 ( V_3 , V_4 , V_1 , V_10 , NULL , NULL , NULL ) ;
V_2 = F_11 ( V_3 , V_4 , V_1 , V_2 , NULL , NULL ) ;
F_12 ( V_4 , V_3 , & V_23 , V_1 , V_2 , V_9 ) ;
break;
default:
V_2 = F_10 ( V_3 , V_4 , V_1 , V_10 , NULL , NULL , NULL ) ;
V_2 = F_11 ( V_3 , V_4 , V_1 , V_2 , NULL , NULL ) ;
F_12 ( V_4 , V_3 , & V_21 , V_1 , V_2 , V_9 ) ;
}
break;
default:
V_2 = F_10 ( V_3 , V_4 , V_1 , V_10 , NULL , NULL , NULL ) ;
V_2 = F_11 ( V_3 , V_4 , V_1 , V_2 , NULL , NULL ) ;
F_12 ( V_4 , V_3 , & V_21 , V_1 , V_2 , V_9 ) ;
}
V_2 = V_11 ;
}
}
static void
F_13 ( T_1 * V_1 , int V_2 , T_2 * V_3 , T_3 * V_4 , int V_5 ) {
int V_24 = V_5 ;
T_8 V_25 = 0 ;
T_7 V_26 = 0 ;
T_9 * V_27 ;
while ( ( V_24 > 0 ) && ! ( V_25 & 0x80 ) ) {
V_25 = F_14 ( V_1 , V_2 ++ ) ;
V_24 -- ;
V_26 <<= 7 ;
V_26 |= V_25 & 0x7F ;
}
V_27 = F_15 ( V_4 , V_28 , V_1 , V_2 - ( V_5 - V_24 ) , V_5 - V_24 , V_26 ) ;
if ( V_24 > 0 ) {
F_16 ( V_3 , V_27 , & V_29 ) ;
}
}
static void
F_17 ( T_1 * V_1 , T_2 * V_3 , T_3 * V_4 ) {
T_10 V_2 ;
T_9 * V_27 ;
T_3 * V_30 ;
T_8 V_31 , V_32 ;
V_2 = 0 ;
V_27 = F_2 ( V_4 , V_33 , V_1 , V_2 , - 1 , V_34 ) ;
F_18 ( V_27 ) ;
V_31 = F_14 ( V_1 , V_2 ) ;
V_32 = F_14 ( V_1 , V_2 + 1 ) ;
V_30 = F_19 ( V_4 , V_1 , V_2 , - 1 , V_35 , NULL ,
F_20 ( V_31 , F_21 ( V_36 ) , L_1 ) ) ;
F_2 ( V_30 , V_37 , V_1 , V_2 , 1 , V_15 ) ;
F_2 ( V_30 , V_38 , V_1 , V_2 + 1 , 1 , V_15 ) ;
V_2 += 2 ;
if ( F_22 ( V_1 , V_2 ) <= 0 )
return;
switch ( V_31 ) {
case V_39 :
F_1 ( V_1 , V_2 , V_3 , V_30 , V_32 ) ;
break;
case V_40 :
F_13 ( V_1 , V_2 , V_3 , V_30 , V_32 ) ;
break;
default:
if ( V_32 > 0 ) {
F_2 ( V_30 , V_41 , V_1 , V_2 , V_32 , V_34 ) ;
}
}
}
static void
F_23 ( T_1 * V_1 , T_2 * V_3 , T_3 * V_4 ) {
F_24 ( V_19 , V_1 , V_3 , V_4 ) ;
}
void F_25 ( void ) {
static T_11 V_42 [] = {
{ & V_37 , { L_2 , L_3 ,
V_43 , V_44 , F_21 ( V_36 ) , 0x0 ,
L_4 , V_45 } } ,
{ & V_38 , { L_5 , L_6 ,
V_43 , V_46 , NULL , 0x0 ,
L_7 , V_45 } } ,
{ & V_41 , { L_8 , L_9 ,
V_47 , V_48 , NULL , 0x0 ,
NULL , V_45 } } ,
{ & V_14 , { L_10 , L_11 ,
V_43 , V_44 , F_21 ( V_49 ) , 0x1F ,
NULL , V_45 } } ,
{ & V_28 , { L_12 , L_13 ,
V_43 , V_44 , F_21 ( V_50 ) , 0x0 ,
NULL , V_45 } } ,
#include "packet-q932-hfarr.c"
} ;
static T_10 * V_51 [] = {
& V_52 ,
& V_35 ,
#include "packet-q932-ettarr.c"
} ;
static T_12 V_53 [] = {
{ & V_20 , { L_14 , V_54 , V_55 , L_15 , V_56 } } ,
{ & V_23 , { L_16 , V_54 , V_55 , L_17 , V_56 } } ,
{ & V_21 , { L_18 , V_54 , V_55 , L_19 , V_56 } } ,
{ & V_29 , { L_20 , V_54 , V_55 , L_21 , V_56 } } ,
} ;
T_13 * V_57 ;
T_14 * V_58 ;
static const T_15 V_59 [] = {
{ L_22 , L_23 , 0 } ,
{ L_24 , L_25 , 1 } ,
{ NULL , NULL , - 1 }
} ;
V_33 = F_26 ( V_60 , V_61 , V_62 ) ;
F_27 ( L_26 , F_23 , V_33 ) ;
F_28 ( V_33 , V_42 , F_29 ( V_42 ) ) ;
F_30 ( V_51 , F_29 ( V_51 ) ) ;
V_58 = F_31 ( V_33 ) ;
F_32 ( V_58 , V_53 , F_29 ( V_53 ) ) ;
F_33 ( & V_17 ) ;
V_17 . V_63 = F_34 ( L_27 , L_28 , V_64 , V_48 ) ;
V_17 . V_65 = F_34 ( L_29 , L_30 , V_64 , V_48 ) ;
V_17 . V_66 = F_34 ( L_31 , L_32 , V_64 , V_48 ) ;
V_67 = F_34 ( L_33 , L_34 , V_68 , V_44 ) ;
V_69 = F_34 ( L_35 , L_36 , V_68 , V_44 ) ;
V_70 = F_34 ( L_37 , L_38 , V_68 , V_44 ) ;
V_71 = F_34 ( L_39 , L_40 , V_68 , V_44 ) ;
V_72 = F_34 ( L_41 , L_42 , V_68 , V_44 ) ;
V_73 = F_34 ( L_43 , L_44 , V_68 , V_44 ) ;
V_57 = F_35 ( V_33 , V_74 ) ;
F_36 ( V_57 , L_45 ,
L_46 ,
L_46 ,
& V_75 , V_59 , FALSE ) ;
}
void V_74 ( void ) {
T_16 V_76 ;
static T_5 V_77 = FALSE ;
if ( ! V_77 ) {
V_76 = F_37 ( F_17 , V_33 ) ;
F_38 ( L_47 , ( 0x00 << 8 ) | V_39 , V_76 ) ;
F_38 ( L_47 , ( 0x00 << 8 ) | V_40 , V_76 ) ;
V_19 = F_39 ( L_48 ) ;
}
if( V_75 == 0 ) {
V_17 . V_78 = V_67 ;
V_17 . V_79 = V_69 ;
V_17 . V_80 = V_70 ;
} else{
V_17 . V_78 = V_71 ;
V_17 . V_79 = V_72 ;
V_17 . V_80 = V_73 ;
}
}
