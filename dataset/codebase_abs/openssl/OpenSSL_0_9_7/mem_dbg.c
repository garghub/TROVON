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
return ( ( const char * ) ( ( const V_19 * ) V_17 ) -> V_20
- ( const char * ) ( ( const V_19 * ) V_18 ) -> V_20 ) ;
}
static unsigned long F_13 ( const void * V_17 )
{
unsigned long V_5 ;
V_5 = ( unsigned long ) ( ( const V_19 * ) V_17 ) -> V_20 ;
V_5 = V_5 * 17851 + ( V_5 >> 14 ) * 7 + ( V_5 >> 4 ) * 251 ;
return ( V_5 ) ;
}
static int F_14 ( const void * V_17 , const void * V_18 )
{
return ( ( ( const T_1 * ) V_17 ) -> V_21
!= ( ( const T_1 * ) V_18 ) -> V_21 ) ;
}
static unsigned long F_15 ( const void * V_17 )
{
unsigned long V_5 ;
V_5 = ( unsigned long ) ( ( const T_1 * ) V_17 ) -> V_21 ;
V_5 = V_5 * 17851 + ( V_5 >> 14 ) * 7 + ( V_5 >> 4 ) * 251 ;
return ( V_5 ) ;
}
static T_1 * F_16 ( void )
{
T_1 V_22 ;
T_1 * V_5 = NULL ;
if ( V_23 != NULL )
{
V_22 . V_21 = F_5 () ;
if ( ( V_5 = ( T_1 * ) F_17 ( V_23 , & V_22 ) ) != NULL )
{
T_1 * V_3 = V_5 -> V_3 ;
if ( V_3 != NULL )
{
V_3 -> V_2 ++ ;
F_18 ( V_23 , ( char * ) V_3 ) ;
}
#ifdef F_19
if ( V_5 -> V_21 != V_22 . V_21 )
{
fprintf ( V_24 , L_1 ,
V_5 -> V_21 , V_22 . V_21 ) ;
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
int F_20 ( const char * V_25 , const char * V_26 , int line )
{
T_1 * V_27 , * V_28 ;
int V_5 = 0 ;
if ( F_21 () )
{
F_22 () ;
if ( ( V_27 = ( T_1 * ) F_23 ( sizeof( T_1 ) ) ) == NULL )
{
V_5 = 0 ;
goto V_29;
}
if ( V_23 == NULL )
{
if ( ( V_23 = F_24 ( F_15 , F_14 ) ) == NULL )
{
F_2 ( V_27 ) ;
V_5 = 0 ;
goto V_29;
}
}
V_27 -> V_21 = F_5 () ;
V_27 -> V_26 = V_26 ;
V_27 -> line = line ;
V_27 -> V_25 = V_25 ;
V_27 -> V_2 = 1 ;
V_27 -> V_3 = NULL ;
if ( ( V_28 = ( T_1 * ) F_18 ( V_23 , ( char * ) V_27 ) ) != NULL )
{
#ifdef F_19
if ( V_27 -> V_21 != V_28 -> V_21 )
{
fprintf ( V_24 , L_2 ,
V_28 -> V_21 , V_27 -> V_21 ) ;
abort () ;
}
#endif
V_27 -> V_3 = V_28 ;
}
V_29:
F_25 () ;
}
return ( V_5 ) ;
}
int F_26 ( void )
{
int V_5 = 0 ;
if ( F_21 () )
{
F_22 () ;
V_5 = ( F_16 () != NULL ) ;
F_25 () ;
}
return ( V_5 ) ;
}
int F_27 ( void )
{
int V_5 = 0 ;
if ( F_21 () )
{
F_22 () ;
while( F_16 () != NULL )
V_5 ++ ;
F_25 () ;
}
return ( V_5 ) ;
}
void F_28 ( void * V_20 , int V_30 , const char * V_26 , int line ,
int V_31 )
{
V_19 * V_32 , * V_33 ;
T_1 V_22 , * V_28 ;
switch( V_31 & 127 )
{
case 0 :
break;
case 1 :
if ( V_20 == NULL )
break;
if ( F_21 () )
{
F_22 () ;
if ( ( V_32 = ( V_19 * ) F_23 ( sizeof( V_19 ) ) ) == NULL )
{
F_2 ( V_20 ) ;
F_25 () ;
return;
}
if ( V_34 == NULL )
{
if ( ( V_34 = F_24 ( F_13 , F_12 ) ) == NULL )
{
F_2 ( V_20 ) ;
F_2 ( V_32 ) ;
V_20 = NULL ;
goto V_29;
}
}
V_32 -> V_20 = V_20 ;
V_32 -> V_26 = V_26 ;
V_32 -> line = line ;
V_32 -> V_30 = V_30 ;
if ( V_16 & V_35 )
V_32 -> V_21 = F_5 () ;
else
V_32 -> V_21 = 0 ;
if ( V_36 == V_37 )
{
V_32 -> V_36 = V_36 ;
}
V_32 -> V_36 = V_36 ++ ;
#ifdef F_19
fprintf ( V_24 , L_3 ,
V_32 -> V_36 ,
( V_31 & 128 ) ? '*' : '+' ,
V_32 -> V_20 , V_32 -> V_30 ) ;
#endif
if ( V_16 & V_38 )
V_32 -> time = time ( NULL ) ;
else
V_32 -> time = 0 ;
V_22 . V_21 = F_5 () ;
V_32 -> V_39 = NULL ;
if ( V_23 != NULL
&& ( V_28 = ( T_1 * ) F_29 ( V_23 , ( char * ) & V_22 ) ) != NULL )
{
V_32 -> V_39 = V_28 ;
V_28 -> V_2 ++ ;
}
if ( ( V_33 = ( V_19 * ) F_18 ( V_34 , ( char * ) V_32 ) ) != NULL )
{
if ( V_33 -> V_39 != NULL )
{
V_33 -> V_39 -> V_2 -- ;
}
F_2 ( V_33 ) ;
}
V_29:
F_25 () ;
}
break;
}
return;
}
void F_30 ( void * V_20 , int V_31 )
{
V_19 V_32 , * V_40 ;
switch( V_31 )
{
case 0 :
if ( V_20 == NULL )
break;
if ( F_21 () && ( V_34 != NULL ) )
{
F_22 () ;
V_32 . V_20 = V_20 ;
V_40 = ( V_19 * ) F_17 ( V_34 , ( char * ) & V_32 ) ;
if ( V_40 != NULL )
{
#ifdef F_19
fprintf ( V_24 , L_4 ,
V_40 -> V_36 , V_40 -> V_20 , V_40 -> V_30 ) ;
#endif
if ( V_40 -> V_39 != NULL )
F_1 ( V_40 -> V_39 ) ;
F_2 ( V_40 ) ;
}
F_25 () ;
}
break;
case 1 :
break;
}
}
void F_31 ( void * V_41 , void * V_42 , int V_30 ,
const char * V_26 , int line , int V_31 )
{
V_19 V_32 , * V_40 ;
#ifdef F_19
fprintf ( V_24 , L_5 ,
V_41 , V_42 , V_30 , V_26 , line , V_31 ) ;
#endif
switch( V_31 )
{
case 0 :
break;
case 1 :
if ( V_42 == NULL )
break;
if ( V_41 == NULL )
{
F_28 ( V_42 , V_30 , V_26 , line , 128 | V_31 ) ;
break;
}
if ( F_21 () )
{
F_22 () ;
V_32 . V_20 = V_41 ;
V_40 = ( V_19 * ) F_17 ( V_34 , ( char * ) & V_32 ) ;
if ( V_40 != NULL )
{
#ifdef F_19
fprintf ( V_24 , L_6 ,
V_40 -> V_36 ,
V_40 -> V_20 , V_40 -> V_30 ,
V_42 , V_30 ) ;
#endif
V_40 -> V_20 = V_42 ;
V_40 -> V_30 = V_30 ;
F_18 ( V_34 , ( char * ) V_40 ) ;
}
F_25 () ;
}
break;
}
return;
}
static void F_32 ( const V_19 * V_32 , T_2 * V_43 )
{
char V_44 [ 1024 ] ;
char * V_45 = V_44 ;
T_1 * V_46 ;
int V_47 ;
struct V_48 * V_49 = NULL ;
unsigned long V_50 ;
if( V_32 -> V_20 == ( char * ) V_43 -> V_51 )
return;
if ( V_16 & V_38 )
{
V_49 = localtime ( & V_32 -> time ) ;
sprintf ( V_45 , L_7 ,
V_49 -> V_52 , V_49 -> V_53 , V_49 -> V_54 ) ;
V_45 += strlen ( V_45 ) ;
}
sprintf ( V_45 , L_8 ,
V_32 -> V_36 , V_32 -> V_26 , V_32 -> line ) ;
V_45 += strlen ( V_45 ) ;
if ( V_16 & V_35 )
{
sprintf ( V_45 , L_9 , V_32 -> V_21 ) ;
V_45 += strlen ( V_45 ) ;
}
sprintf ( V_45 , L_10 ,
V_32 -> V_30 , ( unsigned long ) V_32 -> V_20 ) ;
V_45 += strlen ( V_45 ) ;
F_33 ( V_43 -> V_51 , V_44 ) ;
V_43 -> V_55 ++ ;
V_43 -> V_56 += V_32 -> V_30 ;
V_46 = V_32 -> V_39 ;
V_47 = 0 ;
if ( ! V_46 )
return;
V_50 = V_46 -> V_21 ;
do
{
int V_57 ;
int V_58 ;
V_47 ++ ;
memset ( V_44 , '>' , V_47 ) ;
sprintf ( V_44 + V_47 ,
L_11 ,
V_46 -> V_21 , V_46 -> V_26 , V_46 -> line ) ;
V_57 = strlen ( V_44 ) ;
V_58 = strlen ( V_46 -> V_25 ) ;
if ( 128 - V_57 - 3 < V_58 )
{
memcpy ( V_44 + V_57 , V_46 -> V_25 , 128 - V_57 - 3 ) ;
V_57 = 128 - 3 ;
}
else
{
strcpy ( V_44 + V_57 , V_46 -> V_25 ) ;
V_57 = strlen ( V_44 ) ;
}
sprintf ( V_44 + V_57 , L_12 ) ;
F_33 ( V_43 -> V_51 , V_44 ) ;
V_46 = V_46 -> V_3 ;
}
while( V_46 && V_46 -> V_21 == V_50 );
#ifdef F_19
if ( V_46 )
{
fprintf ( V_24 , L_13 ) ;
abort () ;
}
#endif
}
static void F_34 ( const V_19 * V_32 , T_3 * * V_59 )
{
(* * V_59)( V_32 -> V_36 , V_32 -> V_26 , V_32 -> line , V_32 -> V_30 , V_32 -> V_20 ) ;
}
