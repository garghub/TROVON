T_1 F_1 ( const void * V_1 , T_2 V_2 )
{
const T_3 * V_3 = V_1 ;
int V_4 , V_5 ;
unsigned V_6 , V_7 ;
T_4 V_8 ;
T_1 V_9 = NULL ;
while ( V_2 > 0 && V_3 [ 0 ] == 0 ) {
V_3 ++ ;
V_2 -- ;
}
V_6 = V_2 * 8 ;
if ( V_6 > V_10 ) {
F_2 ( L_1 , V_6 ) ;
return NULL ;
}
if ( V_2 > 0 )
V_6 -= F_3 ( V_3 [ 0 ] ) ;
else
V_6 = 0 ;
V_7 = F_4 ( V_2 , V_11 ) ;
V_9 = F_5 ( V_7 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_6 = V_6 ;
V_9 -> V_12 = 0 ;
V_9 -> V_7 = V_7 ;
if ( V_2 > 0 ) {
V_4 = V_11 - V_2 % V_11 ;
V_4 %= V_11 ;
for ( V_5 = V_7 ; V_5 > 0 ; V_5 -- ) {
V_8 = 0 ;
for (; V_4 < V_11 ; V_4 ++ ) {
V_8 <<= 8 ;
V_8 |= * V_3 ++ ;
}
V_4 = 0 ;
V_9 -> V_13 [ V_5 - 1 ] = V_8 ;
}
}
return V_9 ;
}
T_1 F_6 ( const void * V_1 , unsigned * V_14 )
{
const T_3 * V_3 = V_1 ;
int V_4 , V_5 ;
unsigned V_6 , V_2 , V_7 , V_15 = 0 ;
T_4 V_8 ;
T_1 V_9 = NULL ;
if ( * V_14 < 2 )
goto V_16;
V_6 = V_3 [ 0 ] << 8 | V_3 [ 1 ] ;
if ( V_6 > V_10 ) {
F_2 ( L_1 , V_6 ) ;
goto V_16;
}
V_3 += 2 ;
V_15 = 2 ;
V_2 = F_4 ( V_6 , 8 ) ;
V_7 = F_4 ( V_2 , V_11 ) ;
V_9 = F_5 ( V_7 ) ;
if ( ! V_9 )
return NULL ;
V_4 = V_11 - V_2 % V_11 ;
V_4 %= V_11 ;
V_9 -> V_6 = V_6 ;
V_5 = V_9 -> V_7 = V_7 ;
V_9 -> V_12 = 0 ;
for (; V_5 > 0 ; V_5 -- ) {
V_8 = 0 ;
for (; V_4 < V_11 ; V_4 ++ ) {
if ( ++ V_15 > * V_14 ) {
F_7
( L_2 ,
V_15 , * V_14 ) ;
goto V_16;
}
V_8 <<= 8 ;
V_8 |= * V_3 ++ ;
}
V_4 = 0 ;
V_9 -> V_13 [ V_5 - 1 ] = V_8 ;
}
V_16:
* V_14 = V_15 ;
return V_9 ;
}
int F_8 ( T_1 V_8 , T_3 * V_17 , unsigned V_18 , unsigned * V_2 ,
int * V_12 )
{
T_3 * V_19 ;
T_4 V_20 ;
unsigned int V_21 = F_9 ( V_8 ) ;
int V_4 , V_22 = 0 ;
if ( ! V_17 || ! V_2 )
return - V_23 ;
if ( V_12 )
* V_12 = V_8 -> V_12 ;
V_19 = ( void * ) & V_8 -> V_13 [ V_8 -> V_7 ] - 1 ;
for ( V_4 = V_8 -> V_7 * sizeof( V_20 ) - 1 ; V_4 >= 0 ; V_4 -- , V_19 -- ) {
if ( ! * V_19 )
V_22 ++ ;
else
break;
}
if ( V_18 < V_21 - V_22 ) {
* V_2 = V_21 - V_22 ;
return - V_24 ;
}
V_19 = V_17 ;
* V_2 = V_21 - V_22 ;
for ( V_4 = V_8 -> V_7 - 1 ; V_4 >= 0 ; V_4 -- ) {
V_20 = V_8 -> V_13 [ V_4 ] ;
#if V_11 == 4
* V_19 ++ = V_20 >> 24 ;
* V_19 ++ = V_20 >> 16 ;
* V_19 ++ = V_20 >> 8 ;
* V_19 ++ = V_20 ;
#elif V_11 == 8
* V_19 ++ = V_20 >> 56 ;
* V_19 ++ = V_20 >> 48 ;
* V_19 ++ = V_20 >> 40 ;
* V_19 ++ = V_20 >> 32 ;
* V_19 ++ = V_20 >> 24 ;
* V_19 ++ = V_20 >> 16 ;
* V_19 ++ = V_20 >> 8 ;
* V_19 ++ = V_20 ;
#else
#error please implement for this limb size.
#endif
if ( V_22 > 0 ) {
if ( V_22 >= sizeof( V_20 ) ) {
V_19 -= sizeof( V_20 ) ;
} else {
T_4 * V_25 = ( void * ) V_19 - sizeof( V_20 ) ;
T_4 * V_26 = ( void * ) V_19 - sizeof( V_20 )
+ V_22 ;
* V_25 = * V_26 ;
V_19 -= V_22 ;
}
V_22 -= sizeof( V_20 ) ;
}
}
return 0 ;
}
void * F_10 ( T_1 V_8 , unsigned * V_2 , int * V_12 )
{
T_3 * V_17 ;
unsigned int V_21 ;
int V_27 ;
if ( ! V_2 )
return NULL ;
V_21 = F_9 ( V_8 ) ;
if ( ! V_21 )
V_21 ++ ;
V_17 = F_11 ( V_21 , V_28 ) ;
if ( ! V_17 )
return NULL ;
V_27 = F_8 ( V_8 , V_17 , V_21 , V_2 , V_12 ) ;
if ( V_27 ) {
F_12 ( V_17 ) ;
return NULL ;
}
return V_17 ;
}
int F_13 ( T_1 V_8 , const void * V_1 , unsigned V_2 , int V_12 )
{
const T_3 * V_3 = V_1 , * V_19 ;
T_4 V_20 ;
int V_7 ;
int V_4 ;
V_7 = F_4 ( V_2 , V_11 ) ;
if ( F_14 ( V_8 , V_7 ) < 0 )
return - V_29 ;
V_8 -> V_12 = V_12 ;
for ( V_4 = 0 , V_19 = V_3 + V_2 - 1 ; V_19 >= V_3 + V_11 ; ) {
#if V_11 == 4
V_20 = ( T_4 ) * V_19 -- ;
V_20 |= ( T_4 ) * V_19 -- << 8 ;
V_20 |= ( T_4 ) * V_19 -- << 16 ;
V_20 |= ( T_4 ) * V_19 -- << 24 ;
#elif V_11 == 8
V_20 = ( T_4 ) * V_19 -- ;
V_20 |= ( T_4 ) * V_19 -- << 8 ;
V_20 |= ( T_4 ) * V_19 -- << 16 ;
V_20 |= ( T_4 ) * V_19 -- << 24 ;
V_20 |= ( T_4 ) * V_19 -- << 32 ;
V_20 |= ( T_4 ) * V_19 -- << 40 ;
V_20 |= ( T_4 ) * V_19 -- << 48 ;
V_20 |= ( T_4 ) * V_19 -- << 56 ;
#else
#error please implement for this limb size.
#endif
V_8 -> V_13 [ V_4 ++ ] = V_20 ;
}
if ( V_19 >= V_3 ) {
#if V_11 == 4
V_20 = * V_19 -- ;
if ( V_19 >= V_3 )
V_20 |= ( T_4 ) * V_19 -- << 8 ;
if ( V_19 >= V_3 )
V_20 |= ( T_4 ) * V_19 -- << 16 ;
if ( V_19 >= V_3 )
V_20 |= ( T_4 ) * V_19 -- << 24 ;
#elif V_11 == 8
V_20 = ( T_4 ) * V_19 -- ;
if ( V_19 >= V_3 )
V_20 |= ( T_4 ) * V_19 -- << 8 ;
if ( V_19 >= V_3 )
V_20 |= ( T_4 ) * V_19 -- << 16 ;
if ( V_19 >= V_3 )
V_20 |= ( T_4 ) * V_19 -- << 24 ;
if ( V_19 >= V_3 )
V_20 |= ( T_4 ) * V_19 -- << 32 ;
if ( V_19 >= V_3 )
V_20 |= ( T_4 ) * V_19 -- << 40 ;
if ( V_19 >= V_3 )
V_20 |= ( T_4 ) * V_19 -- << 48 ;
if ( V_19 >= V_3 )
V_20 |= ( T_4 ) * V_19 -- << 56 ;
#else
#error please implement for this limb size.
#endif
V_8 -> V_13 [ V_4 ++ ] = V_20 ;
}
V_8 -> V_7 = V_4 ;
if ( V_4 != V_7 ) {
F_15 ( L_3 , V_4 ,
V_7 ) ;
F_16 () ;
}
return 0 ;
}
int F_17 ( T_1 V_8 , struct V_30 * V_31 , unsigned * V_2 ,
int * V_12 )
{
T_5 * V_19 , * V_32 ;
T_4 V_20 , V_33 ;
unsigned int V_21 = F_9 ( V_8 ) ;
int V_4 , V_34 , V_35 = 0 , V_22 = 0 , V_18 ;
if ( ! V_2 )
return - V_23 ;
if ( V_12 )
* V_12 = V_8 -> V_12 ;
V_19 = ( void * ) & V_8 -> V_13 [ V_8 -> V_7 ] - 1 ;
for ( V_4 = V_8 -> V_7 * sizeof( V_20 ) - 1 ; V_4 >= 0 ; V_4 -- , V_19 -- ) {
if ( ! * V_19 )
V_22 ++ ;
else
break;
}
if ( * V_2 < V_21 - V_22 ) {
* V_2 = V_21 - V_22 ;
return - V_24 ;
}
* V_2 = V_21 - V_22 ;
V_18 = V_31 -> V_36 ;
V_32 = F_18 ( V_31 ) ;
for ( V_4 = V_8 -> V_7 - 1 ; V_4 >= 0 ; V_4 -- ) {
V_20 = V_8 -> V_13 [ V_4 ] ;
V_19 = ( T_5 * ) & V_33 ;
#if V_11 == 4
* V_19 ++ = V_20 >> 24 ;
* V_19 ++ = V_20 >> 16 ;
* V_19 ++ = V_20 >> 8 ;
* V_19 ++ = V_20 ;
#elif V_11 == 8
* V_19 ++ = V_20 >> 56 ;
* V_19 ++ = V_20 >> 48 ;
* V_19 ++ = V_20 >> 40 ;
* V_19 ++ = V_20 >> 32 ;
* V_19 ++ = V_20 >> 24 ;
* V_19 ++ = V_20 >> 16 ;
* V_19 ++ = V_20 >> 8 ;
* V_19 ++ = V_20 ;
#else
#error please implement for this limb size.
#endif
if ( V_22 > 0 ) {
if ( V_22 >= sizeof( V_20 ) ) {
V_19 -= sizeof( V_20 ) ;
continue;
} else {
T_4 * V_25 = ( void * ) V_19 - sizeof( V_20 ) ;
T_4 * V_26 = ( void * ) V_19 - sizeof( V_20 )
+ V_22 ;
* V_25 = * V_26 ;
V_19 -= V_22 ;
V_35 = V_22 ;
}
V_22 -= sizeof( V_20 ) ;
}
V_19 = V_19 - ( sizeof( V_20 ) - V_35 ) ;
for ( V_34 = 0 ; V_34 < sizeof( V_20 ) - V_35 ; V_34 ++ ) {
if ( ! V_18 ) {
V_31 = F_19 ( V_31 ) ;
if ( ! V_31 )
return - V_23 ;
V_18 = V_31 -> V_36 ;
V_32 = F_18 ( V_31 ) ;
}
* V_32 ++ = * V_19 ++ ;
V_18 -- ;
}
V_35 = 0 ;
}
return 0 ;
}
T_1 F_20 ( struct V_30 * V_31 , unsigned int V_37 )
{
struct V_30 * V_38 ;
int V_34 , V_4 , V_5 , V_39 , V_22 , V_40 ;
unsigned int V_6 , V_7 , V_2 ;
T_4 V_8 ;
T_1 V_9 = NULL ;
V_22 = 0 ;
V_40 = F_21 ( V_31 ) ;
F_22 (sgl, sg, ents, i) {
const T_5 * V_41 = F_18 ( V_38 ) ;
int V_37 = V_38 -> V_36 ;
while ( V_37 && ! * V_41 ) {
V_22 ++ ;
V_37 -- ;
V_41 ++ ;
}
if ( V_37 && * V_41 )
break;
V_40 -- ;
V_22 = 0 ;
}
V_31 = V_38 ;
if ( ! V_40 )
V_2 = 0 ;
else
V_2 = V_37 - V_22 ;
V_6 = V_2 * 8 ;
if ( V_6 > V_10 ) {
F_2 ( L_1 , V_6 ) ;
return NULL ;
}
if ( V_2 > 0 )
V_6 -= F_3 ( * ( T_5 * ) ( F_18 ( V_31 ) + V_22 ) ) ;
else
V_6 = 0 ;
V_7 = F_4 ( V_2 , V_11 ) ;
V_9 = F_5 ( V_7 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_6 = V_6 ;
V_9 -> V_12 = 0 ;
V_9 -> V_7 = V_7 ;
if ( V_2 == 0 )
return V_9 ;
V_5 = V_7 - 1 ;
V_8 = 0 ;
V_39 = 0 ;
V_34 = V_11 - V_2 % V_11 ;
V_34 %= V_11 ;
F_22 (sgl, sg, ents, i) {
const T_5 * V_3 = F_18 ( V_38 ) + V_22 ;
int V_37 = V_38 -> V_36 - V_22 ;
int V_42 = V_34 ;
if ( F_23 ( V_38 ) && ( V_37 % V_11 ) )
V_37 += V_11 - ( V_37 % V_11 ) ;
for (; V_34 < V_37 + V_42 ; V_34 ++ ) {
V_8 <<= 8 ;
V_8 |= * V_3 ++ ;
if ( ( ( V_39 + V_34 + 1 ) % V_11 ) == 0 ) {
V_9 -> V_13 [ V_5 -- ] = V_8 ;
V_8 = 0 ;
}
}
V_39 += V_34 ;
V_34 = 0 ;
V_22 = 0 ;
}
return V_9 ;
}
