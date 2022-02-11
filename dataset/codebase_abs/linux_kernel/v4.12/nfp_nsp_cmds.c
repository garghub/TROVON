struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_5 * V_6 ;
int V_7 ;
if ( F_2 ( V_3 ) < 15 )
return NULL ;
V_6 = F_3 ( sizeof( * V_6 ) , V_8 ) ;
if ( ! V_6 )
return NULL ;
V_7 = F_4 ( V_3 , V_6 , sizeof( * V_6 ) ) ;
if ( V_7 < 0 ) {
F_5 ( F_6 ( V_3 ) , L_1 ,
V_7 ) ;
goto V_9;
}
V_4 = F_3 ( sizeof( * V_4 ) , V_8 ) ;
if ( ! V_4 )
goto V_9;
memcpy ( V_4 -> V_10 , V_6 -> V_10 , sizeof( V_4 -> V_10 ) ) ;
V_4 -> V_10 [ sizeof( V_4 -> V_10 ) - 1 ] = '\0' ;
V_4 -> V_11 = V_6 -> V_11 ;
V_4 -> V_12 = V_6 -> V_12 ;
V_4 -> V_13 = V_6 -> V_13 ;
V_4 -> V_14 = V_6 -> V_14 ;
V_4 -> V_15 = F_7 ( V_6 -> V_15 ) ;
V_4 -> V_16 = F_7 ( V_6 -> V_16 ) ;
V_4 -> V_3 = F_7 ( V_6 -> V_3 ) ;
V_9:
F_8 ( V_6 ) ;
return V_4 ;
}
