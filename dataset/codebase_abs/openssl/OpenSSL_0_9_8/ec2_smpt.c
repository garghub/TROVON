int F_1 ( const T_1 * V_1 , T_2 * V_2 ,
const T_3 * V_3 , int V_4 , T_4 * V_5 )
{
#ifndef F_2
F_3 ( V_6 , V_7 ) ;
return 0 ;
#else
T_4 * V_8 = NULL ;
T_3 * V_9 , * V_10 , * V_11 , * V_12 ;
int V_13 = 0 , V_14 ;
F_4 () ;
if ( V_5 == NULL )
{
V_5 = V_8 = F_5 () ;
if ( V_5 == NULL )
return 0 ;
}
V_4 = ( V_4 != 0 ) ? 1 : 0 ;
F_6 ( V_5 ) ;
V_9 = F_7 ( V_5 ) ;
V_10 = F_7 ( V_5 ) ;
V_11 = F_7 ( V_5 ) ;
V_12 = F_7 ( V_5 ) ;
if ( V_12 == NULL ) goto V_15;
if ( ! F_8 ( V_10 , V_3 , V_1 -> V_16 ) ) goto V_15;
if ( F_9 ( V_10 ) )
{
if ( ! F_10 ( V_11 , & V_1 -> V_17 , V_1 -> V_16 , V_5 ) ) goto V_15;
}
else
{
if ( ! V_1 -> V_18 -> V_19 ( V_1 , V_9 , V_10 , V_5 ) ) goto V_15;
if ( ! V_1 -> V_18 -> V_20 ( V_1 , V_9 , & V_1 -> V_17 , V_9 , V_5 ) ) goto V_15;
if ( ! F_11 ( V_9 , & V_1 -> V_21 , V_9 ) ) goto V_15;
if ( ! F_11 ( V_9 , V_10 , V_9 ) ) goto V_15;
if ( ! F_12 ( V_12 , V_9 , V_1 -> V_16 , V_5 ) )
{
unsigned long V_15 = F_13 () ;
if ( F_14 ( V_15 ) == V_22 && F_15 ( V_15 ) == V_23 )
{
F_4 () ;
F_3 ( V_6 , V_24 ) ;
}
else
F_3 ( V_6 , V_25 ) ;
goto V_15;
}
V_14 = ( F_16 ( V_12 ) ) ? 1 : 0 ;
if ( ! V_1 -> V_18 -> V_26 ( V_1 , V_11 , V_10 , V_12 , V_5 ) ) goto V_15;
if ( V_14 != V_4 )
{
if ( ! F_11 ( V_11 , V_11 , V_10 ) ) goto V_15;
}
}
if ( ! F_17 ( V_1 , V_2 , V_10 , V_11 , V_5 ) ) goto V_15;
V_13 = 1 ;
V_15:
F_18 ( V_5 ) ;
if ( V_8 != NULL )
F_19 ( V_8 ) ;
return V_13 ;
#endif
}
