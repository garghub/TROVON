void F_1 ( T_1 * V_1 , T_1 V_2 , T_1 V_3 , T_1 * V_4 )
{
* V_4 = F_2 ( V_1 ) ;
* V_1 ++ = F_2 ( V_5 ) ;
* V_1 ++ = V_3 ;
* V_1 ++ = F_2 ( V_6 ) ;
F_3 ( V_1 ) ;
F_4 () ;
F_5 ( * V_4 , * V_4 + V_2 ) ;
F_5 ( F_2 ( V_4 ) ,
F_2 ( V_4 ) + sizeof( * V_4 ) ) ;
}
int F_6 ( unsigned long V_7 , int (* F_7)( unsigned long ) )
{
struct V_8 * V_9 = V_10 -> V_11 ;
int V_12 ;
if ( ! V_5 )
return - V_13 ;
V_12 = F_8 ( V_7 , F_7 ) ;
if ( V_12 == 0 ) {
F_9 ( V_9 -> V_14 , V_9 ) ;
F_10 () ;
}
return V_12 ;
}
