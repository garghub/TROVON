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
V_3 -> V_6 = V_5 ;
V_3 -> V_7 = 0 ;
V_2 -> V_8 = 1 ;
V_2 -> V_9 = ( char * ) V_3 ;
V_2 -> V_10 = 0 ;
return ( 1 ) ;
}
static int F_5 ( T_2 * V_11 )
{
T_3 * V_12 ;
if ( V_11 == NULL ) return ( 0 ) ;
V_12 = ( T_3 * ) V_11 -> V_9 ;
if ( V_12 -> V_4 != NULL ) F_4 ( V_12 -> V_4 ) ;
F_4 ( V_11 -> V_9 ) ;
V_11 -> V_9 = NULL ;
V_11 -> V_8 = 0 ;
V_11 -> V_10 = 0 ;
return ( 1 ) ;
}
static int F_6 ( T_2 * V_12 , char * V_13 , int V_14 )
{
int V_15 = 0 ;
if ( V_13 == NULL ) return ( 0 ) ;
if ( V_12 -> V_16 == NULL ) return ( 0 ) ;
V_15 = F_7 ( V_12 -> V_16 , V_13 , V_14 ) ;
F_8 ( V_12 ) ;
F_9 ( V_12 ) ;
return ( V_15 ) ;
}
static int F_10 ( T_2 * V_12 , const char * V_17 , int V_18 )
{
int V_19 , V_20 = 0 , V_21 ;
T_3 * V_3 ;
if ( ( V_17 == NULL ) || ( V_18 <= 0 ) ) return ( 0 ) ;
V_3 = ( T_3 * ) V_12 -> V_9 ;
if ( ( V_3 == NULL ) || ( V_12 -> V_16 == NULL ) ) return ( 0 ) ;
F_8 ( V_12 ) ;
do
{
const char * V_22 ;
for( V_22 = V_17 ; V_22 < V_17 + V_18 && * V_22 != '\n' ; V_22 ++ )
;
if ( * V_22 == '\n' )
{
V_22 ++ ;
V_21 = 1 ;
}
else
V_21 = 0 ;
while ( ( V_21 || V_22 - V_17 > V_3 -> V_6 - V_3 -> V_7 )
&& V_3 -> V_7 > 0 )
{
int V_23 = V_3 -> V_7 ;
V_19 = V_3 -> V_6 - V_3 -> V_7 ;
if ( V_22 - V_17 > 0 )
{
if ( V_19 >= V_22 - V_17 )
{
memcpy ( & ( V_3 -> V_4 [ V_3 -> V_7 ] ) ,
V_17 , V_22 - V_17 ) ;
V_3 -> V_7 += V_22 - V_17 ;
V_18 -= V_22 - V_17 ;
V_20 += V_22 - V_17 ;
V_17 = V_22 ;
}
else
{
memcpy ( & ( V_3 -> V_4 [ V_3 -> V_7 ] ) ,
V_17 , V_19 ) ;
V_3 -> V_7 += V_19 ;
V_18 -= V_19 ;
V_17 += V_19 ;
V_20 += V_19 ;
}
}
#ifdef F_11
F_12 ( V_12 -> V_16 , L_1 , 3 ) ;
#endif
V_19 = F_12 ( V_12 -> V_16 ,
V_3 -> V_4 , V_3 -> V_7 ) ;
if ( V_19 <= 0 )
{
V_3 -> V_7 = V_23 ;
F_9 ( V_12 ) ;
#ifdef F_11
F_12 ( V_12 -> V_16 , L_2 , 3 ) ;
#endif
if ( V_19 < 0 ) return ( ( V_20 > 0 ) ? V_20 : V_19 ) ;
if ( V_19 == 0 ) return ( V_20 ) ;
}
#ifdef F_11
F_12 ( V_12 -> V_16 , L_2 , 3 ) ;
#endif
if ( V_19 < V_3 -> V_7 )
memmove ( V_3 -> V_4 , V_3 -> V_4 + V_19 ,
V_3 -> V_7 - V_19 ) ;
V_3 -> V_7 -= V_19 ;
}
if ( ( V_21 || V_22 - V_17 > V_3 -> V_6 ) && V_22 - V_17 > 0 )
{
#ifdef F_11
F_12 ( V_12 -> V_16 , L_1 , 3 ) ;
#endif
V_19 = F_12 ( V_12 -> V_16 , V_17 , V_22 - V_17 ) ;
if ( V_19 <= 0 )
{
F_9 ( V_12 ) ;
#ifdef F_11
F_12 ( V_12 -> V_16 , L_2 , 3 ) ;
#endif
if ( V_19 < 0 ) return ( ( V_20 > 0 ) ? V_20 : V_19 ) ;
if ( V_19 == 0 ) return ( V_20 ) ;
}
#ifdef F_11
F_12 ( V_12 -> V_16 , L_2 , 3 ) ;
#endif
V_20 += V_19 ;
V_17 += V_19 ;
V_18 -= V_19 ;
}
}
while( V_21 && V_18 > 0 );
if ( V_18 > 0 )
{
memcpy ( & ( V_3 -> V_4 [ V_3 -> V_7 ] ) , V_17 , V_18 ) ;
V_3 -> V_7 += V_18 ;
V_20 += V_18 ;
}
return V_20 ;
}
static long F_13 ( T_2 * V_12 , int V_24 , long V_20 , void * V_9 )
{
T_2 * V_25 ;
T_3 * V_3 ;
long V_15 = 1 ;
char * V_22 ;
int V_26 ;
int V_27 ;
V_3 = ( T_3 * ) V_12 -> V_9 ;
switch ( V_24 )
{
case V_28 :
V_3 -> V_7 = 0 ;
if ( V_12 -> V_16 == NULL ) return ( 0 ) ;
V_15 = F_14 ( V_12 -> V_16 , V_24 , V_20 , V_9 ) ;
break;
case V_29 :
V_15 = ( long ) V_3 -> V_7 ;
break;
case V_30 :
V_15 = ( long ) V_3 -> V_7 ;
if ( V_15 == 0 )
{
if ( V_12 -> V_16 == NULL ) return ( 0 ) ;
V_15 = F_14 ( V_12 -> V_16 , V_24 , V_20 , V_9 ) ;
}
break;
case V_31 :
V_27 = ( int ) V_20 ;
V_22 = V_3 -> V_4 ;
if ( ( V_27 > V_5 ) && ( V_27 != V_3 -> V_6 ) )
{
V_22 = ( char * ) F_3 ( ( int ) V_20 ) ;
if ( V_22 == NULL )
goto V_32;
}
if ( V_3 -> V_4 != V_22 )
{
if ( V_3 -> V_7 > V_27 )
{
V_3 -> V_7 = V_27 ;
}
memcpy ( V_22 , V_3 -> V_4 , V_3 -> V_7 ) ;
F_4 ( V_3 -> V_4 ) ;
V_3 -> V_4 = V_22 ;
V_3 -> V_6 = V_27 ;
}
break;
case V_33 :
if ( V_12 -> V_16 == NULL ) return ( 0 ) ;
F_8 ( V_12 ) ;
V_15 = F_14 ( V_12 -> V_16 , V_24 , V_20 , V_9 ) ;
F_9 ( V_12 ) ;
break;
case V_34 :
if ( V_12 -> V_16 == NULL ) return ( 0 ) ;
if ( V_3 -> V_7 <= 0 )
{
V_15 = F_14 ( V_12 -> V_16 , V_24 , V_20 , V_9 ) ;
break;
}
for (; ; )
{
F_8 ( V_12 ) ;
if ( V_3 -> V_7 > 0 )
{
V_26 = F_12 ( V_12 -> V_16 ,
V_3 -> V_4 , V_3 -> V_7 ) ;
#if 0
fprintf(stderr,"FLUSH %3d -> %3d\n",ctx->obuf_len,r);
#endif
F_9 ( V_12 ) ;
if ( V_26 <= 0 ) return ( ( long ) V_26 ) ;
if ( V_26 < V_3 -> V_7 )
memmove ( V_3 -> V_4 , V_3 -> V_4 + V_26 ,
V_3 -> V_7 - V_26 ) ;
V_3 -> V_7 -= V_26 ;
}
else
{
V_3 -> V_7 = 0 ;
V_15 = 1 ;
break;
}
}
V_15 = F_14 ( V_12 -> V_16 , V_24 , V_20 , V_9 ) ;
break;
case V_35 :
V_25 = ( T_2 * ) V_9 ;
if ( ! F_15 ( V_25 , V_3 -> V_6 ) )
V_15 = 0 ;
break;
default:
if ( V_12 -> V_16 == NULL ) return ( 0 ) ;
V_15 = F_14 ( V_12 -> V_16 , V_24 , V_20 , V_9 ) ;
break;
}
return ( V_15 ) ;
V_32:
F_16 ( V_36 , V_37 ) ;
return ( 0 ) ;
}
static long F_17 ( T_2 * V_12 , int V_24 , T_4 * V_38 )
{
long V_15 = 1 ;
if ( V_12 -> V_16 == NULL ) return ( 0 ) ;
switch ( V_24 )
{
default:
V_15 = F_18 ( V_12 -> V_16 , V_24 , V_38 ) ;
break;
}
return ( V_15 ) ;
}
static int F_19 ( T_2 * V_12 , char * V_39 , int V_40 )
{
if ( V_12 -> V_16 == NULL ) return ( 0 ) ;
return ( F_20 ( V_12 -> V_16 , V_39 , V_40 ) ) ;
}
static int F_21 ( T_2 * V_12 , const char * V_41 )
{
return ( F_10 ( V_12 , V_41 , strlen ( V_41 ) ) ) ;
}
