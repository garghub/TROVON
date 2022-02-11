int F_1 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , T_2 * V_4 )
{
T_1 * V_5 , * V_6 , * V_7 ;
int V_8 = 0 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
V_5 = & ( V_4 -> V_9 [ V_4 -> V_10 ] ) ;
V_6 = & ( V_4 -> V_9 [ V_4 -> V_10 + 1 ] ) ;
if ( F_3 ( V_5 , V_2 ) == NULL ) goto V_11;
if ( F_3 ( V_6 , V_3 ) == NULL ) goto V_11;
if ( F_4 ( V_5 , V_6 ) < 0 ) { V_7 = V_5 ; V_5 = V_6 ; V_6 = V_7 ; }
V_7 = F_5 ( V_5 , V_6 ) ;
if ( V_7 == NULL ) goto V_11;
if ( F_3 ( V_1 , V_7 ) == NULL ) goto V_11;
V_8 = 1 ;
V_11:
return ( V_8 ) ;
}
static T_1 * F_5 ( T_1 * V_5 , T_1 * V_6 )
{
T_1 * V_7 ;
int V_12 = 0 ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
for (; ; )
{
if ( F_6 ( V_6 ) )
break;
if ( F_7 ( V_5 ) )
{
if ( F_7 ( V_6 ) )
{
if ( ! F_8 ( V_5 , V_5 , V_6 ) ) goto V_11;
if ( ! F_9 ( V_5 , V_5 ) ) goto V_11;
if ( F_4 ( V_5 , V_6 ) < 0 )
{ V_7 = V_5 ; V_5 = V_6 ; V_6 = V_7 ; }
}
else
{
if ( ! F_9 ( V_6 , V_6 ) ) goto V_11;
if ( F_4 ( V_5 , V_6 ) < 0 )
{ V_7 = V_5 ; V_5 = V_6 ; V_6 = V_7 ; }
}
}
else
{
if ( F_7 ( V_6 ) )
{
if ( ! F_9 ( V_5 , V_5 ) ) goto V_11;
if ( F_4 ( V_5 , V_6 ) < 0 )
{ V_7 = V_5 ; V_5 = V_6 ; V_6 = V_7 ; }
}
else
{
if ( ! F_9 ( V_5 , V_5 ) ) goto V_11;
if ( ! F_9 ( V_6 , V_6 ) ) goto V_11;
V_12 ++ ;
}
}
}
if ( V_12 )
{
if ( ! F_10 ( V_5 , V_5 , V_12 ) ) goto V_11;
}
return ( V_5 ) ;
V_11:
return ( NULL ) ;
}
T_1 * F_11 ( T_1 * V_13 , T_1 * V_5 , T_1 * V_14 , T_2 * V_4 )
{
T_1 * V_15 , * V_16 , * V_17 , * V_18 , * V_19 , * V_20 , * V_21 ;
T_1 * V_22 , * V_8 = NULL ;
int V_23 ;
F_2 ( V_5 ) ;
F_2 ( V_14 ) ;
V_15 = & ( V_4 -> V_9 [ V_4 -> V_10 ] ) ;
V_16 = & ( V_4 -> V_9 [ V_4 -> V_10 + 1 ] ) ;
V_17 = & ( V_4 -> V_9 [ V_4 -> V_10 + 2 ] ) ;
V_20 = & ( V_4 -> V_9 [ V_4 -> V_10 + 3 ] ) ;
V_19 = & ( V_4 -> V_9 [ V_4 -> V_10 + 4 ] ) ;
V_18 = & ( V_4 -> V_9 [ V_4 -> V_10 + 5 ] ) ;
V_4 -> V_10 += 6 ;
if ( V_13 == NULL )
V_21 = F_12 () ;
else
V_21 = V_13 ;
if ( V_21 == NULL ) goto V_11;
F_13 ( V_17 ) ;
F_14 ( V_18 ) ;
if ( F_3 ( V_15 , V_5 ) == NULL ) goto V_11;
if ( F_3 ( V_16 , V_14 ) == NULL ) goto V_11;
V_23 = 1 ;
while ( ! F_6 ( V_16 ) )
{
if ( ! F_15 ( V_20 , V_19 , V_15 , V_16 , V_4 ) ) goto V_11;
V_22 = V_15 ;
V_15 = V_16 ;
V_16 = V_19 ;
if ( ! F_16 ( V_22 , V_20 , V_17 , V_4 ) ) goto V_11;
if ( ! F_17 ( V_22 , V_22 , V_18 ) ) goto V_11;
V_19 = V_18 ;
V_18 = V_17 ;
V_17 = V_22 ;
V_23 = - V_23 ;
}
if ( V_23 < 0 )
{
if ( ! F_8 ( V_18 , V_14 , V_18 ) ) goto V_11;
}
if ( F_18 ( V_15 ) )
{ if ( ! F_19 ( V_21 , V_18 , V_14 , V_4 ) ) goto V_11; }
else
{
F_20 ( V_24 , V_25 ) ;
goto V_11;
}
V_8 = V_21 ;
V_11:
if ( ( V_8 == NULL ) && ( V_13 == NULL ) ) F_21 ( V_21 ) ;
V_4 -> V_10 -= 6 ;
return ( V_8 ) ;
}
