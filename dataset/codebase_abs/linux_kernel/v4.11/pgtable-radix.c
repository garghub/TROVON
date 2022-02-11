static int F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
unsigned long V_4 = V_1 | V_3 | V_5 ;
V_6 -> V_4 = F_2 ( V_4 ) ;
return 0 ;
}
static T_1 void * F_3 ( unsigned long V_7 )
{
void * V_8 ;
V_8 = F_4 ( F_5 ( V_7 , V_7 , V_9 ) ) ;
memset ( V_8 , 0 , V_7 ) ;
return V_8 ;
}
int F_6 ( unsigned long V_10 , unsigned long V_11 ,
T_2 V_12 ,
unsigned int V_13 )
{
T_3 * V_14 ;
T_4 * V_15 ;
T_5 * V_16 ;
T_6 * V_17 ;
F_7 ( V_18 > V_19 ) ;
if ( F_8 () ) {
V_14 = F_9 ( V_10 ) ;
V_15 = F_10 ( & V_20 , V_14 , V_10 ) ;
if ( ! V_15 )
return - V_21 ;
if ( V_13 == V_22 ) {
V_17 = ( T_6 * ) V_15 ;
goto V_23;
}
V_16 = F_11 ( & V_20 , V_15 , V_10 ) ;
if ( ! V_16 )
return - V_21 ;
if ( V_13 == V_24 ) {
V_17 = F_12 ( V_16 ) ;
goto V_23;
}
V_17 = F_13 ( V_16 , V_10 ) ;
if ( ! V_17 )
return - V_21 ;
} else {
V_14 = F_9 ( V_10 ) ;
if ( F_14 ( * V_14 ) ) {
V_15 = F_3 ( V_25 ) ;
F_15 ( V_15 == NULL ) ;
F_16 ( & V_20 , V_14 , V_15 ) ;
}
V_15 = F_17 ( V_14 , V_10 ) ;
if ( V_13 == V_22 ) {
V_17 = ( T_6 * ) V_15 ;
goto V_23;
}
if ( F_18 ( * V_15 ) ) {
V_16 = F_3 ( V_26 ) ;
F_15 ( V_16 == NULL ) ;
F_19 ( & V_20 , V_15 , V_16 ) ;
}
V_16 = F_20 ( V_15 , V_10 ) ;
if ( V_13 == V_24 ) {
V_17 = F_12 ( V_16 ) ;
goto V_23;
}
if ( ! F_21 ( * V_16 ) ) {
V_17 = F_3 ( V_27 ) ;
F_15 ( V_17 == NULL ) ;
F_22 ( & V_20 , V_16 , V_17 ) ;
}
V_17 = F_23 ( V_16 , V_10 ) ;
}
V_23:
F_24 ( & V_20 , V_10 , V_17 , F_25 ( V_11 >> V_28 , V_12 ) ) ;
F_26 () ;
return 0 ;
}
static inline void T_7 F_27 ( unsigned long V_29 ,
unsigned long V_30 ,
unsigned long V_7 )
{
if ( V_30 <= V_29 )
return;
F_28 ( L_1 , V_29 , V_30 , V_7 ) ;
}
static int T_7 F_29 ( unsigned long V_29 ,
unsigned long V_30 )
{
unsigned long V_31 , V_32 = 0 ;
V_29 = F_30 ( V_29 , V_27 ) ;
for ( V_31 = V_29 ; V_31 < V_30 ; V_31 += V_32 ) {
unsigned long V_33 , V_34 ;
int V_35 ;
V_33 = V_30 - V_31 ;
V_34 = V_32 ;
if ( F_31 ( V_31 , V_22 ) && V_33 >= V_22 &&
V_36 [ V_37 ] . V_38 )
V_32 = V_22 ;
else if ( F_31 ( V_31 , V_24 ) && V_33 >= V_24 &&
V_36 [ V_39 ] . V_38 )
V_32 = V_24 ;
else
V_32 = V_27 ;
if ( V_32 != V_34 ) {
F_27 ( V_29 , V_31 , V_34 ) ;
V_29 = V_31 ;
}
V_35 = F_6 ( ( unsigned long ) F_4 ( V_31 ) , V_31 ,
V_40 , V_32 ) ;
if ( V_35 )
return V_35 ;
}
F_27 ( V_29 , V_31 , V_32 ) ;
return 0 ;
}
static void T_8 F_32 ( void )
{
unsigned long V_41 ;
struct V_42 * V_43 ;
V_44 = 0 ;
F_33 (memory, reg)
F_34 ( F_29 ( V_43 -> V_1 ,
V_43 -> V_1 + V_43 -> V_7 ) ) ;
F_35 ( ( V_45 > 36 ) , L_2 ) ;
V_46 = F_3 ( 1UL << V_45 ) ;
V_41 = F_36 () ;
V_46 -> V_47 = F_2 ( V_41 | F_37 ( V_20 . V_48 ) | V_49 ) ;
F_38 ( F_37 ( V_46 ) , 0 , V_45 - 12 ) ;
F_28 ( L_3 , V_46 , V_20 . V_48 ) ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE_5(%0,%1,2,1,1) : :
"r" (TLBIEL_INVAL_SET_LPID), "r" (0));
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
}
static void T_8 F_39 ( void )
{
unsigned long V_41 , V_50 ;
F_40 () ;
V_41 = F_36 () ;
V_50 = V_41 | F_37 ( V_20 . V_48 ) | V_49 | V_51 ;
F_41 ( 0 , V_50 , 0 ) ;
F_28 ( L_4 ) ;
F_28 ( L_5 , V_6 ) ;
}
void T_8 F_42 ( void )
{
F_38 = F_1 ;
}
static int T_8 F_43 ( unsigned int V_38 )
{
int V_52 = - 1 ;
switch ( V_38 ) {
case 0xc :
V_52 = V_53 ;
break;
case 0x10 :
V_52 = V_54 ;
break;
case 0x15 :
V_52 = V_39 ;
break;
case 0x1e :
V_52 = V_37 ;
break;
}
return V_52 ;
}
static int T_8 F_44 ( unsigned long V_55 ,
const char * V_56 , int V_57 ,
void * V_58 )
{
int V_7 = 0 ;
int V_38 , V_52 ;
unsigned int V_59 ;
const T_9 * V_60 ;
const char * type = F_45 ( V_55 , L_6 , NULL ) ;
if ( type == NULL || strcmp ( type , L_7 ) != 0 )
return 0 ;
V_60 = F_45 ( V_55 , L_8 , & V_7 ) ;
if ( ! V_60 )
return 0 ;
F_28 ( L_9 ) ;
for (; V_7 >= 4 ; V_7 -= 4 , ++ V_60 ) {
struct V_61 * V_62 ;
V_38 = F_46 ( V_60 [ 0 ] ) & ~ ( 0xe << 28 ) ;
V_59 = F_46 ( V_60 [ 0 ] ) >> 29 ;
F_28 ( L_10 , V_38 , V_59 ) ;
V_52 = F_43 ( V_38 ) ;
if ( V_52 < 0 )
continue;
V_62 = & V_36 [ V_52 ] ;
V_62 -> V_38 = V_38 ;
V_62 -> V_59 = V_59 ;
}
V_63 -> V_64 &= ~ V_65 ;
return 1 ;
}
void T_8 F_47 ( void )
{
int V_35 ;
V_35 = F_48 ( F_44 , NULL ) ;
if ( V_35 != 0 )
goto V_66;
V_36 [ V_53 ] . V_38 = 12 ;
V_36 [ V_53 ] . V_59 = 0x0 ;
V_36 [ V_54 ] . V_38 = 16 ;
V_36 [ V_54 ] . V_59 = 0x5 ;
V_66:
#ifdef F_49
if ( V_36 [ V_39 ] . V_38 ) {
V_67 = V_39 ;
}
#endif
return;
}
static void F_50 ( void )
{
unsigned long V_68 ;
unsigned long V_69 = 3UL << F_51 ( 53 ) ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(1), "i"(0), "i"(2), "r"(0) : "memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(1), "i"(1), "i"(2), "r"(0) : "memory");
asm volatile("eieio; tlbsync; ptesync; isync; slbia": : :"memory");
V_68 = F_52 ( V_70 ) ;
V_68 |= V_71 ;
F_53 ( V_70 , V_68 ) ;
asm volatile("isync": : :"memory");
while ( ! ( F_52 ( V_70 ) & V_71 ) )
F_54 () ;
}
static void F_55 ( void )
{
F_53 ( V_72 , ( 3ul << 62 ) ) ;
}
static void F_56 ( void )
{
unsigned long V_73 ;
if ( F_57 ( V_74 ) )
V_73 = 0 ;
else
V_73 = ( 1ul << 62 ) ;
F_53 ( V_75 , V_73 ) ;
}
void T_8 F_58 ( void )
{
unsigned long V_76 ;
#ifdef F_59
V_77 = V_54 ;
#else
V_77 = V_53 ;
#endif
#ifdef F_49
V_67 = V_77 ;
#endif
V_78 = V_79 ;
V_80 = V_81 ;
V_82 = V_83 ;
V_84 = V_49 ;
V_85 = V_81 ;
V_86 = V_87 ;
V_88 = V_89 ;
V_90 = V_91 ;
V_92 = V_93 ;
V_94 = V_95 ;
V_96 = V_97 ;
V_98 = V_99 ;
V_100 = V_101 ;
V_102 = V_103 ;
V_104 = V_105 ;
V_106 = V_107 ;
V_108 = (struct V_109 * ) V_110 ;
V_111 = V_112 ;
#ifdef F_60
V_113 = V_114 ;
#endif
V_115 = V_116 ;
V_117 = V_118 ;
if ( ! F_61 ( V_119 ) ) {
F_42 () ;
if ( F_57 ( V_74 ) )
F_50 () ;
V_76 = F_52 ( V_120 ) ;
F_53 ( V_120 , V_76 | V_121 | V_122 ) ;
F_39 () ;
F_55 () ;
} else {
F_62 () ;
}
F_63 ( V_9 ) ;
F_56 () ;
F_32 () ;
}
void F_64 ( void )
{
unsigned long V_76 ;
if ( ! F_61 ( V_119 ) ) {
if ( F_57 ( V_74 ) )
F_50 () ;
V_76 = F_52 ( V_120 ) ;
F_53 ( V_120 , V_76 | V_121 | V_122 ) ;
F_53 ( V_123 ,
F_37 ( V_6 ) | ( V_124 - 12 ) ) ;
F_55 () ;
}
F_56 () ;
}
void F_65 ( void )
{
unsigned long V_76 ;
if ( ! F_61 ( V_119 ) ) {
V_76 = F_52 ( V_120 ) ;
F_53 ( V_120 , V_76 & ~ V_121 ) ;
F_53 ( V_123 , 0 ) ;
F_66 ( 0 ) ;
F_67 () ;
}
}
void F_68 ( T_10 V_125 ,
T_10 V_126 )
{
F_15 ( V_125 != 0 ) ;
V_127 = F_69 ( V_128 , V_126 , 0x40000000 ) ;
F_63 ( V_125 + V_126 ) ;
}
static void F_70 ( T_6 * V_129 , T_5 * V_130 )
{
T_6 * V_131 ;
int V_132 ;
for ( V_132 = 0 ; V_132 < V_133 ; V_132 ++ ) {
V_131 = V_129 + V_132 ;
if ( ! F_71 ( * V_131 ) )
return;
}
F_72 ( & V_20 , V_129 ) ;
F_73 ( V_130 ) ;
}
static void F_74 ( T_5 * V_134 , T_4 * V_135 )
{
T_5 * V_130 ;
int V_132 ;
for ( V_132 = 0 ; V_132 < V_136 ; V_132 ++ ) {
V_130 = V_134 + V_132 ;
if ( ! F_75 ( * V_130 ) )
return;
}
F_76 ( & V_20 , V_134 ) ;
F_77 ( V_135 ) ;
}
static void F_78 ( T_6 * V_129 , unsigned long V_31 ,
unsigned long V_30 )
{
unsigned long V_137 ;
T_6 * V_131 ;
V_131 = V_129 + F_79 ( V_31 ) ;
for (; V_31 < V_30 ; V_31 = V_137 , V_131 ++ ) {
V_137 = ( V_31 + V_27 ) & V_138 ;
if ( V_137 > V_30 )
V_137 = V_30 ;
if ( ! F_80 ( * V_131 ) )
continue;
if ( ! F_81 ( V_31 ) || ! F_81 ( V_137 ) ) {
F_82 ( 1 , L_11 , V_139 ) ;
continue;
}
F_83 ( & V_20 , V_31 , V_131 ) ;
}
}
static void F_84 ( T_5 * V_134 , unsigned long V_31 ,
unsigned long V_30 )
{
unsigned long V_137 ;
T_6 * V_140 ;
T_5 * V_130 ;
V_130 = V_134 + F_85 ( V_31 ) ;
for (; V_31 < V_30 ; V_31 = V_137 , V_130 ++ ) {
V_137 = F_86 ( V_31 , V_30 ) ;
if ( ! F_21 ( * V_130 ) )
continue;
if ( F_87 ( * V_130 ) ) {
if ( ! F_31 ( V_31 , V_24 ) ||
! F_31 ( V_137 , V_24 ) ) {
F_82 ( 1 , L_11 , V_139 ) ;
continue;
}
F_83 ( & V_20 , V_31 , ( T_6 * ) V_130 ) ;
continue;
}
V_140 = ( T_6 * ) F_88 ( * V_130 ) ;
F_78 ( V_140 , V_31 , V_137 ) ;
F_70 ( V_140 , V_130 ) ;
}
}
static void F_89 ( T_4 * V_141 , unsigned long V_31 ,
unsigned long V_30 )
{
unsigned long V_137 ;
T_5 * V_142 ;
T_4 * V_135 ;
V_135 = V_141 + F_90 ( V_31 ) ;
for (; V_31 < V_30 ; V_31 = V_137 , V_135 ++ ) {
V_137 = F_91 ( V_31 , V_30 ) ;
if ( ! F_92 ( * V_135 ) )
continue;
if ( F_93 ( * V_135 ) ) {
if ( ! F_31 ( V_31 , V_22 ) ||
! F_31 ( V_137 , V_22 ) ) {
F_82 ( 1 , L_11 , V_139 ) ;
continue;
}
F_83 ( & V_20 , V_31 , ( T_6 * ) V_135 ) ;
continue;
}
V_142 = ( T_5 * ) F_94 ( * V_135 ) ;
F_84 ( V_142 , V_31 , V_137 ) ;
F_74 ( V_142 , V_135 ) ;
}
}
static void F_95 ( unsigned long V_29 , unsigned long V_30 )
{
unsigned long V_31 , V_137 ;
T_4 * V_143 ;
T_3 * V_48 ;
F_96 ( & V_20 . V_144 ) ;
for ( V_31 = V_29 ; V_31 < V_30 ; V_31 = V_137 ) {
V_137 = F_97 ( V_31 , V_30 ) ;
V_48 = F_9 ( V_31 ) ;
if ( ! F_98 ( * V_48 ) )
continue;
if ( F_99 ( * V_48 ) ) {
if ( ! F_31 ( V_31 , V_145 ) ||
! F_31 ( V_137 , V_145 ) ) {
F_82 ( 1 , L_11 , V_139 ) ;
continue;
}
F_83 ( & V_20 , V_31 , ( T_6 * ) V_48 ) ;
continue;
}
V_143 = ( T_4 * ) F_100 ( * V_48 ) ;
F_89 ( V_143 , V_31 , V_137 ) ;
}
F_101 ( & V_20 . V_144 ) ;
F_102 ( V_29 , V_30 ) ;
}
int T_1 F_103 ( unsigned long V_29 , unsigned long V_30 )
{
return F_29 ( V_29 , V_30 ) ;
}
int F_104 ( unsigned long V_29 , unsigned long V_30 )
{
F_95 ( V_29 , V_30 ) ;
return 0 ;
}
int T_7 F_105 ( unsigned long V_29 ,
unsigned long V_146 ,
unsigned long V_147 )
{
unsigned long V_12 = V_148 | V_149 | V_150 ;
F_15 ( F_6 ( V_29 , V_147 , F_106 ( V_12 ) , V_146 ) ) ;
return 0 ;
}
void F_107 ( unsigned long V_29 , unsigned long V_146 )
{
F_95 ( V_29 , V_29 + V_146 ) ;
}
unsigned long F_108 ( struct V_151 * V_152 , unsigned long V_31 ,
T_5 * V_16 , unsigned long V_153 ,
unsigned long V_154 )
{
unsigned long V_155 ;
#ifdef F_109
F_34 ( ! F_110 ( * V_16 ) ) ;
F_111 ( & V_152 -> V_144 ) ;
#endif
V_155 = F_112 ( V_152 , V_31 , ( T_6 * ) V_16 , V_153 , V_154 , 1 ) ;
F_113 ( V_31 , V_155 , V_153 , V_154 ) ;
return V_155 ;
}
T_5 F_114 ( struct V_156 * V_157 , unsigned long V_158 ,
T_5 * V_16 )
{
T_5 V_130 ;
F_115 ( V_158 & ~ V_159 ) ;
F_115 ( F_110 ( * V_16 ) ) ;
V_130 = * V_16 ;
F_73 ( V_16 ) ;
F_116 () ;
F_117 ( V_157 , V_158 , V_158 + V_160 ) ;
return V_130 ;
}
void F_118 ( struct V_151 * V_152 , T_5 * V_16 ,
T_11 V_161 )
{
struct V_162 * V_163 = (struct V_162 * ) V_161 ;
F_111 ( F_119 ( V_152 , V_16 ) ) ;
if ( ! F_120 ( V_152 , V_16 ) )
F_121 ( V_163 ) ;
else
F_122 ( V_163 , (struct V_162 * ) F_120 ( V_152 , V_16 ) ) ;
F_120 ( V_152 , V_16 ) = V_161 ;
}
T_11 F_123 ( struct V_151 * V_152 , T_5 * V_16 )
{
T_6 * V_17 ;
T_11 V_161 ;
struct V_162 * V_163 ;
F_111 ( F_119 ( V_152 , V_16 ) ) ;
V_161 = F_120 ( V_152 , V_16 ) ;
V_163 = (struct V_162 * ) V_161 ;
if ( F_124 ( V_163 ) )
F_120 ( V_152 , V_16 ) = NULL ;
else {
F_120 ( V_152 , V_16 ) = ( T_11 ) V_163 -> V_137 ;
F_125 ( V_163 ) ;
}
V_17 = ( T_6 * ) V_161 ;
* V_17 = F_126 ( 0 ) ;
V_17 ++ ;
* V_17 = F_126 ( 0 ) ;
return V_161 ;
}
T_5 F_127 ( struct V_151 * V_152 ,
unsigned long V_31 , T_5 * V_16 )
{
T_5 V_164 ;
unsigned long V_155 ;
V_155 = F_108 ( V_152 , V_31 , V_16 , ~ 0UL , 0 ) ;
V_164 = F_128 ( V_155 ) ;
F_116 () ;
return V_164 ;
}
int F_129 ( void )
{
if ( V_36 [ V_39 ] . V_38 == V_165 )
return 1 ;
return 0 ;
}
