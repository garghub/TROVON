static inline void F_1 ( void )
{
F_2 ( 0 , NULL ) ;
F_2 ( 1 , NULL ) ;
F_2 ( 2 , & V_1 ) ;
}
static inline void F_3 ( void )
{
int V_2 ;
V_2 = F_4 ( V_3 , L_1 ) ;
if ( V_2 ) {
F_5 ( V_4 L_2 , V_2 ) ;
return;
}
F_6 ( V_3 , 0 ) ;
F_7 ( 1 ) ;
F_8 ( V_3 , 1 ) ;
}
static inline void F_9 ( void )
{
int V_2 ;
V_2 = F_10 ( V_5 ,
V_6 | V_7 , L_3 ) ;
if ( V_2 ) {
F_11 ( L_4 , V_2 ) ;
return;
}
}
void T_1 F_12 ( void )
{
F_13 ( V_8 ,
F_14 ( V_8 ) ) ;
}
static void T_1 F_15 ( void )
{
F_16 () ;
F_12 () ;
F_1 () ;
F_3 () ;
F_17 ( & V_9 ) ;
F_18 ( 0 , NULL ) ;
F_19 ( 0 , & V_10 ) ;
F_20 ( 0 , NULL ) ;
F_20 ( 1 , NULL ) ;
F_20 ( 2 , NULL ) ;
F_9 () ;
F_21 () ;
}
static void T_1 F_22 ( void )
{
F_23 ( 32768 , 24000000 , 22579200 , 0 ) ;
}
