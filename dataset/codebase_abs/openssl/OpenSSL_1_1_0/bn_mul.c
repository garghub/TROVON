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
if ( V_5 < 0 ) {
for (; ; ) {
V_7 = V_3 [ 0 ] ;
V_1 [ 0 ] = ( 0 - V_7 - V_6 ) & V_8 ;
if ( V_7 != 0 )
V_6 = 1 ;
if ( ++ V_5 >= 0 )
break;
V_7 = V_3 [ 1 ] ;
V_1 [ 1 ] = ( 0 - V_7 - V_6 ) & V_8 ;
if ( V_7 != 0 )
V_6 = 1 ;
if ( ++ V_5 >= 0 )
break;
V_7 = V_3 [ 2 ] ;
V_1 [ 2 ] = ( 0 - V_7 - V_6 ) & V_8 ;
if ( V_7 != 0 )
V_6 = 1 ;
if ( ++ V_5 >= 0 )
break;
V_7 = V_3 [ 3 ] ;
V_1 [ 3 ] = ( 0 - V_7 - V_6 ) & V_8 ;
if ( V_7 != 0 )
V_6 = 1 ;
if ( ++ V_5 >= 0 )
break;
V_3 += 4 ;
V_1 += 4 ;
}
} else {
int V_9 = V_5 ;
while ( V_6 ) {
V_7 = V_2 [ 0 ] ;
V_1 [ 0 ] = ( V_7 - V_6 ) & V_8 ;
if ( V_7 != 0 )
V_6 = 0 ;
if ( -- V_5 <= 0 )
break;
V_7 = V_2 [ 1 ] ;
V_1 [ 1 ] = ( V_7 - V_6 ) & V_8 ;
if ( V_7 != 0 )
V_6 = 0 ;
if ( -- V_5 <= 0 )
break;
V_7 = V_2 [ 2 ] ;
V_1 [ 2 ] = ( V_7 - V_6 ) & V_8 ;
if ( V_7 != 0 )
V_6 = 0 ;
if ( -- V_5 <= 0 )
break;
V_7 = V_2 [ 3 ] ;
V_1 [ 3 ] = ( V_7 - V_6 ) & V_8 ;
if ( V_7 != 0 )
V_6 = 0 ;
if ( -- V_5 <= 0 )
break;
V_9 = V_5 ;
V_2 += 4 ;
V_1 += 4 ;
}
if ( V_5 > 0 ) {
if ( V_9 > V_5 ) {
switch ( V_9 - V_5 ) {
case 1 :
V_1 [ 1 ] = V_2 [ 1 ] ;
if ( -- V_5 <= 0 )
break;
case 2 :
V_1 [ 2 ] = V_2 [ 2 ] ;
if ( -- V_5 <= 0 )
break;
case 3 :
V_1 [ 3 ] = V_2 [ 3 ] ;
if ( -- V_5 <= 0 )
break;
}
V_2 += 4 ;
V_1 += 4 ;
}
}
if ( V_5 > 0 ) {
for (; ; ) {
V_1 [ 0 ] = V_2 [ 0 ] ;
if ( -- V_5 <= 0 )
break;
V_1 [ 1 ] = V_2 [ 1 ] ;
if ( -- V_5 <= 0 )
break;
V_1 [ 2 ] = V_2 [ 2 ] ;
if ( -- V_5 <= 0 )
break;
V_1 [ 3 ] = V_2 [ 3 ] ;
if ( -- V_5 <= 0 )
break;
V_2 += 4 ;
V_1 += 4 ;
}
}
}
return V_6 ;
}
T_1 F_3 ( T_1 * V_1 ,
const T_1 * V_2 , const T_1 * V_3 ,
int V_4 , int V_5 )
{
T_1 V_6 , V_10 , V_7 ;
assert ( V_4 >= 0 ) ;
V_6 = F_4 ( V_1 , V_2 , V_3 , V_4 ) ;
if ( V_5 == 0 )
return V_6 ;
V_1 += V_4 ;
V_2 += V_4 ;
V_3 += V_4 ;
if ( V_5 < 0 ) {
int V_9 = V_5 ;
while ( V_6 ) {
V_10 = ( V_6 + V_3 [ 0 ] ) & V_8 ;
V_6 = ( V_10 < V_6 ) ;
V_1 [ 0 ] = V_10 ;
if ( ++ V_5 >= 0 )
break;
V_10 = ( V_6 + V_3 [ 1 ] ) & V_8 ;
V_6 = ( V_10 < V_6 ) ;
V_1 [ 1 ] = V_10 ;
if ( ++ V_5 >= 0 )
break;
V_10 = ( V_6 + V_3 [ 2 ] ) & V_8 ;
V_6 = ( V_10 < V_6 ) ;
V_1 [ 2 ] = V_10 ;
if ( ++ V_5 >= 0 )
break;
V_10 = ( V_6 + V_3 [ 3 ] ) & V_8 ;
V_6 = ( V_10 < V_6 ) ;
V_1 [ 3 ] = V_10 ;
if ( ++ V_5 >= 0 )
break;
V_9 = V_5 ;
V_3 += 4 ;
V_1 += 4 ;
}
if ( V_5 < 0 ) {
if ( V_9 < V_5 ) {
switch ( V_5 - V_9 ) {
case 1 :
V_1 [ 1 ] = V_3 [ 1 ] ;
if ( ++ V_5 >= 0 )
break;
case 2 :
V_1 [ 2 ] = V_3 [ 2 ] ;
if ( ++ V_5 >= 0 )
break;
case 3 :
V_1 [ 3 ] = V_3 [ 3 ] ;
if ( ++ V_5 >= 0 )
break;
}
V_3 += 4 ;
V_1 += 4 ;
}
}
if ( V_5 < 0 ) {
for (; ; ) {
V_1 [ 0 ] = V_3 [ 0 ] ;
if ( ++ V_5 >= 0 )
break;
V_1 [ 1 ] = V_3 [ 1 ] ;
if ( ++ V_5 >= 0 )
break;
V_1 [ 2 ] = V_3 [ 2 ] ;
if ( ++ V_5 >= 0 )
break;
V_1 [ 3 ] = V_3 [ 3 ] ;
if ( ++ V_5 >= 0 )
break;
V_3 += 4 ;
V_1 += 4 ;
}
}
} else {
int V_9 = V_5 ;
while ( V_6 ) {
V_7 = ( V_2 [ 0 ] + V_6 ) & V_8 ;
V_6 = ( V_7 < V_6 ) ;
V_1 [ 0 ] = V_7 ;
if ( -- V_5 <= 0 )
break;
V_7 = ( V_2 [ 1 ] + V_6 ) & V_8 ;
V_6 = ( V_7 < V_6 ) ;
V_1 [ 1 ] = V_7 ;
if ( -- V_5 <= 0 )
break;
V_7 = ( V_2 [ 2 ] + V_6 ) & V_8 ;
V_6 = ( V_7 < V_6 ) ;
V_1 [ 2 ] = V_7 ;
if ( -- V_5 <= 0 )
break;
V_7 = ( V_2 [ 3 ] + V_6 ) & V_8 ;
V_6 = ( V_7 < V_6 ) ;
V_1 [ 3 ] = V_7 ;
if ( -- V_5 <= 0 )
break;
V_9 = V_5 ;
V_2 += 4 ;
V_1 += 4 ;
}
if ( V_5 > 0 ) {
if ( V_9 > V_5 ) {
switch ( V_9 - V_5 ) {
case 1 :
V_1 [ 1 ] = V_2 [ 1 ] ;
if ( -- V_5 <= 0 )
break;
case 2 :
V_1 [ 2 ] = V_2 [ 2 ] ;
if ( -- V_5 <= 0 )
break;
case 3 :
V_1 [ 3 ] = V_2 [ 3 ] ;
if ( -- V_5 <= 0 )
break;
}
V_2 += 4 ;
V_1 += 4 ;
}
}
if ( V_5 > 0 ) {
for (; ; ) {
V_1 [ 0 ] = V_2 [ 0 ] ;
if ( -- V_5 <= 0 )
break;
V_1 [ 1 ] = V_2 [ 1 ] ;
if ( -- V_5 <= 0 )
break;
V_1 [ 2 ] = V_2 [ 2 ] ;
if ( -- V_5 <= 0 )
break;
V_1 [ 3 ] = V_2 [ 3 ] ;
if ( -- V_5 <= 0 )
break;
V_2 += 4 ;
V_1 += 4 ;
}
}
}
return V_6 ;
}
void F_5 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , int V_11 ,
int V_12 , int V_13 , T_1 * V_7 )
{
int V_14 = V_11 / 2 , V_15 , V_16 ;
int V_17 = V_14 + V_12 , V_18 = V_14 + V_13 ;
unsigned int V_19 , V_20 ;
T_1 V_21 , V_22 , * V_23 ;
# ifdef F_6
# if 0
if (n2 == 4) {
bn_mul_comba4(r, a, b);
return;
}
# endif
if ( V_11 == 8 && V_12 == 0 && V_13 == 0 ) {
F_7 ( V_1 , V_2 , V_3 ) ;
return;
}
# endif
if ( V_11 < V_24 ) {
F_8 ( V_1 , V_2 , V_11 + V_12 , V_3 , V_11 + V_13 ) ;
if ( ( V_12 + V_13 ) < 0 )
memset ( & V_1 [ 2 * V_11 + V_12 + V_13 ] , 0 ,
sizeof( T_1 ) * - ( V_12 + V_13 ) ) ;
return;
}
V_15 = F_9 ( V_2 , & ( V_2 [ V_14 ] ) , V_17 , V_14 - V_17 ) ;
V_16 = F_9 ( & ( V_3 [ V_14 ] ) , V_3 , V_18 , V_18 - V_14 ) ;
V_20 = V_19 = 0 ;
switch ( V_15 * 3 + V_16 ) {
case - 4 :
F_1 ( V_7 , & ( V_2 [ V_14 ] ) , V_2 , V_17 , V_17 - V_14 ) ;
F_1 ( & ( V_7 [ V_14 ] ) , V_3 , & ( V_3 [ V_14 ] ) , V_18 , V_14 - V_18 ) ;
break;
case - 3 :
V_20 = 1 ;
break;
case - 2 :
F_1 ( V_7 , & ( V_2 [ V_14 ] ) , V_2 , V_17 , V_17 - V_14 ) ;
F_1 ( & ( V_7 [ V_14 ] ) , & ( V_3 [ V_14 ] ) , V_3 , V_18 , V_18 - V_14 ) ;
V_19 = 1 ;
break;
case - 1 :
case 0 :
case 1 :
V_20 = 1 ;
break;
case 2 :
F_1 ( V_7 , V_2 , & ( V_2 [ V_14 ] ) , V_17 , V_14 - V_17 ) ;
F_1 ( & ( V_7 [ V_14 ] ) , V_3 , & ( V_3 [ V_14 ] ) , V_18 , V_14 - V_18 ) ;
V_19 = 1 ;
break;
case 3 :
V_20 = 1 ;
break;
case 4 :
F_1 ( V_7 , V_2 , & ( V_2 [ V_14 ] ) , V_17 , V_14 - V_17 ) ;
F_1 ( & ( V_7 [ V_14 ] ) , & ( V_3 [ V_14 ] ) , V_3 , V_18 , V_18 - V_14 ) ;
break;
}
# ifdef F_6
if ( V_14 == 4 && V_12 == 0 && V_13 == 0 ) {
if ( ! V_20 )
F_10 ( & ( V_7 [ V_11 ] ) , V_7 , & ( V_7 [ V_14 ] ) ) ;
else
memset ( & V_7 [ V_11 ] , 0 , sizeof( * V_7 ) * 8 ) ;
F_10 ( V_1 , V_2 , V_3 ) ;
F_10 ( & ( V_1 [ V_11 ] ) , & ( V_2 [ V_14 ] ) , & ( V_3 [ V_14 ] ) ) ;
} else if ( V_14 == 8 && V_12 == 0 && V_13 == 0 ) {
if ( ! V_20 )
F_7 ( & ( V_7 [ V_11 ] ) , V_7 , & ( V_7 [ V_14 ] ) ) ;
else
memset ( & V_7 [ V_11 ] , 0 , sizeof( * V_7 ) * 16 ) ;
F_7 ( V_1 , V_2 , V_3 ) ;
F_7 ( & ( V_1 [ V_11 ] ) , & ( V_2 [ V_14 ] ) , & ( V_3 [ V_14 ] ) ) ;
} else
# endif
{
V_23 = & ( V_7 [ V_11 * 2 ] ) ;
if ( ! V_20 )
F_5 ( & ( V_7 [ V_11 ] ) , V_7 , & ( V_7 [ V_14 ] ) , V_14 , 0 , 0 , V_23 ) ;
else
memset ( & V_7 [ V_11 ] , 0 , sizeof( * V_7 ) * V_11 ) ;
F_5 ( V_1 , V_2 , V_3 , V_14 , 0 , 0 , V_23 ) ;
F_5 ( & ( V_1 [ V_11 ] ) , & ( V_2 [ V_14 ] ) , & ( V_3 [ V_14 ] ) , V_14 , V_12 , V_13 , V_23 ) ;
}
V_15 = ( int ) ( F_4 ( V_7 , V_1 , & ( V_1 [ V_11 ] ) , V_11 ) ) ;
if ( V_19 ) {
V_15 -= ( int ) ( F_2 ( & ( V_7 [ V_11 ] ) , V_7 , & ( V_7 [ V_11 ] ) , V_11 ) ) ;
} else {
V_15 += ( int ) ( F_4 ( & ( V_7 [ V_11 ] ) , & ( V_7 [ V_11 ] ) , V_7 , V_11 ) ) ;
}
V_15 += ( int ) ( F_4 ( & ( V_1 [ V_14 ] ) , & ( V_1 [ V_14 ] ) , & ( V_7 [ V_11 ] ) , V_11 ) ) ;
if ( V_15 ) {
V_23 = & ( V_1 [ V_14 + V_11 ] ) ;
V_22 = * V_23 ;
V_21 = ( V_22 + V_15 ) & V_8 ;
* V_23 = V_21 ;
if ( V_21 < ( T_1 ) V_15 ) {
do {
V_23 ++ ;
V_22 = * V_23 ;
V_21 = ( V_22 + 1 ) & V_8 ;
* V_23 = V_21 ;
} while ( V_21 == 0 );
}
}
}
void F_11 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , int V_14 ,
int V_17 , int V_18 , T_1 * V_7 )
{
int V_25 , V_26 , V_11 = V_14 * 2 ;
int V_15 , V_16 , V_19 ;
T_1 V_21 , V_22 , * V_23 ;
if ( V_14 < 8 ) {
F_8 ( V_1 , V_2 , V_14 + V_17 , V_3 , V_14 + V_18 ) ;
return;
}
V_15 = F_9 ( V_2 , & ( V_2 [ V_14 ] ) , V_17 , V_14 - V_17 ) ;
V_16 = F_9 ( & ( V_3 [ V_14 ] ) , V_3 , V_18 , V_18 - V_14 ) ;
V_19 = 0 ;
switch ( V_15 * 3 + V_16 ) {
case - 4 :
F_1 ( V_7 , & ( V_2 [ V_14 ] ) , V_2 , V_17 , V_17 - V_14 ) ;
F_1 ( & ( V_7 [ V_14 ] ) , V_3 , & ( V_3 [ V_14 ] ) , V_18 , V_14 - V_18 ) ;
break;
case - 3 :
case - 2 :
F_1 ( V_7 , & ( V_2 [ V_14 ] ) , V_2 , V_17 , V_17 - V_14 ) ;
F_1 ( & ( V_7 [ V_14 ] ) , & ( V_3 [ V_14 ] ) , V_3 , V_18 , V_18 - V_14 ) ;
V_19 = 1 ;
break;
case - 1 :
case 0 :
case 1 :
case 2 :
F_1 ( V_7 , V_2 , & ( V_2 [ V_14 ] ) , V_17 , V_14 - V_17 ) ;
F_1 ( & ( V_7 [ V_14 ] ) , V_3 , & ( V_3 [ V_14 ] ) , V_18 , V_14 - V_18 ) ;
V_19 = 1 ;
break;
case 3 :
case 4 :
F_1 ( V_7 , V_2 , & ( V_2 [ V_14 ] ) , V_17 , V_14 - V_17 ) ;
F_1 ( & ( V_7 [ V_14 ] ) , & ( V_3 [ V_14 ] ) , V_3 , V_18 , V_18 - V_14 ) ;
break;
}
# if 0
if (n == 4) {
bn_mul_comba4(&(t[n2]), t, &(t[n]));
bn_mul_comba4(r, a, b);
bn_mul_normal(&(r[n2]), &(a[n]), tn, &(b[n]), tn);
memset(&r[n2 + tn * 2], 0, sizeof(*r) * (n2 - tn * 2));
} else
# endif
if ( V_14 == 8 ) {
F_7 ( & ( V_7 [ V_11 ] ) , V_7 , & ( V_7 [ V_14 ] ) ) ;
F_7 ( V_1 , V_2 , V_3 ) ;
F_8 ( & ( V_1 [ V_11 ] ) , & ( V_2 [ V_14 ] ) , V_17 , & ( V_3 [ V_14 ] ) , V_18 ) ;
memset ( & V_1 [ V_11 + V_17 + V_18 ] , 0 , sizeof( * V_1 ) * ( V_11 - V_17 - V_18 ) ) ;
} else {
V_23 = & ( V_7 [ V_11 * 2 ] ) ;
F_5 ( & ( V_7 [ V_11 ] ) , V_7 , & ( V_7 [ V_14 ] ) , V_14 , 0 , 0 , V_23 ) ;
F_5 ( V_1 , V_2 , V_3 , V_14 , 0 , 0 , V_23 ) ;
V_25 = V_14 / 2 ;
if ( V_17 > V_18 )
V_26 = V_17 - V_25 ;
else
V_26 = V_18 - V_25 ;
if ( V_26 == 0 ) {
F_5 ( & ( V_1 [ V_11 ] ) , & ( V_2 [ V_14 ] ) , & ( V_3 [ V_14 ] ) ,
V_25 , V_17 - V_25 , V_18 - V_25 , V_23 ) ;
memset ( & V_1 [ V_11 + V_25 * 2 ] , 0 , sizeof( * V_1 ) * ( V_11 - V_25 * 2 ) ) ;
} else if ( V_26 > 0 ) {
F_11 ( & ( V_1 [ V_11 ] ) , & ( V_2 [ V_14 ] ) , & ( V_3 [ V_14 ] ) ,
V_25 , V_17 - V_25 , V_18 - V_25 , V_23 ) ;
memset ( & ( V_1 [ V_11 + V_17 + V_18 ] ) , 0 ,
sizeof( T_1 ) * ( V_11 - V_17 - V_18 ) ) ;
} else {
memset ( & V_1 [ V_11 ] , 0 , sizeof( * V_1 ) * V_11 ) ;
if ( V_17 < V_24
&& V_18 < V_24 ) {
F_8 ( & ( V_1 [ V_11 ] ) , & ( V_2 [ V_14 ] ) , V_17 , & ( V_3 [ V_14 ] ) , V_18 ) ;
} else {
for (; ; ) {
V_25 /= 2 ;
if ( V_25 < V_17 || V_25 < V_18 ) {
F_11 ( & ( V_1 [ V_11 ] ) ,
& ( V_2 [ V_14 ] ) , & ( V_3 [ V_14 ] ) ,
V_25 , V_17 - V_25 , V_18 - V_25 , V_23 ) ;
break;
} else if ( V_25 == V_17 || V_25 == V_18 ) {
F_5 ( & ( V_1 [ V_11 ] ) ,
& ( V_2 [ V_14 ] ) , & ( V_3 [ V_14 ] ) ,
V_25 , V_17 - V_25 , V_18 - V_25 , V_23 ) ;
break;
}
}
}
}
}
V_15 = ( int ) ( F_4 ( V_7 , V_1 , & ( V_1 [ V_11 ] ) , V_11 ) ) ;
if ( V_19 ) {
V_15 -= ( int ) ( F_2 ( & ( V_7 [ V_11 ] ) , V_7 , & ( V_7 [ V_11 ] ) , V_11 ) ) ;
} else {
V_15 += ( int ) ( F_4 ( & ( V_7 [ V_11 ] ) , & ( V_7 [ V_11 ] ) , V_7 , V_11 ) ) ;
}
V_15 += ( int ) ( F_4 ( & ( V_1 [ V_14 ] ) , & ( V_1 [ V_14 ] ) , & ( V_7 [ V_11 ] ) , V_11 ) ) ;
if ( V_15 ) {
V_23 = & ( V_1 [ V_14 + V_11 ] ) ;
V_22 = * V_23 ;
V_21 = ( V_22 + V_15 ) & V_8 ;
* V_23 = V_21 ;
if ( V_21 < ( T_1 ) V_15 ) {
do {
V_23 ++ ;
V_22 = * V_23 ;
V_21 = ( V_22 + 1 ) & V_8 ;
* V_23 = V_21 ;
} while ( V_21 == 0 );
}
}
}
void F_12 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , int V_11 ,
T_1 * V_7 )
{
int V_14 = V_11 / 2 ;
F_5 ( V_1 , V_2 , V_3 , V_14 , 0 , 0 , & ( V_7 [ 0 ] ) ) ;
if ( V_14 >= V_27 ) {
F_12 ( & ( V_7 [ 0 ] ) , & ( V_2 [ 0 ] ) , & ( V_3 [ V_14 ] ) , V_14 , & ( V_7 [ V_11 ] ) ) ;
F_4 ( & ( V_1 [ V_14 ] ) , & ( V_1 [ V_14 ] ) , & ( V_7 [ 0 ] ) , V_14 ) ;
F_12 ( & ( V_7 [ 0 ] ) , & ( V_2 [ V_14 ] ) , & ( V_3 [ 0 ] ) , V_14 , & ( V_7 [ V_11 ] ) ) ;
F_4 ( & ( V_1 [ V_14 ] ) , & ( V_1 [ V_14 ] ) , & ( V_7 [ 0 ] ) , V_14 ) ;
} else {
F_13 ( & ( V_7 [ 0 ] ) , & ( V_2 [ 0 ] ) , & ( V_3 [ V_14 ] ) , V_14 ) ;
F_13 ( & ( V_7 [ V_14 ] ) , & ( V_2 [ V_14 ] ) , & ( V_3 [ 0 ] ) , V_14 ) ;
F_4 ( & ( V_1 [ V_14 ] ) , & ( V_1 [ V_14 ] ) , & ( V_7 [ 0 ] ) , V_14 ) ;
F_4 ( & ( V_1 [ V_14 ] ) , & ( V_1 [ V_14 ] ) , & ( V_7 [ V_14 ] ) , V_14 ) ;
}
}
void F_14 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , T_1 * V_10 , int V_11 ,
T_1 * V_7 )
{
int V_25 , V_14 ;
int V_15 , V_16 ;
int V_19 , V_28 , V_20 ;
T_1 V_29 , V_30 , * V_31 , * V_32 ;
V_14 = V_11 / 2 ;
V_19 = V_20 = 0 ;
V_15 = F_15 ( & ( V_2 [ 0 ] ) , & ( V_2 [ V_14 ] ) , V_14 ) ;
V_16 = F_15 ( & ( V_3 [ V_14 ] ) , & ( V_3 [ 0 ] ) , V_14 ) ;
switch ( V_15 * 3 + V_16 ) {
case - 4 :
F_2 ( & ( V_1 [ 0 ] ) , & ( V_2 [ V_14 ] ) , & ( V_2 [ 0 ] ) , V_14 ) ;
F_2 ( & ( V_1 [ V_14 ] ) , & ( V_3 [ 0 ] ) , & ( V_3 [ V_14 ] ) , V_14 ) ;
break;
case - 3 :
V_20 = 1 ;
break;
case - 2 :
F_2 ( & ( V_1 [ 0 ] ) , & ( V_2 [ V_14 ] ) , & ( V_2 [ 0 ] ) , V_14 ) ;
F_2 ( & ( V_1 [ V_14 ] ) , & ( V_3 [ V_14 ] ) , & ( V_3 [ 0 ] ) , V_14 ) ;
V_19 = 1 ;
break;
case - 1 :
case 0 :
case 1 :
V_20 = 1 ;
break;
case 2 :
F_2 ( & ( V_1 [ 0 ] ) , & ( V_2 [ 0 ] ) , & ( V_2 [ V_14 ] ) , V_14 ) ;
F_2 ( & ( V_1 [ V_14 ] ) , & ( V_3 [ 0 ] ) , & ( V_3 [ V_14 ] ) , V_14 ) ;
V_19 = 1 ;
break;
case 3 :
V_20 = 1 ;
break;
case 4 :
F_2 ( & ( V_1 [ 0 ] ) , & ( V_2 [ 0 ] ) , & ( V_2 [ V_14 ] ) , V_14 ) ;
F_2 ( & ( V_1 [ V_14 ] ) , & ( V_3 [ V_14 ] ) , & ( V_3 [ 0 ] ) , V_14 ) ;
break;
}
V_28 = V_19 ;
# ifdef F_6
if ( V_14 == 8 ) {
F_7 ( & ( V_7 [ 0 ] ) , & ( V_1 [ 0 ] ) , & ( V_1 [ V_14 ] ) ) ;
F_7 ( V_1 , & ( V_2 [ V_14 ] ) , & ( V_3 [ V_14 ] ) ) ;
} else
# endif
{
F_5 ( & ( V_7 [ 0 ] ) , & ( V_1 [ 0 ] ) , & ( V_1 [ V_14 ] ) , V_14 , 0 , 0 , & ( V_7 [ V_11 ] ) ) ;
F_5 ( V_1 , & ( V_2 [ V_14 ] ) , & ( V_3 [ V_14 ] ) , V_14 , 0 , 0 , & ( V_7 [ V_11 ] ) ) ;
}
if ( V_10 != NULL ) {
V_31 = & ( V_7 [ V_11 + V_14 ] ) ;
F_4 ( V_31 , & ( V_1 [ 0 ] ) , & ( V_10 [ 0 ] ) , V_14 ) ;
} else {
V_31 = & ( V_1 [ 0 ] ) ;
}
if ( V_19 )
V_19 = ( int ) ( F_2 ( & ( V_7 [ V_11 ] ) , V_31 , & ( V_7 [ 0 ] ) , V_14 ) ) ;
else {
F_4 ( & ( V_7 [ V_11 ] ) , V_31 , & ( V_7 [ 0 ] ) , V_14 ) ;
V_19 = 0 ;
}
if ( V_10 != NULL ) {
F_2 ( & ( V_7 [ V_11 + V_14 ] ) , & ( V_10 [ V_14 ] ) , & ( V_7 [ V_11 ] ) , V_14 ) ;
} else {
V_31 = & ( V_7 [ V_11 + V_14 ] ) ;
V_32 = & ( V_7 [ V_11 ] ) ;
for ( V_25 = 0 ; V_25 < V_14 ; V_25 ++ )
V_31 [ V_25 ] = ( ( ~ V_32 [ V_25 ] ) + 1 ) & V_8 ;
}
if ( V_10 != NULL ) {
V_31 = & ( V_7 [ V_11 ] ) ;
V_15 = ( int ) ( F_4 ( V_31 , & ( V_7 [ V_11 + V_14 ] ) , & ( V_10 [ 0 ] ) , V_14 ) ) ;
} else {
V_31 = & ( V_7 [ V_11 + V_14 ] ) ;
V_15 = 0 ;
}
V_15 += ( int ) ( F_4 ( & ( V_7 [ V_11 ] ) , V_31 , & ( V_1 [ 0 ] ) , V_14 ) ) ;
if ( V_28 )
V_15 -= ( int ) ( F_2 ( & ( V_7 [ V_11 ] ) , & ( V_7 [ V_11 ] ) , & ( V_7 [ 0 ] ) , V_14 ) ) ;
else
V_15 += ( int ) ( F_4 ( & ( V_7 [ V_11 ] ) , & ( V_7 [ V_11 ] ) , & ( V_7 [ 0 ] ) , V_14 ) ) ;
V_16 = ( int ) ( F_4 ( & ( V_1 [ 0 ] ) , & ( V_1 [ 0 ] ) , & ( V_7 [ V_11 + V_14 ] ) , V_14 ) ) ;
V_16 += ( int ) ( F_4 ( & ( V_1 [ 0 ] ) , & ( V_1 [ 0 ] ) , & ( V_1 [ V_14 ] ) , V_14 ) ) ;
if ( V_28 )
V_16 -= ( int ) ( F_2 ( & ( V_1 [ 0 ] ) , & ( V_1 [ 0 ] ) , & ( V_7 [ V_14 ] ) , V_14 ) ) ;
else
V_16 += ( int ) ( F_4 ( & ( V_1 [ 0 ] ) , & ( V_1 [ 0 ] ) , & ( V_7 [ V_14 ] ) , V_14 ) ) ;
if ( V_15 != 0 ) {
V_25 = 0 ;
if ( V_15 > 0 ) {
V_30 = V_15 ;
do {
V_29 = ( V_1 [ V_25 ] + V_30 ) & V_8 ;
V_1 [ V_25 ++ ] = V_29 ;
V_30 = ( V_30 > V_29 ) ;
} while ( V_30 );
} else {
V_30 = - V_15 ;
do {
V_29 = V_1 [ V_25 ] ;
V_1 [ V_25 ++ ] = ( V_29 - V_30 ) & V_8 ;
V_30 = ( V_30 > V_29 ) ;
} while ( V_30 );
}
}
if ( V_16 != 0 ) {
V_25 = V_14 ;
if ( V_16 > 0 ) {
V_30 = V_16 ;
do {
V_29 = ( V_1 [ V_25 ] + V_30 ) & V_8 ;
V_1 [ V_25 ++ ] = V_29 ;
V_30 = ( V_30 > V_29 ) ;
} while ( V_30 );
} else {
V_30 = - V_16 ;
do {
V_29 = V_1 [ V_25 ] ;
V_1 [ V_25 ++ ] = ( V_29 - V_30 ) & V_8 ;
V_30 = ( V_30 > V_29 ) ;
} while ( V_30 );
}
}
}
int F_16 ( T_2 * V_1 , const T_2 * V_2 , const T_2 * V_3 , T_3 * V_33 )
{
int V_34 = 0 ;
int V_35 , V_36 , V_37 ;
T_2 * V_38 ;
#if F_17 ( F_6 ) || F_17 ( V_39 )
int V_25 ;
#endif
#ifdef V_39
T_2 * V_7 = NULL ;
int V_26 = 0 , V_40 ;
#endif
F_18 ( V_2 ) ;
F_18 ( V_3 ) ;
F_18 ( V_1 ) ;
V_36 = V_2 -> V_35 ;
V_37 = V_3 -> V_35 ;
if ( ( V_36 == 0 ) || ( V_37 == 0 ) ) {
F_19 ( V_1 ) ;
return ( 1 ) ;
}
V_35 = V_36 + V_37 ;
F_20 ( V_33 ) ;
if ( ( V_1 == V_2 ) || ( V_1 == V_3 ) ) {
if ( ( V_38 = F_21 ( V_33 ) ) == NULL )
goto V_41;
} else
V_38 = V_1 ;
V_38 -> V_19 = V_2 -> V_19 ^ V_3 -> V_19 ;
#if F_17 ( F_6 ) || F_17 ( V_39 )
V_25 = V_36 - V_37 ;
#endif
#ifdef F_6
if ( V_25 == 0 ) {
# if 0
if (al == 4) {
if (bn_wexpand(rr, 8) == NULL)
goto err;
rr->top = 8;
bn_mul_comba4(rr->d, a->d, b->d);
goto end;
}
# endif
if ( V_36 == 8 ) {
if ( F_22 ( V_38 , 16 ) == NULL )
goto V_41;
V_38 -> V_35 = 16 ;
F_7 ( V_38 -> V_42 , V_2 -> V_42 , V_3 -> V_42 ) ;
goto V_43;
}
}
#endif
#ifdef V_39
if ( ( V_36 >= V_44 ) && ( V_37 >= V_44 ) ) {
if ( V_25 >= - 1 && V_25 <= 1 ) {
if ( V_25 >= 0 ) {
V_26 = F_23 ( ( T_1 ) V_36 ) ;
}
if ( V_25 == - 1 ) {
V_26 = F_23 ( ( T_1 ) V_37 ) ;
}
V_26 = 1 << ( V_26 - 1 ) ;
assert ( V_26 <= V_36 || V_26 <= V_37 ) ;
V_40 = V_26 + V_26 ;
V_7 = F_21 ( V_33 ) ;
if ( V_7 == NULL )
goto V_41;
if ( V_36 > V_26 || V_37 > V_26 ) {
if ( F_22 ( V_7 , V_40 * 4 ) == NULL )
goto V_41;
if ( F_22 ( V_38 , V_40 * 4 ) == NULL )
goto V_41;
F_11 ( V_38 -> V_42 , V_2 -> V_42 , V_3 -> V_42 ,
V_26 , V_36 - V_26 , V_37 - V_26 , V_7 -> V_42 ) ;
} else {
if ( F_22 ( V_7 , V_40 * 2 ) == NULL )
goto V_41;
if ( F_22 ( V_38 , V_40 * 2 ) == NULL )
goto V_41;
F_5 ( V_38 -> V_42 , V_2 -> V_42 , V_3 -> V_42 , V_26 , V_36 - V_26 , V_37 - V_26 , V_7 -> V_42 ) ;
}
V_38 -> V_35 = V_35 ;
goto V_43;
}
# if 0
if (i == 1 && !BN_get_flags(b, BN_FLG_STATIC_DATA)) {
BIGNUM *tmp_bn = (BIGNUM *)b;
if (bn_wexpand(tmp_bn, al) == NULL)
goto err;
tmp_bn->d[bl] = 0;
bl++;
i--;
} else if (i == -1 && !BN_get_flags(a, BN_FLG_STATIC_DATA)) {
BIGNUM *tmp_bn = (BIGNUM *)a;
if (bn_wexpand(tmp_bn, bl) == NULL)
goto err;
tmp_bn->d[al] = 0;
al++;
i++;
}
if (i == 0) {
j = BN_num_bits_word((BN_ULONG)al);
j = 1 << (j - 1);
k = j + j;
t = BN_CTX_get(ctx);
if (al == j) {
if (bn_wexpand(t, k * 2) == NULL)
goto err;
if (bn_wexpand(rr, k * 2) == NULL)
goto err;
bn_mul_recursive(rr->d, a->d, b->d, al, t->d);
} else {
if (bn_wexpand(t, k * 4) == NULL)
goto err;
if (bn_wexpand(rr, k * 4) == NULL)
goto err;
bn_mul_part_recursive(rr->d, a->d, b->d, al - j, j, t->d);
}
rr->top = top;
goto end;
}
# endif
}
#endif
if ( F_22 ( V_38 , V_35 ) == NULL )
goto V_41;
V_38 -> V_35 = V_35 ;
F_8 ( V_38 -> V_42 , V_2 -> V_42 , V_36 , V_3 -> V_42 , V_37 ) ;
#if F_17 ( F_6 ) || F_17 ( V_39 )
V_43:
#endif
F_24 ( V_38 ) ;
if ( V_1 != V_38 )
F_25 ( V_1 , V_38 ) ;
V_34 = 1 ;
V_41:
F_18 ( V_1 ) ;
F_26 ( V_33 ) ;
return ( V_34 ) ;
}
void F_8 ( T_1 * V_1 , T_1 * V_2 , int V_45 , T_1 * V_3 , int V_46 )
{
T_1 * V_38 ;
if ( V_45 < V_46 ) {
int V_47 ;
T_1 * V_48 ;
V_47 = V_45 ;
V_45 = V_46 ;
V_46 = V_47 ;
V_48 = V_2 ;
V_2 = V_3 ;
V_3 = V_48 ;
}
V_38 = & ( V_1 [ V_45 ] ) ;
if ( V_46 <= 0 ) {
( void ) F_27 ( V_1 , V_2 , V_45 , 0 ) ;
return;
} else
V_38 [ 0 ] = F_27 ( V_1 , V_2 , V_45 , V_3 [ 0 ] ) ;
for (; ; ) {
if ( -- V_46 <= 0 )
return;
V_38 [ 1 ] = F_28 ( & ( V_1 [ 1 ] ) , V_2 , V_45 , V_3 [ 1 ] ) ;
if ( -- V_46 <= 0 )
return;
V_38 [ 2 ] = F_28 ( & ( V_1 [ 2 ] ) , V_2 , V_45 , V_3 [ 2 ] ) ;
if ( -- V_46 <= 0 )
return;
V_38 [ 3 ] = F_28 ( & ( V_1 [ 3 ] ) , V_2 , V_45 , V_3 [ 3 ] ) ;
if ( -- V_46 <= 0 )
return;
V_38 [ 4 ] = F_28 ( & ( V_1 [ 4 ] ) , V_2 , V_45 , V_3 [ 4 ] ) ;
V_38 += 4 ;
V_1 += 4 ;
V_3 += 4 ;
}
}
void F_13 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , int V_14 )
{
F_27 ( V_1 , V_2 , V_14 , V_3 [ 0 ] ) ;
for (; ; ) {
if ( -- V_14 <= 0 )
return;
F_28 ( & ( V_1 [ 1 ] ) , V_2 , V_14 , V_3 [ 1 ] ) ;
if ( -- V_14 <= 0 )
return;
F_28 ( & ( V_1 [ 2 ] ) , V_2 , V_14 , V_3 [ 2 ] ) ;
if ( -- V_14 <= 0 )
return;
F_28 ( & ( V_1 [ 3 ] ) , V_2 , V_14 , V_3 [ 3 ] ) ;
if ( -- V_14 <= 0 )
return;
F_28 ( & ( V_1 [ 4 ] ) , V_2 , V_14 , V_3 [ 4 ] ) ;
V_1 += 4 ;
V_3 += 4 ;
}
}
