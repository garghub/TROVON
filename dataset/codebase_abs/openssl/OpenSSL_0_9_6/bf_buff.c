T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = ( T_3 * ) F_3 ( sizeof( T_3 ) ) ;
if ( V_3 == NULL ) return ( 0 ) ;
V_3 -> V_4 = ( char * ) F_3 ( V_5 ) ;
if ( V_3 -> V_4 == NULL ) { F_4 ( V_3 ) ; return ( 0 ) ; }
V_3 -> V_6 = ( char * ) F_3 ( V_5 ) ;
if ( V_3 -> V_6 == NULL ) { F_4 ( V_3 -> V_4 ) ; F_4 ( V_3 ) ; return ( 0 ) ; }
V_3 -> V_7 = V_5 ;
V_3 -> V_8 = V_5 ;
V_3 -> V_9 = 0 ;
V_3 -> V_10 = 0 ;
V_3 -> V_11 = 0 ;
V_3 -> V_12 = 0 ;
V_2 -> V_13 = 1 ;
V_2 -> V_14 = ( char * ) V_3 ;
V_2 -> V_15 = 0 ;
return ( 1 ) ;
}
static int F_5 ( T_2 * V_16 )
{
T_3 * V_17 ;
if ( V_16 == NULL ) return ( 0 ) ;
V_17 = ( T_3 * ) V_16 -> V_14 ;
if ( V_17 -> V_4 != NULL ) F_4 ( V_17 -> V_4 ) ;
if ( V_17 -> V_6 != NULL ) F_4 ( V_17 -> V_6 ) ;
F_4 ( V_16 -> V_14 ) ;
V_16 -> V_14 = NULL ;
V_16 -> V_13 = 0 ;
V_16 -> V_15 = 0 ;
return ( 1 ) ;
}
static int F_6 ( T_2 * V_17 , char * V_18 , int V_19 )
{
int V_20 , V_21 = 0 ;
T_3 * V_3 ;
if ( V_18 == NULL ) return ( 0 ) ;
V_3 = ( T_3 * ) V_17 -> V_14 ;
if ( ( V_3 == NULL ) || ( V_17 -> V_22 == NULL ) ) return ( 0 ) ;
V_21 = 0 ;
F_7 ( V_17 ) ;
V_23:
V_20 = V_3 -> V_9 ;
if ( V_20 != 0 )
{
if ( V_20 > V_19 ) V_20 = V_19 ;
memcpy ( V_18 , & ( V_3 -> V_4 [ V_3 -> V_10 ] ) , V_20 ) ;
V_3 -> V_10 += V_20 ;
V_3 -> V_9 -= V_20 ;
V_21 += V_20 ;
if ( V_19 == V_20 ) return ( V_21 ) ;
V_19 -= V_20 ;
V_18 += V_20 ;
}
if ( V_19 > V_3 -> V_7 )
{
for (; ; )
{
V_20 = F_8 ( V_17 -> V_22 , V_18 , V_19 ) ;
if ( V_20 <= 0 )
{
F_9 ( V_17 ) ;
if ( V_20 < 0 ) return ( ( V_21 > 0 ) ? V_21 : V_20 ) ;
if ( V_20 == 0 ) return ( V_21 ) ;
}
V_21 += V_20 ;
if ( V_19 == V_20 ) return ( V_21 ) ;
V_18 += V_20 ;
V_19 -= V_20 ;
}
}
V_20 = F_8 ( V_17 -> V_22 , V_3 -> V_4 , V_3 -> V_7 ) ;
if ( V_20 <= 0 )
{
F_9 ( V_17 ) ;
if ( V_20 < 0 ) return ( ( V_21 > 0 ) ? V_21 : V_20 ) ;
if ( V_20 == 0 ) return ( V_21 ) ;
}
V_3 -> V_10 = 0 ;
V_3 -> V_9 = V_20 ;
goto V_23;
}
static int F_10 ( T_2 * V_17 , const char * V_24 , int V_25 )
{
int V_20 , V_21 = 0 ;
T_3 * V_3 ;
if ( ( V_24 == NULL ) || ( V_25 <= 0 ) ) return ( 0 ) ;
V_3 = ( T_3 * ) V_17 -> V_14 ;
if ( ( V_3 == NULL ) || ( V_17 -> V_22 == NULL ) ) return ( 0 ) ;
F_7 ( V_17 ) ;
V_23:
V_20 = V_3 -> V_8 - ( V_3 -> V_11 + V_3 -> V_12 ) ;
if ( V_20 >= V_25 )
{
memcpy ( & ( V_3 -> V_6 [ V_3 -> V_11 ] ) , V_24 , V_25 ) ;
V_3 -> V_11 += V_25 ;
return ( V_21 + V_25 ) ;
}
if ( V_3 -> V_11 != 0 )
{
if ( V_20 > 0 )
{
memcpy ( & ( V_3 -> V_6 [ V_3 -> V_11 ] ) , V_24 , V_20 ) ;
V_24 += V_20 ;
V_25 -= V_20 ;
V_21 += V_20 ;
V_3 -> V_11 += V_20 ;
}
for (; ; )
{
V_20 = F_11 ( V_17 -> V_22 , & ( V_3 -> V_6 [ V_3 -> V_12 ] ) ,
V_3 -> V_11 ) ;
if ( V_20 <= 0 )
{
F_9 ( V_17 ) ;
if ( V_20 < 0 ) return ( ( V_21 > 0 ) ? V_21 : V_20 ) ;
if ( V_20 == 0 ) return ( V_21 ) ;
}
V_3 -> V_12 += V_20 ;
V_3 -> V_11 -= V_20 ;
if ( V_3 -> V_11 == 0 ) break;
}
}
V_3 -> V_12 = 0 ;
while ( V_25 >= V_3 -> V_8 )
{
V_20 = F_11 ( V_17 -> V_22 , V_24 , V_25 ) ;
if ( V_20 <= 0 )
{
F_9 ( V_17 ) ;
if ( V_20 < 0 ) return ( ( V_21 > 0 ) ? V_21 : V_20 ) ;
if ( V_20 == 0 ) return ( V_21 ) ;
}
V_21 += V_20 ;
V_24 += V_20 ;
V_25 -= V_20 ;
if ( V_25 == 0 ) return ( V_21 ) ;
}
goto V_23;
}
static long F_12 ( T_2 * V_17 , int V_26 , long V_21 , void * V_14 )
{
T_2 * V_27 ;
T_3 * V_3 ;
long V_28 = 1 ;
char * V_29 , * V_30 ;
int V_31 , V_20 , * V_32 ;
int V_33 , V_34 ;
V_3 = ( T_3 * ) V_17 -> V_14 ;
switch ( V_26 )
{
case V_35 :
V_3 -> V_10 = 0 ;
V_3 -> V_9 = 0 ;
V_3 -> V_12 = 0 ;
V_3 -> V_11 = 0 ;
if ( V_17 -> V_22 == NULL ) return ( 0 ) ;
V_28 = F_13 ( V_17 -> V_22 , V_26 , V_21 , V_14 ) ;
break;
case V_36 :
V_28 = ( long ) V_3 -> V_11 ;
break;
case V_37 :
V_28 = 0 ;
V_29 = V_3 -> V_4 ;
for ( V_20 = V_3 -> V_10 ; V_20 < V_3 -> V_9 ; V_20 ++ )
{
if ( V_29 [ V_20 ] == '\n' ) V_28 ++ ;
}
break;
case V_38 :
V_28 = ( long ) V_3 -> V_11 ;
if ( V_28 == 0 )
{
if ( V_17 -> V_22 == NULL ) return ( 0 ) ;
V_28 = F_13 ( V_17 -> V_22 , V_26 , V_21 , V_14 ) ;
}
break;
case V_39 :
V_28 = ( long ) V_3 -> V_9 ;
if ( V_28 == 0 )
{
if ( V_17 -> V_22 == NULL ) return ( 0 ) ;
V_28 = F_13 ( V_17 -> V_22 , V_26 , V_21 , V_14 ) ;
}
break;
case V_40 :
if ( V_21 > V_3 -> V_7 )
{
V_29 = F_3 ( ( int ) V_21 ) ;
if ( V_29 == NULL ) goto V_41;
if ( V_3 -> V_4 != NULL ) F_4 ( V_3 -> V_4 ) ;
V_3 -> V_4 = V_29 ;
}
V_3 -> V_10 = 0 ;
V_3 -> V_9 = ( int ) V_21 ;
memcpy ( V_3 -> V_4 , V_14 , ( int ) V_21 ) ;
V_28 = 1 ;
break;
case V_42 :
if ( V_14 != NULL )
{
V_32 = ( int * ) V_14 ;
if ( * V_32 == 0 )
{
V_33 = ( int ) V_21 ;
V_34 = V_3 -> V_8 ;
}
else
{
V_33 = V_3 -> V_7 ;
V_34 = ( int ) V_21 ;
}
}
else
{
V_33 = ( int ) V_21 ;
V_34 = ( int ) V_21 ;
}
V_29 = V_3 -> V_4 ;
V_30 = V_3 -> V_6 ;
if ( ( V_33 > V_5 ) && ( V_33 != V_3 -> V_7 ) )
{
V_29 = ( char * ) F_3 ( ( int ) V_21 ) ;
if ( V_29 == NULL ) goto V_41;
}
if ( ( V_34 > V_5 ) && ( V_34 != V_3 -> V_8 ) )
{
V_30 = ( char * ) F_3 ( ( int ) V_21 ) ;
if ( V_30 == NULL )
{
if ( V_29 != V_3 -> V_4 ) F_4 ( V_29 ) ;
goto V_41;
}
}
if ( V_3 -> V_4 != V_29 )
{
F_4 ( V_3 -> V_4 ) ;
V_3 -> V_4 = V_29 ;
V_3 -> V_10 = 0 ;
V_3 -> V_9 = 0 ;
V_3 -> V_7 = V_33 ;
}
if ( V_3 -> V_6 != V_30 )
{
F_4 ( V_3 -> V_6 ) ;
V_3 -> V_6 = V_30 ;
V_3 -> V_12 = 0 ;
V_3 -> V_11 = 0 ;
V_3 -> V_8 = V_34 ;
}
break;
case V_43 :
if ( V_17 -> V_22 == NULL ) return ( 0 ) ;
F_7 ( V_17 ) ;
V_28 = F_13 ( V_17 -> V_22 , V_26 , V_21 , V_14 ) ;
F_9 ( V_17 ) ;
break;
case V_44 :
if ( V_17 -> V_22 == NULL ) return ( 0 ) ;
if ( V_3 -> V_11 <= 0 )
{
V_28 = F_13 ( V_17 -> V_22 , V_26 , V_21 , V_14 ) ;
break;
}
for (; ; )
{
F_7 ( V_17 ) ;
if ( V_3 -> V_11 > V_3 -> V_12 )
{
V_31 = F_11 ( V_17 -> V_22 ,
& ( V_3 -> V_6 [ V_3 -> V_12 ] ) ,
V_3 -> V_11 - V_3 -> V_12 ) ;
#if 0
fprintf(stderr,"FLUSH [%3d] %3d -> %3d\n",ctx->obuf_off,ctx->obuf_len-ctx->obuf_off,r);
#endif
F_9 ( V_17 ) ;
if ( V_31 <= 0 ) return ( ( long ) V_31 ) ;
V_3 -> V_12 += V_31 ;
}
else
{
V_3 -> V_11 = 0 ;
V_3 -> V_12 = 0 ;
V_28 = 1 ;
break;
}
}
V_28 = F_13 ( V_17 -> V_22 , V_26 , V_21 , V_14 ) ;
break;
case V_45 :
V_27 = ( T_2 * ) V_14 ;
if ( ! F_14 ( V_27 , V_3 -> V_7 ) ||
! F_15 ( V_27 , V_3 -> V_8 ) )
V_28 = 0 ;
break;
default:
if ( V_17 -> V_22 == NULL ) return ( 0 ) ;
V_28 = F_13 ( V_17 -> V_22 , V_26 , V_21 , V_14 ) ;
break;
}
return ( V_28 ) ;
V_41:
F_16 ( V_46 , V_47 ) ;
return ( 0 ) ;
}
static long F_17 ( T_2 * V_17 , int V_26 , T_4 * V_48 )
{
long V_28 = 1 ;
if ( V_17 -> V_22 == NULL ) return ( 0 ) ;
switch ( V_26 )
{
default:
V_28 = F_18 ( V_17 -> V_22 , V_26 , V_48 ) ;
break;
}
return ( V_28 ) ;
}
static int F_19 ( T_2 * V_17 , char * V_49 , int V_50 )
{
T_3 * V_3 ;
int V_21 = 0 , V_20 , V_51 ;
char * V_52 ;
V_3 = ( T_3 * ) V_17 -> V_14 ;
V_50 -- ;
F_7 ( V_17 ) ;
for (; ; )
{
if ( V_3 -> V_9 > 0 )
{
V_52 = & ( V_3 -> V_4 [ V_3 -> V_10 ] ) ;
V_51 = 0 ;
for ( V_20 = 0 ; ( V_20 < V_3 -> V_9 ) && ( V_20 < V_50 ) ; V_20 ++ )
{
* ( V_49 ++ ) = V_52 [ V_20 ] ;
if ( V_52 [ V_20 ] == '\n' )
{
V_51 = 1 ;
V_20 ++ ;
break;
}
}
V_21 += V_20 ;
V_50 -= V_20 ;
V_3 -> V_9 -= V_20 ;
V_3 -> V_10 += V_20 ;
if ( ( V_51 ) || ( V_20 == V_50 ) )
{
* V_49 = '\0' ;
return ( V_21 ) ;
}
}
else
{
V_20 = F_8 ( V_17 -> V_22 , V_3 -> V_4 , V_3 -> V_7 ) ;
if ( V_20 <= 0 )
{
F_9 ( V_17 ) ;
if ( V_20 < 0 ) return ( ( V_21 > 0 ) ? V_21 : V_20 ) ;
if ( V_20 == 0 ) return ( V_21 ) ;
}
V_3 -> V_9 = V_20 ;
V_3 -> V_10 = 0 ;
}
}
}
static int F_20 ( T_2 * V_17 , const char * V_53 )
{
return ( F_10 ( V_17 , V_53 , strlen ( V_53 ) ) ) ;
}
