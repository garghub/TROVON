int F_1 ( int V_1 )
{
int V_2 = V_3 ;
F_2 ( V_4 ) ;
switch ( V_1 )
{
case V_5 :
V_3 |= V_5 ;
break;
case V_6 :
V_3 &= ~ V_5 ;
break;
case V_7 :
V_3 &= ~ V_8 ;
break;
case V_8 :
if ( V_3 & V_5 )
V_3 |= V_8 ;
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
if ( V_3 & V_8 )
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
if ( V_23 == V_24 )
{
F_7 -> V_23 = V_23 ;
}
F_7 -> V_23 = V_23 ++ ;
if ( ( V_20 = ( T_1 * ) F_22 ( V_21 , ( char * ) F_7 ) ) != NULL )
{
Free ( V_20 ) ;
}
V_22:
F_3 ( V_4 ) ;
F_20 () ;
}
return ( V_2 ) ;
}
void F_23 ( void * V_11 )
{
T_1 F_7 , * V_25 ;
if ( ( V_3 & V_8 ) && ( V_21 != NULL ) )
{
F_19 () ;
F_2 ( V_4 ) ;
F_7 . V_11 = V_11 ;
V_25 = ( T_1 * ) F_24 ( V_21 , ( char * ) & F_7 ) ;
if ( V_25 != NULL )
Free ( V_25 ) ;
F_3 ( V_4 ) ;
F_20 () ;
}
V_14 ( V_11 ) ;
}
void * F_25 ( void * V_11 , int V_17 , const char * V_19 , int line )
{
char * V_2 ;
T_1 F_7 , * V_25 ;
V_2 = V_13 ( V_11 , V_17 ) ;
if ( V_2 == V_11 ) return ( V_2 ) ;
if ( V_3 & V_8 )
{
F_19 () ;
if ( V_2 == NULL ) return ( NULL ) ;
F_7 . V_11 = V_11 ;
F_2 ( V_4 ) ;
V_25 = ( T_1 * ) F_24 ( V_21 , ( char * ) & F_7 ) ;
if ( V_25 != NULL )
{
V_25 -> V_11 = V_2 ;
F_22 ( V_21 , ( char * ) V_25 ) ;
}
F_3 ( V_4 ) ;
F_20 () ;
}
return ( V_2 ) ;
}
void * F_26 ( void * V_9 , int V_26 )
{
if ( V_9 != NULL ) Free ( V_9 ) ;
V_9 = ( char * ) Malloc ( V_26 ) ;
return ( V_9 ) ;
}
void * F_27 ( void * V_9 , int V_26 , const char * V_19 , int line )
{
if ( V_9 != NULL ) F_23 ( V_9 ) ;
V_9 = ( char * ) F_18 ( V_26 , V_19 , line ) ;
return ( V_9 ) ;
}
static void F_28 ( T_1 * F_7 , T_2 * V_27 )
{
char V_28 [ 128 ] ;
if( F_7 -> V_11 == ( char * ) V_27 -> V_29 )
return;
sprintf ( V_28 , L_1 ,
F_7 -> V_23 , F_7 -> V_19 , F_7 -> line , F_7 -> V_17 , ( long ) F_7 -> V_11 ) ;
F_29 ( V_27 -> V_29 , V_28 ) ;
V_27 -> V_30 ++ ;
V_27 -> V_31 += F_7 -> V_17 ;
}
void F_30 ( T_3 * V_10 )
{
T_2 V_32 ;
char V_28 [ 80 ] ;
if ( V_21 == NULL ) return;
V_32 . V_29 = V_10 ;
V_32 . V_31 = 0 ;
V_32 . V_30 = 0 ;
F_2 ( V_4 ) ;
F_31 ( V_21 , ( void ( * ) () ) F_28 , ( char * ) & V_32 ) ;
F_3 ( V_4 ) ;
if ( V_32 . V_30 != 0 )
{
sprintf ( V_28 , L_2 ,
V_32 . V_31 , V_32 . V_30 ) ;
F_29 ( V_10 , V_28 ) ;
}
#if 0
lh_stats_bio(mh,b);
lh_node_stats_bio(mh,b);
lh_node_usage_stats_bio(mh,b);
#endif
}
static void F_32 ( T_1 * F_7 , char * V_33 )
{
void (* F_33)() = ( void ( * ) ( ) ) V_33 ;
F_33 ( F_7 -> V_23 , F_7 -> V_19 , F_7 -> line , F_7 -> V_17 , F_7 -> V_11 ) ;
}
void F_34 ( void (* V_33)() )
{
if ( V_21 == NULL ) return;
F_2 ( V_4 ) ;
V_34 = V_33 ;
F_31 ( V_21 , ( void ( * ) () ) F_32 , ( char * ) V_34 ) ;
V_34 = NULL ;
F_3 ( V_4 ) ;
}
void F_35 ( T_4 * V_35 )
{
T_3 * V_10 ;
if ( V_21 == NULL ) return;
if ( ( V_10 = F_36 ( F_37 () ) ) == NULL )
return;
F_38 ( V_10 , V_35 , V_36 ) ;
F_30 ( V_10 ) ;
F_39 ( V_10 ) ;
}
