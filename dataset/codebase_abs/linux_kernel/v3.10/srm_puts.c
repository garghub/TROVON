long
F_1 ( const char * V_1 , long V_2 )
{
long V_3 , V_4 ;
if ( ! V_5 )
return V_2 ;
for ( V_3 = V_2 ; V_3 > 0 ; V_3 -= V_4 )
{
V_4 = F_2 ( 0 , V_1 , V_3 ) ;
V_4 &= 0xffffffff ;
V_1 += V_4 ;
}
return V_2 ;
}
