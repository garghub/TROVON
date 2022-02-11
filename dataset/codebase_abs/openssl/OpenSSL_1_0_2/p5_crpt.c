void F_1 ( void )
{
}
int F_2 ( T_1 * V_1 , const char * V_2 , int V_3 ,
T_2 * V_4 , const T_3 * V_5 ,
const T_4 * V_6 , int V_7 )
{
T_5 V_8 ;
unsigned char V_9 [ V_10 ] ;
unsigned char V_11 [ V_12 ] , V_13 [ V_14 ] ;
int V_15 ;
T_6 * V_16 ;
int V_17 , V_18 ;
unsigned char * V_19 ;
const unsigned char * V_20 ;
int V_21 ;
int V_22 = 0 ;
F_3 ( & V_8 ) ;
if ( V_4 == NULL || V_4 -> type != V_23 ||
V_4 -> V_24 . V_25 == NULL ) {
F_4 ( V_26 , V_27 ) ;
return 0 ;
}
V_20 = V_4 -> V_24 . V_25 -> V_28 ;
if ( ! ( V_16 = F_5 ( NULL , & V_20 , V_4 -> V_24 . V_25 -> V_29 ) ) ) {
F_4 ( V_26 , V_27 ) ;
return 0 ;
}
if ( ! V_16 -> V_18 )
V_18 = 1 ;
else
V_18 = F_6 ( V_16 -> V_18 ) ;
V_19 = V_16 -> V_19 -> V_28 ;
V_17 = V_16 -> V_19 -> V_29 ;
if ( ! V_2 )
V_3 = 0 ;
else if ( V_3 == - 1 )
V_3 = strlen ( V_2 ) ;
if ( ! F_7 ( & V_8 , V_6 , NULL ) )
goto V_30;
if ( ! F_8 ( & V_8 , V_2 , V_3 ) )
goto V_30;
if ( ! F_8 ( & V_8 , V_19 , V_17 ) )
goto V_30;
F_9 ( V_16 ) ;
if ( ! F_10 ( & V_8 , V_9 , NULL ) )
goto V_30;
V_21 = F_11 ( V_6 ) ;
if ( V_21 < 0 )
return 0 ;
for ( V_15 = 1 ; V_15 < V_18 ; V_15 ++ ) {
if ( ! F_7 ( & V_8 , V_6 , NULL ) )
goto V_30;
if ( ! F_8 ( & V_8 , V_9 , V_21 ) )
goto V_30;
if ( ! F_10 ( & V_8 , V_9 , NULL ) )
goto V_30;
}
F_12 ( F_13 ( V_5 ) <= ( int ) sizeof( V_9 ) ) ;
memcpy ( V_11 , V_9 , F_13 ( V_5 ) ) ;
F_12 ( F_14 ( V_5 ) <= 16 ) ;
memcpy ( V_13 , V_9 + ( 16 - F_14 ( V_5 ) ) ,
F_14 ( V_5 ) ) ;
if ( ! F_15 ( V_1 , V_5 , NULL , V_11 , V_13 , V_7 ) )
goto V_30;
F_16 ( V_9 , V_10 ) ;
F_16 ( V_11 , V_12 ) ;
F_16 ( V_13 , V_14 ) ;
V_22 = 1 ;
V_30:
F_17 ( & V_8 ) ;
return V_22 ;
}
