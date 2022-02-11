int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
T_1 * V_5 , * V_6 , * V_7 ;
int V_8 = 0 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
F_3 ( V_4 ) ;
V_5 = F_4 ( V_4 ) ;
V_6 = F_4 ( V_4 ) ;
if ( V_5 == NULL || V_6 == NULL ) goto V_9;
if ( F_5 ( V_5 , V_2 ) == NULL ) goto V_9;
if ( F_5 ( V_6 , V_3 ) == NULL ) goto V_9;
V_5 -> V_10 = 0 ;
V_6 -> V_10 = 0 ;
if ( F_6 ( V_5 , V_6 ) < 0 ) { V_7 = V_5 ; V_5 = V_6 ; V_6 = V_7 ; }
V_7 = F_7 ( V_5 , V_6 ) ;
if ( V_7 == NULL ) goto V_9;
if ( F_5 ( V_1 , V_7 ) == NULL ) goto V_9;
V_8 = 1 ;
V_9:
F_8 ( V_4 ) ;
return ( V_8 ) ;
}
static T_1 * F_7 ( T_1 * V_5 , T_1 * V_6 )
{
T_1 * V_7 ;
int V_11 = 0 ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
while ( ! F_9 ( V_6 ) )
{
if ( F_10 ( V_5 ) )
{
if ( F_10 ( V_6 ) )
{
if ( ! F_11 ( V_5 , V_5 , V_6 ) ) goto V_9;
if ( ! F_12 ( V_5 , V_5 ) ) goto V_9;
if ( F_6 ( V_5 , V_6 ) < 0 )
{ V_7 = V_5 ; V_5 = V_6 ; V_6 = V_7 ; }
}
else
{
if ( ! F_12 ( V_6 , V_6 ) ) goto V_9;
if ( F_6 ( V_5 , V_6 ) < 0 )
{ V_7 = V_5 ; V_5 = V_6 ; V_6 = V_7 ; }
}
}
else
{
if ( F_10 ( V_6 ) )
{
if ( ! F_12 ( V_5 , V_5 ) ) goto V_9;
if ( F_6 ( V_5 , V_6 ) < 0 )
{ V_7 = V_5 ; V_5 = V_6 ; V_6 = V_7 ; }
}
else
{
if ( ! F_12 ( V_5 , V_5 ) ) goto V_9;
if ( ! F_12 ( V_6 , V_6 ) ) goto V_9;
V_11 ++ ;
}
}
}
if ( V_11 )
{
if ( ! F_13 ( V_5 , V_5 , V_11 ) ) goto V_9;
}
return ( V_5 ) ;
V_9:
return ( NULL ) ;
}
T_1 * F_14 ( T_1 * V_12 ,
const T_1 * V_5 , const T_1 * V_13 , T_2 * V_4 )
{
T_1 * V_14 , * V_15 , * V_16 , * V_17 , * V_18 , * V_19 , * V_20 , * V_21 = NULL ;
T_1 * V_8 = NULL ;
int V_22 ;
F_2 ( V_5 ) ;
F_2 ( V_13 ) ;
F_3 ( V_4 ) ;
V_14 = F_4 ( V_4 ) ;
V_15 = F_4 ( V_4 ) ;
V_16 = F_4 ( V_4 ) ;
V_19 = F_4 ( V_4 ) ;
V_18 = F_4 ( V_4 ) ;
V_17 = F_4 ( V_4 ) ;
V_20 = F_4 ( V_4 ) ;
if ( V_20 == NULL ) goto V_9;
if ( V_12 == NULL )
V_21 = F_15 () ;
else
V_21 = V_12 ;
if ( V_21 == NULL ) goto V_9;
F_16 ( V_16 ) ;
F_17 ( V_17 ) ;
if ( F_5 ( V_15 , V_5 ) == NULL ) goto V_9;
if ( F_5 ( V_14 , V_13 ) == NULL ) goto V_9;
V_14 -> V_10 = 0 ;
if ( V_15 -> V_10 || ( F_18 ( V_15 , V_14 ) >= 0 ) )
{
if ( ! F_19 ( V_15 , V_15 , V_14 , V_4 ) ) goto V_9;
}
V_22 = - 1 ;
if ( F_10 ( V_13 ) && ( F_20 ( V_13 ) <= ( V_23 <= 32 ? 450 : 2048 ) ) )
{
int V_24 ;
while ( ! F_9 ( V_15 ) )
{
V_24 = 0 ;
while ( ! F_21 ( V_15 , V_24 ) )
{
V_24 ++ ;
if ( F_10 ( V_16 ) )
{
if ( ! F_22 ( V_16 , V_16 , V_13 ) ) goto V_9;
}
if ( ! F_12 ( V_16 , V_16 ) ) goto V_9;
}
if ( V_24 > 0 )
{
if ( ! F_23 ( V_15 , V_15 , V_24 ) ) goto V_9;
}
V_24 = 0 ;
while ( ! F_21 ( V_14 , V_24 ) )
{
V_24 ++ ;
if ( F_10 ( V_17 ) )
{
if ( ! F_22 ( V_17 , V_17 , V_13 ) ) goto V_9;
}
if ( ! F_12 ( V_17 , V_17 ) ) goto V_9;
}
if ( V_24 > 0 )
{
if ( ! F_23 ( V_14 , V_14 , V_24 ) ) goto V_9;
}
if ( F_18 ( V_15 , V_14 ) >= 0 )
{
if ( ! F_22 ( V_16 , V_16 , V_17 ) ) goto V_9;
if ( ! F_24 ( V_15 , V_15 , V_14 ) ) goto V_9;
}
else
{
if ( ! F_22 ( V_17 , V_17 , V_16 ) ) goto V_9;
if ( ! F_24 ( V_14 , V_14 , V_15 ) ) goto V_9;
}
}
}
else
{
while ( ! F_9 ( V_15 ) )
{
T_1 * V_25 ;
if ( F_20 ( V_14 ) == F_20 ( V_15 ) )
{
if ( ! F_16 ( V_19 ) ) goto V_9;
if ( ! F_11 ( V_18 , V_14 , V_15 ) ) goto V_9;
}
else if ( F_20 ( V_14 ) == F_20 ( V_15 ) + 1 )
{
if ( ! F_25 ( V_20 , V_15 ) ) goto V_9;
if ( F_18 ( V_14 , V_20 ) < 0 )
{
if ( ! F_16 ( V_19 ) ) goto V_9;
if ( ! F_11 ( V_18 , V_14 , V_15 ) ) goto V_9;
}
else
{
if ( ! F_11 ( V_18 , V_14 , V_20 ) ) goto V_9;
if ( ! F_26 ( V_19 , V_20 , V_15 ) ) goto V_9;
if ( F_18 ( V_14 , V_19 ) < 0 )
{
if ( ! F_27 ( V_19 , 2 ) ) goto V_9;
}
else
{
if ( ! F_27 ( V_19 , 3 ) ) goto V_9;
if ( ! F_11 ( V_18 , V_18 , V_15 ) ) goto V_9;
}
}
}
else
{
if ( ! F_28 ( V_19 , V_18 , V_14 , V_15 , V_4 ) ) goto V_9;
}
V_25 = V_14 ;
V_14 = V_15 ;
V_15 = V_18 ;
if ( F_29 ( V_19 ) )
{
if ( ! F_26 ( V_25 , V_16 , V_17 ) ) goto V_9;
}
else
{
if ( F_30 ( V_19 , 2 ) )
{
if ( ! F_25 ( V_25 , V_16 ) ) goto V_9;
}
else if ( F_30 ( V_19 , 4 ) )
{
if ( ! F_13 ( V_25 , V_16 , 2 ) ) goto V_9;
}
else if ( V_19 -> V_26 == 1 )
{
if ( ! F_5 ( V_25 , V_16 ) ) goto V_9;
if ( ! F_31 ( V_25 , V_19 -> V_27 [ 0 ] ) ) goto V_9;
}
else
{
if ( ! F_32 ( V_25 , V_19 , V_16 , V_4 ) ) goto V_9;
}
if ( ! F_26 ( V_25 , V_25 , V_17 ) ) goto V_9;
}
V_18 = V_17 ;
V_17 = V_16 ;
V_16 = V_25 ;
V_22 = - V_22 ;
}
}
if ( V_22 < 0 )
{
if ( ! F_11 ( V_17 , V_13 , V_17 ) ) goto V_9;
}
if ( F_29 ( V_14 ) )
{
if ( ! V_17 -> V_10 && F_18 ( V_17 , V_13 ) < 0 )
{
if ( ! F_5 ( V_21 , V_17 ) ) goto V_9;
}
else
{
if ( ! F_19 ( V_21 , V_17 , V_13 , V_4 ) ) goto V_9;
}
}
else
{
F_33 ( V_28 , V_29 ) ;
goto V_9;
}
V_8 = V_21 ;
V_9:
if ( ( V_8 == NULL ) && ( V_12 == NULL ) ) F_34 ( V_21 ) ;
F_8 ( V_4 ) ;
return ( V_8 ) ;
}
