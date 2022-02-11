static void F_1 ( void * V_1 )
{
T_1 V_2 , V_3 ;
T_1 V_4 , V_5 ;
struct V_6 * V_7 = F_2 ( & V_8 ) ;
T_2 V_9 = F_3 () ;
T_3 V_10 = F_4 ( V_9 , V_7 -> time ) ;
unsigned long V_11 ;
if ( V_10 < V_12 )
return;
F_5 ( V_11 ) ;
F_6 ( V_13 , V_2 ) ;
F_6 ( V_14 , V_4 ) ;
F_7 ( V_11 ) ;
V_3 = V_2 - V_7 -> V_2 ;
V_5 = V_4 - V_7 -> V_4 ;
if ( V_5 == 0 )
return;
V_7 -> time = V_9 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_4 = V_4 ;
if ( V_10 > V_15 )
V_7 -> V_16 = 0 ;
else
V_7 -> V_16 = F_8 ( ( V_17 * V_3 ) , V_5 ) ;
}
unsigned int F_9 ( int V_18 )
{
unsigned int V_16 ;
if ( ! V_17 )
return 0 ;
if ( ! F_10 ( V_19 ) )
return 0 ;
F_11 ( V_18 , F_1 , NULL , 1 ) ;
V_16 = F_12 ( V_8 . V_16 , V_18 ) ;
if ( V_16 )
return V_16 ;
F_13 ( V_20 ) ;
F_11 ( V_18 , F_1 , NULL , 1 ) ;
return F_12 ( V_8 . V_16 , V_18 ) ;
}
