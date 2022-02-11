static T_1 F_1 ( void )
{
T_1 V_1 = F_2 () ;
F_3 ( V_1 | 0x00010000 ) ;
asm volatile(
" .set push \n"
" .set noat \n"
" .set noreorder \n"
" lw $1, 0(%0) \n"
" sb $0, 0(%1) \n"
" sync \n"
" lb %1, 0(%1) \n"
" b 1f \n"
" ori %1, $1, 2 \n"
" .align 8 \n"
"1: \n"
" nop \n"
" sw %1, 0(%0) \n"
" sync \n"
" li %1, 0x20 \n"
"2: \n"
" nop \n"
" bnez %1,2b \n"
" addiu %1, -1 \n"
" sw $1, 0(%0) \n"
" sync \n"
".set pop \n"
:
: "Jr" (PCIMT_UCONF), "Jr" (0xbc000000));
F_3 ( V_1 ) ;
return V_1 ;
}
static inline void F_4 ( struct V_2 * V_3 )
{
F_5 ( 0x100 << ( V_3 -> V_4 - V_5 ) ) ;
F_6 () ;
}
static inline void F_7 ( struct V_2 * V_3 )
{
F_8 ( 0x100 << ( V_3 -> V_4 - V_5 ) ) ;
F_9 () ;
}
static void F_10 ( void )
{
T_1 V_6 , V_1 ;
int V_4 ;
F_8 ( V_7 ) ;
V_1 = F_1 () ;
V_6 = F_11 () ;
V_4 = F_12 ( ( ( V_6 & V_1 ) >> 8 ) & 0xf8 ) ;
if ( F_13 ( V_4 > 0 ) )
F_14 ( V_5 + V_4 - 1 ) ;
F_5 ( V_7 ) ;
}
void T_2 F_15 ( void )
{
int V_8 ;
for ( V_8 = V_5 + 2 ; V_8 < V_5 + 8 ; V_8 ++ )
F_16 ( V_8 , & V_9 , V_10 ) ;
V_11 = F_10 ;
F_17 ( V_12 , V_7 ) ;
F_18 ( V_5 + 3 , & V_13 ) ;
}
void F_19 ( void )
{
}
static int T_2 F_20 ( void )
{
switch ( V_14 ) {
case V_15 :
case V_16 :
F_21 ( & V_17 ) ;
F_21 ( & V_18 ) ;
F_21 ( & V_19 ) ;
F_21 ( & V_20 ) ;
F_21 ( & V_21 ) ;
F_22 () ;
break;
}
return 0 ;
}
