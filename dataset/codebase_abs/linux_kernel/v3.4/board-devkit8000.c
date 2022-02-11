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
V_9 [ 0 ] . V_10 = V_6 + 0 ;
F_8 ( V_9 ) ;
V_11 [ 2 ] . V_6 = V_6 + V_12 + 1 ;
V_13 . V_3 = V_6 + V_12 + 0 ;
V_8 = F_9 ( V_13 . V_3 ,
V_14 , L_1 ) ;
if ( V_8 < 0 ) {
V_13 . V_3 = - V_15 ;
F_10 ( V_16 L_2 ) ;
}
V_17 . V_3 = V_6 + 7 ;
V_8 = F_9 ( V_17 . V_3 ,
V_14 , L_3 ) ;
if ( V_8 < 0 ) {
V_17 . V_3 = - V_15 ;
F_10 ( V_16 L_4 ) ;
}
return 0 ;
}
static int T_1 F_11 ( void )
{
F_12 ( & V_18 ,
V_19 | V_20 ,
V_21 ) ;
F_13 ( L_5 , & V_18 ) ;
F_14 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_15 ( void )
{
unsigned char * V_22 = V_23 . V_24 ;
struct V_25 V_26 ;
int V_8 ;
V_8 = F_9 ( V_27 , V_28 , L_6 ) ;
if ( V_8 < 0 ) {
F_10 ( V_16 L_7 ,
V_27 ) ;
return;
}
F_16 ( & V_26 ) ;
V_22 [ 0 ] = 0x02 ;
V_22 [ 1 ] = V_26 . V_29 & 0xff ;
V_22 [ 2 ] = ( V_26 . V_30 & 0xff000000 ) >> 24 ;
V_22 [ 3 ] = ( V_26 . V_30 & 0x00ff0000 ) >> 16 ;
V_22 [ 4 ] = ( V_26 . V_30 & 0x0000ff00 ) >> 8 ;
V_22 [ 5 ] = ( V_26 . V_30 & 0x000000ff ) ;
}
static void T_1 F_17 ( void )
{
F_18 ( V_31 , V_32 ) ;
F_19 () ;
F_20 ( V_33 ,
V_33 ) ;
F_15 () ;
F_21 ( V_9 ) ;
F_11 () ;
V_34 [ 2 ] . V_35 = F_22 ( V_27 ) ;
F_23 ( V_36 ,
F_24 ( V_36 ) ) ;
F_25 ( & V_37 ) ;
F_26 ( 2 , V_38 , 0 , NULL ) ;
F_27 ( NULL ) ;
F_28 ( & V_39 ) ;
F_29 ( V_40 , V_41 ,
F_24 ( V_41 ) ) ;
F_30 ( L_8 , V_42 ) ;
F_30 ( L_9 , V_42 ) ;
}
