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
F_28 ( F_29 ( 0xf0100000 ) , 0x40470000 , 0x82000fff ) ;
#endif
F_30 () ;
F_31 () ;
F_13 ( V_19 ,
F_3 ( V_19 ) ) ;
F_13 ( V_20 ,
F_3 ( V_20 ) ) ;
F_25 () ;
}
void T_1 F_32 ( struct V_21 * V_22 )
{
F_11 ( & V_6 , L_4 , - 1 ,
V_23 ,
F_3 ( V_23 ) ,
V_22 , sizeof( * V_22 ) ) ;
}
void T_1 F_33 ( int V_24 , struct V_25 * V_22 )
{
F_34 ( V_24 < 0 || V_24 > 3 ) ;
V_26 [ V_24 ] -> V_27 = V_22 ;
V_26 [ V_24 ] -> V_28 = sizeof( * V_22 ) ;
F_35 ( V_26 [ V_24 ] ) ;
}
void T_1 __weak F_36 ( void ) { }
void T_1 F_37 ( void )
{
F_38 () ;
F_36 () ;
F_39 () ;
}
void T_1 F_40 ( void )
{
F_41 ( V_19 ,
F_3 ( V_19 ) ) ;
}
void T_1 F_42 ( void )
{
V_12 = F_43 ( V_29 ) ;
F_44 () ;
F_13 ( V_30 ,
F_3 ( V_30 ) ) ;
}
static int F_45 ( struct V_31 * V_27 , unsigned int V_32 )
{
return 0 ;
}
void T_1 F_46 ( void )
{
V_33 . V_34 = F_45 ;
F_47 () ;
F_48 ( 0xffffffff , V_35 ) ;
F_48 ( 0x3fffffff , V_36 ) ;
F_48 ( 0xfffffff0 , V_37 ) ;
F_48 ( 0xfff7ffff , V_38 ) ;
F_48 ( 0xfffbffdf , V_39 ) ;
F_48 ( 0xbffffffc , V_40 ) ;
F_48 ( 0x003fee3f , V_41 ) ;
}
void T_1 F_49 ( void )
{
F_50 ( 1000 , 2 , 4 ) ;
}
void T_1 F_51 ( void )
{
F_38 () ;
F_13 ( V_19 ,
F_3 ( V_19 ) ) ;
F_52 ( NULL , V_42 , NULL , NULL ) ;
}
