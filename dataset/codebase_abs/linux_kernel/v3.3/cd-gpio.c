static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_2 , F_3 ( 100 ) ) ;
return V_3 ;
}
int F_4 ( struct V_4 * V_5 , unsigned int V_6 ,
unsigned int V_1 , unsigned long V_7 )
{
T_2 V_8 = strlen ( F_5 ( V_5 -> V_9 ) ) + 4 ;
struct V_10 * V_11 = F_6 ( sizeof( * V_11 ) + V_8 , V_12 ) ;
int V_13 ;
if ( ! V_11 )
return - V_14 ;
snprintf ( V_11 -> V_15 , V_8 , L_1 , F_5 ( V_5 -> V_9 ) ) ;
V_13 = F_7 ( V_6 , V_16 , V_11 -> V_15 ) ;
if ( V_13 < 0 )
goto V_17;
V_13 = F_8 ( V_1 , NULL , F_1 ,
V_7 , V_11 -> V_15 , V_5 ) ;
if ( V_13 < 0 )
goto V_18;
V_11 -> V_6 = V_6 ;
V_5 -> V_19 . V_1 = V_1 ;
V_5 -> V_19 . V_20 = V_11 ;
return 0 ;
V_18:
F_9 ( V_6 ) ;
V_17:
F_10 ( V_11 ) ;
return V_13 ;
}
void F_11 ( struct V_4 * V_5 )
{
struct V_10 * V_11 = V_5 -> V_19 . V_20 ;
F_12 ( V_5 -> V_19 . V_1 , V_5 ) ;
F_9 ( V_11 -> V_6 ) ;
F_10 ( V_11 ) ;
}
