const char * F_1 ( void )
{
return L_1 ;
}
void T_1 F_2 ( void )
{
unsigned char * V_1 ;
unsigned long V_2 ;
V_3 = V_4 ;
V_5 = ( char * * ) V_6 ;
V_7 = ( char * * ) V_8 ;
F_3 () ;
V_1 = F_4 ( L_2 ) ;
if ( ! V_1 || F_5 ( V_1 , 0 , & V_2 ) )
V_2 = 0x04000000 ;
F_6 ( 0 , V_2 , V_9 ) ;
}
void F_7 ( unsigned char V_10 )
{
F_8 ( V_11 , V_10 ) ;
}
static void F_9 ( char * V_10 )
{
F_10 ( 4 , 0 ) ;
F_10 ( 5 , 0 ) ;
F_11 ( V_12 L_3 ) ;
F_12 () ;
F_10 ( 1 , 0 ) ;
F_13 ( 1 ) ;
F_14 ( 1 , 1 ) ;
while ( 1 )
F_15 () ;
}
static void F_16 ( void )
{
while ( 1 )
F_15 () ;
}
void T_1 F_17 ( void )
{
F_11 ( V_13 L_4 ) ;
V_14 = F_16 ;
V_15 = F_16 ;
V_16 = F_9 ;
F_18 ( V_17 ) ;
F_18 ( V_18 ) ;
F_10 ( 215 , 1 ) ;
}
static int F_19 ( const struct V_19 * V_20 , T_2 V_21 , T_2 V_22 )
{
if ( ( V_21 == 0 ) && ( V_22 == 1 ) )
return V_23 ;
else if ( ( V_21 == 0 ) && ( V_22 == 2 ) )
return V_24 ;
return 0xff ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_25 ) ;
}
static int T_1 F_22 ( void )
{
F_23 ( 0 , V_26 , F_24 ( V_26 ) ) ;
return F_25 ( V_27 , F_24 ( V_27 ) ) ;
}
