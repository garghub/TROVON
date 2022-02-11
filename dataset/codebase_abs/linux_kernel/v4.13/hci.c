static int F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case V_2 :
return 0 ;
case V_3 :
return - V_4 ;
case V_5 :
return - V_6 ;
default:
return - 1 ;
}
}
static void F_2 ( struct V_7 * V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_8 -> V_11 [ V_9 ] . V_12 = V_13 ;
V_8 -> V_11 [ V_9 ] . V_14 = V_15 ;
}
memset ( V_8 -> V_16 , V_17 , sizeof( V_8 -> V_16 ) ) ;
}
static void F_3 ( struct V_18 * V_19 , T_1 V_14 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( V_19 -> V_20 -> V_11 [ V_9 ] . V_14 == V_14 ) {
V_19 -> V_20 -> V_11 [ V_9 ] . V_12 = V_13 ;
V_19 -> V_20 -> V_11 [ V_9 ] . V_14 = V_15 ;
}
}
}
static int F_4 ( struct V_18 * V_19 , T_1 V_21 ,
const T_1 V_22 , const T_1 * V_23 ,
T_2 V_24 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
int V_29 , V_9 , V_30 ;
T_1 V_31 = V_21 ;
V_26 = V_19 -> V_20 -> V_26 ;
if ( ! V_26 )
return - V_32 ;
V_9 = 0 ;
V_28 = F_5 ( V_19 , V_26 -> V_33 +
V_34 , V_35 ) ;
if ( ! V_28 )
return - V_36 ;
F_6 ( V_28 , V_34 + 2 ) ;
* ( T_1 * ) F_7 ( V_28 , 1 ) = V_22 ;
do {
V_29 = V_26 -> V_33 ;
if ( V_9 + V_26 -> V_33 -
( V_28 -> V_29 + 1 ) >= V_24 ) {
V_31 |= V_37 ;
V_29 = V_24 - V_9 ;
} else {
V_29 = V_26 -> V_33 - V_28 -> V_29 - 1 ;
}
* ( T_1 * ) F_7 ( V_28 , 1 ) = V_31 ;
if ( V_29 > 0 )
F_8 ( V_28 , V_23 + V_9 , V_29 ) ;
V_30 = F_9 ( V_19 , V_26 -> V_38 , V_28 ) ;
if ( V_30 < 0 )
return V_30 ;
V_9 += V_29 ;
if ( V_9 < V_24 ) {
V_28 = F_5 ( V_19 ,
V_26 -> V_33 +
V_34 , V_35 ) ;
if ( ! V_28 )
return - V_36 ;
F_6 ( V_28 , V_34 + 1 ) ;
}
} while ( V_9 < V_24 );
return V_9 ;
}
static void F_10 ( struct V_18 * V_19 , unsigned long V_39 )
{
struct V_40 * V_23 = (struct V_40 * ) V_39 ;
F_4 ( V_19 , V_23 -> V_21 , V_23 -> V_41 ,
V_23 -> V_23 , V_23 -> V_24 ) ;
}
int F_11 ( struct V_18 * V_19 , T_1 V_12 , T_1 V_42 ,
const T_1 * V_43 , T_2 V_44 )
{
T_1 V_21 = V_19 -> V_20 -> V_16 [ V_12 ] ;
if ( V_21 == V_17 )
return - V_45 ;
return F_4 ( V_19 , V_21 ,
F_12 ( V_46 , V_42 ) ,
V_43 , V_44 ) ;
}
int F_13 ( struct V_18 * V_19 , T_1 V_12 , T_1 V_41 ,
const T_1 * V_43 , T_2 V_44 ,
struct V_27 * * V_28 )
{
struct V_47 * V_48 ;
struct V_25 * V_26 ;
struct V_40 V_23 ;
int V_30 ;
T_1 V_21 = V_19 -> V_20 -> V_16 [ V_12 ] ;
if ( V_21 == V_17 )
return - V_45 ;
V_26 = V_19 -> V_20 -> V_26 ;
if ( ! V_26 )
return - V_32 ;
V_23 . V_38 = V_26 -> V_38 ;
V_23 . V_21 = V_21 ;
V_23 . V_41 = F_12 ( V_49 , V_41 ) ;
V_23 . V_23 = V_43 ;
V_23 . V_24 = V_44 ;
V_30 = F_14 ( V_19 , F_10 , ( unsigned long ) & V_23 ,
F_15 ( V_50 ) ) ;
if ( V_30 == V_51 ) {
V_48 = (struct V_47 * ) V_26 -> V_52 -> V_23 ;
V_30 = F_1 (
F_16 ( V_48 -> V_53 ) ) ;
F_17 ( V_26 -> V_52 , V_54 ) ;
if ( ! V_30 && V_28 )
* V_28 = V_26 -> V_52 ;
}
return V_30 ;
}
int F_18 ( struct V_18 * V_19 )
{
int V_30 ;
V_30 = F_13 ( V_19 , V_55 ,
V_56 , NULL , 0 , NULL ) ;
if ( V_30 < 0 )
return V_30 ;
F_2 ( V_19 -> V_20 ) ;
return V_30 ;
}
static void F_19 ( struct V_18 * V_19 , T_1 V_21 ,
T_1 V_42 , struct V_27 * V_28 )
{
if ( V_19 -> V_57 -> V_58 )
V_19 -> V_57 -> V_58 ( V_19 , V_21 , V_42 , V_28 ) ;
}
static void F_20 ( struct V_18 * V_19 , T_1 V_21 ,
T_1 V_41 , struct V_27 * V_28 )
{
T_1 V_12 = V_19 -> V_20 -> V_11 [ V_21 ] . V_12 ;
T_1 V_59 = V_2 | ~ V_60 ;
T_1 V_61 , V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
F_21 ( L_1 , V_12 , V_21 , V_41 ) ;
switch ( V_41 ) {
case V_69 :
if ( V_28 -> V_29 != 5 ) {
V_59 = V_70 ;
goto exit;
}
V_64 = (struct V_63 * ) V_28 -> V_23 ;
V_61 = V_64 -> V_61 ;
V_62 = V_64 -> V_21 ;
V_19 -> V_20 -> V_16 [ V_61 ] = V_62 ;
V_19 -> V_20 -> V_11 [ V_62 ] . V_12 = V_61 ;
V_19 -> V_20 -> V_11 [ V_62 ] . V_14 =
V_64 -> V_71 ;
break;
case V_72 :
if ( V_12 == V_13 ) {
V_59 = V_70 ;
goto exit;
}
break;
case V_73 :
if ( V_28 -> V_29 != 1 ) {
V_59 = V_70 ;
goto exit;
}
V_66 = (struct V_65 * ) V_28 -> V_23 ;
V_19 -> V_20 -> V_11 [ V_66 -> V_21 ] . V_12 =
V_13 ;
V_19 -> V_20 -> V_11 [ V_66 -> V_21 ] . V_14 =
V_15 ;
break;
case V_74 :
if ( V_28 -> V_29 != 1 ) {
V_59 = V_70 ;
goto exit;
}
V_68 =
(struct V_67 * ) V_28 -> V_23 ;
F_3 ( V_19 , V_68 -> V_14 ) ;
break;
default:
F_21 ( L_2 , V_41 , V_12 ) ;
break;
}
if ( V_19 -> V_57 -> V_75 )
V_19 -> V_57 -> V_75 ( V_19 , V_21 , V_41 , V_28 ) ;
exit:
F_4 ( V_19 , V_21 , V_59 , NULL , 0 ) ;
F_22 ( V_28 ) ;
}
static void F_23 ( struct V_18 * V_19 , T_1 V_21 ,
T_1 V_1 , struct V_27 * V_28 )
{
struct V_25 * V_26 ;
T_1 V_59 = V_1 ;
V_26 = V_19 -> V_20 -> V_26 ;
if ( ! V_26 ) {
V_59 = V_76 ;
goto exit;
}
V_26 -> V_52 = V_28 ;
exit:
F_24 ( V_19 , V_51 ) ;
}
static void F_25 ( struct V_18 * V_19 , T_1 V_21 ,
T_1 type , T_1 V_77 , struct V_27 * V_28 )
{
switch ( type ) {
case V_78 :
F_23 ( V_19 , V_21 , V_77 , V_28 ) ;
break;
case V_49 :
F_20 ( V_19 , V_21 , V_77 , V_28 ) ;
break;
case V_46 :
F_19 ( V_19 , V_21 , V_77 , V_28 ) ;
break;
default:
F_26 ( L_3 ,
type , V_77 ) ;
F_22 ( V_28 ) ;
break;
}
F_24 ( V_19 , V_51 ) ;
}
static void F_27 ( struct V_79 * V_80 )
{
struct V_7 * V_8 =
F_28 ( V_80 , struct V_7 , V_81 ) ;
struct V_27 * V_28 ;
struct V_47 * V_48 ;
T_1 V_21 , type , V_77 ;
while ( ( V_28 = F_29 ( & V_8 -> V_82 ) ) != NULL ) {
V_21 = F_30 ( V_28 -> V_23 [ 0 ] ) ;
F_17 ( V_28 , V_83 ) ;
V_48 = (struct V_47 * ) V_28 -> V_23 ;
type = F_31 ( V_48 -> V_53 ) ;
V_77 = F_16 ( V_48 -> V_53 ) ;
F_17 ( V_28 , V_54 ) ;
F_25 ( V_8 -> V_19 , V_21 ,
type , V_77 , V_28 ) ;
}
}
void F_32 ( void * V_84 ,
struct V_27 * V_28 , int V_85 )
{
struct V_18 * V_19 = (struct V_18 * ) V_84 ;
struct V_86 * V_87 ;
T_1 V_21 , type ;
struct V_27 * V_88 ;
struct V_27 * V_89 ;
int V_90 ;
F_21 ( L_4 ) ;
if ( V_85 ) {
F_24 ( V_19 , V_85 ) ;
return;
}
V_87 = (struct V_86 * ) V_28 -> V_23 ;
if ( ( V_87 -> V_53 & ~ V_60 ) == 0 ) {
F_33 ( & V_19 -> V_20 -> V_91 , V_28 ) ;
return;
}
if ( F_34 ( & V_19 -> V_20 -> V_91 ) ) {
V_21 = F_30 ( V_87 -> V_53 ) ;
F_33 ( & V_19 -> V_20 -> V_91 , V_28 ) ;
V_90 = 0 ;
F_35 (&ndev->hci_dev->rx_hcp_frags, frag_skb) {
V_90 += ( V_89 -> V_29 -
V_83 ) ;
}
V_88 = F_36 ( V_83 +
V_90 , V_35 ) ;
if ( ! V_88 ) {
F_24 ( V_19 , - V_36 ) ;
return;
}
F_37 ( V_88 , V_21 ) ;
F_35 (&ndev->hci_dev->rx_hcp_frags, frag_skb) {
V_90 = V_89 -> V_29 - V_83 ;
F_8 ( V_88 ,
V_89 -> V_23 + V_83 ,
V_90 ) ;
}
F_38 ( & V_19 -> V_20 -> V_91 ) ;
} else {
V_87 -> V_53 &= V_60 ;
V_88 = V_28 ;
}
V_87 = (struct V_86 * ) V_88 -> V_23 ;
type = F_31 ( V_87 -> V_48 . V_53 ) ;
if ( type == V_78 ) {
V_21 = F_30 ( V_87 -> V_53 ) ;
F_17 ( V_88 , V_83 ) ;
F_25 ( V_19 , V_21 , type ,
V_51 , V_88 ) ;
} else {
F_33 ( & V_19 -> V_20 -> V_82 , V_88 ) ;
F_39 ( & V_19 -> V_20 -> V_81 ) ;
}
}
int F_40 ( struct V_18 * V_19 , T_1 V_21 )
{
struct V_40 V_23 ;
struct V_25 * V_26 ;
V_26 = V_19 -> V_20 -> V_26 ;
if ( ! V_26 )
return - V_32 ;
V_23 . V_38 = V_26 -> V_38 ;
V_23 . V_21 = V_21 ;
V_23 . V_41 = F_12 ( V_49 ,
V_72 ) ;
V_23 . V_23 = NULL ;
V_23 . V_24 = 0 ;
return F_14 ( V_19 , F_10 ,
( unsigned long ) & V_23 ,
F_15 ( V_50 ) ) ;
}
static T_1 F_41 ( struct V_18 * V_19 , T_1 V_92 ,
T_1 V_61 , int * V_1 )
{
T_1 V_21 ;
struct V_27 * V_28 ;
struct V_93 V_94 ;
struct V_63 * V_95 ;
F_21 ( L_5 , V_61 ) ;
V_94 . V_96 = V_55 ;
V_94 . V_92 = V_92 ;
V_94 . V_61 = V_61 ;
* V_1 = F_13 ( V_19 , V_55 ,
V_97 ,
( T_1 * ) & V_94 , sizeof( V_94 ) , & V_28 ) ;
if ( * V_1 < 0 )
return V_17 ;
V_95 = (struct V_63 * ) V_28 -> V_23 ;
V_21 = V_95 -> V_21 ;
F_22 ( V_28 ) ;
F_21 ( L_6 , V_21 ) ;
return V_21 ;
}
static int F_42 ( struct V_18 * V_19 , T_1 V_21 )
{
F_21 ( L_4 ) ;
return F_13 ( V_19 , V_55 ,
V_98 , & V_21 , 1 , NULL ) ;
}
int F_43 ( struct V_18 * V_19 , T_1 V_12 , T_1 V_99 ,
const T_1 * V_43 , T_2 V_44 )
{
struct V_47 * V_48 ;
struct V_25 * V_26 ;
struct V_40 V_23 ;
int V_30 ;
T_1 * V_100 ;
T_1 V_21 = V_19 -> V_20 -> V_16 [ V_12 ] ;
F_21 ( L_7 , V_99 , V_12 ) ;
if ( V_21 == V_17 )
return - V_45 ;
V_26 = V_19 -> V_20 -> V_26 ;
if ( ! V_26 )
return - V_32 ;
V_100 = F_44 ( 1 + V_44 , V_35 ) ;
if ( ! V_100 )
return - V_36 ;
* V_100 = V_99 ;
memcpy ( V_100 + 1 , V_43 , V_44 ) ;
V_23 . V_38 = V_26 -> V_38 ;
V_23 . V_21 = V_21 ;
V_23 . V_41 = F_12 ( V_49 ,
V_101 ) ;
V_23 . V_23 = V_100 ;
V_23 . V_24 = V_44 + 1 ;
V_30 = F_14 ( V_19 , F_10 ,
( unsigned long ) & V_23 ,
F_15 ( V_50 ) ) ;
if ( V_30 == V_51 ) {
V_48 = (struct V_47 * ) V_26 -> V_52 -> V_23 ;
V_30 = F_1 (
F_16 ( V_48 -> V_53 ) ) ;
F_17 ( V_26 -> V_52 , V_54 ) ;
}
F_45 ( V_100 ) ;
return V_30 ;
}
int F_46 ( struct V_18 * V_19 , T_1 V_12 , T_1 V_99 ,
struct V_27 * * V_28 )
{
struct V_47 * V_48 ;
struct V_25 * V_26 ;
struct V_40 V_23 ;
int V_30 ;
T_1 V_21 = V_19 -> V_20 -> V_16 [ V_12 ] ;
F_21 ( L_7 , V_99 , V_12 ) ;
if ( V_21 == V_17 )
return - V_45 ;
V_26 = V_19 -> V_20 -> V_26 ;
if ( ! V_26 )
return - V_32 ;
V_23 . V_38 = V_26 -> V_38 ;
V_23 . V_21 = V_21 ;
V_23 . V_41 = F_12 ( V_49 ,
V_102 ) ;
V_23 . V_23 = & V_99 ;
V_23 . V_24 = 1 ;
V_30 = F_14 ( V_19 , F_10 , ( unsigned long ) & V_23 ,
F_15 ( V_50 ) ) ;
if ( V_30 == V_51 ) {
V_48 = (struct V_47 * ) V_26 -> V_52 -> V_23 ;
V_30 = F_1 (
F_16 ( V_48 -> V_53 ) ) ;
F_17 ( V_26 -> V_52 , V_54 ) ;
if ( ! V_30 && V_28 )
* V_28 = V_26 -> V_52 ;
}
return V_30 ;
}
int F_47 ( struct V_18 * V_19 ,
T_1 V_92 , T_1 V_61 , T_1 V_21 )
{
bool V_103 = false ;
int V_30 ;
if ( V_21 == V_104 )
return 0 ;
if ( V_19 -> V_20 -> V_16 [ V_61 ] != V_17 )
return - V_105 ;
if ( V_21 != V_17 )
goto V_106;
switch ( V_61 ) {
case V_107 :
V_21 = V_108 ;
break;
case V_55 :
V_21 = V_109 ;
break;
default:
V_21 = F_41 ( V_19 , V_92 , V_61 , & V_30 ) ;
if ( V_21 == V_17 )
return V_30 ;
V_103 = true ;
break;
}
V_106:
V_30 = F_40 ( V_19 , V_21 ) ;
if ( V_30 < 0 ) {
if ( V_103 ) {
if ( F_42 ( V_19 , V_21 ) < 0 ) {
}
}
return V_30 ;
}
V_19 -> V_20 -> V_11 [ V_21 ] . V_12 = V_61 ;
V_19 -> V_20 -> V_11 [ V_21 ] . V_14 = V_92 ;
V_19 -> V_20 -> V_16 [ V_61 ] = V_21 ;
return 0 ;
}
static int F_48 ( struct V_18 * V_19 ,
T_1 V_110 ,
struct V_111 * V_112 )
{
int V_30 ;
while ( V_110 -- ) {
V_30 = F_47 ( V_19 , V_112 -> V_92 ,
V_112 -> V_12 , V_112 -> V_21 ) ;
if ( V_30 < 0 )
return V_30 ;
V_112 ++ ;
}
return 0 ;
}
int F_49 ( struct V_18 * V_19 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
int V_30 ;
V_19 -> V_20 -> V_113 = 0 ;
V_19 -> V_20 -> V_114 = 0 ;
V_26 = V_19 -> V_20 -> V_26 ;
if ( ! V_26 )
return - V_32 ;
V_26 -> V_115 = F_32 ;
V_26 -> V_116 = V_19 ;
F_2 ( V_19 -> V_20 ) ;
if ( V_19 -> V_20 -> V_117 . V_112 [ 0 ] . V_12 != V_55 )
return - V_32 ;
V_30 = F_47 ( V_19 ,
V_19 -> V_20 -> V_117 . V_112 [ 0 ] . V_92 ,
V_19 -> V_20 -> V_117 . V_112 [ 0 ] . V_12 ,
V_19 -> V_20 -> V_117 . V_112 [ 0 ] . V_21 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_46 ( V_19 , V_55 ,
V_118 , & V_28 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_28 -> V_29 &&
V_28 -> V_29 == strlen ( V_19 -> V_20 -> V_117 . V_119 ) &&
! memcmp ( V_19 -> V_20 -> V_117 . V_119 , V_28 -> V_23 , V_28 -> V_29 ) &&
V_19 -> V_57 -> V_120 ) {
V_30 = V_19 -> V_57 -> V_120 ( V_19 ) ;
} else {
V_30 = F_18 ( V_19 ) ;
if ( V_30 < 0 )
goto exit;
V_30 = F_48 ( V_19 ,
V_19 -> V_20 -> V_117 . V_110 ,
V_19 -> V_20 -> V_117 . V_112 ) ;
if ( V_30 < 0 )
goto exit;
V_30 = F_43 ( V_19 , V_55 ,
V_118 ,
V_19 -> V_20 -> V_117 . V_119 ,
strlen ( V_19 -> V_20 -> V_117 . V_119 ) ) ;
}
exit:
F_22 ( V_28 ) ;
return V_30 ;
}
struct V_7 * F_50 ( struct V_18 * V_19 )
{
struct V_7 * V_8 ;
V_8 = F_51 ( sizeof( * V_8 ) , V_35 ) ;
if ( ! V_8 )
return NULL ;
F_52 ( & V_8 -> V_91 ) ;
F_53 ( & V_8 -> V_81 , F_27 ) ;
F_52 ( & V_8 -> V_82 ) ;
V_8 -> V_19 = V_19 ;
return V_8 ;
}
