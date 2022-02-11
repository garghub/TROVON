void F_1 ( void )
{
signal ( V_1 , V_2 ) ;
}
int F_2 ( unsigned long V_3 , int * V_4 )
{
int V_5 , V_6 [ 2 ] , V_7 ;
V_7 = F_3 ( V_6 , 1 , 1 ) ;
if( V_7 < 0 ) {
F_4 ( L_1 , - V_7 ) ;
goto V_8;
}
V_9 = V_6 [ 0 ] ;
* V_4 = V_6 [ 1 ] ;
V_7 = F_5 ( * V_4 , 0 ) ;
if ( V_7 ) {
F_4 ( L_2 ) ;
goto V_10;
}
V_5 = F_6 ( V_11 , ( void * ) V_3 , V_12 | V_13 , NULL ) ;
if( V_5 < 0 ) {
V_7 = - V_14 ;
F_4 ( L_3 , V_14 ) ;
goto V_10;
}
return ( V_5 ) ;
V_10:
F_7 ( V_6 [ 0 ] ) ;
F_7 ( V_6 [ 1 ] ) ;
V_9 = - 1 ;
* V_4 = - 1 ;
V_8:
return V_7 ;
}
