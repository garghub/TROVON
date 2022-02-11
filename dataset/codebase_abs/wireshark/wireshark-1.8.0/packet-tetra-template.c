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
V_31 = V_27 + 4 ;
for( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
T_1 V_37 [] = {
V_38 ,
V_39 ,
V_40
} ;
T_1 V_41 , V_42 , V_43 ;
V_1 = ( V_28 >> ( ( V_30 + 1 ) * 4 ) ) & 0xf ;
F_23 ( V_32 , V_37 [ V_30 ] , V_25 , V_27 , 4 , V_1 ) ;
F_24 ( V_32 , V_44 , V_25 , V_27 , 4 , ! ( V_28 >> ( V_30 + 2 ) & 0x01 ) ) ;
V_42 = F_1 ( V_1 ) ;
V_41 = V_42 >> 3 ;
V_43 = V_42 % 8 ;
if ( ( V_43 ) != 0 )
V_41 ++ ;
V_33 = F_25 ( V_25 , V_31 , V_41 , V_41 ) ;
F_3 ( V_1 , V_45 , V_33 , V_32 , V_17 ) ;
if ( ( V_43 ) != 0 )
V_41 -- ;
V_31 += V_41 ;
}
}
void F_26 ( T_3 * V_25 , T_5 * V_17 , T_4 * V_26 , int V_27 )
{
T_2 V_46 = 0 ;
T_2 V_29 = 0 , V_30 ;
T_2 V_1 ;
T_1 V_31 = 0 ;
T_6 * V_18 = NULL ;
T_4 * V_32 = NULL ;
T_3 * V_33 ;
V_46 = F_22 ( V_25 , V_27 ) ;
F_23 ( V_26 , V_47 , V_25 , V_27 , 4 , V_46 ) ;
V_29 = ( V_46 & 0x3 ) + 1 ;
V_18 = F_23 ( V_26 , V_36 , V_25 , V_27 , 4 , V_29 ) ;
V_32 = F_6 ( V_18 , V_23 ) ;
V_46 >>= 2 ;
if( V_29 == 2 )
V_46 >>= 4 ;
V_31 = V_27 + 4 ;
for( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
T_1 V_37 [] = { V_48 , V_49 , V_50 } ;
T_1 V_41 , V_42 , V_43 ;
V_1 = V_46 & 0xf ;
F_23 ( V_32 , V_37 [ V_30 ] , V_25 , V_27 , 4 , V_1 ) ;
V_46 >>= 4 ;
V_42 = F_2 ( V_1 ) ;
V_41 = V_42 >> 3 ;
V_43 = V_42 % 8 ;
if ( ( V_43 ) != 0 )
V_41 ++ ;
V_33 = F_25 ( V_25 , V_31 , V_41 , V_41 ) ;
F_3 ( V_1 , V_24 , V_33 , V_32 , V_17 ) ;
V_31 += V_41 ;
}
}
static void
F_27 ( T_3 * V_25 , T_5 * V_17 , T_4 * V_16 )
{
T_6 * V_51 = NULL ;
T_6 * V_18 = NULL ;
T_4 * V_26 = NULL ;
T_4 * V_32 = NULL ;
T_8 type = 0 ;
T_8 V_52 = - 1 ;
F_28 ( V_17 -> V_53 , V_54 , V_55 ) ;
F_29 ( V_17 -> V_53 , V_56 ) ;
type = F_8 ( V_25 , 0 ) ;
if( V_57 ) {
V_52 = F_8 ( V_25 , 1 ) ;
V_52 |= 0xff00 ;
}
switch( type ) {
case 1 :
if( V_57 )
F_30 ( V_17 -> V_53 , V_56 , L_1 ,
V_17 -> V_58 , V_17 -> V_59 , V_52 ) ;
else
F_30 ( V_17 -> V_53 , V_56 , L_2 ,
V_17 -> V_58 , V_17 -> V_59 ) ;
break;
case 2 :
if( V_57 )
F_30 ( V_17 -> V_53 , V_56 , L_3 ,
V_17 -> V_58 , V_17 -> V_59 , V_52 ) ;
else
F_30 ( V_17 -> V_53 , V_56 , L_4 ,
V_17 -> V_58 , V_17 -> V_59 ) ;
break;
case 3 :
if( V_57 )
F_30 ( V_17 -> V_53 , V_56 , L_5 ,
V_17 -> V_58 , V_17 -> V_59 , V_52 ) ;
else
F_30 ( V_17 -> V_53 , V_56 , L_6 ,
V_17 -> V_58 , V_17 -> V_59 ) ;
break;
case 127 :
if( V_57 )
F_30 ( V_17 -> V_53 , V_56 , L_7 ,
V_17 -> V_58 , V_17 -> V_59 , V_52 ) ;
else
F_30 ( V_17 -> V_53 , V_56 , L_8 ,
V_17 -> V_58 , V_17 -> V_59 ) ;
break;
case 128 :
if( V_57 )
F_30 ( V_17 -> V_53 , V_56 , L_9 ,
V_17 -> V_58 , V_17 -> V_59 , V_52 ) ;
else
F_30 ( V_17 -> V_53 , V_56 , L_10 ,
V_17 -> V_58 , V_17 -> V_59 ) ;
break;
default:
F_30 ( V_17 -> V_53 , V_56 , L_11 ,
V_17 -> V_58 , V_17 -> V_59 , type ) ;
break;
}
if ( V_16 ) {
T_2 V_27 = 0 ;
T_2 V_60 = 0 ;
T_2 V_61 = 0 ;
V_51 = F_4 ( V_16 , V_62 , V_25 , 0 , - 1 , V_22 ) ;
V_26 = F_6 ( V_51 , V_23 ) ;
V_27 ++ ;
if( V_57 ) {
F_23 ( V_26 , V_63 , V_25 , V_27 , 1 , V_52 ) ;
V_27 ++ ;
}
V_18 = F_4 ( V_26 , V_64 , V_25 , V_27 , - 1 , V_22 ) ;
V_32 = F_6 ( V_18 , V_23 ) ;
V_60 = F_22 ( V_25 , V_27 ) ;
V_18 = F_4 ( V_32 , V_65 , V_25 , V_27 , 4 , V_66 ) ;
V_61 = ( ( V_60 & 0x7800 ) >> 11 ) ;
if( V_61 == 4 )
V_61 = 3 ;
if( V_61 == 8 )
V_61 = 4 ;
F_31 ( V_18 , L_12 ,
V_60 & 0x3F , ( V_60 & 0x7c0 ) >> 6 ,
V_61 ) ;
V_27 += 4 ;
switch( type ) {
case 1 :
case 128 :
F_26 ( V_25 , V_17 , V_32 , V_27 ) ;
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
void F_32 ( void )
{
static T_9 V_67 = FALSE ;
if ( ! V_67 ) {
V_68 = F_33 ( L_13 ) ;
V_69 = F_34 ( F_27 , V_62 ) ;
F_35 ( L_14 , V_70 , V_69 ) ;
}
}
void F_36 ( void )
{
T_10 * V_71 ;
static T_11 V_72 [] = {
{ & V_73 ,
{ L_15 , L_16 , V_74 , V_75 , NULL , 0x0 ,
L_17 , V_76 } } ,
{ & V_64 ,
{ L_18 , L_19 , V_74 , V_75 , NULL , 0x0 ,
L_20 , V_76 } } ,
{ & V_36 ,
{ L_21 , L_22 , V_77 , V_78 , NULL , 0x0 ,
L_23 , V_76 } } ,
{ & V_48 ,
{ L_24 , L_25 , V_77 , V_78 , F_37 ( V_79 ) , 0x0 ,
L_26 , V_76 } } ,
{ & V_49 ,
{ L_27 , L_28 , V_77 , V_78 , F_37 ( V_79 ) , 0x0 ,
L_26 , V_76 } } ,
{ & V_50 ,
{ L_29 , L_30 , V_77 , V_78 , F_37 ( V_79 ) , 0x0 ,
L_26 , V_76 } } ,
{ & V_47 ,
{ L_31 , L_32 , V_80 , V_81 , NULL , 0x0 ,
L_33 , V_76 } } ,
{ & V_35 ,
{ L_34 , L_35 , V_80 , V_81 , NULL , 0x0 ,
L_36 , V_76 } } ,
{ & V_63 ,
{ L_37 , L_38 , V_80 , V_81 , NULL , 0x0 ,
NULL , V_76 } } ,
{ & V_38 ,
{ L_24 , L_39 , V_77 , V_78 , F_37 ( V_82 ) , 0x0 ,
L_26 , V_76 } } ,
{ & V_39 ,
{ L_27 , L_40 , V_77 , V_78 , F_37 ( V_82 ) , 0x0 ,
L_26 , V_76 } } ,
{ & V_40 ,
{ L_29 , L_41 , V_77 , V_78 , F_37 ( V_82 ) , 0x0 ,
L_26 , V_76 } } ,
{ & V_65 ,
{ L_42 , L_43 , V_80 , V_81 , NULL , 0x0 ,
L_44 , V_76 } } ,
{ & V_44 ,
{ L_45 , L_46 , V_83 , V_75 , NULL , 0x0 ,
L_47 , V_76 } } ,
{ & V_34 ,
{ L_48 , L_49 , V_80 , V_78 , NULL , 0x0 ,
L_50 , V_76 } } ,
{ & V_21 ,
{ L_51 , L_52 , V_84 , V_75 , NULL , 0x0 ,
NULL , V_76 } } ,
#include "packet-tetra-hfarr.c"
} ;
static T_1 * V_85 [] = {
& V_23 ,
& V_86 ,
& V_87 ,
& V_88 ,
& V_89 ,
#include "packet-tetra-ettarr.c"
} ;
if ( V_62 != - 1 )
return;
V_62 = F_38 ( L_53 , L_54 , L_54 ) ;
F_39 ( V_62 , V_72 , F_40 ( V_72 ) ) ;
F_41 ( V_85 , F_40 ( V_85 ) ) ;
F_42 ( L_54 , F_27 , V_62 ) ;
V_71 = F_43 ( V_62 , NULL ) ;
F_44 ( V_71 , L_55 ,
L_56 ,
L_57 ,
& V_57 ) ;
}
