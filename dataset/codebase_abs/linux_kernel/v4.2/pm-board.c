static void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
T_2 V_3 , V_4 ;
int V_5 ;
V_3 = F_2 ( V_6 ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ )
V_3 &= ~ F_3 ( V_8 [ V_5 ] ) ;
V_3 |= F_3 ( V_8 [ 0 ] ) ;
F_4 ( V_3 , V_6 ) ;
V_4 = F_2 ( V_6 ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ )
V_4 |= F_3 ( V_8 [ V_5 ] ) ;
V_2 = F_5 ( V_2 ) ;
V_4 = F_5 ( V_4 ) ;
F_6 ( 3000 ) ;
asm volatile (
".balign 32\n\t"
"str %[srcmd], [%[sdram_reg]]\n\t"
"mov r1, #50\n\t"
"1: subs r1, r1, #1\n\t"
"bne 1b\n\t"
"str %[ackcmd], [%[gpio_ctrl]]\n\t"
"b .\n\t"
: : [srcmd] "r" (srcmd), [sdram_reg] "r" (sdram_reg),
[ackcmd] "r" (ackcmd), [gpio_ctrl] "r" (gpio_ctrl) : "r1");
}
static int F_7 ( void )
{
struct V_9 * V_10 ;
struct V_9 * V_11 ;
int V_12 = 0 , V_5 ;
if ( ! F_8 ( L_1 ) )
return - V_13 ;
V_10 = F_9 ( NULL , L_2 ) ;
if ( ! V_10 )
return - V_13 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
char * V_14 ;
struct V_15 args ;
V_16 [ V_5 ] = F_10 ( V_10 , L_3 , V_5 ) ;
if ( V_16 [ V_5 ] < 0 ) {
V_12 = - V_13 ;
goto V_17;
}
V_14 = F_11 ( V_18 , L_4 , V_5 ) ;
if ( ! V_14 ) {
V_12 = - V_19 ;
goto V_17;
}
V_12 = F_12 ( V_16 [ V_5 ] , V_14 ) ;
if ( V_12 < 0 ) {
F_13 ( V_14 ) ;
goto V_17;
}
V_12 = F_14 ( V_16 [ V_5 ] , 0 ) ;
if ( V_12 < 0 ) {
F_15 ( V_16 [ V_5 ] ) ;
F_13 ( V_14 ) ;
goto V_17;
}
V_12 = F_16 ( V_10 , L_3 , 2 ,
V_5 , & args ) ;
if ( V_12 < 0 ) {
F_15 ( V_16 [ V_5 ] ) ;
F_13 ( V_14 ) ;
goto V_17;
}
V_11 = args . V_10 ;
V_8 [ V_5 ] = args . args [ 0 ] ;
}
V_6 = F_17 ( V_11 , 0 ) ;
if ( ! V_6 )
return - V_19 ;
F_18 ( F_1 ) ;
V_17:
F_19 ( V_10 ) ;
return V_12 ;
}
