static void
F_1 ( struct V_1 * V_2 , unsigned long * V_3 , int V_4 ,
unsigned long V_5 , unsigned V_6 , int V_7 )
{
unsigned long V_8 , V_9 ;
if ( ! V_6 )
return;
V_8 = F_2 ( V_2 , ~ 0UL , V_4 ) ;
V_9 = ~ ( F_2 ( V_2 , ~ 0UL , ( V_4 + V_6 ) % V_7 ) ) ;
if ( V_4 + V_6 <= V_7 ) {
if ( V_9 )
V_8 &= V_9 ;
* V_3 = F_3 ( V_5 , * V_3 , V_8 ) ;
} else {
if ( V_8 != ~ 0UL ) {
* V_3 = F_3 ( V_5 , * V_3 , V_8 ) ;
V_3 ++ ;
V_6 -= V_7 - V_4 ;
}
V_6 /= V_7 ;
while ( V_6 >= 8 ) {
* V_3 ++ = V_5 ;
* V_3 ++ = V_5 ;
* V_3 ++ = V_5 ;
* V_3 ++ = V_5 ;
* V_3 ++ = V_5 ;
* V_3 ++ = V_5 ;
* V_3 ++ = V_5 ;
* V_3 ++ = V_5 ;
V_6 -= 8 ;
}
while ( V_6 -- )
* V_3 ++ = V_5 ;
if ( V_9 )
* V_3 = F_3 ( V_5 , * V_3 , V_9 ) ;
}
}
static void
F_4 ( struct V_1 * V_2 , unsigned long * V_3 , int V_4 ,
unsigned long V_5 , int V_10 , int V_11 , unsigned V_6 , int V_7 )
{
unsigned long V_8 , V_9 ;
if ( ! V_6 )
return;
V_8 = F_2 ( V_2 , ~ 0UL , V_4 ) ;
V_9 = ~ ( F_2 ( V_2 , ~ 0UL , ( V_4 + V_6 ) % V_7 ) ) ;
if ( V_4 + V_6 <= V_7 ) {
if ( V_9 )
V_8 &= V_9 ;
* V_3 = F_3 ( V_5 , * V_3 , V_8 ) ;
} else {
if ( V_8 ) {
* V_3 = F_3 ( V_5 , * V_3 , V_8 ) ;
V_3 ++ ;
V_5 = V_5 << V_10 | V_5 >> V_11 ;
V_6 -= V_7 - V_4 ;
}
V_6 /= V_7 ;
while ( V_6 >= 4 ) {
* V_3 ++ = V_5 ;
V_5 = V_5 << V_10 | V_5 >> V_11 ;
* V_3 ++ = V_5 ;
V_5 = V_5 << V_10 | V_5 >> V_11 ;
* V_3 ++ = V_5 ;
V_5 = V_5 << V_10 | V_5 >> V_11 ;
* V_3 ++ = V_5 ;
V_5 = V_5 << V_10 | V_5 >> V_11 ;
V_6 -= 4 ;
}
while ( V_6 -- ) {
* V_3 ++ = V_5 ;
V_5 = V_5 << V_10 | V_5 >> V_11 ;
}
if ( V_9 )
* V_3 = F_3 ( V_5 , * V_3 , V_9 ) ;
}
}
static void
F_5 ( struct V_1 * V_2 , unsigned long * V_3 , int V_4 ,
unsigned long V_5 , unsigned V_6 , int V_7 )
{
unsigned long V_12 = V_5 ;
unsigned long V_8 , V_9 ;
if ( ! V_6 )
return;
V_8 = F_2 ( V_2 , ~ 0UL , V_4 ) ;
V_9 = ~ ( F_2 ( V_2 , ~ 0UL , ( V_4 + V_6 ) % V_7 ) ) ;
if ( V_4 + V_6 <= V_7 ) {
if ( V_9 )
V_8 &= V_9 ;
* V_3 = F_3 ( * V_3 ^ V_12 , * V_3 , V_8 ) ;
} else {
if ( V_8 != 0UL ) {
* V_3 = F_3 ( * V_3 ^ V_12 , * V_3 , V_8 ) ;
V_3 ++ ;
V_6 -= V_7 - V_4 ;
}
V_6 /= V_7 ;
while ( V_6 >= 8 ) {
* V_3 ++ ^= V_12 ;
* V_3 ++ ^= V_12 ;
* V_3 ++ ^= V_12 ;
* V_3 ++ ^= V_12 ;
* V_3 ++ ^= V_12 ;
* V_3 ++ ^= V_12 ;
* V_3 ++ ^= V_12 ;
* V_3 ++ ^= V_12 ;
V_6 -= 8 ;
}
while ( V_6 -- )
* V_3 ++ ^= V_12 ;
if ( V_9 )
* V_3 = F_3 ( * V_3 ^ V_12 , * V_3 , V_9 ) ;
}
}
static void
F_6 ( struct V_1 * V_2 , unsigned long * V_3 , int V_4 ,
unsigned long V_5 , int V_10 , int V_11 , unsigned V_6 ,
int V_7 )
{
unsigned long V_8 , V_9 ;
if ( ! V_6 )
return;
V_8 = F_2 ( V_2 , ~ 0UL , V_4 ) ;
V_9 = ~ ( F_2 ( V_2 , ~ 0UL , ( V_4 + V_6 ) % V_7 ) ) ;
if ( V_4 + V_6 <= V_7 ) {
if ( V_9 )
V_8 &= V_9 ;
* V_3 = F_3 ( * V_3 ^ V_5 , * V_3 , V_8 ) ;
} else {
if ( V_8 != 0UL ) {
* V_3 = F_3 ( * V_3 ^ V_5 , * V_3 , V_8 ) ;
V_3 ++ ;
V_5 = V_5 << V_10 | V_5 >> V_11 ;
V_6 -= V_7 - V_4 ;
}
V_6 /= V_7 ;
while ( V_6 >= 4 ) {
* V_3 ++ ^= V_5 ;
V_5 = V_5 << V_10 | V_5 >> V_11 ;
* V_3 ++ ^= V_5 ;
V_5 = V_5 << V_10 | V_5 >> V_11 ;
* V_3 ++ ^= V_5 ;
V_5 = V_5 << V_10 | V_5 >> V_11 ;
* V_3 ++ ^= V_5 ;
V_5 = V_5 << V_10 | V_5 >> V_11 ;
V_6 -= 4 ;
}
while ( V_6 -- ) {
* V_3 ^= V_5 ;
V_5 = V_5 << V_10 | V_5 >> V_11 ;
}
if ( V_9 )
* V_3 = F_3 ( * V_3 ^ V_5 , * V_3 , V_9 ) ;
}
}
void F_7 ( struct V_1 * V_2 , const struct V_13 * V_14 )
{
unsigned long V_5 , V_15 , V_16 ;
unsigned long V_17 = V_14 -> V_17 , V_18 = V_14 -> V_18 ;
int V_7 = V_19 , V_20 = V_7 >> 3 ;
T_1 V_21 = V_2 -> V_22 . V_23 ;
unsigned long * V_3 ;
int V_4 , V_10 ;
if ( V_2 -> V_24 != V_25 )
return;
if ( V_2 -> V_26 . V_27 == V_28 ||
V_2 -> V_26 . V_27 == V_29 )
V_16 = ( ( T_1 * ) ( V_2 -> V_30 ) ) [ V_14 -> V_31 ] ;
else
V_16 = V_14 -> V_31 ;
V_5 = F_8 ( V_21 , V_16 ) ;
V_3 = ( unsigned long * ) ( ( unsigned long ) V_2 -> V_32 & ~ ( V_20 - 1 ) ) ;
V_4 = ( ( unsigned long ) V_2 -> V_32 & ( V_20 - 1 ) ) * 8 ;
V_4 += V_14 -> V_33 * V_2 -> V_26 . V_34 * 8 + V_14 -> V_35 * V_21 ;
V_10 = V_7 % V_21 ;
if ( V_2 -> V_36 -> V_37 )
V_2 -> V_36 -> V_37 ( V_2 ) ;
if ( ! V_10 ) {
void (* F_9)( struct V_1 * V_2 , unsigned long * V_3 ,
int V_4 , unsigned long V_5 , unsigned V_6 ,
int V_7 ) = NULL ;
switch ( V_14 -> V_38 ) {
case V_39 :
F_9 = F_5 ;
break;
case V_40 :
F_9 = F_1 ;
break;
default:
F_10 ( V_41 L_1
L_2 ) ;
F_9 = F_1 ;
break;
}
while ( V_18 -- ) {
V_3 += V_4 >> ( F_11 ( V_7 ) - 1 ) ;
V_4 &= ( V_7 - 1 ) ;
F_9 ( V_2 , V_3 , V_4 , V_5 , V_17 * V_21 , V_7 ) ;
V_4 += V_2 -> V_26 . V_34 * 8 ;
}
} else {
int V_11 , V_42 ;
void (* F_12)( struct V_1 * V_2 , unsigned long * V_3 ,
int V_4 , unsigned long V_5 , int V_10 ,
int V_11 , unsigned V_6 , int V_7 ) = NULL ;
#ifdef F_13
V_11 = V_10 ;
V_10 = V_21 - V_11 ;
#else
V_11 = V_21 - V_10 ;
#endif
switch ( V_14 -> V_38 ) {
case V_39 :
F_12 = F_6 ;
break;
case V_40 :
F_12 = F_4 ;
break;
default:
F_10 ( V_41 L_3
L_2 ) ;
F_12 = F_4 ;
break;
}
while ( V_18 -- ) {
V_3 += V_4 / V_7 ;
V_4 &= ( V_7 - 1 ) ;
V_42 = V_4 % V_21 ;
V_15 = F_14 ( F_15 ( F_16 ( V_5 ) , V_42 , V_21 ) ) ;
F_12 ( V_2 , V_3 , V_4 , V_15 , V_10 , V_11 ,
V_17 * V_21 , V_7 ) ;
V_4 += V_2 -> V_26 . V_34 * 8 ;
}
}
}
