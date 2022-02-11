static T_1 * F_1 ( const T_2 * V_1 )
{
T_1 * V_2 = NULL ;
T_3 * V_3 = NULL ;
T_4 * V_4 = NULL ;
T_5 * V_5 = NULL , * V_6 = NULL , * V_7 = NULL , * V_8 = NULL , * V_9 = NULL , * V_10 = NULL ;
int V_11 = 0 ;
if ( ( V_4 = F_2 () ) == NULL )
{
F_3 ( V_12 , V_13 ) ;
goto V_14;
}
if ( ( V_5 = F_4 () ) == NULL || ( V_6 = F_4 () ) == NULL ||
( V_7 = F_4 () ) == NULL || ( V_8 = F_4 () ) == NULL ||
( V_9 = F_4 () ) == NULL || ( V_10 = F_4 () ) == NULL )
{
F_3 ( V_12 , V_13 ) ;
goto V_14;
}
if ( ! F_5 ( & V_5 , V_1 -> V_5 ) || ! F_5 ( & V_6 , V_1 -> V_6 )
|| ! F_5 ( & V_7 , V_1 -> V_7 ) )
{
F_3 ( V_12 , V_15 ) ;
goto V_14;
}
if ( V_1 -> V_16 == V_17 )
{
if ( ( V_2 = F_6 ( V_5 , V_6 , V_7 , V_4 ) ) == NULL )
{
F_3 ( V_12 , V_18 ) ;
goto V_14;
}
}
else
{
if ( ( V_2 = F_7 ( V_5 , V_6 , V_7 , V_4 ) ) == NULL )
{
F_3 ( V_12 , V_18 ) ;
goto V_14;
}
}
if ( ( V_3 = F_8 ( V_2 ) ) == NULL )
{
F_3 ( V_12 , V_18 ) ;
goto V_14;
}
if ( ! F_5 ( & V_8 , V_1 -> V_8 ) || ! F_5 ( & V_9 , V_1 -> V_9 ) )
{
F_3 ( V_12 , V_15 ) ;
goto V_14;
}
if ( ! F_9 ( V_2 , V_3 , V_8 , V_9 , V_4 ) )
{
F_3 ( V_12 , V_18 ) ;
goto V_14;
}
if ( ! F_5 ( & V_10 , V_1 -> V_10 ) || ! F_10 ( V_8 , V_1 -> V_19 ) )
{
F_3 ( V_12 , V_15 ) ;
goto V_14;
}
if ( ! F_11 ( V_2 , V_3 , V_10 , V_8 ) )
{
F_3 ( V_12 , V_18 ) ;
goto V_14;
}
if ( V_1 -> V_20 )
{
if ( ! F_12 ( V_2 , V_1 -> V_20 , V_1 -> V_21 ) )
{
F_3 ( V_12 , V_18 ) ;
goto V_14;
}
}
V_11 = 1 ;
V_14:
if ( ! V_11 )
{
F_13 ( V_2 ) ;
V_2 = NULL ;
}
if ( V_3 )
F_14 ( V_3 ) ;
if ( V_4 )
F_15 ( V_4 ) ;
if ( V_5 )
F_16 ( V_5 ) ;
if ( V_6 )
F_16 ( V_6 ) ;
if ( V_7 )
F_16 ( V_7 ) ;
if ( V_10 )
F_16 ( V_10 ) ;
if ( V_8 )
F_16 ( V_8 ) ;
if ( V_9 )
F_16 ( V_9 ) ;
return V_2 ;
}
T_1 * F_17 ( int V_22 )
{
T_6 V_23 ;
T_1 * V_24 = NULL ;
if ( V_22 <= 0 )
return NULL ;
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ )
if ( V_26 [ V_23 ] . V_22 == V_22 )
{
V_24 = F_1 ( V_26 [ V_23 ] . V_1 ) ;
break;
}
if ( V_24 == NULL )
{
F_3 ( V_27 , V_28 ) ;
return NULL ;
}
F_18 ( V_24 , V_22 ) ;
return V_24 ;
}
T_6 F_19 ( T_7 * V_29 , T_6 V_30 )
{
T_6 V_23 , V_31 ;
if ( V_29 == NULL || V_30 == 0 )
return V_25 ;
V_31 = V_30 < V_25 ? V_30 : V_25 ;
for ( V_23 = 0 ; V_23 < V_31 ; V_23 ++ )
{
V_29 [ V_23 ] . V_22 = V_26 [ V_23 ] . V_22 ;
V_29 [ V_23 ] . V_32 = V_26 [ V_23 ] . V_1 -> V_32 ;
}
return V_25 ;
}
