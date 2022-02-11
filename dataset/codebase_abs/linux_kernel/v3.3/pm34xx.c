static inline void F_1 ( void )
{
F_2 () ;
}
static inline void F_3 ( void )
{
F_4 () ;
}
static void F_5 ( void )
{
int V_1 = 0 ;
F_6 ( V_2 , V_3 ,
V_4 ) ;
F_7 ( V_3 , V_4 ) ;
while ( ! ( F_7 ( V_3 , V_4 ) &
V_5 ) ) {
V_1 ++ ;
if ( V_1 > 1000 ) {
F_8 ( L_1 ) ;
return;
}
F_6 ( V_5 ,
V_3 , V_4 ) ;
}
}
static void F_9 ( void )
{
F_10 ( V_2 , V_3 ,
V_4 ) ;
}
static void F_11 ( void )
{
F_12 () ;
F_13 ( F_14 ( V_6 ) ,
V_7 + 0x2a0 ) ;
F_15 () ;
F_16 () ;
F_17 () ;
F_18 () ;
}
static void F_19 ( void )
{
F_20 () ;
F_21 () ;
F_22 () ;
F_23 () ;
}
static void F_24 ( void )
{
T_1 V_8 ;
int V_9 = F_25 ( V_10 ) ;
if ( F_26 () != V_11 ) {
F_27 ( V_10 , V_12 ) ;
V_8 = F_28 ( ( T_1 * )
F_29 ( V_13 ) ) ;
F_27 ( V_10 , V_9 ) ;
if ( V_8 ) {
F_30 ( V_14 L_2 ,
V_8 ) ;
while ( 1 )
;
}
}
}
static int F_31 ( T_2 V_15 , T_3 V_16 , T_1 V_17 )
{
T_1 V_18 , V_19 , V_20 , V_21 ;
T_4 V_22 = ( V_16 == 3 ) ? V_23 : V_24 ;
T_4 V_25 = ( V_16 == 3 ) ? V_26 : V_27 ;
T_4 V_28 = ( V_16 == 3 ) ? V_29 : V_30 ;
T_4 V_31 = ( V_16 == 3 ) ?
V_32 : V_33 ;
int V_34 = 0 ;
V_18 = F_7 ( V_15 , V_22 ) ;
V_18 &= F_7 ( V_15 , V_31 ) ;
V_18 &= ~ V_17 ;
if ( V_18 ) {
V_20 = F_32 ( V_15 , V_28 ) ;
V_19 = F_32 ( V_15 , V_25 ) ;
while ( V_18 ) {
V_21 = V_18 ;
F_33 ( V_21 , V_15 , V_28 ) ;
if ( V_15 == V_35 )
V_21 |= 1 << V_36 ;
F_33 ( V_21 , V_15 , V_25 ) ;
F_34 ( V_18 , V_15 , V_22 ) ;
V_18 = F_7 ( V_15 , V_22 ) ;
V_18 &= ~ V_17 ;
V_34 ++ ;
}
F_35 ( V_20 , V_15 , V_28 ) ;
F_35 ( V_19 , V_15 , V_25 ) ;
}
return V_34 ;
}
static T_5 F_36 ( int V_37 , void * V_38 )
{
int V_34 ;
V_34 = F_31 ( V_3 , 1 ,
~ ( V_39 | V_5 ) ) ;
return V_34 ? V_40 : V_41 ;
}
static T_5 F_37 ( int V_37 , void * V_38 )
{
int V_34 ;
V_34 = F_31 ( V_3 , 1 ,
V_39 | V_5 ) ;
V_34 += F_31 ( V_42 , 1 , 0 ) ;
V_34 += F_31 ( V_43 , 1 , 0 ) ;
if ( F_38 () > V_44 ) {
V_34 += F_31 ( V_42 , 3 , 0 ) ;
V_34 += F_31 ( V_35 , 1 , 0 ) ;
}
return V_34 ? V_40 : V_41 ;
}
static void F_39 ( T_1 * V_45 )
{
T_1 V_46 ;
asm("mrc p15, 0, %0, c1, c0, 1" : "=r" (val));
* V_45 ++ = 1 ;
* V_45 ++ = V_46 ;
asm("mrc p15, 1, %0, c9, c0, 2" : "=r" (val));
* V_45 ++ = 1 ;
* V_45 ++ = V_46 ;
}
static int F_40 ( unsigned long V_47 )
{
F_41 ( V_47 ) ;
return 0 ;
}
void F_42 ( void )
{
int V_47 = 0 ;
int V_9 = V_12 ;
int V_48 = V_12 ;
int V_49 = V_12 ;
int V_50 ;
int V_51 , V_52 ;
T_1 V_53 = 0 ;
F_43 ( V_10 ) ;
F_43 ( V_54 ) ;
F_43 ( V_55 ) ;
F_43 ( V_56 ) ;
V_9 = F_25 ( V_10 ) ;
switch ( V_9 ) {
case V_12 :
case V_57 :
V_47 = 0 ;
break;
case V_58 :
V_47 = 3 ;
break;
default:
F_30 ( V_14 L_3 ) ;
return;
}
if ( F_44 ( V_54 ) == V_12 )
F_27 ( V_54 , V_9 ) ;
V_48 = F_25 ( V_56 ) ;
V_49 = F_25 ( V_55 ) ;
if ( F_45 () &&
( V_48 < V_12 ||
V_49 < V_12 ) ) {
F_6 ( V_59 , V_3 , V_4 ) ;
if ( F_46 () )
F_5 () ;
}
F_47 () ;
if ( V_48 < V_12 ) {
V_50 = ( V_48 == V_58 ) ? 1 : 0 ;
F_48 ( V_50 ) ;
if ( V_48 == V_58 )
F_1 () ;
}
if ( V_49 < V_12 ) {
if ( V_49 == V_58 ) {
F_11 () ;
F_49 () ;
}
}
F_50 () ;
if ( F_51 () && F_38 () >= V_60 &&
( F_26 () == V_61 ||
F_26 () == V_62 ) &&
V_49 == V_58 )
V_53 = F_52 ( V_63 ) ;
if ( V_47 )
F_39 ( V_64 ) ;
if ( V_47 == 1 || V_47 == 3 )
F_53 ( V_47 , F_40 ) ;
else
F_40 ( V_47 ) ;
if ( F_51 () && F_38 () >= V_60 &&
( F_26 () == V_61 ||
F_26 () == V_62 ) &&
V_49 == V_58 )
F_54 ( V_53 , V_63 ) ;
if ( V_49 < V_12 ) {
V_51 = F_55 ( V_55 ) ;
if ( V_51 == V_58 ) {
F_19 () ;
F_56 () ;
F_57 () ;
F_58 () ;
}
if ( V_49 == V_58 )
F_10 ( V_65 ,
V_66 ,
V_67 ) ;
}
F_59 () ;
F_60 () ;
if ( V_48 < V_12 ) {
V_52 = F_55 ( V_56 ) ;
F_61 () ;
if ( V_52 == V_58 )
F_3 () ;
}
if ( F_45 () &&
( V_48 < V_12 ||
V_49 < V_12 ) ) {
F_10 ( V_59 , V_3 ,
V_4 ) ;
if ( F_46 () )
F_9 () ;
}
F_62 ( V_10 -> V_68 [ 0 ] ) ;
}
static void F_63 ( void )
{
F_64 () ;
F_65 () ;
if ( F_66 () || F_67 () )
goto V_69;
F_68 ( V_70 , 1 , F_69 () ) ;
F_70 ( 1 , F_69 () ) ;
F_42 () ;
F_71 ( F_69 () ) ;
F_70 ( V_71 , F_69 () ) ;
V_69:
F_72 () ;
F_73 () ;
}
static int F_74 ( void )
{
struct V_72 * V_73 ;
int V_74 , V_8 = 0 ;
F_75 (pwrst, &pwrst_list, node)
V_73 -> V_75 = F_25 ( V_73 -> V_76 ) ;
F_75 (pwrst, &pwrst_list, node) {
if ( F_76 ( V_73 -> V_76 , V_73 -> V_77 ) )
goto V_78;
if ( F_43 ( V_73 -> V_76 ) )
goto V_78;
}
F_77 () ;
F_42 () ;
V_78:
F_75 (pwrst, &pwrst_list, node) {
V_74 = F_55 ( V_73 -> V_76 ) ;
if ( V_74 > V_73 -> V_77 ) {
F_30 ( V_79 L_4
L_5 ,
V_73 -> V_76 -> V_80 , V_73 -> V_77 ) ;
V_8 = - 1 ;
}
F_76 ( V_73 -> V_76 , V_73 -> V_75 ) ;
}
if ( V_8 )
F_30 ( V_14 L_6 ) ;
else
F_30 ( V_79 L_7
L_8 ) ;
return V_8 ;
}
static int F_78 ( T_6 V_38 )
{
int V_8 = 0 ;
switch ( V_81 ) {
case V_82 :
case V_83 :
V_8 = F_74 () ;
break;
default:
V_8 = - V_84 ;
}
return V_8 ;
}
static int F_79 ( T_6 V_74 )
{
F_80 () ;
V_81 = V_74 ;
F_81 () ;
return 0 ;
}
static void F_82 ( void )
{
V_81 = V_85 ;
F_83 () ;
return;
}
static void F_84 ( void )
{
F_85 () ;
}
static void T_7 F_86 ( void )
{
F_35 ( 0 , V_86 , V_87 ) ;
if ( ! ( F_32 ( V_86 , V_88 ) &
V_89 ) )
return;
F_34 ( V_90 |
V_91 |
V_92 ,
V_86 , V_93 ) ;
F_35 ( V_94 ,
V_86 , V_87 ) ;
F_13 ( V_95 ,
V_96 ) ;
F_34 ( 0 , V_86 , V_93 ) ;
F_35 ( 0 , V_86 , V_87 ) ;
F_34 ( V_90 |
V_91 |
V_92 ,
V_86 , V_93 ) ;
}
static void T_7 F_87 ( void )
{
T_4 V_97 , V_98 ;
V_97 = ( 1 << 4 ) | ( 1 << 3 ) ;
V_98 = F_88 ( V_99 ) ;
V_98 |= V_97 ;
F_89 ( V_98 , V_99 ) ;
V_98 = F_88 ( V_100 ) ;
V_98 |= V_97 ;
F_89 ( V_98 , V_100 ) ;
F_34 ( V_101 |
V_102 ,
V_42 , V_93 ) ;
F_34 ( 0 , V_42 , V_93 ) ;
}
static void T_7 F_90 ( void )
{
T_1 V_103 = F_91 () ?
V_104 : 0 ;
T_1 V_105 = F_91 () ?
V_106 : 0 ;
F_13 ( V_107 , V_108 ) ;
F_92 ( V_109 ,
1 << V_110 ,
V_66 ,
V_111 ) ;
F_34 ( V_59 | V_112 |
V_113 | V_114 ,
V_3 , V_4 ) ;
F_34 ( V_115 |
V_116 |
V_117 ,
V_3 , V_33 ) ;
F_34 ( V_118 ,
V_119 , V_4 ) ;
F_34 ( V_103 |
V_120 | V_121 |
V_122 | V_123 |
V_124 | V_125 |
V_126 | V_127 |
V_128 ,
V_43 , V_4 ) ;
F_34 ( V_105 |
V_129 |
V_130 |
V_131 |
V_132 |
V_133 |
V_134 |
V_135 |
V_136 |
V_137 ,
V_43 , V_33 ) ;
F_34 ( 0 , V_3 , V_138 ) ;
F_34 ( 0 , V_42 , V_139 ) ;
F_34 ( 0 , V_42 , V_140 ) ;
F_34 ( 0 , V_43 , V_138 ) ;
F_34 ( 0xffffffff , V_141 , V_142 ) ;
F_34 ( 0xffffffff , V_42 , V_142 ) ;
F_34 ( 0xffffffff , V_43 , V_142 ) ;
F_34 ( 0xffffffff , V_143 , V_142 ) ;
F_34 ( 0xffffffff , V_144 , V_142 ) ;
F_34 ( 0xffffffff , V_119 , V_142 ) ;
F_34 ( 0xffffffff , V_35 , V_142 ) ;
F_34 ( 0 , V_145 , V_146 ) ;
F_86 () ;
F_87 () ;
}
void F_93 ( int V_147 )
{
struct V_72 * V_73 ;
T_1 V_74 ;
if ( V_147 )
V_74 = V_58 ;
else
V_74 = V_57 ;
F_75 (pwrst, &pwrst_list, node) {
if ( F_94 ( V_148 ) &&
V_73 -> V_76 == V_55 &&
V_74 == V_58 ) {
V_73 -> V_77 = V_57 ;
F_95 ( L_9 ,
V_149 ) ;
} else {
V_73 -> V_77 = V_74 ;
}
F_76 ( V_73 -> V_76 , V_73 -> V_77 ) ;
}
}
int F_96 ( struct V_150 * V_76 )
{
struct V_72 * V_73 ;
F_75 (pwrst, &pwrst_list, node) {
if ( V_73 -> V_76 == V_76 )
return V_73 -> V_77 ;
}
return - V_84 ;
}
int F_97 ( struct V_150 * V_76 , int V_74 )
{
struct V_72 * V_73 ;
F_75 (pwrst, &pwrst_list, node) {
if ( V_73 -> V_76 == V_76 ) {
V_73 -> V_77 = V_74 ;
return 0 ;
}
}
return - V_84 ;
}
static int T_7 F_98 ( struct V_150 * V_76 , void * V_38 )
{
struct V_72 * V_73 ;
if ( ! V_76 -> V_151 )
return 0 ;
V_73 = F_99 ( sizeof( struct V_72 ) , V_152 ) ;
if ( ! V_73 )
return - V_153 ;
V_73 -> V_76 = V_76 ;
V_73 -> V_77 = V_57 ;
F_100 ( & V_73 -> V_154 , & V_155 ) ;
if ( F_101 ( V_76 ) )
F_102 ( V_76 ) ;
return F_76 ( V_73 -> V_76 , V_73 -> V_77 ) ;
}
static int T_7 F_103 ( struct V_156 * V_157 , void * V_38 )
{
if ( V_157 -> V_158 & V_159 )
F_62 ( V_157 ) ;
else if ( V_157 -> V_158 & V_160 &&
F_104 ( & V_157 -> V_161 ) == 0 )
F_105 ( V_157 ) ;
return 0 ;
}
void F_106 ( void )
{
V_162 = F_107 ( V_163 , V_164 ) ;
if ( F_26 () != V_11 )
F_28 = F_107 ( V_165 ,
V_166 ) ;
}
static void T_7 F_108 ( void )
{
if ( F_91 () ) {
V_167 |= V_168 ;
F_109 () ;
if ( F_38 () < V_169 )
V_167 |= V_148 ;
}
}
static int T_7 F_110 ( void )
{
struct V_72 * V_73 , * V_170 ;
struct V_156 * V_171 , * V_172 , * V_173 , * V_174 ;
int V_8 ;
if ( ! F_111 () )
return - V_175 ;
if ( ! F_46 () )
F_112 ( L_10 ) ;
F_108 () ;
F_90 () ;
V_8 = F_113 ( F_114 ( L_11 ) ,
F_37 , V_176 , L_12 , NULL ) ;
if ( V_8 ) {
F_8 ( L_13 ) ;
goto V_177;
}
V_8 = F_113 ( F_114 ( L_14 ) ,
F_36 , V_178 | V_176 , L_15 ,
F_110 ) ;
if ( V_8 ) {
F_8 ( L_16 ) ;
goto V_177;
}
V_8 = F_115 ( F_98 , NULL ) ;
if ( V_8 ) {
F_30 ( V_14 L_17 ) ;
goto V_179;
}
( void ) F_116 ( F_103 , NULL ) ;
V_10 = F_117 ( L_18 ) ;
if ( V_10 == NULL ) {
F_30 ( V_14 L_19 ) ;
goto V_179;
}
V_54 = F_117 ( L_20 ) ;
V_56 = F_117 ( L_21 ) ;
V_55 = F_117 ( L_22 ) ;
V_180 = F_117 ( L_23 ) ;
V_171 = F_118 ( L_24 ) ;
V_173 = F_118 ( L_25 ) ;
V_172 = F_118 ( L_26 ) ;
V_174 = F_118 ( L_27 ) ;
#ifdef F_119
F_120 ( & V_181 ) ;
#endif
V_182 = F_63 ;
F_121 () ;
if ( F_94 ( V_168 ) )
F_122 () ;
F_123 ( V_171 , V_173 ) ;
if ( F_26 () != V_11 ) {
V_13 =
F_99 ( 0x803F , V_183 ) ;
if ( ! V_13 )
F_30 ( V_14 L_28
L_29 ) ;
F_64 () ;
F_65 () ;
F_18 () ;
F_24 () ;
F_23 () ;
F_73 () ;
F_72 () ;
}
F_124 () ;
V_177:
return V_8 ;
V_179:
F_125 ( V_184 , NULL ) ;
F_126 (pwrst, tmp, &pwrst_list, node) {
F_127 ( & V_73 -> V_154 ) ;
F_128 ( V_73 ) ;
}
return V_8 ;
}
