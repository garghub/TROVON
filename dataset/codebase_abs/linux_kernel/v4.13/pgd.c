T_1 * F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 , * V_4 ;
T_2 * V_5 , * V_6 ;
T_3 * V_7 , * V_8 ;
V_3 = ( T_1 * ) F_2 ( V_9 , 0 ) ;
if ( ! V_3 )
goto V_10;
memset ( V_3 , 0 , V_11 * sizeof( T_1 ) ) ;
V_4 = F_3 ( 0 ) ;
memcpy ( V_3 + V_11 , V_4 + V_11 ,
( V_12 - V_11 ) * sizeof( T_1 ) ) ;
F_4 ( V_3 , V_12 * sizeof( T_1 ) ) ;
if ( ! F_5 () ) {
V_5 = F_6 ( V_2 , ( V_13 * ) V_3 , 0 ) ;
if ( ! V_5 )
goto V_14;
V_7 = F_7 ( V_2 , V_5 , 0 ) ;
if ( ! V_7 )
goto V_15;
V_6 = F_8 ( ( V_13 * ) V_4 , 0 ) ;
V_8 = F_9 ( V_6 , 0 ) ;
F_10 ( V_7 , * V_8 ) ;
F_11 ( V_8 ) ;
F_11 ( V_7 ) ;
}
return V_3 ;
V_15:
F_12 ( V_2 , V_5 ) ;
F_13 ( V_2 ) ;
V_14:
F_14 ( ( unsigned long ) V_3 , 0 ) ;
V_10:
return NULL ;
}
void F_15 ( struct V_1 * V_2 , T_1 * V_16 )
{
T_2 * V_17 ;
T_4 V_18 ;
if ( ! V_16 )
return;
V_17 = F_16 ( V_16 , 0 ) ;
if ( F_17 ( * V_17 ) )
goto free;
if ( F_18 ( * V_17 ) ) {
F_19 ( * V_17 ) ;
F_20 ( V_17 ) ;
goto free;
}
V_18 = F_21 ( * V_17 ) ;
F_20 ( V_17 ) ;
F_22 ( V_2 , V_18 ) ;
F_23 ( & V_2 -> V_19 ) ;
F_12 ( V_2 , V_17 ) ;
F_13 ( V_2 ) ;
free:
F_14 ( ( unsigned long ) V_16 , 0 ) ;
}
