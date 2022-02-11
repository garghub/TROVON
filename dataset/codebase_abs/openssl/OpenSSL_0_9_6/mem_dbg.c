int F_1 ( int V_1 )
{
int V_2 = V_3 ;
F_2 ( V_4 ) ;
switch ( V_1 )
{
case V_5 :
V_3 = V_5 | V_6 ;
V_7 = 0 ;
break;
case V_8 :
V_3 = 0 ;
V_7 = 0 ;
break;
case V_9 :
if ( V_3 & V_5 )
{
V_3 &= ~ V_6 ;
if ( V_7 != F_3 () )
{
F_4 ( V_4 ) ;
F_2 ( V_10 ) ;
F_2 ( V_4 ) ;
V_7 = F_3 () ;
}
}
break;
case V_6 :
if ( V_3 & V_5 )
{
V_3 |= V_6 ;
if ( V_7 != 0 )
{
V_7 = 0 ;
F_4 ( V_10 ) ;
}
}
break;
default:
break;
}
F_4 ( V_4 ) ;
return ( V_2 ) ;
}
int F_5 ( void )
{
int V_2 = 0 ;
if ( V_3 & V_5 )
{
F_2 ( V_4 ) ;
V_2 = ( V_3 & V_6 )
&& V_7 != F_3 () ;
F_4 ( V_4 ) ;
}
return ( V_2 ) ;
}
void F_6 ( long V_11 )
{
V_12 = V_11 ;
}
long F_7 ( void )
{
return V_12 ;
}
static int F_8 ( T_1 * V_13 , T_1 * V_14 )
{
return ( ( char * ) V_13 -> V_15 - ( char * ) V_14 -> V_15 ) ;
}
static unsigned long F_9 ( T_1 * V_13 )
{
unsigned long V_2 ;
V_2 = ( unsigned long ) V_13 -> V_15 ;
V_2 = V_2 * 17851 + ( V_2 >> 14 ) * 7 + ( V_2 >> 4 ) * 251 ;
return ( V_2 ) ;
}
static int F_10 ( T_2 * V_13 , T_2 * V_14 )
{
return ( V_13 -> V_16 != V_14 -> V_16 ) ;
}
static unsigned long F_11 ( T_2 * V_13 )
{
unsigned long V_2 ;
V_2 = ( unsigned long ) V_13 -> V_16 ;
V_2 = V_2 * 17851 + ( V_2 >> 14 ) * 7 + ( V_2 >> 4 ) * 251 ;
return ( V_2 ) ;
}
static T_2 * F_12 ()
{
T_2 V_17 ;
T_2 * V_2 = NULL ;
if ( V_18 != NULL )
{
V_17 . V_16 = F_3 () ;
if ( ( V_2 = ( T_2 * ) F_13 ( V_18 , & V_17 ) ) != NULL )
{
T_2 * V_19 = V_2 -> V_19 ;
if ( V_19 != NULL )
{
V_19 -> V_20 ++ ;
F_14 ( V_18 , ( char * ) V_19 ) ;
}
#ifdef F_15
if ( V_2 -> V_16 != V_17 . V_16 )
{
fprintf ( V_21 , L_1 ,
V_2 -> V_16 , V_17 . V_16 ) ;
abort () ;
}
#endif
if ( -- ( V_2 -> V_20 ) <= 0 )
{
V_2 -> V_19 = NULL ;
if ( V_19 != NULL )
V_19 -> V_20 -- ;
F_16 ( V_2 ) ;
}
}
}
return ( V_2 ) ;
}
int F_17 ( const char * V_22 , const char * V_23 , int line )
{
T_2 * V_24 , * V_25 ;
int V_2 = 0 ;
if ( F_18 () )
{
F_19 () ;
if ( ( V_24 = ( T_2 * ) F_20 ( sizeof( T_2 ) ) ) == NULL )
{
V_2 = 0 ;
goto V_26;
}
if ( V_18 == NULL )
{
if ( ( V_18 = F_21 ( F_11 , F_10 ) ) == NULL )
{
F_16 ( V_24 ) ;
V_2 = 0 ;
goto V_26;
}
}
V_24 -> V_16 = F_3 () ;
V_24 -> V_23 = V_23 ;
V_24 -> line = line ;
V_24 -> V_22 = V_22 ;
V_24 -> V_20 = 1 ;
V_24 -> V_19 = NULL ;
if ( ( V_25 = ( T_2 * ) F_14 ( V_18 , ( char * ) V_24 ) ) != NULL )
{
#ifdef F_15
if ( V_24 -> V_16 != V_25 -> V_16 )
{
fprintf ( V_21 , L_2 ,
V_25 -> V_16 , V_24 -> V_16 ) ;
abort () ;
}
#endif
V_24 -> V_19 = V_25 ;
}
V_26:
F_22 () ;
}
return ( V_2 ) ;
}
int F_23 ( void )
{
int V_2 = 0 ;
if ( F_18 () )
{
F_19 () ;
V_2 = ( F_12 () != NULL ) ;
F_22 () ;
}
return ( V_2 ) ;
}
int F_24 ( void )
{
int V_2 = 0 ;
if ( F_18 () )
{
F_19 () ;
while( F_12 () != NULL )
V_2 ++ ;
F_22 () ;
}
return ( V_2 ) ;
}
void F_25 ( void * V_15 , int V_27 , const char * V_23 , int line ,
int V_28 )
{
T_1 * V_29 , * V_30 ;
T_2 V_17 , * V_25 ;
switch( V_28 & 127 )
{
case 0 :
break;
case 1 :
if ( V_15 == NULL )
break;
if ( F_18 () )
{
F_19 () ;
if ( ( V_29 = ( T_1 * ) F_20 ( sizeof( T_1 ) ) ) == NULL )
{
F_16 ( V_15 ) ;
F_22 () ;
return;
}
if ( V_31 == NULL )
{
if ( ( V_31 = F_21 ( F_9 , F_8 ) ) == NULL )
{
F_16 ( V_15 ) ;
F_16 ( V_29 ) ;
V_15 = NULL ;
goto V_26;
}
}
V_29 -> V_15 = V_15 ;
V_29 -> V_23 = V_23 ;
V_29 -> line = line ;
V_29 -> V_27 = V_27 ;
if ( V_12 & V_32 )
V_29 -> V_16 = F_3 () ;
else
V_29 -> V_16 = 0 ;
if ( V_33 == V_34 )
{
V_29 -> V_33 = V_33 ;
}
V_29 -> V_33 = V_33 ++ ;
#ifdef F_15
fprintf ( V_21 , L_3 ,
V_29 -> V_33 ,
( V_28 & 128 ) ? '*' : '+' ,
V_29 -> V_15 , V_29 -> V_27 ) ;
#endif
if ( V_12 & V_35 )
V_29 -> time = time ( NULL ) ;
else
V_29 -> time = 0 ;
V_17 . V_16 = F_3 () ;
V_29 -> V_36 = NULL ;
if ( V_18 != NULL
&& ( V_25 = ( T_2 * ) F_26 ( V_18 , ( char * ) & V_17 ) ) != NULL )
{
V_29 -> V_36 = V_25 ;
V_25 -> V_20 ++ ;
}
if ( ( V_30 = ( T_1 * ) F_14 ( V_31 , ( char * ) V_29 ) ) != NULL )
{
if ( V_30 -> V_36 != NULL )
{
V_30 -> V_36 -> V_20 -- ;
}
F_16 ( V_30 ) ;
}
V_26:
F_22 () ;
}
break;
}
return;
}
void F_27 ( void * V_15 , int V_28 )
{
T_1 V_29 , * V_37 ;
switch( V_28 )
{
case 0 :
if ( V_15 == NULL )
break;
if ( F_18 () && ( V_31 != NULL ) )
{
F_19 () ;
V_29 . V_15 = V_15 ;
V_37 = ( T_1 * ) F_13 ( V_31 , ( char * ) & V_29 ) ;
if ( V_37 != NULL )
{
#ifdef F_15
fprintf ( V_21 , L_4 ,
V_37 -> V_33 , V_37 -> V_15 , V_37 -> V_27 ) ;
#endif
if ( V_37 -> V_36 != NULL )
{
V_37 -> V_36 -> V_20 -- ;
}
F_16 ( V_37 ) ;
}
F_22 () ;
}
break;
case 1 :
break;
}
}
void F_28 ( void * V_38 , void * V_39 , int V_27 ,
const char * V_23 , int line , int V_28 )
{
T_1 V_29 , * V_37 ;
#ifdef F_15
fprintf ( V_21 , L_5 ,
V_38 , V_39 , V_27 , V_23 , line , V_28 ) ;
#endif
switch( V_28 )
{
case 0 :
break;
case 1 :
if ( V_39 == NULL )
break;
if ( V_38 == NULL )
{
F_25 ( V_39 , V_27 , V_23 , line , 128 | V_28 ) ;
break;
}
if ( F_18 () )
{
F_19 () ;
V_29 . V_15 = V_38 ;
V_37 = ( T_1 * ) F_13 ( V_31 , ( char * ) & V_29 ) ;
if ( V_37 != NULL )
{
#ifdef F_15
fprintf ( V_21 , L_6 ,
V_37 -> V_33 ,
V_37 -> V_15 , V_37 -> V_27 ,
V_39 , V_27 ) ;
#endif
V_37 -> V_15 = V_39 ;
V_37 -> V_27 = V_27 ;
F_14 ( V_31 , ( char * ) V_37 ) ;
}
F_22 () ;
}
break;
}
return;
}
static void F_29 ( T_1 * V_29 , T_3 * V_40 )
{
char V_41 [ 1024 ] ;
char * V_42 = V_41 ;
T_2 * V_43 ;
int V_44 ;
struct V_45 * V_46 = NULL ;
unsigned long V_47 ;
if( V_29 -> V_15 == ( char * ) V_40 -> V_48 )
return;
if ( V_12 & V_35 )
{
V_46 = localtime ( & V_29 -> time ) ;
sprintf ( V_42 , L_7 ,
V_46 -> V_49 , V_46 -> V_50 , V_46 -> V_51 ) ;
V_42 += strlen ( V_42 ) ;
}
sprintf ( V_42 , L_8 ,
V_29 -> V_33 , V_29 -> V_23 , V_29 -> line ) ;
V_42 += strlen ( V_42 ) ;
if ( V_12 & V_32 )
{
sprintf ( V_42 , L_9 , V_29 -> V_16 ) ;
V_42 += strlen ( V_42 ) ;
}
sprintf ( V_42 , L_10 ,
V_29 -> V_27 , ( unsigned long ) V_29 -> V_15 ) ;
V_42 += strlen ( V_42 ) ;
F_30 ( V_40 -> V_48 , V_41 ) ;
V_40 -> V_52 ++ ;
V_40 -> V_53 += V_29 -> V_27 ;
V_43 = V_29 -> V_36 ;
V_44 = 0 ;
if ( ! V_43 )
return;
V_47 = V_43 -> V_16 ;
do
{
int V_54 ;
int V_55 ;
V_44 ++ ;
memset ( V_41 , '>' , V_44 ) ;
sprintf ( V_41 + V_44 ,
L_11 ,
V_43 -> V_16 , V_43 -> V_23 , V_43 -> line ) ;
V_54 = strlen ( V_41 ) ;
V_55 = strlen ( V_43 -> V_22 ) ;
if ( 128 - V_54 - 3 < V_55 )
{
memcpy ( V_41 + V_54 , V_43 -> V_22 , 128 - V_54 - 3 ) ;
V_54 = 128 - 3 ;
}
else
{
strcpy ( V_41 + V_54 , V_43 -> V_22 ) ;
V_54 = strlen ( V_41 ) ;
}
sprintf ( V_41 + V_54 , L_12 ) ;
F_30 ( V_40 -> V_48 , V_41 ) ;
V_43 = V_43 -> V_19 ;
}
while( V_43 && V_43 -> V_16 == V_47 );
#ifdef F_15
if ( V_43 )
{
fprintf ( V_21 , L_13 ) ;
abort () ;
}
#endif
}
void F_31 ( T_4 * V_14 )
{
T_3 V_56 ;
char V_41 [ 80 ] ;
if ( V_31 == NULL && V_18 == NULL )
return;
V_56 . V_48 = V_14 ;
V_56 . V_53 = 0 ;
V_56 . V_52 = 0 ;
F_19 () ;
if ( V_31 != NULL )
F_32 ( V_31 , ( void ( * ) () ) F_29 , ( char * ) & V_56 ) ;
if ( V_56 . V_52 != 0 )
{
sprintf ( V_41 , L_14 ,
V_56 . V_53 , V_56 . V_52 ) ;
F_30 ( V_14 , V_41 ) ;
}
else
{
F_2 ( V_4 ) ;
if ( V_31 != NULL )
{
F_33 ( V_31 ) ;
V_31 = NULL ;
}
if ( V_18 != NULL )
{
if ( F_34 ( V_18 ) == 0 )
{
F_33 ( V_18 ) ;
V_18 = NULL ;
}
}
F_4 ( V_4 ) ;
}
F_22 () ;
#if 0
lh_stats_bio(mh,b);
lh_node_stats_bio(mh,b);
lh_node_usage_stats_bio(mh,b);
#endif
}
void F_35 ( T_5 * V_57 )
{
T_4 * V_14 ;
if ( V_31 == NULL ) return;
if ( ( V_14 = F_36 ( F_37 () ) ) == NULL )
return;
F_38 ( V_14 , V_57 , V_58 ) ;
F_31 ( V_14 ) ;
F_39 ( V_14 ) ;
}
static void F_40 ( T_1 * V_29 ,
void (* * F_41)( unsigned long , const char * , int , int , void * ) )
{
(* * F_41)( V_29 -> V_33 , V_29 -> V_23 , V_29 -> line , V_29 -> V_27 , V_29 -> V_15 ) ;
}
void F_42 ( void (* F_41)( unsigned long , const char * , int , int , void * ) )
{
if ( V_31 == NULL ) return;
F_2 ( V_10 ) ;
F_32 ( V_31 , ( void ( * ) () ) F_40 , ( void * ) & F_41 ) ;
F_4 ( V_10 ) ;
}
