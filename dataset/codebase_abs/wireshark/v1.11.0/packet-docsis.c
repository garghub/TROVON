static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 )
{
T_2 * V_4 ;
T_4 * V_5 , * V_6 ;
T_5 V_7 ;
int V_8 ;
T_6 type ;
T_6 V_9 ;
T_6 V_10 ;
T_6 V_11 ;
T_7 V_12 ;
V_7 = F_2 ( V_1 , 1 ) ;
V_8 = 4 ;
V_5 = F_3 ( V_2 , V_1 , V_8 , V_7 , L_1 ) ;
V_4 = F_4 ( V_5 , V_13 ) ;
while ( V_8 < V_7 + 4 )
{
type = ( F_2 ( V_1 , V_8 ) & 0xF0 ) ;
V_9 = ( F_2 ( V_1 , V_8 ) & 0x0F ) ;
if ( ( ( ( type >> 4 ) & 0x0F ) == 6 ) && ( V_9 == 2 ) )
{
V_6 = F_5 ( V_4 , V_14 , V_1 , V_8 , 1 , V_15 ) ;
F_6 ( V_6 ) ;
F_3 ( V_4 , V_1 , V_8 , 1 , L_2 ) ;
}
else
F_5 ( V_4 , V_14 , V_1 , V_8 , 1 , V_15 ) ;
F_5 ( V_4 , V_16 , V_1 , V_8 , 1 , V_15 ) ;
switch ( ( type >> 4 ) & 0x0F )
{
case V_17 :
if ( V_9 == 3 )
{
V_11 = F_2 ( V_1 , V_8 + 1 ) ;
V_12 = F_7 ( V_1 , V_8 + 2 ) ;
F_8 ( V_4 , V_18 , V_1 ,
V_8 + 1 , 1 , V_11 ) ;
F_8 ( V_4 , V_19 , V_1 , V_8 + 2 , 2 ,
V_12 ) ;
}
else
{
F_9 ( V_20 ) ;
}
break;
case V_21 :
if ( V_9 == 2 )
{
V_12 = F_7 ( V_1 , V_8 + 1 ) ;
F_8 ( V_4 , V_19 , V_1 , V_8 + 2 , 2 ,
V_12 ) ;
}
else
{
F_9 ( V_20 ) ;
}
case V_22 :
F_5 ( V_4 , V_23 , V_1 , V_8 + 1 , 1 ,
V_15 ) ;
F_5 ( V_4 , V_24 , V_1 , V_8 + 1 , 1 ,
V_15 ) ;
F_5 ( V_4 , V_25 , V_1 , V_8 + 2 , 1 ,
V_15 ) ;
F_5 ( V_4 , V_26 , V_1 , V_8 + 2 ,
1 , V_15 ) ;
F_5 ( V_4 , V_19 , V_1 , V_8 + 2 , 2 ,
V_15 ) ;
F_5 ( V_4 , V_18 , V_1 , V_8 + 4 ,
1 , V_15 ) ;
if ( V_3 )
{
F_5 ( V_4 , V_27 , V_1 , V_8 + 5 ,
1 , V_15 ) ;
F_5 ( V_4 , V_28 , V_1 , V_8 + 5 ,
1 , V_15 ) ;
F_5 ( V_4 , V_29 , V_1 , V_8 + 5 ,
1 , V_15 ) ;
F_5 ( V_4 , V_30 , V_1 , V_8 + 5 ,
1 , V_15 ) ;
}
break;
case V_31 :
F_5 ( V_4 , V_23 , V_1 , V_8 + 1 , 1 ,
V_15 ) ;
F_5 ( V_4 , V_24 , V_1 , V_8 + 1 , 1 ,
V_15 ) ;
F_5 ( V_4 , V_25 , V_1 , V_8 + 2 , 1 ,
V_15 ) ;
F_5 ( V_4 , V_26 , V_1 , V_8 + 2 ,
1 , V_15 ) ;
F_5 ( V_4 , V_32 , V_1 , V_8 + 2 , 2 ,
V_15 ) ;
F_5 ( V_4 , V_33 , V_1 , V_8 + 4 , 1 ,
V_15 ) ;
break;
case V_34 :
case V_35 :
V_10 = F_2 ( V_1 , V_8 + 1 ) ;
if ( V_10 == 0 )
{
V_6 = F_5 ( V_4 , V_36 , V_1 , V_8 + 1 , 1 , V_15 ) ;
F_6 ( V_6 ) ;
F_3 ( V_4 , V_1 , V_8 + 1 , 1 , L_3 ) ;
}
else
F_5 ( V_4 , V_36 , V_1 , V_8 + 1 , 1 , V_15 ) ;
if ( V_9 == 2 )
{
F_5 ( V_4 , V_37 , V_1 , V_8 + 2 , 1 , V_15 ) ;
F_5 ( V_4 , V_38 , V_1 , V_8 + 2 , 1 , V_15 ) ;
}
break;
case V_39 :
F_5 ( V_4 , V_40 , V_1 , V_8 + 1 , 1 ,
V_15 ) ;
F_5 ( V_4 , V_41 , V_1 , V_8 + 1 , 1 ,
V_15 ) ;
F_5 ( V_4 , V_42 , V_1 , V_8 + 2 , 1 ,
V_15 ) ;
F_5 ( V_4 , V_43 , V_1 , V_8 + 2 ,
1 , V_15 ) ;
F_5 ( V_4 , V_44 , V_1 , V_8 + 2 , 2 ,
V_15 ) ;
break;
case V_45 :
F_5 ( V_4 , V_46 , V_1 , V_8 + 1 , 1 , FALSE ) ;
if ( V_9 == 3 )
{
F_5 ( V_4 , V_47 , V_1 , V_8 + 1 , 3 , FALSE ) ;
}
if ( V_9 == 5 )
{
F_5 ( V_4 , V_48 , V_1 , V_8 + 1 , 1 , FALSE ) ;
F_5 ( V_4 , V_47 , V_1 , V_8 + 1 , 3 , FALSE ) ;
F_5 ( V_4 , V_49 , V_1 , V_8 + 4 , 2 , FALSE ) ;
}
break;
default:
if ( V_9 > 0 )
F_5 ( V_4 , V_50 , V_1 , V_8 + 1 ,
V_9 , V_51 ) ;
}
V_8 += V_9 + 1 ;
}
return;
}
static void
F_10 ( T_1 * V_1 , T_8 * V_52 , T_2 * V_2 )
{
T_6 V_53 ;
T_6 V_54 ;
T_6 V_55 ;
T_6 V_56 ;
T_5 V_57 ;
T_5 V_58 ;
T_7 V_59 ;
T_1 * V_60 , * V_61 ;
T_5 V_62 , V_63 ;
T_5 V_64 ;
T_3 V_3 = FALSE ;
T_5 V_65 ;
T_4 * V_66 ;
T_2 * V_67 ;
static T_5 V_68 ;
static T_5 V_69 ;
V_53 = F_2 ( V_1 , 0 ) ;
V_54 = ( V_53 >> 6 ) & 0x03 ;
V_55 = ( V_53 >> 1 ) & 0x1F ;
V_56 = ( V_53 & 0x01 ) ;
V_57 = F_2 ( V_1 , 1 ) ;
V_59 = F_7 ( V_1 , 2 ) ;
if ( V_56 == 0x00 )
V_58 = 6 ;
else
V_58 = 6 + V_57 ;
V_63 = F_11 ( V_1 , V_58 ) ;
if ( ( V_54 == V_70 ) && V_55 == 0x02 )
{
V_62 = 0 ;
V_64 = 6 ;
}
else
{
V_64 = 6 + V_59 ;
V_62 = V_59 - ( V_57 + 2 ) ;
}
if ( ( V_54 == V_70 ) && ( V_55 == 0x1c ) )
{
V_68 = V_59 ;
V_69 = 6 ;
}
F_12 ( V_52 -> V_71 , V_72 , L_4 ) ;
F_13 ( V_52 -> V_71 , V_73 ) ;
switch ( V_54 )
{
case V_74 :
F_12 ( V_52 -> V_71 , V_73 , L_5 ) ;
break;
case V_75 :
F_12 ( V_52 -> V_71 , V_73 , L_6 ) ;
break;
case V_76 :
F_12 ( V_52 -> V_71 , V_73 , L_7 ) ;
break;
case V_70 :
if ( V_55 == 0x02 )
F_14 ( V_52 -> V_71 , V_73 ,
L_8 , V_59 ,
V_57 ) ;
else if ( V_55 == 0x03 )
F_12 ( V_52 -> V_71 , V_73 , L_9 ) ;
else
F_12 ( V_52 -> V_71 , V_73 , L_10 ) ;
break;
}
if ( V_2 )
{
V_66 = F_15 ( V_2 , V_77 , V_1 , 0 ,
V_58 , L_4 ) ;
V_67 = F_4 ( V_66 , V_78 ) ;
F_5 ( V_67 , V_79 , V_1 , 0 , 1 , V_15 ) ;
switch ( V_54 )
{
case V_74 :
case V_75 :
case V_76 :
F_5 ( V_67 , V_80 , V_1 , 0 , 1 ,
V_15 ) ;
F_5 ( V_67 , V_81 , V_1 , 0 , 1 ,
V_15 ) ;
if ( V_56 == 0x01 )
{
F_5 ( V_67 , V_82 , V_1 , 1 , 1 ,
V_15 ) ;
F_5 ( V_67 , V_83 , V_1 , 2 , 2 ,
V_15 ) ;
F_1 ( V_1 , V_67 , V_3 ) ;
F_5 ( V_67 , V_84 , V_1 ,
4 + V_57 , 2 , V_15 ) ;
}
else
{
F_5 ( V_67 , V_85 , V_1 , 1 , 1 ,
V_15 ) ;
F_5 ( V_67 , V_83 , V_1 , 2 , 2 ,
V_15 ) ;
F_5 ( V_67 , V_84 , V_1 , 4 , 2 ,
V_15 ) ;
}
break;
case V_70 :
F_5 ( V_67 , V_86 , V_1 , 0 ,
1 , V_15 ) ;
F_5 ( V_67 , V_81 , V_1 , 0 , 1 ,
V_15 ) ;
if ( V_55 == 0x02 )
{
F_8 ( V_67 , V_18 , V_1 , 1 ,
1 , V_57 ) ;
F_8 ( V_67 , V_19 , V_1 , 2 , 2 ,
V_59 ) ;
F_5 ( V_67 , V_84 , V_1 , 4 , 2 ,
V_15 ) ;
break;
}
if ( V_55 == 0x03 )
{
V_3 = TRUE ;
}
if ( V_55 == 0x1c )
{
F_16 ( V_66 , L_11 ) ;
F_5 ( V_67 , V_87 , V_1 , 1 ,
1 , V_15 ) ;
F_5 ( V_67 , V_83 , V_1 , 2 , 2 ,
V_15 ) ;
F_5 ( V_67 , V_84 , V_1 , 4 , 2 ,
V_15 ) ;
break;
}
if ( V_56 == 0x01 )
{
F_5 ( V_67 , V_82 , V_1 , 1 , 1 ,
V_15 ) ;
F_5 ( V_67 , V_83 , V_1 , 2 , 2 ,
V_15 ) ;
F_1 ( V_1 , V_67 , V_3 ) ;
F_5 ( V_67 , V_84 , V_1 ,
4 + V_57 , 2 , V_15 ) ;
break;
}
F_5 ( V_67 , V_85 , V_1 , 1 , 1 ,
V_15 ) ;
F_5 ( V_67 , V_83 , V_1 , 2 , 2 ,
V_15 ) ;
F_5 ( V_67 , V_84 , V_1 , 4 , 2 , V_15 ) ;
break;
}
}
switch ( V_54 )
{
case V_74 :
case V_76 :
if ( V_62 >= 0 )
{
if ( V_62 > 0 )
{
V_60 = F_17 ( V_1 , V_58 , V_63 , V_62 ) ;
F_18 ( V_88 , V_60 , V_52 , V_2 ) ;
}
if ( V_68 > 0 )
{
V_68 = V_68 - V_64 ;
V_69 += V_64 ;
}
}
break;
case V_70 :
switch ( V_55 )
{
case 0x00 :
case 0x01 :
if ( V_62 > 0 )
{
V_61 = F_17 ( V_1 , V_58 , V_63 , V_62 ) ;
F_18 ( V_89 , V_61 , V_52 , V_2 ) ;
}
if ( V_68 > 0 )
{
V_68 = V_68 - V_64 ;
V_69 += V_64 ;
}
break;
case 0x02 :
break;
case 0x03 :
if ( V_62 > 0 )
{
V_61 = F_17 ( V_1 , V_58 , V_63 , V_62 ) ;
F_18 ( V_90 , V_61 , V_52 , V_2 ) ;
}
if ( V_68 > 0 )
{
V_68 = V_68 - V_64 ;
V_69 += V_64 ;
}
break;
case 0x1c :
while ( V_68 > 0 )
{
V_65 = V_68 ;
V_60 = F_17 ( V_1 , V_69 , - 1 , V_68 ) ;
F_18 ( V_91 , V_60 , V_52 , V_2 ) ;
if ( V_65 <= V_68 )
F_9 ( V_20 ) ;
}
V_68 = 0 ;
V_69 = 0 ;
F_12 ( V_52 -> V_71 , V_73 , L_12 ) ;
break;
}
break;
}
}
void
F_19 ( void )
{
static T_9 V_92 [] = {
{ & V_79 ,
{ L_13 , L_14 ,
V_93 , V_94 , F_20 ( V_95 ) , 0xC0 ,
L_15 , V_96 }
} ,
{ & V_80 ,
{ L_16 , L_17 ,
V_93 , V_97 , NULL , 0x3E ,
L_18 , V_96 }
} ,
{ & V_86 ,
{ L_16 , L_17 ,
V_93 , V_94 , F_20 ( V_98 ) , 0x3E ,
L_18 , V_96 }
} ,
{ & V_81 ,
{ L_19 , L_20 ,
V_99 , 8 , F_21 ( & V_100 ) , 0x01 ,
L_21 , V_96 }
} ,
{ & V_85 ,
{ L_22 , L_23 ,
V_93 , V_94 , NULL , 0x0 ,
L_24 , V_96 }
} ,
{ & V_87 ,
{ L_25 , L_23 ,
V_93 , V_97 , NULL , 0x0 ,
NULL , V_96 }
} ,
{ & V_82 ,
{ L_26 , L_23 ,
V_93 , V_97 , NULL , 0x0 ,
L_24 , V_96 }
} ,
{ & V_83 ,
{ L_27 , L_28 ,
V_101 , V_97 , NULL , 0x0 ,
L_29 , V_96 }
} ,
{ & V_14 ,
{ L_30 , L_31 ,
V_93 , V_97 , F_20 ( V_102 ) , 0xF0 ,
L_32 , V_96 }
} ,
{ & V_16 ,
{ L_33 , L_34 ,
V_93 , V_97 , NULL , 0x0F ,
L_35 , V_96 }
} ,
{ & V_50 ,
{ L_36 , L_37 ,
V_103 , V_104 , NULL , 0x0 ,
L_38 , V_96 }
} ,
{ & V_27 ,
{ L_39 , L_40 ,
V_93 , V_97 , NULL , 0xC0 ,
NULL , V_96 }
} ,
{ & V_28 ,
{ L_41 , L_42 ,
V_99 , 8 , NULL , 0x20 ,
NULL , V_96 }
} ,
{ & V_29 ,
{ L_43 , L_44 ,
V_99 , 8 , NULL , 0x10 ,
NULL , V_96 }
} ,
{ & V_30 ,
{ L_45 , L_46 ,
V_93 , V_97 , NULL , 0x0F ,
L_47 , V_96 }
} ,
{ & V_19 ,
{ L_48 , L_49 ,
V_101 , V_97 , NULL , 0x3FFF ,
L_50 , V_96 }
} ,
{ & V_32 ,
{ L_51 , L_52 ,
V_101 , V_97 , NULL , 0x3FFF ,
L_53 , V_96 }
} ,
{ & V_33 ,
{ L_39 , L_54 ,
V_93 , V_94 , NULL , 0x3FFF ,
L_55 , V_96 }
} ,
{ & V_18 ,
{ L_56 , L_57 ,
V_93 , V_97 , NULL , 0x0 ,
L_58 , V_96 }
} ,
{ & V_23 ,
{ L_59 , L_60 ,
V_93 , V_97 , NULL , 0xF0 ,
NULL , V_96 }
} ,
{ & V_24 ,
{ L_61 , L_62 ,
V_93 , V_97 , NULL , 0x0F ,
NULL , V_96 }
} ,
{ & V_36 ,
{ L_63 , L_64 ,
V_93 , V_97 , NULL , 0x0 ,
NULL , V_96 }
} ,
{ & V_37 ,
{ L_65 , L_66 ,
V_99 , 8 , F_21 ( & V_105 ) , 0x80 ,
NULL , V_96 }
} ,
{ & V_38 ,
{ L_67 , L_68 ,
V_93 , V_97 , NULL , 0x7F ,
NULL , V_96 }
} ,
{ & V_40 ,
{ L_59 , L_69 ,
V_93 , V_97 , NULL , 0xF0 ,
L_70 , V_96 }
} ,
{ & V_41 ,
{ L_61 , L_71 ,
V_93 , V_97 , NULL , 0x0F ,
L_70 , V_96 }
} ,
{ & V_42 ,
{ L_72 , L_73 ,
V_99 , 8 , F_21 ( & V_106 ) , 0x80 ,
L_74 , V_96 } ,
} ,
{ & V_43 ,
{ L_75 , L_76 ,
V_99 , 8 , F_21 ( & V_107 ) , 0x40 ,
L_70 , V_96 } ,
} ,
{ & V_44 ,
{ L_48 , L_77 ,
V_101 , V_97 , NULL , 0x3FFF ,
L_50 , V_96 }
} ,
{ & V_46 ,
{ L_78 , L_79 ,
V_93 , V_97 , NULL , 0xE0 ,
L_70 , V_96 }
} ,
{ & V_48 ,
{ L_80 , L_81 ,
V_93 , V_97 , NULL , 0x10 ,
L_70 , V_96 }
} ,
{ & V_47 ,
{ L_82 , L_83 ,
V_108 , V_97 , NULL , 0x0FFFFF ,
L_70 , V_96 }
} ,
{ & V_49 ,
{ L_84 , L_85 ,
V_101 , V_97 , NULL , 0x0 ,
L_70 , V_96 }
} ,
{ & V_84 ,
{ L_86 , L_87 ,
V_101 , V_94 , NULL , 0x0 ,
NULL , V_96 } ,
} ,
{ & V_25 ,
{ L_72 , L_88 ,
V_99 , 8 , F_21 ( & V_106 ) , 0x80 ,
L_74 , V_96 } ,
} ,
{ & V_26 ,
{ L_75 , L_89 ,
V_99 , 8 , F_21 ( & V_107 ) , 0x40 ,
NULL , V_96 } ,
} ,
} ;
static T_5 * V_109 [] = {
& V_78 ,
& V_13 ,
} ;
#if 0
docsis_dissector_table = register_dissector_table ("docsis",
"DOCSIS Encapsulation Type",
FT_UINT8, BASE_DEC);
#endif
V_77 = F_22 ( L_90 , L_4 , L_91 ) ;
F_23 ( V_77 , V_92 , F_24 ( V_92 ) ) ;
F_25 ( V_109 , F_24 ( V_109 ) ) ;
F_26 ( L_91 , F_10 , V_77 ) ;
}
void
F_27 ( void )
{
V_91 = F_28 ( L_91 ) ;
V_90 = F_28 ( L_92 ) ;
F_29 ( L_93 , V_110 , V_91 ) ;
V_89 = F_28 ( L_94 ) ;
V_88 = F_28 ( L_95 ) ;
}
