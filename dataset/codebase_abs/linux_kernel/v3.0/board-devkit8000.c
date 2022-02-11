static int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ) )
F_3 ( V_2 -> V_3 , 1 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ) )
F_3 ( V_2 -> V_3 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ) )
F_3 ( V_2 -> V_3 , 1 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ) )
F_3 ( V_2 -> V_3 , 0 ) ;
}
static int F_7 ( struct V_4 * V_5 ,
unsigned V_6 , unsigned V_7 )
{
int V_8 ;
F_8 ( 29 , V_9 ) ;
V_10 [ 0 ] . V_11 = V_6 + 0 ;
F_9 ( V_10 ) ;
V_12 [ 2 ] . V_6 = V_6 + V_13 + 1 ;
V_14 . V_3 = V_6 + V_13 + 0 ;
V_8 = F_10 ( V_14 . V_3 ,
V_15 , L_1 ) ;
if ( V_8 < 0 ) {
V_14 . V_3 = - V_16 ;
F_11 ( V_17 L_2 ) ;
}
V_18 . V_3 = V_6 + 7 ;
V_8 = F_10 ( V_18 . V_3 ,
V_15 , L_3 ) ;
if ( V_8 < 0 ) {
V_18 . V_3 = - V_16 ;
F_11 ( V_17 L_4 ) ;
}
return 0 ;
}
static int T_1 F_12 ( void )
{
F_13 ( L_5 , & V_19 ) ;
F_14 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_15 ( void )
{
F_16 () ;
F_17 ( V_20 ,
V_20 ) ;
}
static void T_1 F_18 ( void )
{
F_19 () ;
#ifdef F_20
F_21 ( 12 ) ;
#endif
}
static void T_1 F_22 ( void )
{
unsigned char * V_21 = V_22 . V_23 ;
struct V_24 V_25 ;
int V_8 ;
V_8 = F_10 ( V_26 , V_27 , L_6 ) ;
if ( V_8 < 0 ) {
F_11 ( V_17 L_7 ,
V_26 ) ;
return;
}
F_23 ( & V_25 ) ;
V_21 [ 0 ] = 0x02 ;
V_21 [ 1 ] = V_25 . V_28 & 0xff ;
V_21 [ 2 ] = ( V_25 . V_29 & 0xff000000 ) >> 24 ;
V_21 [ 3 ] = ( V_25 . V_29 & 0x00ff0000 ) >> 16 ;
V_21 [ 4 ] = ( V_25 . V_29 & 0x0000ff00 ) >> 8 ;
V_21 [ 5 ] = ( V_25 . V_29 & 0x000000ff ) ;
}
static void T_1 F_24 ( void )
{
F_25 ( V_30 , V_31 ) ;
F_26 () ;
F_22 () ;
F_12 () ;
F_27 ( V_32 ,
F_28 ( V_32 ) ) ;
F_29 ( & V_33 ) ;
F_30 ( 2 , V_34 , 0 , NULL ) ;
F_31 ( NULL ) ;
F_32 ( & V_35 ) ;
F_33 ( V_36 , V_37 ,
F_28 ( V_37 ) ) ;
F_34 ( L_8 , V_38 ) ;
F_34 ( L_9 , V_38 ) ;
}
