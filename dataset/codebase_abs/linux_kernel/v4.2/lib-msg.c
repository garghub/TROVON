void
F_1 ( T_1 * V_1 , T_2 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 1 ;
V_2 -> type = V_5 ;
F_2 ( V_1 , & V_2 -> V_1 ) ;
F_3 ( & V_2 -> V_6 , V_1 ) ;
}
void
F_4 ( T_3 * V_7 , T_4 V_8 )
{
T_5 * V_9 = & V_7 -> V_10 ;
T_2 * V_2 = & V_7 -> V_11 ;
F_5 ( ! V_7 -> V_12 ) ;
V_2 -> type = V_8 ;
if ( V_8 == V_13 ) {
V_2 -> V_14 . V_15 = F_6 ( V_9 -> V_16 ) ;
V_2 -> V_14 . V_17 = F_7 ( V_9 -> V_18 ) ;
V_2 -> V_19 . V_15 = V_20 ;
V_2 -> V_19 . V_17 = V_21 . V_22 ;
V_2 -> V_23 = V_20 ;
} else {
V_2 -> V_14 . V_17 = V_9 -> V_18 ;
V_2 -> V_14 . V_15 = V_9 -> V_16 ;
V_2 -> V_19 . V_17 = V_9 -> V_24 ;
V_2 -> V_19 . V_15 = V_9 -> V_25 ;
V_2 -> V_26 = V_9 -> V_27 ;
V_2 -> V_23 = V_7 -> V_28 ;
V_2 -> V_29 = V_7 -> V_30 ;
V_2 -> V_31 = V_7 -> V_32 ;
}
switch ( V_8 ) {
default:
F_8 () ;
case V_33 :
V_2 -> V_34 = V_9 -> V_7 . V_35 . V_36 ;
V_2 -> V_37 = V_9 -> V_7 . V_35 . V_37 ;
V_2 -> V_38 = V_9 -> V_7 . V_35 . V_38 ;
return;
case V_39 :
V_2 -> V_34 = V_9 -> V_7 . V_40 . V_36 ;
V_2 -> V_37 = V_9 -> V_7 . V_40 . V_37 ;
V_2 -> V_38 = 0 ;
return;
case V_41 :
V_2 -> V_37 = V_9 -> V_7 . V_42 . V_37 ;
V_2 -> V_29 = V_9 -> V_7 . V_42 . V_29 ;
return;
case V_43 :
return;
case V_13 :
if ( V_7 -> V_44 == V_45 ) {
V_2 -> V_34 = F_7 ( V_9 -> V_7 . V_35 . V_36 ) ;
V_2 -> V_37 = F_6 ( V_9 -> V_7 . V_35 . V_37 ) ;
V_2 -> V_31 = F_7 ( V_9 -> V_7 . V_35 . V_31 ) ;
V_2 -> V_29 =
V_2 -> V_26 = F_7 ( V_9 -> V_27 ) ;
V_2 -> V_38 = F_6 ( V_9 -> V_7 . V_35 . V_38 ) ;
} else {
F_5 ( V_7 -> V_44 == V_46 ) ;
V_2 -> V_34 = F_7 ( V_9 -> V_7 . V_40 . V_36 ) ;
V_2 -> V_37 = F_6 ( V_9 -> V_7 . V_40 . V_37 ) ;
V_2 -> V_29 =
V_2 -> V_26 = F_7 ( V_9 -> V_7 . V_40 . V_47 ) ;
V_2 -> V_31 = F_7 ( V_9 -> V_7 . V_40 . V_48 ) ;
V_2 -> V_38 = 0 ;
}
return;
}
}
void
F_9 ( T_3 * V_7 , int V_49 )
{
struct V_50 * V_51 = V_21 . V_52 [ V_49 ] ;
T_6 * V_53 = V_21 . V_54 [ V_49 ] ;
F_5 ( ! V_7 -> V_55 ) ;
if ( V_7 -> V_56 ) {
F_5 ( ! V_7 -> V_57 ) ;
V_7 -> V_58 = V_49 ;
V_7 -> V_55 = 1 ;
if ( V_7 -> V_59 ) {
F_5 ( V_7 -> V_60 ) ;
return;
}
} else {
F_5 ( ! V_7 -> V_56 ) ;
V_7 -> V_61 = V_49 ;
V_7 -> V_59 = 1 ;
}
F_5 ( ! V_7 -> V_60 ) ;
V_7 -> V_60 = 1 ;
F_10 ( & V_7 -> V_62 , & V_51 -> V_63 ) ;
V_53 -> V_64 ++ ;
if ( V_53 -> V_64 > V_53 -> V_65 )
V_53 -> V_65 = V_53 -> V_64 ;
}
static void
F_11 ( T_3 * V_7 , int V_3 )
{
T_6 * V_53 ;
T_2 * V_2 = & V_7 -> V_11 ;
F_5 ( V_7 -> V_55 ) ;
if ( V_3 != 0 )
goto V_66;
V_53 = V_21 . V_54 [ V_7 -> V_58 ] ;
switch ( V_2 -> type ) {
default:
F_5 ( V_7 -> V_12 ) ;
F_5 ( V_7 -> V_59 ) ;
F_5 ( V_2 -> type == 0 ) ;
V_53 -> V_67 += V_7 -> V_68 ;
V_53 -> V_69 ++ ;
goto V_66;
case V_33 :
F_5 ( ! V_7 -> V_59 ) ;
F_5 ( V_7 -> V_44 == V_70 ) ;
V_7 -> V_44 = V_45 ;
break;
case V_13 :
F_5 ( ! V_7 -> V_59 ) ;
if ( V_7 -> V_44 == V_45 )
V_53 -> V_71 += V_7 -> V_68 ;
break;
case V_39 :
F_5 ( V_7 -> V_59 ) ;
F_5 ( V_7 -> V_44 == V_72 ) ;
V_7 -> V_44 = V_46 ;
break;
}
V_53 -> V_73 ++ ;
V_66:
F_12 ( V_7 ) ;
V_7 -> V_55 = 0 ;
}
static void
F_13 ( T_3 * V_7 , int V_3 )
{
T_6 * V_53 ;
T_2 * V_2 = & V_7 -> V_11 ;
F_5 ( ! V_7 -> V_55 ) ;
F_5 ( V_7 -> V_59 ) ;
if ( V_3 != 0 )
goto V_66;
V_53 = V_21 . V_54 [ V_7 -> V_61 ] ;
switch ( V_2 -> type ) {
default:
F_5 ( V_2 -> type == 0 ) ;
F_5 ( V_7 -> V_12 ) ;
goto V_66;
case V_41 :
F_5 ( V_7 -> V_44 == V_70 ) ;
break;
case V_39 :
F_5 ( V_7 -> V_44 == V_72 ||
V_7 -> V_44 == V_46 ) ;
V_53 -> V_71 += V_7 -> V_30 ;
break;
case V_33 :
F_5 ( V_7 -> V_44 == V_45 ) ;
break;
case V_43 :
F_5 ( V_7 -> V_44 == V_46 ||
V_7 -> V_44 == V_72 ) ;
break;
}
V_53 -> V_74 ++ ;
if ( V_2 -> type == V_33 || V_2 -> type == V_43 )
V_53 -> V_75 += V_7 -> V_30 ;
V_66:
F_14 ( V_7 ) ;
V_7 -> V_59 = 0 ;
}
void
F_15 ( T_3 * V_7 , int V_49 , int V_3 )
{
int V_76 = V_49 ;
F_5 ( V_7 -> V_55 || V_7 -> V_59 ) ;
F_5 ( V_7 -> V_60 ) ;
if ( V_7 -> V_55 ) {
F_5 ( V_49 == V_7 -> V_58 ) ;
F_11 ( V_7 , V_3 ) ;
}
if ( V_7 -> V_59 ) {
if ( V_49 != V_7 -> V_61 ) {
F_16 ( V_49 ) ;
V_76 = V_7 -> V_61 ;
F_17 ( V_76 ) ;
}
F_13 ( V_7 , V_3 ) ;
}
F_18 ( & V_7 -> V_62 ) ;
V_7 -> V_60 = 0 ;
V_21 . V_54 [ V_76 ] -> V_64 -- ;
if ( V_76 != V_49 ) {
F_16 ( V_76 ) ;
F_17 ( V_49 ) ;
}
}
void
F_19 ( T_3 * V_7 , T_1 * V_1 ,
unsigned int V_31 , unsigned int V_77 )
{
F_5 ( ! V_7 -> V_12 ) ;
V_7 -> V_78 = V_1 ;
if ( V_7 -> V_57 ) {
V_7 -> V_32 = V_31 ;
V_7 -> V_30 = V_77 ;
}
V_1 -> V_79 ++ ;
if ( V_1 -> V_80 != V_81 ) {
F_5 ( V_1 -> V_80 > 0 ) ;
V_1 -> V_80 -- ;
}
F_3 ( & V_7 -> V_11 . V_6 , V_1 ) ;
F_2 ( V_1 , & V_7 -> V_11 . V_1 ) ;
}
void
F_20 ( T_3 * V_7 , int V_3 )
{
T_1 * V_1 = V_7 -> V_78 ;
int V_82 ;
V_1 -> V_79 -- ;
F_5 ( V_1 -> V_79 >= 0 ) ;
V_82 = F_21 ( V_1 ) ;
if ( V_1 -> V_83 != NULL ) {
V_7 -> V_11 . V_3 = V_3 ;
V_7 -> V_11 . V_4 = V_82 ;
F_22 ( V_1 -> V_83 , & V_7 -> V_11 ) ;
}
if ( V_82 )
F_23 ( V_1 ) ;
V_7 -> V_78 = NULL ;
}
static int
F_24 ( T_3 * V_7 , int V_49 )
{
T_7 V_84 ;
int V_85 ;
int V_3 = V_7 -> V_11 . V_3 ;
F_5 ( V_7 -> V_60 ) ;
if ( V_3 == 0 && V_7 -> V_86 ) {
F_15 ( V_7 , V_49 , 0 ) ;
V_7 -> V_86 = 0 ;
F_16 ( V_49 ) ;
F_5 ( V_7 -> V_11 . type == V_33 ) ;
F_5 ( ! V_7 -> V_12 ) ;
V_84 = V_7 -> V_10 . V_7 . V_35 . V_84 ;
F_25 ( V_7 , V_70 , V_7 -> V_11 . V_19 , 0 , 0 ) ;
V_7 -> V_10 . V_7 . V_42 . V_87 = V_84 ;
V_7 -> V_10 . V_7 . V_42 . V_37 = V_7 -> V_11 . V_37 ;
V_7 -> V_10 . V_7 . V_42 . V_29 = F_26 ( V_7 -> V_11 . V_29 ) ;
V_85 = F_27 ( V_7 -> V_11 . V_14 . V_15 , V_7 , V_20 ) ;
F_17 ( V_49 ) ;
return V_85 ;
} else if ( V_3 == 0 &&
( V_7 -> V_12 && ! V_7 -> V_56 ) ) {
F_5 ( ! V_7 -> V_57 ) ;
F_16 ( V_49 ) ;
V_85 = F_27 ( V_20 , V_7 , V_20 ) ;
F_17 ( V_49 ) ;
return V_85 ;
}
F_15 ( V_7 , V_49 , V_3 ) ;
F_28 ( V_7 ) ;
return 0 ;
}
void
F_29 ( T_8 * V_88 , T_3 * V_7 , int V_3 )
{
struct V_50 * V_51 ;
int V_89 ;
int V_49 ;
int V_85 ;
int V_90 ;
F_5 ( ! F_30 () ) ;
if ( V_7 == NULL )
return;
#if 0
CDEBUG(D_WARNING, "%s msg->%s Flags:%s%s%s%s%s%s%s%s%s%s%s txp %s rxp %s\n",
lnet_msgtyp2str(msg->msg_type), libcfs_id2str(msg->msg_target),
msg->msg_target_is_router ? "t" : "",
msg->msg_routing ? "X" : "",
msg->msg_ack ? "A" : "",
msg->msg_sending ? "S" : "",
msg->msg_receiving ? "R" : "",
msg->msg_delayed ? "d" : "",
msg->msg_txcredit ? "C" : "",
msg->msg_peertxcredit ? "c" : "",
msg->msg_rtrcredit ? "F" : "",
msg->msg_peerrtrcredit ? "f" : "",
msg->msg_onactivelist ? "!" : "",
msg->msg_txpeer == NULL ? "<none>" : libcfs_nid2str(msg->msg_txpeer->lp_nid),
msg->msg_rxpeer == NULL ? "<none>" : libcfs_nid2str(msg->msg_rxpeer->lp_nid));
#endif
V_7 -> V_11 . V_3 = V_3 ;
if ( V_7 -> V_78 != NULL ) {
V_49 = F_31 ( V_7 -> V_78 -> V_91 . V_92 ) ;
F_32 ( V_49 ) ;
F_20 ( V_7 , V_3 ) ;
F_33 ( V_49 ) ;
}
V_93:
V_85 = 0 ;
if ( ! V_7 -> V_55 && ! V_7 -> V_59 ) {
F_5 ( ! V_7 -> V_60 ) ;
F_28 ( V_7 ) ;
return;
}
V_49 = V_7 -> V_55 ? V_7 -> V_58 : V_7 -> V_61 ;
F_17 ( V_49 ) ;
V_51 = V_21 . V_52 [ V_49 ] ;
F_34 ( & V_7 -> V_94 , & V_51 -> V_95 ) ;
V_89 = - 1 ;
for ( V_90 = 0 ; V_90 < V_51 -> V_96 ; V_90 ++ ) {
if ( V_51 -> V_97 [ V_90 ] == V_98 )
break;
if ( V_89 < 0 && V_51 -> V_97 [ V_90 ] == NULL )
V_89 = V_90 ;
}
if ( V_90 < V_51 -> V_96 || V_89 < 0 ) {
F_16 ( V_49 ) ;
return;
}
V_51 -> V_97 [ V_89 ] = V_98 ;
while ( ! F_35 ( & V_51 -> V_95 ) ) {
V_7 = F_36 ( V_51 -> V_95 . V_99 ,
T_3 , V_94 ) ;
F_18 ( & V_7 -> V_94 ) ;
V_85 = F_24 ( V_7 , V_49 ) ;
if ( V_85 != 0 )
break;
}
V_51 -> V_97 [ V_89 ] = NULL ;
F_16 ( V_49 ) ;
if ( V_85 != 0 )
goto V_93;
}
void
F_37 ( struct V_50 * V_51 )
{
int V_100 = 0 ;
if ( V_51 -> V_101 == 0 )
return;
while ( ! F_35 ( & V_51 -> V_63 ) ) {
T_3 * V_7 = F_36 ( V_51 -> V_63 . V_99 ,
T_3 , V_62 ) ;
F_5 ( V_7 -> V_60 ) ;
V_7 -> V_60 = 0 ;
F_18 ( & V_7 -> V_62 ) ;
F_28 ( V_7 ) ;
V_100 ++ ;
}
if ( V_100 > 0 )
F_38 ( L_1 , V_100 ) ;
if ( V_51 -> V_97 != NULL ) {
F_39 ( V_51 -> V_97 ,
V_51 -> V_96 *
sizeof( * V_51 -> V_97 ) ) ;
V_51 -> V_97 = NULL ;
}
#ifdef F_40
F_41 ( & V_51 -> V_102 ) ;
#endif
V_51 -> V_101 = 0 ;
}
int
F_42 ( struct V_50 * V_51 , int V_49 )
{
int V_85 ;
V_51 -> V_101 = 1 ;
F_43 ( & V_51 -> V_63 ) ;
F_43 ( & V_51 -> V_95 ) ;
#ifdef F_40
memset ( & V_51 -> V_102 , 0 , sizeof( V_103 ) ) ;
V_85 = F_44 ( & V_51 -> V_102 ,
V_104 , sizeof( T_3 ) ) ;
if ( V_85 != 0 ) {
F_38 ( L_2 ) ;
F_37 ( V_51 ) ;
return V_85 ;
}
#else
V_85 = 0 ;
#endif
V_51 -> V_96 = F_45 ( F_46 () , V_49 ) ;
F_47 ( V_51 -> V_97 , F_46 () , V_49 ,
V_51 -> V_96 *
sizeof( * V_51 -> V_97 ) ) ;
if ( V_51 -> V_97 == NULL ) {
F_38 ( L_3 ) ;
F_37 ( V_51 ) ;
return - V_105 ;
}
return V_85 ;
}
void
F_48 ( void )
{
struct V_50 * V_51 ;
int V_90 ;
if ( V_21 . V_52 == NULL )
return;
F_49 (container, i, the_lnet.ln_msg_containers)
F_37 ( V_51 ) ;
F_50 ( V_21 . V_52 ) ;
V_21 . V_52 = NULL ;
}
int
F_51 ( void )
{
struct V_50 * V_51 ;
int V_85 ;
int V_90 ;
V_21 . V_52 = F_52 ( F_46 () ,
sizeof( * V_51 ) ) ;
if ( V_21 . V_52 == NULL ) {
F_38 ( L_4 ) ;
return - V_105 ;
}
F_49 (container, i, the_lnet.ln_msg_containers) {
V_85 = F_42 ( V_51 , V_90 ) ;
if ( V_85 != 0 ) {
F_48 () ;
return V_85 ;
}
}
return 0 ;
}
