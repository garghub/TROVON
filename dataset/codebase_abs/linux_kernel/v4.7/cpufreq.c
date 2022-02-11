void F_1 ( int V_1 , struct V_2 * V_3 ,
void (* F_2)( struct V_2 * V_3 , T_1 time ,
unsigned long V_4 , unsigned long V_5 ) )
{
if ( F_3 ( ! V_3 || ! F_2 ) )
return;
if ( F_3 ( F_4 ( V_6 , V_1 ) ) )
return;
V_3 -> F_2 = F_2 ;
F_5 ( F_4 ( V_6 , V_1 ) , V_3 ) ;
}
void F_6 ( int V_1 )
{
F_5 ( F_4 ( V_6 , V_1 ) , NULL ) ;
}
