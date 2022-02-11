T_1 F_1 ( const void * V_1 , T_2 V_2 )
{
const T_3 * V_3 = V_1 ;
int V_4 , V_5 ;
unsigned V_6 , V_7 ;
T_4 V_8 ;
T_1 V_9 = NULL ;
while ( V_2 >= 0 && V_3 [ 0 ] == 0 ) {
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
V_7 = ( V_2 + V_11 - 1 ) / V_11 ;
V_9 = F_4 ( V_7 ) ;
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
T_1 F_5 ( const void * V_1 , unsigned * V_14 )
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
V_2 = ( V_6 + 7 ) / 8 ;
V_7 = ( V_2 + V_11 - 1 ) / V_11 ;
V_9 = F_4 ( V_7 ) ;
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
F_6
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
void * F_7 ( T_1 V_8 , unsigned * V_2 , int * V_12 )
{
T_3 * V_17 , * V_3 ;
T_4 V_18 ;
int V_4 ;
unsigned int V_19 ;
if ( V_12 )
* V_12 = V_8 -> V_12 ;
* V_2 = V_19 = V_8 -> V_7 * V_11 ;
if ( ! V_19 )
V_19 ++ ;
V_17 = V_3 = F_8 ( V_19 , V_20 ) ;
if ( ! V_17 )
return NULL ;
for ( V_4 = V_8 -> V_7 - 1 ; V_4 >= 0 ; V_4 -- ) {
V_18 = V_8 -> V_13 [ V_4 ] ;
#if V_11 == 4
* V_17 ++ = V_18 >> 24 ;
* V_17 ++ = V_18 >> 16 ;
* V_17 ++ = V_18 >> 8 ;
* V_17 ++ = V_18 ;
#elif V_11 == 8
* V_17 ++ = V_18 >> 56 ;
* V_17 ++ = V_18 >> 48 ;
* V_17 ++ = V_18 >> 40 ;
* V_17 ++ = V_18 >> 32 ;
* V_17 ++ = V_18 >> 24 ;
* V_17 ++ = V_18 >> 16 ;
* V_17 ++ = V_18 >> 8 ;
* V_17 ++ = V_18 ;
#else
#error please implement for this limb size.
#endif
}
for ( V_17 = V_3 ; ! * V_17 && * V_2 ; V_17 ++ , -- * V_2 )
;
if ( V_17 != V_3 )
memmove ( V_3 , V_17 , * V_2 ) ;
return V_3 ;
}
int F_9 ( T_1 V_8 , const void * V_1 , unsigned V_2 , int V_12 )
{
const T_3 * V_3 = V_1 , * V_17 ;
T_4 V_18 ;
int V_7 ;
int V_4 ;
V_7 = ( V_2 + V_11 - 1 ) / V_11 ;
if ( F_10 ( V_8 , V_7 ) < 0 )
return - V_21 ;
V_8 -> V_12 = V_12 ;
for ( V_4 = 0 , V_17 = V_3 + V_2 - 1 ; V_17 >= V_3 + V_11 ; ) {
#if V_11 == 4
V_18 = ( T_4 ) * V_17 -- ;
V_18 |= ( T_4 ) * V_17 -- << 8 ;
V_18 |= ( T_4 ) * V_17 -- << 16 ;
V_18 |= ( T_4 ) * V_17 -- << 24 ;
#elif V_11 == 8
V_18 = ( T_4 ) * V_17 -- ;
V_18 |= ( T_4 ) * V_17 -- << 8 ;
V_18 |= ( T_4 ) * V_17 -- << 16 ;
V_18 |= ( T_4 ) * V_17 -- << 24 ;
V_18 |= ( T_4 ) * V_17 -- << 32 ;
V_18 |= ( T_4 ) * V_17 -- << 40 ;
V_18 |= ( T_4 ) * V_17 -- << 48 ;
V_18 |= ( T_4 ) * V_17 -- << 56 ;
#else
#error please implement for this limb size.
#endif
V_8 -> V_13 [ V_4 ++ ] = V_18 ;
}
if ( V_17 >= V_3 ) {
#if V_11 == 4
V_18 = * V_17 -- ;
if ( V_17 >= V_3 )
V_18 |= ( T_4 ) * V_17 -- << 8 ;
if ( V_17 >= V_3 )
V_18 |= ( T_4 ) * V_17 -- << 16 ;
if ( V_17 >= V_3 )
V_18 |= ( T_4 ) * V_17 -- << 24 ;
#elif V_11 == 8
V_18 = ( T_4 ) * V_17 -- ;
if ( V_17 >= V_3 )
V_18 |= ( T_4 ) * V_17 -- << 8 ;
if ( V_17 >= V_3 )
V_18 |= ( T_4 ) * V_17 -- << 16 ;
if ( V_17 >= V_3 )
V_18 |= ( T_4 ) * V_17 -- << 24 ;
if ( V_17 >= V_3 )
V_18 |= ( T_4 ) * V_17 -- << 32 ;
if ( V_17 >= V_3 )
V_18 |= ( T_4 ) * V_17 -- << 40 ;
if ( V_17 >= V_3 )
V_18 |= ( T_4 ) * V_17 -- << 48 ;
if ( V_17 >= V_3 )
V_18 |= ( T_4 ) * V_17 -- << 56 ;
#else
#error please implement for this limb size.
#endif
V_8 -> V_13 [ V_4 ++ ] = V_18 ;
}
V_8 -> V_7 = V_4 ;
if ( V_4 != V_7 ) {
F_11 ( L_3 , V_4 ,
V_7 ) ;
F_12 () ;
}
return 0 ;
}
