static void T_1 F_1 ( void )
{
T_2 V_1 ;
void T_3 * V_2 = F_2 ( V_3 , 4 ) ;
F_3 ( ! V_2 ) ;
V_1 = F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
F_6 ( V_1 ) ;
}
int F_7 ( bool V_4 )
{
static struct V_5 * V_6 = NULL ;
int V_7 = 0 ;
if ( ! V_6 )
V_6 = F_8 ( V_8 ) ;
if ( F_9 ( V_6 ) ) {
F_10 ( L_1 ) ;
return F_11 ( V_6 ) ;
}
if ( V_4 )
V_7 = F_12 ( V_6 ) ;
else
F_13 ( V_6 ) ;
return V_7 ;
}
static int F_14 ( struct V_9 * V_10 )
{
int V_7 = F_7 ( true ) ;
if ( V_7 )
return V_7 ;
F_15 ( & V_10 -> V_11 ) ;
F_16 ( & V_10 -> V_11 ) ;
return 0 ;
}
static void F_17 ( struct V_9 * V_10 )
{
if ( F_7 ( false ) )
return;
F_18 ( & V_10 -> V_11 ) ;
F_19 ( & V_10 -> V_11 ) ;
}
static int F_20 ( struct V_12 * V_13 )
{
F_21 ( 0x00ff0040 , V_13 -> V_14 + 0x0094 ) ;
F_21 ( 0x00000001 , V_13 -> V_14 + 0x009C ) ;
return 0 ;
}
void T_1 F_22 ( void )
{
F_23 (
L_2 , - 1 ,
V_15 ,
F_24 ( V_15 ) ) ;
F_25 ( 0 ) ;
F_25 ( 1 ) ;
F_25 ( 2 ) ;
F_25 ( 3 ) ;
F_25 ( 4 ) ;
}
static void T_1 F_26 ( int V_16 )
{
F_3 ( V_16 < 0 || V_16 > 3 ) ;
F_23 (
L_3 , V_16 ,
V_17 + ( 2 * V_16 ) , 2 ) ;
}
static void T_1 F_27 ( int V_16 )
{
F_3 ( V_16 < 0 || V_16 > 2 ) ;
F_23 (
L_4 , V_16 ,
V_18 + ( 2 * V_16 ) , 2 ) ;
}
void T_1 F_28 ( void )
{
#ifdef F_29
void T_3 * V_19 = F_2 ( 0xf0100000 , 0x1000 ) ;
if ( V_19 ) {
F_30 ( V_19 , 0x00400000 , 0xc20f0fff ) ;
}
#endif
}
static void T_1 F_31 ( void )
{
F_32 ( NULL , L_5 ,
- 1 , V_20 ,
F_24 ( V_20 ) ,
& V_21 ,
sizeof( V_21 ) ) ;
}
void T_1 F_33 ( void )
{
F_28 () ;
F_34 ( 0 ) ;
F_35 ( 0 ) ;
F_35 ( 1 ) ;
F_35 ( 2 ) ;
F_35 ( 3 ) ;
F_35 ( 4 ) ;
F_35 ( 5 ) ;
F_26 ( 0 ) ;
F_26 ( 1 ) ;
F_26 ( 2 ) ;
F_26 ( 3 ) ;
F_27 ( 0 ) ;
F_27 ( 1 ) ;
F_27 ( 2 ) ;
F_31 () ;
}
void T_1 F_36 ( void )
{
F_37 () ;
F_38 ( & V_22 ) ;
F_38 ( & V_23 ) ;
}
void T_1 F_39 ( int V_24 )
{
void T_3 * V_25 = F_2 ( 0xfe780000 , V_26 ) ;
unsigned long V_27 ;
if ( ! V_25 ) {
F_40 ( L_6 ) ;
return;
}
V_27 = F_4 ( V_25 ) ;
if ( V_24 )
V_27 |= 1 << 23 ;
else
V_27 &= ~ ( 1 << 23 ) ;
V_27 |= ( 1 << 21 ) ;
F_21 ( V_27 , V_25 ) ;
F_5 ( V_25 ) ;
}
void T_1 F_41 ( int V_24 )
{
F_39 ( V_24 ) ;
if ( V_24 )
F_32 (
NULL , L_7 , - 1 ,
V_28 , F_24 ( V_28 ) ,
& V_29 , sizeof( V_29 ) ) ;
}
void T_1 F_42 ( void )
{
void T_3 * V_19 = F_2 ( 0xfe700000 , 0x00100000 ) ;
#ifdef F_43
void T_3 * V_30 = F_2 ( 0xfe438000 , 0x1000 ) ;
void T_3 * V_31 = F_2 ( 0xfe430000 , 0x1000 ) ;
#endif
F_3 ( ! V_19 ) ;
#ifdef F_43
F_44 ( 0 , 29 , V_30 , V_31 ) ;
#else
F_45 () ;
#endif
F_46 ( 0x73ffffff , V_19 + V_32 ) ;
F_46 ( 0xffffffff , V_19 + V_33 ) ;
F_46 ( 0x08330773 , V_19 + V_34 ) ;
F_46 ( 0x00311110 , V_19 + V_35 ) ;
F_5 ( V_19 ) ;
}
