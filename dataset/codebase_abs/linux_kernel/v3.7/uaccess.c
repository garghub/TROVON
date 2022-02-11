T_1 F_1 ( void T_2 * V_1 , unsigned long V_2 )
{
long V_3 ;
while ( V_2 > V_4 ) {
V_3 = F_2 ( V_1 , & V_5 ,
V_4 ) ;
if ( V_3 )
return V_2 - ( V_4 - V_3 ) ;
V_2 -= V_4 ;
V_1 += V_4 ;
}
if ( V_2 )
V_2 = F_2 ( V_1 , & V_5 , V_2 ) ;
return V_2 ;
}
unsigned long F_3 ( void T_2 * V_1 , unsigned long V_2 )
{
if ( ! F_4 ( V_6 , V_1 , V_2 ) )
return V_2 ;
else
return F_1 ( V_1 , V_2 ) ;
}
