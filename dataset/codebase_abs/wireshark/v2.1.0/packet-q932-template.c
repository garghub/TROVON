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
static int
F_17 ( T_1 * V_1 , T_2 * V_3 , T_3 * V_4 , void * T_10 V_30 ) {
T_11 V_2 ;
T_9 * V_27 ;
T_3 * V_31 ;
T_8 V_32 , V_33 ;
V_2 = 0 ;
V_27 = F_2 ( V_4 , V_34 , V_1 , V_2 , - 1 , V_35 ) ;
F_18 ( V_27 ) ;
V_32 = F_14 ( V_1 , V_2 ) ;
V_33 = F_14 ( V_1 , V_2 + 1 ) ;
V_31 = F_19 ( V_4 , V_1 , V_2 , - 1 , V_36 , NULL ,
F_20 ( V_32 , F_21 ( V_37 ) , L_1 ) ) ;
F_2 ( V_31 , V_38 , V_1 , V_2 , 1 , V_15 ) ;
F_2 ( V_31 , V_39 , V_1 , V_2 + 1 , 1 , V_15 ) ;
V_2 += 2 ;
if ( F_22 ( V_1 , V_2 ) <= 0 )
return V_2 ;
switch ( V_32 ) {
case V_40 :
F_1 ( V_1 , V_2 , V_3 , V_31 , V_33 ) ;
break;
case V_41 :
F_13 ( V_1 , V_2 , V_3 , V_31 , V_33 ) ;
break;
default:
if ( V_33 > 0 ) {
F_2 ( V_31 , V_42 , V_1 , V_2 , V_33 , V_35 ) ;
}
}
return F_23 ( V_1 ) ;
}
static int
F_24 ( T_1 * V_1 , T_2 * V_3 , T_3 * V_4 , void * T_10 V_30 ) {
return F_25 ( V_19 , V_1 , V_3 , V_4 ) ;
}
void F_26 ( void ) {
static T_12 V_43 [] = {
{ & V_38 , { L_2 , L_3 ,
V_44 , V_45 , F_21 ( V_37 ) , 0x0 ,
L_4 , V_46 } } ,
{ & V_39 , { L_5 , L_6 ,
V_44 , V_47 , NULL , 0x0 ,
L_7 , V_46 } } ,
{ & V_42 , { L_8 , L_9 ,
V_48 , V_49 , NULL , 0x0 ,
NULL , V_46 } } ,
{ & V_14 , { L_10 , L_11 ,
V_44 , V_45 , F_21 ( V_50 ) , 0x1F ,
NULL , V_46 } } ,
{ & V_28 , { L_12 , L_13 ,
V_44 , V_45 , F_21 ( V_51 ) , 0x0 ,
NULL , V_46 } } ,
#include "packet-q932-hfarr.c"
} ;
static T_11 * V_52 [] = {
& V_53 ,
& V_36 ,
#include "packet-q932-ettarr.c"
} ;
static T_13 V_54 [] = {
{ & V_20 , { L_14 , V_55 , V_56 , L_15 , V_57 } } ,
{ & V_23 , { L_16 , V_55 , V_56 , L_17 , V_57 } } ,
{ & V_21 , { L_18 , V_55 , V_56 , L_19 , V_57 } } ,
{ & V_29 , { L_20 , V_55 , V_56 , L_21 , V_57 } } ,
} ;
T_14 * V_58 ;
T_15 * V_59 ;
static const T_16 V_60 [] = {
{ L_22 , L_23 , V_61 } ,
{ L_24 , L_25 , V_62 } ,
{ NULL , NULL , - 1 }
} ;
V_34 = F_27 ( V_63 , V_64 , V_65 ) ;
F_28 ( L_26 , F_24 , V_34 ) ;
F_29 ( V_34 , V_43 , F_30 ( V_43 ) ) ;
F_31 ( V_52 , F_30 ( V_52 ) ) ;
V_59 = F_32 ( V_34 ) ;
F_33 ( V_59 , V_54 , F_30 ( V_54 ) ) ;
F_34 ( & V_17 ) ;
V_17 . V_66 = F_35 ( L_27 , L_28 , V_34 , V_67 , V_49 , V_68 ) ;
V_17 . V_69 = F_35 ( L_29 , L_30 , V_34 , V_67 , V_49 , V_68 ) ;
V_17 . V_70 = F_35 ( L_31 , L_32 , V_34 , V_67 , V_49 , V_68 ) ;
V_71 = F_35 ( L_33 , L_34 , V_34 , V_72 , V_45 , V_68 ) ;
V_73 = F_35 ( L_35 , L_36 , V_34 , V_72 , V_45 , V_68 ) ;
V_74 = F_35 ( L_37 , L_38 , V_34 , V_72 , V_45 , V_68 ) ;
V_75 = F_35 ( L_39 , L_40 , V_34 , V_72 , V_45 , V_68 ) ;
V_76 = F_35 ( L_41 , L_42 , V_34 , V_72 , V_45 , V_68 ) ;
V_77 = F_35 ( L_43 , L_44 , V_34 , V_72 , V_45 , V_68 ) ;
V_58 = F_36 ( V_34 , V_78 ) ;
F_37 ( V_58 , L_45 ,
L_46 ,
L_46 ,
& V_79 , V_60 , FALSE ) ;
}
void V_78 ( void ) {
T_17 V_80 ;
static T_5 V_81 = FALSE ;
if ( ! V_81 ) {
V_80 = F_38 ( F_17 , V_34 ) ;
F_39 ( L_47 , ( 0x00 << 8 ) | V_40 , V_80 ) ;
F_39 ( L_47 , ( 0x00 << 8 ) | V_41 , V_80 ) ;
V_19 = F_40 ( L_48 , V_34 ) ;
}
if( V_79 == V_61 ) {
V_17 . V_82 = V_71 ;
V_17 . V_83 = V_73 ;
V_17 . V_84 = V_74 ;
} else{
V_17 . V_82 = V_75 ;
V_17 . V_83 = V_76 ;
V_17 . V_84 = V_77 ;
}
}
