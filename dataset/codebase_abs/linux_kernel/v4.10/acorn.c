static struct V_1 *
F_1 ( struct V_2 * V_3 , char * V_4 , char * V_5 ,
unsigned long V_6 , int V_7 )
{
struct V_1 * V_8 ;
unsigned int V_9 ;
if ( F_2 ( V_5 ) )
return NULL ;
V_8 = (struct V_1 * ) ( V_5 + 0x1c0 ) ;
if ( V_8 -> V_10 == 0 && V_8 -> V_11 == 0 )
return NULL ;
V_9 = ( F_3 ( V_8 -> V_11 ) << 23 ) |
( F_3 ( V_8 -> V_10 ) >> 9 ) ;
if ( V_4 ) {
F_4 ( V_3 -> V_12 , L_1 , V_13 ) ;
F_4 ( V_3 -> V_12 , V_4 , V_13 ) ;
F_4 ( V_3 -> V_12 , L_2 , V_13 ) ;
}
F_5 ( V_3 , V_7 , V_6 , V_9 ) ;
return V_8 ;
}
static int F_6 ( struct V_2 * V_3 ,
unsigned long V_14 , int V_7 ,
unsigned long V_9 )
{
T_1 V_15 ;
struct V_16 * V_17 ;
V_17 = F_7 ( V_3 , V_14 , & V_15 ) ;
if ( ! V_17 )
return - 1 ;
F_4 ( V_3 -> V_12 , L_3 , V_13 ) ;
if ( V_17 -> V_18 == V_19 ) {
unsigned long V_20 = V_9 > 2 ? 2 : V_9 ;
int V_21 ;
F_4 ( V_3 -> V_12 , L_4 , V_13 ) ;
F_5 ( V_3 , V_7 ++ , V_14 , V_20 ) ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
if ( V_17 -> V_21 [ V_21 ] . V_22 &&
memcmp ( V_17 -> V_21 [ V_21 ] . V_4 , L_5 , 4 ) ) {
F_5 ( V_3 , V_7 ++ ,
F_3 ( V_17 -> V_21 [ V_21 ] . V_23 ) ,
F_3 ( V_17 -> V_21 [ V_21 ] . V_24 ) ) ;
F_4 ( V_3 -> V_12 , L_6 , V_13 ) ;
F_4 ( V_3 -> V_12 , V_17 -> V_21 [ V_21 ] . V_4 , V_13 ) ;
F_4 ( V_3 -> V_12 , L_7 , V_13 ) ;
}
}
F_4 ( V_3 -> V_12 , L_8 , V_13 ) ;
} else {
F_5 ( V_3 , V_7 ++ , V_14 , V_9 ) ;
}
F_8 ( V_15 ) ;
return V_7 ;
}
static int F_9 ( struct V_2 * V_3 ,
unsigned long V_14 , int V_7 ,
unsigned long V_9 )
{
T_1 V_15 ;
struct V_25 * V_26 ;
unsigned long V_20 = V_9 > 2 ? 2 : V_9 ;
F_4 ( V_3 -> V_12 , L_9 , V_13 ) ;
F_5 ( V_3 , V_7 ++ , V_14 , V_20 ) ;
V_26 = F_7 ( V_3 , V_14 , & V_15 ) ;
if ( ! V_26 )
return - 1 ;
F_4 ( V_3 -> V_12 , L_4 , V_13 ) ;
while ( V_26 -> V_18 == F_10 ( V_27 ) ||
V_26 -> V_18 == F_10 ( V_28 ) ) {
if ( V_7 == V_3 -> V_29 )
break;
F_5 ( V_3 , V_7 ++ , V_14 +
F_3 ( V_26 -> V_30 ) ,
F_3 ( V_26 -> V_9 ) ) ;
V_26 ++ ;
}
F_4 ( V_3 -> V_12 , L_10 , V_13 ) ;
F_8 ( V_15 ) ;
return V_7 ;
}
int F_11 ( struct V_2 * V_3 )
{
unsigned long V_6 = 0 ;
unsigned int V_31 = 0 ;
T_1 V_15 ;
unsigned char * V_5 ;
char * V_4 = L_11 ;
int V_32 = 1 ;
int V_7 = 1 ;
do {
struct V_1 * V_8 ;
unsigned int V_9 ;
V_5 = F_7 ( V_3 , V_31 * 2 + 6 , & V_15 ) ;
if ( ! V_5 )
return - 1 ;
if ( V_7 == V_3 -> V_29 )
break;
V_8 = F_1 ( V_3 , V_4 , V_5 , V_6 , V_7 ++ ) ;
if ( ! V_8 )
break;
V_4 = NULL ;
V_9 = ( V_5 [ 0x1fd ] + ( V_5 [ 0x1fe ] << 8 ) ) *
( V_8 -> V_33 + ( V_8 -> V_34 & 0x40 ? 1 : 0 ) ) *
V_8 -> V_35 ;
if ( ! V_9 )
break;
V_32 = 0 ;
V_6 += V_9 ;
V_31 += V_9 >> ( V_36 - 9 ) ;
V_9 = 0 ;
switch ( V_5 [ 0x1fc ] & 15 ) {
case 0 :
break;
#ifdef F_12
case V_37 :
V_7 = F_6 ( V_3 , V_6 , V_7 ,
V_9 ) ;
break;
#endif
case V_38 :
V_7 = F_9 ( V_3 , V_6 , V_7 ,
V_9 ) ;
break;
}
F_8 ( V_15 ) ;
if ( V_7 == - 1 )
return - 1 ;
} while ( 1 );
F_8 ( V_15 ) ;
return V_32 ? 0 : 1 ;
}
int F_13 ( struct V_2 * V_3 )
{
unsigned long V_30 , V_9 , V_39 , V_33 ;
T_1 V_15 ;
unsigned char * V_5 ;
struct V_1 * V_8 ;
unsigned char V_40 ;
int V_7 = 1 ;
V_5 = F_7 ( V_3 , 6 , & V_15 ) ;
if ( ! V_5 )
return - 1 ;
V_8 = F_1 ( V_3 , L_12 , V_5 , 0 , V_7 ++ ) ;
if ( ! V_8 ) {
F_8 ( V_15 ) ;
return 0 ;
}
V_33 = V_8 -> V_33 + ( ( V_8 -> V_34 >> 6 ) & 1 ) ;
V_39 = V_8 -> V_35 * V_33 ;
V_30 = ( ( V_5 [ 0x1fe ] << 8 ) + V_5 [ 0x1fd ] ) * V_39 ;
V_40 = V_5 [ 0x1fc ] & 15 ;
F_8 ( V_15 ) ;
V_9 = ( V_3 -> V_41 -> V_42 -> V_43 >> 9 ) - V_30 ;
if ( V_30 ) {
switch ( V_40 ) {
#ifdef F_12
case V_37 :
case V_44 :
V_7 = F_6 ( V_3 , V_30 , V_7 ,
V_9 ) ;
break;
#endif
case V_38 :
V_7 = F_9 ( V_3 , V_30 , V_7 ,
V_9 ) ;
break;
}
}
F_4 ( V_3 -> V_12 , L_13 , V_13 ) ;
return 1 ;
}
static int F_14 ( struct V_2 * V_3 ,
unsigned long V_45 )
{
T_1 V_15 ;
unsigned char * V_5 = F_7 ( V_3 , V_45 , & V_15 ) ;
int V_46 = 0 ;
if ( V_5 ) {
if ( memcmp ( V_5 , L_14 , 9 ) == 0 )
V_46 = 1 ;
F_8 ( V_15 ) ;
}
return V_46 ;
}
static inline int F_15 ( const unsigned char * V_5 )
{
unsigned long V_47 ;
int V_48 ;
for ( V_48 = 0 , V_47 = 0x50617274 ; V_48 < 508 ; V_48 ++ )
V_47 += V_5 [ V_48 ] ;
V_47 -= F_3 ( * ( V_49 * ) ( & V_5 [ 508 ] ) ) ;
return V_47 == 0 ;
}
int F_16 ( struct V_2 * V_3 )
{
const unsigned char * V_5 ;
const struct V_50 * V_51 ;
int V_7 ;
T_1 V_15 ;
V_5 = F_7 ( V_3 , 0 , & V_15 ) ;
if ( ! V_5 )
return - 1 ;
if ( ! F_15 ( V_5 ) ) {
F_8 ( V_15 ) ;
return 0 ;
}
F_4 ( V_3 -> V_12 , L_15 , V_13 ) ;
for ( V_7 = 1 , V_51 = ( const struct V_50 * ) V_5 ; V_51 -> V_20 ; V_51 ++ ) {
T_2 V_23 = F_3 ( V_51 -> V_23 ) ;
T_3 V_20 = F_3 ( V_51 -> V_20 ) ;
if ( V_7 == V_3 -> V_29 )
break;
if ( V_20 < 0 ) {
V_20 = - V_20 ;
if ( V_20 > 1 && F_14 ( V_3 , V_23 ) ) {
V_23 += 1 ;
V_20 -= 1 ;
}
}
if ( V_20 )
F_5 ( V_3 , V_7 ++ , V_23 , V_20 ) ;
}
F_8 ( V_15 ) ;
F_4 ( V_3 -> V_12 , L_13 , V_13 ) ;
return 1 ;
}
static inline int F_17 ( const unsigned char * V_5 )
{
unsigned char V_52 = 0x2a ;
int V_48 ;
if ( V_5 [ 510 ] == 0x55 && V_5 [ 511 ] == 0xaa )
return 0 ;
for ( V_48 = 0 ; V_48 < 511 ; V_48 ++ )
V_52 += V_5 [ V_48 ] ;
return V_52 == V_5 [ 511 ] ;
}
int F_18 ( struct V_2 * V_3 )
{
T_1 V_15 ;
const unsigned char * V_5 ;
const struct V_53 * V_51 ;
int V_7 = 1 ;
int V_48 ;
V_5 = F_7 ( V_3 , 0 , & V_15 ) ;
if ( ! V_5 )
return - 1 ;
if ( ! F_17 ( V_5 ) ) {
F_8 ( V_15 ) ;
return 0 ;
}
F_4 ( V_3 -> V_12 , L_16 , V_13 ) ;
for ( V_48 = 0 , V_51 = ( const struct V_53 * ) V_5 ; V_48 < 12 ; V_48 ++ , V_51 ++ ) {
T_2 V_23 = F_3 ( V_51 -> V_23 ) ;
T_2 V_20 = F_3 ( V_51 -> V_20 ) ;
if ( V_20 )
F_5 ( V_3 , V_7 ++ , V_23 , V_20 ) ;
}
F_8 ( V_15 ) ;
F_4 ( V_3 -> V_12 , L_13 , V_13 ) ;
return 1 ;
}
int F_19 ( struct V_2 * V_3 )
{
T_1 V_15 ;
const unsigned char * V_5 ;
unsigned char V_54 [ 256 ] ;
struct V_55 * V_51 ;
T_4 V_23 = 0 ;
int V_48 , V_7 = 1 ;
V_5 = F_7 ( V_3 , 7 , & V_15 ) ;
if ( ! V_5 )
return - 1 ;
for ( V_48 = 0 ; V_48 < 256 ; V_48 ++ )
V_54 [ V_48 ] = V_5 [ V_48 ] ^ V_56 [ V_48 & 15 ] ;
F_8 ( V_15 ) ;
for ( V_48 = 0 , V_51 = (struct V_55 * ) V_54 ; V_48 < 8 ; V_48 ++ , V_51 ++ ) {
T_4 V_57 ;
if ( memcmp ( V_51 -> V_18 , L_17 , 6 ) )
break;
V_57 = F_3 ( V_51 -> V_23 ) ;
if ( V_48 )
F_5 ( V_3 , V_7 ++ , V_23 , V_57 - V_23 ) ;
V_23 = V_57 ;
}
if ( V_48 != 0 ) {
T_4 V_20 ;
V_20 = F_20 ( V_3 -> V_41 -> V_58 ) ;
F_5 ( V_3 , V_7 ++ , V_23 , V_20 - V_23 ) ;
F_4 ( V_3 -> V_12 , L_13 , V_13 ) ;
}
return V_48 ? 1 : 0 ;
}
