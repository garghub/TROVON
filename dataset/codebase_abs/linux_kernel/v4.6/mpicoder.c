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
static int F_8 ( T_1 V_8 )
{
T_4 V_17 ;
int V_4 , V_18 = 0 ;
for ( V_4 = V_8 -> V_7 - 1 ; V_4 >= 0 ; V_4 -- ) {
V_17 = V_8 -> V_13 [ V_4 ] ;
if ( V_17 == 0 ) {
V_18 += sizeof( T_4 ) ;
} else {
V_18 += F_3 ( V_17 ) / 8 ;
break;
}
}
return V_18 ;
}
int F_9 ( T_1 V_8 , T_3 * V_19 , unsigned V_20 , unsigned * V_2 ,
int * V_12 )
{
T_3 * V_21 ;
T_4 V_17 ;
unsigned int V_22 = F_10 ( V_8 ) ;
int V_4 , V_18 ;
if ( ! V_19 || ! V_2 )
return - V_23 ;
if ( V_12 )
* V_12 = V_8 -> V_12 ;
V_18 = F_8 ( V_8 ) ;
if ( V_20 < V_22 - V_18 ) {
* V_2 = V_22 - V_18 ;
return - V_24 ;
}
V_21 = V_19 ;
* V_2 = V_22 - V_18 ;
for ( V_4 = V_8 -> V_7 - 1 ; V_4 >= 0 ; V_4 -- ) {
V_17 = V_8 -> V_13 [ V_4 ] ;
#if V_11 == 4
* V_21 ++ = V_17 >> 24 ;
* V_21 ++ = V_17 >> 16 ;
* V_21 ++ = V_17 >> 8 ;
* V_21 ++ = V_17 ;
#elif V_11 == 8
* V_21 ++ = V_17 >> 56 ;
* V_21 ++ = V_17 >> 48 ;
* V_21 ++ = V_17 >> 40 ;
* V_21 ++ = V_17 >> 32 ;
* V_21 ++ = V_17 >> 24 ;
* V_21 ++ = V_17 >> 16 ;
* V_21 ++ = V_17 >> 8 ;
* V_21 ++ = V_17 ;
#else
#error please implement for this limb size.
#endif
if ( V_18 > 0 ) {
if ( V_18 >= sizeof( V_17 ) ) {
V_21 -= sizeof( V_17 ) ;
} else {
T_4 * V_25 = ( void * ) V_21 - sizeof( V_17 ) ;
T_4 * V_26 = ( void * ) V_21 - sizeof( V_17 )
+ V_18 ;
* V_25 = * V_26 ;
V_21 -= V_18 ;
}
V_18 -= sizeof( V_17 ) ;
}
}
return 0 ;
}
void * F_11 ( T_1 V_8 , unsigned * V_2 , int * V_12 )
{
T_3 * V_19 ;
unsigned int V_22 ;
int V_27 ;
if ( ! V_2 )
return NULL ;
V_22 = F_10 ( V_8 ) ;
if ( ! V_22 )
V_22 ++ ;
V_19 = F_12 ( V_22 , V_28 ) ;
if ( ! V_19 )
return NULL ;
V_27 = F_9 ( V_8 , V_19 , V_22 , V_2 , V_12 ) ;
if ( V_27 ) {
F_13 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
int F_14 ( T_1 V_8 , const void * V_1 , unsigned V_2 , int V_12 )
{
const T_3 * V_3 = V_1 , * V_21 ;
T_4 V_17 ;
int V_7 ;
int V_4 ;
V_7 = F_4 ( V_2 , V_11 ) ;
if ( F_15 ( V_8 , V_7 ) < 0 )
return - V_29 ;
V_8 -> V_12 = V_12 ;
for ( V_4 = 0 , V_21 = V_3 + V_2 - 1 ; V_21 >= V_3 + V_11 ; ) {
#if V_11 == 4
V_17 = ( T_4 ) * V_21 -- ;
V_17 |= ( T_4 ) * V_21 -- << 8 ;
V_17 |= ( T_4 ) * V_21 -- << 16 ;
V_17 |= ( T_4 ) * V_21 -- << 24 ;
#elif V_11 == 8
V_17 = ( T_4 ) * V_21 -- ;
V_17 |= ( T_4 ) * V_21 -- << 8 ;
V_17 |= ( T_4 ) * V_21 -- << 16 ;
V_17 |= ( T_4 ) * V_21 -- << 24 ;
V_17 |= ( T_4 ) * V_21 -- << 32 ;
V_17 |= ( T_4 ) * V_21 -- << 40 ;
V_17 |= ( T_4 ) * V_21 -- << 48 ;
V_17 |= ( T_4 ) * V_21 -- << 56 ;
#else
#error please implement for this limb size.
#endif
V_8 -> V_13 [ V_4 ++ ] = V_17 ;
}
if ( V_21 >= V_3 ) {
#if V_11 == 4
V_17 = * V_21 -- ;
if ( V_21 >= V_3 )
V_17 |= ( T_4 ) * V_21 -- << 8 ;
if ( V_21 >= V_3 )
V_17 |= ( T_4 ) * V_21 -- << 16 ;
if ( V_21 >= V_3 )
V_17 |= ( T_4 ) * V_21 -- << 24 ;
#elif V_11 == 8
V_17 = ( T_4 ) * V_21 -- ;
if ( V_21 >= V_3 )
V_17 |= ( T_4 ) * V_21 -- << 8 ;
if ( V_21 >= V_3 )
V_17 |= ( T_4 ) * V_21 -- << 16 ;
if ( V_21 >= V_3 )
V_17 |= ( T_4 ) * V_21 -- << 24 ;
if ( V_21 >= V_3 )
V_17 |= ( T_4 ) * V_21 -- << 32 ;
if ( V_21 >= V_3 )
V_17 |= ( T_4 ) * V_21 -- << 40 ;
if ( V_21 >= V_3 )
V_17 |= ( T_4 ) * V_21 -- << 48 ;
if ( V_21 >= V_3 )
V_17 |= ( T_4 ) * V_21 -- << 56 ;
#else
#error please implement for this limb size.
#endif
V_8 -> V_13 [ V_4 ++ ] = V_17 ;
}
V_8 -> V_7 = V_4 ;
if ( V_4 != V_7 ) {
F_16 ( L_3 , V_4 ,
V_7 ) ;
F_17 () ;
}
return 0 ;
}
int F_18 ( T_1 V_8 , struct V_30 * V_31 , unsigned * V_2 ,
int * V_12 )
{
T_5 * V_21 , * V_32 ;
T_4 V_17 , V_33 ;
unsigned int V_22 = F_10 ( V_8 ) ;
int V_4 , V_34 , V_35 = 0 , V_18 , V_20 ;
if ( ! V_2 )
return - V_23 ;
if ( V_12 )
* V_12 = V_8 -> V_12 ;
V_18 = F_8 ( V_8 ) ;
if ( * V_2 < V_22 - V_18 ) {
* V_2 = V_22 - V_18 ;
return - V_24 ;
}
* V_2 = V_22 - V_18 ;
V_20 = V_31 -> V_36 ;
V_32 = F_19 ( V_31 ) ;
for ( V_4 = V_8 -> V_7 - 1 ; V_4 >= 0 ; V_4 -- ) {
V_17 = V_8 -> V_13 [ V_4 ] ;
V_21 = ( T_5 * ) & V_33 ;
#if V_11 == 4
* V_21 ++ = V_17 >> 24 ;
* V_21 ++ = V_17 >> 16 ;
* V_21 ++ = V_17 >> 8 ;
* V_21 ++ = V_17 ;
#elif V_11 == 8
* V_21 ++ = V_17 >> 56 ;
* V_21 ++ = V_17 >> 48 ;
* V_21 ++ = V_17 >> 40 ;
* V_21 ++ = V_17 >> 32 ;
* V_21 ++ = V_17 >> 24 ;
* V_21 ++ = V_17 >> 16 ;
* V_21 ++ = V_17 >> 8 ;
* V_21 ++ = V_17 ;
#else
#error please implement for this limb size.
#endif
if ( V_18 > 0 ) {
if ( V_18 >= sizeof( V_17 ) ) {
V_21 -= sizeof( V_17 ) ;
continue;
} else {
T_4 * V_25 = ( void * ) V_21 - sizeof( V_17 ) ;
T_4 * V_26 = ( void * ) V_21 - sizeof( V_17 )
+ V_18 ;
* V_25 = * V_26 ;
V_21 -= V_18 ;
V_35 = V_18 ;
}
V_18 -= sizeof( V_17 ) ;
}
V_21 = V_21 - ( sizeof( V_17 ) - V_35 ) ;
for ( V_34 = 0 ; V_34 < sizeof( V_17 ) - V_35 ; V_34 ++ ) {
if ( ! V_20 ) {
V_31 = F_20 ( V_31 ) ;
if ( ! V_31 )
return - V_23 ;
V_20 = V_31 -> V_36 ;
V_32 = F_19 ( V_31 ) ;
}
* V_32 ++ = * V_21 ++ ;
V_20 -- ;
}
V_35 = 0 ;
}
return 0 ;
}
T_1 F_21 ( struct V_30 * V_31 , unsigned int V_37 )
{
struct V_30 * V_38 ;
int V_34 , V_4 , V_5 , V_39 , V_18 , V_40 ;
unsigned int V_6 , V_7 , V_2 ;
T_4 V_8 ;
T_1 V_9 = NULL ;
V_18 = 0 ;
V_40 = F_22 ( V_31 ) ;
F_23 (sgl, sg, ents, i) {
const T_5 * V_41 = F_19 ( V_38 ) ;
int V_37 = V_38 -> V_36 ;
while ( V_37 && ! * V_41 ) {
V_18 ++ ;
V_37 -- ;
V_41 ++ ;
}
if ( V_37 && * V_41 )
break;
V_40 -- ;
V_18 = 0 ;
}
V_31 = V_38 ;
if ( ! V_40 )
V_2 = 0 ;
else
V_2 = V_37 - V_18 ;
V_6 = V_2 * 8 ;
if ( V_6 > V_10 ) {
F_2 ( L_1 , V_6 ) ;
return NULL ;
}
if ( V_2 > 0 )
V_6 -= F_3 ( * ( T_5 * ) ( F_19 ( V_31 ) + V_18 ) ) ;
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
F_23 (sgl, sg, ents, i) {
const T_5 * V_3 = F_19 ( V_38 ) + V_18 ;
int V_37 = V_38 -> V_36 - V_18 ;
int V_42 = V_34 ;
if ( F_24 ( V_38 ) && ( V_37 % V_11 ) )
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
V_18 = 0 ;
}
return V_9 ;
}
