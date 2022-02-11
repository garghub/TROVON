int F_1 ( int V_1 )
{
int V_2 = V_3 ;
F_2 ( V_4 ) ;
switch ( V_1 )
{
case V_5 :
V_3 = V_5 | V_6 ;
break;
case V_7 :
V_3 = 0 ;
break;
case V_8 :
V_3 &= ~ V_6 ;
break;
case V_6 :
if ( V_3 & V_5 )
V_3 |= V_6 ;
break;
default:
break;
}
F_3 ( V_4 ) ;
return ( V_2 ) ;
}
static int F_4 ( T_1 * V_9 , T_1 * V_10 )
{
return ( V_9 -> V_11 - V_10 -> V_11 ) ;
}
static unsigned long F_5 ( T_1 * V_9 )
{
unsigned long V_2 ;
V_2 = ( unsigned long ) V_9 -> V_11 ;
V_2 = V_2 * 17851 + ( V_2 >> 14 ) * 7 + ( V_2 >> 4 ) * 251 ;
return ( V_2 ) ;
}
void F_6 ( char * (* F_7)() , char * (* F_8)() , void (* F_9)() )
{
if ( ( F_7 == NULL ) || ( F_8 == NULL ) || ( F_9 == NULL ) ) return;
V_12 = F_7 ;
V_13 = F_8 ;
V_14 = F_9 ;
V_15 = F_7 ;
V_16 = F_9 ;
}
void F_10 ( char * (* F_7)() , void (* F_9)() )
{
if ( ( F_7 == NULL ) || ( F_9 == NULL ) ) return;
V_15 = F_7 ;
V_16 = F_9 ;
}
void F_11 ( char * (* * F_7)() , char * (* * F_8)() , void (* * F_9)() )
{
if ( F_7 != NULL ) * F_7 = V_12 ;
if ( F_8 != NULL ) * F_8 = V_13 ;
if ( F_9 != NULL ) * F_9 = V_14 ;
}
void F_12 ( char * (* * F_7)() , void (* * F_9)() )
{
if ( F_7 != NULL ) * F_7 = V_15 ;
if ( F_9 != NULL ) * F_9 = V_16 ;
}
void * F_13 ( int V_17 )
{
return ( V_15 ( V_17 ) ) ;
}
void F_14 ( void * V_18 )
{
V_16 ( V_18 ) ;
}
void * F_15 ( int V_17 )
{
return ( V_12 ( V_17 ) ) ;
}
void * F_16 ( void * V_18 , int V_17 )
{
return ( V_13 ( V_18 , V_17 ) ) ;
}
void F_17 ( void * V_18 )
{
V_14 ( V_18 ) ;
}
void * F_18 ( int V_17 , const char * V_19 , int line )
{
char * V_2 ;
T_1 * F_7 , * V_20 ;
if ( ( V_2 = V_12 ( V_17 ) ) == NULL )
return ( NULL ) ;
if ( V_3 & V_6 )
{
F_19 () ;
if ( ( F_7 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ) == NULL )
{
Free ( V_2 ) ;
F_20 () ;
return ( NULL ) ;
}
F_2 ( V_4 ) ;
if ( V_21 == NULL )
{
if ( ( V_21 = F_21 ( F_5 , F_4 ) ) == NULL )
{
Free ( V_2 ) ;
Free ( F_7 ) ;
V_2 = NULL ;
goto V_22;
}
}
F_7 -> V_11 = V_2 ;
F_7 -> V_19 = V_19 ;
F_7 -> line = line ;
F_7 -> V_17 = V_17 ;
#ifdef F_22
F_7 -> V_23 = F_23 () ;
#endif
if ( V_24 == V_25 )
{
F_7 -> V_24 = V_24 ;
}
F_7 -> V_24 = V_24 ++ ;
#ifdef F_24
F_7 -> time = time ( NULL ) ;
#endif
if ( ( V_20 = ( T_1 * ) F_25 ( V_21 , ( char * ) F_7 ) ) != NULL )
{
Free ( V_20 ) ;
}
V_22:
F_3 ( V_4 ) ;
F_20 () ;
}
return ( V_2 ) ;
}
void F_26 ( void * V_11 )
{
T_1 F_7 , * V_26 ;
if ( ( V_3 & V_6 ) && ( V_21 != NULL ) )
{
F_19 () ;
F_2 ( V_4 ) ;
F_7 . V_11 = V_11 ;
V_26 = ( T_1 * ) F_27 ( V_21 , ( char * ) & F_7 ) ;
if ( V_26 != NULL )
Free ( V_26 ) ;
F_3 ( V_4 ) ;
F_20 () ;
}
V_14 ( V_11 ) ;
}
void * F_28 ( void * V_11 , int V_17 , const char * V_19 , int line )
{
char * V_2 ;
T_1 F_7 , * V_26 ;
V_2 = V_13 ( V_11 , V_17 ) ;
if ( V_2 == V_11 ) return ( V_2 ) ;
if ( V_3 & V_6 )
{
F_19 () ;
if ( V_2 == NULL ) return ( NULL ) ;
F_7 . V_11 = V_11 ;
F_2 ( V_4 ) ;
V_26 = ( T_1 * ) F_27 ( V_21 , ( char * ) & F_7 ) ;
if ( V_26 != NULL )
{
V_26 -> V_11 = V_2 ;
F_25 ( V_21 , ( char * ) V_26 ) ;
}
F_3 ( V_4 ) ;
F_20 () ;
}
return ( V_2 ) ;
}
void * F_29 ( void * V_9 , int V_27 )
{
if ( V_9 != NULL ) Free ( V_9 ) ;
V_9 = ( char * ) Malloc ( V_27 ) ;
return ( V_9 ) ;
}
void * F_30 ( void * V_9 , int V_27 , const char * V_19 , int line )
{
if ( V_9 != NULL ) F_26 ( V_9 ) ;
V_9 = ( char * ) F_18 ( V_27 , V_19 , line ) ;
return ( V_9 ) ;
}
static void F_31 ( T_1 * F_7 , T_2 * V_28 )
{
char V_29 [ 128 ] ;
#ifdef F_24
struct V_30 * V_31 ;
#endif
if( F_7 -> V_11 == ( char * ) V_28 -> V_32 )
return;
#ifdef F_24
V_31 = localtime ( & F_7 -> time ) ;
#endif
sprintf ( V_29 ,
#ifdef F_24
L_1
#endif
L_2
#ifdef F_22
L_3
#endif
L_4 ,
#ifdef F_24
V_31 -> V_33 , V_31 -> V_34 , V_31 -> V_35 ,
#endif
F_7 -> V_24 , F_7 -> V_19 , F_7 -> line ,
#ifdef F_22
F_7 -> V_23 ,
#endif
F_7 -> V_17 , ( unsigned long ) F_7 -> V_11 ) ;
F_32 ( V_28 -> V_32 , V_29 ) ;
V_28 -> V_36 ++ ;
V_28 -> V_37 += F_7 -> V_17 ;
}
void F_33 ( T_3 * V_10 )
{
T_2 V_38 ;
char V_29 [ 80 ] ;
if ( V_21 == NULL ) return;
V_38 . V_32 = V_10 ;
V_38 . V_37 = 0 ;
V_38 . V_36 = 0 ;
F_2 ( V_4 ) ;
F_34 ( V_21 , ( void ( * ) () ) F_31 , ( char * ) & V_38 ) ;
F_3 ( V_4 ) ;
if ( V_38 . V_36 != 0 )
{
sprintf ( V_29 , L_5 ,
V_38 . V_37 , V_38 . V_36 ) ;
F_32 ( V_10 , V_29 ) ;
}
#if 0
lh_stats_bio(mh,b);
lh_node_stats_bio(mh,b);
lh_node_usage_stats_bio(mh,b);
#endif
}
static void F_35 ( T_1 * F_7 , char * V_39 )
{
void (* F_36)() = ( void ( * ) ( ) ) V_39 ;
F_36 ( F_7 -> V_24 , F_7 -> V_19 , F_7 -> line , F_7 -> V_17 , F_7 -> V_11 ) ;
}
void F_37 ( void (* V_39)() )
{
if ( V_21 == NULL ) return;
F_2 ( V_4 ) ;
V_40 = V_39 ;
F_34 ( V_21 , ( void ( * ) () ) F_35 , ( char * ) V_40 ) ;
V_40 = NULL ;
F_3 ( V_4 ) ;
}
void F_38 ( T_4 * V_41 )
{
T_3 * V_10 ;
if ( V_21 == NULL ) return;
if ( ( V_10 = F_39 ( F_40 () ) ) == NULL )
return;
F_41 ( V_10 , V_41 , V_42 ) ;
F_33 ( V_10 ) ;
F_42 ( V_10 ) ;
}
