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
static int F_10 ( char * V_18 , void T_2 * V_19 )
{
unsigned int V_20 , V_21 ;
V_21 = F_11 ( V_19 + 4 ) ;
V_20 = F_11 ( V_19 ) ;
V_18 [ 0 ] = ( V_21 & 0x0000ff00 ) >> 8 ;
V_18 [ 1 ] = V_21 & 0x000000ff ;
V_18 [ 2 ] = ( V_20 & 0xff000000 ) >> 24 ;
V_18 [ 3 ] = ( V_20 & 0x00ff0000 ) >> 16 ;
V_18 [ 4 ] = ( V_20 & 0x0000ff00 ) >> 8 ;
V_18 [ 5 ] = V_20 & 0x000000ff ;
return 0 ;
}
static const char * F_12 ( struct V_22 * V_23 )
{
const char * V_24 ;
if ( F_13 ( V_23 , L_1 , & V_24 ) < 0 )
V_24 = V_23 -> V_24 ;
if ( ! V_24 )
V_24 = L_2 ;
return V_24 ;
}
static int F_14 ( struct V_25 * V_26 )
{
int V_27 ;
V_27 = F_15 ( V_26 -> V_28 ) ;
if ( ! V_27 )
V_26 -> V_29 = true ;
return V_27 ;
}
static int F_16 ( struct V_30 * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = V_30 -> V_33 ;
struct V_22 * V_35 , * V_36 , * V_23 = V_34 -> V_37 ;
struct V_22 * V_38 ;
struct V_39 * V_40 ;
struct V_25 * V_25 ;
struct V_31 * V_41 ;
bool V_42 = false ;
int V_27 ;
V_35 = F_17 ( V_23 , L_3 ) ;
if ( ! V_35 ) {
F_18 ( V_34 , L_4 ) ;
return V_43 ;
}
F_19 (devices, child) {
const char * V_24 = F_12 ( V_38 ) ;
if ( ! strcasecmp ( V_32 -> V_24 , V_24 ) )
break;
}
F_20 ( V_35 ) ;
if ( ! V_38 ) {
F_21 ( V_34 , L_5 , V_32 -> V_24 ) ;
return V_43 ;
}
V_40 = F_22 ( V_34 , sizeof( * V_40 ) , V_44 ) ;
if ( ! V_40 ) {
F_20 ( V_38 ) ;
return - V_45 ;
}
V_40 -> V_30 = V_30 ;
V_40 -> V_31 = V_32 ;
F_23 ( & V_40 -> V_46 , & V_30 -> V_47 ) ;
V_27 = V_32 -> V_48 ( V_30 , V_34 , V_38 ,
& V_40 -> V_49 ) ;
F_20 ( V_38 ) ;
if ( V_27 ) {
F_18 ( V_34 , L_6 ,
V_32 -> V_24 , V_27 ) ;
F_24 ( & V_40 -> V_46 ) ;
F_25 ( V_34 , V_40 ) ;
return V_50 ;
}
F_26 (tmp) {
if ( V_41 -> V_51 )
V_42 = true ;
}
if ( ! V_42 )
return 0 ;
F_27 (netcp_intf, &netcp_device->interface_head,
interface_list) {
struct V_52 * V_53 ;
if ( ! V_25 -> V_29 )
V_27 = F_14 ( V_25 ) ;
if ( V_27 )
return - V_54 ;
V_53 = F_22 ( V_34 , sizeof( * V_53 ) ,
V_44 ) ;
if ( ! V_53 )
return - V_45 ;
V_36 = F_28 ( V_25 -> V_55 ,
V_32 -> V_24 , 0 ) ;
V_53 -> V_56 = V_25 ;
V_53 -> V_31 = V_32 ;
F_23 ( & V_53 -> V_57 ,
& V_25 -> V_58 ) ;
V_27 = V_32 -> V_59 ( V_40 -> V_49 ,
V_25 -> V_28 , V_36 ,
& V_53 -> V_49 ) ;
F_20 ( V_36 ) ;
if ( V_27 ) {
F_29 ( V_34 , L_7 ,
V_32 -> V_24 , V_27 ) ;
F_24 ( & V_53 -> V_57 ) ;
F_25 ( V_34 , V_53 ) ;
continue;
}
}
return 0 ;
}
int F_30 ( struct V_31 * V_32 )
{
struct V_30 * V_30 ;
struct V_31 * V_41 ;
int V_27 ;
if ( ! V_32 -> V_24 ) {
F_31 ( 1 , L_8 ) ;
return - V_60 ;
}
if ( ! V_32 -> V_48 ) {
F_31 ( 1 , L_9 ) ;
return - V_60 ;
}
F_32 ( & V_61 ) ;
F_26 (tmp) {
if ( ! strcasecmp ( V_41 -> V_24 , V_32 -> V_24 ) ) {
F_33 ( & V_61 ) ;
return - V_62 ;
}
}
F_23 ( & V_32 -> V_63 , & V_64 ) ;
F_27 (netcp_device, &netcp_devices, device_list) {
V_27 = F_16 ( V_30 , V_32 ) ;
if ( V_27 < 0 )
goto V_65;
}
F_33 ( & V_61 ) ;
return 0 ;
V_65:
F_33 ( & V_61 ) ;
F_34 ( V_32 ) ;
return V_27 ;
}
static void F_35 ( struct V_30 * V_30 ,
struct V_31 * V_32 )
{
struct V_39 * V_40 , * V_66 ;
struct V_25 * V_25 , * V_67 ;
struct V_33 * V_34 = V_30 -> V_33 ;
F_36 (netcp_intf, netcp_tmp,
&netcp_device->interface_head,
interface_list) {
struct V_52 * V_53 , * V_68 ;
F_36 (intf_modpriv, intf_tmp,
&netcp_intf->module_head,
intf_list) {
if ( V_53 -> V_31 == V_32 ) {
V_32 -> V_69 ( V_53 -> V_49 ) ;
F_24 ( & V_53 -> V_57 ) ;
F_25 ( V_34 , V_53 ) ;
break;
}
}
}
F_36 (inst_modpriv, inst_tmp,
&netcp_device->modpriv_head, inst_list) {
if ( V_40 -> V_31 == V_32 ) {
V_32 -> remove ( V_30 ,
V_40 -> V_49 ) ;
F_24 ( & V_40 -> V_46 ) ;
F_25 ( V_34 , V_40 ) ;
break;
}
}
}
void F_34 ( struct V_31 * V_32 )
{
struct V_30 * V_30 ;
struct V_31 * V_70 ;
F_32 ( & V_61 ) ;
F_27 (netcp_device, &netcp_devices, device_list) {
F_35 ( V_30 , V_32 ) ;
}
F_26 (module_tmp) {
if ( V_32 == V_70 ) {
F_24 ( & V_32 -> V_63 ) ;
break;
}
}
F_33 ( & V_61 ) ;
}
void * F_37 ( struct V_31 * V_32 ,
struct V_25 * V_71 )
{
struct V_52 * V_53 ;
F_27 (intf_modpriv, &intf->module_head, intf_list)
if ( V_53 -> V_31 == V_32 )
return V_53 -> V_49 ;
return NULL ;
}
int F_38 ( struct V_25 * V_56 , int V_72 ,
T_3 * V_73 , void * V_74 )
{
struct V_75 * V_76 ;
struct V_75 * V_77 ;
unsigned long V_78 ;
V_76 = F_22 ( V_56 -> V_34 , sizeof( * V_76 ) , V_44 ) ;
if ( ! V_76 )
return - V_45 ;
V_76 -> V_73 = V_73 ;
V_76 -> V_74 = V_74 ;
V_76 -> V_72 = V_72 ;
F_39 ( & V_56 -> V_79 , V_78 ) ;
F_27 (next, &netcp_priv->txhook_list_head, list) {
if ( V_77 -> V_72 > V_72 )
break;
}
F_40 ( & V_76 -> V_80 , V_77 -> V_80 . V_81 , & V_77 -> V_80 ) ;
F_41 ( & V_56 -> V_79 , V_78 ) ;
return 0 ;
}
int F_42 ( struct V_25 * V_56 , int V_72 ,
T_3 * V_73 , void * V_74 )
{
struct V_75 * V_77 , * V_82 ;
unsigned long V_78 ;
F_39 ( & V_56 -> V_79 , V_78 ) ;
F_36 (next, n, &netcp_priv->txhook_list_head, list) {
if ( ( V_77 -> V_72 == V_72 ) &&
( V_77 -> V_73 == V_73 ) &&
( V_77 -> V_74 == V_74 ) ) {
F_24 ( & V_77 -> V_80 ) ;
F_41 ( & V_56 -> V_79 , V_78 ) ;
F_25 ( V_56 -> V_34 , V_77 ) ;
return 0 ;
}
}
F_41 ( & V_56 -> V_79 , V_78 ) ;
return - V_83 ;
}
int F_43 ( struct V_25 * V_56 , int V_72 ,
T_3 * V_73 , void * V_74 )
{
struct V_75 * V_76 ;
struct V_75 * V_77 ;
unsigned long V_78 ;
V_76 = F_22 ( V_56 -> V_34 , sizeof( * V_76 ) , V_44 ) ;
if ( ! V_76 )
return - V_45 ;
V_76 -> V_73 = V_73 ;
V_76 -> V_74 = V_74 ;
V_76 -> V_72 = V_72 ;
F_39 ( & V_56 -> V_79 , V_78 ) ;
F_27 (next, &netcp_priv->rxhook_list_head, list) {
if ( V_77 -> V_72 > V_72 )
break;
}
F_40 ( & V_76 -> V_80 , V_77 -> V_80 . V_81 , & V_77 -> V_80 ) ;
F_41 ( & V_56 -> V_79 , V_78 ) ;
return 0 ;
}
int F_44 ( struct V_25 * V_56 , int V_72 ,
T_3 * V_73 , void * V_74 )
{
struct V_75 * V_77 , * V_82 ;
unsigned long V_78 ;
F_39 ( & V_56 -> V_79 , V_78 ) ;
F_36 (next, n, &netcp_priv->rxhook_list_head, list) {
if ( ( V_77 -> V_72 == V_72 ) &&
( V_77 -> V_73 == V_73 ) &&
( V_77 -> V_74 == V_74 ) ) {
F_24 ( & V_77 -> V_80 ) ;
F_41 ( & V_56 -> V_79 , V_78 ) ;
F_25 ( V_56 -> V_34 , V_77 ) ;
return 0 ;
}
}
F_41 ( & V_56 -> V_79 , V_78 ) ;
return - V_83 ;
}
static void F_45 ( bool V_84 , void * V_85 )
{
if ( V_84 )
F_46 ( V_85 ) ;
else
F_47 ( V_85 ) ;
}
static void F_48 ( struct V_25 * V_26 ,
struct V_4 * V_5 )
{
struct V_4 * V_3 ;
T_4 V_86 , V_87 ;
unsigned int V_88 , V_89 = sizeof( * V_3 ) ;
void * V_90 ;
T_1 V_41 ;
F_4 ( & V_86 , 1 , & V_5 -> V_6 ) ;
while ( V_86 ) {
V_3 = F_49 ( V_26 -> V_91 , V_86 , V_89 ) ;
if ( F_50 ( ! V_3 ) ) {
F_18 ( V_26 -> V_92 , L_10 ) ;
break;
}
F_1 ( & V_87 , & V_41 , & V_86 , V_3 ) ;
F_2 ( ( T_1 * ) & V_90 , & V_41 , V_3 ) ;
F_51 ( V_26 -> V_34 , V_87 , V_93 , V_94 ) ;
F_52 ( V_90 ) ;
F_53 ( V_26 -> V_91 , V_5 ) ;
}
F_2 ( ( T_1 * ) & V_90 , & V_88 , V_5 ) ;
if ( V_90 )
F_45 ( V_88 <= V_93 , V_90 ) ;
F_53 ( V_26 -> V_91 , V_5 ) ;
}
static void F_54 ( struct V_25 * V_26 )
{
struct V_4 * V_5 ;
unsigned int V_89 ;
T_4 V_95 ;
for (; ; ) {
V_95 = F_55 ( V_26 -> V_96 , & V_89 ) ;
if ( ! V_95 )
break;
V_5 = F_49 ( V_26 -> V_91 , V_95 , V_89 ) ;
if ( F_50 ( ! V_5 ) ) {
F_18 ( V_26 -> V_92 , L_11 ,
V_97 ) ;
V_26 -> V_28 -> V_98 . V_99 ++ ;
continue;
}
F_48 ( V_26 , V_5 ) ;
V_26 -> V_28 -> V_98 . V_100 ++ ;
}
}
static int F_56 ( struct V_25 * V_26 )
{
unsigned int V_89 , V_88 , V_101 ;
struct V_4 * V_5 , * V_3 ;
unsigned int V_102 = 0 , V_103 ;
struct V_75 * V_104 ;
T_4 V_86 , V_105 ;
struct V_106 V_107 ;
struct V_108 * V_109 ;
void * V_110 ;
T_1 V_41 ;
V_86 = F_55 ( V_26 -> V_96 , & V_89 ) ;
if ( ! V_86 )
return - 1 ;
V_5 = F_49 ( V_26 -> V_91 , V_86 , V_89 ) ;
if ( F_50 ( ! V_5 ) ) {
F_18 ( V_26 -> V_92 , L_10 ) ;
return 0 ;
}
F_1 ( & V_105 , & V_88 , & V_86 , V_5 ) ;
F_2 ( ( T_1 * ) & V_110 , & V_101 , V_5 ) ;
if ( F_50 ( ! V_110 ) ) {
F_18 ( V_26 -> V_92 , L_12 ) ;
goto V_111;
}
V_102 &= V_112 ;
V_103 = V_88 ;
F_57 ( V_26 -> V_34 , V_105 , V_88 , V_94 ) ;
V_109 = F_58 ( V_110 , V_101 ) ;
if ( F_50 ( ! V_109 ) ) {
F_18 ( V_26 -> V_92 , L_13 ) ;
goto V_111;
}
F_59 ( V_109 , V_113 ) ;
F_60 ( V_109 , V_88 ) ;
while ( V_86 ) {
struct V_114 * V_114 ;
V_3 = F_49 ( V_26 -> V_91 , V_86 , V_89 ) ;
if ( F_50 ( ! V_3 ) ) {
F_18 ( V_26 -> V_92 , L_10 ) ;
goto V_111;
}
F_1 ( & V_105 , & V_88 , & V_86 , V_3 ) ;
F_2 ( ( T_1 * ) & V_114 , & V_41 , V_3 ) ;
if ( F_61 ( V_105 && V_88 && V_114 ) ) {
F_51 ( V_26 -> V_34 , V_105 , V_93 ,
V_94 ) ;
} else {
F_18 ( V_26 -> V_92 , L_14 ,
( void * ) V_105 , V_88 , V_114 ) ;
goto V_111;
}
F_62 ( V_109 , F_63 ( V_109 ) -> V_115 , V_114 ,
F_64 ( V_105 ) , V_88 , V_93 ) ;
V_103 += V_88 ;
F_53 ( V_26 -> V_91 , V_3 ) ;
}
F_53 ( V_26 -> V_91 , V_5 ) ;
if ( F_50 ( V_102 != V_103 ) )
F_29 ( V_26 -> V_92 , L_15 ,
V_102 , V_103 ) ;
F_65 ( V_109 , V_109 -> V_116 - V_117 ) ;
V_107 . V_109 = V_109 ;
V_107 . V_118 = false ;
F_27 (rx_hook, &netcp->rxhook_list_head, list) {
int V_27 ;
V_27 = V_104 -> V_73 ( V_104 -> V_72 , V_104 -> V_74 ,
& V_107 ) ;
if ( F_50 ( V_27 ) ) {
F_18 ( V_26 -> V_92 , L_16 ,
V_104 -> V_72 , V_27 ) ;
V_26 -> V_28 -> V_98 . V_99 ++ ;
F_66 ( V_109 ) ;
return 0 ;
}
}
V_26 -> V_28 -> V_98 . V_119 ++ ;
V_26 -> V_28 -> V_98 . V_120 += V_109 -> V_116 ;
V_109 -> V_121 = F_67 ( V_109 , V_26 -> V_28 ) ;
F_68 ( V_109 ) ;
return 0 ;
V_111:
F_48 ( V_26 , V_5 ) ;
V_26 -> V_28 -> V_98 . V_99 ++ ;
return 0 ;
}
static int F_69 ( struct V_25 * V_26 ,
unsigned int V_122 )
{
int V_14 ;
for ( V_14 = 0 ; ( V_14 < V_122 ) && ! F_56 ( V_26 ) ; V_14 ++ )
;
return V_14 ;
}
static void F_70 ( struct V_25 * V_26 , int V_123 )
{
struct V_4 * V_5 ;
unsigned int V_88 , V_89 ;
T_4 V_95 ;
void * V_90 ;
T_1 V_41 ;
while ( ( V_95 = F_55 ( V_26 -> V_124 [ V_123 ] , & V_89 ) ) ) {
V_5 = F_49 ( V_26 -> V_91 , V_95 , V_89 ) ;
if ( F_50 ( ! V_5 ) ) {
F_18 ( V_26 -> V_92 , L_10 ) ;
continue;
}
F_3 ( & V_95 , & V_88 , V_5 ) ;
F_2 ( ( T_1 * ) & V_90 , & V_41 , V_5 ) ;
if ( F_50 ( ! V_95 ) ) {
F_18 ( V_26 -> V_92 , L_17 ) ;
F_53 ( V_26 -> V_91 , V_5 ) ;
continue;
}
if ( F_50 ( ! V_90 ) ) {
F_18 ( V_26 -> V_92 , L_12 ) ;
F_53 ( V_26 -> V_91 , V_5 ) ;
continue;
}
if ( V_123 == 0 ) {
F_57 ( V_26 -> V_34 , V_95 , V_88 ,
V_94 ) ;
F_45 ( ( V_88 <= V_93 ) , V_90 ) ;
} else {
F_51 ( V_26 -> V_34 , V_95 , V_88 ,
V_94 ) ;
F_52 ( V_90 ) ;
}
F_53 ( V_26 -> V_91 , V_5 ) ;
}
}
static void F_71 ( struct V_25 * V_26 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_125 &&
! F_72 ( V_26 -> V_124 [ V_14 ] ) ; V_14 ++ )
F_70 ( V_26 , V_14 ) ;
if ( F_73 ( V_26 -> V_91 ) != V_26 -> V_126 )
F_18 ( V_26 -> V_92 , L_18 ,
V_26 -> V_126 - F_73 ( V_26 -> V_91 ) ) ;
F_74 ( V_26 -> V_91 ) ;
V_26 -> V_91 = NULL ;
}
static void F_75 ( struct V_25 * V_26 , int V_123 )
{
struct V_4 * V_127 ;
unsigned int V_88 , V_89 ;
T_1 V_15 , V_16 ;
struct V_114 * V_114 ;
T_4 V_95 ;
void * V_128 ;
T_1 V_9 [ 2 ] ;
V_127 = F_76 ( V_26 -> V_91 ) ;
if ( F_72 ( V_127 ) ) {
F_29 ( V_26 -> V_92 , L_19 ) ;
return;
}
if ( F_61 ( V_123 == 0 ) ) {
unsigned int V_129 ;
V_88 = V_130 + V_113 ;
V_129 = F_77 ( V_88 ) +
F_77 ( sizeof( struct V_131 ) ) ;
V_128 = F_78 ( V_129 ) ;
V_9 [ 1 ] = V_129 ;
if ( F_50 ( ! V_128 ) ) {
F_79 ( V_26 -> V_92 ,
L_20 ) ;
goto V_65;
}
V_95 = F_80 ( V_26 -> V_34 , V_128 , V_88 ,
V_132 ) ;
if ( F_50 ( F_81 ( V_26 -> V_34 , V_95 ) ) )
goto V_65;
V_9 [ 0 ] = ( T_1 ) V_128 ;
} else {
V_114 = F_82 ( V_133 | V_134 | V_135 ) ;
if ( F_50 ( ! V_114 ) ) {
F_79 ( V_26 -> V_92 , L_21 ) ;
goto V_65;
}
V_88 = V_93 ;
V_95 = F_83 ( V_26 -> V_34 , V_114 , 0 , V_88 , V_132 ) ;
V_9 [ 0 ] = ( T_1 ) V_114 ;
V_9 [ 1 ] = 0 ;
}
V_15 = V_136 ;
V_15 |= V_88 & V_112 ;
V_16 = V_137 ;
V_16 |= V_138 << V_139 ;
V_16 |= ( V_26 -> V_140 & V_141 ) <<
V_142 ;
F_8 ( V_95 , V_88 , V_127 ) ;
F_7 ( V_9 [ 0 ] , V_9 [ 1 ] , V_127 ) ;
F_6 ( V_15 , V_16 , V_127 ) ;
F_84 ( V_26 -> V_91 , V_127 , sizeof( * V_127 ) , & V_95 ,
& V_89 ) ;
F_85 ( V_26 -> V_124 [ V_123 ] , V_95 , sizeof( * V_127 ) , 0 ) ;
return;
V_65:
F_53 ( V_26 -> V_91 , V_127 ) ;
}
static void F_86 ( struct V_25 * V_26 )
{
T_1 V_143 [ V_125 ] = { 0 } ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_125 && V_26 -> V_124 [ V_14 ] ; V_14 ++ ) {
V_143 [ V_14 ] = V_26 -> V_144 [ V_14 ] -
F_87 ( V_26 -> V_124 [ V_14 ] ) ;
while ( V_143 [ V_14 ] -- )
F_75 ( V_26 , V_14 ) ;
}
}
static int F_88 ( struct V_145 * V_146 , int V_122 )
{
struct V_25 * V_26 = F_89 ( V_146 , struct V_25 ,
V_147 ) ;
unsigned int V_148 ;
V_148 = F_69 ( V_26 , V_122 ) ;
if ( V_148 < V_122 ) {
F_90 ( & V_26 -> V_147 ) ;
F_91 ( V_26 -> V_96 ) ;
}
F_86 ( V_26 ) ;
return V_148 ;
}
static void F_92 ( void * V_149 )
{
struct V_25 * V_26 = V_149 ;
F_93 ( V_26 -> V_96 ) ;
F_94 ( & V_26 -> V_147 ) ;
}
static void F_95 ( struct V_25 * V_26 ,
struct V_4 * V_5 ,
unsigned int V_150 )
{
struct V_4 * V_3 = V_5 ;
T_4 V_86 , V_87 ;
unsigned int V_88 ;
while ( V_3 ) {
F_1 ( & V_87 , & V_88 , & V_86 , V_3 ) ;
if ( V_87 && V_88 )
F_57 ( V_26 -> V_34 , V_87 , V_88 ,
V_132 ) ;
else
F_21 ( V_26 -> V_92 , L_22 ,
( void * ) V_87 , V_88 ) ;
F_53 ( V_26 -> V_151 , V_3 ) ;
V_3 = NULL ;
if ( V_86 ) {
V_3 = F_49 ( V_26 -> V_151 , V_86 ,
V_150 ) ;
if ( ! V_3 )
F_18 ( V_26 -> V_92 , L_23 ) ;
}
}
}
static int F_96 ( struct V_25 * V_26 ,
unsigned int V_122 )
{
struct V_4 * V_5 ;
struct V_108 * V_109 ;
unsigned int V_89 ;
T_4 V_95 ;
int V_152 = 0 ;
T_1 V_41 ;
while ( V_122 -- ) {
V_95 = F_55 ( V_26 -> V_153 , & V_89 ) ;
if ( ! V_95 )
break;
V_5 = F_49 ( V_26 -> V_151 , V_95 , V_89 ) ;
if ( F_50 ( ! V_5 ) ) {
F_18 ( V_26 -> V_92 , L_23 ) ;
V_26 -> V_28 -> V_98 . V_154 ++ ;
continue;
}
F_2 ( ( T_1 * ) & V_109 , & V_41 , V_5 ) ;
F_95 ( V_26 , V_5 , V_89 ) ;
if ( ! V_109 ) {
F_18 ( V_26 -> V_92 , L_24 ) ;
V_26 -> V_28 -> V_98 . V_154 ++ ;
continue;
}
if ( F_97 ( V_26 -> V_28 , V_109 ) &&
F_98 ( V_26 -> V_28 ) &&
( F_73 ( V_26 -> V_151 ) >
V_26 -> V_155 ) ) {
T_5 V_156 = F_99 ( V_109 ) ;
F_100 ( V_26 -> V_28 , V_156 ) ;
}
V_26 -> V_28 -> V_98 . V_157 ++ ;
V_26 -> V_28 -> V_98 . V_158 += V_109 -> V_116 ;
F_66 ( V_109 ) ;
V_152 ++ ;
}
return V_152 ;
}
static int F_101 ( struct V_145 * V_146 , int V_122 )
{
int V_148 ;
struct V_25 * V_26 = F_89 ( V_146 , struct V_25 ,
V_159 ) ;
V_148 = F_96 ( V_26 , V_122 ) ;
if ( V_148 < V_122 ) {
F_90 ( & V_26 -> V_159 ) ;
F_91 ( V_26 -> V_153 ) ;
}
return V_148 ;
}
static void F_102 ( void * V_149 )
{
struct V_25 * V_26 = V_149 ;
F_93 ( V_26 -> V_153 ) ;
F_94 ( & V_26 -> V_159 ) ;
}
static struct V_4 *
F_103 ( struct V_108 * V_109 , struct V_25 * V_26 )
{
struct V_4 * V_5 , * V_3 , * V_160 ;
unsigned int V_161 = F_104 ( V_109 ) ;
struct V_33 * V_34 = V_26 -> V_34 ;
T_4 V_162 ;
unsigned int V_89 ;
int V_14 ;
V_162 = F_80 ( V_34 , V_109 -> V_163 , V_161 , V_132 ) ;
if ( F_50 ( F_81 ( V_34 , V_162 ) ) ) {
F_18 ( V_26 -> V_92 , L_25 ) ;
return NULL ;
}
V_5 = F_76 ( V_26 -> V_151 ) ;
if ( F_50 ( F_72 ( V_5 ) ) ) {
F_18 ( V_26 -> V_92 , L_26 ) ;
F_57 ( V_34 , V_162 , V_161 , V_132 ) ;
return NULL ;
}
F_5 ( V_162 , V_161 , 0 , V_5 ) ;
if ( F_105 ( V_109 ) ) {
F_106 ( F_63 ( V_109 ) ) ;
} else {
V_5 -> V_6 = 0 ;
goto V_164;
}
V_160 = V_5 ;
for ( V_14 = 0 ; V_14 < F_63 ( V_109 ) -> V_115 ; V_14 ++ ) {
T_6 * V_165 = & F_63 ( V_109 ) -> V_166 [ V_14 ] ;
struct V_114 * V_114 = F_107 ( V_165 ) ;
T_1 V_167 = V_165 -> V_167 ;
T_1 V_88 = F_108 ( V_165 ) ;
T_4 V_168 ;
T_1 V_16 ;
V_162 = F_83 ( V_34 , V_114 , V_167 , V_88 ,
V_132 ) ;
if ( F_50 ( ! V_162 ) ) {
F_18 ( V_26 -> V_92 , L_27 ) ;
goto V_169;
}
V_3 = F_76 ( V_26 -> V_151 ) ;
if ( F_50 ( F_72 ( V_3 ) ) ) {
F_18 ( V_26 -> V_92 , L_28 ) ;
F_51 ( V_34 , V_162 , V_88 , V_132 ) ;
goto V_169;
}
V_168 = F_109 ( V_26 -> V_151 ,
( void * ) V_3 ) ;
V_16 =
( V_26 -> V_170 & V_141 ) <<
V_142 ;
F_5 ( V_162 , V_88 , 0 , V_3 ) ;
F_9 ( & V_168 , 1 , & V_160 -> V_6 ) ;
V_161 += V_88 ;
if ( V_160 != V_5 )
F_84 ( V_26 -> V_151 , V_160 ,
sizeof( * V_160 ) , & V_168 , & V_89 ) ;
V_160 = V_3 ;
}
if ( V_160 != V_5 )
F_84 ( V_26 -> V_151 , V_160 , sizeof( * V_160 ) ,
& V_162 , & V_89 ) ;
if ( F_63 ( V_109 ) -> V_171 ) {
F_110 ( V_26 -> V_92 , L_29 ) ;
goto V_169;
}
V_164:
F_111 ( V_161 != V_109 -> V_116 ) ;
V_161 &= V_112 ;
F_9 ( & V_161 , 1 , & V_5 -> V_15 ) ;
return V_5 ;
V_169:
F_95 ( V_26 , V_5 , sizeof( * V_5 ) ) ;
return NULL ;
}
static int F_112 ( struct V_25 * V_26 ,
struct V_108 * V_109 ,
struct V_4 * V_5 )
{
struct V_172 * V_173 = NULL ;
struct V_75 * V_174 ;
struct V_106 V_107 ;
unsigned int V_89 ;
T_4 V_95 ;
T_1 V_41 = 0 ;
int V_27 = 0 ;
V_107 . V_26 = V_26 ;
V_107 . V_109 = V_109 ;
V_107 . V_173 = NULL ;
V_107 . V_175 = 0 ;
V_107 . V_176 = NULL ;
V_107 . V_177 = NULL ;
V_107 . V_178 = V_5 -> V_178 ;
V_107 . V_179 = V_5 -> V_179 ;
memset ( V_107 . V_178 , 0 , V_180 * sizeof( T_1 ) ) ;
F_27 (tx_hook, &netcp->txhook_list_head, list) {
V_27 = V_174 -> V_73 ( V_174 -> V_72 , V_174 -> V_74 ,
& V_107 ) ;
if ( F_50 ( V_27 != 0 ) ) {
F_18 ( V_26 -> V_92 , L_30 ,
V_174 -> V_72 , V_27 ) ;
V_27 = ( V_27 < 0 ) ? V_27 : V_181 ;
goto V_182;
}
}
V_173 = V_107 . V_173 ;
if ( ! V_173 ) {
F_18 ( V_26 -> V_92 , L_31 ) ;
V_27 = - V_183 ;
goto V_182;
}
if ( V_107 . V_175 ) {
T_1 * V_179 = V_107 . V_179 ;
memmove ( V_107 . V_179 , V_107 . V_179 + V_107 . V_175 ,
V_107 . V_175 ) ;
F_9 ( V_179 , V_107 . V_175 , V_179 ) ;
V_41 |= ( V_107 . V_175 & V_184 ) <<
V_139 ;
}
V_41 |= V_137 |
( ( V_26 -> V_170 & V_141 ) <<
V_142 ) ;
if ( ! ( V_173 -> V_78 & V_185 ) ) {
V_41 |= ( ( V_173 -> V_186 & V_187 ) <<
V_188 ) ;
}
F_9 ( & V_41 , 1 , & V_5 -> V_17 ) ;
F_9 ( ( T_1 * ) & V_109 , 1 , & V_5 -> V_9 [ 0 ] ) ;
if ( V_173 -> V_78 & V_185 ) {
V_41 = V_173 -> V_186 ;
F_9 ( ( T_1 * ) & V_41 , 1 , & V_5 -> V_189 ) ;
}
V_27 = F_84 ( V_26 -> V_151 , V_5 , sizeof( * V_5 ) , & V_95 ,
& V_89 ) ;
if ( F_50 ( V_27 ) ) {
F_18 ( V_26 -> V_92 , L_32 , V_97 ) ;
V_27 = - V_45 ;
goto V_182;
}
F_113 ( V_109 ) ;
F_85 ( V_173 -> V_190 , V_95 , V_89 , 0 ) ;
V_182:
return V_27 ;
}
static int F_114 ( struct V_108 * V_109 , struct V_191 * V_28 )
{
struct V_25 * V_26 = F_115 ( V_28 ) ;
int V_156 = F_99 ( V_109 ) ;
struct V_4 * V_5 ;
int V_192 , V_27 = 0 ;
if ( F_50 ( V_109 -> V_116 <= 0 ) ) {
F_66 ( V_109 ) ;
return V_181 ;
}
if ( F_50 ( V_109 -> V_116 < V_193 ) ) {
V_27 = F_116 ( V_109 , V_193 ) ;
if ( V_27 < 0 ) {
F_21 ( V_26 -> V_92 , L_33 ,
V_27 ) ;
V_28 -> V_98 . V_194 ++ ;
return V_27 ;
}
V_109 -> V_116 = V_193 ;
}
V_5 = F_103 ( V_109 , V_26 ) ;
if ( F_50 ( ! V_5 ) ) {
F_117 ( V_28 , V_156 ) ;
V_27 = - V_195 ;
goto V_196;
}
V_27 = F_112 ( V_26 , V_109 , V_5 ) ;
if ( V_27 )
goto V_196;
V_28 -> V_197 = V_198 ;
V_192 = F_73 ( V_26 -> V_151 ) ;
if ( V_192 < V_26 -> V_199 ) {
F_29 ( V_26 -> V_92 , L_34 , V_192 ) ;
F_117 ( V_28 , V_156 ) ;
}
return V_181 ;
V_196:
V_28 -> V_98 . V_194 ++ ;
if ( V_5 )
F_95 ( V_26 , V_5 , sizeof( * V_5 ) ) ;
F_66 ( V_109 ) ;
return V_27 ;
}
int F_118 ( struct V_172 * V_173 )
{
if ( V_173 -> V_200 ) {
F_119 ( V_173 -> V_200 ) ;
V_173 -> V_200 = NULL ;
}
return 0 ;
}
int F_120 ( struct V_172 * V_173 )
{
struct V_33 * V_34 = V_173 -> V_30 -> V_33 ;
struct V_201 V_202 ;
int V_27 = 0 ;
T_7 V_24 [ 16 ] ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 . V_203 = V_204 ;
V_202 . V_205 . V_206 . V_207 = false ;
V_202 . V_205 . V_206 . V_208 = false ;
V_202 . V_205 . V_206 . V_209 = V_210 ;
V_173 -> V_200 = F_121 ( V_34 ,
V_173 -> V_211 , & V_202 ) ;
if ( F_72 ( V_173 -> V_200 ) ) {
F_18 ( V_34 , L_35 ,
V_173 -> V_211 ) ;
goto V_212;
}
snprintf ( V_24 , sizeof( V_24 ) , L_36 , F_122 ( V_34 ) ) ;
V_173 -> V_190 = F_123 ( V_24 , V_173 -> V_213 ,
V_214 ) ;
if ( F_124 ( V_173 -> V_190 ) ) {
F_18 ( V_34 , L_37 ,
V_24 , V_27 ) ;
V_27 = F_125 ( V_173 -> V_190 ) ;
goto V_212;
}
F_29 ( V_34 , L_38 , V_24 ) ;
return 0 ;
V_212:
if ( ! F_72 ( V_173 -> V_200 ) )
F_119 ( V_173 -> V_200 ) ;
V_173 -> V_200 = NULL ;
return V_27 ;
}
int F_126 ( struct V_172 * V_173 ,
struct V_30 * V_30 ,
const char * V_211 , unsigned int V_213 )
{
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
V_173 -> V_30 = V_30 ;
V_173 -> V_211 = V_211 ;
V_173 -> V_213 = V_213 ;
return 0 ;
}
static struct V_215 * F_127 ( struct V_25 * V_26 ,
const T_7 * V_216 ,
enum V_217 type )
{
struct V_215 * V_218 ;
F_27 (naddr, &netcp->addr_list, node) {
if ( V_218 -> type != type )
continue;
if ( V_216 && memcmp ( V_216 , V_218 -> V_216 , V_219 ) )
continue;
return V_218 ;
}
return NULL ;
}
static struct V_215 * F_128 ( struct V_25 * V_26 ,
const T_7 * V_216 ,
enum V_217 type )
{
struct V_215 * V_218 ;
V_218 = F_129 ( V_26 -> V_34 , sizeof( * V_218 ) , V_133 ) ;
if ( ! V_218 )
return NULL ;
V_218 -> type = type ;
V_218 -> V_78 = 0 ;
V_218 -> V_26 = V_26 ;
if ( V_216 )
F_130 ( V_218 -> V_216 , V_216 ) ;
else
F_131 ( V_218 -> V_216 ) ;
F_23 ( & V_218 -> V_23 , & V_26 -> V_220 ) ;
return V_218 ;
}
static void F_132 ( struct V_25 * V_26 , struct V_215 * V_218 )
{
F_24 ( & V_218 -> V_23 ) ;
F_25 ( V_26 -> V_34 , V_218 ) ;
}
static void F_133 ( struct V_25 * V_26 )
{
struct V_215 * V_218 ;
F_27 (naddr, &netcp->addr_list, node)
V_218 -> V_78 = 0 ;
}
static void F_134 ( struct V_25 * V_26 , const T_7 * V_216 ,
enum V_217 type )
{
struct V_215 * V_218 ;
V_218 = F_127 ( V_26 , V_216 , type ) ;
if ( V_218 ) {
V_218 -> V_78 |= V_221 ;
return;
}
V_218 = F_128 ( V_26 , V_216 , type ) ;
if ( ! F_111 ( ! V_218 ) )
V_218 -> V_78 |= V_222 ;
}
static void F_135 ( struct V_25 * V_26 )
{
struct V_215 * V_218 , * V_41 ;
struct V_52 * V_223 ;
struct V_31 * V_32 ;
int error ;
F_36 (naddr, tmp, &netcp->addr_list, node) {
if ( V_218 -> V_78 & ( V_221 | V_222 ) )
continue;
F_29 ( V_26 -> V_92 , L_39 ,
V_218 -> V_216 , V_218 -> type ) ;
F_32 ( & V_61 ) ;
F_136 (netcp, priv) {
V_32 = V_223 -> V_31 ;
if ( ! V_32 -> V_224 )
continue;
error = V_32 -> V_224 ( V_223 -> V_49 ,
V_218 ) ;
F_111 ( error ) ;
}
F_33 ( & V_61 ) ;
F_132 ( V_26 , V_218 ) ;
}
}
static void F_137 ( struct V_25 * V_26 )
{
struct V_215 * V_218 , * V_41 ;
struct V_52 * V_223 ;
struct V_31 * V_32 ;
int error ;
F_36 (naddr, tmp, &netcp->addr_list, node) {
if ( ! ( V_218 -> V_78 & V_222 ) )
continue;
F_29 ( V_26 -> V_92 , L_40 ,
V_218 -> V_216 , V_218 -> type ) ;
F_32 ( & V_61 ) ;
F_136 (netcp, priv) {
V_32 = V_223 -> V_31 ;
if ( ! V_32 -> V_225 )
continue;
error = V_32 -> V_225 ( V_223 -> V_49 , V_218 ) ;
F_111 ( error ) ;
}
F_33 ( & V_61 ) ;
}
}
static void F_138 ( struct V_191 * V_28 )
{
struct V_25 * V_26 = F_115 ( V_28 ) ;
struct V_226 * V_227 ;
bool V_228 ;
V_228 = ( V_28 -> V_78 & V_229 ||
V_28 -> V_78 & V_230 ||
F_139 ( V_28 ) > V_231 ) ;
F_133 ( V_26 ) ;
F_134 ( V_26 , V_28 -> V_232 , V_233 ) ;
F_140 (ndev, ndev_addr)
F_134 ( V_26 , V_227 -> V_216 , V_234 ) ;
F_141 (ndev_addr, ndev)
F_134 ( V_26 , V_227 -> V_216 , V_235 ) ;
F_142 (ndev_addr, ndev)
F_134 ( V_26 , V_227 -> V_216 , V_236 ) ;
if ( V_228 )
F_134 ( V_26 , NULL , V_237 ) ;
F_135 ( V_26 ) ;
F_137 ( V_26 ) ;
}
static void F_143 ( struct V_25 * V_26 )
{
int V_14 ;
if ( V_26 -> V_238 ) {
F_119 ( V_26 -> V_238 ) ;
V_26 -> V_238 = NULL ;
}
if ( ! F_72 ( V_26 -> V_91 ) )
F_71 ( V_26 ) ;
if ( ! F_72 ( V_26 -> V_96 ) ) {
F_144 ( V_26 -> V_96 ) ;
V_26 -> V_96 = NULL ;
}
for ( V_14 = 0 ; V_14 < V_125 &&
! F_72 ( V_26 -> V_124 [ V_14 ] ) ; ++ V_14 ) {
F_144 ( V_26 -> V_124 [ V_14 ] ) ;
V_26 -> V_124 [ V_14 ] = NULL ;
}
if ( ! F_72 ( V_26 -> V_153 ) ) {
F_144 ( V_26 -> V_153 ) ;
V_26 -> V_153 = NULL ;
}
if ( ! F_72 ( V_26 -> V_151 ) ) {
F_74 ( V_26 -> V_151 ) ;
V_26 -> V_151 = NULL ;
}
}
static int F_145 ( struct V_191 * V_28 )
{
struct V_25 * V_26 = F_115 ( V_28 ) ;
struct V_239 V_240 ;
struct V_201 V_202 ;
T_1 V_241 = 0 ;
T_7 V_24 [ 16 ] ;
int V_27 ;
int V_14 ;
snprintf ( V_24 , sizeof( V_24 ) , L_41 , V_28 -> V_24 ) ;
V_26 -> V_91 = F_146 ( V_24 , V_26 -> V_126 ,
V_26 -> V_242 ) ;
if ( F_72 ( V_26 -> V_91 ) ) {
F_18 ( V_26 -> V_92 , L_42 ) ;
V_27 = F_125 ( V_26 -> V_91 ) ;
goto V_65;
}
snprintf ( V_24 , sizeof( V_24 ) , L_43 , V_28 -> V_24 ) ;
V_26 -> V_151 = F_146 ( V_24 , V_26 -> V_243 ,
V_26 -> V_244 ) ;
if ( F_72 ( V_26 -> V_151 ) ) {
F_18 ( V_26 -> V_92 , L_44 ) ;
V_27 = F_125 ( V_26 -> V_151 ) ;
goto V_65;
}
snprintf ( V_24 , sizeof( V_24 ) , L_45 , V_28 -> V_24 ) ;
V_26 -> V_153 = F_123 ( V_24 , V_26 -> V_170 , 0 ) ;
if ( F_72 ( V_26 -> V_153 ) ) {
V_27 = F_125 ( V_26 -> V_153 ) ;
goto V_65;
}
V_26 -> V_170 = F_147 ( V_26 -> V_153 ) ;
V_240 . V_245 = F_102 ;
V_240 . V_246 = V_26 ;
V_27 = F_148 ( V_26 -> V_153 ,
V_247 ,
( unsigned long ) & V_240 ) ;
if ( V_27 )
goto V_65;
F_93 ( V_26 -> V_153 ) ;
snprintf ( V_24 , sizeof( V_24 ) , L_46 , V_28 -> V_24 ) ;
V_26 -> V_96 = F_123 ( V_24 , V_26 -> V_140 , 0 ) ;
if ( F_72 ( V_26 -> V_96 ) ) {
V_27 = F_125 ( V_26 -> V_96 ) ;
goto V_65;
}
V_26 -> V_140 = F_147 ( V_26 -> V_96 ) ;
V_240 . V_245 = F_92 ;
V_240 . V_246 = V_26 ;
V_27 = F_148 ( V_26 -> V_96 ,
V_247 ,
( unsigned long ) & V_240 ) ;
if ( V_27 )
goto V_65;
F_93 ( V_26 -> V_96 ) ;
for ( V_14 = 0 ; V_14 < V_125 && V_26 -> V_144 [ V_14 ] ;
++ V_14 ) {
snprintf ( V_24 , sizeof( V_24 ) , L_47 , V_28 -> V_24 , V_14 ) ;
V_26 -> V_124 [ V_14 ] = F_123 ( V_24 , V_248 , 0 ) ;
if ( F_72 ( V_26 -> V_124 [ V_14 ] ) ) {
V_27 = F_125 ( V_26 -> V_124 [ V_14 ] ) ;
goto V_65;
}
}
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 . V_203 = V_249 ;
V_202 . V_205 . V_250 . V_251 = true ;
V_202 . V_205 . V_250 . V_252 = true ;
V_202 . V_205 . V_250 . V_253 = V_254 ;
V_202 . V_205 . V_250 . V_255 = V_256 ;
V_202 . V_205 . V_250 . V_257 = false ;
V_202 . V_205 . V_250 . V_258 = V_113 ;
V_202 . V_205 . V_250 . V_259 = V_26 -> V_140 ;
V_202 . V_205 . V_250 . V_260 = V_261 ;
for ( V_14 = 0 ; V_14 < V_125 ; ++ V_14 ) {
if ( V_26 -> V_124 [ V_14 ] )
V_241 = F_147 ( V_26 -> V_124 [ V_14 ] ) ;
V_202 . V_205 . V_250 . V_123 [ V_14 ] = V_241 ;
}
V_26 -> V_238 = F_121 ( V_26 -> V_30 -> V_33 ,
V_26 -> V_211 , & V_202 ) ;
if ( F_72 ( V_26 -> V_238 ) ) {
F_18 ( V_26 -> V_92 , L_48 ,
V_26 -> V_211 ) ;
goto V_65;
}
F_29 ( V_26 -> V_92 , L_49 , V_26 -> V_238 ) ;
return 0 ;
V_65:
F_143 ( V_26 ) ;
return V_27 ;
}
static int F_149 ( struct V_191 * V_28 )
{
struct V_25 * V_26 = F_115 ( V_28 ) ;
struct V_52 * V_53 ;
struct V_31 * V_32 ;
int V_27 ;
F_150 ( V_28 ) ;
V_27 = F_145 ( V_28 ) ;
if ( V_27 ) {
F_18 ( V_26 -> V_92 , L_50 ) ;
goto V_65;
}
F_32 ( & V_61 ) ;
F_136 (netcp, intf_modpriv) {
V_32 = V_53 -> V_31 ;
if ( V_32 -> V_262 ) {
V_27 = V_32 -> V_262 ( V_53 -> V_49 , V_28 ) ;
if ( V_27 != 0 ) {
F_18 ( V_26 -> V_92 , L_51 ) ;
goto V_263;
}
}
}
F_33 ( & V_61 ) ;
F_151 ( & V_26 -> V_147 ) ;
F_151 ( & V_26 -> V_159 ) ;
F_91 ( V_26 -> V_153 ) ;
F_91 ( V_26 -> V_96 ) ;
F_86 ( V_26 ) ;
F_152 ( V_28 ) ;
F_29 ( V_26 -> V_92 , L_52 , V_28 -> V_24 ) ;
return 0 ;
V_263:
F_136 (netcp, intf_modpriv) {
V_32 = V_53 -> V_31 ;
if ( V_32 -> V_264 )
V_32 -> V_264 ( V_53 -> V_49 , V_28 ) ;
}
F_33 ( & V_61 ) ;
V_65:
F_143 ( V_26 ) ;
return V_27 ;
}
static int F_153 ( struct V_191 * V_28 )
{
struct V_25 * V_26 = F_115 ( V_28 ) ;
struct V_52 * V_53 ;
struct V_31 * V_32 ;
int V_212 = 0 ;
F_154 ( V_28 ) ;
F_150 ( V_28 ) ;
F_133 ( V_26 ) ;
F_135 ( V_26 ) ;
F_93 ( V_26 -> V_96 ) ;
F_93 ( V_26 -> V_153 ) ;
F_155 ( & V_26 -> V_147 ) ;
F_155 ( & V_26 -> V_159 ) ;
F_32 ( & V_61 ) ;
F_136 (netcp, intf_modpriv) {
V_32 = V_53 -> V_31 ;
if ( V_32 -> V_264 ) {
V_212 = V_32 -> V_264 ( V_53 -> V_49 , V_28 ) ;
if ( V_212 != 0 )
F_18 ( V_26 -> V_92 , L_53 ) ;
}
}
F_33 ( & V_61 ) ;
F_54 ( V_26 ) ;
F_96 ( V_26 , V_26 -> V_243 ) ;
if ( F_73 ( V_26 -> V_151 ) != V_26 -> V_243 )
F_18 ( V_26 -> V_92 , L_54 ,
V_26 -> V_243 - F_73 ( V_26 -> V_151 ) ) ;
F_143 ( V_26 ) ;
F_29 ( V_26 -> V_92 , L_55 , V_28 -> V_24 ) ;
return 0 ;
}
static int F_156 ( struct V_191 * V_28 ,
struct V_265 * V_266 , int V_267 )
{
struct V_25 * V_26 = F_115 ( V_28 ) ;
struct V_52 * V_53 ;
struct V_31 * V_32 ;
int V_27 = - 1 , V_212 = - V_268 ;
if ( ! F_98 ( V_28 ) )
return - V_60 ;
F_32 ( & V_61 ) ;
F_136 (netcp, intf_modpriv) {
V_32 = V_53 -> V_31 ;
if ( ! V_32 -> V_269 )
continue;
V_212 = V_32 -> V_269 ( V_53 -> V_49 , V_266 , V_267 ) ;
if ( ( V_212 < 0 ) && ( V_212 != - V_268 ) ) {
V_27 = V_212 ;
goto V_182;
}
if ( V_212 == 0 )
V_27 = V_212 ;
}
V_182:
F_33 ( & V_61 ) ;
return ( V_27 == 0 ) ? 0 : V_212 ;
}
static int F_157 ( struct V_191 * V_28 , int V_270 )
{
struct V_25 * V_26 = F_115 ( V_28 ) ;
if ( ( V_270 < 68 ) ||
( V_270 > ( V_271 - V_272 - V_117 ) ) ) {
F_18 ( V_26 -> V_92 , L_56 , V_270 ) ;
return - V_60 ;
}
V_28 -> V_273 = V_270 ;
return 0 ;
}
static void F_158 ( struct V_191 * V_28 )
{
struct V_25 * V_26 = F_115 ( V_28 ) ;
unsigned int V_274 = F_73 ( V_26 -> V_151 ) ;
F_18 ( V_26 -> V_92 , L_57 , V_274 ) ;
F_96 ( V_26 , V_26 -> V_243 ) ;
V_28 -> V_197 = V_198 ;
F_152 ( V_28 ) ;
}
static int F_159 ( struct V_191 * V_28 , T_8 V_275 , T_5 V_276 )
{
struct V_25 * V_26 = F_115 ( V_28 ) ;
struct V_52 * V_53 ;
struct V_31 * V_32 ;
int V_212 = 0 ;
F_29 ( V_26 -> V_92 , L_58 , V_276 ) ;
F_32 ( & V_61 ) ;
F_136 (netcp, intf_modpriv) {
V_32 = V_53 -> V_31 ;
if ( ( V_32 -> V_277 ) && ( V_276 != 0 ) ) {
V_212 = V_32 -> V_277 ( V_53 -> V_49 , V_276 ) ;
if ( V_212 != 0 ) {
F_18 ( V_26 -> V_92 , L_59 ,
V_276 ) ;
break;
}
}
}
F_33 ( & V_61 ) ;
return V_212 ;
}
static int F_160 ( struct V_191 * V_28 , T_8 V_275 , T_5 V_276 )
{
struct V_25 * V_26 = F_115 ( V_28 ) ;
struct V_52 * V_53 ;
struct V_31 * V_32 ;
int V_212 = 0 ;
F_29 ( V_26 -> V_92 , L_60 , V_276 ) ;
F_32 ( & V_61 ) ;
F_136 (netcp, intf_modpriv) {
V_32 = V_53 -> V_31 ;
if ( V_32 -> V_278 ) {
V_212 = V_32 -> V_278 ( V_53 -> V_49 , V_276 ) ;
if ( V_212 != 0 ) {
F_18 ( V_26 -> V_92 , L_61 ,
V_276 ) ;
break;
}
}
}
F_33 ( & V_61 ) ;
return V_212 ;
}
static T_5 F_161 ( struct V_191 * V_34 , struct V_108 * V_109 ,
void * V_279 ,
T_9 V_280 )
{
return 0 ;
}
static int F_162 ( struct V_191 * V_34 , T_7 V_281 )
{
int V_14 ;
F_163 () ;
if ( ( V_34 -> V_282 <= 1 ) ||
( V_34 -> V_282 < V_281 ) )
return - V_60 ;
if ( V_281 ) {
F_164 ( V_34 , V_281 ) ;
for ( V_14 = 0 ; V_14 < V_281 ; V_14 ++ )
F_165 ( V_34 , V_14 , 1 , V_14 ) ;
} else {
F_166 ( V_34 ) ;
}
return 0 ;
}
static int F_167 ( struct V_30 * V_30 ,
struct V_22 * V_55 )
{
struct V_33 * V_34 = V_30 -> V_33 ;
struct V_22 * V_23 = V_34 -> V_37 ;
struct V_25 * V_26 ;
struct V_191 * V_28 ;
T_10 V_283 ;
struct V_284 V_285 ;
void T_2 * V_286 = NULL ;
T_1 V_19 = 0 ;
const void * V_287 ;
T_7 V_288 [ 6 ] ;
T_1 V_289 [ 2 ] ;
int V_27 = 0 ;
V_28 = F_168 ( sizeof( * V_26 ) , 1 , 1 ) ;
if ( ! V_28 ) {
F_18 ( V_34 , L_62 ) ;
return - V_45 ;
}
V_28 -> V_290 |= V_291 ;
V_28 -> V_290 |= V_292 ;
V_28 -> V_293 = V_28 -> V_290 ;
V_28 -> V_294 |= V_291 ;
V_26 = F_115 ( V_28 ) ;
F_169 ( & V_26 -> V_79 ) ;
F_170 ( & V_26 -> V_58 ) ;
F_170 ( & V_26 -> V_295 ) ;
F_170 ( & V_26 -> V_296 ) ;
F_170 ( & V_26 -> V_220 ) ;
V_26 -> V_30 = V_30 ;
V_26 -> V_34 = V_30 -> V_33 ;
V_26 -> V_28 = V_28 ;
V_26 -> V_92 = & V_28 -> V_34 ;
V_26 -> V_297 = F_171 ( V_298 , V_299 ) ;
V_26 -> V_199 = V_300 ;
V_26 -> V_155 = V_26 -> V_199 ;
V_26 -> V_55 = V_55 ;
V_27 = F_172 ( V_55 , L_63 , & V_19 ) ;
if ( V_19 ) {
if ( F_173 ( V_23 , V_301 , & V_285 ) ) {
F_18 ( V_34 , L_64 ) ;
V_27 = - V_54 ;
goto V_302;
}
V_283 = F_174 ( & V_285 ) ;
if ( ! F_175 ( V_34 , V_285 . V_303 , V_283 ,
F_122 ( V_34 ) ) ) {
F_18 ( V_34 , L_65 ) ;
V_27 = - V_45 ;
goto V_302;
}
V_286 = F_176 ( V_34 , V_285 . V_303 , V_283 ) ;
if ( ! V_286 ) {
F_18 ( V_34 , L_66 ) ;
F_177 ( V_34 , V_285 . V_303 , V_283 ) ;
V_27 = - V_45 ;
goto V_302;
}
F_10 ( V_288 , V_286 ) ;
if ( F_178 ( V_288 ) )
F_130 ( V_28 -> V_304 , V_288 ) ;
else
F_179 ( V_28 -> V_304 ) ;
F_180 ( V_34 , V_286 ) ;
F_177 ( V_34 , V_285 . V_303 , V_283 ) ;
} else {
V_287 = F_181 ( V_55 ) ;
if ( V_287 )
F_130 ( V_28 -> V_304 , V_287 ) ;
else
F_179 ( V_28 -> V_304 ) ;
}
V_27 = F_13 ( V_55 , L_67 ,
& V_26 -> V_211 ) ;
if ( V_27 < 0 ) {
F_18 ( V_34 , L_68 ) ;
V_27 = - V_54 ;
goto V_302;
}
V_27 = F_172 ( V_55 , L_69 ,
& V_26 -> V_140 ) ;
if ( V_27 < 0 ) {
F_21 ( V_34 , L_70 ) ;
V_26 -> V_140 = V_305 ;
}
V_27 = F_182 ( V_55 , L_71 ,
V_26 -> V_144 ,
V_125 ) ;
if ( V_27 < 0 ) {
F_18 ( V_34 , L_72 ) ;
V_26 -> V_144 [ 0 ] = 128 ;
}
V_27 = F_182 ( V_55 , L_73 , V_289 , 2 ) ;
if ( V_27 < 0 ) {
F_18 ( V_34 , L_74 ) ;
V_27 = - V_54 ;
goto V_302;
}
V_26 -> V_126 = V_289 [ 0 ] ;
V_26 -> V_242 = V_289 [ 1 ] ;
V_27 = F_182 ( V_55 , L_75 , V_289 , 2 ) ;
if ( V_27 < 0 ) {
F_18 ( V_34 , L_76 ) ;
V_27 = - V_54 ;
goto V_302;
}
V_26 -> V_243 = V_289 [ 0 ] ;
V_26 -> V_244 = V_289 [ 1 ] ;
if ( V_26 -> V_243 < V_300 ) {
F_18 ( V_34 , L_77 ,
V_300 ) ;
V_27 = - V_54 ;
goto V_302;
}
V_27 = F_172 ( V_55 , L_78 ,
& V_26 -> V_170 ) ;
if ( V_27 < 0 ) {
F_21 ( V_34 , L_79 ) ;
V_26 -> V_170 = V_305 ;
}
F_183 ( V_28 , & V_26 -> V_147 , F_88 , V_306 ) ;
F_183 ( V_28 , & V_26 -> V_159 , F_101 , V_306 ) ;
V_28 -> V_307 = 0 ;
V_28 -> V_308 = V_309 ;
V_28 -> V_310 = & V_311 ;
F_184 ( V_28 , V_34 ) ;
F_23 ( & V_26 -> V_312 , & V_30 -> V_313 ) ;
return 0 ;
V_302:
F_185 ( V_28 ) ;
return V_27 ;
}
static void F_186 ( struct V_30 * V_30 ,
struct V_191 * V_28 )
{
struct V_52 * V_53 , * V_41 ;
struct V_25 * V_26 = F_115 ( V_28 ) ;
struct V_31 * V_32 ;
F_29 ( V_30 -> V_33 , L_80 ,
V_28 -> V_24 ) ;
F_36 (intf_modpriv, tmp, &netcp->module_head,
intf_list) {
V_32 = V_53 -> V_31 ;
F_29 ( V_30 -> V_33 , L_81 ,
V_32 -> V_24 ) ;
if ( V_32 -> V_69 )
V_32 -> V_69 ( V_53 -> V_49 ) ;
F_24 ( & V_53 -> V_57 ) ;
F_47 ( V_53 ) ;
}
F_31 ( ! F_187 ( & V_26 -> V_58 ) , L_82 ,
V_28 -> V_24 ) ;
F_24 ( & V_26 -> V_312 ) ;
F_20 ( V_26 -> V_55 ) ;
F_188 ( V_28 ) ;
F_189 ( & V_26 -> V_147 ) ;
F_185 ( V_28 ) ;
}
static int F_190 ( struct V_314 * V_315 )
{
struct V_22 * V_23 = V_315 -> V_34 . V_37 ;
struct V_25 * V_25 , * V_67 ;
struct V_22 * V_38 , * V_316 ;
struct V_30 * V_30 ;
struct V_33 * V_34 = & V_315 -> V_34 ;
struct V_31 * V_32 ;
int V_27 ;
if ( ! V_23 ) {
F_18 ( V_34 , L_83 ) ;
return - V_54 ;
}
V_30 = F_22 ( V_34 , sizeof( * V_30 ) , V_44 ) ;
if ( ! V_30 )
return - V_45 ;
F_191 ( & V_315 -> V_34 ) ;
V_27 = F_192 ( & V_315 -> V_34 ) ;
if ( V_27 < 0 ) {
F_18 ( V_34 , L_84 ) ;
F_193 ( & V_315 -> V_34 ) ;
return V_27 ;
}
F_170 ( & V_30 -> V_313 ) ;
F_170 ( & V_30 -> V_47 ) ;
V_30 -> V_33 = V_34 ;
F_194 ( V_315 , V_30 ) ;
V_316 = F_17 ( V_23 , L_85 ) ;
if ( ! V_316 ) {
F_18 ( V_34 , L_86 ) ;
V_27 = - V_54 ;
goto V_317;
}
F_19 (interfaces, child) {
V_27 = F_167 ( V_30 , V_38 ) ;
if ( V_27 ) {
F_18 ( V_34 , L_87 ,
V_38 -> V_24 ) ;
goto V_318;
}
}
F_23 ( & V_30 -> V_319 , & V_320 ) ;
F_32 ( & V_61 ) ;
F_26 (module) {
V_27 = F_16 ( V_30 , V_32 ) ;
if ( V_27 < 0 )
F_18 ( V_34 , L_88 , V_32 -> V_24 ) ;
}
F_33 ( & V_61 ) ;
return 0 ;
V_318:
F_36 (netcp_intf, netcp_tmp,
&netcp_device->interface_head,
interface_list) {
F_186 ( V_30 , V_25 -> V_28 ) ;
}
V_317:
F_195 ( & V_315 -> V_34 ) ;
F_193 ( & V_315 -> V_34 ) ;
F_194 ( V_315 , NULL ) ;
return V_27 ;
}
static int F_196 ( struct V_314 * V_315 )
{
struct V_30 * V_30 = F_197 ( V_315 ) ;
struct V_25 * V_25 , * V_67 ;
struct V_39 * V_40 , * V_41 ;
struct V_31 * V_32 ;
F_36 (inst_modpriv, tmp, &netcp_device->modpriv_head,
inst_list) {
V_32 = V_40 -> V_31 ;
F_29 ( & V_315 -> V_34 , L_89 , V_32 -> V_24 ) ;
V_32 -> remove ( V_30 , V_40 -> V_49 ) ;
F_24 ( & V_40 -> V_46 ) ;
F_47 ( V_40 ) ;
}
F_36 (netcp_intf, netcp_tmp,
&netcp_device->interface_head,
interface_list) {
F_186 ( V_30 , V_25 -> V_28 ) ;
}
F_31 ( ! F_187 ( & V_30 -> V_313 ) ,
L_90 , V_315 -> V_24 ) ;
F_195 ( & V_315 -> V_34 ) ;
F_193 ( & V_315 -> V_34 ) ;
F_194 ( V_315 , NULL ) ;
return 0 ;
}
