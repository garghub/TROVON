static void F_1 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 ,
struct V_4 * V_5 )
{
* V_2 = V_5 -> V_2 ;
* V_1 = V_5 -> V_1 ;
* V_3 = V_5 -> V_6 ;
}
static void F_2 ( T_1 * V_7 , T_1 * V_8 , struct V_4 * V_5 )
{
* V_7 = V_5 -> V_9 [ 0 ] ;
* V_8 = V_5 -> V_9 [ 1 ] ;
}
static void F_3 ( T_1 * V_1 , T_1 * V_2 ,
struct V_4 * V_5 )
{
* V_1 = V_5 -> V_10 ;
* V_2 = V_5 -> V_11 ;
}
static void F_4 ( T_1 * V_12 , int V_13 , T_1 * V_5 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
V_12 [ V_14 ] = V_5 [ V_14 ] ;
}
static void F_5 ( T_1 V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
V_5 -> V_2 = V_2 ;
V_5 -> V_1 = V_1 ;
V_5 -> V_6 = V_3 ;
}
static void F_6 ( T_1 V_15 , T_1 V_16 ,
struct V_4 * V_5 )
{
V_5 -> V_15 = V_15 ;
V_5 -> V_17 = V_16 ;
}
static void F_7 ( T_1 V_7 , T_1 V_8 , struct V_4 * V_5 )
{
V_5 -> V_9 [ 0 ] = V_7 ;
V_5 -> V_9 [ 1 ] = V_8 ;
}
static void F_8 ( T_1 V_1 , T_1 V_2 ,
struct V_4 * V_5 )
{
V_5 -> V_10 = V_1 ;
V_5 -> V_11 = V_2 ;
}
static void F_9 ( T_1 * V_12 , int V_13 , T_1 * V_5 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
V_5 [ V_14 ] = V_12 [ V_14 ] ;
}
static int F_10 ( char * V_18 , void T_2 * V_19 , T_1 V_20 )
{
unsigned int V_21 , V_22 ;
V_22 = F_11 ( V_19 + 4 ) ;
V_21 = F_11 ( V_19 ) ;
switch ( V_20 ) {
case V_23 :
V_21 = V_22 ;
V_22 = F_11 ( V_19 ) ;
break;
default:
break;
}
V_18 [ 0 ] = ( V_22 & 0x0000ff00 ) >> 8 ;
V_18 [ 1 ] = V_22 & 0x000000ff ;
V_18 [ 2 ] = ( V_21 & 0xff000000 ) >> 24 ;
V_18 [ 3 ] = ( V_21 & 0x00ff0000 ) >> 16 ;
V_18 [ 4 ] = ( V_21 & 0x0000ff00 ) >> 8 ;
V_18 [ 5 ] = V_21 & 0x000000ff ;
return 0 ;
}
static const char * F_12 ( struct V_24 * V_25 )
{
const char * V_26 ;
if ( F_13 ( V_25 , L_1 , & V_26 ) < 0 )
V_26 = V_25 -> V_26 ;
if ( ! V_26 )
V_26 = L_2 ;
return V_26 ;
}
static int F_14 ( struct V_27 * V_28 )
{
int V_29 ;
V_29 = F_15 ( V_28 -> V_30 ) ;
if ( ! V_29 )
V_28 -> V_31 = true ;
return V_29 ;
}
static int F_16 ( struct V_32 * V_32 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_32 -> V_35 ;
struct V_24 * V_37 , * V_38 , * V_25 = V_36 -> V_39 ;
struct V_24 * V_40 ;
struct V_41 * V_42 ;
struct V_27 * V_27 ;
struct V_33 * V_43 ;
bool V_44 = false ;
int V_29 ;
V_37 = F_17 ( V_25 , L_3 ) ;
if ( ! V_37 ) {
F_18 ( V_36 , L_4 ) ;
return V_45 ;
}
F_19 (devices, child) {
const char * V_26 = F_12 ( V_40 ) ;
if ( ! strcasecmp ( V_34 -> V_26 , V_26 ) )
break;
}
F_20 ( V_37 ) ;
if ( ! V_40 ) {
F_21 ( V_36 , L_5 , V_34 -> V_26 ) ;
return V_45 ;
}
V_42 = F_22 ( V_36 , sizeof( * V_42 ) , V_46 ) ;
if ( ! V_42 ) {
F_20 ( V_40 ) ;
return - V_47 ;
}
V_42 -> V_32 = V_32 ;
V_42 -> V_33 = V_34 ;
F_23 ( & V_42 -> V_48 , & V_32 -> V_49 ) ;
V_29 = V_34 -> V_50 ( V_32 , V_36 , V_40 ,
& V_42 -> V_51 ) ;
F_20 ( V_40 ) ;
if ( V_29 ) {
F_18 ( V_36 , L_6 ,
V_34 -> V_26 , V_29 ) ;
F_24 ( & V_42 -> V_48 ) ;
F_25 ( V_36 , V_42 ) ;
return V_52 ;
}
F_26 (tmp) {
if ( V_43 -> V_53 )
V_44 = true ;
}
if ( ! V_44 )
return 0 ;
F_27 (netcp_intf, &netcp_device->interface_head,
interface_list) {
struct V_54 * V_55 ;
V_55 = F_22 ( V_36 , sizeof( * V_55 ) ,
V_46 ) ;
if ( ! V_55 )
return - V_47 ;
V_38 = F_28 ( V_27 -> V_56 ,
V_34 -> V_26 , 0 ) ;
if ( ! V_38 ) {
F_25 ( V_36 , V_55 ) ;
continue;
}
V_55 -> V_57 = V_27 ;
V_55 -> V_33 = V_34 ;
F_23 ( & V_55 -> V_58 ,
& V_27 -> V_59 ) ;
V_29 = V_34 -> V_60 ( V_42 -> V_51 ,
V_27 -> V_30 , V_38 ,
& V_55 -> V_51 ) ;
F_20 ( V_38 ) ;
if ( V_29 ) {
F_29 ( V_36 , L_7 ,
V_34 -> V_26 , V_29 ) ;
F_24 ( & V_55 -> V_58 ) ;
F_25 ( V_36 , V_55 ) ;
continue;
}
}
F_27 (netcp_intf,
&netcp_device->interface_head,
interface_list) {
if ( ! V_27 -> V_31 ) {
V_29 = F_14 ( V_27 ) ;
if ( V_29 )
return - V_61 ;
}
}
return 0 ;
}
int F_30 ( struct V_33 * V_34 )
{
struct V_32 * V_32 ;
struct V_33 * V_43 ;
int V_29 ;
if ( ! V_34 -> V_26 ) {
F_31 ( 1 , L_8 ) ;
return - V_62 ;
}
if ( ! V_34 -> V_50 ) {
F_31 ( 1 , L_9 ) ;
return - V_62 ;
}
F_32 ( & V_63 ) ;
F_26 (tmp) {
if ( ! strcasecmp ( V_43 -> V_26 , V_34 -> V_26 ) ) {
F_33 ( & V_63 ) ;
return - V_64 ;
}
}
F_23 ( & V_34 -> V_65 , & V_66 ) ;
F_27 (netcp_device, &netcp_devices, device_list) {
V_29 = F_16 ( V_32 , V_34 ) ;
if ( V_29 < 0 )
goto V_67;
}
F_33 ( & V_63 ) ;
return 0 ;
V_67:
F_33 ( & V_63 ) ;
F_34 ( V_34 ) ;
return V_29 ;
}
static void F_35 ( struct V_32 * V_32 ,
struct V_33 * V_34 )
{
struct V_41 * V_42 , * V_68 ;
struct V_27 * V_27 , * V_69 ;
struct V_35 * V_36 = V_32 -> V_35 ;
F_36 (netcp_intf, netcp_tmp,
&netcp_device->interface_head,
interface_list) {
struct V_54 * V_55 , * V_70 ;
F_36 (intf_modpriv, intf_tmp,
&netcp_intf->module_head,
intf_list) {
if ( V_55 -> V_33 == V_34 ) {
V_34 -> V_71 ( V_55 -> V_51 ) ;
F_24 ( & V_55 -> V_58 ) ;
F_25 ( V_36 , V_55 ) ;
break;
}
}
}
F_36 (inst_modpriv, inst_tmp,
&netcp_device->modpriv_head, inst_list) {
if ( V_42 -> V_33 == V_34 ) {
V_34 -> remove ( V_32 ,
V_42 -> V_51 ) ;
F_24 ( & V_42 -> V_48 ) ;
F_25 ( V_36 , V_42 ) ;
break;
}
}
}
void F_34 ( struct V_33 * V_34 )
{
struct V_32 * V_32 ;
struct V_33 * V_72 ;
F_32 ( & V_63 ) ;
F_27 (netcp_device, &netcp_devices, device_list) {
F_35 ( V_32 , V_34 ) ;
}
F_26 (module_tmp) {
if ( V_34 == V_72 ) {
F_24 ( & V_34 -> V_65 ) ;
break;
}
}
F_33 ( & V_63 ) ;
}
void * F_37 ( struct V_33 * V_34 ,
struct V_27 * V_73 )
{
struct V_54 * V_55 ;
F_27 (intf_modpriv, &intf->module_head, intf_list)
if ( V_55 -> V_33 == V_34 )
return V_55 -> V_51 ;
return NULL ;
}
int F_38 ( struct V_27 * V_57 , int V_74 ,
T_3 * V_75 , void * V_76 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 ;
unsigned long V_80 ;
V_78 = F_22 ( V_57 -> V_36 , sizeof( * V_78 ) , V_46 ) ;
if ( ! V_78 )
return - V_47 ;
V_78 -> V_75 = V_75 ;
V_78 -> V_76 = V_76 ;
V_78 -> V_74 = V_74 ;
F_39 ( & V_57 -> V_81 , V_80 ) ;
F_27 (next, &netcp_priv->txhook_list_head, list) {
if ( V_79 -> V_74 > V_74 )
break;
}
F_40 ( & V_78 -> V_82 , V_79 -> V_82 . V_83 , & V_79 -> V_82 ) ;
F_41 ( & V_57 -> V_81 , V_80 ) ;
return 0 ;
}
int F_42 ( struct V_27 * V_57 , int V_74 ,
T_3 * V_75 , void * V_76 )
{
struct V_77 * V_79 , * V_84 ;
unsigned long V_80 ;
F_39 ( & V_57 -> V_81 , V_80 ) ;
F_36 (next, n, &netcp_priv->txhook_list_head, list) {
if ( ( V_79 -> V_74 == V_74 ) &&
( V_79 -> V_75 == V_75 ) &&
( V_79 -> V_76 == V_76 ) ) {
F_24 ( & V_79 -> V_82 ) ;
F_41 ( & V_57 -> V_81 , V_80 ) ;
F_25 ( V_57 -> V_36 , V_79 ) ;
return 0 ;
}
}
F_41 ( & V_57 -> V_81 , V_80 ) ;
return - V_85 ;
}
int F_43 ( struct V_27 * V_57 , int V_74 ,
T_3 * V_75 , void * V_76 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 ;
unsigned long V_80 ;
V_78 = F_22 ( V_57 -> V_36 , sizeof( * V_78 ) , V_46 ) ;
if ( ! V_78 )
return - V_47 ;
V_78 -> V_75 = V_75 ;
V_78 -> V_76 = V_76 ;
V_78 -> V_74 = V_74 ;
F_39 ( & V_57 -> V_81 , V_80 ) ;
F_27 (next, &netcp_priv->rxhook_list_head, list) {
if ( V_79 -> V_74 > V_74 )
break;
}
F_40 ( & V_78 -> V_82 , V_79 -> V_82 . V_83 , & V_79 -> V_82 ) ;
F_41 ( & V_57 -> V_81 , V_80 ) ;
return 0 ;
}
int F_44 ( struct V_27 * V_57 , int V_74 ,
T_3 * V_75 , void * V_76 )
{
struct V_77 * V_79 , * V_84 ;
unsigned long V_80 ;
F_39 ( & V_57 -> V_81 , V_80 ) ;
F_36 (next, n, &netcp_priv->rxhook_list_head, list) {
if ( ( V_79 -> V_74 == V_74 ) &&
( V_79 -> V_75 == V_75 ) &&
( V_79 -> V_76 == V_76 ) ) {
F_24 ( & V_79 -> V_82 ) ;
F_41 ( & V_57 -> V_81 , V_80 ) ;
F_25 ( V_57 -> V_36 , V_79 ) ;
return 0 ;
}
}
F_41 ( & V_57 -> V_81 , V_80 ) ;
return - V_85 ;
}
static void F_45 ( bool V_86 , void * V_87 )
{
if ( V_86 )
F_46 ( V_87 ) ;
else
F_47 ( V_87 ) ;
}
static void F_48 ( struct V_27 * V_28 ,
struct V_4 * V_5 )
{
struct V_4 * V_3 ;
T_4 V_88 , V_89 ;
unsigned int V_90 , V_91 = sizeof( * V_3 ) ;
void * V_92 ;
T_1 V_43 ;
F_4 ( & V_88 , 1 , & V_5 -> V_6 ) ;
while ( V_88 ) {
V_3 = F_49 ( V_28 -> V_93 , V_88 , V_91 ) ;
if ( F_50 ( ! V_3 ) ) {
F_18 ( V_28 -> V_94 , L_10 ) ;
break;
}
F_1 ( & V_89 , & V_43 , & V_88 , V_3 ) ;
F_2 ( ( T_1 * ) & V_92 , & V_43 , V_3 ) ;
F_51 ( V_28 -> V_36 , V_89 , V_95 , V_96 ) ;
F_52 ( V_92 ) ;
F_53 ( V_28 -> V_93 , V_5 ) ;
}
F_2 ( ( T_1 * ) & V_92 , & V_90 , V_5 ) ;
if ( V_92 )
F_45 ( V_90 <= V_95 , V_92 ) ;
F_53 ( V_28 -> V_93 , V_5 ) ;
}
static void F_54 ( struct V_27 * V_28 )
{
struct V_4 * V_5 ;
unsigned int V_91 ;
T_4 V_97 ;
for (; ; ) {
V_97 = F_55 ( V_28 -> V_98 , & V_91 ) ;
if ( ! V_97 )
break;
V_5 = F_49 ( V_28 -> V_93 , V_97 , V_91 ) ;
if ( F_50 ( ! V_5 ) ) {
F_18 ( V_28 -> V_94 , L_11 ,
V_99 ) ;
V_28 -> V_30 -> V_100 . V_101 ++ ;
continue;
}
F_48 ( V_28 , V_5 ) ;
V_28 -> V_30 -> V_100 . V_102 ++ ;
}
}
static int F_56 ( struct V_27 * V_28 )
{
unsigned int V_91 , V_90 , V_103 ;
struct V_4 * V_5 , * V_3 ;
unsigned int V_104 = 0 , V_105 ;
struct V_77 * V_106 ;
T_4 V_88 , V_107 ;
struct V_108 V_109 ;
struct V_110 * V_111 ;
void * V_112 ;
T_1 V_43 ;
V_88 = F_55 ( V_28 -> V_98 , & V_91 ) ;
if ( ! V_88 )
return - 1 ;
V_5 = F_49 ( V_28 -> V_93 , V_88 , V_91 ) ;
if ( F_50 ( ! V_5 ) ) {
F_18 ( V_28 -> V_94 , L_10 ) ;
return 0 ;
}
F_1 ( & V_107 , & V_90 , & V_88 , V_5 ) ;
F_2 ( ( T_1 * ) & V_112 , & V_103 , V_5 ) ;
if ( F_50 ( ! V_112 ) ) {
F_18 ( V_28 -> V_94 , L_12 ) ;
goto V_113;
}
V_104 &= V_114 ;
V_105 = V_90 ;
F_57 ( V_28 -> V_36 , V_107 , V_90 , V_96 ) ;
V_111 = F_58 ( V_112 , V_103 ) ;
if ( F_50 ( ! V_111 ) ) {
F_18 ( V_28 -> V_94 , L_13 ) ;
goto V_113;
}
F_59 ( V_111 , V_115 ) ;
F_60 ( V_111 , V_90 ) ;
while ( V_88 ) {
struct V_116 * V_116 ;
V_3 = F_49 ( V_28 -> V_93 , V_88 , V_91 ) ;
if ( F_50 ( ! V_3 ) ) {
F_18 ( V_28 -> V_94 , L_10 ) ;
goto V_113;
}
F_1 ( & V_107 , & V_90 , & V_88 , V_3 ) ;
F_2 ( ( T_1 * ) & V_116 , & V_43 , V_3 ) ;
if ( F_61 ( V_107 && V_90 && V_116 ) ) {
F_51 ( V_28 -> V_36 , V_107 , V_95 ,
V_96 ) ;
} else {
F_18 ( V_28 -> V_94 , L_14 ,
( void * ) V_107 , V_90 , V_116 ) ;
goto V_113;
}
F_62 ( V_111 , F_63 ( V_111 ) -> V_117 , V_116 ,
F_64 ( V_107 ) , V_90 , V_95 ) ;
V_105 += V_90 ;
F_53 ( V_28 -> V_93 , V_3 ) ;
}
F_53 ( V_28 -> V_93 , V_5 ) ;
if ( F_50 ( V_104 != V_105 ) )
F_29 ( V_28 -> V_94 , L_15 ,
V_104 , V_105 ) ;
F_65 ( V_111 , V_111 -> V_118 - V_119 ) ;
V_109 . V_111 = V_111 ;
V_109 . V_120 = false ;
F_27 (rx_hook, &netcp->rxhook_list_head, list) {
int V_29 ;
V_29 = V_106 -> V_75 ( V_106 -> V_74 , V_106 -> V_76 ,
& V_109 ) ;
if ( F_50 ( V_29 ) ) {
F_18 ( V_28 -> V_94 , L_16 ,
V_106 -> V_74 , V_29 ) ;
V_28 -> V_30 -> V_100 . V_101 ++ ;
F_66 ( V_111 ) ;
return 0 ;
}
}
V_28 -> V_30 -> V_100 . V_121 ++ ;
V_28 -> V_30 -> V_100 . V_122 += V_111 -> V_118 ;
V_111 -> V_123 = F_67 ( V_111 , V_28 -> V_30 ) ;
F_68 ( V_111 ) ;
return 0 ;
V_113:
F_48 ( V_28 , V_5 ) ;
V_28 -> V_30 -> V_100 . V_101 ++ ;
return 0 ;
}
static int F_69 ( struct V_27 * V_28 ,
unsigned int V_124 )
{
int V_14 ;
for ( V_14 = 0 ; ( V_14 < V_124 ) && ! F_56 ( V_28 ) ; V_14 ++ )
;
return V_14 ;
}
static void F_70 ( struct V_27 * V_28 , int V_125 )
{
struct V_4 * V_5 ;
unsigned int V_90 , V_91 ;
T_4 V_97 ;
void * V_92 ;
T_1 V_43 ;
while ( ( V_97 = F_55 ( V_28 -> V_126 [ V_125 ] , & V_91 ) ) ) {
V_5 = F_49 ( V_28 -> V_93 , V_97 , V_91 ) ;
if ( F_50 ( ! V_5 ) ) {
F_18 ( V_28 -> V_94 , L_10 ) ;
continue;
}
F_3 ( & V_97 , & V_90 , V_5 ) ;
F_2 ( ( T_1 * ) & V_92 , & V_43 , V_5 ) ;
if ( F_50 ( ! V_97 ) ) {
F_18 ( V_28 -> V_94 , L_17 ) ;
F_53 ( V_28 -> V_93 , V_5 ) ;
continue;
}
if ( F_50 ( ! V_92 ) ) {
F_18 ( V_28 -> V_94 , L_12 ) ;
F_53 ( V_28 -> V_93 , V_5 ) ;
continue;
}
if ( V_125 == 0 ) {
F_57 ( V_28 -> V_36 , V_97 , V_90 ,
V_96 ) ;
F_45 ( ( V_90 <= V_95 ) , V_92 ) ;
} else {
F_51 ( V_28 -> V_36 , V_97 , V_90 ,
V_96 ) ;
F_52 ( V_92 ) ;
}
F_53 ( V_28 -> V_93 , V_5 ) ;
}
}
static void F_71 ( struct V_27 * V_28 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_127 &&
! F_72 ( V_28 -> V_126 [ V_14 ] ) ; V_14 ++ )
F_70 ( V_28 , V_14 ) ;
if ( F_73 ( V_28 -> V_93 ) != V_28 -> V_128 )
F_18 ( V_28 -> V_94 , L_18 ,
V_28 -> V_128 - F_73 ( V_28 -> V_93 ) ) ;
F_74 ( V_28 -> V_93 ) ;
V_28 -> V_93 = NULL ;
}
static int F_75 ( struct V_27 * V_28 , int V_125 )
{
struct V_4 * V_129 ;
unsigned int V_90 , V_91 ;
T_1 V_15 , V_16 ;
struct V_116 * V_116 ;
T_4 V_97 ;
void * V_130 ;
T_1 V_9 [ 2 ] ;
V_129 = F_76 ( V_28 -> V_93 ) ;
if ( F_72 ( V_129 ) ) {
F_29 ( V_28 -> V_94 , L_19 ) ;
return - V_47 ;
}
if ( F_61 ( V_125 == 0 ) ) {
unsigned int V_131 ;
V_90 = V_132 + V_115 ;
V_131 = F_77 ( V_90 ) +
F_77 ( sizeof( struct V_133 ) ) ;
V_130 = F_78 ( V_131 ) ;
V_9 [ 1 ] = V_131 ;
if ( F_50 ( ! V_130 ) ) {
F_79 ( V_28 -> V_94 ,
L_20 ) ;
goto V_67;
}
V_97 = F_80 ( V_28 -> V_36 , V_130 , V_90 ,
V_134 ) ;
if ( F_50 ( F_81 ( V_28 -> V_36 , V_97 ) ) )
goto V_67;
V_9 [ 0 ] = ( T_1 ) V_130 ;
} else {
V_116 = F_82 ( V_135 | V_136 | V_137 ) ;
if ( F_50 ( ! V_116 ) ) {
F_79 ( V_28 -> V_94 , L_21 ) ;
goto V_67;
}
V_90 = V_95 ;
V_97 = F_83 ( V_28 -> V_36 , V_116 , 0 , V_90 , V_134 ) ;
V_9 [ 0 ] = ( T_1 ) V_116 ;
V_9 [ 1 ] = 0 ;
}
V_15 = V_138 ;
V_15 |= V_90 & V_114 ;
V_16 = V_139 ;
V_16 |= V_140 << V_141 ;
V_16 |= ( V_28 -> V_142 & V_143 ) <<
V_144 ;
F_8 ( V_97 , V_90 , V_129 ) ;
F_7 ( V_9 [ 0 ] , V_9 [ 1 ] , V_129 ) ;
F_6 ( V_15 , V_16 , V_129 ) ;
F_84 ( V_28 -> V_93 , V_129 , sizeof( * V_129 ) , & V_97 ,
& V_91 ) ;
F_85 ( V_28 -> V_126 [ V_125 ] , V_97 , sizeof( * V_129 ) , 0 ) ;
return 0 ;
V_67:
F_53 ( V_28 -> V_93 , V_129 ) ;
return - V_47 ;
}
static void F_86 ( struct V_27 * V_28 )
{
T_1 V_145 [ V_127 ] = { 0 } ;
int V_14 , V_29 = 0 ;
for ( V_14 = 0 ; V_14 < V_127 && V_28 -> V_126 [ V_14 ] ; V_14 ++ ) {
V_145 [ V_14 ] = V_28 -> V_146 [ V_14 ] -
F_87 ( V_28 -> V_126 [ V_14 ] ) ;
while ( V_145 [ V_14 ] -- && ! V_29 )
V_29 = F_75 ( V_28 , V_14 ) ;
}
}
static int F_88 ( struct V_147 * V_148 , int V_124 )
{
struct V_27 * V_28 = F_89 ( V_148 , struct V_27 ,
V_149 ) ;
unsigned int V_150 ;
V_150 = F_69 ( V_28 , V_124 ) ;
F_86 ( V_28 ) ;
if ( V_150 < V_124 ) {
F_90 ( & V_28 -> V_149 ) ;
F_91 ( V_28 -> V_98 ) ;
}
return V_150 ;
}
static void F_92 ( void * V_151 )
{
struct V_27 * V_28 = V_151 ;
F_93 ( V_28 -> V_98 ) ;
F_94 ( & V_28 -> V_149 ) ;
}
static void F_95 ( struct V_27 * V_28 ,
struct V_4 * V_5 ,
unsigned int V_152 )
{
struct V_4 * V_3 = V_5 ;
T_4 V_88 , V_89 ;
unsigned int V_90 ;
while ( V_3 ) {
F_1 ( & V_89 , & V_90 , & V_88 , V_3 ) ;
if ( V_89 && V_90 )
F_57 ( V_28 -> V_36 , V_89 , V_90 ,
V_134 ) ;
else
F_21 ( V_28 -> V_94 , L_22 ,
( void * ) V_89 , V_90 ) ;
F_53 ( V_28 -> V_153 , V_3 ) ;
V_3 = NULL ;
if ( V_88 ) {
V_3 = F_49 ( V_28 -> V_153 , V_88 ,
V_152 ) ;
if ( ! V_3 )
F_18 ( V_28 -> V_94 , L_23 ) ;
}
}
}
static int F_96 ( struct V_27 * V_28 ,
unsigned int V_124 )
{
struct V_4 * V_5 ;
struct V_110 * V_111 ;
unsigned int V_91 ;
T_4 V_97 ;
int V_154 = 0 ;
T_1 V_43 ;
while ( V_124 -- ) {
V_97 = F_55 ( V_28 -> V_155 , & V_91 ) ;
if ( ! V_97 )
break;
V_5 = F_49 ( V_28 -> V_153 , V_97 , V_91 ) ;
if ( F_50 ( ! V_5 ) ) {
F_18 ( V_28 -> V_94 , L_23 ) ;
V_28 -> V_30 -> V_100 . V_156 ++ ;
continue;
}
F_2 ( ( T_1 * ) & V_111 , & V_43 , V_5 ) ;
F_95 ( V_28 , V_5 , V_91 ) ;
if ( ! V_111 ) {
F_18 ( V_28 -> V_94 , L_24 ) ;
V_28 -> V_30 -> V_100 . V_156 ++ ;
continue;
}
if ( F_97 ( V_28 -> V_30 , V_111 ) &&
F_98 ( V_28 -> V_30 ) &&
( F_73 ( V_28 -> V_153 ) >
V_28 -> V_157 ) ) {
T_5 V_158 = F_99 ( V_111 ) ;
F_100 ( V_28 -> V_30 , V_158 ) ;
}
V_28 -> V_30 -> V_100 . V_159 ++ ;
V_28 -> V_30 -> V_100 . V_160 += V_111 -> V_118 ;
F_66 ( V_111 ) ;
V_154 ++ ;
}
return V_154 ;
}
static int F_101 ( struct V_147 * V_148 , int V_124 )
{
int V_150 ;
struct V_27 * V_28 = F_89 ( V_148 , struct V_27 ,
V_161 ) ;
V_150 = F_96 ( V_28 , V_124 ) ;
if ( V_150 < V_124 ) {
F_90 ( & V_28 -> V_161 ) ;
F_91 ( V_28 -> V_155 ) ;
}
return V_150 ;
}
static void F_102 ( void * V_151 )
{
struct V_27 * V_28 = V_151 ;
F_93 ( V_28 -> V_155 ) ;
F_94 ( & V_28 -> V_161 ) ;
}
static struct V_4 *
F_103 ( struct V_110 * V_111 , struct V_27 * V_28 )
{
struct V_4 * V_5 , * V_3 , * V_162 ;
unsigned int V_163 = F_104 ( V_111 ) ;
struct V_35 * V_36 = V_28 -> V_36 ;
T_4 V_164 ;
unsigned int V_91 ;
int V_14 ;
V_164 = F_80 ( V_36 , V_111 -> V_165 , V_163 , V_134 ) ;
if ( F_50 ( F_81 ( V_36 , V_164 ) ) ) {
F_18 ( V_28 -> V_94 , L_25 ) ;
return NULL ;
}
V_5 = F_76 ( V_28 -> V_153 ) ;
if ( F_72 ( V_5 ) ) {
F_18 ( V_28 -> V_94 , L_26 ) ;
F_57 ( V_36 , V_164 , V_163 , V_134 ) ;
return NULL ;
}
F_5 ( V_164 , V_163 , 0 , V_5 ) ;
if ( F_105 ( V_111 ) ) {
F_106 ( F_63 ( V_111 ) ) ;
} else {
V_5 -> V_6 = 0 ;
goto V_166;
}
V_162 = V_5 ;
for ( V_14 = 0 ; V_14 < F_63 ( V_111 ) -> V_117 ; V_14 ++ ) {
T_6 * V_167 = & F_63 ( V_111 ) -> V_168 [ V_14 ] ;
struct V_116 * V_116 = F_107 ( V_167 ) ;
T_1 V_169 = V_167 -> V_169 ;
T_1 V_90 = F_108 ( V_167 ) ;
T_4 V_170 ;
T_1 V_16 ;
V_164 = F_83 ( V_36 , V_116 , V_169 , V_90 ,
V_134 ) ;
if ( F_50 ( ! V_164 ) ) {
F_18 ( V_28 -> V_94 , L_27 ) ;
goto V_171;
}
V_3 = F_76 ( V_28 -> V_153 ) ;
if ( F_72 ( V_3 ) ) {
F_18 ( V_28 -> V_94 , L_28 ) ;
F_51 ( V_36 , V_164 , V_90 , V_134 ) ;
goto V_171;
}
V_170 = F_109 ( V_28 -> V_153 ,
( void * ) V_3 ) ;
V_16 =
( V_28 -> V_172 & V_143 ) <<
V_144 ;
F_5 ( V_164 , V_90 , 0 , V_3 ) ;
F_9 ( & V_170 , 1 , & V_162 -> V_6 ) ;
V_163 += V_90 ;
if ( V_162 != V_5 )
F_84 ( V_28 -> V_153 , V_162 ,
sizeof( * V_162 ) , & V_170 , & V_91 ) ;
V_162 = V_3 ;
}
if ( V_162 != V_5 )
F_84 ( V_28 -> V_153 , V_162 , sizeof( * V_162 ) ,
& V_164 , & V_91 ) ;
if ( F_63 ( V_111 ) -> V_173 ) {
F_110 ( V_28 -> V_94 , L_29 ) ;
goto V_171;
}
V_166:
F_111 ( V_163 != V_111 -> V_118 ) ;
V_163 &= V_114 ;
F_9 ( & V_163 , 1 , & V_5 -> V_15 ) ;
return V_5 ;
V_171:
F_95 ( V_28 , V_5 , sizeof( * V_5 ) ) ;
return NULL ;
}
static int F_112 ( struct V_27 * V_28 ,
struct V_110 * V_111 ,
struct V_4 * V_5 )
{
struct V_174 * V_175 = NULL ;
struct V_77 * V_176 ;
struct V_108 V_109 ;
unsigned int V_91 ;
T_4 V_97 ;
T_1 V_43 = 0 ;
int V_29 = 0 ;
V_109 . V_28 = V_28 ;
V_109 . V_111 = V_111 ;
V_109 . V_175 = NULL ;
V_109 . V_177 = 0 ;
V_109 . V_178 = NULL ;
V_109 . V_179 = NULL ;
V_109 . V_180 = V_5 -> V_180 ;
V_109 . V_181 = V_5 -> V_181 ;
memset ( V_109 . V_180 , 0 , V_182 * sizeof( T_1 ) ) ;
F_27 (tx_hook, &netcp->txhook_list_head, list) {
V_29 = V_176 -> V_75 ( V_176 -> V_74 , V_176 -> V_76 ,
& V_109 ) ;
if ( F_50 ( V_29 != 0 ) ) {
F_18 ( V_28 -> V_94 , L_30 ,
V_176 -> V_74 , V_29 ) ;
V_29 = ( V_29 < 0 ) ? V_29 : V_183 ;
goto V_184;
}
}
V_175 = V_109 . V_175 ;
if ( ! V_175 ) {
F_18 ( V_28 -> V_94 , L_31 ) ;
V_29 = - V_185 ;
goto V_184;
}
if ( V_109 . V_177 ) {
T_1 * V_181 = V_109 . V_181 ;
memmove ( V_109 . V_181 , V_109 . V_181 + V_109 . V_177 ,
V_109 . V_177 ) ;
F_9 ( V_181 , V_109 . V_177 , V_181 ) ;
V_43 |= ( V_109 . V_177 & V_186 ) <<
V_141 ;
}
V_43 |= V_139 |
( ( V_28 -> V_172 & V_143 ) <<
V_144 ) ;
if ( ! ( V_175 -> V_80 & V_187 ) ) {
V_43 |= ( ( V_175 -> V_188 & V_189 ) <<
V_190 ) ;
}
F_9 ( & V_43 , 1 , & V_5 -> V_17 ) ;
F_9 ( ( T_1 * ) & V_111 , 1 , & V_5 -> V_9 [ 0 ] ) ;
if ( V_175 -> V_80 & V_187 ) {
V_43 = V_175 -> V_188 ;
F_9 ( ( T_1 * ) & V_43 , 1 , & V_5 -> V_191 ) ;
}
V_29 = F_84 ( V_28 -> V_153 , V_5 , sizeof( * V_5 ) , & V_97 ,
& V_91 ) ;
if ( F_50 ( V_29 ) ) {
F_18 ( V_28 -> V_94 , L_32 , V_99 ) ;
V_29 = - V_47 ;
goto V_184;
}
F_113 ( V_111 ) ;
F_85 ( V_175 -> V_192 , V_97 , V_91 , 0 ) ;
V_184:
return V_29 ;
}
static int F_114 ( struct V_110 * V_111 , struct V_193 * V_30 )
{
struct V_27 * V_28 = F_115 ( V_30 ) ;
int V_158 = F_99 ( V_111 ) ;
struct V_4 * V_5 ;
int V_194 , V_29 = 0 ;
if ( F_50 ( V_111 -> V_118 <= 0 ) ) {
F_66 ( V_111 ) ;
return V_183 ;
}
if ( F_50 ( V_111 -> V_118 < V_195 ) ) {
V_29 = F_116 ( V_111 , V_195 ) ;
if ( V_29 < 0 ) {
F_21 ( V_28 -> V_94 , L_33 ,
V_29 ) ;
V_30 -> V_100 . V_196 ++ ;
return V_29 ;
}
V_111 -> V_118 = V_195 ;
}
V_5 = F_103 ( V_111 , V_28 ) ;
if ( F_50 ( ! V_5 ) ) {
F_117 ( V_30 , V_158 ) ;
V_29 = - V_197 ;
goto V_198;
}
V_29 = F_112 ( V_28 , V_111 , V_5 ) ;
if ( V_29 )
goto V_198;
V_30 -> V_199 = V_200 ;
V_194 = F_73 ( V_28 -> V_153 ) ;
if ( V_194 < V_28 -> V_201 ) {
F_29 ( V_28 -> V_94 , L_34 , V_194 ) ;
F_117 ( V_30 , V_158 ) ;
}
return V_183 ;
V_198:
V_30 -> V_100 . V_196 ++ ;
if ( V_5 )
F_95 ( V_28 , V_5 , sizeof( * V_5 ) ) ;
F_66 ( V_111 ) ;
return V_29 ;
}
int F_118 ( struct V_174 * V_175 )
{
if ( V_175 -> V_202 ) {
F_119 ( V_175 -> V_202 ) ;
V_175 -> V_202 = NULL ;
}
return 0 ;
}
int F_120 ( struct V_174 * V_175 )
{
struct V_35 * V_36 = V_175 -> V_32 -> V_35 ;
struct V_203 V_204 ;
int V_29 = 0 ;
T_7 V_26 [ 16 ] ;
memset ( & V_204 , 0 , sizeof( V_204 ) ) ;
V_204 . V_205 = V_206 ;
V_204 . V_207 . V_208 . V_209 = false ;
V_204 . V_207 . V_208 . V_210 = false ;
V_204 . V_207 . V_208 . V_211 = V_212 ;
V_175 -> V_202 = F_121 ( V_36 ,
V_175 -> V_213 , & V_204 ) ;
if ( F_72 ( V_175 -> V_202 ) ) {
F_18 ( V_36 , L_35 ,
V_175 -> V_213 ) ;
goto V_214;
}
snprintf ( V_26 , sizeof( V_26 ) , L_36 , F_122 ( V_36 ) ) ;
V_175 -> V_192 = F_123 ( V_26 , V_175 -> V_215 ,
V_216 ) ;
if ( F_124 ( V_175 -> V_192 ) ) {
F_18 ( V_36 , L_37 ,
V_26 , V_29 ) ;
V_29 = F_125 ( V_175 -> V_192 ) ;
goto V_214;
}
F_29 ( V_36 , L_38 , V_26 ) ;
return 0 ;
V_214:
if ( ! F_72 ( V_175 -> V_202 ) )
F_119 ( V_175 -> V_202 ) ;
V_175 -> V_202 = NULL ;
return V_29 ;
}
int F_126 ( struct V_174 * V_175 ,
struct V_32 * V_32 ,
const char * V_213 , unsigned int V_215 )
{
memset ( V_175 , 0 , sizeof( * V_175 ) ) ;
V_175 -> V_32 = V_32 ;
V_175 -> V_213 = V_213 ;
V_175 -> V_215 = V_215 ;
return 0 ;
}
static struct V_217 * F_127 ( struct V_27 * V_28 ,
const T_7 * V_218 ,
enum V_219 type )
{
struct V_217 * V_220 ;
F_27 (naddr, &netcp->addr_list, node) {
if ( V_220 -> type != type )
continue;
if ( V_218 && memcmp ( V_218 , V_220 -> V_218 , V_221 ) )
continue;
return V_220 ;
}
return NULL ;
}
static struct V_217 * F_128 ( struct V_27 * V_28 ,
const T_7 * V_218 ,
enum V_219 type )
{
struct V_217 * V_220 ;
V_220 = F_129 ( V_28 -> V_36 , sizeof( * V_220 ) , V_135 ) ;
if ( ! V_220 )
return NULL ;
V_220 -> type = type ;
V_220 -> V_80 = 0 ;
V_220 -> V_28 = V_28 ;
if ( V_218 )
F_130 ( V_220 -> V_218 , V_218 ) ;
else
F_131 ( V_220 -> V_218 ) ;
F_23 ( & V_220 -> V_25 , & V_28 -> V_222 ) ;
return V_220 ;
}
static void F_132 ( struct V_27 * V_28 , struct V_217 * V_220 )
{
F_24 ( & V_220 -> V_25 ) ;
F_25 ( V_28 -> V_36 , V_220 ) ;
}
static void F_133 ( struct V_27 * V_28 )
{
struct V_217 * V_220 ;
F_27 (naddr, &netcp->addr_list, node)
V_220 -> V_80 = 0 ;
}
static void F_134 ( struct V_27 * V_28 , const T_7 * V_218 ,
enum V_219 type )
{
struct V_217 * V_220 ;
V_220 = F_127 ( V_28 , V_218 , type ) ;
if ( V_220 ) {
V_220 -> V_80 |= V_223 ;
return;
}
V_220 = F_128 ( V_28 , V_218 , type ) ;
if ( ! F_111 ( ! V_220 ) )
V_220 -> V_80 |= V_224 ;
}
static void F_135 ( struct V_27 * V_28 )
{
struct V_217 * V_220 , * V_43 ;
struct V_54 * V_225 ;
struct V_33 * V_34 ;
int error ;
F_36 (naddr, tmp, &netcp->addr_list, node) {
if ( V_220 -> V_80 & ( V_223 | V_224 ) )
continue;
F_29 ( V_28 -> V_94 , L_39 ,
V_220 -> V_218 , V_220 -> type ) ;
F_136 (netcp, priv) {
V_34 = V_225 -> V_33 ;
if ( ! V_34 -> V_226 )
continue;
error = V_34 -> V_226 ( V_225 -> V_51 ,
V_220 ) ;
F_111 ( error ) ;
}
F_132 ( V_28 , V_220 ) ;
}
}
static void F_137 ( struct V_27 * V_28 )
{
struct V_217 * V_220 , * V_43 ;
struct V_54 * V_225 ;
struct V_33 * V_34 ;
int error ;
F_36 (naddr, tmp, &netcp->addr_list, node) {
if ( ! ( V_220 -> V_80 & V_224 ) )
continue;
F_29 ( V_28 -> V_94 , L_40 ,
V_220 -> V_218 , V_220 -> type ) ;
F_136 (netcp, priv) {
V_34 = V_225 -> V_33 ;
if ( ! V_34 -> V_227 )
continue;
error = V_34 -> V_227 ( V_225 -> V_51 , V_220 ) ;
F_111 ( error ) ;
}
}
}
static void F_138 ( struct V_193 * V_30 )
{
struct V_27 * V_28 = F_115 ( V_30 ) ;
struct V_228 * V_229 ;
bool V_230 ;
V_230 = ( V_30 -> V_80 & V_231 ||
V_30 -> V_80 & V_232 ||
F_139 ( V_30 ) > V_233 ) ;
F_140 ( & V_28 -> V_81 ) ;
F_133 ( V_28 ) ;
F_134 ( V_28 , V_30 -> V_234 , V_235 ) ;
F_141 (ndev, ndev_addr)
F_134 ( V_28 , V_229 -> V_218 , V_236 ) ;
F_142 (ndev_addr, ndev)
F_134 ( V_28 , V_229 -> V_218 , V_237 ) ;
F_143 (ndev_addr, ndev)
F_134 ( V_28 , V_229 -> V_218 , V_238 ) ;
if ( V_230 )
F_134 ( V_28 , NULL , V_239 ) ;
F_135 ( V_28 ) ;
F_137 ( V_28 ) ;
F_144 ( & V_28 -> V_81 ) ;
}
static void F_145 ( struct V_27 * V_28 )
{
int V_14 ;
if ( V_28 -> V_240 ) {
F_119 ( V_28 -> V_240 ) ;
V_28 -> V_240 = NULL ;
}
if ( ! F_72 ( V_28 -> V_93 ) )
F_71 ( V_28 ) ;
if ( ! F_72 ( V_28 -> V_98 ) ) {
F_146 ( V_28 -> V_98 ) ;
V_28 -> V_98 = NULL ;
}
for ( V_14 = 0 ; V_14 < V_127 &&
! F_72 ( V_28 -> V_126 [ V_14 ] ) ; ++ V_14 ) {
F_146 ( V_28 -> V_126 [ V_14 ] ) ;
V_28 -> V_126 [ V_14 ] = NULL ;
}
if ( ! F_72 ( V_28 -> V_155 ) ) {
F_146 ( V_28 -> V_155 ) ;
V_28 -> V_155 = NULL ;
}
if ( ! F_72 ( V_28 -> V_153 ) ) {
F_74 ( V_28 -> V_153 ) ;
V_28 -> V_153 = NULL ;
}
}
static int F_147 ( struct V_193 * V_30 )
{
struct V_27 * V_28 = F_115 ( V_30 ) ;
struct V_241 V_242 ;
struct V_203 V_204 ;
T_1 V_243 = 0 ;
T_7 V_26 [ 16 ] ;
int V_29 ;
int V_14 ;
snprintf ( V_26 , sizeof( V_26 ) , L_41 , V_30 -> V_26 ) ;
V_28 -> V_93 = F_148 ( V_26 , V_28 -> V_128 ,
V_28 -> V_244 ) ;
if ( F_72 ( V_28 -> V_93 ) ) {
F_18 ( V_28 -> V_94 , L_42 ) ;
V_29 = F_125 ( V_28 -> V_93 ) ;
goto V_67;
}
snprintf ( V_26 , sizeof( V_26 ) , L_43 , V_30 -> V_26 ) ;
V_28 -> V_153 = F_148 ( V_26 , V_28 -> V_245 ,
V_28 -> V_246 ) ;
if ( F_72 ( V_28 -> V_153 ) ) {
F_18 ( V_28 -> V_94 , L_44 ) ;
V_29 = F_125 ( V_28 -> V_153 ) ;
goto V_67;
}
snprintf ( V_26 , sizeof( V_26 ) , L_45 , V_30 -> V_26 ) ;
V_28 -> V_155 = F_123 ( V_26 , V_28 -> V_172 , 0 ) ;
if ( F_72 ( V_28 -> V_155 ) ) {
V_29 = F_125 ( V_28 -> V_155 ) ;
goto V_67;
}
V_28 -> V_172 = F_149 ( V_28 -> V_155 ) ;
V_242 . V_247 = F_102 ;
V_242 . V_248 = V_28 ;
V_29 = F_150 ( V_28 -> V_155 ,
V_249 ,
( unsigned long ) & V_242 ) ;
if ( V_29 )
goto V_67;
F_93 ( V_28 -> V_155 ) ;
snprintf ( V_26 , sizeof( V_26 ) , L_46 , V_30 -> V_26 ) ;
V_28 -> V_98 = F_123 ( V_26 , V_28 -> V_142 , 0 ) ;
if ( F_72 ( V_28 -> V_98 ) ) {
V_29 = F_125 ( V_28 -> V_98 ) ;
goto V_67;
}
V_28 -> V_142 = F_149 ( V_28 -> V_98 ) ;
V_242 . V_247 = F_92 ;
V_242 . V_248 = V_28 ;
V_29 = F_150 ( V_28 -> V_98 ,
V_249 ,
( unsigned long ) & V_242 ) ;
if ( V_29 )
goto V_67;
F_93 ( V_28 -> V_98 ) ;
for ( V_14 = 0 ; V_14 < V_127 && V_28 -> V_146 [ V_14 ] ;
++ V_14 ) {
snprintf ( V_26 , sizeof( V_26 ) , L_47 , V_30 -> V_26 , V_14 ) ;
V_28 -> V_126 [ V_14 ] = F_123 ( V_26 , V_250 , 0 ) ;
if ( F_72 ( V_28 -> V_126 [ V_14 ] ) ) {
V_29 = F_125 ( V_28 -> V_126 [ V_14 ] ) ;
goto V_67;
}
}
memset ( & V_204 , 0 , sizeof( V_204 ) ) ;
V_204 . V_205 = V_251 ;
V_204 . V_207 . V_252 . V_253 = true ;
V_204 . V_207 . V_252 . V_254 = true ;
V_204 . V_207 . V_252 . V_255 = V_256 ;
V_204 . V_207 . V_252 . V_257 = V_258 ;
V_204 . V_207 . V_252 . V_259 = false ;
V_204 . V_207 . V_252 . V_260 = V_115 ;
V_204 . V_207 . V_252 . V_261 = V_28 -> V_142 ;
V_204 . V_207 . V_252 . V_262 = V_263 ;
for ( V_14 = 0 ; V_14 < V_127 ; ++ V_14 ) {
if ( V_28 -> V_126 [ V_14 ] )
V_243 = F_149 ( V_28 -> V_126 [ V_14 ] ) ;
V_204 . V_207 . V_252 . V_125 [ V_14 ] = V_243 ;
}
V_28 -> V_240 = F_121 ( V_28 -> V_32 -> V_35 ,
V_28 -> V_213 , & V_204 ) ;
if ( F_72 ( V_28 -> V_240 ) ) {
F_18 ( V_28 -> V_94 , L_48 ,
V_28 -> V_213 ) ;
goto V_67;
}
F_29 ( V_28 -> V_94 , L_49 , V_28 -> V_240 ) ;
return 0 ;
V_67:
F_145 ( V_28 ) ;
return V_29 ;
}
static int F_151 ( struct V_193 * V_30 )
{
struct V_27 * V_28 = F_115 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
int V_29 ;
F_152 ( V_30 ) ;
V_29 = F_147 ( V_30 ) ;
if ( V_29 ) {
F_18 ( V_28 -> V_94 , L_50 ) ;
goto V_67;
}
F_136 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( V_34 -> V_264 ) {
V_29 = V_34 -> V_264 ( V_55 -> V_51 , V_30 ) ;
if ( V_29 != 0 ) {
F_18 ( V_28 -> V_94 , L_51 ) ;
goto V_265;
}
}
}
F_153 ( & V_28 -> V_149 ) ;
F_153 ( & V_28 -> V_161 ) ;
F_91 ( V_28 -> V_155 ) ;
F_91 ( V_28 -> V_98 ) ;
F_86 ( V_28 ) ;
F_154 ( V_30 ) ;
F_29 ( V_28 -> V_94 , L_52 , V_30 -> V_26 ) ;
return 0 ;
V_265:
F_136 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( V_34 -> V_266 )
V_34 -> V_266 ( V_55 -> V_51 , V_30 ) ;
}
V_67:
F_145 ( V_28 ) ;
return V_29 ;
}
static int F_155 ( struct V_193 * V_30 )
{
struct V_27 * V_28 = F_115 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
int V_214 = 0 ;
F_156 ( V_30 ) ;
F_152 ( V_30 ) ;
F_133 ( V_28 ) ;
F_135 ( V_28 ) ;
F_93 ( V_28 -> V_98 ) ;
F_93 ( V_28 -> V_155 ) ;
F_157 ( & V_28 -> V_149 ) ;
F_157 ( & V_28 -> V_161 ) ;
F_136 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( V_34 -> V_266 ) {
V_214 = V_34 -> V_266 ( V_55 -> V_51 , V_30 ) ;
if ( V_214 != 0 )
F_18 ( V_28 -> V_94 , L_53 ) ;
}
}
F_54 ( V_28 ) ;
F_96 ( V_28 , V_28 -> V_245 ) ;
if ( F_73 ( V_28 -> V_153 ) != V_28 -> V_245 )
F_18 ( V_28 -> V_94 , L_54 ,
V_28 -> V_245 - F_73 ( V_28 -> V_153 ) ) ;
F_145 ( V_28 ) ;
F_29 ( V_28 -> V_94 , L_55 , V_30 -> V_26 ) ;
return 0 ;
}
static int F_158 ( struct V_193 * V_30 ,
struct V_267 * V_268 , int V_269 )
{
struct V_27 * V_28 = F_115 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
int V_29 = - 1 , V_214 = - V_270 ;
if ( ! F_98 ( V_30 ) )
return - V_62 ;
F_136 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( ! V_34 -> V_271 )
continue;
V_214 = V_34 -> V_271 ( V_55 -> V_51 , V_268 , V_269 ) ;
if ( ( V_214 < 0 ) && ( V_214 != - V_270 ) ) {
V_29 = V_214 ;
goto V_184;
}
if ( V_214 == 0 )
V_29 = V_214 ;
}
V_184:
return ( V_29 == 0 ) ? 0 : V_214 ;
}
static int F_159 ( struct V_193 * V_30 , int V_272 )
{
struct V_27 * V_28 = F_115 ( V_30 ) ;
if ( ( V_272 < 68 ) ||
( V_272 > ( V_273 - V_274 - V_119 ) ) ) {
F_18 ( V_28 -> V_94 , L_56 , V_272 ) ;
return - V_62 ;
}
V_30 -> V_275 = V_272 ;
return 0 ;
}
static void F_160 ( struct V_193 * V_30 )
{
struct V_27 * V_28 = F_115 ( V_30 ) ;
unsigned int V_276 = F_73 ( V_28 -> V_153 ) ;
F_18 ( V_28 -> V_94 , L_57 , V_276 ) ;
F_96 ( V_28 , V_28 -> V_245 ) ;
V_30 -> V_199 = V_200 ;
F_154 ( V_30 ) ;
}
static int F_161 ( struct V_193 * V_30 , T_8 V_277 , T_5 V_278 )
{
struct V_27 * V_28 = F_115 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
unsigned long V_80 ;
int V_214 = 0 ;
F_29 ( V_28 -> V_94 , L_58 , V_278 ) ;
F_39 ( & V_28 -> V_81 , V_80 ) ;
F_136 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( ( V_34 -> V_279 ) && ( V_278 != 0 ) ) {
V_214 = V_34 -> V_279 ( V_55 -> V_51 , V_278 ) ;
if ( V_214 != 0 ) {
F_18 ( V_28 -> V_94 , L_59 ,
V_278 ) ;
break;
}
}
}
F_41 ( & V_28 -> V_81 , V_80 ) ;
return V_214 ;
}
static int F_162 ( struct V_193 * V_30 , T_8 V_277 , T_5 V_278 )
{
struct V_27 * V_28 = F_115 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
unsigned long V_80 ;
int V_214 = 0 ;
F_29 ( V_28 -> V_94 , L_60 , V_278 ) ;
F_39 ( & V_28 -> V_81 , V_80 ) ;
F_136 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( V_34 -> V_280 ) {
V_214 = V_34 -> V_280 ( V_55 -> V_51 , V_278 ) ;
if ( V_214 != 0 ) {
F_18 ( V_28 -> V_94 , L_61 ,
V_278 ) ;
break;
}
}
}
F_41 ( & V_28 -> V_81 , V_80 ) ;
return V_214 ;
}
static T_5 F_163 ( struct V_193 * V_36 , struct V_110 * V_111 ,
void * V_281 ,
T_9 V_282 )
{
return 0 ;
}
static int F_164 ( struct V_193 * V_36 , T_7 V_283 )
{
int V_14 ;
F_165 () ;
if ( ( V_36 -> V_284 <= 1 ) ||
( V_36 -> V_284 < V_283 ) )
return - V_62 ;
if ( V_283 ) {
F_166 ( V_36 , V_283 ) ;
for ( V_14 = 0 ; V_14 < V_283 ; V_14 ++ )
F_167 ( V_36 , V_14 , 1 , V_14 ) ;
} else {
F_168 ( V_36 ) ;
}
return 0 ;
}
static int F_169 ( struct V_32 * V_32 ,
struct V_24 * V_56 )
{
struct V_35 * V_36 = V_32 -> V_35 ;
struct V_24 * V_25 = V_36 -> V_39 ;
struct V_27 * V_28 ;
struct V_193 * V_30 ;
T_10 V_285 ;
struct V_286 V_287 ;
void T_2 * V_288 = NULL ;
T_1 V_19 = 0 ;
const void * V_289 ;
T_7 V_290 [ 6 ] ;
T_1 V_291 [ 2 ] ;
int V_29 = 0 ;
V_30 = F_170 ( sizeof( * V_28 ) , 1 , 1 ) ;
if ( ! V_30 ) {
F_18 ( V_36 , L_62 ) ;
return - V_47 ;
}
V_30 -> V_292 |= V_293 ;
V_30 -> V_292 |= V_294 ;
V_30 -> V_295 = V_30 -> V_292 ;
V_30 -> V_296 |= V_293 ;
V_28 = F_115 ( V_30 ) ;
F_171 ( & V_28 -> V_81 ) ;
F_172 ( & V_28 -> V_59 ) ;
F_172 ( & V_28 -> V_297 ) ;
F_172 ( & V_28 -> V_298 ) ;
F_172 ( & V_28 -> V_222 ) ;
V_28 -> V_32 = V_32 ;
V_28 -> V_36 = V_32 -> V_35 ;
V_28 -> V_30 = V_30 ;
V_28 -> V_94 = & V_30 -> V_36 ;
V_28 -> V_299 = F_173 ( V_300 , V_301 ) ;
V_28 -> V_201 = V_302 ;
V_28 -> V_157 = V_28 -> V_201 ;
V_28 -> V_56 = V_56 ;
V_29 = F_174 ( V_56 , L_63 , & V_19 ) ;
if ( V_19 ) {
if ( F_175 ( V_25 , V_303 , & V_287 ) ) {
F_18 ( V_36 , L_64 ) ;
V_29 = - V_61 ;
goto V_304;
}
V_285 = F_176 ( & V_287 ) ;
if ( ! F_177 ( V_36 , V_287 . V_305 , V_285 ,
F_122 ( V_36 ) ) ) {
F_18 ( V_36 , L_65 ) ;
V_29 = - V_47 ;
goto V_304;
}
V_288 = F_178 ( V_36 , V_287 . V_305 , V_285 ) ;
if ( ! V_288 ) {
F_18 ( V_36 , L_66 ) ;
F_179 ( V_36 , V_287 . V_305 , V_285 ) ;
V_29 = - V_47 ;
goto V_304;
}
F_10 ( V_290 , V_288 , V_19 ) ;
if ( F_180 ( V_290 ) )
F_130 ( V_30 -> V_306 , V_290 ) ;
else
F_181 ( V_30 -> V_306 ) ;
F_182 ( V_36 , V_288 ) ;
F_179 ( V_36 , V_287 . V_305 , V_285 ) ;
} else {
V_289 = F_183 ( V_56 ) ;
if ( V_289 )
F_130 ( V_30 -> V_306 , V_289 ) ;
else
F_181 ( V_30 -> V_306 ) ;
}
V_29 = F_13 ( V_56 , L_67 ,
& V_28 -> V_213 ) ;
if ( V_29 < 0 ) {
F_18 ( V_36 , L_68 ) ;
V_29 = - V_61 ;
goto V_304;
}
V_29 = F_174 ( V_56 , L_69 ,
& V_28 -> V_142 ) ;
if ( V_29 < 0 ) {
F_21 ( V_36 , L_70 ) ;
V_28 -> V_142 = V_307 ;
}
V_29 = F_184 ( V_56 , L_71 ,
V_28 -> V_146 ,
V_127 ) ;
if ( V_29 < 0 ) {
F_18 ( V_36 , L_72 ) ;
V_28 -> V_146 [ 0 ] = 128 ;
}
V_29 = F_184 ( V_56 , L_73 , V_291 , 2 ) ;
if ( V_29 < 0 ) {
F_18 ( V_36 , L_74 ) ;
V_29 = - V_61 ;
goto V_304;
}
V_28 -> V_128 = V_291 [ 0 ] ;
V_28 -> V_244 = V_291 [ 1 ] ;
V_29 = F_184 ( V_56 , L_75 , V_291 , 2 ) ;
if ( V_29 < 0 ) {
F_18 ( V_36 , L_76 ) ;
V_29 = - V_61 ;
goto V_304;
}
V_28 -> V_245 = V_291 [ 0 ] ;
V_28 -> V_246 = V_291 [ 1 ] ;
if ( V_28 -> V_245 < V_302 ) {
F_18 ( V_36 , L_77 ,
V_302 ) ;
V_29 = - V_61 ;
goto V_304;
}
V_29 = F_174 ( V_56 , L_78 ,
& V_28 -> V_172 ) ;
if ( V_29 < 0 ) {
F_21 ( V_36 , L_79 ) ;
V_28 -> V_172 = V_307 ;
}
F_185 ( V_30 , & V_28 -> V_149 , F_88 , V_308 ) ;
F_185 ( V_30 , & V_28 -> V_161 , F_101 , V_308 ) ;
V_30 -> V_309 = 0 ;
V_30 -> V_310 = V_311 ;
V_30 -> V_312 = & V_313 ;
F_186 ( V_30 , V_36 ) ;
F_23 ( & V_28 -> V_314 , & V_32 -> V_315 ) ;
return 0 ;
V_304:
F_187 ( V_30 ) ;
return V_29 ;
}
static void F_188 ( struct V_32 * V_32 ,
struct V_193 * V_30 )
{
struct V_54 * V_55 , * V_43 ;
struct V_27 * V_28 = F_115 ( V_30 ) ;
struct V_33 * V_34 ;
F_29 ( V_32 -> V_35 , L_80 ,
V_30 -> V_26 ) ;
F_36 (intf_modpriv, tmp, &netcp->module_head,
intf_list) {
V_34 = V_55 -> V_33 ;
F_29 ( V_32 -> V_35 , L_81 ,
V_34 -> V_26 ) ;
if ( V_34 -> V_71 )
V_34 -> V_71 ( V_55 -> V_51 ) ;
F_24 ( & V_55 -> V_58 ) ;
F_47 ( V_55 ) ;
}
F_31 ( ! F_189 ( & V_28 -> V_59 ) , L_82 ,
V_30 -> V_26 ) ;
F_24 ( & V_28 -> V_314 ) ;
F_20 ( V_28 -> V_56 ) ;
F_190 ( V_30 ) ;
F_191 ( & V_28 -> V_149 ) ;
F_187 ( V_30 ) ;
}
static int F_192 ( struct V_316 * V_317 )
{
struct V_24 * V_25 = V_317 -> V_36 . V_39 ;
struct V_27 * V_27 , * V_69 ;
struct V_24 * V_40 , * V_318 ;
struct V_32 * V_32 ;
struct V_35 * V_36 = & V_317 -> V_36 ;
int V_29 ;
if ( ! V_25 ) {
F_18 ( V_36 , L_83 ) ;
return - V_61 ;
}
V_32 = F_22 ( V_36 , sizeof( * V_32 ) , V_46 ) ;
if ( ! V_32 )
return - V_47 ;
F_193 ( & V_317 -> V_36 ) ;
V_29 = F_194 ( & V_317 -> V_36 ) ;
if ( V_29 < 0 ) {
F_18 ( V_36 , L_84 ) ;
F_195 ( & V_317 -> V_36 ) ;
return V_29 ;
}
F_172 ( & V_32 -> V_315 ) ;
F_172 ( & V_32 -> V_49 ) ;
V_32 -> V_35 = V_36 ;
F_196 ( V_317 , V_32 ) ;
V_318 = F_17 ( V_25 , L_85 ) ;
if ( ! V_318 ) {
F_18 ( V_36 , L_86 ) ;
V_29 = - V_61 ;
goto V_319;
}
F_19 (interfaces, child) {
V_29 = F_169 ( V_32 , V_40 ) ;
if ( V_29 ) {
F_18 ( V_36 , L_87 ,
V_40 -> V_26 ) ;
goto V_320;
}
}
F_23 ( & V_32 -> V_321 , & V_322 ) ;
return 0 ;
V_320:
F_36 (netcp_intf, netcp_tmp,
&netcp_device->interface_head,
interface_list) {
F_188 ( V_32 , V_27 -> V_30 ) ;
}
V_319:
F_197 ( & V_317 -> V_36 ) ;
F_195 ( & V_317 -> V_36 ) ;
F_196 ( V_317 , NULL ) ;
return V_29 ;
}
static int F_198 ( struct V_316 * V_317 )
{
struct V_32 * V_32 = F_199 ( V_317 ) ;
struct V_27 * V_27 , * V_69 ;
struct V_41 * V_42 , * V_43 ;
struct V_33 * V_34 ;
F_36 (inst_modpriv, tmp, &netcp_device->modpriv_head,
inst_list) {
V_34 = V_42 -> V_33 ;
F_29 ( & V_317 -> V_36 , L_88 , V_34 -> V_26 ) ;
V_34 -> remove ( V_32 , V_42 -> V_51 ) ;
F_24 ( & V_42 -> V_48 ) ;
F_47 ( V_42 ) ;
}
F_36 (netcp_intf, netcp_tmp,
&netcp_device->interface_head,
interface_list) {
F_188 ( V_32 , V_27 -> V_30 ) ;
}
F_31 ( ! F_189 ( & V_32 -> V_315 ) ,
L_89 , V_317 -> V_26 ) ;
F_197 ( & V_317 -> V_36 ) ;
F_195 ( & V_317 -> V_36 ) ;
F_196 ( V_317 , NULL ) ;
return 0 ;
}
