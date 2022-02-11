static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
char * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_6 * V_6 = V_2 -> V_7 -> V_8 ;
T_1 V_9 = V_6 -> V_10 ;
int V_11 ;
V_11 = - V_12 ;
if ( V_9 > 2 * V_13 )
goto V_14;
V_11 = - V_15 ;
V_5 = F_3 ( V_6 -> V_16 , F_4 ( V_6 , 0 ) ) ;
if ( ! V_5 )
goto V_14;
memcpy ( V_3 , V_5 -> V_17 , ( V_9 > V_13 ) ? V_13 : V_9 ) ;
F_5 ( V_5 ) ;
if ( V_9 > V_13 ) {
V_5 = F_3 ( V_6 -> V_16 , F_4 ( V_6 , 1 ) ) ;
if ( ! V_5 )
goto V_14;
memcpy ( V_3 + V_13 , V_5 -> V_17 , V_9 - V_13 ) ;
F_5 ( V_5 ) ;
}
V_3 [ V_9 ] = '\0' ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
return 0 ;
V_14:
F_8 ( V_2 ) ;
F_7 ( V_2 ) ;
return V_11 ;
}
