static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
unsigned long * V_5 , unsigned char * V_6 )
{
T_1 V_7 = V_2 -> V_8 ;
* V_6 = ( V_7 != 0 ) ;
* V_5 = ( V_7 << 16 ) | ( V_3 << 8 ) | V_4 ;
F_2 ( ( L_1
L_2
V_7 , V_3 , V_4 , * V_5 ) ) ;
return 0 ;
}
static unsigned int
F_3 ( unsigned long V_9 , unsigned char V_6 )
{
unsigned long V_10 ;
int V_11 , V_12 ;
int V_13 = 0 ;
F_2 ( ( L_3 , V_9 , V_6 ) ) ;
F_4 ( V_10 ) ;
V_11 = * ( V_14 ) V_15 ;
* ( V_14 ) V_15 = V_11 ;
F_5 () ;
* ( V_14 ) V_15 ;
if ( V_6 ) {
V_13 = * ( V_14 ) V_16 ;
* ( V_14 ) V_16 = ( V_13 & ~ 3 ) | 1 ;
F_5 () ;
* ( V_14 ) V_16 ;
}
F_5 () ;
F_6 () ;
F_7 ( 0 ) = 1 ;
F_8 ( 0 ) = 0 ;
F_5 () ;
V_12 = * ( V_14 ) V_9 ;
F_5 () ;
F_5 () ;
if ( F_8 ( 0 ) ) {
F_8 ( 0 ) = 0 ;
V_12 = 0xffffffff ;
F_5 () ;
}
F_7 ( 0 ) = 0 ;
F_5 () ;
if ( V_6 ) {
* ( V_14 ) V_16 = V_13 ;
F_5 () ;
* ( V_14 ) V_16 ;
}
F_9 ( V_10 ) ;
F_2 ( ( L_4 ) ) ;
return V_12 ;
}
static void
F_10 ( unsigned long V_9 , unsigned int V_12 , unsigned char V_6 )
{
unsigned long V_10 ;
int V_11 , V_13 = 0 ;
F_2 ( ( L_5 , V_9 , V_6 ) ) ;
F_4 ( V_10 ) ;
V_11 = * ( V_14 ) V_15 ;
* ( V_14 ) V_15 = V_11 ;
F_5 () ;
* ( V_14 ) V_15 ;
if ( V_6 ) {
V_13 = * ( V_14 ) V_16 ;
* ( V_14 ) V_16 = ( V_13 & ~ 3 ) | 1 ;
F_5 () ;
* ( V_14 ) V_16 ;
}
F_5 () ;
F_6 () ;
F_7 ( 0 ) = 1 ;
F_8 ( 0 ) = 0 ;
F_5 () ;
* ( V_14 ) V_9 = V_12 ;
F_5 () ;
* ( V_14 ) V_9 ;
F_7 ( 0 ) = 0 ;
F_5 () ;
if ( V_6 ) {
* ( V_14 ) V_16 = V_13 ;
F_5 () ;
* ( V_14 ) V_16 ;
}
F_9 ( V_10 ) ;
F_2 ( ( L_4 ) ) ;
}
static int
F_11 ( struct V_1 * V_7 , unsigned int V_17 , int V_4 , int V_18 ,
T_2 * V_12 )
{
unsigned long V_9 , V_5 ;
long V_19 ;
unsigned char V_6 ;
int V_20 ;
if ( F_1 ( V_7 , V_17 , V_4 , & V_5 , & V_6 ) )
return V_21 ;
V_19 = ( V_18 - 1 ) * 8 ;
V_20 = ( V_4 & 3 ) * 8 ;
V_9 = ( V_5 << 5 ) + V_19 + V_22 ;
* V_12 = F_3 ( V_9 , V_6 ) >> ( V_20 ) ;
return V_23 ;
}
static int
F_12 ( struct V_1 * V_7 , unsigned int V_17 , int V_4 , int V_18 ,
T_2 V_12 )
{
unsigned long V_9 , V_5 ;
long V_19 ;
unsigned char V_6 ;
if ( F_1 ( V_7 , V_17 , V_4 , & V_5 , & V_6 ) )
return V_21 ;
V_19 = ( V_18 - 1 ) * 8 ;
V_9 = ( V_5 << 5 ) + V_19 + V_22 ;
F_10 ( V_9 , V_12 << ( ( V_4 & 3 ) * 8 ) , V_6 ) ;
return V_23 ;
}
void
F_13 ( struct V_24 * V_25 , T_3 V_26 , T_3 V_27 )
{
F_14 () ;
* ( V_14 ) V_28 = 3 ;
F_5 () ;
* ( V_14 ) V_28 ;
}
void
F_15 ( struct V_24 * V_25 ,
T_3 V_26 , T_3 V_27 )
{
void T_4 * V_29 ;
int V_30 ;
F_5 () ;
V_30 = * ( V_14 ) V_31 ;
* ( V_14 ) V_31 = V_30 | V_32 ;
F_5 () ;
* ( V_14 ) V_31 ;
F_5 () ;
V_29 = F_16 ( V_33 , 32768 * 4 ) ;
F_17 ( V_29 + 0x00000 ) ;
F_17 ( V_29 + 0x08000 ) ;
F_17 ( V_29 + 0x10000 ) ;
F_17 ( V_29 + 0x18000 ) ;
F_18 ( V_29 ) ;
F_5 () ;
* ( V_14 ) V_31 = V_30 ;
F_5 () ;
* ( V_14 ) V_31 ;
F_5 () ;
}
static inline void
F_19 ( int V_34 )
{
unsigned long * V_35 , V_36 ;
long V_37 ;
V_35 = F_20 ( V_38 , 32768 , 0 ) ;
V_36 = ( F_21 ( V_35 ) >> ( V_39 - 1 ) ) | 1 ;
for ( V_37 = 0 ; V_37 < V_38 / sizeof( unsigned long ) ; ++ V_37 )
V_35 [ V_37 ] = V_36 ;
* ( V_14 ) F_22 ( V_34 ) = V_33 | 3 ;
* ( V_14 ) F_23 ( V_34 )
= ( V_38 * 1024 - 1 ) & 0xfff00000 ;
* ( V_14 ) F_24 ( V_34 ) = F_21 ( V_35 ) >> 2 ;
}
static void T_5
F_25 ( void )
{
static int V_40 [ V_41 / 4 ]
V_42 ( ( F_26 ( V_41 ) ) )
V_43 = { 0 } ;
struct V_44 * V_45 = V_46 -> V_47 ;
int V_30 , V_48 , V_49 , V_50 , V_51 ;
int V_52 , V_53 = 0 ;
void T_4 * V_29 ;
if ( V_46 -> V_54 )
V_53 = 1 ;
F_5 () ;
V_30 = * ( V_14 ) V_31 ;
* ( V_14 ) V_31 = V_30 | V_32 ;
F_5 () ;
* ( V_14 ) V_31 ;
F_5 () ;
V_48 = V_45 -> V_55 ;
V_49 = V_48 | 1 ;
V_50 = ( F_21 ( V_40 ) >> ( V_39 - 1 ) ) | 1 ;
* ( V_14 ) F_27 ( 0 ) = V_49 ;
* ( V_14 ) F_27 ( 1 ) = 0 ;
* ( V_14 ) F_27 ( 2 ) = 0 ;
* ( V_14 ) F_27 ( 3 ) = 0 ;
* ( V_14 ) F_27 ( 4 ) = 0 ;
* ( V_14 ) F_27 ( 5 ) = 0 ;
* ( V_14 ) F_27 ( 6 ) = 0 ;
* ( V_14 ) F_27 ( 7 ) = 0 ;
* ( V_14 ) F_28 ( 0 , 0 ) = V_50 ;
* ( V_14 ) F_28 ( 0 , 1 ) = 0 ;
* ( V_14 ) F_28 ( 0 , 2 ) = 0 ;
* ( V_14 ) F_28 ( 0 , 3 ) = 0 ;
F_5 () ;
V_29 = F_16 ( V_48 , 8 * V_41 ) ;
V_52 = * ( V_14 ) F_27 ( 0 ) ;
if ( V_52 != V_49 ) {
F_29 ( L_6
L_7 , V_52 , V_49 ) ;
goto V_56;
}
V_52 = * ( V_14 ) F_27 ( 1 ) ;
if ( V_52 != 0 ) {
F_29 ( L_6
L_8 , V_52 ) ;
goto V_56;
}
V_52 = * ( V_14 ) F_28 ( 0 , 0 ) ;
if ( V_52 != V_50 ) {
F_29 ( L_6
L_9 , V_52 , V_50 ) ;
goto V_56;
}
F_29 ( L_10 ) ;
V_51 = 0xdeadbeef ;
V_40 [ 0 ] = V_51 ;
F_7 ( 0 ) = 1 ;
F_8 ( 0 ) = 0 ;
F_5 () ;
V_52 = F_17 ( V_29 ) ;
F_5 () ;
F_7 ( 0 ) = 0 ;
F_5 () ;
if ( F_8 ( 0 ) ) {
F_29 ( L_11 ) ;
goto V_56;
}
if ( V_52 != V_51 ) {
F_29 ( L_12
L_13 , V_52 , V_51 ) ;
goto V_56;
}
F_29 ( L_14 ) ;
if ( ! V_53 ) {
F_13 ( V_45 -> V_25 , 0 , - 1 ) ;
V_52 = * ( V_14 ) F_27 ( 0 ) ;
if ( V_52 & 1 ) {
V_53 = 1 ;
F_29 ( L_15 ) ;
} else {
F_29 ( L_16 ) ;
}
}
V_51 = 0x5adda15e ;
V_40 [ 0 ] = V_51 ;
V_45 -> V_57 [ 4 ] = V_50 ;
F_7 ( 0 ) = 1 ;
F_8 ( 0 ) = 0 ;
F_5 () ;
V_52 = F_17 ( V_29 + 4 * V_41 ) ;
F_5 () ;
F_7 ( 0 ) = 0 ;
F_5 () ;
if ( F_8 ( 0 ) ) {
F_29 ( L_17 ) ;
goto V_56;
}
if ( V_52 != V_51 ) {
F_29 ( L_18
L_13 , V_52 , V_51 ) ;
goto V_56;
}
F_29 ( L_19 ) ;
V_51 = 0xabcdef12 ;
V_40 [ 0 ] = V_51 ;
V_45 -> V_57 [ 5 ] = V_50 ;
F_7 ( 0 ) = 1 ;
F_8 ( 0 ) = 0 ;
F_5 () ;
V_52 = F_17 ( V_29 + 5 * V_41 ) ;
F_5 () ;
F_7 ( 0 ) = 0 ;
F_5 () ;
if ( F_8 ( 0 ) ) {
F_29 ( L_20
L_21 ) ;
V_45 -> V_58 = 4 ;
} else if ( V_52 != V_51 ) {
F_29 ( L_20
L_13 , V_52 , V_51 ) ;
goto V_56;
} else {
F_29 ( L_22 ) ;
}
F_7 ( 0 ) = 1 ;
F_8 ( 0 ) = 0 ;
F_5 () ;
V_52 = F_17 ( V_29 + 6 * V_41 ) ;
F_5 () ;
F_7 ( 0 ) = 0 ;
F_5 () ;
F_29 ( L_23 ,
F_8 ( 0 ) ? L_24 : L_25 ) ;
V_45 -> V_57 [ 4 ] = 0 ;
V_45 -> V_57 [ 5 ] = 0 ;
if ( V_53 ) {
V_59 . V_60 = F_15 ;
F_14 () ;
* ( V_14 ) F_27 ( 0 ) = 2 ;
* ( V_14 ) F_27 ( 1 ) = 2 ;
* ( V_14 ) F_27 ( 2 ) = 2 ;
* ( V_14 ) F_27 ( 3 ) = 2 ;
F_29 ( L_26 ) ;
}
V_59 . V_60 ( V_45 -> V_25 , 0 , - 1 ) ;
exit:
F_18 ( V_29 ) ;
F_5 () ;
* ( V_14 ) V_31 = V_30 ;
F_5 () ;
* ( V_14 ) V_31 ;
F_5 () ;
return;
V_56:
F_29 ( L_27 ) ;
* ( V_14 ) V_61 = 0 ;
* ( V_14 ) V_62 = 0 ;
V_46 -> V_47 = NULL ;
V_59 . V_60 = NULL ;
goto exit;
}
void
F_30 ( int V_63 )
{
int V_37 ;
V_64 . V_65 = * ( V_14 ) V_66 ;
V_64 . V_67 = * ( V_14 ) V_31 ;
V_64 . V_68 = * ( V_14 ) V_69 ;
V_64 . V_70 = * ( V_14 ) V_71 ;
V_64 . V_72 = * ( V_14 ) V_73 ;
if ( V_63 )
V_64 . V_74 = * ( V_14 ) V_75 ;
else
V_64 . V_74 = 0 ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
V_64 . V_34 [ V_37 ] . V_76 = * ( V_14 ) F_22 ( V_37 ) ;
V_64 . V_34 [ V_37 ] . V_77 = * ( V_14 ) F_23 ( V_37 ) ;
V_64 . V_34 [ V_37 ] . V_78 = * ( V_14 ) F_24 ( V_37 ) ;
}
F_5 () ;
}
void
F_31 ( void )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
* ( V_14 ) F_22 ( V_37 ) = V_64 . V_34 [ V_37 ] . V_76 ;
* ( V_14 ) F_23 ( V_37 ) = V_64 . V_34 [ V_37 ] . V_77 ;
* ( V_14 ) F_24 ( V_37 ) = V_64 . V_34 [ V_37 ] . V_78 ;
}
* ( V_14 ) V_69 = V_64 . V_68 ;
* ( V_14 ) V_71 = V_64 . V_70 ;
* ( V_14 ) V_73 = V_64 . V_72 ;
* ( V_14 ) V_66 = V_64 . V_65 ;
* ( V_14 ) V_31 = V_64 . V_67 ;
if ( V_64 . V_74 )
* ( V_14 ) V_75 = V_64 . V_74 ;
F_5 () ;
}
static void T_5
F_32 ( int V_63 )
{
struct V_24 * V_25 ;
int V_52 , V_79 , V_80 ;
V_79 = * ( V_14 ) V_81 & V_82 ;
F_29 ( L_28 ,
V_79 , V_63 ? L_29 : L_30 ) ;
if ( V_83 )
F_30 ( V_63 ) ;
V_52 = * ( V_14 ) V_66 ;
V_52 &= ~ ( V_84 | V_85 | V_86
| V_87 | V_88 ) ;
* ( V_14 ) V_66 = V_52 ;
V_52 = * ( V_14 ) V_15 ;
* ( V_14 ) V_15 = V_52 ;
V_52 = * ( V_14 ) V_31 ;
V_52 |= V_89 | V_90 ;
* ( V_14 ) V_31 = V_52 ;
* ( V_14 ) V_16 = 0 ;
* ( V_14 ) V_69 = 0 ;
* ( V_14 ) V_71 = 0 ;
if ( V_63 ) {
V_52 = * ( V_14 ) V_75 ;
V_52 |= V_91 | V_92 ;
* ( V_14 ) V_75 = V_52 ;
}
F_5 () ;
* ( V_14 ) V_81 ;
V_46 = V_25 = F_33 () ;
V_25 -> V_93 = & V_94 ;
V_25 -> V_95 = & V_96 ;
V_25 -> V_97 = 0 ;
if ( ! V_63 ) {
struct V_98 * V_68 = F_34 () ;
V_25 -> V_95 = V_68 ;
V_68 -> V_26 = 0 ;
V_68 -> V_27 = V_99 ;
V_68 -> V_100 = V_101 ;
V_68 -> V_10 = V_102 ;
if ( F_35 ( & V_96 , V_68 ) < 0 )
F_29 ( V_103 L_31 ) ;
V_25 -> V_104 = V_105 - V_106 ;
V_25 -> V_107 = V_108 - V_106 ;
V_25 -> V_109 = V_110 - V_106 ;
V_25 -> V_54 = 0 ;
} else {
V_25 -> V_104 = 0 ;
V_25 -> V_107 = V_111 - V_106 ;
V_25 -> V_109 = 0 ;
V_25 -> V_54 = V_112 - V_106 ;
}
V_25 -> V_113 = NULL ;
V_25 -> V_47 = F_36 ( V_25 , 0x00800000 , 0x00800000 , 32768 ) ;
V_114 = 0x80000000 ;
V_115 = 0x80000000 ;
* ( V_14 ) V_61 = V_25 -> V_47 -> V_55 | 3 ;
* ( V_14 ) V_116 = ( V_25 -> V_47 -> V_18 - 1 ) & 0xfff00000 ;
* ( V_14 ) V_117 = F_21 ( V_25 -> V_47 -> V_57 ) >> 2 ;
* ( V_14 ) V_118 = V_114 | 1 ;
* ( V_14 ) V_119 = ( V_115 - 1 ) & 0xfff00000 ;
* ( V_14 ) V_120 = 0 >> 2 ;
V_80 = 1 ;
if ( V_63 ) {
* ( V_14 ) V_121 = 0 ;
} else if ( V_79 == 1 ) {
* ( V_14 ) V_62 = 0 ;
V_80 = 3 ;
} else if ( V_122 > ( 0x100000000UL >> V_39 ) ) {
* ( V_14 ) V_121 = 0 ;
} else {
* ( V_14 ) V_121 = 0x00000000 | 1 | 8 ;
* ( V_14 ) V_123 = 0xfff00000 ;
* ( V_14 ) V_124 = 0 >> 2 ;
V_59 . V_72 = 0x200000000UL ;
* ( V_14 ) V_73 = V_59 . V_72 >> 32 ;
}
F_19 ( V_80 ) ;
}
void T_5
F_37 ( void )
{
F_32 ( 0 ) ;
}
void T_5
F_38 ( void )
{
unsigned int V_125 , V_126 ;
unsigned long V_127 ;
__asm__ __volatile__ ("rpcc %0" : "=r"(cc0));
V_127 = * ( V_128 ) V_129 ;
do { } while( * ( V_128 ) V_129 - V_127 < 4096 );
__asm__ __volatile__ ("rpcc %0" : "=r"(cc1));
V_126 -= V_125 ;
V_130 -> V_131 = ( ( V_126 >> 11 ) * 100000000UL ) / 3 ;
F_39 ( V_130 ) ;
F_32 ( 1 ) ;
}
void
F_40 ( int V_132 )
{
if ( V_83 )
F_31 () ;
}
void T_5
F_41 ( void )
{
F_25 () ;
F_42 () ;
}
static inline void
F_43 ( void )
{
int V_133 ;
V_133 = * ( V_14 ) V_15 ;
* ( V_14 ) V_15 = V_133 ;
F_5 () ;
* ( V_14 ) V_15 ;
}
static void
F_44 ( struct V_134 * V_135 , const char * V_136 )
{
static const char * const V_137 [ 16 ] = {
L_32 , L_33 , L_34 ,
L_35 , L_36 , L_37 , L_38 ,
L_39 , L_40 , L_41 ,
L_42 , L_43 ,
L_44 , L_45 ,
L_46 , L_47
} ;
if ( V_135 -> V_138 & ( V_139
| V_140
| V_85
| V_86 ) ) {
static const char * const V_141 [ 6 ] = {
L_48 , L_49 , L_50 ,
L_51 , L_52 , L_53
} ;
const char * V_34 ;
const char * V_142 ;
unsigned long V_9 , V_143 ;
int V_144 , V_145 ;
V_142 = V_137 [ V_135 -> V_146 & 0x7 ] ;
V_144 = ( V_135 -> V_146 >> 4 ) & 1 ;
V_145 = ( V_135 -> V_146 >> 5 ) & 1 ;
V_143 = ( V_135 -> V_146 >> 8 ) & 0x1F ;
V_143 = F_45 ( V_143 ) ;
V_34 = V_141 [ V_143 ] ;
V_9 = V_135 -> V_147 ;
if ( V_145 ) {
V_143 = * ( V_14 ) V_73 & 0xFFUL ;
V_9 |= V_143 << 32 ;
}
F_29 ( V_148 L_54 , V_136 ) ;
F_29 ( V_148 L_55 , V_142 ) ;
F_29 ( V_148 L_56 , V_9 ) ;
F_29 ( V_148 L_57 ,
V_34 , V_144 , V_145 ) ;
} else if ( V_135 -> V_138 & ( V_149
| V_150
| V_87
| V_88
| V_151 ) ) {
static const char * const V_152 [ 16 ] = {
L_58 , L_59 , L_60 ,
L_61 , L_62 , L_63 ,
L_64 , L_65 ,
L_66 , L_67 ,
L_68 , L_69 ,
L_70 , L_71 , L_72 ,
L_73
} ;
static const char * const V_153 [ 16 ] = {
L_58 , L_74 , L_75 , L_76 ,
L_65 , L_66 ,
L_67 , L_68 ,
L_77 , L_78 ,
L_79 , L_69 , L_70 ,
L_71 , L_72 , L_73
} ;
const char * V_142 ;
const char * V_154 , * V_155 ;
unsigned long V_9 , V_143 ;
int V_145 ;
V_154 = V_152 [ ( V_135 -> V_146 >> 16 ) & 0xF ] ;
V_155 = V_153 [ ( V_135 -> V_146 >> 20 ) & 0xF ] ;
V_142 = V_137 [ ( V_135 -> V_146 >> 24 ) & 0xF ] ;
V_145 = ( V_135 -> V_146 >> 28 ) & 1 ;
V_9 = V_135 -> V_156 ;
if ( V_145 ) {
V_143 = * ( volatile int * ) V_73 & 0xFFUL ;
V_9 |= V_143 << 32 ;
}
F_29 ( V_148 L_54 , V_136 ) ;
F_29 ( V_148 L_80 , V_142 ) ;
F_29 ( V_148 L_81 ,
V_154 , V_155 ) ;
F_29 ( V_148 L_82 ,
V_9 , V_145 ) ;
} else {
F_29 ( V_148 L_54 , V_136 ) ;
F_29 ( V_148 L_83 ) ;
F_29 ( V_148 L_84 , V_135 -> V_146 ) ;
F_29 ( V_148 L_85 , V_135 -> V_147 ) ;
F_29 ( V_148 L_86 , V_135 -> V_156 ) ;
}
}
static void
F_46 ( struct V_134 * V_135 , const char * V_136 )
{
unsigned long V_157 ;
unsigned long V_158 ;
const char * V_159 ;
const char * V_160 ;
const char * V_161 ;
unsigned long V_143 ;
if ( ( V_135 -> V_162 >> 20 ) & 1 )
F_44 ( V_135 , V_136 ) ;
else
F_29 ( V_148 L_54 , V_136 ) ;
V_157 = V_135 -> V_163 & 0xfffffff0 ;
V_157 |= ( V_135 -> V_162 & 0x83UL ) << 32 ;
V_158 = ( V_135 -> V_162 >> 12 ) & 0xF ;
V_143 = ( V_135 -> V_162 >> 8 ) & 0xF ;
V_143 |= ( ( V_135 -> V_162 >> 20 ) & 1 ) << 4 ;
if ( ( V_143 & 0x1E ) == 0x06 )
V_159 = L_87 ;
else if ( ( V_143 & 0x1C ) == 0x08 )
V_159 = L_88 ;
else if ( V_143 == 0x1C )
V_159 = L_89 ;
else if ( ( V_143 & 0x1E ) == 0x0E )
V_159 = L_90 ;
else if ( ( V_143 & 0x1C ) == 0x18 )
V_159 = L_91 ;
else if ( ( V_143 & 0x1E ) == 0x12 )
V_159 = L_92 ;
else
V_159 = L_93 ;
V_143 = ( V_135 -> V_162 >> 16 ) & 0xF ;
switch ( V_143 ) {
case 0x0 :
V_160 = L_58 ;
break;
case 0x1 :
V_160 = L_94 ;
break;
case 0x2 : case 0x3 :
V_160 = L_95 ;
break;
case 0x4 : case 0x5 : case 0x6 :
V_160 = L_96 ;
break;
case 0x8 : case 0x9 : case 0xB :
V_160 = L_97 ;
break;
case 0xC :
V_160 = L_98 ;
break;
case 0xE : case 0xF :
V_160 = L_99 ;
break;
default:
V_160 = L_93 ;
break;
}
V_143 = ( V_135 -> V_162 >> 24 ) & 0x1F ;
switch ( V_143 ) {
case 0x00 : V_161 = L_100 ; break;
case 0x01 : V_161 = L_101 ; break;
case 0x02 : V_161 = L_102 ; break;
case 0x03 : V_161 = L_103 ; break;
case 0x04 : V_161 = L_104 ; break;
case 0x05 : V_161 = L_105 ; break;
case 0x06 : V_161 = L_106 ; break;
case 0x07 : V_161 = L_107 ; break;
case 0x08 : V_161 = L_108 ; break;
case 0x09 : V_161 = L_109 ; break;
case 0x0A : V_161 = L_110 ; break;
case 0x0B : V_161 = L_111 ; break;
case 0x0C : V_161 = L_112 ; break;
case 0x0D : V_161 = L_113 ; break;
case 0x0E : V_161 = L_114 ; break;
case 0x0F : V_161 = L_115 ; break;
case 0x10 : V_161 = L_116 ; break;
case 0x1F : V_161 = L_117 ; break;
default: V_161 = L_93 ; break;
}
F_29 ( V_148 L_118 , V_159 ) ;
F_29 ( V_148 L_119 ,
V_157 , V_158 ) ;
F_29 ( V_148 L_120 , V_160 ) ;
F_29 ( V_148 L_121 , V_161 ) ;
}
static void
F_47 ( struct V_134 * V_135 , const char * V_136 )
{
long V_164 ;
long V_37 ;
const char * V_165 ;
F_46 ( V_135 , V_136 ) ;
V_164 = V_135 -> V_166 & 0xff ;
if ( V_164 == ( V_164 & - V_164 ) ) {
V_165 = V_148 L_122 ;
V_37 = F_45 ( V_164 ) - 1 ;
} else {
static unsigned char const V_167 [ 64 ] = {
0xCE , 0xCB , 0xD3 , 0xD5 ,
0xD6 , 0xD9 , 0xDA , 0xDC ,
0x23 , 0x25 , 0x26 , 0x29 ,
0x2A , 0x2C , 0x31 , 0x34 ,
0x0E , 0x0B , 0x13 , 0x15 ,
0x16 , 0x19 , 0x1A , 0x1C ,
0xE3 , 0xE5 , 0xE6 , 0xE9 ,
0xEA , 0xEC , 0xF1 , 0xF4 ,
0x4F , 0x4A , 0x52 , 0x54 ,
0x57 , 0x58 , 0x5B , 0x5D ,
0xA2 , 0xA4 , 0xA7 , 0xA8 ,
0xAB , 0xAD , 0xB0 , 0xB5 ,
0x8F , 0x8A , 0x92 , 0x94 ,
0x97 , 0x98 , 0x9B , 0x9D ,
0x62 , 0x64 , 0x67 , 0x68 ,
0x6B , 0x6D , 0x70 , 0x75
} ;
for ( V_37 = 0 ; V_37 < 64 ; ++ V_37 )
if ( V_167 [ V_37 ] == V_164 )
break;
if ( V_37 < 64 )
V_165 = V_148 L_123 ;
else
V_165 = V_148 L_124 ;
}
F_29 ( V_165 , V_164 , V_37 ) ;
}
static void
F_48 ( struct V_134 * V_135 )
{
static const char * const V_168 [ 16 ] = {
L_125 , L_126 , L_127 , L_128 , L_129 ,
L_130 , L_131 , L_132 ,
L_133 , L_134 , L_135 ,
L_136 , L_137 , L_138 ,
L_139 , L_140
} ;
unsigned long V_9 ;
unsigned long V_19 ;
const char * V_142 ;
int V_169 ;
V_9 = V_135 -> V_170 & 0xfffffff0 ;
V_9 |= ( V_135 -> V_171 & 0x83UL ) << 32 ;
V_142 = V_168 [ ( V_135 -> V_171 >> 8 ) & 0xF ] ;
V_19 = ( V_135 -> V_171 >> 12 ) & 0xF ;
V_169 = ( V_135 -> V_171 >> 21 ) & 1 ;
F_29 ( V_148 L_141 ) ;
F_29 ( V_148 L_142 , V_142 , V_169 ) ;
F_29 ( V_148 L_143 , V_9 , V_19 ) ;
}
static int
F_49 ( unsigned long V_172 )
{
struct V_173 * V_174 ;
struct V_134 * V_135 ;
V_174 = ( void * ) V_172 ;
V_135 = ( void * ) ( V_172 + V_174 -> V_175 ) ;
if ( ( V_135 -> V_138 & V_176 ) == 0 )
return 0 ;
#ifdef F_50
if ( ! V_177 )
return 1 ;
switch ( F_45 ( V_135 -> V_138 & 0xfff ) - 1 ) {
case 0 :
F_47 ( V_135 , L_144 ) ;
break;
case 1 :
F_47 ( V_135 , L_145 ) ;
break;
case 2 :
F_48 ( V_135 ) ;
break;
case 3 :
F_46 ( V_135 , L_146 ) ;
break;
case 4 :
F_44 ( V_135 , L_147 ) ;
break;
case 5 :
F_44 ( V_135 , L_148 ) ;
break;
case 6 :
F_44 ( V_135 , L_149 ) ;
break;
case 7 :
F_44 ( V_135 , L_150 ) ;
break;
case 8 :
F_44 ( V_135 , L_151 ) ;
break;
case 9 :
F_44 ( V_135 , L_152 ) ;
break;
case 10 :
F_46 ( V_135 , L_153 ) ;
break;
case 11 :
F_44 ( V_135 , L_154 ) ;
break;
}
if ( V_135 -> V_138 & V_178 )
F_29 ( V_148 L_155
L_156 ) ;
if ( V_135 -> V_138 & V_179 )
F_29 ( V_148 L_155
L_157 ) ;
if ( V_135 -> V_138 & V_180 )
F_29 ( V_148 L_155
L_158 ) ;
if ( V_135 -> V_138 & V_181 )
F_29 ( V_148 L_155
L_159 ) ;
if ( V_135 -> V_138 & V_182 )
F_29 ( V_148 L_155
L_160 ) ;
if ( V_135 -> V_138 & V_183 )
F_29 ( V_148 L_155
L_161 ) ;
if ( V_135 -> V_138 & V_184 )
F_29 ( V_148 L_155
L_162 ) ;
if ( V_135 -> V_138 & V_185 )
F_29 ( V_148 L_155
L_163 ) ;
if ( V_135 -> V_138 & V_186 )
F_29 ( V_148 L_155
L_164 ) ;
if ( V_135 -> V_138 & V_187 )
F_29 ( V_148 L_155
L_165 ) ;
if ( V_135 -> V_138 & V_188 )
F_29 ( V_148 L_155
L_166 ) ;
#endif
return 1 ;
}
void
F_51 ( unsigned long V_189 , unsigned long V_172 )
{
int V_190 ;
F_5 () ;
F_5 () ;
F_6 () ;
F_43 () ;
F_52 ( F_53 () ) ;
F_5 () ;
V_190 = F_7 ( 0 ) ;
if ( ! V_190 && V_189 == 0x660 )
V_190 = F_49 ( V_172 ) ;
F_54 ( V_189 , V_172 , L_167 , V_190 ) ;
}
