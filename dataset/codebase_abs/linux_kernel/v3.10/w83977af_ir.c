static int T_1 F_1 ( void )
{
int V_1 ;
F_2 ( 0 , L_1 , V_2 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_3 ) && V_4 [ V_1 ] < 2000 ; V_1 ++ ) {
if ( F_4 ( V_1 , V_4 [ V_1 ] , V_5 [ V_1 ] , V_6 [ V_1 ] ) == 0 )
return 0 ;
}
return - V_7 ;
}
static void T_2 F_5 ( void )
{
int V_1 ;
F_2 ( 4 , L_1 , V_2 ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_3 ) ; V_1 ++ ) {
if ( V_3 [ V_1 ] )
F_6 ( V_3 [ V_1 ] ) ;
}
}
static int F_4 ( int V_1 , unsigned int V_8 , unsigned int V_5 ,
unsigned int V_6 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
F_2 ( 0 , L_1 , V_2 ) ;
if ( ! F_7 ( V_8 , V_14 , V_15 ) ) {
F_2 ( 0 , L_2 ,
V_2 , V_8 ) ;
return - V_7 ;
}
if ( F_8 ( V_8 , V_5 , V_6 ) == - 1 ) {
V_13 = - 1 ;
goto V_16;
}
V_10 = F_9 ( sizeof( struct V_11 ) ) ;
if ( V_10 == NULL ) {
F_10 ( V_17 L_3
L_4 ) ;
V_13 = - V_18 ;
goto V_16;
}
V_12 = F_11 ( V_10 ) ;
F_12 ( & V_12 -> V_19 ) ;
V_12 -> V_4 . V_20 = V_8 ;
V_12 -> V_4 . V_5 = V_5 ;
V_12 -> V_4 . V_21 = V_14 ;
V_12 -> V_4 . V_6 = V_6 ;
V_12 -> V_4 . V_22 = 32 ;
F_13 ( & V_12 -> V_23 ) ;
V_12 -> V_23 . V_24 . V_25 = V_26 | V_27 | V_28 | V_29 |
V_30 | V_31 | V_32 | ( V_33 << 8 ) ;
V_12 -> V_23 . V_34 . V_25 = V_35 ;
F_14 ( & V_12 -> V_23 ) ;
V_12 -> V_36 . V_37 = 14384 ;
V_12 -> V_38 . V_37 = 4000 ;
V_12 -> V_36 . V_39 =
F_15 ( NULL , V_12 -> V_36 . V_37 ,
& V_12 -> V_40 , V_41 | V_42 ) ;
if ( V_12 -> V_36 . V_39 == NULL ) {
V_13 = - V_18 ;
goto V_43;
}
V_12 -> V_38 . V_39 =
F_15 ( NULL , V_12 -> V_38 . V_37 ,
& V_12 -> V_44 , V_41 | V_42 ) ;
if ( V_12 -> V_38 . V_39 == NULL ) {
V_13 = - V_18 ;
goto V_45;
}
V_12 -> V_36 . V_46 = FALSE ;
V_12 -> V_36 . V_47 = V_48 ;
V_12 -> V_38 . V_49 = V_12 -> V_38 . V_39 ;
V_12 -> V_36 . V_49 = V_12 -> V_36 . V_39 ;
V_12 -> V_50 = V_10 ;
V_10 -> V_51 = & V_52 ;
V_13 = F_16 ( V_10 ) ;
if ( V_13 ) {
F_17 ( L_5 , V_2 ) ;
goto V_53;
}
F_18 ( L_6 , V_10 -> V_54 ) ;
V_3 [ V_1 ] = V_12 ;
return 0 ;
V_53:
F_19 ( NULL , V_12 -> V_38 . V_37 ,
V_12 -> V_38 . V_39 , V_12 -> V_44 ) ;
V_45:
F_19 ( NULL , V_12 -> V_36 . V_37 ,
V_12 -> V_36 . V_39 , V_12 -> V_40 ) ;
V_43:
F_20 ( V_10 ) ;
V_16:
F_21 ( V_8 , V_14 ) ;
return V_13 ;
}
static int F_6 ( struct V_11 * V_12 )
{
int V_8 ;
F_2 ( 0 , L_1 , V_2 ) ;
V_8 = V_12 -> V_4 . V_20 ;
#ifdef F_22
F_23 ( V_55 ) ;
F_24 ( V_56 , V_55 ) ;
F_25 ( 0x30 , 0x00 , V_55 ) ;
F_26 ( V_55 ) ;
#endif
F_27 ( V_12 -> V_50 ) ;
F_2 ( 0 , L_7 ,
V_2 , V_12 -> V_4 . V_20 ) ;
F_21 ( V_12 -> V_4 . V_20 , V_12 -> V_4 . V_21 ) ;
if ( V_12 -> V_38 . V_39 )
F_19 ( NULL , V_12 -> V_38 . V_37 ,
V_12 -> V_38 . V_39 , V_12 -> V_44 ) ;
if ( V_12 -> V_36 . V_39 )
F_19 ( NULL , V_12 -> V_36 . V_37 ,
V_12 -> V_36 . V_39 , V_12 -> V_40 ) ;
F_20 ( V_12 -> V_50 ) ;
return 0 ;
}
static int F_8 ( int V_8 , int V_5 , int V_6 )
{
int V_57 ;
int V_1 ;
for ( V_1 = 0 ; V_1 < 2 ; V_1 ++ ) {
F_2 ( 0 , L_1 , V_2 ) ;
#ifdef F_22
F_23 ( V_58 [ V_1 ] ) ;
F_24 ( V_56 , V_58 [ V_1 ] ) ;
F_25 ( 0x60 , ( V_8 >> 8 ) & 0xff , V_58 [ V_1 ] ) ;
F_25 ( 0x61 , ( V_8 ) & 0xff , V_58 [ V_1 ] ) ;
F_25 ( 0x70 , V_5 , V_58 [ V_1 ] ) ;
#ifdef F_28
F_25 ( 0x74 , V_6 + 1 , V_58 [ V_1 ] ) ;
#else
F_25 ( 0x74 , V_6 , V_58 [ V_1 ] ) ;
#endif
F_25 ( 0x75 , 0x04 , V_58 [ V_1 ] ) ;
F_25 ( 0xf0 , V_59 | V_60 , V_58 [ V_1 ] ) ;
F_25 ( 0x30 , 0x01 , V_58 [ V_1 ] ) ;
F_26 ( V_58 [ V_1 ] ) ;
#endif
F_29 ( V_8 , V_61 ) ;
F_30 ( V_8 + 2 , 0x00 ) ;
F_29 ( V_8 , V_62 ) ;
F_30 ( V_63 , V_8 + V_64 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( F_31 ( V_8 + V_65 ) | V_66 , V_8 + V_65 ) ;
F_29 ( V_8 , V_62 ) ;
F_30 ( V_67 , V_8 + V_64 ) ;
F_29 ( V_8 , V_68 ) ;
V_57 = F_31 ( V_8 + V_69 ) ;
if ( 0x10 == ( V_57 & 0xf0 ) ) {
V_55 = V_58 [ V_1 ] ;
F_29 ( V_8 , V_61 ) ;
F_30 ( V_70 | V_71 , V_8 + V_72 ) ;
F_29 ( V_8 , V_62 ) ;
F_30 ( V_73 | V_74 | V_75 | V_76 |
V_77 , V_8 + V_78 ) ;
F_29 ( V_8 , V_79 ) ;
F_30 ( 2048 & 0xff , V_8 + 6 ) ;
F_30 ( ( 2048 >> 8 ) & 0x1f , V_8 + 7 ) ;
F_29 ( V_8 , V_80 ) ;
F_30 ( 0x40 , V_8 + 7 ) ;
F_18 ( L_8
L_9 , V_57 ) ;
return 0 ;
} else {
F_2 ( 0 , L_10 , V_2 ) ;
}
}
return - 1 ;
}
static void F_32 ( struct V_11 * V_12 , T_3 V_81 )
{
int V_82 = V_67 ;
int V_8 ;
T_4 V_83 ;
V_8 = V_12 -> V_4 . V_20 ;
V_12 -> V_4 . V_81 = V_81 ;
V_83 = F_31 ( V_8 + V_84 ) ;
F_29 ( V_8 , V_62 ) ;
F_30 ( 0 , V_8 + V_85 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( 0x00 , V_8 + V_86 ) ;
switch ( V_81 ) {
case 9600 : F_30 ( 0x0c , V_8 + V_87 ) ; break;
case 19200 : F_30 ( 0x06 , V_8 + V_87 ) ; break;
case 38400 : F_30 ( 0x03 , V_8 + V_87 ) ; break;
case 57600 : F_30 ( 0x02 , V_8 + V_87 ) ; break;
case 115200 : F_30 ( 0x01 , V_8 + V_87 ) ; break;
case 576000 :
V_82 = V_88 ;
F_2 ( 0 , L_11 , V_2 ) ;
break;
case 1152000 :
V_82 = V_89 ;
F_2 ( 0 , L_12 , V_2 ) ;
break;
case 4000000 :
V_82 = V_90 ;
F_2 ( 0 , L_13 , V_2 ) ;
break;
default:
V_82 = V_90 ;
F_2 ( 0 , L_14 , V_2 , V_81 ) ;
break;
}
F_29 ( V_8 , V_62 ) ;
F_30 ( V_82 , V_8 + V_64 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( V_70 | V_71 , V_8 + V_72 ) ;
F_29 ( V_8 , V_62 ) ;
F_30 ( 0x00 , V_8 + V_78 ) ;
F_30 ( V_77 , V_8 + V_78 ) ;
F_30 ( 0xa7 , V_8 + V_78 ) ;
F_33 ( V_12 -> V_50 ) ;
F_29 ( V_8 , V_62 ) ;
if ( V_81 > V_91 ) {
F_30 ( V_92 , V_8 + V_85 ) ;
F_34 ( V_12 ) ;
} else
F_30 ( V_93 , V_8 + V_85 ) ;
F_30 ( V_83 , V_8 + V_84 ) ;
}
static T_5 F_35 ( struct V_94 * V_95 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 ;
T_6 V_81 ;
int V_8 ;
T_4 V_83 ;
int V_96 ;
V_12 = F_11 ( V_10 ) ;
V_8 = V_12 -> V_4 . V_20 ;
F_2 ( 4 , L_15 , V_2 , V_97 ,
( int ) V_95 -> V_98 ) ;
F_36 ( V_10 ) ;
V_81 = F_37 ( V_95 ) ;
if ( ( V_81 != V_12 -> V_4 . V_81 ) && ( V_81 != - 1 ) ) {
if ( ! V_95 -> V_98 ) {
F_32 ( V_12 , V_81 ) ;
F_38 ( V_95 ) ;
return V_99 ;
} else
V_12 -> V_100 = V_81 ;
}
V_83 = F_31 ( V_8 + V_84 ) ;
if ( V_12 -> V_4 . V_81 > V_91 ) {
V_12 -> V_38 . V_49 = V_12 -> V_38 . V_39 ;
F_39 ( V_95 , V_12 -> V_38 . V_49 , V_95 -> V_98 ) ;
V_12 -> V_38 . V_98 = V_95 -> V_98 ;
V_96 = F_40 ( V_95 ) ;
F_2 ( 4 , L_16 , V_2 , V_97 , V_96 ) ;
if ( V_96 )
F_41 ( V_96 ) ;
F_29 ( V_8 , V_62 ) ;
F_30 ( V_101 , V_8 + V_85 ) ;
F_42 ( V_12 , V_8 ) ;
} else {
V_12 -> V_38 . V_49 = V_12 -> V_38 . V_39 ;
V_12 -> V_38 . V_98 = F_43 ( V_95 , V_12 -> V_38 . V_49 ,
V_12 -> V_38 . V_37 ) ;
F_29 ( V_8 , V_62 ) ;
F_30 ( V_102 , V_8 + V_85 ) ;
}
F_38 ( V_95 ) ;
F_30 ( V_83 , V_8 + V_84 ) ;
return V_99 ;
}
static void F_42 ( struct V_11 * V_12 , int V_8 )
{
T_4 V_83 ;
#ifdef F_44
unsigned long V_103 ;
T_4 V_104 ;
#endif
F_2 ( 4 , L_17 , V_2 , V_12 -> V_38 . V_98 ) ;
V_83 = F_31 ( V_8 + V_84 ) ;
F_29 ( V_8 , V_62 ) ;
F_30 ( F_31 ( V_8 + V_64 ) & ~ V_105 , V_8 + V_64 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( V_106 | V_66 , V_8 + V_65 ) ;
#ifdef F_44
F_45 ( & V_12 -> V_19 , V_103 ) ;
F_46 ( V_12 -> V_4 . V_6 ) ;
F_47 ( V_12 -> V_4 . V_6 ) ;
F_48 ( V_12 -> V_4 . V_6 , V_107 ) ;
F_49 ( V_12 -> V_4 . V_6 , V_12 -> V_44 ) ;
F_50 ( V_12 -> V_4 . V_6 , V_12 -> V_38 . V_98 ) ;
#else
F_51 ( V_12 -> V_4 . V_6 , V_12 -> V_44 , V_12 -> V_38 . V_98 ,
V_108 ) ;
#endif
V_12 -> V_4 . V_109 = V_110 ;
F_29 ( V_8 , V_62 ) ;
#ifdef F_44
V_104 = F_31 ( V_8 + V_64 ) ;
F_30 ( V_104 | V_105 , V_8 + V_64 ) ;
F_52 ( V_12 -> V_4 . V_6 ) ;
F_53 ( & V_12 -> V_19 , V_103 ) ;
#else
F_30 ( F_31 ( V_8 + V_64 ) | V_105 | V_111 , V_8 + V_64 ) ;
#endif
F_30 ( V_83 , V_8 + V_84 ) ;
}
static int F_54 ( int V_8 , T_4 * V_112 , int V_98 , int V_22 )
{
int V_113 = 0 ;
T_4 V_83 ;
F_2 ( 4 , L_1 , V_2 ) ;
V_83 = F_31 ( V_8 + V_84 ) ;
F_29 ( V_8 , V_62 ) ;
if ( ! ( F_55 ( V_8 + V_114 ) & V_115 ) ) {
F_2 ( 4 ,
L_18 , V_2 ) ;
V_22 -= 17 ;
F_2 ( 4 , L_19 ,
V_2 , V_22 ) ;
}
while ( ( V_22 -- > 0 ) && ( V_113 < V_98 ) ) {
F_30 ( V_112 [ V_113 ++ ] , V_8 + V_116 ) ;
}
F_2 ( 4 , L_20 ,
V_2 , V_22 , V_113 , V_98 ) ;
F_30 ( V_83 , V_8 + V_84 ) ;
return V_113 ;
}
static void F_56 ( struct V_11 * V_12 )
{
int V_8 ;
T_4 V_83 ;
F_2 ( 4 , L_21 , V_2 , V_97 ) ;
F_57 (self != NULL, return;) ;
V_8 = V_12 -> V_4 . V_20 ;
V_83 = F_31 ( V_8 + V_84 ) ;
F_29 ( V_8 , V_62 ) ;
F_30 ( F_31 ( V_8 + V_64 ) & ~ V_105 , V_8 + V_64 ) ;
if ( F_31 ( V_8 + V_117 ) & V_118 ) {
F_2 ( 0 , L_22 , V_2 ) ;
V_12 -> V_50 -> V_119 . V_120 ++ ;
V_12 -> V_50 -> V_119 . V_121 ++ ;
F_30 ( V_118 , V_8 + V_117 ) ;
} else
V_12 -> V_50 -> V_119 . V_122 ++ ;
if ( V_12 -> V_100 ) {
F_32 ( V_12 , V_12 -> V_100 ) ;
V_12 -> V_100 = 0 ;
}
F_33 ( V_12 -> V_50 ) ;
F_30 ( V_83 , V_8 + V_84 ) ;
}
static int F_34 ( struct V_11 * V_12 )
{
int V_8 ;
T_4 V_83 ;
#ifdef F_58
unsigned long V_103 ;
T_4 V_104 ;
#endif
F_57 (self != NULL, return -1;) ;
F_2 ( 4 , L_23 , V_2 ) ;
V_8 = V_12 -> V_4 . V_20 ;
V_83 = F_31 ( V_8 + V_84 ) ;
F_29 ( V_8 , V_62 ) ;
F_30 ( F_31 ( V_8 + V_64 ) & ~ V_105 , V_8 + V_64 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( ( F_31 ( V_8 + V_65 ) & ~ V_106 ) | V_66 ,
V_8 + V_65 ) ;
V_12 -> V_4 . V_109 = V_123 ;
V_12 -> V_36 . V_49 = V_12 -> V_36 . V_39 ;
#ifdef F_58
F_45 ( & V_12 -> V_19 , V_103 ) ;
F_46 ( V_12 -> V_4 . V_6 ) ;
F_47 ( V_12 -> V_4 . V_6 ) ;
F_48 ( V_12 -> V_4 . V_6 , V_107 ) ;
F_49 ( V_12 -> V_4 . V_6 , V_12 -> V_40 ) ;
F_50 ( V_12 -> V_4 . V_6 , V_12 -> V_36 . V_37 ) ;
#else
F_51 ( V_12 -> V_4 . V_6 , V_12 -> V_40 , V_12 -> V_36 . V_37 ,
V_107 ) ;
#endif
F_29 ( V_8 , V_62 ) ;
F_30 ( V_73 | V_74 | V_76 | V_77 , V_8 + V_78 ) ;
V_12 -> V_124 . V_98 = V_12 -> V_124 . V_125 = V_12 -> V_124 . V_39 = 0 ;
F_29 ( V_8 , V_62 ) ;
#ifdef F_58
V_104 = F_31 ( V_8 + V_64 ) ;
F_30 ( V_104 | V_105 , V_8 + V_64 ) ;
F_52 ( V_12 -> V_4 . V_6 ) ;
F_53 ( & V_12 -> V_19 , V_103 ) ;
#else
F_30 ( F_31 ( V_8 + V_64 ) | V_105 , V_8 + V_64 ) ;
#endif
F_30 ( V_83 , V_8 + V_84 ) ;
return 0 ;
}
static int F_59 ( struct V_11 * V_12 )
{
struct V_94 * V_95 ;
struct V_124 * V_124 ;
int V_98 ;
int V_8 ;
T_4 V_83 ;
T_4 V_126 ;
F_2 ( 4 , L_23 , V_2 ) ;
V_124 = & V_12 -> V_124 ;
V_8 = V_12 -> V_4 . V_20 ;
V_83 = F_31 ( V_8 + V_84 ) ;
V_8 = V_12 -> V_4 . V_20 ;
F_29 ( V_8 , V_127 ) ;
while ( ( V_126 = F_31 ( V_8 + V_128 ) ) & V_129 ) {
V_124 -> V_130 [ V_124 -> V_125 ] . V_126 = V_126 ;
V_124 -> V_130 [ V_124 -> V_125 ] . V_98 = F_31 ( V_8 + V_131 ) ;
V_124 -> V_130 [ V_124 -> V_125 ] . V_98 |= F_31 ( V_8 + V_132 ) << 8 ;
V_124 -> V_125 ++ ;
V_124 -> V_98 ++ ;
}
while ( V_124 -> V_98 ) {
V_126 = V_124 -> V_130 [ V_124 -> V_39 ] . V_126 ;
V_98 = V_124 -> V_130 [ V_124 -> V_39 ] . V_98 ;
V_124 -> V_39 ++ ;
V_124 -> V_98 -- ;
if ( V_126 & V_133 ) {
if ( V_126 & V_134 ) {
V_12 -> V_50 -> V_119 . V_135 += V_98 ;
} else {
V_12 -> V_50 -> V_119 . V_135 ++ ;
V_12 -> V_36 . V_49 += V_98 ;
if ( V_126 & V_136 )
V_12 -> V_50 -> V_119 . V_137 ++ ;
if ( V_126 & V_138 )
V_12 -> V_50 -> V_119 . V_139 ++ ;
if ( V_126 & V_140 )
V_12 -> V_50 -> V_119 . V_141 ++ ;
}
if ( V_126 & V_142 )
V_12 -> V_50 -> V_119 . V_143 ++ ;
if ( V_126 & V_144 )
V_12 -> V_50 -> V_119 . V_143 ++ ;
} else {
F_29 ( V_8 , V_62 ) ;
if ( F_31 ( V_8 + V_114 ) & V_145 ) {
F_41 ( 80 ) ;
}
V_95 = F_60 ( V_98 + 1 ) ;
if ( V_95 == NULL ) {
F_10 ( V_146
L_24 , V_2 ) ;
F_30 ( V_83 , V_8 + V_84 ) ;
return FALSE ;
}
F_61 ( V_95 , 1 ) ;
if ( V_12 -> V_4 . V_81 < 4000000 ) {
F_62 ( V_95 , V_98 - 2 ) ;
F_63 ( V_95 ,
V_12 -> V_36 . V_49 ,
V_98 - 2 ) ;
} else {
F_62 ( V_95 , V_98 - 4 ) ;
F_63 ( V_95 ,
V_12 -> V_36 . V_49 ,
V_98 - 4 ) ;
}
V_12 -> V_36 . V_49 += V_98 ;
V_12 -> V_50 -> V_119 . V_147 ++ ;
V_95 -> V_10 = V_12 -> V_50 ;
F_64 ( V_95 ) ;
V_95 -> V_148 = F_65 ( V_149 ) ;
F_66 ( V_95 ) ;
}
}
F_30 ( V_83 , V_8 + V_84 ) ;
return TRUE ;
}
static void F_67 ( struct V_11 * V_12 )
{
T_4 V_150 = 0x00 ;
int V_8 ;
F_2 ( 4 , L_1 , V_2 ) ;
F_57 (self != NULL, return;) ;
V_8 = V_12 -> V_4 . V_20 ;
do {
V_150 = F_31 ( V_8 + V_151 ) ;
F_68 ( V_12 -> V_50 , & V_12 -> V_50 -> V_119 , & V_12 -> V_36 ,
V_150 ) ;
} while ( F_31 ( V_8 + V_114 ) & V_145 );
}
static T_4 F_69 ( struct V_11 * V_12 , int V_152 )
{
int V_113 ;
T_4 V_153 = 0 ;
T_4 V_83 ;
int V_8 ;
F_2 ( 4 , L_25 , V_2 , V_152 ) ;
V_8 = V_12 -> V_4 . V_20 ;
if ( V_152 & V_154 ) {
V_113 = F_54 ( V_12 -> V_4 . V_20 ,
V_12 -> V_38 . V_49 ,
V_12 -> V_38 . V_98 ,
V_12 -> V_4 . V_22 ) ;
V_12 -> V_38 . V_49 += V_113 ;
V_12 -> V_38 . V_98 -= V_113 ;
V_12 -> V_4 . V_109 = V_110 ;
if ( V_12 -> V_38 . V_98 > 0 ) {
V_153 |= V_102 ;
} else {
V_83 = F_31 ( V_8 + V_84 ) ;
F_29 ( V_8 , V_62 ) ;
F_30 ( V_155 , V_8 + V_117 ) ;
F_30 ( V_83 , V_8 + V_84 ) ;
V_12 -> V_50 -> V_119 . V_122 ++ ;
F_33 ( V_12 -> V_50 ) ;
V_153 |= V_156 ;
}
}
if ( V_152 & V_157 ) {
if ( V_12 -> V_100 ) {
F_2 ( 2 ,
L_26 , V_2 ) ;
F_32 ( V_12 , V_12 -> V_100 ) ;
V_12 -> V_100 = 0 ;
}
V_12 -> V_4 . V_109 = V_123 ;
V_153 |= V_93 ;
}
if ( V_152 & V_158 ) {
F_67 ( V_12 ) ;
V_153 |= V_93 ;
}
return V_153 ;
}
static T_4 F_70 ( struct V_11 * V_12 , int V_152 )
{
T_4 V_153 = 0 ;
T_4 V_83 ;
int V_8 ;
V_8 = V_12 -> V_4 . V_20 ;
V_83 = F_31 ( V_8 + V_84 ) ;
if ( V_152 & ( V_159 | V_160 ) ) {
if ( F_59 ( V_12 ) ) {
V_153 |= V_92 ;
} else {
F_29 ( V_8 , V_79 ) ;
F_30 ( 0x01 , V_8 + V_161 ) ;
F_30 ( 0x00 , V_8 + V_162 ) ;
F_30 ( V_163 , V_8 + V_164 ) ;
V_153 |= V_165 ;
}
}
if ( V_152 & V_166 ) {
F_29 ( V_8 , V_79 ) ;
F_30 ( 0 , V_8 + V_164 ) ;
if ( V_12 -> V_4 . V_109 == V_110 ) {
F_42 ( V_12 , V_8 ) ;
V_153 |= V_101 ;
} else {
F_59 ( V_12 ) ;
V_153 |= V_92 ;
}
}
if ( V_152 & V_167 ) {
F_56 ( V_12 ) ;
F_34 ( V_12 ) ;
V_153 = V_92 ;
}
F_30 ( V_83 , V_8 + V_84 ) ;
return V_153 ;
}
static T_7 F_71 ( int V_5 , void * V_168 )
{
struct V_9 * V_10 = V_168 ;
struct V_11 * V_12 ;
T_4 V_83 , V_169 , V_152 ;
int V_8 ;
V_12 = F_11 ( V_10 ) ;
V_8 = V_12 -> V_4 . V_20 ;
V_83 = F_31 ( V_8 + V_84 ) ;
F_29 ( V_8 , V_62 ) ;
V_169 = F_31 ( V_8 + V_85 ) ;
V_152 = F_31 ( V_8 + V_170 ) & V_169 ;
F_30 ( 0 , V_8 + V_85 ) ;
if ( V_152 ) {
if ( V_12 -> V_4 . V_81 > V_91 )
V_169 = F_70 ( V_12 , V_152 ) ;
else
V_169 = F_69 ( V_12 , V_152 ) ;
}
F_30 ( V_169 , V_8 + V_85 ) ;
F_30 ( V_83 , V_8 + V_84 ) ;
return F_72 ( V_152 ) ;
}
static int F_73 ( struct V_11 * V_12 )
{
int V_126 = FALSE ;
int V_8 ;
T_4 V_83 ;
F_57 (self != NULL, return FALSE;) ;
if ( V_12 -> V_4 . V_81 > 115200 ) {
V_8 = V_12 -> V_4 . V_20 ;
V_83 = F_31 ( V_8 + V_84 ) ;
F_29 ( V_8 , V_61 ) ;
if ( ( F_31 ( V_8 + V_171 ) & 0x3f ) != 0 ) {
V_126 = TRUE ;
}
F_30 ( V_83 , V_8 + V_84 ) ;
} else
V_126 = ( V_12 -> V_36 . V_47 != V_48 ) ;
return V_126 ;
}
static int F_74 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_8 ;
char V_172 [ 32 ] ;
T_4 V_83 ;
F_2 ( 0 , L_1 , V_2 ) ;
F_57 (dev != NULL, return -1;) ;
V_12 = F_11 ( V_10 ) ;
F_57 (self != NULL, return 0;) ;
V_8 = V_12 -> V_4 . V_20 ;
if ( F_75 ( V_12 -> V_4 . V_5 , F_71 , 0 , V_10 -> V_54 ,
( void * ) V_10 ) ) {
return - V_173 ;
}
if ( F_76 ( V_12 -> V_4 . V_6 , V_10 -> V_54 ) ) {
F_77 ( V_12 -> V_4 . V_5 , V_10 ) ;
return - V_173 ;
}
V_83 = F_31 ( V_8 + V_84 ) ;
F_29 ( V_8 , V_62 ) ;
if ( V_12 -> V_4 . V_81 > 115200 ) {
F_30 ( V_92 , V_8 + V_85 ) ;
F_34 ( V_12 ) ;
} else
F_30 ( V_93 , V_8 + V_85 ) ;
F_30 ( V_83 , V_8 + V_84 ) ;
F_78 ( V_10 ) ;
sprintf ( V_172 , L_27 , V_12 -> V_4 . V_20 ) ;
V_12 -> V_174 = F_79 ( V_10 , & V_12 -> V_23 , V_172 ) ;
return 0 ;
}
static int F_80 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_8 ;
T_4 V_83 ;
F_2 ( 0 , L_1 , V_2 ) ;
F_57 (dev != NULL, return -1;) ;
V_12 = F_11 ( V_10 ) ;
F_57 (self != NULL, return 0;) ;
V_8 = V_12 -> V_4 . V_20 ;
F_36 ( V_10 ) ;
if ( V_12 -> V_174 )
F_81 ( V_12 -> V_174 ) ;
V_12 -> V_174 = NULL ;
F_46 ( V_12 -> V_4 . V_6 ) ;
V_83 = F_31 ( V_8 + V_84 ) ;
F_29 ( V_8 , V_62 ) ;
F_30 ( 0 , V_8 + V_85 ) ;
F_77 ( V_12 -> V_4 . V_5 , V_10 ) ;
F_82 ( V_12 -> V_4 . V_6 ) ;
F_30 ( V_83 , V_8 + V_84 ) ;
return 0 ;
}
static int F_83 ( struct V_9 * V_10 , struct V_175 * V_176 , int V_177 )
{
struct V_178 * V_5 = (struct V_178 * ) V_176 ;
struct V_11 * V_12 ;
unsigned long V_103 ;
int V_179 = 0 ;
F_57 (dev != NULL, return -1;) ;
V_12 = F_11 ( V_10 ) ;
F_57 (self != NULL, return -1;) ;
F_2 ( 2 , L_28 , V_2 , V_10 -> V_54 , V_177 ) ;
F_45 ( & V_12 -> V_19 , V_103 ) ;
switch ( V_177 ) {
case V_180 :
if ( ! F_84 ( V_181 ) ) {
V_179 = - V_182 ;
goto V_183;
}
F_32 ( V_12 , V_5 -> V_184 ) ;
break;
case V_185 :
if ( ! F_84 ( V_181 ) ) {
V_179 = - V_182 ;
goto V_183;
}
F_85 ( V_12 -> V_50 , TRUE ) ;
break;
case V_186 :
V_5 -> V_187 = F_73 ( V_12 ) ;
break;
default:
V_179 = - V_188 ;
}
V_183:
F_53 ( & V_12 -> V_19 , V_103 ) ;
return V_179 ;
}
