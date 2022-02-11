static T_1 F_1 ( int V_1 , int V_2 )
{
if ( V_2 == 1 && V_1 == 0x3d )
return 0x01 ;
else if ( V_2 == 2 && V_1 == 0x3c )
return 0x0100 ;
else if ( V_2 == 4 && V_1 == 0x3c )
return 0x00000100 ;
return 0 ;
}
static int F_2 ( struct V_3 * V_4 , unsigned int V_5 ,
int V_1 , int V_2 , T_1 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_2 * V_9 = V_8 -> V_10 ;
int V_11 = F_4 ( V_5 ) ;
int V_12 = F_5 ( V_5 ) ;
volatile void * V_13 ;
T_1 V_14 , V_15 , V_16 ;
int V_17 ;
V_13 = & V_9 -> V_18 [ V_11 ] . V_19 [ V_12 ] . V_20 [ V_21 ] ;
if ( F_6 ( V_14 , ( T_1 * ) V_13 ) )
return V_22 ;
if ( V_14 == ( V_23 | ( V_24 << 16 ) ) )
goto V_25;
V_13 = & V_9 -> V_18 [ V_11 ] . V_19 [ V_12 ] . V_20 [ V_1 ^ ( 4 - V_2 ) ] ;
if ( V_2 == 1 )
V_17 = F_6 ( * V_6 , ( V_26 * ) V_13 ) ;
else if ( V_2 == 2 )
V_17 = F_6 ( * V_6 , ( V_27 * ) V_13 ) ;
else
V_17 = F_6 ( * V_6 , ( T_1 * ) V_13 ) ;
return V_17 ? V_22 : V_28 ;
V_25:
if ( ( V_1 >= 0x14 && V_1 < 0x40 ) || ( V_1 >= 0x48 ) ) {
* V_6 = F_1 ( V_1 , V_2 ) ;
return V_28 ;
}
V_13 = & V_9 -> V_18 [ V_11 ] . V_19 [ V_12 ] . V_29 [ V_1 >> 2 ] ;
if ( F_6 ( V_14 , ( T_1 * ) V_13 ) )
return V_22 ;
V_15 = ( ( V_1 & 3 ) << 3 ) ;
V_16 = ( 0xffffffffU >> ( ( 4 - V_2 ) << 3 ) ) ;
* V_6 = ( V_14 >> V_15 ) & V_16 ;
return V_28 ;
}
static int F_7 ( struct V_3 * V_4 , unsigned int V_5 ,
int V_1 , int V_2 , T_1 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_2 * V_9 = V_8 -> V_10 ;
int V_30 = V_4 -> V_31 ;
int V_11 = F_4 ( V_5 ) ;
int V_12 = F_5 ( V_5 ) ;
volatile void * V_13 ;
T_1 V_14 , V_15 , V_16 ;
int V_17 ;
V_9 -> V_32 = ( V_30 << 16 ) | ( V_11 << 11 ) ;
V_13 = & V_9 -> V_33 . V_20 [ ( V_12 << 8 ) | V_21 ] ;
if ( F_6 ( V_14 , ( T_1 * ) V_13 ) )
return V_22 ;
if ( V_14 == ( V_23 | ( V_24 << 16 ) ) )
goto V_25;
V_9 -> V_32 = ( V_30 << 16 ) | ( V_11 << 11 ) ;
V_13 = & V_9 -> V_33 . V_20 [ ( V_12 << 8 ) | ( V_1 ^ ( 4 - V_2 ) ) ] ;
if ( V_2 == 1 )
V_17 = F_6 ( * V_6 , ( V_26 * ) V_13 ) ;
else if ( V_2 == 2 )
V_17 = F_6 ( * V_6 , ( V_27 * ) V_13 ) ;
else
V_17 = F_6 ( * V_6 , ( T_1 * ) V_13 ) ;
return V_17 ? V_22 : V_28 ;
V_25:
if ( ( V_1 >= 0x14 && V_1 < 0x40 ) || ( V_1 >= 0x48 ) ) {
* V_6 = F_1 ( V_1 , V_2 ) ;
return V_28 ;
}
V_9 -> V_32 = ( V_30 << 16 ) | ( V_11 << 11 ) ;
V_13 = & V_9 -> V_33 . V_20 [ ( V_12 << 8 ) | V_1 ] ;
if ( F_6 ( V_14 , ( T_1 * ) V_13 ) )
return V_22 ;
V_15 = ( ( V_1 & 3 ) << 3 ) ;
V_16 = ( 0xffffffffU >> ( ( 4 - V_2 ) << 3 ) ) ;
* V_6 = ( V_14 >> V_15 ) & V_16 ;
return V_28 ;
}
static int F_8 ( struct V_3 * V_4 , unsigned int V_5 ,
int V_1 , int V_2 , T_1 * V_6 )
{
if ( V_4 -> V_31 > 0 )
return F_7 ( V_4 , V_5 , V_1 , V_2 , V_6 ) ;
return F_2 ( V_4 , V_5 , V_1 , V_2 , V_6 ) ;
}
static int F_9 ( struct V_3 * V_4 , unsigned int V_5 ,
int V_1 , int V_2 , T_1 V_6 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_2 * V_9 = V_8 -> V_10 ;
int V_11 = F_4 ( V_5 ) ;
int V_12 = F_5 ( V_5 ) ;
volatile void * V_13 ;
T_1 V_14 , V_15 , V_16 , V_34 ;
int V_17 ;
V_13 = & V_9 -> V_18 [ V_11 ] . V_19 [ V_12 ] . V_20 [ V_21 ] ;
if ( F_6 ( V_14 , ( T_1 * ) V_13 ) )
return V_22 ;
if ( V_14 == ( V_23 | ( V_24 << 16 ) ) )
goto V_25;
V_13 = & V_9 -> V_18 [ V_11 ] . V_19 [ V_12 ] . V_20 [ V_1 ^ ( 4 - V_2 ) ] ;
if ( V_2 == 1 ) {
V_17 = F_10 ( V_6 , ( V_26 * ) V_13 ) ;
} else if ( V_2 == 2 ) {
V_17 = F_10 ( V_6 , ( V_27 * ) V_13 ) ;
} else {
V_17 = F_10 ( V_6 , ( T_1 * ) V_13 ) ;
}
if ( V_17 )
return V_22 ;
return V_28 ;
V_25:
if ( ( V_1 >= 0x14 && V_1 < 0x40 ) || ( V_1 >= 0x48 ) )
return V_28 ;
V_13 = & V_9 -> V_18 [ V_11 ] . V_19 [ V_12 ] . V_29 [ V_1 >> 2 ] ;
if ( F_6 ( V_14 , ( T_1 * ) V_13 ) )
return V_22 ;
V_15 = ( ( V_1 & 3 ) << 3 ) ;
V_16 = ( 0xffffffffU >> ( ( 4 - V_2 ) << 3 ) ) ;
V_34 = V_16 << V_15 ;
V_14 = ( V_14 & ~ V_34 ) | ( ( V_6 & V_16 ) << V_15 ) ;
if ( F_10 ( V_14 , ( T_1 * ) V_13 ) )
return V_22 ;
return V_28 ;
}
static int F_11 ( struct V_3 * V_4 , unsigned int V_5 ,
int V_1 , int V_2 , T_1 V_6 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_2 * V_9 = V_8 -> V_10 ;
int V_11 = F_4 ( V_5 ) ;
int V_12 = F_5 ( V_5 ) ;
int V_30 = V_4 -> V_31 ;
volatile void * V_13 ;
T_1 V_14 , V_15 , V_16 , V_34 ;
int V_17 ;
V_9 -> V_32 = ( V_30 << 16 ) | ( V_11 << 11 ) ;
V_13 = & V_9 -> V_33 . V_20 [ ( V_12 << 8 ) | V_21 ] ;
if ( F_6 ( V_14 , ( T_1 * ) V_13 ) )
return V_22 ;
if ( V_14 == ( V_23 | ( V_24 << 16 ) ) )
goto V_25;
V_13 = & V_9 -> V_33 . V_20 [ ( V_12 << 8 ) | ( V_1 ^ ( 4 - V_2 ) ) ] ;
if ( V_2 == 1 ) {
V_17 = F_10 ( V_6 , ( V_26 * ) V_13 ) ;
} else if ( V_2 == 2 ) {
V_17 = F_10 ( V_6 , ( V_27 * ) V_13 ) ;
} else {
V_17 = F_10 ( V_6 , ( T_1 * ) V_13 ) ;
}
if ( V_17 )
return V_22 ;
return V_28 ;
V_25:
if ( ( V_1 >= 0x14 && V_1 < 0x40 ) || ( V_1 >= 0x48 ) )
return V_28 ;
V_13 = & V_9 -> V_18 [ V_11 ] . V_19 [ V_12 ] . V_29 [ V_1 >> 2 ] ;
if ( F_6 ( V_14 , ( T_1 * ) V_13 ) )
return V_22 ;
V_15 = ( ( V_1 & 3 ) << 3 ) ;
V_16 = ( 0xffffffffU >> ( ( 4 - V_2 ) << 3 ) ) ;
V_34 = V_16 << V_15 ;
V_14 = ( V_14 & ~ V_34 ) | ( ( V_6 & V_16 ) << V_15 ) ;
if ( F_10 ( V_14 , ( T_1 * ) V_13 ) )
return V_22 ;
return V_28 ;
}
static int F_12 ( struct V_3 * V_4 , unsigned int V_5 ,
int V_1 , int V_2 , T_1 V_6 )
{
if ( V_4 -> V_31 > 0 )
return F_11 ( V_4 , V_5 , V_1 , V_2 , V_6 ) ;
return F_9 ( V_4 , V_5 , V_1 , V_2 , V_6 ) ;
}
