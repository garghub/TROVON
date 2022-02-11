T_1 * F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
T_1 * V_5 = V_1 ;
int V_6 = 1 ;
int V_7 ;
T_1 * V_8 , * V_9 , * V_10 , * V_11 , * V_12 , * V_13 ;
int V_14 , V_15 , V_16 ;
if ( ! F_2 ( V_3 ) || F_3 ( V_3 , 1 ) )
{
if ( F_3 ( V_3 , 2 ) )
{
if ( V_5 == NULL )
V_5 = F_4 () ;
if ( V_5 == NULL )
goto V_17;
if ( ! F_5 ( V_5 , F_6 ( V_2 , 0 ) ) )
{
if ( V_5 != V_1 )
F_7 ( V_5 ) ;
return NULL ;
}
F_8 ( V_5 ) ;
return V_5 ;
}
F_9 ( V_18 , V_19 ) ;
return ( NULL ) ;
}
if ( F_10 ( V_2 ) || F_11 ( V_2 ) )
{
if ( V_5 == NULL )
V_5 = F_4 () ;
if ( V_5 == NULL )
goto V_17;
if ( ! F_5 ( V_5 , F_11 ( V_2 ) ) )
{
if ( V_5 != V_1 )
F_7 ( V_5 ) ;
return NULL ;
}
F_8 ( V_5 ) ;
return V_5 ;
}
F_12 ( V_4 ) ;
V_8 = F_13 ( V_4 ) ;
V_9 = F_13 ( V_4 ) ;
V_10 = F_13 ( V_4 ) ;
V_11 = F_13 ( V_4 ) ;
V_12 = F_13 ( V_4 ) ;
V_13 = F_13 ( V_4 ) ;
if ( V_13 == NULL ) goto V_17;
if ( V_5 == NULL )
V_5 = F_4 () ;
if ( V_5 == NULL ) goto V_17;
if ( ! F_14 ( V_8 , V_2 , V_3 , V_4 ) ) goto V_17;
V_14 = 1 ;
while ( ! F_6 ( V_3 , V_14 ) )
V_14 ++ ;
if ( V_14 == 1 )
{
if ( ! F_15 ( V_10 , V_3 , 2 ) ) goto V_17;
V_10 -> V_20 = 0 ;
if ( ! F_16 ( V_10 , 1 ) ) goto V_17;
if ( ! F_17 ( V_5 , V_8 , V_10 , V_3 , V_4 ) ) goto V_17;
V_6 = 0 ;
goto V_21;
}
if ( V_14 == 2 )
{
if ( ! F_18 ( V_11 , V_8 , V_3 ) ) goto V_17;
if ( ! F_15 ( V_10 , V_3 , 3 ) ) goto V_17;
V_10 -> V_20 = 0 ;
if ( ! F_17 ( V_9 , V_11 , V_10 , V_3 , V_4 ) ) goto V_17;
if ( ! F_19 ( V_13 , V_9 , V_3 , V_4 ) ) goto V_17;
if ( ! F_20 ( V_11 , V_11 , V_13 , V_3 , V_4 ) ) goto V_17;
if ( ! F_21 ( V_11 , 1 ) ) goto V_17;
if ( ! F_20 ( V_12 , V_8 , V_9 , V_3 , V_4 ) ) goto V_17;
if ( ! F_20 ( V_12 , V_12 , V_11 , V_3 , V_4 ) ) goto V_17;
if ( ! F_22 ( V_5 , V_12 ) ) goto V_17;
V_6 = 0 ;
goto V_21;
}
if ( ! F_22 ( V_10 , V_3 ) ) goto V_17;
V_10 -> V_20 = 0 ;
V_15 = 2 ;
do
{
if ( V_15 < 22 )
{
if ( ! F_5 ( V_13 , V_15 ) ) goto V_17;
}
else
{
if ( ! F_23 ( V_13 , F_24 ( V_3 ) , 0 , 0 ) ) goto V_17;
if ( F_25 ( V_13 , V_3 ) >= 0 )
{
if ( ! ( V_3 -> V_20 ? V_22 : V_23 ) ( V_13 , V_13 , V_3 ) ) goto V_17;
}
if ( F_10 ( V_13 ) )
if ( ! F_5 ( V_13 , V_15 ) ) goto V_17;
}
V_7 = F_26 ( V_13 , V_10 , V_4 ) ;
if ( V_7 < - 1 ) goto V_17;
if ( V_7 == 0 )
{
F_9 ( V_18 , V_19 ) ;
goto V_17;
}
}
while ( V_7 == 1 && ++ V_15 < 82 );
if ( V_7 != - 1 )
{
F_9 ( V_18 , V_24 ) ;
goto V_17;
}
if ( ! F_15 ( V_10 , V_10 , V_14 ) ) goto V_17;
if ( ! F_17 ( V_13 , V_13 , V_10 , V_3 , V_4 ) ) goto V_17;
if ( F_11 ( V_13 ) )
{
F_9 ( V_18 , V_19 ) ;
goto V_17;
}
if ( ! F_27 ( V_11 , V_10 ) ) goto V_17;
if ( F_10 ( V_11 ) )
{
if ( ! F_14 ( V_11 , V_8 , V_3 , V_4 ) ) goto V_17;
if ( F_10 ( V_11 ) )
{
F_28 ( V_5 ) ;
V_6 = 0 ;
goto V_17;
}
else
if ( ! F_29 ( V_12 ) ) goto V_17;
}
else
{
if ( ! F_17 ( V_12 , V_8 , V_11 , V_3 , V_4 ) ) goto V_17;
if ( F_10 ( V_12 ) )
{
F_28 ( V_5 ) ;
V_6 = 0 ;
goto V_17;
}
}
if ( ! F_19 ( V_9 , V_12 , V_3 , V_4 ) ) goto V_17;
if ( ! F_20 ( V_9 , V_9 , V_8 , V_3 , V_4 ) ) goto V_17;
if ( ! F_20 ( V_12 , V_12 , V_8 , V_3 , V_4 ) ) goto V_17;
while ( 1 )
{
if ( F_11 ( V_9 ) )
{
if ( ! F_22 ( V_5 , V_12 ) ) goto V_17;
V_6 = 0 ;
goto V_21;
}
V_15 = 1 ;
if ( ! F_19 ( V_11 , V_9 , V_3 , V_4 ) ) goto V_17;
while ( ! F_11 ( V_11 ) )
{
V_15 ++ ;
if ( V_15 == V_14 )
{
F_9 ( V_18 , V_25 ) ;
goto V_17;
}
if ( ! F_20 ( V_11 , V_11 , V_11 , V_3 , V_4 ) ) goto V_17;
}
if ( ! F_22 ( V_11 , V_13 ) ) goto V_17;
for ( V_16 = V_14 - V_15 - 1 ; V_16 > 0 ; V_16 -- )
{
if ( ! F_19 ( V_11 , V_11 , V_3 , V_4 ) ) goto V_17;
}
if ( ! F_20 ( V_13 , V_11 , V_11 , V_3 , V_4 ) ) goto V_17;
if ( ! F_20 ( V_12 , V_12 , V_11 , V_3 , V_4 ) ) goto V_17;
if ( ! F_20 ( V_9 , V_9 , V_13 , V_3 , V_4 ) ) goto V_17;
V_14 = V_15 ;
}
V_21:
if ( ! V_6 )
{
if ( ! F_19 ( V_12 , V_5 , V_3 , V_4 ) )
V_6 = 1 ;
if ( ! V_6 && 0 != F_30 ( V_12 , V_8 ) )
{
F_9 ( V_18 , V_25 ) ;
V_6 = 1 ;
}
}
V_17:
if ( V_6 )
{
if ( V_5 != NULL && V_5 != V_1 )
{
F_31 ( V_5 ) ;
}
V_5 = NULL ;
}
F_32 ( V_4 ) ;
F_8 ( V_5 ) ;
return V_5 ;
}
