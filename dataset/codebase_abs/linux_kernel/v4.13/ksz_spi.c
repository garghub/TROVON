static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
unsigned int V_5 )
{
T_1 V_6 ;
int V_7 ;
V_6 = V_3 & V_8 ;
V_6 |= V_9 << V_10 ;
V_6 <<= V_11 ;
V_6 = F_2 ( V_6 ) ;
V_7 = F_3 ( V_2 , & V_6 , 4 , V_4 , V_5 ) ;
return V_7 ;
}
static int F_4 ( struct V_12 * V_13 , T_1 V_3 , T_2 * V_14 ,
unsigned int V_5 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
return F_1 ( V_2 , V_3 , V_14 , V_5 ) ;
}
static int F_5 ( struct V_12 * V_13 , T_1 V_3 , T_2 * V_4 )
{
return F_4 ( V_13 , V_3 , V_4 , 1 ) ;
}
static int F_6 ( struct V_12 * V_13 , T_1 V_3 , T_3 * V_4 )
{
int V_7 = F_4 ( V_13 , V_3 , ( T_2 * ) V_4 , 2 ) ;
if ( ! V_7 )
* V_4 = F_7 ( * V_4 ) ;
return V_7 ;
}
static int F_8 ( struct V_12 * V_13 , T_1 V_3 , T_1 * V_4 )
{
int V_7 ;
* V_4 = 0 ;
V_7 = F_4 ( V_13 , V_3 , ( T_2 * ) V_4 , 3 ) ;
if ( ! V_7 ) {
* V_4 = F_9 ( * V_4 ) ;
* V_4 >>= 8 ;
}
return V_7 ;
}
static int F_10 ( struct V_12 * V_13 , T_1 V_3 , T_1 * V_4 )
{
int V_7 = F_4 ( V_13 , V_3 , ( T_2 * ) V_4 , 4 ) ;
if ( ! V_7 )
* V_4 = F_9 ( * V_4 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
unsigned int V_5 )
{
T_1 V_6 ;
T_2 V_14 [ 12 ] ;
int V_16 ;
V_6 = V_3 & V_8 ;
V_6 |= ( V_17 << V_10 ) ;
V_6 <<= V_11 ;
V_6 = F_2 ( V_6 ) ;
V_14 [ 0 ] = V_6 & 0xFF ;
V_14 [ 1 ] = ( V_6 & 0xFF00 ) >> 8 ;
V_14 [ 2 ] = ( V_6 & 0xFF0000 ) >> 16 ;
V_14 [ 3 ] = ( V_6 & 0xFF000000 ) >> 24 ;
for ( V_16 = 0 ; V_16 < V_5 ; V_16 ++ )
V_14 [ V_16 + 4 ] = V_4 [ V_16 ] ;
return F_12 ( V_2 , & V_14 , 4 + V_5 ) ;
}
static int F_13 ( struct V_12 * V_13 , T_1 V_3 , T_2 V_18 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
return F_11 ( V_2 , V_3 , & V_18 , 1 ) ;
}
static int F_14 ( struct V_12 * V_13 , T_1 V_3 , T_3 V_18 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
V_18 = F_15 ( V_18 ) ;
return F_11 ( V_2 , V_3 , ( T_2 * ) & V_18 , 2 ) ;
}
static int F_16 ( struct V_12 * V_13 , T_1 V_3 , T_1 V_18 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
V_18 <<= 8 ;
V_18 = F_2 ( V_18 ) ;
return F_11 ( V_2 , V_3 , ( T_2 * ) & V_18 , 3 ) ;
}
static int F_17 ( struct V_12 * V_13 , T_1 V_3 , T_1 V_18 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
V_18 = F_2 ( V_18 ) ;
return F_11 ( V_2 , V_3 , ( T_2 * ) & V_18 , 4 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_7 ;
V_13 = F_19 ( & V_2 -> V_13 , & V_19 , V_2 ) ;
if ( ! V_13 )
return - V_20 ;
if ( V_2 -> V_13 . V_21 )
V_13 -> V_22 = V_2 -> V_13 . V_21 ;
V_7 = F_20 ( V_13 ) ;
if ( V_7 )
return V_7 ;
F_21 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_23 ( V_2 ) ;
if ( V_13 )
F_24 ( V_13 ) ;
return 0 ;
}
