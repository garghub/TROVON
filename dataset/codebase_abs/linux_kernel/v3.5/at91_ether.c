static inline unsigned long F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned int V_3 , unsigned long V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
V_6 = F_1 ( V_2 , V_7 ) ;
F_3 ( V_2 , V_7 , V_6 | V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
V_6 = F_1 ( V_2 , V_7 ) ;
F_3 ( V_2 , V_7 , V_6 & ~ V_8 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
unsigned long V_9 = V_10 + 2 ;
while ( ! ( F_1 ( V_2 , V_11 ) & V_12 ) ) {
if ( F_8 ( V_10 , V_9 ) ) {
F_9 ( L_1 ) ;
break;
}
F_10 () ;
}
}
static void F_11 ( struct V_1 * V_2 , unsigned char V_13 , unsigned char V_14 , unsigned int V_5 )
{
F_3 ( V_2 , V_15 , V_16 | V_17
| ( ( V_13 & 0x1f ) << 23 ) | ( V_14 << 18 ) | ( V_5 & V_18 ) ) ;
F_7 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned char V_13 , unsigned char V_14 , unsigned int * V_5 )
{
F_3 ( V_2 , V_15 , V_16 | V_19
| ( ( V_13 & 0x1f ) << 23 ) | ( V_14 << 18 ) ) ;
F_7 ( V_2 ) ;
* V_5 = F_1 ( V_2 , V_15 ) & V_18 ;
}
static void F_13 ( struct V_20 * V_21 , int V_22 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
unsigned int V_23 , V_24 , V_25 , V_26 ;
unsigned int V_27 , V_28 ;
if ( ! F_15 ( & V_2 -> V_29 ) ) {
F_16 ( V_21 ) ;
if ( ! V_22 )
F_9 ( V_30 L_2 , V_21 -> V_31 ) ;
return;
}
F_12 ( V_2 , V_2 -> V_32 , V_33 , & V_23 ) ;
F_12 ( V_2 , V_2 -> V_32 , V_34 , & V_24 ) ;
if ( V_24 & V_35 ) {
if ( ! ( V_23 & V_36 ) )
return;
F_12 ( V_2 , V_2 -> V_32 , V_37 , & V_25 ) ;
if ( ( V_25 & V_38 ) || ( V_25 & V_39 ) ) V_27 = V_40 ;
else V_27 = V_41 ;
if ( ( V_25 & V_38 ) || ( V_25 & V_42 ) ) V_28 = V_43 ;
else V_28 = V_44 ;
} else {
V_27 = ( V_24 & V_45 ) ? V_40 : V_41 ;
V_28 = ( V_24 & V_46 ) ? V_43 : V_44 ;
}
V_26 = F_1 ( V_2 , V_47 ) & ~ ( V_48 | V_49 ) ;
if ( V_27 == V_40 ) {
if ( V_28 == V_43 )
V_26 |= V_48 | V_49 ;
else
V_26 |= V_48 ;
} else {
if ( V_28 == V_43 )
V_26 |= V_49 ;
else {}
}
F_3 ( V_2 , V_47 , V_26 ) ;
if ( ! V_22 )
F_9 ( V_30 L_3 , V_21 -> V_31 , V_27 , ( V_28 == V_43 ) ? L_4 : L_5 ) ;
F_17 ( V_21 ) ;
}
static T_1 F_18 ( int V_50 , void * V_51 )
{
struct V_20 * V_21 = (struct V_20 * ) V_51 ;
struct V_1 * V_2 = F_14 ( V_21 ) ;
unsigned int V_52 ;
F_5 ( V_2 ) ;
if ( ( V_2 -> V_53 == V_54 ) || ( V_2 -> V_53 == V_55 ) ) {
F_12 ( V_2 , V_2 -> V_32 , V_56 , & V_52 ) ;
if ( ! ( V_52 & ( 1 << 0 ) ) )
goto V_57;
}
else if ( V_2 -> V_53 == V_58 ) {
F_12 ( V_2 , V_2 -> V_32 , V_59 , & V_52 ) ;
if ( ! ( V_52 & ( 1 << 2 ) ) )
goto V_57;
}
else if ( V_2 -> V_53 == V_60 ) {
F_12 ( V_2 , V_2 -> V_32 , V_61 , & V_52 ) ;
if ( ! ( V_52 & ( 1 << 0 ) ) )
goto V_57;
}
else if ( V_2 -> V_53 == V_62 ) {
F_12 ( V_2 , V_2 -> V_32 , V_63 , & V_52 ) ;
if ( ! ( V_52 & ( ( 1 << 2 ) | 1 ) ) )
goto V_57;
}
else if ( V_2 -> V_53 == V_64 ) {
F_12 ( V_2 , V_2 -> V_32 , V_65 , & V_52 ) ;
if ( ! ( V_52 & ( ( 1 << 2 ) | 1 ) ) )
goto V_57;
}
else if ( V_2 -> V_53 == V_66 ) {
F_12 ( V_2 , V_2 -> V_32 , V_67 , & V_52 ) ;
if ( ! ( V_52 & ( 1 << 7 ) ) )
goto V_57;
}
F_13 ( V_21 , 0 ) ;
V_57:
F_6 ( V_2 ) ;
return V_68 ;
}
static void F_19 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
unsigned int V_69 , V_70 ;
int V_71 ;
if ( ! F_20 ( V_2 -> V_72 . V_73 ) ) {
F_21 ( & V_2 -> V_74 , V_10 + V_75 ) ;
return;
}
V_70 = F_22 ( V_2 -> V_72 . V_73 ) ;
V_71 = F_23 ( V_70 , F_18 , 0 , V_21 -> V_31 , V_21 ) ;
if ( V_71 ) {
F_9 ( V_76 L_6 , V_70 , V_71 ) ;
return;
}
F_24 ( & V_2 -> V_77 ) ;
F_5 ( V_2 ) ;
if ( ( V_2 -> V_53 == V_54 ) || ( V_2 -> V_53 == V_55 ) ) {
F_12 ( V_2 , V_2 -> V_32 , V_56 , & V_69 ) ;
V_69 = V_69 & ~ 0xf00 ;
F_11 ( V_2 , V_2 -> V_32 , V_56 , V_69 ) ;
}
else if ( V_2 -> V_53 == V_58 ) {
F_12 ( V_2 , V_2 -> V_32 , V_78 , & V_69 ) ;
V_69 = V_69 | 0xf2 ;
F_11 ( V_2 , V_2 -> V_32 , V_78 , V_69 ) ;
}
else if ( V_2 -> V_53 == V_60 ) {
V_69 = ( 1 << 15 ) | ( 1 << 14 ) ;
F_11 ( V_2 , V_2 -> V_32 , V_61 , V_69 ) ;
}
else if ( V_2 -> V_53 == V_62 ) {
V_69 = ( 1 << 10 ) | ( 1 << 8 ) ;
F_11 ( V_2 , V_2 -> V_32 , V_63 , V_69 ) ;
}
else if ( V_2 -> V_53 == V_64 ) {
F_12 ( V_2 , V_2 -> V_32 , V_65 , & V_69 ) ;
V_69 = V_69 | 0x500 ;
F_11 ( V_2 , V_2 -> V_32 , V_65 , V_69 ) ;
}
else if ( V_2 -> V_53 == V_66 ) {
F_12 ( V_2 , V_2 -> V_32 , V_79 , & V_69 ) ;
V_69 = V_69 | 0x3c ;
F_11 ( V_2 , V_2 -> V_32 , V_79 , V_69 ) ;
F_12 ( V_2 , V_2 -> V_32 , V_80 , & V_69 ) ;
V_69 = V_69 | 0x3 ;
F_11 ( V_2 , V_2 -> V_32 , V_80 , V_69 ) ;
}
F_6 ( V_2 ) ;
F_25 ( & V_2 -> V_77 ) ;
}
static void F_26 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
unsigned int V_69 ;
unsigned int V_70 ;
if ( ! F_20 ( V_2 -> V_72 . V_73 ) ) {
F_27 ( & V_2 -> V_74 ) ;
return;
}
F_24 ( & V_2 -> V_77 ) ;
F_5 ( V_2 ) ;
if ( ( V_2 -> V_53 == V_54 ) || ( V_2 -> V_53 == V_55 ) ) {
F_12 ( V_2 , V_2 -> V_32 , V_56 , & V_69 ) ;
V_69 = V_69 | 0xf00 ;
F_11 ( V_2 , V_2 -> V_32 , V_56 , V_69 ) ;
}
else if ( V_2 -> V_53 == V_58 ) {
F_12 ( V_2 , V_2 -> V_32 , V_78 , & V_69 ) ;
V_69 = V_69 & ~ 0xf2 ;
F_11 ( V_2 , V_2 -> V_32 , V_78 , V_69 ) ;
}
else if ( V_2 -> V_53 == V_60 ) {
F_12 ( V_2 , V_2 -> V_32 , V_61 , & V_69 ) ;
V_69 = ~ ( 1 << 14 ) ;
F_11 ( V_2 , V_2 -> V_32 , V_61 , V_69 ) ;
}
else if ( V_2 -> V_53 == V_62 ) {
F_12 ( V_2 , V_2 -> V_32 , V_63 , & V_69 ) ;
V_69 = ~ ( ( 1 << 10 ) | ( 1 << 8 ) ) ;
F_11 ( V_2 , V_2 -> V_32 , V_63 , V_69 ) ;
}
else if ( V_2 -> V_53 == V_64 ) {
F_12 ( V_2 , V_2 -> V_32 , V_65 , & V_69 ) ;
V_69 = V_69 & ~ 0x500 ;
F_11 ( V_2 , V_2 -> V_32 , V_65 , V_69 ) ;
}
else if ( V_2 -> V_53 == V_66 ) {
F_12 ( V_2 , V_2 -> V_32 , V_80 , & V_69 ) ;
V_69 = V_69 & ~ 0x3 ;
F_11 ( V_2 , V_2 -> V_32 , V_80 , V_69 ) ;
F_12 ( V_2 , V_2 -> V_32 , V_79 , & V_69 ) ;
V_69 = V_69 & ~ 0x3c ;
F_11 ( V_2 , V_2 -> V_32 , V_79 , V_69 ) ;
}
F_6 ( V_2 ) ;
F_25 ( & V_2 -> V_77 ) ;
V_70 = F_22 ( V_2 -> V_72 . V_73 ) ;
F_28 ( V_70 , V_21 ) ;
}
static void F_29 ( unsigned long V_51 )
{
struct V_20 * V_21 = (struct V_20 * ) V_51 ;
struct V_1 * V_2 = F_14 ( V_21 ) ;
F_5 ( V_2 ) ;
F_13 ( V_21 , 1 ) ;
F_6 ( V_2 ) ;
F_21 ( & V_2 -> V_74 , V_10 + V_75 ) ;
}
static void T_2 F_30 ( struct V_1 * V_2 )
{
unsigned int V_81 ;
F_24 ( & V_2 -> V_77 ) ;
F_5 ( V_2 ) ;
if ( ( V_2 -> V_53 == V_54 ) || ( V_2 -> V_53 == V_55 ) ) {
F_12 ( V_2 , V_2 -> V_32 , V_82 , & V_81 ) ;
if ( ( V_81 & ( 1 << 10 ) ) == 0 )
V_2 -> V_83 = V_84 ;
} else if ( F_31 () ) {
F_11 ( V_2 , V_2 -> V_32 , V_85 , 0x0d22 ) ;
} else if ( F_32 () )
F_11 ( V_2 , V_2 -> V_32 , V_85 , 0x156A ) ;
F_6 ( V_2 ) ;
F_25 ( & V_2 -> V_77 ) ;
}
static short T_2 F_33 ( struct V_20 * V_21 , unsigned int V_86 , unsigned int V_87 )
{
char V_88 [ 6 ] ;
if ( F_31 () ) {
V_88 [ 5 ] = ( V_87 & 0xff ) ;
V_88 [ 4 ] = ( V_87 & 0xff00 ) >> 8 ;
V_88 [ 3 ] = ( V_87 & 0xff0000 ) >> 16 ;
V_88 [ 2 ] = ( V_87 & 0xff000000 ) >> 24 ;
V_88 [ 1 ] = ( V_86 & 0xff ) ;
V_88 [ 0 ] = ( V_86 & 0xff00 ) >> 8 ;
}
else {
V_88 [ 0 ] = ( V_87 & 0xff ) ;
V_88 [ 1 ] = ( V_87 & 0xff00 ) >> 8 ;
V_88 [ 2 ] = ( V_87 & 0xff0000 ) >> 16 ;
V_88 [ 3 ] = ( V_87 & 0xff000000 ) >> 24 ;
V_88 [ 4 ] = ( V_86 & 0xff ) ;
V_88 [ 5 ] = ( V_86 & 0xff00 ) >> 8 ;
}
if ( F_34 ( V_88 ) ) {
memcpy ( V_21 -> V_89 , & V_88 , 6 ) ;
return 1 ;
}
return 0 ;
}
static void T_2 F_35 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
if ( F_33 ( V_21 , F_1 ( V_2 , V_90 ) , F_1 ( V_2 , V_91 ) ) )
return;
if ( F_33 ( V_21 , F_1 ( V_2 , V_92 ) , F_1 ( V_2 , V_93 ) ) )
return;
if ( F_33 ( V_21 , F_1 ( V_2 , V_94 ) , F_1 ( V_2 , V_95 ) ) )
return;
if ( F_33 ( V_21 , F_1 ( V_2 , V_96 ) , F_1 ( V_2 , V_97 ) ) )
return;
F_9 ( V_76 L_7 ) ;
}
static void F_36 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
F_3 ( V_2 , V_91 , ( V_21 -> V_89 [ 3 ] << 24 ) | ( V_21 -> V_89 [ 2 ] << 16 ) | ( V_21 -> V_89 [ 1 ] << 8 ) | ( V_21 -> V_89 [ 0 ] ) ) ;
F_3 ( V_2 , V_90 , ( V_21 -> V_89 [ 5 ] << 8 ) | ( V_21 -> V_89 [ 4 ] ) ) ;
F_3 ( V_2 , V_93 , 0 ) ;
F_3 ( V_2 , V_92 , 0 ) ;
}
static int F_37 ( struct V_20 * V_21 , void * V_88 )
{
struct V_98 * V_14 = V_88 ;
if ( ! F_34 ( V_14 -> V_99 ) )
return - V_100 ;
memcpy ( V_21 -> V_89 , V_14 -> V_99 , V_21 -> V_101 ) ;
F_36 ( V_21 ) ;
F_9 ( L_8 , V_21 -> V_31 ,
V_21 -> V_89 ) ;
return 0 ;
}
static int inline F_38 ( int V_102 , T_3 * V_88 )
{
if ( V_88 [ V_102 / 8 ] & ( 1 << ( V_102 % 8 ) ) )
return 1 ;
return 0 ;
}
static int F_39 ( T_3 * V_88 )
{
int V_103 , V_104 , V_105 ;
int V_106 = 0 ;
for ( V_104 = 0 ; V_104 < 6 ; V_104 ++ ) {
for ( V_103 = 0 , V_105 = 0 ; V_103 < 8 ; V_103 ++ )
V_105 ^= F_38 ( V_103 * 6 + V_104 , V_88 ) ;
V_106 |= ( V_105 << V_104 ) ;
}
return V_106 ;
}
static void F_40 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
struct V_107 * V_108 ;
unsigned long V_109 [ 2 ] ;
unsigned int V_102 ;
V_109 [ 0 ] = V_109 [ 1 ] = 0 ;
F_41 (ha, dev) {
V_102 = F_39 ( V_108 -> V_88 ) ;
V_109 [ V_102 >> 5 ] |= 1 << ( V_102 & 31 ) ;
}
F_3 ( V_2 , V_110 , V_109 [ 0 ] ) ;
F_3 ( V_2 , V_111 , V_109 [ 1 ] ) ;
}
static void F_42 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
unsigned long V_112 ;
V_112 = F_1 ( V_2 , V_47 ) ;
if ( V_21 -> V_113 & V_114 )
V_112 |= V_115 ;
else if ( V_21 -> V_113 & ( ~ V_114 ) )
V_112 &= ~ V_115 ;
if ( V_21 -> V_113 & V_116 ) {
F_3 ( V_2 , V_111 , - 1 ) ;
F_3 ( V_2 , V_110 , - 1 ) ;
V_112 |= V_117 ;
} else if ( ! F_43 ( V_21 ) ) {
F_40 ( V_21 ) ;
V_112 |= V_117 ;
} else if ( V_21 -> V_113 & ( ~ V_116 ) ) {
F_3 ( V_2 , V_111 , 0 ) ;
F_3 ( V_2 , V_110 , 0 ) ;
V_112 &= ~ V_117 ;
}
F_3 ( V_2 , V_47 , V_112 ) ;
}
static int F_44 ( struct V_20 * V_21 , int V_118 , int V_119 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
unsigned int V_5 ;
F_12 ( V_2 , V_118 , V_119 , & V_5 ) ;
return V_5 ;
}
static void F_45 ( struct V_20 * V_21 , int V_118 , int V_119 , int V_5 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
F_11 ( V_2 , V_118 , V_119 , V_5 ) ;
}
static int F_46 ( struct V_20 * V_21 , struct V_120 * V_121 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
int V_122 ;
F_24 ( & V_2 -> V_77 ) ;
F_5 ( V_2 ) ;
V_122 = F_47 ( & V_2 -> V_29 , V_121 ) ;
F_6 ( V_2 ) ;
F_25 ( & V_2 -> V_77 ) ;
if ( V_2 -> V_83 == V_84 ) {
V_121 -> V_123 = V_124 ;
V_121 -> V_125 = V_84 ;
}
return V_122 ;
}
static int F_48 ( struct V_20 * V_21 , struct V_120 * V_121 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
int V_122 ;
F_24 ( & V_2 -> V_77 ) ;
F_5 ( V_2 ) ;
V_122 = F_49 ( & V_2 -> V_29 , V_121 ) ;
F_6 ( V_2 ) ;
F_25 ( & V_2 -> V_77 ) ;
return V_122 ;
}
static int F_50 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
int V_122 ;
F_24 ( & V_2 -> V_77 ) ;
F_5 ( V_2 ) ;
V_122 = F_51 ( & V_2 -> V_29 ) ;
F_6 ( V_2 ) ;
F_25 ( & V_2 -> V_77 ) ;
return V_122 ;
}
static void F_52 ( struct V_20 * V_21 , struct V_126 * V_127 )
{
F_53 ( V_127 -> V_128 , V_129 , sizeof( V_127 -> V_128 ) ) ;
F_53 ( V_127 -> V_130 , V_131 , sizeof( V_127 -> V_130 ) ) ;
F_53 ( V_127 -> V_132 , F_54 ( V_21 -> V_21 . V_133 ) , sizeof( V_127 -> V_132 ) ) ;
}
static int F_55 ( struct V_20 * V_21 , struct V_134 * V_135 , int V_121 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
int V_136 ;
if ( ! F_56 ( V_21 ) )
return - V_137 ;
F_24 ( & V_2 -> V_77 ) ;
F_5 ( V_2 ) ;
V_136 = F_57 ( & V_2 -> V_29 , F_58 ( V_135 ) , V_121 , NULL ) ;
F_6 ( V_2 ) ;
F_25 ( & V_2 -> V_77 ) ;
return V_136 ;
}
static void F_59 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
struct V_138 * V_139 , * V_140 ;
int V_103 ;
unsigned long V_6 ;
V_139 = V_2 -> V_139 ;
V_140 = V_2 -> V_140 ;
for ( V_103 = 0 ; V_103 < V_141 ; V_103 ++ ) {
V_139 -> V_142 [ V_103 ] . V_88 = ( unsigned int ) & V_140 -> V_143 [ V_103 ] [ 0 ] ;
V_139 -> V_142 [ V_103 ] . V_144 = 0 ;
}
V_139 -> V_142 [ V_103 - 1 ] . V_88 |= V_145 ;
V_2 -> V_146 = 0 ;
F_3 ( V_2 , V_147 , ( unsigned long ) V_140 ) ;
V_6 = F_1 ( V_2 , V_7 ) ;
F_3 ( V_2 , V_7 , V_6 | V_148 | V_149 ) ;
}
static int F_60 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
unsigned long V_6 ;
if ( ! F_34 ( V_21 -> V_89 ) )
return - V_100 ;
F_61 ( V_2 -> V_150 ) ;
V_6 = F_1 ( V_2 , V_7 ) ;
F_3 ( V_2 , V_7 , V_6 | V_151 ) ;
F_36 ( V_21 ) ;
F_19 ( V_21 ) ;
F_3 ( V_2 , V_152 , V_153 | V_154
| V_155 | V_156 | V_157
| V_158 | V_159 ) ;
F_24 ( & V_2 -> V_77 ) ;
F_5 ( V_2 ) ;
F_13 ( V_21 , 0 ) ;
F_6 ( V_2 ) ;
F_25 ( & V_2 -> V_77 ) ;
F_59 ( V_21 ) ;
F_62 ( V_21 ) ;
return 0 ;
}
static int F_63 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
unsigned long V_6 ;
V_6 = F_1 ( V_2 , V_7 ) ;
F_3 ( V_2 , V_7 , V_6 & ~ ( V_149 | V_148 ) ) ;
F_26 ( V_21 ) ;
F_3 ( V_2 , V_160 , V_153 | V_154
| V_155 | V_156 | V_157
| V_158 | V_159 ) ;
F_64 ( V_21 ) ;
F_65 ( V_2 -> V_150 ) ;
return 0 ;
}
static int F_66 ( struct V_161 * V_162 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
if ( F_1 ( V_2 , V_163 ) & V_164 ) {
F_64 ( V_21 ) ;
V_2 -> V_162 = V_162 ;
V_2 -> V_165 = V_162 -> V_166 ;
V_2 -> V_167 = F_67 ( NULL , V_162 -> V_168 , V_162 -> V_166 , V_169 ) ;
V_21 -> V_170 . V_171 += V_162 -> V_166 ;
F_3 ( V_2 , V_172 , V_2 -> V_167 ) ;
F_3 ( V_2 , V_173 , V_162 -> V_166 ) ;
} else {
F_9 ( V_76 L_9 ) ;
return V_174 ;
}
return V_175 ;
}
static struct V_176 * F_68 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
int V_177 , V_178 , V_179 , V_180 , V_181 ;
if ( F_56 ( V_21 ) ) {
V_21 -> V_170 . V_182 += F_1 ( V_2 , V_183 ) ;
V_177 = F_1 ( V_2 , V_184 ) ;
V_21 -> V_170 . V_185 += V_177 ;
V_178 = F_1 ( V_2 , V_186 ) + F_1 ( V_2 , V_187 ) ;
V_21 -> V_170 . V_188 += V_178 ;
V_179 = F_1 ( V_2 , V_189 ) ;
V_21 -> V_170 . V_190 += V_179 ;
V_21 -> V_170 . V_191 += F_1 ( V_2 , V_192 ) ;
V_21 -> V_170 . V_193 += ( V_177 + V_178 + V_179
+ F_1 ( V_2 , V_194 ) + F_1 ( V_2 , V_195 ) ) ;
V_21 -> V_170 . V_196 += F_1 ( V_2 , V_197 ) ;
V_21 -> V_170 . V_198 += F_1 ( V_2 , V_199 ) ;
V_21 -> V_170 . V_200 += F_1 ( V_2 , V_201 ) ;
V_21 -> V_170 . V_202 += F_1 ( V_2 , V_203 ) ;
V_180 = F_1 ( V_2 , V_204 ) ;
V_181 = F_1 ( V_2 , V_205 ) ;
V_21 -> V_170 . V_206 += V_180 ;
V_21 -> V_170 . V_207 += V_181 ;
V_21 -> V_170 . V_208 += ( F_1 ( V_2 , V_209 ) + F_1 ( V_2 , V_210 ) + V_180 + V_181 ) ;
}
return & V_21 -> V_170 ;
}
static void F_69 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_14 ( V_21 ) ;
struct V_138 * V_139 ;
unsigned char * V_211 ;
struct V_161 * V_162 ;
unsigned int V_212 ;
V_139 = V_2 -> V_139 ;
while ( V_139 -> V_142 [ V_2 -> V_146 ] . V_88 & V_213 ) {
V_211 = V_139 -> V_143 [ V_2 -> V_146 ] ;
V_212 = V_139 -> V_142 [ V_2 -> V_146 ] . V_144 & 0x7ff ;
V_162 = F_70 ( V_21 , V_212 + 2 ) ;
if ( V_162 != NULL ) {
F_71 ( V_162 , 2 ) ;
memcpy ( F_72 ( V_162 , V_212 ) , V_211 , V_212 ) ;
V_162 -> V_214 = F_73 ( V_162 , V_21 ) ;
V_21 -> V_170 . V_215 += V_212 ;
F_74 ( V_162 ) ;
}
else {
V_21 -> V_170 . V_216 += 1 ;
F_9 ( V_217 L_10 , V_21 -> V_31 ) ;
}
if ( V_139 -> V_142 [ V_2 -> V_146 ] . V_144 & V_218 )
V_21 -> V_170 . V_219 ++ ;
V_139 -> V_142 [ V_2 -> V_146 ] . V_88 &= ~ V_213 ;
if ( V_2 -> V_146 == V_141 - 1 )
V_2 -> V_146 = 0 ;
else
V_2 -> V_146 ++ ;
}
}
static T_1 F_75 ( int V_50 , void * V_51 )
{
struct V_20 * V_21 = (struct V_20 * ) V_51 ;
struct V_1 * V_2 = F_14 ( V_21 ) ;
unsigned long V_220 , V_6 ;
V_220 = F_1 ( V_2 , V_221 ) ;
if ( V_220 & V_153 )
F_69 ( V_21 ) ;
if ( V_220 & V_157 ) {
if ( V_220 & ( V_155 | V_156 ) )
V_21 -> V_170 . V_222 += 1 ;
if ( V_2 -> V_162 ) {
F_76 ( V_2 -> V_162 ) ;
V_2 -> V_162 = NULL ;
F_77 ( NULL , V_2 -> V_167 , V_2 -> V_165 , V_169 ) ;
}
F_78 ( V_21 ) ;
}
if ( V_220 & V_154 ) {
V_6 = F_1 ( V_2 , V_7 ) ;
F_3 ( V_2 , V_7 , V_6 & ~ V_148 ) ;
F_3 ( V_2 , V_7 , V_6 | V_148 ) ;
}
if ( V_220 & V_158 )
F_9 ( L_11 , V_21 -> V_31 ) ;
return V_68 ;
}
static void F_79 ( struct V_20 * V_21 )
{
unsigned long V_113 ;
F_80 ( V_113 ) ;
F_75 ( V_21 -> V_50 , V_21 ) ;
F_81 ( V_113 ) ;
}
static int T_2 F_82 ( struct V_1 * V_2 )
{
unsigned int V_223 , V_224 ;
unsigned long V_118 ;
unsigned short V_32 = 0 ;
while ( V_32 < V_225 ) {
F_5 ( V_2 ) ;
F_12 ( V_2 , V_32 , V_226 , & V_223 ) ;
F_12 ( V_2 , V_32 , V_227 , & V_224 ) ;
F_6 ( V_2 ) ;
V_118 = ( V_223 << 16 ) | ( V_224 & 0xfff0 ) ;
switch ( V_118 ) {
case V_54 :
case V_55 :
case V_58 :
case V_228 :
case V_60 :
case V_229 :
case V_66 :
case V_230 :
case V_62 :
case V_64 :
case V_231 :
V_2 -> V_53 = V_118 ;
V_2 -> V_32 = V_32 ;
return 1 ;
}
V_32 ++ ;
}
return 0 ;
}
static int T_2 F_83 ( struct V_232 * V_233 )
{
struct V_234 * V_72 = V_233 -> V_21 . V_235 ;
struct V_236 * V_237 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_136 ;
V_237 = F_84 ( V_233 , V_238 , 0 ) ;
if ( ! V_237 )
return - V_239 ;
V_21 = F_85 ( sizeof( struct V_1 ) ) ;
if ( ! V_21 )
return - V_240 ;
V_2 = F_14 ( V_21 ) ;
V_2 -> V_72 = * V_72 ;
F_86 ( & V_2 -> V_77 ) ;
V_21 -> V_241 = V_237 -> V_242 ;
V_2 -> V_4 = F_87 ( V_237 -> V_242 , V_237 -> V_243 - V_237 -> V_242 + 1 ) ;
if ( ! V_2 -> V_4 ) {
V_136 = - V_240 ;
goto V_244;
}
V_2 -> V_150 = F_88 ( & V_233 -> V_21 , L_12 ) ;
if ( F_89 ( V_2 -> V_150 ) ) {
V_136 = - V_245 ;
goto V_246;
}
F_61 ( V_2 -> V_150 ) ;
V_21 -> V_50 = F_90 ( V_233 , 0 ) ;
if ( F_23 ( V_21 -> V_50 , F_75 , 0 , V_21 -> V_31 , V_21 ) ) {
V_136 = - V_247 ;
goto V_248;
}
V_2 -> V_139 = (struct V_138 * ) F_91 ( NULL , sizeof( struct V_138 ) , ( V_249 * ) & V_2 -> V_140 , V_250 ) ;
if ( V_2 -> V_139 == NULL ) {
V_136 = - V_240 ;
goto V_251;
}
F_92 ( V_21 ) ;
V_21 -> V_252 = & V_253 ;
V_21 -> V_254 = & V_255 ;
F_93 ( V_233 , V_21 ) ;
F_94 ( V_21 , & V_233 -> V_21 ) ;
F_35 ( V_21 ) ;
F_36 ( V_21 ) ;
F_3 ( V_2 , V_7 , 0 ) ;
if ( V_72 -> V_256 )
F_3 ( V_2 , V_47 , V_257 | V_258 | V_259 ) ;
else
F_3 ( V_2 , V_47 , V_257 | V_258 ) ;
if ( ! F_82 ( V_2 ) ) {
F_9 ( V_76 L_13 ) ;
V_136 = - V_245 ;
goto V_260;
}
F_30 ( V_2 ) ;
V_2 -> V_29 . V_21 = V_21 ;
V_2 -> V_29 . F_44 = F_44 ;
V_2 -> V_29 . F_45 = F_45 ;
V_2 -> V_29 . V_118 = V_2 -> V_32 ;
V_2 -> V_29 . V_261 = 0x1f ;
V_2 -> V_29 . V_262 = 0x1f ;
V_136 = F_95 ( V_21 ) ;
if ( V_136 )
goto V_260;
F_24 ( & V_2 -> V_77 ) ;
F_5 ( V_2 ) ;
F_13 ( V_21 , 0 ) ;
F_6 ( V_2 ) ;
F_25 ( & V_2 -> V_77 ) ;
F_16 ( V_21 ) ;
if ( F_20 ( V_2 -> V_72 . V_73 ) ) {
F_96 ( V_72 -> V_73 , L_14 ) ;
} else {
F_97 ( & V_2 -> V_74 ) ;
V_2 -> V_74 . V_168 = ( unsigned long ) V_21 ;
V_2 -> V_74 . V_263 = F_29 ;
}
F_9 ( V_30 L_15 ,
V_21 -> V_31 , ( V_264 ) V_21 -> V_241 , V_21 -> V_50 ,
F_1 ( V_2 , V_47 ) & V_48 ? L_16 : L_17 ,
F_1 ( V_2 , V_47 ) & V_49 ? L_4 : L_5 ,
V_21 -> V_89 ) ;
if ( ( V_2 -> V_53 == V_54 ) || ( V_2 -> V_53 == V_55 ) )
F_9 ( V_30 L_18 , V_21 -> V_31 , ( V_2 -> V_83 == V_84 ) ? L_19 : L_20 ) ;
else if ( V_2 -> V_53 == V_58 )
F_9 ( V_30 L_21 , V_21 -> V_31 ) ;
else if ( V_2 -> V_53 == V_228 )
F_9 ( V_30 L_22 , V_21 -> V_31 ) ;
else if ( V_2 -> V_53 == V_60 )
F_9 ( V_30 L_23 , V_21 -> V_31 ) ;
else if ( V_2 -> V_53 == V_229 )
F_9 ( V_30 L_24 , V_21 -> V_31 ) ;
else if ( V_2 -> V_53 == V_66 )
F_9 ( V_30 L_25 , V_21 -> V_31 ) ;
else if ( V_2 -> V_53 == V_230 )
F_9 ( V_30 L_26 , V_21 -> V_31 ) ;
else if ( V_2 -> V_53 == V_62 )
F_9 ( V_30 L_27 , V_21 -> V_31 ) ;
else if ( V_2 -> V_53 == V_64 )
F_9 ( V_30 L_28 , V_21 -> V_31 ) ;
else if ( V_2 -> V_53 == V_231 )
F_9 ( V_30 L_29 , V_21 -> V_31 ) ;
F_65 ( V_2 -> V_150 ) ;
return 0 ;
V_260:
F_93 ( V_233 , NULL ) ;
F_98 ( NULL , sizeof( struct V_138 ) , V_2 -> V_139 , ( V_249 ) V_2 -> V_140 ) ;
V_251:
F_28 ( V_21 -> V_50 , V_21 ) ;
V_248:
F_65 ( V_2 -> V_150 ) ;
F_99 ( V_2 -> V_150 ) ;
V_246:
F_100 ( V_2 -> V_4 ) ;
V_244:
F_101 ( V_21 ) ;
return V_136 ;
}
static int T_4 F_102 ( struct V_232 * V_233 )
{
struct V_20 * V_21 = F_103 ( V_233 ) ;
struct V_1 * V_2 = F_14 ( V_21 ) ;
if ( F_20 ( V_2 -> V_72 . V_73 ) )
F_104 ( V_2 -> V_72 . V_73 ) ;
F_105 ( V_21 ) ;
F_28 ( V_21 -> V_50 , V_21 ) ;
F_98 ( NULL , sizeof( struct V_138 ) , V_2 -> V_139 , ( V_249 ) V_2 -> V_140 ) ;
F_99 ( V_2 -> V_150 ) ;
F_93 ( V_233 , NULL ) ;
F_101 ( V_21 ) ;
return 0 ;
}
static int F_106 ( struct V_232 * V_233 , T_5 V_265 )
{
struct V_20 * V_266 = F_103 ( V_233 ) ;
struct V_1 * V_2 = F_14 ( V_266 ) ;
if ( F_56 ( V_266 ) ) {
if ( F_20 ( V_2 -> V_72 . V_73 ) ) {
int V_267 = F_22 ( V_2 -> V_72 . V_73 ) ;
F_107 ( V_267 ) ;
}
F_64 ( V_266 ) ;
F_108 ( V_266 ) ;
F_65 ( V_2 -> V_150 ) ;
}
return 0 ;
}
static int F_109 ( struct V_232 * V_233 )
{
struct V_20 * V_266 = F_103 ( V_233 ) ;
struct V_1 * V_2 = F_14 ( V_266 ) ;
if ( F_56 ( V_266 ) ) {
F_61 ( V_2 -> V_150 ) ;
F_110 ( V_266 ) ;
F_62 ( V_266 ) ;
if ( F_20 ( V_2 -> V_72 . V_73 ) ) {
int V_267 = F_22 ( V_2 -> V_72 . V_73 ) ;
F_111 ( V_267 ) ;
}
}
return 0 ;
}
static int T_2 F_112 ( void )
{
return F_113 ( & V_268 , F_83 ) ;
}
static void T_6 F_114 ( void )
{
F_115 ( & V_268 ) ;
}
