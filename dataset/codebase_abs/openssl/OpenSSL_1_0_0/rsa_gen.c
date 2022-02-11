int F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 , T_3 * V_4 )
{
if( V_1 -> V_5 -> V_6 )
return V_1 -> V_5 -> V_6 ( V_1 , V_2 , V_3 , V_4 ) ;
return F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static int F_2 ( T_1 * V_1 , int V_2 , T_2 * V_3 , T_3 * V_4 )
{
T_2 * V_7 = NULL , * V_8 = NULL , * V_9 = NULL , * V_10 = NULL , * V_11 ;
T_2 V_12 , V_13 , V_14 ;
T_2 * V_15 , * V_16 , * V_17 ;
int V_18 , V_19 , V_20 = - 1 , V_21 = 0 ;
T_4 * V_22 = NULL ;
V_22 = F_3 () ;
if ( V_22 == NULL ) goto V_23;
F_4 ( V_22 ) ;
V_7 = F_5 ( V_22 ) ;
V_8 = F_5 ( V_22 ) ;
V_9 = F_5 ( V_22 ) ;
V_10 = F_5 ( V_22 ) ;
if ( V_10 == NULL ) goto V_23;
V_18 = ( V_2 + 1 ) / 2 ;
V_19 = V_2 - V_18 ;
if( ! V_1 -> V_21 && ( ( V_1 -> V_21 = F_6 () ) == NULL ) ) goto V_23;
if( ! V_1 -> V_16 && ( ( V_1 -> V_16 = F_6 () ) == NULL ) ) goto V_23;
if( ! V_1 -> V_24 && ( ( V_1 -> V_24 = F_6 () ) == NULL ) ) goto V_23;
if( ! V_1 -> V_17 && ( ( V_1 -> V_17 = F_6 () ) == NULL ) ) goto V_23;
if( ! V_1 -> V_25 && ( ( V_1 -> V_25 = F_6 () ) == NULL ) ) goto V_23;
if( ! V_1 -> V_26 && ( ( V_1 -> V_26 = F_6 () ) == NULL ) ) goto V_23;
if( ! V_1 -> V_27 && ( ( V_1 -> V_27 = F_6 () ) == NULL ) ) goto V_23;
if( ! V_1 -> V_28 && ( ( V_1 -> V_28 = F_6 () ) == NULL ) ) goto V_23;
F_7 ( V_1 -> V_24 , V_3 ) ;
for (; ; )
{
if( ! F_8 ( V_1 -> V_17 , V_18 , 0 , NULL , NULL , V_4 ) )
goto V_23;
if ( ! F_9 ( V_9 , V_1 -> V_17 , F_10 () ) ) goto V_23;
if ( ! F_11 ( V_8 , V_9 , V_1 -> V_24 , V_22 ) ) goto V_23;
if ( F_12 ( V_8 ) ) break;
if( ! F_13 ( V_4 , 2 , V_21 ++ ) )
goto V_23;
}
if( ! F_13 ( V_4 , 3 , 0 ) )
goto V_23;
for (; ; )
{
unsigned int V_29 = 0 ;
do
{
if( ! F_8 ( V_1 -> V_25 , V_19 , 0 , NULL , NULL , V_4 ) )
goto V_23;
} while( ( F_14 ( V_1 -> V_17 , V_1 -> V_25 ) == 0 ) && ( ++ V_29 < 3 ) );
if( V_29 == 3 )
{
V_20 = 0 ;
F_15 ( V_30 , V_31 ) ;
goto V_23;
}
if ( ! F_9 ( V_9 , V_1 -> V_25 , F_10 () ) ) goto V_23;
if ( ! F_11 ( V_8 , V_9 , V_1 -> V_24 , V_22 ) ) goto V_23;
if ( F_12 ( V_8 ) )
break;
if( ! F_13 ( V_4 , 2 , V_21 ++ ) )
goto V_23;
}
if( ! F_13 ( V_4 , 3 , 1 ) )
goto V_23;
if ( F_14 ( V_1 -> V_17 , V_1 -> V_25 ) < 0 )
{
V_11 = V_1 -> V_17 ;
V_1 -> V_17 = V_1 -> V_25 ;
V_1 -> V_25 = V_11 ;
}
if ( ! F_16 ( V_1 -> V_21 , V_1 -> V_17 , V_1 -> V_25 , V_22 ) ) goto V_23;
if ( ! F_9 ( V_8 , V_1 -> V_17 , F_10 () ) ) goto V_23;
if ( ! F_9 ( V_9 , V_1 -> V_25 , F_10 () ) ) goto V_23;
if ( ! F_16 ( V_7 , V_8 , V_9 , V_22 ) ) goto V_23;
if ( ! ( V_1 -> V_32 & V_33 ) )
{
V_15 = & V_12 ;
F_17 ( V_15 , V_7 , V_34 ) ;
}
else
V_15 = V_7 ;
if ( ! F_18 ( V_1 -> V_16 , V_1 -> V_24 , V_15 , V_22 ) ) goto V_23;
if ( ! ( V_1 -> V_32 & V_33 ) )
{
V_16 = & V_13 ;
F_17 ( V_16 , V_1 -> V_16 , V_34 ) ;
}
else
V_16 = V_1 -> V_16 ;
if ( ! F_19 ( V_1 -> V_26 , V_16 , V_8 , V_22 ) ) goto V_23;
if ( ! F_19 ( V_1 -> V_27 , V_16 , V_9 , V_22 ) ) goto V_23;
if ( ! ( V_1 -> V_32 & V_33 ) )
{
V_17 = & V_14 ;
F_17 ( V_17 , V_1 -> V_17 , V_34 ) ;
}
else
V_17 = V_1 -> V_17 ;
if ( ! F_18 ( V_1 -> V_28 , V_1 -> V_25 , V_17 , V_22 ) ) goto V_23;
V_20 = 1 ;
V_23:
if ( V_20 == - 1 )
{
F_15 ( V_30 , V_35 ) ;
V_20 = 0 ;
}
if ( V_22 != NULL )
{
F_20 ( V_22 ) ;
F_21 ( V_22 ) ;
}
return V_20 ;
}
