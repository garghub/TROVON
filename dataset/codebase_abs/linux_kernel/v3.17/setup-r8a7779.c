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
NULL , L_2 , - 1 ,
V_6 , F_3 ( V_6 ) ,
& V_7 , sizeof( V_7 ) ) ;
}
void T_1 F_12 ( void )
{
F_13 ( V_8 ,
F_3 ( V_8 ) ) ;
}
static int F_14 ( struct V_9 * V_10 )
{
if ( F_15 ( V_11 ) )
return F_16 ( V_11 ) ;
F_17 ( & V_10 -> V_12 ) ;
F_18 ( & V_10 -> V_12 ) ;
F_19 ( V_11 ) ;
return 0 ;
}
static void F_20 ( struct V_9 * V_10 )
{
if ( F_15 ( V_11 ) )
return;
F_21 ( V_11 ) ;
F_22 ( & V_10 -> V_12 ) ;
F_23 ( & V_10 -> V_12 ) ;
}
static int F_24 ( struct V_13 * V_14 )
{
F_8 ( 0x00ff0040 , V_14 -> V_15 + 0x0094 ) ;
F_8 ( 0x00000001 , V_14 -> V_15 + 0x009C ) ;
return 0 ;
}
static void T_1 F_25 ( void )
{
F_11 ( NULL , L_3 ,
- 1 , V_16 ,
F_3 ( V_16 ) ,
& V_17 ,
sizeof( V_17 ) ) ;
}
void T_1 F_26 ( void )
{
#ifdef F_27
F_28 ( F_29 ( 0xf0100000 ) , 0x00400000 , 0xc20f0fff ) ;
#endif
F_30 () ;
F_31 () ;
F_13 ( V_18 ,
F_3 ( V_18 ) ) ;
F_13 ( V_19 ,
F_3 ( V_19 ) ) ;
F_25 () ;
}
void T_1 F_32 ( void )
{
F_33 ( V_18 ,
F_3 ( V_18 ) ) ;
}
void T_1 F_34 ( void )
{
V_11 = F_35 ( V_20 ) ;
F_36 () ;
F_13 ( V_21 ,
F_3 ( V_21 ) ) ;
}
static int F_37 ( struct V_22 * V_23 , unsigned int V_24 )
{
return 0 ;
}
void T_1 F_38 ( void )
{
V_25 . V_26 = F_37 ;
F_39 () ;
F_40 ( 0xffffffff , V_27 ) ;
F_40 ( 0x3fffffff , V_28 ) ;
F_40 ( 0xfffffff0 , V_29 ) ;
F_40 ( 0xfff7ffff , V_30 ) ;
F_40 ( 0xfffbffdf , V_31 ) ;
F_40 ( 0xbffffffc , V_32 ) ;
F_40 ( 0x003fee3f , V_33 ) ;
}
void T_1 F_41 ( void )
{
F_13 ( V_18 ,
F_3 ( V_18 ) ) ;
}
T_3 T_1 F_42 ( void )
{
static T_3 V_34 ;
static bool V_35 ;
if ( ! V_35 ) {
void T_2 * V_36 = F_5 ( V_37 , V_4 ) ;
F_43 ( ! V_36 ) ;
V_34 = F_7 ( V_36 ) ;
F_9 ( V_36 ) ;
V_35 = true ;
}
return V_34 ;
}
