int
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , 0x100474 ) ;
if ( V_3 & 0x00000004 )
V_2 -> V_4 . type = V_5 ;
if ( V_3 & 0x00000002 )
V_2 -> V_4 . type = V_6 ;
if ( V_3 & 0x00000001 )
V_2 -> V_4 . type = V_7 ;
V_2 -> V_4 . V_8 = F_2 ( V_2 , 0x10020c ) & 0xff000000 ;
return 0 ;
}
static void
F_3 ( struct V_1 * V_2 , int V_9 , T_1 V_10 , T_1 V_8 , T_1 V_11 ,
T_1 V_12 , struct V_13 * V_14 )
{
V_14 -> V_10 = 0x00000001 ;
V_14 -> V_10 |= V_10 ;
V_14 -> V_15 = F_4 ( 1u , V_10 + V_8 ) - 1 ;
V_14 -> V_11 = V_11 ;
}
void
F_5 ( struct V_1 * V_2 , int V_9 , struct V_13 * V_14 )
{
F_6 ( V_2 , 0x100604 + ( V_9 * 0x10 ) , V_14 -> V_15 ) ;
F_6 ( V_2 , 0x100608 + ( V_9 * 0x10 ) , V_14 -> V_11 ) ;
F_6 ( V_2 , 0x100600 + ( V_9 * 0x10 ) , V_14 -> V_10 ) ;
F_2 ( V_2 , 0x100600 + ( V_9 * 0x10 ) ) ;
}
int
F_7 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = ( void * ) V_17 ;
int V_20 ;
V_20 = F_8 ( & V_19 -> V_21 ) ;
if ( V_20 )
return V_20 ;
F_6 ( V_19 , 0x100850 , 0x80000000 ) ;
F_6 ( V_19 , 0x100800 , 0x00000001 ) ;
return 0 ;
}
static int
F_9 ( struct V_16 * V_22 , struct V_16 * V_23 ,
struct V_24 * V_25 , void * V_26 , T_1 V_8 ,
struct V_16 * * V_27 )
{
struct V_18 * V_19 ;
int V_20 ;
V_20 = F_10 ( V_22 , V_23 , V_25 , & V_19 ) ;
* V_27 = F_11 ( V_19 ) ;
if ( V_20 )
return V_20 ;
V_19 -> V_21 . V_28 = V_29 ;
V_19 -> V_21 . V_4 . V_30 = F_1 ;
V_19 -> V_21 . V_14 . V_31 = 12 ;
V_19 -> V_21 . V_14 . V_30 = F_3 ;
V_19 -> V_21 . V_14 . V_32 = V_33 ;
V_19 -> V_21 . V_14 . V_34 = F_5 ;
return F_12 ( & V_19 -> V_21 ) ;
}
