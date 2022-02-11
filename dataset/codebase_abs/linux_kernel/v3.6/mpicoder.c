T_1 F_1 ( const void * V_1 , unsigned * V_2 )
{
const T_2 * V_3 = V_1 ;
int V_4 , V_5 ;
unsigned V_6 , V_7 , V_8 , V_9 = 0 ;
T_3 V_10 ;
T_1 V_11 = NULL ;
if ( * V_2 < 2 )
goto V_12;
V_6 = V_3 [ 0 ] << 8 | V_3 [ 1 ] ;
if ( V_6 > V_13 ) {
F_2 ( L_1 , V_6 ) ;
goto V_12;
}
V_3 += 2 ;
V_9 = 2 ;
V_7 = ( V_6 + 7 ) / 8 ;
V_8 = ( V_7 + V_14 - 1 ) / V_14 ;
V_11 = F_3 ( V_8 ) ;
if ( ! V_11 )
return NULL ;
V_4 = V_14 - V_7 % V_14 ;
V_4 %= V_14 ;
V_11 -> V_6 = V_6 ;
V_5 = V_11 -> V_8 = V_8 ;
V_11 -> V_15 = 0 ;
for (; V_5 > 0 ; V_5 -- ) {
V_10 = 0 ;
for (; V_4 < V_14 ; V_4 ++ ) {
if ( ++ V_9 > * V_2 ) {
F_4
( L_2 ,
V_9 , * V_2 ) ;
goto V_12;
}
V_10 <<= 8 ;
V_10 |= * V_3 ++ ;
}
V_4 = 0 ;
V_11 -> V_16 [ V_5 - 1 ] = V_10 ;
}
V_12:
* V_2 = V_9 ;
return V_11 ;
}
void * F_5 ( T_1 V_10 , unsigned * V_7 , int * V_15 )
{
T_2 * V_17 , * V_3 ;
T_3 V_18 ;
int V_4 ;
unsigned int V_19 ;
if ( V_15 )
* V_15 = V_10 -> V_15 ;
* V_7 = V_19 = V_10 -> V_8 * V_14 ;
if ( ! V_19 )
V_19 ++ ;
V_17 = V_3 = F_6 ( V_19 , V_20 ) ;
if ( ! V_17 )
return NULL ;
for ( V_4 = V_10 -> V_8 - 1 ; V_4 >= 0 ; V_4 -- ) {
V_18 = V_10 -> V_16 [ V_4 ] ;
#if V_14 == 4
* V_17 ++ = V_18 >> 24 ;
* V_17 ++ = V_18 >> 16 ;
* V_17 ++ = V_18 >> 8 ;
* V_17 ++ = V_18 ;
#elif V_14 == 8
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
for ( V_17 = V_3 ; ! * V_17 && * V_7 ; V_17 ++ , -- * V_7 )
;
if ( V_17 != V_3 )
memmove ( V_3 , V_17 , * V_7 ) ;
return V_3 ;
}
int F_7 ( T_1 V_10 , const void * V_1 , unsigned V_7 , int V_15 )
{
const T_2 * V_3 = V_1 , * V_17 ;
T_3 V_18 ;
int V_8 ;
int V_4 ;
V_8 = ( V_7 + V_14 - 1 ) / V_14 ;
if ( F_8 ( V_10 , V_8 ) < 0 )
return - V_21 ;
V_10 -> V_15 = V_15 ;
for ( V_4 = 0 , V_17 = V_3 + V_7 - 1 ; V_17 >= V_3 + V_14 ; ) {
#if V_14 == 4
V_18 = ( T_3 ) * V_17 -- ;
V_18 |= ( T_3 ) * V_17 -- << 8 ;
V_18 |= ( T_3 ) * V_17 -- << 16 ;
V_18 |= ( T_3 ) * V_17 -- << 24 ;
#elif V_14 == 8
V_18 = ( T_3 ) * V_17 -- ;
V_18 |= ( T_3 ) * V_17 -- << 8 ;
V_18 |= ( T_3 ) * V_17 -- << 16 ;
V_18 |= ( T_3 ) * V_17 -- << 24 ;
V_18 |= ( T_3 ) * V_17 -- << 32 ;
V_18 |= ( T_3 ) * V_17 -- << 40 ;
V_18 |= ( T_3 ) * V_17 -- << 48 ;
V_18 |= ( T_3 ) * V_17 -- << 56 ;
#else
#error please implement for this limb size.
#endif
V_10 -> V_16 [ V_4 ++ ] = V_18 ;
}
if ( V_17 >= V_3 ) {
#if V_14 == 4
V_18 = * V_17 -- ;
if ( V_17 >= V_3 )
V_18 |= ( T_3 ) * V_17 -- << 8 ;
if ( V_17 >= V_3 )
V_18 |= ( T_3 ) * V_17 -- << 16 ;
if ( V_17 >= V_3 )
V_18 |= ( T_3 ) * V_17 -- << 24 ;
#elif V_14 == 8
V_18 = ( T_3 ) * V_17 -- ;
if ( V_17 >= V_3 )
V_18 |= ( T_3 ) * V_17 -- << 8 ;
if ( V_17 >= V_3 )
V_18 |= ( T_3 ) * V_17 -- << 16 ;
if ( V_17 >= V_3 )
V_18 |= ( T_3 ) * V_17 -- << 24 ;
if ( V_17 >= V_3 )
V_18 |= ( T_3 ) * V_17 -- << 32 ;
if ( V_17 >= V_3 )
V_18 |= ( T_3 ) * V_17 -- << 40 ;
if ( V_17 >= V_3 )
V_18 |= ( T_3 ) * V_17 -- << 48 ;
if ( V_17 >= V_3 )
V_18 |= ( T_3 ) * V_17 -- << 56 ;
#else
#error please implement for this limb size.
#endif
V_10 -> V_16 [ V_4 ++ ] = V_18 ;
}
V_10 -> V_8 = V_4 ;
if ( V_4 != V_8 ) {
F_9 ( L_3 , V_4 ,
V_8 ) ;
F_10 () ;
}
return 0 ;
}
