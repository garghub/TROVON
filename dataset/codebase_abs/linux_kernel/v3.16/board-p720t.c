static void T_1 F_1 ( void T_2 * V_1 , int V_2 )
{
V_3 [ 0 ] . V_4 = ( unsigned long ) V_1 ;
V_5 . V_6 = V_2 ;
F_2 ( & V_7 ) ;
}
static void F_3 ( struct V_8 * V_9 , unsigned int V_10 )
{
if ( V_10 ) {
F_4 ( V_11 , 1 ) ;
F_4 ( V_12 , 1 ) ;
F_4 ( V_13 , 1 ) ;
F_4 ( V_14 , 1 ) ;
} else {
F_4 ( V_12 , 0 ) ;
F_4 ( V_13 , 0 ) ;
F_4 ( V_14 , 0 ) ;
F_4 ( V_11 , 0 ) ;
}
}
static void F_5 ( int V_15 )
{
F_4 ( V_16 , V_15 ) ;
}
static void T_1
F_6 ( struct V_17 * V_17 , char * * V_18 )
{
if ( V_17 -> V_19 . V_17 != V_20 ) {
V_17 -> V_19 . V_17 = V_20 ;
V_17 -> V_19 . V_21 = F_7 ( V_22 ) ;
V_17 -> V_23 . V_24 . V_25 = 0 ;
V_17 -> V_23 . V_24 . V_26 = V_27 ;
V_17 -> V_23 . V_24 . V_28 = 0x0100 ;
V_17 = F_8 ( V_17 ) ;
V_17 -> V_19 . V_17 = V_29 ;
V_17 -> V_19 . V_21 = F_7 ( V_30 ) ;
V_17 -> V_23 . V_31 . V_21 = 4096 ;
V_17 -> V_23 . V_31 . V_4 = V_32 ;
V_17 = F_8 ( V_17 ) ;
V_17 -> V_19 . V_17 = V_33 ;
V_17 -> V_19 . V_21 = 0 ;
}
}
static void T_1 F_9 ( void )
{
int V_34 ;
F_10 () ;
for ( V_34 = 0 ; V_34 < F_11 ( V_35 ) ; V_34 ++ )
F_1 ( V_35 [ V_34 ] . V_1 , V_35 [ V_34 ] . V_2 ) ;
F_2 ( & V_36 ) ;
}
static void T_1 F_12 ( void )
{
F_13 ( F_14 ( V_37 , F_11 ( V_37 ) ) ) ;
F_15 ( & V_38 , L_1 , 0 ,
& V_39 ,
sizeof( V_39 ) ) ;
F_15 ( & V_38 , L_2 , 0 ,
& V_40 ,
sizeof( V_40 ) ) ;
F_16 ( L_3 , 0 , NULL , 0 ) ;
F_15 ( & V_38 , L_4 , 0 ,
& V_41 ,
sizeof( V_41 ) ) ;
}
