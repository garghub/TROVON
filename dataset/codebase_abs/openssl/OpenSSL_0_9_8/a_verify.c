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
F_8 ( & V_6 , type , NULL ) ;
F_9 ( & V_6 , ( unsigned char * ) V_8 , V_11 ) ;
F_10 ( V_8 , ( unsigned int ) V_11 ) ;
F_11 ( V_8 ) ;
if ( F_12 ( & V_6 , ( unsigned char * ) V_3 -> V_4 ,
( unsigned int ) V_3 -> V_17 , V_5 ) <= 0 )
{
F_6 ( V_13 , V_18 ) ;
V_9 = 0 ;
goto V_15;
}
V_9 = 1 ;
V_15:
F_13 ( & V_6 ) ;
return ( V_9 ) ;
}
int F_14 ( const T_7 * V_19 , T_2 * V_2 , T_3 * V_3 ,
void * V_20 , T_4 * V_5 )
{
T_5 V_6 ;
const T_6 * type ;
unsigned char * V_8 = NULL ;
int V_9 = - 1 , V_10 , V_11 ;
F_2 ( & V_6 ) ;
V_10 = F_3 ( V_2 -> V_12 ) ;
type = F_4 ( F_5 ( V_10 ) ) ;
if ( type == NULL )
{
F_6 ( V_21 , V_14 ) ;
goto V_15;
}
if ( ! F_8 ( & V_6 , type , NULL ) )
{
F_6 ( V_21 , V_18 ) ;
V_9 = 0 ;
goto V_15;
}
V_11 = F_15 ( V_20 , & V_8 , V_19 ) ;
if ( V_8 == NULL )
{
F_6 ( V_21 , V_16 ) ;
goto V_15;
}
F_9 ( & V_6 , ( unsigned char * ) V_8 , V_11 ) ;
F_10 ( V_8 , ( unsigned int ) V_11 ) ;
F_11 ( V_8 ) ;
if ( F_12 ( & V_6 , ( unsigned char * ) V_3 -> V_4 ,
( unsigned int ) V_3 -> V_17 , V_5 ) <= 0 )
{
F_6 ( V_21 , V_18 ) ;
V_9 = 0 ;
goto V_15;
}
V_9 = 1 ;
V_15:
F_13 ( & V_6 ) ;
return ( V_9 ) ;
}
