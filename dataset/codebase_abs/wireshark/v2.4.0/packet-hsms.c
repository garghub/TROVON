static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 , int * V_5 )
{
T_4 * V_6 ;
T_3 * V_7 , * V_8 ;
T_4 * V_9 = NULL ;
T_5 V_10 = - 1 ;
T_5 V_11 = - 1 ;
T_5 V_12 = 0 ;
T_5 * V_13 = NULL ;
int V_14 = 0 ;
int V_15 = 0 ;
V_10 = ( F_2 ( V_1 , * V_5 ) & 0xFC ) >> 2 ;
V_11 = ( F_2 ( V_1 , * V_5 ) & 0x3 ) ;
switch ( V_11 )
{
case 3 :
V_12 = F_3 ( V_1 , * V_5 + 1 ) ;
break;
case 2 :
V_12 = F_4 ( V_1 , * V_5 + 1 ) ;
break;
case 1 :
V_12 = F_2 ( V_1 , * V_5 + 1 ) ;
break;
default:
return - 1 ;
}
if ( V_10 != 0 )
{
V_13 = ( T_5 * ) F_5 ( V_16 , F_6 ( V_10 ) ) ;
if ( V_12 % F_7 ( V_13 ) != 0 )
return - 1 ;
V_12 = V_12 / F_7 ( V_13 ) ;
}
V_7 = F_8 ( V_3 , V_1 , * V_5 , - 1 , V_17 , & V_9 , L_1 , F_9 ( V_10 , V_18 , L_2 ) , V_12 ) ;
V_8 = F_8 ( V_7 , V_1 , * V_5 , 1 , V_19 , & V_6 , L_3 , F_9 ( V_10 , V_18 , L_2 ) , V_11 ) ;
F_10 ( V_8 , V_20 , V_1 , * V_5 , 1 , V_21 ) ;
F_10 ( V_8 , V_22 , V_1 , * V_5 , 1 , V_21 ) ;
* V_5 += 1 ;
V_14 = V_11 ;
F_10 ( V_7 , V_23 , V_1 , * V_5 , V_14 , V_21 ) ;
* V_5 += V_14 ;
switch( V_10 )
{
case V_24 :
V_13 = ( T_5 * ) F_5 ( V_16 , F_6 ( V_10 ) ) ;
V_14 = F_7 ( V_13 ) * V_12 ;
F_10 ( V_7 , V_25 , V_1 , * V_5 , V_14 , V_26 ) ;
V_15 = V_14 ;
* V_5 += V_14 ;
break;
case V_27 :
V_13 = ( T_5 * ) F_5 ( V_16 , F_6 ( V_10 ) ) ;
V_14 = F_7 ( V_13 ) * V_12 ;
F_10 ( V_7 , V_28 , V_1 , * V_5 , V_14 , V_29 | V_26 ) ;
V_15 = V_14 ;
* V_5 += V_14 ;
break;
default:
for( unsigned int V_30 = 0 ; V_30 < V_12 ; V_30 ++ )
{
if ( V_10 == 0 )
{
int V_31 = F_1 ( V_1 , V_2 , V_7 , V_4 , V_5 ) ;
if ( V_31 == - 1 )
{
return - 1 ;
}
V_15 += V_31 ;
}
else
{
V_13 = ( T_5 * ) F_5 ( V_16 , F_6 ( V_10 ) ) ;
V_14 = F_7 ( V_13 ) ;
switch( V_10 )
{
case V_32 :
F_10 ( V_7 , V_33 , V_1 , * V_5 , V_14 , V_21 ) ;
break;
case V_34 :
F_10 ( V_7 , V_35 , V_1 , * V_5 , V_14 , V_21 ) ;
break;
case V_36 :
F_10 ( V_7 , V_37 , V_1 , * V_5 , V_14 , V_21 ) ;
break;
case V_38 :
F_10 ( V_7 , V_39 , V_1 , * V_5 , V_14 , V_21 ) ;
break;
case V_40 :
F_10 ( V_7 , V_41 , V_1 , * V_5 , V_14 , V_21 ) ;
break;
case V_42 :
F_10 ( V_7 , V_43 , V_1 , * V_5 , V_14 , V_21 ) ;
break;
case V_44 :
F_10 ( V_7 , V_45 , V_1 , * V_5 , V_14 , V_21 ) ;
break;
case V_46 :
F_10 ( V_7 , V_47 , V_1 , * V_5 , V_14 , V_21 ) ;
break;
case V_48 :
F_10 ( V_7 , V_49 , V_1 , * V_5 , V_14 , V_21 ) ;
break;
case V_50 :
F_10 ( V_7 , V_51 , V_1 , * V_5 , V_14 , V_21 ) ;
break;
case V_52 :
F_10 ( V_7 , V_53 , V_1 , * V_5 , V_14 , V_21 ) ;
break;
default:
return - 1 ;
}
V_15 += V_14 ;
* V_5 += V_14 ;
}
}
}
F_11 ( V_7 , V_15 + V_11 + 1 ) ;
return 1 + V_11 + V_15 ;
}
static int
F_12 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 , int * V_5 )
{
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
}
static int
F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 )
{
T_4 * V_9 = NULL ;
T_4 * V_54 ;
T_3 * V_55 , * V_56 , * V_57 ;
T_5 V_5 = 0 ;
T_5 V_58 = - 1 ;
T_5 V_59 = - 1 ;
T_5 V_60 = - 1 ;
T_5 V_61 = - 1 ;
T_5 V_62 = - 1 ;
if ( F_14 ( V_1 ) < V_63 )
return 0 ;
if ( ( F_15 ( V_1 , 0 ) + 4 ) != F_14 ( V_1 ) )
return 0 ;
V_58 = F_4 ( V_1 , 4 ) ;
V_59 = F_2 ( V_1 , 6 ) ;
V_60 = F_2 ( V_1 , 7 ) ;
V_61 = F_2 ( V_1 , 8 ) ;
V_62 = F_2 ( V_1 , 9 ) ;
if ( ( V_62 == 8 ) || ( V_62 == 10 ) || ( V_62 > 127 ) )
return 0 ;
switch ( V_62 )
{
case V_64 :
if ( V_59 == 0 )
return 0 ;
break;
case V_65 :
case V_66 :
case V_67 :
if ( ( V_59 != 0 ) || ( V_60 != 0 ) )
return 0 ;
if ( F_14 ( V_1 ) > V_63 )
return 0 ;
break;
case V_68 :
case V_69 :
if ( V_59 != 0 )
return 0 ;
if ( F_14 ( V_1 ) > V_63 )
return 0 ;
break;
case V_70 :
case V_71 :
if ( V_58 != 0xFFFF )
return 0 ;
if ( V_59 != 0 )
return 0 ;
if ( V_60 != 0 )
return 0 ;
if ( F_14 ( V_1 ) > V_63 )
return 0 ;
break;
case V_72 :
if ( F_14 ( V_1 ) > V_63 )
return 0 ;
break;
}
F_16 ( V_2 -> V_73 , V_74 , L_4 ) ;
F_17 ( V_2 -> V_73 , V_75 ) ;
if ( V_62 == V_64 )
{
F_18 ( V_2 -> V_73 , V_75 , L_5 ,
V_59 & 0x7F , V_60 ) ;
}
else
{
F_18 ( V_2 -> V_73 , V_75 , L_6 ,
F_9 ( V_62 , V_76 , L_7 ) ) ;
}
V_54 = F_10 ( V_3 , V_77 , V_1 , 0 , - 1 , V_26 ) ;
V_55 = F_19 ( V_54 , V_78 ) ;
F_10 ( V_55 , V_79 , V_1 , V_5 , 4 , V_21 ) ;
V_5 += 4 ;
switch ( V_62 )
{
case V_64 :
V_56 = F_8 ( V_55 , V_1 , V_5 , 10 , V_19 , & V_9 , L_8 , V_59 & 0x7F , V_60 ) ;
break;
default:
V_56 = F_8 ( V_55 , V_1 , V_5 , 10 , V_19 , & V_9 , L_9 , F_9 ( V_62 , V_76 , L_7 ) ) ;
break;
}
F_10 ( V_56 , V_80 , V_1 , V_5 , 2 , V_21 ) ;
V_5 += 2 ;
switch ( V_62 )
{
case V_64 :
V_57 = F_8 ( V_56 , V_1 , V_5 , 1 , V_19 , & V_9 , L_10 , V_59 & 0x7F , ( ( V_59 & 0x80 ) > 0 ) ? L_11 : L_12 ) ;
F_10 ( V_57 , V_81 , V_1 , V_5 , 1 , V_21 ) ;
F_10 ( V_57 , V_82 , V_1 , V_5 , 1 , V_21 ) ;
V_5 += 1 ;
F_10 ( V_56 , V_83 , V_1 , V_5 , 1 , V_21 ) ;
V_5 += 1 ;
break;
default:
F_10 ( V_56 , V_84 , V_1 , V_5 , 1 , V_21 ) ;
V_5 += 1 ;
F_10 ( V_56 , V_85 , V_1 , V_5 , 1 , V_21 ) ;
V_5 += 1 ;
break;
}
V_54 = F_10 ( V_56 , V_86 , V_1 , V_5 , 1 , V_21 ) ;
V_5 += 1 ;
if ( V_61 != 0 )
F_20 ( V_2 , V_54 , & V_87 ) ;
F_10 ( V_56 , V_88 , V_1 , V_5 , 1 , V_21 ) ;
V_5 += 1 ;
F_10 ( V_56 , V_89 , V_1 , V_5 , 4 , V_21 ) ;
V_5 += 4 ;
if ( F_14 ( V_1 ) > V_63 )
{
if ( V_61 == V_90 )
F_12 ( V_1 , V_2 , V_55 , V_4 , & V_5 ) ;
}
return V_5 ;
}
static T_5
F_21 ( T_2 * V_2 V_91 , T_1 * V_1 , int V_5 , void * V_4 V_91 )
{
return ( T_5 ) F_15 ( V_1 , V_5 ) + 4 ;
}
static int
F_22 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 )
{
F_23 ( V_1 , V_2 , V_3 , TRUE , 4 ,
F_21 , F_13 , V_4 ) ;
return F_24 ( V_1 ) ;
}
static void
F_25 ( void )
{
V_16 = F_26 ( F_27 () , V_92 , V_93 ) ;
F_28 ( V_16 , F_29 ( V_94 ) , F_29 ( 0 ) ) ;
F_28 ( V_16 , F_29 ( V_24 ) , F_29 ( 1 ) ) ;
F_28 ( V_16 , F_29 ( V_32 ) , F_29 ( 1 ) ) ;
F_28 ( V_16 , F_29 ( V_27 ) , F_29 ( 1 ) ) ;
F_28 ( V_16 , F_29 ( V_95 ) , F_29 ( 2 ) ) ;
F_28 ( V_16 , F_29 ( V_96 ) , F_29 ( 2 ) ) ;
F_28 ( V_16 , F_29 ( V_34 ) , F_29 ( 8 ) ) ;
F_28 ( V_16 , F_29 ( V_36 ) , F_29 ( 1 ) ) ;
F_28 ( V_16 , F_29 ( V_38 ) , F_29 ( 2 ) ) ;
F_28 ( V_16 , F_29 ( V_40 ) , F_29 ( 4 ) ) ;
F_28 ( V_16 , F_29 ( V_42 ) , F_29 ( 8 ) ) ;
F_28 ( V_16 , F_29 ( V_44 ) , F_29 ( 4 ) ) ;
F_28 ( V_16 , F_29 ( V_46 ) , F_29 ( 8 ) ) ;
F_28 ( V_16 , F_29 ( V_48 ) , F_29 ( 1 ) ) ;
F_28 ( V_16 , F_29 ( V_50 ) , F_29 ( 2 ) ) ;
F_28 ( V_16 , F_29 ( V_52 ) , F_29 ( 4 ) ) ;
}
void
F_30 ( void )
{
T_6 * V_97 ;
static T_7 V_98 [] = {
{ & V_79 ,
{ L_13 , L_14 ,
V_99 , V_100 ,
NULL , 0x0 ,
NULL , V_101 }
} ,
{ & V_80 ,
{ L_15 , L_16 ,
V_102 , V_100 ,
NULL , 0x0 ,
NULL , V_101 }
} ,
{ & V_84 ,
{ L_17 , L_18 ,
V_103 , V_100 ,
NULL , 0x0 ,
NULL , V_101 }
} ,
{ & V_81 ,
{ L_19 , L_20 ,
V_104 , 8 ,
NULL , 0x80 ,
NULL , V_101 }
} ,
{ & V_82 ,
{ L_21 , L_22 ,
V_103 , V_100 ,
NULL , 0x7F ,
NULL , V_101 }
} ,
{ & V_85 ,
{ L_23 , L_24 ,
V_103 , V_100 ,
NULL , 0x0 ,
NULL , V_101 }
} ,
{ & V_83 ,
{ L_25 , L_26 ,
V_103 , V_100 ,
NULL , 0x0 ,
NULL , V_101 }
} ,
{ & V_86 ,
{ L_27 , L_28 ,
V_103 , V_100 ,
F_31 ( V_105 ) , 0x0 ,
NULL , V_101 }
} ,
{ & V_88 ,
{ L_29 , L_30 ,
V_103 , V_100 ,
F_31 ( V_76 ) , 0x0 ,
NULL , V_101 }
} ,
{ & V_89 ,
{ L_31 , L_32 ,
V_99 , V_100 ,
NULL , 0x0 ,
NULL , V_101 }
} ,
{ & V_20 ,
{ L_33 , L_34 ,
V_103 , V_106 ,
F_31 ( V_18 ) , 0xFC ,
NULL , V_101 }
} ,
{ & V_22 ,
{ L_35 , L_36 ,
V_103 , V_106 ,
NULL , 0x03 ,
NULL , V_101 }
} ,
{ & V_23 ,
{ L_37 , L_38 ,
V_99 , V_100 ,
NULL , 0x00 ,
NULL , V_101 }
} ,
{ & V_25 ,
{ L_39 , L_40 ,
V_107 , V_108 ,
NULL , 0x00 ,
NULL , V_101 }
} ,
{ & V_33 ,
{ L_39 , L_41 ,
V_104 , 8 ,
NULL , 0x01 ,
NULL , V_101 }
} ,
{ & V_28 ,
{ L_39 , L_42 ,
V_109 , V_110 ,
NULL , 0x00 ,
NULL , V_101 }
} ,
{ & V_35 ,
{ L_39 , L_43 ,
V_111 , V_100 ,
NULL , 0x00 ,
NULL , V_101 }
} ,
{ & V_37 ,
{ L_39 , L_44 ,
V_112 , V_100 ,
NULL , 0x00 ,
NULL , V_101 }
} ,
{ & V_39 ,
{ L_39 , L_45 ,
V_113 , V_100 ,
NULL , 0x00 ,
NULL , V_101 }
} ,
{ & V_41 ,
{ L_39 , L_46 ,
V_114 , V_100 ,
NULL , 0x00 ,
NULL , V_101 }
} ,
{ & V_43 ,
{ L_39 , L_47 ,
V_115 , V_110 ,
NULL , 0x00 ,
NULL , V_101 }
} ,
{ & V_45 ,
{ L_39 , L_48 ,
V_116 , V_110 ,
NULL , 0x00 ,
NULL , V_101 }
} ,
{ & V_47 ,
{ L_39 , L_49 ,
V_117 , V_100 ,
NULL , 0x00 ,
NULL , V_101 }
} ,
{ & V_49 ,
{ L_39 , L_50 ,
V_103 , V_100 ,
NULL , 0x00 ,
NULL , V_101 }
} ,
{ & V_51 ,
{ L_39 , L_51 ,
V_102 , V_100 ,
NULL , 0x00 ,
NULL , V_101 }
} ,
{ & V_53 ,
{ L_39 , L_52 ,
V_99 , V_100 ,
NULL , 0x00 ,
NULL , V_101 }
} ,
} ;
static T_8 * V_118 [] = {
& V_78 ,
& V_19 ,
& V_119 ,
& V_17
} ;
static T_9 V_120 [] = {
{ & V_87 ,
{ L_53 ,
V_121 ,
V_122 ,
L_54 ,
V_123 }
}
} ;
V_77 = F_32 (
L_55 ,
L_4 ,
L_56
) ;
F_33 ( V_77 , V_98 , F_34 ( V_98 ) ) ;
F_35 ( V_118 , F_34 ( V_118 ) ) ;
V_97 = F_36 ( V_77 ) ;
F_37 ( V_97 , V_120 , F_34 ( V_120 ) ) ;
F_25 () ;
}
void
F_38 ( void )
{
static T_10 V_124 ;
V_124 = F_39 ( F_22 , V_77 ) ;
F_40 ( L_57 , V_124 ) ;
}
