int F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 , T_3 * V_4 )
{
if ( V_1 -> V_5 -> V_6 )
return V_1 -> V_5 -> V_6 ( V_1 , V_2 , V_3 , V_4 ) ;
return F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static int F_2 ( T_1 * V_1 , int V_2 , T_2 * V_3 ,
T_3 * V_4 )
{
T_2 * V_7 = NULL , * V_8 = NULL , * V_9 = NULL , * V_10 = NULL , * V_11 ;
int V_12 , V_13 , V_14 = - 1 , V_15 = 0 ;
T_4 * V_16 = NULL ;
V_16 = F_3 () ;
if ( V_16 == NULL )
goto V_17;
F_4 ( V_16 ) ;
V_7 = F_5 ( V_16 ) ;
V_8 = F_5 ( V_16 ) ;
V_9 = F_5 ( V_16 ) ;
V_10 = F_5 ( V_16 ) ;
if ( V_10 == NULL )
goto V_17;
V_12 = ( V_2 + 1 ) / 2 ;
V_13 = V_2 - V_12 ;
if ( ! V_1 -> V_15 && ( ( V_1 -> V_15 = F_6 () ) == NULL ) )
goto V_17;
if ( ! V_1 -> V_18 && ( ( V_1 -> V_18 = F_7 () ) == NULL ) )
goto V_17;
if ( ! V_1 -> V_19 && ( ( V_1 -> V_19 = F_6 () ) == NULL ) )
goto V_17;
if ( ! V_1 -> V_20 && ( ( V_1 -> V_20 = F_7 () ) == NULL ) )
goto V_17;
if ( ! V_1 -> V_21 && ( ( V_1 -> V_21 = F_7 () ) == NULL ) )
goto V_17;
if ( ! V_1 -> V_22 && ( ( V_1 -> V_22 = F_7 () ) == NULL ) )
goto V_17;
if ( ! V_1 -> V_23 && ( ( V_1 -> V_23 = F_7 () ) == NULL ) )
goto V_17;
if ( ! V_1 -> V_24 && ( ( V_1 -> V_24 = F_7 () ) == NULL ) )
goto V_17;
F_8 ( V_1 -> V_19 , V_3 ) ;
for (; ; ) {
if ( ! F_9 ( V_1 -> V_20 , V_12 , 0 , NULL , NULL , V_4 ) )
goto V_17;
if ( ! F_10 ( V_9 , V_1 -> V_20 , F_11 () ) )
goto V_17;
if ( ! F_12 ( V_8 , V_9 , V_1 -> V_19 , V_16 ) )
goto V_17;
if ( F_13 ( V_8 ) )
break;
if ( ! F_14 ( V_4 , 2 , V_15 ++ ) )
goto V_17;
}
if ( ! F_14 ( V_4 , 3 , 0 ) )
goto V_17;
for (; ; ) {
unsigned int V_25 = 0 ;
do {
if ( ! F_9 ( V_1 -> V_21 , V_13 , 0 , NULL , NULL , V_4 ) )
goto V_17;
} while ( ( F_15 ( V_1 -> V_20 , V_1 -> V_21 ) == 0 ) && ( ++ V_25 < 3 ) );
if ( V_25 == 3 ) {
V_14 = 0 ;
F_16 ( V_26 , V_27 ) ;
goto V_17;
}
if ( ! F_10 ( V_9 , V_1 -> V_21 , F_11 () ) )
goto V_17;
if ( ! F_12 ( V_8 , V_9 , V_1 -> V_19 , V_16 ) )
goto V_17;
if ( F_13 ( V_8 ) )
break;
if ( ! F_14 ( V_4 , 2 , V_15 ++ ) )
goto V_17;
}
if ( ! F_14 ( V_4 , 3 , 1 ) )
goto V_17;
if ( F_15 ( V_1 -> V_20 , V_1 -> V_21 ) < 0 ) {
V_11 = V_1 -> V_20 ;
V_1 -> V_20 = V_1 -> V_21 ;
V_1 -> V_21 = V_11 ;
}
if ( ! F_17 ( V_1 -> V_15 , V_1 -> V_20 , V_1 -> V_21 , V_16 ) )
goto V_17;
if ( ! F_10 ( V_8 , V_1 -> V_20 , F_11 () ) )
goto V_17;
if ( ! F_10 ( V_9 , V_1 -> V_21 , F_11 () ) )
goto V_17;
if ( ! F_17 ( V_7 , V_8 , V_9 , V_16 ) )
goto V_17;
{
T_2 * V_28 = F_6 () ;
if ( V_28 == NULL )
goto V_17;
F_18 ( V_28 , V_7 , V_29 ) ;
if ( ! F_19 ( V_1 -> V_18 , V_1 -> V_19 , V_28 , V_16 ) ) {
F_20 ( V_28 ) ;
goto V_17;
}
F_20 ( V_28 ) ;
}
{
T_2 * V_18 = F_6 () ;
if ( V_18 == NULL )
goto V_17;
F_18 ( V_18 , V_1 -> V_18 , V_29 ) ;
if (
! F_21 ( V_1 -> V_22 , V_18 , V_8 , V_16 )
|| ! F_21 ( V_1 -> V_23 , V_18 , V_9 , V_16 ) ) {
F_20 ( V_18 ) ;
goto V_17;
}
F_20 ( V_18 ) ;
}
{
T_2 * V_20 = F_6 () ;
if ( V_20 == NULL )
goto V_17;
F_18 ( V_20 , V_1 -> V_20 , V_29 ) ;
if ( ! F_19 ( V_1 -> V_24 , V_1 -> V_21 , V_20 , V_16 ) ) {
F_20 ( V_20 ) ;
goto V_17;
}
F_20 ( V_20 ) ;
}
V_14 = 1 ;
V_17:
if ( V_14 == - 1 ) {
F_16 ( V_26 , V_30 ) ;
V_14 = 0 ;
}
if ( V_16 != NULL )
F_22 ( V_16 ) ;
F_23 ( V_16 ) ;
return V_14 ;
}
