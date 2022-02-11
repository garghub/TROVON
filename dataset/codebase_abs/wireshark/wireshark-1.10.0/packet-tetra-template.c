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
F_7 ( V_15 , V_17 , V_19 ) ;
break;
case V_4 :
V_20 = F_8 ( V_15 , 0 ) ;
switch( V_20 >> 6 ) {
case 0 :
F_9 ( V_15 , V_17 , V_19 ) ;
break;
case 1 :
if( ( V_20 >> 5 ) == 3 ) {
if ( V_14 == V_24 )
F_10 ( V_15 , V_17 , V_19 ) ;
else
F_11 ( V_15 , V_17 , V_19 ) ;
} else
F_12 ( V_15 , V_17 , V_19 ) ;
break;
case 2 :
F_13 ( V_15 , V_17 , V_19 ) ;
break;
}
break;
case V_5 :
V_20 = F_8 ( V_15 , 0 ) ;
switch( V_20 >> 6 ) {
case 0 :
F_9 ( V_15 , V_17 , V_19 ) ;
break;
case 1 :
if( ( V_20 >> 5 ) == 3 )
F_14 ( V_15 , V_17 , V_19 ) ;
else
F_15 ( V_15 , V_17 , V_19 ) ;
break;
case 2 :
F_13 ( V_15 , V_17 , V_19 ) ;
break;
}
break;
case V_13 :
V_20 = F_8 ( V_15 , 0 ) ;
switch( V_20 >> 7 ) {
case 0 :
F_16 ( V_15 , V_17 , V_19 ) ;
break;
case 1 :
F_17 ( V_15 , V_17 , V_19 ) ;
break;
}
break;
case V_6 :
F_18 ( V_15 , V_17 , V_19 ) ;
break;
case V_7 :
F_19 ( V_15 , V_17 , V_19 ) ;
break;
case V_12 :
V_20 = F_8 ( V_15 , 0 ) ;
switch( V_20 >> 6 ) {
case 0 :
F_9 ( V_15 , V_17 , V_19 ) ;
break;
case 1 :
if( ( V_20 >> 5 ) == 3 ) {
if ( V_14 == V_24 )
F_14 ( V_15 , V_17 , V_19 ) ;
else
F_20 ( V_15 , V_17 , V_19 ) ;
} else
F_15 ( V_15 , V_17 , V_19 ) ;
break;
case 2 :
F_13 ( V_15 , V_17 , V_19 ) ;
break;
}
break;
}
}
static void F_21 ( T_3 * V_25 , T_5 * V_17 , T_4 * V_26 , int V_27 )
{
T_2 V_28 = 0 ;
T_2 V_29 = 0 , V_30 ;
T_2 V_1 ;
T_1 V_31 = 0 ;
T_6 * V_18 ;
T_4 * V_32 = NULL ;
T_3 * V_33 ;
V_28 = F_22 ( V_25 , V_27 ) ;
F_23 ( V_26 , V_34 , V_25 , V_27 , 4 , V_28 ) ;
V_27 += 4 ;
V_28 = F_22 ( V_25 , V_27 ) ;
F_23 ( V_26 , V_35 , V_25 , V_27 , 4 , V_28 ) ;
V_29 = V_28 & 0x3 ;
V_18 = F_23 ( V_26 , V_36 , V_25 , V_27 , 4 , V_29 ) ;
V_32 = F_6 ( V_18 , V_23 ) ;
if ( V_29 > 3 ) {
F_24 ( V_17 , V_18 , V_37 , V_38 ,
L_1 ) ;
V_29 = 3 ;
}
V_31 = V_27 + 4 ;
for( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
T_1 V_39 [] = {
V_40 ,
V_41 ,
V_42
} ;
T_1 V_43 , V_44 , V_45 ;
V_1 = ( V_28 >> ( ( V_30 + 1 ) * 4 ) ) & 0xf ;
F_23 ( V_32 , V_39 [ V_30 ] , V_25 , V_27 , 4 , V_1 ) ;
F_25 ( V_32 , V_46 , V_25 , V_27 , 4 , ! ( V_28 >> ( V_30 + 2 ) & 0x01 ) ) ;
V_44 = F_1 ( V_1 ) ;
V_43 = V_44 >> 3 ;
V_45 = V_44 % 8 ;
if ( ( V_45 ) != 0 )
V_43 ++ ;
V_33 = F_26 ( V_25 , V_31 , V_43 , V_43 ) ;
F_3 ( V_1 , V_47 , V_33 , V_32 , V_17 ) ;
if ( ( V_45 ) != 0 )
V_43 -- ;
V_31 += V_43 ;
}
}
void F_27 ( T_3 * V_25 , T_5 * V_17 , T_4 * V_26 , int V_27 )
{
T_2 V_48 = 0 ;
T_2 V_29 = 0 , V_30 ;
T_2 V_1 ;
T_1 V_31 = 0 ;
T_6 * V_18 = NULL ;
T_4 * V_32 = NULL ;
T_3 * V_33 ;
V_48 = F_22 ( V_25 , V_27 ) ;
F_23 ( V_26 , V_49 , V_25 , V_27 , 4 , V_48 ) ;
V_29 = ( V_48 & 0x3 ) + 1 ;
V_18 = F_23 ( V_26 , V_36 , V_25 , V_27 , 4 , V_29 ) ;
V_32 = F_6 ( V_18 , V_23 ) ;
V_48 >>= 2 ;
if( V_29 == 2 )
V_48 >>= 4 ;
if ( V_29 > 3 ) {
F_24 ( V_17 , V_18 , V_37 , V_38 ,
L_1 ) ;
V_29 = 3 ;
}
V_31 = V_27 + 4 ;
for( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
T_1 V_39 [] = { V_50 , V_51 , V_52 } ;
T_1 V_43 , V_44 , V_45 ;
V_1 = V_48 & 0xf ;
F_23 ( V_32 , V_39 [ V_30 ] , V_25 , V_27 , 4 , V_1 ) ;
V_48 >>= 4 ;
V_44 = F_2 ( V_1 ) ;
V_43 = V_44 >> 3 ;
V_45 = V_44 % 8 ;
if ( ( V_45 ) != 0 )
V_43 ++ ;
V_33 = F_26 ( V_25 , V_31 , V_43 , V_43 ) ;
F_3 ( V_1 , V_24 , V_33 , V_32 , V_17 ) ;
V_31 += V_43 ;
}
}
static void
F_28 ( T_3 * V_25 , T_5 * V_17 , T_4 * V_16 )
{
T_6 * V_53 = NULL ;
T_6 * V_18 = NULL ;
T_4 * V_26 = NULL ;
T_4 * V_32 = NULL ;
T_8 type = 0 ;
T_8 V_54 = - 1 ;
F_29 ( V_17 -> V_55 , V_56 , V_57 ) ;
F_30 ( V_17 -> V_55 , V_58 ) ;
type = F_8 ( V_25 , 0 ) ;
if( V_59 ) {
V_54 = F_8 ( V_25 , 1 ) ;
V_54 |= 0xff00 ;
}
switch( type ) {
case 1 :
if( V_59 )
F_31 ( V_17 -> V_55 , V_58 , L_2 ,
V_17 -> V_60 , V_17 -> V_61 , V_54 ) ;
else
F_31 ( V_17 -> V_55 , V_58 , L_3 ,
V_17 -> V_60 , V_17 -> V_61 ) ;
break;
case 2 :
if( V_59 )
F_31 ( V_17 -> V_55 , V_58 , L_4 ,
V_17 -> V_60 , V_17 -> V_61 , V_54 ) ;
else
F_31 ( V_17 -> V_55 , V_58 , L_5 ,
V_17 -> V_60 , V_17 -> V_61 ) ;
break;
case 3 :
if( V_59 )
F_31 ( V_17 -> V_55 , V_58 , L_6 ,
V_17 -> V_60 , V_17 -> V_61 , V_54 ) ;
else
F_31 ( V_17 -> V_55 , V_58 , L_7 ,
V_17 -> V_60 , V_17 -> V_61 ) ;
break;
case 127 :
if( V_59 )
F_31 ( V_17 -> V_55 , V_58 , L_8 ,
V_17 -> V_60 , V_17 -> V_61 , V_54 ) ;
else
F_31 ( V_17 -> V_55 , V_58 , L_9 ,
V_17 -> V_60 , V_17 -> V_61 ) ;
break;
case 128 :
if( V_59 )
F_31 ( V_17 -> V_55 , V_58 , L_10 ,
V_17 -> V_60 , V_17 -> V_61 , V_54 ) ;
else
F_31 ( V_17 -> V_55 , V_58 , L_11 ,
V_17 -> V_60 , V_17 -> V_61 ) ;
break;
default:
F_31 ( V_17 -> V_55 , V_58 , L_12 ,
V_17 -> V_60 , V_17 -> V_61 , type ) ;
break;
}
if ( V_16 ) {
T_2 V_27 = 0 ;
T_2 V_62 = 0 ;
T_2 V_63 = 0 ;
V_53 = F_4 ( V_16 , V_64 , V_25 , 0 , - 1 , V_22 ) ;
V_26 = F_6 ( V_53 , V_23 ) ;
V_27 ++ ;
if( V_59 ) {
F_23 ( V_26 , V_65 , V_25 , V_27 , 1 , V_54 ) ;
V_27 ++ ;
}
V_18 = F_4 ( V_26 , V_66 , V_25 , V_27 , - 1 , V_22 ) ;
V_32 = F_6 ( V_18 , V_23 ) ;
V_62 = F_22 ( V_25 , V_27 ) ;
V_18 = F_4 ( V_32 , V_67 , V_25 , V_27 , 4 , V_68 ) ;
V_63 = ( ( V_62 & 0x7800 ) >> 11 ) ;
if( V_63 == 4 )
V_63 = 3 ;
if( V_63 == 8 )
V_63 = 4 ;
F_32 ( V_18 , L_13 ,
V_62 & 0x3F , ( V_62 & 0x7c0 ) >> 6 ,
V_63 ) ;
V_27 += 4 ;
switch( type ) {
case 1 :
case 128 :
F_27 ( V_25 , V_17 , V_32 , V_27 ) ;
break;
case 2 :
case 127 :
F_21 ( V_25 , V_17 , V_32 , V_27 ) ;
break;
case 3 :
break;
default:
break;
}
}
}
void F_33 ( void )
{
static T_9 V_69 = FALSE ;
if ( ! V_69 ) {
V_70 = F_34 ( L_14 ) ;
V_71 = F_35 ( F_28 , V_64 ) ;
F_36 ( L_15 , V_72 , V_71 ) ;
}
}
void F_37 ( void )
{
T_10 * V_73 ;
static T_11 V_74 [] = {
{ & V_75 ,
{ L_16 , L_17 , V_76 , V_77 , NULL , 0x0 ,
L_18 , V_78 } } ,
{ & V_66 ,
{ L_19 , L_20 , V_76 , V_77 , NULL , 0x0 ,
L_21 , V_78 } } ,
{ & V_36 ,
{ L_22 , L_23 , V_79 , V_80 , NULL , 0x0 ,
L_24 , V_78 } } ,
{ & V_50 ,
{ L_25 , L_26 , V_79 , V_80 , F_38 ( V_81 ) , 0x0 ,
L_27 , V_78 } } ,
{ & V_51 ,
{ L_28 , L_29 , V_79 , V_80 , F_38 ( V_81 ) , 0x0 ,
L_27 , V_78 } } ,
{ & V_52 ,
{ L_30 , L_31 , V_79 , V_80 , F_38 ( V_81 ) , 0x0 ,
L_27 , V_78 } } ,
{ & V_49 ,
{ L_32 , L_33 , V_82 , V_83 , NULL , 0x0 ,
L_34 , V_78 } } ,
{ & V_35 ,
{ L_35 , L_36 , V_82 , V_83 , NULL , 0x0 ,
L_37 , V_78 } } ,
{ & V_65 ,
{ L_38 , L_39 , V_82 , V_83 , NULL , 0x0 ,
NULL , V_78 } } ,
{ & V_40 ,
{ L_25 , L_40 , V_79 , V_80 , F_38 ( V_84 ) , 0x0 ,
L_27 , V_78 } } ,
{ & V_41 ,
{ L_28 , L_41 , V_79 , V_80 , F_38 ( V_84 ) , 0x0 ,
L_27 , V_78 } } ,
{ & V_42 ,
{ L_30 , L_42 , V_79 , V_80 , F_38 ( V_84 ) , 0x0 ,
L_27 , V_78 } } ,
{ & V_67 ,
{ L_43 , L_44 , V_82 , V_83 , NULL , 0x0 ,
L_45 , V_78 } } ,
{ & V_46 ,
{ L_46 , L_47 , V_85 , V_77 , NULL , 0x0 ,
L_48 , V_78 } } ,
{ & V_34 ,
{ L_49 , L_50 , V_82 , V_80 , NULL , 0x0 ,
L_51 , V_78 } } ,
{ & V_21 ,
{ L_52 , L_53 , V_86 , V_77 , NULL , 0x0 ,
NULL , V_78 } } ,
#include "packet-tetra-hfarr.c"
} ;
static T_1 * V_87 [] = {
& V_23 ,
& V_88 ,
& V_89 ,
& V_90 ,
& V_91 ,
#include "packet-tetra-ettarr.c"
} ;
if ( V_64 != - 1 )
return;
V_64 = F_39 ( L_54 , L_55 , L_55 ) ;
F_40 ( V_64 , V_74 , F_41 ( V_74 ) ) ;
F_42 ( V_87 , F_41 ( V_87 ) ) ;
F_43 ( L_55 , F_28 , V_64 ) ;
V_73 = F_44 ( V_64 , NULL ) ;
F_45 ( V_73 , L_56 ,
L_57 ,
L_58 ,
& V_59 ) ;
}
