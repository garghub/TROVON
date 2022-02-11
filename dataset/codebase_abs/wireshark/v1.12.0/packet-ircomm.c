static void F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 = 0 ;
T_4 V_5 ;
char V_6 [ 128 ] ;
T_4 V_7 ;
if ( F_2 ( V_1 ) == 0 )
return;
F_3 ( V_2 -> V_8 , V_9 , L_1 ) ;
V_5 = F_4 ( V_1 , V_4 ) ;
V_7 = F_2 ( V_1 ) - 1 - V_5 ;
if ( V_7 > 0 )
F_5 ( V_6 , 128 , L_2 , V_5 , V_7 , ( V_7 > 1 ) ? L_3 : L_4 ) ;
else
F_5 ( V_6 , 128 , L_5 , V_5 ) ;
F_6 ( V_2 -> V_8 , V_10 , V_6 ) ;
if ( V_3 )
{
T_5 * V_11 = F_7 ( V_3 , V_12 , V_1 , 0 , - 1 , V_13 ) ;
T_3 * V_14 = F_8 ( V_11 , V_15 ) ;
T_3 * V_16 ;
V_11 = F_7 ( V_14 , V_17 , V_1 , 0 , V_5 + 1 , V_13 ) ;
V_16 = F_8 ( V_11 , V_18 ) ;
F_7 ( V_16 , V_19 , V_1 , V_4 , 1 , V_20 ) ;
V_4 ++ ;
{
T_1 * V_21 = F_9 ( V_1 , V_4 , V_5 , V_5 ) ;
F_10 ( V_22 , V_21 , V_2 , V_16 ) ;
V_4 += V_5 ;
}
V_1 = F_11 ( V_1 , V_4 ) ;
F_10 ( V_22 , V_1 , V_2 , V_14 ) ;
}
}
static void F_12 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_7 = F_2 ( V_1 ) ;
char V_6 [ 128 ] ;
if ( V_7 == 0 )
return;
F_3 ( V_2 -> V_8 , V_9 , L_1 ) ;
F_5 ( V_6 , 128 , L_6 , V_7 , ( V_7 > 1 ) ? L_3 : L_4 ) ;
F_6 ( V_2 -> V_8 , V_10 , V_6 ) ;
if ( V_3 )
{
T_5 * V_11 = F_7 ( V_3 , V_12 , V_1 , 0 , - 1 , V_13 ) ;
T_3 * V_14 = F_8 ( V_11 , V_15 ) ;
F_10 ( V_22 , V_1 , V_2 , V_14 ) ;
}
}
static T_6 F_13 ( T_1 * V_1 , T_4 V_4 , T_2 * V_2 V_23 ,
T_3 * V_14 , T_4 V_24 , T_7 V_25 )
{
T_4 V_7 ;
T_4 V_26 = 0 ;
T_5 * V_11 ;
T_3 * V_27 ;
char V_6 [ 256 ] ;
T_7 V_28 ;
if ( ! F_14 ( V_1 , V_14 , V_4 , L_7 , V_25 ) )
return TRUE ;
if ( V_14 )
{
V_7 = F_15 ( V_1 , V_4 ) + V_4 + 2 ;
V_4 += 2 ;
while ( V_4 < V_7 )
{
T_7 V_29 = F_4 ( V_1 , V_4 + 1 ) ;
V_11 = F_7 ( V_14 , V_30 , V_1 , V_4 , V_29 + 2 , V_13 ) ;
V_27 = F_8 ( V_11 , V_31 [ V_24 * V_32 + V_26 ] ) ;
V_6 [ 0 ] = 0 ;
switch ( F_4 ( V_1 , V_4 ) )
{
case V_33 :
F_16 ( V_11 , L_8 ) ;
V_28 = F_4 ( V_1 , V_4 + 2 ) ;
if ( V_28 & V_34 )
F_17 ( V_6 , L_9 , 256 ) ;
if ( V_28 & V_35 )
F_17 ( V_6 , L_10 , 256 ) ;
if ( V_28 & V_36 )
F_17 ( V_6 , L_11 , 256 ) ;
if ( V_28 & V_37 )
F_17 ( V_6 , L_12 , 256 ) ;
F_17 ( V_6 , L_13 , 256 ) ;
F_16 ( V_11 , L_14 , V_6 + 2 ) ;
break;
case V_38 :
F_16 ( V_11 , L_15 ) ;
V_28 = F_4 ( V_1 , V_4 + 2 ) ;
if ( V_28 & V_39 )
F_17 ( V_6 , L_16 , 256 ) ;
if ( V_28 & V_40 )
F_17 ( V_6 , L_17 , 256 ) ;
F_17 ( V_6 , L_13 , 256 ) ;
F_16 ( V_11 , L_14 , V_6 + 2 ) ;
break;
case V_41 :
F_16 ( V_11 , L_18 ,
F_18 ( V_1 , V_4 + 2 , V_29 ) ) ;
break;
default:
F_16 ( V_11 , L_19 ) ;
}
V_4 = F_19 ( V_1 , V_27 , V_4 ) ;
V_26 ++ ;
}
}
return TRUE ;
}
static T_6 F_20 ( T_1 * V_1 , T_4 V_4 , T_2 * V_2 ,
T_3 * V_14 , T_4 V_24 V_23 , T_7 V_25 )
{
T_7 V_42 ;
if ( ( V_42 = F_21 ( V_1 , V_14 , V_4 , L_20 , V_25 ) ) == 0 )
return FALSE ;
F_22 ( V_2 , V_42 , TRUE , F_1 ) ;
return FALSE ;
}
static T_6 F_23 ( T_1 * V_1 , T_4 V_4 , T_2 * V_2 ,
T_3 * V_14 , T_4 V_24 V_23 , T_7 V_25 )
{
T_7 V_42 ;
if ( ( V_42 = F_21 ( V_1 , V_14 , V_4 , L_21 , V_25 ) ) == 0 )
return FALSE ;
F_22 ( V_2 , V_42 , FALSE , F_12 ) ;
return FALSE ;
}
void F_24 ( void )
{
T_4 V_43 ;
static T_8 V_44 [] = {
{ & V_30 ,
{ L_22 , L_23 ,
V_45 , V_46 , NULL , 0 ,
NULL , V_47 } } ,
#if 0
{ &hf_param_pi,
{ "Parameter Identifier", "ircomm.pi",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_param_pl,
{ "Parameter Length", "ircomm.pl",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_param_pv,
{ "Parameter Value", "ircomm.pv",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
#endif
{ & V_17 ,
{ L_24 , L_25 ,
V_45 , V_46 , NULL , 0 ,
NULL , V_47 } } ,
{ & V_19 ,
{ L_26 , L_27 ,
V_48 , V_49 , NULL , 0 ,
NULL , V_47 } }
} ;
static T_9 * V_50 [] = {
& V_15 ,
& V_18
} ;
T_9 * V_51 [ V_52 * V_32 ] ;
V_12 = F_25 ( L_28 , L_1 , L_29 ) ;
F_26 ( V_12 , V_44 , F_27 ( V_44 ) ) ;
F_28 ( V_50 , F_27 ( V_50 ) ) ;
for ( V_43 = 0 ; V_43 < V_52 * V_32 ; V_43 ++ )
{
V_31 [ V_43 ] = - 1 ;
V_51 [ V_43 ] = & V_31 [ V_43 ] ;
}
F_28 ( V_51 , V_52 * V_32 ) ;
}
void
F_29 ( void ) {
V_22 = F_30 ( L_30 ) ;
}
