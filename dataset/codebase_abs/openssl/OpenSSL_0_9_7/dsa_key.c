int F_1 ( T_1 * V_1 )
{
int V_2 = 0 ;
T_2 * V_3 = NULL ;
T_3 * V_4 = NULL , * V_5 = NULL ;
if ( ( V_3 = F_2 () ) == NULL ) goto V_6;
if ( V_1 -> V_5 == NULL )
{
if ( ( V_5 = F_3 () ) == NULL ) goto V_6;
}
else
V_5 = V_1 -> V_5 ;
do
if ( ! F_4 ( V_5 , V_1 -> V_7 ) ) goto V_6;
while ( F_5 ( V_5 ) );
if ( V_1 -> V_4 == NULL )
{
if ( ( V_4 = F_3 () ) == NULL ) goto V_6;
}
else
V_4 = V_1 -> V_4 ;
if ( ! F_6 ( V_4 , V_1 -> V_8 , V_5 , V_1 -> V_9 , V_3 ) ) goto V_6;
V_1 -> V_5 = V_5 ;
V_1 -> V_4 = V_4 ;
V_2 = 1 ;
V_6:
if ( ( V_4 != NULL ) && ( V_1 -> V_4 == NULL ) ) F_7 ( V_4 ) ;
if ( ( V_5 != NULL ) && ( V_1 -> V_5 == NULL ) ) F_7 ( V_5 ) ;
if ( V_3 != NULL ) F_8 ( V_3 ) ;
return ( V_2 ) ;
}
