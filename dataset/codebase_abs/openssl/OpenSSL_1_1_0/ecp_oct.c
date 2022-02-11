int F_1 ( const T_1 * V_1 ,
T_2 * V_2 ,
const T_3 * V_3 , int V_4 ,
T_4 * V_5 )
{
T_4 * V_6 = NULL ;
T_3 * V_7 , * V_8 , * V_9 , * V_10 ;
int V_11 = 0 ;
F_2 () ;
if ( V_5 == NULL ) {
V_5 = V_6 = F_3 () ;
if ( V_5 == NULL )
return 0 ;
}
V_4 = ( V_4 != 0 ) ;
F_4 ( V_5 ) ;
V_7 = F_5 ( V_5 ) ;
V_8 = F_5 ( V_5 ) ;
V_9 = F_5 ( V_5 ) ;
V_10 = F_5 ( V_5 ) ;
if ( V_10 == NULL )
goto V_12;
if ( ! F_6 ( V_9 , V_3 , V_1 -> V_13 , V_5 ) )
goto V_12;
if ( V_1 -> V_14 -> V_15 == 0 ) {
if ( ! V_1 -> V_14 -> V_16 ( V_1 , V_8 , V_3 , V_5 ) )
goto V_12;
if ( ! V_1 -> V_14 -> V_17 ( V_1 , V_7 , V_8 , V_3 , V_5 ) )
goto V_12;
} else {
if ( ! F_7 ( V_8 , V_3 , V_1 -> V_13 , V_5 ) )
goto V_12;
if ( ! F_8 ( V_7 , V_8 , V_3 , V_1 -> V_13 , V_5 ) )
goto V_12;
}
if ( V_1 -> V_18 ) {
if ( ! F_9 ( V_8 , V_9 , V_1 -> V_13 ) )
goto V_12;
if ( ! F_10 ( V_8 , V_8 , V_9 , V_1 -> V_13 ) )
goto V_12;
if ( ! F_11 ( V_7 , V_7 , V_8 , V_1 -> V_13 ) )
goto V_12;
} else {
if ( V_1 -> V_14 -> V_15 ) {
if ( ! V_1 -> V_14 -> V_15 ( V_1 , V_8 , V_1 -> V_19 , V_5 ) )
goto V_12;
if ( ! F_8 ( V_8 , V_8 , V_9 , V_1 -> V_13 , V_5 ) )
goto V_12;
} else {
if ( ! V_1 -> V_14 -> V_17 ( V_1 , V_8 , V_1 -> V_19 , V_9 , V_5 ) )
goto V_12;
}
if ( ! F_10 ( V_7 , V_7 , V_8 , V_1 -> V_13 ) )
goto V_12;
}
if ( V_1 -> V_14 -> V_15 ) {
if ( ! V_1 -> V_14 -> V_15 ( V_1 , V_8 , V_1 -> V_20 , V_5 ) )
goto V_12;
if ( ! F_10 ( V_7 , V_7 , V_8 , V_1 -> V_13 ) )
goto V_12;
} else {
if ( ! F_10 ( V_7 , V_7 , V_1 -> V_20 , V_1 -> V_13 ) )
goto V_12;
}
if ( ! F_12 ( V_10 , V_7 , V_1 -> V_13 , V_5 ) ) {
unsigned long V_12 = F_13 () ;
if ( F_14 ( V_12 ) == V_21
&& F_15 ( V_12 ) == V_22 ) {
F_2 () ;
F_16 ( V_23 ,
V_24 ) ;
} else
F_16 ( V_23 ,
V_25 ) ;
goto V_12;
}
if ( V_4 != F_17 ( V_10 ) ) {
if ( F_18 ( V_10 ) ) {
int V_26 ;
V_26 = F_19 ( V_9 , V_1 -> V_13 , V_5 ) ;
if ( V_26 == - 2 )
goto V_12;
if ( V_26 == 1 )
F_16 ( V_23 ,
V_27 ) ;
else
F_16 ( V_23 ,
V_24 ) ;
goto V_12;
}
if ( ! F_20 ( V_10 , V_1 -> V_13 , V_10 ) )
goto V_12;
}
if ( V_4 != F_17 ( V_10 ) ) {
F_16 ( V_23 ,
V_28 ) ;
goto V_12;
}
if ( ! F_21 ( V_1 , V_2 , V_9 , V_10 , V_5 ) )
goto V_12;
V_11 = 1 ;
V_12:
F_22 ( V_5 ) ;
F_23 ( V_6 ) ;
return V_11 ;
}
T_5 F_24 ( const T_1 * V_1 , const T_2 * V_2 ,
T_6 V_29 ,
unsigned char * V_30 , T_5 V_31 , T_4 * V_5 )
{
T_5 V_11 ;
T_4 * V_6 = NULL ;
int V_32 = 0 ;
T_3 * V_9 , * V_10 ;
T_5 V_33 , V_34 , V_35 ;
if ( ( V_29 != V_36 )
&& ( V_29 != V_37 )
&& ( V_29 != V_38 ) ) {
F_16 ( V_39 , V_40 ) ;
goto V_12;
}
if ( F_25 ( V_1 , V_2 ) ) {
if ( V_30 != NULL ) {
if ( V_31 < 1 ) {
F_16 ( V_39 , V_41 ) ;
return 0 ;
}
V_30 [ 0 ] = 0 ;
}
return 1 ;
}
V_33 = F_26 ( V_1 -> V_13 ) ;
V_11 =
( V_29 ==
V_36 ) ? 1 + V_33 : 1 + 2 * V_33 ;
if ( V_30 != NULL ) {
if ( V_31 < V_11 ) {
F_16 ( V_39 , V_41 ) ;
goto V_12;
}
if ( V_5 == NULL ) {
V_5 = V_6 = F_3 () ;
if ( V_5 == NULL )
return 0 ;
}
F_4 ( V_5 ) ;
V_32 = 1 ;
V_9 = F_5 ( V_5 ) ;
V_10 = F_5 ( V_5 ) ;
if ( V_10 == NULL )
goto V_12;
if ( ! F_27 ( V_1 , V_2 , V_9 , V_10 , V_5 ) )
goto V_12;
if ( ( V_29 == V_36
|| V_29 == V_38 ) && F_17 ( V_10 ) )
V_30 [ 0 ] = V_29 + 1 ;
else
V_30 [ 0 ] = V_29 ;
V_34 = 1 ;
V_35 = V_33 - F_26 ( V_9 ) ;
if ( V_35 > V_33 ) {
F_16 ( V_39 , V_28 ) ;
goto V_12;
}
while ( V_35 > 0 ) {
V_30 [ V_34 ++ ] = 0 ;
V_35 -- ;
}
V_35 = F_28 ( V_9 , V_30 + V_34 ) ;
V_34 += V_35 ;
if ( V_34 != 1 + V_33 ) {
F_16 ( V_39 , V_28 ) ;
goto V_12;
}
if ( V_29 == V_37
|| V_29 == V_38 ) {
V_35 = V_33 - F_26 ( V_10 ) ;
if ( V_35 > V_33 ) {
F_16 ( V_39 , V_28 ) ;
goto V_12;
}
while ( V_35 > 0 ) {
V_30 [ V_34 ++ ] = 0 ;
V_35 -- ;
}
V_35 = F_28 ( V_10 , V_30 + V_34 ) ;
V_34 += V_35 ;
}
if ( V_34 != V_11 ) {
F_16 ( V_39 , V_28 ) ;
goto V_12;
}
}
if ( V_32 )
F_22 ( V_5 ) ;
F_23 ( V_6 ) ;
return V_11 ;
V_12:
if ( V_32 )
F_22 ( V_5 ) ;
F_23 ( V_6 ) ;
return 0 ;
}
int F_29 ( const T_1 * V_1 , T_2 * V_2 ,
const unsigned char * V_30 , T_5 V_31 , T_4 * V_5 )
{
T_6 V_29 ;
int V_4 ;
T_4 * V_6 = NULL ;
T_3 * V_9 , * V_10 ;
T_5 V_33 , V_42 ;
int V_11 = 0 ;
if ( V_31 == 0 ) {
F_16 ( V_43 , V_41 ) ;
return 0 ;
}
V_29 = V_30 [ 0 ] ;
V_4 = V_29 & 1 ;
V_29 = V_29 & ~ 1U ;
if ( ( V_29 != 0 ) && ( V_29 != V_36 )
&& ( V_29 != V_37 )
&& ( V_29 != V_38 ) ) {
F_16 ( V_43 , V_44 ) ;
return 0 ;
}
if ( ( V_29 == 0 || V_29 == V_37 ) && V_4 ) {
F_16 ( V_43 , V_44 ) ;
return 0 ;
}
if ( V_29 == 0 ) {
if ( V_31 != 1 ) {
F_16 ( V_43 , V_44 ) ;
return 0 ;
}
return F_30 ( V_1 , V_2 ) ;
}
V_33 = F_26 ( V_1 -> V_13 ) ;
V_42 =
( V_29 ==
V_36 ) ? 1 + V_33 : 1 + 2 * V_33 ;
if ( V_31 != V_42 ) {
F_16 ( V_43 , V_44 ) ;
return 0 ;
}
if ( V_5 == NULL ) {
V_5 = V_6 = F_3 () ;
if ( V_5 == NULL )
return 0 ;
}
F_4 ( V_5 ) ;
V_9 = F_5 ( V_5 ) ;
V_10 = F_5 ( V_5 ) ;
if ( V_10 == NULL )
goto V_12;
if ( ! F_31 ( V_30 + 1 , V_33 , V_9 ) )
goto V_12;
if ( F_32 ( V_9 , V_1 -> V_13 ) >= 0 ) {
F_16 ( V_43 , V_44 ) ;
goto V_12;
}
if ( V_29 == V_36 ) {
if ( ! F_33
( V_1 , V_2 , V_9 , V_4 , V_5 ) )
goto V_12;
} else {
if ( ! F_31 ( V_30 + 1 + V_33 , V_33 , V_10 ) )
goto V_12;
if ( F_32 ( V_10 , V_1 -> V_13 ) >= 0 ) {
F_16 ( V_43 , V_44 ) ;
goto V_12;
}
if ( V_29 == V_38 ) {
if ( V_4 != F_17 ( V_10 ) ) {
F_16 ( V_43 , V_44 ) ;
goto V_12;
}
}
if ( ! F_21 ( V_1 , V_2 , V_9 , V_10 , V_5 ) )
goto V_12;
}
V_11 = 1 ;
V_12:
F_22 ( V_5 ) ;
F_23 ( V_6 ) ;
return V_11 ;
}
