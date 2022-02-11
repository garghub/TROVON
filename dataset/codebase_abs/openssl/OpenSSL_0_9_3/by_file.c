T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 , int V_3 , const char * V_4 , long V_5 ,
char * * V_6 )
{
int V_7 = 0 , V_8 = 0 ;
char * V_9 ;
switch ( V_3 )
{
case V_10 :
if ( V_5 == V_11 )
{
V_7 = F_3 ( V_2 , F_4 () ,
V_12 ) ;
V_8 = F_5 ( V_2 , F_4 () ,
V_12 ) ;
if ( ! V_7 || ! V_8 )
{
F_6 ( V_13 , V_14 ) ;
}
else
{
V_9 = ( char * ) Getenv ( F_7 () ) ;
V_7 = F_3 ( V_2 , V_9 ,
V_12 ) ;
V_8 = F_5 ( V_2 , V_9 ,
V_12 ) ;
}
}
else
{
V_7 = F_3 ( V_2 , V_4 , ( int ) V_5 ) ;
V_8 = F_5 ( V_2 , V_4 , ( int ) V_5 ) ;
}
break;
}
return ( ( V_7 && V_8 ) ? V_7 : 0 ) ;
}
int F_3 ( T_2 * V_2 , const char * V_9 , int type )
{
int V_6 = 0 ;
T_3 * V_15 = NULL ;
int V_16 , V_17 = 0 ;
T_4 * V_18 = NULL ;
if ( V_9 == NULL ) return ( 1 ) ;
V_15 = F_8 ( F_9 () ) ;
if ( ( V_15 == NULL ) || ( F_10 ( V_15 , V_9 ) <= 0 ) )
{
F_6 ( V_19 , V_20 ) ;
goto V_21;
}
if ( type == V_12 )
{
for (; ; )
{
V_18 = F_11 ( V_15 , NULL , NULL ) ;
if ( V_18 == NULL )
{
if ( ( F_12 ( F_13 () ) ==
V_22 ) && ( V_17 > 0 ) )
{
F_14 () ;
break;
}
else
{
F_6 ( V_19 ,
V_23 ) ;
goto V_21;
}
}
V_16 = F_15 ( V_2 -> V_24 , V_18 ) ;
if ( ! V_16 ) goto V_21;
V_17 ++ ;
F_16 ( V_18 ) ;
V_18 = NULL ;
}
V_6 = V_17 ;
}
else if ( type == V_25 )
{
V_18 = F_17 ( V_15 , NULL ) ;
if ( V_18 == NULL )
{
F_6 ( V_19 , V_26 ) ;
goto V_21;
}
V_16 = F_15 ( V_2 -> V_24 , V_18 ) ;
if ( ! V_16 ) goto V_21;
V_6 = V_16 ;
}
else
{
F_6 ( V_19 , V_27 ) ;
goto V_21;
}
V_21:
if ( V_18 != NULL ) F_16 ( V_18 ) ;
if ( V_15 != NULL ) F_18 ( V_15 ) ;
return ( V_6 ) ;
}
int F_5 ( T_2 * V_2 , const char * V_9 , int type )
{
int V_6 = 0 ;
T_3 * V_15 = NULL ;
int V_16 , V_17 = 0 ;
T_5 * V_18 = NULL ;
if ( V_9 == NULL ) return ( 1 ) ;
V_15 = F_8 ( F_9 () ) ;
if ( ( V_15 == NULL ) || ( F_10 ( V_15 , V_9 ) <= 0 ) )
{
F_6 ( V_28 , V_20 ) ;
goto V_21;
}
if ( type == V_12 )
{
for (; ; )
{
V_18 = F_19 ( V_15 , NULL , NULL ) ;
if ( V_18 == NULL )
{
if ( ( F_12 ( F_13 () ) ==
V_22 ) && ( V_17 > 0 ) )
{
F_14 () ;
break;
}
else
{
F_6 ( V_28 ,
V_23 ) ;
goto V_21;
}
}
V_16 = F_20 ( V_2 -> V_24 , V_18 ) ;
if ( ! V_16 ) goto V_21;
V_17 ++ ;
F_21 ( V_18 ) ;
V_18 = NULL ;
}
V_6 = V_17 ;
}
else if ( type == V_25 )
{
V_18 = F_22 ( V_15 , NULL ) ;
if ( V_18 == NULL )
{
F_6 ( V_28 , V_26 ) ;
goto V_21;
}
V_16 = F_20 ( V_2 -> V_24 , V_18 ) ;
if ( ! V_16 ) goto V_21;
V_6 = V_16 ;
}
else
{
F_6 ( V_28 , V_27 ) ;
goto V_21;
}
V_21:
if ( V_18 != NULL ) F_21 ( V_18 ) ;
if ( V_15 != NULL ) F_18 ( V_15 ) ;
return ( V_6 ) ;
}
