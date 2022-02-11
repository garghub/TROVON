static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_3 * V_6 , * V_7 ;
T_6 V_8 = 0 ;
T_6 V_9 ;
T_7 V_10 = F_2 ( V_1 ) ;
if ( V_10 == 0 )
return V_10 ;
F_3 ( V_2 -> V_11 , V_12 , L_1 ) ;
V_9 = F_4 ( V_1 , V_8 ) ;
V_10 -= 1 + V_9 ;
if ( V_10 > 0 )
F_5 ( V_2 -> V_11 , V_13 , L_2 , V_9 , V_10 , ( V_10 > 1 ) ? L_3 : L_4 ) ;
else
F_5 ( V_2 -> V_11 , V_13 , L_5 , V_9 ) ;
V_5 = F_6 ( V_3 , V_14 , V_1 , 0 , - 1 , V_15 ) ;
V_6 = F_7 ( V_5 , V_16 ) ;
V_5 = F_6 ( V_6 , V_17 , V_1 , 0 , V_9 + 1 , V_15 ) ;
V_7 = F_7 ( V_5 , V_18 ) ;
F_6 ( V_7 , V_19 , V_1 , V_8 , 1 , V_20 ) ;
V_8 ++ ;
F_8 ( V_21 , F_9 ( V_1 , V_8 , V_9 ) , V_2 , V_7 ) ;
V_8 += V_9 ;
F_8 ( V_21 , F_10 ( V_1 , V_8 ) , V_2 , V_6 ) ;
return V_10 ;
}
static int F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_6 V_10 = F_2 ( V_1 ) ;
if ( V_10 == 0 )
return 0 ;
F_3 ( V_2 -> V_11 , V_12 , L_1 ) ;
F_5 ( V_2 -> V_11 , V_13 , L_6 , V_10 , ( V_10 > 1 ) ? L_3 : L_4 ) ;
if ( V_3 )
{
T_5 * V_5 = F_6 ( V_3 , V_14 , V_1 , 0 , - 1 , V_15 ) ;
T_3 * V_6 = F_7 ( V_5 , V_16 ) ;
F_8 ( V_21 , V_1 , V_2 , V_6 ) ;
}
return V_10 ;
}
static T_8 F_12 ( T_1 * V_1 , T_6 V_8 , T_2 * V_2 V_4 ,
T_3 * V_3 , T_6 V_22 , T_9 V_23 , T_9 T_10 V_4 )
{
T_6 V_10 ;
T_6 V_24 = 0 ;
T_5 * V_5 ;
T_3 * V_25 ;
char V_26 [ 256 ] ;
T_9 V_27 ;
if ( ! F_13 ( V_1 , V_3 , V_8 , L_7 , V_23 ) )
return TRUE ;
if ( V_3 )
{
V_10 = F_14 ( V_1 , V_8 ) + V_8 + 2 ;
V_8 += 2 ;
while ( V_8 < V_10 )
{
T_9 V_28 = F_4 ( V_1 , V_8 + 1 ) ;
V_5 = F_6 ( V_3 , V_29 , V_1 , V_8 , V_28 + 2 , V_15 ) ;
V_25 = F_7 ( V_5 , V_30 [ V_22 * V_31 + V_24 ] ) ;
V_26 [ 0 ] = 0 ;
switch ( F_4 ( V_1 , V_8 ) )
{
case V_32 :
F_15 ( V_5 , L_8 ) ;
V_27 = F_4 ( V_1 , V_8 + 2 ) ;
if ( V_27 & V_33 )
F_16 ( V_26 , L_9 , 256 ) ;
if ( V_27 & V_34 )
F_16 ( V_26 , L_10 , 256 ) ;
if ( V_27 & V_35 )
F_16 ( V_26 , L_11 , 256 ) ;
if ( V_27 & V_36 )
F_16 ( V_26 , L_12 , 256 ) ;
F_16 ( V_26 , L_13 , 256 ) ;
F_15 ( V_5 , L_14 , V_26 + 2 ) ;
break;
case V_37 :
F_15 ( V_5 , L_15 ) ;
V_27 = F_4 ( V_1 , V_8 + 2 ) ;
if ( V_27 & V_38 )
F_16 ( V_26 , L_16 , 256 ) ;
if ( V_27 & V_39 )
F_16 ( V_26 , L_17 , 256 ) ;
F_16 ( V_26 , L_13 , 256 ) ;
F_15 ( V_5 , L_14 , V_26 + 2 ) ;
break;
case V_40 :
F_15 ( V_5 , L_18 ,
F_17 ( V_1 , V_8 + 2 , V_28 ) ) ;
break;
default:
F_15 ( V_5 , L_19 ) ;
}
V_8 = F_18 ( V_1 , V_25 , V_8 ) ;
V_24 ++ ;
}
}
return TRUE ;
}
static T_8 F_19 ( T_1 * V_1 , T_6 V_8 , T_2 * V_2 ,
T_3 * V_3 , T_6 V_22 V_4 , T_9 V_23 , T_9 T_10 )
{
T_9 V_41 ;
if ( ( V_41 = F_20 ( V_1 , V_3 , V_8 , L_20 , V_23 ) ) == 0 )
return FALSE ;
F_21 ( V_2 , V_41 , TRUE , V_42 , T_10 ) ;
return FALSE ;
}
static T_8 F_22 ( T_1 * V_1 , T_6 V_8 , T_2 * V_2 ,
T_3 * V_3 , T_6 V_22 V_4 , T_9 V_23 , T_9 T_10 )
{
T_9 V_41 ;
if ( ( V_41 = F_20 ( V_1 , V_3 , V_8 , L_21 , V_23 ) ) == 0 )
return FALSE ;
F_21 ( V_2 , V_41 , FALSE , V_43 , T_10 ) ;
return FALSE ;
}
void F_23 ( void )
{
T_6 V_44 ;
static T_11 V_45 [] = {
{ & V_29 ,
{ L_22 , L_23 ,
V_46 , V_47 , NULL , 0 ,
NULL , V_48 } } ,
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
V_46 , V_47 , NULL , 0 ,
NULL , V_48 } } ,
{ & V_19 ,
{ L_26 , L_27 ,
V_49 , V_50 , NULL , 0 ,
NULL , V_48 } }
} ;
static T_7 * V_51 [] = {
& V_16 ,
& V_18
} ;
T_7 * V_52 [ V_53 * V_31 ] ;
V_14 = F_24 ( L_28 , L_1 , L_29 ) ;
F_25 ( L_30 , F_11 , V_14 ) ;
F_25 ( L_31 , F_1 , V_14 ) ;
F_26 ( V_14 , V_45 , F_27 ( V_45 ) ) ;
F_28 ( V_51 , F_27 ( V_51 ) ) ;
for ( V_44 = 0 ; V_44 < V_53 * V_31 ; V_44 ++ )
{
V_30 [ V_44 ] = - 1 ;
V_52 [ V_44 ] = & V_30 [ V_44 ] ;
}
F_28 ( V_52 , V_53 * V_31 ) ;
}
void
F_29 ( void ) {
V_21 = F_30 ( L_32 ) ;
V_43 = F_30 ( L_30 ) ;
V_42 = F_30 ( L_31 ) ;
}
