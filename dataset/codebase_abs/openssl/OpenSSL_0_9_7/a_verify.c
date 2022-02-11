int F_1 ( int (* F_2)() , T_1 * V_1 , T_2 * V_2 ,
char * V_3 , T_3 * V_4 )
{
T_4 V_5 ;
const T_5 * type ;
unsigned char * V_6 , * V_7 = NULL ;
int V_8 = - 1 , V_9 , V_10 ;
F_3 ( & V_5 ) ;
V_9 = F_4 ( V_1 -> V_11 ) ;
type = F_5 ( F_6 ( V_9 ) ) ;
if ( type == NULL )
{
F_7 ( V_12 , V_13 ) ;
goto V_14;
}
V_10 = F_2 ( V_3 , NULL ) ;
V_7 = F_8 ( ( unsigned int ) V_10 ) ;
if ( V_7 == NULL )
{
F_7 ( V_12 , V_15 ) ;
goto V_14;
}
V_6 = V_7 ;
F_2 ( V_3 , & V_6 ) ;
F_9 ( & V_5 , type , NULL ) ;
F_10 ( & V_5 , ( unsigned char * ) V_7 , V_10 ) ;
F_11 ( V_7 , ( unsigned int ) V_10 ) ;
F_12 ( V_7 ) ;
if ( F_13 ( & V_5 , ( unsigned char * ) V_2 -> V_3 ,
( unsigned int ) V_2 -> V_16 , V_4 ) <= 0 )
{
F_7 ( V_12 , V_17 ) ;
V_8 = 0 ;
goto V_14;
}
V_8 = 1 ;
V_14:
F_14 ( & V_5 ) ;
return ( V_8 ) ;
}
int F_15 ( const T_6 * V_18 , T_1 * V_1 , T_2 * V_2 ,
void * V_19 , T_3 * V_4 )
{
T_4 V_5 ;
const T_5 * type ;
unsigned char * V_7 = NULL ;
int V_8 = - 1 , V_9 , V_10 ;
F_3 ( & V_5 ) ;
V_9 = F_4 ( V_1 -> V_11 ) ;
type = F_5 ( F_6 ( V_9 ) ) ;
if ( type == NULL )
{
F_7 ( V_12 , V_13 ) ;
goto V_14;
}
V_10 = F_16 ( V_19 , & V_7 , V_18 ) ;
if ( V_7 == NULL )
{
F_7 ( V_12 , V_15 ) ;
goto V_14;
}
F_9 ( & V_5 , type , NULL ) ;
F_10 ( & V_5 , ( unsigned char * ) V_7 , V_10 ) ;
F_11 ( V_7 , ( unsigned int ) V_10 ) ;
F_12 ( V_7 ) ;
if ( F_13 ( & V_5 , ( unsigned char * ) V_2 -> V_3 ,
( unsigned int ) V_2 -> V_16 , V_4 ) <= 0 )
{
F_7 ( V_12 , V_17 ) ;
V_8 = 0 ;
goto V_14;
}
V_8 = 1 ;
V_14:
F_14 ( & V_5 ) ;
return ( V_8 ) ;
}
