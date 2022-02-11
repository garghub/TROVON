unsigned long F_1 ( void )
{
unsigned long V_1 ;
unsigned long V_2 ;
__asm__ __volatile__(
"rd %%psr, %0\n\t"
"or %0, %2, %1\n\t"
"wr %1, 0, %%psr\n\t"
"nop; nop; nop\n"
: "=&r" (retval), "=r" (tmp)
: "i" (PSR_PIL)
: "memory");
return V_1 ;
}
void F_2 ( void )
{
unsigned long V_2 ;
__asm__ __volatile__(
"rd %%psr, %0\n\t"
"andn %0, %1, %0\n\t"
"wr %0, 0, %%psr\n\t"
"nop; nop; nop\n"
: "=&r" (tmp)
: "i" (PSR_PIL)
: "memory");
}
void F_3 ( unsigned long V_3 )
{
unsigned long V_2 ;
__asm__ __volatile__(
"rd %%psr, %0\n\t"
"and %2, %1, %2\n\t"
"andn %0, %1, %0\n\t"
"wr %0, %2, %%psr\n\t"
"nop; nop; nop\n"
: "=&r" (tmp)
: "i" (PSR_PIL), "r" (old_psr)
: "memory");
}
unsigned int F_4 ( unsigned int V_4 , unsigned int V_5 )
{
unsigned long V_6 ;
unsigned int V_7 ;
F_5 ( & V_8 , V_6 ) ;
for ( V_7 = 1 ; V_7 < V_9 ; V_7 ++ ) {
if ( V_10 [ V_7 ] . V_4 == V_4 && V_10 [ V_7 ] . V_5 == V_5 )
goto V_11;
}
for ( V_7 = 1 ; V_7 < V_9 ; V_7 ++ ) {
if ( ! V_10 [ V_7 ] . V_12 )
break;
}
if ( V_7 < V_9 ) {
V_10 [ V_7 ] . V_4 = V_4 ;
V_10 [ V_7 ] . V_12 = V_7 ;
V_10 [ V_7 ] . V_5 = V_5 ;
} else {
F_6 ( V_13 L_1 ) ;
V_7 = 0 ;
}
V_11:
F_7 ( & V_8 , V_6 ) ;
return V_7 ;
}
void F_8 ( unsigned int V_12 )
{
struct V_14 * V_15 ;
unsigned long V_6 ;
unsigned int V_5 ;
F_9 ( V_12 >= V_9 ) ;
F_5 ( & V_16 , V_6 ) ;
V_15 = & V_10 [ V_12 ] ;
V_5 = V_15 -> V_5 ;
F_9 ( V_5 >= V_17 ) ;
V_15 -> V_18 = V_19 [ V_5 ] ;
V_19 [ V_5 ] = V_15 ;
F_7 ( & V_16 , V_6 ) ;
}
void F_10 ( unsigned int V_12 )
{
struct V_14 * V_15 , * * V_20 ;
unsigned long V_6 ;
F_9 ( V_12 >= V_9 ) ;
F_5 ( & V_16 , V_6 ) ;
V_15 = & V_10 [ V_12 ] ;
F_9 ( V_15 -> V_5 >= V_17 ) ;
V_20 = & V_19 [ V_15 -> V_5 ] ;
while ( * V_20 != V_15 )
V_20 = & ( * V_20 ) -> V_18 ;
* V_20 = V_15 -> V_18 ;
F_7 ( & V_16 , V_6 ) ;
}
int F_11 ( struct V_21 * V_15 , int V_22 )
{
int V_23 ;
#ifdef F_12
F_13 ( V_15 , L_2 ) ;
F_14 (j)
F_13 ( V_15 , L_3 , F_15 ( V_23 ) . V_24 ) ;
F_13 ( V_15 , L_4 ) ;
F_13 ( V_15 , L_5 ) ;
F_14 (j)
F_13 ( V_15 , L_3 , F_15 ( V_23 ) . V_25 ) ;
F_13 ( V_15 , L_6 ) ;
#endif
F_13 ( V_15 , L_7 ) ;
F_14 (j)
F_13 ( V_15 , L_3 , F_15 ( V_23 ) . V_26 ) ;
F_13 ( V_15 , L_8 ) ;
return 0 ;
}
void F_16 ( unsigned int V_5 , struct V_27 * V_28 )
{
struct V_27 * V_29 ;
struct V_14 * V_15 ;
F_9 ( V_5 > 15 ) ;
V_29 = F_17 ( V_28 ) ;
F_18 () ;
V_15 = V_19 [ V_5 ] ;
while ( V_15 ) {
struct V_14 * V_18 = V_15 -> V_18 ;
F_19 ( V_15 -> V_12 ) ;
V_15 = V_18 ;
}
F_20 () ;
F_17 ( V_29 ) ;
}
int F_21 ( unsigned int V_12 , T_1 V_30 )
{
unsigned int V_31 ;
int V_32 ;
V_32 = F_22 ( V_12 , V_30 , 0 , L_9 , NULL ) ;
if ( V_32 )
return - 1 ;
V_33 = V_12 ;
V_31 = ( V_12 & ( V_9 - 1 ) ) ;
#define F_23 ( T_2 ) \
table[SP_TRAP_IRQ1+(cpu_irq-1)].inst_one = SPARC_RD_PSR_L0; \
table[SP_TRAP_IRQ1+(cpu_irq-1)].inst_two = \
SPARC_BRANCH((unsigned long) floppy_hardint, \
(unsigned long) &table[SP_TRAP_IRQ1+(cpu_irq-1)].inst_two);\
table[SP_TRAP_IRQ1+(cpu_irq-1)].inst_three = SPARC_RD_WIM_L3; \
table[SP_TRAP_IRQ1+(cpu_irq-1)].inst_four = SPARC_NOP;
F_23 (sparc_ttable)
#if V_34 F_12
if ( V_35 != V_36 ) {
struct V_37 * V_38 ;
V_38 = & V_39 ;
F_23 (trap_table)
V_38 = & V_40 ;
F_23 (trap_table)
V_38 = & V_41 ;
F_23 (trap_table)
}
#endif
#undef F_23
F_24 () ;
return 0 ;
}
void F_25 ( int V_12 , void * V_42 , struct V_27 * V_28 )
{
struct V_27 * V_29 ;
V_29 = F_17 ( V_28 ) ;
F_18 () ;
F_19 ( V_33 ) ;
F_20 () ;
F_17 ( V_29 ) ;
}
void T_3 F_26 ( void )
{
switch ( V_35 ) {
case V_43 :
F_27 () ;
if ( F_28 () )
F_29 () ;
else
F_30 () ;
break;
case V_44 :
F_31 () ;
break;
case V_36 :
F_32 () ;
break;
default:
F_33 ( L_10 ) ;
break;
}
}
