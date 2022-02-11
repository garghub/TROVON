int F_1 ( unsigned long V_1 , unsigned long V_2 )
{
if ( ! V_2 )
return 1 ;
if ( ! V_1 || V_1 > ( 0xffffffffUL - ( V_2 - 1 ) ) )
goto V_3;
if ( F_2 () )
return 1 ;
if ( V_4 <= V_1 && ( V_1 + V_2 - 1 ) < V_5 )
return 1 ;
V_3:
F_3 ( L_1 ,
V_6 -> V_7 , V_1 , V_2 ) ;
return 0 ;
}
T_1 int F_4 ( unsigned long V_8 , unsigned long V_9 )
{
F_5 ( V_8 , V_9 ) ;
F_6 ( V_8 , V_9 ) ;
return 0 ;
}
