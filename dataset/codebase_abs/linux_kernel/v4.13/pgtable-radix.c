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
void F_27 ( unsigned long V_29 , unsigned long V_30 ,
unsigned long V_31 )
{
unsigned long V_32 ;
T_3 * V_14 ;
T_4 * V_15 ;
T_5 * V_16 ;
T_6 * V_17 ;
V_29 = F_28 ( V_29 , V_27 ) ;
V_30 = F_29 ( V_30 ) ;
F_30 ( L_1 ,
V_29 , V_30 , V_31 ) ;
for ( V_32 = V_29 ; V_32 < V_30 ; V_32 += V_27 ) {
V_14 = F_9 ( V_32 ) ;
V_15 = F_10 ( & V_20 , V_14 , V_32 ) ;
if ( ! V_15 )
continue;
if ( F_31 ( * V_15 ) ) {
V_17 = ( T_6 * ) V_15 ;
goto V_33;
}
V_16 = F_11 ( & V_20 , V_15 , V_32 ) ;
if ( ! V_16 )
continue;
if ( F_32 ( * V_16 ) ) {
V_17 = F_12 ( V_16 ) ;
goto V_33;
}
V_17 = F_13 ( V_16 , V_32 ) ;
if ( ! V_17 )
continue;
V_33:
F_33 ( & V_20 , V_32 , V_17 , V_31 , 0 , 0 ) ;
}
F_34 ( V_29 , V_30 ) ;
}
void F_35 ( void )
{
unsigned long V_29 , V_30 ;
V_29 = ( unsigned long ) V_34 ;
V_30 = ( unsigned long ) V_35 ;
F_27 ( V_29 , V_30 , V_36 ) ;
}
void F_36 ( void )
{
unsigned long V_29 = ( unsigned long ) V_35 ;
unsigned long V_30 = ( unsigned long ) V_37 ;
F_27 ( V_29 , V_30 , V_38 ) ;
}
static inline void T_7 F_37 ( unsigned long V_29 ,
unsigned long V_30 ,
unsigned long V_7 )
{
if ( V_30 <= V_29 )
return;
F_38 ( L_2 , V_29 , V_30 , V_7 ) ;
}
static int T_7 F_39 ( unsigned long V_29 ,
unsigned long V_30 )
{
unsigned long V_39 , V_40 , V_41 = 0 ;
T_2 V_42 ;
unsigned long V_43 ;
#ifdef F_40
int V_44 = 1 ;
#else
int V_44 = 0 ;
#endif
V_29 = F_41 ( V_29 , V_27 ) ;
for ( V_40 = V_29 ; V_40 < V_30 ; V_40 += V_41 ) {
unsigned long V_45 , V_46 ;
int V_47 ;
V_45 = V_30 - V_40 ;
V_46 = V_41 ;
V_43 = V_22 ;
V_48:
if ( F_42 ( V_40 , V_22 ) && V_45 >= V_22 &&
V_49 [ V_50 ] . V_51 &&
V_22 <= V_43 )
V_41 = V_22 ;
else if ( F_42 ( V_40 , V_24 ) && V_45 >= V_24 &&
V_49 [ V_52 ] . V_51 )
V_41 = V_24 ;
else
V_41 = V_27 ;
if ( V_44 && ( V_41 == V_22 ) &&
( V_40 <= F_43 ( V_35 ) ) &&
( V_40 + V_41 ) >= F_43 ( V_34 ) ) {
V_43 = V_24 ;
goto V_48;
}
if ( V_44 && ( V_41 == V_24 ) &&
( V_40 <= F_43 ( V_35 ) ) &&
( V_40 + V_41 ) >= F_43 ( V_34 ) )
V_41 = V_27 ;
if ( V_41 != V_46 ) {
F_37 ( V_29 , V_40 , V_46 ) ;
V_29 = V_40 ;
}
V_39 = ( unsigned long ) F_4 ( V_40 ) ;
if ( F_44 ( V_39 , V_39 + V_41 ) ||
F_45 ( V_39 , V_39 + V_41 ) )
V_42 = V_53 ;
else
V_42 = V_54 ;
V_47 = F_6 ( V_39 , V_40 , V_42 , V_41 ) ;
if ( V_47 )
return V_47 ;
}
F_37 ( V_29 , V_40 , V_41 ) ;
return 0 ;
}
static void T_8 F_46 ( void )
{
unsigned long V_55 ;
struct V_56 * V_57 ;
V_58 = 0 ;
F_47 (memory, reg)
F_48 ( F_39 ( V_57 -> V_1 ,
V_57 -> V_1 + V_57 -> V_7 ) ) ;
if ( F_49 ( V_59 ) ) {
if ( ! V_60 )
V_60 = 20 ;
#ifdef F_50
V_61 = 1 << ( V_60 - 1 ) ;
#else
V_61 = 1 ;
#endif
} else {
if ( ! V_60 )
V_60 = 19 ;
V_61 = 1 ;
}
F_15 ( V_62 > 36 ) ;
V_63 = F_3 ( 1UL << V_62 ) ;
V_55 = F_51 () ;
V_63 -> V_64 = F_2 ( V_55 | F_52 ( V_20 . V_65 ) | V_66 ) ;
F_53 ( F_52 ( V_63 ) , 0 , V_62 - 12 ) ;
F_38 ( L_3 , V_63 , V_20 . V_65 ) ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE_5(%0,%1,2,1,1) : :
"r" (TLBIEL_INVAL_SET_LPID), "r" (0));
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
F_54 ( 0 , 0 , V_67 , 0 , 2 , 1 , 1 ) ;
}
static void T_8 F_55 ( void )
{
unsigned long V_55 , V_68 ;
F_56 () ;
V_55 = F_51 () ;
V_68 = V_55 | F_52 ( V_20 . V_65 ) | V_66 | V_69 ;
F_57 ( 0 , V_68 , 0 ) ;
F_38 ( L_4 ) ;
F_38 ( L_5 , V_6 ) ;
}
void T_8 F_58 ( void )
{
F_53 = F_1 ;
}
static int T_8 F_59 ( unsigned int V_51 )
{
int V_32 = - 1 ;
switch ( V_51 ) {
case 0xc :
V_32 = V_70 ;
break;
case 0x10 :
V_32 = V_71 ;
break;
case 0x15 :
V_32 = V_52 ;
break;
case 0x1e :
V_32 = V_50 ;
break;
}
return V_32 ;
}
static int T_8 F_60 ( unsigned long V_72 ,
const char * V_73 , int V_74 ,
void * V_75 )
{
int V_7 = 0 ;
int V_51 , V_32 ;
unsigned int V_76 ;
const T_9 * V_77 ;
const char * type = F_61 ( V_72 , L_6 , NULL ) ;
if ( type == NULL || strcmp ( type , L_7 ) != 0 )
return 0 ;
V_77 = F_61 ( V_72 , L_8 , & V_7 ) ;
if ( V_77 && V_7 == 4 )
V_60 = F_62 ( V_77 ) ;
V_77 = F_61 ( V_72 , L_9 , & V_7 ) ;
if ( ! V_77 )
return 0 ;
F_38 ( L_10 ) ;
for (; V_7 >= 4 ; V_7 -= 4 , ++ V_77 ) {
struct V_78 * V_79 ;
V_51 = F_63 ( V_77 [ 0 ] ) & ~ ( 0xe << 28 ) ;
V_76 = F_63 ( V_77 [ 0 ] ) >> 29 ;
F_38 ( L_11 , V_51 , V_76 ) ;
V_32 = F_59 ( V_51 ) ;
if ( V_32 < 0 )
continue;
V_79 = & V_49 [ V_32 ] ;
V_79 -> V_51 = V_51 ;
V_79 -> V_76 = V_76 ;
}
V_80 -> V_81 &= ~ V_82 ;
return 1 ;
}
void T_8 F_64 ( void )
{
int V_47 ;
V_47 = F_65 ( F_60 , NULL ) ;
if ( V_47 != 0 )
goto V_83;
V_49 [ V_70 ] . V_51 = 12 ;
V_49 [ V_70 ] . V_76 = 0x0 ;
V_49 [ V_71 ] . V_51 = 16 ;
V_49 [ V_71 ] . V_76 = 0x5 ;
V_83:
#ifdef F_66
if ( V_49 [ V_52 ] . V_51 ) {
V_84 = V_52 ;
}
#endif
return;
}
static void F_67 ( void )
{
unsigned long V_85 ;
unsigned long V_86 = 3UL << F_68 ( 53 ) ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(1), "i"(0), "i"(2), "r"(0) : "memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(1), "i"(1), "i"(2), "r"(0) : "memory");
asm volatile("eieio; tlbsync; ptesync; isync; slbia": : :"memory");
F_54 ( 0 , 0 , V_86 , 0 , 2 , 0 , 1 ) ;
F_54 ( 0 , 0 , V_86 , 0 , 2 , 1 , 1 ) ;
V_85 = F_69 ( V_87 ) ;
V_85 |= V_88 ;
F_70 ( V_87 , V_85 ) ;
asm volatile("isync": : :"memory");
while ( ! ( F_69 ( V_87 ) & V_88 ) )
F_71 () ;
}
static void F_72 ( void )
{
F_70 ( V_89 , ( 3ul << 62 ) ) ;
}
static void F_73 ( void )
{
unsigned long V_90 ;
if ( F_49 ( V_91 ) )
V_90 = 0 ;
else
V_90 = ( 1ul << 62 ) ;
F_70 ( V_92 , V_90 ) ;
}
void T_8 F_74 ( void )
{
unsigned long V_93 ;
#ifdef F_75
V_94 = V_71 ;
#else
V_94 = V_70 ;
#endif
#ifdef F_66
V_84 = V_94 ;
#endif
V_95 = V_96 ;
V_97 = V_98 ;
V_99 = V_100 ;
V_101 = V_66 ;
V_102 = V_98 ;
V_103 = V_104 ;
V_105 = V_106 ;
V_107 = V_108 ;
V_109 = V_110 ;
V_111 = V_112 ;
V_113 = V_114 ;
V_115 = V_116 ;
V_117 = V_118 ;
V_119 = V_120 ;
V_121 = V_122 ;
V_123 = V_124 ;
V_125 = (struct V_126 * ) V_127 ;
V_128 = V_129 ;
#ifdef F_76
V_130 = V_131 ;
#endif
V_132 = V_133 ;
V_134 = V_135 ;
if ( ! F_77 ( V_136 ) ) {
F_58 () ;
if ( F_49 ( V_91 ) )
F_67 () ;
V_93 = F_69 ( V_137 ) ;
F_70 ( V_137 , V_93 | V_138 | V_139 ) ;
F_55 () ;
F_72 () ;
} else {
F_78 () ;
}
F_79 ( V_9 ) ;
F_73 () ;
F_46 () ;
}
void F_80 ( void )
{
unsigned long V_93 ;
if ( ! F_77 ( V_136 ) ) {
if ( F_49 ( V_91 ) )
F_67 () ;
V_93 = F_69 ( V_137 ) ;
F_70 ( V_137 , V_93 | V_138 | V_139 ) ;
F_70 ( V_140 ,
F_52 ( V_6 ) | ( V_141 - 12 ) ) ;
F_72 () ;
}
F_73 () ;
}
void F_81 ( void )
{
unsigned long V_93 ;
if ( ! F_77 ( V_136 ) ) {
V_93 = F_69 ( V_137 ) ;
F_70 ( V_137 , V_93 & ~ V_138 ) ;
F_70 ( V_140 , 0 ) ;
F_82 ( 0 ) ;
F_83 () ;
}
}
void F_84 ( T_10 V_142 ,
T_10 V_143 )
{
F_15 ( V_142 != 0 ) ;
V_144 = F_85 ( V_145 , V_143 , 0x40000000 ) ;
F_79 ( V_142 + V_143 ) ;
}
static void F_86 ( T_6 * V_146 , T_5 * V_147 )
{
T_6 * V_148 ;
int V_149 ;
for ( V_149 = 0 ; V_149 < V_150 ; V_149 ++ ) {
V_148 = V_146 + V_149 ;
if ( ! F_87 ( * V_148 ) )
return;
}
F_88 ( & V_20 , V_146 ) ;
F_89 ( V_147 ) ;
}
static void F_90 ( T_5 * V_151 , T_4 * V_152 )
{
T_5 * V_147 ;
int V_149 ;
for ( V_149 = 0 ; V_149 < V_153 ; V_149 ++ ) {
V_147 = V_151 + V_149 ;
if ( ! F_91 ( * V_147 ) )
return;
}
F_92 ( & V_20 , V_151 ) ;
F_93 ( V_152 ) ;
}
static void F_94 ( T_6 * V_146 , unsigned long V_40 ,
unsigned long V_30 )
{
unsigned long V_154 ;
T_6 * V_148 ;
V_148 = V_146 + F_95 ( V_40 ) ;
for (; V_40 < V_30 ; V_40 = V_154 , V_148 ++ ) {
V_154 = ( V_40 + V_27 ) & V_155 ;
if ( V_154 > V_30 )
V_154 = V_30 ;
if ( ! F_96 ( * V_148 ) )
continue;
if ( ! F_97 ( V_40 ) || ! F_97 ( V_154 ) ) {
F_98 ( 1 , L_12 , V_156 ) ;
continue;
}
F_99 ( & V_20 , V_40 , V_148 ) ;
}
}
static void F_100 ( T_5 * V_151 , unsigned long V_40 ,
unsigned long V_30 )
{
unsigned long V_154 ;
T_6 * V_157 ;
T_5 * V_147 ;
V_147 = V_151 + F_101 ( V_40 ) ;
for (; V_40 < V_30 ; V_40 = V_154 , V_147 ++ ) {
V_154 = F_102 ( V_40 , V_30 ) ;
if ( ! F_21 ( * V_147 ) )
continue;
if ( F_32 ( * V_147 ) ) {
if ( ! F_42 ( V_40 , V_24 ) ||
! F_42 ( V_154 , V_24 ) ) {
F_98 ( 1 , L_12 , V_156 ) ;
continue;
}
F_99 ( & V_20 , V_40 , ( T_6 * ) V_147 ) ;
continue;
}
V_157 = ( T_6 * ) F_103 ( * V_147 ) ;
F_94 ( V_157 , V_40 , V_154 ) ;
F_86 ( V_157 , V_147 ) ;
}
}
static void F_104 ( T_4 * V_158 , unsigned long V_40 ,
unsigned long V_30 )
{
unsigned long V_154 ;
T_5 * V_159 ;
T_4 * V_152 ;
V_152 = V_158 + F_105 ( V_40 ) ;
for (; V_40 < V_30 ; V_40 = V_154 , V_152 ++ ) {
V_154 = F_106 ( V_40 , V_30 ) ;
if ( ! F_107 ( * V_152 ) )
continue;
if ( F_31 ( * V_152 ) ) {
if ( ! F_42 ( V_40 , V_22 ) ||
! F_42 ( V_154 , V_22 ) ) {
F_98 ( 1 , L_12 , V_156 ) ;
continue;
}
F_99 ( & V_20 , V_40 , ( T_6 * ) V_152 ) ;
continue;
}
V_159 = ( T_5 * ) F_108 ( * V_152 ) ;
F_100 ( V_159 , V_40 , V_154 ) ;
F_90 ( V_159 , V_152 ) ;
}
}
static void F_109 ( unsigned long V_29 , unsigned long V_30 )
{
unsigned long V_40 , V_154 ;
T_4 * V_160 ;
T_3 * V_65 ;
F_110 ( & V_20 . V_161 ) ;
for ( V_40 = V_29 ; V_40 < V_30 ; V_40 = V_154 ) {
V_154 = F_111 ( V_40 , V_30 ) ;
V_65 = F_9 ( V_40 ) ;
if ( ! F_112 ( * V_65 ) )
continue;
if ( F_113 ( * V_65 ) ) {
if ( ! F_42 ( V_40 , V_162 ) ||
! F_42 ( V_154 , V_162 ) ) {
F_98 ( 1 , L_12 , V_156 ) ;
continue;
}
F_99 ( & V_20 , V_40 , ( T_6 * ) V_65 ) ;
continue;
}
V_160 = ( T_4 * ) F_114 ( * V_65 ) ;
F_104 ( V_160 , V_40 , V_154 ) ;
}
F_115 ( & V_20 . V_161 ) ;
F_34 ( V_29 , V_30 ) ;
}
int T_1 F_116 ( unsigned long V_29 , unsigned long V_30 )
{
return F_39 ( V_29 , V_30 ) ;
}
int F_117 ( unsigned long V_29 , unsigned long V_30 )
{
F_109 ( V_29 , V_30 ) ;
return 0 ;
}
int T_7 F_118 ( unsigned long V_29 ,
unsigned long V_163 ,
unsigned long V_164 )
{
unsigned long V_12 = V_165 | V_166 | V_167 ;
F_15 ( F_6 ( V_29 , V_164 , F_119 ( V_12 ) , V_163 ) ) ;
return 0 ;
}
void F_120 ( unsigned long V_29 , unsigned long V_163 )
{
F_109 ( V_29 , V_29 + V_163 ) ;
}
unsigned long F_121 ( struct V_168 * V_169 , unsigned long V_40 ,
T_5 * V_16 , unsigned long V_170 ,
unsigned long V_171 )
{
unsigned long V_172 ;
#ifdef F_122
F_48 ( ! F_123 ( * V_16 ) && ! F_124 ( * V_16 ) ) ;
F_125 ( & V_169 -> V_161 ) ;
#endif
V_172 = F_33 ( V_169 , V_40 , ( T_6 * ) V_16 , V_170 , V_171 , 1 ) ;
F_126 ( V_40 , V_172 , V_170 , V_171 ) ;
return V_172 ;
}
T_5 F_127 ( struct V_173 * V_174 , unsigned long V_175 ,
T_5 * V_16 )
{
T_5 V_147 ;
F_128 ( V_175 & ~ V_176 ) ;
F_128 ( F_123 ( * V_16 ) ) ;
F_128 ( F_124 ( * V_16 ) ) ;
V_147 = * V_16 ;
F_89 ( V_16 ) ;
F_129 () ;
F_130 ( V_174 , V_175 , V_175 + V_177 ) ;
return V_147 ;
}
void F_131 ( struct V_168 * V_169 , T_5 * V_16 ,
T_11 V_178 )
{
struct V_179 * V_180 = (struct V_179 * ) V_178 ;
F_125 ( F_132 ( V_169 , V_16 ) ) ;
if ( ! F_133 ( V_169 , V_16 ) )
F_134 ( V_180 ) ;
else
F_135 ( V_180 , (struct V_179 * ) F_133 ( V_169 , V_16 ) ) ;
F_133 ( V_169 , V_16 ) = V_178 ;
}
T_11 F_136 ( struct V_168 * V_169 , T_5 * V_16 )
{
T_6 * V_17 ;
T_11 V_178 ;
struct V_179 * V_180 ;
F_125 ( F_132 ( V_169 , V_16 ) ) ;
V_178 = F_133 ( V_169 , V_16 ) ;
V_180 = (struct V_179 * ) V_178 ;
if ( F_137 ( V_180 ) )
F_133 ( V_169 , V_16 ) = NULL ;
else {
F_133 ( V_169 , V_16 ) = ( T_11 ) V_180 -> V_154 ;
F_138 ( V_180 ) ;
}
V_17 = ( T_6 * ) V_178 ;
* V_17 = F_139 ( 0 ) ;
V_17 ++ ;
* V_17 = F_139 ( 0 ) ;
return V_178 ;
}
T_5 F_140 ( struct V_168 * V_169 ,
unsigned long V_40 , T_5 * V_16 )
{
T_5 V_181 ;
unsigned long V_172 ;
V_172 = F_121 ( V_169 , V_40 , V_16 , ~ 0UL , 0 ) ;
V_181 = F_141 ( V_172 ) ;
F_129 () ;
return V_181 ;
}
int F_142 ( void )
{
if ( V_49 [ V_52 ] . V_51 == V_182 )
return 1 ;
return 0 ;
}
