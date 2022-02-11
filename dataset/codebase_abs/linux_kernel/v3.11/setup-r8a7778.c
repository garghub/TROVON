void T_1 F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 , L_1 , - 1 ,
V_4 ,
F_3 ( V_4 ) ,
V_2 , sizeof( * V_2 ) ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
if ( F_5 ( V_7 ) )
return F_6 ( V_7 ) ;
F_7 ( & V_6 -> V_8 ) ;
F_8 ( & V_6 -> V_8 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static void F_10 ( struct V_5 * V_6 )
{
if ( F_5 ( V_7 ) )
return;
F_11 ( V_7 ) ;
F_12 ( & V_6 -> V_8 ) ;
F_13 ( & V_6 -> V_8 ) ;
}
static int F_14 ( struct V_9 * V_10 )
{
F_15 ( 0x00ff0040 , V_10 -> V_11 + 0x0094 ) ;
F_15 ( 0x00000001 , V_10 -> V_11 + 0x009C ) ;
return 0 ;
}
void T_1 F_16 ( struct V_12 * V_2 )
{
F_2 ( & V_3 , L_2 , - 1 ,
V_13 ,
F_3 ( V_13 ) ,
V_2 , sizeof( * V_2 ) ) ;
}
void T_1 F_17 ( void )
{
F_18 (
L_3 , - 1 ,
V_14 ,
F_3 ( V_14 ) ) ;
F_19 ( 0 ) ;
F_19 ( 1 ) ;
F_19 ( 2 ) ;
F_19 ( 3 ) ;
F_19 ( 4 ) ;
}
void T_1 F_20 ( int V_15 ,
struct V_16 * V_17 )
{
F_21 ( V_15 < 0 || V_15 > 2 ) ;
F_2 (
& V_3 , L_4 , V_15 ,
V_18 + ( 2 * V_15 ) , 2 ,
V_17 , sizeof( * V_17 ) ) ;
}
void T_1 F_22 ( int V_15 )
{
F_21 ( V_15 < 0 || V_15 > 3 ) ;
F_18 (
L_5 , V_15 ,
V_19 + ( 2 * V_15 ) , 2 ) ;
}
void T_1 F_23 ( int V_15 )
{
F_21 ( V_15 < 0 || V_15 > 2 ) ;
F_18 (
L_6 , V_15 ,
V_20 + ( 2 * V_15 ) , 2 ) ;
}
void T_1 F_24 ( struct V_21 * V_17 )
{
F_2 (
& V_3 , L_7 , - 1 ,
V_22 , F_3 ( V_22 ) ,
V_17 , sizeof( * V_17 ) ) ;
}
void T_1 F_25 ( void )
{
int V_23 ;
#ifdef F_26
void T_2 * V_24 = F_27 ( 0xf0100000 , 0x1000 ) ;
if ( V_24 ) {
F_28 ( V_24 , 0x40470000 , 0x82000fff ) ;
}
#endif
for ( V_23 = 0 ; V_23 < F_3 ( V_25 ) ; V_23 ++ )
F_29 ( & V_3 , L_8 , V_23 ,
& V_25 [ V_23 ] ,
sizeof( struct V_26 ) ) ;
F_30 ( 0 ) ;
F_30 ( 1 ) ;
}
void T_1 F_31 ( void )
{
V_7 = F_32 ( V_27 ) ;
F_33 ( & V_28 ) ;
F_33 ( & V_29 ) ;
}
void T_1 F_34 ( int V_30 )
{
void T_2 * V_31 = F_27 ( 0xfe780000 , V_32 ) ;
unsigned long V_33 ;
if ( ! V_31 ) {
F_35 ( L_9 ) ;
return;
}
V_33 = F_36 ( V_31 ) ;
if ( V_30 )
V_33 |= 1 << 23 ;
else
V_33 &= ~ ( 1 << 23 ) ;
V_33 |= ( 1 << 21 ) ;
F_15 ( V_33 , V_31 ) ;
F_37 ( V_31 ) ;
if ( V_30 )
F_2 (
& V_3 , L_10 , - 1 ,
V_34 , F_3 ( V_34 ) ,
& V_35 , sizeof( V_35 ) ) ;
}
static void T_1 F_38 ( void )
{
void T_2 * V_24 = F_27 ( 0xfe700000 , 0x00100000 ) ;
F_21 ( ! V_24 ) ;
F_39 ( 0x73ffffff , V_24 + V_36 ) ;
F_39 ( 0xffffffff , V_24 + V_37 ) ;
F_39 ( 0x08330773 , V_24 + V_38 ) ;
F_39 ( 0x00311110 , V_24 + V_39 ) ;
F_37 ( V_24 ) ;
}
void T_1 F_40 ( void )
{
void T_2 * V_40 ;
void T_2 * V_41 ;
V_40 = F_27 ( 0xfe438000 , V_32 ) ;
V_41 = F_27 ( 0xfe430000 , V_32 ) ;
F_21 ( ! V_40 || ! V_41 ) ;
F_41 ( 0 , 29 , V_40 , V_41 ) ;
F_38 () ;
}
void T_1 F_42 ( void )
{
F_43 ( 800 , 1 , 3 ) ;
}
void T_1 F_44 ( void )
{
F_45 () ;
F_38 () ;
}
void T_1 F_46 ( void )
{
F_47 ( NULL , V_42 ,
V_43 , NULL ) ;
}
