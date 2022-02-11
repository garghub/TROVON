int F_1 ( unsigned long V_1 , int (* F_2)( unsigned long ) )
{
struct V_2 * V_3 = V_4 -> V_5 ;
int V_6 ;
if ( ! V_7 )
return - V_8 ;
V_6 = F_3 ( V_1 , F_2 ) ;
if ( V_6 == 0 ) {
F_4 ( V_3 -> V_9 , V_3 ) ;
F_5 () ;
F_6 () ;
}
return V_6 ;
}
int F_1 ( unsigned long V_1 , int (* F_2)( unsigned long ) )
{
return F_3 ( V_1 , F_2 ) ;
}
void F_7 ( T_1 * V_10 , T_1 V_11 , T_1 V_12 , T_1 * V_13 )
{
T_1 * V_14 = V_10 ;
* V_13 = F_8 ( V_10 ) ;
* V_10 ++ = F_8 ( V_7 ) ;
* V_10 ++ = V_12 ;
* V_10 ++ = F_8 ( V_15 ) ;
F_9 ( V_10 ) ;
F_10 () ;
F_11 ( V_14 , V_11 ) ;
F_11 ( V_13 , sizeof( * V_13 ) ) ;
F_12 ( * V_13 , * V_13 + V_11 ) ;
F_12 ( F_8 ( V_13 ) ,
F_8 ( V_13 ) + sizeof( * V_13 ) ) ;
}
static int F_13 ( void )
{
void * V_16 ;
V_16 = F_14 ( F_15 () , sizeof( T_1 ) , V_17 ) ;
if ( F_16 ( ! V_16 ) )
return - V_18 ;
V_19 . V_20 = V_16 ;
V_19 . V_21 = F_8 ( V_16 ) ;
F_17 ( & V_19 ) ;
return 0 ;
}
