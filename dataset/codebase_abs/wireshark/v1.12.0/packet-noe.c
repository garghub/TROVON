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
F_9 ( V_5 , V_15 , V_6 , V_7 , 1 , V_16 ) ;
V_7 += 1 ;
V_8 -= 1 ;
F_9 ( V_5 , V_17 , V_6 , V_7 , 2 , V_10 ) ;
V_7 += 2 ;
V_8 -= 2 ;
F_9 ( V_5 , V_18 , V_6 , V_7 , 4 , V_10 ) ;
V_7 += 4 ;
V_8 -= 4 ;
F_9 ( V_5 , V_19 , V_6 , V_7 , V_8 , V_16 ) ;
}
static void F_10 ( T_2 * V_5 ,
T_3 * V_6 ,
T_4 V_7 ,
T_4 V_8 )
{
T_5 * V_20 ;
T_2 * V_21 ;
T_6 V_22 ;
T_7 V_23 ;
V_20 = F_11 ( V_5 ,
V_6 ,
V_7 ,
V_8 ,
L_4 ) ;
V_21 = F_12 ( V_20 , V_24 ) ;
while( V_8 > 0 )
{
V_22 = F_13 ( V_6 , V_7 ) ;
F_9 ( V_21 , V_14 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
V_8 -= 1 ;
if ( V_22 >= V_25 )
{
F_9 ( V_20 , V_15 , V_6 , V_7 , 1 , V_16 ) ;
V_7 += 1 ;
V_8 -= 1 ;
}
V_23 = F_13 ( V_6 , V_7 ) ;
if ( V_23 & 0x80 )
{
V_23 = F_14 ( V_6 , V_7 ) ;
V_23 &= 0x7fff ;
F_15 ( V_21 , V_26 , V_6 , V_7 , 2 ,
F_13 ( V_6 , V_7 ) * 256 + F_13 ( V_6 , V_7 + 1 ) ) ;
V_7 += 2 ;
V_8 -= 2 ;
}
else
{
F_15 ( V_21 , V_26 , V_6 , V_7 , 1 ,
F_13 ( V_6 , V_7 ) ) ;
V_7 += 1 ;
V_8 -= 1 ;
}
switch( V_23 )
{
case 0 :
{
break;
}
case 1 :
F_9 ( V_21 , V_27 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
V_8 -= 1 ;
break;
case 2 :
F_9 ( V_21 , V_28 , V_6 , V_7 , 2 , V_10 ) ;
V_7 += 2 ;
V_8 -= 2 ;
break;
case 3 :
F_9 ( V_21 , V_29 , V_6 , V_7 , 3 , V_10 ) ;
V_7 += 3 ;
V_8 -= 3 ;
break;
case 4 :
F_9 ( V_21 , V_30 , V_6 , V_7 , 4 , V_10 ) ;
V_7 += 4 ;
V_8 -= 4 ;
break;
default:
F_9 ( V_21 , V_31 , V_6 , V_7 , V_23 , V_16 ) ;
V_7 += V_23 ;
V_8 -= V_23 ;
break;
}
}
}
static void F_16 ( T_2 * V_5 ,
T_3 * V_6 ,
T_4 V_7 ,
T_4 V_8 )
{
T_5 * V_32 ;
T_2 * V_33 ;
T_6 V_34 ;
V_32 = F_11 ( V_5 ,
V_6 ,
V_7 ,
V_8 ,
L_4 ) ;
V_33 = F_12 ( V_32 , V_35 ) ;
while( V_8 > 0 )
{
V_34 = F_13 ( V_6 , V_7 ) ;
F_9 ( V_33 , V_14 , V_6 , V_7 , 1 , V_10 ) ;
V_7 += 1 ;
V_8 -= 1 ;
if ( V_34 >= V_25 )
{
F_9 ( V_32 , V_15 , V_6 , V_7 , 1 , V_16 ) ;
V_7 += 1 ;
V_8 -= 1 ;
}
}
}
static void F_17 ( T_2 * V_5 ,
T_3 * V_6 ,
T_8 * V_36 ,
T_4 V_7 ,
T_4 V_8 )
{
T_5 * V_37 ;
T_6 V_38 = F_13 ( V_6 , V_7 ) ;
F_9 ( V_5 , V_39 , V_6 , V_7 , 1 , V_10 ) ;
F_18 ( V_36 -> V_40 , V_41 , L_5 ,
F_7 ( V_38 , & V_42 , L_2 ) ) ;
F_19 ( V_5 , L_6 ,
F_7 ( V_38 , & V_42 , L_2 ) ) ;
V_7 += 1 ;
V_8 -= 1 ;
switch( V_38 )
{
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
V_37 = F_9 ( V_5 , V_49 , V_6 , V_7 , 1 , V_10 ) ;
F_20 ( V_37 , V_8 ) ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
{
T_1 V_55 = 0 ;
T_1 V_56 ;
char * V_3 ;
int V_57 = V_8 ;
int V_58 = V_7 ;
while( V_57 > 0 )
{
V_55 = ( V_55 << 8 ) + F_13 ( V_6 , V_58 ) ;
V_58 += 1 ;
V_57 -= 1 ;
}
V_56 = F_1 ( V_55 ) ;
V_3 = ( char * ) F_4 ( F_5 () , 30 ) ;
F_6 ( V_3 , 30 , L_7 , F_3 ( ( int ) V_56 ) ) ;
F_18 ( V_36 -> V_40 , V_41 , L_8 , V_3 ) ;
F_19 ( V_5 , L_6 ,
V_3 ) ;
F_11 ( V_5 ,
V_6 ,
V_7 ,
V_8 ,
L_9 V_59 L_10 ,
V_3 ,
F_21 ( V_6 , V_7 , V_8 ) ,
V_56 ) ;
break;
}
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
{
F_8 ( V_5 , V_6 , V_7 , V_8 ) ;
break;
}
case V_65 :
F_9 ( V_5 , V_66 , V_6 , V_7 , 1 , V_10 ) ;
break;
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
F_9 ( V_5 , V_13 , V_6 , V_7 , 2 , V_10 ) ;
break;
case V_72 :
F_9 ( V_5 , V_73 , V_6 , V_7 , 4 , V_10 ) ;
break;
case V_74 :
{
F_9 ( V_5 , V_13 , V_6 , V_7 , 2 , V_10 ) ;
V_7 += 2 ;
F_11 ( V_5 ,
V_6 ,
V_7 ,
1 ,
L_11 ,
F_14 ( V_6 , V_7 ) ) ;
V_7 += 1 ;
F_11 ( V_5 ,
V_6 ,
V_7 ,
1 ,
L_12 ,
F_14 ( V_6 , V_7 ) ) ;
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
static void F_22 ( T_2 * V_5 ,
T_3 * V_6 ,
T_8 * V_36 ,
T_6 V_75 ,
T_4 V_7 ,
T_4 V_8 )
{
T_6 V_76 = F_13 ( V_6 , V_7 ) ;
F_9 ( V_5 , V_12 , V_6 , V_7 , 1 , V_10 ) ;
F_18 ( V_36 -> V_40 , V_41 , L_5 ,
F_7 ( V_76 , & V_77 , L_2 ) ) ;
F_19 ( V_5 , L_6 ,
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
F_16 ( V_5 , V_6 , V_7 , V_8 ) ;
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
static void F_23 ( T_3 * V_6 ,
T_8 * V_36 ,
T_2 * V_5 )
{
T_5 * V_83 ;
T_2 * V_84 ;
T_9 V_8 ;
T_6 V_85 ;
T_6 V_75 ;
T_10 V_86 ;
T_9 V_7 = 0 ;
V_83 = F_9 ( V_5 , V_87 , V_6 , 0 , - 1 , V_16 ) ;
V_84 = F_12 ( V_83 , V_88 ) ;
V_8 = F_24 ( V_6 , V_7 ) ;
F_15 ( V_84 ,
V_17 ,
V_6 ,
V_7 ,
2 ,
V_8 ) ;
V_7 += 2 ;
V_85 = F_13 ( V_6 , V_7 ) ;
F_18 ( V_36 -> V_40 , V_41 , L_13 ,
F_25 ( V_85 , V_89 , L_2 ) ) ;
F_15 ( V_84 ,
V_90 ,
V_6 ,
V_7 ,
1 ,
V_85 ) ;
V_7 += 1 ;
V_8 -= 1 ;
F_19 ( V_83 , L_6 ,
F_25 ( V_85 , V_89 , L_2 ) ) ;
V_75 = F_13 ( V_6 , V_7 ) ;
V_86 = ( V_75 & 0x80 ) != 0 ;
V_75 = ( V_75 & 0x7f ) ;
F_26 ( V_84 ,
V_11 ,
V_6 ,
V_7 ,
1 ,
V_75 ,
L_14 ,
F_25 ( V_75 , V_91 , L_2 ) ,
V_75 ) ;
if ( V_75 >= V_92 )
return;
F_18 ( V_36 -> V_40 , V_41 , L_8 ,
F_25 ( V_75 , V_91 , L_2 ) ) ;
F_19 ( V_83 , L_6 ,
F_25 ( V_75 , V_91 , L_2 ) ) ;
if ( V_75 == V_93 )
{
V_7 += 1 ;
V_8 -= 1 ;
F_17 ( V_84 , V_6 , V_36 , V_7 , V_8 ) ;
}
else
{
F_27 ( V_84 ,
V_94 ,
V_6 ,
V_7 ,
1 ,
V_86 ) ;
V_7 += 1 ;
V_8 -= 1 ;
F_22 ( V_84 , V_6 , V_36 , V_75 , V_7 , V_8 ) ;
}
}
void F_28 ( void )
{
static T_11 V_95 [] =
{
{ & V_17 ,
{
L_15 ,
L_16 ,
V_96 ,
V_97 ,
NULL ,
0x0 ,
L_17 ,
V_98
}
} ,
{ & V_90 ,
{
L_18 ,
L_19 ,
V_99 ,
V_100 ,
F_29 ( V_101 ) ,
0x0 ,
L_20 ,
V_98
}
} ,
{ & V_94 ,
{
L_21 ,
L_22 ,
V_102 ,
V_103 ,
NULL ,
0x0 ,
L_23 ,
V_98
}
} ,
{ & V_11 ,
{
L_24 ,
L_25 ,
V_99 ,
V_97 ,
F_29 ( V_91 ) ,
0x0 ,
L_20 ,
V_98
}
} ,
{ & V_12 ,
{
L_26 ,
L_27 ,
V_99 ,
V_97 | V_104 ,
& V_77 ,
0x0 ,
L_28 ,
V_98
}
} ,
{ & V_39 ,
{
L_29 ,
L_30 ,
V_99 ,
V_97 | V_104 ,
& V_42 ,
0x0 ,
L_31 ,
V_98
}
} ,
{ & V_13 ,
{
L_32 ,
L_33 ,
V_96 ,
V_100 ,
NULL ,
0x0 ,
L_34 ,
V_98
}
} ,
{ & V_80 ,
{
L_35 ,
L_36 ,
V_99 ,
V_97 ,
NULL ,
0x0 ,
L_37 ,
V_98
}
} ,
{ & V_14 ,
{
L_38 ,
L_39 ,
V_99 ,
V_100 | V_104 ,
& V_105 ,
0x0 ,
L_40 ,
V_98
}
} ,
{ & V_26 ,
{
L_41 ,
L_42 ,
V_96 ,
V_97 ,
NULL ,
0x0 ,
L_43 ,
V_98
}
} ,
{ & V_9 ,
{
L_44 ,
L_45 ,
V_96 ,
V_97 | V_104 ,
& V_106 ,
0x0 ,
L_46 ,
V_98
}
} ,
{ & V_15 ,
{
L_47 ,
L_48 ,
V_99 ,
V_97 ,
NULL ,
0x0 ,
L_49 ,
V_98
}
} ,
{ & V_18 ,
{
L_50 ,
L_51 ,
V_107 ,
V_100 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_19 ,
{
L_52 ,
L_53 ,
V_108 ,
V_103 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_27 ,
{
L_50 ,
L_54 ,
V_99 ,
V_97 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_28 ,
{
L_50 ,
L_54 ,
V_96 ,
V_97 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_29 ,
{
L_50 ,
L_54 ,
V_109 ,
V_97 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_30 ,
{
L_50 ,
L_54 ,
V_107 ,
V_97 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_31 ,
{
L_50 ,
L_55 ,
V_108 ,
V_103 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_49 ,
{
L_50 ,
L_56 ,
V_99 ,
V_97 ,
F_29 ( V_110 ) ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_66 ,
{
L_57 ,
L_58 ,
V_99 ,
V_97 ,
F_29 ( V_101 ) ,
0x0 ,
NULL ,
V_98
}
} ,
{ & V_73 ,
{
L_59 ,
L_60 ,
V_107 ,
V_97 ,
NULL ,
0x0 ,
NULL ,
V_98
}
} ,
} ;
static T_9 * V_111 [] =
{
& V_88 ,
& V_24 ,
& V_35 ,
& V_112 ,
} ;
V_87 = F_30 ( L_61 , L_62 , L_63 ) ;
F_31 ( V_87 , V_95 , F_32 ( V_95 ) ) ;
F_33 ( L_63 , F_23 , V_87 ) ;
F_34 ( V_111 , F_32 ( V_111 ) ) ;
}
void F_35 ( void )
{
#if 0
dissector_handle_t handle_noe = find_dissector("noe");
dissector_add_uint("ua.opcode", 0x15, handle_noe);
#endif
}
