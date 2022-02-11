int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 ,
char * V_4 , T_4 * V_5 )
{
T_5 V_6 ;
const T_6 * type ;
unsigned char * V_7 , * V_8 = NULL ;
int V_9 = - 1 , V_10 , V_11 ;
F_2 ( & V_6 ) ;
V_10 = F_3 ( V_2 -> V_12 ) ;
type = F_4 ( F_5 ( V_10 ) ) ;
if ( type == NULL )
{
F_6 ( V_13 , V_14 ) ;
goto V_15;
}
V_11 = V_1 ( V_4 , NULL ) ;
V_8 = F_7 ( ( unsigned int ) V_11 ) ;
if ( V_8 == NULL )
{
F_6 ( V_13 , V_16 ) ;
goto V_15;
}
V_7 = V_8 ;
V_1 ( V_4 , & V_7 ) ;
if ( ! F_8 ( & V_6 , type , NULL )
|| ! F_9 ( & V_6 , ( unsigned char * ) V_8 , V_11 ) )
{
F_6 ( V_13 , V_17 ) ;
V_9 = 0 ;
goto V_15;
}
F_10 ( V_8 , ( unsigned int ) V_11 ) ;
F_11 ( V_8 ) ;
if ( F_12 ( & V_6 , ( unsigned char * ) V_3 -> V_4 ,
( unsigned int ) V_3 -> V_18 , V_5 ) <= 0 )
{
F_6 ( V_13 , V_17 ) ;
V_9 = 0 ;
goto V_15;
}
V_9 = 1 ;
V_15:
F_13 ( & V_6 ) ;
return ( V_9 ) ;
}
int F_14 ( const T_7 * V_19 , T_2 * V_2 ,
T_3 * V_3 , void * V_20 , T_4 * V_5 )
{
T_5 V_6 ;
unsigned char * V_8 = NULL ;
int V_9 = - 1 , V_11 ;
int V_21 , V_22 ;
F_2 ( & V_6 ) ;
if ( ! F_15 ( F_3 ( V_2 -> V_12 ) , & V_21 , & V_22 ) )
{
F_6 ( V_23 , V_24 ) ;
goto V_15;
}
if ( V_21 == V_25 )
{
if ( ! V_5 -> V_26 || ! V_5 -> V_26 -> V_27 )
{
F_6 ( V_23 , V_24 ) ;
goto V_15;
}
V_9 = V_5 -> V_26 -> V_27 ( & V_6 , V_19 , V_20 , V_2 ,
V_3 , V_5 ) ;
if ( V_9 != 2 )
goto V_15;
V_9 = - 1 ;
}
else
{
const T_6 * type ;
type = F_16 ( V_21 ) ;
if ( type == NULL )
{
F_6 ( V_23 , V_14 ) ;
goto V_15;
}
if ( F_17 ( V_22 ) != V_5 -> V_26 -> V_28 )
{
F_6 ( V_23 , V_29 ) ;
goto V_15;
}
if ( ! F_18 ( & V_6 , NULL , type , NULL , V_5 ) )
{
F_6 ( V_23 , V_17 ) ;
V_9 = 0 ;
goto V_15;
}
}
V_11 = F_19 ( V_20 , & V_8 , V_19 ) ;
if ( V_8 == NULL )
{
F_6 ( V_23 , V_16 ) ;
goto V_15;
}
if ( ! F_20 ( & V_6 , V_8 , V_11 ) )
{
F_6 ( V_23 , V_17 ) ;
V_9 = 0 ;
goto V_15;
}
F_10 ( V_8 , ( unsigned int ) V_11 ) ;
F_11 ( V_8 ) ;
if ( F_21 ( & V_6 , V_3 -> V_4 ,
( V_30 ) V_3 -> V_18 ) <= 0 )
{
F_6 ( V_23 , V_17 ) ;
V_9 = 0 ;
goto V_15;
}
V_9 = 1 ;
V_15:
F_13 ( & V_6 ) ;
return ( V_9 ) ;
}
