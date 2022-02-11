static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
V_9 -> V_12 = V_13 ;
V_11 = F_2 ( V_9 -> V_14 + V_15 ) ;
V_11 &= ~ ( V_16 | V_17 |
V_18 ) ;
F_3 ( V_11 , V_9 -> V_14 + V_15 ) ;
if ( V_7 [ 1 ] == 1 ) {
F_3 ( V_19 ,
V_9 -> V_14 + V_15 ) ;
F_3 ( 0x0 , V_2 -> V_20 + V_21 ) ;
F_3 ( 0x0 , V_2 -> V_20 + V_22 ) ;
F_3 ( 0x0 , V_2 -> V_20 + V_23 ) ;
if ( V_9 -> V_24 ) {
unsigned long V_20 ;
V_20 = V_9 -> V_24 + V_25 ;
F_3 ( 0x0 , V_20 + F_4 ( 0 ) ) ;
F_3 ( 0x0 , V_20 + F_4 ( 1 ) ) ;
F_3 ( 0x0 , V_20 + F_4 ( 2 ) ) ;
}
} else {
F_3 ( 0x0 , V_9 -> V_14 + V_15 ) ;
}
F_3 ( V_7 [ 2 ] , V_9 -> V_14 + V_26 ) ;
F_3 ( V_7 [ 3 ] , V_9 -> V_14 + V_27 ) ;
V_11 = F_2 ( V_9 -> V_14 + V_15 ) ;
V_11 &= ~ ( V_28 | V_29 |
V_16 | V_17 |
V_30 | V_31 |
V_32 | V_18 ) ;
V_11 |= F_5 ( 2 ) | V_30 ;
F_3 ( V_11 , V_9 -> V_14 + V_15 ) ;
return V_6 -> V_33 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
V_11 = F_2 ( V_9 -> V_14 + V_15 ) ;
V_11 &= ~ ( V_16 | V_17 ) ;
switch ( V_7 [ 1 ] ) {
case 0 :
V_11 &= ~ V_18 ;
break;
case 1 :
V_11 |= V_18 ;
break;
}
F_3 ( V_11 , V_9 -> V_14 + V_15 ) ;
return V_6 -> V_33 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_7 [ 0 ] = F_2 ( V_9 -> V_14 + V_34 ) &
V_35 ;
V_7 [ 1 ] = F_2 ( V_9 -> V_14 + V_36 ) ;
return V_6 -> V_33 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_37 = F_9 ( V_6 -> V_38 ) ;
unsigned long V_20 = V_9 -> V_24 + F_4 ( V_37 ) ;
unsigned int V_11 ;
V_9 -> V_12 = V_13 ;
V_11 = F_2 ( V_20 + V_15 ) ;
V_11 &= ~ ( V_16 | V_17 |
V_18 ) ;
F_3 ( V_11 , V_20 + V_15 ) ;
F_3 ( V_7 [ 3 ] , V_20 + V_27 ) ;
V_11 &= ~ ( V_39 | V_29 |
V_30 | V_31 |
V_32 ) ;
V_11 |= V_28 | F_5 ( V_7 [ 4 ] ) ;
F_3 ( V_11 , V_20 + V_15 ) ;
if ( V_7 [ 1 ] )
V_11 |= V_19 ;
else
V_11 &= ~ V_19 ;
F_3 ( V_11 , V_20 + V_15 ) ;
if ( V_7 [ 6 ] )
V_11 |= V_40 ;
else
V_11 &= ~ V_40 ;
F_3 ( V_11 , V_20 + V_15 ) ;
return V_6 -> V_33 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_37 = F_9 ( V_6 -> V_38 ) ;
unsigned long V_20 = V_9 -> V_24 + F_4 ( V_37 ) ;
unsigned int V_11 ;
V_11 = F_2 ( V_20 + V_15 ) ;
V_11 &= ~ ( V_16 | V_17 ) ;
switch ( V_7 [ 1 ] ) {
case 0 :
V_11 = 0 ;
break;
case 1 :
V_11 |= V_18 ;
break;
case 2 :
V_11 |= V_16 ;
break;
}
F_3 ( V_11 , V_20 + V_15 ) ;
return V_6 -> V_33 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_37 = F_9 ( V_6 -> V_38 ) ;
unsigned long V_20 = V_9 -> V_24 + F_4 ( V_37 ) ;
unsigned int V_41 ;
V_7 [ 0 ] = F_2 ( V_20 + V_36 ) ;
V_41 = F_2 ( V_20 + V_34 ) ;
V_7 [ 1 ] = ( V_41 & V_42 ) ? 1 : 0 ;
V_7 [ 2 ] = ( V_41 & V_43 ) ? 1 : 0 ;
V_7 [ 3 ] = ( V_41 & V_44 ) ? 1 : 0 ;
V_7 [ 4 ] = ( V_41 & V_35 ) ? 1 : 0 ;
return V_6 -> V_33 ;
}
