int F_1 ( T_1 * V_1 )
{
int V_2 = 0 ;
unsigned int V_3 ;
T_2 * V_4 = NULL ;
T_3 * V_5 = NULL , * V_6 = NULL ;
if ( ( V_4 = F_2 () ) == NULL ) goto V_7;
if ( V_1 -> V_6 == NULL )
{
if ( ( V_6 = F_3 () ) == NULL ) goto V_7;
}
else
V_6 = V_1 -> V_6 ;
V_3 = F_4 ( V_1 -> V_8 ) ;
for (; ; )
{
F_5 ( V_6 , V_3 , 1 , 0 ) ;
if ( F_6 ( V_6 , V_1 -> V_8 ) >= 0 )
F_7 ( V_6 , V_6 , V_1 -> V_8 ) ;
if ( ! F_8 ( V_6 ) ) break;
}
if ( V_1 -> V_5 == NULL )
{
if ( ( V_5 = F_3 () ) == NULL ) goto V_7;
}
else
V_5 = V_1 -> V_5 ;
if ( ! F_9 ( V_5 , V_1 -> V_9 , V_6 , V_1 -> V_10 , V_4 ) ) goto V_7;
V_1 -> V_6 = V_6 ;
V_1 -> V_5 = V_5 ;
V_2 = 1 ;
V_7:
if ( ( V_5 != NULL ) && ( V_1 -> V_5 == NULL ) ) F_10 ( V_5 ) ;
if ( ( V_6 != NULL ) && ( V_1 -> V_6 == NULL ) ) F_10 ( V_6 ) ;
if ( V_4 != NULL ) F_11 ( V_4 ) ;
return ( V_2 ) ;
}
