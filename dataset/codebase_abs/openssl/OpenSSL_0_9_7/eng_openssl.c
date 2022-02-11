static int F_1 ( T_1 * V_1 )
{
if( ! F_2 ( V_1 , V_2 )
|| ! F_3 ( V_1 , V_3 )
#ifndef F_4
#ifndef F_5
|| ! F_6 ( V_1 , F_7 () )
#endif
#ifndef F_8
|| ! F_9 ( V_1 , F_10 () )
#endif
#ifndef F_11
|| ! F_12 ( V_1 , F_13 () )
#endif
|| ! F_14 ( V_1 , F_15 () )
#ifdef F_16
|| ! F_17 ( V_1 , V_4 )
#endif
#ifdef F_18
|| ! F_19 ( V_1 , V_5 )
#endif
#endif
#ifdef F_20
|| ! F_21 ( V_1 , V_6 )
#endif
)
return 0 ;
return 1 ;
}
static T_1 * F_22 ( void )
{
T_1 * V_7 = F_23 () ;
if( ! V_7 )
return NULL ;
if( ! F_1 ( V_7 ) )
{
F_24 ( V_7 ) ;
return NULL ;
}
return V_7 ;
}
void F_25 ( void )
{
T_1 * V_8 = F_22 () ;
if( ! V_8 ) return;
F_26 ( V_8 ) ;
F_24 ( V_8 ) ;
F_27 () ;
}
static int F_28 ( T_1 * V_1 , const char * V_9 )
{
if( V_9 && ( strcmp ( V_9 , V_2 ) != 0 ) )
return 0 ;
if( ! F_1 ( V_1 ) )
return 0 ;
return 1 ;
}
static int F_29 ( T_2 * V_10 , const unsigned char * V_11 ,
const unsigned char * V_12 , int V_13 )
{
#ifdef F_30
fprintf ( V_14 , L_1 ) ;
#endif
memcpy ( & F_31 ( V_10 ) -> V_11 [ 0 ] , V_11 , F_32 ( V_10 ) ) ;
F_33 ( & F_31 ( V_10 ) -> V_15 , F_32 ( V_10 ) ,
F_31 ( V_10 ) -> V_11 ) ;
return 1 ;
}
static int F_34 ( T_2 * V_10 , unsigned char * V_16 ,
const unsigned char * V_17 , unsigned int V_18 )
{
#ifdef F_35
fprintf ( V_14 , L_2 ) ;
#endif
F_36 ( & F_31 ( V_10 ) -> V_15 , V_18 , V_17 , V_16 ) ;
return 1 ;
}
static int V_4 ( T_1 * V_1 , const T_3 * * V_19 ,
const int * * V_20 , int V_21 )
{
if( ! V_19 )
{
* V_20 = V_22 ;
return V_23 ;
}
if( V_21 == V_24 )
* V_19 = & V_25 ;
else if( V_21 == V_26 )
* V_19 = & V_27 ;
else
{
#ifdef F_37
fprintf ( V_14 , L_3
L_4 , V_21 ) ;
#endif
* V_19 = NULL ;
return 0 ;
}
return 1 ;
}
static int F_38 ( T_4 * V_10 )
{
#ifdef F_39
fprintf ( V_14 , L_5 ) ;
#endif
return F_40 ( V_10 -> V_28 ) ;
}
static int F_41 ( T_4 * V_10 , const void * V_29 , unsigned long V_30 )
{
#ifdef F_42
fprintf ( V_14 , L_6 ) ;
#endif
return F_43 ( V_10 -> V_28 , V_29 , V_30 ) ;
}
static int F_44 ( T_4 * V_10 , unsigned char * V_31 )
{
#ifdef F_45
fprintf ( V_14 , L_7 ) ;
#endif
return F_46 ( V_31 , V_10 -> V_28 ) ;
}
static int V_5 ( T_1 * V_1 , const T_5 * * V_32 ,
const int * * V_20 , int V_21 )
{
if( ! V_32 )
{
* V_20 = V_33 ;
return V_34 ;
}
if( V_21 == V_35 )
* V_32 = & V_36 ;
else
{
#ifdef F_47
fprintf ( V_14 , L_8
L_4 , V_21 ) ;
#endif
* V_32 = NULL ;
return 0 ;
}
return 1 ;
}
static T_6 * V_6 ( T_1 * V_37 , const char * V_38 ,
T_7 * V_39 , void * V_40 )
{
T_8 * V_17 ;
T_6 * V_11 ;
fprintf ( V_14 , L_9 , V_38 ) ;
V_17 = F_48 ( V_38 , L_10 ) ;
if ( ! V_17 )
return NULL ;
V_11 = F_49 ( V_17 , NULL , 0 , NULL ) ;
F_50 ( V_17 ) ;
return V_11 ;
}
