static unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
V_2 = F_2 () ;
switch ( V_2 & 0xf0000ff0 ) {
case 0x40000850 :
case 0x400008d0 :
case 0x200008d0 :
V_1 -= 4096 ;
break;
default:
break;
}
return V_1 ;
}
void F_3 ( void )
{
int V_3 ;
unsigned long V_1 , V_4 ;
V_1 = 0 ;
for ( V_3 = 0 ; V_3 < F_4 ( V_5 ) ; V_3 ++ ) {
V_4 = F_5 ( V_5 [ V_3 ] ) ;
if ( V_4 & V_6 )
V_1 += F_6 ( V_4 ) ;
}
V_1 = F_1 ( V_1 ) ;
F_7 ( 0 , V_1 ) ;
}
static T_1 F_8 ( T_2 V_7 )
{
T_1 V_8 = ( ( T_1 ) ( V_7 & 0xFFE00000u ) ) << 2 ;
switch ( ( V_7 >> 4 ) & 0xFFF ) {
case 0 :
return 0 ;
case 0xffc :
return V_8 + 0x000800000ull ;
case 0xff8 :
return V_8 + 0x001000000ull ;
case 0xff0 :
return V_8 + 0x002000000ull ;
case 0xfe0 :
return V_8 + 0x004000000ull ;
case 0xfc0 :
return V_8 + 0x008000000ull ;
case 0xf80 :
return V_8 + 0x010000000ull ;
case 0xf00 :
return V_8 + 0x020000000ull ;
case 0xe00 :
return V_8 + 0x040000000ull ;
case 0xc00 :
return V_8 + 0x080000000ull ;
case 0x800 :
return V_8 + 0x100000000ull ;
}
printf ( L_1 , V_7 ) ;
return 0 ;
}
void F_9 ( void )
{
T_1 V_9 , V_1 = 0 ;
V_9 = F_8 ( F_10 ( V_10 ) ) ;
if ( V_9 > V_1 )
V_1 = V_9 ;
V_9 = F_8 ( F_10 ( V_11 ) ) ;
if ( V_9 > V_1 )
V_1 = V_9 ;
V_9 = F_8 ( F_10 ( V_12 ) ) ;
if ( V_9 > V_1 )
V_1 = V_9 ;
V_9 = F_8 ( F_10 ( V_13 ) ) ;
if ( V_9 > V_1 )
V_1 = V_9 ;
F_7 ( 0 , V_1 ) ;
}
static inline T_2 F_11 ( void )
{
void * V_14 ;
char V_15 [ 64 ] ;
T_2 V_16 , V_17 ;
V_14 = F_12 ( L_2 ) ;
if ( ! V_14 )
goto V_18;
if ( F_13 ( V_14 , L_3 , V_15 , sizeof( V_15 ) ) <= 0 )
goto V_18;
V_15 [ sizeof( V_15 ) - 1 ] = 0 ;
if ( ! strcmp ( V_15 , L_4 ) ||
! strcmp ( V_15 , L_5 ) )
return 1 ;
V_18:
V_16 = F_5 ( V_19 ) ;
V_16 = F_14 ( V_16 , V_20 , V_21 ) ;
V_17 = 0 ;
while ( V_16 ) {
if ( V_16 & 0x1 )
V_17 ++ ;
V_16 = V_16 >> 1 ;
}
return V_17 ;
}
void F_15 ( void )
{
T_2 V_16 , V_22 , V_23 , V_24 ;
T_2 V_17 , V_25 , V_26 , V_27 , V_28 ;
unsigned long V_1 ;
V_16 = F_5 ( V_29 ) ;
if ( ! F_14 ( V_16 , V_30 , V_31 ) )
F_16 ( L_6 ) ;
V_22 = F_14 ( V_16 , V_32 , V_33 ) ;
V_23 = F_14 ( V_16 , V_34 , V_35 ) ;
V_24 = F_14 ( V_16 , V_36 , V_37 ) ;
V_17 = F_11 () ;
if ( ! V_17 )
F_16 ( L_7 ) ;
if ( V_17 > V_22 )
F_16 ( L_8 ) ;
V_16 = F_5 ( V_38 ) ;
if ( F_14 ( V_16 , V_39 , V_40 ) )
V_28 = 4 ;
else
V_28 = 8 ;
V_16 = F_5 ( V_41 ) ;
V_26 = F_14 ( V_16 , V_42 , V_43 ) ;
if ( V_26 > V_24 )
F_16 ( L_9 ) ;
V_26 = V_24 - V_26 ;
V_16 = F_5 ( V_44 ) ;
V_25 = F_14 ( V_16 , V_45 , V_46 ) ;
if ( V_25 > V_23 )
F_16 ( L_10 ) ;
V_25 = V_23 - V_25 ;
if ( F_14 ( V_16 , V_47 , V_48 ) )
V_27 = 8 ;
else
V_27 = 4 ;
V_1 = V_17 * ( 1 << ( V_25 + V_26 ) ) * V_27 * V_28 ;
V_1 = F_1 ( V_1 ) ;
F_7 ( 0 , V_1 ) ;
}
void F_17 ( void )
{
unsigned long V_49 ;
asm volatile (
"mfspr %0,%1\n"
"oris %0,%0,%2@h\n"
"mtspr %1,%0"
: "=&r"(tmp) : "i"(SPRN_DBCR0_44X), "i"(DBCR0_RST_SYSTEM)
);
}
void F_18 ( void )
{
unsigned long V_49 ;
asm volatile (
"mfspr %0,%1\n"
"oris %0,%0,%2@h\n"
"mtspr %1,%0"
: "=&r"(tmp) : "i"(SPRN_DBCR0_40X), "i"(DBCR0_RST_SYSTEM)
);
}
void F_19 ( T_2 * V_50 , T_2 * V_51 )
{
if ( V_50 )
* V_50 = V_52 ;
if ( V_51 )
* V_51 = V_52 ;
F_20 ( V_53 , V_54 ) ;
while ( F_10 ( V_53 ) & V_54 )
;
}
void F_21 ( const char * V_55 )
{
void * V_14 ;
T_2 V_56 ;
T_2 V_57 [ V_58 * 4 ] ;
T_2 * V_59 = V_57 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_58 ; V_3 ++ ) {
F_20 ( V_60 , F_22 ( V_3 ) ) ;
V_56 = F_10 ( V_61 ) ;
if ( ( V_56 & V_62 ) != V_63 ) {
* V_59 ++ = V_3 ;
* V_59 ++ = 0 ;
* V_59 ++ = V_56 & V_64 ;
* V_59 ++ = F_23 ( V_56 ) ;
}
}
V_14 = F_12 ( V_55 ) ;
if ( ! V_14 )
F_16 ( L_11 , V_55 ) ;
F_24 ( V_14 , L_12 , V_57 , ( V_59 - V_57 ) * sizeof( T_2 ) ) ;
}
void F_25 ( unsigned int V_65 , unsigned int V_66 )
{
T_2 V_67 = F_10 ( V_68 ) ;
T_2 V_69 = F_10 ( V_70 ) ;
T_2 V_71 , V_72 , V_73 , V_55 , V_74 , V_75 , V_76 , V_77 ;
T_2 V_78 = F_26 ( V_67 ) ;
T_2 V_79 = F_27 ( V_67 ) ;
if ( V_67 & V_80 ) {
V_71 = V_72 = V_65 ;
} else {
if ( V_67 & V_81 )
V_77 = F_28 ( V_67 ) * V_78 * V_79 ;
else
V_77 = F_29 ( V_67 ) * F_30 ( V_67 ) ;
V_71 = V_65 * V_77 / F_30 ( V_67 ) ;
V_72 = V_65 * V_77 / F_28 ( V_67 ) ;
}
V_73 = V_72 / V_78 ;
V_55 = V_73 / V_79 ;
if ( ( F_2 () & 0xf0000fff ) == 0x40000440 )
V_74 = V_65 ;
else
V_74 = V_71 ;
if ( V_69 & V_82 )
V_75 = V_66 ;
else
V_75 = V_72 / F_31 ( V_69 ) ;
if ( V_69 & V_83 )
V_76 = V_66 ;
else
V_76 = V_72 / F_31 ( V_69 ) ;
printf ( L_13 ,
( V_65 + 500000 ) / 1000000 , V_65 ) ;
F_32 ( V_71 , V_74 , 0 ) ;
F_33 ( L_14 , V_72 ) ;
F_33 ( L_15 , V_73 ) ;
F_33 ( L_16 , V_55 ) ;
F_33 ( L_17 , V_75 ) ;
F_33 ( L_18 , V_76 ) ;
}
static inline T_2 F_34 ( T_2 V_84 , T_2 V_85 )
{
return V_84 ? V_84 : V_85 ;
}
static unsigned int F_35 ( unsigned int V_65 ,
unsigned int V_86 ,
int V_87 )
{
T_2 V_88 = F_36 ( V_89 ) ;
T_2 V_90 = F_36 ( V_91 ) ;
T_2 V_92 = F_34 ( ( V_90 >> 24 ) & 0x1f , 32 ) ;
T_2 V_93 = F_34 ( ( V_90 >> 16 ) & 0xf , 16 ) ;
T_2 V_94 = F_34 ( ( V_90 >> 8 ) & 7 , 8 ) ;
T_2 V_95 = F_34 ( V_90 & 0x3f , 64 ) ;
T_2 V_96 = F_34 ( ( F_36 ( V_97 ) >> 24 ) & 7 , 8 ) ;
T_2 V_98 = F_34 ( ( F_36 ( V_99 ) >> 24 ) & 7 , 8 ) ;
T_2 V_100 = F_34 ( ( F_36 ( V_101 ) >> 24 ) & 3 , 4 ) ;
T_2 V_102 = F_34 ( ( F_36 ( V_103 ) >> 24 ) & 3 , 4 ) ;
T_2 V_104 , V_105 ;
T_2 V_71 , V_72 , V_73 , V_55 , V_106 ;
T_2 V_107 , V_74 = V_86 ;
if ( V_88 & 0x40000000 ) {
T_2 V_77 ;
switch ( ( V_88 >> 24 ) & 7 ) {
case 0 :
V_77 = ( ( V_88 & 0x20000000 ) ? V_94 : V_93 ) * V_95 ;
break;
case 1 :
V_77 = V_93 * V_96 ;
break;
case 5 :
V_77 = V_94 * V_98 * V_100 * V_102 ;
break;
default:
printf ( L_19 ) ;
goto V_108;
}
V_77 *= V_92 ;
V_106 = V_65 * V_77 ;
V_104 = V_106 / V_93 ;
V_105 = V_106 / V_94 ;
} else {
V_108:
V_106 = 0 ;
V_104 = V_105 = V_65 ;
}
V_71 = V_104 / V_96 ;
V_72 = V_105 / V_98 ;
V_73 = V_72 / V_100 ;
V_55 = ( V_87 ? V_73 : V_72 ) / V_102 ;
V_107 = F_37 ( V_109 ) ;
if ( V_74 == 0 ) {
V_107 &= ~ 0x80u ;
F_38 ( V_109 , V_107 ) ;
}
if ( ( V_107 & 0x0080 ) == 0 )
V_74 = V_71 ;
F_32 ( V_71 , V_74 , 0 ) ;
F_33 ( L_14 , V_72 ) ;
F_33 ( L_15 , V_73 ) ;
F_33 ( L_16 , V_55 ) ;
return V_72 ;
}
static void F_39 ( int V_110 , const char * V_111 ,
unsigned int V_66 ,
unsigned int V_112 )
{
unsigned int V_113 ;
unsigned int clock ;
switch ( V_110 ) {
case 0 :
V_113 = F_40 ( V_114 ) ;
break;
case 1 :
V_113 = F_40 ( V_115 ) ;
break;
case 2 :
V_113 = F_40 ( V_116 ) ;
break;
case 3 :
V_113 = F_40 ( V_117 ) ;
break;
default:
return;
}
if ( V_113 & 0x00800000u )
clock = V_66 ;
else
clock = V_112 / F_34 ( V_113 & 0xff , 256 ) ;
F_33 ( V_111 , clock ) ;
}
void F_41 ( unsigned int V_65 ,
unsigned int V_66 ,
unsigned int V_86 )
{
unsigned int V_112 = F_35 ( V_65 , V_86 , 0 ) ;
F_39 ( 0 , L_20 , V_66 , V_112 ) ;
F_39 ( 1 , L_21 , V_66 , V_112 ) ;
F_39 ( 2 , L_22 , V_66 , V_112 ) ;
F_39 ( 3 , L_23 , V_66 , V_112 ) ;
}
void F_42 ( unsigned int V_65 ,
unsigned int V_66 ,
unsigned int V_86 )
{
unsigned int V_112 = F_35 ( V_65 , V_86 , 1 ) ;
F_39 ( 0 , L_17 , V_66 , V_112 ) ;
F_39 ( 1 , L_18 , V_66 , V_112 ) ;
}
void F_43 ( unsigned int V_65 ,
unsigned int V_66 ,
unsigned int V_86 )
{
unsigned int V_112 = F_35 ( V_65 , V_86 , 1 ) ;
F_39 ( 0 , L_24 , V_66 , V_112 ) ;
F_39 ( 1 , L_25 , V_66 , V_112 ) ;
F_39 ( 2 , L_26 , V_66 , V_112 ) ;
}
void F_44 ( unsigned int V_65 , unsigned int V_66 )
{
T_2 V_118 = F_10 ( V_119 ) ;
T_2 V_120 = F_10 ( V_121 ) ;
T_2 V_122 = F_10 ( V_123 ) ;
T_2 V_124 = F_10 ( V_125 ) ;
T_2 V_71 , V_72 , V_73 , V_55 , V_74 , V_75 , V_76 , V_77 ;
T_2 V_126 , V_94 , V_92 , V_127 , V_78 , V_79 , V_128 , V_129 ;
V_126 = ( 8 - ( ( V_118 & 0xe0000000 ) >> 29 ) ) ;
V_92 = ( V_118 & 0x1e000000 ) >> 25 ;
if ( V_92 == 0 )
V_92 = 16 ;
V_127 = ( ( V_118 & 0x00060000 ) >> 17 ) + 1 ;
V_78 = ( ( V_118 & 0x00018000 ) >> 15 ) + 1 ;
V_128 = ( ( V_118 & 0x00006000 ) >> 13 ) + 1 ;
V_79 = ( ( V_118 & 0x00001800 ) >> 11 ) + 2 ;
V_129 = ( ( V_120 & 0x3e ) >> 1 ) + 1 ;
if ( ( F_2 () & 0xfffffff0 ) == ( 0x50910951 & 0xfffffff0 ) ) {
V_94 = 8 - ( V_118 & 0x00000007 ) ;
if ( ! ( V_124 & 0x00001000 ) )
if ( V_124 & 0x00000020 )
V_77 = V_94 * 2 * V_128 ;
else
V_77 = V_94 * V_127 * V_128 ;
else if ( V_124 & 0x00000020 )
if ( V_124 & 0x00000800 )
V_77 = V_94 * 2 * V_79 ;
else
V_77 = V_92 * V_126 ;
else if ( V_79 == V_92 )
V_77 = V_92 * V_127 * V_79 ;
else
V_77 = V_92 * V_94 * V_127 ;
V_71 = V_65 * V_77 / V_126 ;
V_72 = V_65 * V_77 / ( V_94 * V_127 ) ;
} else {
V_77 = V_126 * V_92 * V_127 ;
V_71 = V_65 * V_77 / V_126 ;
V_72 = V_71 / V_127 ;
}
V_73 = V_72 / V_78 ;
V_55 = V_72 / V_79 ;
if ( V_120 & 0x80 )
V_75 = V_66 ;
else
V_75 = V_71 / V_129 ;
if ( V_120 & 0x40 )
V_76 = V_66 ;
else
V_76 = V_71 / V_129 ;
V_122 = V_122 & ~ 0x00800000 ;
F_20 ( V_123 , V_122 ) ;
V_74 = V_71 ;
F_32 ( V_71 , V_74 , 0 ) ;
F_33 ( L_14 , V_72 ) ;
F_33 ( L_15 , V_73 ) ;
F_33 ( L_27 , V_55 ) ;
F_33 ( L_20 , V_75 ) ;
F_33 ( L_21 , V_76 ) ;
}
void F_45 ( unsigned int V_65 )
{
T_2 V_130 = F_10 ( V_131 ) ;
T_2 V_132 = F_10 ( V_133 ) ;
T_2 V_134 = F_10 ( V_135 ) ;
T_2 V_71 , V_72 , V_73 , V_55 , V_75 , V_76 ;
T_2 V_93 , V_94 , V_92 , V_127 , V_78 , V_79 ;
T_2 V_136 , V_74 , V_77 ;
V_93 = 8 - ( ( V_132 & 0x00070000 ) >> 16 ) ;
V_94 = 8 - ( ( V_132 & 0x00007000 ) >> 12 ) ;
V_92 = ( V_132 & 0x00f00000 ) >> 20 ;
if ( V_92 == 0 )
V_92 = 16 ;
V_127 = ( ( V_130 & 0x00030000 ) >> 16 ) + 1 ;
V_79 = ( ( V_130 & 0x00000300 ) >> 8 ) + 2 ;
V_78 = ( ( V_130 & 0x00003000 ) >> 12 ) + 1 ;
V_77 = V_92 * V_94 ;
V_136 = ( ( V_130 & 0x00300000 ) >> 20 ) + 1 ;
if ( V_132 & 0x80000000 )
V_71 = V_65 * V_77 / ( V_93 * V_136 ) ;
else
V_71 = V_65 / V_136 ;
V_72 = V_71 / V_127 ;
V_73 = V_72 / V_78 ;
V_55 = V_72 / V_79 ;
V_74 = V_71 ;
V_75 = V_71 / ( V_134 & 0x0000007f ) ;
V_76 = V_71 / ( ( V_134 & 0x00007f00 ) >> 8 ) ;
F_32 ( V_71 , V_74 , 0 ) ;
F_33 ( L_14 , V_72 ) ;
F_33 ( L_15 , V_73 ) ;
F_33 ( L_27 , V_55 ) ;
F_33 ( L_20 , V_75 ) ;
F_33 ( L_21 , V_76 ) ;
}
T_2 F_46 ( unsigned long V_137 )
{
T_2 V_110 ;
for ( V_110 = 0 ; V_110 < F_4 ( V_138 ) ; V_110 ++ )
if ( V_137 == ( T_2 ) V_138 [ V_110 ] )
return V_110 + 1 ;
return 0 ;
}
T_2 F_47 ( unsigned long V_139 )
{
T_2 V_110 ;
for ( V_110 = 0 ; V_110 < F_4 ( V_140 ) ; V_110 ++ )
if ( V_139 == ( T_2 ) V_140 [ V_110 ] )
return V_110 + 1 ;
return 0 ;
}
void F_48 ( unsigned int V_65 , unsigned int V_141 )
{
T_2 V_88 = F_36 ( V_89 ) ;
T_2 V_90 = F_36 ( V_91 ) ;
T_2 V_142 = F_36 ( V_97 ) ;
T_2 V_143 = F_36 ( V_99 ) ;
T_2 V_144 = F_36 ( V_101 ) ;
T_2 V_145 = F_36 ( V_103 ) ;
T_2 V_92 = F_47 ( F_34 ( ( V_90 >> 24 ) & 0xff , 1 ) ) ;
T_2 V_93 = F_46 ( F_34 ( ( V_90 >> 16 ) & 0x0f , 1 ) ) ;
T_2 V_146 = F_34 ( ( V_142 >> 24 ) & 7 , 8 ) ;
T_2 V_147 = 2 ;
T_2 V_148 = F_34 ( ( V_143 >> 16 ) & 7 , 8 ) ;
T_2 V_100 = F_34 ( ( V_144 >> 24 ) & 3 , 4 ) ;
T_2 V_102 = F_34 ( ( V_145 >> 24 ) & 3 , 4 ) ;
T_2 V_71 , V_72 , V_73 , V_55 , V_106 , V_74 , V_75 , V_76 ;
if ( V_88 & 0x40000000 ) {
T_2 V_77 ;
switch ( ( V_88 >> 24 ) & 7 ) {
case 0 :
V_77 = V_92 ;
break;
case 1 :
V_77 = V_92 * V_93 * V_146 ;
break;
case 5 :
V_77 = V_92 * V_93 * V_148 * V_147 * V_100 * V_102 ;
break;
default:
printf ( L_19 ) ;
goto V_108;
}
V_106 = ( unsigned int ) ( V_65 * V_77 ) ;
} else {
V_108:
V_106 = 0 ;
}
V_71 = V_106 / ( V_93 * V_146 ) ;
V_72 = V_106 / ( V_93 * V_148 * V_147 ) ;
V_73 = V_72 / V_100 ;
V_55 = V_73 / V_102 ;
V_74 = V_71 ;
V_75 = V_76 = V_141 ;
F_32 ( V_71 , V_74 , 0 ) ;
F_33 ( L_14 , V_72 ) ;
F_33 ( L_15 , V_73 ) ;
F_33 ( L_16 , V_55 ) ;
F_33 ( L_28 , V_75 ) ;
F_33 ( L_20 , V_76 ) ;
}
