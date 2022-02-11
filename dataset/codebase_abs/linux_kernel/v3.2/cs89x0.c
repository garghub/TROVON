static int T_1 F_1 ( char * V_1 )
{
V_2 = F_2 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
if ( ! strcmp ( V_1 , L_1 ) ) V_3 = V_4 ;
else if ( ! strcmp ( V_1 , L_2 ) ) V_3 = V_5 ;
else if ( ! strcmp ( V_1 , L_3 ) ) V_3 = V_6 ;
return 1 ;
}
struct V_7 * T_1 F_4 ( int V_8 )
{
struct V_7 * V_9 = F_5 ( sizeof( struct V_10 ) ) ;
unsigned * V_11 ;
int V_12 = 0 ;
int V_13 ;
int V_14 ;
if ( ! V_9 )
return F_6 ( - V_15 ) ;
sprintf ( V_9 -> V_16 , L_4 , V_8 ) ;
F_7 ( V_9 ) ;
V_14 = V_9 -> V_17 ;
V_13 = V_9 -> V_13 ;
if ( V_18 )
F_8 ( L_5 , V_14 ) ;
if ( V_14 > 0x1ff ) {
V_12 = F_9 ( V_9 , V_14 , 0 ) ;
} else if ( V_14 != 0 ) {
V_12 = - V_19 ;
} else {
for ( V_11 = V_20 ; * V_11 ; V_11 ++ ) {
if ( F_9 ( V_9 , * V_11 , 0 ) == 0 )
break;
V_9 -> V_13 = V_13 ;
}
if ( ! * V_11 )
V_12 = - V_15 ;
}
if ( V_12 )
goto V_21;
return V_9 ;
V_21:
F_10 ( V_9 ) ;
F_8 ( V_22 L_6 ) ;
return F_6 ( V_12 ) ;
}
static T_2
F_11 ( unsigned long V_17 , int V_23 )
{
return F_12 ( V_17 + ( V_23 << 1 ) ) ;
}
static void
F_13 ( unsigned long V_17 , int V_23 , T_2 V_24 )
{
F_14 ( V_24 , V_17 + ( V_23 << 1 ) ) ;
}
static T_2
F_11 ( unsigned long V_17 , int V_23 )
{
return F_15 ( V_17 + ( V_23 << 1 ) ) ;
}
static void
F_13 ( unsigned long V_17 , int V_23 , T_2 V_24 )
{
F_16 ( V_24 , V_17 + ( V_23 << 1 ) ) ;
}
static T_2
F_11 ( unsigned long V_17 , int V_23 )
{
return F_17 ( V_17 + V_23 ) ;
}
static void
F_13 ( unsigned long V_17 , int V_23 , T_2 V_24 )
{
F_18 ( V_24 , V_17 + V_23 ) ;
}
static void
F_19 ( unsigned long V_17 , int V_23 , void * V_25 , int V_26 )
{
T_3 * V_27 = ( T_3 * ) V_25 ;
do {
T_2 V_28 ;
V_28 = F_11 ( V_17 , V_23 ) ;
* V_27 ++ = ( T_3 ) V_28 ;
* V_27 ++ = ( T_3 ) ( V_28 >> 8 ) ;
} while ( -- V_26 );
}
static void
F_20 ( unsigned long V_17 , int V_23 , void * V_25 , int V_26 )
{
T_3 * V_27 = ( T_3 * ) V_25 ;
do {
T_2 V_28 ;
V_28 = * V_27 ++ ;
V_28 |= ( * V_27 ++ ) << 8 ;
F_13 ( V_17 , V_23 , V_28 ) ;
} while ( -- V_26 );
}
static T_2
F_21 ( struct V_7 * V_9 , T_2 V_29 )
{
F_13 ( V_9 -> V_17 , V_30 , V_29 ) ;
return F_11 ( V_9 -> V_17 , V_31 ) ;
}
static void
F_22 ( struct V_7 * V_9 , T_2 V_29 , T_2 V_24 )
{
F_13 ( V_9 -> V_17 , V_30 , V_29 ) ;
F_13 ( V_9 -> V_17 , V_31 , V_24 ) ;
}
static int T_1
F_23 ( struct V_7 * V_9 )
{
int V_32 = V_33 ;
while( F_21 ( V_9 , V_34 ) & V_35 )
if ( V_33 - V_32 >= 40 )
return - 1 ;
return 0 ;
}
static int T_1
F_24 ( struct V_7 * V_9 , int V_36 , int V_37 , int * V_38 )
{
int V_39 ;
if ( V_18 > 3 ) F_8 ( L_7 , V_36 , V_37 ) ;
for ( V_39 = 0 ; V_39 < V_37 ; V_39 ++ ) {
if ( F_23 ( V_9 ) < 0 ) return - 1 ;
F_22 ( V_9 , V_40 , ( V_36 + V_39 ) | V_41 ) ;
if ( F_23 ( V_9 ) < 0 ) return - 1 ;
V_38 [ V_39 ] = F_21 ( V_9 , V_42 ) ;
if ( V_18 > 3 ) F_8 ( L_8 , V_38 [ V_39 ] ) ;
}
if ( V_18 > 3 ) F_8 ( L_9 ) ;
return 0 ;
}
static int T_1
F_25 ( int V_36 , int V_37 , int * V_38 )
{
int V_39 , V_43 ;
V_43 = 0 ;
for ( V_39 = 0 ; V_39 < V_37 ; V_39 ++ )
V_43 += V_38 [ V_39 ] ;
V_43 &= 0xffff ;
if ( V_43 == 0 )
return 0 ;
return - 1 ;
}
static void F_26 ( struct V_7 * V_9 )
{
F_27 ( V_9 -> V_13 ) ;
F_28 ( V_9 -> V_13 , V_9 ) ;
F_29 ( V_9 -> V_13 ) ;
}
static int T_1
F_9 ( struct V_7 * V_9 , int V_44 , int V_45 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
static unsigned V_47 ;
int V_39 ;
int V_48 ;
unsigned V_49 = 0 ;
int V_50 [ V_51 ] ;
int V_52 ;
if ( ! V_45 ) {
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
F_31 ( & V_46 -> V_53 ) ;
#ifndef F_32
#if V_54
if ( V_2 ) {
V_46 -> V_55 = 1 ;
V_46 -> V_56 = V_2 ;
V_46 -> V_57 = 16 ;
}
#endif
V_46 -> V_58 = V_3 ;
#endif
#if F_33 ( V_59 )
V_46 -> V_58 |= V_4 | V_60 ;
#endif
}
if ( ! F_34 ( V_44 & ~ 3 , V_61 , V_62 ) ) {
F_8 ( V_63 L_10 ,
V_62 , V_44 , V_61 ) ;
V_52 = - V_64 ;
goto V_65;
}
if ( V_44 & 1 ) {
if ( V_18 > 1 )
F_8 ( V_66 L_11 , V_9 -> V_16 , V_44 ) ;
if ( ( V_44 & 2 ) != 2 )
if ( ( F_11 ( V_44 & ~ 3 , V_30 ) & V_67 ) != V_68 ) {
F_8 ( V_63 L_12 ,
V_9 -> V_16 , F_11 ( V_44 & ~ 3 , V_30 ) ) ;
V_52 = - V_15 ;
goto V_69;
}
}
V_44 &= ~ 3 ;
F_8 ( V_70 L_13 ,
V_44 , V_30 , F_11 ( V_44 , V_30 ) ) ;
F_13 ( V_44 , V_30 , V_71 ) ;
V_48 = F_11 ( V_44 , V_31 ) ;
if ( V_48 != V_72 ) {
F_8 ( V_70 L_14
V_73 L_9 ,
V_9 -> V_16 , V_44 , V_31 , V_48 ) ;
V_52 = - V_15 ;
goto V_69;
}
V_9 -> V_17 = V_44 ;
V_49 = F_21 ( V_9 , V_74 ) ;
V_46 -> V_75 = V_49 & ~ V_76 ;
V_46 -> V_77 = ( ( V_49 & V_76 ) >> 8 ) + 'A' ;
V_46 -> V_78 = V_79 ;
if ( V_46 -> V_75 == V_80 && V_46 -> V_77 >= 'F' )
V_46 -> V_78 = V_81 ;
if ( V_46 -> V_75 != V_80 && V_46 -> V_77 >= 'C' )
V_46 -> V_78 = V_81 ;
if ( V_18 && V_47 ++ == 0 )
F_8 ( V_82 ) ;
F_8 ( V_66 L_15 ,
V_9 -> V_16 ,
V_46 -> V_75 == V_80 ? '0' : '2' ,
V_46 -> V_75 == V_83 ? L_16 : L_17 ,
V_46 -> V_77 ,
V_9 -> V_17 ) ;
F_35 ( V_9 ) ;
if ( ( F_21 ( V_9 , V_34 ) & ( V_84 | V_85 ) ) ==
( V_84 | V_85 ) ) {
for ( V_39 = 0 ; V_39 < V_86 / 2 ; V_39 ++ ) {
unsigned int V_87 ;
V_87 = F_21 ( V_9 , V_88 + V_39 * 2 ) ;
V_9 -> V_89 [ V_39 * 2 ] = V_87 & 0xFF ;
V_9 -> V_89 [ V_39 * 2 + 1 ] = V_87 >> 8 ;
}
V_46 -> V_90 = 0 ;
V_39 = F_21 ( V_9 , V_91 ) ;
if ( ( V_39 & ( V_92 | V_93 ) ) == ( V_92 | V_93 ) )
V_46 -> V_90 |= V_94 ;
if ( ( V_39 & V_95 ) == V_95 )
V_46 -> V_90 |= V_96 | V_97 ;
if ( ( V_39 & ( V_98 | V_99 ) ) == 0 )
V_46 -> V_90 |= V_100 | V_101 ;
if ( ( V_39 & ( V_98 | V_99 ) ) == V_98 )
V_46 -> V_90 |= V_102 | V_103 ;
if ( ( V_39 & ( V_98 | V_99 ) ) == V_99 )
V_46 -> V_90 |= V_102 | V_100 |
V_103 | V_101 | V_104 ;
if ( V_18 > 1 )
F_8 ( V_66 L_18 ,
V_9 -> V_16 , V_39 , V_46 -> V_90 ) ;
if ( V_46 -> V_75 == V_80 )
V_46 -> V_105 = F_21 ( V_9 , V_106 ) & V_107 ;
F_8 ( L_19 ) ;
}
F_8 ( L_9 ) ;
if ( ( F_21 ( V_9 , V_34 ) & V_85 ) == 0 )
F_8 ( V_22 L_20 ) ;
else if ( F_24 ( V_9 , V_108 , V_51 , V_50 ) < 0 ) {
F_8 ( V_22 L_21 ) ;
} else if ( F_25 ( V_108 , V_51 , V_50 ) < 0 ) {
if ( ( F_21 ( V_9 , V_34 ) & ( V_84 | V_85 ) ) !=
( V_84 | V_85 ) )
F_8 ( V_22 L_22 ) ;
} else {
if ( ! V_46 -> V_109 ) V_46 -> V_109 = V_50 [ V_110 / 2 ] ;
if ( ! V_46 -> V_90 ) V_46 -> V_90 = V_50 [ V_111 / 2 ] ;
V_46 -> V_105 = V_50 [ V_112 / 2 ] ;
V_9 -> V_113 = V_50 [ V_114 / 2 ] << 8 ;
for ( V_39 = 0 ; V_39 < V_86 / 2 ; V_39 ++ ) {
V_9 -> V_89 [ V_39 * 2 ] = V_50 [ V_39 ] ;
V_9 -> V_89 [ V_39 * 2 + 1 ] = V_50 [ V_39 ] >> 8 ;
}
if ( V_18 > 1 )
F_8 ( V_70 L_23 ,
V_9 -> V_16 , V_46 -> V_90 ) ;
}
{
int V_115 = 0 ;
if ( V_46 -> V_58 & V_4 ) { V_46 -> V_90 |= V_100 ; V_115 ++ ; }
if ( V_46 -> V_58 & V_5 ) { V_46 -> V_90 |= V_102 ; V_115 ++ ; }
if ( V_46 -> V_58 & V_6 ) { V_46 -> V_90 |= V_116 ; V_115 ++ ; }
if ( V_115 > 1 ) { V_46 -> V_90 |= V_104 ; }
else if ( V_46 -> V_58 & V_4 ) { V_46 -> V_90 |= V_101 ; }
else if ( V_46 -> V_58 & V_5 ) { V_46 -> V_90 |= V_103 ; }
else if ( V_46 -> V_58 & V_6 ) { V_46 -> V_90 |= V_117 ; }
}
if ( V_18 > 1 )
F_8 ( V_70 L_24 ,
V_9 -> V_16 , V_46 -> V_58 , V_46 -> V_90 ) ;
F_8 ( V_66 L_25 ,
( V_46 -> V_90 & V_100 ) ? L_26 : L_17 ,
( V_46 -> V_90 & V_102 ) ? L_27 : L_17 ,
( V_46 -> V_90 & V_116 ) ? L_28 : L_17 ) ;
V_46 -> V_118 = 0xffff ;
if ( V_46 -> V_75 != V_80 &&
( V_39 = F_21 ( V_9 , V_119 ) & 0xff ,
( V_39 != 0 && V_39 < V_120 ) ) ) {
if ( ! V_9 -> V_13 )
V_9 -> V_13 = V_39 ;
} else {
V_39 = V_46 -> V_105 & V_107 ;
if ( V_46 -> V_75 == V_80 ) {
#ifdef F_36
V_39 = V_121 [ 0 ] ;
#else
if ( V_39 >= F_37 ( V_121 ) )
F_8 ( L_29 , V_39 ) ;
else
V_39 = V_121 [ V_39 ] ;
V_46 -> V_118 = V_122 ;
} else {
int V_123 [ V_124 / 2 ] ;
if ( F_24 ( V_9 , V_125 ,
V_124 / 2 ,
V_123 ) >= 0 ) {
if ( ( V_123 [ 0 ] & 0xff ) == V_126 )
V_46 -> V_118 = ( V_123 [ 0 ] >> 8 ) | ( V_123 [ 1 ] << 8 ) ;
}
#endif
}
if ( ! V_9 -> V_13 )
V_9 -> V_13 = V_39 ;
}
F_8 ( L_30 , V_9 -> V_13 ) ;
#if V_54
if ( V_46 -> V_55 ) {
F_38 ( V_9 ) ;
F_8 ( L_31 , V_9 -> V_56 ) ;
}
else
#endif
{
F_8 ( L_32 ) ;
}
F_8 ( L_33 , V_9 -> V_89 ) ;
V_9 -> V_127 = & V_128 ;
V_9 -> V_129 = V_130 ;
F_8 ( L_9 ) ;
if ( V_18 )
F_8 ( L_34 ) ;
V_52 = F_39 ( V_9 ) ;
if ( V_52 )
goto V_131;
return 0 ;
V_131:
F_13 ( V_9 -> V_17 , V_30 , V_71 ) ;
V_69:
F_40 ( V_44 & ~ 3 , V_61 ) ;
V_65:
return V_52 ;
}
static void
F_38 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
if ( V_46 -> V_56 ) {
V_9 -> V_56 = V_46 -> V_56 ;
V_46 -> V_105 |= V_132 ;
} else {
if ( ( V_46 -> V_105 & V_133 ) == 0 )
return;
V_9 -> V_56 = V_46 -> V_105 & V_134 ;
if ( V_46 -> V_75 == V_80 )
V_9 -> V_56 += 5 ;
if ( V_9 -> V_56 < 5 || V_9 -> V_56 > 7 ) {
V_46 -> V_105 &= ~ V_133 ;
return;
}
}
}
static void
F_41 ( struct V_7 * V_9 , int V_75 , int V_56 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
if ( ( V_46 -> V_105 & V_133 ) == 0 )
return;
if ( V_75 == V_80 ) {
F_22 ( V_9 , V_135 , V_56 - 5 ) ;
} else {
F_22 ( V_9 , V_136 , V_56 ) ;
}
}
static void
F_42 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
if ( V_46 -> V_55 ) {
if ( ( V_46 -> V_105 & V_133 ) == 0 ) {
if ( V_18 > 3 )
F_8 ( L_35 ) ;
return;
}
if ( V_46 -> V_105 & V_132 ) {
V_46 -> V_137 |= V_138 ;
if ( V_18 > 3 )
F_8 ( L_36 ) ;
} else {
V_46 -> V_137 |= V_139 ;
if ( V_18 > 3 )
F_8 ( L_37 ) ;
}
}
}
static int
F_43 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
if ( V_46 -> V_55 )
return ( V_46 -> V_105 & V_133 ) ? V_140 : 0 ;
else
return 0 ;
}
static int
F_44 ( struct V_7 * V_9 )
{
int V_52 = 0 ;
struct V_10 * V_46 = F_30 ( V_9 ) ;
if ( V_46 -> V_55 ) {
if ( V_46 -> V_105 & V_133 )
V_52 |= V_141 ;
if ( V_46 -> V_105 & V_142 )
V_52 |= V_143 ;
if ( V_46 -> V_57 == 64 )
V_52 |= V_144 ;
V_52 |= V_145 ;
}
return V_52 ;
}
static void
F_45 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
struct V_146 * V_147 ;
int V_148 , V_26 ;
unsigned char * V_149 = V_46 -> V_150 ;
V_148 = V_149 [ 0 ] + ( V_149 [ 1 ] << 8 ) ;
V_26 = V_149 [ 2 ] + ( V_149 [ 3 ] << 8 ) ;
V_149 += 4 ;
if ( V_18 > 5 ) {
F_8 ( L_38 ,
V_9 -> V_16 , ( unsigned long ) V_149 , V_148 , V_26 ) ;
}
if ( ( V_148 & V_151 ) == 0 ) {
F_46 ( V_148 , V_9 ) ;
goto V_152;
}
V_147 = F_47 ( V_26 + 2 ) ;
if ( V_147 == NULL ) {
if ( V_18 )
F_8 ( L_39 , V_9 -> V_16 ) ;
V_9 -> V_153 . V_154 ++ ;
V_152:
V_149 += ( V_26 + 3 ) & ~ 3 ;
if ( V_149 >= V_46 -> V_155 ) V_149 -= V_46 -> V_57 * 1024 ;
V_46 -> V_150 = V_149 ;
return;
}
F_48 ( V_147 , 2 ) ;
if ( V_149 + V_26 > V_46 -> V_155 ) {
int V_156 = V_46 -> V_155 - V_149 ;
memcpy ( F_49 ( V_147 , V_156 ) , V_149 , V_156 ) ;
memcpy ( F_49 ( V_147 , V_26 - V_156 ) , V_46 -> V_157 ,
V_26 - V_156 ) ;
} else {
memcpy ( F_49 ( V_147 , V_26 ) , V_149 , V_26 ) ;
}
V_149 += ( V_26 + 3 ) & ~ 3 ;
if ( V_149 >= V_46 -> V_155 ) V_149 -= V_46 -> V_57 * 1024 ;
V_46 -> V_150 = V_149 ;
if ( V_18 > 3 ) {
F_8 ( L_40 ,
V_9 -> V_16 , V_26 ,
( V_147 -> V_158 [ V_86 + V_86 ] << 8 ) | V_147 -> V_158 [ V_86 + V_86 + 1 ] ) ;
}
V_147 -> V_159 = F_50 ( V_147 , V_9 ) ;
F_51 ( V_147 ) ;
V_9 -> V_153 . V_160 ++ ;
V_9 -> V_153 . V_161 += V_26 ;
}
static void T_1 F_35 ( struct V_7 * V_9 )
{
#if ! F_33 ( V_162 )
#if ! F_33 ( V_163 )
struct V_10 * V_46 = F_30 ( V_9 ) ;
int V_44 = V_9 -> V_17 ;
#endif
int V_164 ;
F_22 ( V_9 , V_165 , F_21 ( V_9 , V_165 ) | V_166 ) ;
F_52 ( 30 ) ;
#if ! F_33 ( V_163 )
if ( V_46 -> V_75 != V_80 ) {
F_13 ( V_44 , V_30 , V_119 ) ;
F_53 ( V_9 -> V_13 , V_44 + V_31 ) ;
F_53 ( 0 , V_44 + V_31 + 1 ) ;
F_13 ( V_44 , V_30 , V_167 ) ;
F_53 ( ( V_9 -> V_113 >> 16 ) & 0xff , V_44 + V_31 ) ;
F_53 ( ( V_9 -> V_113 >> 8 ) & 0xff , V_44 + V_31 + 1 ) ;
}
#endif
V_164 = V_33 ;
while( ( F_21 ( V_9 , V_34 ) & V_168 ) == 0 && V_33 - V_164 < 2 )
;
#endif
}
static void
F_54 ( struct V_7 * V_9 , int V_169 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
unsigned int V_170 ;
int V_171 = V_33 ;
V_170 = V_93 ;
if ( ( ( V_46 -> V_90 & V_94 ) != 0 ) ^ V_169 )
V_170 |= V_92 ;
else
V_170 &= ~ V_92 ;
F_22 ( V_9 , V_165 , V_170 ) ;
while ( V_33 - V_171 < V_130 )
;
}
static int
F_55 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
int V_171 = V_33 ;
int V_172 ;
if ( V_18 > 1 ) F_8 ( L_41 , V_9 -> V_16 ) ;
F_22 ( V_9 , V_91 , V_46 -> V_173 & ~ V_98 ) ;
F_54 ( V_9 , 0 ) ;
for ( V_171 = V_33 ; V_33 - V_171 < 15 ; )
;
if ( ( F_21 ( V_9 , V_174 ) & V_175 ) == 0 )
return V_176 ;
if ( V_46 -> V_75 == V_80 ) {
switch ( V_46 -> V_58 & 0xf0 ) {
#if 0
case FORCE_AUTO:
printk("%s: cs8900 doesn't autonegotiate\n",dev->name);
return DETECTED_NONE;
#endif
case V_177 :
V_46 -> V_58 &= ~ V_177 ;
V_46 -> V_58 |= V_178 ;
break;
case V_178 :
break;
case V_60 :
F_22 ( V_9 , V_179 , F_21 ( V_9 , V_179 ) | V_180 ) ;
break;
}
V_172 = F_21 ( V_9 , V_179 ) & V_180 ;
} else {
switch ( V_46 -> V_58 & 0xf0 ) {
case V_177 :
V_46 -> V_109 = V_181 ;
break;
case V_178 :
V_46 -> V_109 = 0 ;
break;
case V_60 :
V_46 -> V_109 = V_182 | V_183 ;
break;
}
F_22 ( V_9 , V_184 , V_46 -> V_109 & V_185 ) ;
if ( ( V_46 -> V_109 & V_186 ) == V_181 ) {
F_8 ( V_66 L_42 , V_9 -> V_16 ) ;
while ( F_21 ( V_9 , V_187 ) & V_188 ) {
if ( V_33 - V_171 > 4000 ) {
F_8 ( V_63 L_43 ) ;
break;
}
}
}
V_172 = F_21 ( V_9 , V_187 ) & V_189 ;
}
if ( V_172 )
return V_190 ;
else
return V_191 ;
}
static int
F_56 ( struct V_7 * V_9 )
{
char V_192 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 46 ,
0 , 0 ,
0xf3 , 0 } ;
long V_171 = V_33 ;
F_22 ( V_9 , V_91 , F_21 ( V_9 , V_91 ) | V_193 ) ;
memcpy ( V_192 , V_9 -> V_89 , V_86 ) ;
memcpy ( V_192 + V_86 , V_9 -> V_89 , V_86 ) ;
F_13 ( V_9 -> V_17 , V_194 , V_195 ) ;
F_13 ( V_9 -> V_17 , V_196 , V_197 ) ;
while ( V_33 - V_171 < 5 )
if ( F_21 ( V_9 , V_198 ) & V_199 )
break;
if ( V_33 - V_171 >= 5 )
return 0 ;
F_20 ( V_9 -> V_17 , V_200 , V_192 , ( V_197 + 1 ) >> 1 ) ;
if ( V_18 > 1 ) F_8 ( L_44 ) ;
for ( V_171 = V_33 ; V_33 - V_171 < 3 ; )
;
if ( ( F_21 ( V_9 , V_201 ) & V_202 ) == V_203 ) {
if ( V_18 > 1 ) F_8 ( L_45 ) ;
return 1 ;
}
if ( V_18 > 1 ) F_8 ( L_46 ) ;
return 0 ;
}
static int
F_57 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
if ( V_18 > 1 ) F_8 ( L_47 , V_9 -> V_16 ) ;
F_54 ( V_9 , 0 ) ;
F_22 ( V_9 , V_91 , ( V_46 -> V_173 & ~ V_99 ) | V_98 ) ;
if ( F_56 ( V_9 ) )
return V_204 ;
else
return V_176 ;
}
static int
F_58 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
if ( V_18 > 1 ) F_8 ( L_48 , V_9 -> V_16 ) ;
F_54 ( V_9 , 1 ) ;
F_22 ( V_9 , V_91 , ( V_46 -> V_173 & ~ V_99 ) | V_98 ) ;
if ( F_56 ( V_9 ) )
return V_205 ;
else
return V_176 ;
}
static void
F_59 ( struct V_7 * V_9 , int V_75 , int V_13 )
{
int V_39 ;
if ( V_75 == V_80 ) {
for ( V_39 = 0 ; V_39 != F_37 ( V_121 ) ; V_39 ++ )
if ( V_121 [ V_39 ] == V_13 )
break;
if ( V_39 == F_37 ( V_121 ) )
V_39 = 3 ;
F_22 ( V_9 , V_106 , V_39 ) ;
} else {
F_22 ( V_9 , V_119 , V_13 ) ;
}
}
static int
F_60 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
int V_206 = 0 ;
int V_39 ;
int V_207 ;
if ( V_9 -> V_13 < 2 ) {
#if 0
writereg(dev, PP_BusCTL, readreg(dev, PP_BusCTL)|ENABLE_IRQ );
#endif
F_22 ( V_9 , V_208 , V_209 | V_145 ) ;
for ( V_39 = 2 ; V_39 < V_120 ; V_39 ++ ) {
if ( ( 1 << V_39 ) & V_46 -> V_118 ) {
if ( F_61 ( V_39 , F_28 , 0 , V_9 -> V_16 , V_9 ) == 0 ) {
V_9 -> V_13 = V_39 ;
F_59 ( V_9 , V_46 -> V_75 , V_39 ) ;
break;
}
}
}
if ( V_39 >= V_120 ) {
F_22 ( V_9 , V_208 , 0 ) ;
F_8 ( V_63 L_49 ) ;
V_207 = - V_210 ;
goto V_211;
}
}
else
{
#ifndef F_36
if ( ( ( 1 << V_9 -> V_13 ) & V_46 -> V_118 ) == 0 ) {
F_8 ( V_63 L_50 ,
V_9 -> V_16 , V_9 -> V_13 , V_46 -> V_118 ) ;
V_207 = - V_210 ;
goto V_211;
}
#endif
F_22 ( V_9 , V_208 , F_21 ( V_9 , V_208 ) | V_209 ) ;
#if 0
writereg(dev, PP_BusCTL, ENABLE_IRQ | MEMORY_ON);
#endif
F_59 ( V_9 , V_46 -> V_75 , V_9 -> V_13 ) ;
V_207 = F_61 ( V_9 -> V_13 , F_28 , 0 , V_9 -> V_16 , V_9 ) ;
if ( V_207 ) {
F_8 ( V_63 L_51 , V_9 -> V_13 ) ;
goto V_211;
}
}
#if V_54
if ( V_46 -> V_55 ) {
if ( V_46 -> V_105 & V_133 ) {
unsigned long V_212 ;
V_46 -> V_157 = ( unsigned char * ) F_62 ( V_213 ,
F_63 ( V_46 -> V_57 * 1024 ) ) ;
if ( ! V_46 -> V_157 ) {
F_8 ( V_63 L_52 , V_9 -> V_16 , V_46 -> V_57 ) ;
goto V_214;
}
if ( V_18 > 1 ) {
F_8 ( L_53 ,
V_9 -> V_16 ,
( unsigned long ) V_46 -> V_157 ,
( unsigned long ) F_64 ( V_46 -> V_157 ) ) ;
}
if ( ( unsigned long ) V_46 -> V_157 >= V_215 ||
! F_65 ( V_46 -> V_157 , V_46 -> V_157 + V_46 -> V_57 * 1024 - 1 ) ) {
F_8 ( V_63 L_54 , V_9 -> V_16 ) ;
goto V_214;
}
memset ( V_46 -> V_157 , 0 , V_46 -> V_57 * 1024 ) ;
if ( F_66 ( V_9 -> V_56 , V_9 -> V_16 ) ) {
F_8 ( V_63 L_55 , V_9 -> V_16 , V_9 -> V_56 ) ;
goto V_214;
}
F_41 ( V_9 , V_46 -> V_75 , V_9 -> V_56 ) ;
V_46 -> V_150 = V_46 -> V_157 ;
V_46 -> V_155 = V_46 -> V_157 + V_46 -> V_57 * 1024 ;
F_67 ( & V_46 -> V_53 , V_212 ) ;
F_68 ( V_9 -> V_56 ) ;
F_69 ( V_9 -> V_56 ) ;
F_70 ( V_9 -> V_56 , V_216 ) ;
F_71 ( V_9 -> V_56 , F_64 ( V_46 -> V_157 ) ) ;
F_72 ( V_9 -> V_56 , V_46 -> V_57 * 1024 ) ;
F_73 ( V_9 -> V_56 ) ;
F_74 ( & V_46 -> V_53 , V_212 ) ;
}
}
#endif
for ( V_39 = 0 ; V_39 < V_86 / 2 ; V_39 ++ )
F_22 ( V_9 , V_88 + V_39 * 2 , V_9 -> V_89 [ V_39 * 2 ] | ( V_9 -> V_89 [ V_39 * 2 + 1 ] << 8 ) ) ;
F_22 ( V_9 , V_208 , V_145 ) ;
if ( ( V_46 -> V_90 & V_96 ) && ( V_46 -> V_90 & V_97 ) )
V_46 -> V_173 = V_95 ;
else
V_46 -> V_173 = 0 ;
switch( V_46 -> V_90 & V_217 ) {
case V_101 : V_206 = V_46 -> V_90 & V_100 ; break;
case V_103 : V_206 = V_46 -> V_90 & V_102 ; break;
case V_117 : V_206 = V_46 -> V_90 & V_116 ; break;
default: V_206 = V_46 -> V_90 & ( V_100 | V_102 | V_116 ) ;
}
if ( ! V_206 ) {
F_8 ( V_63 L_56 , V_9 -> V_16 ) ;
V_218:
#if V_54
F_75 ( V_9 -> V_56 ) ;
V_214:
F_76 ( V_46 ) ;
#endif
F_22 ( V_9 , V_91 , F_21 ( V_9 , V_91 ) & ~ ( V_193 | V_219 ) ) ;
F_77 ( V_9 -> V_13 , V_9 ) ;
V_207 = - V_210 ;
goto V_211;
}
switch( V_46 -> V_90 & V_217 ) {
case V_101 :
V_206 = F_55 ( V_9 ) ;
if ( V_206 == V_176 ) {
F_8 ( V_22 L_57 , V_9 -> V_16 ) ;
if ( V_46 -> V_109 & V_220 )
V_206 = V_191 ;
}
break;
case V_103 :
V_206 = F_57 ( V_9 ) ;
if ( V_206 == V_176 ) {
F_8 ( V_22 L_58 , V_9 -> V_16 ) ;
if ( V_46 -> V_109 & V_220 )
V_206 = V_204 ;
}
break;
case V_117 :
V_206 = F_58 ( V_9 ) ;
if ( V_206 == V_176 ) {
F_8 ( V_22 L_59 , V_9 -> V_16 ) ;
if ( V_46 -> V_109 & V_220 )
V_206 = V_205 ;
}
break;
case V_104 :
F_22 ( V_9 , V_91 , V_46 -> V_173 | V_99 ) ;
if ( V_46 -> V_90 & V_100 )
if ( ( V_206 = F_55 ( V_9 ) ) != V_176 )
break;
if ( V_46 -> V_90 & V_102 )
if ( ( V_206 = F_57 ( V_9 ) ) != V_176 )
break;
if ( V_46 -> V_90 & V_116 )
if ( ( V_206 = F_58 ( V_9 ) ) != V_176 )
break;
F_8 ( V_63 L_60 , V_9 -> V_16 ) ;
goto V_218;
}
switch( V_206 ) {
case V_176 :
F_8 ( V_63 L_61 , V_9 -> V_16 ) ;
goto V_218;
case V_191 :
F_8 ( V_66 L_62 , V_9 -> V_16 ) ;
break;
case V_190 :
F_8 ( V_66 L_63 , V_9 -> V_16 ) ;
break;
case V_204 :
F_8 ( V_66 L_64 , V_9 -> V_16 ) ;
break;
case V_205 :
F_8 ( V_66 L_65 , V_9 -> V_16 ) ;
break;
}
F_22 ( V_9 , V_91 , F_21 ( V_9 , V_91 ) | V_219 | V_193 ) ;
V_46 -> V_221 = 0 ;
F_22 ( V_9 , V_222 , V_223 ) ;
V_46 -> V_137 = V_224 | V_225 ;
if ( V_46 -> V_105 & V_226 )
V_46 -> V_137 |= V_227 ;
#if V_54
F_42 ( V_9 ) ;
#endif
F_22 ( V_9 , V_228 , V_46 -> V_137 ) ;
F_22 ( V_9 , V_229 , V_230 | V_231 | V_232 |
V_233 | V_234 | V_235 | V_236 ) ;
F_22 ( V_9 , V_237 , V_238 | V_239 |
#if V_54
F_43 ( V_9 ) |
#endif
V_240 | V_241 ) ;
F_22 ( V_9 , V_208 , V_209
| ( V_9 -> V_113 ? V_145 : 0 )
#if V_54
| F_44 ( V_9 )
#endif
) ;
F_78 ( V_9 ) ;
if ( V_18 > 1 )
F_8 ( L_66 ) ;
return 0 ;
V_211:
return V_207 ;
}
static void F_79 ( struct V_7 * V_9 )
{
if ( V_18 > 0 ) F_8 ( L_67 , V_9 -> V_16 ,
F_80 ( V_9 ) ? L_68 : L_69 ) ;
F_81 ( V_9 ) ;
}
static T_4 F_82 ( struct V_146 * V_147 , struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
unsigned long V_212 ;
if ( V_18 > 3 ) {
F_8 ( L_70 ,
V_9 -> V_16 , V_147 -> V_37 ,
( V_147 -> V_158 [ V_86 + V_86 ] << 8 ) | V_147 -> V_158 [ V_86 + V_86 + 1 ] ) ;
}
F_67 ( & V_46 -> V_53 , V_212 ) ;
F_83 ( V_9 ) ;
F_13 ( V_9 -> V_17 , V_194 , V_46 -> V_78 ) ;
F_13 ( V_9 -> V_17 , V_196 , V_147 -> V_37 ) ;
if ( ( F_21 ( V_9 , V_198 ) & V_199 ) == 0 ) {
F_74 ( & V_46 -> V_53 , V_212 ) ;
if ( V_18 ) F_8 ( L_71 ) ;
return V_242 ;
}
F_20 ( V_9 -> V_17 , V_200 , V_147 -> V_158 , ( V_147 -> V_37 + 1 ) >> 1 ) ;
F_74 ( & V_46 -> V_53 , V_212 ) ;
V_9 -> V_153 . V_243 += V_147 -> V_37 ;
F_84 ( V_147 ) ;
return V_244 ;
}
static T_5 F_28 ( int V_13 , void * V_245 )
{
struct V_7 * V_9 = V_245 ;
struct V_10 * V_46 ;
int V_44 , V_148 ;
int V_246 = 0 ;
V_44 = V_9 -> V_17 ;
V_46 = F_30 ( V_9 ) ;
while ( ( V_148 = F_11 ( V_9 -> V_17 , V_247 ) ) ) {
if ( V_18 > 4 ) F_8 ( L_72 , V_9 -> V_16 , V_148 ) ;
V_246 = 1 ;
switch( V_148 & V_248 ) {
case V_249 :
F_85 ( V_9 ) ;
break;
case V_250 :
V_9 -> V_153 . V_251 ++ ;
F_81 ( V_9 ) ;
if ( ( V_148 & ( V_203 |
V_252 |
V_253 |
V_254 |
V_255 ) ) != V_203 ) {
if ( ( V_148 & V_203 ) == 0 )
V_9 -> V_153 . V_256 ++ ;
if ( V_148 & V_252 )
V_9 -> V_153 . V_257 ++ ;
if ( V_148 & V_253 )
V_9 -> V_153 . V_258 ++ ;
if ( V_148 & V_254 )
V_9 -> V_153 . V_259 ++ ;
if ( V_148 & V_255 )
V_9 -> V_153 . V_260 ++ ;
}
break;
case V_261 :
if ( V_148 & V_262 ) {
F_81 ( V_9 ) ;
}
if ( V_148 & V_263 ) {
if ( V_18 > 0 ) F_8 ( L_73 , V_9 -> V_16 ) ;
V_46 -> V_264 ++ ;
if ( V_46 -> V_264 == 3 ) V_46 -> V_78 = V_79 ;
else if ( V_46 -> V_264 == 6 ) V_46 -> V_78 = V_195 ;
F_81 ( V_9 ) ;
}
#if V_54
if ( V_46 -> V_55 && ( V_148 & V_265 ) ) {
int V_115 = F_21 ( V_9 , V_266 ) ;
while( V_115 ) {
if ( V_18 > 5 )
F_8 ( L_74 , V_9 -> V_16 , V_115 ) ;
if ( V_18 > 2 && V_115 > 1 )
F_8 ( L_74 , V_9 -> V_16 , V_115 ) ;
F_45 ( V_9 ) ;
if ( -- V_115 == 0 )
V_115 = F_21 ( V_9 , V_266 ) ;
if ( V_18 > 2 && V_115 > 0 )
F_8 ( L_75 , V_9 -> V_16 , V_115 ) ;
}
}
#endif
break;
case V_267 :
V_9 -> V_153 . V_268 += ( V_148 >> 6 ) ;
break;
case V_269 :
V_9 -> V_153 . V_270 += ( V_148 >> 6 ) ;
break;
}
}
return F_86 ( V_246 ) ;
}
static void
F_46 ( int V_148 , struct V_7 * V_9 )
{
V_9 -> V_153 . V_271 ++ ;
if ( V_148 & V_272 )
V_9 -> V_153 . V_273 ++ ;
if ( V_148 & V_274 )
V_9 -> V_153 . V_273 ++ ;
if ( ( V_148 & V_275 ) && ! ( V_148 & ( V_274 | V_272 ) ) )
V_9 -> V_153 . V_276 ++ ;
if ( V_148 & V_277 )
V_9 -> V_153 . V_278 ++ ;
}
static void
F_85 ( struct V_7 * V_9 )
{
struct V_146 * V_147 ;
int V_148 , V_26 ;
int V_44 = V_9 -> V_17 ;
V_148 = F_11 ( V_44 , V_279 ) ;
V_26 = F_11 ( V_44 , V_279 ) ;
if ( ( V_148 & V_151 ) == 0 ) {
F_46 ( V_148 , V_9 ) ;
return;
}
V_147 = F_47 ( V_26 + 2 ) ;
if ( V_147 == NULL ) {
#if 0
printk(KERN_WARNING "%s: Memory squeeze, dropping packet.\n", dev->name);
#endif
V_9 -> V_153 . V_154 ++ ;
return;
}
F_48 ( V_147 , 2 ) ;
F_19 ( V_44 , V_279 , F_49 ( V_147 , V_26 ) , V_26 >> 1 ) ;
if ( V_26 & 1 )
V_147 -> V_158 [ V_26 - 1 ] = F_11 ( V_44 , V_279 ) ;
if ( V_18 > 3 ) {
F_8 ( L_76 ,
V_9 -> V_16 , V_26 ,
( V_147 -> V_158 [ V_86 + V_86 ] << 8 ) | V_147 -> V_158 [ V_86 + V_86 + 1 ] ) ;
}
V_147 -> V_159 = F_50 ( V_147 , V_9 ) ;
F_51 ( V_147 ) ;
V_9 -> V_153 . V_160 ++ ;
V_9 -> V_153 . V_161 += V_26 ;
}
static void F_76 ( struct V_10 * V_46 )
{
if ( V_46 -> V_157 ) {
F_87 ( ( unsigned long ) ( V_46 -> V_157 ) , F_63 ( V_46 -> V_57 * 1024 ) ) ;
V_46 -> V_157 = NULL ;
}
}
static int
F_88 ( struct V_7 * V_9 )
{
#if V_54
struct V_10 * V_46 = F_30 ( V_9 ) ;
#endif
F_83 ( V_9 ) ;
F_22 ( V_9 , V_228 , 0 ) ;
F_22 ( V_9 , V_229 , 0 ) ;
F_22 ( V_9 , V_237 , 0 ) ;
F_22 ( V_9 , V_208 , 0 ) ;
F_77 ( V_9 -> V_13 , V_9 ) ;
#if V_54
if ( V_46 -> V_55 && V_46 -> V_56 ) {
F_75 ( V_9 -> V_56 ) ;
F_76 ( V_46 ) ;
}
#endif
return 0 ;
}
static struct V_280 *
F_89 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
unsigned long V_212 ;
F_67 ( & V_46 -> V_53 , V_212 ) ;
V_9 -> V_153 . V_268 += ( F_21 ( V_9 , V_281 ) >> 6 ) ;
V_9 -> V_153 . V_270 += ( F_21 ( V_9 , V_282 ) >> 6 ) ;
F_74 ( & V_46 -> V_53 , V_212 ) ;
return & V_9 -> V_153 ;
}
static void F_90 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
unsigned long V_212 ;
F_67 ( & V_46 -> V_53 , V_212 ) ;
if( V_9 -> V_212 & V_283 )
{
V_46 -> V_221 = V_284 ;
}
else if ( ( V_9 -> V_212 & V_285 ) || ! F_91 ( V_9 ) )
{
V_46 -> V_221 = V_286 ;
}
else
V_46 -> V_221 = 0 ;
F_22 ( V_9 , V_222 , V_223 | V_46 -> V_221 ) ;
F_22 ( V_9 , V_228 , V_46 -> V_137 |
( V_46 -> V_221 == V_284 ? ( V_225 | V_287 | V_288 ) : 0 ) ) ;
F_74 ( & V_46 -> V_53 , V_212 ) ;
}
static int F_92 ( struct V_7 * V_9 , void * V_289 )
{
int V_39 ;
struct V_290 * V_291 = V_289 ;
if ( F_93 ( V_9 ) )
return - V_64 ;
memcpy ( V_9 -> V_89 , V_291 -> V_292 , V_9 -> V_293 ) ;
if ( V_18 )
F_8 ( L_77 ,
V_9 -> V_16 , V_9 -> V_89 ) ;
for ( V_39 = 0 ; V_39 < V_86 / 2 ; V_39 ++ )
F_22 ( V_9 , V_88 + V_39 * 2 , V_9 -> V_89 [ V_39 * 2 ] | ( V_9 -> V_89 [ V_39 * 2 + 1 ] << 8 ) ) ;
return 0 ;
}
int T_1 F_94 ( void )
{
struct V_7 * V_9 = F_5 ( sizeof( struct V_10 ) ) ;
struct V_10 * V_46 ;
int V_207 = 0 ;
#if V_294
V_18 = V_295 ;
#else
V_295 = 0 ;
#endif
if ( ! V_9 )
return - V_296 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_17 = V_14 ;
V_46 = F_30 ( V_9 ) ;
#if V_54
if ( V_55 ) {
V_46 -> V_55 = V_55 ;
V_46 -> V_56 = V_56 ;
V_46 -> V_57 = V_57 ;
}
#endif
F_31 ( & V_46 -> V_53 ) ;
if ( ! strcmp ( V_297 , L_1 ) )
V_46 -> V_90 = V_101 | V_100 ;
else if ( ! strcmp ( V_297 , L_2 ) )
V_46 -> V_90 = V_103 | V_102 ;
else if ( ! strcmp ( V_297 , L_3 ) )
V_46 -> V_90 = V_117 | V_116 ;
else
V_46 -> V_90 = V_101 | V_100 ;
if ( V_298 == - 1 )
V_46 -> V_109 = V_181 ;
if ( V_14 == 0 ) {
F_8 ( V_63 L_78 ) ;
F_8 ( V_63 L_79 ) ;
V_207 = - V_299 ;
goto V_21;
} else if ( V_14 <= 0x1ff ) {
V_207 = - V_19 ;
goto V_21;
}
#if V_54
if ( V_55 && V_57 != 16 && V_57 != 64 ) {
F_8 ( V_63 L_80 , V_57 ) ;
V_207 = - V_299 ;
goto V_21;
}
#endif
V_207 = F_9 ( V_9 , V_14 , 1 ) ;
if ( V_207 )
goto V_21;
V_300 = V_9 ;
return 0 ;
V_21:
F_10 ( V_9 ) ;
return V_207 ;
}
void T_6
F_95 ( void )
{
F_96 ( V_300 ) ;
F_13 ( V_300 -> V_17 , V_30 , V_71 ) ;
F_40 ( V_300 -> V_17 , V_61 ) ;
F_10 ( V_300 ) ;
}
