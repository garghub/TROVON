static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0x1B , 0x135E ) ;
F_3 ( 10 ) ;
F_2 ( V_2 , 0x00 , 0x0280 ) ;
F_2 ( V_2 , 0x01 , 0x7112 ) ;
F_2 ( V_2 , 0x01 , 0x7110 ) ;
F_2 ( V_2 , 0x01 , 0x7112 ) ;
F_2 ( V_2 , 0x01 , 0x7113 ) ;
F_2 ( V_2 , 0x00 , 0x0288 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 = F_5 ( V_2 , V_4 ) ;
V_3 &= ~ ( V_5 | V_6 | V_7 ) ;
F_6 ( V_2 , V_4 , V_3 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
T_1 V_3 = F_5 ( V_2 , V_4 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 <= V_2 -> V_9 ; V_8 ++ ) {
if ( V_2 -> V_10 [ V_8 ] & V_11 )
V_3 |= V_5 ;
if ( V_2 -> V_10 [ V_8 ] & V_12 )
V_3 |= V_6 ;
if ( V_2 -> V_10 [ V_8 ] & V_13 )
V_3 |= V_7 ;
}
if ( V_2 -> V_14 )
V_3 &= ~ ( ( T_1 ) V_6 ) ;
F_6 ( V_2 , V_4 , V_3 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
#ifndef F_9
int V_8 ;
#endif
V_3 = V_15 | V_16 ;
#ifndef F_9
for ( V_8 = 0 ; V_8 <= V_2 -> V_9 ; V_8 ++ ) {
F_10 ( L_1 , V_8 , V_2 -> V_10 [ V_8 ] ) ;
if ( V_2 -> V_10 [ V_8 ] & V_11 )
V_3 |= V_5 ;
if ( V_2 -> V_10 [ V_8 ] & V_12 )
V_3 |= V_6 ;
if ( V_2 -> V_10 [ V_8 ] & V_13 )
V_3 |= V_7 ;
}
if ( V_2 -> V_14 )
V_3 &= ~ ( ( T_1 ) V_6 ) ;
#endif
if ( V_2 -> V_17 >= V_18 )
V_3 |= V_19 ;
#ifdef F_11
V_3 |= V_20 ;
#endif
if ( ! V_2 -> V_21 )
V_3 |= V_22 ;
F_6 ( V_2 , V_4 , V_3 ) ;
F_10 ( L_2 , V_3 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_4 , 0 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 && F_14 ( V_2 ) ) {
if ( V_2 -> V_24 ) {
F_15 ( V_2 , V_25 , 0xFF ,
V_26 | V_27 | V_28 | V_29 ) ;
} else {
F_15 ( V_2 , V_30 , 0xFF ,
V_31 ) ;
}
F_15 ( V_2 , V_32 , 0xFF , V_33 ) ;
F_15 ( V_2 , 0xFF2C , 0x01 , 0x01 ) ;
F_15 ( V_2 , V_34 , 0xFF ,
V_35 | V_36 ) ;
V_2 -> V_37 = 1 ;
V_2 -> V_38 = 1 ;
} else {
V_2 -> V_39 |= V_12 ;
}
return V_40 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_2 V_41 ;
int V_42 = 0 ;
int V_43 ;
if ( V_2 -> V_44 ) {
if ( F_17 ( V_2 , 0x5288 ) ) {
F_18 ( V_2 , 0xFE5A , & V_41 ) ;
if ( V_41 & 0x08 )
V_42 = 1 ;
} else if ( F_17 ( V_2 , 0x5208 ) ) {
F_18 ( V_2 , 0xFE70 , & V_41 ) ;
if ( V_41 & 0x80 )
V_42 = 1 ;
}
} else {
if ( V_2 -> V_45 )
V_42 = 1 ;
}
F_10 ( L_3 , V_2 -> V_45 ) ;
F_10 ( L_4 , V_2 -> V_44 ) ;
F_10 ( L_5 , V_42 ) ;
if ( V_42 ) {
T_2 V_46 = 0 ;
F_18 ( V_2 , V_47 , & V_41 ) ;
V_46 = 0x08 ;
if ( V_41 & V_46 ) {
if ( F_17 ( V_2 , 0x5288 ) )
F_15 ( V_2 , 0xFE5A , 0x08 , 0x00 ) ;
else if ( F_17 ( V_2 , 0x5208 ) )
F_15 ( V_2 , 0xFE70 , 0x80 , 0x00 ) ;
F_15 ( V_2 , V_47 , 0xFF , V_41 ) ;
V_2 -> V_39 |= V_12 ;
} else {
F_10 ( L_6 ) ;
if ( V_2 -> V_24 ) {
V_43 = F_19 ( V_2 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
} else {
F_15 ( V_2 , V_30 ,
V_49 | 0x20 , 0 ) ;
}
V_43 = F_21 ( V_2 , V_12 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
if ( F_17 ( V_2 , 0x5288 ) )
F_15 ( V_2 , 0xFE5A , 0x08 , 0x08 ) ;
else if ( F_17 ( V_2 , 0x5208 ) )
F_15 ( V_2 , 0xFE70 , 0x80 , 0x80 ) ;
V_2 -> V_50 = 1 ;
V_2 -> V_38 = 1 ;
}
} else {
F_15 ( V_2 , V_47 , 0x08 , 0x08 ) ;
V_2 -> V_39 |= V_12 ;
}
return V_40 ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_43 ;
F_6 ( V_2 , V_51 , V_2 -> V_52 ) ;
F_23 ( V_2 ) ;
F_15 ( V_2 , V_53 , 0x03 , 0x00 ) ;
F_15 ( V_2 , V_54 , 0x1E , 0 ) ;
#ifdef F_11
if ( F_24 ( V_2 , V_55 ) )
F_15 ( V_2 , V_56 , V_57 , 0 ) ;
else
F_15 ( V_2 , V_56 , V_57 , V_58 ) ;
F_15 ( V_2 , V_59 , V_60 , V_61 ) ;
F_15 ( V_2 , V_62 , V_63 , V_64 ) ;
F_15 ( V_2 , V_65 , 0xFF , V_66 | V_67 ) ;
#else
F_15 ( V_2 , V_56 , V_57 , V_57 ) ;
#endif
if ( ! F_17 ( V_2 , 0x5288 ) )
F_15 ( V_2 , V_68 , 0xFF , 0x03 ) ;
F_15 ( V_2 , V_69 , 0xFF , 0x03 ) ;
F_15 ( V_2 , V_70 , 0x0A , 0 ) ;
F_15 ( V_2 , V_71 , 0xFF , V_2 -> V_72 ) ;
#ifdef F_25
F_15 ( V_2 , V_73 , 0xFF ,
V_74 | V_75 | V_76 ) ;
#endif
if ( V_2 -> V_24 ) {
F_15 ( V_2 , V_77 , 0xFF , V_78 | V_79 ) ;
F_15 ( V_2 , V_80 , 0xFF , 0x12 ) ;
}
F_15 ( V_2 , V_70 , 0x16 , 0x10 ) ;
if ( V_2 -> V_81 ) {
if ( V_2 -> V_82 ) {
if ( F_14 ( V_2 ) ) {
if ( F_17 ( V_2 , 0x5288 ) ) {
V_43 = F_26 ( V_2 , 2 , 0xC0 , 0xFF , V_2 -> V_81 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
}
}
} else {
if ( F_17 ( V_2 , 0x5208 ) )
F_15 ( V_2 , V_83 ,
0xFF , 0x3F ) ;
V_43 = F_27 ( V_2 , V_84 ,
V_2 -> V_81 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
V_2 -> V_85 [ 0 ] = V_2 -> V_81 ;
if ( F_14 ( V_2 ) ) {
V_2 -> V_85 [ 1 ] = V_2 -> V_81 ;
if ( F_17 ( V_2 , 0x5288 ) )
V_43 = F_26 ( V_2 , 2 , 0xC0 , 0xFF , V_2 -> V_81 ) ;
else
V_43 = F_26 ( V_2 , 1 , 0xC0 , 0xFF , V_2 -> V_81 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
}
V_2 -> V_86 = 1 ;
}
} else {
if ( V_2 -> V_24 && F_17 ( V_2 , 0x5208 ) ) {
V_43 = F_2 ( V_2 , 0x07 , 0x0129 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
}
V_43 = F_27 ( V_2 , V_84 ,
V_2 -> V_81 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
}
V_43 = F_27 ( V_2 , 0x81 , 1 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
if ( F_14 ( V_2 ) ) {
if ( F_17 ( V_2 , 0x5288 ) )
V_43 = F_26 ( V_2 , 2 , 0xC0 ,
0xFF00 , 0x0100 ) ;
else
V_43 = F_26 ( V_2 , 1 , 0xC0 ,
0xFF00 , 0x0100 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
}
if ( F_17 ( V_2 , 0x5288 ) ) {
if ( ! F_14 ( V_2 ) ) {
V_43 = F_26 ( V_2 , 2 , 0xC0 , 0xFFFF ,
0x0103 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
V_43 = F_26 ( V_2 , 2 , 0x84 , 0xFF , 0x03 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
}
}
F_15 ( V_2 , V_87 , V_88 , V_88 ) ;
F_15 ( V_2 , V_89 , 0xFF , 0x80 ) ;
if ( V_2 -> V_24 ) {
if ( F_17 ( V_2 , 0x5208 ) ) {
if ( V_2 -> V_90 ) {
F_15 ( V_2 , V_91 , 0x77 , 0 ) ;
F_12 ( V_2 ) ;
} else {
F_8 ( V_2 ) ;
}
if ( V_2 -> V_17 >= V_92 ) {
T_3 V_3 ;
V_43 = F_28 ( V_2 , 0x00 ,
& V_3 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
V_3 &= 0xFE7F ;
V_3 |= 0x80 ;
V_43 = F_2 ( V_2 , 0x00 ,
V_3 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
V_43 = F_28 ( V_2 , 0x1C ,
& V_3 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
V_3 &= 0xFFF7 ;
V_43 = F_2 ( V_2 , 0x1C ,
V_3 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
}
if ( V_2 -> V_44 &&
( V_2 -> V_17 < V_18 ) )
F_1 ( V_2 ) ;
} else {
F_8 ( V_2 ) ;
}
} else {
F_8 ( V_2 ) ;
}
V_2 -> V_39 = 0 ;
V_2 -> V_93 = F_5 ( V_2 , V_94 ) ;
if ( V_2 -> V_14 )
goto V_95;
F_10 ( L_7 ,
V_2 -> V_93 ) ;
if ( V_2 -> V_93 & V_96 ) {
#ifdef F_29
if ( F_17 ( V_2 , 0x5208 ) && ( V_2 -> V_17 < V_18 ) )
V_43 = F_13 ( V_2 ) ;
else
V_43 = F_16 ( V_2 ) ;
F_10 ( L_8 ,
( unsigned int ) ( V_2 -> V_39 ) ) ;
#else
V_43 = F_13 ( V_2 ) ;
#endif
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
} else {
V_2 -> V_38 = 0 ;
F_15 ( V_2 , V_34 , V_35 | V_36 ,
0 ) ;
}
V_95:
if ( V_2 -> V_93 & V_97 )
V_2 -> V_39 |= V_11 ;
if ( V_2 -> V_93 & V_98 )
V_2 -> V_39 |= V_13 ;
if ( V_2 -> V_93 & V_99 )
F_15 ( V_2 , V_77 , V_100 , V_100 ) ;
F_10 ( L_9 ,
( unsigned int ) ( V_2 -> V_39 ) ) ;
F_15 ( V_2 , V_101 , 0x01 , 0x00 ) ;
if ( F_17 ( V_2 , 0x5208 ) || F_17 ( V_2 , 0x5288 ) ) {
F_15 ( V_2 , V_102 , 0x03 , 0x03 ) ;
}
if ( V_2 -> V_103 && ! V_2 -> V_104 ) {
F_15 ( V_2 , V_105 , 0x07 , 0x07 ) ;
if ( V_2 -> V_106 )
F_15 ( V_2 , V_107 , 0xFF , 0x33 ) ;
} else {
F_15 ( V_2 , V_105 , 0x07 , 0x04 ) ;
F_15 ( V_2 , V_107 , 0xFF , 0x30 ) ;
}
if ( F_17 ( V_2 , 0x5208 ) && ( V_2 -> V_17 >= V_92 ) )
F_15 ( V_2 , V_108 , 0x1C , 0x14 ) ;
if ( V_2 -> V_24 && F_17 ( V_2 , 0x5208 ) ) {
V_43 = F_30 ( V_2 , 0x1C , 2 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
}
if ( V_2 -> V_109 ) {
F_15 ( V_2 , V_110 , 0xFF ,
V_111 | V_112 ) ;
F_31 ( V_2 -> V_113 ) ;
F_15 ( V_2 , V_110 , 0xFF ,
V_114 | V_115 ) ;
F_3 ( 200 ) ;
}
F_32 ( V_2 , 0 ) ;
V_2 -> V_44 = 0 ;
return V_40 ;
}
static inline int F_33 ( T_1 V_116 )
{
int V_8 , V_117 = 0 ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
T_2 V_41 = ( T_2 ) ( V_116 >> ( V_8 * 8 ) ) ;
if ( ( V_41 < 0x01 ) || ( V_41 > 0x04 ) ) {
V_117 = 1 ;
break;
}
}
return ! V_117 ;
}
static inline int F_34 ( T_1 V_118 )
{
int V_8 , V_117 = 0 ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
T_2 V_41 = ( T_2 ) ( V_118 >> ( V_8 * 8 ) ) ;
if ( V_41 > 0x03 ) {
V_117 = 1 ;
break;
}
}
return ! V_117 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_43 ;
T_3 V_3 = 0 ;
T_2 V_119 = 0 ;
F_15 ( V_2 , V_120 , 0x03 , 0x03 ) ;
F_18 ( V_2 , V_120 , & V_119 ) ;
if ( V_119 == 0 )
V_2 -> V_24 = 1 ;
else
V_2 -> V_24 = 0 ;
if ( V_2 -> V_24 ) {
V_43 = F_28 ( V_2 , 0x1C , & V_3 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
F_10 ( L_10 , V_3 ) ;
V_2 -> V_17 = ( V_3 >> 4 ) & 0x07 ;
if ( V_3 & V_121 )
V_2 -> V_90 = 1 ;
else
V_2 -> V_90 = 0 ;
} else {
F_18 ( V_2 , 0xFE80 , & V_119 ) ;
V_2 -> V_17 = V_119 ;
V_2 -> V_90 = 0 ;
}
F_18 ( V_2 , V_122 , & V_119 ) ;
F_10 ( L_11 , V_119 ) ;
if ( V_119 & V_123 )
V_2 -> V_106 = 1 ;
else
V_2 -> V_106 = 0 ;
F_18 ( V_2 , 0xFE50 , & V_119 ) ;
if ( V_119 & 0x01 )
V_2 -> V_14 = 1 ;
else
V_2 -> V_14 = 0 ;
F_36 ( V_2 , 0x0E , & V_119 ) ;
if ( V_119 & 0x80 )
F_37 ( V_2 ) ;
else
F_38 ( V_2 ) ;
if ( V_2 -> V_124 ) {
F_18 ( V_2 , V_70 , & V_119 ) ;
if ( V_119 & 0x80 )
V_2 -> V_104 = 1 ;
else
V_2 -> V_104 = 0 ;
}
return V_40 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_43 ;
T_2 V_119 = 0 , V_125 ;
T_1 V_126 = 0 ;
F_15 ( V_2 , V_120 , 0x03 , 0x03 ) ;
F_18 ( V_2 , V_120 , & V_119 ) ;
if ( V_119 == 0 )
V_2 -> V_24 = 1 ;
else
V_2 -> V_24 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_90 = 0 ;
F_18 ( V_2 , V_122 , & V_119 ) ;
F_10 ( L_11 , V_119 ) ;
if ( V_119 & V_123 )
V_2 -> V_106 = 1 ;
else
V_2 -> V_106 = 0 ;
F_18 ( V_2 , V_32 , & V_119 ) ;
F_10 ( L_12 , V_119 ) ;
if ( V_119 & 0x04 )
V_2 -> V_127 = V_128 ;
else
V_2 -> V_127 = V_129 ;
F_18 ( V_2 , 0xFE5A , & V_119 ) ;
if ( V_119 & 0x10 )
V_2 -> V_14 = 1 ;
else
V_2 -> V_14 = 0 ;
V_43 = F_40 ( V_2 , 0 , 0x718 , & V_126 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
V_125 = ( T_2 ) ( ( V_126 >> 29 ) & 0x07 ) ;
F_10 ( L_13 , V_125 ) ;
if ( V_125 == 0x02 )
F_37 ( V_2 ) ;
else
F_38 ( V_2 ) ;
if ( V_2 -> V_124 ) {
F_18 ( V_2 , V_70 , & V_119 ) ;
if ( V_119 & 0x80 )
V_2 -> V_104 = 1 ;
else
V_2 -> V_104 = 0 ;
if ( F_41 ( V_2 , V_129 ) )
V_2 -> V_130 = V_131 ;
else
V_2 -> V_130 = V_132 ;
}
return V_40 ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = & ( V_2 -> V_134 ) ;
struct V_135 * V_136 = & ( V_2 -> V_136 ) ;
struct V_137 * V_138 = & ( V_2 -> V_138 ) ;
int V_43 ;
unsigned int V_8 ;
F_10 ( L_14 ,
V_2 -> V_139 , V_2 -> V_140 ) ;
V_2 -> V_17 = 0 ;
#ifdef F_43
V_2 -> V_141 = 0 ;
#endif
memset ( V_136 , 0 , sizeof( struct V_135 ) ) ;
memset ( V_134 , 0 , sizeof( struct V_133 ) ) ;
memset ( V_138 , 0 , sizeof( struct V_137 ) ) ;
V_2 -> V_142 = 0 ;
V_2 -> V_143 = 0 ;
V_2 -> V_144 = 0 ;
V_2 -> V_145 = V_146 ;
V_2 -> V_147 = V_146 ;
V_2 -> V_148 = V_146 ;
V_2 -> V_38 = 0 ;
V_2 -> V_149 = 0 ;
V_2 -> V_150 = 1 ;
F_44 ( V_2 , V_151 ) ;
V_2 -> V_86 = 0 ;
V_2 -> V_50 = 0 ;
V_2 -> V_152 = 0 ;
V_2 -> V_153 = 0 ;
V_2 -> V_154 = 0 ;
V_2 -> V_155 = 0 ;
V_2 -> V_90 = 0 ;
V_2 -> V_156 = 0 ;
memset ( V_2 -> V_157 , 0 , 12 ) ;
for ( V_8 = 0 ; V_8 < V_158 ; V_8 ++ ) {
F_45 ( V_2 , V_8 , V_159 ) ;
V_2 -> V_160 [ V_8 ] = 0 ;
}
if ( ! F_33 ( V_2 -> V_116 ) )
V_2 -> V_116 = 0x01040203 ;
F_10 ( L_15 , V_2 -> V_116 ) ;
if ( ! F_34 ( V_2 -> V_118 ) )
V_2 -> V_118 = 0x00010203 ;
F_10 ( L_16 , V_2 -> V_118 ) ;
if ( ( V_2 -> V_161 > 31 ) || ( V_2 -> V_161 < 0 ) )
V_2 -> V_161 = 0 ;
if ( ( V_2 -> V_162 > 31 ) || ( V_2 -> V_162 < 0 ) )
V_2 -> V_162 = 0 ;
F_15 ( V_2 , V_56 , V_163 , 0 ) ;
F_3 ( 200 ) ;
F_15 ( V_2 , V_164 , 0x07 , 0x07 ) ;
F_10 ( L_17 , V_2 -> V_124 ) ;
if ( F_17 ( V_2 , 0x5208 ) ) {
V_43 = F_35 ( V_2 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
} else if ( F_17 ( V_2 , 0x5288 ) ) {
V_43 = F_39 ( V_2 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
}
if ( V_2 -> V_165 == 2 )
V_2 -> V_165 = 0 ;
F_10 ( L_18 , V_2 -> V_24 ) ;
F_10 ( L_19 , V_2 -> V_17 ) ;
F_10 ( L_20 , V_2 -> V_90 ) ;
F_10 ( L_21 , V_2 -> V_106 ) ;
F_10 ( L_22 , V_2 -> V_156 ) ;
F_10 ( L_23 , V_2 -> V_14 ) ;
F_10 ( L_24 , V_2 -> V_81 ) ;
F_10 ( L_25 , V_2 -> V_130 ) ;
F_10 ( L_26 , V_2 -> V_104 ) ;
F_10 ( L_27 , V_2 -> V_165 ) ;
F_10 ( L_28 , V_2 -> V_127 ) ;
if ( F_24 ( V_2 , V_55 ) ) {
V_2 -> V_166 [ V_12 ] = 0 ;
V_2 -> V_166 [ V_13 ] = 1 ;
V_2 -> V_166 [ V_11 ] = 0xFF ;
V_2 -> V_10 [ 0 ] = V_12 ;
V_2 -> V_10 [ 1 ] = V_13 ;
V_2 -> V_9 = 1 ;
F_46 ( V_2 ) ;
} else if ( F_24 ( V_2 , V_131 ) ) {
V_2 -> V_166 [ V_12 ] = 0 ;
V_2 -> V_166 [ V_13 ] = 0 ;
V_2 -> V_166 [ V_11 ] = 0xFF ;
V_2 -> V_10 [ 0 ] = V_12 | V_13 ;
V_2 -> V_9 = 0 ;
} else {
V_2 -> V_166 [ V_11 ] = 0 ;
V_2 -> V_166 [ V_12 ] = 0 ;
V_2 -> V_166 [ V_13 ] = 0 ;
V_2 -> V_10 [ 0 ] = V_11 | V_12 | V_13 ;
V_2 -> V_9 = 0 ;
}
V_43 = F_22 ( V_2 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
return V_40 ;
}
void F_47 ( struct V_1 * V_2 )
{
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
V_2 -> V_167 = 0 ;
V_2 -> V_168 = 0 ;
}
static inline void F_50 ( struct V_1 * V_2 )
{
if ( V_2 -> V_167 && V_2 -> V_169 ) {
if ( V_2 -> V_170 < V_171 ) {
V_2 -> V_170 ++ ;
} else {
V_2 -> V_170 = 0 ;
F_51 ( V_2 , V_172 ) ;
}
}
}
static void F_52 ( struct V_1 * V_2 )
{
int V_173 , V_174 ;
T_1 V_41 = 0 ;
T_2 V_175 = 0 , V_176 = 0 ;
V_173 = 0 ;
V_174 = 0 ;
F_36 ( V_2 , V_84 , & V_175 ) ;
if ( V_2 -> V_85 [ 0 ] != V_175 ) {
V_174 = 1 ;
V_2 -> V_85 [ 0 ] = V_175 ;
}
if ( F_14 ( V_2 ) && ! F_53 ( V_2 ) ) {
F_40 ( V_2 , 1 , 0xC0 , & V_41 ) ;
V_176 = ( T_2 ) V_41 ;
if ( V_2 -> V_85 [ 1 ] != V_176 ) {
V_174 = 1 ;
V_2 -> V_85 [ 1 ] = V_176 ;
}
if ( ( V_175 & 0x03 ) && ( V_176 & 0x03 ) )
V_173 = 1 ;
} else {
if ( V_175 & 0x03 )
V_173 = 1 ;
}
if ( V_174 ) {
if ( V_173 )
V_2 -> V_81 = 0x03 ;
F_10 ( L_29 ,
V_2 -> V_85 [ 0 ] , V_2 -> V_85 [ 1 ] ) ;
if ( V_2 -> V_81 ) {
V_2 -> V_86 = 1 ;
} else {
V_2 -> V_86 = 0 ;
V_2 -> V_152 = 0 ;
}
F_54 ( V_2 , V_83 , 0xFF ,
0x30 | V_2 -> V_85 [ 0 ] |
( V_2 -> V_85 [ 1 ] << 2 ) ) ;
}
}
void F_55 ( struct V_1 * V_2 )
{
#ifdef F_56
struct V_133 * V_134 = & ( V_2 -> V_134 ) ;
#endif
int V_177 ;
if ( F_57 ( V_2 , V_178 ) )
return;
if ( F_57 ( V_2 , V_179 ) )
goto V_180;
if ( V_2 -> V_181 ) {
T_2 V_119 ;
F_36 ( V_2 , 0 , & V_119 ) ;
}
if ( F_57 ( V_2 , V_182 ) )
return;
#ifdef F_11
if ( V_2 -> V_183 ) {
F_58 ( V_2 , V_184 , & ( V_2 -> V_185 ) ) ;
if ( V_2 -> V_167 & V_12 )
F_59 ( V_2 ) ;
else if ( V_2 -> V_167 & V_13 )
F_60 ( V_2 ) ;
else if ( V_2 -> V_167 & V_11 )
F_61 ( V_2 ) ;
V_2 -> V_183 = 0 ;
}
#endif
#ifdef F_56
if ( V_134 -> V_186 ) {
if ( V_2 -> V_167 & V_12 ) {
T_2 V_119 ;
F_58 ( V_2 , 0xFD30 , & V_119 ) ;
if ( V_119 & 0x02 ) {
V_134 -> V_186 = V_187 ;
V_134 -> V_188 = 1 ;
V_2 -> V_189 |= V_12 ;
}
} else {
V_134 -> V_186 = V_187 ;
}
}
#endif
F_62 ( V_2 ) ;
if ( V_2 -> V_165 ) {
V_177 = 1 ;
if ( F_17 ( V_2 , 0x5288 ) ) {
V_177 = 0 ;
} else {
if ( F_14 ( V_2 ) && ! F_53 ( V_2 ) ) {
T_1 V_119 ;
F_40 ( V_2 , 1 , 0x04 , & V_119 ) ;
if ( V_119 & 0x07 )
V_177 = 0 ;
}
}
} else {
V_177 = 0 ;
}
if ( V_177 && ! V_2 -> V_38 ) {
if ( F_63 ( V_2 ) != V_190 ) {
V_2 -> V_191 = 0 ;
} else {
if ( V_2 -> V_191 <
( V_2 -> V_192 / V_193 ) ) {
V_2 -> V_191 ++ ;
} else {
F_64 ( V_2 ) ;
return;
}
}
}
if ( F_17 ( V_2 , 0x5208 ) ) {
F_52 ( V_2 ) ;
#ifdef F_65
if ( F_14 ( V_2 ) && ! F_53 ( V_2 ) &&
V_2 -> V_81 && V_2 -> V_82 ) {
if ( V_2 -> V_38 ) {
F_66 ( V_2 ) ;
} else {
if ( ! V_2 -> V_152 ) {
F_10 ( L_30 ) ;
F_54 ( V_2 ,
V_83 , 0xFC ,
0x30 | ( V_2 -> V_85 [ 1 ] << 2 ) ) ;
V_2 -> V_152 = 1 ;
}
}
}
#endif
}
if ( V_2 -> V_194 < V_195 ) {
V_2 -> V_194 ++ ;
} else {
if ( F_63 ( V_2 ) != V_190 ) {
F_10 ( L_31 ) ;
F_44 ( V_2 , V_190 ) ;
#if ! F_67 ( F_25 ) && F_67 ( V_196 )
V_2 -> V_170 = 0 ;
#endif
F_68 ( V_2 , V_197 ) ;
F_69 ( V_2 , V_172 ) ;
if ( V_2 -> V_198 && ! V_2 -> V_168 && ! V_2 -> V_38 )
F_70 ( V_2 , V_197 | V_199 ) ;
}
}
switch ( F_63 ( V_2 ) ) {
case V_200 :
#if ! F_67 ( F_25 ) && F_67 ( V_196 )
F_50 ( V_2 ) ;
#endif
F_71 ( V_2 ) ;
break;
case V_190 :
if ( V_2 -> V_38 && ! V_2 -> V_37 )
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
break;
default:
break;
}
#ifdef F_11
if ( F_24 ( V_2 , V_55 ) ) {
#ifdef F_74
if ( V_2 -> V_185 &
( V_201 | V_202 | V_203 | V_204 ) )
F_10 ( L_32 ,
V_2 -> V_185 ) ;
#endif
if ( V_2 -> V_185 & ( V_201 | V_202 ) ) {
if ( V_2 -> V_167 & V_12 ) {
F_54 ( V_2 , V_205 , V_206 ,
0 ) ;
F_75 ( V_2 , V_12 ) ;
V_2 -> V_207 |= V_12 ;
}
}
if ( V_2 -> V_185 & ( V_203 | V_204 ) ) {
if ( V_2 -> V_167 & V_13 ) {
F_54 ( V_2 , V_205 , V_208 ,
0 ) ;
F_75 ( V_2 , V_13 ) ;
V_2 -> V_207 |= V_13 ;
}
}
} else {
if ( V_2 -> V_185 & ( V_201 | V_202 ) ) {
F_10 ( L_32 ,
V_2 -> V_185 ) ;
if ( V_2 -> V_167 & V_12 ) {
F_54 ( V_2 , V_205 , V_206 ,
0 ) ;
V_2 -> V_207 |= V_12 ;
} else if ( V_2 -> V_167 & V_13 ) {
F_54 ( V_2 , V_205 , V_208 ,
0 ) ;
V_2 -> V_207 |= V_13 ;
} else if ( V_2 -> V_167 & V_11 ) {
F_54 ( V_2 , V_205 , V_209 ,
0 ) ;
V_2 -> V_207 |= V_11 ;
}
F_75 ( V_2 , V_12 ) ;
}
}
#endif
V_180:
if ( V_2 -> V_104 && V_2 -> V_150 &&
! V_2 -> V_168 && ! V_2 -> V_210 && ! V_2 -> V_38 ) {
int V_211 = V_2 -> V_212 && (
V_2 -> V_81 || V_2 -> V_165 ) ;
int V_213 = V_2 -> V_214 ;
int V_215 = V_213 +
V_2 -> V_216 ;
int V_217 = V_215 +
V_2 -> V_218 ;
if ( V_2 -> V_149 <= V_217 ) {
if ( V_2 -> V_149 == V_213 ) {
F_44 ( V_2 , V_179 ) ;
if ( V_2 -> V_24 && F_17 ( V_2 , 0x5208 ) )
F_76 ( V_2 , 0x1C , 2 ) ;
if ( V_2 -> V_167 ) {
F_10 ( L_33 ) ;
if ( V_211 )
F_54 ( V_2 , V_53 , 0x03 , 1 ) ;
F_54 ( V_2 ,
V_70 , 0x0A ,
0x0A ) ;
if ( V_211 )
F_77 ( V_2 ) ;
V_2 -> V_149 = V_217 + 1 ;
} else {
F_10 ( L_34 ) ;
if ( V_211 )
F_54 ( V_2 , V_53 , 0x03 , 1 ) ;
F_54 ( V_2 , V_70 , 0x02 , 0x02 ) ;
if ( V_211 )
F_77 ( V_2 ) ;
}
}
if ( V_2 -> V_149 == V_215 ) {
F_10 ( L_35 ) ;
if ( V_211 )
F_78 ( V_2 ) ;
if ( V_2 -> V_24 && F_17 ( V_2 , 0x5208 ) )
F_76 ( V_2 , 0x1C , 2 ) ;
F_54 ( V_2 , V_70 ,
0x0A , 0x0A ) ;
}
V_2 -> V_149 ++ ;
}
} else {
V_2 -> V_149 = 0 ;
}
}
void F_79 ( struct V_1 * V_2 )
{
V_2 -> V_150 = 0 ;
F_54 ( V_2 , V_70 , 0x0A , 0x00 ) ;
}
void F_80 ( struct V_1 * V_2 , int V_219 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 <= 8 ; V_8 ++ ) {
int V_220 = V_51 + V_8 * 4 ;
T_1 V_3 ;
V_3 = F_5 ( V_2 , V_220 ) ;
F_10 ( L_36 , V_220 , V_3 ) ;
}
F_6 ( V_2 , V_221 , V_222 ) ;
F_6 ( V_2 , V_223 , V_224 ) ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
T_3 V_220 = 0xFE20 + ( T_3 ) V_8 ;
T_2 V_119 ;
F_58 ( V_2 , V_220 , & V_119 ) ;
F_10 ( L_37 , V_220 , V_119 ) ;
}
F_54 ( V_2 , V_225 , 0x80 , 0x80 ) ;
F_54 ( V_2 , V_226 , 0x80 , 0x80 ) ;
}
int F_54 ( struct V_1 * V_2 , T_3 V_220 , T_2 V_227 , T_2 V_228 )
{
int V_8 ;
T_1 V_119 = 3 << 30 ;
V_119 |= ( T_1 ) ( V_220 & 0x3FFF ) << 16 ;
V_119 |= ( T_1 ) V_227 << 8 ;
V_119 |= ( T_1 ) V_228 ;
F_6 ( V_2 , V_229 , V_119 ) ;
for ( V_8 = 0 ; V_8 < V_230 ; V_8 ++ ) {
V_119 = F_5 ( V_2 , V_229 ) ;
if ( ( V_119 & ( 1 << 31 ) ) == 0 ) {
if ( V_228 != ( T_2 ) V_119 )
F_20 ( V_2 , V_48 ) ;
return V_40 ;
}
}
F_20 ( V_2 , V_231 ) ;
}
int F_58 ( struct V_1 * V_2 , T_3 V_220 , T_2 * V_228 )
{
T_1 V_119 = 2 << 30 ;
int V_8 ;
if ( V_228 )
* V_228 = 0 ;
V_119 |= ( T_1 ) ( V_220 & 0x3FFF ) << 16 ;
F_6 ( V_2 , V_229 , V_119 ) ;
for ( V_8 = 0 ; V_8 < V_230 ; V_8 ++ ) {
V_119 = F_5 ( V_2 , V_229 ) ;
if ( ( V_119 & ( 1 << 31 ) ) == 0 )
break;
}
if ( V_8 >= V_230 )
F_20 ( V_2 , V_231 ) ;
if ( V_228 )
* V_228 = ( T_2 ) ( V_119 & 0xFF ) ;
return V_40 ;
}
int F_26 ( struct V_1 * V_2 , T_2 V_232 , T_3 V_220 , T_1 V_227 ,
T_1 V_119 )
{
T_2 V_233 = 0 , V_41 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
if ( V_227 & 0xFF ) {
F_15 ( V_2 , V_234 + V_8 ,
0xFF , ( T_2 ) ( V_119 & V_227 & 0xFF ) ) ;
V_233 |= ( 1 << V_8 ) ;
}
V_227 >>= 8 ;
V_119 >>= 8 ;
}
if ( V_233 ) {
F_15 ( V_2 , V_235 , 0xFF , ( T_2 ) V_220 ) ;
F_15 ( V_2 , V_236 , 0xFF , ( T_2 ) ( V_220 >> 8 ) ) ;
F_15 ( V_2 , V_237 , 0xFF ,
0x80 | V_233 | ( ( V_232 & 0x03 ) << 4 ) ) ;
for ( V_8 = 0 ; V_8 < V_230 ; V_8 ++ ) {
F_18 ( V_2 , V_237 , & V_41 ) ;
if ( ( V_41 & 0x80 ) == 0 )
break;
}
}
return V_40 ;
}
int F_40 ( struct V_1 * V_2 , T_2 V_232 , T_3 V_220 , T_1 * V_119 )
{
int V_8 ;
T_2 V_41 ;
T_1 V_228 = 0 ;
F_15 ( V_2 , V_235 , 0xFF , ( T_2 ) V_220 ) ;
F_15 ( V_2 , V_236 , 0xFF , ( T_2 ) ( V_220 >> 8 ) ) ;
F_15 ( V_2 , V_237 , 0xFF , 0x80 | ( ( V_232 & 0x03 ) << 4 ) ) ;
for ( V_8 = 0 ; V_8 < V_230 ; V_8 ++ ) {
F_18 ( V_2 , V_237 , & V_41 ) ;
if ( ( V_41 & 0x80 ) == 0 )
break;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
F_18 ( V_2 , V_234 + V_8 , & V_41 ) ;
V_228 |= ( T_1 ) V_41 << ( V_8 * 8 ) ;
}
if ( V_119 )
* V_119 = V_228 ;
return V_40 ;
}
int F_81 ( struct V_1 * V_2 , T_2 V_238 , T_3 V_220 , T_2 * V_239 ,
int V_240 )
{
T_1 * V_228 , * V_227 ;
T_3 V_241 = V_220 % 4 ;
T_3 V_242 = V_220 - V_241 ;
int V_243 , V_8 , V_244 ;
int V_43 ;
F_10 ( L_38 , V_245 ) ;
if ( ! V_239 )
F_20 ( V_2 , V_246 ) ;
if ( ( V_240 + V_241 ) % 4 )
V_243 = ( V_240 + V_241 ) / 4 + 1 ;
else
V_243 = ( V_240 + V_241 ) / 4 ;
F_10 ( L_39 , V_243 ) ;
V_228 = F_82 ( V_243 * 4 ) ;
if ( ! V_228 )
F_20 ( V_2 , V_246 ) ;
V_227 = F_82 ( V_243 * 4 ) ;
if ( ! V_227 ) {
F_83 ( V_228 ) ;
F_20 ( V_2 , V_246 ) ;
}
V_244 = 0 ;
for ( V_8 = 0 ; V_8 < V_240 ; V_8 ++ ) {
V_227 [ V_244 ] |= 0xFF << ( V_241 * 8 ) ;
V_228 [ V_244 ] |= V_239 [ V_8 ] << ( V_241 * 8 ) ;
if ( ++ V_241 == 4 ) {
V_244 ++ ;
V_241 = 0 ;
}
}
F_84 ( V_227 , V_243 * 4 ) ;
F_84 ( V_228 , V_243 * 4 ) ;
for ( V_8 = 0 ; V_8 < V_243 ; V_8 ++ ) {
V_43 = F_26 ( V_2 , V_238 , V_242 + V_8 * 4 ,
V_227 [ V_8 ] , V_228 [ V_8 ] ) ;
if ( V_43 != V_40 ) {
F_83 ( V_228 ) ;
F_83 ( V_227 ) ;
F_20 ( V_2 , V_48 ) ;
}
}
F_83 ( V_228 ) ;
F_83 ( V_227 ) ;
return V_40 ;
}
int F_85 ( struct V_1 * V_2 , T_2 V_238 , T_3 V_220 , T_2 * V_239 ,
int V_240 )
{
T_1 * V_228 ;
T_3 V_241 = V_220 % 4 ;
T_3 V_242 = V_220 - V_241 ;
int V_243 , V_8 , V_244 ;
int V_43 ;
F_10 ( L_38 , V_245 ) ;
if ( ( V_240 + V_241 ) % 4 )
V_243 = ( V_240 + V_241 ) / 4 + 1 ;
else
V_243 = ( V_240 + V_241 ) / 4 ;
F_10 ( L_39 , V_243 ) ;
V_228 = F_86 ( V_243 * 4 ) ;
if ( ! V_228 )
F_20 ( V_2 , V_246 ) ;
for ( V_8 = 0 ; V_8 < V_243 ; V_8 ++ ) {
V_43 = F_40 ( V_2 , V_238 , V_242 + V_8 * 4 ,
V_228 + V_8 ) ;
if ( V_43 != V_40 ) {
F_83 ( V_228 ) ;
F_20 ( V_2 , V_48 ) ;
}
}
if ( V_239 ) {
V_244 = 0 ;
for ( V_8 = 0 ; V_8 < V_240 ; V_8 ++ ) {
V_239 [ V_8 ] = ( T_2 ) ( V_228 [ V_244 ] >> ( V_241 * 8 ) ) ;
if ( ++ V_241 == 4 ) {
V_244 ++ ;
V_241 = 0 ;
}
}
}
F_83 ( V_228 ) ;
return V_40 ;
}
int F_2 ( struct V_1 * V_2 , T_2 V_220 , T_3 V_119 )
{
int V_8 , V_247 = 0 ;
T_2 V_41 ;
F_15 ( V_2 , V_248 , 0xFF , ( T_2 ) V_119 ) ;
F_15 ( V_2 , V_249 , 0xFF , ( T_2 ) ( V_119 >> 8 ) ) ;
F_15 ( V_2 , V_250 , 0xFF , V_220 ) ;
F_15 ( V_2 , V_251 , 0xFF , 0x81 ) ;
for ( V_8 = 0 ; V_8 < 100000 ; V_8 ++ ) {
F_18 ( V_2 , V_251 , & V_41 ) ;
if ( ! ( V_41 & 0x80 ) ) {
V_247 = 1 ;
break;
}
}
if ( ! V_247 )
F_20 ( V_2 , V_48 ) ;
return V_40 ;
}
int F_28 ( struct V_1 * V_2 , T_2 V_220 , T_3 * V_119 )
{
int V_8 , V_247 = 0 ;
T_3 V_228 = 0 ;
T_2 V_41 ;
F_15 ( V_2 , V_250 , 0xFF , V_220 ) ;
F_15 ( V_2 , V_251 , 0xFF , 0x80 ) ;
for ( V_8 = 0 ; V_8 < 100000 ; V_8 ++ ) {
F_18 ( V_2 , V_251 , & V_41 ) ;
if ( ! ( V_41 & 0x80 ) ) {
V_247 = 1 ;
break;
}
}
if ( ! V_247 )
F_20 ( V_2 , V_48 ) ;
F_18 ( V_2 , V_248 , & V_41 ) ;
V_228 = V_41 ;
F_18 ( V_2 , V_249 , & V_41 ) ;
V_228 |= ( T_3 ) V_41 << 8 ;
if ( V_119 )
* V_119 = V_228 ;
return V_40 ;
}
int F_87 ( struct V_1 * V_2 , T_2 V_220 , T_2 * V_119 )
{
int V_8 ;
T_2 V_228 = 0 ;
F_15 ( V_2 , V_252 , 0xFF , 0x80 | V_220 ) ;
for ( V_8 = 0 ; V_8 < 100 ; V_8 ++ ) {
F_18 ( V_2 , V_252 , & V_228 ) ;
if ( ! ( V_228 & 0x80 ) )
break;
F_31 ( 1 ) ;
}
if ( V_228 & 0x80 )
F_20 ( V_2 , V_231 ) ;
F_18 ( V_2 , V_253 , & V_228 ) ;
if ( V_119 )
* V_119 = V_228 ;
return V_40 ;
}
int F_88 ( struct V_1 * V_2 , T_2 V_220 , T_2 V_119 )
{
int V_8 , V_244 ;
T_2 V_228 = 0 , V_41 = 0xFF ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
if ( V_119 & ( T_2 ) ( 1 << V_8 ) )
continue;
V_41 &= ( ~ ( T_2 ) ( 1 << V_8 ) ) ;
F_10 ( L_40 , V_41 , V_220 ) ;
F_15 ( V_2 , V_253 , 0xFF , V_41 ) ;
F_15 ( V_2 , V_252 , 0xFF , 0xA0 | V_220 ) ;
for ( V_244 = 0 ; V_244 < 100 ; V_244 ++ ) {
F_18 ( V_2 , V_252 , & V_228 ) ;
if ( ! ( V_228 & 0x80 ) )
break;
F_3 ( 3 ) ;
}
if ( V_228 & 0x80 )
F_20 ( V_2 , V_231 ) ;
F_3 ( 5 ) ;
}
return V_40 ;
}
int F_30 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_254 )
{
int V_43 ;
T_3 V_255 ;
V_43 = F_28 ( V_2 , V_3 , & V_255 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
if ( V_255 & ( 1 << V_254 ) ) {
V_255 &= ~ ( 1 << V_254 ) ;
V_43 = F_2 ( V_2 , V_3 , V_255 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
}
return V_40 ;
}
int F_76 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_254 )
{
int V_43 ;
T_3 V_255 ;
V_43 = F_28 ( V_2 , V_3 , & V_255 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
if ( 0 == ( V_255 & ( 1 << V_254 ) ) ) {
V_255 |= ( 1 << V_254 ) ;
V_43 = F_2 ( V_2 , V_3 , V_255 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
}
return V_40 ;
}
int F_89 ( struct V_1 * V_2 )
{
T_2 V_119 ;
F_18 ( V_2 , V_87 , & V_119 ) ;
F_10 ( L_41 , V_119 ) ;
if ( V_119 & V_88 ) {
F_10 ( L_42 ) ;
F_54 ( V_2 , V_87 , V_88 , V_88 ) ;
return V_48 ;
}
return V_40 ;
}
static void F_90 ( struct V_1 * V_2 , T_2 V_256 )
{
T_1 V_257 ;
F_10 ( L_43 , V_2 -> V_140 , V_256 ) ;
if ( F_14 ( V_2 ) ) {
T_2 V_232 ;
if ( F_17 ( V_2 , 0x5288 ) )
V_232 = 2 ;
else
V_232 = 1 ;
F_40 ( V_2 , V_232 , 0x84 , & V_257 ) ;
F_10 ( L_44 , ( int ) V_232 ,
V_257 ) ;
F_26 ( V_2 , V_232 , 0x84 , 0xFF , V_256 ) ;
}
F_27 ( V_2 , 0x44 , V_256 ) ;
F_27 ( V_2 , 0x45 , 0 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
F_90 ( V_2 , 2 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
F_27 ( V_2 , 0x44 , 0 ) ;
F_27 ( V_2 , 0x45 , 0 ) ;
}
void F_91 ( struct V_1 * V_2 )
{
F_10 ( L_45 ) ;
F_54 ( V_2 , V_87 , V_88 , V_88 ) ;
if ( V_2 -> V_258 ) {
F_92 ( V_2 ) ;
F_70 ( V_2 , V_197 | V_199 ) ;
}
if ( F_14 ( V_2 ) ) {
if ( F_17 ( V_2 , 0x5288 ) )
F_26 ( V_2 , 2 , 0xC0 , 0xFF00 , 0x0100 ) ;
else
F_26 ( V_2 , 1 , 0xC0 , 0xFF00 , 0x0100 ) ;
}
if ( V_2 -> V_104 ) {
F_54 ( V_2 , V_53 , 0x01 , 0x01 ) ;
} else {
if ( ! V_2 -> V_90 ) {
T_1 V_41 ;
V_41 = F_5 ( V_2 , V_4 ) ;
V_41 |= V_259 ;
F_6 ( V_2 , V_4 , V_41 ) ;
}
F_54 ( V_2 , V_70 , 0x02 , 0 ) ;
}
F_77 ( V_2 ) ;
F_93 ( V_2 ) ;
F_44 ( V_2 , V_182 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
F_10 ( L_46 ) ;
F_78 ( V_2 ) ;
if ( V_2 -> V_258 ) {
F_68 ( V_2 , V_197 | V_199 ) ;
F_31 ( 1000 ) ;
}
if ( F_95 ( V_2 ) ) {
V_2 -> V_189 = V_12 | V_13 | V_11 ;
F_96 ( V_2 , 1 ) ;
F_93 ( V_2 ) ;
} else if ( V_2 -> V_258 ) {
V_2 -> V_189 = V_12 | V_13 | V_11 ;
F_96 ( V_2 , 0 ) ;
}
}
int F_97 ( struct V_1 * V_2 )
{
T_1 V_260 , V_261 ;
int V_262 = 0 ;
#ifdef F_11
T_1 V_183 = 0 ;
V_183 = V_263 ;
#endif
if ( V_2 -> V_165 ) {
V_2 -> V_191 = 0 ;
if ( F_63 ( V_2 ) == V_182 ) {
V_262 = 1 ;
F_78 ( V_2 ) ;
F_44 ( V_2 , V_200 ) ;
}
}
V_261 = F_5 ( V_2 , V_4 ) ;
V_2 -> V_93 = F_5 ( V_2 , V_94 ) ;
if ( ( ( V_2 -> V_93 & V_261 ) == 0 ) ||
( V_2 -> V_93 == 0xFFFFFFFF ) )
return V_48 ;
V_260 = V_2 -> V_93 &= ( V_261 | 0x7FFFFF ) ;
if ( V_260 & V_259 ) {
V_2 -> V_149 = 0 ;
if ( V_260 & V_264 ) {
if ( V_260 & V_96 ) {
F_98 ( V_265 , & ( V_2 -> V_39 ) ) ;
} else {
F_98 ( V_265 , & ( V_2 -> V_266 ) ) ;
V_2 -> V_143 = 0 ;
V_2 -> V_147 = 0 ;
F_99 ( V_265 , & ( V_2 -> V_39 ) ) ;
}
} else {
if ( V_262 && ( V_260 & V_96 ) )
F_98 ( V_265 , & ( V_2 -> V_189 ) ) ;
}
if ( ! F_17 ( V_2 , 0x5288 ) || F_41 ( V_2 , V_128 ) ) {
if ( V_260 & V_267 ) {
if ( V_260 & V_97 ) {
F_98 ( V_268 , & ( V_2 -> V_39 ) ) ;
} else {
F_98 ( V_268 , & ( V_2 -> V_266 ) ) ;
V_2 -> V_142 = 0 ;
V_2 -> V_145 = 0 ;
F_99 ( V_268 , & ( V_2 -> V_39 ) ) ;
}
} else {
if ( V_262 && ( V_260 & V_97 ) )
F_98 ( V_268 , & ( V_2 -> V_189 ) ) ;
}
}
if ( V_260 & V_269 ) {
if ( V_260 & V_98 ) {
F_98 ( V_270 , & ( V_2 -> V_39 ) ) ;
} else {
F_98 ( V_270 , & ( V_2 -> V_266 ) ) ;
V_2 -> V_144 = 0 ;
V_2 -> V_148 = 0 ;
F_99 ( V_270 , & ( V_2 -> V_39 ) ) ;
}
} else {
if ( V_262 && ( V_260 & V_98 ) )
F_98 ( V_270 , & ( V_2 -> V_189 ) ) ;
}
}
#ifdef F_11
V_2 -> V_183 = V_183 & V_260 ;
#endif
if ( V_2 -> V_38 ) {
if ( V_2 -> V_93 & V_271 )
V_2 -> V_93 &= ~ ( T_1 ) V_271 ;
}
return V_40 ;
}
void F_100 ( struct V_1 * V_2 , int V_272 )
{
int V_43 ;
F_10 ( L_47 , V_272 ) ;
F_44 ( V_2 , V_178 ) ;
V_43 = F_68 ( V_2 , V_197 ) ;
if ( V_43 != V_40 )
return;
F_101 ( V_2 ) ;
F_12 ( V_2 ) ;
F_69 ( V_2 , V_172 ) ;
#ifdef F_29
if ( V_2 -> V_38 ) {
V_2 -> V_45 = 1 ;
if ( F_17 ( V_2 , 0x5208 ) ) {
F_54 ( V_2 , V_47 , 0x08 , 0x08 ) ;
F_54 ( V_2 , 0xFE70 , 0x80 , 0x80 ) ;
} else if ( F_17 ( V_2 , 0x5288 ) ) {
F_54 ( V_2 , V_47 , 0x08 , 0x08 ) ;
F_54 ( V_2 , 0xFE5A , 0x08 , 0x08 ) ;
}
}
#endif
if ( F_17 ( V_2 , 0x5208 ) && ( V_2 -> V_17 >= V_92 ) ) {
F_54 ( V_2 , V_108 , 0x08 , 0x08 ) ;
}
if ( V_272 == V_273 ) {
F_10 ( L_48 ) ;
F_54 ( V_2 , V_53 , 0x03 ,
V_274 ) ;
} else if ( V_272 == V_275 ) {
if ( V_2 -> V_276 > 0 )
F_3 ( V_2 -> V_276 ) ;
F_10 ( L_49 ) ;
F_54 ( V_2 , V_53 , 0x03 ,
V_277 ) ;
}
if ( V_2 -> V_278 && V_2 -> V_104 )
F_54 ( V_2 , V_70 , 0x02 , 2 ) ;
F_70 ( V_2 , V_197 | V_199 ) ;
V_2 -> V_279 = 0 ;
V_2 -> V_155 = 0 ;
V_2 -> V_167 = 0 ;
}
void F_73 ( struct V_1 * V_2 )
{
if ( V_2 -> V_81 && V_2 -> V_82 ) {
if ( ! V_2 -> V_86 ) {
F_10 ( L_50 ) ;
V_2 -> V_86 = 1 ;
if ( V_2 -> V_24 && F_17 ( V_2 , 0x5208 ) )
F_2 ( V_2 , 0x07 , 0 ) ;
if ( F_17 ( V_2 , 0x5208 ) ) {
F_54 ( V_2 , V_83 , 0xF3 ,
0x30 | V_2 -> V_85 [ 0 ] ) ;
} else {
F_27 ( V_2 , V_84 ,
V_2 -> V_81 ) ;
}
if ( F_14 ( V_2 ) ) {
T_3 V_119 = V_2 -> V_81 | 0x0100 ;
if ( F_17 ( V_2 , 0x5288 ) )
F_26 ( V_2 , 2 , 0xC0 ,
0xFFFF , V_119 ) ;
else
F_26 ( V_2 , 1 , 0xC0 ,
0xFFFF , V_119 ) ;
}
}
}
return;
}
void F_23 ( struct V_1 * V_2 )
{
if ( F_17 ( V_2 , 0x5208 ) )
F_52 ( V_2 ) ;
if ( V_2 -> V_81 && V_2 -> V_82 ) {
if ( V_2 -> V_86 ) {
F_10 ( L_51 ) ;
V_2 -> V_86 = 0 ;
if ( V_2 -> V_24 && F_17 ( V_2 , 0x5208 ) )
F_2 ( V_2 , 0x07 , 0x0129 ) ;
if ( F_17 ( V_2 , 0x5208 ) )
F_54 ( V_2 , V_83 ,
0xF3 , 0x30 ) ;
else
F_27 ( V_2 , V_84 , 0x00 ) ;
F_3 ( 1 ) ;
}
}
return;
}
int F_102 ( struct V_1 * V_2 , T_2 * V_239 , int V_280 )
{
int V_43 ;
int V_8 , V_244 ;
T_3 V_281 ;
T_2 * V_282 ;
if ( ! V_239 )
F_20 ( V_2 , V_283 ) ;
V_282 = V_239 ;
V_281 = V_284 ;
for ( V_8 = 0 ; V_8 < V_280 / 256 ; V_8 ++ ) {
F_103 ( V_2 ) ;
for ( V_244 = 0 ; V_244 < 256 ; V_244 ++ )
F_104 ( V_2 , V_285 , V_281 ++ , 0 , 0 ) ;
V_43 = F_105 ( V_2 , 0 , 250 ) ;
if ( V_43 < 0 )
F_20 ( V_2 , V_48 ) ;
memcpy ( V_282 , F_106 ( V_2 ) , 256 ) ;
V_282 += 256 ;
}
if ( V_280 % 256 ) {
F_103 ( V_2 ) ;
for ( V_244 = 0 ; V_244 < V_280 % 256 ; V_244 ++ )
F_104 ( V_2 , V_285 , V_281 ++ , 0 , 0 ) ;
V_43 = F_105 ( V_2 , 0 , 250 ) ;
if ( V_43 < 0 )
F_20 ( V_2 , V_48 ) ;
}
memcpy ( V_282 , F_106 ( V_2 ) , V_280 % 256 ) ;
return V_40 ;
}
int F_107 ( struct V_1 * V_2 , T_2 * V_239 , int V_280 )
{
int V_43 ;
int V_8 , V_244 ;
T_3 V_281 ;
T_2 * V_282 ;
if ( ! V_239 )
F_20 ( V_2 , V_283 ) ;
V_282 = V_239 ;
V_281 = V_284 ;
for ( V_8 = 0 ; V_8 < V_280 / 256 ; V_8 ++ ) {
F_103 ( V_2 ) ;
for ( V_244 = 0 ; V_244 < 256 ; V_244 ++ ) {
F_104 ( V_2 , V_286 , V_281 ++ , 0xFF ,
* V_282 ) ;
V_282 ++ ;
}
V_43 = F_105 ( V_2 , 0 , 250 ) ;
if ( V_43 < 0 )
F_20 ( V_2 , V_48 ) ;
}
if ( V_280 % 256 ) {
F_103 ( V_2 ) ;
for ( V_244 = 0 ; V_244 < V_280 % 256 ; V_244 ++ ) {
F_104 ( V_2 , V_286 , V_281 ++ , 0xFF ,
* V_282 ) ;
V_282 ++ ;
}
V_43 = F_105 ( V_2 , 0 , 250 ) ;
if ( V_43 < 0 )
F_20 ( V_2 , V_48 ) ;
}
return V_40 ;
}
int F_108 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 , 0 ) == 0xFFFFFFFF )
F_20 ( V_2 , V_48 ) ;
return V_40 ;
}
int F_68 ( struct V_1 * V_2 , T_2 V_287 )
{
int V_43 ;
T_2 V_227 = 0 ;
if ( V_287 & V_197 )
V_227 |= V_163 ;
#ifdef F_11
if ( V_287 & V_199 ) {
V_227 |= V_288 ;
if ( F_24 ( V_2 , V_55 ) )
V_227 |= V_58 ;
}
#endif
if ( V_227 ) {
V_43 = F_54 ( V_2 , V_56 , V_227 , 0 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
if ( F_17 ( V_2 , 0x5288 ) )
F_3 ( 200 ) ;
}
return V_40 ;
}
int F_70 ( struct V_1 * V_2 , T_2 V_287 )
{
int V_43 ;
T_2 V_227 = 0 , V_119 = 0 ;
if ( V_287 & V_197 )
V_227 |= V_163 ;
#ifdef F_11
if ( V_287 & V_199 ) {
V_227 |= V_288 ;
if ( F_24 ( V_2 , V_55 ) )
V_227 |= V_58 ;
}
#endif
if ( V_227 ) {
V_119 = V_227 ;
V_43 = F_54 ( V_2 , V_56 , V_227 , V_119 ) ;
if ( V_43 != V_40 )
F_20 ( V_2 , V_48 ) ;
}
return V_40 ;
}
