void T_1 F_1 ( struct V_1 * V_2 , char * * V_3 )
{
if ( F_2 () )
F_3 ( 0xa0000000 , V_4 ) ;
else
F_3 ( 0xa0000000 , V_5 ) ;
}
int F_4 ( struct V_6 * V_7 )
{
F_5 ( V_8 , 0 ) ;
F_5 ( V_9 , 0 ) ;
F_6 ( 1 ) ;
F_5 ( V_8 , 1 ) ;
F_6 ( 1 ) ;
F_5 ( V_9 , 1 ) ;
F_6 ( 1 ) ;
return 0 ;
}
int F_7 ( struct V_6 * V_7 )
{
F_5 ( V_8 , 0 ) ;
F_5 ( V_9 , 0 ) ;
return 0 ;
}
int F_8 ( struct V_6 * V_7 )
{
F_5 ( V_8 , 0 ) ;
return 0 ;
}
int F_9 ( struct V_6 * V_7 )
{
F_5 ( V_8 , 1 ) ;
F_6 ( 1 ) ;
return 0 ;
}
void F_10 ( void )
{
F_11 ( V_8 , NULL ) ;
F_11 ( V_9 , NULL ) ;
F_12 ( V_8 , 0 ) ;
F_12 ( V_9 , 0 ) ;
}
static void F_13 ( struct V_10 * V_10 )
{
}
static void T_1 F_14 ( void )
{
F_15 ( V_11 , F_16 ( V_11 ) ) ;
}
static void T_1 F_17 ( void )
{
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_20 ( NULL ) ;
F_14 () ;
F_10 () ;
F_21 ( F_22 ( V_12 ) ) ;
}
static void T_1 F_23 ( void )
{
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_20 ( NULL ) ;
F_14 () ;
F_10 () ;
F_21 ( F_22 ( V_13 ) ) ;
}
static void T_1 F_24 ( void )
{
F_25 ( F_22 ( V_14 ) ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_20 ( NULL ) ;
F_14 () ;
F_10 () ;
F_26 ( NULL , & V_15 ) ;
F_21 ( F_22 ( V_16 ) ) ;
}
static void T_1 F_27 ( void )
{
F_25 ( F_22 ( V_17 ) ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_20 ( NULL ) ;
F_14 () ;
F_28 ( L_1 , V_18 . V_19 ,
L_2 , & V_20 . V_7 ) ,
F_10 () ;
F_21 ( F_22 ( V_21 ) ) ;
F_29 ( NULL ) ;
F_30 ( & V_22 ) ;
}
static void T_1 F_31 ( void )
{
F_25 ( F_22 ( V_23 ) ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_20 ( NULL ) ;
F_28 ( L_3 , V_24 . V_19 ,
L_4 , NULL ) ,
F_10 () ;
F_21 ( F_22 ( V_25 ) ) ;
F_29 ( NULL ) ;
F_30 ( & V_22 ) ;
}
static void F_32 ( struct V_26 * V_27 )
{
unsigned long V_28 ;
V_28 = F_33 ( V_29 ) ;
if ( V_27 -> V_30 -> V_31 == 480 )
V_28 |= 0x100 ;
else
V_28 &= ~ 0x100 ;
F_34 ( V_29 , V_28 ) ;
}
static void T_1 F_35 ( void )
{
F_25 ( F_22 ( V_32 ) ) ;
F_18 ( NULL ) ;
F_19 ( NULL ) ;
F_20 ( NULL ) ;
F_28 ( L_3 , V_33 . V_19 ,
L_4 , NULL ) ,
F_10 () ;
F_21 ( F_22 ( V_34 ) ) ;
F_29 ( NULL ) ;
}
