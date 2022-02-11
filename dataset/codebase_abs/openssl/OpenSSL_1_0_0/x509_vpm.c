static void F_1 ( T_1 * V_1 )
{
if ( ! V_1 )
return;
V_1 -> V_2 = NULL ;
V_1 -> V_3 = 0 ;
V_1 -> V_4 = 0 ;
V_1 -> V_5 = 0 ;
V_1 -> V_6 = 0 ;
V_1 -> V_7 = - 1 ;
if ( V_1 -> V_8 )
{
F_2 ( V_1 -> V_8 , V_9 ) ;
V_1 -> V_8 = NULL ;
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
int F_7 ( T_1 * V_10 ,
const T_1 * V_11 )
{
unsigned long V_5 ;
int V_12 , V_13 ;
if ( ! V_11 )
return 1 ;
V_5 = V_10 -> V_5 | V_11 -> V_5 ;
if ( V_5 & V_14 )
V_10 -> V_5 = 0 ;
if ( V_5 & V_15 )
return 1 ;
if ( V_5 & V_16 )
V_12 = 1 ;
else
V_12 = 0 ;
if ( V_5 & V_17 )
V_13 = 1 ;
else
V_13 = 0 ;
F_8 ( V_3 , 0 ) ;
F_8 ( V_4 , 0 ) ;
F_8 ( V_7 , - 1 ) ;
if ( V_13 || ! ( V_10 -> V_6 & V_18 ) )
{
V_10 -> V_19 = V_11 -> V_19 ;
V_10 -> V_6 &= ~ V_18 ;
}
if ( V_5 & V_20 )
V_10 -> V_6 = 0 ;
V_10 -> V_6 |= V_11 -> V_6 ;
if ( F_9 ( V_8 , NULL ) )
{
if ( ! F_10 ( V_10 , V_11 -> V_8 ) )
return 0 ;
}
return 1 ;
}
int F_11 ( T_1 * V_21 ,
const T_1 * V_22 )
{
unsigned long V_23 = V_21 -> V_5 ;
int V_24 ;
V_21 -> V_5 |= V_16 ;
V_24 = F_7 ( V_21 , V_22 ) ;
V_21 -> V_5 = V_23 ;
return V_24 ;
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
int F_14 ( T_1 * V_1 , unsigned long V_6 )
{
V_1 -> V_6 |= V_6 ;
if ( V_6 & V_25 )
V_1 -> V_6 |= V_26 ;
return 1 ;
}
int F_15 ( T_1 * V_1 , unsigned long V_6 )
{
V_1 -> V_6 &= ~ V_6 ;
return 1 ;
}
unsigned long F_16 ( T_1 * V_1 )
{
return V_1 -> V_6 ;
}
int F_17 ( T_1 * V_1 , int V_3 )
{
return F_18 ( & V_1 -> V_3 , V_3 ) ;
}
int F_19 ( T_1 * V_1 , int V_4 )
{
return F_20 ( & V_1 -> V_4 , V_4 ) ;
}
void F_21 ( T_1 * V_1 , int V_7 )
{
V_1 -> V_7 = V_7 ;
}
void F_22 ( T_1 * V_1 , T_2 V_27 )
{
V_1 -> V_19 = V_27 ;
V_1 -> V_6 |= V_18 ;
}
int F_23 ( T_1 * V_1 , T_3 * V_28 )
{
if ( ! V_1 -> V_8 )
{
V_1 -> V_8 = F_24 () ;
if ( ! V_1 -> V_8 )
return 0 ;
}
if ( ! F_25 ( V_1 -> V_8 , V_28 ) )
return 0 ;
return 1 ;
}
int F_26 ( const T_1 * V_1 )
{
return V_1 -> V_7 ;
}
static int F_27 ( const T_1 * V_29 , const T_1 * V_30 )
{
return strcmp ( V_29 -> V_2 , V_30 -> V_2 ) ;
}
static int F_28 ( const T_1 * const * V_29 ,
const T_1 * const * V_30 )
{
return strcmp ( ( * V_29 ) -> V_2 , ( * V_30 ) -> V_2 ) ;
}
int F_29 ( T_1 * V_1 )
{
int V_31 ;
T_1 * V_32 ;
if ( ! V_33 )
{
V_33 = F_30 ( F_28 ) ;
if ( ! V_33 )
return 0 ;
}
else
{
V_31 = F_31 ( V_33 , V_1 ) ;
if ( V_31 != - 1 )
{
V_32 = F_32 ( V_33 , V_31 ) ;
F_5 ( V_32 ) ;
( void ) F_33 ( V_33 , V_31 ) ;
}
}
if ( ! F_34 ( V_33 , V_1 ) )
return 0 ;
return 1 ;
}
const T_1 * F_35 ( const char * V_2 )
{
int V_31 ;
T_1 V_34 ;
V_34 . V_2 = ( char * ) V_2 ;
if ( V_33 )
{
V_31 = F_31 ( V_33 , & V_34 ) ;
if ( V_31 != - 1 )
return F_32 ( V_33 , V_31 ) ;
}
return F_36 ( & V_34 , V_35 ,
sizeof( V_35 ) / sizeof( T_1 ) ) ;
}
void F_37 ( void )
{
if ( V_33 )
F_38 ( V_33 ,
F_5 ) ;
V_33 = NULL ;
}
