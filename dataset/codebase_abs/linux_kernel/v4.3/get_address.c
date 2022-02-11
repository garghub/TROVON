static int F_1 ( int V_1 , unsigned long * V_2 )
{
T_1 V_3 , V_4 , V_5 ;
long V_6 ;
V_7 ;
F_2 ( 1 ) ;
F_3 ( V_5 , ( T_1 V_8 * ) ( * V_2 ) ) ;
V_9 ;
( * V_2 ) ++ ;
V_3 = V_5 >> 6 ;
V_4 = ( V_5 >> 3 ) & 7 ;
V_5 &= 7 ;
if ( ( V_1 == 0 ) && ( V_5 == 5 ) )
V_6 = 0 ;
else
V_6 = F_4 ( V_5 ) ;
if ( V_4 == 4 ) {
if ( V_3 )
F_5 ( V_10 ) ;
} else {
V_6 += ( F_4 ( V_4 ) ) << V_3 ;
}
if ( V_1 == 1 ) {
long V_11 ;
V_7 ;
F_2 ( 1 ) ;
F_3 ( V_11 , ( signed char V_8 * ) ( * V_2 ) ) ;
V_6 += V_11 ;
V_9 ;
( * V_2 ) ++ ;
} else if ( V_1 == 2 || V_5 == 5 ) {
long V_11 ;
V_7 ;
F_2 ( 4 ) ;
F_3 ( V_11 , ( long V_8 * ) ( * V_2 ) ) ;
V_6 += V_11 ;
V_9 ;
( * V_2 ) += 4 ;
}
return V_6 ;
}
static unsigned long F_6 ( T_1 V_12 , struct V_13 * V_14 )
{
V_12 -- ;
#ifdef F_7
if ( V_12 > V_15 ) {
F_5 ( V_16 | 0x130 ) ;
F_8 ( V_17 , V_18 ) ;
}
#endif
V_14 -> V_19 = F_9 ( V_12 ) ;
return ( unsigned long ) F_9 ( V_12 ) << 4 ;
}
static long F_10 ( T_1 V_20 , T_1 V_12 ,
struct V_13 * V_14 , long V_6 )
{
struct V_21 V_22 ;
unsigned long V_23 , V_24 , V_13 , V_25 ;
V_12 -- ;
#ifdef F_7
if ( V_12 > V_15 ) {
F_5 ( V_16 | 0x132 ) ;
F_8 ( V_17 , V_18 ) ;
}
#endif
switch ( V_12 ) {
case V_26 - 1 :
V_14 -> V_19 = F_11 ( V_17 -> V_27 ) ;
break;
default:
V_14 -> V_19 = F_12 ( V_12 ) ;
}
V_22 = F_13 ( V_14 -> V_19 ) ;
V_23 = F_14 ( V_22 ) ;
V_13 = V_23 + V_6 ;
V_24 = V_23
+ ( F_15 ( V_22 ) + 1 ) * F_16 ( V_22 ) - 1 ;
if ( V_24 < V_23 )
V_24 = 0xffffffff ;
if ( F_17 ( V_22 ) ) {
if ( F_18 ( V_22 ) )
V_25 = 0xffffffff ;
else {
V_25 = V_23 + ( 1 << 20 ) ;
if ( V_25 < V_23 )
V_25 = 0xffffffff ;
}
V_28 =
( V_13 <= V_24 ) || ( V_13 >= V_25 ) ? 0 :
( ( V_25 - V_13 ) >= 255 ? 255 : V_25 - V_13 ) ;
} else {
V_28 =
( V_13 > V_24 ) || ( V_13 < V_23 ) ? 0 :
( ( V_24 - V_13 ) >= 254 ? 255 : V_24 - V_13 + 1 ) ;
}
if ( F_19 ( V_22 ) ||
( ! F_20 ( V_22 ) && ( V_20 & V_29 ) ) ) {
V_28 = 0 ;
}
return V_13 ;
}
void V_8 * F_21 ( T_1 V_20 , unsigned long * V_2 ,
struct V_13 * V_14 , T_2 V_30 )
{
T_1 V_1 ;
unsigned V_31 = V_20 & 7 ;
long * V_32 ;
int V_13 = 0 ;
if ( ! V_30 . V_33 && ( V_20 & V_29 )
&& ( V_30 . V_34 . V_12 == V_35 ) ) {
F_8 ( V_17 , V_18 ) ;
}
V_14 -> V_19 = V_36 ;
V_1 = ( V_20 >> 6 ) & 3 ;
if ( V_31 == 4 && V_1 != 3 ) {
V_13 = F_1 ( V_1 , V_2 ) ;
} else {
V_32 = & F_4 ( V_31 ) ;
switch ( V_1 ) {
case 0 :
if ( V_31 == 5 ) {
V_7 ;
F_2 ( 4 ) ;
F_3 ( V_13 ,
( unsigned long V_8
* ) ( * V_2 ) ) ;
( * V_2 ) += 4 ;
V_9 ;
V_14 -> V_6 = V_13 ;
return ( void V_8 * ) V_13 ;
} else {
V_13 = * V_32 ;
V_14 -> V_6 = V_13 ;
return ( void V_8 * ) V_13 ;
}
case 1 :
V_7 ;
F_2 ( 1 ) ;
F_3 ( V_13 , ( signed char V_8 * ) ( * V_2 ) ) ;
V_9 ;
( * V_2 ) ++ ;
break;
case 2 :
V_7 ;
F_2 ( 4 ) ;
F_3 ( V_13 , ( long V_8 * ) ( * V_2 ) ) ;
( * V_2 ) += 4 ;
V_9 ;
break;
case 3 :
F_5 ( V_10 ) ;
}
V_13 += * V_32 ;
}
V_14 -> V_6 = V_13 ;
switch ( V_30 . V_33 ) {
case 0 :
break;
case V_37 :
V_13 += F_6 ( V_30 . V_34 . V_12 , V_14 ) ;
break;
case V_38 :
case V_39 :
V_13 = F_10 ( V_20 , V_30 . V_34 . V_12 ,
V_14 , V_13 ) ;
break;
default:
F_5 ( V_16 | 0x133 ) ;
}
return ( void V_8 * ) V_13 ;
}
void V_8 * F_22 ( T_1 V_20 , unsigned long * V_2 ,
struct V_13 * V_14 , T_2 V_30 )
{
T_1 V_1 ;
unsigned V_31 = V_20 & 7 ;
int V_13 = 0 ;
if ( ! V_30 . V_33 && ( V_20 & V_29 )
&& ( V_30 . V_34 . V_12 == V_35 ) ) {
F_8 ( V_17 , V_18 ) ;
}
V_14 -> V_19 = V_36 ;
V_1 = ( V_20 >> 6 ) & 3 ;
switch ( V_1 ) {
case 0 :
if ( V_31 == 6 ) {
V_7 ;
F_2 ( 2 ) ;
F_3 ( V_13 ,
( unsigned short V_8 * ) ( * V_2 ) ) ;
( * V_2 ) += 2 ;
V_9 ;
goto V_40;
}
break;
case 1 :
V_7 ;
F_2 ( 1 ) ;
F_3 ( V_13 , ( signed char V_8 * ) ( * V_2 ) ) ;
V_9 ;
( * V_2 ) ++ ;
break;
case 2 :
V_7 ;
F_2 ( 2 ) ;
F_3 ( V_13 , ( unsigned short V_8 * ) ( * V_2 ) ) ;
( * V_2 ) += 2 ;
V_9 ;
break;
case 3 :
F_5 ( V_10 ) ;
break;
}
switch ( V_31 ) {
case 0 :
V_13 += V_17 -> V_27 -> V_41 + V_17 -> V_27 -> V_42 ;
break;
case 1 :
V_13 += V_17 -> V_27 -> V_41 + V_17 -> V_27 -> V_43 ;
break;
case 2 :
V_13 += V_17 -> V_27 -> V_44 + V_17 -> V_27 -> V_42 ;
if ( V_30 . V_34 . V_12 == V_45 )
V_30 . V_34 . V_12 = V_15 ;
break;
case 3 :
V_13 += V_17 -> V_27 -> V_44 + V_17 -> V_27 -> V_43 ;
if ( V_30 . V_34 . V_12 == V_45 )
V_30 . V_34 . V_12 = V_15 ;
break;
case 4 :
V_13 += V_17 -> V_27 -> V_42 ;
break;
case 5 :
V_13 += V_17 -> V_27 -> V_43 ;
break;
case 6 :
V_13 += V_17 -> V_27 -> V_44 ;
if ( V_30 . V_34 . V_12 == V_45 )
V_30 . V_34 . V_12 = V_15 ;
break;
case 7 :
V_13 += V_17 -> V_27 -> V_41 ;
break;
}
V_40:
V_13 &= 0xffff ;
V_14 -> V_6 = V_13 ;
switch ( V_30 . V_33 ) {
case 0 :
break;
case V_37 :
V_13 += F_6 ( V_30 . V_34 . V_12 , V_14 ) ;
break;
case V_38 :
case V_39 :
V_13 = F_10 ( V_20 , V_30 . V_34 . V_12 ,
V_14 , V_13 ) ;
break;
default:
F_5 ( V_16 | 0x131 ) ;
}
return ( void V_8 * ) V_13 ;
}
