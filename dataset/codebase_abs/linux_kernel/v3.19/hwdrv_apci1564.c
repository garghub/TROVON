static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
V_9 -> V_12 = V_13 ;
V_11 = F_2 ( V_9 -> V_14 + V_15 ) ;
V_11 &= 0xfffff9fe ;
F_3 ( V_11 , V_9 -> V_14 + V_15 ) ;
if ( V_7 [ 1 ] == 1 ) {
F_3 ( 0x02 , V_9 -> V_14 + V_15 ) ;
F_3 ( 0x0 , V_2 -> V_16 + V_17 ) ;
F_3 ( 0x0 , V_2 -> V_16 + V_18 ) ;
F_3 ( 0x0 , V_2 -> V_16 + V_19 ) ;
if ( V_9 -> V_20 ) {
unsigned long V_16 ;
V_16 = V_9 -> V_20 + V_21 ;
F_3 ( 0x0 , V_16 + F_4 ( 0 ) ) ;
F_3 ( 0x0 , V_16 + F_4 ( 1 ) ) ;
F_3 ( 0x0 , V_16 + F_4 ( 2 ) ) ;
}
} else {
F_3 ( 0x0 , V_9 -> V_14 + V_15 ) ;
}
F_3 ( V_7 [ 2 ] , V_9 -> V_14 + V_22 ) ;
F_3 ( V_7 [ 3 ] , V_9 -> V_14 + V_23 ) ;
V_11 = F_2 ( V_9 -> V_14 + V_15 ) ;
V_11 &= 0xfff719e2 ;
V_11 |= ( 2 << 13 ) | 0x10 ;
F_3 ( V_11 , V_9 -> V_14 + V_15 ) ;
return V_6 -> V_24 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
V_11 = F_2 ( V_9 -> V_14 + V_15 ) ;
switch ( V_7 [ 1 ] ) {
case 0 :
V_11 &= 0xfffff9fe ;
break;
case 1 :
V_11 &= 0xfffff9ff ;
V_11 |= 0x1 ;
break;
}
F_3 ( V_11 , V_9 -> V_14 + V_15 ) ;
return V_6 -> V_24 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_7 [ 0 ] = F_2 ( V_9 -> V_14 + V_25 ) & 0x1 ;
V_7 [ 1 ] = F_2 ( V_9 -> V_14 + V_26 ) ;
return V_6 -> V_24 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_27 = F_8 ( V_6 -> V_28 ) ;
unsigned long V_16 = V_9 -> V_20 + F_4 ( V_27 ) ;
unsigned int V_11 ;
V_9 -> V_12 = V_13 ;
V_11 = F_2 ( V_16 + V_15 ) ;
V_11 &= 0xfffff9fe ;
F_3 ( V_11 , V_16 + V_15 ) ;
F_3 ( V_7 [ 3 ] , V_16 + V_23 ) ;
V_11 &= 0xfffc19e2 ;
V_11 |= 0x80000 | ( V_7 [ 4 ] << 16 ) ;
F_3 ( V_11 , V_16 + V_15 ) ;
V_11 &= 0xfffff9fd ;
V_11 |= ( V_7 [ 1 ] << 1 ) ;
F_3 ( V_11 , V_16 + V_15 ) ;
V_11 &= 0xfffbf9ff ;
V_11 |= ( V_7 [ 6 ] << 18 ) ;
F_3 ( V_11 , V_16 + V_15 ) ;
return V_6 -> V_24 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_27 = F_8 ( V_6 -> V_28 ) ;
unsigned long V_16 = V_9 -> V_20 + F_4 ( V_27 ) ;
unsigned int V_11 ;
V_11 = F_2 ( V_16 + V_15 ) ;
switch ( V_7 [ 1 ] ) {
case 0 :
V_11 = 0 ;
break;
case 1 :
V_11 &= 0xfffff9ff ;
V_11 |= 0x1 ;
break;
case 2 :
V_11 &= 0xfffff9ff ;
V_11 |= 0x400 ;
break;
}
F_3 ( V_11 , V_16 + V_15 ) ;
return V_6 -> V_24 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_27 = F_8 ( V_6 -> V_28 ) ;
unsigned long V_16 = V_9 -> V_20 + F_4 ( V_27 ) ;
unsigned int V_29 ;
V_7 [ 0 ] = F_2 ( V_16 + V_26 ) ;
V_29 = F_2 ( V_16 + V_25 ) ;
V_7 [ 1 ] = ( V_29 >> 1 ) & 1 ;
V_7 [ 2 ] = ( V_29 >> 2 ) & 1 ;
V_7 [ 3 ] = ( V_29 >> 3 ) & 1 ;
V_7 [ 4 ] = ( V_29 >> 0 ) & 1 ;
return V_6 -> V_24 ;
}
