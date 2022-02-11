void T_1 F_1 ( void )
{
#ifdef F_2
F_3 ( L_1 ) ;
#endif
F_4 ( & V_1 , V_2 ,
V_3 - V_2 ) ;
#ifdef F_5
F_3 ( L_2 ) ;
if ( F_6 ( ( void * ) ( 0x50f0a000 ) ) ) {
* ( long * ) ( 0x50f0a014 ) = 0x7fffL ;
* ( long * ) ( 0x50f0a010 ) = 0L ;
}
F_3 ( L_3 ) ;
#endif
if ( V_4 )
F_7 () ;
else
F_8 () ;
if ( V_5 )
F_9 () ;
if ( V_6 )
F_10 () ;
F_11 () ;
if ( F_12 ( V_7 , V_8 , 0 , L_4 ,
V_8 ) )
F_13 ( L_5 ) ;
#ifdef F_2
F_3 ( L_6 ) ;
#endif
}
void F_14 ( unsigned int V_9 )
{
int V_10 = F_15 ( V_9 ) ;
switch( V_10 ) {
case 1 :
F_16 ( V_9 ) ;
break;
case 2 :
case 7 :
if ( V_4 )
F_17 ( V_9 ) ;
else
F_16 ( V_9 ) ;
break;
case 3 :
case 5 :
case 6 :
if ( V_5 )
F_18 ( V_9 ) ;
else if ( V_4 )
F_17 ( V_9 ) ;
break;
case 4 :
if ( V_5 )
F_18 ( V_9 ) ;
break;
case 8 :
if ( V_6 )
F_19 ( V_9 ) ;
break;
}
}
void F_20 ( unsigned int V_9 )
{
int V_10 = F_15 ( V_9 ) ;
switch( V_10 ) {
case 1 :
F_21 ( V_9 ) ;
break;
case 2 :
case 7 :
if ( V_4 )
F_22 ( V_9 ) ;
else
F_21 ( V_9 ) ;
break;
case 3 :
case 5 :
case 6 :
if ( V_5 )
F_23 ( V_9 ) ;
else if ( V_4 )
F_22 ( V_9 ) ;
break;
case 4 :
if ( V_5 )
F_23 ( V_9 ) ;
break;
case 8 :
if ( V_6 )
F_24 ( V_9 ) ;
break;
}
}
void F_25 ( unsigned int V_9 )
{
switch( F_15 ( V_9 ) ) {
case 1 :
F_26 ( V_9 ) ;
break;
case 2 :
case 7 :
if ( V_4 )
F_27 ( V_9 ) ;
else
F_26 ( V_9 ) ;
break;
case 3 :
case 5 :
case 6 :
if ( V_5 )
F_28 ( V_9 ) ;
else if ( V_4 )
F_27 ( V_9 ) ;
break;
case 4 :
if ( V_5 )
F_28 ( V_9 ) ;
break;
case 8 :
if ( V_6 )
F_29 ( V_9 ) ;
break;
}
}
int F_30 ( unsigned int V_9 )
{
switch( F_15 ( V_9 ) ) {
case 1 :
return F_31 ( V_9 ) ;
case 2 :
case 7 :
if ( V_4 )
return F_32 ( V_9 ) ;
else
return F_31 ( V_9 ) ;
case 3 :
case 5 :
case 6 :
if ( V_5 )
return F_33 ( V_9 ) ;
else if ( V_4 )
return F_32 ( V_9 ) ;
break;
case 4 :
if ( V_5 )
F_33 ( V_9 ) ;
break;
}
return 0 ;
}
T_2 F_34 ( int V_9 , void * V_11 )
{
if ( V_12 [ V_9 ] < 10 ) {
F_3 ( L_7 , V_9 ) ;
V_12 [ V_9 ] ++ ;
}
return V_13 ;
}
T_2 V_8 ( int V_9 , void * V_11 )
{
int V_14 ;
V_15 ++ ;
for ( V_14 = 0 ; V_14 < 100 ; V_14 ++ )
F_35 ( 1000 ) ;
if ( V_15 == 1 ) {
V_16 = 1 ;
F_3 ( L_8 ) ;
} else {
F_3 ( L_9 ) ;
V_16 = 0 ;
}
F_36 () ;
while ( V_16 == 1 )
F_35 ( 1000 ) ;
if ( V_17 >= 8 ) {
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
V_15 -- ;
return V_13 ;
}
