static bool F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 & F_2 ( 29 ) ;
}
static int F_3 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_3 >> 24 ) & 0x1f ;
}
static int F_4 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 & ( F_2 ( 24 ) - 1 ) ;
}
static bool F_5 ( const struct V_4 * V_2 )
{
return V_2 -> V_3 & F_2 ( 31 ) ;
}
static int F_6 ( const struct V_4 * V_2 )
{
return V_2 -> V_3 & ( F_2 ( 10 ) - 1 ) ;
}
static int F_7 ( const struct V_5 * V_2 )
{
return ( V_2 -> V_3 >> 24 ) & 0xf ;
}
static int F_8 ( const struct V_5 * V_2 )
{
return V_2 -> V_3 & ( F_2 ( 12 ) - 1 ) ;
}
static int F_9 ( const struct V_5 * V_2 )
{
return ( V_2 -> V_3 >> 24 ) & 0x1f ;
}
static int F_10 ( const struct V_5 * V_2 )
{
return V_2 -> V_3 & ( F_2 ( 16 ) - 1 ) ;
}
static inline T_1 F_11 ( T_1 V_6 )
{
return F_12 ( V_7 + V_6 / 4 ) ;
}
static inline void F_13 ( T_1 V_6 , T_1 V_8 )
{
F_14 ( V_8 , V_7 + V_6 / 4 ) ;
}
T_1 F_15 ( void )
{
return V_9 ;
}
static void F_16 ( enum V_10 V_11 , int V_12 , T_2 V_13 )
{
F_17 ( ! V_12 || V_11 == V_14 ||
V_11 == V_15 ) ;
if ( ( V_16 & 0xFF00 ) >= V_17 )
F_13 ( F_18 ( V_11 ) ,
( V_12 ? 0x1000 : 0 ) | ( V_13 & 0x3ff ) ) ;
else
F_13 ( F_18 ( V_11 ) ,
( V_12 ? 0x100 : 0 ) | ( V_13 & 0x1f ) ) ;
}
static void F_19 ( enum V_18 V_19 ,
T_2 V_20 , T_2 V_21 , T_2 V_22 , T_2 V_23 ,
T_2 V_24 , T_2 V_25 , T_2 V_26 )
{
F_13 ( F_20 ( V_19 ) , ( ( V_20 & 0xff ) << 24 ) |
( ( V_21 & 0x7 ) << 20 ) | ( ( V_22 & 0x7 ) << 16 ) |
( ( V_23 & 0x7 ) << 12 ) | ( ( V_24 & 0x7 ) << 8 ) |
( ( V_25 & 0x7 ) << 4 ) | ( V_26 & 0x7 ) ) ;
}
static void F_21 ( void )
{
F_13 ( V_27 , 0 ) ;
}
static void F_22 ( void )
{
F_13 ( V_28 , V_29 |
( V_30 << 24 ) |
( V_31 << 8 ) |
( V_32 << 4 ) |
V_33 ) ;
}
static void F_23 ( T_3 * V_34 , T_2 * V_35 , T_2 * V_36 )
{
T_1 V_37 = F_11 ( V_38 ) ;
* V_34 = ( V_37 >> 16 ) ;
* V_35 = ( V_37 >> 8 ) & 0xff ;
* V_36 = V_37 & 0xff ;
}
static void F_24 ( enum V_39 V_40 , T_4 V_41 , T_1 V_42 )
{
T_1 V_6 = ( V_40 == V_43 ) ? V_44 : V_45 ;
T_1 exp = F_25 ( V_42 ) ;
F_17 ( ( V_42 >= 4096 ) && ( V_42 <= 1024 * 1024 * 1024 ) &&
F_26 ( V_42 ) ) ;
F_17 ( ! ( V_41 & ( V_42 - 1 ) ) ) ;
F_13 ( V_6 , F_27 ( V_41 ) ) ;
F_13 ( V_6 + V_46 , F_28 ( V_41 ) ) ;
F_13 ( V_6 + V_47 , V_48 | ( exp - 1 ) ) ;
}
static void F_29 ( T_1 V_49 , T_2 V_50 )
{
F_13 ( V_51 , V_49 & 0xffffff ) ;
F_13 ( V_52 , V_50 ) ;
}
static void F_30 ( T_3 V_49 )
{
F_13 ( V_53 , V_49 & 0x3ff ) ;
}
static int F_31 ( struct V_54 * V_55 , T_1 V_56 , T_1 V_57 )
{
T_2 V_58 = F_32 ( F_11 ( V_59 ) ) ;
F_17 ( V_56 && ! ( V_56 & 7 ) && ! ( V_57 & 7 ) && V_57 ) ;
if ( ! F_33 ( V_58 ) ) {
F_34 ( V_55 , L_1 ) ;
F_35 ( 1 ) ;
}
F_13 ( F_36 ( 0 ) , V_56 ) ;
F_13 ( F_36 ( 1 ) , V_56 + V_57 - 16 ) ;
F_37 () ;
F_13 ( V_59 , V_60 ) ;
do {
V_58 = F_32 ( F_11 ( V_59 ) ) ;
} while ( ! F_33 ( V_58 ) );
if ( F_38 ( V_58 ) )
return 0 ;
if ( F_39 ( V_58 ) )
return - V_61 ;
if ( F_40 ( V_58 ) )
return - V_62 ;
F_34 ( V_55 , L_2 , V_58 ) ;
return - V_63 ;
}
static int F_41 ( struct V_64 * V_65 )
{
V_66 = V_65 -> V_67 ;
V_68 = V_65 -> V_42 ;
F_35 ( ! ( V_66 && V_68 ) ) ;
return 0 ;
}
static int F_42 ( struct V_64 * V_65 )
{
V_69 = V_65 -> V_67 ;
V_70 = V_65 -> V_42 ;
F_35 ( ! ( V_69 && V_70 ) ) ;
return 0 ;
}
static unsigned int F_43 ( void )
{
return V_68 / 64 ;
}
static int F_44 ( struct V_54 * V_55 , struct V_71 * V_72 ,
T_5 V_73 , T_6 V_74 )
{
void T_7 * V_75 = F_45 ( V_73 , V_74 , 0 ) ;
F_46 ( V_75 , 0 , V_74 ) ;
F_47 ( ( unsigned long ) V_75 ,
( unsigned long ) V_75 + V_74 ) ;
F_48 ( V_75 ) ;
return 0 ;
}
static void F_49 ( struct V_54 * V_55 , T_1 V_76 )
{
T_1 V_77 , V_78 , V_79 = 0xffffffff ;
F_50 ( V_55 , L_3 ) ;
V_77 = V_76 / 32 ;
if ( V_76 % 32 ) {
V_77 ++ ;
V_79 = ~ ( V_79 << V_76 % 32 ) ;
}
V_78 = 16 - V_77 ;
F_50 ( V_55 , L_4 , F_11 ( F_51 ( V_78 ) ) & V_79 ) ;
V_78 ++ ;
for (; V_78 < 16 ; V_78 ++ )
F_50 ( V_55 , L_4 , F_11 ( F_51 ( V_78 ) ) ) ;
}
static void F_52 ( struct V_54 * V_55 , T_1 V_80 ,
T_1 V_81 )
{
struct V_1 V_82 ;
struct V_5 V_83 ;
int V_84 ;
V_82 . V_3 = F_11 ( V_85 ) ;
if ( ( V_16 & 0xFF00 ) >= V_17 ) {
struct V_4 V_86 ;
V_86 . V_3 = F_11 ( V_87 ) ;
if ( V_81 & V_88 ) {
F_50 ( V_55 , L_5 ,
F_5 ( & V_86 ) ? L_6 : L_7 ,
F_6 ( & V_86 ) ) ;
}
if ( V_81 & ( V_89 | V_90 ) )
F_50 ( V_55 , L_8 ,
F_4 ( & V_82 ) ) ;
if ( V_81 & ( V_91 | V_92 ) ) {
V_83 . V_3 = F_11 ( V_93 ) ;
V_84 = F_9 ( & V_83 ) ;
F_50 ( V_55 , L_9 ,
V_94 [ V_84 ] . V_95 ,
V_94 [ V_84 ] . V_96
& F_10 ( & V_83 ) ) ;
F_49 ( V_55 , V_94 [ V_84 ] . V_97 ) ;
}
} else {
if ( V_81 & V_88 ) {
F_50 ( V_55 , L_5 ,
F_1 ( & V_82 ) ? L_6 : L_7 ,
F_3 ( & V_82 ) ) ;
}
if ( V_81 & V_89 )
F_50 ( V_55 , L_8 ,
F_4 ( & V_82 ) ) ;
if ( V_81 & ( V_91 | V_92 ) ) {
V_83 . V_3 = F_11 ( V_93 ) ;
V_84 = F_7 ( & V_83 ) ;
F_50 ( V_55 , L_9 ,
V_94 [ V_84 ] . V_95 ,
V_94 [ V_84 ] . V_96
& F_8 ( & V_83 ) ) ;
F_49 ( V_55 , V_94 [ V_84 ] . V_97 ) ;
}
}
}
static T_8 F_53 ( int V_98 , void * V_99 )
{
T_1 V_80 , V_100 , V_81 , V_101 , V_77 ;
struct V_54 * V_55 = V_99 ;
V_100 = F_11 ( V_102 ) ;
V_80 = F_11 ( V_103 ) ;
V_81 = F_11 ( V_104 ) ;
V_101 = V_80 & V_100 ;
if ( ! V_101 )
return V_105 ;
for ( V_77 = 0 ; V_77 < F_54 ( V_106 ) ; V_77 ++ ) {
if ( V_106 [ V_77 ] . V_79 & V_101 ) {
F_55 ( V_55 , L_10 ,
V_106 [ V_77 ] . V_95 ) ;
if ( V_106 [ V_77 ] . V_79 & V_81 ) {
F_52 ( V_55 , V_101 ,
V_81 ) ;
F_13 ( V_104 , V_81 ) ;
}
if ( V_106 [ V_77 ] . V_79 & V_107 ) {
F_56 ( V_55 , L_11 ,
V_106 [ V_77 ] . V_79 ) ;
V_100 &= ~ V_106 [ V_77 ] . V_79 ;
F_13 ( V_102 , V_100 ) ;
}
}
}
F_13 ( V_103 , V_80 ) ;
return V_108 ;
}
static int F_57 ( struct V_54 * V_55 )
{
int V_77 , V_109 ;
F_24 ( V_43 , V_66 , V_68 ) ;
F_24 ( V_110 , V_69 , V_70 ) ;
V_109 = F_31 ( V_55 , 8 , V_70 / 64 - 8 ) ;
if ( V_109 )
return V_109 ;
F_29 ( 512 , 64 ) ;
F_30 ( 128 ) ;
F_13 ( V_103 , V_111 ) ;
F_22 () ;
F_21 () ;
for ( V_77 = V_112 ; V_77 <= V_113 ; V_77 ++ )
F_19 ( V_77 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
F_16 ( V_14 , 1 , 0 ) ;
F_16 ( V_15 , 1 , 0 ) ;
return 0 ;
}
void F_58 ( T_3 V_114 )
{
static int V_115 ;
static T_1 V_116 ;
T_1 V_117 , V_118 ;
int V_119 = V_114 - V_120 ;
if ( ( V_16 & 0xFF00 ) >= V_17 )
V_117 = F_11 ( F_59 ( V_119 ) ) ;
else
V_117 = F_11 ( F_60 ( V_119 ) ) ;
if ( ! V_115 ) {
V_116 = V_117 & V_121 ;
V_115 = 1 ;
return;
}
V_118 = ( V_117 & ( ~ V_121 ) ) | V_116 ;
if ( ( V_16 & 0xFF00 ) >= V_17 )
F_13 ( F_59 ( V_119 ) , V_118 ) ;
else
F_13 ( F_60 ( V_119 ) , V_118 ) ;
}
void F_61 ( T_3 V_114 , unsigned int V_122 )
{
int V_119 = V_114 - V_120 ;
T_1 V_117 , V_118 ;
if ( ( V_16 & 0xFF00 ) >= V_17 ) {
V_117 = F_11 ( F_62 ( V_119 ) ) ;
V_122 /= 2 ;
V_118 = ( V_117 & ( ~ V_123 ) ) | ( V_122 << 16 ) ;
F_13 ( F_62 ( V_119 ) , V_118 ) ;
} else {
V_117 = F_11 ( F_63 ( V_119 ) ) ;
V_118 = ( V_117 & ( ~ V_123 ) ) | ( V_122 << 16 ) ;
F_13 ( F_63 ( V_119 ) , V_118 ) ;
}
}
static int F_64 ( struct V_54 * V_55 )
{
int V_124 , V_125 ;
int V_126 , V_77 ;
switch ( V_16 >> 8 ) {
case 1 :
V_124 = 15 ;
V_125 = 256 ;
break;
case 2 :
V_124 = 3 ;
V_125 = 64 ;
break;
case 3 :
V_124 = 15 ;
V_125 = 256 ;
break;
default:
return - V_63 ;
}
V_126 = F_65 ( V_127 , V_128 | V_129 ,
V_124 , - 1 ) ;
if ( V_126 ) {
F_66 ( V_55 , L_12 , V_126 ) ;
return V_126 ;
}
V_126 = F_65 ( V_130 , V_129 , V_125 , - 1 ) ;
if ( V_126 ) {
F_66 ( V_55 , L_13 , V_126 ) ;
return V_126 ;
}
for ( V_77 = 0 ; V_77 < V_125 ; V_77 ++ )
V_9 |= F_67 ( V_77 ) ;
V_126 = F_65 ( V_131 , V_132 | V_129 ,
F_43 () - V_132 , - 1 ) ;
if ( V_126 ) {
F_66 ( V_55 , L_14 , V_126 ) ;
return V_126 ;
}
return 0 ;
}
static int F_68 ( struct V_133 * V_134 )
{
struct V_54 * V_55 = & V_134 -> V_55 ;
struct V_71 * V_72 = V_55 -> V_135 ;
struct V_136 * V_137 ;
int V_126 , V_138 ;
T_3 V_34 ;
T_2 V_35 , V_36 ;
V_137 = F_69 ( V_134 , V_139 , 0 ) ;
if ( ! V_137 ) {
F_66 ( V_55 , L_15 ,
V_72 -> V_140 ) ;
return - V_141 ;
}
V_7 = F_70 ( V_55 , V_137 -> V_142 , F_71 ( V_137 ) ) ;
if ( ! V_7 )
return - V_141 ;
F_23 ( & V_34 , & V_35 , & V_36 ) ;
if ( V_35 == 1 && V_36 == 0 ) {
F_66 ( V_55 , L_16 ) ;
return - V_63 ;
} else if ( V_35 == 1 && V_36 == 1 )
V_16 = V_143 ;
else if ( V_35 == 1 && V_36 == 2 )
V_16 = V_144 ;
else if ( V_35 == 2 && V_36 == 0 )
V_16 = V_145 ;
else if ( V_35 == 3 && V_36 == 0 )
V_16 = V_17 ;
else if ( V_35 == 3 && V_36 == 1 )
V_16 = V_146 ;
else {
F_66 ( V_55 , L_17 ) ;
return - V_63 ;
}
if ( ( V_16 & 0xff00 ) >= V_17 )
V_128 = V_147 ;
V_126 = F_44 ( V_55 , V_72 , V_66 , V_68 ) ;
F_35 ( V_126 ) ;
if ( V_126 )
return - V_63 ;
V_126 = F_57 ( V_55 ) ;
if ( V_126 ) {
F_66 ( V_55 , L_18 ) ;
return V_126 ;
}
V_138 = F_72 ( V_134 , 0 ) ;
if ( V_138 <= 0 ) {
F_73 ( V_55 , L_19 ,
V_72 -> V_140 ) ;
return - V_63 ;
}
V_126 = F_74 ( V_55 , V_138 , F_53 , V_148 , L_20 ,
V_55 ) ;
if ( V_126 ) {
F_66 ( V_55 , L_21 ,
V_126 , V_72 -> V_140 ) ;
return V_126 ;
}
F_13 ( V_103 , 0xffffffff ) ;
F_13 ( V_102 , 0xffffffff ) ;
V_131 = F_75 ( V_55 , 0 , - 1 , L_22 ) ;
if ( F_76 ( V_131 ) ) {
V_126 = F_77 ( V_131 ) ;
F_66 ( V_55 , L_23 , V_126 ) ;
return V_126 ;
}
V_127 = F_75 ( V_55 , 0 , - 1 , L_24 ) ;
if ( F_76 ( V_127 ) ) {
V_126 = F_77 ( V_127 ) ;
F_66 ( V_55 , L_25 , V_126 ) ;
return V_126 ;
}
V_130 = F_75 ( V_55 , 0 , - 1 , L_26 ) ;
if ( F_76 ( V_130 ) ) {
V_126 = F_77 ( V_130 ) ;
F_66 ( V_55 , L_27 , V_126 ) ;
return V_126 ;
}
V_126 = F_64 ( V_55 ) ;
if ( V_126 )
return V_126 ;
V_126 = F_78 ( F_43 () ) ;
if ( V_126 )
return V_126 ;
V_126 = F_79 () ;
if ( V_126 )
return V_126 ;
return 0 ;
}
