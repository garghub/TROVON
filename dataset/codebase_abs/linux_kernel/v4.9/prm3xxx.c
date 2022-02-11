static T_1 F_1 ( T_2 V_1 )
{
struct V_2 * V_3 = & V_2 [ V_1 ] ;
T_1 V_4 ;
V_4 = F_2 ( V_5 ,
V_6 ) ;
return V_4 & V_3 -> V_7 ;
}
static void F_3 ( T_2 V_1 )
{
struct V_2 * V_3 = & V_2 [ V_1 ] ;
F_4 ( V_3 -> V_7 ,
V_5 , V_6 ) ;
}
T_1 F_5 ( T_2 V_8 )
{
return F_2 ( V_9 , V_8 ) ;
}
void F_6 ( T_1 V_10 , T_2 V_8 )
{
F_4 ( V_10 , V_9 , V_8 ) ;
}
T_1 F_7 ( T_1 V_11 , T_1 V_12 , T_2 V_8 )
{
return F_8 ( V_11 , V_12 , V_9 , V_8 ) ;
}
static void F_9 ( void )
{
F_10 ( V_13 , V_9 ,
V_14 ) ;
F_2 ( V_9 , V_14 ) ;
}
static void F_11 ( unsigned long * V_15 )
{
T_1 V_11 , V_16 ;
V_11 = F_2 ( V_5 , V_17 ) ;
V_16 = F_2 ( V_5 , V_6 ) ;
V_15 [ 0 ] = V_11 & V_16 ;
}
static void F_12 ( void )
{
F_2 ( V_5 , V_18 ) ;
}
static void F_13 ( T_1 * V_19 )
{
V_19 [ 0 ] = F_2 ( V_5 ,
V_17 ) ;
F_4 ( 0 , V_5 , V_17 ) ;
F_2 ( V_5 , V_18 ) ;
}
static void F_14 ( T_1 * V_19 )
{
F_4 ( V_19 [ 0 ] , V_5 ,
V_17 ) ;
}
static int F_15 ( T_3 V_20 , T_2 V_21 , T_1 V_22 )
{
T_1 V_23 , V_24 , V_25 , V_26 ;
T_4 V_27 = ( V_21 == 3 ) ? V_28 : V_29 ;
T_4 V_30 = ( V_21 == 3 ) ? V_31 : V_32 ;
T_4 V_33 = ( V_21 == 3 ) ? V_34 : V_35 ;
T_4 V_36 = ( V_21 == 3 ) ?
V_37 : V_38 ;
int V_39 = 0 ;
V_23 = F_2 ( V_20 , V_27 ) ;
V_23 &= F_2 ( V_20 , V_36 ) ;
V_23 &= V_22 ;
if ( V_23 ) {
V_25 = F_16 ( V_20 , V_33 ) ;
V_24 = F_16 ( V_20 , V_30 ) ;
while ( V_23 ) {
V_26 = V_23 ;
F_17 ( V_26 , V_20 , V_33 ) ;
if ( V_20 == V_40 )
V_26 |= 1 << V_41 ;
F_17 ( V_26 , V_20 , V_30 ) ;
F_4 ( V_23 , V_20 , V_27 ) ;
V_23 = F_2 ( V_20 , V_27 ) ;
V_23 &= V_22 ;
V_39 ++ ;
}
F_18 ( V_25 , V_20 , V_33 ) ;
F_18 ( V_24 , V_20 , V_30 ) ;
}
return V_39 ;
}
void T_5 F_19 ( void )
{
F_4 (
V_42 |
V_43 ,
V_44 , V_14 ) ;
F_4 ( 0 , V_44 , V_14 ) ;
}
void T_5 F_20 ( bool V_45 , bool V_46 )
{
T_1 V_47 ;
T_1 V_48 ;
F_8 ( V_49 ,
1 << V_50 ,
V_9 ,
V_51 ) ;
F_4 ( V_52 | V_53 |
V_54 | V_55 ,
V_56 , V_57 ) ;
F_4 ( V_58 |
V_59 |
V_60 ,
V_56 , V_38 ) ;
F_4 ( V_61 ,
V_62 , V_57 ) ;
if ( V_45 ) {
V_47 = V_63 ;
V_48 = V_64 ;
} else {
V_47 = 0 ;
V_48 = 0 ;
}
F_4 ( V_47 |
V_65 |
V_66 |
V_67 |
V_68 |
V_69 |
V_70 |
V_71 |
V_72 |
V_73 ,
V_74 , V_57 ) ;
F_4 ( V_48 |
V_75 |
V_76 |
V_77 |
V_78 |
V_79 |
V_80 |
V_81 |
V_82 |
V_83 ,
V_74 , V_38 ) ;
if ( V_46 ) {
F_4 ( 0 , V_56 , V_84 ) ;
F_4 ( 0 , V_44 , V_85 ) ;
F_4 ( 0 , V_44 , V_86 ) ;
F_4 ( 0 , V_74 ,
V_84 ) ;
}
F_4 ( 0xffffffff , V_87 , V_88 ) ;
F_4 ( 0xffffffff , V_44 , V_88 ) ;
F_4 ( 0xffffffff , V_74 , V_88 ) ;
F_4 ( 0xffffffff , V_89 , V_88 ) ;
F_4 ( 0xffffffff , V_90 , V_88 ) ;
F_4 ( 0xffffffff , V_62 , V_88 ) ;
F_4 ( 0xffffffff , V_40 ,
V_88 ) ;
F_4 ( 0 , V_5 , V_6 ) ;
F_21 () ;
F_19 () ;
}
static void F_22 ( void )
{
F_23 ( V_52 , V_56 ,
V_57 ) ;
F_10 ( V_52 , V_56 ,
V_57 ) ;
F_2 ( V_56 , V_57 ) ;
}
static void F_24 ( void )
{
int V_91 = 0 ;
F_10 ( V_92 , V_56 ,
V_57 ) ;
F_25 ( F_2 ( V_56 , V_93 ) &
V_94 ,
V_95 , V_91 ) ;
if ( V_91 == V_95 )
F_26 ( L_1 ) ;
F_23 ( V_92 , V_56 ,
V_57 ) ;
F_10 ( V_94 , V_56 ,
V_93 ) ;
F_2 ( V_56 , V_93 ) ;
}
static void T_5 F_27 ( void )
{
if ( V_96 & V_97 )
F_10 ( V_52 , V_56 ,
V_57 ) ;
}
static T_1 F_28 ( void )
{
struct V_98 * V_99 ;
T_1 V_100 = 0 ;
T_1 V_101 ;
V_101 = F_2 ( V_56 , V_88 ) ;
V_99 = V_102 ;
while ( V_99 -> V_103 >= 0 && V_99 -> V_104 >= 0 ) {
if ( V_101 & ( 1 << V_99 -> V_103 ) )
V_100 |= 1 << V_99 -> V_104 ;
V_99 ++ ;
}
return V_100 ;
}
void F_21 ( void )
{
F_18 ( 0 , V_105 , V_106 ) ;
if ( ! ( F_16 ( V_105 , V_107 ) &
V_108 ) )
return;
F_4 ( V_109 |
V_110 |
V_111 ,
V_105 , V_14 ) ;
F_18 ( V_112 ,
V_105 , V_106 ) ;
F_4 ( 0 , V_105 , V_14 ) ;
F_18 ( 0 , V_105 , V_106 ) ;
F_4 ( V_109 |
V_110 |
V_111 ,
V_105 , V_14 ) ;
}
int F_29 ( void )
{
if ( F_2 ( V_9 , V_113 ) &
V_114 ) {
F_10 ( V_114 ,
V_9 ,
V_113 ) ;
return 1 ;
}
return 0 ;
}
void F_30 ( T_1 * V_115 )
{
* V_115 ++ = F_2 ( V_9 ,
V_51 ) ;
* V_115 ++ = F_2 ( V_9 ,
V_116 ) ;
}
static int F_31 ( struct V_117 * V_118 , T_2 V_119 )
{
F_8 ( V_120 ,
( V_119 << V_121 ) ,
V_118 -> V_122 , V_123 ) ;
return 0 ;
}
static int F_32 ( struct V_117 * V_118 )
{
return F_33 ( V_118 -> V_122 ,
V_123 ,
V_120 ) ;
}
static int F_34 ( struct V_117 * V_118 )
{
return F_33 ( V_118 -> V_122 ,
V_124 ,
V_125 ) ;
}
static int F_35 ( struct V_117 * V_118 )
{
return F_33 ( V_118 -> V_122 ,
V_126 ,
V_127 ) ;
}
static int F_36 ( struct V_117 * V_118 )
{
return F_33 ( V_118 -> V_122 ,
V_124 ,
V_128 ) ;
}
static int F_37 ( struct V_117 * V_118 )
{
return F_33 ( V_118 -> V_122 ,
V_123 ,
V_128 ) ;
}
static int F_38 ( struct V_117 * V_118 )
{
return F_33 ( V_118 -> V_122 ,
V_126 ,
V_129 ) ;
}
static int F_39 ( T_2 V_130 )
{
switch ( V_130 ) {
case 0 :
return V_131 ;
case 1 :
return V_132 ;
case 2 :
return V_133 ;
case 3 :
return V_134 ;
default:
F_40 ( 1 ) ;
return - V_135 ;
}
return 0 ;
}
static int F_41 ( struct V_117 * V_118 , T_2 V_130 )
{
T_1 V_136 ;
V_136 = F_39 ( V_130 ) ;
return F_33 ( V_118 -> V_122 ,
V_126 , V_136 ) ;
}
static int F_42 ( struct V_117 * V_118 )
{
F_4 ( 0 , V_118 -> V_122 , V_126 ) ;
return 0 ;
}
static int F_43 ( struct V_117 * V_118 )
{
return F_8 ( 0 ,
1 << V_137 ,
V_118 -> V_122 , V_123 ) ;
}
static int F_44 ( struct V_117 * V_118 )
{
return F_8 ( 1 << V_137 ,
0 , V_118 -> V_122 ,
V_123 ) ;
}
int T_5 F_45 ( const struct V_138 * V_139 )
{
F_46 ( V_140 ,
V_141 + V_105 ) ;
if ( F_47 () )
V_96 |= V_97 ;
return F_48 ( & V_142 ) ;
}
static int F_49 ( void )
{
int V_143 ;
if ( ! ( V_96 & V_97 ) )
return 0 ;
if ( F_50 () )
V_144 . V_145 =
F_24 ;
else
V_144 . V_145 =
F_22 ;
if ( F_51 () ) {
struct V_146 * V_147 ;
int V_148 ;
V_147 = F_52 ( NULL , V_149 ) ;
if ( V_147 ) {
V_148 = F_53 ( V_147 , 0 ) ;
if ( V_148 >= 0 )
V_144 . V_150 = V_148 ;
}
}
F_27 () ;
V_143 = F_54 ( & V_144 ) ;
if ( ! V_143 )
F_55 ( F_56 ( L_2 ) ,
V_151 ) ;
return V_143 ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_142 ) ;
}
