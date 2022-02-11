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
if ( V_2 )
F_10 (
& V_6 , L_2 , - 1 ,
V_7 , F_3 ( V_7 ) ,
& V_8 , sizeof( V_8 ) ) ;
}
void T_1 F_11 ( void )
{
F_12 ( V_9 ,
F_3 ( V_9 ) ) ;
}
static int F_13 ( struct V_10 * V_11 )
{
if ( F_14 ( V_12 ) )
return F_15 ( V_12 ) ;
F_16 ( & V_11 -> V_13 ) ;
F_17 ( & V_11 -> V_13 ) ;
F_18 ( V_12 ) ;
return 0 ;
}
static void F_19 ( struct V_10 * V_11 )
{
if ( F_14 ( V_12 ) )
return;
F_20 ( V_12 ) ;
F_21 ( & V_11 -> V_13 ) ;
F_22 ( & V_11 -> V_13 ) ;
}
static int F_23 ( struct V_14 * V_15 )
{
F_8 ( 0x00ff0040 , V_15 -> V_16 + 0x0094 ) ;
F_8 ( 0x00000001 , V_15 -> V_16 + 0x009C ) ;
return 0 ;
}
void T_1 F_24 ( void )
{
#ifdef F_25
F_26 ( F_27 ( 0xf0100000 ) , 0x40470000 , 0x82000fff ) ;
#endif
F_28 () ;
F_29 () ;
F_12 ( V_17 ,
F_3 ( V_17 ) ) ;
F_12 ( V_18 ,
F_3 ( V_18 ) ) ;
}
void T_1 F_30 ( struct V_19 * V_20 )
{
F_10 ( & V_6 , L_3 , - 1 ,
V_21 ,
F_3 ( V_21 ) ,
V_20 , sizeof( * V_20 ) ) ;
}
void T_1 F_31 ( int V_22 , struct V_23 * V_20 )
{
F_32 ( V_22 < 0 || V_22 > 3 ) ;
V_24 [ V_22 ] -> V_25 = V_20 ;
V_24 [ V_22 ] -> V_26 = sizeof( * V_20 ) ;
F_33 ( V_24 [ V_22 ] ) ;
}
void T_1 __weak F_34 ( void ) { }
void T_1 F_35 ( void )
{
F_36 () ;
F_34 () ;
F_37 () ;
}
void T_1 F_38 ( void )
{
F_39 ( V_17 ,
F_3 ( V_17 ) ) ;
}
void T_1 F_40 ( void )
{
V_12 = F_41 ( V_27 ) ;
F_42 () ;
F_12 ( V_28 ,
F_3 ( V_28 ) ) ;
}
static int F_43 ( struct V_29 * V_25 , unsigned int V_30 )
{
return 0 ;
}
void T_1 F_44 ( void )
{
V_31 . V_32 = F_43 ;
F_45 () ;
F_46 ( 0xffffffff , V_33 ) ;
F_46 ( 0x3fffffff , V_34 ) ;
F_46 ( 0xfffffff0 , V_35 ) ;
F_46 ( 0xfff7ffff , V_36 ) ;
F_46 ( 0xfffbffdf , V_37 ) ;
F_46 ( 0xbffffffc , V_38 ) ;
F_46 ( 0x003fee3f , V_39 ) ;
}
void T_1 F_47 ( void )
{
F_48 ( 1000 , 2 , 4 ) ;
}
void T_1 F_49 ( void )
{
F_36 () ;
F_12 ( V_17 ,
F_3 ( V_17 ) ) ;
F_50 ( NULL , V_40 , NULL , NULL ) ;
}
