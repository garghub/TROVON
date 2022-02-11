void error ( char * V_1 )
{
puts ( L_1 ) ;
puts ( V_1 ) ;
puts ( L_2 ) ;
while ( 1 )
;
}
void * memcpy ( void * V_2 , const void * V_3 , T_1 V_4 )
{
int V_5 ;
const char * V_6 = V_3 ;
char * V_7 = V_2 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
V_7 [ V_5 ] = V_6 [ V_5 ] ;
return V_2 ;
}
void * memset ( void * V_6 , int V_8 , T_1 V_4 )
{
int V_5 ;
char * V_9 = V_6 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
V_9 [ V_5 ] = V_8 ;
return V_6 ;
}
void F_1 ( unsigned long V_10 )
{
unsigned long V_11 , V_12 ;
V_11 = ( unsigned long ) ( & V_13 ) ;
V_12 = ( unsigned long ) ( & V_14 ) -
( unsigned long ) ( & V_13 ) ;
puts ( L_3 ) ;
F_2 ( V_11 ) ;
puts ( L_4 ) ;
F_2 ( V_12 + V_11 ) ;
puts ( L_5 ) ;
V_15 = V_10 ;
V_16 = V_10 + V_17 ;
puts ( L_6 ) ;
F_2 ( V_18 ) ;
puts ( L_5 ) ;
F_3 ( ( char * ) V_11 , V_12 , 0 , 0 ,
( void * ) V_18 , 0 , error ) ;
puts ( L_7 ) ;
}
