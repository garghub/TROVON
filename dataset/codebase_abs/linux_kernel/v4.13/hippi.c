static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_5 , const void * V_6 , unsigned int V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 , V_10 ) ;
struct V_11 * V_12 = (struct V_11 * ) V_2 -> V_13 ;
if ( ! V_7 ) {
V_7 = V_2 -> V_7 - V_10 ;
F_3 ( L_1 ) ;
}
V_9 -> V_14 . V_15 = F_4 ( 0x04800018 ) ;
V_9 -> V_14 . V_16 = F_4 ( V_7 + 8 ) ;
V_9 -> V_17 . V_18 = 0 ;
V_9 -> V_17 . V_19 = 0 ;
V_9 -> V_17 . V_20 = 0 ;
V_9 -> V_17 . V_21 = 2 ;
V_9 -> V_17 . V_22 = 2 ;
memcpy ( V_9 -> V_17 . V_23 , V_4 -> V_24 + 3 , 3 ) ;
memset ( & V_9 -> V_17 . V_25 , 0 , 16 ) ;
V_9 -> V_26 . V_27 = V_28 ;
V_9 -> V_26 . V_29 = V_28 ;
V_9 -> V_26 . V_30 = V_31 ;
V_9 -> V_26 . V_32 [ 0 ] = 0x00 ;
V_9 -> V_26 . V_32 [ 1 ] = 0x00 ;
V_9 -> V_26 . V_32 [ 2 ] = 0x00 ;
V_9 -> V_26 . V_33 = F_5 ( type ) ;
if ( V_5 )
{
memcpy ( V_9 -> V_17 . V_34 , V_5 + 3 , 3 ) ;
memcpy ( & V_12 -> V_35 , V_5 + 2 , 4 ) ;
return V_10 ;
}
V_12 -> V_35 = 0 ;
return - ( ( int ) V_10 ) ;
}
T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 ;
V_2 -> V_4 = V_4 ;
F_7 ( V_2 ) ;
V_9 = (struct V_8 * ) F_8 ( V_2 ) ;
F_9 ( V_2 , V_10 ) ;
return V_9 -> V_26 . V_33 ;
}
int F_10 ( struct V_3 * V_4 , void * V_36 )
{
struct V_37 * V_38 = V_36 ;
if ( F_11 ( V_4 ) )
return - V_39 ;
memcpy ( V_4 -> V_24 , V_38 -> V_40 , V_4 -> V_41 ) ;
return 0 ;
}
int F_12 ( struct V_3 * V_4 , struct V_42 * V_36 )
{
F_13 ( V_36 , V_43 , 0 ) ;
if ( V_36 -> V_44 -> V_45 != V_46 )
F_13 ( V_36 , V_47 , 0 ) ;
return 0 ;
}
static void F_14 ( struct V_3 * V_4 )
{
V_4 -> V_48 = & V_49 ;
V_4 -> type = V_50 ;
V_4 -> V_51 = V_10 ;
V_4 -> V_52 = 65280 ;
V_4 -> V_53 = 68 ;
V_4 -> V_54 = 65280 ;
V_4 -> V_41 = V_55 ;
V_4 -> V_56 = 25 ;
memset ( V_4 -> V_57 , 0xFF , V_55 ) ;
V_4 -> V_58 = 0 ;
}
struct V_3 * F_15 ( int V_59 )
{
return F_16 ( V_59 , L_2 , V_60 ,
F_14 ) ;
}
