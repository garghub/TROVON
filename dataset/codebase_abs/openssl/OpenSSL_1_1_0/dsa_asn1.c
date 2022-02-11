void F_1 ( const T_1 * V_1 , const T_2 * * V_2 , const T_2 * * V_3 )
{
if ( V_2 != NULL )
* V_2 = V_1 -> V_4 ;
if ( V_3 != NULL )
* V_3 = V_1 -> V_5 ;
}
int F_2 ( T_1 * V_1 , T_2 * V_4 , T_2 * V_5 )
{
if ( V_4 == NULL || V_5 == NULL )
return 0 ;
F_3 ( V_1 -> V_4 ) ;
F_3 ( V_1 -> V_5 ) ;
V_1 -> V_4 = V_4 ;
V_1 -> V_5 = V_5 ;
return 1 ;
}
static int F_4 ( int V_6 , T_3 * * V_7 , const T_4 * V_8 ,
void * V_9 )
{
if ( V_6 == V_10 ) {
* V_7 = ( T_3 * ) F_5 () ;
if ( * V_7 != NULL )
return 2 ;
return 0 ;
} else if ( V_6 == V_11 ) {
F_6 ( ( V_12 * ) * V_7 ) ;
* V_7 = NULL ;
return 2 ;
}
return 1 ;
}
int F_7 ( int type , const unsigned char * V_13 , int V_14 ,
unsigned char * V_1 , unsigned int * V_15 , V_12 * V_16 )
{
T_1 * V_5 ;
F_8 ( V_13 , V_14 ) ;
V_5 = F_9 ( V_13 , V_14 , V_16 ) ;
if ( V_5 == NULL ) {
* V_15 = 0 ;
return ( 0 ) ;
}
* V_15 = F_10 ( V_5 , & V_1 ) ;
F_11 ( V_5 ) ;
return ( 1 ) ;
}
int F_12 ( int type , const unsigned char * V_13 , int V_17 ,
const unsigned char * V_18 , int V_15 , V_12 * V_16 )
{
T_1 * V_5 ;
const unsigned char * V_19 = V_18 ;
unsigned char * V_20 = NULL ;
int V_21 = - 1 ;
int V_22 = - 1 ;
V_5 = F_13 () ;
if ( V_5 == NULL )
return ( V_22 ) ;
if ( F_14 ( & V_5 , & V_19 , V_15 ) == NULL )
goto V_23;
V_21 = F_10 ( V_5 , & V_20 ) ;
if ( V_21 != V_15 || memcmp ( V_18 , V_20 , V_21 ) )
goto V_23;
V_22 = F_15 ( V_13 , V_17 , V_5 , V_16 ) ;
V_23:
F_16 ( V_20 , V_21 ) ;
F_11 ( V_5 ) ;
return ( V_22 ) ;
}
