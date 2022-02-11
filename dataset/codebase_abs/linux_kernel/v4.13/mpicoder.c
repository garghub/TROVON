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
V_6 -= F_3 ( V_3 [ 0 ] ) - ( V_11 - 8 ) ;
V_7 = F_4 ( V_2 , V_12 ) ;
V_9 = F_5 ( V_7 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_6 = V_6 ;
V_9 -> V_13 = 0 ;
V_9 -> V_7 = V_7 ;
if ( V_2 > 0 ) {
V_4 = V_12 - V_2 % V_12 ;
V_4 %= V_12 ;
for ( V_5 = V_7 ; V_5 > 0 ; V_5 -- ) {
V_8 = 0 ;
for (; V_4 < V_12 ; V_4 ++ ) {
V_8 <<= 8 ;
V_8 |= * V_3 ++ ;
}
V_4 = 0 ;
V_9 -> V_14 [ V_5 - 1 ] = V_8 ;
}
}
return V_9 ;
}
T_1 F_6 ( const void * V_1 , unsigned * V_15 )
{
const T_3 * V_3 = V_1 ;
unsigned int V_6 , V_2 ;
T_1 V_9 ;
if ( * V_15 < 2 )
return F_7 ( - V_16 ) ;
V_6 = V_3 [ 0 ] << 8 | V_3 [ 1 ] ;
if ( V_6 > V_10 ) {
F_2 ( L_1 , V_6 ) ;
return F_7 ( - V_16 ) ;
}
V_2 = F_4 ( V_6 , 8 ) ;
if ( V_2 + 2 > * V_15 ) {
F_2 ( L_2 ,
V_2 , * V_15 ) ;
return F_7 ( - V_16 ) ;
}
V_9 = F_1 ( V_3 + 2 , V_2 ) ;
if ( ! V_9 )
return F_7 ( - V_17 ) ;
* V_15 = V_2 + 2 ;
return V_9 ;
}
static int F_8 ( T_1 V_8 )
{
T_4 V_18 ;
int V_4 , V_19 = 0 ;
for ( V_4 = V_8 -> V_7 - 1 ; V_4 >= 0 ; V_4 -- ) {
V_18 = V_8 -> V_14 [ V_4 ] ;
if ( V_18 == 0 ) {
V_19 += sizeof( T_4 ) ;
} else {
V_19 += F_3 ( V_18 ) / 8 ;
break;
}
}
return V_19 ;
}
int F_9 ( T_1 V_8 , T_3 * V_20 , unsigned V_21 , unsigned * V_2 ,
int * V_13 )
{
T_3 * V_22 ;
#if V_12 == 4
T_5 V_18 ;
#elif V_12 == 8
T_6 V_18 ;
#else
#error please implement for this limb size.
#endif
unsigned int V_23 = F_10 ( V_8 ) ;
int V_4 , V_19 ;
if ( ! V_20 || ! V_2 )
return - V_16 ;
if ( V_13 )
* V_13 = V_8 -> V_13 ;
V_19 = F_8 ( V_8 ) ;
if ( V_21 < V_23 - V_19 ) {
* V_2 = V_23 - V_19 ;
return - V_24 ;
}
V_22 = V_20 ;
* V_2 = V_23 - V_19 ;
for ( V_4 = V_8 -> V_7 - 1 - V_19 / V_12 ,
V_19 %= V_12 ;
V_4 >= 0 ; V_4 -- ) {
#if V_12 == 4
V_18 = F_11 ( V_8 -> V_14 [ V_4 ] ) ;
#elif V_12 == 8
V_18 = F_12 ( V_8 -> V_14 [ V_4 ] ) ;
#else
#error please implement for this limb size.
#endif
memcpy ( V_22 , ( V_25 * ) & V_18 + V_19 , V_12 - V_19 ) ;
V_22 += V_12 - V_19 ;
V_19 = 0 ;
}
return 0 ;
}
void * F_13 ( T_1 V_8 , unsigned * V_2 , int * V_13 )
{
T_3 * V_20 ;
unsigned int V_23 ;
int V_26 ;
if ( ! V_2 )
return NULL ;
V_23 = F_10 ( V_8 ) ;
if ( ! V_23 )
V_23 ++ ;
V_20 = F_14 ( V_23 , V_27 ) ;
if ( ! V_20 )
return NULL ;
V_26 = F_9 ( V_8 , V_20 , V_23 , V_2 , V_13 ) ;
if ( V_26 ) {
F_15 ( V_20 ) ;
return NULL ;
}
return V_20 ;
}
int F_16 ( T_1 V_8 , struct V_28 * V_29 , unsigned V_2 ,
int * V_13 )
{
V_25 * V_22 , * V_30 ;
#if V_12 == 4
T_5 V_18 ;
#elif V_12 == 8
T_6 V_18 ;
#else
#error please implement for this limb size.
#endif
unsigned int V_23 = F_10 ( V_8 ) ;
struct V_31 V_32 ;
int V_4 , V_33 , V_21 ;
int V_34 ;
if ( V_13 )
* V_13 = V_8 -> V_13 ;
if ( V_2 < V_23 )
return - V_24 ;
V_34 = F_17 ( V_29 , V_2 ) ;
if ( V_34 < 0 )
return - V_16 ;
F_18 ( & V_32 , V_29 , V_34 , V_35 | V_36 ) ;
F_19 ( & V_32 ) ;
V_21 = V_32 . V_37 ;
V_30 = V_32 . V_38 ;
while ( V_2 > V_23 ) {
V_4 = F_20 ( unsigned , V_2 - V_23 , V_21 ) ;
memset ( V_30 , 0 , V_4 ) ;
V_30 += V_4 ;
V_2 -= V_4 ;
V_21 -= V_4 ;
if ( ! V_21 ) {
F_19 ( & V_32 ) ;
V_21 = V_32 . V_37 ;
V_30 = V_32 . V_38 ;
}
}
for ( V_4 = V_8 -> V_7 - 1 ; V_4 >= 0 ; V_4 -- ) {
#if V_12 == 4
V_18 = V_8 -> V_14 [ V_4 ] ? F_11 ( V_8 -> V_14 [ V_4 ] ) : 0 ;
#elif V_12 == 8
V_18 = V_8 -> V_14 [ V_4 ] ? F_12 ( V_8 -> V_14 [ V_4 ] ) : 0 ;
#else
#error please implement for this limb size.
#endif
V_22 = ( V_25 * ) & V_18 ;
for ( V_33 = 0 ; V_33 < sizeof( V_18 ) ; V_33 ++ ) {
* V_30 ++ = * V_22 ++ ;
if ( ! -- V_21 ) {
F_19 ( & V_32 ) ;
V_21 = V_32 . V_37 ;
V_30 = V_32 . V_38 ;
}
}
}
F_21 ( & V_32 ) ;
return 0 ;
}
T_1 F_22 ( struct V_28 * V_29 , unsigned int V_2 )
{
struct V_31 V_32 ;
unsigned int V_6 , V_7 ;
int V_33 , V_5 , V_39 , V_19 , V_40 ;
unsigned int V_41 ;
const V_25 * V_42 ;
T_4 V_8 ;
T_1 V_9 = NULL ;
V_40 = F_17 ( V_29 , V_2 ) ;
if ( V_40 < 0 )
return NULL ;
F_18 ( & V_32 , V_29 , V_40 , V_35 | V_43 ) ;
V_19 = 0 ;
V_41 = 0 ;
while ( V_2 > 0 ) {
while ( V_41 && ! * V_42 ) {
V_19 ++ ;
V_41 -- ;
V_42 ++ ;
}
if ( V_41 && * V_42 )
break;
F_19 ( & V_32 ) ;
V_42 = V_32 . V_38 ;
V_41 = V_32 . V_37 ;
V_2 -= V_19 ;
V_19 = 0 ;
}
V_32 . V_44 = V_19 ;
V_2 -= V_19 ;
V_6 = V_2 * 8 ;
if ( V_6 > V_10 ) {
F_21 ( & V_32 ) ;
F_2 ( L_1 , V_6 ) ;
return NULL ;
}
if ( V_2 > 0 )
V_6 -= F_3 ( * V_42 ) - ( V_11 - 8 ) ;
F_21 ( & V_32 ) ;
V_7 = F_4 ( V_2 , V_12 ) ;
V_9 = F_5 ( V_7 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_6 = V_6 ;
V_9 -> V_13 = 0 ;
V_9 -> V_7 = V_7 ;
if ( V_2 == 0 )
return V_9 ;
V_5 = V_7 - 1 ;
V_8 = 0 ;
V_39 = V_12 - V_2 % V_12 ;
V_39 %= V_12 ;
while ( F_19 ( & V_32 ) ) {
V_42 = V_32 . V_38 ;
V_41 = V_32 . V_37 ;
for ( V_33 = 0 ; V_33 < V_41 ; V_33 ++ ) {
V_8 <<= 8 ;
V_8 |= * V_42 ++ ;
if ( ( ( V_39 + V_33 + 1 ) % V_12 ) == 0 ) {
V_9 -> V_14 [ V_5 -- ] = V_8 ;
V_8 = 0 ;
}
}
V_39 += V_33 ;
}
return V_9 ;
}
