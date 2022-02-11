unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 )
{
if ( V_1 && V_2 )
return ( V_1 / F_2 ( V_1 , V_2 ) ) * V_2 ;
else
return 0 ;
}
unsigned long F_3 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 )
return V_3 ;
return ( V_2 ? : V_1 ) ;
}
