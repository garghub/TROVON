static void F_1 ( void )
{
int V_1 = 0 ;
F_2 ( V_2 , V_3 ,
V_4 ) ;
F_3 ( V_3 , V_4 ) ;
while ( ! ( F_3 ( V_3 , V_4 ) &
V_5 ) ) {
V_1 ++ ;
if ( V_1 > 1000 ) {
F_4 ( L_1 ) ;
return;
}
F_2 ( V_5 ,
V_3 , V_4 ) ;
}
}
static void F_5 ( void )
{
F_6 ( V_2 , V_3 ,
V_4 ) ;
}
static void F_7 ( void )
{
F_8 () ;
F_9 ( F_10 ( V_6 ) ,
V_7 + 0x2a0 ) ;
F_11 () ;
F_12 () ;
F_13 () ;
F_14 () ;
}
static void F_15 ( void )
{
F_16 () ;
F_17 () ;
F_18 () ;
F_19 () ;
}
static void F_20 ( void )
{
T_1 V_8 ;
int V_9 = F_21 ( V_10 ) ;
if ( F_22 () != V_11 ) {
F_23 ( V_10 , V_12 ) ;
V_8 = F_24 ( ( T_1 * )
F_25 ( V_13 ) ) ;
F_23 ( V_10 , V_9 ) ;
if ( V_8 ) {
F_4 ( L_2 , V_8 ) ;
while ( 1 )
;
}
}
}
static int F_26 ( T_2 V_14 , T_3 V_15 , T_1 V_16 )
{
T_1 V_17 , V_18 , V_19 , V_20 ;
T_4 V_21 = ( V_15 == 3 ) ? V_22 : V_23 ;
T_4 V_24 = ( V_15 == 3 ) ? V_25 : V_26 ;
T_4 V_27 = ( V_15 == 3 ) ? V_28 : V_29 ;
T_4 V_30 = ( V_15 == 3 ) ?
V_31 : V_32 ;
int V_33 = 0 ;
V_17 = F_3 ( V_14 , V_21 ) ;
V_17 &= F_3 ( V_14 , V_30 ) ;
V_17 &= ~ V_16 ;
if ( V_17 ) {
V_19 = F_27 ( V_14 , V_27 ) ;
V_18 = F_27 ( V_14 , V_24 ) ;
while ( V_17 ) {
V_20 = V_17 ;
F_28 ( V_20 , V_14 , V_27 ) ;
if ( V_14 == V_34 )
V_20 |= 1 << V_35 ;
F_28 ( V_20 , V_14 , V_24 ) ;
F_29 ( V_17 , V_14 , V_21 ) ;
V_17 = F_3 ( V_14 , V_21 ) ;
V_17 &= ~ V_16 ;
V_33 ++ ;
}
F_30 ( V_19 , V_14 , V_27 ) ;
F_30 ( V_18 , V_14 , V_24 ) ;
}
return V_33 ;
}
static T_5 F_31 ( int V_36 , void * V_37 )
{
int V_33 ;
V_33 = F_26 ( V_3 , 1 ,
~ ( V_38 | V_5 ) ) ;
return V_33 ? V_39 : V_40 ;
}
static T_5 F_32 ( int V_36 , void * V_37 )
{
int V_33 ;
V_33 = F_26 ( V_3 , 1 ,
V_38 | V_5 ) ;
V_33 += F_26 ( V_41 , 1 , 0 ) ;
V_33 += F_26 ( V_42 , 1 , 0 ) ;
if ( F_33 () > V_43 ) {
V_33 += F_26 ( V_41 , 3 , 0 ) ;
V_33 += F_26 ( V_34 , 1 , 0 ) ;
}
return V_33 ? V_39 : V_40 ;
}
static void F_34 ( T_1 * V_44 )
{
T_1 V_45 ;
asm("mrc p15, 0, %0, c1, c0, 1" : "=r" (val));
* V_44 ++ = 1 ;
* V_44 ++ = V_45 ;
asm("mrc p15, 1, %0, c9, c0, 2" : "=r" (val));
* V_44 ++ = 1 ;
* V_44 ++ = V_45 ;
}
static int F_35 ( unsigned long V_46 )
{
F_36 ( V_46 ) ;
return 0 ;
}
void F_37 ( void )
{
int V_46 = 0 ;
int V_9 = V_12 ;
int V_47 = V_12 ;
int V_48 = V_12 ;
int V_49 ;
int V_50 ;
T_1 V_51 = 0 ;
V_9 = F_21 ( V_10 ) ;
switch ( V_9 ) {
case V_12 :
case V_52 :
V_46 = 0 ;
break;
case V_53 :
V_46 = 3 ;
break;
default:
F_4 ( L_3 ) ;
return;
}
if ( F_38 ( V_54 ) == V_12 )
F_23 ( V_54 , V_9 ) ;
V_47 = F_21 ( V_55 ) ;
V_48 = F_21 ( V_56 ) ;
if ( F_39 () &&
( V_47 < V_12 ||
V_48 < V_12 ) ) {
F_2 ( V_57 , V_3 , V_4 ) ;
if ( F_40 () )
F_1 () ;
}
F_41 () ;
if ( V_47 < V_12 ) {
V_49 = ( V_47 == V_53 ) ? 1 : 0 ;
F_42 ( V_49 ) ;
}
if ( V_48 < V_12 ) {
if ( V_48 == V_53 ) {
F_7 () ;
F_43 () ;
}
}
F_44 () ;
if ( F_45 () && F_33 () >= V_58 &&
( F_22 () == V_59 ||
F_22 () == V_60 ) &&
V_48 == V_53 )
V_51 = F_46 ( V_61 ) ;
if ( V_46 )
F_34 ( V_62 ) ;
if ( V_46 == 1 || V_46 == 3 )
F_47 ( V_46 , F_35 ) ;
else
F_35 ( V_46 ) ;
if ( F_45 () && F_33 () >= V_58 &&
( F_22 () == V_59 ||
F_22 () == V_60 ) &&
V_48 == V_53 )
F_48 ( V_51 , V_61 ) ;
if ( V_48 < V_12 ) {
V_50 = F_49 ( V_56 ) ;
if ( V_50 == V_53 ) {
F_15 () ;
F_50 () ;
F_51 () ;
F_52 () ;
}
if ( V_48 == V_53 )
F_6 ( V_63 ,
V_64 ,
V_65 ) ;
}
F_53 () ;
F_54 () ;
if ( V_47 < V_12 )
F_55 () ;
if ( F_39 () &&
( V_47 < V_12 ||
V_48 < V_12 ) ) {
F_6 ( V_57 , V_3 ,
V_4 ) ;
if ( F_40 () )
F_5 () ;
}
F_56 ( V_10 -> V_66 [ 0 ] ) ;
}
static void F_57 ( void )
{
F_58 () ;
if ( F_59 () )
goto V_67;
F_60 ( V_68 , 1 , F_61 () ) ;
F_62 ( 1 , F_61 () ) ;
F_37 () ;
F_63 ( F_61 () ) ;
F_62 ( V_69 , F_61 () ) ;
V_67:
F_64 () ;
}
static int F_65 ( void )
{
struct V_70 * V_71 ;
int V_72 , V_8 = 0 ;
F_66 (pwrst, &pwrst_list, node)
V_71 -> V_73 = F_21 ( V_71 -> V_74 ) ;
F_66 (pwrst, &pwrst_list, node) {
if ( F_67 ( V_71 -> V_74 , V_71 -> V_75 ) )
goto V_76;
if ( F_68 ( V_71 -> V_74 ) )
goto V_76;
}
F_69 () ;
F_37 () ;
V_76:
F_66 (pwrst, &pwrst_list, node) {
V_72 = F_49 ( V_71 -> V_74 ) ;
if ( V_72 > V_71 -> V_75 ) {
F_70 ( L_4
L_5 ,
V_71 -> V_74 -> V_77 , V_71 -> V_75 ) ;
V_8 = - 1 ;
}
F_67 ( V_71 -> V_74 , V_71 -> V_73 ) ;
}
if ( V_8 )
F_4 ( L_6 ) ;
else
F_70 ( L_7 ) ;
return V_8 ;
}
static void T_6 F_71 ( void )
{
F_30 ( 0 , V_78 , V_79 ) ;
if ( ! ( F_27 ( V_78 , V_80 ) &
V_81 ) )
return;
F_29 ( V_82 |
V_83 |
V_84 ,
V_78 , V_85 ) ;
F_30 ( V_86 ,
V_78 , V_79 ) ;
F_9 ( V_87 ,
V_88 ) ;
F_29 ( 0 , V_78 , V_85 ) ;
F_30 ( 0 , V_78 , V_79 ) ;
F_29 ( V_82 |
V_83 |
V_84 ,
V_78 , V_85 ) ;
}
static void T_6 F_72 ( void )
{
T_4 V_89 , V_90 ;
V_89 = ( 1 << 4 ) | ( 1 << 3 ) ;
V_90 = F_73 ( V_91 ) ;
V_90 |= V_89 ;
F_74 ( V_90 , V_91 ) ;
V_90 = F_73 ( V_92 ) ;
V_90 |= V_89 ;
F_74 ( V_90 , V_92 ) ;
F_29 ( V_93 |
V_94 ,
V_41 , V_85 ) ;
F_29 ( 0 , V_41 , V_85 ) ;
}
static void T_6 F_75 ( void )
{
T_1 V_95 = F_76 () ?
V_96 : 0 ;
T_1 V_97 = F_76 () ?
V_98 : 0 ;
F_9 ( V_99 , V_100 ) ;
F_77 ( V_101 ,
1 << V_102 ,
V_64 ,
V_103 ) ;
F_29 ( V_57 | V_104 |
V_105 | V_106 ,
V_3 , V_4 ) ;
F_29 ( V_107 |
V_108 |
V_109 ,
V_3 , V_32 ) ;
F_29 ( V_110 ,
V_111 , V_4 ) ;
F_29 ( V_95 |
V_112 | V_113 |
V_114 | V_115 |
V_116 | V_117 |
V_118 | V_119 |
V_120 ,
V_42 , V_4 ) ;
F_29 ( V_97 |
V_121 |
V_122 |
V_123 |
V_124 |
V_125 |
V_126 |
V_127 |
V_128 |
V_129 ,
V_42 , V_32 ) ;
F_29 ( 0 , V_3 , V_130 ) ;
F_29 ( 0 , V_41 , V_131 ) ;
F_29 ( 0 , V_41 , V_132 ) ;
F_29 ( 0 , V_42 , V_130 ) ;
F_29 ( 0xffffffff , V_133 , V_134 ) ;
F_29 ( 0xffffffff , V_41 , V_134 ) ;
F_29 ( 0xffffffff , V_42 , V_134 ) ;
F_29 ( 0xffffffff , V_135 , V_134 ) ;
F_29 ( 0xffffffff , V_136 , V_134 ) ;
F_29 ( 0xffffffff , V_111 , V_134 ) ;
F_29 ( 0xffffffff , V_34 , V_134 ) ;
F_29 ( 0 , V_137 , V_138 ) ;
F_71 () ;
F_72 () ;
}
void F_78 ( int V_139 )
{
struct V_70 * V_71 ;
T_1 V_72 ;
if ( V_139 )
V_72 = V_53 ;
else
V_72 = V_52 ;
F_66 (pwrst, &pwrst_list, node) {
if ( F_79 ( V_140 ) &&
V_71 -> V_74 == V_56 &&
V_72 == V_53 ) {
V_71 -> V_75 = V_52 ;
F_80 ( L_8 ,
V_141 ) ;
} else {
V_71 -> V_75 = V_72 ;
}
F_67 ( V_71 -> V_74 , V_71 -> V_75 ) ;
}
}
int F_81 ( struct V_142 * V_74 )
{
struct V_70 * V_71 ;
F_66 (pwrst, &pwrst_list, node) {
if ( V_71 -> V_74 == V_74 )
return V_71 -> V_75 ;
}
return - V_143 ;
}
int F_82 ( struct V_142 * V_74 , int V_72 )
{
struct V_70 * V_71 ;
F_66 (pwrst, &pwrst_list, node) {
if ( V_71 -> V_74 == V_74 ) {
V_71 -> V_75 = V_72 ;
return 0 ;
}
}
return - V_143 ;
}
static int T_6 F_83 ( struct V_142 * V_74 , void * V_37 )
{
struct V_70 * V_71 ;
if ( ! V_74 -> V_144 )
return 0 ;
V_71 = F_84 ( sizeof( struct V_70 ) , V_145 ) ;
if ( ! V_71 )
return - V_146 ;
V_71 -> V_74 = V_74 ;
V_71 -> V_75 = V_52 ;
F_85 ( & V_71 -> V_147 , & V_148 ) ;
if ( F_86 ( V_74 ) )
F_87 ( V_74 ) ;
return F_67 ( V_71 -> V_74 , V_71 -> V_75 ) ;
}
void F_88 ( void )
{
V_149 = F_89 ( V_150 , V_151 ) ;
if ( F_22 () != V_11 )
F_24 = F_89 ( V_152 ,
V_153 ) ;
}
static void T_6 F_90 ( void )
{
if ( F_76 () ) {
V_154 |= V_155 ;
F_91 () ;
if ( F_33 () < V_156 )
V_154 |= V_140 ;
}
}
int T_6 F_92 ( void )
{
struct V_70 * V_71 , * V_157 ;
struct V_158 * V_159 , * V_160 ;
int V_8 ;
if ( ! F_40 () )
F_93 ( L_9 ) ;
F_90 () ;
F_75 () ;
V_8 = F_94 ( F_95 ( L_10 ) ,
F_32 , V_161 , L_11 , NULL ) ;
if ( V_8 ) {
F_4 ( L_12 ) ;
goto V_162;
}
V_8 = F_94 ( F_95 ( L_13 ) ,
F_31 , V_163 | V_161 , L_14 ,
F_92 ) ;
F_96 ( F_95 ( L_13 ) ) ;
if ( V_8 ) {
F_4 ( L_15 ) ;
goto V_164;
}
V_8 = F_97 ( F_83 , NULL ) ;
if ( V_8 ) {
F_4 ( L_16 ) ;
goto V_165;
}
( void ) F_98 ( V_166 , NULL ) ;
V_10 = F_99 ( L_17 ) ;
if ( V_10 == NULL ) {
F_4 ( L_18 ) ;
V_8 = - V_143 ;
goto V_165;
}
V_54 = F_99 ( L_19 ) ;
V_55 = F_99 ( L_20 ) ;
V_56 = F_99 ( L_21 ) ;
V_167 = F_99 ( L_22 ) ;
V_159 = F_100 ( L_23 ) ;
V_160 = F_100 ( L_24 ) ;
#ifdef F_101
V_168 = F_65 ;
#endif
V_169 = F_57 ;
F_102 () ;
if ( F_79 ( V_155 ) )
F_103 () ;
F_104 ( V_159 , V_160 ) ;
if ( F_22 () != V_11 ) {
V_13 =
F_84 ( 0x803F , V_170 ) ;
if ( ! V_13 )
F_4 ( L_25
L_26 ) ;
F_105 () ;
F_58 () ;
F_14 () ;
F_20 () ;
F_19 () ;
F_106 () ;
F_64 () ;
}
F_107 () ;
return V_8 ;
V_165:
F_108 (pwrst, tmp, &pwrst_list, node) {
F_109 ( & V_71 -> V_147 ) ;
F_110 ( V_71 ) ;
}
F_111 ( F_95 ( L_13 ) , F_92 ) ;
V_164:
F_111 ( F_95 ( L_10 ) , NULL ) ;
V_162:
return V_8 ;
}
