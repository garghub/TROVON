static T_1 F_1 ( T_2 * V_1 , T_3 V_2 , T_4 * V_3 )
{
T_1 V_4 = F_2 ( V_1 , V_2 ) ;
T_1 V_5 =
( V_4 >> 33 & 0x0007 ) << 30 |
( V_4 >> 17 & 0x7fff ) << 15 |
( V_4 >> 1 & 0x7fff ) << 0 ;
unsigned int V_6 = ( unsigned int ) ( V_5 % V_7 ) ;
V_3 -> V_8 = ( V_9 ) ( V_5 / V_7 ) ;
V_3 -> V_10 = ( int ) ( F_3 ( 1000000000 ) * V_6 / V_7 ) ;
return V_5 ;
}
static T_1 F_4 ( T_2 * V_1 , T_3 V_2 ,
T_4 * V_3 )
{
T_1 V_4 = F_5 ( V_1 , V_2 ) ;
T_1 V_5 =
( V_4 >> 43 & 0x0007 ) << 30 |
( V_4 >> 27 & 0x7fff ) << 15 |
( V_4 >> 11 & 0x7fff ) << 0 ;
unsigned int V_11 = ( unsigned int ) ( ( V_4 >> 1 ) & 0x1ff ) ;
T_1 V_12 = 300 * V_5 + V_11 ;
unsigned int V_6 = ( unsigned int ) ( V_12 % V_13 ) ;
V_3 -> V_8 = ( V_9 ) ( V_12 / V_13 ) ;
V_3 -> V_10 = ( int ) ( F_3 ( 1000000000 ) * V_6 / V_13 ) ;
return V_12 ;
}
static int
F_6 ( T_2 * V_1 , T_5 * T_6 V_14 ,
T_7 * V_15 , unsigned int V_16 )
{
T_8 * V_17 = F_7 ( V_15 , V_18 , V_1 ,
0 , - 1 , V_19 ) ;
T_7 * V_20 = F_8 ( V_17 , V_21 ) ;
T_3 V_2 = 0 ;
if ( V_16 & V_22 ) {
T_4 V_3 ;
F_1 ( V_1 , V_2 , & V_3 ) ;
F_9 ( V_20 , V_23 , V_1 ,
V_2 , 5 , & V_3 ) ;
V_2 += 5 ;
}
if ( V_16 & V_24 ) {
T_4 V_3 ;
F_1 ( V_1 , V_2 , & V_3 ) ;
F_9 ( V_20 , V_25 , V_1 ,
V_2 , 5 , & V_3 ) ;
V_2 += 5 ;
}
if ( V_16 & V_26 ) {
T_4 V_3 ;
F_4 ( V_1 , V_2 , & V_3 ) ;
F_9 ( V_20 , V_27 , V_1 ,
V_2 , 6 , & V_3 ) ;
V_2 += 6 ;
}
if ( V_16 & V_28 ) {
unsigned int V_29 = ( F_10 ( V_1 , V_2 ) >> 1 & 0x3fff ) * 50 ;
F_11 ( V_20 , V_30 , V_1 ,
V_2 , 3 , V_29 ) ;
V_2 += 3 ;
}
if ( V_16 & V_31 )
{
T_9 V_32 = F_12 ( V_1 , V_2 ) ;
T_9 V_33 ;
T_7 * V_34 ;
T_8 * V_35 ;
V_35 = F_7 ( V_17 ,
V_36 , V_1 ,
V_2 , 1 , V_19 ) ;
V_34 = F_8 ( V_35 ,
V_37 ) ;
V_33 = ( V_32 >> 5 ) ;
F_11 ( V_34 ,
V_38 , V_1 ,
V_2 , 1 ,
V_33 ) ;
if ( V_33 == V_39
|| V_33 == V_40 )
{
F_11 ( V_34 ,
V_41 , V_1 ,
V_2 , 1 ,
( V_32 & 0x18 ) >> 3 ) ;
F_11 ( V_34 ,
V_42 , V_1 ,
V_2 , 1 ,
( V_32 & 0x04 ) >> 2 ) ;
F_11 ( V_34 ,
V_43 , V_1 ,
V_2 , 1 ,
( V_32 & 0x03 ) ) ;
}
else if ( V_33 == V_44
|| V_33 == V_45 )
{
F_11 ( V_34 ,
V_46 , V_1 ,
V_2 , 1 ,
( V_32 & 0x1F ) ) ;
}
else if ( V_33 == V_47 )
{
F_11 ( V_34 ,
V_41 , V_1 ,
V_2 , 1 ,
( V_32 & 0x18 ) >> 3 ) ;
}
V_2 += 1 ;
}
if ( V_16 & V_48 ) {
F_7 ( V_20 , V_49 , V_1 ,
V_2 , 1 , V_50 ) ;
V_2 ++ ;
}
if ( V_16 & V_51 ) {
F_7 ( V_20 , V_52 , V_1 ,
V_2 , 2 , V_50 ) ;
V_2 += 2 ;
}
if ( V_16 & V_53 ) {
int V_54 = F_12 ( V_1 , V_2 ) ;
F_7 ( V_20 , V_55 , V_1 ,
V_2 , 1 , V_50 ) ;
V_2 ++ ;
if ( V_54 & V_56 ) {
F_7 ( V_20 , V_57 , V_1 ,
V_2 , 16 , V_19 ) ;
V_2 += 16 ;
}
if ( V_54 & V_58 ) {
F_7 ( V_20 , V_59 , V_1 ,
V_2 , 1 , V_50 ) ;
V_2 ++ ;
}
if ( V_54 & V_60 ) {
F_7 ( V_20 , V_61 , V_1 ,
V_2 , 2 , V_50 ) ;
V_2 += 2 ;
}
if ( V_54 & V_62 ) {
unsigned int V_63 = F_10 ( V_1 , V_2 ) ;
F_11 ( V_20 , V_64 , V_1 ,
V_2 , 2 , ( V_63 & 0x2000 ? 1024 : 128 ) * ( V_63 & 0x1ff ) ) ;
V_2 += 2 ;
}
if ( V_54 & V_65 ) {
F_7 ( V_20 , V_66 , V_1 ,
V_2 , 2 , V_50 ) ;
V_2 += 2 ;
}
}
return V_2 ;
}
static T_3
F_13 ( T_2 * V_1 , T_3 V_2 ,
T_5 * T_6 V_14 , T_7 * V_15 )
{
unsigned int V_67 , V_68 ;
T_8 * V_17 = F_7 ( V_15 , V_69 , V_1 ,
V_2 / 8 , 10 , V_19 ) ;
T_7 * V_20 = F_8 ( V_17 , V_70 ) ;
T_4 V_3 ;
F_4 ( V_1 , V_2 / 8 , & V_3 ) ;
F_9 ( V_20 , V_71 , V_1 , V_2 / 8 , 6 , & V_3 ) ;
V_2 += 6 * 8 ;
V_67 = ( F_14 ( V_1 , V_2 / 8 ) >> 2 ) * 50 ;
F_11 ( V_20 , V_72 , V_1 , V_2 / 8 , 3 ,
V_67 ) ;
V_2 += 3 * 8 ;
V_68 = F_12 ( V_1 , V_2 / 8 ) & 0x07 ;
F_7 ( V_20 , V_73 , V_1 ,
V_2 / 8 , 1 , V_50 ) ;
V_2 += 1 * 8 ;
if ( V_68 > 0 ) {
F_7 ( V_20 , V_74 , V_1 ,
V_2 / 8 , V_68 , V_19 ) ;
V_2 += V_68 * 8 ;
}
return V_2 ;
}
static T_10
F_15 ( T_2 * V_1 , T_5 * T_6 , T_7 * V_20 , void * T_11 V_14 )
{
int V_75 ;
int V_76 ;
T_12 V_77 ;
T_3 V_2 = 0 ;
if ( ! F_16 ( V_1 , 0 , 3 ) )
return FALSE ;
V_75 = F_14 ( V_1 , 0 ) ;
if ( V_75 != V_78 )
return FALSE ;
F_17 ( T_6 -> V_79 , V_80 , L_1 ) ;
F_18 ( T_6 -> V_79 , V_81 ) ;
V_76 = F_12 ( V_1 , 3 ) ;
F_19 ( T_6 -> V_79 , V_81 , L_2 , F_20 ( V_76 , V_82 , L_3 ) ) ;
#if 0
if (tree == NULL)
return TRUE;
#endif
F_21 ( & V_77 , V_83 , TRUE , T_6 ) ;
V_2 = F_22 ( V_1 , V_2 , & V_77 ,
V_20 , V_84 ) ;
if ( V_76 == V_85 ) {
int V_86 ;
V_86 = F_12 ( V_1 , 5 ) >> 3 & 0x07 ;
F_19 ( T_6 -> V_79 , V_81 , L_2 , F_20 ( V_86 , V_87 , L_4 ) ) ;
V_2 = F_23 ( V_1 , V_2 , & V_77 ,
V_20 , V_88 ) ;
F_7 ( V_20 , V_89 , V_1 ,
V_2 / 8 , - 1 , V_19 ) ;
} else if ( V_76 == V_90 ) {
T_2 * V_91 ;
V_2 = F_24 ( V_1 , V_2 , & V_77 ,
V_20 , V_92 ) ;
F_7 ( V_20 , V_93 , V_1 ,
V_2 / 8 , 64 , V_19 ) ;
V_2 += 64 * 8 ;
V_91 = F_25 ( V_1 , V_2 / 8 ) ;
F_15 ( V_91 , T_6 , V_20 , NULL ) ;
} else if ( V_76 == V_94 ) {
T_2 * V_91 ;
V_2 = F_26 ( V_1 , V_2 , & V_77 ,
V_20 , V_95 ) ;
V_91 = F_25 ( V_1 , V_2 / 8 ) ;
F_15 ( V_91 , T_6 , V_20 , NULL ) ;
} else if ( V_76 == V_96 ) {
T_2 * V_91 ;
V_2 = F_27 ( V_1 , V_2 , & V_77 ,
V_20 , V_97 ) ;
V_91 = F_25 ( V_1 , V_2 / 8 ) ;
F_15 ( V_91 , T_6 , V_20 , NULL ) ;
} else if ( V_76 == V_98 ) {
if ( F_12 ( V_1 , V_2 / 8 ) >> 6 == 1 ) {
F_13 ( V_1 , V_2 , T_6 , V_20 ) ;
} else {
F_7 ( V_20 , V_99 , V_1 ,
V_2 / 8 , 8 , V_19 ) ;
}
} else if ( V_76 == V_100 || V_76 == V_101 ) {
unsigned int V_102 = F_10 ( V_1 , V_2 / 8 ) ;
F_7 ( V_20 , V_103 , V_1 ,
V_2 / 8 , 2 , V_50 ) ;
V_2 += 2 * 8 ;
F_7 ( V_20 , V_99 , V_1 ,
V_2 / 8 , V_102 , V_19 ) ;
} else if ( V_76 == V_104 ) {
unsigned int V_105 = F_10 ( V_1 , V_2 / 8 ) ;
F_7 ( V_20 , V_103 , V_1 ,
V_2 / 8 , 2 , V_50 ) ;
V_2 += 2 * 8 ;
F_7 ( V_20 , V_106 , V_1 ,
V_2 / 8 , V_105 , V_19 ) ;
} else if ( V_76 == V_107
|| V_76 >= V_108 ) {
int V_109 = F_10 ( V_1 , 4 ) ;
if ( ( F_12 ( V_1 , 6 ) & 0xc0 ) == 0x80 ) {
int V_110 ;
T_2 * V_91 ;
V_2 = F_28 ( V_1 , V_2 , & V_77 ,
V_20 , V_111 ) ;
if( V_109 != 0 && V_76 != V_112 ) {
V_109 -= 5 ;
}
V_110 = F_12 ( V_1 , 8 ) ;
if ( V_110 > 0 ) {
int V_16 = F_12 ( V_1 , 7 ) ;
T_2 * V_113 = F_29 ( V_1 , V_2 / 8 ,
V_110 ) ;
F_6 ( V_113 , T_6 , V_20 , V_16 ) ;
V_2 += V_110 * 8 ;
if( V_109 != 0 && V_76 != V_112 ) {
V_109 -= V_110 ;
}
}
if( V_109 == 0 ) {
F_7 ( V_20 , V_99 , V_1 , ( V_2 >> 3 ) , - 1 , V_19 ) ;
return TRUE ;
}
V_91 = F_30 ( V_1 , V_2 / 8 , - 1 , V_109 ) ;
if ( F_14 ( V_91 , 0 ) == V_78 )
F_15 ( V_91 , T_6 , V_20 , NULL ) ;
else if ( F_12 ( V_91 , 0 ) == 0xff )
F_31 ( V_91 , T_6 , V_20 , T_11 ) ;
else
F_7 ( V_20 , V_99 , V_91 ,
0 , - 1 , V_19 ) ;
} else {
unsigned int V_102 = F_10 ( V_1 , V_2 / 8 ) ;
F_7 ( V_20 , V_103 , V_1 ,
V_2 / 8 , 2 , V_50 ) ;
V_2 += 2 * 8 ;
F_7 ( V_20 , V_99 , V_1 ,
V_2 / 8 , V_102 , V_19 ) ;
}
} else {
F_7 ( V_20 , V_99 , V_1 ,
V_2 / 8 , - 1 , V_19 ) ;
}
return TRUE ;
}
static int
F_31 ( T_2 * V_1 , T_5 * T_6 , T_7 * V_20 , void * T_11 V_14 )
{
T_13 * V_114 ;
if ( ! F_32 ( V_115 , V_1 , T_6 , V_20 , & V_114 , NULL ) ) {
F_17 ( T_6 -> V_79 , V_80 , L_5 ) ;
F_18 ( T_6 -> V_79 , V_81 ) ;
F_7 ( V_20 , V_116 , V_1 , 0 , - 1 , V_19 ) ;
}
return F_33 ( V_1 ) ;
}
void
F_34 ( void )
{
static T_14 V_117 [] = {
#include "packet-mpeg-pes-hfarr.c"
{ & V_69 ,
{ L_6 , L_7 ,
V_118 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_71 ,
{ L_8 , L_9 ,
V_121 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_72 ,
{ L_10 , L_11 ,
V_122 , V_123 , NULL , 0 , NULL , V_120 } } ,
{ & V_73 ,
{ L_12 , L_13 ,
V_124 , V_123 , NULL , 0x07 , NULL , V_120 } } ,
{ & V_74 ,
{ L_14 , L_15 ,
V_125 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_111 ,
{ L_16 , L_17 ,
V_118 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_18 ,
{ L_18 , L_19 ,
V_125 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_23 ,
{ L_20 , L_21 ,
V_121 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_25 ,
{ L_22 , L_23 ,
V_121 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_27 ,
{ L_24 , L_25 ,
V_121 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_30 ,
{ L_26 , L_27 ,
V_122 , V_123 , NULL , 0x7ffe , NULL , V_120 } } ,
{ & V_36 ,
{ L_28 , L_29 ,
V_125 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_38 ,
{ L_30 , L_31 ,
V_124 , V_126 , F_35 ( V_127 ) , 0 ,
L_32 , V_120 } } ,
{ & V_41 ,
{ L_33 , L_34 ,
V_124 , V_126 , F_35 ( V_128 ) , 0 ,
L_35 , V_120 } } ,
{ & V_42 ,
{ L_36 , L_37 ,
V_124 , V_126 , F_35 ( V_129 ) , 0 ,
L_38 , V_120 } } ,
{ & V_43 ,
{ L_39 , L_40 ,
V_124 , V_126 , F_35 ( V_130 ) , 0 ,
L_41 , V_120 } } ,
{ & V_46 ,
{ L_42 , L_43 ,
V_124 , V_126 , NULL , 0 , L_44 , V_120 } } ,
{ & V_49 ,
{ L_45 , L_46 ,
V_124 , V_123 , NULL , 0x7f , NULL , V_120 } } ,
{ & V_52 ,
{ L_47 , L_48 ,
V_131 , V_123 , NULL , 0 , NULL , V_120 } } ,
{ & V_55 ,
{ L_49 , L_50 ,
V_124 , V_126 , NULL , 0 , NULL , V_120 } } ,
{ & V_57 ,
{ L_51 , L_52 ,
V_125 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_59 ,
{ L_53 , L_54 ,
V_124 , V_123 , NULL , 0 , NULL , V_120 } } ,
{ & V_61 ,
{ L_55 , L_56 ,
V_131 , V_126 , NULL , 0 , NULL , V_120 } } ,
{ & V_64 ,
{ L_57 , L_58 ,
V_131 , V_123 , NULL , 0 , NULL , V_120 } } ,
{ & V_66 ,
{ L_59 , L_60 ,
V_131 , V_126 , NULL , 0 , NULL , V_120 } } ,
{ & V_106 ,
{ L_61 , L_62 ,
V_125 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_99 ,
{ L_63 , L_64 ,
V_125 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_92 ,
{ L_65 , L_66 ,
V_118 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_95 ,
{ L_67 , L_68 ,
V_118 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_97 ,
{ L_69 , L_70 ,
V_118 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_88 ,
{ L_71 , L_72 ,
V_118 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_93 ,
{ L_73 , L_74 ,
V_125 , V_119 , NULL , 0 , NULL , V_120 } } ,
{ & V_89 ,
{ L_75 , L_76 ,
V_125 , V_119 , NULL , 0 , NULL , V_120 } } ,
} ;
static T_3 * V_132 [] = {
#include "packet-mpeg-pes-ettarr.c"
& V_70 ,
& V_21 ,
& V_37
} ;
V_116 = F_36 (
L_77 , L_5 , L_78 ) ;
F_37 ( L_78 , F_31 , V_116 ) ;
V_115 = F_38 ( L_78 , V_116 ) ;
V_84 = F_36 (
L_79 , L_1 , L_80 ) ;
F_39 ( V_84 , V_117 , F_40 ( V_117 ) ) ;
F_41 ( V_132 , F_40 ( V_132 ) ) ;
F_37 ( L_80 , F_15 , V_84 ) ;
}
void
F_42 ( void )
{
T_15 V_133 = F_43 ( L_78 ) ;
F_44 ( L_81 , V_134 , V_133 ) ;
F_45 ( L_78 , F_15 , L_1 , L_82 , V_84 , V_135 ) ;
}
