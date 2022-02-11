int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
const T_1 * V_4 ;
int V_5 = V_2 -> V_6 , V_7 ;
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
V_7 = F_5 ( V_1 , V_2 , V_3 ) ;
V_1 -> V_6 = V_5 ;
F_2 ( V_1 ) ;
return V_7 ;
}
int F_5 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
int V_8 , V_9 , V_10 ;
T_2 * V_11 , * V_12 , * V_13 , V_14 , V_15 , V_16 ;
const T_1 * V_4 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( V_2 -> V_17 < V_3 -> V_17 )
{ V_4 = V_2 ; V_2 = V_3 ; V_3 = V_4 ; }
V_8 = V_2 -> V_17 ;
V_9 = V_3 -> V_17 ;
V_10 = V_8 - V_9 ;
if ( F_6 ( V_1 , V_8 + 1 ) == NULL )
return 0 ;
V_1 -> V_17 = V_8 ;
V_11 = V_2 -> V_18 ;
V_12 = V_3 -> V_18 ;
V_13 = V_1 -> V_18 ;
V_14 = F_7 ( V_13 , V_11 , V_12 , V_9 ) ;
V_13 += V_9 ;
V_11 += V_9 ;
V_12 += V_9 ;
if ( V_14 )
{
while ( V_10 )
{
V_10 -- ;
V_15 = * ( V_11 ++ ) ;
V_16 = ( V_15 + 1 ) & V_19 ;
* ( V_13 ++ ) = V_16 ;
if ( V_16 )
{
V_14 = 0 ;
break;
}
}
if ( V_14 )
{
* V_13 = 1 ;
V_1 -> V_17 ++ ;
}
}
if ( V_10 && V_13 != V_11 )
while ( V_10 -- )
* ( V_13 ++ ) = * ( V_11 ++ ) ;
V_1 -> V_6 = 0 ;
F_2 ( V_1 ) ;
return 1 ;
}
int F_4 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
int V_8 , V_9 , V_10 ;
register T_2 V_15 , V_16 , * V_11 , * V_12 , * V_13 ;
int V_20 , V_14 ;
#if F_8 ( V_21 ) && ! F_8 ( V_22 )
int V_23 ;
#endif
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
V_8 = V_2 -> V_17 ;
V_9 = V_3 -> V_17 ;
V_10 = V_8 - V_9 ;
if ( V_10 < 0 )
{
F_9 ( V_24 , V_25 ) ;
return ( 0 ) ;
}
if ( F_6 ( V_1 , V_8 ) == NULL ) return ( 0 ) ;
V_11 = V_2 -> V_18 ;
V_12 = V_3 -> V_18 ;
V_13 = V_1 -> V_18 ;
#if 1
V_14 = 0 ;
for ( V_20 = V_9 ; V_20 != 0 ; V_20 -- )
{
V_15 = * ( V_11 ++ ) ;
V_16 = * ( V_12 ++ ) ;
if ( V_14 )
{
V_14 = ( V_15 <= V_16 ) ;
V_15 = ( V_15 - V_16 - 1 ) & V_19 ;
}
else
{
V_14 = ( V_15 < V_16 ) ;
V_15 = ( V_15 - V_16 ) & V_19 ;
}
#if F_8 ( V_21 ) && ! F_8 ( V_22 )
V_23 = V_15 ;
#endif
* ( V_13 ++ ) = V_15 & V_19 ;
}
#else
V_14 = F_10 ( V_13 , V_11 , V_12 , V_9 ) ;
V_11 += V_9 ;
V_12 += V_9 ;
V_13 += V_9 ;
#endif
if ( V_14 )
{
if ( ! V_10 )
return 0 ;
while ( V_10 )
{
V_10 -- ;
V_15 = * ( V_11 ++ ) ;
V_16 = ( V_15 - 1 ) & V_19 ;
* ( V_13 ++ ) = V_16 ;
if ( V_15 )
break;
}
}
#if 0
memcpy(rp,ap,sizeof(*rp)*(max-i));
#else
if ( V_13 != V_11 )
{
for (; ; )
{
if ( ! V_10 -- ) break;
V_13 [ 0 ] = V_11 [ 0 ] ;
if ( ! V_10 -- ) break;
V_13 [ 1 ] = V_11 [ 1 ] ;
if ( ! V_10 -- ) break;
V_13 [ 2 ] = V_11 [ 2 ] ;
if ( ! V_10 -- ) break;
V_13 [ 3 ] = V_11 [ 3 ] ;
V_13 += 4 ;
V_11 += 4 ;
}
}
#endif
V_1 -> V_17 = V_8 ;
V_1 -> V_6 = 0 ;
F_11 ( V_1 ) ;
return ( 1 ) ;
}
int F_12 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 )
{
int V_8 ;
int V_26 = 0 , V_6 = 0 ;
const T_1 * V_4 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
if ( V_2 -> V_6 )
{
if ( V_3 -> V_6 )
{ V_4 = V_2 ; V_2 = V_3 ; V_3 = V_4 ; }
else
{ V_26 = 1 ; V_6 = 1 ; }
}
else
{
if ( V_3 -> V_6 ) { V_26 = 1 ; V_6 = 0 ; }
}
if ( V_26 )
{
if ( ! F_5 ( V_1 , V_2 , V_3 ) ) return ( 0 ) ;
V_1 -> V_6 = V_6 ;
return ( 1 ) ;
}
V_8 = ( V_2 -> V_17 > V_3 -> V_17 ) ? V_2 -> V_17 : V_3 -> V_17 ;
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
F_2 ( V_1 ) ;
return ( 1 ) ;
}
