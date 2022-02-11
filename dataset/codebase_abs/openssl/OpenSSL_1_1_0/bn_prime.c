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
T_3 * V_18 = NULL ;
T_4 * V_19 = NULL ;
int V_20 = F_3 ( V_9 ) ;
if ( V_9 < 2 ) {
F_4 ( V_21 , V_22 ) ;
return 0 ;
} else if ( V_9 == 2 && V_10 ) {
F_4 ( V_21 , V_22 ) ;
return 0 ;
}
V_19 = F_5 ( sizeof( * V_19 ) * V_23 ) ;
if ( V_19 == NULL )
goto V_24;
V_18 = F_6 () ;
if ( V_18 == NULL )
goto V_24;
F_7 ( V_18 ) ;
V_13 = F_8 ( V_18 ) ;
if ( ! V_13 )
goto V_24;
V_25:
if ( V_11 == NULL ) {
if ( ! F_9 ( V_8 , V_9 , V_19 ) )
goto V_24;
} else {
if ( V_10 ) {
if ( ! F_10 ( V_8 , V_9 , V_11 , V_12 , V_18 ) )
goto V_24;
} else {
if ( ! F_11 ( V_8 , V_9 , V_11 , V_12 , V_18 ) )
goto V_24;
}
}
if ( ! F_1 ( V_1 , 0 , V_17 ++ ) )
goto V_24;
if ( ! V_10 ) {
V_15 = F_12 ( V_8 , V_20 , V_18 , 0 , V_1 ) ;
if ( V_15 == - 1 )
goto V_24;
if ( V_15 == 0 )
goto V_25;
} else {
if ( ! F_13 ( V_13 , V_8 ) )
goto V_24;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ ) {
V_16 = F_12 ( V_8 , 1 , V_18 , 0 , V_1 ) ;
if ( V_16 == - 1 )
goto V_24;
if ( V_16 == 0 )
goto V_25;
V_16 = F_12 ( V_13 , 1 , V_18 , 0 , V_1 ) ;
if ( V_16 == - 1 )
goto V_24;
if ( V_16 == 0 )
goto V_25;
if ( ! F_1 ( V_1 , 2 , V_17 - 1 ) )
goto V_24;
}
}
V_14 = 1 ;
V_24:
F_14 ( V_19 ) ;
if ( V_18 != NULL )
F_15 ( V_18 ) ;
F_16 ( V_18 ) ;
F_17 ( V_8 ) ;
return V_14 ;
}
int F_18 ( const T_2 * V_2 , int V_20 , T_3 * V_26 ,
T_1 * V_1 )
{
return F_12 ( V_2 , V_20 , V_26 , 0 , V_1 ) ;
}
int F_12 ( const T_2 * V_2 , int V_20 , T_3 * V_26 ,
int V_27 , T_1 * V_1 )
{
int V_15 , V_16 , V_8 = - 1 ;
int V_28 ;
T_3 * V_18 = NULL ;
T_2 * V_29 , * V_30 , * V_31 ;
T_5 * V_32 = NULL ;
const T_2 * V_33 = NULL ;
if ( F_19 ( V_2 , F_20 () ) <= 0 )
return 0 ;
if ( V_20 == V_34 )
V_20 = F_3 ( F_21 ( V_2 ) ) ;
if ( ! F_22 ( V_2 ) )
return F_23 ( V_2 , 2 ) ;
if ( V_27 ) {
for ( V_15 = 1 ; V_15 < V_23 ; V_15 ++ ) {
T_6 V_35 = F_24 ( V_2 , V_36 [ V_15 ] ) ;
if ( V_35 == ( T_6 ) - 1 )
goto V_24;
if ( V_35 == 0 )
return 0 ;
}
if ( ! F_1 ( V_1 , 1 , - 1 ) )
goto V_24;
}
if ( V_26 != NULL )
V_18 = V_26 ;
else if ( ( V_18 = F_6 () ) == NULL )
goto V_24;
F_7 ( V_18 ) ;
if ( V_2 -> V_37 ) {
T_2 * V_13 ;
if ( ( V_13 = F_8 ( V_18 ) ) == NULL )
goto V_24;
F_25 ( V_13 , V_2 ) ;
V_13 -> V_37 = 0 ;
V_33 = V_13 ;
} else
V_33 = V_2 ;
V_29 = F_8 ( V_18 ) ;
V_30 = F_8 ( V_18 ) ;
V_31 = F_8 ( V_18 ) ;
if ( V_31 == NULL )
goto V_24;
if ( ! F_25 ( V_29 , V_33 ) )
goto V_24;
if ( ! F_26 ( V_29 , 1 ) )
goto V_24;
if ( F_27 ( V_29 ) ) {
V_8 = 0 ;
goto V_24;
}
V_28 = 1 ;
while ( ! F_28 ( V_29 , V_28 ) )
V_28 ++ ;
if ( ! F_29 ( V_30 , V_29 , V_28 ) )
goto V_24;
V_32 = F_30 () ;
if ( V_32 == NULL )
goto V_24;
if ( ! F_31 ( V_32 , V_33 , V_18 ) )
goto V_24;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ ) {
if ( ! F_32 ( V_31 , V_29 ) )
goto V_24;
if ( ! F_33 ( V_31 , 1 ) )
goto V_24;
V_16 = F_34 ( V_31 , V_33 , V_29 , V_30 , V_28 , V_18 , V_32 ) ;
if ( V_16 == - 1 )
goto V_24;
if ( V_16 ) {
V_8 = 0 ;
goto V_24;
}
if ( ! F_1 ( V_1 , 1 , V_15 ) )
goto V_24;
}
V_8 = 1 ;
V_24:
if ( V_18 != NULL ) {
F_15 ( V_18 ) ;
if ( V_26 == NULL )
F_16 ( V_18 ) ;
}
F_35 ( V_32 ) ;
return ( V_8 ) ;
}
int F_36 ( T_2 * V_38 , int V_9 , T_3 * V_18 )
{
int V_15 ;
int V_8 = 0 ;
V_25:
if ( ! F_37 ( V_38 , V_9 , V_39 , V_40 ) )
goto V_24;
for ( V_15 = 1 ; V_15 < V_23 ; V_15 ++ ) {
T_6 V_35 = F_24 ( V_38 , ( T_6 ) V_36 [ V_15 ] ) ;
if ( V_35 == ( T_6 ) - 1 )
goto V_24;
if ( V_35 <= 1 ) {
goto V_25;
}
}
V_8 = 1 ;
V_24:
F_17 ( V_38 ) ;
return ( V_8 ) ;
}
int F_38 ( T_2 * V_38 , int V_9 , T_3 * V_18 )
{
int V_15 ;
T_2 * V_41 ;
T_2 * V_42 ;
int V_8 = 0 ;
F_39 ( V_9 > V_43 ) ;
F_7 ( V_18 ) ;
if ( ( V_41 = F_8 ( V_18 ) ) == NULL )
goto V_24;
if ( ( V_42 = F_8 ( V_18 ) ) == NULL )
goto V_24;
if ( ! F_33 ( V_42 , V_44 ) )
goto V_24;
V_25:
if ( ! F_37 ( V_38 , V_9 - V_43 ,
V_39 , V_40 ) )
goto V_24;
if ( F_28 ( V_38 , V_9 ) )
goto V_25;
if ( ! F_40 ( V_41 , V_42 ) )
goto V_24;
if ( ! F_41 ( V_38 , V_45 )
|| ! F_33 ( V_38 , V_46 [ F_42 ( V_41 ) ] ) )
goto V_24;
for ( V_15 = V_47 ; V_15 < V_23 ; V_15 ++ ) {
T_6 V_35 = F_24 ( V_38 , ( T_6 ) V_36 [ V_15 ] ) ;
if ( V_35 == ( T_6 ) - 1 )
goto V_24;
if ( V_35 <= 1 )
goto V_25;
}
V_8 = 1 ;
V_24:
F_15 ( V_18 ) ;
F_17 ( V_38 ) ;
return V_8 ;
}
static int F_34 ( T_2 * V_48 , const T_2 * V_2 , const T_2 * V_49 ,
const T_2 * V_50 , int V_28 , T_3 * V_18 ,
T_5 * V_32 )
{
if ( ! F_43 ( V_48 , V_48 , V_50 , V_2 , V_18 , V_32 ) )
return - 1 ;
if ( F_44 ( V_48 ) )
return 0 ;
if ( F_19 ( V_48 , V_49 ) == 0 )
return 0 ;
while ( -- V_28 ) {
if ( ! F_45 ( V_48 , V_48 , V_48 , V_2 , V_18 ) )
return - 1 ;
if ( F_44 ( V_48 ) )
return 1 ;
if ( F_19 ( V_48 , V_49 ) == 0 )
return 0 ;
}
F_17 ( V_48 ) ;
return 1 ;
}
static int F_9 ( T_2 * V_38 , int V_9 , T_4 * V_19 )
{
int V_15 ;
T_6 V_51 ;
T_6 V_52 = V_53 - V_36 [ V_23 - 1 ] ;
char V_54 = V_9 <= V_55 ;
V_56:
if ( ! F_37 ( V_38 , V_9 , V_57 , V_40 ) )
return ( 0 ) ;
for ( V_15 = 1 ; V_15 < V_23 ; V_15 ++ ) {
T_6 V_35 = F_24 ( V_38 , ( T_6 ) V_36 [ V_15 ] ) ;
if ( V_35 == ( T_6 ) - 1 )
return 0 ;
V_19 [ V_15 ] = ( T_4 ) V_35 ;
}
if ( V_54 ) {
T_6 V_58 ;
if ( V_9 == V_55 ) {
V_58 = ~ ( ( T_6 ) 0 ) - F_42 ( V_38 ) ;
} else {
V_58 = ( ( ( T_6 ) 1 ) << V_9 ) - F_42 ( V_38 ) - 1 ;
}
if ( V_58 < V_52 )
V_52 = V_58 ;
}
V_51 = 0 ;
V_25:
if ( V_54 ) {
T_6 V_59 = F_42 ( V_38 ) ;
for ( V_15 = 1 ; V_15 < V_23 && V_36 [ V_15 ] < V_59 ; V_15 ++ ) {
if ( ( V_19 [ V_15 ] + V_51 ) % V_36 [ V_15 ] == 0 ) {
V_51 += 2 ;
if ( V_51 > V_52 )
goto V_56;
goto V_25;
}
}
} else {
for ( V_15 = 1 ; V_15 < V_23 ; V_15 ++ ) {
if ( ( ( V_19 [ V_15 ] + V_51 ) % V_36 [ V_15 ] ) <= 1 ) {
V_51 += 2 ;
if ( V_51 > V_52 )
goto V_56;
goto V_25;
}
}
}
if ( ! F_33 ( V_38 , V_51 ) )
return ( 0 ) ;
if ( F_21 ( V_38 ) != V_9 )
goto V_56;
F_17 ( V_38 ) ;
return ( 1 ) ;
}
int F_11 ( T_2 * V_38 , int V_9 ,
const T_2 * V_11 , const T_2 * V_12 , T_3 * V_18 )
{
int V_15 , V_8 = 0 ;
T_2 * V_60 ;
F_7 ( V_18 ) ;
if ( ( V_60 = F_8 ( V_18 ) ) == NULL )
goto V_24;
if ( ! F_37 ( V_38 , V_9 , V_39 , V_40 ) )
goto V_24;
if ( ! F_46 ( V_60 , V_38 , V_11 , V_18 ) )
goto V_24;
if ( ! F_47 ( V_38 , V_38 , V_60 ) )
goto V_24;
if ( V_12 == NULL ) {
if ( ! F_33 ( V_38 , 1 ) )
goto V_24;
} else {
if ( ! F_48 ( V_38 , V_38 , V_12 ) )
goto V_24;
}
V_25:
for ( V_15 = 1 ; V_15 < V_23 ; V_15 ++ ) {
T_6 V_35 = F_24 ( V_38 , ( T_6 ) V_36 [ V_15 ] ) ;
if ( V_35 == ( T_6 ) - 1 )
goto V_24;
if ( V_35 <= 1 ) {
if ( ! F_48 ( V_38 , V_38 , V_11 ) )
goto V_24;
goto V_25;
}
}
V_8 = 1 ;
V_24:
F_15 ( V_18 ) ;
F_17 ( V_38 ) ;
return ( V_8 ) ;
}
static int F_10 ( T_2 * V_61 , int V_9 , const T_2 * V_62 ,
const T_2 * V_12 , T_3 * V_18 )
{
int V_15 , V_8 = 0 ;
T_2 * V_60 , * V_63 , * V_64 ;
V_9 -- ;
F_7 ( V_18 ) ;
V_60 = F_8 ( V_18 ) ;
V_64 = F_8 ( V_18 ) ;
V_63 = F_8 ( V_18 ) ;
if ( V_63 == NULL )
goto V_24;
if ( ! F_13 ( V_63 , V_62 ) )
goto V_24;
if ( ! F_37 ( V_64 , V_9 , V_39 , V_40 ) )
goto V_24;
if ( ! F_46 ( V_60 , V_64 , V_63 , V_18 ) )
goto V_24;
if ( ! F_47 ( V_64 , V_64 , V_60 ) )
goto V_24;
if ( V_12 == NULL ) {
if ( ! F_33 ( V_64 , 1 ) )
goto V_24;
} else {
if ( ! F_13 ( V_60 , V_12 ) )
goto V_24;
if ( ! F_48 ( V_64 , V_64 , V_60 ) )
goto V_24;
}
if ( ! F_49 ( V_61 , V_64 ) )
goto V_24;
if ( ! F_33 ( V_61 , 1 ) )
goto V_24;
V_25:
for ( V_15 = 1 ; V_15 < V_23 ; V_15 ++ ) {
T_6 V_65 = F_24 ( V_61 , ( T_6 ) V_36 [ V_15 ] ) ;
T_6 V_66 = F_24 ( V_64 , ( T_6 ) V_36 [ V_15 ] ) ;
if ( V_65 == ( T_6 ) - 1 || V_66 == ( T_6 ) - 1 )
goto V_24;
if ( V_65 == 0 || V_66 == 0 ) {
if ( ! F_48 ( V_61 , V_61 , V_62 ) )
goto V_24;
if ( ! F_48 ( V_64 , V_64 , V_63 ) )
goto V_24;
goto V_25;
}
}
V_8 = 1 ;
V_24:
F_15 ( V_18 ) ;
F_17 ( V_61 ) ;
return ( V_8 ) ;
}
