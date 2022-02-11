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
V_13 = F_9 ( V_95 ) -> V_13 ;
if ( V_93 )
V_13 -> V_99 |= ( 1 << V_107 ) ;
else
V_13 -> V_99 &= ~ ( 1 << V_107 ) ;
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
if ( V_108 . V_109 )
V_13 -> V_18 . V_22 = V_13 -> V_55 -> V_110 ;
else if ( V_108 . V_111 )
V_13 -> V_18 . V_22 = F_57 ( V_112 , V_70 ,
V_13 -> V_55 -> V_110 ) ;
else
V_13 -> V_18 . V_22 = V_71 ;
F_55 ( V_13 ) ;
if ( V_13 -> V_18 . V_22 < V_13 -> V_55 -> V_110 )
F_30 ( F_7 ( V_13 ) , L_17
L_18 ,
F_58 ( V_13 -> V_55 -> V_110 ) ) ;
}
V_32 = F_9 ( V_95 ) ;
F_32 ( & V_13 -> V_30 , V_79 ) ;
V_13 -> V_36 = ( V_93 != 0 ) ;
F_21 ( V_32 ) ;
F_33 ( & V_13 -> V_30 , V_79 ) ;
F_59 ( F_5 ( V_32 ) ) ;
return 0 ;
}
static T_2 F_60 ( struct V_14 * V_19 , struct V_113 * V_114 ,
char * V_89 )
{
struct V_17 * V_13 = F_10 ( V_19 ) ;
if ( ! V_13 -> V_55 || ! V_13 -> V_55 -> V_115 )
return 0 ;
return F_61 ( V_89 , V_116 , L_19 , V_13 -> V_55 -> V_115 ) ;
}
static int F_62 ( struct V_21 * V_117 ,
struct V_118 * V_55 )
{
struct V_9 * V_32 = F_9 ( V_117 ) ;
struct V_17 * V_13 = V_32 -> V_13 ;
if ( V_55 -> V_110 == V_119 )
return - V_67 ;
V_13 -> V_99 = 0 ;
V_13 -> V_55 = V_55 ;
return 0 ;
}
static int F_63 ( struct V_21 * V_117 )
{
struct V_9 * V_32 = F_9 ( V_117 ) ;
struct V_17 * V_13 = V_32 -> V_13 ;
V_13 -> V_55 = NULL ;
return 0 ;
}
static void F_64 ( struct V_17 * V_13 )
{
int V_120 ;
F_36 ( & V_13 -> V_18 . V_121 ) ;
for ( V_120 = 0 ; V_120 < V_122 ; V_120 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_120 ] ;
if ( ! V_123 [ V_120 ] )
break;
V_4 -> V_4 . V_63 = V_123 [ V_120 ] ;
V_4 -> V_4 . V_124 = & V_125 ;
F_42 ( & V_4 -> V_4 . V_121 , & V_13 -> V_18 . V_121 ) ;
V_4 -> V_77 = V_4 -> V_78 = V_4 -> V_126 =
V_4 -> V_127 = 0 ;
F_65 ( & V_4 -> V_4 , ~ 0 ) ;
V_4 -> V_4 . V_128 = 16 ;
V_4 -> V_129 = V_105 ;
V_4 -> V_18 = & V_13 -> V_18 ;
V_4 -> V_60 = NULL ;
F_36 ( & V_4 -> V_26 ) ;
}
V_13 -> V_18 . V_130 = & V_13 -> V_4 [ 0 ] . V_4 ;
F_14 ( & V_13 -> V_4 [ 0 ] . V_4 . V_121 ) ;
F_36 ( & V_13 -> V_86 . V_26 ) ;
#ifdef F_66
V_13 -> V_18 . V_131 = 1 ;
#endif
}
static int F_67 ( struct V_132 * V_133 )
{
struct V_17 * V_13 ;
int V_134 ;
V_13 = * ( ( void * * ) F_68 ( & V_133 -> V_19 ) ) ;
V_13 -> V_18 . V_63 = V_135 ;
V_13 -> V_18 . V_124 = & V_136 ;
V_13 -> V_18 . V_110 = V_23 ;
V_13 -> V_18 . V_19 . V_20 = & V_133 -> V_19 ;
F_64 ( V_13 ) ;
V_134 = F_69 ( & V_133 -> V_19 , & V_13 -> V_18 ) ;
if ( V_134 < 0 )
goto V_137;
V_134 = F_70 ( & V_13 -> V_18 . V_19 , & V_138 ) ;
if ( V_134 < 0 )
goto V_139;
F_71 ( V_133 , V_13 ) ;
return V_134 ;
V_139:
F_72 ( & V_13 -> V_18 ) ;
V_137:
return V_134 ;
}
static int F_73 ( struct V_132 * V_133 )
{
struct V_17 * V_13 = F_74 ( V_133 ) ;
F_75 ( & V_13 -> V_18 . V_19 , & V_138 ) ;
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
static int F_79 ( struct V_132 * V_133 , T_3 V_140 )
{
struct V_17 * V_13 = F_74 ( V_133 ) ;
struct V_9 * V_32 = F_9 ( & V_13 -> V_18 ) ;
F_30 ( & V_133 -> V_19 , L_19 , V_141 ) ;
F_76 ( V_13 , V_32 , 1 ) ;
F_59 ( F_5 ( V_32 ) ) ;
return 0 ;
}
static int F_80 ( struct V_132 * V_133 )
{
struct V_17 * V_13 = F_74 ( V_133 ) ;
struct V_9 * V_32 = F_9 ( & V_13 -> V_18 ) ;
F_30 ( & V_133 -> V_19 , L_19 , V_141 ) ;
F_76 ( V_13 , V_32 , 0 ) ;
F_59 ( F_5 ( V_32 ) ) ;
return 0 ;
}
static unsigned int F_81 ( const struct V_59 * V_60 )
{
unsigned int V_142 ;
V_142 = F_82 ( V_60 ) << 1 ;
if ( F_83 ( V_60 ) )
V_142 |= 1 ;
return V_142 ;
}
static int F_84 ( struct V_9 * V_32 , struct V_143 * V_143 )
{
const struct V_59 * V_60 = & V_143 -> V_4 -> V_60 ;
T_4 V_142 ;
if ( ! F_28 ( V_60 ) )
return 0 ;
V_142 = F_81 ( V_60 ) ;
return ( 1 << V_142 ) & V_32 -> V_144 ;
}
static int F_85 ( struct V_9 * V_32 ,
unsigned int V_145 )
{
int V_128 ;
V_128 = V_32 -> V_146 [ F_86 ( V_145 ) ] ;
if ( F_87 ( V_145 ) )
V_128 >>= 4 ;
else
V_128 &= 0xf ;
V_128 ++ ;
return V_128 ;
}
static void F_88 ( struct V_9 * V_32 ,
unsigned int V_145 , unsigned int V_147 )
{
int V_128 ;
V_147 -- ;
V_128 = V_32 -> V_146 [ F_86 ( V_145 ) ] ;
if ( F_87 ( V_145 ) ) {
V_147 <<= 4 ;
V_128 &= 0xf ;
} else {
V_128 &= 0xf0 ;
}
V_128 |= V_147 ;
V_32 -> V_146 [ F_86 ( V_145 ) ] = V_128 ;
}
static int F_89 ( struct V_9 * V_32 , struct V_143 * V_143 )
{
unsigned int V_128 ;
int V_148 ;
V_148 = F_84 ( V_32 , V_143 ) ;
if ( ! V_143 -> V_149 ) {
if ( V_148 )
return - V_67 ;
return 0 ;
}
if ( ! V_148 )
return - V_67 ;
V_128 = F_85 ( V_32 ,
F_86 ( V_143 -> V_145 ) ) ;
if ( V_143 -> V_149 > V_128 ) {
F_29 ( F_6 ( V_32 ) , L_20 ,
V_143 -> V_149 ) ;
F_90 () ;
return - V_67 ;
}
return 0 ;
}
static int F_91 (
struct V_10 * V_11 ,
struct V_143 * V_143 ,
T_1 V_80
) {
struct V_9 * V_32 ;
struct V_150 * V_150 ;
unsigned long V_79 ;
int V_134 ;
V_150 = F_92 ( sizeof *V_150 , V_80 ) ;
if ( ! V_150 )
return - V_151 ;
V_150 -> V_143 = V_143 ;
V_150 -> V_152 = 0 ;
V_32 = F_4 ( V_11 ) ;
F_32 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
V_134 = F_89 ( V_32 , V_143 ) ;
if ( V_134 ) {
F_39 ( V_150 ) ;
goto V_69;
}
V_134 = F_93 ( V_11 , V_143 ) ;
if ( V_134 ) {
F_39 ( V_150 ) ;
goto V_69;
}
if ( ! V_32 -> V_153 ) {
V_32 -> V_153 = V_143 -> V_19 ;
F_94 ( V_32 -> V_153 ) ;
} else if ( F_95 ( V_32 -> V_153 != V_143 -> V_19 ) )
F_29 ( F_6 ( V_32 ) , L_21 ) ;
F_42 ( & V_150 -> V_154 , & V_32 -> V_154 ) ;
V_143 -> V_155 = V_150 ;
if ( F_96 ( V_143 -> V_145 ) == V_156 )
V_143 -> V_157 = 1 ;
if ( ! F_97 ( & V_32 -> V_158 ) )
F_53 ( & V_32 -> V_158 , V_105 + 1 ) ;
V_69:
F_33 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
return V_134 ;
}
static int F_98 ( struct V_10 * V_11 , struct V_143 * V_143 , int V_28 )
{
struct V_9 * V_32 ;
unsigned long V_79 ;
int V_134 ;
V_32 = F_4 ( V_11 ) ;
F_32 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
V_134 = F_99 ( V_11 , V_143 , V_28 ) ;
if ( ! V_134 && V_32 -> V_44 != V_159 &&
! F_12 ( & V_32 -> V_154 ) )
F_53 ( & V_32 -> V_158 , V_105 ) ;
F_33 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
return V_134 ;
}
static int F_100 ( struct V_143 * V_143 , struct V_5 * V_8 ,
T_4 V_160 )
{
void * V_161 , * V_162 ;
struct V_150 * V_150 = V_143 -> V_155 ;
int V_163 ;
struct V_164 * V_165 = & V_150 -> V_165 ;
T_4 V_166 = 0 ;
T_4 V_167 ;
bool V_168 ;
V_163 = F_101 ( V_143 -> V_145 ) ;
V_162 = V_8 -> V_8 . V_89 + V_8 -> V_8 . V_83 ;
if ( ! V_143 -> V_169 ) {
V_161 = V_143 -> V_170 + V_143 -> V_171 ;
if ( V_163 )
memcpy ( V_161 , V_162 , V_160 ) ;
else
memcpy ( V_162 , V_161 , V_160 ) ;
return V_160 ;
}
if ( ! V_150 -> V_152 ) {
T_4 V_79 = V_172 ;
if ( V_163 )
V_79 |= V_173 ;
else
V_79 |= V_174 ;
F_102 ( V_165 , V_143 -> V_175 , V_143 -> V_169 , V_79 ) ;
V_150 -> V_152 = 1 ;
}
V_168 = F_103 ( V_165 ) ;
if ( V_168 == false ) {
F_104 ( 1 ) ;
return - V_67 ;
}
do {
V_161 = V_165 -> V_176 ;
V_167 = F_57 ( T_4 , V_160 , V_165 -> V_87 ) ;
V_165 -> V_177 = V_167 ;
V_166 += V_167 ;
if ( V_163 )
memcpy ( V_161 , V_162 , V_167 ) ;
else
memcpy ( V_162 , V_161 , V_167 ) ;
V_160 -= V_167 ;
if ( ! V_160 )
break;
V_168 = F_103 ( V_165 ) ;
if ( V_168 == false ) {
F_104 ( 1 ) ;
return - V_67 ;
}
V_162 += V_167 ;
} while ( 1 );
F_105 ( V_165 ) ;
return V_166 ;
}
static int F_106 ( struct V_9 * V_32 , struct V_143 * V_143 ,
struct V_1 * V_4 , int V_178 , int * V_28 )
{
struct V_17 * V_13 = V_32 -> V_13 ;
struct V_5 * V_8 ;
V_179:
F_19 (req, &ep->queue, queue) {
unsigned V_180 , V_181 , V_160 ;
int V_182 , V_163 ;
int V_183 = 0 ;
if ( F_84 ( V_32 , V_143 ) ) {
if ( ( V_143 -> V_149 != V_8 -> V_8 . V_149 ) )
continue;
}
V_180 = V_143 -> V_184 - V_143 -> V_171 ;
V_181 = V_8 -> V_8 . V_87 - V_8 -> V_8 . V_83 ;
V_160 = F_107 ( V_180 , V_181 ) ;
V_163 = F_101 ( V_143 -> V_145 ) ;
if ( F_95 ( V_160 == 0 ) )
V_182 = 1 ;
else {
if ( V_178 < V_4 -> V_4 . V_74 && V_178 < V_160 )
break;
V_160 = F_57 ( unsigned , V_160 , V_178 ) ;
if ( V_160 == 0 )
break;
if ( V_160 > V_4 -> V_4 . V_74 ) {
V_183 = 1 ;
V_160 -= ( V_160 % V_4 -> V_4 . V_74 ) ;
}
V_182 = ( V_160 % V_4 -> V_4 . V_74 ) != 0 ;
V_160 = F_100 ( V_143 , V_8 , V_160 ) ;
V_4 -> V_129 = V_105 ;
if ( ( int ) V_160 < 0 ) {
V_8 -> V_8 . V_28 = V_160 ;
} else {
V_178 -= V_160 ;
V_143 -> V_171 += V_160 ;
V_8 -> V_8 . V_83 += V_160 ;
}
}
if ( V_182 ) {
if ( V_180 == V_181 ) {
V_8 -> V_8 . V_28 = 0 ;
* V_28 = 0 ;
} else if ( V_163 ) {
V_8 -> V_8 . V_28 = 0 ;
if ( V_181 > V_180 )
* V_28 = - V_185 ;
else
* V_28 = 0 ;
} else if ( ! V_163 ) {
* V_28 = 0 ;
if ( V_180 > V_181 )
V_8 -> V_8 . V_28 = - V_185 ;
else
V_8 -> V_8 . V_28 = 0 ;
}
} else {
if ( V_8 -> V_8 . V_87 == V_8 -> V_8 . V_83
&& ! V_8 -> V_8 . V_186 )
V_8 -> V_8 . V_28 = 0 ;
if ( V_143 -> V_184 == V_143 -> V_171
&& ! ( V_143 -> V_187
& V_188 ) )
* V_28 = 0 ;
}
if ( V_8 -> V_8 . V_28 != - V_82 ) {
F_14 ( & V_8 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_16 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_17 ( & V_13 -> V_30 ) ;
V_183 = 1 ;
}
if ( * V_28 != - V_82 )
break;
if ( V_183 )
goto V_179;
}
return V_178 ;
}
static int F_108 ( struct V_17 * V_13 , struct V_1 * V_4 )
{
int V_178 = V_4 -> V_4 . V_74 ;
if ( V_13 -> V_18 . V_22 == V_70 ) {
int V_189 ;
V_189 = F_25 ( V_4 -> V_60 ) ;
V_189 = ( V_189 >> 11 ) & 0x03 ;
V_189 *= 8 ;
V_178 += V_178 * V_189 ;
}
if ( V_13 -> V_18 . V_22 == V_23 ) {
switch ( F_26 ( V_4 -> V_60 ) ) {
case V_73 :
V_178 = 3 * 16 * 1024 * 8 ;
break;
case V_72 :
V_178 = 3 * 1024 * 8 ;
break;
case V_68 :
default:
break;
}
}
return V_178 ;
}
static struct V_1 * F_109 ( struct V_17 * V_13 , V_112 V_31 )
{
int V_120 ;
if ( ! F_110 ( ( V_13 -> V_18 . V_22 == V_23 ?
V_13 -> V_24 : V_13 -> V_25 ) ) )
return NULL ;
if ( ( V_31 & ~ V_85 ) == 0 )
return & V_13 -> V_4 [ 0 ] ;
for ( V_120 = 1 ; V_120 < V_122 ; V_120 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_120 ] ;
if ( ! V_4 -> V_60 )
continue;
if ( V_4 -> V_60 -> V_84 == V_31 )
return V_4 ;
}
return NULL ;
}
static int F_111 ( struct V_9 * V_32 , struct V_143 * V_143 ,
struct V_190 * V_191 ,
int * V_28 )
{
struct V_1 * V_192 ;
struct V_17 * V_13 = V_32 -> V_13 ;
int V_193 = 1 ;
unsigned V_194 ;
unsigned V_195 ;
V_194 = F_112 ( V_191 -> V_196 ) ;
V_195 = F_112 ( V_191 -> V_197 ) ;
switch ( V_191 -> V_198 ) {
case V_199 :
if ( V_191 -> V_200 != V_201 )
break;
V_13 -> V_31 = V_195 ;
* V_28 = 0 ;
F_30 ( F_7 ( V_13 ) , L_22 ,
V_195 ) ;
V_193 = 0 ;
break;
case V_202 :
if ( V_191 -> V_200 == V_201 ) {
V_193 = 0 ;
switch ( V_195 ) {
case V_101 :
break;
case V_100 :
V_13 -> V_18 . V_203 = 1 ;
break;
case V_204 :
V_13 -> V_18 . V_205 = 1 ;
break;
case V_206 :
V_13 -> V_18 . V_207 = 1 ;
break;
case V_208 :
if ( F_5 ( V_32 ) -> V_22 ==
V_33 )
V_195 = V_209 ;
else
V_193 = - V_210 ;
break;
case V_211 :
if ( F_5 ( V_32 ) -> V_22 ==
V_33 )
V_195 = V_212 ;
else
V_193 = - V_210 ;
break;
case V_213 :
if ( F_5 ( V_32 ) -> V_22 ==
V_33 )
V_195 = V_214 ;
else
V_193 = - V_210 ;
break;
default:
V_193 = - V_210 ;
}
if ( V_193 == 0 ) {
V_13 -> V_99 |= ( 1 << V_195 ) ;
* V_28 = 0 ;
}
} else if ( V_191 -> V_200 == V_215 ) {
V_192 = F_109 ( V_13 , V_194 ) ;
if ( ! V_192 || V_192 -> V_4 . V_63 == V_64 ) {
V_193 = - V_210 ;
break;
}
V_192 -> V_77 = 1 ;
V_193 = 0 ;
* V_28 = 0 ;
}
break;
case V_216 :
if ( V_191 -> V_200 == V_201 ) {
V_193 = 0 ;
switch ( V_195 ) {
case V_101 :
V_195 = V_101 ;
break;
case V_208 :
if ( F_5 ( V_32 ) -> V_22 ==
V_33 )
V_195 = V_209 ;
else
V_193 = - V_210 ;
break;
case V_211 :
if ( F_5 ( V_32 ) -> V_22 ==
V_33 )
V_195 = V_212 ;
else
V_193 = - V_210 ;
break;
case V_213 :
if ( F_5 ( V_32 ) -> V_22 ==
V_33 )
V_195 = V_214 ;
else
V_193 = - V_210 ;
break;
default:
V_193 = - V_210 ;
break;
}
if ( V_193 == 0 ) {
V_13 -> V_99 &= ~ ( 1 << V_195 ) ;
* V_28 = 0 ;
}
} else if ( V_191 -> V_200 == V_215 ) {
V_192 = F_109 ( V_13 , V_194 ) ;
if ( ! V_192 ) {
V_193 = - V_210 ;
break;
}
if ( ! V_192 -> V_78 )
V_192 -> V_77 = 0 ;
V_193 = 0 ;
* V_28 = 0 ;
}
break;
case V_217 :
if ( V_191 -> V_200 == V_218
|| V_191 -> V_200 == V_219
|| V_191 -> V_200 == V_220 ) {
char * V_89 ;
V_89 = ( char * ) V_143 -> V_170 ;
if ( V_143 -> V_184 > 0 ) {
if ( V_191 -> V_200 == V_220 ) {
V_192 = F_109 ( V_13 , V_194 ) ;
if ( ! V_192 ) {
V_193 = - V_210 ;
break;
}
V_89 [ 0 ] = V_192 -> V_77 ;
} else if ( V_191 -> V_200 ==
V_218 ) {
V_89 [ 0 ] = ( V_112 ) V_13 -> V_99 ;
} else
V_89 [ 0 ] = 0 ;
}
if ( V_143 -> V_184 > 1 )
V_89 [ 1 ] = 0 ;
V_143 -> V_171 = F_57 ( T_4 , 2 ,
V_143 -> V_184 ) ;
V_193 = 0 ;
* V_28 = 0 ;
}
break;
}
return V_193 ;
}
static void F_113 ( unsigned long V_221 )
{
struct V_9 * V_32 = (struct V_9 * ) V_221 ;
struct V_17 * V_13 = V_32 -> V_13 ;
struct V_150 * V_150 , * V_189 ;
unsigned long V_79 ;
int V_178 , V_222 ;
int V_120 ;
switch ( V_13 -> V_18 . V_22 ) {
case V_223 :
V_222 = 8 * 12 ;
break;
case V_71 :
V_222 = 64 * 19 ;
break;
case V_70 :
V_222 = 512 * 13 * 8 ;
break;
case V_23 :
V_222 = 490000 ;
break;
default:
F_29 ( F_6 ( V_32 ) , L_23 ) ;
return;
}
F_32 ( & V_13 -> V_30 , V_79 ) ;
if ( ! V_32 -> V_153 ) {
F_29 ( F_6 ( V_32 ) ,
L_24 ) ;
F_33 ( & V_13 -> V_30 , V_79 ) ;
return;
}
for ( V_120 = 0 ; V_120 < V_122 ; V_120 ++ ) {
if ( ! V_123 [ V_120 ] )
break;
V_13 -> V_4 [ V_120 ] . V_126 = 0 ;
}
V_224:
F_114 (urbp, tmp, &dum_hcd->urbp_list, urbp_list) {
struct V_143 * V_143 ;
struct V_5 * V_8 ;
V_112 V_31 ;
struct V_1 * V_4 = NULL ;
int type ;
int V_28 = - V_82 ;
V_143 = V_150 -> V_143 ;
if ( V_143 -> V_225 )
goto V_226;
else if ( V_32 -> V_44 != V_159 )
continue;
type = F_96 ( V_143 -> V_145 ) ;
if ( V_222 <= 0 && type == V_227 )
continue;
V_31 = F_86 ( V_143 -> V_145 ) ;
if ( F_101 ( V_143 -> V_145 ) )
V_31 |= V_85 ;
V_4 = F_109 ( V_13 , V_31 ) ;
if ( ! V_4 ) {
F_30 ( F_6 ( V_32 ) ,
L_25 ,
V_143 ) ;
V_28 = - V_228 ;
goto V_226;
}
if ( V_4 -> V_126 )
continue;
V_4 -> V_126 = 1 ;
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_143 -> V_157 ) {
V_4 -> V_127 = 1 ;
V_143 -> V_157 = 0 ;
}
if ( V_4 -> V_77 && ! V_4 -> V_127 ) {
F_30 ( F_6 ( V_32 ) , L_26 ,
V_4 -> V_4 . V_63 , V_143 ) ;
V_28 = - V_229 ;
goto V_226;
}
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_4 -> V_127 ) {
struct V_190 V_191 ;
int V_93 = 1 ;
V_191 = * (struct V_190 * ) V_143 -> V_230 ;
F_19 (req, &ep->queue, queue) {
F_14 ( & V_8 -> V_26 ) ;
V_8 -> V_8 . V_28 = - V_185 ;
F_30 ( F_7 ( V_13 ) , L_27 ,
V_8 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_16 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_17 ( & V_13 -> V_30 ) ;
V_4 -> V_126 = 0 ;
goto V_224;
}
V_4 -> V_129 = V_105 ;
V_4 -> V_127 = 0 ;
V_4 -> V_77 = 0 ;
V_93 = F_111 ( V_32 , V_143 , & V_191 ,
& V_28 ) ;
if ( V_93 > 0 ) {
F_15 ( & V_13 -> V_30 ) ;
V_93 = V_13 -> V_55 -> V_191 ( & V_13 -> V_18 ,
& V_191 ) ;
F_17 ( & V_13 -> V_30 ) ;
if ( V_93 >= 0 ) {
V_178 = 64 * 1024 ;
goto V_231;
}
}
if ( V_93 < 0 ) {
if ( V_93 != - V_210 )
F_30 ( F_7 ( V_13 ) ,
L_28 ,
V_93 ) ;
V_28 = - V_229 ;
V_143 -> V_171 = 0 ;
}
goto V_226;
}
V_178 = V_222 ;
switch ( F_96 ( V_143 -> V_145 ) ) {
case V_232 :
V_178 = V_61 ( V_178 , F_108 ( V_13 , V_4 ) ) ;
V_28 = - V_233 ;
break;
case V_234 :
V_178 = V_61 ( V_178 , F_108 ( V_13 , V_4 ) ) ;
default:
V_231:
V_4 -> V_129 = V_105 ;
V_222 = F_106 ( V_32 , V_143 , V_4 , V_178 , & V_28 ) ;
break;
}
if ( V_28 == - V_82 )
continue;
V_226:
F_115 ( & V_150 -> V_154 ) ;
F_39 ( V_150 ) ;
if ( V_4 )
V_4 -> V_126 = V_4 -> V_127 = 0 ;
F_116 ( F_5 ( V_32 ) , V_143 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_117 ( F_5 ( V_32 ) , V_143 , V_28 ) ;
F_17 ( & V_13 -> V_30 ) ;
goto V_224;
}
if ( F_12 ( & V_32 -> V_154 ) ) {
F_118 ( V_32 -> V_153 ) ;
V_32 -> V_153 = NULL ;
} else if ( V_32 -> V_44 == V_159 ) {
F_53 ( & V_32 -> V_158 , V_105 + F_52 ( 1 ) ) ;
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
V_32 -> V_34 |= ( V_235 << 16 ) ;
V_32 -> V_34 &= ~ V_50 ;
F_21 ( V_32 ) ;
}
if ( ( V_32 -> V_34 & V_236 ) != 0 ) {
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
F_123 ( struct V_237 * V_60 )
{
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_65 = 0x2a ;
V_60 -> V_238 = 12 ;
V_60 -> V_239 = F_124 ( 0x0001 ) ;
V_60 -> V_240 = 1 ;
V_60 -> V_241 . V_242 . V_243 = 0x04 ;
V_60 -> V_241 . V_242 . V_244 = 0xffff ;
}
static inline void F_125 ( struct V_237 * V_60 )
{
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_65 = 0x29 ;
V_60 -> V_238 = 9 ;
V_60 -> V_239 = F_124 ( 0x0001 ) ;
V_60 -> V_240 = 1 ;
V_60 -> V_241 . V_245 . V_244 [ 0 ] = 0xff ;
V_60 -> V_241 . V_245 . V_244 [ 1 ] = 0xff ;
}
static int F_126 (
struct V_10 * V_11 ,
T_5 V_246 ,
T_5 V_197 ,
T_5 V_196 ,
char * V_89 ,
T_5 V_247
) {
struct V_9 * V_32 ;
int V_62 = 0 ;
unsigned long V_79 ;
if ( ! F_120 ( V_11 ) )
return - V_248 ;
V_32 = F_4 ( V_11 ) ;
F_32 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
switch ( V_246 ) {
case V_249 :
break;
case V_250 :
switch ( V_197 ) {
case V_251 :
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
case V_252 :
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
V_32 -> V_34 &= ~ ( 1 << V_197 ) ;
F_21 ( V_32 ) ;
}
break;
case V_253 :
if ( V_11 -> V_22 == V_33 &&
( V_247 < V_254 ||
V_197 != ( V_255 << 8 ) ) ) {
F_30 ( F_6 ( V_32 ) ,
L_33
L_34 ) ;
goto error;
}
if ( V_11 -> V_22 == V_33 )
F_123 ( (struct V_237 * ) V_89 ) ;
else
F_125 ( (struct V_237 * ) V_89 ) ;
break;
case V_256 | V_257 :
if ( V_11 -> V_22 != V_33 )
goto error;
if ( ( V_197 >> 8 ) != V_258 )
goto error;
memcpy ( V_89 , & V_259 , sizeof( V_259 ) ) ;
V_62 = sizeof( V_259 ) ;
break;
case V_260 :
* ( V_261 * ) V_89 = F_127 ( 0 ) ;
break;
case V_262 :
if ( V_196 != 1 )
V_62 = - V_229 ;
if ( V_32 -> V_51 &&
F_121 ( V_105 , V_32 -> V_104 ) ) {
V_32 -> V_34 |= ( V_235 << 16 ) ;
V_32 -> V_34 &= ~ V_50 ;
}
if ( ( V_32 -> V_34 & V_52 ) != 0 &&
F_121 ( V_105 , V_32 -> V_104 ) ) {
V_32 -> V_34 |= ( V_263 << 16 ) ;
V_32 -> V_34 &= ~ V_52 ;
if ( V_32 -> V_13 -> V_36 ) {
V_32 -> V_34 |= V_39 ;
if ( V_11 -> V_22 < V_33 ) {
switch ( V_32 -> V_13 -> V_18 . V_22 ) {
case V_70 :
V_32 -> V_34 |=
V_49 ;
break;
case V_223 :
V_32 -> V_13 -> V_18 . V_130 ->
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
( ( V_264 * ) V_89 ) [ 0 ] = F_124 ( V_32 -> V_34 ) ;
( ( V_264 * ) V_89 ) [ 1 ] = F_124 ( V_32 -> V_34 >> 16 ) ;
break;
case V_265 :
V_62 = - V_229 ;
break;
case V_266 :
switch ( V_197 ) {
case V_267 :
if ( V_11 -> V_22 != V_33 ) {
F_30 ( F_6 ( V_32 ) ,
L_35
L_36 ) ;
goto error;
}
break;
case V_268 :
case V_269 :
if ( V_11 -> V_22 != V_33 ) {
F_30 ( F_6 ( V_32 ) ,
L_37
L_36 ) ;
goto error;
}
break;
case V_251 :
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
case V_252 :
if ( V_11 -> V_22 == V_33 )
V_32 -> V_34 |= V_35 ;
else
V_32 -> V_34 |= V_47 ;
F_21 ( V_32 ) ;
break;
case V_270 :
if ( V_11 -> V_22 != V_33 ) {
F_30 ( F_6 ( V_32 ) ,
L_39
L_36 ) ;
goto error;
}
case V_271 :
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
( 1 << V_107 ) ;
V_32 -> V_104 = V_105 + F_52 ( 50 ) ;
default:
if ( V_11 -> V_22 == V_33 ) {
if ( ( V_32 -> V_34 &
V_35 ) != 0 ) {
V_32 -> V_34 |= ( 1 << V_197 ) ;
F_21 ( V_32 ) ;
}
} else
if ( ( V_32 -> V_34 &
V_47 ) != 0 ) {
V_32 -> V_34 |= ( 1 << V_197 ) ;
F_21 ( V_32 ) ;
}
}
break;
case V_272 :
if ( V_11 -> V_22 != V_33 ) {
F_30 ( F_6 ( V_32 ) ,
L_40
L_36 ) ;
goto error;
}
* ( V_261 * ) V_89 = F_127 ( 0 ) ;
break;
case V_273 :
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
V_246 , V_197 , V_196 , V_247 ) ;
error:
V_62 = - V_229 ;
}
F_33 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
if ( ( V_32 -> V_34 & V_236 ) != 0 )
F_59 ( V_11 ) ;
return V_62 ;
}
static int F_128 ( struct V_10 * V_11 )
{
struct V_9 * V_32 = F_4 ( V_11 ) ;
F_30 ( & V_11 -> V_15 . V_274 -> V_19 , L_19 , V_141 ) ;
F_77 ( & V_32 -> V_13 -> V_30 ) ;
V_32 -> V_44 = V_45 ;
F_21 ( V_32 ) ;
V_11 -> V_140 = V_275 ;
F_78 ( & V_32 -> V_13 -> V_30 ) ;
return 0 ;
}
static int F_129 ( struct V_10 * V_11 )
{
struct V_9 * V_32 = F_4 ( V_11 ) ;
int V_134 = 0 ;
F_30 ( & V_11 -> V_15 . V_274 -> V_19 , L_19 , V_141 ) ;
F_77 ( & V_32 -> V_13 -> V_30 ) ;
if ( ! F_120 ( V_11 ) ) {
V_134 = - V_29 ;
} else {
V_32 -> V_44 = V_159 ;
F_21 ( V_32 ) ;
if ( ! F_12 ( & V_32 -> V_154 ) )
F_53 ( & V_32 -> V_158 , V_105 ) ;
V_11 -> V_140 = V_276 ;
}
F_78 ( & V_32 -> V_13 -> V_30 ) ;
return V_134 ;
}
static inline T_2 F_130 ( char * V_89 , T_6 V_277 , struct V_143 * V_143 )
{
int V_4 = F_86 ( V_143 -> V_145 ) ;
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
static T_2 F_131 ( struct V_14 * V_19 , struct V_113 * V_114 ,
char * V_89 )
{
struct V_10 * V_11 = F_132 ( V_19 ) ;
struct V_9 * V_32 = F_4 ( V_11 ) ;
struct V_150 * V_150 ;
T_6 V_277 = 0 ;
unsigned long V_79 ;
F_32 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
F_19 (urbp, &dum_hcd->urbp_list, urbp_list) {
T_6 V_278 ;
V_278 = F_130 ( V_89 , V_116 - V_277 , V_150 -> V_143 ) ;
V_89 += V_278 ;
V_277 += V_278 ;
}
F_33 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
return V_277 ;
}
static int F_133 ( struct V_9 * V_32 )
{
F_134 ( & V_32 -> V_158 ) ;
V_32 -> V_158 . V_115 = F_113 ;
V_32 -> V_158 . V_279 = ( unsigned long ) V_32 ;
V_32 -> V_44 = V_159 ;
V_32 -> V_144 = 0 ;
F_36 ( & V_32 -> V_154 ) ;
F_5 ( V_32 ) -> V_280 = V_281 ;
F_5 ( V_32 ) -> V_140 = V_276 ;
F_5 ( V_32 ) -> V_282 = 1 ;
#ifdef F_66
F_5 ( V_32 ) -> V_15 . V_283 = 1 ;
#endif
return 0 ;
return F_70 ( F_6 ( V_32 ) , & V_284 ) ;
}
static int F_135 ( struct V_10 * V_11 )
{
struct V_9 * V_32 = F_4 ( V_11 ) ;
if ( ! F_136 ( V_11 ) )
return F_133 ( V_32 ) ;
F_137 ( & V_32 -> V_13 -> V_30 ) ;
F_134 ( & V_32 -> V_158 ) ;
V_32 -> V_158 . V_115 = F_113 ;
V_32 -> V_158 . V_279 = ( unsigned long ) V_32 ;
V_32 -> V_44 = V_159 ;
F_36 ( & V_32 -> V_154 ) ;
V_11 -> V_280 = V_281 ;
V_11 -> V_140 = V_276 ;
V_11 -> V_282 = 1 ;
#ifdef F_66
V_11 -> V_15 . V_283 = 1 ;
#endif
return F_70 ( F_6 ( V_32 ) , & V_284 ) ;
}
static void F_138 ( struct V_10 * V_11 )
{
struct V_17 * V_13 ;
V_13 = F_4 ( V_11 ) -> V_13 ;
F_75 ( F_6 ( F_4 ( V_11 ) ) , & V_284 ) ;
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
V_11 -> V_15 . V_285 = ~ 0 ;
if ( F_136 ( V_11 ) ) {
V_13 -> V_25 = F_4 ( V_11 ) ;
V_13 -> V_25 -> V_13 = V_13 ;
V_11 -> V_22 = V_286 ;
V_11 -> V_15 . V_274 -> V_22 = V_70 ;
} else {
V_13 -> V_24 = F_4 ( V_11 ) ;
V_13 -> V_24 -> V_13 = V_13 ;
V_11 -> V_22 = V_33 ;
V_11 -> V_15 . V_274 -> V_22 = V_23 ;
}
return 0 ;
}
static int F_142 ( struct V_10 * V_11 , struct V_287 * V_153 ,
struct V_288 * * V_289 , unsigned int V_290 ,
unsigned int V_291 , T_1 V_80 )
{
struct V_9 * V_32 = F_4 ( V_11 ) ;
unsigned long V_79 ;
int V_292 ;
int V_293 = V_291 ;
unsigned int V_142 ;
unsigned int V_120 ;
if ( ! V_290 )
return - V_67 ;
F_32 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
for ( V_120 = 0 ; V_120 < V_290 ; V_120 ++ ) {
V_142 = F_81 ( & V_289 [ V_120 ] -> V_60 ) ;
if ( ( 1 << V_142 ) & V_32 -> V_144 ) {
V_293 = - V_67 ;
goto V_294;
}
V_292 = F_27 ( & V_289 [ V_120 ] -> V_295 ) ;
if ( ! V_292 ) {
V_293 = - V_67 ;
goto V_294;
}
if ( V_292 < V_293 ) {
F_30 ( F_6 ( V_32 ) , L_52
L_53 ,
V_289 [ V_120 ] -> V_60 . V_84 ,
V_292 ) ;
V_293 = V_292 ;
}
}
for ( V_120 = 0 ; V_120 < V_290 ; V_120 ++ ) {
V_142 = F_81 ( & V_289 [ V_120 ] -> V_60 ) ;
V_32 -> V_144 |= 1 << V_142 ;
F_88 ( V_32 ,
F_82 ( & V_289 [ V_120 ] -> V_60 ) , V_293 ) ;
}
V_294:
F_33 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
return V_293 ;
}
static int F_143 ( struct V_10 * V_11 , struct V_287 * V_153 ,
struct V_288 * * V_289 , unsigned int V_290 ,
T_1 V_80 )
{
struct V_9 * V_32 = F_4 ( V_11 ) ;
unsigned long V_79 ;
int V_296 ;
unsigned int V_142 ;
unsigned int V_120 ;
F_32 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
for ( V_120 = 0 ; V_120 < V_290 ; V_120 ++ ) {
V_142 = F_81 ( & V_289 [ V_120 ] -> V_60 ) ;
if ( ! ( ( 1 << V_142 ) & V_32 -> V_144 ) ) {
V_296 = - V_67 ;
goto V_294;
}
}
for ( V_120 = 0 ; V_120 < V_290 ; V_120 ++ ) {
V_142 = F_81 ( & V_289 [ V_120 ] -> V_60 ) ;
V_32 -> V_144 &= ~ ( 1 << V_142 ) ;
F_88 ( V_32 ,
F_82 ( & V_289 [ V_120 ] -> V_60 ) , 0 ) ;
}
V_296 = 0 ;
V_294:
F_33 ( & V_32 -> V_13 -> V_30 , V_79 ) ;
return V_296 ;
}
static int F_144 ( struct V_132 * V_133 )
{
struct V_17 * V_13 ;
struct V_10 * V_25 ;
struct V_10 * V_24 ;
int V_62 ;
F_139 ( & V_133 -> V_19 , L_54 V_297 L_55 , V_298 ) ;
V_13 = * ( ( void * * ) F_68 ( & V_133 -> V_19 ) ) ;
if ( ! V_108 . V_109 )
V_9 . V_79 = V_286 ;
V_25 = F_145 ( & V_9 , & V_133 -> V_19 , F_146 ( & V_133 -> V_19 ) ) ;
if ( ! V_25 )
return - V_151 ;
V_25 -> V_299 = 1 ;
V_62 = F_147 ( V_25 , 0 , 0 ) ;
if ( V_62 )
goto V_300;
if ( V_108 . V_109 ) {
V_24 = F_148 ( & V_9 , & V_133 -> V_19 ,
F_146 ( & V_133 -> V_19 ) , V_25 ) ;
if ( ! V_24 ) {
V_62 = - V_151 ;
goto V_301;
}
V_62 = F_147 ( V_24 , 0 , 0 ) ;
if ( V_62 )
goto V_302;
}
return 0 ;
V_302:
F_149 ( V_24 ) ;
V_301:
F_150 ( V_25 ) ;
V_300:
F_149 ( V_25 ) ;
V_13 -> V_25 = V_13 -> V_24 = NULL ;
return V_62 ;
}
static int F_151 ( struct V_132 * V_133 )
{
struct V_17 * V_13 ;
V_13 = F_4 ( F_74 ( V_133 ) ) -> V_13 ;
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
static int F_152 ( struct V_132 * V_133 , T_3 V_140 )
{
struct V_10 * V_11 ;
struct V_9 * V_32 ;
int V_134 = 0 ;
F_30 ( & V_133 -> V_19 , L_19 , V_141 ) ;
V_11 = F_74 ( V_133 ) ;
V_32 = F_4 ( V_11 ) ;
if ( V_32 -> V_44 == V_159 ) {
F_153 ( & V_133 -> V_19 , L_56 ) ;
V_134 = - V_303 ;
} else
F_154 ( V_304 , & V_11 -> V_79 ) ;
return V_134 ;
}
static int F_155 ( struct V_132 * V_133 )
{
struct V_10 * V_11 ;
F_30 ( & V_133 -> V_19 , L_19 , V_141 ) ;
V_11 = F_74 ( V_133 ) ;
F_156 ( V_304 , & V_11 -> V_79 ) ;
F_59 ( V_11 ) ;
return 0 ;
}
static int T_7 F_157 ( void )
{
int V_62 = - V_151 ;
int V_120 ;
struct V_17 * V_13 [ V_305 ] ;
if ( F_158 () )
return - V_306 ;
if ( ! V_108 . V_111 && V_108 . V_109 )
return - V_67 ;
if ( V_108 . V_307 < 1 || V_108 . V_307 > V_305 ) {
F_159 ( L_57 ,
V_305 ) ;
return - V_67 ;
}
for ( V_120 = 0 ; V_120 < V_108 . V_307 ; V_120 ++ ) {
V_308 [ V_120 ] = F_160 ( V_309 , V_120 ) ;
if ( ! V_308 [ V_120 ] ) {
V_120 -- ;
while ( V_120 >= 0 )
F_161 ( V_308 [ V_120 -- ] ) ;
return V_62 ;
}
}
for ( V_120 = 0 ; V_120 < V_108 . V_307 ; V_120 ++ ) {
V_310 [ V_120 ] = F_160 ( V_135 , V_120 ) ;
if ( ! V_310 [ V_120 ] ) {
V_120 -- ;
while ( V_120 >= 0 )
F_161 ( V_310 [ V_120 -- ] ) ;
goto V_311;
}
}
for ( V_120 = 0 ; V_120 < V_108 . V_307 ; V_120 ++ ) {
V_13 [ V_120 ] = F_35 ( sizeof( struct V_17 ) , V_312 ) ;
if ( ! V_13 [ V_120 ] ) {
V_62 = - V_151 ;
goto V_313;
}
V_62 = F_162 ( V_308 [ V_120 ] , & V_13 [ V_120 ] ,
sizeof( void * ) ) ;
if ( V_62 )
goto V_313;
V_62 = F_162 ( V_310 [ V_120 ] , & V_13 [ V_120 ] ,
sizeof( void * ) ) ;
if ( V_62 )
goto V_313;
}
V_62 = F_163 ( & V_314 ) ;
if ( V_62 < 0 )
goto V_313;
V_62 = F_163 ( & V_315 ) ;
if ( V_62 < 0 )
goto V_316;
for ( V_120 = 0 ; V_120 < V_108 . V_307 ; V_120 ++ ) {
V_62 = F_164 ( V_308 [ V_120 ] ) ;
if ( V_62 < 0 ) {
V_120 -- ;
while ( V_120 >= 0 )
F_165 ( V_308 [ V_120 -- ] ) ;
goto V_317;
}
}
for ( V_120 = 0 ; V_120 < V_108 . V_307 ; V_120 ++ ) {
if ( ! V_13 [ V_120 ] -> V_25 ||
( ! V_13 [ V_120 ] -> V_24 && V_108 . V_109 ) ) {
V_62 = - V_67 ;
goto V_318;
}
}
for ( V_120 = 0 ; V_120 < V_108 . V_307 ; V_120 ++ ) {
V_62 = F_164 ( V_310 [ V_120 ] ) ;
if ( V_62 < 0 ) {
V_120 -- ;
while ( V_120 >= 0 )
F_165 ( V_310 [ V_120 ] ) ;
goto V_318;
}
}
for ( V_120 = 0 ; V_120 < V_108 . V_307 ; V_120 ++ ) {
if ( ! F_74 ( V_310 [ V_120 ] ) ) {
V_62 = - V_67 ;
goto V_319;
}
}
return V_62 ;
V_319:
for ( V_120 = 0 ; V_120 < V_108 . V_307 ; V_120 ++ )
F_165 ( V_310 [ V_120 ] ) ;
V_318:
for ( V_120 = 0 ; V_120 < V_108 . V_307 ; V_120 ++ )
F_165 ( V_308 [ V_120 ] ) ;
V_317:
F_166 ( & V_315 ) ;
V_316:
F_166 ( & V_314 ) ;
V_313:
for ( V_120 = 0 ; V_120 < V_108 . V_307 ; V_120 ++ )
F_39 ( V_13 [ V_120 ] ) ;
for ( V_120 = 0 ; V_120 < V_108 . V_307 ; V_120 ++ )
F_161 ( V_310 [ V_120 ] ) ;
V_311:
for ( V_120 = 0 ; V_120 < V_108 . V_307 ; V_120 ++ )
F_161 ( V_308 [ V_120 ] ) ;
return V_62 ;
}
static void T_8 F_167 ( void )
{
int V_120 ;
for ( V_120 = 0 ; V_120 < V_108 . V_307 ; V_120 ++ ) {
struct V_17 * V_13 ;
V_13 = * ( ( void * * ) F_68 ( & V_310 [ V_120 ] -> V_19 ) ) ;
F_168 ( V_310 [ V_120 ] ) ;
F_168 ( V_308 [ V_120 ] ) ;
F_39 ( V_13 ) ;
}
F_166 ( & V_315 ) ;
F_166 ( & V_314 ) ;
}
