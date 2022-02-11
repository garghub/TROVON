static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_2 , F_3 ( 100 ) ) ;
return V_3 ;
}
int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
T_2 V_7 = strlen ( F_5 ( V_5 -> V_8 ) ) + 4 ;
struct V_9 * V_10 ;
int V_1 = F_6 ( V_6 ) ;
int V_11 ;
if ( V_1 < 0 )
return V_1 ;
V_10 = F_7 ( sizeof( * V_10 ) + V_7 , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
snprintf ( V_10 -> V_14 , V_7 , L_1 , F_5 ( V_5 -> V_8 ) ) ;
V_11 = F_8 ( V_6 , V_15 , V_10 -> V_14 ) ;
if ( V_11 < 0 )
goto V_16;
V_11 = F_9 ( V_1 , NULL , F_1 ,
V_17 | V_18 |
V_19 , V_10 -> V_14 , V_5 ) ;
if ( V_11 < 0 )
goto V_20;
V_10 -> V_6 = V_6 ;
V_5 -> V_21 . V_1 = V_1 ;
V_5 -> V_21 . V_22 = V_10 ;
return 0 ;
V_20:
F_10 ( V_6 ) ;
V_16:
F_11 ( V_10 ) ;
return V_11 ;
}
void F_12 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_21 . V_22 ;
if ( ! V_10 )
return;
F_13 ( V_5 -> V_21 . V_1 , V_5 ) ;
F_10 ( V_10 -> V_6 ) ;
F_11 ( V_10 ) ;
}
