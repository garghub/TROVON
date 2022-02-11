void
F_1 ( T_1 * V_1 , T_2 * V_2 )
{
V_3 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 1 ;
V_2 -> type = V_6 ;
F_2 ( V_1 , & V_2 -> V_1 ) ;
F_3 ( & V_2 -> V_7 , V_1 ) ;
EXIT ;
}
void
F_4 ( T_3 * V_8 , T_4 V_9 )
{
T_5 * V_10 = & V_8 -> V_11 ;
T_2 * V_2 = & V_8 -> V_12 ;
F_5 ( ! V_8 -> V_13 ) ;
V_2 -> type = V_9 ;
if ( V_9 == V_14 ) {
V_2 -> V_15 . V_16 = F_6 ( V_10 -> V_17 ) ;
V_2 -> V_15 . V_18 = F_7 ( V_10 -> V_19 ) ;
V_2 -> V_20 . V_16 = V_21 ;
V_2 -> V_20 . V_18 = V_22 . V_23 ;
V_2 -> V_24 = V_21 ;
} else {
V_2 -> V_15 . V_18 = V_10 -> V_19 ;
V_2 -> V_15 . V_16 = V_10 -> V_17 ;
V_2 -> V_20 . V_18 = V_10 -> V_25 ;
V_2 -> V_20 . V_16 = V_10 -> V_26 ;
V_2 -> V_27 = V_10 -> V_28 ;
V_2 -> V_24 = V_8 -> V_29 ;
V_2 -> V_30 = V_8 -> V_31 ;
V_2 -> V_32 = V_8 -> V_33 ;
}
switch ( V_9 ) {
default:
F_8 () ;
case V_34 :
V_2 -> V_35 = V_10 -> V_8 . V_36 . V_37 ;
V_2 -> V_38 = V_10 -> V_8 . V_36 . V_38 ;
V_2 -> V_39 = V_10 -> V_8 . V_36 . V_39 ;
return;
case V_40 :
V_2 -> V_35 = V_10 -> V_8 . V_41 . V_37 ;
V_2 -> V_38 = V_10 -> V_8 . V_41 . V_38 ;
V_2 -> V_39 = 0 ;
return;
case V_42 :
V_2 -> V_38 = V_10 -> V_8 . V_43 . V_38 ;
V_2 -> V_30 = V_10 -> V_8 . V_43 . V_30 ;
return;
case V_44 :
return;
case V_14 :
if ( V_8 -> V_45 == V_46 ) {
V_2 -> V_35 = F_7 ( V_10 -> V_8 . V_36 . V_37 ) ;
V_2 -> V_38 = F_6 ( V_10 -> V_8 . V_36 . V_38 ) ;
V_2 -> V_32 = F_7 ( V_10 -> V_8 . V_36 . V_32 ) ;
V_2 -> V_30 =
V_2 -> V_27 = F_7 ( V_10 -> V_28 ) ;
V_2 -> V_39 = F_6 ( V_10 -> V_8 . V_36 . V_39 ) ;
} else {
F_5 ( V_8 -> V_45 == V_47 ) ;
V_2 -> V_35 = F_7 ( V_10 -> V_8 . V_41 . V_37 ) ;
V_2 -> V_38 = F_6 ( V_10 -> V_8 . V_41 . V_38 ) ;
V_2 -> V_30 =
V_2 -> V_27 = F_7 ( V_10 -> V_8 . V_41 . V_48 ) ;
V_2 -> V_32 = F_7 ( V_10 -> V_8 . V_41 . V_49 ) ;
V_2 -> V_39 = 0 ;
}
return;
}
}
void
F_9 ( T_3 * V_8 , int V_50 )
{
struct V_51 * V_52 = V_22 . V_53 [ V_50 ] ;
T_6 * V_54 = V_22 . V_55 [ V_50 ] ;
F_5 ( ! V_8 -> V_56 ) ;
if ( V_8 -> V_57 ) {
F_5 ( ! V_8 -> V_58 ) ;
V_8 -> V_59 = V_50 ;
V_8 -> V_56 = 1 ;
if ( V_8 -> V_60 ) {
F_5 ( V_8 -> V_61 ) ;
return;
}
} else {
F_5 ( ! V_8 -> V_57 ) ;
V_8 -> V_62 = V_50 ;
V_8 -> V_60 = 1 ;
}
F_5 ( ! V_8 -> V_61 ) ;
V_8 -> V_61 = 1 ;
F_10 ( & V_8 -> V_63 , & V_52 -> V_64 ) ;
V_54 -> V_65 ++ ;
if ( V_54 -> V_65 > V_54 -> V_66 )
V_54 -> V_66 = V_54 -> V_65 ;
}
static void
F_11 ( T_3 * V_8 , int V_4 )
{
T_6 * V_54 ;
T_2 * V_2 = & V_8 -> V_12 ;
F_5 ( V_8 -> V_56 ) ;
if ( V_4 != 0 )
goto V_67;
V_54 = V_22 . V_55 [ V_8 -> V_59 ] ;
switch ( V_2 -> type ) {
default:
F_5 ( V_8 -> V_13 ) ;
F_5 ( V_8 -> V_60 ) ;
F_5 ( V_2 -> type == 0 ) ;
V_54 -> V_68 += V_8 -> V_69 ;
V_54 -> V_70 ++ ;
goto V_67;
case V_34 :
F_5 ( ! V_8 -> V_60 ) ;
F_5 ( V_8 -> V_45 == V_71 ) ;
V_8 -> V_45 = V_46 ;
break;
case V_14 :
F_5 ( ! V_8 -> V_60 ) ;
if ( V_8 -> V_45 == V_46 )
V_54 -> V_72 += V_8 -> V_69 ;
break;
case V_40 :
F_5 ( V_8 -> V_60 ) ;
F_5 ( V_8 -> V_45 == V_73 ) ;
V_8 -> V_45 = V_47 ;
break;
}
V_54 -> V_74 ++ ;
V_67:
F_12 ( V_8 ) ;
V_8 -> V_56 = 0 ;
}
static void
F_13 ( T_3 * V_8 , int V_4 )
{
T_6 * V_54 ;
T_2 * V_2 = & V_8 -> V_12 ;
F_5 ( ! V_8 -> V_56 ) ;
F_5 ( V_8 -> V_60 ) ;
if ( V_4 != 0 )
goto V_67;
V_54 = V_22 . V_55 [ V_8 -> V_62 ] ;
switch ( V_2 -> type ) {
default:
F_5 ( V_2 -> type == 0 ) ;
F_5 ( V_8 -> V_13 ) ;
goto V_67;
case V_42 :
F_5 ( V_8 -> V_45 == V_71 ) ;
break;
case V_40 :
F_5 ( V_8 -> V_45 == V_73 ||
V_8 -> V_45 == V_47 ) ;
V_54 -> V_72 += V_8 -> V_31 ;
break;
case V_34 :
F_5 ( V_8 -> V_45 == V_46 ) ;
break;
case V_44 :
F_5 ( V_8 -> V_45 == V_47 ||
V_8 -> V_45 == V_73 ) ;
break;
}
V_54 -> V_75 ++ ;
if ( V_2 -> type == V_34 || V_2 -> type == V_44 )
V_54 -> V_76 += V_8 -> V_31 ;
V_67:
F_14 ( V_8 ) ;
V_8 -> V_60 = 0 ;
}
void
F_15 ( T_3 * V_8 , int V_50 , int V_4 )
{
int V_77 = V_50 ;
F_5 ( V_8 -> V_56 || V_8 -> V_60 ) ;
F_5 ( V_8 -> V_61 ) ;
if ( V_8 -> V_56 ) {
F_5 ( V_50 == V_8 -> V_59 ) ;
F_11 ( V_8 , V_4 ) ;
}
if ( V_8 -> V_60 ) {
if ( V_50 != V_8 -> V_62 ) {
F_16 ( V_50 ) ;
V_77 = V_8 -> V_62 ;
F_17 ( V_77 ) ;
}
F_13 ( V_8 , V_4 ) ;
}
F_18 ( & V_8 -> V_63 ) ;
V_8 -> V_61 = 0 ;
V_22 . V_55 [ V_77 ] -> V_65 -- ;
if ( V_77 != V_50 ) {
F_16 ( V_77 ) ;
F_17 ( V_50 ) ;
}
}
void
F_19 ( T_3 * V_8 , T_1 * V_1 ,
unsigned int V_32 , unsigned int V_78 )
{
F_5 ( ! V_8 -> V_13 ) ;
V_8 -> V_79 = V_1 ;
if ( V_8 -> V_58 ) {
V_8 -> V_33 = V_32 ;
V_8 -> V_31 = V_78 ;
}
V_1 -> V_80 ++ ;
if ( V_1 -> V_81 != V_82 ) {
F_5 ( V_1 -> V_81 > 0 ) ;
V_1 -> V_81 -- ;
}
F_3 ( & V_8 -> V_12 . V_7 , V_1 ) ;
F_2 ( V_1 , & V_8 -> V_12 . V_1 ) ;
}
void
F_20 ( T_3 * V_8 , int V_4 )
{
T_1 * V_1 = V_8 -> V_79 ;
int V_83 ;
V_1 -> V_80 -- ;
F_5 ( V_1 -> V_80 >= 0 ) ;
V_83 = F_21 ( V_1 ) ;
if ( V_1 -> V_84 != NULL ) {
V_8 -> V_12 . V_4 = V_4 ;
V_8 -> V_12 . V_5 = V_83 ;
F_22 ( V_1 -> V_84 , & V_8 -> V_12 ) ;
}
if ( V_83 )
F_23 ( V_1 ) ;
V_8 -> V_79 = NULL ;
}
static int
F_24 ( T_3 * V_8 , int V_50 )
{
T_7 V_85 ;
int V_86 ;
int V_4 = V_8 -> V_12 . V_4 ;
F_5 ( V_8 -> V_61 ) ;
if ( V_4 == 0 && V_8 -> V_87 ) {
F_15 ( V_8 , V_50 , 0 ) ;
V_8 -> V_87 = 0 ;
F_16 ( V_50 ) ;
F_5 ( V_8 -> V_12 . type == V_34 ) ;
F_5 ( ! V_8 -> V_13 ) ;
V_85 = V_8 -> V_11 . V_8 . V_36 . V_85 ;
F_25 ( V_8 , V_71 , V_8 -> V_12 . V_20 , 0 , 0 ) ;
V_8 -> V_11 . V_8 . V_43 . V_88 = V_85 ;
V_8 -> V_11 . V_8 . V_43 . V_38 = V_8 -> V_12 . V_38 ;
V_8 -> V_11 . V_8 . V_43 . V_30 = F_26 ( V_8 -> V_12 . V_30 ) ;
V_86 = F_27 ( V_8 -> V_12 . V_15 . V_16 , V_8 , V_21 ) ;
F_17 ( V_50 ) ;
return V_86 ;
} else if ( V_4 == 0 &&
( V_8 -> V_13 && ! V_8 -> V_57 ) ) {
F_5 ( ! V_8 -> V_58 ) ;
F_16 ( V_50 ) ;
V_86 = F_27 ( V_21 , V_8 , V_21 ) ;
F_17 ( V_50 ) ;
return V_86 ;
}
F_15 ( V_8 , V_50 , V_4 ) ;
F_28 ( V_8 ) ;
return 0 ;
}
void
F_29 ( T_8 * V_89 , T_3 * V_8 , int V_4 )
{
struct V_51 * V_52 ;
int V_90 ;
int V_50 ;
int V_86 ;
int V_91 ;
F_5 ( ! F_30 () ) ;
if ( V_8 == NULL )
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
V_8 -> V_12 . V_4 = V_4 ;
if ( V_8 -> V_79 != NULL ) {
V_50 = F_31 ( V_8 -> V_79 -> V_92 . V_93 ) ;
F_32 ( V_50 ) ;
F_20 ( V_8 , V_4 ) ;
F_33 ( V_50 ) ;
}
V_94:
V_86 = 0 ;
if ( ! V_8 -> V_56 && ! V_8 -> V_60 ) {
F_5 ( ! V_8 -> V_61 ) ;
F_34 ( V_8 ) ;
return;
}
V_50 = V_8 -> V_56 ? V_8 -> V_59 : V_8 -> V_62 ;
F_17 ( V_50 ) ;
V_52 = V_22 . V_53 [ V_50 ] ;
F_35 ( & V_8 -> V_95 , & V_52 -> V_96 ) ;
V_90 = - 1 ;
for ( V_91 = 0 ; V_91 < V_52 -> V_97 ; V_91 ++ ) {
if ( V_52 -> V_98 [ V_91 ] == V_99 )
break;
if ( V_90 < 0 && V_52 -> V_98 [ V_91 ] == NULL )
V_90 = V_91 ;
}
if ( V_91 < V_52 -> V_97 || V_90 < 0 ) {
F_16 ( V_50 ) ;
return;
}
V_52 -> V_98 [ V_90 ] = V_99 ;
while ( ! F_36 ( & V_52 -> V_96 ) ) {
V_8 = F_37 ( V_52 -> V_96 . V_100 ,
T_3 , V_95 ) ;
F_18 ( & V_8 -> V_95 ) ;
V_86 = F_24 ( V_8 , V_50 ) ;
if ( V_86 != 0 )
break;
}
V_52 -> V_98 [ V_90 ] = NULL ;
F_16 ( V_50 ) ;
if ( V_86 != 0 )
goto V_94;
}
void
F_38 ( struct V_51 * V_52 )
{
int V_101 = 0 ;
if ( V_52 -> V_102 == 0 )
return;
while ( ! F_36 ( & V_52 -> V_64 ) ) {
T_3 * V_8 = F_37 ( V_52 -> V_64 . V_100 ,
T_3 , V_63 ) ;
F_5 ( V_8 -> V_61 ) ;
V_8 -> V_61 = 0 ;
F_18 ( & V_8 -> V_63 ) ;
F_34 ( V_8 ) ;
V_101 ++ ;
}
if ( V_101 > 0 )
F_39 ( L_1 , V_101 ) ;
if ( V_52 -> V_98 != NULL ) {
F_40 ( V_52 -> V_98 ,
V_52 -> V_97 *
sizeof( * V_52 -> V_98 ) ) ;
V_52 -> V_98 = NULL ;
}
#ifdef F_41
F_42 ( & V_52 -> V_103 ) ;
#endif
V_52 -> V_102 = 0 ;
}
int
F_43 ( struct V_51 * V_52 , int V_50 )
{
int V_86 ;
V_52 -> V_102 = 1 ;
F_44 ( & V_52 -> V_64 ) ;
F_44 ( & V_52 -> V_96 ) ;
#ifdef F_41
memset ( & V_52 -> V_103 , 0 , sizeof( V_104 ) ) ;
V_86 = F_45 ( & V_52 -> V_103 ,
V_105 , sizeof( T_3 ) ) ;
if ( V_86 != 0 ) {
F_39 ( L_2 ) ;
F_38 ( V_52 ) ;
return V_86 ;
}
#else
V_86 = 0 ;
#endif
V_52 -> V_97 = F_46 ( F_47 () , V_50 ) ;
F_48 ( V_52 -> V_98 , F_47 () , V_50 ,
V_52 -> V_97 *
sizeof( * V_52 -> V_98 ) ) ;
if ( V_52 -> V_98 == NULL ) {
F_39 ( L_3 ) ;
F_38 ( V_52 ) ;
return - V_106 ;
}
return V_86 ;
}
void
F_49 ( void )
{
struct V_51 * V_52 ;
int V_91 ;
if ( V_22 . V_53 == NULL )
return;
F_50 (container, i, the_lnet.ln_msg_containers)
F_38 ( V_52 ) ;
F_51 ( V_22 . V_53 ) ;
V_22 . V_53 = NULL ;
}
int
F_52 ( void )
{
struct V_51 * V_52 ;
int V_86 ;
int V_91 ;
V_22 . V_53 = F_53 ( F_47 () ,
sizeof( * V_52 ) ) ;
if ( V_22 . V_53 == NULL ) {
F_39 ( L_4 ) ;
return - V_106 ;
}
F_50 (container, i, the_lnet.ln_msg_containers) {
V_86 = F_43 ( V_52 , V_91 ) ;
if ( V_86 != 0 ) {
F_49 () ;
return V_86 ;
}
}
return 0 ;
}
