static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3
( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_8 ) ;
}
static inline struct V_9 * F_4 ( struct V_10 * V_11 )
{
return (struct V_9 * ) ( V_11 -> V_12 ) ;
}
static inline struct V_10 * F_5 ( struct V_9 * V_13 )
{
return F_2 ( ( void * ) V_13 , struct V_10 , V_12 ) ;
}
static inline struct V_14 * F_6 ( struct V_9 * V_13 )
{
return F_5 ( V_13 ) -> V_15 . V_16 ;
}
static inline struct V_14 * F_7 ( struct V_17 * V_13 )
{
return V_13 -> V_18 . V_19 . V_20 ;
}
static inline struct V_17 * F_8 ( struct V_1 * V_4 )
{
return F_2 ( V_4 -> V_18 , struct V_17 , V_18 ) ;
}
static inline struct V_9 * F_9 ( struct V_21 * V_18 )
{
struct V_17 * V_13 = F_2 ( V_18 , struct V_17 , V_18 ) ;
if ( V_13 -> V_18 . V_22 == V_23 )
return V_13 -> V_24 ;
else
return V_13 -> V_25 ;
}
static inline struct V_17 * F_10 ( struct V_14 * V_19 )
{
return F_2 ( V_19 , struct V_17 , V_18 . V_19 ) ;
}
static void F_11 ( struct V_17 * V_13 , struct V_1 * V_4 )
{
while ( ! F_12 ( & V_4 -> V_26 ) ) {
struct V_5 * V_8 ;
V_8 = F_13 ( V_4 -> V_26 . V_27 , struct V_5 , V_26 ) ;
F_14 ( & V_8 -> V_26 ) ;
V_8 -> V_8 . V_28 = - V_29 ;
F_15 ( & V_13 -> V_30 ) ;
V_8 -> V_8 . V_31 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_16 ( & V_13 -> V_30 ) ;
}
}
static void F_17 ( struct V_17 * V_13 )
{
struct V_1 * V_4 ;
V_13 -> V_32 = 0 ;
F_18 (ep, &dum->gadget.ep_list, ep.ep_list)
F_11 ( V_13 , V_4 ) ;
}
static void F_19 ( struct V_9 * V_33 )
{
struct V_17 * V_13 = V_33 -> V_13 ;
if ( F_5 ( V_33 ) -> V_22 == V_34 ) {
if ( ( V_33 -> V_35 & V_36 ) == 0 ) {
V_33 -> V_35 = 0 ;
} else if ( ! V_13 -> V_37 || V_13 -> V_38 ) {
V_33 -> V_35 &= ~ ( V_39 |
V_40 ) ;
if ( ( V_33 -> V_41 &
V_39 ) != 0 )
V_33 -> V_35 |=
( V_42 << 16 ) ;
} else {
V_33 -> V_35 |= ( V_39 |
V_43 ) ;
if ( ( V_33 -> V_41 &
V_39 ) == 0 )
V_33 -> V_35 |=
( V_42 << 16 ) ;
if ( ( V_33 -> V_35 &
V_40 ) == 1 &&
( V_33 -> V_35 &
V_44 ) == 1 &&
V_33 -> V_45 != V_46 )
V_33 -> V_47 = 1 ;
}
} else {
if ( ( V_33 -> V_35 & V_48 ) == 0 ) {
V_33 -> V_35 = 0 ;
} else if ( ! V_13 -> V_37 || V_13 -> V_38 ) {
V_33 -> V_35 &= ~ ( V_39 |
V_40 |
V_49 |
V_50 |
V_51 ) ;
if ( ( V_33 -> V_41 &
V_39 ) != 0 )
V_33 -> V_35 |=
( V_42 << 16 ) ;
} else {
V_33 -> V_35 |= V_39 ;
if ( ( V_33 -> V_41 &
V_39 ) == 0 )
V_33 -> V_35 |=
( V_42 << 16 ) ;
if ( ( V_33 -> V_35 & V_40 ) == 0 )
V_33 -> V_35 &= ~ V_51 ;
else if ( ( V_33 -> V_35 &
V_51 ) == 0 &&
V_33 -> V_45 != V_46 )
V_33 -> V_47 = 1 ;
}
}
}
static void F_20 ( struct V_9 * V_33 )
{
struct V_17 * V_13 = V_33 -> V_13 ;
V_33 -> V_47 = 0 ;
if ( V_13 -> V_37 )
if ( ( F_5 ( V_33 ) -> V_22 == V_34 &&
V_13 -> V_18 . V_22 != V_23 ) ||
( F_5 ( V_33 ) -> V_22 != V_34 &&
V_13 -> V_18 . V_22 == V_23 ) )
return;
F_19 ( V_33 ) ;
if ( ( V_33 -> V_35 & V_40 ) == 0 ||
V_33 -> V_47 )
V_33 -> V_52 = 0 ;
if ( ( V_33 -> V_35 & V_39 ) == 0 ||
( V_33 -> V_35 & V_53 ) != 0 ) {
if ( ( V_33 -> V_41 & V_39 ) != 0 &&
( V_33 -> V_41 & V_53 ) == 0 &&
V_13 -> V_54 ) {
F_17 ( V_13 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_13 -> V_54 -> V_55 ( & V_13 -> V_18 ) ;
F_16 ( & V_13 -> V_30 ) ;
}
} else if ( V_33 -> V_47 != V_33 -> V_56 ) {
if ( V_33 -> V_56 && V_13 -> V_54 -> V_57 ) {
F_15 ( & V_13 -> V_30 ) ;
V_13 -> V_54 -> V_57 ( & V_13 -> V_18 ) ;
F_16 ( & V_13 -> V_30 ) ;
} else if ( ! V_33 -> V_56 && V_13 -> V_54 -> V_58 ) {
F_15 ( & V_13 -> V_30 ) ;
V_13 -> V_54 -> V_58 ( & V_13 -> V_18 ) ;
F_16 ( & V_13 -> V_30 ) ;
}
}
V_33 -> V_41 = V_33 -> V_35 ;
V_33 -> V_56 = V_33 -> V_47 ;
}
static int F_21 ( struct V_2 * V_3 ,
const struct V_59 * V_60 )
{
struct V_17 * V_13 ;
struct V_9 * V_33 ;
struct V_1 * V_4 ;
unsigned V_61 ;
int V_62 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_60 || V_4 -> V_60 || V_3 -> V_63 == V_64
|| V_60 -> V_65 != V_66 )
return - V_67 ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_54 )
return - V_29 ;
V_33 = F_9 ( & V_13 -> V_18 ) ;
if ( ! F_22 ( V_33 ) )
return - V_29 ;
V_61 = F_23 ( V_60 ) & 0x7ff ;
V_62 = - V_67 ;
switch ( F_24 ( V_60 ) ) {
case V_68 :
if ( strstr ( V_4 -> V_4 . V_63 , L_1 )
|| strstr ( V_4 -> V_4 . V_63 , L_2 ) ) {
goto V_69;
}
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
if ( V_61 == 1024 )
break;
goto V_69;
case V_70 :
if ( V_61 == 512 )
break;
goto V_69;
case V_71 :
if ( V_61 == 8 || V_61 == 16 || V_61 == 32 || V_61 == 64 )
break;
default:
goto V_69;
}
break;
case V_72 :
if ( strstr ( V_4 -> V_4 . V_63 , L_1 ) )
goto V_69;
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
case V_70 :
if ( V_61 <= 1024 )
break;
case V_71 :
if ( V_61 <= 64 )
break;
default:
if ( V_61 <= 8 )
break;
goto V_69;
}
break;
case V_73 :
if ( strstr ( V_4 -> V_4 . V_63 , L_3 )
|| strstr ( V_4 -> V_4 . V_63 , L_2 ) )
goto V_69;
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
case V_70 :
if ( V_61 <= 1024 )
break;
case V_71 :
if ( V_61 <= 1023 )
break;
default:
goto V_69;
}
break;
default:
goto V_69;
}
V_3 -> V_74 = V_61 ;
if ( F_25 ( V_3 -> V_75 ) ) {
if ( ! F_26 ( V_60 ) ) {
F_27 ( F_7 ( V_13 ) , L_4
L_5 , V_3 -> V_63 ) ;
return - V_67 ;
}
V_4 -> V_76 = 1 ;
}
V_4 -> V_60 = V_60 ;
F_28 (udc_dev(dum), L_6 ,
_ep->name,
desc->bEndpointAddress & 0x0f ,
(desc->bEndpointAddress & USB_DIR_IN) ? L_7 : L_8 ,
({ char *val;
switch (usb_endpoint_type(desc)) {
case USB_ENDPOINT_XFER_BULK:
val = L_9;
break;
case USB_ENDPOINT_XFER_ISOC:
val = L_10;
break;
case USB_ENDPOINT_XFER_INT:
val = L_11;
break;
default:
val = L_12;
break;
}; val; }),
max, ep->stream_en ? L_13 : L_14 ) ;
V_4 -> V_77 = V_4 -> V_78 = 0 ;
V_62 = 0 ;
V_69:
return V_62 ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
unsigned long V_79 ;
int V_62 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_4 -> V_60 || V_3 -> V_63 == V_64 )
return - V_67 ;
V_13 = F_8 ( V_4 ) ;
F_30 ( & V_13 -> V_30 , V_79 ) ;
V_4 -> V_60 = NULL ;
V_4 -> V_76 = 0 ;
V_62 = 0 ;
F_11 ( V_13 , V_4 ) ;
F_31 ( & V_13 -> V_30 , V_79 ) ;
F_28 ( F_7 ( V_13 ) , L_15 , V_3 -> V_63 ) ;
return V_62 ;
}
static struct V_6 * F_32 ( struct V_2 * V_3 ,
T_1 V_80 )
{
struct V_1 * V_4 ;
struct V_5 * V_8 ;
if ( ! V_3 )
return NULL ;
V_4 = F_1 ( V_3 ) ;
V_8 = F_33 ( sizeof( * V_8 ) , V_80 ) ;
if ( ! V_8 )
return NULL ;
F_34 ( & V_8 -> V_26 ) ;
return & V_8 -> V_8 ;
}
static void F_35 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_5 * V_8 ;
if ( ! V_3 || ! V_7 ) {
F_36 ( 1 ) ;
return;
}
V_8 = F_3 ( V_7 ) ;
F_36 ( ! F_12 ( & V_8 -> V_26 ) ) ;
F_37 ( V_8 ) ;
}
static void F_38 ( struct V_2 * V_4 , struct V_6 * V_8 )
{
}
static int F_39 ( struct V_2 * V_3 , struct V_6 * V_7 ,
T_1 V_80 )
{
struct V_1 * V_4 ;
struct V_5 * V_8 ;
struct V_17 * V_13 ;
struct V_9 * V_33 ;
unsigned long V_79 ;
V_8 = F_3 ( V_7 ) ;
if ( ! V_7 || ! F_12 ( & V_8 -> V_26 ) || ! V_7 -> V_31 )
return - V_67 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ( ! V_4 -> V_60 && V_3 -> V_63 != V_64 ) )
return - V_67 ;
V_13 = F_8 ( V_4 ) ;
V_33 = F_9 ( & V_13 -> V_18 ) ;
if ( ! V_13 -> V_54 || ! F_22 ( V_33 ) )
return - V_29 ;
#if 0
dev_dbg(udc_dev(dum), "ep %p queue req %p to %s, len %d buf %p\n",
ep, _req, _ep->name, _req->length, _req->buf);
#endif
V_7 -> V_28 = - V_81 ;
V_7 -> V_82 = 0 ;
F_30 ( & V_13 -> V_30 , V_79 ) ;
if ( V_4 -> V_60 && ( V_4 -> V_60 -> V_83 & V_84 ) &&
F_12 ( & V_13 -> V_85 . V_26 ) &&
F_12 ( & V_4 -> V_26 ) &&
V_7 -> V_86 <= V_87 ) {
V_8 = & V_13 -> V_85 ;
V_8 -> V_8 = * V_7 ;
V_8 -> V_8 . V_88 = V_13 -> V_89 ;
memcpy ( V_13 -> V_89 , V_7 -> V_88 , V_7 -> V_86 ) ;
V_8 -> V_8 . V_90 = V_13 ;
V_8 -> V_8 . V_31 = F_38 ;
F_40 ( & V_8 -> V_26 , & V_4 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_7 -> V_82 = V_7 -> V_86 ;
V_7 -> V_28 = 0 ;
V_7 -> V_31 ( V_3 , V_7 ) ;
F_16 ( & V_13 -> V_30 ) ;
} else
F_40 ( & V_8 -> V_26 , & V_4 -> V_26 ) ;
F_31 ( & V_13 -> V_30 , V_79 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
int V_62 = - V_67 ;
unsigned long V_79 ;
struct V_5 * V_8 = NULL ;
if ( ! V_3 || ! V_7 )
return V_62 ;
V_4 = F_1 ( V_3 ) ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_54 )
return - V_29 ;
F_42 ( V_79 ) ;
F_16 ( & V_13 -> V_30 ) ;
F_18 (req, &ep->queue, queue) {
if ( & V_8 -> V_8 == V_7 ) {
F_14 ( & V_8 -> V_26 ) ;
V_7 -> V_28 = - V_91 ;
V_62 = 0 ;
break;
}
}
F_15 ( & V_13 -> V_30 ) ;
if ( V_62 == 0 ) {
F_28 ( F_7 ( V_13 ) ,
L_16 ,
V_8 , V_3 -> V_63 , V_7 -> V_86 , V_7 -> V_88 ) ;
V_7 -> V_31 ( V_3 , V_7 ) ;
}
F_43 ( V_79 ) ;
return V_62 ;
}
static int
F_44 ( struct V_2 * V_3 , int V_92 , int V_78 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
if ( ! V_3 )
return - V_67 ;
V_4 = F_1 ( V_3 ) ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_54 )
return - V_29 ;
if ( ! V_92 )
V_4 -> V_77 = V_4 -> V_78 = 0 ;
else if ( V_4 -> V_60 && ( V_4 -> V_60 -> V_83 & V_84 ) &&
! F_12 ( & V_4 -> V_26 ) )
return - V_93 ;
else {
V_4 -> V_77 = 1 ;
if ( V_78 )
V_4 -> V_78 = 1 ;
}
return 0 ;
}
static int
F_45 ( struct V_2 * V_3 , int V_92 )
{
return F_44 ( V_3 , V_92 , 0 ) ;
}
static int F_46 ( struct V_2 * V_3 )
{
if ( ! V_3 || V_3 -> V_63 == V_64 )
return - V_67 ;
return F_44 ( V_3 , 1 , 1 ) ;
}
static int F_47 ( struct V_21 * V_94 )
{
struct V_95 V_96 ;
F_48 ( & V_96 ) ;
return V_96 . V_97 / 1000 ;
}
static int F_49 ( struct V_21 * V_94 )
{
struct V_9 * V_33 ;
V_33 = F_9 ( V_94 ) ;
if ( ! ( V_33 -> V_13 -> V_98 & ( ( 1 << V_99 )
| ( 1 << V_100 ) ) ) )
return - V_67 ;
if ( ( V_33 -> V_35 & V_39 ) == 0 )
return - V_101 ;
if ( ( V_33 -> V_35 & V_51 ) == 0 &&
V_33 -> V_45 != V_46 )
return - V_102 ;
V_33 -> V_52 = 1 ;
V_33 -> V_103 = V_104 + F_50 ( 20 ) ;
F_51 ( & F_5 ( V_33 ) -> V_105 , V_33 -> V_103 ) ;
return 0 ;
}
static int F_52 ( struct V_21 * V_94 , int V_92 )
{
struct V_17 * V_13 ;
V_13 = F_9 ( V_94 ) -> V_13 ;
if ( V_92 )
V_13 -> V_98 |= ( 1 << V_106 ) ;
else
V_13 -> V_98 &= ~ ( 1 << V_106 ) ;
return 0 ;
}
static void F_53 ( struct V_17 * V_13 )
{
if ( V_13 -> V_18 . V_22 == V_23 )
V_13 -> V_4 [ 0 ] . V_4 . V_74 = 9 ;
else
V_13 -> V_4 [ 0 ] . V_4 . V_74 = 64 ;
}
static int F_54 ( struct V_21 * V_94 , int V_92 )
{
struct V_9 * V_33 ;
struct V_17 * V_13 ;
unsigned long V_79 ;
V_13 = F_10 ( & V_94 -> V_19 ) ;
if ( V_92 && V_13 -> V_54 ) {
if ( V_107 . V_108 )
V_13 -> V_18 . V_22 = V_13 -> V_54 -> V_109 ;
else if ( V_107 . V_110 )
V_13 -> V_18 . V_22 = F_55 ( V_111 , V_70 ,
V_13 -> V_54 -> V_109 ) ;
else
V_13 -> V_18 . V_22 = V_71 ;
F_53 ( V_13 ) ;
if ( V_13 -> V_18 . V_22 < V_13 -> V_54 -> V_109 )
F_28 ( F_7 ( V_13 ) , L_17
L_18 ,
F_56 ( V_13 -> V_54 -> V_109 ) ) ;
}
V_33 = F_9 ( V_94 ) ;
F_30 ( & V_13 -> V_30 , V_79 ) ;
V_13 -> V_37 = ( V_92 != 0 ) ;
F_20 ( V_33 ) ;
F_31 ( & V_13 -> V_30 , V_79 ) ;
F_57 ( F_5 ( V_33 ) ) ;
return 0 ;
}
static T_2 F_58 ( struct V_14 * V_19 , struct V_112 * V_113 ,
char * V_88 )
{
struct V_17 * V_13 = F_10 ( V_19 ) ;
if ( ! V_13 -> V_54 || ! V_13 -> V_54 -> V_114 )
return 0 ;
return F_59 ( V_88 , V_115 , L_19 , V_13 -> V_54 -> V_114 ) ;
}
static int F_60 ( struct V_21 * V_116 ,
struct V_117 * V_54 )
{
struct V_9 * V_33 = F_9 ( V_116 ) ;
struct V_17 * V_13 = V_33 -> V_13 ;
if ( V_54 -> V_109 == V_118 )
return - V_67 ;
V_13 -> V_98 = 0 ;
V_13 -> V_54 = V_54 ;
V_13 -> V_18 . V_19 . V_54 = & V_54 -> V_54 ;
F_28 ( F_7 ( V_13 ) , L_20 ,
V_54 -> V_54 . V_63 ) ;
return 0 ;
}
static int F_61 ( struct V_21 * V_116 ,
struct V_117 * V_54 )
{
struct V_9 * V_33 = F_9 ( V_116 ) ;
struct V_17 * V_13 = V_33 -> V_13 ;
F_28 ( F_7 ( V_13 ) , L_21 ,
V_54 -> V_54 . V_63 ) ;
V_13 -> V_18 . V_19 . V_54 = NULL ;
V_13 -> V_54 = NULL ;
return 0 ;
}
static void F_62 ( struct V_14 * V_19 )
{
return;
}
static void F_63 ( struct V_17 * V_13 )
{
int V_119 ;
F_34 ( & V_13 -> V_18 . V_120 ) ;
for ( V_119 = 0 ; V_119 < V_121 ; V_119 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_119 ] ;
if ( ! V_122 [ V_119 ] )
break;
V_4 -> V_4 . V_63 = V_122 [ V_119 ] ;
V_4 -> V_4 . V_123 = & V_124 ;
F_40 ( & V_4 -> V_4 . V_120 , & V_13 -> V_18 . V_120 ) ;
V_4 -> V_77 = V_4 -> V_78 = V_4 -> V_125 =
V_4 -> V_126 = 0 ;
V_4 -> V_4 . V_74 = ~ 0 ;
V_4 -> V_4 . V_127 = 16 ;
V_4 -> V_128 = V_104 ;
V_4 -> V_18 = & V_13 -> V_18 ;
V_4 -> V_60 = NULL ;
F_34 ( & V_4 -> V_26 ) ;
}
V_13 -> V_18 . V_129 = & V_13 -> V_4 [ 0 ] . V_4 ;
F_14 ( & V_13 -> V_4 [ 0 ] . V_4 . V_120 ) ;
F_34 ( & V_13 -> V_85 . V_26 ) ;
#ifdef F_64
V_13 -> V_18 . V_130 = 1 ;
#endif
}
static int F_65 ( struct V_131 * V_132 )
{
struct V_17 * V_13 = & V_133 ;
int V_134 ;
V_13 -> V_18 . V_63 = V_135 ;
V_13 -> V_18 . V_123 = & V_136 ;
V_13 -> V_18 . V_109 = V_23 ;
F_66 ( & V_13 -> V_18 . V_19 , L_22 ) ;
V_13 -> V_18 . V_19 . V_20 = & V_132 -> V_19 ;
V_13 -> V_18 . V_19 . V_137 = F_62 ;
V_134 = F_67 ( & V_13 -> V_18 . V_19 ) ;
if ( V_134 < 0 ) {
F_68 ( & V_13 -> V_18 . V_19 ) ;
return V_134 ;
}
F_63 ( V_13 ) ;
V_134 = F_69 ( & V_132 -> V_19 , & V_13 -> V_18 ) ;
if ( V_134 < 0 )
goto V_138;
V_134 = F_70 ( & V_13 -> V_18 . V_19 , & V_139 ) ;
if ( V_134 < 0 )
goto V_140;
F_71 ( V_132 , V_13 ) ;
return V_134 ;
V_140:
F_72 ( & V_13 -> V_18 ) ;
V_138:
F_73 ( & V_13 -> V_18 . V_19 ) ;
return V_134 ;
}
static int F_74 ( struct V_131 * V_132 )
{
struct V_17 * V_13 = F_75 ( V_132 ) ;
F_72 ( & V_13 -> V_18 ) ;
F_71 ( V_132 , NULL ) ;
F_76 ( & V_13 -> V_18 . V_19 , & V_139 ) ;
F_73 ( & V_13 -> V_18 . V_19 ) ;
return 0 ;
}
static void F_77 ( struct V_17 * V_13 , struct V_9 * V_33 ,
int V_57 )
{
F_78 ( & V_13 -> V_30 ) ;
V_13 -> V_38 = V_57 ;
F_20 ( V_33 ) ;
F_79 ( & V_13 -> V_30 ) ;
}
static int F_80 ( struct V_131 * V_132 , T_3 V_141 )
{
struct V_17 * V_13 = F_75 ( V_132 ) ;
struct V_9 * V_33 = F_9 ( & V_13 -> V_18 ) ;
F_28 ( & V_132 -> V_19 , L_19 , V_142 ) ;
F_77 ( V_13 , V_33 , 1 ) ;
F_57 ( F_5 ( V_33 ) ) ;
return 0 ;
}
static int F_81 ( struct V_131 * V_132 )
{
struct V_17 * V_13 = F_75 ( V_132 ) ;
struct V_9 * V_33 = F_9 ( & V_13 -> V_18 ) ;
F_28 ( & V_132 -> V_19 , L_19 , V_142 ) ;
F_77 ( V_13 , V_33 , 0 ) ;
F_57 ( F_5 ( V_33 ) ) ;
return 0 ;
}
static unsigned int F_82 ( const struct V_59 * V_60 )
{
unsigned int V_143 ;
V_143 = F_83 ( V_60 ) << 1 ;
if ( F_84 ( V_60 ) )
V_143 |= 1 ;
return V_143 ;
}
static int F_85 ( struct V_9 * V_33 , struct V_144 * V_144 )
{
const struct V_59 * V_60 = & V_144 -> V_4 -> V_60 ;
T_4 V_143 ;
if ( ! F_26 ( V_60 ) )
return 0 ;
V_143 = F_82 ( V_60 ) ;
return ( 1 << V_143 ) & V_33 -> V_145 ;
}
static int F_86 ( struct V_9 * V_33 ,
unsigned int V_146 )
{
int V_127 ;
V_127 = V_33 -> V_147 [ F_87 ( V_146 ) ] ;
if ( F_88 ( V_146 ) )
V_127 >>= 4 ;
else
V_127 &= 0xf ;
V_127 ++ ;
return V_127 ;
}
static void F_89 ( struct V_9 * V_33 ,
unsigned int V_146 , unsigned int V_148 )
{
int V_127 ;
V_148 -- ;
V_127 = V_33 -> V_147 [ F_87 ( V_146 ) ] ;
if ( F_88 ( V_146 ) ) {
V_148 <<= 4 ;
V_127 &= 0xf ;
} else {
V_127 &= 0xf0 ;
}
V_127 |= V_148 ;
V_33 -> V_147 [ F_87 ( V_146 ) ] = V_127 ;
}
static int F_90 ( struct V_9 * V_33 , struct V_144 * V_144 )
{
unsigned int V_127 ;
int V_149 ;
V_149 = F_85 ( V_33 , V_144 ) ;
if ( ! V_144 -> V_150 ) {
if ( V_149 )
return - V_67 ;
return 0 ;
}
if ( ! V_149 )
return - V_67 ;
V_127 = F_86 ( V_33 ,
F_87 ( V_144 -> V_146 ) ) ;
if ( V_144 -> V_150 > V_127 ) {
F_27 ( F_6 ( V_33 ) , L_23 ,
V_144 -> V_150 ) ;
F_91 () ;
return - V_67 ;
}
return 0 ;
}
static int F_92 (
struct V_10 * V_11 ,
struct V_144 * V_144 ,
T_1 V_80
) {
struct V_9 * V_33 ;
struct V_151 * V_151 ;
unsigned long V_79 ;
int V_134 ;
V_151 = F_93 ( sizeof *V_151 , V_80 ) ;
if ( ! V_151 )
return - V_152 ;
V_151 -> V_144 = V_144 ;
V_151 -> V_153 = 0 ;
V_33 = F_4 ( V_11 ) ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
V_134 = F_90 ( V_33 , V_144 ) ;
if ( V_134 ) {
F_37 ( V_151 ) ;
goto V_69;
}
V_134 = F_94 ( V_11 , V_144 ) ;
if ( V_134 ) {
F_37 ( V_151 ) ;
goto V_69;
}
if ( ! V_33 -> V_154 ) {
V_33 -> V_154 = V_144 -> V_19 ;
F_95 ( V_33 -> V_154 ) ;
} else if ( F_96 ( V_33 -> V_154 != V_144 -> V_19 ) )
F_27 ( F_6 ( V_33 ) , L_24 ) ;
F_40 ( & V_151 -> V_155 , & V_33 -> V_155 ) ;
V_144 -> V_156 = V_151 ;
if ( F_97 ( V_144 -> V_146 ) == V_157 )
V_144 -> V_158 = 1 ;
if ( ! F_98 ( & V_33 -> V_159 ) )
F_51 ( & V_33 -> V_159 , V_104 + 1 ) ;
V_69:
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_134 ;
}
static int F_99 ( struct V_10 * V_11 , struct V_144 * V_144 , int V_28 )
{
struct V_9 * V_33 ;
unsigned long V_79 ;
int V_134 ;
V_33 = F_4 ( V_11 ) ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
V_134 = F_100 ( V_11 , V_144 , V_28 ) ;
if ( ! V_134 && V_33 -> V_45 != V_160 &&
! F_12 ( & V_33 -> V_155 ) )
F_51 ( & V_33 -> V_159 , V_104 ) ;
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_134 ;
}
static int F_101 ( struct V_144 * V_144 , struct V_5 * V_8 ,
T_4 V_161 )
{
void * V_162 , * V_163 ;
struct V_151 * V_151 = V_144 -> V_156 ;
int V_164 ;
struct V_165 * V_166 = & V_151 -> V_166 ;
T_4 V_167 = 0 ;
T_4 V_168 ;
bool V_169 ;
V_164 = F_102 ( V_144 -> V_146 ) ;
V_163 = V_8 -> V_8 . V_88 + V_8 -> V_8 . V_82 ;
if ( ! V_144 -> V_170 ) {
V_162 = V_144 -> V_171 + V_144 -> V_172 ;
if ( V_164 )
memcpy ( V_162 , V_163 , V_161 ) ;
else
memcpy ( V_163 , V_162 , V_161 ) ;
return V_161 ;
}
if ( ! V_151 -> V_153 ) {
T_4 V_79 = V_173 ;
if ( V_164 )
V_79 |= V_174 ;
else
V_79 |= V_175 ;
F_103 ( V_166 , V_144 -> V_176 , V_144 -> V_170 , V_79 ) ;
V_151 -> V_153 = 1 ;
}
V_169 = F_104 ( V_166 ) ;
if ( V_169 == false ) {
F_105 ( 1 ) ;
return - V_67 ;
}
do {
V_162 = V_166 -> V_177 ;
V_168 = F_55 ( T_4 , V_161 , V_166 -> V_86 ) ;
V_166 -> V_178 = V_168 ;
V_167 += V_168 ;
if ( V_164 )
memcpy ( V_162 , V_163 , V_168 ) ;
else
memcpy ( V_163 , V_162 , V_168 ) ;
V_161 -= V_168 ;
if ( ! V_161 )
break;
V_169 = F_104 ( V_166 ) ;
if ( V_169 == false ) {
F_105 ( 1 ) ;
return - V_67 ;
}
V_163 += V_168 ;
} while ( 1 );
F_106 ( V_166 ) ;
return V_167 ;
}
static int F_107 ( struct V_9 * V_33 , struct V_144 * V_144 ,
struct V_1 * V_4 , int V_179 , int * V_28 )
{
struct V_17 * V_13 = V_33 -> V_13 ;
struct V_5 * V_8 ;
V_180:
F_18 (req, &ep->queue, queue) {
unsigned V_181 , V_182 , V_161 ;
int V_183 , V_164 ;
int V_184 = 0 ;
if ( F_85 ( V_33 , V_144 ) ) {
if ( ( V_144 -> V_150 != V_8 -> V_8 . V_150 ) )
continue;
}
V_181 = V_144 -> V_185 - V_144 -> V_172 ;
V_182 = V_8 -> V_8 . V_86 - V_8 -> V_8 . V_82 ;
V_161 = F_108 ( V_181 , V_182 ) ;
V_164 = F_102 ( V_144 -> V_146 ) ;
if ( F_96 ( V_161 == 0 ) )
V_183 = 1 ;
else {
if ( V_179 < V_4 -> V_4 . V_74 && V_179 < V_161 )
break;
V_161 = F_55 ( unsigned , V_161 , V_179 ) ;
if ( V_161 == 0 )
break;
if ( V_161 > V_4 -> V_4 . V_74 ) {
V_184 = 1 ;
V_161 -= ( V_161 % V_4 -> V_4 . V_74 ) ;
}
V_183 = ( V_161 % V_4 -> V_4 . V_74 ) != 0 ;
V_161 = F_101 ( V_144 , V_8 , V_161 ) ;
V_4 -> V_128 = V_104 ;
if ( ( int ) V_161 < 0 ) {
V_8 -> V_8 . V_28 = V_161 ;
} else {
V_179 -= V_161 ;
V_144 -> V_172 += V_161 ;
V_8 -> V_8 . V_82 += V_161 ;
}
}
if ( V_183 ) {
if ( V_181 == V_182 ) {
V_8 -> V_8 . V_28 = 0 ;
* V_28 = 0 ;
} else if ( V_164 ) {
V_8 -> V_8 . V_28 = 0 ;
if ( V_182 > V_181 )
* V_28 = - V_186 ;
else
* V_28 = 0 ;
} else if ( ! V_164 ) {
* V_28 = 0 ;
if ( V_181 > V_182 )
V_8 -> V_8 . V_28 = - V_186 ;
else
V_8 -> V_8 . V_28 = 0 ;
}
} else {
if ( V_8 -> V_8 . V_86 == V_8 -> V_8 . V_82
&& ! V_8 -> V_8 . V_187 )
V_8 -> V_8 . V_28 = 0 ;
if ( V_144 -> V_185 == V_144 -> V_172
&& ! ( V_144 -> V_188
& V_189 ) )
* V_28 = 0 ;
}
if ( V_8 -> V_8 . V_28 != - V_81 ) {
F_14 ( & V_8 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_8 -> V_8 . V_31 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_16 ( & V_13 -> V_30 ) ;
V_184 = 1 ;
}
if ( * V_28 != - V_81 )
break;
if ( V_184 )
goto V_180;
}
return V_179 ;
}
static int F_109 ( struct V_17 * V_13 , struct V_1 * V_4 )
{
int V_179 = V_4 -> V_4 . V_74 ;
if ( V_13 -> V_18 . V_22 == V_70 ) {
int V_190 ;
V_190 = F_23 ( V_4 -> V_60 ) ;
V_190 = ( V_190 >> 11 ) & 0x03 ;
V_190 *= 8 ;
V_179 += V_179 * V_190 ;
}
if ( V_13 -> V_18 . V_22 == V_23 ) {
switch ( F_24 ( V_4 -> V_60 ) ) {
case V_73 :
V_179 = 3 * 16 * 1024 * 8 ;
break;
case V_72 :
V_179 = 3 * 1024 * 8 ;
break;
case V_68 :
default:
break;
}
}
return V_179 ;
}
static struct V_1 * F_110 ( struct V_17 * V_13 , V_111 V_32 )
{
int V_119 ;
if ( ! F_111 ( ( V_13 -> V_18 . V_22 == V_23 ?
V_13 -> V_24 : V_13 -> V_25 ) ) )
return NULL ;
if ( ( V_32 & ~ V_84 ) == 0 )
return & V_13 -> V_4 [ 0 ] ;
for ( V_119 = 1 ; V_119 < V_121 ; V_119 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_119 ] ;
if ( ! V_4 -> V_60 )
continue;
if ( V_4 -> V_60 -> V_83 == V_32 )
return V_4 ;
}
return NULL ;
}
static int F_112 ( struct V_9 * V_33 , struct V_144 * V_144 ,
struct V_191 * V_192 ,
int * V_28 )
{
struct V_1 * V_193 ;
struct V_17 * V_13 = V_33 -> V_13 ;
int V_194 = 1 ;
unsigned V_195 ;
unsigned V_196 ;
V_195 = F_113 ( V_192 -> V_197 ) ;
V_196 = F_113 ( V_192 -> V_198 ) ;
switch ( V_192 -> V_199 ) {
case V_200 :
if ( V_192 -> V_201 != V_202 )
break;
V_13 -> V_32 = V_196 ;
* V_28 = 0 ;
F_28 ( F_7 ( V_13 ) , L_25 ,
V_196 ) ;
V_194 = 0 ;
break;
case V_203 :
if ( V_192 -> V_201 == V_202 ) {
V_194 = 0 ;
switch ( V_196 ) {
case V_100 :
break;
case V_99 :
V_13 -> V_18 . V_204 = 1 ;
break;
case V_205 :
V_13 -> V_18 . V_206 = 1 ;
break;
case V_207 :
V_13 -> V_18 . V_208 = 1 ;
break;
case V_209 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_196 = V_210 ;
else
V_194 = - V_211 ;
break;
case V_212 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_196 = V_213 ;
else
V_194 = - V_211 ;
break;
case V_214 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_196 = V_215 ;
else
V_194 = - V_211 ;
break;
default:
V_194 = - V_211 ;
}
if ( V_194 == 0 ) {
V_13 -> V_98 |= ( 1 << V_196 ) ;
* V_28 = 0 ;
}
} else if ( V_192 -> V_201 == V_216 ) {
V_193 = F_110 ( V_13 , V_195 ) ;
if ( ! V_193 || V_193 -> V_4 . V_63 == V_64 ) {
V_194 = - V_211 ;
break;
}
V_193 -> V_77 = 1 ;
V_194 = 0 ;
* V_28 = 0 ;
}
break;
case V_217 :
if ( V_192 -> V_201 == V_202 ) {
V_194 = 0 ;
switch ( V_196 ) {
case V_100 :
V_196 = V_100 ;
break;
case V_209 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_196 = V_210 ;
else
V_194 = - V_211 ;
break;
case V_212 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_196 = V_213 ;
else
V_194 = - V_211 ;
break;
case V_214 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_196 = V_215 ;
else
V_194 = - V_211 ;
break;
default:
V_194 = - V_211 ;
break;
}
if ( V_194 == 0 ) {
V_13 -> V_98 &= ~ ( 1 << V_196 ) ;
* V_28 = 0 ;
}
} else if ( V_192 -> V_201 == V_216 ) {
V_193 = F_110 ( V_13 , V_195 ) ;
if ( ! V_193 ) {
V_194 = - V_211 ;
break;
}
if ( ! V_193 -> V_78 )
V_193 -> V_77 = 0 ;
V_194 = 0 ;
* V_28 = 0 ;
}
break;
case V_218 :
if ( V_192 -> V_201 == V_219
|| V_192 -> V_201 == V_220
|| V_192 -> V_201 == V_221 ) {
char * V_88 ;
V_88 = ( char * ) V_144 -> V_171 ;
if ( V_144 -> V_185 > 0 ) {
if ( V_192 -> V_201 == V_221 ) {
V_193 = F_110 ( V_13 , V_195 ) ;
if ( ! V_193 ) {
V_194 = - V_211 ;
break;
}
V_88 [ 0 ] = V_193 -> V_77 ;
} else if ( V_192 -> V_201 ==
V_219 ) {
V_88 [ 0 ] = ( V_111 ) V_13 -> V_98 ;
} else
V_88 [ 0 ] = 0 ;
}
if ( V_144 -> V_185 > 1 )
V_88 [ 1 ] = 0 ;
V_144 -> V_172 = F_55 ( T_4 , 2 ,
V_144 -> V_185 ) ;
V_194 = 0 ;
* V_28 = 0 ;
}
break;
}
return V_194 ;
}
static void F_114 ( unsigned long V_222 )
{
struct V_9 * V_33 = (struct V_9 * ) V_222 ;
struct V_17 * V_13 = V_33 -> V_13 ;
struct V_151 * V_151 , * V_190 ;
unsigned long V_79 ;
int V_179 , V_223 ;
int V_119 ;
switch ( V_13 -> V_18 . V_22 ) {
case V_224 :
V_223 = 8 * 12 ;
break;
case V_71 :
V_223 = 64 * 19 ;
break;
case V_70 :
V_223 = 512 * 13 * 8 ;
break;
case V_23 :
V_223 = 490000 ;
break;
default:
F_27 ( F_6 ( V_33 ) , L_26 ) ;
return;
}
F_30 ( & V_13 -> V_30 , V_79 ) ;
if ( ! V_33 -> V_154 ) {
F_27 ( F_6 ( V_33 ) ,
L_27 ) ;
F_31 ( & V_13 -> V_30 , V_79 ) ;
return;
}
for ( V_119 = 0 ; V_119 < V_121 ; V_119 ++ ) {
if ( ! V_122 [ V_119 ] )
break;
V_13 -> V_4 [ V_119 ] . V_125 = 0 ;
}
V_225:
F_115 (urbp, tmp, &dum_hcd->urbp_list, urbp_list) {
struct V_144 * V_144 ;
struct V_5 * V_8 ;
V_111 V_32 ;
struct V_1 * V_4 = NULL ;
int type ;
int V_28 = - V_81 ;
V_144 = V_151 -> V_144 ;
if ( V_144 -> V_226 )
goto V_227;
else if ( V_33 -> V_45 != V_160 )
continue;
type = F_97 ( V_144 -> V_146 ) ;
if ( V_223 <= 0 && type == V_228 )
continue;
V_32 = F_87 ( V_144 -> V_146 ) ;
if ( F_102 ( V_144 -> V_146 ) )
V_32 |= V_84 ;
V_4 = F_110 ( V_13 , V_32 ) ;
if ( ! V_4 ) {
F_28 ( F_6 ( V_33 ) ,
L_28 ,
V_144 ) ;
V_28 = - V_229 ;
goto V_227;
}
if ( V_4 -> V_125 )
continue;
V_4 -> V_125 = 1 ;
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_144 -> V_158 ) {
V_4 -> V_126 = 1 ;
V_144 -> V_158 = 0 ;
}
if ( V_4 -> V_77 && ! V_4 -> V_126 ) {
F_28 ( F_6 ( V_33 ) , L_29 ,
V_4 -> V_4 . V_63 , V_144 ) ;
V_28 = - V_230 ;
goto V_227;
}
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_4 -> V_126 ) {
struct V_191 V_192 ;
int V_92 = 1 ;
V_192 = * (struct V_191 * ) V_144 -> V_231 ;
F_18 (req, &ep->queue, queue) {
F_14 ( & V_8 -> V_26 ) ;
V_8 -> V_8 . V_28 = - V_186 ;
F_28 ( F_7 ( V_13 ) , L_30 ,
V_8 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_8 -> V_8 . V_31 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_16 ( & V_13 -> V_30 ) ;
V_4 -> V_125 = 0 ;
goto V_225;
}
V_4 -> V_128 = V_104 ;
V_4 -> V_126 = 0 ;
V_4 -> V_77 = 0 ;
V_92 = F_112 ( V_33 , V_144 , & V_192 ,
& V_28 ) ;
if ( V_92 > 0 ) {
F_15 ( & V_13 -> V_30 ) ;
V_92 = V_13 -> V_54 -> V_192 ( & V_13 -> V_18 ,
& V_192 ) ;
F_16 ( & V_13 -> V_30 ) ;
if ( V_92 >= 0 ) {
V_179 = 64 * 1024 ;
goto V_232;
}
}
if ( V_92 < 0 ) {
if ( V_92 != - V_211 )
F_28 ( F_7 ( V_13 ) ,
L_31 ,
V_92 ) ;
V_28 = - V_230 ;
V_144 -> V_172 = 0 ;
}
goto V_227;
}
V_179 = V_223 ;
switch ( F_97 ( V_144 -> V_146 ) ) {
case V_233 :
V_179 = V_61 ( V_179 , F_109 ( V_13 , V_4 ) ) ;
V_28 = - V_234 ;
break;
case V_235 :
V_179 = V_61 ( V_179 , F_109 ( V_13 , V_4 ) ) ;
default:
V_232:
V_4 -> V_128 = V_104 ;
V_223 = F_107 ( V_33 , V_144 , V_4 , V_179 , & V_28 ) ;
break;
}
if ( V_28 == - V_81 )
continue;
V_227:
F_116 ( & V_151 -> V_155 ) ;
F_37 ( V_151 ) ;
if ( V_4 )
V_4 -> V_125 = V_4 -> V_126 = 0 ;
F_117 ( F_5 ( V_33 ) , V_144 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_118 ( F_5 ( V_33 ) , V_144 , V_28 ) ;
F_16 ( & V_13 -> V_30 ) ;
goto V_225;
}
if ( F_12 ( & V_33 -> V_155 ) ) {
F_119 ( V_33 -> V_154 ) ;
V_33 -> V_154 = NULL ;
} else if ( V_33 -> V_45 == V_160 ) {
F_51 ( & V_33 -> V_159 , V_104 + F_50 ( 1 ) ) ;
}
F_31 ( & V_13 -> V_30 , V_79 ) ;
}
static int F_120 ( struct V_10 * V_11 , char * V_88 )
{
struct V_9 * V_33 ;
unsigned long V_79 ;
int V_62 = 0 ;
V_33 = F_4 ( V_11 ) ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
if ( ! F_121 ( V_11 ) )
goto V_69;
if ( V_33 -> V_52 && F_122 ( V_104 , V_33 -> V_103 ) ) {
V_33 -> V_35 |= ( V_236 << 16 ) ;
V_33 -> V_35 &= ~ V_51 ;
F_20 ( V_33 ) ;
}
if ( ( V_33 -> V_35 & V_237 ) != 0 ) {
* V_88 = ( 1 << 1 ) ;
F_28 ( F_6 ( V_33 ) , L_32 ,
V_33 -> V_35 ) ;
V_62 = 1 ;
if ( V_33 -> V_45 == V_46 )
F_123 ( V_11 ) ;
}
V_69:
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_62 ;
}
static inline void
F_124 ( struct V_238 * V_60 )
{
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_65 = 0x2a ;
V_60 -> V_239 = 12 ;
V_60 -> V_240 = F_125 ( 0x0001 ) ;
V_60 -> V_241 = 1 ;
V_60 -> V_242 . V_243 . V_244 = 0x04 ;
V_60 -> V_242 . V_243 . V_245 = 0xffff ;
}
static inline void F_126 ( struct V_238 * V_60 )
{
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_65 = 0x29 ;
V_60 -> V_239 = 9 ;
V_60 -> V_240 = F_125 ( 0x0001 ) ;
V_60 -> V_241 = 1 ;
V_60 -> V_242 . V_246 . V_245 [ 0 ] = 0xff ;
V_60 -> V_242 . V_246 . V_245 [ 1 ] = 0xff ;
}
static int F_127 (
struct V_10 * V_11 ,
T_5 V_247 ,
T_5 V_198 ,
T_5 V_197 ,
char * V_88 ,
T_5 V_248
) {
struct V_9 * V_33 ;
int V_62 = 0 ;
unsigned long V_79 ;
if ( ! F_121 ( V_11 ) )
return - V_249 ;
V_33 = F_4 ( V_11 ) ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
switch ( V_247 ) {
case V_250 :
break;
case V_251 :
switch ( V_198 ) {
case V_252 :
if ( V_11 -> V_22 == V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_33
L_34 ) ;
goto error;
}
if ( V_33 -> V_35 & V_51 ) {
V_33 -> V_52 = 1 ;
V_33 -> V_103 = V_104 +
F_50 ( 20 ) ;
}
break;
case V_253 :
if ( V_11 -> V_22 == V_34 ) {
if ( V_33 -> V_35 & V_48 )
F_28 ( F_6 ( V_33 ) ,
L_35 ) ;
} else
if ( V_33 -> V_35 &
V_36 )
F_28 ( F_6 ( V_33 ) ,
L_35 ) ;
default:
V_33 -> V_35 &= ~ ( 1 << V_198 ) ;
F_20 ( V_33 ) ;
}
break;
case V_254 :
if ( V_11 -> V_22 == V_34 &&
( V_248 < V_255 ||
V_198 != ( V_256 << 8 ) ) ) {
F_28 ( F_6 ( V_33 ) ,
L_36
L_37 ) ;
goto error;
}
if ( V_11 -> V_22 == V_34 )
F_124 ( (struct V_238 * ) V_88 ) ;
else
F_126 ( (struct V_238 * ) V_88 ) ;
break;
case V_257 | V_258 :
if ( V_11 -> V_22 != V_34 )
goto error;
if ( ( V_198 >> 8 ) != V_259 )
goto error;
memcpy ( V_88 , & V_260 , sizeof( V_260 ) ) ;
V_62 = sizeof( V_260 ) ;
break;
case V_261 :
* ( V_262 * ) V_88 = F_128 ( 0 ) ;
break;
case V_263 :
if ( V_197 != 1 )
V_62 = - V_230 ;
if ( V_33 -> V_52 &&
F_122 ( V_104 , V_33 -> V_103 ) ) {
V_33 -> V_35 |= ( V_236 << 16 ) ;
V_33 -> V_35 &= ~ V_51 ;
}
if ( ( V_33 -> V_35 & V_53 ) != 0 &&
F_122 ( V_104 , V_33 -> V_103 ) ) {
V_33 -> V_35 |= ( V_264 << 16 ) ;
V_33 -> V_35 &= ~ V_53 ;
if ( V_33 -> V_13 -> V_37 ) {
V_33 -> V_35 |= V_40 ;
if ( V_11 -> V_22 < V_34 ) {
switch ( V_33 -> V_13 -> V_18 . V_22 ) {
case V_70 :
V_33 -> V_35 |=
V_50 ;
break;
case V_224 :
V_33 -> V_13 -> V_18 . V_129 ->
V_74 = 8 ;
V_33 -> V_35 |=
V_49 ;
break;
default:
V_33 -> V_13 -> V_18 . V_22 =
V_71 ;
break;
}
}
}
}
F_20 ( V_33 ) ;
( ( V_265 * ) V_88 ) [ 0 ] = F_125 ( V_33 -> V_35 ) ;
( ( V_265 * ) V_88 ) [ 1 ] = F_125 ( V_33 -> V_35 >> 16 ) ;
break;
case V_266 :
V_62 = - V_230 ;
break;
case V_267 :
switch ( V_198 ) {
case V_268 :
if ( V_11 -> V_22 != V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_38
L_39 ) ;
goto error;
}
break;
case V_269 :
case V_270 :
if ( V_11 -> V_22 != V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_40
L_39 ) ;
goto error;
}
break;
case V_252 :
if ( V_11 -> V_22 == V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_33
L_34 ) ;
goto error;
}
if ( V_33 -> V_47 ) {
V_33 -> V_35 |= V_51 ;
F_20 ( V_33 ) ;
if ( ( ( 1 << V_99 )
& V_33 -> V_13 -> V_98 ) != 0 )
F_28 ( F_6 ( V_33 ) ,
L_41 ) ;
}
break;
case V_253 :
if ( V_11 -> V_22 == V_34 )
V_33 -> V_35 |= V_36 ;
else
V_33 -> V_35 |= V_48 ;
F_20 ( V_33 ) ;
break;
case V_271 :
if ( V_11 -> V_22 != V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_42
L_39 ) ;
goto error;
}
case V_272 :
if ( V_11 -> V_22 == V_34 ) {
V_33 -> V_35 = 0 ;
V_33 -> V_35 =
( V_36 |
V_39 |
V_53 ) ;
} else
V_33 -> V_35 &= ~ ( V_40
| V_49
| V_50 ) ;
V_33 -> V_13 -> V_98 &=
( 1 << V_106 ) ;
V_33 -> V_103 = V_104 + F_50 ( 50 ) ;
default:
if ( V_11 -> V_22 == V_34 ) {
if ( ( V_33 -> V_35 &
V_36 ) != 0 ) {
V_33 -> V_35 |= ( 1 << V_198 ) ;
F_20 ( V_33 ) ;
}
} else
if ( ( V_33 -> V_35 &
V_48 ) != 0 ) {
V_33 -> V_35 |= ( 1 << V_198 ) ;
F_20 ( V_33 ) ;
}
}
break;
case V_273 :
if ( V_11 -> V_22 != V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_43
L_39 ) ;
goto error;
}
* ( V_262 * ) V_88 = F_128 ( 0 ) ;
break;
case V_274 :
if ( V_11 -> V_22 != V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_44
L_45 ) ;
goto error;
}
break;
default:
F_28 ( F_6 ( V_33 ) ,
L_46 ,
V_247 , V_198 , V_197 , V_248 ) ;
error:
V_62 = - V_230 ;
}
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
if ( ( V_33 -> V_35 & V_237 ) != 0 )
F_57 ( V_11 ) ;
return V_62 ;
}
static int F_129 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
F_28 ( & V_11 -> V_15 . V_275 -> V_19 , L_19 , V_142 ) ;
F_78 ( & V_33 -> V_13 -> V_30 ) ;
V_33 -> V_45 = V_46 ;
F_20 ( V_33 ) ;
V_11 -> V_141 = V_276 ;
F_79 ( & V_33 -> V_13 -> V_30 ) ;
return 0 ;
}
static int F_130 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
int V_134 = 0 ;
F_28 ( & V_11 -> V_15 . V_275 -> V_19 , L_19 , V_142 ) ;
F_78 ( & V_33 -> V_13 -> V_30 ) ;
if ( ! F_121 ( V_11 ) ) {
V_134 = - V_29 ;
} else {
V_33 -> V_45 = V_160 ;
F_20 ( V_33 ) ;
if ( ! F_12 ( & V_33 -> V_155 ) )
F_51 ( & V_33 -> V_159 , V_104 ) ;
V_11 -> V_141 = V_277 ;
}
F_79 ( & V_33 -> V_13 -> V_30 ) ;
return V_134 ;
}
static inline T_2 F_131 ( char * V_88 , T_6 V_278 , struct V_144 * V_144 )
{
int V_4 = F_87 ( V_144 -> V_146 ) ;
return snprintf (buf, size,
L_47 ,
urb,
({ char *s;
switch (urb->dev->speed) {
case USB_SPEED_LOW:
s = L_48;
break;
case USB_SPEED_FULL:
s = L_49;
break;
case USB_SPEED_HIGH:
s = L_50;
break;
case USB_SPEED_SUPER:
s = L_51;
break;
default:
s = L_52;
break;
}; s; }),
ep, ep ? (usb_pipein(urb->pipe) ? L_7 : L_8) : L_53 ,
({ char *s; \
switch (usb_pipetype(urb->pipe)) { \
case PIPE_CONTROL: \
s = L_53; \
break; \
case PIPE_BULK: \
s = L_3; \
break; \
case PIPE_INTERRUPT: \
s = L_2; \
break; \
default: \
s = L_1; \
break; \
}; s; }),
urb->actual_length, urb->transfer_buffer_length) ;
}
static T_2 F_132 ( struct V_14 * V_19 , struct V_112 * V_113 ,
char * V_88 )
{
struct V_10 * V_11 = F_133 ( V_19 ) ;
struct V_9 * V_33 = F_4 ( V_11 ) ;
struct V_151 * V_151 ;
T_6 V_278 = 0 ;
unsigned long V_79 ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
F_18 (urbp, &dum_hcd->urbp_list, urbp_list) {
T_6 V_279 ;
V_279 = F_131 ( V_88 , V_115 - V_278 , V_151 -> V_144 ) ;
V_88 += V_279 ;
V_278 += V_279 ;
}
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_278 ;
}
static int F_134 ( struct V_9 * V_33 )
{
F_135 ( & V_33 -> V_159 ) ;
V_33 -> V_159 . V_114 = F_114 ;
V_33 -> V_159 . V_280 = ( unsigned long ) V_33 ;
V_33 -> V_45 = V_160 ;
V_33 -> V_145 = 0 ;
F_34 ( & V_33 -> V_155 ) ;
F_5 ( V_33 ) -> V_281 = V_282 ;
F_5 ( V_33 ) -> V_141 = V_277 ;
F_5 ( V_33 ) -> V_283 = 1 ;
#ifdef F_64
F_5 ( V_33 ) -> V_15 . V_284 = 1 ;
#endif
return 0 ;
return F_70 ( F_6 ( V_33 ) , & V_285 ) ;
}
static int F_136 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
if ( ! F_137 ( V_11 ) )
return F_134 ( V_33 ) ;
F_138 ( & V_33 -> V_13 -> V_30 ) ;
F_135 ( & V_33 -> V_159 ) ;
V_33 -> V_159 . V_114 = F_114 ;
V_33 -> V_159 . V_280 = ( unsigned long ) V_33 ;
V_33 -> V_45 = V_160 ;
F_34 ( & V_33 -> V_155 ) ;
V_11 -> V_281 = V_282 ;
V_11 -> V_141 = V_277 ;
V_11 -> V_283 = 1 ;
#ifdef F_64
V_11 -> V_15 . V_284 = 1 ;
#endif
return F_70 ( F_6 ( V_33 ) , & V_285 ) ;
}
static void F_139 ( struct V_10 * V_11 )
{
struct V_17 * V_13 ;
V_13 = F_4 ( V_11 ) -> V_13 ;
F_76 ( F_6 ( F_4 ( V_11 ) ) , & V_285 ) ;
F_140 ( V_13 -> V_54 ) ;
F_141 ( F_6 ( F_4 ( V_11 ) ) , L_54 ) ;
}
static int F_142 ( struct V_10 * V_11 )
{
return F_47 ( NULL ) ;
}
static int F_143 ( struct V_10 * V_11 )
{
V_11 -> V_15 . V_286 = ~ 0 ;
if ( F_137 ( V_11 ) ) {
V_133 . V_25 = F_4 ( V_11 ) ;
V_133 . V_25 -> V_13 = & V_133 ;
V_11 -> V_22 = V_287 ;
V_11 -> V_15 . V_275 -> V_22 = V_70 ;
} else {
V_133 . V_24 = F_4 ( V_11 ) ;
V_133 . V_24 -> V_13 = & V_133 ;
V_11 -> V_22 = V_34 ;
V_11 -> V_15 . V_275 -> V_22 = V_23 ;
}
return 0 ;
}
static int F_144 ( struct V_10 * V_11 , struct V_288 * V_154 ,
struct V_289 * * V_290 , unsigned int V_291 ,
unsigned int V_292 , T_1 V_80 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
unsigned long V_79 ;
int V_293 ;
int V_294 = V_292 ;
unsigned int V_143 ;
unsigned int V_119 ;
if ( ! V_291 )
return - V_67 ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
for ( V_119 = 0 ; V_119 < V_291 ; V_119 ++ ) {
V_143 = F_82 ( & V_290 [ V_119 ] -> V_60 ) ;
if ( ( 1 << V_143 ) & V_33 -> V_145 ) {
V_294 = - V_67 ;
goto V_295;
}
V_293 = F_25 ( & V_290 [ V_119 ] -> V_296 ) ;
if ( ! V_293 ) {
V_294 = - V_67 ;
goto V_295;
}
if ( V_293 < V_294 ) {
F_28 ( F_6 ( V_33 ) , L_55
L_56 ,
V_290 [ V_119 ] -> V_60 . V_83 ,
V_293 ) ;
V_294 = V_293 ;
}
}
for ( V_119 = 0 ; V_119 < V_291 ; V_119 ++ ) {
V_143 = F_82 ( & V_290 [ V_119 ] -> V_60 ) ;
V_33 -> V_145 |= 1 << V_143 ;
F_89 ( V_33 ,
F_83 ( & V_290 [ V_119 ] -> V_60 ) , V_294 ) ;
}
V_295:
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_294 ;
}
static int F_145 ( struct V_10 * V_11 , struct V_288 * V_154 ,
struct V_289 * * V_290 , unsigned int V_291 ,
T_1 V_80 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
unsigned long V_79 ;
int V_297 ;
unsigned int V_143 ;
unsigned int V_119 ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
for ( V_119 = 0 ; V_119 < V_291 ; V_119 ++ ) {
V_143 = F_82 ( & V_290 [ V_119 ] -> V_60 ) ;
if ( ! ( ( 1 << V_143 ) & V_33 -> V_145 ) ) {
V_297 = - V_67 ;
goto V_295;
}
}
for ( V_119 = 0 ; V_119 < V_291 ; V_119 ++ ) {
V_143 = F_82 ( & V_290 [ V_119 ] -> V_60 ) ;
V_33 -> V_145 &= ~ ( 1 << V_143 ) ;
F_89 ( V_33 ,
F_83 ( & V_290 [ V_119 ] -> V_60 ) , 0 ) ;
}
V_297 = 0 ;
V_295:
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_297 ;
}
static int F_146 ( struct V_131 * V_132 )
{
struct V_10 * V_25 ;
struct V_10 * V_24 ;
int V_62 ;
F_141 ( & V_132 -> V_19 , L_57 V_298 L_58 , V_299 ) ;
if ( ! V_107 . V_108 )
V_9 . V_79 = V_287 ;
V_25 = F_147 ( & V_9 , & V_132 -> V_19 , F_148 ( & V_132 -> V_19 ) ) ;
if ( ! V_25 )
return - V_152 ;
V_25 -> V_300 = 1 ;
V_62 = F_149 ( V_25 , 0 , 0 ) ;
if ( V_62 )
goto V_301;
if ( V_107 . V_108 ) {
V_24 = F_150 ( & V_9 , & V_132 -> V_19 ,
F_148 ( & V_132 -> V_19 ) , V_25 ) ;
if ( ! V_24 ) {
V_62 = - V_152 ;
goto V_302;
}
V_62 = F_149 ( V_24 , 0 , 0 ) ;
if ( V_62 )
goto V_303;
}
return 0 ;
V_303:
F_151 ( V_24 ) ;
V_302:
F_152 ( V_25 ) ;
V_301:
F_151 ( V_25 ) ;
V_133 . V_25 = V_133 . V_24 = NULL ;
return V_62 ;
}
static int F_153 ( struct V_131 * V_132 )
{
struct V_17 * V_13 ;
V_13 = F_4 ( F_75 ( V_132 ) ) -> V_13 ;
if ( V_13 -> V_24 ) {
F_152 ( F_5 ( V_13 -> V_24 ) ) ;
F_151 ( F_5 ( V_13 -> V_24 ) ) ;
}
F_152 ( F_5 ( V_13 -> V_25 ) ) ;
F_151 ( F_5 ( V_13 -> V_25 ) ) ;
V_133 . V_25 = NULL ;
V_133 . V_24 = NULL ;
return 0 ;
}
static int F_154 ( struct V_131 * V_132 , T_3 V_141 )
{
struct V_10 * V_11 ;
struct V_9 * V_33 ;
int V_134 = 0 ;
F_28 ( & V_132 -> V_19 , L_19 , V_142 ) ;
V_11 = F_75 ( V_132 ) ;
V_33 = F_4 ( V_11 ) ;
if ( V_33 -> V_45 == V_160 ) {
F_155 ( & V_132 -> V_19 , L_59 ) ;
V_134 = - V_304 ;
} else
F_156 ( V_305 , & V_11 -> V_79 ) ;
return V_134 ;
}
static int F_157 ( struct V_131 * V_132 )
{
struct V_10 * V_11 ;
F_28 ( & V_132 -> V_19 , L_19 , V_142 ) ;
V_11 = F_75 ( V_132 ) ;
F_158 ( V_305 , & V_11 -> V_79 ) ;
F_57 ( V_11 ) ;
return 0 ;
}
static int T_7 F_159 ( void )
{
int V_62 = - V_152 ;
if ( F_160 () )
return - V_306 ;
if ( ! V_107 . V_110 && V_107 . V_108 )
return - V_67 ;
V_307 = F_161 ( V_308 , - 1 ) ;
if ( ! V_307 )
return V_62 ;
V_309 = F_161 ( V_135 , - 1 ) ;
if ( ! V_309 )
goto V_310;
V_62 = F_162 ( & V_311 ) ;
if ( V_62 < 0 )
goto V_312;
V_62 = F_162 ( & V_313 ) ;
if ( V_62 < 0 )
goto V_314;
V_62 = F_163 ( V_307 ) ;
if ( V_62 < 0 )
goto V_315;
if ( ! V_133 . V_25 ||
( ! V_133 . V_24 && V_107 . V_108 ) ) {
V_62 = - V_67 ;
goto V_316;
}
V_62 = F_163 ( V_309 ) ;
if ( V_62 < 0 )
goto V_316;
if ( ! F_75 ( V_309 ) ) {
V_62 = - V_67 ;
goto V_317;
}
return V_62 ;
V_317:
F_164 ( V_309 ) ;
V_316:
F_164 ( V_307 ) ;
V_315:
F_165 ( & V_313 ) ;
V_314:
F_165 ( & V_311 ) ;
V_312:
F_166 ( V_309 ) ;
V_310:
F_166 ( V_307 ) ;
return V_62 ;
}
static void T_8 F_167 ( void )
{
F_168 ( V_309 ) ;
F_168 ( V_307 ) ;
F_165 ( & V_313 ) ;
F_165 ( & V_311 ) ;
}
