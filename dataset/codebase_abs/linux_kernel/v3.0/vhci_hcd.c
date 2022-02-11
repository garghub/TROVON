static void F_1 ( T_1 V_1 )
{
int V_2 = 0 ;
F_2 ( L_1 , V_1 ) ;
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ ) {
if ( V_1 & ( 1 << V_2 ) )
F_2 ( L_2 , V_3 [ V_2 ] ) ;
}
F_2 ( L_3 ) ;
}
void F_3 ( int V_4 , enum V_5 V_6 )
{
unsigned long V_7 ;
F_4 ( L_4 , V_4 ) ;
F_5 ( & V_8 -> V_9 , V_7 ) ;
V_8 -> V_10 [ V_4 ] |= V_11
| ( 1 << V_12 ) ;
switch ( V_6 ) {
case V_13 :
V_8 -> V_10 [ V_4 ] |= V_14 ;
break;
case V_15 :
V_8 -> V_10 [ V_4 ] |= V_16 ;
break;
default:
break;
}
F_6 ( & V_8 -> V_9 , V_7 ) ;
F_7 ( F_8 ( V_8 ) ) ;
}
void F_9 ( int V_4 )
{
unsigned long V_7 ;
F_4 ( L_5 , V_4 ) ;
F_5 ( & V_8 -> V_9 , V_7 ) ;
V_8 -> V_10 [ V_4 ] &= ~ V_11 ;
V_8 -> V_10 [ V_4 ] |=
( 1 << V_12 ) ;
F_6 ( & V_8 -> V_9 , V_7 ) ;
F_7 ( F_8 ( V_8 ) ) ;
}
static int F_10 ( struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_21 ;
unsigned long V_7 ;
int V_22 = 0 ;
unsigned long * V_23 = ( unsigned long * ) V_19 ;
int V_4 ;
int V_24 = 0 ;
* V_23 = 0 ;
V_21 = F_11 ( V_18 ) ;
F_5 ( & V_21 -> V_9 , V_7 ) ;
if ( ! F_12 ( V_18 ) ) {
F_4 ( L_6 ) ;
goto V_25;
}
for ( V_4 = 0 ; V_4 < V_26 ; V_4 ++ ) {
if ( ( V_21 -> V_10 [ V_4 ] & V_27 ) ) {
F_4 ( L_7 , V_4 ) ;
* V_23 |= 1 << ( V_4 + 1 ) ;
V_24 = 1 ;
}
}
F_13 ( L_8 , V_24 ) ;
if ( V_18 -> V_28 == V_29 )
F_14 ( V_18 ) ;
if ( V_24 )
V_22 = 1 + ( V_26 / 8 ) ;
else
V_22 = 0 ;
V_25:
F_6 ( & V_21 -> V_9 , V_7 ) ;
return V_22 ;
}
static inline void F_15 ( struct V_30 * V_31 )
{
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_32 = 0x29 ;
V_31 -> V_33 = 9 ;
V_31 -> V_34 = ( V_35 V_36 )
( F_16 ( 0x0001 ) ) ;
V_31 -> V_37 = V_26 ;
V_31 -> V_38 . V_39 . V_40 [ 0 ] = 0xff ;
V_31 -> V_38 . V_39 . V_40 [ 1 ] = 0xff ;
}
static int F_17 ( struct V_17 * V_18 , T_2 V_41 , T_2 V_42 ,
T_2 V_43 , char * V_19 , T_2 V_44 )
{
struct V_20 * V_45 ;
int V_22 = 0 ;
unsigned long V_7 ;
int V_4 ;
T_1 V_46 [ V_26 ] ;
if ( ! F_12 ( V_18 ) )
return - V_47 ;
F_4 ( L_9 , V_41 , V_42 ,
V_43 ) ;
if ( V_43 > V_26 )
F_18 ( L_10 , V_43 ) ;
V_4 = ( ( V_48 ) ( V_43 & 0x00ff ) ) - 1 ;
V_45 = F_11 ( V_18 ) ;
F_5 ( & V_45 -> V_9 , V_7 ) ;
if ( V_49 ) {
int V_2 = 0 ;
for ( V_2 = 0 ; V_2 < V_26 ; V_2 ++ )
V_46 [ V_2 ] = V_45 -> V_10 [ V_2 ] ;
}
switch ( V_41 ) {
case V_50 :
F_4 ( L_11 ) ;
break;
case V_51 :
switch ( V_42 ) {
case V_52 :
if ( V_45 -> V_10 [ V_4 ] & V_53 ) {
V_45 -> V_54 = 1 ;
V_45 -> V_55 =
V_56 + F_19 ( 20 ) ;
}
break;
case V_57 :
F_4 ( L_12
L_13 ) ;
V_45 -> V_10 [ V_4 ] = 0 ;
V_45 -> V_54 = 0 ;
break;
case V_58 :
F_4 ( L_12
L_14 ) ;
switch ( V_45 -> V_59 [ V_4 ] . V_6 ) {
case V_13 :
V_45 -> V_10 [ V_4 ] |=
V_14 ;
break;
case V_15 :
V_45 -> V_10 [ V_4 ] |=
V_16 ;
break;
default:
break;
}
default:
F_4 ( L_15 ,
V_42 ) ;
V_45 -> V_10 [ V_4 ] &= ~ ( 1 << V_42 ) ;
break;
}
break;
case V_60 :
F_4 ( L_16 ) ;
F_15 ( (struct V_30 * ) V_19 ) ;
break;
case V_61 :
F_4 ( L_17 ) ;
* ( V_62 * ) V_19 = F_20 ( 0 ) ;
break;
case V_63 :
F_4 ( L_18 , V_43 ) ;
if ( V_43 > V_26 || V_43 < 1 ) {
F_18 ( L_10 , V_43 ) ;
V_22 = - V_64 ;
}
if ( V_45 -> V_54 && F_21 ( V_56 , V_45 -> V_55 ) ) {
V_45 -> V_10 [ V_4 ] |=
( 1 << V_65 ) ;
V_45 -> V_10 [ V_4 ] &=
~ ( 1 << V_52 ) ;
V_45 -> V_54 = 0 ;
V_45 -> V_55 = 0 ;
}
if ( ( V_45 -> V_10 [ V_4 ] & ( 1 << V_66 ) ) !=
0 && F_21 ( V_56 , V_45 -> V_55 ) ) {
V_45 -> V_10 [ V_4 ] |=
( 1 << V_58 ) ;
V_45 -> V_10 [ V_4 ] &=
~ ( 1 << V_66 ) ;
V_45 -> V_55 = 0 ;
if ( V_45 -> V_59 [ V_4 ] . V_67 . V_1 ==
V_68 ) {
F_4 ( L_19
L_20 ,
V_4 ,
V_45 -> V_59 [ V_4 ] . V_67 . V_1 ) ;
V_45 -> V_10 [ V_4 ] |=
V_69 ;
}
#if 0
if (dum->driver) {
dum->port_status[rhport] |=
USB_PORT_STAT_ENABLE;
dum->gadget.speed = dum->driver->speed;
dum->gadget.ep0->maxpacket = 64;
switch (dum->gadget.speed) {
case USB_SPEED_HIGH:
dum->port_status[rhport] |=
USB_PORT_STAT_HIGH_SPEED;
break;
case USB_SPEED_LOW:
dum->gadget.ep0->maxpacket = 8;
dum->port_status[rhport] |=
USB_PORT_STAT_LOW_SPEED;
break;
default:
dum->gadget.speed = USB_SPEED_FULL;
break;
}
}
#endif
}
( ( T_2 * ) V_19 ) [ 0 ] = F_22 ( V_45 -> V_10 [ V_4 ] ) ;
( ( T_2 * ) V_19 ) [ 1 ] = F_22 ( V_45 -> V_10 [ V_4 ] >> 16 ) ;
F_4 ( L_21 , ( ( T_2 * ) V_19 ) [ 0 ] ,
( ( T_2 * ) V_19 ) [ 1 ] ) ;
break;
case V_70 :
F_4 ( L_22 ) ;
V_22 = - V_64 ;
break;
case V_71 :
switch ( V_42 ) {
case V_52 :
F_4 ( L_23
L_24 ) ;
#if 0
dum->port_status[rhport] |=
(1 << USB_PORT_FEAT_SUSPEND);
if (dum->driver->suspend) {
spin_unlock(&dum->lock);
dum->driver->suspend(&dum->gadget);
spin_lock(&dum->lock);
}
#endif
break;
case V_66 :
F_4 ( L_23
L_25 ) ;
if ( V_45 -> V_10 [ V_4 ] & V_69 ) {
V_45 -> V_10 [ V_4 ] &=
~ ( V_69 |
V_16 |
V_14 ) ;
#if 0
if (dum->driver) {
dev_dbg(hardware, "disconnect\n");
stop_activity(dum, dum->driver);
}
#endif
}
V_45 -> V_55 = V_56 + F_19 ( 50 ) ;
default:
F_4 ( L_26 ,
V_42 ) ;
V_45 -> V_10 [ V_4 ] |= ( 1 << V_42 ) ;
break;
}
break;
default:
F_18 ( L_27 ) ;
V_22 = - V_64 ;
}
if ( V_49 ) {
F_2 ( L_28 , V_4 ) ;
F_1 ( V_46 [ V_4 ] ) ;
F_1 ( V_45 -> V_10 [ V_4 ] ) ;
}
F_4 ( L_29 ) ;
F_6 ( & V_45 -> V_9 , V_7 ) ;
return V_22 ;
}
static struct V_72 * F_23 ( struct V_73 * V_74 )
{
int V_2 ;
if ( ! V_74 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_26 ; V_2 ++ )
if ( V_8 -> V_59 [ V_2 ] . V_74 == V_74 )
return F_24 ( V_2 ) ;
return NULL ;
}
static void F_25 ( struct V_75 * V_75 )
{
struct V_72 * V_59 = F_23 ( V_75 -> V_76 ) ;
struct V_77 * V_78 ;
unsigned long V_79 ;
if ( ! V_59 ) {
F_18 ( L_30 ) ;
return;
}
V_78 = F_26 ( sizeof( struct V_77 ) , V_80 ) ;
F_5 ( & V_59 -> V_81 , V_79 ) ;
if ( ! V_78 ) {
F_27 ( & V_75 -> V_76 -> V_76 , L_31 ) ;
F_6 ( & V_59 -> V_81 , V_79 ) ;
F_28 ( & V_59 -> V_67 , V_82 ) ;
return;
}
V_78 -> V_83 = F_29 ( & V_8 -> V_83 ) ;
if ( V_78 -> V_83 == 0xffff )
F_30 ( & V_75 -> V_76 -> V_76 , L_32 ) ;
V_78 -> V_59 = V_59 ;
V_78 -> V_75 = V_75 ;
V_75 -> V_84 = ( void * ) V_78 ;
F_31 ( & V_78 -> V_85 , & V_59 -> V_86 ) ;
F_32 ( & V_59 -> V_87 ) ;
F_6 ( & V_59 -> V_81 , V_79 ) ;
}
static int F_33 ( struct V_17 * V_18 , struct V_75 * V_75 ,
T_3 V_88 )
{
struct V_89 * V_76 = & V_75 -> V_76 -> V_76 ;
int V_90 = 0 ;
unsigned long V_7 ;
struct V_72 * V_59 ;
F_34 ( L_33 ,
V_18 , V_75 , V_88 ) ;
F_35 ( ! V_75 -> V_91 && V_75 -> V_92 ) ;
F_5 ( & V_8 -> V_9 , V_7 ) ;
if ( V_75 -> V_1 != - V_93 ) {
F_27 ( V_76 , L_34 , V_75 -> V_1 ) ;
F_6 ( & V_8 -> V_9 , V_7 ) ;
return V_75 -> V_1 ;
}
V_59 = F_24 ( V_75 -> V_76 -> V_94 - 1 ) ;
F_36 ( & V_59 -> V_67 . V_9 ) ;
if ( V_59 -> V_67 . V_1 == V_95 ||
V_59 -> V_67 . V_1 == V_96 ) {
F_27 ( V_76 , L_35 , V_59 -> V_4 ) ;
F_37 ( & V_59 -> V_67 . V_9 ) ;
F_6 ( & V_8 -> V_9 , V_7 ) ;
return - V_97 ;
}
F_37 ( & V_59 -> V_67 . V_9 ) ;
V_90 = F_38 ( V_18 , V_75 ) ;
if ( V_90 )
goto V_98;
if ( F_39 ( V_75 -> V_99 ) == 0 ) {
V_48 type = F_40 ( V_75 -> V_99 ) ;
struct V_100 * V_101 =
(struct V_100 * ) V_75 -> V_102 ;
if ( type != V_103 || ! V_101 ) {
F_27 ( V_76 , L_36 ) ;
V_90 = - V_104 ;
goto V_105;
}
switch ( V_101 -> V_106 ) {
case V_107 :
F_30 ( V_76 , L_37 ,
V_101 -> V_42 , V_59 -> V_4 ) ;
if ( V_59 -> V_74 )
F_41 ( V_59 -> V_74 ) ;
V_59 -> V_74 = F_42 ( V_75 -> V_76 ) ;
F_36 ( & V_59 -> V_67 . V_9 ) ;
V_59 -> V_67 . V_1 = V_108 ;
F_37 ( & V_59 -> V_67 . V_9 ) ;
if ( V_75 -> V_1 == - V_93 ) {
V_75 -> V_1 = 0 ;
}
goto V_105;
case V_109 :
if ( V_101 -> V_42 == ( V_110 << 8 ) )
F_34 ( L_38
L_39
L_40 ) ;
if ( V_59 -> V_74 )
F_41 ( V_59 -> V_74 ) ;
V_59 -> V_74 = F_42 ( V_75 -> V_76 ) ;
goto V_111;
default:
F_27 ( V_76 , L_41
L_42 , V_101 -> V_106 ,
V_101 -> V_42 ) ;
V_90 = - V_104 ;
goto V_105;
}
}
V_111:
F_25 ( V_75 ) ;
F_6 ( & V_8 -> V_9 , V_7 ) ;
return 0 ;
V_105:
F_43 ( V_18 , V_75 ) ;
V_98:
F_6 ( & V_8 -> V_9 , V_7 ) ;
F_44 ( F_8 ( V_8 ) , V_75 , V_75 -> V_1 ) ;
return V_90 ;
}
static int F_45 ( struct V_17 * V_18 , struct V_75 * V_75 , int V_1 )
{
unsigned long V_7 ;
struct V_77 * V_78 ;
struct V_72 * V_59 ;
F_13 ( L_43 , V_75 ) ;
F_5 ( & V_8 -> V_9 , V_7 ) ;
V_78 = V_75 -> V_84 ;
if ( ! V_78 ) {
F_6 ( & V_8 -> V_9 , V_7 ) ;
return 0 ;
}
{
int V_90 = 0 ;
V_90 = F_46 ( V_18 , V_75 , V_1 ) ;
if ( V_90 ) {
F_6 ( & V_8 -> V_9 , V_7 ) ;
return V_90 ;
}
}
V_59 = V_78 -> V_59 ;
if ( ! V_59 -> V_67 . V_112 ) {
unsigned long V_113 ;
F_5 ( & V_59 -> V_81 , V_113 ) ;
F_13 ( L_44 , V_59 ) ;
F_47 ( & V_78 -> V_85 ) ;
F_48 ( V_78 ) ;
V_75 -> V_84 = NULL ;
F_6 ( & V_59 -> V_81 , V_113 ) ;
F_13 ( L_45 , V_75 ) ;
F_43 ( V_18 , V_75 ) ;
F_6 ( & V_8 -> V_9 , V_7 ) ;
F_44 ( F_8 ( V_8 ) , V_75 ,
V_75 -> V_1 ) ;
F_5 ( & V_8 -> V_9 , V_7 ) ;
} else {
unsigned long V_113 ;
struct V_114 * V_115 ;
F_5 ( & V_59 -> V_81 , V_113 ) ;
V_115 = F_26 ( sizeof( struct V_114 ) , V_80 ) ;
if ( ! V_115 ) {
F_18 ( L_46 ) ;
F_6 ( & V_59 -> V_81 , V_113 ) ;
F_6 ( & V_8 -> V_9 , V_7 ) ;
F_28 ( & V_59 -> V_67 , V_82 ) ;
return - V_116 ;
}
V_115 -> V_83 = F_29 ( & V_8 -> V_83 ) ;
if ( V_115 -> V_83 == 0xffff )
F_13 ( L_32 ) ;
V_115 -> V_117 = V_78 -> V_83 ;
F_13 ( L_47 , V_59 ) ;
F_31 ( & V_115 -> V_85 , & V_59 -> V_118 ) ;
F_32 ( & V_59 -> V_87 ) ;
F_6 ( & V_59 -> V_81 , V_113 ) ;
}
F_6 ( & V_8 -> V_9 , V_7 ) ;
F_34 ( L_48 ) ;
return 0 ;
}
static void F_49 ( struct V_72 * V_59 )
{
struct V_114 * V_115 , * V_119 ;
F_36 ( & V_59 -> V_81 ) ;
F_50 (unlink, tmp, &vdev->unlink_tx, list) {
F_13 ( L_49 , V_115 -> V_117 ) ;
F_47 ( & V_115 -> V_85 ) ;
F_48 ( V_115 ) ;
}
F_50 (unlink, tmp, &vdev->unlink_rx, list) {
struct V_75 * V_75 ;
F_13 ( L_50 , V_115 -> V_117 ) ;
V_75 = F_51 ( V_59 , V_115 -> V_117 ) ;
if ( ! V_75 ) {
F_13 ( L_51 ,
V_115 -> V_117 ) ;
F_47 ( & V_115 -> V_85 ) ;
F_48 ( V_115 ) ;
continue;
}
V_75 -> V_1 = - V_97 ;
F_36 ( & V_8 -> V_9 ) ;
F_43 ( F_8 ( V_8 ) , V_75 ) ;
F_37 ( & V_8 -> V_9 ) ;
F_44 ( F_8 ( V_8 ) , V_75 ,
V_75 -> V_1 ) ;
F_47 ( & V_115 -> V_85 ) ;
F_48 ( V_115 ) ;
}
F_37 ( & V_59 -> V_81 ) ;
}
static void F_52 ( struct V_120 * V_67 )
{
struct V_72 * V_59 = F_53 ( V_67 , struct V_72 , V_67 ) ;
if ( V_67 -> V_112 ) {
F_2 ( L_52 , V_67 -> V_112 ) ;
F_54 ( V_67 -> V_112 , V_121 ) ;
}
if ( V_59 -> V_67 . V_122 )
F_55 ( V_59 -> V_67 . V_122 ) ;
if ( V_59 -> V_67 . V_123 )
F_55 ( V_59 -> V_67 . V_123 ) ;
F_13 ( L_53 ) ;
if ( V_59 -> V_67 . V_112 != NULL ) {
F_56 ( V_59 -> V_67 . V_112 ) ;
V_59 -> V_67 . V_112 = NULL ;
}
F_13 ( L_54 ) ;
F_49 ( V_59 ) ;
F_9 ( V_59 -> V_4 ) ;
F_13 ( L_55 ) ;
}
static void F_57 ( struct V_120 * V_67 )
{
struct V_72 * V_59 = F_53 ( V_67 , struct V_72 , V_67 ) ;
F_36 ( & V_67 -> V_9 ) ;
V_59 -> V_6 = 0 ;
V_59 -> V_124 = 0 ;
if ( V_59 -> V_74 )
F_41 ( V_59 -> V_74 ) ;
V_59 -> V_74 = NULL ;
V_67 -> V_112 = NULL ;
V_67 -> V_1 = V_95 ;
F_37 ( & V_67 -> V_9 ) ;
}
static void F_58 ( struct V_120 * V_67 )
{
F_36 ( & V_67 -> V_9 ) ;
V_67 -> V_1 = V_96 ;
F_37 ( & V_67 -> V_9 ) ;
}
static void F_59 ( struct V_72 * V_59 )
{
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_67 . V_125 = V_126 ;
V_59 -> V_67 . V_1 = V_95 ;
F_60 ( & V_59 -> V_67 . V_9 ) ;
F_61 ( & V_59 -> V_127 ) ;
F_61 ( & V_59 -> V_86 ) ;
F_61 ( & V_59 -> V_118 ) ;
F_61 ( & V_59 -> V_128 ) ;
F_60 ( & V_59 -> V_81 ) ;
F_62 ( & V_59 -> V_87 ) ;
V_59 -> V_67 . V_129 . V_130 = F_52 ;
V_59 -> V_67 . V_129 . V_131 = F_57 ;
V_59 -> V_67 . V_129 . V_132 = F_58 ;
F_63 ( & V_59 -> V_67 ) ;
}
static int F_64 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = F_11 ( V_18 ) ;
int V_4 ;
int V_133 = 0 ;
F_34 ( L_56 ) ;
for ( V_4 = 0 ; V_4 < V_26 ; V_4 ++ ) {
struct V_72 * V_59 = & V_21 -> V_59 [ V_4 ] ;
F_59 ( V_59 ) ;
V_59 -> V_4 = V_4 ;
}
F_65 ( & V_21 -> V_83 , 0 ) ;
F_60 ( & V_21 -> V_9 ) ;
V_18 -> V_134 = 0 ;
V_18 -> V_28 = V_135 ;
V_18 -> V_136 = 1 ;
V_133 = F_66 ( & F_67 ( V_21 ) -> V_137 , & V_138 ) ;
if ( V_133 ) {
F_18 ( L_57 ) ;
return V_133 ;
}
return 0 ;
}
static void F_68 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = F_11 ( V_18 ) ;
int V_4 = 0 ;
F_34 ( L_58 ) ;
F_69 ( & F_67 ( V_21 ) -> V_137 , & V_138 ) ;
for ( V_4 = 0 ; V_4 < V_26 ; V_4 ++ ) {
struct V_72 * V_59 = & V_21 -> V_59 [ V_4 ] ;
F_28 ( & V_59 -> V_67 , V_139 ) ;
F_70 ( & V_59 -> V_67 ) ;
}
}
static int F_71 ( struct V_17 * V_18 )
{
F_18 ( L_59 ) ;
return 0 ;
}
static int F_72 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = F_11 ( V_18 ) ;
F_73 ( & V_18 -> V_140 . V_141 -> V_76 , L_60 , V_142 ) ;
F_74 ( & V_21 -> V_9 ) ;
V_18 -> V_28 = V_29 ;
F_75 ( & V_21 -> V_9 ) ;
return 0 ;
}
static int F_76 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = F_11 ( V_18 ) ;
int V_143 = 0 ;
F_73 ( & V_18 -> V_140 . V_141 -> V_76 , L_60 , V_142 ) ;
F_74 ( & V_21 -> V_9 ) ;
if ( ! F_12 ( V_18 ) ) {
V_143 = - V_144 ;
} else {
V_18 -> V_28 = V_135 ;
}
F_75 ( & V_21 -> V_9 ) ;
return V_143 ;
return 0 ;
}
static int F_77 ( struct V_145 * V_146 )
{
struct V_17 * V_18 ;
int V_90 ;
F_34 ( L_61 , V_146 -> V_147 , V_146 -> V_148 ) ;
if ( V_146 -> V_76 . V_149 ) {
F_30 ( & V_146 -> V_76 , L_62 ) ;
return - V_104 ;
}
V_18 = F_78 ( & V_150 , & V_146 -> V_76 , F_79 ( & V_146 -> V_76 ) ) ;
if ( ! V_18 ) {
F_18 ( L_63 ) ;
return - V_116 ;
}
V_18 -> V_151 = 1 ;
V_8 = F_11 ( V_18 ) ;
V_90 = F_80 ( V_18 , 0 , 0 ) ;
if ( V_90 != 0 ) {
F_18 ( L_64 , V_90 ) ;
F_81 ( V_18 ) ;
V_8 = NULL ;
return V_90 ;
}
F_34 ( L_65 ) ;
return 0 ;
}
static int F_82 ( struct V_145 * V_146 )
{
struct V_17 * V_18 ;
V_18 = F_83 ( V_146 ) ;
if ( ! V_18 )
return 0 ;
F_84 ( V_18 ) ;
F_81 ( V_18 ) ;
V_8 = NULL ;
return 0 ;
}
static int F_85 ( struct V_145 * V_146 , T_4 V_28 )
{
struct V_17 * V_18 ;
int V_4 = 0 ;
int V_152 = 0 ;
int V_90 = 0 ;
V_18 = F_83 ( V_146 ) ;
F_36 ( & V_8 -> V_9 ) ;
for ( V_4 = 0 ; V_4 < V_26 ; V_4 ++ )
if ( V_8 -> V_10 [ V_4 ] &
V_11 )
V_152 += 1 ;
F_37 ( & V_8 -> V_9 ) ;
if ( V_152 > 0 ) {
F_30 ( & V_146 -> V_76 , L_66
L_67 , V_152 , ( V_152 == 1 ? L_68 : L_69 ) ) ;
V_90 = - V_153 ;
} else {
F_30 ( & V_146 -> V_76 , L_70 ) ;
F_86 ( V_154 , & V_18 -> V_7 ) ;
}
return V_90 ;
}
static int F_87 ( struct V_145 * V_146 )
{
struct V_17 * V_18 ;
F_73 ( & V_146 -> V_76 , L_60 , V_142 ) ;
V_18 = F_83 ( V_146 ) ;
F_88 ( V_154 , & V_18 -> V_7 ) ;
F_7 ( V_18 ) ;
return 0 ;
}
static void F_89 ( struct V_89 * V_76 )
{
return;
}
static int T_5 F_90 ( void )
{
int V_90 ;
if ( F_91 () )
return - V_97 ;
V_90 = F_92 ( & V_155 ) ;
if ( V_90 < 0 )
goto V_156;
V_90 = F_93 ( & V_157 ) ;
if ( V_90 < 0 )
goto V_158;
F_13 ( V_159 L_71 V_160 L_3 ) ;
return V_90 ;
V_158:
F_94 ( & V_155 ) ;
V_156:
return V_90 ;
}
static void T_6 F_95 ( void )
{
F_96 ( & V_157 ) ;
F_94 ( & V_155 ) ;
}
