int F_1 ( int V_1 , struct V_2 * V_3 )
{
int V_4 ;
V_4 = F_2 ( V_5 , V_1 , 0 , V_3 -> V_6 ) ;
if ( V_4 < 0 )
return - V_7 ;
return 0 ;
}
int F_3 ( int V_1 , struct V_2 * V_3 )
{
int V_4 ;
V_4 = F_2 ( V_8 , V_1 , 0 , V_3 -> V_6 ) ;
if ( V_4 < 0 )
return - V_7 ;
return 0 ;
}
int F_4 ( int V_1 )
{
int V_4 ;
V_4 = F_2 ( V_5 , V_1 , 0 , V_9 ) ;
if ( V_4 < 0 )
return - V_7 ;
F_5 ( V_1 ) ;
F_6 ( V_1 , V_10 ) ;
return 0 ;
}
void F_7 ( unsigned long * V_3 , unsigned long * V_11 )
{
memcpy ( V_3 , V_9 , sizeof( V_9 ) ) ;
if ( V_11 )
memcpy ( V_11 , V_10 , sizeof( V_10 ) ) ;
}
