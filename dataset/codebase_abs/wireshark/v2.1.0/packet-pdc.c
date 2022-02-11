static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 , T_4 V_4 )
{
T_5 V_5 ;
T_4 V_6 ;
T_6 * V_7 ;
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
V_7 = F_2 ( V_8 , V_17 , V_1 , V_3 + V_5 , 1 , V_11 ) ;
V_9 = F_3 ( V_7 , V_16 ) ;
V_5 += 1 ;
switch ( V_6 )
{
case V_18 :
F_2 ( V_9 , V_19 , V_1 , V_3 + V_5 , 1 , V_11 ) ;
F_2 ( V_9 , V_20 , V_1 , V_3 + V_5 + 1 , 1 , V_11 ) ;
V_5 += 2 ;
break;
case V_21 :
F_2 ( V_9 , V_19 , V_1 , V_3 + V_5 , 1 , V_11 ) ;
F_2 ( V_9 , V_22 , V_1 , V_3 + V_5 + 1 , 2 , V_11 ) ;
F_2 ( V_9 , V_23 , V_1 , V_3 + V_5 + 3 , 2 , V_11 ) ;
V_5 += 5 ;
break;
case V_24 :
F_2 ( V_9 , V_19 , V_1 , V_3 + V_5 , 1 , V_11 ) ;
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
F_2 ( V_2 , V_26 , V_1 , V_3 , 1 , V_11 ) ;
F_2 ( V_2 , V_27 , V_1 , V_3 , 1 , V_11 ) ;
F_2 ( V_2 , V_28 , V_1 , V_3 , 1 , V_11 ) ;
F_2 ( V_2 , V_29 , V_1 , V_3 + 1 , 1 , V_11 ) ;
return ( 2 ) ;
}
static int F_7 ( T_1 * V_1 , T_2 * V_30 , T_2 * V_2 , T_3 V_3 , T_7 * V_31 )
{
T_3 V_32 ;
T_3 V_33 ;
T_1 * V_34 ;
F_2 ( V_2 , V_35 , V_1 , V_3 , 4 , V_11 ) ;
V_3 += 4 ;
F_2 ( V_2 , V_36 , V_1 , V_3 , 2 , V_11 ) ;
V_32 = F_8 ( V_1 , V_3 ) ;
V_3 += 2 ;
V_33 = V_32 + 6 ;
V_34 = F_9 ( V_1 , V_3 , V_32 ) ;
if ( V_37 != NULL )
F_10 ( V_37 , V_34 , V_31 , V_30 ) ;
return ( V_33 ) ;
}
static int F_7 ( T_1 * V_1 , T_2 * V_30 V_38 , T_2 * V_2 , T_3 V_3 , T_7 * V_31 V_38 )
{
F_2 ( V_2 , V_35 , V_1 , V_3 , 4 , V_11 ) ;
return ( 2 ) ;
}
static int F_11 ( T_1 * V_1 , T_2 * V_30 , T_2 * V_2 , T_3 V_3 , T_7 * V_31 )
{
T_3 V_32 ;
T_3 V_33 ;
T_1 * V_34 ;
F_2 ( V_2 , V_39 , V_1 , V_3 , 2 , V_11 ) ;
V_32 = F_8 ( V_1 , 2 ) ;
V_33 = V_32 + 2 ;
V_34 = F_9 ( V_1 , V_3 + 2 , V_32 ) ;
if ( V_37 != NULL )
F_10 ( V_37 , V_34 , V_31 , V_30 ) ;
return ( V_33 ) ;
}
static int F_11 ( T_1 * V_1 V_38 , T_2 * V_30 V_38 , T_2 * V_2 V_38 , T_3 V_3 V_38 , T_7 * V_31 V_38 )
{
return ( 2 ) ;
}
static int F_12 ( T_1 * V_1 , T_2 * V_30 , T_2 * V_2 , T_3 V_3 , T_7 * V_31 )
{
T_3 V_32 ;
T_3 V_33 ;
T_1 * V_34 ;
F_2 ( V_2 , V_39 , V_1 , V_3 , 2 , V_11 ) ;
V_32 = F_8 ( V_1 , 2 ) ;
V_33 = V_32 + 2 ;
V_34 = F_9 ( V_1 , V_3 + 2 , V_32 ) ;
if ( V_37 != NULL )
F_10 ( V_37 , V_34 , V_31 , V_30 ) ;
return ( V_33 ) ;
}
static int F_12 ( T_1 * V_1 V_38 , T_2 * V_30 V_38 , T_2 * V_2 V_38 , T_3 V_3 V_38 , T_7 * V_31 V_38 )
{
return 2 ;
}
static int F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 )
{
F_2 ( V_2 , V_40 , V_1 , V_3 , 2 , V_11 ) ;
F_2 ( V_2 , V_41 , V_1 , V_3 , 2 , V_11 ) ;
F_2 ( V_2 , V_13 , V_1 , V_3 + 2 , 4 , V_11 ) ;
return ( 6 ) ;
}
static int F_14 ( T_1 * V_1 , T_2 * V_2 , T_7 * V_31 )
{
T_8 V_42 = 0 ;
T_4 V_43 ;
T_4 V_44 ;
T_3 V_45 ;
T_6 * V_46 ;
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
static int F_16 ( T_1 * V_1 , T_7 * V_31 , T_2 * V_2 , void * T_9 V_38 )
{
F_15 ( V_31 -> V_53 , V_61 , V_62 ) ;
F_17 ( V_31 -> V_53 , V_54 ) ;
F_14 ( V_1 , V_2 , V_31 ) ;
return F_18 ( V_1 ) ;
}
static T_8 F_19 ( T_7 * V_31 V_38 , T_1 * V_1 ,
int V_3 , void * T_9 V_38 )
{
T_8 V_63 ;
T_8 V_64 ;
T_4 V_65 ;
V_65 = F_4 ( V_1 , V_3 + 1 ) ;
switch ( V_65 )
{
case V_52 :
V_63 = F_4 ( V_1 , V_3 ) ;
V_64 = 1 ;
break;
case V_55 :
V_63 = F_4 ( V_1 , V_3 ) ;
V_64 = 1 ;
break;
case V_56 :
V_63 = F_4 ( V_1 , V_3 ) ;
V_64 = 1 ;
break;
case V_57 :
V_63 = F_8 ( V_1 , V_3 + 2 ) ;
V_64 = 4 ;
break;
case V_58 :
V_63 = F_8 ( V_1 , V_3 + 6 ) ;
V_64 = 8 ;
break;
case V_59 :
V_63 = F_4 ( V_1 , V_3 ) ;
V_64 = 1 ;
break;
case V_60 :
V_63 = F_4 ( V_1 , V_3 ) + 1 ;
V_64 = 0 ;
break;
default:
V_63 = 0 ;
V_64 = 0 ;
}
return V_63 + V_64 ;
}
static int F_20 ( T_1 * V_1 , T_7 * V_31 , T_2 * V_2 , void * T_9 V_38 )
{
T_4 V_65 ;
T_4 V_66 ;
V_65 = F_4 ( V_1 , 1 ) ;
switch ( V_65 )
{
case V_52 :
V_66 = 2 ;
break;
case V_55 :
V_66 = 2 ;
break;
case V_56 :
V_66 = 2 ;
break;
case V_57 :
V_66 = 4 ;
break;
case V_58 :
V_66 = 8 ;
break;
case V_59 :
V_66 = 2 ;
break;
case V_60 :
V_66 = 2 ;
break;
default:
V_66 = 2 ;
break;
}
F_21 ( V_1 , V_31 , V_2 , TRUE , V_66 , F_19 , F_16 , NULL ) ;
return F_22 ( V_1 ) ;
}
void F_23 ( void )
{
T_10 * V_67 ;
static T_11 V_68 [] =
{
{ & V_50 ,
{ L_8 , L_9 ,
V_69 , V_70 , NULL , 0x0 , NULL , V_71 } } ,
{ & V_51 ,
{ L_10 , L_11 ,
V_69 , V_70 , F_24 ( V_72 ) , 0x0 , NULL , V_71 } } ,
{ & V_10 ,
{ L_12 , L_13 ,
V_69 , V_70 , NULL , 0x0 , NULL , V_71 } } ,
{ & V_13 ,
{ L_14 , L_15 ,
V_73 , V_70 , NULL , 0x0 , NULL , V_71 } } ,
{ & V_12 ,
{ L_16 , L_17 ,
V_69 , V_70 , F_24 ( V_74 ) , 0x0 , NULL , V_71 } } ,
{ & V_40 ,
{ L_18 , L_19 ,
V_75 , V_70 , NULL , 0x8000 , NULL , V_71 } } ,
{ & V_41 ,
{ L_20 , L_21 ,
V_75 , V_70 , NULL , 0x07FF , NULL , V_71 } } ,
{ & V_14 ,
{ L_22 , L_23 ,
V_76 , V_77 , NULL , 0x0 , NULL , V_71 } } ,
{ & V_17 ,
{ L_24 , L_25 ,
V_69 , V_70 , F_24 ( V_78 ) , 0x0 , NULL , V_71 } } ,
{ & V_19 ,
{ L_26 , L_27 ,
V_69 , V_70 , NULL , 0x0 , NULL , V_71 } } ,
{ & V_20 ,
{ L_28 , L_29 ,
V_69 , V_70 , NULL , 0x0 , NULL , V_71 } } ,
{ & V_22 ,
{ L_30 , L_31 ,
V_73 , V_70 , NULL , 0x0 , NULL , V_71 } } ,
{ & V_23 ,
{ L_32 , L_33 ,
V_73 , V_70 , NULL , 0x0 , NULL , V_71 } } ,
{ & V_25 ,
{ L_34 , L_35 ,
V_75 , V_70 , NULL , 0x0 , NULL , V_71 } } ,
{ & V_26 ,
{ L_36 , L_37 ,
V_69 , V_70 , F_24 ( V_79 ) , 0x80 , NULL , V_71 } } ,
{ & V_29 ,
{ L_38 , L_39 ,
V_69 , V_70 , F_24 ( V_80 ) , 0x0 , NULL , V_71 } } ,
{ & V_27 ,
{ L_40 , L_41 ,
V_69 , V_70 , F_24 ( V_81 ) , 0x70 , NULL , V_71 } } ,
{ & V_28 ,
{ L_38 , L_42 ,
V_69 , V_70 , F_24 ( V_82 ) , 0x0F , NULL , V_71 } } ,
{ & V_39 ,
{ L_43 , L_44 ,
V_75 , V_70 , NULL , 0x0 , NULL , V_71 } } ,
{ & V_35 ,
{ L_45 , L_46 ,
V_73 , V_70 , NULL , 0x0 , NULL , V_71 } } ,
{ & V_36 ,
{ L_47 , L_48 ,
V_75 , V_70 , NULL , 0x0 , NULL , V_71 } } ,
} ;
static T_5 * V_83 [] = {
& V_49 ,
& V_16
} ;
V_48 = F_25 (
L_49 ,
L_50 ,
L_51
) ;
F_26 ( V_48 , V_68 , F_27 ( V_68 ) ) ;
F_28 ( V_83 , F_27 ( V_83 ) ) ;
V_67 = F_29 ( V_48 , V_84 ) ;
F_30 ( V_67 , L_52 , L_53 , L_54 , 10 , & V_85 ) ;
}
void V_84 ( void )
{
static T_12 V_86 ;
static int V_87 ;
static T_13 V_88 = FALSE ;
if ( ! V_88 )
{
V_37 = F_31 ( L_55 , V_48 ) ;
V_86 = F_32 ( F_20 , V_48 ) ;
F_33 ( L_52 , V_86 ) ;
V_88 = TRUE ;
}
else
{
if ( V_87 != 0 )
F_34 ( L_52 , V_87 , V_86 ) ;
}
V_87 = V_85 ;
if ( V_87 != 0 )
F_35 ( L_52 , V_87 , V_86 ) ;
}
