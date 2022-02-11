T_1 F_1 ( T_2 V_1 )
{
struct V_2 * V_3 = & V_2 [ V_1 ] ;
T_1 V_4 ;
V_4 = F_2 ( V_5 ,
V_6 ) ;
return V_4 & V_3 -> V_7 ;
}
void F_3 ( T_2 V_1 )
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
void F_9 ( void )
{
F_10 ( V_13 , V_9 ,
V_14 ) ;
F_2 ( V_9 , V_14 ) ;
}
void F_11 ( unsigned long * V_15 )
{
T_1 V_11 , V_16 ;
V_11 = F_2 ( V_5 , V_17 ) ;
V_16 = F_2 ( V_5 , V_6 ) ;
V_15 [ 0 ] = V_11 & V_16 ;
}
void F_12 ( void )
{
F_2 ( V_5 , V_18 ) ;
}
void F_13 ( T_1 * V_19 )
{
V_19 [ 0 ] = F_2 ( V_5 ,
V_17 ) ;
F_4 ( 0 , V_5 , V_17 ) ;
F_2 ( V_5 , V_18 ) ;
}
void F_14 ( T_1 * V_19 )
{
F_4 ( V_19 [ 0 ] , V_5 ,
V_17 ) ;
}
int F_15 ( T_3 V_20 , T_2 V_21 , T_1 V_22 )
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
V_23 &= ~ V_22 ;
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
V_23 &= ~ V_22 ;
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
void F_22 ( void )
{
F_23 ( V_52 , V_56 ,
V_57 ) ;
F_10 ( V_52 , V_56 ,
V_57 ) ;
F_2 ( V_56 , V_57 ) ;
}
void F_24 ( void )
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
void F_27 ( void )
{
if ( V_96 . V_97 )
V_96 . V_97 () ;
}
static void T_5 F_28 ( void )
{
if ( V_98 & V_99 )
F_10 ( V_52 , V_56 ,
V_57 ) ;
}
static T_1 F_29 ( void )
{
struct V_100 * V_101 ;
T_1 V_102 = 0 ;
T_1 V_103 ;
V_103 = F_2 ( V_56 , V_88 ) ;
V_101 = V_104 ;
while ( V_101 -> V_105 >= 0 && V_101 -> V_106 >= 0 ) {
if ( V_103 & ( 1 << V_101 -> V_105 ) )
V_102 |= 1 << V_101 -> V_106 ;
V_101 ++ ;
}
return V_102 ;
}
void F_21 ( void )
{
F_18 ( 0 , V_107 , V_108 ) ;
if ( ! ( F_16 ( V_107 , V_109 ) &
V_110 ) )
return;
F_4 ( V_111 |
V_112 |
V_113 ,
V_107 , V_14 ) ;
F_18 ( V_114 ,
V_107 , V_108 ) ;
F_4 ( 0 , V_107 , V_14 ) ;
F_18 ( 0 , V_107 , V_108 ) ;
F_4 ( V_111 |
V_112 |
V_113 ,
V_107 , V_14 ) ;
}
int F_30 ( void )
{
if ( F_2 ( V_9 , V_115 ) &
V_116 ) {
F_10 ( V_116 ,
V_9 ,
V_115 ) ;
return 1 ;
}
return 0 ;
}
void F_31 ( T_1 * V_117 )
{
* V_117 ++ = F_2 ( V_9 ,
V_51 ) ;
* V_117 ++ = F_2 ( V_9 ,
V_118 ) ;
}
static int F_32 ( struct V_119 * V_120 , T_2 V_121 )
{
F_8 ( V_122 ,
( V_121 << V_123 ) ,
V_120 -> V_124 , V_125 ) ;
return 0 ;
}
static int F_33 ( struct V_119 * V_120 )
{
return F_34 ( V_120 -> V_124 ,
V_125 ,
V_122 ) ;
}
static int F_35 ( struct V_119 * V_120 )
{
return F_34 ( V_120 -> V_124 ,
V_126 ,
V_127 ) ;
}
static int F_36 ( struct V_119 * V_120 )
{
return F_34 ( V_120 -> V_124 ,
V_128 ,
V_129 ) ;
}
static int F_37 ( struct V_119 * V_120 )
{
return F_34 ( V_120 -> V_124 ,
V_126 ,
V_130 ) ;
}
static int F_38 ( struct V_119 * V_120 )
{
return F_34 ( V_120 -> V_124 ,
V_125 ,
V_130 ) ;
}
static int F_39 ( struct V_119 * V_120 )
{
return F_34 ( V_120 -> V_124 ,
V_128 ,
V_131 ) ;
}
static int F_40 ( T_2 V_132 )
{
switch ( V_132 ) {
case 0 :
return V_133 ;
case 1 :
return V_134 ;
case 2 :
return V_135 ;
case 3 :
return V_136 ;
default:
F_41 ( 1 ) ;
return - V_137 ;
}
return 0 ;
}
static int F_42 ( struct V_119 * V_120 , T_2 V_132 )
{
T_1 V_138 ;
V_138 = F_40 ( V_132 ) ;
return F_34 ( V_120 -> V_124 ,
V_128 , V_138 ) ;
}
static int F_43 ( struct V_119 * V_120 )
{
F_4 ( 0 , V_120 -> V_124 , V_128 ) ;
return 0 ;
}
static int F_44 ( struct V_119 * V_120 )
{
return F_8 ( 0 ,
1 << V_139 ,
V_120 -> V_124 , V_125 ) ;
}
static int F_45 ( struct V_119 * V_120 )
{
return F_8 ( 1 << V_139 ,
0 , V_120 -> V_124 ,
V_125 ) ;
}
int T_5 F_46 ( void )
{
if ( F_47 () )
V_98 |= V_99 ;
return F_48 ( & V_140 ) ;
}
static int F_49 ( void )
{
int V_141 ;
if ( ! ( V_98 & V_99 ) )
return 0 ;
if ( F_50 () )
V_96 . V_97 =
F_24 ;
else
V_96 . V_97 =
F_22 ;
if ( F_51 () ) {
struct V_142 * V_143 ;
int V_144 ;
V_143 = F_52 ( NULL , V_145 ) ;
if ( V_143 ) {
V_144 = F_53 ( V_143 , 0 ) ;
if ( V_144 >= 0 )
V_96 . V_146 = V_144 ;
}
}
F_28 () ;
V_141 = F_54 ( & V_96 ) ;
if ( ! V_141 )
F_55 ( F_56 ( L_2 ) ,
V_147 ) ;
return V_141 ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_140 ) ;
}
