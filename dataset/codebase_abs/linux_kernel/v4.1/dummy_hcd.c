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
F_16 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_17 ( & V_13 -> V_30 ) ;
}
}
static void F_18 ( struct V_17 * V_13 )
{
struct V_1 * V_4 ;
V_13 -> V_31 = 0 ;
F_19 (ep, &dum->gadget.ep_list, ep.ep_list)
F_11 ( V_13 , V_4 ) ;
}
static void F_20 ( struct V_9 * V_32 )
{
struct V_17 * V_13 = V_32 -> V_13 ;
if ( F_5 ( V_32 ) -> V_22 == V_33 ) {
if ( ( V_32 -> V_34 & V_35 ) == 0 ) {
V_32 -> V_34 = 0 ;
} else if ( ! V_13 -> V_36 || V_13 -> V_37 ) {
V_32 -> V_34 &= ~ ( V_38 |
V_39 ) ;
if ( ( V_32 -> V_40 &
V_38 ) != 0 )
V_32 -> V_34 |=
( V_41 << 16 ) ;
} else {
V_32 -> V_34 |= ( V_38 |
V_42 ) ;
if ( ( V_32 -> V_40 &
V_38 ) == 0 )
V_32 -> V_34 |=
( V_41 << 16 ) ;
if ( ( V_32 -> V_34 &
V_39 ) == 1 &&
( V_32 -> V_34 &
V_43 ) == 1 &&
V_32 -> V_44 != V_45 )
V_32 -> V_46 = 1 ;
}
} else {
if ( ( V_32 -> V_34 & V_47 ) == 0 ) {
V_32 -> V_34 = 0 ;
} else if ( ! V_13 -> V_36 || V_13 -> V_37 ) {
V_32 -> V_34 &= ~ ( V_38 |
V_39 |
V_48 |
V_49 |
V_50 ) ;
if ( ( V_32 -> V_40 &
V_38 ) != 0 )
V_32 -> V_34 |=
( V_41 << 16 ) ;
} else {
V_32 -> V_34 |= V_38 ;
if ( ( V_32 -> V_40 &
V_38 ) == 0 )
V_32 -> V_34 |=
( V_41 << 16 ) ;
if ( ( V_32 -> V_34 & V_39 ) == 0 )
V_32 -> V_34 &= ~ V_50 ;
else if ( ( V_32 -> V_34 &
V_50 ) == 0 &&
V_32 -> V_44 != V_45 )
V_32 -> V_46 = 1 ;
}
}
}
static void F_21 ( struct V_9 * V_32 )
{
struct V_17 * V_13 = V_32 -> V_13 ;
V_32 -> V_46 = 0 ;
if ( V_13 -> V_36 )
if ( ( F_5 ( V_32 ) -> V_22 == V_33 &&
V_13 -> V_18 . V_22 != V_23 ) ||
( F_5 ( V_32 ) -> V_22 != V_33 &&
V_13 -> V_18 . V_22 == V_23 ) )
return;
F_20 ( V_32 ) ;
if ( ( V_32 -> V_34 & V_39 ) == 0 ||
V_32 -> V_46 )
V_32 -> V_51 = 0 ;
if ( ( V_32 -> V_34 & V_38 ) == 0 ||
( V_32 -> V_34 & V_52 ) != 0 ) {
unsigned V_53 = V_38 &
V_32 -> V_40 & ( ~ V_32 -> V_34 ) ;
unsigned V_54 = V_52 &
( ~ V_32 -> V_40 ) & V_32 -> V_34 ;
if ( V_13 -> V_55 && ( V_53 || V_54 ) ) {
F_18 ( V_13 ) ;
F_15 ( & V_13 -> V_30 ) ;
if ( V_54 )
F_22 ( & V_13 -> V_18 , V_13 -> V_55 ) ;
else
V_13 -> V_55 -> V_53 ( & V_13 -> V_18 ) ;
F_17 ( & V_13 -> V_30 ) ;
}
} else if ( V_32 -> V_46 != V_32 -> V_56 ) {
if ( V_32 -> V_56 && V_13 -> V_55 -> V_57 ) {
F_15 ( & V_13 -> V_30 ) ;
V_13 -> V_55 -> V_57 ( & V_13 -> V_18 ) ;
F_17 ( & V_13 -> V_30 ) ;
} else if ( ! V_32 -> V_56 && V_13 -> V_55 -> V_58 ) {
F_15 ( & V_13 -> V_30 ) ;
V_13 -> V_55 -> V_58 ( & V_13 -> V_18 ) ;
F_17 ( & V_13 -> V_30 ) ;
}
}
V_32 -> V_40 = V_32 -> V_34 ;
V_32 -> V_56 = V_32 -> V_46 ;
}
static int F_23 ( struct V_2 * V_3 ,
const struct V_59 * V_60 )
{
struct V_17 * V_13 ;
struct V_9 * V_32 ;
struct V_1 * V_4 ;
unsigned V_61 ;
int V_62 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_60 || V_4 -> V_60 || V_3 -> V_63 == V_64
|| V_60 -> V_65 != V_66 )
return - V_67 ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_55 )
return - V_29 ;
V_32 = F_9 ( & V_13 -> V_18 ) ;
if ( ! F_24 ( V_32 ) )
return - V_29 ;
V_61 = F_25 ( V_60 ) & 0x7ff ;
V_62 = - V_67 ;
switch ( F_26 ( V_60 ) ) {
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
if ( F_27 ( V_3 -> V_75 ) ) {
if ( ! F_28 ( V_60 ) ) {
F_29 ( F_7 ( V_13 ) , L_4
L_5 , V_3 -> V_63 ) ;
return - V_67 ;
}
V_4 -> V_76 = 1 ;
}
V_4 -> V_60 = V_60 ;
F_30 (udc_dev(dum), L_6 ,
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
static int F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
unsigned long V_79 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_4 -> V_60 || V_3 -> V_63 == V_64 )
return - V_67 ;
V_13 = F_8 ( V_4 ) ;
F_32 ( & V_13 -> V_30 , V_79 ) ;
V_4 -> V_60 = NULL ;
V_4 -> V_76 = 0 ;
F_11 ( V_13 , V_4 ) ;
F_33 ( & V_13 -> V_30 , V_79 ) ;
F_30 ( F_7 ( V_13 ) , L_15 , V_3 -> V_63 ) ;
return 0 ;
}
static struct V_6 * F_34 ( struct V_2 * V_3 ,
T_1 V_80 )
{
struct V_1 * V_4 ;
struct V_5 * V_8 ;
if ( ! V_3 )
return NULL ;
V_4 = F_1 ( V_3 ) ;
V_8 = F_35 ( sizeof( * V_8 ) , V_80 ) ;
if ( ! V_8 )
return NULL ;
F_36 ( & V_8 -> V_26 ) ;
return & V_8 -> V_8 ;
}
static void F_37 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_5 * V_8 ;
if ( ! V_3 || ! V_7 ) {
F_38 ( 1 ) ;
return;
}
V_8 = F_3 ( V_7 ) ;
F_38 ( ! F_12 ( & V_8 -> V_26 ) ) ;
F_39 ( V_8 ) ;
}
static void F_40 ( struct V_2 * V_4 , struct V_6 * V_8 )
{
}
static int F_41 ( struct V_2 * V_3 , struct V_6 * V_7 ,
T_1 V_80 )
{
struct V_1 * V_4 ;
struct V_5 * V_8 ;
struct V_17 * V_13 ;
struct V_9 * V_32 ;
unsigned long V_79 ;
V_8 = F_3 ( V_7 ) ;
if ( ! V_7 || ! F_12 ( & V_8 -> V_26 ) || ! V_7 -> V_81 )
return - V_67 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ( ! V_4 -> V_60 && V_3 -> V_63 != V_64 ) )
return - V_67 ;
V_13 = F_8 ( V_4 ) ;
V_32 = F_9 ( & V_13 -> V_18 ) ;
if ( ! V_13 -> V_55 || ! F_24 ( V_32 ) )
return - V_29 ;
#if 0
dev_dbg(udc_dev(dum), "ep %p queue req %p to %s, len %d buf %p\n",
ep, _req, _ep->name, _req->length, _req->buf);
#endif
V_7 -> V_28 = - V_82 ;
V_7 -> V_83 = 0 ;
F_32 ( & V_13 -> V_30 , V_79 ) ;
if ( V_4 -> V_60 && ( V_4 -> V_60 -> V_84 & V_85 ) &&
F_12 ( & V_13 -> V_86 . V_26 ) &&
F_12 ( & V_4 -> V_26 ) &&
V_7 -> V_87 <= V_88 ) {
V_8 = & V_13 -> V_86 ;
V_8 -> V_8 = * V_7 ;
V_8 -> V_8 . V_89 = V_13 -> V_90 ;
memcpy ( V_13 -> V_90 , V_7 -> V_89 , V_7 -> V_87 ) ;
V_8 -> V_8 . V_91 = V_13 ;
V_8 -> V_8 . V_81 = F_40 ;
F_42 ( & V_8 -> V_26 , & V_4 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_7 -> V_83 = V_7 -> V_87 ;
V_7 -> V_28 = 0 ;
F_16 ( V_3 , V_7 ) ;
F_17 ( & V_13 -> V_30 ) ;
} else
F_42 ( & V_8 -> V_26 , & V_4 -> V_26 ) ;
F_33 ( & V_13 -> V_30 , V_79 ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_6 * V_7 )
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
if ( ! V_13 -> V_55 )
return - V_29 ;
F_44 ( V_79 ) ;
F_17 ( & V_13 -> V_30 ) ;
F_19 (req, &ep->queue, queue) {
if ( & V_8 -> V_8 == V_7 ) {
F_14 ( & V_8 -> V_26 ) ;
V_7 -> V_28 = - V_92 ;
V_62 = 0 ;
break;
}
}
F_15 ( & V_13 -> V_30 ) ;
if ( V_62 == 0 ) {
F_30 ( F_7 ( V_13 ) ,
L_16 ,
V_8 , V_3 -> V_63 , V_7 -> V_87 , V_7 -> V_89 ) ;
F_16 ( V_3 , V_7 ) ;
}
F_45 ( V_79 ) ;
return V_62 ;
}
static int
F_46 ( struct V_2 * V_3 , int V_93 , int V_78 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
if ( ! V_3 )
return - V_67 ;
V_4 = F_1 ( V_3 ) ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_55 )
return - V_29 ;
if ( ! V_93 )
V_4 -> V_77 = V_4 -> V_78 = 0 ;
else if ( V_4 -> V_60 && ( V_4 -> V_60 -> V_84 & V_85 ) &&
! F_12 ( & V_4 -> V_26 ) )
return - V_94 ;
else {
V_4 -> V_77 = 1 ;
if ( V_78 )
V_4 -> V_78 = 1 ;
}
return 0 ;
}
static int
F_47 ( struct V_2 * V_3 , int V_93 )
{
return F_46 ( V_3 , V_93 , 0 ) ;
}
static int F_48 ( struct V_2 * V_3 )
{
if ( ! V_3 || V_3 -> V_63 == V_64 )
return - V_67 ;
return F_46 ( V_3 , 1 , 1 ) ;
}
static int F_49 ( struct V_21 * V_95 )
{
struct V_96 V_97 ;
F_50 ( & V_97 ) ;
return V_97 . V_98 / 1000 ;
}
static int F_51 ( struct V_21 * V_95 )
{
struct V_9 * V_32 ;
V_32 = F_9 ( V_95 ) ;
if ( ! ( V_32 -> V_13 -> V_99 & ( ( 1 << V_100 )
| ( 1 << V_101 ) ) ) )
return - V_67 ;
if ( ( V_32 -> V_34 & V_38 ) == 0 )
return - V_102 ;
if ( ( V_32 -> V_34 & V_50 ) == 0 &&
V_32 -> V_44 != V_45 )
return - V_103 ;
V_32 -> V_51 = 1 ;
V_32 -> V_104 = V_105 + F_52 ( 20 ) ;
F_53 ( & F_5 ( V_32 ) -> V_106 , V_32 -> V_104 ) ;
return 0 ;
}
static int F_54 ( struct V_21 * V_95 , int V_93 )
{
struct V_17 * V_13 ;
V_95 -> V_107 = ( V_93 != 0 ) ;
V_13 = F_9 ( V_95 ) -> V_13 ;
if ( V_93 )
V_13 -> V_99 |= ( 1 << V_108 ) ;
else
V_13 -> V_99 &= ~ ( 1 << V_108 ) ;
return 0 ;
}
static void F_55 ( struct V_17 * V_13 )
{
if ( V_13 -> V_18 . V_22 == V_23 )
V_13 -> V_4 [ 0 ] . V_4 . V_74 = 9 ;
else
V_13 -> V_4 [ 0 ] . V_4 . V_74 = 64 ;
}
static int F_56 ( struct V_21 * V_95 , int V_93 )
{
struct V_9 * V_32 ;
struct V_17 * V_13 ;
unsigned long V_79 ;
V_13 = F_10 ( & V_95 -> V_19 ) ;
if ( V_93 && V_13 -> V_55 ) {
if ( V_109 . V_110 )
V_13 -> V_18 . V_22 = V_13 -> V_55 -> V_111 ;
else if ( V_109 . V_112 )
V_13 -> V_18 . V_22 = F_57 ( V_113 , V_70 ,
V_13 -> V_55 -> V_111 ) ;
else
V_13 -> V_18 . V_22 = V_71 ;
F_55 ( V_13 ) ;
if ( V_13 -> V_18 . V_22 < V_13 -> V_55 -> V_111 )
F_30 ( F_7 ( V_13 ) , L_17
L_18 ,
F_58 ( V_13 -> V_55 -> V_111 ) ) ;
}
V_32 = F_9 ( V_95 ) ;
F_32 ( & V_13 -> V_30 , V_79 ) ;
V_13 -> V_36 = ( V_93 != 0 ) ;
F_21 ( V_32 ) ;
F_33 ( & V_13 -> V_30 , V_79 ) ;
F_59 ( F_5 ( V_32 ) ) ;
return 0 ;
}
static T_2 F_60 ( struct V_14 * V_19 , struct V_114 * V_115 ,
char * V_89 )
{
struct V_17 * V_13 = F_10 ( V_19 ) ;
if ( ! V_13 -> V_55 || ! V_13 -> V_55 -> V_116 )
return 0 ;
return F_61 ( V_89 , V_117 , L_19 , V_13 -> V_55 -> V_116 ) ;
}
static int F_62 ( struct V_21 * V_118 ,
struct V_119 * V_55 )
{
struct V_9 * V_32 = F_9 ( V_118 ) ;
struct V_17 * V_13 = V_32 -> V_13 ;
if ( V_55 -> V_111 == V_120 )
return - V_67 ;
V_13 -> V_99 = 0 ;
V_13 -> V_55 = V_55 ;
return 0 ;
}
static int F_63 ( struct V_21 * V_118 )
{
struct V_9 * V_32 = F_9 ( V_118 ) ;
struct V_17 * V_13 = V_32 -> V_13 ;
V_13 -> V_55 = NULL ;
return 0 ;
}
static void F_64 ( struct V_17 * V_13 )
{
int V_121 ;
F_36 ( & V_13 -> V_18 . V_122 ) ;
for ( V_121 = 0 ; V_121 < V_123 ; V_121 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_121 ] ;
if ( ! V_124 [ V_121 ] )
break;
V_4 -> V_4 . V_63 = V_124 [ V_121 ] ;
V_4 -> V_4 . V_125 = & V_126 ;
F_42 ( & V_4 -> V_4 . V_122 , & V_13 -> V_18 . V_122 ) ;
V_4 -> V_77 = V_4 -> V_78 = V_4 -> V_127 =
V_4 -> V_128 = 0 ;
F_65 ( & V_4 -> V_4 , ~ 0 ) ;
V_4 -> V_4 . V_129 = 16 ;
V_4 -> V_130 = V_105 ;
V_4 -> V_18 = & V_13 -> V_18 ;
V_4 -> V_60 = NULL ;
F_36 ( & V_4 -> V_26 ) ;
}
V_13 -> V_18 . V_131 = & V_13 -> V_4 [ 0 ] . V_4 ;
F_14 ( & V_13 -> V_4 [ 0 ] . V_4 . V_122 ) ;
F_36 ( & V_13 -> V_86 . V_26 ) ;
#ifdef F_66
V_13 -> V_18 . V_132 = 1 ;
#endif
}
static int F_67 ( struct V_133 * V_134 )
{
struct V_17 * V_13 ;
int V_135 ;
V_13 = * ( ( void * * ) F_68 ( & V_134 -> V_19 ) ) ;
V_13 -> V_18 . V_63 = V_136 ;
V_13 -> V_18 . V_125 = & V_137 ;
V_13 -> V_18 . V_111 = V_23 ;
V_13 -> V_18 . V_19 . V_20 = & V_134 -> V_19 ;
F_64 ( V_13 ) ;
V_135 = F_69 ( & V_134 -> V_19 , & V_13 -> V_18 ) ;
if ( V_135 < 0 )
goto V_138;
V_135 = F_70 ( & V_13 -> V_18 . V_19 , & V_139 ) ;
if ( V_135 < 0 )
goto V_140;
F_71 ( V_134 , V_13 ) ;
return V_135 ;
V_140:
F_72 ( & V_13 -> V_18 ) ;
V_138:
return V_135 ;
}
static int F_73 ( struct V_133 * V_134 )
{
struct V_17 * V_13 = F_74 ( V_134 ) ;
F_75 ( & V_13 -> V_18 . V_19 , & V_139 ) ;
F_72 ( & V_13 -> V_18 ) ;
return 0 ;
}
static void F_76 ( struct V_17 * V_13 , struct V_9 * V_32 ,
int V_57 )
{
F_77 ( & V_13 -> V_30 ) ;
V_13 -> V_37 = V_57 ;
F_21 ( V_32 ) ;
F_78 ( & V_13 -> V_30 ) ;
}
static int F_79 ( struct V_133 * V_134 , T_3 V_141 )
{
struct V_17 * V_13 = F_74 ( V_134 ) ;
struct V_9 * V_32 = F_9 ( & V_13 -> V_18 ) ;
F_30 ( & V_134 -> V_19 , L_19 , V_142 ) ;
F_76 ( V_13 , V_32 , 1 ) ;
F_59 ( F_5 ( V_32 ) ) ;
return 0 ;
}
static int F_80 ( struct V_133 * V_134 )
{
struct V_17 * V_13 = F_74 ( V_134 ) ;
struct V_9 * V_32 = F_9 ( & V_13 -> V_18 ) ;
F_30 ( & V_134 -> V_19 , L_19 , V_142 ) ;
F_76 ( V_13 , V_32 , 0 ) ;
F_59 ( F_5 ( V_32 ) ) ;
return 0 ;
}
static unsigned int F_81 ( const struct V_59 * V_60 )
{
unsigned int V_143 ;
V_143 = F_82 ( V_60 ) << 1 ;
if ( F_83 ( V_60 ) )
V_143 |= 1 ;
return V_143 ;
}
static int F_84 ( struct V_9 * V_32 , struct V_144 * V_144 )
{
const struct V_59 * V_60 = & V_144 -> V_4 -> V_60 ;
T_4 V_143 ;
if ( ! F_28 ( V_60 ) )
return 0 ;
V_143 = F_81 ( V_60 ) ;
return ( 1 << V_143 ) & V_32 -> V_145 ;
}
static int F_85 ( struct V_9 * V_32 ,
unsigned int V_146 )
{
int V_129 ;
V_129 = V_32 -> V_147 [ F_86 ( V_146 ) ] ;
if ( F_87 ( V_146 ) )
V_129 >>= 4 ;
else
V_129 &= 0xf ;
V_129 ++ ;
return V_129 ;
}
static void F_88 ( struct V_9 * V_32 ,
unsigned int V_146 , unsigned int V_148 )
{
int V_129 ;
V_148 -- ;
V_129 = V_32 -> V_147 [ F_86 ( V_146 ) ] ;
if ( F_87 ( V_146 ) ) {
V_148 <<= 4 ;
V_129 &= 0xf ;
} else {
V_129 &= 0xf0 ;
}
V_129 |= V_148 ;
V_32 -> V_147 [ F_86 ( V_146 ) ] = V_129 ;
}
static int F_89 ( struct V_9 * V_32 , struct V_144 * V_144 )
{
unsigned int V_129 ;
int V_149 ;
V_149 = F_84 ( V_32 , V_144 ) ;
if ( ! V_144 -> V_150 ) {
if ( V_149 )
return - V_67 ;
return 0 ;
}
if ( ! V_149 )
return - V_67 ;
V_129 = F_85 ( V_32 ,
F_86 ( V_144 -> V_146 ) ) ;
if ( V_144 -> V_150 > V_129 ) {
F_29 ( F_6 ( V_32 ) , L_20 ,
V_144 -> V_150 ) ;
F_90 () ;
return - V_67 ;
}
return 0 ;
}
static int F_91 (
struct V_10 * V_11 ,
struct V_144 * V_144 ,
T_1 V_80
) {
struct V_9 * V_32 ;
struct V_151 * V_151 ;
unsigned long V_79 ;
int V_135 ;
V_151 = F_92 ( sizeof *V_151 , V_80 ) ;
if ( ! V_151 )
return - V_152 ;
V_151 -> V_144 = V_144 ;
V_151 -> V_153 = 0 ;
V_32 = F_4 ( V_11 ) ;
F_32 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
V_135 = F_89 ( V_32 , V_144 ) ;
if ( V_135 ) {
F_39 ( V_151 ) ;
goto V_69;
}
V_135 = F_93 ( V_11 , V_144 ) ;
if ( V_135 ) {
F_39 ( V_151 ) ;
goto V_69;
}
if ( ! V_32 -> V_154 ) {
V_32 -> V_154 = V_144 -> V_19 ;
F_94 ( V_32 -> V_154 ) ;
} else if ( F_95 ( V_32 -> V_154 != V_144 -> V_19 ) )
F_29 ( F_6 ( V_32 ) , L_21 ) ;
F_42 ( & V_151 -> V_155 , & V_32 -> V_155 ) ;
V_144 -> V_156 = V_151 ;
if ( F_96 ( V_144 -> V_146 ) == V_157 )
V_144 -> V_158 = 1 ;
if ( ! F_97 ( & V_32 -> V_159 ) )
F_53 ( & V_32 -> V_159 , V_105 + 1 ) ;
V_69:
F_33 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
return V_135 ;
}
static int F_98 ( struct V_10 * V_11 , struct V_144 * V_144 , int V_28 )
{
struct V_9 * V_32 ;
unsigned long V_79 ;
int V_135 ;
V_32 = F_4 ( V_11 ) ;
F_32 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
V_135 = F_99 ( V_11 , V_144 , V_28 ) ;
if ( ! V_135 && V_32 -> V_44 != V_160 &&
! F_12 ( & V_32 -> V_155 ) )
F_53 ( & V_32 -> V_159 , V_105 ) ;
F_33 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
return V_135 ;
}
static int F_100 ( struct V_144 * V_144 , struct V_5 * V_8 ,
T_4 V_161 )
{
void * V_162 , * V_163 ;
struct V_151 * V_151 = V_144 -> V_156 ;
int V_164 ;
struct V_165 * V_166 = & V_151 -> V_166 ;
T_4 V_167 = 0 ;
T_4 V_168 ;
bool V_169 ;
V_164 = F_101 ( V_144 -> V_146 ) ;
V_163 = V_8 -> V_8 . V_89 + V_8 -> V_8 . V_83 ;
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
F_102 ( V_166 , V_144 -> V_176 , V_144 -> V_170 , V_79 ) ;
V_151 -> V_153 = 1 ;
}
V_169 = F_103 ( V_166 ) ;
if ( V_169 == false ) {
F_104 ( 1 ) ;
return - V_67 ;
}
do {
V_162 = V_166 -> V_177 ;
V_168 = F_57 ( T_4 , V_161 , V_166 -> V_87 ) ;
V_166 -> V_178 = V_168 ;
V_167 += V_168 ;
if ( V_164 )
memcpy ( V_162 , V_163 , V_168 ) ;
else
memcpy ( V_163 , V_162 , V_168 ) ;
V_161 -= V_168 ;
if ( ! V_161 )
break;
V_169 = F_103 ( V_166 ) ;
if ( V_169 == false ) {
F_104 ( 1 ) ;
return - V_67 ;
}
V_163 += V_168 ;
} while ( 1 );
F_105 ( V_166 ) ;
return V_167 ;
}
static int F_106 ( struct V_9 * V_32 , struct V_144 * V_144 ,
struct V_1 * V_4 , int V_179 , int * V_28 )
{
struct V_17 * V_13 = V_32 -> V_13 ;
struct V_5 * V_8 ;
V_180:
F_19 (req, &ep->queue, queue) {
unsigned V_181 , V_182 , V_161 ;
int V_183 , V_164 ;
int V_184 = 0 ;
if ( F_84 ( V_32 , V_144 ) ) {
if ( ( V_144 -> V_150 != V_8 -> V_8 . V_150 ) )
continue;
}
V_181 = V_144 -> V_185 - V_144 -> V_172 ;
V_182 = V_8 -> V_8 . V_87 - V_8 -> V_8 . V_83 ;
V_161 = F_107 ( V_181 , V_182 ) ;
V_164 = F_101 ( V_144 -> V_146 ) ;
if ( F_95 ( V_161 == 0 ) )
V_183 = 1 ;
else {
if ( V_179 < V_4 -> V_4 . V_74 && V_179 < V_161 )
break;
V_161 = F_57 ( unsigned , V_161 , V_179 ) ;
if ( V_161 == 0 )
break;
if ( V_161 > V_4 -> V_4 . V_74 ) {
V_184 = 1 ;
V_161 -= ( V_161 % V_4 -> V_4 . V_74 ) ;
}
V_183 = ( V_161 % V_4 -> V_4 . V_74 ) != 0 ;
V_161 = F_100 ( V_144 , V_8 , V_161 ) ;
V_4 -> V_130 = V_105 ;
if ( ( int ) V_161 < 0 ) {
V_8 -> V_8 . V_28 = V_161 ;
} else {
V_179 -= V_161 ;
V_144 -> V_172 += V_161 ;
V_8 -> V_8 . V_83 += V_161 ;
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
if ( V_8 -> V_8 . V_87 == V_8 -> V_8 . V_83
&& ! V_8 -> V_8 . V_187 )
V_8 -> V_8 . V_28 = 0 ;
if ( V_144 -> V_185 == V_144 -> V_172
&& ! ( V_144 -> V_188
& V_189 ) )
* V_28 = 0 ;
}
if ( V_8 -> V_8 . V_28 != - V_82 ) {
F_14 ( & V_8 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_16 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_17 ( & V_13 -> V_30 ) ;
V_184 = 1 ;
}
if ( * V_28 != - V_82 )
break;
if ( V_184 )
goto V_180;
}
return V_179 ;
}
static int F_108 ( struct V_17 * V_13 , struct V_1 * V_4 )
{
int V_179 = V_4 -> V_4 . V_74 ;
if ( V_13 -> V_18 . V_22 == V_70 ) {
int V_190 ;
V_190 = F_25 ( V_4 -> V_60 ) ;
V_190 = ( V_190 >> 11 ) & 0x03 ;
V_190 *= 8 ;
V_179 += V_179 * V_190 ;
}
if ( V_13 -> V_18 . V_22 == V_23 ) {
switch ( F_26 ( V_4 -> V_60 ) ) {
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
static struct V_1 * F_109 ( struct V_17 * V_13 , V_113 V_31 )
{
int V_121 ;
if ( ! F_110 ( ( V_13 -> V_18 . V_22 == V_23 ?
V_13 -> V_24 : V_13 -> V_25 ) ) )
return NULL ;
if ( ( V_31 & ~ V_85 ) == 0 )
return & V_13 -> V_4 [ 0 ] ;
for ( V_121 = 1 ; V_121 < V_123 ; V_121 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_121 ] ;
if ( ! V_4 -> V_60 )
continue;
if ( V_4 -> V_60 -> V_84 == V_31 )
return V_4 ;
}
return NULL ;
}
static int F_111 ( struct V_9 * V_32 , struct V_144 * V_144 ,
struct V_191 * V_192 ,
int * V_28 )
{
struct V_1 * V_193 ;
struct V_17 * V_13 = V_32 -> V_13 ;
int V_194 = 1 ;
unsigned V_195 ;
unsigned V_196 ;
V_195 = F_112 ( V_192 -> V_197 ) ;
V_196 = F_112 ( V_192 -> V_198 ) ;
switch ( V_192 -> V_199 ) {
case V_200 :
if ( V_192 -> V_201 != V_202 )
break;
V_13 -> V_31 = V_196 ;
* V_28 = 0 ;
F_30 ( F_7 ( V_13 ) , L_22 ,
V_196 ) ;
V_194 = 0 ;
break;
case V_203 :
if ( V_192 -> V_201 == V_202 ) {
V_194 = 0 ;
switch ( V_196 ) {
case V_101 :
break;
case V_100 :
V_13 -> V_18 . V_204 = 1 ;
break;
case V_205 :
V_13 -> V_18 . V_206 = 1 ;
break;
case V_207 :
V_13 -> V_18 . V_208 = 1 ;
break;
case V_209 :
if ( F_5 ( V_32 ) -> V_22 ==
V_33 )
V_196 = V_210 ;
else
V_194 = - V_211 ;
break;
case V_212 :
if ( F_5 ( V_32 ) -> V_22 ==
V_33 )
V_196 = V_213 ;
else
V_194 = - V_211 ;
break;
case V_214 :
if ( F_5 ( V_32 ) -> V_22 ==
V_33 )
V_196 = V_215 ;
else
V_194 = - V_211 ;
break;
default:
V_194 = - V_211 ;
}
if ( V_194 == 0 ) {
V_13 -> V_99 |= ( 1 << V_196 ) ;
* V_28 = 0 ;
}
} else if ( V_192 -> V_201 == V_216 ) {
V_193 = F_109 ( V_13 , V_195 ) ;
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
case V_101 :
V_196 = V_101 ;
break;
case V_209 :
if ( F_5 ( V_32 ) -> V_22 ==
V_33 )
V_196 = V_210 ;
else
V_194 = - V_211 ;
break;
case V_212 :
if ( F_5 ( V_32 ) -> V_22 ==
V_33 )
V_196 = V_213 ;
else
V_194 = - V_211 ;
break;
case V_214 :
if ( F_5 ( V_32 ) -> V_22 ==
V_33 )
V_196 = V_215 ;
else
V_194 = - V_211 ;
break;
default:
V_194 = - V_211 ;
break;
}
if ( V_194 == 0 ) {
V_13 -> V_99 &= ~ ( 1 << V_196 ) ;
* V_28 = 0 ;
}
} else if ( V_192 -> V_201 == V_216 ) {
V_193 = F_109 ( V_13 , V_195 ) ;
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
char * V_89 ;
V_89 = ( char * ) V_144 -> V_171 ;
if ( V_144 -> V_185 > 0 ) {
if ( V_192 -> V_201 == V_221 ) {
V_193 = F_109 ( V_13 , V_195 ) ;
if ( ! V_193 ) {
V_194 = - V_211 ;
break;
}
V_89 [ 0 ] = V_193 -> V_77 ;
} else if ( V_192 -> V_201 ==
V_219 ) {
V_89 [ 0 ] = ( V_113 ) V_13 -> V_99 ;
} else
V_89 [ 0 ] = 0 ;
}
if ( V_144 -> V_185 > 1 )
V_89 [ 1 ] = 0 ;
V_144 -> V_172 = F_57 ( T_4 , 2 ,
V_144 -> V_185 ) ;
V_194 = 0 ;
* V_28 = 0 ;
}
break;
}
return V_194 ;
}
static void F_113 ( unsigned long V_222 )
{
struct V_9 * V_32 = (struct V_9 * ) V_222 ;
struct V_17 * V_13 = V_32 -> V_13 ;
struct V_151 * V_151 , * V_190 ;
unsigned long V_79 ;
int V_179 , V_223 ;
int V_121 ;
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
F_29 ( F_6 ( V_32 ) , L_23 ) ;
return;
}
F_32 ( & V_13 -> V_30 , V_79 ) ;
if ( ! V_32 -> V_154 ) {
F_29 ( F_6 ( V_32 ) ,
L_24 ) ;
F_33 ( & V_13 -> V_30 , V_79 ) ;
return;
}
for ( V_121 = 0 ; V_121 < V_123 ; V_121 ++ ) {
if ( ! V_124 [ V_121 ] )
break;
V_13 -> V_4 [ V_121 ] . V_127 = 0 ;
}
V_225:
F_114 (urbp, tmp, &dum_hcd->urbp_list, urbp_list) {
struct V_144 * V_144 ;
struct V_5 * V_8 ;
V_113 V_31 ;
struct V_1 * V_4 = NULL ;
int type ;
int V_28 = - V_82 ;
V_144 = V_151 -> V_144 ;
if ( V_144 -> V_226 )
goto V_227;
else if ( V_32 -> V_44 != V_160 )
continue;
type = F_96 ( V_144 -> V_146 ) ;
if ( V_223 <= 0 && type == V_228 )
continue;
V_31 = F_86 ( V_144 -> V_146 ) ;
if ( F_101 ( V_144 -> V_146 ) )
V_31 |= V_85 ;
V_4 = F_109 ( V_13 , V_31 ) ;
if ( ! V_4 ) {
F_30 ( F_6 ( V_32 ) ,
L_25 ,
V_144 ) ;
V_28 = - V_229 ;
goto V_227;
}
if ( V_4 -> V_127 )
continue;
V_4 -> V_127 = 1 ;
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_144 -> V_158 ) {
V_4 -> V_128 = 1 ;
V_144 -> V_158 = 0 ;
}
if ( V_4 -> V_77 && ! V_4 -> V_128 ) {
F_30 ( F_6 ( V_32 ) , L_26 ,
V_4 -> V_4 . V_63 , V_144 ) ;
V_28 = - V_230 ;
goto V_227;
}
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_4 -> V_128 ) {
struct V_191 V_192 ;
int V_93 = 1 ;
V_192 = * (struct V_191 * ) V_144 -> V_231 ;
F_19 (req, &ep->queue, queue) {
F_14 ( & V_8 -> V_26 ) ;
V_8 -> V_8 . V_28 = - V_186 ;
F_30 ( F_7 ( V_13 ) , L_27 ,
V_8 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_16 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_17 ( & V_13 -> V_30 ) ;
V_4 -> V_127 = 0 ;
goto V_225;
}
V_4 -> V_130 = V_105 ;
V_4 -> V_128 = 0 ;
V_4 -> V_77 = 0 ;
V_93 = F_111 ( V_32 , V_144 , & V_192 ,
& V_28 ) ;
if ( V_93 > 0 ) {
F_15 ( & V_13 -> V_30 ) ;
V_93 = V_13 -> V_55 -> V_192 ( & V_13 -> V_18 ,
& V_192 ) ;
F_17 ( & V_13 -> V_30 ) ;
if ( V_93 >= 0 ) {
V_179 = 64 * 1024 ;
goto V_232;
}
}
if ( V_93 < 0 ) {
if ( V_93 != - V_211 )
F_30 ( F_7 ( V_13 ) ,
L_28 ,
V_93 ) ;
V_28 = - V_230 ;
V_144 -> V_172 = 0 ;
}
goto V_227;
}
V_179 = V_223 ;
switch ( F_96 ( V_144 -> V_146 ) ) {
case V_233 :
V_179 = V_61 ( V_179 , F_108 ( V_13 , V_4 ) ) ;
V_28 = - V_234 ;
break;
case V_235 :
V_179 = V_61 ( V_179 , F_108 ( V_13 , V_4 ) ) ;
default:
V_232:
V_4 -> V_130 = V_105 ;
V_223 = F_106 ( V_32 , V_144 , V_4 , V_179 , & V_28 ) ;
break;
}
if ( V_28 == - V_82 )
continue;
V_227:
F_115 ( & V_151 -> V_155 ) ;
F_39 ( V_151 ) ;
if ( V_4 )
V_4 -> V_127 = V_4 -> V_128 = 0 ;
F_116 ( F_5 ( V_32 ) , V_144 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_117 ( F_5 ( V_32 ) , V_144 , V_28 ) ;
F_17 ( & V_13 -> V_30 ) ;
goto V_225;
}
if ( F_12 ( & V_32 -> V_155 ) ) {
F_118 ( V_32 -> V_154 ) ;
V_32 -> V_154 = NULL ;
} else if ( V_32 -> V_44 == V_160 ) {
F_53 ( & V_32 -> V_159 , V_105 + F_52 ( 1 ) ) ;
}
F_33 ( & V_13 -> V_30 , V_79 ) ;
}
static int F_119 ( struct V_10 * V_11 , char * V_89 )
{
struct V_9 * V_32 ;
unsigned long V_79 ;
int V_62 = 0 ;
V_32 = F_4 ( V_11 ) ;
F_32 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
if ( ! F_120 ( V_11 ) )
goto V_69;
if ( V_32 -> V_51 && F_121 ( V_105 , V_32 -> V_104 ) ) {
V_32 -> V_34 |= ( V_236 << 16 ) ;
V_32 -> V_34 &= ~ V_50 ;
F_21 ( V_32 ) ;
}
if ( ( V_32 -> V_34 & V_237 ) != 0 ) {
* V_89 = ( 1 << 1 ) ;
F_30 ( F_6 ( V_32 ) , L_29 ,
V_32 -> V_34 ) ;
V_62 = 1 ;
if ( V_32 -> V_44 == V_45 )
F_122 ( V_11 ) ;
}
V_69:
F_33 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
return V_62 ;
}
static inline void
F_123 ( struct V_238 * V_60 )
{
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_65 = V_239 ;
V_60 -> V_240 = 12 ;
V_60 -> V_241 = F_124 (
V_242 |
V_243 ) ;
V_60 -> V_244 = 1 ;
V_60 -> V_245 . V_246 . V_247 = 0x04 ;
V_60 -> V_245 . V_246 . V_248 = 0xffff ;
}
static inline void F_125 ( struct V_238 * V_60 )
{
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_65 = V_249 ;
V_60 -> V_240 = 9 ;
V_60 -> V_241 = F_124 (
V_242 |
V_243 ) ;
V_60 -> V_244 = 1 ;
V_60 -> V_245 . V_250 . V_248 [ 0 ] = 0xff ;
V_60 -> V_245 . V_250 . V_248 [ 1 ] = 0xff ;
}
static int F_126 (
struct V_10 * V_11 ,
T_5 V_251 ,
T_5 V_198 ,
T_5 V_197 ,
char * V_89 ,
T_5 V_252
) {
struct V_9 * V_32 ;
int V_62 = 0 ;
unsigned long V_79 ;
if ( ! F_120 ( V_11 ) )
return - V_253 ;
V_32 = F_4 ( V_11 ) ;
F_32 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
switch ( V_251 ) {
case V_254 :
break;
case V_255 :
switch ( V_198 ) {
case V_256 :
if ( V_11 -> V_22 == V_33 ) {
F_30 ( F_6 ( V_32 ) ,
L_30
L_31 ) ;
goto error;
}
if ( V_32 -> V_34 & V_50 ) {
V_32 -> V_51 = 1 ;
V_32 -> V_104 = V_105 +
F_52 ( 20 ) ;
}
break;
case V_257 :
if ( V_11 -> V_22 == V_33 ) {
if ( V_32 -> V_34 & V_47 )
F_30 ( F_6 ( V_32 ) ,
L_32 ) ;
} else
if ( V_32 -> V_34 &
V_35 )
F_30 ( F_6 ( V_32 ) ,
L_32 ) ;
default:
V_32 -> V_34 &= ~ ( 1 << V_198 ) ;
F_21 ( V_32 ) ;
}
break;
case V_258 :
if ( V_11 -> V_22 == V_33 &&
( V_252 < V_259 ||
V_198 != ( V_239 << 8 ) ) ) {
F_30 ( F_6 ( V_32 ) ,
L_33
L_34 ) ;
goto error;
}
if ( V_11 -> V_22 == V_33 )
F_123 ( (struct V_238 * ) V_89 ) ;
else
F_125 ( (struct V_238 * ) V_89 ) ;
break;
case V_260 | V_261 :
if ( V_11 -> V_22 != V_33 )
goto error;
if ( ( V_198 >> 8 ) != V_262 )
goto error;
memcpy ( V_89 , & V_263 , sizeof( V_263 ) ) ;
V_62 = sizeof( V_263 ) ;
break;
case V_264 :
* ( V_265 * ) V_89 = F_127 ( 0 ) ;
break;
case V_266 :
if ( V_197 != 1 )
V_62 = - V_230 ;
if ( V_32 -> V_51 &&
F_121 ( V_105 , V_32 -> V_104 ) ) {
V_32 -> V_34 |= ( V_236 << 16 ) ;
V_32 -> V_34 &= ~ V_50 ;
}
if ( ( V_32 -> V_34 & V_52 ) != 0 &&
F_121 ( V_105 , V_32 -> V_104 ) ) {
V_32 -> V_34 |= ( V_267 << 16 ) ;
V_32 -> V_34 &= ~ V_52 ;
if ( V_32 -> V_13 -> V_36 ) {
V_32 -> V_34 |= V_39 ;
if ( V_11 -> V_22 < V_33 ) {
switch ( V_32 -> V_13 -> V_18 . V_22 ) {
case V_70 :
V_32 -> V_34 |=
V_49 ;
break;
case V_224 :
V_32 -> V_13 -> V_18 . V_131 ->
V_74 = 8 ;
V_32 -> V_34 |=
V_48 ;
break;
default:
V_32 -> V_13 -> V_18 . V_22 =
V_71 ;
break;
}
}
}
}
F_21 ( V_32 ) ;
( ( V_268 * ) V_89 ) [ 0 ] = F_124 ( V_32 -> V_34 ) ;
( ( V_268 * ) V_89 ) [ 1 ] = F_124 ( V_32 -> V_34 >> 16 ) ;
break;
case V_269 :
V_62 = - V_230 ;
break;
case V_270 :
switch ( V_198 ) {
case V_271 :
if ( V_11 -> V_22 != V_33 ) {
F_30 ( F_6 ( V_32 ) ,
L_35
L_36 ) ;
goto error;
}
break;
case V_272 :
case V_273 :
if ( V_11 -> V_22 != V_33 ) {
F_30 ( F_6 ( V_32 ) ,
L_37
L_36 ) ;
goto error;
}
break;
case V_256 :
if ( V_11 -> V_22 == V_33 ) {
F_30 ( F_6 ( V_32 ) ,
L_30
L_31 ) ;
goto error;
}
if ( V_32 -> V_46 ) {
V_32 -> V_34 |= V_50 ;
F_21 ( V_32 ) ;
if ( ( ( 1 << V_100 )
& V_32 -> V_13 -> V_99 ) != 0 )
F_30 ( F_6 ( V_32 ) ,
L_38 ) ;
}
break;
case V_257 :
if ( V_11 -> V_22 == V_33 )
V_32 -> V_34 |= V_35 ;
else
V_32 -> V_34 |= V_47 ;
F_21 ( V_32 ) ;
break;
case V_274 :
if ( V_11 -> V_22 != V_33 ) {
F_30 ( F_6 ( V_32 ) ,
L_39
L_36 ) ;
goto error;
}
case V_275 :
if ( V_11 -> V_22 == V_33 ) {
V_32 -> V_34 = 0 ;
V_32 -> V_34 =
( V_35 |
V_38 |
V_52 ) ;
} else
V_32 -> V_34 &= ~ ( V_39
| V_48
| V_49 ) ;
V_32 -> V_13 -> V_99 &=
( 1 << V_108 ) ;
V_32 -> V_104 = V_105 + F_52 ( 50 ) ;
default:
if ( V_11 -> V_22 == V_33 ) {
if ( ( V_32 -> V_34 &
V_35 ) != 0 ) {
V_32 -> V_34 |= ( 1 << V_198 ) ;
F_21 ( V_32 ) ;
}
} else
if ( ( V_32 -> V_34 &
V_47 ) != 0 ) {
V_32 -> V_34 |= ( 1 << V_198 ) ;
F_21 ( V_32 ) ;
}
}
break;
case V_276 :
if ( V_11 -> V_22 != V_33 ) {
F_30 ( F_6 ( V_32 ) ,
L_40
L_36 ) ;
goto error;
}
* ( V_265 * ) V_89 = F_127 ( 0 ) ;
break;
case V_277 :
if ( V_11 -> V_22 != V_33 ) {
F_30 ( F_6 ( V_32 ) ,
L_41
L_42 ) ;
goto error;
}
break;
default:
F_30 ( F_6 ( V_32 ) ,
L_43 ,
V_251 , V_198 , V_197 , V_252 ) ;
error:
V_62 = - V_230 ;
}
F_33 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
if ( ( V_32 -> V_34 & V_237 ) != 0 )
F_59 ( V_11 ) ;
return V_62 ;
}
static int F_128 ( struct V_10 * V_11 )
{
struct V_9 * V_32 = F_4 ( V_11 ) ;
F_30 ( & V_11 -> V_15 . V_278 -> V_19 , L_19 , V_142 ) ;
F_77 ( & V_32 -> V_13 -> V_30 ) ;
V_32 -> V_44 = V_45 ;
F_21 ( V_32 ) ;
V_11 -> V_141 = V_279 ;
F_78 ( & V_32 -> V_13 -> V_30 ) ;
return 0 ;
}
static int F_129 ( struct V_10 * V_11 )
{
struct V_9 * V_32 = F_4 ( V_11 ) ;
int V_135 = 0 ;
F_30 ( & V_11 -> V_15 . V_278 -> V_19 , L_19 , V_142 ) ;
F_77 ( & V_32 -> V_13 -> V_30 ) ;
if ( ! F_120 ( V_11 ) ) {
V_135 = - V_29 ;
} else {
V_32 -> V_44 = V_160 ;
F_21 ( V_32 ) ;
if ( ! F_12 ( & V_32 -> V_155 ) )
F_53 ( & V_32 -> V_159 , V_105 ) ;
V_11 -> V_141 = V_280 ;
}
F_78 ( & V_32 -> V_13 -> V_30 ) ;
return V_135 ;
}
static inline T_2 F_130 ( char * V_89 , T_6 V_281 , struct V_144 * V_144 )
{
int V_4 = F_86 ( V_144 -> V_146 ) ;
return snprintf (buf, size,
L_44 ,
urb,
({ char *s;
switch (urb->dev->speed) {
case USB_SPEED_LOW:
s = L_45;
break;
case USB_SPEED_FULL:
s = L_46;
break;
case USB_SPEED_HIGH:
s = L_47;
break;
case USB_SPEED_SUPER:
s = L_48;
break;
default:
s = L_49;
break;
} s; }),
ep, ep ? (usb_pipein(urb->pipe) ? L_7 : L_8) : L_50 ,
({ char *s; \
switch (usb_pipetype(urb->pipe)) { \
case PIPE_CONTROL: \
s = L_50; \
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
static T_2 F_131 ( struct V_14 * V_19 , struct V_114 * V_115 ,
char * V_89 )
{
struct V_10 * V_11 = F_132 ( V_19 ) ;
struct V_9 * V_32 = F_4 ( V_11 ) ;
struct V_151 * V_151 ;
T_6 V_281 = 0 ;
unsigned long V_79 ;
F_32 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
F_19 (urbp, &dum_hcd->urbp_list, urbp_list) {
T_6 V_282 ;
V_282 = F_130 ( V_89 , V_117 - V_281 , V_151 -> V_144 ) ;
V_89 += V_282 ;
V_281 += V_282 ;
}
F_33 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
return V_281 ;
}
static int F_133 ( struct V_9 * V_32 )
{
F_134 ( & V_32 -> V_159 ) ;
V_32 -> V_159 . V_116 = F_113 ;
V_32 -> V_159 . V_283 = ( unsigned long ) V_32 ;
V_32 -> V_44 = V_160 ;
V_32 -> V_145 = 0 ;
F_36 ( & V_32 -> V_155 ) ;
F_5 ( V_32 ) -> V_284 = V_285 ;
F_5 ( V_32 ) -> V_141 = V_280 ;
F_5 ( V_32 ) -> V_286 = 1 ;
#ifdef F_66
F_5 ( V_32 ) -> V_15 . V_287 = 1 ;
#endif
return 0 ;
return F_70 ( F_6 ( V_32 ) , & V_288 ) ;
}
static int F_135 ( struct V_10 * V_11 )
{
struct V_9 * V_32 = F_4 ( V_11 ) ;
if ( ! F_136 ( V_11 ) )
return F_133 ( V_32 ) ;
F_137 ( & V_32 -> V_13 -> V_30 ) ;
F_134 ( & V_32 -> V_159 ) ;
V_32 -> V_159 . V_116 = F_113 ;
V_32 -> V_159 . V_283 = ( unsigned long ) V_32 ;
V_32 -> V_44 = V_160 ;
F_36 ( & V_32 -> V_155 ) ;
V_11 -> V_284 = V_285 ;
V_11 -> V_141 = V_280 ;
V_11 -> V_286 = 1 ;
#ifdef F_66
V_11 -> V_15 . V_287 = 1 ;
#endif
return F_70 ( F_6 ( V_32 ) , & V_288 ) ;
}
static void F_138 ( struct V_10 * V_11 )
{
struct V_17 * V_13 ;
V_13 = F_4 ( V_11 ) -> V_13 ;
F_75 ( F_6 ( F_4 ( V_11 ) ) , & V_288 ) ;
F_139 ( F_6 ( F_4 ( V_11 ) ) , L_51 ) ;
}
static int F_140 ( struct V_10 * V_11 )
{
return F_49 ( NULL ) ;
}
static int F_141 ( struct V_10 * V_11 )
{
struct V_17 * V_13 ;
V_13 = * ( ( void * * ) F_68 ( V_11 -> V_15 . V_16 ) ) ;
V_11 -> V_15 . V_289 = ~ 0 ;
if ( F_136 ( V_11 ) ) {
V_13 -> V_25 = F_4 ( V_11 ) ;
V_13 -> V_25 -> V_13 = V_13 ;
V_11 -> V_22 = V_290 ;
V_11 -> V_15 . V_278 -> V_22 = V_70 ;
} else {
V_13 -> V_24 = F_4 ( V_11 ) ;
V_13 -> V_24 -> V_13 = V_13 ;
V_11 -> V_22 = V_33 ;
V_11 -> V_15 . V_278 -> V_22 = V_23 ;
}
return 0 ;
}
static int F_142 ( struct V_10 * V_11 , struct V_291 * V_154 ,
struct V_292 * * V_293 , unsigned int V_294 ,
unsigned int V_295 , T_1 V_80 )
{
struct V_9 * V_32 = F_4 ( V_11 ) ;
unsigned long V_79 ;
int V_296 ;
int V_297 = V_295 ;
unsigned int V_143 ;
unsigned int V_121 ;
if ( ! V_294 )
return - V_67 ;
F_32 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
for ( V_121 = 0 ; V_121 < V_294 ; V_121 ++ ) {
V_143 = F_81 ( & V_293 [ V_121 ] -> V_60 ) ;
if ( ( 1 << V_143 ) & V_32 -> V_145 ) {
V_297 = - V_67 ;
goto V_298;
}
V_296 = F_27 ( & V_293 [ V_121 ] -> V_299 ) ;
if ( ! V_296 ) {
V_297 = - V_67 ;
goto V_298;
}
if ( V_296 < V_297 ) {
F_30 ( F_6 ( V_32 ) , L_52
L_53 ,
V_293 [ V_121 ] -> V_60 . V_84 ,
V_296 ) ;
V_297 = V_296 ;
}
}
for ( V_121 = 0 ; V_121 < V_294 ; V_121 ++ ) {
V_143 = F_81 ( & V_293 [ V_121 ] -> V_60 ) ;
V_32 -> V_145 |= 1 << V_143 ;
F_88 ( V_32 ,
F_82 ( & V_293 [ V_121 ] -> V_60 ) , V_297 ) ;
}
V_298:
F_33 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
return V_297 ;
}
static int F_143 ( struct V_10 * V_11 , struct V_291 * V_154 ,
struct V_292 * * V_293 , unsigned int V_294 ,
T_1 V_80 )
{
struct V_9 * V_32 = F_4 ( V_11 ) ;
unsigned long V_79 ;
int V_300 ;
unsigned int V_143 ;
unsigned int V_121 ;
F_32 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
for ( V_121 = 0 ; V_121 < V_294 ; V_121 ++ ) {
V_143 = F_81 ( & V_293 [ V_121 ] -> V_60 ) ;
if ( ! ( ( 1 << V_143 ) & V_32 -> V_145 ) ) {
V_300 = - V_67 ;
goto V_298;
}
}
for ( V_121 = 0 ; V_121 < V_294 ; V_121 ++ ) {
V_143 = F_81 ( & V_293 [ V_121 ] -> V_60 ) ;
V_32 -> V_145 &= ~ ( 1 << V_143 ) ;
F_88 ( V_32 ,
F_82 ( & V_293 [ V_121 ] -> V_60 ) , 0 ) ;
}
V_300 = 0 ;
V_298:
F_33 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
return V_300 ;
}
static int F_144 ( struct V_133 * V_134 )
{
struct V_17 * V_13 ;
struct V_10 * V_25 ;
struct V_10 * V_24 ;
int V_62 ;
F_139 ( & V_134 -> V_19 , L_54 V_301 L_55 , V_302 ) ;
V_13 = * ( ( void * * ) F_68 ( & V_134 -> V_19 ) ) ;
if ( ! V_109 . V_110 )
V_9 . V_79 = V_290 ;
V_25 = F_145 ( & V_9 , & V_134 -> V_19 , F_146 ( & V_134 -> V_19 ) ) ;
if ( ! V_25 )
return - V_152 ;
V_25 -> V_303 = 1 ;
V_62 = F_147 ( V_25 , 0 , 0 ) ;
if ( V_62 )
goto V_304;
if ( V_109 . V_110 ) {
V_24 = F_148 ( & V_9 , & V_134 -> V_19 ,
F_146 ( & V_134 -> V_19 ) , V_25 ) ;
if ( ! V_24 ) {
V_62 = - V_152 ;
goto V_305;
}
V_62 = F_147 ( V_24 , 0 , 0 ) ;
if ( V_62 )
goto V_306;
}
return 0 ;
V_306:
F_149 ( V_24 ) ;
V_305:
F_150 ( V_25 ) ;
V_304:
F_149 ( V_25 ) ;
V_13 -> V_25 = V_13 -> V_24 = NULL ;
return V_62 ;
}
static int F_151 ( struct V_133 * V_134 )
{
struct V_17 * V_13 ;
V_13 = F_4 ( F_74 ( V_134 ) ) -> V_13 ;
if ( V_13 -> V_24 ) {
F_150 ( F_5 ( V_13 -> V_24 ) ) ;
F_149 ( F_5 ( V_13 -> V_24 ) ) ;
}
F_150 ( F_5 ( V_13 -> V_25 ) ) ;
F_149 ( F_5 ( V_13 -> V_25 ) ) ;
V_13 -> V_25 = NULL ;
V_13 -> V_24 = NULL ;
return 0 ;
}
static int F_152 ( struct V_133 * V_134 , T_3 V_141 )
{
struct V_10 * V_11 ;
struct V_9 * V_32 ;
int V_135 = 0 ;
F_30 ( & V_134 -> V_19 , L_19 , V_142 ) ;
V_11 = F_74 ( V_134 ) ;
V_32 = F_4 ( V_11 ) ;
if ( V_32 -> V_44 == V_160 ) {
F_153 ( & V_134 -> V_19 , L_56 ) ;
V_135 = - V_307 ;
} else
F_154 ( V_308 , & V_11 -> V_79 ) ;
return V_135 ;
}
static int F_155 ( struct V_133 * V_134 )
{
struct V_10 * V_11 ;
F_30 ( & V_134 -> V_19 , L_19 , V_142 ) ;
V_11 = F_74 ( V_134 ) ;
F_156 ( V_308 , & V_11 -> V_79 ) ;
F_59 ( V_11 ) ;
return 0 ;
}
static int T_7 F_157 ( void )
{
int V_62 = - V_152 ;
int V_121 ;
struct V_17 * V_13 [ V_309 ] ;
if ( F_158 () )
return - V_310 ;
if ( ! V_109 . V_112 && V_109 . V_110 )
return - V_67 ;
if ( V_109 . V_311 < 1 || V_109 . V_311 > V_309 ) {
F_159 ( L_57 ,
V_309 ) ;
return - V_67 ;
}
for ( V_121 = 0 ; V_121 < V_109 . V_311 ; V_121 ++ ) {
V_312 [ V_121 ] = F_160 ( V_313 , V_121 ) ;
if ( ! V_312 [ V_121 ] ) {
V_121 -- ;
while ( V_121 >= 0 )
F_161 ( V_312 [ V_121 -- ] ) ;
return V_62 ;
}
}
for ( V_121 = 0 ; V_121 < V_109 . V_311 ; V_121 ++ ) {
V_314 [ V_121 ] = F_160 ( V_136 , V_121 ) ;
if ( ! V_314 [ V_121 ] ) {
V_121 -- ;
while ( V_121 >= 0 )
F_161 ( V_314 [ V_121 -- ] ) ;
goto V_315;
}
}
for ( V_121 = 0 ; V_121 < V_109 . V_311 ; V_121 ++ ) {
V_13 [ V_121 ] = F_35 ( sizeof( struct V_17 ) , V_316 ) ;
if ( ! V_13 [ V_121 ] ) {
V_62 = - V_152 ;
goto V_317;
}
V_62 = F_162 ( V_312 [ V_121 ] , & V_13 [ V_121 ] ,
sizeof( void * ) ) ;
if ( V_62 )
goto V_317;
V_62 = F_162 ( V_314 [ V_121 ] , & V_13 [ V_121 ] ,
sizeof( void * ) ) ;
if ( V_62 )
goto V_317;
}
V_62 = F_163 ( & V_318 ) ;
if ( V_62 < 0 )
goto V_317;
V_62 = F_163 ( & V_319 ) ;
if ( V_62 < 0 )
goto V_320;
for ( V_121 = 0 ; V_121 < V_109 . V_311 ; V_121 ++ ) {
V_62 = F_164 ( V_312 [ V_121 ] ) ;
if ( V_62 < 0 ) {
V_121 -- ;
while ( V_121 >= 0 )
F_165 ( V_312 [ V_121 -- ] ) ;
goto V_321;
}
}
for ( V_121 = 0 ; V_121 < V_109 . V_311 ; V_121 ++ ) {
if ( ! V_13 [ V_121 ] -> V_25 ||
( ! V_13 [ V_121 ] -> V_24 && V_109 . V_110 ) ) {
V_62 = - V_67 ;
goto V_322;
}
}
for ( V_121 = 0 ; V_121 < V_109 . V_311 ; V_121 ++ ) {
V_62 = F_164 ( V_314 [ V_121 ] ) ;
if ( V_62 < 0 ) {
V_121 -- ;
while ( V_121 >= 0 )
F_165 ( V_314 [ V_121 ] ) ;
goto V_322;
}
}
for ( V_121 = 0 ; V_121 < V_109 . V_311 ; V_121 ++ ) {
if ( ! F_74 ( V_314 [ V_121 ] ) ) {
V_62 = - V_67 ;
goto V_323;
}
}
return V_62 ;
V_323:
for ( V_121 = 0 ; V_121 < V_109 . V_311 ; V_121 ++ )
F_165 ( V_314 [ V_121 ] ) ;
V_322:
for ( V_121 = 0 ; V_121 < V_109 . V_311 ; V_121 ++ )
F_165 ( V_312 [ V_121 ] ) ;
V_321:
F_166 ( & V_319 ) ;
V_320:
F_166 ( & V_318 ) ;
V_317:
for ( V_121 = 0 ; V_121 < V_109 . V_311 ; V_121 ++ )
F_39 ( V_13 [ V_121 ] ) ;
for ( V_121 = 0 ; V_121 < V_109 . V_311 ; V_121 ++ )
F_161 ( V_314 [ V_121 ] ) ;
V_315:
for ( V_121 = 0 ; V_121 < V_109 . V_311 ; V_121 ++ )
F_161 ( V_312 [ V_121 ] ) ;
return V_62 ;
}
static void T_8 F_167 ( void )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < V_109 . V_311 ; V_121 ++ ) {
struct V_17 * V_13 ;
V_13 = * ( ( void * * ) F_68 ( & V_314 [ V_121 ] -> V_19 ) ) ;
F_168 ( V_314 [ V_121 ] ) ;
F_168 ( V_312 [ V_121 ] ) ;
F_39 ( V_13 ) ;
}
F_166 ( & V_319 ) ;
F_166 ( & V_318 ) ;
}
