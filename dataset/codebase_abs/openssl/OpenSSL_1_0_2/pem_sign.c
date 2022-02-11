void F_1 ( T_1 * V_1 , T_2 * type )
{
F_2 ( V_1 , type , NULL ) ;
}
void F_3 ( T_1 * V_1 , unsigned char * V_2 , unsigned int V_3 )
{
F_4 ( V_1 , V_2 , V_3 ) ;
}
int F_5 ( T_1 * V_1 , unsigned char * V_4 ,
unsigned int * V_5 , T_3 * V_6 )
{
unsigned char * V_7 ;
int V_8 , V_9 = 0 ;
unsigned int V_10 ;
V_7 = ( unsigned char * ) F_6 ( F_7 ( V_6 ) + 2 ) ;
if ( V_7 == NULL ) {
F_8 ( V_11 , V_12 ) ;
goto V_13;
}
if ( F_9 ( V_1 , V_7 , & V_10 , V_6 ) <= 0 )
goto V_13;
V_8 = F_10 ( V_4 , V_7 , V_10 ) ;
* V_5 = V_8 ;
V_9 = 1 ;
V_13:
if ( V_7 != NULL )
F_11 ( V_7 ) ;
return ( V_9 ) ;
}
