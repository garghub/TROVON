const T_1 * F_1 ( void )
{
return & V_1 ;
}
static T_2 * F_2 ( const unsigned char * V_2 , int V_3 , T_3 * V_4 )
{
T_4 * V_5 = NULL ;
T_4 * V_6 ;
T_4 * V_7 ;
T_5 * V_8 = NULL ;
int V_9 = V_10 ;
T_2 * V_11 = NULL ;
int V_12 = 0 ;
V_6 = F_3 () ;
V_7 = F_3 () ;
if ( V_6 == NULL || V_7 == NULL )
goto V_13;
if ( ! V_4 -> V_14 || ! V_4 -> V_15 || ! V_4 -> V_16 ) {
V_9 = V_17 ;
goto V_13;
}
V_11 = F_4 () ;
if ( V_11 == NULL )
goto V_13;
V_11 -> V_18 = F_3 () ;
V_11 -> V_19 = F_3 () ;
if ( V_11 -> V_18 == NULL || V_11 -> V_19 == NULL )
goto V_13;
V_8 = F_5 () ;
if ( V_8 == NULL )
goto V_13;
V_20:
if ( ! F_6 ( V_4 , V_8 , & V_5 , & V_11 -> V_18 , V_2 , V_3 ) )
goto V_13;
if ( V_3 > F_7 ( V_4 -> V_15 ) )
V_3 = F_7 ( V_4 -> V_15 ) ;
if ( F_8 ( V_2 , V_3 , V_6 ) == NULL )
goto V_13;
if ( ! F_9 ( V_7 , V_4 -> V_21 , V_11 -> V_18 , V_4 -> V_15 , V_8 ) )
goto V_13;
if ( ! F_10 ( V_11 -> V_19 , V_7 , V_6 ) )
goto V_13;
if ( F_11 ( V_11 -> V_19 , V_4 -> V_15 ) > 0 )
if ( ! F_12 ( V_11 -> V_19 , V_11 -> V_19 , V_4 -> V_15 ) )
goto V_13;
if ( ! F_9 ( V_11 -> V_19 , V_11 -> V_19 , V_5 , V_4 -> V_15 , V_8 ) )
goto V_13;
if ( F_13 ( V_11 -> V_18 ) || F_13 ( V_11 -> V_19 ) )
goto V_20;
V_12 = 1 ;
V_13:
if ( V_12 == 0 ) {
F_14 ( V_22 , V_9 ) ;
F_15 ( V_11 ) ;
V_11 = NULL ;
}
F_16 ( V_8 ) ;
F_17 ( V_6 ) ;
F_17 ( V_7 ) ;
F_17 ( V_5 ) ;
return V_11 ;
}
static int F_18 ( T_3 * V_4 , T_5 * V_23 ,
T_4 * * V_24 , T_4 * * V_25 )
{
return F_6 ( V_4 , V_23 , V_24 , V_25 , NULL , 0 ) ;
}
static int F_6 ( T_3 * V_4 , T_5 * V_23 ,
T_4 * * V_24 , T_4 * * V_25 ,
const unsigned char * V_2 , int V_3 )
{
T_5 * V_8 = NULL ;
T_4 * V_26 , * V_5 = NULL , * V_18 = * V_25 ;
int V_11 = 0 ;
if ( ! V_4 -> V_14 || ! V_4 -> V_15 || ! V_4 -> V_16 ) {
F_14 ( V_27 , V_17 ) ;
return 0 ;
}
V_26 = F_3 () ;
if ( V_26 == NULL )
goto V_13;
if ( V_23 == NULL ) {
if ( ( V_8 = F_5 () ) == NULL )
goto V_13;
} else
V_8 = V_23 ;
do {
if ( V_2 != NULL ) {
if ( ! F_19 ( V_26 , V_4 -> V_15 , V_4 -> V_21 , V_2 ,
V_3 , V_8 ) )
goto V_13;
} else if ( ! F_20 ( V_26 , V_4 -> V_15 ) )
goto V_13;
} while ( F_13 ( V_26 ) );
F_21 ( V_26 , V_28 ) ;
if ( V_4 -> V_29 & V_30 ) {
if ( ! F_22 ( & V_4 -> V_31 ,
V_4 -> V_32 , V_4 -> V_14 , V_8 ) )
goto V_13;
}
if ( ! F_10 ( V_26 , V_26 , V_4 -> V_15 ) )
goto V_13;
if ( F_23 ( V_26 ) <= F_23 ( V_4 -> V_15 ) ) {
if ( ! F_10 ( V_26 , V_26 , V_4 -> V_15 ) )
goto V_13;
}
if ( ( V_4 ) -> V_33 -> V_34 != NULL ) {
if ( ! V_4 -> V_33 -> V_34 ( V_4 , V_18 , V_4 -> V_16 , V_26 , V_4 -> V_14 , V_8 ,
V_4 -> V_31 ) )
goto V_13;
} else {
if ( ! F_24 ( V_18 , V_4 -> V_16 , V_26 , V_4 -> V_14 , V_8 , V_4 -> V_31 ) )
goto V_13;
}
if ( ! F_25 ( V_18 , V_18 , V_4 -> V_15 , V_8 ) )
goto V_13;
if ( ( V_5 = F_26 ( NULL , V_26 , V_4 -> V_15 , V_8 ) ) == NULL )
goto V_13;
F_17 ( * V_24 ) ;
* V_24 = V_5 ;
V_5 = NULL ;
V_11 = 1 ;
V_13:
if ( ! V_11 )
F_14 ( V_27 , V_10 ) ;
if ( V_8 != V_23 )
F_16 ( V_8 ) ;
F_17 ( V_26 ) ;
return V_11 ;
}
static int F_27 ( const unsigned char * V_2 , int V_35 ,
T_2 * V_36 , T_3 * V_4 )
{
T_5 * V_8 ;
T_4 * V_37 , * V_38 , * V_39 ;
T_6 * V_40 = NULL ;
const T_4 * V_18 , * V_19 ;
int V_11 = - 1 , V_41 ;
if ( ! V_4 -> V_14 || ! V_4 -> V_15 || ! V_4 -> V_16 ) {
F_14 ( V_42 , V_17 ) ;
return - 1 ;
}
V_41 = F_23 ( V_4 -> V_15 ) ;
if ( V_41 != 160 && V_41 != 224 && V_41 != 256 ) {
F_14 ( V_42 , V_43 ) ;
return - 1 ;
}
if ( F_23 ( V_4 -> V_14 ) > V_44 ) {
F_14 ( V_42 , V_45 ) ;
return - 1 ;
}
V_37 = F_3 () ;
V_38 = F_3 () ;
V_39 = F_3 () ;
V_8 = F_5 () ;
if ( V_37 == NULL || V_38 == NULL || V_39 == NULL || V_8 == NULL )
goto V_13;
F_28 ( V_36 , & V_18 , & V_19 ) ;
if ( F_13 ( V_18 ) || F_29 ( V_18 ) ||
F_30 ( V_18 , V_4 -> V_15 ) >= 0 ) {
V_11 = 0 ;
goto V_13;
}
if ( F_13 ( V_19 ) || F_29 ( V_19 ) ||
F_30 ( V_19 , V_4 -> V_15 ) >= 0 ) {
V_11 = 0 ;
goto V_13;
}
if ( ( F_26 ( V_38 , V_19 , V_4 -> V_15 , V_8 ) ) == NULL )
goto V_13;
if ( V_35 > ( V_41 >> 3 ) )
V_35 = ( V_41 >> 3 ) ;
if ( F_8 ( V_2 , V_35 , V_37 ) == NULL )
goto V_13;
if ( ! F_9 ( V_37 , V_37 , V_38 , V_4 -> V_15 , V_8 ) )
goto V_13;
if ( ! F_9 ( V_38 , V_18 , V_38 , V_4 -> V_15 , V_8 ) )
goto V_13;
if ( V_4 -> V_29 & V_30 ) {
V_40 = F_22 ( & V_4 -> V_31 ,
V_4 -> V_32 , V_4 -> V_14 , V_8 ) ;
if ( ! V_40 )
goto V_13;
}
if ( V_4 -> V_33 -> V_46 != NULL ) {
if ( ! V_4 -> V_33 -> V_46 ( V_4 , V_39 , V_4 -> V_16 , V_37 , V_4 -> V_47 , V_38 ,
V_4 -> V_14 , V_8 , V_40 ) )
goto V_13;
} else {
if ( ! F_31 ( V_39 , V_4 -> V_16 , V_37 , V_4 -> V_47 , V_38 , V_4 -> V_14 , V_8 ,
V_40 ) )
goto V_13;
}
if ( ! F_25 ( V_37 , V_39 , V_4 -> V_15 , V_8 ) )
goto V_13;
V_11 = ( F_30 ( V_37 , V_18 ) == 0 ) ;
V_13:
if ( V_11 < 0 )
F_14 ( V_42 , V_10 ) ;
F_16 ( V_8 ) ;
F_32 ( V_37 ) ;
F_32 ( V_38 ) ;
F_32 ( V_39 ) ;
return ( V_11 ) ;
}
static int F_33 ( T_3 * V_4 )
{
V_4 -> V_29 |= V_30 ;
return ( 1 ) ;
}
static int F_34 ( T_3 * V_4 )
{
F_35 ( V_4 -> V_31 ) ;
return ( 1 ) ;
}
