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
static bool F_26 ( struct V_38 * V_39 )
{
switch ( V_39 -> type ) {
case V_41 :
case V_48 :
break;
default:
return false ;
}
switch ( V_39 -> V_42 -> V_43 ) {
case V_49 :
case V_50 :
break;
default:
return false ;
}
return true ;
}
void F_27 ( struct V_38 * V_39 )
{
const struct V_30 * V_31 = V_39 -> V_31 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_1 * V_3 ;
unsigned int V_55 ;
T_2 V_56 ;
if ( ! F_28 ( F_29 ( V_31 ) , V_57 ) )
return;
V_55 = F_30 ( sizeof( struct V_51 ) ) +
F_31 ( strlen ( V_39 -> V_58 -> V_59 -> V_60 ) ) +
F_31 ( strlen ( V_39 -> V_58 -> V_60 ) ) +
F_32 ( sizeof( V_61 ) ) +
F_31 ( sizeof( T_1 ) ) +
F_31 ( 0 ) +
F_31 ( sizeof( V_62 ) ) +
F_31 ( sizeof( V_62 ) ) +
F_31 ( V_13 ) +
F_31 ( V_63 ) +
F_31 ( V_64 ) +
F_31 ( sizeof( V_62 ) ) +
F_31 ( sizeof( V_65 ) ) +
F_31 ( sizeof( V_62 ) ) +
F_31 ( sizeof( V_65 ) ) +
F_31 ( sizeof( V_62 ) ) +
F_31 ( sizeof( V_62 ) ) +
F_31 ( sizeof( V_62 ) ) ;
if ( F_26 ( V_39 ) )
V_55 += F_31 ( strlen ( V_39 -> V_42 -> V_58 -> V_60 ) ) ;
V_3 = F_33 ( V_55 , V_66 ) ;
if ( ! V_3 )
return;
V_56 = F_34 ( V_67 , V_68 ) ;
V_54 = F_35 ( V_3 , 0 , 0 , V_56 , sizeof( struct V_51 ) , 0 ) ;
if ( ! V_54 )
goto V_69;
V_52 = F_36 ( V_54 ) ;
V_52 -> V_70 = V_39 -> V_71 -> type -> V_72 ;
V_52 -> V_73 = V_74 ;
V_52 -> V_75 = 0 ;
if ( F_5 ( V_3 , V_76 , F_17 ( F_37 ( V_31 ) ) ) )
goto V_69;
if ( F_5 ( V_3 , V_77 , F_17 ( V_39 -> type ) ) )
goto V_69;
if ( F_1 ( V_3 , V_31 -> V_3 ) )
goto V_69;
if ( F_38 ( V_3 , V_78 , V_39 -> V_58 -> V_60 ) )
goto V_69;
if ( F_38 ( V_3 , V_79 , V_39 -> V_58 -> V_59 -> V_60 ) )
goto V_69;
if ( F_23 ( V_3 , V_39 ) )
goto V_69;
switch ( V_39 -> type ) {
case V_80 :
case V_81 :
break;
case V_41 :
case V_48 :
if ( F_39 ( V_3 , V_82 , V_39 -> V_42 ) )
goto V_69;
break;
case V_83 :
if ( F_5 ( V_3 , V_84 ,
F_17 ( V_39 -> V_71 -> V_85 ) ) )
goto V_69;
break;
}
if ( V_31 -> V_3 -> V_86 &&
F_5 ( V_3 , V_87 , F_17 ( V_31 -> V_3 -> V_86 ) ) )
goto V_69;
if ( ! V_39 -> V_88 ) {
if ( F_16 ( V_3 , F_40 ( V_31 ) , F_41 ( V_31 ) ) )
goto V_69;
if ( F_19 ( V_3 , V_31 ) )
goto V_69;
V_39 -> V_88 = true ;
}
F_42 ( V_3 , V_54 ) ;
F_43 ( V_3 , F_29 ( V_31 ) , 0 , V_57 , 0 , V_66 ) ;
return;
V_69:
F_44 ( 1 ) ;
F_45 ( V_3 ) ;
}
void F_46 ( struct V_38 * V_39 , const struct V_30 * V_31 ,
const struct V_89 * V_42 ,
const struct V_90 * V_58 )
{
V_39 -> V_71 = F_47 ( V_58 ) ;
V_39 -> V_91 = true ;
V_39 -> V_88 = false ;
V_39 -> V_31 = V_31 ;
V_39 -> V_42 = V_42 ;
}
