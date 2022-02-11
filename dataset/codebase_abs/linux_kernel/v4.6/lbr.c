static void F_1 ( bool V_1 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
T_1 V_4 , V_5 = 0 , V_6 ;
if ( V_1 && V_7 . V_8 >= 4 )
return;
if ( V_3 -> V_9 )
V_5 = V_3 -> V_9 -> V_10 & V_7 . V_11 ;
if ( ! V_1 && V_3 -> V_9 )
F_3 ( V_12 , V_5 ) ;
F_4 ( V_13 , V_4 ) ;
V_6 = V_4 ;
V_4 |= V_14 ;
if ( ! ( V_5 & V_15 ) )
V_4 |= V_16 ;
if ( V_6 != V_4 )
F_3 ( V_13 , V_4 ) ;
}
static void F_5 ( void )
{
T_1 V_4 ;
F_4 ( V_13 , V_4 ) ;
V_4 &= ~ ( V_14 | V_16 ) ;
F_3 ( V_13 , V_4 ) ;
}
static void F_6 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_7 . V_18 ; V_17 ++ )
F_3 ( V_7 . V_19 + V_17 , 0 ) ;
}
static void F_7 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_7 . V_18 ; V_17 ++ ) {
F_3 ( V_7 . V_19 + V_17 , 0 ) ;
F_3 ( V_7 . V_20 + V_17 , 0 ) ;
if ( V_7 . V_21 . V_22 == V_23 )
F_3 ( V_24 + V_17 , 0 ) ;
}
}
void F_8 ( void )
{
if ( ! V_7 . V_18 )
return;
if ( V_7 . V_21 . V_22 == V_25 )
F_6 () ;
else
F_7 () ;
}
static inline T_1 F_9 ( void )
{
T_1 V_26 ;
F_4 ( V_7 . V_27 , V_26 ) ;
return V_26 ;
}
static void F_10 ( struct V_28 * V_29 )
{
int V_17 ;
unsigned V_30 , V_31 ;
T_1 V_26 ;
if ( V_29 -> V_32 == 0 ||
V_29 -> V_33 == V_34 ) {
F_8 () ;
return;
}
V_31 = V_7 . V_18 - 1 ;
V_26 = V_29 -> V_26 ;
for ( V_17 = 0 ; V_17 < V_26 ; V_17 ++ ) {
V_30 = ( V_26 - V_17 ) & V_31 ;
F_3 ( V_7 . V_19 + V_30 , V_29 -> V_19 [ V_17 ] ) ;
F_3 ( V_7 . V_20 + V_30 , V_29 -> V_20 [ V_17 ] ) ;
if ( V_7 . V_21 . V_22 == V_23 )
F_3 ( V_24 + V_30 , V_29 -> V_35 [ V_17 ] ) ;
}
F_3 ( V_7 . V_27 , V_26 ) ;
V_29 -> V_33 = V_34 ;
}
static void F_11 ( struct V_28 * V_29 )
{
int V_17 ;
unsigned V_30 , V_31 ;
T_1 V_26 ;
if ( V_29 -> V_32 == 0 ) {
V_29 -> V_33 = V_34 ;
return;
}
V_31 = V_7 . V_18 - 1 ;
V_26 = F_9 () ;
for ( V_17 = 0 ; V_17 < V_26 ; V_17 ++ ) {
V_30 = ( V_26 - V_17 ) & V_31 ;
F_4 ( V_7 . V_19 + V_30 , V_29 -> V_19 [ V_17 ] ) ;
F_4 ( V_7 . V_20 + V_30 , V_29 -> V_20 [ V_17 ] ) ;
if ( V_7 . V_21 . V_22 == V_23 )
F_4 ( V_24 + V_30 , V_29 -> V_35 [ V_17 ] ) ;
}
V_29 -> V_26 = V_26 ;
V_29 -> V_33 = V_36 ;
}
void F_12 ( struct V_37 * V_38 , bool V_39 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
struct V_28 * V_29 ;
V_29 = V_38 ? V_38 -> V_40 : NULL ;
if ( V_29 ) {
if ( V_39 ) {
F_10 ( V_29 ) ;
V_3 -> V_41 = V_38 ;
} else {
F_11 ( V_29 ) ;
}
return;
}
if ( V_39 ) {
F_8 () ;
V_3 -> V_41 = V_38 ;
}
}
static inline bool F_13 ( unsigned V_42 )
{
return ( V_42 & V_43 ) && ( V_42 & V_44 ) ;
}
void F_14 ( struct V_45 * V_46 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
struct V_28 * V_29 ;
if ( ! V_7 . V_18 )
return;
if ( V_46 -> V_38 -> V_47 && V_3 -> V_41 != V_46 -> V_38 ) {
F_8 () ;
V_3 -> V_41 = V_46 -> V_38 ;
}
V_3 -> V_42 = V_46 -> V_48 . V_49 . V_50 ;
if ( F_13 ( V_3 -> V_42 ) && V_46 -> V_38 &&
V_46 -> V_38 -> V_40 ) {
V_29 = V_46 -> V_38 -> V_40 ;
V_29 -> V_32 ++ ;
}
V_3 -> V_51 ++ ;
F_15 ( V_46 -> V_38 -> V_52 ) ;
}
void F_16 ( struct V_45 * V_46 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
struct V_28 * V_29 ;
if ( ! V_7 . V_18 )
return;
if ( F_13 ( V_3 -> V_42 ) && V_46 -> V_38 &&
V_46 -> V_38 -> V_40 ) {
V_29 = V_46 -> V_38 -> V_40 ;
V_29 -> V_32 -- ;
}
V_3 -> V_51 -- ;
F_17 ( V_3 -> V_51 < 0 ) ;
F_18 ( V_46 -> V_38 -> V_52 ) ;
if ( V_3 -> V_53 && ! V_3 -> V_51 ) {
F_5 () ;
V_3 -> V_41 = NULL ;
}
}
void F_19 ( bool V_1 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
if ( V_3 -> V_51 )
F_1 ( V_1 ) ;
}
void F_20 ( void )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
if ( V_3 -> V_51 )
F_5 () ;
}
static void F_21 ( struct V_2 * V_3 )
{
unsigned long V_31 = V_7 . V_18 - 1 ;
T_1 V_26 = F_9 () ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_7 . V_18 ; V_17 ++ ) {
unsigned long V_30 = ( V_26 - V_17 ) & V_31 ;
union {
struct {
T_2 V_54 ;
T_2 V_55 ;
};
T_1 V_56 ;
} V_57 ;
F_4 ( V_7 . V_19 + V_30 , V_57 . V_56 ) ;
V_3 -> V_58 [ V_17 ] . V_54 = V_57 . V_54 ;
V_3 -> V_58 [ V_17 ] . V_55 = V_57 . V_55 ;
V_3 -> V_58 [ V_17 ] . V_59 = 0 ;
V_3 -> V_58 [ V_17 ] . V_60 = 0 ;
V_3 -> V_58 [ V_17 ] . V_61 = 0 ;
}
V_3 -> V_62 . V_63 = V_17 ;
}
static void F_22 ( struct V_2 * V_3 )
{
bool V_64 = false ;
unsigned long V_31 = V_7 . V_18 - 1 ;
int V_22 = V_7 . V_21 . V_22 ;
T_1 V_26 = F_9 () ;
int V_17 ;
int V_65 = 0 ;
int V_66 = V_7 . V_18 ;
if ( V_3 -> V_9 ) {
V_64 = ! ( V_3 -> V_9 -> V_10 & V_67 ) ;
if ( V_3 -> V_9 -> V_10 & V_15 )
V_66 = V_26 ;
}
for ( V_17 = 0 ; V_17 < V_66 ; V_17 ++ ) {
unsigned long V_30 = ( V_26 - V_17 ) & V_31 ;
T_1 V_54 , V_55 , V_68 = 0 , V_69 = 0 , V_70 = 0 , abort = 0 ;
int V_71 = 0 ;
T_3 V_72 = 0 ;
int V_73 = V_74 [ V_22 ] ;
F_4 ( V_7 . V_19 + V_30 , V_54 ) ;
F_4 ( V_7 . V_20 + V_30 , V_55 ) ;
if ( V_22 == V_23 && V_64 ) {
T_1 V_75 ;
F_4 ( V_24 + V_30 , V_75 ) ;
V_68 = ! ! ( V_75 & V_76 ) ;
V_69 = ! V_68 ;
V_70 = ! ! ( V_75 & V_77 ) ;
abort = ! ! ( V_75 & V_78 ) ;
V_72 = ( V_75 & V_79 ) ;
}
if ( V_73 & V_80 ) {
V_68 = ! ! ( V_54 & V_81 ) ;
V_69 = ! V_68 ;
V_71 = 1 ;
}
if ( V_73 & V_82 ) {
V_70 = ! ! ( V_54 & V_83 ) ;
abort = ! ! ( V_54 & V_84 ) ;
V_71 = 3 ;
}
V_54 = ( T_1 ) ( ( ( ( V_85 ) V_54 ) << V_71 ) >> V_71 ) ;
if ( abort && V_7 . V_86 && V_65 > 0 )
V_65 -- ;
V_3 -> V_58 [ V_65 ] . V_54 = V_54 ;
V_3 -> V_58 [ V_65 ] . V_55 = V_55 ;
V_3 -> V_58 [ V_65 ] . V_59 = V_68 ;
V_3 -> V_58 [ V_65 ] . V_60 = V_69 ;
V_3 -> V_58 [ V_65 ] . V_70 = V_70 ;
V_3 -> V_58 [ V_65 ] . abort = abort ;
V_3 -> V_58 [ V_65 ] . V_72 = V_72 ;
V_3 -> V_58 [ V_65 ] . V_61 = 0 ;
V_65 ++ ;
}
V_3 -> V_62 . V_63 = V_65 ;
}
void F_23 ( void )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
if ( ! V_3 -> V_51 )
return;
if ( V_7 . V_21 . V_22 == V_25 )
F_21 ( V_3 ) ;
else
F_22 ( V_3 ) ;
F_24 ( V_3 ) ;
}
static int F_25 ( struct V_45 * V_46 )
{
T_1 V_87 = V_46 -> V_88 . V_89 ;
int V_31 = 0 ;
if ( V_87 & V_90 )
V_31 |= V_43 ;
if ( V_87 & V_91 )
V_31 |= V_92 ;
if ( V_87 & V_93 )
V_31 |= V_94 ;
if ( V_87 & V_95 )
V_31 |= V_96 ;
if ( V_87 & V_97 )
V_31 |= V_98 | V_99 | V_100 ;
if ( V_87 & V_101 )
V_31 |= V_102 ;
if ( V_87 & V_103 )
V_31 |= V_104 ;
if ( V_87 & V_105 )
V_31 |= V_106 ;
if ( V_87 & V_107 )
V_31 |= V_108 ;
if ( V_87 & V_109 )
V_31 |= V_110 ;
if ( V_87 & V_111 ) {
if ( ! F_26 () )
return - V_112 ;
if ( V_31 & ~ ( V_43 | V_92 ) )
return - V_113 ;
V_31 |= V_114 | V_102 | V_98 |
V_44 ;
}
if ( V_87 & V_115 )
V_31 |= V_116 ;
if ( V_87 & V_117 )
V_31 |= V_114 | V_118 ;
V_46 -> V_48 . V_49 . V_50 = V_31 ;
return 0 ;
}
static int F_27 ( struct V_45 * V_46 )
{
struct V_119 * V_50 ;
T_1 V_87 = V_46 -> V_88 . V_89 ;
T_1 V_31 = 0 , V_120 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_121 ; V_17 ++ ) {
if ( ! ( V_87 & ( 1ULL << V_17 ) ) )
continue;
V_120 = V_7 . V_122 [ V_17 ] ;
if ( V_120 == V_123 )
return - V_112 ;
if ( V_120 != V_124 )
V_31 |= V_120 ;
}
V_50 = & V_46 -> V_48 . V_49 ;
V_50 -> V_125 = V_126 ;
V_50 -> V_10 = V_31 ^ ( V_7 . V_11 & ~ V_15 ) ;
if ( ( V_87 & V_127 ) &&
( V_87 & V_128 ) &&
( V_7 . V_21 . V_22 == V_23 ) )
V_50 -> V_10 |= V_67 ;
return 0 ;
}
int F_28 ( struct V_45 * V_46 )
{
int V_129 = 0 ;
if ( ! V_7 . V_18 )
return - V_112 ;
V_129 = F_25 ( V_46 ) ;
if ( V_129 )
return V_129 ;
if ( V_7 . V_122 )
V_129 = F_27 ( V_46 ) ;
return V_129 ;
}
static int F_29 ( unsigned long V_54 , unsigned long V_55 , int abort )
{
struct V_130 V_130 ;
void * V_131 ;
int V_132 , V_133 ;
int V_129 = V_134 ;
int V_135 , V_136 , V_137 ;
T_4 V_138 [ V_139 ] ;
int V_140 = 0 ;
V_136 = F_30 ( V_55 ) ? V_92 : V_43 ;
V_137 = F_30 ( V_54 ) ? V_92 : V_43 ;
if ( V_54 == 0 || V_55 == 0 )
return V_134 ;
if ( abort )
return V_104 | V_136 ;
if ( V_137 == V_43 ) {
if ( ! V_141 -> V_142 )
return V_134 ;
V_133 = F_31 ( V_138 , ( void V_143 * ) V_54 ,
V_139 ) ;
V_132 = V_139 - V_133 ;
if ( ! V_132 )
return V_134 ;
V_131 = V_138 ;
} else {
if ( F_32 ( V_54 ) ) {
V_131 = ( void * ) V_54 ;
V_132 = V_139 ;
} else {
return V_134 ;
}
}
#ifdef F_33
V_140 = F_30 ( ( unsigned long ) V_131 ) || ! F_34 ( V_144 ) ;
#endif
F_35 ( & V_130 , V_131 , V_132 , V_140 ) ;
F_36 ( & V_130 ) ;
if ( ! V_130 . V_145 . V_146 )
return V_104 ;
switch ( V_130 . V_145 . V_147 [ 0 ] ) {
case 0xf :
switch ( V_130 . V_145 . V_147 [ 1 ] ) {
case 0x05 :
case 0x34 :
V_129 = V_148 ;
break;
case 0x07 :
case 0x35 :
V_129 = V_100 ;
break;
case 0x80 ... 0x8f :
V_129 = V_110 ;
break;
default:
V_129 = V_134 ;
}
break;
case 0x70 ... 0x7f :
V_129 = V_110 ;
break;
case 0xc2 :
case 0xc3 :
case 0xca :
case 0xcb :
V_129 = V_98 ;
break;
case 0xcf :
V_129 = V_99 ;
break;
case 0xcc ... 0xce :
V_129 = V_149 ;
break;
case 0xe8 :
F_37 ( & V_130 ) ;
if ( V_130 . V_150 . V_151 == 0 ) {
V_129 = V_118 ;
break;
}
case 0x9a :
V_129 = V_114 ;
break;
case 0xe0 ... 0xe3 :
V_129 = V_110 ;
break;
case 0xe9 ... 0xeb :
V_129 = V_152 ;
break;
case 0xff :
F_38 ( & V_130 ) ;
V_135 = ( V_130 . V_153 . V_147 [ 0 ] >> 3 ) & 0x7 ;
switch ( V_135 ) {
case 2 :
case 3 :
V_129 = V_102 ;
break;
case 4 :
case 5 :
V_129 = V_116 ;
break;
}
break;
default:
V_129 = V_134 ;
}
if ( V_137 == V_43 && V_136 == V_92
&& V_129 != V_148 && V_129 != V_149 )
V_129 = V_154 ;
if ( V_129 != V_134 )
V_129 |= V_136 ;
return V_129 ;
}
static void
F_24 ( struct V_2 * V_3 )
{
T_1 V_54 , V_55 ;
int V_42 = V_3 -> V_42 ;
int V_17 , V_155 , type ;
bool V_156 = false ;
if ( ( V_42 & V_157 ) == V_157 )
return;
for ( V_17 = 0 ; V_17 < V_3 -> V_62 . V_63 ; V_17 ++ ) {
V_54 = V_3 -> V_58 [ V_17 ] . V_54 ;
V_55 = V_3 -> V_58 [ V_17 ] . V_55 ;
type = F_29 ( V_54 , V_55 , V_3 -> V_58 [ V_17 ] . abort ) ;
if ( type != V_134 && ( V_42 & V_158 ) ) {
if ( V_3 -> V_58 [ V_17 ] . V_70 )
type |= V_106 ;
else
type |= V_108 ;
}
if ( type == V_134 || ( V_42 & type ) != type ) {
V_3 -> V_58 [ V_17 ] . V_54 = 0 ;
V_156 = true ;
}
}
if ( ! V_156 )
return;
for ( V_17 = 0 ; V_17 < V_3 -> V_62 . V_63 ; ) {
if ( ! V_3 -> V_58 [ V_17 ] . V_54 ) {
V_155 = V_17 ;
while ( ++ V_155 < V_3 -> V_62 . V_63 )
V_3 -> V_58 [ V_155 - 1 ] = V_3 -> V_58 [ V_155 ] ;
V_3 -> V_62 . V_63 -- ;
if ( ! V_3 -> V_58 [ V_17 ] . V_54 )
continue;
}
V_17 ++ ;
}
}
void T_5 F_39 ( void )
{
V_7 . V_18 = 4 ;
V_7 . V_27 = V_159 ;
V_7 . V_19 = V_160 ;
V_7 . V_20 = V_161 ;
F_40 ( L_1 ) ;
}
void T_5 F_41 ( void )
{
V_7 . V_18 = 16 ;
V_7 . V_27 = V_159 ;
V_7 . V_19 = V_162 ;
V_7 . V_20 = V_163 ;
V_7 . V_11 = V_164 ;
V_7 . V_122 = V_165 ;
F_40 ( L_2 ) ;
}
void T_5 F_42 ( void )
{
V_7 . V_18 = 16 ;
V_7 . V_27 = V_159 ;
V_7 . V_19 = V_162 ;
V_7 . V_20 = V_163 ;
V_7 . V_11 = V_164 ;
V_7 . V_122 = V_166 ;
F_40 ( L_2 ) ;
}
void F_43 ( void )
{
V_7 . V_18 = 16 ;
V_7 . V_27 = V_159 ;
V_7 . V_19 = V_162 ;
V_7 . V_20 = V_163 ;
V_7 . V_11 = V_164 ;
V_7 . V_122 = V_167 ;
F_40 ( L_2 ) ;
}
T_5 void F_44 ( void )
{
V_7 . V_18 = 32 ;
V_7 . V_27 = V_159 ;
V_7 . V_19 = V_162 ;
V_7 . V_20 = V_163 ;
V_7 . V_11 = V_164 ;
V_7 . V_122 = V_167 ;
F_40 ( L_3 ) ;
}
void T_5 F_45 ( void )
{
if ( V_168 . V_169 == 28
&& V_168 . V_170 < 10 ) {
F_40 ( L_4 ) ;
return;
}
V_7 . V_18 = 8 ;
V_7 . V_27 = V_159 ;
V_7 . V_19 = V_160 ;
V_7 . V_20 = V_161 ;
F_40 ( L_5 ) ;
}
void F_46 ( void )
{
V_7 . V_18 = 8 ;
V_7 . V_27 = V_159 ;
V_7 . V_19 = V_162 ;
V_7 . V_20 = V_163 ;
V_7 . V_11 = V_164 ;
V_7 . V_122 = V_166 ;
F_40 ( L_5 ) ;
}
