int
F_1 ( struct V_1 * V_2 ,
int (* F_2)( void * ) , void * V_3 , char * V_4 )
{
F_3 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = F_4 ( F_2 , V_3 , V_4 ) ;
if ( F_5 ( V_2 -> V_6 ) ) {
V_2 -> V_7 = 0 ;
return 0 ;
}
V_2 -> V_7 = V_2 -> V_6 -> V_8 ;
return 1 ;
}
void
F_6 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
if ( V_2 -> V_7 == 0 )
return;
F_7 ( V_2 -> V_6 ) ;
if ( F_8 ( & V_2 -> V_5 , 60 * V_10 ) )
V_9 = 1 ;
if ( V_9 )
V_2 -> V_7 = 0 ;
}
