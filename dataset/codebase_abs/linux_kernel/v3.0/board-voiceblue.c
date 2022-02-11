static int T_1 F_1 ( void )
{
if ( ! F_2 () )
return - V_1 ;
return F_3 ( & V_2 ) ;
}
static void T_1 F_4 ( void )
{
F_5 () ;
F_6 () ;
}
static void T_1 F_7 ( void )
{
F_8 () ;
}
static int F_9 ( struct V_3 * V_4 , unsigned long V_5 ,
void * V_6 )
{
if ( F_10 ( V_7 , & V_8 ) )
return V_9 ;
F_11 ( 0x78 , V_10 ) ;
F_11 ( 0x01 , V_11 ) ;
return V_9 ;
}
static int T_1 F_12 ( void )
{
if ( ! F_2 () )
return - V_1 ;
F_13 ( & V_12 , & V_13 ) ;
return 0 ;
}
void F_14 ( void )
{
F_15 ( 0 , 0 ) ;
F_16 ( 0 , 1 ) ;
F_16 ( 0 , 0 ) ;
V_14 = 0 ;
}
void F_17 ( void )
{
F_16 ( 0 , 0 ) ;
F_16 ( 0 , 1 ) ;
F_16 ( 0 , 0 ) ;
F_18 ( 0 ) ;
}
void F_19 ( void )
{
if ( F_20 ( V_15 , & V_8 ) )
return;
V_14 = ! V_14 ;
F_16 ( 0 , V_14 ) ;
}
static void F_21 ( char V_16 , const char * V_17 )
{
if ( F_22 () ) {
F_23 ( F_24 ( V_18 ) & ~ ( 1 << 4 ) , V_18 ) ;
F_23 ( 0x8 , V_19 ) ;
}
F_25 ( V_15 , & V_8 ) ;
F_14 () ;
while ( 1 ) ;
}
static void T_1 F_26 ( void )
{
F_27 ( V_20 ) ;
F_27 ( V_21 ) ;
F_27 ( V_22 ) ;
F_27 ( V_23 ) ;
F_27 ( V_24 ) ;
F_27 ( V_25 ) ;
F_28 ( 0 , L_1 ) ;
F_28 ( 7 , L_2 ) ;
F_15 ( 7 , 1 ) ;
F_29 ( 2 ) ;
F_16 ( 7 , 0 ) ;
F_30 ( 50 ) ;
F_28 ( 8 , L_3 ) ;
F_28 ( 6 , L_4 ) ;
F_15 ( 6 , 0 ) ;
F_28 ( 12 , L_5 ) ;
F_28 ( 13 , L_5 ) ;
F_28 ( 14 , L_5 ) ;
F_28 ( 15 , L_5 ) ;
F_31 ( F_32 ( 12 ) , V_26 ) ;
F_31 ( F_32 ( 13 ) , V_26 ) ;
F_31 ( F_32 ( 14 ) , V_26 ) ;
F_31 ( F_32 ( 15 ) , V_26 ) ;
F_33 ( V_27 , F_34 ( V_27 ) ) ;
V_28 = V_29 ;
V_30 = F_34 ( V_29 ) ;
F_35 () ;
F_36 ( & V_31 ) ;
F_37 ( 1 , 100 , NULL , 0 ) ;
F_11 ( 0x00 , V_10 ) ;
F_11 ( 0x00 , V_11 ) ;
V_32 = F_21 ;
}
