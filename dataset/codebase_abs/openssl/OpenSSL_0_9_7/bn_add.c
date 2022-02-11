int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
const T_1 * V_4 ;
int V_5 = V_2 -> V_6 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( V_5 ^ V_3 -> V_6 )
{
if ( V_5 )
{ V_4 = V_2 ; V_2 = V_3 ; V_3 = V_4 ; }
if ( F_3 ( V_2 , V_3 ) < 0 )
{
if ( ! F_4 ( V_1 , V_3 , V_2 ) ) return ( 0 ) ;
V_1 -> V_6 = 1 ;
}
else
{
if ( ! F_4 ( V_1 , V_2 , V_3 ) ) return ( 0 ) ;
V_1 -> V_6 = 0 ;
}
return ( 1 ) ;
}
if ( ! F_5 ( V_1 , V_2 , V_3 ) ) return ( 0 ) ;
if ( V_5 )
V_1 -> V_6 = 1 ;
else
V_1 -> V_6 = 0 ;
return ( 1 ) ;
}
int F_5 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
register int V_7 ;
int V_8 , V_9 ;
T_2 * V_10 , * V_11 , * V_12 , V_13 , V_14 ;
const T_1 * V_4 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( V_2 -> V_15 < V_3 -> V_15 )
{ V_4 = V_2 ; V_2 = V_3 ; V_3 = V_4 ; }
V_8 = V_2 -> V_15 ;
V_9 = V_3 -> V_15 ;
if ( F_6 ( V_1 , V_8 + 1 ) == NULL )
return ( 0 ) ;
V_1 -> V_15 = V_8 ;
V_10 = V_2 -> V_16 ;
V_11 = V_3 -> V_16 ;
V_12 = V_1 -> V_16 ;
V_13 = 0 ;
V_13 = F_7 ( V_12 , V_10 , V_11 , V_9 ) ;
V_12 += V_9 ;
V_10 += V_9 ;
V_11 += V_9 ;
V_7 = V_9 ;
if ( V_13 )
{
while ( V_7 < V_8 )
{
V_7 ++ ;
V_14 = * ( V_10 ++ ) ;
if ( ( * ( V_12 ++ ) = ( V_14 + 1 ) & V_17 ) >= V_14 )
{
V_13 = 0 ;
break;
}
}
if ( ( V_7 >= V_8 ) && V_13 )
{
* ( V_12 ++ ) = 1 ;
V_1 -> V_15 ++ ;
}
}
if ( V_12 != V_10 )
{
for (; V_7 < V_8 ; V_7 ++ )
* ( V_12 ++ ) = * ( V_10 ++ ) ;
}
V_1 -> V_6 = 0 ;
return ( 1 ) ;
}
int F_4 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
int V_8 , V_9 ;
register T_2 V_14 , V_18 , * V_10 , * V_11 , * V_12 ;
int V_7 , V_13 ;
#if F_8 ( V_19 ) && ! F_8 ( V_20 )
int V_21 ;
#endif
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( V_2 -> V_15 < V_3 -> V_15 )
{
F_9 ( V_22 , V_23 ) ;
return ( 0 ) ;
}
V_8 = V_2 -> V_15 ;
V_9 = V_3 -> V_15 ;
if ( F_6 ( V_1 , V_8 ) == NULL ) return ( 0 ) ;
V_10 = V_2 -> V_16 ;
V_11 = V_3 -> V_16 ;
V_12 = V_1 -> V_16 ;
#if 1
V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ )
{
V_14 = * ( V_10 ++ ) ;
V_18 = * ( V_11 ++ ) ;
if ( V_13 )
{
V_13 = ( V_14 <= V_18 ) ;
V_14 = ( V_14 - V_18 - 1 ) & V_17 ;
}
else
{
V_13 = ( V_14 < V_18 ) ;
V_14 = ( V_14 - V_18 ) & V_17 ;
}
#if F_8 ( V_19 ) && ! F_8 ( V_20 )
V_21 = V_14 ;
#endif
* ( V_12 ++ ) = V_14 & V_17 ;
}
#else
V_13 = F_10 ( V_12 , V_10 , V_11 , V_9 ) ;
V_10 += V_9 ;
V_11 += V_9 ;
V_12 += V_9 ;
V_7 = V_9 ;
#endif
if ( V_13 )
{
while ( V_7 < V_8 )
{
V_7 ++ ;
V_14 = * ( V_10 ++ ) ;
V_18 = ( V_14 - 1 ) & V_17 ;
* ( V_12 ++ ) = V_18 ;
if ( V_14 > V_18 ) break;
}
}
#if 0
memcpy(rp,ap,sizeof(*rp)*(max-i));
#else
if ( V_12 != V_10 )
{
for (; ; )
{
if ( V_7 ++ >= V_8 ) break;
V_12 [ 0 ] = V_10 [ 0 ] ;
if ( V_7 ++ >= V_8 ) break;
V_12 [ 1 ] = V_10 [ 1 ] ;
if ( V_7 ++ >= V_8 ) break;
V_12 [ 2 ] = V_10 [ 2 ] ;
if ( V_7 ++ >= V_8 ) break;
V_12 [ 3 ] = V_10 [ 3 ] ;
V_12 += 4 ;
V_10 += 4 ;
}
}
#endif
V_1 -> V_15 = V_8 ;
V_1 -> V_6 = 0 ;
F_11 ( V_1 ) ;
return ( 1 ) ;
}
int F_12 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
int V_8 ;
int V_24 = 0 , V_6 = 0 ;
const T_1 * V_4 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( V_2 -> V_6 )
{
if ( V_3 -> V_6 )
{ V_4 = V_2 ; V_2 = V_3 ; V_3 = V_4 ; }
else
{ V_24 = 1 ; V_6 = 1 ; }
}
else
{
if ( V_3 -> V_6 ) { V_24 = 1 ; V_6 = 0 ; }
}
if ( V_24 )
{
if ( ! F_5 ( V_1 , V_2 , V_3 ) ) return ( 0 ) ;
V_1 -> V_6 = V_6 ;
return ( 1 ) ;
}
V_8 = ( V_2 -> V_15 > V_3 -> V_15 ) ? V_2 -> V_15 : V_3 -> V_15 ;
if ( F_6 ( V_1 , V_8 ) == NULL ) return ( 0 ) ;
if ( F_3 ( V_2 , V_3 ) < 0 )
{
if ( ! F_4 ( V_1 , V_3 , V_2 ) ) return ( 0 ) ;
V_1 -> V_6 = 1 ;
}
else
{
if ( ! F_4 ( V_1 , V_2 , V_3 ) ) return ( 0 ) ;
V_1 -> V_6 = 0 ;
}
return ( 1 ) ;
}
