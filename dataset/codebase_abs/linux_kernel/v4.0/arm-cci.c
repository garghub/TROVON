static bool F_1 ( int V_1 , int * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
if ( V_1 == V_2 [ V_4 ] )
return true ;
return false ;
}
static int F_2 ( void )
{
int V_5 ;
V_5 = F_3 ( V_6 + V_7 ) & V_8 ;
V_5 >>= V_9 ;
if ( V_5 < V_10 )
return V_11 ;
else
return V_12 ;
}
static struct V_13 * F_4 ( void )
{
int V_5 = F_2 () ;
return & V_14 [ V_5 ] ;
}
static int F_5 ( T_1 V_15 )
{
return V_16 -> V_17 -> V_18 <= V_15 &&
V_15 <= V_16 -> V_17 -> V_19 ;
}
static int F_6 ( T_1 V_15 )
{
return V_16 -> V_17 -> V_20 <= V_15 &&
V_15 <= V_16 -> V_17 -> V_21 ;
}
static int F_7 ( T_1 V_22 )
{
T_1 V_23 = F_8 ( V_22 ) ;
T_1 V_15 = F_9 ( V_22 ) ;
switch ( V_23 ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
if ( F_5 ( V_15 ) )
return V_22 ;
break;
case V_29 :
case V_30 :
case V_31 :
if ( F_6 ( V_15 ) )
return V_22 ;
break;
}
return - V_32 ;
}
static int F_10 ( struct V_33 * V_33 , int V_34 )
{
return V_35 <= V_34 &&
V_34 <= F_11 ( V_33 ) ;
}
static T_2 F_12 ( int V_34 , unsigned int V_36 )
{
return F_3 ( V_16 -> V_37 + F_13 ( V_34 ) + V_36 ) ;
}
static void F_14 ( T_2 V_38 , int V_34 , unsigned int V_36 )
{
return F_15 ( V_38 , V_16 -> V_37 + F_13 ( V_34 ) + V_36 ) ;
}
static void F_16 ( int V_34 )
{
F_14 ( 0 , V_34 , V_39 ) ;
}
static void F_17 ( int V_34 )
{
F_14 ( 1 , V_34 , V_39 ) ;
}
static void F_18 ( int V_34 , unsigned long V_40 )
{
V_40 &= V_41 ;
F_14 ( V_40 , V_34 , V_42 ) ;
}
static T_2 F_19 ( void )
{
T_2 V_43 = ( F_3 ( V_6 + V_44 ) &
V_45 ) >> V_46 ;
return V_43 + 1 ;
}
static int F_20 ( struct V_47 * V_48 , struct V_49 * V_40 )
{
struct V_33 * V_33 = F_21 ( V_40 -> V_16 ) ;
struct V_50 * V_22 = & V_40 -> V_48 ;
unsigned long V_51 = V_22 -> V_52 & V_41 ;
int V_34 ;
if ( V_51 == V_53 ) {
if ( F_22 ( V_35 , V_48 -> V_54 ) )
return - V_55 ;
return V_35 ;
}
for ( V_34 = V_56 ; V_34 <= F_11 ( V_33 ) ; ++ V_34 )
if ( ! F_22 ( V_34 , V_48 -> V_54 ) )
return V_34 ;
return - V_55 ;
}
static int F_23 ( struct V_49 * V_40 )
{
int V_57 ;
T_1 V_58 = V_40 -> V_59 . V_58 & V_41 ;
if ( V_40 -> V_59 . type < V_60 )
return - V_32 ;
if ( V_58 == V_53 )
V_57 = V_58 ;
else
V_57 = F_7 ( V_58 ) ;
return V_57 ;
}
static int F_24 ( struct V_33 * V_33 , T_3 V_61 )
{
int V_4 ;
struct V_62 * V_63 = V_33 -> V_64 ;
if ( F_25 ( ! V_63 ) )
return - V_65 ;
if ( V_16 -> V_3 < 1 ) {
F_26 ( & V_63 -> V_66 , L_1 ) ;
return - V_65 ;
}
for ( V_4 = 0 ; V_4 < V_16 -> V_3 ; V_4 ++ ) {
int V_67 = F_27 ( V_16 -> V_2 [ V_4 ] , V_61 , V_68 ,
L_2 , V_33 ) ;
if ( V_67 ) {
F_26 ( & V_63 -> V_66 , L_3 ,
V_16 -> V_2 [ V_4 ] ) ;
return V_67 ;
}
F_28 ( V_4 , & V_16 -> V_69 ) ;
}
return 0 ;
}
static void F_29 ( struct V_33 * V_33 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_16 -> V_3 ; V_4 ++ ) {
if ( ! F_30 ( V_4 , & V_16 -> V_69 ) )
continue;
F_31 ( V_16 -> V_2 [ V_4 ] , V_33 ) ;
}
}
static T_2 F_32 ( struct V_49 * V_40 )
{
struct V_33 * V_33 = F_21 ( V_40 -> V_16 ) ;
struct V_50 * V_70 = & V_40 -> V_48 ;
int V_34 = V_70 -> V_34 ;
T_2 V_38 ;
if ( F_25 ( ! F_10 ( V_33 , V_34 ) ) ) {
F_26 ( & V_33 -> V_64 -> V_66 , L_4 , V_34 ) ;
return 0 ;
}
V_38 = F_12 ( V_34 , V_71 ) ;
return V_38 ;
}
static void F_33 ( struct V_49 * V_40 , T_2 V_38 )
{
struct V_33 * V_33 = F_21 ( V_40 -> V_16 ) ;
struct V_50 * V_70 = & V_40 -> V_48 ;
int V_34 = V_70 -> V_34 ;
if ( F_25 ( ! F_10 ( V_33 , V_34 ) ) )
F_26 ( & V_33 -> V_64 -> V_66 , L_4 , V_34 ) ;
else
F_14 ( V_38 , V_34 , V_71 ) ;
}
static T_4 F_34 ( struct V_49 * V_40 )
{
struct V_50 * V_72 = & V_40 -> V_48 ;
T_4 V_73 , V_74 , V_75 ;
do {
V_74 = F_35 ( & V_72 -> V_76 ) ;
V_75 = F_32 ( V_40 ) ;
} while ( F_36 ( & V_72 -> V_76 , V_74 ,
V_75 ) != V_74 );
V_73 = ( V_75 - V_74 ) & V_77 ;
F_37 ( V_73 , & V_40 -> V_78 ) ;
return V_75 ;
}
static void F_38 ( struct V_49 * V_40 )
{
F_34 ( V_40 ) ;
}
void F_39 ( struct V_49 * V_40 )
{
struct V_50 * V_72 = & V_40 -> V_48 ;
T_4 V_79 = 1ULL << 31 ;
F_40 ( & V_72 -> V_76 , V_79 ) ;
F_33 ( V_40 , V_79 ) ;
}
static T_5 F_41 ( int V_80 , void * V_66 )
{
unsigned long V_81 ;
struct V_33 * V_33 = V_66 ;
struct V_47 * V_82 = & V_16 -> V_83 ;
int V_34 , V_84 = V_85 ;
F_42 ( & V_82 -> V_86 , V_81 ) ;
for ( V_34 = V_35 ; V_34 <= F_11 ( V_33 ) ; V_34 ++ ) {
struct V_49 * V_40 = V_82 -> V_82 [ V_34 ] ;
struct V_50 * V_70 ;
if ( ! V_40 )
continue;
V_70 = & V_40 -> V_48 ;
if ( ! ( F_12 ( V_34 , V_87 ) &
V_88 ) )
continue;
F_14 ( V_88 , V_34 , V_87 ) ;
F_34 ( V_40 ) ;
F_39 ( V_40 ) ;
V_84 = V_89 ;
}
F_43 ( & V_82 -> V_86 , V_81 ) ;
return F_44 ( V_84 ) ;
}
static int F_45 ( struct V_33 * V_33 )
{
int V_90 = F_24 ( V_33 , F_41 ) ;
if ( V_90 ) {
F_29 ( V_33 ) ;
return V_90 ;
}
return 0 ;
}
static void F_46 ( struct V_33 * V_33 )
{
F_29 ( V_33 ) ;
}
static void F_47 ( struct V_49 * V_40 )
{
struct V_33 * V_33 = F_21 ( V_40 -> V_16 ) ;
T_6 * V_91 = & V_33 -> V_91 ;
struct V_92 * V_93 = & V_33 -> V_93 ;
if ( F_48 ( V_91 , V_93 ) ) {
F_46 ( V_33 ) ;
F_49 ( V_93 ) ;
}
}
static void F_50 ( struct V_16 * V_16 )
{
struct V_33 * V_33 = F_21 ( V_16 ) ;
struct V_47 * V_83 = & V_33 -> V_83 ;
int V_94 = F_51 ( V_83 -> V_54 , V_33 -> V_95 ) ;
unsigned long V_81 ;
T_2 V_79 ;
if ( ! V_94 )
return;
F_42 ( & V_83 -> V_86 , V_81 ) ;
V_79 = F_3 ( V_6 + V_44 ) | V_96 ;
F_52 ( V_79 , V_6 + V_44 ) ;
F_43 ( & V_83 -> V_86 , V_81 ) ;
}
static void F_53 ( struct V_16 * V_16 )
{
struct V_33 * V_33 = F_21 ( V_16 ) ;
struct V_47 * V_83 = & V_33 -> V_83 ;
unsigned long V_81 ;
T_2 V_79 ;
F_42 ( & V_83 -> V_86 , V_81 ) ;
V_79 = F_3 ( V_6 + V_44 ) & ~ V_96 ;
F_52 ( V_79 , V_6 + V_44 ) ;
F_43 ( & V_83 -> V_86 , V_81 ) ;
}
static void F_54 ( struct V_49 * V_40 , int V_97 )
{
struct V_33 * V_33 = F_21 ( V_40 -> V_16 ) ;
struct V_47 * V_83 = & V_33 -> V_83 ;
struct V_50 * V_72 = & V_40 -> V_48 ;
int V_34 = V_72 -> V_34 ;
unsigned long V_81 ;
if ( V_97 & V_98 )
F_55 ( ! ( V_72 -> V_99 & V_100 ) ) ;
V_72 -> V_99 = 0 ;
if ( F_25 ( ! F_10 ( V_33 , V_34 ) ) ) {
F_26 ( & V_33 -> V_64 -> V_66 , L_4 , V_34 ) ;
return;
}
F_42 ( & V_83 -> V_86 , V_81 ) ;
if ( V_34 != V_35 )
F_18 ( V_34 , V_72 -> V_52 ) ;
F_39 ( V_40 ) ;
F_17 ( V_34 ) ;
F_43 ( & V_83 -> V_86 , V_81 ) ;
}
static void F_56 ( struct V_49 * V_40 , int V_97 )
{
struct V_33 * V_33 = F_21 ( V_40 -> V_16 ) ;
struct V_50 * V_72 = & V_40 -> V_48 ;
int V_34 = V_72 -> V_34 ;
if ( V_72 -> V_99 & V_101 )
return;
if ( F_25 ( ! F_10 ( V_33 , V_34 ) ) ) {
F_26 ( & V_33 -> V_64 -> V_66 , L_4 , V_34 ) ;
return;
}
F_16 ( V_34 ) ;
F_34 ( V_40 ) ;
V_72 -> V_99 |= V_101 | V_100 ;
}
static int F_57 ( struct V_49 * V_40 , int V_81 )
{
struct V_33 * V_33 = F_21 ( V_40 -> V_16 ) ;
struct V_47 * V_83 = & V_33 -> V_83 ;
struct V_50 * V_72 = & V_40 -> V_48 ;
int V_34 ;
int V_67 = 0 ;
F_58 ( V_40 -> V_16 ) ;
V_34 = F_20 ( V_83 , V_40 ) ;
if ( V_34 < 0 ) {
V_67 = V_34 ;
goto V_102;
}
V_40 -> V_48 . V_34 = V_34 ;
V_83 -> V_82 [ V_34 ] = V_40 ;
V_72 -> V_99 = V_101 | V_100 ;
if ( V_81 & V_103 )
F_54 ( V_40 , V_98 ) ;
F_59 ( V_40 ) ;
V_102:
F_60 ( V_40 -> V_16 ) ;
return V_67 ;
}
static void F_61 ( struct V_49 * V_40 , int V_81 )
{
struct V_33 * V_33 = F_21 ( V_40 -> V_16 ) ;
struct V_47 * V_83 = & V_33 -> V_83 ;
struct V_50 * V_72 = & V_40 -> V_48 ;
int V_34 = V_72 -> V_34 ;
F_56 ( V_40 , V_104 ) ;
V_83 -> V_82 [ V_34 ] = NULL ;
F_62 ( V_34 , V_83 -> V_54 ) ;
F_59 ( V_40 ) ;
}
static int
F_63 ( struct V_47 * V_83 ,
struct V_49 * V_40 )
{
if ( F_64 ( V_40 ) )
return 1 ;
if ( V_40 -> V_99 < V_105 )
return 1 ;
if ( V_40 -> V_99 == V_105 && ! V_40 -> V_59 . V_106 )
return 1 ;
return F_20 ( V_83 , V_40 ) >= 0 ;
}
static int
F_65 ( struct V_49 * V_40 )
{
struct V_49 * V_107 , * V_108 = V_40 -> V_109 ;
struct V_47 V_110 = {
. V_54 = V_111 ,
} ;
if ( ! F_63 ( & V_110 , V_108 ) )
return - V_112 ;
F_66 (sibling, &leader->sibling_list, group_entry) {
if ( ! F_63 ( & V_110 , V_107 ) )
return - V_112 ;
}
if ( ! F_63 ( & V_110 , V_40 ) )
return - V_112 ;
return 0 ;
}
static int
F_67 ( struct V_49 * V_40 )
{
struct V_50 * V_72 = & V_40 -> V_48 ;
int V_57 ;
V_57 = F_23 ( V_40 ) ;
if ( V_57 < 0 ) {
F_68 ( L_5 , V_40 -> V_59 . type ,
V_40 -> V_59 . V_58 ) ;
return V_57 ;
}
V_72 -> V_34 = - 1 ;
V_72 -> V_52 = 0 ;
V_72 -> V_58 = 0 ;
V_72 -> V_113 = 0 ;
V_72 -> V_52 |= ( unsigned long ) V_57 ;
V_72 -> V_114 = V_77 >> 1 ;
V_72 -> V_115 = V_72 -> V_114 ;
F_40 ( & V_72 -> V_116 , V_72 -> V_114 ) ;
if ( V_40 -> V_109 != V_40 ) {
if ( F_65 ( V_40 ) != 0 )
return - V_112 ;
}
return 0 ;
}
static int F_69 ( struct V_49 * V_40 )
{
struct V_33 * V_33 = F_21 ( V_40 -> V_16 ) ;
T_6 * V_91 = & V_33 -> V_91 ;
int V_67 = 0 ;
int V_117 ;
if ( V_40 -> V_59 . type != V_40 -> V_16 -> type )
return - V_32 ;
if ( F_70 ( V_40 ) || V_40 -> V_118 & V_119 )
return - V_120 ;
if ( V_40 -> V_59 . V_121 ||
V_40 -> V_59 . V_122 ||
V_40 -> V_59 . V_123 ||
V_40 -> V_59 . V_124 ||
V_40 -> V_59 . V_125 ||
V_40 -> V_59 . V_126 )
return - V_112 ;
V_117 = F_71 ( & V_33 -> V_127 ) ;
if ( V_40 -> V_117 < 0 || V_117 < 0 )
return - V_112 ;
V_40 -> V_117 = V_117 ;
V_40 -> V_128 = F_47 ;
if ( ! F_72 ( V_91 ) ) {
F_73 ( & V_33 -> V_93 ) ;
if ( F_74 ( V_91 ) == 0 )
V_67 = F_45 ( V_33 ) ;
if ( ! V_67 )
F_75 ( V_91 ) ;
F_49 ( & V_33 -> V_93 ) ;
}
if ( V_67 )
return V_67 ;
V_67 = F_67 ( V_40 ) ;
if ( V_67 )
F_47 ( V_40 ) ;
return V_67 ;
}
static T_7 F_76 ( struct V_129 * V_66 ,
struct V_130 * V_59 , char * V_131 )
{
int V_132 = F_77 ( V_131 , V_133 - 1 , L_6 ,
F_78 ( & V_16 -> V_127 ) ) ;
V_131 [ V_132 ++ ] = '\n' ;
V_131 [ V_132 ] = '\0' ;
return V_132 ;
}
static int F_79 ( struct V_33 * V_33 , struct V_62 * V_134 )
{
char * V_135 = V_136 [ F_2 () ] ;
V_33 -> V_16 = (struct V_16 ) {
. V_135 = V_136 [ F_2 () ] ,
. V_137 = V_138 ,
. V_139 = F_50 ,
. V_140 = F_53 ,
. V_141 = F_69 ,
. V_142 = F_57 ,
. V_143 = F_61 ,
. V_144 = F_54 ,
. V_145 = F_56 ,
. V_146 = F_38 ,
. V_147 = V_148 ,
} ;
V_33 -> V_64 = V_134 ;
V_33 -> V_95 = F_19 () ;
return F_80 ( & V_33 -> V_16 , V_135 , - 1 ) ;
}
static int F_81 ( struct V_149 * V_150 ,
unsigned long V_151 , void * V_152 )
{
unsigned int V_117 = ( long ) V_152 ;
unsigned int V_153 ;
switch ( V_151 & ~ V_154 ) {
case V_155 :
if ( ! F_82 ( V_117 , & V_16 -> V_127 ) )
break;
V_153 = F_83 ( V_156 , V_117 ) ;
if ( V_153 < 0 )
break;
F_84 ( V_153 , & V_16 -> V_127 ) ;
default:
break;
}
return V_157 ;
}
static int F_85 ( struct V_62 * V_134 )
{
struct V_158 * V_159 ;
int V_4 , V_90 , V_1 ;
V_16 = F_86 ( & V_134 -> V_66 , sizeof( * V_16 ) , V_160 ) ;
if ( ! V_16 )
return - V_161 ;
V_159 = F_87 ( V_134 , V_162 , 0 ) ;
V_16 -> V_37 = F_88 ( & V_134 -> V_66 , V_159 ) ;
if ( F_89 ( V_16 -> V_37 ) )
return - V_161 ;
V_16 -> V_3 = 0 ;
for ( V_4 = 0 ; V_4 < V_163 ; V_4 ++ ) {
V_1 = F_90 ( V_134 , V_4 ) ;
if ( V_1 < 0 )
break;
if ( F_1 ( V_1 , V_16 -> V_2 , V_16 -> V_3 ) )
continue;
V_16 -> V_2 [ V_16 -> V_3 ++ ] = V_1 ;
}
if ( V_4 < V_163 ) {
F_91 ( & V_134 -> V_66 , L_7 ,
V_4 , V_163 ) ;
return - V_112 ;
}
V_16 -> V_17 = F_4 () ;
if ( ! V_16 -> V_17 ) {
F_91 ( & V_134 -> V_66 , L_8 ) ;
return - V_112 ;
}
F_92 ( & V_16 -> V_83 . V_86 ) ;
F_93 ( & V_16 -> V_93 ) ;
F_94 ( & V_16 -> V_91 , 0 ) ;
F_84 ( F_95 () , & V_16 -> V_127 ) ;
V_90 = F_96 ( & V_164 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_79 ( V_16 , V_134 ) ;
if ( V_90 )
return V_90 ;
return 0 ;
}
static int F_97 ( struct V_62 * V_134 )
{
if ( ! F_98 () )
return - V_65 ;
return F_99 ( V_134 -> V_66 . V_165 , NULL , NULL , & V_134 -> V_66 ) ;
}
static inline void F_100 ( struct V_166 * V_167 , T_2 V_168 , T_4 V_169 )
{
V_167 -> V_167 = V_170 | V_168 ;
V_167 -> V_169 = V_169 ;
}
static inline bool F_101 ( struct V_166 * V_167 )
{
return ! ! ( V_167 -> V_167 & V_170 ) ;
}
static inline bool F_102 ( struct V_166 * V_167 , T_4 V_169 )
{
return V_167 -> V_169 == ( V_169 & V_171 ) ;
}
static int F_103 ( struct V_172 * V_173 , int type )
{
int V_4 ;
bool V_174 ;
struct V_172 * V_175 ;
V_175 = F_104 ( V_173 , L_9 , 0 ) ;
for ( V_4 = 0 ; V_4 < V_176 ; V_4 ++ ) {
V_174 = V_177 [ V_4 ] . type == type ;
if ( V_174 && V_175 == V_177 [ V_4 ] . V_173 )
return V_4 ;
}
return - V_65 ;
}
int F_105 ( struct V_172 * V_173 )
{
return F_103 ( V_173 , V_178 ) ;
}
static void F_106 ( void )
{
int V_167 , V_117 ;
struct V_172 * V_179 ;
F_107 (cpu) {
V_179 = F_108 ( V_117 , NULL ) ;
if ( F_109 ( ! V_179 , L_10 ) )
continue;
V_167 = F_103 ( V_179 , V_180 ) ;
if ( V_167 < 0 )
continue;
F_100 ( & V_166 [ V_117 ] , V_167 , F_110 ( V_117 ) ) ;
}
F_107 (cpu) {
F_109 ( ! F_101 ( & V_166 [ V_117 ] ) ,
L_11 ,
V_117 ) ;
}
}
static void T_8 F_111 ( unsigned int V_167 , bool V_181 )
{
void T_9 * V_37 = V_177 [ V_167 ] . V_37 ;
F_15 ( V_181 ? V_182 : 0 , V_37 + V_183 ) ;
while ( F_3 ( V_6 + V_184 ) & 0x1 )
;
}
int T_8 F_112 ( T_4 V_169 )
{
int V_117 ;
bool V_185 ;
for ( V_117 = 0 ; V_117 < V_186 ; V_117 ++ ) {
V_185 = F_101 ( & V_166 [ V_117 ] ) ;
if ( V_185 && F_102 ( & V_166 [ V_117 ] , V_169 ) ) {
F_111 ( V_166 [ V_117 ] . V_167 , false ) ;
return 0 ;
}
}
return - V_65 ;
}
T_10 void T_11 F_113 ( void )
{
asm volatile ("\n"
" .arch armv7-a\n"
" mrc p15, 0, r0, c0, c0, 5 @ get MPIDR value \n"
" and r0, r0, #"__stringify(MPIDR_HWID_BITMASK)" \n"
" adr r1, 5f \n"
" ldr r2, [r1] \n"
" add r1, r1, r2 @ &cpu_port \n"
" add ip, r1, %[sizeof_cpu_port] \n"
"1: ldr r2, [r1, %[offsetof_cpu_port_mpidr_lsb]] \n"
" cmp r2, r0 @ compare MPIDR \n"
" bne 2f \n"
" ldr r3, [r1, %[offsetof_cpu_port_port]] \n"
" tst r3, #"__stringify(PORT_VALID)" \n"
" bne 3f \n"
"2: add r1, r1, %[sizeof_struct_cpu_port] \n"
" cmp r1, ip @ done? \n"
" blo 1b \n"
"cci_port_not_found: \n"
" wfi \n"
" wfe \n"
" b cci_port_not_found \n"
"3: bic r3, r3, #"__stringify(PORT_VALID)" \n"
" adr r0, 6f \n"
" ldmia r0, {r1, r2} \n"
" sub r1, r1, r0 @ virt - phys \n"
" ldr r0, [r0, r2] @ *(&ports) \n"
" mov r2, %[sizeof_struct_ace_port] \n"
" mla r0, r2, r3, r0 @ &ports[index] \n"
" sub r0, r0, r1 @ virt_to_phys() \n"
" ldr r0, [r0, %[offsetof_port_phys]] \n"
" mov r3, %[cci_enable_req]\n"
" str r3, [r0, #"__stringify(CCI_PORT_CTRL)"] \n"
" adr r1, 7f \n"
" ldr r0, [r1] \n"
" ldr r0, [r0, r1] @ cci_ctrl_base \n"
"4: ldr r1, [r0, #"__stringify(CCI_CTRL_STATUS)"] \n"
" tst r1, %[cci_control_status_bits] \n"
" bne 4b \n"
" mov r0, #0 \n"
" bx lr \n"
" .align 2 \n"
"5: .word cpu_port - . \n"
"6: .word . \n"
" .word ports - 6b \n"
"7: .word cci_ctrl_phys - . \n"
: :
[sizeof_cpu_port] "i" (sizeof(cpu_port)),
[cci_enable_req] "i" cpu_to_le32(CCI_ENABLE_REQ),
[cci_control_status_bits] "i" cpu_to_le32(1),
#ifndef F_114
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)),
#else
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)+4),
#endif
[offsetof_cpu_port_port] "i" (offsetof(struct cpu_port, port)),
[sizeof_struct_cpu_port] "i" (sizeof(struct cpu_port)),
[sizeof_struct_ace_port] "i" (sizeof(struct cci_ace_port)),
[offsetof_port_phys] "i" (offsetof(struct cci_ace_port, phys)) );
F_115 () ;
}
int T_8 F_116 ( struct V_172 * V_173 , bool V_181 )
{
int V_167 ;
if ( ! V_173 )
return - V_65 ;
V_167 = F_103 ( V_173 , V_178 ) ;
if ( F_117 ( V_167 < 0 , L_12 ,
V_173 -> V_187 ) )
return - V_65 ;
F_111 ( V_167 , V_181 ) ;
return 0 ;
}
int T_8 F_118 ( T_2 V_167 , bool V_181 )
{
if ( V_167 >= V_176 || V_177 [ V_167 ] . type == V_188 )
return - V_65 ;
if ( V_177 [ V_167 ] . type == V_180 )
return - V_189 ;
F_111 ( V_167 , V_181 ) ;
return 0 ;
}
static int F_119 ( void )
{
struct V_190 const * V_191 ;
int V_90 , V_4 , V_192 = 0 , V_193 = 0 ;
struct V_172 * V_194 , * V_195 ;
struct V_158 V_159 ;
const char * V_196 ;
bool V_197 ;
V_194 = F_120 ( NULL , V_198 ) ;
if ( ! V_194 )
return - V_65 ;
if ( ! F_121 ( V_194 ) )
return - V_65 ;
V_191 = F_122 ( V_198 , V_194 ) -> V_199 ;
if ( ! V_191 )
return - V_65 ;
V_176 = V_191 -> V_192 + V_191 -> V_193 ;
V_177 = F_123 ( V_176 , sizeof( * V_177 ) , V_160 ) ;
if ( ! V_177 )
return - V_161 ;
V_90 = F_124 ( V_194 , 0 , & V_159 ) ;
if ( ! V_90 ) {
V_6 = F_125 ( V_159 . V_144 , F_126 ( & V_159 ) ) ;
V_200 = V_159 . V_144 ;
}
if ( V_90 || ! V_6 ) {
F_109 ( 1 , L_13 ) ;
V_90 = - V_201 ;
goto V_202;
}
F_127 (np, cp) {
if ( ! F_122 ( V_203 , V_195 ) )
continue;
V_4 = V_192 + V_193 ;
if ( V_4 >= V_176 )
break;
if ( F_128 ( V_195 , L_14 ,
& V_196 ) ) {
F_109 ( 1 , L_15 ,
V_195 -> V_187 ) ;
continue;
}
V_197 = strcmp ( V_196 , L_16 ) == 0 ;
if ( ! V_197 && strcmp ( V_196 , L_17 ) ) {
F_109 ( 1 , L_18 ,
V_195 -> V_187 ) ;
continue;
}
V_90 = F_124 ( V_195 , 0 , & V_159 ) ;
if ( ! V_90 ) {
V_177 [ V_4 ] . V_37 = F_125 ( V_159 . V_144 , F_126 ( & V_159 ) ) ;
V_177 [ V_4 ] . V_204 = V_159 . V_144 ;
}
if ( V_90 || ! V_177 [ V_4 ] . V_37 ) {
F_109 ( 1 , L_19 , V_4 ) ;
continue;
}
if ( V_197 ) {
if ( F_129 ( V_192 >= V_191 -> V_192 ) )
continue;
V_177 [ V_4 ] . type = V_180 ;
++ V_192 ;
} else {
if ( F_129 ( V_193 >= V_191 -> V_193 ) )
continue;
V_177 [ V_4 ] . type = V_178 ;
++ V_193 ;
}
V_177 [ V_4 ] . V_173 = V_195 ;
}
F_106 () ;
F_130 ( & V_6 ) ;
F_130 ( & V_200 ) ;
F_130 ( & V_177 ) ;
F_130 ( & V_166 ) ;
F_131 ( V_177 , sizeof( * V_177 ) * V_176 ) ;
F_132 ( L_20 ) ;
return 0 ;
V_202:
F_133 ( V_177 ) ;
return V_90 ;
}
static int F_134 ( void )
{
if ( V_205 != - V_55 )
return V_205 ;
F_73 ( & V_206 ) ;
if ( V_205 == - V_55 )
V_205 = F_119 () ;
F_49 ( & V_206 ) ;
return V_205 ;
}
static int T_12 F_135 ( void )
{
int V_90 ;
V_90 = F_136 ( & V_207 ) ;
if ( V_90 )
return V_90 ;
return F_136 ( & V_208 ) ;
}
static int T_12 F_135 ( void )
{
return 0 ;
}
bool F_98 ( void )
{
return F_134 () == 0 ;
}
