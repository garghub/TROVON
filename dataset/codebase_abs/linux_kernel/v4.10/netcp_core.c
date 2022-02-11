static void F_1 ( T_1 * V_1 , T_2 * V_2 , T_1 * V_3 ,
struct V_4 * V_5 )
{
* V_2 = F_2 ( V_5 -> V_2 ) ;
* V_1 = F_2 ( V_5 -> V_1 ) ;
* V_3 = F_2 ( V_5 -> V_6 ) ;
}
static T_2 F_3 ( int V_7 , struct V_4 * V_5 )
{
return V_5 -> V_8 [ V_7 ] ;
}
static void F_4 ( T_1 * V_1 , T_2 * V_2 ,
struct V_4 * V_5 )
{
* V_1 = F_2 ( V_5 -> V_9 ) ;
* V_2 = F_2 ( V_5 -> V_10 ) ;
}
static void F_5 ( T_1 * V_11 , int V_12 , T_3 * V_5 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
V_11 [ V_13 ] = F_2 ( V_5 [ V_13 ] ) ;
}
static void F_6 ( T_1 V_1 , T_2 V_2 , T_2 V_3 ,
struct V_4 * V_5 )
{
V_5 -> V_2 = F_7 ( V_2 ) ;
V_5 -> V_1 = F_7 ( V_1 ) ;
V_5 -> V_6 = F_7 ( V_3 ) ;
}
static void F_8 ( T_2 V_14 , T_2 V_15 ,
struct V_4 * V_5 )
{
V_5 -> V_14 = F_7 ( V_14 ) ;
V_5 -> V_16 = F_7 ( V_15 ) ;
}
static void F_9 ( int V_7 , T_2 V_17 , struct V_4 * V_5 )
{
V_5 -> V_8 [ V_7 ] = V_17 ;
}
static void F_10 ( T_1 V_1 , T_2 V_2 ,
struct V_4 * V_5 )
{
V_5 -> V_9 = F_7 ( V_1 ) ;
V_5 -> V_10 = F_7 ( V_2 ) ;
}
static void F_11 ( T_2 * V_11 , int V_12 , T_3 * V_5 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
V_5 [ V_13 ] = F_7 ( V_11 [ V_13 ] ) ;
}
static int F_12 ( char * V_18 , void T_4 * V_19 , T_2 V_20 )
{
unsigned int V_21 , V_22 ;
V_22 = F_13 ( V_19 + 4 ) ;
V_21 = F_13 ( V_19 ) ;
switch ( V_20 ) {
case V_23 :
V_21 = V_22 ;
V_22 = F_13 ( V_19 ) ;
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
static const char * F_14 ( struct V_24 * V_25 )
{
const char * V_26 ;
if ( F_15 ( V_25 , L_1 , & V_26 ) < 0 )
V_26 = V_25 -> V_26 ;
if ( ! V_26 )
V_26 = L_2 ;
return V_26 ;
}
static int F_16 ( struct V_27 * V_28 )
{
int V_29 ;
V_29 = F_17 ( V_28 -> V_30 ) ;
if ( ! V_29 )
V_28 -> V_31 = true ;
return V_29 ;
}
static int F_18 ( struct V_32 * V_32 ,
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
V_37 = F_19 ( V_25 , L_3 ) ;
if ( ! V_37 ) {
F_20 ( V_36 , L_4 ) ;
return V_45 ;
}
F_21 (devices, child) {
const char * V_26 = F_14 ( V_40 ) ;
if ( ! strcasecmp ( V_34 -> V_26 , V_26 ) )
break;
}
F_22 ( V_37 ) ;
if ( ! V_40 ) {
F_23 ( V_36 , L_5 , V_34 -> V_26 ) ;
return V_45 ;
}
V_42 = F_24 ( V_36 , sizeof( * V_42 ) , V_46 ) ;
if ( ! V_42 ) {
F_22 ( V_40 ) ;
return - V_47 ;
}
V_42 -> V_32 = V_32 ;
V_42 -> V_33 = V_34 ;
F_25 ( & V_42 -> V_48 , & V_32 -> V_49 ) ;
V_29 = V_34 -> V_50 ( V_32 , V_36 , V_40 ,
& V_42 -> V_51 ) ;
F_22 ( V_40 ) ;
if ( V_29 ) {
F_20 ( V_36 , L_6 ,
V_34 -> V_26 , V_29 ) ;
F_26 ( & V_42 -> V_48 ) ;
F_27 ( V_36 , V_42 ) ;
return V_52 ;
}
F_28 (tmp) {
if ( V_43 -> V_53 )
V_44 = true ;
}
if ( ! V_44 )
return 0 ;
F_29 (netcp_intf, &netcp_device->interface_head,
interface_list) {
struct V_54 * V_55 ;
V_55 = F_24 ( V_36 , sizeof( * V_55 ) ,
V_46 ) ;
if ( ! V_55 )
return - V_47 ;
V_38 = F_30 ( V_27 -> V_56 ,
V_34 -> V_26 , 0 ) ;
if ( ! V_38 ) {
F_27 ( V_36 , V_55 ) ;
continue;
}
V_55 -> V_57 = V_27 ;
V_55 -> V_33 = V_34 ;
F_25 ( & V_55 -> V_58 ,
& V_27 -> V_59 ) ;
V_29 = V_34 -> V_60 ( V_42 -> V_51 ,
V_27 -> V_30 , V_38 ,
& V_55 -> V_51 ) ;
F_22 ( V_38 ) ;
if ( V_29 ) {
F_31 ( V_36 , L_7 ,
V_34 -> V_26 , V_29 ) ;
F_26 ( & V_55 -> V_58 ) ;
F_27 ( V_36 , V_55 ) ;
continue;
}
}
F_29 (netcp_intf,
&netcp_device->interface_head,
interface_list) {
if ( ! V_27 -> V_31 ) {
V_29 = F_16 ( V_27 ) ;
if ( V_29 )
return - V_61 ;
}
}
return 0 ;
}
int F_32 ( struct V_33 * V_34 )
{
struct V_32 * V_32 ;
struct V_33 * V_43 ;
int V_29 ;
if ( ! V_34 -> V_26 ) {
F_33 ( 1 , L_8 ) ;
return - V_62 ;
}
if ( ! V_34 -> V_50 ) {
F_33 ( 1 , L_9 ) ;
return - V_62 ;
}
F_34 ( & V_63 ) ;
F_28 (tmp) {
if ( ! strcasecmp ( V_43 -> V_26 , V_34 -> V_26 ) ) {
F_35 ( & V_63 ) ;
return - V_64 ;
}
}
F_25 ( & V_34 -> V_65 , & V_66 ) ;
F_29 (netcp_device, &netcp_devices, device_list) {
V_29 = F_18 ( V_32 , V_34 ) ;
if ( V_29 < 0 )
goto V_67;
}
F_35 ( & V_63 ) ;
return 0 ;
V_67:
F_35 ( & V_63 ) ;
F_36 ( V_34 ) ;
return V_29 ;
}
static void F_37 ( struct V_32 * V_32 ,
struct V_33 * V_34 )
{
struct V_41 * V_42 , * V_68 ;
struct V_27 * V_27 , * V_69 ;
struct V_35 * V_36 = V_32 -> V_35 ;
F_38 (netcp_intf, netcp_tmp,
&netcp_device->interface_head,
interface_list) {
struct V_54 * V_55 , * V_70 ;
F_38 (intf_modpriv, intf_tmp,
&netcp_intf->module_head,
intf_list) {
if ( V_55 -> V_33 == V_34 ) {
V_34 -> V_71 ( V_55 -> V_51 ) ;
F_26 ( & V_55 -> V_58 ) ;
F_27 ( V_36 , V_55 ) ;
break;
}
}
}
F_38 (inst_modpriv, inst_tmp,
&netcp_device->modpriv_head, inst_list) {
if ( V_42 -> V_33 == V_34 ) {
V_34 -> remove ( V_32 ,
V_42 -> V_51 ) ;
F_26 ( & V_42 -> V_48 ) ;
F_27 ( V_36 , V_42 ) ;
break;
}
}
}
void F_36 ( struct V_33 * V_34 )
{
struct V_32 * V_32 ;
struct V_33 * V_72 ;
F_34 ( & V_63 ) ;
F_29 (netcp_device, &netcp_devices, device_list) {
F_37 ( V_32 , V_34 ) ;
}
F_28 (module_tmp) {
if ( V_34 == V_72 ) {
F_26 ( & V_34 -> V_65 ) ;
break;
}
}
F_35 ( & V_63 ) ;
}
void * F_39 ( struct V_33 * V_34 ,
struct V_27 * V_73 )
{
struct V_54 * V_55 ;
F_29 (intf_modpriv, &intf->module_head, intf_list)
if ( V_55 -> V_33 == V_34 )
return V_55 -> V_51 ;
return NULL ;
}
int F_40 ( struct V_27 * V_57 , int V_74 ,
T_5 * V_75 , void * V_76 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 ;
unsigned long V_80 ;
V_78 = F_24 ( V_57 -> V_36 , sizeof( * V_78 ) , V_46 ) ;
if ( ! V_78 )
return - V_47 ;
V_78 -> V_75 = V_75 ;
V_78 -> V_76 = V_76 ;
V_78 -> V_74 = V_74 ;
F_41 ( & V_57 -> V_81 , V_80 ) ;
F_29 (next, &netcp_priv->txhook_list_head, list) {
if ( V_79 -> V_74 > V_74 )
break;
}
F_42 ( & V_78 -> V_82 , V_79 -> V_82 . V_83 , & V_79 -> V_82 ) ;
F_43 ( & V_57 -> V_81 , V_80 ) ;
return 0 ;
}
int F_44 ( struct V_27 * V_57 , int V_74 ,
T_5 * V_75 , void * V_76 )
{
struct V_77 * V_79 , * V_84 ;
unsigned long V_80 ;
F_41 ( & V_57 -> V_81 , V_80 ) ;
F_38 (next, n, &netcp_priv->txhook_list_head, list) {
if ( ( V_79 -> V_74 == V_74 ) &&
( V_79 -> V_75 == V_75 ) &&
( V_79 -> V_76 == V_76 ) ) {
F_26 ( & V_79 -> V_82 ) ;
F_43 ( & V_57 -> V_81 , V_80 ) ;
F_27 ( V_57 -> V_36 , V_79 ) ;
return 0 ;
}
}
F_43 ( & V_57 -> V_81 , V_80 ) ;
return - V_85 ;
}
int F_45 ( struct V_27 * V_57 , int V_74 ,
T_5 * V_75 , void * V_76 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 ;
unsigned long V_80 ;
V_78 = F_24 ( V_57 -> V_36 , sizeof( * V_78 ) , V_46 ) ;
if ( ! V_78 )
return - V_47 ;
V_78 -> V_75 = V_75 ;
V_78 -> V_76 = V_76 ;
V_78 -> V_74 = V_74 ;
F_41 ( & V_57 -> V_81 , V_80 ) ;
F_29 (next, &netcp_priv->rxhook_list_head, list) {
if ( V_79 -> V_74 > V_74 )
break;
}
F_42 ( & V_78 -> V_82 , V_79 -> V_82 . V_83 , & V_79 -> V_82 ) ;
F_43 ( & V_57 -> V_81 , V_80 ) ;
return 0 ;
}
int F_46 ( struct V_27 * V_57 , int V_74 ,
T_5 * V_75 , void * V_76 )
{
struct V_77 * V_79 , * V_84 ;
unsigned long V_80 ;
F_41 ( & V_57 -> V_81 , V_80 ) ;
F_38 (next, n, &netcp_priv->rxhook_list_head, list) {
if ( ( V_79 -> V_74 == V_74 ) &&
( V_79 -> V_75 == V_75 ) &&
( V_79 -> V_76 == V_76 ) ) {
F_26 ( & V_79 -> V_82 ) ;
F_43 ( & V_57 -> V_81 , V_80 ) ;
F_27 ( V_57 -> V_36 , V_79 ) ;
return 0 ;
}
}
F_43 ( & V_57 -> V_81 , V_80 ) ;
return - V_85 ;
}
static void F_47 ( bool V_86 , void * V_87 )
{
if ( V_86 )
F_48 ( V_87 ) ;
else
F_49 ( V_87 ) ;
}
static void F_50 ( struct V_27 * V_28 ,
struct V_4 * V_5 )
{
struct V_4 * V_3 ;
T_1 V_88 , V_89 ;
unsigned int V_90 , V_91 = sizeof( * V_3 ) ;
void * V_92 ;
T_2 V_43 ;
F_5 ( & V_88 , 1 , & V_5 -> V_6 ) ;
while ( V_88 ) {
V_3 = F_51 ( V_28 -> V_93 , V_88 , V_91 ) ;
if ( F_52 ( ! V_3 ) ) {
F_20 ( V_28 -> V_94 , L_10 ) ;
break;
}
F_1 ( & V_89 , & V_43 , & V_88 , V_3 ) ;
V_92 = ( void * ) F_53 ( V_3 ) ;
V_90 = ( int ) F_54 ( V_5 ) ;
F_55 ( V_28 -> V_36 , V_89 , V_95 , V_96 ) ;
F_56 ( V_92 ) ;
F_57 ( V_28 -> V_93 , V_5 ) ;
}
V_92 = ( void * ) F_53 ( V_5 ) ;
V_90 = ( int ) F_54 ( V_5 ) ;
if ( V_92 )
F_47 ( V_90 <= V_95 , V_92 ) ;
F_57 ( V_28 -> V_93 , V_5 ) ;
}
static void F_58 ( struct V_27 * V_28 )
{
struct V_4 * V_5 ;
unsigned int V_91 ;
T_1 V_97 ;
for (; ; ) {
V_97 = F_59 ( V_28 -> V_98 , & V_91 ) ;
if ( ! V_97 )
break;
V_5 = F_51 ( V_28 -> V_93 , V_97 , V_91 ) ;
if ( F_52 ( ! V_5 ) ) {
F_20 ( V_28 -> V_94 , L_11 ,
V_99 ) ;
V_28 -> V_30 -> V_100 . V_101 ++ ;
continue;
}
F_50 ( V_28 , V_5 ) ;
V_28 -> V_30 -> V_100 . V_102 ++ ;
}
}
static int F_60 ( struct V_27 * V_28 )
{
unsigned int V_91 , V_90 , V_103 ;
struct V_4 * V_5 , * V_3 ;
unsigned int V_104 = 0 , V_105 ;
struct V_77 * V_106 ;
T_1 V_88 , V_107 ;
struct V_108 V_109 ;
struct V_110 * V_111 ;
void * V_112 ;
V_88 = F_59 ( V_28 -> V_98 , & V_91 ) ;
if ( ! V_88 )
return - 1 ;
V_5 = F_51 ( V_28 -> V_93 , V_88 , V_91 ) ;
if ( F_52 ( ! V_5 ) ) {
F_20 ( V_28 -> V_94 , L_10 ) ;
return 0 ;
}
F_1 ( & V_107 , & V_90 , & V_88 , V_5 ) ;
V_112 = ( void * ) F_53 ( V_5 ) ;
V_103 = ( int ) F_54 ( V_5 ) ;
if ( F_52 ( ! V_112 ) ) {
F_20 ( V_28 -> V_94 , L_12 ) ;
goto V_113;
}
V_104 &= V_114 ;
V_105 = V_90 ;
F_61 ( V_28 -> V_36 , V_107 , V_90 , V_96 ) ;
V_111 = F_62 ( V_112 , V_103 ) ;
if ( F_52 ( ! V_111 ) ) {
F_20 ( V_28 -> V_94 , L_13 ) ;
goto V_113;
}
F_63 ( V_111 , V_115 ) ;
F_64 ( V_111 , V_90 ) ;
while ( V_88 ) {
struct V_116 * V_116 ;
V_3 = F_51 ( V_28 -> V_93 , V_88 , V_91 ) ;
if ( F_52 ( ! V_3 ) ) {
F_20 ( V_28 -> V_94 , L_10 ) ;
goto V_113;
}
F_1 ( & V_107 , & V_90 , & V_88 , V_3 ) ;
V_116 = (struct V_116 * ) F_53 ( V_5 ) ;
if ( F_65 ( V_107 && V_90 && V_116 ) ) {
F_55 ( V_28 -> V_36 , V_107 , V_95 ,
V_96 ) ;
} else {
F_20 ( V_28 -> V_94 , L_14 ,
& V_107 , V_90 , V_116 ) ;
goto V_113;
}
F_66 ( V_111 , F_67 ( V_111 ) -> V_117 , V_116 ,
F_68 ( V_107 ) , V_90 , V_95 ) ;
V_105 += V_90 ;
F_57 ( V_28 -> V_93 , V_3 ) ;
}
F_57 ( V_28 -> V_93 , V_5 ) ;
if ( F_52 ( V_104 != V_105 ) )
F_31 ( V_28 -> V_94 , L_15 ,
V_104 , V_105 ) ;
F_69 ( V_111 , V_111 -> V_118 - V_119 ) ;
V_109 . V_111 = V_111 ;
V_111 -> V_36 = V_28 -> V_30 ;
V_109 . V_120 = false ;
F_29 (rx_hook, &netcp->rxhook_list_head, list) {
int V_29 ;
V_29 = V_106 -> V_75 ( V_106 -> V_74 , V_106 -> V_76 ,
& V_109 ) ;
if ( F_52 ( V_29 ) ) {
F_20 ( V_28 -> V_94 , L_16 ,
V_106 -> V_74 , V_29 ) ;
V_28 -> V_30 -> V_100 . V_101 ++ ;
F_70 ( V_111 ) ;
return 0 ;
}
}
V_28 -> V_30 -> V_100 . V_121 ++ ;
V_28 -> V_30 -> V_100 . V_122 += V_111 -> V_118 ;
V_111 -> V_123 = F_71 ( V_111 , V_28 -> V_30 ) ;
F_72 ( V_111 ) ;
return 0 ;
V_113:
F_50 ( V_28 , V_5 ) ;
V_28 -> V_30 -> V_100 . V_101 ++ ;
return 0 ;
}
static int F_73 ( struct V_27 * V_28 ,
unsigned int V_124 )
{
int V_13 ;
for ( V_13 = 0 ; ( V_13 < V_124 ) && ! F_60 ( V_28 ) ; V_13 ++ )
;
return V_13 ;
}
static void F_74 ( struct V_27 * V_28 , int V_125 )
{
struct V_4 * V_5 ;
unsigned int V_90 , V_91 ;
T_1 V_97 ;
void * V_92 ;
while ( ( V_97 = F_59 ( V_28 -> V_126 [ V_125 ] , & V_91 ) ) ) {
V_5 = F_51 ( V_28 -> V_93 , V_97 , V_91 ) ;
if ( F_52 ( ! V_5 ) ) {
F_20 ( V_28 -> V_94 , L_10 ) ;
continue;
}
F_4 ( & V_97 , & V_90 , V_5 ) ;
V_92 = ( void * ) F_53 ( V_5 ) ;
if ( F_52 ( ! V_97 ) ) {
F_20 ( V_28 -> V_94 , L_17 ) ;
F_57 ( V_28 -> V_93 , V_5 ) ;
continue;
}
if ( F_52 ( ! V_92 ) ) {
F_20 ( V_28 -> V_94 , L_12 ) ;
F_57 ( V_28 -> V_93 , V_5 ) ;
continue;
}
if ( V_125 == 0 ) {
F_61 ( V_28 -> V_36 , V_97 , V_90 ,
V_96 ) ;
F_47 ( ( V_90 <= V_95 ) , V_92 ) ;
} else {
F_55 ( V_28 -> V_36 , V_97 , V_90 ,
V_96 ) ;
F_56 ( V_92 ) ;
}
F_57 ( V_28 -> V_93 , V_5 ) ;
}
}
static void F_75 ( struct V_27 * V_28 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_127 &&
! F_76 ( V_28 -> V_126 [ V_13 ] ) ; V_13 ++ )
F_74 ( V_28 , V_13 ) ;
if ( F_77 ( V_28 -> V_93 ) != V_28 -> V_128 )
F_20 ( V_28 -> V_94 , L_18 ,
V_28 -> V_128 - F_77 ( V_28 -> V_93 ) ) ;
F_78 ( V_28 -> V_93 ) ;
V_28 -> V_93 = NULL ;
}
static int F_79 ( struct V_27 * V_28 , int V_125 )
{
struct V_4 * V_129 ;
unsigned int V_90 , V_91 ;
T_2 V_14 , V_15 ;
struct V_116 * V_116 ;
T_1 V_97 ;
void * V_130 ;
T_2 V_8 [ 2 ] ;
V_129 = F_80 ( V_28 -> V_93 ) ;
if ( F_76 ( V_129 ) ) {
F_31 ( V_28 -> V_94 , L_19 ) ;
return - V_47 ;
}
if ( F_65 ( V_125 == 0 ) ) {
unsigned int V_131 ;
V_90 = V_132 + V_115 ;
V_131 = F_81 ( V_90 ) +
F_81 ( sizeof( struct V_133 ) ) ;
V_130 = F_82 ( V_131 ) ;
V_8 [ 1 ] = V_131 ;
if ( F_52 ( ! V_130 ) ) {
F_83 ( V_28 -> V_94 ,
L_20 ) ;
goto V_67;
}
V_97 = F_84 ( V_28 -> V_36 , V_130 , V_90 ,
V_134 ) ;
if ( F_52 ( F_85 ( V_28 -> V_36 , V_97 ) ) )
goto V_67;
V_8 [ 0 ] = ( T_2 ) V_130 ;
} else {
V_116 = F_86 ( V_135 | V_136 | V_137 ) ;
if ( F_52 ( ! V_116 ) ) {
F_83 ( V_28 -> V_94 , L_21 ) ;
goto V_67;
}
V_90 = V_95 ;
V_97 = F_87 ( V_28 -> V_36 , V_116 , 0 , V_90 , V_134 ) ;
V_8 [ 0 ] = ( T_2 ) V_116 ;
V_8 [ 1 ] = 0 ;
}
V_14 = V_138 ;
V_14 |= V_90 & V_114 ;
V_15 = V_139 ;
V_15 |= V_140 << V_141 ;
V_15 |= ( V_28 -> V_142 & V_143 ) <<
V_144 ;
F_10 ( V_97 , V_90 , V_129 ) ;
F_88 ( V_8 [ 0 ] , V_129 ) ;
F_89 ( V_8 [ 1 ] , V_129 ) ;
F_8 ( V_14 , V_15 , V_129 ) ;
F_90 ( V_28 -> V_93 , V_129 , sizeof( * V_129 ) , & V_97 ,
& V_91 ) ;
F_91 ( V_28 -> V_126 [ V_125 ] , V_97 , sizeof( * V_129 ) , 0 ) ;
return 0 ;
V_67:
F_57 ( V_28 -> V_93 , V_129 ) ;
return - V_47 ;
}
static void F_92 ( struct V_27 * V_28 )
{
T_2 V_145 [ V_127 ] = { 0 } ;
int V_13 , V_29 = 0 ;
for ( V_13 = 0 ; V_13 < V_127 && V_28 -> V_126 [ V_13 ] ; V_13 ++ ) {
V_145 [ V_13 ] = V_28 -> V_146 [ V_13 ] -
F_93 ( V_28 -> V_126 [ V_13 ] ) ;
while ( V_145 [ V_13 ] -- && ! V_29 )
V_29 = F_79 ( V_28 , V_13 ) ;
}
}
static int F_94 ( struct V_147 * V_148 , int V_124 )
{
struct V_27 * V_28 = F_95 ( V_148 , struct V_27 ,
V_149 ) ;
unsigned int V_150 ;
V_150 = F_73 ( V_28 , V_124 ) ;
F_92 ( V_28 ) ;
if ( V_150 < V_124 ) {
F_96 ( & V_28 -> V_149 ) ;
F_97 ( V_28 -> V_98 ) ;
}
return V_150 ;
}
static void F_98 ( void * V_151 )
{
struct V_27 * V_28 = V_151 ;
F_99 ( V_28 -> V_98 ) ;
F_100 ( & V_28 -> V_149 ) ;
}
static void F_101 ( struct V_27 * V_28 ,
struct V_4 * V_5 ,
unsigned int V_152 )
{
struct V_4 * V_3 = V_5 ;
T_1 V_88 , V_89 ;
unsigned int V_90 ;
while ( V_3 ) {
F_1 ( & V_89 , & V_90 , & V_88 , V_3 ) ;
if ( V_89 && V_90 )
F_61 ( V_28 -> V_36 , V_89 , V_90 ,
V_134 ) ;
else
F_23 ( V_28 -> V_94 , L_22 ,
& V_89 , V_90 ) ;
F_57 ( V_28 -> V_153 , V_3 ) ;
V_3 = NULL ;
if ( V_88 ) {
V_3 = F_51 ( V_28 -> V_153 , V_88 ,
V_152 ) ;
if ( ! V_3 )
F_20 ( V_28 -> V_94 , L_23 ) ;
}
}
}
static int F_102 ( struct V_27 * V_28 ,
unsigned int V_124 )
{
struct V_4 * V_5 ;
struct V_154 * V_155 ;
struct V_110 * V_111 ;
unsigned int V_91 ;
T_1 V_97 ;
int V_156 = 0 ;
while ( V_124 -- ) {
V_97 = F_59 ( V_28 -> V_157 , & V_91 ) ;
if ( ! V_97 )
break;
V_5 = F_51 ( V_28 -> V_153 , V_97 , V_91 ) ;
if ( F_52 ( ! V_5 ) ) {
F_20 ( V_28 -> V_94 , L_23 ) ;
V_28 -> V_30 -> V_100 . V_158 ++ ;
continue;
}
V_111 = (struct V_110 * ) F_53 ( V_5 ) ;
F_101 ( V_28 , V_5 , V_91 ) ;
if ( ! V_111 ) {
F_20 ( V_28 -> V_94 , L_24 ) ;
V_28 -> V_30 -> V_100 . V_158 ++ ;
continue;
}
V_155 = (struct V_154 * ) V_111 -> V_159 ;
if ( V_155 -> V_160 )
V_155 -> V_160 ( V_155 -> V_161 , V_111 ) ;
if ( F_103 ( V_28 -> V_30 , V_111 ) &&
F_104 ( V_28 -> V_30 ) &&
( F_77 ( V_28 -> V_153 ) >
V_28 -> V_162 ) ) {
T_6 V_163 = F_105 ( V_111 ) ;
F_106 ( V_28 -> V_30 , V_163 ) ;
}
V_28 -> V_30 -> V_100 . V_164 ++ ;
V_28 -> V_30 -> V_100 . V_165 += V_111 -> V_118 ;
F_70 ( V_111 ) ;
V_156 ++ ;
}
return V_156 ;
}
static int F_107 ( struct V_147 * V_148 , int V_124 )
{
int V_150 ;
struct V_27 * V_28 = F_95 ( V_148 , struct V_27 ,
V_166 ) ;
V_150 = F_102 ( V_28 , V_124 ) ;
if ( V_150 < V_124 ) {
F_96 ( & V_28 -> V_166 ) ;
F_97 ( V_28 -> V_157 ) ;
}
return V_150 ;
}
static void F_108 ( void * V_151 )
{
struct V_27 * V_28 = V_151 ;
F_99 ( V_28 -> V_157 ) ;
F_100 ( & V_28 -> V_166 ) ;
}
static struct V_4 *
F_109 ( struct V_110 * V_111 , struct V_27 * V_28 )
{
struct V_4 * V_5 , * V_3 , * V_167 ;
unsigned int V_168 = F_110 ( V_111 ) ;
struct V_35 * V_36 = V_28 -> V_36 ;
T_1 V_169 ;
unsigned int V_91 ;
int V_13 ;
V_169 = F_84 ( V_36 , V_111 -> V_17 , V_168 , V_134 ) ;
if ( F_52 ( F_85 ( V_36 , V_169 ) ) ) {
F_20 ( V_28 -> V_94 , L_25 ) ;
return NULL ;
}
V_5 = F_80 ( V_28 -> V_153 ) ;
if ( F_76 ( V_5 ) ) {
F_20 ( V_28 -> V_94 , L_26 ) ;
F_61 ( V_36 , V_169 , V_168 , V_134 ) ;
return NULL ;
}
F_6 ( V_169 , V_168 , 0 , V_5 ) ;
if ( F_111 ( V_111 ) ) {
F_112 ( F_67 ( V_111 ) ) ;
} else {
V_5 -> V_6 = 0 ;
goto V_170;
}
V_167 = V_5 ;
for ( V_13 = 0 ; V_13 < F_67 ( V_111 ) -> V_117 ; V_13 ++ ) {
T_7 * V_171 = & F_67 ( V_111 ) -> V_172 [ V_13 ] ;
struct V_116 * V_116 = F_113 ( V_171 ) ;
T_2 V_173 = V_171 -> V_173 ;
T_2 V_90 = F_114 ( V_171 ) ;
T_1 V_174 ;
T_2 V_175 ;
T_2 V_15 ;
V_169 = F_87 ( V_36 , V_116 , V_173 , V_90 ,
V_134 ) ;
if ( F_52 ( ! V_169 ) ) {
F_20 ( V_28 -> V_94 , L_27 ) ;
goto V_176;
}
V_3 = F_80 ( V_28 -> V_153 ) ;
if ( F_76 ( V_3 ) ) {
F_20 ( V_28 -> V_94 , L_28 ) ;
F_55 ( V_36 , V_169 , V_90 , V_134 ) ;
goto V_176;
}
V_174 = F_115 ( V_28 -> V_153 , V_3 ) ;
V_15 =
( V_28 -> V_177 & V_143 ) <<
V_144 ;
F_6 ( V_169 , V_90 , 0 , V_3 ) ;
V_175 = ( T_2 ) V_174 ;
F_11 ( & V_175 , 1 , & V_167 -> V_6 ) ;
V_168 += V_90 ;
if ( V_167 != V_5 )
F_90 ( V_28 -> V_153 , V_167 ,
sizeof( * V_167 ) , & V_174 , & V_91 ) ;
V_167 = V_3 ;
}
if ( V_167 != V_5 )
F_90 ( V_28 -> V_153 , V_167 , sizeof( * V_167 ) ,
& V_169 , & V_91 ) ;
if ( F_67 ( V_111 ) -> V_178 ) {
F_116 ( V_28 -> V_94 , L_29 ) ;
goto V_176;
}
V_170:
F_117 ( V_168 != V_111 -> V_118 ) ;
V_168 &= V_114 ;
F_11 ( & V_168 , 1 , & V_5 -> V_14 ) ;
return V_5 ;
V_176:
F_101 ( V_28 , V_5 , sizeof( * V_5 ) ) ;
return NULL ;
}
static int F_118 ( struct V_27 * V_28 ,
struct V_110 * V_111 ,
struct V_4 * V_5 )
{
struct V_179 * V_180 = NULL ;
struct V_77 * V_181 ;
struct V_108 V_109 ;
struct V_154 * V_155 ;
unsigned int V_91 ;
T_1 V_97 ;
T_2 V_43 = 0 ;
int V_29 = 0 ;
V_109 . V_28 = V_28 ;
V_109 . V_111 = V_111 ;
V_109 . V_180 = NULL ;
V_109 . V_182 = 0 ;
V_109 . V_161 = NULL ;
V_109 . V_160 = NULL ;
V_109 . V_183 = V_5 -> V_183 ;
V_109 . V_184 = ( T_2 V_185 * ) V_5 -> V_184 ;
memset ( V_109 . V_183 , 0 , V_186 * sizeof( T_3 ) ) ;
F_29 (tx_hook, &netcp->txhook_list_head, list) {
V_29 = V_181 -> V_75 ( V_181 -> V_74 , V_181 -> V_76 ,
& V_109 ) ;
if ( F_52 ( V_29 != 0 ) ) {
F_20 ( V_28 -> V_94 , L_30 ,
V_181 -> V_74 , V_29 ) ;
V_29 = ( V_29 < 0 ) ? V_29 : V_187 ;
goto V_188;
}
}
V_180 = V_109 . V_180 ;
if ( ! V_180 ) {
F_20 ( V_28 -> V_94 , L_31 ) ;
V_29 = - V_189 ;
goto V_188;
}
V_155 = (struct V_154 * ) V_111 -> V_159 ;
V_155 -> V_161 = V_109 . V_161 ;
V_155 -> V_160 = V_109 . V_160 ;
if ( V_109 . V_182 ) {
T_3 * V_184 = ( void V_185 * ) V_109 . V_184 ;
memmove ( V_109 . V_184 , V_109 . V_184 + V_109 . V_182 ,
V_109 . V_182 ) ;
F_11 ( V_109 . V_184 , V_109 . V_182 , V_184 ) ;
V_43 |= ( V_109 . V_182 & V_190 ) <<
V_141 ;
}
V_43 |= V_139 |
( ( V_28 -> V_177 & V_143 ) <<
V_144 ) ;
if ( ! ( V_180 -> V_80 & V_191 ) ) {
V_43 |= ( ( V_180 -> V_192 & V_193 ) <<
V_194 ) ;
}
F_11 ( & V_43 , 1 , & V_5 -> V_16 ) ;
F_88 ( ( T_2 ) V_111 , V_5 ) ;
if ( V_180 -> V_80 & V_191 ) {
V_43 = V_180 -> V_192 ;
F_11 ( & V_43 , 1 , & V_5 -> V_195 ) ;
}
V_29 = F_90 ( V_28 -> V_153 , V_5 , sizeof( * V_5 ) , & V_97 ,
& V_91 ) ;
if ( F_52 ( V_29 ) ) {
F_20 ( V_28 -> V_94 , L_32 , V_99 ) ;
V_29 = - V_47 ;
goto V_188;
}
F_119 ( V_111 ) ;
F_91 ( V_180 -> V_196 , V_97 , V_91 , 0 ) ;
V_188:
return V_29 ;
}
static int F_120 ( struct V_110 * V_111 , struct V_197 * V_30 )
{
struct V_27 * V_28 = F_121 ( V_30 ) ;
int V_163 = F_105 ( V_111 ) ;
struct V_4 * V_5 ;
int V_198 , V_29 = 0 ;
if ( F_52 ( V_111 -> V_118 <= 0 ) ) {
F_70 ( V_111 ) ;
return V_187 ;
}
if ( F_52 ( V_111 -> V_118 < V_199 ) ) {
V_29 = F_122 ( V_111 , V_199 ) ;
if ( V_29 < 0 ) {
F_23 ( V_28 -> V_94 , L_33 ,
V_29 ) ;
V_30 -> V_100 . V_200 ++ ;
return V_29 ;
}
V_111 -> V_118 = V_199 ;
}
V_5 = F_109 ( V_111 , V_28 ) ;
if ( F_52 ( ! V_5 ) ) {
F_123 ( V_30 , V_163 ) ;
V_29 = - V_201 ;
goto V_202;
}
V_29 = F_118 ( V_28 , V_111 , V_5 ) ;
if ( V_29 )
goto V_202;
F_124 ( V_30 ) ;
V_198 = F_77 ( V_28 -> V_153 ) ;
if ( V_198 < V_28 -> V_203 ) {
F_31 ( V_28 -> V_94 , L_34 , V_198 ) ;
F_123 ( V_30 , V_163 ) ;
}
return V_187 ;
V_202:
V_30 -> V_100 . V_200 ++ ;
if ( V_5 )
F_101 ( V_28 , V_5 , sizeof( * V_5 ) ) ;
F_70 ( V_111 ) ;
return V_29 ;
}
int F_125 ( struct V_179 * V_180 )
{
if ( V_180 -> V_204 ) {
F_126 ( V_180 -> V_204 ) ;
V_180 -> V_204 = NULL ;
}
return 0 ;
}
int F_127 ( struct V_179 * V_180 )
{
struct V_35 * V_36 = V_180 -> V_32 -> V_35 ;
struct V_205 V_206 ;
int V_29 = 0 ;
T_8 V_26 [ 16 ] ;
memset ( & V_206 , 0 , sizeof( V_206 ) ) ;
V_206 . V_207 = V_208 ;
V_206 . V_209 . V_210 . V_211 = false ;
V_206 . V_209 . V_210 . V_212 = false ;
V_206 . V_209 . V_210 . V_213 = V_214 ;
V_180 -> V_204 = F_128 ( V_36 ,
V_180 -> V_215 , & V_206 ) ;
if ( F_76 ( V_180 -> V_204 ) ) {
F_20 ( V_36 , L_35 ,
V_180 -> V_215 ) ;
goto V_216;
}
snprintf ( V_26 , sizeof( V_26 ) , L_36 , F_129 ( V_36 ) ) ;
V_180 -> V_196 = F_130 ( V_26 , V_180 -> V_217 ,
V_218 ) ;
if ( F_131 ( V_180 -> V_196 ) ) {
F_20 ( V_36 , L_37 ,
V_26 , V_29 ) ;
V_29 = F_132 ( V_180 -> V_196 ) ;
goto V_216;
}
F_31 ( V_36 , L_38 , V_26 ) ;
return 0 ;
V_216:
if ( ! F_76 ( V_180 -> V_204 ) )
F_126 ( V_180 -> V_204 ) ;
V_180 -> V_204 = NULL ;
return V_29 ;
}
int F_133 ( struct V_179 * V_180 ,
struct V_32 * V_32 ,
const char * V_215 , unsigned int V_217 )
{
memset ( V_180 , 0 , sizeof( * V_180 ) ) ;
V_180 -> V_32 = V_32 ;
V_180 -> V_215 = V_215 ;
V_180 -> V_217 = V_217 ;
return 0 ;
}
static struct V_219 * F_134 ( struct V_27 * V_28 ,
const T_8 * V_220 ,
enum V_221 type )
{
struct V_219 * V_222 ;
F_29 (naddr, &netcp->addr_list, node) {
if ( V_222 -> type != type )
continue;
if ( V_220 && memcmp ( V_220 , V_222 -> V_220 , V_223 ) )
continue;
return V_222 ;
}
return NULL ;
}
static struct V_219 * F_135 ( struct V_27 * V_28 ,
const T_8 * V_220 ,
enum V_221 type )
{
struct V_219 * V_222 ;
V_222 = F_136 ( V_28 -> V_36 , sizeof( * V_222 ) , V_135 ) ;
if ( ! V_222 )
return NULL ;
V_222 -> type = type ;
V_222 -> V_80 = 0 ;
V_222 -> V_28 = V_28 ;
if ( V_220 )
F_137 ( V_222 -> V_220 , V_220 ) ;
else
F_138 ( V_222 -> V_220 ) ;
F_25 ( & V_222 -> V_25 , & V_28 -> V_224 ) ;
return V_222 ;
}
static void F_139 ( struct V_27 * V_28 , struct V_219 * V_222 )
{
F_26 ( & V_222 -> V_25 ) ;
F_27 ( V_28 -> V_36 , V_222 ) ;
}
static void F_140 ( struct V_27 * V_28 )
{
struct V_219 * V_222 ;
F_29 (naddr, &netcp->addr_list, node)
V_222 -> V_80 = 0 ;
}
static void F_141 ( struct V_27 * V_28 , const T_8 * V_220 ,
enum V_221 type )
{
struct V_219 * V_222 ;
V_222 = F_134 ( V_28 , V_220 , type ) ;
if ( V_222 ) {
V_222 -> V_80 |= V_225 ;
return;
}
V_222 = F_135 ( V_28 , V_220 , type ) ;
if ( ! F_117 ( ! V_222 ) )
V_222 -> V_80 |= V_226 ;
}
static void F_142 ( struct V_27 * V_28 )
{
struct V_219 * V_222 , * V_43 ;
struct V_54 * V_227 ;
struct V_33 * V_34 ;
int error ;
F_38 (naddr, tmp, &netcp->addr_list, node) {
if ( V_222 -> V_80 & ( V_225 | V_226 ) )
continue;
F_31 ( V_28 -> V_94 , L_39 ,
V_222 -> V_220 , V_222 -> type ) ;
F_143 (netcp, priv) {
V_34 = V_227 -> V_33 ;
if ( ! V_34 -> V_228 )
continue;
error = V_34 -> V_228 ( V_227 -> V_51 ,
V_222 ) ;
F_117 ( error ) ;
}
F_139 ( V_28 , V_222 ) ;
}
}
static void F_144 ( struct V_27 * V_28 )
{
struct V_219 * V_222 , * V_43 ;
struct V_54 * V_227 ;
struct V_33 * V_34 ;
int error ;
F_38 (naddr, tmp, &netcp->addr_list, node) {
if ( ! ( V_222 -> V_80 & V_226 ) )
continue;
F_31 ( V_28 -> V_94 , L_40 ,
V_222 -> V_220 , V_222 -> type ) ;
F_143 (netcp, priv) {
V_34 = V_227 -> V_33 ;
if ( ! V_34 -> V_229 )
continue;
error = V_34 -> V_229 ( V_227 -> V_51 , V_222 ) ;
F_117 ( error ) ;
}
}
}
static void F_145 ( struct V_197 * V_30 )
{
struct V_27 * V_28 = F_121 ( V_30 ) ;
struct V_230 * V_231 ;
bool V_232 ;
V_232 = ( V_30 -> V_80 & V_233 ||
V_30 -> V_80 & V_234 ||
F_146 ( V_30 ) > V_235 ) ;
F_147 ( & V_28 -> V_81 ) ;
F_140 ( V_28 ) ;
F_141 ( V_28 , V_30 -> V_236 , V_237 ) ;
F_148 (ndev, ndev_addr)
F_141 ( V_28 , V_231 -> V_220 , V_238 ) ;
F_149 (ndev_addr, ndev)
F_141 ( V_28 , V_231 -> V_220 , V_239 ) ;
F_150 (ndev_addr, ndev)
F_141 ( V_28 , V_231 -> V_220 , V_240 ) ;
if ( V_232 )
F_141 ( V_28 , NULL , V_241 ) ;
F_142 ( V_28 ) ;
F_144 ( V_28 ) ;
F_151 ( & V_28 -> V_81 ) ;
}
static void F_152 ( struct V_27 * V_28 )
{
int V_13 ;
if ( V_28 -> V_242 ) {
F_126 ( V_28 -> V_242 ) ;
V_28 -> V_242 = NULL ;
}
if ( ! F_76 ( V_28 -> V_93 ) )
F_75 ( V_28 ) ;
if ( ! F_76 ( V_28 -> V_98 ) ) {
F_153 ( V_28 -> V_98 ) ;
V_28 -> V_98 = NULL ;
}
for ( V_13 = 0 ; V_13 < V_127 &&
! F_76 ( V_28 -> V_126 [ V_13 ] ) ; ++ V_13 ) {
F_153 ( V_28 -> V_126 [ V_13 ] ) ;
V_28 -> V_126 [ V_13 ] = NULL ;
}
if ( ! F_76 ( V_28 -> V_157 ) ) {
F_153 ( V_28 -> V_157 ) ;
V_28 -> V_157 = NULL ;
}
if ( ! F_76 ( V_28 -> V_153 ) ) {
F_78 ( V_28 -> V_153 ) ;
V_28 -> V_153 = NULL ;
}
}
static int F_154 ( struct V_197 * V_30 )
{
struct V_27 * V_28 = F_121 ( V_30 ) ;
struct V_243 V_244 ;
struct V_205 V_206 ;
T_2 V_245 = 0 ;
T_8 V_26 [ 16 ] ;
int V_29 ;
int V_13 ;
snprintf ( V_26 , sizeof( V_26 ) , L_41 , V_30 -> V_26 ) ;
V_28 -> V_93 = F_155 ( V_26 , V_28 -> V_128 ,
V_28 -> V_246 ) ;
if ( F_76 ( V_28 -> V_93 ) ) {
F_20 ( V_28 -> V_94 , L_42 ) ;
V_29 = F_132 ( V_28 -> V_93 ) ;
goto V_67;
}
snprintf ( V_26 , sizeof( V_26 ) , L_43 , V_30 -> V_26 ) ;
V_28 -> V_153 = F_155 ( V_26 , V_28 -> V_247 ,
V_28 -> V_248 ) ;
if ( F_76 ( V_28 -> V_153 ) ) {
F_20 ( V_28 -> V_94 , L_44 ) ;
V_29 = F_132 ( V_28 -> V_153 ) ;
goto V_67;
}
snprintf ( V_26 , sizeof( V_26 ) , L_45 , V_30 -> V_26 ) ;
V_28 -> V_157 = F_130 ( V_26 , V_28 -> V_177 , 0 ) ;
if ( F_131 ( V_28 -> V_157 ) ) {
V_29 = F_132 ( V_28 -> V_157 ) ;
goto V_67;
}
V_28 -> V_177 = F_156 ( V_28 -> V_157 ) ;
V_244 . V_249 = F_108 ;
V_244 . V_250 = V_28 ;
V_29 = F_157 ( V_28 -> V_157 ,
V_251 ,
( unsigned long ) & V_244 ) ;
if ( V_29 )
goto V_67;
F_99 ( V_28 -> V_157 ) ;
snprintf ( V_26 , sizeof( V_26 ) , L_46 , V_30 -> V_26 ) ;
V_28 -> V_98 = F_130 ( V_26 , V_28 -> V_142 , 0 ) ;
if ( F_131 ( V_28 -> V_98 ) ) {
V_29 = F_132 ( V_28 -> V_98 ) ;
goto V_67;
}
V_28 -> V_142 = F_156 ( V_28 -> V_98 ) ;
V_244 . V_249 = F_98 ;
V_244 . V_250 = V_28 ;
V_29 = F_157 ( V_28 -> V_98 ,
V_251 ,
( unsigned long ) & V_244 ) ;
if ( V_29 )
goto V_67;
F_99 ( V_28 -> V_98 ) ;
for ( V_13 = 0 ; V_13 < V_127 && V_28 -> V_146 [ V_13 ] ;
++ V_13 ) {
snprintf ( V_26 , sizeof( V_26 ) , L_47 , V_30 -> V_26 , V_13 ) ;
V_28 -> V_126 [ V_13 ] = F_130 ( V_26 , V_252 , 0 ) ;
if ( F_131 ( V_28 -> V_126 [ V_13 ] ) ) {
V_29 = F_132 ( V_28 -> V_126 [ V_13 ] ) ;
goto V_67;
}
}
memset ( & V_206 , 0 , sizeof( V_206 ) ) ;
V_206 . V_207 = V_253 ;
V_206 . V_209 . V_254 . V_255 = true ;
V_206 . V_209 . V_254 . V_256 = true ;
V_206 . V_209 . V_254 . V_257 = V_258 ;
V_206 . V_209 . V_254 . V_259 = V_260 ;
V_206 . V_209 . V_254 . V_261 = false ;
V_206 . V_209 . V_254 . V_262 = V_115 ;
V_206 . V_209 . V_254 . V_263 = V_28 -> V_142 ;
V_206 . V_209 . V_254 . V_264 = V_265 ;
for ( V_13 = 0 ; V_13 < V_127 ; ++ V_13 ) {
if ( V_28 -> V_126 [ V_13 ] )
V_245 = F_156 ( V_28 -> V_126 [ V_13 ] ) ;
V_206 . V_209 . V_254 . V_125 [ V_13 ] = V_245 ;
}
V_28 -> V_242 = F_128 ( V_28 -> V_32 -> V_35 ,
V_28 -> V_215 , & V_206 ) ;
if ( F_76 ( V_28 -> V_242 ) ) {
F_20 ( V_28 -> V_94 , L_48 ,
V_28 -> V_215 ) ;
goto V_67;
}
F_31 ( V_28 -> V_94 , L_49 , V_28 -> V_242 ) ;
return 0 ;
V_67:
F_152 ( V_28 ) ;
return V_29 ;
}
static int F_158 ( struct V_197 * V_30 )
{
struct V_27 * V_28 = F_121 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
int V_29 ;
F_159 ( V_30 ) ;
V_29 = F_154 ( V_30 ) ;
if ( V_29 ) {
F_20 ( V_28 -> V_94 , L_50 ) ;
goto V_67;
}
F_143 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( V_34 -> V_266 ) {
V_29 = V_34 -> V_266 ( V_55 -> V_51 , V_30 ) ;
if ( V_29 != 0 ) {
F_20 ( V_28 -> V_94 , L_51 ) ;
goto V_267;
}
}
}
F_160 ( & V_28 -> V_149 ) ;
F_160 ( & V_28 -> V_166 ) ;
F_97 ( V_28 -> V_157 ) ;
F_97 ( V_28 -> V_98 ) ;
F_92 ( V_28 ) ;
F_161 ( V_30 ) ;
F_31 ( V_28 -> V_94 , L_52 , V_30 -> V_26 ) ;
return 0 ;
V_267:
F_143 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( V_34 -> V_268 )
V_34 -> V_268 ( V_55 -> V_51 , V_30 ) ;
}
V_67:
F_152 ( V_28 ) ;
return V_29 ;
}
static int F_162 ( struct V_197 * V_30 )
{
struct V_27 * V_28 = F_121 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
int V_216 = 0 ;
F_163 ( V_30 ) ;
F_159 ( V_30 ) ;
F_140 ( V_28 ) ;
F_142 ( V_28 ) ;
F_99 ( V_28 -> V_98 ) ;
F_99 ( V_28 -> V_157 ) ;
F_164 ( & V_28 -> V_149 ) ;
F_164 ( & V_28 -> V_166 ) ;
F_143 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( V_34 -> V_268 ) {
V_216 = V_34 -> V_268 ( V_55 -> V_51 , V_30 ) ;
if ( V_216 != 0 )
F_20 ( V_28 -> V_94 , L_53 ) ;
}
}
F_58 ( V_28 ) ;
F_102 ( V_28 , V_28 -> V_247 ) ;
if ( F_77 ( V_28 -> V_153 ) != V_28 -> V_247 )
F_20 ( V_28 -> V_94 , L_54 ,
V_28 -> V_247 - F_77 ( V_28 -> V_153 ) ) ;
F_152 ( V_28 ) ;
F_31 ( V_28 -> V_94 , L_55 , V_30 -> V_26 ) ;
return 0 ;
}
static int F_165 ( struct V_197 * V_30 ,
struct V_269 * V_270 , int V_271 )
{
struct V_27 * V_28 = F_121 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
int V_29 = - 1 , V_216 = - V_272 ;
if ( ! F_104 ( V_30 ) )
return - V_62 ;
F_143 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( ! V_34 -> V_273 )
continue;
V_216 = V_34 -> V_273 ( V_55 -> V_51 , V_270 , V_271 ) ;
if ( ( V_216 < 0 ) && ( V_216 != - V_272 ) ) {
V_29 = V_216 ;
goto V_188;
}
if ( V_216 == 0 )
V_29 = V_216 ;
}
V_188:
return ( V_29 == 0 ) ? 0 : V_216 ;
}
static void F_166 ( struct V_197 * V_30 )
{
struct V_27 * V_28 = F_121 ( V_30 ) ;
unsigned int V_274 = F_77 ( V_28 -> V_153 ) ;
F_20 ( V_28 -> V_94 , L_56 , V_274 ) ;
F_102 ( V_28 , V_28 -> V_247 ) ;
F_124 ( V_30 ) ;
F_161 ( V_30 ) ;
}
static int F_167 ( struct V_197 * V_30 , T_9 V_275 , T_6 V_276 )
{
struct V_27 * V_28 = F_121 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
unsigned long V_80 ;
int V_216 = 0 ;
F_31 ( V_28 -> V_94 , L_57 , V_276 ) ;
F_41 ( & V_28 -> V_81 , V_80 ) ;
F_143 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( ( V_34 -> V_277 ) && ( V_276 != 0 ) ) {
V_216 = V_34 -> V_277 ( V_55 -> V_51 , V_276 ) ;
if ( V_216 != 0 ) {
F_20 ( V_28 -> V_94 , L_58 ,
V_276 ) ;
break;
}
}
}
F_43 ( & V_28 -> V_81 , V_80 ) ;
return V_216 ;
}
static int F_168 ( struct V_197 * V_30 , T_9 V_275 , T_6 V_276 )
{
struct V_27 * V_28 = F_121 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
unsigned long V_80 ;
int V_216 = 0 ;
F_31 ( V_28 -> V_94 , L_59 , V_276 ) ;
F_41 ( & V_28 -> V_81 , V_80 ) ;
F_143 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( V_34 -> V_278 ) {
V_216 = V_34 -> V_278 ( V_55 -> V_51 , V_276 ) ;
if ( V_216 != 0 ) {
F_20 ( V_28 -> V_94 , L_60 ,
V_276 ) ;
break;
}
}
}
F_43 ( & V_28 -> V_81 , V_80 ) ;
return V_216 ;
}
static T_6 F_169 ( struct V_197 * V_36 , struct V_110 * V_111 ,
void * V_279 ,
T_10 V_280 )
{
return 0 ;
}
static int F_170 ( struct V_197 * V_36 , T_2 V_281 , T_9 V_275 ,
struct V_282 * V_283 )
{
int V_13 ;
F_171 () ;
if ( V_283 -> type != V_284 )
return - V_62 ;
if ( ( V_36 -> V_285 <= 1 ) ||
( V_36 -> V_285 < V_283 -> V_283 ) )
return - V_62 ;
if ( V_283 -> V_283 ) {
F_172 ( V_36 , V_283 -> V_283 ) ;
for ( V_13 = 0 ; V_13 < V_283 -> V_283 ; V_13 ++ )
F_173 ( V_36 , V_13 , 1 , V_13 ) ;
} else {
F_174 ( V_36 ) ;
}
return 0 ;
}
static int F_175 ( struct V_32 * V_32 ,
struct V_24 * V_56 )
{
struct V_35 * V_36 = V_32 -> V_35 ;
struct V_24 * V_25 = V_36 -> V_39 ;
struct V_27 * V_28 ;
struct V_197 * V_30 ;
T_11 V_286 ;
struct V_287 V_288 ;
void T_4 * V_289 = NULL ;
T_2 V_19 = 0 ;
const void * V_290 ;
T_8 V_291 [ 6 ] ;
T_2 V_292 [ 2 ] ;
int V_29 = 0 ;
V_30 = F_176 ( sizeof( * V_28 ) , 1 , 1 ) ;
if ( ! V_30 ) {
F_20 ( V_36 , L_61 ) ;
return - V_47 ;
}
V_30 -> V_293 |= V_294 ;
V_30 -> V_293 |= V_295 ;
V_30 -> V_296 = V_30 -> V_293 ;
V_30 -> V_297 |= V_294 ;
V_30 -> V_298 = V_299 ;
V_30 -> V_300 = V_301 - ( V_302 + V_119 ) ;
V_28 = F_121 ( V_30 ) ;
F_177 ( & V_28 -> V_81 ) ;
F_178 ( & V_28 -> V_59 ) ;
F_178 ( & V_28 -> V_303 ) ;
F_178 ( & V_28 -> V_304 ) ;
F_178 ( & V_28 -> V_224 ) ;
V_28 -> V_32 = V_32 ;
V_28 -> V_36 = V_32 -> V_35 ;
V_28 -> V_30 = V_30 ;
V_28 -> V_94 = & V_30 -> V_36 ;
V_28 -> V_305 = F_179 ( V_306 , V_307 ) ;
V_28 -> V_203 = V_308 ;
V_28 -> V_162 = V_28 -> V_203 ;
V_28 -> V_56 = V_56 ;
V_29 = F_180 ( V_56 , L_62 , & V_19 ) ;
if ( V_19 ) {
if ( F_181 ( V_25 , V_309 , & V_288 ) ) {
F_20 ( V_36 , L_63 ) ;
V_29 = - V_61 ;
goto V_310;
}
V_286 = F_182 ( & V_288 ) ;
if ( ! F_183 ( V_36 , V_288 . V_311 , V_286 ,
F_129 ( V_36 ) ) ) {
F_20 ( V_36 , L_64 ) ;
V_29 = - V_47 ;
goto V_310;
}
V_289 = F_184 ( V_36 , V_288 . V_311 , V_286 ) ;
if ( ! V_289 ) {
F_20 ( V_36 , L_65 ) ;
F_185 ( V_36 , V_288 . V_311 , V_286 ) ;
V_29 = - V_47 ;
goto V_310;
}
F_12 ( V_291 , V_289 , V_19 ) ;
if ( F_186 ( V_291 ) )
F_137 ( V_30 -> V_312 , V_291 ) ;
else
F_187 ( V_30 -> V_312 ) ;
F_188 ( V_36 , V_289 ) ;
F_185 ( V_36 , V_288 . V_311 , V_286 ) ;
} else {
V_290 = F_189 ( V_56 ) ;
if ( V_290 )
F_137 ( V_30 -> V_312 , V_290 ) ;
else
F_187 ( V_30 -> V_312 ) ;
}
V_29 = F_15 ( V_56 , L_66 ,
& V_28 -> V_215 ) ;
if ( V_29 < 0 ) {
F_20 ( V_36 , L_67 ) ;
V_29 = - V_61 ;
goto V_310;
}
V_29 = F_180 ( V_56 , L_68 ,
& V_28 -> V_142 ) ;
if ( V_29 < 0 ) {
F_23 ( V_36 , L_69 ) ;
V_28 -> V_142 = V_313 ;
}
V_29 = F_190 ( V_56 , L_70 ,
V_28 -> V_146 ,
V_127 ) ;
if ( V_29 < 0 ) {
F_20 ( V_36 , L_71 ) ;
V_28 -> V_146 [ 0 ] = 128 ;
}
V_29 = F_190 ( V_56 , L_72 , V_292 , 2 ) ;
if ( V_29 < 0 ) {
F_20 ( V_36 , L_73 ) ;
V_29 = - V_61 ;
goto V_310;
}
V_28 -> V_128 = V_292 [ 0 ] ;
V_28 -> V_246 = V_292 [ 1 ] ;
V_29 = F_190 ( V_56 , L_74 , V_292 , 2 ) ;
if ( V_29 < 0 ) {
F_20 ( V_36 , L_75 ) ;
V_29 = - V_61 ;
goto V_310;
}
V_28 -> V_247 = V_292 [ 0 ] ;
V_28 -> V_248 = V_292 [ 1 ] ;
if ( V_28 -> V_247 < V_308 ) {
F_20 ( V_36 , L_76 ,
V_308 ) ;
V_29 = - V_61 ;
goto V_310;
}
V_29 = F_180 ( V_56 , L_77 ,
& V_28 -> V_177 ) ;
if ( V_29 < 0 ) {
F_23 ( V_36 , L_78 ) ;
V_28 -> V_177 = V_313 ;
}
F_191 ( V_30 , & V_28 -> V_149 , F_94 , V_314 ) ;
F_192 ( V_30 , & V_28 -> V_166 , F_107 , V_314 ) ;
V_30 -> V_315 = 0 ;
V_30 -> V_316 = V_317 ;
V_30 -> V_318 = & V_319 ;
F_193 ( V_30 , V_36 ) ;
F_25 ( & V_28 -> V_320 , & V_32 -> V_321 ) ;
return 0 ;
V_310:
F_194 ( V_30 ) ;
return V_29 ;
}
static void F_195 ( struct V_32 * V_32 ,
struct V_197 * V_30 )
{
struct V_54 * V_55 , * V_43 ;
struct V_27 * V_28 = F_121 ( V_30 ) ;
struct V_33 * V_34 ;
F_31 ( V_32 -> V_35 , L_79 ,
V_30 -> V_26 ) ;
F_38 (intf_modpriv, tmp, &netcp->module_head,
intf_list) {
V_34 = V_55 -> V_33 ;
F_31 ( V_32 -> V_35 , L_80 ,
V_34 -> V_26 ) ;
if ( V_34 -> V_71 )
V_34 -> V_71 ( V_55 -> V_51 ) ;
F_26 ( & V_55 -> V_58 ) ;
}
F_33 ( ! F_196 ( & V_28 -> V_59 ) , L_81 ,
V_30 -> V_26 ) ;
F_26 ( & V_28 -> V_320 ) ;
F_22 ( V_28 -> V_56 ) ;
F_197 ( V_30 ) ;
F_198 ( & V_28 -> V_149 ) ;
F_194 ( V_30 ) ;
}
static int F_199 ( struct V_322 * V_323 )
{
struct V_24 * V_25 = V_323 -> V_36 . V_39 ;
struct V_27 * V_27 , * V_69 ;
struct V_24 * V_40 , * V_324 ;
struct V_32 * V_32 ;
struct V_35 * V_36 = & V_323 -> V_36 ;
int V_29 ;
if ( ! V_25 ) {
F_20 ( V_36 , L_82 ) ;
return - V_61 ;
}
V_32 = F_24 ( V_36 , sizeof( * V_32 ) , V_46 ) ;
if ( ! V_32 )
return - V_47 ;
F_200 ( & V_323 -> V_36 ) ;
V_29 = F_201 ( & V_323 -> V_36 ) ;
if ( V_29 < 0 ) {
F_20 ( V_36 , L_83 ) ;
F_202 ( & V_323 -> V_36 ) ;
return V_29 ;
}
F_178 ( & V_32 -> V_321 ) ;
F_178 ( & V_32 -> V_49 ) ;
V_32 -> V_35 = V_36 ;
F_203 ( V_323 , V_32 ) ;
V_324 = F_19 ( V_25 , L_84 ) ;
if ( ! V_324 ) {
F_20 ( V_36 , L_85 ) ;
V_29 = - V_61 ;
goto V_325;
}
F_21 (interfaces, child) {
V_29 = F_175 ( V_32 , V_40 ) ;
if ( V_29 ) {
F_20 ( V_36 , L_86 ,
V_40 -> V_26 ) ;
goto V_326;
}
}
F_22 ( V_324 ) ;
F_25 ( & V_32 -> V_327 , & V_328 ) ;
return 0 ;
V_326:
F_38 (netcp_intf, netcp_tmp,
&netcp_device->interface_head,
interface_list) {
F_195 ( V_32 , V_27 -> V_30 ) ;
}
F_22 ( V_324 ) ;
V_325:
F_204 ( & V_323 -> V_36 ) ;
F_202 ( & V_323 -> V_36 ) ;
F_203 ( V_323 , NULL ) ;
return V_29 ;
}
static int F_205 ( struct V_322 * V_323 )
{
struct V_32 * V_32 = F_206 ( V_323 ) ;
struct V_27 * V_27 , * V_69 ;
struct V_41 * V_42 , * V_43 ;
struct V_33 * V_34 ;
F_38 (inst_modpriv, tmp, &netcp_device->modpriv_head,
inst_list) {
V_34 = V_42 -> V_33 ;
F_31 ( & V_323 -> V_36 , L_87 , V_34 -> V_26 ) ;
V_34 -> remove ( V_32 , V_42 -> V_51 ) ;
F_26 ( & V_42 -> V_48 ) ;
}
F_38 (netcp_intf, netcp_tmp,
&netcp_device->interface_head,
interface_list) {
F_195 ( V_32 , V_27 -> V_30 ) ;
}
F_33 ( ! F_196 ( & V_32 -> V_321 ) ,
L_88 , V_323 -> V_26 ) ;
F_204 ( & V_323 -> V_36 ) ;
F_202 ( & V_323 -> V_36 ) ;
F_203 ( V_323 , NULL ) ;
return 0 ;
}
