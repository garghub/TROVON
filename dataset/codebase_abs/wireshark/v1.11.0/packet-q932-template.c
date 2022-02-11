void
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
V_13 = F_5 ( V_1 , V_10 , V_11 - V_10 , V_11 - V_10 ) ;
switch ( V_6 ) {
case V_16 :
switch ( V_8 ) {
case 10 :
F_6 ( V_13 , V_3 , V_4 ) ;
break;
case 18 :
F_7 ( V_13 , V_3 , V_4 ) ;
break;
case 11 :
F_8 ( V_13 , V_3 , V_4 ) ;
break;
case 1 :
case 2 :
case 3 :
case 4 :
V_17 . V_18 = 1 ;
V_3 -> V_19 = & V_17 ;
F_9 ( V_20 , V_13 , V_3 , V_4 ) ;
break;
case 12 :
case 14 :
case 15 :
case 17 :
V_2 = F_10 ( V_3 , V_4 , V_1 , V_10 , NULL , NULL , NULL ) ;
V_2 = F_11 ( V_3 , V_4 , V_1 , V_2 , NULL , NULL ) ;
F_12 ( V_4 , V_1 , V_2 , V_9 , L_1 ) ;
break;
default:
V_2 = F_10 ( V_3 , V_4 , V_1 , V_10 , NULL , NULL , NULL ) ;
V_2 = F_11 ( V_3 , V_4 , V_1 , V_2 , NULL , NULL ) ;
F_12 ( V_4 , V_1 , V_2 , V_9 , L_2 ) ;
}
break;
case V_21 :
switch ( V_8 ) {
case 0 :
case 1 :
case 2 :
case 3 :
case 4 :
V_2 = F_10 ( V_3 , V_4 , V_1 , V_10 , NULL , NULL , NULL ) ;
V_2 = F_11 ( V_3 , V_4 , V_1 , V_2 , NULL , NULL ) ;
F_12 ( V_4 , V_1 , V_2 , V_9 , L_3 ) ;
break;
default:
V_2 = F_10 ( V_3 , V_4 , V_1 , V_10 , NULL , NULL , NULL ) ;
V_2 = F_11 ( V_3 , V_4 , V_1 , V_2 , NULL , NULL ) ;
F_12 ( V_4 , V_1 , V_2 , V_9 , L_2 ) ;
}
break;
default:
V_2 = F_10 ( V_3 , V_4 , V_1 , V_10 , NULL , NULL , NULL ) ;
V_2 = F_11 ( V_3 , V_4 , V_1 , V_2 , NULL , NULL ) ;
F_12 ( V_4 , V_1 , V_2 , V_9 , L_2 ) ;
}
V_2 = V_11 ;
}
}
static void
F_13 ( T_1 * V_1 , int V_2 , T_2 * V_3 V_22 , T_3 * V_4 , int V_5 ) {
int V_23 = V_5 ;
T_8 V_24 = 0 ;
T_7 V_25 = 0 ;
while ( ( V_23 > 0 ) && ! ( V_24 & 0x80 ) ) {
V_24 = F_14 ( V_1 , V_2 ++ ) ;
V_23 -- ;
V_25 <<= 7 ;
V_25 |= V_24 & 0x7F ;
}
F_15 ( V_4 , V_26 , V_1 , V_2 - ( V_5 - V_23 ) , V_5 - V_23 , V_25 ) ;
if ( V_23 > 0 ) {
F_12 ( V_4 , V_1 , V_2 - V_23 , V_23 , L_4 , F_16 ( V_1 , V_2 - V_23 , V_23 ) ) ;
}
}
static void
F_17 ( T_1 * V_1 , T_2 * V_3 , T_3 * V_4 ) {
T_9 V_2 ;
T_10 * V_27 , * V_28 ;
T_3 * V_29 ;
T_8 V_30 , V_31 ;
V_2 = 0 ;
V_27 = F_2 ( V_4 , V_32 , V_1 , V_2 , - 1 , V_33 ) ;
F_18 ( V_27 ) ;
V_30 = F_14 ( V_1 , V_2 ) ;
V_31 = F_14 ( V_1 , V_2 + 1 ) ;
V_28 = F_12 ( V_4 , V_1 , V_2 , - 1 , L_5 ,
F_19 ( V_30 , F_20 ( V_34 ) , L_6 ) ) ;
V_29 = F_21 ( V_28 , V_35 ) ;
F_2 ( V_29 , V_36 , V_1 , V_2 , 1 , V_15 ) ;
F_2 ( V_29 , V_37 , V_1 , V_2 + 1 , 1 , V_15 ) ;
V_2 += 2 ;
if ( F_22 ( V_1 , V_2 ) <= 0 )
return;
switch ( V_30 ) {
case V_38 :
F_1 ( V_1 , V_2 , V_3 , V_29 , V_31 ) ;
break;
case V_39 :
F_13 ( V_1 , V_2 , V_3 , V_29 , V_31 ) ;
break;
default:
if ( V_31 > 0 ) {
if ( V_4 ) F_2 ( V_29 , V_40 , V_1 , V_2 , V_31 , V_33 ) ;
}
}
}
static void
F_23 ( T_1 * V_1 , T_2 * V_3 , T_3 * V_4 ) {
F_9 ( V_20 , V_1 , V_3 , V_4 ) ;
}
void F_24 ( void ) {
static T_11 V_41 [] = {
{ & V_36 , { L_7 , L_8 ,
V_42 , V_43 , F_20 ( V_34 ) , 0x0 ,
L_9 , V_44 } } ,
{ & V_37 , { L_10 , L_11 ,
V_42 , V_45 , NULL , 0x0 ,
L_12 , V_44 } } ,
{ & V_40 , { L_13 , L_14 ,
V_46 , V_47 , NULL , 0x0 ,
NULL , V_44 } } ,
{ & V_14 , { L_15 , L_16 ,
V_42 , V_43 , F_20 ( V_48 ) , 0x1F ,
NULL , V_44 } } ,
{ & V_26 , { L_17 , L_18 ,
V_42 , V_43 , F_20 ( V_49 ) , 0x0 ,
NULL , V_44 } } ,
#include "packet-q932-hfarr.c"
} ;
static T_9 * V_50 [] = {
& V_51 ,
& V_35 ,
#include "packet-q932-ettarr.c"
} ;
T_12 * V_52 ;
static const T_13 V_53 [] = {
{ L_19 , L_20 , 0 } ,
{ L_21 , L_22 , 1 } ,
{ NULL , NULL , - 1 }
} ;
V_32 = F_25 ( V_54 , V_55 , V_56 ) ;
F_26 ( L_23 , F_23 , V_32 ) ;
F_27 ( V_32 , V_41 , F_28 ( V_41 ) ) ;
F_29 ( V_50 , F_28 ( V_50 ) ) ;
F_30 ( & V_17 ) ;
V_17 . V_57 = F_31 ( L_24 , L_25 , V_58 , V_47 ) ;
V_17 . V_59 = F_31 ( L_26 , L_27 , V_58 , V_47 ) ;
V_17 . V_60 = F_31 ( L_28 , L_29 , V_58 , V_47 ) ;
V_61 = F_31 ( L_30 , L_31 , V_62 , V_43 ) ;
V_63 = F_31 ( L_32 , L_33 , V_62 , V_43 ) ;
V_64 = F_31 ( L_34 , L_35 , V_62 , V_43 ) ;
V_65 = F_31 ( L_36 , L_37 , V_62 , V_43 ) ;
V_66 = F_31 ( L_38 , L_39 , V_62 , V_43 ) ;
V_67 = F_31 ( L_40 , L_41 , V_62 , V_43 ) ;
V_52 = F_32 ( V_32 , V_68 ) ;
F_33 ( V_52 , L_42 ,
L_43 ,
L_43 ,
& V_69 , V_53 , FALSE ) ;
}
void V_68 ( void ) {
T_14 V_70 ;
static T_5 V_71 = FALSE ;
if ( ! V_71 ) {
V_70 = F_34 ( F_17 , V_32 ) ;
F_35 ( L_44 , ( 0x00 << 8 ) | V_38 , V_70 ) ;
F_35 ( L_44 , ( 0x00 << 8 ) | V_39 , V_70 ) ;
V_20 = F_36 ( L_45 ) ;
}
if( V_69 == 0 ) {
V_17 . V_72 = V_61 ;
V_17 . V_73 = V_63 ;
V_17 . V_74 = V_64 ;
} else{
V_17 . V_72 = V_65 ;
V_17 . V_73 = V_66 ;
V_17 . V_74 = V_67 ;
}
}
