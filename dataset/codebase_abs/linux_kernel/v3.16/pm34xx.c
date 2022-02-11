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
F_38 ( V_45 ) ;
F_39 () ;
if ( F_40 () && F_29 () >= V_54 &&
( F_16 () == V_55 ||
F_16 () == V_56 ) &&
V_45 == V_50 )
V_48 = F_41 ( V_57 ) ;
if ( V_43 )
F_30 ( V_58 ) ;
if ( V_43 == 1 || V_43 == 3 )
F_42 ( V_43 , F_31 ) ;
else
F_31 ( V_43 ) ;
if ( F_40 () && F_29 () >= V_54 &&
( F_16 () == V_55 ||
F_16 () == V_56 ) &&
V_45 == V_50 )
F_43 ( V_48 , V_57 ) ;
if ( V_45 < V_7 ) {
V_47 = F_44 ( V_53 ) ;
if ( V_47 == V_50 ) {
F_9 () ;
F_45 () ;
F_46 () ;
F_47 () ;
}
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
F_53 ( V_59 , F_54 () ) ;
}
static int F_55 ( void )
{
struct V_60 * V_61 ;
int V_62 , V_3 = 0 ;
F_56 (pwrst, &pwrst_list, node)
V_61 -> V_63 = F_15 ( V_61 -> V_64 ) ;
F_56 (pwrst, &pwrst_list, node) {
if ( F_57 ( V_61 -> V_64 , V_61 -> V_65 ) )
goto V_66;
if ( F_58 ( V_61 -> V_64 ) )
goto V_66;
}
F_59 () ;
F_33 () ;
V_66:
F_56 (pwrst, &pwrst_list, node) {
V_62 = F_44 ( V_61 -> V_64 ) ;
if ( V_62 > V_61 -> V_65 ) {
F_60 ( L_3 ,
V_61 -> V_64 -> V_67 , V_61 -> V_65 ) ;
V_3 = - 1 ;
}
F_57 ( V_61 -> V_64 , V_61 -> V_63 ) ;
}
if ( V_3 )
F_20 ( L_4 ) ;
else
F_60 ( L_5 ) ;
return V_3 ;
}
static void T_6 F_61 ( void )
{
F_26 ( 0 , V_68 , V_69 ) ;
if ( ! ( F_23 ( V_68 , V_70 ) &
V_71 ) )
return;
F_25 ( V_72 |
V_73 |
V_74 ,
V_68 , V_75 ) ;
F_26 ( V_76 ,
V_68 , V_69 ) ;
F_62 () ;
F_25 ( 0 , V_68 , V_75 ) ;
F_26 ( 0 , V_68 , V_69 ) ;
F_25 ( V_72 |
V_73 |
V_74 ,
V_68 , V_75 ) ;
}
static void T_6 F_63 ( void )
{
T_4 V_77 , V_78 ;
V_77 = ( 1 << 4 ) | ( 1 << 3 ) ;
V_78 = F_64 ( V_79 ) ;
V_78 |= V_77 ;
F_65 ( V_78 , V_79 ) ;
V_78 = F_64 ( V_80 ) ;
V_78 |= V_77 ;
F_65 ( V_78 , V_80 ) ;
F_25 ( V_81 |
V_82 ,
V_38 , V_75 ) ;
F_25 ( 0 , V_38 , V_75 ) ;
}
static void T_6 F_66 ( void )
{
T_1 V_83 = F_67 () ?
V_84 : 0 ;
T_1 V_85 = F_67 () ?
V_86 : 0 ;
F_3 ( V_87 , V_88 ) ;
F_68 ( V_89 ,
1 << V_90 ,
V_91 ,
V_92 ) ;
F_25 ( V_93 | V_94 |
V_95 | V_96 ,
V_33 , V_97 ) ;
F_25 ( V_98 |
V_99 |
V_100 ,
V_33 , V_27 ) ;
F_25 ( V_101 ,
V_102 , V_97 ) ;
F_25 ( V_83 |
V_103 | V_104 |
V_105 | V_106 |
V_107 | V_108 |
V_109 | V_110 |
V_111 ,
V_39 , V_97 ) ;
F_25 ( V_85 |
V_112 |
V_113 |
V_114 |
V_115 |
V_116 |
V_117 |
V_118 |
V_119 |
V_120 ,
V_39 , V_27 ) ;
if ( F_69 () ) {
F_25 ( 0 , V_33 , V_121 ) ;
F_25 ( 0 , V_38 , V_122 ) ;
F_25 ( 0 , V_38 , V_123 ) ;
F_25 ( 0 , V_39 ,
V_121 ) ;
}
F_25 ( 0xffffffff , V_124 , V_125 ) ;
F_25 ( 0xffffffff , V_38 , V_125 ) ;
F_25 ( 0xffffffff , V_39 , V_125 ) ;
F_25 ( 0xffffffff , V_126 , V_125 ) ;
F_25 ( 0xffffffff , V_127 , V_125 ) ;
F_25 ( 0xffffffff , V_102 , V_125 ) ;
F_25 ( 0xffffffff , V_29 , V_125 ) ;
F_25 ( 0 , V_128 , V_129 ) ;
F_61 () ;
F_63 () ;
}
void F_70 ( int V_130 )
{
struct V_60 * V_61 ;
T_1 V_62 ;
if ( V_130 )
V_62 = V_50 ;
else
V_62 = V_49 ;
F_56 (pwrst, &pwrst_list, node) {
if ( F_71 ( V_131 ) &&
V_61 -> V_64 == V_53 &&
V_62 == V_50 ) {
V_61 -> V_65 = V_49 ;
F_72 ( L_6 ,
V_132 ) ;
} else {
V_61 -> V_65 = V_62 ;
}
F_57 ( V_61 -> V_64 , V_61 -> V_65 ) ;
}
}
int F_73 ( struct V_133 * V_64 )
{
struct V_60 * V_61 ;
F_56 (pwrst, &pwrst_list, node) {
if ( V_61 -> V_64 == V_64 )
return V_61 -> V_65 ;
}
return - V_134 ;
}
int F_74 ( struct V_133 * V_64 , int V_62 )
{
struct V_60 * V_61 ;
F_56 (pwrst, &pwrst_list, node) {
if ( V_61 -> V_64 == V_64 ) {
V_61 -> V_65 = V_62 ;
return 0 ;
}
}
return - V_134 ;
}
static int T_6 F_75 ( struct V_133 * V_64 , void * V_32 )
{
struct V_60 * V_61 ;
if ( ! V_64 -> V_135 )
return 0 ;
V_61 = F_76 ( sizeof( struct V_60 ) , V_136 ) ;
if ( ! V_61 )
return - V_137 ;
V_61 -> V_64 = V_64 ;
V_61 -> V_65 = V_49 ;
F_77 ( & V_61 -> V_138 , & V_139 ) ;
if ( F_78 ( V_64 ) )
F_79 ( V_64 ) ;
return F_57 ( V_61 -> V_64 , V_61 -> V_65 ) ;
}
void F_80 ( void )
{
V_140 = F_81 ( V_141 , V_142 ) ;
if ( F_16 () != V_6 )
F_18 = F_81 ( V_143 ,
V_144 ) ;
}
static void T_6 F_82 ( void )
{
if ( F_67 () ) {
V_145 |= V_146 ;
F_83 () ;
if ( F_29 () < V_147 )
V_145 |= ( V_131 |
V_148 ) ;
} else if ( F_84 () ) {
V_145 |= V_148 ;
}
}
int T_6 F_85 ( void )
{
struct V_60 * V_61 , * V_149 ;
struct V_150 * V_151 , * V_152 , * V_153 , * V_154 ;
int V_3 ;
if ( ! F_86 () )
F_87 ( L_7 ) ;
F_82 () ;
F_66 () ;
V_3 = F_88 ( F_89 ( L_8 ) ,
F_28 , V_155 , L_9 , NULL ) ;
if ( V_3 ) {
F_20 ( L_10 ) ;
goto V_156;
}
V_3 = F_88 ( F_89 ( L_11 ) ,
F_27 , V_157 | V_155 , L_12 ,
F_85 ) ;
F_90 ( F_89 ( L_11 ) ) ;
if ( V_3 ) {
F_20 ( L_13 ) ;
goto V_158;
}
V_3 = F_91 ( F_75 , NULL ) ;
if ( V_3 ) {
F_20 ( L_14 ) ;
goto V_159;
}
( void ) F_92 ( V_160 , NULL ) ;
V_5 = F_93 ( L_15 ) ;
if ( V_5 == NULL ) {
F_20 ( L_16 ) ;
V_3 = - V_134 ;
goto V_159;
}
V_51 = F_93 ( L_17 ) ;
V_52 = F_93 ( L_18 ) ;
V_53 = F_93 ( L_19 ) ;
V_151 = F_94 ( L_20 ) ;
V_152 = F_94 ( L_21 ) ;
V_153 = F_94 ( L_22 ) ;
V_154 = F_94 ( L_23 ) ;
F_95 ( F_55 ) ;
V_161 = F_51 ;
F_96 () ;
if ( F_71 ( V_146 ) )
F_97 () ;
if ( F_71 ( V_148 ) )
F_98 ( V_153 , V_154 ) ;
F_98 ( V_151 , V_152 ) ;
if ( F_16 () != V_6 ) {
V_8 =
F_76 ( 0x803F , V_162 ) ;
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
V_159:
F_102 (pwrst, tmp, &pwrst_list, node) {
F_103 ( & V_61 -> V_138 ) ;
F_104 ( V_61 ) ;
}
F_105 ( F_89 ( L_11 ) , F_85 ) ;
V_158:
F_105 ( F_89 ( L_8 ) , NULL ) ;
V_156:
return V_3 ;
}
