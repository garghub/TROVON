int F_1 ( int type , unsigned char * V_1 , unsigned int V_2 ,
unsigned char * V_3 , unsigned int * V_4 , T_1 * V_5 )
{
T_2 V_6 ;
int V_7 , V_8 , V_9 = 1 ;
unsigned char * V_10 , * V_11 ;
V_6 . type = V_12 ;
V_6 . V_13 = V_2 ;
V_6 . V_14 = V_1 ;
V_7 = F_2 ( & V_6 , NULL ) ;
V_8 = F_3 ( V_5 ) ;
if ( ( V_7 - V_15 ) > V_8 )
{
F_4 ( V_16 , V_17 ) ;
return ( 0 ) ;
}
V_11 = ( unsigned char * ) F_5 ( ( unsigned int ) V_8 + 1 ) ;
if ( V_11 == NULL )
{
F_4 ( V_16 , V_18 ) ;
return ( 0 ) ;
}
V_10 = V_11 ;
F_2 ( & V_6 , & V_10 ) ;
V_7 = F_6 ( V_7 , V_11 , V_3 , V_5 , V_15 ) ;
if ( V_7 <= 0 )
V_9 = 0 ;
else
* V_4 = V_7 ;
memset ( V_11 , 0 , ( unsigned int ) V_8 + 1 ) ;
F_7 ( V_11 ) ;
return ( V_9 ) ;
}
int F_8 ( int V_19 , unsigned char * V_1 ,
unsigned int V_2 , unsigned char * V_20 , unsigned int V_4 ,
T_1 * V_5 )
{
int V_7 , V_9 = 0 ;
unsigned char * V_10 , * V_11 ;
T_2 * V_6 = NULL ;
if ( V_4 != ( unsigned int ) F_3 ( V_5 ) )
{
F_4 ( V_21 , V_22 ) ;
return ( 0 ) ;
}
V_11 = ( unsigned char * ) F_5 ( ( unsigned int ) V_4 ) ;
if ( V_11 == NULL )
{
F_4 ( V_21 , V_18 ) ;
goto V_23;
}
V_7 = F_9 ( ( int ) V_4 , V_20 , V_11 , V_5 , V_15 ) ;
if ( V_7 <= 0 ) goto V_23;
V_10 = V_11 ;
V_6 = F_10 ( NULL , & V_10 , ( long ) V_7 ) ;
if ( V_6 == NULL ) goto V_23;
if ( ( ( unsigned int ) V_6 -> V_13 != V_2 ) ||
( memcmp ( V_1 , V_6 -> V_14 , V_2 ) != 0 ) )
{
F_4 ( V_21 , V_24 ) ;
}
else
V_9 = 1 ;
V_23:
if ( V_6 != NULL ) F_11 ( V_6 ) ;
memset ( V_11 , 0 , ( unsigned int ) V_4 ) ;
F_7 ( V_11 ) ;
return ( V_9 ) ;
}
