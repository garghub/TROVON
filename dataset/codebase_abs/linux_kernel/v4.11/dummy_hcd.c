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
if ( ( V_34 -> V_36 &
V_41 ) == 1 &&
( V_34 -> V_36 &
V_45 ) == 1 &&
V_34 -> V_46 != V_47 )
V_34 -> V_48 = 1 ;
}
} else {
if ( ( V_34 -> V_36 & V_49 ) == 0 ) {
V_34 -> V_36 = 0 ;
} else if ( ! V_13 -> V_38 || V_13 -> V_39 ) {
V_34 -> V_36 &= ~ ( V_40 |
V_41 |
V_50 |
V_51 |
V_52 ) ;
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
V_34 -> V_36 &= ~ V_52 ;
else if ( ( V_34 -> V_36 &
V_52 ) == 0 &&
V_34 -> V_46 != V_47 )
V_34 -> V_48 = 1 ;
}
}
}
static void F_20 ( struct V_9 * V_34 )
{
struct V_17 * V_13 = V_34 -> V_13 ;
V_34 -> V_48 = 0 ;
if ( V_13 -> V_38 )
if ( ( F_5 ( V_34 ) -> V_22 == V_35 &&
V_13 -> V_18 . V_22 != V_23 ) ||
( F_5 ( V_34 ) -> V_22 != V_35 &&
V_13 -> V_18 . V_22 == V_23 ) )
return;
F_19 ( V_34 ) ;
if ( ( V_34 -> V_36 & V_41 ) == 0 ||
V_34 -> V_48 )
V_34 -> V_53 = 0 ;
if ( ( V_34 -> V_36 & V_40 ) == 0 ||
( V_34 -> V_36 & V_54 ) != 0 ) {
unsigned V_55 = V_40 &
V_34 -> V_42 & ( ~ V_34 -> V_36 ) ;
unsigned V_56 = V_54 &
( ~ V_34 -> V_42 ) & V_34 -> V_36 ;
if ( V_13 -> V_57 && ( V_55 || V_56 ) ) {
F_18 ( V_13 ) ;
F_15 ( & V_13 -> V_30 ) ;
if ( V_56 )
F_21 ( & V_13 -> V_18 , V_13 -> V_57 ) ;
else
V_13 -> V_57 -> V_55 ( & V_13 -> V_18 ) ;
F_17 ( & V_13 -> V_30 ) ;
}
} else if ( V_34 -> V_48 != V_34 -> V_58 ) {
if ( V_34 -> V_58 && V_13 -> V_57 -> V_59 ) {
F_15 ( & V_13 -> V_30 ) ;
V_13 -> V_57 -> V_59 ( & V_13 -> V_18 ) ;
F_17 ( & V_13 -> V_30 ) ;
} else if ( ! V_34 -> V_58 && V_13 -> V_57 -> V_60 ) {
F_15 ( & V_13 -> V_30 ) ;
V_13 -> V_57 -> V_60 ( & V_13 -> V_18 ) ;
F_17 ( & V_13 -> V_30 ) ;
}
}
V_34 -> V_42 = V_34 -> V_36 ;
V_34 -> V_58 = V_34 -> V_48 ;
}
static int F_22 ( struct V_2 * V_3 ,
const struct V_61 * V_62 )
{
struct V_17 * V_13 ;
struct V_9 * V_34 ;
struct V_1 * V_4 ;
unsigned V_63 ;
int V_64 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_62 || V_4 -> V_62 || V_3 -> V_65 == V_66
|| V_62 -> V_67 != V_68 )
return - V_69 ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_57 )
return - V_29 ;
V_34 = F_9 ( & V_13 -> V_18 ) ;
if ( ! F_23 ( V_34 ) )
return - V_29 ;
V_63 = F_24 ( V_62 ) ;
V_64 = - V_69 ;
switch ( F_25 ( V_62 ) ) {
case V_70 :
if ( strstr ( V_4 -> V_4 . V_65 , L_1 )
|| strstr ( V_4 -> V_4 . V_65 , L_2 ) ) {
goto V_71;
}
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
if ( V_63 == 1024 )
break;
goto V_71;
case V_72 :
if ( V_63 == 512 )
break;
goto V_71;
case V_73 :
if ( V_63 == 8 || V_63 == 16 || V_63 == 32 || V_63 == 64 )
break;
default:
goto V_71;
}
break;
case V_74 :
if ( strstr ( V_4 -> V_4 . V_65 , L_1 ) )
goto V_71;
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
case V_72 :
if ( V_63 <= 1024 )
break;
case V_73 :
if ( V_63 <= 64 )
break;
default:
if ( V_63 <= 8 )
break;
goto V_71;
}
break;
case V_75 :
if ( strstr ( V_4 -> V_4 . V_65 , L_3 )
|| strstr ( V_4 -> V_4 . V_65 , L_2 ) )
goto V_71;
switch ( V_13 -> V_18 . V_22 ) {
case V_23 :
case V_72 :
if ( V_63 <= 1024 )
break;
case V_73 :
if ( V_63 <= 1023 )
break;
default:
goto V_71;
}
break;
default:
goto V_71;
}
V_3 -> V_76 = V_63 ;
if ( F_26 ( V_3 -> V_77 ) ) {
if ( ! F_27 ( V_62 ) ) {
F_28 ( F_7 ( V_13 ) , L_4
L_5 , V_3 -> V_65 ) ;
return - V_69 ;
}
V_4 -> V_78 = 1 ;
}
V_4 -> V_62 = V_62 ;
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
V_4 -> V_79 = V_4 -> V_80 = 0 ;
V_64 = 0 ;
V_71:
return V_64 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
unsigned long V_81 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_4 -> V_62 || V_3 -> V_65 == V_66 )
return - V_69 ;
V_13 = F_8 ( V_4 ) ;
F_31 ( & V_13 -> V_30 , V_81 ) ;
V_4 -> V_62 = NULL ;
V_4 -> V_78 = 0 ;
F_11 ( V_13 , V_4 ) ;
F_32 ( & V_13 -> V_30 , V_81 ) ;
F_29 ( F_7 ( V_13 ) , L_15 , V_3 -> V_65 ) ;
return 0 ;
}
static struct V_6 * F_33 ( struct V_2 * V_3 ,
T_1 V_82 )
{
struct V_5 * V_8 ;
if ( ! V_3 )
return NULL ;
V_8 = F_34 ( sizeof( * V_8 ) , V_82 ) ;
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
T_1 V_82 )
{
struct V_1 * V_4 ;
struct V_5 * V_8 ;
struct V_17 * V_13 ;
struct V_9 * V_34 ;
unsigned long V_81 ;
V_8 = F_3 ( V_7 ) ;
if ( ! V_7 || ! F_12 ( & V_8 -> V_26 ) || ! V_7 -> V_83 )
return - V_69 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ( ! V_4 -> V_62 && V_3 -> V_65 != V_66 ) )
return - V_69 ;
V_13 = F_8 ( V_4 ) ;
V_34 = F_9 ( & V_13 -> V_18 ) ;
if ( ! V_13 -> V_57 || ! F_23 ( V_34 ) )
return - V_29 ;
#if 0
dev_dbg(udc_dev(dum), "ep %p queue req %p to %s, len %d buf %p\n",
ep, _req, _ep->name, _req->length, _req->buf);
#endif
V_7 -> V_28 = - V_84 ;
V_7 -> V_85 = 0 ;
F_31 ( & V_13 -> V_30 , V_81 ) ;
if ( V_4 -> V_62 && ( V_4 -> V_62 -> V_86 & V_87 ) &&
F_12 ( & V_13 -> V_88 . V_26 ) &&
F_12 ( & V_4 -> V_26 ) &&
V_7 -> V_89 <= V_90 ) {
V_8 = & V_13 -> V_88 ;
V_8 -> V_8 = * V_7 ;
V_8 -> V_8 . V_91 = V_13 -> V_92 ;
memcpy ( V_13 -> V_92 , V_7 -> V_91 , V_7 -> V_89 ) ;
V_8 -> V_8 . V_93 = V_13 ;
V_8 -> V_8 . V_83 = F_39 ;
F_41 ( & V_8 -> V_26 , & V_4 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
V_7 -> V_85 = V_7 -> V_89 ;
V_7 -> V_28 = 0 ;
F_16 ( V_3 , V_7 ) ;
F_17 ( & V_13 -> V_30 ) ;
} else
F_41 ( & V_8 -> V_26 , & V_4 -> V_26 ) ;
F_32 ( & V_13 -> V_30 , V_81 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
int V_64 = - V_69 ;
unsigned long V_81 ;
struct V_5 * V_8 = NULL ;
if ( ! V_3 || ! V_7 )
return V_64 ;
V_4 = F_1 ( V_3 ) ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_57 )
return - V_29 ;
F_43 ( V_81 ) ;
F_17 ( & V_13 -> V_30 ) ;
F_44 (req, &ep->queue, queue) {
if ( & V_8 -> V_8 == V_7 ) {
F_14 ( & V_8 -> V_26 ) ;
V_7 -> V_28 = - V_94 ;
V_64 = 0 ;
break;
}
}
F_15 ( & V_13 -> V_30 ) ;
if ( V_64 == 0 ) {
F_29 ( F_7 ( V_13 ) ,
L_16 ,
V_8 , V_3 -> V_65 , V_7 -> V_89 , V_7 -> V_91 ) ;
F_16 ( V_3 , V_7 ) ;
}
F_45 ( V_81 ) ;
return V_64 ;
}
static int
F_46 ( struct V_2 * V_3 , int V_95 , int V_80 )
{
struct V_1 * V_4 ;
struct V_17 * V_13 ;
if ( ! V_3 )
return - V_69 ;
V_4 = F_1 ( V_3 ) ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_57 )
return - V_29 ;
if ( ! V_95 )
V_4 -> V_79 = V_4 -> V_80 = 0 ;
else if ( V_4 -> V_62 && ( V_4 -> V_62 -> V_86 & V_87 ) &&
! F_12 ( & V_4 -> V_26 ) )
return - V_96 ;
else {
V_4 -> V_79 = 1 ;
if ( V_80 )
V_4 -> V_80 = 1 ;
}
return 0 ;
}
static int
F_47 ( struct V_2 * V_3 , int V_95 )
{
return F_46 ( V_3 , V_95 , 0 ) ;
}
static int F_48 ( struct V_2 * V_3 )
{
if ( ! V_3 || V_3 -> V_65 == V_66 )
return - V_69 ;
return F_46 ( V_3 , 1 , 1 ) ;
}
static int F_49 ( struct V_21 * V_97 )
{
struct V_98 V_99 ;
F_50 ( & V_99 ) ;
return V_99 . V_100 / V_101 ;
}
static int F_51 ( struct V_21 * V_97 )
{
struct V_9 * V_34 ;
V_34 = F_9 ( V_97 ) ;
if ( ! ( V_34 -> V_13 -> V_102 & ( ( 1 << V_103 )
| ( 1 << V_104 ) ) ) )
return - V_69 ;
if ( ( V_34 -> V_36 & V_40 ) == 0 )
return - V_105 ;
if ( ( V_34 -> V_36 & V_52 ) == 0 &&
V_34 -> V_46 != V_47 )
return - V_106 ;
V_34 -> V_53 = 1 ;
V_34 -> V_107 = V_108 + F_52 ( 20 ) ;
F_53 ( & F_5 ( V_34 ) -> V_109 , V_34 -> V_107 ) ;
return 0 ;
}
static int F_54 ( struct V_21 * V_97 , int V_95 )
{
struct V_17 * V_13 ;
V_97 -> V_110 = ( V_95 != 0 ) ;
V_13 = F_9 ( V_97 ) -> V_13 ;
if ( V_95 )
V_13 -> V_102 |= ( 1 << V_111 ) ;
else
V_13 -> V_102 &= ~ ( 1 << V_111 ) ;
return 0 ;
}
static void F_55 ( struct V_17 * V_13 )
{
if ( V_13 -> V_18 . V_22 == V_23 )
V_13 -> V_4 [ 0 ] . V_4 . V_76 = 9 ;
else
V_13 -> V_4 [ 0 ] . V_4 . V_76 = 64 ;
}
static int F_56 ( struct V_21 * V_97 , int V_95 )
{
struct V_9 * V_34 ;
struct V_17 * V_13 ;
unsigned long V_81 ;
V_13 = F_10 ( & V_97 -> V_19 ) ;
if ( V_95 && V_13 -> V_57 ) {
if ( V_112 . V_113 )
V_13 -> V_18 . V_22 = V_13 -> V_57 -> V_114 ;
else if ( V_112 . V_115 )
V_13 -> V_18 . V_22 = F_57 ( V_116 , V_72 ,
V_13 -> V_57 -> V_114 ) ;
else
V_13 -> V_18 . V_22 = V_73 ;
F_55 ( V_13 ) ;
if ( V_13 -> V_18 . V_22 < V_13 -> V_57 -> V_114 )
F_29 ( F_7 ( V_13 ) , L_17
L_18 ,
F_58 ( V_13 -> V_57 -> V_114 ) ) ;
}
V_34 = F_9 ( V_97 ) ;
F_31 ( & V_13 -> V_30 , V_81 ) ;
V_13 -> V_38 = ( V_95 != 0 ) ;
F_20 ( V_34 ) ;
F_32 ( & V_13 -> V_30 , V_81 ) ;
F_59 ( F_5 ( V_34 ) ) ;
return 0 ;
}
static T_2 F_60 ( struct V_14 * V_19 , struct V_117 * V_118 ,
char * V_91 )
{
struct V_17 * V_13 = F_10 ( V_19 ) ;
if ( ! V_13 -> V_57 || ! V_13 -> V_57 -> V_119 )
return 0 ;
return F_61 ( V_91 , V_120 , L_19 , V_13 -> V_57 -> V_119 ) ;
}
static int F_62 ( struct V_21 * V_121 ,
struct V_122 * V_57 )
{
struct V_9 * V_34 = F_9 ( V_121 ) ;
struct V_17 * V_13 = V_34 -> V_13 ;
if ( V_57 -> V_114 == V_123 )
return - V_69 ;
V_13 -> V_102 = 0 ;
V_13 -> V_57 = V_57 ;
return 0 ;
}
static int F_63 ( struct V_21 * V_121 )
{
struct V_9 * V_34 = F_9 ( V_121 ) ;
struct V_17 * V_13 = V_34 -> V_13 ;
V_13 -> V_57 = NULL ;
return 0 ;
}
static void F_64 ( struct V_17 * V_13 )
{
int V_31 ;
F_35 ( & V_13 -> V_18 . V_124 ) ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_31 ] ;
if ( ! V_125 [ V_31 ] . V_65 )
break;
V_4 -> V_4 . V_65 = V_125 [ V_31 ] . V_65 ;
V_4 -> V_4 . V_126 = V_125 [ V_31 ] . V_126 ;
V_4 -> V_4 . V_127 = & V_128 ;
F_41 ( & V_4 -> V_4 . V_124 , & V_13 -> V_18 . V_124 ) ;
V_4 -> V_79 = V_4 -> V_80 = V_4 -> V_129 =
V_4 -> V_130 = 0 ;
F_65 ( & V_4 -> V_4 , ~ 0 ) ;
V_4 -> V_4 . V_131 = 16 ;
V_4 -> V_132 = V_108 ;
V_4 -> V_18 = & V_13 -> V_18 ;
V_4 -> V_62 = NULL ;
F_35 ( & V_4 -> V_26 ) ;
}
V_13 -> V_18 . V_133 = & V_13 -> V_4 [ 0 ] . V_4 ;
F_14 ( & V_13 -> V_4 [ 0 ] . V_4 . V_124 ) ;
F_35 ( & V_13 -> V_88 . V_26 ) ;
#ifdef F_66
V_13 -> V_18 . V_134 = 1 ;
#endif
}
static int F_67 ( struct V_135 * V_136 )
{
struct V_17 * V_13 ;
int V_137 ;
V_13 = * ( ( void * * ) F_68 ( & V_136 -> V_19 ) ) ;
F_69 ( & V_13 -> V_18 , sizeof( struct V_21 ) ) ;
V_13 -> V_18 . V_65 = V_138 ;
V_13 -> V_18 . V_127 = & V_139 ;
V_13 -> V_18 . V_114 = V_23 ;
V_13 -> V_18 . V_19 . V_20 = & V_136 -> V_19 ;
F_64 ( V_13 ) ;
V_137 = F_70 ( & V_136 -> V_19 , & V_13 -> V_18 ) ;
if ( V_137 < 0 )
goto V_140;
V_137 = F_71 ( & V_13 -> V_18 . V_19 , & V_141 ) ;
if ( V_137 < 0 )
goto V_142;
F_72 ( V_136 , V_13 ) ;
return V_137 ;
V_142:
F_73 ( & V_13 -> V_18 ) ;
V_140:
return V_137 ;
}
static int F_74 ( struct V_135 * V_136 )
{
struct V_17 * V_13 = F_75 ( V_136 ) ;
F_76 ( & V_13 -> V_18 . V_19 , & V_141 ) ;
F_73 ( & V_13 -> V_18 ) ;
return 0 ;
}
static void F_77 ( struct V_17 * V_13 , struct V_9 * V_34 ,
int V_59 )
{
F_78 ( & V_13 -> V_30 ) ;
V_13 -> V_39 = V_59 ;
F_20 ( V_34 ) ;
F_79 ( & V_13 -> V_30 ) ;
}
static int F_80 ( struct V_135 * V_136 , T_3 V_143 )
{
struct V_17 * V_13 = F_75 ( V_136 ) ;
struct V_9 * V_34 = F_9 ( & V_13 -> V_18 ) ;
F_29 ( & V_136 -> V_19 , L_19 , V_144 ) ;
F_77 ( V_13 , V_34 , 1 ) ;
F_59 ( F_5 ( V_34 ) ) ;
return 0 ;
}
static int F_81 ( struct V_135 * V_136 )
{
struct V_17 * V_13 = F_75 ( V_136 ) ;
struct V_9 * V_34 = F_9 ( & V_13 -> V_18 ) ;
F_29 ( & V_136 -> V_19 , L_19 , V_144 ) ;
F_77 ( V_13 , V_34 , 0 ) ;
F_59 ( F_5 ( V_34 ) ) ;
return 0 ;
}
static unsigned int F_82 ( const struct V_61 * V_62 )
{
unsigned int V_145 ;
V_145 = F_83 ( V_62 ) << 1 ;
if ( F_84 ( V_62 ) )
V_145 |= 1 ;
return V_145 ;
}
static int F_85 ( struct V_9 * V_34 , struct V_146 * V_146 )
{
const struct V_61 * V_62 = & V_146 -> V_4 -> V_62 ;
T_4 V_145 ;
if ( ! F_27 ( V_62 ) )
return 0 ;
V_145 = F_82 ( V_62 ) ;
return ( 1 << V_145 ) & V_34 -> V_147 ;
}
static int F_86 ( struct V_9 * V_34 ,
unsigned int V_148 )
{
int V_131 ;
V_131 = V_34 -> V_149 [ F_87 ( V_148 ) ] ;
if ( F_88 ( V_148 ) )
V_131 >>= 4 ;
else
V_131 &= 0xf ;
V_131 ++ ;
return V_131 ;
}
static void F_89 ( struct V_9 * V_34 ,
unsigned int V_148 , unsigned int V_150 )
{
int V_131 ;
V_150 -- ;
V_131 = V_34 -> V_149 [ F_87 ( V_148 ) ] ;
if ( F_88 ( V_148 ) ) {
V_150 <<= 4 ;
V_131 &= 0xf ;
} else {
V_131 &= 0xf0 ;
}
V_131 |= V_150 ;
V_34 -> V_149 [ F_87 ( V_148 ) ] = V_131 ;
}
static int F_90 ( struct V_9 * V_34 , struct V_146 * V_146 )
{
unsigned int V_131 ;
int V_151 ;
V_151 = F_85 ( V_34 , V_146 ) ;
if ( ! V_146 -> V_152 ) {
if ( V_151 )
return - V_69 ;
return 0 ;
}
if ( ! V_151 )
return - V_69 ;
V_131 = F_86 ( V_34 ,
F_87 ( V_146 -> V_148 ) ) ;
if ( V_146 -> V_152 > V_131 ) {
F_28 ( F_6 ( V_34 ) , L_20 ,
V_146 -> V_152 ) ;
F_91 () ;
return - V_69 ;
}
return 0 ;
}
static int F_92 (
struct V_10 * V_11 ,
struct V_146 * V_146 ,
T_1 V_82
) {
struct V_9 * V_34 ;
struct V_153 * V_153 ;
unsigned long V_81 ;
int V_137 ;
V_153 = F_93 ( sizeof *V_153 , V_82 ) ;
if ( ! V_153 )
return - V_154 ;
V_153 -> V_146 = V_146 ;
V_153 -> V_155 = 0 ;
V_34 = F_4 ( V_11 ) ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
V_137 = F_90 ( V_34 , V_146 ) ;
if ( V_137 ) {
F_38 ( V_153 ) ;
goto V_71;
}
V_137 = F_94 ( V_11 , V_146 ) ;
if ( V_137 ) {
F_38 ( V_153 ) ;
goto V_71;
}
if ( ! V_34 -> V_156 ) {
V_34 -> V_156 = V_146 -> V_19 ;
F_95 ( V_34 -> V_156 ) ;
} else if ( F_96 ( V_34 -> V_156 != V_146 -> V_19 ) )
F_28 ( F_6 ( V_34 ) , L_21 ) ;
F_41 ( & V_153 -> V_157 , & V_34 -> V_157 ) ;
V_146 -> V_158 = V_153 ;
if ( F_97 ( V_146 -> V_148 ) == V_159 )
V_146 -> V_160 = 1 ;
if ( ! F_98 ( & V_34 -> V_161 ) )
F_53 ( & V_34 -> V_161 , V_108 + 1 ) ;
V_71:
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
return V_137 ;
}
static int F_99 ( struct V_10 * V_11 , struct V_146 * V_146 , int V_28 )
{
struct V_9 * V_34 ;
unsigned long V_81 ;
int V_137 ;
V_34 = F_4 ( V_11 ) ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
V_137 = F_100 ( V_11 , V_146 , V_28 ) ;
if ( ! V_137 && V_34 -> V_46 != V_162 &&
! F_12 ( & V_34 -> V_157 ) )
F_53 ( & V_34 -> V_161 , V_108 ) ;
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
return V_137 ;
}
static int F_101 ( struct V_146 * V_146 , struct V_5 * V_8 ,
T_4 V_163 )
{
void * V_164 , * V_165 ;
struct V_153 * V_153 = V_146 -> V_158 ;
int V_166 ;
struct V_167 * V_168 = & V_153 -> V_168 ;
T_4 V_169 = 0 ;
T_4 V_170 ;
bool V_171 ;
V_166 = F_102 ( V_146 -> V_148 ) ;
V_165 = V_8 -> V_8 . V_91 + V_8 -> V_8 . V_85 ;
if ( ! V_146 -> V_172 ) {
V_164 = V_146 -> V_173 + V_146 -> V_174 ;
if ( V_166 )
memcpy ( V_164 , V_165 , V_163 ) ;
else
memcpy ( V_165 , V_164 , V_163 ) ;
return V_163 ;
}
if ( ! V_153 -> V_155 ) {
T_4 V_81 = V_175 ;
if ( V_166 )
V_81 |= V_176 ;
else
V_81 |= V_177 ;
F_103 ( V_168 , V_146 -> V_178 , V_146 -> V_172 , V_81 ) ;
V_153 -> V_155 = 1 ;
}
V_171 = F_104 ( V_168 ) ;
if ( V_171 == false ) {
F_105 ( 1 ) ;
return - V_69 ;
}
do {
V_164 = V_168 -> V_179 ;
V_170 = F_57 ( T_4 , V_163 , V_168 -> V_89 ) ;
V_168 -> V_180 = V_170 ;
V_169 += V_170 ;
if ( V_166 )
memcpy ( V_164 , V_165 , V_170 ) ;
else
memcpy ( V_165 , V_164 , V_170 ) ;
V_163 -= V_170 ;
if ( ! V_163 )
break;
V_171 = F_104 ( V_168 ) ;
if ( V_171 == false ) {
F_105 ( 1 ) ;
return - V_69 ;
}
V_165 += V_170 ;
} while ( 1 );
F_106 ( V_168 ) ;
return V_169 ;
}
static int F_107 ( struct V_9 * V_34 , struct V_146 * V_146 ,
struct V_1 * V_4 , int V_181 , int * V_28 )
{
struct V_17 * V_13 = V_34 -> V_13 ;
struct V_5 * V_8 ;
int V_182 = 0 ;
V_183:
F_44 (req, &ep->queue, queue) {
unsigned V_184 , V_185 , V_163 ;
int V_186 , V_166 ;
int V_187 = 0 ;
if ( F_85 ( V_34 , V_146 ) ) {
if ( ( V_146 -> V_152 != V_8 -> V_8 . V_152 ) )
continue;
}
V_184 = V_146 -> V_188 - V_146 -> V_174 ;
V_185 = V_8 -> V_8 . V_89 - V_8 -> V_8 . V_85 ;
V_163 = F_108 ( V_184 , V_185 ) ;
V_166 = F_102 ( V_146 -> V_148 ) ;
if ( F_96 ( V_163 == 0 ) )
V_186 = 1 ;
else {
if ( V_181 < V_4 -> V_4 . V_76 && V_181 < V_163 )
break;
V_163 = F_57 ( unsigned , V_163 , V_181 ) ;
if ( V_163 == 0 )
break;
if ( V_163 >= V_4 -> V_4 . V_76 ) {
V_186 = 0 ;
if ( V_163 % V_4 -> V_4 . V_76 )
V_187 = 1 ;
V_163 -= V_163 % V_4 -> V_4 . V_76 ;
} else {
V_186 = 1 ;
}
V_163 = F_101 ( V_146 , V_8 , V_163 ) ;
V_4 -> V_132 = V_108 ;
if ( ( int ) V_163 < 0 ) {
V_8 -> V_8 . V_28 = V_163 ;
} else {
V_181 -= V_163 ;
V_182 += V_163 ;
V_146 -> V_174 += V_163 ;
V_8 -> V_8 . V_85 += V_163 ;
}
}
if ( V_186 ) {
if ( V_184 == V_185 ) {
V_8 -> V_8 . V_28 = 0 ;
* V_28 = 0 ;
} else if ( V_166 ) {
V_8 -> V_8 . V_28 = 0 ;
if ( V_185 > V_184 )
* V_28 = - V_189 ;
else
* V_28 = 0 ;
} else {
* V_28 = 0 ;
if ( V_184 > V_185 )
V_8 -> V_8 . V_28 = - V_189 ;
else
V_8 -> V_8 . V_28 = 0 ;
}
} else {
if ( V_8 -> V_8 . V_89 == V_8 -> V_8 . V_85 ) {
if ( V_8 -> V_8 . V_190 && V_166 )
V_187 = 1 ;
else
V_8 -> V_8 . V_28 = 0 ;
}
if ( V_146 -> V_188 == V_146 -> V_174 ) {
if ( V_146 -> V_191 & V_192 &&
! V_166 )
V_187 = 1 ;
else
* V_28 = 0 ;
}
}
if ( V_8 -> V_8 . V_28 != - V_84 ) {
F_14 ( & V_8 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_16 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_17 ( & V_13 -> V_30 ) ;
V_187 = 1 ;
}
if ( * V_28 != - V_84 )
break;
if ( V_187 )
goto V_183;
}
return V_182 ;
}
static int F_109 ( struct V_17 * V_13 , struct V_1 * V_4 )
{
int V_181 = V_4 -> V_4 . V_76 ;
if ( V_13 -> V_18 . V_22 == V_72 ) {
int V_193 ;
V_193 = F_110 ( V_4 -> V_62 ) ;
V_193 *= 8 ;
V_181 += V_181 * V_193 ;
}
if ( V_13 -> V_18 . V_22 == V_23 ) {
switch ( F_25 ( V_4 -> V_62 ) ) {
case V_75 :
V_181 = 3 * 16 * 1024 * 8 ;
break;
case V_74 :
V_181 = 3 * 1024 * 8 ;
break;
case V_70 :
default:
break;
}
}
return V_181 ;
}
static struct V_1 * F_111 ( struct V_17 * V_13 , V_116 V_32 )
{
int V_31 ;
if ( ! F_112 ( ( V_13 -> V_18 . V_22 == V_23 ?
V_13 -> V_24 : V_13 -> V_25 ) ) )
return NULL ;
if ( ( V_32 & ~ V_87 ) == 0 )
return & V_13 -> V_4 [ 0 ] ;
for ( V_31 = 1 ; V_31 < V_33 ; V_31 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_31 ] ;
if ( ! V_4 -> V_62 )
continue;
if ( V_4 -> V_62 -> V_86 == V_32 )
return V_4 ;
}
return NULL ;
}
static int F_113 ( struct V_9 * V_34 , struct V_146 * V_146 ,
struct V_194 * V_195 ,
int * V_28 )
{
struct V_1 * V_196 ;
struct V_17 * V_13 = V_34 -> V_13 ;
int V_197 = 1 ;
unsigned V_198 ;
unsigned V_199 ;
V_198 = F_114 ( V_195 -> V_200 ) ;
V_199 = F_114 ( V_195 -> V_201 ) ;
switch ( V_195 -> V_202 ) {
case V_203 :
if ( V_195 -> V_204 != V_205 )
break;
V_13 -> V_32 = V_199 ;
* V_28 = 0 ;
F_29 ( F_7 ( V_13 ) , L_22 ,
V_199 ) ;
V_197 = 0 ;
break;
case V_206 :
if ( V_195 -> V_204 == V_205 ) {
V_197 = 0 ;
switch ( V_199 ) {
case V_104 :
break;
case V_103 :
V_13 -> V_18 . V_207 = 1 ;
break;
case V_208 :
V_13 -> V_18 . V_209 = 1 ;
break;
case V_210 :
V_13 -> V_18 . V_211 = 1 ;
break;
case V_212 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_199 = V_213 ;
else
V_197 = - V_214 ;
break;
case V_215 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_199 = V_216 ;
else
V_197 = - V_214 ;
break;
case V_217 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_199 = V_218 ;
else
V_197 = - V_214 ;
break;
default:
V_197 = - V_214 ;
}
if ( V_197 == 0 ) {
V_13 -> V_102 |= ( 1 << V_199 ) ;
* V_28 = 0 ;
}
} else if ( V_195 -> V_204 == V_219 ) {
V_196 = F_111 ( V_13 , V_198 ) ;
if ( ! V_196 || V_196 -> V_4 . V_65 == V_66 ) {
V_197 = - V_214 ;
break;
}
V_196 -> V_79 = 1 ;
V_197 = 0 ;
* V_28 = 0 ;
}
break;
case V_220 :
if ( V_195 -> V_204 == V_205 ) {
V_197 = 0 ;
switch ( V_199 ) {
case V_104 :
V_199 = V_104 ;
break;
case V_212 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_199 = V_213 ;
else
V_197 = - V_214 ;
break;
case V_215 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_199 = V_216 ;
else
V_197 = - V_214 ;
break;
case V_217 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_199 = V_218 ;
else
V_197 = - V_214 ;
break;
default:
V_197 = - V_214 ;
break;
}
if ( V_197 == 0 ) {
V_13 -> V_102 &= ~ ( 1 << V_199 ) ;
* V_28 = 0 ;
}
} else if ( V_195 -> V_204 == V_219 ) {
V_196 = F_111 ( V_13 , V_198 ) ;
if ( ! V_196 ) {
V_197 = - V_214 ;
break;
}
if ( ! V_196 -> V_80 )
V_196 -> V_79 = 0 ;
V_197 = 0 ;
* V_28 = 0 ;
}
break;
case V_221 :
if ( V_195 -> V_204 == V_222
|| V_195 -> V_204 == V_223
|| V_195 -> V_204 == V_224 ) {
char * V_91 ;
V_91 = ( char * ) V_146 -> V_173 ;
if ( V_146 -> V_188 > 0 ) {
if ( V_195 -> V_204 == V_224 ) {
V_196 = F_111 ( V_13 , V_198 ) ;
if ( ! V_196 ) {
V_197 = - V_214 ;
break;
}
V_91 [ 0 ] = V_196 -> V_79 ;
} else if ( V_195 -> V_204 ==
V_222 ) {
V_91 [ 0 ] = ( V_116 ) V_13 -> V_102 ;
} else
V_91 [ 0 ] = 0 ;
}
if ( V_146 -> V_188 > 1 )
V_91 [ 1 ] = 0 ;
V_146 -> V_174 = F_57 ( T_4 , 2 ,
V_146 -> V_188 ) ;
V_197 = 0 ;
* V_28 = 0 ;
}
break;
}
return V_197 ;
}
static void F_115 ( unsigned long V_225 )
{
struct V_9 * V_34 = (struct V_9 * ) V_225 ;
struct V_17 * V_13 = V_34 -> V_13 ;
struct V_153 * V_153 , * V_193 ;
unsigned long V_81 ;
int V_181 , V_226 ;
int V_31 ;
switch ( V_13 -> V_18 . V_22 ) {
case V_227 :
V_226 = 8 * 12 ;
break;
case V_73 :
V_226 = 64 * 19 ;
break;
case V_72 :
V_226 = 512 * 13 * 8 ;
break;
case V_23 :
V_226 = 490000 ;
break;
default:
F_28 ( F_6 ( V_34 ) , L_23 ) ;
return;
}
F_31 ( & V_13 -> V_30 , V_81 ) ;
if ( ! V_34 -> V_156 ) {
F_28 ( F_6 ( V_34 ) ,
L_24 ) ;
F_32 ( & V_13 -> V_30 , V_81 ) ;
return;
}
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
if ( ! V_125 [ V_31 ] . V_65 )
break;
V_13 -> V_4 [ V_31 ] . V_129 = 0 ;
}
V_228:
F_116 (urbp, tmp, &dum_hcd->urbp_list, urbp_list) {
struct V_146 * V_146 ;
struct V_5 * V_8 ;
V_116 V_32 ;
struct V_1 * V_4 = NULL ;
int type ;
int V_28 = - V_84 ;
V_146 = V_153 -> V_146 ;
if ( V_146 -> V_229 )
goto V_230;
else if ( V_34 -> V_46 != V_162 )
continue;
type = F_97 ( V_146 -> V_148 ) ;
if ( V_226 <= 0 && type == V_231 )
continue;
V_32 = F_87 ( V_146 -> V_148 ) ;
if ( F_102 ( V_146 -> V_148 ) )
V_32 |= V_87 ;
V_4 = F_111 ( V_13 , V_32 ) ;
if ( ! V_4 ) {
F_29 ( F_6 ( V_34 ) ,
L_25 ,
V_146 ) ;
V_28 = - V_232 ;
goto V_230;
}
if ( V_4 -> V_129 )
continue;
V_4 -> V_129 = 1 ;
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_146 -> V_160 ) {
V_4 -> V_130 = 1 ;
V_146 -> V_160 = 0 ;
}
if ( V_4 -> V_79 && ! V_4 -> V_130 ) {
F_29 ( F_6 ( V_34 ) , L_26 ,
V_4 -> V_4 . V_65 , V_146 ) ;
V_28 = - V_233 ;
goto V_230;
}
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_4 -> V_130 ) {
struct V_194 V_195 ;
int V_95 = 1 ;
V_195 = * (struct V_194 * ) V_146 -> V_234 ;
F_44 (req, &ep->queue, queue) {
F_14 ( & V_8 -> V_26 ) ;
V_8 -> V_8 . V_28 = - V_189 ;
F_29 ( F_7 ( V_13 ) , L_27 ,
V_8 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_16 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_17 ( & V_13 -> V_30 ) ;
V_4 -> V_129 = 0 ;
goto V_228;
}
V_4 -> V_132 = V_108 ;
V_4 -> V_130 = 0 ;
V_4 -> V_79 = 0 ;
V_95 = F_113 ( V_34 , V_146 , & V_195 ,
& V_28 ) ;
if ( V_95 > 0 ) {
F_15 ( & V_13 -> V_30 ) ;
V_95 = V_13 -> V_57 -> V_195 ( & V_13 -> V_18 ,
& V_195 ) ;
F_17 ( & V_13 -> V_30 ) ;
if ( V_95 >= 0 ) {
V_181 = 64 * 1024 ;
goto V_235;
}
}
if ( V_95 < 0 ) {
if ( V_95 != - V_214 )
F_29 ( F_7 ( V_13 ) ,
L_28 ,
V_95 ) ;
V_28 = - V_233 ;
V_146 -> V_174 = 0 ;
}
goto V_230;
}
V_181 = V_226 ;
switch ( F_97 ( V_146 -> V_148 ) ) {
case V_236 :
V_181 = V_63 ( V_181 , F_109 ( V_13 , V_4 ) ) ;
V_28 = - V_237 ;
break;
case V_238 :
V_181 = V_63 ( V_181 , F_109 ( V_13 , V_4 ) ) ;
default:
V_235:
V_4 -> V_132 = V_108 ;
V_226 -= F_107 ( V_34 , V_146 , V_4 , V_181 , & V_28 ) ;
break;
}
if ( V_28 == - V_84 )
continue;
V_230:
F_117 ( & V_153 -> V_157 ) ;
F_38 ( V_153 ) ;
if ( V_4 )
V_4 -> V_129 = V_4 -> V_130 = 0 ;
F_118 ( F_5 ( V_34 ) , V_146 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_119 ( F_5 ( V_34 ) , V_146 , V_28 ) ;
F_17 ( & V_13 -> V_30 ) ;
goto V_228;
}
if ( F_12 ( & V_34 -> V_157 ) ) {
F_120 ( V_34 -> V_156 ) ;
V_34 -> V_156 = NULL ;
} else if ( V_34 -> V_46 == V_162 ) {
F_53 ( & V_34 -> V_161 , V_108 + F_52 ( 1 ) ) ;
}
F_32 ( & V_13 -> V_30 , V_81 ) ;
}
static int F_121 ( struct V_10 * V_11 , char * V_91 )
{
struct V_9 * V_34 ;
unsigned long V_81 ;
int V_64 = 0 ;
V_34 = F_4 ( V_11 ) ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
if ( ! F_122 ( V_11 ) )
goto V_71;
if ( V_34 -> V_53 && F_123 ( V_108 , V_34 -> V_107 ) ) {
V_34 -> V_36 |= ( V_239 << 16 ) ;
V_34 -> V_36 &= ~ V_52 ;
F_20 ( V_34 ) ;
}
if ( ( V_34 -> V_36 & V_240 ) != 0 ) {
* V_91 = ( 1 << 1 ) ;
F_29 ( F_6 ( V_34 ) , L_29 ,
V_34 -> V_36 ) ;
V_64 = 1 ;
if ( V_34 -> V_46 == V_47 )
F_124 ( V_11 ) ;
}
V_71:
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
return V_64 ;
}
static inline void
F_125 ( struct V_241 * V_62 )
{
memset ( V_62 , 0 , sizeof *V_62 ) ;
V_62 -> V_67 = V_242 ;
V_62 -> V_243 = 12 ;
V_62 -> V_244 = F_126 (
V_245 |
V_246 ) ;
V_62 -> V_247 = 1 ;
V_62 -> V_248 . V_249 . V_250 = 0x04 ;
V_62 -> V_248 . V_249 . V_251 = 0xffff ;
}
static inline void F_127 ( struct V_241 * V_62 )
{
memset ( V_62 , 0 , sizeof *V_62 ) ;
V_62 -> V_67 = V_252 ;
V_62 -> V_243 = 9 ;
V_62 -> V_244 = F_126 (
V_245 |
V_246 ) ;
V_62 -> V_247 = 1 ;
V_62 -> V_248 . V_253 . V_251 [ 0 ] = 0xff ;
V_62 -> V_248 . V_253 . V_251 [ 1 ] = 0xff ;
}
static int F_128 (
struct V_10 * V_11 ,
T_5 V_254 ,
T_5 V_201 ,
T_5 V_200 ,
char * V_91 ,
T_5 V_255
) {
struct V_9 * V_34 ;
int V_64 = 0 ;
unsigned long V_81 ;
if ( ! F_122 ( V_11 ) )
return - V_256 ;
V_34 = F_4 ( V_11 ) ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
switch ( V_254 ) {
case V_257 :
break;
case V_258 :
switch ( V_201 ) {
case V_259 :
if ( V_11 -> V_22 == V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_30
L_31 ) ;
goto error;
}
if ( V_34 -> V_36 & V_52 ) {
V_34 -> V_53 = 1 ;
V_34 -> V_107 = V_108 +
F_52 ( 20 ) ;
}
break;
case V_260 :
if ( V_11 -> V_22 == V_35 ) {
if ( V_34 -> V_36 & V_49 )
F_29 ( F_6 ( V_34 ) ,
L_32 ) ;
} else
if ( V_34 -> V_36 &
V_37 )
F_29 ( F_6 ( V_34 ) ,
L_32 ) ;
default:
V_34 -> V_36 &= ~ ( 1 << V_201 ) ;
F_20 ( V_34 ) ;
}
break;
case V_261 :
if ( V_11 -> V_22 == V_35 &&
( V_255 < V_262 ||
V_201 != ( V_242 << 8 ) ) ) {
F_29 ( F_6 ( V_34 ) ,
L_33
L_34 ) ;
goto error;
}
if ( V_11 -> V_22 == V_35 )
F_125 ( (struct V_241 * ) V_91 ) ;
else
F_127 ( (struct V_241 * ) V_91 ) ;
break;
case V_263 | V_264 :
if ( V_11 -> V_22 != V_35 )
goto error;
if ( ( V_201 >> 8 ) != V_265 )
goto error;
memcpy ( V_91 , & V_266 , sizeof( V_266 ) ) ;
V_64 = sizeof( V_266 ) ;
break;
case V_267 :
* ( V_268 * ) V_91 = F_129 ( 0 ) ;
break;
case V_269 :
if ( V_200 != 1 )
V_64 = - V_233 ;
if ( V_34 -> V_53 &&
F_123 ( V_108 , V_34 -> V_107 ) ) {
V_34 -> V_36 |= ( V_239 << 16 ) ;
V_34 -> V_36 &= ~ V_52 ;
}
if ( ( V_34 -> V_36 & V_54 ) != 0 &&
F_123 ( V_108 , V_34 -> V_107 ) ) {
V_34 -> V_36 |= ( V_270 << 16 ) ;
V_34 -> V_36 &= ~ V_54 ;
if ( V_34 -> V_13 -> V_38 ) {
V_34 -> V_36 |= V_41 ;
if ( V_11 -> V_22 < V_35 ) {
switch ( V_34 -> V_13 -> V_18 . V_22 ) {
case V_72 :
V_34 -> V_36 |=
V_51 ;
break;
case V_227 :
V_34 -> V_13 -> V_18 . V_133 ->
V_76 = 8 ;
V_34 -> V_36 |=
V_50 ;
break;
default:
V_34 -> V_13 -> V_18 . V_22 =
V_73 ;
break;
}
}
}
}
F_20 ( V_34 ) ;
( ( V_271 * ) V_91 ) [ 0 ] = F_126 ( V_34 -> V_36 ) ;
( ( V_271 * ) V_91 ) [ 1 ] = F_126 ( V_34 -> V_36 >> 16 ) ;
break;
case V_272 :
V_64 = - V_233 ;
break;
case V_273 :
switch ( V_201 ) {
case V_274 :
if ( V_11 -> V_22 != V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_35
L_36 ) ;
goto error;
}
break;
case V_275 :
case V_276 :
if ( V_11 -> V_22 != V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_37
L_36 ) ;
goto error;
}
break;
case V_259 :
if ( V_11 -> V_22 == V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_30
L_31 ) ;
goto error;
}
if ( V_34 -> V_48 ) {
V_34 -> V_36 |= V_52 ;
F_20 ( V_34 ) ;
if ( ( ( 1 << V_103 )
& V_34 -> V_13 -> V_102 ) != 0 )
F_29 ( F_6 ( V_34 ) ,
L_38 ) ;
}
break;
case V_260 :
if ( V_11 -> V_22 == V_35 )
V_34 -> V_36 |= V_37 ;
else
V_34 -> V_36 |= V_49 ;
F_20 ( V_34 ) ;
break;
case V_277 :
if ( V_11 -> V_22 != V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_39
L_36 ) ;
goto error;
}
case V_278 :
if ( V_11 -> V_22 == V_35 ) {
V_34 -> V_36 = 0 ;
V_34 -> V_36 =
( V_37 |
V_40 |
V_54 ) ;
} else
V_34 -> V_36 &= ~ ( V_41
| V_50
| V_51 ) ;
V_34 -> V_13 -> V_102 &=
( 1 << V_111 ) ;
V_34 -> V_107 = V_108 + F_52 ( 50 ) ;
default:
if ( V_11 -> V_22 == V_35 ) {
if ( ( V_34 -> V_36 &
V_37 ) != 0 ) {
V_34 -> V_36 |= ( 1 << V_201 ) ;
F_20 ( V_34 ) ;
}
} else
if ( ( V_34 -> V_36 &
V_49 ) != 0 ) {
V_34 -> V_36 |= ( 1 << V_201 ) ;
F_20 ( V_34 ) ;
}
}
break;
case V_279 :
if ( V_11 -> V_22 != V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_40
L_36 ) ;
goto error;
}
* ( V_268 * ) V_91 = F_129 ( 0 ) ;
break;
case V_280 :
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
V_254 , V_201 , V_200 , V_255 ) ;
error:
V_64 = - V_233 ;
}
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
if ( ( V_34 -> V_36 & V_240 ) != 0 )
F_59 ( V_11 ) ;
return V_64 ;
}
static int F_130 ( struct V_10 * V_11 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
F_29 ( & V_11 -> V_15 . V_281 -> V_19 , L_19 , V_144 ) ;
F_78 ( & V_34 -> V_13 -> V_30 ) ;
V_34 -> V_46 = V_47 ;
F_20 ( V_34 ) ;
V_11 -> V_143 = V_282 ;
F_79 ( & V_34 -> V_13 -> V_30 ) ;
return 0 ;
}
static int F_131 ( struct V_10 * V_11 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
int V_137 = 0 ;
F_29 ( & V_11 -> V_15 . V_281 -> V_19 , L_19 , V_144 ) ;
F_78 ( & V_34 -> V_13 -> V_30 ) ;
if ( ! F_122 ( V_11 ) ) {
V_137 = - V_29 ;
} else {
V_34 -> V_46 = V_162 ;
F_20 ( V_34 ) ;
if ( ! F_12 ( & V_34 -> V_157 ) )
F_53 ( & V_34 -> V_161 , V_108 ) ;
V_11 -> V_143 = V_283 ;
}
F_79 ( & V_34 -> V_13 -> V_30 ) ;
return V_137 ;
}
static inline T_2 F_132 ( char * V_91 , T_6 V_284 , struct V_146 * V_146 )
{
int V_4 = F_87 ( V_146 -> V_148 ) ;
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
static T_2 F_133 ( struct V_14 * V_19 , struct V_117 * V_118 ,
char * V_91 )
{
struct V_10 * V_11 = F_134 ( V_19 ) ;
struct V_9 * V_34 = F_4 ( V_11 ) ;
struct V_153 * V_153 ;
T_6 V_284 = 0 ;
unsigned long V_81 ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
F_44 (urbp, &dum_hcd->urbp_list, urbp_list) {
T_6 V_285 ;
V_285 = F_132 ( V_91 , V_120 - V_284 , V_153 -> V_146 ) ;
V_91 += V_285 ;
V_284 += V_285 ;
}
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
return V_284 ;
}
static int F_135 ( struct V_9 * V_34 )
{
F_136 ( & V_34 -> V_161 ) ;
V_34 -> V_161 . V_119 = F_115 ;
V_34 -> V_161 . V_286 = ( unsigned long ) V_34 ;
V_34 -> V_46 = V_162 ;
V_34 -> V_147 = 0 ;
F_35 ( & V_34 -> V_157 ) ;
F_5 ( V_34 ) -> V_287 = V_288 ;
F_5 ( V_34 ) -> V_143 = V_283 ;
F_5 ( V_34 ) -> V_289 = 1 ;
#ifdef F_66
F_5 ( V_34 ) -> V_15 . V_290 = 1 ;
#endif
return 0 ;
return F_71 ( F_6 ( V_34 ) , & V_291 ) ;
}
static int F_137 ( struct V_10 * V_11 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
if ( ! F_138 ( V_11 ) )
return F_135 ( V_34 ) ;
F_139 ( & V_34 -> V_13 -> V_30 ) ;
F_136 ( & V_34 -> V_161 ) ;
V_34 -> V_161 . V_119 = F_115 ;
V_34 -> V_161 . V_286 = ( unsigned long ) V_34 ;
V_34 -> V_46 = V_162 ;
F_35 ( & V_34 -> V_157 ) ;
V_11 -> V_287 = V_288 ;
V_11 -> V_143 = V_283 ;
V_11 -> V_289 = 1 ;
#ifdef F_66
V_11 -> V_15 . V_290 = 1 ;
#endif
return F_71 ( F_6 ( V_34 ) , & V_291 ) ;
}
static void F_140 ( struct V_10 * V_11 )
{
F_76 ( F_6 ( F_4 ( V_11 ) ) , & V_291 ) ;
F_141 ( F_6 ( F_4 ( V_11 ) ) , L_51 ) ;
}
static int F_142 ( struct V_10 * V_11 )
{
return F_49 ( NULL ) ;
}
static int F_143 ( struct V_10 * V_11 )
{
struct V_17 * V_13 ;
V_13 = * ( ( void * * ) F_68 ( V_11 -> V_15 . V_16 ) ) ;
V_11 -> V_15 . V_292 = ~ 0 ;
if ( F_138 ( V_11 ) ) {
V_13 -> V_25 = F_4 ( V_11 ) ;
V_13 -> V_25 -> V_13 = V_13 ;
V_11 -> V_22 = V_293 ;
V_11 -> V_15 . V_281 -> V_22 = V_72 ;
} else {
V_13 -> V_24 = F_4 ( V_11 ) ;
V_13 -> V_24 -> V_13 = V_13 ;
V_11 -> V_22 = V_35 ;
V_11 -> V_15 . V_281 -> V_22 = V_23 ;
}
return 0 ;
}
static int F_144 ( struct V_10 * V_11 , struct V_294 * V_156 ,
struct V_295 * * V_296 , unsigned int V_297 ,
unsigned int V_298 , T_1 V_82 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
unsigned long V_81 ;
int V_299 ;
int V_300 = V_298 ;
unsigned int V_145 ;
unsigned int V_31 ;
if ( ! V_297 )
return - V_69 ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
for ( V_31 = 0 ; V_31 < V_297 ; V_31 ++ ) {
V_145 = F_82 ( & V_296 [ V_31 ] -> V_62 ) ;
if ( ( 1 << V_145 ) & V_34 -> V_147 ) {
V_300 = - V_69 ;
goto V_301;
}
V_299 = F_26 ( & V_296 [ V_31 ] -> V_302 ) ;
if ( ! V_299 ) {
V_300 = - V_69 ;
goto V_301;
}
if ( V_299 < V_300 ) {
F_29 ( F_6 ( V_34 ) , L_52
L_53 ,
V_296 [ V_31 ] -> V_62 . V_86 ,
V_299 ) ;
V_300 = V_299 ;
}
}
for ( V_31 = 0 ; V_31 < V_297 ; V_31 ++ ) {
V_145 = F_82 ( & V_296 [ V_31 ] -> V_62 ) ;
V_34 -> V_147 |= 1 << V_145 ;
F_89 ( V_34 ,
F_83 ( & V_296 [ V_31 ] -> V_62 ) , V_300 ) ;
}
V_301:
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
return V_300 ;
}
static int F_145 ( struct V_10 * V_11 , struct V_294 * V_156 ,
struct V_295 * * V_296 , unsigned int V_297 ,
T_1 V_82 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
unsigned long V_81 ;
int V_303 ;
unsigned int V_145 ;
unsigned int V_31 ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
for ( V_31 = 0 ; V_31 < V_297 ; V_31 ++ ) {
V_145 = F_82 ( & V_296 [ V_31 ] -> V_62 ) ;
if ( ! ( ( 1 << V_145 ) & V_34 -> V_147 ) ) {
V_303 = - V_69 ;
goto V_301;
}
}
for ( V_31 = 0 ; V_31 < V_297 ; V_31 ++ ) {
V_145 = F_82 ( & V_296 [ V_31 ] -> V_62 ) ;
V_34 -> V_147 &= ~ ( 1 << V_145 ) ;
F_89 ( V_34 ,
F_83 ( & V_296 [ V_31 ] -> V_62 ) , 0 ) ;
}
V_303 = 0 ;
V_301:
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
return V_303 ;
}
static int F_146 ( struct V_135 * V_136 )
{
struct V_17 * V_13 ;
struct V_10 * V_25 ;
struct V_10 * V_24 ;
int V_64 ;
F_141 ( & V_136 -> V_19 , L_54 V_304 L_55 , V_305 ) ;
V_13 = * ( ( void * * ) F_68 ( & V_136 -> V_19 ) ) ;
if ( ! V_112 . V_113 )
V_9 . V_81 = V_293 ;
V_25 = F_147 ( & V_9 , & V_136 -> V_19 , F_148 ( & V_136 -> V_19 ) ) ;
if ( ! V_25 )
return - V_154 ;
V_25 -> V_306 = 1 ;
V_64 = F_149 ( V_25 , 0 , 0 ) ;
if ( V_64 )
goto V_307;
if ( V_112 . V_113 ) {
V_24 = F_150 ( & V_9 , & V_136 -> V_19 ,
F_148 ( & V_136 -> V_19 ) , V_25 ) ;
if ( ! V_24 ) {
V_64 = - V_154 ;
goto V_308;
}
V_64 = F_149 ( V_24 , 0 , 0 ) ;
if ( V_64 )
goto V_309;
}
return 0 ;
V_309:
F_151 ( V_24 ) ;
V_308:
F_152 ( V_25 ) ;
V_307:
F_151 ( V_25 ) ;
V_13 -> V_25 = V_13 -> V_24 = NULL ;
return V_64 ;
}
static int F_153 ( struct V_135 * V_136 )
{
struct V_17 * V_13 ;
V_13 = F_4 ( F_75 ( V_136 ) ) -> V_13 ;
if ( V_13 -> V_24 ) {
F_152 ( F_5 ( V_13 -> V_24 ) ) ;
F_151 ( F_5 ( V_13 -> V_24 ) ) ;
}
F_152 ( F_5 ( V_13 -> V_25 ) ) ;
F_151 ( F_5 ( V_13 -> V_25 ) ) ;
V_13 -> V_25 = NULL ;
V_13 -> V_24 = NULL ;
return 0 ;
}
static int F_154 ( struct V_135 * V_136 , T_3 V_143 )
{
struct V_10 * V_11 ;
struct V_9 * V_34 ;
int V_137 = 0 ;
F_29 ( & V_136 -> V_19 , L_19 , V_144 ) ;
V_11 = F_75 ( V_136 ) ;
V_34 = F_4 ( V_11 ) ;
if ( V_34 -> V_46 == V_162 ) {
F_155 ( & V_136 -> V_19 , L_56 ) ;
V_137 = - V_310 ;
} else
F_156 ( V_311 , & V_11 -> V_81 ) ;
return V_137 ;
}
static int F_157 ( struct V_135 * V_136 )
{
struct V_10 * V_11 ;
F_29 ( & V_136 -> V_19 , L_19 , V_144 ) ;
V_11 = F_75 ( V_136 ) ;
F_158 ( V_311 , & V_11 -> V_81 ) ;
F_59 ( V_11 ) ;
return 0 ;
}
static int T_7 F_159 ( void )
{
int V_64 = - V_154 ;
int V_31 ;
struct V_17 * V_13 [ V_312 ] ;
if ( F_160 () )
return - V_313 ;
if ( ! V_112 . V_115 && V_112 . V_113 )
return - V_69 ;
if ( V_112 . V_314 < 1 || V_112 . V_314 > V_312 ) {
F_161 ( L_57 ,
V_312 ) ;
return - V_69 ;
}
for ( V_31 = 0 ; V_31 < V_112 . V_314 ; V_31 ++ ) {
V_315 [ V_31 ] = F_162 ( V_316 , V_31 ) ;
if ( ! V_315 [ V_31 ] ) {
V_31 -- ;
while ( V_31 >= 0 )
F_163 ( V_315 [ V_31 -- ] ) ;
return V_64 ;
}
}
for ( V_31 = 0 ; V_31 < V_112 . V_314 ; V_31 ++ ) {
V_317 [ V_31 ] = F_162 ( V_138 , V_31 ) ;
if ( ! V_317 [ V_31 ] ) {
V_31 -- ;
while ( V_31 >= 0 )
F_163 ( V_317 [ V_31 -- ] ) ;
goto V_318;
}
}
for ( V_31 = 0 ; V_31 < V_112 . V_314 ; V_31 ++ ) {
V_13 [ V_31 ] = F_34 ( sizeof( struct V_17 ) , V_319 ) ;
if ( ! V_13 [ V_31 ] ) {
V_64 = - V_154 ;
goto V_320;
}
V_64 = F_164 ( V_315 [ V_31 ] , & V_13 [ V_31 ] ,
sizeof( void * ) ) ;
if ( V_64 )
goto V_320;
V_64 = F_164 ( V_317 [ V_31 ] , & V_13 [ V_31 ] ,
sizeof( void * ) ) ;
if ( V_64 )
goto V_320;
}
V_64 = F_165 ( & V_321 ) ;
if ( V_64 < 0 )
goto V_320;
V_64 = F_165 ( & V_322 ) ;
if ( V_64 < 0 )
goto V_323;
for ( V_31 = 0 ; V_31 < V_112 . V_314 ; V_31 ++ ) {
V_64 = F_166 ( V_315 [ V_31 ] ) ;
if ( V_64 < 0 ) {
V_31 -- ;
while ( V_31 >= 0 )
F_167 ( V_315 [ V_31 -- ] ) ;
goto V_324;
}
}
for ( V_31 = 0 ; V_31 < V_112 . V_314 ; V_31 ++ ) {
if ( ! V_13 [ V_31 ] -> V_25 ||
( ! V_13 [ V_31 ] -> V_24 && V_112 . V_113 ) ) {
V_64 = - V_69 ;
goto V_325;
}
}
for ( V_31 = 0 ; V_31 < V_112 . V_314 ; V_31 ++ ) {
V_64 = F_166 ( V_317 [ V_31 ] ) ;
if ( V_64 < 0 ) {
V_31 -- ;
while ( V_31 >= 0 )
F_167 ( V_317 [ V_31 ] ) ;
goto V_325;
}
}
for ( V_31 = 0 ; V_31 < V_112 . V_314 ; V_31 ++ ) {
if ( ! F_75 ( V_317 [ V_31 ] ) ) {
V_64 = - V_69 ;
goto V_326;
}
}
return V_64 ;
V_326:
for ( V_31 = 0 ; V_31 < V_112 . V_314 ; V_31 ++ )
F_167 ( V_317 [ V_31 ] ) ;
V_325:
for ( V_31 = 0 ; V_31 < V_112 . V_314 ; V_31 ++ )
F_167 ( V_315 [ V_31 ] ) ;
V_324:
F_168 ( & V_322 ) ;
V_323:
F_168 ( & V_321 ) ;
V_320:
for ( V_31 = 0 ; V_31 < V_112 . V_314 ; V_31 ++ )
F_38 ( V_13 [ V_31 ] ) ;
for ( V_31 = 0 ; V_31 < V_112 . V_314 ; V_31 ++ )
F_163 ( V_317 [ V_31 ] ) ;
V_318:
for ( V_31 = 0 ; V_31 < V_112 . V_314 ; V_31 ++ )
F_163 ( V_315 [ V_31 ] ) ;
return V_64 ;
}
static void T_8 F_169 ( void )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_112 . V_314 ; V_31 ++ ) {
struct V_17 * V_13 ;
V_13 = * ( ( void * * ) F_68 ( & V_317 [ V_31 ] -> V_19 ) ) ;
F_170 ( V_317 [ V_31 ] ) ;
F_170 ( V_315 [ V_31 ] ) ;
F_38 ( V_13 ) ;
}
F_168 ( & V_322 ) ;
F_168 ( & V_321 ) ;
}
