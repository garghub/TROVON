int F_1 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 )
{
T_1 * V_4 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( V_2 -> V_5 ^ V_3 -> V_5 )
{
if ( V_2 -> V_5 )
{ V_4 = V_2 ; V_2 = V_3 ; V_3 = V_4 ; }
if ( F_3 ( V_2 , V_3 ) < 0 )
{
if ( ! F_4 ( V_1 , V_3 , V_2 ) ) return ( 0 ) ;
V_1 -> V_5 = 1 ;
}
else
{
if ( ! F_4 ( V_1 , V_2 , V_3 ) ) return ( 0 ) ;
V_1 -> V_5 = 0 ;
}
return ( 1 ) ;
}
if ( V_2 -> V_5 )
V_1 -> V_5 = 1 ;
else
V_1 -> V_5 = 0 ;
if ( ! F_5 ( V_1 , V_2 , V_3 ) ) return ( 0 ) ;
return ( 1 ) ;
}
int F_5 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
register int V_6 ;
int V_7 , V_8 ;
T_2 * V_9 , * V_10 , * V_11 , V_12 , V_13 ;
const T_1 * V_4 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( V_2 -> V_14 < V_3 -> V_14 )
{ V_4 = V_2 ; V_2 = V_3 ; V_3 = V_4 ; }
V_7 = V_2 -> V_14 ;
V_8 = V_3 -> V_14 ;
if ( F_6 ( V_1 , V_7 + 1 ) == NULL )
return ( 0 ) ;
V_1 -> V_14 = V_7 ;
V_9 = V_2 -> V_15 ;
V_10 = V_3 -> V_15 ;
V_11 = V_1 -> V_15 ;
V_12 = 0 ;
V_12 = F_7 ( V_11 , V_9 , V_10 , V_8 ) ;
V_11 += V_8 ;
V_9 += V_8 ;
V_10 += V_8 ;
V_6 = V_8 ;
if ( V_12 )
{
while ( V_6 < V_7 )
{
V_6 ++ ;
V_13 = * ( V_9 ++ ) ;
if ( ( * ( V_11 ++ ) = ( V_13 + 1 ) & V_16 ) >= V_13 )
{
V_12 = 0 ;
break;
}
}
if ( ( V_6 >= V_7 ) && V_12 )
{
* ( V_11 ++ ) = 1 ;
V_1 -> V_14 ++ ;
}
}
if ( V_11 != V_9 )
{
for (; V_6 < V_7 ; V_6 ++ )
* ( V_11 ++ ) = * ( V_9 ++ ) ;
}
return ( 1 ) ;
}
int F_4 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
int V_7 , V_8 ;
register T_2 V_13 , V_17 , * V_9 , * V_10 , * V_11 ;
int V_6 , V_12 ;
#if F_8 ( V_18 ) && ! F_8 ( V_19 )
int V_20 ;
#endif
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( V_2 -> V_14 < V_3 -> V_14 )
{
F_9 ( V_21 , V_22 ) ;
return ( 0 ) ;
}
V_7 = V_2 -> V_14 ;
V_8 = V_3 -> V_14 ;
if ( F_6 ( V_1 , V_7 ) == NULL ) return ( 0 ) ;
V_9 = V_2 -> V_15 ;
V_10 = V_3 -> V_15 ;
V_11 = V_1 -> V_15 ;
#if 1
V_12 = 0 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
{
V_13 = * ( V_9 ++ ) ;
V_17 = * ( V_10 ++ ) ;
if ( V_12 )
{
V_12 = ( V_13 <= V_17 ) ;
V_13 = ( V_13 - V_17 - 1 ) & V_16 ;
}
else
{
V_12 = ( V_13 < V_17 ) ;
V_13 = ( V_13 - V_17 ) & V_16 ;
}
#if F_8 ( V_18 ) && ! F_8 ( V_19 )
V_20 = V_13 ;
#endif
* ( V_11 ++ ) = V_13 & V_16 ;
}
#else
V_12 = F_10 ( V_11 , V_9 , V_10 , V_8 ) ;
V_9 += V_8 ;
V_10 += V_8 ;
V_11 += V_8 ;
V_6 = V_8 ;
#endif
if ( V_12 )
{
while ( V_6 < V_7 )
{
V_6 ++ ;
V_13 = * ( V_9 ++ ) ;
V_17 = ( V_13 - 1 ) & V_16 ;
* ( V_11 ++ ) = V_17 ;
if ( V_13 > V_17 ) break;
}
}
#if 0
memcpy(rp,ap,sizeof(*rp)*(max-i));
#else
if ( V_11 != V_9 )
{
for (; ; )
{
if ( V_6 ++ >= V_7 ) break;
V_11 [ 0 ] = V_9 [ 0 ] ;
if ( V_6 ++ >= V_7 ) break;
V_11 [ 1 ] = V_9 [ 1 ] ;
if ( V_6 ++ >= V_7 ) break;
V_11 [ 2 ] = V_9 [ 2 ] ;
if ( V_6 ++ >= V_7 ) break;
V_11 [ 3 ] = V_9 [ 3 ] ;
V_11 += 4 ;
V_9 += 4 ;
}
}
#endif
V_1 -> V_14 = V_7 ;
F_11 ( V_1 ) ;
return ( 1 ) ;
}
int F_12 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
int V_7 ;
int V_23 = 0 , V_5 = 0 ;
const T_1 * V_4 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( V_2 -> V_5 )
{
if ( V_3 -> V_5 )
{ V_4 = V_2 ; V_2 = V_3 ; V_3 = V_4 ; }
else
{ V_23 = 1 ; V_5 = 1 ; }
}
else
{
if ( V_3 -> V_5 ) { V_23 = 1 ; V_5 = 0 ; }
}
if ( V_23 )
{
if ( ! F_5 ( V_1 , V_2 , V_3 ) ) return ( 0 ) ;
V_1 -> V_5 = V_5 ;
return ( 1 ) ;
}
V_7 = ( V_2 -> V_14 > V_3 -> V_14 ) ? V_2 -> V_14 : V_3 -> V_14 ;
if ( F_6 ( V_1 , V_7 ) == NULL ) return ( 0 ) ;
if ( F_3 ( V_2 , V_3 ) < 0 )
{
if ( ! F_4 ( V_1 , V_3 , V_2 ) ) return ( 0 ) ;
V_1 -> V_5 = 1 ;
}
else
{
if ( ! F_4 ( V_1 , V_2 , V_3 ) ) return ( 0 ) ;
V_1 -> V_5 = 0 ;
}
return ( 1 ) ;
}
