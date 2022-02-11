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
if ( V_14 == V_24 )
F_9 ( V_15 , V_17 , V_19 ) ;
else
F_10 ( V_15 , V_17 , V_19 ) ;
break;
case 1 :
if( ( V_20 >> 5 ) == 3 ) {
if ( V_14 == V_24 )
F_11 ( V_15 , V_17 , V_19 ) ;
else
F_12 ( V_15 , V_17 , V_19 ) ;
} else
F_13 ( V_15 , V_17 , V_19 ) ;
break;
case 2 :
F_14 ( V_15 , V_17 , V_19 ) ;
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
F_15 ( V_15 , V_17 , V_19 ) ;
else
F_16 ( V_15 , V_17 , V_19 ) ;
break;
case 2 :
F_14 ( V_15 , V_17 , V_19 ) ;
break;
}
break;
case V_13 :
V_20 = F_8 ( V_15 , 0 ) ;
switch( V_20 >> 7 ) {
case 0 :
F_17 ( V_15 , V_17 , V_19 ) ;
break;
case 1 :
F_18 ( V_15 , V_17 , V_19 ) ;
break;
}
break;
case V_6 :
F_19 ( V_17 -> V_25 , V_26 , NULL , L_1 ) ;
F_20 ( V_15 , V_17 , V_19 ) ;
break;
case V_7 :
F_19 ( V_17 -> V_25 , V_26 , NULL , L_2 ) ;
F_21 ( V_15 , V_17 , V_19 ) ;
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
F_15 ( V_15 , V_17 , V_19 ) ;
else
F_22 ( V_15 , V_17 , V_19 ) ;
} else
F_16 ( V_15 , V_17 , V_19 ) ;
break;
case 2 :
F_14 ( V_15 , V_17 , V_19 ) ;
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
T_1 V_40 [] = {
V_41 ,
V_42 ,
V_43
} ;
T_1 V_44 , V_45 , V_46 ;
V_1 = ( V_30 >> ( ( V_32 + 1 ) * 4 ) ) & 0xf ;
F_25 ( V_34 , V_40 [ V_32 ] , V_27 , V_29 , 4 , V_1 ) ;
F_27 ( V_34 , V_47 , V_27 , V_29 , 4 , ! ( V_30 >> ( V_32 + 2 ) & 0x01 ) ) ;
V_45 = F_1 ( V_1 ) ;
V_44 = V_45 >> 3 ;
V_46 = V_45 % 8 ;
if ( ( V_46 ) != 0 )
V_44 ++ ;
V_35 = F_28 ( V_27 , V_33 , V_44 , V_44 ) ;
F_3 ( V_1 , V_48 , V_35 , V_34 , V_17 ) ;
if ( ( V_46 ) != 0 )
V_44 -- ;
V_33 += V_44 ;
}
}
void F_29 ( T_3 * V_27 , T_5 * V_17 , T_4 * V_28 , int V_29 )
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
T_1 V_40 [] = { V_51 , V_52 , V_53 } ;
T_1 V_44 , V_45 , V_46 ;
V_1 = V_49 & 0xf ;
F_25 ( V_34 , V_40 [ V_32 ] , V_27 , V_29 , 4 , V_1 ) ;
V_49 >>= 4 ;
V_45 = F_2 ( V_1 ) ;
V_44 = V_45 >> 3 ;
V_46 = V_45 % 8 ;
if ( ( V_46 ) != 0 )
V_44 ++ ;
V_35 = F_28 ( V_27 , V_33 , V_44 , V_44 ) ;
F_3 ( V_1 , V_24 , V_35 , V_34 , V_17 ) ;
V_33 += V_44 ;
}
}
static void
F_30 ( T_3 * V_27 , T_5 * V_17 , T_4 * V_16 )
{
T_6 * V_54 = NULL ;
T_6 * V_18 = NULL ;
T_4 * V_28 = NULL ;
T_4 * V_34 = NULL ;
T_8 type = 0 ;
T_7 V_55 = - 1 ;
F_31 ( V_17 -> V_25 , V_56 , V_57 ) ;
F_32 ( V_17 -> V_25 , V_26 ) ;
type = F_8 ( V_27 , 0 ) ;
if( V_58 ) {
V_55 = F_8 ( V_27 , 1 ) ;
}
switch( type ) {
case 1 :
if( V_58 )
F_33 ( V_17 -> V_25 , V_26 , L_4 ,
V_55 ) ;
else
F_33 ( V_17 -> V_25 , V_26 , L_5 ) ;
break;
case 2 :
if( V_58 )
F_33 ( V_17 -> V_25 , V_26 , L_6 ,
V_55 ) ;
else
F_33 ( V_17 -> V_25 , V_26 , L_7 ) ;
break;
case 3 :
if( V_58 )
F_33 ( V_17 -> V_25 , V_26 , L_8 ,
V_55 ) ;
else
F_33 ( V_17 -> V_25 , V_26 , L_9 ) ;
break;
case 127 :
if( V_58 )
F_33 ( V_17 -> V_25 , V_26 , L_10 ,
V_55 ) ;
else
F_33 ( V_17 -> V_25 , V_26 , L_11 ) ;
break;
case 128 :
if( V_58 )
F_33 ( V_17 -> V_25 , V_26 , L_12 ,
V_55 ) ;
else
F_33 ( V_17 -> V_25 , V_26 , L_13 ) ;
break;
default:
F_33 ( V_17 -> V_25 , V_26 , L_14 , type ) ;
break;
}
if ( V_16 ) {
T_2 V_29 = 0 ;
T_2 V_59 = 0 ;
T_2 V_60 = 0 ;
V_54 = F_4 ( V_16 , V_61 , V_27 , 0 , - 1 , V_22 ) ;
V_28 = F_6 ( V_54 , V_23 ) ;
V_29 ++ ;
if( V_58 ) {
F_25 ( V_28 , V_62 , V_27 , V_29 , 1 , V_55 ) ;
V_29 ++ ;
}
V_18 = F_4 ( V_28 , V_63 , V_27 , V_29 , - 1 , V_22 ) ;
V_34 = F_6 ( V_18 , V_23 ) ;
V_59 = F_24 ( V_27 , V_29 ) ;
V_18 = F_4 ( V_34 , V_64 , V_27 , V_29 , 4 , V_65 ) ;
V_60 = ( ( V_59 & 0x7800 ) >> 11 ) ;
if( V_60 == 4 )
V_60 = 3 ;
if( V_60 == 8 )
V_60 = 4 ;
F_34 ( V_18 , L_15 ,
V_59 & 0x3F , ( V_59 & 0x7c0 ) >> 6 ,
V_60 ) ;
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
}
void F_35 ( void )
{
static T_9 V_66 = FALSE ;
if ( ! V_66 ) {
V_67 = F_36 ( L_16 ) ;
V_68 = F_37 ( F_30 , V_61 ) ;
F_38 ( L_17 , V_69 , V_68 ) ;
}
}
void F_39 ( void )
{
T_10 * V_70 ;
T_11 * V_71 ;
static T_12 V_72 [] = {
{ & V_73 ,
{ L_18 , L_19 , V_74 , V_75 , NULL , 0x0 ,
L_20 , V_76 } } ,
{ & V_63 ,
{ L_21 , L_22 , V_74 , V_75 , NULL , 0x0 ,
L_23 , V_76 } } ,
{ & V_38 ,
{ L_24 , L_25 , V_77 , V_78 , NULL , 0x0 ,
L_26 , V_76 } } ,
{ & V_51 ,
{ L_27 , L_28 , V_77 , V_78 , F_40 ( V_79 ) , 0x0 ,
L_29 , V_76 } } ,
{ & V_52 ,
{ L_30 , L_31 , V_77 , V_78 , F_40 ( V_79 ) , 0x0 ,
L_29 , V_76 } } ,
{ & V_53 ,
{ L_32 , L_33 , V_77 , V_78 , F_40 ( V_79 ) , 0x0 ,
L_29 , V_76 } } ,
{ & V_50 ,
{ L_34 , L_35 , V_80 , V_81 , NULL , 0x0 ,
L_36 , V_76 } } ,
{ & V_37 ,
{ L_37 , L_38 , V_80 , V_81 , NULL , 0x0 ,
L_39 , V_76 } } ,
{ & V_62 ,
{ L_40 , L_41 , V_77 , V_78 , NULL , 0x0 ,
NULL , V_76 } } ,
{ & V_41 ,
{ L_27 , L_42 , V_77 , V_78 , F_40 ( V_82 ) , 0x0 ,
L_29 , V_76 } } ,
{ & V_42 ,
{ L_30 , L_43 , V_77 , V_78 , F_40 ( V_82 ) , 0x0 ,
L_29 , V_76 } } ,
{ & V_43 ,
{ L_32 , L_44 , V_77 , V_78 , F_40 ( V_82 ) , 0x0 ,
L_29 , V_76 } } ,
{ & V_64 ,
{ L_45 , L_46 , V_80 , V_81 , NULL , 0x0 ,
L_47 , V_76 } } ,
{ & V_47 ,
{ L_48 , L_49 , V_83 , V_75 , NULL , 0x0 ,
L_50 , V_76 } } ,
{ & V_36 ,
{ L_51 , L_52 , V_80 , V_78 , NULL , 0x0 ,
L_53 , V_76 } } ,
{ & V_21 ,
{ L_54 , L_55 , V_84 , V_75 , NULL , 0x0 ,
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
static T_13 V_90 [] = {
{ & V_39 , { L_56 , V_91 , V_92 , L_57 , V_93 } } ,
} ;
V_61 = F_41 ( L_58 , L_59 , L_59 ) ;
F_42 ( V_61 , V_72 , F_43 ( V_72 ) ) ;
F_44 ( V_85 , F_43 ( V_85 ) ) ;
F_45 ( L_59 , F_30 , V_61 ) ;
V_71 = F_46 ( V_61 ) ;
F_47 ( V_71 , V_90 , F_43 ( V_90 ) ) ;
V_70 = F_48 ( V_61 , NULL ) ;
F_49 ( V_70 , L_60 ,
L_61 ,
L_62 ,
& V_58 ) ;
}
