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
int V_5 ;
if ( V_3 != V_6 )
return - V_7 ;
V_5 = F_4 ( V_8 , NULL , 0 , NULL , 0 ) ;
if ( V_5 )
return V_5 ;
V_4 = F_5 ( V_9 + V_10 ) ;
V_4 &= 0xffff0000 ;
F_6 () ;
F_7 ( V_4 , V_9 + V_10 ) ;
F_4 ( V_11 , NULL , 0 , NULL , 0 ) ;
F_4 ( V_12 , NULL , 0 , NULL , 0 ) ;
F_4 ( V_12 , NULL , 0 , NULL , 0 ) ;
return 0 ;
}
T_3 int F_8 ( T_4 V_13 )
{
void * V_14 = F_9 ( F_10 () ) ;
F_7 ( V_2 << 16 , V_9 + V_10 ) ;
__asm__("movl %0,%%eax" : : "r" (pgd_addr));
__asm__("call *(%%edi); cld"
: : "D" (&ofw_bios_entry));
__asm__("movb $0x34, %al\n\t"
"outb %al, $0x70\n\t"
"movb $0x30, %al\n\t"
"outb %al, $0x71\n\t");
return 0 ;
}
static void F_11 ( void )
{
F_12 ( V_15 L_1 ) ;
F_7 ( 0x40000000 , V_16 + V_17 ) ;
F_7 ( 0x40000000 , V_16 + V_18 ) ;
F_7 ( 0x40000000 , V_16 + V_19 ) ;
F_7 ( 0x40000000 , V_16 + V_20 ) ;
F_7 ( 0x0002ffff , V_16 + V_21 ) ;
F_7 ( 0xffffffff , V_9 + V_22 ) ;
F_7 ( 0x00002000 , V_9 + V_23 ) ;
}
static int F_13 ( T_2 V_3 )
{
return V_3 == V_6 ;
}
static int T_5 F_14 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
int V_28 ;
if ( ! F_15 () )
return - V_29 ;
V_28 = F_16 ( V_25 ) ;
if ( V_28 )
return V_28 ;
V_27 = F_17 ( V_25 , V_30 , 0 ) ;
if ( ! V_27 ) {
F_18 ( & V_25 -> V_31 , L_2 ) ;
return - V_32 ;
}
if ( strcmp ( V_25 -> V_33 , L_3 ) == 0 )
V_16 = V_27 -> V_34 ;
else if ( strcmp ( V_25 -> V_33 , L_4 ) == 0 )
V_9 = V_27 -> V_34 ;
if ( V_16 && V_9 ) {
F_19 ( & V_35 ) ;
V_36 = F_11 ;
F_12 ( V_15 L_5 ) ;
}
return 0 ;
}
static int T_6 F_20 ( struct V_24 * V_25 )
{
F_21 ( V_25 ) ;
if ( strcmp ( V_25 -> V_33 , L_3 ) == 0 )
V_16 = 0 ;
else if ( strcmp ( V_25 -> V_33 , L_4 ) == 0 )
V_9 = 0 ;
V_36 = NULL ;
return 0 ;
}
static int T_7 F_22 ( void )
{
int V_5 ;
V_5 = F_23 ( & V_37 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_23 ( & V_38 ) ;
if ( V_5 )
F_24 ( & V_37 ) ;
return V_5 ;
}
