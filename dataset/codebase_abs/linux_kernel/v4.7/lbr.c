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
if ( V_22 == V_80 ) {
V_68 = ! ! ( V_54 & V_81 ) ;
V_69 = ! V_68 ;
V_71 = 1 ;
V_72 = ( ( V_55 >> 48 ) & V_79 ) ;
V_55 = ( T_1 ) ( ( ( ( V_82 ) V_55 ) << 16 ) >> 16 ) ;
}
if ( V_73 & V_83 ) {
V_68 = ! ! ( V_54 & V_81 ) ;
V_69 = ! V_68 ;
V_71 = 1 ;
}
if ( V_73 & V_84 ) {
V_70 = ! ! ( V_54 & V_85 ) ;
abort = ! ! ( V_54 & V_86 ) ;
V_71 = 3 ;
}
V_54 = ( T_1 ) ( ( ( ( V_82 ) V_54 ) << V_71 ) >> V_71 ) ;
if ( abort && V_7 . V_87 && V_65 > 0 )
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
T_1 V_88 = V_46 -> V_89 . V_90 ;
int V_31 = 0 ;
if ( V_88 & V_91 )
V_31 |= V_43 ;
if ( V_88 & V_92 )
V_31 |= V_93 ;
if ( V_88 & V_94 )
V_31 |= V_95 ;
if ( V_88 & V_96 )
V_31 |= V_97 ;
if ( V_88 & V_98 )
V_31 |= V_99 | V_100 | V_101 ;
if ( V_88 & V_102 )
V_31 |= V_103 ;
if ( V_88 & V_104 )
V_31 |= V_105 ;
if ( V_88 & V_106 )
V_31 |= V_107 ;
if ( V_88 & V_108 )
V_31 |= V_109 ;
if ( V_88 & V_110 )
V_31 |= V_111 ;
if ( V_88 & V_112 ) {
if ( ! F_26 () )
return - V_113 ;
if ( V_31 & ~ ( V_43 | V_93 ) )
return - V_114 ;
V_31 |= V_115 | V_103 | V_99 |
V_44 ;
}
if ( V_88 & V_116 )
V_31 |= V_117 ;
if ( V_88 & V_118 )
V_31 |= V_115 | V_119 ;
V_46 -> V_48 . V_49 . V_50 = V_31 ;
return 0 ;
}
static int F_27 ( struct V_45 * V_46 )
{
struct V_120 * V_50 ;
T_1 V_88 = V_46 -> V_89 . V_90 ;
T_1 V_31 = 0 , V_121 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_122 ; V_17 ++ ) {
if ( ! ( V_88 & ( 1ULL << V_17 ) ) )
continue;
V_121 = V_7 . V_123 [ V_17 ] ;
if ( V_121 == V_124 )
return - V_113 ;
if ( V_121 != V_125 )
V_31 |= V_121 ;
}
V_50 = & V_46 -> V_48 . V_49 ;
V_50 -> V_126 = V_127 ;
V_50 -> V_10 = V_31 ^ ( V_7 . V_11 & ~ V_15 ) ;
if ( ( V_88 & V_128 ) &&
( V_88 & V_129 ) &&
( V_7 . V_21 . V_22 == V_23 ) )
V_50 -> V_10 |= V_67 ;
return 0 ;
}
int F_28 ( struct V_45 * V_46 )
{
int V_130 = 0 ;
if ( ! V_7 . V_18 )
return - V_113 ;
V_130 = F_25 ( V_46 ) ;
if ( V_130 )
return V_130 ;
if ( V_7 . V_123 )
V_130 = F_27 ( V_46 ) ;
return V_130 ;
}
static int F_29 ( unsigned long V_54 , unsigned long V_55 , int abort )
{
struct V_131 V_131 ;
void * V_132 ;
int V_133 , V_134 ;
int V_130 = V_135 ;
int V_136 , V_137 , V_138 ;
T_4 V_139 [ V_140 ] ;
int V_141 = 0 ;
V_137 = F_30 ( V_55 ) ? V_93 : V_43 ;
V_138 = F_30 ( V_54 ) ? V_93 : V_43 ;
if ( V_54 == 0 || V_55 == 0 )
return V_135 ;
if ( abort )
return V_105 | V_137 ;
if ( V_138 == V_43 ) {
if ( ! V_142 -> V_143 )
return V_135 ;
V_134 = F_31 ( V_139 , ( void V_144 * ) V_54 ,
V_140 ) ;
V_133 = V_140 - V_134 ;
if ( ! V_133 )
return V_135 ;
V_132 = V_139 ;
} else {
if ( F_32 ( V_54 ) ) {
V_132 = ( void * ) V_54 ;
V_133 = V_140 ;
} else {
return V_135 ;
}
}
#ifdef F_33
V_141 = F_30 ( ( unsigned long ) V_132 ) || ! F_34 ( V_145 ) ;
#endif
F_35 ( & V_131 , V_132 , V_133 , V_141 ) ;
F_36 ( & V_131 ) ;
if ( ! V_131 . V_146 . V_147 )
return V_105 ;
switch ( V_131 . V_146 . V_148 [ 0 ] ) {
case 0xf :
switch ( V_131 . V_146 . V_148 [ 1 ] ) {
case 0x05 :
case 0x34 :
V_130 = V_149 ;
break;
case 0x07 :
case 0x35 :
V_130 = V_101 ;
break;
case 0x80 ... 0x8f :
V_130 = V_111 ;
break;
default:
V_130 = V_135 ;
}
break;
case 0x70 ... 0x7f :
V_130 = V_111 ;
break;
case 0xc2 :
case 0xc3 :
case 0xca :
case 0xcb :
V_130 = V_99 ;
break;
case 0xcf :
V_130 = V_100 ;
break;
case 0xcc ... 0xce :
V_130 = V_150 ;
break;
case 0xe8 :
F_37 ( & V_131 ) ;
if ( V_131 . V_151 . V_152 == 0 ) {
V_130 = V_119 ;
break;
}
case 0x9a :
V_130 = V_115 ;
break;
case 0xe0 ... 0xe3 :
V_130 = V_111 ;
break;
case 0xe9 ... 0xeb :
V_130 = V_153 ;
break;
case 0xff :
F_38 ( & V_131 ) ;
V_136 = ( V_131 . V_154 . V_148 [ 0 ] >> 3 ) & 0x7 ;
switch ( V_136 ) {
case 2 :
case 3 :
V_130 = V_103 ;
break;
case 4 :
case 5 :
V_130 = V_117 ;
break;
}
break;
default:
V_130 = V_135 ;
}
if ( V_138 == V_43 && V_137 == V_93
&& V_130 != V_149 && V_130 != V_150 )
V_130 = V_155 ;
if ( V_130 != V_135 )
V_130 |= V_137 ;
return V_130 ;
}
static void
F_24 ( struct V_2 * V_3 )
{
T_1 V_54 , V_55 ;
int V_42 = V_3 -> V_42 ;
int V_17 , V_156 , type ;
bool V_157 = false ;
if ( ( V_42 & V_158 ) == V_158 )
return;
for ( V_17 = 0 ; V_17 < V_3 -> V_62 . V_63 ; V_17 ++ ) {
V_54 = V_3 -> V_58 [ V_17 ] . V_54 ;
V_55 = V_3 -> V_58 [ V_17 ] . V_55 ;
type = F_29 ( V_54 , V_55 , V_3 -> V_58 [ V_17 ] . abort ) ;
if ( type != V_135 && ( V_42 & V_159 ) ) {
if ( V_3 -> V_58 [ V_17 ] . V_70 )
type |= V_107 ;
else
type |= V_109 ;
}
if ( type == V_135 || ( V_42 & type ) != type ) {
V_3 -> V_58 [ V_17 ] . V_54 = 0 ;
V_157 = true ;
}
}
if ( ! V_157 )
return;
for ( V_17 = 0 ; V_17 < V_3 -> V_62 . V_63 ; ) {
if ( ! V_3 -> V_58 [ V_17 ] . V_54 ) {
V_156 = V_17 ;
while ( ++ V_156 < V_3 -> V_62 . V_63 )
V_3 -> V_58 [ V_156 - 1 ] = V_3 -> V_58 [ V_156 ] ;
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
V_7 . V_27 = V_160 ;
V_7 . V_19 = V_161 ;
V_7 . V_20 = V_162 ;
F_40 ( L_1 ) ;
}
void T_5 F_41 ( void )
{
V_7 . V_18 = 16 ;
V_7 . V_27 = V_160 ;
V_7 . V_19 = V_163 ;
V_7 . V_20 = V_164 ;
V_7 . V_11 = V_165 ;
V_7 . V_123 = V_166 ;
F_40 ( L_2 ) ;
}
void T_5 F_42 ( void )
{
V_7 . V_18 = 16 ;
V_7 . V_27 = V_160 ;
V_7 . V_19 = V_163 ;
V_7 . V_20 = V_164 ;
V_7 . V_11 = V_165 ;
V_7 . V_123 = V_167 ;
F_40 ( L_2 ) ;
}
void F_43 ( void )
{
V_7 . V_18 = 16 ;
V_7 . V_27 = V_160 ;
V_7 . V_19 = V_163 ;
V_7 . V_20 = V_164 ;
V_7 . V_11 = V_165 ;
V_7 . V_123 = V_168 ;
F_40 ( L_2 ) ;
}
T_5 void F_44 ( void )
{
V_7 . V_18 = 32 ;
V_7 . V_27 = V_160 ;
V_7 . V_19 = V_163 ;
V_7 . V_20 = V_164 ;
V_7 . V_11 = V_165 ;
V_7 . V_123 = V_168 ;
F_40 ( L_3 ) ;
}
void T_5 F_45 ( void )
{
if ( V_169 . V_170 == 28
&& V_169 . V_171 < 10 ) {
F_40 ( L_4 ) ;
return;
}
V_7 . V_18 = 8 ;
V_7 . V_27 = V_160 ;
V_7 . V_19 = V_161 ;
V_7 . V_20 = V_162 ;
F_40 ( L_5 ) ;
}
void T_5 F_46 ( void )
{
V_7 . V_18 = 8 ;
V_7 . V_27 = V_160 ;
V_7 . V_19 = V_161 ;
V_7 . V_20 = V_162 ;
V_7 . V_11 = V_165 ;
V_7 . V_123 = V_166 ;
F_40 ( L_5 ) ;
}
void F_47 ( void )
{
V_7 . V_18 = 8 ;
V_7 . V_27 = V_160 ;
V_7 . V_19 = V_163 ;
V_7 . V_20 = V_164 ;
V_7 . V_11 = V_165 ;
V_7 . V_123 = V_167 ;
F_40 ( L_5 ) ;
}
