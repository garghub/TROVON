static unsigned int F_1 ( T_1 * V_1 )
{
unsigned int V_2 ;
V_2 = * V_1 -> V_3 ++ ;
if ( V_2 & 0x80 ) {
V_2 &= 0x3f ;
V_2 <<= 8 ;
V_2 += * V_1 -> V_3 ++ ;
}
return V_2 ;
}
static unsigned int F_2 ( T_1 * V_1 )
{
unsigned int V_4 = ( * V_1 -> V_3 ) & ( 0x80 >> V_1 -> V_5 ) ;
F_3 ( V_1 ) ;
return V_4 ;
}
static unsigned int F_4 ( T_1 * V_1 , unsigned int V_4 )
{
unsigned int V_2 , V_6 ;
V_2 = ( * V_1 -> V_3 ) & ( 0xffU >> V_1 -> V_5 ) ;
V_6 = V_4 + V_1 -> V_5 ;
if ( V_6 < 8 ) {
V_2 >>= 8 - V_6 ;
V_1 -> V_5 = V_6 ;
} else if ( V_6 == 8 ) {
V_1 -> V_3 ++ ;
V_1 -> V_5 = 0 ;
} else {
V_2 <<= 8 ;
V_2 += * ( ++ V_1 -> V_3 ) ;
V_2 >>= 16 - V_6 ;
V_1 -> V_5 = V_6 - 8 ;
}
return V_2 ;
}
static unsigned int F_5 ( T_1 * V_1 , unsigned int V_4 )
{
unsigned int V_2 , V_6 , V_7 , V_8 ;
if ( ! V_4 )
return 0 ;
V_6 = V_1 -> V_5 + V_4 ;
if ( V_6 < 8 ) {
V_2 = ( unsigned int ) ( * V_1 -> V_3 ) << ( V_1 -> V_5 + 24 ) ;
V_1 -> V_5 = V_6 ;
} else if ( V_6 == 8 ) {
V_2 = ( unsigned int ) ( * V_1 -> V_3 ++ ) << ( V_1 -> V_5 + 24 ) ;
V_1 -> V_5 = 0 ;
} else {
for ( V_8 = V_6 >> 3 , V_7 = 24 , V_2 = 0 ; V_8 ;
V_8 -- , V_7 -= 8 )
V_2 |= ( unsigned int ) ( * V_1 -> V_3 ++ ) << V_7 ;
if ( V_6 < 32 ) {
V_2 |= ( unsigned int ) ( * V_1 -> V_3 ) << V_7 ;
V_2 <<= V_1 -> V_5 ;
} else if ( V_6 > 32 ) {
V_2 <<= V_1 -> V_5 ;
V_2 |= ( * V_1 -> V_3 ) >> ( 8 - V_1 -> V_5 ) ;
}
V_1 -> V_5 = V_6 & 0x7 ;
}
V_2 &= 0xffffffff << ( 32 - V_4 ) ;
return V_2 ;
}
static unsigned int F_6 ( T_1 * V_1 , int V_4 )
{
unsigned int V_2 = 0 ;
switch ( V_4 ) {
case 4 :
V_2 |= * V_1 -> V_3 ++ ;
V_2 <<= 8 ;
case 3 :
V_2 |= * V_1 -> V_3 ++ ;
V_2 <<= 8 ;
case 2 :
V_2 |= * V_1 -> V_3 ++ ;
V_2 <<= 8 ;
case 1 :
V_2 |= * V_1 -> V_3 ++ ;
break;
}
return V_2 ;
}
static int F_7 ( T_1 * V_1 , const struct V_9 * V_10 ,
char * V_11 , int V_12 )
{
F_8 ( L_1 , V_12 * V_13 , L_2 , V_10 -> V_14 ) ;
return V_15 ;
}
static int F_9 ( T_1 * V_1 , const struct V_9 * V_10 ,
char * V_11 , int V_12 )
{
F_8 ( L_1 , V_12 * V_13 , L_2 , V_10 -> V_14 ) ;
F_3 ( V_1 ) ;
F_10 ( V_1 , 0 ) ;
return V_15 ;
}
static int F_11 ( T_1 * V_1 , const struct V_9 * V_10 ,
char * V_11 , int V_12 )
{
int V_16 ;
F_8 ( L_1 , V_12 * V_13 , L_2 , V_10 -> V_14 ) ;
F_12 ( V_1 ) ;
F_10 ( V_1 , 1 ) ;
V_16 = * V_1 -> V_3 ++ ;
V_1 -> V_3 += V_16 ;
F_10 ( V_1 , 0 ) ;
return V_15 ;
}
static int F_13 ( T_1 * V_1 , const struct V_9 * V_10 ,
char * V_11 , int V_12 )
{
unsigned int V_16 ;
F_8 ( L_3 , V_12 * V_13 , L_2 , V_10 -> V_14 ) ;
switch ( V_10 -> V_17 ) {
case V_18 :
F_12 ( V_1 ) ;
V_1 -> V_3 ++ ;
break;
case V_19 :
F_12 ( V_1 ) ;
V_1 -> V_3 += 2 ;
break;
case V_20 :
V_16 = F_4 ( V_1 , 2 ) + 1 ;
F_12 ( V_1 ) ;
if ( V_11 && ( V_10 -> V_21 & V_22 ) ) {
unsigned int V_2 = F_6 ( V_1 , V_16 ) + V_10 -> V_23 ;
F_8 ( L_4 , V_2 ) ;
* ( ( unsigned int * ) ( V_11 + V_10 -> V_24 ) ) = V_2 ;
}
V_1 -> V_3 += V_16 ;
break;
case V_25 :
F_12 ( V_1 ) ;
F_10 ( V_1 , 2 ) ;
V_16 = F_1 ( V_1 ) ;
V_1 -> V_3 += V_16 ;
break;
default:
F_14 ( V_1 , V_10 -> V_17 ) ;
break;
}
F_8 ( L_5 ) ;
F_10 ( V_1 , 0 ) ;
return V_15 ;
}
static int F_15 ( T_1 * V_1 , const struct V_9 * V_10 ,
char * V_11 , int V_12 )
{
F_8 ( L_1 , V_12 * V_13 , L_2 , V_10 -> V_14 ) ;
if ( ( V_10 -> V_21 & V_26 ) && F_2 ( V_1 ) ) {
F_14 ( V_1 , 7 ) ;
} else {
F_14 ( V_1 , V_10 -> V_17 ) ;
}
F_10 ( V_1 , 0 ) ;
return V_15 ;
}
static int F_16 ( T_1 * V_1 , const struct V_9 * V_10 ,
char * V_11 , int V_12 )
{
unsigned int V_16 ;
F_8 ( L_1 , V_12 * V_13 , L_2 , V_10 -> V_14 ) ;
F_12 ( V_1 ) ;
switch ( V_10 -> V_17 ) {
case V_27 :
V_16 = V_10 -> V_23 ;
break;
case V_19 :
F_10 ( V_1 , 2 ) ;
V_16 = ( * V_1 -> V_3 ++ ) << 8 ;
V_16 += ( * V_1 -> V_3 ++ ) + V_10 -> V_23 ;
break;
case V_28 :
F_10 ( V_1 , 2 ) ;
V_16 = F_1 ( V_1 ) ;
break;
default:
V_16 = 0 ;
break;
}
V_1 -> V_3 += V_16 >> 3 ;
V_1 -> V_5 = V_16 & 7 ;
F_10 ( V_1 , 0 ) ;
return V_15 ;
}
static int F_17 ( T_1 * V_1 , const struct V_9 * V_10 ,
char * V_11 , int V_12 )
{
unsigned int V_16 ;
F_8 ( L_1 , V_12 * V_13 , L_2 , V_10 -> V_14 ) ;
V_16 = F_4 ( V_1 , V_10 -> V_17 ) + V_10 -> V_23 ;
F_12 ( V_1 ) ;
F_14 ( V_1 , ( V_16 << 2 ) ) ;
F_10 ( V_1 , 0 ) ;
return V_15 ;
}
static int F_18 ( T_1 * V_1 , const struct V_9 * V_10 ,
char * V_11 , int V_12 )
{
unsigned int V_16 ;
F_8 ( L_3 , V_12 * V_13 , L_2 , V_10 -> V_14 ) ;
switch ( V_10 -> V_17 ) {
case V_27 :
if ( V_10 -> V_23 > 2 ) {
F_12 ( V_1 ) ;
if ( V_11 && ( V_10 -> V_21 & V_22 ) ) {
F_19 ( V_10 -> V_23 == 4 ,
F_8 ( L_6 ,
V_1 -> V_3 [ 0 ] , V_1 -> V_3 [ 1 ] ,
V_1 -> V_3 [ 2 ] , V_1 -> V_3 [ 3 ] ,
V_1 -> V_3 [ 4 ] * 256 + V_1 -> V_3 [ 5 ] ) ) ;
* ( ( unsigned int * ) ( V_11 + V_10 -> V_24 ) ) =
V_1 -> V_3 - V_1 -> V_29 ;
}
}
V_16 = V_10 -> V_23 ;
break;
case V_18 :
F_12 ( V_1 ) ;
F_10 ( V_1 , 1 ) ;
V_16 = ( * V_1 -> V_3 ++ ) + V_10 -> V_23 ;
break;
case V_28 :
F_12 ( V_1 ) ;
F_10 ( V_1 , 2 ) ;
V_16 = F_1 ( V_1 ) + V_10 -> V_23 ;
break;
default:
V_16 = F_4 ( V_1 , V_10 -> V_17 ) + V_10 -> V_23 ;
F_12 ( V_1 ) ;
break;
}
V_1 -> V_3 += V_16 ;
F_8 ( L_5 ) ;
F_10 ( V_1 , 0 ) ;
return V_15 ;
}
static int F_20 ( T_1 * V_1 , const struct V_9 * V_10 ,
char * V_11 , int V_12 )
{
unsigned int V_16 ;
F_8 ( L_1 , V_12 * V_13 , L_2 , V_10 -> V_14 ) ;
switch ( V_10 -> V_17 ) {
case V_18 :
F_12 ( V_1 ) ;
F_10 ( V_1 , 1 ) ;
V_16 = ( * V_1 -> V_3 ++ ) + V_10 -> V_23 ;
break;
default:
V_16 = F_4 ( V_1 , V_10 -> V_17 ) + V_10 -> V_23 ;
F_12 ( V_1 ) ;
break;
}
V_1 -> V_3 += V_16 << 1 ;
F_10 ( V_1 , 0 ) ;
return V_15 ;
}
static int F_21 ( T_1 * V_1 , const struct V_9 * V_10 ,
char * V_11 , int V_12 )
{
unsigned int V_30 , V_31 , V_32 , V_33 , V_16 = 0 , V_34 , V_35 ;
int V_36 ;
const struct V_9 * V_37 ;
unsigned char * V_38 = NULL ;
F_8 ( L_1 , V_12 * V_13 , L_2 , V_10 -> V_14 ) ;
V_11 = ( V_11 && ( V_10 -> V_21 & V_22 ) ) ? V_11 + V_10 -> V_24 : NULL ;
V_30 = ( V_10 -> V_21 & V_26 ) ? F_2 ( V_1 ) : 0 ;
V_31 = F_5 ( V_1 , V_10 -> V_17 ) ;
if ( V_11 )
* ( unsigned int * ) V_11 = V_31 ;
for ( V_32 = V_33 = 0 , V_37 = V_10 -> V_39 ; V_32 < V_10 -> V_23 ; V_32 ++ , V_37 ++ ) {
if ( V_37 -> V_21 & V_40 ) {
F_8 ( L_1 , ( V_12 + 1 ) * V_13 , L_2 ,
V_37 -> V_14 ) ;
return V_41 ;
}
if ( V_37 -> V_21 & V_42 ) {
if ( ! ( ( 0x80000000U >> ( V_33 ++ ) ) & V_31 ) )
continue;
}
if ( V_37 -> V_21 & V_43 ) {
F_10 ( V_1 , 2 ) ;
V_16 = F_1 ( V_1 ) ;
F_10 ( V_1 , V_16 ) ;
if ( ! V_11 || ! ( V_37 -> V_21 & V_22 ) ) {
F_8 ( L_1 , ( V_12 + 1 ) * V_13 ,
L_2 , V_37 -> V_14 ) ;
V_1 -> V_3 += V_16 ;
continue;
}
V_38 = V_1 -> V_3 ;
if ( ( V_36 = ( V_44 [ V_37 -> type ] ) ( V_1 , V_37 , V_11 ,
V_12 + 1 ) ) <
V_15 )
return V_36 ;
V_1 -> V_3 = V_38 + V_16 ;
V_1 -> V_5 = 0 ;
} else if ( ( V_36 = ( V_44 [ V_37 -> type ] ) ( V_1 , V_37 , V_11 ,
V_12 + 1 ) ) <
V_15 )
return V_36 ;
}
if ( ! V_30 )
return V_15 ;
V_35 = F_4 ( V_1 , 7 ) + 1 ;
F_10 ( V_1 , ( V_35 + 7 ) >> 3 ) ;
V_34 = F_5 ( V_1 , V_35 ) ;
V_31 |= V_34 >> V_10 -> V_17 ;
if ( V_11 )
* ( unsigned int * ) V_11 = V_31 ;
F_12 ( V_1 ) ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ , V_32 ++ , V_37 ++ ) {
if ( V_32 >= V_10 -> V_45 ) {
F_10 ( V_1 , 2 ) ;
V_16 = F_1 ( V_1 ) ;
F_10 ( V_1 , V_16 ) ;
V_1 -> V_3 += V_16 ;
continue;
}
if ( V_37 -> V_21 & V_40 ) {
F_8 ( L_1 , ( V_12 + 1 ) * V_13 , L_2 ,
V_37 -> V_14 ) ;
return V_41 ;
}
if ( ! ( ( 0x80000000 >> V_33 ) & V_34 ) )
continue;
F_10 ( V_1 , 2 ) ;
V_16 = F_1 ( V_1 ) ;
F_10 ( V_1 , V_16 ) ;
if ( ! V_11 || ! ( V_37 -> V_21 & V_22 ) ) {
F_8 ( L_1 , ( V_12 + 1 ) * V_13 , L_2 ,
V_37 -> V_14 ) ;
V_1 -> V_3 += V_16 ;
continue;
}
V_38 = V_1 -> V_3 ;
if ( ( V_36 = ( V_44 [ V_37 -> type ] ) ( V_1 , V_37 , V_11 ,
V_12 + 1 ) ) <
V_15 )
return V_36 ;
V_1 -> V_3 = V_38 + V_16 ;
V_1 -> V_5 = 0 ;
}
return V_15 ;
}
static int F_22 ( T_1 * V_1 , const struct V_9 * V_10 ,
char * V_11 , int V_12 )
{
unsigned int V_46 , V_47 = 0 , V_32 , V_16 = 0 ;
int V_36 ;
const struct V_9 * V_37 ;
unsigned char * V_38 = NULL ;
F_8 ( L_1 , V_12 * V_13 , L_2 , V_10 -> V_14 ) ;
V_11 = ( V_11 && ( V_10 -> V_21 & V_22 ) ) ? V_11 + V_10 -> V_24 : NULL ;
switch ( V_10 -> V_17 ) {
case V_18 :
F_12 ( V_1 ) ;
F_10 ( V_1 , 1 ) ;
V_46 = * V_1 -> V_3 ++ ;
break;
case V_19 :
F_12 ( V_1 ) ;
F_10 ( V_1 , 2 ) ;
V_46 = * V_1 -> V_3 ++ ;
V_46 <<= 8 ;
V_46 += * V_1 -> V_3 ++ ;
break;
case V_28 :
F_12 ( V_1 ) ;
F_10 ( V_1 , 2 ) ;
V_46 = F_1 ( V_1 ) ;
break;
default:
V_46 = F_4 ( V_1 , V_10 -> V_17 ) ;
break;
}
V_46 += V_10 -> V_23 ;
if ( V_11 ) {
V_47 = V_46 > V_10 -> V_45 ? V_10 -> V_45 : V_46 ;
* ( unsigned int * ) V_11 = V_47 ;
V_11 += sizeof( unsigned int ) ;
}
V_37 = V_10 -> V_39 ;
if ( V_11 )
V_11 -= V_37 -> V_24 ;
for ( V_32 = 0 ; V_32 < V_46 ; V_32 ++ ) {
if ( V_37 -> V_21 & V_43 ) {
F_12 ( V_1 ) ;
V_16 = F_1 ( V_1 ) ;
F_10 ( V_1 , V_16 ) ;
if ( ! V_11 || ! ( V_37 -> V_21 & V_22 ) ) {
F_8 ( L_1 , ( V_12 + 1 ) * V_13 ,
L_2 , V_37 -> V_14 ) ;
V_1 -> V_3 += V_16 ;
continue;
}
V_38 = V_1 -> V_3 ;
if ( ( V_36 = ( V_44 [ V_37 -> type ] ) ( V_1 , V_37 ,
V_32 <
V_47 ?
V_11 : NULL ,
V_12 + 1 ) ) <
V_15 )
return V_36 ;
V_1 -> V_3 = V_38 + V_16 ;
V_1 -> V_5 = 0 ;
} else
if ( ( V_36 = ( V_44 [ V_37 -> type ] ) ( V_1 , V_37 ,
V_32 <
V_47 ?
V_11 : NULL ,
V_12 + 1 ) ) <
V_15 )
return V_36 ;
if ( V_11 )
V_11 += V_37 -> V_24 ;
}
return V_15 ;
}
static int F_23 ( T_1 * V_1 , const struct V_9 * V_10 ,
char * V_11 , int V_12 )
{
unsigned int type , V_30 , V_16 = 0 ;
int V_36 ;
const struct V_9 * V_37 ;
unsigned char * V_38 = NULL ;
F_8 ( L_1 , V_12 * V_13 , L_2 , V_10 -> V_14 ) ;
V_11 = ( V_11 && ( V_10 -> V_21 & V_22 ) ) ? V_11 + V_10 -> V_24 : NULL ;
if ( ( V_10 -> V_21 & V_26 ) && F_2 ( V_1 ) ) {
V_30 = 1 ;
type = F_4 ( V_1 , 7 ) + V_10 -> V_23 ;
} else {
V_30 = 0 ;
type = F_4 ( V_1 , V_10 -> V_17 ) ;
if ( type >= V_10 -> V_23 )
return V_48 ;
}
if ( V_11 )
* ( unsigned int * ) V_11 = type ;
if ( type >= V_10 -> V_45 ) {
F_12 ( V_1 ) ;
V_16 = F_1 ( V_1 ) ;
F_10 ( V_1 , V_16 ) ;
V_1 -> V_3 += V_16 ;
return V_15 ;
}
V_37 = & V_10 -> V_39 [ type ] ;
if ( V_37 -> V_21 & V_40 ) {
F_8 ( L_1 , ( V_12 + 1 ) * V_13 , L_2 , V_37 -> V_14 ) ;
return V_41 ;
}
if ( V_30 || ( V_37 -> V_21 & V_43 ) ) {
F_12 ( V_1 ) ;
V_16 = F_1 ( V_1 ) ;
F_10 ( V_1 , V_16 ) ;
if ( ! V_11 || ! ( V_37 -> V_21 & V_22 ) ) {
F_8 ( L_1 , ( V_12 + 1 ) * V_13 , L_2 ,
V_37 -> V_14 ) ;
V_1 -> V_3 += V_16 ;
return V_15 ;
}
V_38 = V_1 -> V_3 ;
if ( ( V_36 = ( V_44 [ V_37 -> type ] ) ( V_1 , V_37 , V_11 , V_12 + 1 ) ) <
V_15 )
return V_36 ;
V_1 -> V_3 = V_38 + V_16 ;
V_1 -> V_5 = 0 ;
} else if ( ( V_36 = ( V_44 [ V_37 -> type ] ) ( V_1 , V_37 , V_11 , V_12 + 1 ) ) <
V_15 )
return V_36 ;
return V_15 ;
}
int F_24 ( unsigned char * V_29 , T_2 V_17 , T_3 * V_49 )
{
static const struct V_9 V_50 = {
F_25 ( L_7 ) V_51 , 5 , 24 , 32 , V_22 | V_26 ,
0 , V_52
} ;
T_1 V_1 ;
V_1 . V_29 = V_1 . V_38 = V_1 . V_3 = V_29 ;
V_1 . V_53 = V_29 + V_17 ;
V_1 . V_5 = 0 ;
return F_23 ( & V_1 , & V_50 , ( char * ) V_49 , 0 ) ;
}
static int F_26 ( unsigned char * V_29 , unsigned char * V_38 ,
T_2 V_17 , T_4 * V_54 )
{
static const struct V_9 V_55 = {
F_25 ( L_8 ) V_56 , 1 , 2 , 2 , V_22 | V_26 ,
0 , V_57
} ;
T_1 V_1 ;
V_1 . V_29 = V_29 ;
V_1 . V_38 = V_1 . V_3 = V_38 ;
V_1 . V_53 = V_38 + V_17 ;
V_1 . V_5 = 0 ;
return F_21 ( & V_1 , & V_55 , ( char * ) V_54 , 0 ) ;
}
int F_27 ( unsigned char * V_29 , T_2 V_17 ,
T_5 *
V_58 )
{
static const struct V_9 V_59 = {
F_25 ( L_9 ) V_51 , 2 , 4 , 4 ,
V_22 | V_26 , 0 , V_60
} ;
T_1 V_1 ;
V_1 . V_29 = V_1 . V_38 = V_1 . V_3 = V_29 ;
V_1 . V_53 = V_29 + V_17 ;
V_1 . V_5 = 0 ;
return F_23 ( & V_1 , & V_59 ,
( char * ) V_58 , 0 ) ;
}
int F_28 ( unsigned char * V_29 , T_2 V_17 , T_6 * V_61 )
{
unsigned char * V_62 = V_29 ;
int V_16 ;
if ( ! V_62 || V_17 < 1 )
return V_63 ;
if ( * V_62 != 0x08 ) {
F_8 ( L_10 ) ;
return V_48 ;
}
V_62 ++ ;
V_17 -- ;
if ( V_17 < 1 )
return V_63 ;
V_16 = * V_62 ++ ;
V_17 -- ;
if ( V_17 < V_16 )
return V_63 ;
V_62 += V_16 ;
V_17 -= V_16 ;
if ( V_17 < 1 )
return V_63 ;
V_61 -> V_64 = * V_62 ++ ;
F_8 ( L_11 , V_61 -> V_64 ) ;
if ( * V_62 & 0x80 ) {
V_62 ++ ;
V_17 -- ;
}
while ( V_17 > 0 ) {
if ( * V_62 == 0x7e ) {
if ( V_17 < 3 )
break;
V_62 ++ ;
V_16 = * V_62 ++ << 8 ;
V_16 |= * V_62 ++ ;
V_17 -= 3 ;
if ( V_17 < V_16 )
break;
V_62 ++ ;
V_16 -- ;
return F_26 ( V_29 , V_62 , V_16 ,
& V_61 -> V_65 ) ;
}
V_62 ++ ;
V_17 -- ;
if ( V_17 < 1 )
break;
V_16 = * V_62 ++ ;
if ( V_17 < V_16 )
break;
V_62 += V_16 ;
V_17 -= V_16 ;
}
F_8 ( L_12 ) ;
return V_63 ;
}
