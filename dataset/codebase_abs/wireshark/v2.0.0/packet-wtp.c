static void
F_1 ( void )
{
F_2 ( & V_1 ,
& V_2 ) ;
}
static void
F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static char F_5 ( unsigned char V_3 )
{
switch ( F_6 ( V_3 ) ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
return V_3 & 0x01 ;
default:
return 0 ;
}
}
static void
F_7 ( T_1 * V_10 , T_2 * V_11 )
{
int V_12 = 0 ;
unsigned char V_13 ;
unsigned char V_14 ;
unsigned char V_15 ;
T_1 * V_16 = NULL ;
T_3 * V_17 ;
V_13 = F_8 ( V_11 , V_12 ++ ) ;
V_14 = ( V_13 & 0x78 ) >> 3 ;
if ( V_13 & 0x04 )
V_15 = F_8 ( V_11 , V_12 ++ ) ;
else
V_15 = V_13 & 0x03 ;
V_17 = F_9 ( V_10 , V_18 ,
V_11 , 0 , F_10 ( V_11 ) , V_14 ) ;
V_16 = F_11 ( V_17 , V_19 ) ;
switch ( V_14 ) {
case 0x00 :
break;
case 0x01 :
F_12 ( V_16 , V_20 ,
V_11 , V_12 , V_15 , V_21 ) ;
break;
case 0x02 :
F_12 ( V_16 , V_22 ,
V_11 , V_12 ++ , 1 , V_23 ) ;
F_12 ( V_16 , V_24 ,
V_11 , V_12 , V_15 - 1 , V_21 ) ;
break;
case 0x03 :
F_12 ( V_16 , V_25 ,
V_11 , V_12 , 1 , V_23 ) ;
break;
case 0x04 :
break;
case 0x05 :
break;
default:
break;
}
}
static void
F_13 ( T_2 * V_11 , T_4 * V_26 , T_1 * V_10 )
{
char * V_27 ;
int V_28 = 0 ;
T_5 V_29 , V_30 = 0 ;
unsigned char V_31 ;
unsigned char V_32 ;
unsigned char V_33 ;
unsigned char V_34 = '\0' ;
T_6 V_35 = 0 ;
T_6 V_36 = 0 ;
int V_37 = 0 ;
T_3 * V_38 = NULL ;
T_1 * V_39 = NULL ;
char V_40 ;
char V_41 = 3 ;
int V_42 = 0 ;
int V_43 ;
T_2 * V_44 = NULL ;
T_7 V_45 = 0 ;
T_8 V_46 = 0 ;
int V_47 ;
T_5 V_48 ;
#define F_14 256
V_27 = ( char * ) F_15 ( F_16 () , F_14 ) ;
V_31 = F_8 ( V_11 , V_28 + 0 ) ;
if ( V_31 == 0 ) {
T_6 V_49 = 0 ;
T_6 V_50 = 0 ;
if ( V_10 ) {
V_38 = F_12 ( V_10 , V_51 ,
V_11 , V_28 , 1 , V_21 ) ;
V_39 = F_11 ( V_38 , V_52 ) ;
F_17 ( V_38 , L_1 ) ;
}
V_28 = 1 ;
V_43 = 1 ;
while ( V_28 < ( int ) F_18 ( V_11 ) ) {
T_2 * V_53 ;
V_31 = F_8 ( V_11 , V_28 + 0 ) ;
if ( V_31 & 0x80 ) {
V_49 = 2 ;
V_50 = ( ( V_31 & 0x7f ) << 8 ) | F_8 ( V_11 , V_28 + 1 ) ;
} else {
V_49 = 1 ;
V_50 = V_31 ;
}
if ( V_10 ) {
F_9 ( V_39 , V_54 ,
V_11 , V_28 , V_49 , V_50 ) ;
}
if ( V_43 > 1 ) {
F_19 ( V_26 -> V_55 , V_56 , L_2 ) ;
}
V_53 = F_20 ( V_11 , V_28 + V_49 , V_50 ) ;
F_13 ( V_53 , V_26 , V_39 ) ;
V_28 += V_49 + V_50 ;
V_43 ++ ;
}
if ( V_10 ) {
F_17 ( V_38 , L_3 , V_43 ) ;
}
return;
}
V_32 = V_31 & 0x80 ;
V_33 = F_5 ( V_31 ) ;
V_40 = F_6 ( V_31 ) ;
#ifdef F_21
printf ( L_4 ,
V_26 -> V_57 -> V_58 , V_10 ,
F_22 ( V_40 , V_59 , L_5 ) ,
V_40 , F_10 ( V_11 ) ) ;
#endif
V_29 = F_23 ( V_27 , F_14 , L_6 ,
F_22 ( V_40 , V_59 , L_5 ) ) ;
V_30 += F_24 ( V_29 , F_14 - V_30 ) ;
switch ( V_40 ) {
case V_4 :
V_34 = F_25 ( V_31 ) ;
V_46 = F_26 ( V_11 , V_28 + 1 ) ;
V_45 = 0 ;
V_41 = F_27 ( F_8 ( V_11 , V_28 + 3 ) ) ;
V_29 = F_23 ( & V_27 [ V_30 ] , F_14 - V_30 ,
L_7 , V_41 ) ;
V_30 += F_24 ( V_29 , F_14 - V_30 ) ;
V_35 = 4 ;
break;
case V_7 :
case V_8 :
V_34 = F_25 ( V_31 ) ;
V_46 = F_26 ( V_11 , V_28 + 1 ) ;
V_45 = F_8 ( V_11 , V_28 + 3 ) ;
if ( V_45 != 0 ) {
V_29 = F_23 ( & V_27 [ V_30 ] , F_14 - V_30 ,
L_8 , V_45 ) ;
V_30 += F_24 ( V_29 , F_14 - V_30 ) ;
}
V_35 = 4 ;
break;
case ABORT :
V_35 = 4 ;
break;
case V_5 :
V_34 = F_25 ( V_31 ) ;
V_46 = F_26 ( V_11 , V_28 + 1 ) ;
V_45 = 0 ;
V_35 = 3 ;
break;
case V_6 :
V_35 = 3 ;
break;
case V_9 :
V_42 = F_8 ( V_11 , V_28 + 3 ) ;
V_35 = V_42 + 4 ;
break;
default:
break;
} ;
if ( V_33 ) {
F_23 ( & V_27 [ V_30 ] , F_14 - V_30 , L_9 ) ;
} ;
if ( V_10 ) {
#ifdef F_21
fprintf ( V_60 , L_10 , V_35 ) ;
#endif
V_38 = F_12 ( V_10 , V_51 , V_11 , V_28 , 0 , V_21 ) ;
#ifdef F_21
fprintf ( V_60 , L_11 ) ;
#endif
V_39 = F_11 ( V_38 , V_61 ) ;
#ifdef F_21
fprintf ( V_60 , L_10 , V_35 ) ;
fprintf ( V_60 , L_12 , V_28 ) ;
#endif
F_12 (
V_39 ,
V_62 ,
V_11 ,
V_28 ,
1 ,
V_31
) ;
F_12 ( V_39 , V_63 , V_11 , V_28 , 1 , V_23 ) ;
switch( V_40 ) {
case V_4 :
F_12 ( V_39 , V_64 , V_11 , V_28 , 1 , V_23 ) ;
F_12 ( V_39 , V_65 , V_11 , V_28 , 1 , V_23 ) ;
F_12 ( V_39 , V_66 , V_11 , V_28 + 1 , 2 , V_67 ) ;
F_12 ( V_39 , V_68 , V_11 , V_28 + 1 , 2 , V_67 ) ;
F_12 ( V_39 , V_69 , V_11 , V_28 + 3 , 1 , V_23 ) ;
F_12 ( V_39 , V_70 , V_11 , V_28 + 3 , 1 , V_23 ) ;
F_12 ( V_39 , V_71 , V_11 , V_28 + 3 , 1 , V_23 ) ;
F_12 ( V_39 , V_72 , V_11 , V_28 + 3 , 1 , V_23 ) ;
F_12 ( V_39 , V_73 , V_11 , V_28 + 3 , 1 , V_23 ) ;
F_17 ( V_38 ,
L_13
L_14 ,
V_4 ,
F_28 ( V_41 , V_74 , L_15 ) ,
V_41 ) ;
break;
case V_5 :
F_12 ( V_39 , V_64 , V_11 , V_28 , 1 , V_23 ) ;
F_12 ( V_39 , V_65 , V_11 , V_28 , 1 , V_23 ) ;
F_12 ( V_39 , V_66 , V_11 , V_28 + 1 , 2 , V_67 ) ;
F_12 ( V_39 , V_68 , V_11 , V_28 + 1 , 2 , V_67 ) ;
F_17 ( V_38 , L_16 , V_5 ) ;
break;
case V_6 :
F_12 ( V_39 , V_75 , V_11 , V_28 , 1 , V_67 ) ;
F_12 ( V_39 , V_65 , V_11 , V_28 , 1 , V_23 ) ;
F_12 ( V_39 , V_66 , V_11 , V_28 + 1 , 2 , V_67 ) ;
F_12 ( V_39 , V_68 , V_11 , V_28 + 1 , 2 , V_67 ) ;
F_17 ( V_38 , L_17 , V_6 ) ;
break;
case ABORT :
V_37 = F_8 ( V_11 , V_28 ) & 0x07 ;
F_12 ( V_39 , V_76 , V_11 , V_28 , 1 , V_23 ) ;
F_12 ( V_39 , V_66 , V_11 , V_28 + 1 , 2 , V_67 ) ;
F_12 ( V_39 , V_68 , V_11 , V_28 + 1 , 2 , V_67 ) ;
if ( V_37 == V_77 ) {
T_7 V_78 = F_8 ( V_11 , V_28 + 3 ) ;
F_12 ( V_39 , V_79 , V_11 , V_28 + 3 , 1 , V_23 ) ;
F_17 ( V_38 ,
L_18
L_19
L_20 ,
ABORT ,
V_77 ,
F_28 ( V_78 , V_80 , L_15 ) ,
V_78 ) ;
}
else if ( V_37 == V_81 ) {
T_7 V_78 = F_8 ( V_11 , V_28 + 3 ) ;
F_12 ( V_39 , V_82 , V_11 , V_28 + 3 , 1 , V_23 ) ;
F_17 ( V_38 ,
L_18
L_21
L_20 ,
ABORT ,
V_77 ,
F_29 ( V_78 , & V_83 , L_15 ) ,
V_78 ) ;
}
break;
case V_7 :
F_12 ( V_39 , V_64 , V_11 , V_28 , 1 , V_23 ) ;
F_12 ( V_39 , V_65 , V_11 , V_28 , 1 , V_23 ) ;
F_12 ( V_39 , V_66 , V_11 , V_28 + 1 , 2 , V_67 ) ;
F_12 ( V_39 , V_68 , V_11 , V_28 + 1 , 2 , V_67 ) ;
F_12 ( V_39 , V_84 , V_11 , V_28 + 3 , 1 , V_23 ) ;
F_17 ( V_38 ,
L_22
L_23 ,
V_7 , V_45 ) ;
break;
case V_8 :
F_12 ( V_39 , V_64 , V_11 , V_28 , 1 , V_23 ) ;
F_12 ( V_39 , V_65 , V_11 , V_28 , 1 , V_23 ) ;
F_12 ( V_39 , V_66 , V_11 , V_28 + 1 , 2 , V_67 ) ;
F_12 ( V_39 , V_68 , V_11 , V_28 + 1 , 2 , V_67 ) ;
F_12 ( V_39 , V_84 , V_11 , V_28 + 3 , 1 , V_23 ) ;
F_17 ( V_38 ,
L_24
L_23 ,
V_8 , V_45 ) ;
break;
case V_9 :
F_12 ( V_39 , V_65 , V_11 , V_28 , 1 , V_23 ) ;
F_12 ( V_39 , V_66 , V_11 , V_28 + 1 , 2 , V_67 ) ;
F_12 ( V_39 , V_68 , V_11 , V_28 + 1 , 2 , V_67 ) ;
F_12 ( V_39 , V_85 , V_11 , V_28 + 3 , 1 , V_23 ) ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
{
F_12 ( V_39 , V_84 , V_11 , V_28 + 4 + V_43 , 1 , V_23 ) ;
}
F_17 ( V_38 ,
L_25
L_26 ,
V_9 , V_42 ) ;
break;
default:
break;
} ;
if ( V_33 ) {
F_17 ( V_38 , L_27 ) ;
}
} else {
#ifdef F_21
fprintf ( V_60 , L_28 , V_10 ) ;
#endif
}
if ( V_32 ) {
T_7 V_86 ;
T_7 V_13 ;
T_6 V_87 ;
T_2 * V_88 ;
V_36 = 0 ;
do {
V_13 = F_8 ( V_11 , V_28 + V_35 + V_36 ) ;
V_86 = V_13 & 0x80 ;
if ( V_13 & 0x04 )
V_87 = 2 + F_8 ( V_11 , V_28 + V_35 + V_36 + 1 ) ;
else
V_87 = 1 + ( V_13 & 0x03 ) ;
if ( V_10 )
{
V_88 = F_20 ( V_11 , V_28 + V_35 + V_36 , V_87 ) ;
F_7 ( V_39 , V_88 ) ;
}
V_36 += V_87 ;
} while ( V_86 );
} else {
}
if ( V_10 )
F_30 ( V_38 , V_35 + V_36 ) ;
#ifdef F_21
fprintf ( V_60 , L_10 , V_35 ) ;
#endif
V_47 = V_28 + V_35 + V_36 ;
V_48 = F_31 ( V_11 , V_47 ) ;
if ( ( V_48 >= 0 ) &&
! ( ( V_40 == V_6 ) || ( V_40 == V_9 ) || ( V_40 == ABORT ) ) )
{
if ( ( ( V_40 == V_7 ) || ( V_40 == V_8 )
|| ( ( ( V_40 == V_4 ) || ( V_40 == V_5 ) ) && ( ! V_34 ) )
) && F_32 ( V_11 , V_47 , V_48 ) )
{
T_9 * V_89 = NULL ;
T_10 V_90 = 0 ;
T_11 V_91 = V_26 -> V_92 ;
V_26 -> V_92 = TRUE ;
V_89 = F_33 ( & V_1 , V_11 , V_47 ,
V_26 , V_46 , NULL , V_45 , V_48 , ! V_34 , 0 ) ;
V_44 = F_34 ( V_11 , V_47 , V_26 ,
L_29 , V_89 , & V_93 ,
NULL , V_39 ) ;
#ifdef F_21
printf ( L_30 ,
V_26 -> V_57 -> V_58 ,
V_89 ? L_31 : L_32 ,
V_89 ? V_89 -> V_90 : - 1 ,
V_44 ,
V_89
) ;
#endif
if ( V_89 ) {
V_90 = V_89 -> V_90 ;
if ( V_26 -> V_57 -> V_58 == V_90 ) {
F_35 ( V_94 , V_44 , V_26 , V_10 ) ;
} else {
F_36 ( V_26 -> V_55 , V_56 ,
L_33 ,
V_27 , V_89 -> V_90 ) ;
F_12 ( V_39 , V_95 , V_11 , V_47 , - 1 , V_21 ) ;
}
} else {
F_36 ( V_26 -> V_55 , V_56 ,
L_34 ,
V_27 , V_45 ) ;
F_12 ( V_39 , V_95 , V_11 , V_47 , - 1 , V_21 ) ;
}
V_26 -> V_92 = V_91 ;
}
else if ( ( ( V_40 == V_4 ) || ( V_40 == V_5 ) ) && ( V_34 ) )
{
V_44 = F_37 ( V_11 , V_47 ) ;
F_35 ( V_94 , V_44 , V_26 , V_10 ) ;
}
else
{
F_19 ( V_26 -> V_55 , V_56 , V_27 ) ;
}
}
else
{
F_19 ( V_26 -> V_55 , V_56 , V_27 ) ;
}
}
static void
F_38 ( T_2 * V_11 , T_4 * V_26 , T_1 * V_10 )
{
F_39 ( V_26 -> V_55 , V_96 , L_35 ) ;
F_40 ( V_26 -> V_55 , V_56 ) ;
F_13 ( V_11 , V_26 , V_10 ) ;
}
static void
F_41 ( T_2 * V_11 , T_4 * V_26 , T_1 * V_10 )
{
F_39 ( V_26 -> V_55 , V_96 , L_36 ) ;
F_40 ( V_26 -> V_55 , V_56 ) ;
F_13 ( V_11 , V_26 , V_10 ) ;
}
void
F_42 ( void )
{
static T_12 V_97 [] = {
{ & V_54 ,
{ L_37 , L_38 ,
V_98 , V_99 , NULL , 0x0 ,
L_39 , V_100
}
} ,
{ & V_62 ,
{ L_40 , L_41 ,
V_101 , 8 , F_43 ( & V_102 ) , 0x80 ,
NULL , V_100
}
} ,
{ & V_63 ,
{ L_42 , L_43 ,
V_103 , V_104 , F_44 ( V_59 ) , 0x78 ,
NULL , V_100
}
} ,
{ & V_64 ,
{ L_44 , L_45 ,
V_103 , V_104 , F_44 ( V_105 ) , 0x06 ,
NULL , V_100
}
} ,
{ & V_65 ,
{ L_46 , L_47 ,
V_101 , 8 , F_43 ( & V_106 ) , 0x01 ,
NULL , V_100
}
} ,
{ & V_66 ,
{ L_48 , L_49 ,
V_101 , 16 , F_43 ( & V_107 ) , 0x8000 ,
NULL , V_100
}
} ,
{ & V_68 ,
{ L_50 , L_51 ,
V_98 , V_104 , NULL , 0x7FFF ,
NULL , V_100
}
} ,
{ & V_69 ,
{ L_52 , L_53 ,
V_103 , V_104 , F_44 ( V_108 ) , 0xC0 ,
NULL , V_100
}
} ,
{ & V_70 ,
{ L_54 , L_55 ,
V_101 , 8 , F_43 ( & V_109 ) , 0x20 ,
NULL , V_100
}
} ,
{ & V_71 ,
{ L_56 , L_57 ,
V_101 , 8 , F_43 ( & V_110 ) , 0x10 ,
NULL , V_100
}
} ,
{ & V_72 ,
{ L_58 , L_59 ,
V_103 , V_104 , NULL , 0x0C ,
NULL , V_100
}
} ,
{ & V_73 ,
{ L_60 , L_61 ,
V_103 , V_104 , F_44 ( V_74 ) , 0x03 ,
NULL , V_100
}
} ,
{ & V_75 ,
{ L_62 , L_63 ,
V_101 , 8 , F_43 ( & V_111 ) , 0x04 ,
NULL , V_100
}
} ,
{ & V_76 ,
{ L_64 , L_65 ,
V_103 , V_104 , F_44 ( V_112 ) , 0x07 ,
NULL , V_100
}
} ,
{ & V_79 ,
{ L_66 , L_67 ,
V_103 , V_104 , F_44 ( V_80 ) , 0x00 ,
NULL , V_100
}
} ,
{ & V_82 ,
{ L_66 , L_68 ,
V_103 , V_104 | V_113 , & V_83 , 0x00 ,
NULL , V_100
}
} ,
{ & V_84 ,
{ L_69 , L_70 ,
V_103 , V_99 , NULL , 0x00 ,
NULL , V_100
}
} ,
{ & V_85 ,
{ L_71 , L_72 ,
V_103 , V_99 , NULL , 0x00 ,
NULL , V_100
}
} ,
{ & V_95 ,
{ L_73 , L_74 ,
V_114 , V_115 , NULL , 0x00 ,
NULL , V_100
}
} ,
#if 0
{ &hf_wtp_header_variable_part,
{ "Header: Variable part", "wtp.header_variable_part",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Variable part of the header", HFILL
}
},
{ &hf_wtp_data,
{ "Data", "wtp.header_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ & V_18 ,
{ L_75 , L_76 ,
V_103 , V_104 , F_44 ( V_116 ) , 0x00 ,
L_77 , V_100
}
} ,
{ & V_25 ,
{ L_78 , L_79 ,
V_103 , V_99 , NULL , 0x00 ,
L_80 , V_100
}
} ,
{ & V_22 ,
{ L_81 , L_82 ,
V_103 , V_104 , F_44 ( V_117 ) , 0x00 ,
L_83 , V_100
}
} ,
{ & V_24 ,
{ L_84 , L_85 ,
V_118 , V_115 , NULL , 0x00 ,
L_86 , V_100
}
} ,
{ & V_20 ,
{ L_87 , L_88 ,
V_118 , V_115 , NULL , 0x00 ,
L_89 , V_100
}
} ,
{ & V_119 ,
{ L_90 , L_91 ,
V_101 , V_115 , NULL , 0x0 ,
L_92 , V_100
}
} ,
{ & V_120 ,
{ L_93 , L_94 ,
V_101 , V_115 , NULL , 0x0 ,
L_95 , V_100
}
} ,
{ & V_121 ,
{ L_96 , L_97 ,
V_101 , V_115 , NULL , 0x0 ,
L_98 , V_100
}
} ,
{ & V_122 ,
{ L_99 , L_100 ,
V_101 , V_115 , NULL , 0x0 ,
L_101 , V_100
}
} ,
{ & V_123 ,
{ L_102 , L_103 ,
V_124 , V_115 , NULL , 0x0 ,
L_104 , V_100
}
} ,
{ & V_125 ,
{ L_105 , L_106 ,
V_126 , V_99 , NULL , 0x0 ,
NULL , V_100
}
} ,
{ & V_127 ,
{ L_107 , L_108 ,
V_124 , V_115 , NULL , 0x0 ,
L_109 , V_100
}
} ,
{ & V_128 ,
{ L_110 , L_111 ,
V_126 , V_99 , NULL , 0x0 ,
L_112 , V_100
}
} ,
{ & V_129 ,
{ L_113 , L_114 ,
V_124 , V_115 , NULL , 0x0 ,
NULL , V_100
}
} ,
{ & V_130 ,
{ L_115 , L_116 ,
V_118 , V_115 , NULL , 0x0 ,
NULL , V_100
}
} ,
} ;
static T_5 * V_131 [] = {
& V_61 ,
& V_52 ,
& V_132 ,
& V_19 ,
& V_133 ,
& V_134 ,
} ;
V_51 = F_45 (
L_117 ,
L_118 ,
L_119
) ;
F_46 ( V_51 , V_97 , F_47 ( V_97 ) ) ;
F_48 ( V_131 , F_47 ( V_131 ) ) ;
F_49 ( L_120 , F_41 , V_51 ) ;
F_49 ( L_121 , F_38 , V_51 ) ;
F_50 ( F_1 ) ;
F_51 ( F_3 ) ;
}
void
F_52 ( void )
{
T_13 V_135 ;
V_94 = F_53 ( L_122 ) ;
V_135 = F_53 ( L_121 ) ;
F_54 ( L_123 , V_136 , V_135 ) ;
F_54 ( L_124 , V_136 , V_135 ) ;
F_54 ( L_125 , V_136 , V_135 ) ;
}
