static int F_1 ( T_1 * * V_1 , const T_2 * V_2 )
{
* V_1 = ( T_1 * ) F_2 () ;
if ( * V_1 != NULL )
return 1 ;
else
return 0 ;
}
static void F_3 ( T_1 * * V_1 , const T_2 * V_2 )
{
if ( ! * V_1 )
return;
if ( V_2 -> V_3 & V_4 )
F_4 ( ( V_5 * ) * V_1 ) ;
else
F_5 ( ( V_5 * ) * V_1 ) ;
* V_1 = NULL ;
}
static int F_6 ( T_1 * * V_1 , unsigned char * V_6 , int * V_7 ,
const T_2 * V_2 )
{
V_5 * V_8 ;
int V_9 ;
if ( ! * V_1 )
return - 1 ;
V_8 = ( V_5 * ) * V_1 ;
if ( F_7 ( V_8 ) & 0x7 )
V_9 = 0 ;
else
V_9 = 1 ;
if ( V_6 ) {
if ( V_9 )
* V_6 ++ = 0 ;
F_8 ( V_8 , V_6 ) ;
}
return V_9 + F_9 ( V_8 ) ;
}
static int F_10 ( T_1 * * V_1 , const unsigned char * V_6 , int V_10 ,
int V_11 , char * V_12 , const T_2 * V_2 )
{
V_5 * V_8 ;
if ( * V_1 == NULL && ! F_11 ( V_1 , V_2 ) )
return 0 ;
V_8 = ( V_5 * ) * V_1 ;
if ( ! F_12 ( V_6 , V_10 , V_8 ) ) {
F_3 ( V_1 , V_2 ) ;
return 0 ;
}
return 1 ;
}
static int F_13 ( T_1 * * V_1 , const unsigned char * V_6 , int V_10 ,
int V_11 , char * V_12 , const T_2 * V_2 )
{
if ( ! * V_1 )
F_1 ( V_1 , V_2 ) ;
return F_10 ( V_1 , V_6 , V_10 , V_11 , V_12 , V_2 ) ;
}
static int F_14 ( T_3 * V_13 , T_1 * * V_1 , const T_2 * V_2 ,
int V_14 , const T_4 * V_15 )
{
if ( ! F_15 ( V_13 , * ( V_5 * * ) V_1 ) )
return 0 ;
if ( F_16 ( V_13 , L_1 ) <= 0 )
return 0 ;
return 1 ;
}
