int F_1 ( bool V_1 )
{
static struct V_2 * V_3 = NULL ;
int V_4 = 0 ;
if ( ! V_3 )
V_3 = F_2 ( V_5 ) ;
if ( F_3 ( V_3 ) ) {
F_4 ( L_1 ) ;
return F_5 ( V_3 ) ;
}
if ( V_1 )
V_4 = F_6 ( V_3 ) ;
else
F_7 ( V_3 ) ;
return V_4 ;
}
static int F_8 ( struct V_6 * V_7 )
{
int V_4 = F_1 ( true ) ;
if ( V_4 )
return V_4 ;
F_9 ( & V_7 -> V_8 ) ;
F_10 ( & V_7 -> V_8 ) ;
return 0 ;
}
static void F_11 ( struct V_6 * V_7 )
{
if ( F_1 ( false ) )
return;
F_12 ( & V_7 -> V_8 ) ;
F_13 ( & V_7 -> V_8 ) ;
}
static int F_14 ( struct V_9 * V_10 )
{
F_15 ( 0x00ff0040 , V_10 -> V_11 + 0x0094 ) ;
F_15 ( 0x00000001 , V_10 -> V_11 + 0x009C ) ;
return 0 ;
}
void T_1 F_16 ( void )
{
F_17 (
L_2 , - 1 ,
V_12 ,
F_18 ( V_12 ) ) ;
F_19 ( 0 ) ;
F_19 ( 1 ) ;
F_19 ( 2 ) ;
F_19 ( 3 ) ;
F_19 ( 4 ) ;
}
static void T_1 F_20 ( int V_13 )
{
F_21 ( V_13 < 0 || V_13 > 3 ) ;
F_17 (
L_3 , V_13 ,
V_14 + ( 2 * V_13 ) , 2 ) ;
}
static void T_1 F_22 ( int V_13 )
{
F_21 ( V_13 < 0 || V_13 > 2 ) ;
F_17 (
L_4 , V_13 ,
V_15 + ( 2 * V_13 ) , 2 ) ;
}
void T_1 F_23 ( void )
{
#ifdef F_24
void T_2 * V_16 = F_25 ( 0xf0100000 , 0x1000 ) ;
if ( V_16 ) {
F_26 ( V_16 , 0x00400000 , 0xc20f0fff ) ;
}
#endif
F_27 ( 0 ) ;
F_27 ( 1 ) ;
F_27 ( 2 ) ;
F_27 ( 3 ) ;
F_27 ( 4 ) ;
F_27 ( 5 ) ;
F_28 ( 0 ) ;
}
static void T_1 F_29 ( void )
{
F_30 ( & V_17 , L_5 , - 1 ,
V_18 ,
F_18 ( V_18 ) ,
& V_19 ,
sizeof( V_19 ) ) ;
}
void T_1 F_31 ( void )
{
F_23 () ;
F_20 ( 0 ) ;
F_20 ( 1 ) ;
F_20 ( 2 ) ;
F_20 ( 3 ) ;
F_22 ( 0 ) ;
F_22 ( 1 ) ;
F_22 ( 2 ) ;
F_29 () ;
}
void T_1 F_32 ( void )
{
F_33 ( & V_20 ) ;
F_33 ( & V_21 ) ;
}
void T_1 F_34 ( int V_22 )
{
void T_2 * V_23 = F_25 ( 0xfe780000 , V_24 ) ;
unsigned long V_25 ;
if ( ! V_23 ) {
F_35 ( L_6 ) ;
return;
}
V_25 = F_36 ( V_23 ) ;
if ( V_22 )
V_25 |= 1 << 23 ;
else
V_25 &= ~ ( 1 << 23 ) ;
V_25 |= ( 1 << 21 ) ;
F_15 ( V_25 , V_23 ) ;
F_37 ( V_23 ) ;
}
void T_1 F_38 ( int V_22 )
{
F_34 ( V_22 ) ;
if ( V_22 )
F_30 (
& V_17 , L_7 , - 1 ,
V_26 , F_18 ( V_26 ) ,
& V_27 , sizeof( V_27 ) ) ;
}
void T_1 F_39 ( void )
{
F_40 ( 800 , 1 , 3 ) ;
}
void T_1 F_41 ( void )
{
void T_2 * V_16 = F_25 ( 0xfe700000 , 0x00100000 ) ;
F_21 ( ! V_16 ) ;
F_42 () ;
F_43 ( 0x73ffffff , V_16 + V_28 ) ;
F_43 ( 0xffffffff , V_16 + V_29 ) ;
F_43 ( 0x08330773 , V_16 + V_30 ) ;
F_43 ( 0x00311110 , V_16 + V_31 ) ;
F_37 ( V_16 ) ;
}
