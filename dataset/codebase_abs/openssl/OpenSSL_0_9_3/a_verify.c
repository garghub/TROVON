int F_1 ( int (* F_2)() , T_1 * V_1 , T_2 * V_2 ,
char * V_3 , T_3 * V_4 )
{
T_4 V_5 ;
const T_5 * type ;
unsigned char * V_6 , * V_7 = NULL ;
int V_8 = - 1 , V_9 , V_10 ;
V_9 = F_3 ( V_1 -> V_11 ) ;
type = F_4 ( F_5 ( V_9 ) ) ;
if ( type == NULL )
{
F_6 ( V_12 , V_13 ) ;
goto V_14;
}
V_10 = F_2 ( V_3 , NULL ) ;
V_7 = Malloc ( ( unsigned int ) V_10 ) ;
if ( V_7 == NULL )
{
F_6 ( V_12 , V_15 ) ;
goto V_14;
}
V_6 = V_7 ;
F_2 ( V_3 , & V_6 ) ;
F_7 ( & V_5 , type ) ;
F_8 ( & V_5 , ( unsigned char * ) V_7 , V_10 ) ;
memset ( V_7 , 0 , ( unsigned int ) V_10 ) ;
Free ( ( char * ) V_7 ) ;
if ( F_9 ( & V_5 , ( unsigned char * ) V_2 -> V_3 ,
( unsigned int ) V_2 -> V_16 , V_4 ) <= 0 )
{
F_6 ( V_12 , V_17 ) ;
V_8 = 0 ;
goto V_14;
}
V_8 = 1 ;
V_14:
return ( V_8 ) ;
}
