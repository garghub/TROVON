void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , T_1 V_5 ,
struct V_6 * V_7 )
{
T_1 V_8 = F_2 ( V_4 , 0x80 ) ;
T_1 V_9 = F_3 ( V_8 / V_2 -> V_10 -> V_11 , 0x100 ) ;
if ( ( V_5 & 2 ) &&
! F_4 ( & V_2 -> V_9 , 1 , V_9 , V_9 , 1 , & V_7 -> V_12 ) ) {
V_7 -> V_13 = 0x28000000 ;
V_7 -> V_13 |= ( ( V_7 -> V_12 -> V_14 ) >> 8 ) ;
V_7 -> V_13 |= ( ( V_7 -> V_12 -> V_14 + V_9 - 1 ) >> 8 ) << 13 ;
#ifdef F_5
V_7 -> V_13 |= 0x40000000 ;
#endif
}
}
static int
F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = ( void * ) V_16 ;
int V_19 ;
V_19 = F_7 ( & V_18 -> V_20 ) ;
if ( V_19 )
return V_19 ;
F_8 ( V_18 , 0x10033c , 0x00008000 , 0x00000000 ) ;
return 0 ;
}
static int
F_9 ( struct V_15 * V_21 , struct V_15 * V_22 ,
struct V_23 * V_24 , void * V_25 , T_1 V_4 ,
struct V_15 * * V_26 )
{
struct V_17 * V_18 ;
int V_19 ;
V_19 = F_10 ( V_21 , V_22 , V_24 , & V_27 , & V_18 ) ;
* V_26 = F_11 ( V_18 ) ;
if ( V_19 )
return V_19 ;
V_18 -> V_20 . V_28 = V_29 ;
V_18 -> V_20 . V_7 . V_30 = 8 ;
V_18 -> V_20 . V_7 . V_31 = V_32 ;
V_18 -> V_20 . V_7 . V_33 = F_1 ;
V_18 -> V_20 . V_7 . V_34 = V_35 ;
V_18 -> V_20 . V_7 . V_36 = V_37 ;
return 0 ;
}
