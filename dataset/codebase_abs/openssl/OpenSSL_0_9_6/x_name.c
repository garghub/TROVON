int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_6 ) ;
F_4 () ;
F_5 ( V_1 -> V_3 , V_4 ) ;
F_5 ( V_1 -> V_5 , V_6 ) ;
F_6 () ;
}
T_1 * F_7 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_7 )
{
F_8 ( V_1 , T_1 * , V_8 ) ;
F_9 () ;
F_10 () ;
F_11 ( V_9 -> V_3 , V_10 ) ;
F_11 ( V_9 -> V_5 , V_11 ) ;
V_9 -> V_12 = 0 ;
F_12 ( V_1 , V_13 , V_14 ) ;
}
int F_13 ( T_2 * V_1 , unsigned char * * V_2 )
{
int V_9 ;
if ( V_1 == NULL ) return ( 0 ) ;
if ( V_1 -> V_15 )
{
V_9 = F_14 ( V_1 ) ;
if ( V_9 < 0 ) return ( V_9 ) ;
}
V_9 = V_1 -> V_16 -> V_7 ;
if ( V_2 != NULL )
{
memcpy ( * V_2 , V_1 -> V_16 -> V_17 , V_9 ) ;
* V_2 += V_9 ;
}
return ( V_9 ) ;
}
static int F_14 ( T_2 * V_1 )
{
T_1 * V_18 , * V_19 = NULL ;
F_15 ( T_1 ) * V_20 ;
T_3 * V_21 = NULL ;
int V_12 = 0 , V_22 , V_9 = 0 ;
int V_23 ;
unsigned char * V_24 ;
int V_25 = 0 ;
V_20 = V_1 -> V_26 ;
for ( V_23 = 0 ; V_23 < F_16 ( V_20 ) ; V_23 ++ )
{
V_18 = F_17 ( V_20 , V_23 ) ;
if ( V_19 == NULL )
{
V_19 = V_18 ;
V_25 = 0 ;
}
if ( V_18 -> V_12 != V_12 )
{
V_9 += F_18 ( 1 , V_25 , V_27 ) ;
V_19 -> V_25 = V_25 ;
V_19 = V_18 ;
V_25 = 0 ;
V_12 = V_18 -> V_12 ;
}
V_25 += F_1 ( V_18 , NULL ) ;
}
V_9 += F_18 ( 1 , V_25 , V_27 ) ;
if ( V_19 != NULL )
V_19 -> V_25 = V_25 ;
V_22 = F_18 ( 1 , V_9 , V_28 ) ;
V_21 = V_1 -> V_16 ;
if ( ! F_19 ( V_21 , V_22 ) ) goto V_29;
V_24 = ( unsigned char * ) V_21 -> V_17 ;
F_20 ( & V_24 , 1 , V_9 , V_28 , V_30 ) ;
V_12 = - 1 ;
for ( V_23 = 0 ; V_23 < F_16 ( V_20 ) ; V_23 ++ )
{
V_18 = F_17 ( V_20 , V_23 ) ;
if ( V_12 != V_18 -> V_12 )
{
V_12 = V_18 -> V_12 ;
F_20 ( & V_24 , 1 , V_18 -> V_25 ,
V_27 , V_30 ) ;
}
F_1 ( V_18 , & V_24 ) ;
}
V_1 -> V_15 = 0 ;
return ( V_22 ) ;
V_29:
return ( - 1 ) ;
}
T_2 * F_21 ( T_2 * * V_1 , unsigned char * * V_2 , long V_7 )
{
int V_12 = 0 , V_23 ;
int V_31 = 0 ;
unsigned char * V_32 ;
F_8 ( V_1 , T_2 * , V_33 ) ;
V_32 = * V_2 ;
if ( F_16 ( V_9 -> V_26 ) > 0 )
{
while ( F_16 ( V_9 -> V_26 ) > 0 )
V_13 (
F_22 ( V_9 -> V_26 ) ) ;
}
F_9 () ;
F_10 () ;
for (; ; )
{
if ( F_23 () ) break;
F_24 ( T_1 , V_9 -> V_26 ,
F_7 ,
V_13 ) ;
for (; V_31 < F_16 ( V_9 -> V_26 ) ; V_31 ++ )
{
F_17 ( V_9 -> V_26 , V_31 ) -> V_12 = V_12 ;
}
V_12 ++ ;
}
V_23 = ( int ) ( V_34 . V_24 - V_32 ) ;
if ( ! F_19 ( V_9 -> V_16 , V_23 ) ) goto V_29;
memcpy ( V_9 -> V_16 -> V_17 , V_32 , V_23 ) ;
V_9 -> V_16 -> V_7 = V_23 ;
V_9 -> V_15 = 0 ;
F_12 ( V_1 , V_35 , V_36 ) ;
}
T_2 * V_33 ( void )
{
T_2 * V_9 = NULL ;
T_4 V_34 ;
F_25 ( V_9 , T_2 ) ;
if ( ( V_9 -> V_26 = F_26 () ) == NULL )
{ V_34 . line = __LINE__ ; goto V_37; }
F_27 ( V_9 -> V_16 , V_38 ) ;
V_9 -> V_15 = 1 ;
return ( V_9 ) ;
F_28 ( V_39 ) ;
}
T_1 * V_8 ( void )
{
T_1 * V_9 = NULL ;
T_4 V_34 ;
F_25 ( V_9 , T_1 ) ;
V_9 -> V_3 = NULL ;
V_9 -> V_12 = 0 ;
F_27 ( V_9 -> V_5 , V_40 ) ;
return ( V_9 ) ;
F_28 ( V_41 ) ;
}
void V_35 ( T_2 * V_1 )
{
if( V_1 == NULL )
return;
F_29 ( V_1 -> V_16 ) ;
F_30 ( V_1 -> V_26 , V_13 ) ;
F_31 ( V_1 ) ;
}
void V_13 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_32 ( V_1 -> V_3 ) ;
F_33 ( V_1 -> V_5 ) ;
F_31 ( V_1 ) ;
}
int F_34 ( T_2 * * V_42 , T_2 * V_43 )
{
T_2 * V_44 ;
if ( * V_42 == NULL ) return ( 0 ) ;
if ( * V_42 != V_43 )
{
V_44 = F_35 ( V_43 ) ;
if ( V_44 != NULL )
{
V_35 ( * V_42 ) ;
* V_42 = V_44 ;
}
}
return ( * V_42 != NULL ) ;
}
