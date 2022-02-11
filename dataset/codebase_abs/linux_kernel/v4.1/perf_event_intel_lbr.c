static void F_1 ( bool V_1 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
T_1 V_4 , V_5 = 0 , V_6 ;
if ( V_3 -> V_7 && ! V_1 ) {
V_5 = V_3 -> V_7 -> V_8 ;
F_3 ( V_9 , V_5 ) ;
}
F_4 ( V_10 , V_4 ) ;
V_6 = V_4 ;
V_4 |= V_11 ;
if ( ! ( V_5 & V_12 ) )
V_4 |= V_13 ;
if ( V_6 != V_4 )
F_3 ( V_10 , V_4 ) ;
}
static void F_5 ( void )
{
T_1 V_4 ;
F_4 ( V_10 , V_4 ) ;
V_4 &= ~ ( V_11 | V_13 ) ;
F_3 ( V_10 , V_4 ) ;
}
static void F_6 ( void )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 . V_16 ; V_14 ++ )
F_3 ( V_15 . V_17 + V_14 , 0 ) ;
}
static void F_7 ( void )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 . V_16 ; V_14 ++ ) {
F_3 ( V_15 . V_17 + V_14 , 0 ) ;
F_3 ( V_15 . V_18 + V_14 , 0 ) ;
}
}
void F_8 ( void )
{
if ( ! V_15 . V_16 )
return;
if ( V_15 . V_19 . V_20 == V_21 )
F_6 () ;
else
F_7 () ;
}
static inline T_1 F_9 ( void )
{
T_1 V_22 ;
F_4 ( V_15 . V_23 , V_22 ) ;
return V_22 ;
}
static void F_10 ( struct V_24 * V_25 )
{
int V_14 ;
unsigned V_26 , V_27 ;
T_1 V_22 ;
if ( V_25 -> V_28 == 0 ||
V_25 -> V_29 == V_30 ) {
F_8 () ;
return;
}
V_27 = V_15 . V_16 - 1 ;
V_22 = F_9 () ;
for ( V_14 = 0 ; V_14 < V_15 . V_16 ; V_14 ++ ) {
V_26 = ( V_22 - V_14 ) & V_27 ;
F_3 ( V_15 . V_17 + V_26 , V_25 -> V_17 [ V_14 ] ) ;
F_3 ( V_15 . V_18 + V_26 , V_25 -> V_18 [ V_14 ] ) ;
}
V_25 -> V_29 = V_30 ;
}
static void F_11 ( struct V_24 * V_25 )
{
int V_14 ;
unsigned V_26 , V_27 ;
T_1 V_22 ;
if ( V_25 -> V_28 == 0 ) {
V_25 -> V_29 = V_30 ;
return;
}
V_27 = V_15 . V_16 - 1 ;
V_22 = F_9 () ;
for ( V_14 = 0 ; V_14 < V_15 . V_16 ; V_14 ++ ) {
V_26 = ( V_22 - V_14 ) & V_27 ;
F_4 ( V_15 . V_17 + V_26 , V_25 -> V_17 [ V_14 ] ) ;
F_4 ( V_15 . V_18 + V_26 , V_25 -> V_18 [ V_14 ] ) ;
}
V_25 -> V_29 = V_31 ;
}
void F_12 ( struct V_32 * V_33 , bool V_34 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
struct V_24 * V_25 ;
if ( ! V_15 . V_16 )
return;
V_25 = V_33 ? V_33 -> V_35 : NULL ;
if ( V_25 ) {
if ( V_34 ) {
F_10 ( V_25 ) ;
V_3 -> V_36 = V_33 ;
} else {
F_11 ( V_25 ) ;
}
return;
}
if ( V_34 ) {
F_8 () ;
V_3 -> V_36 = V_33 ;
}
}
static inline bool F_13 ( unsigned V_37 )
{
return ( V_37 & V_38 ) && ( V_37 & V_39 ) ;
}
void F_14 ( struct V_40 * V_41 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
struct V_24 * V_25 ;
if ( ! V_15 . V_16 )
return;
if ( V_41 -> V_33 -> V_42 && V_3 -> V_36 != V_41 -> V_33 ) {
F_8 () ;
V_3 -> V_36 = V_41 -> V_33 ;
}
V_3 -> V_37 = V_41 -> V_43 . V_44 . V_45 ;
if ( F_13 ( V_3 -> V_37 ) && V_41 -> V_33 &&
V_41 -> V_33 -> V_35 ) {
V_25 = V_41 -> V_33 -> V_35 ;
V_25 -> V_28 ++ ;
}
V_3 -> V_46 ++ ;
F_15 ( V_41 -> V_33 -> V_47 ) ;
}
void F_16 ( struct V_40 * V_41 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
struct V_24 * V_25 ;
if ( ! V_15 . V_16 )
return;
if ( F_13 ( V_3 -> V_37 ) && V_41 -> V_33 &&
V_41 -> V_33 -> V_35 ) {
V_25 = V_41 -> V_33 -> V_35 ;
V_25 -> V_28 -- ;
}
V_3 -> V_46 -- ;
F_17 ( V_3 -> V_46 < 0 ) ;
F_18 ( V_41 -> V_33 -> V_47 ) ;
if ( V_3 -> V_48 && ! V_3 -> V_46 ) {
F_5 () ;
V_3 -> V_36 = NULL ;
}
}
void F_19 ( bool V_1 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
if ( V_3 -> V_46 )
F_1 ( V_1 ) ;
}
void F_20 ( void )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
if ( V_3 -> V_46 )
F_5 () ;
}
static void F_21 ( struct V_2 * V_3 )
{
unsigned long V_27 = V_15 . V_16 - 1 ;
T_1 V_22 = F_9 () ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 . V_16 ; V_14 ++ ) {
unsigned long V_26 = ( V_22 - V_14 ) & V_27 ;
union {
struct {
T_2 V_49 ;
T_2 V_50 ;
};
T_1 V_51 ;
} V_52 ;
F_4 ( V_15 . V_17 + V_26 , V_52 . V_51 ) ;
V_3 -> V_53 [ V_14 ] . V_49 = V_52 . V_49 ;
V_3 -> V_53 [ V_14 ] . V_50 = V_52 . V_50 ;
V_3 -> V_53 [ V_14 ] . V_54 = 0 ;
V_3 -> V_53 [ V_14 ] . V_55 = 0 ;
V_3 -> V_53 [ V_14 ] . V_56 = 0 ;
}
V_3 -> V_57 . V_58 = V_14 ;
}
static void F_22 ( struct V_2 * V_3 )
{
unsigned long V_27 = V_15 . V_16 - 1 ;
int V_20 = V_15 . V_19 . V_20 ;
T_1 V_22 = F_9 () ;
int V_14 ;
int V_59 = 0 ;
for ( V_14 = 0 ; V_14 < V_15 . V_16 ; V_14 ++ ) {
unsigned long V_26 = ( V_22 - V_14 ) & V_27 ;
T_1 V_49 , V_50 , V_60 = 0 , V_61 = 0 , V_62 = 0 , abort = 0 ;
int V_63 = 0 ;
int V_64 = V_65 [ V_20 ] ;
F_4 ( V_15 . V_17 + V_26 , V_49 ) ;
F_4 ( V_15 . V_18 + V_26 , V_50 ) ;
if ( V_64 & V_66 ) {
V_60 = ! ! ( V_49 & V_67 ) ;
V_61 = ! V_60 ;
V_63 = 1 ;
}
if ( V_64 & V_68 ) {
V_62 = ! ! ( V_49 & V_69 ) ;
abort = ! ! ( V_49 & V_70 ) ;
V_63 = 3 ;
}
V_49 = ( T_1 ) ( ( ( ( V_71 ) V_49 ) << V_63 ) >> V_63 ) ;
if ( abort && V_15 . V_72 && V_59 > 0 )
V_59 -- ;
V_3 -> V_53 [ V_59 ] . V_49 = V_49 ;
V_3 -> V_53 [ V_59 ] . V_50 = V_50 ;
V_3 -> V_53 [ V_59 ] . V_54 = V_60 ;
V_3 -> V_53 [ V_59 ] . V_55 = V_61 ;
V_3 -> V_53 [ V_59 ] . V_62 = V_62 ;
V_3 -> V_53 [ V_59 ] . abort = abort ;
V_3 -> V_53 [ V_59 ] . V_56 = 0 ;
V_59 ++ ;
}
V_3 -> V_57 . V_58 = V_59 ;
}
void F_23 ( void )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
if ( ! V_3 -> V_46 )
return;
if ( V_15 . V_19 . V_20 == V_21 )
F_21 ( V_3 ) ;
else
F_22 ( V_3 ) ;
F_24 ( V_3 ) ;
}
static int F_25 ( struct V_40 * V_41 )
{
T_1 V_73 = V_41 -> V_74 . V_75 ;
int V_27 = 0 ;
if ( V_73 & V_76 )
V_27 |= V_38 ;
if ( V_73 & V_77 )
V_27 |= V_78 ;
if ( V_73 & V_79 )
V_27 |= V_80 ;
if ( V_73 & V_81 )
V_27 |= V_82 ;
if ( V_73 & V_83 )
V_27 |= V_84 | V_85 | V_86 ;
if ( V_73 & V_87 )
V_27 |= V_88 ;
if ( V_73 & V_89 )
V_27 |= V_90 ;
if ( V_73 & V_91 )
V_27 |= V_92 ;
if ( V_73 & V_93 )
V_27 |= V_94 ;
if ( V_73 & V_95 )
V_27 |= V_96 ;
if ( V_73 & V_97 ) {
if ( ! F_26 () )
return - V_98 ;
if ( V_27 & ~ ( V_38 | V_78 ) )
return - V_99 ;
V_27 |= V_100 | V_88 | V_84 |
V_39 ;
}
V_41 -> V_43 . V_44 . V_45 = V_27 ;
return 0 ;
}
static int F_27 ( struct V_40 * V_41 )
{
struct V_101 * V_45 ;
T_1 V_73 = V_41 -> V_74 . V_75 ;
T_1 V_27 = 0 , V_102 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_103 ; V_14 ++ ) {
if ( ! ( V_73 & ( 1ULL << V_14 ) ) )
continue;
V_102 = V_15 . V_104 [ V_14 ] ;
if ( V_102 == V_105 )
return - V_98 ;
if ( V_102 != V_106 )
V_27 |= V_102 ;
}
V_45 = & V_41 -> V_43 . V_44 ;
V_45 -> V_107 = V_108 ;
V_45 -> V_8 = V_27 ^ V_15 . V_109 ;
return 0 ;
}
int F_28 ( struct V_40 * V_41 )
{
int V_110 = 0 ;
if ( ! V_15 . V_16 )
return - V_98 ;
V_110 = F_25 ( V_41 ) ;
if ( V_110 )
return V_110 ;
if ( V_15 . V_104 )
V_110 = F_27 ( V_41 ) ;
return V_110 ;
}
static int F_29 ( unsigned long V_49 , unsigned long V_50 , int abort )
{
struct V_111 V_111 ;
void * V_112 ;
int V_113 , V_114 ;
int V_110 = V_115 ;
int V_116 , V_117 , V_118 ;
T_3 V_119 [ V_120 ] ;
int V_121 = 0 ;
V_117 = F_30 ( V_50 ) ? V_78 : V_38 ;
V_118 = F_30 ( V_49 ) ? V_78 : V_38 ;
if ( V_49 == 0 || V_50 == 0 )
return V_115 ;
if ( abort )
return V_90 | V_117 ;
if ( V_118 == V_38 ) {
if ( ! V_122 -> V_123 )
return V_115 ;
V_114 = F_31 ( V_119 , ( void V_124 * ) V_49 ,
V_120 ) ;
V_113 = V_120 - V_114 ;
if ( ! V_113 )
return V_115 ;
V_112 = V_119 ;
} else {
if ( F_32 ( V_49 ) ) {
V_112 = ( void * ) V_49 ;
V_113 = V_120 ;
} else {
return V_115 ;
}
}
#ifdef F_33
V_121 = F_30 ( ( unsigned long ) V_112 ) || ! F_34 ( V_125 ) ;
#endif
F_35 ( & V_111 , V_112 , V_113 , V_121 ) ;
F_36 ( & V_111 ) ;
if ( ! V_111 . V_126 . V_127 )
return V_90 ;
switch ( V_111 . V_126 . V_128 [ 0 ] ) {
case 0xf :
switch ( V_111 . V_126 . V_128 [ 1 ] ) {
case 0x05 :
case 0x34 :
V_110 = V_129 ;
break;
case 0x07 :
case 0x35 :
V_110 = V_86 ;
break;
case 0x80 ... 0x8f :
V_110 = V_96 ;
break;
default:
V_110 = V_115 ;
}
break;
case 0x70 ... 0x7f :
V_110 = V_96 ;
break;
case 0xc2 :
case 0xc3 :
case 0xca :
case 0xcb :
V_110 = V_84 ;
break;
case 0xcf :
V_110 = V_85 ;
break;
case 0xcc ... 0xce :
V_110 = V_130 ;
break;
case 0xe8 :
F_37 ( & V_111 ) ;
if ( V_111 . V_131 . V_132 == 0 ) {
V_110 = V_133 ;
break;
}
case 0x9a :
V_110 = V_100 ;
break;
case 0xe0 ... 0xe3 :
V_110 = V_96 ;
break;
case 0xe9 ... 0xeb :
V_110 = V_134 ;
break;
case 0xff :
F_38 ( & V_111 ) ;
V_116 = ( V_111 . V_135 . V_128 [ 0 ] >> 3 ) & 0x7 ;
switch ( V_116 ) {
case 2 :
case 3 :
V_110 = V_88 ;
break;
case 4 :
case 5 :
V_110 = V_134 ;
break;
}
break;
default:
V_110 = V_115 ;
}
if ( V_118 == V_38 && V_117 == V_78
&& V_110 != V_129 && V_110 != V_130 )
V_110 = V_136 ;
if ( V_110 != V_115 )
V_110 |= V_117 ;
return V_110 ;
}
static void
F_24 ( struct V_2 * V_3 )
{
T_1 V_49 , V_50 ;
int V_37 = V_3 -> V_37 ;
int V_14 , V_137 , type ;
bool V_138 = false ;
if ( ( V_37 & V_139 ) == V_139 )
return;
for ( V_14 = 0 ; V_14 < V_3 -> V_57 . V_58 ; V_14 ++ ) {
V_49 = V_3 -> V_53 [ V_14 ] . V_49 ;
V_50 = V_3 -> V_53 [ V_14 ] . V_50 ;
type = F_29 ( V_49 , V_50 , V_3 -> V_53 [ V_14 ] . abort ) ;
if ( type != V_115 && ( V_37 & V_140 ) ) {
if ( V_3 -> V_53 [ V_14 ] . V_62 )
type |= V_92 ;
else
type |= V_94 ;
}
if ( type == V_115 || ( V_37 & type ) != type ) {
V_3 -> V_53 [ V_14 ] . V_49 = 0 ;
V_138 = true ;
}
}
if ( ! V_138 )
return;
for ( V_14 = 0 ; V_14 < V_3 -> V_57 . V_58 ; ) {
if ( ! V_3 -> V_53 [ V_14 ] . V_49 ) {
V_137 = V_14 ;
while ( ++ V_137 < V_3 -> V_57 . V_58 )
V_3 -> V_53 [ V_137 - 1 ] = V_3 -> V_53 [ V_137 ] ;
V_3 -> V_57 . V_58 -- ;
if ( ! V_3 -> V_53 [ V_14 ] . V_49 )
continue;
}
V_14 ++ ;
}
}
void T_4 F_39 ( void )
{
V_15 . V_16 = 4 ;
V_15 . V_23 = V_141 ;
V_15 . V_17 = V_142 ;
V_15 . V_18 = V_143 ;
F_40 ( L_1 ) ;
}
void T_4 F_41 ( void )
{
V_15 . V_16 = 16 ;
V_15 . V_23 = V_141 ;
V_15 . V_17 = V_144 ;
V_15 . V_18 = V_145 ;
V_15 . V_109 = V_146 ;
V_15 . V_104 = V_147 ;
F_40 ( L_2 ) ;
}
void T_4 F_42 ( void )
{
V_15 . V_16 = 16 ;
V_15 . V_23 = V_141 ;
V_15 . V_17 = V_144 ;
V_15 . V_18 = V_145 ;
V_15 . V_109 = V_146 ;
V_15 . V_104 = V_148 ;
F_40 ( L_2 ) ;
}
void F_43 ( void )
{
V_15 . V_16 = 16 ;
V_15 . V_23 = V_141 ;
V_15 . V_17 = V_144 ;
V_15 . V_18 = V_145 ;
V_15 . V_109 = V_146 ;
V_15 . V_104 = V_149 ;
F_40 ( L_2 ) ;
}
void T_4 F_44 ( void )
{
if ( V_150 . V_151 == 28
&& V_150 . V_152 < 10 ) {
F_40 ( L_3 ) ;
return;
}
V_15 . V_16 = 8 ;
V_15 . V_23 = V_141 ;
V_15 . V_17 = V_142 ;
V_15 . V_18 = V_143 ;
F_40 ( L_4 ) ;
}
