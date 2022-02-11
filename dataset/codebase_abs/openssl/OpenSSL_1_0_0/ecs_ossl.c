const T_1 * F_1 ( void )
{
return & V_1 ;
}
static int F_2 ( T_2 * V_2 , T_3 * V_3 , T_4 * * V_4 ,
T_4 * * V_5 )
{
T_3 * V_6 = NULL ;
T_4 * V_7 = NULL , * V_8 = NULL , * V_9 = NULL , * V_10 = NULL ;
T_5 * V_11 = NULL ;
const T_6 * V_12 ;
int V_13 = 0 ;
if ( V_2 == NULL || ( V_12 = F_3 ( V_2 ) ) == NULL )
{
F_4 ( V_14 , V_15 ) ;
return 0 ;
}
if ( V_3 == NULL )
{
if ( ( V_6 = F_5 () ) == NULL )
{
F_4 ( V_14 , V_16 ) ;
return 0 ;
}
}
else
V_6 = V_3 ;
V_7 = F_6 () ;
V_8 = F_6 () ;
V_9 = F_6 () ;
V_10 = F_6 () ;
if ( ! V_7 || ! V_8 || ! V_9 || ! V_10 )
{
F_4 ( V_14 , V_16 ) ;
goto V_17;
}
if ( ( V_11 = F_7 ( V_12 ) ) == NULL )
{
F_4 ( V_14 , V_18 ) ;
goto V_17;
}
if ( ! F_8 ( V_12 , V_9 , V_6 ) )
{
F_4 ( V_14 , V_18 ) ;
goto V_17;
}
do
{
do
if ( ! F_9 ( V_7 , V_9 ) )
{
F_4 ( V_14 ,
V_19 ) ;
goto V_17;
}
while ( F_10 ( V_7 ) );
if ( ! F_11 ( V_12 , V_11 , V_7 , NULL , NULL , V_6 ) )
{
F_4 ( V_14 , V_18 ) ;
goto V_17;
}
if ( F_12 ( F_13 ( V_12 ) ) == V_20 )
{
if ( ! F_14 ( V_12 ,
V_11 , V_10 , NULL , V_6 ) )
{
F_4 ( V_14 , V_18 ) ;
goto V_17;
}
}
else
{
if ( ! F_15 ( V_12 ,
V_11 , V_10 , NULL , V_6 ) )
{
F_4 ( V_14 , V_18 ) ;
goto V_17;
}
}
if ( ! F_16 ( V_8 , V_10 , V_9 , V_6 ) )
{
F_4 ( V_14 , V_21 ) ;
goto V_17;
}
}
while ( F_10 ( V_8 ) );
if ( ! F_17 ( V_7 , V_7 , V_9 , V_6 ) )
{
F_4 ( V_14 , V_21 ) ;
goto V_17;
}
if ( * V_5 != NULL )
F_18 ( * V_5 ) ;
if ( * V_4 != NULL )
F_18 ( * V_4 ) ;
* V_5 = V_8 ;
* V_4 = V_7 ;
V_13 = 1 ;
V_17:
if ( ! V_13 )
{
if ( V_7 != NULL ) F_18 ( V_7 ) ;
if ( V_8 != NULL ) F_18 ( V_8 ) ;
}
if ( V_3 == NULL )
F_19 ( V_6 ) ;
if ( V_9 != NULL )
F_20 ( V_9 ) ;
if ( V_11 != NULL )
F_21 ( V_11 ) ;
if ( V_10 )
F_18 ( V_10 ) ;
return ( V_13 ) ;
}
static T_7 * F_22 ( const unsigned char * V_22 , int V_23 ,
const T_4 * V_24 , const T_4 * V_25 , T_2 * V_2 )
{
int V_26 = 0 , V_27 ;
T_4 * V_28 = NULL , * V_29 , * V_30 = NULL , * V_31 = NULL , * V_9 = NULL ;
const T_4 * V_32 ;
T_3 * V_6 = NULL ;
const T_6 * V_12 ;
T_7 * V_13 ;
T_8 * V_33 ;
const T_4 * V_34 ;
V_33 = F_23 ( V_2 ) ;
V_12 = F_3 ( V_2 ) ;
V_34 = F_24 ( V_2 ) ;
if ( V_12 == NULL || V_34 == NULL || V_33 == NULL )
{
F_4 ( V_35 , V_15 ) ;
return NULL ;
}
V_13 = F_25 () ;
if ( ! V_13 )
{
F_4 ( V_35 , V_16 ) ;
return NULL ;
}
V_29 = V_13 -> V_29 ;
if ( ( V_6 = F_5 () ) == NULL || ( V_9 = F_6 () ) == NULL ||
( V_31 = F_6 () ) == NULL || ( V_30 = F_6 () ) == NULL )
{
F_4 ( V_35 , V_16 ) ;
goto V_17;
}
if ( ! F_8 ( V_12 , V_9 , V_6 ) )
{
F_4 ( V_35 , V_18 ) ;
goto V_17;
}
V_27 = F_26 ( V_9 ) ;
if ( 8 * V_23 > V_27 )
V_23 = ( V_27 + 7 ) / 8 ;
if ( ! F_27 ( V_22 , V_23 , V_30 ) )
{
F_4 ( V_35 , V_21 ) ;
goto V_17;
}
if ( ( 8 * V_23 > V_27 ) && ! F_28 ( V_30 , V_30 , 8 - ( V_27 & 0x7 ) ) )
{
F_4 ( V_35 , V_21 ) ;
goto V_17;
}
do
{
if ( V_24 == NULL || V_25 == NULL )
{
if ( ! F_29 ( V_2 , V_6 , & V_28 , & V_13 -> V_8 ) )
{
F_4 ( V_35 , V_36 ) ;
goto V_17;
}
V_32 = V_28 ;
}
else
{
V_32 = V_24 ;
if ( F_30 ( V_13 -> V_8 , V_25 ) == NULL )
{
F_4 ( V_35 , V_16 ) ;
goto V_17;
}
}
if ( ! F_31 ( V_31 , V_34 , V_13 -> V_8 , V_9 , V_6 ) )
{
F_4 ( V_35 , V_21 ) ;
goto V_17;
}
if ( ! F_32 ( V_29 , V_31 , V_30 , V_9 ) )
{
F_4 ( V_35 , V_21 ) ;
goto V_17;
}
if ( ! F_31 ( V_29 , V_29 , V_32 , V_9 , V_6 ) )
{
F_4 ( V_35 , V_21 ) ;
goto V_17;
}
if ( F_10 ( V_29 ) )
{
if ( V_24 != NULL && V_25 != NULL )
{
F_4 ( V_35 , V_37 ) ;
goto V_17;
}
}
else
break;
}
while ( 1 );
V_26 = 1 ;
V_17:
if ( ! V_26 )
{
F_33 ( V_13 ) ;
V_13 = NULL ;
}
if ( V_6 )
F_19 ( V_6 ) ;
if ( V_30 )
F_18 ( V_30 ) ;
if ( V_31 )
F_18 ( V_31 ) ;
if ( V_9 )
F_20 ( V_9 ) ;
if ( V_28 )
F_18 ( V_28 ) ;
return V_13 ;
}
static int F_34 ( const unsigned char * V_22 , int V_23 ,
const T_7 * V_38 , T_2 * V_2 )
{
int V_13 = - 1 , V_27 ;
T_3 * V_6 ;
T_4 * V_9 , * V_39 , * V_40 , * V_30 , * V_10 ;
T_5 * V_41 = NULL ;
const T_6 * V_12 ;
const T_5 * V_42 ;
if ( V_2 == NULL || ( V_12 = F_3 ( V_2 ) ) == NULL ||
( V_42 = F_35 ( V_2 ) ) == NULL || V_38 == NULL )
{
F_4 ( V_43 , V_44 ) ;
return - 1 ;
}
V_6 = F_5 () ;
if ( ! V_6 )
{
F_4 ( V_43 , V_16 ) ;
return - 1 ;
}
F_36 ( V_6 ) ;
V_9 = F_37 ( V_6 ) ;
V_39 = F_37 ( V_6 ) ;
V_40 = F_37 ( V_6 ) ;
V_30 = F_37 ( V_6 ) ;
V_10 = F_37 ( V_6 ) ;
if ( ! V_10 )
{
F_4 ( V_43 , V_21 ) ;
goto V_17;
}
if ( ! F_8 ( V_12 , V_9 , V_6 ) )
{
F_4 ( V_43 , V_18 ) ;
goto V_17;
}
if ( F_10 ( V_38 -> V_8 ) || F_38 ( V_38 -> V_8 ) ||
F_39 ( V_38 -> V_8 , V_9 ) >= 0 || F_10 ( V_38 -> V_29 ) ||
F_38 ( V_38 -> V_29 ) || F_39 ( V_38 -> V_29 , V_9 ) >= 0 )
{
F_4 ( V_43 , V_45 ) ;
V_13 = 0 ;
goto V_17;
}
if ( ! F_17 ( V_40 , V_38 -> V_29 , V_9 , V_6 ) )
{
F_4 ( V_43 , V_21 ) ;
goto V_17;
}
V_27 = F_26 ( V_9 ) ;
if ( 8 * V_23 > V_27 )
V_23 = ( V_27 + 7 ) / 8 ;
if ( ! F_27 ( V_22 , V_23 , V_30 ) )
{
F_4 ( V_43 , V_21 ) ;
goto V_17;
}
if ( ( 8 * V_23 > V_27 ) && ! F_28 ( V_30 , V_30 , 8 - ( V_27 & 0x7 ) ) )
{
F_4 ( V_43 , V_21 ) ;
goto V_17;
}
if ( ! F_31 ( V_39 , V_30 , V_40 , V_9 , V_6 ) )
{
F_4 ( V_43 , V_21 ) ;
goto V_17;
}
if ( ! F_31 ( V_40 , V_38 -> V_8 , V_40 , V_9 , V_6 ) )
{
F_4 ( V_43 , V_21 ) ;
goto V_17;
}
if ( ( V_41 = F_7 ( V_12 ) ) == NULL )
{
F_4 ( V_43 , V_16 ) ;
goto V_17;
}
if ( ! F_11 ( V_12 , V_41 , V_39 , V_42 , V_40 , V_6 ) )
{
F_4 ( V_43 , V_18 ) ;
goto V_17;
}
if ( F_12 ( F_13 ( V_12 ) ) == V_20 )
{
if ( ! F_14 ( V_12 ,
V_41 , V_10 , NULL , V_6 ) )
{
F_4 ( V_43 , V_18 ) ;
goto V_17;
}
}
else
{
if ( ! F_15 ( V_12 ,
V_41 , V_10 , NULL , V_6 ) )
{
F_4 ( V_43 , V_18 ) ;
goto V_17;
}
}
if ( ! F_16 ( V_39 , V_10 , V_9 , V_6 ) )
{
F_4 ( V_43 , V_21 ) ;
goto V_17;
}
V_13 = ( F_39 ( V_39 , V_38 -> V_8 ) == 0 ) ;
V_17:
F_40 ( V_6 ) ;
F_19 ( V_6 ) ;
if ( V_41 )
F_21 ( V_41 ) ;
return V_13 ;
}
