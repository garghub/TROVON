T_1 *
F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 , T_5 V_5 , T_6 V_6 )
{
int V_7 , V_8 ;
T_7 V_9 ;
T_8 V_10 , V_11 ;
T_7 V_12 , V_13 , V_14 , V_15 , V_16 , V_17 ;
T_9 * V_18 ;
T_1 * V_19 ;
T_6 V_20 = FALSE ;
int V_21 , V_22 ;
switch( V_5 ) {
case V_23 :
V_21 = V_24 ;
V_22 = V_25 ;
break;
case V_26 :
V_21 = V_27 ;
V_22 = V_28 ;
break;
case V_29 :
V_21 = V_30 ;
V_22 = V_31 ;
break;
case V_32 :
V_21 = V_33 ;
V_22 = V_34 ;
break;
case V_35 :
V_21 = V_36 ;
V_22 = V_37 ;
break;
case V_38 :
V_21 = V_39 ;
V_22 = V_40 ;
break;
default:
V_21 = V_41 ;
V_22 = V_42 ;
}
V_7 = V_4 ;
V_8 = F_2 ( V_1 , V_4 ) ;
V_9 = F_3 ( V_1 , V_4 ) ;
V_12 = V_9 & 0x0f ;
V_13 = V_9 >> 4 ;
V_4 ++ ;
V_9 = F_3 ( V_1 , V_4 ) ;
V_14 = V_9 & 0x0f ;
V_17 = V_9 >> 4 ;
V_4 ++ ;
V_9 = F_3 ( V_1 , V_4 ) ;
V_15 = V_9 & 0x0f ;
V_16 = V_9 >> 4 ;
V_10 = 100 * V_12 + 10 * V_13 + V_14 ;
V_11 = 10 * V_15 + V_16 ;
if ( ( V_17 != 0xf ) || ( V_8 == 0xffffff ) ) {
V_20 = TRUE ;
if( V_6 )
V_11 = 10 * V_11 + V_17 ;
else
V_11 = 100 * V_17 + V_11 ;
}
V_18 = F_4 ( V_3 , V_21 , V_1 , V_7 , 2 , V_10 ) ;
if ( ( ( V_12 > 9 ) || ( V_13 > 9 ) || ( V_14 > 9 ) ) && ( V_8 != 0xffffff ) )
F_5 ( V_2 , V_18 , & V_43 ) ;
if ( V_20 ) {
V_18 = F_6 ( V_3 , V_22 , V_1 , V_7 + 1 , 2 , V_11 ,
L_1 ,
F_7 ( V_10 * 1000 + V_11 , & V_44 , L_2 ) ,
V_11 ) ;
V_19 = F_8 ( F_9 () , L_3 ,
V_10 ,
F_7 ( V_10 , & V_45 , L_4 ) ,
V_11 ,
F_7 ( V_10 * 1000 + V_11 , & V_44 , L_4 ) ) ;
} else {
V_18 = F_6 ( V_3 , V_22 , V_1 , V_7 + 1 , 2 , V_11 ,
L_5 ,
F_7 ( V_10 * 100 + V_11 , & V_46 , L_2 ) ,
V_11 ) ;
V_19 = F_8 ( F_9 () , L_6 ,
V_10 ,
F_7 ( V_10 , & V_45 , L_4 ) ,
V_11 ,
F_7 ( V_10 * 100 + V_11 , & V_46 , L_4 ) ) ;
}
if ( ( ( V_15 > 9 ) || ( V_16 > 9 ) || ( ( V_17 > 9 ) && ( V_17 != 0x0f ) ) ) && ( V_8 != 0xffffff ) )
F_5 ( V_2 , V_18 , & V_47 ) ;
return V_19 ;
}
int
F_10 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 , T_5 V_5 , T_6 V_6 )
{
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
return V_4 + 3 ;
}
int
F_11 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 )
{
T_10 V_7 , V_8 ;
T_7 V_9 ;
T_8 V_10 , V_11 ;
T_7 V_12 , V_13 , V_14 , V_15 , V_16 , V_17 ;
T_9 * V_18 ;
T_6 V_20 ;
V_20 = FALSE ;
V_7 = V_4 ;
V_8 = F_2 ( V_1 , V_4 ) ;
V_9 = F_3 ( V_1 , V_4 ) ;
V_12 = V_9 & 0x0f ;
V_13 = V_9 >> 4 ;
V_4 ++ ;
V_9 = F_3 ( V_1 , V_4 ) ;
V_14 = V_9 & 0x0f ;
V_15 = V_9 >> 4 ;
V_4 ++ ;
V_9 = F_3 ( V_1 , V_4 ) ;
V_16 = V_9 & 0x0f ;
V_17 = V_9 >> 4 ;
V_10 = 100 * V_12 + 10 * V_13 + V_14 ;
V_11 = 10 * V_15 + V_16 ;
if ( ! F_12 ( V_10 * 100 + V_11 , & V_46 ) ) {
V_11 = 10 * V_11 + V_17 ;
V_20 = TRUE ;
}
V_18 = F_4 ( V_3 , V_41 , V_1 , V_7 , 2 , V_10 ) ;
if ( ( ( V_12 > 9 ) || ( V_13 > 9 ) || ( V_14 > 9 ) ) & ( V_8 != 0xffffff ) )
F_5 ( V_2 , V_18 , & V_43 ) ;
if ( V_20 )
V_18 = F_6 ( V_3 , V_42 , V_1 , V_7 + 1 , 2 , V_11 ,
L_1 ,
F_7 ( V_10 * 1000 + V_11 , & V_44 , L_2 ) ,
V_11 ) ;
else
V_18 = F_6 ( V_3 , V_42 , V_1 , V_7 + 1 , 2 , V_11 ,
L_5 ,
F_7 ( V_10 * 100 + V_11 , & V_46 , L_2 ) ,
V_11 ) ;
if ( ( ( V_15 > 9 ) || ( V_16 > 9 ) || ( V_20 && ( V_17 > 9 ) ) ) && ( V_8 != 0xffffff ) )
F_5 ( V_2 , V_18 , & V_47 ) ;
if ( V_20 )
return 6 ;
else
return 5 ;
}
static int
F_13 ( T_2 * V_1 , T_3 * V_2 V_48 , T_4 * V_3 , int V_4 )
{
T_10 V_7 ;
T_7 V_9 ;
T_8 V_10 , V_11 ;
T_7 V_12 , V_13 , V_14 , V_15 , V_16 , V_17 ;
T_6 V_20 ;
V_20 = FALSE ;
V_7 = V_4 ;
V_9 = F_3 ( V_1 , V_4 ) ;
V_12 = V_9 >> 4 ;
V_4 ++ ;
V_9 = F_3 ( V_1 , V_4 ) ;
V_13 = V_9 & 0x0f ;
V_14 = V_9 >> 4 ;
V_4 ++ ;
V_9 = F_3 ( V_1 , V_4 ) ;
V_15 = V_9 & 0x0f ;
V_16 = V_9 >> 4 ;
V_4 ++ ;
V_9 = F_3 ( V_1 , V_4 ) ;
V_17 = V_9 & 0x0f ;
V_10 = 100 * V_12 + 10 * V_13 + V_14 ;
V_11 = 10 * V_15 + V_16 ;
if ( ! F_12 ( V_10 * 100 + V_11 , & V_46 ) ) {
V_11 = 10 * V_11 + V_17 ;
V_20 = TRUE ;
}
F_4 ( V_3 , V_41 , V_1 , V_7 , 2 , V_10 ) ;
if ( V_20 )
F_6 ( V_3 , V_42 , V_1 , V_7 + 2 , 2 , V_11 ,
L_1 ,
F_7 ( V_10 * 1000 + V_11 , & V_44 , L_2 ) ,
V_11 ) ;
else
F_6 ( V_3 , V_42 , V_1 , V_7 + 2 , 1 , V_11 ,
L_5 ,
F_7 ( V_10 * 100 + V_11 , & V_46 , L_2 ) ,
V_11 ) ;
if ( V_20 )
return 7 ;
else
return 5 ;
}
int
F_14 ( T_2 * V_1 , T_3 * V_2 V_48 , T_4 * V_3 , int V_4 )
{
T_8 V_10 = 0 , V_11 = 0 ;
T_6 V_20 = FALSE ;
F_15 ( F_16 ( F_9 () , V_1 , V_4 , 3 , V_49 ) ,
NULL , & V_10 ) ;
F_15 ( F_16 ( F_9 () , V_1 , V_4 + 3 , 2 , V_49 ) ,
NULL , & V_11 ) ;
if ( ! F_12 ( V_10 * 100 + V_11 , & V_46 ) ) {
F_15 ( F_16 ( F_9 () , V_1 , V_4 + 3 , 3 , V_49 ) ,
NULL , & V_11 ) ;
V_20 = TRUE ;
}
F_4 ( V_3 , V_41 , V_1 , V_4 , 3 , V_10 ) ;
if ( V_20 )
F_6 ( V_3 , V_42 , V_1 , V_4 + 3 , 3 , V_11 ,
L_1 ,
F_7 ( V_10 * 1000 + V_11 , & V_44 , L_7 ) ,
V_11 ) ;
else
F_6 ( V_3 , V_42 , V_1 , V_4 + 3 , 2 , V_11 ,
L_5 ,
F_7 ( V_10 * 100 + V_11 , & V_46 , L_8 ) ,
V_11 ) ;
if ( V_20 )
return 6 ;
else
return 5 ;
}
const T_1 *
F_17 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 , int V_50 , T_6 V_51 )
{
T_9 * V_18 ;
T_4 * V_52 ;
const T_1 * V_53 ;
V_53 = F_18 ( V_1 , V_4 , V_50 , NULL , V_51 ) ;
V_18 = F_19 ( V_3 , V_54 , V_1 , V_4 , V_50 , V_53 ) ;
V_52 = F_20 ( V_18 , V_55 ) ;
if( V_51 ) {
F_13 ( V_1 , V_2 , V_52 , V_4 ) ;
} else {
F_11 ( V_1 , V_2 , V_52 , V_4 ) ;
}
return V_53 ;
}
const T_1 *
F_21 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 , int V_50 )
{
T_9 * V_18 ;
T_4 * V_52 ;
const T_1 * V_53 ;
V_53 = F_16 ( F_9 () , V_1 , V_4 , V_50 , V_49 ) ;
V_18 = F_19 ( V_3 , V_54 , V_1 , V_4 , V_50 , V_53 ) ;
V_52 = F_20 ( V_18 , V_55 ) ;
F_14 ( V_1 , V_2 , V_52 , V_4 ) ;
return V_53 ;
}
void
F_22 ( void )
{
static T_11 V_56 [] = {
{ & V_54 ,
{ L_9 , L_10 ,
V_57 , V_58 , NULL , 0x0 ,
L_11 , V_59 }
} ,
{ & V_41 ,
{ L_12 , L_13 ,
V_60 , V_61 | V_62 , & V_45 , 0x0 ,
L_14 , V_59 }
} ,
{ & V_24 ,
{ L_12 , L_15 ,
V_60 , V_61 | V_62 , & V_45 , 0x0 ,
L_14 , V_59 }
} ,
{ & V_27 ,
{ L_12 , L_16 ,
V_60 , V_61 | V_62 , & V_45 , 0x0 ,
L_14 , V_59 }
} ,
{ & V_30 ,
{ L_12 , L_17 ,
V_60 , V_61 | V_62 , & V_45 , 0x0 ,
L_14 , V_59 }
} ,
{ & V_33 ,
{ L_12 , L_18 ,
V_60 , V_61 | V_62 , & V_45 , 0x0 ,
L_14 , V_59 }
} ,
{ & V_36 ,
{ L_12 , L_19 ,
V_60 , V_61 | V_62 , & V_45 , 0x0 ,
L_14 , V_59 }
} ,
{ & V_39 ,
{ L_12 , L_20 ,
V_60 , V_61 | V_62 , & V_45 , 0x0 ,
L_14 , V_59 }
} ,
{ & V_42 ,
{ L_21 , L_22 ,
V_60 , V_61 , NULL , 0x0 ,
L_23 , V_59 }
} ,
{ & V_25 ,
{ L_21 , L_24 ,
V_60 , V_61 , NULL , 0x0 ,
L_23 , V_59 }
} ,
{ & V_28 ,
{ L_21 , L_25 ,
V_60 , V_61 , NULL , 0x0 ,
L_23 , V_59 }
} ,
{ & V_31 ,
{ L_21 , L_26 ,
V_60 , V_61 , NULL , 0x0 ,
L_23 , V_59 }
} ,
{ & V_34 ,
{ L_21 , L_27 ,
V_60 , V_61 , NULL , 0x0 ,
L_23 , V_59 }
} ,
{ & V_37 ,
{ L_21 , L_28 ,
V_60 , V_61 , NULL , 0x0 ,
L_23 , V_59 }
} ,
{ & V_40 ,
{ L_21 , L_29 ,
V_60 , V_61 , NULL , 0x0 ,
L_23 , V_59 }
} ,
#if 0
{ &hf_E212_msin,
{ "Mobile Subscriber Identification Number (MSIN)", "e212.msin",
FT_STRING, BASE_NONE, NULL, 0,
"Mobile Subscriber Identification Number(MSIN)", HFILL }},
#endif
} ;
static T_12 * V_63 [] = {
& V_55 ,
} ;
static T_13 V_64 [] = {
{ & V_43 , { L_30 , V_65 , V_66 , L_31 , V_67 } } ,
{ & V_47 , { L_32 , V_65 , V_66 , L_33 , V_67 } } ,
} ;
T_14 * V_68 ;
V_69 = F_23 (
L_34 ,
L_35 ,
L_36 ) ;
F_24 ( V_69 , V_56 , F_25 ( V_56 ) ) ;
F_26 ( V_63 , F_25 ( V_63 ) ) ;
V_68 = F_27 ( V_69 ) ;
F_28 ( V_68 , V_64 , F_25 ( V_64 ) ) ;
}
