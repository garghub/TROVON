static void
F_1 ( void )
{
F_2 ( & V_1 ,
& V_2 ) ;
}
static void
F_3 ( T_1 * V_3 , T_2 * V_4 , T_3 * V_5 )
{
T_4 V_6 , V_7 = 0 ;
T_5 V_8 , V_9 , V_10 = 0 ;
T_5 V_11 , V_12 , V_13 [ 48 ] ;
T_6 V_14 = TRUE ;
T_7 V_15 [ 48 ] ;
T_8 * V_16 = NULL , * V_17 = NULL ;
T_3 * V_18 = NULL , * V_19 = NULL ;
V_6 = F_4 ( V_3 ) ;
F_5 ( V_4 -> V_20 , V_21 , L_1 ) ;
V_17 = F_6 ( V_5 , V_22 , V_3 , 0 , - 1 ,
L_2 ) ;
V_18 = F_7 ( V_17 , V_23 ) ;
F_8 ( V_18 , V_24 , V_3 , V_7 , 1 , V_25 ) ;
V_8 = F_9 ( V_3 , V_7 ) ;
if ( 0 == ( V_8 & 0xC0 ) )
{
V_11 = V_8 & 0x3F ;
F_8 ( V_18 , V_26 , V_3 , V_7 ++ , 1 , V_25 ) ;
if ( 1 == V_11 )
{
F_10 ( V_18 , V_3 , V_7 - 1 , 1 , L_3 ) ;
}
else if ( ( 2 <= V_11 ) && ( 48 >= V_11 ) )
{
F_10 ( V_18 , V_3 , V_7 - 1 , 1 , L_4 ) ;
}
else
{
F_10 ( V_18 , V_3 , V_7 - 1 , 1 , L_5 ) ;
V_14 = FALSE ;
}
F_8 ( V_18 , V_27 , V_3 , V_7 , 1 , V_25 ) ;
V_12 = F_9 ( V_3 , V_7 ) ;
F_8 ( V_18 , V_28 , V_3 , V_7 ++ , 1 , V_25 ) ;
if ( V_12 < V_11 )
{
F_10 ( V_18 , V_3 , V_7 - 1 , 1 , L_6 ) ;
V_14 = FALSE ;
}
if ( V_14 )
{
memset ( & V_13 , 0xFF , sizeof( V_13 ) ) ;
memset ( & V_15 , 0xFF , sizeof( V_15 ) ) ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ )
{
T_5 V_29 ;
V_8 = F_9 ( V_3 , V_7 ++ ) ;
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ )
{
if ( V_8 & ( 0x80 >> V_29 ) )
{
V_13 [ V_10 ++ ] = ( V_9 << 3 ) + V_29 + 1 ;
}
}
}
V_19 = F_11 ( V_18 , V_3 , V_7 - 6 , 6 , V_30 , & V_16 ,
L_7 , V_10 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
{
F_12 ( V_13 [ V_9 ] <= 48 ) ;
V_8 = F_9 ( V_3 , V_7 ) ;
if ( ( V_8 & 0x80 ) == 0x80 )
{
T_5 V_31 ;
T_7 V_32 ;
V_31 = F_9 ( V_3 , V_7 + 1 ) ;
V_32 = ( ( V_8 & 0x7F ) << 8 ) + V_31 ;
F_13 ( V_19 , V_33 , V_3 , V_7 , 2 , V_13 [ V_9 ] ,
L_8 ,
V_13 [ V_9 ] , V_32 ) ;
V_7 += 2 ;
V_15 [ V_13 [ V_9 ] - 1 ] = V_32 ;
}
else if ( ( V_8 & 0xC0 ) == 0 )
{
if ( V_8 == 0 )
{
F_13 ( V_19 , V_33 , V_3 , V_7 ++ , 1 , V_13 [ V_9 ] ,
L_9 ,
V_13 [ V_9 ] , V_8 ) ;
}
else if ( V_8 < V_13 [ V_9 ] )
{
F_13 ( V_19 , V_33 , V_3 , V_7 ++ , 1 , V_13 [ V_9 ] ,
L_10 ,
V_13 [ V_9 ] , V_15 [ V_8 - 1 ] , V_8 ) ;
V_15 [ V_13 [ V_9 ] - 1 ] = V_15 [ V_8 - 1 ] ;
}
else
{
F_13 ( V_19 , V_33 , V_3 , V_7 ++ , 1 , V_13 [ V_9 ] ,
L_11 ,
V_13 [ V_9 ] , V_8 ) ;
}
}
else if ( V_8 == 0x40 )
{
F_13 ( V_19 , V_33 , V_3 , V_7 ++ , 1 , V_13 [ V_10 ] ,
L_12 , V_13 [ V_10 ] ) ;
V_15 [ V_13 [ V_9 ] - 1 ] = 0xFFFE ;
}
else if ( V_8 == 0x41 )
{
F_13 ( V_19 , V_33 , V_3 , V_7 ++ , 1 , V_13 [ V_10 ] ,
L_13 , V_13 [ V_10 ] ) ;
V_15 [ V_13 [ V_9 ] - 1 ] = 0xFFFE ;
}
else
{
F_13 ( V_19 , V_33 , V_3 , V_7 , 1 , V_13 [ V_10 ] ,
L_14 , V_13 [ V_10 ] , V_8 ) ;
V_15 [ V_13 [ V_9 ] - 1 ] = 0xFFFE ;
}
}
F_14 ( V_16 , V_3 , V_7 ) ;
V_19 = F_15 ( V_18 , V_3 , V_7 , 0 ,
V_30 , & V_16 , L_15 ) ;
for ( V_10 = 0 ; V_7 < V_6 ; )
{
if ( V_12 > 48 )
V_12 = 48 ;
while ( ( V_10 < V_12 ) && ( V_15 [ V_10 ] != 0xFFFF ) )
{
V_10 ++ ;
}
if ( V_10 >= V_12 )
break;
V_8 = F_9 ( V_3 , V_7 ) ;
if ( ( V_8 & 0x80 ) == 0x80 )
{
if ( ( V_7 + 1 ) < V_6 )
{
T_5 V_31 ;
T_7 V_32 ;
V_31 = F_9 ( V_3 , V_7 + 1 ) ;
V_32 = ( ( V_8 & 0x7F ) << 8 ) + V_31 ;
V_15 [ V_10 ] = V_32 ;
V_10 ++ ;
F_13 ( V_19 , V_33 , V_3 , V_7 , 2 , V_10 ,
L_16 ,
V_10 , V_32 ) ;
V_7 += 2 ;
}
else
{
++ V_10 ;
}
}
else if ( V_8 && ( ( V_8 & 0xC0 ) == 0 ) )
{
if ( V_8 < V_10 )
{
V_15 [ V_10 ] = V_15 [ V_8 - 1 ] ;
V_10 ++ ;
F_13 ( V_19 , V_33 , V_3 , V_7 ++ , 1 , V_10 ,
L_10 ,
V_10 , V_15 [ V_8 - 1 ] , V_8 ) ;
}
else
{
V_10 ++ ;
F_13 ( V_19 , V_33 , V_3 , V_7 ++ , 1 , V_10 ,
L_11 ,
V_10 , V_8 ) ;
}
}
else if ( V_8 == 0x40 )
{
V_10 ++ ;
F_13 ( V_19 , V_33 , V_3 , V_7 ++ , 1 , V_10 ,
L_12 , V_10 ) ;
}
else if ( V_8 == 0x41 )
{
V_10 ++ ;
F_13 ( V_19 , V_33 , V_3 , V_7 ++ , 1 , V_10 ,
L_13 , V_10 ) ;
}
else
{
V_10 ++ ;
F_13 ( V_19 , V_33 , V_3 , V_7 , 1 , V_10 ,
L_14 , V_10 , V_8 ) ;
}
}
F_14 ( V_16 , V_3 , V_7 ) ;
F_10 ( V_18 , V_3 , V_7 , - 1 , L_17 ) ;
}
}
}
static void
F_16 ( T_1 * V_3 , T_2 * V_4 , T_3 * V_34 )
{
T_9 * V_35 = NULL ;
T_5 V_36 , V_37 , V_38 , V_39 ;
T_10 V_7 ;
T_8 * V_40 ;
T_3 * V_41 ;
T_1 * V_42 = NULL , * V_43 = NULL ;
V_7 = 0 ;
V_36 = F_9 ( V_3 , V_7 ) ;
V_40 = F_6 ( V_34 , V_22 , V_3 , 0 , - 1 ,
L_18 , V_36 & 3 ) ;
F_5 ( V_4 -> V_20 , V_44 , L_19 ) ;
V_41 = F_7 ( V_40 , V_45 ) ;
F_10 ( V_41 , V_3 , V_7 , 1 , L_20 ) ;
F_17 ( V_41 , V_46 , V_3 , V_7 , 1 , V_36 ) ;
F_17 ( V_41 , V_47 , V_3 , V_7 , 1 , V_36 ) ;
F_17 ( V_41 , V_48 , V_3 , V_7 , 1 , V_36 ) ;
F_17 ( V_41 , V_49 , V_3 , V_7 , 1 , V_36 ) ;
V_39 = V_36 & 0x0F ;
V_38 = ( V_36 & 0x60 ) >> 5 ;
V_37 = ( V_36 & 0x10 ) >> 4 ;
if ( V_38 == 1 )
{
switch ( V_39 )
{
case 0x00 :
case 0x08 :
V_4 -> V_50 = TRUE ;
V_35 = F_18 ( & V_1 ,
V_3 , V_7 , V_4 , 0 , NULL ,
V_39 & 0x03 , V_51 + 1 , ! V_37 ) ;
V_42 = F_19 ( V_3 , V_7 , V_4 , L_21 ,
V_35 , & V_52 , NULL , V_41 ) ;
break;
case 0x01 :
case 0x02 :
case 0x03 :
V_4 -> V_50 = TRUE ;
V_7 ++ ;
V_35 = F_18 ( & V_1 ,
V_3 , V_7 , V_4 , 0 , NULL ,
V_39 , V_51 , ! V_37 ) ;
V_42 = F_19 ( V_3 , V_7 , V_4 , L_21 ,
V_35 , & V_52 , NULL , V_41 ) ;
break;
case 0x0F :
F_10 ( V_41 , V_3 , V_7 , 1 , L_22 ) ;
F_20 ( V_53 , V_3 , V_4 , V_41 ) ;
break;
default:
F_10 ( V_41 , V_3 , V_7 , 1 , L_23 ) ;
F_20 ( V_53 , V_3 , V_4 , V_41 ) ;
break;
}
if ( V_42 )
{
V_7 = 0 ;
V_36 = F_9 ( V_42 , V_7 ++ ) ;
V_43 = F_21 ( V_42 , V_7 ) ;
if ( V_36 & 0x08 )
{
F_3 ( V_43 , V_4 , V_34 ) ;
}
else
{
F_20 ( V_54 , V_43 , V_4 , V_34 ) ;
}
}
}
else
{
F_10 ( V_41 , V_3 , V_7 , 1 , L_24 ) ;
F_20 ( V_53 , V_3 , V_4 , V_41 ) ;
}
}
void
F_22 ( void )
{
static T_11 V_55 [] =
{
{ & V_46 ,
{ L_25 , L_26 ,
V_56 , V_57 , NULL , 0x80 ,
NULL , V_58 }
} ,
{ & V_47 ,
{ L_27 , L_28 ,
V_56 , V_59 , F_23 ( V_60 ) , 0x60 ,
NULL , V_58 }
} ,
{ & V_48 ,
{ L_29 , L_30 ,
V_56 , V_59 , NULL , 0x10 ,
NULL , V_58 }
} ,
{ & V_49 ,
{ L_31 , L_32 ,
V_56 , V_59 , F_23 ( V_61 ) , 0x0F ,
NULL , V_58 }
} ,
{ & V_24 ,
{ L_33 , L_34 ,
V_56 , V_59 , F_23 ( V_62 ) , 0xC0 ,
NULL , V_58 }
} ,
{ & V_26 ,
{ L_35 , L_36 ,
V_56 , V_59 , NULL , 0x3F ,
NULL , V_58 }
} ,
{ & V_27 ,
{ L_37 , L_38 ,
V_56 , V_59 , NULL , 0xC0 ,
NULL , V_58 }
} ,
{ & V_28 ,
{ L_39 , L_40 ,
V_56 , V_59 , NULL , 0x3F ,
NULL , V_58 }
} ,
{ & V_33 ,
{ L_41 , L_42 ,
V_56 , V_59 , NULL , 0x0 ,
NULL , V_58 }
} ,
#if 0
{ &hf_gsm_cbch_sched_msg_id,
{ "GSM CBCH Schedule Message ID", "gsm_cbch.sched_msg_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
#endif
{ & V_63 ,
{ L_43 ,
L_44 ,
V_64 , V_65 , NULL , 0x0 ,
L_45 , V_58
}
} ,
{ & V_66 ,
{ L_46 ,
L_47 ,
V_64 , V_65 , NULL , 0x0 ,
L_48 , V_58
}
} ,
{ & V_67 ,
{ L_49 ,
L_50 ,
V_64 , V_65 , NULL , 0x0 ,
L_51 , V_58
}
} ,
{ & V_68 ,
{ L_52 ,
L_53 ,
V_64 , V_65 , NULL , 0x0 ,
L_54 , V_58
}
} ,
{ & V_69 ,
{ L_55 ,
L_56 ,
V_70 , V_65 , NULL , 0x0 ,
L_57 , V_58
}
} ,
{ & V_71 ,
{ L_58 ,
L_59 ,
V_72 , V_59 , NULL , 0x0 ,
L_60 , V_58
}
} ,
{ & V_73 ,
{ L_61 ,
L_62 ,
V_70 , V_65 , NULL , 0x0 ,
L_63 , V_58
}
} ,
{ & V_74 ,
{ L_64 ,
L_65 ,
V_72 , V_59 , NULL , 0x0 ,
L_66 , V_58
}
} ,
{ & V_75 ,
{ L_67 ,
L_68 ,
V_70 , V_65 , NULL , 0x0 ,
NULL , V_58
}
} ,
{ & V_76 ,
{ L_69 ,
L_70 ,
V_77 , V_65 , NULL , 0x0 ,
NULL , V_58
}
}
} ;
static T_12 * V_78 [] = {
& V_45 ,
& V_23 ,
& V_30 ,
& V_79 ,
& V_80 ,
} ;
V_22 = F_24 ( L_71 , L_72 , L_73 ) ;
F_25 ( V_22 , V_55 , F_26 ( V_55 ) ) ;
F_27 ( L_73 , F_16 , V_22 ) ;
F_28 ( F_1 ) ;
F_29 ( V_78 , F_26 ( V_78 ) ) ;
}
void
F_30 ( void )
{
V_53 = F_31 ( L_74 ) ;
V_54 = F_31 ( L_75 ) ;
}
