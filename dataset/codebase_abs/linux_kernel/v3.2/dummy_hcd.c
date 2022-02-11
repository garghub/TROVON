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
static void
F_17 ( struct V_17 * V_13 )
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
static int
F_21 ( struct V_2 * V_3 , const struct V_59 * V_60 )
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
switch ( V_60 -> V_68 & 0x03 ) {
case V_69 :
if ( strstr ( V_4 -> V_4 . V_63 , L_1 )
|| strstr ( V_4 -> V_4 . V_63 , L_2 ) ) {
goto V_70;
}
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
if ( V_61 == 1024 )
break;
goto V_70;
case V_71 :
if ( V_61 == 512 )
break;
goto V_70;
case V_72 :
if ( V_61 == 8 || V_61 == 16 || V_61 == 32 || V_61 == 64 )
break;
default:
goto V_70;
}
break;
case V_73 :
if ( strstr ( V_4 -> V_4 . V_63 , L_1 ) )
goto V_70;
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
case V_71 :
if ( V_61 <= 1024 )
break;
case V_72 :
if ( V_61 <= 64 )
break;
default:
if ( V_61 <= 8 )
break;
goto V_70;
}
break;
case V_74 :
if ( strstr ( V_4 -> V_4 . V_63 , L_3 )
|| strstr ( V_4 -> V_4 . V_63 , L_2 ) )
goto V_70;
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
case V_71 :
if ( V_61 <= 1024 )
break;
case V_72 :
if ( V_61 <= 1023 )
break;
default:
goto V_70;
}
break;
default:
goto V_70;
}
V_3 -> V_75 = V_61 ;
V_4 -> V_60 = V_60 ;
F_24 (udc_dev(dum), L_4 ,
_ep->name,
desc->bEndpointAddress & 0x0f ,
(desc->bEndpointAddress & USB_DIR_IN) ? L_5 : L_6 ,
({ char *val;
switch (desc->bmAttributes & 0x03) {
case USB_ENDPOINT_XFER_BULK:
val = L_7;
break;
case USB_ENDPOINT_XFER_ISOC:
val = L_8;
break;
case USB_ENDPOINT_XFER_INT:
val = L_9;
break;
default:
val = L_10;
break;
}; val; }),
max) ;
V_4 -> V_76 = V_4 -> V_77 = 0 ;
V_62 = 0 ;
V_70:
return V_62 ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
unsigned long V_78 ;
int V_62 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_4 -> V_60 || V_3 -> V_63 == V_64 )
return - V_67 ;
V_13 = F_8 ( V_4 ) ;
F_26 ( & V_13 -> V_30 , V_78 ) ;
V_4 -> V_60 = NULL ;
V_62 = 0 ;
F_11 ( V_13 , V_4 ) ;
F_27 ( & V_13 -> V_30 , V_78 ) ;
F_24 ( F_7 ( V_13 ) , L_11 , V_3 -> V_63 ) ;
return V_62 ;
}
static struct V_6 *
F_28 ( struct V_2 * V_3 , T_1 V_79 )
{
struct V_1 * V_4 ;
struct V_5 * V_8 ;
if ( ! V_3 )
return NULL ;
V_4 = F_1 ( V_3 ) ;
V_8 = F_29 ( sizeof( * V_8 ) , V_79 ) ;
if ( ! V_8 )
return NULL ;
F_30 ( & V_8 -> V_26 ) ;
return & V_8 -> V_8 ;
}
static void
F_31 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_1 * V_4 ;
struct V_5 * V_8 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || ! V_7 || ( ! V_4 -> V_60 && V_3 -> V_63 != V_64 ) )
return;
V_8 = F_3 ( V_7 ) ;
F_32 ( ! F_12 ( & V_8 -> V_26 ) ) ;
F_33 ( V_8 ) ;
}
static void
F_34 ( struct V_2 * V_4 , struct V_6 * V_8 )
{
}
static int
F_35 ( struct V_2 * V_3 , struct V_6 * V_7 ,
T_1 V_79 )
{
struct V_1 * V_4 ;
struct V_5 * V_8 ;
struct V_17 * V_13 ;
struct V_9 * V_33 ;
unsigned long V_78 ;
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
dev_dbg (udc_dev(dum), "ep %p queue req %p to %s, len %d buf %p\n",
ep, _req, _ep->name, _req->length, _req->buf);
#endif
V_7 -> V_28 = - V_80 ;
V_7 -> V_81 = 0 ;
F_26 ( & V_13 -> V_30 , V_78 ) ;
if ( V_4 -> V_60 && ( V_4 -> V_60 -> V_82 & V_83 ) &&
F_12 ( & V_13 -> V_84 . V_26 ) &&
F_12 ( & V_4 -> V_26 ) &&
V_7 -> V_85 <= V_86 ) {
V_8 = & V_13 -> V_84 ;
V_8 -> V_8 = * V_7 ;
V_8 -> V_8 . V_87 = V_13 -> V_88 ;
memcpy ( V_13 -> V_88 , V_7 -> V_87 , V_7 -> V_85 ) ;
V_8 -> V_8 . V_89 = V_13 ;
V_8 -> V_8 . V_31 = F_34 ;
F_36 ( & V_8 -> V_26 , & V_4 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_7 -> V_81 = V_7 -> V_85 ;
V_7 -> V_28 = 0 ;
V_7 -> V_31 ( V_3 , V_7 ) ;
F_16 ( & V_13 -> V_30 ) ;
} else
F_36 ( & V_8 -> V_26 , & V_4 -> V_26 ) ;
F_27 ( & V_13 -> V_30 , V_78 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
int V_62 = - V_67 ;
unsigned long V_78 ;
struct V_5 * V_8 = NULL ;
if ( ! V_3 || ! V_7 )
return V_62 ;
V_4 = F_1 ( V_3 ) ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_54 )
return - V_29 ;
F_38 ( V_78 ) ;
F_16 ( & V_13 -> V_30 ) ;
F_18 (req, &ep->queue, queue) {
if ( & V_8 -> V_8 == V_7 ) {
F_14 ( & V_8 -> V_26 ) ;
V_7 -> V_28 = - V_90 ;
V_62 = 0 ;
break;
}
}
F_15 ( & V_13 -> V_30 ) ;
if ( V_62 == 0 ) {
F_24 ( F_7 ( V_13 ) ,
L_12 ,
V_8 , V_3 -> V_63 , V_7 -> V_85 , V_7 -> V_87 ) ;
V_7 -> V_31 ( V_3 , V_7 ) ;
}
F_39 ( V_78 ) ;
return V_62 ;
}
static int
F_40 ( struct V_2 * V_3 , int V_91 , int V_77 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
if ( ! V_3 )
return - V_67 ;
V_4 = F_1 ( V_3 ) ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_54 )
return - V_29 ;
if ( ! V_91 )
V_4 -> V_76 = V_4 -> V_77 = 0 ;
else if ( V_4 -> V_60 && ( V_4 -> V_60 -> V_82 & V_83 ) &&
! F_12 ( & V_4 -> V_26 ) )
return - V_92 ;
else {
V_4 -> V_76 = 1 ;
if ( V_77 )
V_4 -> V_77 = 1 ;
}
return 0 ;
}
static int
F_41 ( struct V_2 * V_3 , int V_91 )
{
return F_40 ( V_3 , V_91 , 0 ) ;
}
static int F_42 ( struct V_2 * V_3 )
{
if ( ! V_3 || V_3 -> V_63 == V_64 )
return - V_67 ;
return F_40 ( V_3 , 1 , 1 ) ;
}
static int F_43 ( struct V_21 * V_93 )
{
struct V_94 V_95 ;
F_44 ( & V_95 ) ;
return V_95 . V_96 / 1000 ;
}
static int F_45 ( struct V_21 * V_93 )
{
struct V_9 * V_33 ;
V_33 = F_9 ( V_93 ) ;
if ( ! ( V_33 -> V_13 -> V_97 & ( ( 1 << V_98 )
| ( 1 << V_99 ) ) ) )
return - V_67 ;
if ( ( V_33 -> V_35 & V_39 ) == 0 )
return - V_100 ;
if ( ( V_33 -> V_35 & V_51 ) == 0 &&
V_33 -> V_45 != V_46 )
return - V_101 ;
V_33 -> V_52 = 1 ;
V_33 -> V_102 = V_103 + F_46 ( 20 ) ;
F_47 ( & F_5 ( V_33 ) -> V_104 , V_33 -> V_102 ) ;
return 0 ;
}
static int F_48 ( struct V_21 * V_93 , int V_91 )
{
struct V_17 * V_13 ;
V_13 = ( F_9 ( V_93 ) ) -> V_13 ;
if ( V_91 )
V_13 -> V_97 |= ( 1 << V_105 ) ;
else
V_13 -> V_97 &= ~ ( 1 << V_105 ) ;
return 0 ;
}
static void F_49 ( struct V_17 * V_13 )
{
T_2 V_106 ;
if ( V_13 -> V_18 . V_22 == V_23 ) {
for ( V_106 = 0 ; V_106 < V_107 ; V_106 ++ )
V_13 -> V_4 [ V_106 ] . V_4 . V_108 = 0x10 ;
V_13 -> V_4 [ 0 ] . V_4 . V_75 = 9 ;
} else {
for ( V_106 = 0 ; V_106 < V_107 ; V_106 ++ )
V_13 -> V_4 [ V_106 ] . V_4 . V_108 = 0 ;
V_13 -> V_4 [ 0 ] . V_4 . V_75 = 64 ;
}
}
static int F_50 ( struct V_21 * V_93 , int V_91 )
{
struct V_9 * V_33 ;
struct V_17 * V_13 ;
unsigned long V_78 ;
V_13 = F_10 ( & V_93 -> V_19 ) ;
if ( V_91 && V_13 -> V_54 ) {
if ( V_109 . V_110 )
V_13 -> V_18 . V_22 = V_13 -> V_54 -> V_22 ;
else if ( V_109 . V_111 )
V_13 -> V_18 . V_22 = F_51 ( V_112 , V_71 ,
V_13 -> V_54 -> V_22 ) ;
else
V_13 -> V_18 . V_22 = V_72 ;
F_49 ( V_13 ) ;
if ( V_13 -> V_18 . V_22 < V_13 -> V_54 -> V_22 )
F_24 ( F_7 ( V_13 ) , L_13
L_14 ,
( V_13 -> V_54 -> V_22 == V_23 ?
L_15 : L_16 ) ) ;
}
V_33 = F_9 ( V_93 ) ;
F_26 ( & V_13 -> V_30 , V_78 ) ;
V_13 -> V_37 = ( V_91 != 0 ) ;
F_20 ( V_33 ) ;
F_27 ( & V_13 -> V_30 , V_78 ) ;
F_52 ( F_5 ( V_33 ) ) ;
return 0 ;
}
static T_3
F_53 ( struct V_14 * V_19 , struct V_113 * V_114 , char * V_87 )
{
struct V_17 * V_13 = F_10 ( V_19 ) ;
if ( ! V_13 -> V_54 || ! V_13 -> V_54 -> V_115 )
return 0 ;
return F_54 ( V_87 , V_116 , L_17 , V_13 -> V_54 -> V_115 ) ;
}
static int F_55 ( struct V_21 * V_117 ,
struct V_118 * V_54 )
{
struct V_9 * V_33 = F_9 ( V_117 ) ;
struct V_17 * V_13 = V_33 -> V_13 ;
if ( V_54 -> V_22 == V_119 )
return - V_67 ;
V_13 -> V_97 = 0 ;
V_13 -> V_54 = V_54 ;
F_24 ( F_7 ( V_13 ) , L_18 ,
V_54 -> V_54 . V_63 ) ;
return 0 ;
}
static int F_56 ( struct V_21 * V_117 ,
struct V_118 * V_54 )
{
struct V_9 * V_33 = F_9 ( V_117 ) ;
struct V_17 * V_13 = V_33 -> V_13 ;
F_24 ( F_7 ( V_13 ) , L_19 ,
V_54 -> V_54 . V_63 ) ;
V_13 -> V_54 = NULL ;
F_50 ( & V_13 -> V_18 , 0 ) ;
return 0 ;
}
static void
F_57 ( struct V_14 * V_19 )
{
return;
}
static void F_58 ( struct V_17 * V_13 )
{
int V_106 ;
F_30 ( & V_13 -> V_18 . V_120 ) ;
for ( V_106 = 0 ; V_106 < V_107 ; V_106 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_106 ] ;
if ( ! V_121 [ V_106 ] )
break;
V_4 -> V_4 . V_63 = V_121 [ V_106 ] ;
V_4 -> V_4 . V_122 = & V_123 ;
F_36 ( & V_4 -> V_4 . V_120 , & V_13 -> V_18 . V_120 ) ;
V_4 -> V_76 = V_4 -> V_77 = V_4 -> V_124 =
V_4 -> V_125 = 0 ;
V_4 -> V_4 . V_75 = ~ 0 ;
V_4 -> V_126 = V_103 ;
V_4 -> V_18 = & V_13 -> V_18 ;
V_4 -> V_60 = NULL ;
F_30 ( & V_4 -> V_26 ) ;
}
V_13 -> V_18 . V_127 = & V_13 -> V_4 [ 0 ] . V_4 ;
F_14 ( & V_13 -> V_4 [ 0 ] . V_4 . V_120 ) ;
F_30 ( & V_13 -> V_84 . V_26 ) ;
#ifdef F_59
V_13 -> V_18 . V_128 = 1 ;
#endif
}
static int F_60 ( struct V_129 * V_130 )
{
struct V_17 * V_13 = & V_131 ;
int V_132 ;
V_13 -> V_18 . V_63 = V_133 ;
V_13 -> V_18 . V_122 = & V_134 ;
V_13 -> V_18 . V_135 = 1 ;
F_61 ( & V_13 -> V_18 . V_19 , L_20 ) ;
V_13 -> V_18 . V_19 . V_20 = & V_130 -> V_19 ;
V_13 -> V_18 . V_19 . V_136 = F_57 ;
V_132 = F_62 ( & V_13 -> V_18 . V_19 ) ;
if ( V_132 < 0 ) {
F_63 ( & V_13 -> V_18 . V_19 ) ;
return V_132 ;
}
F_58 ( V_13 ) ;
V_132 = F_64 ( & V_130 -> V_19 , & V_13 -> V_18 ) ;
if ( V_132 < 0 )
goto V_137;
V_132 = F_65 ( & V_13 -> V_18 . V_19 , & V_138 ) ;
if ( V_132 < 0 )
goto V_139;
F_66 ( V_130 , V_13 ) ;
return V_132 ;
V_139:
F_67 ( & V_13 -> V_18 ) ;
V_137:
F_68 ( & V_13 -> V_18 . V_19 ) ;
return V_132 ;
}
static int F_69 ( struct V_129 * V_130 )
{
struct V_17 * V_13 = F_70 ( V_130 ) ;
F_67 ( & V_13 -> V_18 ) ;
F_66 ( V_130 , NULL ) ;
F_71 ( & V_13 -> V_18 . V_19 , & V_138 ) ;
F_68 ( & V_13 -> V_18 . V_19 ) ;
return 0 ;
}
static void F_72 ( struct V_17 * V_13 , struct V_9 * V_33 ,
int V_57 )
{
F_73 ( & V_13 -> V_30 ) ;
V_13 -> V_38 = V_57 ;
F_20 ( V_33 ) ;
F_74 ( & V_13 -> V_30 ) ;
}
static int F_75 ( struct V_129 * V_130 , T_4 V_140 )
{
struct V_17 * V_13 = F_70 ( V_130 ) ;
struct V_9 * V_33 = F_9 ( & V_13 -> V_18 ) ;
F_24 ( & V_130 -> V_19 , L_17 , V_141 ) ;
F_72 ( V_13 , V_33 , 1 ) ;
F_52 ( F_5 ( V_33 ) ) ;
return 0 ;
}
static int F_76 ( struct V_129 * V_130 )
{
struct V_17 * V_13 = F_70 ( V_130 ) ;
struct V_9 * V_33 = F_9 ( & V_13 -> V_18 ) ;
F_24 ( & V_130 -> V_19 , L_17 , V_141 ) ;
F_72 ( V_13 , V_33 , 0 ) ;
F_52 ( F_5 ( V_33 ) ) ;
return 0 ;
}
static int F_77 (
struct V_10 * V_11 ,
struct V_142 * V_142 ,
T_1 V_79
) {
struct V_9 * V_33 ;
struct V_143 * V_143 ;
unsigned long V_78 ;
int V_132 ;
if ( ! V_142 -> V_144 && V_142 -> V_145 )
return - V_67 ;
V_143 = F_78 ( sizeof *V_143 , V_79 ) ;
if ( ! V_143 )
return - V_146 ;
V_143 -> V_142 = V_142 ;
V_33 = F_4 ( V_11 ) ;
F_26 ( & V_33 -> V_13 -> V_30 , V_78 ) ;
V_132 = F_79 ( V_11 , V_142 ) ;
if ( V_132 ) {
F_33 ( V_143 ) ;
goto V_70;
}
if ( ! V_33 -> V_147 ) {
V_33 -> V_147 = V_142 -> V_19 ;
F_80 ( V_33 -> V_147 ) ;
} else if ( F_81 ( V_33 -> V_147 != V_142 -> V_19 ) )
F_82 ( F_6 ( V_33 ) , L_21 ) ;
F_36 ( & V_143 -> V_148 , & V_33 -> V_148 ) ;
V_142 -> V_149 = V_143 ;
if ( F_83 ( V_142 -> V_150 ) == V_151 )
V_142 -> V_152 = 1 ;
if ( ! F_84 ( & V_33 -> V_153 ) )
F_47 ( & V_33 -> V_153 , V_103 + 1 ) ;
V_70:
F_27 ( & V_33 -> V_13 -> V_30 , V_78 ) ;
return V_132 ;
}
static int F_85 ( struct V_10 * V_11 , struct V_142 * V_142 , int V_28 )
{
struct V_9 * V_33 ;
unsigned long V_78 ;
int V_132 ;
V_33 = F_4 ( V_11 ) ;
F_26 ( & V_33 -> V_13 -> V_30 , V_78 ) ;
V_132 = F_86 ( V_11 , V_142 , V_28 ) ;
if ( ! V_132 && V_33 -> V_45 != V_154 &&
! F_12 ( & V_33 -> V_148 ) )
F_47 ( & V_33 -> V_153 , V_103 ) ;
F_27 ( & V_33 -> V_13 -> V_30 , V_78 ) ;
return V_132 ;
}
static int
F_87 ( struct V_17 * V_13 , struct V_142 * V_142 , struct V_1 * V_4 , int V_155 ,
int * V_28 )
{
struct V_5 * V_8 ;
V_156:
F_18 (req, &ep->queue, queue) {
unsigned V_157 , V_158 , V_159 ;
int V_160 , V_161 ;
int V_162 = 0 ;
V_157 = V_142 -> V_145 - V_142 -> V_163 ;
V_158 = V_8 -> V_8 . V_85 - V_8 -> V_8 . V_81 ;
V_159 = F_88 ( V_157 , V_158 ) ;
V_161 = F_89 ( V_142 -> V_150 ) ;
if ( F_81 ( V_159 == 0 ) )
V_160 = 1 ;
else {
char * V_164 , * V_165 ;
if ( V_155 < V_4 -> V_4 . V_75 && V_155 < V_159 )
break;
V_159 = F_88 ( V_159 , ( unsigned ) V_155 ) ;
if ( V_159 == 0 )
break;
if ( V_159 > V_4 -> V_4 . V_75 ) {
V_162 = 1 ;
V_159 -= ( V_159 % V_4 -> V_4 . V_75 ) ;
}
V_160 = ( V_159 % V_4 -> V_4 . V_75 ) != 0 ;
V_164 = V_142 -> V_144 + V_142 -> V_163 ;
V_165 = V_8 -> V_8 . V_87 + V_8 -> V_8 . V_81 ;
if ( V_161 )
memcpy ( V_164 , V_165 , V_159 ) ;
else
memcpy ( V_165 , V_164 , V_159 ) ;
V_4 -> V_126 = V_103 ;
V_155 -= V_159 ;
V_142 -> V_163 += V_159 ;
V_8 -> V_8 . V_81 += V_159 ;
}
if ( V_160 ) {
if ( V_157 == V_158 ) {
V_8 -> V_8 . V_28 = 0 ;
* V_28 = 0 ;
} else if ( V_161 ) {
V_8 -> V_8 . V_28 = 0 ;
if ( V_158 > V_157 )
* V_28 = - V_166 ;
else
* V_28 = 0 ;
} else if ( ! V_161 ) {
* V_28 = 0 ;
if ( V_157 > V_158 )
V_8 -> V_8 . V_28 = - V_166 ;
else
V_8 -> V_8 . V_28 = 0 ;
}
} else {
if ( V_8 -> V_8 . V_85 == V_8 -> V_8 . V_81
&& ! V_8 -> V_8 . V_167 )
V_8 -> V_8 . V_28 = 0 ;
if ( V_142 -> V_145 == V_142 -> V_163
&& ! ( V_142 -> V_168
& V_169 ) )
* V_28 = 0 ;
}
if ( V_8 -> V_8 . V_28 != - V_80 ) {
F_14 ( & V_8 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_8 -> V_8 . V_31 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_16 ( & V_13 -> V_30 ) ;
V_162 = 1 ;
}
if ( * V_28 != - V_80 )
break;
if ( V_162 )
goto V_156;
}
return V_155 ;
}
static int F_90 ( struct V_17 * V_13 , struct V_1 * V_4 )
{
int V_155 = V_4 -> V_4 . V_75 ;
if ( V_13 -> V_18 . V_22 == V_71 ) {
int V_170 ;
V_170 = F_23 ( V_4 -> V_60 ) ;
V_170 = ( V_170 >> 11 ) & 0x03 ;
V_170 *= 8 ;
V_155 += V_155 * V_170 ;
}
if ( V_13 -> V_18 . V_22 == V_23 ) {
switch ( V_4 -> V_60 -> V_68 & 0x03 ) {
case V_74 :
V_155 = 3 * 16 * 1024 * 8 ;
break;
case V_73 :
V_155 = 3 * 1024 * 8 ;
break;
case V_69 :
default:
break;
}
}
return V_155 ;
}
static struct V_1 * F_91 ( struct V_17 * V_13 , V_112 V_32 )
{
int V_106 ;
if ( ! F_92 ( ( V_13 -> V_18 . V_22 == V_23 ?
V_13 -> V_24 : V_13 -> V_25 ) ) )
return NULL ;
if ( ( V_32 & ~ V_83 ) == 0 )
return & V_13 -> V_4 [ 0 ] ;
for ( V_106 = 1 ; V_106 < V_107 ; V_106 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_106 ] ;
if ( ! V_4 -> V_60 )
continue;
if ( V_4 -> V_60 -> V_82 == V_32 )
return V_4 ;
}
return NULL ;
}
static int F_93 ( struct V_9 * V_33 , struct V_142 * V_142 ,
struct V_171 * V_172 ,
int * V_28 )
{
struct V_1 * V_173 ;
struct V_17 * V_13 = V_33 -> V_13 ;
int V_174 = 1 ;
unsigned V_175 ;
unsigned V_176 ;
V_175 = F_94 ( V_172 -> V_177 ) ;
V_176 = F_94 ( V_172 -> V_178 ) ;
switch ( V_172 -> V_179 ) {
case V_180 :
if ( V_172 -> V_181 != V_182 )
break;
V_13 -> V_32 = V_176 ;
* V_28 = 0 ;
F_24 ( F_7 ( V_13 ) , L_22 ,
V_176 ) ;
V_174 = 0 ;
break;
case V_183 :
if ( V_172 -> V_181 == V_182 ) {
V_174 = 0 ;
switch ( V_176 ) {
case V_99 :
break;
case V_98 :
V_13 -> V_18 . V_184 = 1 ;
break;
case V_185 :
V_13 -> V_18 . V_186 = 1 ;
break;
case V_187 :
V_13 -> V_18 . V_188 = 1 ;
break;
case V_189 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_176 = V_190 ;
else
V_174 = - V_191 ;
break;
case V_192 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_176 = V_193 ;
else
V_174 = - V_191 ;
break;
case V_194 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_176 = V_195 ;
else
V_174 = - V_191 ;
break;
default:
V_174 = - V_191 ;
}
if ( V_174 == 0 ) {
V_13 -> V_97 |= ( 1 << V_176 ) ;
* V_28 = 0 ;
}
} else if ( V_172 -> V_181 == V_196 ) {
V_173 = F_91 ( V_13 , V_175 ) ;
if ( ! V_173 || V_173 -> V_4 . V_63 == V_64 ) {
V_174 = - V_191 ;
break;
}
V_173 -> V_76 = 1 ;
V_174 = 0 ;
* V_28 = 0 ;
}
break;
case V_197 :
if ( V_172 -> V_181 == V_182 ) {
V_174 = 0 ;
switch ( V_176 ) {
case V_99 :
V_176 = V_99 ;
break;
case V_189 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_176 = V_190 ;
else
V_174 = - V_191 ;
break;
case V_192 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_176 = V_193 ;
else
V_174 = - V_191 ;
break;
case V_194 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_176 = V_195 ;
else
V_174 = - V_191 ;
break;
default:
V_174 = - V_191 ;
break;
}
if ( V_174 == 0 ) {
V_13 -> V_97 &= ~ ( 1 << V_176 ) ;
* V_28 = 0 ;
}
} else if ( V_172 -> V_181 == V_196 ) {
V_173 = F_91 ( V_13 , V_175 ) ;
if ( ! V_173 ) {
V_174 = - V_191 ;
break;
}
if ( ! V_173 -> V_77 )
V_173 -> V_76 = 0 ;
V_174 = 0 ;
* V_28 = 0 ;
}
break;
case V_198 :
if ( V_172 -> V_181 == V_199
|| V_172 -> V_181 == V_200
|| V_172 -> V_181 == V_201 ) {
char * V_87 ;
V_87 = ( char * ) V_142 -> V_144 ;
if ( V_142 -> V_145 > 0 ) {
if ( V_172 -> V_181 == V_201 ) {
V_173 = F_91 ( V_13 , V_175 ) ;
if ( ! V_173 ) {
V_174 = - V_191 ;
break;
}
V_87 [ 0 ] = V_173 -> V_76 ;
} else if ( V_172 -> V_181 ==
V_199 ) {
V_87 [ 0 ] = ( V_112 ) V_13 -> V_97 ;
} else
V_87 [ 0 ] = 0 ;
}
if ( V_142 -> V_145 > 1 )
V_87 [ 1 ] = 0 ;
V_142 -> V_163 = F_51 ( T_2 , 2 ,
V_142 -> V_145 ) ;
V_174 = 0 ;
* V_28 = 0 ;
}
break;
}
return V_174 ;
}
static void F_95 ( unsigned long V_202 )
{
struct V_9 * V_33 = (struct V_9 * ) V_202 ;
struct V_17 * V_13 = V_33 -> V_13 ;
struct V_143 * V_143 , * V_170 ;
unsigned long V_78 ;
int V_155 , V_203 ;
int V_106 ;
switch ( V_13 -> V_18 . V_22 ) {
case V_204 :
V_203 = 8 * 12 ;
break;
case V_72 :
V_203 = 64 * 19 ;
break;
case V_71 :
V_203 = 512 * 13 * 8 ;
break;
case V_23 :
V_203 = 490000 ;
break;
default:
F_82 ( F_6 ( V_33 ) , L_23 ) ;
return;
}
F_26 ( & V_13 -> V_30 , V_78 ) ;
if ( ! V_33 -> V_147 ) {
F_82 ( F_6 ( V_33 ) ,
L_24 ) ;
F_27 ( & V_13 -> V_30 , V_78 ) ;
return;
}
for ( V_106 = 0 ; V_106 < V_107 ; V_106 ++ ) {
if ( ! V_121 [ V_106 ] )
break;
V_13 -> V_4 [ V_106 ] . V_124 = 0 ;
}
V_205:
F_96 (urbp, tmp, &dum_hcd->urbp_list, urbp_list) {
struct V_142 * V_142 ;
struct V_5 * V_8 ;
V_112 V_32 ;
struct V_1 * V_4 = NULL ;
int type ;
int V_28 = - V_80 ;
V_142 = V_143 -> V_142 ;
if ( V_142 -> V_206 )
goto V_207;
else if ( V_33 -> V_45 != V_154 )
continue;
type = F_83 ( V_142 -> V_150 ) ;
if ( V_203 <= 0 && type == V_208 )
continue;
V_32 = F_97 ( V_142 -> V_150 ) ;
if ( F_89 ( V_142 -> V_150 ) )
V_32 |= V_83 ;
V_4 = F_91 ( V_13 , V_32 ) ;
if ( ! V_4 ) {
F_24 ( F_6 ( V_33 ) ,
L_25 ,
V_142 ) ;
V_28 = - V_209 ;
goto V_207;
}
if ( V_4 -> V_124 )
continue;
V_4 -> V_124 = 1 ;
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_142 -> V_152 ) {
V_4 -> V_125 = 1 ;
V_142 -> V_152 = 0 ;
}
if ( V_4 -> V_76 && ! V_4 -> V_125 ) {
F_24 ( F_6 ( V_33 ) , L_26 ,
V_4 -> V_4 . V_63 , V_142 ) ;
V_28 = - V_210 ;
goto V_207;
}
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_4 -> V_125 ) {
struct V_171 V_172 ;
int V_91 = 1 ;
V_172 = * (struct V_171 * ) V_142 -> V_211 ;
F_18 (req, &ep->queue, queue) {
F_14 ( & V_8 -> V_26 ) ;
V_8 -> V_8 . V_28 = - V_166 ;
F_24 ( F_7 ( V_13 ) , L_27 ,
V_8 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_8 -> V_8 . V_31 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_16 ( & V_13 -> V_30 ) ;
V_4 -> V_124 = 0 ;
goto V_205;
}
V_4 -> V_126 = V_103 ;
V_4 -> V_125 = 0 ;
V_4 -> V_76 = 0 ;
V_91 = F_93 ( V_33 , V_142 , & V_172 ,
& V_28 ) ;
if ( V_91 > 0 ) {
F_15 ( & V_13 -> V_30 ) ;
V_91 = V_13 -> V_54 -> V_172 ( & V_13 -> V_18 ,
& V_172 ) ;
F_16 ( & V_13 -> V_30 ) ;
if ( V_91 >= 0 ) {
V_155 = 64 * 1024 ;
goto V_212;
}
}
if ( V_91 < 0 ) {
if ( V_91 != - V_191 )
F_24 ( F_7 ( V_13 ) ,
L_28 ,
V_91 ) ;
V_28 = - V_210 ;
V_142 -> V_163 = 0 ;
}
goto V_207;
}
V_155 = V_203 ;
switch ( F_83 ( V_142 -> V_150 ) ) {
case V_213 :
V_155 = V_61 ( V_155 , F_90 ( V_13 , V_4 ) ) ;
V_28 = - V_214 ;
break;
case V_215 :
V_155 = V_61 ( V_155 , F_90 ( V_13 , V_4 ) ) ;
default:
V_212:
V_4 -> V_126 = V_103 ;
V_203 = F_87 ( V_13 , V_142 , V_4 , V_155 , & V_28 ) ;
break;
}
if ( V_28 == - V_80 )
continue;
V_207:
F_98 ( & V_143 -> V_148 ) ;
F_33 ( V_143 ) ;
if ( V_4 )
V_4 -> V_124 = V_4 -> V_125 = 0 ;
F_99 ( F_5 ( V_33 ) , V_142 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_100 ( F_5 ( V_33 ) , V_142 , V_28 ) ;
F_16 ( & V_13 -> V_30 ) ;
goto V_205;
}
if ( F_12 ( & V_33 -> V_148 ) ) {
F_101 ( V_33 -> V_147 ) ;
V_33 -> V_147 = NULL ;
} else if ( V_33 -> V_45 == V_154 ) {
F_47 ( & V_33 -> V_153 , V_103 + F_46 ( 1 ) ) ;
}
F_27 ( & V_13 -> V_30 , V_78 ) ;
}
static int F_102 ( struct V_10 * V_11 , char * V_87 )
{
struct V_9 * V_33 ;
unsigned long V_78 ;
int V_62 = 0 ;
V_33 = F_4 ( V_11 ) ;
F_26 ( & V_33 -> V_13 -> V_30 , V_78 ) ;
if ( ! F_103 ( V_11 ) )
goto V_70;
if ( V_33 -> V_52 && F_104 ( V_103 , V_33 -> V_102 ) ) {
V_33 -> V_35 |= ( V_216 << 16 ) ;
V_33 -> V_35 &= ~ V_51 ;
F_20 ( V_33 ) ;
}
if ( ( V_33 -> V_35 & V_217 ) != 0 ) {
* V_87 = ( 1 << 1 ) ;
F_24 ( F_6 ( V_33 ) , L_29 ,
V_33 -> V_35 ) ;
V_62 = 1 ;
if ( V_33 -> V_45 == V_46 )
F_105 ( V_11 ) ;
}
V_70:
F_27 ( & V_33 -> V_13 -> V_30 , V_78 ) ;
return V_62 ;
}
static inline void
F_106 ( struct V_218 * V_60 )
{
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_65 = 0x2a ;
V_60 -> V_219 = 12 ;
V_60 -> V_220 = F_107 ( 0x0001 ) ;
V_60 -> V_221 = 1 ;
V_60 -> V_222 . V_223 . V_224 = 0x04 ;
V_60 -> V_222 . V_223 . V_225 = 0xffff ;
}
static inline void
F_108 ( struct V_218 * V_60 )
{
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_65 = 0x29 ;
V_60 -> V_219 = 9 ;
V_60 -> V_220 = F_107 ( 0x0001 ) ;
V_60 -> V_221 = 1 ;
V_60 -> V_222 . V_226 . V_225 [ 0 ] = 0xff ;
V_60 -> V_222 . V_226 . V_225 [ 1 ] = 0xff ;
}
static int F_109 (
struct V_10 * V_11 ,
T_5 V_227 ,
T_5 V_178 ,
T_5 V_177 ,
char * V_87 ,
T_5 V_228
) {
struct V_9 * V_33 ;
int V_62 = 0 ;
unsigned long V_78 ;
if ( ! F_103 ( V_11 ) )
return - V_229 ;
V_33 = F_4 ( V_11 ) ;
F_26 ( & V_33 -> V_13 -> V_30 , V_78 ) ;
switch ( V_227 ) {
case V_230 :
break;
case V_231 :
switch ( V_178 ) {
case V_232 :
if ( V_11 -> V_22 == V_34 ) {
F_24 ( F_6 ( V_33 ) ,
L_30
L_31 ) ;
goto error;
}
if ( V_33 -> V_35 & V_51 ) {
V_33 -> V_52 = 1 ;
V_33 -> V_102 = V_103 +
F_46 ( 20 ) ;
}
break;
case V_233 :
if ( V_11 -> V_22 == V_34 ) {
if ( V_33 -> V_35 & V_48 )
F_24 ( F_6 ( V_33 ) ,
L_32 ) ;
} else
if ( V_33 -> V_35 &
V_36 )
F_24 ( F_6 ( V_33 ) ,
L_32 ) ;
default:
V_33 -> V_35 &= ~ ( 1 << V_178 ) ;
F_20 ( V_33 ) ;
}
break;
case V_234 :
if ( V_11 -> V_22 == V_34 &&
( V_228 < V_235 ||
V_178 != ( V_236 << 8 ) ) ) {
F_24 ( F_6 ( V_33 ) ,
L_33
L_34 ) ;
goto error;
}
if ( V_11 -> V_22 == V_34 )
F_106 ( (struct V_218 * ) V_87 ) ;
else
F_108 ( (struct V_218 * ) V_87 ) ;
break;
case V_237 :
* ( V_238 * ) V_87 = F_110 ( 0 ) ;
break;
case V_239 :
if ( V_177 != 1 )
V_62 = - V_210 ;
if ( V_33 -> V_52 &&
F_104 ( V_103 , V_33 -> V_102 ) ) {
V_33 -> V_35 |= ( V_216 << 16 ) ;
V_33 -> V_35 &= ~ V_51 ;
}
if ( ( V_33 -> V_35 & V_53 ) != 0 &&
F_104 ( V_103 , V_33 -> V_102 ) ) {
V_33 -> V_35 |= ( V_240 << 16 ) ;
V_33 -> V_35 &= ~ V_53 ;
if ( V_33 -> V_13 -> V_37 ) {
V_33 -> V_35 |= V_40 ;
if ( V_11 -> V_22 < V_34 ) {
switch ( V_33 -> V_13 -> V_18 . V_22 ) {
case V_71 :
V_33 -> V_35 |=
V_50 ;
break;
case V_204 :
V_33 -> V_13 -> V_18 . V_127 ->
V_75 = 8 ;
V_33 -> V_35 |=
V_49 ;
break;
default:
V_33 -> V_13 -> V_18 . V_22 =
V_72 ;
break;
}
}
}
}
F_20 ( V_33 ) ;
( ( V_241 * ) V_87 ) [ 0 ] = F_107 ( V_33 -> V_35 ) ;
( ( V_241 * ) V_87 ) [ 1 ] = F_107 ( V_33 -> V_35 >> 16 ) ;
break;
case V_242 :
V_62 = - V_210 ;
break;
case V_243 :
switch ( V_178 ) {
case V_244 :
if ( V_11 -> V_22 != V_34 ) {
F_24 ( F_6 ( V_33 ) ,
L_35
L_36 ) ;
goto error;
}
break;
case V_245 :
case V_246 :
if ( V_11 -> V_22 != V_34 ) {
F_24 ( F_6 ( V_33 ) ,
L_37
L_36 ) ;
goto error;
}
break;
case V_232 :
if ( V_11 -> V_22 == V_34 ) {
F_24 ( F_6 ( V_33 ) ,
L_30
L_31 ) ;
goto error;
}
if ( V_33 -> V_47 ) {
V_33 -> V_35 |= V_51 ;
F_20 ( V_33 ) ;
if ( ( ( 1 << V_98 )
& V_33 -> V_13 -> V_97 ) != 0 )
F_24 ( F_6 ( V_33 ) ,
L_38 ) ;
}
break;
case V_233 :
if ( V_11 -> V_22 == V_34 )
V_33 -> V_35 |= V_36 ;
else
V_33 -> V_35 |= V_48 ;
F_20 ( V_33 ) ;
break;
case V_247 :
if ( V_11 -> V_22 != V_34 ) {
F_24 ( F_6 ( V_33 ) ,
L_39
L_36 ) ;
goto error;
}
case V_248 :
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
V_33 -> V_13 -> V_97 &=
( 1 << V_105 ) ;
V_33 -> V_102 = V_103 + F_46 ( 50 ) ;
default:
if ( V_11 -> V_22 == V_34 ) {
if ( ( V_33 -> V_35 &
V_36 ) != 0 ) {
V_33 -> V_35 |= ( 1 << V_178 ) ;
F_20 ( V_33 ) ;
}
} else
if ( ( V_33 -> V_35 &
V_48 ) != 0 ) {
V_33 -> V_35 |= ( 1 << V_178 ) ;
F_20 ( V_33 ) ;
}
}
break;
case V_249 :
if ( V_11 -> V_22 != V_34 ) {
F_24 ( F_6 ( V_33 ) ,
L_40
L_36 ) ;
goto error;
}
* ( V_238 * ) V_87 = F_110 ( 0 ) ;
break;
case V_250 :
if ( V_11 -> V_22 != V_34 ) {
F_24 ( F_6 ( V_33 ) ,
L_41
L_42 ) ;
goto error;
}
break;
default:
F_24 ( F_6 ( V_33 ) ,
L_43 ,
V_227 , V_178 , V_177 , V_228 ) ;
error:
V_62 = - V_210 ;
}
F_27 ( & V_33 -> V_13 -> V_30 , V_78 ) ;
if ( ( V_33 -> V_35 & V_217 ) != 0 )
F_52 ( V_11 ) ;
return V_62 ;
}
static int F_111 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
F_24 ( & V_11 -> V_15 . V_251 -> V_19 , L_17 , V_141 ) ;
F_73 ( & V_33 -> V_13 -> V_30 ) ;
V_33 -> V_45 = V_46 ;
F_20 ( V_33 ) ;
V_11 -> V_140 = V_252 ;
F_74 ( & V_33 -> V_13 -> V_30 ) ;
return 0 ;
}
static int F_112 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
int V_132 = 0 ;
F_24 ( & V_11 -> V_15 . V_251 -> V_19 , L_17 , V_141 ) ;
F_73 ( & V_33 -> V_13 -> V_30 ) ;
if ( ! F_103 ( V_11 ) ) {
V_132 = - V_29 ;
} else {
V_33 -> V_45 = V_154 ;
F_20 ( V_33 ) ;
if ( ! F_12 ( & V_33 -> V_148 ) )
F_47 ( & V_33 -> V_153 , V_103 ) ;
V_11 -> V_140 = V_253 ;
}
F_74 ( & V_33 -> V_13 -> V_30 ) ;
return V_132 ;
}
static inline T_3
F_113 ( char * V_87 , T_6 V_254 , struct V_142 * V_142 )
{
int V_4 = F_97 ( V_142 -> V_150 ) ;
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
}; s; }),
ep, ep ? (usb_pipein (urb->pipe) ? L_5 : L_6) : L_50 ,
({ char *s; \
switch (usb_pipetype (urb->pipe)) { \
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
}; s;}),
urb->actual_length, urb->transfer_buffer_length) ;
}
static T_3
F_114 ( struct V_14 * V_19 , struct V_113 * V_114 , char * V_87 )
{
struct V_10 * V_11 = F_115 ( V_19 ) ;
struct V_9 * V_33 = F_4 ( V_11 ) ;
struct V_143 * V_143 ;
T_6 V_254 = 0 ;
unsigned long V_78 ;
F_26 ( & V_33 -> V_13 -> V_30 , V_78 ) ;
F_18 (urbp, &dum_hcd->urbp_list, urbp_list) {
T_6 V_255 ;
V_255 = F_113 ( V_87 , V_116 - V_254 , V_143 -> V_142 ) ;
V_87 += V_255 ;
V_254 += V_255 ;
}
F_27 ( & V_33 -> V_13 -> V_30 , V_78 ) ;
return V_254 ;
}
static int F_116 ( struct V_9 * V_33 )
{
F_117 ( & V_33 -> V_153 ) ;
V_33 -> V_153 . V_115 = F_95 ;
V_33 -> V_153 . V_256 = ( unsigned long ) V_33 ;
V_33 -> V_45 = V_154 ;
F_30 ( & V_33 -> V_148 ) ;
F_5 ( V_33 ) -> V_257 = V_258 ;
F_5 ( V_33 ) -> V_140 = V_253 ;
F_5 ( V_33 ) -> V_259 = 1 ;
#ifdef F_59
F_5 ( V_33 ) -> V_15 . V_260 = 1 ;
#endif
return 0 ;
return F_65 ( F_6 ( V_33 ) , & V_261 ) ;
}
static int F_118 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
if ( ! F_119 ( V_11 ) )
return F_116 ( V_33 ) ;
F_120 ( & V_33 -> V_13 -> V_30 ) ;
F_117 ( & V_33 -> V_153 ) ;
V_33 -> V_153 . V_115 = F_95 ;
V_33 -> V_153 . V_256 = ( unsigned long ) V_33 ;
V_33 -> V_45 = V_154 ;
F_30 ( & V_33 -> V_148 ) ;
V_11 -> V_257 = V_258 ;
V_11 -> V_140 = V_253 ;
V_11 -> V_259 = 1 ;
#ifdef F_59
V_11 -> V_15 . V_260 = 1 ;
#endif
return F_65 ( F_6 ( V_33 ) , & V_261 ) ;
}
static void F_121 ( struct V_10 * V_11 )
{
struct V_17 * V_13 ;
V_13 = ( F_4 ( V_11 ) ) -> V_13 ;
F_71 ( F_6 ( F_4 ( V_11 ) ) , & V_261 ) ;
F_122 ( V_13 -> V_54 ) ;
F_123 ( F_6 ( F_4 ( V_11 ) ) , L_51 ) ;
}
static int F_124 ( struct V_10 * V_11 )
{
return F_43 ( NULL ) ;
}
static int F_125 ( struct V_10 * V_11 )
{
if ( F_119 ( V_11 ) ) {
V_131 . V_25 = F_4 ( V_11 ) ;
V_131 . V_25 -> V_13 = & V_131 ;
V_11 -> V_22 = V_262 ;
V_11 -> V_15 . V_251 -> V_22 = V_71 ;
} else {
V_131 . V_24 = F_4 ( V_11 ) ;
V_131 . V_24 -> V_13 = & V_131 ;
V_11 -> V_22 = V_34 ;
V_11 -> V_15 . V_251 -> V_22 = V_23 ;
}
return 0 ;
}
int F_126 ( struct V_10 * V_11 , struct V_263 * V_147 ,
struct V_264 * * V_265 , unsigned int V_266 ,
unsigned int V_267 , T_1 V_79 )
{
if ( V_11 -> V_22 != V_34 )
F_24 ( F_6 ( F_4 ( V_11 ) ) ,
L_52 ,
V_141 ) ;
return 0 ;
}
int F_127 ( struct V_10 * V_11 , struct V_263 * V_147 ,
struct V_264 * * V_265 , unsigned int V_266 ,
T_1 V_79 )
{
if ( V_11 -> V_22 != V_34 )
F_24 ( F_6 ( F_4 ( V_11 ) ) ,
L_52 ,
V_141 ) ;
return 0 ;
}
static int F_128 ( struct V_129 * V_130 )
{
struct V_10 * V_25 ;
struct V_10 * V_24 ;
int V_62 ;
F_123 ( & V_130 -> V_19 , L_53 V_268 L_54 , V_269 ) ;
if ( ! V_109 . V_110 )
V_9 . V_78 = V_262 ;
V_25 = F_129 ( & V_9 , & V_130 -> V_19 , F_130 ( & V_130 -> V_19 ) ) ;
if ( ! V_25 )
return - V_146 ;
V_25 -> V_270 = 1 ;
V_62 = F_131 ( V_25 , 0 , 0 ) ;
if ( V_62 != 0 ) {
F_132 ( V_25 ) ;
return V_62 ;
}
if ( V_109 . V_110 ) {
V_24 = F_133 ( & V_9 , & V_130 -> V_19 ,
F_130 ( & V_130 -> V_19 ) , V_25 ) ;
if ( ! V_24 ) {
V_62 = - V_146 ;
goto V_271;
}
V_62 = F_131 ( V_24 , 0 , 0 ) ;
if ( V_62 )
goto V_272;
}
return 0 ;
V_272:
F_132 ( V_24 ) ;
V_271:
F_132 ( V_25 ) ;
V_131 . V_25 = V_131 . V_24 = NULL ;
return V_62 ;
}
static int F_134 ( struct V_129 * V_130 )
{
struct V_17 * V_13 ;
V_13 = ( F_4 ( F_70 ( V_130 ) ) ) -> V_13 ;
if ( V_13 -> V_24 ) {
F_135 ( F_5 ( V_13 -> V_24 ) ) ;
F_132 ( F_5 ( V_13 -> V_24 ) ) ;
}
F_135 ( F_5 ( V_13 -> V_25 ) ) ;
F_132 ( F_5 ( V_13 -> V_25 ) ) ;
V_131 . V_25 = NULL ;
V_131 . V_24 = NULL ;
return 0 ;
}
static int F_136 ( struct V_129 * V_130 , T_4 V_140 )
{
struct V_10 * V_11 ;
struct V_9 * V_33 ;
int V_132 = 0 ;
F_24 ( & V_130 -> V_19 , L_17 , V_141 ) ;
V_11 = F_70 ( V_130 ) ;
V_33 = F_4 ( V_11 ) ;
if ( V_33 -> V_45 == V_154 ) {
F_137 ( & V_130 -> V_19 , L_55 ) ;
V_132 = - V_273 ;
} else
F_138 ( V_274 , & V_11 -> V_78 ) ;
return V_132 ;
}
static int F_139 ( struct V_129 * V_130 )
{
struct V_10 * V_11 ;
F_24 ( & V_130 -> V_19 , L_17 , V_141 ) ;
V_11 = F_70 ( V_130 ) ;
F_140 ( V_274 , & V_11 -> V_78 ) ;
F_52 ( V_11 ) ;
return 0 ;
}
static int T_7 F_141 ( void )
{
int V_62 = - V_146 ;
if ( F_142 () )
return - V_275 ;
if ( ! V_109 . V_111 && V_109 . V_110 )
return - V_67 ;
V_276 = F_143 ( V_277 , - 1 ) ;
if ( ! V_276 )
return V_62 ;
V_278 = F_143 ( V_133 , - 1 ) ;
if ( ! V_278 )
goto V_279;
V_62 = F_144 ( & V_280 ) ;
if ( V_62 < 0 )
goto V_281;
V_62 = F_144 ( & V_282 ) ;
if ( V_62 < 0 )
goto V_283;
V_62 = F_145 ( V_276 ) ;
if ( V_62 < 0 )
goto V_284;
if ( ! V_131 . V_25 ||
( ! V_131 . V_24 && V_109 . V_110 ) ) {
V_62 = - V_67 ;
goto V_285;
}
V_62 = F_145 ( V_278 ) ;
if ( V_62 < 0 )
goto V_285;
if ( ! F_70 ( V_278 ) ) {
V_62 = - V_67 ;
goto V_286;
}
return V_62 ;
V_286:
F_146 ( V_278 ) ;
V_285:
F_146 ( V_276 ) ;
V_284:
F_147 ( & V_282 ) ;
V_283:
F_147 ( & V_280 ) ;
V_281:
F_148 ( V_278 ) ;
V_279:
F_148 ( V_276 ) ;
return V_62 ;
}
static void T_8 F_149 ( void )
{
F_150 ( V_278 ) ;
F_150 ( V_276 ) ;
F_147 ( & V_282 ) ;
F_147 ( & V_280 ) ;
}
