T_1 * F_1 ( void )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if( V_1 == NULL )
{
F_3 ( V_2 , V_3 ) ;
return NULL ;
}
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
V_1 -> V_4 = 1 ;
F_4 (ret, 0 , 1 )
F_5 ( V_5 , V_1 , & V_1 -> V_6 ) ;
return V_1 ;
}
void F_6 ( T_1 * V_7 )
{
V_7 -> V_8 = NULL ;
V_7 -> V_9 = NULL ;
V_7 -> V_10 = NULL ;
V_7 -> V_11 = NULL ;
V_7 -> V_12 = NULL ;
V_7 -> V_13 = NULL ;
V_7 -> V_14 = NULL ;
V_7 -> V_15 = NULL ;
V_7 -> V_16 = NULL ;
V_7 -> V_17 = NULL ;
V_7 -> V_18 = NULL ;
V_7 -> V_19 = NULL ;
V_7 -> V_20 = NULL ;
V_7 -> V_21 = NULL ;
V_7 -> V_22 = NULL ;
V_7 -> V_23 = NULL ;
V_7 -> V_24 = 0 ;
}
int F_7 ( T_1 * V_7 , int V_25 )
{
int V_26 ;
if( V_7 == NULL )
{
F_3 ( V_27 ,
V_28 ) ;
return 0 ;
}
if( V_25 )
V_26 = F_8 ( & V_7 -> V_4 , - 1 , V_29 ) ;
else
V_26 = -- V_7 -> V_4 ;
F_4 (e, 0 , -1 )
if ( V_26 > 0 ) return 1 ;
#ifdef F_9
if ( V_26 < 0 )
{
fprintf ( V_30 , L_1 ) ;
abort () ;
}
#endif
if( V_7 -> V_17 )
V_7 -> V_17 ( V_7 ) ;
F_10 ( V_5 , V_7 , & V_7 -> V_6 ) ;
F_11 ( V_7 ) ;
return 1 ;
}
int F_12 ( T_1 * V_7 )
{
return F_7 ( V_7 , 1 ) ;
}
static int F_13 ( int V_31 )
{
if( V_32 ) return 1 ;
if( ! V_31 ) return 0 ;
V_32 = F_14 () ;
return ( V_32 ? 1 : 0 ) ;
}
static T_2 * F_15 ( T_3 * V_33 )
{
T_2 * V_34 = F_2 ( sizeof(
T_2 ) ) ;
if( ! V_34 ) return NULL ;
V_34 -> V_33 = V_33 ;
return V_34 ;
}
void F_16 ( T_3 * V_33 )
{
T_2 * V_34 ;
if( ! F_13 ( 1 ) ) return;
V_34 = F_15 ( V_33 ) ;
if( V_34 )
F_17 ( V_32 , V_34 , 0 ) ;
}
void F_18 ( T_3 * V_33 )
{
T_2 * V_34 ;
if( ! F_13 ( 1 ) ) return;
V_34 = F_15 ( V_33 ) ;
if( V_34 )
F_19 ( V_32 , V_34 ) ;
}
static void F_20 ( T_2 * V_34 )
{
( * ( V_34 -> V_33 ) ) ( ) ;
F_11 ( V_34 ) ;
}
void F_21 ( void )
{
if( F_13 ( 0 ) )
{
F_22 ( V_32 ,
F_20 ) ;
V_32 = NULL ;
}
F_23 ( NULL ) ;
}
int F_24 ( long V_35 , void * V_36 , T_4 * V_37 ,
T_5 * V_38 , T_6 * V_39 )
{
return F_25 ( V_5 , V_35 , V_36 ,
V_37 , V_38 , V_39 ) ;
}
int F_26 ( T_1 * V_7 , int V_40 , void * V_41 )
{
return ( F_27 ( & V_7 -> V_6 , V_40 , V_41 ) ) ;
}
void * F_28 ( const T_1 * V_7 , int V_40 )
{
return ( F_29 ( & V_7 -> V_6 , V_40 ) ) ;
}
int F_30 ( T_1 * V_7 , const char * V_8 )
{
if( V_8 == NULL )
{
F_3 ( V_42 ,
V_28 ) ;
return 0 ;
}
V_7 -> V_8 = V_8 ;
return 1 ;
}
int F_31 ( T_1 * V_7 , const char * V_9 )
{
if( V_9 == NULL )
{
F_3 ( V_43 ,
V_28 ) ;
return 0 ;
}
V_7 -> V_9 = V_9 ;
return 1 ;
}
int F_32 ( T_1 * V_7 , T_7 V_44 )
{
V_7 -> V_17 = V_44 ;
return 1 ;
}
int F_33 ( T_1 * V_7 , T_7 V_45 )
{
V_7 -> V_18 = V_45 ;
return 1 ;
}
int F_34 ( T_1 * V_7 , T_7 V_46 )
{
V_7 -> V_19 = V_46 ;
return 1 ;
}
int F_35 ( T_1 * V_7 , T_8 V_47 )
{
V_7 -> V_20 = V_47 ;
return 1 ;
}
int F_36 ( T_1 * V_7 , int V_24 )
{
V_7 -> V_24 = V_24 ;
return 1 ;
}
int F_37 ( T_1 * V_7 , const T_9 * V_48 )
{
V_7 -> V_23 = V_48 ;
return 1 ;
}
const char * F_38 ( const T_1 * V_7 )
{
return V_7 -> V_8 ;
}
const char * F_39 ( const T_1 * V_7 )
{
return V_7 -> V_9 ;
}
T_7 F_40 ( const T_1 * V_7 )
{
return V_7 -> V_17 ;
}
T_7 F_41 ( const T_1 * V_7 )
{
return V_7 -> V_18 ;
}
T_7 F_42 ( const T_1 * V_7 )
{
return V_7 -> V_19 ;
}
T_8 F_43 ( const T_1 * V_7 )
{
return V_7 -> V_20 ;
}
int F_44 ( const T_1 * V_7 )
{
return V_7 -> V_24 ;
}
const T_9 * F_45 ( const T_1 * V_7 )
{
return V_7 -> V_23 ;
}
void * F_46 ( void )
{
return & V_49 ;
}
