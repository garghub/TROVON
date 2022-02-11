void T_1 F_1 ( void )
{
int V_1 ;
#ifdef F_2
void T_2 * V_2 = F_3 ( 0xf0100000 , 0x1000 ) ;
if ( V_2 ) {
F_4 ( V_2 , 0x40470000 , 0x82000fff ) ;
}
#endif
for ( V_1 = 0 ; V_1 < F_5 ( V_3 ) ; V_1 ++ )
F_6 ( & V_4 , L_1 , V_1 ,
& V_3 [ V_1 ] ,
sizeof( struct V_5 ) ) ;
F_7 ( 0 ) ;
F_7 ( 1 ) ;
}
void T_1 F_8 ( struct V_6 * V_7 )
{
F_9 ( & V_4 , L_2 , - 1 ,
V_8 ,
F_5 ( V_8 ) ,
V_7 , sizeof( * V_7 ) ) ;
}
void T_1 F_10 ( int V_9 )
{
void T_2 * V_10 = F_3 ( 0xfe780000 , V_11 ) ;
unsigned long V_12 ;
if ( ! V_10 ) {
F_11 ( L_3 ) ;
return;
}
V_12 = F_12 ( V_10 ) ;
if ( V_9 )
V_12 |= 1 << 23 ;
else
V_12 &= ~ ( 1 << 23 ) ;
V_12 |= ( 1 << 21 ) ;
F_13 ( V_12 , V_10 ) ;
F_14 ( V_10 ) ;
if ( V_9 )
F_9 (
& V_4 , L_4 , - 1 ,
V_13 , F_5 ( V_13 ) ,
& V_14 , sizeof( V_14 ) ) ;
}
static void T_1 F_15 ( void )
{
void T_2 * V_2 = F_3 ( 0xfe700000 , 0x00100000 ) ;
F_16 ( ! V_2 ) ;
F_17 ( 0x73ffffff , V_2 + V_15 ) ;
F_17 ( 0xffffffff , V_2 + V_16 ) ;
F_17 ( 0x08330773 , V_2 + V_17 ) ;
F_17 ( 0x00311110 , V_2 + V_18 ) ;
F_14 ( V_2 ) ;
}
void T_1 F_18 ( void )
{
void T_2 * V_19 ;
void T_2 * V_20 ;
V_19 = F_3 ( 0xfe438000 , V_11 ) ;
V_20 = F_3 ( 0xfe430000 , V_11 ) ;
F_16 ( ! V_19 || ! V_20 ) ;
F_19 ( 0 , 29 , V_19 , V_20 ) ;
F_15 () ;
}
void T_1 F_20 ( void )
{
F_21 ( 800 , 1 , 3 ) ;
}
void T_1 F_22 ( void )
{
F_23 () ;
F_15 () ;
}
void T_1 F_24 ( void )
{
F_25 ( NULL , V_21 ,
V_22 , NULL ) ;
}
