static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_2 ( & V_4 -> V_7 ) ;
F_3 ( & V_2 -> V_8 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = V_2 -> V_11 ;
V_6 -> V_10 = F_4 ( V_4 -> V_10 ) ;
V_2 -> V_11 ++ ;
V_2 -> V_11 %= V_12 ;
if ( V_6 -> V_13 )
F_5 ( & V_4 -> V_7 , & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_8 ) ;
V_4 -> V_15 . V_16 = V_4 -> V_15 . V_17 ;
V_4 -> V_15 . V_18 = 0 ;
memcpy ( & V_4 -> V_6 , V_6 , sizeof( * V_6 ) ) ;
return V_4 -> V_10 ;
}
T_1 F_7 ( struct V_1 * V_2 )
{
T_1 V_10 = V_2 -> V_19 ;
V_2 -> V_19 ++ ;
V_2 -> V_19 %= V_20 ;
return V_10 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_21 * V_4 ,
struct V_22 * V_6 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
T_1 V_27 )
{
F_2 ( & V_4 -> V_7 ) ;
F_3 ( & V_2 -> V_8 ) ;
V_4 -> V_10 = F_7 ( V_2 ) ;
V_24 -> V_10 = F_4 ( V_4 -> V_10 ) ;
if ( V_24 -> V_13 )
F_5 ( & V_4 -> V_7 , & V_2 -> V_28 ) ;
F_6 ( & V_2 -> V_8 ) ;
V_4 -> V_15 . V_16 = V_4 -> V_15 . V_17 ;
V_4 -> V_15 . V_18 = 0 ;
if ( V_26 ) {
V_4 -> V_15 . V_16 -= sizeof( struct V_29 ) ;
V_26 -> V_10 = F_4 ( V_4 -> V_10 ) ;
V_26 -> V_30 = F_4 ( V_27 ) ;
memcpy ( & V_4 -> V_26 , V_26 , sizeof( * V_26 ) ) ;
V_24 -> V_30 = F_4 ( sizeof( struct V_29 ) ) ;
} else
V_24 -> V_30 = 0 ;
V_24 -> V_30 = F_4 ( V_27 +
F_9 ( V_24 -> V_30 ) ) ;
V_6 -> V_30 = F_4 ( sizeof( struct V_31 ) +
F_9 ( V_24 -> V_30 ) ) ;
memcpy ( & V_4 -> V_6 , V_6 , sizeof( * V_6 ) ) ;
memcpy ( & V_4 -> V_24 , V_24 , sizeof( * V_24 ) ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_21 * V_32 , * V_33 ;
struct V_3 * V_34 , * V_35 ;
F_11 (wcmd, wnext, &iwm->wifi_pending_cmd, pending) {
F_12 ( & V_32 -> V_7 ) ;
F_13 ( V_32 ) ;
}
F_11 (nwcmd, nwnext, &iwm->nonwifi_pending_cmd,
pending) {
F_12 ( & V_34 -> V_7 ) ;
F_13 ( V_34 ) ;
}
}
struct V_21 * F_14 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_21 * V_4 ;
F_15 (cmd, &iwm->wifi_pending_cmd, pending)
if ( V_4 -> V_10 == V_10 ) {
F_12 ( & V_4 -> V_7 ) ;
return V_4 ;
}
return NULL ;
}
struct V_3 * F_16 ( struct V_1 * V_2 ,
T_2 V_10 , T_2 V_36 )
{
struct V_3 * V_4 ;
F_15 (cmd, &iwm->nonwifi_pending_cmd, pending)
if ( ( V_4 -> V_10 == V_10 ) &&
( V_4 -> V_6 . V_37 == V_36 ) &&
( V_4 -> V_9 ) ) {
F_12 ( & V_4 -> V_7 ) ;
return V_4 ;
}
return NULL ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
struct V_5 * V_4 )
{
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
F_18 ( V_39 -> V_4 , V_40 , V_4 -> V_37 ) ;
F_18 ( V_39 -> V_4 , V_41 , V_4 -> V_13 ) ;
F_18 ( V_39 -> V_4 , V_42 , 1 ) ;
F_18 ( V_39 -> V_4 , V_43 ,
V_4 -> V_44 ) ;
F_18 ( V_39 -> V_4 , V_45 , V_46 ) ;
F_18 ( V_39 -> V_4 , V_47 ,
F_9 ( V_4 -> V_10 ) ) ;
V_39 -> V_48 = V_4 -> V_48 ;
V_39 -> V_49 = V_4 -> V_49 ;
V_39 -> V_50 = V_4 -> V_50 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_38 * V_51 ;
struct V_52 * V_15 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
V_15 = & V_4 -> V_15 ;
V_15 -> V_16 -= sizeof( struct V_53 ) ;
V_15 -> V_18 += sizeof( struct V_53 ) ;
V_51 = (struct V_38 * ) ( V_15 -> V_16 ) ;
F_17 ( V_2 , V_51 , V_6 ) ;
F_20 ( V_2 , V_54 ,
L_1
L_2
L_3 , V_6 -> V_37 , V_6 -> V_13 ,
V_6 -> V_44 , V_4 -> V_10 , V_6 -> V_48 ,
V_6 -> V_49 , V_6 -> V_50 ) ;
F_21 ( V_2 , V_51 ) ;
return F_22 ( V_2 , V_15 -> V_16 , V_15 -> V_18 ) ;
}
void F_23 ( struct V_1 * V_2 , T_2 * V_15 , T_2 V_55 )
{
struct V_56 * V_39 = (struct V_56 * ) V_15 ;
F_18 ( V_39 -> V_4 , V_42 , V_55 ) ;
}
void F_24 ( struct V_1 * V_2 ,
struct V_56 * V_39 ,
struct V_22 * V_4 )
{
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
F_18 ( V_39 -> V_4 , V_40 , V_57 ) ;
F_18 ( V_39 -> V_4 , V_42 , V_4 -> V_55 ) ;
F_18 ( V_39 -> V_4 , V_45 , V_46 ) ;
F_18 ( V_39 -> V_58 , V_59 ,
F_9 ( V_4 -> V_30 ) ) ;
F_18 ( V_39 -> V_58 , V_60 , V_4 -> V_61 ) ;
F_18 ( V_39 -> V_58 , V_62 , V_4 -> V_63 ) ;
F_18 ( V_39 -> V_58 , V_64 , V_4 -> V_65 ) ;
}
void F_25 ( struct V_1 * V_2 ,
struct V_31 * V_39 ,
struct V_23 * V_4 )
{
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
F_18 ( V_39 -> V_58 , V_66 ,
F_9 ( V_4 -> V_30 ) ) ;
F_18 ( V_39 -> V_58 , V_67 , V_4 -> V_68 ) ;
F_26 ( V_39 -> V_4 . V_69 , V_70 , V_4 -> V_13 ) ;
V_39 -> V_4 . V_4 = V_4 -> V_71 ;
V_39 -> V_4 . V_10 = V_4 -> V_10 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_21 * V_4 )
{
struct V_72 * V_73 ;
struct V_74 * V_15 ;
struct V_22 * V_6 = & V_4 -> V_6 ;
struct V_23 * V_24 = & V_4 -> V_24 ;
int V_75 ;
V_15 = & V_4 -> V_15 ;
V_15 -> V_16 -= sizeof( struct V_72 ) ;
V_15 -> V_18 += sizeof( struct V_72 ) ;
V_73 = (struct V_72 * ) ( V_15 -> V_16 ) ;
F_24 ( V_2 , & V_73 -> V_76 , V_6 ) ;
F_25 ( V_2 , & V_73 -> V_77 , V_24 ) ;
F_20 ( V_2 , V_54 ,
L_4
L_5
L_6 ,
V_57 , V_24 -> V_71 ,
V_6 -> V_55 , V_6 -> V_30 , V_6 -> V_61 ,
V_6 -> V_63 , V_6 -> V_65 , V_4 -> V_10 ) ;
if ( V_24 -> V_71 == V_78 )
F_20 ( V_2 , V_54 , L_7 ,
V_4 -> V_26 . V_71 ) ;
V_75 = F_28 ( V_2 , V_6 -> V_61 , V_15 -> V_18 ) ;
if ( V_75 && ( V_24 -> V_71 != V_79 ) ) {
F_29 ( V_2 , V_54 , L_8 ,
V_24 -> V_71 ) ;
return V_75 ;
}
F_30 ( V_2 , V_73 ) ;
return F_22 ( V_2 , V_15 -> V_16 , V_15 -> V_18 ) ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const void * V_17 )
{
struct V_3 * V_4 ;
int V_75 , V_10 ;
V_4 = F_32 ( sizeof( struct V_3 ) , V_80 ) ;
if ( ! V_4 ) {
F_33 ( V_2 , L_9 ) ;
return - V_81 ;
}
V_10 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_4 -> V_6 . V_37 == V_82 ||
V_4 -> V_6 . V_37 == V_83 ) {
V_4 -> V_15 . V_18 = F_34 ( V_4 -> V_6 . V_49 ) ;
memcpy ( & V_4 -> V_15 . V_17 , V_17 , V_4 -> V_15 . V_18 ) ;
}
V_75 = F_19 ( V_2 , V_4 ) ;
if ( ! V_6 -> V_13 )
F_13 ( V_4 ) ;
if ( V_75 < 0 )
return V_75 ;
return V_10 ;
}
static void F_35 ( struct V_1 * V_2 , struct V_29 * V_39 ,
struct V_25 * V_4 )
{
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_71 = V_4 -> V_71 ;
V_39 -> V_69 = 0 ;
V_39 -> V_10 = V_4 -> V_10 ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_22 * V_6 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
const void * V_17 , T_1 V_27 )
{
struct V_21 * V_4 ;
struct V_29 * V_39 ;
int V_84 = 0 ;
int V_75 ;
V_4 = F_32 ( sizeof( struct V_21 ) , V_80 ) ;
if ( ! V_4 ) {
F_33 ( V_2 , L_10 ) ;
return - V_81 ;
}
F_8 ( V_2 , V_4 , V_6 , V_24 , V_26 , V_27 ) ;
if ( V_26 ) {
V_39 = (struct V_29 * ) ( V_4 -> V_15 . V_16 ) ;
F_35 ( V_2 , V_39 , & V_4 -> V_26 ) ;
V_84 = sizeof( struct V_29 ) ;
}
memcpy ( V_4 -> V_15 . V_17 , V_17 , V_27 ) ;
V_4 -> V_15 . V_18 = F_9 ( V_24 -> V_30 ) ;
V_75 = F_27 ( V_2 , V_4 ) ;
if ( ! V_24 -> V_13 )
F_13 ( V_4 ) ;
return V_75 ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_22 * V_6 ,
struct V_23 * V_24 ,
const void * V_17 , T_1 V_27 )
{
return F_36 ( V_2 , V_6 , V_24 , NULL ,
V_17 , V_27 ) ;
}
