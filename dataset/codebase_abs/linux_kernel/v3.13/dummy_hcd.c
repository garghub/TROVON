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
} val; }),
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
F_28 ( F_7 ( V_13 ) , L_20 ,
V_54 -> V_54 . V_63 ) ;
return 0 ;
}
static int F_61 ( struct V_21 * V_116 ,
struct V_117 * V_54 )
{
struct V_9 * V_33 = F_9 ( V_116 ) ;
struct V_17 * V_13 = V_33 -> V_13 ;
if ( V_54 )
F_28 ( F_7 ( V_13 ) , L_21 ,
V_54 -> V_54 . V_63 ) ;
V_13 -> V_54 = NULL ;
return 0 ;
}
static void F_62 ( struct V_17 * V_13 )
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
#ifdef F_63
V_13 -> V_18 . V_130 = 1 ;
#endif
}
static int F_64 ( struct V_131 * V_132 )
{
struct V_17 * V_13 ;
int V_133 ;
V_13 = * ( ( void * * ) F_65 ( & V_132 -> V_19 ) ) ;
V_13 -> V_18 . V_63 = V_134 ;
V_13 -> V_18 . V_123 = & V_135 ;
V_13 -> V_18 . V_109 = V_23 ;
V_13 -> V_18 . V_19 . V_20 = & V_132 -> V_19 ;
F_62 ( V_13 ) ;
V_133 = F_66 ( & V_132 -> V_19 , & V_13 -> V_18 ) ;
if ( V_133 < 0 )
goto V_136;
V_133 = F_67 ( & V_13 -> V_18 . V_19 , & V_137 ) ;
if ( V_133 < 0 )
goto V_138;
F_68 ( V_132 , V_13 ) ;
return V_133 ;
V_138:
F_69 ( & V_13 -> V_18 ) ;
V_136:
return V_133 ;
}
static int F_70 ( struct V_131 * V_132 )
{
struct V_17 * V_13 = F_71 ( V_132 ) ;
F_72 ( & V_13 -> V_18 . V_19 , & V_137 ) ;
F_69 ( & V_13 -> V_18 ) ;
return 0 ;
}
static void F_73 ( struct V_17 * V_13 , struct V_9 * V_33 ,
int V_57 )
{
F_74 ( & V_13 -> V_30 ) ;
V_13 -> V_38 = V_57 ;
F_20 ( V_33 ) ;
F_75 ( & V_13 -> V_30 ) ;
}
static int F_76 ( struct V_131 * V_132 , T_3 V_139 )
{
struct V_17 * V_13 = F_71 ( V_132 ) ;
struct V_9 * V_33 = F_9 ( & V_13 -> V_18 ) ;
F_28 ( & V_132 -> V_19 , L_19 , V_140 ) ;
F_73 ( V_13 , V_33 , 1 ) ;
F_57 ( F_5 ( V_33 ) ) ;
return 0 ;
}
static int F_77 ( struct V_131 * V_132 )
{
struct V_17 * V_13 = F_71 ( V_132 ) ;
struct V_9 * V_33 = F_9 ( & V_13 -> V_18 ) ;
F_28 ( & V_132 -> V_19 , L_19 , V_140 ) ;
F_73 ( V_13 , V_33 , 0 ) ;
F_57 ( F_5 ( V_33 ) ) ;
return 0 ;
}
static unsigned int F_78 ( const struct V_59 * V_60 )
{
unsigned int V_141 ;
V_141 = F_79 ( V_60 ) << 1 ;
if ( F_80 ( V_60 ) )
V_141 |= 1 ;
return V_141 ;
}
static int F_81 ( struct V_9 * V_33 , struct V_142 * V_142 )
{
const struct V_59 * V_60 = & V_142 -> V_4 -> V_60 ;
T_4 V_141 ;
if ( ! F_26 ( V_60 ) )
return 0 ;
V_141 = F_78 ( V_60 ) ;
return ( 1 << V_141 ) & V_33 -> V_143 ;
}
static int F_82 ( struct V_9 * V_33 ,
unsigned int V_144 )
{
int V_127 ;
V_127 = V_33 -> V_145 [ F_83 ( V_144 ) ] ;
if ( F_84 ( V_144 ) )
V_127 >>= 4 ;
else
V_127 &= 0xf ;
V_127 ++ ;
return V_127 ;
}
static void F_85 ( struct V_9 * V_33 ,
unsigned int V_144 , unsigned int V_146 )
{
int V_127 ;
V_146 -- ;
V_127 = V_33 -> V_145 [ F_83 ( V_144 ) ] ;
if ( F_84 ( V_144 ) ) {
V_146 <<= 4 ;
V_127 &= 0xf ;
} else {
V_127 &= 0xf0 ;
}
V_127 |= V_146 ;
V_33 -> V_145 [ F_83 ( V_144 ) ] = V_127 ;
}
static int F_86 ( struct V_9 * V_33 , struct V_142 * V_142 )
{
unsigned int V_127 ;
int V_147 ;
V_147 = F_81 ( V_33 , V_142 ) ;
if ( ! V_142 -> V_148 ) {
if ( V_147 )
return - V_67 ;
return 0 ;
}
if ( ! V_147 )
return - V_67 ;
V_127 = F_82 ( V_33 ,
F_83 ( V_142 -> V_144 ) ) ;
if ( V_142 -> V_148 > V_127 ) {
F_27 ( F_6 ( V_33 ) , L_22 ,
V_142 -> V_148 ) ;
F_87 () ;
return - V_67 ;
}
return 0 ;
}
static int F_88 (
struct V_10 * V_11 ,
struct V_142 * V_142 ,
T_1 V_80
) {
struct V_9 * V_33 ;
struct V_149 * V_149 ;
unsigned long V_79 ;
int V_133 ;
V_149 = F_89 ( sizeof *V_149 , V_80 ) ;
if ( ! V_149 )
return - V_150 ;
V_149 -> V_142 = V_142 ;
V_149 -> V_151 = 0 ;
V_33 = F_4 ( V_11 ) ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
V_133 = F_86 ( V_33 , V_142 ) ;
if ( V_133 ) {
F_37 ( V_149 ) ;
goto V_69;
}
V_133 = F_90 ( V_11 , V_142 ) ;
if ( V_133 ) {
F_37 ( V_149 ) ;
goto V_69;
}
if ( ! V_33 -> V_152 ) {
V_33 -> V_152 = V_142 -> V_19 ;
F_91 ( V_33 -> V_152 ) ;
} else if ( F_92 ( V_33 -> V_152 != V_142 -> V_19 ) )
F_27 ( F_6 ( V_33 ) , L_23 ) ;
F_40 ( & V_149 -> V_153 , & V_33 -> V_153 ) ;
V_142 -> V_154 = V_149 ;
if ( F_93 ( V_142 -> V_144 ) == V_155 )
V_142 -> V_156 = 1 ;
if ( ! F_94 ( & V_33 -> V_157 ) )
F_51 ( & V_33 -> V_157 , V_104 + 1 ) ;
V_69:
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_133 ;
}
static int F_95 ( struct V_10 * V_11 , struct V_142 * V_142 , int V_28 )
{
struct V_9 * V_33 ;
unsigned long V_79 ;
int V_133 ;
V_33 = F_4 ( V_11 ) ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
V_133 = F_96 ( V_11 , V_142 , V_28 ) ;
if ( ! V_133 && V_33 -> V_45 != V_158 &&
! F_12 ( & V_33 -> V_153 ) )
F_51 ( & V_33 -> V_157 , V_104 ) ;
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_133 ;
}
static int F_97 ( struct V_142 * V_142 , struct V_5 * V_8 ,
T_4 V_159 )
{
void * V_160 , * V_161 ;
struct V_149 * V_149 = V_142 -> V_154 ;
int V_162 ;
struct V_163 * V_164 = & V_149 -> V_164 ;
T_4 V_165 = 0 ;
T_4 V_166 ;
bool V_167 ;
V_162 = F_98 ( V_142 -> V_144 ) ;
V_161 = V_8 -> V_8 . V_88 + V_8 -> V_8 . V_82 ;
if ( ! V_142 -> V_168 ) {
V_160 = V_142 -> V_169 + V_142 -> V_170 ;
if ( V_162 )
memcpy ( V_160 , V_161 , V_159 ) ;
else
memcpy ( V_161 , V_160 , V_159 ) ;
return V_159 ;
}
if ( ! V_149 -> V_151 ) {
T_4 V_79 = V_171 ;
if ( V_162 )
V_79 |= V_172 ;
else
V_79 |= V_173 ;
F_99 ( V_164 , V_142 -> V_174 , V_142 -> V_168 , V_79 ) ;
V_149 -> V_151 = 1 ;
}
V_167 = F_100 ( V_164 ) ;
if ( V_167 == false ) {
F_101 ( 1 ) ;
return - V_67 ;
}
do {
V_160 = V_164 -> V_175 ;
V_166 = F_55 ( T_4 , V_159 , V_164 -> V_86 ) ;
V_164 -> V_176 = V_166 ;
V_165 += V_166 ;
if ( V_162 )
memcpy ( V_160 , V_161 , V_166 ) ;
else
memcpy ( V_161 , V_160 , V_166 ) ;
V_159 -= V_166 ;
if ( ! V_159 )
break;
V_167 = F_100 ( V_164 ) ;
if ( V_167 == false ) {
F_101 ( 1 ) ;
return - V_67 ;
}
V_161 += V_166 ;
} while ( 1 );
F_102 ( V_164 ) ;
return V_165 ;
}
static int F_103 ( struct V_9 * V_33 , struct V_142 * V_142 ,
struct V_1 * V_4 , int V_177 , int * V_28 )
{
struct V_17 * V_13 = V_33 -> V_13 ;
struct V_5 * V_8 ;
V_178:
F_18 (req, &ep->queue, queue) {
unsigned V_179 , V_180 , V_159 ;
int V_181 , V_162 ;
int V_182 = 0 ;
if ( F_81 ( V_33 , V_142 ) ) {
if ( ( V_142 -> V_148 != V_8 -> V_8 . V_148 ) )
continue;
}
V_179 = V_142 -> V_183 - V_142 -> V_170 ;
V_180 = V_8 -> V_8 . V_86 - V_8 -> V_8 . V_82 ;
V_159 = F_104 ( V_179 , V_180 ) ;
V_162 = F_98 ( V_142 -> V_144 ) ;
if ( F_92 ( V_159 == 0 ) )
V_181 = 1 ;
else {
if ( V_177 < V_4 -> V_4 . V_74 && V_177 < V_159 )
break;
V_159 = F_55 ( unsigned , V_159 , V_177 ) ;
if ( V_159 == 0 )
break;
if ( V_159 > V_4 -> V_4 . V_74 ) {
V_182 = 1 ;
V_159 -= ( V_159 % V_4 -> V_4 . V_74 ) ;
}
V_181 = ( V_159 % V_4 -> V_4 . V_74 ) != 0 ;
V_159 = F_97 ( V_142 , V_8 , V_159 ) ;
V_4 -> V_128 = V_104 ;
if ( ( int ) V_159 < 0 ) {
V_8 -> V_8 . V_28 = V_159 ;
} else {
V_177 -= V_159 ;
V_142 -> V_170 += V_159 ;
V_8 -> V_8 . V_82 += V_159 ;
}
}
if ( V_181 ) {
if ( V_179 == V_180 ) {
V_8 -> V_8 . V_28 = 0 ;
* V_28 = 0 ;
} else if ( V_162 ) {
V_8 -> V_8 . V_28 = 0 ;
if ( V_180 > V_179 )
* V_28 = - V_184 ;
else
* V_28 = 0 ;
} else if ( ! V_162 ) {
* V_28 = 0 ;
if ( V_179 > V_180 )
V_8 -> V_8 . V_28 = - V_184 ;
else
V_8 -> V_8 . V_28 = 0 ;
}
} else {
if ( V_8 -> V_8 . V_86 == V_8 -> V_8 . V_82
&& ! V_8 -> V_8 . V_185 )
V_8 -> V_8 . V_28 = 0 ;
if ( V_142 -> V_183 == V_142 -> V_170
&& ! ( V_142 -> V_186
& V_187 ) )
* V_28 = 0 ;
}
if ( V_8 -> V_8 . V_28 != - V_81 ) {
F_14 ( & V_8 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_8 -> V_8 . V_31 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_16 ( & V_13 -> V_30 ) ;
V_182 = 1 ;
}
if ( * V_28 != - V_81 )
break;
if ( V_182 )
goto V_178;
}
return V_177 ;
}
static int F_105 ( struct V_17 * V_13 , struct V_1 * V_4 )
{
int V_177 = V_4 -> V_4 . V_74 ;
if ( V_13 -> V_18 . V_22 == V_70 ) {
int V_188 ;
V_188 = F_23 ( V_4 -> V_60 ) ;
V_188 = ( V_188 >> 11 ) & 0x03 ;
V_188 *= 8 ;
V_177 += V_177 * V_188 ;
}
if ( V_13 -> V_18 . V_22 == V_23 ) {
switch ( F_24 ( V_4 -> V_60 ) ) {
case V_73 :
V_177 = 3 * 16 * 1024 * 8 ;
break;
case V_72 :
V_177 = 3 * 1024 * 8 ;
break;
case V_68 :
default:
break;
}
}
return V_177 ;
}
static struct V_1 * F_106 ( struct V_17 * V_13 , V_111 V_32 )
{
int V_119 ;
if ( ! F_107 ( ( V_13 -> V_18 . V_22 == V_23 ?
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
static int F_108 ( struct V_9 * V_33 , struct V_142 * V_142 ,
struct V_189 * V_190 ,
int * V_28 )
{
struct V_1 * V_191 ;
struct V_17 * V_13 = V_33 -> V_13 ;
int V_192 = 1 ;
unsigned V_193 ;
unsigned V_194 ;
V_193 = F_109 ( V_190 -> V_195 ) ;
V_194 = F_109 ( V_190 -> V_196 ) ;
switch ( V_190 -> V_197 ) {
case V_198 :
if ( V_190 -> V_199 != V_200 )
break;
V_13 -> V_32 = V_194 ;
* V_28 = 0 ;
F_28 ( F_7 ( V_13 ) , L_24 ,
V_194 ) ;
V_192 = 0 ;
break;
case V_201 :
if ( V_190 -> V_199 == V_200 ) {
V_192 = 0 ;
switch ( V_194 ) {
case V_100 :
break;
case V_99 :
V_13 -> V_18 . V_202 = 1 ;
break;
case V_203 :
V_13 -> V_18 . V_204 = 1 ;
break;
case V_205 :
V_13 -> V_18 . V_206 = 1 ;
break;
case V_207 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_194 = V_208 ;
else
V_192 = - V_209 ;
break;
case V_210 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_194 = V_211 ;
else
V_192 = - V_209 ;
break;
case V_212 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_194 = V_213 ;
else
V_192 = - V_209 ;
break;
default:
V_192 = - V_209 ;
}
if ( V_192 == 0 ) {
V_13 -> V_98 |= ( 1 << V_194 ) ;
* V_28 = 0 ;
}
} else if ( V_190 -> V_199 == V_214 ) {
V_191 = F_106 ( V_13 , V_193 ) ;
if ( ! V_191 || V_191 -> V_4 . V_63 == V_64 ) {
V_192 = - V_209 ;
break;
}
V_191 -> V_77 = 1 ;
V_192 = 0 ;
* V_28 = 0 ;
}
break;
case V_215 :
if ( V_190 -> V_199 == V_200 ) {
V_192 = 0 ;
switch ( V_194 ) {
case V_100 :
V_194 = V_100 ;
break;
case V_207 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_194 = V_208 ;
else
V_192 = - V_209 ;
break;
case V_210 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_194 = V_211 ;
else
V_192 = - V_209 ;
break;
case V_212 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_194 = V_213 ;
else
V_192 = - V_209 ;
break;
default:
V_192 = - V_209 ;
break;
}
if ( V_192 == 0 ) {
V_13 -> V_98 &= ~ ( 1 << V_194 ) ;
* V_28 = 0 ;
}
} else if ( V_190 -> V_199 == V_214 ) {
V_191 = F_106 ( V_13 , V_193 ) ;
if ( ! V_191 ) {
V_192 = - V_209 ;
break;
}
if ( ! V_191 -> V_78 )
V_191 -> V_77 = 0 ;
V_192 = 0 ;
* V_28 = 0 ;
}
break;
case V_216 :
if ( V_190 -> V_199 == V_217
|| V_190 -> V_199 == V_218
|| V_190 -> V_199 == V_219 ) {
char * V_88 ;
V_88 = ( char * ) V_142 -> V_169 ;
if ( V_142 -> V_183 > 0 ) {
if ( V_190 -> V_199 == V_219 ) {
V_191 = F_106 ( V_13 , V_193 ) ;
if ( ! V_191 ) {
V_192 = - V_209 ;
break;
}
V_88 [ 0 ] = V_191 -> V_77 ;
} else if ( V_190 -> V_199 ==
V_217 ) {
V_88 [ 0 ] = ( V_111 ) V_13 -> V_98 ;
} else
V_88 [ 0 ] = 0 ;
}
if ( V_142 -> V_183 > 1 )
V_88 [ 1 ] = 0 ;
V_142 -> V_170 = F_55 ( T_4 , 2 ,
V_142 -> V_183 ) ;
V_192 = 0 ;
* V_28 = 0 ;
}
break;
}
return V_192 ;
}
static void F_110 ( unsigned long V_220 )
{
struct V_9 * V_33 = (struct V_9 * ) V_220 ;
struct V_17 * V_13 = V_33 -> V_13 ;
struct V_149 * V_149 , * V_188 ;
unsigned long V_79 ;
int V_177 , V_221 ;
int V_119 ;
switch ( V_13 -> V_18 . V_22 ) {
case V_222 :
V_221 = 8 * 12 ;
break;
case V_71 :
V_221 = 64 * 19 ;
break;
case V_70 :
V_221 = 512 * 13 * 8 ;
break;
case V_23 :
V_221 = 490000 ;
break;
default:
F_27 ( F_6 ( V_33 ) , L_25 ) ;
return;
}
F_30 ( & V_13 -> V_30 , V_79 ) ;
if ( ! V_33 -> V_152 ) {
F_27 ( F_6 ( V_33 ) ,
L_26 ) ;
F_31 ( & V_13 -> V_30 , V_79 ) ;
return;
}
for ( V_119 = 0 ; V_119 < V_121 ; V_119 ++ ) {
if ( ! V_122 [ V_119 ] )
break;
V_13 -> V_4 [ V_119 ] . V_125 = 0 ;
}
V_223:
F_111 (urbp, tmp, &dum_hcd->urbp_list, urbp_list) {
struct V_142 * V_142 ;
struct V_5 * V_8 ;
V_111 V_32 ;
struct V_1 * V_4 = NULL ;
int type ;
int V_28 = - V_81 ;
V_142 = V_149 -> V_142 ;
if ( V_142 -> V_224 )
goto V_225;
else if ( V_33 -> V_45 != V_158 )
continue;
type = F_93 ( V_142 -> V_144 ) ;
if ( V_221 <= 0 && type == V_226 )
continue;
V_32 = F_83 ( V_142 -> V_144 ) ;
if ( F_98 ( V_142 -> V_144 ) )
V_32 |= V_84 ;
V_4 = F_106 ( V_13 , V_32 ) ;
if ( ! V_4 ) {
F_28 ( F_6 ( V_33 ) ,
L_27 ,
V_142 ) ;
V_28 = - V_227 ;
goto V_225;
}
if ( V_4 -> V_125 )
continue;
V_4 -> V_125 = 1 ;
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_142 -> V_156 ) {
V_4 -> V_126 = 1 ;
V_142 -> V_156 = 0 ;
}
if ( V_4 -> V_77 && ! V_4 -> V_126 ) {
F_28 ( F_6 ( V_33 ) , L_28 ,
V_4 -> V_4 . V_63 , V_142 ) ;
V_28 = - V_228 ;
goto V_225;
}
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_4 -> V_126 ) {
struct V_189 V_190 ;
int V_92 = 1 ;
V_190 = * (struct V_189 * ) V_142 -> V_229 ;
F_18 (req, &ep->queue, queue) {
F_14 ( & V_8 -> V_26 ) ;
V_8 -> V_8 . V_28 = - V_184 ;
F_28 ( F_7 ( V_13 ) , L_29 ,
V_8 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_8 -> V_8 . V_31 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_16 ( & V_13 -> V_30 ) ;
V_4 -> V_125 = 0 ;
goto V_223;
}
V_4 -> V_128 = V_104 ;
V_4 -> V_126 = 0 ;
V_4 -> V_77 = 0 ;
V_92 = F_108 ( V_33 , V_142 , & V_190 ,
& V_28 ) ;
if ( V_92 > 0 ) {
F_15 ( & V_13 -> V_30 ) ;
V_92 = V_13 -> V_54 -> V_190 ( & V_13 -> V_18 ,
& V_190 ) ;
F_16 ( & V_13 -> V_30 ) ;
if ( V_92 >= 0 ) {
V_177 = 64 * 1024 ;
goto V_230;
}
}
if ( V_92 < 0 ) {
if ( V_92 != - V_209 )
F_28 ( F_7 ( V_13 ) ,
L_30 ,
V_92 ) ;
V_28 = - V_228 ;
V_142 -> V_170 = 0 ;
}
goto V_225;
}
V_177 = V_221 ;
switch ( F_93 ( V_142 -> V_144 ) ) {
case V_231 :
V_177 = V_61 ( V_177 , F_105 ( V_13 , V_4 ) ) ;
V_28 = - V_232 ;
break;
case V_233 :
V_177 = V_61 ( V_177 , F_105 ( V_13 , V_4 ) ) ;
default:
V_230:
V_4 -> V_128 = V_104 ;
V_221 = F_103 ( V_33 , V_142 , V_4 , V_177 , & V_28 ) ;
break;
}
if ( V_28 == - V_81 )
continue;
V_225:
F_112 ( & V_149 -> V_153 ) ;
F_37 ( V_149 ) ;
if ( V_4 )
V_4 -> V_125 = V_4 -> V_126 = 0 ;
F_113 ( F_5 ( V_33 ) , V_142 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_114 ( F_5 ( V_33 ) , V_142 , V_28 ) ;
F_16 ( & V_13 -> V_30 ) ;
goto V_223;
}
if ( F_12 ( & V_33 -> V_153 ) ) {
F_115 ( V_33 -> V_152 ) ;
V_33 -> V_152 = NULL ;
} else if ( V_33 -> V_45 == V_158 ) {
F_51 ( & V_33 -> V_157 , V_104 + F_50 ( 1 ) ) ;
}
F_31 ( & V_13 -> V_30 , V_79 ) ;
}
static int F_116 ( struct V_10 * V_11 , char * V_88 )
{
struct V_9 * V_33 ;
unsigned long V_79 ;
int V_62 = 0 ;
V_33 = F_4 ( V_11 ) ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
if ( ! F_117 ( V_11 ) )
goto V_69;
if ( V_33 -> V_52 && F_118 ( V_104 , V_33 -> V_103 ) ) {
V_33 -> V_35 |= ( V_234 << 16 ) ;
V_33 -> V_35 &= ~ V_51 ;
F_20 ( V_33 ) ;
}
if ( ( V_33 -> V_35 & V_235 ) != 0 ) {
* V_88 = ( 1 << 1 ) ;
F_28 ( F_6 ( V_33 ) , L_31 ,
V_33 -> V_35 ) ;
V_62 = 1 ;
if ( V_33 -> V_45 == V_46 )
F_119 ( V_11 ) ;
}
V_69:
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_62 ;
}
static inline void
F_120 ( struct V_236 * V_60 )
{
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_65 = 0x2a ;
V_60 -> V_237 = 12 ;
V_60 -> V_238 = F_121 ( 0x0001 ) ;
V_60 -> V_239 = 1 ;
V_60 -> V_240 . V_241 . V_242 = 0x04 ;
V_60 -> V_240 . V_241 . V_243 = 0xffff ;
}
static inline void F_122 ( struct V_236 * V_60 )
{
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_65 = 0x29 ;
V_60 -> V_237 = 9 ;
V_60 -> V_238 = F_121 ( 0x0001 ) ;
V_60 -> V_239 = 1 ;
V_60 -> V_240 . V_244 . V_243 [ 0 ] = 0xff ;
V_60 -> V_240 . V_244 . V_243 [ 1 ] = 0xff ;
}
static int F_123 (
struct V_10 * V_11 ,
T_5 V_245 ,
T_5 V_196 ,
T_5 V_195 ,
char * V_88 ,
T_5 V_246
) {
struct V_9 * V_33 ;
int V_62 = 0 ;
unsigned long V_79 ;
if ( ! F_117 ( V_11 ) )
return - V_247 ;
V_33 = F_4 ( V_11 ) ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
switch ( V_245 ) {
case V_248 :
break;
case V_249 :
switch ( V_196 ) {
case V_250 :
if ( V_11 -> V_22 == V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_32
L_33 ) ;
goto error;
}
if ( V_33 -> V_35 & V_51 ) {
V_33 -> V_52 = 1 ;
V_33 -> V_103 = V_104 +
F_50 ( 20 ) ;
}
break;
case V_251 :
if ( V_11 -> V_22 == V_34 ) {
if ( V_33 -> V_35 & V_48 )
F_28 ( F_6 ( V_33 ) ,
L_34 ) ;
} else
if ( V_33 -> V_35 &
V_36 )
F_28 ( F_6 ( V_33 ) ,
L_34 ) ;
default:
V_33 -> V_35 &= ~ ( 1 << V_196 ) ;
F_20 ( V_33 ) ;
}
break;
case V_252 :
if ( V_11 -> V_22 == V_34 &&
( V_246 < V_253 ||
V_196 != ( V_254 << 8 ) ) ) {
F_28 ( F_6 ( V_33 ) ,
L_35
L_36 ) ;
goto error;
}
if ( V_11 -> V_22 == V_34 )
F_120 ( (struct V_236 * ) V_88 ) ;
else
F_122 ( (struct V_236 * ) V_88 ) ;
break;
case V_255 | V_256 :
if ( V_11 -> V_22 != V_34 )
goto error;
if ( ( V_196 >> 8 ) != V_257 )
goto error;
memcpy ( V_88 , & V_258 , sizeof( V_258 ) ) ;
V_62 = sizeof( V_258 ) ;
break;
case V_259 :
* ( V_260 * ) V_88 = F_124 ( 0 ) ;
break;
case V_261 :
if ( V_195 != 1 )
V_62 = - V_228 ;
if ( V_33 -> V_52 &&
F_118 ( V_104 , V_33 -> V_103 ) ) {
V_33 -> V_35 |= ( V_234 << 16 ) ;
V_33 -> V_35 &= ~ V_51 ;
}
if ( ( V_33 -> V_35 & V_53 ) != 0 &&
F_118 ( V_104 , V_33 -> V_103 ) ) {
V_33 -> V_35 |= ( V_262 << 16 ) ;
V_33 -> V_35 &= ~ V_53 ;
if ( V_33 -> V_13 -> V_37 ) {
V_33 -> V_35 |= V_40 ;
if ( V_11 -> V_22 < V_34 ) {
switch ( V_33 -> V_13 -> V_18 . V_22 ) {
case V_70 :
V_33 -> V_35 |=
V_50 ;
break;
case V_222 :
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
( ( V_263 * ) V_88 ) [ 0 ] = F_121 ( V_33 -> V_35 ) ;
( ( V_263 * ) V_88 ) [ 1 ] = F_121 ( V_33 -> V_35 >> 16 ) ;
break;
case V_264 :
V_62 = - V_228 ;
break;
case V_265 :
switch ( V_196 ) {
case V_266 :
if ( V_11 -> V_22 != V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_37
L_38 ) ;
goto error;
}
break;
case V_267 :
case V_268 :
if ( V_11 -> V_22 != V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_39
L_38 ) ;
goto error;
}
break;
case V_250 :
if ( V_11 -> V_22 == V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_32
L_33 ) ;
goto error;
}
if ( V_33 -> V_47 ) {
V_33 -> V_35 |= V_51 ;
F_20 ( V_33 ) ;
if ( ( ( 1 << V_99 )
& V_33 -> V_13 -> V_98 ) != 0 )
F_28 ( F_6 ( V_33 ) ,
L_40 ) ;
}
break;
case V_251 :
if ( V_11 -> V_22 == V_34 )
V_33 -> V_35 |= V_36 ;
else
V_33 -> V_35 |= V_48 ;
F_20 ( V_33 ) ;
break;
case V_269 :
if ( V_11 -> V_22 != V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_41
L_38 ) ;
goto error;
}
case V_270 :
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
V_33 -> V_35 |= ( 1 << V_196 ) ;
F_20 ( V_33 ) ;
}
} else
if ( ( V_33 -> V_35 &
V_48 ) != 0 ) {
V_33 -> V_35 |= ( 1 << V_196 ) ;
F_20 ( V_33 ) ;
}
}
break;
case V_271 :
if ( V_11 -> V_22 != V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_42
L_38 ) ;
goto error;
}
* ( V_260 * ) V_88 = F_124 ( 0 ) ;
break;
case V_272 :
if ( V_11 -> V_22 != V_34 ) {
F_28 ( F_6 ( V_33 ) ,
L_43
L_44 ) ;
goto error;
}
break;
default:
F_28 ( F_6 ( V_33 ) ,
L_45 ,
V_245 , V_196 , V_195 , V_246 ) ;
error:
V_62 = - V_228 ;
}
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
if ( ( V_33 -> V_35 & V_235 ) != 0 )
F_57 ( V_11 ) ;
return V_62 ;
}
static int F_125 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
F_28 ( & V_11 -> V_15 . V_273 -> V_19 , L_19 , V_140 ) ;
F_74 ( & V_33 -> V_13 -> V_30 ) ;
V_33 -> V_45 = V_46 ;
F_20 ( V_33 ) ;
V_11 -> V_139 = V_274 ;
F_75 ( & V_33 -> V_13 -> V_30 ) ;
return 0 ;
}
static int F_126 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
int V_133 = 0 ;
F_28 ( & V_11 -> V_15 . V_273 -> V_19 , L_19 , V_140 ) ;
F_74 ( & V_33 -> V_13 -> V_30 ) ;
if ( ! F_117 ( V_11 ) ) {
V_133 = - V_29 ;
} else {
V_33 -> V_45 = V_158 ;
F_20 ( V_33 ) ;
if ( ! F_12 ( & V_33 -> V_153 ) )
F_51 ( & V_33 -> V_157 , V_104 ) ;
V_11 -> V_139 = V_275 ;
}
F_75 ( & V_33 -> V_13 -> V_30 ) ;
return V_133 ;
}
static inline T_2 F_127 ( char * V_88 , T_6 V_276 , struct V_142 * V_142 )
{
int V_4 = F_83 ( V_142 -> V_144 ) ;
return snprintf (buf, size,
L_46 ,
urb,
({ char *s;
switch (urb->dev->speed) {
case USB_SPEED_LOW:
s = L_47;
break;
case USB_SPEED_FULL:
s = L_48;
break;
case USB_SPEED_HIGH:
s = L_49;
break;
case USB_SPEED_SUPER:
s = L_50;
break;
default:
s = L_51;
break;
} s; }),
ep, ep ? (usb_pipein(urb->pipe) ? L_7 : L_8) : L_52 ,
({ char *s; \
switch (usb_pipetype(urb->pipe)) { \
case PIPE_CONTROL: \
s = L_52; \
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
} s; }),
urb->actual_length, urb->transfer_buffer_length) ;
}
static T_2 F_128 ( struct V_14 * V_19 , struct V_112 * V_113 ,
char * V_88 )
{
struct V_10 * V_11 = F_129 ( V_19 ) ;
struct V_9 * V_33 = F_4 ( V_11 ) ;
struct V_149 * V_149 ;
T_6 V_276 = 0 ;
unsigned long V_79 ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
F_18 (urbp, &dum_hcd->urbp_list, urbp_list) {
T_6 V_277 ;
V_277 = F_127 ( V_88 , V_115 - V_276 , V_149 -> V_142 ) ;
V_88 += V_277 ;
V_276 += V_277 ;
}
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_276 ;
}
static int F_130 ( struct V_9 * V_33 )
{
F_131 ( & V_33 -> V_157 ) ;
V_33 -> V_157 . V_114 = F_110 ;
V_33 -> V_157 . V_278 = ( unsigned long ) V_33 ;
V_33 -> V_45 = V_158 ;
V_33 -> V_143 = 0 ;
F_34 ( & V_33 -> V_153 ) ;
F_5 ( V_33 ) -> V_279 = V_280 ;
F_5 ( V_33 ) -> V_139 = V_275 ;
F_5 ( V_33 ) -> V_281 = 1 ;
#ifdef F_63
F_5 ( V_33 ) -> V_15 . V_282 = 1 ;
#endif
return 0 ;
return F_67 ( F_6 ( V_33 ) , & V_283 ) ;
}
static int F_132 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
if ( ! F_133 ( V_11 ) )
return F_130 ( V_33 ) ;
F_134 ( & V_33 -> V_13 -> V_30 ) ;
F_131 ( & V_33 -> V_157 ) ;
V_33 -> V_157 . V_114 = F_110 ;
V_33 -> V_157 . V_278 = ( unsigned long ) V_33 ;
V_33 -> V_45 = V_158 ;
F_34 ( & V_33 -> V_153 ) ;
V_11 -> V_279 = V_280 ;
V_11 -> V_139 = V_275 ;
V_11 -> V_281 = 1 ;
#ifdef F_63
V_11 -> V_15 . V_282 = 1 ;
#endif
return F_67 ( F_6 ( V_33 ) , & V_283 ) ;
}
static void F_135 ( struct V_10 * V_11 )
{
struct V_17 * V_13 ;
V_13 = F_4 ( V_11 ) -> V_13 ;
F_72 ( F_6 ( F_4 ( V_11 ) ) , & V_283 ) ;
F_136 ( V_13 -> V_54 ) ;
F_137 ( F_6 ( F_4 ( V_11 ) ) , L_53 ) ;
}
static int F_138 ( struct V_10 * V_11 )
{
return F_47 ( NULL ) ;
}
static int F_139 ( struct V_10 * V_11 )
{
struct V_17 * V_13 ;
V_13 = * ( ( void * * ) F_65 ( V_11 -> V_15 . V_16 ) ) ;
V_11 -> V_15 . V_284 = ~ 0 ;
if ( F_133 ( V_11 ) ) {
V_13 -> V_25 = F_4 ( V_11 ) ;
V_13 -> V_25 -> V_13 = V_13 ;
V_11 -> V_22 = V_285 ;
V_11 -> V_15 . V_273 -> V_22 = V_70 ;
} else {
V_13 -> V_24 = F_4 ( V_11 ) ;
V_13 -> V_24 -> V_13 = V_13 ;
V_11 -> V_22 = V_34 ;
V_11 -> V_15 . V_273 -> V_22 = V_23 ;
}
return 0 ;
}
static int F_140 ( struct V_10 * V_11 , struct V_286 * V_152 ,
struct V_287 * * V_288 , unsigned int V_289 ,
unsigned int V_290 , T_1 V_80 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
unsigned long V_79 ;
int V_291 ;
int V_292 = V_290 ;
unsigned int V_141 ;
unsigned int V_119 ;
if ( ! V_289 )
return - V_67 ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
for ( V_119 = 0 ; V_119 < V_289 ; V_119 ++ ) {
V_141 = F_78 ( & V_288 [ V_119 ] -> V_60 ) ;
if ( ( 1 << V_141 ) & V_33 -> V_143 ) {
V_292 = - V_67 ;
goto V_293;
}
V_291 = F_25 ( & V_288 [ V_119 ] -> V_294 ) ;
if ( ! V_291 ) {
V_292 = - V_67 ;
goto V_293;
}
if ( V_291 < V_292 ) {
F_28 ( F_6 ( V_33 ) , L_54
L_55 ,
V_288 [ V_119 ] -> V_60 . V_83 ,
V_291 ) ;
V_292 = V_291 ;
}
}
for ( V_119 = 0 ; V_119 < V_289 ; V_119 ++ ) {
V_141 = F_78 ( & V_288 [ V_119 ] -> V_60 ) ;
V_33 -> V_143 |= 1 << V_141 ;
F_85 ( V_33 ,
F_79 ( & V_288 [ V_119 ] -> V_60 ) , V_292 ) ;
}
V_293:
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_292 ;
}
static int F_141 ( struct V_10 * V_11 , struct V_286 * V_152 ,
struct V_287 * * V_288 , unsigned int V_289 ,
T_1 V_80 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
unsigned long V_79 ;
int V_295 ;
unsigned int V_141 ;
unsigned int V_119 ;
F_30 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
for ( V_119 = 0 ; V_119 < V_289 ; V_119 ++ ) {
V_141 = F_78 ( & V_288 [ V_119 ] -> V_60 ) ;
if ( ! ( ( 1 << V_141 ) & V_33 -> V_143 ) ) {
V_295 = - V_67 ;
goto V_293;
}
}
for ( V_119 = 0 ; V_119 < V_289 ; V_119 ++ ) {
V_141 = F_78 ( & V_288 [ V_119 ] -> V_60 ) ;
V_33 -> V_143 &= ~ ( 1 << V_141 ) ;
F_85 ( V_33 ,
F_79 ( & V_288 [ V_119 ] -> V_60 ) , 0 ) ;
}
V_295 = 0 ;
V_293:
F_31 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_295 ;
}
static int F_142 ( struct V_131 * V_132 )
{
struct V_17 * V_13 ;
struct V_10 * V_25 ;
struct V_10 * V_24 ;
int V_62 ;
F_137 ( & V_132 -> V_19 , L_56 V_296 L_57 , V_297 ) ;
V_13 = * ( ( void * * ) F_65 ( & V_132 -> V_19 ) ) ;
if ( ! V_107 . V_108 )
V_9 . V_79 = V_285 ;
V_25 = F_143 ( & V_9 , & V_132 -> V_19 , F_144 ( & V_132 -> V_19 ) ) ;
if ( ! V_25 )
return - V_150 ;
V_25 -> V_298 = 1 ;
V_62 = F_145 ( V_25 , 0 , 0 ) ;
if ( V_62 )
goto V_299;
if ( V_107 . V_108 ) {
V_24 = F_146 ( & V_9 , & V_132 -> V_19 ,
F_144 ( & V_132 -> V_19 ) , V_25 ) ;
if ( ! V_24 ) {
V_62 = - V_150 ;
goto V_300;
}
V_62 = F_145 ( V_24 , 0 , 0 ) ;
if ( V_62 )
goto V_301;
}
return 0 ;
V_301:
F_147 ( V_24 ) ;
V_300:
F_148 ( V_25 ) ;
V_299:
F_147 ( V_25 ) ;
V_13 -> V_25 = V_13 -> V_24 = NULL ;
return V_62 ;
}
static int F_149 ( struct V_131 * V_132 )
{
struct V_17 * V_13 ;
V_13 = F_4 ( F_71 ( V_132 ) ) -> V_13 ;
if ( V_13 -> V_24 ) {
F_148 ( F_5 ( V_13 -> V_24 ) ) ;
F_147 ( F_5 ( V_13 -> V_24 ) ) ;
}
F_148 ( F_5 ( V_13 -> V_25 ) ) ;
F_147 ( F_5 ( V_13 -> V_25 ) ) ;
V_13 -> V_25 = NULL ;
V_13 -> V_24 = NULL ;
return 0 ;
}
static int F_150 ( struct V_131 * V_132 , T_3 V_139 )
{
struct V_10 * V_11 ;
struct V_9 * V_33 ;
int V_133 = 0 ;
F_28 ( & V_132 -> V_19 , L_19 , V_140 ) ;
V_11 = F_71 ( V_132 ) ;
V_33 = F_4 ( V_11 ) ;
if ( V_33 -> V_45 == V_158 ) {
F_151 ( & V_132 -> V_19 , L_58 ) ;
V_133 = - V_302 ;
} else
F_152 ( V_303 , & V_11 -> V_79 ) ;
return V_133 ;
}
static int F_153 ( struct V_131 * V_132 )
{
struct V_10 * V_11 ;
F_28 ( & V_132 -> V_19 , L_19 , V_140 ) ;
V_11 = F_71 ( V_132 ) ;
F_154 ( V_303 , & V_11 -> V_79 ) ;
F_57 ( V_11 ) ;
return 0 ;
}
static int T_7 F_155 ( void )
{
int V_62 = - V_150 ;
int V_119 ;
struct V_17 * V_13 [ V_304 ] ;
if ( F_156 () )
return - V_305 ;
if ( ! V_107 . V_110 && V_107 . V_108 )
return - V_67 ;
if ( V_107 . V_306 < 1 || V_107 . V_306 > V_304 ) {
F_157 ( L_59 ,
V_304 ) ;
return - V_67 ;
}
for ( V_119 = 0 ; V_119 < V_107 . V_306 ; V_119 ++ ) {
V_307 [ V_119 ] = F_158 ( V_308 , V_119 ) ;
if ( ! V_307 [ V_119 ] ) {
V_119 -- ;
while ( V_119 >= 0 )
F_159 ( V_307 [ V_119 -- ] ) ;
return V_62 ;
}
}
for ( V_119 = 0 ; V_119 < V_107 . V_306 ; V_119 ++ ) {
V_309 [ V_119 ] = F_158 ( V_134 , V_119 ) ;
if ( ! V_309 [ V_119 ] ) {
V_119 -- ;
while ( V_119 >= 0 )
F_159 ( V_309 [ V_119 -- ] ) ;
goto V_310;
}
}
for ( V_119 = 0 ; V_119 < V_107 . V_306 ; V_119 ++ ) {
V_13 [ V_119 ] = F_33 ( sizeof( struct V_17 ) , V_311 ) ;
if ( ! V_13 [ V_119 ] ) {
V_62 = - V_150 ;
goto V_312;
}
V_62 = F_160 ( V_307 [ V_119 ] , & V_13 [ V_119 ] ,
sizeof( void * ) ) ;
if ( V_62 )
goto V_312;
V_62 = F_160 ( V_309 [ V_119 ] , & V_13 [ V_119 ] ,
sizeof( void * ) ) ;
if ( V_62 )
goto V_312;
}
V_62 = F_161 ( & V_313 ) ;
if ( V_62 < 0 )
goto V_312;
V_62 = F_161 ( & V_314 ) ;
if ( V_62 < 0 )
goto V_315;
for ( V_119 = 0 ; V_119 < V_107 . V_306 ; V_119 ++ ) {
V_62 = F_162 ( V_307 [ V_119 ] ) ;
if ( V_62 < 0 ) {
V_119 -- ;
while ( V_119 >= 0 )
F_163 ( V_307 [ V_119 -- ] ) ;
goto V_316;
}
}
for ( V_119 = 0 ; V_119 < V_107 . V_306 ; V_119 ++ ) {
if ( ! V_13 [ V_119 ] -> V_25 ||
( ! V_13 [ V_119 ] -> V_24 && V_107 . V_108 ) ) {
V_62 = - V_67 ;
goto V_317;
}
}
for ( V_119 = 0 ; V_119 < V_107 . V_306 ; V_119 ++ ) {
V_62 = F_162 ( V_309 [ V_119 ] ) ;
if ( V_62 < 0 ) {
V_119 -- ;
while ( V_119 >= 0 )
F_163 ( V_309 [ V_119 ] ) ;
goto V_317;
}
}
for ( V_119 = 0 ; V_119 < V_107 . V_306 ; V_119 ++ ) {
if ( ! F_71 ( V_309 [ V_119 ] ) ) {
V_62 = - V_67 ;
goto V_318;
}
}
return V_62 ;
V_318:
for ( V_119 = 0 ; V_119 < V_107 . V_306 ; V_119 ++ )
F_163 ( V_309 [ V_119 ] ) ;
V_317:
for ( V_119 = 0 ; V_119 < V_107 . V_306 ; V_119 ++ )
F_163 ( V_307 [ V_119 ] ) ;
V_316:
F_164 ( & V_314 ) ;
V_315:
F_164 ( & V_313 ) ;
V_312:
for ( V_119 = 0 ; V_119 < V_107 . V_306 ; V_119 ++ )
F_37 ( V_13 [ V_119 ] ) ;
for ( V_119 = 0 ; V_119 < V_107 . V_306 ; V_119 ++ )
F_159 ( V_309 [ V_119 ] ) ;
V_310:
for ( V_119 = 0 ; V_119 < V_107 . V_306 ; V_119 ++ )
F_159 ( V_307 [ V_119 ] ) ;
return V_62 ;
}
static void T_8 F_165 ( void )
{
int V_119 ;
for ( V_119 = 0 ; V_119 < V_107 . V_306 ; V_119 ++ ) {
struct V_17 * V_13 ;
V_13 = * ( ( void * * ) F_65 ( & V_309 [ V_119 ] -> V_19 ) ) ;
F_166 ( V_309 [ V_119 ] ) ;
F_166 ( V_307 [ V_119 ] ) ;
F_37 ( V_13 ) ;
}
F_164 ( & V_314 ) ;
F_164 ( & V_313 ) ;
}
