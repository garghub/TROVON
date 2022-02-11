void F_1 ( T_1 V_1 )
{
V_2 |= V_1 ;
}
void F_2 ( T_1 V_1 )
{
V_2 &= ~ V_1 ;
}
static int F_3 ( T_2 V_3 )
{
unsigned long V_4 ;
if ( V_3 != V_5 )
return - V_6 ;
V_4 = F_4 ( V_7 + V_8 ) ;
V_4 &= 0xffff0000 ;
F_5 () ;
F_6 ( V_4 , V_7 + V_8 ) ;
return 0 ;
}
T_3 int F_7 ( T_4 V_9 )
{
void * V_10 = F_8 ( F_9 () ) ;
F_6 ( V_2 << 16 , V_7 + V_8 ) ;
__asm__("movl %0,%%eax" : : "r" (pgd_addr));
__asm__("call *(%%edi); cld"
: : "D" (&ofw_bios_entry));
__asm__("movb $0x34, %al\n\t"
"outb %al, $0x70\n\t"
"movb $0x30, %al\n\t"
"outb %al, $0x71\n\t");
return 0 ;
}
static void F_10 ( void )
{
F_11 ( V_11 L_1 ) ;
F_6 ( 0x40000000 , V_12 + V_13 ) ;
F_6 ( 0x40000000 , V_12 + V_14 ) ;
F_6 ( 0x40000000 , V_12 + V_15 ) ;
F_6 ( 0x40000000 , V_12 + V_16 ) ;
F_6 ( 0x0002ffff , V_12 + V_17 ) ;
F_6 ( 0xffffffff , V_7 + V_18 ) ;
F_6 ( 0x00002000 , V_7 + V_19 ) ;
}
static int F_12 ( T_2 V_3 )
{
return V_3 == V_5 ;
}
static int F_13 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
int V_24 ;
if ( ! F_14 () )
return - V_25 ;
V_24 = F_15 ( V_21 ) ;
if ( V_24 )
return V_24 ;
V_23 = F_16 ( V_21 , V_26 , 0 ) ;
if ( ! V_23 ) {
F_17 ( & V_21 -> V_27 , L_2 ) ;
return - V_28 ;
}
if ( strcmp ( V_21 -> V_29 , L_3 ) == 0 )
V_12 = V_23 -> V_30 ;
else if ( strcmp ( V_21 -> V_29 , L_4 ) == 0 )
V_7 = V_23 -> V_30 ;
if ( V_12 && V_7 ) {
F_18 ( & V_31 ) ;
V_32 = F_10 ;
F_11 ( V_11 L_5 ) ;
}
return 0 ;
}
static int F_19 ( struct V_20 * V_21 )
{
F_20 ( V_21 ) ;
if ( strcmp ( V_21 -> V_29 , L_3 ) == 0 )
V_12 = 0 ;
else if ( strcmp ( V_21 -> V_29 , L_4 ) == 0 )
V_7 = 0 ;
V_32 = NULL ;
return 0 ;
}
static int T_5 F_21 ( void )
{
int V_33 ;
V_33 = F_22 ( & V_34 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_22 ( & V_35 ) ;
if ( V_33 )
F_23 ( & V_34 ) ;
return V_33 ;
}
