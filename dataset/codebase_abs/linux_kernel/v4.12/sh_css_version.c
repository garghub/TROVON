enum V_1
F_1 ( char * V_2 , int V_3 )
{
if ( V_3 <= ( int ) strlen ( V_4 ) + ( int ) strlen ( F_2 () ) + 5 )
return V_5 ;
strcpy ( V_2 , V_4 ) ;
strcat ( V_2 , L_1 ) ;
strcat ( V_2 , F_2 () ) ;
strcat ( V_2 , L_2 ) ;
return V_6 ;
}
