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
F_10 ( NULL , L_2 , - 1 ,
& V_8 , sizeof( V_8 ) ) ;
F_10 ( NULL , L_3 , - 1 ,
& V_9 , sizeof( V_9 ) ) ;
F_11 ( NULL , L_4 , - 1 ,
& V_10 , 1 ,
& V_11 , sizeof( V_11 ) ) ;
if ( F_12 ( F_13 ( V_3 ) ,
& F_1 ,
V_12 | V_13 ,
L_5 , NULL ) < 0 ) {
F_14 ( V_14 L_6 ,
F_13 ( V_3 ) ) ;
}
if ( F_12 ( F_13 ( V_15 ) , & F_4 ,
V_12 | V_13 ,
L_7 , NULL ) < 0 ) {
F_14 ( V_14 L_8 ,
F_13 ( V_15 ) ) ;
}
return 0 ;
}
