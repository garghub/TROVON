T_1 *
F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 , T_5 V_5 )
{
int V_6 , V_7 ;
T_6 V_8 ;
T_7 V_9 , V_10 ;
T_6 V_11 , V_12 , V_13 , V_14 , V_15 , V_16 ;
T_8 * V_17 ;
T_1 * V_18 ;
T_5 V_19 = FALSE ;
V_6 = V_4 ;
V_7 = F_2 ( V_1 , V_4 ) ;
V_8 = F_3 ( V_1 , V_4 ) ;
V_11 = V_8 & 0x0f ;
V_12 = V_8 >> 4 ;
V_4 ++ ;
V_8 = F_3 ( V_1 , V_4 ) ;
V_13 = V_8 & 0x0f ;
V_16 = V_8 >> 4 ;
V_4 ++ ;
V_8 = F_3 ( V_1 , V_4 ) ;
V_14 = V_8 & 0x0f ;
V_15 = V_8 >> 4 ;
V_9 = 100 * V_11 + 10 * V_12 + V_13 ;
V_10 = 10 * V_14 + V_15 ;
if ( ( V_16 != 0xf ) || ( V_7 == 0xffffff ) ) {
V_19 = TRUE ;
if( V_5 )
V_10 = 10 * V_10 + V_16 ;
else
V_10 = 100 * V_16 + V_10 ;
}
V_17 = F_4 ( V_3 , V_20 , V_1 , V_6 , 2 , V_9 ) ;
if ( ( ( V_11 > 9 ) || ( V_12 > 9 ) || ( V_13 > 9 ) ) && ( V_7 != 0xffffff ) )
F_5 ( V_2 , V_17 , & V_21 ) ;
if ( V_19 ) {
V_17 = F_6 ( V_3 , V_22 , V_1 , V_6 + 1 , 2 , V_10 ,
L_1 ,
F_7 ( V_9 * 1000 + V_10 , & V_23 , L_2 ) ,
V_10 ) ;
V_18 = F_8 ( F_9 () , L_3 ,
V_9 ,
F_7 ( V_9 , & V_24 , L_4 ) ,
V_10 ,
F_7 ( V_9 * 1000 + V_10 , & V_23 , L_4 ) ) ;
} else {
V_17 = F_6 ( V_3 , V_22 , V_1 , V_6 + 1 , 2 , V_10 ,
L_5 ,
F_7 ( V_9 * 1000 + 10 * V_10 , & V_23 , L_2 ) ,
V_10 ) ;
V_18 = F_8 ( F_9 () , L_6 ,
V_9 ,
F_7 ( V_9 , & V_24 , L_4 ) ,
V_10 ,
F_7 ( V_9 * 1000 + V_10 , & V_23 , L_4 ) ) ;
}
if ( ( ( V_14 > 9 ) || ( V_15 > 9 ) || ( ( V_16 > 9 ) && ( V_16 != 0x0f ) ) ) && ( V_7 != 0xffffff ) )
F_5 ( V_2 , V_17 , & V_25 ) ;
return V_18 ;
}
int
F_10 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 , T_5 V_5 )
{
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
return V_4 + 3 ;
}
int
F_11 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 )
{
T_9 V_6 , V_7 ;
T_6 V_8 ;
T_7 V_9 , V_10 ;
T_6 V_11 , V_12 , V_13 , V_14 , V_15 , V_16 ;
T_8 * V_17 ;
T_5 V_19 ;
V_19 = FALSE ;
V_6 = V_4 ;
V_7 = F_2 ( V_1 , V_4 ) ;
V_8 = F_3 ( V_1 , V_4 ) ;
V_11 = V_8 & 0x0f ;
V_12 = V_8 >> 4 ;
V_4 ++ ;
V_8 = F_3 ( V_1 , V_4 ) ;
V_13 = V_8 & 0x0f ;
V_14 = V_8 >> 4 ;
V_4 ++ ;
V_8 = F_3 ( V_1 , V_4 ) ;
V_15 = V_8 & 0x0f ;
V_16 = V_8 >> 4 ;
V_9 = 100 * V_11 + 10 * V_12 + V_13 ;
V_10 = 10 * V_14 + V_15 ;
if ( ! F_12 ( V_9 * 1000 + 10 * V_10 , & V_23 ) ) {
V_10 = 10 * V_10 + V_16 ;
V_19 = TRUE ;
}
V_17 = F_4 ( V_3 , V_20 , V_1 , V_6 , 2 , V_9 ) ;
if ( ( ( V_11 > 9 ) || ( V_12 > 9 ) || ( V_13 > 9 ) ) & ( V_7 != 0xffffff ) )
F_5 ( V_2 , V_17 , & V_21 ) ;
if ( V_19 )
V_17 = F_6 ( V_3 , V_22 , V_1 , V_6 + 1 , 2 , V_10 ,
L_1 ,
F_7 ( V_9 * 1000 + V_10 , & V_23 , L_2 ) ,
V_10 ) ;
else
V_17 = F_6 ( V_3 , V_22 , V_1 , V_6 + 1 , 2 , V_10 ,
L_5 ,
F_7 ( V_9 * 1000 + 10 * V_10 , & V_23 , L_2 ) ,
V_10 ) ;
if ( ( ( V_14 > 9 ) || ( V_15 > 9 ) || ( V_19 && ( V_16 > 9 ) ) ) && ( V_7 != 0xffffff ) )
F_5 ( V_2 , V_17 , & V_25 ) ;
if ( V_19 )
return 6 ;
else
return 5 ;
}
void
F_13 ( void )
{
static T_10 V_26 [] = {
{ & V_20 ,
{ L_7 , L_8 ,
V_27 , V_28 | V_29 , & V_24 , 0x0 ,
L_9 , V_30 }
} ,
{ & V_22 ,
{ L_10 , L_11 ,
V_27 , V_28 , NULL , 0x0 ,
L_12 , V_30 }
} ,
#if 0
{ &hf_E212_msin,
{ "Mobile Subscriber Identification Number (MSIN)", "e212.msin",
FT_STRING, BASE_NONE, NULL, 0,
"Mobile Subscriber Identification Number(MSIN)", HFILL }},
#endif
} ;
static T_11 V_31 [] = {
{ & V_21 , { L_13 , V_32 , V_33 , L_14 , V_34 } } ,
{ & V_25 , { L_15 , V_32 , V_33 , L_16 , V_34 } } ,
} ;
T_12 * V_35 ;
V_36 = F_14 (
L_17 ,
L_18 ,
L_19 ) ;
F_15 ( V_36 , V_26 , F_16 ( V_26 ) ) ;
V_35 = F_17 ( V_36 ) ;
F_18 ( V_35 , V_31 , F_16 ( V_31 ) ) ;
}
