int F_1 ( T_1 * V_1 , T_2 * V_2 , T_2 * V_3 ,
T_3 * V_4 , char * V_5 , T_4 * V_6 ,
const T_5 * type )
{
T_6 V_7 ;
unsigned char * V_8 , * V_9 = NULL , * V_10 = NULL ;
int V_11 , V_12 = 0 , V_13 = 0 , V_14 = 0 ;
T_2 * V_15 ;
F_2 ( & V_7 ) ;
for ( V_11 = 0 ; V_11 < 2 ; V_11 ++ )
{
if ( V_11 == 0 )
V_15 = V_2 ;
else
V_15 = V_3 ;
if ( V_15 == NULL ) continue;
if ( type -> V_16 == V_17 )
{
F_3 ( V_15 -> V_18 ) ;
V_15 -> V_18 = NULL ;
}
else if ( ( V_15 -> V_18 == NULL ) ||
( V_15 -> V_18 -> type != V_19 ) )
{
F_3 ( V_15 -> V_18 ) ;
if ( ( V_15 -> V_18 = F_4 () ) == NULL ) goto V_20;
V_15 -> V_18 -> type = V_19 ;
}
F_5 ( V_15 -> V_21 ) ;
V_15 -> V_21 = F_6 ( type -> V_16 ) ;
if ( V_15 -> V_21 == NULL )
{
F_7 ( V_22 , V_23 ) ;
goto V_20;
}
if ( V_15 -> V_21 -> V_24 == 0 )
{
F_7 ( V_22 , V_25 ) ;
goto V_20;
}
}
V_12 = V_1 ( V_5 , NULL ) ;
V_9 = ( unsigned char * ) F_8 ( ( unsigned int ) V_12 ) ;
V_14 = V_13 = F_9 ( V_6 ) ;
V_10 = ( unsigned char * ) F_8 ( ( unsigned int ) V_13 ) ;
if ( ( V_9 == NULL ) || ( V_10 == NULL ) )
{
V_13 = 0 ;
F_7 ( V_22 , V_26 ) ;
goto V_20;
}
V_8 = V_9 ;
V_1 ( V_5 , & V_8 ) ;
F_10 ( & V_7 , type , NULL ) ;
F_11 ( & V_7 , ( unsigned char * ) V_9 , V_12 ) ;
if ( ! F_12 ( & V_7 , ( unsigned char * ) V_10 ,
( unsigned int * ) & V_13 , V_6 ) )
{
V_13 = 0 ;
F_7 ( V_22 , V_27 ) ;
goto V_20;
}
if ( V_4 -> V_5 != NULL ) F_13 ( V_4 -> V_5 ) ;
V_4 -> V_5 = V_10 ;
V_10 = NULL ;
V_4 -> V_24 = V_13 ;
V_4 -> V_28 &= ~ ( V_29 | 0x07 ) ;
V_4 -> V_28 |= V_29 ;
V_20:
F_14 ( & V_7 ) ;
if ( V_9 != NULL )
{ F_15 ( ( char * ) V_9 , ( unsigned int ) V_12 ) ; F_13 ( V_9 ) ; }
if ( V_10 != NULL )
{ F_15 ( ( char * ) V_10 , V_14 ) ; F_13 ( V_10 ) ; }
return ( V_13 ) ;
}
int F_16 ( const T_7 * V_30 , T_2 * V_2 , T_2 * V_3 ,
T_3 * V_4 , void * V_31 , T_4 * V_6 ,
const T_5 * type )
{
T_6 V_7 ;
unsigned char * V_9 = NULL , * V_10 = NULL ;
int V_11 , V_12 = 0 , V_13 = 0 , V_14 = 0 ;
T_2 * V_15 ;
F_2 ( & V_7 ) ;
for ( V_11 = 0 ; V_11 < 2 ; V_11 ++ )
{
if ( V_11 == 0 )
V_15 = V_2 ;
else
V_15 = V_3 ;
if ( V_15 == NULL ) continue;
if ( type -> V_16 == V_17 ||
type -> V_16 == V_32 )
{
F_3 ( V_15 -> V_18 ) ;
V_15 -> V_18 = NULL ;
}
else if ( ( V_15 -> V_18 == NULL ) ||
( V_15 -> V_18 -> type != V_19 ) )
{
F_3 ( V_15 -> V_18 ) ;
if ( ( V_15 -> V_18 = F_4 () ) == NULL ) goto V_20;
V_15 -> V_18 -> type = V_19 ;
}
F_5 ( V_15 -> V_21 ) ;
V_15 -> V_21 = F_6 ( type -> V_16 ) ;
if ( V_15 -> V_21 == NULL )
{
F_7 ( V_33 , V_23 ) ;
goto V_20;
}
if ( V_15 -> V_21 -> V_24 == 0 )
{
F_7 ( V_33 , V_25 ) ;
goto V_20;
}
}
V_12 = F_17 ( V_31 , & V_9 , V_30 ) ;
V_14 = V_13 = F_9 ( V_6 ) ;
V_10 = ( unsigned char * ) F_8 ( ( unsigned int ) V_13 ) ;
if ( ( V_9 == NULL ) || ( V_10 == NULL ) )
{
V_13 = 0 ;
F_7 ( V_33 , V_26 ) ;
goto V_20;
}
F_10 ( & V_7 , type , NULL ) ;
F_11 ( & V_7 , ( unsigned char * ) V_9 , V_12 ) ;
if ( ! F_12 ( & V_7 , ( unsigned char * ) V_10 ,
( unsigned int * ) & V_13 , V_6 ) )
{
V_13 = 0 ;
F_7 ( V_33 , V_27 ) ;
goto V_20;
}
if ( V_4 -> V_5 != NULL ) F_13 ( V_4 -> V_5 ) ;
V_4 -> V_5 = V_10 ;
V_10 = NULL ;
V_4 -> V_24 = V_13 ;
V_4 -> V_28 &= ~ ( V_29 | 0x07 ) ;
V_4 -> V_28 |= V_29 ;
V_20:
F_14 ( & V_7 ) ;
if ( V_9 != NULL )
{ F_15 ( ( char * ) V_9 , ( unsigned int ) V_12 ) ; F_13 ( V_9 ) ; }
if ( V_10 != NULL )
{ F_15 ( ( char * ) V_10 , V_14 ) ; F_13 ( V_10 ) ; }
return ( V_13 ) ;
}
