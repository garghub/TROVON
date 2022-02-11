static inline unsigned int F_1 ( unsigned int V_1 )
{
unsigned long V_2 ;
__asm__ __volatile__("\n\tlda [%1] %2, %0\n\t" :
"=r" (data) :
"r" (addr), "i" (ASI_M_BYPASS));
return V_2 ;
}
static void F_2 ( void )
{
__asm__ __volatile__("mov 0x6c, %%g1\n\t"
"mov 0x4c, %%g2\n\t"
"mov 0xdf, %%g3\n\t"
"stb %%g1, [%0+3]\n\t"
"stb %%g2, [%0+3]\n\t"
"stb %%g3, [%0+3]\n\t" : :
"r" (clk_ctrl) :
"g1", "g2", "g3");
}
static void F_3 ( void )
{
__asm__ __volatile__("mov 0xcc, %%g2\n\t"
"mov 0x4c, %%g3\n\t"
"mov 0xcf, %%g4\n\t"
"mov 0xdf, %%g5\n\t"
"stb %%g2, [%0+3]\n\t"
"stb %%g3, [%0+3]\n\t"
"stb %%g4, [%0+3]\n\t"
"stb %%g5, [%0+3]\n\t" : :
"r" (clk_ctrl) :
"g2", "g3", "g4", "g5");
}
static void F_4 ( void )
{
unsigned int V_3 ;
unsigned long V_4 ;
if ( ! V_5 )
return;
if ( ! ( V_6 & V_7 ) ) {
F_5 ( V_4 ) ;
F_2 () ;
V_6 |= V_7 ;
F_6 ( V_4 ) ;
return;
}
if ( ! ( V_5 [ 2 ] & 1 ) )
return;
F_5 ( V_4 ) ;
V_3 = F_1 ( V_8 ) ;
if ( ( V_3 & V_9 ) != 0 ) {
F_6 ( V_4 ) ;
return;
}
F_3 () ;
F_6 ( V_4 ) ;
}
static void F_7 ( void )
{
if ( ! V_5 )
return;
V_5 [ 0 ] = 0 ;
}
void T_1 F_8 ( void )
{
T_2 V_10 , V_11 ;
char V_12 [ 20 ] ;
F_9 ( V_13 , L_1 , V_12 , sizeof( V_12 ) ) ;
if ( strncmp ( V_12 , L_2 , 7 ) )
return;
V_10 = F_10 ( V_13 ) ;
V_10 = F_11 ( V_10 , L_3 ) ;
V_10 = F_10 ( V_10 ) ;
V_11 = F_11 ( V_10 , L_4 ) ;
if ( ! V_11 )
return;
F_12 ( L_5 ) ;
V_5 = ( char * ) F_13 ( V_11 , L_6 ) ;
V_6 = 0 ;
if ( V_12 [ 10 ] == '\0' ) {
V_14 = F_4 ;
F_12 ( L_7 ) ;
} else if ( ( V_12 [ 10 ] == 'X' ) || ( V_12 [ 10 ] == 'G' ) ) {
V_14 = F_7 ;
F_12 ( L_8 , V_12 + 7 ) ;
} else
F_12 ( L_9 , V_12 + 7 ) ;
}
