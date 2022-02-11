static int F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
unsigned long V_4 , V_5 ;
V_4 = F_2 ( V_6 [ 0 ] . V_4 ) ;
V_5 = V_1 | V_3 | V_7 ;
F_3 ( 0 , V_4 , V_5 ) ;
return 0 ;
}
static T_1 void * F_4 ( unsigned long V_8 )
{
void * V_9 ;
V_9 = F_5 ( F_6 ( V_8 , V_8 , V_10 ) ) ;
memset ( V_9 , 0 , V_8 ) ;
return V_9 ;
}
int F_7 ( unsigned long V_11 , unsigned long V_12 ,
T_2 V_13 ,
unsigned int V_14 )
{
T_3 * V_15 ;
T_4 * V_16 ;
T_5 * V_17 ;
T_6 * V_18 ;
F_8 ( V_19 > V_20 ) ;
if ( F_9 () ) {
V_15 = F_10 ( V_11 ) ;
V_16 = F_11 ( & V_21 , V_15 , V_11 ) ;
if ( ! V_16 )
return - V_22 ;
if ( V_14 == V_23 ) {
V_18 = ( T_6 * ) V_16 ;
goto V_24;
}
V_17 = F_12 ( & V_21 , V_16 , V_11 ) ;
if ( ! V_17 )
return - V_22 ;
if ( V_14 == V_25 ) {
V_18 = F_13 ( V_17 ) ;
goto V_24;
}
V_18 = F_14 ( V_17 , V_11 ) ;
if ( ! V_18 )
return - V_22 ;
} else {
V_15 = F_10 ( V_11 ) ;
if ( F_15 ( * V_15 ) ) {
V_16 = F_4 ( V_26 ) ;
F_16 ( V_16 == NULL ) ;
F_17 ( & V_21 , V_15 , V_16 ) ;
}
V_16 = F_18 ( V_15 , V_11 ) ;
if ( V_14 == V_23 ) {
V_18 = ( T_6 * ) V_16 ;
goto V_24;
}
if ( F_19 ( * V_16 ) ) {
V_17 = F_4 ( V_27 ) ;
F_16 ( V_17 == NULL ) ;
F_20 ( & V_21 , V_16 , V_17 ) ;
}
V_17 = F_21 ( V_16 , V_11 ) ;
if ( V_14 == V_25 ) {
V_18 = F_13 ( V_17 ) ;
goto V_24;
}
if ( ! F_22 ( * V_17 ) ) {
V_18 = F_4 ( V_28 ) ;
F_16 ( V_18 == NULL ) ;
F_23 ( & V_21 , V_17 , V_18 ) ;
}
V_18 = F_24 ( V_17 , V_11 ) ;
}
V_24:
F_25 ( & V_21 , V_11 , V_18 , F_26 ( V_12 >> V_29 , V_13 ) ) ;
F_27 () ;
return 0 ;
}
void F_28 ( unsigned long V_30 , unsigned long V_31 ,
unsigned long V_32 )
{
unsigned long V_33 ;
T_3 * V_15 ;
T_4 * V_16 ;
T_5 * V_17 ;
T_6 * V_18 ;
V_30 = F_29 ( V_30 , V_28 ) ;
V_31 = F_30 ( V_31 ) ;
F_31 ( L_1 ,
V_30 , V_31 , V_32 ) ;
for ( V_33 = V_30 ; V_33 < V_31 ; V_33 += V_28 ) {
V_15 = F_10 ( V_33 ) ;
V_16 = F_11 ( & V_21 , V_15 , V_33 ) ;
if ( ! V_16 )
continue;
if ( F_32 ( * V_16 ) ) {
V_18 = ( T_6 * ) V_16 ;
goto V_34;
}
V_17 = F_12 ( & V_21 , V_16 , V_33 ) ;
if ( ! V_17 )
continue;
if ( F_33 ( * V_17 ) ) {
V_18 = F_13 ( V_17 ) ;
goto V_34;
}
V_18 = F_14 ( V_17 , V_33 ) ;
if ( ! V_18 )
continue;
V_34:
F_34 ( & V_21 , V_33 , V_18 , V_32 , 0 , 0 ) ;
}
F_35 ( V_30 , V_31 ) ;
}
void F_36 ( void )
{
unsigned long V_30 , V_31 ;
V_30 = ( unsigned long ) V_35 ;
V_31 = ( unsigned long ) V_36 ;
F_28 ( V_30 , V_31 , V_37 ) ;
}
void F_37 ( void )
{
unsigned long V_30 = ( unsigned long ) V_36 ;
unsigned long V_31 = ( unsigned long ) V_38 ;
F_28 ( V_30 , V_31 , V_39 ) ;
}
static inline void T_7 F_38 ( unsigned long V_30 ,
unsigned long V_31 ,
unsigned long V_8 )
{
char V_40 [ 10 ] ;
if ( V_31 <= V_30 )
return;
F_39 ( V_8 , 1 , V_41 , V_40 , sizeof( V_40 ) ) ;
F_40 ( L_2 , V_30 , V_31 , V_40 ) ;
}
static int T_7 F_41 ( unsigned long V_30 ,
unsigned long V_31 )
{
unsigned long V_42 , V_43 , V_44 = 0 ;
T_2 V_45 ;
unsigned long V_46 ;
#ifdef F_42
int V_47 = 1 ;
#else
int V_47 = 0 ;
#endif
V_30 = F_43 ( V_30 , V_28 ) ;
for ( V_43 = V_30 ; V_43 < V_31 ; V_43 += V_44 ) {
unsigned long V_48 , V_49 ;
int V_50 ;
V_48 = V_31 - V_43 ;
V_49 = V_44 ;
V_46 = V_23 ;
V_51:
if ( F_44 ( V_43 , V_23 ) && V_48 >= V_23 &&
V_52 [ V_53 ] . V_54 &&
V_23 <= V_46 )
V_44 = V_23 ;
else if ( F_44 ( V_43 , V_25 ) && V_48 >= V_25 &&
V_52 [ V_55 ] . V_54 )
V_44 = V_25 ;
else
V_44 = V_28 ;
if ( V_47 && ( V_44 == V_23 ) &&
( V_43 <= F_45 ( V_36 ) ) &&
( V_43 + V_44 ) >= F_45 ( V_35 ) ) {
V_46 = V_25 ;
goto V_51;
}
if ( V_47 && ( V_44 == V_25 ) &&
( V_43 <= F_45 ( V_36 ) ) &&
( V_43 + V_44 ) >= F_45 ( V_35 ) )
V_44 = V_28 ;
if ( V_44 != V_49 ) {
F_38 ( V_30 , V_43 , V_49 ) ;
V_30 = V_43 ;
}
V_42 = ( unsigned long ) F_5 ( V_43 ) ;
if ( F_46 ( V_42 , V_42 + V_44 ) ||
F_47 ( V_42 , V_42 + V_44 ) )
V_45 = V_56 ;
else
V_45 = V_57 ;
V_50 = F_7 ( V_42 , V_43 , V_45 , V_44 ) ;
if ( V_50 )
return V_50 ;
}
F_38 ( V_30 , V_43 , V_44 ) ;
return 0 ;
}
static void T_8 F_48 ( void )
{
unsigned long V_58 ;
struct V_59 * V_60 ;
V_61 = 0 ;
F_49 (memory, reg)
F_50 ( F_41 ( V_60 -> V_1 ,
V_60 -> V_1 + V_60 -> V_8 ) ) ;
if ( F_51 ( V_62 ) ) {
if ( ! V_63 )
V_63 = 20 ;
#ifdef F_52
V_64 = 1 << ( V_63 - 1 ) ;
#else
V_64 = 1 ;
#endif
} else {
if ( ! V_63 )
V_63 = 19 ;
V_64 = 1 ;
}
F_16 ( V_65 > 36 ) ;
V_66 = F_4 ( 1UL << V_65 ) ;
V_58 = F_53 () ;
V_66 -> V_67 = F_54 ( V_58 | F_55 ( V_21 . V_68 ) | V_69 ) ;
F_56 ( F_55 ( V_66 ) , 0 , V_65 - 12 ) ;
F_40 ( L_3 , V_66 , V_21 . V_68 ) ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE_5(%0,%1,2,1,1) : :
"r" (TLBIEL_INVAL_SET_LPID), "r" (0));
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
F_57 ( 0 , 0 , V_70 , 0 , 2 , 1 , 1 ) ;
}
static void T_8 F_58 ( void )
{
unsigned long V_58 , V_71 ;
F_59 () ;
V_58 = F_53 () ;
V_71 = V_58 | F_55 ( V_21 . V_68 ) | V_69 | V_72 ;
F_3 ( 0 , V_71 , 0 ) ;
F_40 ( L_4 ) ;
F_40 ( L_5 , V_6 ) ;
}
void T_8 F_60 ( void )
{
F_56 = F_1 ;
}
static int T_8 F_61 ( unsigned int V_54 )
{
int V_33 = - 1 ;
switch ( V_54 ) {
case 0xc :
V_33 = V_73 ;
break;
case 0x10 :
V_33 = V_74 ;
break;
case 0x15 :
V_33 = V_55 ;
break;
case 0x1e :
V_33 = V_53 ;
break;
}
return V_33 ;
}
static int T_8 F_62 ( unsigned long V_75 ,
const char * V_76 , int V_77 ,
void * V_78 )
{
int V_8 = 0 ;
int V_54 , V_33 ;
unsigned int V_79 ;
const T_9 * V_80 ;
const char * type = F_63 ( V_75 , L_6 , NULL ) ;
if ( type == NULL || strcmp ( type , L_7 ) != 0 )
return 0 ;
V_80 = F_63 ( V_75 , L_8 , & V_8 ) ;
if ( V_80 && V_8 == 4 )
V_63 = F_64 ( V_80 ) ;
V_80 = F_63 ( V_75 , L_9 , & V_8 ) ;
if ( ! V_80 )
return 0 ;
F_40 ( L_10 ) ;
for (; V_8 >= 4 ; V_8 -= 4 , ++ V_80 ) {
struct V_81 * V_82 ;
V_54 = F_65 ( V_80 [ 0 ] ) & ~ ( 0xe << 28 ) ;
V_79 = F_65 ( V_80 [ 0 ] ) >> 29 ;
F_40 ( L_11 , V_54 , V_79 ) ;
V_33 = F_61 ( V_54 ) ;
if ( V_33 < 0 )
continue;
V_82 = & V_52 [ V_33 ] ;
V_82 -> V_54 = V_54 ;
V_82 -> V_79 = V_79 ;
}
V_83 -> V_84 &= ~ V_85 ;
return 1 ;
}
void T_8 F_66 ( void )
{
int V_50 ;
V_50 = F_67 ( F_62 , NULL ) ;
if ( V_50 != 0 )
goto V_86;
V_52 [ V_73 ] . V_54 = 12 ;
V_52 [ V_73 ] . V_79 = 0x0 ;
V_52 [ V_74 ] . V_54 = 16 ;
V_52 [ V_74 ] . V_79 = 0x5 ;
V_86:
#ifdef F_68
if ( V_52 [ V_55 ] . V_54 ) {
V_87 = V_55 ;
}
#endif
return;
}
static void F_69 ( void )
{
unsigned long V_88 ;
unsigned long V_89 = 3UL << F_70 ( 53 ) ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(1), "i"(0), "i"(2), "r"(0) : "memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(1), "i"(1), "i"(2), "r"(0) : "memory");
asm volatile("eieio; tlbsync; ptesync; isync; slbia": : :"memory");
F_57 ( 0 , 0 , V_89 , 0 , 2 , 0 , 1 ) ;
F_57 ( 0 , 0 , V_89 , 0 , 2 , 1 , 1 ) ;
V_88 = F_71 ( V_90 ) ;
V_88 |= V_91 ;
F_72 ( V_90 , V_88 ) ;
asm volatile("isync": : :"memory");
while ( ! ( F_71 ( V_90 ) & V_91 ) )
F_73 () ;
}
static void F_74 ( void )
{
F_72 ( V_92 , ( 3ul << 62 ) ) ;
}
static void F_75 ( void )
{
unsigned long V_93 ;
if ( F_51 ( V_94 ) )
V_93 = 0 ;
else
V_93 = ( 1ul << 62 ) ;
F_72 ( V_95 , V_93 ) ;
}
void T_8 F_76 ( void )
{
unsigned long V_96 ;
#ifdef F_77
V_97 = V_74 ;
#else
V_97 = V_73 ;
#endif
#ifdef F_68
V_87 = V_97 ;
#endif
V_98 = V_99 ;
V_100 = V_101 ;
V_102 = V_103 ;
V_104 = V_69 ;
V_105 = V_101 ;
V_106 = V_107 ;
V_108 = V_109 ;
V_110 = V_111 ;
V_112 = V_113 ;
V_114 = V_115 ;
V_116 = V_117 ;
V_118 = V_119 ;
V_120 = V_121 ;
V_122 = V_123 ;
V_124 = V_125 ;
V_126 = V_127 ;
V_128 = V_129 ;
V_130 = (struct V_131 * ) V_132 ;
V_133 = V_134 ;
#ifdef F_78
V_135 = V_136 ;
#endif
V_137 = V_138 ;
V_139 = V_140 ;
if ( ! F_79 ( V_141 ) ) {
F_60 () ;
if ( F_51 ( V_94 ) )
F_69 () ;
V_96 = F_71 ( V_142 ) ;
F_72 ( V_142 , V_96 | V_143 | V_144 ) ;
F_58 () ;
F_74 () ;
} else {
F_80 () ;
}
F_81 ( V_10 ) ;
F_75 () ;
F_48 () ;
}
void F_82 ( void )
{
unsigned long V_96 ;
if ( ! F_79 ( V_141 ) ) {
if ( F_51 ( V_94 ) )
F_69 () ;
V_96 = F_71 ( V_142 ) ;
F_72 ( V_142 , V_96 | V_143 | V_144 ) ;
F_72 ( V_145 ,
F_55 ( V_6 ) | ( V_146 - 12 ) ) ;
F_74 () ;
}
F_75 () ;
}
void F_83 ( void )
{
unsigned long V_96 ;
if ( ! F_79 ( V_141 ) ) {
V_96 = F_71 ( V_142 ) ;
F_72 ( V_142 , V_96 & ~ V_143 ) ;
F_72 ( V_145 , 0 ) ;
F_84 ( 0 ) ;
F_85 () ;
}
}
void F_86 ( T_10 V_147 ,
T_10 V_148 )
{
F_16 ( V_147 != 0 ) ;
V_149 = F_87 ( V_150 , V_148 , 0x40000000 ) ;
F_81 ( V_147 + V_148 ) ;
}
static void F_88 ( T_6 * V_151 , T_5 * V_152 )
{
T_6 * V_153 ;
int V_154 ;
for ( V_154 = 0 ; V_154 < V_155 ; V_154 ++ ) {
V_153 = V_151 + V_154 ;
if ( ! F_89 ( * V_153 ) )
return;
}
F_90 ( & V_21 , V_151 ) ;
F_91 ( V_152 ) ;
}
static void F_92 ( T_5 * V_156 , T_4 * V_157 )
{
T_5 * V_152 ;
int V_154 ;
for ( V_154 = 0 ; V_154 < V_158 ; V_154 ++ ) {
V_152 = V_156 + V_154 ;
if ( ! F_93 ( * V_152 ) )
return;
}
F_94 ( & V_21 , V_156 ) ;
F_95 ( V_157 ) ;
}
static void F_96 ( T_6 * V_151 , unsigned long V_43 ,
unsigned long V_31 )
{
unsigned long V_159 ;
T_6 * V_153 ;
V_153 = V_151 + F_97 ( V_43 ) ;
for (; V_43 < V_31 ; V_43 = V_159 , V_153 ++ ) {
V_159 = ( V_43 + V_28 ) & V_160 ;
if ( V_159 > V_31 )
V_159 = V_31 ;
if ( ! F_98 ( * V_153 ) )
continue;
if ( ! F_99 ( V_43 ) || ! F_99 ( V_159 ) ) {
F_100 ( 1 , L_12 , V_161 ) ;
continue;
}
F_101 ( & V_21 , V_43 , V_153 ) ;
}
}
static void F_102 ( T_5 * V_156 , unsigned long V_43 ,
unsigned long V_31 )
{
unsigned long V_159 ;
T_6 * V_162 ;
T_5 * V_152 ;
V_152 = V_156 + F_103 ( V_43 ) ;
for (; V_43 < V_31 ; V_43 = V_159 , V_152 ++ ) {
V_159 = F_104 ( V_43 , V_31 ) ;
if ( ! F_22 ( * V_152 ) )
continue;
if ( F_33 ( * V_152 ) ) {
if ( ! F_44 ( V_43 , V_25 ) ||
! F_44 ( V_159 , V_25 ) ) {
F_100 ( 1 , L_12 , V_161 ) ;
continue;
}
F_101 ( & V_21 , V_43 , ( T_6 * ) V_152 ) ;
continue;
}
V_162 = ( T_6 * ) F_105 ( * V_152 ) ;
F_96 ( V_162 , V_43 , V_159 ) ;
F_88 ( V_162 , V_152 ) ;
}
}
static void F_106 ( T_4 * V_163 , unsigned long V_43 ,
unsigned long V_31 )
{
unsigned long V_159 ;
T_5 * V_164 ;
T_4 * V_157 ;
V_157 = V_163 + F_107 ( V_43 ) ;
for (; V_43 < V_31 ; V_43 = V_159 , V_157 ++ ) {
V_159 = F_108 ( V_43 , V_31 ) ;
if ( ! F_109 ( * V_157 ) )
continue;
if ( F_32 ( * V_157 ) ) {
if ( ! F_44 ( V_43 , V_23 ) ||
! F_44 ( V_159 , V_23 ) ) {
F_100 ( 1 , L_12 , V_161 ) ;
continue;
}
F_101 ( & V_21 , V_43 , ( T_6 * ) V_157 ) ;
continue;
}
V_164 = ( T_5 * ) F_110 ( * V_157 ) ;
F_102 ( V_164 , V_43 , V_159 ) ;
F_92 ( V_164 , V_157 ) ;
}
}
static void F_111 ( unsigned long V_30 , unsigned long V_31 )
{
unsigned long V_43 , V_159 ;
T_4 * V_165 ;
T_3 * V_68 ;
F_112 ( & V_21 . V_166 ) ;
for ( V_43 = V_30 ; V_43 < V_31 ; V_43 = V_159 ) {
V_159 = F_113 ( V_43 , V_31 ) ;
V_68 = F_10 ( V_43 ) ;
if ( ! F_114 ( * V_68 ) )
continue;
if ( F_115 ( * V_68 ) ) {
if ( ! F_44 ( V_43 , V_167 ) ||
! F_44 ( V_159 , V_167 ) ) {
F_100 ( 1 , L_12 , V_161 ) ;
continue;
}
F_101 ( & V_21 , V_43 , ( T_6 * ) V_68 ) ;
continue;
}
V_165 = ( T_4 * ) F_116 ( * V_68 ) ;
F_106 ( V_165 , V_43 , V_159 ) ;
}
F_117 ( & V_21 . V_166 ) ;
F_35 ( V_30 , V_31 ) ;
}
int T_1 F_118 ( unsigned long V_30 , unsigned long V_31 )
{
return F_41 ( V_30 , V_31 ) ;
}
int F_119 ( unsigned long V_30 , unsigned long V_31 )
{
F_111 ( V_30 , V_31 ) ;
return 0 ;
}
int T_7 F_120 ( unsigned long V_30 ,
unsigned long V_168 ,
unsigned long V_169 )
{
unsigned long V_13 = V_170 | V_171 | V_172 ;
F_16 ( F_7 ( V_30 , V_169 , F_121 ( V_13 ) , V_168 ) ) ;
return 0 ;
}
void F_122 ( unsigned long V_30 , unsigned long V_168 )
{
F_111 ( V_30 , V_30 + V_168 ) ;
}
unsigned long F_123 ( struct V_173 * V_174 , unsigned long V_43 ,
T_5 * V_17 , unsigned long V_175 ,
unsigned long V_176 )
{
unsigned long V_177 ;
#ifdef F_124
F_50 ( ! F_125 ( * V_17 ) && ! F_126 ( * V_17 ) ) ;
F_127 ( & V_174 -> V_166 ) ;
#endif
V_177 = F_34 ( V_174 , V_43 , ( T_6 * ) V_17 , V_175 , V_176 , 1 ) ;
F_128 ( V_43 , V_177 , V_175 , V_176 ) ;
return V_177 ;
}
T_5 F_129 ( struct V_178 * V_179 , unsigned long V_180 ,
T_5 * V_17 )
{
T_5 V_152 ;
F_130 ( V_180 & ~ V_181 ) ;
F_130 ( F_125 ( * V_17 ) ) ;
F_130 ( F_126 ( * V_17 ) ) ;
V_152 = * V_17 ;
F_91 ( V_17 ) ;
F_131 ( V_179 -> V_182 ) ;
F_132 ( V_179 -> V_182 , V_180 ) ;
return V_152 ;
}
void F_133 ( struct V_173 * V_174 , T_5 * V_17 ,
T_11 V_183 )
{
struct V_184 * V_185 = (struct V_184 * ) V_183 ;
F_127 ( F_134 ( V_174 , V_17 ) ) ;
if ( ! F_135 ( V_174 , V_17 ) )
F_136 ( V_185 ) ;
else
F_137 ( V_185 , (struct V_184 * ) F_135 ( V_174 , V_17 ) ) ;
F_135 ( V_174 , V_17 ) = V_183 ;
}
T_11 F_138 ( struct V_173 * V_174 , T_5 * V_17 )
{
T_6 * V_18 ;
T_11 V_183 ;
struct V_184 * V_185 ;
F_127 ( F_134 ( V_174 , V_17 ) ) ;
V_183 = F_135 ( V_174 , V_17 ) ;
V_185 = (struct V_184 * ) V_183 ;
if ( F_139 ( V_185 ) )
F_135 ( V_174 , V_17 ) = NULL ;
else {
F_135 ( V_174 , V_17 ) = ( T_11 ) V_185 -> V_159 ;
F_140 ( V_185 ) ;
}
V_18 = ( T_6 * ) V_183 ;
* V_18 = F_141 ( 0 ) ;
V_18 ++ ;
* V_18 = F_141 ( 0 ) ;
return V_183 ;
}
T_5 F_142 ( struct V_173 * V_174 ,
unsigned long V_43 , T_5 * V_17 )
{
T_5 V_186 ;
unsigned long V_177 ;
V_177 = F_123 ( V_174 , V_43 , V_17 , ~ 0UL , 0 ) ;
V_186 = F_143 ( V_177 ) ;
F_131 ( V_174 ) ;
return V_186 ;
}
int F_144 ( void )
{
if ( V_52 [ V_55 ] . V_54 == V_187 )
return 1 ;
return 0 ;
}
