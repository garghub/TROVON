static void
F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( & V_2 ) ;
}
static void
F_4 ( T_1 * V_3 , T_2 * V_4 , T_3 * V_5 )
{
T_4 V_6 , V_7 , V_8 , V_9 = 0 ;
T_4 V_10 , V_11 , V_12 , V_13 [ 48 ] ;
T_4 V_14 = 0 ;
T_5 V_15 = TRUE ;
T_6 V_16 [ 48 ] ;
T_7 * V_17 = NULL , * V_18 = NULL ;
T_3 * V_19 = NULL , * V_20 = NULL ;
V_10 = F_5 ( V_3 ) ;
F_6 ( V_4 -> V_21 , V_22 , L_1 ) ;
V_18 = F_7 ( V_5 , V_23 , V_3 , 0 , V_10 ,
L_2 ) ;
V_19 = F_8 ( V_18 , V_24 ) ;
F_9 ( V_19 , V_25 , V_3 , V_14 , 1 , V_26 ) ;
V_6 = F_10 ( V_3 , V_14 ) ;
if ( 0 == ( V_6 & 0xC0 ) )
{
V_11 = V_6 & 0x3F ;
F_9 ( V_19 , V_27 , V_3 , V_14 ++ , 1 , V_26 ) ;
if ( 1 == V_11 )
{
F_11 ( V_19 , V_3 , V_14 - 1 , 1 , L_3 ) ;
}
else if ( ( 2 <= V_11 ) && ( 48 >= V_11 ) )
{
F_11 ( V_19 , V_3 , V_14 - 1 , 1 , L_4 ) ;
}
else
{
F_11 ( V_19 , V_3 , V_14 - 1 , 1 , L_5 ) ;
V_15 = FALSE ;
}
F_9 ( V_19 , V_28 , V_3 , V_14 , 1 , V_26 ) ;
V_12 = F_10 ( V_3 , V_14 ) ;
F_9 ( V_19 , V_29 , V_3 , V_14 ++ , 1 , V_26 ) ;
if ( V_12 < V_11 )
{
F_11 ( V_19 , V_3 , V_14 - 1 , 1 , L_6 ) ;
V_15 = FALSE ;
}
if ( V_15 )
{
memset ( & V_13 , 0xFF , sizeof( V_13 ) ) ;
memset ( & V_16 , 0xFF , sizeof( V_16 ) ) ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
{
V_6 = F_10 ( V_3 , V_14 ++ ) ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ )
{
if ( V_6 & ( 0x80 >> V_8 ) )
{
V_13 [ V_9 ++ ] = ( V_7 << 3 ) + V_8 + 1 ;
}
}
}
V_17 = F_11 ( V_19 , V_3 , V_14 - 6 , 6 , L_7 , V_9 ) ;
V_20 = F_8 ( V_17 , V_30 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ )
{
F_12 ( V_13 [ V_7 ] < 48 ) ;
V_6 = F_10 ( V_3 , V_14 ) ;
if ( ( V_6 & 0x80 ) == 0x80 )
{
T_4 V_31 ;
T_6 V_32 ;
V_31 = F_10 ( V_3 , V_14 + 1 ) ;
V_32 = ( ( V_6 & 0x7F ) << 8 ) + V_31 ;
F_11 ( V_20 , V_3 , V_14 , 2 ,
L_8 ,
V_13 [ V_7 ] , V_32 ) ;
V_14 += 2 ;
V_16 [ V_13 [ V_7 ] - 1 ] = V_32 ;
}
else if ( ( V_6 & 0xC0 ) == 0 )
{
if ( V_6 < V_13 [ V_7 ] )
{
F_11 ( V_20 , V_3 , V_14 ++ , 1 ,
L_9 ,
V_13 [ V_7 ] , V_16 [ V_6 - 1 ] , V_6 ) ;
V_16 [ V_13 [ V_7 ] - 1 ] = V_16 [ V_6 - 1 ] ;
}
else
{
F_11 ( V_20 , V_3 , V_14 ++ , 1 ,
L_10 ,
V_13 [ V_7 ] , V_6 ) ;
}
}
else if ( V_6 == 0x40 )
{
F_11 ( V_20 , V_3 , V_14 ++ , 1 , L_11 , V_13 [ V_9 ] ) ;
V_16 [ V_13 [ V_7 ] - 1 ] = 0xFFFE ;
}
else if ( V_6 == 0x41 )
{
F_11 ( V_20 , V_3 , V_14 ++ , 1 , L_12 , V_13 [ V_9 ] ) ;
V_16 [ V_13 [ V_7 ] - 1 ] = 0xFFFE ;
}
else
{
F_11 ( V_20 , V_3 , V_14 , 1 , L_13 , V_13 [ V_9 ] , V_6 ) ;
V_16 [ V_13 [ V_7 ] - 1 ] = 0xFFFE ;
}
}
F_13 ( V_17 , V_3 , V_14 ) ;
V_17 = F_11 ( V_19 , V_3 , V_14 , 0 , L_14 ) ;
V_20 = F_8 ( V_17 , V_30 ) ;
for ( V_9 = 0 ; V_14 < V_10 ; V_8 ++ )
{
while ( ( V_16 [ V_9 ] != 0xFFFF ) && ( V_9 < V_12 ) )
{
V_9 ++ ;
}
if ( V_9 >= V_12 )
break;
V_6 = F_10 ( V_3 , V_14 ) ;
if ( ( V_6 & 0x80 ) == 0x80 )
{
if ( ( V_14 + 1 ) < V_10 )
{
T_4 V_31 ;
T_6 V_32 ;
V_31 = F_10 ( V_3 , V_14 + 1 ) ;
V_32 = ( ( V_6 & 0x7F ) << 8 ) + V_31 ;
V_16 [ V_9 ] = V_32 ;
F_11 ( V_20 , V_3 , V_14 , 2 ,
L_15 ,
++ V_9 , V_32 ) ;
V_14 += 2 ;
}
}
else if ( ( V_6 & 0xC0 ) == 0 )
{
if ( V_6 < V_9 )
{
V_16 [ V_9 ] = V_16 [ V_6 - 1 ] ;
F_11 ( V_20 , V_3 , V_14 ++ , 1 ,
L_9 ,
++ V_9 , V_16 [ V_6 - 1 ] , V_6 ) ;
}
else
{
F_11 ( V_20 , V_3 , V_14 ++ , 1 ,
L_10 ,
++ V_9 , V_6 ) ;
}
}
else if ( V_6 == 0x40 )
{
F_11 ( V_20 , V_3 , V_14 ++ , 1 , L_11 , ++ V_9 ) ;
}
else if ( V_6 == 0x41 )
{
F_11 ( V_20 , V_3 , V_14 ++ , 1 , L_12 , ++ V_9 ) ;
}
else
{
F_11 ( V_20 , V_3 , V_14 , 1 , L_13 , ++ V_9 , V_6 ) ;
}
}
F_13 ( V_17 , V_3 , V_14 ) ;
F_11 ( V_19 , V_3 , V_14 , - 1 , L_16 ) ;
}
}
}
static void
F_14 ( T_1 * V_3 , T_2 * V_4 , T_3 * V_33 )
{
T_8 * V_34 = NULL ;
T_4 V_35 , V_36 , V_37 , V_38 ;
T_9 V_14 ;
T_9 V_10 ;
T_7 * V_39 = NULL ;
T_3 * V_40 = NULL ;
T_1 * V_41 = NULL , * V_42 = NULL ;
V_10 = F_5 ( V_3 ) ;
V_14 = 0 ;
V_35 = F_10 ( V_3 , V_14 ) ;
V_39 = F_7 ( V_33 , V_23 , V_3 , 0 , V_10 ,
L_17 , V_35 & 3 ) ;
F_6 ( V_4 -> V_21 , V_43 , L_18 ) ;
V_40 = F_8 ( V_39 , V_44 ) ;
F_11 ( V_40 , V_3 , V_14 , 1 , L_19 ) ;
F_15 ( V_40 , V_45 , V_3 , V_14 , 1 , V_35 ) ;
F_15 ( V_40 , V_46 , V_3 , V_14 , 1 , V_35 ) ;
F_15 ( V_40 , V_47 , V_3 , V_14 , 1 , V_35 ) ;
F_15 ( V_40 , V_48 , V_3 , V_14 , 1 , V_35 ) ;
V_38 = V_35 & 0x0F ;
V_37 = ( V_35 & 0x60 ) >> 5 ;
V_36 = ( V_35 & 0x10 ) >> 4 ;
if ( V_37 == 1 )
{
switch ( V_38 )
{
case 0x00 :
case 0x08 :
V_4 -> V_49 = TRUE ;
V_34 = F_16 ( V_3 , V_14 , V_4 , 0 ,
V_1 , V_2 ,
V_38 & 0x03 , V_50 + 1 , ! V_36 ) ;
V_41 = F_17 ( V_3 , V_14 , V_4 , L_20 ,
V_34 , & V_51 , NULL , V_40 ) ;
break;
case 0x01 :
case 0x02 :
case 0x03 :
V_4 -> V_49 = TRUE ;
V_14 ++ ;
V_34 = F_16 ( V_3 , V_14 , V_4 , 0 ,
V_1 , V_2 , V_38 ,
V_50 , ! V_36 ) ;
V_41 = F_17 ( V_3 , V_14 , V_4 , L_20 ,
V_34 , & V_51 , NULL , V_40 ) ;
break;
case 0x0F :
F_11 ( V_40 , V_3 , V_14 , 1 , L_21 ) ;
F_18 ( V_52 , V_3 , V_4 , V_40 ) ;
break;
default:
F_11 ( V_40 , V_3 , V_14 , 1 , L_22 ) ;
F_18 ( V_52 , V_3 , V_4 , V_40 ) ;
break;
}
if ( V_41 )
{
V_14 = 0 ;
V_35 = F_10 ( V_41 , V_14 ++ ) ;
V_42 = F_19 ( V_41 , V_14 ) ;
if ( V_35 & 0x08 )
{
F_4 ( V_42 , V_4 , V_33 ) ;
}
else
{
F_18 ( V_53 , V_42 , V_4 , V_33 ) ;
}
}
}
else
{
F_11 ( V_40 , V_3 , V_14 , 1 , L_23 ) ;
F_18 ( V_52 , V_3 , V_4 , V_40 ) ;
}
}
void
F_20 ( void )
{
static T_10 V_54 [] =
{
{ & V_45 ,
{ L_24 , L_25 ,
V_55 , V_56 , NULL , 0x80 ,
NULL , V_57 }
} ,
{ & V_46 ,
{ L_26 , L_27 ,
V_55 , V_58 , F_21 ( V_59 ) , 0x60 ,
NULL , V_57 }
} ,
{ & V_47 ,
{ L_28 , L_29 ,
V_55 , V_58 , NULL , 0x10 ,
NULL , V_57 }
} ,
{ & V_48 ,
{ L_30 , L_31 ,
V_55 , V_58 , F_21 ( V_60 ) , 0x0F ,
NULL , V_57 }
} ,
{ & V_25 ,
{ L_32 , L_33 ,
V_55 , V_58 , F_21 ( V_61 ) , 0xC0 ,
NULL , V_57 }
} ,
{ & V_27 ,
{ L_34 , L_35 ,
V_55 , V_58 , NULL , 0x3F ,
NULL , V_57 }
} ,
{ & V_28 ,
{ L_36 , L_37 ,
V_55 , V_58 , NULL , 0xC0 ,
NULL , V_57 }
} ,
{ & V_29 ,
{ L_38 , L_39 ,
V_55 , V_58 , NULL , 0x3F ,
NULL , V_57 }
} ,
{ & V_62 ,
{ L_40 , L_41 ,
V_63 , V_58 , NULL , 0x0 ,
NULL , V_57 }
} ,
{ & V_64 ,
{ L_42 ,
L_43 ,
V_65 , V_66 , NULL , 0x0 ,
L_44 , V_57
}
} ,
{ & V_67 ,
{ L_45 ,
L_46 ,
V_65 , V_66 , NULL , 0x0 ,
L_47 , V_57
}
} ,
{ & V_68 ,
{ L_48 ,
L_49 ,
V_65 , V_66 , NULL , 0x0 ,
L_50 , V_57
}
} ,
{ & V_69 ,
{ L_51 ,
L_52 ,
V_65 , V_66 , NULL , 0x0 ,
L_53 , V_57
}
} ,
{ & V_70 ,
{ L_54 ,
L_55 ,
V_71 , V_66 , NULL , 0x0 ,
L_56 , V_57
}
} ,
{ & V_72 ,
{ L_57 ,
L_58 ,
V_73 , V_58 , NULL , 0x0 ,
L_59 , V_57
}
} ,
{ & V_74 ,
{ L_60 ,
L_61 ,
V_71 , V_66 , NULL , 0x0 ,
L_62 , V_57
}
} ,
{ & V_75 ,
{ L_63 ,
L_64 ,
V_73 , V_58 , NULL , 0x0 ,
L_65 , V_57
}
} ,
{ & V_76 ,
{ L_66 ,
L_67 ,
V_71 , V_66 , NULL , 0x0 ,
NULL , V_57
}
} ,
{ & V_77 ,
{ L_68 ,
L_69 ,
V_78 , V_66 , NULL , 0x0 ,
NULL , V_57
}
}
} ;
static T_11 * V_79 [] = {
& V_44 ,
& V_24 ,
& V_30 ,
& V_80 ,
& V_81 ,
} ;
V_23 = F_22 ( L_70 , L_71 , L_72 ) ;
F_23 ( V_23 , V_54 , F_24 ( V_54 ) ) ;
F_25 ( L_72 , F_14 , V_23 ) ;
F_26 ( F_1 ) ;
F_27 ( V_79 , F_24 ( V_79 ) ) ;
}
void
F_28 ( void )
{
V_52 = F_29 ( L_73 ) ;
V_53 = F_29 ( L_74 ) ;
}
