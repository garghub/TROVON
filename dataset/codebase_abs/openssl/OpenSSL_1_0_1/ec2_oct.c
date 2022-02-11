int F_1 ( const T_1 * V_1 , T_2 * V_2 ,
const T_3 * V_3 , int V_4 , T_4 * V_5 )
{
T_4 * V_6 = NULL ;
T_3 * V_7 , * V_8 , * V_9 , * V_10 ;
int V_11 = 0 , V_12 ;
F_2 () ;
if ( V_5 == NULL )
{
V_5 = V_6 = F_3 () ;
if ( V_5 == NULL )
return 0 ;
}
V_4 = ( V_4 != 0 ) ? 1 : 0 ;
F_4 ( V_5 ) ;
V_7 = F_5 ( V_5 ) ;
V_8 = F_5 ( V_5 ) ;
V_9 = F_5 ( V_5 ) ;
V_10 = F_5 ( V_5 ) ;
if ( V_10 == NULL ) goto V_13;
if ( ! F_6 ( V_8 , V_3 , V_1 -> V_14 ) ) goto V_13;
if ( F_7 ( V_8 ) )
{
if ( ! F_8 ( V_9 , & V_1 -> V_15 , V_1 -> V_14 , V_5 ) ) goto V_13;
}
else
{
if ( ! V_1 -> V_16 -> V_17 ( V_1 , V_7 , V_8 , V_5 ) ) goto V_13;
if ( ! V_1 -> V_16 -> V_18 ( V_1 , V_7 , & V_1 -> V_15 , V_7 , V_5 ) ) goto V_13;
if ( ! F_9 ( V_7 , & V_1 -> V_19 , V_7 ) ) goto V_13;
if ( ! F_9 ( V_7 , V_8 , V_7 ) ) goto V_13;
if ( ! F_10 ( V_10 , V_7 , V_1 -> V_14 , V_5 ) )
{
unsigned long V_13 = F_11 () ;
if ( F_12 ( V_13 ) == V_20 && F_13 ( V_13 ) == V_21 )
{
F_2 () ;
F_14 ( V_22 , V_23 ) ;
}
else
F_14 ( V_22 , V_24 ) ;
goto V_13;
}
V_12 = ( F_15 ( V_10 ) ) ? 1 : 0 ;
if ( ! V_1 -> V_16 -> V_25 ( V_1 , V_9 , V_8 , V_10 , V_5 ) ) goto V_13;
if ( V_12 != V_4 )
{
if ( ! F_9 ( V_9 , V_9 , V_8 ) ) goto V_13;
}
}
if ( ! F_16 ( V_1 , V_2 , V_8 , V_9 , V_5 ) ) goto V_13;
V_11 = 1 ;
V_13:
F_17 ( V_5 ) ;
if ( V_6 != NULL )
F_18 ( V_6 ) ;
return V_11 ;
}
T_5 F_19 ( const T_1 * V_1 , const T_2 * V_2 , T_6 V_26 ,
unsigned char * V_27 , T_5 V_28 , T_4 * V_5 )
{
T_5 V_11 ;
T_4 * V_6 = NULL ;
int V_29 = 0 ;
T_3 * V_8 , * V_9 , * V_30 ;
T_5 V_31 , V_32 , V_33 ;
if ( ( V_26 != V_34 )
&& ( V_26 != V_35 )
&& ( V_26 != V_36 ) )
{
F_14 ( V_37 , V_38 ) ;
goto V_13;
}
if ( F_20 ( V_1 , V_2 ) )
{
if ( V_27 != NULL )
{
if ( V_28 < 1 )
{
F_14 ( V_37 , V_39 ) ;
return 0 ;
}
V_27 [ 0 ] = 0 ;
}
return 1 ;
}
V_31 = ( F_21 ( V_1 ) + 7 ) / 8 ;
V_11 = ( V_26 == V_34 ) ? 1 + V_31 : 1 + 2 * V_31 ;
if ( V_27 != NULL )
{
if ( V_28 < V_11 )
{
F_14 ( V_37 , V_39 ) ;
goto V_13;
}
if ( V_5 == NULL )
{
V_5 = V_6 = F_3 () ;
if ( V_5 == NULL )
return 0 ;
}
F_4 ( V_5 ) ;
V_29 = 1 ;
V_8 = F_5 ( V_5 ) ;
V_9 = F_5 ( V_5 ) ;
V_30 = F_5 ( V_5 ) ;
if ( V_30 == NULL ) goto V_13;
if ( ! F_22 ( V_1 , V_2 , V_8 , V_9 , V_5 ) ) goto V_13;
V_27 [ 0 ] = V_26 ;
if ( ( V_26 != V_35 ) && ! F_7 ( V_8 ) )
{
if ( ! V_1 -> V_16 -> V_18 ( V_1 , V_30 , V_9 , V_8 , V_5 ) ) goto V_13;
if ( F_15 ( V_30 ) ) V_27 [ 0 ] ++ ;
}
V_32 = 1 ;
V_33 = V_31 - F_23 ( V_8 ) ;
if ( V_33 > V_31 )
{
F_14 ( V_37 , V_40 ) ;
goto V_13;
}
while ( V_33 > 0 )
{
V_27 [ V_32 ++ ] = 0 ;
V_33 -- ;
}
V_33 = F_24 ( V_8 , V_27 + V_32 ) ;
V_32 += V_33 ;
if ( V_32 != 1 + V_31 )
{
F_14 ( V_37 , V_40 ) ;
goto V_13;
}
if ( V_26 == V_35 || V_26 == V_36 )
{
V_33 = V_31 - F_23 ( V_9 ) ;
if ( V_33 > V_31 )
{
F_14 ( V_37 , V_40 ) ;
goto V_13;
}
while ( V_33 > 0 )
{
V_27 [ V_32 ++ ] = 0 ;
V_33 -- ;
}
V_33 = F_24 ( V_9 , V_27 + V_32 ) ;
V_32 += V_33 ;
}
if ( V_32 != V_11 )
{
F_14 ( V_37 , V_40 ) ;
goto V_13;
}
}
if ( V_29 )
F_17 ( V_5 ) ;
if ( V_6 != NULL )
F_18 ( V_6 ) ;
return V_11 ;
V_13:
if ( V_29 )
F_17 ( V_5 ) ;
if ( V_6 != NULL )
F_18 ( V_6 ) ;
return 0 ;
}
int F_25 ( const T_1 * V_1 , T_2 * V_2 ,
const unsigned char * V_27 , T_5 V_28 , T_4 * V_5 )
{
T_6 V_26 ;
int V_4 ;
T_4 * V_6 = NULL ;
T_3 * V_8 , * V_9 , * V_30 ;
T_5 V_31 , V_41 ;
int V_11 = 0 ;
if ( V_28 == 0 )
{
F_14 ( V_42 , V_39 ) ;
return 0 ;
}
V_26 = V_27 [ 0 ] ;
V_4 = V_26 & 1 ;
V_26 = V_26 & ~ 1U ;
if ( ( V_26 != 0 ) && ( V_26 != V_34 )
&& ( V_26 != V_35 )
&& ( V_26 != V_36 ) )
{
F_14 ( V_42 , V_43 ) ;
return 0 ;
}
if ( ( V_26 == 0 || V_26 == V_35 ) && V_4 )
{
F_14 ( V_42 , V_43 ) ;
return 0 ;
}
if ( V_26 == 0 )
{
if ( V_28 != 1 )
{
F_14 ( V_42 , V_43 ) ;
return 0 ;
}
return F_26 ( V_1 , V_2 ) ;
}
V_31 = ( F_21 ( V_1 ) + 7 ) / 8 ;
V_41 = ( V_26 == V_34 ) ? 1 + V_31 : 1 + 2 * V_31 ;
if ( V_28 != V_41 )
{
F_14 ( V_42 , V_43 ) ;
return 0 ;
}
if ( V_5 == NULL )
{
V_5 = V_6 = F_3 () ;
if ( V_5 == NULL )
return 0 ;
}
F_4 ( V_5 ) ;
V_8 = F_5 ( V_5 ) ;
V_9 = F_5 ( V_5 ) ;
V_30 = F_5 ( V_5 ) ;
if ( V_30 == NULL ) goto V_13;
if ( ! F_27 ( V_27 + 1 , V_31 , V_8 ) ) goto V_13;
if ( F_28 ( V_8 , & V_1 -> V_44 ) >= 0 )
{
F_14 ( V_42 , V_43 ) ;
goto V_13;
}
if ( V_26 == V_34 )
{
if ( ! F_29 ( V_1 , V_2 , V_8 , V_4 , V_5 ) ) goto V_13;
}
else
{
if ( ! F_27 ( V_27 + 1 + V_31 , V_31 , V_9 ) ) goto V_13;
if ( F_28 ( V_9 , & V_1 -> V_44 ) >= 0 )
{
F_14 ( V_42 , V_43 ) ;
goto V_13;
}
if ( V_26 == V_36 )
{
if ( ! V_1 -> V_16 -> V_18 ( V_1 , V_30 , V_9 , V_8 , V_5 ) ) goto V_13;
if ( V_4 != F_15 ( V_30 ) )
{
F_14 ( V_42 , V_43 ) ;
goto V_13;
}
}
if ( ! F_16 ( V_1 , V_2 , V_8 , V_9 , V_5 ) ) goto V_13;
}
if ( ! F_30 ( V_1 , V_2 , V_5 ) )
{
F_14 ( V_42 , V_45 ) ;
goto V_13;
}
V_11 = 1 ;
V_13:
F_17 ( V_5 ) ;
if ( V_6 != NULL )
F_18 ( V_6 ) ;
return V_11 ;
}
