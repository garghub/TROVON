int F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 , T_3 * V_4 )
{
#ifdef F_2
if ( F_3 () && ! ( V_1 -> V_5 -> V_6 & V_7 )
&& ! ( V_1 -> V_6 & V_8 ) ) {
F_4 ( V_9 , V_10 ) ;
return 0 ;
}
#endif
if ( V_1 -> V_5 -> V_11 )
return V_1 -> V_5 -> V_11 ( V_1 , V_2 , V_3 , V_4 ) ;
#ifdef F_2
if ( F_3 () )
return F_5 ( V_1 , V_2 , V_3 , V_4 ) ;
#endif
return F_6 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static int F_6 ( T_1 * V_1 , int V_2 , T_2 * V_3 ,
T_3 * V_4 )
{
T_2 * V_12 = NULL , * V_13 = NULL , * V_14 = NULL , * V_15 = NULL , * V_16 ;
T_2 V_17 , V_18 , V_19 ;
T_2 * V_20 , * V_21 , * V_22 ;
int V_23 , V_24 , V_25 = - 1 , V_26 = 0 ;
T_4 * V_27 = NULL ;
V_27 = F_7 () ;
if ( V_27 == NULL )
goto V_28;
F_8 ( V_27 ) ;
V_12 = F_9 ( V_27 ) ;
V_13 = F_9 ( V_27 ) ;
V_14 = F_9 ( V_27 ) ;
V_15 = F_9 ( V_27 ) ;
if ( V_15 == NULL )
goto V_28;
V_23 = ( V_2 + 1 ) / 2 ;
V_24 = V_2 - V_23 ;
if ( ! V_1 -> V_26 && ( ( V_1 -> V_26 = F_10 () ) == NULL ) )
goto V_28;
if ( ! V_1 -> V_21 && ( ( V_1 -> V_21 = F_10 () ) == NULL ) )
goto V_28;
if ( ! V_1 -> V_29 && ( ( V_1 -> V_29 = F_10 () ) == NULL ) )
goto V_28;
if ( ! V_1 -> V_22 && ( ( V_1 -> V_22 = F_10 () ) == NULL ) )
goto V_28;
if ( ! V_1 -> V_30 && ( ( V_1 -> V_30 = F_10 () ) == NULL ) )
goto V_28;
if ( ! V_1 -> V_31 && ( ( V_1 -> V_31 = F_10 () ) == NULL ) )
goto V_28;
if ( ! V_1 -> V_32 && ( ( V_1 -> V_32 = F_10 () ) == NULL ) )
goto V_28;
if ( ! V_1 -> V_33 && ( ( V_1 -> V_33 = F_10 () ) == NULL ) )
goto V_28;
F_11 ( V_1 -> V_29 , V_3 ) ;
for (; ; ) {
if ( ! F_12 ( V_1 -> V_22 , V_23 , 0 , NULL , NULL , V_4 ) )
goto V_28;
if ( ! F_13 ( V_14 , V_1 -> V_22 , F_14 () ) )
goto V_28;
if ( ! F_15 ( V_13 , V_14 , V_1 -> V_29 , V_27 ) )
goto V_28;
if ( F_16 ( V_13 ) )
break;
if ( ! F_17 ( V_4 , 2 , V_26 ++ ) )
goto V_28;
}
if ( ! F_17 ( V_4 , 3 , 0 ) )
goto V_28;
for (; ; ) {
unsigned int V_34 = 0 ;
do {
if ( ! F_12 ( V_1 -> V_30 , V_24 , 0 , NULL , NULL , V_4 ) )
goto V_28;
} while ( ( F_18 ( V_1 -> V_22 , V_1 -> V_30 ) == 0 ) && ( ++ V_34 < 3 ) );
if ( V_34 == 3 ) {
V_25 = 0 ;
F_4 ( V_35 , V_36 ) ;
goto V_28;
}
if ( ! F_13 ( V_14 , V_1 -> V_30 , F_14 () ) )
goto V_28;
if ( ! F_15 ( V_13 , V_14 , V_1 -> V_29 , V_27 ) )
goto V_28;
if ( F_16 ( V_13 ) )
break;
if ( ! F_17 ( V_4 , 2 , V_26 ++ ) )
goto V_28;
}
if ( ! F_17 ( V_4 , 3 , 1 ) )
goto V_28;
if ( F_18 ( V_1 -> V_22 , V_1 -> V_30 ) < 0 ) {
V_16 = V_1 -> V_22 ;
V_1 -> V_22 = V_1 -> V_30 ;
V_1 -> V_30 = V_16 ;
}
if ( ! F_19 ( V_1 -> V_26 , V_1 -> V_22 , V_1 -> V_30 , V_27 ) )
goto V_28;
if ( ! F_13 ( V_13 , V_1 -> V_22 , F_14 () ) )
goto V_28;
if ( ! F_13 ( V_14 , V_1 -> V_30 , F_14 () ) )
goto V_28;
if ( ! F_19 ( V_12 , V_13 , V_14 , V_27 ) )
goto V_28;
if ( ! ( V_1 -> V_6 & V_37 ) ) {
V_20 = & V_17 ;
F_20 ( V_20 , V_12 , V_38 ) ;
} else
V_20 = V_12 ;
if ( ! F_21 ( V_1 -> V_21 , V_1 -> V_29 , V_20 , V_27 ) )
goto V_28;
if ( ! ( V_1 -> V_6 & V_37 ) ) {
V_21 = & V_18 ;
F_20 ( V_21 , V_1 -> V_21 , V_38 ) ;
} else
V_21 = V_1 -> V_21 ;
if ( ! F_22 ( V_1 -> V_31 , V_21 , V_13 , V_27 ) )
goto V_28;
if ( ! F_22 ( V_1 -> V_32 , V_21 , V_14 , V_27 ) )
goto V_28;
if ( ! ( V_1 -> V_6 & V_37 ) ) {
V_22 = & V_19 ;
F_20 ( V_22 , V_1 -> V_22 , V_38 ) ;
} else
V_22 = V_1 -> V_22 ;
if ( ! F_21 ( V_1 -> V_33 , V_1 -> V_30 , V_22 , V_27 ) )
goto V_28;
V_25 = 1 ;
V_28:
if ( V_25 == - 1 ) {
F_4 ( V_35 , V_39 ) ;
V_25 = 0 ;
}
if ( V_27 != NULL ) {
F_23 ( V_27 ) ;
F_24 ( V_27 ) ;
}
return V_25 ;
}
