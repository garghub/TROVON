T_1 F_1 ( unsigned long V_1 , char * V_2 ,
T_2 V_3 , unsigned long V_4 , int V_5 )
{
void * V_6 ;
if ( ! V_3 )
return 0 ;
V_6 = F_2 ( V_1 << V_7 , V_8 ) ;
if ( ! V_6 )
return - V_9 ;
if ( V_5 ) {
if ( F_3 ( V_2 , V_6 + V_4 , V_3 ) ) {
F_4 ( V_6 ) ;
return - V_10 ;
}
} else
memcpy ( V_2 , V_6 + V_4 , V_3 ) ;
F_5 () ;
F_4 ( V_6 ) ;
return V_3 ;
}
