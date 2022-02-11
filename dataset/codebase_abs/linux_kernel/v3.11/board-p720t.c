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
F_6 ( struct V_17 * V_17 , char * * V_18 , struct V_19 * V_20 )
{
if ( V_17 -> V_21 . V_17 != V_22 ) {
V_17 -> V_21 . V_17 = V_22 ;
V_17 -> V_21 . V_23 = F_7 ( V_24 ) ;
V_17 -> V_25 . V_26 . V_27 = 0 ;
V_17 -> V_25 . V_26 . V_28 = V_29 ;
V_17 -> V_25 . V_26 . V_30 = 0x0100 ;
V_17 = F_8 ( V_17 ) ;
V_17 -> V_21 . V_17 = V_31 ;
V_17 -> V_21 . V_23 = F_7 ( V_32 ) ;
V_17 -> V_25 . V_33 . V_23 = 4096 ;
V_17 -> V_25 . V_33 . V_4 = V_34 ;
V_17 = F_8 ( V_17 ) ;
V_17 -> V_21 . V_17 = V_35 ;
V_17 -> V_21 . V_23 = 0 ;
}
}
static void T_1 F_9 ( void )
{
int V_36 ;
F_10 () ;
for ( V_36 = 0 ; V_36 < F_11 ( V_37 ) ; V_36 ++ )
F_1 ( V_37 [ V_36 ] . V_1 , V_37 [ V_36 ] . V_2 ) ;
F_2 ( & V_38 ) ;
}
static void T_1 F_12 ( void )
{
F_13 ( F_14 ( V_39 , F_11 ( V_39 ) ) ) ;
F_15 ( & V_40 , L_1 , 0 ,
& V_41 ,
sizeof( V_41 ) ) ;
F_15 ( & V_40 , L_2 , 0 ,
& V_42 ,
sizeof( V_42 ) ) ;
F_16 ( L_3 , 0 , NULL , 0 ) ;
F_15 ( & V_40 , L_4 , 0 ,
& V_43 ,
sizeof( V_43 ) ) ;
}
