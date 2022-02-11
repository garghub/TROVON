void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 , F_4 ( V_1 ) ) ;
}
void T_1 F_5 ( int V_2 )
{
void T_2 * V_3 = F_6 ( 0xfe780000 , V_4 ) ;
T_3 V_5 ;
if ( ! V_3 ) {
F_7 ( L_1 ) ;
return;
}
V_5 = F_8 ( V_3 ) ;
if ( V_2 )
V_5 |= 1 << 23 ;
else
V_5 &= ~ ( 1 << 23 ) ;
V_5 |= ( 1 << 21 ) ;
F_9 ( V_5 , V_3 ) ;
F_10 ( V_3 ) ;
}
void T_1 F_11 ( int V_2 )
{
F_5 ( V_2 ) ;
if ( V_2 )
F_12 (
NULL , L_2 , - 1 ,
V_6 , F_4 ( V_6 ) ,
& V_7 , sizeof( V_7 ) ) ;
}
void T_1 F_13 ( void )
{
F_14 ( V_8 ,
F_4 ( V_8 ) ) ;
}
static int F_15 ( struct V_9 * V_10 )
{
if ( F_16 ( V_11 ) )
return F_17 ( V_11 ) ;
F_18 ( & V_10 -> V_12 ) ;
F_19 ( & V_10 -> V_12 ) ;
F_20 ( V_11 ) ;
return 0 ;
}
static void F_21 ( struct V_9 * V_10 )
{
if ( F_16 ( V_11 ) )
return;
F_22 ( V_11 ) ;
F_23 ( & V_10 -> V_12 ) ;
F_24 ( & V_10 -> V_12 ) ;
}
static int F_25 ( struct V_13 * V_14 )
{
F_9 ( 0x00ff0040 , V_14 -> V_15 + 0x0094 ) ;
F_9 ( 0x00000001 , V_14 -> V_15 + 0x009C ) ;
return 0 ;
}
static void T_1 F_26 ( void )
{
F_12 ( NULL , L_3 ,
- 1 , V_16 ,
F_4 ( V_16 ) ,
& V_17 ,
sizeof( V_17 ) ) ;
}
void T_1 F_27 ( void )
{
#ifdef F_28
F_29 ( F_30 ( 0xf0100000 ) , 0x00400000 , 0xc20f0fff ) ;
#endif
F_31 () ;
F_32 () ;
F_14 ( V_18 ,
F_4 ( V_18 ) ) ;
F_14 ( V_19 ,
F_4 ( V_19 ) ) ;
F_26 () ;
}
void T_1 F_33 ( void )
{
F_34 ( V_18 ,
F_4 ( V_18 ) ) ;
}
void T_1 F_35 ( void )
{
V_11 = F_36 ( V_20 ) ;
F_37 () ;
F_14 ( V_21 ,
F_4 ( V_21 ) ) ;
}
static int F_38 ( struct V_22 * V_23 , unsigned int V_24 )
{
return 0 ;
}
void T_1 F_39 ( void )
{
#ifdef F_40
void T_2 * V_25 = F_6 ( 0xf0001000 , 0x1000 ) ;
void T_2 * V_26 = F_6 ( 0xf0000100 , 0x1000 ) ;
#endif
V_27 . V_28 = F_38 ;
#ifdef F_40
F_41 ( 0 , 29 , V_25 , V_26 ) ;
#else
F_42 () ;
#endif
F_43 ( 0xffffffff , V_29 ) ;
F_43 ( 0x3fffffff , V_30 ) ;
F_43 ( 0xfffffff0 , V_31 ) ;
F_43 ( 0xfff7ffff , V_32 ) ;
F_43 ( 0xfffbffdf , V_33 ) ;
F_43 ( 0xbffffffc , V_34 ) ;
F_43 ( 0x003fee3f , V_35 ) ;
}
T_3 T_1 F_44 ( void )
{
static T_3 V_36 ;
static bool V_37 ;
if ( ! V_37 ) {
void T_2 * V_38 = F_6 ( V_39 , V_4 ) ;
F_45 ( ! V_38 ) ;
V_36 = F_8 ( V_38 ) ;
F_10 ( V_38 ) ;
V_37 = true ;
}
return V_36 ;
}
