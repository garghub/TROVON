static int F_1 ( const T_1 * const * V_1 ,
const T_1 * const * V_2 )
{
return F_2 ( ( * V_1 ) -> V_3 , ( * V_2 ) -> V_3 ) ;
}
static void F_3 ( T_1 * V_4 )
{
if ( V_4 -> V_3 )
F_4 ( V_4 -> V_3 ) ;
F_5 ( V_4 ) ;
}
static T_1 * F_6 ( T_2 * V_5 , T_3 * V_6 )
{
T_1 V_7 ;
int V_8 ;
V_7 . V_3 = V_6 ;
V_8 = F_7 ( V_5 -> V_9 , & V_7 ) ;
if ( V_8 == - 1 )
return NULL ;
return F_8 ( V_5 -> V_9 , V_8 ) ;
}
int F_9 ( T_4 * V_10 , T_5 * V_9 )
{
T_6 * V_4 ;
T_1 * V_11 = NULL ;
T_7 * V_12 ;
T_2 * V_5 = V_10 -> V_13 ;
int V_14 ;
int V_15 = 0 ;
if ( F_10 ( V_9 ) == 0 )
{
V_15 = - 1 ;
goto V_16;
}
V_5 -> V_9 = F_11 ( F_1 ) ;
for ( V_14 = 0 ; V_14 < F_10 ( V_9 ) ; V_14 ++ )
{
V_4 = F_12 ( V_9 , V_14 ) ;
if ( ( F_13 ( V_4 -> V_3 ) == V_17 )
|| ( F_13 ( V_4 -> V_18 ) == V_17 ) )
{
V_15 = - 1 ;
goto V_16;
}
if ( F_6 ( V_5 , V_4 -> V_3 ) != NULL )
{
V_15 = - 1 ;
goto V_16;
}
V_12 = F_14 ( V_5 , V_4 -> V_18 ) ;
if ( ! V_12 && ! V_5 -> V_19 )
continue;
if ( ! V_12 )
{
V_12 = F_15 ( NULL , V_4 -> V_18 ,
V_5 -> V_19 -> V_20
& V_21 ) ;
if ( ! V_12 )
goto V_16;
V_12 -> V_22 = V_5 -> V_19 -> V_22 ;
V_4 -> V_18 = NULL ;
V_12 -> V_20 |= V_23 ;
V_12 -> V_20 |= V_24 ;
if ( ! F_16 ( V_5 -> V_12 , V_12 ) )
{
F_17 ( V_12 ) ;
goto V_16;
}
}
else
V_12 -> V_20 |= V_25 ;
if ( ! F_18 ( V_12 -> V_26 ,
V_4 -> V_3 ) )
goto V_16;
V_11 = F_19 ( sizeof( T_1 ) ) ;
if ( ! V_11 )
goto V_16;
V_11 -> V_3 = V_4 -> V_3 ;
V_4 -> V_3 = NULL ;
V_11 -> V_12 = V_12 ;
if ( ! F_20 ( V_5 -> V_9 , V_11 ) )
goto V_16;
V_11 = NULL ;
}
V_15 = 1 ;
V_16:
if ( V_15 == - 1 )
V_10 -> V_27 |= V_28 ;
if ( V_11 )
F_3 ( V_11 ) ;
if ( V_15 <= 0 )
{
F_21 ( V_5 -> V_9 , F_3 ) ;
V_5 -> V_9 = NULL ;
}
F_22 ( V_9 , V_29 ) ;
return V_15 ;
}
