int F_1 ( T_1 * V_1 , int V_2 , int V_3 )
{
if ( ! V_1 )
return 1 ;
switch ( V_1 -> V_4 ) {
case 1 :
if ( ! V_1 -> V_1 . V_5 )
return 1 ;
V_1 -> V_1 . V_5 ( V_2 , V_3 , V_1 -> V_6 ) ;
return 1 ;
case 2 :
return V_1 -> V_1 . V_7 ( V_2 , V_3 , V_1 ) ;
default:
break;
}
return 0 ;
}
int F_2 ( T_2 * V_8 , int V_9 , int V_10 ,
const T_2 * V_11 , const T_2 * V_12 , T_1 * V_1 )
{
T_2 * V_13 ;
int V_14 = 0 ;
int V_15 , V_16 , V_17 = 0 ;
T_3 * V_18 ;
int V_19 = F_3 ( V_9 ) ;
V_18 = F_4 () ;
if ( V_18 == NULL )
goto V_20;
F_5 ( V_18 ) ;
V_13 = F_6 ( V_18 ) ;
if ( ! V_13 )
goto V_20;
V_21:
if ( V_11 == NULL ) {
if ( ! F_7 ( V_8 , V_9 ) )
goto V_20;
} else {
if ( V_10 ) {
if ( ! F_8 ( V_8 , V_9 , V_11 , V_12 , V_18 ) )
goto V_20;
} else {
if ( ! F_9 ( V_8 , V_9 , V_11 , V_12 , V_18 ) )
goto V_20;
}
}
if ( ! F_1 ( V_1 , 0 , V_17 ++ ) )
goto V_20;
if ( ! V_10 ) {
V_15 = F_10 ( V_8 , V_19 , V_18 , 0 , V_1 ) ;
if ( V_15 == - 1 )
goto V_20;
if ( V_15 == 0 )
goto V_21;
} else {
if ( ! F_11 ( V_13 , V_8 ) )
goto V_20;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
V_16 = F_10 ( V_8 , 1 , V_18 , 0 , V_1 ) ;
if ( V_16 == - 1 )
goto V_20;
if ( V_16 == 0 )
goto V_21;
V_16 = F_10 ( V_13 , 1 , V_18 , 0 , V_1 ) ;
if ( V_16 == - 1 )
goto V_20;
if ( V_16 == 0 )
goto V_21;
if ( ! F_1 ( V_1 , 2 , V_17 - 1 ) )
goto V_20;
}
}
V_14 = 1 ;
V_20:
if ( V_18 != NULL ) {
F_12 ( V_18 ) ;
F_13 ( V_18 ) ;
}
F_14 ( V_8 ) ;
return V_14 ;
}
int F_15 ( const T_2 * V_2 , int V_19 , T_3 * V_22 ,
T_1 * V_1 )
{
return F_10 ( V_2 , V_19 , V_22 , 0 , V_1 ) ;
}
int F_10 ( const T_2 * V_2 , int V_19 , T_3 * V_22 ,
int V_23 , T_1 * V_1 )
{
int V_15 , V_16 , V_8 = - 1 ;
int V_24 ;
T_3 * V_18 = NULL ;
T_2 * V_25 , * V_26 , * V_27 ;
T_4 * V_28 = NULL ;
const T_2 * V_29 = NULL ;
if ( F_16 ( V_2 , F_17 () ) <= 0 )
return 0 ;
if ( V_19 == V_30 )
V_19 = F_3 ( F_18 ( V_2 ) ) ;
if ( ! F_19 ( V_2 ) )
return F_20 ( V_2 , 2 ) ;
if ( V_23 ) {
for ( V_15 = 1 ; V_15 < V_31 ; V_15 ++ )
if ( F_21 ( V_2 , V_32 [ V_15 ] ) == 0 )
return 0 ;
if ( ! F_1 ( V_1 , 1 , - 1 ) )
goto V_20;
}
if ( V_22 != NULL )
V_18 = V_22 ;
else if ( ( V_18 = F_4 () ) == NULL )
goto V_20;
F_5 ( V_18 ) ;
if ( V_2 -> V_33 ) {
T_2 * V_13 ;
if ( ( V_13 = F_6 ( V_18 ) ) == NULL )
goto V_20;
F_22 ( V_13 , V_2 ) ;
V_13 -> V_33 = 0 ;
V_29 = V_13 ;
} else
V_29 = V_2 ;
V_25 = F_6 ( V_18 ) ;
V_26 = F_6 ( V_18 ) ;
V_27 = F_6 ( V_18 ) ;
if ( V_27 == NULL )
goto V_20;
if ( ! F_22 ( V_25 , V_29 ) )
goto V_20;
if ( ! F_23 ( V_25 , 1 ) )
goto V_20;
if ( F_24 ( V_25 ) ) {
V_8 = 0 ;
goto V_20;
}
V_24 = 1 ;
while ( ! F_25 ( V_25 , V_24 ) )
V_24 ++ ;
if ( ! F_26 ( V_26 , V_25 , V_24 ) )
goto V_20;
V_28 = F_27 () ;
if ( V_28 == NULL )
goto V_20;
if ( ! F_28 ( V_28 , V_29 , V_18 ) )
goto V_20;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
if ( ! F_29 ( V_27 , V_25 ) )
goto V_20;
if ( ! F_30 ( V_27 , 1 ) )
goto V_20;
V_16 = F_31 ( V_27 , V_29 , V_25 , V_26 , V_24 , V_18 , V_28 ) ;
if ( V_16 == - 1 )
goto V_20;
if ( V_16 ) {
V_8 = 0 ;
goto V_20;
}
if ( ! F_1 ( V_1 , 1 , V_15 ) )
goto V_20;
}
V_8 = 1 ;
V_20:
if ( V_18 != NULL ) {
F_12 ( V_18 ) ;
if ( V_22 == NULL )
F_13 ( V_18 ) ;
}
if ( V_28 != NULL )
F_32 ( V_28 ) ;
return ( V_8 ) ;
}
static int F_31 ( T_2 * V_34 , const T_2 * V_2 , const T_2 * V_35 ,
const T_2 * V_36 , int V_24 , T_3 * V_18 ,
T_4 * V_28 )
{
if ( ! F_33 ( V_34 , V_34 , V_36 , V_2 , V_18 , V_28 ) )
return - 1 ;
if ( F_34 ( V_34 ) )
return 0 ;
if ( F_16 ( V_34 , V_35 ) == 0 )
return 0 ;
while ( -- V_24 ) {
if ( ! F_35 ( V_34 , V_34 , V_34 , V_2 , V_18 ) )
return - 1 ;
if ( F_34 ( V_34 ) )
return 1 ;
if ( F_16 ( V_34 , V_35 ) == 0 )
return 0 ;
}
F_14 ( V_34 ) ;
return 1 ;
}
static int F_7 ( T_2 * V_37 , int V_9 )
{
int V_15 ;
T_5 V_38 [ V_31 ] ;
T_6 V_39 , V_40 ;
V_41:
if ( ! F_36 ( V_37 , V_9 , 1 , 1 ) )
return ( 0 ) ;
for ( V_15 = 1 ; V_15 < V_31 ; V_15 ++ )
V_38 [ V_15 ] = ( T_5 ) F_21 ( V_37 , ( T_6 ) V_32 [ V_15 ] ) ;
V_40 = V_42 - V_32 [ V_31 - 1 ] ;
V_39 = 0 ;
V_21: for ( V_15 = 1 ; V_15 < V_31 ; V_15 ++ ) {
if ( ( ( V_38 [ V_15 ] + V_39 ) % V_32 [ V_15 ] ) <= 1 ) {
V_39 += 2 ;
if ( V_39 > V_40 )
goto V_41;
goto V_21;
}
}
if ( ! F_30 ( V_37 , V_39 ) )
return ( 0 ) ;
F_14 ( V_37 ) ;
return ( 1 ) ;
}
static int F_9 ( T_2 * V_37 , int V_9 ,
const T_2 * V_11 , const T_2 * V_12 ,
T_3 * V_18 )
{
int V_15 , V_8 = 0 ;
T_2 * V_43 ;
F_5 ( V_18 ) ;
if ( ( V_43 = F_6 ( V_18 ) ) == NULL )
goto V_20;
if ( ! F_36 ( V_37 , V_9 , 0 , 1 ) )
goto V_20;
if ( ! F_37 ( V_43 , V_37 , V_11 , V_18 ) )
goto V_20;
if ( ! F_38 ( V_37 , V_37 , V_43 ) )
goto V_20;
if ( V_12 == NULL ) {
if ( ! F_30 ( V_37 , 1 ) )
goto V_20;
} else {
if ( ! F_39 ( V_37 , V_37 , V_12 ) )
goto V_20;
}
V_21: for ( V_15 = 1 ; V_15 < V_31 ; V_15 ++ ) {
if ( F_21 ( V_37 , ( T_6 ) V_32 [ V_15 ] ) <= 1 ) {
if ( ! F_39 ( V_37 , V_37 , V_11 ) )
goto V_20;
goto V_21;
}
}
V_8 = 1 ;
V_20:
F_12 ( V_18 ) ;
F_14 ( V_37 ) ;
return ( V_8 ) ;
}
static int F_8 ( T_2 * V_44 , int V_9 , const T_2 * V_45 ,
const T_2 * V_12 , T_3 * V_18 )
{
int V_15 , V_8 = 0 ;
T_2 * V_43 , * V_46 , * V_47 ;
V_9 -- ;
F_5 ( V_18 ) ;
V_43 = F_6 ( V_18 ) ;
V_47 = F_6 ( V_18 ) ;
V_46 = F_6 ( V_18 ) ;
if ( V_46 == NULL )
goto V_20;
if ( ! F_11 ( V_46 , V_45 ) )
goto V_20;
if ( ! F_36 ( V_47 , V_9 , 0 , 1 ) )
goto V_20;
if ( ! F_37 ( V_43 , V_47 , V_46 , V_18 ) )
goto V_20;
if ( ! F_38 ( V_47 , V_47 , V_43 ) )
goto V_20;
if ( V_12 == NULL ) {
if ( ! F_30 ( V_47 , 1 ) )
goto V_20;
} else {
if ( ! F_11 ( V_43 , V_12 ) )
goto V_20;
if ( ! F_39 ( V_47 , V_47 , V_43 ) )
goto V_20;
}
if ( ! F_40 ( V_44 , V_47 ) )
goto V_20;
if ( ! F_30 ( V_44 , 1 ) )
goto V_20;
V_21: for ( V_15 = 1 ; V_15 < V_31 ; V_15 ++ ) {
if ( ( F_21 ( V_44 , ( T_6 ) V_32 [ V_15 ] ) == 0 ) ||
( F_21 ( V_47 , ( T_6 ) V_32 [ V_15 ] ) == 0 ) ) {
if ( ! F_39 ( V_44 , V_44 , V_45 ) )
goto V_20;
if ( ! F_39 ( V_47 , V_47 , V_46 ) )
goto V_20;
goto V_21;
}
}
V_8 = 1 ;
V_20:
F_12 ( V_18 ) ;
F_14 ( V_44 ) ;
return ( V_8 ) ;
}
