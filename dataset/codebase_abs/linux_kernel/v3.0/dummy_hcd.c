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
static inline struct V_14 * F_7 ( struct V_9 * V_13 )
{
return V_13 -> V_17 . V_18 . V_19 ;
}
static inline struct V_9 * F_8 ( struct V_1 * V_4 )
{
return F_2 ( V_4 -> V_17 , struct V_9 , V_17 ) ;
}
static inline struct V_9 * F_9 ( struct V_20 * V_17 )
{
return F_2 ( V_17 , struct V_9 , V_17 ) ;
}
static inline struct V_9 * F_10 ( struct V_14 * V_18 )
{
return F_2 ( V_18 , struct V_9 , V_17 . V_18 ) ;
}
static void F_11 ( struct V_9 * V_13 , struct V_1 * V_4 )
{
while ( ! F_12 ( & V_4 -> V_21 ) ) {
struct V_5 * V_8 ;
V_8 = F_13 ( V_4 -> V_21 . V_22 , struct V_5 , V_21 ) ;
F_14 ( & V_8 -> V_21 ) ;
V_8 -> V_8 . V_23 = - V_24 ;
F_15 ( & V_13 -> V_25 ) ;
V_8 -> V_8 . V_26 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_16 ( & V_13 -> V_25 ) ;
}
}
static void
F_17 ( struct V_9 * V_13 )
{
struct V_1 * V_4 ;
V_13 -> V_27 = 0 ;
F_18 (ep, &dum->gadget.ep_list, ep.ep_list)
F_11 ( V_13 , V_4 ) ;
}
static void
F_19 ( struct V_9 * V_13 )
{
V_13 -> V_28 = 0 ;
if ( ( V_13 -> V_29 & V_30 ) == 0 )
V_13 -> V_29 = 0 ;
else if ( ! V_13 -> V_31 || V_13 -> V_32 ) {
V_13 -> V_29 &= ~ ( V_33 |
V_34 |
V_35 |
V_36 |
V_37 ) ;
if ( ( V_13 -> V_38 & V_33 ) != 0 )
V_13 -> V_29 |= ( V_39 << 16 ) ;
} else {
V_13 -> V_29 |= V_33 ;
if ( ( V_13 -> V_38 & V_33 ) == 0 )
V_13 -> V_29 |= ( V_39 << 16 ) ;
if ( ( V_13 -> V_29 & V_34 ) == 0 )
V_13 -> V_29 &= ~ V_37 ;
else if ( ( V_13 -> V_29 & V_37 ) == 0 &&
V_13 -> V_40 != V_41 )
V_13 -> V_28 = 1 ;
}
if ( ( V_13 -> V_29 & V_34 ) == 0 || V_13 -> V_28 )
V_13 -> V_42 = 0 ;
if ( ( V_13 -> V_29 & V_33 ) == 0 ||
( V_13 -> V_29 & V_43 ) != 0 ) {
if ( ( V_13 -> V_38 & V_33 ) != 0 &&
( V_13 -> V_38 & V_43 ) == 0 &&
V_13 -> V_44 ) {
F_17 ( V_13 ) ;
F_15 ( & V_13 -> V_25 ) ;
V_13 -> V_44 -> V_45 ( & V_13 -> V_17 ) ;
F_16 ( & V_13 -> V_25 ) ;
}
} else if ( V_13 -> V_28 != V_13 -> V_46 ) {
if ( V_13 -> V_46 && V_13 -> V_44 -> V_47 ) {
F_15 ( & V_13 -> V_25 ) ;
V_13 -> V_44 -> V_47 ( & V_13 -> V_17 ) ;
F_16 ( & V_13 -> V_25 ) ;
} else if ( ! V_13 -> V_46 && V_13 -> V_44 -> V_48 ) {
F_15 ( & V_13 -> V_25 ) ;
V_13 -> V_44 -> V_48 ( & V_13 -> V_17 ) ;
F_16 ( & V_13 -> V_25 ) ;
}
}
V_13 -> V_38 = V_13 -> V_29 ;
V_13 -> V_46 = V_13 -> V_28 ;
}
static int
F_20 ( struct V_2 * V_3 , const struct V_49 * V_50 )
{
struct V_9 * V_13 ;
struct V_1 * V_4 ;
unsigned V_51 ;
int V_52 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_50 || V_4 -> V_50 || V_3 -> V_53 == V_54
|| V_50 -> V_55 != V_56 )
return - V_57 ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_44 || ! F_21 ( V_13 ) )
return - V_24 ;
V_51 = F_22 ( V_50 -> V_58 ) & 0x3ff ;
V_52 = - V_57 ;
switch ( V_50 -> V_59 & 0x03 ) {
case V_60 :
if ( strstr ( V_4 -> V_4 . V_53 , L_1 )
|| strstr ( V_4 -> V_4 . V_53 , L_2 ) ) {
goto V_61;
}
switch ( V_13 -> V_17 . V_62 ) {
case V_63 :
if ( V_51 == 512 )
break;
goto V_61;
case V_64 :
if ( V_51 == 8 || V_51 == 16 || V_51 == 32 || V_51 == 64 )
break;
default:
goto V_61;
}
break;
case V_65 :
if ( strstr ( V_4 -> V_4 . V_53 , L_1 ) )
goto V_61;
switch ( V_13 -> V_17 . V_62 ) {
case V_63 :
if ( V_51 <= 1024 )
break;
case V_64 :
if ( V_51 <= 64 )
break;
default:
if ( V_51 <= 8 )
break;
goto V_61;
}
break;
case V_66 :
if ( strstr ( V_4 -> V_4 . V_53 , L_3 )
|| strstr ( V_4 -> V_4 . V_53 , L_2 ) )
goto V_61;
switch ( V_13 -> V_17 . V_62 ) {
case V_63 :
if ( V_51 <= 1024 )
break;
case V_64 :
if ( V_51 <= 1023 )
break;
default:
goto V_61;
}
break;
default:
goto V_61;
}
V_3 -> V_67 = V_51 ;
V_4 -> V_50 = V_50 ;
F_23 (udc_dev(dum), L_4 ,
_ep->name,
desc->bEndpointAddress & 0x0f ,
(desc->bEndpointAddress & USB_DIR_IN) ? L_5 : L_6 ,
({ char *val;
switch (desc->bmAttributes & 0x03) {
case USB_ENDPOINT_XFER_BULK: val = L_7; break;
case USB_ENDPOINT_XFER_ISOC: val = L_8; break;
case USB_ENDPOINT_XFER_INT: val = L_9; break;
default: val = L_10; break;
}; val; }),
max) ;
V_4 -> V_68 = V_4 -> V_69 = 0 ;
V_52 = 0 ;
V_61:
return V_52 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_9 * V_13 ;
unsigned long V_70 ;
int V_52 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ! V_4 -> V_50 || V_3 -> V_53 == V_54 )
return - V_57 ;
V_13 = F_8 ( V_4 ) ;
F_25 ( & V_13 -> V_25 , V_70 ) ;
V_4 -> V_50 = NULL ;
V_52 = 0 ;
F_11 ( V_13 , V_4 ) ;
F_26 ( & V_13 -> V_25 , V_70 ) ;
F_23 ( F_7 ( V_13 ) , L_11 , V_3 -> V_53 ) ;
return V_52 ;
}
static struct V_6 *
F_27 ( struct V_2 * V_3 , T_1 V_71 )
{
struct V_1 * V_4 ;
struct V_5 * V_8 ;
if ( ! V_3 )
return NULL ;
V_4 = F_1 ( V_3 ) ;
V_8 = F_28 ( sizeof( * V_8 ) , V_71 ) ;
if ( ! V_8 )
return NULL ;
F_29 ( & V_8 -> V_21 ) ;
return & V_8 -> V_8 ;
}
static void
F_30 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_1 * V_4 ;
struct V_5 * V_8 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || ! V_7 || ( ! V_4 -> V_50 && V_3 -> V_53 != V_54 ) )
return;
V_8 = F_3 ( V_7 ) ;
F_31 ( ! F_12 ( & V_8 -> V_21 ) ) ;
F_32 ( V_8 ) ;
}
static void
F_33 ( struct V_2 * V_4 , struct V_6 * V_8 )
{
}
static int
F_34 ( struct V_2 * V_3 , struct V_6 * V_7 ,
T_1 V_71 )
{
struct V_1 * V_4 ;
struct V_5 * V_8 ;
struct V_9 * V_13 ;
unsigned long V_70 ;
V_8 = F_3 ( V_7 ) ;
if ( ! V_7 || ! F_12 ( & V_8 -> V_21 ) || ! V_7 -> V_26 )
return - V_57 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_3 || ( ! V_4 -> V_50 && V_3 -> V_53 != V_54 ) )
return - V_57 ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_44 || ! F_21 ( V_13 ) )
return - V_24 ;
#if 0
dev_dbg (udc_dev(dum), "ep %p queue req %p to %s, len %d buf %p\n",
ep, _req, _ep->name, _req->length, _req->buf);
#endif
V_7 -> V_23 = - V_72 ;
V_7 -> V_73 = 0 ;
F_25 ( & V_13 -> V_25 , V_70 ) ;
if ( V_4 -> V_50 && ( V_4 -> V_50 -> V_74 & V_75 ) &&
F_12 ( & V_13 -> V_76 . V_21 ) &&
F_12 ( & V_4 -> V_21 ) &&
V_7 -> V_77 <= V_78 ) {
V_8 = & V_13 -> V_76 ;
V_8 -> V_8 = * V_7 ;
V_8 -> V_8 . V_79 = V_13 -> V_80 ;
memcpy ( V_13 -> V_80 , V_7 -> V_79 , V_7 -> V_77 ) ;
V_8 -> V_8 . V_81 = V_13 ;
V_8 -> V_8 . V_26 = F_33 ;
F_35 ( & V_8 -> V_21 , & V_4 -> V_21 ) ;
F_15 ( & V_13 -> V_25 ) ;
V_7 -> V_73 = V_7 -> V_77 ;
V_7 -> V_23 = 0 ;
V_7 -> V_26 ( V_3 , V_7 ) ;
F_16 ( & V_13 -> V_25 ) ;
} else
F_35 ( & V_8 -> V_21 , & V_4 -> V_21 ) ;
F_26 ( & V_13 -> V_25 , V_70 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_1 * V_4 ;
struct V_9 * V_13 ;
int V_52 = - V_57 ;
unsigned long V_70 ;
struct V_5 * V_8 = NULL ;
if ( ! V_3 || ! V_7 )
return V_52 ;
V_4 = F_1 ( V_3 ) ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_44 )
return - V_24 ;
F_37 ( V_70 ) ;
F_16 ( & V_13 -> V_25 ) ;
F_18 (req, &ep->queue, queue) {
if ( & V_8 -> V_8 == V_7 ) {
F_14 ( & V_8 -> V_21 ) ;
V_7 -> V_23 = - V_82 ;
V_52 = 0 ;
break;
}
}
F_15 ( & V_13 -> V_25 ) ;
if ( V_52 == 0 ) {
F_23 ( F_7 ( V_13 ) ,
L_12 ,
V_8 , V_3 -> V_53 , V_7 -> V_77 , V_7 -> V_79 ) ;
V_7 -> V_26 ( V_3 , V_7 ) ;
}
F_38 ( V_70 ) ;
return V_52 ;
}
static int
F_39 ( struct V_2 * V_3 , int V_83 , int V_69 )
{
struct V_1 * V_4 ;
struct V_9 * V_13 ;
if ( ! V_3 )
return - V_57 ;
V_4 = F_1 ( V_3 ) ;
V_13 = F_8 ( V_4 ) ;
if ( ! V_13 -> V_44 )
return - V_24 ;
if ( ! V_83 )
V_4 -> V_68 = V_4 -> V_69 = 0 ;
else if ( V_4 -> V_50 && ( V_4 -> V_50 -> V_74 & V_75 ) &&
! F_12 ( & V_4 -> V_21 ) )
return - V_84 ;
else {
V_4 -> V_68 = 1 ;
if ( V_69 )
V_4 -> V_69 = 1 ;
}
return 0 ;
}
static int
F_40 ( struct V_2 * V_3 , int V_83 )
{
return F_39 ( V_3 , V_83 , 0 ) ;
}
static int F_41 ( struct V_2 * V_3 )
{
if ( ! V_3 || V_3 -> V_53 == V_54 )
return - V_57 ;
return F_39 ( V_3 , 1 , 1 ) ;
}
static int F_42 ( struct V_20 * V_85 )
{
struct V_86 V_87 ;
F_43 ( & V_87 ) ;
return V_87 . V_88 / 1000 ;
}
static int F_44 ( struct V_20 * V_85 )
{
struct V_9 * V_13 ;
V_13 = F_9 ( V_85 ) ;
if ( ! ( V_13 -> V_89 & ( ( 1 << V_90 )
| ( 1 << V_91 ) ) ) )
return - V_57 ;
if ( ( V_13 -> V_29 & V_33 ) == 0 )
return - V_92 ;
if ( ( V_13 -> V_29 & V_37 ) == 0 &&
V_13 -> V_40 != V_41 )
return - V_93 ;
V_13 -> V_42 = 1 ;
V_13 -> V_94 = V_95 + F_45 ( 20 ) ;
F_46 ( & F_5 ( V_13 ) -> V_96 , V_13 -> V_94 ) ;
return 0 ;
}
static int F_47 ( struct V_20 * V_85 , int V_83 )
{
struct V_9 * V_13 ;
V_13 = F_9 ( V_85 ) ;
if ( V_83 )
V_13 -> V_89 |= ( 1 << V_97 ) ;
else
V_13 -> V_89 &= ~ ( 1 << V_97 ) ;
return 0 ;
}
static int F_48 ( struct V_20 * V_85 , int V_83 )
{
struct V_9 * V_13 ;
unsigned long V_70 ;
V_13 = F_9 ( V_85 ) ;
F_25 ( & V_13 -> V_25 , V_70 ) ;
V_13 -> V_31 = ( V_83 != 0 ) ;
F_19 ( V_13 ) ;
F_26 ( & V_13 -> V_25 , V_70 ) ;
F_49 ( F_5 ( V_13 ) ) ;
return 0 ;
}
static T_2
F_50 ( struct V_14 * V_18 , struct V_98 * V_99 , char * V_79 )
{
struct V_9 * V_13 = F_10 ( V_18 ) ;
if ( ! V_13 -> V_44 || ! V_13 -> V_44 -> V_100 )
return 0 ;
return F_51 ( V_79 , V_101 , L_13 , V_13 -> V_44 -> V_100 ) ;
}
int
F_52 ( struct V_102 * V_44 ,
int (* F_53)( struct V_20 * ) )
{
struct V_9 * V_13 = V_103 ;
int V_52 , V_104 ;
if ( ! V_13 )
return - V_57 ;
if ( V_13 -> V_44 )
return - V_105 ;
if ( ! F_53 || ! V_44 -> V_106 || V_44 -> V_62 == V_107 )
return - V_57 ;
V_13 -> V_89 = 0 ;
F_29 ( & V_13 -> V_17 . V_108 ) ;
for ( V_104 = 0 ; V_104 < V_109 ; V_104 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_104 ] ;
if ( ! V_110 [ V_104 ] )
break;
V_4 -> V_4 . V_53 = V_110 [ V_104 ] ;
V_4 -> V_4 . V_111 = & V_112 ;
F_35 ( & V_4 -> V_4 . V_108 , & V_13 -> V_17 . V_108 ) ;
V_4 -> V_68 = V_4 -> V_69 = V_4 -> V_113 =
V_4 -> V_114 = 0 ;
V_4 -> V_4 . V_67 = ~ 0 ;
V_4 -> V_115 = V_95 ;
V_4 -> V_17 = & V_13 -> V_17 ;
V_4 -> V_50 = NULL ;
F_29 ( & V_4 -> V_21 ) ;
}
V_13 -> V_17 . V_116 = & V_13 -> V_4 [ 0 ] . V_4 ;
V_13 -> V_4 [ 0 ] . V_4 . V_67 = 64 ;
F_14 ( & V_13 -> V_4 [ 0 ] . V_4 . V_108 ) ;
F_29 ( & V_13 -> V_76 . V_21 ) ;
V_44 -> V_44 . V_117 = NULL ;
V_13 -> V_44 = V_44 ;
V_13 -> V_17 . V_18 . V_44 = & V_44 -> V_44 ;
F_23 ( F_7 ( V_13 ) , L_14 ,
V_44 -> V_44 . V_53 ) ;
V_52 = F_53 ( & V_13 -> V_17 ) ;
if ( V_52 ) {
V_13 -> V_44 = NULL ;
V_13 -> V_17 . V_18 . V_44 = NULL ;
return V_52 ;
}
F_54 ( & V_13 -> V_25 ) ;
V_13 -> V_31 = 1 ;
F_19 ( V_13 ) ;
F_55 ( & V_13 -> V_25 ) ;
F_49 ( F_5 ( V_13 ) ) ;
return 0 ;
}
int
F_56 ( struct V_102 * V_44 )
{
struct V_9 * V_13 = V_103 ;
unsigned long V_70 ;
if ( ! V_13 )
return - V_118 ;
if ( ! V_44 || V_44 != V_13 -> V_44 || ! V_44 -> V_119 )
return - V_57 ;
F_23 ( F_7 ( V_13 ) , L_15 ,
V_44 -> V_44 . V_53 ) ;
F_25 ( & V_13 -> V_25 , V_70 ) ;
V_13 -> V_31 = 0 ;
F_19 ( V_13 ) ;
F_26 ( & V_13 -> V_25 , V_70 ) ;
V_44 -> V_119 ( & V_13 -> V_17 ) ;
V_13 -> V_17 . V_18 . V_44 = NULL ;
V_13 -> V_44 = NULL ;
F_25 ( & V_13 -> V_25 , V_70 ) ;
V_13 -> V_31 = 0 ;
F_19 ( V_13 ) ;
F_26 ( & V_13 -> V_25 , V_70 ) ;
F_49 ( F_5 ( V_13 ) ) ;
return 0 ;
}
int F_57 ( struct V_20 * V_17 , int V_120 )
{
return - V_121 ;
}
static void
F_58 ( struct V_14 * V_18 )
{
struct V_9 * V_13 = F_10 ( V_18 ) ;
F_59 ( F_5 ( V_13 ) ) ;
}
static int F_60 ( struct V_122 * V_123 )
{
struct V_9 * V_13 = V_103 ;
int V_124 ;
F_61 ( F_5 ( V_13 ) ) ;
V_13 -> V_17 . V_53 = V_125 ;
V_13 -> V_17 . V_111 = & V_126 ;
V_13 -> V_17 . V_127 = 1 ;
V_13 -> V_17 . V_128 = ( F_5 ( V_13 ) -> V_15 . V_129 != 0 ) ;
F_62 ( & V_13 -> V_17 . V_18 , L_16 ) ;
V_13 -> V_17 . V_18 . V_19 = & V_123 -> V_18 ;
V_13 -> V_17 . V_18 . V_130 = F_58 ;
V_124 = F_63 ( & V_13 -> V_17 . V_18 ) ;
if ( V_124 < 0 ) {
F_64 ( & V_13 -> V_17 . V_18 ) ;
return V_124 ;
}
V_124 = F_65 ( & V_13 -> V_17 . V_18 , & V_131 ) ;
if ( V_124 < 0 )
F_66 ( & V_13 -> V_17 . V_18 ) ;
else
F_67 ( V_123 , V_13 ) ;
return V_124 ;
}
static int F_68 ( struct V_122 * V_123 )
{
struct V_9 * V_13 = F_69 ( V_123 ) ;
F_67 ( V_123 , NULL ) ;
F_70 ( & V_13 -> V_17 . V_18 , & V_131 ) ;
F_66 ( & V_13 -> V_17 . V_18 ) ;
return 0 ;
}
static int F_71 ( struct V_122 * V_123 , T_3 V_132 )
{
struct V_9 * V_13 = F_69 ( V_123 ) ;
F_23 ( & V_123 -> V_18 , L_13 , V_133 ) ;
F_54 ( & V_13 -> V_25 ) ;
V_13 -> V_32 = 1 ;
F_19 ( V_13 ) ;
F_55 ( & V_13 -> V_25 ) ;
F_49 ( F_5 ( V_13 ) ) ;
return 0 ;
}
static int F_72 ( struct V_122 * V_123 )
{
struct V_9 * V_13 = F_69 ( V_123 ) ;
F_23 ( & V_123 -> V_18 , L_13 , V_133 ) ;
F_54 ( & V_13 -> V_25 ) ;
V_13 -> V_32 = 0 ;
F_19 ( V_13 ) ;
F_55 ( & V_13 -> V_25 ) ;
F_49 ( F_5 ( V_13 ) ) ;
return 0 ;
}
static int F_73 (
struct V_10 * V_11 ,
struct V_134 * V_134 ,
T_1 V_71
) {
struct V_9 * V_13 ;
struct V_135 * V_135 ;
unsigned long V_70 ;
int V_124 ;
if ( ! V_134 -> V_136 && V_134 -> V_137 )
return - V_57 ;
V_135 = F_74 ( sizeof *V_135 , V_71 ) ;
if ( ! V_135 )
return - V_138 ;
V_135 -> V_134 = V_134 ;
V_13 = F_4 ( V_11 ) ;
F_25 ( & V_13 -> V_25 , V_70 ) ;
V_124 = F_75 ( V_11 , V_134 ) ;
if ( V_124 ) {
F_32 ( V_135 ) ;
goto V_61;
}
if ( ! V_13 -> V_139 ) {
V_13 -> V_139 = V_134 -> V_18 ;
F_76 ( V_13 -> V_139 ) ;
} else if ( F_77 ( V_13 -> V_139 != V_134 -> V_18 ) )
F_78 ( F_6 ( V_13 ) , L_17 ) ;
F_35 ( & V_135 -> V_140 , & V_13 -> V_140 ) ;
V_134 -> V_141 = V_135 ;
if ( F_79 ( V_134 -> V_142 ) == V_143 )
V_134 -> V_144 = 1 ;
if ( ! F_80 ( & V_13 -> V_145 ) )
F_46 ( & V_13 -> V_145 , V_95 + 1 ) ;
V_61:
F_26 ( & V_13 -> V_25 , V_70 ) ;
return V_124 ;
}
static int F_81 ( struct V_10 * V_11 , struct V_134 * V_134 , int V_23 )
{
struct V_9 * V_13 ;
unsigned long V_70 ;
int V_124 ;
V_13 = F_4 ( V_11 ) ;
F_25 ( & V_13 -> V_25 , V_70 ) ;
V_124 = F_82 ( V_11 , V_134 , V_23 ) ;
if ( ! V_124 && V_13 -> V_40 != V_146 &&
! F_12 ( & V_13 -> V_140 ) )
F_46 ( & V_13 -> V_145 , V_95 ) ;
F_26 ( & V_13 -> V_25 , V_70 ) ;
return V_124 ;
}
static int
F_83 ( struct V_9 * V_13 , struct V_134 * V_134 , struct V_1 * V_4 , int V_147 ,
int * V_23 )
{
struct V_5 * V_8 ;
V_148:
F_18 (req, &ep->queue, queue) {
unsigned V_149 , V_150 , V_151 ;
int V_152 , V_153 ;
int V_154 = 0 ;
V_149 = V_134 -> V_137 - V_134 -> V_155 ;
V_150 = V_8 -> V_8 . V_77 - V_8 -> V_8 . V_73 ;
V_151 = F_84 ( V_149 , V_150 ) ;
V_153 = F_85 ( V_134 -> V_142 ) ;
if ( F_77 ( V_151 == 0 ) )
V_152 = 1 ;
else {
char * V_156 , * V_157 ;
if ( V_147 < V_4 -> V_4 . V_67 && V_147 < V_151 )
break;
V_151 = F_84 ( V_151 , ( unsigned ) V_147 ) ;
if ( V_151 == 0 )
break;
if ( V_151 > V_4 -> V_4 . V_67 ) {
V_154 = 1 ;
V_151 -= ( V_151 % V_4 -> V_4 . V_67 ) ;
}
V_152 = ( V_151 % V_4 -> V_4 . V_67 ) != 0 ;
V_156 = V_134 -> V_136 + V_134 -> V_155 ;
V_157 = V_8 -> V_8 . V_79 + V_8 -> V_8 . V_73 ;
if ( V_153 )
memcpy ( V_156 , V_157 , V_151 ) ;
else
memcpy ( V_157 , V_156 , V_151 ) ;
V_4 -> V_115 = V_95 ;
V_147 -= V_151 ;
V_134 -> V_155 += V_151 ;
V_8 -> V_8 . V_73 += V_151 ;
}
if ( V_152 ) {
if ( V_149 == V_150 ) {
V_8 -> V_8 . V_23 = 0 ;
* V_23 = 0 ;
} else if ( V_153 ) {
V_8 -> V_8 . V_23 = 0 ;
if ( V_150 > V_149 )
* V_23 = - V_158 ;
else
* V_23 = 0 ;
} else if ( ! V_153 ) {
* V_23 = 0 ;
if ( V_149 > V_150 )
V_8 -> V_8 . V_23 = - V_158 ;
else
V_8 -> V_8 . V_23 = 0 ;
}
} else {
if ( V_8 -> V_8 . V_77 == V_8 -> V_8 . V_73
&& ! V_8 -> V_8 . V_159 )
V_8 -> V_8 . V_23 = 0 ;
if ( V_134 -> V_137 == V_134 -> V_155
&& ! ( V_134 -> V_160
& V_161 ) )
* V_23 = 0 ;
}
if ( V_8 -> V_8 . V_23 != - V_72 ) {
F_14 ( & V_8 -> V_21 ) ;
F_15 ( & V_13 -> V_25 ) ;
V_8 -> V_8 . V_26 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_16 ( & V_13 -> V_25 ) ;
V_154 = 1 ;
}
if ( * V_23 != - V_72 )
break;
if ( V_154 )
goto V_148;
}
return V_147 ;
}
static int F_86 ( struct V_9 * V_13 , struct V_1 * V_4 )
{
int V_147 = V_4 -> V_4 . V_67 ;
if ( V_13 -> V_17 . V_62 == V_63 ) {
int V_162 ;
V_162 = F_22 ( V_4 -> V_50 -> V_58 ) ;
V_162 = ( V_162 >> 11 ) & 0x03 ;
V_162 *= 8 ;
V_147 += V_147 * V_162 ;
}
return V_147 ;
}
static struct V_1 * F_87 ( struct V_9 * V_13 , T_4 V_27 )
{
int V_104 ;
if ( ! F_88 ( V_13 ) )
return NULL ;
if ( ( V_27 & ~ V_75 ) == 0 )
return & V_13 -> V_4 [ 0 ] ;
for ( V_104 = 1 ; V_104 < V_109 ; V_104 ++ ) {
struct V_1 * V_4 = & V_13 -> V_4 [ V_104 ] ;
if ( ! V_4 -> V_50 )
continue;
if ( V_4 -> V_50 -> V_74 == V_27 )
return V_4 ;
}
return NULL ;
}
static int F_89 ( struct V_9 * V_13 , struct V_134 * V_134 ,
struct V_163 * V_106 ,
int * V_23 )
{
struct V_1 * V_164 ;
int V_165 = 1 ;
unsigned V_166 ;
unsigned V_167 ;
V_166 = F_22 ( V_106 -> V_168 ) ;
V_167 = F_22 ( V_106 -> V_169 ) ;
switch ( V_106 -> V_170 ) {
case V_171 :
if ( V_106 -> V_172 != V_173 )
break;
V_13 -> V_27 = V_167 ;
* V_23 = 0 ;
F_23 ( F_7 ( V_13 ) , L_18 ,
V_167 ) ;
V_165 = 0 ;
break;
case V_174 :
if ( V_106 -> V_172 == V_173 ) {
V_165 = 0 ;
switch ( V_167 ) {
case V_91 :
break;
case V_90 :
V_13 -> V_17 . V_175 = 1 ;
break;
case V_176 :
V_13 -> V_17 . V_177 = 1 ;
break;
case V_178 :
V_13 -> V_17 . V_179 = 1 ;
break;
default:
V_165 = - V_180 ;
}
if ( V_165 == 0 ) {
V_13 -> V_89 |= ( 1 << V_167 ) ;
* V_23 = 0 ;
}
} else if ( V_106 -> V_172 == V_181 ) {
V_164 = F_87 ( V_13 , V_166 ) ;
if ( ! V_164 || V_164 -> V_4 . V_53 == V_54 ) {
V_165 = - V_180 ;
break;
}
V_164 -> V_68 = 1 ;
V_165 = 0 ;
* V_23 = 0 ;
}
break;
case V_182 :
if ( V_106 -> V_172 == V_173 ) {
V_165 = 0 ;
switch ( V_167 ) {
case V_91 :
V_167 = V_91 ;
break;
default:
V_165 = - V_180 ;
break;
}
if ( V_165 == 0 ) {
V_13 -> V_89 &= ~ ( 1 << V_167 ) ;
* V_23 = 0 ;
}
} else if ( V_106 -> V_172 == V_181 ) {
V_164 = F_87 ( V_13 , V_166 ) ;
if ( ! V_164 ) {
V_165 = - V_180 ;
break;
}
if ( ! V_164 -> V_69 )
V_164 -> V_68 = 0 ;
V_165 = 0 ;
* V_23 = 0 ;
}
break;
case V_183 :
if ( V_106 -> V_172 == V_184
|| V_106 -> V_172 == V_185
|| V_106 -> V_172 == V_186 ) {
char * V_79 ;
V_79 = ( char * ) V_134 -> V_136 ;
if ( V_134 -> V_137 > 0 ) {
if ( V_106 -> V_172 == V_186 ) {
V_164 = F_87 ( V_13 , V_166 ) ;
if ( ! V_164 ) {
V_165 = - V_180 ;
break;
}
V_79 [ 0 ] = V_164 -> V_68 ;
} else if ( V_106 -> V_172 ==
V_184 ) {
V_79 [ 0 ] = ( T_4 ) V_13 -> V_89 ;
} else
V_79 [ 0 ] = 0 ;
}
if ( V_134 -> V_137 > 1 )
V_79 [ 1 ] = 0 ;
V_134 -> V_155 = F_90 ( V_187 , 2 ,
V_134 -> V_137 ) ;
V_165 = 0 ;
* V_23 = 0 ;
}
break;
}
return V_165 ;
}
static void F_91 ( unsigned long V_188 )
{
struct V_9 * V_13 = (struct V_9 * ) V_188 ;
struct V_135 * V_135 , * V_162 ;
unsigned long V_70 ;
int V_147 , V_189 ;
int V_104 ;
switch ( V_13 -> V_17 . V_62 ) {
case V_190 :
V_189 = 8 * 12 ;
break;
case V_64 :
V_189 = 64 * 19 ;
break;
case V_63 :
V_189 = 512 * 13 * 8 ;
break;
default:
F_78 ( F_6 ( V_13 ) , L_19 ) ;
return;
}
F_25 ( & V_13 -> V_25 , V_70 ) ;
if ( ! V_13 -> V_139 ) {
F_78 ( F_6 ( V_13 ) ,
L_20 ) ;
F_26 ( & V_13 -> V_25 , V_70 ) ;
return;
}
for ( V_104 = 0 ; V_104 < V_109 ; V_104 ++ ) {
if ( ! V_110 [ V_104 ] )
break;
V_13 -> V_4 [ V_104 ] . V_113 = 0 ;
}
V_191:
F_92 (urbp, tmp, &dum->urbp_list, urbp_list) {
struct V_134 * V_134 ;
struct V_5 * V_8 ;
T_4 V_27 ;
struct V_1 * V_4 = NULL ;
int type ;
int V_23 = - V_72 ;
V_134 = V_135 -> V_134 ;
if ( V_134 -> V_192 )
goto V_193;
else if ( V_13 -> V_40 != V_146 )
continue;
type = F_79 ( V_134 -> V_142 ) ;
if ( V_189 <= 0 && type == V_194 )
continue;
V_27 = F_93 ( V_134 -> V_142 ) ;
if ( F_85 ( V_134 -> V_142 ) )
V_27 |= V_75 ;
V_4 = F_87 ( V_13 , V_27 ) ;
if ( ! V_4 ) {
F_23 ( F_6 ( V_13 ) ,
L_21 ,
V_134 ) ;
V_23 = - V_195 ;
goto V_193;
}
if ( V_4 -> V_113 )
continue;
V_4 -> V_113 = 1 ;
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_134 -> V_144 ) {
V_4 -> V_114 = 1 ;
V_134 -> V_144 = 0 ;
}
if ( V_4 -> V_68 && ! V_4 -> V_114 ) {
F_23 ( F_6 ( V_13 ) , L_22 ,
V_4 -> V_4 . V_53 , V_134 ) ;
V_23 = - V_196 ;
goto V_193;
}
if ( V_4 == & V_13 -> V_4 [ 0 ] && V_4 -> V_114 ) {
struct V_163 V_106 ;
int V_83 = 1 ;
V_106 = * (struct V_163 * ) V_134 -> V_197 ;
F_18 (req, &ep->queue, queue) {
F_14 ( & V_8 -> V_21 ) ;
V_8 -> V_8 . V_23 = - V_158 ;
F_23 ( F_7 ( V_13 ) , L_23 ,
V_8 ) ;
F_15 ( & V_13 -> V_25 ) ;
V_8 -> V_8 . V_26 ( & V_4 -> V_4 , & V_8 -> V_8 ) ;
F_16 ( & V_13 -> V_25 ) ;
V_4 -> V_113 = 0 ;
goto V_191;
}
V_4 -> V_115 = V_95 ;
V_4 -> V_114 = 0 ;
V_4 -> V_68 = 0 ;
V_83 = F_89 ( V_13 , V_134 , & V_106 ,
& V_23 ) ;
if ( V_83 > 0 ) {
F_15 ( & V_13 -> V_25 ) ;
V_83 = V_13 -> V_44 -> V_106 ( & V_13 -> V_17 ,
& V_106 ) ;
F_16 ( & V_13 -> V_25 ) ;
if ( V_83 >= 0 ) {
V_147 = 64 * 1024 ;
goto V_198;
}
}
if ( V_83 < 0 ) {
if ( V_83 != - V_180 )
F_23 ( F_7 ( V_13 ) ,
L_24 ,
V_83 ) ;
V_23 = - V_196 ;
V_134 -> V_155 = 0 ;
}
goto V_193;
}
V_147 = V_189 ;
switch ( F_79 ( V_134 -> V_142 ) ) {
case V_199 :
V_147 = V_51 ( V_147 , F_86 ( V_13 , V_4 ) ) ;
V_23 = - V_121 ;
break;
case V_200 :
V_147 = V_51 ( V_147 , F_86 ( V_13 , V_4 ) ) ;
default:
V_198:
V_4 -> V_115 = V_95 ;
V_189 = F_83 ( V_13 , V_134 , V_4 , V_147 , & V_23 ) ;
break;
}
if ( V_23 == - V_72 )
continue;
V_193:
F_94 ( & V_135 -> V_140 ) ;
F_32 ( V_135 ) ;
if ( V_4 )
V_4 -> V_113 = V_4 -> V_114 = 0 ;
F_95 ( F_5 ( V_13 ) , V_134 ) ;
F_15 ( & V_13 -> V_25 ) ;
F_96 ( F_5 ( V_13 ) , V_134 , V_23 ) ;
F_16 ( & V_13 -> V_25 ) ;
goto V_191;
}
if ( F_12 ( & V_13 -> V_140 ) ) {
F_97 ( V_13 -> V_139 ) ;
V_13 -> V_139 = NULL ;
} else if ( V_13 -> V_40 == V_146 ) {
F_46 ( & V_13 -> V_145 , V_95 + F_45 ( 1 ) ) ;
}
F_26 ( & V_13 -> V_25 , V_70 ) ;
}
static int F_98 ( struct V_10 * V_11 , char * V_79 )
{
struct V_9 * V_13 ;
unsigned long V_70 ;
int V_52 = 0 ;
V_13 = F_4 ( V_11 ) ;
F_25 ( & V_13 -> V_25 , V_70 ) ;
if ( ! F_99 ( V_11 ) )
goto V_61;
if ( V_13 -> V_42 && F_100 ( V_95 , V_13 -> V_94 ) ) {
V_13 -> V_29 |= ( V_201 << 16 ) ;
V_13 -> V_29 &= ~ V_37 ;
F_19 ( V_13 ) ;
}
if ( ( V_13 -> V_29 & V_202 ) != 0 ) {
* V_79 = ( 1 << 1 ) ;
F_23 ( F_6 ( V_13 ) , L_25 ,
V_13 -> V_29 ) ;
V_52 = 1 ;
if ( V_13 -> V_40 == V_41 )
F_101 ( V_11 ) ;
}
V_61:
F_26 ( & V_13 -> V_25 , V_70 ) ;
return V_52 ;
}
static inline void
F_102 ( struct V_203 * V_50 )
{
memset ( V_50 , 0 , sizeof *V_50 ) ;
V_50 -> V_55 = 0x29 ;
V_50 -> V_204 = 9 ;
V_50 -> V_205 = F_103 ( 0x0001 ) ;
V_50 -> V_206 = 1 ;
V_50 -> V_207 . V_208 . V_209 [ 0 ] = 0xff ;
V_50 -> V_207 . V_208 . V_209 [ 1 ] = 0xff ;
}
static int F_104 (
struct V_10 * V_11 ,
T_5 V_210 ,
T_5 V_169 ,
T_5 V_168 ,
char * V_79 ,
T_5 V_211
) {
struct V_9 * V_13 ;
int V_52 = 0 ;
unsigned long V_70 ;
if ( ! F_99 ( V_11 ) )
return - V_212 ;
V_13 = F_4 ( V_11 ) ;
F_25 ( & V_13 -> V_25 , V_70 ) ;
switch ( V_210 ) {
case V_213 :
break;
case V_214 :
switch ( V_169 ) {
case V_215 :
if ( V_13 -> V_29 & V_37 ) {
V_13 -> V_42 = 1 ;
V_13 -> V_94 = V_95 +
F_45 ( 20 ) ;
}
break;
case V_216 :
if ( V_13 -> V_29 & V_30 )
F_23 ( F_6 ( V_13 ) , L_26 ) ;
default:
V_13 -> V_29 &= ~ ( 1 << V_169 ) ;
F_19 ( V_13 ) ;
}
break;
case V_217 :
F_102 ( (struct V_203 * ) V_79 ) ;
break;
case V_218 :
* ( V_219 * ) V_79 = F_105 ( 0 ) ;
break;
case V_220 :
if ( V_168 != 1 )
V_52 = - V_196 ;
if ( V_13 -> V_42 &&
F_100 ( V_95 , V_13 -> V_94 ) ) {
V_13 -> V_29 |= ( V_201 << 16 ) ;
V_13 -> V_29 &= ~ V_37 ;
}
if ( ( V_13 -> V_29 & V_43 ) != 0 &&
F_100 ( V_95 , V_13 -> V_94 ) ) {
V_13 -> V_29 |= ( V_221 << 16 ) ;
V_13 -> V_29 &= ~ V_43 ;
if ( V_13 -> V_31 ) {
V_13 -> V_29 |= V_34 ;
V_13 -> V_17 . V_62 = V_13 -> V_44 -> V_62 ;
V_13 -> V_17 . V_116 -> V_67 = 64 ;
switch ( V_13 -> V_17 . V_62 ) {
case V_63 :
V_13 -> V_29 |=
V_36 ;
break;
case V_190 :
V_13 -> V_17 . V_116 -> V_67 = 8 ;
V_13 -> V_29 |=
V_35 ;
break;
default:
V_13 -> V_17 . V_62 = V_64 ;
break;
}
}
}
F_19 ( V_13 ) ;
( ( V_222 * ) V_79 ) [ 0 ] = F_103 ( V_13 -> V_29 ) ;
( ( V_222 * ) V_79 ) [ 1 ] = F_103 ( V_13 -> V_29 >> 16 ) ;
break;
case V_223 :
V_52 = - V_196 ;
break;
case V_224 :
switch ( V_169 ) {
case V_215 :
if ( V_13 -> V_28 ) {
V_13 -> V_29 |= V_37 ;
F_19 ( V_13 ) ;
if ( ( ( 1 << V_90 )
& V_13 -> V_89 ) != 0 )
F_23 ( F_6 ( V_13 ) ,
L_27 ) ;
}
break;
case V_216 :
V_13 -> V_29 |= V_30 ;
F_19 ( V_13 ) ;
break;
case V_225 :
V_13 -> V_29 &= ~ ( V_34
| V_35
| V_36 ) ;
V_13 -> V_89 = 0 ;
V_13 -> V_94 = V_95 + F_45 ( 50 ) ;
default:
if ( ( V_13 -> V_29 & V_30 ) != 0 ) {
V_13 -> V_29 |= ( 1 << V_169 ) ;
F_19 ( V_13 ) ;
}
}
break;
default:
F_23 ( F_6 ( V_13 ) ,
L_28 ,
V_210 , V_169 , V_168 , V_211 ) ;
V_52 = - V_196 ;
}
F_26 ( & V_13 -> V_25 , V_70 ) ;
if ( ( V_13 -> V_29 & V_202 ) != 0 )
F_49 ( V_11 ) ;
return V_52 ;
}
static int F_106 ( struct V_10 * V_11 )
{
struct V_9 * V_13 = F_4 ( V_11 ) ;
F_23 ( & V_11 -> V_15 . V_226 -> V_18 , L_13 , V_133 ) ;
F_54 ( & V_13 -> V_25 ) ;
V_13 -> V_40 = V_41 ;
F_19 ( V_13 ) ;
V_11 -> V_132 = V_227 ;
F_55 ( & V_13 -> V_25 ) ;
return 0 ;
}
static int F_107 ( struct V_10 * V_11 )
{
struct V_9 * V_13 = F_4 ( V_11 ) ;
int V_124 = 0 ;
F_23 ( & V_11 -> V_15 . V_226 -> V_18 , L_13 , V_133 ) ;
F_54 ( & V_13 -> V_25 ) ;
if ( ! F_99 ( V_11 ) ) {
V_124 = - V_24 ;
} else {
V_13 -> V_40 = V_146 ;
F_19 ( V_13 ) ;
if ( ! F_12 ( & V_13 -> V_140 ) )
F_46 ( & V_13 -> V_145 , V_95 ) ;
V_11 -> V_132 = V_228 ;
}
F_55 ( & V_13 -> V_25 ) ;
return V_124 ;
}
static inline T_2
F_108 ( char * V_79 , T_6 V_229 , struct V_134 * V_134 )
{
int V_4 = F_93 ( V_134 -> V_142 ) ;
return snprintf (buf, size,
L_29 ,
urb,
({ char *s;
switch (urb->dev->speed) {
case USB_SPEED_LOW: s = L_30; break;
case USB_SPEED_FULL: s = L_31; break;
case USB_SPEED_HIGH: s = L_32; break;
default: s = L_33; break;
}; s; }),
ep, ep ? (usb_pipein (urb->pipe) ? L_5 : L_6) : L_34 ,
({ char *s; \
switch (usb_pipetype (urb->pipe)) { \
case PIPE_CONTROL: s = L_34; break; \
case PIPE_BULK: s = L_3; break; \
case PIPE_INTERRUPT: s = L_2; break; \
default: s = L_1; break; \
}; s;}),
urb->actual_length, urb->transfer_buffer_length) ;
}
static T_2
F_109 ( struct V_14 * V_18 , struct V_98 * V_99 , char * V_79 )
{
struct V_10 * V_11 = F_110 ( V_18 ) ;
struct V_9 * V_13 = F_4 ( V_11 ) ;
struct V_135 * V_135 ;
T_6 V_229 = 0 ;
unsigned long V_70 ;
F_25 ( & V_13 -> V_25 , V_70 ) ;
F_18 (urbp, &dum->urbp_list, urbp_list) {
T_6 V_230 ;
V_230 = F_108 ( V_79 , V_101 - V_229 , V_135 -> V_134 ) ;
V_79 += V_230 ;
V_229 += V_230 ;
}
F_26 ( & V_13 -> V_25 , V_70 ) ;
return V_229 ;
}
static int F_111 ( struct V_10 * V_11 )
{
struct V_9 * V_13 ;
V_13 = F_4 ( V_11 ) ;
F_112 ( & V_13 -> V_25 ) ;
F_113 ( & V_13 -> V_145 ) ;
V_13 -> V_145 . V_100 = F_91 ;
V_13 -> V_145 . V_231 = ( unsigned long ) V_13 ;
V_13 -> V_40 = V_146 ;
F_29 ( & V_13 -> V_140 ) ;
V_11 -> V_232 = V_233 ;
V_11 -> V_132 = V_228 ;
V_11 -> V_234 = 1 ;
#ifdef F_114
V_11 -> V_15 . V_129 = 1 ;
#endif
return F_65 ( F_6 ( V_13 ) , & V_235 ) ;
}
static void F_115 ( struct V_10 * V_11 )
{
struct V_9 * V_13 ;
V_13 = F_4 ( V_11 ) ;
F_70 ( F_6 ( V_13 ) , & V_235 ) ;
F_56 ( V_13 -> V_44 ) ;
F_116 ( F_6 ( V_13 ) , L_35 ) ;
}
static int F_117 ( struct V_10 * V_11 )
{
return F_42 ( NULL ) ;
}
static int F_118 ( struct V_122 * V_123 )
{
struct V_10 * V_11 ;
int V_52 ;
F_116 ( & V_123 -> V_18 , L_36 V_236 L_37 , V_237 ) ;
V_11 = F_119 ( & V_238 , & V_123 -> V_18 , F_120 ( & V_123 -> V_18 ) ) ;
if ( ! V_11 )
return - V_138 ;
V_103 = F_4 ( V_11 ) ;
V_11 -> V_239 = 1 ;
V_52 = F_121 ( V_11 , 0 , 0 ) ;
if ( V_52 != 0 ) {
F_59 ( V_11 ) ;
V_103 = NULL ;
}
return V_52 ;
}
static int F_122 ( struct V_122 * V_123 )
{
struct V_10 * V_11 ;
V_11 = F_69 ( V_123 ) ;
F_123 ( V_11 ) ;
F_59 ( V_11 ) ;
V_103 = NULL ;
return 0 ;
}
static int F_124 ( struct V_122 * V_123 , T_3 V_132 )
{
struct V_10 * V_11 ;
struct V_9 * V_13 ;
int V_124 = 0 ;
F_23 ( & V_123 -> V_18 , L_13 , V_133 ) ;
V_11 = F_69 ( V_123 ) ;
V_13 = F_4 ( V_11 ) ;
if ( V_13 -> V_40 == V_146 ) {
F_125 ( & V_123 -> V_18 , L_38 ) ;
V_124 = - V_105 ;
} else
F_126 ( V_240 , & V_11 -> V_70 ) ;
return V_124 ;
}
static int F_127 ( struct V_122 * V_123 )
{
struct V_10 * V_11 ;
F_23 ( & V_123 -> V_18 , L_13 , V_133 ) ;
V_11 = F_69 ( V_123 ) ;
F_128 ( V_240 , & V_11 -> V_70 ) ;
F_49 ( V_11 ) ;
return 0 ;
}
static int T_7 F_129 ( void )
{
int V_52 = - V_138 ;
if ( F_130 () )
return - V_118 ;
V_241 = F_131 ( V_242 , - 1 ) ;
if ( ! V_241 )
return V_52 ;
V_243 = F_131 ( V_125 , - 1 ) ;
if ( ! V_243 )
goto V_244;
V_52 = F_132 ( & V_245 ) ;
if ( V_52 < 0 )
goto V_246;
V_52 = F_132 ( & V_247 ) ;
if ( V_52 < 0 )
goto V_248;
V_52 = F_133 ( V_241 ) ;
if ( V_52 < 0 )
goto V_249;
if ( ! V_103 ) {
V_52 = - V_57 ;
goto V_250;
}
V_52 = F_133 ( V_243 ) ;
if ( V_52 < 0 )
goto V_250;
if ( ! F_69 ( V_243 ) ) {
V_52 = - V_57 ;
goto V_251;
}
return V_52 ;
V_251:
F_134 ( V_243 ) ;
V_250:
F_134 ( V_241 ) ;
V_249:
F_135 ( & V_247 ) ;
V_248:
F_135 ( & V_245 ) ;
V_246:
F_136 ( V_243 ) ;
V_244:
F_136 ( V_241 ) ;
return V_52 ;
}
static void T_8 F_137 ( void )
{
F_138 ( V_243 ) ;
F_138 ( V_241 ) ;
F_135 ( & V_247 ) ;
F_135 ( & V_245 ) ;
}
