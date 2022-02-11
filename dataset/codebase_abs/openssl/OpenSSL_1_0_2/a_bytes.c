T_1 * F_1 ( T_1 * * V_1 , const unsigned char * * V_2 ,
long V_3 , int type )
{
T_1 * V_4 = NULL ;
const unsigned char * V_5 ;
unsigned char * V_6 ;
long V_7 ;
int V_8 , V_9 , V_10 ;
int V_11 = 0 ;
V_5 = * V_2 ;
V_8 = F_2 ( & V_5 , & V_7 , & V_9 , & V_10 , V_3 ) ;
if ( V_8 & 0x80 )
goto V_12;
if ( V_9 >= 32 ) {
V_11 = V_13 ;
goto V_12;
}
if ( ! ( F_3 ( V_9 ) & type ) ) {
V_11 = V_14 ;
goto V_12;
}
if ( V_9 == V_15 )
return ( F_4 ( V_1 , V_2 , V_3 ) ) ;
if ( ( V_1 == NULL ) || ( ( * V_1 ) == NULL ) ) {
if ( ( V_4 = F_5 () ) == NULL )
return ( NULL ) ;
} else
V_4 = ( * V_1 ) ;
if ( V_7 != 0 ) {
V_6 = ( unsigned char * ) F_6 ( ( int ) V_7 + 1 ) ;
if ( V_6 == NULL ) {
V_11 = V_16 ;
goto V_12;
}
memcpy ( V_6 , V_5 , ( int ) V_7 ) ;
V_6 [ V_7 ] = '\0' ;
V_5 += V_7 ;
} else
V_6 = NULL ;
if ( V_4 -> V_17 != NULL )
F_7 ( V_4 -> V_17 ) ;
V_4 -> V_3 = ( int ) V_7 ;
V_4 -> V_17 = V_6 ;
V_4 -> type = V_9 ;
if ( V_1 != NULL )
( * V_1 ) = V_4 ;
* V_2 = V_5 ;
return ( V_4 ) ;
V_12:
F_8 ( V_18 , V_11 ) ;
if ( ( V_4 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_4 ) ) )
F_9 ( V_4 ) ;
return ( NULL ) ;
}
int F_10 ( T_1 * V_1 , unsigned char * * V_2 , int V_9 , int V_10 )
{
int V_4 , V_19 , V_20 ;
unsigned char * V_5 ;
if ( V_1 == NULL )
return ( 0 ) ;
if ( V_9 == V_15 )
return ( F_11 ( V_1 , V_2 ) ) ;
V_4 = V_1 -> V_3 ;
V_19 = F_12 ( 0 , V_4 , V_9 ) ;
if ( V_2 == NULL )
return ( V_19 ) ;
V_5 = * V_2 ;
if ( ( V_9 == V_21 ) || ( V_9 == V_22 ) )
V_20 = 1 ;
else
V_20 = 0 ;
F_13 ( & V_5 , V_20 , V_4 , V_9 , V_10 ) ;
memcpy ( V_5 , V_1 -> V_17 , V_1 -> V_3 ) ;
V_5 += V_1 -> V_3 ;
* V_2 = V_5 ;
return ( V_19 ) ;
}
T_1 * F_14 ( T_1 * * V_1 , const unsigned char * * V_2 ,
long V_3 , int V_23 , int V_24 )
{
T_1 * V_4 = NULL ;
const unsigned char * V_5 ;
unsigned char * V_6 ;
long V_7 ;
int V_8 , V_9 , V_10 ;
int V_11 = 0 ;
if ( ( V_1 == NULL ) || ( ( * V_1 ) == NULL ) ) {
if ( ( V_4 = F_5 () ) == NULL )
return ( NULL ) ;
} else
V_4 = ( * V_1 ) ;
V_5 = * V_2 ;
V_8 = F_2 ( & V_5 , & V_7 , & V_9 , & V_10 , V_3 ) ;
if ( V_8 & 0x80 ) {
V_11 = V_25 ;
goto V_12;
}
if ( V_9 != V_23 ) {
V_11 = V_26 ;
goto V_12;
}
if ( V_8 & V_27 ) {
T_2 V_28 ;
V_28 . V_2 = V_2 ;
V_28 . V_5 = V_5 ;
V_28 . V_8 = V_8 ;
V_28 . V_29 = V_7 ;
V_28 . V_9 = V_23 ;
V_28 . V_10 = V_24 ;
V_28 . V_30 = ( V_3 == 0 ) ? 0 : ( V_5 + V_3 ) ;
if ( ! F_15 ( V_4 , & V_28 ) )
goto V_12;
else {
V_5 = V_28 . V_5 ;
}
} else {
if ( V_7 != 0 ) {
if ( ( V_4 -> V_3 < V_7 ) || ( V_4 -> V_17 == NULL ) ) {
if ( V_4 -> V_17 != NULL )
F_7 ( V_4 -> V_17 ) ;
V_6 = ( unsigned char * ) F_6 ( ( int ) V_7 + 1 ) ;
if ( V_6 == NULL ) {
V_11 = V_16 ;
goto V_12;
}
} else
V_6 = V_4 -> V_17 ;
memcpy ( V_6 , V_5 , ( int ) V_7 ) ;
V_6 [ V_7 ] = '\0' ;
V_5 += V_7 ;
} else {
V_6 = NULL ;
if ( V_4 -> V_17 != NULL )
F_7 ( V_4 -> V_17 ) ;
}
V_4 -> V_3 = ( int ) V_7 ;
V_4 -> V_17 = V_6 ;
V_4 -> type = V_23 ;
}
if ( V_1 != NULL )
( * V_1 ) = V_4 ;
* V_2 = V_5 ;
return ( V_4 ) ;
V_12:
if ( ( V_4 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_4 ) ) )
F_9 ( V_4 ) ;
F_8 ( V_31 , V_11 ) ;
return ( NULL ) ;
}
static int F_15 ( T_1 * V_1 , T_2 * V_28 )
{
T_1 * V_32 = NULL ;
T_3 V_33 ;
int V_34 ;
V_33 . V_3 = 0 ;
V_33 . V_30 = 0 ;
V_33 . V_17 = NULL ;
if ( V_1 == NULL ) {
V_28 -> error = V_35 ;
goto V_12;
}
V_34 = 0 ;
for (; ; ) {
if ( V_28 -> V_8 & 1 ) {
V_28 -> V_36 = F_16 ( & V_28 -> V_5 ,
( long ) ( V_28 -> V_30 - V_28 -> V_5 ) ) ;
if ( V_28 -> V_36 )
break;
} else {
if ( V_28 -> V_29 <= 0 )
break;
}
V_28 -> V_37 = V_28 -> V_5 ;
if ( F_14 ( & V_32 , & V_28 -> V_5 , V_28 -> V_30 - V_28 -> V_5 , V_28 -> V_9 , V_28 -> V_10 )
== NULL ) {
V_28 -> error = V_38 ;
goto V_12;
}
if ( ! F_17 ( & V_33 , V_34 + V_32 -> V_3 ) ) {
V_28 -> error = V_39 ;
goto V_12;
}
memcpy ( & ( V_33 . V_17 [ V_34 ] ) , V_32 -> V_17 , V_32 -> V_3 ) ;
if ( ! ( V_28 -> V_8 & 1 ) )
V_28 -> V_29 -= ( V_28 -> V_5 - V_28 -> V_37 ) ;
V_34 += V_32 -> V_3 ;
}
if ( ! F_18 ( V_28 ) )
goto V_12;
V_1 -> V_3 = V_34 ;
if ( V_1 -> V_17 != NULL )
F_7 ( V_1 -> V_17 ) ;
V_1 -> V_17 = ( unsigned char * ) V_33 . V_17 ;
if ( V_32 != NULL )
F_9 ( V_32 ) ;
return ( 1 ) ;
V_12:
F_8 ( V_40 , V_28 -> error ) ;
if ( V_32 != NULL )
F_9 ( V_32 ) ;
if ( V_33 . V_17 != NULL )
F_7 ( V_33 . V_17 ) ;
return ( 0 ) ;
}
