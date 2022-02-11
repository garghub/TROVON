int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
T_1 * V_5 , * V_6 , * V_7 ;
int V_8 = 0 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
F_3 ( V_4 ) ;
V_5 = F_4 ( V_4 ) ;
V_6 = F_4 ( V_4 ) ;
if ( V_5 == NULL || V_6 == NULL )
goto V_9;
if ( F_5 ( V_5 , V_2 ) == NULL )
goto V_9;
if ( F_5 ( V_6 , V_3 ) == NULL )
goto V_9;
V_5 -> V_10 = 0 ;
V_6 -> V_10 = 0 ;
if ( F_6 ( V_5 , V_6 ) < 0 ) {
V_7 = V_5 ;
V_5 = V_6 ;
V_6 = V_7 ;
}
V_7 = F_7 ( V_5 , V_6 ) ;
if ( V_7 == NULL )
goto V_9;
if ( F_5 ( V_1 , V_7 ) == NULL )
goto V_9;
V_8 = 1 ;
V_9:
F_8 ( V_4 ) ;
F_2 ( V_1 ) ;
return ( V_8 ) ;
}
static T_1 * F_7 ( T_1 * V_5 , T_1 * V_6 )
{
T_1 * V_7 ;
int V_11 = 0 ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
while ( ! F_9 ( V_6 ) ) {
if ( F_10 ( V_5 ) ) {
if ( F_10 ( V_6 ) ) {
if ( ! F_11 ( V_5 , V_5 , V_6 ) )
goto V_9;
if ( ! F_12 ( V_5 , V_5 ) )
goto V_9;
if ( F_6 ( V_5 , V_6 ) < 0 ) {
V_7 = V_5 ;
V_5 = V_6 ;
V_6 = V_7 ;
}
} else {
if ( ! F_12 ( V_6 , V_6 ) )
goto V_9;
if ( F_6 ( V_5 , V_6 ) < 0 ) {
V_7 = V_5 ;
V_5 = V_6 ;
V_6 = V_7 ;
}
}
} else {
if ( F_10 ( V_6 ) ) {
if ( ! F_12 ( V_5 , V_5 ) )
goto V_9;
if ( F_6 ( V_5 , V_6 ) < 0 ) {
V_7 = V_5 ;
V_5 = V_6 ;
V_6 = V_7 ;
}
} else {
if ( ! F_12 ( V_5 , V_5 ) )
goto V_9;
if ( ! F_12 ( V_6 , V_6 ) )
goto V_9;
V_11 ++ ;
}
}
}
if ( V_11 ) {
if ( ! F_13 ( V_5 , V_5 , V_11 ) )
goto V_9;
}
F_2 ( V_5 ) ;
return ( V_5 ) ;
V_9:
return ( NULL ) ;
}
T_1 * F_14 ( T_1 * V_12 ,
const T_1 * V_5 , const T_1 * V_13 , T_2 * V_4 )
{
T_1 * V_14 ;
int V_15 ;
V_14 = F_15 ( V_12 , V_5 , V_13 , V_4 , & V_15 ) ;
if ( V_15 )
F_16 ( V_16 , V_17 ) ;
return V_14 ;
}
T_1 * F_15 ( T_1 * V_12 ,
const T_1 * V_5 , const T_1 * V_13 , T_2 * V_4 ,
int * V_18 )
{
T_1 * V_19 , * V_20 , * V_21 , * V_22 , * V_23 , * V_24 , * V_25 , * V_26 = NULL ;
T_1 * V_8 = NULL ;
int V_27 ;
if ( V_18 )
* V_18 = 0 ;
if ( ( F_17 ( V_5 , V_28 ) != 0 )
|| ( F_17 ( V_13 , V_28 ) != 0 ) ) {
return F_18 ( V_12 , V_5 , V_13 , V_4 ) ;
}
F_2 ( V_5 ) ;
F_2 ( V_13 ) ;
F_3 ( V_4 ) ;
V_19 = F_4 ( V_4 ) ;
V_20 = F_4 ( V_4 ) ;
V_21 = F_4 ( V_4 ) ;
V_24 = F_4 ( V_4 ) ;
V_23 = F_4 ( V_4 ) ;
V_22 = F_4 ( V_4 ) ;
V_25 = F_4 ( V_4 ) ;
if ( V_25 == NULL )
goto V_9;
if ( V_12 == NULL )
V_26 = F_19 () ;
else
V_26 = V_12 ;
if ( V_26 == NULL )
goto V_9;
F_20 ( V_21 ) ;
F_21 ( V_22 ) ;
if ( F_5 ( V_20 , V_5 ) == NULL )
goto V_9;
if ( F_5 ( V_19 , V_13 ) == NULL )
goto V_9;
V_19 -> V_10 = 0 ;
if ( V_20 -> V_10 || ( F_22 ( V_20 , V_19 ) >= 0 ) ) {
if ( ! F_23 ( V_20 , V_20 , V_19 , V_4 ) )
goto V_9;
}
V_27 = - 1 ;
if ( F_10 ( V_13 ) && ( F_24 ( V_13 ) <= 2048 ) ) {
int V_29 ;
while ( ! F_9 ( V_20 ) ) {
V_29 = 0 ;
while ( ! F_25 ( V_20 , V_29 ) ) {
V_29 ++ ;
if ( F_10 ( V_21 ) ) {
if ( ! F_26 ( V_21 , V_21 , V_13 ) )
goto V_9;
}
if ( ! F_12 ( V_21 , V_21 ) )
goto V_9;
}
if ( V_29 > 0 ) {
if ( ! F_27 ( V_20 , V_20 , V_29 ) )
goto V_9;
}
V_29 = 0 ;
while ( ! F_25 ( V_19 , V_29 ) ) {
V_29 ++ ;
if ( F_10 ( V_22 ) ) {
if ( ! F_26 ( V_22 , V_22 , V_13 ) )
goto V_9;
}
if ( ! F_12 ( V_22 , V_22 ) )
goto V_9;
}
if ( V_29 > 0 ) {
if ( ! F_27 ( V_19 , V_19 , V_29 ) )
goto V_9;
}
if ( F_22 ( V_20 , V_19 ) >= 0 ) {
if ( ! F_26 ( V_21 , V_21 , V_22 ) )
goto V_9;
if ( ! F_28 ( V_20 , V_20 , V_19 ) )
goto V_9;
} else {
if ( ! F_26 ( V_22 , V_22 , V_21 ) )
goto V_9;
if ( ! F_28 ( V_19 , V_19 , V_20 ) )
goto V_9;
}
}
} else {
while ( ! F_9 ( V_20 ) ) {
T_1 * V_30 ;
if ( F_24 ( V_19 ) == F_24 ( V_20 ) ) {
if ( ! F_20 ( V_24 ) )
goto V_9;
if ( ! F_11 ( V_23 , V_19 , V_20 ) )
goto V_9;
} else if ( F_24 ( V_19 ) == F_24 ( V_20 ) + 1 ) {
if ( ! F_29 ( V_25 , V_20 ) )
goto V_9;
if ( F_22 ( V_19 , V_25 ) < 0 ) {
if ( ! F_20 ( V_24 ) )
goto V_9;
if ( ! F_11 ( V_23 , V_19 , V_20 ) )
goto V_9;
} else {
if ( ! F_11 ( V_23 , V_19 , V_25 ) )
goto V_9;
if ( ! F_30 ( V_24 , V_25 , V_20 ) )
goto V_9;
if ( F_22 ( V_19 , V_24 ) < 0 ) {
if ( ! F_31 ( V_24 , 2 ) )
goto V_9;
} else {
if ( ! F_31 ( V_24 , 3 ) )
goto V_9;
if ( ! F_11 ( V_23 , V_23 , V_20 ) )
goto V_9;
}
}
} else {
if ( ! F_32 ( V_24 , V_23 , V_19 , V_20 , V_4 ) )
goto V_9;
}
V_30 = V_19 ;
V_19 = V_20 ;
V_20 = V_23 ;
if ( F_33 ( V_24 ) ) {
if ( ! F_30 ( V_30 , V_21 , V_22 ) )
goto V_9;
} else {
if ( F_34 ( V_24 , 2 ) ) {
if ( ! F_29 ( V_30 , V_21 ) )
goto V_9;
} else if ( F_34 ( V_24 , 4 ) ) {
if ( ! F_13 ( V_30 , V_21 , 2 ) )
goto V_9;
} else if ( V_24 -> V_31 == 1 ) {
if ( ! F_5 ( V_30 , V_21 ) )
goto V_9;
if ( ! F_35 ( V_30 , V_24 -> V_32 [ 0 ] ) )
goto V_9;
} else {
if ( ! F_36 ( V_30 , V_24 , V_21 , V_4 ) )
goto V_9;
}
if ( ! F_30 ( V_30 , V_30 , V_22 ) )
goto V_9;
}
V_23 = V_22 ;
V_22 = V_21 ;
V_21 = V_30 ;
V_27 = - V_27 ;
}
}
if ( V_27 < 0 ) {
if ( ! F_11 ( V_22 , V_13 , V_22 ) )
goto V_9;
}
if ( F_33 ( V_19 ) ) {
if ( ! V_22 -> V_10 && F_22 ( V_22 , V_13 ) < 0 ) {
if ( ! F_5 ( V_26 , V_22 ) )
goto V_9;
} else {
if ( ! F_23 ( V_26 , V_22 , V_13 , V_4 ) )
goto V_9;
}
} else {
if ( V_18 )
* V_18 = 1 ;
goto V_9;
}
V_8 = V_26 ;
V_9:
if ( ( V_8 == NULL ) && ( V_12 == NULL ) )
F_37 ( V_26 ) ;
F_8 ( V_4 ) ;
F_2 ( V_8 ) ;
return ( V_8 ) ;
}
static T_1 * F_18 ( T_1 * V_12 ,
const T_1 * V_5 , const T_1 * V_13 ,
T_2 * V_4 )
{
T_1 * V_19 , * V_20 , * V_21 , * V_22 , * V_23 , * V_24 , * V_25 , * V_26 = NULL ;
T_1 * V_8 = NULL ;
int V_27 ;
F_2 ( V_5 ) ;
F_2 ( V_13 ) ;
F_3 ( V_4 ) ;
V_19 = F_4 ( V_4 ) ;
V_20 = F_4 ( V_4 ) ;
V_21 = F_4 ( V_4 ) ;
V_24 = F_4 ( V_4 ) ;
V_23 = F_4 ( V_4 ) ;
V_22 = F_4 ( V_4 ) ;
V_25 = F_4 ( V_4 ) ;
if ( V_25 == NULL )
goto V_9;
if ( V_12 == NULL )
V_26 = F_19 () ;
else
V_26 = V_12 ;
if ( V_26 == NULL )
goto V_9;
F_20 ( V_21 ) ;
F_21 ( V_22 ) ;
if ( F_5 ( V_20 , V_5 ) == NULL )
goto V_9;
if ( F_5 ( V_19 , V_13 ) == NULL )
goto V_9;
V_19 -> V_10 = 0 ;
if ( V_20 -> V_10 || ( F_22 ( V_20 , V_19 ) >= 0 ) ) {
{
T_1 V_33 ;
F_38 ( & V_33 ) ;
F_39 ( & V_33 , V_20 , V_28 ) ;
if ( ! F_23 ( V_20 , & V_33 , V_19 , V_4 ) )
goto V_9;
}
}
V_27 = - 1 ;
while ( ! F_9 ( V_20 ) ) {
T_1 * V_30 ;
{
T_1 V_34 ;
F_38 ( & V_34 ) ;
F_39 ( & V_34 , V_19 , V_28 ) ;
if ( ! F_32 ( V_24 , V_23 , & V_34 , V_20 , V_4 ) )
goto V_9;
}
V_30 = V_19 ;
V_19 = V_20 ;
V_20 = V_23 ;
if ( ! F_36 ( V_30 , V_24 , V_21 , V_4 ) )
goto V_9;
if ( ! F_30 ( V_30 , V_30 , V_22 ) )
goto V_9;
V_23 = V_22 ;
V_22 = V_21 ;
V_21 = V_30 ;
V_27 = - V_27 ;
}
if ( V_27 < 0 ) {
if ( ! F_11 ( V_22 , V_13 , V_22 ) )
goto V_9;
}
if ( F_33 ( V_19 ) ) {
if ( ! V_22 -> V_10 && F_22 ( V_22 , V_13 ) < 0 ) {
if ( ! F_5 ( V_26 , V_22 ) )
goto V_9;
} else {
if ( ! F_23 ( V_26 , V_22 , V_13 , V_4 ) )
goto V_9;
}
} else {
F_16 ( V_35 , V_17 ) ;
goto V_9;
}
V_8 = V_26 ;
V_9:
if ( ( V_8 == NULL ) && ( V_12 == NULL ) )
F_37 ( V_26 ) ;
F_8 ( V_4 ) ;
F_2 ( V_8 ) ;
return ( V_8 ) ;
}
