int F_1 ( unsigned long V_1 , int (* F_2)( unsigned long ) )
{
struct V_2 * V_3 = V_4 -> V_5 ;
T_1 V_6 = F_3 ( F_4 () ) ;
int V_7 ;
if ( ! V_8 )
return - V_9 ;
V_7 = F_5 ( V_1 , F_2 , V_6 ) ;
if ( V_7 == 0 ) {
F_6 ( V_3 -> V_10 , V_3 ) ;
F_7 () ;
F_8 () ;
}
return V_7 ;
}
int F_1 ( unsigned long V_1 , int (* F_2)( unsigned long ) )
{
T_1 V_6 = F_3 ( F_4 () ) ;
return F_5 ( V_1 , F_2 , V_6 ) ;
}
void F_9 ( T_1 * V_11 , T_1 V_12 , T_1 V_13 , T_1 * V_14 )
{
T_1 * V_15 = V_11 ;
* V_14 = F_10 ( V_11 ) ;
* V_11 ++ = F_10 ( V_8 ) ;
* V_11 ++ = V_13 ;
* V_11 ++ = F_10 ( V_16 ) ;
F_11 ( V_11 ) ;
F_12 () ;
F_13 ( V_15 , V_12 ) ;
F_13 ( V_14 , sizeof( * V_14 ) ) ;
F_14 ( * V_14 , * V_14 + V_12 ) ;
F_14 ( F_10 ( V_14 ) ,
F_10 ( V_14 ) + sizeof( * V_14 ) ) ;
}
static int F_15 ( void )
{
void * V_17 ;
V_17 = F_16 ( F_17 () , sizeof( T_1 ) , V_18 ) ;
if ( F_18 ( ! V_17 ) )
return - V_19 ;
V_20 . V_21 = V_17 ;
V_20 . V_22 = F_10 ( V_17 ) ;
F_19 ( & V_20 ) ;
return 0 ;
}
