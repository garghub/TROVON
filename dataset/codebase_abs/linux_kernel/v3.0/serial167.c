void F_1 ( long V_1 )
{
T_1 V_2 ;
volatile T_1 * V_3 = & V_2 ;
int V_4 ;
while ( V_1 -- )
for ( V_4 = 100 ; V_4 ; V_4 -- )
V_2 |= * V_3 ;
}
static inline int F_2 ( struct V_5 * V_6 , char * V_7 ,
const char * V_8 )
{
#ifdef F_3
if ( ! V_6 ) {
F_4 ( L_1 , V_7 ,
V_8 ) ;
return 1 ;
}
if ( V_6 < & V_9 [ 0 ] || V_6 >= & V_9 [ V_10 ] ) {
F_4 ( L_2 ,
V_7 , V_8 ) ;
return 1 ;
}
if ( V_6 -> V_11 != V_12 ) {
F_4 ( L_3
L_4 , V_7 , V_8 ) ;
return 1 ;
}
#endif
return 0 ;
}
T_2 F_5 ( volatile T_1 * V_13 , T_1 V_14 )
{
unsigned long V_15 ;
volatile int V_4 ;
F_6 ( V_15 ) ;
for ( V_4 = 0 ; V_4 < 100 ; V_4 ++ ) {
if ( V_13 [ V_16 ] == 0 ) {
break;
}
F_1 ( 10L ) ;
}
if ( V_4 == 10 ) {
F_7 ( V_15 ) ;
return ( - 1 ) ;
}
V_13 [ V_16 ] = V_14 ;
F_7 ( V_15 ) ;
return ( 0 ) ;
}
static void F_8 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
volatile unsigned char * V_13 = ( unsigned char * ) V_20 ;
int V_21 ;
unsigned long V_15 ;
#ifdef F_9
F_4 ( L_5 , V_18 -> V_7 ) ;
#endif
if ( F_2 ( V_6 , V_18 -> V_7 , L_6 ) )
return;
V_21 = V_6 -> line ;
F_6 ( V_15 ) ;
V_13 [ V_22 ] = ( T_1 ) ( V_21 ) ;
V_13 [ V_23 ] &= ~ ( V_24 | V_25 ) ;
F_7 ( V_15 ) ;
}
static void F_10 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
volatile unsigned char * V_13 = ( unsigned char * ) V_20 ;
int V_21 ;
unsigned long V_15 ;
#ifdef F_9
F_4 ( L_7 , V_18 -> V_7 ) ;
#endif
if ( F_2 ( V_6 , V_18 -> V_7 , L_8 ) )
return;
V_21 = V_6 -> line ;
F_6 ( V_15 ) ;
V_13 [ V_22 ] = ( T_1 ) ( V_21 ) ;
V_13 [ V_23 ] |= V_24 ;
F_7 ( V_15 ) ;
}
static T_3 F_11 ( int V_26 , void * V_27 )
{
struct V_17 * V_18 ;
struct V_5 * V_6 ;
volatile unsigned char * V_13 = ( unsigned char * ) V_20 ;
unsigned char V_28 , V_29 ;
int V_21 ;
char V_30 ;
V_21 = ( T_2 ) ( V_13 [ V_31 ] >> 2 ) ;
V_6 = & V_9 [ V_21 ] ;
V_6 -> V_32 = V_33 ;
if ( ( V_28 = V_13 [ V_34 ] ) & V_35 ) {
V_13 [ V_36 ] = V_37 ;
return V_38 ;
}
if ( ( V_29 = V_13 [ V_39 ] ) != 0 )
V_30 = V_13 [ V_40 ] ;
else
V_30 = 0 ;
if ( V_6 -> V_18 == 0 ) {
V_13 [ V_36 ] = V_29 ? 0 : V_37 ;
return V_38 ;
} else {
V_18 = V_6 -> V_18 ;
if ( V_28 & V_6 -> V_41 ) {
V_13 [ V_36 ] = V_29 ? 0 : V_37 ;
return V_38 ;
}
if ( F_12 ( V_18 , 1 ) != 0 ) {
if ( V_28 & V_6 -> V_42 ) {
if ( V_28 & V_43 ) {
F_13 ( V_18 , V_30 ,
V_44 ) ;
if ( V_6 -> V_15 & V_45 ) {
F_14 ( V_18 ) ;
}
} else if ( V_28 & V_46 ) {
F_13 ( V_18 , V_30 ,
V_47 ) ;
} else if ( V_28 & V_48 ) {
F_13 ( V_18 , V_30 ,
V_49 ) ;
} else if ( V_28 & V_50 ) {
F_13 ( V_18 , 0 ,
V_51 ) ;
if ( F_12 ( V_18 , 1 ) !=
0 ) {
F_13 ( V_18 , V_30 ,
V_47 ) ;
}
} else {
F_13 ( V_18 , 0 ,
V_52 ) ;
}
} else {
F_13 ( V_18 , V_30 , V_52 ) ;
}
} else {
}
}
F_15 ( V_18 ) ;
V_13 [ V_36 ] = V_29 ? 0 : V_37 ;
return V_38 ;
}
static T_3 F_16 ( int V_26 , void * V_27 )
{
struct V_5 * V_6 ;
volatile unsigned char * V_13 = ( unsigned char * ) V_20 ;
int V_21 ;
int V_53 ;
int V_54 ;
V_21 = ( T_2 ) ( V_13 [ V_31 ] >> 2 ) ;
V_6 = & V_9 [ V_21 ] ;
V_6 -> V_32 = V_33 ;
V_53 = V_13 [ V_55 ] ;
V_54 = V_13 [ V_56 ] ;
if ( V_6 -> V_18 == 0 ) {
;
} else {
if ( ( V_53 & V_57 )
&& ( V_6 -> V_15 & V_58 ) ) {
if ( V_54 & V_57 ) {
F_17 ( & V_6 -> V_59 ) ;
} else {
F_18 ( V_6 -> V_18 ) ;
F_17 ( & V_6 -> V_59 ) ;
V_6 -> V_15 &= ~ V_60 ;
}
}
if ( ( V_53 & V_61 )
&& ( V_6 -> V_15 & V_62 ) ) {
if ( V_6 -> V_18 -> V_63 ) {
if ( V_54 & V_61 ) {
V_6 -> V_18 -> V_63 = 0 ;
V_13 [ V_23 ] |= V_24 ;
F_19 ( V_6 -> V_18 ) ;
}
} else {
if ( ! ( V_54 & V_61 ) ) {
V_6 -> V_18 -> V_63 = 1 ;
V_13 [ V_23 ] &=
~ ( V_24 | V_25 ) ;
}
}
}
if ( V_54 & V_64 ) {
}
}
V_13 [ V_65 ] = 0 ;
return V_38 ;
}
static T_3 F_20 ( int V_26 , void * V_27 )
{
struct V_5 * V_6 ;
volatile unsigned char * V_13 = ( unsigned char * ) V_20 ;
int V_21 ;
int V_66 , V_67 ;
int V_68 ;
V_21 = ( T_2 ) ( V_13 [ V_31 ] >> 2 ) ;
if ( ( V_21 < 0 ) || ( V_10 <= V_21 ) ) {
V_13 [ V_23 ] &= ~ ( V_24 | V_25 ) ;
V_13 [ V_69 ] = V_37 ;
return V_38 ;
}
V_6 = & V_9 [ V_21 ] ;
V_6 -> V_32 = V_33 ;
if ( V_6 -> V_18 == 0 ) {
V_13 [ V_23 ] &= ~ ( V_24 | V_25 ) ;
V_13 [ V_69 ] = V_37 ;
return V_38 ;
}
V_67 = V_66 = V_13 [ V_70 ] ;
if ( V_6 -> V_71 ) {
V_68 = V_6 -> V_71 ;
V_13 [ V_72 ] = V_68 ;
V_66 -- ;
V_6 -> V_71 = 0 ;
}
if ( V_6 -> V_73 ) {
V_13 [ V_72 ] = 0 ;
V_13 [ V_72 ] = 0x81 ;
V_13 [ V_72 ] = 0 ;
V_13 [ V_72 ] = 0x82 ;
V_13 [ V_72 ] = V_6 -> V_73 * 200 / V_74 ;
V_13 [ V_72 ] = 0 ;
V_13 [ V_72 ] = 0x83 ;
V_66 -= 7 ;
V_6 -> V_73 = 0 ;
}
while ( V_66 > 0 ) {
if ( ! V_6 -> V_75 ) {
V_13 [ V_23 ] &= ~ ( V_24 | V_25 ) ;
break;
}
if ( V_6 -> V_76 == 0 ) {
V_13 [ V_23 ] &= ~ ( V_24 | V_25 ) ;
break;
}
if ( V_6 -> V_18 -> V_63 || V_6 -> V_18 -> V_77 ) {
V_13 [ V_23 ] &= ~ ( V_24 | V_25 ) ;
break;
}
V_68 = V_6 -> V_76 [ V_6 -> V_78 ] ;
if ( V_68 ) {
V_6 -> V_75 -- ;
V_6 -> V_78 = ( V_6 -> V_78 + 1 )
& ( V_79 - 1 ) ;
V_13 [ V_72 ] = V_68 ;
V_66 -- ;
} else {
if ( V_66 > 1 ) {
V_6 -> V_75 -- ;
V_6 -> V_78 = ( V_6 -> V_78 + 1 )
& ( V_79 - 1 ) ;
V_13 [ V_72 ] = V_68 ;
V_13 [ V_72 ] = 0 ;
V_66 -- ;
V_66 -- ;
} else {
break;
}
}
}
if ( V_6 -> V_75 < V_80 )
F_19 ( V_6 -> V_18 ) ;
V_13 [ V_69 ] = ( V_66 != V_67 ) ? 0 : V_37 ;
return V_38 ;
}
static T_3 F_21 ( int V_26 , void * V_27 )
{
struct V_17 * V_18 ;
struct V_5 * V_6 ;
volatile unsigned char * V_13 = ( unsigned char * ) V_20 ;
int V_21 ;
char V_30 ;
int V_66 ;
int V_81 ;
V_21 = ( T_2 ) ( V_13 [ V_31 ] >> 2 ) ;
V_6 = & V_9 [ V_21 ] ;
V_6 -> V_32 = V_33 ;
V_81 = V_66 = V_13 [ V_39 ] ;
if ( V_6 -> V_18 == 0 ) {
while ( V_66 -- ) {
V_30 = V_13 [ V_40 ] ;
}
} else {
V_18 = V_6 -> V_18 ;
#ifdef F_22
++ V_6 -> V_82 . V_83 ;
V_6 -> V_82 . V_66 += V_66 ;
if ( V_66 > V_6 -> V_82 . V_84 )
V_6 -> V_82 . V_84 = V_66 ;
V_6 -> V_82 . V_85 = V_66 ;
#endif
while ( V_66 -- ) {
V_30 = V_13 [ V_40 ] ;
F_13 ( V_18 , V_30 , V_52 ) ;
#ifdef F_23
F_24 ( 10L ) ;
#endif
}
F_15 ( V_18 ) ;
}
V_13 [ V_36 ] = V_81 ? 0 : V_37 ;
return V_38 ;
}
static int F_25 ( struct V_5 * V_6 )
{
unsigned long V_15 ;
volatile unsigned char * V_13 = ( unsigned char * ) V_20 ;
int V_21 ;
if ( V_6 -> V_15 & V_86 ) {
return 0 ;
}
if ( ! V_6 -> type ) {
if ( V_6 -> V_18 ) {
F_26 ( V_87 , & V_6 -> V_18 -> V_15 ) ;
}
return 0 ;
}
if ( ! V_6 -> V_76 ) {
V_6 -> V_76 = ( unsigned char * ) F_27 ( V_88 ) ;
if ( ! V_6 -> V_76 ) {
return - V_89 ;
}
}
F_28 ( V_6 ) ;
V_21 = V_6 -> line ;
#ifdef F_29
F_4 ( L_9 , V_21 ) ;
#endif
F_6 ( V_15 ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
F_5 ( V_13 , V_90 | V_91 ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
V_13 [ V_56 ] = V_92 ;
V_13 [ V_93 ] = V_94 ;
#ifdef F_30
F_4 ( L_10 , __LINE__ ) ;
F_4 ( L_11 , V_13 [ V_56 ] ,
V_13 [ V_93 ] ) ;
#endif
V_13 [ V_23 ] |= V_95 ;
V_6 -> V_15 |= V_86 ;
if ( V_6 -> V_18 ) {
F_31 ( V_87 , & V_6 -> V_18 -> V_15 ) ;
}
V_6 -> V_75 = V_6 -> V_96 = V_6 -> V_78 = 0 ;
F_7 ( V_15 ) ;
#ifdef F_29
F_4 ( L_12 ) ;
#endif
return 0 ;
}
void F_32 ( struct V_5 * V_6 )
{
unsigned long V_15 ;
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
int V_21 ;
V_21 = V_6 -> line ;
F_6 ( V_15 ) ;
V_13 [ V_22 ] = V_21 ;
V_13 [ V_23 ] |= V_24 ;
F_7 ( V_15 ) ;
}
static void F_33 ( struct V_5 * V_6 )
{
unsigned long V_15 ;
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
int V_21 ;
if ( ! ( V_6 -> V_15 & V_86 ) ) {
return;
}
V_21 = V_6 -> line ;
#ifdef F_29
F_4 ( L_13 , V_21 ) ;
#endif
F_6 ( V_15 ) ;
if ( V_6 -> V_76 ) {
F_34 ( ( unsigned long ) V_6 -> V_76 ) ;
V_6 -> V_76 = NULL ;
}
V_13 [ V_22 ] = ( T_1 ) V_21 ;
if ( ! V_6 -> V_18 || ( V_6 -> V_18 -> V_97 -> V_98 & V_99 ) ) {
V_13 [ V_56 ] = 0 ;
V_13 [ V_93 ] = 0 ;
#ifdef F_30
F_4 ( L_14 , __LINE__ ) ;
F_4 ( L_11 , V_13 [ V_56 ] ,
V_13 [ V_93 ] ) ;
#endif
}
F_5 ( V_13 , V_100 ) ;
if ( V_6 -> V_18 ) {
F_26 ( V_87 , & V_6 -> V_18 -> V_15 ) ;
}
V_6 -> V_15 &= ~ V_86 ;
F_7 ( V_15 ) ;
#ifdef F_29
F_4 ( L_12 ) ;
#endif
}
static void F_28 ( struct V_5 * V_6 )
{
unsigned long V_15 ;
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
int V_21 ;
unsigned V_101 ;
int V_4 ;
unsigned char V_102 , V_103 = 0 ;
if ( ! V_6 -> V_18 || ! V_6 -> V_18 -> V_97 ) {
return;
}
if ( V_6 -> line == - 1 ) {
return;
}
V_101 = V_6 -> V_18 -> V_97 -> V_98 ;
V_4 = V_101 & V_104 ;
#ifdef F_35
if ( V_4 & F_35 ) {
if ( V_4 == V_105 )
V_4 = 16 ;
else if ( V_4 == V_106 )
V_4 = 18 ;
#ifdef F_36
else if ( V_4 == F_36 )
V_4 = 17 ;
#endif
else
V_6 -> V_18 -> V_97 -> V_98 &= ~ F_35 ;
}
#endif
if ( V_4 == 15 ) {
if ( ( V_6 -> V_15 & V_107 ) == V_108 )
V_4 += 1 ;
if ( ( V_6 -> V_15 & V_107 ) == V_109 )
V_4 += 3 ;
}
if ( V_6 != V_110 ) {
V_6 -> V_111 = V_112 [ V_4 ] ;
V_6 -> V_113 = V_114 [ V_4 ] ;
V_6 -> V_115 = V_112 [ V_4 ] ;
V_6 -> V_116 = V_114 [ V_4 ] >> 5 ;
if ( V_117 [ V_4 ] == 134 ) {
V_6 -> V_118 =
( V_6 -> V_119 * V_74 * 30 / 269 ) + 2 ;
} else if ( V_117 [ V_4 ] ) {
V_6 -> V_118 =
( V_6 -> V_119 * V_74 * 15 / V_117 [ V_4 ] ) +
2 ;
} else {
V_6 -> V_118 = 0 ;
}
}
V_6 -> V_120 = 0 ;
V_6 -> V_121 = 0 ;
V_6 -> V_122 = 0 ;
V_6 -> V_123 = ( V_6 -> V_124 ? V_6 -> V_124 : V_125 [ V_4 ] ) ;
V_21 = V_6 -> line ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
if ( F_37 ( V_6 -> V_18 ) ) {
if ( V_13 [ V_23 ] & V_126 )
V_13 [ V_23 ] &= ~ V_126 ;
if ( V_13 [ V_127 ] & ( V_64 | V_61 | V_57 ) )
V_13 [ V_127 ] &= ~ ( V_64 | V_61 | V_57 ) ;
if ( V_13 [ V_128 ] & ( V_64 | V_61 | V_57 ) )
V_13 [ V_128 ] &= ~ ( V_64 | V_61 | V_57 ) ;
} else {
if ( ( V_13 [ V_23 ] & V_126 ) != V_126 )
V_13 [ V_23 ] |= V_126 ;
if ( ( V_13 [ V_127 ] & ( V_64 | V_61 | V_57 ) ) !=
( V_64 | V_61 | V_57 ) )
V_13 [ V_127 ] |= V_64 | V_61 | V_57 ;
if ( ( V_13 [ V_128 ] & ( V_64 | V_61 | V_57 ) ) !=
( V_64 | V_61 | V_57 ) )
V_13 [ V_128 ] |= V_64 | V_61 | V_57 ;
}
V_6 -> V_129 = ( V_101 & V_130 ) ? V_131 : V_132 ;
V_6 -> V_133 = V_134 ;
switch ( V_101 & V_135 ) {
case V_136 :
V_6 -> V_137 = V_138 ;
break;
case V_139 :
V_6 -> V_137 = V_140 ;
break;
case V_141 :
V_6 -> V_137 = V_142 ;
break;
case V_143 :
V_6 -> V_137 = V_144 ;
break;
}
if ( V_101 & V_145 ) {
if ( V_101 & V_146 ) {
V_6 -> V_137 |= V_147 ;
} else {
V_6 -> V_137 |= V_148 ;
}
} else {
V_6 -> V_137 |= V_149 ;
}
#if 0
if (cflag & CRTSCTS) {
info->flags |= ASYNC_CTS_FLOW;
info->cor2 |= CyCtsAE;
} else {
info->flags &= ~ASYNC_CTS_FLOW;
info->cor2 &= ~CyCtsAE;
}
#endif
if ( V_101 & V_150 )
V_6 -> V_15 &= ~ V_58 ;
else
V_6 -> V_15 |= V_58 ;
V_21 = V_6 -> line ;
F_6 ( V_15 ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
if ( V_13 [ V_31 ] != V_21 << 2 )
V_13 [ V_31 ] = V_21 << 2 ;
if ( V_13 [ V_151 ] != 0x5c )
V_13 [ V_151 ] = 0x5c ;
if ( V_13 [ V_152 ] != V_6 -> V_137 )
V_103 = 1 ;
if ( V_13 [ V_153 ] != V_6 -> V_113 )
V_13 [ V_153 ] = V_6 -> V_113 ;
if ( V_13 [ V_154 ] != V_6 -> V_111 )
V_13 [ V_154 ] = V_6 -> V_111 ;
if ( V_13 [ V_155 ] != V_6 -> V_116 )
V_13 [ V_155 ] = V_6 -> V_116 ;
if ( V_13 [ V_156 ] != V_6 -> V_115 )
V_13 [ V_156 ] = V_6 -> V_115 ;
if ( V_13 [ V_157 ] != F_38 ( V_6 -> V_18 ) )
V_13 [ V_157 ] = F_38 ( V_6 -> V_18 ) ;
if ( V_13 [ V_158 ] != F_39 ( V_6 -> V_18 ) )
V_13 [ V_158 ] = F_39 ( V_6 -> V_18 ) ;
if ( V_13 [ V_159 ] != F_38 ( V_6 -> V_18 ) )
V_13 [ V_159 ] = F_38 ( V_6 -> V_18 ) ;
if ( V_13 [ V_160 ] != F_38 ( V_6 -> V_18 ) )
V_13 [ V_160 ] = F_38 ( V_6 -> V_18 ) ;
if ( V_13 [ V_152 ] != V_6 -> V_137 )
V_13 [ V_152 ] = V_6 -> V_137 ;
if ( V_13 [ V_161 ] != V_6 -> V_133 )
V_13 [ V_161 ] = V_6 -> V_133 ;
if ( V_13 [ V_162 ] != V_6 -> V_129 )
V_13 [ V_162 ] = V_6 -> V_129 ;
if ( V_13 [ V_127 ] != V_6 -> V_123 )
V_13 [ V_127 ] = V_6 -> V_123 ;
if ( V_13 [ V_128 ] != V_6 -> V_122 )
V_13 [ V_128 ] = V_6 -> V_122 ;
if ( V_13 [ V_163 ] != V_6 -> V_121 )
V_13 [ V_163 ] = V_6 -> V_121 ;
if ( V_13 [ V_164 ] != V_6 -> V_120 )
V_13 [ V_164 ] = V_6 -> V_120 ;
if ( V_103 )
F_5 ( V_13 , V_165 ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
V_102 = V_6 -> V_166 ? V_6 -> V_166 : 0x02 ;
if ( V_13 [ V_167 ] != V_102 )
V_13 [ V_167 ] = V_102 ;
if ( V_13 [ V_168 ] != 0 )
V_13 [ V_168 ] = 0 ;
if ( V_4 == 0 ) {
if ( ( V_13 [ V_93 ] & V_94 ) == V_94 )
V_13 [ V_93 ] = 0 ;
#ifdef F_30
F_4 ( L_14 , __LINE__ ) ;
F_4 ( L_11 , V_13 [ V_56 ] ,
V_13 [ V_93 ] ) ;
#endif
} else {
if ( ( V_13 [ V_93 ] & V_94 ) != V_94 )
V_13 [ V_93 ] = V_94 ;
#ifdef F_30
F_4 ( L_10 , __LINE__ ) ;
F_4 ( L_11 , V_13 [ V_56 ] ,
V_13 [ V_93 ] ) ;
#endif
}
if ( V_6 -> V_18 ) {
F_31 ( V_87 , & V_6 -> V_18 -> V_15 ) ;
}
F_7 ( V_15 ) ;
}
static int F_40 ( struct V_17 * V_18 , unsigned char V_169 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
unsigned long V_15 ;
#ifdef F_41
F_4 ( L_15 , V_18 -> V_7 , V_169 ) ;
#endif
if ( F_2 ( V_6 , V_18 -> V_7 , L_16 ) )
return 0 ;
if ( ! V_6 -> V_76 )
return 0 ;
F_6 ( V_15 ) ;
if ( V_6 -> V_75 >= V_79 - 1 ) {
F_7 ( V_15 ) ;
return 0 ;
}
V_6 -> V_76 [ V_6 -> V_96 ++ ] = V_169 ;
V_6 -> V_96 &= V_79 - 1 ;
V_6 -> V_75 ++ ;
F_7 ( V_15 ) ;
return 1 ;
}
static void F_42 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
unsigned long V_15 ;
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
int V_21 ;
#ifdef F_41
F_4 ( L_17 , V_18 -> V_7 ) ;
#endif
if ( F_2 ( V_6 , V_18 -> V_7 , L_18 ) )
return;
if ( V_6 -> V_75 <= 0 || V_18 -> V_63
|| V_18 -> V_77 || ! V_6 -> V_76 )
return;
V_21 = V_6 -> line ;
F_6 ( V_15 ) ;
V_13 [ V_22 ] = V_21 ;
V_13 [ V_23 ] |= V_24 ;
F_7 ( V_15 ) ;
}
static int F_43 ( struct V_17 * V_18 , const unsigned char * V_170 , int V_171 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
unsigned long V_15 ;
int V_172 , V_173 = 0 ;
#ifdef F_41
F_4 ( L_19 , V_18 -> V_7 ) ;
#endif
if ( F_2 ( V_6 , V_18 -> V_7 , L_20 ) ) {
return 0 ;
}
if ( ! V_6 -> V_76 ) {
return 0 ;
}
while ( 1 ) {
F_6 ( V_15 ) ;
V_172 = F_44 ( int , V_171 , F_45 ( V_174 - V_6 -> V_75 - 1 ,
V_174 - V_6 -> V_96 ) ) ;
if ( V_172 <= 0 ) {
F_7 ( V_15 ) ;
break;
}
memcpy ( V_6 -> V_76 + V_6 -> V_96 , V_170 , V_172 ) ;
V_6 -> V_96 =
( V_6 -> V_96 + V_172 ) & ( V_174 - 1 ) ;
V_6 -> V_75 += V_172 ;
F_7 ( V_15 ) ;
V_170 += V_172 ;
V_171 -= V_172 ;
V_173 += V_172 ;
}
if ( V_6 -> V_75 && ! V_18 -> V_63 && ! V_18 -> V_77 ) {
F_32 ( V_6 ) ;
}
return V_173 ;
}
static int F_46 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
int V_175 ;
#ifdef F_41
F_4 ( L_21 , V_18 -> V_7 ) ;
#endif
if ( F_2 ( V_6 , V_18 -> V_7 , L_22 ) )
return 0 ;
V_175 = V_79 - V_6 -> V_75 - 1 ;
if ( V_175 < 0 )
V_175 = 0 ;
return V_175 ;
}
static int F_47 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
#ifdef F_41
F_4 ( L_23 , V_18 -> V_7 , V_6 -> V_75 ) ;
#endif
if ( F_2 ( V_6 , V_18 -> V_7 , L_24 ) )
return 0 ;
return V_6 -> V_75 ;
}
static void F_48 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
unsigned long V_15 ;
#ifdef F_41
F_4 ( L_25 , V_18 -> V_7 ) ;
#endif
if ( F_2 ( V_6 , V_18 -> V_7 , L_26 ) )
return;
F_6 ( V_15 ) ;
V_6 -> V_75 = V_6 -> V_96 = V_6 -> V_78 = 0 ;
F_7 ( V_15 ) ;
F_19 ( V_18 ) ;
}
static void F_49 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
unsigned long V_15 ;
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
int V_21 ;
#ifdef F_50
char V_170 [ 64 ] ;
F_4 ( L_27 , F_51 ( V_18 , V_170 ) ,
V_18 -> V_176 . V_177 ( V_18 ) ) ;
F_4 ( L_28 , V_18 -> V_7 ) ;
#endif
if ( F_2 ( V_6 , V_18 -> V_7 , L_29 ) ) {
return;
}
if ( F_52 ( V_18 ) ) {
V_6 -> V_71 = F_39 ( V_18 ) ;
}
V_21 = V_6 -> line ;
F_6 ( V_15 ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
V_13 [ V_56 ] = 0 ;
F_7 ( V_15 ) ;
}
static void F_53 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
unsigned long V_15 ;
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
int V_21 ;
#ifdef F_50
char V_170 [ 64 ] ;
F_4 ( L_27 , F_51 ( V_18 , V_170 ) ,
V_18 -> V_176 . V_177 ( V_18 ) ) ;
F_4 ( L_30 , V_18 -> V_7 ) ;
#endif
if ( F_2 ( V_6 , V_18 -> V_7 , L_29 ) ) {
return;
}
if ( F_52 ( V_18 ) ) {
V_6 -> V_71 = F_38 ( V_18 ) ;
}
V_21 = V_6 -> line ;
F_6 ( V_15 ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
V_13 [ V_56 ] = V_92 ;
F_7 ( V_15 ) ;
}
static int
F_54 ( struct V_5 * V_6 ,
struct V_178 T_4 * V_179 )
{
struct V_178 V_180 ;
if ( ! V_179 )
return - V_181 ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_180 . type = V_6 -> type ;
V_180 . line = V_6 -> line ;
V_180 . V_182 = V_6 -> line ;
V_180 . V_26 = 0 ;
V_180 . V_15 = V_6 -> V_15 ;
V_180 . V_183 = 0 ;
V_180 . V_184 = V_6 -> V_184 ;
V_180 . V_185 = 0 ;
V_180 . V_186 = 0 ;
return F_55 ( V_179 , & V_180 , sizeof( * V_179 ) ) ? - V_181 : 0 ;
}
static int
F_56 ( struct V_5 * V_6 ,
struct V_178 T_4 * V_187 )
{
struct V_178 V_188 ;
struct V_5 V_189 ;
if ( ! V_187 )
return - V_181 ;
if ( F_57 ( & V_188 , V_187 , sizeof( V_188 ) ) )
return - V_181 ;
V_189 = * V_6 ;
if ( ! F_58 ( V_190 ) ) {
if ( ( V_188 . V_184 != V_6 -> V_184 ) ||
( ( V_188 . V_15 & V_191 & ~ V_192 ) !=
( V_6 -> V_15 & V_191 & ~ V_192 ) ) )
return - V_193 ;
V_6 -> V_15 = ( ( V_6 -> V_15 & ~ V_192 ) |
( V_188 . V_15 & V_192 ) ) ;
goto V_194;
}
V_6 -> V_15 = ( ( V_6 -> V_15 & ~ V_191 ) |
( V_188 . V_15 & V_191 ) ) ;
V_6 -> V_184 = V_188 . V_184 ;
V_194:
if ( V_6 -> V_15 & V_86 ) {
F_28 ( V_6 ) ;
return 0 ;
}
return F_25 ( V_6 ) ;
}
static int F_59 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
int V_21 ;
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
unsigned long V_15 ;
unsigned char V_195 ;
V_21 = V_6 -> line ;
F_6 ( V_15 ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
V_195 = V_13 [ V_56 ] | V_13 [ V_93 ] ;
F_7 ( V_15 ) ;
return ( ( V_195 & V_92 ) ? V_196 : 0 )
| ( ( V_195 & V_94 ) ? V_197 : 0 )
| ( ( V_195 & V_57 ) ? V_198 : 0 )
| ( ( V_195 & V_64 ) ? V_199 : 0 )
| ( ( V_195 & V_61 ) ? V_200 : 0 ) ;
}
static int
F_60 ( struct V_17 * V_18 , unsigned int V_201 , unsigned int V_202 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
int V_21 ;
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
unsigned long V_15 ;
V_21 = V_6 -> line ;
if ( V_201 & V_196 ) {
F_6 ( V_15 ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
V_13 [ V_56 ] = V_92 ;
F_7 ( V_15 ) ;
}
if ( V_201 & V_197 ) {
F_6 ( V_15 ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
V_13 [ V_93 ] = V_94 ;
#ifdef F_30
F_4 ( L_10 , __LINE__ ) ;
F_4 ( L_11 , V_13 [ V_56 ] ,
V_13 [ V_93 ] ) ;
#endif
F_7 ( V_15 ) ;
}
if ( V_202 & V_196 ) {
F_6 ( V_15 ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
V_13 [ V_56 ] = 0 ;
F_7 ( V_15 ) ;
}
if ( V_202 & V_197 ) {
F_6 ( V_15 ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
V_13 [ V_93 ] = 0 ;
#ifdef F_30
F_4 ( L_14 , __LINE__ ) ;
F_4 ( L_11 , V_13 [ V_56 ] ,
V_13 [ V_93 ] ) ;
#endif
F_7 ( V_15 ) ;
}
return 0 ;
}
static void F_61 ( struct V_5 * V_6 , int V_203 )
{
V_6 -> V_73 = V_203 ;
if ( ! V_6 -> V_75 ) {
F_32 ( V_6 ) ;
}
}
static int
F_62 ( struct V_5 * V_6 , struct V_204 T_4 * V_82 )
{
if ( F_55 ( V_82 , & V_6 -> V_82 , sizeof( struct V_204 ) ) )
return - V_181 ;
V_6 -> V_82 . V_83 = 0 ;
V_6 -> V_82 . V_66 = 0 ;
V_6 -> V_82 . V_84 = 0 ;
V_6 -> V_82 . V_85 = 0 ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 , unsigned long T_4 * V_205 )
{
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
unsigned long V_206 ;
int V_21 ;
if ( F_64 ( V_206 , V_205 ) )
return - V_181 ;
V_21 = V_6 -> line ;
V_6 -> V_123 &= ~ V_207 ;
V_6 -> V_123 |= V_206 & V_207 ;
V_13 [ V_127 ] = V_6 -> V_123 ;
return 0 ;
}
static int
F_65 ( struct V_5 * V_6 , unsigned long T_4 * V_206 )
{
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
int V_21 ;
unsigned long V_180 ;
V_21 = V_6 -> line ;
V_180 = V_13 [ V_127 ] & V_207 ;
return F_66 ( V_180 , V_206 ) ;
}
static int
F_67 ( struct V_5 * V_6 , unsigned long T_4 * V_205 )
{
unsigned long V_206 ;
if ( F_64 ( V_206 , V_205 ) )
return - V_181 ;
V_6 -> V_124 = V_206 & 0x0f ;
return 0 ;
}
static int
F_68 ( struct V_5 * V_6 , unsigned long T_4 * V_206 )
{
return F_66 ( V_6 -> V_124 , V_206 ) ;
}
static int F_69 ( struct V_5 * V_6 , unsigned long T_4 * V_205 )
{
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
int V_21 ;
unsigned long V_206 ;
if ( F_64 ( V_206 , V_205 ) )
return - V_181 ;
V_21 = V_6 -> line ;
V_13 [ V_167 ] = V_206 & 0xff ;
V_13 [ V_168 ] = ( V_206 >> 8 ) & 0xff ;
return 0 ;
}
static int F_70 ( struct V_5 * V_6 , unsigned long T_4 * V_206 )
{
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
int V_21 ;
unsigned long V_180 ;
V_21 = V_6 -> line ;
V_180 = V_13 [ V_167 ] ;
return F_66 ( V_180 , V_206 ) ;
}
static int F_71 ( struct V_5 * V_6 , unsigned long V_206 )
{
V_6 -> V_166 = V_206 & 0xff ;
return 0 ;
}
static int
F_72 ( struct V_5 * V_6 , unsigned long T_4 * V_206 )
{
return F_66 ( V_6 -> V_166 , V_206 ) ;
}
static int
F_73 ( struct V_17 * V_18 ,
unsigned int V_14 , unsigned long V_205 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
int V_208 = 0 ;
void T_4 * V_209 = ( void T_4 * ) V_205 ;
#ifdef F_9
F_4 ( L_31 , V_18 -> V_7 , V_14 , V_205 ) ;
#endif
F_74 () ;
switch ( V_14 ) {
case V_210 :
V_208 = F_62 ( V_6 , V_209 ) ;
break;
case V_211 :
V_208 = F_65 ( V_6 , V_209 ) ;
break;
case V_212 :
V_208 = F_63 ( V_6 , V_209 ) ;
break;
case V_213 :
V_208 = F_68 ( V_6 , V_209 ) ;
break;
case V_214 :
V_208 = F_67 ( V_6 , V_209 ) ;
break;
case V_215 :
V_208 = F_70 ( V_6 , V_209 ) ;
break;
case V_216 :
V_208 = F_69 ( V_6 , V_209 ) ;
break;
case V_217 :
V_208 = F_72 ( V_6 , V_209 ) ;
break;
case V_218 :
V_208 = F_71 ( V_6 , ( unsigned long ) V_205 ) ;
break;
case V_219 :
V_208 = F_75 ( V_18 ) ;
if ( V_208 )
break;
F_76 ( V_18 , 0 ) ;
if ( ! V_205 )
F_61 ( V_6 , V_74 / 4 ) ;
break;
case V_220 :
V_208 = F_75 ( V_18 ) ;
if ( V_208 )
break;
F_76 ( V_18 , 0 ) ;
F_61 ( V_6 , V_205 ? V_205 * ( V_74 / 10 ) : V_74 / 4 ) ;
break;
case V_221 :
V_208 = F_54 ( V_6 , V_209 ) ;
break;
case V_222 :
V_208 = F_56 ( V_6 , V_209 ) ;
break;
default:
V_208 = - V_223 ;
}
F_77 () ;
#ifdef F_9
F_4 ( L_32 ) ;
#endif
return V_208 ;
}
static void F_78 ( struct V_17 * V_18 , struct V_224 * V_225 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
#ifdef F_9
F_4 ( L_33 , V_18 -> V_7 ) ;
#endif
if ( V_18 -> V_97 -> V_98 == V_225 -> V_98 )
return;
F_28 ( V_6 ) ;
if ( ( V_225 -> V_98 & V_226 ) &&
! ( V_18 -> V_97 -> V_98 & V_226 ) ) {
V_18 -> V_63 = 0 ;
F_10 ( V_18 ) ;
}
#ifdef F_79
if ( ! ( V_225 -> V_98 & V_150 ) &&
( V_18 -> V_97 -> V_98 & V_150 ) )
F_17 ( & V_6 -> V_59 ) ;
#endif
}
static void F_80 ( struct V_17 * V_18 , struct V_227 * V_228 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
#ifdef F_9
F_4 ( L_34 , V_18 -> V_7 ) ;
#endif
if ( ! V_6 || F_2 ( V_6 , V_18 -> V_7 , L_35 ) ) {
return;
}
#ifdef F_29
F_4 ( L_36 , V_18 -> V_7 , V_6 -> V_171 ) ;
#endif
if ( ( V_18 -> V_171 == 1 ) && ( V_6 -> V_171 != 1 ) ) {
F_4 ( L_37
L_38 , V_6 -> V_171 ) ;
V_6 -> V_171 = 1 ;
}
#ifdef F_81
F_4 ( L_39 , __LINE__ ,
V_6 -> V_171 - 1 ) ;
#endif
if ( -- V_6 -> V_171 < 0 ) {
F_4 ( L_40 ,
V_6 -> line , V_6 -> V_171 ) ;
#ifdef F_81
F_4 ( L_41 , __LINE__ ) ;
#endif
V_6 -> V_171 = 0 ;
}
if ( V_6 -> V_171 )
return;
V_6 -> V_15 |= V_229 ;
if ( V_6 -> V_15 & V_86 )
F_76 ( V_18 , 3000 ) ;
F_33 ( V_6 ) ;
F_48 ( V_18 ) ;
F_82 ( V_18 ) ;
V_6 -> V_18 = NULL ;
if ( V_6 -> V_230 ) {
if ( V_6 -> V_184 ) {
F_83 ( F_84
( V_6 -> V_184 ) ) ;
}
F_17 ( & V_6 -> V_59 ) ;
}
V_6 -> V_15 &= ~ ( V_60 | V_229 ) ;
F_17 ( & V_6 -> V_231 ) ;
#ifdef F_9
F_4 ( L_42 ) ;
#endif
}
void F_85 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_19 ;
#ifdef F_9
F_4 ( L_43 , V_18 -> V_7 ) ;
#endif
if ( F_2 ( V_6 , V_18 -> V_7 , L_44 ) )
return;
F_33 ( V_6 ) ;
#if 0
info->event = 0;
info->count = 0;
#ifdef F_81
printk("cyc: %d: setting count to 0\n", __LINE__);
#endif
info->tty = 0;
#endif
V_6 -> V_15 &= ~ V_60 ;
F_17 ( & V_6 -> V_59 ) ;
}
static int
F_86 ( struct V_17 * V_18 , struct V_227 * V_228 ,
struct V_5 * V_6 )
{
F_87 ( V_232 , V_233 ) ;
unsigned long V_15 ;
int V_21 ;
int V_234 ;
volatile T_1 * V_13 = ( T_1 * ) V_20 ;
if ( V_6 -> V_15 & V_229 ) {
F_88 ( & V_6 -> V_231 ) ;
if ( V_6 -> V_15 & V_235 ) {
return - V_236 ;
} else {
return - V_237 ;
}
}
if ( V_228 -> V_238 & V_239 ) {
V_6 -> V_15 |= V_60 ;
return 0 ;
}
V_234 = 0 ;
F_89 ( & V_6 -> V_59 , & V_232 ) ;
#ifdef F_29
F_4 ( L_45 ,
V_18 -> V_7 , V_6 -> V_171 ) ;
#endif
V_6 -> V_171 -- ;
#ifdef F_81
F_4 ( L_39 , __LINE__ , V_6 -> V_171 ) ;
#endif
V_6 -> V_230 ++ ;
V_21 = V_6 -> line ;
while ( 1 ) {
F_6 ( V_15 ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
V_13 [ V_56 ] = V_92 ;
V_13 [ V_93 ] = V_94 ;
#ifdef F_30
F_4 ( L_10 , __LINE__ ) ;
F_4 ( L_11 , V_13 [ V_56 ] ,
V_13 [ V_93 ] ) ;
#endif
F_7 ( V_15 ) ;
F_90 ( V_240 ) ;
if ( F_91 ( V_228 )
|| ! ( V_6 -> V_15 & V_86 ) ) {
if ( V_6 -> V_15 & V_235 ) {
V_234 = - V_236 ;
} else {
V_234 = - V_237 ;
}
break;
}
F_6 ( V_15 ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
if ( ! ( V_6 -> V_15 & V_229 )
&& ( F_37 ( V_18 )
|| ( V_13 [ V_56 ] & V_57 ) ) ) {
F_7 ( V_15 ) ;
break;
}
F_7 ( V_15 ) ;
if ( F_92 ( V_233 ) ) {
V_234 = - V_237 ;
break;
}
#ifdef F_29
F_4 ( L_46 ,
V_18 -> V_7 , V_6 -> V_171 ) ;
#endif
F_77 () ;
F_93 () ;
F_74 () ;
}
F_94 ( V_241 ) ;
F_95 ( & V_6 -> V_59 , & V_232 ) ;
if ( ! F_91 ( V_228 ) ) {
V_6 -> V_171 ++ ;
#ifdef F_81
F_4 ( L_47 , __LINE__ ,
V_6 -> V_171 ) ;
#endif
}
V_6 -> V_230 -- ;
#ifdef F_29
F_4 ( L_48 ,
V_18 -> V_7 , V_6 -> V_171 ) ;
#endif
if ( V_234 )
return V_234 ;
V_6 -> V_15 |= V_60 ;
return 0 ;
}
int F_96 ( struct V_17 * V_18 , struct V_227 * V_228 )
{
struct V_5 * V_6 ;
int V_234 , line ;
line = V_18 -> V_242 ;
if ( ( line < 0 ) || ( V_10 <= line ) ) {
return - V_243 ;
}
V_6 = & V_9 [ line ] ;
if ( V_6 -> line < 0 ) {
return - V_243 ;
}
#ifdef F_9
F_4 ( L_49 , V_18 -> V_7 ) ;
#endif
if ( F_2 ( V_6 , V_18 -> V_7 , L_50 ) ) {
return - V_243 ;
}
#ifdef F_29
F_4 ( L_51 , V_18 -> V_7 , V_6 -> V_171 ) ;
#endif
V_6 -> V_171 ++ ;
#ifdef F_81
F_4 ( L_47 , __LINE__ , V_6 -> V_171 ) ;
#endif
V_18 -> V_19 = V_6 ;
V_6 -> V_18 = V_18 ;
V_234 = F_25 ( V_6 ) ;
if ( V_234 ) {
return V_234 ;
}
V_234 = F_86 ( V_18 , V_228 , V_6 ) ;
if ( V_234 ) {
#ifdef F_29
F_4 ( L_52 ,
V_234 ) ;
#endif
return V_234 ;
}
#ifdef F_29
F_4 ( L_53 ) ;
#endif
return 0 ;
}
static void F_97 ( void )
{
F_4 ( L_54 ) ;
}
void F_98 ( int V_101 )
{
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
int V_169 ;
T_1 V_244 ;
T_1 V_245 , V_115 , V_246 = 0 ;
unsigned long V_15 ;
F_6 ( V_15 ) ;
V_13 [ V_22 ] = 0 ;
V_245 = V_13 [ V_155 ] << 5 ;
V_115 = V_13 [ V_156 ] ;
for ( V_244 = 0 ; V_244 < sizeof( V_112 ) ; V_244 ++ )
if ( V_115 == V_112 [ V_244 ] && V_245 == V_114 [ V_244 ] )
break;
if ( V_244 >= sizeof( V_112 ) ) {
V_244 = 14 ;
V_246 = 1 ;
}
V_247 = V_244 ;
F_1 ( 20000L ) ;
if ( V_13 [ V_16 ] != 0x00 ) {
F_7 ( V_15 ) ;
return;
}
V_13 [ V_16 ] = V_248 ;
F_1 ( 1000L ) ;
if ( V_13 [ V_249 ] == 0x00 ) {
F_7 ( V_15 ) ;
return;
}
V_13 [ V_250 ] = 10 ;
V_13 [ V_251 ] = 0x01 ;
V_13 [ V_252 ] = 0x02 ;
V_13 [ V_253 ] = 0x03 ;
for ( V_169 = 3 ; V_169 >= 0 ; V_169 -- ) {
V_13 [ V_22 ] = ( T_1 ) V_169 ;
V_13 [ V_23 ] = 0 ;
V_13 [ V_254 ] = V_255 ;
V_13 [ V_31 ] = ( T_1 ) V_169 << 2 ;
V_13 [ V_151 ] = 0x5c ;
V_13 [ V_153 ] = V_114 [ V_244 ] ;
V_13 [ V_154 ] = V_112 [ V_244 ] ;
V_13 [ V_155 ] = V_114 [ V_244 ] >> 5 ;
V_13 [ V_156 ] = V_112 [ V_244 ] ;
V_13 [ V_157 ] = 'Q' & 0x1f ;
V_13 [ V_158 ] = 'X' & 0x1f ;
V_13 [ V_159 ] = 0 ;
V_13 [ V_160 ] = 0 ;
V_13 [ V_152 ] = V_144 | V_149 ;
V_13 [ V_161 ] = 0 ;
V_13 [ V_162 ] = V_132 ;
V_13 [ V_127 ] = V_125 [ V_244 ] ;
V_13 [ V_128 ] = 0 ;
V_13 [ V_163 ] = 0 ;
V_13 [ V_164 ] = 0 ;
V_13 [ V_167 ] = 2 ;
V_13 [ V_168 ] = 0 ;
V_13 [ V_56 ] = 0 ;
V_13 [ V_93 ] = 0 ;
F_5 ( V_13 , V_165 | V_100 | V_256 ) ;
}
V_13 [ V_56 ] = V_92 ;
V_13 [ V_93 ] = V_94 ;
V_13 [ V_23 ] = V_95 ;
F_5 ( V_13 , V_90 | V_91 ) ;
F_7 ( V_15 ) ;
F_1 ( 20000L ) ;
F_4 ( L_55 , V_13 [ V_249 ] ) ;
if ( V_246 )
F_4
( L_56 ,
V_245 >> 5 , V_115 ) ;
}
static int T_5 F_99 ( void )
{
struct V_5 * V_6 ;
int V_175 = 0 ;
int V_257 = 0 ;
int V_258 = 0 ;
int V_242 ;
int V_259 ;
#ifdef F_100
struct V_260 V_261 ;
#endif
if ( ! ( V_262 & V_263 ) )
return 0 ;
V_264 = F_101 ( V_10 ) ;
if ( ! V_264 )
return - V_89 ;
#if 0
scrn[1] = '\0';
#endif
F_97 () ;
if ( V_265 )
V_259 = V_265 & 0017 ;
else {
V_259 = V_247 ;
V_110 = & V_9 [ 0 ] ;
V_265 = V_259 | V_143 ;
#if 0
serial_console = 64;
#endif
}
V_264 -> V_266 = V_267 ;
V_264 -> V_7 = L_57 ;
V_264 -> V_268 = V_269 ;
V_264 -> V_270 = 64 ;
V_264 -> type = V_271 ;
V_264 -> V_272 = V_273 ;
V_264 -> V_274 = V_275 ;
V_264 -> V_274 . V_98 =
V_276 | V_143 | V_277 | V_99 | V_150 ;
V_264 -> V_15 = V_278 ;
F_102 ( V_264 , & V_279 ) ;
V_175 = F_103 ( V_264 ) ;
if ( V_175 ) {
F_4 ( V_280 L_58 ) ;
F_104 ( V_264 ) ;
return V_175 ;
}
V_258 = 0 ;
V_6 = V_9 ;
for ( V_242 = 0 ; V_242 < 1 ; V_242 ++ ) {
V_257 = 4 ;
if ( V_258 < V_10 ) {
while ( V_257 -- && V_258 < V_10 ) {
V_6 -> V_11 = V_12 ;
V_6 -> type = V_281 ;
V_6 -> V_282 = V_242 ;
V_6 -> line = V_258 ;
V_6 -> V_15 = V_283 ;
V_6 -> V_18 = NULL ;
V_6 -> V_119 = 12 ;
V_6 -> V_137 = V_149 | V_144 ;
V_6 -> V_133 = V_134 ;
V_6 -> V_129 = V_132 ;
V_6 -> V_123 = 0x08 ;
V_6 -> V_122 = 0 ;
V_6 -> V_121 = 0 ;
V_6 -> V_120 = 0 ;
V_6 -> V_111 = V_112 [ V_259 ] ;
V_6 -> V_113 = V_114 [ V_259 ] ;
V_6 -> V_115 = V_112 [ V_259 ] ;
V_6 -> V_116 = V_114 [ V_259 ] >> 5 ;
V_6 -> V_184 = 0 ;
V_6 -> V_71 = 0 ;
V_6 -> V_171 = 0 ;
#ifdef F_81
F_4 ( L_41 ,
__LINE__ ) ;
#endif
V_6 -> V_230 = 0 ;
V_6 -> V_124 = 0 ;
V_6 -> V_166 = 0 ;
F_105 ( & V_6 -> V_59 ) ;
F_105 ( & V_6 -> V_231 ) ;
V_6 -> V_42 =
V_35 | V_284 | V_43 | V_48 |
V_46 | V_50 ;
F_4 ( L_59 , V_6 -> line ) ;
V_258 ++ ;
V_6 ++ ;
if ( ! ( V_258 & 7 ) ) {
F_4 ( L_60 ) ;
}
}
}
F_4 ( L_61 ) ;
}
while ( V_258 < V_10 ) {
V_6 -> line = - 1 ;
V_258 ++ ;
V_6 ++ ;
}
V_175 = F_106 ( V_285 , F_11 , 0 ,
L_62 , F_11 ) ;
if ( V_175 ) {
F_4 ( V_280 L_63 ) ;
goto V_286;
}
V_175 = F_106 ( V_287 , F_16 , 0 ,
L_64 , F_16 ) ;
if ( V_175 ) {
F_4 ( V_280 L_65 ) ;
goto V_288;
}
V_175 = F_106 ( V_289 , F_20 , 0 ,
L_66 , F_20 ) ;
if ( V_175 ) {
F_4 ( V_280 L_67 ) ;
goto V_290;
}
V_175 = F_106 ( V_291 , F_21 , 0 ,
L_68 , F_21 ) ;
if ( V_175 ) {
F_4 ( V_280 L_69 ) ;
goto V_292;
}
V_293 [ V_294 ] = 0x15 ;
V_293 [ V_295 ] = 0x15 ;
V_293 [ V_296 ] = 0x15 ;
V_293 [ V_297 ] = 3 ;
return 0 ;
V_292:
F_107 ( V_289 , F_20 ) ;
V_290:
F_107 ( V_287 , F_16 ) ;
V_288:
F_107 ( V_285 , F_11 ) ;
V_286:
if ( F_108 ( V_264 ) )
F_4 ( V_280
L_70 ) ;
F_104 ( V_264 ) ;
return V_175 ;
}
static void F_109 ( int V_298 )
{
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
int V_21 ;
struct V_5 * V_6 ;
unsigned long V_15 ;
V_6 = & V_9 [ V_298 ] ;
V_21 = V_6 -> line ;
F_4 ( L_71 , V_21 ) ;
F_4 ( L_72 ) ;
F_4 ( L_73 ,
V_6 -> V_282 , V_6 -> line , V_6 -> V_15 ) ;
F_4
( L_74 ,
( long ) V_6 -> V_18 , V_6 -> V_42 , V_6 -> V_118 ,
V_6 -> V_119 ) ;
F_4 ( L_75 ,
V_6 -> V_137 , V_6 -> V_133 , V_6 -> V_129 , V_6 -> V_123 , V_6 -> V_122 ,
V_6 -> V_121 , V_6 -> V_120 ) ;
F_4 ( L_76 , V_6 -> V_111 , V_6 -> V_113 ,
V_6 -> V_115 , V_6 -> V_116 ) ;
F_4 ( L_77 , V_6 -> V_184 ,
V_6 -> V_299 , V_6 -> V_171 ) ;
F_4 ( L_78 , V_6 -> V_71 ,
V_6 -> V_230 ) ;
F_4 ( L_79 , ( long ) V_6 -> V_59 ) ;
F_6 ( V_15 ) ;
F_4 ( L_80 , V_13 [ V_249 ] ) ;
F_4 ( L_81 , V_13 [ V_22 ] ) ;
F_4 ( L_82 , V_13 [ V_34 ] ) ;
F_4 ( L_83 , V_13 [ V_300 ] ) ;
F_4 ( L_84 , V_13 [ V_55 ] ) ;
F_4 ( L_85 , V_13 [ V_301 ] ) ;
F_4 ( L_86 , V_13 [ V_302 ] ) ;
F_4 ( L_87 , V_13 [ V_303 ] ) ;
F_4 ( L_88 , V_13 [ V_250 ] ) ;
V_13 [ V_22 ] = ( T_1 ) V_21 ;
#if 0
printk(" CyRIVR %x\n", base_addr[CyRIVR]);
printk(" CyTIVR %x\n", base_addr[CyTIVR]);
printk(" CyMIVR %x\n", base_addr[CyMIVR]);
printk(" CyMISR %x\n", base_addr[CyMISR]);
#endif
F_4 ( L_89 , V_13 [ V_16 ] ) ;
F_4 ( L_90 , V_13 [ V_23 ] ) ;
F_4 ( L_91 , V_13 [ V_152 ] ) ;
F_4 ( L_92 , V_13 [ V_161 ] ) ;
F_4 ( L_93 , V_13 [ V_162 ] ) ;
F_4 ( L_94 , V_13 [ V_127 ] ) ;
F_4 ( L_95 , V_13 [ V_128 ] ) ;
#if 0
printk(" CyCCSR %x\n", base_addr[CyCCSR]);
printk(" CyRDCR %x\n", base_addr[CyRDCR]);
#endif
F_4 ( L_96 , V_13 [ V_157 ] ) ;
F_4 ( L_97 , V_13 [ V_158 ] ) ;
#if 0
printk(" CySCHR3 %x\n", base_addr[CySCHR3]);
printk(" CySCHR4 %x\n", base_addr[CySCHR4]);
printk(" CySCRL %x\n", base_addr[CySCRL]);
printk(" CySCRH %x\n", base_addr[CySCRH]);
printk(" CyLNC %x\n", base_addr[CyLNC]);
printk(" CyMCOR1 %x\n", base_addr[CyMCOR1]);
printk(" CyMCOR2 %x\n", base_addr[CyMCOR2]);
#endif
F_4 ( L_98 , V_13 [ V_167 ] ) ;
F_4 ( L_99 , V_13 [ V_168 ] ) ;
F_4 ( L_100 , V_13 [ V_56 ] ) ;
F_4 ( L_101 , V_13 [ V_93 ] ) ;
F_4 ( L_102 , V_13 [ V_156 ] ) ;
F_4 ( L_103 , V_13 [ V_155 ] ) ;
F_4 ( L_104 , V_13 [ V_154 ] ) ;
F_4 ( L_105 , V_13 [ V_153 ] ) ;
F_7 ( V_15 ) ;
}
void F_110 ( struct V_304 * V_305 , const char * V_306 ,
unsigned V_171 )
{
volatile unsigned char * V_13 = ( T_1 * ) V_20 ;
unsigned long V_15 ;
volatile T_1 V_307 ;
T_1 V_308 ;
int V_182 ;
T_1 V_309 = 0 ;
int V_4 = 0 ;
F_6 ( V_15 ) ;
V_182 = 0 ;
V_13 [ V_22 ] = ( T_1 ) V_182 ;
while ( V_13 [ V_16 ] )
;
V_13 [ V_16 ] = V_91 ;
V_308 = V_13 [ V_23 ] ;
V_13 [ V_23 ] = V_24 ;
while ( 1 ) {
if ( V_293 [ V_295 ] & 0x20 ) {
V_307 = V_293 [ V_310 ] ;
if ( ( V_13 [ V_31 ] >> 2 ) == V_182 ) {
if ( V_4 == V_171 ) {
V_13 [ V_69 ] = V_37 ;
break;
}
if ( V_309 ) {
V_13 [ V_72 ] = '\n' ;
V_306 ++ ;
V_4 ++ ;
V_309 = 0 ;
} else if ( * V_306 == '\n' ) {
V_13 [ V_72 ] = '\r' ;
V_309 = 1 ;
} else {
V_13 [ V_72 ] = * V_306 ++ ;
V_4 ++ ;
}
V_13 [ V_69 ] = 0 ;
} else
V_13 [ V_69 ] = V_37 ;
}
}
V_13 [ V_23 ] = V_308 ;
F_7 ( V_15 ) ;
}
static struct V_311 * F_111 ( struct V_304 * V_172 ,
int * V_242 )
{
* V_242 = V_172 -> V_242 ;
return V_264 ;
}
static int T_5 F_112 ( void )
{
if ( V_312 == V_313 ||
V_312 == V_314 ||
V_312 == V_315 ) {
F_98 ( 0 ) ;
F_113 ( & V_316 ) ;
}
return 0 ;
}
