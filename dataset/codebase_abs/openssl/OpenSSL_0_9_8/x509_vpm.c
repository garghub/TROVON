static void F_1 ( T_1 * V_1 )
{
if ( ! V_1 )
return;
V_1 -> V_2 = NULL ;
V_1 -> V_3 = 0 ;
V_1 -> V_4 = 0 ;
V_1 -> V_5 = V_6 ;
V_1 -> V_7 = 0 ;
V_1 -> V_8 = - 1 ;
if ( V_1 -> V_9 )
{
F_2 ( V_1 -> V_9 , V_10 ) ;
V_1 -> V_9 = NULL ;
}
}
T_1 * F_3 ( void )
{
T_1 * V_1 ;
V_1 = F_4 ( sizeof( T_1 ) ) ;
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
F_1 ( V_1 ) ;
return V_1 ;
}
void F_5 ( T_1 * V_1 )
{
F_1 ( V_1 ) ;
F_6 ( V_1 ) ;
}
int F_7 ( T_1 * V_11 ,
const T_1 * V_12 )
{
unsigned long V_5 ;
int V_13 , V_14 ;
if ( ! V_12 )
return 1 ;
V_5 = V_11 -> V_5 | V_12 -> V_5 ;
if ( V_5 & V_15 )
V_11 -> V_5 = 0 ;
if ( V_5 & V_16 )
return 1 ;
if ( V_5 & V_6 )
V_13 = 1 ;
else
V_13 = 0 ;
if ( V_5 & V_17 )
V_14 = 1 ;
else
V_14 = 0 ;
F_8 ( V_3 , 0 ) ;
F_8 ( V_4 , 0 ) ;
F_8 ( V_8 , - 1 ) ;
if ( V_5 & V_18 )
V_11 -> V_7 = 0 ;
V_11 -> V_7 |= V_12 -> V_7 ;
if ( F_9 ( V_9 , NULL ) )
{
if ( ! F_10 ( V_11 , V_12 -> V_9 ) )
return 0 ;
}
return 1 ;
}
int F_11 ( T_1 * V_19 ,
const T_1 * V_20 )
{
V_19 -> V_5 |= V_6 ;
return F_7 ( V_19 , V_20 ) ;
}
int F_12 ( T_1 * V_1 , const char * V_2 )
{
if ( V_1 -> V_2 )
F_6 ( V_1 -> V_2 ) ;
V_1 -> V_2 = F_13 ( V_2 ) ;
if ( V_1 -> V_2 )
return 1 ;
return 0 ;
}
int F_14 ( T_1 * V_1 , unsigned long V_7 )
{
V_1 -> V_7 |= V_7 ;
if ( V_7 & V_21 )
V_1 -> V_7 |= V_22 ;
return 1 ;
}
int F_15 ( T_1 * V_1 , int V_3 )
{
return F_16 ( & V_1 -> V_3 , V_3 ) ;
}
int F_17 ( T_1 * V_1 , int V_4 )
{
return F_18 ( & V_1 -> V_4 , V_4 ) ;
}
void F_19 ( T_1 * V_1 , int V_8 )
{
V_1 -> V_8 = V_8 ;
}
void F_20 ( T_1 * V_1 , T_2 V_23 )
{
V_1 -> V_24 = V_23 ;
V_1 -> V_7 |= V_25 ;
}
int F_21 ( T_1 * V_1 , T_3 * V_26 )
{
if ( ! V_1 -> V_9 )
{
V_1 -> V_9 = F_22 () ;
if ( ! V_1 -> V_9 )
return 0 ;
}
if ( ! F_23 ( V_1 -> V_9 , V_26 ) )
return 0 ;
return 1 ;
}
int F_24 ( const T_1 * V_1 )
{
return V_1 -> V_8 ;
}
static int F_25 ( const void * V_27 , const void * V_28 )
{
const T_1 * V_29 = V_27 , * V_30 = V_28 ;
return strcmp ( V_29 -> V_2 , V_30 -> V_2 ) ;
}
static int F_26 ( const T_1 * const * V_29 ,
const T_1 * const * V_30 )
{
return strcmp ( ( * V_29 ) -> V_2 , ( * V_30 ) -> V_2 ) ;
}
int F_27 ( T_1 * V_1 )
{
int V_31 ;
T_1 * V_32 ;
if ( ! V_33 )
{
V_33 = F_28 ( F_26 ) ;
if ( ! V_33 )
return 0 ;
}
else
{
V_31 = F_29 ( V_33 , V_1 ) ;
if ( V_31 != - 1 )
{
V_32 = F_30 ( V_33 , V_31 ) ;
F_5 ( V_32 ) ;
F_31 ( V_33 , V_31 ) ;
}
}
if ( ! F_32 ( V_33 , V_1 ) )
return 0 ;
return 1 ;
}
const T_1 * F_33 ( const char * V_2 )
{
int V_31 ;
T_1 V_34 ;
V_34 . V_2 = ( char * ) V_2 ;
if ( V_33 )
{
V_31 = F_29 ( V_33 , & V_34 ) ;
if ( V_31 != - 1 )
return F_30 ( V_33 , V_31 ) ;
}
return ( const T_1 * ) F_34 ( ( char * ) & V_34 ,
( char * ) & V_35 ,
sizeof( V_35 ) / sizeof( T_1 ) ,
sizeof( T_1 ) ,
F_25 ) ;
}
void F_35 ( void )
{
if ( V_33 )
F_36 ( V_33 ,
F_5 ) ;
V_33 = NULL ;
}
