int F_1 ( T_1 * V_1 , const unsigned char * V_2 ,
unsigned int V_3 , T_2 * V_4 )
{
unsigned char V_5 [ V_6 ] ;
unsigned int V_7 = 0 ;
int V_8 = 0 ;
T_3 * V_9 = NULL ;
if ( F_2 ( V_1 , V_10 ) ) {
if ( ! F_3 ( V_1 , V_5 , & V_7 ) )
goto V_11;
} else {
int V_12 = 0 ;
T_1 * V_13 = F_4 () ;
if ( V_13 == NULL ) {
F_5 ( V_14 , V_15 ) ;
return 0 ;
}
V_12 = F_6 ( V_13 , V_1 ) ;
if ( V_12 )
V_12 = F_3 ( V_13 , V_5 , & V_7 ) ;
F_7 ( V_13 ) ;
if ( ! V_12 )
return 0 ;
}
V_8 = - 1 ;
V_9 = F_8 ( V_4 , NULL ) ;
if ( V_9 == NULL )
goto V_11;
if ( F_9 ( V_9 ) <= 0 )
goto V_11;
if ( F_10 ( V_9 , F_11 ( V_1 ) ) <= 0 )
goto V_11;
V_8 = F_12 ( V_9 , V_2 , V_3 , V_5 , V_7 ) ;
V_11:
F_13 ( V_9 ) ;
return V_8 ;
}
