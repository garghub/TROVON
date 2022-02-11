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
F_54 ( V_63 , 1 , F_55 () ) ;
F_56 ( 1 , F_55 () ) ;
F_33 () ;
F_57 ( F_55 () ) ;
F_56 ( V_64 , F_55 () ) ;
V_62:
F_58 () ;
}
static int F_59 ( void )
{
struct V_65 * V_66 ;
int V_67 , V_3 = 0 ;
F_60 (pwrst, &pwrst_list, node)
V_66 -> V_68 = F_15 ( V_66 -> V_69 ) ;
F_60 (pwrst, &pwrst_list, node) {
if ( F_61 ( V_66 -> V_69 , V_66 -> V_70 ) )
goto V_71;
if ( F_62 ( V_66 -> V_69 ) )
goto V_71;
}
F_63 () ;
F_33 () ;
V_71:
F_60 (pwrst, &pwrst_list, node) {
V_67 = F_43 ( V_66 -> V_69 ) ;
if ( V_67 > V_66 -> V_70 ) {
F_64 ( L_3
L_4 ,
V_66 -> V_69 -> V_72 , V_66 -> V_70 ) ;
V_3 = - 1 ;
}
F_61 ( V_66 -> V_69 , V_66 -> V_68 ) ;
}
if ( V_3 )
F_20 ( L_5 ) ;
else
F_64 ( L_6 ) ;
return V_3 ;
}
static void T_6 F_65 ( void )
{
F_26 ( 0 , V_73 , V_74 ) ;
if ( ! ( F_23 ( V_73 , V_75 ) &
V_76 ) )
return;
F_25 ( V_77 |
V_78 |
V_79 ,
V_73 , V_80 ) ;
F_26 ( V_81 ,
V_73 , V_74 ) ;
F_3 ( V_82 ,
V_83 ) ;
F_25 ( 0 , V_73 , V_80 ) ;
F_26 ( 0 , V_73 , V_74 ) ;
F_25 ( V_77 |
V_78 |
V_79 ,
V_73 , V_80 ) ;
}
static void T_6 F_66 ( void )
{
T_4 V_84 , V_85 ;
V_84 = ( 1 << 4 ) | ( 1 << 3 ) ;
V_85 = F_67 ( V_86 ) ;
V_85 |= V_84 ;
F_68 ( V_85 , V_86 ) ;
V_85 = F_67 ( V_87 ) ;
V_85 |= V_84 ;
F_68 ( V_85 , V_87 ) ;
F_25 ( V_88 |
V_89 ,
V_38 , V_80 ) ;
F_25 ( 0 , V_38 , V_80 ) ;
}
static void T_6 F_69 ( void )
{
T_1 V_90 = F_70 () ?
V_91 : 0 ;
T_1 V_92 = F_70 () ?
V_93 : 0 ;
F_3 ( V_94 , V_95 ) ;
F_71 ( V_96 ,
1 << V_97 ,
V_60 ,
V_98 ) ;
F_25 ( V_99 | V_100 |
V_101 | V_102 ,
V_33 , V_103 ) ;
F_25 ( V_104 |
V_105 |
V_106 ,
V_33 , V_27 ) ;
F_25 ( V_107 ,
V_108 , V_103 ) ;
F_25 ( V_90 |
V_109 | V_110 |
V_111 | V_112 |
V_113 | V_114 |
V_115 | V_116 |
V_117 ,
V_39 , V_103 ) ;
F_25 ( V_92 |
V_118 |
V_119 |
V_120 |
V_121 |
V_122 |
V_123 |
V_124 |
V_125 |
V_126 ,
V_39 , V_27 ) ;
if ( F_72 () ) {
F_25 ( 0 , V_33 , V_127 ) ;
F_25 ( 0 , V_38 , V_128 ) ;
F_25 ( 0 , V_38 , V_129 ) ;
F_25 ( 0 , V_39 ,
V_127 ) ;
}
F_25 ( 0xffffffff , V_130 , V_131 ) ;
F_25 ( 0xffffffff , V_38 , V_131 ) ;
F_25 ( 0xffffffff , V_39 , V_131 ) ;
F_25 ( 0xffffffff , V_132 , V_131 ) ;
F_25 ( 0xffffffff , V_133 , V_131 ) ;
F_25 ( 0xffffffff , V_108 , V_131 ) ;
F_25 ( 0xffffffff , V_29 , V_131 ) ;
F_25 ( 0 , V_134 , V_135 ) ;
if ( F_72 () )
F_65 () ;
F_66 () ;
}
void F_73 ( int V_136 )
{
struct V_65 * V_66 ;
T_1 V_67 ;
if ( V_136 )
V_67 = V_50 ;
else
V_67 = V_49 ;
F_60 (pwrst, &pwrst_list, node) {
if ( F_74 ( V_137 ) &&
V_66 -> V_69 == V_53 &&
V_67 == V_50 ) {
V_66 -> V_70 = V_49 ;
F_75 ( L_7 ,
V_138 ) ;
} else {
V_66 -> V_70 = V_67 ;
}
F_61 ( V_66 -> V_69 , V_66 -> V_70 ) ;
}
}
int F_76 ( struct V_139 * V_69 )
{
struct V_65 * V_66 ;
F_60 (pwrst, &pwrst_list, node) {
if ( V_66 -> V_69 == V_69 )
return V_66 -> V_70 ;
}
return - V_140 ;
}
int F_77 ( struct V_139 * V_69 , int V_67 )
{
struct V_65 * V_66 ;
F_60 (pwrst, &pwrst_list, node) {
if ( V_66 -> V_69 == V_69 ) {
V_66 -> V_70 = V_67 ;
return 0 ;
}
}
return - V_140 ;
}
static int T_6 F_78 ( struct V_139 * V_69 , void * V_32 )
{
struct V_65 * V_66 ;
if ( ! V_69 -> V_141 )
return 0 ;
V_66 = F_79 ( sizeof( struct V_65 ) , V_142 ) ;
if ( ! V_66 )
return - V_143 ;
V_66 -> V_69 = V_69 ;
V_66 -> V_70 = V_49 ;
F_80 ( & V_66 -> V_144 , & V_145 ) ;
if ( F_81 ( V_69 ) )
F_82 ( V_69 ) ;
return F_61 ( V_66 -> V_69 , V_66 -> V_70 ) ;
}
void F_83 ( void )
{
V_146 = F_84 ( V_147 , V_148 ) ;
if ( F_16 () != V_6 )
F_18 = F_84 ( V_149 ,
V_150 ) ;
}
static void T_6 F_85 ( void )
{
if ( F_70 () ) {
V_151 |= V_152 ;
F_86 () ;
if ( F_29 () < V_153 )
V_151 |= V_137 ;
}
}
int T_6 F_87 ( void )
{
struct V_65 * V_66 , * V_154 ;
struct V_155 * V_156 , * V_157 ;
int V_3 ;
if ( ! F_88 () )
F_89 ( L_8 ) ;
F_85 () ;
F_69 () ;
V_3 = F_90 ( F_91 ( L_9 ) ,
F_28 , V_158 , L_10 , NULL ) ;
if ( V_3 ) {
F_20 ( L_11 ) ;
goto V_159;
}
V_3 = F_90 ( F_91 ( L_12 ) ,
F_27 , V_160 | V_158 , L_13 ,
F_87 ) ;
F_92 ( F_91 ( L_12 ) ) ;
if ( V_3 ) {
F_20 ( L_14 ) ;
goto V_161;
}
V_3 = F_93 ( F_78 , NULL ) ;
if ( V_3 ) {
F_20 ( L_15 ) ;
goto V_162;
}
( void ) F_94 ( V_163 , NULL ) ;
V_5 = F_95 ( L_16 ) ;
if ( V_5 == NULL ) {
F_20 ( L_17 ) ;
V_3 = - V_140 ;
goto V_162;
}
V_51 = F_95 ( L_18 ) ;
V_52 = F_95 ( L_19 ) ;
V_53 = F_95 ( L_20 ) ;
V_156 = F_96 ( L_21 ) ;
V_157 = F_96 ( L_22 ) ;
#ifdef F_97
V_164 = F_59 ;
#endif
V_165 = F_51 ;
F_98 () ;
if ( F_74 ( V_152 ) )
F_99 () ;
F_100 ( V_156 , V_157 ) ;
if ( F_16 () != V_6 ) {
V_8 =
F_79 ( 0x803F , V_166 ) ;
if ( ! V_8 )
F_20 ( L_23
L_24 ) ;
F_101 () ;
F_52 () ;
F_8 () ;
F_14 () ;
F_13 () ;
F_102 () ;
F_58 () ;
}
F_103 () ;
return V_3 ;
V_162:
F_104 (pwrst, tmp, &pwrst_list, node) {
F_105 ( & V_66 -> V_144 ) ;
F_106 ( V_66 ) ;
}
F_107 ( F_91 ( L_12 ) , F_87 ) ;
V_161:
F_107 ( F_91 ( L_9 ) , NULL ) ;
V_159:
return V_3 ;
}
