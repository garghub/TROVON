static T_1 F_1 ( int V_1 , void * V_2 )
{
if ( F_2 ( V_3 ) )
F_3 ( V_4 , 1 ) ;
else
F_3 ( V_4 , 0 ) ;
return V_5 ;
}
static T_1 F_4 ( int V_1 , void * V_2 )
{
F_5 () ;
return V_5 ;
}
int T_2 F_6 ( void )
{
F_7 ( 0 , V_6 ,
F_8 ( V_6 ) ) ;
F_9 ( L_1 , - 1 ,
V_7 , F_8 ( V_7 ) ) ;
F_10 ( V_8 , F_8 ( V_8 ) ) ;
F_11 ( NULL , L_2 , - 1 ,
& V_9 , sizeof( V_9 ) ) ;
F_11 ( NULL , L_3 , - 1 ,
& V_10 , sizeof( V_10 ) ) ;
F_12 ( NULL , L_4 , - 1 ,
& V_11 , 1 ,
& V_12 , sizeof( V_12 ) ) ;
if ( F_13 ( F_14 ( V_3 ) ,
& F_1 ,
V_13 | V_14 ,
L_5 , NULL ) < 0 ) {
F_15 ( V_15 L_6 ,
F_14 ( V_3 ) ) ;
}
if ( F_13 ( F_14 ( V_16 ) , & F_4 ,
V_13 | V_14 ,
L_7 , NULL ) < 0 ) {
F_15 ( V_15 L_8 ,
F_14 ( V_16 ) ) ;
}
return 0 ;
}
