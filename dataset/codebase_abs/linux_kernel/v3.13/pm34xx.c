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
V_3 = F_18 ( ( T_1 * ) ( unsigned long )
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
if ( F_52 () )
return;
F_53 ( 1 , F_54 () ) ;
F_33 () ;
F_53 ( V_62 , F_54 () ) ;
}
static int F_55 ( void )
{
struct V_63 * V_64 ;
int V_65 , V_3 = 0 ;
F_56 (pwrst, &pwrst_list, node)
V_64 -> V_66 = F_15 ( V_64 -> V_67 ) ;
F_56 (pwrst, &pwrst_list, node) {
if ( F_57 ( V_64 -> V_67 , V_64 -> V_68 ) )
goto V_69;
if ( F_58 ( V_64 -> V_67 ) )
goto V_69;
}
F_59 () ;
F_33 () ;
V_69:
F_56 (pwrst, &pwrst_list, node) {
V_65 = F_43 ( V_64 -> V_67 ) ;
if ( V_65 > V_64 -> V_68 ) {
F_60 ( L_3 ,
V_64 -> V_67 -> V_70 , V_64 -> V_68 ) ;
V_3 = - 1 ;
}
F_57 ( V_64 -> V_67 , V_64 -> V_66 ) ;
}
if ( V_3 )
F_20 ( L_4 ) ;
else
F_60 ( L_5 ) ;
return V_3 ;
}
static void T_6 F_61 ( void )
{
F_26 ( 0 , V_71 , V_72 ) ;
if ( ! ( F_23 ( V_71 , V_73 ) &
V_74 ) )
return;
F_25 ( V_75 |
V_76 |
V_77 ,
V_71 , V_78 ) ;
F_26 ( V_79 ,
V_71 , V_72 ) ;
F_62 () ;
F_25 ( 0 , V_71 , V_78 ) ;
F_26 ( 0 , V_71 , V_72 ) ;
F_25 ( V_75 |
V_76 |
V_77 ,
V_71 , V_78 ) ;
}
static void T_6 F_63 ( void )
{
T_4 V_80 , V_81 ;
V_80 = ( 1 << 4 ) | ( 1 << 3 ) ;
V_81 = F_64 ( V_82 ) ;
V_81 |= V_80 ;
F_65 ( V_81 , V_82 ) ;
V_81 = F_64 ( V_83 ) ;
V_81 |= V_80 ;
F_65 ( V_81 , V_83 ) ;
F_25 ( V_84 |
V_85 ,
V_38 , V_78 ) ;
F_25 ( 0 , V_38 , V_78 ) ;
}
static void T_6 F_66 ( void )
{
T_1 V_86 = F_67 () ?
V_87 : 0 ;
T_1 V_88 = F_67 () ?
V_89 : 0 ;
F_3 ( V_90 , V_91 ) ;
F_68 ( V_92 ,
1 << V_93 ,
V_60 ,
V_94 ) ;
F_25 ( V_95 | V_96 |
V_97 | V_98 ,
V_33 , V_99 ) ;
F_25 ( V_100 |
V_101 |
V_102 ,
V_33 , V_27 ) ;
F_25 ( V_103 ,
V_104 , V_99 ) ;
F_25 ( V_86 |
V_105 | V_106 |
V_107 | V_108 |
V_109 | V_110 |
V_111 | V_112 |
V_113 ,
V_39 , V_99 ) ;
F_25 ( V_88 |
V_114 |
V_115 |
V_116 |
V_117 |
V_118 |
V_119 |
V_120 |
V_121 |
V_122 ,
V_39 , V_27 ) ;
if ( F_69 () ) {
F_25 ( 0 , V_33 , V_123 ) ;
F_25 ( 0 , V_38 , V_124 ) ;
F_25 ( 0 , V_38 , V_125 ) ;
F_25 ( 0 , V_39 ,
V_123 ) ;
}
F_25 ( 0xffffffff , V_126 , V_127 ) ;
F_25 ( 0xffffffff , V_38 , V_127 ) ;
F_25 ( 0xffffffff , V_39 , V_127 ) ;
F_25 ( 0xffffffff , V_128 , V_127 ) ;
F_25 ( 0xffffffff , V_129 , V_127 ) ;
F_25 ( 0xffffffff , V_104 , V_127 ) ;
F_25 ( 0xffffffff , V_29 , V_127 ) ;
F_25 ( 0 , V_130 , V_131 ) ;
F_61 () ;
F_63 () ;
}
void F_70 ( int V_132 )
{
struct V_63 * V_64 ;
T_1 V_65 ;
if ( V_132 )
V_65 = V_50 ;
else
V_65 = V_49 ;
F_56 (pwrst, &pwrst_list, node) {
if ( F_71 ( V_133 ) &&
V_64 -> V_67 == V_53 &&
V_65 == V_50 ) {
V_64 -> V_68 = V_49 ;
F_72 ( L_6 ,
V_134 ) ;
} else {
V_64 -> V_68 = V_65 ;
}
F_57 ( V_64 -> V_67 , V_64 -> V_68 ) ;
}
}
int F_73 ( struct V_135 * V_67 )
{
struct V_63 * V_64 ;
F_56 (pwrst, &pwrst_list, node) {
if ( V_64 -> V_67 == V_67 )
return V_64 -> V_68 ;
}
return - V_136 ;
}
int F_74 ( struct V_135 * V_67 , int V_65 )
{
struct V_63 * V_64 ;
F_56 (pwrst, &pwrst_list, node) {
if ( V_64 -> V_67 == V_67 ) {
V_64 -> V_68 = V_65 ;
return 0 ;
}
}
return - V_136 ;
}
static int T_6 F_75 ( struct V_135 * V_67 , void * V_32 )
{
struct V_63 * V_64 ;
if ( ! V_67 -> V_137 )
return 0 ;
V_64 = F_76 ( sizeof( struct V_63 ) , V_138 ) ;
if ( ! V_64 )
return - V_139 ;
V_64 -> V_67 = V_67 ;
V_64 -> V_68 = V_49 ;
F_77 ( & V_64 -> V_140 , & V_141 ) ;
if ( F_78 ( V_67 ) )
F_79 ( V_67 ) ;
return F_57 ( V_64 -> V_67 , V_64 -> V_68 ) ;
}
void F_80 ( void )
{
V_142 = F_81 ( V_143 , V_144 ) ;
if ( F_16 () != V_6 )
F_18 = F_81 ( V_145 ,
V_146 ) ;
}
static void T_6 F_82 ( void )
{
if ( F_67 () ) {
V_147 |= V_148 ;
F_83 () ;
if ( F_29 () < V_149 )
V_147 |= ( V_133 |
V_150 ) ;
} else if ( F_84 () ) {
V_147 |= V_150 ;
}
}
int T_6 F_85 ( void )
{
struct V_63 * V_64 , * V_151 ;
struct V_152 * V_153 , * V_154 , * V_155 , * V_156 ;
int V_3 ;
if ( ! F_86 () )
F_87 ( L_7 ) ;
F_82 () ;
F_66 () ;
V_3 = F_88 ( F_89 ( L_8 ) ,
F_28 , V_157 , L_9 , NULL ) ;
if ( V_3 ) {
F_20 ( L_10 ) ;
goto V_158;
}
V_3 = F_88 ( F_89 ( L_11 ) ,
F_27 , V_159 | V_157 , L_12 ,
F_85 ) ;
F_90 ( F_89 ( L_11 ) ) ;
if ( V_3 ) {
F_20 ( L_13 ) ;
goto V_160;
}
V_3 = F_91 ( F_75 , NULL ) ;
if ( V_3 ) {
F_20 ( L_14 ) ;
goto V_161;
}
( void ) F_92 ( V_162 , NULL ) ;
V_5 = F_93 ( L_15 ) ;
if ( V_5 == NULL ) {
F_20 ( L_16 ) ;
V_3 = - V_136 ;
goto V_161;
}
V_51 = F_93 ( L_17 ) ;
V_52 = F_93 ( L_18 ) ;
V_53 = F_93 ( L_19 ) ;
V_153 = F_94 ( L_20 ) ;
V_154 = F_94 ( L_21 ) ;
V_155 = F_94 ( L_22 ) ;
V_156 = F_94 ( L_23 ) ;
#ifdef F_95
V_163 = F_55 ;
#endif
V_164 = F_51 ;
F_96 () ;
if ( F_71 ( V_148 ) )
F_97 () ;
if ( F_71 ( V_150 ) )
F_98 ( V_155 , V_156 ) ;
F_98 ( V_153 , V_154 ) ;
if ( F_16 () != V_6 ) {
V_8 =
F_76 ( 0x803F , V_165 ) ;
if ( ! V_8 )
F_20 ( L_24 ) ;
F_99 () ;
F_8 () ;
F_14 () ;
F_13 () ;
F_100 () ;
}
F_101 () ;
return V_3 ;
V_161:
F_102 (pwrst, tmp, &pwrst_list, node) {
F_103 ( & V_64 -> V_140 ) ;
F_104 ( V_64 ) ;
}
F_105 ( F_89 ( L_11 ) , F_85 ) ;
V_160:
F_105 ( F_89 ( L_8 ) , NULL ) ;
V_158:
return V_3 ;
}
