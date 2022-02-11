static inline bool F_1 ( void )
{
return ( V_1 != V_2 ) ;
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
int V_3 = 0 ;
if ( F_7 () >= V_4 ) {
F_8 ( V_5 , V_6 ,
V_7 ) ;
F_9 ( V_6 , V_7 ) ;
while ( ! ( F_9 ( V_6 , V_7 ) &
V_8 ) ) {
V_3 ++ ;
if ( V_3 > 1000 ) {
F_10 ( V_9 L_1
L_2 ) ;
return;
}
F_8 ( V_8 ,
V_6 , V_7 ) ;
}
}
}
static void F_11 ( void )
{
if ( F_7 () >= V_4 )
F_12 ( V_5 , V_6 ,
V_7 ) ;
}
static void F_13 ( void )
{
F_14 () ;
F_15 ( F_16 ( V_10 ) ,
V_11 + 0x2a0 ) ;
F_17 () ;
F_18 () ;
F_19 () ;
F_20 () ;
}
static void F_21 ( void )
{
F_22 () ;
F_23 () ;
F_24 () ;
F_25 () ;
}
static void F_26 ( void )
{
T_1 V_12 ;
int V_13 = F_27 ( V_14 ) ;
if ( F_28 () != V_15 ) {
F_29 ( V_14 , V_16 ) ;
V_12 = F_30 ( ( T_1 * )
F_31 ( V_17 ) ) ;
F_29 ( V_14 , V_13 ) ;
if ( V_12 ) {
F_10 ( V_9 L_3 ,
V_12 ) ;
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
V_20 = F_9 ( V_18 , V_24 ) ;
V_20 &= F_9 ( V_18 , V_33 ) ;
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
V_20 = F_9 ( V_18 , V_24 ) ;
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
if ( F_7 () > V_41 ) {
V_36 += F_32 ( V_39 , 3 ) ;
V_36 += F_32 ( V_37 , 1 ) ;
}
return V_36 ;
}
static T_5 F_38 ( int V_42 , void * V_43 )
{
T_1 V_44 , V_45 ;
int V_36 = 0 ;
V_44 = F_9 ( V_46 ,
V_47 ) ;
V_45 = F_9 ( V_46 ,
V_48 ) ;
V_45 &= V_44 ;
do {
if ( V_45 & ( V_49 |
V_50 ) ) {
V_36 = F_37 () ;
F_39 ( V_36 == 0 , L_4
L_5 ) ;
} else {
F_39 ( 1 , L_6
L_7 , V_45 ) ;
}
F_35 ( V_45 , V_46 ,
V_48 ) ;
V_45 = F_9 ( V_46 ,
V_48 ) ;
V_45 &= V_44 ;
} while ( V_45 );
return V_51 ;
}
static void F_40 ( T_1 * V_52 )
{
T_1 V_53 ;
asm("mrc p15, 0, %0, c1, c0, 1" : "=r" (val));
* V_52 ++ = 1 ;
* V_52 ++ = V_53 ;
asm("mrc p15, 1, %0, c9, c0, 2" : "=r" (val));
* V_52 ++ = 1 ;
* V_52 ++ = V_53 ;
}
static int F_41 ( unsigned long V_54 )
{
F_42 ( V_54 ) ;
return 0 ;
}
void F_43 ( void )
{
int V_54 = 0 ;
int V_13 = V_16 ;
int V_55 = V_16 ;
int V_56 = V_16 ;
int V_57 ;
int V_58 , V_59 ;
T_1 V_60 = 0 ;
F_44 ( V_14 ) ;
F_44 ( V_61 ) ;
F_44 ( V_62 ) ;
F_44 ( V_63 ) ;
V_13 = F_27 ( V_14 ) ;
switch ( V_13 ) {
case V_16 :
case V_64 :
V_54 = 0 ;
break;
case V_65 :
V_54 = 3 ;
break;
default:
F_10 ( V_9 L_8 ) ;
return;
}
F_45 () ;
if ( F_46 ( V_61 ) == V_16 )
F_29 ( V_61 , V_13 ) ;
V_55 = F_27 ( V_63 ) ;
V_56 = F_27 ( V_62 ) ;
if ( F_47 () &&
( V_55 < V_16 ||
V_56 < V_16 ) ) {
F_8 ( V_66 , V_6 , V_7 ) ;
F_6 () ;
}
if ( ! F_1 () )
if ( V_55 < V_16 ||
V_56 < V_16 )
if ( ! F_48 () )
goto V_67;
if ( V_55 < V_16 ) {
V_57 = ( V_55 == V_65 ) ? 1 : 0 ;
F_49 ( 2 ) ;
F_49 ( 3 ) ;
F_50 ( V_57 ) ;
if ( V_55 == V_65 )
F_2 () ;
}
if ( V_56 < V_16 ) {
F_49 ( 0 ) ;
F_49 ( 1 ) ;
if ( V_56 == V_65 ) {
F_13 () ;
F_51 () ;
}
}
F_52 () ;
if ( F_7 () >= V_68 &&
F_28 () != V_15 &&
V_56 == V_65 )
V_60 = F_53 ( V_69 ) ;
if ( V_54 )
F_40 ( V_70 ) ;
if ( V_54 == 1 || V_54 == 3 )
F_54 ( V_54 , F_41 ) ;
else
F_41 ( V_54 ) ;
if ( F_7 () >= V_68 &&
F_28 () != V_15 &&
V_56 == V_65 )
F_55 ( V_60 , V_69 ) ;
if ( V_56 < V_16 ) {
V_58 = F_56 ( V_62 ) ;
if ( V_58 == V_65 ) {
F_21 () ;
F_57 () ;
F_58 () ;
F_59 () ;
}
F_60 ( 0 ) ;
F_60 ( 1 ) ;
if ( V_56 == V_65 )
F_12 ( V_71 ,
V_72 ,
V_73 ) ;
}
F_61 () ;
if ( V_55 < V_16 ) {
V_59 = F_56 ( V_63 ) ;
F_62 () ;
if ( V_59 == V_65 )
F_4 () ;
F_60 ( 2 ) ;
F_60 ( 3 ) ;
}
if ( ! F_1 () )
F_63 () ;
V_67:
if ( F_47 () &&
( V_55 < V_16 ||
V_56 < V_16 ) ) {
F_12 ( V_66 , V_6 ,
V_7 ) ;
F_11 () ;
}
F_64 () ;
F_65 ( V_14 -> V_74 [ 0 ] ) ;
}
int F_66 ( void )
{
if ( ! F_67 () )
return 0 ;
return 1 ;
}
static void F_68 ( void )
{
F_69 () ;
F_70 () ;
if ( ! F_66 () )
goto V_75;
if ( F_71 () || F_72 () )
goto V_75;
F_73 ( V_76 , 1 , F_74 () ) ;
F_75 ( 1 , F_74 () ) ;
F_43 () ;
F_76 ( F_74 () ) ;
F_75 ( V_77 , F_74 () ) ;
V_75:
F_77 () ;
F_78 () ;
}
static int F_79 ( void )
{
struct V_78 * V_79 ;
int V_80 , V_12 = 0 ;
F_80 (pwrst, &pwrst_list, node)
V_79 -> V_81 = F_27 ( V_79 -> V_82 ) ;
F_80 (pwrst, &pwrst_list, node) {
if ( F_81 ( V_79 -> V_82 , V_79 -> V_83 ) )
goto V_84;
if ( F_44 ( V_79 -> V_82 ) )
goto V_84;
}
F_82 () ;
F_83 () ;
F_43 () ;
V_84:
F_80 (pwrst, &pwrst_list, node) {
V_80 = F_56 ( V_79 -> V_82 ) ;
if ( V_80 > V_79 -> V_83 ) {
F_10 ( V_85 L_9
L_10 ,
V_79 -> V_82 -> V_86 , V_79 -> V_83 ) ;
V_12 = - 1 ;
}
F_81 ( V_79 -> V_82 , V_79 -> V_81 ) ;
}
if ( V_12 )
F_10 ( V_9 L_11 ) ;
else
F_10 ( V_85 L_12
L_13 ) ;
return V_12 ;
}
static int F_84 ( T_6 V_87 )
{
int V_12 = 0 ;
switch ( V_1 ) {
case V_88 :
case V_89 :
V_12 = F_79 () ;
break;
default:
V_12 = - V_90 ;
}
return V_12 ;
}
static int F_85 ( T_6 V_80 )
{
F_86 () ;
V_1 = V_80 ;
F_87 ( 0 ) ;
return 0 ;
}
static void F_88 ( void )
{
V_1 = V_2 ;
F_87 ( 1 ) ;
F_89 () ;
return;
}
static void T_7 F_90 ( void )
{
F_36 ( 0 , V_91 , V_92 ) ;
if ( ! ( F_33 ( V_91 , V_93 ) &
V_94 ) )
return;
F_35 ( V_95 |
V_96 |
V_97 ,
V_91 , V_98 ) ;
F_36 ( V_99 ,
V_91 , V_92 ) ;
F_15 ( V_100 ,
V_101 ) ;
F_35 ( 0 , V_91 , V_98 ) ;
F_36 ( 0 , V_91 , V_92 ) ;
F_35 ( V_95 |
V_96 |
V_97 ,
V_91 , V_98 ) ;
}
static void T_7 F_91 ( void )
{
T_4 V_102 , V_103 ;
V_102 = ( 1 << 4 ) | ( 1 << 3 ) ;
V_103 = F_92 ( V_104 ) ;
V_103 |= V_102 ;
F_93 ( V_103 , V_104 ) ;
V_103 = F_92 ( V_105 ) ;
V_103 |= V_102 ;
F_93 ( V_103 , V_105 ) ;
F_35 ( V_106 |
V_107 ,
V_39 , V_98 ) ;
F_35 ( 0 , V_39 , V_98 ) ;
}
static void T_7 F_94 ( void )
{
T_1 V_108 = F_95 () ?
V_109 : 0 ;
T_1 V_110 = F_95 () ?
V_111 : 0 ;
F_15 ( V_112 , V_113 ) ;
F_96 ( V_114 ,
1 << V_115 ,
V_72 ,
V_116 ) ;
F_35 ( V_66 | V_117 |
V_118 | V_119 ,
V_6 , V_7 ) ;
F_35 ( V_120 |
V_121 |
V_122 ,
V_6 , V_35 ) ;
F_35 ( V_123 | V_124 ,
V_46 , V_47 ) ;
F_35 ( V_125 ,
V_126 , V_7 ) ;
F_35 ( V_108 |
V_127 | V_128 |
V_129 | V_130 |
V_131 | V_132 |
V_133 | V_134 |
V_135 ,
V_40 , V_7 ) ;
F_35 ( V_110 |
V_136 |
V_137 |
V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_143 |
V_144 ,
V_40 , V_35 ) ;
F_35 ( 0 , V_6 , V_145 ) ;
F_35 ( 0 , V_39 , V_146 ) ;
F_35 ( 0 , V_39 , V_147 ) ;
F_35 ( 0 , V_40 , V_145 ) ;
F_35 ( 0xffffffff , V_148 , V_149 ) ;
F_35 ( 0xffffffff , V_39 , V_149 ) ;
F_35 ( 0xffffffff , V_40 , V_149 ) ;
F_35 ( 0xffffffff , V_150 , V_149 ) ;
F_35 ( 0xffffffff , V_151 , V_149 ) ;
F_35 ( 0xffffffff , V_126 , V_149 ) ;
F_35 ( 0xffffffff , V_37 , V_149 ) ;
F_35 ( 0 , V_46 , V_48 ) ;
F_90 () ;
F_91 () ;
}
void F_97 ( int V_152 )
{
struct V_78 * V_79 ;
T_1 V_80 ;
if ( V_152 )
V_80 = V_65 ;
else
V_80 = V_64 ;
F_80 (pwrst, &pwrst_list, node) {
if ( F_98 ( V_153 ) &&
V_79 -> V_82 == V_62 &&
V_80 == V_65 ) {
V_79 -> V_83 = V_64 ;
F_99 ( L_14 ,
V_154 ) ;
} else {
V_79 -> V_83 = V_80 ;
}
F_81 ( V_79 -> V_82 , V_79 -> V_83 ) ;
}
}
int F_100 ( struct V_155 * V_82 )
{
struct V_78 * V_79 ;
F_80 (pwrst, &pwrst_list, node) {
if ( V_79 -> V_82 == V_82 )
return V_79 -> V_83 ;
}
return - V_90 ;
}
int F_101 ( struct V_155 * V_82 , int V_80 )
{
struct V_78 * V_79 ;
F_80 (pwrst, &pwrst_list, node) {
if ( V_79 -> V_82 == V_82 ) {
V_79 -> V_83 = V_80 ;
return 0 ;
}
}
return - V_90 ;
}
static int T_7 F_102 ( struct V_155 * V_82 , void * V_87 )
{
struct V_78 * V_79 ;
if ( ! V_82 -> V_156 )
return 0 ;
V_79 = F_103 ( sizeof( struct V_78 ) , V_157 ) ;
if ( ! V_79 )
return - V_158 ;
V_79 -> V_82 = V_82 ;
V_79 -> V_83 = V_64 ;
F_104 ( & V_79 -> V_159 , & V_160 ) ;
if ( F_105 ( V_82 ) )
F_106 ( V_82 ) ;
return F_81 ( V_79 -> V_82 , V_79 -> V_83 ) ;
}
static int T_7 F_107 ( struct V_161 * V_162 , void * V_87 )
{
if ( V_162 -> V_163 & V_164 )
F_65 ( V_162 ) ;
else if ( V_162 -> V_163 & V_165 &&
F_108 ( & V_162 -> V_166 ) == 0 )
F_109 ( V_162 ) ;
return 0 ;
}
void F_110 ( void )
{
V_167 = F_111 ( V_168 , V_169 ) ;
if ( F_28 () != V_15 )
F_30 = F_111 ( V_170 ,
V_171 ) ;
}
static void T_7 F_112 ( void )
{
if ( F_95 () ) {
V_172 |= V_173 ;
F_113 () ;
if ( F_7 () < V_174 )
V_172 |= V_153 ;
}
}
static int T_7 F_114 ( void )
{
struct V_78 * V_79 , * V_175 ;
struct V_161 * V_176 , * V_177 , * V_178 , * V_179 ;
int V_12 ;
if ( ! F_115 () )
return - V_180 ;
F_112 () ;
F_94 () ;
V_12 = F_116 ( V_181 ,
( V_182 ) F_38 ,
V_183 , L_15 , NULL ) ;
if ( V_12 ) {
F_10 ( V_9 L_16 ,
V_181 ) ;
goto V_184;
}
V_12 = F_117 ( F_102 , NULL ) ;
if ( V_12 ) {
F_10 ( V_9 L_17 ) ;
goto V_185;
}
( void ) F_118 ( F_107 , NULL ) ;
V_14 = F_119 ( L_18 ) ;
if ( V_14 == NULL ) {
F_10 ( V_9 L_19 ) ;
goto V_185;
}
V_61 = F_119 ( L_20 ) ;
V_63 = F_119 ( L_21 ) ;
V_62 = F_119 ( L_22 ) ;
V_186 = F_119 ( L_23 ) ;
V_176 = F_120 ( L_24 ) ;
V_178 = F_120 ( L_25 ) ;
V_177 = F_120 ( L_26 ) ;
V_179 = F_120 ( L_27 ) ;
#ifdef F_121
F_122 ( & V_187 ) ;
#endif
V_188 = F_68 ;
F_123 () ;
if ( F_98 ( V_173 ) )
F_124 () ;
F_125 ( V_176 , V_178 ) ;
if ( F_28 () != V_15 ) {
V_17 =
F_103 ( 0x803F , V_189 ) ;
if ( ! V_17 )
F_10 ( V_9 L_28
L_29 ) ;
F_69 () ;
F_70 () ;
F_20 () ;
F_26 () ;
F_25 () ;
F_78 () ;
F_77 () ;
}
F_126 () ;
V_184:
return V_12 ;
V_185:
F_127 ( V_181 , NULL ) ;
F_128 (pwrst, tmp, &pwrst_list, node) {
F_129 ( & V_79 -> V_159 ) ;
F_130 ( V_79 ) ;
}
return V_12 ;
}
