int F_1 ( T_1 * V_1 , unsigned char * V_2 , int V_3 )
{
T_2 * V_4 ;
if ( ( V_4 = F_2 () ) == NULL ) return ( 0 ) ;
if ( ! F_3 ( V_4 , V_2 , V_3 ) ) return ( 0 ) ;
F_4 ( V_1 , V_5 , V_4 ) ;
return ( 1 ) ;
}
int F_5 ( T_1 * V_1 , unsigned char * V_2 ,
int V_6 )
{
int V_7 , V_8 ;
unsigned char * V_9 ;
if ( ( V_1 -> type != V_5 ) || ( V_1 -> V_10 . V_11 == NULL ) )
{
F_6 ( V_12 , V_13 ) ;
return ( - 1 ) ;
}
V_9 = F_7 ( V_1 -> V_10 . V_11 ) ;
V_7 = F_8 ( V_1 -> V_10 . V_11 ) ;
if ( V_7 < V_6 )
V_8 = V_7 ;
else
V_8 = V_6 ;
memcpy ( V_2 , V_9 , V_8 ) ;
return ( V_7 ) ;
}
int F_9 ( T_1 * V_1 , long V_8 , unsigned char * V_2 ,
int V_3 )
{
int V_14 , V_15 ;
T_3 V_4 , * V_16 ;
T_4 V_17 ;
unsigned char * V_9 ;
unsigned char V_18 [ 32 ] ;
V_17 . V_2 = V_18 ;
V_17 . V_19 = 32 ;
V_4 . V_2 = V_2 ;
V_4 . type = V_5 ;
V_4 . V_19 = V_3 ;
F_10 ( & V_17 , V_8 ) ;
V_14 = F_11 ( & V_17 , NULL ) ;
V_14 += F_12 ( & V_4 , NULL ) ;
V_15 = F_13 ( 1 , V_14 , V_20 ) ;
if ( ( V_16 = F_14 () ) == NULL ) return ( 0 ) ;
F_15 ( V_16 , NULL , V_15 ) ;
F_16 ( V_16 , V_15 ) ;
V_9 = F_7 ( V_16 ) ;
F_17 ( & V_9 , 1 , V_14 , V_20 , V_21 ) ;
F_11 ( & V_17 , & V_9 ) ;
F_12 ( & V_4 , & V_9 ) ;
F_4 ( V_1 , V_20 , V_16 ) ;
return ( 1 ) ;
}
int F_18 ( T_1 * V_1 , long * V_8 , unsigned char * V_2 ,
int V_6 )
{
int V_7 = - 1 , V_14 ;
T_4 * V_22 = NULL ;
T_3 * V_4 = NULL ;
unsigned char * V_9 ;
long V_19 ;
T_5 V_23 ;
if ( ( V_1 -> type != V_20 ) || ( V_1 -> V_10 . V_24 == NULL ) )
{
goto V_25;
}
V_9 = F_7 ( V_1 -> V_10 . V_24 ) ;
V_19 = F_8 ( V_1 -> V_10 . V_24 ) ;
V_23 . V_26 = & V_9 ;
V_23 . V_9 = V_9 ;
V_23 . V_27 = V_9 + V_19 ;
V_23 . error = V_13 ;
F_19 () ;
V_23 . V_28 = V_23 . V_9 ;
if ( ( V_22 = F_20 ( NULL , & V_23 . V_9 , V_23 . V_29 ) ) == NULL ) goto V_25;
V_23 . V_29 -= ( V_23 . V_9 - V_23 . V_28 ) ;
V_23 . V_28 = V_23 . V_9 ;
if ( ( V_4 = F_21 ( NULL , & V_23 . V_9 , V_23 . V_29 ) ) == NULL ) goto V_25;
V_23 . V_29 -= ( V_23 . V_9 - V_23 . V_28 ) ;
if ( ! F_22 () ) goto V_25;
if ( V_8 != NULL )
* V_8 = F_23 ( V_22 ) ;
V_7 = F_8 ( V_4 ) ;
if ( V_6 > V_7 )
V_14 = V_7 ;
else
V_14 = V_6 ;
if ( V_2 != NULL )
memcpy ( V_2 , F_7 ( V_4 ) , V_14 ) ;
if ( 0 )
{
V_25:
F_6 ( V_30 , V_13 ) ;
}
if ( V_4 != NULL ) F_24 ( V_4 ) ;
if ( V_22 != NULL ) F_25 ( V_22 ) ;
return ( V_7 ) ;
}
