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
int V_2 , V_16 ;
struct V_7 * V_17 ;
F_8 (cpu) {
V_17 = F_9 ( V_16 , NULL ) ;
if ( F_10 ( ! V_17 , L_2 ) )
continue;
V_2 = F_4 ( V_17 , V_18 ) ;
if ( V_2 < 0 )
continue;
F_1 ( & V_1 [ V_16 ] , V_2 , F_11 ( V_16 ) ) ;
}
F_8 (cpu) {
F_10 ( ! F_2 ( & V_1 [ V_16 ] ) ,
L_3 ,
V_16 ) ;
}
}
static void T_4 F_12 ( unsigned int V_2 , bool V_19 )
{
void T_5 * V_20 = V_13 [ V_2 ] . V_20 ;
F_13 ( V_19 ? V_21 : 0 , V_20 + V_22 ) ;
while ( F_14 ( V_23 + V_24 ) & 0x1 )
;
}
int T_4 F_15 ( T_2 V_4 )
{
int V_16 ;
bool V_25 ;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ ) {
V_25 = F_2 ( & V_1 [ V_16 ] ) ;
if ( V_25 && F_3 ( & V_1 [ V_16 ] , V_4 ) ) {
F_12 ( V_1 [ V_16 ] . V_2 , false ) ;
return 0 ;
}
}
return - V_14 ;
}
T_6 void T_7 F_16 ( void )
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
#ifndef F_17
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)),
#else
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)+4),
#endif
[offsetof_cpu_port_port] "i" (offsetof(struct cpu_port, port)),
[sizeof_struct_cpu_port] "i" (sizeof(struct cpu_port)),
[sizeof_struct_ace_port] "i" (sizeof(struct cci_ace_port)),
[offsetof_port_phys] "i" (offsetof(struct cci_ace_port, phys)) );
F_18 () ;
}
int T_4 F_19 ( struct V_7 * V_8 , bool V_19 )
{
int V_2 ;
if ( ! V_8 )
return - V_14 ;
V_2 = F_4 ( V_8 , V_15 ) ;
if ( F_20 ( V_2 < 0 , L_4 ,
V_8 -> V_27 ) )
return - V_14 ;
F_12 ( V_2 , V_19 ) ;
return 0 ;
}
int T_4 F_21 ( T_1 V_2 , bool V_19 )
{
if ( V_2 >= V_12 || V_13 [ V_2 ] . type == V_28 )
return - V_14 ;
if ( V_13 [ V_2 ] . type == V_18 )
return - V_29 ;
F_12 ( V_2 , V_19 ) ;
return 0 ;
}
static int T_3 F_22 ( void )
{
struct V_30 const * V_31 ;
int V_32 , V_9 , V_33 = 0 , V_34 = 0 ;
struct V_7 * V_35 , * V_36 ;
struct V_37 V_38 ;
const char * V_39 ;
bool V_40 ;
V_35 = F_23 ( NULL , V_41 ) ;
if ( ! V_35 )
return - V_14 ;
V_31 = F_24 ( V_41 , V_35 ) -> V_42 ;
if ( ! V_31 )
return - V_14 ;
V_12 = V_31 -> V_33 + V_31 -> V_34 ;
V_13 = F_25 ( sizeof( * V_13 ) , V_12 , V_43 ) ;
if ( ! V_13 )
return - V_44 ;
V_32 = F_26 ( V_35 , 0 , & V_38 ) ;
if ( ! V_32 ) {
V_23 = F_27 ( V_38 . V_45 , F_28 ( & V_38 ) ) ;
V_46 = V_38 . V_45 ;
}
if ( V_32 || ! V_23 ) {
F_10 ( 1 , L_5 ) ;
V_32 = - V_47 ;
goto V_48;
}
F_29 (np, cp) {
if ( ! F_24 ( V_49 , V_36 ) )
continue;
V_9 = V_33 + V_34 ;
if ( V_9 >= V_12 )
break;
if ( F_30 ( V_36 , L_6 ,
& V_39 ) ) {
F_10 ( 1 , L_7 ,
V_36 -> V_27 ) ;
continue;
}
V_40 = strcmp ( V_39 , L_8 ) == 0 ;
if ( ! V_40 && strcmp ( V_39 , L_9 ) ) {
F_10 ( 1 , L_10 ,
V_36 -> V_27 ) ;
continue;
}
V_32 = F_26 ( V_36 , 0 , & V_38 ) ;
if ( ! V_32 ) {
V_13 [ V_9 ] . V_20 = F_27 ( V_38 . V_45 , F_28 ( & V_38 ) ) ;
V_13 [ V_9 ] . V_50 = V_38 . V_45 ;
}
if ( V_32 || ! V_13 [ V_9 ] . V_20 ) {
F_10 ( 1 , L_11 , V_9 ) ;
continue;
}
if ( V_40 ) {
if ( F_31 ( V_33 >= V_31 -> V_33 ) )
continue;
V_13 [ V_9 ] . type = V_18 ;
++ V_33 ;
} else {
if ( F_31 ( V_34 >= V_31 -> V_34 ) )
continue;
V_13 [ V_9 ] . type = V_15 ;
++ V_34 ;
}
V_13 [ V_9 ] . V_8 = V_36 ;
}
F_7 () ;
F_32 ( & V_23 ) ;
F_32 ( & V_46 ) ;
F_32 ( & V_13 ) ;
F_32 ( & V_1 ) ;
F_33 ( V_13 , sizeof( * V_13 ) * V_12 ) ;
F_34 ( L_12 ) ;
return 0 ;
V_48:
F_35 ( V_13 ) ;
return V_32 ;
}
static int T_3 F_36 ( void )
{
if ( V_51 != - V_52 )
return V_51 ;
F_37 ( & V_53 ) ;
if ( V_51 == - V_52 )
V_51 = F_22 () ;
F_38 ( & V_53 ) ;
return V_51 ;
}
bool T_3 F_39 ( void )
{
return F_36 () == 0 ;
}
