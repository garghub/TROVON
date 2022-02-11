static inline bool F_1 ( void )
{
return ( V_1 != V_2 ) && V_3 ;
}
static inline bool F_1 ( void )
{
return false ;
}
static inline void F_2 ( void )
{
F_3 () ;
}
static inline void F_4 ( void )
{
F_5 () ;
}
static void F_6 ( void )
{
int V_4 = 0 ;
F_7 ( V_5 , V_6 ,
V_7 ) ;
F_8 ( V_6 , V_7 ) ;
while ( ! ( F_8 ( V_6 , V_7 ) &
V_8 ) ) {
V_4 ++ ;
if ( V_4 > 1000 ) {
F_9 ( L_1 ) ;
return;
}
F_7 ( V_8 ,
V_6 , V_7 ) ;
}
}
static void F_10 ( void )
{
F_11 ( V_5 , V_6 ,
V_7 ) ;
}
static void F_12 ( void )
{
F_13 () ;
F_14 ( F_15 ( V_9 ) ,
V_10 + 0x2a0 ) ;
F_16 () ;
F_17 () ;
F_18 () ;
F_19 () ;
}
static void F_20 ( void )
{
F_21 () ;
F_22 () ;
F_23 () ;
F_24 () ;
}
static void F_25 ( void )
{
T_1 V_11 ;
int V_12 = F_26 ( V_13 ) ;
if ( F_27 () != V_14 ) {
F_28 ( V_13 , V_15 ) ;
V_11 = F_29 ( ( T_1 * )
F_30 ( V_16 ) ) ;
F_28 ( V_13 , V_12 ) ;
if ( V_11 ) {
F_31 ( V_17 L_2 ,
V_11 ) ;
while ( 1 )
;
}
}
}
static int F_32 ( T_2 V_18 , T_3 V_19 )
{
T_1 V_20 , V_21 , V_22 , V_23 ;
T_4 V_24 = ( V_19 == 3 ) ? V_25 : V_26 ;
T_4 V_27 = ( V_19 == 3 ) ? V_28 : V_29 ;
T_4 V_30 = ( V_19 == 3 ) ? V_31 : V_32 ;
T_4 V_33 = ( V_19 == 3 ) ?
V_34 : V_35 ;
int V_36 = 0 ;
V_20 = F_8 ( V_18 , V_24 ) ;
V_20 &= F_8 ( V_18 , V_33 ) ;
if ( V_20 ) {
V_22 = F_33 ( V_18 , V_30 ) ;
V_21 = F_33 ( V_18 , V_27 ) ;
while ( V_20 ) {
V_23 = V_20 ;
F_34 ( V_23 , V_18 , V_30 ) ;
if ( V_18 == V_37 )
V_23 |= 1 << V_38 ;
F_34 ( V_23 , V_18 , V_27 ) ;
F_35 ( V_20 , V_18 , V_24 ) ;
V_20 = F_8 ( V_18 , V_24 ) ;
V_36 ++ ;
}
F_36 ( V_22 , V_18 , V_30 ) ;
F_36 ( V_21 , V_18 , V_27 ) ;
}
return V_36 ;
}
static int F_37 ( void )
{
int V_36 ;
V_36 = F_32 ( V_6 , 1 ) ;
V_36 += F_32 ( V_39 , 1 ) ;
V_36 += F_32 ( V_40 , 1 ) ;
if ( F_38 () > V_41 ) {
V_36 += F_32 ( V_39 , 3 ) ;
V_36 += F_32 ( V_37 , 1 ) ;
}
return V_36 ;
}
static T_5 F_39 ( int V_42 , void * V_43 )
{
T_1 V_44 , V_45 ;
int V_36 = 0 ;
V_44 = F_8 ( V_46 ,
V_47 ) ;
V_45 = F_8 ( V_46 ,
V_48 ) ;
V_45 &= V_44 ;
do {
if ( V_45 & ( V_49 |
V_50 ) ) {
V_36 = F_37 () ;
F_40 ( V_36 == 0 , L_3
L_4 ) ;
} else {
F_40 ( 1 , L_5
L_6 , V_45 ) ;
}
F_35 ( V_45 , V_46 ,
V_48 ) ;
V_45 = F_8 ( V_46 ,
V_48 ) ;
V_45 &= V_44 ;
} while ( V_45 );
return V_51 ;
}
static void F_41 ( T_1 * V_52 )
{
T_1 V_53 ;
asm("mrc p15, 0, %0, c1, c0, 1" : "=r" (val));
* V_52 ++ = 1 ;
* V_52 ++ = V_53 ;
asm("mrc p15, 1, %0, c9, c0, 2" : "=r" (val));
* V_52 ++ = 1 ;
* V_52 ++ = V_53 ;
}
static int F_42 ( unsigned long V_54 )
{
F_43 ( V_54 ) ;
return 0 ;
}
void F_44 ( void )
{
int V_54 = 0 ;
int V_12 = V_15 ;
int V_55 = V_15 ;
int V_56 = V_15 ;
int V_57 ;
int V_58 , V_59 ;
T_1 V_60 = 0 ;
F_45 ( V_13 ) ;
F_45 ( V_61 ) ;
F_45 ( V_62 ) ;
F_45 ( V_63 ) ;
V_12 = F_26 ( V_13 ) ;
switch ( V_12 ) {
case V_15 :
case V_64 :
V_54 = 0 ;
break;
case V_65 :
V_54 = 3 ;
break;
default:
F_31 ( V_17 L_7 ) ;
return;
}
if ( F_46 ( V_61 ) == V_15 )
F_28 ( V_61 , V_12 ) ;
V_55 = F_26 ( V_63 ) ;
V_56 = F_26 ( V_62 ) ;
if ( F_47 () &&
( V_55 < V_15 ||
V_56 < V_15 ) ) {
F_7 ( V_66 , V_6 , V_7 ) ;
if ( F_48 () )
F_6 () ;
}
if ( ! F_1 () )
if ( V_55 < V_15 ||
V_56 < V_15 )
if ( ! F_49 () )
goto V_67;
F_50 () ;
if ( V_55 < V_15 ) {
V_57 = ( V_55 == V_65 ) ? 1 : 0 ;
F_51 ( 2 ) ;
F_51 ( 3 ) ;
F_52 ( V_57 ) ;
if ( V_55 == V_65 )
F_2 () ;
}
if ( V_56 < V_15 ) {
F_51 ( 0 ) ;
F_51 ( 1 ) ;
if ( V_56 == V_65 ) {
F_12 () ;
F_53 () ;
}
}
F_54 () ;
if ( F_55 () && F_38 () >= V_68 &&
( F_27 () == V_69 ||
F_27 () == V_70 ) &&
V_56 == V_65 )
V_60 = F_56 ( V_71 ) ;
if ( V_54 )
F_41 ( V_72 ) ;
if ( V_54 == 1 || V_54 == 3 )
F_57 ( V_54 , F_42 ) ;
else
F_42 ( V_54 ) ;
if ( F_55 () && F_38 () >= V_68 &&
( F_27 () == V_69 ||
F_27 () == V_70 ) &&
V_56 == V_65 )
F_58 ( V_60 , V_71 ) ;
if ( V_56 < V_15 ) {
V_58 = F_59 ( V_62 ) ;
if ( V_58 == V_65 ) {
F_20 () ;
F_60 () ;
F_61 () ;
F_62 () ;
}
F_63 ( 0 ) ;
F_63 ( 1 ) ;
if ( V_56 == V_65 )
F_11 ( V_73 ,
V_74 ,
V_75 ) ;
}
F_64 () ;
F_65 () ;
if ( V_55 < V_15 ) {
V_59 = F_59 ( V_63 ) ;
F_66 () ;
if ( V_59 == V_65 )
F_4 () ;
F_63 ( 2 ) ;
F_63 ( 3 ) ;
}
if ( ! F_1 () )
F_67 () ;
V_67:
if ( F_47 () &&
( V_55 < V_15 ||
V_56 < V_15 ) ) {
F_11 ( V_66 , V_6 ,
V_7 ) ;
if ( F_48 () )
F_10 () ;
}
F_68 ( V_13 -> V_76 [ 0 ] ) ;
}
int F_69 ( void )
{
if ( ! F_70 () )
return 0 ;
return 1 ;
}
static void F_71 ( void )
{
F_72 () ;
F_73 () ;
if ( ! F_69 () )
goto V_77;
if ( F_74 () || F_75 () )
goto V_77;
F_76 ( V_78 , 1 , F_77 () ) ;
F_78 ( 1 , F_77 () ) ;
F_44 () ;
F_79 ( F_77 () ) ;
F_78 ( V_79 , F_77 () ) ;
V_77:
F_80 () ;
F_81 () ;
}
static int F_82 ( void )
{
struct V_80 * V_81 ;
int V_82 , V_11 = 0 ;
F_83 (pwrst, &pwrst_list, node)
V_81 -> V_83 = F_26 ( V_81 -> V_84 ) ;
F_83 (pwrst, &pwrst_list, node) {
if ( F_84 ( V_81 -> V_84 , V_81 -> V_85 ) )
goto V_86;
if ( F_45 ( V_81 -> V_84 ) )
goto V_86;
}
F_85 () ;
F_86 () ;
F_44 () ;
V_86:
F_83 (pwrst, &pwrst_list, node) {
V_82 = F_59 ( V_81 -> V_84 ) ;
if ( V_82 > V_81 -> V_85 ) {
F_31 ( V_87 L_8
L_9 ,
V_81 -> V_84 -> V_88 , V_81 -> V_85 ) ;
V_11 = - 1 ;
}
F_84 ( V_81 -> V_84 , V_81 -> V_83 ) ;
}
if ( V_11 )
F_31 ( V_17 L_10 ) ;
else
F_31 ( V_87 L_11
L_12 ) ;
return V_11 ;
}
static int F_87 ( T_6 V_89 )
{
int V_11 = 0 ;
switch ( V_1 ) {
case V_90 :
case V_91 :
V_11 = F_82 () ;
break;
default:
V_11 = - V_92 ;
}
return V_11 ;
}
static int F_88 ( T_6 V_82 )
{
F_89 () ;
V_1 = V_82 ;
F_90 ( 0 ) ;
return 0 ;
}
static void F_91 ( void )
{
V_1 = V_2 ;
F_90 ( 1 ) ;
F_92 () ;
return;
}
static void T_7 F_93 ( void )
{
F_36 ( 0 , V_93 , V_94 ) ;
if ( ! ( F_33 ( V_93 , V_95 ) &
V_96 ) )
return;
F_35 ( V_97 |
V_98 |
V_99 ,
V_93 , V_100 ) ;
F_36 ( V_101 ,
V_93 , V_94 ) ;
F_14 ( V_102 ,
V_103 ) ;
F_35 ( 0 , V_93 , V_100 ) ;
F_36 ( 0 , V_93 , V_94 ) ;
F_35 ( V_97 |
V_98 |
V_99 ,
V_93 , V_100 ) ;
}
static void T_7 F_94 ( void )
{
T_4 V_104 , V_105 ;
V_104 = ( 1 << 4 ) | ( 1 << 3 ) ;
V_105 = F_95 ( V_106 ) ;
V_105 |= V_104 ;
F_96 ( V_105 , V_106 ) ;
V_105 = F_95 ( V_107 ) ;
V_105 |= V_104 ;
F_96 ( V_105 , V_107 ) ;
F_35 ( V_108 |
V_109 ,
V_39 , V_100 ) ;
F_35 ( 0 , V_39 , V_100 ) ;
}
static void T_7 F_97 ( void )
{
T_1 V_110 = F_98 () ?
V_111 : 0 ;
T_1 V_112 = F_98 () ?
V_113 : 0 ;
F_14 ( V_114 , V_115 ) ;
F_99 ( V_116 ,
1 << V_117 ,
V_74 ,
V_118 ) ;
F_35 ( V_66 | V_119 |
V_120 | V_121 ,
V_6 , V_7 ) ;
F_35 ( V_122 |
V_123 |
V_124 ,
V_6 , V_35 ) ;
F_35 ( V_125 | V_126 ,
V_46 , V_47 ) ;
F_35 ( V_127 ,
V_128 , V_7 ) ;
F_35 ( V_110 |
V_129 | V_130 |
V_131 | V_132 |
V_133 | V_134 |
V_135 | V_136 |
V_137 ,
V_40 , V_7 ) ;
F_35 ( V_112 |
V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 ,
V_40 , V_35 ) ;
F_35 ( 0 , V_6 , V_147 ) ;
F_35 ( 0 , V_39 , V_148 ) ;
F_35 ( 0 , V_39 , V_149 ) ;
F_35 ( 0 , V_40 , V_147 ) ;
F_35 ( 0xffffffff , V_150 , V_151 ) ;
F_35 ( 0xffffffff , V_39 , V_151 ) ;
F_35 ( 0xffffffff , V_40 , V_151 ) ;
F_35 ( 0xffffffff , V_152 , V_151 ) ;
F_35 ( 0xffffffff , V_153 , V_151 ) ;
F_35 ( 0xffffffff , V_128 , V_151 ) ;
F_35 ( 0xffffffff , V_37 , V_151 ) ;
F_35 ( 0 , V_46 , V_48 ) ;
F_93 () ;
F_94 () ;
}
void F_100 ( int V_154 )
{
struct V_80 * V_81 ;
T_1 V_82 ;
if ( V_154 )
V_82 = V_65 ;
else
V_82 = V_64 ;
F_83 (pwrst, &pwrst_list, node) {
if ( F_101 ( V_155 ) &&
V_81 -> V_84 == V_62 &&
V_82 == V_65 ) {
V_81 -> V_85 = V_64 ;
F_102 ( L_13 ,
V_156 ) ;
} else {
V_81 -> V_85 = V_82 ;
}
F_84 ( V_81 -> V_84 , V_81 -> V_85 ) ;
}
}
int F_103 ( struct V_157 * V_84 )
{
struct V_80 * V_81 ;
F_83 (pwrst, &pwrst_list, node) {
if ( V_81 -> V_84 == V_84 )
return V_81 -> V_85 ;
}
return - V_92 ;
}
int F_104 ( struct V_157 * V_84 , int V_82 )
{
struct V_80 * V_81 ;
F_83 (pwrst, &pwrst_list, node) {
if ( V_81 -> V_84 == V_84 ) {
V_81 -> V_85 = V_82 ;
return 0 ;
}
}
return - V_92 ;
}
static int T_7 F_105 ( struct V_157 * V_84 , void * V_89 )
{
struct V_80 * V_81 ;
if ( ! V_84 -> V_158 )
return 0 ;
V_81 = F_106 ( sizeof( struct V_80 ) , V_159 ) ;
if ( ! V_81 )
return - V_160 ;
V_81 -> V_84 = V_84 ;
V_81 -> V_85 = V_64 ;
F_107 ( & V_81 -> V_161 , & V_162 ) ;
if ( F_108 ( V_84 ) )
F_109 ( V_84 ) ;
return F_84 ( V_81 -> V_84 , V_81 -> V_85 ) ;
}
static int T_7 F_110 ( struct V_163 * V_164 , void * V_89 )
{
if ( V_164 -> V_165 & V_166 )
F_68 ( V_164 ) ;
else if ( V_164 -> V_165 & V_167 &&
F_111 ( & V_164 -> V_168 ) == 0 )
F_112 ( V_164 ) ;
return 0 ;
}
void F_113 ( void )
{
V_169 = F_114 ( V_170 , V_171 ) ;
if ( F_27 () != V_14 )
F_29 = F_114 ( V_172 ,
V_173 ) ;
}
static void T_7 F_115 ( void )
{
if ( F_98 () ) {
V_174 |= V_175 ;
F_116 () ;
if ( F_38 () < V_176 )
V_174 |= V_155 ;
}
}
static int T_7 F_117 ( void )
{
struct V_80 * V_81 , * V_177 ;
struct V_163 * V_178 , * V_179 , * V_180 , * V_181 ;
int V_11 ;
if ( ! F_118 () )
return - V_182 ;
if ( ! F_48 () )
F_119 ( L_14 ) ;
F_115 () ;
F_97 () ;
V_11 = F_120 ( V_183 ,
( V_184 ) F_39 ,
V_185 , L_15 , NULL ) ;
if ( V_11 ) {
F_31 ( V_17 L_16 ,
V_183 ) ;
goto V_186;
}
V_11 = F_121 ( F_105 , NULL ) ;
if ( V_11 ) {
F_31 ( V_17 L_17 ) ;
goto V_187;
}
( void ) F_122 ( F_110 , NULL ) ;
V_13 = F_123 ( L_18 ) ;
if ( V_13 == NULL ) {
F_31 ( V_17 L_19 ) ;
goto V_187;
}
V_61 = F_123 ( L_20 ) ;
V_63 = F_123 ( L_21 ) ;
V_62 = F_123 ( L_22 ) ;
V_188 = F_123 ( L_23 ) ;
V_178 = F_124 ( L_24 ) ;
V_180 = F_124 ( L_25 ) ;
V_179 = F_124 ( L_26 ) ;
V_181 = F_124 ( L_27 ) ;
#ifdef F_125
F_126 ( & V_189 ) ;
#endif
V_190 = F_71 ;
F_127 () ;
if ( F_101 ( V_175 ) )
F_128 () ;
F_129 ( V_178 , V_180 ) ;
if ( F_27 () != V_14 ) {
V_16 =
F_106 ( 0x803F , V_191 ) ;
if ( ! V_16 )
F_31 ( V_17 L_28
L_29 ) ;
F_72 () ;
F_73 () ;
F_19 () ;
F_25 () ;
F_24 () ;
F_81 () ;
F_80 () ;
}
F_130 () ;
V_186:
return V_11 ;
V_187:
F_131 ( V_183 , NULL ) ;
F_132 (pwrst, tmp, &pwrst_list, node) {
F_133 ( & V_81 -> V_161 ) ;
F_134 ( V_81 ) ;
}
return V_11 ;
}
