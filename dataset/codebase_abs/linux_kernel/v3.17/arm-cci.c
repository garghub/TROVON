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
static int F_10 ( struct V_33 * V_34 , int V_35 )
{
return V_36 <= V_35 &&
V_35 <= F_11 ( V_34 ) ;
}
static T_2 F_12 ( int V_35 , unsigned int V_37 )
{
return F_3 ( V_16 -> V_38 + F_13 ( V_35 ) + V_37 ) ;
}
static void F_14 ( T_2 V_39 , int V_35 , unsigned int V_37 )
{
return F_15 ( V_39 , V_16 -> V_38 + F_13 ( V_35 ) + V_37 ) ;
}
static void F_16 ( int V_35 )
{
F_14 ( 0 , V_35 , V_40 ) ;
}
static void F_17 ( int V_35 )
{
F_14 ( 1 , V_35 , V_40 ) ;
}
static void F_18 ( int V_35 , unsigned long V_41 )
{
V_41 &= V_42 ;
F_14 ( V_41 , V_35 , V_43 ) ;
}
static T_2 F_19 ( void )
{
T_2 V_44 = ( F_3 ( V_6 + V_45 ) &
V_46 ) >> V_47 ;
return V_44 + 1 ;
}
static struct V_48 * F_20 ( void )
{
return & V_16 -> V_49 ;
}
static int F_21 ( struct V_48 * V_50 , struct V_51 * V_41 )
{
struct V_33 * V_34 = F_22 ( V_41 -> V_16 ) ;
struct V_52 * V_22 = & V_41 -> V_50 ;
unsigned long V_53 = V_22 -> V_54 & V_42 ;
int V_35 ;
if ( V_53 == V_55 ) {
if ( F_23 ( V_36 , V_50 -> V_56 ) )
return - V_57 ;
return V_36 ;
}
for ( V_35 = V_58 ; V_35 <= F_11 ( V_34 ) ; ++ V_35 )
if ( ! F_23 ( V_35 , V_50 -> V_56 ) )
return V_35 ;
return - V_57 ;
}
static int F_24 ( struct V_51 * V_41 )
{
int V_59 ;
T_1 V_60 = V_41 -> V_61 . V_60 & V_42 ;
if ( V_41 -> V_61 . type < V_62 )
return - V_32 ;
if ( V_60 == V_55 )
V_59 = V_60 ;
else
V_59 = F_7 ( V_60 ) ;
return V_59 ;
}
static int F_25 ( struct V_33 * V_34 , T_3 V_63 )
{
int V_4 ;
struct V_64 * V_65 = V_34 -> V_66 ;
if ( F_26 ( ! V_65 ) )
return - V_67 ;
if ( V_16 -> V_3 < 1 ) {
F_27 ( & V_65 -> V_68 , L_1 ) ;
return - V_67 ;
}
for ( V_4 = 0 ; V_4 < V_16 -> V_3 ; V_4 ++ ) {
int V_69 = F_28 ( V_16 -> V_2 [ V_4 ] , V_63 , V_70 ,
L_2 , V_34 ) ;
if ( V_69 ) {
F_27 ( & V_65 -> V_68 , L_3 ,
V_16 -> V_2 [ V_4 ] ) ;
return V_69 ;
}
F_29 ( V_4 , & V_16 -> V_71 ) ;
}
return 0 ;
}
static T_4 F_30 ( int V_72 , void * V_68 )
{
unsigned long V_73 ;
struct V_33 * V_34 = (struct V_33 * ) V_68 ;
struct V_48 * V_74 = V_34 -> V_75 () ;
struct V_76 V_77 ;
struct V_78 * V_79 ;
int V_35 , V_80 = V_81 ;
F_31 ( & V_74 -> V_82 , V_73 ) ;
V_79 = F_32 () ;
for ( V_35 = V_36 ; V_35 <= F_11 ( V_34 ) ; V_35 ++ ) {
struct V_51 * V_41 = V_74 -> V_74 [ V_35 ] ;
struct V_52 * V_83 ;
if ( ! V_41 )
continue;
V_83 = & V_41 -> V_50 ;
if ( ! ( F_12 ( V_35 , V_84 ) &
V_85 ) )
continue;
F_14 ( V_85 , V_35 , V_84 ) ;
V_80 = V_86 ;
F_33 ( V_41 ) ;
F_34 ( & V_77 , 0 , V_83 -> V_87 ) ;
if ( ! F_35 ( V_41 ) )
continue;
if ( F_36 ( V_41 , & V_77 , V_79 ) )
V_34 -> V_88 ( V_41 ) ;
}
F_37 ( & V_74 -> V_82 , V_73 ) ;
return F_38 ( V_80 ) ;
}
static void F_39 ( struct V_33 * V_34 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_16 -> V_3 ; V_4 ++ ) {
if ( ! F_40 ( V_4 , & V_16 -> V_71 ) )
continue;
F_41 ( V_16 -> V_2 [ V_4 ] , V_34 ) ;
}
}
static void F_42 ( struct V_51 * V_41 )
{
unsigned long V_73 ;
struct V_33 * V_34 = F_22 ( V_41 -> V_16 ) ;
struct V_48 * V_74 = V_34 -> V_75 () ;
struct V_52 * V_83 = & V_41 -> V_50 ;
int V_35 = V_83 -> V_35 ;
if ( F_26 ( ! F_10 ( V_34 , V_35 ) ) ) {
F_27 ( & V_34 -> V_66 -> V_68 , L_4 , V_35 ) ;
return;
}
F_31 ( & V_74 -> V_82 , V_73 ) ;
if ( V_35 != V_36 )
F_18 ( V_35 , V_83 -> V_54 ) ;
F_17 ( V_35 ) ;
F_37 ( & V_74 -> V_82 , V_73 ) ;
}
static void F_43 ( struct V_51 * V_41 )
{
struct V_33 * V_34 = F_22 ( V_41 -> V_16 ) ;
struct V_52 * V_83 = & V_41 -> V_50 ;
int V_35 = V_83 -> V_35 ;
if ( F_26 ( ! F_10 ( V_34 , V_35 ) ) ) {
F_27 ( & V_34 -> V_66 -> V_68 , L_4 , V_35 ) ;
return;
}
F_16 ( V_35 ) ;
}
static void F_44 ( struct V_33 * V_34 )
{
T_2 V_89 ;
unsigned long V_73 ;
struct V_48 * V_74 = V_34 -> V_75 () ;
F_31 ( & V_74 -> V_82 , V_73 ) ;
V_89 = F_3 ( V_6 + V_45 ) | V_90 ;
F_45 ( V_89 , V_6 + V_45 ) ;
F_37 ( & V_74 -> V_82 , V_73 ) ;
}
static void F_46 ( struct V_33 * V_34 )
{
T_2 V_89 ;
unsigned long V_73 ;
struct V_48 * V_74 = V_34 -> V_75 () ;
F_31 ( & V_74 -> V_82 , V_73 ) ;
V_89 = F_3 ( V_6 + V_45 ) & ~ V_90 ;
F_45 ( V_89 , V_6 + V_45 ) ;
F_37 ( & V_74 -> V_82 , V_73 ) ;
}
static T_2 F_47 ( struct V_51 * V_41 )
{
struct V_33 * V_34 = F_22 ( V_41 -> V_16 ) ;
struct V_52 * V_83 = & V_41 -> V_50 ;
int V_35 = V_83 -> V_35 ;
T_2 V_39 ;
if ( F_26 ( ! F_10 ( V_34 , V_35 ) ) ) {
F_27 ( & V_34 -> V_66 -> V_68 , L_4 , V_35 ) ;
return 0 ;
}
V_39 = F_12 ( V_35 , V_91 ) ;
return V_39 ;
}
static void F_48 ( struct V_51 * V_41 , T_2 V_39 )
{
struct V_33 * V_34 = F_22 ( V_41 -> V_16 ) ;
struct V_52 * V_83 = & V_41 -> V_50 ;
int V_35 = V_83 -> V_35 ;
if ( F_26 ( ! F_10 ( V_34 , V_35 ) ) )
F_27 ( & V_34 -> V_66 -> V_68 , L_4 , V_35 ) ;
else
F_14 ( V_39 , V_35 , V_91 ) ;
}
static int F_49 ( struct V_33 * V_34 , struct V_64 * V_92 )
{
* V_34 = (struct V_33 ) {
. V_93 = V_94 [ F_2 () ] ,
. V_95 = ( 1LLU << 32 ) - 1 ,
. V_75 = F_20 ,
. V_96 = F_21 ,
. V_97 = F_24 ,
. F_28 = F_25 ,
. V_98 = F_30 ,
. F_41 = F_39 ,
. V_99 = F_42 ,
. V_88 = F_43 ,
. V_100 = F_44 ,
. V_101 = F_46 ,
. V_102 = F_47 ,
. V_103 = F_48 ,
} ;
V_34 -> V_66 = V_92 ;
V_34 -> V_104 = F_19 () ;
return F_50 ( V_34 , - 1 ) ;
}
static int F_51 ( struct V_64 * V_92 )
{
struct V_105 * V_106 ;
int V_4 , V_107 , V_1 ;
V_16 = F_52 ( & V_92 -> V_68 , sizeof( * V_16 ) , V_108 ) ;
if ( ! V_16 )
return - V_109 ;
V_106 = F_53 ( V_92 , V_110 , 0 ) ;
V_16 -> V_38 = F_54 ( & V_92 -> V_68 , V_106 ) ;
if ( F_55 ( V_16 -> V_38 ) )
return - V_109 ;
V_16 -> V_3 = 0 ;
for ( V_4 = 0 ; V_4 < V_111 ; V_4 ++ ) {
V_1 = F_56 ( V_92 , V_4 ) ;
if ( V_1 < 0 )
break;
if ( F_1 ( V_1 , V_16 -> V_2 , V_16 -> V_3 ) )
continue;
V_16 -> V_2 [ V_16 -> V_3 ++ ] = V_1 ;
}
if ( V_4 < V_111 ) {
F_57 ( & V_92 -> V_68 , L_5 ,
V_4 , V_111 ) ;
return - V_112 ;
}
V_16 -> V_17 = F_4 () ;
if ( ! V_16 -> V_17 ) {
F_57 ( & V_92 -> V_68 , L_6 ) ;
return - V_112 ;
}
V_16 -> V_34 = F_52 ( & V_92 -> V_68 , sizeof( * ( V_16 -> V_34 ) ) , V_108 ) ;
if ( ! V_16 -> V_34 )
return - V_109 ;
V_16 -> V_49 . V_74 = V_16 -> V_74 ;
V_16 -> V_49 . V_56 = V_16 -> V_56 ;
F_58 ( & V_16 -> V_49 . V_82 ) ;
V_107 = F_49 ( V_16 -> V_34 , V_92 ) ;
if ( V_107 )
return V_107 ;
return 0 ;
}
static int F_59 ( struct V_64 * V_92 )
{
if ( ! F_60 () )
return - V_67 ;
return F_61 ( V_92 -> V_68 . V_113 , NULL , NULL , & V_92 -> V_68 ) ;
}
static inline void F_62 ( struct V_114 * V_115 , T_2 V_116 , T_5 V_117 )
{
V_115 -> V_115 = V_118 | V_116 ;
V_115 -> V_117 = V_117 ;
}
static inline bool F_63 ( struct V_114 * V_115 )
{
return ! ! ( V_115 -> V_115 & V_118 ) ;
}
static inline bool F_64 ( struct V_114 * V_115 , T_5 V_117 )
{
return V_115 -> V_117 == ( V_117 & V_119 ) ;
}
static int F_65 ( struct V_120 * V_121 , int type )
{
int V_4 ;
bool V_122 ;
struct V_120 * V_123 ;
V_123 = F_66 ( V_121 , L_7 , 0 ) ;
for ( V_4 = 0 ; V_4 < V_124 ; V_4 ++ ) {
V_122 = V_125 [ V_4 ] . type == type ;
if ( V_122 && V_123 == V_125 [ V_4 ] . V_121 )
return V_4 ;
}
return - V_67 ;
}
int F_67 ( struct V_120 * V_121 )
{
return F_65 ( V_121 , V_126 ) ;
}
static void F_68 ( void )
{
int V_115 , V_127 ;
struct V_120 * V_128 ;
F_69 (cpu) {
V_128 = F_70 ( V_127 , NULL ) ;
if ( F_71 ( ! V_128 , L_8 ) )
continue;
V_115 = F_65 ( V_128 , V_129 ) ;
if ( V_115 < 0 )
continue;
F_62 ( & V_114 [ V_127 ] , V_115 , F_72 ( V_127 ) ) ;
}
F_69 (cpu) {
F_71 ( ! F_63 ( & V_114 [ V_127 ] ) ,
L_9 ,
V_127 ) ;
}
}
static void T_6 F_73 ( unsigned int V_115 , bool V_99 )
{
void T_7 * V_38 = V_125 [ V_115 ] . V_38 ;
F_15 ( V_99 ? V_130 : 0 , V_38 + V_131 ) ;
while ( F_3 ( V_6 + V_132 ) & 0x1 )
;
}
int T_6 F_74 ( T_5 V_117 )
{
int V_127 ;
bool V_133 ;
for ( V_127 = 0 ; V_127 < V_134 ; V_127 ++ ) {
V_133 = F_63 ( & V_114 [ V_127 ] ) ;
if ( V_133 && F_64 ( & V_114 [ V_127 ] , V_117 ) ) {
F_73 ( V_114 [ V_127 ] . V_115 , false ) ;
return 0 ;
}
}
return - V_67 ;
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
int T_6 F_78 ( struct V_120 * V_121 , bool V_99 )
{
int V_115 ;
if ( ! V_121 )
return - V_67 ;
V_115 = F_65 ( V_121 , V_126 ) ;
if ( F_79 ( V_115 < 0 , L_10 ,
V_121 -> V_135 ) )
return - V_67 ;
F_73 ( V_115 , V_99 ) ;
return 0 ;
}
int T_6 F_80 ( T_2 V_115 , bool V_99 )
{
if ( V_115 >= V_124 || V_125 [ V_115 ] . type == V_136 )
return - V_67 ;
if ( V_125 [ V_115 ] . type == V_129 )
return - V_137 ;
F_73 ( V_115 , V_99 ) ;
return 0 ;
}
static int F_81 ( void )
{
struct V_138 const * V_139 ;
int V_107 , V_4 , V_140 = 0 , V_141 = 0 ;
struct V_120 * V_142 , * V_143 ;
struct V_105 V_106 ;
const char * V_144 ;
bool V_145 ;
V_142 = F_82 ( NULL , V_146 ) ;
if ( ! V_142 )
return - V_67 ;
V_139 = F_83 ( V_146 , V_142 ) -> V_77 ;
if ( ! V_139 )
return - V_67 ;
V_124 = V_139 -> V_140 + V_139 -> V_141 ;
V_125 = F_84 ( V_124 , sizeof( * V_125 ) , V_108 ) ;
if ( ! V_125 )
return - V_109 ;
V_107 = F_85 ( V_142 , 0 , & V_106 ) ;
if ( ! V_107 ) {
V_6 = F_86 ( V_106 . V_100 , F_87 ( & V_106 ) ) ;
V_147 = V_106 . V_100 ;
}
if ( V_107 || ! V_6 ) {
F_71 ( 1 , L_11 ) ;
V_107 = - V_148 ;
goto V_149;
}
F_88 (np, cp) {
if ( ! F_83 ( V_150 , V_143 ) )
continue;
V_4 = V_140 + V_141 ;
if ( V_4 >= V_124 )
break;
if ( F_89 ( V_143 , L_12 ,
& V_144 ) ) {
F_71 ( 1 , L_13 ,
V_143 -> V_135 ) ;
continue;
}
V_145 = strcmp ( V_144 , L_14 ) == 0 ;
if ( ! V_145 && strcmp ( V_144 , L_15 ) ) {
F_71 ( 1 , L_16 ,
V_143 -> V_135 ) ;
continue;
}
V_107 = F_85 ( V_143 , 0 , & V_106 ) ;
if ( ! V_107 ) {
V_125 [ V_4 ] . V_38 = F_86 ( V_106 . V_100 , F_87 ( & V_106 ) ) ;
V_125 [ V_4 ] . V_151 = V_106 . V_100 ;
}
if ( V_107 || ! V_125 [ V_4 ] . V_38 ) {
F_71 ( 1 , L_17 , V_4 ) ;
continue;
}
if ( V_145 ) {
if ( F_90 ( V_140 >= V_139 -> V_140 ) )
continue;
V_125 [ V_4 ] . type = V_129 ;
++ V_140 ;
} else {
if ( F_90 ( V_141 >= V_139 -> V_141 ) )
continue;
V_125 [ V_4 ] . type = V_126 ;
++ V_141 ;
}
V_125 [ V_4 ] . V_121 = V_143 ;
}
F_68 () ;
F_91 ( & V_6 ) ;
F_91 ( & V_147 ) ;
F_91 ( & V_125 ) ;
F_91 ( & V_114 ) ;
F_92 ( V_125 , sizeof( * V_125 ) * V_124 ) ;
F_93 ( L_18 ) ;
return 0 ;
V_149:
F_94 ( V_125 ) ;
return V_107 ;
}
static int F_95 ( void )
{
if ( V_152 != - V_57 )
return V_152 ;
F_96 ( & V_153 ) ;
if ( V_152 == - V_57 )
V_152 = F_81 () ;
F_97 ( & V_153 ) ;
return V_152 ;
}
static int T_10 F_98 ( void )
{
int V_107 ;
V_107 = F_99 ( & V_154 ) ;
if ( V_107 )
return V_107 ;
return F_99 ( & V_155 ) ;
}
static int T_10 F_98 ( void )
{
return 0 ;
}
bool F_60 ( void )
{
return F_95 () == 0 ;
}
