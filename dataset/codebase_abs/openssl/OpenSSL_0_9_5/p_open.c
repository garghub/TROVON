int F_1 ( T_1 * V_1 , T_2 * type , unsigned char * V_2 ,
int V_3 , unsigned char * V_4 , T_3 * V_5 )
{
unsigned char * V_6 = NULL ;
int V_7 , V_8 = 0 , V_9 = 0 ;
if ( V_5 -> type != V_10 )
{
F_2 ( V_11 , V_12 ) ;
V_9 = - 1 ;
goto V_13;
}
V_8 = F_3 ( V_5 -> V_14 . V_15 ) ;
V_6 = ( unsigned char * ) Malloc ( V_8 + 2 ) ;
if ( V_6 == NULL )
{
F_2 ( V_11 , V_16 ) ;
V_9 = - 1 ;
goto V_13;
}
V_7 = F_4 ( V_6 , V_2 , V_3 , V_5 ) ;
if ( V_7 != type -> V_17 )
{
goto V_13;
}
F_5 ( V_1 ) ;
F_6 ( V_1 , type , V_6 , V_4 ) ;
V_9 = 1 ;
V_13:
if ( V_6 != NULL ) memset ( V_6 , 0 , V_8 ) ;
Free ( V_6 ) ;
return ( V_9 ) ;
}
int F_7 ( T_1 * V_1 , unsigned char * V_18 , int * V_19 )
{
int V_7 ;
V_7 = F_8 ( V_1 , V_18 , V_19 ) ;
F_6 ( V_1 , NULL , NULL , NULL ) ;
return ( V_7 ) ;
}
