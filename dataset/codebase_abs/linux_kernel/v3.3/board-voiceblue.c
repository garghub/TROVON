static int T_1 F_1 ( void )
{
if ( ! F_2 () )
return - V_1 ;
return F_3 ( & V_2 ) ;
}
static int F_4 ( struct V_3 * V_4 , unsigned long V_5 ,
void * V_6 )
{
if ( F_5 ( V_7 , & V_8 ) )
return V_9 ;
F_6 ( 0x78 , V_10 ) ;
F_6 ( 0x01 , V_11 ) ;
return V_9 ;
}
static int T_1 F_7 ( void )
{
if ( ! F_2 () )
return - V_1 ;
F_8 ( & V_12 , & V_13 ) ;
return 0 ;
}
void F_9 ( void )
{
F_10 ( 0 , 0 ) ;
F_11 ( 0 , 1 ) ;
F_11 ( 0 , 0 ) ;
V_14 = 0 ;
}
void F_12 ( void )
{
F_11 ( 0 , 0 ) ;
F_11 ( 0 , 1 ) ;
F_11 ( 0 , 0 ) ;
F_13 ( 0 ) ;
}
void F_14 ( void )
{
if ( F_15 ( V_15 , & V_8 ) )
return;
V_14 = ! V_14 ;
F_11 ( 0 , V_14 ) ;
}
static void F_16 ( char V_16 , const char * V_17 )
{
if ( F_17 () ) {
F_18 ( F_19 ( V_18 ) & ~ ( 1 << 4 ) , V_18 ) ;
F_18 ( 0x8 , V_19 ) ;
}
F_20 ( V_15 , & V_8 ) ;
F_9 () ;
while ( 1 ) ;
}
static void T_1 F_21 ( void )
{
F_22 ( V_20 ) ;
F_22 ( V_21 ) ;
F_22 ( V_22 ) ;
F_22 ( V_23 ) ;
F_22 ( V_24 ) ;
F_22 ( V_25 ) ;
F_23 ( 0 , L_1 ) ;
F_23 ( 7 , L_2 ) ;
F_10 ( 7 , 1 ) ;
F_24 ( 2 ) ;
F_11 ( 7 , 0 ) ;
F_25 ( 50 ) ;
F_23 ( 8 , L_3 ) ;
F_23 ( 6 , L_4 ) ;
F_10 ( 6 , 0 ) ;
F_23 ( 12 , L_5 ) ;
F_23 ( 13 , L_5 ) ;
F_23 ( 14 , L_5 ) ;
F_23 ( 15 , L_5 ) ;
F_26 ( F_27 ( 12 ) , V_26 ) ;
F_26 ( F_27 ( 13 ) , V_26 ) ;
F_26 ( F_27 ( 14 ) , V_26 ) ;
F_26 ( F_27 ( 15 ) , V_26 ) ;
F_28 ( V_27 , F_29 ( V_27 ) ) ;
V_28 = V_29 ;
V_30 = F_29 ( V_29 ) ;
F_30 () ;
F_31 ( & V_31 ) ;
F_32 ( 1 , 100 , NULL , 0 ) ;
F_6 ( 0x00 , V_10 ) ;
F_6 ( 0x00 , V_11 ) ;
}
