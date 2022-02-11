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
F_9 ( struct V_7 * V_9 , unsigned long V_44 , int V_45 )
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
}
if ( ! F_33 ( V_44 & ~ 3 , V_59 , V_60 ) ) {
F_8 ( V_61 L_10 ,
V_60 , V_44 , V_59 ) ;
V_52 = - V_62 ;
goto V_63;
}
if ( V_44 & 1 ) {
if ( V_18 > 1 )
F_8 ( V_64 L_11 , V_9 -> V_16 , V_44 ) ;
if ( ( V_44 & 2 ) != 2 )
if ( ( F_11 ( V_44 & ~ 3 , V_30 ) & V_65 ) != V_66 ) {
F_8 ( V_61 L_12 ,
V_9 -> V_16 , F_11 ( V_44 & ~ 3 , V_30 ) ) ;
V_52 = - V_15 ;
goto V_67;
}
}
V_44 &= ~ 3 ;
F_8 ( V_68 L_13 ,
V_44 , V_30 , F_11 ( V_44 , V_30 ) ) ;
F_13 ( V_44 , V_30 , V_69 ) ;
V_48 = F_11 ( V_44 , V_31 ) ;
if ( V_48 != V_70 ) {
F_8 ( V_68 L_14
V_71 L_9 ,
V_9 -> V_16 , V_44 , V_31 , V_48 ) ;
V_52 = - V_15 ;
goto V_67;
}
V_9 -> V_17 = V_44 ;
V_49 = F_21 ( V_9 , V_72 ) ;
V_46 -> V_73 = V_49 & ~ V_74 ;
V_46 -> V_75 = ( ( V_49 & V_74 ) >> 8 ) + 'A' ;
V_46 -> V_76 = V_77 ;
if ( V_46 -> V_73 == V_78 && V_46 -> V_75 >= 'F' )
V_46 -> V_76 = V_79 ;
if ( V_46 -> V_73 != V_78 && V_46 -> V_75 >= 'C' )
V_46 -> V_76 = V_79 ;
if ( V_18 && V_47 ++ == 0 )
F_8 ( V_80 ) ;
F_8 ( V_64 L_15 ,
V_9 -> V_16 ,
V_46 -> V_73 == V_78 ? '0' : '2' ,
V_46 -> V_73 == V_81 ? L_16 : L_17 ,
V_46 -> V_75 ,
V_9 -> V_17 ) ;
F_34 ( V_9 ) ;
if ( ( F_21 ( V_9 , V_34 ) & ( V_82 | V_83 ) ) ==
( V_82 | V_83 ) ) {
for ( V_39 = 0 ; V_39 < V_84 / 2 ; V_39 ++ ) {
unsigned int V_85 ;
V_85 = F_21 ( V_9 , V_86 + V_39 * 2 ) ;
V_9 -> V_87 [ V_39 * 2 ] = V_85 & 0xFF ;
V_9 -> V_87 [ V_39 * 2 + 1 ] = V_85 >> 8 ;
}
V_46 -> V_88 = 0 ;
V_39 = F_21 ( V_9 , V_89 ) ;
if ( ( V_39 & ( V_90 | V_91 ) ) == ( V_90 | V_91 ) )
V_46 -> V_88 |= V_92 ;
if ( ( V_39 & V_93 ) == V_93 )
V_46 -> V_88 |= V_94 | V_95 ;
if ( ( V_39 & ( V_96 | V_97 ) ) == 0 )
V_46 -> V_88 |= V_98 | V_99 ;
if ( ( V_39 & ( V_96 | V_97 ) ) == V_96 )
V_46 -> V_88 |= V_100 | V_101 ;
if ( ( V_39 & ( V_96 | V_97 ) ) == V_97 )
V_46 -> V_88 |= V_100 | V_98 |
V_101 | V_99 | V_102 ;
if ( V_18 > 1 )
F_8 ( V_64 L_18 ,
V_9 -> V_16 , V_39 , V_46 -> V_88 ) ;
if ( V_46 -> V_73 == V_78 )
V_46 -> V_103 = F_21 ( V_9 , V_104 ) & V_105 ;
F_8 ( L_19 ) ;
}
F_8 ( L_9 ) ;
if ( ( F_21 ( V_9 , V_34 ) & V_83 ) == 0 )
F_8 ( V_22 L_20 ) ;
else if ( F_24 ( V_9 , V_106 , V_51 , V_50 ) < 0 ) {
F_8 ( V_22 L_21 ) ;
} else if ( F_25 ( V_106 , V_51 , V_50 ) < 0 ) {
if ( ( F_21 ( V_9 , V_34 ) & ( V_82 | V_83 ) ) !=
( V_82 | V_83 ) )
F_8 ( V_22 L_22 ) ;
} else {
if ( ! V_46 -> V_107 ) V_46 -> V_107 = V_50 [ V_108 / 2 ] ;
if ( ! V_46 -> V_88 ) V_46 -> V_88 = V_50 [ V_109 / 2 ] ;
V_46 -> V_103 = V_50 [ V_110 / 2 ] ;
V_9 -> V_111 = V_50 [ V_112 / 2 ] << 8 ;
for ( V_39 = 0 ; V_39 < V_84 / 2 ; V_39 ++ ) {
V_9 -> V_87 [ V_39 * 2 ] = V_50 [ V_39 ] ;
V_9 -> V_87 [ V_39 * 2 + 1 ] = V_50 [ V_39 ] >> 8 ;
}
if ( V_18 > 1 )
F_8 ( V_68 L_23 ,
V_9 -> V_16 , V_46 -> V_88 ) ;
}
{
int V_113 = 0 ;
if ( V_46 -> V_58 & V_4 ) { V_46 -> V_88 |= V_98 ; V_113 ++ ; }
if ( V_46 -> V_58 & V_5 ) { V_46 -> V_88 |= V_100 ; V_113 ++ ; }
if ( V_46 -> V_58 & V_6 ) { V_46 -> V_88 |= V_114 ; V_113 ++ ; }
if ( V_113 > 1 ) { V_46 -> V_88 |= V_102 ; }
else if ( V_46 -> V_58 & V_4 ) { V_46 -> V_88 |= V_99 ; }
else if ( V_46 -> V_58 & V_5 ) { V_46 -> V_88 |= V_101 ; }
else if ( V_46 -> V_58 & V_6 ) { V_46 -> V_88 |= V_115 ; }
}
if ( V_18 > 1 )
F_8 ( V_68 L_24 ,
V_9 -> V_16 , V_46 -> V_58 , V_46 -> V_88 ) ;
F_8 ( V_64 L_25 ,
( V_46 -> V_88 & V_98 ) ? L_26 : L_17 ,
( V_46 -> V_88 & V_100 ) ? L_27 : L_17 ,
( V_46 -> V_88 & V_114 ) ? L_28 : L_17 ) ;
V_46 -> V_116 = 0xffff ;
if ( V_46 -> V_73 != V_78 &&
( V_39 = F_21 ( V_9 , V_117 ) & 0xff ,
( V_39 != 0 && V_39 < V_118 ) ) ) {
if ( ! V_9 -> V_13 )
V_9 -> V_13 = V_39 ;
} else {
V_39 = V_46 -> V_103 & V_105 ;
#ifndef F_35
if ( V_46 -> V_73 == V_78 ) {
#ifdef F_36
V_39 = V_119 [ 0 ] ;
#else
if ( V_39 >= F_37 ( V_119 ) )
F_8 ( L_29 , V_39 ) ;
else
V_39 = V_119 [ V_39 ] ;
V_46 -> V_116 = V_120 ;
} else {
int V_121 [ V_122 / 2 ] ;
if ( F_24 ( V_9 , V_123 ,
V_122 / 2 ,
V_121 ) >= 0 ) {
if ( ( V_121 [ 0 ] & 0xff ) == V_124 )
V_46 -> V_116 = ( V_121 [ 0 ] >> 8 ) | ( V_121 [ 1 ] << 8 ) ;
}
#endif
}
#endif
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
F_8 ( L_33 , V_9 -> V_87 ) ;
V_9 -> V_125 = & V_126 ;
V_9 -> V_127 = V_128 ;
F_8 ( L_9 ) ;
if ( V_18 )
F_8 ( L_34 ) ;
V_52 = F_39 ( V_9 ) ;
if ( V_52 )
goto V_129;
return 0 ;
V_129:
F_13 ( V_9 -> V_17 , V_30 , V_69 ) ;
V_67:
F_40 ( V_44 & ~ 3 , V_59 ) ;
V_63:
return V_52 ;
}
static void
F_38 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
if ( V_46 -> V_56 ) {
V_9 -> V_56 = V_46 -> V_56 ;
V_46 -> V_103 |= V_130 ;
} else {
if ( ( V_46 -> V_103 & V_131 ) == 0 )
return;
V_9 -> V_56 = V_46 -> V_103 & V_132 ;
if ( V_46 -> V_73 == V_78 )
V_9 -> V_56 += 5 ;
if ( V_9 -> V_56 < 5 || V_9 -> V_56 > 7 ) {
V_46 -> V_103 &= ~ V_131 ;
return;
}
}
}
static void
F_41 ( struct V_7 * V_9 , int V_73 , int V_56 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
if ( ( V_46 -> V_103 & V_131 ) == 0 )
return;
if ( V_73 == V_78 ) {
F_22 ( V_9 , V_133 , V_56 - 5 ) ;
} else {
F_22 ( V_9 , V_134 , V_56 ) ;
}
}
static void
F_42 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
if ( V_46 -> V_55 ) {
if ( ( V_46 -> V_103 & V_131 ) == 0 ) {
if ( V_18 > 3 )
F_8 ( L_35 ) ;
return;
}
if ( V_46 -> V_103 & V_130 ) {
V_46 -> V_135 |= V_136 ;
if ( V_18 > 3 )
F_8 ( L_36 ) ;
} else {
V_46 -> V_135 |= V_137 ;
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
return ( V_46 -> V_103 & V_131 ) ? V_138 : 0 ;
else
return 0 ;
}
static int
F_44 ( struct V_7 * V_9 )
{
int V_52 = 0 ;
struct V_10 * V_46 = F_30 ( V_9 ) ;
if ( V_46 -> V_55 ) {
if ( V_46 -> V_103 & V_131 )
V_52 |= V_139 ;
if ( V_46 -> V_103 & V_140 )
V_52 |= V_141 ;
if ( V_46 -> V_57 == 64 )
V_52 |= V_142 ;
V_52 |= V_143 ;
}
return V_52 ;
}
static void
F_45 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
struct V_144 * V_145 ;
int V_146 , V_26 ;
unsigned char * V_147 = V_46 -> V_148 ;
V_146 = V_147 [ 0 ] + ( V_147 [ 1 ] << 8 ) ;
V_26 = V_147 [ 2 ] + ( V_147 [ 3 ] << 8 ) ;
V_147 += 4 ;
if ( V_18 > 5 ) {
F_8 ( L_38 ,
V_9 -> V_16 , ( unsigned long ) V_147 , V_146 , V_26 ) ;
}
if ( ( V_146 & V_149 ) == 0 ) {
F_46 ( V_146 , V_9 ) ;
goto V_150;
}
V_145 = F_47 ( V_9 , V_26 + 2 ) ;
if ( V_145 == NULL ) {
if ( V_18 )
F_8 ( L_39 , V_9 -> V_16 ) ;
V_9 -> V_151 . V_152 ++ ;
V_150:
V_147 += ( V_26 + 3 ) & ~ 3 ;
if ( V_147 >= V_46 -> V_153 ) V_147 -= V_46 -> V_57 * 1024 ;
V_46 -> V_148 = V_147 ;
return;
}
F_48 ( V_145 , 2 ) ;
if ( V_147 + V_26 > V_46 -> V_153 ) {
int V_154 = V_46 -> V_153 - V_147 ;
memcpy ( F_49 ( V_145 , V_154 ) , V_147 , V_154 ) ;
memcpy ( F_49 ( V_145 , V_26 - V_154 ) , V_46 -> V_155 ,
V_26 - V_154 ) ;
} else {
memcpy ( F_49 ( V_145 , V_26 ) , V_147 , V_26 ) ;
}
V_147 += ( V_26 + 3 ) & ~ 3 ;
if ( V_147 >= V_46 -> V_153 ) V_147 -= V_46 -> V_57 * 1024 ;
V_46 -> V_148 = V_147 ;
if ( V_18 > 3 ) {
F_8 ( L_40 ,
V_9 -> V_16 , V_26 ,
( V_145 -> V_156 [ V_84 + V_84 ] << 8 ) | V_145 -> V_156 [ V_84 + V_84 + 1 ] ) ;
}
V_145 -> V_157 = F_50 ( V_145 , V_9 ) ;
F_51 ( V_145 ) ;
V_9 -> V_151 . V_158 ++ ;
V_9 -> V_151 . V_159 += V_26 ;
}
static void T_1 F_34 ( struct V_7 * V_9 )
{
#if ! F_52 ( V_160 )
#if ! F_52 ( F_36 )
struct V_10 * V_46 = F_30 ( V_9 ) ;
int V_44 = V_9 -> V_17 ;
#endif
int V_161 ;
F_22 ( V_9 , V_162 , F_21 ( V_9 , V_162 ) | V_163 ) ;
F_53 ( 30 ) ;
#if ! F_52 ( F_36 )
if ( V_46 -> V_73 != V_78 ) {
F_13 ( V_44 , V_30 , V_117 ) ;
F_54 ( V_9 -> V_13 , V_44 + V_31 ) ;
F_54 ( 0 , V_44 + V_31 + 1 ) ;
F_13 ( V_44 , V_30 , V_164 ) ;
F_54 ( ( V_9 -> V_111 >> 16 ) & 0xff , V_44 + V_31 ) ;
F_54 ( ( V_9 -> V_111 >> 8 ) & 0xff , V_44 + V_31 + 1 ) ;
}
#endif
V_161 = V_33 ;
while( ( F_21 ( V_9 , V_34 ) & V_165 ) == 0 && V_33 - V_161 < 2 )
;
#endif
}
static void
F_55 ( struct V_7 * V_9 , int V_166 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
unsigned int V_167 ;
int V_168 = V_33 ;
V_167 = V_91 ;
if ( ( ( V_46 -> V_88 & V_92 ) != 0 ) ^ V_166 )
V_167 |= V_90 ;
else
V_167 &= ~ V_90 ;
F_22 ( V_9 , V_162 , V_167 ) ;
while ( V_33 - V_168 < V_128 )
;
}
static int
F_56 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
int V_168 = V_33 ;
int V_169 ;
if ( V_18 > 1 ) F_8 ( L_41 , V_9 -> V_16 ) ;
F_22 ( V_9 , V_89 , V_46 -> V_170 & ~ V_96 ) ;
F_55 ( V_9 , 0 ) ;
for ( V_168 = V_33 ; V_33 - V_168 < 15 ; )
;
if ( ( F_21 ( V_9 , V_171 ) & V_172 ) == 0 )
return V_173 ;
if ( V_46 -> V_73 == V_78 ) {
switch ( V_46 -> V_58 & 0xf0 ) {
#if 0
case FORCE_AUTO:
printk("%s: cs8900 doesn't autonegotiate\n",dev->name);
return DETECTED_NONE;
#endif
case V_174 :
V_46 -> V_58 &= ~ V_174 ;
V_46 -> V_58 |= V_175 ;
break;
case V_175 :
break;
case V_176 :
F_22 ( V_9 , V_177 , F_21 ( V_9 , V_177 ) | V_178 ) ;
break;
}
V_169 = F_21 ( V_9 , V_177 ) & V_178 ;
} else {
switch ( V_46 -> V_58 & 0xf0 ) {
case V_174 :
V_46 -> V_107 = V_179 ;
break;
case V_175 :
V_46 -> V_107 = 0 ;
break;
case V_176 :
V_46 -> V_107 = V_180 | V_181 ;
break;
}
F_22 ( V_9 , V_182 , V_46 -> V_107 & V_183 ) ;
if ( ( V_46 -> V_107 & V_184 ) == V_179 ) {
F_8 ( V_64 L_42 , V_9 -> V_16 ) ;
while ( F_21 ( V_9 , V_185 ) & V_186 ) {
if ( V_33 - V_168 > 4000 ) {
F_8 ( V_61 L_43 ) ;
break;
}
}
}
V_169 = F_21 ( V_9 , V_185 ) & V_187 ;
}
if ( V_169 )
return V_188 ;
else
return V_189 ;
}
static int
F_57 ( struct V_7 * V_9 )
{
char V_190 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 46 ,
0 , 0 ,
0xf3 , 0 } ;
long V_168 = V_33 ;
F_22 ( V_9 , V_89 , F_21 ( V_9 , V_89 ) | V_191 ) ;
memcpy ( V_190 , V_9 -> V_87 , V_84 ) ;
memcpy ( V_190 + V_84 , V_9 -> V_87 , V_84 ) ;
F_13 ( V_9 -> V_17 , V_192 , V_193 ) ;
F_13 ( V_9 -> V_17 , V_194 , V_195 ) ;
while ( V_33 - V_168 < 5 )
if ( F_21 ( V_9 , V_196 ) & V_197 )
break;
if ( V_33 - V_168 >= 5 )
return 0 ;
F_20 ( V_9 -> V_17 , V_198 , V_190 , ( V_195 + 1 ) >> 1 ) ;
if ( V_18 > 1 ) F_8 ( L_44 ) ;
for ( V_168 = V_33 ; V_33 - V_168 < 3 ; )
;
if ( ( F_21 ( V_9 , V_199 ) & V_200 ) == V_201 ) {
if ( V_18 > 1 ) F_8 ( L_45 ) ;
return 1 ;
}
if ( V_18 > 1 ) F_8 ( L_46 ) ;
return 0 ;
}
static int
F_58 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
if ( V_18 > 1 ) F_8 ( L_47 , V_9 -> V_16 ) ;
F_55 ( V_9 , 0 ) ;
F_22 ( V_9 , V_89 , ( V_46 -> V_170 & ~ V_97 ) | V_96 ) ;
if ( F_57 ( V_9 ) )
return V_202 ;
else
return V_173 ;
}
static int
F_59 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
if ( V_18 > 1 ) F_8 ( L_48 , V_9 -> V_16 ) ;
F_55 ( V_9 , 1 ) ;
F_22 ( V_9 , V_89 , ( V_46 -> V_170 & ~ V_97 ) | V_96 ) ;
if ( F_57 ( V_9 ) )
return V_203 ;
else
return V_173 ;
}
static void
F_60 ( struct V_7 * V_9 , int V_73 , int V_13 )
{
int V_39 ;
if ( V_73 == V_78 ) {
#ifndef F_35
for ( V_39 = 0 ; V_39 != F_37 ( V_119 ) ; V_39 ++ )
if ( V_119 [ V_39 ] == V_13 )
break;
if ( V_39 == F_37 ( V_119 ) )
V_39 = 3 ;
#else
V_39 = 0 ;
#endif
F_22 ( V_9 , V_104 , V_39 ) ;
} else {
F_22 ( V_9 , V_117 , V_13 ) ;
}
}
static int
F_61 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
int V_204 = 0 ;
int V_39 ;
int V_205 ;
if ( V_9 -> V_13 < 2 ) {
#if 0
writereg(dev, PP_BusCTL, readreg(dev, PP_BusCTL)|ENABLE_IRQ );
#endif
F_22 ( V_9 , V_206 , V_207 | V_143 ) ;
for ( V_39 = 2 ; V_39 < V_118 ; V_39 ++ ) {
if ( ( 1 << V_39 ) & V_46 -> V_116 ) {
if ( F_62 ( V_39 , F_28 , 0 , V_9 -> V_16 , V_9 ) == 0 ) {
V_9 -> V_13 = V_39 ;
F_60 ( V_9 , V_46 -> V_73 , V_39 ) ;
break;
}
}
}
if ( V_39 >= V_118 ) {
F_22 ( V_9 , V_206 , 0 ) ;
F_8 ( V_61 L_49 ) ;
V_205 = - V_208 ;
goto V_209;
}
}
else
{
#if ! F_52 ( F_36 ) && ! F_52 ( F_35 )
if ( ( ( 1 << V_9 -> V_13 ) & V_46 -> V_116 ) == 0 ) {
F_8 ( V_61 L_50 ,
V_9 -> V_16 , V_9 -> V_13 , V_46 -> V_116 ) ;
V_205 = - V_208 ;
goto V_209;
}
#endif
F_22 ( V_9 , V_206 , F_21 ( V_9 , V_206 ) | V_207 ) ;
#if 0
writereg(dev, PP_BusCTL, ENABLE_IRQ | MEMORY_ON);
#endif
F_60 ( V_9 , V_46 -> V_73 , V_9 -> V_13 ) ;
V_205 = F_62 ( V_9 -> V_13 , F_28 , 0 , V_9 -> V_16 , V_9 ) ;
if ( V_205 ) {
F_8 ( V_61 L_51 , V_9 -> V_13 ) ;
goto V_209;
}
}
#if V_54
if ( V_46 -> V_55 ) {
if ( V_46 -> V_103 & V_131 ) {
unsigned long V_210 ;
V_46 -> V_155 = ( unsigned char * ) F_63 ( V_211 ,
F_64 ( V_46 -> V_57 * 1024 ) ) ;
if ( ! V_46 -> V_155 ) {
F_8 ( V_61 L_52 , V_9 -> V_16 , V_46 -> V_57 ) ;
goto V_212;
}
if ( V_18 > 1 ) {
F_8 ( L_53 ,
V_9 -> V_16 ,
( unsigned long ) V_46 -> V_155 ,
( unsigned long ) F_65 ( V_46 -> V_155 ) ) ;
}
if ( ( unsigned long ) V_46 -> V_155 >= V_213 ||
! F_66 ( V_46 -> V_155 , V_46 -> V_155 + V_46 -> V_57 * 1024 - 1 ) ) {
F_8 ( V_61 L_54 , V_9 -> V_16 ) ;
goto V_212;
}
memset ( V_46 -> V_155 , 0 , V_46 -> V_57 * 1024 ) ;
if ( F_67 ( V_9 -> V_56 , V_9 -> V_16 ) ) {
F_8 ( V_61 L_55 , V_9 -> V_16 , V_9 -> V_56 ) ;
goto V_212;
}
F_41 ( V_9 , V_46 -> V_73 , V_9 -> V_56 ) ;
V_46 -> V_148 = V_46 -> V_155 ;
V_46 -> V_153 = V_46 -> V_155 + V_46 -> V_57 * 1024 ;
F_68 ( & V_46 -> V_53 , V_210 ) ;
F_69 ( V_9 -> V_56 ) ;
F_70 ( V_9 -> V_56 ) ;
F_71 ( V_9 -> V_56 , V_214 ) ;
F_72 ( V_9 -> V_56 , F_65 ( V_46 -> V_155 ) ) ;
F_73 ( V_9 -> V_56 , V_46 -> V_57 * 1024 ) ;
F_74 ( V_9 -> V_56 ) ;
F_75 ( & V_46 -> V_53 , V_210 ) ;
}
}
#endif
for ( V_39 = 0 ; V_39 < V_84 / 2 ; V_39 ++ )
F_22 ( V_9 , V_86 + V_39 * 2 , V_9 -> V_87 [ V_39 * 2 ] | ( V_9 -> V_87 [ V_39 * 2 + 1 ] << 8 ) ) ;
F_22 ( V_9 , V_206 , V_143 ) ;
if ( ( V_46 -> V_88 & V_94 ) && ( V_46 -> V_88 & V_95 ) )
V_46 -> V_170 = V_93 ;
else
V_46 -> V_170 = 0 ;
switch( V_46 -> V_88 & V_215 ) {
case V_99 : V_204 = V_46 -> V_88 & V_98 ; break;
case V_101 : V_204 = V_46 -> V_88 & V_100 ; break;
case V_115 : V_204 = V_46 -> V_88 & V_114 ; break;
default: V_204 = V_46 -> V_88 & ( V_98 | V_100 | V_114 ) ;
}
if ( ! V_204 ) {
F_8 ( V_61 L_56 , V_9 -> V_16 ) ;
V_216:
#if V_54
F_76 ( V_9 -> V_56 ) ;
V_212:
F_77 ( V_46 ) ;
#endif
F_22 ( V_9 , V_89 , F_21 ( V_9 , V_89 ) & ~ ( V_191 | V_217 ) ) ;
F_78 ( V_9 -> V_13 , V_9 ) ;
V_205 = - V_208 ;
goto V_209;
}
switch( V_46 -> V_88 & V_215 ) {
case V_99 :
V_204 = F_56 ( V_9 ) ;
if ( V_204 == V_173 ) {
F_8 ( V_22 L_57 , V_9 -> V_16 ) ;
if ( V_46 -> V_107 & V_218 )
V_204 = V_189 ;
}
break;
case V_101 :
V_204 = F_58 ( V_9 ) ;
if ( V_204 == V_173 ) {
F_8 ( V_22 L_58 , V_9 -> V_16 ) ;
if ( V_46 -> V_107 & V_218 )
V_204 = V_202 ;
}
break;
case V_115 :
V_204 = F_59 ( V_9 ) ;
if ( V_204 == V_173 ) {
F_8 ( V_22 L_59 , V_9 -> V_16 ) ;
if ( V_46 -> V_107 & V_218 )
V_204 = V_203 ;
}
break;
case V_102 :
F_22 ( V_9 , V_89 , V_46 -> V_170 | V_97 ) ;
if ( V_46 -> V_88 & V_98 )
if ( ( V_204 = F_56 ( V_9 ) ) != V_173 )
break;
if ( V_46 -> V_88 & V_100 )
if ( ( V_204 = F_58 ( V_9 ) ) != V_173 )
break;
if ( V_46 -> V_88 & V_114 )
if ( ( V_204 = F_59 ( V_9 ) ) != V_173 )
break;
F_8 ( V_61 L_60 , V_9 -> V_16 ) ;
goto V_216;
}
switch( V_204 ) {
case V_173 :
F_8 ( V_61 L_61 , V_9 -> V_16 ) ;
goto V_216;
case V_189 :
F_8 ( V_64 L_62 , V_9 -> V_16 ) ;
break;
case V_188 :
F_8 ( V_64 L_63 , V_9 -> V_16 ) ;
break;
case V_202 :
F_8 ( V_64 L_64 , V_9 -> V_16 ) ;
break;
case V_203 :
F_8 ( V_64 L_65 , V_9 -> V_16 ) ;
break;
}
F_22 ( V_9 , V_89 , F_21 ( V_9 , V_89 ) | V_217 | V_191 ) ;
V_46 -> V_219 = 0 ;
F_22 ( V_9 , V_220 , V_221 ) ;
V_46 -> V_135 = V_222 | V_223 ;
if ( V_46 -> V_103 & V_224 )
V_46 -> V_135 |= V_225 ;
#if V_54
F_42 ( V_9 ) ;
#endif
F_22 ( V_9 , V_226 , V_46 -> V_135 ) ;
F_22 ( V_9 , V_227 , V_228 | V_229 | V_230 |
V_231 | V_232 | V_233 | V_234 ) ;
F_22 ( V_9 , V_235 , V_236 | V_237 |
#if V_54
F_43 ( V_9 ) |
#endif
V_238 | V_239 ) ;
F_22 ( V_9 , V_206 , V_207
| ( V_9 -> V_111 ? V_143 : 0 )
#if V_54
| F_44 ( V_9 )
#endif
) ;
F_79 ( V_9 ) ;
if ( V_18 > 1 )
F_8 ( L_66 ) ;
return 0 ;
V_209:
return V_205 ;
}
static void F_80 ( struct V_7 * V_9 )
{
if ( V_18 > 0 ) F_8 ( L_67 , V_9 -> V_16 ,
F_81 ( V_9 ) ? L_68 : L_69 ) ;
F_82 ( V_9 ) ;
}
static T_4 F_83 ( struct V_144 * V_145 , struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
unsigned long V_210 ;
if ( V_18 > 3 ) {
F_8 ( L_70 ,
V_9 -> V_16 , V_145 -> V_37 ,
( V_145 -> V_156 [ V_84 + V_84 ] << 8 ) | V_145 -> V_156 [ V_84 + V_84 + 1 ] ) ;
}
F_68 ( & V_46 -> V_53 , V_210 ) ;
F_84 ( V_9 ) ;
F_13 ( V_9 -> V_17 , V_192 , V_46 -> V_76 ) ;
F_13 ( V_9 -> V_17 , V_194 , V_145 -> V_37 ) ;
if ( ( F_21 ( V_9 , V_196 ) & V_197 ) == 0 ) {
F_75 ( & V_46 -> V_53 , V_210 ) ;
if ( V_18 ) F_8 ( L_71 ) ;
return V_240 ;
}
F_20 ( V_9 -> V_17 , V_198 , V_145 -> V_156 , ( V_145 -> V_37 + 1 ) >> 1 ) ;
F_75 ( & V_46 -> V_53 , V_210 ) ;
V_9 -> V_151 . V_241 += V_145 -> V_37 ;
F_85 ( V_145 ) ;
return V_242 ;
}
static T_5 F_28 ( int V_13 , void * V_243 )
{
struct V_7 * V_9 = V_243 ;
struct V_10 * V_46 ;
int V_44 , V_146 ;
int V_244 = 0 ;
V_44 = V_9 -> V_17 ;
V_46 = F_30 ( V_9 ) ;
while ( ( V_146 = F_11 ( V_9 -> V_17 , V_245 ) ) ) {
if ( V_18 > 4 ) F_8 ( L_72 , V_9 -> V_16 , V_146 ) ;
V_244 = 1 ;
switch( V_146 & V_246 ) {
case V_247 :
F_86 ( V_9 ) ;
break;
case V_248 :
V_9 -> V_151 . V_249 ++ ;
F_82 ( V_9 ) ;
if ( ( V_146 & ( V_201 |
V_250 |
V_251 |
V_252 |
V_253 ) ) != V_201 ) {
if ( ( V_146 & V_201 ) == 0 )
V_9 -> V_151 . V_254 ++ ;
if ( V_146 & V_250 )
V_9 -> V_151 . V_255 ++ ;
if ( V_146 & V_251 )
V_9 -> V_151 . V_256 ++ ;
if ( V_146 & V_252 )
V_9 -> V_151 . V_257 ++ ;
if ( V_146 & V_253 )
V_9 -> V_151 . V_258 ++ ;
}
break;
case V_259 :
if ( V_146 & V_260 ) {
F_82 ( V_9 ) ;
}
if ( V_146 & V_261 ) {
if ( V_18 > 0 ) F_8 ( L_73 , V_9 -> V_16 ) ;
V_46 -> V_262 ++ ;
if ( V_46 -> V_262 == 3 ) V_46 -> V_76 = V_77 ;
else if ( V_46 -> V_262 == 6 ) V_46 -> V_76 = V_193 ;
F_82 ( V_9 ) ;
}
#if V_54
if ( V_46 -> V_55 && ( V_146 & V_263 ) ) {
int V_113 = F_21 ( V_9 , V_264 ) ;
while( V_113 ) {
if ( V_18 > 5 )
F_8 ( L_74 , V_9 -> V_16 , V_113 ) ;
if ( V_18 > 2 && V_113 > 1 )
F_8 ( L_74 , V_9 -> V_16 , V_113 ) ;
F_45 ( V_9 ) ;
if ( -- V_113 == 0 )
V_113 = F_21 ( V_9 , V_264 ) ;
if ( V_18 > 2 && V_113 > 0 )
F_8 ( L_75 , V_9 -> V_16 , V_113 ) ;
}
}
#endif
break;
case V_265 :
V_9 -> V_151 . V_266 += ( V_146 >> 6 ) ;
break;
case V_267 :
V_9 -> V_151 . V_268 += ( V_146 >> 6 ) ;
break;
}
}
return F_87 ( V_244 ) ;
}
static void
F_46 ( int V_146 , struct V_7 * V_9 )
{
V_9 -> V_151 . V_269 ++ ;
if ( V_146 & V_270 )
V_9 -> V_151 . V_271 ++ ;
if ( V_146 & V_272 )
V_9 -> V_151 . V_271 ++ ;
if ( ( V_146 & V_273 ) && ! ( V_146 & ( V_272 | V_270 ) ) )
V_9 -> V_151 . V_274 ++ ;
if ( V_146 & V_275 )
V_9 -> V_151 . V_276 ++ ;
}
static void
F_86 ( struct V_7 * V_9 )
{
struct V_144 * V_145 ;
int V_146 , V_26 ;
int V_44 = V_9 -> V_17 ;
V_146 = F_11 ( V_44 , V_277 ) ;
V_26 = F_11 ( V_44 , V_277 ) ;
if ( ( V_146 & V_149 ) == 0 ) {
F_46 ( V_146 , V_9 ) ;
return;
}
V_145 = F_47 ( V_9 , V_26 + 2 ) ;
if ( V_145 == NULL ) {
#if 0
printk(KERN_WARNING "%s: Memory squeeze, dropping packet.\n", dev->name);
#endif
V_9 -> V_151 . V_152 ++ ;
return;
}
F_48 ( V_145 , 2 ) ;
F_19 ( V_44 , V_277 , F_49 ( V_145 , V_26 ) , V_26 >> 1 ) ;
if ( V_26 & 1 )
V_145 -> V_156 [ V_26 - 1 ] = F_11 ( V_44 , V_277 ) ;
if ( V_18 > 3 ) {
F_8 ( L_76 ,
V_9 -> V_16 , V_26 ,
( V_145 -> V_156 [ V_84 + V_84 ] << 8 ) | V_145 -> V_156 [ V_84 + V_84 + 1 ] ) ;
}
V_145 -> V_157 = F_50 ( V_145 , V_9 ) ;
F_51 ( V_145 ) ;
V_9 -> V_151 . V_158 ++ ;
V_9 -> V_151 . V_159 += V_26 ;
}
static void F_77 ( struct V_10 * V_46 )
{
if ( V_46 -> V_155 ) {
F_88 ( ( unsigned long ) ( V_46 -> V_155 ) , F_64 ( V_46 -> V_57 * 1024 ) ) ;
V_46 -> V_155 = NULL ;
}
}
static int
F_89 ( struct V_7 * V_9 )
{
#if V_54
struct V_10 * V_46 = F_30 ( V_9 ) ;
#endif
F_84 ( V_9 ) ;
F_22 ( V_9 , V_226 , 0 ) ;
F_22 ( V_9 , V_227 , 0 ) ;
F_22 ( V_9 , V_235 , 0 ) ;
F_22 ( V_9 , V_206 , 0 ) ;
F_78 ( V_9 -> V_13 , V_9 ) ;
#if V_54
if ( V_46 -> V_55 && V_46 -> V_56 ) {
F_76 ( V_9 -> V_56 ) ;
F_77 ( V_46 ) ;
}
#endif
return 0 ;
}
static struct V_278 *
F_90 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
unsigned long V_210 ;
F_68 ( & V_46 -> V_53 , V_210 ) ;
V_9 -> V_151 . V_266 += ( F_21 ( V_9 , V_279 ) >> 6 ) ;
V_9 -> V_151 . V_268 += ( F_21 ( V_9 , V_280 ) >> 6 ) ;
F_75 ( & V_46 -> V_53 , V_210 ) ;
return & V_9 -> V_151 ;
}
static void F_91 ( struct V_7 * V_9 )
{
struct V_10 * V_46 = F_30 ( V_9 ) ;
unsigned long V_210 ;
F_68 ( & V_46 -> V_53 , V_210 ) ;
if( V_9 -> V_210 & V_281 )
{
V_46 -> V_219 = V_282 ;
}
else if ( ( V_9 -> V_210 & V_283 ) || ! F_92 ( V_9 ) )
{
V_46 -> V_219 = V_284 ;
}
else
V_46 -> V_219 = 0 ;
F_22 ( V_9 , V_220 , V_221 | V_46 -> V_219 ) ;
F_22 ( V_9 , V_226 , V_46 -> V_135 |
( V_46 -> V_219 == V_282 ? ( V_223 | V_285 | V_286 ) : 0 ) ) ;
F_75 ( & V_46 -> V_53 , V_210 ) ;
}
static int F_93 ( struct V_7 * V_9 , void * V_287 )
{
int V_39 ;
struct V_288 * V_289 = V_287 ;
if ( F_94 ( V_9 ) )
return - V_62 ;
memcpy ( V_9 -> V_87 , V_289 -> V_290 , V_9 -> V_291 ) ;
if ( V_18 )
F_8 ( L_77 ,
V_9 -> V_16 , V_9 -> V_87 ) ;
for ( V_39 = 0 ; V_39 < V_84 / 2 ; V_39 ++ )
F_22 ( V_9 , V_86 + V_39 * 2 , V_9 -> V_87 [ V_39 * 2 ] | ( V_9 -> V_87 [ V_39 * 2 + 1 ] << 8 ) ) ;
return 0 ;
}
int T_1 F_95 ( void )
{
struct V_7 * V_9 = F_5 ( sizeof( struct V_10 ) ) ;
struct V_10 * V_46 ;
int V_205 = 0 ;
#if V_292
V_18 = V_293 ;
#else
V_293 = 0 ;
#endif
if ( ! V_9 )
return - V_294 ;
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
if ( ! strcmp ( V_295 , L_1 ) )
V_46 -> V_88 = V_99 | V_98 ;
else if ( ! strcmp ( V_295 , L_2 ) )
V_46 -> V_88 = V_101 | V_100 ;
else if ( ! strcmp ( V_295 , L_3 ) )
V_46 -> V_88 = V_115 | V_114 ;
else
V_46 -> V_88 = V_99 | V_98 ;
if ( V_296 == - 1 )
V_46 -> V_107 = V_179 ;
if ( V_14 == 0 ) {
F_8 ( V_61 L_78 ) ;
F_8 ( V_61 L_79 ) ;
V_205 = - V_297 ;
goto V_21;
} else if ( V_14 <= 0x1ff ) {
V_205 = - V_19 ;
goto V_21;
}
#if V_54
if ( V_55 && V_57 != 16 && V_57 != 64 ) {
F_8 ( V_61 L_80 , V_57 ) ;
V_205 = - V_297 ;
goto V_21;
}
#endif
V_205 = F_9 ( V_9 , V_14 , 1 ) ;
if ( V_205 )
goto V_21;
V_298 = V_9 ;
return 0 ;
V_21:
F_10 ( V_9 ) ;
return V_205 ;
}
void T_6
F_96 ( void )
{
F_97 ( V_298 ) ;
F_13 ( V_298 -> V_17 , V_30 , V_69 ) ;
F_40 ( V_298 -> V_17 , V_59 ) ;
F_10 ( V_298 ) ;
}
static int T_1 F_98 ( struct V_299 * V_300 )
{
struct V_7 * V_9 = F_5 ( sizeof( struct V_10 ) ) ;
struct V_10 * V_46 ;
struct V_301 * V_302 ;
int V_12 ;
if ( ! V_9 )
return - V_294 ;
V_46 = F_30 ( V_9 ) ;
V_302 = F_99 ( V_300 , V_303 , 0 ) ;
V_9 -> V_13 = F_100 ( V_300 , 0 ) ;
if ( V_302 == NULL || V_9 -> V_13 <= 0 ) {
F_101 ( & V_9 -> V_9 , L_81 ) ;
V_12 = - V_19 ;
goto free;
}
V_46 -> V_304 = V_302 -> V_305 ;
V_46 -> V_306 = F_102 ( V_302 ) ;
if ( ! F_103 ( V_46 -> V_304 , V_46 -> V_306 , V_60 ) ) {
F_101 ( & V_9 -> V_9 , L_82 ) ;
V_12 = - V_62 ;
goto free;
}
V_46 -> V_307 = F_104 ( V_46 -> V_304 , V_46 -> V_306 ) ;
if ( ! V_46 -> V_307 ) {
F_101 ( & V_9 -> V_9 , L_83 ) ;
V_12 = - V_294 ;
goto V_308;
}
V_12 = F_9 ( V_9 , ( unsigned long ) V_46 -> V_307 , 0 ) ;
if ( V_12 ) {
F_101 ( & V_9 -> V_9 , L_84 ) ;
goto V_309;
}
F_105 ( V_300 , V_9 ) ;
return 0 ;
V_309:
F_106 ( V_46 -> V_307 ) ;
V_308:
F_107 ( V_46 -> V_304 , V_46 -> V_306 ) ;
free:
F_10 ( V_9 ) ;
return V_12 ;
}
static int F_108 ( struct V_299 * V_300 )
{
struct V_7 * V_9 = F_109 ( V_300 ) ;
struct V_10 * V_46 = F_30 ( V_9 ) ;
F_97 ( V_9 ) ;
F_106 ( V_46 -> V_307 ) ;
F_107 ( V_46 -> V_304 , V_46 -> V_306 ) ;
F_10 ( V_9 ) ;
return 0 ;
}
static int T_1 F_110 ( void )
{
return F_111 ( & V_310 , F_98 ) ;
}
static void T_6 F_112 ( void )
{
F_113 ( & V_310 ) ;
}
