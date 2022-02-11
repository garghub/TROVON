const char * F_1 ( void )
{
return L_1 ;
}
void T_1 F_2 ( void )
{
unsigned char * V_1 ;
unsigned long V_2 ;
V_3 = V_4 ;
V_5 = ( char * * ) V_6 ;
V_7 = ( char * * ) V_8 ;
F_3 () ;
V_1 = F_4 ( L_2 ) ;
if ( ! V_1 || F_5 ( V_1 , 0 , & V_2 ) )
V_2 = 0x04000000 ;
F_6 ( 0 , V_2 , V_9 ) ;
}
void F_7 ( unsigned char V_10 )
{
F_8 ( V_11 , V_10 ) ;
}
static void F_9 ( char * V_10 )
{
__asm__ __volatile__("jr\t%0" : : "r"(0xbfc00000));
}
static void F_10 ( void )
{
while ( 1 )
asm volatile (
" .set mips32 \n"
" wait \n"
" .set mips0 \n");
}
void T_1 F_11 ( void )
{
T_2 V_12 ;
V_13 = F_10 ;
V_14 = F_10 ;
V_15 = F_9 ;
F_12 () ;
F_13 () ;
V_12 = F_14 ( V_16 ) & ~ V_17 ;
V_12 |= V_17 ;
F_15 ( V_12 , V_16 ) ;
F_16 ( V_18 ) ;
F_17 ( 1 , ( void V_19 * ) F_18 ( V_18 + 0x18 ) ) ;
F_19 () ;
}
static int T_1 F_20 ( void )
{
F_21 ( V_20 , V_21 ) ;
F_21 ( V_22 , V_23 ) ;
F_21 ( V_24 , V_23 ) ;
F_21 ( V_25 , V_23 ) ;
F_21 ( V_26 , V_23 ) ;
F_21 ( V_27 , V_23 ) ;
F_21 ( V_28 , V_23 ) ;
F_21 ( V_29 , V_23 ) ;
F_21 ( V_30 , V_23 ) ;
F_21 ( V_31 , V_23 ) ;
F_21 ( V_32 , V_23 ) ;
F_21 ( V_33 , V_23 ) ;
return F_22 ( V_34 ,
F_23 ( V_34 ) ) ;
}
