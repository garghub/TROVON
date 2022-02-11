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
}
static void T_1 F_28 ( void )
{
F_29 ( NULL , L_5 ,
- 1 , V_17 ,
F_18 ( V_17 ) ,
& V_18 ,
sizeof( V_18 ) ) ;
}
void T_1 F_30 ( void )
{
F_23 () ;
F_31 ( 0 ) ;
F_31 ( 1 ) ;
F_31 ( 2 ) ;
F_31 ( 3 ) ;
F_31 ( 4 ) ;
F_31 ( 5 ) ;
F_20 ( 0 ) ;
F_20 ( 1 ) ;
F_20 ( 2 ) ;
F_20 ( 3 ) ;
F_22 ( 0 ) ;
F_22 ( 1 ) ;
F_22 ( 2 ) ;
F_28 () ;
}
void T_1 F_32 ( void )
{
F_33 ( & V_19 ) ;
F_33 ( & V_20 ) ;
}
void T_1 F_34 ( int V_21 )
{
void T_2 * V_22 = F_25 ( 0xfe780000 , V_23 ) ;
unsigned long V_24 ;
if ( ! V_22 ) {
F_35 ( L_6 ) ;
return;
}
V_24 = F_36 ( V_22 ) ;
if ( V_21 )
V_24 |= 1 << 23 ;
else
V_24 &= ~ ( 1 << 23 ) ;
V_24 |= ( 1 << 21 ) ;
F_15 ( V_24 , V_22 ) ;
F_37 ( V_22 ) ;
}
void T_1 F_38 ( int V_21 )
{
F_34 ( V_21 ) ;
if ( V_21 )
F_29 (
NULL , L_7 , - 1 ,
V_25 , F_18 ( V_25 ) ,
& V_26 , sizeof( V_26 ) ) ;
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
F_43 ( 0x73ffffff , V_16 + V_27 ) ;
F_43 ( 0xffffffff , V_16 + V_28 ) ;
F_43 ( 0x08330773 , V_16 + V_29 ) ;
F_43 ( 0x00311110 , V_16 + V_30 ) ;
F_37 ( V_16 ) ;
}
