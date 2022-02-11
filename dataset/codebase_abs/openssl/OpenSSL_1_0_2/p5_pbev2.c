T_1 * F_1 ( int V_1 , unsigned char * V_2 , int V_3 ,
int V_4 , int V_5 )
{
T_1 * V_6 = NULL ;
T_2 * V_7 = NULL ;
T_3 * V_8 = NULL ;
if ( ! ( V_7 = F_2 () ) )
goto V_9;
if ( ! ( V_8 = F_3 () ) )
goto V_9;
V_7 -> V_2 -> V_10 . V_11 = V_8 ;
V_7 -> V_2 -> type = V_12 ;
if ( ! V_3 )
V_3 = V_13 ;
if ( ! ( V_8 -> V_14 = F_4 ( V_3 ) ) )
goto V_9;
V_8 -> V_15 = V_3 ;
if ( V_2 )
memcpy ( V_8 -> V_14 , V_2 , V_3 ) ;
else if ( F_5 ( V_8 -> V_14 , V_3 ) < 0 )
goto V_9;
if ( V_1 <= 0 )
V_1 = V_16 ;
if ( ! F_6 ( V_7 -> V_1 , V_1 ) )
goto V_9;
if ( V_5 > 0 ) {
if ( ! ( V_7 -> V_17 = F_7 () ) )
goto V_9;
if ( ! F_6 ( V_7 -> V_17 , V_5 ) )
goto V_9;
}
if ( V_4 > 0 && V_4 != V_18 ) {
V_7 -> V_19 = F_8 () ;
if ( ! V_7 -> V_19 )
goto V_9;
F_9 ( V_7 -> V_19 , F_10 ( V_4 ) , V_20 , NULL ) ;
}
V_6 = F_8 () ;
if ( ! V_6 )
goto V_9;
V_6 -> V_21 = F_10 ( V_22 ) ;
if ( ! ( V_6 -> V_23 = F_11 () ) )
goto V_9;
if ( ! F_12 ( V_7 , F_13 ( T_2 ) ,
& V_6 -> V_23 -> V_10 . V_24 ) )
goto V_9;
V_6 -> V_23 -> type = V_25 ;
F_14 ( V_7 ) ;
return V_6 ;
V_9:
F_15 ( V_26 , V_27 ) ;
F_14 ( V_7 ) ;
F_16 ( V_6 ) ;
return NULL ;
}
