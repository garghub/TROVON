static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_5 , V_3 ) ;
if ( V_7 < 0 )
F_3 ( & V_5 -> V_8 ,
L_1 ,
V_3 , V_7 ) ;
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_9 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int error ;
error = F_5 ( V_5 , V_3 , V_9 ) ;
if ( error < 0 ) {
F_3 ( & V_5 -> V_8 ,
L_2 ,
V_3 , error ) ;
return error ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 ,
T_1 * V_10 , T_2 V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_12 ;
V_12 = F_7 ( V_5 , V_3 , V_11 , V_10 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_5 -> V_8 ,
L_3 ,
V_13 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static void F_8 ( struct V_14 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_15 ;
int V_16 , V_17 , V_18 ;
int V_7 ;
T_1 V_10 [ 6 ] ;
V_7 = F_1 ( V_2 , V_19 ) ;
if ( V_7 < 0 )
return;
if ( ! ( V_7 & V_20 ) )
return;
V_7 = F_6 ( V_2 , V_13 , V_10 , sizeof( V_10 ) ) ;
if ( V_7 < 0 )
return;
V_16 = ( ( int ) ( V_21 ) V_10 [ 1 ] << 4 ) | ( V_10 [ 0 ] & 0xf ) ;
V_17 = ( ( int ) ( V_21 ) V_10 [ 3 ] << 4 ) | ( V_10 [ 2 ] & 0xf ) ;
V_18 = ( ( int ) ( V_21 ) V_10 [ 5 ] << 4 ) | ( V_10 [ 4 ] & 0xf ) ;
F_9 ( V_8 -> V_22 , V_23 , V_16 ) ;
F_9 ( V_8 -> V_22 , V_24 , V_17 ) ;
F_9 ( V_8 -> V_22 , V_25 , V_18 ) ;
F_10 ( V_8 -> V_22 ) ;
}
static void F_11 ( struct V_14 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_15 ;
int V_12 ;
V_12 = F_4 ( V_2 , V_26 , 0x07 ) ;
if ( V_12 )
return;
V_12 = F_4 ( V_2 , V_27 , 0x01 ) ;
if ( V_12 < 0 )
return;
F_12 ( V_28 ) ;
}
static void F_13 ( struct V_14 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_15 ;
F_4 ( V_2 , V_27 , 0x00 ) ;
F_4 ( V_2 , V_29 , 0x01 ) ;
}
static int F_14 ( struct V_4 * V_5 ,
const struct V_30 * V_31 )
{
struct V_14 * V_32 ;
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_15 ( & V_5 -> V_8 , sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_32 = F_16 ( & V_5 -> V_8 ) ;
if ( ! V_32 )
return - V_34 ;
V_2 -> V_6 = V_5 ;
V_2 -> V_32 = V_32 ;
V_32 -> V_15 = V_2 ;
V_32 -> V_22 -> V_35 = V_36 ;
V_32 -> V_22 -> V_31 . V_37 = V_38 ;
V_32 -> V_39 = F_8 ;
V_32 -> V_40 = V_41 ;
V_32 -> V_42 = V_43 ;
V_32 -> V_44 = F_11 ;
V_32 -> V_45 = F_13 ;
F_17 ( V_46 , V_32 -> V_22 -> V_47 ) ;
F_18 ( V_32 -> V_22 , V_23 , - 2048 , 2047 , 32 , 32 ) ;
F_18 ( V_32 -> V_22 , V_24 , - 2048 , 2047 , 32 , 32 ) ;
F_18 ( V_32 -> V_22 , V_25 , - 2048 , 2047 , 32 , 32 ) ;
V_12 = F_19 ( V_32 ) ;
if ( V_12 ) {
F_3 ( & V_5 -> V_8 , L_4 ) ;
return V_12 ;
}
F_20 ( V_5 , V_2 ) ;
return 0 ;
}
