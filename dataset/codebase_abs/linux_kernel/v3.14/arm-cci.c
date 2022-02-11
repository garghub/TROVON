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
if ( V_5 <= V_10 )
return V_11 ;
else if ( V_5 <= V_12 )
return V_13 ;
return - V_14 ;
}
static struct V_15 * F_4 ( void )
{
int V_5 = F_2 () ;
if ( V_5 < 0 )
return NULL ;
return & V_16 [ V_5 ] ;
}
static int F_5 ( T_1 V_17 )
{
return V_18 -> V_19 -> V_20 <= V_17 &&
V_17 <= V_18 -> V_19 -> V_21 ;
}
static int F_6 ( T_1 V_17 )
{
return V_18 -> V_19 -> V_22 <= V_17 &&
V_17 <= V_18 -> V_19 -> V_23 ;
}
static int F_7 ( T_1 V_24 )
{
T_1 V_25 = F_8 ( V_24 ) ;
T_1 V_17 = F_9 ( V_24 ) ;
switch ( V_25 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
if ( F_5 ( V_17 ) )
return V_24 ;
break;
case V_31 :
case V_32 :
case V_33 :
if ( F_6 ( V_17 ) )
return V_24 ;
break;
}
return - V_14 ;
}
static int F_10 ( struct V_34 * V_35 , int V_36 )
{
return V_37 <= V_36 &&
V_36 <= F_11 ( V_35 ) ;
}
static T_2 F_12 ( int V_36 , unsigned int V_38 )
{
return F_3 ( V_18 -> V_39 + F_13 ( V_36 ) + V_38 ) ;
}
static void F_14 ( T_2 V_40 , int V_36 , unsigned int V_38 )
{
return F_15 ( V_40 , V_18 -> V_39 + F_13 ( V_36 ) + V_38 ) ;
}
static void F_16 ( int V_36 )
{
F_14 ( 0 , V_36 , V_41 ) ;
}
static void F_17 ( int V_36 )
{
F_14 ( 1 , V_36 , V_41 ) ;
}
static void F_18 ( int V_36 , unsigned long V_42 )
{
V_42 &= V_43 ;
F_14 ( V_42 , V_36 , V_44 ) ;
}
static T_2 F_19 ( void )
{
T_2 V_45 = ( F_3 ( V_6 + V_46 ) &
V_47 ) >> V_48 ;
return V_45 + 1 ;
}
static struct V_49 * F_20 ( void )
{
return & V_18 -> V_50 ;
}
static int F_21 ( struct V_49 * V_51 , struct V_52 * V_42 )
{
struct V_34 * V_35 = F_22 ( V_42 -> V_18 ) ;
struct V_53 * V_24 = & V_42 -> V_51 ;
unsigned long V_54 = V_24 -> V_55 & V_43 ;
int V_36 ;
if ( V_54 == V_56 ) {
if ( F_23 ( V_37 , V_51 -> V_57 ) )
return - V_58 ;
return V_37 ;
}
for ( V_36 = V_59 ; V_36 <= F_11 ( V_35 ) ; ++ V_36 )
if ( ! F_23 ( V_36 , V_51 -> V_57 ) )
return V_36 ;
return - V_58 ;
}
static int F_24 ( struct V_52 * V_42 )
{
int V_60 ;
T_1 V_61 = V_42 -> V_62 . V_61 & V_43 ;
if ( V_42 -> V_62 . type < V_63 )
return - V_14 ;
if ( V_61 == V_56 )
V_60 = V_61 ;
else
V_60 = F_7 ( V_61 ) ;
return V_60 ;
}
static int F_25 ( struct V_34 * V_35 , T_3 V_64 )
{
int V_4 ;
struct V_65 * V_66 = V_35 -> V_67 ;
if ( F_26 ( ! V_66 ) )
return - V_68 ;
if ( V_18 -> V_3 < 1 ) {
F_27 ( & V_66 -> V_69 , L_1 ) ;
return - V_68 ;
}
for ( V_4 = 0 ; V_4 < V_18 -> V_3 ; V_4 ++ ) {
int V_70 = F_28 ( V_18 -> V_2 [ V_4 ] , V_64 , V_71 ,
L_2 , V_35 ) ;
if ( V_70 ) {
F_27 ( & V_66 -> V_69 , L_3 ,
V_18 -> V_2 [ V_4 ] ) ;
return V_70 ;
}
F_29 ( V_4 , & V_18 -> V_72 ) ;
}
return 0 ;
}
static T_4 F_30 ( int V_73 , void * V_69 )
{
unsigned long V_74 ;
struct V_34 * V_35 = (struct V_34 * ) V_69 ;
struct V_49 * V_75 = V_35 -> V_76 () ;
struct V_77 V_78 ;
struct V_79 * V_80 ;
int V_36 , V_81 = V_82 ;
F_31 ( & V_75 -> V_83 , V_74 ) ;
V_80 = F_32 () ;
for ( V_36 = V_37 ; V_36 <= F_11 ( V_35 ) ; V_36 ++ ) {
struct V_52 * V_42 = V_75 -> V_75 [ V_36 ] ;
struct V_53 * V_84 ;
if ( ! V_42 )
continue;
V_84 = & V_42 -> V_51 ;
if ( ! F_12 ( V_36 , V_85 ) & V_86 )
continue;
F_14 ( V_86 , V_36 , V_85 ) ;
V_81 = V_87 ;
F_33 ( V_42 ) ;
F_34 ( & V_78 , 0 , V_84 -> V_88 ) ;
if ( ! F_35 ( V_42 ) )
continue;
if ( F_36 ( V_42 , & V_78 , V_80 ) )
V_35 -> V_89 ( V_42 ) ;
}
F_37 ( & V_75 -> V_83 , V_74 ) ;
return F_38 ( V_81 ) ;
}
static void F_39 ( struct V_34 * V_35 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_18 -> V_3 ; V_4 ++ ) {
if ( ! F_40 ( V_4 , & V_18 -> V_72 ) )
continue;
F_41 ( V_18 -> V_2 [ V_4 ] , V_35 ) ;
}
}
static void F_42 ( struct V_52 * V_42 )
{
unsigned long V_74 ;
struct V_34 * V_35 = F_22 ( V_42 -> V_18 ) ;
struct V_49 * V_75 = V_35 -> V_76 () ;
struct V_53 * V_84 = & V_42 -> V_51 ;
int V_36 = V_84 -> V_36 ;
if ( F_26 ( ! F_10 ( V_35 , V_36 ) ) ) {
F_27 ( & V_35 -> V_67 -> V_69 , L_4 , V_36 ) ;
return;
}
F_31 ( & V_75 -> V_83 , V_74 ) ;
if ( V_36 != V_37 )
F_18 ( V_36 , V_84 -> V_55 ) ;
F_17 ( V_36 ) ;
F_37 ( & V_75 -> V_83 , V_74 ) ;
}
static void F_43 ( struct V_52 * V_42 )
{
struct V_34 * V_35 = F_22 ( V_42 -> V_18 ) ;
struct V_53 * V_84 = & V_42 -> V_51 ;
int V_36 = V_84 -> V_36 ;
if ( F_26 ( ! F_10 ( V_35 , V_36 ) ) ) {
F_27 ( & V_35 -> V_67 -> V_69 , L_4 , V_36 ) ;
return;
}
F_16 ( V_36 ) ;
}
static void F_44 ( struct V_34 * V_35 )
{
T_2 V_90 ;
unsigned long V_74 ;
struct V_49 * V_75 = V_35 -> V_76 () ;
F_31 ( & V_75 -> V_83 , V_74 ) ;
V_90 = F_3 ( V_6 + V_46 ) | V_91 ;
F_45 ( V_90 , V_6 + V_46 ) ;
F_37 ( & V_75 -> V_83 , V_74 ) ;
}
static void F_46 ( struct V_34 * V_35 )
{
T_2 V_90 ;
unsigned long V_74 ;
struct V_49 * V_75 = V_35 -> V_76 () ;
F_31 ( & V_75 -> V_83 , V_74 ) ;
V_90 = F_3 ( V_6 + V_46 ) & ~ V_91 ;
F_45 ( V_90 , V_6 + V_46 ) ;
F_37 ( & V_75 -> V_83 , V_74 ) ;
}
static T_2 F_47 ( struct V_52 * V_42 )
{
struct V_34 * V_35 = F_22 ( V_42 -> V_18 ) ;
struct V_53 * V_84 = & V_42 -> V_51 ;
int V_36 = V_84 -> V_36 ;
T_2 V_40 ;
if ( F_26 ( ! F_10 ( V_35 , V_36 ) ) ) {
F_27 ( & V_35 -> V_67 -> V_69 , L_4 , V_36 ) ;
return 0 ;
}
V_40 = F_12 ( V_36 , V_92 ) ;
return V_40 ;
}
static void F_48 ( struct V_52 * V_42 , T_2 V_40 )
{
struct V_34 * V_35 = F_22 ( V_42 -> V_18 ) ;
struct V_53 * V_84 = & V_42 -> V_51 ;
int V_36 = V_84 -> V_36 ;
if ( F_26 ( ! F_10 ( V_35 , V_36 ) ) )
F_27 ( & V_35 -> V_67 -> V_69 , L_4 , V_36 ) ;
else
F_14 ( V_40 , V_36 , V_92 ) ;
}
static int F_49 ( struct V_34 * V_35 , struct V_65 * V_93 )
{
* V_35 = (struct V_34 ) {
. V_94 = V_95 ,
. V_96 = ( 1LLU << 32 ) - 1 ,
. V_76 = F_20 ,
. V_97 = F_21 ,
. V_98 = F_24 ,
. F_28 = F_25 ,
. V_99 = F_30 ,
. F_41 = F_39 ,
. V_100 = F_42 ,
. V_89 = F_43 ,
. V_101 = F_44 ,
. V_102 = F_46 ,
. V_103 = F_47 ,
. V_104 = F_48 ,
} ;
V_35 -> V_67 = V_93 ;
V_35 -> V_105 = F_19 () ;
return F_50 ( V_35 , - 1 ) ;
}
static int F_51 ( struct V_65 * V_93 )
{
struct V_106 * V_107 ;
int V_4 , V_108 , V_1 ;
V_18 = F_52 ( & V_93 -> V_69 , sizeof( * V_18 ) , V_109 ) ;
if ( ! V_18 )
return - V_110 ;
V_107 = F_53 ( V_93 , V_111 , 0 ) ;
V_18 -> V_39 = F_54 ( & V_93 -> V_69 , V_107 ) ;
if ( F_55 ( V_18 -> V_39 ) )
return - V_110 ;
V_18 -> V_3 = 0 ;
for ( V_4 = 0 ; V_4 < V_112 ; V_4 ++ ) {
V_1 = F_56 ( V_93 , V_4 ) ;
if ( V_1 < 0 )
break;
if ( F_1 ( V_1 , V_18 -> V_2 , V_18 -> V_3 ) )
continue;
V_18 -> V_2 [ V_18 -> V_3 ++ ] = V_1 ;
}
if ( V_4 < V_112 ) {
F_57 ( & V_93 -> V_69 , L_5 ,
V_4 , V_112 ) ;
return - V_113 ;
}
V_18 -> V_19 = F_4 () ;
if ( ! V_18 -> V_19 ) {
F_57 ( & V_93 -> V_69 , L_6 ) ;
return - V_113 ;
}
V_18 -> V_35 = F_52 ( & V_93 -> V_69 , sizeof( * ( V_18 -> V_35 ) ) , V_109 ) ;
if ( ! V_18 -> V_35 )
return - V_110 ;
V_18 -> V_50 . V_75 = V_18 -> V_75 ;
V_18 -> V_50 . V_57 = V_18 -> V_57 ;
F_58 ( & V_18 -> V_50 . V_83 ) ;
V_108 = F_49 ( V_18 -> V_35 , V_93 ) ;
if ( V_108 )
return V_108 ;
return 0 ;
}
static int F_59 ( struct V_65 * V_93 )
{
if ( ! F_60 () )
return - V_68 ;
return F_61 ( V_93 -> V_69 . V_114 , NULL , NULL , & V_93 -> V_69 ) ;
}
static inline void F_62 ( struct V_115 * V_116 , T_2 V_117 , T_5 V_118 )
{
V_116 -> V_116 = V_119 | V_117 ;
V_116 -> V_118 = V_118 ;
}
static inline bool F_63 ( struct V_115 * V_116 )
{
return ! ! ( V_116 -> V_116 & V_119 ) ;
}
static inline bool F_64 ( struct V_115 * V_116 , T_5 V_118 )
{
return V_116 -> V_118 == ( V_118 & V_120 ) ;
}
static int F_65 ( struct V_121 * V_122 , int type )
{
int V_4 ;
bool V_123 ;
struct V_121 * V_124 ;
V_124 = F_66 ( V_122 , L_7 , 0 ) ;
for ( V_4 = 0 ; V_4 < V_125 ; V_4 ++ ) {
V_123 = V_126 [ V_4 ] . type == type ;
if ( V_123 && V_124 == V_126 [ V_4 ] . V_122 )
return V_4 ;
}
return - V_68 ;
}
int F_67 ( struct V_121 * V_122 )
{
return F_65 ( V_122 , V_127 ) ;
}
static void F_68 ( void )
{
int V_116 , V_128 ;
struct V_121 * V_129 ;
F_69 (cpu) {
V_129 = F_70 ( V_128 , NULL ) ;
if ( F_71 ( ! V_129 , L_8 ) )
continue;
V_116 = F_65 ( V_129 , V_130 ) ;
if ( V_116 < 0 )
continue;
F_62 ( & V_115 [ V_128 ] , V_116 , F_72 ( V_128 ) ) ;
}
F_69 (cpu) {
F_71 ( ! F_63 ( & V_115 [ V_128 ] ) ,
L_9 ,
V_128 ) ;
}
}
static void T_6 F_73 ( unsigned int V_116 , bool V_100 )
{
void T_7 * V_39 = V_126 [ V_116 ] . V_39 ;
F_15 ( V_100 ? V_131 : 0 , V_39 + V_132 ) ;
while ( F_3 ( V_6 + V_133 ) & 0x1 )
;
}
int T_6 F_74 ( T_5 V_118 )
{
int V_128 ;
bool V_134 ;
for ( V_128 = 0 ; V_128 < V_135 ; V_128 ++ ) {
V_134 = F_63 ( & V_115 [ V_128 ] ) ;
if ( V_134 && F_64 ( & V_115 [ V_128 ] , V_118 ) ) {
F_73 ( V_115 [ V_128 ] . V_116 , false ) ;
return 0 ;
}
}
return - V_68 ;
}
T_8 void T_9 F_75 ( void )
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
#ifndef F_76
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)),
#else
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)+4),
#endif
[offsetof_cpu_port_port] "i" (offsetof(struct cpu_port, port)),
[sizeof_struct_cpu_port] "i" (sizeof(struct cpu_port)),
[sizeof_struct_ace_port] "i" (sizeof(struct cci_ace_port)),
[offsetof_port_phys] "i" (offsetof(struct cci_ace_port, phys)) );
F_77 () ;
}
int T_6 F_78 ( struct V_121 * V_122 , bool V_100 )
{
int V_116 ;
if ( ! V_122 )
return - V_68 ;
V_116 = F_65 ( V_122 , V_127 ) ;
if ( F_79 ( V_116 < 0 , L_10 ,
V_122 -> V_136 ) )
return - V_68 ;
F_73 ( V_116 , V_100 ) ;
return 0 ;
}
int T_6 F_80 ( T_2 V_116 , bool V_100 )
{
if ( V_116 >= V_125 || V_126 [ V_116 ] . type == V_137 )
return - V_68 ;
if ( V_126 [ V_116 ] . type == V_130 )
return - V_138 ;
F_73 ( V_116 , V_100 ) ;
return 0 ;
}
static int F_81 ( void )
{
struct V_139 const * V_140 ;
int V_108 , V_4 , V_141 = 0 , V_142 = 0 ;
struct V_121 * V_143 , * V_144 ;
struct V_106 V_107 ;
const char * V_145 ;
bool V_146 ;
V_143 = F_82 ( NULL , V_147 ) ;
if ( ! V_143 )
return - V_68 ;
V_140 = F_83 ( V_147 , V_143 ) -> V_78 ;
if ( ! V_140 )
return - V_68 ;
V_125 = V_140 -> V_141 + V_140 -> V_142 ;
V_126 = F_84 ( V_125 , sizeof( * V_126 ) , V_109 ) ;
if ( ! V_126 )
return - V_110 ;
V_108 = F_85 ( V_143 , 0 , & V_107 ) ;
if ( ! V_108 ) {
V_6 = F_86 ( V_107 . V_101 , F_87 ( & V_107 ) ) ;
V_148 = V_107 . V_101 ;
}
if ( V_108 || ! V_6 ) {
F_71 ( 1 , L_11 ) ;
V_108 = - V_149 ;
goto V_150;
}
F_88 (np, cp) {
if ( ! F_83 ( V_151 , V_144 ) )
continue;
V_4 = V_141 + V_142 ;
if ( V_4 >= V_125 )
break;
if ( F_89 ( V_144 , L_12 ,
& V_145 ) ) {
F_71 ( 1 , L_13 ,
V_144 -> V_136 ) ;
continue;
}
V_146 = strcmp ( V_145 , L_14 ) == 0 ;
if ( ! V_146 && strcmp ( V_145 , L_15 ) ) {
F_71 ( 1 , L_16 ,
V_144 -> V_136 ) ;
continue;
}
V_108 = F_85 ( V_144 , 0 , & V_107 ) ;
if ( ! V_108 ) {
V_126 [ V_4 ] . V_39 = F_86 ( V_107 . V_101 , F_87 ( & V_107 ) ) ;
V_126 [ V_4 ] . V_152 = V_107 . V_101 ;
}
if ( V_108 || ! V_126 [ V_4 ] . V_39 ) {
F_71 ( 1 , L_17 , V_4 ) ;
continue;
}
if ( V_146 ) {
if ( F_90 ( V_141 >= V_140 -> V_141 ) )
continue;
V_126 [ V_4 ] . type = V_130 ;
++ V_141 ;
} else {
if ( F_90 ( V_142 >= V_140 -> V_142 ) )
continue;
V_126 [ V_4 ] . type = V_127 ;
++ V_142 ;
}
V_126 [ V_4 ] . V_122 = V_144 ;
}
F_68 () ;
F_91 ( & V_6 ) ;
F_91 ( & V_148 ) ;
F_91 ( & V_126 ) ;
F_91 ( & V_115 ) ;
F_92 ( V_126 , sizeof( * V_126 ) * V_125 ) ;
F_93 ( L_18 ) ;
return 0 ;
V_150:
F_94 ( V_126 ) ;
return V_108 ;
}
static int F_95 ( void )
{
if ( V_153 != - V_58 )
return V_153 ;
F_96 ( & V_154 ) ;
if ( V_153 == - V_58 )
V_153 = F_81 () ;
F_97 ( & V_154 ) ;
return V_153 ;
}
static int T_10 F_98 ( void )
{
int V_108 ;
V_108 = F_99 ( & V_155 ) ;
if ( V_108 )
return V_108 ;
return F_99 ( & V_156 ) ;
}
static int T_10 F_98 ( void )
{
return 0 ;
}
bool F_60 ( void )
{
return F_95 () == 0 ;
}
