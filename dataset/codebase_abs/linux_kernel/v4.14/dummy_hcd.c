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
int V_31 ;
V_13 -> V_32 = 0 ;
for ( V_31 = 0 ; V_31 < V_33 ; ++ V_31 )
F_11 ( V_13 , & V_13 -> V_4 [ V_31 ] ) ;
}
static void F_19 ( struct V_9 * V_34 )
{
struct V_17 * V_13 = V_34 -> V_13 ;
if ( F_5 ( V_34 ) -> V_22 == V_35 ) {
if ( ( V_34 -> V_36 & V_37 ) == 0 ) {
V_34 -> V_36 = 0 ;
} else if ( ! V_13 -> V_38 || V_13 -> V_39 ) {
V_34 -> V_36 &= ~ ( V_40 |
V_41 ) ;
if ( ( V_34 -> V_42 &
V_40 ) != 0 )
V_34 -> V_36 |=
( V_43 << 16 ) ;
} else {
V_34 -> V_36 |= ( V_40 |
V_44 ) ;
if ( ( V_34 -> V_42 &
V_40 ) == 0 )
V_34 -> V_36 |=
( V_43 << 16 ) ;
if ( ( V_34 -> V_36 & V_41 ) &&
( V_34 -> V_36 &
V_45 ) == V_46 &&
V_34 -> V_47 != V_48 )
V_34 -> V_49 = 1 ;
}
} else {
if ( ( V_34 -> V_36 & V_50 ) == 0 ) {
V_34 -> V_36 = 0 ;
} else if ( ! V_13 -> V_38 || V_13 -> V_39 ) {
V_34 -> V_36 &= ~ ( V_40 |
V_41 |
V_51 |
V_52 |
V_53 ) ;
if ( ( V_34 -> V_42 &
V_40 ) != 0 )
V_34 -> V_36 |=
( V_43 << 16 ) ;
} else {
V_34 -> V_36 |= V_40 ;
if ( ( V_34 -> V_42 &
V_40 ) == 0 )
V_34 -> V_36 |=
( V_43 << 16 ) ;
if ( ( V_34 -> V_36 & V_41 ) == 0 )
V_34 -> V_36 &= ~ V_53 ;
else if ( ( V_34 -> V_36 &
V_53 ) == 0 &&
V_34 -> V_47 != V_48 )
V_34 -> V_49 = 1 ;
}
}
}
static void F_20 ( struct V_9 * V_34 )
{
struct V_17 * V_13 = V_34 -> V_13 ;
unsigned int V_54 ;
V_34 -> V_49 = 0 ;
if ( V_13 -> V_38 )
if ( ( F_5 ( V_34 ) -> V_22 == V_35 &&
V_13 -> V_18 . V_22 != V_23 ) ||
( F_5 ( V_34 ) -> V_22 != V_35 &&
V_13 -> V_18 . V_22 == V_23 ) )
return;
F_19 ( V_34 ) ;
V_54 = ( F_5 ( V_34 ) -> V_22 == V_35 ?
V_37 : V_50 ) ;
if ( ( V_34 -> V_36 & V_41 ) == 0 ||
V_34 -> V_49 )
V_34 -> V_55 = 0 ;
if ( ( V_34 -> V_36 & V_54 ) == 0 ||
( V_34 -> V_36 & V_56 ) != 0 ) {
unsigned int V_57 = V_54 &
V_34 -> V_42 & ( ~ V_34 -> V_36 ) ;
unsigned int V_58 = V_56 &
( ~ V_34 -> V_42 ) & V_34 -> V_36 ;
if ( V_13 -> V_59 && ( V_57 || V_58 ) ) {
F_18 ( V_13 ) ;
++ V_13 -> V_60 ;
F_15 ( & V_13 -> V_30 ) ;
if ( V_58 )
F_21 ( & V_13 -> V_18 , V_13 -> V_61 ) ;
else
V_13 -> V_61 -> V_57 ( & V_13 -> V_18 ) ;
F_17 ( & V_13 -> V_30 ) ;
-- V_13 -> V_60 ;
}
} else if ( V_34 -> V_49 != V_34 -> V_62 &&
V_13 -> V_59 ) {
++ V_13 -> V_60 ;
F_15 ( & V_13 -> V_30 ) ;
if ( V_34 -> V_62 && V_13 -> V_61 -> V_63 )
V_13 -> V_61 -> V_63 ( & V_13 -> V_18 ) ;
else if ( ! V_34 -> V_62 && V_13 -> V_61 -> V_64 )
V_13 -> V_61 -> V_64 ( & V_13 -> V_18 ) ;
F_17 ( & V_13 -> V_30 ) ;
-- V_13 -> V_60 ;
}
V_34 -> V_42 = V_34 -> V_36 ;
V_34 -> V_62 = V_34 -> V_49 ;
}
static int F_22 ( struct V_2 * V_3 ,
const struct V_65 * V_66 )
{
struct V_17 * V_13 ;
struct V_9 * V_34 ;
struct V_1 * V_4 ;
unsigned V_67 ;
int V_68 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_66 || V_4 -> V_66 || V_3 -> V_69 == V_70
|| V_66 -> V_71 != V_72 )
return - V_73 ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_61 )
return - V_29 ;
V_34 = F_9 ( & V_13 -> V_18 ) ;
if ( ! F_23 ( V_34 ) )
return - V_29 ;
V_67 = F_24 ( V_66 ) ;
V_68 = - V_73 ;
switch ( F_25 ( V_66 ) ) {
case V_74 :
if ( strstr ( V_4 -> V_4 . V_69 , L_1 )
|| strstr ( V_4 -> V_4 . V_69 , L_2 ) ) {
goto V_75;
}
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
if ( V_67 == 1024 )
break;
goto V_75;
case V_76 :
if ( V_67 == 512 )
break;
goto V_75;
case V_77 :
if ( V_67 == 8 || V_67 == 16 || V_67 == 32 || V_67 == 64 )
break;
default:
goto V_75;
}
break;
case V_78 :
if ( strstr ( V_4 -> V_4 . V_69 , L_1 ) )
goto V_75;
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
case V_76 :
if ( V_67 <= 1024 )
break;
case V_77 :
if ( V_67 <= 64 )
break;
default:
if ( V_67 <= 8 )
break;
goto V_75;
}
break;
case V_79 :
if ( strstr ( V_4 -> V_4 . V_69 , L_3 )
|| strstr ( V_4 -> V_4 . V_69 , L_2 ) )
goto V_75;
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
case V_76 :
if ( V_67 <= 1024 )
break;
case V_77 :
if ( V_67 <= 1023 )
break;
default:
goto V_75;
}
break;
default:
goto V_75;
}
V_3 -> V_80 = V_67 ;
if ( F_26 ( V_3 -> V_81 ) ) {
if ( ! F_27 ( V_66 ) ) {
F_28 ( F_7 ( V_13 ) , L_4
L_5 , V_3 -> V_69 ) ;
return - V_73 ;
}
V_4 -> V_82 = 1 ;
}
V_4 -> V_66 = V_66 ;
F_29 (udc_dev(dum), L_6 ,
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
V_4 -> V_83 = V_4 -> V_84 = 0 ;
V_68 = 0 ;
V_75:
return V_68 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
unsigned long V_85 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_4 -> V_66 || V_3 -> V_69 == V_70 )
return - V_73 ;
V_13 = F_8 ( V_4 ) ;
F_31 ( & V_13 -> V_30 , V_85 ) ;
V_4 -> V_66 = NULL ;
V_4 -> V_82 = 0 ;
F_11 ( V_13 , V_4 ) ;
F_32 ( & V_13 -> V_30 , V_85 ) ;
F_29 ( F_7 ( V_13 ) , L_15 , V_3 -> V_69 ) ;
return 0 ;
}
static struct V_6 * F_33 ( struct V_2 * V_3 ,
T_1 V_86 )
{
struct V_5 * V_8 ;
if ( ! V_3 )
return NULL ;
V_8 = F_34 ( sizeof( * V_8 ) , V_86 ) ;
if ( ! V_8 )
return NULL ;
F_35 ( & V_8 -> V_26 ) ;
return & V_8 -> V_8 ;
}
static void F_36 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_5 * V_8 ;
if ( ! V_3 || ! V_7 ) {
F_37 ( 1 ) ;
return;
}
V_8 = F_3 ( V_7 ) ;
F_37 ( ! F_12 ( & V_8 -> V_26 ) ) ;
F_38 ( V_8 ) ;
}
static void F_39 ( struct V_2 * V_4 , struct V_6 * V_8 )
{
}
static int F_40 ( struct V_2 * V_3 , struct V_6 * V_7 ,
T_1 V_86 )
{
struct V_1 * V_4 ;
struct V_5 * V_8 ;
struct V_17 * V_13 ;
struct V_9 * V_34 ;
unsigned long V_85 ;
V_8 = F_3 ( V_7 ) ;
if ( ! V_7 || ! F_12 ( & V_8 -> V_26 ) || ! V_7 -> V_87 )
return - V_73 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ( ! V_4 -> V_66 && V_3 -> V_69 != V_70 ) )
return - V_73 ;
V_13 = F_8 ( V_4 ) ;
V_34 = F_9 ( & V_13 -> V_18 ) ;
if ( ! V_13 -> V_61 || ! F_23 ( V_34 ) )
return - V_29 ;
#if 0
dev_dbg(udc_dev(dum), "ep %p queue req %p to %s, len %d buf %p\n",
ep, _req, _ep->name, _req->length, _req->buf);
#endif
V_7 -> V_28 = - V_88 ;
V_7 -> V_89 = 0 ;
F_31 ( & V_13 -> V_30 , V_85 ) ;
if ( V_4 -> V_66 && ( V_4 -> V_66 -> V_90 & V_91 ) &&
F_12 ( & V_13 -> V_92 . V_26 ) &&
F_12 ( & V_4 -> V_26 ) &&
V_7 -> V_93 <= V_94 ) {
V_8 = & V_13 -> V_92 ;
V_8 -> V_8 = * V_7 ;
V_8 -> V_8 . V_95 = V_13 -> V_96 ;
memcpy ( V_13 -> V_96 , V_7 -> V_95 , V_7 -> V_93 ) ;
V_8 -> V_8 . V_97 = V_13 ;
V_8 -> V_8 . V_87 = F_39 ;
F_41 ( & V_8 -> V_26 , & V_4 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_7 -> V_89 = V_7 -> V_93 ;
V_7 -> V_28 = 0 ;
F_16 ( V_3 , V_7 ) ;
F_17 ( & V_13 -> V_30 ) ;
} else
F_41 ( & V_8 -> V_26 , & V_4 -> V_26 ) ;
F_32 ( & V_13 -> V_30 , V_85 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
int V_68 = - V_73 ;
unsigned long V_85 ;
struct V_5 * V_8 = NULL ;
if ( ! V_3 || ! V_7 )
return V_68 ;
V_4 = F_1 ( V_3 ) ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_61 )
return - V_29 ;
F_43 ( V_85 ) ;
F_17 ( & V_13 -> V_30 ) ;
F_44 (req, &ep->queue, queue) {
if ( & V_8 -> V_8 == V_7 ) {
F_14 ( & V_8 -> V_26 ) ;
V_7 -> V_28 = - V_98 ;
V_68 = 0 ;
break;
}
}
F_15 ( & V_13 -> V_30 ) ;
if ( V_68 == 0 ) {
F_29 ( F_7 ( V_13 ) ,
L_16 ,
V_8 , V_3 -> V_69 , V_7 -> V_93 , V_7 -> V_95 ) ;
F_16 ( V_3 , V_7 ) ;
}
F_45 ( V_85 ) ;
return V_68 ;
}
static int
F_46 ( struct V_2 * V_3 , int V_99 , int V_84 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
if ( ! V_3 )
return - V_73 ;
V_4 = F_1 ( V_3 ) ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_61 )
return - V_29 ;
if ( ! V_99 )
V_4 -> V_83 = V_4 -> V_84 = 0 ;
else if ( V_4 -> V_66 && ( V_4 -> V_66 -> V_90 & V_91 ) &&
! F_12 ( & V_4 -> V_26 ) )
return - V_100 ;
else {
V_4 -> V_83 = 1 ;
if ( V_84 )
V_4 -> V_84 = 1 ;
}
return 0 ;
}
static int
F_47 ( struct V_2 * V_3 , int V_99 )
{
return F_46 ( V_3 , V_99 , 0 ) ;
}
static int F_48 ( struct V_2 * V_3 )
{
if ( ! V_3 || V_3 -> V_69 == V_70 )
return - V_73 ;
return F_46 ( V_3 , 1 , 1 ) ;
}
static int F_49 ( struct V_21 * V_101 )
{
struct V_102 V_103 ;
F_50 ( & V_103 ) ;
return V_103 . V_104 / V_105 ;
}
static int F_51 ( struct V_21 * V_101 )
{
struct V_9 * V_34 ;
V_34 = F_9 ( V_101 ) ;
if ( ! ( V_34 -> V_13 -> V_106 & ( ( 1 << V_107 )
| ( 1 << V_108 ) ) ) )
return - V_73 ;
if ( ( V_34 -> V_36 & V_40 ) == 0 )
return - V_109 ;
if ( ( V_34 -> V_36 & V_53 ) == 0 &&
V_34 -> V_47 != V_48 )
return - V_110 ;
V_34 -> V_55 = 1 ;
V_34 -> V_111 = V_112 + F_52 ( 20 ) ;
F_53 ( & F_5 ( V_34 ) -> V_113 , V_34 -> V_111 ) ;
return 0 ;
}
static int F_54 ( struct V_21 * V_101 , int V_99 )
{
struct V_17 * V_13 ;
V_101 -> V_114 = ( V_99 != 0 ) ;
V_13 = F_9 ( V_101 ) -> V_13 ;
if ( V_99 )
V_13 -> V_106 |= ( 1 << V_115 ) ;
else
V_13 -> V_106 &= ~ ( 1 << V_115 ) ;
return 0 ;
}
static void F_55 ( struct V_17 * V_13 )
{
if ( V_13 -> V_18 . V_22 == V_23 )
V_13 -> V_4 [ 0 ] . V_4 . V_80 = 9 ;
else
V_13 -> V_4 [ 0 ] . V_4 . V_80 = 64 ;
}
static int F_56 ( struct V_21 * V_101 , int V_99 )
{
struct V_9 * V_34 ;
struct V_17 * V_13 ;
unsigned long V_85 ;
V_13 = F_10 ( & V_101 -> V_19 ) ;
V_34 = F_9 ( V_101 ) ;
F_31 ( & V_13 -> V_30 , V_85 ) ;
V_13 -> V_38 = ( V_99 != 0 ) ;
F_20 ( V_34 ) ;
F_32 ( & V_13 -> V_30 , V_85 ) ;
F_57 ( F_5 ( V_34 ) ) ;
return 0 ;
}
static void F_58 ( struct V_21 * V_101 ,
enum V_116 V_22 )
{
struct V_17 * V_13 ;
V_13 = F_10 ( & V_101 -> V_19 ) ;
if ( V_117 . V_118 )
V_13 -> V_18 . V_22 = F_59 ( V_119 , V_23 , V_22 ) ;
else if ( V_117 . V_120 )
V_13 -> V_18 . V_22 = F_59 ( V_119 , V_76 , V_22 ) ;
else
V_13 -> V_18 . V_22 = V_77 ;
F_55 ( V_13 ) ;
if ( V_13 -> V_18 . V_22 < V_22 )
F_29 ( F_7 ( V_13 ) , L_17
L_18 ,
F_60 ( V_22 ) ) ;
}
static T_2 F_61 ( struct V_14 * V_19 , struct V_121 * V_122 ,
char * V_95 )
{
struct V_17 * V_13 = F_10 ( V_19 ) ;
if ( ! V_13 -> V_61 || ! V_13 -> V_61 -> V_123 )
return 0 ;
return F_62 ( V_95 , V_124 , L_19 , V_13 -> V_61 -> V_123 ) ;
}
static int F_63 ( struct V_21 * V_125 ,
struct V_126 * V_61 )
{
struct V_9 * V_34 = F_9 ( V_125 ) ;
struct V_17 * V_13 = V_34 -> V_13 ;
if ( V_61 -> V_127 == V_128 )
return - V_73 ;
F_64 ( & V_13 -> V_30 ) ;
V_13 -> V_106 = 0 ;
V_13 -> V_61 = V_61 ;
V_13 -> V_59 = 1 ;
F_65 ( & V_13 -> V_30 ) ;
return 0 ;
}
static int F_66 ( struct V_21 * V_125 )
{
struct V_9 * V_34 = F_9 ( V_125 ) ;
struct V_17 * V_13 = V_34 -> V_13 ;
F_64 ( & V_13 -> V_30 ) ;
V_13 -> V_59 = 0 ;
F_18 ( V_13 ) ;
while ( V_13 -> V_60 > 0 ) {
F_65 ( & V_13 -> V_30 ) ;
F_67 ( 1000 , 2000 ) ;
F_64 ( & V_13 -> V_30 ) ;
}
V_13 -> V_61 = NULL ;
F_65 ( & V_13 -> V_30 ) ;
return 0 ;
}
static void F_68 ( struct V_17 * V_13 )
{
int V_31 ;
F_35 ( & V_13 -> V_18 . V_129 ) ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_31 ] ;
if ( ! V_130 [ V_31 ] . V_69 )
break;
V_4 -> V_4 . V_69 = V_130 [ V_31 ] . V_69 ;
V_4 -> V_4 . V_131 = V_130 [ V_31 ] . V_131 ;
V_4 -> V_4 . V_132 = & V_133 ;
F_41 ( & V_4 -> V_4 . V_129 , & V_13 -> V_18 . V_129 ) ;
V_4 -> V_83 = V_4 -> V_84 = V_4 -> V_134 =
V_4 -> V_135 = 0 ;
F_69 ( & V_4 -> V_4 , ~ 0 ) ;
V_4 -> V_4 . V_136 = 16 ;
V_4 -> V_137 = V_112 ;
V_4 -> V_18 = & V_13 -> V_18 ;
V_4 -> V_66 = NULL ;
F_35 ( & V_4 -> V_26 ) ;
}
V_13 -> V_18 . V_138 = & V_13 -> V_4 [ 0 ] . V_4 ;
F_14 ( & V_13 -> V_4 [ 0 ] . V_4 . V_129 ) ;
F_35 ( & V_13 -> V_92 . V_26 ) ;
#ifdef F_70
V_13 -> V_18 . V_139 = 1 ;
#endif
}
static int F_71 ( struct V_140 * V_141 )
{
struct V_17 * V_13 ;
int V_142 ;
V_13 = * ( ( void * * ) F_72 ( & V_141 -> V_19 ) ) ;
F_73 ( & V_13 -> V_18 , sizeof( struct V_21 ) ) ;
V_13 -> V_18 . V_69 = V_143 ;
V_13 -> V_18 . V_132 = & V_144 ;
if ( V_117 . V_118 )
V_13 -> V_18 . V_127 = V_23 ;
else if ( V_117 . V_120 )
V_13 -> V_18 . V_127 = V_76 ;
else
V_13 -> V_18 . V_127 = V_77 ;
V_13 -> V_18 . V_19 . V_20 = & V_141 -> V_19 ;
F_68 ( V_13 ) ;
V_142 = F_74 ( & V_141 -> V_19 , & V_13 -> V_18 ) ;
if ( V_142 < 0 )
goto V_145;
V_142 = F_75 ( & V_13 -> V_18 . V_19 , & V_146 ) ;
if ( V_142 < 0 )
goto V_147;
F_76 ( V_141 , V_13 ) ;
return V_142 ;
V_147:
F_77 ( & V_13 -> V_18 ) ;
V_145:
return V_142 ;
}
static int F_78 ( struct V_140 * V_141 )
{
struct V_17 * V_13 = F_79 ( V_141 ) ;
F_80 ( & V_13 -> V_18 . V_19 , & V_146 ) ;
F_77 ( & V_13 -> V_18 ) ;
return 0 ;
}
static void F_81 ( struct V_17 * V_13 , struct V_9 * V_34 ,
int V_63 )
{
F_64 ( & V_13 -> V_30 ) ;
V_13 -> V_39 = V_63 ;
F_20 ( V_34 ) ;
F_65 ( & V_13 -> V_30 ) ;
}
static int F_82 ( struct V_140 * V_141 , T_3 V_148 )
{
struct V_17 * V_13 = F_79 ( V_141 ) ;
struct V_9 * V_34 = F_9 ( & V_13 -> V_18 ) ;
F_29 ( & V_141 -> V_19 , L_19 , V_149 ) ;
F_81 ( V_13 , V_34 , 1 ) ;
F_57 ( F_5 ( V_34 ) ) ;
return 0 ;
}
static int F_83 ( struct V_140 * V_141 )
{
struct V_17 * V_13 = F_79 ( V_141 ) ;
struct V_9 * V_34 = F_9 ( & V_13 -> V_18 ) ;
F_29 ( & V_141 -> V_19 , L_19 , V_149 ) ;
F_81 ( V_13 , V_34 , 0 ) ;
F_57 ( F_5 ( V_34 ) ) ;
return 0 ;
}
static unsigned int F_84 ( const struct V_65 * V_66 )
{
unsigned int V_150 ;
V_150 = F_85 ( V_66 ) << 1 ;
if ( F_86 ( V_66 ) )
V_150 |= 1 ;
return V_150 ;
}
static int F_87 ( struct V_9 * V_34 , struct V_151 * V_151 )
{
const struct V_65 * V_66 = & V_151 -> V_4 -> V_66 ;
T_4 V_150 ;
if ( ! F_27 ( V_66 ) )
return 0 ;
V_150 = F_84 ( V_66 ) ;
return ( 1 << V_150 ) & V_34 -> V_152 ;
}
static int F_88 ( struct V_9 * V_34 ,
unsigned int V_153 )
{
int V_136 ;
V_136 = V_34 -> V_154 [ F_89 ( V_153 ) ] ;
if ( F_90 ( V_153 ) )
V_136 >>= 4 ;
else
V_136 &= 0xf ;
V_136 ++ ;
return V_136 ;
}
static void F_91 ( struct V_9 * V_34 ,
unsigned int V_153 , unsigned int V_155 )
{
int V_136 ;
V_155 -- ;
V_136 = V_34 -> V_154 [ F_89 ( V_153 ) ] ;
if ( F_90 ( V_153 ) ) {
V_155 <<= 4 ;
V_136 &= 0xf ;
} else {
V_136 &= 0xf0 ;
}
V_136 |= V_155 ;
V_34 -> V_154 [ F_89 ( V_153 ) ] = V_136 ;
}
static int F_92 ( struct V_9 * V_34 , struct V_151 * V_151 )
{
unsigned int V_136 ;
int V_156 ;
V_156 = F_87 ( V_34 , V_151 ) ;
if ( ! V_151 -> V_157 ) {
if ( V_156 )
return - V_73 ;
return 0 ;
}
if ( ! V_156 )
return - V_73 ;
V_136 = F_88 ( V_34 ,
F_89 ( V_151 -> V_153 ) ) ;
if ( V_151 -> V_157 > V_136 ) {
F_28 ( F_6 ( V_34 ) , L_20 ,
V_151 -> V_157 ) ;
F_93 () ;
return - V_73 ;
}
return 0 ;
}
static int F_94 (
struct V_10 * V_11 ,
struct V_151 * V_151 ,
T_1 V_86
) {
struct V_9 * V_34 ;
struct V_158 * V_158 ;
unsigned long V_85 ;
int V_142 ;
V_158 = F_95 ( sizeof *V_158 , V_86 ) ;
if ( ! V_158 )
return - V_159 ;
V_158 -> V_151 = V_151 ;
V_158 -> V_160 = 0 ;
V_34 = F_4 ( V_11 ) ;
F_31 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
V_142 = F_92 ( V_34 , V_151 ) ;
if ( V_142 ) {
F_38 ( V_158 ) ;
goto V_75;
}
V_142 = F_96 ( V_11 , V_151 ) ;
if ( V_142 ) {
F_38 ( V_158 ) ;
goto V_75;
}
if ( ! V_34 -> V_161 ) {
V_34 -> V_161 = V_151 -> V_19 ;
F_97 ( V_34 -> V_161 ) ;
} else if ( F_98 ( V_34 -> V_161 != V_151 -> V_19 ) )
F_28 ( F_6 ( V_34 ) , L_21 ) ;
F_41 ( & V_158 -> V_162 , & V_34 -> V_162 ) ;
V_151 -> V_163 = V_158 ;
if ( ! V_34 -> V_164 )
V_34 -> V_164 = V_158 ;
if ( F_99 ( V_151 -> V_153 ) == V_165 )
V_151 -> V_166 = 1 ;
if ( ! F_100 ( & V_34 -> V_167 ) )
F_53 ( & V_34 -> V_167 , V_112 + 1 ) ;
V_75:
F_32 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
return V_142 ;
}
static int F_101 ( struct V_10 * V_11 , struct V_151 * V_151 , int V_28 )
{
struct V_9 * V_34 ;
unsigned long V_85 ;
int V_142 ;
V_34 = F_4 ( V_11 ) ;
F_31 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
V_142 = F_102 ( V_11 , V_151 , V_28 ) ;
if ( ! V_142 && V_34 -> V_47 != V_168 &&
! F_12 ( & V_34 -> V_162 ) )
F_53 ( & V_34 -> V_167 , V_112 ) ;
F_32 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
return V_142 ;
}
static int F_103 ( struct V_151 * V_151 , struct V_5 * V_8 ,
T_4 V_169 )
{
void * V_170 , * V_171 ;
struct V_158 * V_158 = V_151 -> V_163 ;
int V_172 ;
struct V_173 * V_174 = & V_158 -> V_174 ;
T_4 V_175 = 0 ;
T_4 V_176 ;
bool V_177 ;
V_172 = F_104 ( V_151 -> V_153 ) ;
V_171 = V_8 -> V_8 . V_95 + V_8 -> V_8 . V_89 ;
if ( ! V_151 -> V_178 ) {
V_170 = V_151 -> V_179 + V_151 -> V_180 ;
if ( V_172 )
memcpy ( V_170 , V_171 , V_169 ) ;
else
memcpy ( V_171 , V_170 , V_169 ) ;
return V_169 ;
}
if ( ! V_158 -> V_160 ) {
T_4 V_85 = V_181 ;
if ( V_172 )
V_85 |= V_182 ;
else
V_85 |= V_183 ;
F_105 ( V_174 , V_151 -> V_184 , V_151 -> V_178 , V_85 ) ;
V_158 -> V_160 = 1 ;
}
V_177 = F_106 ( V_174 ) ;
if ( V_177 == false ) {
F_107 ( 1 ) ;
return - V_73 ;
}
do {
V_170 = V_174 -> V_185 ;
V_176 = F_59 ( T_4 , V_169 , V_174 -> V_93 ) ;
V_174 -> V_186 = V_176 ;
V_175 += V_176 ;
if ( V_172 )
memcpy ( V_170 , V_171 , V_176 ) ;
else
memcpy ( V_171 , V_170 , V_176 ) ;
V_169 -= V_176 ;
if ( ! V_169 )
break;
V_177 = F_106 ( V_174 ) ;
if ( V_177 == false ) {
F_107 ( 1 ) ;
return - V_73 ;
}
V_171 += V_176 ;
} while ( 1 );
F_108 ( V_174 ) ;
return V_175 ;
}
static int F_109 ( struct V_9 * V_34 , struct V_151 * V_151 ,
struct V_1 * V_4 , int V_187 , int * V_28 )
{
struct V_17 * V_13 = V_34 -> V_13 ;
struct V_5 * V_8 ;
int V_188 = 0 ;
V_189:
F_44 (req, &ep->queue, queue) {
unsigned V_190 , V_191 , V_169 ;
int V_192 , V_172 ;
int V_193 = 0 ;
if ( F_87 ( V_34 , V_151 ) ) {
if ( ( V_151 -> V_157 != V_8 -> V_8 . V_157 ) )
continue;
}
V_190 = V_151 -> V_194 - V_151 -> V_180 ;
V_191 = V_8 -> V_8 . V_93 - V_8 -> V_8 . V_89 ;
V_169 = F_110 ( V_190 , V_191 ) ;
V_172 = F_104 ( V_151 -> V_153 ) ;
if ( F_98 ( V_169 == 0 ) )
V_192 = 1 ;
else {
if ( V_187 < V_4 -> V_4 . V_80 && V_187 < V_169 )
break;
V_169 = F_59 ( unsigned , V_169 , V_187 ) ;
if ( V_169 == 0 )
break;
if ( V_169 >= V_4 -> V_4 . V_80 ) {
V_192 = 0 ;
if ( V_169 % V_4 -> V_4 . V_80 )
V_193 = 1 ;
V_169 -= V_169 % V_4 -> V_4 . V_80 ;
} else {
V_192 = 1 ;
}
V_169 = F_103 ( V_151 , V_8 , V_169 ) ;
V_4 -> V_137 = V_112 ;
if ( ( int ) V_169 < 0 ) {
V_8 -> V_8 . V_28 = V_169 ;
} else {
V_187 -= V_169 ;
V_188 += V_169 ;
V_151 -> V_180 += V_169 ;
V_8 -> V_8 . V_89 += V_169 ;
}
}
if ( V_192 ) {
if ( V_190 == V_191 ) {
V_8 -> V_8 . V_28 = 0 ;
* V_28 = 0 ;
} else if ( V_172 ) {
V_8 -> V_8 . V_28 = 0 ;
if ( V_191 > V_190 )
* V_28 = - V_195 ;
else
* V_28 = 0 ;
} else {
* V_28 = 0 ;
if ( V_190 > V_191 )
V_8 -> V_8 . V_28 = - V_195 ;
else
V_8 -> V_8 . V_28 = 0 ;
}
} else {
if ( V_8 -> V_8 . V_93 == V_8 -> V_8 . V_89 ) {
if ( V_8 -> V_8 . V_196 && V_172 )
V_193 = 1 ;
else
V_8 -> V_8 . V_28 = 0 ;
}
if ( V_151 -> V_194 == V_151 -> V_180 ) {
if ( V_151 -> V_197 & V_198 &&
! V_172 )
V_193 = 1 ;
else
* V_28 = 0 ;
}
}
if ( V_8 -> V_8 . V_28 != - V_88 ) {
F_14 ( & V_8 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_16 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_17 ( & V_13 -> V_30 ) ;
V_193 = 1 ;
}
if ( * V_28 != - V_88 )
break;
if ( V_193 )
goto V_189;
}
return V_188 ;
}
static int F_111 ( struct V_17 * V_13 , struct V_1 * V_4 )
{
int V_187 = V_4 -> V_4 . V_80 ;
if ( V_13 -> V_18 . V_22 == V_76 ) {
int V_199 ;
V_199 = F_112 ( V_4 -> V_66 ) ;
V_199 *= 8 ;
V_187 += V_187 * V_199 ;
}
if ( V_13 -> V_18 . V_22 == V_23 ) {
switch ( F_25 ( V_4 -> V_66 ) ) {
case V_79 :
V_187 = 3 * 16 * 1024 * 8 ;
break;
case V_78 :
V_187 = 3 * 1024 * 8 ;
break;
case V_74 :
default:
break;
}
}
return V_187 ;
}
static struct V_1 * F_113 ( struct V_17 * V_13 , V_119 V_32 )
{
int V_31 ;
if ( ! F_114 ( ( V_13 -> V_18 . V_22 == V_23 ?
V_13 -> V_24 : V_13 -> V_25 ) ) )
return NULL ;
if ( ! V_13 -> V_59 )
return NULL ;
if ( ( V_32 & ~ V_91 ) == 0 )
return & V_13 -> V_4 [ 0 ] ;
for ( V_31 = 1 ; V_31 < V_33 ; V_31 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_31 ] ;
if ( ! V_4 -> V_66 )
continue;
if ( V_4 -> V_66 -> V_90 == V_32 )
return V_4 ;
}
return NULL ;
}
static int F_115 ( struct V_9 * V_34 , struct V_151 * V_151 ,
struct V_200 * V_201 ,
int * V_28 )
{
struct V_1 * V_202 ;
struct V_17 * V_13 = V_34 -> V_13 ;
int V_203 = 1 ;
unsigned V_204 ;
unsigned V_205 ;
V_204 = F_116 ( V_201 -> V_206 ) ;
V_205 = F_116 ( V_201 -> V_207 ) ;
switch ( V_201 -> V_208 ) {
case V_209 :
if ( V_201 -> V_210 != V_211 )
break;
V_13 -> V_32 = V_205 ;
* V_28 = 0 ;
F_29 ( F_7 ( V_13 ) , L_22 ,
V_205 ) ;
V_203 = 0 ;
break;
case V_212 :
if ( V_201 -> V_210 == V_211 ) {
V_203 = 0 ;
switch ( V_205 ) {
case V_108 :
break;
case V_107 :
V_13 -> V_18 . V_213 = 1 ;
break;
case V_214 :
V_13 -> V_18 . V_215 = 1 ;
break;
case V_216 :
V_13 -> V_18 . V_217 = 1 ;
break;
case V_218 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_205 = V_219 ;
else
V_203 = - V_220 ;
break;
case V_221 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_205 = V_222 ;
else
V_203 = - V_220 ;
break;
case V_223 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_205 = V_224 ;
else
V_203 = - V_220 ;
break;
default:
V_203 = - V_220 ;
}
if ( V_203 == 0 ) {
V_13 -> V_106 |= ( 1 << V_205 ) ;
* V_28 = 0 ;
}
} else if ( V_201 -> V_210 == V_225 ) {
V_202 = F_113 ( V_13 , V_204 ) ;
if ( ! V_202 || V_202 -> V_4 . V_69 == V_70 ) {
V_203 = - V_220 ;
break;
}
V_202 -> V_83 = 1 ;
V_203 = 0 ;
* V_28 = 0 ;
}
break;
case V_226 :
if ( V_201 -> V_210 == V_211 ) {
V_203 = 0 ;
switch ( V_205 ) {
case V_108 :
V_205 = V_108 ;
break;
case V_218 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_205 = V_219 ;
else
V_203 = - V_220 ;
break;
case V_221 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_205 = V_222 ;
else
V_203 = - V_220 ;
break;
case V_223 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_205 = V_224 ;
else
V_203 = - V_220 ;
break;
default:
V_203 = - V_220 ;
break;
}
if ( V_203 == 0 ) {
V_13 -> V_106 &= ~ ( 1 << V_205 ) ;
* V_28 = 0 ;
}
} else if ( V_201 -> V_210 == V_225 ) {
V_202 = F_113 ( V_13 , V_204 ) ;
if ( ! V_202 ) {
V_203 = - V_220 ;
break;
}
if ( ! V_202 -> V_84 )
V_202 -> V_83 = 0 ;
V_203 = 0 ;
* V_28 = 0 ;
}
break;
case V_227 :
if ( V_201 -> V_210 == V_228
|| V_201 -> V_210 == V_229
|| V_201 -> V_210 == V_230 ) {
char * V_95 ;
V_95 = ( char * ) V_151 -> V_179 ;
if ( V_151 -> V_194 > 0 ) {
if ( V_201 -> V_210 == V_230 ) {
V_202 = F_113 ( V_13 , V_204 ) ;
if ( ! V_202 ) {
V_203 = - V_220 ;
break;
}
V_95 [ 0 ] = V_202 -> V_83 ;
} else if ( V_201 -> V_210 ==
V_228 ) {
V_95 [ 0 ] = ( V_119 ) V_13 -> V_106 ;
} else
V_95 [ 0 ] = 0 ;
}
if ( V_151 -> V_194 > 1 )
V_95 [ 1 ] = 0 ;
V_151 -> V_180 = F_59 ( T_4 , 2 ,
V_151 -> V_194 ) ;
V_203 = 0 ;
* V_28 = 0 ;
}
break;
}
return V_203 ;
}
static void F_117 ( unsigned long V_231 )
{
struct V_9 * V_34 = (struct V_9 * ) V_231 ;
struct V_17 * V_13 = V_34 -> V_13 ;
struct V_158 * V_158 , * V_199 ;
unsigned long V_85 ;
int V_187 , V_232 ;
int V_31 ;
switch ( V_13 -> V_18 . V_22 ) {
case V_233 :
V_232 = 8 * 12 ;
break;
case V_77 :
V_232 = 64 * 19 ;
break;
case V_76 :
V_232 = 512 * 13 * 8 ;
break;
case V_23 :
V_232 = 490000 ;
break;
default:
F_28 ( F_6 ( V_34 ) , L_23 ) ;
return;
}
F_31 ( & V_13 -> V_30 , V_85 ) ;
if ( ! V_34 -> V_161 ) {
F_28 ( F_6 ( V_34 ) ,
L_24 ) ;
F_32 ( & V_13 -> V_30 , V_85 ) ;
return;
}
V_34 -> V_164 = NULL ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
if ( ! V_130 [ V_31 ] . V_69 )
break;
V_13 -> V_4 [ V_31 ] . V_134 = 0 ;
}
V_234:
F_118 (urbp, tmp, &dum_hcd->urbp_list, urbp_list) {
struct V_151 * V_151 ;
struct V_5 * V_8 ;
V_119 V_32 ;
struct V_1 * V_4 = NULL ;
int type ;
int V_28 = - V_88 ;
if ( V_158 == V_34 -> V_164 )
break;
V_151 = V_158 -> V_151 ;
if ( V_151 -> V_235 )
goto V_236;
else if ( V_34 -> V_47 != V_168 )
continue;
type = F_99 ( V_151 -> V_153 ) ;
if ( V_232 <= 0 && type == V_237 )
continue;
V_32 = F_89 ( V_151 -> V_153 ) ;
if ( F_104 ( V_151 -> V_153 ) )
V_32 |= V_91 ;
V_4 = F_113 ( V_13 , V_32 ) ;
if ( ! V_4 ) {
F_29 ( F_6 ( V_34 ) ,
L_25 ,
V_151 ) ;
V_28 = - V_238 ;
goto V_236;
}
if ( V_4 -> V_134 )
continue;
V_4 -> V_134 = 1 ;
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_151 -> V_166 ) {
V_4 -> V_135 = 1 ;
V_151 -> V_166 = 0 ;
}
if ( V_4 -> V_83 && ! V_4 -> V_135 ) {
F_29 ( F_6 ( V_34 ) , L_26 ,
V_4 -> V_4 . V_69 , V_151 ) ;
V_28 = - V_239 ;
goto V_236;
}
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_4 -> V_135 ) {
struct V_200 V_201 ;
int V_99 = 1 ;
V_201 = * (struct V_200 * ) V_151 -> V_240 ;
F_44 (req, &ep->queue, queue) {
F_14 ( & V_8 -> V_26 ) ;
V_8 -> V_8 . V_28 = - V_195 ;
F_29 ( F_7 ( V_13 ) , L_27 ,
V_8 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_16 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_17 ( & V_13 -> V_30 ) ;
V_4 -> V_134 = 0 ;
goto V_234;
}
V_4 -> V_137 = V_112 ;
V_4 -> V_135 = 0 ;
V_4 -> V_83 = 0 ;
V_99 = F_115 ( V_34 , V_151 , & V_201 ,
& V_28 ) ;
if ( V_99 > 0 ) {
++ V_13 -> V_60 ;
F_15 ( & V_13 -> V_30 ) ;
V_99 = V_13 -> V_61 -> V_201 ( & V_13 -> V_18 ,
& V_201 ) ;
F_17 ( & V_13 -> V_30 ) ;
-- V_13 -> V_60 ;
if ( V_99 >= 0 ) {
V_187 = 64 * 1024 ;
goto V_241;
}
}
if ( V_99 < 0 ) {
if ( V_99 != - V_220 )
F_29 ( F_7 ( V_13 ) ,
L_28 ,
V_99 ) ;
V_28 = - V_239 ;
V_151 -> V_180 = 0 ;
}
goto V_236;
}
V_187 = V_232 ;
switch ( F_99 ( V_151 -> V_153 ) ) {
case V_242 :
V_187 = V_67 ( V_187 , F_111 ( V_13 , V_4 ) ) ;
V_28 = - V_243 ;
break;
case V_244 :
V_187 = V_67 ( V_187 , F_111 ( V_13 , V_4 ) ) ;
default:
V_241:
V_4 -> V_137 = V_112 ;
V_232 -= F_109 ( V_34 , V_151 , V_4 , V_187 , & V_28 ) ;
break;
}
if ( V_28 == - V_88 )
continue;
V_236:
F_119 ( & V_158 -> V_162 ) ;
F_38 ( V_158 ) ;
if ( V_4 )
V_4 -> V_134 = V_4 -> V_135 = 0 ;
F_120 ( F_5 ( V_34 ) , V_151 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_121 ( F_5 ( V_34 ) , V_151 , V_28 ) ;
F_17 ( & V_13 -> V_30 ) ;
goto V_234;
}
if ( F_12 ( & V_34 -> V_162 ) ) {
F_122 ( V_34 -> V_161 ) ;
V_34 -> V_161 = NULL ;
} else if ( V_34 -> V_47 == V_168 ) {
F_53 ( & V_34 -> V_167 , V_112 + F_52 ( 1 ) ) ;
}
F_32 ( & V_13 -> V_30 , V_85 ) ;
}
static int F_123 ( struct V_10 * V_11 , char * V_95 )
{
struct V_9 * V_34 ;
unsigned long V_85 ;
int V_68 = 0 ;
V_34 = F_4 ( V_11 ) ;
F_31 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
if ( ! F_124 ( V_11 ) )
goto V_75;
if ( V_34 -> V_55 && F_125 ( V_112 , V_34 -> V_111 ) ) {
V_34 -> V_36 |= ( V_245 << 16 ) ;
V_34 -> V_36 &= ~ V_53 ;
F_20 ( V_34 ) ;
}
if ( ( V_34 -> V_36 & V_246 ) != 0 ) {
* V_95 = ( 1 << 1 ) ;
F_29 ( F_6 ( V_34 ) , L_29 ,
V_34 -> V_36 ) ;
V_68 = 1 ;
if ( V_34 -> V_47 == V_48 )
F_126 ( V_11 ) ;
}
V_75:
F_32 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
return V_68 ;
}
static inline void
F_127 ( struct V_247 * V_66 )
{
memset ( V_66 , 0 , sizeof *V_66 ) ;
V_66 -> V_71 = V_248 ;
V_66 -> V_249 = 12 ;
V_66 -> V_250 = F_128 (
V_251 |
V_252 ) ;
V_66 -> V_253 = 1 ;
V_66 -> V_254 . V_255 . V_256 = 0x04 ;
V_66 -> V_254 . V_255 . V_257 = 0 ;
}
static inline void F_129 ( struct V_247 * V_66 )
{
memset ( V_66 , 0 , sizeof *V_66 ) ;
V_66 -> V_71 = V_258 ;
V_66 -> V_249 = 9 ;
V_66 -> V_250 = F_128 (
V_251 |
V_252 ) ;
V_66 -> V_253 = 1 ;
V_66 -> V_254 . V_259 . V_257 [ 0 ] = 0 ;
V_66 -> V_254 . V_259 . V_257 [ 1 ] = 0xff ;
}
static int F_130 (
struct V_10 * V_11 ,
T_5 V_260 ,
T_5 V_207 ,
T_5 V_206 ,
char * V_95 ,
T_5 V_261
) {
struct V_9 * V_34 ;
int V_68 = 0 ;
unsigned long V_85 ;
if ( ! F_124 ( V_11 ) )
return - V_262 ;
V_34 = F_4 ( V_11 ) ;
F_31 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
switch ( V_260 ) {
case V_263 :
break;
case V_264 :
switch ( V_207 ) {
case V_265 :
if ( V_11 -> V_22 == V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_30
L_31 ) ;
goto error;
}
if ( V_34 -> V_36 & V_53 ) {
V_34 -> V_55 = 1 ;
V_34 -> V_111 = V_112 +
F_52 ( 20 ) ;
}
break;
case V_266 :
F_29 ( F_6 ( V_34 ) , L_32 ) ;
if ( V_11 -> V_22 == V_35 )
V_34 -> V_36 &= ~ V_37 ;
else
V_34 -> V_36 &= ~ V_50 ;
F_20 ( V_34 ) ;
break;
default:
V_34 -> V_36 &= ~ ( 1 << V_207 ) ;
F_20 ( V_34 ) ;
}
break;
case V_267 :
if ( V_11 -> V_22 == V_35 &&
( V_261 < V_268 ||
V_207 != ( V_248 << 8 ) ) ) {
F_29 ( F_6 ( V_34 ) ,
L_33
L_34 ) ;
goto error;
}
if ( V_11 -> V_22 == V_35 )
F_127 ( (struct V_247 * ) V_95 ) ;
else
F_129 ( (struct V_247 * ) V_95 ) ;
break;
case V_269 | V_270 :
if ( V_11 -> V_22 != V_35 )
goto error;
if ( ( V_207 >> 8 ) != V_271 )
goto error;
memcpy ( V_95 , & V_272 , sizeof( V_272 ) ) ;
V_68 = sizeof( V_272 ) ;
break;
case V_273 :
* ( V_274 * ) V_95 = F_131 ( 0 ) ;
break;
case V_275 :
if ( V_206 != 1 )
V_68 = - V_239 ;
if ( V_34 -> V_55 &&
F_125 ( V_112 , V_34 -> V_111 ) ) {
V_34 -> V_36 |= ( V_245 << 16 ) ;
V_34 -> V_36 &= ~ V_53 ;
}
if ( ( V_34 -> V_36 & V_56 ) != 0 &&
F_125 ( V_112 , V_34 -> V_111 ) ) {
V_34 -> V_36 |= ( V_276 << 16 ) ;
V_34 -> V_36 &= ~ V_56 ;
if ( V_34 -> V_13 -> V_38 ) {
V_34 -> V_36 |= V_41 ;
if ( V_11 -> V_22 < V_35 ) {
switch ( V_34 -> V_13 -> V_18 . V_22 ) {
case V_76 :
V_34 -> V_36 |=
V_52 ;
break;
case V_233 :
V_34 -> V_13 -> V_18 . V_138 ->
V_80 = 8 ;
V_34 -> V_36 |=
V_51 ;
break;
default:
V_34 -> V_13 -> V_18 . V_22 =
V_77 ;
break;
}
}
}
}
F_20 ( V_34 ) ;
( ( V_277 * ) V_95 ) [ 0 ] = F_128 ( V_34 -> V_36 ) ;
( ( V_277 * ) V_95 ) [ 1 ] = F_128 ( V_34 -> V_36 >> 16 ) ;
break;
case V_278 :
V_68 = - V_239 ;
break;
case V_279 :
switch ( V_207 ) {
case V_280 :
if ( V_11 -> V_22 != V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_35
L_36 ) ;
goto error;
}
break;
case V_281 :
case V_282 :
if ( V_11 -> V_22 != V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_37
L_36 ) ;
goto error;
}
break;
case V_265 :
if ( V_11 -> V_22 == V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_30
L_31 ) ;
goto error;
}
if ( V_34 -> V_49 ) {
V_34 -> V_36 |= V_53 ;
F_20 ( V_34 ) ;
if ( ( ( 1 << V_107 )
& V_34 -> V_13 -> V_106 ) != 0 )
F_29 ( F_6 ( V_34 ) ,
L_38 ) ;
}
break;
case V_266 :
if ( V_11 -> V_22 == V_35 )
V_34 -> V_36 |= V_37 ;
else
V_34 -> V_36 |= V_50 ;
F_20 ( V_34 ) ;
break;
case V_283 :
if ( V_11 -> V_22 != V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_39
L_36 ) ;
goto error;
}
case V_284 :
if ( V_11 -> V_22 == V_35 ) {
V_34 -> V_36 = 0 ;
V_34 -> V_36 =
( V_37 |
V_40 |
V_56 ) ;
} else
V_34 -> V_36 &= ~ ( V_41
| V_51
| V_52 ) ;
V_34 -> V_13 -> V_106 &=
( 1 << V_115 ) ;
V_34 -> V_111 = V_112 + F_52 ( 50 ) ;
default:
if ( V_11 -> V_22 == V_35 ) {
if ( ( V_34 -> V_36 &
V_37 ) != 0 ) {
V_34 -> V_36 |= ( 1 << V_207 ) ;
}
} else
if ( ( V_34 -> V_36 &
V_50 ) != 0 ) {
V_34 -> V_36 |= ( 1 << V_207 ) ;
}
F_20 ( V_34 ) ;
}
break;
case V_285 :
if ( V_11 -> V_22 != V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_40
L_36 ) ;
goto error;
}
* ( V_274 * ) V_95 = F_131 ( 0 ) ;
break;
case V_286 :
if ( V_11 -> V_22 != V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_41
L_42 ) ;
goto error;
}
break;
default:
F_29 ( F_6 ( V_34 ) ,
L_43 ,
V_260 , V_207 , V_206 , V_261 ) ;
error:
V_68 = - V_239 ;
}
F_32 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
if ( ( V_34 -> V_36 & V_246 ) != 0 )
F_57 ( V_11 ) ;
return V_68 ;
}
static int F_132 ( struct V_10 * V_11 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
F_29 ( & V_11 -> V_15 . V_287 -> V_19 , L_19 , V_149 ) ;
F_64 ( & V_34 -> V_13 -> V_30 ) ;
V_34 -> V_47 = V_48 ;
F_20 ( V_34 ) ;
V_11 -> V_148 = V_288 ;
F_65 ( & V_34 -> V_13 -> V_30 ) ;
return 0 ;
}
static int F_133 ( struct V_10 * V_11 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
int V_142 = 0 ;
F_29 ( & V_11 -> V_15 . V_287 -> V_19 , L_19 , V_149 ) ;
F_64 ( & V_34 -> V_13 -> V_30 ) ;
if ( ! F_124 ( V_11 ) ) {
V_142 = - V_29 ;
} else {
V_34 -> V_47 = V_168 ;
F_20 ( V_34 ) ;
if ( ! F_12 ( & V_34 -> V_162 ) )
F_53 ( & V_34 -> V_167 , V_112 ) ;
V_11 -> V_148 = V_289 ;
}
F_65 ( & V_34 -> V_13 -> V_30 ) ;
return V_142 ;
}
static inline T_2 F_134 ( char * V_95 , T_6 V_290 , struct V_151 * V_151 )
{
int V_4 = F_89 ( V_151 -> V_153 ) ;
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
static T_2 F_135 ( struct V_14 * V_19 , struct V_121 * V_122 ,
char * V_95 )
{
struct V_10 * V_11 = F_136 ( V_19 ) ;
struct V_9 * V_34 = F_4 ( V_11 ) ;
struct V_158 * V_158 ;
T_6 V_290 = 0 ;
unsigned long V_85 ;
F_31 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
F_44 (urbp, &dum_hcd->urbp_list, urbp_list) {
T_6 V_291 ;
V_291 = F_134 ( V_95 , V_124 - V_290 , V_158 -> V_151 ) ;
V_95 += V_291 ;
V_290 += V_291 ;
}
F_32 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
return V_290 ;
}
static int F_137 ( struct V_9 * V_34 )
{
F_138 ( & V_34 -> V_167 ) ;
V_34 -> V_167 . V_123 = F_117 ;
V_34 -> V_167 . V_292 = ( unsigned long ) V_34 ;
V_34 -> V_47 = V_168 ;
V_34 -> V_152 = 0 ;
F_35 ( & V_34 -> V_162 ) ;
F_5 ( V_34 ) -> V_293 = V_294 ;
F_5 ( V_34 ) -> V_148 = V_289 ;
F_5 ( V_34 ) -> V_295 = 1 ;
#ifdef F_70
F_5 ( V_34 ) -> V_15 . V_296 = 1 ;
#endif
return 0 ;
return F_75 ( F_6 ( V_34 ) , & V_297 ) ;
}
static int F_139 ( struct V_10 * V_11 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
if ( ! F_140 ( V_11 ) )
return F_137 ( V_34 ) ;
F_141 ( & V_34 -> V_13 -> V_30 ) ;
F_138 ( & V_34 -> V_167 ) ;
V_34 -> V_167 . V_123 = F_117 ;
V_34 -> V_167 . V_292 = ( unsigned long ) V_34 ;
V_34 -> V_47 = V_168 ;
F_35 ( & V_34 -> V_162 ) ;
V_11 -> V_293 = V_294 ;
V_11 -> V_148 = V_289 ;
V_11 -> V_295 = 1 ;
#ifdef F_70
V_11 -> V_15 . V_296 = 1 ;
#endif
return F_75 ( F_6 ( V_34 ) , & V_297 ) ;
}
static void F_142 ( struct V_10 * V_11 )
{
F_80 ( F_6 ( F_4 ( V_11 ) ) , & V_297 ) ;
F_143 ( F_6 ( F_4 ( V_11 ) ) , L_51 ) ;
}
static int F_144 ( struct V_10 * V_11 )
{
return F_49 ( NULL ) ;
}
static int F_145 ( struct V_10 * V_11 )
{
struct V_17 * V_13 ;
V_13 = * ( ( void * * ) F_72 ( V_11 -> V_15 . V_16 ) ) ;
V_11 -> V_15 . V_298 = ~ 0 ;
if ( F_140 ( V_11 ) ) {
V_13 -> V_25 = F_4 ( V_11 ) ;
V_13 -> V_25 -> V_13 = V_13 ;
V_11 -> V_22 = V_299 ;
V_11 -> V_15 . V_287 -> V_22 = V_76 ;
} else {
V_13 -> V_24 = F_4 ( V_11 ) ;
V_13 -> V_24 -> V_13 = V_13 ;
V_11 -> V_22 = V_35 ;
V_11 -> V_15 . V_287 -> V_22 = V_23 ;
}
return 0 ;
}
static int F_146 ( struct V_10 * V_11 , struct V_300 * V_161 ,
struct V_301 * * V_302 , unsigned int V_303 ,
unsigned int V_304 , T_1 V_86 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
unsigned long V_85 ;
int V_305 ;
int V_306 = V_304 ;
unsigned int V_150 ;
unsigned int V_31 ;
if ( ! V_303 )
return - V_73 ;
F_31 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
for ( V_31 = 0 ; V_31 < V_303 ; V_31 ++ ) {
V_150 = F_84 ( & V_302 [ V_31 ] -> V_66 ) ;
if ( ( 1 << V_150 ) & V_34 -> V_152 ) {
V_306 = - V_73 ;
goto V_307;
}
V_305 = F_26 ( & V_302 [ V_31 ] -> V_308 ) ;
if ( ! V_305 ) {
V_306 = - V_73 ;
goto V_307;
}
if ( V_305 < V_306 ) {
F_29 ( F_6 ( V_34 ) , L_52
L_53 ,
V_302 [ V_31 ] -> V_66 . V_90 ,
V_305 ) ;
V_306 = V_305 ;
}
}
for ( V_31 = 0 ; V_31 < V_303 ; V_31 ++ ) {
V_150 = F_84 ( & V_302 [ V_31 ] -> V_66 ) ;
V_34 -> V_152 |= 1 << V_150 ;
F_91 ( V_34 ,
F_85 ( & V_302 [ V_31 ] -> V_66 ) , V_306 ) ;
}
V_307:
F_32 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
return V_306 ;
}
static int F_147 ( struct V_10 * V_11 , struct V_300 * V_161 ,
struct V_301 * * V_302 , unsigned int V_303 ,
T_1 V_86 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
unsigned long V_85 ;
int V_309 ;
unsigned int V_150 ;
unsigned int V_31 ;
F_31 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
for ( V_31 = 0 ; V_31 < V_303 ; V_31 ++ ) {
V_150 = F_84 ( & V_302 [ V_31 ] -> V_66 ) ;
if ( ! ( ( 1 << V_150 ) & V_34 -> V_152 ) ) {
V_309 = - V_73 ;
goto V_307;
}
}
for ( V_31 = 0 ; V_31 < V_303 ; V_31 ++ ) {
V_150 = F_84 ( & V_302 [ V_31 ] -> V_66 ) ;
V_34 -> V_152 &= ~ ( 1 << V_150 ) ;
F_91 ( V_34 ,
F_85 ( & V_302 [ V_31 ] -> V_66 ) , 0 ) ;
}
V_309 = 0 ;
V_307:
F_32 ( & V_34 -> V_13 -> V_30 , V_85 ) ;
return V_309 ;
}
static int F_148 ( struct V_140 * V_141 )
{
struct V_17 * V_13 ;
struct V_10 * V_25 ;
struct V_10 * V_24 ;
int V_68 ;
F_143 ( & V_141 -> V_19 , L_54 V_310 L_55 , V_311 ) ;
V_13 = * ( ( void * * ) F_72 ( & V_141 -> V_19 ) ) ;
if ( V_117 . V_118 )
V_9 . V_85 = V_35 | V_312 ;
else if ( V_117 . V_120 )
V_9 . V_85 = V_299 ;
else
V_9 . V_85 = V_313 ;
V_25 = F_149 ( & V_9 , & V_141 -> V_19 , F_150 ( & V_141 -> V_19 ) ) ;
if ( ! V_25 )
return - V_159 ;
V_25 -> V_314 = 1 ;
V_68 = F_151 ( V_25 , 0 , 0 ) ;
if ( V_68 )
goto V_315;
if ( V_117 . V_118 ) {
V_24 = F_152 ( & V_9 , & V_141 -> V_19 ,
F_150 ( & V_141 -> V_19 ) , V_25 ) ;
if ( ! V_24 ) {
V_68 = - V_159 ;
goto V_316;
}
V_68 = F_151 ( V_24 , 0 , 0 ) ;
if ( V_68 )
goto V_317;
}
return 0 ;
V_317:
F_153 ( V_24 ) ;
V_316:
F_154 ( V_25 ) ;
V_315:
F_153 ( V_25 ) ;
V_13 -> V_25 = V_13 -> V_24 = NULL ;
return V_68 ;
}
static int F_155 ( struct V_140 * V_141 )
{
struct V_17 * V_13 ;
V_13 = F_4 ( F_79 ( V_141 ) ) -> V_13 ;
if ( V_13 -> V_24 ) {
F_154 ( F_5 ( V_13 -> V_24 ) ) ;
F_153 ( F_5 ( V_13 -> V_24 ) ) ;
}
F_154 ( F_5 ( V_13 -> V_25 ) ) ;
F_153 ( F_5 ( V_13 -> V_25 ) ) ;
V_13 -> V_25 = NULL ;
V_13 -> V_24 = NULL ;
return 0 ;
}
static int F_156 ( struct V_140 * V_141 , T_3 V_148 )
{
struct V_10 * V_11 ;
struct V_9 * V_34 ;
int V_142 = 0 ;
F_29 ( & V_141 -> V_19 , L_19 , V_149 ) ;
V_11 = F_79 ( V_141 ) ;
V_34 = F_4 ( V_11 ) ;
if ( V_34 -> V_47 == V_168 ) {
F_157 ( & V_141 -> V_19 , L_56 ) ;
V_142 = - V_318 ;
} else
F_158 ( V_319 , & V_11 -> V_85 ) ;
return V_142 ;
}
static int F_159 ( struct V_140 * V_141 )
{
struct V_10 * V_11 ;
F_29 ( & V_141 -> V_19 , L_19 , V_149 ) ;
V_11 = F_79 ( V_141 ) ;
F_160 ( V_319 , & V_11 -> V_85 ) ;
F_57 ( V_11 ) ;
return 0 ;
}
static int T_7 F_161 ( void )
{
int V_68 = - V_159 ;
int V_31 ;
struct V_17 * V_13 [ V_320 ] ;
if ( F_162 () )
return - V_321 ;
if ( ! V_117 . V_120 && V_117 . V_118 )
return - V_73 ;
if ( V_117 . V_322 < 1 || V_117 . V_322 > V_320 ) {
F_163 ( L_57 ,
V_320 ) ;
return - V_73 ;
}
for ( V_31 = 0 ; V_31 < V_117 . V_322 ; V_31 ++ ) {
V_323 [ V_31 ] = F_164 ( V_324 , V_31 ) ;
if ( ! V_323 [ V_31 ] ) {
V_31 -- ;
while ( V_31 >= 0 )
F_165 ( V_323 [ V_31 -- ] ) ;
return V_68 ;
}
}
for ( V_31 = 0 ; V_31 < V_117 . V_322 ; V_31 ++ ) {
V_325 [ V_31 ] = F_164 ( V_143 , V_31 ) ;
if ( ! V_325 [ V_31 ] ) {
V_31 -- ;
while ( V_31 >= 0 )
F_165 ( V_325 [ V_31 -- ] ) ;
goto V_326;
}
}
for ( V_31 = 0 ; V_31 < V_117 . V_322 ; V_31 ++ ) {
V_13 [ V_31 ] = F_34 ( sizeof( struct V_17 ) , V_327 ) ;
if ( ! V_13 [ V_31 ] ) {
V_68 = - V_159 ;
goto V_328;
}
V_68 = F_166 ( V_323 [ V_31 ] , & V_13 [ V_31 ] ,
sizeof( void * ) ) ;
if ( V_68 )
goto V_328;
V_68 = F_166 ( V_325 [ V_31 ] , & V_13 [ V_31 ] ,
sizeof( void * ) ) ;
if ( V_68 )
goto V_328;
}
V_68 = F_167 ( & V_329 ) ;
if ( V_68 < 0 )
goto V_328;
V_68 = F_167 ( & V_330 ) ;
if ( V_68 < 0 )
goto V_331;
for ( V_31 = 0 ; V_31 < V_117 . V_322 ; V_31 ++ ) {
V_68 = F_168 ( V_323 [ V_31 ] ) ;
if ( V_68 < 0 ) {
V_31 -- ;
while ( V_31 >= 0 )
F_169 ( V_323 [ V_31 -- ] ) ;
goto V_332;
}
}
for ( V_31 = 0 ; V_31 < V_117 . V_322 ; V_31 ++ ) {
if ( ! V_13 [ V_31 ] -> V_25 ||
( ! V_13 [ V_31 ] -> V_24 && V_117 . V_118 ) ) {
V_68 = - V_73 ;
goto V_333;
}
}
for ( V_31 = 0 ; V_31 < V_117 . V_322 ; V_31 ++ ) {
V_68 = F_168 ( V_325 [ V_31 ] ) ;
if ( V_68 < 0 ) {
V_31 -- ;
while ( V_31 >= 0 )
F_169 ( V_325 [ V_31 -- ] ) ;
goto V_333;
}
}
for ( V_31 = 0 ; V_31 < V_117 . V_322 ; V_31 ++ ) {
if ( ! F_79 ( V_325 [ V_31 ] ) ) {
V_68 = - V_73 ;
goto V_334;
}
}
return V_68 ;
V_334:
for ( V_31 = 0 ; V_31 < V_117 . V_322 ; V_31 ++ )
F_169 ( V_325 [ V_31 ] ) ;
V_333:
for ( V_31 = 0 ; V_31 < V_117 . V_322 ; V_31 ++ )
F_169 ( V_323 [ V_31 ] ) ;
V_332:
F_170 ( & V_330 ) ;
V_331:
F_170 ( & V_329 ) ;
V_328:
for ( V_31 = 0 ; V_31 < V_117 . V_322 ; V_31 ++ )
F_38 ( V_13 [ V_31 ] ) ;
for ( V_31 = 0 ; V_31 < V_117 . V_322 ; V_31 ++ )
F_165 ( V_325 [ V_31 ] ) ;
V_326:
for ( V_31 = 0 ; V_31 < V_117 . V_322 ; V_31 ++ )
F_165 ( V_323 [ V_31 ] ) ;
return V_68 ;
}
static void T_8 F_171 ( void )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_117 . V_322 ; V_31 ++ ) {
struct V_17 * V_13 ;
V_13 = * ( ( void * * ) F_72 ( & V_325 [ V_31 ] -> V_19 ) ) ;
F_172 ( V_325 [ V_31 ] ) ;
F_172 ( V_323 [ V_31 ] ) ;
F_38 ( V_13 ) ;
}
F_170 ( & V_330 ) ;
F_170 ( & V_329 ) ;
}
