static void F_1 ( T_1 * V_1 )
{
if ( -- ( V_1 -> V_2 ) <= 0 )
{
if ( V_1 -> V_3 != NULL )
{
F_1 ( V_1 -> V_3 ) ;
}
F_2 ( V_1 ) ;
}
}
int F_3 ( int V_4 )
{
int V_5 = V_6 ;
F_4 ( V_7 ) ;
switch ( V_4 )
{
case V_8 :
V_6 = V_8 | V_9 ;
V_10 = 0 ;
break;
case V_11 :
V_6 = 0 ;
V_10 = 0 ;
break;
case V_12 :
if ( V_6 & V_8 )
{
if ( ! V_10 || ( V_13 != F_5 () ) )
{
F_6 ( V_7 ) ;
F_4 ( V_14 ) ;
F_4 ( V_7 ) ;
V_6 &= ~ V_9 ;
V_13 = F_5 () ;
}
V_10 ++ ;
}
break;
case V_9 :
if ( V_6 & V_8 )
{
if ( V_10 )
{
V_10 -- ;
if ( V_10 == 0 )
{
V_6 |= V_9 ;
F_6 ( V_14 ) ;
}
}
}
break;
default:
break;
}
F_6 ( V_7 ) ;
return ( V_5 ) ;
}
int F_7 ( void )
{
int V_5 = 0 ;
if ( V_6 & V_8 )
{
F_8 ( V_7 ) ;
V_5 = ( V_6 & V_9 )
|| ( V_13 != F_5 () ) ;
F_9 ( V_7 ) ;
}
return ( V_5 ) ;
}
void F_10 ( long V_15 )
{
V_16 = V_15 ;
}
long F_11 ( void )
{
return V_16 ;
}
static int F_12 ( const void * V_17 , const void * V_18 )
{
#ifdef F_13
const char * V_19 = ( const char * ) ( ( const V_20 * ) V_17 ) -> V_21 ,
* V_22 = ( const char * ) ( ( const V_20 * ) V_18 ) -> V_21 ;
if ( V_19 == V_22 ) return 0 ;
else if ( V_19 > V_22 ) return 1 ;
else return - 1 ;
#else
return ( ( const char * ) ( ( const V_20 * ) V_17 ) -> V_21
- ( const char * ) ( ( const V_20 * ) V_18 ) -> V_21 ) ;
#endif
}
static unsigned long F_14 ( const void * V_17 )
{
unsigned long V_5 ;
V_5 = ( unsigned long ) ( ( const V_20 * ) V_17 ) -> V_21 ;
V_5 = V_5 * 17851 + ( V_5 >> 14 ) * 7 + ( V_5 >> 4 ) * 251 ;
return ( V_5 ) ;
}
static int F_15 ( const void * V_17 , const void * V_18 )
{
return ( ( ( const T_1 * ) V_17 ) -> V_23
!= ( ( const T_1 * ) V_18 ) -> V_23 ) ;
}
static unsigned long F_16 ( const void * V_17 )
{
unsigned long V_5 ;
V_5 = ( unsigned long ) ( ( const T_1 * ) V_17 ) -> V_23 ;
V_5 = V_5 * 17851 + ( V_5 >> 14 ) * 7 + ( V_5 >> 4 ) * 251 ;
return ( V_5 ) ;
}
static T_1 * F_17 ( void )
{
T_1 V_24 ;
T_1 * V_5 = NULL ;
if ( V_25 != NULL )
{
V_24 . V_23 = F_5 () ;
if ( ( V_5 = ( T_1 * ) F_18 ( V_25 , & V_24 ) ) != NULL )
{
T_1 * V_3 = V_5 -> V_3 ;
if ( V_3 != NULL )
{
V_3 -> V_2 ++ ;
F_19 ( V_25 , ( char * ) V_3 ) ;
}
#ifdef F_20
if ( V_5 -> V_23 != V_24 . V_23 )
{
fprintf ( V_26 , L_1 ,
V_5 -> V_23 , V_24 . V_23 ) ;
abort () ;
}
#endif
if ( -- ( V_5 -> V_2 ) <= 0 )
{
V_5 -> V_3 = NULL ;
if ( V_3 != NULL )
V_3 -> V_2 -- ;
F_2 ( V_5 ) ;
}
}
}
return ( V_5 ) ;
}
int F_21 ( const char * V_27 , const char * V_28 , int line )
{
T_1 * V_29 , * V_30 ;
int V_5 = 0 ;
if ( F_22 () )
{
F_23 () ;
if ( ( V_29 = ( T_1 * ) F_24 ( sizeof( T_1 ) ) ) == NULL )
{
V_5 = 0 ;
goto V_31;
}
if ( V_25 == NULL )
{
if ( ( V_25 = F_25 ( F_16 , F_15 ) ) == NULL )
{
F_2 ( V_29 ) ;
V_5 = 0 ;
goto V_31;
}
}
V_29 -> V_23 = F_5 () ;
V_29 -> V_28 = V_28 ;
V_29 -> line = line ;
V_29 -> V_27 = V_27 ;
V_29 -> V_2 = 1 ;
V_29 -> V_3 = NULL ;
if ( ( V_30 = ( T_1 * ) F_19 ( V_25 , ( char * ) V_29 ) ) != NULL )
{
#ifdef F_20
if ( V_29 -> V_23 != V_30 -> V_23 )
{
fprintf ( V_26 , L_2 ,
V_30 -> V_23 , V_29 -> V_23 ) ;
abort () ;
}
#endif
V_29 -> V_3 = V_30 ;
}
V_31:
F_26 () ;
}
return ( V_5 ) ;
}
int F_27 ( void )
{
int V_5 = 0 ;
if ( F_22 () )
{
F_23 () ;
V_5 = ( F_17 () != NULL ) ;
F_26 () ;
}
return ( V_5 ) ;
}
int F_28 ( void )
{
int V_5 = 0 ;
if ( F_22 () )
{
F_23 () ;
while( F_17 () != NULL )
V_5 ++ ;
F_26 () ;
}
return ( V_5 ) ;
}
void F_29 ( void * V_21 , int V_32 , const char * V_28 , int line ,
int V_33 )
{
V_20 * V_34 , * V_35 ;
T_1 V_24 , * V_30 ;
switch( V_33 & 127 )
{
case 0 :
break;
case 1 :
if ( V_21 == NULL )
break;
if ( F_22 () )
{
F_23 () ;
if ( ( V_34 = ( V_20 * ) F_24 ( sizeof( V_20 ) ) ) == NULL )
{
F_2 ( V_21 ) ;
F_26 () ;
return;
}
if ( V_36 == NULL )
{
if ( ( V_36 = F_25 ( F_14 , F_12 ) ) == NULL )
{
F_2 ( V_21 ) ;
F_2 ( V_34 ) ;
V_21 = NULL ;
goto V_31;
}
}
V_34 -> V_21 = V_21 ;
V_34 -> V_28 = V_28 ;
V_34 -> line = line ;
V_34 -> V_32 = V_32 ;
if ( V_16 & V_37 )
V_34 -> V_23 = F_5 () ;
else
V_34 -> V_23 = 0 ;
if ( V_38 == V_39 )
{
V_34 -> V_38 = V_38 ;
}
V_34 -> V_38 = V_38 ++ ;
#ifdef F_20
fprintf ( V_26 , L_3 ,
V_34 -> V_38 ,
( V_33 & 128 ) ? '*' : '+' ,
V_34 -> V_21 , V_34 -> V_32 ) ;
#endif
if ( V_16 & V_40 )
V_34 -> time = time ( NULL ) ;
else
V_34 -> time = 0 ;
V_24 . V_23 = F_5 () ;
V_34 -> V_41 = NULL ;
if ( V_25 != NULL
&& ( V_30 = ( T_1 * ) F_30 ( V_25 , ( char * ) & V_24 ) ) != NULL )
{
V_34 -> V_41 = V_30 ;
V_30 -> V_2 ++ ;
}
if ( ( V_35 = ( V_20 * ) F_19 ( V_36 , ( char * ) V_34 ) ) != NULL )
{
if ( V_35 -> V_41 != NULL )
{
V_35 -> V_41 -> V_2 -- ;
}
F_2 ( V_35 ) ;
}
V_31:
F_26 () ;
}
break;
}
return;
}
void F_31 ( void * V_21 , int V_33 )
{
V_20 V_34 , * V_42 ;
switch( V_33 )
{
case 0 :
if ( V_21 == NULL )
break;
if ( F_22 () && ( V_36 != NULL ) )
{
F_23 () ;
V_34 . V_21 = V_21 ;
V_42 = ( V_20 * ) F_18 ( V_36 , ( char * ) & V_34 ) ;
if ( V_42 != NULL )
{
#ifdef F_20
fprintf ( V_26 , L_4 ,
V_42 -> V_38 , V_42 -> V_21 , V_42 -> V_32 ) ;
#endif
if ( V_42 -> V_41 != NULL )
F_1 ( V_42 -> V_41 ) ;
F_2 ( V_42 ) ;
}
F_26 () ;
}
break;
case 1 :
break;
}
}
void F_32 ( void * V_43 , void * V_44 , int V_32 ,
const char * V_28 , int line , int V_33 )
{
V_20 V_34 , * V_42 ;
#ifdef F_20
fprintf ( V_26 , L_5 ,
V_43 , V_44 , V_32 , V_28 , line , V_33 ) ;
#endif
switch( V_33 )
{
case 0 :
break;
case 1 :
if ( V_44 == NULL )
break;
if ( V_43 == NULL )
{
F_29 ( V_44 , V_32 , V_28 , line , 128 | V_33 ) ;
break;
}
if ( F_22 () )
{
F_23 () ;
V_34 . V_21 = V_43 ;
V_42 = ( V_20 * ) F_18 ( V_36 , ( char * ) & V_34 ) ;
if ( V_42 != NULL )
{
#ifdef F_20
fprintf ( V_26 , L_6 ,
V_42 -> V_38 ,
V_42 -> V_21 , V_42 -> V_32 ,
V_44 , V_32 ) ;
#endif
V_42 -> V_21 = V_44 ;
V_42 -> V_32 = V_32 ;
F_19 ( V_36 , ( char * ) V_42 ) ;
}
F_26 () ;
}
break;
}
return;
}
static void F_33 ( const V_20 * V_34 , T_2 * V_45 )
{
char V_46 [ 1024 ] ;
char * V_47 = V_46 ;
T_1 * V_48 ;
int V_49 ;
struct V_50 * V_51 = NULL ;
unsigned long V_52 ;
#define F_34 (sizeof buf - (size_t)(bufp - buf))
if( V_34 -> V_21 == ( char * ) V_45 -> V_53 )
return;
if ( V_16 & V_40 )
{
V_51 = localtime ( & V_34 -> time ) ;
F_35 ( V_47 , F_34 , L_7 ,
V_51 -> V_54 , V_51 -> V_55 , V_51 -> V_56 ) ;
V_47 += strlen ( V_47 ) ;
}
F_35 ( V_47 , F_34 , L_8 ,
V_34 -> V_38 , V_34 -> V_28 , V_34 -> line ) ;
V_47 += strlen ( V_47 ) ;
if ( V_16 & V_37 )
{
F_35 ( V_47 , F_34 , L_9 , V_34 -> V_23 ) ;
V_47 += strlen ( V_47 ) ;
}
F_35 ( V_47 , F_34 , L_10 ,
V_34 -> V_32 , ( unsigned long ) V_34 -> V_21 ) ;
V_47 += strlen ( V_47 ) ;
F_36 ( V_45 -> V_53 , V_46 ) ;
V_45 -> V_57 ++ ;
V_45 -> V_58 += V_34 -> V_32 ;
V_48 = V_34 -> V_41 ;
V_49 = 0 ;
if ( ! V_48 )
return;
V_52 = V_48 -> V_23 ;
do
{
int V_59 ;
int V_60 ;
V_49 ++ ;
memset ( V_46 , '>' , V_49 ) ;
F_35 ( V_46 + V_49 , sizeof V_46 - V_49 ,
L_11 ,
V_48 -> V_23 , V_48 -> V_28 , V_48 -> line ) ;
V_59 = strlen ( V_46 ) ;
V_60 = strlen ( V_48 -> V_27 ) ;
if ( 128 - V_59 - 3 < V_60 )
{
memcpy ( V_46 + V_59 , V_48 -> V_27 , 128 - V_59 - 3 ) ;
V_59 = 128 - 3 ;
}
else
{
F_37 ( V_46 + V_59 , V_48 -> V_27 ,
sizeof V_46 - V_59 ) ;
V_59 = strlen ( V_46 ) ;
}
F_35 ( V_46 + V_59 , sizeof V_46 - V_59 , L_12 ) ;
F_36 ( V_45 -> V_53 , V_46 ) ;
V_48 = V_48 -> V_3 ;
}
while( V_48 && V_48 -> V_23 == V_52 );
#ifdef F_20
if ( V_48 )
{
fprintf ( V_26 , L_13 ) ;
abort () ;
}
#endif
}
static void F_38 ( const V_20 * V_34 , T_3 * * V_61 )
{
(* * V_61)( V_34 -> V_38 , V_34 -> V_28 , V_34 -> line , V_34 -> V_32 , V_34 -> V_21 ) ;
}
