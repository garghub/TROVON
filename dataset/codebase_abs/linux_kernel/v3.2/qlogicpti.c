static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 | V_4 ,
V_2 -> V_5 + V_6 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_5 + V_6 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
T_1 V_7 ;
T_2 V_8 = V_2 -> V_8 ;
#if 0
if (sbus_can_burst64() && (bursts & DMA_BURST64)) {
val = (SBUS_CFG1_BENAB | SBUS_CFG1_B64);
} else
#endif
if ( V_8 & V_9 ) {
V_7 = ( V_10 | V_11 ) ;
} else if ( V_8 & V_12 ) {
V_7 = ( V_10 | V_13 ) ;
} else if ( V_8 & V_14 ) {
V_7 = ( V_10 | V_15 ) ;
} else {
V_7 = 0 ;
}
F_2 ( V_7 , V_2 -> V_5 + V_16 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_3 V_17 [] , int V_18 )
{
int V_19 ;
T_1 V_20 ;
if ( V_21 [ V_17 [ 0 ] ] == 0 )
return 1 ;
V_20 = F_6 ( V_2 -> V_5 + V_22 ) ;
V_20 |= V_23 ;
F_2 ( V_20 , V_2 -> V_5 + V_22 ) ;
V_19 = V_24 ;
while ( -- V_19 && ( F_6 ( V_2 -> V_5 + V_25 ) & V_26 ) ) {
F_7 () ;
F_8 () ;
}
if ( ! V_19 )
F_9 ( V_27 L_1 ,
V_2 -> V_28 ) ;
switch ( V_21 [ V_17 [ 0 ] ] >> 4 ) {
case 6 : F_2 ( V_17 [ 5 ] , V_2 -> V_5 + V_29 ) ;
case 5 : F_2 ( V_17 [ 4 ] , V_2 -> V_5 + V_30 ) ;
case 4 : F_2 ( V_17 [ 3 ] , V_2 -> V_5 + V_31 ) ;
case 3 : F_2 ( V_17 [ 2 ] , V_2 -> V_5 + V_32 ) ;
case 2 : F_2 ( V_17 [ 1 ] , V_2 -> V_5 + V_33 ) ;
case 1 : F_2 ( V_17 [ 0 ] , V_2 -> V_5 + V_34 ) ;
}
V_20 = F_6 ( V_2 -> V_5 + V_25 ) ;
V_20 |= V_35 ;
F_2 ( V_20 , V_2 -> V_5 + V_25 ) ;
F_2 ( 0 , V_2 -> V_5 + V_22 ) ;
V_20 = F_6 ( V_2 -> V_5 + V_25 ) ;
V_20 |= V_36 ;
F_2 ( V_20 , V_2 -> V_5 + V_25 ) ;
V_19 = V_24 ;
while ( -- V_19 &&
( F_6 ( V_2 -> V_5 + V_25 ) & V_35 ) )
F_10 ( 20 ) ;
if ( ! V_19 )
F_9 ( V_27 L_2 ,
V_2 -> V_28 , V_17 [ 0 ] ) ;
V_19 = V_24 ;
while ( -- V_19 &&
! ( F_6 ( V_2 -> V_5 + V_22 ) & V_23 ) ) {
F_10 ( 20 ) ;
if ( F_6 ( V_2 -> V_5 + V_34 ) & 0x4000 )
break;
}
if ( ! V_19 )
F_9 ( V_27 L_3 ,
V_2 -> V_28 , V_17 [ 0 ] ) ;
V_19 = V_24 ;
while ( -- V_19 && ( F_6 ( V_2 -> V_5 + V_34 ) == 0x04 ) )
F_10 ( 20 ) ;
if ( ! V_19 )
F_9 ( V_27 L_4 ,
V_2 -> V_28 , V_17 [ 0 ] ) ;
switch ( V_21 [ V_17 [ 0 ] ] & 0xf ) {
case 6 : V_17 [ 5 ] = F_6 ( V_2 -> V_5 + V_29 ) ;
case 5 : V_17 [ 4 ] = F_6 ( V_2 -> V_5 + V_30 ) ;
case 4 : V_17 [ 3 ] = F_6 ( V_2 -> V_5 + V_31 ) ;
case 3 : V_17 [ 2 ] = F_6 ( V_2 -> V_5 + V_32 ) ;
case 2 : V_17 [ 1 ] = F_6 ( V_2 -> V_5 + V_33 ) ;
case 1 : V_17 [ 0 ] = F_6 ( V_2 -> V_5 + V_34 ) ;
}
V_20 = F_6 ( V_2 -> V_5 + V_25 ) ;
V_20 |= V_35 ;
F_2 ( V_20 , V_2 -> V_5 + V_25 ) ;
V_20 = F_6 ( V_2 -> V_5 + V_22 ) ;
V_20 &= ~ ( V_23 ) ;
F_2 ( V_20 , V_2 -> V_5 + V_22 ) ;
return 0 ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
int V_37 ;
V_2 -> V_38 . V_39 = V_2 -> V_40 ;
V_2 -> V_38 . V_41 = 3 ;
V_2 -> V_38 . V_42 = 0 ;
V_2 -> V_38 . V_43 = 5 ;
V_2 -> V_38 . V_44 = 3 ;
V_2 -> V_38 . V_45 = 1 ;
V_2 -> V_38 . V_46 = 1 ;
V_2 -> V_38 . V_47 = 1 ;
V_2 -> V_38 . V_48 = 1 ;
V_2 -> V_38 . V_49 = 8 ;
V_2 -> V_38 . V_50 = 250 ;
V_2 -> V_38 . V_51 = 256 ;
for( V_37 = 0 ; V_37 < V_52 ; V_37 ++ ) {
V_2 -> V_53 [ V_37 ] . V_54 = 0xcd ;
V_2 -> V_53 [ V_37 ] . V_55 = 16 ;
if ( V_2 -> V_56 ) {
V_2 -> V_53 [ V_37 ] . V_57 = 12 ;
V_2 -> V_53 [ V_37 ] . V_58 = 8 ;
} else {
V_2 -> V_53 [ V_37 ] . V_57 = 25 ;
V_2 -> V_53 [ V_37 ] . V_58 = 12 ;
}
V_2 -> V_53 [ V_37 ] . V_59 = 1 ;
}
}
static int F_12 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = (struct V_1 * ) V_61 -> V_62 ;
T_3 V_17 [ 6 ] ;
unsigned short V_63 ;
int V_19 , V_37 ;
unsigned long V_64 ;
V_63 = 0x1000 ;
F_13 ( V_61 -> V_65 , V_64 ) ;
F_2 ( V_66 , V_2 -> V_5 + V_25 ) ;
if ( F_6 ( V_2 -> V_5 + V_67 ) & V_68 ) {
F_2 ( V_69 , V_2 -> V_5 + V_70 ) ;
F_2 ( V_71 , V_2 -> V_5 + V_72 ) ;
F_10 ( 400 ) ;
}
F_2 ( V_73 , V_2 -> V_5 + V_6 ) ;
F_2 ( ( V_74 | V_75 ) , V_2 -> V_5 + V_76 ) ;
F_2 ( ( V_74 | V_75 ) , V_2 -> V_5 + V_77 ) ;
V_19 = V_24 ;
while ( -- V_19 && ( ( F_6 ( V_2 -> V_5 + V_34 ) & 0xff ) == 0x04 ) )
F_10 ( 20 ) ;
if ( ! V_19 )
F_9 ( V_27 L_5 ,
V_2 -> V_28 ) ;
F_2 ( V_66 , V_2 -> V_5 + V_25 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
if ( F_6 ( V_2 -> V_5 + V_78 ) & V_79 ) {
V_2 -> V_56 = 1 ;
F_2 ( ( V_80 | V_81 ) ,
V_2 -> V_5 + V_82 ) ;
} else {
V_2 -> V_56 = 0 ;
F_2 ( ( V_83 | V_84 ) ,
V_2 -> V_5 + V_82 ) ;
}
F_11 ( V_2 ) ;
F_2 ( V_85 , V_2 -> V_5 + V_25 ) ;
V_17 [ 0 ] = V_86 ;
V_17 [ 1 ] = V_63 ;
if ( F_5 ( V_2 , V_17 , 1 ) ) {
F_9 ( V_27 L_6 ,
V_2 -> V_28 ) ;
F_14 ( V_61 -> V_65 , V_64 ) ;
return 1 ;
}
V_17 [ 0 ] = V_87 ;
V_17 [ 1 ] = V_2 -> V_38 . V_39 ;
if ( F_5 ( V_2 , V_17 , 1 ) ||
( V_17 [ 0 ] != V_88 ) ) {
F_9 ( V_27 L_7 ,
V_2 -> V_28 ) ;
F_14 ( V_61 -> V_65 , V_64 ) ;
return 1 ;
}
V_2 -> V_89 = V_2 -> V_90 = 0 ;
V_17 [ 0 ] = V_91 ;
V_17 [ 1 ] = V_92 + 1 ;
V_17 [ 2 ] = ( T_3 ) ( V_2 -> V_93 >> 16 ) ;
V_17 [ 3 ] = ( T_3 ) ( V_2 -> V_93 & 0xffff ) ;
V_17 [ 4 ] = V_17 [ 5 ] = 0 ;
if ( F_5 ( V_2 , V_17 , 1 ) ) {
F_9 ( V_27 L_8 ,
V_2 -> V_28 ) ;
F_14 ( V_61 -> V_65 , V_64 ) ;
return 1 ;
}
V_17 [ 0 ] = V_94 ;
V_17 [ 1 ] = V_95 + 1 ;
V_17 [ 2 ] = ( T_3 ) ( V_2 -> V_96 >> 16 ) ;
V_17 [ 3 ] = ( T_3 ) ( V_2 -> V_96 & 0xffff ) ;
V_17 [ 4 ] = V_17 [ 5 ] = 0 ;
if ( F_5 ( V_2 , V_17 , 1 ) ) {
F_9 ( V_27 L_9 ,
V_2 -> V_28 ) ;
F_14 ( V_61 -> V_65 , V_64 ) ;
return 1 ;
}
V_17 [ 0 ] = V_97 ;
V_17 [ 1 ] = V_2 -> V_38 . V_42 ;
V_17 [ 2 ] = V_2 -> V_38 . V_43 ;
F_5 ( V_2 , V_17 , 0 ) ;
V_17 [ 0 ] = V_98 ;
V_17 [ 1 ] = V_2 -> V_38 . V_49 ;
F_5 ( V_2 , V_17 , 0 ) ;
for ( V_37 = 0 ; V_37 < V_52 ; V_37 ++ ) {
V_17 [ 0 ] = V_99 ;
V_17 [ 1 ] = ( V_37 << 8 ) ;
F_5 ( V_2 , V_17 , 0 ) ;
}
V_17 [ 0 ] = V_100 ;
F_5 ( V_2 , V_17 , 0 ) ;
V_17 [ 0 ] = V_101 ;
V_17 [ 1 ] = V_2 -> V_38 . V_50 ;
F_5 ( V_2 , V_17 , 0 ) ;
for ( V_37 = 0 ; V_37 < V_52 ; V_37 ++ ) {
V_17 [ 0 ] = V_102 ;
V_17 [ 1 ] = ( V_37 << 8 ) ;
V_17 [ 2 ] = ( V_2 -> V_53 [ V_37 ] . V_54 << 8 ) ;
V_17 [ 2 ] |= 0xc0 ;
V_17 [ 3 ] = 0 ;
F_5 ( V_2 , V_17 , 0 ) ;
}
V_17 [ 0 ] = V_103 ;
V_17 [ 1 ] = V_2 -> V_38 . V_41 ;
F_5 ( V_2 , V_17 , 0 ) ;
V_2 -> V_104 = 1 ;
F_14 ( V_61 -> V_65 , V_64 ) ;
return 0 ;
}
static int T_4 F_15 ( struct V_1 * V_2 )
{
const struct V_105 * V_106 ;
const char V_107 [] = L_10 ;
const T_5 * V_108 ;
struct V_60 * V_61 = V_2 -> V_109 ;
unsigned short V_110 = 0 ;
unsigned short V_17 [ 6 ] ;
unsigned short V_63 , V_111 ;
int V_112 ;
unsigned long V_64 ;
int V_37 , V_113 ;
V_112 = F_16 ( & V_106 , V_107 , & V_2 -> V_114 -> V_115 ) ;
if ( V_112 ) {
F_9 ( V_116 L_11 ,
V_107 , V_112 ) ;
return V_112 ;
}
if ( V_106 -> V_117 % 2 ) {
F_9 ( V_116 L_12 ,
V_106 -> V_117 , V_107 ) ;
V_112 = - V_118 ;
goto V_119;
}
V_108 = ( const T_5 * ) & V_106 -> V_120 [ 0 ] ;
V_63 = 0x1000 ;
V_111 = V_106 -> V_117 / 2 ;
F_13 ( V_61 -> V_65 , V_64 ) ;
for ( V_37 = 0 ; V_37 < V_111 ; V_37 ++ )
V_110 += F_17 ( V_108 [ V_37 ] ) ;
if ( V_110 ) {
F_9 ( V_27 L_13 ,
V_2 -> V_28 ) ;
V_112 = 1 ;
goto V_121;
}
F_2 ( V_73 , V_2 -> V_5 + V_6 ) ;
F_2 ( ( V_74 | V_75 ) , V_2 -> V_5 + V_76 ) ;
F_2 ( ( V_74 | V_75 ) , V_2 -> V_5 + V_77 ) ;
V_113 = V_122 ;
while ( -- V_113 && ( F_6 ( V_2 -> V_5 + V_6 ) & V_73 ) )
F_10 ( 20 ) ;
if ( ! V_113 ) {
F_9 ( V_27 L_14 , V_2 -> V_28 ) ;
V_112 = 1 ;
goto V_121;
}
F_2 ( V_123 , V_2 -> V_5 + V_25 ) ;
F_18 ( 1 ) ;
F_2 ( ( V_4 | V_3 ) , V_2 -> V_5 + V_6 ) ;
F_4 ( V_2 ) ;
F_2 ( 0 , V_2 -> V_5 + V_22 ) ;
if ( F_6 ( V_2 -> V_5 + V_78 ) & V_79 ) {
V_2 -> V_56 = 1 ;
F_2 ( ( V_80 | V_81 ) ,
V_2 -> V_5 + V_82 ) ;
} else {
V_2 -> V_56 = 0 ;
F_2 ( ( V_83 | V_84 ) ,
V_2 -> V_5 + V_82 ) ;
}
F_2 ( V_85 , V_2 -> V_5 + V_25 ) ;
F_2 ( V_66 , V_2 -> V_5 + V_25 ) ;
if ( F_6 ( V_2 -> V_5 + V_124 ) & V_125 )
V_2 -> V_126 = 1 ;
else
V_2 -> V_126 = 0 ;
F_2 ( V_85 , V_2 -> V_5 + V_25 ) ;
V_17 [ 0 ] = V_127 ;
V_17 [ 1 ] = V_17 [ 2 ] = V_17 [ 3 ] = V_17 [ 4 ] = V_17 [ 5 ] = 0 ;
if ( F_5 ( V_2 , V_17 , 1 ) ) {
F_9 ( V_27 L_15 ,
V_2 -> V_28 ) ;
V_112 = 1 ;
goto V_121;
}
for ( V_37 = 0 ; V_37 < V_111 ; V_37 ++ ) {
V_17 [ 0 ] = V_128 ;
V_17 [ 1 ] = V_63 + V_37 ;
V_17 [ 2 ] = F_17 ( V_108 [ V_37 ] ) ;
if ( F_5 ( V_2 , V_17 , 1 ) ||
V_17 [ 0 ] != V_88 ) {
F_9 ( L_16 ,
V_2 -> V_28 ) ;
V_112 = 1 ;
goto V_121;
}
}
F_2 ( V_123 , V_2 -> V_5 + V_25 ) ;
F_18 ( 1 ) ;
F_1 ( V_2 ) ;
F_2 ( 0 , V_2 -> V_5 + V_22 ) ;
F_2 ( V_85 , V_2 -> V_5 + V_25 ) ;
V_17 [ 0 ] = V_129 ;
V_17 [ 1 ] = V_63 ;
if ( F_5 ( V_2 , V_17 , 1 ) ||
( V_17 [ 0 ] != V_88 ) ) {
F_9 ( V_27 L_17 ,
V_2 -> V_28 ) ;
V_112 = 1 ;
goto V_121;
}
V_17 [ 0 ] = V_86 ;
V_17 [ 1 ] = V_63 ;
F_5 ( V_2 , V_17 , 1 ) ;
V_17 [ 0 ] = V_130 ;
if ( F_5 ( V_2 , V_17 , 1 ) ||
( V_17 [ 0 ] != V_88 ) ) {
F_9 ( V_27 L_18 ,
V_2 -> V_28 ) ;
V_112 = 1 ;
goto V_121;
}
V_2 -> V_131 = V_17 [ 1 ] ;
V_2 -> V_132 = V_17 [ 2 ] ;
V_2 -> V_133 = V_17 [ 3 ] ;
V_17 [ 0 ] = V_134 ;
V_17 [ 1 ] = V_2 -> clock ;
if ( F_5 ( V_2 , V_17 , 1 ) ||
( V_17 [ 0 ] != V_88 ) ) {
F_9 ( V_27 L_19 ,
V_2 -> V_28 ) ;
V_112 = 1 ;
goto V_121;
}
if ( V_2 -> V_135 != 0 ) {
V_17 [ 0 ] = V_128 ;
V_17 [ 1 ] = 0xff80 ;
V_17 [ 2 ] = ( unsigned short ) V_2 -> V_40 ;
F_5 ( V_2 , V_17 , 1 ) ;
V_17 [ 0 ] = V_128 ;
V_17 [ 1 ] = 0xff00 ;
V_17 [ 2 ] = ( unsigned short ) 3 ;
F_5 ( V_2 , V_17 , 1 ) ;
}
V_121:
F_14 ( V_61 -> V_65 , V_64 ) ;
V_119:
F_19 ( V_106 ) ;
return V_112 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_136 = F_21 ( V_2 -> V_137 ) ;
V_136 &= 0xf0 ;
if ( ! ( V_136 & V_138 ) && ( V_2 -> V_139 & V_138 ) )
F_9 ( L_20 , V_2 -> V_28 ) ;
if ( ! ( V_136 & V_140 ) && ( V_2 -> V_139 & V_140 ) )
F_9 ( L_21 , V_2 -> V_28 ) ;
if ( V_136 != V_2 -> V_139 ) {
int error = 0 ;
if ( V_136 & V_138 ) {
error ++ ;
F_9 ( L_22 , V_2 -> V_28 ) ;
}
if ( V_136 & V_140 ) {
error ++ ;
F_9 ( L_23 , V_2 -> V_28 ) ;
}
if ( V_2 -> V_126 &&
( V_136 & V_141 ) != V_141 ) {
error ++ ;
F_9 ( L_24
L_25 , V_2 -> V_28 ) ;
}
V_2 -> V_139 = V_136 ;
return error ;
}
return 0 ;
}
static void T_4 F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_142 ) ;
if ( V_143 != NULL ) {
struct V_1 * V_144 = V_143 ;
while( V_144 -> V_145 )
V_144 = V_144 -> V_145 ;
V_144 -> V_145 = V_2 ;
} else {
V_143 = V_2 ;
}
V_2 -> V_145 = NULL ;
F_24 ( & V_142 ) ;
}
static void T_6 F_25 ( struct V_1 * V_2 )
{
F_23 ( & V_142 ) ;
if ( V_143 == V_2 ) {
V_143 = V_2 -> V_145 ;
} else {
struct V_1 * V_144 = V_143 ;
while( V_144 -> V_145 != V_2 )
V_144 = V_144 -> V_145 ;
V_144 -> V_145 = V_2 -> V_145 ;
}
V_2 -> V_145 = NULL ;
F_24 ( & V_142 ) ;
}
static int T_4 F_26 ( struct V_1 * V_2 )
{
struct V_146 * V_114 = V_2 -> V_114 ;
V_2 -> V_5 = F_27 ( & V_114 -> V_147 [ 0 ] , 0 ,
F_28 ( & V_114 -> V_147 [ 0 ] ) ,
L_26 ) ;
if ( ! V_2 -> V_5 ) {
F_9 ( L_27 ) ;
return - 1 ;
}
if ( V_2 -> V_135 ) {
V_2 -> V_137 = F_27 ( & V_114 -> V_147 [ 0 ] , ( 16 * 4096 ) ,
sizeof( unsigned char ) ,
L_28 ) ;
if ( ! V_2 -> V_137 ) {
F_9 ( L_29 ) ;
return - 1 ;
}
}
return 0 ;
}
static int T_4 F_29 ( struct V_1 * V_2 )
{
struct V_146 * V_114 = V_2 -> V_114 ;
V_2 -> V_109 -> V_148 = V_2 -> V_148 = V_114 -> V_149 . V_150 [ 0 ] ;
if ( F_30 ( V_2 -> V_148 , V_151 ,
V_152 , L_30 , V_2 ) )
goto V_153;
F_9 ( L_31 , V_2 -> V_28 , V_2 -> V_148 ) ;
return 0 ;
V_153:
F_9 ( L_32 , V_2 -> V_28 ) ;
return - 1 ;
}
static void T_4 F_31 ( struct V_1 * V_2 )
{
struct V_146 * V_114 = V_2 -> V_114 ;
struct V_154 * V_155 ;
V_155 = V_114 -> V_115 . V_156 ;
V_2 -> V_40 = F_32 ( V_155 , L_33 , - 1 ) ;
if ( V_2 -> V_40 == - 1 )
V_2 -> V_40 = F_32 ( V_155 , L_34 ,
- 1 ) ;
if ( V_2 -> V_40 == - 1 )
V_2 -> V_40 =
F_32 ( V_155 -> V_157 ,
L_34 , 7 ) ;
V_2 -> V_109 -> V_158 = V_2 -> V_40 ;
V_2 -> V_109 -> V_159 = 64 ;
F_9 ( L_35 , V_2 -> V_40 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_146 * V_114 = V_2 -> V_114 ;
T_2 V_8 , V_160 ;
V_8 = F_32 ( V_114 -> V_115 . V_156 , L_36 , 0xff ) ;
V_160 = F_32 ( V_114 -> V_115 . V_156 -> V_157 , L_36 , 0xff ) ;
if ( V_160 != 0xff )
V_8 &= V_160 ;
if ( V_8 == 0xff ||
( V_8 & V_12 ) == 0 ||
( V_8 & V_9 ) == 0 )
V_8 = ( V_9 - 1 ) ;
V_2 -> V_8 = V_8 ;
}
static void F_34 ( struct V_1 * V_2 )
{
unsigned int V_161 ;
V_161 = F_35 ( V_2 -> V_162 , L_37 , 40000000 ) ;
V_2 -> clock = ( V_161 + 500000 ) / 1000000 ;
if ( V_2 -> clock == 0 )
V_2 -> clock = 40 ;
}
static int T_4 F_36 ( struct V_1 * V_2 )
{
struct V_146 * V_114 = V_2 -> V_114 ;
#define F_37 ( T_7 ) (((entries) + 1) * QUEUE_ENTRY_LEN)
V_2 -> V_163 = F_38 ( & V_114 -> V_115 ,
F_37 ( V_92 ) ,
& V_2 -> V_93 , V_164 ) ;
if ( V_2 -> V_163 == NULL ||
V_2 -> V_93 == 0 ) {
F_9 ( L_38 ) ;
return - 1 ;
}
V_2 -> V_165 = F_38 ( & V_114 -> V_115 ,
F_37 ( V_95 ) ,
& V_2 -> V_96 , V_164 ) ;
if ( V_2 -> V_165 == NULL ||
V_2 -> V_96 == 0 ) {
F_39 ( & V_114 -> V_115 , F_37 ( V_92 ) ,
V_2 -> V_163 , V_2 -> V_93 ) ;
F_9 ( L_39 ) ;
return - 1 ;
}
memset ( V_2 -> V_163 , 0 , F_37 ( V_92 ) ) ;
memset ( V_2 -> V_165 , 0 , F_37 ( V_95 ) ) ;
return 0 ;
}
const char * F_40 ( struct V_60 * V_61 )
{
static char V_166 [ 80 ] ;
struct V_1 * V_2 = (struct V_1 * ) V_61 -> V_62 ;
sprintf ( V_166 , L_40 ,
V_2 -> V_109 -> V_148 , V_2 -> V_5 ) ;
return V_166 ;
}
static inline void F_41 ( struct V_167 * V_168 )
{
struct V_169 * V_170 = (struct V_169 * ) V_168 ;
memset ( V_170 , 0 , sizeof( struct V_169 ) ) ;
V_170 -> V_171 . V_172 = 1 ;
V_170 -> V_171 . V_173 = V_174 ;
V_170 -> V_175 = V_176 ;
V_170 -> V_177 = 0 ;
}
static inline void F_42 ( struct V_167 * V_168 , struct V_178 * V_179 ,
struct V_1 * V_2 )
{
memset ( V_168 , 0 , sizeof( struct V_167 ) ) ;
V_168 -> V_171 . V_172 = 1 ;
V_168 -> V_171 . V_173 = V_180 ;
V_168 -> V_181 = V_179 -> V_182 -> V_183 ;
V_168 -> V_184 = V_179 -> V_182 -> V_185 ;
V_168 -> V_186 = V_179 -> V_187 ;
V_168 -> V_188 = 0 ;
if ( V_179 -> V_182 -> V_189 ) {
if ( V_2 -> V_190 [ V_179 -> V_182 -> V_183 ] == 0 )
V_2 -> V_191 [ V_179 -> V_182 -> V_183 ] = V_192 ;
if ( F_43 ( V_192 , V_2 -> V_191 [ V_179 -> V_182 -> V_183 ] + ( 5 * V_193 ) ) ) {
V_168 -> V_188 = V_194 ;
V_2 -> V_191 [ V_179 -> V_182 -> V_183 ] = V_192 ;
} else
V_168 -> V_188 = V_195 ;
}
if ( ( V_179 -> V_196 [ 0 ] == V_197 ) ||
( V_179 -> V_196 [ 0 ] == V_198 ) ||
( V_179 -> V_196 [ 0 ] == V_199 ) )
V_168 -> V_188 |= V_200 ;
else
V_168 -> V_188 |= V_201 ;
V_168 -> V_202 = V_179 -> V_203 -> V_113 / V_193 ;
memcpy ( V_168 -> V_204 , V_179 -> V_196 , V_179 -> V_187 ) ;
}
static inline int F_44 ( struct V_178 * V_179 , struct V_167 * V_168 ,
struct V_1 * V_2 , T_8 V_205 , T_8 V_206 )
{
struct V_207 * V_208 ;
struct V_209 * V_210 , * V_211 ;
int V_37 , V_212 ;
if ( F_45 ( V_179 ) ) {
int V_213 ;
V_210 = F_46 ( V_179 ) ;
V_213 = F_47 ( & V_2 -> V_114 -> V_115 , V_210 ,
F_48 ( V_179 ) ,
V_179 -> V_214 ) ;
V_208 = V_168 -> V_207 ;
V_168 -> V_215 = V_213 ;
V_212 = V_213 ;
if ( V_212 > 4 )
V_212 = 4 ;
F_49 (sg, s, n, i) {
V_208 [ V_37 ] . V_216 = F_50 ( V_211 ) ;
V_208 [ V_37 ] . V_217 = F_51 ( V_211 ) ;
}
V_213 -= 4 ;
V_210 = V_211 ;
while ( V_213 > 0 ) {
struct V_218 * V_219 ;
++ V_168 -> V_171 . V_172 ;
V_219 = (struct V_218 * ) & V_2 -> V_165 [ V_205 ] ;
V_205 = F_52 ( V_205 ) ;
if ( V_205 == V_206 )
return - 1 ;
V_219 -> V_171 . V_173 = V_220 ;
V_219 -> V_171 . V_172 = 0 ;
V_219 -> V_171 . V_221 = 0 ;
V_219 -> V_171 . V_64 = 0 ;
V_219 -> V_222 = 0 ;
V_208 = V_219 -> V_207 ;
V_212 = V_213 ;
if ( V_212 > 7 )
V_212 = 7 ;
F_49 (sg, s, n, i) {
V_208 [ V_37 ] . V_216 = F_50 ( V_211 ) ;
V_208 [ V_37 ] . V_217 = F_51 ( V_211 ) ;
}
V_213 -= V_212 ;
V_210 = V_211 ;
}
} else {
V_168 -> V_207 [ 0 ] . V_216 = 0 ;
V_168 -> V_207 [ 0 ] . V_217 = 0 ;
V_168 -> V_215 = 1 ;
}
V_168 -> V_223 = V_205 ;
V_2 -> V_224 [ V_205 ] = V_179 ;
V_2 -> V_190 [ V_179 -> V_182 -> V_183 ] ++ ;
F_2 ( V_205 , V_2 -> V_5 + V_30 ) ;
V_2 -> V_89 = V_205 ;
return V_205 ;
}
static inline void F_53 ( struct V_60 * V_61 , T_8 V_205 , T_8 V_206 )
{
int V_225 = V_95 - F_54 ( V_205 , V_206 ) - 64 ;
V_61 -> V_226 = V_61 -> V_227 + V_225 ;
V_61 -> V_228 = F_55 ( V_225 ) ;
}
static int F_56 ( struct V_229 * V_230 )
{
struct V_1 * V_2 = F_57 ( V_230 -> V_61 ) ;
int V_231 = V_230 -> V_183 ;
T_3 V_17 [ 6 ] ;
if ( V_230 -> V_232 ) {
V_2 -> V_53 [ V_231 ] . V_54 |= 0x10 ;
} else {
V_2 -> V_53 [ V_231 ] . V_58 = 0 ;
V_2 -> V_53 [ V_231 ] . V_57 = 0 ;
}
if ( V_230 -> V_233 )
V_2 -> V_53 [ V_231 ] . V_54 |= 0x20 ;
V_17 [ 0 ] = V_102 ;
V_17 [ 1 ] = ( V_231 << 8 ) ;
V_17 [ 2 ] = ( V_2 -> V_53 [ V_231 ] . V_54 << 8 ) ;
if ( V_2 -> V_53 [ V_231 ] . V_54 & 0x10 ) {
V_17 [ 3 ] = ( V_2 -> V_53 [ V_231 ] . V_58 << 8 ) |
V_2 -> V_53 [ V_231 ] . V_57 ;
} else {
V_17 [ 3 ] = 0 ;
}
F_5 ( V_2 , V_17 , 0 ) ;
return 0 ;
}
static int F_58 ( struct V_178 * V_179 , void (* F_59)( struct V_178 * ) )
{
struct V_60 * V_61 = V_179 -> V_182 -> V_61 ;
struct V_1 * V_2 = (struct V_1 * ) V_61 -> V_62 ;
struct V_167 * V_168 ;
T_8 V_206 ;
int V_205 ;
V_179 -> V_234 = F_59 ;
V_205 = V_2 -> V_89 ;
V_168 = (struct V_167 * ) & V_2 -> V_165 [ V_205 ] ;
V_206 = F_6 ( V_2 -> V_5 + V_30 ) ;
V_205 = F_52 ( V_205 ) ;
if ( V_205 == V_206 )
goto V_235;
if ( V_2 -> V_104 ) {
F_41 ( V_168 ) ;
V_2 -> V_104 = 0 ;
if ( F_52 ( V_205 ) == V_206 ) {
F_2 ( V_205 , V_2 -> V_5 + V_30 ) ;
V_2 -> V_89 = V_205 ;
goto V_235;
}
V_168 = (struct V_167 * ) & V_2 -> V_165 [ V_205 ] ;
V_205 = F_52 ( V_205 ) ;
}
F_42 ( V_168 , V_179 , V_2 ) ;
if ( ( V_205 = F_44 ( V_179 , V_168 , V_2 , V_205 , V_206 ) ) == - 1 )
goto V_235;
F_53 ( V_61 , V_205 , V_206 ) ;
return 0 ;
V_235:
F_9 ( V_27 L_41 ,
V_2 -> V_28 ) ;
V_179 -> V_236 = V_237 ;
F_59 ( V_179 ) ;
return 1 ;
}
struct V_178 * F_60 ( struct V_1 * V_2 )
{
struct V_178 * V_179 , * V_238 = NULL ;
struct V_239 * V_240 ;
T_8 V_205 , V_206 ;
if ( ! ( F_6 ( V_2 -> V_5 + V_241 ) & V_242 ) )
return NULL ;
V_205 = F_6 ( V_2 -> V_5 + V_29 ) ;
F_2 ( V_35 , V_2 -> V_5 + V_25 ) ;
if ( F_6 ( V_2 -> V_5 + V_22 ) & V_23 ) {
switch ( F_6 ( V_2 -> V_5 + V_34 ) ) {
case V_243 :
case V_244 :
V_2 -> V_104 = 1 ;
break;
case V_245 :
case V_246 :
case V_247 :
case V_248 :
break;
} ;
F_2 ( 0 , V_2 -> V_5 + V_22 ) ;
}
V_206 = V_2 -> V_90 ;
while ( V_206 != V_205 ) {
T_8 V_249 ;
V_240 = (struct V_239 * ) & V_2 -> V_163 [ V_206 ] ;
V_206 = F_61 ( V_206 ) ;
V_249 = V_240 -> V_223 ;
V_179 = V_2 -> V_224 [ V_249 ] ;
V_2 -> V_224 [ V_249 ] = NULL ;
if ( V_240 -> V_250 == V_251 ||
V_240 -> V_250 == V_252 ||
( V_240 -> V_253 & V_254 ) )
V_2 -> V_104 = 1 ;
if ( V_240 -> V_255 & V_256 )
memcpy ( V_179 -> V_257 , V_240 -> V_258 ,
V_259 ) ;
if ( V_240 -> V_171 . V_173 == V_260 )
V_179 -> V_236 =
F_62 ( V_240 , V_2 -> V_28 ) ;
else
V_179 -> V_236 = V_261 << 16 ;
if ( F_45 ( V_179 ) )
F_63 ( & V_2 -> V_114 -> V_115 ,
F_46 ( V_179 ) , F_48 ( V_179 ) ,
V_179 -> V_214 ) ;
V_2 -> V_190 [ V_179 -> V_182 -> V_183 ] -- ;
F_2 ( V_206 , V_2 -> V_5 + V_29 ) ;
V_179 -> V_262 = ( unsigned char * ) V_238 ;
V_238 = V_179 ;
}
V_2 -> V_90 = V_206 ;
return V_238 ;
}
static T_9 V_151 ( int V_148 , void * V_263 )
{
struct V_1 * V_2 = V_263 ;
unsigned long V_64 ;
struct V_178 * V_264 ;
F_13 ( V_2 -> V_109 -> V_65 , V_64 ) ;
V_264 = F_60 ( V_2 ) ;
if ( V_264 != NULL ) {
do {
struct V_178 * V_145 ;
V_145 = (struct V_178 * ) V_264 -> V_262 ;
V_264 -> V_234 ( V_264 ) ;
V_264 = V_145 ;
} while ( V_264 != NULL );
}
F_14 ( V_2 -> V_109 -> V_65 , V_64 ) ;
return V_265 ;
}
static int F_64 ( struct V_178 * V_179 )
{
T_3 V_17 [ 6 ] ;
struct V_60 * V_61 = V_179 -> V_182 -> V_61 ;
struct V_1 * V_2 = (struct V_1 * ) V_61 -> V_62 ;
int V_266 = V_267 ;
T_10 V_268 ;
int V_37 ;
F_9 ( V_269 L_42 ,
V_2 -> V_28 , ( int ) V_179 -> V_182 -> V_183 , ( int ) V_179 -> V_182 -> V_185 ) ;
F_3 ( V_2 ) ;
for ( V_37 = 0 ; V_37 < V_95 + 1 ; V_37 ++ )
if ( V_2 -> V_224 [ V_37 ] == V_179 )
break;
V_268 = V_37 ;
V_17 [ 0 ] = V_270 ;
V_17 [ 1 ] = ( ( ( T_3 ) V_179 -> V_182 -> V_183 ) << 8 ) | V_179 -> V_182 -> V_185 ;
V_17 [ 2 ] = V_268 >> 16 ;
V_17 [ 3 ] = V_268 & 0xffff ;
if ( F_5 ( V_2 , V_17 , 0 ) ||
( V_17 [ 0 ] != V_88 ) ) {
F_9 ( V_27 L_43 ,
V_2 -> V_28 , V_17 [ 0 ] ) ;
V_266 = V_271 ;
}
F_1 ( V_2 ) ;
return V_266 ;
}
static int F_65 ( struct V_178 * V_179 )
{
T_3 V_17 [ 6 ] ;
struct V_60 * V_61 = V_179 -> V_182 -> V_61 ;
struct V_1 * V_2 = (struct V_1 * ) V_61 -> V_62 ;
int V_266 = V_267 ;
F_9 ( V_269 L_44 ,
V_2 -> V_28 ) ;
F_3 ( V_2 ) ;
V_17 [ 0 ] = V_103 ;
V_17 [ 1 ] = V_2 -> V_38 . V_41 ;
if ( F_5 ( V_2 , V_17 , 0 ) ||
( V_17 [ 0 ] != V_88 ) ) {
F_9 ( V_27 L_45 ,
V_2 -> V_28 , V_17 [ 0 ] ) ;
V_266 = V_271 ;
}
F_1 ( V_2 ) ;
return V_266 ;
}
static int T_4 F_66 ( struct V_146 * V_114 )
{
const struct V_272 * V_273 ;
struct V_274 * V_275 ;
struct V_154 * V_155 = V_114 -> V_115 . V_156 ;
struct V_60 * V_61 ;
struct V_1 * V_2 ;
static int V_276 ;
const char * V_277 ;
V_273 = F_67 ( V_278 , & V_114 -> V_115 ) ;
if ( ! V_273 )
return - V_118 ;
V_275 = V_273 -> V_120 ;
if ( V_114 -> V_149 . V_150 [ 0 ] == 0 )
return - V_279 ;
V_61 = F_68 ( V_275 , sizeof( struct V_1 ) ) ;
if ( ! V_61 )
return - V_280 ;
V_2 = F_57 ( V_61 ) ;
V_61 -> V_281 = V_52 ;
V_2 -> V_109 = V_61 ;
V_2 -> V_114 = V_114 ;
V_2 -> V_28 = V_276 ;
strcpy ( V_2 -> V_282 , V_114 -> V_115 . V_156 -> V_283 ) ;
V_2 -> V_135 = strcmp ( V_2 -> V_282 , L_46 ) ;
if ( F_26 ( V_2 ) < 0 )
goto V_284;
if ( F_29 ( V_2 ) < 0 )
goto V_285;
F_31 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
memset ( V_2 -> V_224 , 0 , sizeof( V_2 -> V_224 ) ) ;
if ( F_36 ( V_2 ) < 0 )
goto V_286;
if ( F_15 ( V_2 ) )
goto V_287;
if ( V_2 -> V_135 ) {
if ( F_20 ( V_2 ) )
goto V_287;
}
if ( F_12 ( V_61 ) )
goto V_287;
F_9 ( L_47 , V_2 -> V_131 ,
V_2 -> V_132 , V_2 -> V_133 ) ;
V_277 = F_69 ( V_155 , L_48 , NULL ) ;
if ( V_277 && V_277 [ 0 ] )
F_9 ( L_49 , V_277 ) ;
if ( F_70 ( V_155 , L_50 , NULL ) != NULL )
V_2 -> V_126 = 1 ;
F_9 ( L_51 ,
V_2 -> V_28 ,
( V_2 -> V_56 ? L_52 : L_53 ) ,
( V_2 -> V_126 ? L_50 : L_54 ) ) ;
if ( F_71 ( V_61 , & V_114 -> V_115 ) ) {
F_9 ( L_55 , V_2 -> V_28 ) ;
goto V_287;
}
F_72 ( & V_114 -> V_115 , V_2 ) ;
F_22 ( V_2 ) ;
F_73 ( V_61 ) ;
V_276 ++ ;
return 0 ;
V_287:
#define F_37 ( T_7 ) (((entries) + 1) * QUEUE_ENTRY_LEN)
F_39 ( & V_114 -> V_115 ,
F_37 ( V_92 ) ,
V_2 -> V_163 , V_2 -> V_93 ) ;
F_39 ( & V_114 -> V_115 ,
F_37 ( V_95 ) ,
V_2 -> V_165 , V_2 -> V_96 ) ;
#undef F_37
V_285:
F_74 ( & V_114 -> V_147 [ 0 ] , V_2 -> V_5 ,
F_28 ( & V_114 -> V_147 [ 0 ] ) ) ;
if ( V_2 -> V_135 )
F_74 ( & V_114 -> V_147 [ 0 ] , V_2 -> V_137 ,
sizeof( unsigned char ) ) ;
V_286:
F_75 ( V_2 -> V_148 , V_2 ) ;
V_284:
F_76 ( V_61 ) ;
return - V_279 ;
}
static int T_6 F_77 ( struct V_146 * V_114 )
{
struct V_1 * V_2 = F_78 ( & V_114 -> V_115 ) ;
F_25 ( V_2 ) ;
F_79 ( V_2 -> V_109 ) ;
F_2 ( 0 , V_2 -> V_5 + V_6 ) ;
F_75 ( V_2 -> V_148 , V_2 ) ;
#define F_37 ( T_7 ) (((entries) + 1) * QUEUE_ENTRY_LEN)
F_39 ( & V_114 -> V_115 ,
F_37 ( V_92 ) ,
V_2 -> V_163 , V_2 -> V_93 ) ;
F_39 ( & V_114 -> V_115 ,
F_37 ( V_95 ) ,
V_2 -> V_165 , V_2 -> V_96 ) ;
#undef F_37
F_74 ( & V_114 -> V_147 [ 0 ] , V_2 -> V_5 ,
F_28 ( & V_114 -> V_147 [ 0 ] ) ) ;
if ( V_2 -> V_135 )
F_74 ( & V_114 -> V_147 [ 0 ] , V_2 -> V_137 , sizeof( unsigned char ) ) ;
F_76 ( V_2 -> V_109 ) ;
return 0 ;
}
static int T_11 F_80 ( void )
{
return F_81 ( & V_288 ) ;
}
static void T_12 F_82 ( void )
{
F_83 ( & V_288 ) ;
}
