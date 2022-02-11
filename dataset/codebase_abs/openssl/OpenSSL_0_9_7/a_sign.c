int F_1 ( int (* F_2)() , T_1 * V_1 , T_1 * V_2 ,
T_2 * V_3 , char * V_4 , T_3 * V_5 ,
const T_4 * type )
{
T_5 V_6 ;
unsigned char * V_7 , * V_8 = NULL , * V_9 = NULL ;
int V_10 , V_11 = 0 , V_12 = 0 , V_13 = 0 ;
T_1 * V_14 ;
F_3 ( & V_6 ) ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ )
{
if ( V_10 == 0 )
V_14 = V_1 ;
else
V_14 = V_2 ;
if ( V_14 == NULL ) continue;
if ( type -> V_15 == V_16 )
{
F_4 ( V_14 -> V_17 ) ;
V_14 -> V_17 = NULL ;
}
else if ( ( V_14 -> V_17 == NULL ) ||
( V_14 -> V_17 -> type != V_18 ) )
{
F_4 ( V_14 -> V_17 ) ;
if ( ( V_14 -> V_17 = F_5 () ) == NULL ) goto V_19;
V_14 -> V_17 -> type = V_18 ;
}
F_6 ( V_14 -> V_20 ) ;
V_14 -> V_20 = F_7 ( type -> V_15 ) ;
if ( V_14 -> V_20 == NULL )
{
F_8 ( V_21 , V_22 ) ;
goto V_19;
}
if ( V_14 -> V_20 -> V_23 == 0 )
{
F_8 ( V_21 , V_24 ) ;
goto V_19;
}
}
V_11 = F_2 ( V_4 , NULL ) ;
V_8 = ( unsigned char * ) F_9 ( ( unsigned int ) V_11 ) ;
V_13 = V_12 = F_10 ( V_5 ) ;
V_9 = ( unsigned char * ) F_9 ( ( unsigned int ) V_12 ) ;
if ( ( V_8 == NULL ) || ( V_9 == NULL ) )
{
V_12 = 0 ;
F_8 ( V_21 , V_25 ) ;
goto V_19;
}
V_7 = V_8 ;
F_2 ( V_4 , & V_7 ) ;
F_11 ( & V_6 , type , NULL ) ;
F_12 ( & V_6 , ( unsigned char * ) V_8 , V_11 ) ;
if ( ! F_13 ( & V_6 , ( unsigned char * ) V_9 ,
( unsigned int * ) & V_12 , V_5 ) )
{
V_12 = 0 ;
F_8 ( V_21 , V_26 ) ;
goto V_19;
}
if ( V_3 -> V_4 != NULL ) F_14 ( V_3 -> V_4 ) ;
V_3 -> V_4 = V_9 ;
V_9 = NULL ;
V_3 -> V_23 = V_12 ;
V_3 -> V_27 &= ~ ( V_28 | 0x07 ) ;
V_3 -> V_27 |= V_28 ;
V_19:
F_15 ( & V_6 ) ;
if ( V_8 != NULL )
{ F_16 ( ( char * ) V_8 , ( unsigned int ) V_11 ) ; F_14 ( V_8 ) ; }
if ( V_9 != NULL )
{ F_16 ( ( char * ) V_9 , V_13 ) ; F_14 ( V_9 ) ; }
return ( V_12 ) ;
}
int F_17 ( const T_6 * V_29 , T_1 * V_1 , T_1 * V_2 ,
T_2 * V_3 , void * V_30 , T_3 * V_5 ,
const T_4 * type )
{
T_5 V_6 ;
unsigned char * V_8 = NULL , * V_9 = NULL ;
int V_10 , V_11 = 0 , V_12 = 0 , V_13 = 0 ;
T_1 * V_14 ;
F_3 ( & V_6 ) ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ )
{
if ( V_10 == 0 )
V_14 = V_1 ;
else
V_14 = V_2 ;
if ( V_14 == NULL ) continue;
if ( type -> V_15 == V_16 )
{
F_4 ( V_14 -> V_17 ) ;
V_14 -> V_17 = NULL ;
}
else if ( ( V_14 -> V_17 == NULL ) ||
( V_14 -> V_17 -> type != V_18 ) )
{
F_4 ( V_14 -> V_17 ) ;
if ( ( V_14 -> V_17 = F_5 () ) == NULL ) goto V_19;
V_14 -> V_17 -> type = V_18 ;
}
F_6 ( V_14 -> V_20 ) ;
V_14 -> V_20 = F_7 ( type -> V_15 ) ;
if ( V_14 -> V_20 == NULL )
{
F_8 ( V_21 , V_22 ) ;
goto V_19;
}
if ( V_14 -> V_20 -> V_23 == 0 )
{
F_8 ( V_21 , V_24 ) ;
goto V_19;
}
}
V_11 = F_18 ( V_30 , & V_8 , V_29 ) ;
V_13 = V_12 = F_10 ( V_5 ) ;
V_9 = ( unsigned char * ) F_9 ( ( unsigned int ) V_12 ) ;
if ( ( V_8 == NULL ) || ( V_9 == NULL ) )
{
V_12 = 0 ;
F_8 ( V_21 , V_25 ) ;
goto V_19;
}
F_11 ( & V_6 , type , NULL ) ;
F_12 ( & V_6 , ( unsigned char * ) V_8 , V_11 ) ;
if ( ! F_13 ( & V_6 , ( unsigned char * ) V_9 ,
( unsigned int * ) & V_12 , V_5 ) )
{
V_12 = 0 ;
F_8 ( V_21 , V_26 ) ;
goto V_19;
}
if ( V_3 -> V_4 != NULL ) F_14 ( V_3 -> V_4 ) ;
V_3 -> V_4 = V_9 ;
V_9 = NULL ;
V_3 -> V_23 = V_12 ;
V_3 -> V_27 &= ~ ( V_28 | 0x07 ) ;
V_3 -> V_27 |= V_28 ;
V_19:
F_15 ( & V_6 ) ;
if ( V_8 != NULL )
{ F_16 ( ( char * ) V_8 , ( unsigned int ) V_11 ) ; F_14 ( V_8 ) ; }
if ( V_9 != NULL )
{ F_16 ( ( char * ) V_9 , V_13 ) ; F_14 ( V_9 ) ; }
return ( V_12 ) ;
}
