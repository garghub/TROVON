T_1 * F_1 ( T_1 * V_1 , int V_2 , int V_3 ,
const T_1 * V_4 , const T_1 * V_5 ,
void (* F_2) ( int , int , void * ) , void * V_6 )
{
T_2 V_7 ;
T_1 * V_8 = NULL ;
int V_9 = 0 ;
F_3 ( & V_7 , F_2 , V_6 ) ;
if ( V_1 == NULL ) {
if ( ( V_8 = F_4 () ) == NULL )
goto V_10;
} else
V_8 = V_1 ;
if ( ! F_5 ( V_8 , V_2 , V_3 , V_4 , V_5 , & V_7 ) )
goto V_10;
V_9 = 1 ;
V_10:
if ( ! V_9 && ( V_1 == NULL ) && ( V_8 != NULL ) )
F_6 ( V_8 ) ;
return ( V_9 ? V_8 : NULL ) ;
}
int F_7 ( const T_1 * V_11 , int V_12 ,
void (* F_2) ( int , int , void * ) , T_3 * V_13 ,
void * V_6 )
{
T_2 V_7 ;
F_3 ( & V_7 , F_2 , V_6 ) ;
return F_8 ( V_11 , V_12 , V_13 , & V_7 ) ;
}
int F_9 ( const T_1 * V_11 , int V_12 ,
void (* F_2) ( int , int , void * ) ,
T_3 * V_13 , void * V_6 ,
int V_14 )
{
T_2 V_7 ;
F_3 ( & V_7 , F_2 , V_6 ) ;
return F_10 ( V_11 , V_12 , V_13 ,
V_14 , & V_7 ) ;
}
