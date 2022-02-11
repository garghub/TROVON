static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( 0xffffffff , V_2 -> V_4 + V_5 ) ;
F_2 ( 0xffffffff , V_2 -> V_4 + V_5 + 4 ) ;
F_2 ( 0xffffffff , V_2 -> V_4 + V_6 ) ;
F_2 ( 0xffffffff , V_2 -> V_4 + V_6 + 4 ) ;
F_2 ( 0 , V_2 -> V_4 + V_7 ) ;
F_2 ( 0 , V_2 -> V_4 + V_7 + 4 ) ;
V_3 = F_3 ( V_2 -> V_4 + V_8 ) ;
V_2 -> V_9 [ 0 ] = ~ V_3 ;
V_3 = F_3 ( V_2 -> V_4 + V_8 + 4 ) ;
V_2 -> V_9 [ 1 ] = ~ V_3 ;
F_2 ( 0xffffffff , V_2 -> V_4 + V_10 ) ;
F_2 ( 0xffffffff , V_2 -> V_4 + V_10 + 4 ) ;
}
static void T_2 F_4 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_13 ;
T_1 V_14 , V_15 ;
for (; ; ) {
V_15 = 0 ;
V_14 = F_5 ( V_2 -> V_4 + V_16 ) ;
if ( ! V_14 ) {
V_14 = F_5 ( V_2 -> V_4 + V_16 + 4 ) ;
V_15 = 32 ;
}
if ( V_14 == 0 )
break;
V_15 += F_6 ( V_14 ) - 1 ;
F_7 ( V_2 -> V_17 , V_15 , V_12 ) ;
}
}
static void F_8 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
unsigned int V_20 = V_19 -> V_21 >> 5 ;
unsigned int V_22 = 1u << ( V_19 -> V_21 & 0x1f ) ;
if ( V_2 -> V_9 [ V_20 ] & V_22 )
F_2 ( V_22 , V_2 -> V_4 + V_10 + V_20 * 4 ) ;
}
static void F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
unsigned int V_20 = V_19 -> V_21 >> 5 ;
unsigned int V_22 = 1u << ( V_19 -> V_21 & 0x1f ) ;
F_2 ( V_22 , V_2 -> V_4 + V_5 + V_20 * 4 ) ;
}
static void F_11 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
unsigned int V_20 = V_19 -> V_21 >> 5 ;
unsigned int V_22 = 1u << ( V_19 -> V_21 & 0x1f ) ;
F_2 ( V_22 , V_2 -> V_4 + V_23 + V_20 * 4 ) ;
}
static void F_12 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
unsigned int V_20 = V_19 -> V_21 >> 5 ;
unsigned int V_22 = 1u << ( V_19 -> V_21 & 0x1f ) ;
F_2 ( V_22 , V_2 -> V_4 + V_5 + V_20 * 4 ) ;
if ( V_2 -> V_9 [ V_20 ] & V_22 )
F_2 ( V_22 , V_2 -> V_4 + V_10 + V_20 * 4 ) ;
}
static int F_13 ( struct V_24 * V_19 , unsigned int V_15 ,
T_3 V_21 )
{
struct V_1 * V_2 = V_19 -> V_25 ;
unsigned int V_20 = V_21 >> 5 ;
unsigned int V_22 = 1u << ( V_21 & 0x1f ) ;
if ( V_20 > 1 )
return - V_26 ;
if ( V_2 -> V_9 [ V_20 ] & V_22 )
F_14 ( V_15 , & V_27 , V_28 ) ;
else
F_14 ( V_15 , & V_27 , V_29 ) ;
F_15 ( V_15 , V_2 ) ;
F_16 ( V_15 ) ;
return 0 ;
}
static int T_4 F_17 ( struct V_30 * V_31 ,
struct V_30 * V_32 )
{
void T_5 * V_12 ;
struct V_1 * V_2 ;
if ( F_18 ( V_32 , L_1 ) )
return - V_33 ;
if ( F_18 ( V_13 , L_2 ) )
return - V_33 ;
V_12 = F_19 ( V_31 , 0 ) ;
if ( F_20 ( ! V_12 ) )
return - V_34 ;
V_2 = F_21 ( sizeof( struct V_1 ) , V_35 ) ;
if ( F_20 ( ! V_2 ) ) {
F_22 ( V_12 ) ;
return - V_36 ;
}
V_2 -> V_4 = V_12 ;
F_1 ( V_2 ) ;
V_13 = V_2 ;
F_23 ( F_4 ) ;
V_2 -> V_17 = F_24 ( V_31 , V_37 , 0 ,
& V_38 , V_2 ) ;
return 0 ;
}
