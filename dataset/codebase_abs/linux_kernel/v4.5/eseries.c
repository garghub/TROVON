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
static void T_1 F_13 ( void )
{
F_14 ( NULL , L_1 , NULL , V_10 , 32768 ) ;
}
static void T_1 F_15 ( void )
{
F_16 ( NULL ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_13 () ;
F_10 () ;
F_19 ( F_20 ( V_11 ) ) ;
}
static void T_1 F_21 ( void )
{
F_16 ( NULL ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_13 () ;
F_10 () ;
F_19 ( F_20 ( V_12 ) ) ;
}
static void T_1 F_22 ( void )
{
F_23 ( F_20 ( V_13 ) ) ;
F_16 ( NULL ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_13 () ;
F_10 () ;
F_24 ( NULL , & V_14 ) ;
F_19 ( F_20 ( V_15 ) ) ;
}
static void T_1 F_25 ( void )
{
F_23 ( F_20 ( V_16 ) ) ;
F_16 ( NULL ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_13 () ;
F_26 ( L_2 , V_17 . V_18 ,
L_3 , & V_19 . V_7 ) ,
F_10 () ;
F_19 ( F_20 ( V_20 ) ) ;
F_27 ( NULL ) ;
F_28 ( & V_21 ) ;
}
static void T_1 F_29 ( void )
{
F_23 ( F_20 ( V_22 ) ) ;
F_16 ( NULL ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_26 ( L_4 , V_23 . V_18 ,
L_5 , NULL ) ,
F_10 () ;
F_19 ( F_20 ( V_24 ) ) ;
F_27 ( NULL ) ;
F_28 ( & V_21 ) ;
}
static void F_30 ( struct V_25 * V_26 )
{
unsigned long V_27 ;
V_27 = F_31 ( V_28 ) ;
if ( V_26 -> V_29 -> V_30 == 480 )
V_27 |= 0x100 ;
else
V_27 &= ~ 0x100 ;
F_32 ( V_28 , V_27 ) ;
}
static void T_1 F_33 ( void )
{
F_23 ( F_20 ( V_31 ) ) ;
F_16 ( NULL ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_26 ( L_4 , V_32 . V_18 ,
L_5 , NULL ) ,
F_10 () ;
F_19 ( F_20 ( V_33 ) ) ;
F_27 ( NULL ) ;
}
