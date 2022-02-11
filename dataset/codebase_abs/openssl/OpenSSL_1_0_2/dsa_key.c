int F_1 ( T_1 * V_1 )
{
# ifdef F_2
if ( F_3 () && ! ( V_1 -> V_2 -> V_3 & V_4 )
&& ! ( V_1 -> V_3 & V_5 ) ) {
F_4 ( V_6 , V_7 ) ;
return 0 ;
}
# endif
if ( V_1 -> V_2 -> V_8 )
return V_1 -> V_2 -> V_8 ( V_1 ) ;
# ifdef F_2
if ( F_3 () )
return F_5 ( V_1 ) ;
# endif
return F_6 ( V_1 ) ;
}
static int F_6 ( T_1 * V_1 )
{
int V_9 = 0 ;
T_2 * V_10 = NULL ;
T_3 * V_11 = NULL , * V_12 = NULL ;
if ( ( V_10 = F_7 () ) == NULL )
goto V_13;
if ( V_1 -> V_12 == NULL ) {
if ( ( V_12 = F_8 () ) == NULL )
goto V_13;
} else
V_12 = V_1 -> V_12 ;
do
if ( ! F_9 ( V_12 , V_1 -> V_14 ) )
goto V_13;
while ( F_10 ( V_12 ) ) ;
if ( V_1 -> V_11 == NULL ) {
if ( ( V_11 = F_8 () ) == NULL )
goto V_13;
} else
V_11 = V_1 -> V_11 ;
{
T_3 V_15 ;
T_3 * V_16 ;
if ( ( V_1 -> V_3 & V_17 ) == 0 ) {
F_11 ( & V_15 ) ;
V_16 = & V_15 ;
F_12 ( V_16 , V_12 , V_18 ) ;
} else
V_16 = V_12 ;
if ( ! F_13 ( V_11 , V_1 -> V_19 , V_16 , V_1 -> V_20 , V_10 ) )
goto V_13;
}
V_1 -> V_12 = V_12 ;
V_1 -> V_11 = V_11 ;
V_9 = 1 ;
V_13:
if ( ( V_11 != NULL ) && ( V_1 -> V_11 == NULL ) )
F_14 ( V_11 ) ;
if ( ( V_12 != NULL ) && ( V_1 -> V_12 == NULL ) )
F_14 ( V_12 ) ;
if ( V_10 != NULL )
F_15 ( V_10 ) ;
return ( V_9 ) ;
}
