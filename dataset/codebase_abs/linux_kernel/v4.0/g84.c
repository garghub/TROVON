static int
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
V_11 = F_2 ( V_2 , V_3 , V_5 , 0 , V_2 ,
16 , 16 , 0 , & V_10 ) ;
* V_8 = F_3 ( V_10 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_10 , 0x00 , F_5 ( V_10 ) ) ;
F_4 ( V_10 , 0x04 , 0x00000000 ) ;
F_4 ( V_10 , 0x08 , 0x00000000 ) ;
F_4 ( V_10 , 0x0c , 0x00000000 ) ;
return 0 ;
}
static void
F_6 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_14 ( V_13 ) ;
struct V_16 * V_3 = F_7 ( V_13 ) ;
struct V_1 * V_17 ;
struct V_18 * V_19 = ( void * ) V_13 ;
T_1 V_20 = F_8 ( V_19 , 0x102130 ) ;
T_1 V_21 = F_8 ( V_19 , 0x102190 ) ;
T_1 V_6 = F_8 ( V_19 , 0x102194 ) ;
T_1 V_22 = F_8 ( V_19 , 0x102188 ) & 0x7fffffff ;
int V_23 ;
V_17 = F_9 ( V_3 , V_22 ) ;
V_23 = V_15 -> V_23 ( V_15 , V_17 ) ;
if ( V_20 ) {
F_10 ( V_19 , L_1 , L_2 ) ;
F_11 ( V_24 , V_20 ) ;
F_12 ( L_3 ,
V_23 , ( V_25 ) V_22 << 12 , F_13 ( V_17 ) ,
V_21 , V_6 ) ;
}
F_14 ( V_19 , 0x102130 , V_20 ) ;
F_14 ( V_19 , 0x10200c , 0x10 ) ;
F_15 ( V_17 ) ;
}
static int
F_16 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_18 * V_19 ;
int V_11 ;
V_11 = F_17 ( V_2 , V_3 , V_5 , true ,
L_4 , L_5 , & V_19 ) ;
* V_8 = F_3 ( V_19 ) ;
if ( V_11 )
return V_11 ;
F_18 ( V_19 ) -> V_26 = 0x00004000 ;
F_18 ( V_19 ) -> V_27 = F_6 ;
F_7 ( V_19 ) -> V_28 = & V_29 ;
F_7 ( V_19 ) -> V_30 = V_31 ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_32 )
{
struct V_18 * V_19 = ( void * ) V_32 ;
int V_11 ;
V_11 = F_20 ( & V_19 -> V_33 ) ;
if ( V_11 )
return V_11 ;
F_14 ( V_19 , 0x102130 , 0xffffffff ) ;
F_14 ( V_19 , 0x102140 , 0xffffffbf ) ;
F_14 ( V_19 , 0x10200c , 0x00000010 ) ;
return 0 ;
}
