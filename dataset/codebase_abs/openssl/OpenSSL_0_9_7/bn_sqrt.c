T_1 * F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
T_1 * V_5 = V_1 ;
int V_6 = 1 ;
int V_7 ;
T_1 * V_8 , * V_9 , * V_10 , * V_11 , * V_12 ;
int V_13 , V_14 , V_15 ;
if ( ! F_2 ( V_3 ) || F_3 ( V_3 , 1 ) )
{
if ( F_3 ( V_3 , 2 ) )
{
if ( V_5 == NULL )
V_5 = F_4 () ;
if ( V_5 == NULL )
goto V_16;
if ( ! F_5 ( V_5 , F_6 ( V_2 , 0 ) ) )
{
F_7 ( V_5 ) ;
return NULL ;
}
return V_5 ;
}
F_8 ( V_17 , V_18 ) ;
return ( NULL ) ;
}
if ( F_9 ( V_2 ) || F_10 ( V_2 ) )
{
if ( V_5 == NULL )
V_5 = F_4 () ;
if ( V_5 == NULL )
goto V_16;
if ( ! F_5 ( V_5 , F_10 ( V_2 ) ) )
{
F_7 ( V_5 ) ;
return NULL ;
}
return V_5 ;
}
#if 0
r = BN_kronecker(a, p, ctx);
if (r < -1) return NULL;
if (r == -1)
{
BNerr(BN_F_BN_MOD_SQRT, BN_R_NOT_A_SQUARE);
return(NULL);
}
#endif
F_11 ( V_4 ) ;
V_8 = F_12 ( V_4 ) ;
V_9 = F_12 ( V_4 ) ;
V_10 = F_12 ( V_4 ) ;
V_11 = F_12 ( V_4 ) ;
V_12 = F_12 ( V_4 ) ;
if ( V_12 == NULL ) goto V_16;
if ( V_5 == NULL )
V_5 = F_4 () ;
if ( V_5 == NULL ) goto V_16;
V_13 = 1 ;
while ( ! F_6 ( V_3 , V_13 ) )
V_13 ++ ;
if ( V_13 == 1 )
{
if ( ! F_13 ( V_9 , V_3 , 2 ) ) goto V_16;
V_9 -> V_19 = 0 ;
if ( ! F_14 ( V_9 , 1 ) ) goto V_16;
if ( ! F_15 ( V_5 , V_2 , V_9 , V_3 , V_4 ) ) goto V_16;
V_6 = 0 ;
goto V_16;
}
if ( V_13 == 2 )
{
if ( V_2 -> V_19 || F_16 ( V_2 , V_3 ) >= 0 )
{
if ( ! F_17 ( V_11 , V_2 , V_3 , V_4 ) ) goto V_16;
V_2 = V_11 ;
}
if ( ! F_18 ( V_10 , V_2 , V_3 ) ) goto V_16;
if ( ! F_13 ( V_9 , V_3 , 3 ) ) goto V_16;
V_9 -> V_19 = 0 ;
if ( ! F_15 ( V_8 , V_10 , V_9 , V_3 , V_4 ) ) goto V_16;
if ( ! F_19 ( V_12 , V_8 , V_3 , V_4 ) ) goto V_16;
if ( ! F_20 ( V_10 , V_10 , V_12 , V_3 , V_4 ) ) goto V_16;
if ( ! F_21 ( V_10 , 1 ) ) goto V_16;
if ( ! F_20 ( V_11 , V_2 , V_8 , V_3 , V_4 ) ) goto V_16;
if ( ! F_20 ( V_11 , V_11 , V_10 , V_3 , V_4 ) ) goto V_16;
if ( ! F_22 ( V_5 , V_11 ) ) goto V_16;
V_6 = 0 ;
goto V_16;
}
if ( ! F_22 ( V_9 , V_3 ) ) goto V_16;
V_9 -> V_19 = 0 ;
V_14 = 2 ;
do
{
if ( V_14 < 22 )
{
if ( ! F_5 ( V_12 , V_14 ) ) goto V_16;
}
else
{
if ( ! F_23 ( V_12 , F_24 ( V_3 ) , 0 , 0 ) ) goto V_16;
if ( F_16 ( V_12 , V_3 ) >= 0 )
{
if ( ! ( V_3 -> V_19 ? V_20 : V_21 ) ( V_12 , V_12 , V_3 ) ) goto V_16;
}
if ( F_9 ( V_12 ) )
if ( ! F_5 ( V_12 , V_14 ) ) goto V_16;
}
V_7 = F_25 ( V_12 , V_9 , V_4 ) ;
if ( V_7 < - 1 ) goto V_16;
if ( V_7 == 0 )
{
F_8 ( V_17 , V_18 ) ;
goto V_16;
}
}
while ( V_7 == 1 && ++ V_14 < 82 );
if ( V_7 != - 1 )
{
F_8 ( V_17 , V_22 ) ;
goto V_16;
}
if ( ! F_13 ( V_9 , V_9 , V_13 ) ) goto V_16;
if ( ! F_15 ( V_12 , V_12 , V_9 , V_3 , V_4 ) ) goto V_16;
if ( F_10 ( V_12 ) )
{
F_8 ( V_17 , V_18 ) ;
goto V_16;
}
if ( ! F_26 ( V_10 , V_9 ) ) goto V_16;
if ( F_9 ( V_10 ) )
{
if ( ! F_17 ( V_10 , V_2 , V_3 , V_4 ) ) goto V_16;
if ( F_9 ( V_10 ) )
{
if ( ! F_27 ( V_5 ) ) goto V_16;
V_6 = 0 ;
goto V_16;
}
else
if ( ! F_28 ( V_11 ) ) goto V_16;
}
else
{
if ( ! F_15 ( V_11 , V_2 , V_10 , V_3 , V_4 ) ) goto V_16;
if ( F_9 ( V_11 ) )
{
if ( ! F_27 ( V_5 ) ) goto V_16;
V_6 = 0 ;
goto V_16;
}
}
if ( ! F_19 ( V_8 , V_11 , V_3 , V_4 ) ) goto V_16;
if ( ! F_20 ( V_8 , V_8 , V_2 , V_3 , V_4 ) ) goto V_16;
if ( ! F_20 ( V_11 , V_11 , V_2 , V_3 , V_4 ) ) goto V_16;
while ( 1 )
{
if ( F_10 ( V_8 ) )
{
if ( ! F_22 ( V_5 , V_11 ) ) goto V_16;
V_6 = 0 ;
goto V_16;
}
V_14 = 1 ;
if ( ! F_19 ( V_10 , V_8 , V_3 , V_4 ) ) goto V_16;
while ( ! F_10 ( V_10 ) )
{
V_14 ++ ;
if ( V_14 == V_13 )
{
F_8 ( V_17 , V_23 ) ;
goto V_16;
}
if ( ! F_20 ( V_10 , V_10 , V_10 , V_3 , V_4 ) ) goto V_16;
}
if ( ! F_22 ( V_10 , V_12 ) ) goto V_16;
for ( V_15 = V_13 - V_14 - 1 ; V_15 > 0 ; V_15 -- )
{
if ( ! F_19 ( V_10 , V_10 , V_3 , V_4 ) ) goto V_16;
}
if ( ! F_20 ( V_12 , V_10 , V_10 , V_3 , V_4 ) ) goto V_16;
if ( ! F_20 ( V_11 , V_11 , V_10 , V_3 , V_4 ) ) goto V_16;
if ( ! F_20 ( V_8 , V_8 , V_12 , V_3 , V_4 ) ) goto V_16;
V_13 = V_14 ;
}
V_16:
if ( V_6 )
{
if ( V_5 != NULL && V_5 != V_1 )
{
F_29 ( V_5 ) ;
}
V_5 = NULL ;
}
F_30 ( V_4 ) ;
return V_5 ;
}
