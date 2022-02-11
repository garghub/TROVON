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
int V_14 = 0 ;
F_3 ( & V_8 ) ;
F_3 ( & V_9 ) ;
if ( ! V_4 -> V_15 || ! V_4 -> V_16 || ! V_4 -> V_17 ) {
V_11 = V_18 ;
goto V_19;
}
V_7 = F_4 () ;
if ( V_7 == NULL )
goto V_19;
V_10 = F_5 () ;
if ( V_10 == NULL )
goto V_19;
V_20:
if ( ( V_4 -> V_5 == NULL ) || ( V_4 -> V_6 == NULL ) ) {
if ( ! F_6 ( V_4 , V_10 , & V_5 , & V_6 ) )
goto V_19;
} else {
V_5 = V_4 -> V_5 ;
V_4 -> V_5 = NULL ;
V_6 = V_4 -> V_6 ;
V_4 -> V_6 = NULL ;
V_14 = 1 ;
}
if ( V_3 > F_7 ( V_4 -> V_16 ) )
V_3 = F_7 ( V_4 -> V_16 ) ;
if ( F_8 ( V_2 , V_3 , & V_8 ) == NULL )
goto V_19;
if ( ! F_9 ( & V_9 , V_4 -> V_21 , V_6 , V_4 -> V_16 , V_10 ) )
goto V_19;
if ( ! F_10 ( V_7 , & V_9 , & V_8 ) )
goto V_19;
if ( F_11 ( V_7 , V_4 -> V_16 ) > 0 )
if ( ! F_12 ( V_7 , V_7 , V_4 -> V_16 ) )
goto V_19;
if ( ! F_9 ( V_7 , V_7 , V_5 , V_4 -> V_16 , V_10 ) )
goto V_19;
V_13 = F_13 () ;
if ( V_13 == NULL )
goto V_19;
if ( F_14 ( V_6 ) || F_14 ( V_7 ) ) {
if ( V_14 ) {
V_11 = V_22 ;
goto V_19;
}
goto V_20;
}
V_13 -> V_6 = V_6 ;
V_13 -> V_7 = V_7 ;
V_19:
if ( ! V_13 ) {
F_15 ( V_23 , V_11 ) ;
F_16 ( V_6 ) ;
F_16 ( V_7 ) ;
}
if ( V_10 != NULL )
F_17 ( V_10 ) ;
F_18 ( & V_8 ) ;
F_18 ( & V_9 ) ;
if ( V_5 != NULL )
F_18 ( V_5 ) ;
return ( V_13 ) ;
}
static int F_19 ( T_3 * V_4 , T_5 * V_24 , T_4 * * V_25 ,
T_4 * * V_26 )
{
T_5 * V_10 ;
T_4 V_27 , V_28 , * V_29 , * V_5 = NULL , * V_6 = NULL ;
int V_13 = 0 ;
if ( ! V_4 -> V_15 || ! V_4 -> V_16 || ! V_4 -> V_17 ) {
F_15 ( V_30 , V_18 ) ;
return 0 ;
}
F_3 ( & V_27 ) ;
F_3 ( & V_28 ) ;
if ( V_24 == NULL ) {
if ( ( V_10 = F_5 () ) == NULL )
goto V_19;
} else
V_10 = V_24 ;
if ( ( V_6 = F_4 () ) == NULL )
goto V_19;
do
if ( ! F_20 ( & V_27 , V_4 -> V_16 ) )
goto V_19;
while ( F_14 ( & V_27 ) ) ;
if ( ( V_4 -> V_31 & V_32 ) == 0 ) {
F_21 ( & V_27 , V_33 ) ;
}
if ( V_4 -> V_31 & V_34 ) {
if ( ! F_22 ( & V_4 -> V_35 ,
V_36 , V_4 -> V_15 , V_10 ) )
goto V_19;
}
if ( ( V_4 -> V_31 & V_32 ) == 0 ) {
if ( ! F_23 ( & V_28 , & V_27 ) )
goto V_19;
if ( ! F_10 ( & V_28 , & V_28 , V_4 -> V_16 ) )
goto V_19;
if ( F_24 ( & V_28 ) <= F_24 ( V_4 -> V_16 ) ) {
if ( ! F_10 ( & V_28 , & V_28 , V_4 -> V_16 ) )
goto V_19;
}
V_29 = & V_28 ;
} else {
V_29 = & V_27 ;
}
F_25 (goto err, dsa, r, dsa->g, K, dsa->p, ctx,
dsa->method_mont_p) ;
if ( ! F_26 ( V_6 , V_6 , V_4 -> V_16 , V_10 ) )
goto V_19;
if ( ( V_5 = F_27 ( NULL , & V_27 , V_4 -> V_16 , V_10 ) ) == NULL )
goto V_19;
if ( * V_25 != NULL )
F_18 ( * V_25 ) ;
* V_25 = V_5 ;
V_5 = NULL ;
if ( * V_26 != NULL )
F_18 ( * V_26 ) ;
* V_26 = V_6 ;
V_13 = 1 ;
V_19:
if ( ! V_13 ) {
F_15 ( V_30 , V_12 ) ;
if ( V_6 != NULL )
F_18 ( V_6 ) ;
}
if ( V_24 == NULL )
F_17 ( V_10 ) ;
F_18 ( & V_27 ) ;
F_18 ( & V_28 ) ;
return ( V_13 ) ;
}
static int F_28 ( const unsigned char * V_2 , int V_37 ,
T_2 * V_38 , T_3 * V_4 )
{
T_5 * V_10 ;
T_4 V_39 , V_40 , V_41 ;
T_6 * V_42 = NULL ;
int V_13 = - 1 , V_43 ;
if ( ! V_4 -> V_15 || ! V_4 -> V_16 || ! V_4 -> V_17 ) {
F_15 ( V_44 , V_18 ) ;
return - 1 ;
}
V_43 = F_24 ( V_4 -> V_16 ) ;
if ( V_43 != 160 && V_43 != 224 && V_43 != 256 ) {
F_15 ( V_44 , V_45 ) ;
return - 1 ;
}
if ( F_24 ( V_4 -> V_15 ) > V_46 ) {
F_15 ( V_44 , V_47 ) ;
return - 1 ;
}
F_3 ( & V_39 ) ;
F_3 ( & V_40 ) ;
F_3 ( & V_41 ) ;
if ( ( V_10 = F_5 () ) == NULL )
goto V_19;
if ( F_14 ( V_38 -> V_6 ) || F_29 ( V_38 -> V_6 ) ||
F_30 ( V_38 -> V_6 , V_4 -> V_16 ) >= 0 ) {
V_13 = 0 ;
goto V_19;
}
if ( F_14 ( V_38 -> V_7 ) || F_29 ( V_38 -> V_7 ) ||
F_30 ( V_38 -> V_7 , V_4 -> V_16 ) >= 0 ) {
V_13 = 0 ;
goto V_19;
}
if ( ( F_27 ( & V_40 , V_38 -> V_7 , V_4 -> V_16 , V_10 ) ) == NULL )
goto V_19;
if ( V_37 > ( V_43 >> 3 ) )
V_37 = ( V_43 >> 3 ) ;
if ( F_8 ( V_2 , V_37 , & V_39 ) == NULL )
goto V_19;
if ( ! F_9 ( & V_39 , & V_39 , & V_40 , V_4 -> V_16 , V_10 ) )
goto V_19;
if ( ! F_9 ( & V_40 , V_38 -> V_6 , & V_40 , V_4 -> V_16 , V_10 ) )
goto V_19;
if ( V_4 -> V_31 & V_34 ) {
V_42 = F_22 ( & V_4 -> V_35 ,
V_36 , V_4 -> V_15 , V_10 ) ;
if ( ! V_42 )
goto V_19;
}
F_31 (goto err, dsa, &t1, dsa->g, &u1, dsa->pub_key, &u2, dsa->p,
ctx, mont) ;
if ( ! F_26 ( & V_39 , & V_41 , V_4 -> V_16 , V_10 ) )
goto V_19;
V_13 = ( F_30 ( & V_39 , V_38 -> V_6 ) == 0 ) ;
V_19:
if ( V_13 < 0 )
F_15 ( V_44 , V_12 ) ;
if ( V_10 != NULL )
F_17 ( V_10 ) ;
F_16 ( & V_39 ) ;
F_16 ( & V_40 ) ;
F_16 ( & V_41 ) ;
return ( V_13 ) ;
}
static int F_32 ( T_3 * V_4 )
{
V_4 -> V_31 |= V_34 ;
return ( 1 ) ;
}
static int F_33 ( T_3 * V_4 )
{
if ( V_4 -> V_35 )
F_34 ( V_4 -> V_35 ) ;
return ( 1 ) ;
}
