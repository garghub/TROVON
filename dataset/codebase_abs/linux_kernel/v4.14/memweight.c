T_1 F_1 ( const void * V_1 , T_1 V_2 )
{
T_1 V_3 = 0 ;
T_1 V_4 ;
const unsigned char * V_5 = V_1 ;
for (; V_2 > 0 && ( ( unsigned long ) V_5 ) % sizeof( long ) ;
V_2 -- , V_5 ++ )
V_3 += F_2 ( * V_5 ) ;
V_4 = V_2 / sizeof( long ) ;
if ( V_4 ) {
F_3 ( V_4 >= V_6 / V_7 ) ;
V_3 += F_4 ( ( unsigned long * ) V_5 ,
V_4 * V_7 ) ;
V_2 -= V_4 * sizeof( long ) ;
V_5 += V_4 * sizeof( long ) ;
}
for (; V_2 > 0 ; V_2 -- , V_5 ++ )
V_3 += F_2 ( * V_5 ) ;
return V_3 ;
}
