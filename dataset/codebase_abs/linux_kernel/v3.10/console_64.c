static int F_1 ( const char * V_1 , int V_2 )
{
unsigned long args [ 7 ] ;
int V_3 ;
args [ 0 ] = ( unsigned long ) L_1 ;
args [ 1 ] = 3 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned int ) V_4 ;
args [ 4 ] = ( unsigned long ) V_1 ;
args [ 5 ] = ( unsigned int ) V_2 ;
args [ 6 ] = ( unsigned long ) - 1 ;
F_2 ( args ) ;
V_3 = ( int ) args [ 6 ] ;
if ( V_3 < 0 )
return - 1 ;
return V_3 ;
}
void F_3 ( const char * V_1 , int V_2 )
{
while ( V_2 ) {
int V_5 = F_1 ( V_1 , V_2 ) ;
if ( V_5 < 0 )
continue;
V_2 -= V_5 ;
V_1 += V_2 ;
}
}
