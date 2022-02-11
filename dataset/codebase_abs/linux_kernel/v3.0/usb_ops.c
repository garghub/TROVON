static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 ;
T_1 V_5 ;
T_3 V_6 ;
T_3 V_7 ;
T_3 V_8 ;
T_2 V_9 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_4 = 0x05 ;
V_5 = 0x01 ;
V_7 = 0 ;
V_6 = ( T_3 ) ( V_3 & 0x0000ffff ) ;
V_8 = 1 ;
F_2 ( V_11 , V_4 , V_6 , V_7 , & V_9 , V_8 ,
V_5 ) ;
return ( T_1 ) ( F_3 ( V_9 ) & 0x0ff ) ;
}
static T_3 F_4 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 ;
T_1 V_5 ;
T_3 V_6 ;
T_3 V_7 ;
T_3 V_8 ;
T_2 V_9 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_4 = 0x05 ;
V_5 = 0x01 ;
V_7 = 0 ;
V_6 = ( T_3 ) ( V_3 & 0x0000ffff ) ;
V_8 = 2 ;
F_2 ( V_11 , V_4 , V_6 , V_7 , & V_9 , V_8 ,
V_5 ) ;
return ( T_3 ) ( F_3 ( V_9 ) & 0xffff ) ;
}
static T_2 F_5 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 ;
T_1 V_5 ;
T_3 V_6 ;
T_3 V_7 ;
T_3 V_8 ;
T_2 V_9 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_4 = 0x05 ;
V_5 = 0x01 ;
V_7 = 0 ;
V_6 = ( T_3 ) ( V_3 & 0x0000ffff ) ;
V_8 = 4 ;
F_2 ( V_11 , V_4 , V_6 , V_7 , & V_9 , V_8 ,
V_5 ) ;
return F_3 ( V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_12 )
{
T_1 V_4 ;
T_1 V_5 ;
T_3 V_6 ;
T_3 V_7 ;
T_3 V_8 ;
T_2 V_9 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_4 = 0x05 ;
V_5 = 0x00 ;
V_7 = 0 ;
V_6 = ( T_3 ) ( V_3 & 0x0000ffff ) ;
V_8 = 1 ;
V_9 = V_12 ;
V_9 = F_7 ( V_9 & 0x000000ff ) ;
F_2 ( V_11 , V_4 , V_6 , V_7 , & V_9 , V_8 ,
V_5 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_3 , T_3 V_12 )
{
T_1 V_4 ;
T_1 V_5 ;
T_3 V_6 ;
T_3 V_7 ;
T_3 V_8 ;
T_2 V_9 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_4 = 0x05 ;
V_5 = 0x00 ;
V_7 = 0 ;
V_6 = ( T_3 ) ( V_3 & 0x0000ffff ) ;
V_8 = 2 ;
V_9 = V_12 ;
V_9 = F_7 ( V_9 & 0x0000ffff ) ;
F_2 ( V_11 , V_4 , V_6 , V_7 , & V_9 , V_8 ,
V_5 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_12 )
{
T_1 V_4 ;
T_1 V_5 ;
T_3 V_6 ;
T_3 V_7 ;
T_3 V_8 ;
T_2 V_9 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_4 = 0x05 ;
V_5 = 0x00 ;
V_7 = 0 ;
V_6 = ( T_3 ) ( V_3 & 0x0000ffff ) ;
V_8 = 4 ;
V_9 = F_7 ( V_12 ) ;
F_2 ( V_11 , V_4 , V_6 , V_7 , & V_9 , V_8 ,
V_5 ) ;
}
void F_10 ( T_2 * V_13 )
{
* V_13 = ( ( * V_13 ) | V_14 ) ;
}
static void F_11 ( T_1 * V_15 )
{
}
static void F_12 ( T_1 * V_15 )
{
}
static void F_13 ( T_1 * V_15 )
{
}
static void F_14 ( T_1 * V_15 )
{
}
void F_15 ( struct V_1 * V_16 )
{
V_16 -> V_17 = & F_11 ;
V_16 -> V_18 = & F_12 ;
V_16 -> V_19 = & F_13 ;
V_16 -> V_20 = & F_14 ;
}
void F_16 ( struct V_21 * V_22 )
{
memset ( ( T_1 * ) V_22 , 0 , sizeof( struct V_21 ) ) ;
V_22 -> V_23 = & F_1 ;
V_22 -> V_24 = & F_4 ;
V_22 -> V_25 = & F_5 ;
V_22 -> V_26 = & V_27 ;
V_22 -> V_28 = & F_6 ;
V_22 -> V_29 = & F_8 ;
V_22 -> V_30 = & F_9 ;
V_22 -> V_31 = & V_32 ;
V_22 -> V_33 = & V_34 ;
}
