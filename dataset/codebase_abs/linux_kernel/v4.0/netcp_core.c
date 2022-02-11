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
F_46 ( F_47 ( V_85 ) ) ;
else
F_48 ( V_85 ) ;
}
static void F_49 ( struct V_25 * V_26 ,
struct V_4 * V_5 )
{
struct V_4 * V_3 ;
T_4 V_86 , V_87 ;
unsigned int V_88 , V_89 = sizeof( * V_3 ) ;
void * V_90 ;
T_1 V_41 ;
F_4 ( & V_86 , 1 , & V_5 -> V_6 ) ;
while ( V_86 ) {
V_3 = F_50 ( V_26 -> V_91 , V_86 , V_89 ) ;
if ( F_51 ( ! V_3 ) ) {
F_18 ( V_26 -> V_92 , L_10 ) ;
break;
}
F_1 ( & V_87 , & V_41 , & V_86 , V_3 ) ;
F_2 ( ( T_1 * ) & V_90 , & V_41 , V_3 ) ;
F_52 ( V_26 -> V_34 , V_87 , V_93 , V_94 ) ;
F_53 ( V_90 ) ;
F_54 ( V_26 -> V_91 , V_5 ) ;
}
F_2 ( ( T_1 * ) & V_90 , & V_88 , V_5 ) ;
if ( V_90 )
F_45 ( V_88 <= V_93 , V_90 ) ;
F_54 ( V_26 -> V_91 , V_5 ) ;
}
static void F_55 ( struct V_25 * V_26 )
{
struct V_4 * V_5 ;
unsigned int V_89 ;
T_4 V_95 ;
for (; ; ) {
V_95 = F_56 ( V_26 -> V_96 , & V_89 ) ;
if ( ! V_95 )
break;
V_5 = F_50 ( V_26 -> V_91 , V_95 , V_89 ) ;
if ( F_51 ( ! V_5 ) ) {
F_18 ( V_26 -> V_92 , L_11 ,
V_97 ) ;
V_26 -> V_28 -> V_98 . V_99 ++ ;
continue;
}
F_49 ( V_26 , V_5 ) ;
V_26 -> V_28 -> V_98 . V_100 ++ ;
}
}
static int F_57 ( struct V_25 * V_26 )
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
V_86 = F_56 ( V_26 -> V_96 , & V_89 ) ;
if ( ! V_86 )
return - 1 ;
V_5 = F_50 ( V_26 -> V_91 , V_86 , V_89 ) ;
if ( F_51 ( ! V_5 ) ) {
F_18 ( V_26 -> V_92 , L_10 ) ;
return 0 ;
}
F_1 ( & V_105 , & V_88 , & V_86 , V_5 ) ;
F_2 ( ( T_1 * ) & V_110 , & V_101 , V_5 ) ;
if ( F_51 ( ! V_110 ) ) {
F_18 ( V_26 -> V_92 , L_12 ) ;
goto V_111;
}
V_102 &= V_112 ;
V_103 = V_88 ;
F_58 ( V_26 -> V_34 , V_105 , V_88 , V_94 ) ;
V_109 = F_59 ( V_110 , V_101 ) ;
if ( F_51 ( ! V_109 ) ) {
F_18 ( V_26 -> V_92 , L_13 ) ;
goto V_111;
}
F_60 ( V_109 , V_113 ) ;
F_61 ( V_109 , V_88 ) ;
while ( V_86 ) {
struct V_114 * V_114 ;
V_3 = F_50 ( V_26 -> V_91 , V_86 , V_89 ) ;
if ( F_51 ( ! V_3 ) ) {
F_18 ( V_26 -> V_92 , L_10 ) ;
goto V_111;
}
F_1 ( & V_105 , & V_88 , & V_86 , V_3 ) ;
F_2 ( ( T_1 * ) & V_114 , & V_41 , V_3 ) ;
if ( F_62 ( V_105 && V_88 && V_114 ) ) {
F_52 ( V_26 -> V_34 , V_105 , V_93 ,
V_94 ) ;
} else {
F_18 ( V_26 -> V_92 , L_14 ,
( void * ) V_105 , V_88 , V_114 ) ;
goto V_111;
}
F_63 ( V_109 , F_64 ( V_109 ) -> V_115 , V_114 ,
F_65 ( V_105 ) , V_88 , V_93 ) ;
V_103 += V_88 ;
F_54 ( V_26 -> V_91 , V_3 ) ;
}
F_54 ( V_26 -> V_91 , V_5 ) ;
if ( F_51 ( V_102 != V_103 ) )
F_29 ( V_26 -> V_92 , L_15 ,
V_102 , V_103 ) ;
F_66 ( V_109 , V_109 -> V_116 - V_117 ) ;
V_107 . V_109 = V_109 ;
V_107 . V_118 = false ;
F_27 (rx_hook, &netcp->rxhook_list_head, list) {
int V_27 ;
V_27 = V_104 -> V_73 ( V_104 -> V_72 , V_104 -> V_74 ,
& V_107 ) ;
if ( F_51 ( V_27 ) ) {
F_18 ( V_26 -> V_92 , L_16 ,
V_104 -> V_72 , V_27 ) ;
V_26 -> V_28 -> V_98 . V_99 ++ ;
F_67 ( V_109 ) ;
return 0 ;
}
}
V_26 -> V_28 -> V_119 = V_120 ;
V_26 -> V_28 -> V_98 . V_121 ++ ;
V_26 -> V_28 -> V_98 . V_122 += V_109 -> V_116 ;
V_109 -> V_123 = F_68 ( V_109 , V_26 -> V_28 ) ;
F_69 ( V_109 ) ;
return 0 ;
V_111:
F_49 ( V_26 , V_5 ) ;
V_26 -> V_28 -> V_98 . V_99 ++ ;
return 0 ;
}
static int F_70 ( struct V_25 * V_26 ,
unsigned int V_124 )
{
int V_14 ;
for ( V_14 = 0 ; ( V_14 < V_124 ) && ! F_57 ( V_26 ) ; V_14 ++ )
;
return V_14 ;
}
static void F_71 ( struct V_25 * V_26 , int V_125 )
{
struct V_4 * V_5 ;
unsigned int V_88 , V_89 ;
T_4 V_95 ;
void * V_90 ;
T_1 V_41 ;
while ( ( V_95 = F_56 ( V_26 -> V_126 [ V_125 ] , & V_89 ) ) ) {
V_5 = F_50 ( V_26 -> V_91 , V_95 , V_89 ) ;
if ( F_51 ( ! V_5 ) ) {
F_18 ( V_26 -> V_92 , L_10 ) ;
continue;
}
F_3 ( & V_95 , & V_88 , V_5 ) ;
F_2 ( ( T_1 * ) & V_90 , & V_41 , V_5 ) ;
if ( F_51 ( ! V_95 ) ) {
F_18 ( V_26 -> V_92 , L_17 ) ;
F_54 ( V_26 -> V_91 , V_5 ) ;
continue;
}
if ( F_51 ( ! V_90 ) ) {
F_18 ( V_26 -> V_92 , L_12 ) ;
F_54 ( V_26 -> V_91 , V_5 ) ;
continue;
}
if ( V_125 == 0 ) {
F_58 ( V_26 -> V_34 , V_95 , V_88 ,
V_94 ) ;
F_45 ( ( V_88 <= V_93 ) , V_90 ) ;
} else {
F_52 ( V_26 -> V_34 , V_95 , V_88 ,
V_94 ) ;
F_53 ( V_90 ) ;
}
F_54 ( V_26 -> V_91 , V_5 ) ;
}
}
static void F_72 ( struct V_25 * V_26 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_127 &&
! F_73 ( V_26 -> V_126 [ V_14 ] ) ; V_14 ++ )
F_71 ( V_26 , V_14 ) ;
if ( F_74 ( V_26 -> V_91 ) != V_26 -> V_128 )
F_18 ( V_26 -> V_92 , L_18 ,
V_26 -> V_128 - F_74 ( V_26 -> V_91 ) ) ;
F_75 ( V_26 -> V_91 ) ;
V_26 -> V_91 = NULL ;
}
static void F_76 ( struct V_25 * V_26 , int V_125 )
{
struct V_4 * V_129 ;
unsigned int V_88 , V_89 ;
T_1 V_15 , V_16 ;
struct V_114 * V_114 ;
T_4 V_95 ;
void * V_130 ;
T_1 V_9 [ 2 ] ;
V_129 = F_77 ( V_26 -> V_91 ) ;
if ( F_73 ( V_129 ) ) {
F_29 ( V_26 -> V_92 , L_19 ) ;
return;
}
if ( F_62 ( V_125 == 0 ) ) {
unsigned int V_131 ;
V_88 = V_26 -> V_132 [ 0 ] + V_113 ;
V_131 = F_78 ( V_88 ) +
F_78 ( sizeof( struct V_133 ) ) ;
if ( V_131 <= V_93 ) {
V_130 = F_79 ( V_131 ) ;
V_9 [ 1 ] = V_131 ;
} else {
V_130 = F_80 ( V_131 , V_134 |
V_135 | V_136 ) ;
V_9 [ 1 ] = 0 ;
}
if ( F_51 ( ! V_130 ) ) {
F_81 ( V_26 -> V_92 , L_20 ) ;
goto V_65;
}
V_95 = F_82 ( V_26 -> V_34 , V_130 , V_88 ,
V_137 ) ;
V_9 [ 0 ] = ( T_1 ) V_130 ;
} else {
V_114 = F_83 ( V_134 | V_135 | V_136 ) ;
if ( F_51 ( ! V_114 ) ) {
F_81 ( V_26 -> V_92 , L_21 ) ;
goto V_65;
}
V_88 = V_93 ;
V_95 = F_84 ( V_26 -> V_34 , V_114 , 0 , V_88 , V_137 ) ;
V_9 [ 0 ] = ( T_1 ) V_114 ;
V_9 [ 1 ] = 0 ;
}
V_15 = V_138 ;
V_15 |= V_88 & V_112 ;
V_16 = V_139 ;
V_16 |= V_140 << V_141 ;
V_16 |= ( V_26 -> V_142 & V_143 ) <<
V_144 ;
F_8 ( V_95 , V_88 , V_129 ) ;
F_7 ( V_9 [ 0 ] , V_9 [ 1 ] , V_129 ) ;
F_6 ( V_15 , V_16 , V_129 ) ;
F_85 ( V_26 -> V_91 , V_129 , sizeof( * V_129 ) , & V_95 ,
& V_89 ) ;
F_86 ( V_26 -> V_126 [ V_125 ] , V_95 , sizeof( * V_129 ) , 0 ) ;
return;
V_65:
F_54 ( V_26 -> V_91 , V_129 ) ;
}
static void F_87 ( struct V_25 * V_26 )
{
T_1 V_145 [ V_127 ] = { 0 } ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_127 && V_26 -> V_126 [ V_14 ] ; V_14 ++ ) {
V_145 [ V_14 ] = V_26 -> V_146 [ V_14 ] -
F_88 ( V_26 -> V_126 [ V_14 ] ) ;
while ( V_145 [ V_14 ] -- )
F_76 ( V_26 , V_14 ) ;
}
}
static int F_89 ( struct V_147 * V_148 , int V_124 )
{
struct V_25 * V_26 = F_90 ( V_148 , struct V_25 ,
V_149 ) ;
unsigned int V_150 ;
V_150 = F_70 ( V_26 , V_124 ) ;
if ( V_150 < V_124 ) {
F_91 ( & V_26 -> V_149 ) ;
F_92 ( V_26 -> V_96 ) ;
}
F_87 ( V_26 ) ;
return V_150 ;
}
static void F_93 ( void * V_151 )
{
struct V_25 * V_26 = V_151 ;
F_94 ( V_26 -> V_96 ) ;
F_95 ( & V_26 -> V_149 ) ;
}
static void F_96 ( struct V_25 * V_26 ,
struct V_4 * V_5 ,
unsigned int V_152 )
{
struct V_4 * V_3 = V_5 ;
T_4 V_86 , V_87 ;
unsigned int V_88 ;
while ( V_3 ) {
F_1 ( & V_87 , & V_88 , & V_86 , V_3 ) ;
if ( V_87 && V_88 )
F_58 ( V_26 -> V_34 , V_87 , V_88 ,
V_137 ) ;
else
F_21 ( V_26 -> V_92 , L_22 ,
( void * ) V_87 , V_88 ) ;
F_54 ( V_26 -> V_153 , V_3 ) ;
V_3 = NULL ;
if ( V_86 ) {
V_3 = F_50 ( V_26 -> V_153 , V_86 ,
V_152 ) ;
if ( ! V_3 )
F_18 ( V_26 -> V_92 , L_23 ) ;
}
}
}
static int F_97 ( struct V_25 * V_26 ,
unsigned int V_124 )
{
struct V_4 * V_5 ;
struct V_108 * V_109 ;
unsigned int V_89 ;
T_4 V_95 ;
int V_154 = 0 ;
T_1 V_41 ;
while ( V_124 -- ) {
V_95 = F_56 ( V_26 -> V_155 , & V_89 ) ;
if ( ! V_95 )
break;
V_5 = F_50 ( V_26 -> V_153 , V_95 , V_89 ) ;
if ( F_51 ( ! V_5 ) ) {
F_18 ( V_26 -> V_92 , L_23 ) ;
V_26 -> V_28 -> V_98 . V_156 ++ ;
continue;
}
F_2 ( ( T_1 * ) & V_109 , & V_41 , V_5 ) ;
F_96 ( V_26 , V_5 , V_89 ) ;
if ( ! V_109 ) {
F_18 ( V_26 -> V_92 , L_24 ) ;
V_26 -> V_28 -> V_98 . V_156 ++ ;
continue;
}
if ( F_98 ( V_26 -> V_28 , V_109 ) &&
F_99 ( V_26 -> V_28 ) &&
( F_74 ( V_26 -> V_153 ) >
V_26 -> V_157 ) ) {
T_5 V_158 = F_100 ( V_109 ) ;
F_101 ( V_26 -> V_28 , V_158 ) ;
}
V_26 -> V_28 -> V_98 . V_159 ++ ;
V_26 -> V_28 -> V_98 . V_160 += V_109 -> V_116 ;
F_67 ( V_109 ) ;
V_154 ++ ;
}
return V_154 ;
}
static int F_102 ( struct V_147 * V_148 , int V_124 )
{
int V_150 ;
struct V_25 * V_26 = F_90 ( V_148 , struct V_25 ,
V_161 ) ;
V_150 = F_97 ( V_26 , V_124 ) ;
if ( V_150 < V_124 ) {
F_91 ( & V_26 -> V_161 ) ;
F_92 ( V_26 -> V_155 ) ;
}
return V_150 ;
}
static void F_103 ( void * V_151 )
{
struct V_25 * V_26 = V_151 ;
F_94 ( V_26 -> V_155 ) ;
F_95 ( & V_26 -> V_161 ) ;
}
static struct V_4 *
F_104 ( struct V_108 * V_109 , struct V_25 * V_26 )
{
struct V_4 * V_5 , * V_3 , * V_162 ;
unsigned int V_163 = F_105 ( V_109 ) ;
struct V_33 * V_34 = V_26 -> V_34 ;
T_4 V_164 ;
unsigned int V_89 ;
int V_14 ;
V_164 = F_82 ( V_34 , V_109 -> V_165 , V_163 , V_137 ) ;
if ( F_51 ( ! V_164 ) ) {
F_18 ( V_26 -> V_92 , L_25 ) ;
return NULL ;
}
V_5 = F_77 ( V_26 -> V_153 ) ;
if ( F_51 ( F_73 ( V_5 ) ) ) {
F_18 ( V_26 -> V_92 , L_26 ) ;
F_58 ( V_34 , V_164 , V_163 , V_137 ) ;
return NULL ;
}
F_5 ( V_164 , V_163 , 0 , V_5 ) ;
if ( F_106 ( V_109 ) ) {
F_107 ( F_64 ( V_109 ) ) ;
} else {
V_5 -> V_6 = 0 ;
goto V_166;
}
V_162 = V_5 ;
for ( V_14 = 0 ; V_14 < F_64 ( V_109 ) -> V_115 ; V_14 ++ ) {
T_6 * V_167 = & F_64 ( V_109 ) -> V_168 [ V_14 ] ;
struct V_114 * V_114 = F_108 ( V_167 ) ;
T_1 V_169 = V_167 -> V_169 ;
T_1 V_88 = F_109 ( V_167 ) ;
T_4 V_170 ;
T_1 V_16 ;
V_164 = F_84 ( V_34 , V_114 , V_169 , V_88 ,
V_137 ) ;
if ( F_51 ( ! V_164 ) ) {
F_18 ( V_26 -> V_92 , L_27 ) ;
goto V_171;
}
V_3 = F_77 ( V_26 -> V_153 ) ;
if ( F_51 ( F_73 ( V_3 ) ) ) {
F_18 ( V_26 -> V_92 , L_28 ) ;
F_52 ( V_34 , V_164 , V_88 , V_137 ) ;
goto V_171;
}
V_170 = F_110 ( V_26 -> V_153 ,
( void * ) V_3 ) ;
V_16 =
( V_26 -> V_172 & V_143 ) <<
V_144 ;
F_5 ( V_164 , V_88 , 0 , V_3 ) ;
F_9 ( & V_170 , 1 , & V_162 -> V_6 ) ;
V_163 += V_88 ;
if ( V_162 != V_5 )
F_85 ( V_26 -> V_153 , V_162 ,
sizeof( * V_162 ) , & V_170 , & V_89 ) ;
V_162 = V_3 ;
}
if ( V_162 != V_5 )
F_85 ( V_26 -> V_153 , V_162 , sizeof( * V_162 ) ,
& V_164 , & V_89 ) ;
if ( F_64 ( V_109 ) -> V_173 ) {
F_111 ( V_26 -> V_92 , L_29 ) ;
goto V_171;
}
V_166:
F_112 ( V_163 != V_109 -> V_116 ) ;
V_163 &= V_112 ;
F_9 ( & V_163 , 1 , & V_5 -> V_15 ) ;
return V_5 ;
V_171:
F_96 ( V_26 , V_5 , sizeof( * V_5 ) ) ;
return NULL ;
}
static int F_113 ( struct V_25 * V_26 ,
struct V_108 * V_109 ,
struct V_4 * V_5 )
{
struct V_174 * V_175 = NULL ;
struct V_75 * V_176 ;
struct V_106 V_107 ;
T_1 V_17 = 0 ;
unsigned int V_89 ;
T_4 V_95 ;
int V_27 = 0 ;
V_107 . V_26 = V_26 ;
V_107 . V_109 = V_109 ;
V_107 . V_175 = NULL ;
V_107 . V_177 = 0 ;
V_107 . V_178 = NULL ;
V_107 . V_179 = NULL ;
V_107 . V_180 = V_5 -> V_180 ;
V_107 . V_181 = V_5 -> V_181 ;
memset ( V_107 . V_180 , 0 , V_182 * sizeof( T_1 ) ) ;
F_27 (tx_hook, &netcp->txhook_list_head, list) {
V_27 = V_176 -> V_73 ( V_176 -> V_72 , V_176 -> V_74 ,
& V_107 ) ;
if ( F_51 ( V_27 != 0 ) ) {
F_18 ( V_26 -> V_92 , L_30 ,
V_176 -> V_72 , V_27 ) ;
V_27 = ( V_27 < 0 ) ? V_27 : V_183 ;
goto V_184;
}
}
V_175 = V_107 . V_175 ;
if ( ! V_175 ) {
F_18 ( V_26 -> V_92 , L_31 ) ;
V_27 = - V_185 ;
goto V_184;
}
if ( V_107 . V_177 ) {
T_1 * V_181 = V_107 . V_181 ;
memmove ( V_107 . V_181 , V_107 . V_181 + V_107 . V_177 ,
V_107 . V_177 ) ;
F_9 ( V_181 , V_107 . V_177 , V_181 ) ;
V_17 |=
( V_107 . V_177 & V_186 ) <<
V_141 ;
}
V_17 |= V_139 |
( ( V_26 -> V_172 & V_143 ) <<
V_144 ) |
( ( V_175 -> V_187 & V_188 ) <<
V_189 ) ;
F_9 ( & V_17 , 1 , & V_5 -> V_17 ) ;
F_9 ( ( T_1 * ) & V_109 , 1 , & V_5 -> V_9 [ 0 ] ) ;
V_27 = F_85 ( V_26 -> V_153 , V_5 , sizeof( * V_5 ) , & V_95 ,
& V_89 ) ;
if ( F_51 ( V_27 ) ) {
F_18 ( V_26 -> V_92 , L_32 , V_97 ) ;
V_27 = - V_45 ;
goto V_184;
}
F_114 ( V_109 ) ;
F_86 ( V_175 -> V_190 , V_95 , V_89 , 0 ) ;
V_184:
return V_27 ;
}
static int F_115 ( struct V_108 * V_109 , struct V_191 * V_28 )
{
struct V_25 * V_26 = F_116 ( V_28 ) ;
int V_158 = F_100 ( V_109 ) ;
struct V_4 * V_5 ;
int V_192 , V_27 = 0 ;
if ( F_51 ( V_109 -> V_116 <= 0 ) ) {
F_67 ( V_109 ) ;
return V_183 ;
}
if ( F_51 ( V_109 -> V_116 < V_193 ) ) {
V_27 = F_117 ( V_109 , V_193 ) ;
if ( V_27 < 0 ) {
F_21 ( V_26 -> V_92 , L_33 ,
V_27 ) ;
V_28 -> V_98 . V_194 ++ ;
return V_27 ;
}
V_109 -> V_116 = V_193 ;
}
V_5 = F_104 ( V_109 , V_26 ) ;
if ( F_51 ( ! V_5 ) ) {
F_118 ( V_28 , V_158 ) ;
V_27 = - V_195 ;
goto V_196;
}
V_27 = F_113 ( V_26 , V_109 , V_5 ) ;
if ( V_27 )
goto V_196;
V_28 -> V_197 = V_120 ;
V_192 = F_74 ( V_26 -> V_153 ) ;
if ( V_192 < V_26 -> V_198 ) {
F_29 ( V_26 -> V_92 , L_34 , V_192 ) ;
F_118 ( V_28 , V_158 ) ;
}
return V_183 ;
V_196:
V_28 -> V_98 . V_194 ++ ;
if ( V_5 )
F_96 ( V_26 , V_5 , sizeof( * V_5 ) ) ;
F_67 ( V_109 ) ;
return V_27 ;
}
int F_119 ( struct V_174 * V_175 )
{
if ( V_175 -> V_199 ) {
F_120 ( V_175 -> V_199 ) ;
V_175 -> V_199 = NULL ;
}
return 0 ;
}
int F_121 ( struct V_174 * V_175 )
{
struct V_33 * V_34 = V_175 -> V_30 -> V_33 ;
struct V_200 V_201 ;
int V_27 = 0 ;
T_7 V_24 [ 16 ] ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_202 = V_203 ;
V_201 . V_204 . V_205 . V_206 = false ;
V_201 . V_204 . V_205 . V_207 = false ;
V_201 . V_204 . V_205 . V_208 = V_209 ;
V_175 -> V_199 = F_122 ( V_34 ,
V_175 -> V_210 , & V_201 ) ;
if ( F_73 ( V_175 -> V_199 ) ) {
F_18 ( V_34 , L_35 ,
V_175 -> V_210 ) ;
goto V_211;
}
snprintf ( V_24 , sizeof( V_24 ) , L_36 , F_123 ( V_34 ) ) ;
V_175 -> V_190 = F_124 ( V_24 , V_175 -> V_212 ,
V_213 ) ;
if ( F_125 ( V_175 -> V_190 ) ) {
F_18 ( V_34 , L_37 ,
V_24 , V_27 ) ;
V_27 = F_126 ( V_175 -> V_190 ) ;
goto V_211;
}
F_29 ( V_34 , L_38 , V_24 ) ;
return 0 ;
V_211:
if ( ! F_73 ( V_175 -> V_199 ) )
F_120 ( V_175 -> V_199 ) ;
V_175 -> V_199 = NULL ;
return V_27 ;
}
int F_127 ( struct V_174 * V_175 ,
struct V_30 * V_30 ,
const char * V_210 , unsigned int V_212 )
{
memset ( V_175 , 0 , sizeof( * V_175 ) ) ;
V_175 -> V_30 = V_30 ;
V_175 -> V_210 = V_210 ;
V_175 -> V_212 = V_212 ;
return 0 ;
}
static struct V_214 * F_128 ( struct V_25 * V_26 ,
const T_7 * V_215 ,
enum V_216 type )
{
struct V_214 * V_217 ;
F_27 (naddr, &netcp->addr_list, node) {
if ( V_217 -> type != type )
continue;
if ( V_215 && memcmp ( V_215 , V_217 -> V_215 , V_218 ) )
continue;
return V_217 ;
}
return NULL ;
}
static struct V_214 * F_129 ( struct V_25 * V_26 ,
const T_7 * V_215 ,
enum V_216 type )
{
struct V_214 * V_217 ;
V_217 = F_130 ( V_26 -> V_34 , sizeof( * V_217 ) , V_134 ) ;
if ( ! V_217 )
return NULL ;
V_217 -> type = type ;
V_217 -> V_78 = 0 ;
V_217 -> V_26 = V_26 ;
if ( V_215 )
F_131 ( V_217 -> V_215 , V_215 ) ;
else
memset ( V_217 -> V_215 , 0 , V_218 ) ;
F_23 ( & V_217 -> V_23 , & V_26 -> V_219 ) ;
return V_217 ;
}
static void F_132 ( struct V_25 * V_26 , struct V_214 * V_217 )
{
F_24 ( & V_217 -> V_23 ) ;
F_25 ( V_26 -> V_34 , V_217 ) ;
}
static void F_133 ( struct V_25 * V_26 )
{
struct V_214 * V_217 ;
F_27 (naddr, &netcp->addr_list, node)
V_217 -> V_78 = 0 ;
}
static void F_134 ( struct V_25 * V_26 , const T_7 * V_215 ,
enum V_216 type )
{
struct V_214 * V_217 ;
V_217 = F_128 ( V_26 , V_215 , type ) ;
if ( V_217 ) {
V_217 -> V_78 |= V_220 ;
return;
}
V_217 = F_129 ( V_26 , V_215 , type ) ;
if ( ! F_112 ( ! V_217 ) )
V_217 -> V_78 |= V_221 ;
}
static void F_135 ( struct V_25 * V_26 )
{
struct V_214 * V_217 , * V_41 ;
struct V_52 * V_222 ;
struct V_31 * V_32 ;
int error ;
F_36 (naddr, tmp, &netcp->addr_list, node) {
if ( V_217 -> V_78 & ( V_220 | V_221 ) )
continue;
F_29 ( V_26 -> V_92 , L_39 ,
V_217 -> V_215 , V_217 -> type ) ;
F_32 ( & V_61 ) ;
F_136 (netcp, priv) {
V_32 = V_222 -> V_31 ;
if ( ! V_32 -> V_223 )
continue;
error = V_32 -> V_223 ( V_222 -> V_49 ,
V_217 ) ;
F_112 ( error ) ;
}
F_33 ( & V_61 ) ;
F_132 ( V_26 , V_217 ) ;
}
}
static void F_137 ( struct V_25 * V_26 )
{
struct V_214 * V_217 , * V_41 ;
struct V_52 * V_222 ;
struct V_31 * V_32 ;
int error ;
F_36 (naddr, tmp, &netcp->addr_list, node) {
if ( ! ( V_217 -> V_78 & V_221 ) )
continue;
F_29 ( V_26 -> V_92 , L_40 ,
V_217 -> V_215 , V_217 -> type ) ;
F_32 ( & V_61 ) ;
F_136 (netcp, priv) {
V_32 = V_222 -> V_31 ;
if ( ! V_32 -> V_224 )
continue;
error = V_32 -> V_224 ( V_222 -> V_49 , V_217 ) ;
F_112 ( error ) ;
}
F_33 ( & V_61 ) ;
}
}
static void F_138 ( struct V_191 * V_28 )
{
struct V_25 * V_26 = F_116 ( V_28 ) ;
struct V_225 * V_226 ;
bool V_227 ;
V_227 = ( V_28 -> V_78 & V_228 ||
V_28 -> V_78 & V_229 ||
F_139 ( V_28 ) > V_230 ) ;
F_133 ( V_26 ) ;
F_134 ( V_26 , V_28 -> V_231 , V_232 ) ;
F_140 (ndev, ndev_addr)
F_134 ( V_26 , V_226 -> V_215 , V_233 ) ;
F_141 (ndev_addr, ndev)
F_134 ( V_26 , V_226 -> V_215 , V_234 ) ;
F_142 (ndev_addr, ndev)
F_134 ( V_26 , V_226 -> V_215 , V_235 ) ;
if ( V_227 )
F_134 ( V_26 , NULL , V_236 ) ;
F_135 ( V_26 ) ;
F_137 ( V_26 ) ;
}
static void F_143 ( struct V_25 * V_26 )
{
int V_14 ;
if ( V_26 -> V_237 ) {
F_120 ( V_26 -> V_237 ) ;
V_26 -> V_237 = NULL ;
}
if ( ! F_73 ( V_26 -> V_91 ) )
F_72 ( V_26 ) ;
if ( ! F_73 ( V_26 -> V_96 ) ) {
F_144 ( V_26 -> V_96 ) ;
V_26 -> V_96 = NULL ;
}
for ( V_14 = 0 ; V_14 < V_127 &&
! F_73 ( V_26 -> V_126 [ V_14 ] ) ; ++ V_14 ) {
F_144 ( V_26 -> V_126 [ V_14 ] ) ;
V_26 -> V_126 [ V_14 ] = NULL ;
}
if ( ! F_73 ( V_26 -> V_155 ) ) {
F_144 ( V_26 -> V_155 ) ;
V_26 -> V_155 = NULL ;
}
if ( ! F_73 ( V_26 -> V_153 ) ) {
F_75 ( V_26 -> V_153 ) ;
V_26 -> V_153 = NULL ;
}
}
static int F_145 ( struct V_191 * V_28 )
{
struct V_25 * V_26 = F_116 ( V_28 ) ;
struct V_238 V_239 ;
struct V_200 V_201 ;
T_1 V_240 = 0 ;
T_7 V_24 [ 16 ] ;
int V_27 ;
int V_14 ;
snprintf ( V_24 , sizeof( V_24 ) , L_41 , V_28 -> V_24 ) ;
V_26 -> V_91 = F_146 ( V_24 , V_26 -> V_128 ,
V_26 -> V_241 ) ;
if ( F_73 ( V_26 -> V_91 ) ) {
F_18 ( V_26 -> V_92 , L_42 ) ;
V_27 = F_126 ( V_26 -> V_91 ) ;
goto V_65;
}
snprintf ( V_24 , sizeof( V_24 ) , L_43 , V_28 -> V_24 ) ;
V_26 -> V_153 = F_146 ( V_24 , V_26 -> V_242 ,
V_26 -> V_243 ) ;
if ( F_73 ( V_26 -> V_153 ) ) {
F_18 ( V_26 -> V_92 , L_44 ) ;
V_27 = F_126 ( V_26 -> V_153 ) ;
goto V_65;
}
snprintf ( V_24 , sizeof( V_24 ) , L_45 , V_28 -> V_24 ) ;
V_26 -> V_155 = F_124 ( V_24 , V_26 -> V_172 , 0 ) ;
if ( F_73 ( V_26 -> V_155 ) ) {
V_27 = F_126 ( V_26 -> V_155 ) ;
goto V_65;
}
V_26 -> V_172 = F_147 ( V_26 -> V_155 ) ;
V_239 . V_244 = F_103 ;
V_239 . V_245 = V_26 ;
V_27 = F_148 ( V_26 -> V_155 ,
V_246 ,
( unsigned long ) & V_239 ) ;
if ( V_27 )
goto V_65;
F_94 ( V_26 -> V_155 ) ;
snprintf ( V_24 , sizeof( V_24 ) , L_46 , V_28 -> V_24 ) ;
V_26 -> V_96 = F_124 ( V_24 , V_26 -> V_142 , 0 ) ;
if ( F_73 ( V_26 -> V_96 ) ) {
V_27 = F_126 ( V_26 -> V_96 ) ;
goto V_65;
}
V_26 -> V_142 = F_147 ( V_26 -> V_96 ) ;
V_239 . V_244 = F_93 ;
V_239 . V_245 = V_26 ;
V_27 = F_148 ( V_26 -> V_96 ,
V_246 ,
( unsigned long ) & V_239 ) ;
if ( V_27 )
goto V_65;
F_94 ( V_26 -> V_96 ) ;
for ( V_14 = 0 ; V_14 < V_127 &&
V_26 -> V_146 [ V_14 ] && V_26 -> V_132 [ V_14 ] ; ++ V_14 ) {
snprintf ( V_24 , sizeof( V_24 ) , L_47 , V_28 -> V_24 , V_14 ) ;
V_26 -> V_126 [ V_14 ] = F_124 ( V_24 , V_247 , 0 ) ;
if ( F_73 ( V_26 -> V_126 [ V_14 ] ) ) {
V_27 = F_126 ( V_26 -> V_126 [ V_14 ] ) ;
goto V_65;
}
}
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_202 = V_248 ;
V_201 . V_204 . V_249 . V_250 = true ;
V_201 . V_204 . V_249 . V_251 = true ;
V_201 . V_204 . V_249 . V_252 = V_253 ;
V_201 . V_204 . V_249 . V_254 = V_255 ;
V_201 . V_204 . V_249 . V_256 = false ;
V_201 . V_204 . V_249 . V_257 = V_113 ;
V_201 . V_204 . V_249 . V_258 = V_26 -> V_142 ;
V_201 . V_204 . V_249 . V_259 = V_260 ;
for ( V_14 = 0 ; V_14 < V_127 ; ++ V_14 ) {
if ( V_26 -> V_126 [ V_14 ] )
V_240 = F_147 ( V_26 -> V_126 [ V_14 ] ) ;
V_201 . V_204 . V_249 . V_125 [ V_14 ] = V_240 ;
}
V_26 -> V_237 = F_122 ( V_26 -> V_30 -> V_33 ,
V_26 -> V_210 , & V_201 ) ;
if ( F_73 ( V_26 -> V_237 ) ) {
F_18 ( V_26 -> V_92 , L_48 ,
V_26 -> V_210 ) ;
goto V_65;
}
F_29 ( V_26 -> V_92 , L_49 , V_26 -> V_237 ) ;
return 0 ;
V_65:
F_143 ( V_26 ) ;
return V_27 ;
}
static int F_149 ( struct V_191 * V_28 )
{
struct V_25 * V_26 = F_116 ( V_28 ) ;
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
if ( V_32 -> V_261 ) {
V_27 = V_32 -> V_261 ( V_53 -> V_49 , V_28 ) ;
if ( V_27 != 0 ) {
F_18 ( V_26 -> V_92 , L_51 ) ;
goto V_262;
}
}
}
F_33 ( & V_61 ) ;
F_87 ( V_26 ) ;
F_151 ( & V_26 -> V_149 ) ;
F_151 ( & V_26 -> V_161 ) ;
F_92 ( V_26 -> V_155 ) ;
F_92 ( V_26 -> V_96 ) ;
F_152 ( V_28 ) ;
F_29 ( V_26 -> V_92 , L_52 , V_28 -> V_24 ) ;
return 0 ;
V_262:
F_136 (netcp, intf_modpriv) {
V_32 = V_53 -> V_31 ;
if ( V_32 -> V_263 )
V_32 -> V_263 ( V_53 -> V_49 , V_28 ) ;
}
F_33 ( & V_61 ) ;
V_65:
F_143 ( V_26 ) ;
return V_27 ;
}
static int F_153 ( struct V_191 * V_28 )
{
struct V_25 * V_26 = F_116 ( V_28 ) ;
struct V_52 * V_53 ;
struct V_31 * V_32 ;
int V_211 = 0 ;
F_154 ( V_28 ) ;
F_150 ( V_28 ) ;
F_133 ( V_26 ) ;
F_135 ( V_26 ) ;
F_94 ( V_26 -> V_96 ) ;
F_94 ( V_26 -> V_155 ) ;
F_155 ( & V_26 -> V_149 ) ;
F_155 ( & V_26 -> V_161 ) ;
F_32 ( & V_61 ) ;
F_136 (netcp, intf_modpriv) {
V_32 = V_53 -> V_31 ;
if ( V_32 -> V_263 ) {
V_211 = V_32 -> V_263 ( V_53 -> V_49 , V_28 ) ;
if ( V_211 != 0 )
F_18 ( V_26 -> V_92 , L_53 ) ;
}
}
F_33 ( & V_61 ) ;
F_55 ( V_26 ) ;
F_97 ( V_26 , V_26 -> V_242 ) ;
if ( F_74 ( V_26 -> V_153 ) != V_26 -> V_242 )
F_18 ( V_26 -> V_92 , L_54 ,
V_26 -> V_242 - F_74 ( V_26 -> V_153 ) ) ;
F_143 ( V_26 ) ;
F_29 ( V_26 -> V_92 , L_55 , V_28 -> V_24 ) ;
return 0 ;
}
static int F_156 ( struct V_191 * V_28 ,
struct V_264 * V_265 , int V_266 )
{
struct V_25 * V_26 = F_116 ( V_28 ) ;
struct V_52 * V_53 ;
struct V_31 * V_32 ;
int V_27 = - 1 , V_211 = - V_267 ;
if ( ! F_99 ( V_28 ) )
return - V_60 ;
F_32 ( & V_61 ) ;
F_136 (netcp, intf_modpriv) {
V_32 = V_53 -> V_31 ;
if ( ! V_32 -> V_268 )
continue;
V_211 = V_32 -> V_268 ( V_53 -> V_49 , V_265 , V_266 ) ;
if ( ( V_211 < 0 ) && ( V_211 != - V_267 ) ) {
V_27 = V_211 ;
goto V_184;
}
if ( V_211 == 0 )
V_27 = V_211 ;
}
V_184:
F_33 ( & V_61 ) ;
return ( V_27 == 0 ) ? 0 : V_211 ;
}
static int F_157 ( struct V_191 * V_28 , int V_269 )
{
struct V_25 * V_26 = F_116 ( V_28 ) ;
if ( ( V_269 < 68 ) ||
( V_269 > ( V_270 - V_271 - V_117 ) ) ) {
F_18 ( V_26 -> V_92 , L_56 , V_269 ) ;
return - V_60 ;
}
V_28 -> V_272 = V_269 ;
return 0 ;
}
static void F_158 ( struct V_191 * V_28 )
{
struct V_25 * V_26 = F_116 ( V_28 ) ;
unsigned int V_273 = F_74 ( V_26 -> V_153 ) ;
F_18 ( V_26 -> V_92 , L_57 , V_273 ) ;
F_97 ( V_26 , V_26 -> V_242 ) ;
V_28 -> V_197 = V_120 ;
F_152 ( V_28 ) ;
}
static int F_159 ( struct V_191 * V_28 , T_8 V_274 , T_5 V_275 )
{
struct V_25 * V_26 = F_116 ( V_28 ) ;
struct V_52 * V_53 ;
struct V_31 * V_32 ;
int V_211 = 0 ;
F_29 ( V_26 -> V_92 , L_58 , V_275 ) ;
F_32 ( & V_61 ) ;
F_136 (netcp, intf_modpriv) {
V_32 = V_53 -> V_31 ;
if ( ( V_32 -> V_276 ) && ( V_275 != 0 ) ) {
V_211 = V_32 -> V_276 ( V_53 -> V_49 , V_275 ) ;
if ( V_211 != 0 ) {
F_18 ( V_26 -> V_92 , L_59 ,
V_275 ) ;
break;
}
}
}
F_33 ( & V_61 ) ;
return V_211 ;
}
static int F_160 ( struct V_191 * V_28 , T_8 V_274 , T_5 V_275 )
{
struct V_25 * V_26 = F_116 ( V_28 ) ;
struct V_52 * V_53 ;
struct V_31 * V_32 ;
int V_211 = 0 ;
F_29 ( V_26 -> V_92 , L_60 , V_275 ) ;
F_32 ( & V_61 ) ;
F_136 (netcp, intf_modpriv) {
V_32 = V_53 -> V_31 ;
if ( V_32 -> V_277 ) {
V_211 = V_32 -> V_277 ( V_53 -> V_49 , V_275 ) ;
if ( V_211 != 0 ) {
F_18 ( V_26 -> V_92 , L_61 ,
V_275 ) ;
break;
}
}
}
F_33 ( & V_61 ) ;
return V_211 ;
}
static T_5 F_161 ( struct V_191 * V_34 , struct V_108 * V_109 ,
void * V_278 ,
T_9 V_279 )
{
return 0 ;
}
static int F_162 ( struct V_191 * V_34 , T_7 V_280 )
{
int V_14 ;
F_163 () ;
if ( ( V_34 -> V_281 <= 1 ) ||
( V_34 -> V_281 < V_280 ) )
return - V_60 ;
if ( V_280 ) {
F_164 ( V_34 , V_280 ) ;
for ( V_14 = 0 ; V_14 < V_280 ; V_14 ++ )
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
T_10 V_282 ;
struct V_283 V_284 ;
void T_2 * V_285 = NULL ;
T_1 V_19 = 0 ;
const void * V_286 ;
T_7 V_287 [ 6 ] ;
T_1 V_288 [ 2 ] ;
int V_27 = 0 ;
V_28 = F_168 ( sizeof( * V_26 ) , 1 , 1 ) ;
if ( ! V_28 ) {
F_18 ( V_34 , L_62 ) ;
return - V_45 ;
}
V_28 -> V_289 |= V_290 ;
V_28 -> V_289 |= V_291 ;
V_28 -> V_292 = V_28 -> V_289 ;
V_28 -> V_293 |= V_290 ;
V_26 = F_116 ( V_28 ) ;
F_169 ( & V_26 -> V_79 ) ;
F_170 ( & V_26 -> V_58 ) ;
F_170 ( & V_26 -> V_294 ) ;
F_170 ( & V_26 -> V_295 ) ;
F_170 ( & V_26 -> V_219 ) ;
V_26 -> V_30 = V_30 ;
V_26 -> V_34 = V_30 -> V_33 ;
V_26 -> V_28 = V_28 ;
V_26 -> V_92 = & V_28 -> V_34 ;
V_26 -> V_296 = F_171 ( V_297 , V_298 ) ;
V_26 -> V_198 = V_299 ;
V_26 -> V_157 = V_26 -> V_198 ;
V_26 -> V_55 = V_55 ;
V_27 = F_172 ( V_55 , L_63 , & V_19 ) ;
if ( V_19 ) {
if ( F_173 ( V_23 , V_300 , & V_284 ) ) {
F_18 ( V_34 , L_64 ) ;
V_27 = - V_54 ;
goto V_301;
}
V_282 = F_174 ( & V_284 ) ;
if ( ! F_175 ( V_34 , V_284 . V_302 , V_282 ,
F_123 ( V_34 ) ) ) {
F_18 ( V_34 , L_65 ) ;
V_27 = - V_45 ;
goto V_301;
}
V_285 = F_176 ( V_34 , V_284 . V_302 , V_282 ) ;
if ( ! V_285 ) {
F_18 ( V_34 , L_66 ) ;
F_177 ( V_34 , V_284 . V_302 , V_282 ) ;
V_27 = - V_45 ;
goto V_301;
}
F_10 ( V_287 , V_285 ) ;
if ( F_178 ( V_287 ) )
F_131 ( V_28 -> V_303 , V_287 ) ;
else
F_179 ( V_28 -> V_303 ) ;
F_180 ( V_34 , V_285 ) ;
F_177 ( V_34 , V_284 . V_302 , V_282 ) ;
} else {
V_286 = F_181 ( V_55 ) ;
if ( V_286 )
F_131 ( V_28 -> V_303 , V_286 ) ;
else
F_179 ( V_28 -> V_303 ) ;
}
V_27 = F_13 ( V_55 , L_67 ,
& V_26 -> V_210 ) ;
if ( V_27 < 0 ) {
F_18 ( V_34 , L_68 ) ;
V_27 = - V_54 ;
goto V_301;
}
V_27 = F_172 ( V_55 , L_69 ,
& V_26 -> V_142 ) ;
if ( V_27 < 0 ) {
F_21 ( V_34 , L_70 ) ;
V_26 -> V_142 = V_304 ;
}
V_27 = F_182 ( V_55 , L_71 ,
V_26 -> V_146 ,
V_127 ) ;
if ( V_27 < 0 ) {
F_18 ( V_34 , L_72 ) ;
V_26 -> V_146 [ 0 ] = 128 ;
}
V_27 = F_182 ( V_55 , L_73 ,
V_26 -> V_132 ,
V_127 ) ;
if ( V_27 ) {
F_18 ( V_34 , L_74 ) ;
V_26 -> V_132 [ 0 ] = 1536 ;
}
V_27 = F_182 ( V_55 , L_75 , V_288 , 2 ) ;
if ( V_27 < 0 ) {
F_18 ( V_34 , L_76 ) ;
V_27 = - V_54 ;
goto V_301;
}
V_26 -> V_128 = V_288 [ 0 ] ;
V_26 -> V_241 = V_288 [ 1 ] ;
V_27 = F_182 ( V_55 , L_77 , V_288 , 2 ) ;
if ( V_27 < 0 ) {
F_18 ( V_34 , L_78 ) ;
V_27 = - V_54 ;
goto V_301;
}
V_26 -> V_242 = V_288 [ 0 ] ;
V_26 -> V_243 = V_288 [ 1 ] ;
if ( V_26 -> V_242 < V_299 ) {
F_18 ( V_34 , L_79 ,
V_299 ) ;
V_27 = - V_54 ;
goto V_301;
}
V_27 = F_172 ( V_55 , L_80 ,
& V_26 -> V_172 ) ;
if ( V_27 < 0 ) {
F_21 ( V_34 , L_81 ) ;
V_26 -> V_172 = V_304 ;
}
F_183 ( V_28 , & V_26 -> V_149 , F_89 , V_305 ) ;
F_183 ( V_28 , & V_26 -> V_161 , F_102 , V_305 ) ;
V_28 -> V_306 = 0 ;
V_28 -> V_307 = V_308 ;
V_28 -> V_309 = & V_310 ;
F_184 ( V_28 , V_34 ) ;
F_23 ( & V_26 -> V_311 , & V_30 -> V_312 ) ;
return 0 ;
V_301:
F_185 ( V_28 ) ;
return V_27 ;
}
static void F_186 ( struct V_30 * V_30 ,
struct V_191 * V_28 )
{
struct V_52 * V_53 , * V_41 ;
struct V_25 * V_26 = F_116 ( V_28 ) ;
struct V_31 * V_32 ;
F_29 ( V_30 -> V_33 , L_82 ,
V_28 -> V_24 ) ;
F_36 (intf_modpriv, tmp, &netcp->module_head,
intf_list) {
V_32 = V_53 -> V_31 ;
F_29 ( V_30 -> V_33 , L_83 ,
V_32 -> V_24 ) ;
if ( V_32 -> V_69 )
V_32 -> V_69 ( V_53 -> V_49 ) ;
F_24 ( & V_53 -> V_57 ) ;
F_48 ( V_53 ) ;
}
F_31 ( ! F_187 ( & V_26 -> V_58 ) , L_84 ,
V_28 -> V_24 ) ;
F_24 ( & V_26 -> V_311 ) ;
F_20 ( V_26 -> V_55 ) ;
F_188 ( V_28 ) ;
F_189 ( & V_26 -> V_149 ) ;
F_185 ( V_28 ) ;
}
static int F_190 ( struct V_313 * V_314 )
{
struct V_22 * V_23 = V_314 -> V_34 . V_37 ;
struct V_25 * V_25 , * V_67 ;
struct V_22 * V_38 , * V_315 ;
struct V_30 * V_30 ;
struct V_33 * V_34 = & V_314 -> V_34 ;
struct V_31 * V_32 ;
int V_27 ;
if ( ! V_23 ) {
F_18 ( V_34 , L_85 ) ;
return - V_54 ;
}
V_30 = F_22 ( V_34 , sizeof( * V_30 ) , V_44 ) ;
if ( ! V_30 )
return - V_45 ;
F_191 ( & V_314 -> V_34 ) ;
V_27 = F_192 ( & V_314 -> V_34 ) ;
if ( V_27 < 0 ) {
F_18 ( V_34 , L_86 ) ;
F_193 ( & V_314 -> V_34 ) ;
return V_27 ;
}
F_170 ( & V_30 -> V_312 ) ;
F_170 ( & V_30 -> V_47 ) ;
V_30 -> V_33 = V_34 ;
F_194 ( V_314 , V_30 ) ;
V_315 = F_17 ( V_23 , L_87 ) ;
if ( ! V_315 ) {
F_18 ( V_34 , L_88 ) ;
V_27 = - V_54 ;
goto V_316;
}
F_19 (interfaces, child) {
V_27 = F_167 ( V_30 , V_38 ) ;
if ( V_27 ) {
F_18 ( V_34 , L_89 ,
V_38 -> V_24 ) ;
goto V_317;
}
}
F_23 ( & V_30 -> V_318 , & V_319 ) ;
F_32 ( & V_61 ) ;
F_26 (module) {
V_27 = F_16 ( V_30 , V_32 ) ;
if ( V_27 < 0 )
F_18 ( V_34 , L_90 , V_32 -> V_24 ) ;
}
F_33 ( & V_61 ) ;
return 0 ;
V_317:
F_36 (netcp_intf, netcp_tmp,
&netcp_device->interface_head,
interface_list) {
F_186 ( V_30 , V_25 -> V_28 ) ;
}
V_316:
F_195 ( & V_314 -> V_34 ) ;
F_193 ( & V_314 -> V_34 ) ;
F_194 ( V_314 , NULL ) ;
return V_27 ;
}
static int F_196 ( struct V_313 * V_314 )
{
struct V_30 * V_30 = F_197 ( V_314 ) ;
struct V_39 * V_40 , * V_41 ;
struct V_31 * V_32 ;
F_36 (inst_modpriv, tmp, &netcp_device->modpriv_head,
inst_list) {
V_32 = V_40 -> V_31 ;
F_29 ( & V_314 -> V_34 , L_91 , V_32 -> V_24 ) ;
V_32 -> remove ( V_30 , V_40 -> V_49 ) ;
F_24 ( & V_40 -> V_46 ) ;
F_48 ( V_40 ) ;
}
F_31 ( ! F_187 ( & V_30 -> V_312 ) , L_92 ,
V_314 -> V_24 ) ;
F_25 ( & V_314 -> V_34 , V_30 ) ;
F_195 ( & V_314 -> V_34 ) ;
F_193 ( & V_314 -> V_34 ) ;
F_194 ( V_314 , NULL ) ;
return 0 ;
}
