static int F_1 ( const T_1 * const * V_1 ,
const T_1 * const * V_2 )
{
return F_2 ( ( * V_1 ) -> V_3 -> V_4 , ( * V_2 ) -> V_3 -> V_4 ) ;
}
T_1 * F_3 ( const T_2 * V_5 ,
const T_3 * V_6 )
{
return F_4 ( V_5 -> V_7 , V_6 ) ;
}
T_1 * F_5 ( T_2 * V_5 ,
T_4 * V_3 ,
T_1 * V_8 ,
T_5 * V_9 )
{
T_1 * V_10 ;
V_10 = F_6 ( sizeof( T_1 ) ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_3 = V_3 ;
V_10 -> V_8 = V_8 ;
V_10 -> V_11 = 0 ;
if ( V_5 )
{
if ( F_7 ( V_3 -> V_4 ) == V_12 )
{
if ( V_5 -> V_13 )
goto V_14;
V_5 -> V_13 = V_10 ;
}
else
{
if ( ! V_5 -> V_7 )
V_5 -> V_7 = F_8 () ;
if ( ! V_5 -> V_7 )
goto V_14;
if ( ! F_9 ( V_5 -> V_7 , V_10 ) )
goto V_14;
}
}
if ( V_9 )
{
if ( ! V_9 -> V_15 )
V_9 -> V_15 = F_10 () ;
if ( ! V_9 -> V_15 )
goto V_14;
if ( ! F_11 ( V_9 -> V_15 , V_3 ) )
goto V_14;
}
if ( V_8 )
V_8 -> V_11 ++ ;
return V_10 ;
V_14:
F_12 ( V_10 ) ;
return 0 ;
}
void F_12 ( T_1 * V_10 )
{
F_13 ( V_10 ) ;
}
