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
if ( V_2 == NULL || ( V_12 = F_3 ( V_2 ) ) == NULL ) {
F_4 ( V_14 , V_15 ) ;
return 0 ;
}
if ( V_3 == NULL ) {
if ( ( V_6 = F_5 () ) == NULL ) {
F_4 ( V_14 , V_16 ) ;
return 0 ;
}
} else
V_6 = V_3 ;
V_7 = F_6 () ;
V_8 = F_6 () ;
V_9 = F_6 () ;
V_10 = F_6 () ;
if ( ! V_7 || ! V_8 || ! V_9 || ! V_10 ) {
F_4 ( V_14 , V_16 ) ;
goto V_17;
}
if ( ( V_11 = F_7 ( V_12 ) ) == NULL ) {
F_4 ( V_14 , V_18 ) ;
goto V_17;
}
if ( ! F_8 ( V_12 , V_9 , V_6 ) ) {
F_4 ( V_14 , V_18 ) ;
goto V_17;
}
do {
do
if ( ! F_9 ( V_7 , V_9 ) ) {
F_4 ( V_14 ,
V_19 ) ;
goto V_17;
}
while ( F_10 ( V_7 ) ) ;
if ( ! F_11 ( V_7 , V_7 , V_9 ) )
goto V_17;
if ( F_12 ( V_7 ) <= F_12 ( V_9 ) )
if ( ! F_11 ( V_7 , V_7 , V_9 ) )
goto V_17;
if ( ! F_13 ( V_12 , V_11 , V_7 , NULL , NULL , V_6 ) ) {
F_4 ( V_14 , V_18 ) ;
goto V_17;
}
if ( F_14 ( F_15 ( V_12 ) ) ==
V_20 ) {
if ( ! F_16
( V_12 , V_11 , V_10 , NULL , V_6 ) ) {
F_4 ( V_14 , V_18 ) ;
goto V_17;
}
}
#ifndef F_17
else {
if ( ! F_18 ( V_12 ,
V_11 , V_10 , NULL ,
V_6 ) ) {
F_4 ( V_14 , V_18 ) ;
goto V_17;
}
}
#endif
if ( ! F_19 ( V_8 , V_10 , V_9 , V_6 ) ) {
F_4 ( V_14 , V_21 ) ;
goto V_17;
}
}
while ( F_10 ( V_8 ) );
if ( F_20 ( V_12 ) != NULL ) {
if ( ! F_21 ( V_10 , 2 ) ) {
F_4 ( V_14 , V_21 ) ;
goto V_17;
}
if ( ! F_22 ( V_10 , V_9 , V_10 , V_9 , V_6 ) ) {
F_4 ( V_14 , V_21 ) ;
goto V_17;
}
F_23 ( V_10 , V_22 ) ;
if ( ! F_24
( V_7 , V_7 , V_10 , V_9 , V_6 , F_20 ( V_12 ) ) ) {
F_4 ( V_14 , V_21 ) ;
goto V_17;
}
} else {
if ( ! F_25 ( V_7 , V_7 , V_9 , V_6 ) ) {
F_4 ( V_14 , V_21 ) ;
goto V_17;
}
}
if ( * V_5 != NULL )
F_26 ( * V_5 ) ;
if ( * V_4 != NULL )
F_26 ( * V_4 ) ;
* V_5 = V_8 ;
* V_4 = V_7 ;
V_13 = 1 ;
V_17:
if ( ! V_13 ) {
if ( V_7 != NULL )
F_26 ( V_7 ) ;
if ( V_8 != NULL )
F_26 ( V_8 ) ;
}
if ( V_3 == NULL )
F_27 ( V_6 ) ;
if ( V_9 != NULL )
F_28 ( V_9 ) ;
if ( V_11 != NULL )
F_29 ( V_11 ) ;
if ( V_10 )
F_26 ( V_10 ) ;
return ( V_13 ) ;
}
static T_7 * F_30 ( const unsigned char * V_23 , int V_24 ,
const T_4 * V_25 , const T_4 * V_26 ,
T_2 * V_2 )
{
int V_27 = 0 , V_28 ;
T_4 * V_29 = NULL , * V_30 , * V_31 = NULL , * V_32 = NULL , * V_9 = NULL ;
const T_4 * V_33 ;
T_3 * V_6 = NULL ;
const T_6 * V_12 ;
T_7 * V_13 ;
T_8 * V_34 ;
const T_4 * V_35 ;
V_34 = F_31 ( V_2 ) ;
V_12 = F_3 ( V_2 ) ;
V_35 = F_32 ( V_2 ) ;
if ( V_12 == NULL || V_35 == NULL || V_34 == NULL ) {
F_4 ( V_36 , V_15 ) ;
return NULL ;
}
V_13 = F_33 () ;
if ( ! V_13 ) {
F_4 ( V_36 , V_16 ) ;
return NULL ;
}
V_30 = V_13 -> V_30 ;
if ( ( V_6 = F_5 () ) == NULL || ( V_9 = F_6 () ) == NULL ||
( V_32 = F_6 () ) == NULL || ( V_31 = F_6 () ) == NULL ) {
F_4 ( V_36 , V_16 ) ;
goto V_17;
}
if ( ! F_8 ( V_12 , V_9 , V_6 ) ) {
F_4 ( V_36 , V_18 ) ;
goto V_17;
}
V_28 = F_12 ( V_9 ) ;
if ( 8 * V_24 > V_28 )
V_24 = ( V_28 + 7 ) / 8 ;
if ( ! F_34 ( V_23 , V_24 , V_31 ) ) {
F_4 ( V_36 , V_21 ) ;
goto V_17;
}
if ( ( 8 * V_24 > V_28 ) && ! F_35 ( V_31 , V_31 , 8 - ( V_28 & 0x7 ) ) ) {
F_4 ( V_36 , V_21 ) ;
goto V_17;
}
do {
if ( V_25 == NULL || V_26 == NULL ) {
if ( ! F_36 ( V_2 , V_6 , & V_29 , & V_13 -> V_8 ) ) {
F_4 ( V_36 , V_37 ) ;
goto V_17;
}
V_33 = V_29 ;
} else {
V_33 = V_25 ;
if ( F_37 ( V_13 -> V_8 , V_26 ) == NULL ) {
F_4 ( V_36 , V_16 ) ;
goto V_17;
}
}
if ( ! F_38 ( V_32 , V_35 , V_13 -> V_8 , V_9 , V_6 ) ) {
F_4 ( V_36 , V_21 ) ;
goto V_17;
}
if ( ! F_39 ( V_30 , V_32 , V_31 , V_9 ) ) {
F_4 ( V_36 , V_21 ) ;
goto V_17;
}
if ( ! F_38 ( V_30 , V_30 , V_33 , V_9 , V_6 ) ) {
F_4 ( V_36 , V_21 ) ;
goto V_17;
}
if ( F_10 ( V_30 ) ) {
if ( V_25 != NULL && V_26 != NULL ) {
F_4 ( V_36 ,
V_38 ) ;
goto V_17;
}
} else
break;
}
while ( 1 );
V_27 = 1 ;
V_17:
if ( ! V_27 ) {
F_40 ( V_13 ) ;
V_13 = NULL ;
}
if ( V_6 )
F_27 ( V_6 ) ;
if ( V_31 )
F_26 ( V_31 ) ;
if ( V_32 )
F_26 ( V_32 ) ;
if ( V_9 )
F_28 ( V_9 ) ;
if ( V_29 )
F_26 ( V_29 ) ;
return V_13 ;
}
static int F_41 ( const unsigned char * V_23 , int V_24 ,
const T_7 * V_39 , T_2 * V_2 )
{
int V_13 = - 1 , V_28 ;
T_3 * V_6 ;
T_4 * V_9 , * V_40 , * V_41 , * V_31 , * V_10 ;
T_5 * V_42 = NULL ;
const T_6 * V_12 ;
const T_5 * V_43 ;
if ( V_2 == NULL || ( V_12 = F_3 ( V_2 ) ) == NULL ||
( V_43 = F_42 ( V_2 ) ) == NULL || V_39 == NULL ) {
F_4 ( V_44 , V_45 ) ;
return - 1 ;
}
V_6 = F_5 () ;
if ( ! V_6 ) {
F_4 ( V_44 , V_16 ) ;
return - 1 ;
}
F_43 ( V_6 ) ;
V_9 = F_44 ( V_6 ) ;
V_40 = F_44 ( V_6 ) ;
V_41 = F_44 ( V_6 ) ;
V_31 = F_44 ( V_6 ) ;
V_10 = F_44 ( V_6 ) ;
if ( ! V_10 ) {
F_4 ( V_44 , V_21 ) ;
goto V_17;
}
if ( ! F_8 ( V_12 , V_9 , V_6 ) ) {
F_4 ( V_44 , V_18 ) ;
goto V_17;
}
if ( F_10 ( V_39 -> V_8 ) || F_45 ( V_39 -> V_8 ) ||
F_46 ( V_39 -> V_8 , V_9 ) >= 0 || F_10 ( V_39 -> V_30 ) ||
F_45 ( V_39 -> V_30 ) || F_46 ( V_39 -> V_30 , V_9 ) >= 0 ) {
F_4 ( V_44 , V_46 ) ;
V_13 = 0 ;
goto V_17;
}
if ( ! F_25 ( V_41 , V_39 -> V_30 , V_9 , V_6 ) ) {
F_4 ( V_44 , V_21 ) ;
goto V_17;
}
V_28 = F_12 ( V_9 ) ;
if ( 8 * V_24 > V_28 )
V_24 = ( V_28 + 7 ) / 8 ;
if ( ! F_34 ( V_23 , V_24 , V_31 ) ) {
F_4 ( V_44 , V_21 ) ;
goto V_17;
}
if ( ( 8 * V_24 > V_28 ) && ! F_35 ( V_31 , V_31 , 8 - ( V_28 & 0x7 ) ) ) {
F_4 ( V_44 , V_21 ) ;
goto V_17;
}
if ( ! F_38 ( V_40 , V_31 , V_41 , V_9 , V_6 ) ) {
F_4 ( V_44 , V_21 ) ;
goto V_17;
}
if ( ! F_38 ( V_41 , V_39 -> V_8 , V_41 , V_9 , V_6 ) ) {
F_4 ( V_44 , V_21 ) ;
goto V_17;
}
if ( ( V_42 = F_7 ( V_12 ) ) == NULL ) {
F_4 ( V_44 , V_16 ) ;
goto V_17;
}
if ( ! F_13 ( V_12 , V_42 , V_40 , V_43 , V_41 , V_6 ) ) {
F_4 ( V_44 , V_18 ) ;
goto V_17;
}
if ( F_14 ( F_15 ( V_12 ) ) ==
V_20 ) {
if ( ! F_16 ( V_12 , V_42 , V_10 , NULL , V_6 ) ) {
F_4 ( V_44 , V_18 ) ;
goto V_17;
}
}
#ifndef F_17
else {
if ( ! F_18 ( V_12 , V_42 , V_10 , NULL , V_6 ) ) {
F_4 ( V_44 , V_18 ) ;
goto V_17;
}
}
#endif
if ( ! F_19 ( V_40 , V_10 , V_9 , V_6 ) ) {
F_4 ( V_44 , V_21 ) ;
goto V_17;
}
V_13 = ( F_46 ( V_40 , V_39 -> V_8 ) == 0 ) ;
V_17:
F_47 ( V_6 ) ;
F_27 ( V_6 ) ;
if ( V_42 )
F_29 ( V_42 ) ;
return V_13 ;
}
