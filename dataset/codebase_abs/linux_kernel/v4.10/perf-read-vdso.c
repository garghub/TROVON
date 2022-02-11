int main ( void )
{
void * V_1 , * V_2 ;
T_1 V_3 , V_4 ;
if ( F_1 ( & V_1 , & V_2 ) )
return 1 ;
V_3 = V_2 - V_1 ;
while ( V_3 ) {
V_4 = fwrite ( V_1 , 1 , V_3 , stdout ) ;
if ( ! V_4 )
return 1 ;
V_1 += V_4 ;
V_3 -= V_4 ;
}
if ( fflush ( stdout ) )
return 1 ;
return 0 ;
}
