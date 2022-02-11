static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
V_2 -> V_2 = V_5 | V_3 ;
V_2 -> V_4 = V_4 ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_2 & V_5 ) ;
}
static inline bool F_3 ( struct V_1 * V_2 , T_2 V_4 )
{
return V_2 -> V_4 == ( V_4 & V_6 ) ;
}
static int F_4 ( struct V_7 * V_8 , int type )
{
int V_9 ;
bool V_10 ;
struct V_7 * V_11 ;
V_11 = F_5 ( V_8 , L_1 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
V_10 = V_13 [ V_9 ] . type == type ;
if ( V_10 && V_11 == V_13 [ V_9 ] . V_8 )
return V_9 ;
}
return - V_14 ;
}
int F_6 ( struct V_7 * V_8 )
{
return F_4 ( V_8 , V_15 ) ;
}
static void T_3 F_7 ( void )
{
int V_2 , V_16 , V_17 ;
T_2 V_18 ;
const T_1 * V_19 ;
struct V_7 * V_20 , * V_21 ;
V_21 = F_8 ( L_2 ) ;
if ( F_9 ( ! V_21 , L_3 ) )
return;
if ( F_10 ( F_11 ( V_21 , L_4 , & V_16 ) ) )
V_16 = F_12 ( V_21 ) ;
F_13 (cpus, cpun) {
if ( F_14 ( V_20 -> type , L_5 ) )
continue;
V_19 = F_15 ( V_20 , L_6 , NULL ) ;
if ( F_9 ( ! V_19 , L_7 , V_20 -> V_22 ) )
continue;
V_18 = F_16 ( V_19 , V_16 ) ;
V_17 = F_17 ( V_18 & V_6 ) ;
if ( V_17 < 0 || ! F_18 ( V_17 ) )
continue;
V_2 = F_4 ( V_20 , V_23 ) ;
if ( V_2 < 0 )
continue;
F_1 ( & V_1 [ V_17 ] , V_2 , F_19 ( V_17 ) ) ;
}
F_20 (cpu) {
F_9 ( ! F_2 ( & V_1 [ V_17 ] ) ,
L_8 ,
V_17 ) ;
}
}
static void T_4 F_21 ( unsigned int V_2 , bool V_24 )
{
void T_5 * V_25 = V_13 [ V_2 ] . V_25 ;
F_22 ( V_24 ? V_26 : 0 , V_25 + V_27 ) ;
while ( F_23 ( V_28 + V_29 ) & 0x1 )
;
}
int T_4 F_24 ( T_2 V_4 )
{
int V_17 ;
bool V_30 ;
for ( V_17 = 0 ; V_17 < V_31 ; V_17 ++ ) {
V_30 = F_2 ( & V_1 [ V_17 ] ) ;
if ( V_30 && F_3 ( & V_1 [ V_17 ] , V_4 ) ) {
F_21 ( V_1 [ V_17 ] . V_2 , false ) ;
return 0 ;
}
}
return - V_14 ;
}
T_6 void T_7 F_25 ( void )
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
" mov r3, #"__stringify(CCI_ENABLE_REQ)" \n"
" str r3, [r0, #"__stringify(CCI_PORT_CTRL)"] \n"
" adr r1, 7f \n"
" ldr r0, [r1] \n"
" ldr r0, [r0, r1] @ cci_ctrl_base \n"
"4: ldr r1, [r0, #"__stringify(CCI_CTRL_STATUS)"] \n"
" tst r1, #1 \n"
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
#ifndef F_26
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)),
#else
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)+4),
#endif
[offsetof_cpu_port_port] "i" (offsetof(struct cpu_port, port)),
[sizeof_struct_cpu_port] "i" (sizeof(struct cpu_port)),
[sizeof_struct_ace_port] "i" (sizeof(struct cci_ace_port)),
[offsetof_port_phys] "i" (offsetof(struct cci_ace_port, phys)) );
F_27 () ;
}
int T_4 F_28 ( struct V_7 * V_8 , bool V_24 )
{
int V_2 ;
if ( ! V_8 )
return - V_14 ;
V_2 = F_4 ( V_8 , V_15 ) ;
if ( F_29 ( V_2 < 0 , L_9 ,
V_8 -> V_22 ) )
return - V_14 ;
F_21 ( V_2 , V_24 ) ;
return 0 ;
}
int T_4 F_30 ( T_1 V_2 , bool V_24 )
{
if ( V_2 >= V_12 || V_13 [ V_2 ] . type == V_32 )
return - V_14 ;
if ( V_13 [ V_2 ] . type == V_23 )
return - V_33 ;
F_21 ( V_2 , V_24 ) ;
return 0 ;
}
static int T_3 F_31 ( void )
{
struct V_34 const * V_35 ;
int V_36 , V_9 , V_37 = 0 , V_38 = 0 ;
struct V_7 * V_39 , * V_40 ;
struct V_41 V_42 ;
const char * V_43 ;
bool V_44 ;
V_39 = F_32 ( NULL , V_45 ) ;
if ( ! V_39 )
return - V_14 ;
V_35 = F_33 ( V_45 , V_39 ) -> V_46 ;
if ( ! V_35 )
return - V_14 ;
V_12 = V_35 -> V_37 + V_35 -> V_38 ;
V_13 = F_34 ( sizeof( * V_13 ) , V_12 , V_47 ) ;
if ( ! V_13 )
return - V_48 ;
V_36 = F_35 ( V_39 , 0 , & V_42 ) ;
if ( ! V_36 ) {
V_28 = F_36 ( V_42 . V_49 , F_37 ( & V_42 ) ) ;
V_50 = V_42 . V_49 ;
}
if ( V_36 || ! V_28 ) {
F_9 ( 1 , L_10 ) ;
V_36 = - V_51 ;
goto V_52;
}
F_13 (np, cp) {
if ( ! F_33 ( V_53 , V_40 ) )
continue;
V_9 = V_37 + V_38 ;
if ( V_9 >= V_12 )
break;
if ( F_38 ( V_40 , L_11 ,
& V_43 ) ) {
F_9 ( 1 , L_12 ,
V_40 -> V_22 ) ;
continue;
}
V_44 = strcmp ( V_43 , L_13 ) == 0 ;
if ( ! V_44 && strcmp ( V_43 , L_14 ) ) {
F_9 ( 1 , L_15 ,
V_40 -> V_22 ) ;
continue;
}
V_36 = F_35 ( V_40 , 0 , & V_42 ) ;
if ( ! V_36 ) {
V_13 [ V_9 ] . V_25 = F_36 ( V_42 . V_49 , F_37 ( & V_42 ) ) ;
V_13 [ V_9 ] . V_54 = V_42 . V_49 ;
}
if ( V_36 || ! V_13 [ V_9 ] . V_25 ) {
F_9 ( 1 , L_16 , V_9 ) ;
continue;
}
if ( V_44 ) {
if ( F_10 ( V_37 >= V_35 -> V_37 ) )
continue;
V_13 [ V_9 ] . type = V_23 ;
++ V_37 ;
} else {
if ( F_10 ( V_38 >= V_35 -> V_38 ) )
continue;
V_13 [ V_9 ] . type = V_15 ;
++ V_38 ;
}
V_13 [ V_9 ] . V_8 = V_40 ;
}
F_7 () ;
F_39 ( & V_28 ) ;
F_39 ( & V_50 ) ;
F_39 ( & V_13 ) ;
F_39 ( & V_1 ) ;
F_40 ( V_13 , sizeof( * V_13 ) * V_12 ) ;
F_41 ( L_17 ) ;
return 0 ;
V_52:
F_42 ( V_13 ) ;
return V_36 ;
}
static int T_3 F_43 ( void )
{
if ( V_55 != - V_56 )
return V_55 ;
F_44 ( & V_57 ) ;
if ( V_55 == - V_56 )
V_55 = F_31 () ;
F_45 ( & V_57 ) ;
return V_55 ;
}
bool T_3 F_46 ( void )
{
return F_43 () == 0 ;
}
