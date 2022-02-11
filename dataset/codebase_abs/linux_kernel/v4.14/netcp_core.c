static void F_1 ( T_1 * V_1 , T_2 * V_2 , T_1 * V_3 ,
struct V_4 * V_5 )
{
* V_2 = F_2 ( V_5 -> V_2 ) ;
* V_1 = F_2 ( V_5 -> V_1 ) ;
* V_3 = F_2 ( V_5 -> V_6 ) ;
}
static void F_3 ( T_2 * V_7 , T_2 * V_8 ,
struct V_4 * V_5 )
{
* V_7 = F_2 ( V_5 -> V_7 ) ;
* V_8 = F_2 ( V_5 -> V_9 ) ;
}
static T_2 F_4 ( int V_10 , struct V_4 * V_5 )
{
return V_5 -> V_11 [ V_10 ] ;
}
static void F_5 ( T_1 * V_1 , T_2 * V_2 ,
struct V_4 * V_5 )
{
* V_1 = F_2 ( V_5 -> V_12 ) ;
* V_2 = F_2 ( V_5 -> V_13 ) ;
}
static void F_6 ( T_1 * V_14 , int V_15 , T_3 * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ )
V_14 [ V_16 ] = F_2 ( V_5 [ V_16 ] ) ;
}
static void F_7 ( T_1 V_1 , T_2 V_2 , T_2 V_3 ,
struct V_4 * V_5 )
{
V_5 -> V_2 = F_8 ( V_2 ) ;
V_5 -> V_1 = F_8 ( V_1 ) ;
V_5 -> V_6 = F_8 ( V_3 ) ;
}
static void F_9 ( T_2 V_7 , T_2 V_8 ,
struct V_4 * V_5 )
{
V_5 -> V_7 = F_8 ( V_7 ) ;
V_5 -> V_9 = F_8 ( V_8 ) ;
}
static void F_10 ( int V_10 , T_2 V_17 , struct V_4 * V_5 )
{
V_5 -> V_11 [ V_10 ] = V_17 ;
}
static void F_11 ( T_1 V_1 , T_2 V_2 ,
struct V_4 * V_5 )
{
V_5 -> V_12 = F_8 ( V_1 ) ;
V_5 -> V_13 = F_8 ( V_2 ) ;
}
static void F_12 ( T_2 * V_14 , int V_15 , T_3 * V_5 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ )
V_5 [ V_16 ] = F_8 ( V_14 [ V_16 ] ) ;
}
static int F_13 ( char * V_18 , void T_4 * V_19 , T_2 V_20 )
{
unsigned int V_21 , V_22 ;
V_22 = F_14 ( V_19 + 4 ) ;
V_21 = F_14 ( V_19 ) ;
switch ( V_20 ) {
case V_23 :
V_21 = V_22 ;
V_22 = F_14 ( V_19 ) ;
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
static const char * F_15 ( struct V_24 * V_25 )
{
const char * V_26 ;
if ( F_16 ( V_25 , L_1 , & V_26 ) < 0 )
V_26 = V_25 -> V_26 ;
if ( ! V_26 )
V_26 = L_2 ;
return V_26 ;
}
static int F_17 ( struct V_27 * V_28 )
{
int V_29 ;
V_29 = F_18 ( V_28 -> V_30 ) ;
if ( ! V_29 )
V_28 -> V_31 = true ;
return V_29 ;
}
static int F_19 ( struct V_32 * V_32 ,
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
V_37 = F_20 ( V_25 , L_3 ) ;
if ( ! V_37 ) {
F_21 ( V_36 , L_4 ) ;
return V_45 ;
}
F_22 (devices, child) {
const char * V_26 = F_15 ( V_40 ) ;
if ( ! strcasecmp ( V_34 -> V_26 , V_26 ) )
break;
}
F_23 ( V_37 ) ;
if ( ! V_40 ) {
F_24 ( V_36 , L_5 , V_34 -> V_26 ) ;
return V_45 ;
}
V_42 = F_25 ( V_36 , sizeof( * V_42 ) , V_46 ) ;
if ( ! V_42 ) {
F_23 ( V_40 ) ;
return - V_47 ;
}
V_42 -> V_32 = V_32 ;
V_42 -> V_33 = V_34 ;
F_26 ( & V_42 -> V_48 , & V_32 -> V_49 ) ;
V_29 = V_34 -> V_50 ( V_32 , V_36 , V_40 ,
& V_42 -> V_51 ) ;
F_23 ( V_40 ) ;
if ( V_29 ) {
F_21 ( V_36 , L_6 ,
V_34 -> V_26 , V_29 ) ;
F_27 ( & V_42 -> V_48 ) ;
F_28 ( V_36 , V_42 ) ;
return V_52 ;
}
F_29 (tmp) {
if ( V_43 -> V_53 )
V_44 = true ;
}
if ( ! V_44 )
return 0 ;
F_30 (netcp_intf, &netcp_device->interface_head,
interface_list) {
struct V_54 * V_55 ;
V_55 = F_25 ( V_36 , sizeof( * V_55 ) ,
V_46 ) ;
if ( ! V_55 )
return - V_47 ;
V_38 = F_31 ( V_27 -> V_56 ,
V_34 -> V_26 , 0 ) ;
if ( ! V_38 ) {
F_28 ( V_36 , V_55 ) ;
continue;
}
V_55 -> V_57 = V_27 ;
V_55 -> V_33 = V_34 ;
F_26 ( & V_55 -> V_58 ,
& V_27 -> V_59 ) ;
V_29 = V_34 -> V_60 ( V_42 -> V_51 ,
V_27 -> V_30 , V_38 ,
& V_55 -> V_51 ) ;
F_23 ( V_38 ) ;
if ( V_29 ) {
F_32 ( V_36 , L_7 ,
V_34 -> V_26 , V_29 ) ;
F_27 ( & V_55 -> V_58 ) ;
F_28 ( V_36 , V_55 ) ;
continue;
}
}
F_30 (netcp_intf,
&netcp_device->interface_head,
interface_list) {
if ( ! V_27 -> V_31 ) {
V_29 = F_17 ( V_27 ) ;
if ( V_29 )
return - V_61 ;
}
}
return 0 ;
}
int F_33 ( struct V_33 * V_34 )
{
struct V_32 * V_32 ;
struct V_33 * V_43 ;
int V_29 ;
if ( ! V_34 -> V_26 ) {
F_34 ( 1 , L_8 ) ;
return - V_62 ;
}
if ( ! V_34 -> V_50 ) {
F_34 ( 1 , L_9 ) ;
return - V_62 ;
}
F_35 ( & V_63 ) ;
F_29 (tmp) {
if ( ! strcasecmp ( V_43 -> V_26 , V_34 -> V_26 ) ) {
F_36 ( & V_63 ) ;
return - V_64 ;
}
}
F_26 ( & V_34 -> V_65 , & V_66 ) ;
F_30 (netcp_device, &netcp_devices, device_list) {
V_29 = F_19 ( V_32 , V_34 ) ;
if ( V_29 < 0 )
goto V_67;
}
F_36 ( & V_63 ) ;
return 0 ;
V_67:
F_36 ( & V_63 ) ;
F_37 ( V_34 ) ;
return V_29 ;
}
static void F_38 ( struct V_32 * V_32 ,
struct V_33 * V_34 )
{
struct V_41 * V_42 , * V_68 ;
struct V_27 * V_27 , * V_69 ;
struct V_35 * V_36 = V_32 -> V_35 ;
F_39 (netcp_intf, netcp_tmp,
&netcp_device->interface_head,
interface_list) {
struct V_54 * V_55 , * V_70 ;
F_39 (intf_modpriv, intf_tmp,
&netcp_intf->module_head,
intf_list) {
if ( V_55 -> V_33 == V_34 ) {
V_34 -> V_71 ( V_55 -> V_51 ) ;
F_27 ( & V_55 -> V_58 ) ;
F_28 ( V_36 , V_55 ) ;
break;
}
}
}
F_39 (inst_modpriv, inst_tmp,
&netcp_device->modpriv_head, inst_list) {
if ( V_42 -> V_33 == V_34 ) {
V_34 -> remove ( V_32 ,
V_42 -> V_51 ) ;
F_27 ( & V_42 -> V_48 ) ;
F_28 ( V_36 , V_42 ) ;
break;
}
}
}
void F_37 ( struct V_33 * V_34 )
{
struct V_32 * V_32 ;
struct V_33 * V_72 ;
F_35 ( & V_63 ) ;
F_30 (netcp_device, &netcp_devices, device_list) {
F_38 ( V_32 , V_34 ) ;
}
F_29 (module_tmp) {
if ( V_34 == V_72 ) {
F_27 ( & V_34 -> V_65 ) ;
break;
}
}
F_36 ( & V_63 ) ;
}
void * F_40 ( struct V_33 * V_34 ,
struct V_27 * V_73 )
{
struct V_54 * V_55 ;
F_30 (intf_modpriv, &intf->module_head, intf_list)
if ( V_55 -> V_33 == V_34 )
return V_55 -> V_51 ;
return NULL ;
}
int F_41 ( struct V_27 * V_57 , int V_74 ,
T_5 * V_75 , void * V_76 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 ;
unsigned long V_80 ;
V_78 = F_25 ( V_57 -> V_36 , sizeof( * V_78 ) , V_46 ) ;
if ( ! V_78 )
return - V_47 ;
V_78 -> V_75 = V_75 ;
V_78 -> V_76 = V_76 ;
V_78 -> V_74 = V_74 ;
F_42 ( & V_57 -> V_81 , V_80 ) ;
F_30 (next, &netcp_priv->txhook_list_head, list) {
if ( V_79 -> V_74 > V_74 )
break;
}
F_43 ( & V_78 -> V_82 , V_79 -> V_82 . V_83 , & V_79 -> V_82 ) ;
F_44 ( & V_57 -> V_81 , V_80 ) ;
return 0 ;
}
int F_45 ( struct V_27 * V_57 , int V_74 ,
T_5 * V_75 , void * V_76 )
{
struct V_77 * V_79 , * V_84 ;
unsigned long V_80 ;
F_42 ( & V_57 -> V_81 , V_80 ) ;
F_39 (next, n, &netcp_priv->txhook_list_head, list) {
if ( ( V_79 -> V_74 == V_74 ) &&
( V_79 -> V_75 == V_75 ) &&
( V_79 -> V_76 == V_76 ) ) {
F_27 ( & V_79 -> V_82 ) ;
F_44 ( & V_57 -> V_81 , V_80 ) ;
F_28 ( V_57 -> V_36 , V_79 ) ;
return 0 ;
}
}
F_44 ( & V_57 -> V_81 , V_80 ) ;
return - V_85 ;
}
int F_46 ( struct V_27 * V_57 , int V_74 ,
T_5 * V_75 , void * V_76 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 ;
unsigned long V_80 ;
V_78 = F_25 ( V_57 -> V_36 , sizeof( * V_78 ) , V_46 ) ;
if ( ! V_78 )
return - V_47 ;
V_78 -> V_75 = V_75 ;
V_78 -> V_76 = V_76 ;
V_78 -> V_74 = V_74 ;
F_42 ( & V_57 -> V_81 , V_80 ) ;
F_30 (next, &netcp_priv->rxhook_list_head, list) {
if ( V_79 -> V_74 > V_74 )
break;
}
F_43 ( & V_78 -> V_82 , V_79 -> V_82 . V_83 , & V_79 -> V_82 ) ;
F_44 ( & V_57 -> V_81 , V_80 ) ;
return 0 ;
}
int F_47 ( struct V_27 * V_57 , int V_74 ,
T_5 * V_75 , void * V_76 )
{
struct V_77 * V_79 , * V_84 ;
unsigned long V_80 ;
F_42 ( & V_57 -> V_81 , V_80 ) ;
F_39 (next, n, &netcp_priv->rxhook_list_head, list) {
if ( ( V_79 -> V_74 == V_74 ) &&
( V_79 -> V_75 == V_75 ) &&
( V_79 -> V_76 == V_76 ) ) {
F_27 ( & V_79 -> V_82 ) ;
F_44 ( & V_57 -> V_81 , V_80 ) ;
F_28 ( V_57 -> V_36 , V_79 ) ;
return 0 ;
}
}
F_44 ( & V_57 -> V_81 , V_80 ) ;
return - V_85 ;
}
static void F_48 ( bool V_86 , void * V_87 )
{
if ( V_86 )
F_49 ( V_87 ) ;
else
F_50 ( V_87 ) ;
}
static void F_51 ( struct V_27 * V_28 ,
struct V_4 * V_5 )
{
struct V_4 * V_3 ;
T_1 V_88 , V_89 ;
unsigned int V_90 , V_91 = sizeof( * V_3 ) ;
void * V_92 ;
T_2 V_43 ;
F_6 ( & V_88 , 1 , & V_5 -> V_6 ) ;
while ( V_88 ) {
V_3 = F_52 ( V_28 -> V_93 , V_88 , V_91 ) ;
if ( F_53 ( ! V_3 ) ) {
F_21 ( V_28 -> V_94 , L_10 ) ;
break;
}
F_1 ( & V_89 , & V_43 , & V_88 , V_3 ) ;
V_92 = ( void * ) F_54 ( V_3 ) ;
V_90 = ( int ) F_55 ( V_5 ) ;
F_56 ( V_28 -> V_36 , V_89 , V_95 , V_96 ) ;
F_57 ( V_92 ) ;
F_58 ( V_28 -> V_93 , V_5 ) ;
}
V_92 = ( void * ) F_54 ( V_5 ) ;
V_90 = ( int ) F_55 ( V_5 ) ;
if ( V_92 )
F_48 ( V_90 <= V_95 , V_92 ) ;
F_58 ( V_28 -> V_93 , V_5 ) ;
}
static void F_59 ( struct V_27 * V_28 )
{
struct V_97 * V_98 = & V_28 -> V_99 ;
struct V_4 * V_5 ;
unsigned int V_91 ;
T_1 V_100 ;
for (; ; ) {
V_100 = F_60 ( V_28 -> V_101 , & V_91 ) ;
if ( ! V_100 )
break;
V_5 = F_52 ( V_28 -> V_93 , V_100 , V_91 ) ;
if ( F_53 ( ! V_5 ) ) {
F_21 ( V_28 -> V_94 , L_11 ,
V_102 ) ;
V_98 -> V_103 ++ ;
continue;
}
F_51 ( V_28 , V_5 ) ;
V_98 -> V_104 ++ ;
}
}
static int F_61 ( struct V_27 * V_28 )
{
struct V_97 * V_98 = & V_28 -> V_99 ;
unsigned int V_91 , V_90 , V_105 ;
struct V_4 * V_5 , * V_3 ;
unsigned int V_106 = 0 , V_107 ;
struct V_77 * V_108 ;
T_1 V_88 , V_109 ;
struct V_110 V_111 ;
struct V_112 * V_113 ;
void * V_114 ;
T_2 V_43 ;
V_88 = F_60 ( V_28 -> V_101 , & V_91 ) ;
if ( ! V_88 )
return - 1 ;
V_5 = F_52 ( V_28 -> V_93 , V_88 , V_91 ) ;
if ( F_53 ( ! V_5 ) ) {
F_21 ( V_28 -> V_94 , L_10 ) ;
return 0 ;
}
F_1 ( & V_109 , & V_90 , & V_88 , V_5 ) ;
V_114 = ( void * ) F_54 ( V_5 ) ;
V_105 = ( int ) F_55 ( V_5 ) ;
if ( F_53 ( ! V_114 ) ) {
F_21 ( V_28 -> V_94 , L_12 ) ;
goto V_115;
}
V_106 &= V_116 ;
V_107 = V_90 ;
F_62 ( V_28 -> V_36 , V_109 , V_90 , V_96 ) ;
V_113 = F_63 ( V_114 , V_105 ) ;
if ( F_53 ( ! V_113 ) ) {
F_21 ( V_28 -> V_94 , L_13 ) ;
goto V_115;
}
F_64 ( V_113 , V_117 ) ;
F_65 ( V_113 , V_90 ) ;
while ( V_88 ) {
struct V_118 * V_118 ;
V_3 = F_52 ( V_28 -> V_93 , V_88 , V_91 ) ;
if ( F_53 ( ! V_3 ) ) {
F_21 ( V_28 -> V_94 , L_10 ) ;
goto V_115;
}
F_1 ( & V_109 , & V_90 , & V_88 , V_3 ) ;
V_118 = (struct V_118 * ) F_54 ( V_5 ) ;
if ( F_66 ( V_109 && V_90 && V_118 ) ) {
F_56 ( V_28 -> V_36 , V_109 , V_95 ,
V_96 ) ;
} else {
F_21 ( V_28 -> V_94 , L_14 ,
& V_109 , V_90 , V_118 ) ;
goto V_115;
}
F_67 ( V_113 , F_68 ( V_113 ) -> V_119 , V_118 ,
F_69 ( V_109 ) , V_90 , V_95 ) ;
V_107 += V_90 ;
F_58 ( V_28 -> V_93 , V_3 ) ;
}
if ( F_53 ( V_106 != V_107 ) )
F_32 ( V_28 -> V_94 , L_15 ,
V_106 , V_107 ) ;
if ( ! ( V_28 -> V_120 & V_121 ) )
F_70 ( V_113 , V_113 -> V_122 - V_123 ) ;
V_111 . V_113 = V_113 ;
V_113 -> V_36 = V_28 -> V_30 ;
V_111 . V_124 = false ;
F_3 ( & V_43 , & V_111 . V_125 , V_5 ) ;
V_111 . V_126 = V_5 -> V_126 ;
V_111 . V_127 = ( T_2 V_128 * ) V_5 -> V_127 ;
V_111 . V_125 = ( ( V_111 . V_125 >> V_129 ) &
V_130 ) ;
F_30 (rx_hook, &netcp->rxhook_list_head, list) {
int V_29 ;
V_29 = V_108 -> V_75 ( V_108 -> V_74 , V_108 -> V_76 ,
& V_111 ) ;
if ( F_53 ( V_29 ) ) {
F_21 ( V_28 -> V_94 , L_16 ,
V_108 -> V_74 , V_29 ) ;
V_98 -> V_104 ++ ;
F_58 ( V_28 -> V_93 , V_5 ) ;
F_71 ( V_113 ) ;
return 0 ;
}
}
F_58 ( V_28 -> V_93 , V_5 ) ;
F_72 ( & V_98 -> V_131 ) ;
V_98 -> V_132 ++ ;
V_98 -> V_133 += V_113 -> V_122 ;
F_73 ( & V_98 -> V_131 ) ;
V_113 -> V_134 = F_74 ( V_113 , V_28 -> V_30 ) ;
F_75 ( V_113 ) ;
return 0 ;
V_115:
F_51 ( V_28 , V_5 ) ;
V_98 -> V_103 ++ ;
return 0 ;
}
static int F_76 ( struct V_27 * V_28 ,
unsigned int V_135 )
{
int V_16 ;
for ( V_16 = 0 ; ( V_16 < V_135 ) && ! F_61 ( V_28 ) ; V_16 ++ )
;
return V_16 ;
}
static void F_77 ( struct V_27 * V_28 , int V_136 )
{
struct V_4 * V_5 ;
unsigned int V_90 , V_91 ;
T_1 V_100 ;
void * V_92 ;
while ( ( V_100 = F_60 ( V_28 -> V_137 [ V_136 ] , & V_91 ) ) ) {
V_5 = F_52 ( V_28 -> V_93 , V_100 , V_91 ) ;
if ( F_53 ( ! V_5 ) ) {
F_21 ( V_28 -> V_94 , L_10 ) ;
continue;
}
F_5 ( & V_100 , & V_90 , V_5 ) ;
V_92 = ( void * ) F_54 ( V_5 ) ;
if ( F_53 ( ! V_100 ) ) {
F_21 ( V_28 -> V_94 , L_17 ) ;
F_58 ( V_28 -> V_93 , V_5 ) ;
continue;
}
if ( F_53 ( ! V_92 ) ) {
F_21 ( V_28 -> V_94 , L_12 ) ;
F_58 ( V_28 -> V_93 , V_5 ) ;
continue;
}
if ( V_136 == 0 ) {
F_62 ( V_28 -> V_36 , V_100 , V_90 ,
V_96 ) ;
F_48 ( ( V_90 <= V_95 ) , V_92 ) ;
} else {
F_56 ( V_28 -> V_36 , V_100 , V_90 ,
V_96 ) ;
F_57 ( V_92 ) ;
}
F_58 ( V_28 -> V_93 , V_5 ) ;
}
}
static void F_78 ( struct V_27 * V_28 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_138 &&
! F_79 ( V_28 -> V_137 [ V_16 ] ) ; V_16 ++ )
F_77 ( V_28 , V_16 ) ;
if ( F_80 ( V_28 -> V_93 ) != V_28 -> V_139 )
F_21 ( V_28 -> V_94 , L_18 ,
V_28 -> V_139 - F_80 ( V_28 -> V_93 ) ) ;
F_81 ( V_28 -> V_93 ) ;
V_28 -> V_93 = NULL ;
}
static int F_82 ( struct V_27 * V_28 , int V_136 )
{
struct V_4 * V_140 ;
unsigned int V_90 , V_91 ;
T_2 V_7 , V_8 ;
struct V_118 * V_118 ;
T_1 V_100 ;
void * V_141 ;
T_2 V_11 [ 2 ] ;
V_140 = F_83 ( V_28 -> V_93 ) ;
if ( F_79 ( V_140 ) ) {
F_32 ( V_28 -> V_94 , L_19 ) ;
return - V_47 ;
}
if ( F_66 ( V_136 == 0 ) ) {
unsigned int V_142 ;
V_90 = V_143 + V_117 ;
V_142 = F_84 ( V_90 ) +
F_84 ( sizeof( struct V_144 ) ) ;
V_141 = F_85 ( V_142 ) ;
V_11 [ 1 ] = V_142 ;
if ( F_53 ( ! V_141 ) ) {
F_86 ( V_28 -> V_94 ,
L_20 ) ;
goto V_67;
}
V_100 = F_87 ( V_28 -> V_36 , V_141 , V_90 ,
V_145 ) ;
if ( F_53 ( F_88 ( V_28 -> V_36 , V_100 ) ) )
goto V_67;
V_11 [ 0 ] = ( T_2 ) V_141 ;
} else {
V_118 = F_89 ( V_146 | V_147 | V_148 ) ;
if ( F_53 ( ! V_118 ) ) {
F_86 ( V_28 -> V_94 , L_21 ) ;
goto V_67;
}
V_90 = V_95 ;
V_100 = F_90 ( V_28 -> V_36 , V_118 , 0 , V_90 , V_145 ) ;
V_11 [ 0 ] = ( T_2 ) V_118 ;
V_11 [ 1 ] = 0 ;
}
V_7 = V_149 ;
V_7 |= V_90 & V_116 ;
V_8 = V_150 ;
V_8 |= V_151 << V_152 ;
V_8 |= ( V_28 -> V_153 & V_154 ) <<
V_155 ;
F_11 ( V_100 , V_90 , V_140 ) ;
F_91 ( V_11 [ 0 ] , V_140 ) ;
F_92 ( V_11 [ 1 ] , V_140 ) ;
F_9 ( V_7 , V_8 , V_140 ) ;
F_93 ( V_28 -> V_93 , V_140 , sizeof( * V_140 ) , & V_100 ,
& V_91 ) ;
F_94 ( V_28 -> V_137 [ V_136 ] , V_100 , sizeof( * V_140 ) , 0 ) ;
return 0 ;
V_67:
F_58 ( V_28 -> V_93 , V_140 ) ;
return - V_47 ;
}
static void F_95 ( struct V_27 * V_28 )
{
T_2 V_156 [ V_138 ] = { 0 } ;
int V_16 , V_29 = 0 ;
for ( V_16 = 0 ; V_16 < V_138 && V_28 -> V_137 [ V_16 ] ; V_16 ++ ) {
V_156 [ V_16 ] = V_28 -> V_157 [ V_16 ] -
F_96 ( V_28 -> V_137 [ V_16 ] ) ;
while ( V_156 [ V_16 ] -- && ! V_29 )
V_29 = F_82 ( V_28 , V_16 ) ;
}
}
static int F_97 ( struct V_158 * V_159 , int V_135 )
{
struct V_27 * V_28 = F_98 ( V_159 , struct V_27 ,
V_160 ) ;
unsigned int V_161 ;
V_161 = F_76 ( V_28 , V_135 ) ;
F_95 ( V_28 ) ;
if ( V_161 < V_135 ) {
F_99 ( & V_28 -> V_160 , V_161 ) ;
F_100 ( V_28 -> V_101 ) ;
}
return V_161 ;
}
static void F_101 ( void * V_162 )
{
struct V_27 * V_28 = V_162 ;
F_102 ( V_28 -> V_101 ) ;
F_103 ( & V_28 -> V_160 ) ;
}
static void F_104 ( struct V_27 * V_28 ,
struct V_4 * V_5 ,
unsigned int V_163 )
{
struct V_4 * V_3 = V_5 ;
T_1 V_88 , V_89 ;
unsigned int V_90 ;
while ( V_3 ) {
F_1 ( & V_89 , & V_90 , & V_88 , V_3 ) ;
if ( V_89 && V_90 )
F_62 ( V_28 -> V_36 , V_89 , V_90 ,
V_145 ) ;
else
F_24 ( V_28 -> V_94 , L_22 ,
& V_89 , V_90 ) ;
F_58 ( V_28 -> V_164 , V_3 ) ;
V_3 = NULL ;
if ( V_88 ) {
V_3 = F_52 ( V_28 -> V_164 , V_88 ,
V_163 ) ;
if ( ! V_3 )
F_21 ( V_28 -> V_94 , L_23 ) ;
}
}
}
static int F_105 ( struct V_27 * V_28 ,
unsigned int V_135 )
{
struct V_97 * V_165 = & V_28 -> V_99 ;
struct V_4 * V_5 ;
struct V_166 * V_167 ;
struct V_112 * V_113 ;
unsigned int V_91 ;
T_1 V_100 ;
int V_168 = 0 ;
while ( V_135 -- ) {
V_100 = F_60 ( V_28 -> V_169 , & V_91 ) ;
if ( ! V_100 )
break;
V_5 = F_52 ( V_28 -> V_164 , V_100 , V_91 ) ;
if ( F_53 ( ! V_5 ) ) {
F_21 ( V_28 -> V_94 , L_23 ) ;
V_165 -> V_170 ++ ;
continue;
}
V_113 = (struct V_112 * ) F_54 ( V_5 ) ;
F_104 ( V_28 , V_5 , V_91 ) ;
if ( ! V_113 ) {
F_21 ( V_28 -> V_94 , L_24 ) ;
V_165 -> V_170 ++ ;
continue;
}
V_167 = (struct V_166 * ) V_113 -> V_171 ;
if ( V_167 -> V_172 )
V_167 -> V_172 ( V_167 -> V_173 , V_113 ) ;
if ( F_106 ( V_28 -> V_30 , V_113 ) &&
F_107 ( V_28 -> V_30 ) &&
( F_80 ( V_28 -> V_164 ) >
V_28 -> V_174 ) ) {
T_6 V_175 = F_108 ( V_113 ) ;
F_109 ( V_28 -> V_30 , V_175 ) ;
}
F_72 ( & V_165 -> V_176 ) ;
V_165 -> V_177 ++ ;
V_165 -> V_178 += V_113 -> V_122 ;
F_73 ( & V_165 -> V_176 ) ;
F_71 ( V_113 ) ;
V_168 ++ ;
}
return V_168 ;
}
static int F_110 ( struct V_158 * V_159 , int V_135 )
{
int V_161 ;
struct V_27 * V_28 = F_98 ( V_159 , struct V_27 ,
V_179 ) ;
V_161 = F_105 ( V_28 , V_135 ) ;
if ( V_161 < V_135 ) {
F_111 ( & V_28 -> V_179 ) ;
F_100 ( V_28 -> V_169 ) ;
}
return V_161 ;
}
static void F_112 ( void * V_162 )
{
struct V_27 * V_28 = V_162 ;
F_102 ( V_28 -> V_169 ) ;
F_103 ( & V_28 -> V_179 ) ;
}
static struct V_4 *
F_113 ( struct V_112 * V_113 , struct V_27 * V_28 )
{
struct V_4 * V_5 , * V_3 , * V_180 ;
unsigned int V_181 = F_114 ( V_113 ) ;
struct V_35 * V_36 = V_28 -> V_36 ;
T_1 V_182 ;
unsigned int V_91 ;
int V_16 ;
V_182 = F_87 ( V_36 , V_113 -> V_17 , V_181 , V_145 ) ;
if ( F_53 ( F_88 ( V_36 , V_182 ) ) ) {
F_21 ( V_28 -> V_94 , L_25 ) ;
return NULL ;
}
V_5 = F_83 ( V_28 -> V_164 ) ;
if ( F_79 ( V_5 ) ) {
F_21 ( V_28 -> V_94 , L_26 ) ;
F_62 ( V_36 , V_182 , V_181 , V_145 ) ;
return NULL ;
}
F_7 ( V_182 , V_181 , 0 , V_5 ) ;
if ( F_115 ( V_113 ) ) {
F_116 ( F_68 ( V_113 ) ) ;
} else {
V_5 -> V_6 = 0 ;
goto V_183;
}
V_180 = V_5 ;
for ( V_16 = 0 ; V_16 < F_68 ( V_113 ) -> V_119 ; V_16 ++ ) {
T_7 * V_184 = & F_68 ( V_113 ) -> V_185 [ V_16 ] ;
struct V_118 * V_118 = F_117 ( V_184 ) ;
T_2 V_186 = V_184 -> V_186 ;
T_2 V_90 = F_118 ( V_184 ) ;
T_1 V_187 ;
T_2 V_188 ;
V_182 = F_90 ( V_36 , V_118 , V_186 , V_90 ,
V_145 ) ;
if ( F_53 ( ! V_182 ) ) {
F_21 ( V_28 -> V_94 , L_27 ) ;
goto V_189;
}
V_3 = F_83 ( V_28 -> V_164 ) ;
if ( F_79 ( V_3 ) ) {
F_21 ( V_28 -> V_94 , L_28 ) ;
F_56 ( V_36 , V_182 , V_90 , V_145 ) ;
goto V_189;
}
V_187 = F_119 ( V_28 -> V_164 , V_3 ) ;
F_7 ( V_182 , V_90 , 0 , V_3 ) ;
V_188 = ( T_2 ) V_187 ;
F_12 ( & V_188 , 1 , & V_180 -> V_6 ) ;
V_181 += V_90 ;
if ( V_180 != V_5 )
F_93 ( V_28 -> V_164 , V_180 ,
sizeof( * V_180 ) , & V_187 , & V_91 ) ;
V_180 = V_3 ;
}
if ( V_180 != V_5 )
F_93 ( V_28 -> V_164 , V_180 , sizeof( * V_180 ) ,
& V_182 , & V_91 ) ;
if ( F_68 ( V_113 ) -> V_190 ) {
F_120 ( V_28 -> V_94 , L_29 ) ;
goto V_189;
}
V_183:
F_121 ( V_181 != V_113 -> V_122 ) ;
V_181 &= V_116 ;
F_12 ( & V_181 , 1 , & V_5 -> V_7 ) ;
return V_5 ;
V_189:
F_104 ( V_28 , V_5 , sizeof( * V_5 ) ) ;
return NULL ;
}
static int F_122 ( struct V_27 * V_28 ,
struct V_112 * V_113 ,
struct V_4 * V_5 )
{
struct V_191 * V_192 = NULL ;
struct V_77 * V_193 ;
struct V_110 V_111 ;
struct V_166 * V_167 ;
unsigned int V_91 ;
T_1 V_100 ;
T_2 V_43 = 0 ;
int V_29 = 0 ;
V_111 . V_28 = V_28 ;
V_111 . V_113 = V_113 ;
V_111 . V_192 = NULL ;
V_111 . V_194 = 0 ;
V_111 . V_173 = NULL ;
V_111 . V_172 = NULL ;
V_111 . V_126 = V_5 -> V_126 ;
V_111 . V_127 = ( T_2 V_128 * ) V_5 -> V_127 ;
memset ( V_111 . V_126 , 0 , V_195 * sizeof( T_3 ) ) ;
F_30 (tx_hook, &netcp->txhook_list_head, list) {
V_29 = V_193 -> V_75 ( V_193 -> V_74 , V_193 -> V_76 ,
& V_111 ) ;
if ( F_53 ( V_29 != 0 ) ) {
F_21 ( V_28 -> V_94 , L_30 ,
V_193 -> V_74 , V_29 ) ;
V_29 = ( V_29 < 0 ) ? V_29 : V_196 ;
goto V_197;
}
}
V_192 = V_111 . V_192 ;
if ( ! V_192 ) {
F_21 ( V_28 -> V_94 , L_31 ) ;
V_29 = - V_198 ;
goto V_197;
}
V_167 = (struct V_166 * ) V_113 -> V_171 ;
V_167 -> V_173 = V_111 . V_173 ;
V_167 -> V_172 = V_111 . V_172 ;
if ( V_111 . V_194 ) {
T_3 * V_127 = ( void V_128 * ) V_111 . V_127 ;
F_12 ( ( T_2 * ) V_127 +
( V_151 - V_111 . V_194 ) ,
V_111 . V_194 , V_127 ) ;
V_43 |= ( V_111 . V_194 & V_199 ) <<
V_152 ;
}
V_43 |= V_150 |
( ( V_28 -> V_200 & V_154 ) <<
V_155 ) ;
if ( ! ( V_192 -> V_80 & V_201 ) ) {
V_43 |= ( ( V_192 -> V_202 & V_203 ) <<
V_204 ) ;
}
F_12 ( & V_43 , 1 , & V_5 -> V_9 ) ;
F_91 ( ( T_2 ) V_113 , V_5 ) ;
if ( V_192 -> V_80 & V_201 ) {
V_43 = V_192 -> V_202 ;
F_12 ( & V_43 , 1 , & V_5 -> V_205 ) ;
}
V_29 = F_93 ( V_28 -> V_164 , V_5 , sizeof( * V_5 ) , & V_100 ,
& V_91 ) ;
if ( F_53 ( V_29 ) ) {
F_21 ( V_28 -> V_94 , L_32 , V_102 ) ;
V_29 = - V_47 ;
goto V_197;
}
F_123 ( V_113 ) ;
F_94 ( V_192 -> V_206 , V_100 , V_91 , 0 ) ;
V_197:
return V_29 ;
}
static int F_124 ( struct V_112 * V_113 , struct V_207 * V_30 )
{
struct V_27 * V_28 = F_125 ( V_30 ) ;
struct V_97 * V_165 = & V_28 -> V_99 ;
int V_175 = F_108 ( V_113 ) ;
struct V_4 * V_5 ;
int V_208 , V_29 = 0 ;
if ( F_53 ( V_113 -> V_122 <= 0 ) ) {
F_71 ( V_113 ) ;
return V_196 ;
}
if ( F_53 ( V_113 -> V_122 < V_209 ) ) {
V_29 = F_126 ( V_113 , V_209 ) ;
if ( V_29 < 0 ) {
F_24 ( V_28 -> V_94 , L_33 ,
V_29 ) ;
V_165 -> V_210 ++ ;
return V_29 ;
}
V_113 -> V_122 = V_209 ;
}
V_5 = F_113 ( V_113 , V_28 ) ;
if ( F_53 ( ! V_5 ) ) {
F_127 ( V_30 , V_175 ) ;
V_29 = - V_211 ;
goto V_212;
}
V_29 = F_122 ( V_28 , V_113 , V_5 ) ;
if ( V_29 )
goto V_212;
V_208 = F_80 ( V_28 -> V_164 ) ;
if ( V_208 < V_28 -> V_213 ) {
F_32 ( V_28 -> V_94 , L_34 , V_208 ) ;
F_127 ( V_30 , V_175 ) ;
}
return V_196 ;
V_212:
V_165 -> V_210 ++ ;
if ( V_5 )
F_104 ( V_28 , V_5 , sizeof( * V_5 ) ) ;
F_71 ( V_113 ) ;
return V_29 ;
}
int F_128 ( struct V_191 * V_192 )
{
if ( V_192 -> V_214 ) {
F_129 ( V_192 -> V_214 ) ;
V_192 -> V_214 = NULL ;
}
return 0 ;
}
int F_130 ( struct V_191 * V_192 )
{
struct V_35 * V_36 = V_192 -> V_32 -> V_35 ;
struct V_215 V_216 ;
int V_29 = 0 ;
T_8 V_26 [ 16 ] ;
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
V_216 . V_217 = V_218 ;
V_216 . V_219 . V_220 . V_221 = false ;
V_216 . V_219 . V_220 . V_222 = false ;
V_216 . V_219 . V_220 . V_223 = V_224 ;
V_192 -> V_214 = F_131 ( V_36 ,
V_192 -> V_225 , & V_216 ) ;
if ( F_132 ( V_192 -> V_214 ) ) {
F_21 ( V_36 , L_35 ,
V_192 -> V_225 ) ;
V_29 = F_133 ( V_192 -> V_214 ) ;
goto V_226;
}
snprintf ( V_26 , sizeof( V_26 ) , L_36 , F_134 ( V_36 ) ) ;
V_192 -> V_206 = F_135 ( V_26 , V_192 -> V_227 ,
V_228 ) ;
if ( F_132 ( V_192 -> V_206 ) ) {
F_21 ( V_36 , L_37 ,
V_26 , V_29 ) ;
V_29 = F_133 ( V_192 -> V_206 ) ;
goto V_226;
}
F_32 ( V_36 , L_38 , V_26 ) ;
return 0 ;
V_226:
if ( ! F_79 ( V_192 -> V_214 ) )
F_129 ( V_192 -> V_214 ) ;
V_192 -> V_214 = NULL ;
return V_29 ;
}
int F_136 ( struct V_191 * V_192 ,
struct V_32 * V_32 ,
const char * V_225 , unsigned int V_227 )
{
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
V_192 -> V_32 = V_32 ;
V_192 -> V_225 = V_225 ;
V_192 -> V_227 = V_227 ;
return 0 ;
}
static struct V_229 * F_137 ( struct V_27 * V_28 ,
const T_8 * V_230 ,
enum V_231 type )
{
struct V_229 * V_232 ;
F_30 (naddr, &netcp->addr_list, node) {
if ( V_232 -> type != type )
continue;
if ( V_230 && memcmp ( V_230 , V_232 -> V_230 , V_233 ) )
continue;
return V_232 ;
}
return NULL ;
}
static struct V_229 * F_138 ( struct V_27 * V_28 ,
const T_8 * V_230 ,
enum V_231 type )
{
struct V_229 * V_232 ;
V_232 = F_139 ( V_28 -> V_36 , sizeof( * V_232 ) , V_146 ) ;
if ( ! V_232 )
return NULL ;
V_232 -> type = type ;
V_232 -> V_80 = 0 ;
V_232 -> V_28 = V_28 ;
if ( V_230 )
F_140 ( V_232 -> V_230 , V_230 ) ;
else
F_141 ( V_232 -> V_230 ) ;
F_26 ( & V_232 -> V_25 , & V_28 -> V_234 ) ;
return V_232 ;
}
static void F_142 ( struct V_27 * V_28 , struct V_229 * V_232 )
{
F_27 ( & V_232 -> V_25 ) ;
F_28 ( V_28 -> V_36 , V_232 ) ;
}
static void F_143 ( struct V_27 * V_28 )
{
struct V_229 * V_232 ;
F_30 (naddr, &netcp->addr_list, node)
V_232 -> V_80 = 0 ;
}
static void F_144 ( struct V_27 * V_28 , const T_8 * V_230 ,
enum V_231 type )
{
struct V_229 * V_232 ;
V_232 = F_137 ( V_28 , V_230 , type ) ;
if ( V_232 ) {
V_232 -> V_80 |= V_235 ;
return;
}
V_232 = F_138 ( V_28 , V_230 , type ) ;
if ( ! F_121 ( ! V_232 ) )
V_232 -> V_80 |= V_236 ;
}
static void F_145 ( struct V_27 * V_28 )
{
struct V_229 * V_232 , * V_43 ;
struct V_54 * V_237 ;
struct V_33 * V_34 ;
int error ;
F_39 (naddr, tmp, &netcp->addr_list, node) {
if ( V_232 -> V_80 & ( V_235 | V_236 ) )
continue;
F_32 ( V_28 -> V_94 , L_39 ,
V_232 -> V_230 , V_232 -> type ) ;
F_146 (netcp, priv) {
V_34 = V_237 -> V_33 ;
if ( ! V_34 -> V_238 )
continue;
error = V_34 -> V_238 ( V_237 -> V_51 ,
V_232 ) ;
F_121 ( error ) ;
}
F_142 ( V_28 , V_232 ) ;
}
}
static void F_147 ( struct V_27 * V_28 )
{
struct V_229 * V_232 , * V_43 ;
struct V_54 * V_237 ;
struct V_33 * V_34 ;
int error ;
F_39 (naddr, tmp, &netcp->addr_list, node) {
if ( ! ( V_232 -> V_80 & V_236 ) )
continue;
F_32 ( V_28 -> V_94 , L_40 ,
V_232 -> V_230 , V_232 -> type ) ;
F_146 (netcp, priv) {
V_34 = V_237 -> V_33 ;
if ( ! V_34 -> V_239 )
continue;
error = V_34 -> V_239 ( V_237 -> V_51 , V_232 ) ;
F_121 ( error ) ;
}
}
}
static void F_148 ( struct V_207 * V_30 )
{
struct V_27 * V_28 = F_125 ( V_30 ) ;
struct V_240 * V_241 ;
bool V_242 ;
V_242 = ( V_30 -> V_80 & V_243 ||
V_30 -> V_80 & V_244 ||
F_149 ( V_30 ) > V_245 ) ;
F_150 ( & V_28 -> V_81 ) ;
F_143 ( V_28 ) ;
F_144 ( V_28 , V_30 -> V_246 , V_247 ) ;
F_151 (ndev, ndev_addr)
F_144 ( V_28 , V_241 -> V_230 , V_248 ) ;
F_152 (ndev_addr, ndev)
F_144 ( V_28 , V_241 -> V_230 , V_249 ) ;
F_153 (ndev_addr, ndev)
F_144 ( V_28 , V_241 -> V_230 , V_250 ) ;
if ( V_242 )
F_144 ( V_28 , NULL , V_251 ) ;
F_145 ( V_28 ) ;
F_147 ( V_28 ) ;
F_154 ( & V_28 -> V_81 ) ;
}
static void F_155 ( struct V_27 * V_28 )
{
int V_16 ;
if ( V_28 -> V_252 ) {
F_129 ( V_28 -> V_252 ) ;
V_28 -> V_252 = NULL ;
}
if ( ! F_79 ( V_28 -> V_93 ) )
F_78 ( V_28 ) ;
if ( ! F_79 ( V_28 -> V_101 ) ) {
F_156 ( V_28 -> V_101 ) ;
V_28 -> V_101 = NULL ;
}
for ( V_16 = 0 ; V_16 < V_138 &&
! F_79 ( V_28 -> V_137 [ V_16 ] ) ; ++ V_16 ) {
F_156 ( V_28 -> V_137 [ V_16 ] ) ;
V_28 -> V_137 [ V_16 ] = NULL ;
}
if ( ! F_79 ( V_28 -> V_169 ) ) {
F_156 ( V_28 -> V_169 ) ;
V_28 -> V_169 = NULL ;
}
if ( ! F_79 ( V_28 -> V_164 ) ) {
F_81 ( V_28 -> V_164 ) ;
V_28 -> V_164 = NULL ;
}
}
static int F_157 ( struct V_207 * V_30 )
{
struct V_27 * V_28 = F_125 ( V_30 ) ;
struct V_253 V_254 ;
struct V_215 V_216 ;
T_2 V_255 = 0 ;
T_8 V_26 [ 16 ] ;
int V_29 ;
int V_16 ;
snprintf ( V_26 , sizeof( V_26 ) , L_41 , V_30 -> V_26 ) ;
V_28 -> V_93 = F_158 ( V_26 , V_28 -> V_139 ,
V_28 -> V_256 ) ;
if ( F_79 ( V_28 -> V_93 ) ) {
F_21 ( V_28 -> V_94 , L_42 ) ;
V_29 = F_133 ( V_28 -> V_93 ) ;
goto V_67;
}
snprintf ( V_26 , sizeof( V_26 ) , L_43 , V_30 -> V_26 ) ;
V_28 -> V_164 = F_158 ( V_26 , V_28 -> V_257 ,
V_28 -> V_258 ) ;
if ( F_79 ( V_28 -> V_164 ) ) {
F_21 ( V_28 -> V_94 , L_44 ) ;
V_29 = F_133 ( V_28 -> V_164 ) ;
goto V_67;
}
snprintf ( V_26 , sizeof( V_26 ) , L_45 , V_30 -> V_26 ) ;
V_28 -> V_169 = F_135 ( V_26 , V_28 -> V_200 , 0 ) ;
if ( F_132 ( V_28 -> V_169 ) ) {
V_29 = F_133 ( V_28 -> V_169 ) ;
goto V_67;
}
V_28 -> V_200 = F_159 ( V_28 -> V_169 ) ;
V_254 . V_259 = F_112 ;
V_254 . V_260 = V_28 ;
V_29 = F_160 ( V_28 -> V_169 ,
V_261 ,
( unsigned long ) & V_254 ) ;
if ( V_29 )
goto V_67;
F_102 ( V_28 -> V_169 ) ;
snprintf ( V_26 , sizeof( V_26 ) , L_46 , V_30 -> V_26 ) ;
V_28 -> V_101 = F_135 ( V_26 , V_28 -> V_153 , 0 ) ;
if ( F_132 ( V_28 -> V_101 ) ) {
V_29 = F_133 ( V_28 -> V_101 ) ;
goto V_67;
}
V_28 -> V_153 = F_159 ( V_28 -> V_101 ) ;
V_254 . V_259 = F_101 ;
V_254 . V_260 = V_28 ;
V_29 = F_160 ( V_28 -> V_101 ,
V_261 ,
( unsigned long ) & V_254 ) ;
if ( V_29 )
goto V_67;
F_102 ( V_28 -> V_101 ) ;
for ( V_16 = 0 ; V_16 < V_138 && V_28 -> V_157 [ V_16 ] ;
++ V_16 ) {
snprintf ( V_26 , sizeof( V_26 ) , L_47 , V_30 -> V_26 , V_16 ) ;
V_28 -> V_137 [ V_16 ] = F_135 ( V_26 , V_262 , 0 ) ;
if ( F_132 ( V_28 -> V_137 [ V_16 ] ) ) {
V_29 = F_133 ( V_28 -> V_137 [ V_16 ] ) ;
goto V_67;
}
}
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
V_216 . V_217 = V_263 ;
V_216 . V_219 . V_264 . V_265 = true ;
V_216 . V_219 . V_264 . V_266 = true ;
V_216 . V_219 . V_264 . V_267 = V_268 ;
V_216 . V_219 . V_264 . V_269 = V_270 ;
V_216 . V_219 . V_264 . V_271 = false ;
V_216 . V_219 . V_264 . V_272 = V_117 ;
V_216 . V_219 . V_264 . V_273 = V_28 -> V_153 ;
V_216 . V_219 . V_264 . V_274 = V_275 ;
for ( V_16 = 0 ; V_16 < V_138 ; ++ V_16 ) {
if ( V_28 -> V_137 [ V_16 ] )
V_255 = F_159 ( V_28 -> V_137 [ V_16 ] ) ;
V_216 . V_219 . V_264 . V_136 [ V_16 ] = V_255 ;
}
V_28 -> V_252 = F_131 ( V_28 -> V_32 -> V_35 ,
V_28 -> V_225 , & V_216 ) ;
if ( F_132 ( V_28 -> V_252 ) ) {
F_21 ( V_28 -> V_94 , L_48 ,
V_28 -> V_225 ) ;
V_29 = F_133 ( V_28 -> V_252 ) ;
goto V_67;
}
F_32 ( V_28 -> V_94 , L_49 , V_28 -> V_252 ) ;
return 0 ;
V_67:
F_155 ( V_28 ) ;
return V_29 ;
}
static int F_161 ( struct V_207 * V_30 )
{
struct V_27 * V_28 = F_125 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
int V_29 ;
F_162 ( V_30 ) ;
V_29 = F_157 ( V_30 ) ;
if ( V_29 ) {
F_21 ( V_28 -> V_94 , L_50 ) ;
goto V_67;
}
F_146 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( V_34 -> V_276 ) {
V_29 = V_34 -> V_276 ( V_55 -> V_51 , V_30 ) ;
if ( V_29 != 0 ) {
F_21 ( V_28 -> V_94 , L_51 ) ;
goto V_277;
}
}
}
F_163 ( & V_28 -> V_160 ) ;
F_163 ( & V_28 -> V_179 ) ;
F_100 ( V_28 -> V_169 ) ;
F_100 ( V_28 -> V_101 ) ;
F_95 ( V_28 ) ;
F_164 ( V_30 ) ;
F_32 ( V_28 -> V_94 , L_52 , V_30 -> V_26 ) ;
return 0 ;
V_277:
F_146 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( V_34 -> V_278 )
V_34 -> V_278 ( V_55 -> V_51 , V_30 ) ;
}
V_67:
F_155 ( V_28 ) ;
return V_29 ;
}
static int F_165 ( struct V_207 * V_30 )
{
struct V_27 * V_28 = F_125 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
int V_226 = 0 ;
F_166 ( V_30 ) ;
F_162 ( V_30 ) ;
F_143 ( V_28 ) ;
F_145 ( V_28 ) ;
F_102 ( V_28 -> V_101 ) ;
F_102 ( V_28 -> V_169 ) ;
F_167 ( & V_28 -> V_160 ) ;
F_167 ( & V_28 -> V_179 ) ;
F_146 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( V_34 -> V_278 ) {
V_226 = V_34 -> V_278 ( V_55 -> V_51 , V_30 ) ;
if ( V_226 != 0 )
F_21 ( V_28 -> V_94 , L_53 ) ;
}
}
F_59 ( V_28 ) ;
F_105 ( V_28 , V_28 -> V_257 ) ;
if ( F_80 ( V_28 -> V_164 ) != V_28 -> V_257 )
F_21 ( V_28 -> V_94 , L_54 ,
V_28 -> V_257 - F_80 ( V_28 -> V_164 ) ) ;
F_155 ( V_28 ) ;
F_32 ( V_28 -> V_94 , L_55 , V_30 -> V_26 ) ;
return 0 ;
}
static int F_168 ( struct V_207 * V_30 ,
struct V_279 * V_280 , int V_281 )
{
struct V_27 * V_28 = F_125 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
int V_29 = - 1 , V_226 = - V_282 ;
if ( ! F_107 ( V_30 ) )
return - V_62 ;
F_146 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( ! V_34 -> V_283 )
continue;
V_226 = V_34 -> V_283 ( V_55 -> V_51 , V_280 , V_281 ) ;
if ( ( V_226 < 0 ) && ( V_226 != - V_282 ) ) {
V_29 = V_226 ;
goto V_197;
}
if ( V_226 == 0 )
V_29 = V_226 ;
}
V_197:
return ( V_29 == 0 ) ? 0 : V_226 ;
}
static void F_169 ( struct V_207 * V_30 )
{
struct V_27 * V_28 = F_125 ( V_30 ) ;
unsigned int V_284 = F_80 ( V_28 -> V_164 ) ;
F_21 ( V_28 -> V_94 , L_56 , V_284 ) ;
F_105 ( V_28 , V_28 -> V_257 ) ;
F_170 ( V_30 ) ;
F_164 ( V_30 ) ;
}
static int F_171 ( struct V_207 * V_30 , T_9 V_285 , T_6 V_286 )
{
struct V_27 * V_28 = F_125 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
unsigned long V_80 ;
int V_226 = 0 ;
F_32 ( V_28 -> V_94 , L_57 , V_286 ) ;
F_42 ( & V_28 -> V_81 , V_80 ) ;
F_146 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( ( V_34 -> V_287 ) && ( V_286 != 0 ) ) {
V_226 = V_34 -> V_287 ( V_55 -> V_51 , V_286 ) ;
if ( V_226 != 0 ) {
F_21 ( V_28 -> V_94 , L_58 ,
V_286 ) ;
break;
}
}
}
F_44 ( & V_28 -> V_81 , V_80 ) ;
return V_226 ;
}
static int F_172 ( struct V_207 * V_30 , T_9 V_285 , T_6 V_286 )
{
struct V_27 * V_28 = F_125 ( V_30 ) ;
struct V_54 * V_55 ;
struct V_33 * V_34 ;
unsigned long V_80 ;
int V_226 = 0 ;
F_32 ( V_28 -> V_94 , L_59 , V_286 ) ;
F_42 ( & V_28 -> V_81 , V_80 ) ;
F_146 (netcp, intf_modpriv) {
V_34 = V_55 -> V_33 ;
if ( V_34 -> V_288 ) {
V_226 = V_34 -> V_288 ( V_55 -> V_51 , V_286 ) ;
if ( V_226 != 0 ) {
F_21 ( V_28 -> V_94 , L_60 ,
V_286 ) ;
break;
}
}
}
F_44 ( & V_28 -> V_81 , V_80 ) ;
return V_226 ;
}
static T_6 F_173 ( struct V_207 * V_36 , struct V_112 * V_113 ,
void * V_289 ,
T_10 V_290 )
{
return 0 ;
}
static int F_174 ( struct V_207 * V_36 , enum V_291 type ,
void * V_292 )
{
struct V_293 * V_294 = V_292 ;
T_8 V_295 ;
int V_16 ;
F_175 () ;
if ( type != V_296 )
return - V_282 ;
V_294 -> V_297 = V_298 ;
V_295 = V_294 -> V_295 ;
if ( ( V_36 -> V_299 <= 1 ) ||
( V_36 -> V_299 < V_295 ) )
return - V_62 ;
if ( V_295 ) {
F_176 ( V_36 , V_295 ) ;
for ( V_16 = 0 ; V_16 < V_295 ; V_16 ++ )
F_177 ( V_36 , V_16 , 1 , V_16 ) ;
} else {
F_178 ( V_36 ) ;
}
return 0 ;
}
static void
F_179 ( struct V_207 * V_30 , struct V_300 * V_99 )
{
struct V_27 * V_28 = F_125 ( V_30 ) ;
struct V_97 * V_301 = & V_28 -> V_99 ;
T_11 V_302 , V_303 , V_304 , V_305 ;
unsigned int V_306 ;
do {
V_306 = F_180 ( & V_301 -> V_131 ) ;
V_302 = V_301 -> V_132 ;
V_303 = V_301 -> V_133 ;
} while ( F_181 ( & V_301 -> V_131 , V_306 ) );
do {
V_306 = F_180 ( & V_301 -> V_176 ) ;
V_304 = V_301 -> V_177 ;
V_305 = V_301 -> V_178 ;
} while ( F_181 ( & V_301 -> V_176 , V_306 ) );
V_99 -> V_132 = V_302 ;
V_99 -> V_133 = V_303 ;
V_99 -> V_177 = V_304 ;
V_99 -> V_178 = V_305 ;
V_99 -> V_103 = V_301 -> V_103 ;
V_99 -> V_104 = V_301 -> V_104 ;
V_99 -> V_210 = V_301 -> V_210 ;
}
static int F_182 ( struct V_32 * V_32 ,
struct V_24 * V_56 )
{
struct V_35 * V_36 = V_32 -> V_35 ;
struct V_24 * V_25 = V_36 -> V_39 ;
struct V_27 * V_28 ;
struct V_207 * V_30 ;
T_12 V_307 ;
struct V_308 V_309 ;
void T_4 * V_310 = NULL ;
T_2 V_19 = 0 ;
const void * V_311 ;
T_8 V_312 [ 6 ] ;
T_2 V_313 [ 2 ] ;
int V_29 = 0 ;
V_30 = F_183 ( sizeof( * V_28 ) , 1 , 1 ) ;
if ( ! V_30 ) {
F_21 ( V_36 , L_61 ) ;
return - V_47 ;
}
V_30 -> V_314 |= V_315 ;
V_30 -> V_314 |= V_316 ;
V_30 -> V_317 = V_30 -> V_314 ;
V_30 -> V_318 |= V_315 ;
V_30 -> V_319 = V_320 ;
V_30 -> V_321 = V_322 - ( V_323 + V_123 ) ;
V_28 = F_125 ( V_30 ) ;
F_184 ( & V_28 -> V_81 ) ;
F_185 ( & V_28 -> V_59 ) ;
F_185 ( & V_28 -> V_324 ) ;
F_185 ( & V_28 -> V_325 ) ;
F_185 ( & V_28 -> V_234 ) ;
F_186 ( & V_28 -> V_99 . V_131 ) ;
F_186 ( & V_28 -> V_99 . V_176 ) ;
V_28 -> V_32 = V_32 ;
V_28 -> V_36 = V_32 -> V_35 ;
V_28 -> V_30 = V_30 ;
V_28 -> V_94 = & V_30 -> V_36 ;
V_28 -> V_326 = F_187 ( V_327 , V_328 ) ;
V_28 -> V_213 = V_329 ;
V_28 -> V_174 = V_28 -> V_213 ;
V_28 -> V_56 = V_56 ;
V_29 = F_188 ( V_56 , L_62 , & V_19 ) ;
if ( V_19 ) {
if ( F_189 ( V_25 , V_330 , & V_309 ) ) {
F_21 ( V_36 , L_63 ) ;
V_29 = - V_61 ;
goto V_331;
}
V_307 = F_190 ( & V_309 ) ;
if ( ! F_191 ( V_36 , V_309 . V_306 , V_307 ,
F_134 ( V_36 ) ) ) {
F_21 ( V_36 , L_64 ) ;
V_29 = - V_47 ;
goto V_331;
}
V_310 = F_192 ( V_36 , V_309 . V_306 , V_307 ) ;
if ( ! V_310 ) {
F_21 ( V_36 , L_65 ) ;
F_193 ( V_36 , V_309 . V_306 , V_307 ) ;
V_29 = - V_47 ;
goto V_331;
}
F_13 ( V_312 , V_310 , V_19 ) ;
if ( F_194 ( V_312 ) )
F_140 ( V_30 -> V_332 , V_312 ) ;
else
F_195 ( V_30 -> V_332 ) ;
F_196 ( V_36 , V_310 ) ;
F_193 ( V_36 , V_309 . V_306 , V_307 ) ;
} else {
V_311 = F_197 ( V_56 ) ;
if ( V_311 )
F_140 ( V_30 -> V_332 , V_311 ) ;
else
F_195 ( V_30 -> V_332 ) ;
}
V_29 = F_16 ( V_56 , L_66 ,
& V_28 -> V_225 ) ;
if ( V_29 < 0 ) {
F_21 ( V_36 , L_67 ) ;
V_29 = - V_61 ;
goto V_331;
}
V_29 = F_188 ( V_56 , L_68 ,
& V_28 -> V_153 ) ;
if ( V_29 < 0 ) {
F_24 ( V_36 , L_69 ) ;
V_28 -> V_153 = V_333 ;
}
V_29 = F_198 ( V_56 , L_70 ,
V_28 -> V_157 ,
V_138 ) ;
if ( V_29 < 0 ) {
F_21 ( V_36 , L_71 ) ;
V_28 -> V_157 [ 0 ] = 128 ;
}
V_29 = F_198 ( V_56 , L_72 , V_313 , 2 ) ;
if ( V_29 < 0 ) {
F_21 ( V_36 , L_73 ) ;
V_29 = - V_61 ;
goto V_331;
}
V_28 -> V_139 = V_313 [ 0 ] ;
V_28 -> V_256 = V_313 [ 1 ] ;
V_29 = F_198 ( V_56 , L_74 , V_313 , 2 ) ;
if ( V_29 < 0 ) {
F_21 ( V_36 , L_75 ) ;
V_29 = - V_61 ;
goto V_331;
}
V_28 -> V_257 = V_313 [ 0 ] ;
V_28 -> V_258 = V_313 [ 1 ] ;
if ( V_28 -> V_257 < V_329 ) {
F_21 ( V_36 , L_76 ,
V_329 ) ;
V_29 = - V_61 ;
goto V_331;
}
V_29 = F_188 ( V_56 , L_77 ,
& V_28 -> V_200 ) ;
if ( V_29 < 0 ) {
F_24 ( V_36 , L_78 ) ;
V_28 -> V_200 = V_333 ;
}
F_199 ( V_30 , & V_28 -> V_160 , F_97 , V_334 ) ;
F_200 ( V_30 , & V_28 -> V_179 , F_110 , V_334 ) ;
V_30 -> V_335 = 0 ;
V_30 -> V_336 = V_337 ;
V_30 -> V_338 = & V_339 ;
F_201 ( V_30 , V_36 ) ;
F_26 ( & V_28 -> V_340 , & V_32 -> V_341 ) ;
return 0 ;
V_331:
F_202 ( V_30 ) ;
return V_29 ;
}
static void F_203 ( struct V_32 * V_32 ,
struct V_207 * V_30 )
{
struct V_54 * V_55 , * V_43 ;
struct V_27 * V_28 = F_125 ( V_30 ) ;
struct V_33 * V_34 ;
F_32 ( V_32 -> V_35 , L_79 ,
V_30 -> V_26 ) ;
F_39 (intf_modpriv, tmp, &netcp->module_head,
intf_list) {
V_34 = V_55 -> V_33 ;
F_32 ( V_32 -> V_35 , L_80 ,
V_34 -> V_26 ) ;
if ( V_34 -> V_71 )
V_34 -> V_71 ( V_55 -> V_51 ) ;
F_27 ( & V_55 -> V_58 ) ;
}
F_34 ( ! F_204 ( & V_28 -> V_59 ) , L_81 ,
V_30 -> V_26 ) ;
F_27 ( & V_28 -> V_340 ) ;
F_23 ( V_28 -> V_56 ) ;
F_205 ( V_30 ) ;
F_202 ( V_30 ) ;
}
static int F_206 ( struct V_342 * V_343 )
{
struct V_24 * V_25 = V_343 -> V_36 . V_39 ;
struct V_27 * V_27 , * V_69 ;
struct V_24 * V_40 , * V_344 ;
struct V_32 * V_32 ;
struct V_35 * V_36 = & V_343 -> V_36 ;
int V_29 ;
if ( ! V_25 ) {
F_21 ( V_36 , L_82 ) ;
return - V_61 ;
}
V_32 = F_25 ( V_36 , sizeof( * V_32 ) , V_46 ) ;
if ( ! V_32 )
return - V_47 ;
F_207 ( & V_343 -> V_36 ) ;
V_29 = F_208 ( & V_343 -> V_36 ) ;
if ( V_29 < 0 ) {
F_21 ( V_36 , L_83 ) ;
F_209 ( & V_343 -> V_36 ) ;
return V_29 ;
}
F_185 ( & V_32 -> V_341 ) ;
F_185 ( & V_32 -> V_49 ) ;
V_32 -> V_35 = V_36 ;
F_210 ( V_343 , V_32 ) ;
V_344 = F_20 ( V_25 , L_84 ) ;
if ( ! V_344 ) {
F_21 ( V_36 , L_85 ) ;
V_29 = - V_61 ;
goto V_345;
}
F_22 (interfaces, child) {
V_29 = F_182 ( V_32 , V_40 ) ;
if ( V_29 ) {
F_21 ( V_36 , L_86 ,
V_40 -> V_26 ) ;
goto V_346;
}
}
F_23 ( V_344 ) ;
F_26 ( & V_32 -> V_347 , & V_348 ) ;
return 0 ;
V_346:
F_39 (netcp_intf, netcp_tmp,
&netcp_device->interface_head,
interface_list) {
F_203 ( V_32 , V_27 -> V_30 ) ;
}
F_23 ( V_344 ) ;
V_345:
F_211 ( & V_343 -> V_36 ) ;
F_209 ( & V_343 -> V_36 ) ;
F_210 ( V_343 , NULL ) ;
return V_29 ;
}
static int F_212 ( struct V_342 * V_343 )
{
struct V_32 * V_32 = F_213 ( V_343 ) ;
struct V_27 * V_27 , * V_69 ;
struct V_41 * V_42 , * V_43 ;
struct V_33 * V_34 ;
F_39 (inst_modpriv, tmp, &netcp_device->modpriv_head,
inst_list) {
V_34 = V_42 -> V_33 ;
F_32 ( & V_343 -> V_36 , L_87 , V_34 -> V_26 ) ;
V_34 -> remove ( V_32 , V_42 -> V_51 ) ;
F_27 ( & V_42 -> V_48 ) ;
}
F_39 (netcp_intf, netcp_tmp,
&netcp_device->interface_head,
interface_list) {
F_203 ( V_32 , V_27 -> V_30 ) ;
}
F_34 ( ! F_204 ( & V_32 -> V_341 ) ,
L_88 , V_343 -> V_26 ) ;
F_211 ( & V_343 -> V_36 ) ;
F_209 ( & V_343 -> V_36 ) ;
F_210 ( V_343 , NULL ) ;
return 0 ;
}
