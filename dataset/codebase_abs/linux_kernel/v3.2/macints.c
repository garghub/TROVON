void T_1 F_1 ( void )
{
#ifdef F_2
F_3 ( L_1 ) ;
#endif
F_4 ( & V_1 , V_2 , V_3 ,
V_4 - V_3 ) ;
#ifdef F_5
F_3 ( L_2 ) ;
if ( F_6 ( ( void * ) ( 0x50f0a000 ) ) ) {
* ( long * ) ( 0x50f0a014 ) = 0x7fffL ;
* ( long * ) ( 0x50f0a010 ) = 0L ;
}
F_3 ( L_3 ) ;
#endif
if ( V_5 )
F_7 () ;
else
F_8 () ;
if ( V_6 )
F_9 () ;
if ( V_7 )
F_10 () ;
F_11 () ;
if ( F_12 ( V_8 , V_9 , 0 , L_4 ,
V_9 ) )
F_13 ( L_5 ) ;
#ifdef F_2
F_3 ( L_6 ) ;
#endif
}
void F_14 ( struct V_10 * V_11 )
{
int V_12 = V_11 -> V_12 ;
int V_13 = F_15 ( V_12 ) ;
switch( V_13 ) {
case 1 :
F_16 ( V_12 ) ;
break;
case 2 :
case 7 :
if ( V_5 )
F_17 ( V_12 ) ;
else
F_16 ( V_12 ) ;
break;
case 3 :
case 5 :
case 6 :
if ( V_6 )
F_18 ( V_12 ) ;
else if ( V_5 )
F_17 ( V_12 ) ;
break;
case 4 :
if ( V_6 )
F_18 ( V_12 ) ;
break;
case 8 :
if ( V_7 )
F_19 ( V_12 ) ;
break;
}
}
void F_20 ( struct V_10 * V_11 )
{
int V_12 = V_11 -> V_12 ;
int V_13 = F_15 ( V_12 ) ;
switch( V_13 ) {
case 1 :
F_21 ( V_12 ) ;
break;
case 2 :
case 7 :
if ( V_5 )
F_22 ( V_12 ) ;
else
F_21 ( V_12 ) ;
break;
case 3 :
case 5 :
case 6 :
if ( V_6 )
F_23 ( V_12 ) ;
else if ( V_5 )
F_22 ( V_12 ) ;
break;
case 4 :
if ( V_6 )
F_23 ( V_12 ) ;
break;
case 8 :
if ( V_7 )
F_24 ( V_12 ) ;
break;
}
}
void F_25 ( unsigned int V_12 )
{
switch( F_15 ( V_12 ) ) {
case 1 :
F_26 ( V_12 ) ;
break;
case 2 :
case 7 :
if ( V_5 )
F_27 ( V_12 ) ;
else
F_26 ( V_12 ) ;
break;
case 3 :
case 5 :
case 6 :
if ( V_6 )
F_28 ( V_12 ) ;
else if ( V_5 )
F_27 ( V_12 ) ;
break;
case 4 :
if ( V_6 )
F_28 ( V_12 ) ;
break;
case 8 :
if ( V_7 )
F_29 ( V_12 ) ;
break;
}
}
int F_30 ( unsigned int V_12 )
{
switch( F_15 ( V_12 ) ) {
case 1 :
return F_31 ( V_12 ) ;
case 2 :
case 7 :
if ( V_5 )
return F_32 ( V_12 ) ;
else
return F_31 ( V_12 ) ;
case 3 :
case 5 :
case 6 :
if ( V_6 )
return F_33 ( V_12 ) ;
else if ( V_5 )
return F_32 ( V_12 ) ;
break;
case 4 :
if ( V_6 )
return F_33 ( V_12 ) ;
break;
}
return 0 ;
}
T_2 F_34 ( int V_12 , void * V_14 )
{
if ( V_15 [ V_12 ] < 10 ) {
F_3 ( L_7 , V_12 ) ;
V_15 [ V_12 ] ++ ;
}
return V_16 ;
}
T_2 V_9 ( int V_12 , void * V_14 )
{
int V_17 ;
V_18 ++ ;
for ( V_17 = 0 ; V_17 < 100 ; V_17 ++ )
F_35 ( 1000 ) ;
if ( V_18 == 1 ) {
V_19 = 1 ;
F_3 ( L_8 ) ;
} else {
F_3 ( L_9 ) ;
V_19 = 0 ;
}
F_36 () ;
while ( V_19 == 1 )
F_35 ( 1000 ) ;
if ( V_20 >= 8 ) {
#if 0
struct pt_regs *fp = get_irq_regs();
show_state();
printk("PC: %08lx\nSR: %04x SP: %p\n", fp->pc, fp->sr, fp);
printk("d0: %08lx d1: %08lx d2: %08lx d3: %08lx\n",
fp->d0, fp->d1, fp->d2, fp->d3);
printk("d4: %08lx d5: %08lx a0: %08lx a1: %08lx\n",
fp->d4, fp->d5, fp->a0, fp->a1);
if (STACK_MAGIC != *(unsigned long *)current->kernel_stack_page)
printk("Corrupted stack page\n");
printk("Process %s (pid: %d, stackpage=%08lx)\n",
current->comm, current->pid, current->kernel_stack_page);
if (intr_count == 1)
dump_stack((struct frame *)fp);
#else
#endif
}
V_18 -- ;
return V_16 ;
}
