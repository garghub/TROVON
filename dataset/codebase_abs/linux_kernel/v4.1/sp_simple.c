union V_1 F_1 ( union V_1 V_2 )
{
unsigned int V_3 ;
union V_1 V_4 ;
V_3 = V_5 . V_6 ;
V_5 . V_6 = V_7 ;
V_4 = F_2 ( F_3 ( 0 ) , V_2 ) ;
V_5 . V_6 = V_3 ;
return V_4 ;
}
union V_1 F_4 ( union V_1 V_2 )
{
unsigned int V_3 ;
union V_1 V_4 ;
V_3 = V_5 . V_6 ;
V_5 . V_6 = V_7 ;
if ( F_5 ( V_2 ) )
V_4 = F_2 ( F_3 ( 0 ) , V_2 ) ;
else
V_4 = F_6 ( F_3 ( 0 ) , V_2 ) ;
V_5 . V_6 = V_3 ;
return V_4 ;
}
