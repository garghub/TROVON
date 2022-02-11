int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
unsigned int * V_3 , T_2 * V_4 )
{
unsigned char V_5 [ V_6 ] ;
unsigned int V_7 = 0 ;
int V_8 = 0 ;
T_3 V_9 ;
T_4 * V_10 = NULL ;
* V_3 = 0 ;
if ( F_2 ( V_1 , V_11 ) ) {
if ( ! F_3 ( V_1 , V_5 , & V_7 ) )
goto V_12;
} else {
int V_13 = 0 ;
T_1 * V_14 = F_4 () ;
if ( V_14 == NULL ) {
F_5 ( V_15 , V_16 ) ;
return 0 ;
}
V_13 = F_6 ( V_14 , V_1 ) ;
if ( V_13 )
V_13 = F_3 ( V_14 , V_5 , & V_7 ) ;
F_7 ( V_14 ) ;
if ( ! V_13 )
return 0 ;
}
V_9 = ( T_3 ) F_8 ( V_4 ) ;
V_8 = 0 ;
V_10 = F_9 ( V_4 , NULL ) ;
if ( V_10 == NULL )
goto V_12;
if ( F_10 ( V_10 ) <= 0 )
goto V_12;
if ( F_11 ( V_10 , F_12 ( V_1 ) ) <= 0 )
goto V_12;
if ( F_13 ( V_10 , V_2 , & V_9 , V_5 , V_7 ) <= 0 )
goto V_12;
* V_3 = V_9 ;
V_8 = 1 ;
V_12:
F_14 ( V_10 ) ;
return V_8 ;
}
