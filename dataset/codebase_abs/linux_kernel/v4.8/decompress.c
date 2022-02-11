void error ( char * V_1 )
{
puts ( L_1 ) ;
puts ( V_1 ) ;
puts ( L_2 ) ;
while ( 1 )
;
}
void F_1 ( void )
{
V_2 = 0x000a0dff ;
}
void F_2 ( void )
{
error ( L_3 ) ;
}
void F_3 ( unsigned long V_3 )
{
unsigned long V_4 , V_5 ;
F_1 () ;
V_4 = ( unsigned long ) ( & V_6 ) ;
V_5 = ( unsigned long ) ( & V_7 ) -
( unsigned long ) ( & V_6 ) ;
puts ( L_4 ) ;
F_4 ( V_4 ) ;
puts ( L_5 ) ;
F_4 ( V_5 + V_4 ) ;
puts ( L_6 ) ;
V_8 = V_3 ;
V_9 = V_3 + V_10 ;
puts ( L_7 ) ;
F_4 ( V_11 ) ;
puts ( L_6 ) ;
F_5 ( ( char * ) V_4 , V_5 , 0 , 0 ,
( void * ) V_11 , 0 , 0 , error ) ;
if ( F_6 ( V_12 ) &&
F_7 ( ( void * ) & V_13 ) == V_14 ) {
unsigned int V_15 , V_16 ;
V_16 = F_8 ( ( void * ) & V_13 ) ;
V_15 = F_9 ( ( void * ) & V_7 - 4 ) ;
memcpy ( ( void * ) V_11 + V_15 ,
V_13 , V_16 ) ;
}
puts ( L_8 ) ;
}
