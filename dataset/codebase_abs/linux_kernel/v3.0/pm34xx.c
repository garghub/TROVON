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
static void F_40 ( void )
{
void T_6 * V_52 ;
T_1 V_53 , V_54 ;
T_1 * V_55 ;
V_52 = F_41 ( V_56 ) ;
V_55 = ( T_1 * ) F_42 ( V_52 +
V_57 ) ;
V_53 = F_42 ( V_52 +
V_58 ) ;
V_55 = F_43 ( V_55 ) ;
* V_55 = V_53 ;
F_44 () ;
V_54 = F_42 ( V_52
+ V_59 ) ;
F_45 ( V_54 ) ;
}
void F_46 ( void )
{
int V_60 = 0 ;
int V_13 = V_16 ;
int V_61 = V_16 ;
int V_62 = V_16 ;
int V_63 ;
int V_64 , V_65 ;
T_1 V_66 = 0 ;
if ( ! V_67 )
return;
F_47 ( V_14 ) ;
F_47 ( V_68 ) ;
F_47 ( V_69 ) ;
F_47 ( V_70 ) ;
V_13 = F_27 ( V_14 ) ;
switch ( V_13 ) {
case V_16 :
case V_71 :
V_60 = 0 ;
break;
case V_72 :
V_60 = 3 ;
break;
default:
F_10 ( V_9 L_8 ) ;
return;
}
F_48 () ;
if ( F_49 ( V_68 ) == V_16 )
F_29 ( V_68 , V_13 ) ;
V_61 = F_27 ( V_70 ) ;
V_62 = F_27 ( V_69 ) ;
if ( F_50 () &&
( V_61 < V_16 ||
V_62 < V_16 ) ) {
F_8 ( V_73 , V_6 , V_7 ) ;
F_6 () ;
}
if ( ! F_1 () )
if ( V_61 < V_16 ||
V_62 < V_16 )
if ( ! F_51 () )
goto V_74;
if ( V_61 < V_16 ) {
V_63 = ( V_61 == V_72 ) ? 1 : 0 ;
F_52 ( 2 ) ;
F_52 ( 3 ) ;
F_53 ( V_63 ) ;
if ( V_61 == V_72 )
F_2 () ;
}
if ( V_62 < V_16 ) {
F_52 ( 0 ) ;
F_52 ( 1 ) ;
if ( V_62 == V_72 ) {
F_13 () ;
F_54 () ;
}
}
F_55 () ;
if ( F_7 () >= V_75 &&
F_28 () != V_15 &&
V_62 == V_72 )
V_66 = F_56 ( V_76 ) ;
V_67 ( V_77 , V_60 ) ;
F_57 () ;
if ( F_7 () >= V_75 &&
F_28 () != V_15 &&
V_62 == V_72 )
F_58 ( V_66 , V_76 ) ;
if ( F_59 ( V_14 ) == V_72 )
F_40 () ;
if ( V_62 < V_16 ) {
V_64 = F_59 ( V_69 ) ;
if ( V_64 == V_72 ) {
F_21 () ;
F_60 () ;
F_61 () ;
F_62 () ;
}
F_63 ( 0 ) ;
F_63 ( 1 ) ;
if ( V_62 == V_72 )
F_12 ( V_78 ,
V_79 ,
V_80 ) ;
}
F_64 () ;
if ( V_61 < V_16 ) {
V_65 = F_59 ( V_70 ) ;
F_65 () ;
if ( V_65 == V_72 )
F_4 () ;
F_63 ( 2 ) ;
F_63 ( 3 ) ;
}
if ( ! F_1 () )
F_66 () ;
V_74:
if ( F_50 () &&
( V_61 < V_16 ||
V_62 < V_16 ) ) {
F_12 ( V_73 , V_6 ,
V_7 ) ;
F_11 () ;
}
F_67 () ;
F_68 ( V_14 -> V_81 [ 0 ] ) ;
}
int F_69 ( void )
{
if ( ! V_82 )
return 0 ;
if ( ! F_70 () )
return 0 ;
return 1 ;
}
static void F_71 ( void )
{
F_72 () ;
F_73 () ;
if ( ! F_69 () )
goto V_83;
if ( F_74 () || F_75 () )
goto V_83;
F_76 ( V_84 , 1 , F_77 () ) ;
F_78 ( 1 , F_77 () ) ;
F_46 () ;
F_79 ( F_77 () ) ;
F_78 ( V_85 , F_77 () ) ;
V_83:
F_80 () ;
F_81 () ;
}
static int F_82 ( void )
{
struct V_86 * V_87 ;
int V_88 , V_12 = 0 ;
if ( V_89 || V_90 )
F_83 ( V_89 ,
V_90 ) ;
F_84 (pwrst, &pwrst_list, node)
V_87 -> V_91 = F_27 ( V_87 -> V_92 ) ;
F_84 (pwrst, &pwrst_list, node) {
if ( F_85 ( V_87 -> V_92 , V_87 -> V_93 ) )
goto V_94;
if ( F_47 ( V_87 -> V_92 ) )
goto V_94;
}
F_86 () ;
F_87 () ;
F_46 () ;
V_94:
F_84 (pwrst, &pwrst_list, node) {
V_88 = F_59 ( V_87 -> V_92 ) ;
if ( V_88 > V_87 -> V_93 ) {
F_10 ( V_95 L_9
L_10 ,
V_87 -> V_92 -> V_96 , V_87 -> V_93 ) ;
V_12 = - 1 ;
}
F_85 ( V_87 -> V_92 , V_87 -> V_91 ) ;
}
if ( V_12 )
F_10 ( V_9 L_11 ) ;
else
F_10 ( V_95 L_12
L_13 ) ;
return V_12 ;
}
static int F_88 ( T_7 V_97 )
{
int V_12 = 0 ;
switch ( V_1 ) {
case V_98 :
case V_99 :
V_12 = F_82 () ;
break;
default:
V_12 = - V_100 ;
}
return V_12 ;
}
static int F_89 ( T_7 V_88 )
{
F_90 () ;
V_1 = V_88 ;
F_91 ( 0 ) ;
return 0 ;
}
static void F_92 ( void )
{
V_1 = V_2 ;
F_91 ( 1 ) ;
F_93 () ;
return;
}
static void T_8 F_94 ( void )
{
F_36 ( 0 , V_101 , V_102 ) ;
if ( ! ( F_33 ( V_101 , V_103 ) &
V_104 ) )
return;
F_35 ( V_105 |
V_106 |
V_107 ,
V_101 , V_108 ) ;
F_36 ( V_109 ,
V_101 , V_102 ) ;
F_15 ( V_110 ,
V_111 ) ;
F_35 ( 0 , V_101 , V_108 ) ;
F_36 ( 0 , V_101 , V_102 ) ;
F_35 ( V_105 |
V_106 |
V_107 ,
V_101 , V_108 ) ;
}
static void T_8 F_95 ( void )
{
T_4 V_112 , V_113 ;
V_112 = ( 1 << 4 ) | ( 1 << 3 ) ;
V_113 = F_96 ( V_114 ) ;
V_113 |= V_112 ;
F_97 ( V_113 , V_114 ) ;
V_113 = F_96 ( V_115 ) ;
V_113 |= V_112 ;
F_97 ( V_113 , V_115 ) ;
F_35 ( V_116 |
V_117 ,
V_39 , V_108 ) ;
F_35 ( 0 , V_39 , V_108 ) ;
}
static void T_8 F_98 ( void )
{
T_1 V_118 = F_99 () ?
V_119 : 0 ;
T_1 V_120 = F_99 () ?
V_121 : 0 ;
F_15 ( V_122 , V_123 ) ;
F_100 ( V_124 ,
1 << V_125 ,
V_79 ,
V_126 ) ;
F_35 ( V_73 | V_127 |
V_128 | V_129 ,
V_6 , V_7 ) ;
F_35 ( V_130 |
V_131 |
V_132 ,
V_6 , V_35 ) ;
F_35 ( V_133 | V_134 ,
V_46 , V_47 ) ;
F_35 ( V_135 ,
V_136 , V_7 ) ;
F_35 ( V_118 |
V_137 | V_138 |
V_139 | V_140 |
V_141 | V_142 |
V_143 | V_144 |
V_145 ,
V_40 , V_7 ) ;
F_35 ( V_120 |
V_146 |
V_147 |
V_148 |
V_149 |
V_150 |
V_151 |
V_152 |
V_153 |
V_154 ,
V_40 , V_35 ) ;
F_35 ( 0 , V_6 , V_155 ) ;
F_35 ( 0 , V_39 , V_156 ) ;
F_35 ( 0 , V_39 , V_157 ) ;
F_35 ( 0 , V_40 , V_155 ) ;
F_35 ( 0xffffffff , V_158 , V_159 ) ;
F_35 ( 0xffffffff , V_39 , V_159 ) ;
F_35 ( 0xffffffff , V_40 , V_159 ) ;
F_35 ( 0xffffffff , V_160 , V_159 ) ;
F_35 ( 0xffffffff , V_161 , V_159 ) ;
F_35 ( 0xffffffff , V_136 , V_159 ) ;
F_35 ( 0xffffffff , V_37 , V_159 ) ;
F_35 ( 0 , V_46 , V_48 ) ;
F_94 () ;
F_95 () ;
}
void F_101 ( int V_162 )
{
struct V_86 * V_87 ;
T_1 V_88 ;
if ( V_162 )
V_88 = V_72 ;
else
V_88 = V_71 ;
F_84 (pwrst, &pwrst_list, node) {
if ( F_102 ( V_163 ) &&
V_87 -> V_92 == V_69 &&
V_88 == V_72 ) {
V_87 -> V_93 = V_71 ;
F_103 ( L_14 ,
V_164 ) ;
} else {
V_87 -> V_93 = V_88 ;
}
F_85 ( V_87 -> V_92 , V_87 -> V_93 ) ;
}
}
int F_104 ( struct V_165 * V_92 )
{
struct V_86 * V_87 ;
F_84 (pwrst, &pwrst_list, node) {
if ( V_87 -> V_92 == V_92 )
return V_87 -> V_93 ;
}
return - V_100 ;
}
int F_105 ( struct V_165 * V_92 , int V_88 )
{
struct V_86 * V_87 ;
F_84 (pwrst, &pwrst_list, node) {
if ( V_87 -> V_92 == V_92 ) {
V_87 -> V_93 = V_88 ;
return 0 ;
}
}
return - V_100 ;
}
static int T_8 F_106 ( struct V_165 * V_92 , void * V_97 )
{
struct V_86 * V_87 ;
if ( ! V_92 -> V_166 )
return 0 ;
V_87 = F_107 ( sizeof( struct V_86 ) , V_167 ) ;
if ( ! V_87 )
return - V_168 ;
V_87 -> V_92 = V_92 ;
V_87 -> V_93 = V_71 ;
F_108 ( & V_87 -> V_169 , & V_170 ) ;
if ( F_109 ( V_92 ) )
F_110 ( V_92 ) ;
return F_85 ( V_87 -> V_92 , V_87 -> V_93 ) ;
}
static int T_8 F_111 ( struct V_171 * V_172 , void * V_97 )
{
if ( V_172 -> V_173 & V_174 )
F_68 ( V_172 ) ;
else if ( V_172 -> V_173 & V_175 &&
F_112 ( & V_172 -> V_176 ) == 0 )
F_113 ( V_172 ) ;
return 0 ;
}
void F_114 ( void )
{
V_67 = F_115 ( V_177 ,
V_178 ) ;
if ( F_28 () != V_15 )
F_30 = F_115 ( V_179 ,
V_180 ) ;
}
static void T_8 F_116 ( void )
{
if ( F_99 () ) {
V_181 |= V_182 ;
F_117 () ;
if ( F_7 () < V_183 )
V_181 |= V_163 ;
}
}
static int T_8 F_118 ( void )
{
struct V_86 * V_87 , * V_184 ;
struct V_171 * V_185 , * V_186 , * V_187 , * V_188 ;
int V_12 ;
if ( ! F_119 () )
return - V_189 ;
F_116 () ;
F_98 () ;
V_12 = F_120 ( V_190 ,
( V_191 ) F_38 ,
V_192 , L_15 , NULL ) ;
if ( V_12 ) {
F_10 ( V_9 L_16 ,
V_190 ) ;
goto V_193;
}
V_12 = F_121 ( F_106 , NULL ) ;
if ( V_12 ) {
F_10 ( V_9 L_17 ) ;
goto V_194;
}
( void ) F_122 ( F_111 , NULL ) ;
V_14 = F_123 ( L_18 ) ;
if ( V_14 == NULL ) {
F_10 ( V_9 L_19 ) ;
goto V_194;
}
V_68 = F_123 ( L_20 ) ;
V_70 = F_123 ( L_21 ) ;
V_69 = F_123 ( L_22 ) ;
V_195 = F_123 ( L_23 ) ;
V_185 = F_124 ( L_24 ) ;
V_187 = F_124 ( L_25 ) ;
V_186 = F_124 ( L_26 ) ;
V_188 = F_124 ( L_27 ) ;
F_114 () ;
#ifdef F_125
F_126 ( & V_196 ) ;
#endif
V_197 = F_71 ;
F_127 () ;
if ( F_102 ( V_182 ) )
F_128 () ;
F_129 ( V_185 , V_187 ) ;
if ( F_28 () != V_15 ) {
V_17 =
F_107 ( 0x803F , V_198 ) ;
if ( ! V_17 )
F_10 ( V_9 L_28
L_29 ) ;
F_72 () ;
F_73 () ;
F_20 () ;
F_26 () ;
F_25 () ;
F_81 () ;
F_80 () ;
}
F_130 () ;
V_193:
return V_12 ;
V_194:
F_131 ( V_190 , NULL ) ;
F_132 (pwrst, tmp, &pwrst_list, node) {
F_133 ( & V_87 -> V_169 ) ;
F_134 ( V_87 ) ;
}
return V_12 ;
}
