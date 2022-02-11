int F_1 ( unsigned long V_1 , unsigned long V_2 )
{
if ( ! V_2 )
return 1 ;
if ( ! V_1 || V_1 > ( 0xffffffffUL - ( V_2 - 1 ) ) )
goto V_3;
if ( F_2 ( F_3 () , V_4 ) )
return 1 ;
if ( V_5 <= V_1 && ( V_1 + V_2 - 1 ) < V_6 )
return 1 ;
V_3:
F_4 ( L_1 ,
V_7 -> V_8 , V_1 , V_2 ) ;
return 0 ;
}
T_1 int F_5 ( unsigned long V_9 , unsigned long V_10 )
{
F_6 ( V_9 , V_10 ) ;
F_7 ( V_9 , V_10 ) ;
return 0 ;
}
