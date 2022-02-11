void T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * * V_5 , struct V_6 * V_7 )
{
V_7 -> V_8 = 1 ;
V_7 -> V_9 [ 0 ] . V_10 = 0xa0000000 ;
if ( F_2 () )
V_7 -> V_9 [ 0 ] . V_11 = ( 128 * 1024 * 1024 ) ;
else
V_7 -> V_9 [ 0 ] . V_11 = ( 64 * 1024 * 1024 ) ;
}
int F_3 ( struct V_12 * V_13 )
{
F_4 ( V_14 , 0 ) ;
F_4 ( V_15 , 0 ) ;
F_5 ( 1 ) ;
F_4 ( V_14 , 1 ) ;
F_5 ( 1 ) ;
F_4 ( V_15 , 1 ) ;
F_5 ( 1 ) ;
return 0 ;
}
int F_6 ( struct V_12 * V_13 )
{
F_4 ( V_14 , 0 ) ;
F_4 ( V_15 , 0 ) ;
return 0 ;
}
int F_7 ( struct V_12 * V_13 )
{
F_4 ( V_14 , 0 ) ;
return 0 ;
}
int F_8 ( struct V_12 * V_13 )
{
F_4 ( V_14 , 1 ) ;
F_5 ( 1 ) ;
return 0 ;
}
void F_9 ( void )
{
F_10 ( V_14 , NULL ) ;
F_10 ( V_15 , NULL ) ;
F_11 ( V_14 , 0 ) ;
F_11 ( V_15 , 0 ) ;
}
static void F_12 ( struct V_16 * V_16 )
{
}
void F_13 ( void )
{
F_14 ( V_17 , F_15 ( V_17 ) ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_13 () ;
F_9 () ;
F_20 ( F_21 ( V_18 ) ) ;
}
static void T_1 F_22 ( void )
{
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_13 () ;
F_9 () ;
F_20 ( F_21 ( V_19 ) ) ;
}
static void T_1 F_23 ( void )
{
F_24 ( F_21 ( V_20 ) ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_13 () ;
F_9 () ;
F_25 ( NULL , & V_21 ) ;
F_20 ( F_21 ( V_22 ) ) ;
}
static void T_1 F_26 ( void )
{
F_24 ( F_21 ( V_23 ) ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_13 () ;
F_27 ( L_1 , V_24 . V_25 ,
L_2 , & V_26 . V_13 ) ,
F_9 () ;
F_20 ( F_21 ( V_27 ) ) ;
F_28 ( NULL ) ;
F_29 ( & V_28 ) ;
}
static void T_1 F_30 ( void )
{
F_24 ( F_21 ( V_29 ) ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_27 ( L_3 , V_30 . V_25 ,
L_4 , NULL ) ,
F_9 () ;
F_20 ( F_21 ( V_31 ) ) ;
F_28 ( NULL ) ;
F_29 ( & V_28 ) ;
}
static void F_31 ( struct V_32 * V_33 )
{
unsigned long V_34 ;
V_34 = F_32 ( V_35 ) ;
if ( V_33 -> V_36 -> V_37 == 480 )
V_34 |= 0x100 ;
else
V_34 &= ~ 0x100 ;
F_33 ( V_35 , V_34 ) ;
}
static void T_1 F_34 ( void )
{
F_24 ( F_21 ( V_38 ) ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_27 ( L_3 , V_39 . V_25 ,
L_4 , NULL ) ,
F_9 () ;
F_20 ( F_21 ( V_40 ) ) ;
F_28 ( NULL ) ;
}
