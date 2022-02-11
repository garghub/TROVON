static T_1 F_1 ( T_1 V_1 )
{
union V_2 V_3 ;
T_1 V_4 = F_2 ( V_5 , V_6 ) | F_2 ( V_7 , V_8 ) | F_2 ( V_9 , V_10 ) | F_2 ( V_11 , V_12 ) ;
V_3 . V_4 = V_1 ;
if ( V_3 . V_13 )
V_4 |= F_2 ( V_11 , V_14 ) ;
else
V_4 |= F_2 ( V_11 , V_15 ) ;
if ( V_3 . V_16 )
V_4 |= F_2 ( V_9 , V_15 ) ;
else
V_4 |= F_2 ( V_9 , V_14 ) ;
if ( V_3 . V_17 )
V_4 |= F_2 ( V_18 , V_19 ) ;
return V_4 ;
}
static T_1 F_3 ( struct V_20 * V_21 , T_1 V_1 )
{
union V_22 V_3 ;
T_1 V_23 = V_21 -> V_24 . V_25 & V_26 ;
V_3 . V_4 = 0 ;
V_3 . V_27 = V_28 ;
V_3 . V_29 = V_30 ;
if ( V_23 != 0x12d0 && V_23 != 0x22d0 && V_23 != 0x42d0 && V_23 != 0x82d0 )
return V_3 . V_29 ;
if ( V_1 & 1 )
V_3 . V_29 = V_31 | V_32 ;
else
V_3 . V_29 = V_31 | V_33 ;
return V_3 . V_4 ;
}
static T_1 F_4 ( T_1 V_1 )
{
union V_2 V_3 ;
T_1 V_4 ;
int V_34 = V_35 . V_36 ;
int V_37 = V_35 . V_38 ;
V_3 . V_4 = V_1 ;
V_4 = V_39 [ V_3 . V_40 ] ;
if ( V_37 == 0x6 && ( V_34 == 26 || V_34 == 30
|| V_34 == 31 || V_34 == 46 ) ) {
V_4 |= F_2 ( V_11 , V_8 ) | F_2 ( V_18 , V_8 ) ;
return V_4 ;
}
if ( V_3 . V_41 )
V_4 |= F_2 ( V_11 , V_14 ) | F_2 ( V_11 , V_12 ) ;
else
V_4 |= F_2 ( V_11 , V_15 ) | F_2 ( V_11 , V_10 ) | F_2 ( V_11 , V_12 ) ;
if ( V_3 . V_42 )
V_4 |= F_2 ( V_18 , V_19 ) ;
return V_4 ;
}
void F_5 ( int V_43 )
{
struct V_44 * V_45 = F_6 ( V_46 , V_43 ) . V_45 ;
if ( ! V_45 )
return;
F_7 ( V_43 , V_47 ,
( V_48 ) ( ( T_1 ) ( unsigned long ) V_45 ) ,
( V_48 ) ( ( T_1 ) ( unsigned long ) V_45 >> 32 ) ) ;
}
void F_8 ( int V_43 )
{
if ( ! F_6 ( V_46 , V_43 ) . V_45 )
return;
F_7 ( V_43 , V_47 , 0 , 0 ) ;
}
static int F_9 ( int V_43 )
{
struct V_44 * V_45 = F_6 ( V_46 , V_43 ) . V_45 ;
int V_49 = F_10 ( V_43 ) ;
int V_50 , V_51 = 1 ;
void * V_52 , * V_53 ;
if ( ! V_54 . V_55 )
return 0 ;
V_52 = F_11 ( V_56 , V_57 , V_49 ) ;
if ( F_12 ( ! V_52 ) )
return - V_58 ;
if ( V_54 . V_59 . V_60 < 2 ) {
V_53 = F_11 ( V_61 , V_57 , V_49 ) ;
if ( ! V_53 ) {
F_13 ( V_52 ) ;
return - V_58 ;
}
F_6 ( V_62 , V_43 ) = V_53 ;
}
V_50 = V_56 / V_54 . V_63 ;
V_45 -> V_64 = ( T_1 ) ( unsigned long ) V_52 ;
V_45 -> V_65 = V_45 -> V_64 ;
V_45 -> V_66 = V_45 -> V_64 +
V_50 * V_54 . V_63 ;
V_45 -> V_67 = V_45 -> V_64 +
V_51 * V_54 . V_63 ;
return 0 ;
}
static void F_14 ( int V_43 )
{
struct V_44 * V_45 = F_6 ( V_46 , V_43 ) . V_45 ;
if ( ! V_45 || ! V_54 . V_55 )
return;
F_13 ( F_6 ( V_62 , V_43 ) ) ;
F_6 ( V_62 , V_43 ) = NULL ;
F_13 ( ( void * ) ( unsigned long ) V_45 -> V_64 ) ;
V_45 -> V_64 = 0 ;
}
static int F_15 ( int V_43 )
{
struct V_44 * V_45 = F_6 ( V_46 , V_43 ) . V_45 ;
int V_49 = F_10 ( V_43 ) ;
int V_50 , V_51 ;
void * V_52 ;
if ( ! V_54 . V_68 )
return 0 ;
V_52 = F_11 ( V_69 , V_57 | V_70 , V_49 ) ;
if ( F_12 ( ! V_52 ) ) {
F_16 ( 1 , L_1 , V_71 ) ;
return - V_58 ;
}
V_50 = V_69 / V_72 ;
V_51 = V_50 / 16 ;
V_45 -> V_73 = ( T_1 ) ( unsigned long ) V_52 ;
V_45 -> V_74 = V_45 -> V_73 ;
V_45 -> V_75 = V_45 -> V_73 +
V_50 * V_72 ;
V_45 -> V_76 = V_45 -> V_75 -
V_51 * V_72 ;
return 0 ;
}
static void F_17 ( int V_43 )
{
struct V_44 * V_45 = F_6 ( V_46 , V_43 ) . V_45 ;
if ( ! V_45 || ! V_54 . V_68 )
return;
F_13 ( ( void * ) ( unsigned long ) V_45 -> V_73 ) ;
V_45 -> V_73 = 0 ;
}
static int F_18 ( int V_43 )
{
int V_49 = F_10 ( V_43 ) ;
struct V_44 * V_45 ;
V_45 = F_11 ( sizeof( * V_45 ) , V_57 , V_49 ) ;
if ( F_12 ( ! V_45 ) )
return - V_58 ;
F_6 ( V_46 , V_43 ) . V_45 = V_45 ;
return 0 ;
}
static void F_19 ( int V_43 )
{
struct V_44 * V_45 = F_6 ( V_46 , V_43 ) . V_45 ;
if ( ! V_45 )
return;
F_6 ( V_46 , V_43 ) . V_45 = NULL ;
F_13 ( V_45 ) ;
}
void F_20 ( void )
{
int V_43 ;
if ( ! V_54 . V_68 && ! V_54 . V_55 )
return;
F_21 () ;
F_22 (cpu)
F_8 ( V_43 ) ;
F_23 (cpu) {
F_14 ( V_43 ) ;
F_17 ( V_43 ) ;
F_19 ( V_43 ) ;
}
F_24 () ;
}
void F_25 ( void )
{
int V_77 = 0 , V_78 = 0 ;
int V_43 ;
V_54 . V_79 = 0 ;
V_54 . V_80 = 0 ;
if ( ! V_54 . V_68 && ! V_54 . V_55 )
return;
if ( ! V_54 . V_68 )
V_77 = 1 ;
if ( ! V_54 . V_55 )
V_78 = 1 ;
F_21 () ;
F_23 (cpu) {
if ( F_18 ( V_43 ) ) {
V_77 = 1 ;
V_78 = 1 ;
}
if ( ! V_77 && F_15 ( V_43 ) )
V_77 = 1 ;
if ( ! V_78 && F_9 ( V_43 ) )
V_78 = 1 ;
if ( V_77 && V_78 )
break;
}
if ( V_77 ) {
F_23 (cpu)
F_17 ( V_43 ) ;
}
if ( V_78 ) {
F_23 (cpu)
F_14 ( V_43 ) ;
}
if ( V_77 && V_78 ) {
F_23 (cpu)
F_19 ( V_43 ) ;
} else {
if ( V_54 . V_68 && ! V_77 )
V_54 . V_79 = 1 ;
if ( V_54 . V_55 && ! V_78 )
V_54 . V_80 = 1 ;
F_22 (cpu)
F_5 ( V_43 ) ;
}
F_24 () ;
}
void F_26 ( T_1 V_25 )
{
unsigned long V_81 ;
V_81 = F_27 () ;
V_81 |= V_82 ;
V_81 |= V_83 ;
V_81 |= V_84 ;
if ( ! ( V_25 & V_85 ) )
V_81 |= V_86 ;
if ( ! ( V_25 & V_87 ) )
V_81 |= V_88 ;
F_28 ( V_81 ) ;
}
void F_29 ( void )
{
struct V_46 * V_89 = & F_30 ( V_46 ) ;
unsigned long V_81 ;
if ( ! V_89 -> V_45 )
return;
V_81 = F_27 () ;
V_81 &=
~ ( V_82 | V_83 | V_84 |
V_86 | V_88 ) ;
F_28 ( V_81 ) ;
}
int F_31 ( void )
{
struct V_46 * V_89 = & F_30 ( V_46 ) ;
struct V_44 * V_45 = V_89 -> V_45 ;
struct V_90 {
T_1 V_91 ;
T_1 V_92 ;
T_1 V_93 ;
};
struct V_20 * V_21 = V_89 -> V_94 [ V_95 ] ;
struct V_90 * V_96 , * V_97 ;
struct V_98 V_99 ;
struct V_100 V_101 ;
struct V_102 V_103 ;
struct V_104 V_105 ;
if ( ! V_21 )
return 0 ;
if ( ! V_54 . V_79 )
return 0 ;
V_96 = (struct V_90 * ) ( unsigned long ) V_45 -> V_73 ;
V_97 = (struct V_90 * ) ( unsigned long ) V_45 -> V_74 ;
if ( V_97 <= V_96 )
return 0 ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_45 -> V_74 = V_45 -> V_73 ;
F_32 ( & V_103 , 0 , V_21 -> V_24 . V_106 ) ;
F_33 ( & V_101 , & V_103 , V_21 , & V_105 ) ;
if ( F_34 ( & V_99 , V_21 , V_101 . V_107 * ( V_97 - V_96 ) ) )
return 1 ;
for (; V_96 < V_97 ; V_96 ++ ) {
V_103 . V_108 = V_96 -> V_91 ;
V_103 . V_109 = V_96 -> V_92 ;
F_35 ( & V_99 , & V_101 , & V_103 , V_21 ) ;
}
F_36 ( & V_99 ) ;
V_21 -> V_24 . V_110 ++ ;
V_21 -> V_111 = V_112 ;
return 1 ;
}
struct V_113 * F_37 ( struct V_20 * V_21 )
{
struct V_113 * V_114 ;
if ( ! V_21 -> V_115 . V_116 )
return NULL ;
if ( V_54 . V_117 ) {
F_38 (c, x86_pmu.pebs_constraints) {
if ( ( V_21 -> V_24 . V_25 & V_114 -> V_118 ) == V_114 -> V_119 ) {
V_21 -> V_24 . V_93 |= V_114 -> V_93 ;
return V_114 ;
}
}
}
return & V_120 ;
}
void F_39 ( struct V_20 * V_21 )
{
struct V_46 * V_89 = & F_30 ( V_46 ) ;
struct V_121 * V_122 = & V_21 -> V_24 ;
V_122 -> V_25 &= ~ V_123 ;
V_89 -> V_124 |= 1ULL << V_122 -> V_125 ;
if ( V_21 -> V_24 . V_93 & V_126 )
V_89 -> V_124 |= 1ULL << ( V_122 -> V_125 + 32 ) ;
else if ( V_21 -> V_24 . V_93 & V_127 )
V_89 -> V_124 |= 1ULL << 63 ;
}
void F_40 ( struct V_20 * V_21 )
{
struct V_46 * V_89 = & F_30 ( V_46 ) ;
struct V_121 * V_122 = & V_21 -> V_24 ;
V_89 -> V_124 &= ~ ( 1ULL << V_122 -> V_125 ) ;
if ( V_21 -> V_24 . V_128 -> V_93 & V_126 )
V_89 -> V_124 &= ~ ( 1ULL << ( V_122 -> V_125 + 32 ) ) ;
else if ( V_21 -> V_24 . V_128 -> V_93 & V_127 )
V_89 -> V_124 &= ~ ( 1ULL << 63 ) ;
if ( V_89 -> V_129 )
F_41 ( V_130 , V_89 -> V_124 ) ;
V_122 -> V_25 |= V_123 ;
}
void F_42 ( void )
{
struct V_46 * V_89 = & F_30 ( V_46 ) ;
if ( V_89 -> V_124 )
F_41 ( V_130 , V_89 -> V_124 ) ;
}
void F_43 ( void )
{
struct V_46 * V_89 = & F_30 ( V_46 ) ;
if ( V_89 -> V_124 )
F_41 ( V_130 , 0 ) ;
}
static int F_44 ( struct V_104 * V_105 )
{
struct V_46 * V_89 = & F_30 ( V_46 ) ;
unsigned long V_91 = V_89 -> V_131 [ 0 ] . V_91 ;
unsigned long V_132 , V_92 = V_89 -> V_131 [ 0 ] . V_92 ;
unsigned long V_108 = V_105 -> V_108 ;
int V_133 = 0 ;
void * V_134 ;
if ( ! V_54 . V_59 . V_135 )
return 1 ;
if ( ! V_89 -> V_136 . V_137 || ! V_91 || ! V_92 )
return 0 ;
if ( F_45 ( V_108 ) != F_45 ( V_92 ) )
return 0 ;
if ( ( V_108 - V_92 ) > V_61 )
return 0 ;
if ( V_108 == V_92 ) {
F_46 ( V_105 , V_91 ) ;
return 1 ;
}
if ( ! F_45 ( V_108 ) ) {
int V_107 , V_138 ;
T_2 * V_139 = F_47 ( V_62 ) ;
V_107 = V_108 - V_92 ;
V_138 = F_48 ( V_139 , ( void V_140 * ) V_92 , V_107 ) ;
if ( V_138 != 0 )
return 0 ;
V_134 = V_139 ;
} else {
V_134 = ( void * ) V_92 ;
}
do {
struct V_141 V_141 ;
V_132 = V_92 ;
#ifdef F_49
V_133 = F_45 ( V_92 ) || ! F_50 ( V_142 ) ;
#endif
F_51 ( & V_141 , V_134 , V_133 ) ;
F_52 ( & V_141 ) ;
V_92 += V_141 . V_143 ;
V_134 += V_141 . V_143 ;
} while ( V_92 < V_108 );
if ( V_92 == V_108 ) {
F_46 ( V_105 , V_132 ) ;
return 1 ;
}
return 0 ;
}
static inline T_1 F_53 ( struct V_144 * V_55 )
{
if ( V_55 -> V_145 ) {
union V_146 V_147 = { . V_148 = V_55 -> V_145 } ;
return V_147 . V_149 ;
}
return 0 ;
}
static inline T_1 F_54 ( struct V_144 * V_55 )
{
T_1 V_150 = ( V_55 -> V_145 & V_151 ) >> 32 ;
if ( ( V_150 & V_152 ) && ( V_55 -> V_153 & 1 ) )
V_150 |= ( ( V_55 -> V_153 >> 24 ) & 0xff ) << V_154 ;
return V_150 ;
}
static void F_55 ( struct V_20 * V_21 ,
struct V_104 * V_155 , void * V_156 )
{
struct V_46 * V_89 = & F_30 ( V_46 ) ;
struct V_144 * V_55 = V_156 ;
struct V_102 V_103 ;
struct V_104 V_105 ;
T_1 V_157 ;
int V_158 , V_159 ;
if ( ! F_56 ( V_21 ) )
return;
V_158 = V_21 -> V_24 . V_93 & V_126 ;
V_159 = V_21 -> V_24 . V_93 & ( V_127 |
V_160 ) ;
F_32 ( & V_103 , 0 , V_21 -> V_24 . V_106 ) ;
V_103 . V_161 = V_21 -> V_24 . V_106 ;
V_157 = V_21 -> V_115 . V_157 ;
if ( V_158 || V_159 ) {
if ( V_158 && ( V_157 & V_162 ) )
V_103 . V_163 = V_55 -> V_164 ;
if ( V_157 & V_165 ) {
if ( V_158 )
V_103 . V_166 . V_4 = F_4 ( V_55 -> V_3 ) ;
else if ( V_21 -> V_24 . V_93 & V_160 )
V_103 . V_166 . V_4 =
F_3 ( V_21 , V_55 -> V_3 ) ;
else
V_103 . V_166 . V_4 = F_1 ( V_55 -> V_3 ) ;
}
}
V_105 = * V_155 ;
V_105 . V_93 = V_55 -> V_93 ;
F_46 ( & V_105 , V_55 -> V_108 ) ;
V_105 . V_167 = V_55 -> V_167 ;
V_105 . V_168 = V_55 -> V_168 ;
if ( V_21 -> V_115 . V_116 > 1 && V_54 . V_59 . V_60 >= 2 ) {
V_105 . V_108 = V_55 -> V_169 ;
V_105 . V_93 |= V_170 ;
} else if ( V_21 -> V_115 . V_116 > 1 && F_44 ( & V_105 ) )
V_105 . V_93 |= V_170 ;
else
V_105 . V_93 &= ~ V_170 ;
if ( ( V_21 -> V_115 . V_157 & V_171 ) &&
V_54 . V_59 . V_60 >= 1 )
V_103 . V_109 = V_55 -> V_172 ;
if ( V_54 . V_59 . V_60 >= 2 ) {
if ( ( V_21 -> V_115 . V_157 & V_162 ) && ! V_158 )
V_103 . V_163 = F_53 ( V_55 ) ;
if ( V_21 -> V_115 . V_157 & V_173 )
V_103 . V_150 = F_54 ( V_55 ) ;
}
if ( F_57 ( V_21 ) )
V_103 . V_174 = & V_89 -> V_136 ;
if ( F_58 ( V_21 , & V_103 , & V_105 ) )
F_59 ( V_21 , 0 ) ;
}
static void F_60 ( struct V_104 * V_155 )
{
struct V_46 * V_89 = & F_30 ( V_46 ) ;
struct V_44 * V_45 = V_89 -> V_45 ;
struct V_20 * V_21 = V_89 -> V_94 [ 0 ] ;
struct V_175 * V_96 , * V_97 ;
int V_176 ;
if ( ! V_54 . V_80 )
return;
V_96 = (struct V_175 * ) ( unsigned long ) V_45 -> V_64 ;
V_97 = (struct V_175 * ) ( unsigned long ) V_45 -> V_65 ;
V_45 -> V_65 = V_45 -> V_64 ;
if ( ! F_61 ( 0 , V_89 -> V_177 ) )
return;
F_62 ( ! V_21 ) ;
if ( ! V_21 -> V_115 . V_116 )
return;
V_176 = V_97 - V_96 ;
if ( V_176 <= 0 )
return;
F_16 ( V_176 > 1 , L_2 , V_176 ) ;
V_96 += V_176 - 1 ;
F_55 ( V_21 , V_155 , V_96 ) ;
}
static void F_63 ( struct V_104 * V_155 )
{
struct V_46 * V_89 = & F_30 ( V_46 ) ;
struct V_44 * V_45 = V_89 -> V_45 ;
struct V_20 * V_21 = NULL ;
void * V_96 , * V_97 ;
T_1 V_1 = 0 ;
int V_178 ;
if ( ! V_54 . V_80 )
return;
V_96 = (struct V_179 * ) ( unsigned long ) V_45 -> V_64 ;
V_97 = (struct V_179 * ) ( unsigned long ) V_45 -> V_65 ;
V_45 -> V_65 = V_45 -> V_64 ;
if ( F_12 ( V_96 > V_97 ) )
return;
F_16 ( V_97 - V_96 > V_54 . V_180 * V_54 . V_63 ,
L_3 ,
( long ) ( V_97 - V_96 ) / V_54 . V_63 ) ;
for (; V_96 < V_97 ; V_96 += V_54 . V_63 ) {
struct V_179 * V_181 = V_96 ;
F_64 (bit, (unsigned long *)&p->status,
x86_pmu.max_pebs_events) {
V_21 = V_89 -> V_94 [ V_178 ] ;
if ( ! F_61 ( V_178 , V_89 -> V_177 ) )
continue;
F_62 ( ! V_21 ) ;
if ( ! V_21 -> V_115 . V_116 )
continue;
if ( F_65 ( V_178 , ( unsigned long * ) & V_1 ) )
continue;
break;
}
if ( ! V_21 || V_178 >= V_54 . V_180 )
continue;
F_55 ( V_21 , V_155 , V_96 ) ;
}
}
void F_66 ( void )
{
if ( ! F_67 ( V_182 ) )
return;
V_54 . V_68 = F_67 ( V_183 ) ;
V_54 . V_55 = F_67 ( V_184 ) ;
if ( V_54 . V_55 ) {
char V_185 = V_54 . V_59 . V_135 ? '+' : '-' ;
int V_186 = V_54 . V_59 . V_60 ;
switch ( V_186 ) {
case 0 :
F_68 ( V_187 L_4 , V_185 ) ;
V_54 . V_63 = sizeof( struct V_175 ) ;
V_54 . V_188 = F_60 ;
break;
case 1 :
F_68 ( V_187 L_5 , V_185 ) ;
V_54 . V_63 = sizeof( struct V_179 ) ;
V_54 . V_188 = F_63 ;
break;
case 2 :
F_69 ( L_6 , V_185 ) ;
V_54 . V_63 = sizeof( struct V_144 ) ;
V_54 . V_188 = F_63 ;
break;
default:
F_68 ( V_187 L_7 , V_186 , V_185 ) ;
V_54 . V_55 = 0 ;
}
}
}
void F_70 ( void )
{
struct V_44 * V_45 = F_71 ( V_46 . V_45 ) ;
if ( ! V_54 . V_68 && ! V_54 . V_55 )
return;
F_41 ( V_47 , ( unsigned long ) V_45 ) ;
}
