const T_1 * F_1 ( void )
{
return & V_1 ;
}
static T_2 * F_2 ( const unsigned char * V_2 , int V_3 , T_3 * V_4 )
{
T_4 * V_5 = NULL , * V_6 = NULL , * V_7 = NULL ;
T_4 V_8 ;
T_4 V_9 ;
T_5 * V_10 = NULL ;
int V_11 = V_12 ;
T_2 * V_13 = NULL ;
F_3 ( & V_8 ) ;
F_3 ( & V_9 ) ;
if ( ! V_4 -> V_14 || ! V_4 -> V_15 || ! V_4 -> V_16 )
{
V_11 = V_17 ;
goto V_18;
}
V_7 = F_4 () ;
if ( V_7 == NULL ) goto V_18;
if ( V_3 > V_19 )
{
V_11 = V_20 ;
goto V_18;
}
V_10 = F_5 () ;
if ( V_10 == NULL ) goto V_18;
if ( ( V_4 -> V_5 == NULL ) || ( V_4 -> V_6 == NULL ) )
{
if ( ! F_6 ( V_4 , V_10 , & V_5 , & V_6 ) ) goto V_18;
}
else
{
V_5 = V_4 -> V_5 ;
V_4 -> V_5 = NULL ;
V_6 = V_4 -> V_6 ;
V_4 -> V_6 = NULL ;
}
if ( V_3 > F_7 ( V_4 -> V_15 ) )
V_3 = F_7 ( V_4 -> V_15 ) ;
if ( F_8 ( V_2 , V_3 , & V_8 ) == NULL )
goto V_18;
if ( ! F_9 ( & V_9 , V_4 -> V_21 , V_6 , V_4 -> V_15 , V_10 ) ) goto V_18;
if ( ! F_10 ( V_7 , & V_9 , & V_8 ) ) goto V_18;
if ( F_11 ( V_7 , V_4 -> V_15 ) > 0 )
F_12 ( V_7 , V_7 , V_4 -> V_15 ) ;
if ( ! F_9 ( V_7 , V_7 , V_5 , V_4 -> V_15 , V_10 ) ) goto V_18;
V_13 = F_13 () ;
if ( V_13 == NULL ) goto V_18;
V_13 -> V_6 = V_6 ;
V_13 -> V_7 = V_7 ;
V_18:
if ( ! V_13 )
{
F_14 ( V_22 , V_11 ) ;
F_15 ( V_6 ) ;
F_15 ( V_7 ) ;
}
if ( V_10 != NULL ) F_16 ( V_10 ) ;
F_17 ( & V_8 ) ;
F_17 ( & V_9 ) ;
if ( V_5 != NULL )
F_17 ( V_5 ) ;
return ( V_13 ) ;
}
static int F_18 ( T_3 * V_4 , T_5 * V_23 , T_4 * * V_24 , T_4 * * V_25 )
{
T_5 * V_10 ;
T_4 V_26 , V_27 , * V_28 , * V_5 = NULL , * V_6 = NULL ;
int V_13 = 0 ;
if ( ! V_4 -> V_14 || ! V_4 -> V_15 || ! V_4 -> V_16 )
{
F_14 ( V_29 , V_17 ) ;
return 0 ;
}
F_3 ( & V_26 ) ;
F_3 ( & V_27 ) ;
if ( V_23 == NULL )
{
if ( ( V_10 = F_5 () ) == NULL ) goto V_18;
}
else
V_10 = V_23 ;
if ( ( V_6 = F_4 () ) == NULL ) goto V_18;
do
if ( ! F_19 ( & V_26 , V_4 -> V_15 ) ) goto V_18;
while ( F_20 ( & V_26 ) );
if ( ( V_4 -> V_30 & V_31 ) == 0 )
{
F_21 ( & V_26 , V_32 ) ;
}
if ( V_4 -> V_30 & V_33 )
{
if ( ! F_22 ( & V_4 -> V_34 ,
V_35 ,
V_4 -> V_14 , V_10 ) )
goto V_18;
}
if ( ( V_4 -> V_30 & V_31 ) == 0 )
{
if ( ! F_23 ( & V_27 , & V_26 ) ) goto V_18;
if ( ! F_10 ( & V_27 , & V_27 , V_4 -> V_15 ) ) goto V_18;
if ( F_24 ( & V_27 ) <= F_24 ( V_4 -> V_15 ) )
{
if ( ! F_10 ( & V_27 , & V_27 , V_4 -> V_15 ) ) goto V_18;
}
V_28 = & V_27 ;
}
else
{
V_28 = & V_26 ;
}
F_25 (goto err, dsa, r, dsa->g, K, dsa->p, ctx,
dsa->method_mont_p) ;
if ( ! F_26 ( V_6 , V_6 , V_4 -> V_15 , V_10 ) ) goto V_18;
if ( ( V_5 = F_27 ( NULL , & V_26 , V_4 -> V_15 , V_10 ) ) == NULL ) goto V_18;
if ( * V_24 != NULL ) F_17 ( * V_24 ) ;
* V_24 = V_5 ;
V_5 = NULL ;
if ( * V_25 != NULL ) F_17 ( * V_25 ) ;
* V_25 = V_6 ;
V_13 = 1 ;
V_18:
if ( ! V_13 )
{
F_14 ( V_29 , V_12 ) ;
if ( V_6 != NULL )
F_17 ( V_6 ) ;
}
if ( V_23 == NULL ) F_16 ( V_10 ) ;
F_17 ( & V_26 ) ;
F_17 ( & V_27 ) ;
return ( V_13 ) ;
}
static int F_28 ( const unsigned char * V_2 , int V_36 , T_2 * V_37 ,
T_3 * V_4 )
{
T_5 * V_10 ;
T_4 V_38 , V_39 , V_40 ;
T_6 * V_41 = NULL ;
int V_13 = - 1 , V_42 ;
if ( ! V_4 -> V_14 || ! V_4 -> V_15 || ! V_4 -> V_16 )
{
F_14 ( V_43 , V_17 ) ;
return - 1 ;
}
V_42 = F_24 ( V_4 -> V_15 ) ;
if ( V_42 != 160 && V_42 != 224 && V_42 != 256 )
{
F_14 ( V_43 , V_44 ) ;
return - 1 ;
}
if ( F_24 ( V_4 -> V_14 ) > V_45 )
{
F_14 ( V_43 , V_46 ) ;
return - 1 ;
}
if ( V_36 > V_19 )
{
F_14 ( V_43 , V_20 ) ;
return - 1 ;
}
F_3 ( & V_38 ) ;
F_3 ( & V_39 ) ;
F_3 ( & V_40 ) ;
if ( ( V_10 = F_5 () ) == NULL ) goto V_18;
if ( F_20 ( V_37 -> V_6 ) || F_29 ( V_37 -> V_6 ) ||
F_30 ( V_37 -> V_6 , V_4 -> V_15 ) >= 0 )
{
V_13 = 0 ;
goto V_18;
}
if ( F_20 ( V_37 -> V_7 ) || F_29 ( V_37 -> V_7 ) ||
F_30 ( V_37 -> V_7 , V_4 -> V_15 ) >= 0 )
{
V_13 = 0 ;
goto V_18;
}
if ( ( F_27 ( & V_39 , V_37 -> V_7 , V_4 -> V_15 , V_10 ) ) == NULL ) goto V_18;
if ( V_36 > ( V_42 >> 3 ) )
V_36 = ( V_42 >> 3 ) ;
if ( F_8 ( V_2 , V_36 , & V_38 ) == NULL ) goto V_18;
if ( ! F_9 ( & V_38 , & V_38 , & V_39 , V_4 -> V_15 , V_10 ) ) goto V_18;
if ( ! F_9 ( & V_39 , V_37 -> V_6 , & V_39 , V_4 -> V_15 , V_10 ) ) goto V_18;
if ( V_4 -> V_30 & V_33 )
{
V_41 = F_22 ( & V_4 -> V_34 ,
V_35 , V_4 -> V_14 , V_10 ) ;
if ( ! V_41 )
goto V_18;
}
F_31 (goto err, dsa, &t1, dsa->g, &u1, dsa->pub_key, &u2, dsa->p, ctx, mont) ;
if ( ! F_26 ( & V_38 , & V_40 , V_4 -> V_15 , V_10 ) ) goto V_18;
V_13 = ( F_30 ( & V_38 , V_37 -> V_6 ) == 0 ) ;
V_18:
if ( V_13 != 1 ) F_14 ( V_43 , V_12 ) ;
if ( V_10 != NULL ) F_16 ( V_10 ) ;
F_15 ( & V_38 ) ;
F_15 ( & V_39 ) ;
F_15 ( & V_40 ) ;
return ( V_13 ) ;
}
static int F_32 ( T_3 * V_4 )
{
V_4 -> V_30 |= V_33 ;
return ( 1 ) ;
}
static int F_33 ( T_3 * V_4 )
{
if( V_4 -> V_34 )
F_34 ( V_4 -> V_34 ) ;
return ( 1 ) ;
}
