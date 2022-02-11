static T_1 F_1 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
char * V_6 = V_7 . V_8 . V_9 == V_10 ? V_11
: V_12 ;
T_1 V_13 , V_14 ;
T_2 * V_15 = & V_3 [ * V_4 ] ;
V_13 = F_2 (unsigned long, userCount, frameLeft) ;
if ( V_7 . V_8 . V_16 )
V_13 &= ~ 1 ;
V_14 = V_13 ;
while ( V_13 > 0 ) {
T_2 V_17 ;
if ( F_3 ( V_17 , V_1 ++ ) )
return - V_18 ;
* V_15 ++ = V_6 [ V_17 ] ;
V_13 -- ;
}
* V_4 += V_14 ;
return V_14 ;
}
static T_1 F_4 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
T_1 V_13 , V_14 ;
void * V_15 = & V_3 [ * V_4 ] ;
V_13 = F_2 (unsigned long, userCount, frameLeft) ;
if ( V_7 . V_8 . V_16 )
V_13 &= ~ 1 ;
V_14 = V_13 ;
if ( F_5 ( V_15 , V_1 , V_13 ) )
return - V_18 ;
* V_4 += V_14 ;
return V_14 ;
}
static T_1 F_6 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
T_1 V_13 , V_14 ;
if ( ! V_7 . V_8 . V_16 ) {
T_2 * V_15 = & V_3 [ * V_4 ] ;
V_13 = F_2 (unsigned long, userCount, frameLeft) ;
V_14 = V_13 ;
while ( V_13 > 0 ) {
T_2 V_17 ;
if ( F_3 ( V_17 , V_1 ++ ) )
return - V_18 ;
* V_15 ++ = V_17 ^ 0x80 ;
V_13 -- ;
}
} else {
T_5 * V_15 = ( T_5 * ) & V_3 [ * V_4 ] ;
V_13 = F_2 (unsigned long, userCount, frameLeft) >> 1 ;
V_14 = V_13 * 2 ;
while ( V_13 > 0 ) {
T_5 V_17 ;
if ( F_3 ( V_17 , ( T_5 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 2 ;
* V_15 ++ = V_17 ^ 0x8080 ;
V_13 -- ;
}
}
* V_4 += V_14 ;
return V_14 ;
}
static T_1 F_7 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
T_1 V_13 , V_14 ;
if ( ! V_7 . V_8 . V_16 ) {
T_5 * V_15 = ( T_5 * ) & V_3 [ * V_4 ] ;
V_13 = F_2 (unsigned long, userCount, frameLeft) >> 1 ;
V_14 = V_13 * 2 ;
while ( V_13 > 0 ) {
T_5 V_17 ;
if ( F_3 ( V_17 , ( T_5 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 2 ;
* V_15 ++ = V_17 ;
* V_15 ++ = V_17 ;
V_13 -- ;
}
* V_4 += V_14 * 2 ;
} else {
void * V_15 = ( T_5 * ) & V_3 [ * V_4 ] ;
V_13 = F_2 (unsigned long, userCount, frameLeft) & ~ 3 ;
V_14 = V_13 ;
if ( F_5 ( V_15 , V_1 , V_13 ) )
return - V_18 ;
* V_4 += V_14 ;
}
return V_14 ;
}
static T_1 F_8 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
T_1 V_13 , V_14 ;
if ( ! V_7 . V_8 . V_16 ) {
T_5 * V_15 = ( T_5 * ) & V_3 [ * V_4 ] ;
V_13 = F_2 (unsigned long, userCount, frameLeft) >> 1 ;
V_14 = V_13 * 2 ;
while ( V_13 > 0 ) {
T_5 V_17 ;
if ( F_3 ( V_17 , ( T_5 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 2 ;
V_17 ^= 0x8000 ;
* V_15 ++ = V_17 ;
* V_15 ++ = V_17 ;
V_13 -- ;
}
* V_4 += V_14 * 2 ;
} else {
T_6 * V_15 = ( T_6 * ) & V_3 [ * V_4 ] ;
V_13 = F_2 (unsigned long, userCount, frameLeft) >> 2 ;
V_14 = V_13 * 4 ;
while ( V_13 > 0 ) {
T_7 V_17 ;
if ( F_3 ( V_17 , ( T_7 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 4 ;
* V_15 ++ = V_17 ^ 0x80008000 ;
V_13 -- ;
}
* V_4 += V_14 ;
}
return V_14 ;
}
static T_1 F_9 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
T_1 V_13 , V_14 ;
V_13 = V_5 ;
if ( ! V_7 . V_8 . V_16 ) {
T_5 * V_15 = ( T_5 * ) & V_3 [ * V_4 ] ;
V_13 = F_2 (unsigned long, userCount, frameLeft) >> 1 ;
V_14 = V_13 * 2 ;
while ( V_13 > 0 ) {
T_5 V_17 ;
if ( F_3 ( V_17 , ( T_5 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 2 ;
V_17 = F_10 ( V_17 ) ;
* V_15 ++ = V_17 ;
* V_15 ++ = V_17 ;
V_13 -- ;
}
* V_4 += V_14 * 2 ;
} else {
T_6 * V_15 = ( T_6 * ) & V_3 [ * V_4 ] ;
V_13 = F_2 (unsigned long, userCount, frameLeft) >> 2 ;
V_14 = V_13 * 4 ;
while ( V_13 > 0 ) {
T_6 V_17 ;
if ( F_3 ( V_17 , ( T_7 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 4 ;
V_17 = F_11 ( V_17 ) ;
* V_15 ++ = V_17 ;
V_13 -- ;
}
* V_4 += V_14 ;
}
return V_14 ;
}
static T_1 F_12 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
T_1 V_13 , V_14 ;
V_13 = V_5 ;
if ( ! V_7 . V_8 . V_16 ) {
T_5 * V_15 = ( T_5 * ) & V_3 [ * V_4 ] ;
V_13 = F_2 (unsigned long, userCount, frameLeft) >> 1 ;
V_14 = V_13 * 2 ;
while ( V_13 > 0 ) {
T_5 V_17 ;
if ( F_3 ( V_17 , ( T_5 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 2 ;
V_17 = F_10 ( V_17 ) ^ 0x8000 ;
* V_15 ++ = V_17 ;
* V_15 ++ = V_17 ;
}
* V_4 += V_14 * 2 ;
} else {
T_6 * V_15 = ( T_6 * ) & V_3 [ * V_4 ] ;
V_13 = F_2 (unsigned long, userCount, frameLeft) >> 2 ;
V_14 = V_13 ;
while ( V_13 > 0 ) {
T_6 V_17 ;
if ( F_3 ( V_17 , ( T_7 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 4 ;
V_17 = F_11 ( V_17 ) ^ 0x80008000 ;
* V_15 ++ = V_17 ;
V_13 -- ;
}
* V_4 += V_14 ;
}
return V_14 ;
}
static T_1 F_13 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
char * V_6 = V_7 . V_8 . V_9 == V_10 ? V_11
: V_12 ;
long V_19 = V_20 ;
long V_21 = V_7 . V_22 . V_23 , V_24 = V_7 . V_8 . V_23 ;
T_1 V_14 , V_25 ;
V_14 = V_2 ;
V_25 = V_5 ;
if ( ! V_7 . V_8 . V_16 ) {
T_2 * V_15 = & V_3 [ * V_4 ] ;
T_2 V_17 = V_26 ;
while ( V_5 ) {
T_2 V_27 ;
if ( V_19 < 0 ) {
if ( ! V_2 )
break;
if ( F_3 ( V_27 , V_1 ++ ) )
return - V_18 ;
V_17 = V_6 [ V_27 ] ;
V_2 -- ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -- ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
} else {
T_5 * V_15 = ( T_5 * ) & V_3 [ * V_4 ] ;
T_5 V_17 = V_26 ;
while ( V_5 >= 2 ) {
T_2 V_27 ;
if ( V_19 < 0 ) {
if ( V_2 < 2 )
break;
if ( F_3 ( V_27 , V_1 ++ ) )
return - V_18 ;
V_17 = V_6 [ V_27 ] << 8 ;
if ( F_3 ( V_27 , V_1 ++ ) )
return - V_18 ;
V_17 |= V_6 [ V_27 ] ;
V_2 -= 2 ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -= 2 ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
}
V_20 = V_19 ;
V_14 -= V_2 ;
* V_4 += V_25 - V_5 ;
return V_14 ;
}
static T_1 F_14 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
long V_19 = V_20 ;
long V_21 = V_7 . V_22 . V_23 , V_24 = V_7 . V_8 . V_23 ;
T_1 V_14 , V_25 ;
V_14 = V_2 ;
V_25 = V_5 ;
if ( ! V_7 . V_8 . V_16 ) {
T_2 * V_15 = & V_3 [ * V_4 ] ;
T_2 V_17 = V_26 ;
while ( V_5 ) {
if ( V_19 < 0 ) {
if ( ! V_2 )
break;
if ( F_3 ( V_17 , V_1 ++ ) )
return - V_18 ;
V_2 -- ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -- ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
} else {
T_5 * V_15 = ( T_5 * ) & V_3 [ * V_4 ] ;
T_5 V_17 = V_26 ;
while ( V_5 >= 2 ) {
if ( V_19 < 0 ) {
if ( V_2 < 2 )
break;
if ( F_3 ( V_17 , ( T_5 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 2 ;
V_2 -= 2 ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -= 2 ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
}
V_20 = V_19 ;
V_14 -= V_2 ;
* V_4 += V_25 - V_5 ;
return V_14 ;
}
static T_1 F_15 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
long V_19 = V_20 ;
long V_21 = V_7 . V_22 . V_23 , V_24 = V_7 . V_8 . V_23 ;
T_1 V_14 , V_25 ;
V_14 = V_2 ;
V_25 = V_5 ;
if ( ! V_7 . V_8 . V_16 ) {
T_2 * V_15 = & V_3 [ * V_4 ] ;
T_2 V_17 = V_26 ;
while ( V_5 ) {
if ( V_19 < 0 ) {
if ( ! V_2 )
break;
if ( F_3 ( V_17 , V_1 ++ ) )
return - V_18 ;
V_17 ^= 0x80 ;
V_2 -- ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -- ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
} else {
T_5 * V_15 = ( T_5 * ) & V_3 [ * V_4 ] ;
T_5 V_17 = V_26 ;
while ( V_5 >= 2 ) {
if ( V_19 < 0 ) {
if ( V_2 < 2 )
break;
if ( F_3 ( V_17 , ( T_5 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 2 ;
V_17 ^= 0x8080 ;
V_2 -= 2 ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -= 2 ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
}
V_20 = V_19 ;
V_14 -= V_2 ;
* V_4 += V_25 - V_5 ;
return V_14 ;
}
static T_1 F_16 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
long V_19 = V_20 ;
long V_21 = V_7 . V_22 . V_23 , V_24 = V_7 . V_8 . V_23 ;
T_1 V_14 , V_25 ;
V_14 = V_2 ;
V_25 = V_5 ;
if ( ! V_7 . V_8 . V_16 ) {
T_5 * V_15 = ( T_5 * ) & V_3 [ * V_4 ] ;
T_5 V_17 = V_26 ;
while ( V_5 >= 4 ) {
if ( V_19 < 0 ) {
if ( V_2 < 2 )
break;
if ( F_3 ( V_17 , ( T_5 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 2 ;
V_2 -= 2 ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
* V_15 ++ = V_17 ;
V_5 -= 4 ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
} else {
T_6 * V_15 = ( T_6 * ) & V_3 [ * V_4 ] ;
T_6 V_17 = V_26 ;
while ( V_5 >= 4 ) {
if ( V_19 < 0 ) {
if ( V_2 < 4 )
break;
if ( F_3 ( V_17 , ( T_7 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 4 ;
V_2 -= 4 ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -= 4 ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
}
V_20 = V_19 ;
V_14 -= V_2 ;
* V_4 += V_25 - V_5 ;
return V_14 ;
}
static T_1 F_17 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
long V_19 = V_20 ;
long V_21 = V_7 . V_22 . V_23 , V_24 = V_7 . V_8 . V_23 ;
T_1 V_14 , V_25 ;
V_14 = V_2 ;
V_25 = V_5 ;
if ( ! V_7 . V_8 . V_16 ) {
T_5 * V_15 = ( T_5 * ) & V_3 [ * V_4 ] ;
T_5 V_17 = V_26 ;
while ( V_5 >= 4 ) {
if ( V_19 < 0 ) {
if ( V_2 < 2 )
break;
if ( F_3 ( V_17 , ( T_5 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 2 ;
V_17 ^= 0x8000 ;
V_2 -= 2 ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
* V_15 ++ = V_17 ;
V_5 -= 4 ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
} else {
T_6 * V_15 = ( T_6 * ) & V_3 [ * V_4 ] ;
T_6 V_17 = V_26 ;
while ( V_5 >= 4 ) {
if ( V_19 < 0 ) {
if ( V_2 < 4 )
break;
if ( F_3 ( V_17 , ( T_7 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 4 ;
V_17 ^= 0x80008000 ;
V_2 -= 4 ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -= 4 ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
}
V_20 = V_19 ;
V_14 -= V_2 ;
* V_4 += V_25 - V_5 ;
return V_14 ;
}
static T_1 F_18 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
long V_19 = V_20 ;
long V_21 = V_7 . V_22 . V_23 , V_24 = V_7 . V_8 . V_23 ;
T_1 V_14 , V_25 ;
V_14 = V_2 ;
V_25 = V_5 ;
if ( ! V_7 . V_8 . V_16 ) {
T_5 * V_15 = ( T_5 * ) & V_3 [ * V_4 ] ;
T_5 V_17 = V_26 ;
while ( V_5 >= 4 ) {
if ( V_19 < 0 ) {
if ( V_2 < 2 )
break;
if ( F_3 ( V_17 , ( T_5 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 2 ;
V_17 = F_10 ( V_17 ) ;
V_2 -= 2 ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
* V_15 ++ = V_17 ;
V_5 -= 4 ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
} else {
T_6 * V_15 = ( T_6 * ) & V_3 [ * V_4 ] ;
T_6 V_17 = V_26 ;
while ( V_5 >= 4 ) {
if ( V_19 < 0 ) {
if ( V_2 < 4 )
break;
if ( F_3 ( V_17 , ( T_7 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 4 ;
V_17 = F_11 ( V_17 ) ;
V_2 -= 4 ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -= 4 ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
}
V_20 = V_19 ;
V_14 -= V_2 ;
* V_4 += V_25 - V_5 ;
return V_14 ;
}
static T_1 F_19 ( const T_2 T_3 * V_1 , T_4 V_2 ,
T_2 V_3 [] , T_1 * V_4 ,
T_1 V_5 )
{
long V_19 = V_20 ;
long V_21 = V_7 . V_22 . V_23 , V_24 = V_7 . V_8 . V_23 ;
T_1 V_14 , V_25 ;
V_14 = V_2 ;
V_25 = V_5 ;
if ( ! V_7 . V_8 . V_16 ) {
T_5 * V_15 = ( T_5 * ) & V_3 [ * V_4 ] ;
T_5 V_17 = V_26 ;
while ( V_5 >= 4 ) {
if ( V_19 < 0 ) {
if ( V_2 < 2 )
break;
if ( F_3 ( V_17 , ( T_5 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 2 ;
V_17 = F_10 ( V_17 ) ^ 0x8000 ;
V_2 -= 2 ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
* V_15 ++ = V_17 ;
V_5 -= 4 ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
} else {
T_6 * V_15 = ( T_6 * ) & V_3 [ * V_4 ] ;
T_6 V_17 = V_26 ;
while ( V_5 >= 4 ) {
if ( V_19 < 0 ) {
if ( V_2 < 4 )
break;
if ( F_3 ( V_17 , ( T_7 T_3 * ) V_1 ) )
return - V_18 ;
V_1 += 4 ;
V_17 = F_11 ( V_17 ) ^ 0x80008000 ;
V_2 -= 4 ;
V_19 += V_21 ;
}
* V_15 ++ = V_17 ;
V_5 -= 4 ;
V_19 -= V_24 ;
}
V_26 = V_17 ;
}
V_20 = V_19 ;
V_14 -= V_2 ;
* V_4 += V_25 - V_5 ;
return V_14 ;
}
static void * F_20 ( unsigned int V_28 , T_8 V_29 )
{
return F_21 ( V_28 , L_1 ) ;
}
static void F_22 ( void * V_30 , unsigned int V_28 )
{
F_23 ( V_30 ) ;
}
static int T_9 F_24 ( void )
{
V_31 . V_32 = 0 ;
V_31 . V_33 = 1 ;
V_31 . V_32 = 8 ;
if ( F_25 ( V_34 , V_35 , V_36 , L_2 ,
V_35 ) )
return 0 ;
V_31 . V_37 |= 0x20 ;
V_31 . V_38 |= 0x20 ;
return 1 ;
}
static void F_26 ( void )
{
V_31 . V_32 = 0 ;
V_31 . V_37 &= ~ 0x20 ;
F_27 ( V_34 , V_35 ) ;
}
static int F_28 ( int V_39 )
{
V_7 . V_39 = F_29 ( V_39 ) ;
F_30 ( F_31 ( V_7 . V_39 ) ) ;
return F_32 ( V_7 . V_39 ) ;
}
static int F_33 ( int V_40 )
{
V_7 . V_40 = F_29 ( V_40 ) ;
F_30 ( F_34 ( V_7 . V_40 ) ) ;
return F_32 ( V_7 . V_40 ) ;
}
static void F_35 ( void )
{
V_41 . V_42 = V_43 ;
F_30 ( V_44 ) ;
}
static void F_36 ( void )
{
int V_45 , V_46 , V_47 ;
const int V_48 [ 4 ] = { 50066 , 25033 , 12517 , 6258 } ;
V_47 = - 1 ;
for ( V_46 = 0 ; V_46 < F_37 ( V_48 ) ; V_46 ++ )
if ( ( 100 * abs ( V_7 . V_8 . V_23 - V_48 [ V_46 ] ) / V_48 [ V_46 ] ) < V_49 )
V_47 = V_46 ;
if ( V_47 > - 1 ) {
V_7 . V_8 . V_23 = V_48 [ V_47 ] ;
V_7 . V_50 = & V_51 ;
} else
V_7 . V_50 = & V_52 ;
F_35 () ;
V_7 . V_22 = V_7 . V_8 ;
if ( V_7 . V_22 . V_23 > 50066 ) {
V_7 . V_22 . V_23 = 50066 ;
V_45 = V_53 ;
V_7 . V_50 = & V_51 ;
} else if ( V_7 . V_22 . V_23 > 25033 ) {
V_7 . V_22 . V_23 = 50066 ;
V_45 = V_53 ;
} else if ( V_7 . V_22 . V_23 > 12517 ) {
V_7 . V_22 . V_23 = 25033 ;
V_45 = V_54 ;
} else if ( V_7 . V_22 . V_23 > 6258 ) {
V_7 . V_22 . V_23 = 12517 ;
V_45 = V_55 ;
} else {
V_7 . V_22 . V_23 = 6258 ;
V_45 = V_56 ;
}
V_41 . V_45 = ( V_7 . V_22 . V_16 ?
V_57 : V_58 ) |
V_59 | V_45 ;
V_20 = - V_7 . V_8 . V_23 ;
}
static int F_38 ( int V_9 )
{
switch ( V_9 ) {
case V_60 :
return V_7 . V_8 . V_9 ;
case V_10 :
case V_61 :
case V_62 :
case V_63 :
break;
default:
V_9 = V_62 ;
}
V_7 . V_8 . V_9 = V_9 ;
V_7 . V_8 . V_28 = 8 ;
if ( V_7 . V_64 == V_65 ) {
V_7 . V_66 . V_9 = V_9 ;
V_7 . V_66 . V_28 = 8 ;
}
F_36 () ;
return V_9 ;
}
static int F_39 ( int V_67 )
{
V_7 . V_68 = F_40 ( V_67 & 0xff ) ;
F_30 ( F_41 ( V_7 . V_68 ) ) ;
V_7 . V_69 = F_40 ( ( V_67 & 0xff00 ) >> 8 ) ;
F_30 ( F_42 ( V_7 . V_69 ) ) ;
return F_43 ( V_7 . V_68 ) |
( F_43 ( V_7 . V_69 ) << 8 ) ;
}
static int F_44 ( int V_70 )
{
V_7 . V_70 = F_45 ( V_70 ) ;
F_30 ( F_46 ( V_7 . V_70 ) ) ;
return F_47 ( V_7 . V_70 ) ;
}
static void F_48 ( void )
{
V_41 . V_42 = V_43 ;
V_41 . V_45 = V_53 | V_57 | V_59 ;
V_41 . V_71 = 0 ;
V_41 . V_72 = 0x0 ;
V_41 . V_73 = 0x0000 ;
V_41 . V_74 = 0x0000 ;
V_41 . V_75 = 1 ;
V_41 . V_76 = 3 ;
}
static void F_49 ( void )
{
int V_77 , V_46 , V_47 ;
const int V_48 [ 8 ] = { 49170 , 32780 , 24585 , 19668 , 16390 , 12292 , 9834 , 8195 } ;
V_47 = - 1 ;
for ( V_46 = 0 ; V_46 < F_37 ( V_48 ) ; V_46 ++ )
if ( ( 100 * abs ( V_7 . V_8 . V_23 - V_48 [ V_46 ] ) / V_48 [ V_46 ] ) < V_49 )
V_47 = V_46 ;
if ( V_47 > - 1 ) {
V_7 . V_8 . V_23 = V_48 [ V_47 ] ;
V_7 . V_50 = & V_78 ;
} else
V_7 . V_50 = & V_79 ;
F_48 () ;
V_7 . V_22 = V_7 . V_8 ;
if ( V_7 . V_22 . V_28 == 16 ) {
V_7 . V_22 . V_16 = 1 ;
}
if ( V_7 . V_22 . V_23 > 49170 ) {
V_7 . V_22 . V_23 = 49170 ;
V_77 = 1 ;
V_7 . V_50 = & V_78 ;
} else if ( V_7 . V_22 . V_23 > 32780 ) {
V_7 . V_22 . V_23 = 49170 ;
V_77 = 1 ;
} else if ( V_7 . V_22 . V_23 > 24585 ) {
V_7 . V_22 . V_23 = 32780 ;
V_77 = 2 ;
} else if ( V_7 . V_22 . V_23 > 19668 ) {
V_7 . V_22 . V_23 = 24585 ;
V_77 = 3 ;
} else if ( V_7 . V_22 . V_23 > 16390 ) {
V_7 . V_22 . V_23 = 19668 ;
V_77 = 4 ;
} else if ( V_7 . V_22 . V_23 > 12292 ) {
V_7 . V_22 . V_23 = 16390 ;
V_77 = 5 ;
} else if ( V_7 . V_22 . V_23 > 9834 ) {
V_7 . V_22 . V_23 = 12292 ;
V_77 = 7 ;
} else if ( V_7 . V_22 . V_23 > 8195 ) {
V_7 . V_22 . V_23 = 9834 ;
V_77 = 9 ;
} else {
V_7 . V_22 . V_23 = 8195 ;
V_77 = 11 ;
}
V_41 . V_71 = V_77 ;
V_41 . V_72 = 0x4 ;
V_41 . V_80 = 0x0 ;
V_41 . V_73 = 0x0001 ;
V_41 . V_74 = 0x0000 ;
V_41 . V_81 = 0 ;
V_41 . V_75 = 2 ;
V_41 . V_76 = 0 ;
V_41 . V_45 = ( V_7 . V_22 . V_16 ?
V_57 : V_58 ) |
( ( V_7 . V_22 . V_28 == 8 ) ?
V_59 : V_82 ) |
V_56 ;
V_20 = - V_7 . V_8 . V_23 ;
}
static int F_50 ( int V_9 )
{
int V_28 ;
switch ( V_9 ) {
case V_60 :
return V_7 . V_8 . V_9 ;
case V_10 :
case V_61 :
case V_63 :
case V_62 :
V_28 = 8 ;
break;
case V_83 :
case V_84 :
case V_85 :
case V_86 :
V_28 = 16 ;
break;
default:
V_28 = 8 ;
V_9 = V_62 ;
}
V_7 . V_8 . V_9 = V_9 ;
V_7 . V_8 . V_28 = V_28 ;
if ( V_7 . V_64 == V_65 ) {
V_7 . V_66 . V_9 = V_9 ;
V_7 . V_66 . V_28 = V_7 . V_8 . V_28 ;
}
F_49 () ;
return V_9 ;
}
static int F_51 ( int V_67 )
{
V_7 . V_68 = F_52 ( V_67 & 0xff ) ;
V_7 . V_69 = F_52 ( ( V_67 & 0xff00 ) >> 8 ) ;
V_41 . V_87 = V_7 . V_68 << 8 | V_7 . V_69 << 4 ;
return F_53 ( V_7 . V_68 ) |
F_53 ( V_7 . V_69 ) << 8 ;
}
static void F_54 ( int V_88 )
{
char * V_89 , * V_90 ;
V_89 = V_91 . V_92 [ V_91 . V_93 ] ;
V_90 = V_89 + ( ( V_91 . V_13 == V_88 ) ? V_91 . V_94
: V_91 . V_95 ) ;
F_55 ( F_56 ( V_90 - 1 ) + 1 ) ;
F_57 ( F_56 ( V_89 ) ) ;
V_91 . V_93 = ( V_91 . V_93 + 1 ) % V_91 . V_96 ;
V_91 . V_97 ++ ;
V_41 . V_42 = V_98 | V_99 ;
}
static void F_58 ( void )
{
F_59 ( V_34 ) ;
if ( V_91 . V_97 == 2 ||
V_91 . V_13 <= 0 ) {
F_60 ( V_34 ) ;
return;
}
if ( V_91 . V_97 == 0 ) {
if ( V_91 . V_13 == 1 &&
V_91 . V_94 < V_91 . V_95 &&
! V_91 . V_100 ) {
F_60 ( V_34 ) ;
return;
}
F_54 ( 1 ) ;
if ( V_91 . V_13 == 1 ) {
F_60 ( V_34 ) ;
return;
}
if ( V_91 . V_13 == 2 &&
V_91 . V_94 < V_91 . V_95 &&
! V_91 . V_100 ) {
F_60 ( V_34 ) ;
return;
}
F_54 ( 2 ) ;
} else {
if ( V_91 . V_13 == 2 &&
V_91 . V_94 < V_91 . V_95 &&
! V_91 . V_100 ) {
F_60 ( V_34 ) ;
return;
}
F_54 ( 2 ) ;
}
F_60 ( V_34 ) ;
}
static T_10 V_35 ( int V_101 , void * V_102 )
{
#if 0
static int cnt;
if (write_sq.active == 2)
if (++cnt == 10) {
cnt = 0;
return IRQ_HANDLED;
}
#endif
F_61 ( & V_7 . V_103 ) ;
if ( V_104 && V_105 ) {
V_104 = 0 ;
goto V_106;
}
if ( ! V_91 . V_97 ) {
F_62 ( V_91 . V_107 ) ;
goto V_106;
}
V_91 . V_13 -- ;
V_91 . V_97 -- ;
if ( ! V_91 . V_97 ) {
V_41 . V_42 = V_43 ;
V_104 = 1 ;
}
F_62 ( V_91 . V_108 ) ;
if ( ( V_91 . V_97 != 1 ) || ( V_91 . V_13 != 1 ) )
F_58 () ;
if ( ! V_91 . V_97 ) F_62 ( V_91 . V_107 ) ;
V_106:
F_63 ( & V_7 . V_103 ) ;
return V_109 ;
}
static void T_9 F_64 ( void )
{
F_30 ( F_46 ( 0 ) ) ;
V_7 . V_68 = 0 ;
F_30 ( F_41 ( 0 ) ) ;
V_7 . V_69 = 0 ;
F_30 ( F_42 ( 0 ) ) ;
F_30 ( F_34 ( 0 ) ) ;
F_30 ( F_31 ( 0 ) ) ;
}
static void T_9 F_65 ( void )
{
V_7 . V_68 = ( V_41 . V_87 & 0xf00 ) >> 8 ;
V_7 . V_69 = ( V_41 . V_87 & 0xf0 ) >> 4 ;
}
static int F_66 ( T_7 V_110 , T_6 V_111 )
{
int V_17 ;
unsigned long V_29 ;
switch ( V_110 ) {
case V_112 :
if ( V_105 || V_113 ) {
int V_114 ;
F_67 ( & V_7 . V_103 , V_29 ) ;
V_115 . V_116 = 14 ;
V_114 = V_115 . V_116 ;
F_68 ( & V_7 . V_103 , V_29 ) ;
return F_69 ( V_111 , V_114 & 0x40 ? 0 : 100 ) ;
}
break;
case V_117 :
F_70 ( V_111 , V_17 ) ;
return F_69 ( V_111 , F_71 ( V_17 ) ) ;
case V_118 :
if ( V_105 || V_113 ) {
int V_114 ;
F_70 ( V_111 , V_17 ) ;
F_67 ( & V_7 . V_103 , V_29 ) ;
V_115 . V_116 = 14 ;
V_114 = ( V_115 . V_116 & ~ 0x40 ) |
( V_17 < 50 ? 0x40 : 0 ) ;
V_115 . V_119 = V_114 ;
F_68 ( & V_7 . V_103 , V_29 ) ;
return F_69 ( V_111 , V_114 & 0x40 ? 0 : 100 ) ;
}
}
return - V_120 ;
}
static int F_72 ( T_7 V_110 , T_6 V_111 )
{
int V_17 ;
switch ( V_110 ) {
case V_121 :
return F_69 ( V_111 , 0 ) ;
case V_122 :
return F_69 ( V_111 ,
V_123 | V_124 | V_125 |
( V_113 ? V_126 : 0 ) ) ;
case V_127 :
return F_69 ( V_111 , V_123 ) ;
case V_128 :
return F_69 ( V_111 ,
F_43 ( V_7 . V_68 ) |
( F_43 ( V_7 . V_69 ) << 8 ) ) ;
case V_129 :
return F_69 ( V_111 , F_32 ( V_7 . V_39 ) ) ;
case V_130 :
return F_69 ( V_111 , F_32 ( V_7 . V_40 ) ) ;
case V_131 :
return F_69 ( V_111 , F_47 ( V_7 . V_70 ) ) ;
case V_132 :
F_70 ( V_111 , V_17 ) ;
return F_69 ( V_111 , F_73 ( V_17 ) ) ;
case V_133 :
F_70 ( V_111 , V_17 ) ;
return F_69 ( V_111 , F_74 ( V_17 ) ) ;
case V_134 :
F_70 ( V_111 , V_17 ) ;
return F_69 ( V_111 , F_75 ( V_17 ) ) ;
}
return F_66 ( V_110 , V_111 ) ;
}
static int F_76 ( T_7 V_110 , T_6 V_111 )
{
int V_17 ;
switch ( V_110 ) {
case V_121 :
return F_69 ( V_111 , V_135 ) ;
case V_122 :
return F_69 ( V_111 , V_123 | V_135 | V_126 ) ;
case V_127 :
return F_69 ( V_111 , V_123 | V_135 ) ;
case V_128 :
return F_69 ( V_111 ,
F_53 ( V_7 . V_68 ) |
F_53 ( V_7 . V_69 ) << 8 ) ;
case V_136 :
return F_69 ( V_111 , V_137 ) ;
case V_138 :
F_70 ( V_111 , V_17 ) ;
V_41 . V_139 =
F_77 ( V_17 & 0xff ) << 4 |
F_77 ( V_17 >> 8 & 0xff ) ;
case V_140 :
return F_69 ( V_111 ,
F_78 ( V_41 . V_139 >> 4 & 0xf ) |
F_78 ( V_41 . V_139 & 0xf ) << 8 ) ;
}
return F_66 ( V_110 , V_111 ) ;
}
static int F_79 ( void )
{
V_104 = 0 ;
return 0 ;
}
static int F_80 ( T_11 V_45 )
{
V_104 = 1 ;
return 0 ;
}
static int F_81 ( char * V_141 , T_4 V_142 )
{
int V_143 = 0 ;
V_143 += sprintf ( V_141 + V_143 , L_3 ,
V_7 . V_68 ) ;
V_143 += sprintf ( V_141 + V_143 , L_4 ,
V_7 . V_69 ) ;
V_143 += sprintf ( V_141 + V_143 , L_5 ,
V_7 . V_39 ) ;
V_143 += sprintf ( V_141 + V_143 , L_6 ,
V_7 . V_40 ) ;
if ( V_143 >= V_142 ) {
F_82 ( V_144 L_7 ) ;
V_143 = V_142 ;
}
return V_143 ;
}
static int F_83 ( char * V_141 , T_4 V_142 )
{
int V_143 = 0 ;
V_143 += sprintf ( V_141 + V_143 , L_8 ,
V_7 . V_68 ) ;
V_143 += sprintf ( V_141 + V_143 , L_9 ,
V_7 . V_69 ) ;
if ( V_143 >= V_142 ) {
F_82 ( V_144 L_7 ) ;
V_143 = V_142 ;
}
return V_143 ;
}
static int T_9 F_84 ( void )
{
if ( V_145 && F_85 ( V_146 ) ) {
if ( F_85 ( V_147 ) ) {
V_7 . V_148 = V_149 ;
V_7 . V_148 . V_150 = V_151 ;
V_7 . V_148 . V_152 = V_153 ;
V_105 = 1 ;
} else if ( F_85 ( V_154 ) ) {
V_7 . V_148 = V_155 ;
V_7 . V_148 . V_150 = V_151 ;
V_7 . V_148 . V_152 = V_156 ;
V_105 = 0 ;
} else
return - V_157 ;
if ( ( V_31 . V_37 & V_31 . V_38 & 0x20 ) == 0 )
return F_86 () ;
else {
F_82 ( L_10 ) ;
return - V_158 ;
}
}
return - V_157 ;
}
static void T_12 F_87 ( void )
{
F_88 () ;
}
