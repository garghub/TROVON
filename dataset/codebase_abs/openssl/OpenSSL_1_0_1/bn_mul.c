T_1 F_1 ( T_1 * V_1 ,
const T_1 * V_2 , const T_1 * V_3 ,
int V_4 , int V_5 )
{
T_1 V_6 , V_7 ;
assert ( V_4 >= 0 ) ;
V_6 = F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
if ( V_5 == 0 )
return V_6 ;
V_1 += V_4 ;
V_2 += V_4 ;
V_3 += V_4 ;
if ( V_5 < 0 )
{
#ifdef F_3
fprintf ( V_8 , L_1 , V_4 , V_5 , V_6 ) ;
#endif
for (; ; )
{
V_7 = V_3 [ 0 ] ;
V_1 [ 0 ] = ( 0 - V_7 - V_6 ) & V_9 ;
if ( V_7 != 0 ) V_6 = 1 ;
if ( ++ V_5 >= 0 ) break;
V_7 = V_3 [ 1 ] ;
V_1 [ 1 ] = ( 0 - V_7 - V_6 ) & V_9 ;
if ( V_7 != 0 ) V_6 = 1 ;
if ( ++ V_5 >= 0 ) break;
V_7 = V_3 [ 2 ] ;
V_1 [ 2 ] = ( 0 - V_7 - V_6 ) & V_9 ;
if ( V_7 != 0 ) V_6 = 1 ;
if ( ++ V_5 >= 0 ) break;
V_7 = V_3 [ 3 ] ;
V_1 [ 3 ] = ( 0 - V_7 - V_6 ) & V_9 ;
if ( V_7 != 0 ) V_6 = 1 ;
if ( ++ V_5 >= 0 ) break;
V_3 += 4 ;
V_1 += 4 ;
}
}
else
{
int V_10 = V_5 ;
#ifdef F_3
fprintf ( V_8 , L_2 , V_4 , V_5 , V_6 ) ;
#endif
while( V_6 )
{
V_7 = V_2 [ 0 ] ;
V_1 [ 0 ] = ( V_7 - V_6 ) & V_9 ;
if ( V_7 != 0 ) V_6 = 0 ;
if ( -- V_5 <= 0 ) break;
V_7 = V_2 [ 1 ] ;
V_1 [ 1 ] = ( V_7 - V_6 ) & V_9 ;
if ( V_7 != 0 ) V_6 = 0 ;
if ( -- V_5 <= 0 ) break;
V_7 = V_2 [ 2 ] ;
V_1 [ 2 ] = ( V_7 - V_6 ) & V_9 ;
if ( V_7 != 0 ) V_6 = 0 ;
if ( -- V_5 <= 0 ) break;
V_7 = V_2 [ 3 ] ;
V_1 [ 3 ] = ( V_7 - V_6 ) & V_9 ;
if ( V_7 != 0 ) V_6 = 0 ;
if ( -- V_5 <= 0 ) break;
V_10 = V_5 ;
V_2 += 4 ;
V_1 += 4 ;
}
if ( V_5 > 0 )
{
#ifdef F_3
fprintf ( V_8 , L_3 , V_4 , V_5 ) ;
#endif
if ( V_10 > V_5 )
{
switch ( V_10 - V_5 )
{
case 1 :
V_1 [ 1 ] = V_2 [ 1 ] ;
if ( -- V_5 <= 0 ) break;
case 2 :
V_1 [ 2 ] = V_2 [ 2 ] ;
if ( -- V_5 <= 0 ) break;
case 3 :
V_1 [ 3 ] = V_2 [ 3 ] ;
if ( -- V_5 <= 0 ) break;
}
V_2 += 4 ;
V_1 += 4 ;
}
}
if ( V_5 > 0 )
{
#ifdef F_3
fprintf ( V_8 , L_4 , V_4 , V_5 ) ;
#endif
for(; ; )
{
V_1 [ 0 ] = V_2 [ 0 ] ;
if ( -- V_5 <= 0 ) break;
V_1 [ 1 ] = V_2 [ 1 ] ;
if ( -- V_5 <= 0 ) break;
V_1 [ 2 ] = V_2 [ 2 ] ;
if ( -- V_5 <= 0 ) break;
V_1 [ 3 ] = V_2 [ 3 ] ;
if ( -- V_5 <= 0 ) break;
V_2 += 4 ;
V_1 += 4 ;
}
}
}
return V_6 ;
}
T_1 F_4 ( T_1 * V_1 ,
const T_1 * V_2 , const T_1 * V_3 ,
int V_4 , int V_5 )
{
T_1 V_6 , V_11 , V_7 ;
assert ( V_4 >= 0 ) ;
V_6 = F_5 ( V_1 , V_2 , V_3 , V_4 ) ;
if ( V_5 == 0 )
return V_6 ;
V_1 += V_4 ;
V_2 += V_4 ;
V_3 += V_4 ;
if ( V_5 < 0 )
{
int V_10 = V_5 ;
#ifdef F_3
fprintf ( V_8 , L_5 , V_4 , V_5 , V_6 ) ;
#endif
while ( V_6 )
{
V_11 = ( V_6 + V_3 [ 0 ] ) & V_9 ;
V_6 = ( V_11 < V_6 ) ;
V_1 [ 0 ] = V_11 ;
if ( ++ V_5 >= 0 ) break;
V_11 = ( V_6 + V_3 [ 1 ] ) & V_9 ;
V_6 = ( V_11 < V_6 ) ;
V_1 [ 1 ] = V_11 ;
if ( ++ V_5 >= 0 ) break;
V_11 = ( V_6 + V_3 [ 2 ] ) & V_9 ;
V_6 = ( V_11 < V_6 ) ;
V_1 [ 2 ] = V_11 ;
if ( ++ V_5 >= 0 ) break;
V_11 = ( V_6 + V_3 [ 3 ] ) & V_9 ;
V_6 = ( V_11 < V_6 ) ;
V_1 [ 3 ] = V_11 ;
if ( ++ V_5 >= 0 ) break;
V_10 = V_5 ;
V_3 += 4 ;
V_1 += 4 ;
}
if ( V_5 < 0 )
{
#ifdef F_3
fprintf ( V_8 , L_6 , V_4 , V_5 ) ;
#endif
if ( V_10 < V_5 )
{
switch ( V_5 - V_10 )
{
case 1 :
V_1 [ 1 ] = V_3 [ 1 ] ;
if ( ++ V_5 >= 0 ) break;
case 2 :
V_1 [ 2 ] = V_3 [ 2 ] ;
if ( ++ V_5 >= 0 ) break;
case 3 :
V_1 [ 3 ] = V_3 [ 3 ] ;
if ( ++ V_5 >= 0 ) break;
}
V_3 += 4 ;
V_1 += 4 ;
}
}
if ( V_5 < 0 )
{
#ifdef F_3
fprintf ( V_8 , L_7 , V_4 , V_5 ) ;
#endif
for(; ; )
{
V_1 [ 0 ] = V_3 [ 0 ] ;
if ( ++ V_5 >= 0 ) break;
V_1 [ 1 ] = V_3 [ 1 ] ;
if ( ++ V_5 >= 0 ) break;
V_1 [ 2 ] = V_3 [ 2 ] ;
if ( ++ V_5 >= 0 ) break;
V_1 [ 3 ] = V_3 [ 3 ] ;
if ( ++ V_5 >= 0 ) break;
V_3 += 4 ;
V_1 += 4 ;
}
}
}
else
{
int V_10 = V_5 ;
#ifdef F_3
fprintf ( V_8 , L_8 , V_4 , V_5 ) ;
#endif
while ( V_6 )
{
V_7 = ( V_2 [ 0 ] + V_6 ) & V_9 ;
V_6 = ( V_7 < V_6 ) ;
V_1 [ 0 ] = V_7 ;
if ( -- V_5 <= 0 ) break;
V_7 = ( V_2 [ 1 ] + V_6 ) & V_9 ;
V_6 = ( V_7 < V_6 ) ;
V_1 [ 1 ] = V_7 ;
if ( -- V_5 <= 0 ) break;
V_7 = ( V_2 [ 2 ] + V_6 ) & V_9 ;
V_6 = ( V_7 < V_6 ) ;
V_1 [ 2 ] = V_7 ;
if ( -- V_5 <= 0 ) break;
V_7 = ( V_2 [ 3 ] + V_6 ) & V_9 ;
V_6 = ( V_7 < V_6 ) ;
V_1 [ 3 ] = V_7 ;
if ( -- V_5 <= 0 ) break;
V_10 = V_5 ;
V_2 += 4 ;
V_1 += 4 ;
}
#ifdef F_3
fprintf ( V_8 , L_9 , V_4 , V_5 ) ;
#endif
if ( V_5 > 0 )
{
if ( V_10 > V_5 )
{
switch ( V_10 - V_5 )
{
case 1 :
V_1 [ 1 ] = V_2 [ 1 ] ;
if ( -- V_5 <= 0 ) break;
case 2 :
V_1 [ 2 ] = V_2 [ 2 ] ;
if ( -- V_5 <= 0 ) break;
case 3 :
V_1 [ 3 ] = V_2 [ 3 ] ;
if ( -- V_5 <= 0 ) break;
}
V_2 += 4 ;
V_1 += 4 ;
}
}
if ( V_5 > 0 )
{
#ifdef F_3
fprintf ( V_8 , L_10 , V_4 , V_5 ) ;
#endif
for(; ; )
{
V_1 [ 0 ] = V_2 [ 0 ] ;
if ( -- V_5 <= 0 ) break;
V_1 [ 1 ] = V_2 [ 1 ] ;
if ( -- V_5 <= 0 ) break;
V_1 [ 2 ] = V_2 [ 2 ] ;
if ( -- V_5 <= 0 ) break;
V_1 [ 3 ] = V_2 [ 3 ] ;
if ( -- V_5 <= 0 ) break;
V_2 += 4 ;
V_1 += 4 ;
}
}
}
return V_6 ;
}
void F_6 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , int V_12 ,
int V_13 , int V_14 , T_1 * V_7 )
{
int V_15 = V_12 / 2 , V_16 , V_17 ;
int V_18 = V_15 + V_13 , V_19 = V_15 + V_14 ;
unsigned int V_20 , V_21 ;
T_1 V_22 , V_23 , * V_24 ;
# ifdef F_3
fprintf ( V_8 , L_11 , V_12 , V_13 , V_12 , V_14 ) ;
# endif
# ifdef F_7
# if 0
if (n2 == 4)
{
bn_mul_comba4(r,a,b);
return;
}
# endif
if ( V_12 == 8 && V_13 == 0 && V_14 == 0 )
{
F_8 ( V_1 , V_2 , V_3 ) ;
return;
}
# endif
if ( V_12 < V_25 )
{
F_9 ( V_1 , V_2 , V_12 + V_13 , V_3 , V_12 + V_14 ) ;
if ( ( V_13 + V_14 ) < 0 )
memset ( & V_1 [ 2 * V_12 + V_13 + V_14 ] , 0 ,
sizeof( T_1 ) * - ( V_13 + V_14 ) ) ;
return;
}
V_16 = F_10 ( V_2 , & ( V_2 [ V_15 ] ) , V_18 , V_15 - V_18 ) ;
V_17 = F_10 ( & ( V_3 [ V_15 ] ) , V_3 , V_19 , V_19 - V_15 ) ;
V_21 = V_20 = 0 ;
switch ( V_16 * 3 + V_17 )
{
case - 4 :
F_1 ( V_7 , & ( V_2 [ V_15 ] ) , V_2 , V_18 , V_18 - V_15 ) ;
F_1 ( & ( V_7 [ V_15 ] ) , V_3 , & ( V_3 [ V_15 ] ) , V_19 , V_15 - V_19 ) ;
break;
case - 3 :
V_21 = 1 ;
break;
case - 2 :
F_1 ( V_7 , & ( V_2 [ V_15 ] ) , V_2 , V_18 , V_18 - V_15 ) ;
F_1 ( & ( V_7 [ V_15 ] ) , & ( V_3 [ V_15 ] ) , V_3 , V_19 , V_19 - V_15 ) ;
V_20 = 1 ;
break;
case - 1 :
case 0 :
case 1 :
V_21 = 1 ;
break;
case 2 :
F_1 ( V_7 , V_2 , & ( V_2 [ V_15 ] ) , V_18 , V_15 - V_18 ) ;
F_1 ( & ( V_7 [ V_15 ] ) , V_3 , & ( V_3 [ V_15 ] ) , V_19 , V_15 - V_19 ) ;
V_20 = 1 ;
break;
case 3 :
V_21 = 1 ;
break;
case 4 :
F_1 ( V_7 , V_2 , & ( V_2 [ V_15 ] ) , V_18 , V_15 - V_18 ) ;
F_1 ( & ( V_7 [ V_15 ] ) , & ( V_3 [ V_15 ] ) , V_3 , V_19 , V_19 - V_15 ) ;
break;
}
# ifdef F_7
if ( V_15 == 4 && V_13 == 0 && V_14 == 0 )
{
if ( ! V_21 )
F_11 ( & ( V_7 [ V_12 ] ) , V_7 , & ( V_7 [ V_15 ] ) ) ;
else
memset ( & ( V_7 [ V_12 ] ) , 0 , 8 * sizeof( T_1 ) ) ;
F_11 ( V_1 , V_2 , V_3 ) ;
F_11 ( & ( V_1 [ V_12 ] ) , & ( V_2 [ V_15 ] ) , & ( V_3 [ V_15 ] ) ) ;
}
else if ( V_15 == 8 && V_13 == 0 && V_14 == 0 )
{
if ( ! V_21 )
F_8 ( & ( V_7 [ V_12 ] ) , V_7 , & ( V_7 [ V_15 ] ) ) ;
else
memset ( & ( V_7 [ V_12 ] ) , 0 , 16 * sizeof( T_1 ) ) ;
F_8 ( V_1 , V_2 , V_3 ) ;
F_8 ( & ( V_1 [ V_12 ] ) , & ( V_2 [ V_15 ] ) , & ( V_3 [ V_15 ] ) ) ;
}
else
# endif
{
V_24 = & ( V_7 [ V_12 * 2 ] ) ;
if ( ! V_21 )
F_6 ( & ( V_7 [ V_12 ] ) , V_7 , & ( V_7 [ V_15 ] ) , V_15 , 0 , 0 , V_24 ) ;
else
memset ( & ( V_7 [ V_12 ] ) , 0 , V_12 * sizeof( T_1 ) ) ;
F_6 ( V_1 , V_2 , V_3 , V_15 , 0 , 0 , V_24 ) ;
F_6 ( & ( V_1 [ V_12 ] ) , & ( V_2 [ V_15 ] ) , & ( V_3 [ V_15 ] ) , V_15 , V_13 , V_14 , V_24 ) ;
}
V_16 = ( int ) ( F_5 ( V_7 , V_1 , & ( V_1 [ V_12 ] ) , V_12 ) ) ;
if ( V_20 )
{
V_16 -= ( int ) ( F_2 ( & ( V_7 [ V_12 ] ) , V_7 , & ( V_7 [ V_12 ] ) , V_12 ) ) ;
}
else
{
V_16 += ( int ) ( F_5 ( & ( V_7 [ V_12 ] ) , & ( V_7 [ V_12 ] ) , V_7 , V_12 ) ) ;
}
V_16 += ( int ) ( F_5 ( & ( V_1 [ V_15 ] ) , & ( V_1 [ V_15 ] ) , & ( V_7 [ V_12 ] ) , V_12 ) ) ;
if ( V_16 )
{
V_24 = & ( V_1 [ V_15 + V_12 ] ) ;
V_23 = * V_24 ;
V_22 = ( V_23 + V_16 ) & V_9 ;
* V_24 = V_22 ;
if ( V_22 < ( T_1 ) V_16 )
{
do {
V_24 ++ ;
V_23 = * V_24 ;
V_22 = ( V_23 + 1 ) & V_9 ;
* V_24 = V_22 ;
} while ( V_22 == 0 );
}
}
}
void F_12 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , int V_15 ,
int V_18 , int V_19 , T_1 * V_7 )
{
int V_26 , V_27 , V_12 = V_15 * 2 ;
int V_16 , V_17 , V_20 ;
T_1 V_22 , V_23 , * V_24 ;
# ifdef F_3
fprintf ( V_8 , L_12 ,
V_15 , V_18 , V_15 , V_19 ) ;
# endif
if ( V_15 < 8 )
{
F_9 ( V_1 , V_2 , V_15 + V_18 , V_3 , V_15 + V_19 ) ;
return;
}
V_16 = F_10 ( V_2 , & ( V_2 [ V_15 ] ) , V_18 , V_15 - V_18 ) ;
V_17 = F_10 ( & ( V_3 [ V_15 ] ) , V_3 , V_19 , V_19 - V_15 ) ;
V_20 = 0 ;
switch ( V_16 * 3 + V_17 )
{
case - 4 :
F_1 ( V_7 , & ( V_2 [ V_15 ] ) , V_2 , V_18 , V_18 - V_15 ) ;
F_1 ( & ( V_7 [ V_15 ] ) , V_3 , & ( V_3 [ V_15 ] ) , V_19 , V_15 - V_19 ) ;
break;
case - 3 :
case - 2 :
F_1 ( V_7 , & ( V_2 [ V_15 ] ) , V_2 , V_18 , V_18 - V_15 ) ;
F_1 ( & ( V_7 [ V_15 ] ) , & ( V_3 [ V_15 ] ) , V_3 , V_19 , V_19 - V_15 ) ;
V_20 = 1 ;
break;
case - 1 :
case 0 :
case 1 :
case 2 :
F_1 ( V_7 , V_2 , & ( V_2 [ V_15 ] ) , V_18 , V_15 - V_18 ) ;
F_1 ( & ( V_7 [ V_15 ] ) , V_3 , & ( V_3 [ V_15 ] ) , V_19 , V_15 - V_19 ) ;
V_20 = 1 ;
break;
case 3 :
case 4 :
F_1 ( V_7 , V_2 , & ( V_2 [ V_15 ] ) , V_18 , V_15 - V_18 ) ;
F_1 ( & ( V_7 [ V_15 ] ) , & ( V_3 [ V_15 ] ) , V_3 , V_19 , V_19 - V_15 ) ;
break;
}
# if 0
if (n == 4)
{
bn_mul_comba4(&(t[n2]),t,&(t[n]));
bn_mul_comba4(r,a,b);
bn_mul_normal(&(r[n2]),&(a[n]),tn,&(b[n]),tn);
memset(&(r[n2+tn*2]),0,sizeof(BN_ULONG)*(n2-tn*2));
}
else
# endif
if ( V_15 == 8 )
{
F_8 ( & ( V_7 [ V_12 ] ) , V_7 , & ( V_7 [ V_15 ] ) ) ;
F_8 ( V_1 , V_2 , V_3 ) ;
F_9 ( & ( V_1 [ V_12 ] ) , & ( V_2 [ V_15 ] ) , V_18 , & ( V_3 [ V_15 ] ) , V_19 ) ;
memset ( & ( V_1 [ V_12 + V_18 + V_19 ] ) , 0 , sizeof( T_1 ) * ( V_12 - V_18 - V_19 ) ) ;
}
else
{
V_24 = & ( V_7 [ V_12 * 2 ] ) ;
F_6 ( & ( V_7 [ V_12 ] ) , V_7 , & ( V_7 [ V_15 ] ) , V_15 , 0 , 0 , V_24 ) ;
F_6 ( V_1 , V_2 , V_3 , V_15 , 0 , 0 , V_24 ) ;
V_26 = V_15 / 2 ;
if ( V_18 > V_19 )
V_27 = V_18 - V_26 ;
else
V_27 = V_19 - V_26 ;
if ( V_27 == 0 )
{
F_6 ( & ( V_1 [ V_12 ] ) , & ( V_2 [ V_15 ] ) , & ( V_3 [ V_15 ] ) ,
V_26 , V_18 - V_26 , V_19 - V_26 , V_24 ) ;
memset ( & ( V_1 [ V_12 + V_26 * 2 ] ) , 0 , sizeof( T_1 ) * ( V_12 - V_26 * 2 ) ) ;
}
else if ( V_27 > 0 )
{
F_12 ( & ( V_1 [ V_12 ] ) , & ( V_2 [ V_15 ] ) , & ( V_3 [ V_15 ] ) ,
V_26 , V_18 - V_26 , V_19 - V_26 , V_24 ) ;
memset ( & ( V_1 [ V_12 + V_18 + V_19 ] ) , 0 ,
sizeof( T_1 ) * ( V_12 - V_18 - V_19 ) ) ;
}
else
{
memset ( & ( V_1 [ V_12 ] ) , 0 , sizeof( T_1 ) * V_12 ) ;
if ( V_18 < V_25
&& V_19 < V_25 )
{
F_9 ( & ( V_1 [ V_12 ] ) , & ( V_2 [ V_15 ] ) , V_18 , & ( V_3 [ V_15 ] ) , V_19 ) ;
}
else
{
for (; ; )
{
V_26 /= 2 ;
if ( V_26 < V_18 || V_26 < V_19 )
{
F_12 ( & ( V_1 [ V_12 ] ) ,
& ( V_2 [ V_15 ] ) , & ( V_3 [ V_15 ] ) ,
V_26 , V_18 - V_26 , V_19 - V_26 , V_24 ) ;
break;
}
else if ( V_26 == V_18 || V_26 == V_19 )
{
F_6 ( & ( V_1 [ V_12 ] ) ,
& ( V_2 [ V_15 ] ) , & ( V_3 [ V_15 ] ) ,
V_26 , V_18 - V_26 , V_19 - V_26 , V_24 ) ;
break;
}
}
}
}
}
V_16 = ( int ) ( F_5 ( V_7 , V_1 , & ( V_1 [ V_12 ] ) , V_12 ) ) ;
if ( V_20 )
{
V_16 -= ( int ) ( F_2 ( & ( V_7 [ V_12 ] ) , V_7 , & ( V_7 [ V_12 ] ) , V_12 ) ) ;
}
else
{
V_16 += ( int ) ( F_5 ( & ( V_7 [ V_12 ] ) , & ( V_7 [ V_12 ] ) , V_7 , V_12 ) ) ;
}
V_16 += ( int ) ( F_5 ( & ( V_1 [ V_15 ] ) , & ( V_1 [ V_15 ] ) , & ( V_7 [ V_12 ] ) , V_12 ) ) ;
if ( V_16 )
{
V_24 = & ( V_1 [ V_15 + V_12 ] ) ;
V_23 = * V_24 ;
V_22 = ( V_23 + V_16 ) & V_9 ;
* V_24 = V_22 ;
if ( V_22 < ( T_1 ) V_16 )
{
do {
V_24 ++ ;
V_23 = * V_24 ;
V_22 = ( V_23 + 1 ) & V_9 ;
* V_24 = V_22 ;
} while ( V_22 == 0 );
}
}
}
void F_13 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , int V_12 ,
T_1 * V_7 )
{
int V_15 = V_12 / 2 ;
# ifdef F_3
fprintf ( V_8 , L_13 , V_12 , V_12 ) ;
# endif
F_6 ( V_1 , V_2 , V_3 , V_15 , 0 , 0 , & ( V_7 [ 0 ] ) ) ;
if ( V_15 >= V_28 )
{
F_13 ( & ( V_7 [ 0 ] ) , & ( V_2 [ 0 ] ) , & ( V_3 [ V_15 ] ) , V_15 , & ( V_7 [ V_12 ] ) ) ;
F_5 ( & ( V_1 [ V_15 ] ) , & ( V_1 [ V_15 ] ) , & ( V_7 [ 0 ] ) , V_15 ) ;
F_13 ( & ( V_7 [ 0 ] ) , & ( V_2 [ V_15 ] ) , & ( V_3 [ 0 ] ) , V_15 , & ( V_7 [ V_12 ] ) ) ;
F_5 ( & ( V_1 [ V_15 ] ) , & ( V_1 [ V_15 ] ) , & ( V_7 [ 0 ] ) , V_15 ) ;
}
else
{
F_14 ( & ( V_7 [ 0 ] ) , & ( V_2 [ 0 ] ) , & ( V_3 [ V_15 ] ) , V_15 ) ;
F_14 ( & ( V_7 [ V_15 ] ) , & ( V_2 [ V_15 ] ) , & ( V_3 [ 0 ] ) , V_15 ) ;
F_5 ( & ( V_1 [ V_15 ] ) , & ( V_1 [ V_15 ] ) , & ( V_7 [ 0 ] ) , V_15 ) ;
F_5 ( & ( V_1 [ V_15 ] ) , & ( V_1 [ V_15 ] ) , & ( V_7 [ V_15 ] ) , V_15 ) ;
}
}
void F_15 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , T_1 * V_11 , int V_12 ,
T_1 * V_7 )
{
int V_26 , V_15 ;
int V_16 , V_17 ;
int V_20 , V_29 , V_21 ;
T_1 V_30 , V_31 , * V_32 , * V_33 ;
# ifdef F_3
fprintf ( V_8 , L_14 , V_12 , V_12 ) ;
# endif
V_15 = V_12 / 2 ;
V_20 = V_21 = 0 ;
V_16 = F_16 ( & ( V_2 [ 0 ] ) , & ( V_2 [ V_15 ] ) , V_15 ) ;
V_17 = F_16 ( & ( V_3 [ V_15 ] ) , & ( V_3 [ 0 ] ) , V_15 ) ;
switch ( V_16 * 3 + V_17 )
{
case - 4 :
F_2 ( & ( V_1 [ 0 ] ) , & ( V_2 [ V_15 ] ) , & ( V_2 [ 0 ] ) , V_15 ) ;
F_2 ( & ( V_1 [ V_15 ] ) , & ( V_3 [ 0 ] ) , & ( V_3 [ V_15 ] ) , V_15 ) ;
break;
case - 3 :
V_21 = 1 ;
break;
case - 2 :
F_2 ( & ( V_1 [ 0 ] ) , & ( V_2 [ V_15 ] ) , & ( V_2 [ 0 ] ) , V_15 ) ;
F_2 ( & ( V_1 [ V_15 ] ) , & ( V_3 [ V_15 ] ) , & ( V_3 [ 0 ] ) , V_15 ) ;
V_20 = 1 ;
break;
case - 1 :
case 0 :
case 1 :
V_21 = 1 ;
break;
case 2 :
F_2 ( & ( V_1 [ 0 ] ) , & ( V_2 [ 0 ] ) , & ( V_2 [ V_15 ] ) , V_15 ) ;
F_2 ( & ( V_1 [ V_15 ] ) , & ( V_3 [ 0 ] ) , & ( V_3 [ V_15 ] ) , V_15 ) ;
V_20 = 1 ;
break;
case 3 :
V_21 = 1 ;
break;
case 4 :
F_2 ( & ( V_1 [ 0 ] ) , & ( V_2 [ 0 ] ) , & ( V_2 [ V_15 ] ) , V_15 ) ;
F_2 ( & ( V_1 [ V_15 ] ) , & ( V_3 [ V_15 ] ) , & ( V_3 [ 0 ] ) , V_15 ) ;
break;
}
V_29 = V_20 ;
# ifdef F_7
if ( V_15 == 8 )
{
F_8 ( & ( V_7 [ 0 ] ) , & ( V_1 [ 0 ] ) , & ( V_1 [ V_15 ] ) ) ;
F_8 ( V_1 , & ( V_2 [ V_15 ] ) , & ( V_3 [ V_15 ] ) ) ;
}
else
# endif
{
F_6 ( & ( V_7 [ 0 ] ) , & ( V_1 [ 0 ] ) , & ( V_1 [ V_15 ] ) , V_15 , 0 , 0 , & ( V_7 [ V_12 ] ) ) ;
F_6 ( V_1 , & ( V_2 [ V_15 ] ) , & ( V_3 [ V_15 ] ) , V_15 , 0 , 0 , & ( V_7 [ V_12 ] ) ) ;
}
if ( V_11 != NULL )
{
V_32 = & ( V_7 [ V_12 + V_15 ] ) ;
V_16 = ( int ) ( F_5 ( V_32 , & ( V_1 [ 0 ] ) , & ( V_11 [ 0 ] ) , V_15 ) ) ;
}
else
{
V_16 = 0 ;
V_32 = & ( V_1 [ 0 ] ) ;
}
if ( V_20 )
V_20 = ( int ) ( F_2 ( & ( V_7 [ V_12 ] ) , V_32 , & ( V_7 [ 0 ] ) , V_15 ) ) ;
else
{
F_5 ( & ( V_7 [ V_12 ] ) , V_32 , & ( V_7 [ 0 ] ) , V_15 ) ;
V_20 = 0 ;
}
if ( V_11 != NULL )
{
F_2 ( & ( V_7 [ V_12 + V_15 ] ) , & ( V_11 [ V_15 ] ) , & ( V_7 [ V_12 ] ) , V_15 ) ;
}
else
{
V_32 = & ( V_7 [ V_12 + V_15 ] ) ;
V_33 = & ( V_7 [ V_12 ] ) ;
for ( V_26 = 0 ; V_26 < V_15 ; V_26 ++ )
V_32 [ V_26 ] = ( ( ~ V_33 [ V_26 ] ) + 1 ) & V_9 ;
}
if ( V_11 != NULL )
{
V_32 = & ( V_7 [ V_12 ] ) ;
V_16 = ( int ) ( F_5 ( V_32 , & ( V_7 [ V_12 + V_15 ] ) , & ( V_11 [ 0 ] ) , V_15 ) ) ;
}
else
{
V_32 = & ( V_7 [ V_12 + V_15 ] ) ;
V_16 = 0 ;
}
V_16 += ( int ) ( F_5 ( & ( V_7 [ V_12 ] ) , V_32 , & ( V_1 [ 0 ] ) , V_15 ) ) ;
if ( V_29 )
V_16 -= ( int ) ( F_2 ( & ( V_7 [ V_12 ] ) , & ( V_7 [ V_12 ] ) , & ( V_7 [ 0 ] ) , V_15 ) ) ;
else
V_16 += ( int ) ( F_5 ( & ( V_7 [ V_12 ] ) , & ( V_7 [ V_12 ] ) , & ( V_7 [ 0 ] ) , V_15 ) ) ;
V_17 = ( int ) ( F_5 ( & ( V_1 [ 0 ] ) , & ( V_1 [ 0 ] ) , & ( V_7 [ V_12 + V_15 ] ) , V_15 ) ) ;
V_17 += ( int ) ( F_5 ( & ( V_1 [ 0 ] ) , & ( V_1 [ 0 ] ) , & ( V_1 [ V_15 ] ) , V_15 ) ) ;
if ( V_29 )
V_17 -= ( int ) ( F_2 ( & ( V_1 [ 0 ] ) , & ( V_1 [ 0 ] ) , & ( V_7 [ V_15 ] ) , V_15 ) ) ;
else
V_17 += ( int ) ( F_5 ( & ( V_1 [ 0 ] ) , & ( V_1 [ 0 ] ) , & ( V_7 [ V_15 ] ) , V_15 ) ) ;
if ( V_16 != 0 )
{
V_26 = 0 ;
if ( V_16 > 0 )
{
V_31 = V_16 ;
do {
V_30 = ( V_1 [ V_26 ] + V_31 ) & V_9 ;
V_1 [ V_26 ++ ] = V_30 ;
V_31 = ( V_31 > V_30 ) ;
} while ( V_31 );
}
else
{
V_31 = - V_16 ;
do {
V_30 = V_1 [ V_26 ] ;
V_1 [ V_26 ++ ] = ( V_30 - V_31 ) & V_9 ;
V_31 = ( V_31 > V_30 ) ;
} while ( V_31 );
}
}
if ( V_17 != 0 )
{
V_26 = V_15 ;
if ( V_17 > 0 )
{
V_31 = V_17 ;
do {
V_30 = ( V_1 [ V_26 ] + V_31 ) & V_9 ;
V_1 [ V_26 ++ ] = V_30 ;
V_31 = ( V_31 > V_30 ) ;
} while ( V_31 );
}
else
{
V_31 = - V_17 ;
do {
V_30 = V_1 [ V_26 ] ;
V_1 [ V_26 ++ ] = ( V_30 - V_31 ) & V_9 ;
V_31 = ( V_31 > V_30 ) ;
} while ( V_31 );
}
}
}
int F_17 ( T_2 * V_1 , const T_2 * V_2 , const T_2 * V_3 , T_3 * V_34 )
{
int V_35 = 0 ;
int V_36 , V_37 , V_38 ;
T_2 * V_39 ;
#if F_18 ( F_7 ) || F_18 ( V_40 )
int V_26 ;
#endif
#ifdef V_40
T_2 * V_7 = NULL ;
int V_27 = 0 , V_41 ;
#endif
#ifdef F_3
fprintf ( V_8 , L_15 , V_2 -> V_36 , V_3 -> V_36 ) ;
#endif
F_19 ( V_2 ) ;
F_19 ( V_3 ) ;
F_19 ( V_1 ) ;
V_37 = V_2 -> V_36 ;
V_38 = V_3 -> V_36 ;
if ( ( V_37 == 0 ) || ( V_38 == 0 ) )
{
F_20 ( V_1 ) ;
return ( 1 ) ;
}
V_36 = V_37 + V_38 ;
F_21 ( V_34 ) ;
if ( ( V_1 == V_2 ) || ( V_1 == V_3 ) )
{
if ( ( V_39 = F_22 ( V_34 ) ) == NULL ) goto V_42;
}
else
V_39 = V_1 ;
V_39 -> V_20 = V_2 -> V_20 ^ V_3 -> V_20 ;
#if F_18 ( F_7 ) || F_18 ( V_40 )
V_26 = V_37 - V_38 ;
#endif
#ifdef F_7
if ( V_26 == 0 )
{
# if 0
if (al == 4)
{
if (bn_wexpand(rr,8) == NULL) goto err;
rr->top=8;
bn_mul_comba4(rr->d,a->d,b->d);
goto end;
}
# endif
if ( V_37 == 8 )
{
if ( F_23 ( V_39 , 16 ) == NULL ) goto V_42;
V_39 -> V_36 = 16 ;
F_8 ( V_39 -> V_43 , V_2 -> V_43 , V_3 -> V_43 ) ;
goto V_44;
}
}
#endif
#ifdef V_40
if ( ( V_37 >= V_45 ) && ( V_38 >= V_45 ) )
{
if ( V_26 >= - 1 && V_26 <= 1 )
{
if ( V_26 >= 0 )
{
V_27 = F_24 ( ( T_1 ) V_37 ) ;
}
if ( V_26 == - 1 )
{
V_27 = F_24 ( ( T_1 ) V_38 ) ;
}
V_27 = 1 << ( V_27 - 1 ) ;
assert ( V_27 <= V_37 || V_27 <= V_38 ) ;
V_41 = V_27 + V_27 ;
V_7 = F_22 ( V_34 ) ;
if ( V_7 == NULL )
goto V_42;
if ( V_37 > V_27 || V_38 > V_27 )
{
if ( F_23 ( V_7 , V_41 * 4 ) == NULL ) goto V_42;
if ( F_23 ( V_39 , V_41 * 4 ) == NULL ) goto V_42;
F_12 ( V_39 -> V_43 , V_2 -> V_43 , V_3 -> V_43 ,
V_27 , V_37 - V_27 , V_38 - V_27 , V_7 -> V_43 ) ;
}
else
{
if ( F_23 ( V_7 , V_41 * 2 ) == NULL ) goto V_42;
if ( F_23 ( V_39 , V_41 * 2 ) == NULL ) goto V_42;
F_6 ( V_39 -> V_43 , V_2 -> V_43 , V_3 -> V_43 ,
V_27 , V_37 - V_27 , V_38 - V_27 , V_7 -> V_43 ) ;
}
V_39 -> V_36 = V_36 ;
goto V_44;
}
#if 0
if (i == 1 && !BN_get_flags(b,BN_FLG_STATIC_DATA))
{
BIGNUM *tmp_bn = (BIGNUM *)b;
if (bn_wexpand(tmp_bn,al) == NULL) goto err;
tmp_bn->d[bl]=0;
bl++;
i--;
}
else if (i == -1 && !BN_get_flags(a,BN_FLG_STATIC_DATA))
{
BIGNUM *tmp_bn = (BIGNUM *)a;
if (bn_wexpand(tmp_bn,bl) == NULL) goto err;
tmp_bn->d[al]=0;
al++;
i++;
}
if (i == 0)
{
j=BN_num_bits_word((BN_ULONG)al);
j=1<<(j-1);
k=j+j;
t = BN_CTX_get(ctx);
if (al == j)
{
if (bn_wexpand(t,k*2) == NULL) goto err;
if (bn_wexpand(rr,k*2) == NULL) goto err;
bn_mul_recursive(rr->d,a->d,b->d,al,t->d);
}
else
{
if (bn_wexpand(t,k*4) == NULL) goto err;
if (bn_wexpand(rr,k*4) == NULL) goto err;
bn_mul_part_recursive(rr->d,a->d,b->d,al-j,j,t->d);
}
rr->top=top;
goto end;
}
#endif
}
#endif
if ( F_23 ( V_39 , V_36 ) == NULL ) goto V_42;
V_39 -> V_36 = V_36 ;
F_9 ( V_39 -> V_43 , V_2 -> V_43 , V_37 , V_3 -> V_43 , V_38 ) ;
#if F_18 ( F_7 ) || F_18 ( V_40 )
V_44:
#endif
F_25 ( V_39 ) ;
if ( V_1 != V_39 ) F_26 ( V_1 , V_39 ) ;
V_35 = 1 ;
V_42:
F_19 ( V_1 ) ;
F_27 ( V_34 ) ;
return ( V_35 ) ;
}
void F_9 ( T_1 * V_1 , T_1 * V_2 , int V_46 , T_1 * V_3 , int V_47 )
{
T_1 * V_39 ;
#ifdef F_3
fprintf ( V_8 , L_16 , V_46 , V_47 ) ;
#endif
if ( V_46 < V_47 )
{
int V_48 ;
T_1 * V_49 ;
V_48 = V_46 ; V_46 = V_47 ; V_47 = V_48 ;
V_49 = V_2 ; V_2 = V_3 ; V_3 = V_49 ;
}
V_39 = & ( V_1 [ V_46 ] ) ;
if ( V_47 <= 0 )
{
( void ) F_28 ( V_1 , V_2 , V_46 , 0 ) ;
return;
}
else
V_39 [ 0 ] = F_28 ( V_1 , V_2 , V_46 , V_3 [ 0 ] ) ;
for (; ; )
{
if ( -- V_47 <= 0 ) return;
V_39 [ 1 ] = F_29 ( & ( V_1 [ 1 ] ) , V_2 , V_46 , V_3 [ 1 ] ) ;
if ( -- V_47 <= 0 ) return;
V_39 [ 2 ] = F_29 ( & ( V_1 [ 2 ] ) , V_2 , V_46 , V_3 [ 2 ] ) ;
if ( -- V_47 <= 0 ) return;
V_39 [ 3 ] = F_29 ( & ( V_1 [ 3 ] ) , V_2 , V_46 , V_3 [ 3 ] ) ;
if ( -- V_47 <= 0 ) return;
V_39 [ 4 ] = F_29 ( & ( V_1 [ 4 ] ) , V_2 , V_46 , V_3 [ 4 ] ) ;
V_39 += 4 ;
V_1 += 4 ;
V_3 += 4 ;
}
}
void F_14 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , int V_15 )
{
#ifdef F_3
fprintf ( V_8 , L_17 , V_15 , V_15 ) ;
#endif
F_28 ( V_1 , V_2 , V_15 , V_3 [ 0 ] ) ;
for (; ; )
{
if ( -- V_15 <= 0 ) return;
F_29 ( & ( V_1 [ 1 ] ) , V_2 , V_15 , V_3 [ 1 ] ) ;
if ( -- V_15 <= 0 ) return;
F_29 ( & ( V_1 [ 2 ] ) , V_2 , V_15 , V_3 [ 2 ] ) ;
if ( -- V_15 <= 0 ) return;
F_29 ( & ( V_1 [ 3 ] ) , V_2 , V_15 , V_3 [ 3 ] ) ;
if ( -- V_15 <= 0 ) return;
F_29 ( & ( V_1 [ 4 ] ) , V_2 , V_15 , V_3 [ 4 ] ) ;
V_1 += 4 ;
V_3 += 4 ;
}
}
