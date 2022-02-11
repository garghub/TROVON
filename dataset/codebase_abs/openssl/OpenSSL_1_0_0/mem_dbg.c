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
T_2 V_13 ;
F_5 ( & V_13 ) ;
if ( ! V_10 || F_6 ( & V_14 , & V_13 ) )
{
F_7 ( V_7 ) ;
F_4 ( V_15 ) ;
F_4 ( V_7 ) ;
V_6 &= ~ V_9 ;
F_8 ( & V_14 , & V_13 ) ;
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
F_7 ( V_15 ) ;
}
}
}
break;
default:
break;
}
F_7 ( V_7 ) ;
return ( V_5 ) ;
}
int F_9 ( void )
{
int V_5 = 0 ;
if ( V_6 & V_8 )
{
T_2 V_13 ;
F_5 ( & V_13 ) ;
F_10 ( V_7 ) ;
V_5 = ( V_6 & V_9 )
|| F_6 ( & V_14 , & V_13 ) ;
F_11 ( V_7 ) ;
}
return ( V_5 ) ;
}
void F_12 ( long V_16 )
{
V_17 = V_16 ;
}
long F_13 ( void )
{
return V_17 ;
}
static int F_14 ( const T_3 * V_18 , const T_3 * V_19 )
{
#ifdef F_15
const char * V_20 = ( const char * ) V_18 -> V_21 ,
* V_22 = ( const char * ) V_19 -> V_21 ;
if ( V_20 == V_22 ) return 0 ;
else if ( V_20 > V_22 ) return 1 ;
else return - 1 ;
#else
return ( const char * ) V_18 -> V_21 - ( const char * ) V_19 -> V_21 ;
#endif
}
int F_16 ( void )
{
int V_5 = 0 ;
if ( F_17 () )
{
F_18 () ;
V_5 = ( F_19 () != NULL ) ;
F_20 () ;
}
return ( V_5 ) ;
}
int F_21 ( void )
{
int V_5 = 0 ;
if ( F_17 () )
{
F_18 () ;
while( F_19 () != NULL )
V_5 ++ ;
F_20 () ;
}
return ( V_5 ) ;
}
void F_22 ( void * V_21 , int V_23 , const char * V_24 , int line ,
int V_25 )
{
T_3 * V_26 , * V_27 ;
T_1 V_28 , * V_29 ;
switch( V_25 & 127 )
{
case 0 :
break;
case 1 :
if ( V_21 == NULL )
break;
if ( F_17 () )
{
F_18 () ;
if ( ( V_26 = ( T_3 * ) F_23 ( sizeof( T_3 ) ) ) == NULL )
{
F_2 ( V_21 ) ;
F_20 () ;
return;
}
if ( V_30 == NULL )
{
if ( ( V_30 = F_24 () ) == NULL )
{
F_2 ( V_21 ) ;
F_2 ( V_26 ) ;
V_21 = NULL ;
goto V_31;
}
}
V_26 -> V_21 = V_21 ;
V_26 -> V_24 = V_24 ;
V_26 -> line = line ;
V_26 -> V_23 = V_23 ;
if ( V_17 & V_32 )
F_5 ( & V_26 -> V_33 ) ;
else
memset ( & V_26 -> V_33 , 0 , sizeof( V_26 -> V_33 ) ) ;
if ( V_34 == V_35 )
{
V_26 -> V_34 = V_34 ;
}
V_26 -> V_34 = V_34 ++ ;
#ifdef F_25
fprintf ( V_36 , L_1 ,
V_26 -> V_34 ,
( V_25 & 128 ) ? '*' : '+' ,
V_26 -> V_21 , V_26 -> V_23 ) ;
#endif
if ( V_17 & V_37 )
V_26 -> time = time ( NULL ) ;
else
V_26 -> time = 0 ;
F_5 ( & V_28 . V_33 ) ;
V_26 -> V_38 = NULL ;
if ( V_39 != NULL
&& ( V_29 = F_26 ( V_39 , & V_28 ) ) != NULL )
{
V_26 -> V_38 = V_29 ;
V_29 -> V_2 ++ ;
}
if ( ( V_27 = F_27 ( V_30 , V_26 ) ) != NULL )
{
if ( V_27 -> V_38 != NULL )
{
V_27 -> V_38 -> V_2 -- ;
}
F_2 ( V_27 ) ;
}
V_31:
F_20 () ;
}
break;
}
return;
}
void F_28 ( void * V_21 , int V_25 )
{
T_3 V_26 , * V_40 ;
switch( V_25 )
{
case 0 :
if ( V_21 == NULL )
break;
if ( F_17 () && ( V_30 != NULL ) )
{
F_18 () ;
V_26 . V_21 = V_21 ;
V_40 = F_29 ( V_30 , & V_26 ) ;
if ( V_40 != NULL )
{
#ifdef F_25
fprintf ( V_36 , L_2 ,
V_40 -> V_34 , V_40 -> V_21 , V_40 -> V_23 ) ;
#endif
if ( V_40 -> V_38 != NULL )
F_1 ( V_40 -> V_38 ) ;
F_2 ( V_40 ) ;
}
F_20 () ;
}
break;
case 1 :
break;
}
}
void F_30 ( void * V_41 , void * V_42 , int V_23 ,
const char * V_24 , int line , int V_25 )
{
T_3 V_26 , * V_40 ;
#ifdef F_25
fprintf ( V_36 , L_3 ,
V_41 , V_42 , V_23 , V_24 , line , V_25 ) ;
#endif
switch( V_25 )
{
case 0 :
break;
case 1 :
if ( V_42 == NULL )
break;
if ( V_41 == NULL )
{
F_22 ( V_42 , V_23 , V_24 , line , 128 | V_25 ) ;
break;
}
if ( F_17 () )
{
F_18 () ;
V_26 . V_21 = V_41 ;
V_40 = F_29 ( V_30 , & V_26 ) ;
if ( V_40 != NULL )
{
#ifdef F_25
fprintf ( V_36 , L_4 ,
V_40 -> V_34 ,
V_40 -> V_21 , V_40 -> V_23 ,
V_42 , V_23 ) ;
#endif
V_40 -> V_21 = V_42 ;
V_40 -> V_23 = V_23 ;
( void ) F_27 ( V_30 , V_40 ) ;
}
F_20 () ;
}
break;
}
return;
}
static void F_31 ( const T_3 * V_26 , T_4 * V_43 )
{
char V_44 [ 1024 ] ;
char * V_45 = V_44 ;
T_1 * V_46 ;
int V_47 ;
struct V_48 * V_49 = NULL ;
T_2 V_50 ;
#define F_32 (sizeof buf - (size_t)(bufp - buf))
if( V_26 -> V_21 == ( char * ) V_43 -> V_51 )
return;
if ( V_17 & V_37 )
{
V_49 = localtime ( & V_26 -> time ) ;
F_33 ( V_45 , F_32 , L_5 ,
V_49 -> V_52 , V_49 -> V_53 , V_49 -> V_54 ) ;
V_45 += strlen ( V_45 ) ;
}
F_33 ( V_45 , F_32 , L_6 ,
V_26 -> V_34 , V_26 -> V_24 , V_26 -> line ) ;
V_45 += strlen ( V_45 ) ;
if ( V_17 & V_32 )
{
F_33 ( V_45 , F_32 , L_7 ,
F_34 ( & V_26 -> V_33 ) ) ;
V_45 += strlen ( V_45 ) ;
}
F_33 ( V_45 , F_32 , L_8 ,
V_26 -> V_23 , ( unsigned long ) V_26 -> V_21 ) ;
V_45 += strlen ( V_45 ) ;
F_35 ( V_43 -> V_51 , V_44 ) ;
V_43 -> V_55 ++ ;
V_43 -> V_56 += V_26 -> V_23 ;
V_46 = V_26 -> V_38 ;
V_47 = 0 ;
if ( ! V_46 )
return;
F_8 ( & V_50 , & V_46 -> V_33 ) ;
do
{
int V_57 ;
int V_58 ;
V_47 ++ ;
memset ( V_44 , '>' , V_47 ) ;
F_33 ( V_44 + V_47 , sizeof V_44 - V_47 ,
L_9 ,
F_34 ( & V_46 -> V_33 ) , V_46 -> V_24 ,
V_46 -> line ) ;
V_57 = strlen ( V_44 ) ;
V_58 = strlen ( V_46 -> V_59 ) ;
if ( 128 - V_57 - 3 < V_58 )
{
memcpy ( V_44 + V_57 , V_46 -> V_59 , 128 - V_57 - 3 ) ;
V_57 = 128 - 3 ;
}
else
{
F_36 ( V_44 + V_57 , V_46 -> V_59 ,
sizeof V_44 - V_57 ) ;
V_57 = strlen ( V_44 ) ;
}
F_33 ( V_44 + V_57 , sizeof V_44 - V_57 , L_10 ) ;
F_35 ( V_43 -> V_51 , V_44 ) ;
V_46 = V_46 -> V_3 ;
}
while( V_46 && ! F_6 ( & V_46 -> V_33 , & V_50 ) );
#ifdef F_25
if ( V_46 )
{
fprintf ( V_36 , L_11 ) ;
abort () ;
}
#endif
}
static void F_37 ( const T_3 * V_26 , T_5 * V_60 )
{
(* V_60)( V_26 -> V_34 , V_26 -> V_24 , V_26 -> line , V_26 -> V_23 , V_26 -> V_21 ) ;
}
