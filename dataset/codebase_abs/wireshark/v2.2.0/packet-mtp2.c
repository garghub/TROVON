static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 )
{
if ( V_2 ) {
if ( V_3 ) {
F_2 ( V_2 , V_4 , V_1 , V_5 , V_6 , V_7 ) ;
F_2 ( V_2 , V_8 , V_1 , V_5 , V_6 , V_7 ) ;
F_2 ( V_2 , V_9 , V_1 , V_5 , V_6 , V_7 ) ;
F_2 ( V_2 , V_10 , V_1 , V_11 , V_12 , V_7 ) ;
F_2 ( V_2 , V_8 , V_1 , V_5 , V_6 , V_7 ) ;
F_2 ( V_2 , V_13 , V_1 , V_11 , V_12 , V_7 ) ;
F_2 ( V_2 , V_14 , V_1 , V_15 , V_16 , V_7 ) ;
F_2 ( V_2 , V_17 , V_1 , V_15 , V_16 , V_7 ) ;
} else {
F_2 ( V_2 , V_18 , V_1 , V_19 , V_20 , V_7 ) ;
F_2 ( V_2 , V_21 , V_1 , V_19 , V_20 , V_7 ) ;
F_2 ( V_2 , V_22 , V_1 , V_23 , V_24 , V_7 ) ;
F_2 ( V_2 , V_25 , V_1 , V_23 , V_24 , V_7 ) ;
F_2 ( V_2 , V_26 , V_1 , V_27 , V_28 , V_7 ) ;
F_2 ( V_2 , V_29 , V_1 , V_27 , V_28 , V_7 ) ;
}
}
}
static T_4
F_3 ( T_1 * V_30 )
{
T_5 V_31 = F_4 ( V_30 ) - 2 ;
if ( V_31 == 0 )
return ( 0x0000 ) ;
return F_5 ( V_30 , V_31 ) ;
}
static T_1 *
F_6 ( T_1 * V_32 , T_6 * V_33 , T_7 * V_34 )
{
T_1 * V_35 ;
T_8 V_31 , V_36 ;
int V_37 = 0 ;
V_31 = F_7 ( V_32 , V_37 ) ;
V_36 = F_7 ( V_32 , V_37 ) ;
if ( V_36 < 2 || V_31 < 0 ) {
V_35 = F_8 ( V_32 , V_37 ) ;
} else if ( V_31 < V_36 ) {
V_36 -= 2 ;
if ( V_31 > V_36 )
V_31 = V_36 ;
V_35 = F_9 ( V_32 , V_37 , V_31 , V_36 ) ;
} else {
V_31 -= 2 ;
V_36 -= 2 ;
V_35 = F_9 ( V_32 , V_37 , V_31 , V_36 ) ;
F_10 ( V_33 , V_32 , V_37 + V_31 , V_38 , - 1 , & V_39 , V_34 , F_3 ( V_32 ) ,
V_40 , V_41 ) ;
}
return V_35 ;
}
static void
F_11 ( T_7 * V_34 )
{
F_12 ( V_34 -> V_42 , V_43 , L_1 ) ;
}
static void
F_13 ( T_1 * V_1 , T_7 * V_34 , T_2 * V_2 ,
T_3 V_3 )
{
T_9 V_44 = 0xFF ;
T_9 V_45 , V_46 ;
if ( V_3 ) {
V_45 = V_47 ;
V_46 = V_48 ;
} else {
V_45 = V_49 ;
V_46 = V_50 ;
}
F_2 ( V_2 , V_51 , V_1 , V_45 , V_52 , V_7 ) ;
V_44 = F_14 ( V_1 , V_49 ) ;
if ( ( F_14 ( V_1 , V_27 ) & V_53 ) == 2 )
F_2 ( V_2 , V_54 , V_1 , V_46 , V_55 , V_7 ) ;
F_12 ( V_34 -> V_42 , V_43 , F_15 ( V_44 , V_56 , L_2 ) ) ;
}
static void
F_16 ( T_1 * V_1 , T_7 * V_34 , T_2 * V_57 ,
T_2 * V_58 , T_3 V_3 )
{
T_8 V_59 ;
T_1 * V_60 ;
F_12 ( V_34 -> V_42 , V_43 , L_3 ) ;
if ( V_3 ) {
V_59 = F_4 ( V_1 ) - V_61 ;
V_60 = F_17 ( V_1 , V_62 , V_59 ) ;
} else {
V_59 = F_4 ( V_1 ) - V_63 ;
V_60 = F_17 ( V_1 , V_64 , V_59 ) ;
}
F_18 ( V_65 , V_60 , V_34 , V_58 ) ;
if ( V_58 ) {
if ( V_3 )
F_19 ( V_57 , V_61 ) ;
else
F_19 ( V_57 , V_63 ) ;
}
}
static void
F_20 ( T_1 * V_1 , T_7 * V_34 , T_2 * V_57 ,
T_2 * V_2 , T_6 * V_58 , T_3 V_66 ,
T_3 V_3 )
{
T_4 V_67 ;
T_1 * V_35 = NULL ;
F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_66 )
V_35 = F_6 ( V_1 , V_2 , V_34 ) ;
if ( V_3 )
V_67 = F_21 ( V_1 , V_15 ) & V_68 ;
else
V_67 = F_14 ( V_1 , V_27 ) & V_53 ;
switch( V_67 ) {
case 0 :
F_11 ( V_34 ) ;
break;
case 1 :
case 2 :
if ( V_66 )
F_13 ( V_35 , V_34 , V_2 , V_3 ) ;
else
F_13 ( V_1 , V_34 , V_2 , V_3 ) ;
break;
default:
if ( V_66 )
F_16 ( V_35 , V_34 , V_57 , V_58 , V_3 ) ;
else
F_16 ( V_1 , V_34 , V_57 , V_58 , V_3 ) ;
break;
}
}
static void
F_22 ( T_1 * V_32 , T_7 * V_34 , T_6 * V_58 ,
T_3 V_66 , T_3 V_3 )
{
T_2 * V_57 ;
T_6 * V_2 ;
F_12 ( V_34 -> V_42 , V_69 , L_4 ) ;
V_57 = F_2 ( V_58 , V_70 , V_32 , 0 , - 1 , V_71 ) ;
V_2 = F_23 ( V_57 , V_72 ) ;
F_20 ( V_32 , V_34 , V_57 , V_2 , V_58 , V_66 ,
V_3 ) ;
}
static int
F_24 ( T_1 * V_32 , T_7 * V_34 , T_6 * V_58 , void * T_10 V_73 )
{
if ( V_34 -> V_74 -> V_75 . V_76 == V_77 )
F_22 ( V_32 , V_34 , V_58 , FALSE , V_78 ) ;
else
F_22 ( V_32 , V_34 , V_58 , FALSE ,
( V_34 -> V_74 -> V_75 . V_76 == V_79 ) ) ;
return F_25 ( V_32 ) ;
}
static int
F_26 ( T_1 * V_32 , T_7 * V_34 , T_6 * V_58 , void * T_10 V_73 )
{
F_22 ( V_32 , V_34 , V_58 , TRUE , V_78 ) ;
return F_25 ( V_32 ) ;
}
static int
F_27 ( T_1 * V_32 , T_7 * V_34 , T_6 * V_58 , void * T_10 V_73 )
{
F_22 ( V_32 , V_34 , V_58 , FALSE , V_78 ) ;
return F_25 ( V_32 ) ;
}
void
F_28 ( void )
{
static T_11 V_80 [] = {
{ & V_18 , { L_5 , L_6 , V_81 , V_82 , NULL , V_83 , NULL , V_84 } } ,
{ & V_4 , { L_5 , L_6 , V_85 , V_82 , NULL , V_86 , NULL , V_84 } } ,
{ & V_8 , { L_7 , L_8 , V_85 , V_82 , NULL , V_87 , NULL , V_84 } } ,
{ & V_21 , { L_9 , L_10 , V_81 , V_82 , NULL , V_88 , NULL , V_84 } } ,
{ & V_9 , { L_9 , L_10 , V_85 , V_82 , NULL , V_89 , NULL , V_84 } } ,
{ & V_22 , { L_11 , L_12 , V_81 , V_82 , NULL , V_90 , NULL , V_84 } } ,
{ & V_10 , { L_11 , L_12 , V_85 , V_82 , NULL , V_91 , NULL , V_84 } } ,
{ & V_25 , { L_13 , L_14 , V_81 , V_82 , NULL , V_92 , NULL , V_84 } } ,
{ & V_13 , { L_13 , L_14 , V_85 , V_82 , NULL , V_93 , NULL , V_84 } } ,
{ & V_26 , { L_15 , L_16 , V_81 , V_82 , NULL , V_53 , NULL , V_84 } } ,
{ & V_14 , { L_15 , L_16 , V_85 , V_82 , NULL , V_68 , NULL , V_84 } } ,
{ & V_29 , { L_17 , L_18 , V_81 , V_82 , NULL , V_94 , NULL , V_84 } } ,
{ & V_17 , { L_17 , L_18 , V_85 , V_82 , NULL , V_95 , NULL , V_84 } } ,
{ & V_51 , { L_19 , L_20 , V_81 , V_82 , F_29 ( V_96 ) , 0x0 , NULL , V_84 } } ,
{ & V_54 , { L_21 , L_22 , V_81 , V_97 , NULL , 0x0 , NULL , V_84 } } ,
{ & V_38 , { L_23 , L_24 , V_85 , V_97 , NULL , 0x0 , NULL , V_84 } } ,
} ;
static T_8 * V_98 [] = {
& V_72
} ;
static T_12 V_99 [] = {
{ & V_39 , { L_25 , V_100 , V_101 , L_26 , V_102 } } ,
} ;
T_13 * V_103 ;
T_14 * V_104 ;
V_70 = F_30 ( L_27 , L_4 , L_28 ) ;
V_105 = F_31 ( L_28 , F_27 , V_70 ) ;
F_31 ( L_29 , F_26 , V_70 ) ;
F_32 ( V_70 , V_80 , F_33 ( V_80 ) ) ;
F_34 ( V_98 , F_33 ( V_98 ) ) ;
V_104 = F_35 ( V_70 ) ;
F_36 ( V_104 , V_99 , F_33 ( V_99 ) ) ;
V_103 = F_37 ( V_70 , NULL ) ;
F_38 ( V_103 ,
L_30 ,
L_31 ,
L_32 ,
& V_78 ) ;
}
void
F_39 ( void )
{
T_15 V_106 ;
F_40 ( L_33 , V_107 , V_105 ) ;
V_106 = F_41 ( F_24 ,
V_70 ) ;
F_40 ( L_33 , V_108 ,
V_106 ) ;
V_65 = F_42 ( L_34 , V_70 ) ;
}
