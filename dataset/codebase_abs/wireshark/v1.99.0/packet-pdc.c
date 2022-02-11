static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 , T_4 V_4 )
{
T_3 V_5 ;
T_4 V_6 ;
T_5 * V_7 ;
T_2 * V_8 ;
T_2 * V_9 ;
V_5 = 0 ;
F_2 ( V_2 , V_10 , V_1 , V_3 , 1 , V_11 ) ;
V_5 += 1 ;
F_2 ( V_2 , V_12 , V_1 , V_3 + V_5 , 1 , V_11 ) ;
V_5 += 1 ;
F_2 ( V_2 , V_13 , V_1 , V_3 + V_5 , 4 , V_11 ) ;
V_5 += 4 ;
if ( V_4 > 7 )
{
V_7 = F_2 ( V_2 , V_14 , V_1 , V_3 + V_5 , V_4 - 7 , V_15 ) ;
V_8 = F_3 ( V_7 , V_16 ) ;
while ( ( V_3 + V_5 ) < ( V_4 + 1 ) )
{
V_6 = F_4 ( V_1 , V_3 + V_5 ) ;
V_7 = F_2 ( V_8 , V_17 , V_1 , V_3 + V_5 , 1 , V_15 ) ;
V_9 = F_3 ( V_7 , V_16 ) ;
V_5 += 1 ;
switch ( V_6 )
{
case V_18 :
F_2 ( V_9 , V_19 , V_1 , V_3 + V_5 , 1 , V_15 ) ;
F_2 ( V_9 , V_20 , V_1 , V_3 + V_5 + 1 , 1 , V_15 ) ;
V_5 += 2 ;
break;
case V_21 :
F_2 ( V_9 , V_19 , V_1 , V_3 + V_5 , 1 , V_15 ) ;
F_2 ( V_9 , V_22 , V_1 , V_3 + V_5 + 1 , 2 , V_11 ) ;
F_2 ( V_9 , V_23 , V_1 , V_3 + V_5 + 3 , 2 , V_11 ) ;
V_5 += 5 ;
break;
case V_24 :
F_2 ( V_9 , V_19 , V_1 , V_3 + V_5 , 1 , V_15 ) ;
F_2 ( V_9 , V_25 , V_1 , V_3 + V_5 + 1 , 2 , V_11 ) ;
V_5 += 3 ;
break;
}
}
}
return ( V_5 ) ;
}
static int F_5 ( void )
{
return ( 0 ) ;
}
static int F_6 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 )
{
F_2 ( V_2 , V_26 , V_1 , V_3 , 1 , V_15 ) ;
F_2 ( V_2 , V_27 , V_1 , V_3 , 1 , V_15 ) ;
F_2 ( V_2 , V_28 , V_1 , V_3 , 1 , V_15 ) ;
F_2 ( V_2 , V_29 , V_1 , V_3 + 1 , 1 , V_15 ) ;
return ( 2 ) ;
}
static int F_7 ( T_1 * V_1 , T_2 * V_30 , T_2 * V_2 , T_3 V_3 , T_6 * V_31 )
{
T_3 V_32 ;
T_3 V_33 ;
T_1 * V_34 ;
F_2 ( V_2 , V_35 , V_1 , V_3 , 4 , V_11 ) ;
V_3 += 4 ;
if ( V_36 == 2 )
{
F_2 ( V_2 , V_37 , V_1 , V_3 , 2 , V_11 ) ;
V_32 = F_8 ( V_1 , V_3 ) ;
V_3 += 2 ;
V_33 = V_32 + 6 ;
V_34 = F_9 ( V_1 , V_3 , V_32 ) ;
if ( V_38 != NULL )
F_10 ( V_38 , V_34 , V_31 , V_30 ) ;
return ( V_33 ) ;
}
return ( 2 ) ;
}
static int F_11 ( T_1 * V_1 , T_2 * V_30 , T_2 * V_2 , T_3 V_3 , T_6 * V_31 )
{
T_3 V_32 ;
T_3 V_33 ;
T_1 * V_34 ;
if ( V_36 == 2 )
{
F_2 ( V_2 , V_39 , V_1 , V_3 , 2 , V_11 ) ;
V_32 = F_8 ( V_1 , 2 ) ;
V_33 = V_32 + 2 ;
V_34 = F_9 ( V_1 , V_3 + 2 , V_32 ) ;
if ( V_38 != NULL )
F_10 ( V_38 , V_34 , V_31 , V_30 ) ;
return ( V_33 ) ;
}
return ( 2 ) ;
}
static int F_12 ( T_1 * V_1 , T_2 * V_30 , T_2 * V_2 , T_3 V_3 , T_6 * V_31 )
{
T_3 V_32 ;
T_3 V_33 ;
T_1 * V_34 ;
if ( V_36 == 2 )
{
F_2 ( V_2 , V_39 , V_1 , V_3 , 2 , V_11 ) ;
V_32 = F_8 ( V_1 , 2 ) ;
V_33 = V_32 + 2 ;
V_34 = F_9 ( V_1 , V_3 + 2 , V_32 ) ;
if ( V_38 != NULL )
F_10 ( V_38 , V_34 , V_31 , V_30 ) ;
return ( V_33 ) ;
}
return 2 ;
}
static int F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 )
{
F_2 ( V_2 , V_40 , V_1 , V_3 , 2 , V_11 ) ;
F_2 ( V_2 , V_41 , V_1 , V_3 , 2 , V_11 ) ;
F_2 ( V_2 , V_13 , V_1 , V_3 + 2 , 4 , V_11 ) ;
return ( 6 ) ;
}
static int F_14 ( T_1 * V_1 , T_2 * V_2 , T_6 * V_31 )
{
T_7 V_42 = 0 ;
T_4 V_43 ;
T_4 V_44 ;
T_3 V_45 ;
T_5 * V_46 ;
T_2 * V_47 ;
V_45 = 0 ;
V_43 = F_4 ( V_1 , V_42 ) ;
V_44 = F_4 ( V_1 , V_42 + 1 ) ;
V_45 += 2 ;
V_46 = F_2 ( V_2 , V_48 , V_1 , V_42 , V_43 + 1 , V_15 ) ;
V_47 = F_3 ( V_46 , V_49 ) ;
F_2 ( V_47 , V_50 , V_1 , V_42 , 1 , V_11 ) ;
F_2 ( V_47 , V_51 , V_1 , V_42 + 1 , 1 , V_11 ) ;
switch ( V_44 )
{
case V_52 :
V_45 += F_1 ( V_1 , V_47 , V_45 , V_43 ) ;
F_15 ( V_31 -> V_53 , V_54 , L_1 ) ;
break;
case V_55 :
V_45 += F_5 () ;
F_15 ( V_31 -> V_53 , V_54 , L_2 ) ;
break;
case V_56 :
V_45 += F_6 ( V_1 , V_47 , V_45 ) ;
F_15 ( V_31 -> V_53 , V_54 , L_3 ) ;
break;
case V_57 :
V_45 += F_11 ( V_1 , V_2 , V_47 , V_45 , V_31 ) ;
F_15 ( V_31 -> V_53 , V_54 , L_4 ) ;
break;
case V_58 :
V_45 += F_7 ( V_1 , V_2 , V_47 , V_45 , V_31 ) ;
F_15 ( V_31 -> V_53 , V_54 , L_5 ) ;
break;
case V_59 :
V_45 += F_12 ( V_1 , V_2 , V_47 , V_45 , V_31 ) ;
F_15 ( V_31 -> V_53 , V_54 , L_6 ) ;
break;
case V_60 :
V_45 += F_13 ( V_1 , V_47 , V_45 ) ;
F_15 ( V_31 -> V_53 , V_54 , L_7 ) ;
break;
default:
break;
} ;
return ( V_45 ) ;
}
static int F_16 ( T_1 * V_1 , T_6 * V_31 , T_2 * V_2 , void * T_8 V_61 )
{
F_15 ( V_31 -> V_53 , V_62 , V_63 ) ;
F_17 ( V_31 -> V_53 , V_54 ) ;
F_14 ( V_1 , V_2 , V_31 ) ;
return F_18 ( V_1 ) ;
}
static T_7 F_19 ( T_6 * V_31 V_61 , T_1 * V_1 , int V_3 )
{
T_7 V_64 ;
T_7 V_65 ;
T_4 V_66 ;
V_66 = F_4 ( V_1 , V_3 + 1 ) ;
switch ( V_66 )
{
case V_52 :
V_64 = F_4 ( V_1 , V_3 ) ;
V_65 = 1 ;
break;
case V_55 :
V_64 = F_4 ( V_1 , V_3 ) ;
V_65 = 1 ;
break;
case V_56 :
V_64 = F_4 ( V_1 , V_3 ) ;
V_65 = 1 ;
break;
case V_57 :
V_64 = F_8 ( V_1 , V_3 + 2 ) ;
V_65 = 4 ;
break;
case V_58 :
V_64 = F_8 ( V_1 , V_3 + 6 ) ;
V_65 = 8 ;
break;
case V_59 :
V_64 = F_4 ( V_1 , V_3 ) ;
V_65 = 1 ;
break;
case V_60 :
V_64 = F_4 ( V_1 , V_3 ) + 1 ;
V_65 = 0 ;
break;
default:
V_64 = 0 ;
V_65 = 0 ;
}
return V_64 + V_65 ;
}
static void F_20 ( T_1 * V_1 , T_6 * V_31 , T_2 * V_2 )
{
T_4 V_66 ;
T_4 V_67 ;
V_66 = F_4 ( V_1 , 1 ) ;
switch ( V_66 )
{
case V_52 :
V_67 = 2 ;
break;
case V_55 :
V_67 = 2 ;
break;
case V_56 :
V_67 = 2 ;
break;
case V_57 :
V_67 = 4 ;
break;
case V_58 :
V_67 = 8 ;
break;
case V_59 :
V_67 = 2 ;
break;
case V_60 :
V_67 = 2 ;
break;
default:
V_67 = 2 ;
break;
}
F_21 ( V_1 , V_31 , V_2 , TRUE , V_67 , F_19 , F_16 , NULL ) ;
}
void F_22 ( void )
{
T_9 * V_68 ;
static T_10 V_69 [] =
{
{ & V_50 ,
{ L_8 , L_9 ,
V_70 , V_71 , NULL , 0x0 , NULL , V_72 } } ,
{ & V_51 ,
{ L_10 , L_11 ,
V_70 , V_71 , F_23 ( V_73 ) , 0x0 , NULL , V_72 } } ,
{ & V_10 ,
{ L_12 , L_13 ,
V_70 , V_71 , NULL , 0x0 , NULL , V_72 } } ,
{ & V_13 ,
{ L_14 , L_15 ,
V_74 , V_71 , NULL , 0x0 , NULL , V_72 } } ,
{ & V_12 ,
{ L_16 , L_17 ,
V_70 , V_71 , F_23 ( V_75 ) , 0x0 , NULL , V_72 } } ,
{ & V_40 ,
{ L_18 , L_19 ,
V_76 , V_71 , NULL , 0x8000 , NULL , V_72 } } ,
{ & V_41 ,
{ L_20 , L_21 ,
V_76 , V_71 , NULL , 0x07FF , NULL , V_72 } } ,
{ & V_14 ,
{ L_22 , L_23 ,
V_77 , V_78 , NULL , 0x0 , NULL , V_72 } } ,
{ & V_17 ,
{ L_24 , L_25 ,
V_70 , V_71 , F_23 ( V_79 ) , 0x0 , NULL , V_72 } } ,
{ & V_19 ,
{ L_26 , L_27 ,
V_70 , V_71 , NULL , 0x0 , NULL , V_72 } } ,
{ & V_20 ,
{ L_28 , L_29 ,
V_70 , V_71 , NULL , 0x0 , NULL , V_72 } } ,
{ & V_22 ,
{ L_30 , L_31 ,
V_74 , V_71 , NULL , 0x0 , NULL , V_72 } } ,
{ & V_23 ,
{ L_32 , L_33 ,
V_74 , V_71 , NULL , 0x0 , NULL , V_72 } } ,
{ & V_25 ,
{ L_34 , L_35 ,
V_76 , V_71 , NULL , 0x0 , NULL , V_72 } } ,
{ & V_26 ,
{ L_36 , L_37 ,
V_70 , V_71 , F_23 ( V_80 ) , 0x80 , NULL , V_72 } } ,
{ & V_29 ,
{ L_38 , L_39 ,
V_70 , V_71 , F_23 ( V_81 ) , 0x0 , NULL , V_72 } } ,
{ & V_27 ,
{ L_40 , L_41 ,
V_70 , V_71 , F_23 ( V_82 ) , 0x70 , NULL , V_72 } } ,
{ & V_28 ,
{ L_38 , L_42 ,
V_70 , V_71 , F_23 ( V_83 ) , 0x0F , NULL , V_72 } } ,
{ & V_39 ,
{ L_43 , L_44 ,
V_76 , V_71 , NULL , 0x0 , NULL , V_72 } } ,
{ & V_35 ,
{ L_45 , L_46 ,
V_74 , V_71 , NULL , 0x0 , NULL , V_72 } } ,
{ & V_37 ,
{ L_47 , L_48 ,
V_76 , V_71 , NULL , 0x0 , NULL , V_72 } } ,
} ;
static T_11 * V_84 [] = {
& V_49 ,
& V_16
} ;
V_48 = F_24 (
L_49 ,
L_50 ,
L_51
) ;
F_25 ( V_48 , V_69 , F_26 ( V_69 ) ) ;
F_27 ( V_84 , F_26 ( V_84 ) ) ;
V_68 = F_28 ( V_48 , V_85 ) ;
F_29 ( V_68 , L_52 , L_53 , L_54 , 10 , & V_86 ) ;
}
void V_85 ( void )
{
static T_12 V_87 ;
static int V_88 ;
static T_13 V_89 = FALSE ;
if ( ! V_89 )
{
V_38 = F_30 ( L_55 ) ;
V_87 = F_31 ( F_20 , V_48 ) ;
F_32 ( L_52 , V_87 ) ;
V_89 = TRUE ;
}
else
{
if ( V_88 != 0 )
F_33 ( L_52 , V_88 , V_87 ) ;
}
V_88 = V_86 ;
if ( V_88 != 0 )
F_34 ( L_52 , V_88 , V_87 ) ;
}
