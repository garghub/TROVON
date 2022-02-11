static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_2 -> V_5 [ V_3 ] . V_6 = V_7 ;
V_2 -> V_5 [ V_3 ] . V_8 = V_9 ;
}
memset ( V_2 -> V_10 , V_11 , sizeof( V_2 -> V_10 ) ) ;
}
static void F_2 ( struct V_12 * V_13 , T_1 V_8 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( V_13 -> V_14 -> V_5 [ V_3 ] . V_8 == V_8 ) {
V_13 -> V_14 -> V_5 [ V_3 ] . V_6 = V_7 ;
V_13 -> V_14 -> V_5 [ V_3 ] . V_8 = V_9 ;
}
}
}
static int F_3 ( struct V_12 * V_13 , T_1 V_15 ,
const T_1 V_16 , const T_1 * V_17 ,
T_2 V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 , V_3 , V_24 ;
T_1 V_25 = V_15 ;
V_20 = V_13 -> V_14 -> V_20 ;
if ( ! V_20 )
return - V_26 ;
V_22 = F_4 ( V_13 , 2 + V_20 -> V_27 +
V_28 , V_29 ) ;
if ( ! V_22 )
return - V_30 ;
F_5 ( V_22 , 2 + V_28 ) ;
* F_6 ( V_22 , 1 ) = V_16 ;
V_3 = 0 ;
V_23 = V_20 -> V_27 ;
do {
if ( V_3 + V_20 -> V_27 -
( V_22 -> V_23 + 1 ) >= V_18 ) {
V_25 |= V_31 ;
V_23 = V_18 - V_3 ;
} else {
V_23 = V_20 -> V_27 - V_22 -> V_23 - 1 ;
}
* F_6 ( V_22 , 1 ) = V_25 ;
if ( V_23 > 0 )
memcpy ( F_7 ( V_22 , V_23 ) , V_17 + V_3 , V_23 ) ;
V_24 = F_8 ( V_13 , V_20 -> V_32 , V_22 ) ;
if ( V_24 < 0 )
return V_24 ;
V_3 += V_23 ;
if ( V_3 < V_18 ) {
F_9 ( V_22 , 0 ) ;
F_10 ( V_22 , V_23 ) ;
}
} while ( V_3 < V_18 );
return V_3 ;
}
static void F_11 ( struct V_12 * V_13 , unsigned long V_33 )
{
struct V_34 * V_17 = (struct V_34 * ) V_33 ;
F_3 ( V_13 , V_17 -> V_15 , V_17 -> V_35 ,
V_17 -> V_17 , V_17 -> V_18 ) ;
}
int F_12 ( struct V_12 * V_13 , T_1 V_6 , T_1 V_36 ,
const T_1 * V_37 , T_2 V_38 )
{
T_1 V_15 = V_13 -> V_14 -> V_10 [ V_6 ] ;
if ( V_15 == V_11 )
return - V_39 ;
return F_3 ( V_13 , V_15 ,
F_13 ( V_40 , V_36 ) ,
V_37 , V_38 ) ;
}
int F_14 ( struct V_12 * V_13 , T_1 V_6 , T_1 V_35 ,
const T_1 * V_37 , T_2 V_38 ,
struct V_21 * * V_22 )
{
struct V_19 * V_20 ;
struct V_34 V_17 ;
int V_24 ;
T_1 V_15 = V_13 -> V_14 -> V_10 [ V_6 ] ;
if ( V_15 == V_11 )
return - V_39 ;
V_20 = V_13 -> V_14 -> V_20 ;
if ( ! V_20 )
return - V_26 ;
V_17 . V_32 = V_20 -> V_32 ;
V_17 . V_15 = V_15 ;
V_17 . V_35 = F_13 ( V_41 , V_35 ) ;
V_17 . V_17 = V_37 ;
V_17 . V_18 = V_38 ;
V_24 = F_15 ( V_13 , F_11 , ( unsigned long ) & V_17 ,
F_16 ( V_42 ) ) ;
if ( V_24 == V_43 )
* V_22 = V_20 -> V_44 ;
return V_24 ;
}
static void F_17 ( struct V_12 * V_13 , T_1 V_15 ,
T_1 V_36 , struct V_21 * V_22 )
{
if ( V_13 -> V_45 -> V_46 )
V_13 -> V_45 -> V_46 ( V_13 , V_15 , V_36 , V_22 ) ;
}
static void F_18 ( struct V_12 * V_13 , T_1 V_15 ,
T_1 V_35 , struct V_21 * V_22 )
{
T_1 V_6 = V_13 -> V_14 -> V_5 [ V_15 ] . V_6 ;
T_1 V_47 = V_48 | ~ V_49 ;
T_1 V_50 , V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
F_19 ( L_1 , V_6 , V_15 , V_35 ) ;
switch ( V_35 ) {
case V_58 :
if ( V_22 -> V_23 != 5 ) {
V_47 = V_59 ;
goto exit;
}
V_53 = (struct V_52 * ) V_22 -> V_17 ;
V_50 = V_53 -> V_50 ;
V_51 = V_53 -> V_15 ;
V_13 -> V_14 -> V_10 [ V_50 ] = V_51 ;
V_13 -> V_14 -> V_5 [ V_51 ] . V_6 = V_50 ;
V_13 -> V_14 -> V_5 [ V_51 ] . V_8 =
V_53 -> V_60 ;
break;
case V_61 :
if ( V_6 == V_7 ) {
V_47 = V_59 ;
goto exit;
}
break;
case V_62 :
if ( V_22 -> V_23 != 1 ) {
V_47 = V_59 ;
goto exit;
}
V_55 = (struct V_54 * ) V_22 -> V_17 ;
V_13 -> V_14 -> V_5 [ V_55 -> V_15 ] . V_6 =
V_7 ;
V_13 -> V_14 -> V_5 [ V_55 -> V_15 ] . V_8 =
V_9 ;
break;
case V_63 :
if ( V_22 -> V_23 != 1 ) {
V_47 = V_59 ;
goto exit;
}
V_57 =
(struct V_56 * ) V_22 -> V_17 ;
F_2 ( V_13 , V_57 -> V_8 ) ;
break;
default:
F_19 ( L_2 , V_35 , V_6 ) ;
break;
}
if ( V_13 -> V_45 -> V_64 )
V_13 -> V_45 -> V_64 ( V_13 , V_15 , V_35 , V_22 ) ;
exit:
F_3 ( V_13 , V_15 , V_47 , NULL , 0 ) ;
F_20 ( V_22 ) ;
}
static void F_21 ( struct V_12 * V_13 , T_1 V_15 ,
T_1 V_65 , struct V_21 * V_22 )
{
struct V_19 * V_20 ;
T_1 V_47 = V_65 ;
if ( V_65 != V_48 )
goto exit;
V_20 = V_13 -> V_14 -> V_20 ;
if ( ! V_20 ) {
V_47 = V_66 ;
goto exit;
}
V_20 -> V_44 = V_22 ;
exit:
F_22 ( V_13 , V_47 ) ;
}
static void F_23 ( struct V_12 * V_13 , T_1 V_15 ,
T_1 type , T_1 V_67 , struct V_21 * V_22 )
{
switch ( type ) {
case V_68 :
F_21 ( V_13 , V_15 , V_67 , V_22 ) ;
break;
case V_41 :
F_18 ( V_13 , V_15 , V_67 , V_22 ) ;
break;
case V_40 :
F_17 ( V_13 , V_15 , V_67 , V_22 ) ;
break;
default:
F_24 ( L_3 ,
type , V_67 ) ;
F_20 ( V_22 ) ;
break;
}
F_22 ( V_13 , 0 ) ;
}
static void F_25 ( struct V_69 * V_70 )
{
struct V_1 * V_2 =
F_26 ( V_70 , struct V_1 , V_71 ) ;
struct V_21 * V_22 ;
struct V_72 * V_73 ;
T_1 V_15 , type , V_67 ;
while ( ( V_22 = F_27 ( & V_2 -> V_74 ) ) != NULL ) {
V_15 = V_22 -> V_17 [ 0 ] ;
F_10 ( V_22 , V_75 ) ;
V_73 = (struct V_72 * ) V_22 -> V_17 ;
type = F_28 ( V_73 -> V_76 ) ;
V_67 = F_29 ( V_73 -> V_76 ) ;
F_10 ( V_22 , V_77 ) ;
F_23 ( V_2 -> V_13 , V_15 ,
type , V_67 , V_22 ) ;
}
}
void F_30 ( void * V_78 ,
struct V_21 * V_22 , int V_79 )
{
struct V_12 * V_13 = (struct V_12 * ) V_78 ;
struct V_80 * V_81 ;
T_1 V_15 , type , V_67 ;
struct V_21 * V_82 ;
struct V_21 * V_83 ;
int V_84 ;
F_19 ( L_4 ) ;
if ( V_79 ) {
F_22 ( V_13 , V_79 ) ;
return;
}
V_81 = (struct V_80 * ) V_22 -> V_17 ;
if ( ( V_81 -> V_76 & ~ V_49 ) == 0 ) {
F_31 ( & V_13 -> V_14 -> V_85 , V_22 ) ;
return;
}
if ( F_32 ( & V_13 -> V_14 -> V_85 ) ) {
V_15 = V_81 -> V_76 & V_49 ;
F_31 ( & V_13 -> V_14 -> V_85 , V_22 ) ;
V_84 = 0 ;
F_33 (&ndev->hci_dev->rx_hcp_frags, frag_skb) {
V_84 += ( V_83 -> V_23 -
V_75 ) ;
}
V_82 = F_34 ( V_75 +
V_84 , V_29 ) ;
if ( ! V_82 ) {
F_22 ( V_13 , - V_30 ) ;
return;
}
* F_7 ( V_82 , V_75 ) = V_15 ;
F_33 (&ndev->hci_dev->rx_hcp_frags, frag_skb) {
V_84 = V_83 -> V_23 - V_75 ;
memcpy ( F_7 ( V_82 , V_84 ) , V_83 -> V_17 +
V_75 , V_84 ) ;
}
F_35 ( & V_13 -> V_14 -> V_85 ) ;
} else {
V_81 -> V_76 &= V_49 ;
V_82 = V_22 ;
}
V_81 = (struct V_80 * ) V_82 -> V_17 ;
type = F_28 ( V_81 -> V_73 . V_76 ) ;
if ( type == V_68 ) {
V_15 = V_81 -> V_76 ;
V_67 = F_29 ( V_81 -> V_73 . V_76 ) ;
F_10 ( V_82 , V_75 +
V_77 ) ;
F_23 ( V_13 , V_15 , type , V_67 , V_82 ) ;
} else {
F_31 ( & V_13 -> V_14 -> V_74 , V_82 ) ;
F_36 ( & V_13 -> V_14 -> V_71 ) ;
}
}
int F_37 ( struct V_12 * V_13 , T_1 V_15 )
{
struct V_34 V_17 ;
struct V_19 * V_20 ;
V_20 = V_13 -> V_14 -> V_20 ;
if ( ! V_20 )
return - V_26 ;
V_17 . V_32 = V_20 -> V_32 ;
V_17 . V_15 = V_15 ;
V_17 . V_35 = F_13 ( V_41 ,
V_61 ) ;
V_17 . V_17 = NULL ;
V_17 . V_18 = 0 ;
return F_15 ( V_13 , F_11 ,
( unsigned long ) & V_17 ,
F_16 ( V_42 ) ) ;
}
int F_38 ( struct V_12 * V_13 , T_1 V_6 , T_1 V_86 ,
const T_1 * V_37 , T_2 V_38 )
{
struct V_19 * V_20 ;
struct V_34 V_17 ;
int V_24 ;
T_1 * V_87 ;
T_1 V_15 = V_13 -> V_14 -> V_10 [ V_6 ] ;
F_19 ( L_5 , V_86 , V_6 ) ;
if ( V_15 == V_11 )
return - V_39 ;
V_20 = V_13 -> V_14 -> V_20 ;
if ( ! V_20 )
return - V_26 ;
V_87 = F_39 ( 1 + V_38 , V_29 ) ;
if ( ! V_87 )
return - V_30 ;
* V_87 = V_86 ;
memcpy ( V_87 + 1 , V_37 , V_38 ) ;
V_17 . V_32 = V_20 -> V_32 ;
V_17 . V_15 = V_15 ;
V_17 . V_35 = F_13 ( V_41 ,
V_88 ) ;
V_17 . V_17 = V_87 ;
V_17 . V_18 = V_38 + 1 ;
V_24 = F_15 ( V_13 , F_11 ,
( unsigned long ) & V_17 ,
F_16 ( V_42 ) ) ;
F_40 ( V_87 ) ;
return V_24 ;
}
int F_41 ( struct V_12 * V_13 , T_1 V_6 , T_1 V_86 ,
struct V_21 * * V_22 )
{
struct V_19 * V_20 ;
struct V_34 V_17 ;
int V_24 ;
T_1 V_15 = V_13 -> V_14 -> V_10 [ V_6 ] ;
F_19 ( L_5 , V_86 , V_6 ) ;
if ( V_15 == V_11 )
return - V_39 ;
V_20 = V_13 -> V_14 -> V_20 ;
if ( ! V_20 )
return - V_26 ;
V_17 . V_32 = V_20 -> V_32 ;
V_17 . V_15 = V_15 ;
V_17 . V_35 = F_13 ( V_41 ,
V_89 ) ;
V_17 . V_17 = & V_86 ;
V_17 . V_18 = 1 ;
V_24 = F_15 ( V_13 , F_11 , ( unsigned long ) & V_17 ,
F_16 ( V_42 ) ) ;
if ( V_24 == V_43 )
* V_22 = V_20 -> V_44 ;
return V_24 ;
}
int F_42 ( struct V_12 * V_13 ,
T_1 V_90 , T_1 V_50 , T_1 V_15 )
{
int V_24 ;
if ( V_15 == V_91 )
return 0 ;
if ( V_13 -> V_14 -> V_10 [ V_50 ] != V_11 )
return - V_92 ;
if ( V_15 != V_11 )
goto V_93;
switch ( V_50 ) {
case V_94 :
V_15 = V_95 ;
break;
case V_96 :
V_15 = V_97 ;
break;
}
V_93:
V_24 = F_37 ( V_13 , V_15 ) ;
if ( V_24 < 0 )
return V_24 ;
V_13 -> V_14 -> V_5 [ V_15 ] . V_6 = V_50 ;
V_13 -> V_14 -> V_5 [ V_15 ] . V_8 = V_90 ;
V_13 -> V_14 -> V_10 [ V_50 ] = V_15 ;
return 0 ;
}
static int F_43 ( struct V_12 * V_13 ,
T_1 V_98 ,
struct V_99 * V_100 )
{
int V_24 ;
while ( V_98 -- ) {
V_24 = F_42 ( V_13 , V_100 -> V_90 ,
V_100 -> V_6 , V_100 -> V_15 ) ;
if ( V_24 < 0 )
return V_24 ;
V_100 ++ ;
}
return 0 ;
}
int F_44 ( struct V_12 * V_13 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_24 ;
V_13 -> V_14 -> V_101 = 0 ;
V_13 -> V_14 -> V_102 = 0 ;
V_20 = V_13 -> V_14 -> V_20 ;
if ( ! V_20 )
return - V_26 ;
V_20 -> V_103 = F_30 ;
V_20 -> V_104 = V_13 ;
F_1 ( V_13 -> V_14 ) ;
if ( V_13 -> V_14 -> V_105 . V_100 [ 0 ] . V_6 != V_96 )
return - V_26 ;
V_24 = F_42 ( V_13 ,
V_13 -> V_14 -> V_105 . V_100 [ 0 ] . V_90 ,
V_13 -> V_14 -> V_105 . V_100 [ 0 ] . V_6 ,
V_13 -> V_14 -> V_105 . V_100 [ 0 ] . V_15 ) ;
if ( V_24 < 0 )
goto exit;
V_24 = F_41 ( V_13 , V_96 ,
V_106 , & V_22 ) ;
if ( V_24 < 0 )
goto exit;
if ( V_22 -> V_23 &&
V_22 -> V_23 == strlen ( V_13 -> V_14 -> V_105 . V_107 ) &&
memcmp ( V_13 -> V_14 -> V_105 . V_107 ,
V_22 -> V_17 , V_22 -> V_23 ) == 0 &&
V_13 -> V_45 -> V_108 ) {
V_24 = V_13 -> V_45 -> V_108 ( V_13 ) ;
if ( V_24 < 0 )
goto exit;
} else {
V_24 = F_43 ( V_13 ,
V_13 -> V_14 -> V_105 . V_98 ,
V_13 -> V_14 -> V_105 . V_100 ) ;
if ( V_24 < 0 )
goto exit;
V_24 = F_38 ( V_13 , V_96 ,
V_106 ,
V_13 -> V_14 -> V_105 . V_107 ,
strlen ( V_13 -> V_14 -> V_105 . V_107 ) ) ;
}
if ( V_24 == 0 )
goto exit;
exit:
F_20 ( V_22 ) ;
return V_24 ;
}
struct V_1 * F_45 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
V_2 = F_46 ( sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
return NULL ;
F_47 ( & V_2 -> V_85 ) ;
F_48 ( & V_2 -> V_71 , F_25 ) ;
F_47 ( & V_2 -> V_74 ) ;
V_2 -> V_13 = V_13 ;
return V_2 ;
}
