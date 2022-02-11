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
if ( V_56 )
F_21 ( & V_13 -> V_18 , V_13 -> V_57 ) ;
else
V_13 -> V_57 -> V_55 ( & V_13 -> V_18 ) ;
}
} else if ( V_34 -> V_48 != V_34 -> V_58 ) {
if ( V_34 -> V_58 && V_13 -> V_57 -> V_59 )
V_13 -> V_57 -> V_59 ( & V_13 -> V_18 ) ;
else if ( ! V_34 -> V_58 && V_13 -> V_57 -> V_60 )
V_13 -> V_57 -> V_60 ( & V_13 -> V_18 ) ;
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
V_34 = F_9 ( V_97 ) ;
F_31 ( & V_13 -> V_30 , V_81 ) ;
V_13 -> V_38 = ( V_95 != 0 ) ;
F_20 ( V_34 ) ;
F_32 ( & V_13 -> V_30 , V_81 ) ;
F_57 ( F_5 ( V_34 ) ) ;
return 0 ;
}
static void F_58 ( struct V_21 * V_97 ,
enum V_112 V_22 )
{
struct V_17 * V_13 ;
V_13 = F_10 ( & V_97 -> V_19 ) ;
if ( V_113 . V_114 )
V_13 -> V_18 . V_22 = F_59 ( V_115 , V_23 , V_22 ) ;
else if ( V_113 . V_116 )
V_13 -> V_18 . V_22 = F_59 ( V_115 , V_72 , V_22 ) ;
else
V_13 -> V_18 . V_22 = V_73 ;
F_55 ( V_13 ) ;
if ( V_13 -> V_18 . V_22 < V_22 )
F_29 ( F_7 ( V_13 ) , L_17
L_18 ,
F_60 ( V_22 ) ) ;
}
static T_2 F_61 ( struct V_14 * V_19 , struct V_117 * V_118 ,
char * V_91 )
{
struct V_17 * V_13 = F_10 ( V_19 ) ;
if ( ! V_13 -> V_57 || ! V_13 -> V_57 -> V_119 )
return 0 ;
return F_62 ( V_91 , V_120 , L_19 , V_13 -> V_57 -> V_119 ) ;
}
static int F_63 ( struct V_21 * V_121 ,
struct V_122 * V_57 )
{
struct V_9 * V_34 = F_9 ( V_121 ) ;
struct V_17 * V_13 = V_34 -> V_13 ;
if ( V_57 -> V_123 == V_124 )
return - V_69 ;
V_13 -> V_102 = 0 ;
V_13 -> V_57 = V_57 ;
return 0 ;
}
static int F_64 ( struct V_21 * V_121 )
{
struct V_9 * V_34 = F_9 ( V_121 ) ;
struct V_17 * V_13 = V_34 -> V_13 ;
F_65 ( & V_13 -> V_30 ) ;
V_13 -> V_57 = NULL ;
F_66 ( & V_13 -> V_30 ) ;
return 0 ;
}
static void F_67 ( struct V_17 * V_13 )
{
int V_31 ;
F_35 ( & V_13 -> V_18 . V_125 ) ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_31 ] ;
if ( ! V_126 [ V_31 ] . V_65 )
break;
V_4 -> V_4 . V_65 = V_126 [ V_31 ] . V_65 ;
V_4 -> V_4 . V_127 = V_126 [ V_31 ] . V_127 ;
V_4 -> V_4 . V_128 = & V_129 ;
F_41 ( & V_4 -> V_4 . V_125 , & V_13 -> V_18 . V_125 ) ;
V_4 -> V_79 = V_4 -> V_80 = V_4 -> V_130 =
V_4 -> V_131 = 0 ;
F_68 ( & V_4 -> V_4 , ~ 0 ) ;
V_4 -> V_4 . V_132 = 16 ;
V_4 -> V_133 = V_108 ;
V_4 -> V_18 = & V_13 -> V_18 ;
V_4 -> V_62 = NULL ;
F_35 ( & V_4 -> V_26 ) ;
}
V_13 -> V_18 . V_134 = & V_13 -> V_4 [ 0 ] . V_4 ;
F_14 ( & V_13 -> V_4 [ 0 ] . V_4 . V_125 ) ;
F_35 ( & V_13 -> V_88 . V_26 ) ;
#ifdef F_69
V_13 -> V_18 . V_135 = 1 ;
#endif
}
static int F_70 ( struct V_136 * V_137 )
{
struct V_17 * V_13 ;
int V_138 ;
V_13 = * ( ( void * * ) F_71 ( & V_137 -> V_19 ) ) ;
F_72 ( & V_13 -> V_18 , sizeof( struct V_21 ) ) ;
V_13 -> V_18 . V_65 = V_139 ;
V_13 -> V_18 . V_128 = & V_140 ;
V_13 -> V_18 . V_123 = V_23 ;
V_13 -> V_18 . V_19 . V_20 = & V_137 -> V_19 ;
F_67 ( V_13 ) ;
V_138 = F_73 ( & V_137 -> V_19 , & V_13 -> V_18 ) ;
if ( V_138 < 0 )
goto V_141;
V_138 = F_74 ( & V_13 -> V_18 . V_19 , & V_142 ) ;
if ( V_138 < 0 )
goto V_143;
F_75 ( V_137 , V_13 ) ;
return V_138 ;
V_143:
F_76 ( & V_13 -> V_18 ) ;
V_141:
return V_138 ;
}
static int F_77 ( struct V_136 * V_137 )
{
struct V_17 * V_13 = F_78 ( V_137 ) ;
F_79 ( & V_13 -> V_18 . V_19 , & V_142 ) ;
F_76 ( & V_13 -> V_18 ) ;
return 0 ;
}
static void F_80 ( struct V_17 * V_13 , struct V_9 * V_34 ,
int V_59 )
{
F_65 ( & V_13 -> V_30 ) ;
V_13 -> V_39 = V_59 ;
F_20 ( V_34 ) ;
F_66 ( & V_13 -> V_30 ) ;
}
static int F_81 ( struct V_136 * V_137 , T_3 V_144 )
{
struct V_17 * V_13 = F_78 ( V_137 ) ;
struct V_9 * V_34 = F_9 ( & V_13 -> V_18 ) ;
F_29 ( & V_137 -> V_19 , L_19 , V_145 ) ;
F_80 ( V_13 , V_34 , 1 ) ;
F_57 ( F_5 ( V_34 ) ) ;
return 0 ;
}
static int F_82 ( struct V_136 * V_137 )
{
struct V_17 * V_13 = F_78 ( V_137 ) ;
struct V_9 * V_34 = F_9 ( & V_13 -> V_18 ) ;
F_29 ( & V_137 -> V_19 , L_19 , V_145 ) ;
F_80 ( V_13 , V_34 , 0 ) ;
F_57 ( F_5 ( V_34 ) ) ;
return 0 ;
}
static unsigned int F_83 ( const struct V_61 * V_62 )
{
unsigned int V_146 ;
V_146 = F_84 ( V_62 ) << 1 ;
if ( F_85 ( V_62 ) )
V_146 |= 1 ;
return V_146 ;
}
static int F_86 ( struct V_9 * V_34 , struct V_147 * V_147 )
{
const struct V_61 * V_62 = & V_147 -> V_4 -> V_62 ;
T_4 V_146 ;
if ( ! F_27 ( V_62 ) )
return 0 ;
V_146 = F_83 ( V_62 ) ;
return ( 1 << V_146 ) & V_34 -> V_148 ;
}
static int F_87 ( struct V_9 * V_34 ,
unsigned int V_149 )
{
int V_132 ;
V_132 = V_34 -> V_150 [ F_88 ( V_149 ) ] ;
if ( F_89 ( V_149 ) )
V_132 >>= 4 ;
else
V_132 &= 0xf ;
V_132 ++ ;
return V_132 ;
}
static void F_90 ( struct V_9 * V_34 ,
unsigned int V_149 , unsigned int V_151 )
{
int V_132 ;
V_151 -- ;
V_132 = V_34 -> V_150 [ F_88 ( V_149 ) ] ;
if ( F_89 ( V_149 ) ) {
V_151 <<= 4 ;
V_132 &= 0xf ;
} else {
V_132 &= 0xf0 ;
}
V_132 |= V_151 ;
V_34 -> V_150 [ F_88 ( V_149 ) ] = V_132 ;
}
static int F_91 ( struct V_9 * V_34 , struct V_147 * V_147 )
{
unsigned int V_132 ;
int V_152 ;
V_152 = F_86 ( V_34 , V_147 ) ;
if ( ! V_147 -> V_153 ) {
if ( V_152 )
return - V_69 ;
return 0 ;
}
if ( ! V_152 )
return - V_69 ;
V_132 = F_87 ( V_34 ,
F_88 ( V_147 -> V_149 ) ) ;
if ( V_147 -> V_153 > V_132 ) {
F_28 ( F_6 ( V_34 ) , L_20 ,
V_147 -> V_153 ) ;
F_92 () ;
return - V_69 ;
}
return 0 ;
}
static int F_93 (
struct V_10 * V_11 ,
struct V_147 * V_147 ,
T_1 V_82
) {
struct V_9 * V_34 ;
struct V_154 * V_154 ;
unsigned long V_81 ;
int V_138 ;
V_154 = F_94 ( sizeof *V_154 , V_82 ) ;
if ( ! V_154 )
return - V_155 ;
V_154 -> V_147 = V_147 ;
V_154 -> V_156 = 0 ;
V_34 = F_4 ( V_11 ) ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
V_138 = F_91 ( V_34 , V_147 ) ;
if ( V_138 ) {
F_38 ( V_154 ) ;
goto V_71;
}
V_138 = F_95 ( V_11 , V_147 ) ;
if ( V_138 ) {
F_38 ( V_154 ) ;
goto V_71;
}
if ( ! V_34 -> V_157 ) {
V_34 -> V_157 = V_147 -> V_19 ;
F_96 ( V_34 -> V_157 ) ;
} else if ( F_97 ( V_34 -> V_157 != V_147 -> V_19 ) )
F_28 ( F_6 ( V_34 ) , L_21 ) ;
F_41 ( & V_154 -> V_158 , & V_34 -> V_158 ) ;
V_147 -> V_159 = V_154 ;
if ( F_98 ( V_147 -> V_149 ) == V_160 )
V_147 -> V_161 = 1 ;
if ( ! F_99 ( & V_34 -> V_162 ) )
F_53 ( & V_34 -> V_162 , V_108 + 1 ) ;
V_71:
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
return V_138 ;
}
static int F_100 ( struct V_10 * V_11 , struct V_147 * V_147 , int V_28 )
{
struct V_9 * V_34 ;
unsigned long V_81 ;
int V_138 ;
V_34 = F_4 ( V_11 ) ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
V_138 = F_101 ( V_11 , V_147 , V_28 ) ;
if ( ! V_138 && V_34 -> V_46 != V_163 &&
! F_12 ( & V_34 -> V_158 ) )
F_53 ( & V_34 -> V_162 , V_108 ) ;
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
return V_138 ;
}
static int F_102 ( struct V_147 * V_147 , struct V_5 * V_8 ,
T_4 V_164 )
{
void * V_165 , * V_166 ;
struct V_154 * V_154 = V_147 -> V_159 ;
int V_167 ;
struct V_168 * V_169 = & V_154 -> V_169 ;
T_4 V_170 = 0 ;
T_4 V_171 ;
bool V_172 ;
V_167 = F_103 ( V_147 -> V_149 ) ;
V_166 = V_8 -> V_8 . V_91 + V_8 -> V_8 . V_85 ;
if ( ! V_147 -> V_173 ) {
V_165 = V_147 -> V_174 + V_147 -> V_175 ;
if ( V_167 )
memcpy ( V_165 , V_166 , V_164 ) ;
else
memcpy ( V_166 , V_165 , V_164 ) ;
return V_164 ;
}
if ( ! V_154 -> V_156 ) {
T_4 V_81 = V_176 ;
if ( V_167 )
V_81 |= V_177 ;
else
V_81 |= V_178 ;
F_104 ( V_169 , V_147 -> V_179 , V_147 -> V_173 , V_81 ) ;
V_154 -> V_156 = 1 ;
}
V_172 = F_105 ( V_169 ) ;
if ( V_172 == false ) {
F_106 ( 1 ) ;
return - V_69 ;
}
do {
V_165 = V_169 -> V_180 ;
V_171 = F_59 ( T_4 , V_164 , V_169 -> V_89 ) ;
V_169 -> V_181 = V_171 ;
V_170 += V_171 ;
if ( V_167 )
memcpy ( V_165 , V_166 , V_171 ) ;
else
memcpy ( V_166 , V_165 , V_171 ) ;
V_164 -= V_171 ;
if ( ! V_164 )
break;
V_172 = F_105 ( V_169 ) ;
if ( V_172 == false ) {
F_106 ( 1 ) ;
return - V_69 ;
}
V_166 += V_171 ;
} while ( 1 );
F_107 ( V_169 ) ;
return V_170 ;
}
static int F_108 ( struct V_9 * V_34 , struct V_147 * V_147 ,
struct V_1 * V_4 , int V_182 , int * V_28 )
{
struct V_17 * V_13 = V_34 -> V_13 ;
struct V_5 * V_8 ;
int V_183 = 0 ;
V_184:
F_44 (req, &ep->queue, queue) {
unsigned V_185 , V_186 , V_164 ;
int V_187 , V_167 ;
int V_188 = 0 ;
if ( F_86 ( V_34 , V_147 ) ) {
if ( ( V_147 -> V_153 != V_8 -> V_8 . V_153 ) )
continue;
}
V_185 = V_147 -> V_189 - V_147 -> V_175 ;
V_186 = V_8 -> V_8 . V_89 - V_8 -> V_8 . V_85 ;
V_164 = F_109 ( V_185 , V_186 ) ;
V_167 = F_103 ( V_147 -> V_149 ) ;
if ( F_97 ( V_164 == 0 ) )
V_187 = 1 ;
else {
if ( V_182 < V_4 -> V_4 . V_76 && V_182 < V_164 )
break;
V_164 = F_59 ( unsigned , V_164 , V_182 ) ;
if ( V_164 == 0 )
break;
if ( V_164 >= V_4 -> V_4 . V_76 ) {
V_187 = 0 ;
if ( V_164 % V_4 -> V_4 . V_76 )
V_188 = 1 ;
V_164 -= V_164 % V_4 -> V_4 . V_76 ;
} else {
V_187 = 1 ;
}
V_164 = F_102 ( V_147 , V_8 , V_164 ) ;
V_4 -> V_133 = V_108 ;
if ( ( int ) V_164 < 0 ) {
V_8 -> V_8 . V_28 = V_164 ;
} else {
V_182 -= V_164 ;
V_183 += V_164 ;
V_147 -> V_175 += V_164 ;
V_8 -> V_8 . V_85 += V_164 ;
}
}
if ( V_187 ) {
if ( V_185 == V_186 ) {
V_8 -> V_8 . V_28 = 0 ;
* V_28 = 0 ;
} else if ( V_167 ) {
V_8 -> V_8 . V_28 = 0 ;
if ( V_186 > V_185 )
* V_28 = - V_190 ;
else
* V_28 = 0 ;
} else {
* V_28 = 0 ;
if ( V_185 > V_186 )
V_8 -> V_8 . V_28 = - V_190 ;
else
V_8 -> V_8 . V_28 = 0 ;
}
} else {
if ( V_8 -> V_8 . V_89 == V_8 -> V_8 . V_85 ) {
if ( V_8 -> V_8 . V_191 && V_167 )
V_188 = 1 ;
else
V_8 -> V_8 . V_28 = 0 ;
}
if ( V_147 -> V_189 == V_147 -> V_175 ) {
if ( V_147 -> V_192 & V_193 &&
! V_167 )
V_188 = 1 ;
else
* V_28 = 0 ;
}
}
if ( V_8 -> V_8 . V_28 != - V_84 ) {
F_14 ( & V_8 -> V_26 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_16 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_17 ( & V_13 -> V_30 ) ;
V_188 = 1 ;
}
if ( * V_28 != - V_84 )
break;
if ( V_188 )
goto V_184;
}
return V_183 ;
}
static int F_110 ( struct V_17 * V_13 , struct V_1 * V_4 )
{
int V_182 = V_4 -> V_4 . V_76 ;
if ( V_13 -> V_18 . V_22 == V_72 ) {
int V_194 ;
V_194 = F_111 ( V_4 -> V_62 ) ;
V_194 *= 8 ;
V_182 += V_182 * V_194 ;
}
if ( V_13 -> V_18 . V_22 == V_23 ) {
switch ( F_25 ( V_4 -> V_62 ) ) {
case V_75 :
V_182 = 3 * 16 * 1024 * 8 ;
break;
case V_74 :
V_182 = 3 * 1024 * 8 ;
break;
case V_70 :
default:
break;
}
}
return V_182 ;
}
static struct V_1 * F_112 ( struct V_17 * V_13 , V_115 V_32 )
{
int V_31 ;
if ( ! F_113 ( ( V_13 -> V_18 . V_22 == V_23 ?
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
static int F_114 ( struct V_9 * V_34 , struct V_147 * V_147 ,
struct V_195 * V_196 ,
int * V_28 )
{
struct V_1 * V_197 ;
struct V_17 * V_13 = V_34 -> V_13 ;
int V_198 = 1 ;
unsigned V_199 ;
unsigned V_200 ;
V_199 = F_115 ( V_196 -> V_201 ) ;
V_200 = F_115 ( V_196 -> V_202 ) ;
switch ( V_196 -> V_203 ) {
case V_204 :
if ( V_196 -> V_205 != V_206 )
break;
V_13 -> V_32 = V_200 ;
* V_28 = 0 ;
F_29 ( F_7 ( V_13 ) , L_22 ,
V_200 ) ;
V_198 = 0 ;
break;
case V_207 :
if ( V_196 -> V_205 == V_206 ) {
V_198 = 0 ;
switch ( V_200 ) {
case V_104 :
break;
case V_103 :
V_13 -> V_18 . V_208 = 1 ;
break;
case V_209 :
V_13 -> V_18 . V_210 = 1 ;
break;
case V_211 :
V_13 -> V_18 . V_212 = 1 ;
break;
case V_213 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_200 = V_214 ;
else
V_198 = - V_215 ;
break;
case V_216 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_200 = V_217 ;
else
V_198 = - V_215 ;
break;
case V_218 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_200 = V_219 ;
else
V_198 = - V_215 ;
break;
default:
V_198 = - V_215 ;
}
if ( V_198 == 0 ) {
V_13 -> V_102 |= ( 1 << V_200 ) ;
* V_28 = 0 ;
}
} else if ( V_196 -> V_205 == V_220 ) {
V_197 = F_112 ( V_13 , V_199 ) ;
if ( ! V_197 || V_197 -> V_4 . V_65 == V_66 ) {
V_198 = - V_215 ;
break;
}
V_197 -> V_79 = 1 ;
V_198 = 0 ;
* V_28 = 0 ;
}
break;
case V_221 :
if ( V_196 -> V_205 == V_206 ) {
V_198 = 0 ;
switch ( V_200 ) {
case V_104 :
V_200 = V_104 ;
break;
case V_213 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_200 = V_214 ;
else
V_198 = - V_215 ;
break;
case V_216 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_200 = V_217 ;
else
V_198 = - V_215 ;
break;
case V_218 :
if ( F_5 ( V_34 ) -> V_22 ==
V_35 )
V_200 = V_219 ;
else
V_198 = - V_215 ;
break;
default:
V_198 = - V_215 ;
break;
}
if ( V_198 == 0 ) {
V_13 -> V_102 &= ~ ( 1 << V_200 ) ;
* V_28 = 0 ;
}
} else if ( V_196 -> V_205 == V_220 ) {
V_197 = F_112 ( V_13 , V_199 ) ;
if ( ! V_197 ) {
V_198 = - V_215 ;
break;
}
if ( ! V_197 -> V_80 )
V_197 -> V_79 = 0 ;
V_198 = 0 ;
* V_28 = 0 ;
}
break;
case V_222 :
if ( V_196 -> V_205 == V_223
|| V_196 -> V_205 == V_224
|| V_196 -> V_205 == V_225 ) {
char * V_91 ;
V_91 = ( char * ) V_147 -> V_174 ;
if ( V_147 -> V_189 > 0 ) {
if ( V_196 -> V_205 == V_225 ) {
V_197 = F_112 ( V_13 , V_199 ) ;
if ( ! V_197 ) {
V_198 = - V_215 ;
break;
}
V_91 [ 0 ] = V_197 -> V_79 ;
} else if ( V_196 -> V_205 ==
V_223 ) {
V_91 [ 0 ] = ( V_115 ) V_13 -> V_102 ;
} else
V_91 [ 0 ] = 0 ;
}
if ( V_147 -> V_189 > 1 )
V_91 [ 1 ] = 0 ;
V_147 -> V_175 = F_59 ( T_4 , 2 ,
V_147 -> V_189 ) ;
V_198 = 0 ;
* V_28 = 0 ;
}
break;
}
return V_198 ;
}
static void F_116 ( unsigned long V_226 )
{
struct V_9 * V_34 = (struct V_9 * ) V_226 ;
struct V_17 * V_13 = V_34 -> V_13 ;
struct V_154 * V_154 , * V_194 ;
unsigned long V_81 ;
int V_182 , V_227 ;
int V_31 ;
switch ( V_13 -> V_18 . V_22 ) {
case V_228 :
V_227 = 8 * 12 ;
break;
case V_73 :
V_227 = 64 * 19 ;
break;
case V_72 :
V_227 = 512 * 13 * 8 ;
break;
case V_23 :
V_227 = 490000 ;
break;
default:
F_28 ( F_6 ( V_34 ) , L_23 ) ;
return;
}
F_31 ( & V_13 -> V_30 , V_81 ) ;
if ( ! V_34 -> V_157 ) {
F_28 ( F_6 ( V_34 ) ,
L_24 ) ;
F_32 ( & V_13 -> V_30 , V_81 ) ;
return;
}
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
if ( ! V_126 [ V_31 ] . V_65 )
break;
V_13 -> V_4 [ V_31 ] . V_130 = 0 ;
}
V_229:
F_117 (urbp, tmp, &dum_hcd->urbp_list, urbp_list) {
struct V_147 * V_147 ;
struct V_5 * V_8 ;
V_115 V_32 ;
struct V_1 * V_4 = NULL ;
int type ;
int V_28 = - V_84 ;
V_147 = V_154 -> V_147 ;
if ( V_147 -> V_230 )
goto V_231;
else if ( V_34 -> V_46 != V_163 )
continue;
type = F_98 ( V_147 -> V_149 ) ;
if ( V_227 <= 0 && type == V_232 )
continue;
V_32 = F_88 ( V_147 -> V_149 ) ;
if ( F_103 ( V_147 -> V_149 ) )
V_32 |= V_87 ;
V_4 = F_112 ( V_13 , V_32 ) ;
if ( ! V_4 ) {
F_29 ( F_6 ( V_34 ) ,
L_25 ,
V_147 ) ;
V_28 = - V_233 ;
goto V_231;
}
if ( V_4 -> V_130 )
continue;
V_4 -> V_130 = 1 ;
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_147 -> V_161 ) {
V_4 -> V_131 = 1 ;
V_147 -> V_161 = 0 ;
}
if ( V_4 -> V_79 && ! V_4 -> V_131 ) {
F_29 ( F_6 ( V_34 ) , L_26 ,
V_4 -> V_4 . V_65 , V_147 ) ;
V_28 = - V_234 ;
goto V_231;
}
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_4 -> V_131 ) {
struct V_195 V_196 ;
int V_95 = 1 ;
V_196 = * (struct V_195 * ) V_147 -> V_235 ;
F_44 (req, &ep->queue, queue) {
F_14 ( & V_8 -> V_26 ) ;
V_8 -> V_8 . V_28 = - V_190 ;
F_29 ( F_7 ( V_13 ) , L_27 ,
V_8 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_16 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_17 ( & V_13 -> V_30 ) ;
V_4 -> V_130 = 0 ;
goto V_229;
}
V_4 -> V_133 = V_108 ;
V_4 -> V_131 = 0 ;
V_4 -> V_79 = 0 ;
V_95 = F_114 ( V_34 , V_147 , & V_196 ,
& V_28 ) ;
if ( V_95 > 0 ) {
F_15 ( & V_13 -> V_30 ) ;
V_95 = V_13 -> V_57 -> V_196 ( & V_13 -> V_18 ,
& V_196 ) ;
F_17 ( & V_13 -> V_30 ) ;
if ( V_95 >= 0 ) {
V_182 = 64 * 1024 ;
goto V_236;
}
}
if ( V_95 < 0 ) {
if ( V_95 != - V_215 )
F_29 ( F_7 ( V_13 ) ,
L_28 ,
V_95 ) ;
V_28 = - V_234 ;
V_147 -> V_175 = 0 ;
}
goto V_231;
}
V_182 = V_227 ;
switch ( F_98 ( V_147 -> V_149 ) ) {
case V_237 :
V_182 = V_63 ( V_182 , F_110 ( V_13 , V_4 ) ) ;
V_28 = - V_238 ;
break;
case V_239 :
V_182 = V_63 ( V_182 , F_110 ( V_13 , V_4 ) ) ;
default:
V_236:
V_4 -> V_133 = V_108 ;
V_227 -= F_108 ( V_34 , V_147 , V_4 , V_182 , & V_28 ) ;
break;
}
if ( V_28 == - V_84 )
continue;
V_231:
F_118 ( & V_154 -> V_158 ) ;
F_38 ( V_154 ) ;
if ( V_4 )
V_4 -> V_130 = V_4 -> V_131 = 0 ;
F_119 ( F_5 ( V_34 ) , V_147 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_120 ( F_5 ( V_34 ) , V_147 , V_28 ) ;
F_17 ( & V_13 -> V_30 ) ;
goto V_229;
}
if ( F_12 ( & V_34 -> V_158 ) ) {
F_121 ( V_34 -> V_157 ) ;
V_34 -> V_157 = NULL ;
} else if ( V_34 -> V_46 == V_163 ) {
F_53 ( & V_34 -> V_162 , V_108 + F_52 ( 1 ) ) ;
}
F_32 ( & V_13 -> V_30 , V_81 ) ;
}
static int F_122 ( struct V_10 * V_11 , char * V_91 )
{
struct V_9 * V_34 ;
unsigned long V_81 ;
int V_64 = 0 ;
V_34 = F_4 ( V_11 ) ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
if ( ! F_123 ( V_11 ) )
goto V_71;
if ( V_34 -> V_53 && F_124 ( V_108 , V_34 -> V_107 ) ) {
V_34 -> V_36 |= ( V_240 << 16 ) ;
V_34 -> V_36 &= ~ V_52 ;
F_20 ( V_34 ) ;
}
if ( ( V_34 -> V_36 & V_241 ) != 0 ) {
* V_91 = ( 1 << 1 ) ;
F_29 ( F_6 ( V_34 ) , L_29 ,
V_34 -> V_36 ) ;
V_64 = 1 ;
if ( V_34 -> V_46 == V_47 )
F_125 ( V_11 ) ;
}
V_71:
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
return V_64 ;
}
static inline void
F_126 ( struct V_242 * V_62 )
{
memset ( V_62 , 0 , sizeof *V_62 ) ;
V_62 -> V_67 = V_243 ;
V_62 -> V_244 = 12 ;
V_62 -> V_245 = F_127 (
V_246 |
V_247 ) ;
V_62 -> V_248 = 1 ;
V_62 -> V_249 . V_250 . V_251 = 0x04 ;
V_62 -> V_249 . V_250 . V_252 = 0 ;
}
static inline void F_128 ( struct V_242 * V_62 )
{
memset ( V_62 , 0 , sizeof *V_62 ) ;
V_62 -> V_67 = V_253 ;
V_62 -> V_244 = 9 ;
V_62 -> V_245 = F_127 (
V_246 |
V_247 ) ;
V_62 -> V_248 = 1 ;
V_62 -> V_249 . V_254 . V_252 [ 0 ] = 0 ;
V_62 -> V_249 . V_254 . V_252 [ 1 ] = 0xff ;
}
static int F_129 (
struct V_10 * V_11 ,
T_5 V_255 ,
T_5 V_202 ,
T_5 V_201 ,
char * V_91 ,
T_5 V_256
) {
struct V_9 * V_34 ;
int V_64 = 0 ;
unsigned long V_81 ;
if ( ! F_123 ( V_11 ) )
return - V_257 ;
V_34 = F_4 ( V_11 ) ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
switch ( V_255 ) {
case V_258 :
break;
case V_259 :
switch ( V_202 ) {
case V_260 :
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
case V_261 :
F_29 ( F_6 ( V_34 ) , L_32 ) ;
if ( V_11 -> V_22 == V_35 )
V_34 -> V_36 &= ~ V_37 ;
else
V_34 -> V_36 &= ~ V_49 ;
F_20 ( V_34 ) ;
break;
default:
V_34 -> V_36 &= ~ ( 1 << V_202 ) ;
F_20 ( V_34 ) ;
}
break;
case V_262 :
if ( V_11 -> V_22 == V_35 &&
( V_256 < V_263 ||
V_202 != ( V_243 << 8 ) ) ) {
F_29 ( F_6 ( V_34 ) ,
L_33
L_34 ) ;
goto error;
}
if ( V_11 -> V_22 == V_35 )
F_126 ( (struct V_242 * ) V_91 ) ;
else
F_128 ( (struct V_242 * ) V_91 ) ;
break;
case V_264 | V_265 :
if ( V_11 -> V_22 != V_35 )
goto error;
if ( ( V_202 >> 8 ) != V_266 )
goto error;
memcpy ( V_91 , & V_267 , sizeof( V_267 ) ) ;
V_64 = sizeof( V_267 ) ;
break;
case V_268 :
* ( V_269 * ) V_91 = F_130 ( 0 ) ;
break;
case V_270 :
if ( V_201 != 1 )
V_64 = - V_234 ;
if ( V_34 -> V_53 &&
F_124 ( V_108 , V_34 -> V_107 ) ) {
V_34 -> V_36 |= ( V_240 << 16 ) ;
V_34 -> V_36 &= ~ V_52 ;
}
if ( ( V_34 -> V_36 & V_54 ) != 0 &&
F_124 ( V_108 , V_34 -> V_107 ) ) {
V_34 -> V_36 |= ( V_271 << 16 ) ;
V_34 -> V_36 &= ~ V_54 ;
if ( V_34 -> V_13 -> V_38 ) {
V_34 -> V_36 |= V_41 ;
if ( V_11 -> V_22 < V_35 ) {
switch ( V_34 -> V_13 -> V_18 . V_22 ) {
case V_72 :
V_34 -> V_36 |=
V_51 ;
break;
case V_228 :
V_34 -> V_13 -> V_18 . V_134 ->
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
( ( V_272 * ) V_91 ) [ 0 ] = F_127 ( V_34 -> V_36 ) ;
( ( V_272 * ) V_91 ) [ 1 ] = F_127 ( V_34 -> V_36 >> 16 ) ;
break;
case V_273 :
V_64 = - V_234 ;
break;
case V_274 :
switch ( V_202 ) {
case V_275 :
if ( V_11 -> V_22 != V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_35
L_36 ) ;
goto error;
}
break;
case V_276 :
case V_277 :
if ( V_11 -> V_22 != V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_37
L_36 ) ;
goto error;
}
break;
case V_260 :
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
case V_261 :
if ( V_11 -> V_22 == V_35 )
V_34 -> V_36 |= V_37 ;
else
V_34 -> V_36 |= V_49 ;
F_20 ( V_34 ) ;
break;
case V_278 :
if ( V_11 -> V_22 != V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_39
L_36 ) ;
goto error;
}
case V_279 :
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
V_34 -> V_36 |= ( 1 << V_202 ) ;
}
} else
if ( ( V_34 -> V_36 &
V_49 ) != 0 ) {
V_34 -> V_36 |= ( 1 << V_202 ) ;
}
F_20 ( V_34 ) ;
}
break;
case V_280 :
if ( V_11 -> V_22 != V_35 ) {
F_29 ( F_6 ( V_34 ) ,
L_40
L_36 ) ;
goto error;
}
* ( V_269 * ) V_91 = F_130 ( 0 ) ;
break;
case V_281 :
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
V_255 , V_202 , V_201 , V_256 ) ;
error:
V_64 = - V_234 ;
}
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
if ( ( V_34 -> V_36 & V_241 ) != 0 )
F_57 ( V_11 ) ;
return V_64 ;
}
static int F_131 ( struct V_10 * V_11 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
F_29 ( & V_11 -> V_15 . V_282 -> V_19 , L_19 , V_145 ) ;
F_65 ( & V_34 -> V_13 -> V_30 ) ;
V_34 -> V_46 = V_47 ;
F_20 ( V_34 ) ;
V_11 -> V_144 = V_283 ;
F_66 ( & V_34 -> V_13 -> V_30 ) ;
return 0 ;
}
static int F_132 ( struct V_10 * V_11 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
int V_138 = 0 ;
F_29 ( & V_11 -> V_15 . V_282 -> V_19 , L_19 , V_145 ) ;
F_65 ( & V_34 -> V_13 -> V_30 ) ;
if ( ! F_123 ( V_11 ) ) {
V_138 = - V_29 ;
} else {
V_34 -> V_46 = V_163 ;
F_20 ( V_34 ) ;
if ( ! F_12 ( & V_34 -> V_158 ) )
F_53 ( & V_34 -> V_162 , V_108 ) ;
V_11 -> V_144 = V_284 ;
}
F_66 ( & V_34 -> V_13 -> V_30 ) ;
return V_138 ;
}
static inline T_2 F_133 ( char * V_91 , T_6 V_285 , struct V_147 * V_147 )
{
int V_4 = F_88 ( V_147 -> V_149 ) ;
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
static T_2 F_134 ( struct V_14 * V_19 , struct V_117 * V_118 ,
char * V_91 )
{
struct V_10 * V_11 = F_135 ( V_19 ) ;
struct V_9 * V_34 = F_4 ( V_11 ) ;
struct V_154 * V_154 ;
T_6 V_285 = 0 ;
unsigned long V_81 ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
F_44 (urbp, &dum_hcd->urbp_list, urbp_list) {
T_6 V_286 ;
V_286 = F_133 ( V_91 , V_120 - V_285 , V_154 -> V_147 ) ;
V_91 += V_286 ;
V_285 += V_286 ;
}
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
return V_285 ;
}
static int F_136 ( struct V_9 * V_34 )
{
F_137 ( & V_34 -> V_162 ) ;
V_34 -> V_162 . V_119 = F_116 ;
V_34 -> V_162 . V_287 = ( unsigned long ) V_34 ;
V_34 -> V_46 = V_163 ;
V_34 -> V_148 = 0 ;
F_35 ( & V_34 -> V_158 ) ;
F_5 ( V_34 ) -> V_288 = V_289 ;
F_5 ( V_34 ) -> V_144 = V_284 ;
F_5 ( V_34 ) -> V_290 = 1 ;
#ifdef F_69
F_5 ( V_34 ) -> V_15 . V_291 = 1 ;
#endif
return 0 ;
return F_74 ( F_6 ( V_34 ) , & V_292 ) ;
}
static int F_138 ( struct V_10 * V_11 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
if ( ! F_139 ( V_11 ) )
return F_136 ( V_34 ) ;
F_140 ( & V_34 -> V_13 -> V_30 ) ;
F_137 ( & V_34 -> V_162 ) ;
V_34 -> V_162 . V_119 = F_116 ;
V_34 -> V_162 . V_287 = ( unsigned long ) V_34 ;
V_34 -> V_46 = V_163 ;
F_35 ( & V_34 -> V_158 ) ;
V_11 -> V_288 = V_289 ;
V_11 -> V_144 = V_284 ;
V_11 -> V_290 = 1 ;
#ifdef F_69
V_11 -> V_15 . V_291 = 1 ;
#endif
return F_74 ( F_6 ( V_34 ) , & V_292 ) ;
}
static void F_141 ( struct V_10 * V_11 )
{
F_79 ( F_6 ( F_4 ( V_11 ) ) , & V_292 ) ;
F_142 ( F_6 ( F_4 ( V_11 ) ) , L_51 ) ;
}
static int F_143 ( struct V_10 * V_11 )
{
return F_49 ( NULL ) ;
}
static int F_144 ( struct V_10 * V_11 )
{
struct V_17 * V_13 ;
V_13 = * ( ( void * * ) F_71 ( V_11 -> V_15 . V_16 ) ) ;
V_11 -> V_15 . V_293 = ~ 0 ;
if ( F_139 ( V_11 ) ) {
V_13 -> V_25 = F_4 ( V_11 ) ;
V_13 -> V_25 -> V_13 = V_13 ;
V_11 -> V_22 = V_294 ;
V_11 -> V_15 . V_282 -> V_22 = V_72 ;
} else {
V_13 -> V_24 = F_4 ( V_11 ) ;
V_13 -> V_24 -> V_13 = V_13 ;
V_11 -> V_22 = V_35 ;
V_11 -> V_15 . V_282 -> V_22 = V_23 ;
}
return 0 ;
}
static int F_145 ( struct V_10 * V_11 , struct V_295 * V_157 ,
struct V_296 * * V_297 , unsigned int V_298 ,
unsigned int V_299 , T_1 V_82 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
unsigned long V_81 ;
int V_300 ;
int V_301 = V_299 ;
unsigned int V_146 ;
unsigned int V_31 ;
if ( ! V_298 )
return - V_69 ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
for ( V_31 = 0 ; V_31 < V_298 ; V_31 ++ ) {
V_146 = F_83 ( & V_297 [ V_31 ] -> V_62 ) ;
if ( ( 1 << V_146 ) & V_34 -> V_148 ) {
V_301 = - V_69 ;
goto V_302;
}
V_300 = F_26 ( & V_297 [ V_31 ] -> V_303 ) ;
if ( ! V_300 ) {
V_301 = - V_69 ;
goto V_302;
}
if ( V_300 < V_301 ) {
F_29 ( F_6 ( V_34 ) , L_52
L_53 ,
V_297 [ V_31 ] -> V_62 . V_86 ,
V_300 ) ;
V_301 = V_300 ;
}
}
for ( V_31 = 0 ; V_31 < V_298 ; V_31 ++ ) {
V_146 = F_83 ( & V_297 [ V_31 ] -> V_62 ) ;
V_34 -> V_148 |= 1 << V_146 ;
F_90 ( V_34 ,
F_84 ( & V_297 [ V_31 ] -> V_62 ) , V_301 ) ;
}
V_302:
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
return V_301 ;
}
static int F_146 ( struct V_10 * V_11 , struct V_295 * V_157 ,
struct V_296 * * V_297 , unsigned int V_298 ,
T_1 V_82 )
{
struct V_9 * V_34 = F_4 ( V_11 ) ;
unsigned long V_81 ;
int V_304 ;
unsigned int V_146 ;
unsigned int V_31 ;
F_31 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
for ( V_31 = 0 ; V_31 < V_298 ; V_31 ++ ) {
V_146 = F_83 ( & V_297 [ V_31 ] -> V_62 ) ;
if ( ! ( ( 1 << V_146 ) & V_34 -> V_148 ) ) {
V_304 = - V_69 ;
goto V_302;
}
}
for ( V_31 = 0 ; V_31 < V_298 ; V_31 ++ ) {
V_146 = F_83 ( & V_297 [ V_31 ] -> V_62 ) ;
V_34 -> V_148 &= ~ ( 1 << V_146 ) ;
F_90 ( V_34 ,
F_84 ( & V_297 [ V_31 ] -> V_62 ) , 0 ) ;
}
V_304 = 0 ;
V_302:
F_32 ( & V_34 -> V_13 -> V_30 , V_81 ) ;
return V_304 ;
}
static int F_147 ( struct V_136 * V_137 )
{
struct V_17 * V_13 ;
struct V_10 * V_25 ;
struct V_10 * V_24 ;
int V_64 ;
F_142 ( & V_137 -> V_19 , L_54 V_305 L_55 , V_306 ) ;
V_13 = * ( ( void * * ) F_71 ( & V_137 -> V_19 ) ) ;
if ( ! V_113 . V_114 )
V_9 . V_81 = V_294 ;
V_25 = F_148 ( & V_9 , & V_137 -> V_19 , F_149 ( & V_137 -> V_19 ) ) ;
if ( ! V_25 )
return - V_155 ;
V_25 -> V_307 = 1 ;
V_64 = F_150 ( V_25 , 0 , 0 ) ;
if ( V_64 )
goto V_308;
if ( V_113 . V_114 ) {
V_24 = F_151 ( & V_9 , & V_137 -> V_19 ,
F_149 ( & V_137 -> V_19 ) , V_25 ) ;
if ( ! V_24 ) {
V_64 = - V_155 ;
goto V_309;
}
V_64 = F_150 ( V_24 , 0 , 0 ) ;
if ( V_64 )
goto V_310;
}
return 0 ;
V_310:
F_152 ( V_24 ) ;
V_309:
F_153 ( V_25 ) ;
V_308:
F_152 ( V_25 ) ;
V_13 -> V_25 = V_13 -> V_24 = NULL ;
return V_64 ;
}
static int F_154 ( struct V_136 * V_137 )
{
struct V_17 * V_13 ;
V_13 = F_4 ( F_78 ( V_137 ) ) -> V_13 ;
if ( V_13 -> V_24 ) {
F_153 ( F_5 ( V_13 -> V_24 ) ) ;
F_152 ( F_5 ( V_13 -> V_24 ) ) ;
}
F_153 ( F_5 ( V_13 -> V_25 ) ) ;
F_152 ( F_5 ( V_13 -> V_25 ) ) ;
V_13 -> V_25 = NULL ;
V_13 -> V_24 = NULL ;
return 0 ;
}
static int F_155 ( struct V_136 * V_137 , T_3 V_144 )
{
struct V_10 * V_11 ;
struct V_9 * V_34 ;
int V_138 = 0 ;
F_29 ( & V_137 -> V_19 , L_19 , V_145 ) ;
V_11 = F_78 ( V_137 ) ;
V_34 = F_4 ( V_11 ) ;
if ( V_34 -> V_46 == V_163 ) {
F_156 ( & V_137 -> V_19 , L_56 ) ;
V_138 = - V_311 ;
} else
F_157 ( V_312 , & V_11 -> V_81 ) ;
return V_138 ;
}
static int F_158 ( struct V_136 * V_137 )
{
struct V_10 * V_11 ;
F_29 ( & V_137 -> V_19 , L_19 , V_145 ) ;
V_11 = F_78 ( V_137 ) ;
F_159 ( V_312 , & V_11 -> V_81 ) ;
F_57 ( V_11 ) ;
return 0 ;
}
static int T_7 F_160 ( void )
{
int V_64 = - V_155 ;
int V_31 ;
struct V_17 * V_13 [ V_313 ] ;
if ( F_161 () )
return - V_314 ;
if ( ! V_113 . V_116 && V_113 . V_114 )
return - V_69 ;
if ( V_113 . V_315 < 1 || V_113 . V_315 > V_313 ) {
F_162 ( L_57 ,
V_313 ) ;
return - V_69 ;
}
for ( V_31 = 0 ; V_31 < V_113 . V_315 ; V_31 ++ ) {
V_316 [ V_31 ] = F_163 ( V_317 , V_31 ) ;
if ( ! V_316 [ V_31 ] ) {
V_31 -- ;
while ( V_31 >= 0 )
F_164 ( V_316 [ V_31 -- ] ) ;
return V_64 ;
}
}
for ( V_31 = 0 ; V_31 < V_113 . V_315 ; V_31 ++ ) {
V_318 [ V_31 ] = F_163 ( V_139 , V_31 ) ;
if ( ! V_318 [ V_31 ] ) {
V_31 -- ;
while ( V_31 >= 0 )
F_164 ( V_318 [ V_31 -- ] ) ;
goto V_319;
}
}
for ( V_31 = 0 ; V_31 < V_113 . V_315 ; V_31 ++ ) {
V_13 [ V_31 ] = F_34 ( sizeof( struct V_17 ) , V_320 ) ;
if ( ! V_13 [ V_31 ] ) {
V_64 = - V_155 ;
goto V_321;
}
V_64 = F_165 ( V_316 [ V_31 ] , & V_13 [ V_31 ] ,
sizeof( void * ) ) ;
if ( V_64 )
goto V_321;
V_64 = F_165 ( V_318 [ V_31 ] , & V_13 [ V_31 ] ,
sizeof( void * ) ) ;
if ( V_64 )
goto V_321;
}
V_64 = F_166 ( & V_322 ) ;
if ( V_64 < 0 )
goto V_321;
V_64 = F_166 ( & V_323 ) ;
if ( V_64 < 0 )
goto V_324;
for ( V_31 = 0 ; V_31 < V_113 . V_315 ; V_31 ++ ) {
V_64 = F_167 ( V_316 [ V_31 ] ) ;
if ( V_64 < 0 ) {
V_31 -- ;
while ( V_31 >= 0 )
F_168 ( V_316 [ V_31 -- ] ) ;
goto V_325;
}
}
for ( V_31 = 0 ; V_31 < V_113 . V_315 ; V_31 ++ ) {
if ( ! V_13 [ V_31 ] -> V_25 ||
( ! V_13 [ V_31 ] -> V_24 && V_113 . V_114 ) ) {
V_64 = - V_69 ;
goto V_326;
}
}
for ( V_31 = 0 ; V_31 < V_113 . V_315 ; V_31 ++ ) {
V_64 = F_167 ( V_318 [ V_31 ] ) ;
if ( V_64 < 0 ) {
V_31 -- ;
while ( V_31 >= 0 )
F_168 ( V_318 [ V_31 ] ) ;
goto V_326;
}
}
for ( V_31 = 0 ; V_31 < V_113 . V_315 ; V_31 ++ ) {
if ( ! F_78 ( V_318 [ V_31 ] ) ) {
V_64 = - V_69 ;
goto V_327;
}
}
return V_64 ;
V_327:
for ( V_31 = 0 ; V_31 < V_113 . V_315 ; V_31 ++ )
F_168 ( V_318 [ V_31 ] ) ;
V_326:
for ( V_31 = 0 ; V_31 < V_113 . V_315 ; V_31 ++ )
F_168 ( V_316 [ V_31 ] ) ;
V_325:
F_169 ( & V_323 ) ;
V_324:
F_169 ( & V_322 ) ;
V_321:
for ( V_31 = 0 ; V_31 < V_113 . V_315 ; V_31 ++ )
F_38 ( V_13 [ V_31 ] ) ;
for ( V_31 = 0 ; V_31 < V_113 . V_315 ; V_31 ++ )
F_164 ( V_318 [ V_31 ] ) ;
V_319:
for ( V_31 = 0 ; V_31 < V_113 . V_315 ; V_31 ++ )
F_164 ( V_316 [ V_31 ] ) ;
return V_64 ;
}
static void T_8 F_170 ( void )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_113 . V_315 ; V_31 ++ ) {
struct V_17 * V_13 ;
V_13 = * ( ( void * * ) F_71 ( & V_318 [ V_31 ] -> V_19 ) ) ;
F_171 ( V_318 [ V_31 ] ) ;
F_171 ( V_316 [ V_31 ] ) ;
F_38 ( V_13 ) ;
}
F_169 ( & V_323 ) ;
F_169 ( & V_322 ) ;
}
