void F_1 ( T_1 * V_1 , T_1 V_2 , T_1 V_3 , T_1 * V_4 )
{
T_1 * V_5 = V_1 ;
* V_4 = F_2 ( V_1 ) ;
* V_1 ++ = F_2 ( V_6 ) ;
* V_1 ++ = V_3 ;
* V_1 ++ = F_2 ( V_7 ) ;
F_3 ( V_1 ) ;
F_4 () ;
F_5 ( V_5 , V_2 ) ;
F_5 ( V_4 , sizeof( * V_4 ) ) ;
F_6 ( * V_4 , * V_4 + V_2 ) ;
F_6 ( F_2 ( V_4 ) ,
F_2 ( V_4 ) + sizeof( * V_4 ) ) ;
}
int F_7 ( unsigned long V_8 , int (* F_8)( unsigned long ) )
{
struct V_9 * V_10 = V_11 -> V_12 ;
int V_13 ;
if ( ! V_6 )
return - V_14 ;
V_13 = F_9 ( V_8 , F_8 ) ;
if ( V_13 == 0 ) {
F_10 ( V_10 -> V_15 , V_10 ) ;
F_11 () ;
}
return V_13 ;
}
