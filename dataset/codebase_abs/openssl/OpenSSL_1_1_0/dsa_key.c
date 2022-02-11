int F_1 ( T_1 * V_1 )
{
if ( V_1 -> V_2 -> V_3 )
return V_1 -> V_2 -> V_3 ( V_1 ) ;
return F_2 ( V_1 ) ;
}
static int F_2 ( T_1 * V_1 )
{
int V_4 = 0 ;
T_2 * V_5 = NULL ;
T_3 * V_6 = NULL , * V_7 = NULL ;
if ( ( V_5 = F_3 () ) == NULL )
goto V_8;
if ( V_1 -> V_7 == NULL ) {
if ( ( V_7 = F_4 () ) == NULL )
goto V_8;
} else
V_7 = V_1 -> V_7 ;
do
if ( ! F_5 ( V_7 , V_1 -> V_9 ) )
goto V_8;
while ( F_6 ( V_7 ) ) ;
if ( V_1 -> V_6 == NULL ) {
if ( ( V_6 = F_7 () ) == NULL )
goto V_8;
} else
V_6 = V_1 -> V_6 ;
{
T_3 * V_10 = F_7 () ;
if ( V_10 == NULL )
goto V_8;
F_8 ( V_10 , V_7 , V_11 ) ;
if ( ! F_9 ( V_6 , V_1 -> V_12 , V_10 , V_1 -> V_13 , V_5 ) ) {
F_10 ( V_10 ) ;
goto V_8;
}
F_10 ( V_10 ) ;
}
V_1 -> V_7 = V_7 ;
V_1 -> V_6 = V_6 ;
V_4 = 1 ;
V_8:
if ( V_6 != V_1 -> V_6 )
F_10 ( V_6 ) ;
if ( V_7 != V_1 -> V_7 )
F_10 ( V_7 ) ;
F_11 ( V_5 ) ;
return ( V_4 ) ;
}
