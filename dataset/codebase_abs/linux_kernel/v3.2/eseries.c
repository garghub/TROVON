void T_1 F_1 ( struct V_1 * V_2 , char * * V_3 , struct V_4 * V_5 )
{
V_5 -> V_6 = 1 ;
V_5 -> V_7 [ 0 ] . V_8 = 0xa0000000 ;
if ( F_2 () )
V_5 -> V_7 [ 0 ] . V_9 = ( 128 * 1024 * 1024 ) ;
else
V_5 -> V_7 [ 0 ] . V_9 = ( 64 * 1024 * 1024 ) ;
}
int F_3 ( struct V_10 * V_11 )
{
F_4 ( V_12 , 0 ) ;
F_4 ( V_13 , 0 ) ;
F_5 ( 1 ) ;
F_4 ( V_12 , 1 ) ;
F_5 ( 1 ) ;
F_4 ( V_13 , 1 ) ;
F_5 ( 1 ) ;
return 0 ;
}
int F_6 ( struct V_10 * V_11 )
{
F_4 ( V_12 , 0 ) ;
F_4 ( V_13 , 0 ) ;
return 0 ;
}
int F_7 ( struct V_10 * V_11 )
{
F_4 ( V_12 , 0 ) ;
return 0 ;
}
int F_8 ( struct V_10 * V_11 )
{
F_4 ( V_12 , 1 ) ;
F_5 ( 1 ) ;
return 0 ;
}
void F_9 ( void )
{
F_10 ( V_12 , NULL ) ;
F_10 ( V_13 , NULL ) ;
F_11 ( V_12 , 0 ) ;
F_11 ( V_13 , 0 ) ;
}
static void F_12 ( struct V_14 * V_14 )
{
}
static void T_1 F_13 ( void )
{
F_14 ( V_15 , F_15 ( V_15 ) ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_13 () ;
F_9 () ;
F_20 ( F_21 ( V_16 ) ) ;
}
static void T_1 F_22 ( void )
{
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_13 () ;
F_9 () ;
F_20 ( F_21 ( V_17 ) ) ;
}
static void T_1 F_23 ( void )
{
F_24 ( F_21 ( V_18 ) ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_13 () ;
F_9 () ;
F_25 ( NULL , & V_19 ) ;
F_20 ( F_21 ( V_20 ) ) ;
}
static void T_1 F_26 ( void )
{
F_24 ( F_21 ( V_21 ) ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_13 () ;
F_27 ( L_1 , V_22 . V_23 ,
L_2 , & V_24 . V_11 ) ,
F_9 () ;
F_20 ( F_21 ( V_25 ) ) ;
F_28 ( NULL ) ;
F_29 ( & V_26 ) ;
}
static void T_1 F_30 ( void )
{
F_24 ( F_21 ( V_27 ) ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_27 ( L_3 , V_28 . V_23 ,
L_4 , NULL ) ,
F_9 () ;
F_20 ( F_21 ( V_29 ) ) ;
F_28 ( NULL ) ;
F_29 ( & V_26 ) ;
}
static void F_31 ( struct V_30 * V_31 )
{
unsigned long V_32 ;
V_32 = F_32 ( V_33 ) ;
if ( V_31 -> V_34 -> V_35 == 480 )
V_32 |= 0x100 ;
else
V_32 &= ~ 0x100 ;
F_33 ( V_33 , V_32 ) ;
}
static void T_1 F_34 ( void )
{
F_24 ( F_21 ( V_36 ) ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_27 ( L_3 , V_37 . V_23 ,
L_4 , NULL ) ,
F_9 () ;
F_20 ( F_21 ( V_38 ) ) ;
F_28 ( NULL ) ;
}
