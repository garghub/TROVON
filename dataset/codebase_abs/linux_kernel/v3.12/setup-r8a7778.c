static int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 ) )
return F_3 ( V_3 ) ;
F_4 ( & V_2 -> V_4 ) ;
F_5 ( & V_2 -> V_4 ) ;
F_6 ( V_3 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 ) )
return;
F_8 ( V_3 ) ;
F_9 ( & V_2 -> V_4 ) ;
F_10 ( & V_2 -> V_4 ) ;
}
static int F_11 ( struct V_5 * V_6 )
{
F_12 ( 0x00ff0040 , V_6 -> V_7 + 0x0094 ) ;
F_12 ( 0x00000001 , V_6 -> V_7 + 0x009C ) ;
return 0 ;
}
void T_1 F_13 ( struct V_8 * V_9 )
{
F_14 ( & V_10 , L_1 , - 1 ,
V_11 ,
F_15 ( V_11 ) ,
V_9 , sizeof( * V_9 ) ) ;
}
void T_1 F_16 ( void )
{
F_17 (
L_2 , - 1 ,
V_12 ,
F_15 ( V_12 ) ) ;
F_18 ( 0 ) ;
F_18 ( 1 ) ;
F_18 ( 2 ) ;
F_18 ( 3 ) ;
F_18 ( 4 ) ;
}
static void T_1 F_19 ( int V_13 )
{
F_20 ( V_13 < 0 || V_13 > 3 ) ;
F_17 (
L_3 , V_13 ,
V_14 + ( 2 * V_13 ) , 2 ) ;
}
void T_1 F_21 ( int V_13 )
{
F_20 ( V_13 < 0 || V_13 > 2 ) ;
F_17 (
L_4 , V_13 ,
V_15 + ( 2 * V_13 ) , 2 ) ;
}
void T_1 F_22 ( int V_13 , struct V_16 * V_9 )
{
F_20 ( V_13 < 0 || V_13 > 1 ) ;
V_17 [ V_13 ] -> V_18 = V_9 ;
V_17 [ V_13 ] -> V_19 = sizeof( * V_9 ) ;
F_23 ( V_17 [ V_13 ] ) ;
}
void T_1 F_24 ( void )
{
int V_20 ;
#ifdef F_25
void T_2 * V_21 = F_26 ( 0xf0100000 , 0x1000 ) ;
if ( V_21 ) {
F_27 ( V_21 , 0x40470000 , 0x82000fff ) ;
}
#endif
for ( V_20 = 0 ; V_20 < F_15 ( V_22 ) ; V_20 ++ )
F_28 ( & V_10 , L_5 , V_20 ,
& V_22 [ V_20 ] ,
sizeof( struct V_23 ) ) ;
F_29 ( 0 ) ;
F_29 ( 1 ) ;
}
void T_1 F_30 ( void )
{
F_24 () ;
F_19 ( 0 ) ;
F_19 ( 1 ) ;
F_19 ( 2 ) ;
F_19 ( 3 ) ;
F_21 ( 0 ) ;
F_21 ( 1 ) ;
F_21 ( 2 ) ;
}
void T_1 F_31 ( void )
{
V_3 = F_32 ( V_24 ) ;
F_23 ( & V_25 ) ;
F_23 ( & V_26 ) ;
}
void T_1 F_33 ( int V_27 )
{
void T_2 * V_28 = F_26 ( 0xfe780000 , V_29 ) ;
unsigned long V_30 ;
if ( ! V_28 ) {
F_34 ( L_6 ) ;
return;
}
V_30 = F_35 ( V_28 ) ;
if ( V_27 )
V_30 |= 1 << 23 ;
else
V_30 &= ~ ( 1 << 23 ) ;
V_30 |= ( 1 << 21 ) ;
F_12 ( V_30 , V_28 ) ;
F_36 ( V_28 ) ;
if ( V_27 )
F_14 (
& V_10 , L_7 , - 1 ,
V_31 , F_15 ( V_31 ) ,
& V_32 , sizeof( V_32 ) ) ;
}
void T_1 F_37 ( void )
{
F_38 ( 800 , 1 , 3 ) ;
}
void T_1 F_39 ( void )
{
void T_2 * V_21 = F_26 ( 0xfe700000 , 0x00100000 ) ;
F_20 ( ! V_21 ) ;
F_40 () ;
F_41 ( 0x73ffffff , V_21 + V_33 ) ;
F_41 ( 0xffffffff , V_21 + V_34 ) ;
F_41 ( 0x08330773 , V_21 + V_35 ) ;
F_41 ( 0x00311110 , V_21 + V_36 ) ;
F_36 ( V_21 ) ;
}
