static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 * V_5 )
{
T_1 T_2 * V_6 = V_2 -> V_7 ;
* V_5 = F_2 ( V_6 + ( V_3 << 8 ) + V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_3 * V_5 )
{
T_1 T_2 * V_6 = V_2 -> V_7 ;
if ( F_4 ( V_4 % 2 ) )
return - V_8 ;
if ( V_2 -> V_9 && V_2 -> V_9 -> V_10 )
* V_5 = F_5 ( V_6 + ( V_3 << 8 ) + V_4 ) ;
else
* V_5 = F_6 ( V_6 + ( V_3 << 8 ) + V_4 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_4 * V_5 )
{
T_1 T_2 * V_6 = V_2 -> V_7 ;
if ( F_4 ( V_4 % 4 ) )
return - V_8 ;
if ( V_2 -> V_9 && V_2 -> V_9 -> V_10 )
* V_5 = F_8 ( V_6 + ( V_3 << 8 ) + V_4 ) ;
else
* V_5 = F_9 ( V_6 + ( V_3 << 8 ) + V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_5 * V_5 )
{
T_1 T_2 * V_6 = V_2 -> V_7 ;
if ( F_4 ( V_4 % 2 ) )
return - V_8 ;
if ( V_4 % 4 ) {
T_3 V_11 ;
T_4 V_12 ;
if ( V_2 -> V_9 && V_2 -> V_9 -> V_10 ) {
V_11 = F_5 ( V_6 + ( V_3 << 8 ) + V_4 ) ;
V_12 = F_8 ( V_6 + ( V_3 << 8 ) + V_4 + 2 ) ;
} else {
V_11 = F_6 ( V_6 + ( V_3 << 8 ) + V_4 ) ;
V_12 = F_9 ( V_6 + ( V_3 << 8 ) + V_4 + 2 ) ;
}
* V_5 = ( ( T_5 ) V_12 << 16 ) | V_11 ;
} else {
T_4 V_11 ;
T_3 V_12 ;
if ( V_2 -> V_9 && V_2 -> V_9 -> V_10 ) {
V_11 = F_8 ( V_6 + ( V_3 << 8 ) + V_4 ) ;
V_12 = F_5 ( V_6 + ( V_3 << 8 ) + V_4 + 4 ) ;
} else {
V_11 = F_9 ( V_6 + ( V_3 << 8 ) + V_4 ) ;
V_12 = F_6 ( V_6 + ( V_3 << 8 ) + V_4 + 4 ) ;
}
* V_5 = ( ( T_5 ) V_12 << 32 ) | V_11 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_5 * V_5 )
{
T_1 T_2 * V_6 = V_2 -> V_7 ;
T_4 V_12 , V_11 ;
if ( F_4 ( V_4 % 4 ) )
return - V_8 ;
if ( V_2 -> V_9 && V_2 -> V_9 -> V_10 ) {
V_11 = F_8 ( V_6 + ( V_3 << 8 ) + V_4 ) ;
V_12 = F_8 ( V_6 + ( V_3 << 8 ) + V_4 + 4 ) ;
} else {
V_11 = F_9 ( V_6 + ( V_3 << 8 ) + V_4 ) ;
V_12 = F_9 ( V_6 + ( V_3 << 8 ) + V_4 + 4 ) ;
}
* V_5 = ( ( T_5 ) V_12 << 32 ) | V_11 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_13 )
{
T_1 T_2 * V_6 = V_2 -> V_7 ;
F_13 ( V_13 , V_6 + ( V_3 << 8 ) + V_4 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_3 V_13 )
{
T_1 T_2 * V_6 = V_2 -> V_7 ;
if ( F_4 ( V_4 % 2 ) )
return - V_8 ;
if ( V_2 -> V_9 && V_2 -> V_9 -> V_10 )
F_15 ( V_13 , V_6 + ( V_3 << 8 ) + V_4 ) ;
else
F_16 ( V_13 , V_6 + ( V_3 << 8 ) + V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_4 V_13 )
{
T_1 T_2 * V_6 = V_2 -> V_7 ;
if ( F_4 ( V_4 % 4 ) )
return - V_8 ;
if ( V_2 -> V_9 && V_2 -> V_9 -> V_10 )
F_18 ( V_13 , V_6 + ( V_3 << 8 ) + V_4 ) ;
else
F_19 ( V_13 , V_6 + ( V_3 << 8 ) + V_4 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_5 V_13 )
{
if ( F_4 ( V_4 % 2 ) )
return - V_8 ;
if ( V_4 % 4 ) {
T_4 V_12 = ( T_4 ) ( V_13 >> 16 ) ;
T_3 V_11 = ( T_3 ) V_13 ;
F_14 ( V_2 , V_3 , V_4 , V_11 ) ;
F_17 ( V_2 , V_3 , V_4 + 2 , V_12 ) ;
} else {
T_3 V_12 = ( T_3 ) ( V_13 >> 32 ) ;
T_4 V_11 = ( T_4 ) V_13 ;
F_17 ( V_2 , V_3 , V_4 , V_11 ) ;
F_14 ( V_2 , V_3 , V_4 + 4 , V_12 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_5 V_13 )
{
T_4 V_12 , V_11 ;
V_12 = F_22 ( V_13 ) ;
V_11 = F_23 ( V_13 ) ;
if ( F_4 ( V_4 % 4 ) )
return - V_8 ;
F_17 ( V_2 , V_3 , V_4 , V_11 ) ;
F_17 ( V_2 , V_3 , V_4 + 4 , V_12 ) ;
return 0 ;
}
static int F_24 ( struct V_14 * V_15 )
{
struct V_16 * V_9 = V_15 -> V_2 . V_17 ;
struct V_1 * V_2 ;
if ( ! V_9 )
return - V_8 ;
V_2 = F_25 ( & V_15 -> V_2 , & V_18 , V_9 -> V_6 ) ;
if ( ! V_2 )
return - V_19 ;
V_2 -> V_9 = V_9 ;
F_26 ( V_15 , V_2 ) ;
return F_27 ( V_2 ) ;
}
static int F_28 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_29 ( V_15 ) ;
if ( V_2 )
F_30 ( V_2 ) ;
return 0 ;
}
