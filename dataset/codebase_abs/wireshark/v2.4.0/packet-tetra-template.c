static T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 = 0 ;
switch( V_1 ) {
case V_3 :
V_2 = 14 ;
break;
case V_4 :
V_2 = 268 ;
break;
case V_5 :
V_2 = 124 ; ;
break;
case V_6 :
V_2 = 60 ;
break;
case V_7 :
V_2 = 124 ;
break;
case V_8 :
V_2 = 274 ;
break;
case V_9 :
V_2 = 137 ;
break;
case V_10 :
V_2 = 144 ;
break;
case V_11 :
V_2 = 288 ;
break;
case V_12 :
V_2 = 124 ;
break;
case V_13 :
V_2 = 92 ;
break;
default:
V_2 = 0 ;
break;
}
return V_2 ;
}
static T_1 F_2 ( T_2 V_1 )
{
T_1 V_2 = 0 ;
switch( V_1 ) {
case V_3 :
V_2 = 14 ;
break;
case V_4 :
V_2 = 268 ;
break;
case V_5 :
V_2 = 124 ;
break;
case V_6 :
V_2 = 60 ;
break;
case V_7 :
V_2 = 124 ;
break;
case V_8 :
V_2 = 274 ;
break;
case V_9 :
V_2 = 137 ;
break;
case V_10 :
V_2 = 144 ;
break;
case V_11 :
V_2 = 288 ;
break;
case V_12 :
V_2 = 124 ;
break;
}
return V_2 ;
}
void F_3 ( int V_1 , int V_14 , T_3 * V_15 , T_4 * V_16 , T_5 * V_17 )
{
T_6 * V_18 ;
T_4 * V_19 ;
T_7 V_20 ;
V_18 = F_4 ( V_16 , V_21 ,
V_15 , 0 , F_5 ( V_15 ) , V_22 ) ;
V_19 = F_6 ( V_18 , V_23 ) ;
switch( V_1 ) {
case V_3 :
F_7 ( V_15 , V_17 , V_19 , NULL ) ;
break;
case V_4 :
V_20 = F_8 ( V_15 , 0 ) ;
switch( V_20 >> 6 ) {
case 0 :
if ( V_14 == V_24 )
F_9 ( V_15 , V_17 , V_19 , NULL ) ;
else
F_10 ( V_15 , V_17 , V_19 , NULL ) ;
break;
case 1 :
if( ( V_20 >> 5 ) == 3 ) {
if ( V_14 == V_24 )
F_11 ( V_15 , V_17 , V_19 , NULL ) ;
else
F_12 ( V_15 , V_17 , V_19 , NULL ) ;
} else
F_13 ( V_15 , V_17 , V_19 , NULL ) ;
break;
case 2 :
F_14 ( V_15 , V_17 , V_19 , NULL ) ;
break;
}
break;
case V_5 :
V_20 = F_8 ( V_15 , 0 ) ;
switch( V_20 >> 6 ) {
case 0 :
F_9 ( V_15 , V_17 , V_19 , NULL ) ;
break;
case 1 :
if( ( V_20 >> 5 ) == 3 )
F_15 ( V_15 , V_17 , V_19 , NULL ) ;
else
F_16 ( V_15 , V_17 , V_19 , NULL ) ;
break;
case 2 :
F_14 ( V_15 , V_17 , V_19 , NULL ) ;
break;
}
break;
case V_13 :
V_20 = F_8 ( V_15 , 0 ) ;
switch( V_20 >> 7 ) {
case 0 :
F_17 ( V_15 , V_17 , V_19 , NULL ) ;
break;
case 1 :
F_18 ( V_15 , V_17 , V_19 , NULL ) ;
break;
}
break;
case V_6 :
F_19 ( V_17 -> V_25 , V_26 , NULL , L_1 ) ;
F_20 ( V_15 , V_17 , V_19 , NULL ) ;
break;
case V_7 :
F_19 ( V_17 -> V_25 , V_26 , NULL , L_2 ) ;
F_21 ( V_15 , V_17 , V_19 , NULL ) ;
break;
case V_12 :
V_20 = F_8 ( V_15 , 0 ) ;
switch( V_20 >> 6 ) {
case 0 :
F_9 ( V_15 , V_17 , V_19 , NULL ) ;
break;
case 1 :
if( ( V_20 >> 5 ) == 3 ) {
if ( V_14 == V_24 )
F_15 ( V_15 , V_17 , V_19 , NULL ) ;
else
F_22 ( V_15 , V_17 , V_19 , NULL ) ;
} else
F_16 ( V_15 , V_17 , V_19 , NULL ) ;
break;
case 2 :
F_14 ( V_15 , V_17 , V_19 , NULL ) ;
break;
}
break;
case V_8 :
F_19 ( V_17 -> V_25 , V_26 , NULL , L_3 ) ;
break;
}
}
static void F_23 ( T_3 * V_27 , T_5 * V_17 , T_4 * V_28 , int V_29 )
{
T_2 V_30 = 0 ;
T_2 V_31 = 0 , V_32 ;
T_2 V_1 ;
T_1 V_33 = 0 ;
T_6 * V_18 ;
T_4 * V_34 = NULL ;
T_3 * V_35 ;
V_30 = F_24 ( V_27 , V_29 ) ;
F_25 ( V_28 , V_36 , V_27 , V_29 , 4 , V_30 ) ;
V_29 += 4 ;
V_30 = F_24 ( V_27 , V_29 ) ;
F_25 ( V_28 , V_37 , V_27 , V_29 , 4 , V_30 ) ;
V_31 = V_30 & 0x3 ;
V_18 = F_25 ( V_28 , V_38 , V_27 , V_29 , 4 , V_31 ) ;
V_34 = F_6 ( V_18 , V_23 ) ;
if ( V_31 > 3 ) {
F_26 ( V_17 , V_18 , & V_39 ) ;
V_31 = 3 ;
}
V_33 = V_29 + 4 ;
for( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
T_1 V_40 , V_41 , V_42 ;
T_1 V_43 [ 3 ] ;
V_43 [ 0 ] = V_44 ;
V_43 [ 1 ] = V_45 ;
V_43 [ 2 ] = V_46 ;
V_1 = ( V_30 >> ( ( V_32 + 1 ) * 4 ) ) & 0xf ;
F_25 ( V_34 , V_43 [ V_32 ] , V_27 , V_29 , 4 , V_1 ) ;
F_27 ( V_34 , V_47 , V_27 , V_29 , 4 , ! ( V_30 >> ( V_32 + 2 ) & 0x01 ) ) ;
V_41 = F_1 ( V_1 ) ;
V_40 = V_41 >> 3 ;
V_42 = V_41 % 8 ;
if ( ( V_42 ) != 0 )
V_40 ++ ;
V_35 = F_28 ( V_27 , V_33 , V_40 ) ;
F_3 ( V_1 , V_48 , V_35 , V_34 , V_17 ) ;
if ( ( V_42 ) != 0 )
V_40 -- ;
V_33 += V_40 ;
}
}
static void F_29 ( T_3 * V_27 , T_5 * V_17 , T_4 * V_28 , int V_29 )
{
T_2 V_49 = 0 ;
T_2 V_31 = 0 , V_32 ;
T_2 V_1 ;
T_1 V_33 = 0 ;
T_6 * V_18 = NULL ;
T_4 * V_34 = NULL ;
T_3 * V_35 ;
V_49 = F_24 ( V_27 , V_29 ) ;
F_25 ( V_28 , V_50 , V_27 , V_29 , 4 , V_49 ) ;
V_31 = ( V_49 & 0x3 ) + 1 ;
V_18 = F_25 ( V_28 , V_38 , V_27 , V_29 , 4 , V_31 ) ;
V_34 = F_6 ( V_18 , V_23 ) ;
V_49 >>= 2 ;
if( V_31 == 2 )
V_49 >>= 4 ;
if ( V_31 > 3 ) {
F_26 ( V_17 , V_18 , & V_39 ) ;
V_31 = 3 ;
}
V_33 = V_29 + 4 ;
for( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
T_1 V_40 , V_41 , V_42 ;
T_1 V_43 [ 3 ] ;
V_43 [ 0 ] = V_51 ;
V_43 [ 1 ] = V_52 ;
V_43 [ 2 ] = V_53 ;
V_1 = V_49 & 0xf ;
F_25 ( V_34 , V_43 [ V_32 ] , V_27 , V_29 , 4 , V_1 ) ;
V_49 >>= 4 ;
V_41 = F_2 ( V_1 ) ;
V_40 = V_41 >> 3 ;
V_42 = V_41 % 8 ;
if ( ( V_42 ) != 0 )
V_40 ++ ;
V_35 = F_28 ( V_27 , V_33 , V_40 ) ;
F_3 ( V_1 , V_24 , V_35 , V_34 , V_17 ) ;
V_33 += V_40 ;
}
}
static int
F_30 ( T_3 * V_27 , T_5 * V_17 , T_4 * V_16 , void * T_8 V_54 )
{
T_6 * V_55 = NULL ;
T_6 * V_18 = NULL ;
T_4 * V_28 = NULL ;
T_4 * V_34 = NULL ;
T_9 type = 0 ;
T_7 V_56 = - 1 ;
F_31 ( V_17 -> V_25 , V_57 , V_58 ) ;
F_32 ( V_17 -> V_25 , V_26 ) ;
type = F_8 ( V_27 , 0 ) ;
if( V_59 ) {
V_56 = F_8 ( V_27 , 1 ) ;
}
switch( type ) {
case 1 :
if( V_59 )
F_33 ( V_17 -> V_25 , V_26 , L_4 ,
V_56 ) ;
else
F_33 ( V_17 -> V_25 , V_26 , L_5 ) ;
break;
case 2 :
if( V_59 )
F_33 ( V_17 -> V_25 , V_26 , L_6 ,
V_56 ) ;
else
F_33 ( V_17 -> V_25 , V_26 , L_7 ) ;
break;
case 3 :
if( V_59 )
F_33 ( V_17 -> V_25 , V_26 , L_8 ,
V_56 ) ;
else
F_33 ( V_17 -> V_25 , V_26 , L_9 ) ;
break;
case 127 :
if( V_59 )
F_33 ( V_17 -> V_25 , V_26 , L_10 ,
V_56 ) ;
else
F_33 ( V_17 -> V_25 , V_26 , L_11 ) ;
break;
case 128 :
if( V_59 )
F_33 ( V_17 -> V_25 , V_26 , L_12 ,
V_56 ) ;
else
F_33 ( V_17 -> V_25 , V_26 , L_13 ) ;
break;
default:
F_33 ( V_17 -> V_25 , V_26 , L_14 , type ) ;
break;
}
{
T_2 V_29 = 0 ;
T_2 V_60 = 0 ;
T_2 V_61 = 0 ;
V_55 = F_4 ( V_16 , V_62 , V_27 , 0 , - 1 , V_22 ) ;
V_28 = F_6 ( V_55 , V_23 ) ;
V_29 ++ ;
if( V_59 ) {
F_25 ( V_28 , V_63 , V_27 , V_29 , 1 , V_56 ) ;
V_29 ++ ;
}
V_18 = F_4 ( V_28 , V_64 , V_27 , V_29 , - 1 , V_22 ) ;
V_34 = F_6 ( V_18 , V_23 ) ;
V_60 = F_24 ( V_27 , V_29 ) ;
V_18 = F_4 ( V_34 , V_65 , V_27 , V_29 , 4 , V_66 ) ;
V_61 = ( ( V_60 & 0x7800 ) >> 11 ) ;
if( V_61 == 4 )
V_61 = 3 ;
if( V_61 == 8 )
V_61 = 4 ;
F_34 ( V_18 , L_15 ,
V_60 & 0x3F , ( V_60 & 0x7c0 ) >> 6 ,
V_61 ) ;
V_29 += 4 ;
switch( type ) {
case 1 :
case 128 :
F_29 ( V_27 , V_17 , V_34 , V_29 ) ;
break;
case 2 :
case 127 :
F_23 ( V_27 , V_17 , V_34 , V_29 ) ;
break;
case 3 :
break;
default:
break;
}
}
return F_5 ( V_27 ) ;
}
void F_35 ( void )
{
V_67 = F_36 ( F_30 , V_62 ) ;
F_37 ( L_16 , V_68 , V_67 ) ;
}
void F_38 ( void )
{
T_10 * V_69 ;
T_11 * V_70 ;
static T_12 V_71 [] = {
{ & V_72 ,
{ L_17 , L_18 , V_73 , V_74 , NULL , 0x0 ,
L_19 , V_75 } } ,
{ & V_64 ,
{ L_20 , L_21 , V_73 , V_74 , NULL , 0x0 ,
L_22 , V_75 } } ,
{ & V_38 ,
{ L_23 , L_24 , V_76 , V_77 , NULL , 0x0 ,
L_25 , V_75 } } ,
{ & V_51 ,
{ L_26 , L_27 , V_76 , V_77 , F_39 ( V_78 ) , 0x0 ,
L_28 , V_75 } } ,
{ & V_52 ,
{ L_29 , L_30 , V_76 , V_77 , F_39 ( V_78 ) , 0x0 ,
L_28 , V_75 } } ,
{ & V_53 ,
{ L_31 , L_32 , V_76 , V_77 , F_39 ( V_78 ) , 0x0 ,
L_28 , V_75 } } ,
{ & V_50 ,
{ L_33 , L_34 , V_79 , V_80 , NULL , 0x0 ,
L_35 , V_75 } } ,
{ & V_37 ,
{ L_36 , L_37 , V_79 , V_80 , NULL , 0x0 ,
L_38 , V_75 } } ,
{ & V_63 ,
{ L_39 , L_40 , V_76 , V_77 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_44 ,
{ L_26 , L_41 , V_76 , V_77 , F_39 ( V_81 ) , 0x0 ,
L_28 , V_75 } } ,
{ & V_45 ,
{ L_29 , L_42 , V_76 , V_77 , F_39 ( V_81 ) , 0x0 ,
L_28 , V_75 } } ,
{ & V_46 ,
{ L_31 , L_43 , V_76 , V_77 , F_39 ( V_81 ) , 0x0 ,
L_28 , V_75 } } ,
{ & V_65 ,
{ L_44 , L_45 , V_79 , V_80 , NULL , 0x0 ,
L_46 , V_75 } } ,
{ & V_47 ,
{ L_47 , L_48 , V_82 , V_74 , NULL , 0x0 ,
L_49 , V_75 } } ,
{ & V_36 ,
{ L_50 , L_51 , V_79 , V_77 , NULL , 0x0 ,
L_52 , V_75 } } ,
{ & V_21 ,
{ L_53 , L_54 , V_83 , V_74 , NULL , 0x0 ,
NULL , V_75 } } ,
#include "packet-tetra-hfarr.c"
} ;
static T_1 * V_84 [] = {
& V_23 ,
& V_85 ,
& V_86 ,
& V_87 ,
& V_88 ,
#include "packet-tetra-ettarr.c"
} ;
static T_13 V_89 [] = {
{ & V_39 , { L_55 , V_90 , V_91 , L_56 , V_92 } } ,
} ;
V_62 = F_40 ( L_57 , L_58 , L_58 ) ;
F_41 ( V_62 , V_71 , F_42 ( V_71 ) ) ;
F_43 ( V_84 , F_42 ( V_84 ) ) ;
F_44 ( L_58 , F_30 , V_62 ) ;
V_70 = F_45 ( V_62 ) ;
F_46 ( V_70 , V_89 , F_42 ( V_89 ) ) ;
V_69 = F_47 ( V_62 , NULL ) ;
F_48 ( V_69 , L_59 ,
L_60 ,
L_61 ,
& V_59 ) ;
}
