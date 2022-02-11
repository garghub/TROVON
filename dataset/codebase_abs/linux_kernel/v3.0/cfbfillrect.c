static void
F_1 ( struct V_1 * V_2 , unsigned long T_1 * V_3 , int V_4 ,
unsigned long V_5 , unsigned V_6 , int V_7 , T_2 V_8 )
{
unsigned long V_9 , V_10 ;
if ( ! V_6 )
return;
V_9 = F_2 ( V_2 , V_4 , V_8 ) ;
V_10 = ~ F_2 ( V_2 , ( V_4 + V_6 ) % V_7 , V_8 ) ;
if ( V_4 + V_6 <= V_7 ) {
if ( V_10 )
V_9 &= V_10 ;
F_3 ( F_4 ( V_5 , F_5 ( V_3 ) , V_9 ) , V_3 ) ;
} else {
if ( V_9 != ~ 0UL ) {
F_3 ( F_4 ( V_5 , F_5 ( V_3 ) , V_9 ) , V_3 ) ;
V_3 ++ ;
V_6 -= V_7 - V_4 ;
}
V_6 /= V_7 ;
while ( V_6 >= 8 ) {
F_3 ( V_5 , V_3 ++ ) ;
F_3 ( V_5 , V_3 ++ ) ;
F_3 ( V_5 , V_3 ++ ) ;
F_3 ( V_5 , V_3 ++ ) ;
F_3 ( V_5 , V_3 ++ ) ;
F_3 ( V_5 , V_3 ++ ) ;
F_3 ( V_5 , V_3 ++ ) ;
F_3 ( V_5 , V_3 ++ ) ;
V_6 -= 8 ;
}
while ( V_6 -- )
F_3 ( V_5 , V_3 ++ ) ;
if ( V_10 )
F_3 ( F_4 ( V_5 , F_5 ( V_3 ) , V_10 ) , V_3 ) ;
}
}
static void
F_6 ( struct V_1 * V_2 , unsigned long T_1 * V_3 , int V_4 ,
unsigned long V_5 , int V_11 , int V_12 , unsigned V_6 , int V_7 )
{
unsigned long V_9 , V_10 ;
if ( ! V_6 )
return;
V_9 = F_7 ( V_2 , ~ 0UL , V_4 ) ;
V_10 = ~ ( F_7 ( V_2 , ~ 0UL , ( V_4 + V_6 ) % V_7 ) ) ;
if ( V_4 + V_6 <= V_7 ) {
if ( V_10 )
V_9 &= V_10 ;
F_3 ( F_4 ( V_5 , F_5 ( V_3 ) , V_9 ) , V_3 ) ;
} else {
if ( V_9 ) {
F_3 ( F_4 ( V_5 , F_5 ( V_3 ) , V_9 ) , V_3 ) ;
V_3 ++ ;
V_5 = V_5 << V_11 | V_5 >> V_12 ;
V_6 -= V_7 - V_4 ;
}
V_6 /= V_7 ;
while ( V_6 >= 4 ) {
F_3 ( V_5 , V_3 ++ ) ;
V_5 = V_5 << V_11 | V_5 >> V_12 ;
F_3 ( V_5 , V_3 ++ ) ;
V_5 = V_5 << V_11 | V_5 >> V_12 ;
F_3 ( V_5 , V_3 ++ ) ;
V_5 = V_5 << V_11 | V_5 >> V_12 ;
F_3 ( V_5 , V_3 ++ ) ;
V_5 = V_5 << V_11 | V_5 >> V_12 ;
V_6 -= 4 ;
}
while ( V_6 -- ) {
F_3 ( V_5 , V_3 ++ ) ;
V_5 = V_5 << V_11 | V_5 >> V_12 ;
}
if ( V_10 )
F_3 ( F_4 ( V_5 , F_5 ( V_3 ) , V_10 ) , V_3 ) ;
}
}
static void
F_8 ( struct V_1 * V_2 , unsigned long T_1 * V_3 ,
int V_4 , unsigned long V_5 , unsigned V_6 , int V_7 ,
T_2 V_8 )
{
unsigned long V_13 = V_5 , V_14 ;
unsigned long V_9 , V_10 ;
if ( ! V_6 )
return;
V_9 = F_2 ( V_2 , V_4 , V_8 ) ;
V_10 = ~ F_2 ( V_2 , ( V_4 + V_6 ) % V_7 , V_8 ) ;
if ( V_4 + V_6 <= V_7 ) {
if ( V_10 )
V_9 &= V_10 ;
V_14 = F_5 ( V_3 ) ;
F_3 ( F_4 ( V_14 ^ V_13 , V_14 , V_9 ) , V_3 ) ;
} else {
if ( V_9 != 0UL ) {
V_14 = F_5 ( V_3 ) ;
F_3 ( F_4 ( V_14 ^ V_13 , V_14 , V_9 ) , V_3 ) ;
V_3 ++ ;
V_6 -= V_7 - V_4 ;
}
V_6 /= V_7 ;
while ( V_6 >= 8 ) {
F_3 ( F_5 ( V_3 ) ^ V_13 , V_3 ) ;
V_3 ++ ;
F_3 ( F_5 ( V_3 ) ^ V_13 , V_3 ) ;
V_3 ++ ;
F_3 ( F_5 ( V_3 ) ^ V_13 , V_3 ) ;
V_3 ++ ;
F_3 ( F_5 ( V_3 ) ^ V_13 , V_3 ) ;
V_3 ++ ;
F_3 ( F_5 ( V_3 ) ^ V_13 , V_3 ) ;
V_3 ++ ;
F_3 ( F_5 ( V_3 ) ^ V_13 , V_3 ) ;
V_3 ++ ;
F_3 ( F_5 ( V_3 ) ^ V_13 , V_3 ) ;
V_3 ++ ;
F_3 ( F_5 ( V_3 ) ^ V_13 , V_3 ) ;
V_3 ++ ;
V_6 -= 8 ;
}
while ( V_6 -- ) {
F_3 ( F_5 ( V_3 ) ^ V_13 , V_3 ) ;
V_3 ++ ;
}
if ( V_10 ) {
V_14 = F_5 ( V_3 ) ;
F_3 ( F_4 ( V_14 ^ V_13 , V_14 , V_10 ) , V_3 ) ;
}
}
}
static void
F_9 ( struct V_1 * V_2 , unsigned long T_1 * V_3 ,
int V_4 , unsigned long V_5 , int V_11 , int V_12 ,
unsigned V_6 , int V_7 )
{
unsigned long V_9 , V_10 , V_14 ;
if ( ! V_6 )
return;
V_9 = F_7 ( V_2 , ~ 0UL , V_4 ) ;
V_10 = ~ ( F_7 ( V_2 , ~ 0UL , ( V_4 + V_6 ) % V_7 ) ) ;
if ( V_4 + V_6 <= V_7 ) {
if ( V_10 )
V_9 &= V_10 ;
V_14 = F_5 ( V_3 ) ;
F_3 ( F_4 ( V_14 ^ V_5 , V_14 , V_9 ) , V_3 ) ;
} else {
if ( V_9 != 0UL ) {
V_14 = F_5 ( V_3 ) ;
F_3 ( F_4 ( V_14 ^ V_5 , V_14 , V_9 ) , V_3 ) ;
V_3 ++ ;
V_5 = V_5 << V_11 | V_5 >> V_12 ;
V_6 -= V_7 - V_4 ;
}
V_6 /= V_7 ;
while ( V_6 >= 4 ) {
F_3 ( F_5 ( V_3 ) ^ V_5 , V_3 ) ;
V_3 ++ ;
V_5 = V_5 << V_11 | V_5 >> V_12 ;
F_3 ( F_5 ( V_3 ) ^ V_5 , V_3 ) ;
V_3 ++ ;
V_5 = V_5 << V_11 | V_5 >> V_12 ;
F_3 ( F_5 ( V_3 ) ^ V_5 , V_3 ) ;
V_3 ++ ;
V_5 = V_5 << V_11 | V_5 >> V_12 ;
F_3 ( F_5 ( V_3 ) ^ V_5 , V_3 ) ;
V_3 ++ ;
V_5 = V_5 << V_11 | V_5 >> V_12 ;
V_6 -= 4 ;
}
while ( V_6 -- ) {
F_3 ( F_5 ( V_3 ) ^ V_5 , V_3 ) ;
V_3 ++ ;
V_5 = V_5 << V_11 | V_5 >> V_12 ;
}
if ( V_10 ) {
V_14 = F_5 ( V_3 ) ;
F_3 ( F_4 ( V_14 ^ V_5 , V_14 , V_10 ) , V_3 ) ;
}
}
}
void F_10 ( struct V_1 * V_2 , const struct V_15 * V_16 )
{
unsigned long V_5 , V_17 , V_18 ;
unsigned long V_19 = V_16 -> V_19 , V_20 = V_16 -> V_20 ;
int V_7 = V_21 , V_22 = V_7 >> 3 ;
T_2 V_23 = V_2 -> V_24 . V_25 ;
unsigned long T_1 * V_3 ;
int V_4 , V_11 ;
if ( V_2 -> V_26 != V_27 )
return;
if ( V_2 -> V_28 . V_29 == V_30 ||
V_2 -> V_28 . V_29 == V_31 )
V_18 = ( ( T_2 * ) ( V_2 -> V_32 ) ) [ V_16 -> V_33 ] ;
else
V_18 = V_16 -> V_33 ;
V_5 = F_11 ( V_23 , V_18 ) ;
V_3 = ( unsigned long T_1 * ) ( ( unsigned long ) V_2 -> V_34 & ~ ( V_22 - 1 ) ) ;
V_4 = ( ( unsigned long ) V_2 -> V_34 & ( V_22 - 1 ) ) * 8 ;
V_4 += V_16 -> V_35 * V_2 -> V_28 . V_36 * 8 + V_16 -> V_37 * V_23 ;
V_11 = V_7 % V_23 ;
if ( V_2 -> V_38 -> V_39 )
V_2 -> V_38 -> V_39 ( V_2 ) ;
if ( ! V_11 ) {
T_2 V_8 = F_12 ( V_2 ) ;
void (* F_13)( struct V_1 * V_2 ,
unsigned long T_1 * V_3 , int V_4 ,
unsigned long V_5 , unsigned V_6 , int V_7 ,
T_2 V_8 ) = NULL ;
switch ( V_16 -> V_40 ) {
case V_41 :
F_13 = F_8 ;
break;
case V_42 :
F_13 = F_1 ;
break;
default:
F_14 ( V_43 L_1 ) ;
F_13 = F_1 ;
break;
}
while ( V_20 -- ) {
V_3 += V_4 >> ( F_15 ( V_7 ) - 1 ) ;
V_4 &= ( V_7 - 1 ) ;
F_13 ( V_2 , V_3 , V_4 , V_5 , V_19 * V_23 , V_7 ,
V_8 ) ;
V_4 += V_2 -> V_28 . V_36 * 8 ;
}
} else {
int V_12 , V_44 ;
void (* F_16)( struct V_1 * V_2 , unsigned long T_1 * V_3 ,
int V_4 , unsigned long V_5 , int V_11 ,
int V_12 , unsigned V_6 , int V_7 ) = NULL ;
#ifdef F_17
V_12 = V_11 ;
V_11 = V_23 - V_12 ;
#else
V_12 = V_23 - V_11 ;
#endif
switch ( V_16 -> V_40 ) {
case V_41 :
F_16 = F_9 ;
break;
case V_42 :
F_16 = F_6 ;
break;
default:
F_14 ( V_43 L_1 ) ;
F_16 = F_6 ;
break;
}
while ( V_20 -- ) {
V_3 += V_4 / V_7 ;
V_4 &= ( V_7 - 1 ) ;
V_44 = V_4 % V_23 ;
V_17 = F_18 ( F_19 ( F_20 ( V_5 ) , V_44 , V_23 ) ) ;
F_16 ( V_2 , V_3 , V_4 , V_17 , V_11 , V_12 ,
V_19 * V_23 , V_7 ) ;
V_4 += V_2 -> V_28 . V_36 * 8 ;
}
}
}
