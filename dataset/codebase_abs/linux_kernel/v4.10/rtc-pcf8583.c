static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char V_5 [ 8 ] , V_6 [ 1 ] = { 1 } ;
struct V_7 V_8 [ 2 ] = {
{
. V_6 = V_2 -> V_6 ,
. V_9 = 0 ,
. V_10 = 1 ,
. V_5 = V_6 ,
} , {
. V_6 = V_2 -> V_6 ,
. V_9 = V_11 ,
. V_10 = 6 ,
. V_5 = V_5 ,
}
} ;
int V_12 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
V_12 = F_2 ( V_2 -> V_13 , V_8 , 2 ) ;
if ( V_12 == 2 ) {
V_4 -> V_14 = V_5 [ 4 ] >> 6 ;
V_4 -> V_15 = V_5 [ 5 ] >> 5 ;
V_5 [ 4 ] &= 0x3f ;
V_5 [ 5 ] &= 0x1f ;
V_4 -> V_16 = F_3 ( V_5 [ 1 ] ) ;
V_4 -> V_17 = F_3 ( V_5 [ 2 ] ) ;
V_4 -> V_18 = F_3 ( V_5 [ 3 ] ) ;
V_4 -> V_19 = F_3 ( V_5 [ 4 ] ) ;
V_4 -> V_20 = F_3 ( V_5 [ 5 ] ) - 1 ;
}
return V_12 == 2 ? 0 : - V_21 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_22 )
{
unsigned char V_5 [ 8 ] ;
int V_12 , V_10 = 6 ;
V_5 [ 0 ] = 0 ;
V_5 [ 1 ] = F_5 ( V_2 ) | 0x80 ;
V_5 [ 2 ] = 0 ;
V_5 [ 3 ] = F_6 ( V_4 -> V_16 ) ;
V_5 [ 4 ] = F_6 ( V_4 -> V_17 ) ;
V_5 [ 5 ] = F_6 ( V_4 -> V_18 ) ;
if ( V_22 ) {
V_10 = 8 ;
V_5 [ 6 ] = F_6 ( V_4 -> V_19 ) | ( V_4 -> V_14 << 6 ) ;
V_5 [ 7 ] = F_6 ( V_4 -> V_20 + 1 ) | ( V_4 -> V_15 << 5 ) ;
}
V_12 = F_7 ( V_2 , ( char * ) V_5 , V_10 ) ;
if ( V_12 != V_10 )
return - V_21 ;
V_5 [ 1 ] = F_5 ( V_2 ) ;
V_12 = F_7 ( V_2 , ( char * ) V_5 , 2 ) ;
return V_12 == 2 ? 0 : - V_21 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned char * V_23 )
{
* V_23 = F_5 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned char * V_23 )
{
unsigned char V_5 [ 2 ] ;
V_5 [ 0 ] = 0 ;
V_5 [ 1 ] = * V_23 ;
F_10 ( V_2 , * V_23 ) ;
return F_7 ( V_2 , ( char * ) V_5 , 2 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
unsigned char V_6 [ 1 ] ;
struct V_7 V_8 [ 2 ] = {
{
. V_6 = V_2 -> V_6 ,
. V_9 = 0 ,
. V_10 = 1 ,
. V_5 = V_6 ,
} , {
. V_6 = V_2 -> V_6 ,
. V_9 = V_11 ,
. V_10 = V_25 -> V_26 ,
. V_5 = V_25 -> V_27 ,
}
} ;
if ( V_25 -> V_28 < 8 )
return - V_29 ;
V_6 [ 0 ] = V_25 -> V_28 ;
return F_2 ( V_2 -> V_13 , V_8 , 2 ) == 2 ? 0 : - V_21 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
unsigned char V_5 [ 9 ] ;
int V_12 ;
if ( V_25 -> V_28 < 8 || V_25 -> V_26 > 8 )
return - V_29 ;
V_5 [ 0 ] = V_25 -> V_28 ;
memcpy ( V_5 + 1 , V_25 -> V_27 , V_25 -> V_26 ) ;
V_12 = F_7 ( V_2 , V_5 , V_25 -> V_26 + 1 ) ;
return V_12 == V_25 -> V_26 + 1 ? 0 : - V_21 ;
}
static int F_13 ( struct V_30 * V_31 , struct V_3 * V_32 )
{
struct V_1 * V_2 = F_14 ( V_31 ) ;
unsigned char V_23 , V_33 [ 2 ] ;
struct V_24 V_25 = {
. V_28 = V_34 ,
. V_26 = sizeof( V_33 ) ,
. V_27 = V_33
} ;
int V_35 , V_36 , V_37 ;
F_8 ( V_2 , & V_23 ) ;
if ( V_23 & ( V_38 | V_39 ) ) {
unsigned char V_40 = V_23 & ~ ( V_38 | V_39 ) ;
F_15 ( V_31 , L_1 ,
V_23 , V_40 ) ;
V_37 = F_9 ( V_2 , & V_40 ) ;
if ( V_37 < 0 )
return V_37 ;
}
if ( F_1 ( V_2 , V_32 ) ||
F_11 ( V_2 , & V_25 ) )
return - V_21 ;
V_35 = V_33 [ 0 ] ;
V_36 = V_32 -> V_14 - ( V_35 & 3 ) ;
if ( V_36 < 0 )
V_36 += 4 ;
V_32 -> V_14 = ( V_35 + V_36 + V_33 [ 1 ] * 100 ) - 1900 ;
return 0 ;
}
static int F_16 ( struct V_30 * V_31 , struct V_3 * V_32 )
{
struct V_1 * V_2 = F_14 ( V_31 ) ;
unsigned char V_33 [ 2 ] , V_41 ;
struct V_24 V_42 = {
. V_28 = V_34 ,
. V_26 = sizeof( V_33 ) ,
. V_27 = V_33
} ;
struct V_24 V_43 = {
. V_28 = V_44 ,
. V_26 = 1 ,
. V_27 = & V_41
} ;
unsigned int V_45 = V_32 -> V_14 + 1900 ;
int V_12 ;
V_12 = F_4 ( V_2 , V_32 , 1 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_11 ( V_2 , & V_43 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_11 ( V_2 , & V_42 ) ;
if ( V_12 )
return V_12 ;
V_41 -= V_33 [ 1 ] + V_33 [ 0 ] ;
V_33 [ 1 ] = V_45 / 100 ;
V_33 [ 0 ] = V_45 % 100 ;
V_41 += V_33 [ 1 ] + V_33 [ 0 ] ;
V_12 = F_12 ( V_2 , & V_42 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_12 ( V_2 , & V_43 ) ;
return V_12 ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_46 * V_47 )
{
struct V_48 * V_48 ;
if ( ! F_18 ( V_2 -> V_13 , V_49 ) )
return - V_50 ;
V_48 = F_19 ( & V_2 -> V_31 , sizeof( struct V_48 ) ,
V_51 ) ;
if ( ! V_48 )
return - V_52 ;
F_20 ( V_2 , V_48 ) ;
V_48 -> V_53 = F_21 ( & V_2 -> V_31 ,
V_54 . V_55 . V_56 ,
& V_57 , V_58 ) ;
return F_22 ( V_48 -> V_53 ) ;
}
