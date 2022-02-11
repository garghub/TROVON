void error ( char * V_1 )
{
puts ( L_1 ) ;
puts ( V_1 ) ;
puts ( L_2 ) ;
while ( 1 )
;
}
void F_1 ( unsigned long V_2 )
{
unsigned long V_3 , V_4 ;
V_3 = ( unsigned long ) ( & V_5 ) ;
V_4 = ( unsigned long ) ( & V_6 ) -
( unsigned long ) ( & V_5 ) ;
puts ( L_3 ) ;
F_2 ( V_3 ) ;
puts ( L_4 ) ;
F_2 ( V_4 + V_3 ) ;
puts ( L_5 ) ;
V_7 = V_2 ;
V_8 = V_2 + V_9 ;
puts ( L_6 ) ;
F_2 ( V_10 ) ;
puts ( L_5 ) ;
F_3 ( ( char * ) V_3 , V_4 , 0 , 0 ,
( void * ) V_10 , 0 , error ) ;
puts ( L_7 ) ;
}
