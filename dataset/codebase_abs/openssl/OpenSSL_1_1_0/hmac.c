int F_1 ( T_1 * V_1 , const void * V_2 , int V_3 ,
const T_2 * V_4 , T_3 * V_5 )
{
int V_6 , V_7 , V_8 = 0 ;
unsigned char V_9 [ V_10 ] ;
if ( V_4 != NULL && V_4 != V_1 -> V_4 && ( V_2 == NULL || V_3 < 0 ) )
return 0 ;
if ( V_4 != NULL ) {
V_8 = 1 ;
V_1 -> V_4 = V_4 ;
} else if ( V_1 -> V_4 ) {
V_4 = V_1 -> V_4 ;
} else {
return 0 ;
}
if ( V_2 != NULL ) {
V_8 = 1 ;
V_7 = F_2 ( V_4 ) ;
F_3 ( V_7 <= ( int ) sizeof( V_1 -> V_2 ) ) ;
if ( V_7 < V_3 ) {
if ( ! F_4 ( V_1 -> V_11 , V_4 , V_5 ) )
goto V_12;
if ( ! F_5 ( V_1 -> V_11 , V_2 , V_3 ) )
goto V_12;
if ( ! F_6 ( V_1 -> V_11 , V_1 -> V_2 ,
& V_1 -> V_13 ) )
goto V_12;
} else {
if ( V_3 < 0 || V_3 > ( int ) sizeof( V_1 -> V_2 ) )
return 0 ;
memcpy ( V_1 -> V_2 , V_2 , V_3 ) ;
V_1 -> V_13 = V_3 ;
}
if ( V_1 -> V_13 != V_10 )
memset ( & V_1 -> V_2 [ V_1 -> V_13 ] , 0 ,
V_10 - V_1 -> V_13 ) ;
}
if ( V_8 ) {
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
V_9 [ V_6 ] = 0x36 ^ V_1 -> V_2 [ V_6 ] ;
if ( ! F_4 ( V_1 -> V_14 , V_4 , V_5 ) )
goto V_12;
if ( ! F_5 ( V_1 -> V_14 , V_9 , F_2 ( V_4 ) ) )
goto V_12;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
V_9 [ V_6 ] = 0x5c ^ V_1 -> V_2 [ V_6 ] ;
if ( ! F_4 ( V_1 -> V_15 , V_4 , V_5 ) )
goto V_12;
if ( ! F_5 ( V_1 -> V_15 , V_9 , F_2 ( V_4 ) ) )
goto V_12;
}
if ( ! F_7 ( V_1 -> V_11 , V_1 -> V_14 ) )
goto V_12;
return 1 ;
V_12:
return 0 ;
}
int F_8 ( T_1 * V_1 , const void * V_2 , int V_3 , const T_2 * V_4 )
{
if ( V_2 && V_4 )
F_9 ( V_1 ) ;
return F_1 ( V_1 , V_2 , V_3 , V_4 , NULL ) ;
}
int F_10 ( T_1 * V_1 , const unsigned char * V_16 , T_4 V_3 )
{
if ( ! V_1 -> V_4 )
return 0 ;
return F_5 ( V_1 -> V_11 , V_16 , V_3 ) ;
}
int F_11 ( T_1 * V_1 , unsigned char * V_4 , unsigned int * V_3 )
{
unsigned int V_6 ;
unsigned char V_17 [ V_18 ] ;
if ( ! V_1 -> V_4 )
goto V_12;
if ( ! F_6 ( V_1 -> V_11 , V_17 , & V_6 ) )
goto V_12;
if ( ! F_7 ( V_1 -> V_11 , V_1 -> V_15 ) )
goto V_12;
if ( ! F_5 ( V_1 -> V_11 , V_17 , V_6 ) )
goto V_12;
if ( ! F_6 ( V_1 -> V_11 , V_4 , V_3 ) )
goto V_12;
return 1 ;
V_12:
return 0 ;
}
T_4 F_12 ( const T_1 * V_1 )
{
return F_13 ( ( V_1 ) -> V_4 ) ;
}
T_1 * F_14 ( void )
{
T_1 * V_1 = F_15 ( sizeof( T_1 ) ) ;
if ( V_1 != NULL ) {
if ( ! F_9 ( V_1 ) ) {
F_16 ( V_1 ) ;
return NULL ;
}
}
return V_1 ;
}
static void F_17 ( T_1 * V_1 )
{
F_18 ( V_1 -> V_14 ) ;
F_18 ( V_1 -> V_15 ) ;
F_18 ( V_1 -> V_11 ) ;
V_1 -> V_4 = NULL ;
V_1 -> V_13 = 0 ;
F_19 ( V_1 -> V_2 , sizeof( V_1 -> V_2 ) ) ;
}
void F_16 ( T_1 * V_1 )
{
if ( V_1 != NULL ) {
F_17 ( V_1 ) ;
F_20 ( V_1 -> V_14 ) ;
F_20 ( V_1 -> V_15 ) ;
F_20 ( V_1 -> V_11 ) ;
F_21 ( V_1 ) ;
}
}
int F_9 ( T_1 * V_1 )
{
F_17 ( V_1 ) ;
if ( V_1 -> V_14 == NULL )
V_1 -> V_14 = F_22 () ;
if ( V_1 -> V_14 == NULL )
goto V_12;
if ( V_1 -> V_15 == NULL )
V_1 -> V_15 = F_22 () ;
if ( V_1 -> V_15 == NULL )
goto V_12;
if ( V_1 -> V_11 == NULL )
V_1 -> V_11 = F_22 () ;
if ( V_1 -> V_11 == NULL )
goto V_12;
V_1 -> V_4 = NULL ;
return 1 ;
V_12:
F_17 ( V_1 ) ;
return 0 ;
}
int F_23 ( T_1 * V_19 , T_1 * V_20 )
{
if ( ! F_9 ( V_19 ) )
goto V_12;
if ( ! F_7 ( V_19 -> V_14 , V_20 -> V_14 ) )
goto V_12;
if ( ! F_7 ( V_19 -> V_15 , V_20 -> V_15 ) )
goto V_12;
if ( ! F_7 ( V_19 -> V_11 , V_20 -> V_11 ) )
goto V_12;
memcpy ( V_19 -> V_2 , V_20 -> V_2 , V_10 ) ;
V_19 -> V_13 = V_20 -> V_13 ;
V_19 -> V_4 = V_20 -> V_4 ;
return 1 ;
V_12:
F_17 ( V_19 ) ;
return 0 ;
}
unsigned char * F_24 ( const T_2 * V_21 , const void * V_2 , int V_22 ,
const unsigned char * V_23 , T_4 V_24 , unsigned char * V_4 ,
unsigned int * V_25 )
{
T_1 * V_26 = NULL ;
static unsigned char V_27 [ V_18 ] ;
static const unsigned char V_28 [ 1 ] = { '\0' } ;
if ( V_4 == NULL )
V_4 = V_27 ;
if ( ( V_26 = F_14 () ) == NULL )
goto V_12;
if ( V_2 == NULL && V_22 == 0 ) {
V_2 = V_28 ;
}
if ( ! F_1 ( V_26 , V_2 , V_22 , V_21 , NULL ) )
goto V_12;
if ( ! F_10 ( V_26 , V_23 , V_24 ) )
goto V_12;
if ( ! F_11 ( V_26 , V_4 , V_25 ) )
goto V_12;
F_16 ( V_26 ) ;
return V_4 ;
V_12:
F_16 ( V_26 ) ;
return NULL ;
}
void F_25 ( T_1 * V_1 , unsigned long V_29 )
{
F_26 ( V_1 -> V_14 , V_29 ) ;
F_26 ( V_1 -> V_15 , V_29 ) ;
F_26 ( V_1 -> V_11 , V_29 ) ;
}
const T_2 * F_27 ( const T_1 * V_1 )
{
return V_1 -> V_4 ;
}
