static inline void F_1 ( const int V_1 , const int V_2 )
{
asm volatile(
".set push\n\t"
".set noreorder\n\t"
".balign %0\n\t"
".rept %1\n\t"
"nop\n\t"
".endr\n\t"
".set pop"
:
: GCC_IMM_ASM() (align), GCC_IMM_ASM() (mod));
}
static inline void F_2 ( long * V_3 , long * V_4 , long * V_5 ,
const int V_1 , const int V_2 )
{
unsigned long V_6 ;
int V_7 , V_8 ;
long V_9 , V_10 , V_11 , V_12 , V_13 ;
F_3 ( V_6 ) ;
asm volatile(
""
: "=r" (m1), "=r" (m2), "=r" (s)
: "0" (5), "1" (8), "2" (5));
F_1 ( V_1 , V_2 ) ;
asm volatile(
".set push\n\t"
".set noat\n\t"
".set noreorder\n\t"
".set nomacro\n\t"
"mult %2, %3\n\t"
"dsll32 %0, %4, %5\n\t"
"mflo $0\n\t"
"dsll32 %1, %4, %5\n\t"
"nop\n\t"
".set pop"
: "=&r" (lv1), "=r" (lw)
: "r" (m1), "r" (m2), "r" (s), "I" (0)
: "hi", "lo", GCC_REG_ACCUM);
asm volatile(
""
: "=r" (m1), "=r" (m2), "=r" (s)
: "0" (m1), "1" (m2), "2" (s));
F_1 ( V_1 , V_2 ) ;
V_9 = V_7 * V_8 ;
V_12 = V_10 << 32 ;
asm volatile(
""
: "=r" (lv2)
: "0" (lv2), "r" (p));
F_4 ( V_6 ) ;
* V_3 = V_11 ;
* V_4 = V_12 ;
* V_5 = V_13 ;
}
static inline void F_5 ( void )
{
long V_3 [ 8 ] , V_4 [ 8 ] , V_5 [ 8 ] ;
int V_14 , V_15 , V_16 ;
F_6 ( L_1 ) ;
F_2 ( & V_3 [ 0 ] , & V_4 [ 0 ] , & V_5 [ 0 ] , 32 , 0 ) ;
F_2 ( & V_3 [ 1 ] , & V_4 [ 1 ] , & V_5 [ 1 ] , 32 , 1 ) ;
F_2 ( & V_3 [ 2 ] , & V_4 [ 2 ] , & V_5 [ 2 ] , 32 , 2 ) ;
F_2 ( & V_3 [ 3 ] , & V_4 [ 3 ] , & V_5 [ 3 ] , 32 , 3 ) ;
F_2 ( & V_3 [ 4 ] , & V_4 [ 4 ] , & V_5 [ 4 ] , 32 , 4 ) ;
F_2 ( & V_3 [ 5 ] , & V_4 [ 5 ] , & V_5 [ 5 ] , 32 , 5 ) ;
F_2 ( & V_3 [ 6 ] , & V_4 [ 6 ] , & V_5 [ 6 ] , 32 , 6 ) ;
F_2 ( & V_3 [ 7 ] , & V_4 [ 7 ] , & V_5 [ 7 ] , 32 , 7 ) ;
V_14 = 0 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ )
if ( V_3 [ V_16 ] != V_5 [ V_16 ] )
V_14 = 1 ;
if ( V_14 == 0 ) {
F_6 ( L_2 ) ;
return;
}
F_6 ( L_3 ) ;
V_15 = 1 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ )
if ( V_4 [ V_16 ] != V_5 [ V_16 ] )
V_15 = 0 ;
if ( V_15 == 1 ) {
F_6 ( L_4 ) ;
return;
}
F_6 ( L_2 ) ;
F_7 ( V_17 , ! V_18 ? V_19 : V_20 ) ;
}
T_1 void T_2 F_8 ( struct V_21 * V_22 )
{
V_23 = 1 ;
V_22 -> V_24 += 4 ;
}
static inline void F_9 ( void )
{
extern T_1 void V_25 ( void ) ;
unsigned long V_6 ;
void * V_26 ;
long V_27 , V_28 ;
F_6 ( L_5 ) ;
F_3 ( V_6 ) ;
V_26 = F_10 ( 12 , V_25 ) ;
asm volatile(
".set push\n\t"
".set noat\n\t"
".set noreorder\n\t"
".set nomacro\n\t"
"addiu %1, $0, %2\n\t"
"dsrl %1, %1, 1\n\t"
#ifdef F_11
".set daddi\n\t"
#endif
"daddi %0, %1, %3\n\t"
".set pop"
: "=r" (v), "=&r" (tmp)
: "I" (0xffffffffffffdb9aUL), "I" (0x1234));
F_10 ( 12 , V_26 ) ;
F_4 ( V_6 ) ;
if ( V_23 ) {
F_6 ( L_2 ) ;
return;
}
F_6 ( L_3 ) ;
F_3 ( V_6 ) ;
V_26 = F_10 ( 12 , V_25 ) ;
asm volatile(
"addiu %1, $0, %2\n\t"
"dsrl %1, %1, 1\n\t"
"daddi %0, %1, %3"
: "=r" (v), "=&r" (tmp)
: "I" (0xffffffffffffdb9aUL), "I" (0x1234));
F_10 ( 12 , V_26 ) ;
F_4 ( V_6 ) ;
if ( V_23 ) {
F_6 ( L_4 ) ;
return;
}
F_6 ( L_2 ) ;
F_7 ( V_17 , ! V_29 ? V_30 : V_20 ) ;
}
static inline void F_12 ( void )
{
long V_27 , V_5 , V_28 ;
F_6 ( L_6 ) ;
asm volatile(
".set push\n\t"
".set noat\n\t"
".set noreorder\n\t"
".set nomacro\n\t"
"addiu %2, $0, %3\n\t"
"dsrl %2, %2, 1\n\t"
#ifdef F_11
".set daddi\n\t"
#endif
"daddiu %0, %2, %4\n\t"
"addiu %1, $0, %4\n\t"
"daddu %1, %2\n\t"
".set pop"
: "=&r" (v), "=&r" (w), "=&r" (tmp)
: "I" (0xffffffffffffdb9aUL), "I" (0x1234));
V_31 = V_27 != V_5 ;
if ( ! V_31 ) {
F_6 ( L_2 ) ;
return;
}
F_6 ( L_3 ) ;
asm volatile(
"addiu %2, $0, %3\n\t"
"dsrl %2, %2, 1\n\t"
"daddiu %0, %2, %4\n\t"
"addiu %1, $0, %4\n\t"
"daddu %1, %2"
: "=&r" (v), "=&r" (w), "=&r" (tmp)
: "I" (0xffffffffffffdb9aUL), "I" (0x1234));
if ( V_27 == V_5 ) {
F_6 ( L_4 ) ;
return;
}
F_6 ( L_2 ) ;
F_7 ( V_17 , ! V_29 ? V_30 : V_20 ) ;
}
void T_2 F_13 ( void )
{
F_5 () ;
F_12 () ;
}
void T_2 F_14 ( void )
{
F_9 () ;
}
