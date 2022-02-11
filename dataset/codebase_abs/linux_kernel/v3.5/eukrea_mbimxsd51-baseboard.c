static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_3 )
F_2 ( V_4 , 1 ) ;
else
F_2 ( V_4 , 0 ) ;
}
static void F_3 ( int V_5 )
{
if ( V_5 )
F_2 ( V_6 , 1 ) ;
else
F_2 ( V_6 , 0 ) ;
}
static int T_1 F_4 ( char * V_7 )
{
if ( ! strcmp ( V_7 , L_1 ) )
V_8 = 1 ;
else if ( ! strcmp ( V_7 , L_2 ) )
V_8 = 0 ;
return 0 ;
}
void T_1 F_5 ( void )
{
if ( F_6 ( V_9 ,
F_7 ( V_9 ) ) )
F_8 ( V_10 L_3 ) ;
F_9 ( 1 , NULL ) ;
F_9 ( 2 , & V_11 ) ;
F_10 ( 0 , NULL ) ;
F_11 ( 0 , & V_12 ) ;
F_12 ( V_13 , L_4 ) ;
F_2 ( V_13 , 1 ) ;
F_13 ( V_13 ) ;
F_12 ( V_14 , L_5 ) ;
F_14 ( V_14 ) ;
F_13 ( V_14 ) ;
F_12 ( V_4 , L_6 ) ;
F_2 ( V_4 , 0 ) ;
F_12 ( V_6 , L_7 ) ;
F_2 ( V_6 , 0 ) ;
if ( ! V_8 ) {
F_15 ( & V_15 ) ;
F_15 ( & V_16 ) ;
} else {
F_13 ( V_4 ) ;
F_13 ( V_6 ) ;
}
F_16 ( 0 , V_17 ,
F_7 ( V_17 ) ) ;
F_17 ( - 1 , & V_18 ) ;
F_18 ( & V_19 ) ;
}
