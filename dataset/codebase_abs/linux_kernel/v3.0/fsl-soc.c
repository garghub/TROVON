T_1 * F_1 ( void )
{
void * V_1 ;
unsigned long V_2 = 0 ;
V_1 = F_2 ( NULL , L_1 ) ;
if ( V_1 ) {
int V_3 ;
T_1 V_4 ;
V_3 = F_3 ( V_1 , L_2 , V_5 , V_6 ) ;
if ( V_3 == 4 )
V_4 = V_5 [ 0 ] ;
else
V_4 = 2 ;
if ( V_4 != 1 && V_4 != 2 )
goto V_7;
V_3 = F_3 ( V_1 , L_3 , V_5 , V_6 ) ;
if ( V_3 < 12 )
goto V_7;
if ( V_5 [ 0 ] != 0 )
goto V_7;
if ( V_4 == 2 && V_5 [ 1 ] != 0 )
goto V_7;
if ( ! F_4 ( V_1 , V_5 + V_4 , 8 , & V_2 ) )
V_2 = 0 ;
}
V_7:
if ( ! V_2 )
printf ( L_4 ) ;
return ( T_1 * ) V_2 ;
}
