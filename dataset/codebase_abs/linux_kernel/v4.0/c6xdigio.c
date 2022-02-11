static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned int V_4 ;
int V_5 = 0 ;
do {
V_4 = F_2 ( V_2 -> V_6 + V_7 ) ;
if ( ( V_4 & 0x80 ) != V_3 )
return 0 ;
V_5 ++ ;
} while ( V_5 < V_8 );
return - V_9 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_10 , unsigned int V_4 )
{
F_4 ( V_10 , V_2 -> V_6 + V_11 ) ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int * V_12 ,
unsigned int V_13 ,
unsigned int V_4 )
{
unsigned int V_10 ;
V_10 = F_2 ( V_2 -> V_6 + V_7 ) ;
V_10 >>= 3 ;
V_10 &= 0x07 ;
* V_12 = V_10 ;
return F_3 ( V_2 , V_13 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned int V_14 , unsigned int V_10 )
{
unsigned int V_13 = V_15 | F_7 ( V_14 ) ;
unsigned int V_12 ;
if ( V_10 > 498 )
V_10 = 498 ;
if ( V_10 < 2 )
V_10 = 2 ;
V_12 = ( V_10 >> 0 ) & 0x03 ;
F_3 ( V_2 , V_13 | V_12 | ( 0 << 2 ) , 0x00 ) ;
V_12 = ( V_10 >> 2 ) & 0x03 ;
F_3 ( V_2 , V_13 | V_12 | ( 1 << 2 ) , 0x80 ) ;
V_12 = ( V_10 >> 4 ) & 0x03 ;
F_3 ( V_2 , V_13 | V_12 | ( 0 << 2 ) , 0x00 ) ;
V_12 = ( V_10 >> 6 ) & 0x03 ;
F_3 ( V_2 , V_13 | V_12 | ( 1 << 2 ) , 0x80 ) ;
V_12 = ( V_10 >> 8 ) & 0x03 ;
F_3 ( V_2 , V_13 | V_12 | ( 0 << 2 ) , 0x00 ) ;
F_3 ( V_2 , 0x00 , 0x80 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
unsigned int V_13 = V_16 | F_7 ( V_14 ) ;
unsigned int V_10 = 0 ;
unsigned int V_12 ;
F_3 ( V_2 , V_13 , 0x00 ) ;
F_5 ( V_2 , & V_12 , V_13 | ( 1 << 2 ) , 0x80 ) ;
V_10 |= ( V_12 << 0 ) ;
F_5 ( V_2 , & V_12 , V_13 | ( 0 << 2 ) , 0x00 ) ;
V_10 |= ( V_12 << 3 ) ;
F_5 ( V_2 , & V_12 , V_13 | ( 1 << 2 ) , 0x80 ) ;
V_10 |= ( V_12 << 6 ) ;
F_5 ( V_2 , & V_12 , V_13 | ( 0 << 2 ) , 0x00 ) ;
V_10 |= ( V_12 << 9 ) ;
F_5 ( V_2 , & V_12 , V_13 | ( 1 << 2 ) , 0x80 ) ;
V_10 |= ( V_12 << 12 ) ;
F_5 ( V_2 , & V_12 , V_13 | ( 0 << 2 ) , 0x00 ) ;
V_10 |= ( V_12 << 15 ) ;
F_5 ( V_2 , & V_12 , V_13 | ( 1 << 2 ) , 0x80 ) ;
V_10 |= ( V_12 << 18 ) ;
F_5 ( V_2 , & V_12 , V_13 | ( 0 << 2 ) , 0x00 ) ;
V_10 |= ( V_12 << 21 ) ;
F_3 ( V_2 , 0x00 , 0x80 ) ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_19 * V_20 ,
unsigned int * V_21 )
{
unsigned int V_14 = F_10 ( V_20 -> V_22 ) ;
unsigned int V_10 = ( V_18 -> V_23 >> ( 16 * V_14 ) ) & 0xffff ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_20 -> V_25 ; V_24 ++ ) {
V_10 = V_21 [ V_24 ] ;
F_6 ( V_2 , V_14 , V_10 ) ;
}
V_18 -> V_23 &= ( 0xffff << ( 16 * V_14 ) ) ;
V_18 -> V_23 |= ( V_10 << ( 16 * V_14 ) ) ;
return V_20 -> V_25 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_19 * V_20 ,
unsigned int * V_21 )
{
unsigned int V_14 = F_10 ( V_20 -> V_22 ) ;
unsigned int V_10 ;
int V_24 ;
V_10 = ( V_18 -> V_23 >> ( 16 * V_14 ) ) & 0xffff ;
for ( V_24 = 0 ; V_24 < V_20 -> V_25 ; V_24 ++ )
V_21 [ V_24 ] = V_10 ;
return V_20 -> V_25 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_19 * V_20 ,
unsigned int * V_21 )
{
unsigned int V_14 = F_10 ( V_20 -> V_22 ) ;
unsigned int V_10 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_20 -> V_25 ; V_24 ++ ) {
V_10 = F_8 ( V_2 , V_14 ) ;
V_21 [ V_24 ] = F_13 ( V_18 , V_10 ) ;
}
return V_20 -> V_25 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0x70 , 0x00 ) ;
F_3 ( V_2 , 0x74 , 0x80 ) ;
F_3 ( V_2 , 0x70 , 0x00 ) ;
F_3 ( V_2 , 0x00 , 0x80 ) ;
F_3 ( V_2 , 0x68 , 0x00 ) ;
F_3 ( V_2 , 0x6c , 0x80 ) ;
F_3 ( V_2 , 0x68 , 0x00 ) ;
F_3 ( V_2 , 0x00 , 0x80 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_17 * V_18 ;
int V_28 ;
V_28 = F_16 ( V_2 , V_27 -> V_29 [ 0 ] , 0x03 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_17 ( V_2 , 2 ) ;
if ( V_28 )
return V_28 ;
F_18 ( & V_30 ) ;
V_18 = & V_2 -> V_31 [ 0 ] ;
V_18 -> type = V_32 ;
V_18 -> V_33 = V_34 ;
V_18 -> V_35 = 2 ;
V_18 -> V_36 = 500 ;
V_18 -> V_37 = & V_38 ;
V_18 -> V_39 = F_9 ;
V_18 -> V_40 = F_11 ;
V_18 = & V_2 -> V_31 [ 1 ] ;
V_18 -> type = V_41 ;
V_18 -> V_33 = V_42 | V_43 ;
V_18 -> V_35 = 2 ;
V_18 -> V_36 = 0xffffff ;
V_18 -> V_37 = & V_38 ;
V_18 -> V_40 = F_12 ;
F_14 ( V_2 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
F_21 ( & V_30 ) ;
}
