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
F_13 ( & V_19 ,
V_20 | V_21 ,
V_22 ) ;
F_14 ( L_5 , & V_19 ) ;
F_15 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_16 ( void )
{
F_17 () ;
F_18 ( V_23 ,
V_23 ) ;
}
static void T_1 F_19 ( void )
{
F_20 () ;
}
static void T_1 F_21 ( void )
{
unsigned char * V_24 = V_25 . V_26 ;
struct V_27 V_28 ;
int V_8 ;
V_8 = F_10 ( V_29 , V_30 , L_6 ) ;
if ( V_8 < 0 ) {
F_11 ( V_17 L_7 ,
V_29 ) ;
return;
}
F_22 ( & V_28 ) ;
V_24 [ 0 ] = 0x02 ;
V_24 [ 1 ] = V_28 . V_31 & 0xff ;
V_24 [ 2 ] = ( V_28 . V_32 & 0xff000000 ) >> 24 ;
V_24 [ 3 ] = ( V_28 . V_32 & 0x00ff0000 ) >> 16 ;
V_24 [ 4 ] = ( V_28 . V_32 & 0x0000ff00 ) >> 8 ;
V_24 [ 5 ] = ( V_28 . V_32 & 0x000000ff ) ;
}
static void T_1 F_23 ( void )
{
F_24 ( V_33 , V_34 ) ;
F_25 () ;
F_21 () ;
F_12 () ;
F_26 ( V_35 ,
F_27 ( V_35 ) ) ;
F_28 ( & V_36 ) ;
F_29 ( 2 , V_37 , 0 , NULL ) ;
F_30 ( NULL ) ;
F_31 ( & V_38 ) ;
F_32 ( V_39 , V_40 ,
F_27 ( V_40 ) ) ;
F_33 ( L_8 , V_41 ) ;
F_33 ( L_9 , V_41 ) ;
}
