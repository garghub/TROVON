static void
F_1 ( T_1 * V_1 )
{
V_1 -> V_2 . V_3 = 0x0000 ;
}
static T_2
F_2 ( T_1 * V_1 , const char * V_4 , T_2 T_3 V_5 , T_4 * * T_5 V_5 )
{
const char * V_6 = V_4 ;
char V_7 ;
T_6 V_8 = 0 ;
T_7 V_9 = 0 ;
T_8 V_10 = 0 ;
T_2 V_11 = FALSE ;
const T_9 V_12 = 0x07FF ;
V_7 = * V_6 ;
if ( V_7 == '\0' )
return FALSE ;
if ( V_7 == '.' )
return FALSE ;
if ( V_7 == '-' && V_4 [ 1 ] == '.' )
return FALSE ;
if ( V_7 == '-' && ( V_4 [ 1 ] == 'I' || V_4 [ 1 ] == 'i' ) ) {
if ( ! F_3 ( V_4 , L_1 ) ) {
V_1 -> V_2 . V_3 = V_13 ;
return TRUE ;
}
return FALSE ;
} else if ( V_7 == 'R' || V_7 == 'r' ) {
if ( ! F_3 ( V_4 , L_2 ) ) {
V_1 -> V_2 . V_3 = V_14 ;
return TRUE ;
}
return FALSE ;
} else if ( V_7 == 'N' || V_7 == 'n' ) {
if ( ! F_3 ( V_4 , L_3 ) ) {
V_1 -> V_2 . V_3 = V_15 ;
return TRUE ;
}
if ( ! F_3 ( V_4 , L_4 ) ) {
V_1 -> V_2 . V_3 = V_16 ;
return TRUE ;
}
return FALSE ;
} else if ( V_7 == '+' ) {
if ( ! F_3 ( V_4 , L_5 ) ) {
V_1 -> V_2 . V_3 = V_17 ;
return TRUE ;
}
return FALSE ;
}
if ( V_7 == '-' ) {
if ( V_4 [ 1 ] == '\0' )
return FALSE ;
V_8 = 1 ;
V_6 += 1 ;
}
while ( * V_6 == '0' ) {
V_6 += 1 ;
}
V_7 = * V_6 ;
do {
if ( V_7 == '0' ) {
if ( V_9 * 10 > ( T_7 ) V_12 + V_8 ) {
V_10 += 1 ;
if ( V_10 > 7 )
return FALSE ;
} else {
V_9 *= 10 ;
}
} else if ( V_7 == '1' ) {
V_9 *= 10 ;
V_9 += 1 ;
} else if ( V_7 == '2' ) {
V_9 *= 10 ;
V_9 += 2 ;
} else if ( V_7 == '3' ) {
V_9 *= 10 ;
V_9 += 3 ;
} else if ( V_7 == '4' ) {
V_9 *= 10 ;
V_9 += 4 ;
} else if ( V_7 == '5' ) {
V_9 *= 10 ;
V_9 += 5 ;
} else if ( V_7 == '6' ) {
V_9 *= 10 ;
V_9 += 6 ;
} else if ( V_7 == '7' ) {
V_9 *= 10 ;
V_9 += 7 ;
} else if ( V_7 == '8' ) {
V_9 *= 10 ;
V_9 += 8 ;
} else if ( V_7 == '9' ) {
V_9 *= 10 ;
V_9 += 9 ;
} else if ( V_7 == '.' ) {
if ( V_11 )
return FALSE ;
V_11 = TRUE ;
V_6 += 1 ;
while ( * V_6 == '0' ) {
V_6 += 1 ;
if ( V_9 * 10 <= ( T_7 ) V_12 + V_8 ) {
V_9 *= 10 ;
if ( V_10 > - 8 - 4 )
V_10 -= 1 ;
}
}
V_6 -= 1 ;
} else if ( V_7 != '\0' ) {
return FALSE ;
}
if ( V_9 > ( T_7 ) V_12 + V_8 )
return FALSE ;
if ( V_7 != '.' && V_11 )
V_10 -= 1 ;
V_6 += 1 ;
} while ( ( V_7 = * V_6 ) );
if ( V_8 ) {
V_9 = ~ ( V_9 - 1 ) ;
V_9 &= 0x0FFF ;
}
if ( V_9 == 0 )
V_10 = 0 ;
while ( V_9 > 0 && V_9 % 10 == 0 && V_10 < 7 ) {
V_9 /= 10 ;
V_10 += 1 ;
}
if ( V_10 < - 8 )
return FALSE ;
V_1 -> V_2 . V_3 = ( ( V_10 & 0x0F ) << 12 ) | V_9 ;
return TRUE ;
}
static void
F_4 ( T_1 * V_1 , T_10 T_11 V_5 , int T_12 V_5 , char * V_18 , unsigned int V_19 )
{
T_8 V_10 ;
T_9 V_9 ;
T_9 V_8 ;
T_7 V_20 = 0 ;
#define F_5 5
T_4 V_21 [ F_5 ] ;
T_6 V_22 ;
if ( V_1 -> V_2 . V_3 >= 0x07FE && V_1 -> V_2 . V_3 <= 0x0802 ) {
switch ( V_1 -> V_2 . V_3 ) {
case V_17 :
F_6 ( V_18 , L_5 , V_19 ) ;
break;
case V_16 :
F_6 ( V_18 , L_4 , V_19 ) ;
break;
case V_15 :
F_6 ( V_18 , L_3 , V_19 ) ;
break;
case V_14 :
F_6 ( V_18 , L_2 , V_19 ) ;
break;
case V_13 :
F_6 ( V_18 , L_1 , V_19 ) ;
break;
}
return;
}
V_10 = V_1 -> V_2 . V_3 >> 12 ;
if ( V_10 & 0x8 )
V_10 |= 0xF0 ;
V_9 = V_1 -> V_2 . V_3 & 0x07FF ;
V_8 = ( V_1 -> V_2 . V_3 & 0x0800 ) ;
if ( V_8 )
V_9 = - ( ( V_23 ) V_9 | 0xF800 ) ;
if ( V_9 == 0 ) {
V_18 [ 0 ] = '0' ;
V_18 [ 1 ] = '\0' ;
return;
}
if ( V_8 ) {
V_18 [ 0 ] = '-' ;
V_20 += 1 ;
}
V_22 = F_7 ( V_21 , F_5 , L_6 , V_9 ) ;
if ( V_10 == 0 ) {
memcpy ( V_18 + V_20 , V_21 , V_22 ) ;
V_20 += V_22 ;
} else if ( V_10 > 0 ) {
memcpy ( V_18 + V_20 , V_21 , V_22 ) ;
V_20 += V_22 ;
memset ( V_18 + V_20 , '0' , V_10 ) ;
V_20 += V_10 ;
} else {
if ( - V_10 < V_22 ) {
memcpy ( V_18 + V_20 , V_21 , V_22 + V_10 ) ;
V_20 += V_22 + V_10 ;
V_18 [ V_20 ] = '.' ;
V_20 += 1 ;
memcpy ( V_18 + V_20 , V_21 + V_22 + V_10 , - V_10 ) ;
V_20 += - V_10 ;
} else {
V_18 [ V_20 ] = '0' ;
V_20 += 1 ;
V_18 [ V_20 ] = '.' ;
V_20 += 1 ;
if ( - V_10 - V_22 > 0 ) {
memset ( V_18 + V_20 , '0' , - V_10 - V_22 ) ;
V_20 += - V_10 - V_22 ;
}
memcpy ( V_18 + V_20 , V_21 , V_22 ) ;
V_20 += V_22 ;
}
}
V_18 [ V_20 ] = '\0' ;
}
static int
F_8 ( T_1 * V_1 V_5 , T_10 T_11 V_5 , int T_12 V_5 )
{
return 13 ;
}
static void
F_9 ( T_1 * V_1 , T_7 V_2 )
{
V_1 -> V_2 . V_3 = ( T_9 ) V_2 ;
}
static T_7
F_10 ( T_1 * V_1 )
{
return ( T_7 ) V_1 -> V_2 . V_3 ;
}
static T_9 F_11 ( T_9 V_2 )
{
T_8 V_10 ;
T_9 V_9 ;
T_6 V_8 ;
if ( V_2 >= 0x07FE && V_2 <= 0x0802 )
return V_2 ;
V_9 = V_2 & 0x07FF ;
if ( V_2 & 0x0800 ) {
V_9 = - ( ( V_23 ) V_9 | 0xF800 ) ;
V_8 = 1 ;
} else {
V_8 = 0 ;
}
V_10 = V_2 >> 12 ;
if ( V_10 & 0x08 ) {
V_10 |= 0xF0 ;
}
while ( ( ! ( V_9 % 10 ) ) && V_9 != 0 ) {
V_9 /= 10 ;
if ( V_10 == 7 )
break;
V_10 += 1 ;
}
return ( ( ( ( V_10 & 0x80 ) ? 0x8 : 0x0 ) | ( V_10 & 0x7 ) ) << 12 ) | ( V_8 << 11 ) | V_9 ;
}
static T_2
F_12 ( const T_1 * V_24 , const T_1 * V_25 )
{
return F_11 ( V_24 -> V_2 . V_3 ) == F_11 ( V_25 -> V_2 . V_3 ) ;
}
static T_2
F_13 ( const T_1 * V_24 , const T_1 * V_25 )
{
return F_11 ( V_24 -> V_2 . V_3 ) != F_11 ( V_25 -> V_2 . V_3 ) ;
}
static T_2
F_14 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_9 V_26 ;
T_9 V_27 ;
V_23 V_28 ;
V_23 V_29 ;
T_8 V_30 ;
T_8 V_31 ;
V_26 = F_11 ( V_24 -> V_2 . V_3 ) ;
V_27 = F_11 ( V_25 -> V_2 . V_3 ) ;
if ( V_26 == V_27 )
return FALSE ;
switch ( V_26 ) {
case V_16 :
case V_15 :
case V_14 :
case V_13 :
return FALSE ;
case V_17 :
switch ( V_27 ) {
case V_16 :
case V_15 :
case V_14 :
case V_17 :
return FALSE ;
case V_13 :
default:
return TRUE ;
}
}
V_28 = V_26 & 0x0FFF ;
V_29 = V_27 & 0x0FFF ;
if ( V_26 & 0x0800 )
V_28 |= 0xF000 ;
if ( V_27 & 0x0800 )
V_29 |= 0xF000 ;
V_30 = V_26 >> 12 ;
V_31 = V_27 >> 12 ;
if ( V_30 & 0x08 ) {
V_30 |= 0xF0 ;
}
if ( V_31 & 0x08 ) {
V_31 |= 0xF0 ;
}
if ( V_28 == V_29 && V_30 > V_31 )
return TRUE ;
if ( V_30 == V_31 && V_28 > V_29 )
return TRUE ;
if ( V_30 < V_31 ) {
T_6 V_32 ;
V_32 = V_31 - V_30 ;
if ( V_32 >= 4 )
return FALSE ;
while ( V_32 -- ) {
V_29 *= 10 ;
}
} else {
T_6 V_32 ;
V_32 = V_30 - V_31 ;
if ( V_32 >= 4 )
return TRUE ;
while ( V_32 -- ) {
V_28 *= 10 ;
}
}
if ( V_28 > V_29 )
return TRUE ;
return FALSE ;
}
static T_2
F_15 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_9 V_26 ;
T_9 V_27 ;
V_23 V_28 ;
V_23 V_29 ;
T_8 V_30 ;
T_8 V_31 ;
V_26 = F_11 ( V_24 -> V_2 . V_3 ) ;
V_27 = F_11 ( V_25 -> V_2 . V_3 ) ;
if ( V_26 == V_27 )
return TRUE ;
switch ( V_26 ) {
case V_16 :
case V_15 :
case V_14 :
case V_13 :
return FALSE ;
case V_17 :
switch ( V_27 ) {
case V_16 :
case V_15 :
case V_14 :
case V_17 :
return FALSE ;
case V_13 :
default:
return TRUE ;
}
}
V_28 = V_26 & 0x0FFF ;
V_29 = V_27 & 0x0FFF ;
if ( V_26 & 0x0800 )
V_28 |= 0xF000 ;
if ( V_27 & 0x0800 )
V_29 |= 0xF000 ;
V_30 = V_26 >> 12 ;
V_31 = V_27 >> 12 ;
if ( V_30 & 0x08 ) {
V_30 |= 0xF0 ;
}
if ( V_31 & 0x08 ) {
V_31 |= 0xF0 ;
}
if ( V_28 == V_29 && V_30 >= V_31 )
return TRUE ;
if ( V_30 == V_31 && V_28 >= V_29 )
return TRUE ;
if ( V_30 < V_31 ) {
T_6 V_32 ;
V_32 = V_31 - V_30 ;
if ( V_32 >= 4 )
return FALSE ;
while ( V_32 -- ) {
V_29 *= 10 ;
}
} else {
T_6 V_32 ;
V_32 = V_30 - V_31 ;
if ( V_32 >= 4 )
return TRUE ;
while ( V_32 -- ) {
V_28 *= 10 ;
}
}
if ( V_28 > V_29 )
return TRUE ;
return FALSE ;
}
static T_2
F_16 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_9 V_26 ;
T_9 V_27 ;
V_23 V_28 ;
V_23 V_29 ;
T_8 V_30 ;
T_8 V_31 ;
V_26 = F_11 ( V_24 -> V_2 . V_3 ) ;
V_27 = F_11 ( V_25 -> V_2 . V_3 ) ;
if ( V_26 == V_27 )
return FALSE ;
switch ( V_26 ) {
case V_16 :
case V_15 :
case V_14 :
case V_17 :
return FALSE ;
case V_13 :
switch ( V_27 ) {
case V_16 :
case V_15 :
case V_14 :
case V_13 :
return FALSE ;
case V_17 :
default:
return TRUE ;
}
}
V_28 = V_26 & 0x0FFF ;
V_29 = V_27 & 0x0FFF ;
if ( V_26 & 0x0800 )
V_28 |= 0xFFFFF000 ;
if ( V_27 & 0x0800 )
V_29 |= 0xFFFFF000 ;
V_30 = V_26 >> 12 ;
V_31 = V_27 >> 12 ;
if ( V_30 & 0x08 ) {
V_30 |= 0xF0 ;
}
if ( V_31 & 0x08 ) {
V_31 |= 0xF0 ;
}
if ( V_28 == V_29 && V_30 < V_31 )
return TRUE ;
if ( V_30 == V_31 && V_28 < V_29 )
return TRUE ;
if ( V_30 < V_31 ) {
T_6 V_32 ;
V_32 = V_31 - V_30 ;
if ( V_32 >= 4 )
return TRUE ;
while ( V_32 -- ) {
V_29 *= 10 ;
}
} else {
T_6 V_32 ;
V_32 = V_30 - V_31 ;
if ( V_32 >= 4 )
return FALSE ;
while ( V_32 -- ) {
V_28 *= 10 ;
}
}
if ( V_28 < V_29 )
return TRUE ;
return FALSE ;
}
static T_2
F_17 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_9 V_26 ;
T_9 V_27 ;
V_23 V_28 ;
V_23 V_29 ;
T_8 V_30 ;
T_8 V_31 ;
V_26 = F_11 ( V_24 -> V_2 . V_3 ) ;
V_27 = F_11 ( V_25 -> V_2 . V_3 ) ;
if ( V_26 == V_27 )
return TRUE ;
switch ( V_26 ) {
case V_16 :
case V_15 :
case V_14 :
case V_17 :
return FALSE ;
case V_13 :
switch ( V_27 ) {
case V_16 :
case V_15 :
case V_14 :
case V_13 :
return FALSE ;
case V_17 :
default:
return TRUE ;
}
}
V_28 = V_26 & 0x0FFF ;
V_29 = V_27 & 0x0FFF ;
if ( V_26 & 0x0800 )
V_28 |= 0xF000 ;
if ( V_27 & 0x0800 )
V_29 |= 0xF000 ;
V_30 = V_26 >> 12 ;
V_31 = V_27 >> 12 ;
if ( V_30 & 0x08 ) {
V_30 |= 0xF0 ;
}
if ( V_31 & 0x08 ) {
V_31 |= 0xF0 ;
}
if ( V_28 == V_29 && V_30 <= V_31 )
return TRUE ;
if ( V_30 == V_31 && V_28 <= V_29 )
return TRUE ;
if ( V_30 < V_31 ) {
T_6 V_32 ;
V_32 = V_31 - V_30 ;
if ( V_32 >= 4 )
return TRUE ;
while ( V_32 -- ) {
V_29 *= 10 ;
}
} else {
T_6 V_32 ;
V_32 = V_30 - V_31 ;
if ( V_32 >= 4 )
return FALSE ;
while ( V_32 -- ) {
V_28 *= 10 ;
}
}
if ( V_28 < V_29 )
return TRUE ;
return FALSE ;
}
static T_2
F_18 ( const T_1 * V_24 , const T_1 * V_25 )
{
return ( ( V_24 -> V_2 . V_33 & V_25 -> V_2 . V_33 ) != 0 ) ;
}
static void
F_19 ( T_1 * V_1 )
{
V_1 -> V_2 . V_34 = 0x0000 ;
}
static T_2
F_20 ( T_1 * V_1 , const char * V_4 , T_2 T_3 V_5 , T_4 * * T_5 V_5 )
{
const char * V_6 = V_4 ;
char V_7 ;
T_6 V_8 = 0 ;
T_7 V_9 = 0 ;
V_23 V_10 = 0 ;
T_2 V_11 = FALSE ;
const T_7 V_12 = 0x007FFFFF ;
V_7 = * V_6 ;
if ( V_7 == '\0' )
return FALSE ;
if ( V_7 == '.' )
return FALSE ;
if ( V_7 == '-' && V_4 [ 1 ] == '.' )
return FALSE ;
if ( V_7 == '-' && ( V_4 [ 1 ] == 'I' || V_4 [ 1 ] == 'i' ) ) {
if ( ! F_3 ( V_4 , L_1 ) ) {
V_1 -> V_2 . V_34 = V_35 ;
return TRUE ;
}
return FALSE ;
} else if ( V_7 == 'R' || V_7 == 'r' ) {
if ( ! F_3 ( V_4 , L_2 ) ) {
V_1 -> V_2 . V_34 = V_36 ;
return TRUE ;
}
return FALSE ;
} else if ( V_7 == 'N' || V_7 == 'n' ) {
if ( ! F_3 ( V_4 , L_3 ) ) {
V_1 -> V_2 . V_34 = V_37 ;
return TRUE ;
}
if ( ! F_3 ( V_4 , L_4 ) ) {
V_1 -> V_2 . V_34 = V_38 ;
return TRUE ;
}
return FALSE ;
} else if ( V_7 == '+' ) {
if ( ! F_3 ( V_4 , L_5 ) ) {
V_1 -> V_2 . V_34 = V_39 ;
return TRUE ;
}
return FALSE ;
}
if ( V_7 == '-' ) {
if ( V_4 [ 1 ] == '\0' )
return FALSE ;
V_8 = 1 ;
V_6 += 1 ;
}
while ( * V_6 == '0' ) {
V_6 += 1 ;
}
V_7 = * V_6 ;
do {
if ( V_7 == '0' ) {
if ( V_9 * 10 > V_8 + V_12 ) {
V_10 += 1 ;
if ( V_10 <= 127 )
return FALSE ;
} else {
V_9 *= 10 ;
}
} else if ( V_7 == '1' ) {
V_9 *= 10 ;
V_9 += 1 ;
} else if ( V_7 == '2' ) {
V_9 *= 10 ;
V_9 += 2 ;
} else if ( V_7 == '3' ) {
V_9 *= 10 ;
V_9 += 3 ;
} else if ( V_7 == '4' ) {
V_9 *= 10 ;
V_9 += 4 ;
} else if ( V_7 == '5' ) {
V_9 *= 10 ;
V_9 += 5 ;
} else if ( V_7 == '6' ) {
V_9 *= 10 ;
V_9 += 6 ;
} else if ( V_7 == '7' ) {
V_9 *= 10 ;
V_9 += 7 ;
} else if ( V_7 == '8' ) {
V_9 *= 10 ;
V_9 += 8 ;
} else if ( V_7 == '9' ) {
V_9 *= 10 ;
V_9 += 9 ;
} else if ( V_7 == '.' ) {
if ( V_11 )
return FALSE ;
V_11 = TRUE ;
V_6 += 1 ;
while ( * V_6 == '0' ) {
V_6 += 1 ;
if ( V_9 * 10 <= V_12 + V_8 ) {
V_9 *= 10 ;
if ( V_10 > - 128 - 7 )
V_10 -= 1 ;
}
}
V_6 -= 1 ;
} else if ( V_7 != '\0' ) {
return FALSE ;
}
if ( V_9 > V_12 + V_8 )
return FALSE ;
if ( V_7 != '.' && V_11 )
V_10 -= 1 ;
V_6 += 1 ;
} while ( ( V_7 = * V_6 ) );
if ( V_8 ) {
V_9 = ~ ( V_9 - 1 ) ;
V_9 &= 0x00FFFFFF ;
}
if ( V_9 == 0 )
V_10 = 0 ;
while ( V_9 > 0 && V_9 % 10 == 0 && V_10 < 127 ) {
V_9 /= 10 ;
V_10 += 1 ;
}
if ( V_10 < - 128 )
return FALSE ;
V_1 -> V_2 . V_34 = ( ( V_10 & 0xFF ) << 24 ) | V_9 ;
return TRUE ;
}
static void
F_21 ( T_1 * V_1 , T_10 T_11 V_5 , int T_12 V_5 , char * V_18 , unsigned int V_19 )
{
T_8 V_10 ;
T_7 V_9 ;
T_7 V_8 ;
T_7 V_20 = 0 ;
T_4 V_21 [ 8 ] ;
T_6 V_22 ;
if ( V_1 -> V_2 . V_34 >= 0x007FFFFE && V_1 -> V_2 . V_34 <= 0x00800002 ) {
switch ( V_1 -> V_2 . V_34 ) {
case V_39 :
F_6 ( V_18 , L_5 , V_19 ) ;
break;
case V_38 :
F_6 ( V_18 , L_4 , V_19 ) ;
break;
case V_37 :
F_6 ( V_18 , L_3 , V_19 ) ;
break;
case V_36 :
F_6 ( V_18 , L_2 , V_19 ) ;
break;
case V_35 :
F_6 ( V_18 , L_1 , V_19 ) ;
break;
}
}
V_10 = V_1 -> V_2 . V_34 >> 24 ;
V_9 = V_1 -> V_2 . V_34 & 0x007FFFFF ;
V_8 = ( V_1 -> V_2 . V_34 & 0x00800000 ) ;
if ( V_8 )
V_9 = ( T_7 ) ( - ( ( V_40 ) ( V_9 | 0xFF000000 ) ) ) ;
if ( V_9 == 0 ) {
V_18 [ 0 ] = '0' ;
V_18 [ 1 ] = '\0' ;
return;
}
if ( V_8 ) {
V_18 [ 0 ] = '-' ;
V_20 += 1 ;
}
V_22 = F_7 ( V_21 , V_19 , L_6 , V_9 ) ;
if ( V_10 == 0 ) {
memcpy ( V_18 + V_20 , V_21 , V_22 ) ;
V_20 += V_22 ;
} else if ( V_10 > 0 ) {
memcpy ( V_18 + V_20 , V_21 , V_22 ) ;
V_20 += V_22 ;
memset ( V_18 + V_20 , '0' , V_10 ) ;
V_20 += V_10 ;
} else {
if ( - V_10 < V_22 ) {
memcpy ( V_18 + V_20 , V_21 , V_22 + V_10 ) ;
V_20 += V_22 + V_10 ;
V_18 [ V_20 ] = '.' ;
V_20 += 1 ;
memcpy ( V_18 + V_20 , V_21 + V_22 + V_10 , - V_10 ) ;
V_20 += - V_10 ;
} else {
V_18 [ V_20 ] = '0' ;
V_20 += 1 ;
V_18 [ V_20 ] = '.' ;
V_20 += 1 ;
if ( - V_10 - V_22 > 0 ) {
memset ( V_18 + V_20 , '0' , - V_10 - V_22 ) ;
V_20 += - V_10 - V_22 ;
}
memcpy ( V_18 + V_20 , V_21 , V_22 ) ;
V_20 += V_22 ;
}
}
V_18 [ V_20 ] = '\0' ;
}
static int
F_22 ( T_1 * V_1 V_5 , T_10 T_11 V_5 , int T_12 V_5 )
{
return 136 ;
}
static void
F_23 ( T_1 * V_1 , T_7 V_2 )
{
V_1 -> V_2 . V_34 = V_2 ;
}
static T_7
F_24 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_34 ;
}
static T_7 F_25 ( T_7 V_2 )
{
T_8 V_10 ;
T_9 V_9 ;
T_6 V_8 ;
if ( V_2 >= 0x007FFFFE && V_2 <= 0x00800002 )
return V_2 ;
V_9 = V_2 & 0x907FFFFF ;
if ( V_2 & 0x00800000 ) {
V_9 = ( T_7 ) ( - ( ( V_40 ) ( V_9 | 0xFF000000 ) ) ) ;
V_8 = 1 ;
} else {
V_8 = 0 ;
}
V_10 = V_2 >> 24 ;
while ( ( ! ( V_9 % 10 ) ) && V_9 != 0 ) {
V_9 /= 10 ;
if ( V_10 == 127 )
break;
V_10 += 1 ;
}
return ( V_10 << 24 ) | ( V_8 << 23 ) | V_9 ;
}
static T_2
F_26 ( const T_1 * V_24 , const T_1 * V_25 )
{
return F_25 ( V_24 -> V_2 . V_34 ) == F_25 ( V_25 -> V_2 . V_34 ) ;
}
static T_2
F_27 ( const T_1 * V_24 , const T_1 * V_25 )
{
return F_25 ( V_24 -> V_2 . V_34 ) != F_25 ( V_25 -> V_2 . V_34 ) ;
}
static T_2
F_28 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_7 V_26 ;
T_7 V_27 ;
V_40 V_28 ;
V_40 V_29 ;
T_8 V_30 ;
T_8 V_31 ;
V_26 = F_25 ( V_24 -> V_2 . V_34 ) ;
V_27 = F_25 ( V_25 -> V_2 . V_34 ) ;
if ( V_26 == V_27 )
return FALSE ;
switch ( V_26 ) {
case V_38 :
case V_37 :
case V_36 :
case V_35 :
return FALSE ;
case V_39 :
switch ( V_27 ) {
case V_38 :
case V_37 :
case V_36 :
case V_39 :
return FALSE ;
case V_35 :
default:
return TRUE ;
}
}
V_28 = V_26 & 0x00FFFFFF ;
V_29 = V_27 & 0x00FFFFFF ;
if ( V_26 & 0x00800000 )
V_28 |= 0xFF000000 ;
if ( V_27 & 0x00800000 )
V_29 |= 0xFF000000 ;
V_30 = V_26 >> 24 ;
V_31 = V_27 >> 24 ;
if ( V_28 == V_29 && V_30 > V_31 )
return TRUE ;
if ( V_30 == V_31 && V_28 > V_29 )
return TRUE ;
if ( V_30 < V_31 ) {
T_6 V_32 ;
V_32 = V_31 - V_30 ;
if ( V_32 >= 7 )
return FALSE ;
while ( V_32 -- ) {
V_29 *= 10 ;
}
} else {
T_6 V_32 ;
V_32 = V_30 - V_31 ;
if ( V_32 >= 7 )
return TRUE ;
while ( V_32 -- ) {
V_28 *= 10 ;
}
}
if ( V_28 > V_29 )
return TRUE ;
return FALSE ;
}
static T_2
F_29 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_7 V_26 ;
T_7 V_27 ;
V_40 V_28 ;
V_40 V_29 ;
T_8 V_30 ;
T_8 V_31 ;
V_26 = F_25 ( V_24 -> V_2 . V_34 ) ;
V_27 = F_25 ( V_25 -> V_2 . V_34 ) ;
if ( V_26 == V_27 )
return TRUE ;
switch ( V_26 ) {
case V_38 :
case V_37 :
case V_36 :
case V_35 :
return FALSE ;
case V_39 :
switch ( V_27 ) {
case V_38 :
case V_37 :
case V_36 :
case V_39 :
return FALSE ;
case V_35 :
default:
return TRUE ;
}
}
V_28 = V_26 & 0x00FFFFFF ;
V_29 = V_27 & 0x00FFFFFF ;
if ( V_26 & 0x00800000 )
V_28 |= 0xFF000000 ;
if ( V_27 & 0x00800000 )
V_29 |= 0xFF000000 ;
V_30 = V_26 >> 24 ;
V_31 = V_27 >> 24 ;
if ( V_28 == V_29 && V_30 >= V_31 )
return TRUE ;
if ( V_30 == V_31 && V_28 >= V_29 )
return TRUE ;
if ( V_30 < V_31 ) {
T_6 V_32 ;
V_32 = V_31 - V_30 ;
if ( V_32 >= 7 )
return FALSE ;
while ( V_32 -- ) {
V_29 *= 10 ;
}
} else {
T_6 V_32 ;
V_32 = V_30 - V_31 ;
if ( V_32 >= 7 )
return TRUE ;
while ( V_32 -- ) {
V_28 *= 10 ;
}
}
if ( V_28 > V_29 )
return TRUE ;
return FALSE ;
}
static T_2
F_30 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_7 V_26 ;
T_7 V_27 ;
V_40 V_28 ;
V_40 V_29 ;
T_8 V_30 ;
T_8 V_31 ;
V_26 = F_25 ( V_24 -> V_2 . V_34 ) ;
V_27 = F_25 ( V_25 -> V_2 . V_34 ) ;
if ( V_26 == V_27 )
return FALSE ;
switch ( V_26 ) {
case V_38 :
case V_37 :
case V_36 :
case V_39 :
return FALSE ;
case V_35 :
switch ( V_27 ) {
case V_38 :
case V_37 :
case V_36 :
case V_35 :
return FALSE ;
case V_39 :
default:
return TRUE ;
}
}
V_28 = V_26 & 0x00FFFFFF ;
V_29 = V_27 & 0x00FFFFFF ;
if ( V_26 & 0x00800000 )
V_28 |= 0xFF000000 ;
if ( V_27 & 0x00800000 )
V_29 |= 0xFF000000 ;
V_30 = V_26 >> 24 ;
V_31 = V_27 >> 24 ;
if ( V_28 == V_29 && V_30 < V_31 )
return TRUE ;
if ( V_30 == V_31 && V_28 < V_29 )
return TRUE ;
if ( V_30 < V_31 ) {
T_6 V_32 ;
V_32 = V_31 - V_30 ;
if ( V_32 >= 7 )
return TRUE ;
while ( V_32 -- ) {
V_29 *= 10 ;
}
} else {
T_6 V_32 ;
V_32 = V_30 - V_31 ;
if ( V_32 >= 7 )
return FALSE ;
while ( V_32 -- ) {
V_28 *= 10 ;
}
}
if ( V_28 < V_29 )
return TRUE ;
return FALSE ;
}
static T_2
F_31 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_7 V_26 ;
T_7 V_27 ;
V_40 V_28 ;
V_40 V_29 ;
T_8 V_30 ;
T_8 V_31 ;
V_26 = F_25 ( V_24 -> V_2 . V_34 ) ;
V_27 = F_25 ( V_25 -> V_2 . V_34 ) ;
if ( V_26 == V_27 )
return TRUE ;
switch ( V_26 ) {
case V_38 :
case V_37 :
case V_36 :
case V_39 :
return FALSE ;
case V_35 :
switch ( V_27 ) {
case V_38 :
case V_37 :
case V_36 :
case V_35 :
return FALSE ;
case V_39 :
default:
return TRUE ;
}
}
V_28 = V_26 & 0x00FFFFFF ;
V_29 = V_27 & 0x00FFFFFF ;
if ( V_26 & 0x00800000 )
V_28 |= 0xFF000000 ;
if ( V_27 & 0x00800000 )
V_29 |= 0xFF000000 ;
V_30 = V_26 >> 24 ;
V_31 = V_27 >> 24 ;
if ( V_28 == V_29 && V_30 <= V_31 )
return TRUE ;
if ( V_30 == V_31 && V_28 <= V_29 )
return TRUE ;
if ( V_30 < V_31 ) {
T_6 V_32 ;
V_32 = V_31 - V_30 ;
if ( V_32 >= 7 )
return TRUE ;
while ( V_32 -- ) {
V_29 *= 10 ;
}
} else {
T_6 V_32 ;
V_32 = V_30 - V_31 ;
if ( V_32 >= 7 )
return FALSE ;
while ( V_32 -- ) {
V_28 *= 10 ;
}
}
if ( V_28 < V_29 )
return TRUE ;
return FALSE ;
}
static T_2
F_32 ( const T_1 * V_24 , const T_1 * V_25 )
{
return ( ( V_24 -> V_2 . V_33 & V_25 -> V_2 . V_33 ) != 0 ) ;
}
void
F_33 ( void )
{
static T_13 V_41 = {
V_42 ,
L_7 ,
L_8 ,
2 ,
F_1 ,
NULL ,
F_2 ,
NULL ,
F_4 ,
F_8 ,
{ . V_43 = F_9 } ,
{ . V_44 = F_10 } ,
F_12 ,
F_13 ,
F_14 ,
F_15 ,
F_16 ,
F_17 ,
F_18 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_13 V_45 = {
V_46 ,
L_9 ,
L_10 ,
4 ,
F_19 ,
NULL ,
F_20 ,
NULL ,
F_21 ,
F_22 ,
{ . V_43 = F_23 } ,
{ . V_44 = F_24 } ,
F_26 ,
F_27 ,
F_28 ,
F_29 ,
F_30 ,
F_31 ,
F_32 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
F_34 ( V_42 , & V_41 ) ;
F_34 ( V_46 , & V_45 ) ;
}
