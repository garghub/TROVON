static void
F_1 ( T_1 V_1 , T_1 V_2 , T_2 * V_3 , T_3 V_4 , T_4 * V_5 )
{
const char * V_6 ;
T_4 * V_7 = NULL ;
V_6 = F_2 ( V_1 , V_8 , L_1 ) ;
V_7 = F_3 ( V_5 , V_3 , V_4 , V_2 + 2 , V_9 , NULL , L_2 , V_6 ) ;
F_4 ( V_7 , V_10 , V_3 , V_4 , 1 , V_1 ) ;
F_4 ( V_7 , V_11 , V_3 , V_4 + 1 , 1 , V_2 ) ;
if ( ! V_2 )
return;
switch ( V_1 ) {
case ( V_12 ) :
F_5 ( V_7 , V_13 , V_3 ,
V_4 + 2 , V_2 , V_14 ) ;
break;
case ( V_15 ) :
F_5 ( V_7 , V_16 , V_3 ,
V_4 + 2 , V_2 , V_14 ) ;
break;
case ( V_17 ) :
F_5 ( V_7 , V_18 , V_3 ,
V_4 + 2 , V_2 , V_14 ) ;
break;
case ( V_19 ) :
F_5 ( V_7 , V_20 , V_3 ,
V_4 + 2 , V_2 , V_21 | V_22 ) ;
break;
case ( V_23 ) :
F_5 ( V_7 , V_24 , V_3 ,
V_4 + 2 , V_2 , V_22 ) ;
break;
case ( V_25 ) :
F_5 ( V_7 , V_26 , V_3 ,
V_4 + 2 , V_2 , V_22 ) ;
break;
case ( V_27 ) :
F_5 ( V_7 , V_28 , V_3 ,
V_4 + 2 , V_2 , V_22 ) ;
break;
default:
F_5 ( V_7 , V_29 , V_3 ,
V_4 + 2 , V_2 , V_22 ) ;
break;
}
return;
}
static int
F_6 ( T_2 * V_3 , T_5 * V_30 , T_4 * V_5 , void * T_6 V_31 )
{
T_1 V_1 , V_2 ;
T_3 V_32 , V_4 = 0 ;
T_7 V_33 ;
T_8 * V_34 ;
T_4 * V_35 = NULL ;
T_2 * V_36 ;
F_7 ( V_30 -> V_37 , V_38 , L_3 ) ;
V_34 = F_5 ( V_5 , V_39 ,
V_3 , 0 , - 1 , V_22 ) ;
V_35 = F_8 ( V_34 , V_9 ) ;
V_32 = F_9 ( V_3 ) ;
V_4 = 0 ;
V_33 = FALSE ;
while ( ! V_33 && ( V_32 > 2 ) ) {
V_1 = F_10 ( V_3 , V_4 + 0 ) ;
V_2 = F_10 ( V_3 , V_4 + 1 ) ;
if ( ( V_32 - 2 ) < V_2 )
break;
if ( V_5 )
F_1 ( V_1 , V_2 , V_3 , V_4 , V_35 ) ;
if ( V_1 == V_23 )
V_33 = TRUE ;
V_4 += 2 + V_2 ;
V_32 -= 2 + V_2 ;
}
V_36 = F_11 ( V_3 , V_4 ) ;
F_12 ( V_40 , V_36 , V_30 , V_5 ) ;
return F_13 ( V_3 ) ;
}
static T_7
F_14 ( T_2 * V_3 , T_5 * V_30 , T_4 * V_5 , void * T_6 V_31 )
{
T_3 V_32 , V_4 = 0 ;
T_7 V_33 = FALSE ;
T_1 V_1 , V_2 ;
T_9 V_41 = 0 ;
V_32 = F_13 ( V_3 ) ;
if ( V_32 < V_42 )
return FALSE ;
while ( ( V_32 > 2 ) && ! V_33 ) {
V_1 = F_10 ( V_3 , V_4 + 0 ) ;
V_2 = F_10 ( V_3 , V_4 + 1 ) ;
switch ( V_1 ) {
case ( V_12 ) :
case ( V_15 ) :
case ( V_17 ) :
if ( V_2 != 4 )
return FALSE ;
V_41 |= 1 << V_1 ;
break;
case ( V_23 ) :
if ( V_2 > 1 || V_4 == 0 )
return FALSE ;
V_33 = TRUE ;
break;
case ( V_19 ) :
case ( V_25 ) :
case ( V_27 ) :
break;
default:
return FALSE ;
}
V_4 += 2 + V_2 ;
V_32 -= 2 + V_2 ;
}
if ( ! ( V_41 & ( 1 << V_12 ) ) )
return FALSE ;
if ( ! ( V_41 & ( 1 << V_17 ) ) )
return FALSE ;
if ( ! ( V_41 & ( 1 << V_15 ) ) )
return FALSE ;
F_6 ( V_3 , V_30 , V_5 , T_6 ) ;
return TRUE ;
}
void F_15 ( void ) {
static T_10 V_43 [] = {
{ & V_10 ,
{ L_4 , L_5 , V_44 , V_45 , NULL , 0x0 ,
NULL , V_46 } } ,
{ & V_11 ,
{ L_6 , L_7 , V_44 , V_45 , NULL , 0x0 ,
NULL , V_46 } } ,
{ & V_13 ,
{ L_8 , L_9 , V_47 , V_45 , NULL , 0x0 ,
NULL , V_46 } } ,
{ & V_16 ,
{ L_10 , L_11 , V_47 , V_45 , NULL , 0x0 ,
L_12 , V_46 } } ,
{ & V_18 ,
{ L_13 , L_14 , V_47 , V_45 , NULL , 0x0 ,
L_15 , V_46 } } ,
#if 0
{ &hf_redbackli_dir,
{ "Direction", "redbackli.dir", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#else
{ & V_26 ,
{ L_16 , L_17 , V_48 , V_49 , NULL , 0x0 ,
NULL , V_46 } } ,
#endif
{ & V_20 ,
{ L_18 , L_19 , V_50 , V_49 , NULL , 0x0 ,
NULL , V_46 } } ,
{ & V_28 ,
{ L_20 , L_21 , V_48 , V_49 , NULL , 0x0 ,
NULL , V_46 } } ,
{ & V_24 ,
{ L_22 , L_23 , V_48 , V_49 , NULL , 0x0 ,
NULL , V_46 } } ,
{ & V_29 ,
{ L_24 , L_25 , V_48 , V_49 , NULL , 0x0 ,
NULL , V_46 } }
} ;
static T_3 * V_51 [] = {
& V_9
} ;
V_39 = F_16 ( L_26 ,
L_27 , L_28 ) ;
F_17 ( V_39 , V_43 , F_18 ( V_43 ) ) ;
F_19 ( V_51 , F_18 ( V_51 ) ) ;
F_20 ( L_28 , F_6 , V_39 ) ;
}
void F_21 ( void ) {
T_11 V_52 ;
V_40 = F_22 ( L_29 , V_39 ) ;
V_52 = F_23 ( L_28 ) ;
F_24 ( L_30 , V_52 ) ;
F_25 ( L_31 , F_14 , L_32 , L_33 , V_39 , V_53 ) ;
}
