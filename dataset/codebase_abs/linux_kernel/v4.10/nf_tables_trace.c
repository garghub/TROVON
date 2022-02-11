static int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
T_1 V_4 ;
V_4 = ( T_1 ) F_2 ( F_3 ( V_3 ) , F_4 ( V_3 ) ,
V_3 -> V_5 ) ;
return F_5 ( V_2 , V_6 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_2 type ,
const struct V_1 * V_3 ,
int V_7 , unsigned int V_8 )
{
struct V_9 * V_10 ;
if ( V_8 == 0 )
return 0 ;
V_10 = F_7 ( V_2 , type , V_8 ) ;
if ( ! V_10 || F_8 ( V_3 , V_7 , F_9 ( V_10 ) , V_8 ) )
return - 1 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
struct V_11 V_12 ;
int V_7 ;
F_11 ( sizeof( V_12 ) > V_13 ) ;
V_7 = F_12 ( V_3 ) - V_3 -> V_14 ;
if ( V_7 != - V_15 )
return - 1 ;
if ( F_8 ( V_3 , V_7 , & V_12 , V_15 ) )
return - 1 ;
V_12 . V_16 = V_3 -> V_17 ;
V_12 . V_18 = F_13 ( F_14 ( V_3 ) ) ;
V_12 . V_19 = V_3 -> V_20 ;
return F_15 ( V_2 , V_21 , sizeof( V_12 ) , & V_12 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_22 * V_23 ,
const struct V_22 * V_24 )
{
if ( V_23 ) {
if ( F_5 ( V_2 , V_25 ,
F_17 ( V_23 -> V_26 ) ) )
return - 1 ;
if ( F_18 ( V_2 , V_27 ,
F_13 ( V_23 -> type ) ) )
return - 1 ;
}
if ( V_24 ) {
if ( F_5 ( V_2 , V_28 ,
F_17 ( V_24 -> V_26 ) ) )
return - 1 ;
if ( F_18 ( V_2 , V_29 ,
F_13 ( V_24 -> type ) ) )
return - 1 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_30 * V_31 )
{
const struct V_1 * V_3 = V_31 -> V_3 ;
int V_7 = F_20 ( V_3 ) ;
unsigned int V_8 , V_32 ;
V_32 = V_31 -> V_33 ? V_31 -> V_34 . V_35 : V_3 -> V_8 ;
V_8 = F_21 (unsigned int, nh_end - skb_network_offset(skb),
NFT_TRACETYPE_NETWORK_HSIZE) ;
if ( F_6 ( V_2 , V_36 , V_3 , V_7 , V_8 ) )
return - 1 ;
if ( V_31 -> V_33 ) {
V_8 = F_21 (unsigned int, skb->len - pkt->xt.thoff,
NFT_TRACETYPE_TRANSPORT_HSIZE) ;
if ( F_6 ( V_2 , V_37 , V_3 ,
V_31 -> V_34 . V_35 , V_8 ) )
return - 1 ;
}
if ( ! F_22 ( V_3 ) )
return 0 ;
if ( F_14 ( V_3 ) )
return F_10 ( V_2 , V_3 ) ;
V_7 = F_12 ( V_3 ) - V_3 -> V_14 ;
V_8 = F_21 (unsigned int, -off, NFT_TRACETYPE_LL_HSIZE) ;
return F_6 ( V_2 , V_21 ,
V_3 , V_7 , V_8 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_38 * V_39 )
{
if ( ! V_39 -> V_40 )
return 0 ;
if ( V_39 -> type == V_41 &&
V_39 -> V_42 -> V_43 == V_44 )
return 0 ;
return F_24 ( V_2 , V_45 ,
F_25 ( V_39 -> V_40 -> V_46 ) ,
V_47 ) ;
}
void F_26 ( struct V_38 * V_39 )
{
const struct V_30 * V_31 = V_39 -> V_31 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
struct V_1 * V_3 ;
unsigned int V_52 ;
int V_53 = ( V_54 << 8 ) | V_55 ;
if ( ! F_27 ( F_28 ( V_31 ) , V_56 ) )
return;
V_52 = F_29 ( sizeof( struct V_48 ) ) +
F_30 ( V_57 ) +
F_30 ( V_58 ) +
F_31 ( sizeof( V_59 ) ) +
F_30 ( sizeof( T_1 ) ) +
F_30 ( 0 ) +
F_30 ( sizeof( V_60 ) ) +
F_30 ( V_58 ) +
F_30 ( sizeof( V_60 ) ) +
F_30 ( V_13 ) +
F_30 ( V_61 ) +
F_30 ( V_62 ) +
F_30 ( sizeof( V_60 ) ) +
F_30 ( sizeof( V_63 ) ) +
F_30 ( sizeof( V_60 ) ) +
F_30 ( sizeof( V_63 ) ) +
F_30 ( sizeof( V_60 ) ) +
F_30 ( sizeof( V_60 ) ) +
F_30 ( sizeof( V_60 ) ) ;
V_3 = F_32 ( V_52 , V_64 ) ;
if ( ! V_3 )
return;
V_51 = F_33 ( V_3 , 0 , 0 , V_53 , sizeof( struct V_48 ) , 0 ) ;
if ( ! V_51 )
goto V_65;
V_49 = F_34 ( V_51 ) ;
V_49 -> V_66 = V_39 -> V_67 -> type -> V_68 ;
V_49 -> V_69 = V_70 ;
V_49 -> V_71 = 0 ;
if ( F_5 ( V_3 , V_72 , F_17 ( F_35 ( V_31 ) ) ) )
goto V_65;
if ( F_5 ( V_3 , V_73 , F_17 ( V_39 -> type ) ) )
goto V_65;
if ( F_1 ( V_3 , V_31 -> V_3 ) )
goto V_65;
if ( V_39 -> V_74 ) {
if ( F_36 ( V_3 , V_75 ,
V_39 -> V_74 -> V_76 ) )
goto V_65;
if ( F_36 ( V_3 , V_77 ,
V_39 -> V_74 -> V_78 -> V_76 ) )
goto V_65;
}
if ( F_23 ( V_3 , V_39 ) )
goto V_65;
switch ( V_39 -> type ) {
case V_79 :
case V_80 :
break;
case V_41 :
case V_81 :
if ( F_37 ( V_3 , V_82 , V_39 -> V_42 ) )
goto V_65;
break;
case V_83 :
if ( F_5 ( V_3 , V_84 ,
F_17 ( V_39 -> V_67 -> V_85 ) ) )
goto V_65;
break;
}
if ( V_31 -> V_3 -> V_86 &&
F_5 ( V_3 , V_87 , F_17 ( V_31 -> V_3 -> V_86 ) ) )
goto V_65;
if ( ! V_39 -> V_88 ) {
if ( F_16 ( V_3 , F_38 ( V_31 ) , F_39 ( V_31 ) ) )
goto V_65;
if ( F_19 ( V_3 , V_31 ) )
goto V_65;
V_39 -> V_88 = true ;
}
F_40 ( V_3 , V_51 ) ;
F_41 ( V_3 , F_28 ( V_31 ) , 0 , V_56 , 0 , V_64 ) ;
return;
V_65:
F_42 ( 1 ) ;
F_43 ( V_3 ) ;
}
void F_44 ( struct V_38 * V_39 , const struct V_30 * V_31 ,
const struct V_89 * V_42 ,
const struct V_90 * V_74 )
{
V_39 -> V_67 = F_45 ( V_74 ) ;
V_39 -> V_91 = true ;
V_39 -> V_88 = false ;
V_39 -> V_31 = V_31 ;
V_39 -> V_42 = V_42 ;
}
