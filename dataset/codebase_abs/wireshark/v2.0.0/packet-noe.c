static T_1 F_1 ( T_1 V_1 )
{
static T_1 V_2 ;
if ( V_1 <= F_2 ( 0xFF ) )
{
V_2 =
V_1 & F_2 ( 0x7F ) ;
}
else if ( V_1 <= F_2 ( 0xFFFF ) )
{
V_2 =
( ( V_1 & F_2 ( 0x1F00 ) >> 2 ) +
( V_1 & F_2 ( 0x3F ) ) ) ;
}
else if ( V_1 <= F_2 ( 0xFFFFFF ) )
{
V_2 =
( ( V_1 & F_2 ( 0x0F0000 ) ) >> 4 ) +
( ( V_1 & F_2 ( 0x3F00 ) ) >> 2 ) +
( V_1 & F_2 ( 0x3F ) ) ;
}
else if ( V_1 <= F_2 ( 0xFFFFFFFF ) )
{
V_2 =
( ( V_1 & F_2 ( 0x07000000 ) ) >> 6 ) +
( ( V_1 & F_2 ( 0x3F0000 ) ) >> 4 ) +
( ( V_1 & F_2 ( 0x3F00 ) ) >> 2 ) +
( V_1 & F_2 ( 0x3F ) ) ;
}
else if ( V_1 <= F_2 ( 0xFFFFFFFFFF ) )
{
V_2 =
( ( V_1 & F_2 ( 0x0300000000 ) ) >> 8 ) +
( ( V_1 & F_2 ( 0x3F000000 ) ) >> 6 ) +
( ( V_1 & F_2 ( 0x3F0000 ) ) >> 4 ) +
( ( V_1 & F_2 ( 0x3F00 ) ) >> 2 ) +
( V_1 & F_2 ( 0x3F ) ) ;
}
else if ( V_1 <= F_2 ( 0xFFFFFFFFFFFF ) )
{
V_2 =
( ( V_1 & F_2 ( 0x010000000000 ) ) >> 10 ) +
( ( V_1 & F_2 ( 0x3F00000000 ) ) >> 8 ) +
( ( V_1 & F_2 ( 0x3F000000 ) ) >> 6 ) +
( ( V_1 & F_2 ( 0x3F0000 ) ) >> 4 ) +
( ( V_1 & F_2 ( 0x3F00 ) ) >> 2 ) +
( V_1 & F_2 ( 0x3F ) ) ;
}
else
{
V_2 = F_2 ( 0 ) ;
}
return V_2 ;
}
static char * F_3 ( int V_2 )
{
char * V_3 ;
V_3 = ( char * ) F_4 ( F_5 () , 10 ) ;
if ( ( V_2 <= 0x20 )
|| ( V_2 == 0x7F )
|| ( V_2 == 0xE0 )
|| ( V_2 == 0xE7 )
|| ( V_2 == 0xE8 )
|| ( V_2 == 0xE9 )
|| ( V_2 == 0xF9 ) )
{
F_6 ( V_3 , 10 , L_1 , F_7 ( V_2 , & V_4 , L_2 ) ) ;
}
else if ( V_2 <= 0xFF )
{
F_6 ( V_3 , 10 , L_3 , V_2 ) ;
}
else
{
F_6 ( V_3 , 10 , L_1 , F_7 ( V_2 , & V_4 , L_2 ) ) ;
}
return V_3 ;
}
static void F_8 ( T_2 * V_5 ,
T_3 * V_6 ,
T_4 V_7 ,
T_4 V_8 )
{
if ( ! V_5 )
return;
F_9 ( V_5 , V_9 , V_6 , V_7 , 2 , V_10 ) ;
V_7 += 2 ;
V_8 -= 2 ;
F_9 ( V_5 , V_11 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
V_8 -= 1 ;
F_9 ( V_5 , V_12 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
V_8 -= 1 ;
F_9 ( V_5 , V_13 , V_6 , V_7 , 2 , V_10 ) ;
V_7 += 2 ;
V_8 -= 2 ;
F_9 ( V_5 , V_14 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
V_8 -= 1 ;
F_9 ( V_5 , V_15 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
V_8 -= 1 ;
F_9 ( V_5 , V_16 , V_6 , V_7 , 2 , V_10 ) ;
V_7 += 2 ;
V_8 -= 2 ;
F_9 ( V_5 , V_17 , V_6 , V_7 , 4 , V_10 ) ;
V_7 += 4 ;
V_8 -= 4 ;
F_9 ( V_5 , V_18 , V_6 , V_7 , V_8 , V_19 ) ;
}
static void F_10 ( T_2 * V_5 ,
T_3 * V_6 ,
T_4 V_7 ,
T_4 V_8 )
{
T_2 * V_20 ;
T_5 V_21 ;
T_6 V_22 ;
V_20 = F_11 ( V_5 ,
V_6 ,
V_7 ,
V_8 , V_23 , NULL ,
L_4 ) ;
while( V_8 > 0 )
{
V_21 = F_12 ( V_6 , V_7 ) ;
F_9 ( V_20 , V_14 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
V_8 -= 1 ;
if ( V_21 >= V_24 )
{
F_9 ( V_20 , V_15 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
V_8 -= 1 ;
}
V_22 = F_12 ( V_6 , V_7 ) ;
if ( V_22 & 0x80 )
{
V_22 = F_13 ( V_6 , V_7 ) ;
V_22 &= 0x7fff ;
F_14 ( V_20 , V_25 , V_6 , V_7 , 2 ,
F_12 ( V_6 , V_7 ) * 256 + F_12 ( V_6 , V_7 + 1 ) ) ;
V_7 += 2 ;
V_8 -= 2 ;
}
else
{
F_14 ( V_20 , V_25 , V_6 , V_7 , 1 ,
F_12 ( V_6 , V_7 ) ) ;
V_7 += 1 ;
V_8 -= 1 ;
}
switch( V_22 )
{
case 0 :
{
break;
}
case 1 :
F_9 ( V_20 , V_26 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
V_8 -= 1 ;
break;
case 2 :
F_9 ( V_20 , V_27 , V_6 , V_7 , 2 , V_10 ) ;
V_7 += 2 ;
V_8 -= 2 ;
break;
case 3 :
F_9 ( V_20 , V_28 , V_6 , V_7 , 3 , V_10 ) ;
V_7 += 3 ;
V_8 -= 3 ;
break;
case 4 :
F_9 ( V_20 , V_29 , V_6 , V_7 , 4 , V_10 ) ;
V_7 += 4 ;
V_8 -= 4 ;
break;
default:
F_9 ( V_20 , V_30 , V_6 , V_7 , V_22 , V_19 ) ;
V_7 += V_22 ;
V_8 -= V_22 ;
break;
}
}
}
static void F_15 ( T_2 * V_5 ,
T_3 * V_6 ,
T_4 V_7 ,
T_4 V_8 )
{
T_2 * V_31 ;
T_5 V_32 ;
V_31 = F_11 ( V_5 ,
V_6 ,
V_7 ,
V_8 , V_33 , NULL ,
L_4 ) ;
while( V_8 > 0 )
{
V_32 = F_12 ( V_6 , V_7 ) ;
F_9 ( V_31 , V_14 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
V_8 -= 1 ;
if ( V_32 >= V_24 )
{
F_9 ( V_31 , V_15 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
V_8 -= 1 ;
}
}
}
static void F_16 ( T_2 * V_5 ,
T_3 * V_6 ,
T_7 * V_34 ,
T_4 V_7 ,
T_4 V_8 )
{
T_8 * V_35 ;
T_5 V_36 = F_12 ( V_6 , V_7 ) ;
F_9 ( V_5 , V_37 , V_6 , V_7 , 1 , V_10 ) ;
F_17 ( V_34 -> V_38 , V_39 , L_5 ,
F_7 ( V_36 , & V_40 , L_2 ) ) ;
F_18 ( V_5 , L_6 ,
F_7 ( V_36 , & V_40 , L_2 ) ) ;
V_7 += 1 ;
V_8 -= 1 ;
switch( V_36 )
{
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
V_35 = F_9 ( V_5 , V_47 , V_6 , V_7 , 1 , V_10 ) ;
F_19 ( V_35 , V_8 ) ;
break;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
{
T_1 V_53 = 0 ;
T_1 V_54 ;
char * V_3 ;
int V_55 = V_8 ;
int V_56 = V_7 ;
while( V_55 > 0 )
{
V_53 = ( V_53 << 8 ) + F_12 ( V_6 , V_56 ) ;
V_56 += 1 ;
V_55 -= 1 ;
}
V_54 = F_1 ( V_53 ) ;
V_3 = ( char * ) F_4 ( F_5 () , 30 ) ;
F_6 ( V_3 , 30 , L_7 , F_3 ( ( int ) V_54 ) ) ;
F_17 ( V_34 -> V_38 , V_39 , L_8 , V_3 ) ;
F_18 ( V_5 , L_6 ,
V_3 ) ;
F_20 ( V_5 , V_57 ,
V_6 ,
V_7 ,
V_8 , V_3 ,
L_9 V_58 L_10 ,
V_3 ,
F_21 ( F_5 () , V_6 , V_7 , V_8 ) ,
V_54 ) ;
break;
}
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
{
F_8 ( V_5 , V_6 , V_7 , V_8 ) ;
break;
}
case V_64 :
F_9 ( V_5 , V_65 , V_6 , V_7 , 1 , V_10 ) ;
break;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
F_9 ( V_5 , V_13 , V_6 , V_7 , 2 , V_10 ) ;
break;
case V_71 :
F_9 ( V_5 , V_72 , V_6 , V_7 , 4 , V_10 ) ;
break;
case V_73 :
{
F_9 ( V_5 , V_13 , V_6 , V_7 , 2 , V_10 ) ;
V_7 += 2 ;
F_9 ( V_5 , V_74 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
F_22 ( V_5 , V_17 ,
V_6 ,
V_7 ,
1 , F_13 ( V_6 , V_7 ) ,
L_11 ,
F_13 ( V_6 , V_7 ) ) ;
break;
}
default:
F_9 ( V_5 , V_13 , V_6 , V_7 , 2 , V_10 ) ;
V_7 += 2 ;
V_8 -= 2 ;
if ( V_8 > 0 )
F_10 ( V_5 , V_6 , V_7 , V_8 ) ;
break;
}
}
static void F_23 ( T_2 * V_5 ,
T_3 * V_6 ,
T_7 * V_34 ,
T_5 V_75 ,
T_4 V_7 ,
T_4 V_8 )
{
T_5 V_76 = F_12 ( V_6 , V_7 ) ;
F_9 ( V_5 , V_12 , V_6 , V_7 , 1 , V_10 ) ;
F_17 ( V_34 -> V_38 , V_39 , L_5 ,
F_7 ( V_76 , & V_77 , L_2 ) ) ;
F_18 ( V_5 , L_6 ,
F_7 ( V_76 , & V_77 , L_2 ) ) ;
V_7 += 1 ;
V_8 -= 1 ;
if ( V_76 >= V_78 )
{
F_9 ( V_5 , V_13 , V_6 , V_7 , 2 , V_10 ) ;
V_7 += 2 ;
V_8 -= 2 ;
}
switch( V_75 )
{
case V_79 :
{
F_9 ( V_5 , V_80 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
V_8 -= 1 ;
if ( V_8 > 0 )
F_10 ( V_5 , V_6 , V_7 , V_8 ) ;
break;
}
case V_81 :
{
F_9 ( V_5 , V_80 , V_6 , V_7 , 1 , V_10 ) ;
break;
}
case V_82 :
{
F_15 ( V_5 , V_6 , V_7 , V_8 ) ;
break;
}
default:
{
if ( V_8 > 0 )
F_10 ( V_5 , V_6 , V_7 , V_8 ) ;
break;
}
}
}
static void F_24 ( T_3 * V_6 ,
T_7 * V_34 ,
T_2 * V_5 )
{
T_8 * V_83 ;
T_2 * V_84 ;
T_9 V_8 ;
T_5 V_85 ;
T_5 V_75 ;
T_10 V_86 ;
T_9 V_7 = 0 ;
V_83 = F_9 ( V_5 , V_87 , V_6 , 0 , - 1 , V_19 ) ;
V_84 = F_25 ( V_83 , V_88 ) ;
V_8 = F_26 ( V_6 , V_7 ) ;
F_14 ( V_84 ,
V_16 ,
V_6 ,
V_7 ,
2 ,
V_8 ) ;
V_7 += 2 ;
V_85 = F_12 ( V_6 , V_7 ) ;
F_17 ( V_34 -> V_38 , V_39 , L_12 ,
F_27 ( V_85 , V_89 , L_2 ) ) ;
F_14 ( V_84 ,
V_90 ,
V_6 ,
V_7 ,
1 ,
V_85 ) ;
V_7 += 1 ;
V_8 -= 1 ;
F_18 ( V_83 , L_6 ,
F_27 ( V_85 , V_89 , L_2 ) ) ;
V_75 = F_12 ( V_6 , V_7 ) ;
V_86 = ( V_75 & 0x80 ) != 0 ;
V_75 = ( V_75 & 0x7f ) ;
F_22 ( V_84 ,
V_11 ,
V_6 ,
V_7 ,
1 ,
V_75 ,
L_13 ,
F_27 ( V_75 , V_91 , L_2 ) ,
V_75 ) ;
if ( V_75 >= V_92 )
return;
F_17 ( V_34 -> V_38 , V_39 , L_8 ,
F_27 ( V_75 , V_91 , L_2 ) ) ;
F_18 ( V_83 , L_6 ,
F_27 ( V_75 , V_91 , L_2 ) ) ;
if ( V_75 == V_93 )
{
V_7 += 1 ;
V_8 -= 1 ;
F_16 ( V_84 , V_6 , V_34 , V_7 , V_8 ) ;
}
else
{
F_28 ( V_84 ,
V_94 ,
V_6 ,
V_7 ,
1 ,
V_86 ) ;
V_7 += 1 ;
V_8 -= 1 ;
F_23 ( V_84 , V_6 , V_34 , V_75 , V_7 , V_8 ) ;
}
}
void F_29 ( void )
{
static T_11 V_95 [] =
{
{ & V_16 ,
{
L_14 ,
L_15 ,
V_96 ,
V_97 ,
NULL ,
0x0 ,
L_16 ,
V_98
}
} ,
{ & V_90 ,
{
L_17 ,
L_18 ,
V_99 ,
V_100 ,
F_30 ( V_101 ) ,
0x0 ,
L_19 ,
V_98
}
} ,
{ & V_94 ,
{
L_20 ,
L_21 ,
V_102 ,
V_103 ,
NULL ,
0x0 ,
L_22 ,
V_98
}
} ,
{ & V_11 ,
{
L_23 ,
L_24 ,
V_99 ,
V_97 ,
F_30 ( V_91 ) ,
0x0 ,
L_19 ,
V_98
}
} ,
{ & V_12 ,
{
L_25 ,
L_26 ,
V_99 ,
V_97 | V_104 ,
& V_77 ,
0x0 ,
L_27 ,
V_98
}
} ,
{ & V_37 ,
{
L_28 ,
L_29 ,
V_99 ,
V_97 | V_104 ,
& V_40 ,
0x0 ,
L_30 ,
V_98
}
} ,
{ & V_13 ,
{
L_31 ,
L_32 ,
V_96 ,
V_100 ,
NULL ,
0x0 ,
L_33 ,
V_98
}
} ,
{ & V_80 ,
{
L_34 ,
L_35 ,
V_99 ,
V_97 ,
NULL ,
0x0 ,
L_36 ,
V_98
}
} ,
{ & V_14 ,
{
L_37 ,
L_38 ,
V_99 ,
V_100 | V_104 ,
& V_105 ,
0x0 ,
L_39 ,
V_98
}
} ,
{ & V_25 ,
{
L_40 ,
L_41 ,
V_96 ,
V_97 ,
NULL ,
0x0 ,
L_42 ,
V_98
}
} ,
{ & V_9 ,
{
L_43 ,
L_44 ,
V_96 ,
V_97 | V_104 ,
& V_106 ,
0x0 ,
L_45 ,
V_98
}
} ,
{ & V_15 ,
{
L_46 ,
L_47 ,
V_99 ,
V_97 ,
NULL ,
0x0 ,
L_48 ,
V_98
}
} ,
{ & V_17 ,
{
L_49 ,
L_50 ,
V_107 ,
V_100 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_18 ,
{
L_51 ,
L_52 ,
V_108 ,
V_103 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_26 ,
{
L_49 ,
L_53 ,
V_99 ,
V_97 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_27 ,
{
L_49 ,
L_53 ,
V_96 ,
V_97 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_28 ,
{
L_49 ,
L_53 ,
V_109 ,
V_97 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_29 ,
{
L_49 ,
L_53 ,
V_107 ,
V_97 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_30 ,
{
L_49 ,
L_54 ,
V_108 ,
V_103 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_47 ,
{
L_49 ,
L_55 ,
V_99 ,
V_97 ,
F_30 ( V_110 ) ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_65 ,
{
L_56 ,
L_57 ,
V_99 ,
V_97 ,
F_30 ( V_101 ) ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_72 ,
{
L_58 ,
L_59 ,
V_107 ,
V_97 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_74 ,
{
L_60 ,
L_61 ,
V_99 ,
V_97 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_57 ,
{
L_62 ,
L_63 ,
V_111 ,
V_103 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
} ;
static T_9 * V_112 [] =
{
& V_88 ,
& V_23 ,
& V_33 ,
& V_113 ,
} ;
V_87 = F_31 ( L_64 , L_65 , L_66 ) ;
F_32 ( V_87 , V_95 , F_33 ( V_95 ) ) ;
F_34 ( L_66 , F_24 , V_87 ) ;
F_35 ( V_112 , F_33 ( V_112 ) ) ;
}
void F_36 ( void )
{
#if 0
dissector_handle_t handle_noe = find_dissector("noe");
dissector_add_uint("ua.opcode", 0x15, handle_noe);
#endif
}
