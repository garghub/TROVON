static void F_1 ( void )
{
F_2 () ;
F_3 ( F_4 ( V_1 ) ,
V_2 + 0x2a0 ) ;
F_5 () ;
F_6 () ;
F_7 () ;
F_8 () ;
}
static void F_9 ( void )
{
F_10 () ;
F_11 () ;
F_12 () ;
F_13 () ;
}
static void F_14 ( void )
{
T_1 V_3 ;
int V_4 = F_15 ( V_5 ) ;
if ( F_16 () != V_6 ) {
F_17 ( V_5 , V_7 ) ;
V_3 = F_18 ( ( T_1 * )
F_19 ( V_8 ) ) ;
F_17 ( V_5 , V_4 ) ;
if ( V_3 ) {
F_20 ( L_1 , V_3 ) ;
while ( 1 )
;
}
}
}
static int F_21 ( T_2 V_9 , T_3 V_10 , T_1 V_11 )
{
T_1 V_12 , V_13 , V_14 , V_15 ;
T_4 V_16 = ( V_10 == 3 ) ? V_17 : V_18 ;
T_4 V_19 = ( V_10 == 3 ) ? V_20 : V_21 ;
T_4 V_22 = ( V_10 == 3 ) ? V_23 : V_24 ;
T_4 V_25 = ( V_10 == 3 ) ?
V_26 : V_27 ;
int V_28 = 0 ;
V_12 = F_22 ( V_9 , V_16 ) ;
V_12 &= F_22 ( V_9 , V_25 ) ;
V_12 &= ~ V_11 ;
if ( V_12 ) {
V_14 = F_23 ( V_9 , V_22 ) ;
V_13 = F_23 ( V_9 , V_19 ) ;
while ( V_12 ) {
V_15 = V_12 ;
F_24 ( V_15 , V_9 , V_22 ) ;
if ( V_9 == V_29 )
V_15 |= 1 << V_30 ;
F_24 ( V_15 , V_9 , V_19 ) ;
F_25 ( V_12 , V_9 , V_16 ) ;
V_12 = F_22 ( V_9 , V_16 ) ;
V_12 &= ~ V_11 ;
V_28 ++ ;
}
F_26 ( V_14 , V_9 , V_22 ) ;
F_26 ( V_13 , V_9 , V_19 ) ;
}
return V_28 ;
}
static T_5 F_27 ( int V_31 , void * V_32 )
{
int V_28 ;
V_28 = F_21 ( V_33 , 1 ,
~ ( V_34 | V_35 ) ) ;
return V_28 ? V_36 : V_37 ;
}
static T_5 F_28 ( int V_31 , void * V_32 )
{
int V_28 ;
V_28 = F_21 ( V_33 , 1 ,
V_34 | V_35 ) ;
V_28 += F_21 ( V_38 , 1 , 0 ) ;
V_28 += F_21 ( V_39 , 1 , 0 ) ;
if ( F_29 () > V_40 ) {
V_28 += F_21 ( V_38 , 3 , 0 ) ;
V_28 += F_21 ( V_29 , 1 , 0 ) ;
}
return V_28 ? V_36 : V_37 ;
}
static void F_30 ( T_1 * V_41 )
{
T_1 V_42 ;
asm("mrc p15, 0, %0, c1, c0, 1" : "=r" (val));
* V_41 ++ = 1 ;
* V_41 ++ = V_42 ;
asm("mrc p15, 1, %0, c9, c0, 2" : "=r" (val));
* V_41 ++ = 1 ;
* V_41 ++ = V_42 ;
}
static int F_31 ( unsigned long V_43 )
{
F_32 ( V_43 ) ;
return 0 ;
}
void F_33 ( void )
{
int V_43 = 0 ;
int V_4 = V_7 ;
int V_44 = V_7 ;
int V_45 = V_7 ;
int V_46 ;
int V_47 ;
T_1 V_48 = 0 ;
V_4 = F_15 ( V_5 ) ;
switch ( V_4 ) {
case V_7 :
case V_49 :
V_43 = 0 ;
break;
case V_50 :
V_43 = 3 ;
break;
default:
F_20 ( L_2 ) ;
return;
}
if ( F_34 ( V_51 ) == V_7 )
F_17 ( V_51 , V_4 ) ;
V_44 = F_15 ( V_52 ) ;
V_45 = F_15 ( V_53 ) ;
F_35 ( NULL ) ;
if ( V_44 < V_7 ) {
V_46 = ( V_44 == V_50 ) ? 1 : 0 ;
F_36 ( V_46 ) ;
}
if ( V_45 < V_7 ) {
if ( V_45 == V_50 ) {
F_1 () ;
F_37 () ;
}
}
F_38 () ;
if ( F_39 () && F_29 () >= V_54 &&
( F_16 () == V_55 ||
F_16 () == V_56 ) &&
V_45 == V_50 )
V_48 = F_40 ( V_57 ) ;
if ( V_43 )
F_30 ( V_58 ) ;
if ( V_43 == 1 || V_43 == 3 )
F_41 ( V_43 , F_31 ) ;
else
F_31 ( V_43 ) ;
if ( F_39 () && F_29 () >= V_54 &&
( F_16 () == V_55 ||
F_16 () == V_56 ) &&
V_45 == V_50 )
F_42 ( V_48 , V_57 ) ;
if ( V_45 < V_7 ) {
V_47 = F_43 ( V_53 ) ;
if ( V_47 == V_50 ) {
F_9 () ;
F_44 () ;
F_45 () ;
F_46 () ;
}
if ( V_45 == V_50 )
F_47 ( V_59 ,
V_60 ,
V_61 ) ;
}
F_48 () ;
F_49 ( NULL ) ;
if ( V_44 < V_7 )
F_50 () ;
}
static void F_51 ( void )
{
F_52 () ;
if ( F_53 () )
goto V_62;
F_54 ( 1 , F_55 () ) ;
F_33 () ;
F_54 ( V_63 , F_55 () ) ;
V_62:
F_56 () ;
}
static int F_57 ( void )
{
struct V_64 * V_65 ;
int V_66 , V_3 = 0 ;
F_58 (pwrst, &pwrst_list, node)
V_65 -> V_67 = F_15 ( V_65 -> V_68 ) ;
F_58 (pwrst, &pwrst_list, node) {
if ( F_59 ( V_65 -> V_68 , V_65 -> V_69 ) )
goto V_70;
if ( F_60 ( V_65 -> V_68 ) )
goto V_70;
}
F_61 () ;
F_33 () ;
V_70:
F_58 (pwrst, &pwrst_list, node) {
V_66 = F_43 ( V_65 -> V_68 ) ;
if ( V_66 > V_65 -> V_69 ) {
F_62 ( L_3 ,
V_65 -> V_68 -> V_71 , V_65 -> V_69 ) ;
V_3 = - 1 ;
}
F_59 ( V_65 -> V_68 , V_65 -> V_67 ) ;
}
if ( V_3 )
F_20 ( L_4 ) ;
else
F_62 ( L_5 ) ;
return V_3 ;
}
static void T_6 F_63 ( void )
{
F_26 ( 0 , V_72 , V_73 ) ;
if ( ! ( F_23 ( V_72 , V_74 ) &
V_75 ) )
return;
F_25 ( V_76 |
V_77 |
V_78 ,
V_72 , V_79 ) ;
F_26 ( V_80 ,
V_72 , V_73 ) ;
F_3 ( V_81 ,
V_82 ) ;
F_25 ( 0 , V_72 , V_79 ) ;
F_26 ( 0 , V_72 , V_73 ) ;
F_25 ( V_76 |
V_77 |
V_78 ,
V_72 , V_79 ) ;
}
static void T_6 F_64 ( void )
{
T_4 V_83 , V_84 ;
V_83 = ( 1 << 4 ) | ( 1 << 3 ) ;
V_84 = F_65 ( V_85 ) ;
V_84 |= V_83 ;
F_66 ( V_84 , V_85 ) ;
V_84 = F_65 ( V_86 ) ;
V_84 |= V_83 ;
F_66 ( V_84 , V_86 ) ;
F_25 ( V_87 |
V_88 ,
V_38 , V_79 ) ;
F_25 ( 0 , V_38 , V_79 ) ;
}
static void T_6 F_67 ( void )
{
T_1 V_89 = F_68 () ?
V_90 : 0 ;
T_1 V_91 = F_68 () ?
V_92 : 0 ;
F_3 ( V_93 , V_94 ) ;
F_69 ( V_95 ,
1 << V_96 ,
V_60 ,
V_97 ) ;
F_25 ( V_98 | V_99 |
V_100 | V_101 ,
V_33 , V_102 ) ;
F_25 ( V_103 |
V_104 |
V_105 ,
V_33 , V_27 ) ;
F_25 ( V_106 ,
V_107 , V_102 ) ;
F_25 ( V_89 |
V_108 | V_109 |
V_110 | V_111 |
V_112 | V_113 |
V_114 | V_115 |
V_116 ,
V_39 , V_102 ) ;
F_25 ( V_91 |
V_117 |
V_118 |
V_119 |
V_120 |
V_121 |
V_122 |
V_123 |
V_124 |
V_125 ,
V_39 , V_27 ) ;
if ( F_70 () ) {
F_25 ( 0 , V_33 , V_126 ) ;
F_25 ( 0 , V_38 , V_127 ) ;
F_25 ( 0 , V_38 , V_128 ) ;
F_25 ( 0 , V_39 ,
V_126 ) ;
}
F_25 ( 0xffffffff , V_129 , V_130 ) ;
F_25 ( 0xffffffff , V_38 , V_130 ) ;
F_25 ( 0xffffffff , V_39 , V_130 ) ;
F_25 ( 0xffffffff , V_131 , V_130 ) ;
F_25 ( 0xffffffff , V_132 , V_130 ) ;
F_25 ( 0xffffffff , V_107 , V_130 ) ;
F_25 ( 0xffffffff , V_29 , V_130 ) ;
F_25 ( 0 , V_133 , V_134 ) ;
if ( F_70 () )
F_63 () ;
F_64 () ;
}
void F_71 ( int V_135 )
{
struct V_64 * V_65 ;
T_1 V_66 ;
if ( V_135 )
V_66 = V_50 ;
else
V_66 = V_49 ;
F_58 (pwrst, &pwrst_list, node) {
if ( F_72 ( V_136 ) &&
V_65 -> V_68 == V_53 &&
V_66 == V_50 ) {
V_65 -> V_69 = V_49 ;
F_73 ( L_6 ,
V_137 ) ;
} else {
V_65 -> V_69 = V_66 ;
}
F_59 ( V_65 -> V_68 , V_65 -> V_69 ) ;
}
}
int F_74 ( struct V_138 * V_68 )
{
struct V_64 * V_65 ;
F_58 (pwrst, &pwrst_list, node) {
if ( V_65 -> V_68 == V_68 )
return V_65 -> V_69 ;
}
return - V_139 ;
}
int F_75 ( struct V_138 * V_68 , int V_66 )
{
struct V_64 * V_65 ;
F_58 (pwrst, &pwrst_list, node) {
if ( V_65 -> V_68 == V_68 ) {
V_65 -> V_69 = V_66 ;
return 0 ;
}
}
return - V_139 ;
}
static int T_6 F_76 ( struct V_138 * V_68 , void * V_32 )
{
struct V_64 * V_65 ;
if ( ! V_68 -> V_140 )
return 0 ;
V_65 = F_77 ( sizeof( struct V_64 ) , V_141 ) ;
if ( ! V_65 )
return - V_142 ;
V_65 -> V_68 = V_68 ;
V_65 -> V_69 = V_49 ;
F_78 ( & V_65 -> V_143 , & V_144 ) ;
if ( F_79 ( V_68 ) )
F_80 ( V_68 ) ;
return F_59 ( V_65 -> V_68 , V_65 -> V_69 ) ;
}
void F_81 ( void )
{
V_145 = F_82 ( V_146 , V_147 ) ;
if ( F_16 () != V_6 )
F_18 = F_82 ( V_148 ,
V_149 ) ;
}
static void T_6 F_83 ( void )
{
if ( F_68 () ) {
V_150 |= V_151 ;
F_84 () ;
if ( F_29 () < V_152 )
V_150 |= ( V_136 |
V_153 ) ;
} else if ( F_85 () ) {
V_150 |= V_153 ;
}
}
int T_6 F_86 ( void )
{
struct V_64 * V_65 , * V_154 ;
struct V_155 * V_156 , * V_157 , * V_158 , * V_159 ;
int V_3 ;
if ( ! F_87 () )
F_88 ( L_7 ) ;
F_83 () ;
F_67 () ;
V_3 = F_89 ( F_90 ( L_8 ) ,
F_28 , V_160 , L_9 , NULL ) ;
if ( V_3 ) {
F_20 ( L_10 ) ;
goto V_161;
}
V_3 = F_89 ( F_90 ( L_11 ) ,
F_27 , V_162 | V_160 , L_12 ,
F_86 ) ;
F_91 ( F_90 ( L_11 ) ) ;
if ( V_3 ) {
F_20 ( L_13 ) ;
goto V_163;
}
V_3 = F_92 ( F_76 , NULL ) ;
if ( V_3 ) {
F_20 ( L_14 ) ;
goto V_164;
}
( void ) F_93 ( V_165 , NULL ) ;
V_5 = F_94 ( L_15 ) ;
if ( V_5 == NULL ) {
F_20 ( L_16 ) ;
V_3 = - V_139 ;
goto V_164;
}
V_51 = F_94 ( L_17 ) ;
V_52 = F_94 ( L_18 ) ;
V_53 = F_94 ( L_19 ) ;
V_156 = F_95 ( L_20 ) ;
V_157 = F_95 ( L_21 ) ;
V_158 = F_95 ( L_22 ) ;
V_159 = F_95 ( L_23 ) ;
#ifdef F_96
V_166 = F_57 ;
#endif
V_167 = F_51 ;
F_97 () ;
if ( F_72 ( V_151 ) )
F_98 () ;
if ( F_72 ( V_153 ) )
F_99 ( V_158 , V_159 ) ;
F_99 ( V_156 , V_157 ) ;
if ( F_16 () != V_6 ) {
V_8 =
F_77 ( 0x803F , V_168 ) ;
if ( ! V_8 )
F_20 ( L_24 ) ;
F_100 () ;
F_52 () ;
F_8 () ;
F_14 () ;
F_13 () ;
F_101 () ;
F_56 () ;
}
F_102 () ;
return V_3 ;
V_164:
F_103 (pwrst, tmp, &pwrst_list, node) {
F_104 ( & V_65 -> V_143 ) ;
F_105 ( V_65 ) ;
}
F_106 ( F_90 ( L_11 ) , F_86 ) ;
V_163:
F_106 ( F_90 ( L_8 ) , NULL ) ;
V_161:
return V_3 ;
}
