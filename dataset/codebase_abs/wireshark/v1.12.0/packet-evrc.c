static T_1
F_1 ( T_1 V_1 )
{
switch ( V_1 )
{
default:
break;
case 1 :
return ( 2 ) ;
case 2 :
return ( 5 ) ;
case 3 :
return ( 10 ) ;
case 4 :
return ( 22 ) ;
}
return ( 0 ) ;
}
static void
F_2 ( T_2 * V_2 , T_3 * V_3 , T_4 * V_4 , T_5 V_5 )
{
T_1 V_6 ;
T_1 V_7 ;
T_1 V_8 ;
T_6 V_9 , V_10 ;
T_7 V_11 ;
T_6 V_12 ;
T_8 * V_13 = NULL ;
T_4 * V_14 = NULL ;
T_4 * V_15 = NULL ;
int V_16 ;
int V_17 ;
int V_18 ;
T_1 V_19 [ 0x20 ] ;
F_3 ( V_3 -> V_20 , V_21 , L_1 ) ;
if ( ! V_4 ) return;
V_9 = 0 ;
memset ( V_19 , 0 , sizeof( V_19 ) ) ;
V_12 = F_4 ( V_2 ) ;
V_13 = F_5 ( V_4 , V_22 , V_2 , 0 , V_12 , V_23 ) ;
V_14 = F_6 ( V_13 , V_24 ) ;
if ( V_5 == V_25 )
{
F_5 ( V_14 , V_26 , V_2 , V_9 , 1 , V_27 ) ;
F_5 ( V_14 , V_28 , V_2 , V_9 , 1 , V_27 ) ;
F_5 ( V_14 , V_29 , V_2 , V_9 , 1 , V_27 ) ;
V_9 ++ ;
V_7 = 0 ;
V_11 = TRUE ;
while ( V_11 && ( V_7 < sizeof( V_19 ) ) &&
( ( V_12 - V_9 ) > 0 ) )
{
V_13 =
F_7 ( V_14 , V_2 , V_9 , 1 , L_2 , V_7 + 1 ) ;
V_15 = F_6 ( V_13 , V_30 ) ;
F_5 ( V_15 , V_31 , V_2 , V_9 , 1 , V_27 ) ;
F_5 ( V_15 , V_32 , V_2 , V_9 , 1 , V_27 ) ;
F_5 ( V_15 , V_33 , V_2 , V_9 , 1 , V_27 ) ;
V_6 = F_8 ( V_2 , V_9 ) ;
V_11 = ( V_6 & 0x80 ) ? TRUE : FALSE ;
V_19 [ V_7 ] = F_1 ( ( T_1 ) ( V_6 & 0x7f ) ) ;
V_7 ++ ;
V_9 ++ ;
}
}
else
{
switch ( V_5 )
{
default:
F_9 ( V_14 , V_3 , & V_34 , V_2 , V_9 , V_12 ) ;
return;
case V_35 :
V_16 = V_36 ;
V_17 = V_37 ;
V_18 = V_38 ;
F_5 ( V_14 , V_26 , V_2 , V_9 , 1 , V_27 ) ;
break;
case V_39 :
V_16 = V_40 ;
V_17 = V_41 ;
V_18 = V_42 ;
F_5 ( V_14 , V_26 , V_2 , V_9 , 1 , V_27 ) ;
break;
case V_43 :
V_16 = V_44 ;
V_17 = V_41 ;
V_18 = V_42 ;
F_5 ( V_14 , V_26 , V_2 , V_9 , 1 , V_27 ) ;
break;
case V_45 :
V_16 = V_46 ;
V_17 = V_41 ;
V_18 = V_42 ;
F_5 ( V_14 , V_26 , V_2 , V_9 , 1 , V_27 ) ;
break;
case V_47 :
V_16 = V_48 ;
V_17 = V_41 ;
V_18 = V_42 ;
F_5 ( V_14 , V_49 , V_2 , V_9 , 1 , V_27 ) ;
F_5 ( V_14 , V_50 , V_2 , V_9 , 1 , V_27 ) ;
break;
}
F_5 ( V_14 , V_28 , V_2 , V_9 , 1 , V_27 ) ;
F_5 ( V_14 , V_29 , V_2 , V_9 , 1 , V_27 ) ;
V_9 ++ ;
F_5 ( V_14 , V_16 , V_2 , V_9 , 1 , V_27 ) ;
F_5 ( V_14 , V_51 , V_2 , V_9 , 1 , V_27 ) ;
V_7 = ( F_8 ( V_2 , V_9 ) & 0x1f ) + 1 ;
V_9 ++ ;
V_10 = V_9 ;
V_13 =
F_7 ( V_14 , V_2 , V_9 , - 1 , L_3 ,
V_7 , F_10 ( V_7 , L_4 , L_5 ) ) ;
V_15 = F_6 ( V_13 , V_30 ) ;
V_8 = 0 ;
while ( ( V_8 < V_7 ) &&
( ( V_12 - V_9 ) > 0 ) )
{
V_6 = F_8 ( V_2 , V_9 ) ;
F_5 ( V_15 , V_17 , V_2 , V_9 , 1 , V_27 ) ;
V_19 [ V_8 ] = F_1 ( ( T_1 ) ( ( V_6 & 0xf0 ) >> 4 ) ) ;
V_8 ++ ;
if ( V_8 < V_7 )
{
F_5 ( V_15 , V_18 , V_2 , V_9 , 1 , V_27 ) ;
V_19 [ V_8 ] = F_1 ( ( T_1 ) ( V_6 & 0x0f ) ) ;
V_8 ++ ;
}
V_9 ++ ;
}
if ( V_7 & 0x01 )
{
F_5 ( V_15 , V_52 , V_2 , V_9 - 1 , 1 , V_27 ) ;
}
F_11 ( V_13 , V_9 - V_10 ) ;
}
V_8 = 0 ;
while ( ( V_8 < V_7 ) &&
( ( V_12 - V_9 ) >= V_19 [ V_8 ] ) )
{
F_7 ( V_14 , V_2 , V_9 , V_19 [ V_8 ] , L_6 , V_8 + 1 ) ;
V_9 += V_19 [ V_8 ] ;
V_8 ++ ;
}
}
static void
F_12 ( T_2 * V_2 , T_3 * V_3 , T_4 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , V_35 ) ;
}
static void
F_13 ( T_2 * V_2 , T_3 * V_3 , T_4 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , V_39 ) ;
}
static void
F_14 ( T_2 * V_2 , T_3 * V_3 , T_4 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , V_43 ) ;
}
static void
F_15 ( T_2 * V_2 , T_3 * V_3 , T_4 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , V_45 ) ;
}
static void
F_16 ( T_2 * V_2 , T_3 * V_3 , T_4 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , V_47 ) ;
}
static void
F_17 ( T_2 * V_2 , T_3 * V_3 , T_4 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , V_25 ) ;
}
void
F_18 ( void )
{
T_9 * V_53 ;
static T_10 V_54 [] =
{
{ & V_26 ,
{ L_7 , L_8 ,
V_55 , V_56 , NULL , 0xc0 ,
L_9 , V_57 }
} ,
{ & V_49 ,
{ L_7 , L_8 ,
V_55 , V_56 , NULL , 0x80 ,
L_9 , V_57 }
} ,
{ & V_50 ,
{ L_10 , L_11 ,
V_58 , 8 , F_19 ( & V_59 ) , 0x40 ,
L_12 , V_57 }
} ,
{ & V_28 ,
{ L_13 , L_14 ,
V_55 , V_60 , NULL , 0x38 ,
L_15 , V_57 }
} ,
{ & V_29 ,
{ L_16 , L_17 ,
V_55 , V_60 , NULL , 0x07 ,
L_18 , V_57 }
} ,
{ & V_36 ,
{ L_19 , L_20 ,
V_55 , V_60 , F_20 ( V_61 ) , 0xe0 ,
L_21 , V_57 }
} ,
{ & V_40 ,
{ L_19 , L_22 ,
V_55 , V_60 , F_20 ( V_62 ) , 0xe0 ,
L_21 , V_57 }
} ,
{ & V_44 ,
{ L_19 , L_23 ,
V_55 , V_60 , F_20 ( V_63 ) , 0xe0 ,
L_21 , V_57 }
} ,
{ & V_46 ,
{ L_19 , L_24 ,
V_55 , V_60 , F_20 ( V_64 ) , 0xe0 ,
L_21 , V_57 }
} ,
{ & V_48 ,
{ L_19 , L_25 ,
V_55 , V_60 , F_20 ( V_65 ) , 0xe0 ,
L_21 , V_57 }
} ,
{ & V_51 ,
{ L_26 , L_27 ,
V_55 , V_60 , NULL , 0x1f ,
L_28 , V_57 }
} ,
{ & V_37 ,
{ L_29 , L_30 ,
V_55 , V_60 , F_20 ( V_66 ) , 0xf0 ,
L_31 , V_57 }
} ,
{ & V_38 ,
{ L_29 , L_32 ,
V_55 , V_60 , F_20 ( V_66 ) , 0x0f ,
L_31 , V_57 }
} ,
{ & V_41 ,
{ L_29 , L_33 ,
V_55 , V_60 , F_20 ( V_67 ) , 0xf0 ,
L_31 , V_57 }
} ,
{ & V_42 ,
{ L_29 , L_34 ,
V_55 , V_60 , F_20 ( V_67 ) , 0x0f ,
L_31 , V_57 }
} ,
{ & V_52 ,
{ L_35 , L_36 ,
V_55 , V_60 , NULL , 0x0f ,
L_37 , V_57 }
} ,
{ & V_31 ,
{ L_38 , L_39 ,
V_58 , 8 , F_19 ( & V_68 ) , 0x80 ,
L_40 , V_57 }
} ,
{ & V_32 ,
{ L_41 , L_42 ,
V_55 , V_60 , NULL , 0x40 ,
L_43 , V_57 }
} ,
{ & V_33 ,
{ L_29 , L_44 ,
V_55 , V_60 , F_20 ( V_69 ) , 0x3f ,
L_31 , V_57 }
}
} ;
static T_11 V_70 [] = {
{ & V_34 ,
{ L_45 , V_71 , V_72 ,
L_46 ,
V_73 }
}
} ;
T_12 * V_74 ;
static T_13 * V_75 [] =
{
& V_24 ,
& V_30
} ;
V_22 =
F_21 ( L_47 , L_1 , L_48 ) ;
F_22 ( V_22 , V_54 , F_23 ( V_54 ) ) ;
F_24 ( V_75 , F_23 ( V_75 ) ) ;
V_74 =
F_25 ( V_22 ) ;
F_26 ( V_74 , V_70 , F_23 ( V_70 ) ) ;
V_53 = F_27 ( V_22 , V_76 ) ;
F_28 ( V_53 ,
L_49 ,
L_50 ,
L_51 ,
& V_77 ) ;
}
void
V_76 ( void )
{
static T_7 V_78 = FALSE ;
static T_14 V_79 ;
if ( ! V_78 )
{
T_14 V_80 ;
T_14 V_81 ;
T_14 V_82 ;
T_14 V_83 ;
T_14 V_84 ;
V_80 = F_29 ( F_12 , V_22 ) ;
V_81 = F_29 ( F_13 , V_22 ) ;
V_82 = F_29 ( F_14 , V_22 ) ;
V_83 = F_29 ( F_15 , V_22 ) ;
V_84 = F_29 ( F_16 , V_22 ) ;
V_79 = F_29 ( F_17 , V_22 ) ;
F_30 ( L_52 , L_1 , V_80 ) ;
F_30 ( L_52 , L_53 , V_81 ) ;
F_30 ( L_52 , L_54 , V_82 ) ;
F_30 ( L_52 , L_55 , V_83 ) ;
F_30 ( L_52 , L_56 , V_84 ) ;
V_78 = TRUE ;
}
else
{
F_31 ( L_57 , 60 , V_79 ) ;
}
if ( V_77 )
{
F_32 ( L_57 , 60 , V_79 ) ;
}
}
