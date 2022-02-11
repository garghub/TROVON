void F_1 ( T_1 * V_1 , void * V_2 )
{
F_2 ( (struct V_3 * ) V_1 , (struct V_4 * ) V_2 ) ;
}
void F_3 ( T_1 * V_1 , void * V_2 )
{
F_4 ( (struct V_3 * ) V_1 , (struct V_4 * ) V_2 ) ;
}
void * F_5 ( T_1 * V_1 )
{
return ( ( void * ) F_6 ( (struct V_3 * ) V_1 ) ) ;
}
int F_7 ( T_1 * V_1 )
{
return ( F_8 ( (struct V_3 * ) V_1 ) ) ;
}
int F_9 ( T_1 * V_1 )
{
return ( F_10 ( (struct V_3 * ) V_1 ) ) ;
}
void F_11 ( T_1 * V_1 )
{
F_12 ( (struct V_3 * ) V_1 ) ;
}
void *
F_13 ( int V_5 )
{
struct V_4 * V_6 ;
V_5 += 2 * ( F_14 () ) ;
V_6 = F_15 ( V_7 + sizeof( struct V_8 ) + V_5 ) ;
F_16 ( V_6 , V_7 + sizeof( struct V_8 ) + F_14 () ) ;
return ( ( void * ) V_6 ) ;
}
void *
F_17 ( int V_5 )
{
struct V_4 * V_6 ;
V_6 = F_15 ( V_5 ) ;
return ( ( void * ) V_6 ) ;
}
void
F_18 ( void * V_9 )
{
struct V_4 * V_6 = (struct V_4 * ) V_9 ;
F_19 ( V_6 ) ;
}
T_2 F_20 ( void * V_9 )
{
return ( ( (struct V_4 * ) V_9 ) -> V_10 ) ;
}
void *
F_21 ( void * V_9 )
{
return ( ( (struct V_4 * ) V_9 ) -> V_11 ) ;
}
int
F_22 ( void * V_9 , T_3 V_10 )
{
F_23 ( (struct V_4 * ) V_9 , V_10 ) ;
return 0 ;
}
int
F_24 ( void * V_9 , char * V_12 , T_3 V_10 )
{
F_23 ( (struct V_4 * ) V_9 , V_10 ) ;
memcpy ( ( (struct V_4 * ) V_9 ) -> V_11 , V_12 , V_10 ) ;
return 0 ;
}
int
F_25 ( void * V_9 , T_3 V_10 )
{
F_26 ( (struct V_4 * ) V_9 , V_10 ) ;
return 0 ;
}
int
F_27 ( void * V_9 , char * V_12 , T_3 V_10 )
{
char * V_13 = ( char * ) ( ( (struct V_4 * ) V_9 ) -> V_11 +
( (struct V_4 * ) V_9 ) -> V_10 ) ;
F_26 ( (struct V_4 * ) V_9 , V_10 ) ;
memcpy ( V_13 , V_12 , V_10 ) ;
return 0 ;
}
int
F_28 ( void * V_9 , T_3 V_10 )
{
F_29 ( (struct V_4 * ) V_9 , V_10 ) ;
return 0 ;
}
int
F_30 ( void * V_9 , T_3 V_10 )
{
F_29 ( (struct V_4 * ) V_9 , ( (struct V_4 * ) V_9 ) -> V_10 - V_10 ) ;
return 0 ;
}
int
F_31 ( void * V_9 , char * V_14 , T_3 V_10 )
{
char * V_13 = ( char * ) ( ( (struct V_4 * ) V_9 ) -> V_11 +
( ( (struct V_4 * ) V_9 ) -> V_10 - V_10 ) ) ;
memcpy ( V_14 , V_13 , V_10 ) ;
F_29 ( (struct V_4 * ) V_9 , ( (struct V_4 * ) V_9 ) -> V_10 - V_10 ) ;
return 0 ;
}
T_3 F_32 ( void * V_9 )
{
return ( F_33 ( (struct V_4 * ) V_9 ) ) ;
}
int
F_34 ( void * V_9 , T_3 V_10 )
{
F_35 ( (struct V_4 * ) V_9 , V_10 ) ;
return 0 ;
}
int
F_36 ( void * V_9 , char * V_14 , T_3 V_10 )
{
memcpy ( V_14 , ( (struct V_4 * ) V_9 ) -> V_11 , V_10 ) ;
F_35 ( (struct V_4 * ) V_9 , V_10 ) ;
return 0 ;
}
