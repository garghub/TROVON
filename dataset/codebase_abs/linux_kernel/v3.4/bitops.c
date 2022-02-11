void F_1 ( unsigned long V_1 , volatile void * V_2 )
{
if ( F_2 ( V_1 , V_2 ) )
goto V_3;
V_4:
if ( ! F_3 ( V_1 , V_2 ) )
return;
V_3:
if ( F_4 ( V_1 , V_2 ) )
return;
goto V_4;
}
int F_5 ( unsigned long V_1 , volatile void * V_2 )
{
if ( F_2 ( V_1 , V_2 ) )
goto V_3;
V_4:
if ( ! F_3 ( V_1 , V_2 ) )
return 0 ;
V_3:
if ( F_4 ( V_1 , V_2 ) )
return 1 ;
goto V_4;
}
