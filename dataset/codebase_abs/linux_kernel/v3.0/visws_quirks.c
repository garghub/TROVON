static void T_1 F_1 ( void )
{
F_2 ( V_1 L_1 ) ;
F_3 ( V_2 , V_3 / V_4 ) ;
F_3 ( V_5 , F_4 ( V_5 ) | V_6 ) ;
F_3 ( V_5 , F_4 ( V_5 ) & ~ V_7 ) ;
F_5 () ;
}
static char * T_1 F_6 ( void )
{
long long V_8 = 8 * V_9 ;
V_10 = V_11 . V_12 ;
if ( ! V_10 ) {
F_2 ( V_13 L_2 ) ;
V_10 = 128 * V_9 ;
}
if ( ! V_14 ) {
F_2 ( V_13 L_3 ) ;
V_14 = 8 * V_9 ;
}
V_14 &= ~ ( ( 1 << 20 ) - 1 ) ;
V_15 = V_10 - V_8 ;
F_7 ( 0 , F_8 () , V_16 ) ;
F_7 ( V_17 , V_10 - V_14 - V_17 , V_16 ) ;
F_7 ( V_15 , V_14 , V_18 ) ;
return L_4 ;
}
static void F_9 ( void )
{
F_10 ( V_19 , V_20 ) ;
}
static void F_11 ( void )
{
unsigned short V_21 ;
while ( ( V_21 = F_12 ( V_22 ) ) & 0x100 )
F_13 ( V_21 , V_22 ) ;
F_13 ( V_23 , V_24 ) ;
F_14 ( 10 ) ;
#define F_15 ( T_2 , T_3 , T_4 ) \
(0x80000000 | (bus << 16) | (devfn << 8) | (reg & ~3))
F_16 ( V_25 , 0xCFC ) ;
}
static void T_1 F_17 ( unsigned int V_26 )
{
}
static void T_1 F_18 ( struct V_27 * V_28 )
{
int V_29 , V_30 ;
T_5 V_31 ;
if ( ! ( V_28 -> V_32 & V_33 ) )
return;
V_30 = V_28 -> V_34 ;
F_2 ( V_1 L_5 ,
V_28 -> V_32 & V_35 ? L_6 : L_7 ,
V_28 -> V_34 , ( V_28 -> V_36 & V_37 ) >> 8 ,
( V_28 -> V_36 & V_38 ) >> 4 , V_28 -> V_39 ) ;
if ( V_28 -> V_32 & V_35 )
V_40 = V_28 -> V_34 ;
V_29 = V_28 -> V_39 ;
if ( ( V_29 >= 0x14 && V_28 -> V_34 >= 0xff ) || V_28 -> V_34 >= 0xf ) {
F_2 ( V_41 L_8 ,
V_28 -> V_34 , V_42 ) ;
return;
}
V_43 -> V_44 ( V_28 -> V_34 , & V_31 ) ;
F_19 ( V_45 , V_45 , V_31 ) ;
if ( V_29 == 0x0 ) {
F_2 ( V_41 L_9
L_10 ,
V_28 -> V_34 ) ;
V_29 = 0x10 ;
}
V_46 [ V_28 -> V_34 ] = V_29 ;
}
static void T_1 F_20 ( void )
{
struct V_27 * V_47 = F_21 ( V_48 ) ;
unsigned short V_49 = F_22 ( F_21 ( V_50 ) ) ;
if ( V_49 > V_51 ) {
F_2 ( V_13 L_11 ,
V_49 , V_47 ) ;
V_49 = V_51 ;
}
if ( V_49 > V_52 )
V_49 = V_52 ;
#ifdef F_23
V_53 = 1 ;
#endif
while ( V_49 -- )
F_18 ( V_47 ++ ) ;
V_54 = V_55 ;
}
void T_1 F_24 ( void )
{
int V_56 ;
V_57 = ( char ) ( F_25 ( V_58 ) & V_58 )
>> V_59 ;
if ( V_57 < 0 )
return;
V_60 . V_61 . V_62 = F_6 ;
V_60 . V_63 . V_64 = F_17 ;
V_60 . V_63 . V_65 = F_20 ;
V_60 . V_66 . V_67 = V_68 ;
V_60 . V_66 . V_69 = V_70 ;
V_60 . V_71 . V_72 = F_1 ;
V_60 . V_73 . V_74 = V_75 ;
V_60 . V_73 . V_76 = V_77 ;
V_78 = F_11 ;
V_79 . V_80 = F_9 ;
V_81 = 0 ;
#ifdef F_26
V_82 = 1 ;
#endif
F_27 ( V_83 , V_84 ) ;
F_27 ( V_85 , V_86 ) ;
F_27 ( V_87 , V_84 ) ;
F_27 ( V_88 , V_86 ) ;
F_27 ( V_89 , V_84 ) ;
F_27 ( V_90 , V_86 ) ;
F_27 ( V_91 , V_84 ) ;
F_27 ( 1 , V_86 ) ;
F_27 ( V_83 , V_84 ) ;
F_27 ( V_92 , V_86 ) ;
F_27 ( V_87 , V_84 ) ;
F_27 ( V_93 , V_86 ) ;
F_27 ( V_89 , V_84 ) ;
F_27 ( V_94 , V_86 ) ;
F_27 ( V_91 , V_84 ) ;
F_27 ( 1 , V_86 ) ;
F_27 ( V_95 , V_96 ) ;
F_27 ( V_97 , V_98 ) ;
V_56 = F_25 ( V_99 ) ;
V_56 &= 0x7f ;
if ( V_57 == V_100 ) {
if ( V_56 < 0x6 ) {
V_101 = 4 ;
} else if ( V_56 < 0xc ) {
V_101 = 5 ;
} else {
V_101 = 6 ;
}
} else if ( V_57 == V_102 ) {
V_101 = 2 ;
} else {
V_101 = V_56 ;
}
F_2 ( V_1 L_12 ,
( V_57 == V_100 ? L_13 :
( V_57 == V_102 ? L_14 :
L_15 ) ) , V_101 ) ;
}
static T_1 void F_28 ( void )
{
F_29 ( V_103 , V_104 ) ;
F_29 ( V_105 , V_106 ) ;
if ( ( F_30 ( V_107 ) != V_108 ) ||
( F_30 ( V_109 ) != V_110 ) ) {
F_2 ( V_111 L_16 , 'A' ) ;
}
if ( ( F_31 ( V_107 ) != V_108 ) ||
( F_31 ( V_109 ) != V_110 ) ) {
F_2 ( V_111 L_16 , 'B' ) ;
}
F_32 ( V_112 , V_113 ) ;
F_33 ( V_112 , V_113 ) ;
}
static T_1 void F_34 ( void )
{
F_29 ( V_114 , V_55 ) ;
F_35 () ;
F_2 ( V_1 L_17 ,
( unsigned int ) F_36 ( V_115 ) ,
( unsigned int ) F_36 ( V_116 ) ) ;
F_29 ( V_117 , V_118 ) ;
F_29 ( V_119 , V_120 ) ;
F_2 ( V_1 L_18 ,
F_4 ( V_121 ) , F_37 ( V_122 ) ) ;
F_38 ( V_122 , F_37 ( V_122 ) | V_123 ) ;
F_2 ( V_1 L_19 ,
F_37 ( V_122 ) ) ;
}
static void T_1 V_70 ( void )
{
F_28 () ;
F_34 () ;
}
static inline void F_39 ( int V_124 , int V_125 )
{
F_38 ( F_40 ( V_124 ) , V_126 | ( V_125 + V_127 ) ) ;
F_38 ( F_41 ( V_124 ) , 0 ) ;
}
static inline int F_42 ( void )
{
extern char V_57 ;
extern char V_101 ;
if ( V_57 == V_100 && V_101 == 5 )
return 5 ;
return V_128 ;
}
static int F_43 ( unsigned int V_125 )
{
if ( F_44 ( V_125 ) )
return F_45 ( V_125 ) ;
switch ( V_125 ) {
case 0 : return V_129 ;
case V_130 : return F_42 () ;
case V_131 : return V_132 ;
default: return - 1 ;
}
}
static void F_46 ( struct V_133 * V_134 )
{
F_39 ( F_43 ( V_134 -> V_125 ) , V_134 -> V_125 ) ;
}
static void F_47 ( struct V_133 * V_134 )
{
int V_124 = F_43 ( V_134 -> V_125 ) ;
F_38 ( F_40 ( V_124 ) , V_135 ) ;
F_37 ( F_40 ( V_124 ) ) ;
}
static void F_48 ( struct V_133 * V_134 )
{
unsigned long V_136 ;
F_49 ( & V_137 , V_136 ) ;
F_47 ( V_134 ) ;
F_50 ( V_138 , V_139 ) ;
F_51 ( & V_137 , V_136 ) ;
}
static unsigned int F_52 ( struct V_133 * V_134 )
{
V_140 -> V_74 ( 0 ) ;
F_46 ( V_134 ) ;
return 0 ;
}
static void F_53 ( struct V_133 * V_134 ) { }
static T_6 F_54 ( int V_125 , void * V_141 )
{
unsigned long V_136 ;
int V_142 ;
F_55 ( & V_143 , V_136 ) ;
F_10 ( 0x0c , 0x20 ) ;
V_142 = F_56 ( 0x20 ) ;
if ( F_57 ( ! ( V_142 & 0x80 ) ) )
goto V_144;
V_142 &= 7 ;
if ( F_57 ( V_142 == 2 ) ) {
F_10 ( 0x0c , 0xa0 ) ;
V_142 = F_56 ( 0xa0 ) ;
if ( F_57 ( ! ( V_142 & 0x80 ) ) )
goto V_144;
V_142 = ( V_142 & 7 ) + 8 ;
}
V_145 |= 1 << V_142 ;
if ( F_57 ( V_142 > 7 ) ) {
F_56 ( 0xa1 ) ;
F_10 ( V_146 , 0xa1 ) ;
F_10 ( 0x60 + ( V_142 & 7 ) , 0xa0 ) ;
F_10 ( 0x60 + 2 , 0x20 ) ;
} else {
F_56 ( 0x21 ) ;
F_10 ( V_147 , 0x21 ) ;
F_10 ( 0x60 + V_142 , 0x20 ) ;
}
F_58 ( & V_143 , V_136 ) ;
F_59 ( V_142 ) ;
return V_148 ;
V_144:
F_58 ( & V_143 , V_136 ) ;
return V_149 ;
}
static inline void F_60 ( void )
{
V_150 . V_151 = V_152 . V_153 ;
V_150 . V_154 = V_152 . V_155 ;
V_150 . V_153 = V_152 . V_153 ;
}
static void T_1 V_68 ( void )
{
int V_156 ;
F_60 () ;
for ( V_156 = 0 ; V_156 < V_157 + V_158 + 1 ; V_156 ++ ) {
struct V_159 * V_160 = NULL ;
if ( V_156 == 0 )
V_160 = & V_161 ;
else if ( V_156 == V_130 )
V_160 = & V_161 ;
else if ( V_156 == V_131 )
V_160 = & V_161 ;
else if ( V_156 == V_162 )
V_160 = & V_163 ;
else if ( V_156 < V_157 )
V_160 = & V_150 ;
else if ( F_44 ( V_156 ) )
V_160 = & V_161 ;
if ( V_160 )
F_61 ( V_156 , V_160 ) ;
}
F_62 ( V_162 , & V_164 ) ;
F_62 ( 2 , & V_165 ) ;
}
