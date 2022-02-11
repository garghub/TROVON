static INLINE void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
int V_6 ;
V_4 -> V_7 = V_5 ;
if ( V_4 -> V_8 <= V_5 ) {
return;
}
V_6 = V_4 -> V_8 - V_5 ;
V_4 -> V_8 -= V_6 ;
V_2 -> V_9 += V_6 ;
}
static void F_2 ( void * V_10 ,
struct V_3 * V_11 ,
int V_12 )
{
struct V_3 * V_13 ;
int V_14 ;
struct V_1 * V_2 = (struct V_1 * ) V_10 ;
V_2 -> V_9 = V_12 ;
V_2 -> V_15 = V_12 ;
V_13 = V_11 ;
while ( V_13 != NULL ) {
V_13 -> V_16 = V_13 -> V_17 ;
#ifdef F_3
if ( V_12 > 4 )
{
if ( ( V_13 -> V_18 == V_19 ) || ( V_13 -> V_18 == V_20 ) ) {
F_4 ( V_2 , V_13 , V_13 -> V_16 ) ;
F_5 ( V_13 ) ;
}
}
#endif
if ( V_13 -> V_18 == V_21 ) {
F_4 ( V_2 , V_13 , V_13 -> V_16 ) ;
F_5 ( V_13 ) ;
} else if ( V_13 -> V_18 == V_19 ) {
V_2 -> V_22 = V_13 ;
}
V_13 = V_13 -> V_23 ;
}
if ( V_2 -> V_9 <= 0 ) {
F_6 ( V_24 , ( L_1 , V_12 ) ) ;
F_7 ( false ) ;
return;
}
V_13 = V_11 ;
while ( V_13 != NULL ) {
if ( V_13 -> V_18 == V_21 ) {
V_13 -> V_25 = V_13 -> V_17 ;
} else {
V_14 = ( V_2 -> V_9 / V_13 -> V_17 ) * V_13 -> V_17 ;
V_14 = ( V_14 * 3 ) >> 2 ;
V_14 = F_8 ( V_14 , V_13 -> V_17 ) ;
V_13 -> V_25 = V_14 ;
}
V_13 = V_13 -> V_23 ;
}
}
static void F_9 ( void * V_10 ,
struct V_3 * V_26 ,
T_1 V_27 )
{
struct V_3 * V_13 ;
struct V_1 * V_2 = (struct V_1 * ) V_10 ;
switch ( V_27 ) {
case V_28 :
V_13 = V_26 ;
while ( V_13 != NULL ) {
if ( V_13 -> V_29 > 0 ) {
V_13 -> V_8 += V_13 -> V_29 ;
V_13 -> V_29 = 0 ;
if ( V_13 -> V_8 > V_13 -> V_7 ) {
F_1 ( V_2 , V_13 , V_13 -> V_7 ) ;
}
if ( V_13 -> V_8 > V_13 -> V_25 ) {
F_1 ( V_2 , V_13 , V_13 -> V_25 ) ;
}
if ( ! F_10 ( V_13 ) ) {
if ( V_13 -> V_30 == 0 ) {
F_1 ( V_2 , V_13 , 0 ) ;
}
}
}
V_13 = V_13 -> V_23 ;
}
break;
case V_31 :
F_11 ( V_2 , V_26 ) ;
break;
case V_32 :
F_12 ( V_2 , V_26 ) ;
break;
case V_33 :
F_6 ( V_34 , ( L_2 ,
V_2 -> V_15 , V_2 -> V_9 ) ) ;
break;
default:
break;
}
F_7 ( V_2 -> V_9 <= V_2 -> V_15 ) ;
F_7 ( V_2 -> V_9 >= 0 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_26 )
{
struct V_3 * V_13 = V_26 ;
while ( V_13 != NULL ) {
#ifdef F_3
if ( ( V_13 -> V_18 == V_19 ) || ( V_13 -> V_18 == V_20 ) ) {
F_5 ( V_13 ) ;
}
#endif
if ( V_13 -> V_18 != V_21 ) {
if ( ! F_10 ( V_13 ) ) {
if ( V_13 -> V_30 == 0 ) {
F_1 ( V_2 , V_13 , 0 ) ;
} else {
F_1 ( V_2 , V_13 , V_13 -> V_16 ) ;
}
}
}
V_13 = V_13 -> V_23 ;
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_35 )
{
struct V_3 * V_13 ;
int V_6 = 0 ;
int V_36 ;
do {
if ( V_35 -> V_18 == V_21 ) {
break;
}
#ifdef F_3
if ( V_35 -> V_18 == V_37 ) {
if ( ( V_35 -> V_7 >= V_35 -> V_25 ) ) {
break;
}
}
if ( V_35 -> V_18 == V_38 ) {
if ( ( V_35 -> V_7 >= V_35 -> V_25 ) ) {
break;
}
}
#else
if ( V_35 -> V_18 == V_37 ) {
if ( ( V_35 -> V_7 >= V_35 -> V_25 ) ||
( V_2 -> V_9 <= V_35 -> V_17 ) ) {
break;
}
}
if ( V_35 -> V_18 == V_38 ) {
if ( ( V_35 -> V_7 >= V_35 -> V_25 ) ||
( V_2 -> V_9 <= V_35 -> V_17 ) ) {
break;
}
}
#endif
V_6 = F_13 ( V_2 -> V_9 , V_35 -> V_39 ) ;
if ( V_6 >= V_35 -> V_39 ) {
break;
}
V_13 = V_2 -> V_22 ;
while ( V_13 != V_35 ) {
V_36 = V_35 -> V_39 - V_2 -> V_9 ;
if ( ( V_13 -> V_7 - V_36 ) >= V_13 -> V_16 ) {
F_1 ( V_2 ,
V_13 ,
V_13 -> V_7 - V_36 ) ;
if ( V_2 -> V_9 >= V_35 -> V_39 ) {
break;
}
}
V_13 = V_13 -> V_40 ;
}
V_6 = F_13 ( V_2 -> V_9 , V_35 -> V_39 ) ;
} while ( false );
if ( V_6 ) {
F_4 ( V_2 , V_35 , V_6 ) ;
}
}
int F_14 ( T_2 V_41 , struct V_1 * V_2 )
{
T_3 V_42 [ 5 ] ;
F_15 ( V_2 , sizeof( struct V_1 ) ) ;
V_42 [ 0 ] = V_21 ;
V_42 [ 1 ] = V_38 ;
V_42 [ 2 ] = V_37 ;
V_42 [ 3 ] = V_20 ;
V_42 [ 4 ] = V_19 ;
F_16 ( V_41 ,
V_2 ,
F_9 ,
F_2 ,
V_42 ,
5 ) ;
return 0 ;
}
