static void F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_2 ( V_4 , V_5 ) ;
}
static int
F_3 ( struct V_6 * V_7 , const struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
static int V_12 ;
int V_13 = V_9 -> V_14 ;
int V_15 , V_16 ;
void T_1 * V_3 ;
static int V_17 ;
void * V_18 ;
T_2 V_19 ;
if ( ! V_17 ++ )
F_4 ( L_1 , V_20 ) ;
V_15 = F_5 ( V_7 ) ;
if ( V_15 )
return V_15 ;
V_16 = V_7 -> V_16 ;
V_15 = F_6 ( V_7 , L_2 ) ;
if ( V_15 )
goto V_21;
F_7 ( V_7 ) ;
V_15 = - V_22 ;
V_11 = F_8 ( sizeof ( * V_2 ) ) ;
if ( ! V_11 )
goto V_23;
F_9 ( V_11 , & V_7 -> V_11 ) ;
V_2 = F_10 ( V_11 ) ;
V_3 = F_11 ( V_7 , 0 , 0 ) ;
if ( ! V_3 )
goto V_24;
V_2 -> V_25 = V_3 ;
#ifdef F_12
V_3 = F_11 ( V_7 , 1 , 0 ) ;
if ( ! V_3 )
goto V_26;
#endif
V_2 -> V_3 = V_3 ;
V_2 -> V_27 = V_13 ;
V_2 -> V_7 = V_7 ;
F_13 ( & V_2 -> V_28 ) ;
F_13 ( & V_2 -> V_29 ) ;
V_2 -> V_30 = 1 ;
V_2 -> V_31 = 1 ;
if ( V_12 < V_32 ) {
if ( V_33 [ V_12 ] != NULL ) {
V_2 -> V_30 = 0 ;
if ( strcmp ( V_33 [ V_12 ] , L_3 ) == 0 ||
strcmp ( V_33 [ V_12 ] , L_4 ) == 0 ||
strcmp ( V_33 [ V_12 ] , L_5 ) == 0 ) {
V_2 -> V_30 = 2 ;
} else if ( strcmp ( V_33 [ V_12 ] , L_6 ) == 0 ||
strcmp ( V_33 [ V_12 ] , L_7 ) == 0 ) {
V_2 -> V_34 = 100 ;
V_2 -> V_35 = 1 ;
} else if ( strcmp ( V_33 [ V_12 ] , L_8 ) == 0 ||
strcmp ( V_33 [ V_12 ] , L_9 ) == 0 ) {
V_2 -> V_34 = 100 ;
V_2 -> V_35 = 0 ;
} else if ( strcmp ( V_33 [ V_12 ] , L_10 ) == 0 ||
strcmp ( V_33 [ V_12 ] , L_11 ) == 0 ) {
V_2 -> V_34 = 10 ;
V_2 -> V_35 = 1 ;
} else if ( strcmp ( V_33 [ V_12 ] , L_12 ) == 0 ||
strcmp ( V_33 [ V_12 ] , L_13 ) == 0 ) {
V_2 -> V_34 = 10 ;
V_2 -> V_35 = 0 ;
} else if ( strcmp ( V_33 [ V_12 ] , L_14 ) == 0 ||
strcmp ( V_33 [ V_12 ] , L_15 ) == 0 ) {
V_2 -> V_34 = 1000 ;
V_2 -> V_35 = 1 ;
} else if ( strcmp ( V_33 [ V_12 ] , L_16 ) == 0 ||
strcmp ( V_33 [ V_12 ] , L_17 ) == 0 ) {
V_2 -> V_34 = 1000 ;
V_2 -> V_35 = 0 ;
} else {
V_2 -> V_30 = 1 ;
}
}
if ( V_36 [ V_12 ] != 0 ) {
V_2 -> V_36 = 1 ;
V_11 -> V_37 = V_38 ;
} else {
V_2 -> V_36 = 0 ;
if ( V_37 [ V_12 ] > 0 && V_37 [ V_12 ] < V_39 )
V_11 -> V_37 = V_37 [ V_12 ] ;
}
V_2 -> V_40 = ( V_40 [ V_12 ] > 0 && V_40 [ V_12 ] < 4096 ) ?
V_40 [ V_12 ] : 0 ;
if ( V_41 > 0 && V_42 > 0 ) {
V_2 -> V_41 = V_41 ;
V_2 -> V_42 = V_42 ;
V_2 -> V_43 = 1 ;
}
V_2 -> V_44 = ( V_44 == 0 ) ? 0 : 1 ;
V_2 -> V_45 = ( V_45 == 0 ) ? 0 : 1 ;
if ( V_31 < 1 )
V_31 = 1 ;
else if ( V_31 > V_46 - 1 )
V_31 = V_46 - 1 ;
}
V_11 -> V_47 = & V_47 ;
V_11 -> V_48 = V_49 ;
V_11 -> V_50 = & V_50 ;
#if 0
dev->features = NETIF_F_IP_CSUM;
#endif
F_14 ( V_7 , V_11 ) ;
V_18 = F_15 ( V_7 , V_51 , & V_19 ) ;
if ( ! V_18 )
goto V_26;
V_2 -> V_52 = V_18 ;
V_2 -> V_53 = V_19 ;
V_18 = F_15 ( V_7 , V_54 , & V_19 ) ;
if ( ! V_18 )
goto V_55;
V_2 -> V_56 = V_18 ;
V_2 -> V_57 = V_19 ;
F_16 ( V_11 ) ;
V_15 = F_17 ( V_11 ) ;
if ( V_15 )
goto V_58;
V_2 -> V_59 = ( F_18 ( V_60 ) & V_61 ) ? 1 : 0 ;
V_2 -> V_62 = 0 ;
if ( V_2 -> V_59 ) {
if ( V_2 -> V_30 == 2 ) {
V_2 -> V_30 = 1 ;
}
F_19 ( V_11 ) ;
} else {
if ( V_2 -> V_34 == 1000 )
V_2 -> V_30 = 1 ;
F_20 ( V_11 ) ;
}
V_15 = F_21 ( V_11 ) ;
if ( V_15 )
goto V_58;
V_12 ++ ;
F_4 ( V_63 L_18 ,
V_11 -> V_64 , V_2 -> V_64 , V_11 -> V_65 , V_16 ) ;
if ( V_31 > 1 )
F_4 ( V_63 L_19 ,
V_31 ) ;
if ( V_2 -> V_43 )
F_4 ( V_63
L_20
L_21 ,
V_2 -> V_41 , V_2 -> V_42 * 640 ) ;
if ( V_2 -> V_40 )
F_4 ( V_63 L_22 , V_2 -> V_40 ) ;
return 0 ;
V_58:
F_22 ( V_7 , V_54 , V_2 -> V_56 , V_2 -> V_57 ) ;
V_55:
F_22 ( V_7 , V_51 , V_2 -> V_52 , V_2 -> V_53 ) ;
V_26:
#ifdef F_12
F_23 ( V_7 , V_2 -> V_3 ) ;
#endif
F_23 ( V_7 , V_2 -> V_25 ) ;
V_24:
F_24 ( V_11 ) ;
V_23:
F_25 ( V_7 ) ;
V_21:
F_26 ( V_7 ) ;
return V_15 ;
}
static int
F_17 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
int V_66 , V_67 = 0 ;
V_2 = F_10 ( V_11 ) ;
V_2 -> V_68 = 1 ;
for ( V_66 = 31 ; V_66 >= 0 ; V_66 -- ) {
int V_69 = F_27 ( V_11 , V_66 , 1 ) ;
if ( V_69 != 0xffff && V_69 != 0x0000 ) {
V_2 -> V_68 = V_66 ;
V_67 ++ ;
}
}
if ( ! V_67 ) {
F_4 ( V_70 L_23 , V_11 -> V_64 ) ;
return - V_71 ;
}
return 0 ;
}
static int
F_16 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
int V_66 , V_72 ;
T_3 V_73 [ 256 ] ;
T_3 * V_74 ;
T_4 V_75 ;
T_5 V_76 = ( T_5 ) V_73 ;
int V_77 , V_78 ;
for ( V_66 = 0 ; V_66 < 128 ; V_66 ++ )
( ( V_79 * ) V_73 ) [ V_66 ] = F_28 ( F_29 ( V_2 , V_66 ) ) ;
if ( V_2 -> V_7 -> V_80 == V_81 ) {
V_75 = ~ F_30 ( 256 - 4 , V_73 ) ;
if ( V_76 -> V_75 != F_31 ( V_75 ) ) {
F_4 ( V_70 L_24 ,
V_11 -> V_64 ) ;
return - 1 ;
}
}
for ( V_66 = 0 ; V_66 < 6 ; V_66 ++ )
V_11 -> V_65 [ V_66 ] = V_76 -> V_82 [ V_66 ] ;
if ( V_2 -> V_7 -> V_80 != V_81 ) {
return 0 ;
}
V_66 = 0x30 ;
V_74 = ( T_3 * ) V_73 ;
do {
V_77 = V_74 [ V_66 ++ ] ;
V_78 = V_74 [ V_66 ++ ] ;
if ( ( V_77 == 0 && V_78 == 0 ) || ( V_77 == 0xff && V_78 == 0xff ) ) {
F_4 ( V_70 L_25 ) ;
return - 1 ;
}
switch ( V_77 ) {
case 0 :
break;
case 1 :
return 0 ;
case 2 :
V_2 -> V_83 = V_74 [ V_66 ] ;
F_32 ( V_84 , F_33 ( V_84 ) | V_74 [ V_66 ] ) ;
break;
case 3 :
V_2 -> V_85 = V_74 [ V_66 ] ;
break;
case 9 :
V_72 = ( V_78 - V_66 > 255 ) ? 255 : V_78 - V_66 ;
memcpy ( V_2 -> V_64 , & ( V_74 [ V_66 ] ) , V_72 ) ;
break;
case 4 :
case 5 :
case 6 :
case 7 :
case 8 :
break;
default:
return - 1 ;
}
V_66 = V_78 ;
} while ( 1 );
return 0 ;
}
static int
F_34 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
const int V_16 = V_2 -> V_7 -> V_16 ;
int V_66 ;
T_6 V_86 ;
V_66 = F_35 ( V_16 , V_87 , V_88 , V_11 -> V_64 , V_11 ) ;
if ( V_66 )
return V_66 ;
F_2 ( V_60 + 2 ,
V_89 | V_90 | V_91 | V_92 | V_93 ) ;
F_36 ( 10 ) ;
F_37 ( V_94 , F_38 ( V_94 ) | 0x0230 ) ;
if ( V_2 -> V_36 != 0 )
F_2 ( V_95 , V_38 + 14 ) ;
F_39 ( V_11 ) ;
for ( V_66 = 0 ; V_66 < 6 ; V_66 ++ )
F_32 ( V_96 + V_66 , V_11 -> V_65 [ V_66 ] ) ;
F_40 ( V_11 ) ;
if ( V_2 -> V_43 ) {
F_37 ( V_97 , V_2 -> V_41 | V_2 -> V_42 << 16 ) ;
}
F_32 ( V_98 , 0x20 ) ;
F_32 ( V_99 , 0xff ) ;
F_32 ( V_100 , 0x30 ) ;
F_32 ( V_101 , 0x30 ) ;
F_37 ( V_102 , 0x0007ffff ) ;
F_41 ( V_11 ) ;
if ( V_2 -> V_40 ) {
F_37 ( V_97 , F_38 ( V_97 ) | 0x7 << 10 ) ;
F_2 ( V_103 , V_2 -> V_40 ) ;
F_37 ( V_104 , 0x8100 << 16 | V_2 -> V_40 ) ;
F_37 ( V_105 , F_38 ( V_105 ) | V_106 ) ;
}
F_42 ( & V_2 -> V_107 , V_108 , ( unsigned long ) V_11 ) ;
V_2 -> V_107 . V_109 = V_110 + 1 * V_111 ;
F_43 ( & V_2 -> V_107 ) ;
F_37 ( V_105 , F_38 ( V_105 ) | V_112 | V_113 | V_114 ) ;
V_86 = 0 ;
V_86 |= ( V_2 -> V_40 ) ? V_106 : 0 ;
V_86 |= ( V_2 -> V_35 ) ? V_115 : 0 ;
V_86 |= ( V_2 -> V_44 ) ? V_116 : 0 ;
V_86 |= ( V_2 -> V_45 ) ? V_117 : 0 ;
F_2 ( V_105 , V_86 ) ;
F_44 ( V_11 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void
V_108 ( unsigned long V_118 )
{
struct V_10 * V_11 = (struct V_10 * ) V_118 ;
struct V_1 * V_2 = F_10 ( V_11 ) ;
unsigned int V_119 ;
int V_120 = 1 * V_111 ;
unsigned long V_121 ;
F_45 ( & V_2 -> V_29 , V_121 ) ;
if ( V_2 -> V_122 - V_2 -> V_123 >= V_124 ) {
F_4 ( V_63 L_26 ) ;
for (; V_2 -> V_122 - V_2 -> V_123 > 0 ; V_2 -> V_123 ++ ) {
struct V_125 * V_126 ;
V_119 = V_2 -> V_123 % V_124 ;
if ( V_2 -> V_127 [ V_119 ] == NULL ) {
V_126 = F_46 ( V_11 ,
V_2 -> V_128 ) ;
if ( V_126 == NULL ) {
V_2 -> V_56 [ V_119 ] . V_129 = 0 ;
F_4 ( V_63
L_27 ,
V_11 -> V_64 , V_119 ) ;
break;
}
V_2 -> V_127 [ V_119 ] = V_126 ;
V_2 -> V_56 [ V_119 ] . V_129 =
F_47 ( F_48
( V_2 -> V_7 , V_126 -> V_118 , V_2 -> V_128 ,
V_130 ) ) ;
}
V_2 -> V_56 [ V_119 ] . V_129 |=
F_47 ( ( V_131 ) V_2 -> V_128 << 48 ) ;
V_2 -> V_56 [ V_119 ] . V_132 = 0 ;
}
}
F_49 ( & V_2 -> V_29 , V_121 ) ;
V_2 -> V_107 . V_109 = V_110 + V_120 ;
F_43 ( & V_2 -> V_107 ) ;
}
static void
F_50 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
F_4 ( V_63 L_28 ,
V_11 -> V_64 , F_38 ( V_133 ) ) ;
F_51 ( V_11 , 0 ) ;
V_11 -> V_134 = 0 ;
V_11 -> V_135 = V_110 ;
}
static void
F_39 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
int V_66 ;
V_2 -> V_122 = V_2 -> V_136 = 0 ;
V_2 -> V_123 = V_2 -> V_137 = 0 ;
V_2 -> V_128 = ( V_11 -> V_37 <= 1500 ? V_39 : V_11 -> V_37 + 32 ) ;
for ( V_66 = 0 ; V_66 < V_46 ; V_66 ++ ) {
V_2 -> V_138 [ V_66 ] = NULL ;
V_2 -> V_52 [ V_66 ] . V_132 = F_47 ( V_139 ) ;
V_2 -> V_52 [ V_66 ] . V_140 = F_47 ( V_2 -> V_53 +
( ( V_66 + 1 ) % V_46 ) *
sizeof ( struct V_141 ) ) ;
}
for ( V_66 = 0 ; V_66 < V_124 ; V_66 ++ ) {
V_2 -> V_56 [ V_66 ] . V_140 = F_47 ( V_2 -> V_57 +
( ( V_66 + 1 ) % V_124 ) *
sizeof ( struct V_141 ) ) ;
V_2 -> V_56 [ V_66 ] . V_132 = 0 ;
V_2 -> V_56 [ V_66 ] . V_129 = 0 ;
V_2 -> V_127 [ V_66 ] = NULL ;
}
for ( V_66 = 0 ; V_66 < V_124 ; V_66 ++ ) {
struct V_125 * V_126 ;
V_126 = F_46 ( V_11 , V_2 -> V_128 ) ;
V_2 -> V_127 [ V_66 ] = V_126 ;
if ( V_126 == NULL )
break;
V_2 -> V_56 [ V_66 ] . V_129 =
F_47 ( F_48 (
V_2 -> V_7 , V_126 -> V_118 , V_2 -> V_128 ,
V_130 ) ) ;
V_2 -> V_56 [ V_66 ] . V_129 |= F_47 ( ( V_131 ) V_2 -> V_128 << 48 ) ;
}
F_37 ( V_142 , V_2 -> V_57 ) ;
F_37 ( V_143 , 0 ) ;
}
static T_7
F_52 ( struct V_125 * V_126 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
struct V_141 * V_144 ;
unsigned V_119 ;
V_131 V_145 = 0 ;
if ( V_2 -> V_62 == 0 ) {
F_53 ( V_126 ) ;
return V_146 ;
}
V_119 = V_2 -> V_136 % V_46 ;
V_2 -> V_138 [ V_119 ] = V_126 ;
V_144 = & V_2 -> V_52 [ V_119 ] ;
#if 0
if (skb->ip_summed == CHECKSUM_PARTIAL) {
txdesc->status |=
cpu_to_le64 (TCPChecksumEnable | UDPChecksumEnable |
IPChecksumEnable);
}
#endif
if ( V_2 -> V_40 ) {
V_145 = V_147 |
( ( V_131 ) V_2 -> V_40 << 32 ) |
( ( V_131 ) V_126 -> V_148 << 45 ) ;
}
V_144 -> V_129 = F_47 ( F_48 ( V_2 -> V_7 , V_126 -> V_118 ,
V_126 -> V_149 ,
V_150 ) ) ;
V_144 -> V_129 |= F_47 ( ( V_131 ) V_126 -> V_149 << 48 ) ;
if ( V_119 % V_2 -> V_31 == 0 || V_2 -> V_34 == 10 )
V_144 -> V_132 = F_47 ( V_119 | V_145 |
V_151 |
V_152 |
( 1 << V_153 ) ) ;
else
V_144 -> V_132 = F_47 ( V_119 | V_145 |
V_151 |
( 1 << V_153 ) ) ;
F_37 ( V_154 , F_38 ( V_154 ) | 0x00001000 ) ;
F_37 ( V_155 , 10000 ) ;
V_2 -> V_136 = ( V_2 -> V_136 + 1 ) % V_46 ;
if ( ( V_2 -> V_136 - V_2 -> V_137 + V_46 ) % V_46
< V_156 - 1 && V_2 -> V_34 != 10 ) {
} else if ( ! F_54 ( V_11 ) ) {
F_55 ( V_11 ) ;
}
if ( ! F_38 ( V_157 ) ) {
F_37 ( V_157 , V_2 -> V_53 +
V_119 * sizeof ( struct V_141 ) ) ;
F_37 ( V_158 , 0 ) ;
}
return V_146 ;
}
static T_8
V_87 ( int V_16 , void * V_159 )
{
struct V_10 * V_11 = V_159 ;
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
unsigned V_160 ;
int V_161 = V_162 ;
int V_163 = 0 ;
while ( 1 ) {
V_160 = F_18 ( V_164 ) ;
F_2 ( V_164 , V_160 ) ;
V_160 &= V_5 ;
if ( V_160 == 0 || -- V_161 < 0 )
break;
V_163 = 1 ;
if ( V_160 & V_165 )
F_56 ( V_11 ) ;
if ( ( V_160 & ( V_166 | V_167 ) ) ) {
int V_168 ;
V_168 = F_38 ( V_133 ) ;
if ( V_168 & 0x01 )
F_57 ( V_11 , V_168 ) ;
F_51 ( V_11 , 1 ) ;
}
if ( V_160 &
( V_169 | V_170 | V_171 ) )
F_58 ( V_11 , V_160 ) ;
}
if ( V_2 -> V_136 != V_2 -> V_137 )
F_37 ( V_155 , 100 ) ;
return F_59 ( V_163 ) ;
}
static inline T_2 F_60 ( struct V_141 * V_172 )
{
return F_61 ( V_172 -> V_129 ) & F_62 ( 48 ) ;
}
static void
F_51 ( struct V_10 * V_11 , int V_16 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
int V_119 = V_2 -> V_137 % V_46 ;
int V_173 = 0 ;
unsigned long V_174 = 0 ;
if ( V_16 )
F_63 ( & V_2 -> V_28 ) ;
else
F_45 ( & V_2 -> V_28 , V_174 ) ;
while ( V_119 != V_2 -> V_136 ) {
struct V_125 * V_126 ;
if ( ! ( V_2 -> V_52 [ V_119 ] . V_132 & F_47 ( V_139 ) ) )
break;
V_126 = V_2 -> V_138 [ V_119 ] ;
F_64 ( V_2 -> V_7 ,
F_60 ( & V_2 -> V_52 [ V_119 ] ) ,
V_126 -> V_149 , V_150 ) ;
if ( V_16 )
F_65 ( V_126 ) ;
else
F_53 ( V_126 ) ;
V_2 -> V_138 [ V_119 ] = NULL ;
V_119 = ( V_119 + 1 ) % V_46 ;
V_173 ++ ;
}
if ( V_16 )
F_66 ( & V_2 -> V_28 ) ;
else
F_49 ( & V_2 -> V_28 , V_174 ) ;
V_2 -> V_137 = V_119 ;
if ( F_54 ( V_11 ) &&
( ( V_2 -> V_136 - V_2 -> V_137 + V_46 ) % V_46
< V_156 - 1 || V_2 -> V_34 == 10 ) ) {
F_67 ( V_11 ) ;
}
}
static void
F_57 ( struct V_10 * V_11 , int V_168 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
int V_175 ;
int V_66 ;
V_175 = ( V_168 & 0xffff0000 ) ;
F_4 ( V_70 L_29 ,
V_11 -> V_64 , V_168 , V_175 ) ;
V_2 -> V_176 . V_177 ++ ;
if ( V_168 & 0x10 ) {
V_2 -> V_176 . V_178 ++ ;
F_2 ( V_179 , F_18 ( V_179 ) + 0x10 ) ;
F_2 ( V_60 + 2 ,
V_180 | V_90 | V_91 | V_92 ) ;
for ( V_66 = 50 ; V_66 > 0 ; V_66 -- ) {
if ( ! ( F_18 ( V_60 + 2 ) & V_181 ) )
break;
F_36 ( 1 ) ;
}
F_51 ( V_11 , 1 ) ;
F_37 ( V_157 , V_2 -> V_53 +
V_2 -> V_137 * sizeof ( struct V_141 ) ) ;
F_37 ( V_158 , 0 ) ;
}
if ( V_168 & 0x04 ) {
V_2 -> V_176 . V_178 ++ ;
F_2 ( V_60 + 2 , V_180 | V_91 ) ;
for ( V_66 = 50 ; V_66 > 0 ; V_66 -- ) {
if ( ! ( F_18 ( V_60 + 2 ) & V_181 ) )
break;
F_36 ( 1 ) ;
}
}
#ifdef F_68
if ( V_168 & 0x08 )
V_2 -> V_176 . V_182 ++ ;
#else
if ( V_168 & 0x08 )
V_2 -> V_176 . V_183 ++ ;
#endif
F_37 ( V_105 , F_18 ( V_105 ) | V_114 ) ;
}
static int
F_56 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
int V_119 = V_2 -> V_122 % V_124 ;
int V_161 = 30 ;
while ( 1 ) {
struct V_141 * V_172 = & V_2 -> V_56 [ V_119 ] ;
int V_184 ;
V_131 V_185 ;
if ( ! ( V_172 -> V_132 & F_47 ( V_186 ) ) ||
! ( V_172 -> V_132 & F_47 ( V_187 ) ) ||
! ( V_172 -> V_132 & F_47 ( V_188 ) ) )
break;
V_185 = F_61 ( V_172 -> V_132 ) ;
V_184 = V_185 & 0xffff ;
if ( -- V_161 < 0 )
break;
if ( V_185 & V_189 ) {
V_2 -> V_176 . V_190 ++ ;
if ( V_185 & ( V_191 | V_192 ) )
V_2 -> V_176 . V_193 ++ ;
if ( V_185 & V_194 )
V_2 -> V_176 . V_195 ++ ;
if ( V_185 & V_196 && V_2 -> V_34 != 1000 )
V_2 -> V_176 . V_197 ++ ;
if ( V_185 & V_198 )
V_2 -> V_176 . V_199 ++ ;
} else {
struct V_125 * V_126 ;
if ( V_184 > V_200 ) {
F_64 ( V_2 -> V_7 ,
F_60 ( V_172 ) ,
V_2 -> V_128 ,
V_130 ) ;
F_69 ( V_126 = V_2 -> V_127 [ V_119 ] , V_184 ) ;
V_2 -> V_127 [ V_119 ] = NULL ;
} else if ( ( V_126 = F_46 ( V_11 , V_184 ) ) ) {
F_70 ( V_2 -> V_7 ,
F_60 ( V_172 ) ,
V_2 -> V_128 ,
V_130 ) ;
F_71 ( V_126 ,
V_2 -> V_127 [ V_119 ] -> V_118 ,
V_184 ) ;
F_69 ( V_126 , V_184 ) ;
F_72 ( V_2 -> V_7 ,
F_60 ( V_172 ) ,
V_2 -> V_128 ,
V_130 ) ;
}
V_126 -> V_201 = F_73 ( V_126 , V_11 ) ;
#if 0
if (np->pdev->pci_rev_id >= 0x0c &&
!(frame_status & (TCPError | UDPError | IPError))) {
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
#endif
F_74 ( V_126 ) ;
}
V_119 = ( V_119 + 1 ) % V_124 ;
}
F_63 ( & V_2 -> V_29 ) ;
V_2 -> V_122 = V_119 ;
V_119 = V_2 -> V_123 ;
while ( V_119 != V_2 -> V_122 ) {
struct V_125 * V_126 ;
if ( V_2 -> V_127 [ V_119 ] == NULL ) {
V_126 = F_46 ( V_11 , V_2 -> V_128 ) ;
if ( V_126 == NULL ) {
V_2 -> V_56 [ V_119 ] . V_129 = 0 ;
F_4 ( V_63
L_30
L_31 ,
V_11 -> V_64 , V_119 ) ;
break;
}
V_2 -> V_127 [ V_119 ] = V_126 ;
V_2 -> V_56 [ V_119 ] . V_129 =
F_47 ( F_48
( V_2 -> V_7 , V_126 -> V_118 , V_2 -> V_128 ,
V_130 ) ) ;
}
V_2 -> V_56 [ V_119 ] . V_129 |=
F_47 ( ( V_131 ) V_2 -> V_128 << 48 ) ;
V_2 -> V_56 [ V_119 ] . V_132 = 0 ;
V_119 = ( V_119 + 1 ) % V_124 ;
}
V_2 -> V_123 = V_119 ;
F_66 ( & V_2 -> V_29 ) ;
return 0 ;
}
static void
F_58 ( struct V_10 * V_11 , int V_160 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
T_6 V_86 ;
if ( V_160 & V_170 ) {
if ( F_75 ( V_11 , 10 ) == 0 ) {
F_4 ( V_63 L_32 , V_11 -> V_64 ) ;
if ( V_2 -> V_59 )
F_76 ( V_11 ) ;
else
F_77 ( V_11 ) ;
if ( V_2 -> V_34 == 1000 )
V_2 -> V_31 = V_31 ;
else
V_2 -> V_31 = 1 ;
V_86 = 0 ;
V_86 |= ( V_2 -> V_40 ) ? V_106 : 0 ;
V_86 |= ( V_2 -> V_35 ) ? V_115 : 0 ;
V_86 |= ( V_2 -> V_44 ) ?
V_116 : 0 ;
V_86 |= ( V_2 -> V_45 ) ?
V_117 : 0 ;
F_2 ( V_105 , V_86 ) ;
V_2 -> V_62 = 1 ;
F_78 ( V_11 ) ;
} else {
F_4 ( V_63 L_33 , V_11 -> V_64 ) ;
V_2 -> V_62 = 0 ;
F_79 ( V_11 ) ;
}
}
if ( V_160 & V_171 ) {
F_80 ( V_11 ) ;
}
if ( V_160 & V_169 ) {
F_4 ( V_70 L_34 ,
V_11 -> V_64 , V_160 ) ;
F_2 ( V_60 + 2 , V_89 | V_93 ) ;
F_36 ( 500 ) ;
}
}
static struct V_202 *
F_80 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
#ifdef F_12
int V_66 ;
#endif
unsigned int V_203 ;
V_2 -> V_176 . V_204 += F_38 ( V_205 ) ;
V_2 -> V_176 . V_206 += F_38 ( V_207 ) ;
V_2 -> V_176 . V_208 += F_38 ( V_209 ) ;
V_2 -> V_176 . V_210 += F_38 ( V_211 ) ;
V_2 -> V_176 . V_212 = F_38 ( V_213 ) ;
V_2 -> V_176 . V_183 += F_38 ( V_214 )
+ F_38 ( V_215 ) ;
V_203 = F_18 ( V_216 ) ;
V_2 -> V_176 . V_217 += V_203 ;
V_2 -> V_176 . V_177 += V_203 ;
V_203 = F_18 ( V_218 ) ;
V_2 -> V_176 . V_219 += V_203 ;
V_2 -> V_176 . V_177 += V_203 ;
F_38 ( V_220 ) ;
F_18 ( V_221 ) ;
F_38 ( V_222 ) ;
F_18 ( V_223 ) ;
F_18 ( V_224 ) ;
F_18 ( V_225 ) ;
F_18 ( V_226 ) ;
F_18 ( V_227 ) ;
F_18 ( V_228 ) ;
F_38 ( V_220 ) ;
F_38 ( V_229 ) ;
F_38 ( V_222 ) ;
F_38 ( V_230 ) ;
F_38 ( V_231 ) ;
F_18 ( V_221 ) ;
F_18 ( V_232 ) ;
F_18 ( V_233 ) ;
#ifdef F_12
for ( V_66 = 0x100 ; V_66 <= 0x150 ; V_66 += 4 )
F_38 ( V_66 ) ;
#endif
F_18 ( V_234 ) ;
F_18 ( V_235 ) ;
F_18 ( V_236 ) ;
F_18 ( V_237 ) ;
F_18 ( V_238 ) ;
return & V_2 -> V_176 ;
}
static int
F_41 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
#ifdef F_12
int V_66 ;
#endif
F_38 ( V_205 ) ;
F_38 ( V_207 ) ;
F_38 ( V_209 ) ;
F_38 ( V_211 ) ;
F_38 ( V_213 ) ;
F_38 ( V_214 ) ;
F_38 ( V_215 ) ;
F_38 ( V_231 ) ;
F_18 ( V_225 ) ;
F_18 ( V_226 ) ;
F_18 ( V_227 ) ;
F_18 ( V_228 ) ;
F_18 ( V_216 ) ;
F_18 ( V_218 ) ;
F_38 ( V_220 ) ;
F_18 ( V_221 ) ;
F_38 ( V_222 ) ;
F_18 ( V_223 ) ;
F_18 ( V_224 ) ;
F_38 ( V_220 ) ;
F_38 ( V_229 ) ;
F_38 ( V_222 ) ;
F_38 ( V_230 ) ;
F_18 ( V_221 ) ;
F_18 ( V_232 ) ;
F_18 ( V_233 ) ;
#ifdef F_12
for ( V_66 = 0x100 ; V_66 <= 0x150 ; V_66 += 4 )
F_38 ( V_66 ) ;
#endif
F_18 ( V_234 ) ;
F_18 ( V_235 ) ;
F_18 ( V_236 ) ;
F_18 ( V_237 ) ;
F_18 ( V_238 ) ;
return 0 ;
}
static int
F_81 ( struct V_10 * V_11 , int V_239 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
int V_240 = ( V_2 -> V_36 ) ? V_38 : 1536 ;
if ( ( V_239 < 68 ) || ( V_239 > V_240 ) ) {
return - V_241 ;
}
V_11 -> V_37 = V_239 ;
return 0 ;
}
static void
F_40 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
T_4 V_242 [ 2 ] ;
T_6 V_243 = 0 ;
V_242 [ 0 ] = V_242 [ 1 ] = 0 ;
V_242 [ 1 ] |= 0x02000000 ;
if ( V_11 -> V_121 & V_244 ) {
V_243 = V_245 ;
} else if ( ( V_11 -> V_121 & V_246 ) ||
( F_82 ( V_11 ) > V_247 ) ) {
V_243 = V_248 | V_249 | V_250 ;
} else if ( ! F_83 ( V_11 ) ) {
struct V_251 * V_252 ;
V_243 =
V_248 | V_253 | V_250 ;
F_84 (ha, dev) {
int V_254 , V_255 = 0 ;
int V_75 = F_30 ( V_256 , V_252 -> V_257 ) ;
for ( V_254 = 0 ; V_254 < 6 ; V_254 ++ )
if ( V_75 & ( 1 << ( 31 - V_254 ) ) )
V_255 |= ( 1 << V_254 ) ;
V_242 [ V_255 / 32 ] |= ( 1 << ( V_255 % 32 ) ) ;
}
} else {
V_243 = V_248 | V_250 ;
}
if ( V_2 -> V_40 ) {
V_243 |= V_258 ;
}
F_37 ( V_259 , V_242 [ 0 ] ) ;
F_37 ( V_260 , V_242 [ 1 ] ) ;
F_2 ( V_261 , V_243 ) ;
}
static void F_85 ( struct V_10 * V_11 , struct V_262 * V_263 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
F_86 ( V_263 -> V_264 , L_2 , sizeof( V_263 -> V_264 ) ) ;
F_86 ( V_263 -> V_20 , V_265 , sizeof( V_263 -> V_20 ) ) ;
F_86 ( V_263 -> V_266 , F_87 ( V_2 -> V_7 ) , sizeof( V_263 -> V_266 ) ) ;
}
static int F_88 ( struct V_10 * V_11 , struct V_267 * V_268 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
if ( V_2 -> V_59 ) {
V_268 -> V_269 = V_270 | V_271 ;
V_268 -> V_272 = V_273 | V_274 ;
V_268 -> V_275 = V_276 ;
V_268 -> V_277 = V_278 ;
} else {
V_268 -> V_269 = V_279 |
V_280 | V_281
| V_282 | V_283 |
V_270 | V_284 ;
V_268 -> V_272 = V_285 |
V_286 | V_287 |
V_288 | V_289 |
V_273 | V_290 ;
V_268 -> V_275 = V_291 ;
V_268 -> V_277 = V_278 ;
}
if ( V_2 -> V_62 ) {
F_89 ( V_268 , V_2 -> V_34 ) ;
V_268 -> V_292 = V_2 -> V_35 ? V_293 : V_294 ;
} else {
F_89 ( V_268 , V_295 ) ;
V_268 -> V_292 = V_296 ;
}
if ( V_2 -> V_30 )
V_268 -> V_297 = V_298 ;
else
V_268 -> V_297 = V_299 ;
V_268 -> V_300 = V_2 -> V_68 ;
return 0 ;
}
static int F_90 ( struct V_10 * V_11 , struct V_267 * V_268 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
F_79 ( V_11 ) ;
if ( V_268 -> V_297 == V_298 ) {
if ( V_2 -> V_30 )
return 0 ;
else {
V_2 -> V_30 = 1 ;
F_20 ( V_11 ) ;
return 0 ;
}
} else {
V_2 -> V_30 = 0 ;
if ( V_2 -> V_34 == 1000 ) {
F_89 ( V_268 , V_301 ) ;
V_268 -> V_292 = V_293 ;
F_4 ( L_35 ) ;
}
switch ( F_91 ( V_268 ) ) {
case V_302 :
V_2 -> V_34 = 10 ;
V_2 -> V_35 = ( V_268 -> V_292 == V_293 ) ;
break;
case V_301 :
V_2 -> V_34 = 100 ;
V_2 -> V_35 = ( V_268 -> V_292 == V_293 ) ;
break;
case V_303 :
default:
return - V_241 ;
}
F_20 ( V_11 ) ;
}
return 0 ;
}
static T_4 F_92 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
return V_2 -> V_62 ;
}
static int
F_93 ( struct V_10 * V_11 , struct V_304 * V_305 , int V_268 )
{
int V_68 ;
struct V_1 * V_2 = F_10 ( V_11 ) ;
struct V_306 * V_307 = F_94 ( V_305 ) ;
V_68 = V_2 -> V_68 ;
switch ( V_268 ) {
case V_308 :
V_307 -> V_309 = V_68 ;
break;
case V_310 :
V_307 -> V_311 = F_27 ( V_11 , V_68 , V_307 -> V_312 ) ;
break;
case V_313 :
if ( ! F_95 ( V_314 ) )
return - V_315 ;
F_96 ( V_11 , V_68 , V_307 -> V_312 , V_307 -> V_316 ) ;
break;
default:
return - V_317 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , int V_318 )
{
void T_1 * V_3 = V_2 -> V_25 ;
int V_66 = 1000 ;
F_2 ( V_319 , V_320 | ( V_318 & 0xff ) ) ;
while ( V_66 -- > 0 ) {
if ( ! ( F_18 ( V_319 ) & V_321 ) )
return F_18 ( V_322 ) ;
}
return 0 ;
}
static void
F_97 ( struct V_10 * V_11 , T_4 V_118 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
V_118 = ( ( V_118 ) ? V_323 : 0 ) | ( F_33 ( V_84 ) & 0xf8 ) | V_324 ;
F_32 ( V_84 , V_118 ) ;
F_98 () ;
F_32 ( V_84 , V_118 | V_325 ) ;
F_98 () ;
}
static int
F_99 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
T_3 V_118 ;
V_118 = ( F_33 ( V_84 ) & 0xf8 ) | V_326 ;
F_32 ( V_84 , V_118 ) ;
F_98 () ;
F_32 ( V_84 , V_118 | V_325 ) ;
F_98 () ;
return ( F_33 ( V_84 ) >> 1 ) & 1 ;
}
static void
F_100 ( struct V_10 * V_11 , T_4 V_118 , int V_149 )
{
int V_66 ;
for ( V_66 = V_149 - 1 ; V_66 >= 0 ; V_66 -- ) {
F_97 ( V_11 , V_118 & ( 1 << V_66 ) ) ;
}
}
static int
F_27 ( struct V_10 * V_11 , int V_68 , int V_312 )
{
T_4 V_268 ;
int V_66 ;
T_4 V_327 = 0 ;
F_100 ( V_11 , 0xffffffff , 32 ) ;
V_268 = ( 0x06 << 10 | V_68 << 5 | V_312 ) ;
F_100 ( V_11 , V_268 , 14 ) ;
if ( F_99 ( V_11 ) )
goto V_328;
for ( V_66 = 0 ; V_66 < 16 ; V_66 ++ ) {
V_327 |= F_99 ( V_11 ) ;
V_327 <<= 1 ;
}
F_99 ( V_11 ) ;
return ( V_327 >> 1 ) & 0xffff ;
V_328:
return 0 ;
}
static int
F_96 ( struct V_10 * V_11 , int V_68 , int V_312 , T_6 V_118 )
{
T_4 V_268 ;
F_100 ( V_11 , 0xffffffff , 32 ) ;
V_268 = ( 0x5002 << 16 ) | ( V_68 << 23 ) | ( V_312 << 18 ) | V_118 ;
F_100 ( V_11 , V_268 , 32 ) ;
F_99 ( V_11 ) ;
return 0 ;
}
static int
F_75 ( struct V_10 * V_11 , int V_329 )
{
T_9 V_330 ;
int V_68 ;
struct V_1 * V_2 ;
V_2 = F_10 ( V_11 ) ;
V_68 = V_2 -> V_68 ;
do {
V_330 = F_27 ( V_11 , V_68 , V_331 ) ;
if ( V_330 & V_332 )
return 0 ;
F_36 ( 1 ) ;
} while ( -- V_329 > 0 );
return - 1 ;
}
static int
F_77 ( struct V_10 * V_11 )
{
T_9 V_333 ;
T_9 V_330 ;
T_9 V_334 ;
T_9 V_335 ;
int V_68 ;
struct V_1 * V_2 ;
V_2 = F_10 ( V_11 ) ;
V_68 = V_2 -> V_68 ;
V_330 = F_27 ( V_11 , V_68 , V_331 ) ;
if ( V_2 -> V_30 ) {
if ( ! ( V_330 & V_336 ) ) {
return - 1 ;
}
V_333 = F_27 ( V_11 , V_68 , V_337 ) &
F_27 ( V_11 , V_68 , V_338 ) ;
V_334 = F_27 ( V_11 , V_68 , V_339 ) ;
V_335 = F_27 ( V_11 , V_68 , V_340 ) ;
if ( V_334 & V_341 && V_335 & V_342 ) {
V_2 -> V_34 = 1000 ;
V_2 -> V_35 = 1 ;
F_4 ( V_63 L_36 ) ;
} else if ( V_334 & V_343 && V_335 & V_344 ) {
V_2 -> V_34 = 1000 ;
V_2 -> V_35 = 0 ;
F_4 ( V_63 L_37 ) ;
} else if ( V_333 & V_345 ) {
V_2 -> V_34 = 100 ;
V_2 -> V_35 = 1 ;
F_4 ( V_63 L_38 ) ;
} else if ( V_333 & V_346 ) {
V_2 -> V_34 = 100 ;
V_2 -> V_35 = 0 ;
F_4 ( V_63 L_39 ) ;
} else if ( V_333 & V_347 ) {
V_2 -> V_34 = 10 ;
V_2 -> V_35 = 1 ;
F_4 ( V_63 L_40 ) ;
} else if ( V_333 & V_348 ) {
V_2 -> V_34 = 10 ;
V_2 -> V_35 = 0 ;
F_4 ( V_63 L_41 ) ;
}
if ( V_333 & V_349 ) {
V_2 -> V_44 &= 1 ;
V_2 -> V_45 &= 1 ;
} else if ( V_333 & V_350 ) {
V_2 -> V_44 = 0 ;
V_2 -> V_45 &= 1 ;
}
} else {
T_9 V_351 = F_27 ( V_11 , V_68 , V_352 ) ;
switch ( V_351 & ( V_353 | V_354 ) ) {
case V_354 :
F_4 ( V_63 L_42 ) ;
break;
case V_353 :
F_4 ( V_63 L_43 ) ;
break;
case 0 :
F_4 ( V_63 L_44 ) ;
}
if ( V_351 & V_355 ) {
F_4 ( V_356 L_45 ) ;
} else {
F_4 ( V_356 L_46 ) ;
}
}
if ( V_2 -> V_44 )
F_4 ( V_63 L_47 ) ;
else
F_4 ( V_63 L_48 ) ;
if ( V_2 -> V_45 )
F_4 ( V_63 L_49 ) ;
else
F_4 ( V_63 L_50 ) ;
return 0 ;
}
static int
F_20 ( struct V_10 * V_11 )
{
T_9 V_357 ;
T_9 V_351 ;
T_9 V_330 ;
T_9 V_358 ;
int V_68 ;
struct V_1 * V_2 ;
V_2 = F_10 ( V_11 ) ;
V_68 = V_2 -> V_68 ;
if ( V_2 -> V_30 ) {
V_330 = F_27 ( V_11 , V_68 , V_331 ) ;
V_358 = F_27 ( V_11 , V_68 , V_337 ) &
~ ( V_345 | V_347 |
V_346 | V_348 |
V_359 ) ;
if ( V_330 & V_360 )
V_358 |= V_345 ;
if ( V_330 & V_361 )
V_358 |= V_346 ;
if ( V_330 & V_362 )
V_358 |= V_359 ;
if ( V_330 & V_363 )
V_358 |= V_347 ;
if ( V_330 & V_364 )
V_358 |= V_348 ;
V_358 |= V_349 | V_350 ;
F_96 ( V_11 , V_68 , V_337 , V_358 ) ;
V_357 = F_27 ( V_11 , V_68 , V_365 ) ;
V_357 |= 3 << 5 ;
F_96 ( V_11 , V_68 , V_365 , V_357 ) ;
F_96 ( V_11 , V_68 , V_352 , V_366 ) ;
V_351 = V_367 | V_368 | V_366 ;
F_96 ( V_11 , V_68 , V_352 , V_351 ) ;
F_36 ( 1 ) ;
} else {
V_357 = F_27 ( V_11 , V_68 , V_365 ) ;
V_357 &= ~ ( 3 << 5 ) ;
F_96 ( V_11 , V_68 , V_365 , V_357 ) ;
V_351 = F_27 ( V_11 , V_68 , V_352 ) ;
V_351 |= V_366 ;
F_96 ( V_11 , V_68 , V_352 , V_351 ) ;
V_351 = 0x1940 ;
F_96 ( V_11 , V_68 , V_352 , V_351 ) ;
F_36 ( 100 ) ;
F_96 ( V_11 , V_68 , V_337 , 0 ) ;
V_351 = V_369 ;
if ( V_2 -> V_34 == 100 ) {
V_351 |= V_353 ;
F_4 ( V_63 L_51 ) ;
} else if ( V_2 -> V_34 == 10 ) {
F_4 ( V_63 L_52 ) ;
}
if ( V_2 -> V_35 ) {
V_351 |= V_355 ;
F_4 ( V_356 L_45 ) ;
} else {
F_4 ( V_356 L_46 ) ;
}
#if 0
mscr = mii_read (dev, phy_addr, MII_CTRL1000);
mscr |= MII_MSCR_CFG_ENABLE;
mscr &= ~MII_MSCR_CFG_VALUE = 0;
#endif
F_96 ( V_11 , V_68 , V_352 , V_351 ) ;
F_36 ( 10 ) ;
}
return 0 ;
}
static int
F_76 ( struct V_10 * V_11 )
{
T_9 V_333 ;
T_9 V_330 ;
int V_68 ;
struct V_1 * V_2 ;
V_2 = F_10 ( V_11 ) ;
V_68 = V_2 -> V_68 ;
V_330 = F_27 ( V_11 , V_68 , V_370 ) ;
if ( V_2 -> V_30 ) {
if ( ! ( V_330 & V_336 ) ) {
return - 1 ;
}
V_333 = F_27 ( V_11 , V_68 , V_371 ) &
F_27 ( V_11 , V_68 , V_372 ) ;
V_2 -> V_34 = 1000 ;
if ( V_333 & V_373 ) {
F_4 ( V_63 L_36 ) ;
V_2 -> V_35 = 1 ;
} else {
F_4 ( V_63 L_53 ) ;
V_2 -> V_35 = 0 ;
}
if ( V_333 & V_374 ) {
V_2 -> V_44 &= 1 ;
V_2 -> V_45 &= 1 ;
} else if ( V_333 & V_375 ) {
V_2 -> V_44 = 0 ;
V_2 -> V_45 &= 1 ;
}
} else {
T_9 V_351 = F_27 ( V_11 , V_68 , V_376 ) ;
F_4 ( V_63 L_42 ) ;
if ( V_351 & V_355 ) {
F_4 ( V_356 L_45 ) ;
} else {
F_4 ( V_356 L_46 ) ;
}
}
if ( V_2 -> V_44 )
F_4 ( V_63 L_47 ) ;
else
F_4 ( V_63 L_48 ) ;
if ( V_2 -> V_45 )
F_4 ( V_63 L_49 ) ;
else
F_4 ( V_63 L_50 ) ;
return 0 ;
}
static int
F_19 ( struct V_10 * V_11 )
{
T_9 V_351 ;
T_9 V_377 ;
T_9 V_358 ;
int V_68 ;
struct V_1 * V_2 ;
V_2 = F_10 ( V_11 ) ;
V_68 = V_2 -> V_68 ;
if ( V_2 -> V_30 ) {
V_377 = F_27 ( V_11 , V_68 , V_378 ) ;
V_358 = F_27 ( V_11 , V_68 , V_337 ) &
~ V_379 &
~ V_373 ;
if ( V_377 & ( V_380 | V_381 ) )
V_358 |= V_379 ;
if ( V_377 & ( V_382 | V_383 ) )
V_358 |= V_373 ;
V_358 |= V_374 | V_375 ;
F_96 ( V_11 , V_68 , V_337 , V_358 ) ;
F_96 ( V_11 , V_68 , V_352 , V_366 ) ;
V_351 = V_367 | V_368 | V_366 ;
F_96 ( V_11 , V_68 , V_352 , V_351 ) ;
F_36 ( 1 ) ;
} else {
V_351 = V_366 ;
F_96 ( V_11 , V_68 , V_352 , V_351 ) ;
F_36 ( 10 ) ;
if ( V_2 -> V_35 ) {
V_351 = V_355 ;
F_4 ( V_63 L_54 ) ;
} else {
V_351 = 0 ;
F_4 ( V_63 L_55 ) ;
}
F_96 ( V_11 , V_68 , V_352 , V_351 ) ;
F_36 ( 10 ) ;
F_96 ( V_11 , V_68 , V_337 , 0 ) ;
}
return 0 ;
}
static int
F_101 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_125 * V_126 ;
int V_66 ;
F_55 ( V_11 ) ;
F_2 ( V_4 , 0 ) ;
F_37 ( V_105 , V_384 | V_385 | V_386 ) ;
F_102 ( V_7 -> V_16 , V_11 ) ;
F_103 ( & V_2 -> V_107 ) ;
for ( V_66 = 0 ; V_66 < V_124 ; V_66 ++ ) {
V_126 = V_2 -> V_127 [ V_66 ] ;
if ( V_126 ) {
F_64 ( V_7 , F_60 ( & V_2 -> V_56 [ V_66 ] ) ,
V_126 -> V_149 , V_130 ) ;
F_53 ( V_126 ) ;
V_2 -> V_127 [ V_66 ] = NULL ;
}
V_2 -> V_56 [ V_66 ] . V_132 = 0 ;
V_2 -> V_56 [ V_66 ] . V_129 = 0 ;
}
for ( V_66 = 0 ; V_66 < V_46 ; V_66 ++ ) {
V_126 = V_2 -> V_138 [ V_66 ] ;
if ( V_126 ) {
F_64 ( V_7 , F_60 ( & V_2 -> V_52 [ V_66 ] ) ,
V_126 -> V_149 , V_150 ) ;
F_53 ( V_126 ) ;
V_2 -> V_138 [ V_66 ] = NULL ;
}
}
return 0 ;
}
static void
F_104 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_105 ( V_7 ) ;
if ( V_11 ) {
struct V_1 * V_2 = F_10 ( V_11 ) ;
F_106 ( V_11 ) ;
F_22 ( V_7 , V_54 , V_2 -> V_56 ,
V_2 -> V_57 ) ;
F_22 ( V_7 , V_51 , V_2 -> V_52 ,
V_2 -> V_53 ) ;
#ifdef F_12
F_23 ( V_7 , V_2 -> V_3 ) ;
#endif
F_23 ( V_7 , V_2 -> V_25 ) ;
F_24 ( V_11 ) ;
F_25 ( V_7 ) ;
F_26 ( V_7 ) ;
}
}
