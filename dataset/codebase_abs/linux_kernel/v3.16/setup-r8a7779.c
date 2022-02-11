void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
void T_1 F_4 ( int V_2 )
{
void T_2 * V_3 = F_5 ( 0xfe780000 , V_4 ) ;
T_3 V_5 ;
if ( ! V_3 ) {
F_6 ( L_1 ) ;
return;
}
V_5 = F_7 ( V_3 ) ;
if ( V_2 )
V_5 |= 1 << 23 ;
else
V_5 &= ~ ( 1 << 23 ) ;
V_5 |= ( 1 << 21 ) ;
F_8 ( V_5 , V_3 ) ;
F_9 ( V_3 ) ;
}
void T_1 F_10 ( int V_2 )
{
F_4 ( V_2 ) ;
if ( V_2 )
F_11 (
& V_6 , L_2 , - 1 ,
V_7 , F_3 ( V_7 ) ,
& V_8 , sizeof( V_8 ) ) ;
}
void T_1 F_12 ( void )
{
F_13 ( V_9 ,
F_3 ( V_9 ) ) ;
}
static int F_14 ( struct V_10 * V_11 )
{
if ( F_15 ( V_12 ) )
return F_16 ( V_12 ) ;
F_17 ( & V_11 -> V_13 ) ;
F_18 ( & V_11 -> V_13 ) ;
F_19 ( V_12 ) ;
return 0 ;
}
static void F_20 ( struct V_10 * V_11 )
{
if ( F_15 ( V_12 ) )
return;
F_21 ( V_12 ) ;
F_22 ( & V_11 -> V_13 ) ;
F_23 ( & V_11 -> V_13 ) ;
}
static int F_24 ( struct V_14 * V_15 )
{
F_8 ( 0x00ff0040 , V_15 -> V_16 + 0x0094 ) ;
F_8 ( 0x00000001 , V_15 -> V_16 + 0x009C ) ;
return 0 ;
}
static void T_1 F_25 ( void )
{
F_11 ( & V_6 , L_3 , - 1 ,
V_17 ,
F_3 ( V_17 ) ,
& V_18 ,
sizeof( V_18 ) ) ;
}
void T_1 F_26 ( void )
{
#ifdef F_27
F_28 ( F_29 ( 0xf0100000 ) , 0x00400000 , 0xc20f0fff ) ;
#endif
F_30 () ;
F_31 () ;
F_13 ( V_19 ,
F_3 ( V_19 ) ) ;
F_13 ( V_20 ,
F_3 ( V_20 ) ) ;
F_25 () ;
}
void T_1 __weak F_32 ( void ) { }
void T_1 F_33 ( void )
{
F_34 () ;
F_32 () ;
F_35 () ;
}
void T_1 F_36 ( void )
{
F_37 ( V_19 ,
F_3 ( V_19 ) ) ;
}
void T_1 F_38 ( void )
{
V_12 = F_39 ( V_21 ) ;
F_40 () ;
F_13 ( V_22 ,
F_3 ( V_22 ) ) ;
}
static int F_41 ( struct V_23 * V_24 , unsigned int V_25 )
{
return 0 ;
}
void T_1 F_42 ( void )
{
V_26 . V_27 = F_41 ;
F_43 () ;
F_44 ( 0xffffffff , V_28 ) ;
F_44 ( 0x3fffffff , V_29 ) ;
F_44 ( 0xfffffff0 , V_30 ) ;
F_44 ( 0xfff7ffff , V_31 ) ;
F_44 ( 0xfffbffdf , V_32 ) ;
F_44 ( 0xbffffffc , V_33 ) ;
F_44 ( 0x003fee3f , V_34 ) ;
}
void T_1 F_45 ( void )
{
F_46 ( 1000 , 2 , 4 ) ;
}
void T_1 F_47 ( void )
{
F_34 () ;
F_13 ( V_19 ,
F_3 ( V_19 ) ) ;
F_48 ( NULL , V_35 , NULL , NULL ) ;
}
