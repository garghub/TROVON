void F_1 ( void )
{
}
int F_2 ( T_1 * V_1 , const char * V_2 , int V_3 ,
T_2 * V_4 , const T_3 * V_5 ,
const T_4 * V_6 , int V_7 )
{
T_5 * V_8 ;
unsigned char V_9 [ V_10 ] ;
unsigned char V_11 [ V_12 ] , V_13 [ V_14 ] ;
int V_15 ;
T_6 * V_16 ;
int V_17 , V_18 ;
unsigned char * V_19 ;
int V_20 ;
int V_21 = 0 ;
if ( V_4 == NULL || V_4 -> type != V_22 ||
V_4 -> V_23 . V_24 == NULL ) {
F_3 ( V_25 , V_26 ) ;
return 0 ;
}
V_16 = F_4 ( F_5 ( T_6 ) , V_4 ) ;
if ( V_16 == NULL ) {
F_3 ( V_25 , V_26 ) ;
return 0 ;
}
if ( ! V_16 -> V_18 )
V_18 = 1 ;
else
V_18 = F_6 ( V_16 -> V_18 ) ;
V_19 = V_16 -> V_19 -> V_27 ;
V_17 = V_16 -> V_19 -> V_28 ;
if ( ! V_2 )
V_3 = 0 ;
else if ( V_3 == - 1 )
V_3 = strlen ( V_2 ) ;
V_8 = F_7 () ;
if ( V_8 == NULL ) {
F_3 ( V_25 , V_29 ) ;
goto V_30;
}
if ( ! F_8 ( V_8 , V_6 , NULL ) )
goto V_30;
if ( ! F_9 ( V_8 , V_2 , V_3 ) )
goto V_30;
if ( ! F_9 ( V_8 , V_19 , V_17 ) )
goto V_30;
F_10 ( V_16 ) ;
if ( ! F_11 ( V_8 , V_9 , NULL ) )
goto V_30;
V_20 = F_12 ( V_6 ) ;
if ( V_20 < 0 )
return 0 ;
for ( V_15 = 1 ; V_15 < V_18 ; V_15 ++ ) {
if ( ! F_8 ( V_8 , V_6 , NULL ) )
goto V_30;
if ( ! F_9 ( V_8 , V_9 , V_20 ) )
goto V_30;
if ( ! F_11 ( V_8 , V_9 , NULL ) )
goto V_30;
}
F_13 ( F_14 ( V_5 ) <= ( int ) sizeof( V_9 ) ) ;
memcpy ( V_11 , V_9 , F_14 ( V_5 ) ) ;
F_13 ( F_15 ( V_5 ) <= 16 ) ;
memcpy ( V_13 , V_9 + ( 16 - F_15 ( V_5 ) ) ,
F_15 ( V_5 ) ) ;
if ( ! F_16 ( V_1 , V_5 , NULL , V_11 , V_13 , V_7 ) )
goto V_30;
F_17 ( V_9 , V_10 ) ;
F_17 ( V_11 , V_12 ) ;
F_17 ( V_13 , V_14 ) ;
V_21 = 1 ;
V_30:
F_18 ( V_8 ) ;
return V_21 ;
}
