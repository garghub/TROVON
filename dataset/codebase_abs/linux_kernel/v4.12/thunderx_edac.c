static void F_1 ( char * V_1 , T_1 V_2 ,
const struct V_3 * V_4 ,
const T_2 V_5 )
{
int V_6 = 0 ;
while ( V_4 -> type && V_4 -> V_7 && V_4 -> V_4 ) {
if ( V_5 & V_4 -> V_7 ) {
V_6 = snprintf ( V_1 , V_2 , L_1 ,
V_4 -> type == V_8 ?
L_2 : L_3 ,
V_4 -> V_4 ) ;
V_1 += V_6 ;
V_2 -= V_6 ;
}
V_4 ++ ;
}
}
static unsigned long F_2 ( unsigned long V_9 , int V_10 , int V_11 )
{
return ( V_9 >> V_10 ) & ( ( 1 << V_11 ) - 1 ) ;
}
static T_3 F_3 ( struct V_12 * V_12 ,
const char T_4 * V_9 ,
T_1 V_13 , T_5 * V_14 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_6 V_18 ;
int V_19 ;
V_19 = F_4 ( V_9 , V_13 , 0 , & V_18 ) ;
if ( ! V_19 ) {
F_5 ( V_18 , V_16 -> V_20 + V_21 ) ;
V_19 = V_13 ;
}
return V_19 ;
}
static T_3 F_6 ( struct V_12 * V_12 ,
char T_4 * V_9 ,
T_1 V_13 , T_5 * V_14 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
char V_22 [ 20 ] ;
T_6 V_23 = F_7 ( V_16 -> V_20 + V_24 ) ;
snprintf ( V_22 , sizeof( V_22 ) , L_4 , V_23 ) ;
return F_8 ( V_9 , V_13 , V_14 , V_22 , sizeof( V_22 ) ) ;
}
static int F_9 ( void * V_25 )
{
struct V_15 * V_16 = V_25 ;
T_7 V_26 , V_27 ;
unsigned int V_28 = F_10 () ;
const unsigned int V_29 = V_30 / V_28 ;
unsigned int V_31 , V_32 ;
V_26 = ( T_7 ) F_11 ( V_16 -> V_33 ) ;
V_27 = ( T_7 ) F_12 ( V_16 -> V_33 ) ;
V_32 = ( V_27 & 0x7f ) >> 4 ;
V_16 -> V_34 &= ~ ( 7ULL << 8 ) ;
V_16 -> V_34 |= ( V_32 << 8 ) ;
F_5 ( V_16 -> V_35 , V_16 -> V_20 + V_36 ) ;
F_5 ( V_16 -> V_37 , V_16 -> V_20 + V_38 ) ;
F_5 ( V_16 -> V_34 , V_16 -> V_20 + V_39 ) ;
F_7 ( V_16 -> V_20 + V_36 ) ;
F_7 ( V_16 -> V_20 + V_38 ) ;
F_7 ( V_16 -> V_20 + V_39 ) ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ ) {
memset ( ( void * ) V_26 , V_40 , V_28 ) ;
F_13 () ;
asm volatile("dc civac, %0\n"
"dsb sy\n"
: : "r"(addr + i * cline_size));
}
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ ) {
__asm__ volatile("sys #0,c11,C1,#2, %0\n"
: : "r"(phys + i * cline_size));
}
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ ) {
__asm__ volatile("sys #0,c11,C1,#1, %0"
: : "r"(phys + i * cline_size));
}
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ ) {
asm volatile("dc ivac, %0\n"
"dsb sy\n"
: : "r"(addr + i * cline_size));
}
return 0 ;
}
static T_3 F_14 ( struct V_12 * V_12 ,
const char T_4 * V_9 ,
T_1 V_13 , T_5 * V_14 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned int V_28 = F_10 () ;
T_8 V_41 [ V_28 ] ;
void T_9 * V_26 ;
unsigned int V_42 , V_43 = 100000 ;
F_15 ( & V_16 -> V_44 , 0 ) ;
V_16 -> V_33 = F_16 ( V_16 -> V_45 , V_46 , 0 ) ;
if ( ! V_16 -> V_33 )
return - V_47 ;
V_26 = F_11 ( V_16 -> V_33 ) ;
while ( ! F_17 ( & V_16 -> V_44 ) && V_43 -- ) {
F_18 ( F_9 , V_16 , NULL ) ;
for ( V_42 = 0 ; V_42 < V_30 ; V_42 += sizeof( V_41 ) ) {
memcpy ( V_41 , V_26 + V_42 , V_28 ) ;
asm volatile("dsb ld\n");
}
}
F_19 ( V_16 -> V_33 , 0 ) ;
return V_13 ;
}
static int F_20 ( struct V_48 * V_49 ,
struct V_50 * V_51 [] ,
void * V_9 ,
T_1 V_52 )
{
int V_31 ;
struct V_48 * V_53 ;
if ( ! F_21 ( V_54 ) )
return 0 ;
if ( ! V_49 )
return - V_55 ;
for ( V_31 = 0 ; V_31 < V_52 ; V_31 ++ ) {
V_53 = F_22 ( V_51 [ V_31 ] -> V_56 , V_51 [ V_31 ] -> V_57 ,
V_49 , V_9 , & V_51 [ V_31 ] -> V_58 ) ;
if ( ! V_53 )
break;
}
return V_31 ;
}
static T_10 F_23 ( T_6 V_59 , struct V_15 * V_16 )
{
T_10 V_26 = 0 ;
int V_60 , V_61 ;
V_26 |= V_16 -> V_45 << 40 ;
V_26 |= F_24 ( V_59 ) << V_16 -> V_62 ;
V_26 |= F_25 ( V_59 ) << V_16 -> V_63 ;
V_26 |= F_26 ( V_59 ) << V_16 -> V_64 ;
V_26 |= ( F_27 ( V_59 ) >> 4 ) << V_16 -> V_65 ;
V_60 = F_28 ( V_59 ) << V_16 -> V_66 ;
if ( V_16 -> V_67 )
V_60 ^= F_2 ( V_26 , 12 + V_16 -> V_61 , V_16 -> V_68 ) ;
V_26 |= V_60 << V_16 -> V_66 ;
V_61 = F_29 ( V_16 -> V_69 -> V_70 ) ;
if ( V_16 -> V_71 )
V_61 ^= F_2 ( V_26 , 20 , V_16 -> V_61 ) ^
F_2 ( V_26 , 12 , V_16 -> V_61 ) ;
V_26 |= V_61 << 7 ;
return V_26 ;
}
static unsigned int F_30 ( unsigned int V_45 )
{
unsigned int V_72 = 0 ;
struct V_73 * V_69 = NULL ;
do {
V_69 = F_31 ( V_74 ,
V_75 ,
V_69 ) ;
if ( V_69 ) {
#ifdef F_32
if ( V_69 -> V_76 . V_77 == V_45 )
V_72 ++ ;
#else
V_72 ++ ;
#endif
}
} while ( V_69 );
return V_72 ;
}
static T_11 F_33 ( int V_78 , void * V_79 )
{
struct V_80 * V_81 = V_79 ;
struct V_15 * V_16 = V_81 -> V_82 ;
unsigned long V_83 = F_34 ( V_16 -> V_84 , F_35 ( V_16 -> V_85 ) ) ;
struct V_86 * V_87 = & V_16 -> V_85 [ V_83 ] ;
F_5 ( 0 , V_16 -> V_20 + V_36 ) ;
F_5 ( 0 , V_16 -> V_20 + V_38 ) ;
F_5 ( 0x2 , V_16 -> V_20 + V_39 ) ;
V_87 -> V_88 = F_7 ( V_16 -> V_20 + V_24 ) ;
V_87 -> V_89 = F_7 ( V_16 -> V_20 + V_90 ) ;
V_87 -> V_91 = F_7 ( V_16 -> V_20 + V_92 ) ;
V_87 -> V_93 = F_7 ( V_16 -> V_20 + V_94 ) ;
V_87 -> V_95 = F_7 ( V_16 -> V_20 + V_96 ) ;
V_16 -> V_84 ++ ;
F_15 ( & V_16 -> V_44 , 1 ) ;
F_5 ( V_87 -> V_88 , V_16 -> V_20 + V_24 ) ;
return V_97 ;
}
static T_11 F_36 ( int V_78 , void * V_79 )
{
struct V_80 * V_81 = V_79 ;
struct V_15 * V_16 = V_81 -> V_82 ;
T_10 V_98 ;
unsigned long V_99 ;
struct V_86 * V_87 ;
T_11 V_6 = V_100 ;
char * V_101 ;
char * V_102 ;
V_101 = F_37 ( V_103 , V_46 ) ;
V_102 = F_37 ( V_104 , V_46 ) ;
if ( ! V_101 || ! V_102 )
goto V_105;
while ( F_38 ( V_16 -> V_84 , V_16 -> V_106 ,
F_35 ( V_16 -> V_85 ) ) ) {
V_99 = F_34 ( V_16 -> V_106 , F_35 ( V_16 -> V_85 ) ) ;
V_87 = & V_16 -> V_85 [ V_99 ] ;
F_39 ( & V_16 -> V_69 -> V_76 , L_5 ,
V_87 -> V_88 ) ;
F_39 ( & V_16 -> V_69 -> V_76 , L_6 ,
V_87 -> V_89 ) ;
F_39 ( & V_16 -> V_69 -> V_76 , L_7 ,
V_87 -> V_91 ) ;
F_39 ( & V_16 -> V_69 -> V_76 , L_8 ,
V_87 -> V_93 ) ;
F_39 ( & V_16 -> V_69 -> V_76 , L_9 ,
V_87 -> V_95 ) ;
snprintf ( V_101 , V_103 ,
L_10 ,
F_24 ( V_87 -> V_93 ) ,
F_25 ( V_87 -> V_93 ) ,
F_28 ( V_87 -> V_93 ) ,
F_26 ( V_87 -> V_93 ) ,
F_27 ( V_87 -> V_93 ) ) ;
F_1 ( V_102 , V_104 , V_107 ,
V_87 -> V_88 ) ;
V_98 = F_23 ( V_87 -> V_89 , V_16 ) ;
if ( V_87 -> V_88 & V_108 )
F_40 ( V_109 , V_81 , 1 ,
F_41 ( V_98 ) ,
F_42 ( V_98 ) ,
0 , - 1 , - 1 , - 1 , V_101 , V_102 ) ;
else if ( V_87 -> V_88 & V_110 )
F_40 ( V_111 , V_81 , 1 ,
F_41 ( V_98 ) ,
F_42 ( V_98 ) ,
0 , - 1 , - 1 , - 1 , V_101 , V_102 ) ;
V_16 -> V_106 ++ ;
}
V_6 = V_112 ;
V_105:
F_43 ( V_101 ) ;
F_43 ( V_102 ) ;
return V_6 ;
}
static int F_44 ( struct V_73 * V_69 , T_12 V_113 )
{
F_45 ( V_69 ) ;
F_46 ( V_69 ) ;
F_47 ( V_69 , F_48 ( V_69 , V_113 ) ) ;
return 0 ;
}
static int F_49 ( struct V_73 * V_69 )
{
F_47 ( V_69 , V_114 ) ;
F_50 ( V_69 , V_114 , 0 ) ;
F_51 ( V_69 ) ;
return 0 ;
}
static inline int F_52 ( struct V_73 * V_69 )
{
int V_45 = F_53 ( & V_69 -> V_76 ) ;
int V_6 = F_29 ( V_69 -> V_70 ) ;
V_6 += F_54 ( V_45 , 0 ) << 3 ;
return V_6 ;
}
static int F_55 ( struct V_73 * V_69 ,
const struct V_115 * V_116 )
{
struct V_15 * V_16 ;
struct V_117 V_118 ;
struct V_80 * V_81 ;
T_6 V_119 , V_120 , V_121 ;
int V_6 ;
T_6 V_23 ;
void * V_122 ;
V_118 . type = V_123 ;
V_118 . V_2 = 2 ;
V_118 . V_124 = false ;
V_6 = F_56 ( V_69 ) ;
if ( V_6 ) {
F_57 ( & V_69 -> V_76 , L_11 , V_6 ) ;
return V_6 ;
}
V_6 = F_58 ( V_69 , F_59 ( 0 ) , L_12 ) ;
if ( V_6 ) {
F_57 ( & V_69 -> V_76 , L_13 , V_6 ) ;
return V_6 ;
}
V_81 = F_60 ( F_52 ( V_69 ) , 1 , & V_118 ,
sizeof( struct V_15 ) ) ;
if ( ! V_81 )
return - V_47 ;
V_81 -> V_69 = & V_69 -> V_76 ;
V_16 = V_81 -> V_82 ;
F_61 ( V_69 , V_81 ) ;
V_16 -> V_20 = F_62 ( V_69 ) [ 0 ] ;
V_119 = F_7 ( V_16 -> V_20 + V_125 ) ;
V_120 = F_7 ( V_16 -> V_20 + V_126 ) ;
V_121 = F_7 ( V_16 -> V_20 + V_127 ) ;
if ( V_119 & V_128 ) {
V_81 -> V_129 = F_63 ( V_130 ,
V_120 ) ?
V_131 : V_132 ;
} else {
V_81 -> V_129 = F_63 ( V_130 ,
V_120 ) ?
V_133 : V_134 ;
}
V_81 -> V_135 = V_136 | V_137 ;
V_81 -> V_138 = V_137 ;
V_81 -> V_139 = L_14 ;
V_81 -> V_140 = L_15 ;
V_81 -> V_141 = L_14 ;
V_81 -> V_142 = V_142 ( & V_69 -> V_76 ) ;
V_81 -> V_143 = V_144 ;
V_16 -> V_69 = V_69 ;
V_16 -> V_145 . V_146 = 0 ;
V_16 -> V_84 = 0 ;
V_16 -> V_106 = 0 ;
V_6 = F_64 ( V_69 , & V_16 -> V_145 , 1 ) ;
if ( V_6 ) {
F_57 ( & V_69 -> V_76 , L_16 , V_6 ) ;
goto V_105;
}
V_6 = F_65 ( & V_69 -> V_76 , V_16 -> V_145 . V_147 ,
F_33 ,
F_36 , 0 ,
L_17 , V_81 ) ;
if ( V_6 ) {
F_57 ( & V_69 -> V_76 , L_18 , V_6 ) ;
goto V_105;
}
V_16 -> V_45 = F_63 ( V_148 , F_66 ( V_69 , 0 ) ) ;
V_16 -> V_61 = F_30 ( V_16 -> V_45 ) >> 1 ;
V_16 -> V_68 = ( F_63 ( V_130 , V_120 ) &&
F_63 ( V_149 , V_121 ) ) ? 4 : 3 ;
V_16 -> V_150 = ( V_121 >> 5 ) & 0xf ;
V_16 -> V_62 = 28 + V_16 -> V_150 + V_16 -> V_61 ;
V_16 -> V_63 = V_16 -> V_62 ;
V_16 -> V_63 -= F_63 ( V_151 , V_121 ) ? 1 : 0 ;
V_16 -> V_66 = 7 + V_16 -> V_61 ;
V_16 -> V_64 = 14 + F_67 ( V_121 ) + V_16 -> V_61 ;
V_16 -> V_65 = V_16 -> V_66 + V_16 -> V_68 ;
V_16 -> V_67 = V_119 & V_152 ;
V_122 = F_68 ( V_153 | F_69 ( V_148 , V_16 -> V_45 ) ,
V_30 ) ;
if ( ! V_122 ) {
F_57 ( & V_69 -> V_76 , L_19 ) ;
goto V_105;
}
V_16 -> V_71 = ! ( F_7 ( V_122 ) & V_154 ) ;
F_70 ( V_122 ) ;
V_6 = F_71 ( V_81 ) ;
if ( V_6 ) {
F_57 ( & V_69 -> V_76 , L_20 , V_6 ) ;
goto V_105;
}
V_23 = F_7 ( V_16 -> V_20 + V_24 ) ;
F_5 ( V_23 , V_16 -> V_20 + V_24 ) ;
F_5 ( V_155 , V_16 -> V_20 + V_156 ) ;
if ( F_21 ( V_54 ) ) {
V_6 = F_20 ( V_81 -> V_157 ,
V_158 ,
V_16 ,
F_35 ( V_158 ) ) ;
if ( V_6 != F_35 ( V_158 ) ) {
F_72 ( & V_69 -> V_76 , L_21 ,
V_6 , V_6 >= 0 ? L_22 : L_23 ) ;
}
}
return 0 ;
V_105:
F_61 ( V_69 , NULL ) ;
F_73 ( V_81 ) ;
return V_6 ;
}
static void F_74 ( struct V_73 * V_69 )
{
struct V_80 * V_81 = F_75 ( V_69 ) ;
struct V_15 * V_16 = V_81 -> V_82 ;
F_5 ( V_155 , V_16 -> V_20 + V_159 ) ;
F_76 ( & V_69 -> V_76 ) ;
F_73 ( V_81 ) ;
}
static T_11 F_77 ( int V_78 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
struct V_163 * V_164 = F_78 ( V_162 , struct V_163 ,
V_145 [ V_162 -> V_146 ] ) ;
int V_165 ;
unsigned long V_83 = F_34 ( V_164 -> V_166 ,
F_35 ( V_164 -> V_167 ) ) ;
struct V_168 * V_87 = & V_164 -> V_167 [ V_83 ] ;
V_87 -> V_169 = F_7 ( V_164 -> V_20 + V_170 ) ;
for ( V_165 = 0 ; V_165 < V_171 ; V_165 ++ ) {
V_87 -> V_172 [ V_165 ] =
F_7 ( V_164 -> V_20 + F_79 ( V_165 ) ) ;
V_87 -> V_173 [ V_165 ] =
F_7 ( V_164 -> V_20 + F_80 ( V_165 , 11 ) ) ;
F_5 ( V_87 -> V_172 [ V_165 ] , V_164 -> V_20 + F_79 ( V_165 ) ) ;
}
F_5 ( V_87 -> V_169 , V_164 -> V_20 + V_170 ) ;
V_164 -> V_166 ++ ;
return V_97 ;
}
static T_11 F_81 ( int V_78 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
struct V_163 * V_164 = F_78 ( V_162 , struct V_163 ,
V_145 [ V_162 -> V_146 ] ) ;
T_11 V_6 = V_100 ;
unsigned long V_99 ;
struct V_168 * V_87 ;
int V_165 ;
char * V_101 ;
char * V_102 ;
V_101 = F_37 ( V_174 , V_46 ) ;
V_102 = F_37 ( V_175 , V_46 ) ;
if ( ! V_101 || ! V_102 )
goto V_105;
while ( F_38 ( V_164 -> V_166 , V_164 -> V_176 ,
F_35 ( V_164 -> V_167 ) ) ) {
V_99 = F_34 ( V_164 -> V_176 ,
F_35 ( V_164 -> V_167 ) ) ;
V_87 = & V_164 -> V_167 [ V_99 ] ;
snprintf ( V_101 , V_174 , L_24 ,
V_164 -> V_177 -> V_141 , V_87 -> V_169 ) ;
F_1 ( V_102 , V_175 ,
V_178 , V_87 -> V_169 ) ;
strncat ( V_101 , V_102 , V_174 ) ;
for ( V_165 = 0 ; V_165 < V_171 ; V_165 ++ )
if ( V_87 -> V_169 & F_59 ( V_165 ) ) {
snprintf ( V_102 , V_175 ,
L_25 ,
V_165 , V_87 -> V_172 [ V_165 ] ,
V_165 , V_87 -> V_173 [ V_165 ] ) ;
strncat ( V_101 , V_102 , V_174 ) ;
F_1 ( V_102 , V_175 ,
V_179 ,
V_87 -> V_172 [ V_165 ] ) ;
strncat ( V_101 , V_102 , V_174 ) ;
}
if ( V_87 -> V_169 & V_180 )
F_82 ( V_164 -> V_177 , 0 , 0 , V_101 ) ;
V_164 -> V_176 ++ ;
}
V_6 = V_112 ;
V_105:
F_43 ( V_102 ) ;
F_43 ( V_101 ) ;
return V_6 ;
}
static T_11 F_83 ( int V_78 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
struct V_163 * V_164 = F_78 ( V_162 , struct V_163 ,
V_145 [ V_162 -> V_146 ] ) ;
unsigned long V_83 = F_34 ( V_164 -> V_181 ,
F_35 ( V_164 -> V_182 ) ) ;
struct V_183 * V_87 = & V_164 -> V_182 [ V_83 ] ;
V_87 -> V_184 = V_162 -> V_146 ;
V_87 -> V_185 = F_7 ( V_164 -> V_20 + F_84 ( V_87 -> V_184 ) ) ;
F_5 ( V_87 -> V_185 , V_164 -> V_20 + F_84 ( V_87 -> V_184 ) ) ;
V_164 -> V_181 ++ ;
return V_97 ;
}
static T_11 F_85 ( int V_78 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
struct V_163 * V_164 = F_78 ( V_162 , struct V_163 ,
V_145 [ V_162 -> V_146 ] ) ;
T_11 V_6 = V_100 ;
unsigned long V_99 ;
struct V_183 * V_87 ;
char * V_101 ;
char * V_102 ;
V_101 = F_37 ( V_174 , V_46 ) ;
V_102 = F_37 ( V_175 , V_46 ) ;
if ( ! V_101 || ! V_102 )
goto V_105;
while ( F_38 ( V_164 -> V_181 , V_164 -> V_186 ,
F_35 ( V_164 -> V_182 ) ) ) {
V_99 = F_34 ( V_164 -> V_181 ,
F_35 ( V_164 -> V_182 ) ) ;
V_87 = & V_164 -> V_182 [ V_99 ] ;
snprintf ( V_101 , V_174 ,
L_26 ,
V_164 -> V_177 -> V_141 ,
V_87 -> V_184 , V_87 -> V_185 ) ;
F_1 ( V_102 , V_175 ,
V_187 , V_87 -> V_185 ) ;
strncat ( V_101 , V_102 , V_174 ) ;
if ( V_87 -> V_185 & V_188 )
F_86 ( V_164 -> V_177 , 0 , 0 , V_101 ) ;
else if ( V_87 -> V_185 & V_189 )
F_82 ( V_164 -> V_177 , 0 , 0 , V_101 ) ;
V_164 -> V_186 ++ ;
}
V_6 = V_112 ;
V_105:
F_43 ( V_102 ) ;
F_43 ( V_101 ) ;
return V_6 ;
}
static void F_87 ( struct V_163 * V_164 )
{
int V_165 , V_190 , V_191 ;
for ( V_165 = 0 ; V_165 < V_171 ; V_165 ++ ) {
V_191 = F_7 ( V_164 -> V_20 + F_88 ( V_165 ) ) ;
V_191 |= V_192 ;
V_191 &= ~ V_193 ;
F_5 ( V_191 , V_164 -> V_20 + F_88 ( V_165 ) ) ;
for ( V_190 = 0 ; V_190 < V_194 ; V_190 ++ )
F_7 ( V_164 -> V_20 + F_80 ( V_165 , V_190 ) ) ;
}
}
static int F_89 ( struct V_73 * V_69 ,
const struct V_115 * V_116 )
{
struct V_163 * V_164 ;
struct V_195 * V_177 ;
char V_56 [ 32 ] ;
int V_196 ;
int V_31 ;
int V_6 ;
T_6 V_5 ;
V_6 = F_56 ( V_69 ) ;
if ( V_6 ) {
F_57 ( & V_69 -> V_76 , L_11 , V_6 ) ;
return V_6 ;
}
V_6 = F_58 ( V_69 , F_59 ( 0 ) , L_27 ) ;
if ( V_6 ) {
F_57 ( & V_69 -> V_76 , L_13 , V_6 ) ;
return V_6 ;
}
V_196 = F_90 () ;
snprintf ( V_56 , sizeof( V_56 ) , L_28 , V_196 ) ;
V_177 = F_91 ( sizeof( struct V_163 ) ,
V_56 , 1 , L_29 , 1 ,
0 , NULL , 0 , V_196 ) ;
if ( ! V_177 ) {
F_57 ( & V_69 -> V_76 , L_30 , V_6 ) ;
return - V_47 ;
}
V_164 = V_177 -> V_82 ;
V_164 -> V_177 = V_177 ;
V_164 -> V_166 = 0 ;
V_164 -> V_176 = 0 ;
V_164 -> V_181 = 0 ;
V_164 -> V_186 = 0 ;
V_164 -> V_20 = F_62 ( V_69 ) [ 0 ] ;
if ( ! V_164 -> V_20 ) {
F_57 ( & V_69 -> V_76 , L_13 , V_6 ) ;
V_6 = - V_197 ;
goto V_105;
}
V_164 -> V_69 = V_69 ;
for ( V_31 = 0 ; V_31 < V_198 ; V_31 ++ ) {
V_164 -> V_145 [ V_31 ] . V_146 = V_31 ;
V_164 -> V_145 [ V_31 ] . V_147 = 0 ;
}
V_6 = F_64 ( V_69 , V_164 -> V_145 , V_198 ) ;
if ( V_6 ) {
F_57 ( & V_69 -> V_76 , L_16 , V_6 ) ;
goto V_105;
}
for ( V_31 = 0 ; V_31 < V_198 ; V_31 ++ ) {
V_6 = F_65 ( & V_69 -> V_76 ,
V_164 -> V_145 [ V_31 ] . V_147 ,
( V_31 == 3 ) ?
F_77 :
F_83 ,
( V_31 == 3 ) ?
F_81 :
F_85 ,
0 , L_31 ,
& V_164 -> V_145 [ V_31 ] ) ;
if ( V_6 )
goto V_105;
}
V_177 -> V_76 = & V_69 -> V_76 ;
V_177 -> V_142 = V_142 ( & V_69 -> V_76 ) ;
V_177 -> V_139 = L_32 ;
V_177 -> V_141 = L_32 ;
V_6 = F_92 ( V_177 ) ;
if ( V_6 ) {
F_57 ( & V_69 -> V_76 , L_33 , V_6 ) ;
goto V_105;
}
if ( F_21 ( V_54 ) ) {
V_164 -> V_157 = F_93 ( V_69 -> V_76 . V_199 . V_56 ) ;
V_6 = F_20 ( V_164 -> V_157 ,
V_200 ,
V_164 ,
F_35 ( V_200 ) ) ;
if ( V_6 != F_35 ( V_200 ) ) {
F_72 ( & V_69 -> V_76 , L_21 ,
V_6 , V_6 >= 0 ? L_22 : L_23 ) ;
}
}
F_61 ( V_69 , V_177 ) ;
F_87 ( V_164 ) ;
for ( V_31 = 0 ; V_31 < V_171 ; V_31 ++ ) {
F_5 ( V_201 ,
V_164 -> V_20 + F_94 ( V_31 ) ) ;
V_5 = F_7 ( V_164 -> V_20 + F_79 ( V_31 ) ) ;
F_5 ( V_5 , V_164 -> V_20 + F_79 ( V_31 ) ) ;
}
for ( V_31 = 0 ; V_31 < V_202 ; V_31 ++ ) {
V_5 = F_7 ( V_164 -> V_20 + F_84 ( V_31 ) ) ;
F_5 ( V_5 , V_164 -> V_20 + F_84 ( V_31 ) ) ;
F_5 ( V_203 ,
V_164 -> V_20 + F_95 ( V_31 ) ) ;
}
V_5 = F_7 ( V_164 -> V_20 + V_170 ) ;
F_5 ( V_5 , V_164 -> V_20 + V_170 ) ;
F_5 ( V_204 , V_164 -> V_20 + V_205 ) ;
return 0 ;
V_105:
F_96 ( V_177 ) ;
return V_6 ;
}
static void F_97 ( struct V_73 * V_69 )
{
struct V_195 * V_177 = F_75 ( V_69 ) ;
struct V_163 * V_164 = V_177 -> V_82 ;
int V_31 ;
F_5 ( V_204 , V_164 -> V_20 + V_206 ) ;
for ( V_31 = 0 ; V_31 < V_198 ; V_31 ++ ) {
F_5 ( V_203 ,
V_164 -> V_20 + F_98 ( V_31 ) ) ;
}
F_99 ( V_164 -> V_157 ) ;
F_100 ( & V_69 -> V_76 ) ;
F_96 ( V_177 ) ;
}
static T_11 F_101 ( int V_78 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
struct V_207 * V_208 = F_78 ( V_162 , struct V_207 ,
V_145 ) ;
unsigned long V_83 = F_34 ( V_208 -> V_84 , F_35 ( V_208 -> V_85 ) ) ;
struct V_209 * V_87 = & V_208 -> V_85 [ V_83 ] ;
V_87 -> V_88 = F_7 ( V_208 -> V_20 + V_210 ) ;
if ( V_87 -> V_88 & V_211 ) {
V_87 -> V_212 = L_34 ;
V_87 -> V_213 = F_7 ( V_208 -> V_20 + V_214 ) ;
} else if ( V_87 -> V_88 & V_215 ) {
V_87 -> V_212 = L_35 ;
V_87 -> V_213 = F_7 ( V_208 -> V_20 + V_216 ) ;
} else if ( V_87 -> V_88 & V_217 ) {
V_87 -> V_212 = L_36 ;
V_87 -> V_213 = F_7 ( V_208 -> V_20 + V_218 ) ;
} else if ( V_87 -> V_88 & V_219 ) {
V_87 -> V_212 = L_37 ;
V_87 -> V_213 = F_7 ( V_208 -> V_20 + V_220 ) ;
}
F_5 ( V_87 -> V_88 , V_208 -> V_20 + V_210 ) ;
V_208 -> V_84 ++ ;
return V_97 ;
}
static T_11 F_102 ( int V_78 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
struct V_207 * V_221 = F_78 ( V_162 , struct V_207 ,
V_145 ) ;
unsigned long V_83 = F_34 ( V_221 -> V_84 , F_35 ( V_221 -> V_85 ) ) ;
struct V_209 * V_87 = & V_221 -> V_85 [ V_83 ] ;
V_87 -> V_88 = F_7 ( V_221 -> V_20 + V_222 ) ;
if ( V_87 -> V_88 & V_223 ) {
V_87 -> V_212 = L_38 ;
V_87 -> V_213 = F_7 ( V_221 -> V_20 + V_224 ) ;
} else if ( V_87 -> V_88 & V_225 ) {
V_87 -> V_212 = L_39 ;
V_87 -> V_213 = F_7 ( V_221 -> V_20 + V_226 ) ;
} else if ( V_87 -> V_88 & V_227 ) {
V_87 -> V_212 = L_40 ;
V_87 -> V_213 = F_7 ( V_221 -> V_20 + V_228 ) ;
}
F_5 ( V_87 -> V_88 , V_221 -> V_20 + V_222 ) ;
V_221 -> V_84 ++ ;
return V_97 ;
}
static T_11 F_103 ( int V_78 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
struct V_207 * V_81 = F_78 ( V_162 , struct V_207 ,
V_145 ) ;
unsigned long V_83 = F_34 ( V_81 -> V_84 , F_35 ( V_81 -> V_85 ) ) ;
struct V_209 * V_87 = & V_81 -> V_85 [ V_83 ] ;
V_87 -> V_88 = F_7 ( V_81 -> V_20 + V_229 ) ;
V_87 -> V_213 = F_7 ( V_81 -> V_20 + V_230 ) ;
F_5 ( V_87 -> V_88 , V_81 -> V_20 + V_229 ) ;
V_87 -> V_212 = L_37 ;
V_81 -> V_84 ++ ;
return V_97 ;
}
static T_11 F_104 ( int V_78 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
struct V_207 * V_231 = F_78 ( V_162 , struct V_207 ,
V_145 ) ;
unsigned long V_99 = F_34 ( V_231 -> V_106 , F_35 ( V_231 -> V_85 ) ) ;
struct V_209 * V_87 = & V_231 -> V_85 [ V_99 ] ;
T_11 V_6 = V_100 ;
T_6 V_232 , V_233 ;
const struct V_3 * V_234 ;
char * V_235 ;
char * V_101 ;
char * V_102 ;
V_101 = F_37 ( V_174 , V_46 ) ;
V_102 = F_37 ( V_175 , V_46 ) ;
if ( ! V_101 || ! V_102 )
goto V_105;
switch ( V_231 -> V_69 -> V_236 ) {
case V_237 :
V_235 = L_41 ;
V_232 = V_238 ;
V_233 = V_239 ;
V_234 = V_240 ;
break;
case V_241 :
V_235 = L_42 ;
V_232 = V_242 ;
V_233 = V_243 ;
V_234 = V_244 ;
break;
case V_245 :
V_235 = L_43 ;
V_232 = V_246 ;
V_233 = V_247 ;
V_234 = V_248 ;
break;
default:
F_57 ( & V_231 -> V_69 -> V_76 , L_44 ,
V_231 -> V_69 -> V_236 ) ;
return V_100 ;
}
while ( F_38 ( V_231 -> V_84 , V_231 -> V_106 ,
F_35 ( V_231 -> V_85 ) ) ) {
snprintf ( V_101 , V_249 ,
L_45 ,
V_231 -> V_177 -> V_141 , V_235 , V_87 -> V_88 ,
V_87 -> V_212 , V_87 -> V_213 ) ;
F_1 ( V_102 , V_250 , V_234 , V_87 -> V_88 ) ;
strncat ( V_101 , V_102 , V_249 ) ;
if ( V_87 -> V_88 & V_232 )
F_86 ( V_231 -> V_177 , 0 , 0 , V_101 ) ;
else if ( V_87 -> V_88 & V_233 )
F_82 ( V_231 -> V_177 , 0 , 0 , V_101 ) ;
V_231 -> V_106 ++ ;
}
return V_112 ;
V_105:
F_43 ( V_102 ) ;
F_43 ( V_101 ) ;
return V_6 ;
}
static int F_105 ( struct V_73 * V_69 ,
const struct V_115 * V_116 )
{
struct V_207 * V_231 ;
struct V_195 * V_177 ;
struct V_50 * * V_251 ;
T_1 V_252 ;
T_11 (* F_106)( int , void * ) = NULL ;
char V_56 [ 32 ] ;
const char * V_253 ;
T_6 V_254 , V_255 ;
int V_196 ;
int V_6 ;
V_6 = F_56 ( V_69 ) ;
if ( V_6 ) {
F_57 ( & V_69 -> V_76 , L_11 , V_6 ) ;
return V_6 ;
}
V_6 = F_58 ( V_69 , F_59 ( 0 ) , L_46 ) ;
if ( V_6 ) {
F_57 ( & V_69 -> V_76 , L_13 , V_6 ) ;
return V_6 ;
}
switch ( V_69 -> V_236 ) {
case V_237 :
F_106 = F_101 ;
V_251 = V_256 ;
V_252 = F_35 ( V_256 ) ;
V_253 = L_47 ;
V_254 = V_257 ;
V_255 = V_258 ;
break;
case V_241 :
F_106 = F_102 ;
V_251 = V_259 ;
V_252 = F_35 ( V_259 ) ;
V_253 = L_48 ;
V_254 = V_260 ;
V_255 = V_261 ;
break;
case V_245 :
F_106 = F_103 ;
V_251 = V_262 ;
V_252 = F_35 ( V_262 ) ;
V_253 = L_49 ;
V_254 = V_263 ;
V_255 = V_264 ;
break;
default:
F_57 ( & V_69 -> V_76 , L_50 ,
V_69 -> V_236 ) ;
return - V_265 ;
}
V_196 = F_90 () ;
snprintf ( V_56 , sizeof( V_56 ) , V_253 , V_196 ) ;
V_177 = F_91 ( sizeof( struct V_207 ) ,
V_56 , 1 , L_51 , 1 , 0 ,
NULL , 0 , V_196 ) ;
if ( ! V_177 ) {
F_57 ( & V_69 -> V_76 , L_52 ) ;
return - V_47 ;
}
V_231 = V_177 -> V_82 ;
V_231 -> V_177 = V_177 ;
V_231 -> V_20 = F_62 ( V_69 ) [ 0 ] ;
if ( ! V_231 -> V_20 ) {
F_57 ( & V_69 -> V_76 , L_53 ) ;
V_6 = - V_197 ;
goto V_105;
}
V_231 -> V_69 = V_69 ;
V_231 -> V_84 = 0 ;
V_231 -> V_106 = 0 ;
V_231 -> V_145 . V_146 = 0 ;
V_231 -> V_145 . V_147 = 0 ;
V_6 = F_64 ( V_69 , & V_231 -> V_145 , 1 ) ;
if ( V_6 ) {
F_57 ( & V_69 -> V_76 , L_16 , V_6 ) ;
goto V_105;
}
V_6 = F_65 ( & V_69 -> V_76 , V_231 -> V_145 . V_147 ,
F_106 ,
F_104 ,
0 , L_54 ,
& V_231 -> V_145 ) ;
if ( V_6 )
goto V_105;
V_177 -> V_76 = & V_69 -> V_76 ;
V_177 -> V_142 = V_142 ( & V_69 -> V_76 ) ;
V_177 -> V_139 = L_55 ;
V_177 -> V_141 = L_55 ;
V_6 = F_92 ( V_177 ) ;
if ( V_6 ) {
F_57 ( & V_69 -> V_76 , L_33 , V_6 ) ;
goto V_105;
}
if ( F_21 ( V_54 ) ) {
V_231 -> V_157 = F_93 ( V_69 -> V_76 . V_199 . V_56 ) ;
F_20 ( V_231 -> V_157 , V_251 ,
V_231 , V_252 ) ;
if ( V_6 != V_252 ) {
F_72 ( & V_69 -> V_76 , L_21 ,
V_6 , V_6 >= 0 ? L_22 : L_23 ) ;
}
}
F_61 ( V_69 , V_177 ) ;
F_5 ( V_255 , V_231 -> V_20 + V_254 ) ;
return 0 ;
V_105:
F_96 ( V_177 ) ;
return V_6 ;
}
static void F_107 ( struct V_73 * V_69 )
{
struct V_195 * V_177 = F_75 ( V_69 ) ;
struct V_207 * V_231 = V_177 -> V_82 ;
switch ( V_69 -> V_236 ) {
case V_237 :
F_5 ( V_258 , V_231 -> V_20 + V_266 ) ;
break;
case V_241 :
F_5 ( V_261 , V_231 -> V_20 + V_267 ) ;
break;
case V_245 :
F_5 ( V_264 , V_231 -> V_20 + V_268 ) ;
break;
}
F_99 ( V_231 -> V_157 ) ;
F_100 ( & V_69 -> V_76 ) ;
F_96 ( V_177 ) ;
}
static int T_13 F_108 ( void )
{
int V_269 = 0 ;
V_269 = F_109 ( & V_270 ) ;
if ( V_269 )
return V_269 ;
V_269 = F_109 ( & V_271 ) ;
if ( V_269 )
goto V_272;
V_269 = F_109 ( & V_273 ) ;
if ( V_269 )
goto V_274;
return V_269 ;
V_274:
F_110 ( & V_271 ) ;
V_272:
F_110 ( & V_270 ) ;
return V_269 ;
}
static void T_14 F_111 ( void )
{
F_110 ( & V_273 ) ;
F_110 ( & V_271 ) ;
F_110 ( & V_270 ) ;
}
