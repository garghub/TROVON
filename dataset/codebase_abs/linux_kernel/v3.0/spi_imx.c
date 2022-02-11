static unsigned int F_1 ( unsigned int V_1 ,
unsigned int V_2 )
{
int V_3 , V_4 ;
if ( F_2 () )
V_4 = 18 ;
else
V_4 = 16 ;
for ( V_3 = 2 ; V_3 < V_4 ; V_3 ++ )
if ( V_2 * V_5 [ V_3 ] >= V_1 )
return V_3 ;
return V_4 ;
}
static unsigned int F_3 ( unsigned int V_1 ,
unsigned int V_2 )
{
int V_3 , div = 4 ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ ) {
if ( V_2 * div >= V_1 )
return V_3 ;
div <<= 1 ;
}
return 7 ;
}
static unsigned int F_4 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_6 , V_7 ;
if ( F_5 ( V_2 > V_1 ) )
return 0 ;
V_7 = F_6 ( V_1 ) - F_6 ( V_2 ) ;
if ( V_1 > V_2 << V_7 )
V_7 ++ ;
V_7 = V_4 ( 4U , V_7 ) - 4 ;
if ( F_5 ( V_7 > 0xf ) ) {
F_7 ( L_1 ,
V_8 , V_2 , V_1 ) ;
return 0xff ;
}
V_6 = F_8 ( V_1 , V_2 << V_7 ) - 1 ;
F_9 ( L_2 ,
V_8 , V_1 , V_2 , V_7 , V_6 ) ;
return ( V_6 << V_9 ) |
( V_7 << V_10 ) ;
}
static void T_1 F_10 ( struct V_11 * V_12 , int V_13 )
{
unsigned V_14 = 0 ;
if ( V_13 & V_15 )
V_14 |= V_16 ;
if ( V_13 & V_17 )
V_14 |= V_18 ;
F_11 ( V_14 , V_12 -> V_19 + V_20 ) ;
}
static void T_1 F_12 ( struct V_11 * V_12 )
{
T_2 V_21 ;
V_21 = F_13 ( V_12 -> V_19 + V_22 ) ;
V_21 |= V_23 ;
F_11 ( V_21 , V_12 -> V_19 + V_22 ) ;
}
static int T_1 F_14 ( struct V_11 * V_12 ,
struct V_24 * V_25 )
{
T_2 V_26 = V_27 , V_28 = 0 ;
V_26 |= V_29 ;
V_26 |= F_4 ( V_12 -> V_30 , V_25 -> V_31 ) ;
V_26 |= F_15 ( V_25 -> V_32 ) ;
V_26 |= ( V_25 -> V_33 - 1 ) << V_34 ;
V_28 |= F_16 ( V_25 -> V_32 ) ;
if ( V_25 -> V_35 & V_36 )
V_28 |= F_17 ( V_25 -> V_32 ) ;
if ( V_25 -> V_35 & V_37 )
V_28 |= F_18 ( V_25 -> V_32 ) ;
if ( V_25 -> V_35 & V_38 )
V_28 |= F_19 ( V_25 -> V_32 ) ;
F_11 ( V_26 , V_12 -> V_19 + V_22 ) ;
F_11 ( V_28 , V_12 -> V_19 + V_39 ) ;
return 0 ;
}
static int T_1 F_20 ( struct V_11 * V_12 )
{
return F_13 ( V_12 -> V_19 + V_40 ) & V_41 ;
}
static void T_1 F_21 ( struct V_11 * V_12 )
{
while ( F_20 ( V_12 ) )
F_13 ( V_12 -> V_19 + V_42 ) ;
}
static void T_1 F_22 ( struct V_11 * V_12 , int V_13 )
{
unsigned int V_14 = 0 ;
if ( V_13 & V_15 )
V_14 |= V_43 ;
if ( V_13 & V_17 )
V_14 |= V_44 ;
F_11 ( V_14 , V_12 -> V_19 + V_45 ) ;
}
static void T_1 F_23 ( struct V_11 * V_12 )
{
unsigned int V_21 ;
V_21 = F_13 ( V_12 -> V_19 + V_46 ) ;
V_21 |= V_47 ;
F_11 ( V_21 , V_12 -> V_19 + V_46 ) ;
}
static int T_1 F_24 ( struct V_11 * V_12 ,
struct V_24 * V_25 )
{
unsigned int V_21 = V_48 | V_49 ;
int V_32 = V_12 -> V_50 [ V_25 -> V_32 ] ;
V_21 |= F_3 ( V_12 -> V_30 , V_25 -> V_31 ) <<
V_51 ;
V_21 |= ( V_25 -> V_33 - 1 ) << V_52 ;
if ( V_25 -> V_35 & V_36 )
V_21 |= V_53 ;
if ( V_25 -> V_35 & V_37 )
V_21 |= V_54 ;
if ( V_25 -> V_35 & V_38 )
V_21 |= V_55 ;
if ( V_32 < 0 )
V_21 |= ( V_32 + 32 ) << V_56 ;
F_11 ( V_21 , V_12 -> V_19 + V_46 ) ;
return 0 ;
}
static int T_1 F_25 ( struct V_11 * V_12 ,
struct V_24 * V_25 )
{
unsigned int V_21 = V_48 | V_49 ;
int V_32 = V_12 -> V_50 [ V_25 -> V_32 ] ;
V_21 |= F_3 ( V_12 -> V_30 , V_25 -> V_31 ) <<
V_51 ;
V_21 |= ( V_25 -> V_33 - 1 ) << V_57 ;
V_21 |= V_58 ;
if ( V_25 -> V_35 & V_36 )
V_21 |= V_53 ;
if ( V_25 -> V_35 & V_37 )
V_21 |= V_54 ;
if ( V_25 -> V_35 & V_38 )
V_21 |= V_55 ;
if ( V_32 < 0 )
V_21 |= ( V_32 + 32 ) << V_59 ;
F_11 ( V_21 , V_12 -> V_19 + V_46 ) ;
return 0 ;
}
static int T_1 F_26 ( struct V_11 * V_12 )
{
return F_13 ( V_12 -> V_19 + V_60 ) & V_61 ;
}
static void T_1 F_27 ( struct V_11 * V_12 )
{
while ( F_13 ( V_12 -> V_19 + V_62 ) & V_63 )
F_13 ( V_12 -> V_19 + V_42 ) ;
}
static void T_1 F_28 ( struct V_11 * V_12 , int V_13 )
{
unsigned int V_14 = 0 ;
if ( V_13 & V_15 )
V_14 |= V_64 ;
if ( V_13 & V_17 )
V_14 |= V_65 ;
F_11 ( V_14 , V_12 -> V_19 + V_45 ) ;
}
static void T_1 F_29 ( struct V_11 * V_12 )
{
unsigned int V_21 ;
V_21 = F_13 ( V_12 -> V_19 + V_46 ) ;
V_21 |= V_66 ;
F_11 ( V_21 , V_12 -> V_19 + V_46 ) ;
}
static int T_1 F_30 ( struct V_11 * V_12 ,
struct V_24 * V_25 )
{
unsigned int V_21 = V_67 | V_68 ;
int V_32 = V_12 -> V_50 [ V_25 -> V_32 ] ;
V_21 |= F_1 ( V_12 -> V_30 , V_25 -> V_31 ) <<
V_69 ;
V_21 |= V_25 -> V_33 - 1 ;
if ( V_25 -> V_35 & V_36 )
V_21 |= V_70 ;
if ( V_25 -> V_35 & V_37 )
V_21 |= V_71 ;
if ( V_25 -> V_35 & V_38 )
V_21 |= V_72 ;
if ( V_32 < 0 )
V_21 |= ( V_32 + 32 ) << V_73 ;
F_11 ( V_21 , V_12 -> V_19 + V_46 ) ;
return 0 ;
}
static int T_1 F_31 ( struct V_11 * V_12 )
{
return F_13 ( V_12 -> V_19 + V_45 ) & V_74 ;
}
static void T_1 F_32 ( struct V_11 * V_12 )
{
F_11 ( 1 , V_12 -> V_19 + V_75 ) ;
}
static void T_1 F_33 ( struct V_11 * V_12 , int V_13 )
{
unsigned int V_14 = 0 ;
if ( V_13 & V_15 )
V_14 |= V_76 ;
if ( V_13 & V_17 )
V_14 |= V_77 ;
F_11 ( V_14 , V_12 -> V_19 + V_45 ) ;
}
static void T_1 F_34 ( struct V_11 * V_12 )
{
unsigned int V_21 ;
V_21 = F_13 ( V_12 -> V_19 + V_46 ) ;
V_21 |= V_78 ;
F_11 ( V_21 , V_12 -> V_19 + V_46 ) ;
}
static int T_1 F_35 ( struct V_11 * V_12 ,
struct V_24 * V_25 )
{
unsigned int V_21 = V_79 | V_80 ;
V_21 |= F_3 ( V_12 -> V_30 , V_25 -> V_31 ) <<
V_81 ;
V_21 |= V_25 -> V_33 - 1 ;
if ( V_25 -> V_35 & V_36 )
V_21 |= V_82 ;
if ( V_25 -> V_35 & V_37 )
V_21 |= V_83 ;
F_11 ( V_21 , V_12 -> V_19 + V_46 ) ;
return 0 ;
}
static int T_1 F_36 ( struct V_11 * V_12 )
{
return F_13 ( V_12 -> V_19 + V_45 ) & V_84 ;
}
static void T_1 F_37 ( struct V_11 * V_12 )
{
F_11 ( 1 , V_12 -> V_19 + V_75 ) ;
}
static void F_38 ( struct V_85 * V_86 , int V_87 )
{
struct V_11 * V_12 = F_39 ( V_86 -> V_88 ) ;
int V_89 = V_12 -> V_50 [ V_86 -> V_90 ] ;
int V_91 = V_87 != V_92 ;
int V_93 = ! ( V_86 -> V_35 & V_38 ) ;
if ( V_89 < 0 )
return;
F_40 ( V_89 , V_93 ^ V_91 ) ;
}
static void F_41 ( struct V_11 * V_12 )
{
while ( V_12 -> V_94 < V_12 -> V_95 . V_96 ) {
if ( ! V_12 -> V_97 )
break;
V_12 -> V_98 ( V_12 ) ;
V_12 -> V_94 ++ ;
}
V_12 -> V_95 . V_99 ( V_12 ) ;
}
static T_3 F_42 ( int V_100 , void * V_101 )
{
struct V_11 * V_12 = V_101 ;
while ( V_12 -> V_95 . V_102 ( V_12 ) ) {
V_12 -> V_103 ( V_12 ) ;
V_12 -> V_94 -- ;
}
if ( V_12 -> V_97 ) {
F_41 ( V_12 ) ;
return V_104 ;
}
if ( V_12 -> V_94 ) {
V_12 -> V_95 . V_105 (
V_12 , V_17 ) ;
return V_104 ;
}
V_12 -> V_95 . V_105 ( V_12 , 0 ) ;
F_43 ( & V_12 -> V_106 ) ;
return V_104 ;
}
static int F_44 ( struct V_85 * V_86 ,
struct V_107 * V_108 )
{
struct V_11 * V_12 = F_39 ( V_86 -> V_88 ) ;
struct V_24 V_25 ;
V_25 . V_33 = V_108 ? V_108 -> V_109 : V_86 -> V_109 ;
V_25 . V_31 = V_108 ? V_108 -> V_31 : V_86 -> V_110 ;
V_25 . V_35 = V_86 -> V_35 ;
V_25 . V_32 = V_86 -> V_90 ;
if ( ! V_25 . V_31 )
V_25 . V_31 = V_86 -> V_110 ;
if ( ! V_25 . V_33 )
V_25 . V_33 = V_86 -> V_109 ;
if ( ! V_25 . V_31 )
V_25 . V_31 = V_86 -> V_110 ;
if ( V_25 . V_33 <= 8 ) {
V_12 -> V_103 = V_111 ;
V_12 -> V_98 = V_112 ;
} else if ( V_25 . V_33 <= 16 ) {
V_12 -> V_103 = V_113 ;
V_12 -> V_98 = V_114 ;
} else if ( V_25 . V_33 <= 32 ) {
V_12 -> V_103 = V_115 ;
V_12 -> V_98 = V_116 ;
} else
F_45 () ;
V_12 -> V_95 . V_25 ( V_12 , & V_25 ) ;
return 0 ;
}
static int F_46 ( struct V_85 * V_86 ,
struct V_107 * V_117 )
{
struct V_11 * V_12 = F_39 ( V_86 -> V_88 ) ;
V_12 -> V_118 = V_117 -> V_118 ;
V_12 -> V_119 = V_117 -> V_119 ;
V_12 -> V_97 = V_117 -> V_120 ;
V_12 -> V_94 = 0 ;
F_47 ( & V_12 -> V_106 ) ;
F_41 ( V_12 ) ;
V_12 -> V_95 . V_105 ( V_12 , V_15 ) ;
F_48 ( & V_12 -> V_106 ) ;
return V_117 -> V_120 ;
}
static int F_49 ( struct V_85 * V_86 )
{
struct V_11 * V_12 = F_39 ( V_86 -> V_88 ) ;
int V_89 = V_12 -> V_50 [ V_86 -> V_90 ] ;
F_50 ( & V_86 -> V_121 , L_3 , V_8 ,
V_86 -> V_35 , V_86 -> V_109 , V_86 -> V_110 ) ;
if ( V_89 >= 0 )
F_51 ( V_89 , V_86 -> V_35 & V_38 ? 0 : 1 ) ;
F_38 ( V_86 , V_92 ) ;
return 0 ;
}
static void F_52 ( struct V_85 * V_86 )
{
}
static int T_4 F_53 ( struct V_122 * V_123 )
{
struct V_124 * V_125 ;
struct V_126 * V_88 ;
struct V_11 * V_12 ;
struct V_127 * V_128 ;
int V_3 , V_129 ;
V_125 = F_54 ( & V_123 -> V_121 ) ;
if ( ! V_125 ) {
F_55 ( & V_123 -> V_121 , L_4 ) ;
return - V_130 ;
}
V_88 = F_56 ( & V_123 -> V_121 , sizeof( struct V_11 ) ) ;
if ( ! V_88 )
return - V_131 ;
F_57 ( V_123 , V_88 ) ;
V_88 -> V_132 = V_123 -> V_133 ;
V_88 -> V_134 = V_125 -> V_134 ;
V_12 = F_39 ( V_88 ) ;
V_12 -> V_135 . V_88 = F_58 ( V_88 ) ;
V_12 -> V_50 = V_125 -> V_50 ;
for ( V_3 = 0 ; V_3 < V_88 -> V_134 ; V_3 ++ ) {
if ( V_12 -> V_50 [ V_3 ] < 0 )
continue;
V_129 = F_59 ( V_12 -> V_50 [ V_3 ] , V_136 ) ;
if ( V_129 ) {
while ( V_3 > 0 ) {
V_3 -- ;
if ( V_12 -> V_50 [ V_3 ] >= 0 )
F_60 ( V_12 -> V_50 [ V_3 ] ) ;
}
F_55 ( & V_123 -> V_121 , L_5 ) ;
goto V_137;
}
}
V_12 -> V_135 . V_50 = F_38 ;
V_12 -> V_135 . V_138 = F_44 ;
V_12 -> V_135 . V_139 = F_46 ;
V_12 -> V_135 . V_88 -> V_140 = F_49 ;
V_12 -> V_135 . V_88 -> V_141 = F_52 ;
V_12 -> V_135 . V_88 -> V_142 = V_37 | V_36 | V_38 ;
F_47 ( & V_12 -> V_106 ) ;
V_12 -> V_95 =
V_143 [ V_123 -> V_144 -> V_145 ] ;
V_128 = F_61 ( V_123 , V_146 , 0 ) ;
if ( ! V_128 ) {
F_55 ( & V_123 -> V_121 , L_6 ) ;
V_129 = - V_131 ;
goto V_147;
}
if ( ! F_62 ( V_128 -> V_148 , F_63 ( V_128 ) , V_123 -> V_149 ) ) {
F_55 ( & V_123 -> V_121 , L_7 ) ;
V_129 = - V_150 ;
goto V_147;
}
V_12 -> V_19 = F_64 ( V_128 -> V_148 , F_63 ( V_128 ) ) ;
if ( ! V_12 -> V_19 ) {
V_129 = - V_130 ;
goto V_151;
}
V_12 -> V_100 = F_65 ( V_123 , 0 ) ;
if ( V_12 -> V_100 < 0 ) {
V_129 = - V_130 ;
goto V_152;
}
V_129 = F_66 ( V_12 -> V_100 , F_42 , 0 , V_136 , V_12 ) ;
if ( V_129 ) {
F_55 ( & V_123 -> V_121 , L_8 , V_12 -> V_100 , V_129 ) ;
goto V_152;
}
V_12 -> V_153 = F_67 ( & V_123 -> V_121 , NULL ) ;
if ( F_68 ( V_12 -> V_153 ) ) {
F_55 ( & V_123 -> V_121 , L_9 ) ;
V_129 = F_69 ( V_12 -> V_153 ) ;
goto V_154;
}
F_70 ( V_12 -> V_153 ) ;
V_12 -> V_30 = F_71 ( V_12 -> V_153 ) ;
V_12 -> V_95 . V_155 ( V_12 ) ;
V_12 -> V_95 . V_105 ( V_12 , 0 ) ;
V_129 = F_72 ( & V_12 -> V_135 ) ;
if ( V_129 ) {
F_55 ( & V_123 -> V_121 , L_10 , V_129 ) ;
goto V_156;
}
F_73 ( & V_123 -> V_121 , L_11 ) ;
return V_129 ;
V_156:
F_74 ( V_12 -> V_153 ) ;
F_75 ( V_12 -> V_153 ) ;
V_154:
F_76 ( V_12 -> V_100 , V_12 ) ;
V_152:
F_77 ( V_12 -> V_19 ) ;
V_151:
F_78 ( V_128 -> V_148 , F_63 ( V_128 ) ) ;
V_147:
for ( V_3 = 0 ; V_3 < V_88 -> V_134 ; V_3 ++ )
if ( V_12 -> V_50 [ V_3 ] >= 0 )
F_60 ( V_12 -> V_50 [ V_3 ] ) ;
V_137:
F_79 ( V_88 ) ;
F_80 ( V_88 ) ;
F_57 ( V_123 , NULL ) ;
return V_129 ;
}
static int T_5 F_81 ( struct V_122 * V_123 )
{
struct V_126 * V_88 = F_82 ( V_123 ) ;
struct V_127 * V_128 = F_61 ( V_123 , V_146 , 0 ) ;
struct V_11 * V_12 = F_39 ( V_88 ) ;
int V_3 ;
F_83 ( & V_12 -> V_135 ) ;
F_11 ( 0 , V_12 -> V_19 + V_46 ) ;
F_74 ( V_12 -> V_153 ) ;
F_75 ( V_12 -> V_153 ) ;
F_76 ( V_12 -> V_100 , V_12 ) ;
F_77 ( V_12 -> V_19 ) ;
for ( V_3 = 0 ; V_3 < V_88 -> V_134 ; V_3 ++ )
if ( V_12 -> V_50 [ V_3 ] >= 0 )
F_60 ( V_12 -> V_50 [ V_3 ] ) ;
F_79 ( V_88 ) ;
F_78 ( V_128 -> V_148 , F_63 ( V_128 ) ) ;
F_57 ( V_123 , NULL ) ;
return 0 ;
}
static int T_6 F_84 ( void )
{
return F_85 ( & V_157 ) ;
}
static void T_7 F_86 ( void )
{
F_87 ( & V_157 ) ;
}
