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
static inline bool F_10 ( void )
{
int V_22 = V_7 . V_21 . V_22 ;
bool V_28 = F_11 ( V_29 ) ||
F_11 ( V_30 ) ;
return ! V_28 && ( V_31 [ V_22 ] & V_32 ) ;
}
inline T_1 F_12 ( T_1 V_33 )
{
if ( F_13 ( & V_34 ) ) {
V_33 |= ( V_35 & V_33 ) << 2 ;
}
return V_33 ;
}
static T_1 F_14 ( T_1 V_33 )
{
if ( F_13 ( & V_34 ) ) {
V_33 &= ~ ( V_36 | V_37 ) ;
}
return V_33 ;
}
static inline void F_15 ( unsigned int V_38 , T_1 V_33 )
{
V_33 = F_12 ( V_33 ) ;
F_3 ( V_7 . V_19 + V_38 , V_33 ) ;
}
static inline void F_16 ( unsigned int V_38 , T_1 V_33 )
{
F_3 ( V_7 . V_20 + V_38 , V_33 ) ;
}
static inline T_1 F_17 ( unsigned int V_38 )
{
T_1 V_33 ;
F_4 ( V_7 . V_19 + V_38 , V_33 ) ;
return F_14 ( V_33 ) ;
}
static inline T_1 F_18 ( unsigned int V_38 )
{
T_1 V_33 ;
F_4 ( V_7 . V_20 + V_38 , V_33 ) ;
return V_33 ;
}
static void F_19 ( struct V_39 * V_40 )
{
int V_17 ;
unsigned V_41 , V_42 ;
T_1 V_26 ;
if ( V_40 -> V_43 == 0 ||
V_40 -> V_44 == V_45 ) {
F_8 () ;
return;
}
V_42 = V_7 . V_18 - 1 ;
V_26 = V_40 -> V_26 ;
for ( V_17 = 0 ; V_17 < V_26 ; V_17 ++ ) {
V_41 = ( V_26 - V_17 ) & V_42 ;
F_15 ( V_41 , V_40 -> V_19 [ V_17 ] ) ;
F_16 ( V_41 , V_40 -> V_20 [ V_17 ] ) ;
if ( V_7 . V_21 . V_22 == V_23 )
F_3 ( V_24 + V_41 , V_40 -> V_46 [ V_17 ] ) ;
}
F_3 ( V_7 . V_27 , V_26 ) ;
V_40 -> V_44 = V_45 ;
}
static void F_20 ( struct V_39 * V_40 )
{
unsigned V_41 , V_42 ;
T_1 V_26 ;
int V_17 ;
if ( V_40 -> V_43 == 0 ) {
V_40 -> V_44 = V_45 ;
return;
}
V_42 = V_7 . V_18 - 1 ;
V_26 = F_9 () ;
for ( V_17 = 0 ; V_17 < V_26 ; V_17 ++ ) {
V_41 = ( V_26 - V_17 ) & V_42 ;
V_40 -> V_19 [ V_17 ] = F_17 ( V_41 ) ;
V_40 -> V_20 [ V_17 ] = F_18 ( V_41 ) ;
if ( V_7 . V_21 . V_22 == V_23 )
F_4 ( V_24 + V_41 , V_40 -> V_46 [ V_17 ] ) ;
}
V_40 -> V_26 = V_26 ;
V_40 -> V_44 = V_47 ;
}
void F_21 ( struct V_48 * V_49 , bool V_50 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
struct V_39 * V_40 ;
if ( ! V_3 -> V_51 )
return;
V_40 = V_49 ? V_49 -> V_52 : NULL ;
if ( V_40 ) {
if ( V_50 )
F_19 ( V_40 ) ;
else
F_20 ( V_40 ) ;
return;
}
if ( V_50 )
F_8 () ;
}
static inline bool F_22 ( unsigned V_53 )
{
return ( V_53 & V_54 ) && ( V_53 & V_55 ) ;
}
void F_23 ( struct V_56 * V_57 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
struct V_39 * V_40 ;
if ( ! V_7 . V_18 )
return;
V_3 -> V_53 = V_57 -> V_58 . V_59 . V_60 ;
if ( F_22 ( V_3 -> V_53 ) && V_57 -> V_49 -> V_52 ) {
V_40 = V_57 -> V_49 -> V_52 ;
V_40 -> V_43 ++ ;
}
F_24 ( V_57 -> V_49 -> V_61 ) ;
if ( ! V_3 -> V_51 ++ && ! V_57 -> V_62 )
F_8 () ;
}
void F_25 ( struct V_56 * V_57 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
struct V_39 * V_40 ;
if ( ! V_7 . V_18 )
return;
if ( F_22 ( V_3 -> V_53 ) &&
V_57 -> V_49 -> V_52 ) {
V_40 = V_57 -> V_49 -> V_52 ;
V_40 -> V_43 -- ;
}
V_3 -> V_51 -- ;
F_26 ( V_3 -> V_51 < 0 ) ;
F_27 ( V_57 -> V_49 -> V_61 ) ;
}
void F_28 ( bool V_1 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
if ( V_3 -> V_51 )
F_1 ( V_1 ) ;
}
void F_29 ( void )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
if ( V_3 -> V_51 )
F_5 () ;
}
static void F_30 ( struct V_2 * V_3 )
{
unsigned long V_42 = V_7 . V_18 - 1 ;
T_1 V_26 = F_9 () ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_7 . V_18 ; V_17 ++ ) {
unsigned long V_41 = ( V_26 - V_17 ) & V_42 ;
union {
struct {
T_2 V_63 ;
T_2 V_64 ;
};
T_1 V_65 ;
} V_66 ;
F_4 ( V_7 . V_19 + V_41 , V_66 . V_65 ) ;
V_3 -> V_67 [ V_17 ] . V_63 = V_66 . V_63 ;
V_3 -> V_67 [ V_17 ] . V_64 = V_66 . V_64 ;
V_3 -> V_67 [ V_17 ] . V_68 = 0 ;
V_3 -> V_67 [ V_17 ] . V_69 = 0 ;
V_3 -> V_67 [ V_17 ] . V_70 = 0 ;
V_3 -> V_67 [ V_17 ] . abort = 0 ;
V_3 -> V_67 [ V_17 ] . V_71 = 0 ;
V_3 -> V_67 [ V_17 ] . V_72 = 0 ;
}
V_3 -> V_73 . V_74 = V_17 ;
}
static void F_31 ( struct V_2 * V_3 )
{
bool V_75 = false ;
unsigned long V_42 = V_7 . V_18 - 1 ;
int V_22 = V_7 . V_21 . V_22 ;
T_1 V_26 = F_9 () ;
int V_17 ;
int V_76 = 0 ;
int V_77 = V_7 . V_18 ;
if ( V_3 -> V_9 ) {
V_75 = ! ( V_3 -> V_9 -> V_10 & V_78 ) ;
if ( V_3 -> V_9 -> V_10 & V_15 )
V_77 = V_26 ;
}
for ( V_17 = 0 ; V_17 < V_77 ; V_17 ++ ) {
unsigned long V_41 = ( V_26 - V_17 ) & V_42 ;
T_1 V_63 , V_64 , V_79 = 0 , V_80 = 0 , V_70 = 0 , abort = 0 ;
int V_81 = 0 ;
T_3 V_71 = 0 ;
int V_82 = V_31 [ V_22 ] ;
V_63 = F_17 ( V_41 ) ;
V_64 = F_18 ( V_41 ) ;
if ( V_22 == V_23 && V_75 ) {
T_1 V_83 ;
F_4 ( V_24 + V_41 , V_83 ) ;
V_79 = ! ! ( V_83 & V_84 ) ;
V_80 = ! V_79 ;
V_70 = ! ! ( V_83 & V_85 ) ;
abort = ! ! ( V_83 & V_86 ) ;
V_71 = ( V_83 & V_87 ) ;
}
if ( V_22 == V_88 ) {
V_79 = ! ! ( V_63 & V_89 ) ;
V_80 = ! V_79 ;
V_81 = 1 ;
V_71 = ( ( V_64 >> 48 ) & V_87 ) ;
V_64 = ( T_1 ) ( ( ( ( V_90 ) V_64 ) << 16 ) >> 16 ) ;
}
if ( V_82 & V_91 ) {
V_79 = ! ! ( V_63 & V_89 ) ;
V_80 = ! V_79 ;
V_81 = 1 ;
}
if ( V_82 & V_32 ) {
V_70 = ! ! ( V_63 & V_36 ) ;
abort = ! ! ( V_63 & V_37 ) ;
V_81 = 3 ;
}
V_63 = ( T_1 ) ( ( ( ( V_90 ) V_63 ) << V_81 ) >> V_81 ) ;
if ( abort && V_7 . V_92 && V_76 > 0 )
V_76 -- ;
V_3 -> V_67 [ V_76 ] . V_63 = V_63 ;
V_3 -> V_67 [ V_76 ] . V_64 = V_64 ;
V_3 -> V_67 [ V_76 ] . V_68 = V_79 ;
V_3 -> V_67 [ V_76 ] . V_69 = V_80 ;
V_3 -> V_67 [ V_76 ] . V_70 = V_70 ;
V_3 -> V_67 [ V_76 ] . abort = abort ;
V_3 -> V_67 [ V_76 ] . V_71 = V_71 ;
V_3 -> V_67 [ V_76 ] . V_72 = 0 ;
V_76 ++ ;
}
V_3 -> V_73 . V_74 = V_76 ;
}
void F_32 ( void )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
if ( ! V_3 -> V_51 )
return;
if ( V_7 . V_21 . V_22 == V_25 )
F_30 ( V_3 ) ;
else
F_31 ( V_3 ) ;
F_33 ( V_3 ) ;
}
static int F_34 ( struct V_56 * V_57 )
{
T_1 V_93 = V_57 -> V_94 . V_95 ;
int V_42 = 0 ;
if ( V_93 & V_96 )
V_42 |= V_54 ;
if ( V_93 & V_97 )
V_42 |= V_98 ;
if ( V_93 & V_99 )
V_42 |= V_100 ;
if ( V_93 & V_101 )
V_42 |= V_102 ;
if ( V_93 & V_103 )
V_42 |= V_104 | V_105 | V_106 ;
if ( V_93 & V_107 )
V_42 |= V_108 ;
if ( V_93 & V_109 )
V_42 |= V_110 ;
if ( V_93 & V_111 )
V_42 |= V_112 ;
if ( V_93 & V_113 )
V_42 |= V_114 ;
if ( V_93 & V_115 )
V_42 |= V_116 ;
if ( V_93 & V_117 ) {
if ( ! F_35 () )
return - V_118 ;
if ( V_42 & ~ ( V_54 | V_98 ) )
return - V_119 ;
V_42 |= V_120 | V_108 | V_104 |
V_55 ;
}
if ( V_93 & V_121 )
V_42 |= V_122 ;
if ( V_93 & V_123 )
V_42 |= V_120 | V_124 ;
V_57 -> V_58 . V_59 . V_60 = V_42 ;
return 0 ;
}
static int F_36 ( struct V_56 * V_57 )
{
struct V_125 * V_60 ;
T_1 V_93 = V_57 -> V_94 . V_95 ;
T_1 V_42 = 0 , V_126 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_127 ; V_17 ++ ) {
if ( ! ( V_93 & ( 1ULL << V_17 ) ) )
continue;
V_126 = V_7 . V_128 [ V_17 ] ;
if ( V_126 == V_129 )
return - V_118 ;
if ( V_126 != V_130 )
V_42 |= V_126 ;
}
V_60 = & V_57 -> V_58 . V_59 ;
V_60 -> V_38 = V_131 ;
V_60 -> V_10 = V_42 ^ ( V_7 . V_11 & ~ V_15 ) ;
if ( ( V_93 & V_132 ) &&
( V_93 & V_133 ) &&
( V_7 . V_21 . V_22 == V_23 ) )
V_60 -> V_10 |= V_78 ;
return 0 ;
}
int F_37 ( struct V_56 * V_57 )
{
int V_134 = 0 ;
if ( ! V_7 . V_18 )
return - V_118 ;
V_134 = F_34 ( V_57 ) ;
if ( V_134 )
return V_134 ;
if ( V_7 . V_128 )
V_134 = F_36 ( V_57 ) ;
return V_134 ;
}
static int F_38 ( unsigned long V_63 , unsigned long V_64 , int abort )
{
struct V_135 V_135 ;
void * V_136 ;
int V_137 , V_138 ;
int V_134 = V_139 ;
int V_140 , V_141 , V_142 ;
T_4 V_143 [ V_144 ] ;
int V_145 = 0 ;
V_141 = F_39 ( V_64 ) ? V_98 : V_54 ;
V_142 = F_39 ( V_63 ) ? V_98 : V_54 ;
if ( V_63 == 0 || V_64 == 0 )
return V_139 ;
if ( abort )
return V_110 | V_141 ;
if ( V_142 == V_54 ) {
if ( ! V_146 -> V_147 )
return V_139 ;
V_138 = F_40 ( V_143 , ( void V_148 * ) V_63 ,
V_144 ) ;
V_137 = V_144 - V_138 ;
if ( ! V_137 )
return V_139 ;
V_136 = V_143 ;
} else {
if ( F_41 ( V_63 ) ) {
V_136 = ( void * ) V_63 ;
V_137 = V_144 ;
} else {
return V_139 ;
}
}
#ifdef F_42
V_145 = F_39 ( ( unsigned long ) V_136 ) || ! F_43 ( V_149 ) ;
#endif
F_44 ( & V_135 , V_136 , V_137 , V_145 ) ;
F_45 ( & V_135 ) ;
if ( ! V_135 . V_150 . V_151 )
return V_110 ;
switch ( V_135 . V_150 . V_152 [ 0 ] ) {
case 0xf :
switch ( V_135 . V_150 . V_152 [ 1 ] ) {
case 0x05 :
case 0x34 :
V_134 = V_153 ;
break;
case 0x07 :
case 0x35 :
V_134 = V_106 ;
break;
case 0x80 ... 0x8f :
V_134 = V_116 ;
break;
default:
V_134 = V_139 ;
}
break;
case 0x70 ... 0x7f :
V_134 = V_116 ;
break;
case 0xc2 :
case 0xc3 :
case 0xca :
case 0xcb :
V_134 = V_104 ;
break;
case 0xcf :
V_134 = V_105 ;
break;
case 0xcc ... 0xce :
V_134 = V_154 ;
break;
case 0xe8 :
F_46 ( & V_135 ) ;
if ( V_135 . V_155 . V_156 == 0 ) {
V_134 = V_124 ;
break;
}
case 0x9a :
V_134 = V_120 ;
break;
case 0xe0 ... 0xe3 :
V_134 = V_116 ;
break;
case 0xe9 ... 0xeb :
V_134 = V_157 ;
break;
case 0xff :
F_47 ( & V_135 ) ;
V_140 = ( V_135 . V_158 . V_152 [ 0 ] >> 3 ) & 0x7 ;
switch ( V_140 ) {
case 2 :
case 3 :
V_134 = V_108 ;
break;
case 4 :
case 5 :
V_134 = V_122 ;
break;
}
break;
default:
V_134 = V_139 ;
}
if ( V_142 == V_54 && V_141 == V_98
&& V_134 != V_153 && V_134 != V_154 )
V_134 = V_159 ;
if ( V_134 != V_139 )
V_134 |= V_141 ;
return V_134 ;
}
static void
F_33 ( struct V_2 * V_3 )
{
T_1 V_63 , V_64 ;
int V_53 = V_3 -> V_53 ;
int V_17 , V_160 , type ;
bool V_161 = false ;
if ( ( V_53 & V_162 ) == V_162 )
return;
for ( V_17 = 0 ; V_17 < V_3 -> V_73 . V_74 ; V_17 ++ ) {
V_63 = V_3 -> V_67 [ V_17 ] . V_63 ;
V_64 = V_3 -> V_67 [ V_17 ] . V_64 ;
type = F_38 ( V_63 , V_64 , V_3 -> V_67 [ V_17 ] . abort ) ;
if ( type != V_139 && ( V_53 & V_163 ) ) {
if ( V_3 -> V_67 [ V_17 ] . V_70 )
type |= V_112 ;
else
type |= V_114 ;
}
if ( type == V_139 || ( V_53 & type ) != type ) {
V_3 -> V_67 [ V_17 ] . V_63 = 0 ;
V_161 = true ;
}
}
if ( ! V_161 )
return;
for ( V_17 = 0 ; V_17 < V_3 -> V_73 . V_74 ; ) {
if ( ! V_3 -> V_67 [ V_17 ] . V_63 ) {
V_160 = V_17 ;
while ( ++ V_160 < V_3 -> V_73 . V_74 )
V_3 -> V_67 [ V_160 - 1 ] = V_3 -> V_67 [ V_160 ] ;
V_3 -> V_73 . V_74 -- ;
if ( ! V_3 -> V_67 [ V_17 ] . V_63 )
continue;
}
V_17 ++ ;
}
}
void T_5 F_48 ( void )
{
V_7 . V_18 = 4 ;
V_7 . V_27 = V_164 ;
V_7 . V_19 = V_165 ;
V_7 . V_20 = V_166 ;
}
void T_5 F_49 ( void )
{
V_7 . V_18 = 16 ;
V_7 . V_27 = V_164 ;
V_7 . V_19 = V_167 ;
V_7 . V_20 = V_168 ;
V_7 . V_11 = V_169 ;
V_7 . V_128 = V_170 ;
}
void T_5 F_50 ( void )
{
V_7 . V_18 = 16 ;
V_7 . V_27 = V_164 ;
V_7 . V_19 = V_167 ;
V_7 . V_20 = V_168 ;
V_7 . V_11 = V_169 ;
V_7 . V_128 = V_171 ;
}
void F_51 ( void )
{
V_7 . V_18 = 16 ;
V_7 . V_27 = V_164 ;
V_7 . V_19 = V_167 ;
V_7 . V_20 = V_168 ;
V_7 . V_11 = V_169 ;
V_7 . V_128 = V_172 ;
if ( F_10 () )
F_52 ( & V_34 ) ;
}
T_5 void F_53 ( void )
{
V_7 . V_18 = 32 ;
V_7 . V_27 = V_164 ;
V_7 . V_19 = V_167 ;
V_7 . V_20 = V_168 ;
V_7 . V_11 = V_169 ;
V_7 . V_128 = V_172 ;
}
void T_5 F_54 ( void )
{
if ( V_173 . V_174 == 28
&& V_173 . V_175 < 10 ) {
F_55 ( L_1 ) ;
return;
}
V_7 . V_18 = 8 ;
V_7 . V_27 = V_164 ;
V_7 . V_19 = V_165 ;
V_7 . V_20 = V_166 ;
}
void T_5 F_56 ( void )
{
V_7 . V_18 = 8 ;
V_7 . V_27 = V_164 ;
V_7 . V_19 = V_165 ;
V_7 . V_20 = V_166 ;
V_7 . V_11 = V_169 ;
V_7 . V_128 = V_170 ;
F_55 ( L_2 ) ;
}
void F_57 ( void )
{
V_7 . V_18 = 8 ;
V_7 . V_27 = V_164 ;
V_7 . V_19 = V_167 ;
V_7 . V_20 = V_168 ;
V_7 . V_11 = V_169 ;
V_7 . V_128 = V_171 ;
}
