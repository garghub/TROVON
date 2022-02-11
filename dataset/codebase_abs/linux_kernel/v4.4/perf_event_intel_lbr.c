static void F_1 ( bool V_1 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
T_1 V_4 , V_5 = 0 , V_6 ;
if ( V_1 && V_7 . V_8 >= 4 )
return;
if ( V_3 -> V_9 )
V_5 = V_3 -> V_9 -> V_10 ;
if ( ! V_1 )
F_3 ( V_11 , V_5 ) ;
F_4 ( V_12 , V_4 ) ;
V_6 = V_4 ;
V_4 |= V_13 ;
if ( ! ( V_5 & V_14 ) )
V_4 |= V_15 ;
if ( V_6 != V_4 )
F_3 ( V_12 , V_4 ) ;
}
static void F_5 ( void )
{
T_1 V_4 ;
F_4 ( V_12 , V_4 ) ;
V_4 &= ~ ( V_13 | V_15 ) ;
F_3 ( V_12 , V_4 ) ;
}
static void F_6 ( void )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_7 . V_17 ; V_16 ++ )
F_3 ( V_7 . V_18 + V_16 , 0 ) ;
}
static void F_7 ( void )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_7 . V_17 ; V_16 ++ ) {
F_3 ( V_7 . V_18 + V_16 , 0 ) ;
F_3 ( V_7 . V_19 + V_16 , 0 ) ;
if ( V_7 . V_20 . V_21 == V_22 )
F_3 ( V_23 + V_16 , 0 ) ;
}
}
void F_8 ( void )
{
if ( ! V_7 . V_17 )
return;
if ( V_7 . V_20 . V_21 == V_24 )
F_6 () ;
else
F_7 () ;
}
static inline T_1 F_9 ( void )
{
T_1 V_25 ;
F_4 ( V_7 . V_26 , V_25 ) ;
return V_25 ;
}
static void F_10 ( struct V_27 * V_28 )
{
int V_16 ;
unsigned V_29 , V_30 ;
T_1 V_25 ;
if ( V_28 -> V_31 == 0 ||
V_28 -> V_32 == V_33 ) {
F_8 () ;
return;
}
V_30 = V_7 . V_17 - 1 ;
V_25 = V_28 -> V_25 ;
for ( V_16 = 0 ; V_16 < V_25 ; V_16 ++ ) {
V_29 = ( V_25 - V_16 ) & V_30 ;
F_3 ( V_7 . V_18 + V_29 , V_28 -> V_18 [ V_16 ] ) ;
F_3 ( V_7 . V_19 + V_29 , V_28 -> V_19 [ V_16 ] ) ;
if ( V_7 . V_20 . V_21 == V_22 )
F_3 ( V_23 + V_29 , V_28 -> V_34 [ V_16 ] ) ;
}
F_3 ( V_7 . V_26 , V_25 ) ;
V_28 -> V_32 = V_33 ;
}
static void F_11 ( struct V_27 * V_28 )
{
int V_16 ;
unsigned V_29 , V_30 ;
T_1 V_25 ;
if ( V_28 -> V_31 == 0 ) {
V_28 -> V_32 = V_33 ;
return;
}
V_30 = V_7 . V_17 - 1 ;
V_25 = F_9 () ;
for ( V_16 = 0 ; V_16 < V_25 ; V_16 ++ ) {
V_29 = ( V_25 - V_16 ) & V_30 ;
F_4 ( V_7 . V_18 + V_29 , V_28 -> V_18 [ V_16 ] ) ;
F_4 ( V_7 . V_19 + V_29 , V_28 -> V_19 [ V_16 ] ) ;
if ( V_7 . V_20 . V_21 == V_22 )
F_4 ( V_23 + V_29 , V_28 -> V_34 [ V_16 ] ) ;
}
V_28 -> V_25 = V_25 ;
V_28 -> V_32 = V_35 ;
}
void F_12 ( struct V_36 * V_37 , bool V_38 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
struct V_27 * V_28 ;
V_28 = V_37 ? V_37 -> V_39 : NULL ;
if ( V_28 ) {
if ( V_38 ) {
F_10 ( V_28 ) ;
V_3 -> V_40 = V_37 ;
} else {
F_11 ( V_28 ) ;
}
return;
}
if ( V_38 ) {
F_8 () ;
V_3 -> V_40 = V_37 ;
}
}
static inline bool F_13 ( unsigned V_41 )
{
return ( V_41 & V_42 ) && ( V_41 & V_43 ) ;
}
void F_14 ( struct V_44 * V_45 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
struct V_27 * V_28 ;
if ( ! V_7 . V_17 )
return;
if ( V_45 -> V_37 -> V_46 && V_3 -> V_40 != V_45 -> V_37 ) {
F_8 () ;
V_3 -> V_40 = V_45 -> V_37 ;
}
V_3 -> V_41 = V_45 -> V_47 . V_48 . V_49 ;
if ( F_13 ( V_3 -> V_41 ) && V_45 -> V_37 &&
V_45 -> V_37 -> V_39 ) {
V_28 = V_45 -> V_37 -> V_39 ;
V_28 -> V_31 ++ ;
}
V_3 -> V_50 ++ ;
F_15 ( V_45 -> V_37 -> V_51 ) ;
}
void F_16 ( struct V_44 * V_45 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
struct V_27 * V_28 ;
if ( ! V_7 . V_17 )
return;
if ( F_13 ( V_3 -> V_41 ) && V_45 -> V_37 &&
V_45 -> V_37 -> V_39 ) {
V_28 = V_45 -> V_37 -> V_39 ;
V_28 -> V_31 -- ;
}
V_3 -> V_50 -- ;
F_17 ( V_3 -> V_50 < 0 ) ;
F_18 ( V_45 -> V_37 -> V_51 ) ;
if ( V_3 -> V_52 && ! V_3 -> V_50 ) {
F_5 () ;
V_3 -> V_40 = NULL ;
}
}
void F_19 ( bool V_1 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
if ( V_3 -> V_50 )
F_1 ( V_1 ) ;
}
void F_20 ( void )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
if ( V_3 -> V_50 )
F_5 () ;
}
static void F_21 ( struct V_2 * V_3 )
{
unsigned long V_30 = V_7 . V_17 - 1 ;
T_1 V_25 = F_9 () ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_7 . V_17 ; V_16 ++ ) {
unsigned long V_29 = ( V_25 - V_16 ) & V_30 ;
union {
struct {
T_2 V_53 ;
T_2 V_54 ;
};
T_1 V_55 ;
} V_56 ;
F_4 ( V_7 . V_18 + V_29 , V_56 . V_55 ) ;
V_3 -> V_57 [ V_16 ] . V_53 = V_56 . V_53 ;
V_3 -> V_57 [ V_16 ] . V_54 = V_56 . V_54 ;
V_3 -> V_57 [ V_16 ] . V_58 = 0 ;
V_3 -> V_57 [ V_16 ] . V_59 = 0 ;
V_3 -> V_57 [ V_16 ] . V_60 = 0 ;
}
V_3 -> V_61 . V_62 = V_16 ;
}
static void F_22 ( struct V_2 * V_3 )
{
unsigned long V_30 = V_7 . V_17 - 1 ;
int V_21 = V_7 . V_20 . V_21 ;
T_1 V_25 = F_9 () ;
int V_16 ;
int V_63 = 0 ;
int V_64 = V_7 . V_17 ;
if ( V_3 -> V_9 -> V_10 & V_14 )
V_64 = V_25 ;
for ( V_16 = 0 ; V_16 < V_64 ; V_16 ++ ) {
unsigned long V_29 = ( V_25 - V_16 ) & V_30 ;
T_1 V_53 , V_54 , V_65 = 0 , V_66 = 0 , V_67 = 0 , abort = 0 ;
int V_68 = 0 ;
T_3 V_69 = 0 ;
int V_70 = V_71 [ V_21 ] ;
F_4 ( V_7 . V_18 + V_29 , V_53 ) ;
F_4 ( V_7 . V_19 + V_29 , V_54 ) ;
if ( V_21 == V_22 ) {
T_1 V_72 ;
F_4 ( V_23 + V_29 , V_72 ) ;
V_65 = ! ! ( V_72 & V_73 ) ;
V_66 = ! V_65 ;
V_67 = ! ! ( V_72 & V_74 ) ;
abort = ! ! ( V_72 & V_75 ) ;
V_69 = ( V_72 & V_76 ) ;
}
if ( V_70 & V_77 ) {
V_65 = ! ! ( V_53 & V_78 ) ;
V_66 = ! V_65 ;
V_68 = 1 ;
}
if ( V_70 & V_79 ) {
V_67 = ! ! ( V_53 & V_80 ) ;
abort = ! ! ( V_53 & V_81 ) ;
V_68 = 3 ;
}
V_53 = ( T_1 ) ( ( ( ( V_82 ) V_53 ) << V_68 ) >> V_68 ) ;
if ( abort && V_7 . V_83 && V_63 > 0 )
V_63 -- ;
V_3 -> V_57 [ V_63 ] . V_53 = V_53 ;
V_3 -> V_57 [ V_63 ] . V_54 = V_54 ;
V_3 -> V_57 [ V_63 ] . V_58 = V_65 ;
V_3 -> V_57 [ V_63 ] . V_59 = V_66 ;
V_3 -> V_57 [ V_63 ] . V_67 = V_67 ;
V_3 -> V_57 [ V_63 ] . abort = abort ;
V_3 -> V_57 [ V_63 ] . V_69 = V_69 ;
V_3 -> V_57 [ V_63 ] . V_60 = 0 ;
V_63 ++ ;
}
V_3 -> V_61 . V_62 = V_63 ;
}
void F_23 ( void )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
if ( ! V_3 -> V_50 )
return;
if ( V_7 . V_20 . V_21 == V_24 )
F_21 ( V_3 ) ;
else
F_22 ( V_3 ) ;
F_24 ( V_3 ) ;
}
static int F_25 ( struct V_44 * V_45 )
{
T_1 V_84 = V_45 -> V_85 . V_86 ;
int V_30 = 0 ;
if ( V_84 & V_87 )
V_30 |= V_42 ;
if ( V_84 & V_88 )
V_30 |= V_89 ;
if ( V_84 & V_90 )
V_30 |= V_91 ;
if ( V_84 & V_92 )
V_30 |= V_93 ;
if ( V_84 & V_94 )
V_30 |= V_95 | V_96 | V_97 ;
if ( V_84 & V_98 )
V_30 |= V_99 ;
if ( V_84 & V_100 )
V_30 |= V_101 ;
if ( V_84 & V_102 )
V_30 |= V_103 ;
if ( V_84 & V_104 )
V_30 |= V_105 ;
if ( V_84 & V_106 )
V_30 |= V_107 ;
if ( V_84 & V_108 ) {
if ( ! F_26 () )
return - V_109 ;
if ( V_30 & ~ ( V_42 | V_89 ) )
return - V_110 ;
V_30 |= V_111 | V_99 | V_95 |
V_43 ;
}
if ( V_84 & V_112 )
V_30 |= V_113 ;
if ( V_84 & V_114 )
V_30 |= V_111 | V_115 ;
V_45 -> V_47 . V_48 . V_49 = V_30 ;
return 0 ;
}
static int F_27 ( struct V_44 * V_45 )
{
struct V_116 * V_49 ;
T_1 V_84 = V_45 -> V_85 . V_86 ;
T_1 V_30 = 0 , V_117 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_118 ; V_16 ++ ) {
if ( ! ( V_84 & ( 1ULL << V_16 ) ) )
continue;
V_117 = V_7 . V_119 [ V_16 ] ;
if ( V_117 == V_120 )
return - V_109 ;
if ( V_117 != V_121 )
V_30 |= V_117 ;
}
V_49 = & V_45 -> V_47 . V_48 ;
V_49 -> V_122 = V_123 ;
V_49 -> V_10 = V_30 ^ V_7 . V_124 ;
return 0 ;
}
int F_28 ( struct V_44 * V_45 )
{
int V_125 = 0 ;
if ( ! V_7 . V_17 )
return - V_109 ;
V_125 = F_25 ( V_45 ) ;
if ( V_125 )
return V_125 ;
if ( V_7 . V_119 )
V_125 = F_27 ( V_45 ) ;
return V_125 ;
}
static int F_29 ( unsigned long V_53 , unsigned long V_54 , int abort )
{
struct V_126 V_126 ;
void * V_127 ;
int V_128 , V_129 ;
int V_125 = V_130 ;
int V_131 , V_132 , V_133 ;
T_4 V_134 [ V_135 ] ;
int V_136 = 0 ;
V_132 = F_30 ( V_54 ) ? V_89 : V_42 ;
V_133 = F_30 ( V_53 ) ? V_89 : V_42 ;
if ( V_53 == 0 || V_54 == 0 )
return V_130 ;
if ( abort )
return V_101 | V_132 ;
if ( V_133 == V_42 ) {
if ( ! V_137 -> V_138 )
return V_130 ;
V_129 = F_31 ( V_134 , ( void V_139 * ) V_53 ,
V_135 ) ;
V_128 = V_135 - V_129 ;
if ( ! V_128 )
return V_130 ;
V_127 = V_134 ;
} else {
if ( F_32 ( V_53 ) ) {
V_127 = ( void * ) V_53 ;
V_128 = V_135 ;
} else {
return V_130 ;
}
}
#ifdef F_33
V_136 = F_30 ( ( unsigned long ) V_127 ) || ! F_34 ( V_140 ) ;
#endif
F_35 ( & V_126 , V_127 , V_128 , V_136 ) ;
F_36 ( & V_126 ) ;
if ( ! V_126 . V_141 . V_142 )
return V_101 ;
switch ( V_126 . V_141 . V_143 [ 0 ] ) {
case 0xf :
switch ( V_126 . V_141 . V_143 [ 1 ] ) {
case 0x05 :
case 0x34 :
V_125 = V_144 ;
break;
case 0x07 :
case 0x35 :
V_125 = V_97 ;
break;
case 0x80 ... 0x8f :
V_125 = V_107 ;
break;
default:
V_125 = V_130 ;
}
break;
case 0x70 ... 0x7f :
V_125 = V_107 ;
break;
case 0xc2 :
case 0xc3 :
case 0xca :
case 0xcb :
V_125 = V_95 ;
break;
case 0xcf :
V_125 = V_96 ;
break;
case 0xcc ... 0xce :
V_125 = V_145 ;
break;
case 0xe8 :
F_37 ( & V_126 ) ;
if ( V_126 . V_146 . V_147 == 0 ) {
V_125 = V_115 ;
break;
}
case 0x9a :
V_125 = V_111 ;
break;
case 0xe0 ... 0xe3 :
V_125 = V_107 ;
break;
case 0xe9 ... 0xeb :
V_125 = V_148 ;
break;
case 0xff :
F_38 ( & V_126 ) ;
V_131 = ( V_126 . V_149 . V_143 [ 0 ] >> 3 ) & 0x7 ;
switch ( V_131 ) {
case 2 :
case 3 :
V_125 = V_99 ;
break;
case 4 :
case 5 :
V_125 = V_113 ;
break;
}
break;
default:
V_125 = V_130 ;
}
if ( V_133 == V_42 && V_132 == V_89
&& V_125 != V_144 && V_125 != V_145 )
V_125 = V_150 ;
if ( V_125 != V_130 )
V_125 |= V_132 ;
return V_125 ;
}
static void
F_24 ( struct V_2 * V_3 )
{
T_1 V_53 , V_54 ;
int V_41 = V_3 -> V_41 ;
int V_16 , V_151 , type ;
bool V_152 = false ;
if ( ( V_41 & V_153 ) == V_153 )
return;
for ( V_16 = 0 ; V_16 < V_3 -> V_61 . V_62 ; V_16 ++ ) {
V_53 = V_3 -> V_57 [ V_16 ] . V_53 ;
V_54 = V_3 -> V_57 [ V_16 ] . V_54 ;
type = F_29 ( V_53 , V_54 , V_3 -> V_57 [ V_16 ] . abort ) ;
if ( type != V_130 && ( V_41 & V_154 ) ) {
if ( V_3 -> V_57 [ V_16 ] . V_67 )
type |= V_103 ;
else
type |= V_105 ;
}
if ( type == V_130 || ( V_41 & type ) != type ) {
V_3 -> V_57 [ V_16 ] . V_53 = 0 ;
V_152 = true ;
}
}
if ( ! V_152 )
return;
for ( V_16 = 0 ; V_16 < V_3 -> V_61 . V_62 ; ) {
if ( ! V_3 -> V_57 [ V_16 ] . V_53 ) {
V_151 = V_16 ;
while ( ++ V_151 < V_3 -> V_61 . V_62 )
V_3 -> V_57 [ V_151 - 1 ] = V_3 -> V_57 [ V_151 ] ;
V_3 -> V_61 . V_62 -- ;
if ( ! V_3 -> V_57 [ V_16 ] . V_53 )
continue;
}
V_16 ++ ;
}
}
void T_5 F_39 ( void )
{
V_7 . V_17 = 4 ;
V_7 . V_26 = V_155 ;
V_7 . V_18 = V_156 ;
V_7 . V_19 = V_157 ;
F_40 ( L_1 ) ;
}
void T_5 F_41 ( void )
{
V_7 . V_17 = 16 ;
V_7 . V_26 = V_155 ;
V_7 . V_18 = V_158 ;
V_7 . V_19 = V_159 ;
V_7 . V_124 = V_160 ;
V_7 . V_119 = V_161 ;
F_40 ( L_2 ) ;
}
void T_5 F_42 ( void )
{
V_7 . V_17 = 16 ;
V_7 . V_26 = V_155 ;
V_7 . V_18 = V_158 ;
V_7 . V_19 = V_159 ;
V_7 . V_124 = V_160 ;
V_7 . V_119 = V_162 ;
F_40 ( L_2 ) ;
}
void F_43 ( void )
{
V_7 . V_17 = 16 ;
V_7 . V_26 = V_155 ;
V_7 . V_18 = V_158 ;
V_7 . V_19 = V_159 ;
V_7 . V_124 = V_160 ;
V_7 . V_119 = V_163 ;
F_40 ( L_2 ) ;
}
T_5 void F_44 ( void )
{
V_7 . V_17 = 32 ;
V_7 . V_26 = V_155 ;
V_7 . V_18 = V_158 ;
V_7 . V_19 = V_159 ;
V_7 . V_124 = V_160 ;
V_7 . V_119 = V_163 ;
F_40 ( L_3 ) ;
}
void T_5 F_45 ( void )
{
if ( V_164 . V_165 == 28
&& V_164 . V_166 < 10 ) {
F_40 ( L_4 ) ;
return;
}
V_7 . V_17 = 8 ;
V_7 . V_26 = V_155 ;
V_7 . V_18 = V_156 ;
V_7 . V_19 = V_157 ;
F_40 ( L_5 ) ;
}
