int F_1 ( int (* F_2)() , T_1 * V_1 , T_1 * V_2 ,
T_2 * V_3 , char * V_4 , T_3 * V_5 ,
const T_4 * type )
{
T_5 V_6 ;
unsigned char * V_7 , * V_8 = NULL , * V_9 = NULL ;
int V_10 , V_11 = 0 , V_12 = 0 , V_13 = 0 ;
T_1 * V_14 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ )
{
if ( V_10 == 0 )
V_14 = V_1 ;
else
V_14 = V_2 ;
if ( V_14 == NULL ) continue;
if ( ( V_14 -> V_15 == NULL ) ||
( V_14 -> V_15 -> type != V_16 ) )
{
F_3 ( V_14 -> V_15 ) ;
if ( ( V_14 -> V_15 = F_4 () ) == NULL ) goto V_17;
V_14 -> V_15 -> type = V_16 ;
}
F_5 ( V_14 -> V_18 ) ;
V_14 -> V_18 = F_6 ( type -> V_19 ) ;
if ( V_14 -> V_18 == NULL )
{
F_7 ( V_20 , V_21 ) ;
goto V_17;
}
if ( V_14 -> V_18 -> V_22 == 0 )
{
F_7 ( V_20 , V_23 ) ;
goto V_17;
}
}
V_11 = F_2 ( V_4 , NULL ) ;
V_8 = ( unsigned char * ) F_8 ( ( unsigned int ) V_11 ) ;
V_13 = V_12 = F_9 ( V_5 ) ;
V_9 = ( unsigned char * ) F_8 ( ( unsigned int ) V_12 ) ;
if ( ( V_8 == NULL ) || ( V_9 == NULL ) )
{
V_12 = 0 ;
F_7 ( V_20 , V_24 ) ;
goto V_17;
}
V_7 = V_8 ;
F_2 ( V_4 , & V_7 ) ;
F_10 ( & V_6 , type ) ;
F_11 ( & V_6 , ( unsigned char * ) V_8 , V_11 ) ;
if ( ! F_12 ( & V_6 , ( unsigned char * ) V_9 ,
( unsigned int * ) & V_12 , V_5 ) )
{
V_12 = 0 ;
F_7 ( V_20 , V_25 ) ;
goto V_17;
}
if ( V_3 -> V_4 != NULL ) F_13 ( V_3 -> V_4 ) ;
V_3 -> V_4 = V_9 ;
V_9 = NULL ;
V_3 -> V_22 = V_12 ;
V_3 -> V_26 &= ~ ( V_27 | 0x07 ) ;
V_3 -> V_26 |= V_27 ;
V_17:
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
if ( V_8 != NULL )
{ memset ( ( char * ) V_8 , 0 , ( unsigned int ) V_11 ) ; F_13 ( V_8 ) ; }
if ( V_9 != NULL )
{ memset ( ( char * ) V_9 , 0 , V_13 ) ; F_13 ( V_9 ) ; }
return ( V_12 ) ;
}
