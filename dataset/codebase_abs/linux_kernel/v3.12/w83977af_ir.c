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
& V_12 -> V_40 , V_41 ) ;
if ( V_12 -> V_36 . V_39 == NULL ) {
V_13 = - V_18 ;
goto V_42;
}
V_12 -> V_38 . V_39 =
F_15 ( NULL , V_12 -> V_38 . V_37 ,
& V_12 -> V_43 , V_41 ) ;
if ( V_12 -> V_38 . V_39 == NULL ) {
V_13 = - V_18 ;
goto V_44;
}
V_12 -> V_36 . V_45 = FALSE ;
V_12 -> V_36 . V_46 = V_47 ;
V_12 -> V_38 . V_48 = V_12 -> V_38 . V_39 ;
V_12 -> V_36 . V_48 = V_12 -> V_36 . V_39 ;
V_12 -> V_49 = V_10 ;
V_10 -> V_50 = & V_51 ;
V_13 = F_16 ( V_10 ) ;
if ( V_13 ) {
F_17 ( L_5 , V_2 ) ;
goto V_52;
}
F_18 ( L_6 , V_10 -> V_53 ) ;
V_3 [ V_1 ] = V_12 ;
return 0 ;
V_52:
F_19 ( NULL , V_12 -> V_38 . V_37 ,
V_12 -> V_38 . V_39 , V_12 -> V_43 ) ;
V_44:
F_19 ( NULL , V_12 -> V_36 . V_37 ,
V_12 -> V_36 . V_39 , V_12 -> V_40 ) ;
V_42:
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
F_23 ( V_54 ) ;
F_24 ( V_55 , V_54 ) ;
F_25 ( 0x30 , 0x00 , V_54 ) ;
F_26 ( V_54 ) ;
#endif
F_27 ( V_12 -> V_49 ) ;
F_2 ( 0 , L_7 ,
V_2 , V_12 -> V_4 . V_20 ) ;
F_21 ( V_12 -> V_4 . V_20 , V_12 -> V_4 . V_21 ) ;
if ( V_12 -> V_38 . V_39 )
F_19 ( NULL , V_12 -> V_38 . V_37 ,
V_12 -> V_38 . V_39 , V_12 -> V_43 ) ;
if ( V_12 -> V_36 . V_39 )
F_19 ( NULL , V_12 -> V_36 . V_37 ,
V_12 -> V_36 . V_39 , V_12 -> V_40 ) ;
F_20 ( V_12 -> V_49 ) ;
return 0 ;
}
static int F_8 ( int V_8 , int V_5 , int V_6 )
{
int V_56 ;
int V_1 ;
for ( V_1 = 0 ; V_1 < 2 ; V_1 ++ ) {
F_2 ( 0 , L_1 , V_2 ) ;
#ifdef F_22
F_23 ( V_57 [ V_1 ] ) ;
F_24 ( V_55 , V_57 [ V_1 ] ) ;
F_25 ( 0x60 , ( V_8 >> 8 ) & 0xff , V_57 [ V_1 ] ) ;
F_25 ( 0x61 , ( V_8 ) & 0xff , V_57 [ V_1 ] ) ;
F_25 ( 0x70 , V_5 , V_57 [ V_1 ] ) ;
#ifdef F_28
F_25 ( 0x74 , V_6 + 1 , V_57 [ V_1 ] ) ;
#else
F_25 ( 0x74 , V_6 , V_57 [ V_1 ] ) ;
#endif
F_25 ( 0x75 , 0x04 , V_57 [ V_1 ] ) ;
F_25 ( 0xf0 , V_58 | V_59 , V_57 [ V_1 ] ) ;
F_25 ( 0x30 , 0x01 , V_57 [ V_1 ] ) ;
F_26 ( V_57 [ V_1 ] ) ;
#endif
F_29 ( V_8 , V_60 ) ;
F_30 ( V_8 + 2 , 0x00 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( V_62 , V_8 + V_63 ) ;
F_29 ( V_8 , V_60 ) ;
F_30 ( F_31 ( V_8 + V_64 ) | V_65 , V_8 + V_64 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( V_66 , V_8 + V_63 ) ;
F_29 ( V_8 , V_67 ) ;
V_56 = F_31 ( V_8 + V_68 ) ;
if ( 0x10 == ( V_56 & 0xf0 ) ) {
V_54 = V_57 [ V_1 ] ;
F_29 ( V_8 , V_60 ) ;
F_30 ( V_69 | V_70 , V_8 + V_71 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( V_72 | V_73 | V_74 | V_75 |
V_76 , V_8 + V_77 ) ;
F_29 ( V_8 , V_78 ) ;
F_30 ( 2048 & 0xff , V_8 + 6 ) ;
F_30 ( ( 2048 >> 8 ) & 0x1f , V_8 + 7 ) ;
F_29 ( V_8 , V_79 ) ;
F_30 ( 0x40 , V_8 + 7 ) ;
F_18 ( L_8
L_9 , V_56 ) ;
return 0 ;
} else {
F_2 ( 0 , L_10 , V_2 ) ;
}
}
return - 1 ;
}
static void F_32 ( struct V_11 * V_12 , T_3 V_80 )
{
int V_81 = V_66 ;
int V_8 ;
T_4 V_82 ;
V_8 = V_12 -> V_4 . V_20 ;
V_12 -> V_4 . V_80 = V_80 ;
V_82 = F_31 ( V_8 + V_83 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( 0 , V_8 + V_84 ) ;
F_29 ( V_8 , V_60 ) ;
F_30 ( 0x00 , V_8 + V_85 ) ;
switch ( V_80 ) {
case 9600 : F_30 ( 0x0c , V_8 + V_86 ) ; break;
case 19200 : F_30 ( 0x06 , V_8 + V_86 ) ; break;
case 38400 : F_30 ( 0x03 , V_8 + V_86 ) ; break;
case 57600 : F_30 ( 0x02 , V_8 + V_86 ) ; break;
case 115200 : F_30 ( 0x01 , V_8 + V_86 ) ; break;
case 576000 :
V_81 = V_87 ;
F_2 ( 0 , L_11 , V_2 ) ;
break;
case 1152000 :
V_81 = V_88 ;
F_2 ( 0 , L_12 , V_2 ) ;
break;
case 4000000 :
V_81 = V_89 ;
F_2 ( 0 , L_13 , V_2 ) ;
break;
default:
V_81 = V_89 ;
F_2 ( 0 , L_14 , V_2 , V_80 ) ;
break;
}
F_29 ( V_8 , V_61 ) ;
F_30 ( V_81 , V_8 + V_63 ) ;
F_29 ( V_8 , V_60 ) ;
F_30 ( V_69 | V_70 , V_8 + V_71 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( 0x00 , V_8 + V_77 ) ;
F_30 ( V_76 , V_8 + V_77 ) ;
F_30 ( 0xa7 , V_8 + V_77 ) ;
F_33 ( V_12 -> V_49 ) ;
F_29 ( V_8 , V_61 ) ;
if ( V_80 > V_90 ) {
F_30 ( V_91 , V_8 + V_84 ) ;
F_34 ( V_12 ) ;
} else
F_30 ( V_92 , V_8 + V_84 ) ;
F_30 ( V_82 , V_8 + V_83 ) ;
}
static T_5 F_35 ( struct V_93 * V_94 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 ;
T_6 V_80 ;
int V_8 ;
T_4 V_82 ;
int V_95 ;
V_12 = F_11 ( V_10 ) ;
V_8 = V_12 -> V_4 . V_20 ;
F_2 ( 4 , L_15 , V_2 , V_96 ,
( int ) V_94 -> V_97 ) ;
F_36 ( V_10 ) ;
V_80 = F_37 ( V_94 ) ;
if ( ( V_80 != V_12 -> V_4 . V_80 ) && ( V_80 != - 1 ) ) {
if ( ! V_94 -> V_97 ) {
F_32 ( V_12 , V_80 ) ;
F_38 ( V_94 ) ;
return V_98 ;
} else
V_12 -> V_99 = V_80 ;
}
V_82 = F_31 ( V_8 + V_83 ) ;
if ( V_12 -> V_4 . V_80 > V_90 ) {
V_12 -> V_38 . V_48 = V_12 -> V_38 . V_39 ;
F_39 ( V_94 , V_12 -> V_38 . V_48 , V_94 -> V_97 ) ;
V_12 -> V_38 . V_97 = V_94 -> V_97 ;
V_95 = F_40 ( V_94 ) ;
F_2 ( 4 , L_16 , V_2 , V_96 , V_95 ) ;
if ( V_95 )
F_41 ( V_95 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( V_100 , V_8 + V_84 ) ;
F_42 ( V_12 , V_8 ) ;
} else {
V_12 -> V_38 . V_48 = V_12 -> V_38 . V_39 ;
V_12 -> V_38 . V_97 = F_43 ( V_94 , V_12 -> V_38 . V_48 ,
V_12 -> V_38 . V_37 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( V_101 , V_8 + V_84 ) ;
}
F_38 ( V_94 ) ;
F_30 ( V_82 , V_8 + V_83 ) ;
return V_98 ;
}
static void F_42 ( struct V_11 * V_12 , int V_8 )
{
T_4 V_82 ;
#ifdef F_44
unsigned long V_102 ;
T_4 V_103 ;
#endif
F_2 ( 4 , L_17 , V_2 , V_12 -> V_38 . V_97 ) ;
V_82 = F_31 ( V_8 + V_83 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( F_31 ( V_8 + V_63 ) & ~ V_104 , V_8 + V_63 ) ;
F_29 ( V_8 , V_60 ) ;
F_30 ( V_105 | V_65 , V_8 + V_64 ) ;
#ifdef F_44
F_45 ( & V_12 -> V_19 , V_102 ) ;
F_46 ( V_12 -> V_4 . V_6 ) ;
F_47 ( V_12 -> V_4 . V_6 ) ;
F_48 ( V_12 -> V_4 . V_6 , V_106 ) ;
F_49 ( V_12 -> V_4 . V_6 , V_12 -> V_43 ) ;
F_50 ( V_12 -> V_4 . V_6 , V_12 -> V_38 . V_97 ) ;
#else
F_51 ( V_12 -> V_4 . V_6 , V_12 -> V_43 , V_12 -> V_38 . V_97 ,
V_107 ) ;
#endif
V_12 -> V_4 . V_108 = V_109 ;
F_29 ( V_8 , V_61 ) ;
#ifdef F_44
V_103 = F_31 ( V_8 + V_63 ) ;
F_30 ( V_103 | V_104 , V_8 + V_63 ) ;
F_52 ( V_12 -> V_4 . V_6 ) ;
F_53 ( & V_12 -> V_19 , V_102 ) ;
#else
F_30 ( F_31 ( V_8 + V_63 ) | V_104 | V_110 , V_8 + V_63 ) ;
#endif
F_30 ( V_82 , V_8 + V_83 ) ;
}
static int F_54 ( int V_8 , T_4 * V_111 , int V_97 , int V_22 )
{
int V_112 = 0 ;
T_4 V_82 ;
F_2 ( 4 , L_1 , V_2 ) ;
V_82 = F_31 ( V_8 + V_83 ) ;
F_29 ( V_8 , V_61 ) ;
if ( ! ( F_55 ( V_8 + V_113 ) & V_114 ) ) {
F_2 ( 4 ,
L_18 , V_2 ) ;
V_22 -= 17 ;
F_2 ( 4 , L_19 ,
V_2 , V_22 ) ;
}
while ( ( V_22 -- > 0 ) && ( V_112 < V_97 ) ) {
F_30 ( V_111 [ V_112 ++ ] , V_8 + V_115 ) ;
}
F_2 ( 4 , L_20 ,
V_2 , V_22 , V_112 , V_97 ) ;
F_30 ( V_82 , V_8 + V_83 ) ;
return V_112 ;
}
static void F_56 ( struct V_11 * V_12 )
{
int V_8 ;
T_4 V_82 ;
F_2 ( 4 , L_21 , V_2 , V_96 ) ;
F_57 (self != NULL, return;) ;
V_8 = V_12 -> V_4 . V_20 ;
V_82 = F_31 ( V_8 + V_83 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( F_31 ( V_8 + V_63 ) & ~ V_104 , V_8 + V_63 ) ;
if ( F_31 ( V_8 + V_116 ) & V_117 ) {
F_2 ( 0 , L_22 , V_2 ) ;
V_12 -> V_49 -> V_118 . V_119 ++ ;
V_12 -> V_49 -> V_118 . V_120 ++ ;
F_30 ( V_117 , V_8 + V_116 ) ;
} else
V_12 -> V_49 -> V_118 . V_121 ++ ;
if ( V_12 -> V_99 ) {
F_32 ( V_12 , V_12 -> V_99 ) ;
V_12 -> V_99 = 0 ;
}
F_33 ( V_12 -> V_49 ) ;
F_30 ( V_82 , V_8 + V_83 ) ;
}
static int F_34 ( struct V_11 * V_12 )
{
int V_8 ;
T_4 V_82 ;
#ifdef F_58
unsigned long V_102 ;
T_4 V_103 ;
#endif
F_57 (self != NULL, return -1;) ;
F_2 ( 4 , L_23 , V_2 ) ;
V_8 = V_12 -> V_4 . V_20 ;
V_82 = F_31 ( V_8 + V_83 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( F_31 ( V_8 + V_63 ) & ~ V_104 , V_8 + V_63 ) ;
F_29 ( V_8 , V_60 ) ;
F_30 ( ( F_31 ( V_8 + V_64 ) & ~ V_105 ) | V_65 ,
V_8 + V_64 ) ;
V_12 -> V_4 . V_108 = V_122 ;
V_12 -> V_36 . V_48 = V_12 -> V_36 . V_39 ;
#ifdef F_58
F_45 ( & V_12 -> V_19 , V_102 ) ;
F_46 ( V_12 -> V_4 . V_6 ) ;
F_47 ( V_12 -> V_4 . V_6 ) ;
F_48 ( V_12 -> V_4 . V_6 , V_106 ) ;
F_49 ( V_12 -> V_4 . V_6 , V_12 -> V_40 ) ;
F_50 ( V_12 -> V_4 . V_6 , V_12 -> V_36 . V_37 ) ;
#else
F_51 ( V_12 -> V_4 . V_6 , V_12 -> V_40 , V_12 -> V_36 . V_37 ,
V_106 ) ;
#endif
F_29 ( V_8 , V_61 ) ;
F_30 ( V_72 | V_73 | V_75 | V_76 , V_8 + V_77 ) ;
V_12 -> V_123 . V_97 = V_12 -> V_123 . V_124 = V_12 -> V_123 . V_39 = 0 ;
F_29 ( V_8 , V_61 ) ;
#ifdef F_58
V_103 = F_31 ( V_8 + V_63 ) ;
F_30 ( V_103 | V_104 , V_8 + V_63 ) ;
F_52 ( V_12 -> V_4 . V_6 ) ;
F_53 ( & V_12 -> V_19 , V_102 ) ;
#else
F_30 ( F_31 ( V_8 + V_63 ) | V_104 , V_8 + V_63 ) ;
#endif
F_30 ( V_82 , V_8 + V_83 ) ;
return 0 ;
}
static int F_59 ( struct V_11 * V_12 )
{
struct V_93 * V_94 ;
struct V_123 * V_123 ;
int V_97 ;
int V_8 ;
T_4 V_82 ;
T_4 V_125 ;
F_2 ( 4 , L_23 , V_2 ) ;
V_123 = & V_12 -> V_123 ;
V_8 = V_12 -> V_4 . V_20 ;
V_82 = F_31 ( V_8 + V_83 ) ;
V_8 = V_12 -> V_4 . V_20 ;
F_29 ( V_8 , V_126 ) ;
while ( ( V_125 = F_31 ( V_8 + V_127 ) ) & V_128 ) {
V_123 -> V_129 [ V_123 -> V_124 ] . V_125 = V_125 ;
V_123 -> V_129 [ V_123 -> V_124 ] . V_97 = F_31 ( V_8 + V_130 ) ;
V_123 -> V_129 [ V_123 -> V_124 ] . V_97 |= F_31 ( V_8 + V_131 ) << 8 ;
V_123 -> V_124 ++ ;
V_123 -> V_97 ++ ;
}
while ( V_123 -> V_97 ) {
V_125 = V_123 -> V_129 [ V_123 -> V_39 ] . V_125 ;
V_97 = V_123 -> V_129 [ V_123 -> V_39 ] . V_97 ;
V_123 -> V_39 ++ ;
V_123 -> V_97 -- ;
if ( V_125 & V_132 ) {
if ( V_125 & V_133 ) {
V_12 -> V_49 -> V_118 . V_134 += V_97 ;
} else {
V_12 -> V_49 -> V_118 . V_134 ++ ;
V_12 -> V_36 . V_48 += V_97 ;
if ( V_125 & V_135 )
V_12 -> V_49 -> V_118 . V_136 ++ ;
if ( V_125 & V_137 )
V_12 -> V_49 -> V_118 . V_138 ++ ;
if ( V_125 & V_139 )
V_12 -> V_49 -> V_118 . V_140 ++ ;
}
if ( V_125 & V_141 )
V_12 -> V_49 -> V_118 . V_142 ++ ;
if ( V_125 & V_143 )
V_12 -> V_49 -> V_118 . V_142 ++ ;
} else {
F_29 ( V_8 , V_61 ) ;
if ( F_31 ( V_8 + V_113 ) & V_144 ) {
F_41 ( 80 ) ;
}
V_94 = F_60 ( V_97 + 1 ) ;
if ( V_94 == NULL ) {
F_10 ( V_145
L_24 , V_2 ) ;
F_30 ( V_82 , V_8 + V_83 ) ;
return FALSE ;
}
F_61 ( V_94 , 1 ) ;
if ( V_12 -> V_4 . V_80 < 4000000 ) {
F_62 ( V_94 , V_97 - 2 ) ;
F_63 ( V_94 ,
V_12 -> V_36 . V_48 ,
V_97 - 2 ) ;
} else {
F_62 ( V_94 , V_97 - 4 ) ;
F_63 ( V_94 ,
V_12 -> V_36 . V_48 ,
V_97 - 4 ) ;
}
V_12 -> V_36 . V_48 += V_97 ;
V_12 -> V_49 -> V_118 . V_146 ++ ;
V_94 -> V_10 = V_12 -> V_49 ;
F_64 ( V_94 ) ;
V_94 -> V_147 = F_65 ( V_148 ) ;
F_66 ( V_94 ) ;
}
}
F_30 ( V_82 , V_8 + V_83 ) ;
return TRUE ;
}
static void F_67 ( struct V_11 * V_12 )
{
T_4 V_149 = 0x00 ;
int V_8 ;
F_2 ( 4 , L_1 , V_2 ) ;
F_57 (self != NULL, return;) ;
V_8 = V_12 -> V_4 . V_20 ;
do {
V_149 = F_31 ( V_8 + V_150 ) ;
F_68 ( V_12 -> V_49 , & V_12 -> V_49 -> V_118 , & V_12 -> V_36 ,
V_149 ) ;
} while ( F_31 ( V_8 + V_113 ) & V_144 );
}
static T_4 F_69 ( struct V_11 * V_12 , int V_151 )
{
int V_112 ;
T_4 V_152 = 0 ;
T_4 V_82 ;
int V_8 ;
F_2 ( 4 , L_25 , V_2 , V_151 ) ;
V_8 = V_12 -> V_4 . V_20 ;
if ( V_151 & V_153 ) {
V_112 = F_54 ( V_12 -> V_4 . V_20 ,
V_12 -> V_38 . V_48 ,
V_12 -> V_38 . V_97 ,
V_12 -> V_4 . V_22 ) ;
V_12 -> V_38 . V_48 += V_112 ;
V_12 -> V_38 . V_97 -= V_112 ;
V_12 -> V_4 . V_108 = V_109 ;
if ( V_12 -> V_38 . V_97 > 0 ) {
V_152 |= V_101 ;
} else {
V_82 = F_31 ( V_8 + V_83 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( V_154 , V_8 + V_116 ) ;
F_30 ( V_82 , V_8 + V_83 ) ;
V_12 -> V_49 -> V_118 . V_121 ++ ;
F_33 ( V_12 -> V_49 ) ;
V_152 |= V_155 ;
}
}
if ( V_151 & V_156 ) {
if ( V_12 -> V_99 ) {
F_2 ( 2 ,
L_26 , V_2 ) ;
F_32 ( V_12 , V_12 -> V_99 ) ;
V_12 -> V_99 = 0 ;
}
V_12 -> V_4 . V_108 = V_122 ;
V_152 |= V_92 ;
}
if ( V_151 & V_157 ) {
F_67 ( V_12 ) ;
V_152 |= V_92 ;
}
return V_152 ;
}
static T_4 F_70 ( struct V_11 * V_12 , int V_151 )
{
T_4 V_152 = 0 ;
T_4 V_82 ;
int V_8 ;
V_8 = V_12 -> V_4 . V_20 ;
V_82 = F_31 ( V_8 + V_83 ) ;
if ( V_151 & ( V_158 | V_159 ) ) {
if ( F_59 ( V_12 ) ) {
V_152 |= V_91 ;
} else {
F_29 ( V_8 , V_78 ) ;
F_30 ( 0x01 , V_8 + V_160 ) ;
F_30 ( 0x00 , V_8 + V_161 ) ;
F_30 ( V_162 , V_8 + V_163 ) ;
V_152 |= V_164 ;
}
}
if ( V_151 & V_165 ) {
F_29 ( V_8 , V_78 ) ;
F_30 ( 0 , V_8 + V_163 ) ;
if ( V_12 -> V_4 . V_108 == V_109 ) {
F_42 ( V_12 , V_8 ) ;
V_152 |= V_100 ;
} else {
F_59 ( V_12 ) ;
V_152 |= V_91 ;
}
}
if ( V_151 & V_166 ) {
F_56 ( V_12 ) ;
F_34 ( V_12 ) ;
V_152 = V_91 ;
}
F_30 ( V_82 , V_8 + V_83 ) ;
return V_152 ;
}
static T_7 F_71 ( int V_5 , void * V_167 )
{
struct V_9 * V_10 = V_167 ;
struct V_11 * V_12 ;
T_4 V_82 , V_168 , V_151 ;
int V_8 ;
V_12 = F_11 ( V_10 ) ;
V_8 = V_12 -> V_4 . V_20 ;
V_82 = F_31 ( V_8 + V_83 ) ;
F_29 ( V_8 , V_61 ) ;
V_168 = F_31 ( V_8 + V_84 ) ;
V_151 = F_31 ( V_8 + V_169 ) & V_168 ;
F_30 ( 0 , V_8 + V_84 ) ;
if ( V_151 ) {
if ( V_12 -> V_4 . V_80 > V_90 )
V_168 = F_70 ( V_12 , V_151 ) ;
else
V_168 = F_69 ( V_12 , V_151 ) ;
}
F_30 ( V_168 , V_8 + V_84 ) ;
F_30 ( V_82 , V_8 + V_83 ) ;
return F_72 ( V_151 ) ;
}
static int F_73 ( struct V_11 * V_12 )
{
int V_125 = FALSE ;
int V_8 ;
T_4 V_82 ;
F_57 (self != NULL, return FALSE;) ;
if ( V_12 -> V_4 . V_80 > 115200 ) {
V_8 = V_12 -> V_4 . V_20 ;
V_82 = F_31 ( V_8 + V_83 ) ;
F_29 ( V_8 , V_60 ) ;
if ( ( F_31 ( V_8 + V_170 ) & 0x3f ) != 0 ) {
V_125 = TRUE ;
}
F_30 ( V_82 , V_8 + V_83 ) ;
} else
V_125 = ( V_12 -> V_36 . V_46 != V_47 ) ;
return V_125 ;
}
static int F_74 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_8 ;
char V_171 [ 32 ] ;
T_4 V_82 ;
F_2 ( 0 , L_1 , V_2 ) ;
F_57 (dev != NULL, return -1;) ;
V_12 = F_11 ( V_10 ) ;
F_57 (self != NULL, return 0;) ;
V_8 = V_12 -> V_4 . V_20 ;
if ( F_75 ( V_12 -> V_4 . V_5 , F_71 , 0 , V_10 -> V_53 ,
( void * ) V_10 ) ) {
return - V_172 ;
}
if ( F_76 ( V_12 -> V_4 . V_6 , V_10 -> V_53 ) ) {
F_77 ( V_12 -> V_4 . V_5 , V_10 ) ;
return - V_172 ;
}
V_82 = F_31 ( V_8 + V_83 ) ;
F_29 ( V_8 , V_61 ) ;
if ( V_12 -> V_4 . V_80 > 115200 ) {
F_30 ( V_91 , V_8 + V_84 ) ;
F_34 ( V_12 ) ;
} else
F_30 ( V_92 , V_8 + V_84 ) ;
F_30 ( V_82 , V_8 + V_83 ) ;
F_78 ( V_10 ) ;
sprintf ( V_171 , L_27 , V_12 -> V_4 . V_20 ) ;
V_12 -> V_173 = F_79 ( V_10 , & V_12 -> V_23 , V_171 ) ;
return 0 ;
}
static int F_80 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_8 ;
T_4 V_82 ;
F_2 ( 0 , L_1 , V_2 ) ;
F_57 (dev != NULL, return -1;) ;
V_12 = F_11 ( V_10 ) ;
F_57 (self != NULL, return 0;) ;
V_8 = V_12 -> V_4 . V_20 ;
F_36 ( V_10 ) ;
if ( V_12 -> V_173 )
F_81 ( V_12 -> V_173 ) ;
V_12 -> V_173 = NULL ;
F_46 ( V_12 -> V_4 . V_6 ) ;
V_82 = F_31 ( V_8 + V_83 ) ;
F_29 ( V_8 , V_61 ) ;
F_30 ( 0 , V_8 + V_84 ) ;
F_77 ( V_12 -> V_4 . V_5 , V_10 ) ;
F_82 ( V_12 -> V_4 . V_6 ) ;
F_30 ( V_82 , V_8 + V_83 ) ;
return 0 ;
}
static int F_83 ( struct V_9 * V_10 , struct V_174 * V_175 , int V_176 )
{
struct V_177 * V_5 = (struct V_177 * ) V_175 ;
struct V_11 * V_12 ;
unsigned long V_102 ;
int V_178 = 0 ;
F_57 (dev != NULL, return -1;) ;
V_12 = F_11 ( V_10 ) ;
F_57 (self != NULL, return -1;) ;
F_2 ( 2 , L_28 , V_2 , V_10 -> V_53 , V_176 ) ;
F_45 ( & V_12 -> V_19 , V_102 ) ;
switch ( V_176 ) {
case V_179 :
if ( ! F_84 ( V_180 ) ) {
V_178 = - V_181 ;
goto V_182;
}
F_32 ( V_12 , V_5 -> V_183 ) ;
break;
case V_184 :
if ( ! F_84 ( V_180 ) ) {
V_178 = - V_181 ;
goto V_182;
}
F_85 ( V_12 -> V_49 , TRUE ) ;
break;
case V_185 :
V_5 -> V_186 = F_73 ( V_12 ) ;
break;
default:
V_178 = - V_187 ;
}
V_182:
F_53 ( & V_12 -> V_19 , V_102 ) ;
return V_178 ;
}
