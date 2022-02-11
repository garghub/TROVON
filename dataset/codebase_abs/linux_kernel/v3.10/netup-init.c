static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 ;
T_2 V_6 [ 3 ] ;
struct V_7 V_8 = {
. V_9 = 0x88 >> 1 ,
. V_10 = 0 ,
. V_6 = V_6 ,
. V_11 = 3
} ;
V_6 [ 0 ] = V_3 >> 8 ;
V_6 [ 1 ] = V_3 & 0xff ;
V_6 [ 2 ] = V_4 ;
V_5 = F_2 ( V_2 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( V_12 L_1 , V_13 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_4 )
{
int V_5 ;
T_2 V_6 [ 6 ] ;
struct V_7 V_8 = {
. V_9 = 0x88 >> 1 ,
. V_10 = 0 ,
. V_6 = V_6 ,
. V_11 = 6
} ;
V_6 [ 0 ] = V_3 >> 8 ;
V_6 [ 1 ] = V_3 & 0xff ;
V_6 [ 2 ] = V_4 & 0xff ;
V_6 [ 3 ] = ( V_4 >> 8 ) & 0xff ;
V_6 [ 4 ] = ( V_4 >> 16 ) & 0xff ;
V_6 [ 5 ] = V_4 >> 24 ;
V_5 = F_2 ( V_2 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( V_12 L_1 , V_13 ) ;
}
static T_2 F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 ;
T_2 V_6 [ 2 ] ;
struct V_7 V_8 = {
. V_9 = 0x88 >> 1 ,
. V_10 = 0 ,
. V_6 = V_6 ,
. V_11 = 2
} ;
V_6 [ 0 ] = V_3 >> 8 ;
V_6 [ 1 ] = V_3 & 0xff ;
V_5 = F_2 ( V_2 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( V_12 L_1 , V_13 ) ;
V_8 . V_10 = V_14 ;
V_8 . V_11 = 1 ;
V_5 = F_2 ( V_2 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( V_12 L_2 , V_13 ) ;
return V_6 [ 0 ] ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , unsigned V_15 ,
T_2 V_16 )
{
F_1 ( V_2 , V_3 , ( F_5 ( V_2 , V_3 ) & V_15 ) | V_16 ) ;
}
void F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_20 [ 2 ] ;
struct V_1 * V_2 = & V_20 -> V_21 ;
F_6 ( V_2 , 0x803 , ~ 0x10 , 0x00 ) ;
F_4 ( V_2 , 0x114 , 0xea0eb3 ) ;
F_4 ( V_2 , 0x110 , 0x090319 ) ;
F_6 ( V_2 , 0x803 , ~ 0x10 , 0x10 ) ;
}
