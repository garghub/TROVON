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
V_61 = F_23 ( V_60 -> V_68 ) & 0x7ff ;
V_62 = - V_67 ;
switch ( V_60 -> V_69 & 0x03 ) {
case V_70 :
if ( strstr ( V_4 -> V_4 . V_63 , L_1 )
|| strstr ( V_4 -> V_4 . V_63 , L_2 ) ) {
goto V_71;
}
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
if ( V_61 == 1024 )
break;
goto V_71;
case V_72 :
if ( V_61 == 512 )
break;
goto V_71;
case V_73 :
if ( V_61 == 8 || V_61 == 16 || V_61 == 32 || V_61 == 64 )
break;
default:
goto V_71;
}
break;
case V_74 :
if ( strstr ( V_4 -> V_4 . V_63 , L_1 ) )
goto V_71;
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
case V_72 :
if ( V_61 <= 1024 )
break;
case V_73 :
if ( V_61 <= 64 )
break;
default:
if ( V_61 <= 8 )
break;
goto V_71;
}
break;
case V_75 :
if ( strstr ( V_4 -> V_4 . V_63 , L_3 )
|| strstr ( V_4 -> V_4 . V_63 , L_2 ) )
goto V_71;
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
case V_72 :
if ( V_61 <= 1024 )
break;
case V_73 :
if ( V_61 <= 1023 )
break;
default:
goto V_71;
}
break;
default:
goto V_71;
}
V_3 -> V_76 = V_61 ;
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
V_4 -> V_77 = V_4 -> V_78 = 0 ;
V_62 = 0 ;
V_71:
return V_62 ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
unsigned long V_79 ;
int V_62 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_4 -> V_60 || V_3 -> V_63 == V_64 )
return - V_67 ;
V_13 = F_8 ( V_4 ) ;
F_26 ( & V_13 -> V_30 , V_79 ) ;
V_4 -> V_60 = NULL ;
V_62 = 0 ;
F_11 ( V_13 , V_4 ) ;
F_27 ( & V_13 -> V_30 , V_79 ) ;
F_24 ( F_7 ( V_13 ) , L_11 , V_3 -> V_63 ) ;
return V_62 ;
}
static struct V_6 *
F_28 ( struct V_2 * V_3 , T_1 V_80 )
{
struct V_1 * V_4 ;
struct V_5 * V_8 ;
if ( ! V_3 )
return NULL ;
V_4 = F_1 ( V_3 ) ;
V_8 = F_29 ( sizeof( * V_8 ) , V_80 ) ;
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
dev_dbg (udc_dev(dum), "ep %p queue req %p to %s, len %d buf %p\n",
ep, _req, _ep->name, _req->length, _req->buf);
#endif
V_7 -> V_28 = - V_81 ;
V_7 -> V_82 = 0 ;
F_26 ( & V_13 -> V_30 , V_79 ) ;
if ( V_4 -> V_60 && ( V_4 -> V_60 -> V_83 & V_84 ) &&
F_12 ( & V_13 -> V_85 . V_26 ) &&
F_12 ( & V_4 -> V_26 ) &&
V_7 -> V_86 <= V_87 ) {
V_8 = & V_13 -> V_85 ;
V_8 -> V_8 = * V_7 ;
V_8 -> V_8 . V_88 = V_13 -> V_89 ;
memcpy ( V_13 -> V_89 , V_7 -> V_88 , V_7 -> V_86 ) ;
V_8 -> V_8 . V_90 = V_13 ;
V_8 -> V_8 . V_31 = F_34 ;
F_36 ( & V_8 -> V_26 , & V_4 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_7 -> V_82 = V_7 -> V_86 ;
V_7 -> V_28 = 0 ;
V_7 -> V_31 ( V_3 , V_7 ) ;
F_16 ( & V_13 -> V_30 ) ;
} else
F_36 ( & V_8 -> V_26 , & V_4 -> V_26 ) ;
F_27 ( & V_13 -> V_30 , V_79 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_6 * V_7 )
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
F_38 ( V_79 ) ;
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
F_24 ( F_7 ( V_13 ) ,
L_12 ,
V_8 , V_3 -> V_63 , V_7 -> V_86 , V_7 -> V_88 ) ;
V_7 -> V_31 ( V_3 , V_7 ) ;
}
F_39 ( V_79 ) ;
return V_62 ;
}
static int
F_40 ( struct V_2 * V_3 , int V_92 , int V_78 )
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
F_41 ( struct V_2 * V_3 , int V_92 )
{
return F_40 ( V_3 , V_92 , 0 ) ;
}
static int F_42 ( struct V_2 * V_3 )
{
if ( ! V_3 || V_3 -> V_63 == V_64 )
return - V_67 ;
return F_40 ( V_3 , 1 , 1 ) ;
}
static int F_43 ( struct V_21 * V_94 )
{
struct V_95 V_96 ;
F_44 ( & V_96 ) ;
return V_96 . V_97 / 1000 ;
}
static int F_45 ( struct V_21 * V_94 )
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
V_33 -> V_103 = V_104 + F_46 ( 20 ) ;
F_47 ( & F_5 ( V_33 ) -> V_105 , V_33 -> V_103 ) ;
return 0 ;
}
static int F_48 ( struct V_21 * V_94 , int V_92 )
{
struct V_17 * V_13 ;
V_13 = ( F_9 ( V_94 ) ) -> V_13 ;
if ( V_92 )
V_13 -> V_98 |= ( 1 << V_106 ) ;
else
V_13 -> V_98 &= ~ ( 1 << V_106 ) ;
return 0 ;
}
static void F_49 ( struct V_17 * V_13 )
{
T_2 V_107 ;
if ( V_13 -> V_18 . V_22 == V_23 ) {
for ( V_107 = 0 ; V_107 < V_108 ; V_107 ++ )
V_13 -> V_4 [ V_107 ] . V_4 . V_109 = 0x10 ;
V_13 -> V_4 [ 0 ] . V_4 . V_76 = 9 ;
} else {
for ( V_107 = 0 ; V_107 < V_108 ; V_107 ++ )
V_13 -> V_4 [ V_107 ] . V_4 . V_109 = 0 ;
V_13 -> V_4 [ 0 ] . V_4 . V_76 = 64 ;
}
}
static int F_50 ( struct V_21 * V_94 , int V_92 )
{
struct V_9 * V_33 ;
struct V_17 * V_13 ;
unsigned long V_79 ;
V_13 = F_10 ( & V_94 -> V_19 ) ;
if ( V_92 && V_13 -> V_54 ) {
if ( V_110 . V_111 )
V_13 -> V_18 . V_22 = V_13 -> V_54 -> V_22 ;
else if ( V_110 . V_112 )
V_13 -> V_18 . V_22 = F_51 ( V_113 , V_72 ,
V_13 -> V_54 -> V_22 ) ;
else
V_13 -> V_18 . V_22 = V_73 ;
F_49 ( V_13 ) ;
if ( V_13 -> V_18 . V_22 < V_13 -> V_54 -> V_22 )
F_24 ( F_7 ( V_13 ) , L_13
L_14 ,
( V_13 -> V_54 -> V_22 == V_23 ?
L_15 : L_16 ) ) ;
}
V_33 = F_9 ( V_94 ) ;
F_26 ( & V_13 -> V_30 , V_79 ) ;
V_13 -> V_37 = ( V_92 != 0 ) ;
F_20 ( V_33 ) ;
F_27 ( & V_13 -> V_30 , V_79 ) ;
F_52 ( F_5 ( V_33 ) ) ;
return 0 ;
}
static T_3
F_53 ( struct V_14 * V_19 , struct V_114 * V_115 , char * V_88 )
{
struct V_17 * V_13 = F_10 ( V_19 ) ;
if ( ! V_13 -> V_54 || ! V_13 -> V_54 -> V_116 )
return 0 ;
return F_54 ( V_88 , V_117 , L_17 , V_13 -> V_54 -> V_116 ) ;
}
static int F_55 ( struct V_21 * V_118 ,
struct V_119 * V_54 )
{
struct V_9 * V_33 = F_9 ( V_118 ) ;
struct V_17 * V_13 = V_33 -> V_13 ;
if ( V_54 -> V_22 == V_120 )
return - V_67 ;
V_13 -> V_98 = 0 ;
V_13 -> V_54 = V_54 ;
F_24 ( F_7 ( V_13 ) , L_18 ,
V_54 -> V_54 . V_63 ) ;
return 0 ;
}
static int F_56 ( struct V_21 * V_118 ,
struct V_119 * V_54 )
{
struct V_9 * V_33 = F_9 ( V_118 ) ;
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
int V_107 ;
F_30 ( & V_13 -> V_18 . V_121 ) ;
for ( V_107 = 0 ; V_107 < V_108 ; V_107 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_107 ] ;
if ( ! V_122 [ V_107 ] )
break;
V_4 -> V_4 . V_63 = V_122 [ V_107 ] ;
V_4 -> V_4 . V_123 = & V_124 ;
F_36 ( & V_4 -> V_4 . V_121 , & V_13 -> V_18 . V_121 ) ;
V_4 -> V_77 = V_4 -> V_78 = V_4 -> V_125 =
V_4 -> V_126 = 0 ;
V_4 -> V_4 . V_76 = ~ 0 ;
V_4 -> V_127 = V_104 ;
V_4 -> V_18 = & V_13 -> V_18 ;
V_4 -> V_60 = NULL ;
F_30 ( & V_4 -> V_26 ) ;
}
V_13 -> V_18 . V_128 = & V_13 -> V_4 [ 0 ] . V_4 ;
F_14 ( & V_13 -> V_4 [ 0 ] . V_4 . V_121 ) ;
F_30 ( & V_13 -> V_85 . V_26 ) ;
#ifdef F_59
V_13 -> V_18 . V_129 = 1 ;
#endif
}
static int F_60 ( struct V_130 * V_131 )
{
struct V_17 * V_13 = & V_132 ;
int V_133 ;
V_13 -> V_18 . V_63 = V_134 ;
V_13 -> V_18 . V_123 = & V_135 ;
V_13 -> V_18 . V_136 = 1 ;
F_61 ( & V_13 -> V_18 . V_19 , L_20 ) ;
V_13 -> V_18 . V_19 . V_20 = & V_131 -> V_19 ;
V_13 -> V_18 . V_19 . V_137 = F_57 ;
V_133 = F_62 ( & V_13 -> V_18 . V_19 ) ;
if ( V_133 < 0 ) {
F_63 ( & V_13 -> V_18 . V_19 ) ;
return V_133 ;
}
F_58 ( V_13 ) ;
V_133 = F_64 ( & V_131 -> V_19 , & V_13 -> V_18 ) ;
if ( V_133 < 0 )
goto V_138;
V_133 = F_65 ( & V_13 -> V_18 . V_19 , & V_139 ) ;
if ( V_133 < 0 )
goto V_140;
F_66 ( V_131 , V_13 ) ;
return V_133 ;
V_140:
F_67 ( & V_13 -> V_18 ) ;
V_138:
F_68 ( & V_13 -> V_18 . V_19 ) ;
return V_133 ;
}
static int F_69 ( struct V_130 * V_131 )
{
struct V_17 * V_13 = F_70 ( V_131 ) ;
F_67 ( & V_13 -> V_18 ) ;
F_66 ( V_131 , NULL ) ;
F_71 ( & V_13 -> V_18 . V_19 , & V_139 ) ;
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
static int F_75 ( struct V_130 * V_131 , T_4 V_141 )
{
struct V_17 * V_13 = F_70 ( V_131 ) ;
struct V_9 * V_33 = F_9 ( & V_13 -> V_18 ) ;
F_24 ( & V_131 -> V_19 , L_17 , V_142 ) ;
F_72 ( V_13 , V_33 , 1 ) ;
F_52 ( F_5 ( V_33 ) ) ;
return 0 ;
}
static int F_76 ( struct V_130 * V_131 )
{
struct V_17 * V_13 = F_70 ( V_131 ) ;
struct V_9 * V_33 = F_9 ( & V_13 -> V_18 ) ;
F_24 ( & V_131 -> V_19 , L_17 , V_142 ) ;
F_72 ( V_13 , V_33 , 0 ) ;
F_52 ( F_5 ( V_33 ) ) ;
return 0 ;
}
static int F_77 (
struct V_10 * V_11 ,
struct V_143 * V_143 ,
T_1 V_80
) {
struct V_9 * V_33 ;
struct V_144 * V_144 ;
unsigned long V_79 ;
int V_133 ;
if ( ! V_143 -> V_145 && V_143 -> V_146 )
return - V_67 ;
V_144 = F_78 ( sizeof *V_144 , V_80 ) ;
if ( ! V_144 )
return - V_147 ;
V_144 -> V_143 = V_143 ;
V_33 = F_4 ( V_11 ) ;
F_26 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
V_133 = F_79 ( V_11 , V_143 ) ;
if ( V_133 ) {
F_33 ( V_144 ) ;
goto V_71;
}
if ( ! V_33 -> V_148 ) {
V_33 -> V_148 = V_143 -> V_19 ;
F_80 ( V_33 -> V_148 ) ;
} else if ( F_81 ( V_33 -> V_148 != V_143 -> V_19 ) )
F_82 ( F_6 ( V_33 ) , L_21 ) ;
F_36 ( & V_144 -> V_149 , & V_33 -> V_149 ) ;
V_143 -> V_150 = V_144 ;
if ( F_83 ( V_143 -> V_151 ) == V_152 )
V_143 -> V_153 = 1 ;
if ( ! F_84 ( & V_33 -> V_154 ) )
F_47 ( & V_33 -> V_154 , V_104 + 1 ) ;
V_71:
F_27 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_133 ;
}
static int F_85 ( struct V_10 * V_11 , struct V_143 * V_143 , int V_28 )
{
struct V_9 * V_33 ;
unsigned long V_79 ;
int V_133 ;
V_33 = F_4 ( V_11 ) ;
F_26 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
V_133 = F_86 ( V_11 , V_143 , V_28 ) ;
if ( ! V_133 && V_33 -> V_45 != V_155 &&
! F_12 ( & V_33 -> V_149 ) )
F_47 ( & V_33 -> V_154 , V_104 ) ;
F_27 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_133 ;
}
static int
F_87 ( struct V_17 * V_13 , struct V_143 * V_143 , struct V_1 * V_4 , int V_156 ,
int * V_28 )
{
struct V_5 * V_8 ;
V_157:
F_18 (req, &ep->queue, queue) {
unsigned V_158 , V_159 , V_160 ;
int V_161 , V_162 ;
int V_163 = 0 ;
V_158 = V_143 -> V_146 - V_143 -> V_164 ;
V_159 = V_8 -> V_8 . V_86 - V_8 -> V_8 . V_82 ;
V_160 = F_88 ( V_158 , V_159 ) ;
V_162 = F_89 ( V_143 -> V_151 ) ;
if ( F_81 ( V_160 == 0 ) )
V_161 = 1 ;
else {
char * V_165 , * V_166 ;
if ( V_156 < V_4 -> V_4 . V_76 && V_156 < V_160 )
break;
V_160 = F_88 ( V_160 , ( unsigned ) V_156 ) ;
if ( V_160 == 0 )
break;
if ( V_160 > V_4 -> V_4 . V_76 ) {
V_163 = 1 ;
V_160 -= ( V_160 % V_4 -> V_4 . V_76 ) ;
}
V_161 = ( V_160 % V_4 -> V_4 . V_76 ) != 0 ;
V_165 = V_143 -> V_145 + V_143 -> V_164 ;
V_166 = V_8 -> V_8 . V_88 + V_8 -> V_8 . V_82 ;
if ( V_162 )
memcpy ( V_165 , V_166 , V_160 ) ;
else
memcpy ( V_166 , V_165 , V_160 ) ;
V_4 -> V_127 = V_104 ;
V_156 -= V_160 ;
V_143 -> V_164 += V_160 ;
V_8 -> V_8 . V_82 += V_160 ;
}
if ( V_161 ) {
if ( V_158 == V_159 ) {
V_8 -> V_8 . V_28 = 0 ;
* V_28 = 0 ;
} else if ( V_162 ) {
V_8 -> V_8 . V_28 = 0 ;
if ( V_159 > V_158 )
* V_28 = - V_167 ;
else
* V_28 = 0 ;
} else if ( ! V_162 ) {
* V_28 = 0 ;
if ( V_158 > V_159 )
V_8 -> V_8 . V_28 = - V_167 ;
else
V_8 -> V_8 . V_28 = 0 ;
}
} else {
if ( V_8 -> V_8 . V_86 == V_8 -> V_8 . V_82
&& ! V_8 -> V_8 . V_168 )
V_8 -> V_8 . V_28 = 0 ;
if ( V_143 -> V_146 == V_143 -> V_164
&& ! ( V_143 -> V_169
& V_170 ) )
* V_28 = 0 ;
}
if ( V_8 -> V_8 . V_28 != - V_81 ) {
F_14 ( & V_8 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_8 -> V_8 . V_31 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_16 ( & V_13 -> V_30 ) ;
V_163 = 1 ;
}
if ( * V_28 != - V_81 )
break;
if ( V_163 )
goto V_157;
}
return V_156 ;
}
static int F_90 ( struct V_17 * V_13 , struct V_1 * V_4 )
{
int V_156 = V_4 -> V_4 . V_76 ;
if ( V_13 -> V_18 . V_22 == V_72 ) {
int V_171 ;
V_171 = F_23 ( V_4 -> V_60 -> V_68 ) ;
V_171 = ( V_171 >> 11 ) & 0x03 ;
V_171 *= 8 ;
V_156 += V_156 * V_171 ;
}
if ( V_13 -> V_18 . V_22 == V_23 ) {
switch ( V_4 -> V_60 -> V_69 & 0x03 ) {
case V_75 :
V_156 = 3 * 16 * 1024 * 8 ;
break;
case V_74 :
V_156 = 3 * 1024 * 8 ;
break;
case V_70 :
default:
break;
}
}
return V_156 ;
}
static struct V_1 * F_91 ( struct V_17 * V_13 , V_113 V_32 )
{
int V_107 ;
if ( ! F_92 ( ( V_13 -> V_18 . V_22 == V_23 ?
V_13 -> V_24 : V_13 -> V_25 ) ) )
return NULL ;
if ( ( V_32 & ~ V_84 ) == 0 )
return & V_13 -> V_4 [ 0 ] ;
for ( V_107 = 1 ; V_107 < V_108 ; V_107 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_107 ] ;
if ( ! V_4 -> V_60 )
continue;
if ( V_4 -> V_60 -> V_83 == V_32 )
return V_4 ;
}
return NULL ;
}
static int F_93 ( struct V_9 * V_33 , struct V_143 * V_143 ,
struct V_172 * V_173 ,
int * V_28 )
{
struct V_1 * V_174 ;
struct V_17 * V_13 = V_33 -> V_13 ;
int V_175 = 1 ;
unsigned V_176 ;
unsigned V_177 ;
V_176 = F_23 ( V_173 -> V_178 ) ;
V_177 = F_23 ( V_173 -> V_179 ) ;
switch ( V_173 -> V_180 ) {
case V_181 :
if ( V_173 -> V_182 != V_183 )
break;
V_13 -> V_32 = V_177 ;
* V_28 = 0 ;
F_24 ( F_7 ( V_13 ) , L_22 ,
V_177 ) ;
V_175 = 0 ;
break;
case V_184 :
if ( V_173 -> V_182 == V_183 ) {
V_175 = 0 ;
switch ( V_177 ) {
case V_100 :
break;
case V_99 :
V_13 -> V_18 . V_185 = 1 ;
break;
case V_186 :
V_13 -> V_18 . V_187 = 1 ;
break;
case V_188 :
V_13 -> V_18 . V_189 = 1 ;
break;
case V_190 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_177 = V_191 ;
else
V_175 = - V_192 ;
break;
case V_193 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_177 = V_194 ;
else
V_175 = - V_192 ;
break;
case V_195 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_177 = V_196 ;
else
V_175 = - V_192 ;
break;
default:
V_175 = - V_192 ;
}
if ( V_175 == 0 ) {
V_13 -> V_98 |= ( 1 << V_177 ) ;
* V_28 = 0 ;
}
} else if ( V_173 -> V_182 == V_197 ) {
V_174 = F_91 ( V_13 , V_176 ) ;
if ( ! V_174 || V_174 -> V_4 . V_63 == V_64 ) {
V_175 = - V_192 ;
break;
}
V_174 -> V_77 = 1 ;
V_175 = 0 ;
* V_28 = 0 ;
}
break;
case V_198 :
if ( V_173 -> V_182 == V_183 ) {
V_175 = 0 ;
switch ( V_177 ) {
case V_100 :
V_177 = V_100 ;
break;
case V_190 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_177 = V_191 ;
else
V_175 = - V_192 ;
break;
case V_193 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_177 = V_194 ;
else
V_175 = - V_192 ;
break;
case V_195 :
if ( F_5 ( V_33 ) -> V_22 ==
V_34 )
V_177 = V_196 ;
else
V_175 = - V_192 ;
break;
default:
V_175 = - V_192 ;
break;
}
if ( V_175 == 0 ) {
V_13 -> V_98 &= ~ ( 1 << V_177 ) ;
* V_28 = 0 ;
}
} else if ( V_173 -> V_182 == V_197 ) {
V_174 = F_91 ( V_13 , V_176 ) ;
if ( ! V_174 ) {
V_175 = - V_192 ;
break;
}
if ( ! V_174 -> V_78 )
V_174 -> V_77 = 0 ;
V_175 = 0 ;
* V_28 = 0 ;
}
break;
case V_199 :
if ( V_173 -> V_182 == V_200
|| V_173 -> V_182 == V_201
|| V_173 -> V_182 == V_202 ) {
char * V_88 ;
V_88 = ( char * ) V_143 -> V_145 ;
if ( V_143 -> V_146 > 0 ) {
if ( V_173 -> V_182 == V_202 ) {
V_174 = F_91 ( V_13 , V_176 ) ;
if ( ! V_174 ) {
V_175 = - V_192 ;
break;
}
V_88 [ 0 ] = V_174 -> V_77 ;
} else if ( V_173 -> V_182 ==
V_200 ) {
V_88 [ 0 ] = ( V_113 ) V_13 -> V_98 ;
} else
V_88 [ 0 ] = 0 ;
}
if ( V_143 -> V_146 > 1 )
V_88 [ 1 ] = 0 ;
V_143 -> V_164 = F_51 ( T_2 , 2 ,
V_143 -> V_146 ) ;
V_175 = 0 ;
* V_28 = 0 ;
}
break;
}
return V_175 ;
}
static void F_94 ( unsigned long V_203 )
{
struct V_9 * V_33 = (struct V_9 * ) V_203 ;
struct V_17 * V_13 = V_33 -> V_13 ;
struct V_144 * V_144 , * V_171 ;
unsigned long V_79 ;
int V_156 , V_204 ;
int V_107 ;
switch ( V_13 -> V_18 . V_22 ) {
case V_205 :
V_204 = 8 * 12 ;
break;
case V_73 :
V_204 = 64 * 19 ;
break;
case V_72 :
V_204 = 512 * 13 * 8 ;
break;
case V_23 :
V_204 = 490000 ;
break;
default:
F_82 ( F_6 ( V_33 ) , L_23 ) ;
return;
}
F_26 ( & V_13 -> V_30 , V_79 ) ;
if ( ! V_33 -> V_148 ) {
F_82 ( F_6 ( V_33 ) ,
L_24 ) ;
F_27 ( & V_13 -> V_30 , V_79 ) ;
return;
}
for ( V_107 = 0 ; V_107 < V_108 ; V_107 ++ ) {
if ( ! V_122 [ V_107 ] )
break;
V_13 -> V_4 [ V_107 ] . V_125 = 0 ;
}
V_206:
F_95 (urbp, tmp, &dum_hcd->urbp_list, urbp_list) {
struct V_143 * V_143 ;
struct V_5 * V_8 ;
V_113 V_32 ;
struct V_1 * V_4 = NULL ;
int type ;
int V_28 = - V_81 ;
V_143 = V_144 -> V_143 ;
if ( V_143 -> V_207 )
goto V_208;
else if ( V_33 -> V_45 != V_155 )
continue;
type = F_83 ( V_143 -> V_151 ) ;
if ( V_204 <= 0 && type == V_209 )
continue;
V_32 = F_96 ( V_143 -> V_151 ) ;
if ( F_89 ( V_143 -> V_151 ) )
V_32 |= V_84 ;
V_4 = F_91 ( V_13 , V_32 ) ;
if ( ! V_4 ) {
F_24 ( F_6 ( V_33 ) ,
L_25 ,
V_143 ) ;
V_28 = - V_210 ;
goto V_208;
}
if ( V_4 -> V_125 )
continue;
V_4 -> V_125 = 1 ;
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_143 -> V_153 ) {
V_4 -> V_126 = 1 ;
V_143 -> V_153 = 0 ;
}
if ( V_4 -> V_77 && ! V_4 -> V_126 ) {
F_24 ( F_6 ( V_33 ) , L_26 ,
V_4 -> V_4 . V_63 , V_143 ) ;
V_28 = - V_211 ;
goto V_208;
}
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_4 -> V_126 ) {
struct V_172 V_173 ;
int V_92 = 1 ;
V_173 = * (struct V_172 * ) V_143 -> V_212 ;
F_18 (req, &ep->queue, queue) {
F_14 ( & V_8 -> V_26 ) ;
V_8 -> V_8 . V_28 = - V_167 ;
F_24 ( F_7 ( V_13 ) , L_27 ,
V_8 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_8 -> V_8 . V_31 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_16 ( & V_13 -> V_30 ) ;
V_4 -> V_125 = 0 ;
goto V_206;
}
V_4 -> V_127 = V_104 ;
V_4 -> V_126 = 0 ;
V_4 -> V_77 = 0 ;
V_92 = F_93 ( V_33 , V_143 , & V_173 ,
& V_28 ) ;
if ( V_92 > 0 ) {
F_15 ( & V_13 -> V_30 ) ;
V_92 = V_13 -> V_54 -> V_173 ( & V_13 -> V_18 ,
& V_173 ) ;
F_16 ( & V_13 -> V_30 ) ;
if ( V_92 >= 0 ) {
V_156 = 64 * 1024 ;
goto V_213;
}
}
if ( V_92 < 0 ) {
if ( V_92 != - V_192 )
F_24 ( F_7 ( V_13 ) ,
L_28 ,
V_92 ) ;
V_28 = - V_211 ;
V_143 -> V_164 = 0 ;
}
goto V_208;
}
V_156 = V_204 ;
switch ( F_83 ( V_143 -> V_151 ) ) {
case V_214 :
V_156 = V_61 ( V_156 , F_90 ( V_13 , V_4 ) ) ;
V_28 = - V_215 ;
break;
case V_216 :
V_156 = V_61 ( V_156 , F_90 ( V_13 , V_4 ) ) ;
default:
V_213:
V_4 -> V_127 = V_104 ;
V_204 = F_87 ( V_13 , V_143 , V_4 , V_156 , & V_28 ) ;
break;
}
if ( V_28 == - V_81 )
continue;
V_208:
F_97 ( & V_144 -> V_149 ) ;
F_33 ( V_144 ) ;
if ( V_4 )
V_4 -> V_125 = V_4 -> V_126 = 0 ;
F_98 ( F_5 ( V_33 ) , V_143 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_99 ( F_5 ( V_33 ) , V_143 , V_28 ) ;
F_16 ( & V_13 -> V_30 ) ;
goto V_206;
}
if ( F_12 ( & V_33 -> V_149 ) ) {
F_100 ( V_33 -> V_148 ) ;
V_33 -> V_148 = NULL ;
} else if ( V_33 -> V_45 == V_155 ) {
F_47 ( & V_33 -> V_154 , V_104 + F_46 ( 1 ) ) ;
}
F_27 ( & V_13 -> V_30 , V_79 ) ;
}
static int F_101 ( struct V_10 * V_11 , char * V_88 )
{
struct V_9 * V_33 ;
unsigned long V_79 ;
int V_62 = 0 ;
V_33 = F_4 ( V_11 ) ;
F_26 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
if ( ! F_102 ( V_11 ) )
goto V_71;
if ( V_33 -> V_52 && F_103 ( V_104 , V_33 -> V_103 ) ) {
V_33 -> V_35 |= ( V_217 << 16 ) ;
V_33 -> V_35 &= ~ V_51 ;
F_20 ( V_33 ) ;
}
if ( ( V_33 -> V_35 & V_218 ) != 0 ) {
* V_88 = ( 1 << 1 ) ;
F_24 ( F_6 ( V_33 ) , L_29 ,
V_33 -> V_35 ) ;
V_62 = 1 ;
if ( V_33 -> V_45 == V_46 )
F_104 ( V_11 ) ;
}
V_71:
F_27 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_62 ;
}
static inline void
F_105 ( struct V_219 * V_60 )
{
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_65 = 0x2a ;
V_60 -> V_220 = 12 ;
V_60 -> V_221 = F_106 ( 0x0001 ) ;
V_60 -> V_222 = 1 ;
V_60 -> V_223 . V_224 . V_225 = 0x04 ;
V_60 -> V_223 . V_224 . V_226 = 0xffff ;
}
static inline void
F_107 ( struct V_219 * V_60 )
{
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_65 = 0x29 ;
V_60 -> V_220 = 9 ;
V_60 -> V_221 = F_106 ( 0x0001 ) ;
V_60 -> V_222 = 1 ;
V_60 -> V_223 . V_227 . V_226 [ 0 ] = 0xff ;
V_60 -> V_223 . V_227 . V_226 [ 1 ] = 0xff ;
}
static int F_108 (
struct V_10 * V_11 ,
T_5 V_228 ,
T_5 V_179 ,
T_5 V_178 ,
char * V_88 ,
T_5 V_229
) {
struct V_9 * V_33 ;
int V_62 = 0 ;
unsigned long V_79 ;
if ( ! F_102 ( V_11 ) )
return - V_230 ;
V_33 = F_4 ( V_11 ) ;
F_26 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
switch ( V_228 ) {
case V_231 :
break;
case V_232 :
switch ( V_179 ) {
case V_233 :
if ( V_11 -> V_22 == V_34 ) {
F_24 ( F_6 ( V_33 ) ,
L_30
L_31 ) ;
goto error;
}
if ( V_33 -> V_35 & V_51 ) {
V_33 -> V_52 = 1 ;
V_33 -> V_103 = V_104 +
F_46 ( 20 ) ;
}
break;
case V_234 :
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
V_33 -> V_35 &= ~ ( 1 << V_179 ) ;
F_20 ( V_33 ) ;
}
break;
case V_235 :
if ( V_11 -> V_22 == V_34 &&
( V_229 < V_236 ||
V_179 != ( V_237 << 8 ) ) ) {
F_24 ( F_6 ( V_33 ) ,
L_33
L_34 ) ;
goto error;
}
if ( V_11 -> V_22 == V_34 )
F_105 ( (struct V_219 * ) V_88 ) ;
else
F_107 ( (struct V_219 * ) V_88 ) ;
break;
case V_238 :
* ( V_239 * ) V_88 = F_109 ( 0 ) ;
break;
case V_240 :
if ( V_178 != 1 )
V_62 = - V_211 ;
if ( V_33 -> V_52 &&
F_103 ( V_104 , V_33 -> V_103 ) ) {
V_33 -> V_35 |= ( V_217 << 16 ) ;
V_33 -> V_35 &= ~ V_51 ;
}
if ( ( V_33 -> V_35 & V_53 ) != 0 &&
F_103 ( V_104 , V_33 -> V_103 ) ) {
V_33 -> V_35 |= ( V_241 << 16 ) ;
V_33 -> V_35 &= ~ V_53 ;
if ( V_33 -> V_13 -> V_37 ) {
V_33 -> V_35 |= V_40 ;
if ( V_11 -> V_22 < V_34 ) {
switch ( V_33 -> V_13 -> V_18 . V_22 ) {
case V_72 :
V_33 -> V_35 |=
V_50 ;
break;
case V_205 :
V_33 -> V_13 -> V_18 . V_128 ->
V_76 = 8 ;
V_33 -> V_35 |=
V_49 ;
break;
default:
V_33 -> V_13 -> V_18 . V_22 =
V_73 ;
break;
}
}
}
}
F_20 ( V_33 ) ;
( ( V_242 * ) V_88 ) [ 0 ] = F_106 ( V_33 -> V_35 ) ;
( ( V_242 * ) V_88 ) [ 1 ] = F_106 ( V_33 -> V_35 >> 16 ) ;
break;
case V_243 :
V_62 = - V_211 ;
break;
case V_244 :
switch ( V_179 ) {
case V_245 :
if ( V_11 -> V_22 != V_34 ) {
F_24 ( F_6 ( V_33 ) ,
L_35
L_36 ) ;
goto error;
}
break;
case V_246 :
case V_247 :
if ( V_11 -> V_22 != V_34 ) {
F_24 ( F_6 ( V_33 ) ,
L_37
L_36 ) ;
goto error;
}
break;
case V_233 :
if ( V_11 -> V_22 == V_34 ) {
F_24 ( F_6 ( V_33 ) ,
L_30
L_31 ) ;
goto error;
}
if ( V_33 -> V_47 ) {
V_33 -> V_35 |= V_51 ;
F_20 ( V_33 ) ;
if ( ( ( 1 << V_99 )
& V_33 -> V_13 -> V_98 ) != 0 )
F_24 ( F_6 ( V_33 ) ,
L_38 ) ;
}
break;
case V_234 :
if ( V_11 -> V_22 == V_34 )
V_33 -> V_35 |= V_36 ;
else
V_33 -> V_35 |= V_48 ;
F_20 ( V_33 ) ;
break;
case V_248 :
if ( V_11 -> V_22 != V_34 ) {
F_24 ( F_6 ( V_33 ) ,
L_39
L_36 ) ;
goto error;
}
case V_249 :
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
V_33 -> V_103 = V_104 + F_46 ( 50 ) ;
default:
if ( V_11 -> V_22 == V_34 ) {
if ( ( V_33 -> V_35 &
V_36 ) != 0 ) {
V_33 -> V_35 |= ( 1 << V_179 ) ;
F_20 ( V_33 ) ;
}
} else
if ( ( V_33 -> V_35 &
V_48 ) != 0 ) {
V_33 -> V_35 |= ( 1 << V_179 ) ;
F_20 ( V_33 ) ;
}
}
break;
case V_250 :
if ( V_11 -> V_22 != V_34 ) {
F_24 ( F_6 ( V_33 ) ,
L_40
L_36 ) ;
goto error;
}
* ( V_239 * ) V_88 = F_109 ( 0 ) ;
break;
case V_251 :
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
V_228 , V_179 , V_178 , V_229 ) ;
error:
V_62 = - V_211 ;
}
F_27 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
if ( ( V_33 -> V_35 & V_218 ) != 0 )
F_52 ( V_11 ) ;
return V_62 ;
}
static int F_110 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
F_24 ( & V_11 -> V_15 . V_252 -> V_19 , L_17 , V_142 ) ;
F_73 ( & V_33 -> V_13 -> V_30 ) ;
V_33 -> V_45 = V_46 ;
F_20 ( V_33 ) ;
V_11 -> V_141 = V_253 ;
F_74 ( & V_33 -> V_13 -> V_30 ) ;
return 0 ;
}
static int F_111 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
int V_133 = 0 ;
F_24 ( & V_11 -> V_15 . V_252 -> V_19 , L_17 , V_142 ) ;
F_73 ( & V_33 -> V_13 -> V_30 ) ;
if ( ! F_102 ( V_11 ) ) {
V_133 = - V_29 ;
} else {
V_33 -> V_45 = V_155 ;
F_20 ( V_33 ) ;
if ( ! F_12 ( & V_33 -> V_149 ) )
F_47 ( & V_33 -> V_154 , V_104 ) ;
V_11 -> V_141 = V_254 ;
}
F_74 ( & V_33 -> V_13 -> V_30 ) ;
return V_133 ;
}
static inline T_3
F_112 ( char * V_88 , T_6 V_255 , struct V_143 * V_143 )
{
int V_4 = F_96 ( V_143 -> V_151 ) ;
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
F_113 ( struct V_14 * V_19 , struct V_114 * V_115 , char * V_88 )
{
struct V_10 * V_11 = F_114 ( V_19 ) ;
struct V_9 * V_33 = F_4 ( V_11 ) ;
struct V_144 * V_144 ;
T_6 V_255 = 0 ;
unsigned long V_79 ;
F_26 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
F_18 (urbp, &dum_hcd->urbp_list, urbp_list) {
T_6 V_256 ;
V_256 = F_112 ( V_88 , V_117 - V_255 , V_144 -> V_143 ) ;
V_88 += V_256 ;
V_255 += V_256 ;
}
F_27 ( & V_33 -> V_13 -> V_30 , V_79 ) ;
return V_255 ;
}
static int F_115 ( struct V_9 * V_33 )
{
F_116 ( & V_33 -> V_154 ) ;
V_33 -> V_154 . V_116 = F_94 ;
V_33 -> V_154 . V_257 = ( unsigned long ) V_33 ;
V_33 -> V_45 = V_155 ;
F_30 ( & V_33 -> V_149 ) ;
F_5 ( V_33 ) -> V_258 = V_259 ;
F_5 ( V_33 ) -> V_141 = V_254 ;
F_5 ( V_33 ) -> V_260 = 1 ;
#ifdef F_59
F_5 ( V_33 ) -> V_15 . V_261 = 1 ;
#endif
return 0 ;
return F_65 ( F_6 ( V_33 ) , & V_262 ) ;
}
static int F_117 ( struct V_10 * V_11 )
{
struct V_9 * V_33 = F_4 ( V_11 ) ;
if ( ! F_118 ( V_11 ) )
return F_115 ( V_33 ) ;
F_119 ( & V_33 -> V_13 -> V_30 ) ;
F_116 ( & V_33 -> V_154 ) ;
V_33 -> V_154 . V_116 = F_94 ;
V_33 -> V_154 . V_257 = ( unsigned long ) V_33 ;
V_33 -> V_45 = V_155 ;
F_30 ( & V_33 -> V_149 ) ;
V_11 -> V_258 = V_259 ;
V_11 -> V_141 = V_254 ;
V_11 -> V_260 = 1 ;
#ifdef F_59
V_11 -> V_15 . V_261 = 1 ;
#endif
return F_65 ( F_6 ( V_33 ) , & V_262 ) ;
}
static void F_120 ( struct V_10 * V_11 )
{
struct V_17 * V_13 ;
V_13 = ( F_4 ( V_11 ) ) -> V_13 ;
F_71 ( F_6 ( F_4 ( V_11 ) ) , & V_262 ) ;
F_121 ( V_13 -> V_54 ) ;
F_122 ( F_6 ( F_4 ( V_11 ) ) , L_51 ) ;
}
static int F_123 ( struct V_10 * V_11 )
{
return F_43 ( NULL ) ;
}
static int F_124 ( struct V_10 * V_11 )
{
if ( F_118 ( V_11 ) ) {
V_132 . V_25 = F_4 ( V_11 ) ;
V_132 . V_25 -> V_13 = & V_132 ;
V_11 -> V_22 = V_263 ;
V_11 -> V_15 . V_252 -> V_22 = V_72 ;
} else {
V_132 . V_24 = F_4 ( V_11 ) ;
V_132 . V_24 -> V_13 = & V_132 ;
V_11 -> V_22 = V_34 ;
V_11 -> V_15 . V_252 -> V_22 = V_23 ;
}
return 0 ;
}
int F_125 ( struct V_10 * V_11 , struct V_264 * V_148 ,
struct V_265 * * V_266 , unsigned int V_267 ,
unsigned int V_268 , T_1 V_80 )
{
if ( V_11 -> V_22 != V_34 )
F_24 ( F_6 ( F_4 ( V_11 ) ) ,
L_52 ,
V_142 ) ;
return 0 ;
}
int F_126 ( struct V_10 * V_11 , struct V_264 * V_148 ,
struct V_265 * * V_266 , unsigned int V_267 ,
T_1 V_80 )
{
if ( V_11 -> V_22 != V_34 )
F_24 ( F_6 ( F_4 ( V_11 ) ) ,
L_52 ,
V_142 ) ;
return 0 ;
}
static int F_127 ( struct V_130 * V_131 )
{
struct V_10 * V_25 ;
struct V_10 * V_24 ;
int V_62 ;
F_122 ( & V_131 -> V_19 , L_53 V_269 L_54 , V_270 ) ;
if ( ! V_110 . V_111 )
V_9 . V_79 = V_263 ;
V_25 = F_128 ( & V_9 , & V_131 -> V_19 , F_129 ( & V_131 -> V_19 ) ) ;
if ( ! V_25 )
return - V_147 ;
V_25 -> V_271 = 1 ;
V_62 = F_130 ( V_25 , 0 , 0 ) ;
if ( V_62 != 0 ) {
F_131 ( V_25 ) ;
return V_62 ;
}
if ( V_110 . V_111 ) {
V_24 = F_132 ( & V_9 , & V_131 -> V_19 ,
F_129 ( & V_131 -> V_19 ) , V_25 ) ;
if ( ! V_24 ) {
V_62 = - V_147 ;
goto V_272;
}
V_62 = F_130 ( V_24 , 0 , 0 ) ;
if ( V_62 )
goto V_273;
}
return 0 ;
V_273:
F_131 ( V_24 ) ;
V_272:
F_131 ( V_25 ) ;
V_132 . V_25 = V_132 . V_24 = NULL ;
return V_62 ;
}
static int F_133 ( struct V_130 * V_131 )
{
struct V_17 * V_13 ;
V_13 = ( F_4 ( F_70 ( V_131 ) ) ) -> V_13 ;
if ( V_13 -> V_24 ) {
F_134 ( F_5 ( V_13 -> V_24 ) ) ;
F_131 ( F_5 ( V_13 -> V_24 ) ) ;
}
F_134 ( F_5 ( V_13 -> V_25 ) ) ;
F_131 ( F_5 ( V_13 -> V_25 ) ) ;
V_132 . V_25 = NULL ;
V_132 . V_24 = NULL ;
return 0 ;
}
static int F_135 ( struct V_130 * V_131 , T_4 V_141 )
{
struct V_10 * V_11 ;
struct V_9 * V_33 ;
int V_133 = 0 ;
F_24 ( & V_131 -> V_19 , L_17 , V_142 ) ;
V_11 = F_70 ( V_131 ) ;
V_33 = F_4 ( V_11 ) ;
if ( V_33 -> V_45 == V_155 ) {
F_136 ( & V_131 -> V_19 , L_55 ) ;
V_133 = - V_274 ;
} else
F_137 ( V_275 , & V_11 -> V_79 ) ;
return V_133 ;
}
static int F_138 ( struct V_130 * V_131 )
{
struct V_10 * V_11 ;
F_24 ( & V_131 -> V_19 , L_17 , V_142 ) ;
V_11 = F_70 ( V_131 ) ;
F_139 ( V_275 , & V_11 -> V_79 ) ;
F_52 ( V_11 ) ;
return 0 ;
}
static int T_7 F_140 ( void )
{
int V_62 = - V_147 ;
if ( F_141 () )
return - V_276 ;
if ( ! V_110 . V_112 && V_110 . V_111 )
return - V_67 ;
V_277 = F_142 ( V_278 , - 1 ) ;
if ( ! V_277 )
return V_62 ;
V_279 = F_142 ( V_134 , - 1 ) ;
if ( ! V_279 )
goto V_280;
V_62 = F_143 ( & V_281 ) ;
if ( V_62 < 0 )
goto V_282;
V_62 = F_143 ( & V_283 ) ;
if ( V_62 < 0 )
goto V_284;
V_62 = F_144 ( V_277 ) ;
if ( V_62 < 0 )
goto V_285;
if ( ! V_132 . V_25 ||
( ! V_132 . V_24 && V_110 . V_111 ) ) {
V_62 = - V_67 ;
goto V_286;
}
V_62 = F_144 ( V_279 ) ;
if ( V_62 < 0 )
goto V_286;
if ( ! F_70 ( V_279 ) ) {
V_62 = - V_67 ;
goto V_287;
}
return V_62 ;
V_287:
F_145 ( V_279 ) ;
V_286:
F_145 ( V_277 ) ;
V_285:
F_146 ( & V_283 ) ;
V_284:
F_146 ( & V_281 ) ;
V_282:
F_147 ( V_279 ) ;
V_280:
F_147 ( V_277 ) ;
return V_62 ;
}
static void T_8 F_148 ( void )
{
F_149 ( V_279 ) ;
F_149 ( V_277 ) ;
F_146 ( & V_283 ) ;
F_146 ( & V_281 ) ;
}
