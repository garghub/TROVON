void T_1 F_1 ( int V_1 )
{
void T_2 * V_2 = F_2 ( 0xfe780000 , V_3 ) ;
unsigned long V_4 ;
if ( V_2 ) {
V_4 = F_3 ( V_2 ) ;
if ( V_1 )
V_4 |= 1 << 23 ;
else
V_4 &= ~ ( 1 << 23 ) ;
V_4 |= ( 1 << 21 ) ;
F_4 ( V_4 , V_2 ) ;
F_5 ( V_2 ) ;
if ( V_1 )
F_6 ( & V_5 ) ;
} else
F_7 ( L_1 ) ;
}
static int F_8 ( struct V_6 * V_7 , unsigned int V_8 )
{
return 0 ;
}
static void T_1 F_9 ( void )
{
V_9 . V_10 = F_8 ;
F_10 ( 0xffffffff , V_11 ) ;
F_10 ( 0x3fffffff , V_12 ) ;
F_10 ( 0xfffffff0 , V_13 ) ;
F_10 ( 0xfff7ffff , V_14 ) ;
F_10 ( 0xfffbffdf , V_15 ) ;
F_10 ( 0xbffffffc , V_16 ) ;
F_10 ( 0x003fee3f , V_17 ) ;
}
void T_1 F_11 ( void )
{
void T_2 * V_18 = F_12 ( 0xf0001000 ) ;
void T_2 * V_19 = F_12 ( 0xf0000100 ) ;
F_13 ( 0 , 29 , V_18 , V_19 ) ;
F_9 () ;
}
void T_1 F_14 ( void )
{
F_15 () ;
F_9 () ;
}
