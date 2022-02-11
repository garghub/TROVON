static void T_1 F_1 ( const char * V_1 , int V_2 ,
unsigned long V_3 , unsigned long V_4 ,
int V_5 , const void * V_6 ,
T_2 V_7 )
{
struct V_8 V_9 [ 2 ] ;
struct V_10 * V_11 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_9 [ 0 ] . V_12 = V_13 ;
V_9 [ 0 ] . V_14 = V_3 ;
V_9 [ 0 ] . V_15 = V_3 + V_4 - 1 ;
V_9 [ 1 ] . V_12 = V_16 ;
V_9 [ 1 ] . V_14 = V_5 ;
V_9 [ 1 ] . V_15 = V_5 ;
V_11 = F_2 ( NULL , V_1 , V_2 ,
V_9 , F_3 ( V_9 ) ,
V_6 , V_7 ) ;
if ( F_4 ( V_11 ) ) {
F_5 ( L_1 ,
V_3 , ( int ) F_6 ( V_11 ) ) ;
return;
}
V_11 -> V_17 . V_18 = & V_19 ;
V_11 -> V_17 . V_20 = F_7 ( 32 ) ;
}
static void T_1 F_8 ( void )
{
void T_3 * V_21 ;
F_9 ( V_22 ) ;
F_10 ( 1000 ) ;
F_11 ( V_22 ) ;
V_21 = F_12 ( V_23 , V_24 ) ;
F_13 ( 0xf0000 , V_21 + V_25 ) ;
F_13 ( 0x20c00 , V_21 + V_26 ) ;
F_14 ( V_21 ) ;
F_10 ( 900 ) ;
F_1 ( L_2 , - 1 ,
V_27 , V_28 ,
F_15 ( 6 ) ,
& V_29 , sizeof( V_29 ) ) ;
F_1 ( L_3 , - 1 ,
V_30 , V_31 ,
F_16 ( 3 ) ,
& V_32 , sizeof( V_32 ) ) ;
}
static void T_1 F_17 ( void )
{
void T_3 * V_21 ;
F_11 ( V_33 ) ;
F_9 ( V_34 ) ;
F_10 ( 1000 ) ;
F_9 ( V_33 ) ;
F_11 ( V_34 ) ;
V_21 = F_12 ( V_35 , V_36 ) ;
F_13 ( 0x3 , V_21 + V_26 ) ;
F_14 ( V_21 ) ;
F_1 ( L_2 , - 1 ,
V_37 , V_38 ,
F_16 ( 3 ) ,
& V_29 , sizeof( V_29 ) ) ;
}
static void T_1 F_18 ( void )
{
F_9 ( V_39 ) ;
F_10 ( 10 ) ;
F_11 ( V_40 ) ;
F_10 ( 10 ) ;
F_11 ( V_41 ) ;
F_10 ( 10 ) ;
F_1 ( L_3 , - 1 ,
V_42 , V_43 ,
F_16 ( 3 ) ,
& V_44 , sizeof( V_44 ) ) ;
}
static void T_1 F_19 ( void )
{
F_9 ( V_45 ) ;
F_10 ( 10 ) ;
F_11 ( V_46 ) ;
F_10 ( 10 ) ;
F_11 ( V_47 ) ;
F_10 ( 10 ) ;
F_1 ( L_3 , - 1 ,
V_48 , V_49 ,
F_16 ( 3 ) ,
& V_44 , sizeof( V_44 ) ) ;
}
static void T_1 F_20 ( void )
{
F_9 ( V_50 ) ;
F_10 ( 10 ) ;
F_11 ( V_51 ) ;
F_10 ( 10 ) ;
F_11 ( V_52 ) ;
F_10 ( 10 ) ;
F_1 ( L_3 , - 1 ,
V_53 , V_54 ,
F_16 ( 3 ) ,
& V_44 , sizeof( V_44 ) ) ;
}
static void T_1 F_21 ( void )
{
T_4 V_55 ;
V_55 = F_22 ( V_56 ) ;
if ( V_55 & V_57 )
return;
F_9 ( V_58 ) ;
F_23 ( 1000 ) ;
F_11 ( V_59 ) ;
F_23 ( 1000 ) ;
F_11 ( V_60 ) ;
F_23 ( 1000 ) ;
F_11 ( V_61 ) ;
F_23 ( 1000 ) ;
F_1 ( L_3 , - 1 ,
V_62 , V_63 ,
F_16 ( 3 ) ,
& V_44 , sizeof( V_44 ) ) ;
}
static void T_1 F_24 ( void )
{
F_1 ( L_3 , 0 ,
V_64 , V_65 ,
F_25 ( 0 ) ,
& V_44 , sizeof( V_44 ) ) ;
F_1 ( L_3 , 1 ,
V_66 , V_65 ,
F_25 ( 1 ) ,
& V_44 , sizeof( V_44 ) ) ;
}
void T_1 F_26 ( void )
{
if ( F_27 () )
F_8 () ;
else if ( F_28 () )
F_17 () ;
else if ( F_29 () || F_30 () )
F_18 () ;
else if ( F_31 () )
F_19 () ;
else if ( F_32 () )
F_20 () ;
else if ( F_33 () )
F_21 () ;
else if ( F_34 () )
F_24 () ;
else
F_35 () ;
}
