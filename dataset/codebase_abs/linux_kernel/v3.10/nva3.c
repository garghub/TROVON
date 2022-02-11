void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = ( void * ) V_2 ;
struct V_9 * V_10 ;
T_1 V_11 = F_3 ( V_8 , 0x01c ) ;
T_1 V_12 = F_3 ( V_8 , 0x008 ) & V_11 & ~ ( V_11 >> 16 ) ;
T_2 V_13 = F_3 ( V_8 , 0x050 ) & 0x3fffffff ;
T_1 V_14 = F_3 ( V_8 , 0x040 ) & 0x0000ffff ;
T_1 V_15 = F_3 ( V_8 , 0x040 ) >> 16 ;
T_1 V_16 = ( V_15 & 0x07ff ) << 2 ;
T_1 V_17 = ( V_15 & 0x3800 ) >> 11 ;
T_1 V_18 = F_3 ( V_8 , 0x044 ) ;
int V_19 ;
V_10 = F_4 ( V_6 , V_13 ) ;
V_19 = V_4 -> V_19 ( V_4 , V_10 ) ;
if ( V_12 & 0x00000040 ) {
F_5 ( V_8 , L_1 ) ;
F_6 ( V_20 , V_14 ) ;
F_7 ( L_2 ,
V_19 , V_13 << 12 , F_8 ( V_10 ) , V_17 ,
V_16 , V_18 ) ;
F_9 ( V_8 , 0x004 , 0x00000040 ) ;
V_12 &= ~ 0x00000040 ;
}
if ( V_12 ) {
F_5 ( V_8 , L_3 , V_12 ) ;
F_9 ( V_8 , 0x004 , V_12 ) ;
}
F_10 ( V_10 ) ;
}
static int
F_11 ( struct V_5 * V_6 )
{
F_12 ( & V_6 -> V_21 , 0x0d ) ;
return 0 ;
}
static int
F_13 ( struct V_9 * V_22 , struct V_9 * V_6 ,
struct V_23 * V_24 , void * V_18 , T_1 V_25 ,
struct V_9 * * V_26 )
{
bool V_27 = ( F_14 ( V_22 ) -> V_28 != 0xaf ) ;
struct V_29 * V_30 ;
int V_31 ;
V_31 = F_15 ( V_22 , V_6 , V_24 , 0x104000 , V_27 ,
L_4 , L_5 , & V_30 ) ;
* V_26 = F_16 ( V_30 ) ;
if ( V_31 )
return V_31 ;
F_17 ( V_30 ) -> V_32 = 0x00802000 ;
F_17 ( V_30 ) -> V_33 = F_1 ;
F_2 ( V_30 ) -> V_34 = & V_35 ;
F_2 ( V_30 ) -> V_36 = V_37 ;
F_2 ( V_30 ) -> V_38 = F_11 ;
F_18 ( V_30 ) -> V_39 . V_18 = V_40 ;
F_18 ( V_30 ) -> V_39 . V_25 = sizeof( V_40 ) ;
F_18 ( V_30 ) -> V_18 . V_18 = V_41 ;
F_18 ( V_30 ) -> V_18 . V_25 = sizeof( V_41 ) ;
return 0 ;
}
