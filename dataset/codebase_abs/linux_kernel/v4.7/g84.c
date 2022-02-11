static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , struct V_3 * * V_6 )
{
int V_7 = F_2 ( V_2 -> V_8 -> V_9 . V_10 , 16 ,
V_5 , false , V_4 , V_6 ) ;
if ( V_7 == 0 ) {
F_3 ( * V_6 ) ;
F_4 ( * V_6 , 0x00 , V_2 -> V_11 ) ;
F_4 ( * V_6 , 0x04 , 0x00000000 ) ;
F_4 ( * V_6 , 0x08 , 0x00000000 ) ;
F_4 ( * V_6 , 0x0c , 0x00000000 ) ;
F_5 ( * V_6 ) ;
}
return V_7 ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , struct V_3 * * V_6 )
{
return F_2 ( V_2 -> V_8 -> V_9 . V_10 , 256 ,
V_5 , true , V_4 , V_6 ) ;
}
static void
F_7 ( struct V_12 * V_13 )
{
struct V_14 * V_9 = & V_13 -> V_9 ;
struct V_15 * V_10 = V_9 -> V_10 ;
struct V_16 * V_17 = V_10 -> V_17 ;
struct V_18 * V_19 ;
T_1 V_20 = F_8 ( V_10 , 0x102130 ) ;
T_1 V_21 = F_8 ( V_10 , 0x102190 ) ;
T_1 V_22 = F_8 ( V_10 , 0x102194 ) ;
T_1 V_23 = F_8 ( V_10 , 0x102188 ) & 0x7fffffff ;
unsigned long V_24 ;
char V_25 [ 128 ] ;
V_19 = F_9 ( V_17 , ( V_26 ) V_23 << 12 , & V_24 ) ;
if ( V_20 ) {
F_10 ( V_25 , sizeof( V_25 ) , V_27 , V_20 ) ;
F_11 ( V_9 , L_1
L_2 , V_20 , V_25 ,
V_19 ? V_19 -> V_28 : - 1 , ( V_26 ) V_23 << 12 ,
V_19 ? V_19 -> V_2 . V_29 -> V_30 : L_3 ,
V_21 , V_22 ) ;
}
F_12 ( V_17 , V_24 , & V_19 ) ;
F_13 ( V_10 , 0x102130 , V_20 ) ;
F_13 ( V_10 , 0x10200c , 0x10 ) ;
}
static int
F_14 ( struct V_12 * V_13 )
{
struct V_15 * V_10 = V_13 -> V_9 . V_10 ;
F_13 ( V_10 , 0x102130 , 0xffffffff ) ;
F_13 ( V_10 , 0x102140 , 0xffffffbf ) ;
F_13 ( V_10 , 0x10200c , 0x00000010 ) ;
return 0 ;
}
int
F_15 ( struct V_15 * V_10 , int V_31 ,
struct V_12 * * V_32 )
{
return F_16 ( & V_33 , V_10 , V_31 , true , V_32 ) ;
}
