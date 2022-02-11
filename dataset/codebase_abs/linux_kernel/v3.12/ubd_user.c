int F_1 ( unsigned long V_1 , int * V_2 )
{
int V_3 , V_4 [ 2 ] , V_5 ;
V_5 = F_2 ( V_4 , 1 , 1 ) ;
if( V_5 < 0 ) {
F_3 ( L_1 , - V_5 ) ;
goto V_6;
}
V_7 = V_4 [ 0 ] ;
* V_2 = V_4 [ 1 ] ;
V_5 = F_4 ( * V_2 , 0 ) ;
if ( V_5 ) {
F_3 ( L_2 ) ;
goto V_8;
}
V_3 = F_5 ( V_9 , ( void * ) V_1 , V_10 | V_11 , NULL ) ;
if( V_3 < 0 ) {
V_5 = - V_12 ;
F_3 ( L_3 , V_12 ) ;
goto V_8;
}
return ( V_3 ) ;
V_8:
F_6 ( V_4 [ 0 ] ) ;
F_6 ( V_4 [ 1 ] ) ;
V_7 = - 1 ;
* V_2 = - 1 ;
V_6:
return V_5 ;
}
