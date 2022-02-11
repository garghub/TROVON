int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_8 ;
unsigned int V_9 = 0 ;
unsigned int V_10 = 0 ;
V_11 -> V_12 = V_13 ;
if ( V_7 [ 0 ] == V_14 ) {
V_9 = V_9 | V_7 [ 2 ] ;
V_10 = V_10 | V_7 [ 3 ] ;
F_2 ( V_9 ,
V_11 -> V_15 + V_16 ) ;
F_2 ( V_10 ,
V_11 -> V_15 + V_17 ) ;
if ( V_7 [ 1 ] == V_18 ) {
F_2 ( 0x4 , V_11 -> V_15 + V_19 ) ;
V_8 =
F_3 ( V_11 -> V_15 + V_19 ) ;
}
else
F_2 ( 0x6 , V_11 -> V_15 + V_19 ) ;
}
else {
V_9 = V_9 & 0xFFFF0000 ;
V_10 = V_10 & 0xFFFF0000 ;
F_2 ( V_9 ,
V_11 -> V_15 + V_16 ) ;
F_2 ( V_10 ,
V_11 -> V_15 + V_17 ) ;
F_2 ( 0x0 , V_11 -> V_15 + V_19 ) ;
}
return V_6 -> V_20 ;
}
int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_8 = 0 ;
unsigned int V_21 ;
V_21 = F_5 ( V_6 -> V_22 ) ;
if ( V_21 <= 31 ) {
V_8 = ( unsigned int ) F_3 ( V_11 -> V_15 + V_23 ) ;
* V_7 = ( V_8 >> V_21 ) & 0x1 ;
}
else {
return - V_24 ;
}
return V_6 -> V_20 ;
}
int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_25 = V_7 [ 0 ] ;
unsigned int V_26 = 0 ;
unsigned int V_27 ;
V_27 = F_5 ( V_6 -> V_22 ) ;
if ( V_7 [ 1 ] == 0 ) {
* V_7 = ( unsigned int ) F_3 ( V_11 -> V_15 + V_23 ) ;
switch ( V_27 ) {
case 2 :
V_26 = 3 ;
* V_7 = ( * V_7 >> ( 2 * V_25 ) ) & V_26 ;
break;
case 4 :
V_26 = 15 ;
* V_7 = ( * V_7 >> ( 4 * V_25 ) ) & V_26 ;
break;
case 8 :
V_26 = 255 ;
* V_7 = ( * V_7 >> ( 8 * V_25 ) ) & V_26 ;
break;
case 16 :
V_26 = 65535 ;
* V_7 = ( * V_7 >> ( 16 * V_25 ) ) & V_26 ;
break;
case 31 :
break;
default:
return - V_24 ;
break;
}
}
else {
if ( V_7 [ 1 ] == 1 )
* V_7 = V_28 ;
}
return V_6 -> V_20 ;
}
static void F_7 ( int V_29 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
unsigned int V_31 ;
V_31 = F_3 ( V_11 -> V_15 + V_19 ) ;
F_2 ( V_31 & V_32 ,
V_11 -> V_15 + V_19 ) ;
V_28 =
F_3 ( V_11 -> V_15 + V_33 ) ;
V_28 = V_28 & 0X0000FFFF ;
F_8 ( V_34 , V_11 -> V_12 , 0 ) ;
F_2 ( V_31 , V_11 -> V_15 + V_19 ) ;
return;
}
int F_9 ( struct V_1 * V_2 )
{
F_2 ( 0x0 , V_11 -> V_15 + V_19 ) ;
F_3 ( V_11 -> V_15 + V_33 ) ;
F_2 ( 0x0 , V_11 -> V_15 + V_16 ) ;
F_2 ( 0x0 , V_11 -> V_15 + V_17 ) ;
return 0 ;
}
