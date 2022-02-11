static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_10 . V_11 ;
bool V_12 = false ;
V_4 = F_2 ( sizeof( * V_4 ) , V_13 ) ;
if ( ! V_4 )
return NULL ;
if ( V_12 ) {
V_4 -> V_14 = ( V_9 -> V_15 << 8 ) | V_9 -> V_16 ;
V_4 -> V_17 = ( V_9 -> V_18 << 8 ) | V_9 -> V_19 ;
V_4 -> V_20 = V_4 -> V_14 + \
( ( V_9 -> V_21 << 8 ) | \
V_9 -> V_22 ) ;
V_4 -> V_23 = V_4 -> V_20 + \
( ( V_9 -> V_24 << 8 ) | \
V_9 -> V_25 ) ;
V_4 -> V_26 = V_4 -> V_14 + ( ( V_9 -> V_27 << 8 ) | \
V_9 -> V_28 ) ;
V_4 -> V_29 = \
V_4 -> V_17 + ( ( V_9 -> V_30 << 8 ) | \
V_9 -> V_31 ) ;
V_4 -> V_32 = \
V_4 -> V_29 + ( ( V_9 -> V_33 << 8 ) | \
V_9 -> V_34 ) ;
V_4 -> V_35 = V_4 -> V_17 + \
( ( V_9 -> V_36 << 8 ) | V_9 -> V_37 ) ;
V_4 -> clock = V_9 -> V_38 * 10 ;
F_3 ( V_3 -> V_3 , L_1 , V_4 -> V_14 ) ;
F_3 ( V_3 -> V_3 , L_2 , V_4 -> V_17 ) ;
F_3 ( V_3 -> V_3 , L_3 , V_4 -> V_20 ) ;
F_3 ( V_3 -> V_3 , L_4 , V_4 -> V_23 ) ;
F_3 ( V_3 -> V_3 , L_5 , V_4 -> V_26 ) ;
F_3 ( V_3 -> V_3 , L_6 , V_4 -> V_29 ) ;
F_3 ( V_3 -> V_3 , L_7 , V_4 -> V_32 ) ;
F_3 ( V_3 -> V_3 , L_8 , V_4 -> V_35 ) ;
F_3 ( V_3 -> V_3 , L_9 , V_4 -> clock ) ;
} else {
V_4 -> V_14 = 480 ;
V_4 -> V_17 = 854 ;
V_4 -> V_20 = 487 ;
V_4 -> V_23 = 490 ;
V_4 -> V_26 = 499 ;
V_4 -> V_29 = 861 ;
V_4 -> V_32 = 865 ;
V_4 -> V_35 = 873 ;
V_4 -> clock = 33264 ;
}
F_4 ( V_4 ) ;
F_5 ( V_4 , 0 ) ;
V_4 -> type |= V_39 ;
return V_4 ;
}
static int F_6 ( struct V_2 * V_3 ,
int V_40 ,
struct V_41 * V_42 )
{
if ( ! V_3 || ! V_42 )
return - V_43 ;
V_42 -> V_44 = V_45 ;
V_42 -> V_46 = V_47 ;
return 0 ;
}
static void F_7 ( struct V_48 * V_49 ,
int V_40 )
{
struct V_50 * V_51
= F_8 ( V_49 ) ;
F_9 ( L_10 ) ;
if ( ! V_51 ) {
F_10 ( L_11 ) ;
return;
}
if ( V_49 -> V_52 )
return;
F_11 ( 3 ) ;
F_12 ( V_51 , ( V_53 * ) V_54 ,
sizeof( V_54 ) , false ) ;
F_12 ( V_51 , ( V_53 * ) V_55 ,
sizeof( V_55 ) , false ) ;
F_12 ( V_51 , ( V_53 * ) V_56 ,
sizeof( V_56 ) , false ) ;
F_12 ( V_51 , ( V_53 * ) V_57 ,
sizeof( V_57 ) , false ) ;
F_12 ( V_51 , ( V_53 * ) V_58 ,
sizeof( V_58 ) , false ) ;
F_12 ( V_51 , ( V_53 * ) V_59 ,
sizeof( V_59 ) , false ) ;
F_12 ( V_51 , ( V_53 * ) V_60 ,
sizeof( V_60 ) , false ) ;
F_13 ( V_51 , ( V_53 * ) V_61 ,
sizeof( V_61 ) , false ) ;
F_13 ( V_51 , ( V_53 * ) V_62 ,
sizeof( V_62 ) , false ) ;
F_12 ( V_51 , ( V_53 * ) V_63 ,
sizeof( V_63 ) , false ) ;
F_12 ( V_51 , ( V_53 * ) V_64 ,
sizeof( V_64 ) , false ) ;
F_12 ( V_51 , ( V_53 * ) V_65 ,
sizeof( V_65 ) , false ) ;
V_49 -> V_52 = 1 ;
}
