T_1 * F_1 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_3 , int type )
{
T_1 * V_4 = NULL ;
unsigned char * V_5 , * V_6 ;
long V_7 ;
int V_8 , V_9 , V_10 ;
int V_11 = 0 ;
V_5 = * V_2 ;
V_8 = F_2 ( & V_5 , & V_7 , & V_9 , & V_10 , V_3 ) ;
if ( V_8 & 0x80 ) goto V_12;
if ( V_9 >= 32 )
{
V_11 = V_13 ; ;
goto V_12;
}
if ( ! ( V_14 [ V_9 ] & type ) )
{
V_11 = V_15 ;
goto V_12;
}
if ( V_9 == V_16 )
return ( F_3 ( V_1 , V_2 , V_3 ) ) ;
if ( ( V_1 == NULL ) || ( ( * V_1 ) == NULL ) )
{
if ( ( V_4 = F_4 () ) == NULL ) return ( NULL ) ;
}
else
V_4 = ( * V_1 ) ;
if ( V_7 != 0 )
{
V_6 = ( unsigned char * ) F_5 ( ( int ) V_7 + 1 ) ;
if ( V_6 == NULL )
{
V_11 = V_17 ;
goto V_12;
}
memcpy ( V_6 , V_5 , ( int ) V_7 ) ;
V_6 [ V_7 ] = '\0' ;
V_5 += V_7 ;
}
else
V_6 = NULL ;
if ( V_4 -> V_18 != NULL ) F_6 ( V_4 -> V_18 ) ;
V_4 -> V_3 = ( int ) V_7 ;
V_4 -> V_18 = V_6 ;
V_4 -> type = V_9 ;
if ( V_1 != NULL ) ( * V_1 ) = V_4 ;
* V_2 = V_5 ;
return ( V_4 ) ;
V_12:
F_7 ( V_19 , V_11 ) ;
if ( ( V_4 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_4 ) ) )
F_8 ( V_4 ) ;
return ( NULL ) ;
}
int F_9 ( T_1 * V_1 , unsigned char * * V_2 , int V_9 , int V_10 )
{
int V_4 , V_20 , V_21 ;
unsigned char * V_5 ;
if ( V_1 == NULL ) return ( 0 ) ;
if ( V_9 == V_16 )
return ( F_10 ( V_1 , V_2 ) ) ;
V_4 = V_1 -> V_3 ;
V_20 = F_11 ( 0 , V_4 , V_9 ) ;
if ( V_2 == NULL ) return ( V_20 ) ;
V_5 = * V_2 ;
if ( ( V_9 == V_22 ) || ( V_9 == V_23 ) )
V_21 = 1 ;
else
V_21 = 0 ;
F_12 ( & V_5 , V_21 , V_4 , V_9 , V_10 ) ;
memcpy ( V_5 , V_1 -> V_18 , V_1 -> V_3 ) ;
V_5 += V_1 -> V_3 ;
* V_2 = V_5 ;
return ( V_20 ) ;
}
T_1 * F_13 ( T_1 * * V_1 , unsigned char * * V_2 , long V_3 ,
int V_24 , int V_25 )
{
T_1 * V_4 = NULL ;
unsigned char * V_5 , * V_6 ;
long V_7 ;
int V_8 , V_9 , V_10 ;
int V_11 = 0 ;
if ( ( V_1 == NULL ) || ( ( * V_1 ) == NULL ) )
{
if ( ( V_4 = F_4 () ) == NULL ) return ( NULL ) ;
}
else
V_4 = ( * V_1 ) ;
V_5 = * V_2 ;
V_8 = F_2 ( & V_5 , & V_7 , & V_9 , & V_10 , V_3 ) ;
if ( V_8 & 0x80 )
{
V_11 = V_26 ;
goto V_12;
}
if ( V_9 != V_24 )
{
V_11 = V_27 ;
goto V_12;
}
if ( V_8 & V_28 )
{
T_2 V_29 ;
V_29 . V_2 = V_2 ;
V_29 . V_5 = V_5 ;
V_29 . V_8 = V_8 ;
V_29 . V_30 = V_7 ;
V_29 . V_9 = V_24 ;
V_29 . V_10 = V_25 ;
V_29 . V_31 = ( V_3 == 0 ) ? 0 : ( V_5 + V_3 ) ;
if ( ! F_14 ( V_4 , & V_29 ) )
goto V_12;
else
{
V_5 = V_29 . V_5 ;
}
}
else
{
if ( V_7 != 0 )
{
if ( ( V_4 -> V_3 < V_7 ) || ( V_4 -> V_18 == NULL ) )
{
if ( V_4 -> V_18 != NULL ) F_6 ( V_4 -> V_18 ) ;
V_6 = ( unsigned char * ) F_5 ( ( int ) V_7 + 1 ) ;
if ( V_6 == NULL )
{
V_11 = V_17 ;
goto V_12;
}
}
else
V_6 = V_4 -> V_18 ;
memcpy ( V_6 , V_5 , ( int ) V_7 ) ;
V_6 [ V_7 ] = '\0' ;
V_5 += V_7 ;
}
else
{
V_6 = NULL ;
if ( V_4 -> V_18 != NULL ) F_6 ( V_4 -> V_18 ) ;
}
V_4 -> V_3 = ( int ) V_7 ;
V_4 -> V_18 = V_6 ;
V_4 -> type = V_24 ;
}
if ( V_1 != NULL ) ( * V_1 ) = V_4 ;
* V_2 = V_5 ;
return ( V_4 ) ;
V_12:
if ( ( V_4 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_4 ) ) )
F_8 ( V_4 ) ;
F_7 ( V_32 , V_11 ) ;
return ( NULL ) ;
}
static int F_14 ( T_1 * V_1 , T_2 * V_29 )
{
T_1 * V_33 = NULL ;
T_3 V_34 ;
int V_35 ;
V_34 . V_3 = 0 ;
V_34 . V_31 = 0 ;
V_34 . V_18 = NULL ;
if ( V_1 == NULL )
{
V_29 -> error = V_36 ;
goto V_12;
}
V_35 = 0 ;
for (; ; )
{
if ( V_29 -> V_8 & 1 )
{
V_29 -> V_37 = F_15 ( & V_29 -> V_5 ,
( long ) ( V_29 -> V_31 - V_29 -> V_5 ) ) ;
if ( V_29 -> V_37 ) break;
}
else
{
if ( V_29 -> V_30 <= 0 ) break;
}
V_29 -> V_38 = V_29 -> V_5 ;
if ( F_13 ( & V_33 , & V_29 -> V_5 , V_29 -> V_31 - V_29 -> V_5 , V_29 -> V_9 , V_29 -> V_10 )
== NULL )
{
V_29 -> error = V_39 ;
goto V_12;
}
if ( ! F_16 ( & V_34 , V_35 + V_33 -> V_3 ) )
{
V_29 -> error = V_40 ;
goto V_12;
}
memcpy ( & ( V_34 . V_18 [ V_35 ] ) , V_33 -> V_18 , V_33 -> V_3 ) ;
if ( ! ( V_29 -> V_8 & 1 ) )
V_29 -> V_30 -= ( V_29 -> V_5 - V_29 -> V_38 ) ;
V_35 += V_33 -> V_3 ;
}
if ( ! F_17 ( V_29 ) ) goto V_12;
V_1 -> V_3 = V_35 ;
if ( V_1 -> V_18 != NULL ) F_6 ( V_1 -> V_18 ) ;
V_1 -> V_18 = ( unsigned char * ) V_34 . V_18 ;
if ( V_33 != NULL ) F_8 ( V_33 ) ;
return ( 1 ) ;
V_12:
F_7 ( V_41 , V_29 -> error ) ;
if ( V_33 != NULL ) F_8 ( V_33 ) ;
if ( V_34 . V_18 != NULL ) F_6 ( V_34 . V_18 ) ;
return ( 0 ) ;
}
