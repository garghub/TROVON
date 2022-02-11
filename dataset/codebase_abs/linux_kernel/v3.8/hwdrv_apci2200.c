static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_7 [ 1 ] = F_2 ( V_9 -> V_11 + V_12 ) ;
return V_6 -> V_13 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_14 = V_7 [ 0 ] ;
unsigned int V_15 = V_7 [ 1 ] ;
V_4 -> V_16 = F_2 ( V_9 -> V_11 + V_17 ) ;
if ( V_14 ) {
V_4 -> V_16 &= ~ V_14 ;
V_4 -> V_16 |= ( V_15 & V_14 ) ;
F_4 ( V_4 -> V_16 , V_9 -> V_11 + V_17 ) ;
}
V_7 [ 1 ] = V_4 -> V_16 ;
return V_6 -> V_13 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_7 [ 0 ] == 0 ) {
F_4 ( 0x0 ,
V_9 -> V_11 + V_18 +
V_19 ) ;
F_4 ( V_7 [ 1 ] ,
V_9 -> V_11 + V_18 +
V_20 ) ;
V_7 [ 1 ] = V_7 [ 1 ] >> 16 ;
F_4 ( V_7 [ 1 ] ,
V_9 -> V_11 + V_18 +
V_20 + 2 ) ;
}
else {
F_6 ( L_1 ) ;
return - V_21 ;
}
return V_6 -> V_13 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
switch ( V_7 [ 0 ] ) {
case 0 :
F_4 ( 0x0 , V_9 -> V_11 + V_18 + V_19 ) ;
break;
case 1 :
F_4 ( 0x0001 ,
V_9 -> V_11 + V_18 +
V_19 ) ;
break;
case 2 :
F_4 ( 0x0201 ,
V_9 -> V_11 + V_18 +
V_19 ) ;
break;
default:
F_6 ( L_2 ) ;
return - V_21 ;
}
return V_6 -> V_13 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_7 [ 0 ] =
F_2 ( V_9 -> V_11 + V_18 +
V_22 ) & 0x1 ;
return V_6 -> V_13 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
F_4 ( 0x0 , V_9 -> V_11 + V_17 ) ;
F_4 ( 0x0 ,
V_9 -> V_11 + V_18 +
V_19 ) ;
F_4 ( 0x0 ,
V_9 -> V_11 + V_18 +
V_20 ) ;
F_4 ( 0x0 ,
V_9 -> V_11 + V_18 +
V_20 + 2 ) ;
return 0 ;
}
