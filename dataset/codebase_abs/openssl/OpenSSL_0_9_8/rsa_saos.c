int F_1 ( int type ,
const unsigned char * V_1 , unsigned int V_2 ,
unsigned char * V_3 , unsigned int * V_4 , T_1 * V_5 )
{
T_2 V_6 ;
int V_7 , V_8 , V_9 = 1 ;
unsigned char * V_10 , * V_11 ;
V_6 . type = V_12 ;
V_6 . V_13 = V_2 ;
V_6 . V_14 = ( unsigned char * ) V_1 ;
V_7 = F_2 ( & V_6 , NULL ) ;
V_8 = F_3 ( V_5 ) ;
if ( V_7 > ( V_8 - V_15 ) )
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
V_7 = F_6 ( V_7 , V_11 , V_3 , V_5 , V_19 ) ;
if ( V_7 <= 0 )
V_9 = 0 ;
else
* V_4 = V_7 ;
F_7 ( V_11 , ( unsigned int ) V_8 + 1 ) ;
F_8 ( V_11 ) ;
return ( V_9 ) ;
}
int F_9 ( int V_20 ,
const unsigned char * V_1 ,
unsigned int V_2 , unsigned char * V_21 , unsigned int V_4 ,
T_1 * V_5 )
{
int V_7 , V_9 = 0 ;
unsigned char * V_11 ;
const unsigned char * V_10 ;
T_2 * V_6 = NULL ;
if ( V_4 != ( unsigned int ) F_3 ( V_5 ) )
{
F_4 ( V_22 , V_23 ) ;
return ( 0 ) ;
}
V_11 = ( unsigned char * ) F_5 ( ( unsigned int ) V_4 ) ;
if ( V_11 == NULL )
{
F_4 ( V_22 , V_18 ) ;
goto V_24;
}
V_7 = F_10 ( ( int ) V_4 , V_21 , V_11 , V_5 , V_19 ) ;
if ( V_7 <= 0 ) goto V_24;
V_10 = V_11 ;
V_6 = F_11 ( NULL , & V_10 , ( long ) V_7 ) ;
if ( V_6 == NULL ) goto V_24;
if ( ( ( unsigned int ) V_6 -> V_13 != V_2 ) ||
( memcmp ( V_1 , V_6 -> V_14 , V_2 ) != 0 ) )
{
F_4 ( V_22 , V_25 ) ;
}
else
V_9 = 1 ;
V_24:
if ( V_6 != NULL ) F_12 ( V_6 ) ;
if ( V_11 != NULL )
{
F_7 ( V_11 , ( unsigned int ) V_4 ) ;
F_8 ( V_11 ) ;
}
return ( V_9 ) ;
}
