void
F_1 ( const T_1 * V_1 , int V_2 , int V_3 , T_2 * V_4 )
{
T_3 type ;
if ( ! F_2 ( V_2 , V_3 , V_5 ) ) {
V_4 -> V_6 ++ ;
return;
}
type = ( V_1 [ V_2 + 5 ] >> 4 ) & 0x0F ;
switch ( type ) {
case V_7 :
V_2 += 14 + 12 ;
F_3 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_8 :
V_2 += 14 + 17 ;
F_4 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
default:
V_4 -> V_6 ++ ;
break;
}
}
void
F_5 ( T_4 * V_9 , T_5 * V_10 , T_6 * V_11 , int V_12 )
{
T_6 * volatile V_13 = NULL ;
T_6 * V_14 ;
T_7 * V_15 , * V_16 ;
volatile T_3 type ;
volatile T_8 V_17 ;
T_9 V_18 ;
T_4 * volatile V_19 = NULL ;
T_4 * volatile V_20 ;
T_4 * volatile V_21 = NULL ;
const char * V_22 ;
void * V_23 ;
F_6 ( V_10 -> V_24 , V_25 , L_1 ) ;
F_7 ( V_10 -> V_24 , V_26 ) ;
type = ( F_8 ( V_9 , 5 ) >> 4 ) & 0x0F ;
if ( V_11 ) {
V_15 = F_9 ( V_11 , V_27 , V_9 , 0 , V_5 ,
L_1 ) ;
V_13 = F_10 ( V_15 , V_28 ) ;
V_15 = F_11 ( V_13 , V_29 , V_9 , 0 , 6 , V_30 ) ;
V_16 = F_11 ( V_13 , V_31 , V_9 , 0 , 6 , V_30 ) ;
F_12 ( V_16 ) ;
V_14 = F_10 ( V_15 , V_32 ) ;
F_11 ( V_14 , V_33 , V_9 , 5 , 1 , V_34 ) ;
switch ( type ) {
case V_7 :
F_11 ( V_14 , V_35 , V_9 , 5 , 1 , V_34 ) ;
break;
default:
F_11 ( V_14 , V_36 , V_9 , 5 , 1 , V_34 ) ;
break;
}
F_11 ( V_13 , V_37 , V_9 , 6 , 6 , V_30 ) ;
V_16 = F_11 ( V_13 , V_31 , V_9 , 6 , 6 , V_30 ) ;
F_12 ( V_16 ) ;
}
V_17 = F_13 ( V_9 , 12 ) ;
if ( V_11 )
F_14 ( V_13 , V_38 , V_9 , 12 , 2 , V_17 ) ;
if ( V_17 != 0 ) {
F_15 {
V_19 = F_16 ( V_9 , 14 , V_17 , V_17 ) ;
V_21 = F_17 ( V_9 , 14 + V_17 ) ;
}
F_18 {
V_19 = F_16 ( V_9 , 14 , - 1 , V_17 ) ;
V_21 = NULL ;
}
V_39 ;
} else {
V_17 = F_19 ( V_9 , 14 ) ;
V_19 = F_17 ( V_9 , 14 ) ;
V_21 = NULL ;
}
if ( V_11 ) {
F_20 ( V_19 , 0 , 6 ) ;
F_21 ( V_13 , V_19 , 0 , 1 , L_2 , F_8 ( V_9 , 14 ) ) ;
F_21 ( V_13 , V_19 , 1 , 1 , L_3 , F_8 ( V_9 , 15 ) ) ;
F_21 ( V_13 , V_19 , 2 , 1 , L_4 , F_8 ( V_9 , 16 ) ) ;
F_11 ( V_13 , V_40 , V_19 , 3 , 3 , V_34 ) ;
}
F_22 ( V_10 -> V_24 , V_26 , L_5 ,
F_13 ( V_9 , 20 ) >> 1 ) ;
if ( V_11 ) {
F_11 ( V_13 , V_41 , V_19 , 6 , 2 , V_34 ) ;
F_11 ( V_13 , V_42 , V_19 , 6 , 2 , V_34 ) ;
F_11 ( V_13 , V_43 , V_19 , 8 , 2 , V_34 ) ;
}
switch ( type ) {
case V_7 :
if ( V_17 >= 12 ) {
V_17 -= 12 ;
V_18 = F_23 ( V_19 , 12 ) ;
if ( V_18 > V_17 )
V_18 = V_17 ;
V_20 = F_16 ( V_19 , 12 , V_18 , V_17 ) ;
V_22 = V_10 -> V_44 ;
V_23 = V_10 -> V_45 ;
F_15 {
F_24 ( V_46 , V_20 , V_10 , V_11 ) ;
}
F_25 {
V_10 -> V_45 = V_23 ;
F_26 ( V_20 , V_10 , V_11 , V_47 , V_48 ) ;
V_10 -> V_44 = V_22 ;
}
V_39 ;
F_27 ( V_10 , V_11 , V_13 , V_49 , V_9 , V_21 , V_12 ) ;
}
break;
case V_8 :
if ( V_11 ) {
F_11 ( V_13 , V_50 , V_19 , 10 , 2 , V_34 ) ;
F_11 ( V_13 , V_51 , V_19 , 10 , 2 , V_34 ) ;
F_11 ( V_13 , V_52 , V_19 , 12 , 2 , V_34 ) ;
F_11 ( V_13 , V_53 , V_19 , 14 , 2 , V_34 ) ;
F_11 ( V_13 , V_54 , V_19 , 16 , 1 , V_34 ) ;
F_11 ( V_13 , V_55 , V_19 , 16 , 1 , V_34 ) ;
}
V_20 = F_17 ( V_19 , 17 ) ;
F_24 ( V_56 , V_20 , V_10 , V_11 ) ;
break;
default:
V_20 = F_17 ( V_19 , 12 ) ;
F_24 ( V_57 , V_20 , V_10 , V_11 ) ;
break;
}
}
void
F_28 ( void )
{
static T_10 V_58 [] = {
{ & V_29 ,
{ L_6 , L_7 , V_59 , V_60 , NULL , 0x0 ,
L_8 , V_61 } } ,
{ & V_33 ,
{ L_9 , L_10 , V_62 , V_63 ,
F_29 ( V_64 ) , 0xF0 , NULL , V_61 } } ,
{ & V_35 ,
{ L_11 , L_12 , V_62 , V_63 ,
F_29 ( V_65 ) , 0x03 , L_13 , V_61 } } ,
{ & V_36 ,
{ L_11 , L_14 , V_62 , V_66 , NULL , 0x0F ,
L_15 , V_61 } } ,
{ & V_37 ,
{ L_16 , L_17 , V_59 , V_60 , NULL , 0x0 ,
L_18 , V_61 } } ,
{ & V_31 ,
{ L_19 , L_20 , V_59 , V_60 , NULL , 0x0 ,
L_21 , V_61 } } ,
{ & V_38 ,
{ L_22 , L_23 , V_67 , V_63 , NULL , 0x0 ,
NULL , V_61 } } ,
{ & V_40 ,
{ L_24 , L_25 , V_68 , V_66 , NULL , 0x0 ,
L_26 , V_61 } } ,
{ & V_41 ,
{ L_27 , L_28 , V_67 , V_63 , NULL ,
0xFFFE , L_29 , V_61 } } ,
{ & V_42 ,
{ L_30 , L_31 , V_69 , 16 ,
F_30 ( & V_70 ) , 0x0001 , L_32 , V_61 } } ,
{ & V_43 ,
{ L_33 , L_34 , V_67 , V_63 , NULL , 0x0 ,
L_35 , V_61 } } ,
#if 0
{ &hf_isl_crc,
{ "CRC", "isl.crc", FT_UINT32, BASE_HEX, NULL, 0x0,
"CRC field of encapsulated frame", HFILL }},
#endif
{ & V_50 ,
{ L_36 , L_37 , V_67 , V_63 , NULL ,
0xFFFE , L_38 , V_61 } } ,
{ & V_51 ,
{ L_39 , L_40 , V_69 , 16 ,
F_30 ( & V_71 ) , 0x0001 , NULL , V_61 } } ,
{ & V_52 ,
{ L_41 , L_42 ,
V_67 , V_66 , NULL , 0x0 ,
L_43 , V_61 } } ,
{ & V_53 ,
{ L_44 , L_45 ,
V_67 , V_66 , NULL , 0x0 ,
L_46 , V_61 } } ,
{ & V_54 ,
{ L_47 , L_48 , V_69 , 9 ,
NULL , 0x40 , NULL , V_61 } } ,
{ & V_55 ,
{ L_49 , L_50 , V_62 , V_63 , NULL ,
0x3F , L_51 , V_61 } } ,
{ & V_49 ,
{ L_52 , L_53 , V_72 , V_60 , NULL , 0x0 ,
L_54 , V_61 } } ,
} ;
static T_9 * V_73 [] = {
& V_28 ,
& V_32 ,
} ;
V_27 = F_31 ( L_55 , L_1 , L_56 ) ;
F_32 ( V_27 , V_58 , F_33 ( V_58 ) ) ;
F_34 ( V_73 , F_33 ( V_73 ) ) ;
}
void
F_35 ( void )
{
V_46 = F_36 ( L_57 ) ;
V_56 = F_36 ( L_58 ) ;
V_57 = F_36 ( L_59 ) ;
}
