int F_1 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , T_2 * V_4 )
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
int V_10 = 0 ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
for (; ; )
{
if ( F_9 ( V_6 ) )
break;
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
V_10 ++ ;
}
}
}
if ( V_10 )
{
if ( ! F_13 ( V_5 , V_5 , V_10 ) ) goto V_9;
}
return ( V_5 ) ;
V_9:
return ( NULL ) ;
}
T_1 * F_14 ( T_1 * V_11 , T_1 * V_5 , const T_1 * V_12 , T_2 * V_4 )
{
T_1 * V_13 , * V_14 , * V_15 , * V_16 , * V_17 , * V_18 , * V_19 = NULL ;
T_1 * V_20 , * V_8 = NULL ;
int V_21 ;
F_2 ( V_5 ) ;
F_2 ( V_12 ) ;
F_3 ( V_4 ) ;
V_13 = F_4 ( V_4 ) ;
V_14 = F_4 ( V_4 ) ;
V_15 = F_4 ( V_4 ) ;
V_18 = F_4 ( V_4 ) ;
V_17 = F_4 ( V_4 ) ;
V_16 = F_4 ( V_4 ) ;
if ( V_16 == NULL ) goto V_9;
if ( V_11 == NULL )
V_19 = F_15 () ;
else
V_19 = V_11 ;
if ( V_19 == NULL ) goto V_9;
F_16 ( V_15 ) ;
F_17 ( V_16 ) ;
if ( F_5 ( V_13 , V_5 ) == NULL ) goto V_9;
if ( F_5 ( V_14 , V_12 ) == NULL ) goto V_9;
V_21 = 1 ;
while ( ! F_9 ( V_14 ) )
{
if ( ! F_18 ( V_18 , V_17 , V_13 , V_14 , V_4 ) ) goto V_9;
V_20 = V_13 ;
V_13 = V_14 ;
V_14 = V_17 ;
if ( ! F_19 ( V_20 , V_18 , V_15 , V_4 ) ) goto V_9;
if ( ! F_20 ( V_20 , V_20 , V_16 ) ) goto V_9;
V_17 = V_16 ;
V_16 = V_15 ;
V_15 = V_20 ;
V_21 = - V_21 ;
}
if ( V_21 < 0 )
{
if ( ! F_11 ( V_16 , V_12 , V_16 ) ) goto V_9;
}
if ( F_21 ( V_13 ) )
{ if ( ! F_22 ( V_19 , V_16 , V_12 , V_4 ) ) goto V_9; }
else
{
F_23 ( V_22 , V_23 ) ;
goto V_9;
}
V_8 = V_19 ;
V_9:
if ( ( V_8 == NULL ) && ( V_11 == NULL ) ) F_24 ( V_19 ) ;
F_8 ( V_4 ) ;
return ( V_8 ) ;
}
