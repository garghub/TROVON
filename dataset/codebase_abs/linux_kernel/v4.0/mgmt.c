static T_1 F_1 ( T_1 V_1 )
{
if ( V_1 < F_2 ( V_2 ) )
return V_2 [ V_1 ] ;
return V_3 ;
}
static int F_3 ( T_2 V_4 , struct V_5 * V_6 , void * V_7 , T_2 V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_12 = F_4 ( sizeof( * V_14 ) + V_8 , V_15 ) ;
if ( ! V_12 )
return - V_16 ;
V_14 = ( void * ) F_5 ( V_12 , sizeof( * V_14 ) ) ;
V_14 -> V_17 = F_6 ( V_4 ) ;
if ( V_6 )
V_14 -> V_18 = F_6 ( V_6 -> V_19 ) ;
else
V_14 -> V_18 = F_6 ( V_20 ) ;
V_14 -> V_21 = F_6 ( V_8 ) ;
if ( V_7 )
memcpy ( F_5 ( V_12 , V_8 ) , V_7 , V_8 ) ;
F_7 ( V_12 ) ;
F_8 ( V_12 , V_10 ) ;
F_9 ( V_12 ) ;
return 0 ;
}
static int F_10 ( struct V_9 * V_22 , T_2 V_18 , T_2 V_23 , T_1 V_24 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_25 * V_26 ;
int V_27 ;
F_11 ( L_1 , V_22 , V_18 , V_23 , V_24 ) ;
V_12 = F_4 ( sizeof( * V_14 ) + sizeof( * V_26 ) , V_15 ) ;
if ( ! V_12 )
return - V_16 ;
V_14 = ( void * ) F_5 ( V_12 , sizeof( * V_14 ) ) ;
V_14 -> V_17 = F_6 ( V_28 ) ;
V_14 -> V_18 = F_6 ( V_18 ) ;
V_14 -> V_21 = F_6 ( sizeof( * V_26 ) ) ;
V_26 = ( void * ) F_5 ( V_12 , sizeof( * V_26 ) ) ;
V_26 -> V_24 = V_24 ;
V_26 -> V_17 = F_6 ( V_23 ) ;
V_27 = F_12 ( V_22 , V_12 ) ;
if ( V_27 < 0 )
F_9 ( V_12 ) ;
return V_27 ;
}
static int F_13 ( struct V_9 * V_22 , T_2 V_18 , T_2 V_23 , T_1 V_24 ,
void * V_29 , T_3 V_30 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_31 * V_26 ;
int V_27 ;
F_11 ( L_2 , V_22 ) ;
V_12 = F_4 ( sizeof( * V_14 ) + sizeof( * V_26 ) + V_30 , V_15 ) ;
if ( ! V_12 )
return - V_16 ;
V_14 = ( void * ) F_5 ( V_12 , sizeof( * V_14 ) ) ;
V_14 -> V_17 = F_6 ( V_32 ) ;
V_14 -> V_18 = F_6 ( V_18 ) ;
V_14 -> V_21 = F_6 ( sizeof( * V_26 ) + V_30 ) ;
V_26 = ( void * ) F_5 ( V_12 , sizeof( * V_26 ) + V_30 ) ;
V_26 -> V_17 = F_6 ( V_23 ) ;
V_26 -> V_24 = V_24 ;
if ( V_29 )
memcpy ( V_26 -> V_7 , V_29 , V_30 ) ;
V_27 = F_12 ( V_22 , V_12 ) ;
if ( V_27 < 0 )
F_9 ( V_12 ) ;
return V_27 ;
}
static int F_14 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_33 V_29 ;
F_11 ( L_2 , V_22 ) ;
V_29 . V_34 = V_35 ;
V_29 . V_36 = F_6 ( V_37 ) ;
return F_13 ( V_22 , V_20 , V_38 , 0 , & V_29 ,
sizeof( V_29 ) ) ;
}
static int F_15 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_39 * V_29 ;
const T_2 V_40 = F_2 ( V_41 ) ;
const T_2 V_42 = F_2 ( V_43 ) ;
T_4 * V_17 ;
T_3 V_44 ;
int V_45 , V_27 ;
F_11 ( L_2 , V_22 ) ;
V_44 = sizeof( * V_29 ) + ( ( V_40 + V_42 ) * sizeof( T_2 ) ) ;
V_29 = F_16 ( V_44 , V_15 ) ;
if ( ! V_29 )
return - V_16 ;
V_29 -> V_40 = F_6 ( V_40 ) ;
V_29 -> V_42 = F_6 ( V_42 ) ;
for ( V_45 = 0 , V_17 = V_29 -> V_46 ; V_45 < V_40 ; V_45 ++ , V_17 ++ )
F_17 ( V_41 [ V_45 ] , V_17 ) ;
for ( V_45 = 0 ; V_45 < V_42 ; V_45 ++ , V_17 ++ )
F_17 ( V_43 [ V_45 ] , V_17 ) ;
V_27 = F_13 ( V_22 , V_20 , V_47 , 0 , V_29 ,
V_44 ) ;
F_18 ( V_29 ) ;
return V_27 ;
}
static int F_19 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_48 * V_29 ;
struct V_5 * V_49 ;
T_3 V_30 ;
T_2 V_50 ;
int V_27 ;
F_11 ( L_2 , V_22 ) ;
F_20 ( & V_51 ) ;
V_50 = 0 ;
F_21 (d, &hci_dev_list, list) {
if ( V_49 -> V_52 == V_53 &&
! F_22 ( V_54 , & V_49 -> V_55 ) )
V_50 ++ ;
}
V_30 = sizeof( * V_29 ) + ( 2 * V_50 ) ;
V_29 = F_16 ( V_30 , V_56 ) ;
if ( ! V_29 ) {
F_23 ( & V_51 ) ;
return - V_16 ;
}
V_50 = 0 ;
F_21 (d, &hci_dev_list, list) {
if ( F_22 ( V_57 , & V_49 -> V_55 ) ||
F_22 ( V_58 , & V_49 -> V_55 ) ||
F_22 ( V_59 , & V_49 -> V_55 ) )
continue;
if ( F_22 ( V_60 , & V_49 -> V_61 ) )
continue;
if ( V_49 -> V_52 == V_53 &&
! F_22 ( V_54 , & V_49 -> V_55 ) ) {
V_29 -> V_18 [ V_50 ++ ] = F_6 ( V_49 -> V_19 ) ;
F_11 ( L_3 , V_49 -> V_19 ) ;
}
}
V_29 -> V_62 = F_6 ( V_50 ) ;
V_30 = sizeof( * V_29 ) + ( 2 * V_50 ) ;
F_23 ( & V_51 ) ;
V_27 = F_13 ( V_22 , V_20 , V_63 , 0 , V_29 ,
V_30 ) ;
F_18 ( V_29 ) ;
return V_27 ;
}
static int F_24 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_64 * V_29 ;
struct V_5 * V_49 ;
T_3 V_30 ;
T_2 V_50 ;
int V_27 ;
F_11 ( L_2 , V_22 ) ;
F_20 ( & V_51 ) ;
V_50 = 0 ;
F_21 (d, &hci_dev_list, list) {
if ( V_49 -> V_52 == V_53 &&
F_22 ( V_54 , & V_49 -> V_55 ) )
V_50 ++ ;
}
V_30 = sizeof( * V_29 ) + ( 2 * V_50 ) ;
V_29 = F_16 ( V_30 , V_56 ) ;
if ( ! V_29 ) {
F_23 ( & V_51 ) ;
return - V_16 ;
}
V_50 = 0 ;
F_21 (d, &hci_dev_list, list) {
if ( F_22 ( V_57 , & V_49 -> V_55 ) ||
F_22 ( V_58 , & V_49 -> V_55 ) ||
F_22 ( V_59 , & V_49 -> V_55 ) )
continue;
if ( F_22 ( V_60 , & V_49 -> V_61 ) )
continue;
if ( V_49 -> V_52 == V_53 &&
F_22 ( V_54 , & V_49 -> V_55 ) ) {
V_29 -> V_18 [ V_50 ++ ] = F_6 ( V_49 -> V_19 ) ;
F_11 ( L_3 , V_49 -> V_19 ) ;
}
}
V_29 -> V_62 = F_6 ( V_50 ) ;
V_30 = sizeof( * V_29 ) + ( 2 * V_50 ) ;
F_23 ( & V_51 ) ;
V_27 = F_13 ( V_22 , V_20 , V_65 ,
0 , V_29 , V_30 ) ;
F_18 ( V_29 ) ;
return V_27 ;
}
static bool F_25 ( struct V_5 * V_6 )
{
if ( F_22 ( V_66 , & V_6 -> V_61 ) &&
! F_22 ( V_67 , & V_6 -> V_55 ) )
return false ;
if ( F_22 ( V_68 , & V_6 -> V_61 ) &&
! F_26 ( & V_6 -> V_69 , V_70 ) )
return false ;
return true ;
}
static T_5 F_27 ( struct V_5 * V_6 )
{
T_6 V_71 = 0 ;
if ( F_22 ( V_66 , & V_6 -> V_61 ) &&
! F_22 ( V_67 , & V_6 -> V_55 ) )
V_71 |= V_72 ;
if ( F_22 ( V_68 , & V_6 -> V_61 ) &&
! F_26 ( & V_6 -> V_69 , V_70 ) )
V_71 |= V_73 ;
return F_28 ( V_71 ) ;
}
static int F_29 ( struct V_5 * V_6 , struct V_9 * V_74 )
{
T_5 V_71 = F_27 ( V_6 ) ;
return F_3 ( V_75 , V_6 , & V_71 ,
sizeof( V_71 ) , V_74 ) ;
}
static int F_30 ( struct V_9 * V_22 , T_2 V_17 , struct V_5 * V_6 )
{
T_5 V_71 = F_27 ( V_6 ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_17 , 0 , & V_71 ,
sizeof( V_71 ) ) ;
}
static int F_31 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_76 V_29 ;
T_6 V_71 = 0 ;
F_11 ( L_4 , V_22 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_78 = F_6 ( V_6 -> V_78 ) ;
if ( F_22 ( V_66 , & V_6 -> V_61 ) )
V_71 |= V_72 ;
if ( V_6 -> V_79 )
V_71 |= V_73 ;
V_29 . V_80 = F_28 ( V_71 ) ;
V_29 . V_81 = F_27 ( V_6 ) ;
F_33 ( V_6 ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_82 , 0 , & V_29 ,
sizeof( V_29 ) ) ;
}
static T_6 F_34 ( struct V_5 * V_6 )
{
T_6 V_83 = 0 ;
V_83 |= V_84 ;
V_83 |= V_85 ;
V_83 |= V_86 ;
V_83 |= V_87 ;
V_83 |= V_88 ;
if ( F_35 ( V_6 ) ) {
if ( V_6 -> V_89 >= V_90 )
V_83 |= V_91 ;
V_83 |= V_92 ;
V_83 |= V_93 ;
if ( F_36 ( V_6 ) ) {
V_83 |= V_94 ;
V_83 |= V_95 ;
}
if ( F_37 ( V_6 ) )
V_83 |= V_96 ;
}
if ( F_38 ( V_6 ) ) {
V_83 |= V_97 ;
V_83 |= V_98 ;
V_83 |= V_96 ;
V_83 |= V_99 ;
}
if ( F_22 ( V_66 , & V_6 -> V_61 ) ||
V_6 -> V_79 )
V_83 |= V_100 ;
return V_83 ;
}
static T_6 F_39 ( struct V_5 * V_6 )
{
T_6 V_83 = 0 ;
if ( F_40 ( V_6 ) )
V_83 |= V_84 ;
if ( F_22 ( V_101 , & V_6 -> V_55 ) )
V_83 |= V_87 ;
if ( F_22 ( V_102 , & V_6 -> V_55 ) )
V_83 |= V_91 ;
if ( F_22 ( V_103 , & V_6 -> V_55 ) )
V_83 |= V_88 ;
if ( F_22 ( V_104 , & V_6 -> V_55 ) )
V_83 |= V_85 ;
if ( F_22 ( V_105 , & V_6 -> V_55 ) )
V_83 |= V_92 ;
if ( F_22 ( V_106 , & V_6 -> V_55 ) )
V_83 |= V_97 ;
if ( F_22 ( V_107 , & V_6 -> V_55 ) )
V_83 |= V_93 ;
if ( F_22 ( V_108 , & V_6 -> V_55 ) )
V_83 |= V_94 ;
if ( F_22 ( V_109 , & V_6 -> V_55 ) )
V_83 |= V_95 ;
if ( F_22 ( V_110 , & V_6 -> V_55 ) )
V_83 |= V_98 ;
if ( F_22 ( V_111 , & V_6 -> V_55 ) )
V_83 |= V_96 ;
if ( F_22 ( V_112 , & V_6 -> V_55 ) )
V_83 |= V_86 ;
if ( F_22 ( V_113 , & V_6 -> V_55 ) )
V_83 |= V_99 ;
return V_83 ;
}
static T_1 * F_41 ( struct V_5 * V_6 , T_1 * V_7 , T_7 V_21 )
{
T_1 * V_114 = V_7 , * V_115 = NULL ;
struct V_116 * V_117 ;
if ( V_21 < 4 )
return V_114 ;
F_21 (uuid, &hdev->uuids, list) {
T_2 V_118 ;
if ( V_117 -> V_119 != 16 )
continue;
V_118 = F_42 ( & V_117 -> V_117 [ 12 ] ) ;
if ( V_118 < 0x1100 )
continue;
if ( V_118 == V_120 )
continue;
if ( ! V_115 ) {
V_115 = V_114 ;
V_115 [ 0 ] = 1 ;
V_115 [ 1 ] = V_121 ;
V_114 += 2 ;
}
if ( ( V_114 - V_7 ) + sizeof( T_2 ) > V_21 ) {
V_115 [ 1 ] = V_122 ;
break;
}
* V_114 ++ = ( V_118 & 0x00ff ) ;
* V_114 ++ = ( V_118 & 0xff00 ) >> 8 ;
V_115 [ 0 ] += sizeof( V_118 ) ;
}
return V_114 ;
}
static T_1 * F_43 ( struct V_5 * V_6 , T_1 * V_7 , T_7 V_21 )
{
T_1 * V_114 = V_7 , * V_115 = NULL ;
struct V_116 * V_117 ;
if ( V_21 < 6 )
return V_114 ;
F_21 (uuid, &hdev->uuids, list) {
if ( V_117 -> V_119 != 32 )
continue;
if ( ! V_115 ) {
V_115 = V_114 ;
V_115 [ 0 ] = 1 ;
V_115 [ 1 ] = V_123 ;
V_114 += 2 ;
}
if ( ( V_114 - V_7 ) + sizeof( T_6 ) > V_21 ) {
V_115 [ 1 ] = V_124 ;
break;
}
memcpy ( V_114 , & V_117 -> V_117 [ 12 ] , sizeof( T_6 ) ) ;
V_114 += sizeof( T_6 ) ;
V_115 [ 0 ] += sizeof( T_6 ) ;
}
return V_114 ;
}
static T_1 * F_44 ( struct V_5 * V_6 , T_1 * V_7 , T_7 V_21 )
{
T_1 * V_114 = V_7 , * V_115 = NULL ;
struct V_116 * V_117 ;
if ( V_21 < 18 )
return V_114 ;
F_21 (uuid, &hdev->uuids, list) {
if ( V_117 -> V_119 != 128 )
continue;
if ( ! V_115 ) {
V_115 = V_114 ;
V_115 [ 0 ] = 1 ;
V_115 [ 1 ] = V_125 ;
V_114 += 2 ;
}
if ( ( V_114 - V_7 ) + 16 > V_21 ) {
V_115 [ 1 ] = V_126 ;
break;
}
memcpy ( V_114 , V_117 -> V_117 , 16 ) ;
V_114 += 16 ;
V_115 [ 0 ] += 16 ;
}
return V_114 ;
}
static struct V_127 * F_45 ( T_2 V_17 , struct V_5 * V_6 )
{
struct V_127 * V_23 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
if ( V_23 -> V_17 == V_17 )
return V_23 ;
}
return NULL ;
}
static struct V_127 * F_46 ( T_2 V_17 ,
struct V_5 * V_6 ,
const void * V_7 )
{
struct V_127 * V_23 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
if ( V_23 -> V_128 != V_7 )
continue;
if ( V_23 -> V_17 == V_17 )
return V_23 ;
}
return NULL ;
}
static T_1 F_47 ( struct V_5 * V_6 , T_1 * V_114 )
{
T_1 V_129 = 0 ;
T_3 V_130 ;
V_130 = strlen ( V_6 -> V_131 ) ;
if ( V_130 > 0 ) {
T_3 V_132 = V_133 - V_129 - 2 ;
if ( V_130 > V_132 ) {
V_130 = V_132 ;
V_114 [ 1 ] = V_134 ;
} else
V_114 [ 1 ] = V_135 ;
V_114 [ 0 ] = V_130 + 1 ;
memcpy ( V_114 + 2 , V_6 -> V_131 , V_130 ) ;
V_129 += ( V_130 + 2 ) ;
V_114 += ( V_130 + 2 ) ;
}
return V_129 ;
}
static void F_48 ( struct V_136 * V_137 )
{
struct V_5 * V_6 = V_137 -> V_6 ;
struct V_138 V_139 ;
T_1 V_21 ;
if ( ! F_22 ( V_106 , & V_6 -> V_55 ) )
return;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_21 = F_47 ( V_6 , V_139 . V_7 ) ;
if ( V_6 -> V_140 == V_21 &&
memcmp ( V_139 . V_7 , V_6 -> V_141 , V_21 ) == 0 )
return;
memcpy ( V_6 -> V_141 , V_139 . V_7 , sizeof( V_139 . V_7 ) ) ;
V_6 -> V_140 = V_21 ;
V_139 . V_142 = V_21 ;
F_49 ( V_137 , V_143 , sizeof( V_139 ) , & V_139 ) ;
}
static T_1 F_50 ( struct V_5 * V_6 )
{
struct V_127 * V_23 ;
V_23 = F_45 ( V_144 , V_6 ) ;
if ( V_23 ) {
struct V_145 * V_139 = V_23 -> V_146 ;
if ( V_139 -> V_147 == 0x01 )
return V_148 ;
else if ( V_139 -> V_147 == 0x02 )
return V_149 ;
} else {
if ( F_22 ( V_150 , & V_6 -> V_55 ) )
return V_149 ;
else if ( F_22 ( V_103 , & V_6 -> V_55 ) )
return V_148 ;
}
return 0 ;
}
static T_1 F_51 ( struct V_5 * V_6 , T_1 * V_114 )
{
T_1 V_129 = 0 , V_151 = 0 ;
V_151 |= F_50 ( V_6 ) ;
if ( ! F_22 ( V_105 , & V_6 -> V_55 ) )
V_151 |= V_152 ;
if ( V_151 ) {
F_11 ( L_5 , V_151 ) ;
V_114 [ 0 ] = 2 ;
V_114 [ 1 ] = V_153 ;
V_114 [ 2 ] = V_151 ;
V_129 += 3 ;
V_114 += 3 ;
}
if ( V_6 -> V_154 != V_155 ) {
V_114 [ 0 ] = 2 ;
V_114 [ 1 ] = V_156 ;
V_114 [ 2 ] = ( T_1 ) V_6 -> V_154 ;
V_129 += 3 ;
V_114 += 3 ;
}
return V_129 ;
}
static void F_52 ( struct V_136 * V_137 )
{
struct V_5 * V_6 = V_137 -> V_6 ;
struct V_157 V_139 ;
T_1 V_21 ;
if ( ! F_22 ( V_106 , & V_6 -> V_55 ) )
return;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_21 = F_51 ( V_6 , V_139 . V_7 ) ;
if ( V_6 -> V_158 == V_21 &&
memcmp ( V_139 . V_7 , V_6 -> V_159 , V_21 ) == 0 )
return;
memcpy ( V_6 -> V_159 , V_139 . V_7 , sizeof( V_139 . V_7 ) ) ;
V_6 -> V_158 = V_21 ;
V_139 . V_142 = V_21 ;
F_49 ( V_137 , V_160 , sizeof( V_139 ) , & V_139 ) ;
}
int F_53 ( struct V_5 * V_6 )
{
struct V_136 V_137 ;
F_54 ( & V_137 , V_6 ) ;
F_52 ( & V_137 ) ;
return F_55 ( & V_137 , NULL ) ;
}
static void F_56 ( struct V_5 * V_6 , T_1 * V_7 )
{
T_1 * V_114 = V_7 ;
T_3 V_130 ;
V_130 = strlen ( V_6 -> V_131 ) ;
if ( V_130 > 0 ) {
if ( V_130 > 48 ) {
V_130 = 48 ;
V_114 [ 1 ] = V_134 ;
} else
V_114 [ 1 ] = V_135 ;
V_114 [ 0 ] = V_130 + 1 ;
memcpy ( V_114 + 2 , V_6 -> V_131 , V_130 ) ;
V_114 += ( V_130 + 2 ) ;
}
if ( V_6 -> V_161 != V_155 ) {
V_114 [ 0 ] = 2 ;
V_114 [ 1 ] = V_156 ;
V_114 [ 2 ] = ( T_1 ) V_6 -> V_161 ;
V_114 += 3 ;
}
if ( V_6 -> V_162 > 0 ) {
V_114 [ 0 ] = 9 ;
V_114 [ 1 ] = V_163 ;
F_17 ( V_6 -> V_162 , V_114 + 2 ) ;
F_17 ( V_6 -> V_164 , V_114 + 4 ) ;
F_17 ( V_6 -> V_165 , V_114 + 6 ) ;
F_17 ( V_6 -> V_166 , V_114 + 8 ) ;
V_114 += 10 ;
}
V_114 = F_41 ( V_6 , V_114 , V_167 - ( V_114 - V_7 ) ) ;
V_114 = F_43 ( V_6 , V_114 , V_167 - ( V_114 - V_7 ) ) ;
V_114 = F_44 ( V_6 , V_114 , V_167 - ( V_114 - V_7 ) ) ;
}
static void F_57 ( struct V_136 * V_137 )
{
struct V_5 * V_6 = V_137 -> V_6 ;
struct V_168 V_139 ;
if ( ! F_40 ( V_6 ) )
return;
if ( ! F_58 ( V_6 ) )
return;
if ( ! F_22 ( V_108 , & V_6 -> V_55 ) )
return;
if ( F_22 ( V_169 , & V_6 -> V_55 ) )
return;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
F_56 ( V_6 , V_139 . V_7 ) ;
if ( memcmp ( V_139 . V_7 , V_6 -> V_170 , sizeof( V_139 . V_7 ) ) == 0 )
return;
memcpy ( V_6 -> V_170 , V_139 . V_7 , sizeof( V_139 . V_7 ) ) ;
F_49 ( V_137 , V_171 , sizeof( V_139 ) , & V_139 ) ;
}
static T_1 F_59 ( struct V_5 * V_6 )
{
struct V_116 * V_117 ;
T_1 V_147 = 0 ;
F_21 (uuid, &hdev->uuids, list)
V_147 |= V_117 -> V_172 ;
return V_147 ;
}
static void F_60 ( struct V_136 * V_137 )
{
struct V_5 * V_6 = V_137 -> V_6 ;
T_1 V_173 [ 3 ] ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_40 ( V_6 ) )
return;
if ( ! F_22 ( V_105 , & V_6 -> V_55 ) )
return;
if ( F_22 ( V_169 , & V_6 -> V_55 ) )
return;
V_173 [ 0 ] = V_6 -> V_174 ;
V_173 [ 1 ] = V_6 -> V_175 ;
V_173 [ 2 ] = F_59 ( V_6 ) ;
if ( F_22 ( V_150 , & V_6 -> V_55 ) )
V_173 [ 1 ] |= 0x20 ;
if ( memcmp ( V_173 , V_6 -> V_176 , 3 ) == 0 )
return;
F_49 ( V_137 , V_177 , sizeof( V_173 ) , V_173 ) ;
}
static bool F_61 ( struct V_5 * V_6 )
{
struct V_127 * V_23 ;
V_23 = F_45 ( V_178 , V_6 ) ;
if ( V_23 ) {
struct V_145 * V_139 = V_23 -> V_146 ;
return V_139 -> V_147 ;
}
return F_22 ( V_101 , & V_6 -> V_55 ) ;
}
static void F_62 ( struct V_136 * V_137 )
{
T_1 V_179 = 0x00 ;
F_49 ( V_137 , V_180 , sizeof( V_179 ) , & V_179 ) ;
}
static void F_63 ( struct V_136 * V_137 )
{
struct V_5 * V_6 = V_137 -> V_6 ;
struct V_181 V_139 ;
T_1 V_182 , V_179 = 0x01 ;
bool V_183 ;
if ( F_64 ( V_6 , V_184 ) > 0 )
return;
if ( F_22 ( V_185 , & V_6 -> V_55 ) )
F_62 ( V_137 ) ;
F_65 ( V_185 , & V_6 -> V_55 ) ;
V_183 = F_61 ( V_6 ) ;
if ( F_66 ( V_137 , ! V_183 , & V_182 ) < 0 )
return;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_186 = F_6 ( V_6 -> V_187 ) ;
V_139 . V_188 = F_6 ( V_6 -> V_189 ) ;
V_139 . type = V_183 ? V_190 : V_191 ;
V_139 . V_192 = V_182 ;
V_139 . V_193 = V_6 -> V_194 ;
F_49 ( V_137 , V_195 , sizeof( V_139 ) , & V_139 ) ;
F_49 ( V_137 , V_180 , sizeof( V_179 ) , & V_179 ) ;
}
static void F_67 ( struct V_196 * V_197 )
{
struct V_5 * V_6 = F_68 ( V_197 , struct V_5 ,
V_198 . V_197 ) ;
struct V_136 V_137 ;
if ( ! F_69 ( V_169 , & V_6 -> V_55 ) )
return;
F_54 ( & V_137 , V_6 ) ;
F_32 ( V_6 ) ;
F_57 ( & V_137 ) ;
F_60 ( & V_137 ) ;
F_33 ( V_6 ) ;
F_55 ( & V_137 , NULL ) ;
}
static void F_70 ( struct V_196 * V_197 )
{
struct V_5 * V_6 = F_68 ( V_197 , struct V_5 ,
F_70 . V_197 ) ;
struct V_136 V_137 ;
F_11 ( L_7 ) ;
F_71 ( V_199 , & V_6 -> V_55 ) ;
if ( ! F_22 ( V_110 , & V_6 -> V_55 ) )
return;
F_54 ( & V_137 , V_6 ) ;
F_63 ( & V_137 ) ;
F_55 ( & V_137 , NULL ) ;
}
static void F_72 ( struct V_9 * V_22 , struct V_5 * V_6 )
{
if ( F_73 ( V_200 , & V_6 -> V_55 ) )
return;
F_74 ( & V_6 -> V_198 , F_67 ) ;
F_74 ( & V_6 -> F_70 , F_70 ) ;
F_65 ( V_104 , & V_6 -> V_55 ) ;
}
static int F_75 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_201 V_29 ;
F_11 ( L_4 , V_22 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_202 , & V_6 -> V_202 ) ;
V_29 . V_34 = V_6 -> V_89 ;
V_29 . V_78 = F_6 ( V_6 -> V_78 ) ;
V_29 . V_203 = F_28 ( F_34 ( V_6 ) ) ;
V_29 . V_204 = F_28 ( F_39 ( V_6 ) ) ;
memcpy ( V_29 . V_176 , V_6 -> V_176 , 3 ) ;
memcpy ( V_29 . V_77 , V_6 -> V_131 , sizeof( V_6 -> V_131 ) ) ;
memcpy ( V_29 . V_205 , V_6 -> V_205 , sizeof( V_6 -> V_205 ) ) ;
F_33 ( V_6 ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_206 , 0 , & V_29 ,
sizeof( V_29 ) ) ;
}
static void F_77 ( struct V_127 * V_23 )
{
F_78 ( V_23 -> V_22 ) ;
F_18 ( V_23 -> V_146 ) ;
F_18 ( V_23 ) ;
}
static struct V_127 * F_79 ( struct V_9 * V_22 , T_2 V_17 ,
struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_127 * V_23 ;
V_23 = F_80 ( sizeof( * V_23 ) , V_15 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_17 = V_17 ;
V_23 -> V_18 = V_6 -> V_19 ;
V_23 -> V_146 = F_81 ( V_7 , V_21 , V_15 ) ;
if ( ! V_23 -> V_146 ) {
F_18 ( V_23 ) ;
return NULL ;
}
V_23 -> V_207 = V_21 ;
V_23 -> V_22 = V_22 ;
F_82 ( V_22 ) ;
F_83 ( & V_23 -> V_208 , & V_6 -> V_209 ) ;
return V_23 ;
}
static void F_84 ( T_2 V_17 , struct V_5 * V_6 ,
void (* F_85)( struct V_127 * V_23 ,
void * V_7 ) ,
void * V_7 )
{
struct V_127 * V_23 , * V_210 ;
F_86 (cmd, tmp, &hdev->mgmt_pending, list) {
if ( V_17 > 0 && V_23 -> V_17 != V_17 )
continue;
F_85 ( V_23 , V_7 ) ;
}
}
static void F_87 ( struct V_127 * V_23 )
{
F_88 ( & V_23 -> V_208 ) ;
F_77 ( V_23 ) ;
}
static int F_89 ( struct V_9 * V_22 , T_2 V_17 , struct V_5 * V_6 )
{
T_5 V_83 = F_28 ( F_39 ( V_6 ) ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_17 , 0 , & V_83 ,
sizeof( V_83 ) ) ;
}
static void F_90 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
F_11 ( L_8 , V_6 -> V_77 , V_24 ) ;
if ( F_91 ( V_6 ) == 0 ) {
F_92 ( & V_6 -> V_211 ) ;
F_93 ( V_6 -> V_212 , & V_6 -> V_211 . V_197 ) ;
}
}
static bool F_94 ( struct V_136 * V_137 )
{
struct V_5 * V_6 = V_137 -> V_6 ;
struct V_213 V_139 ;
struct V_214 * V_215 ;
switch ( V_6 -> V_216 . V_217 ) {
case V_218 :
if ( F_22 ( V_219 , & V_6 -> V_151 ) ) {
F_49 ( V_137 , V_220 , 0 , NULL ) ;
} else {
F_92 ( & V_6 -> V_221 ) ;
F_95 ( V_137 ) ;
}
return true ;
case V_222 :
V_215 = F_96 ( V_6 , V_70 ,
V_223 ) ;
if ( ! V_215 )
break;
F_76 ( & V_139 . V_202 , & V_215 -> V_7 . V_202 ) ;
F_49 ( V_137 , V_224 , sizeof( V_139 ) ,
& V_139 ) ;
return true ;
default:
if ( F_22 ( V_225 , & V_6 -> V_55 ) ) {
F_95 ( V_137 ) ;
return true ;
}
break;
}
return false ;
}
static int F_97 ( struct V_5 * V_6 )
{
struct V_136 V_137 ;
struct V_226 * V_227 ;
bool V_228 ;
int V_27 ;
F_54 ( & V_137 , V_6 ) ;
if ( F_22 ( V_229 , & V_6 -> V_151 ) ||
F_22 ( V_230 , & V_6 -> V_151 ) ) {
T_1 V_231 = 0x00 ;
F_49 ( & V_137 , V_232 , 1 , & V_231 ) ;
}
if ( F_22 ( V_185 , & V_6 -> V_55 ) )
F_62 ( & V_137 ) ;
V_228 = F_94 ( & V_137 ) ;
F_21 (conn, &hdev->conn_hash.list, list) {
struct V_233 V_234 ;
struct V_235 V_236 ;
switch ( V_227 -> V_217 ) {
case V_237 :
case V_238 :
V_234 . V_239 = F_6 ( V_227 -> V_239 ) ;
V_234 . V_240 = 0x15 ;
F_49 ( & V_137 , V_241 , sizeof( V_234 ) , & V_234 ) ;
break;
case V_242 :
if ( V_227 -> type == V_184 )
F_49 ( & V_137 , V_243 ,
0 , NULL ) ;
else if ( V_227 -> type == V_244 )
F_49 ( & V_137 , V_245 ,
6 , & V_227 -> V_246 ) ;
break;
case V_247 :
F_76 ( & V_236 . V_202 , & V_227 -> V_246 ) ;
V_236 . V_240 = 0x15 ;
if ( V_227 -> type == V_244 )
F_49 ( & V_137 , V_248 ,
sizeof( V_236 ) , & V_236 ) ;
else if ( V_227 -> type == V_249 )
F_49 ( & V_137 , V_250 ,
sizeof( V_236 ) , & V_236 ) ;
break;
}
}
V_27 = F_55 ( & V_137 , F_90 ) ;
if ( ! V_27 && V_228 )
F_98 ( V_6 , V_251 ) ;
return V_27 ;
}
static int F_99 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_145 * V_139 = V_7 ;
struct V_127 * V_23 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( V_139 -> V_147 != 0x00 && V_139 -> V_147 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_252 ,
V_253 ) ;
F_32 ( V_6 ) ;
if ( F_45 ( V_252 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_252 ,
V_254 ) ;
goto V_255;
}
if ( F_69 ( V_256 , & V_6 -> V_55 ) ) {
F_92 ( & V_6 -> V_211 ) ;
if ( V_139 -> V_147 ) {
F_79 ( V_22 , V_252 , V_6 ,
V_7 , V_21 ) ;
V_27 = F_100 ( V_6 , 1 ) ;
goto V_255;
}
}
if ( ! ! V_139 -> V_147 == F_40 ( V_6 ) ) {
V_27 = F_89 ( V_22 , V_252 , V_6 ) ;
goto V_255;
}
V_23 = F_79 ( V_22 , V_252 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_255;
}
if ( V_139 -> V_147 ) {
F_93 ( V_6 -> V_212 , & V_6 -> V_257 ) ;
V_27 = 0 ;
} else {
V_27 = F_97 ( V_6 ) ;
if ( ! V_27 )
F_101 ( V_6 -> V_212 , & V_6 -> V_211 ,
V_258 ) ;
if ( V_27 == - V_259 ) {
F_92 ( & V_6 -> V_211 ) ;
F_93 ( V_6 -> V_212 , & V_6 -> V_211 . V_197 ) ;
V_27 = 0 ;
}
}
V_255:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_102 ( struct V_5 * V_6 , struct V_9 * V_74 )
{
T_5 V_26 ;
V_26 = F_28 ( F_39 ( V_6 ) ) ;
return F_3 ( V_260 , V_6 , & V_26 , sizeof( V_26 ) , V_74 ) ;
}
int F_103 ( struct V_5 * V_6 )
{
return F_102 ( V_6 , NULL ) ;
}
static void F_104 ( struct V_127 * V_23 , void * V_7 )
{
struct V_261 * V_262 = V_7 ;
F_89 ( V_23 -> V_22 , V_23 -> V_17 , V_262 -> V_6 ) ;
F_88 ( & V_23 -> V_208 ) ;
if ( V_262 -> V_22 == NULL ) {
V_262 -> V_22 = V_23 -> V_22 ;
F_82 ( V_262 -> V_22 ) ;
}
F_77 ( V_23 ) ;
}
static void F_105 ( struct V_127 * V_23 , void * V_7 )
{
T_1 * V_24 = V_7 ;
F_10 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , * V_24 ) ;
F_87 ( V_23 ) ;
}
static void F_106 ( struct V_127 * V_23 , void * V_7 )
{
if ( V_23 -> F_13 ) {
T_1 * V_24 = V_7 ;
V_23 -> F_13 ( V_23 , * V_24 ) ;
F_87 ( V_23 ) ;
return;
}
F_105 ( V_23 , V_7 ) ;
}
static int F_107 ( struct V_127 * V_23 , T_1 V_24 )
{
return F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_24 ,
V_23 -> V_146 , V_23 -> V_207 ) ;
}
static int F_108 ( struct V_127 * V_23 , T_1 V_24 )
{
return F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_24 , V_23 -> V_146 ,
sizeof( struct V_263 ) ) ;
}
static T_1 F_109 ( struct V_5 * V_6 )
{
if ( ! F_35 ( V_6 ) )
return V_264 ;
else if ( ! F_22 ( V_105 , & V_6 -> V_55 ) )
return V_265 ;
else
return V_266 ;
}
static T_1 F_110 ( struct V_5 * V_6 )
{
if ( ! F_38 ( V_6 ) )
return V_264 ;
else if ( ! F_22 ( V_106 , & V_6 -> V_55 ) )
return V_265 ;
else
return V_266 ;
}
static void F_111 ( struct V_5 * V_6 , T_1 V_24 ,
T_2 V_17 )
{
struct V_127 * V_23 ;
struct V_145 * V_139 ;
struct V_136 V_137 ;
bool V_267 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_144 , V_6 ) ;
if ( ! V_23 )
goto V_268;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
F_10 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_269 ) ;
F_65 ( V_150 , & V_6 -> V_55 ) ;
goto V_270;
}
V_139 = V_23 -> V_146 ;
if ( V_139 -> V_147 ) {
V_267 = ! F_73 ( V_103 ,
& V_6 -> V_55 ) ;
if ( V_6 -> V_271 > 0 ) {
int V_272 = F_112 ( V_6 -> V_271 * 1000 ) ;
F_101 ( V_6 -> V_273 , & V_6 -> V_274 ,
V_272 ) ;
}
} else {
V_267 = F_69 ( V_103 ,
& V_6 -> V_55 ) ;
}
F_89 ( V_23 -> V_22 , V_144 , V_6 ) ;
if ( V_267 )
F_102 ( V_6 , V_23 -> V_22 ) ;
F_54 ( & V_137 , V_6 ) ;
F_113 ( & V_137 ) ;
F_60 ( & V_137 ) ;
F_55 ( & V_137 , NULL ) ;
V_270:
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_114 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_275 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
T_2 V_276 ;
T_1 V_231 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_22 ( V_106 , & V_6 -> V_55 ) &&
! F_22 ( V_105 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_144 ,
V_265 ) ;
if ( V_139 -> V_147 != 0x00 && V_139 -> V_147 != 0x01 && V_139 -> V_147 != 0x02 )
return F_10 ( V_22 , V_6 -> V_19 , V_144 ,
V_253 ) ;
V_276 = F_115 ( V_139 -> V_276 ) ;
if ( ( V_139 -> V_147 == 0x00 && V_276 > 0 ) ||
( V_139 -> V_147 == 0x02 && V_276 == 0 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_144 ,
V_253 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) && V_276 > 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_144 ,
V_277 ) ;
goto V_255;
}
if ( F_45 ( V_144 , V_6 ) ||
F_45 ( V_178 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_144 ,
V_254 ) ;
goto V_255;
}
if ( ! F_22 ( V_101 , & V_6 -> V_55 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_144 ,
V_265 ) ;
goto V_255;
}
if ( ! F_40 ( V_6 ) ) {
bool V_267 = false ;
if ( ! ! V_139 -> V_147 != F_22 ( V_103 , & V_6 -> V_55 ) ) {
F_116 ( V_103 , & V_6 -> V_55 ) ;
V_267 = true ;
}
V_27 = F_89 ( V_22 , V_144 , V_6 ) ;
if ( V_27 < 0 )
goto V_255;
if ( V_267 )
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_255;
}
if ( ! ! V_139 -> V_147 == F_22 ( V_103 , & V_6 -> V_55 ) &&
( V_139 -> V_147 == 0x02 ) == F_22 ( V_150 ,
& V_6 -> V_55 ) ) {
F_92 ( & V_6 -> V_274 ) ;
V_6 -> V_271 = V_276 ;
if ( V_139 -> V_147 && V_6 -> V_271 > 0 ) {
int V_272 = F_112 ( V_6 -> V_271 * 1000 ) ;
F_101 ( V_6 -> V_273 , & V_6 -> V_274 ,
V_272 ) ;
}
V_27 = F_89 ( V_22 , V_144 , V_6 ) ;
goto V_255;
}
V_23 = F_79 ( V_22 , V_144 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_255;
}
F_92 ( & V_6 -> V_274 ) ;
V_6 -> V_271 = V_276 ;
if ( V_139 -> V_147 == 0x02 )
F_71 ( V_150 , & V_6 -> V_55 ) ;
else
F_65 ( V_150 , & V_6 -> V_55 ) ;
F_54 ( & V_137 , V_6 ) ;
if ( ! F_22 ( V_105 , & V_6 -> V_55 ) )
goto V_278;
V_231 = V_279 ;
if ( V_139 -> V_147 ) {
struct V_280 V_281 ;
if ( V_139 -> V_147 == 0x02 ) {
V_281 . V_282 = F_117 ( T_1 , V_6 -> V_282 , 2 ) ;
V_281 . V_283 [ 0 ] = 0x00 ;
V_281 . V_283 [ 1 ] = 0x8b ;
V_281 . V_283 [ 2 ] = 0x9e ;
V_281 . V_283 [ 3 ] = 0x33 ;
V_281 . V_283 [ 4 ] = 0x8b ;
V_281 . V_283 [ 5 ] = 0x9e ;
} else {
V_281 . V_282 = 1 ;
V_281 . V_283 [ 0 ] = 0x33 ;
V_281 . V_283 [ 1 ] = 0x8b ;
V_281 . V_283 [ 2 ] = 0x9e ;
}
F_49 ( & V_137 , V_284 ,
( V_281 . V_282 * 3 ) + 1 , & V_281 ) ;
V_231 |= V_285 ;
} else {
F_65 ( V_150 , & V_6 -> V_55 ) ;
}
F_49 ( & V_137 , V_232 , sizeof( V_231 ) , & V_231 ) ;
V_278:
F_52 ( & V_137 ) ;
V_27 = F_55 ( & V_137 , F_111 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_255:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_118 ( struct V_136 * V_137 , bool V_179 )
{
struct V_5 * V_6 = V_137 -> V_6 ;
struct V_286 V_287 ;
T_1 type ;
if ( ! F_22 ( V_105 , & V_6 -> V_55 ) )
return;
if ( V_6 -> V_89 < V_90 )
return;
if ( V_179 ) {
type = V_288 ;
V_287 . V_289 = F_6 ( 0x0100 ) ;
} else {
type = V_290 ;
V_287 . V_289 = F_6 ( 0x0800 ) ;
}
V_287 . V_291 = F_6 ( 0x0012 ) ;
if ( F_119 ( V_6 -> V_292 ) != V_287 . V_289 ||
F_119 ( V_6 -> V_293 ) != V_287 . V_291 )
F_49 ( V_137 , V_294 ,
sizeof( V_287 ) , & V_287 ) ;
if ( V_6 -> V_295 != type )
F_49 ( V_137 , V_296 , 1 , & type ) ;
}
static void F_120 ( struct V_5 * V_6 , T_1 V_24 ,
T_2 V_17 )
{
struct V_127 * V_23 ;
struct V_145 * V_139 ;
bool V_297 , V_298 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_178 , V_6 ) ;
if ( ! V_23 )
goto V_268;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
F_10 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_269 ) ;
goto V_270;
}
V_139 = V_23 -> V_146 ;
if ( V_139 -> V_147 ) {
V_297 = ! F_73 ( V_101 ,
& V_6 -> V_55 ) ;
V_298 = false ;
} else {
V_297 = F_69 ( V_101 ,
& V_6 -> V_55 ) ;
V_298 = F_69 ( V_103 ,
& V_6 -> V_55 ) ;
}
F_89 ( V_23 -> V_22 , V_178 , V_6 ) ;
if ( V_297 || V_298 ) {
F_102 ( V_6 , V_23 -> V_22 ) ;
F_121 ( V_6 ) ;
if ( V_298 )
F_53 ( V_6 ) ;
F_122 ( V_6 ) ;
}
V_270:
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_123 ( struct V_5 * V_6 ,
struct V_9 * V_22 , T_1 V_147 )
{
bool V_267 = false ;
int V_27 ;
if ( ! ! V_147 != F_22 ( V_101 , & V_6 -> V_55 ) )
V_267 = true ;
if ( V_147 ) {
F_71 ( V_101 , & V_6 -> V_55 ) ;
} else {
F_65 ( V_101 , & V_6 -> V_55 ) ;
F_65 ( V_103 , & V_6 -> V_55 ) ;
}
V_27 = F_89 ( V_22 , V_178 , V_6 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_267 ) {
F_121 ( V_6 ) ;
F_122 ( V_6 ) ;
return F_102 ( V_6 , V_22 ) ;
}
return 0 ;
}
static int F_124 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_145 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
T_1 V_231 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_22 ( V_106 , & V_6 -> V_55 ) &&
! F_22 ( V_105 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_178 ,
V_265 ) ;
if ( V_139 -> V_147 != 0x00 && V_139 -> V_147 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_178 ,
V_253 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_123 ( V_6 , V_22 , V_139 -> V_147 ) ;
goto V_255;
}
if ( F_45 ( V_144 , V_6 ) ||
F_45 ( V_178 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_178 ,
V_254 ) ;
goto V_255;
}
V_23 = F_79 ( V_22 , V_178 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_255;
}
F_54 ( & V_137 , V_6 ) ;
if ( ! F_22 ( V_105 , & V_6 -> V_55 ) ) {
if ( ! V_139 -> V_147 ) {
F_65 ( V_150 , & V_6 -> V_55 ) ;
F_65 ( V_103 , & V_6 -> V_55 ) ;
}
F_52 ( & V_137 ) ;
} else if ( V_139 -> V_147 != F_22 ( V_230 , & V_6 -> V_151 ) ) {
if ( V_139 -> V_147 ) {
V_231 = V_279 ;
} else {
if ( F_125 ( & V_6 -> V_299 ) )
V_231 = V_300 ;
else if ( F_22 ( V_229 , & V_6 -> V_151 ) )
V_231 = V_279 ;
else
goto V_301;
if ( F_22 ( V_229 , & V_6 -> V_151 ) &&
V_6 -> V_271 > 0 )
F_92 ( & V_6 -> V_274 ) ;
}
F_49 ( & V_137 , V_232 , 1 , & V_231 ) ;
}
V_301:
if ( V_139 -> V_147 || F_22 ( V_102 , & V_6 -> V_55 ) )
F_118 ( & V_137 , false ) ;
if ( F_22 ( V_110 , & V_6 -> V_55 ) )
F_63 ( & V_137 ) ;
V_27 = F_55 ( & V_137 , F_120 ) ;
if ( V_27 < 0 ) {
F_87 ( V_23 ) ;
if ( V_27 == - V_259 )
V_27 = F_123 ( V_6 , V_22 ,
V_139 -> V_147 ) ;
goto V_255;
}
V_255:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_126 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_145 * V_139 = V_7 ;
bool V_267 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( V_139 -> V_147 != 0x00 && V_139 -> V_147 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_302 ,
V_253 ) ;
F_32 ( V_6 ) ;
if ( V_139 -> V_147 )
V_267 = ! F_73 ( V_104 , & V_6 -> V_55 ) ;
else
V_267 = F_69 ( V_104 , & V_6 -> V_55 ) ;
V_27 = F_89 ( V_22 , V_302 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( V_267 )
V_27 = F_102 ( V_6 , V_22 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_127 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_145 * V_139 = V_7 ;
struct V_127 * V_23 ;
T_1 V_147 , V_24 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
V_24 = F_109 ( V_6 ) ;
if ( V_24 )
return F_10 ( V_22 , V_6 -> V_19 , V_303 ,
V_24 ) ;
if ( V_139 -> V_147 != 0x00 && V_139 -> V_147 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_303 ,
V_253 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
bool V_267 = false ;
if ( ! ! V_139 -> V_147 != F_22 ( V_107 ,
& V_6 -> V_55 ) ) {
F_116 ( V_107 , & V_6 -> V_55 ) ;
V_267 = true ;
}
V_27 = F_89 ( V_22 , V_303 , V_6 ) ;
if ( V_27 < 0 )
goto V_255;
if ( V_267 )
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_255;
}
if ( F_45 ( V_303 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_303 ,
V_254 ) ;
goto V_255;
}
V_147 = ! ! V_139 -> V_147 ;
if ( F_22 ( V_304 , & V_6 -> V_151 ) == V_147 ) {
V_27 = F_89 ( V_22 , V_303 , V_6 ) ;
goto V_255;
}
V_23 = F_79 ( V_22 , V_303 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_255;
}
V_27 = F_128 ( V_6 , V_305 , sizeof( V_147 ) , & V_147 ) ;
if ( V_27 < 0 ) {
F_87 ( V_23 ) ;
goto V_255;
}
V_255:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_129 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_145 * V_139 = V_7 ;
struct V_127 * V_23 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
V_24 = F_109 ( V_6 ) ;
if ( V_24 )
return F_10 ( V_22 , V_6 -> V_19 , V_306 , V_24 ) ;
if ( ! F_36 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_306 ,
V_264 ) ;
if ( V_139 -> V_147 != 0x00 && V_139 -> V_147 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_306 ,
V_253 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
bool V_267 ;
if ( V_139 -> V_147 ) {
V_267 = ! F_73 ( V_108 ,
& V_6 -> V_55 ) ;
} else {
V_267 = F_69 ( V_108 ,
& V_6 -> V_55 ) ;
if ( ! V_267 )
V_267 = F_69 ( V_109 ,
& V_6 -> V_55 ) ;
else
F_65 ( V_109 , & V_6 -> V_55 ) ;
}
V_27 = F_89 ( V_22 , V_306 , V_6 ) ;
if ( V_27 < 0 )
goto V_255;
if ( V_267 )
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_255;
}
if ( F_45 ( V_306 , V_6 ) ||
F_45 ( V_307 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_306 ,
V_254 ) ;
goto V_255;
}
if ( ! ! V_139 -> V_147 == F_22 ( V_108 , & V_6 -> V_55 ) ) {
V_27 = F_89 ( V_22 , V_306 , V_6 ) ;
goto V_255;
}
V_23 = F_79 ( V_22 , V_306 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_255;
}
if ( ! V_139 -> V_147 && F_22 ( V_308 , & V_6 -> V_55 ) )
F_128 ( V_6 , V_309 ,
sizeof( V_139 -> V_147 ) , & V_139 -> V_147 ) ;
V_27 = F_128 ( V_6 , V_310 , 1 , & V_139 -> V_147 ) ;
if ( V_27 < 0 ) {
F_87 ( V_23 ) ;
goto V_255;
}
V_255:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_130 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_145 * V_139 = V_7 ;
bool V_267 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
V_24 = F_109 ( V_6 ) ;
if ( V_24 )
return F_10 ( V_22 , V_6 -> V_19 , V_307 , V_24 ) ;
if ( ! F_36 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_307 ,
V_264 ) ;
if ( ! F_22 ( V_108 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_307 ,
V_265 ) ;
if ( V_139 -> V_147 != 0x00 && V_139 -> V_147 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_307 ,
V_253 ) ;
F_32 ( V_6 ) ;
if ( V_139 -> V_147 ) {
V_267 = ! F_73 ( V_109 , & V_6 -> V_55 ) ;
} else {
if ( F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_307 ,
V_265 ) ;
goto V_268;
}
V_267 = F_69 ( V_109 , & V_6 -> V_55 ) ;
}
V_27 = F_89 ( V_22 , V_307 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( V_267 )
V_27 = F_102 ( V_6 , V_22 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_131 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
struct V_261 V_262 = { NULL , V_6 } ;
F_32 ( V_6 ) ;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
F_84 ( V_311 , V_6 , F_105 ,
& V_269 ) ;
goto V_268;
}
F_84 ( V_311 , V_6 , F_104 , & V_262 ) ;
F_102 ( V_6 , V_262 . V_22 ) ;
if ( V_262 . V_22 )
F_78 ( V_262 . V_22 ) ;
if ( F_22 ( V_106 , & V_6 -> V_55 ) ) {
struct V_136 V_137 ;
F_54 ( & V_137 , V_6 ) ;
F_52 ( & V_137 ) ;
F_48 ( & V_137 ) ;
F_132 ( & V_137 ) ;
F_55 ( & V_137 , NULL ) ;
}
V_268:
F_33 ( V_6 ) ;
}
static int F_133 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_145 * V_139 = V_7 ;
struct V_312 V_281 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
int V_27 ;
T_1 V_147 , V_313 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_311 ,
V_264 ) ;
if ( V_139 -> V_147 != 0x00 && V_139 -> V_147 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_311 ,
V_253 ) ;
if ( ! F_22 ( V_105 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_311 ,
V_265 ) ;
F_32 ( V_6 ) ;
V_147 = ! ! V_139 -> V_147 ;
V_313 = F_134 ( V_6 ) ;
if ( ! F_40 ( V_6 ) || V_147 == V_313 ) {
bool V_267 = false ;
if ( V_147 != F_22 ( V_106 , & V_6 -> V_55 ) ) {
F_116 ( V_106 , & V_6 -> V_55 ) ;
V_267 = true ;
}
if ( ! V_147 && F_22 ( V_110 , & V_6 -> V_55 ) ) {
F_65 ( V_110 , & V_6 -> V_55 ) ;
V_267 = true ;
}
V_27 = F_89 ( V_22 , V_311 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( V_267 )
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_268;
}
if ( F_45 ( V_311 , V_6 ) ||
F_45 ( V_314 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_311 ,
V_254 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_311 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
F_54 ( & V_137 , V_6 ) ;
memset ( & V_281 , 0 , sizeof( V_281 ) ) ;
if ( V_147 ) {
V_281 . V_315 = V_147 ;
V_281 . V_316 = 0x00 ;
} else {
if ( F_22 ( V_185 , & V_6 -> V_55 ) )
F_62 ( & V_137 ) ;
}
F_49 ( & V_137 , V_317 , sizeof( V_281 ) ,
& V_281 ) ;
V_27 = F_55 ( & V_137 , F_131 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_135 ( struct V_5 * V_6 )
{
struct V_127 * V_23 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
switch ( V_23 -> V_17 ) {
case V_318 :
case V_319 :
case V_320 :
case V_252 :
return true ;
}
}
return false ;
}
static T_1 F_136 ( const T_1 * V_117 )
{
T_6 V_147 ;
if ( memcmp ( V_117 , V_321 , 12 ) )
return 128 ;
V_147 = F_137 ( & V_117 [ 12 ] ) ;
if ( V_147 > 0xffff )
return 32 ;
return 16 ;
}
static void F_138 ( struct V_5 * V_6 , T_2 V_322 , T_1 V_24 )
{
struct V_127 * V_23 ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_322 , V_6 ) ;
if ( ! V_23 )
goto V_268;
F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , F_1 ( V_24 ) ,
V_6 -> V_176 , 3 ) ;
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static void F_139 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
F_11 ( L_10 , V_24 ) ;
F_138 ( V_6 , V_318 , V_24 ) ;
}
static int F_140 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_323 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
struct V_116 * V_117 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( F_135 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_318 ,
V_254 ) ;
goto V_255;
}
V_117 = F_16 ( sizeof( * V_117 ) , V_15 ) ;
if ( ! V_117 ) {
V_27 = - V_16 ;
goto V_255;
}
memcpy ( V_117 -> V_117 , V_139 -> V_117 , 16 ) ;
V_117 -> V_172 = V_139 -> V_172 ;
V_117 -> V_119 = F_136 ( V_139 -> V_117 ) ;
F_141 ( & V_117 -> V_208 , & V_6 -> V_324 ) ;
F_54 ( & V_137 , V_6 ) ;
F_60 ( & V_137 ) ;
F_57 ( & V_137 ) ;
V_27 = F_55 ( & V_137 , F_139 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_259 )
goto V_255;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_318 , 0 ,
V_6 -> V_176 , 3 ) ;
goto V_255;
}
V_23 = F_79 ( V_22 , V_318 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_255;
}
V_27 = 0 ;
V_255:
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_142 ( struct V_5 * V_6 )
{
if ( ! F_40 ( V_6 ) )
return false ;
if ( ! F_73 ( V_169 , & V_6 -> V_55 ) ) {
F_101 ( V_6 -> V_273 , & V_6 -> V_198 ,
V_325 ) ;
return true ;
}
return false ;
}
static void F_143 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
F_11 ( L_10 , V_24 ) ;
F_138 ( V_6 , V_319 , V_24 ) ;
}
static int F_144 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_326 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_116 * V_262 , * V_210 ;
T_1 V_327 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_136 V_137 ;
int V_27 , V_328 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( F_135 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_319 ,
V_254 ) ;
goto V_268;
}
if ( memcmp ( V_139 -> V_117 , V_327 , 16 ) == 0 ) {
F_145 ( V_6 ) ;
if ( F_142 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_319 ,
0 , V_6 -> V_176 , 3 ) ;
goto V_268;
}
goto F_60;
}
V_328 = 0 ;
F_86 (match, tmp, &hdev->uuids, list) {
if ( memcmp ( V_262 -> V_117 , V_139 -> V_117 , 16 ) != 0 )
continue;
F_88 ( & V_262 -> V_208 ) ;
F_18 ( V_262 ) ;
V_328 ++ ;
}
if ( V_328 == 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_319 ,
V_253 ) ;
goto V_268;
}
F_60:
F_54 ( & V_137 , V_6 ) ;
F_60 ( & V_137 ) ;
F_57 ( & V_137 ) ;
V_27 = F_55 ( & V_137 , F_143 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_259 )
goto V_268;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_319 , 0 ,
V_6 -> V_176 , 3 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_319 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
V_27 = 0 ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_146 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
F_11 ( L_10 , V_24 ) ;
F_138 ( V_6 , V_320 , V_24 ) ;
}
static int F_147 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_329 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_35 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_320 ,
V_264 ) ;
F_32 ( V_6 ) ;
if ( F_135 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_320 ,
V_254 ) ;
goto V_268;
}
if ( ( V_139 -> V_330 & 0x03 ) != 0 || ( V_139 -> V_331 & 0xe0 ) != 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_320 ,
V_253 ) ;
goto V_268;
}
V_6 -> V_175 = V_139 -> V_331 ;
V_6 -> V_174 = V_139 -> V_330 ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_320 , 0 ,
V_6 -> V_176 , 3 ) ;
goto V_268;
}
F_54 ( & V_137 , V_6 ) ;
if ( F_69 ( V_169 , & V_6 -> V_55 ) ) {
F_33 ( V_6 ) ;
F_148 ( & V_6 -> V_198 ) ;
F_32 ( V_6 ) ;
F_57 ( & V_137 ) ;
}
F_60 ( & V_137 ) ;
V_27 = F_55 ( & V_137 , F_146 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_259 )
goto V_268;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_320 , 0 ,
V_6 -> V_176 , 3 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_320 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
V_27 = 0 ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_149 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_332 * V_139 = V_7 ;
const T_2 V_333 = ( ( V_334 - sizeof( * V_139 ) ) /
sizeof( struct V_335 ) ) ;
T_2 V_336 , V_337 ;
bool V_267 ;
int V_45 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_35 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_338 ,
V_264 ) ;
V_336 = F_115 ( V_139 -> V_336 ) ;
if ( V_336 > V_333 ) {
F_150 ( L_11 ,
V_336 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_338 ,
V_253 ) ;
}
V_337 = sizeof( * V_139 ) + V_336 *
sizeof( struct V_335 ) ;
if ( V_337 != V_21 ) {
F_150 ( L_12 ,
V_337 , V_21 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_338 ,
V_253 ) ;
}
if ( V_139 -> V_339 != 0x00 && V_139 -> V_339 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_338 ,
V_253 ) ;
F_11 ( L_13 , V_6 -> V_77 , V_139 -> V_339 ,
V_336 ) ;
for ( V_45 = 0 ; V_45 < V_336 ; V_45 ++ ) {
struct V_335 * V_340 = & V_139 -> V_341 [ V_45 ] ;
if ( V_340 -> V_342 . type != V_343 || V_340 -> type > 0x08 )
return F_10 ( V_22 , V_6 -> V_19 , V_338 ,
V_253 ) ;
}
F_32 ( V_6 ) ;
F_151 ( V_6 ) ;
if ( V_139 -> V_339 )
V_267 = ! F_73 ( V_112 ,
& V_6 -> V_55 ) ;
else
V_267 = F_69 ( V_112 ,
& V_6 -> V_55 ) ;
if ( V_267 )
F_102 ( V_6 , NULL ) ;
for ( V_45 = 0 ; V_45 < V_336 ; V_45 ++ ) {
struct V_335 * V_340 = & V_139 -> V_341 [ V_45 ] ;
if ( V_340 -> type == V_344 )
continue;
F_152 ( V_6 , NULL , & V_340 -> V_342 . V_202 , V_340 -> V_147 ,
V_340 -> type , V_340 -> V_345 , NULL ) ;
}
F_13 ( V_22 , V_6 -> V_19 , V_338 , 0 , NULL , 0 ) ;
F_33 ( V_6 ) ;
return 0 ;
}
static int F_153 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_346 , struct V_9 * V_10 )
{
struct V_347 V_26 ;
F_76 ( & V_26 . V_342 . V_202 , V_202 ) ;
V_26 . V_342 . type = V_346 ;
return F_3 ( V_348 , V_6 , & V_26 , sizeof( V_26 ) ,
V_10 ) ;
}
static int F_154 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_349 * V_139 = V_7 ;
struct V_350 V_29 ;
struct V_233 V_234 ;
struct V_127 * V_23 ;
struct V_226 * V_227 ;
int V_27 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_342 . V_202 , & V_139 -> V_342 . V_202 ) ;
V_29 . V_342 . type = V_139 -> V_342 . type ;
if ( ! F_155 ( V_139 -> V_342 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_351 ,
V_253 ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_139 -> V_352 != 0x00 && V_139 -> V_352 != 0x01 )
return F_13 ( V_22 , V_6 -> V_19 , V_351 ,
V_253 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_351 ,
V_277 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
if ( V_139 -> V_342 . type == V_343 ) {
if ( V_139 -> V_352 )
V_227 = F_156 ( V_6 , V_244 ,
& V_139 -> V_342 . V_202 ) ;
else
V_227 = NULL ;
V_27 = F_157 ( V_6 , & V_139 -> V_342 . V_202 ) ;
} else {
T_1 V_346 ;
V_227 = F_156 ( V_6 , V_184 ,
& V_139 -> V_342 . V_202 ) ;
if ( V_227 ) {
F_71 ( V_353 , & V_227 -> V_151 ) ;
if ( ! V_139 -> V_352 )
V_227 = NULL ;
}
if ( V_139 -> V_342 . type == V_354 )
V_346 = V_355 ;
else
V_346 = V_356 ;
F_158 ( V_6 , & V_139 -> V_342 . V_202 , V_346 ) ;
V_27 = F_159 ( V_6 , & V_139 -> V_342 . V_202 , V_346 ) ;
}
if ( V_27 < 0 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_351 ,
V_357 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
if ( ! V_227 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_351 , 0 ,
& V_29 , sizeof( V_29 ) ) ;
F_153 ( V_6 , & V_139 -> V_342 . V_202 , V_139 -> V_342 . type , V_22 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_351 , V_6 , V_139 ,
sizeof( * V_139 ) ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
V_23 -> F_13 = F_108 ;
V_234 . V_239 = F_6 ( V_227 -> V_239 ) ;
V_234 . V_240 = 0x13 ;
V_27 = F_128 ( V_6 , V_241 , sizeof( V_234 ) , & V_234 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int V_352 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_358 * V_139 = V_7 ;
struct V_359 V_29 ;
struct V_127 * V_23 ;
struct V_226 * V_227 ;
int V_27 ;
F_11 ( L_7 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_342 . V_202 , & V_139 -> V_342 . V_202 ) ;
V_29 . V_342 . type = V_139 -> V_342 . type ;
if ( ! F_155 ( V_139 -> V_342 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_360 ,
V_253 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_22 ( V_361 , & V_6 -> V_151 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_360 ,
V_277 , & V_29 , sizeof( V_29 ) ) ;
goto V_255;
}
if ( F_45 ( V_360 , V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_360 ,
V_254 , & V_29 , sizeof( V_29 ) ) ;
goto V_255;
}
if ( V_139 -> V_342 . type == V_343 )
V_227 = F_156 ( V_6 , V_244 ,
& V_139 -> V_342 . V_202 ) ;
else
V_227 = F_156 ( V_6 , V_184 , & V_139 -> V_342 . V_202 ) ;
if ( ! V_227 || V_227 -> V_217 == V_362 || V_227 -> V_217 == V_363 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_360 ,
V_364 , & V_29 , sizeof( V_29 ) ) ;
goto V_255;
}
V_23 = F_79 ( V_22 , V_360 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_255;
}
V_23 -> F_13 = F_107 ;
V_27 = F_160 ( V_227 , V_365 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_255:
F_33 ( V_6 ) ;
return V_27 ;
}
static T_1 F_161 ( T_1 V_366 , T_1 V_346 )
{
switch ( V_366 ) {
case V_184 :
switch ( V_346 ) {
case V_355 :
return V_354 ;
default:
return V_367 ;
}
default:
return V_343 ;
}
}
static int F_162 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_8 )
{
struct V_368 * V_29 ;
struct V_226 * V_369 ;
T_3 V_30 ;
int V_27 ;
T_2 V_45 ;
F_11 ( L_7 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_370 ,
V_277 ) ;
goto V_268;
}
V_45 = 0 ;
F_21 (c, &hdev->conn_hash.list, list) {
if ( F_22 ( V_371 , & V_369 -> V_151 ) )
V_45 ++ ;
}
V_30 = sizeof( * V_29 ) + ( V_45 * sizeof( struct V_263 ) ) ;
V_29 = F_16 ( V_30 , V_15 ) ;
if ( ! V_29 ) {
V_27 = - V_16 ;
goto V_268;
}
V_45 = 0 ;
F_21 (c, &hdev->conn_hash.list, list) {
if ( ! F_22 ( V_371 , & V_369 -> V_151 ) )
continue;
F_76 ( & V_29 -> V_342 [ V_45 ] . V_202 , & V_369 -> V_246 ) ;
V_29 -> V_342 [ V_45 ] . type = F_161 ( V_369 -> type , V_369 -> V_372 ) ;
if ( V_369 -> type == V_249 || V_369 -> type == V_373 )
continue;
V_45 ++ ;
}
V_29 -> V_374 = F_6 ( V_45 ) ;
V_30 = sizeof( * V_29 ) + ( V_45 * sizeof( struct V_263 ) ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_370 , 0 , V_29 ,
V_30 ) ;
F_18 ( V_29 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_163 ( struct V_9 * V_22 , struct V_5 * V_6 ,
struct V_375 * V_139 )
{
struct V_127 * V_23 ;
int V_27 ;
V_23 = F_79 ( V_22 , V_376 , V_6 , V_139 ,
sizeof( * V_139 ) ) ;
if ( ! V_23 )
return - V_16 ;
V_27 = F_128 ( V_6 , V_377 ,
sizeof( V_139 -> V_342 . V_202 ) , & V_139 -> V_342 . V_202 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
return V_27 ;
}
static int F_164 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_226 * V_227 ;
struct V_378 * V_139 = V_7 ;
struct V_379 V_380 ;
struct V_127 * V_23 ;
int V_27 ;
F_11 ( L_7 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_381 ,
V_277 ) ;
goto V_255;
}
V_227 = F_156 ( V_6 , V_244 , & V_139 -> V_342 . V_202 ) ;
if ( ! V_227 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_381 ,
V_364 ) ;
goto V_255;
}
if ( V_227 -> V_382 == V_383 && V_139 -> V_345 != 16 ) {
struct V_375 V_384 ;
memcpy ( & V_384 . V_342 , & V_139 -> V_342 , sizeof( V_384 . V_342 ) ) ;
F_150 ( L_14 ) ;
V_27 = F_163 ( V_22 , V_6 , & V_384 ) ;
if ( V_27 >= 0 )
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_381 ,
V_253 ) ;
goto V_255;
}
V_23 = F_79 ( V_22 , V_381 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_255;
}
V_23 -> F_13 = F_108 ;
F_76 ( & V_380 . V_202 , & V_139 -> V_342 . V_202 ) ;
V_380 . V_345 = V_139 -> V_345 ;
memcpy ( V_380 . V_385 , V_139 -> V_385 , sizeof( V_380 . V_385 ) ) ;
V_27 = F_128 ( V_6 , V_386 , sizeof( V_380 ) , & V_380 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_255:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_165 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_387 * V_139 = V_7 ;
F_11 ( L_7 ) ;
if ( V_139 -> V_388 > V_389 )
return F_13 ( V_22 , V_6 -> V_19 , V_390 ,
V_253 , NULL , 0 ) ;
F_32 ( V_6 ) ;
V_6 -> V_388 = V_139 -> V_388 ;
F_11 ( L_15 , V_6 -> V_77 ,
V_6 -> V_388 ) ;
F_33 ( V_6 ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_390 , 0 , NULL ,
0 ) ;
}
static struct V_127 * F_166 ( struct V_226 * V_227 )
{
struct V_5 * V_6 = V_227 -> V_6 ;
struct V_127 * V_23 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
if ( V_23 -> V_17 != V_391 )
continue;
if ( V_23 -> V_128 != V_227 )
continue;
return V_23 ;
}
return NULL ;
}
static int F_167 ( struct V_127 * V_23 , T_1 V_24 )
{
struct V_392 V_29 ;
struct V_226 * V_227 = V_23 -> V_128 ;
int V_27 ;
F_76 ( & V_29 . V_342 . V_202 , & V_227 -> V_246 ) ;
V_29 . V_342 . type = F_161 ( V_227 -> type , V_227 -> V_372 ) ;
V_27 = F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_391 , V_24 ,
& V_29 , sizeof( V_29 ) ) ;
V_227 -> V_393 = NULL ;
V_227 -> V_394 = NULL ;
V_227 -> V_395 = NULL ;
F_168 ( V_227 ) ;
F_65 ( V_353 , & V_227 -> V_151 ) ;
F_169 ( V_227 ) ;
return V_27 ;
}
void F_170 ( struct V_226 * V_227 , bool V_396 )
{
T_1 V_24 = V_396 ? V_266 : V_3 ;
struct V_127 * V_23 ;
V_23 = F_166 ( V_227 ) ;
if ( V_23 ) {
V_23 -> F_13 ( V_23 , V_24 ) ;
F_87 ( V_23 ) ;
}
}
static void F_171 ( struct V_226 * V_227 , T_1 V_24 )
{
struct V_127 * V_23 ;
F_11 ( L_16 , V_24 ) ;
V_23 = F_166 ( V_227 ) ;
if ( ! V_23 ) {
F_11 ( L_17 ) ;
return;
}
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
static void F_172 ( struct V_226 * V_227 , T_1 V_24 )
{
struct V_127 * V_23 ;
F_11 ( L_16 , V_24 ) ;
if ( ! V_24 )
return;
V_23 = F_166 ( V_227 ) ;
if ( ! V_23 ) {
F_11 ( L_17 ) ;
return;
}
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
static int F_173 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_397 * V_139 = V_7 ;
struct V_392 V_29 ;
struct V_127 * V_23 ;
T_1 V_398 , V_399 ;
struct V_226 * V_227 ;
int V_27 ;
F_11 ( L_7 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_342 . V_202 , & V_139 -> V_342 . V_202 ) ;
V_29 . V_342 . type = V_139 -> V_342 . type ;
if ( ! F_155 ( V_139 -> V_342 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_391 ,
V_253 ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_139 -> V_400 > V_389 )
return F_13 ( V_22 , V_6 -> V_19 , V_391 ,
V_253 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_391 ,
V_277 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
V_398 = V_401 ;
V_399 = V_402 ;
if ( V_139 -> V_342 . type == V_343 ) {
V_227 = F_174 ( V_6 , & V_139 -> V_342 . V_202 , V_398 ,
V_399 ) ;
} else {
T_1 V_346 ;
if ( V_139 -> V_342 . type == V_354 )
V_346 = V_355 ;
else
V_346 = V_356 ;
F_175 ( V_6 , & V_139 -> V_342 . V_202 , V_346 ) ;
V_227 = F_176 ( V_6 , & V_139 -> V_342 . V_202 , V_346 ,
V_398 , V_403 ,
V_404 ) ;
}
if ( F_177 ( V_227 ) ) {
int V_24 ;
if ( F_178 ( V_227 ) == - V_405 )
V_24 = V_254 ;
else
V_24 = V_406 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_391 ,
V_24 , & V_29 ,
sizeof( V_29 ) ) ;
goto V_268;
}
if ( V_227 -> V_393 ) {
F_168 ( V_227 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_391 ,
V_254 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_391 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
F_168 ( V_227 ) ;
goto V_268;
}
V_23 -> F_13 = F_167 ;
if ( V_139 -> V_342 . type == V_343 ) {
V_227 -> V_393 = F_171 ;
V_227 -> V_394 = F_171 ;
V_227 -> V_395 = F_171 ;
} else {
V_227 -> V_393 = F_172 ;
V_227 -> V_394 = F_172 ;
V_227 -> V_395 = F_172 ;
}
V_227 -> V_388 = V_139 -> V_400 ;
V_23 -> V_128 = F_179 ( V_227 ) ;
if ( ( V_227 -> V_217 == V_237 || V_227 -> V_217 == V_238 ) &&
F_180 ( V_227 , V_398 , V_399 , true ) ) {
V_23 -> F_13 ( V_23 , 0 ) ;
F_87 ( V_23 ) ;
}
V_27 = 0 ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_181 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_263 * V_342 = V_7 ;
struct V_127 * V_23 ;
struct V_226 * V_227 ;
int V_27 ;
F_11 ( L_7 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_407 ,
V_277 ) ;
goto V_268;
}
V_23 = F_45 ( V_391 , V_6 ) ;
if ( ! V_23 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_407 ,
V_253 ) ;
goto V_268;
}
V_227 = V_23 -> V_128 ;
if ( F_26 ( & V_342 -> V_202 , & V_227 -> V_246 ) != 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_407 ,
V_253 ) ;
goto V_268;
}
V_23 -> F_13 ( V_23 , V_408 ) ;
F_87 ( V_23 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_407 , 0 ,
V_342 , sizeof( * V_342 ) ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_182 ( struct V_9 * V_22 , struct V_5 * V_6 ,
struct V_263 * V_342 , T_2 V_322 ,
T_2 V_409 , T_5 V_410 )
{
struct V_127 * V_23 ;
struct V_226 * V_227 ;
int V_27 ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_322 ,
V_277 , V_342 ,
sizeof( * V_342 ) ) ;
goto V_411;
}
if ( V_342 -> type == V_343 )
V_227 = F_156 ( V_6 , V_244 , & V_342 -> V_202 ) ;
else
V_227 = F_156 ( V_6 , V_184 , & V_342 -> V_202 ) ;
if ( ! V_227 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_322 ,
V_364 , V_342 ,
sizeof( * V_342 ) ) ;
goto V_411;
}
if ( V_342 -> type == V_354 || V_342 -> type == V_367 ) {
V_27 = F_183 ( V_227 , V_322 , V_410 ) ;
if ( ! V_27 )
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_322 ,
V_266 , V_342 ,
sizeof( * V_342 ) ) ;
else
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_322 ,
V_3 , V_342 ,
sizeof( * V_342 ) ) ;
goto V_411;
}
V_23 = F_79 ( V_22 , V_322 , V_6 , V_342 , sizeof( * V_342 ) ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_411;
}
V_23 -> F_13 = F_108 ;
if ( V_409 == V_412 ) {
struct V_413 V_139 ;
F_76 ( & V_139 . V_202 , & V_342 -> V_202 ) ;
V_139 . V_410 = V_410 ;
V_27 = F_128 ( V_6 , V_409 , sizeof( V_139 ) , & V_139 ) ;
} else
V_27 = F_128 ( V_6 , V_409 , sizeof( V_342 -> V_202 ) ,
& V_342 -> V_202 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_411:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_184 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_375 * V_139 = V_7 ;
F_11 ( L_7 ) ;
return F_182 ( V_22 , V_6 , & V_139 -> V_342 ,
V_376 ,
V_377 , 0 ) ;
}
static int F_185 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_414 * V_139 = V_7 ;
F_11 ( L_7 ) ;
if ( V_21 != sizeof( * V_139 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_415 ,
V_253 ) ;
return F_182 ( V_22 , V_6 , & V_139 -> V_342 ,
V_415 ,
V_416 , 0 ) ;
}
static int F_186 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_417 * V_139 = V_7 ;
F_11 ( L_7 ) ;
return F_182 ( V_22 , V_6 , & V_139 -> V_342 ,
V_418 ,
V_419 , 0 ) ;
}
static int F_187 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_420 * V_139 = V_7 ;
F_11 ( L_7 ) ;
return F_182 ( V_22 , V_6 , & V_139 -> V_342 ,
V_421 ,
V_412 , V_139 -> V_410 ) ;
}
static int F_188 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_422 * V_139 = V_7 ;
F_11 ( L_7 ) ;
return F_182 ( V_22 , V_6 , & V_139 -> V_342 ,
V_423 ,
V_424 , 0 ) ;
}
static void F_189 ( struct V_136 * V_137 )
{
struct V_5 * V_6 = V_137 -> V_6 ;
struct V_425 V_139 ;
memcpy ( V_139 . V_77 , V_6 -> V_131 , sizeof( V_139 . V_77 ) ) ;
F_49 ( V_137 , V_426 , sizeof( V_139 ) , & V_139 ) ;
}
static void F_190 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
struct V_427 * V_139 ;
struct V_127 * V_23 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_428 , V_6 ) ;
if ( ! V_23 )
goto V_268;
V_139 = V_23 -> V_146 ;
if ( V_24 )
F_10 ( V_23 -> V_22 , V_6 -> V_19 , V_428 ,
F_1 ( V_24 ) ) ;
else
F_13 ( V_23 -> V_22 , V_6 -> V_19 , V_428 , 0 ,
V_139 , sizeof( * V_139 ) ) ;
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_191 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_427 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
int V_27 ;
F_11 ( L_7 ) ;
F_32 ( V_6 ) ;
if ( ! memcmp ( V_6 -> V_131 , V_139 -> V_77 , sizeof( V_6 -> V_131 ) ) &&
! memcmp ( V_6 -> V_205 , V_139 -> V_205 ,
sizeof( V_6 -> V_205 ) ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_428 , 0 ,
V_7 , V_21 ) ;
goto V_255;
}
memcpy ( V_6 -> V_205 , V_139 -> V_205 , sizeof( V_6 -> V_205 ) ) ;
if ( ! F_40 ( V_6 ) ) {
memcpy ( V_6 -> V_131 , V_139 -> V_77 , sizeof( V_6 -> V_131 ) ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_428 , 0 ,
V_7 , V_21 ) ;
if ( V_27 < 0 )
goto V_255;
V_27 = F_3 ( V_429 , V_6 , V_7 , V_21 ,
V_22 ) ;
goto V_255;
}
V_23 = F_79 ( V_22 , V_428 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_255;
}
memcpy ( V_6 -> V_131 , V_139 -> V_77 , sizeof( V_6 -> V_131 ) ) ;
F_54 ( & V_137 , V_6 ) ;
if ( F_35 ( V_6 ) ) {
F_189 ( & V_137 ) ;
F_57 ( & V_137 ) ;
}
if ( F_38 ( V_6 ) )
F_48 ( & V_137 ) ;
V_27 = F_55 ( & V_137 , F_190 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_255:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_192 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_8 )
{
struct V_127 * V_23 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_430 ,
V_277 ) ;
goto V_268;
}
if ( ! F_36 ( V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_430 ,
V_264 ) ;
goto V_268;
}
if ( F_45 ( V_430 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_430 ,
V_254 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_430 , V_6 , NULL , 0 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
if ( F_193 ( V_6 ) )
V_27 = F_128 ( V_6 , V_431 ,
0 , NULL ) ;
else
V_27 = F_128 ( V_6 , V_432 , 0 , NULL ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_194 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_263 * V_342 = V_7 ;
int V_27 ;
F_11 ( L_18 , V_6 -> V_77 ) ;
if ( ! F_155 ( V_342 -> type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_433 ,
V_253 , V_342 ,
sizeof( * V_342 ) ) ;
F_32 ( V_6 ) ;
if ( V_21 == V_434 ) {
struct V_435 * V_139 = V_7 ;
T_1 V_24 ;
if ( V_139 -> V_342 . type != V_343 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_433 ,
V_253 ,
& V_139 -> V_342 , sizeof( V_139 -> V_342 ) ) ;
goto V_268;
}
V_27 = F_195 ( V_6 , & V_139 -> V_342 . V_202 ,
V_139 -> V_342 . type , V_139 -> V_436 ,
V_139 -> rand , NULL , NULL ) ;
if ( V_27 < 0 )
V_24 = V_3 ;
else
V_24 = V_266 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_433 ,
V_24 , & V_139 -> V_342 , sizeof( V_139 -> V_342 ) ) ;
} else if ( V_21 == V_437 ) {
struct V_438 * V_139 = V_7 ;
T_1 * V_439 , * V_440 , * V_441 , * V_442 ;
T_1 V_24 ;
if ( F_196 ( V_139 -> V_342 . type ) ) {
if ( memcmp ( V_139 -> V_439 , V_443 , 16 ) ||
memcmp ( V_139 -> V_440 , V_443 , 16 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_433 ,
V_253 ,
V_342 , sizeof( * V_342 ) ) ;
goto V_268;
}
V_439 = NULL ;
V_440 = NULL ;
} else {
if ( ! memcmp ( V_139 -> V_439 , V_443 , 16 ) ||
! memcmp ( V_139 -> V_440 , V_443 , 16 ) ) {
V_439 = NULL ;
V_440 = NULL ;
} else {
V_439 = V_139 -> V_439 ;
V_440 = V_139 -> V_440 ;
}
}
if ( ! memcmp ( V_139 -> V_441 , V_443 , 16 ) ||
! memcmp ( V_139 -> V_442 , V_443 , 16 ) ) {
V_441 = NULL ;
V_442 = NULL ;
} else {
V_441 = V_139 -> V_441 ;
V_442 = V_139 -> V_442 ;
}
V_27 = F_195 ( V_6 , & V_139 -> V_342 . V_202 ,
V_139 -> V_342 . type , V_440 , V_439 ,
V_442 , V_441 ) ;
if ( V_27 < 0 )
V_24 = V_3 ;
else
V_24 = V_266 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_433 ,
V_24 , & V_139 -> V_342 , sizeof( V_139 -> V_342 ) ) ;
} else {
F_150 ( L_19 , V_21 ) ;
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_433 ,
V_253 ) ;
}
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_197 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_444 * V_139 = V_7 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( V_139 -> V_342 . type != V_343 )
return F_13 ( V_22 , V_6 -> V_19 , V_445 ,
V_253 ,
& V_139 -> V_342 , sizeof( V_139 -> V_342 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_26 ( & V_139 -> V_342 . V_202 , V_70 ) ) {
F_198 ( V_6 ) ;
V_24 = V_266 ;
goto V_411;
}
V_27 = F_199 ( V_6 , & V_139 -> V_342 . V_202 , V_139 -> V_342 . type ) ;
if ( V_27 < 0 )
V_24 = V_253 ;
else
V_24 = V_266 ;
V_411:
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_445 ,
V_24 , & V_139 -> V_342 , sizeof( V_139 -> V_342 ) ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_200 ( struct V_136 * V_137 , T_1 * V_24 )
{
struct V_5 * V_6 = V_137 -> V_6 ;
struct V_446 V_447 ;
struct V_448 V_449 ;
struct V_450 V_451 ;
T_1 V_452 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
T_1 V_182 ;
int V_27 ;
switch ( V_6 -> V_216 . type ) {
case V_453 :
* V_24 = F_109 ( V_6 ) ;
if ( * V_24 )
return false ;
if ( F_22 ( V_219 , & V_6 -> V_151 ) ) {
* V_24 = V_254 ;
return false ;
}
F_201 ( V_6 ) ;
memset ( & V_451 , 0 , sizeof( V_451 ) ) ;
memcpy ( & V_451 . V_452 , V_452 , sizeof( V_451 . V_452 ) ) ;
V_451 . V_142 = V_454 ;
F_49 ( V_137 , V_455 , sizeof( V_451 ) , & V_451 ) ;
break;
case V_456 :
case V_457 :
* V_24 = F_110 ( V_6 ) ;
if ( * V_24 )
return false ;
if ( V_6 -> V_216 . type == V_457 &&
! F_22 ( V_105 , & V_6 -> V_55 ) ) {
* V_24 = V_264 ;
return false ;
}
if ( F_22 ( V_185 , & V_6 -> V_55 ) ) {
if ( F_202 ( V_6 , V_184 ,
V_242 ) ) {
* V_24 = V_265 ;
return false ;
}
F_62 ( V_137 ) ;
}
if ( F_22 ( V_225 , & V_6 -> V_55 ) )
F_95 ( V_137 ) ;
memset ( & V_447 , 0 , sizeof( V_447 ) ) ;
V_27 = F_66 ( V_137 , true , & V_182 ) ;
if ( V_27 < 0 ) {
* V_24 = V_3 ;
return false ;
}
V_447 . type = V_458 ;
V_447 . V_289 = F_6 ( V_459 ) ;
V_447 . V_291 = F_6 ( V_460 ) ;
V_447 . V_192 = V_182 ;
F_49 ( V_137 , V_461 , sizeof( V_447 ) ,
& V_447 ) ;
memset ( & V_449 , 0 , sizeof( V_449 ) ) ;
V_449 . V_179 = V_462 ;
V_449 . V_463 = V_464 ;
F_49 ( V_137 , V_465 , sizeof( V_449 ) ,
& V_449 ) ;
break;
default:
* V_24 = V_253 ;
return false ;
}
return true ;
}
static void F_203 ( struct V_5 * V_6 , T_1 V_24 ,
T_2 V_17 )
{
struct V_127 * V_23 ;
unsigned long V_276 ;
F_11 ( L_20 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_466 , V_6 ) ;
if ( ! V_23 )
V_23 = F_45 ( V_467 , V_6 ) ;
if ( V_23 ) {
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
if ( V_24 ) {
F_98 ( V_6 , V_468 ) ;
goto V_268;
}
F_98 ( V_6 , V_218 ) ;
switch ( V_6 -> V_216 . type ) {
case V_456 :
V_276 = F_112 ( V_469 ) ;
break;
case V_457 :
V_276 = F_112 ( V_6 -> V_470 ) ;
break;
case V_453 :
V_276 = 0 ;
break;
default:
F_150 ( L_21 , V_6 -> V_216 . type ) ;
V_276 = 0 ;
break;
}
if ( V_276 ) {
if ( F_22 ( V_471 ,
& V_6 -> V_61 ) &&
( V_6 -> V_216 . V_472 > 0 ||
V_6 -> V_216 . V_473 != V_474 ) ) {
V_6 -> V_216 . V_475 = V_476 ;
V_6 -> V_216 . V_477 = V_276 ;
}
F_101 ( V_6 -> V_273 ,
& V_6 -> V_221 , V_276 ) ;
}
V_268:
F_33 ( V_6 ) ;
}
static int F_204 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_478 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_466 ,
V_277 ,
& V_139 -> type , sizeof( V_139 -> type ) ) ;
goto V_255;
}
if ( V_6 -> V_216 . V_217 != V_468 ||
F_22 ( V_479 , & V_6 -> V_55 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_466 ,
V_254 , & V_139 -> type ,
sizeof( V_139 -> type ) ) ;
goto V_255;
}
V_23 = F_79 ( V_22 , V_466 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_255;
}
V_23 -> F_13 = F_107 ;
F_205 ( V_6 ) ;
V_6 -> V_216 . type = V_139 -> type ;
V_6 -> V_216 . V_480 = false ;
F_54 ( & V_137 , V_6 ) ;
if ( ! F_200 ( & V_137 , & V_24 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_466 ,
V_24 , & V_139 -> type , sizeof( V_139 -> type ) ) ;
F_87 ( V_23 ) ;
goto V_255;
}
V_27 = F_55 ( & V_137 , F_203 ) ;
if ( V_27 < 0 ) {
F_87 ( V_23 ) ;
goto V_255;
}
F_98 ( V_6 , V_481 ) ;
V_255:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_206 ( struct V_127 * V_23 , T_1 V_24 )
{
return F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_24 ,
V_23 -> V_146 , 1 ) ;
}
static int F_207 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_482 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
const T_2 V_483 = ( ( V_334 - sizeof( * V_139 ) ) / 16 ) ;
T_2 V_472 , V_337 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_467 ,
V_277 ,
& V_139 -> type , sizeof( V_139 -> type ) ) ;
goto V_255;
}
if ( V_6 -> V_216 . V_217 != V_468 ||
F_22 ( V_479 , & V_6 -> V_55 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_467 ,
V_254 , & V_139 -> type ,
sizeof( V_139 -> type ) ) ;
goto V_255;
}
V_472 = F_115 ( V_139 -> V_472 ) ;
if ( V_472 > V_483 ) {
F_150 ( L_22 ,
V_472 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_467 ,
V_253 , & V_139 -> type ,
sizeof( V_139 -> type ) ) ;
goto V_255;
}
V_337 = sizeof( * V_139 ) + V_472 * 16 ;
if ( V_337 != V_21 ) {
F_150 ( L_23 ,
V_337 , V_21 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_467 ,
V_253 , & V_139 -> type ,
sizeof( V_139 -> type ) ) ;
goto V_255;
}
V_23 = F_79 ( V_22 , V_467 ,
V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_255;
}
V_23 -> F_13 = F_206 ;
F_205 ( V_6 ) ;
V_6 -> V_216 . type = V_139 -> type ;
V_6 -> V_216 . V_473 = V_139 -> V_473 ;
V_6 -> V_216 . V_472 = V_472 ;
if ( V_472 > 0 ) {
V_6 -> V_216 . V_324 = F_81 ( V_139 -> V_324 , V_472 * 16 ,
V_15 ) ;
if ( ! V_6 -> V_216 . V_324 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_467 ,
V_3 ,
& V_139 -> type , sizeof( V_139 -> type ) ) ;
F_87 ( V_23 ) ;
goto V_255;
}
}
F_54 ( & V_137 , V_6 ) ;
if ( ! F_200 ( & V_137 , & V_24 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_467 ,
V_24 , & V_139 -> type , sizeof( V_139 -> type ) ) ;
F_87 ( V_23 ) ;
goto V_255;
}
V_27 = F_55 ( & V_137 , F_203 ) ;
if ( V_27 < 0 ) {
F_87 ( V_23 ) ;
goto V_255;
}
F_98 ( V_6 , V_481 ) ;
V_255:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_208 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
struct V_127 * V_23 ;
F_11 ( L_20 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_484 , V_6 ) ;
if ( V_23 ) {
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
if ( ! V_24 )
F_98 ( V_6 , V_468 ) ;
F_33 ( V_6 ) ;
}
static int F_209 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_485 * V_486 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_210 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_484 ,
V_265 , & V_486 -> type ,
sizeof( V_486 -> type ) ) ;
goto V_268;
}
if ( V_6 -> V_216 . type != V_486 -> type ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_484 ,
V_253 , & V_486 -> type ,
sizeof( V_486 -> type ) ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_484 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
V_23 -> F_13 = F_107 ;
F_54 ( & V_137 , V_6 ) ;
F_94 ( & V_137 ) ;
V_27 = F_55 ( & V_137 , F_208 ) ;
if ( ! V_27 ) {
F_98 ( V_6 , V_251 ) ;
goto V_268;
}
F_87 ( V_23 ) ;
if ( V_27 == - V_259 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_484 , 0 ,
& V_486 -> type , sizeof( V_486 -> type ) ) ;
F_98 ( V_6 , V_468 ) ;
}
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_211 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_487 * V_139 = V_7 ;
struct V_214 * V_215 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_32 ( V_6 ) ;
if ( ! F_210 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_488 ,
V_3 , & V_139 -> V_342 ,
sizeof( V_139 -> V_342 ) ) ;
goto V_255;
}
V_215 = F_212 ( V_6 , & V_139 -> V_342 . V_202 ) ;
if ( ! V_215 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_488 ,
V_253 , & V_139 -> V_342 ,
sizeof( V_139 -> V_342 ) ) ;
goto V_255;
}
if ( V_139 -> V_489 ) {
V_215 -> V_490 = V_491 ;
F_88 ( & V_215 -> V_208 ) ;
} else {
V_215 -> V_490 = V_492 ;
F_213 ( V_6 , V_215 ) ;
}
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_488 , 0 , & V_139 -> V_342 ,
sizeof( V_139 -> V_342 ) ) ;
V_255:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_214 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_493 * V_139 = V_7 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_155 ( V_139 -> V_342 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_494 ,
V_253 ,
& V_139 -> V_342 , sizeof( V_139 -> V_342 ) ) ;
F_32 ( V_6 ) ;
V_27 = F_215 ( & V_6 -> V_495 , & V_139 -> V_342 . V_202 ,
V_139 -> V_342 . type ) ;
if ( V_27 < 0 ) {
V_24 = V_3 ;
goto V_411;
}
F_3 ( V_496 , V_6 , & V_139 -> V_342 , sizeof( V_139 -> V_342 ) ,
V_22 ) ;
V_24 = V_266 ;
V_411:
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_494 , V_24 ,
& V_139 -> V_342 , sizeof( V_139 -> V_342 ) ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_216 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_497 * V_139 = V_7 ;
T_1 V_24 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_155 ( V_139 -> V_342 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_498 ,
V_253 ,
& V_139 -> V_342 , sizeof( V_139 -> V_342 ) ) ;
F_32 ( V_6 ) ;
V_27 = F_217 ( & V_6 -> V_495 , & V_139 -> V_342 . V_202 ,
V_139 -> V_342 . type ) ;
if ( V_27 < 0 ) {
V_24 = V_253 ;
goto V_411;
}
F_3 ( V_499 , V_6 , & V_139 -> V_342 , sizeof( V_139 -> V_342 ) ,
V_22 ) ;
V_24 = V_266 ;
V_411:
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_498 , V_24 ,
& V_139 -> V_342 , sizeof( V_139 -> V_342 ) ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_218 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_500 * V_139 = V_7 ;
struct V_136 V_137 ;
int V_27 ;
T_9 V_501 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
V_501 = F_115 ( V_139 -> V_501 ) ;
if ( V_501 > 0x0002 )
return F_10 ( V_22 , V_6 -> V_19 , V_502 ,
V_253 ) ;
F_32 ( V_6 ) ;
V_6 -> V_162 = V_501 ;
V_6 -> V_164 = F_115 ( V_139 -> V_503 ) ;
V_6 -> V_165 = F_115 ( V_139 -> V_504 ) ;
V_6 -> V_166 = F_115 ( V_139 -> V_34 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_502 , 0 , NULL , 0 ) ;
F_54 ( & V_137 , V_6 ) ;
F_57 ( & V_137 ) ;
F_55 ( & V_137 , NULL ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_219 ( struct V_5 * V_6 , T_1 V_24 ,
T_2 V_17 )
{
struct V_261 V_262 = { NULL , V_6 } ;
F_32 ( V_6 ) ;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
F_84 ( V_314 , V_6 ,
F_105 , & V_269 ) ;
goto V_268;
}
if ( F_22 ( V_185 , & V_6 -> V_55 ) )
F_71 ( V_110 , & V_6 -> V_55 ) ;
else
F_65 ( V_110 , & V_6 -> V_55 ) ;
F_84 ( V_314 , V_6 , F_104 ,
& V_262 ) ;
F_102 ( V_6 , V_262 . V_22 ) ;
if ( V_262 . V_22 )
F_78 ( V_262 . V_22 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_220 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_145 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
T_1 V_147 , V_313 , V_24 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
V_24 = F_110 ( V_6 ) ;
if ( V_24 )
return F_10 ( V_22 , V_6 -> V_19 , V_314 ,
V_24 ) ;
if ( V_139 -> V_147 != 0x00 && V_139 -> V_147 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_314 ,
V_253 ) ;
F_32 ( V_6 ) ;
V_147 = ! ! V_139 -> V_147 ;
V_313 = F_22 ( V_110 , & V_6 -> V_55 ) ;
if ( ! F_40 ( V_6 ) || V_147 == V_313 ||
F_64 ( V_6 , V_184 ) > 0 ||
( F_22 ( V_225 , & V_6 -> V_55 ) &&
V_6 -> V_505 == V_458 ) ) {
bool V_267 = false ;
if ( V_147 != F_22 ( V_110 , & V_6 -> V_55 ) ) {
F_116 ( V_110 , & V_6 -> V_55 ) ;
V_267 = true ;
}
V_27 = F_89 ( V_22 , V_314 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( V_267 )
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_268;
}
if ( F_45 ( V_314 , V_6 ) ||
F_45 ( V_311 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_314 ,
V_254 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_314 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
F_54 ( & V_137 , V_6 ) ;
if ( V_147 )
F_63 ( & V_137 ) ;
else
F_62 ( & V_137 ) ;
V_27 = F_55 ( & V_137 , F_219 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_221 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_506 * V_139 = V_7 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_507 ,
V_264 ) ;
if ( F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_507 ,
V_265 ) ;
if ( F_26 ( & V_139 -> V_202 , V_70 ) ) {
if ( ! F_26 ( & V_139 -> V_202 , V_508 ) )
return F_10 ( V_22 , V_6 -> V_19 ,
V_507 ,
V_253 ) ;
if ( ( V_139 -> V_202 . V_509 [ 5 ] & 0xc0 ) != 0xc0 )
return F_10 ( V_22 , V_6 -> V_19 ,
V_507 ,
V_253 ) ;
}
F_32 ( V_6 ) ;
F_76 ( & V_6 -> V_510 , & V_139 -> V_202 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_507 , 0 , NULL , 0 ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_222 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_511 * V_139 = V_7 ;
T_9 V_289 , V_291 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_512 ,
V_264 ) ;
V_289 = F_115 ( V_139 -> V_289 ) ;
if ( V_289 < 0x0004 || V_289 > 0x4000 )
return F_10 ( V_22 , V_6 -> V_19 , V_512 ,
V_253 ) ;
V_291 = F_115 ( V_139 -> V_291 ) ;
if ( V_291 < 0x0004 || V_291 > 0x4000 )
return F_10 ( V_22 , V_6 -> V_19 , V_512 ,
V_253 ) ;
if ( V_291 > V_289 )
return F_10 ( V_22 , V_6 -> V_19 , V_512 ,
V_253 ) ;
F_32 ( V_6 ) ;
V_6 -> V_513 = V_289 ;
V_6 -> V_514 = V_291 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_512 , 0 , NULL , 0 ) ;
if ( F_22 ( V_225 , & V_6 -> V_55 ) &&
V_6 -> V_216 . V_217 == V_468 ) {
struct V_136 V_137 ;
F_54 ( & V_137 , V_6 ) ;
F_95 ( & V_137 ) ;
F_223 ( & V_137 ) ;
F_55 ( & V_137 , NULL ) ;
}
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_224 ( struct V_5 * V_6 , T_1 V_24 ,
T_2 V_17 )
{
struct V_127 * V_23 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_515 , V_6 ) ;
if ( ! V_23 )
goto V_268;
if ( V_24 ) {
F_10 ( V_23 -> V_22 , V_6 -> V_19 , V_515 ,
F_1 ( V_24 ) ) ;
} else {
struct V_145 * V_139 = V_23 -> V_146 ;
if ( V_139 -> V_147 )
F_71 ( V_102 , & V_6 -> V_55 ) ;
else
F_65 ( V_102 , & V_6 -> V_55 ) ;
F_89 ( V_23 -> V_22 , V_515 , V_6 ) ;
F_102 ( V_6 , V_23 -> V_22 ) ;
}
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_225 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_145 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_22 ( V_105 , & V_6 -> V_55 ) ||
V_6 -> V_89 < V_90 )
return F_10 ( V_22 , V_6 -> V_19 , V_515 ,
V_264 ) ;
if ( V_139 -> V_147 != 0x00 && V_139 -> V_147 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_515 ,
V_253 ) ;
if ( ! F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_515 ,
V_277 ) ;
if ( ! F_22 ( V_101 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_515 ,
V_265 ) ;
F_32 ( V_6 ) ;
if ( F_45 ( V_515 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_515 ,
V_254 ) ;
goto V_268;
}
if ( ! ! V_139 -> V_147 == F_22 ( V_102 , & V_6 -> V_55 ) ) {
V_27 = F_89 ( V_22 , V_515 ,
V_6 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_515 , V_6 ,
V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
F_54 ( & V_137 , V_6 ) ;
F_118 ( & V_137 , V_139 -> V_147 ) ;
V_27 = F_55 ( & V_137 , F_224 ) ;
if ( V_27 < 0 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_515 ,
V_3 ) ;
F_87 ( V_23 ) ;
}
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_226 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
struct V_127 * V_23 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_516 , V_6 ) ;
if ( ! V_23 )
goto V_268;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
F_65 ( V_105 , & V_6 -> V_55 ) ;
F_10 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_269 ) ;
} else {
F_89 ( V_23 -> V_22 , V_516 , V_6 ) ;
F_102 ( V_6 , V_23 -> V_22 ) ;
}
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_227 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 , T_2 V_21 )
{
struct V_145 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_35 ( V_6 ) || ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_516 ,
V_264 ) ;
if ( ! F_22 ( V_106 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_516 ,
V_265 ) ;
if ( V_139 -> V_147 != 0x00 && V_139 -> V_147 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_516 ,
V_253 ) ;
F_32 ( V_6 ) ;
if ( V_139 -> V_147 == F_22 ( V_105 , & V_6 -> V_55 ) ) {
V_27 = F_89 ( V_22 , V_516 , V_6 ) ;
goto V_268;
}
if ( ! F_40 ( V_6 ) ) {
if ( ! V_139 -> V_147 ) {
F_65 ( V_103 , & V_6 -> V_55 ) ;
F_65 ( V_108 , & V_6 -> V_55 ) ;
F_65 ( V_107 , & V_6 -> V_55 ) ;
F_65 ( V_102 , & V_6 -> V_55 ) ;
F_65 ( V_109 , & V_6 -> V_55 ) ;
}
F_116 ( V_105 , & V_6 -> V_55 ) ;
V_27 = F_89 ( V_22 , V_516 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_268;
}
if ( ! V_139 -> V_147 ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_516 ,
V_265 ) ;
goto V_268;
} else {
if ( ! F_22 ( V_105 , & V_6 -> V_55 ) &&
( F_26 ( & V_6 -> V_510 , V_70 ) ||
F_22 ( V_111 , & V_6 -> V_55 ) ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_516 ,
V_265 ) ;
goto V_268;
}
}
if ( F_45 ( V_516 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_516 ,
V_254 ) ;
goto V_268;
}
V_23 = F_79 ( V_22 , V_516 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
F_71 ( V_105 , & V_6 -> V_55 ) ;
F_54 ( & V_137 , V_6 ) ;
F_118 ( & V_137 , false ) ;
F_113 ( & V_137 ) ;
F_52 ( & V_137 ) ;
V_27 = F_55 ( & V_137 , F_226 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_228 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
struct V_127 * V_23 ;
struct V_145 * V_139 ;
F_11 ( L_24 , V_6 -> V_77 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_517 , V_6 ) ;
if ( ! V_23 )
goto V_268;
if ( V_24 ) {
F_10 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 ,
F_1 ( V_24 ) ) ;
goto remove;
}
V_139 = V_23 -> V_146 ;
switch ( V_139 -> V_147 ) {
case 0x00 :
F_65 ( V_111 , & V_6 -> V_55 ) ;
F_65 ( V_518 , & V_6 -> V_55 ) ;
break;
case 0x01 :
F_71 ( V_111 , & V_6 -> V_55 ) ;
F_65 ( V_518 , & V_6 -> V_55 ) ;
break;
case 0x02 :
F_71 ( V_111 , & V_6 -> V_55 ) ;
F_71 ( V_518 , & V_6 -> V_55 ) ;
break;
}
F_89 ( V_23 -> V_22 , V_517 , V_6 ) ;
F_102 ( V_6 , V_23 -> V_22 ) ;
remove:
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_229 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_145 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
T_1 V_147 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_37 ( V_6 ) &&
! F_22 ( V_106 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_517 ,
V_264 ) ;
if ( F_22 ( V_105 , & V_6 -> V_55 ) &&
F_37 ( V_6 ) &&
! F_22 ( V_108 , & V_6 -> V_55 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_517 ,
V_265 ) ;
if ( V_139 -> V_147 != 0x00 && V_139 -> V_147 != 0x01 && V_139 -> V_147 != 0x02 )
return F_10 ( V_22 , V_6 -> V_19 , V_517 ,
V_253 ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) || ! F_37 ( V_6 ) ||
! F_22 ( V_105 , & V_6 -> V_55 ) ) {
bool V_267 ;
if ( V_139 -> V_147 ) {
V_267 = ! F_73 ( V_111 ,
& V_6 -> V_55 ) ;
if ( V_139 -> V_147 == 0x02 )
F_71 ( V_518 , & V_6 -> V_55 ) ;
else
F_65 ( V_518 , & V_6 -> V_55 ) ;
} else {
V_267 = F_69 ( V_111 ,
& V_6 -> V_55 ) ;
F_65 ( V_518 , & V_6 -> V_55 ) ;
}
V_27 = F_89 ( V_22 , V_517 , V_6 ) ;
if ( V_27 < 0 )
goto V_255;
if ( V_267 )
V_27 = F_102 ( V_6 , V_22 ) ;
goto V_255;
}
if ( F_45 ( V_517 , V_6 ) ) {
V_27 = F_10 ( V_22 , V_6 -> V_19 , V_517 ,
V_254 ) ;
goto V_255;
}
V_147 = ! ! V_139 -> V_147 ;
if ( V_147 == F_22 ( V_111 , & V_6 -> V_55 ) &&
( V_139 -> V_147 == 0x02 ) == F_22 ( V_518 , & V_6 -> V_55 ) ) {
V_27 = F_89 ( V_22 , V_517 , V_6 ) ;
goto V_255;
}
V_23 = F_79 ( V_22 , V_517 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_255;
}
F_54 ( & V_137 , V_6 ) ;
F_49 ( & V_137 , V_519 , 1 , & V_147 ) ;
V_27 = F_55 ( & V_137 , F_228 ) ;
if ( V_27 < 0 ) {
F_87 ( V_23 ) ;
goto V_255;
}
V_255:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_230 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_145 * V_139 = V_7 ;
bool V_267 , V_520 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( V_139 -> V_147 != 0x00 && V_139 -> V_147 != 0x01 && V_139 -> V_147 != 0x02 )
return F_10 ( V_22 , V_6 -> V_19 , V_521 ,
V_253 ) ;
F_32 ( V_6 ) ;
if ( V_139 -> V_147 )
V_267 = ! F_73 ( V_112 ,
& V_6 -> V_55 ) ;
else
V_267 = F_69 ( V_112 ,
& V_6 -> V_55 ) ;
if ( V_139 -> V_147 == 0x02 )
V_520 = ! F_73 ( V_308 ,
& V_6 -> V_55 ) ;
else
V_520 = F_69 ( V_308 ,
& V_6 -> V_55 ) ;
if ( F_40 ( V_6 ) && V_520 &&
F_22 ( V_108 , & V_6 -> V_55 ) ) {
T_1 V_522 = ( V_139 -> V_147 == 0x02 ) ? 0x01 : 0x00 ;
F_128 ( V_6 , V_309 ,
sizeof( V_522 ) , & V_522 ) ;
}
V_27 = F_89 ( V_22 , V_521 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( V_267 )
V_27 = F_102 ( V_6 , V_22 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_231 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_523 ,
T_2 V_21 )
{
struct V_524 * V_139 = V_523 ;
bool V_267 ;
int V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_525 ,
V_264 ) ;
if ( V_139 -> V_526 != 0x00 && V_139 -> V_526 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_525 ,
V_253 ) ;
if ( F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_525 ,
V_265 ) ;
F_32 ( V_6 ) ;
F_71 ( V_527 , & V_6 -> V_55 ) ;
if ( V_139 -> V_526 ) {
V_267 = ! F_73 ( V_113 , & V_6 -> V_55 ) ;
memcpy ( V_6 -> V_528 , V_139 -> V_528 , sizeof( V_6 -> V_528 ) ) ;
F_71 ( V_199 , & V_6 -> V_55 ) ;
} else {
V_267 = F_69 ( V_113 , & V_6 -> V_55 ) ;
memset ( V_6 -> V_528 , 0 , sizeof( V_6 -> V_528 ) ) ;
F_65 ( V_199 , & V_6 -> V_55 ) ;
}
V_27 = F_89 ( V_22 , V_525 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( V_267 )
V_27 = F_102 ( V_6 , V_22 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_232 ( struct V_529 * V_528 )
{
switch ( V_528 -> V_342 . type ) {
case V_354 :
return true ;
case V_367 :
if ( ( V_528 -> V_342 . V_202 . V_509 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_233 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_523 ,
T_2 V_21 )
{
struct V_530 * V_139 = V_523 ;
const T_2 V_531 = ( ( V_334 - sizeof( * V_139 ) ) /
sizeof( struct V_529 ) ) ;
T_2 V_532 , V_337 ;
int V_45 , V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_533 ,
V_264 ) ;
V_532 = F_115 ( V_139 -> V_532 ) ;
if ( V_532 > V_531 ) {
F_150 ( L_25 , V_532 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_533 ,
V_253 ) ;
}
V_337 = sizeof( * V_139 ) + V_532 * sizeof( struct V_529 ) ;
if ( V_337 != V_21 ) {
F_150 ( L_26 ,
V_337 , V_21 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_533 ,
V_253 ) ;
}
F_11 ( L_27 , V_6 -> V_77 , V_532 ) ;
for ( V_45 = 0 ; V_45 < V_532 ; V_45 ++ ) {
struct V_529 * V_340 = & V_139 -> V_534 [ V_45 ] ;
if ( ! F_232 ( V_340 ) )
return F_10 ( V_22 , V_6 -> V_19 ,
V_533 ,
V_253 ) ;
}
F_32 ( V_6 ) ;
F_234 ( V_6 ) ;
for ( V_45 = 0 ; V_45 < V_532 ; V_45 ++ ) {
struct V_529 * V_528 = & V_139 -> V_534 [ V_45 ] ;
T_1 V_346 ;
if ( V_528 -> V_342 . type == V_354 )
V_346 = V_355 ;
else
V_346 = V_356 ;
F_235 ( V_6 , & V_528 -> V_342 . V_202 , V_346 , V_528 -> V_147 ,
V_70 ) ;
}
F_71 ( V_527 , & V_6 -> V_55 ) ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_533 , 0 , NULL , 0 ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_236 ( struct V_535 * V_340 )
{
if ( V_340 -> V_536 != 0x00 && V_340 -> V_536 != 0x01 )
return false ;
switch ( V_340 -> V_342 . type ) {
case V_354 :
return true ;
case V_367 :
if ( ( V_340 -> V_342 . V_202 . V_509 [ 5 ] & 0xc0 ) != 0xc0 )
return false ;
return true ;
}
return false ;
}
static int F_237 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_523 , T_2 V_21 )
{
struct V_537 * V_139 = V_523 ;
const T_2 V_333 = ( ( V_334 - sizeof( * V_139 ) ) /
sizeof( struct V_535 ) ) ;
T_2 V_336 , V_337 ;
int V_45 , V_27 ;
F_11 ( L_9 , V_6 -> V_77 ) ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_538 ,
V_264 ) ;
V_336 = F_115 ( V_139 -> V_336 ) ;
if ( V_336 > V_333 ) {
F_150 ( L_28 , V_336 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_538 ,
V_253 ) ;
}
V_337 = sizeof( * V_139 ) + V_336 *
sizeof( struct V_535 ) ;
if ( V_337 != V_21 ) {
F_150 ( L_29 ,
V_337 , V_21 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_538 ,
V_253 ) ;
}
F_11 ( L_30 , V_6 -> V_77 , V_336 ) ;
for ( V_45 = 0 ; V_45 < V_336 ; V_45 ++ ) {
struct V_535 * V_340 = & V_139 -> V_341 [ V_45 ] ;
if ( ! F_236 ( V_340 ) )
return F_10 ( V_22 , V_6 -> V_19 ,
V_538 ,
V_253 ) ;
}
F_32 ( V_6 ) ;
F_238 ( V_6 ) ;
for ( V_45 = 0 ; V_45 < V_336 ; V_45 ++ ) {
struct V_535 * V_340 = & V_139 -> V_341 [ V_45 ] ;
T_1 type , V_346 , V_539 ;
if ( V_340 -> V_342 . type == V_354 )
V_346 = V_355 ;
else
V_346 = V_356 ;
switch ( V_340 -> type ) {
case V_540 :
V_539 = 0x00 ;
type = V_340 -> V_536 ? V_541 : V_542 ;
break;
case V_543 :
V_539 = 0x01 ;
type = V_340 -> V_536 ? V_541 : V_542 ;
break;
case V_544 :
V_539 = 0x00 ;
type = V_545 ;
break;
case V_546 :
V_539 = 0x01 ;
type = V_545 ;
break;
case V_547 :
V_539 = 0x00 ;
type = V_548 ;
default:
continue;
}
F_239 ( V_6 , & V_340 -> V_342 . V_202 , V_346 , type ,
V_539 , V_340 -> V_147 , V_340 -> V_549 , V_340 -> V_550 ,
V_340 -> rand ) ;
}
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_538 , 0 ,
NULL , 0 ) ;
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_240 ( struct V_127 * V_23 , T_1 V_24 )
{
struct V_226 * V_227 = V_23 -> V_128 ;
struct V_551 V_29 ;
int V_27 ;
memcpy ( & V_29 . V_342 , V_23 -> V_146 , sizeof( V_29 . V_342 ) ) ;
if ( V_24 == V_266 ) {
V_29 . V_473 = V_227 -> V_473 ;
V_29 . V_552 = V_227 -> V_552 ;
V_29 . V_553 = V_227 -> V_553 ;
} else {
V_29 . V_473 = V_474 ;
V_29 . V_552 = V_155 ;
V_29 . V_553 = V_155 ;
}
V_27 = F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_554 , V_24 ,
& V_29 , sizeof( V_29 ) ) ;
F_168 ( V_227 ) ;
F_169 ( V_227 ) ;
return V_27 ;
}
static void F_241 ( struct V_5 * V_6 , T_1 V_1 ,
T_2 V_17 )
{
struct V_555 * V_139 ;
struct V_127 * V_23 ;
struct V_226 * V_227 ;
T_2 V_239 ;
T_1 V_24 ;
F_11 ( L_10 , V_1 ) ;
F_32 ( V_6 ) ;
V_139 = F_242 ( V_6 , V_556 ) ;
if ( ! V_139 ) {
V_139 = F_242 ( V_6 , V_557 ) ;
V_24 = V_266 ;
} else {
V_24 = F_1 ( V_1 ) ;
}
if ( ! V_139 ) {
F_150 ( L_31 ) ;
goto V_268;
}
V_239 = F_115 ( V_139 -> V_239 ) ;
V_227 = F_243 ( V_6 , V_239 ) ;
if ( ! V_227 ) {
F_150 ( L_32 , V_239 ) ;
goto V_268;
}
V_23 = F_46 ( V_554 , V_6 , V_227 ) ;
if ( ! V_23 )
goto V_268;
V_23 -> F_13 ( V_23 , V_24 ) ;
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_244 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_558 * V_139 = V_7 ;
struct V_551 V_29 ;
struct V_226 * V_227 ;
unsigned long V_559 ;
int V_27 = 0 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_342 . V_202 , & V_139 -> V_342 . V_202 ) ;
V_29 . V_342 . type = V_139 -> V_342 . type ;
if ( ! F_155 ( V_139 -> V_342 . type ) )
return F_13 ( V_22 , V_6 -> V_19 , V_554 ,
V_253 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_554 ,
V_277 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
if ( V_139 -> V_342 . type == V_343 )
V_227 = F_156 ( V_6 , V_244 ,
& V_139 -> V_342 . V_202 ) ;
else
V_227 = F_156 ( V_6 , V_184 , & V_139 -> V_342 . V_202 ) ;
if ( ! V_227 || V_227 -> V_217 != V_237 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_554 ,
V_364 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
if ( F_46 ( V_554 , V_6 , V_227 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_554 ,
V_254 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
V_559 = V_6 -> V_560 +
F_245 ( V_6 -> V_561 -
V_6 -> V_560 ) ;
if ( F_246 ( V_476 , V_227 -> V_562 +
F_112 ( V_559 ) ) ||
! V_227 -> V_562 ) {
struct V_136 V_137 ;
struct V_563 V_564 ;
struct V_555 V_565 ;
struct V_127 * V_23 ;
F_54 ( & V_137 , V_6 ) ;
V_565 . V_239 = F_6 ( V_227 -> V_239 ) ;
F_49 ( & V_137 , V_556 , sizeof( V_565 ) ,
& V_565 ) ;
if ( ! F_196 ( V_139 -> V_342 . type ) ||
V_227 -> V_552 == V_155 ) {
V_564 . V_239 = F_6 ( V_227 -> V_239 ) ;
V_564 . type = 0x00 ;
F_49 ( & V_137 , V_557 ,
sizeof( V_564 ) , & V_564 ) ;
}
if ( V_227 -> V_553 == V_155 ) {
V_564 . V_239 = F_6 ( V_227 -> V_239 ) ;
V_564 . type = 0x01 ;
F_49 ( & V_137 , V_557 ,
sizeof( V_564 ) , & V_564 ) ;
}
V_27 = F_55 ( & V_137 , F_241 ) ;
if ( V_27 < 0 )
goto V_268;
V_23 = F_79 ( V_22 , V_554 , V_6 ,
V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
F_247 ( V_227 ) ;
V_23 -> V_128 = F_179 ( V_227 ) ;
V_23 -> F_13 = F_240 ;
V_227 -> V_562 = V_476 ;
} else {
V_29 . V_473 = V_227 -> V_473 ;
V_29 . V_552 = V_227 -> V_552 ;
V_29 . V_553 = V_227 -> V_553 ;
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_554 ,
V_266 , & V_29 , sizeof( V_29 ) ) ;
}
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_248 ( struct V_127 * V_23 , T_1 V_24 )
{
struct V_226 * V_227 = V_23 -> V_128 ;
struct V_566 V_29 ;
struct V_5 * V_6 ;
int V_27 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
memcpy ( & V_29 . V_342 , & V_23 -> V_146 , sizeof( V_29 . V_342 ) ) ;
if ( V_24 )
goto V_396;
V_6 = F_249 ( V_23 -> V_18 ) ;
if ( V_6 ) {
V_29 . V_567 = F_28 ( V_6 -> clock ) ;
F_250 ( V_6 ) ;
}
if ( V_227 ) {
V_29 . V_568 = F_28 ( V_227 -> clock ) ;
V_29 . V_569 = F_6 ( V_227 -> V_570 ) ;
}
V_396:
V_27 = F_13 ( V_23 -> V_22 , V_23 -> V_18 , V_23 -> V_17 , V_24 , & V_29 ,
sizeof( V_29 ) ) ;
if ( V_227 ) {
F_168 ( V_227 ) ;
F_169 ( V_227 ) ;
}
return V_27 ;
}
static void F_251 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
struct V_571 * V_281 ;
struct V_127 * V_23 ;
struct V_226 * V_227 ;
F_11 ( L_24 , V_6 -> V_77 , V_24 ) ;
F_32 ( V_6 ) ;
V_281 = F_242 ( V_6 , V_572 ) ;
if ( ! V_281 )
goto V_268;
if ( V_281 -> V_573 ) {
T_2 V_239 = F_115 ( V_281 -> V_239 ) ;
V_227 = F_243 ( V_6 , V_239 ) ;
} else {
V_227 = NULL ;
}
V_23 = F_46 ( V_574 , V_6 , V_227 ) ;
if ( ! V_23 )
goto V_268;
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_252 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_575 * V_139 = V_7 ;
struct V_566 V_29 ;
struct V_571 V_281 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
struct V_226 * V_227 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_76 ( & V_29 . V_342 . V_202 , & V_139 -> V_342 . V_202 ) ;
V_29 . V_342 . type = V_139 -> V_342 . type ;
if ( V_139 -> V_342 . type != V_343 )
return F_13 ( V_22 , V_6 -> V_19 , V_574 ,
V_253 ,
& V_29 , sizeof( V_29 ) ) ;
F_32 ( V_6 ) ;
if ( ! F_40 ( V_6 ) ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 , V_574 ,
V_277 , & V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
if ( F_26 ( & V_139 -> V_342 . V_202 , V_70 ) ) {
V_227 = F_156 ( V_6 , V_244 ,
& V_139 -> V_342 . V_202 ) ;
if ( ! V_227 || V_227 -> V_217 != V_237 ) {
V_27 = F_13 ( V_22 , V_6 -> V_19 ,
V_574 ,
V_364 ,
& V_29 , sizeof( V_29 ) ) ;
goto V_268;
}
} else {
V_227 = NULL ;
}
V_23 = F_79 ( V_22 , V_574 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
V_23 -> F_13 = F_248 ;
F_54 ( & V_137 , V_6 ) ;
memset ( & V_281 , 0 , sizeof( V_281 ) ) ;
F_49 ( & V_137 , V_572 , sizeof( V_281 ) , & V_281 ) ;
if ( V_227 ) {
F_247 ( V_227 ) ;
V_23 -> V_128 = F_179 ( V_227 ) ;
V_281 . V_239 = F_6 ( V_227 -> V_239 ) ;
V_281 . V_573 = 0x01 ;
F_49 ( & V_137 , V_572 , sizeof( V_281 ) , & V_281 ) ;
}
V_27 = F_55 ( & V_137 , F_251 ) ;
if ( V_27 < 0 )
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static bool F_253 ( struct V_5 * V_6 , T_8 * V_342 , T_1 type )
{
struct V_226 * V_227 ;
V_227 = F_156 ( V_6 , V_184 , V_342 ) ;
if ( ! V_227 )
return false ;
if ( V_227 -> V_372 != type )
return false ;
if ( V_227 -> V_217 != V_237 )
return false ;
return true ;
}
static int F_254 ( struct V_136 * V_137 , T_8 * V_342 ,
T_1 V_346 , T_1 V_576 )
{
struct V_5 * V_6 = V_137 -> V_6 ;
struct V_577 * V_578 ;
V_578 = F_175 ( V_6 , V_342 , V_346 ) ;
if ( ! V_578 )
return - V_579 ;
if ( V_578 -> V_576 == V_576 )
return 0 ;
F_255 ( & V_578 -> V_580 ) ;
switch ( V_576 ) {
case V_581 :
case V_582 :
F_132 ( V_137 ) ;
break;
case V_583 :
F_83 ( & V_578 -> V_580 , & V_6 -> V_584 ) ;
F_132 ( V_137 ) ;
break;
case V_585 :
case V_586 :
if ( ! F_253 ( V_6 , V_342 , V_346 ) ) {
F_83 ( & V_578 -> V_580 , & V_6 -> V_587 ) ;
F_132 ( V_137 ) ;
}
break;
}
V_578 -> V_576 = V_576 ;
F_11 ( L_33 , V_342 , V_346 ,
V_576 ) ;
return 0 ;
}
static void F_256 ( struct V_9 * V_22 , struct V_5 * V_6 ,
T_8 * V_202 , T_1 type , T_1 V_580 )
{
struct V_588 V_26 ;
F_76 ( & V_26 . V_342 . V_202 , V_202 ) ;
V_26 . V_342 . type = type ;
V_26 . V_580 = V_580 ;
F_3 ( V_589 , V_6 , & V_26 , sizeof( V_26 ) , V_22 ) ;
}
static void F_257 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
struct V_127 * V_23 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_590 , V_6 ) ;
if ( ! V_23 )
goto V_268;
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_258 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_591 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
T_1 V_592 , V_346 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( ! F_155 ( V_139 -> V_342 . type ) ||
! F_26 ( & V_139 -> V_342 . V_202 , V_70 ) )
return F_13 ( V_22 , V_6 -> V_19 , V_590 ,
V_253 ,
& V_139 -> V_342 , sizeof( V_139 -> V_342 ) ) ;
if ( V_139 -> V_580 != 0x00 && V_139 -> V_580 != 0x01 && V_139 -> V_580 != 0x02 )
return F_13 ( V_22 , V_6 -> V_19 , V_590 ,
V_253 ,
& V_139 -> V_342 , sizeof( V_139 -> V_342 ) ) ;
F_54 ( & V_137 , V_6 ) ;
F_32 ( V_6 ) ;
V_23 = F_79 ( V_22 , V_590 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
V_23 -> F_13 = F_108 ;
if ( V_139 -> V_342 . type == V_343 ) {
if ( V_139 -> V_580 != 0x01 ) {
V_27 = V_23 -> F_13 ( V_23 ,
V_253 ) ;
F_87 ( V_23 ) ;
goto V_268;
}
V_27 = F_215 ( & V_6 -> V_299 , & V_139 -> V_342 . V_202 ,
V_139 -> V_342 . type ) ;
if ( V_27 )
goto V_268;
F_113 ( & V_137 ) ;
goto V_593;
}
if ( V_139 -> V_342 . type == V_354 )
V_346 = V_355 ;
else
V_346 = V_356 ;
if ( V_139 -> V_580 == 0x02 )
V_592 = V_586 ;
else if ( V_139 -> V_580 == 0x01 )
V_592 = V_585 ;
else
V_592 = V_583 ;
if ( F_254 ( & V_137 , & V_139 -> V_342 . V_202 , V_346 ,
V_592 ) < 0 ) {
V_27 = V_23 -> F_13 ( V_23 , V_3 ) ;
F_87 ( V_23 ) ;
goto V_268;
}
V_593:
F_256 ( V_22 , V_6 , & V_139 -> V_342 . V_202 , V_139 -> V_342 . type , V_139 -> V_580 ) ;
V_27 = F_55 ( & V_137 , F_257 ) ;
if ( V_27 < 0 ) {
if ( V_27 == - V_259 )
V_27 = V_23 -> F_13 ( V_23 , V_266 ) ;
F_87 ( V_23 ) ;
}
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static void F_259 ( struct V_9 * V_22 , struct V_5 * V_6 ,
T_8 * V_202 , T_1 type )
{
struct V_594 V_26 ;
F_76 ( & V_26 . V_342 . V_202 , V_202 ) ;
V_26 . V_342 . type = type ;
F_3 ( V_595 , V_6 , & V_26 , sizeof( V_26 ) , V_22 ) ;
}
static void F_260 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
struct V_127 * V_23 ;
F_11 ( L_10 , V_24 ) ;
F_32 ( V_6 ) ;
V_23 = F_45 ( V_596 , V_6 ) ;
if ( ! V_23 )
goto V_268;
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
V_268:
F_33 ( V_6 ) ;
}
static int F_261 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_597 * V_139 = V_7 ;
struct V_127 * V_23 ;
struct V_136 V_137 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_54 ( & V_137 , V_6 ) ;
F_32 ( V_6 ) ;
V_23 = F_79 ( V_22 , V_596 , V_6 , V_7 , V_21 ) ;
if ( ! V_23 ) {
V_27 = - V_16 ;
goto V_268;
}
V_23 -> F_13 = F_108 ;
if ( F_26 ( & V_139 -> V_342 . V_202 , V_70 ) ) {
struct V_577 * V_578 ;
T_1 V_346 ;
if ( ! F_155 ( V_139 -> V_342 . type ) ) {
V_27 = V_23 -> F_13 ( V_23 ,
V_253 ) ;
F_87 ( V_23 ) ;
goto V_268;
}
if ( V_139 -> V_342 . type == V_343 ) {
V_27 = F_217 ( & V_6 -> V_299 ,
& V_139 -> V_342 . V_202 ,
V_139 -> V_342 . type ) ;
if ( V_27 ) {
V_27 = V_23 -> F_13 ( V_23 ,
V_253 ) ;
F_87 ( V_23 ) ;
goto V_268;
}
F_113 ( & V_137 ) ;
F_259 ( V_22 , V_6 , & V_139 -> V_342 . V_202 ,
V_139 -> V_342 . type ) ;
goto V_396;
}
if ( V_139 -> V_342 . type == V_354 )
V_346 = V_355 ;
else
V_346 = V_356 ;
V_578 = F_262 ( V_6 , & V_139 -> V_342 . V_202 ,
V_346 ) ;
if ( ! V_578 ) {
V_27 = V_23 -> F_13 ( V_23 ,
V_253 ) ;
F_87 ( V_23 ) ;
goto V_268;
}
if ( V_578 -> V_576 == V_581 ) {
V_27 = V_23 -> F_13 ( V_23 ,
V_253 ) ;
F_87 ( V_23 ) ;
goto V_268;
}
F_88 ( & V_578 -> V_580 ) ;
F_88 ( & V_578 -> V_208 ) ;
F_18 ( V_578 ) ;
F_132 ( & V_137 ) ;
F_259 ( V_22 , V_6 , & V_139 -> V_342 . V_202 , V_139 -> V_342 . type ) ;
} else {
struct V_577 * V_598 , * V_210 ;
struct V_599 * V_509 , * V_600 ;
if ( V_139 -> V_342 . type ) {
V_27 = V_23 -> F_13 ( V_23 ,
V_253 ) ;
F_87 ( V_23 ) ;
goto V_268;
}
F_86 (b, btmp, &hdev->whitelist, list) {
F_259 ( V_22 , V_6 , & V_509 -> V_202 , V_509 -> V_601 ) ;
F_88 ( & V_509 -> V_208 ) ;
F_18 ( V_509 ) ;
}
F_113 ( & V_137 ) ;
F_86 (p, tmp, &hdev->le_conn_params, list) {
if ( V_598 -> V_576 == V_581 )
continue;
F_259 ( V_22 , V_6 , & V_598 -> V_342 , V_598 -> V_346 ) ;
F_88 ( & V_598 -> V_580 ) ;
F_88 ( & V_598 -> V_208 ) ;
F_18 ( V_598 ) ;
}
F_11 ( L_34 ) ;
F_132 ( & V_137 ) ;
}
V_396:
V_27 = F_55 ( & V_137 , F_260 ) ;
if ( V_27 < 0 ) {
if ( V_27 == - V_259 )
V_27 = V_23 -> F_13 ( V_23 , V_266 ) ;
F_87 ( V_23 ) ;
}
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_263 ( struct V_9 * V_22 , struct V_5 * V_6 , void * V_7 ,
T_2 V_21 )
{
struct V_602 * V_139 = V_7 ;
const T_2 V_603 = ( ( V_334 - sizeof( * V_139 ) ) /
sizeof( struct V_604 ) ) ;
T_2 V_605 , V_337 ;
int V_45 ;
if ( ! F_38 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_606 ,
V_264 ) ;
V_605 = F_115 ( V_139 -> V_605 ) ;
if ( V_605 > V_603 ) {
F_150 ( L_35 ,
V_605 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_606 ,
V_253 ) ;
}
V_337 = sizeof( * V_139 ) + V_605 *
sizeof( struct V_604 ) ;
if ( V_337 != V_21 ) {
F_150 ( L_36 ,
V_337 , V_21 ) ;
return F_10 ( V_22 , V_6 -> V_19 , V_606 ,
V_253 ) ;
}
F_11 ( L_37 , V_6 -> V_77 , V_605 ) ;
F_32 ( V_6 ) ;
F_264 ( V_6 ) ;
for ( V_45 = 0 ; V_45 < V_605 ; V_45 ++ ) {
struct V_604 * V_146 = & V_139 -> V_578 [ V_45 ] ;
struct V_577 * V_607 ;
T_2 V_608 , V_609 , V_610 , V_276 ;
T_1 V_346 ;
F_11 ( L_38 , & V_146 -> V_342 . V_202 ,
V_146 -> V_342 . type ) ;
if ( V_146 -> V_342 . type == V_354 ) {
V_346 = V_355 ;
} else if ( V_146 -> V_342 . type == V_367 ) {
V_346 = V_356 ;
} else {
F_150 ( L_39 ) ;
continue;
}
V_608 = F_265 ( V_146 -> V_186 ) ;
V_609 = F_265 ( V_146 -> V_188 ) ;
V_610 = F_265 ( V_146 -> V_610 ) ;
V_276 = F_265 ( V_146 -> V_276 ) ;
F_11 ( L_40 ,
V_608 , V_609 , V_610 , V_276 ) ;
if ( F_266 ( V_608 , V_609 , V_610 , V_276 ) < 0 ) {
F_150 ( L_39 ) ;
continue;
}
V_607 = F_175 ( V_6 , & V_146 -> V_342 . V_202 ,
V_346 ) ;
if ( ! V_607 ) {
F_150 ( L_41 ) ;
continue;
}
V_607 -> V_611 = V_608 ;
V_607 -> V_612 = V_609 ;
V_607 -> V_613 = V_610 ;
V_607 -> V_614 = V_276 ;
}
F_33 ( V_6 ) ;
return F_13 ( V_22 , V_6 -> V_19 , V_606 , 0 , NULL , 0 ) ;
}
static int F_267 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_615 * V_139 = V_7 ;
bool V_267 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_616 ,
V_265 ) ;
if ( V_139 -> V_617 != 0x00 && V_139 -> V_617 != 0x01 )
return F_10 ( V_22 , V_6 -> V_19 , V_616 ,
V_253 ) ;
if ( ! F_22 ( V_66 , & V_6 -> V_61 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_616 ,
V_264 ) ;
F_32 ( V_6 ) ;
if ( V_139 -> V_617 )
V_267 = ! F_73 ( V_67 ,
& V_6 -> V_55 ) ;
else
V_267 = F_69 ( V_67 ,
& V_6 -> V_55 ) ;
V_27 = F_30 ( V_22 , V_616 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( ! V_267 )
goto V_268;
V_27 = F_29 ( V_6 , V_22 ) ;
if ( F_22 ( V_54 , & V_6 -> V_55 ) == F_25 ( V_6 ) ) {
F_268 ( V_6 ) ;
if ( F_269 ( V_54 , & V_6 -> V_55 ) ) {
F_71 ( V_58 , & V_6 -> V_55 ) ;
F_71 ( V_256 , & V_6 -> V_55 ) ;
F_93 ( V_6 -> V_212 , & V_6 -> V_257 ) ;
} else {
F_71 ( V_618 , & V_6 -> V_151 ) ;
F_270 ( V_6 ) ;
}
}
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
static int F_271 ( struct V_9 * V_22 , struct V_5 * V_6 ,
void * V_7 , T_2 V_21 )
{
struct V_619 * V_139 = V_7 ;
bool V_267 ;
int V_27 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
if ( F_40 ( V_6 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_620 ,
V_265 ) ;
if ( ! F_26 ( & V_139 -> V_202 , V_70 ) )
return F_10 ( V_22 , V_6 -> V_19 , V_620 ,
V_253 ) ;
if ( ! V_6 -> V_79 )
return F_10 ( V_22 , V_6 -> V_19 , V_620 ,
V_264 ) ;
F_32 ( V_6 ) ;
V_267 = ! ! F_26 ( & V_6 -> V_69 , & V_139 -> V_202 ) ;
F_76 ( & V_6 -> V_69 , & V_139 -> V_202 ) ;
V_27 = F_30 ( V_22 , V_620 , V_6 ) ;
if ( V_27 < 0 )
goto V_268;
if ( ! V_267 )
goto V_268;
if ( F_22 ( V_54 , & V_6 -> V_55 ) )
V_27 = F_29 ( V_6 , V_22 ) ;
if ( F_25 ( V_6 ) ) {
F_268 ( V_6 ) ;
F_65 ( V_54 , & V_6 -> V_55 ) ;
F_71 ( V_58 , & V_6 -> V_55 ) ;
F_71 ( V_256 , & V_6 -> V_55 ) ;
F_93 ( V_6 -> V_212 , & V_6 -> V_257 ) ;
}
V_268:
F_33 ( V_6 ) ;
return V_27 ;
}
int F_272 ( struct V_9 * V_22 , struct V_621 * V_622 , T_3 V_623 )
{
void * V_624 ;
T_1 * V_139 ;
struct V_13 * V_14 ;
T_2 V_17 , V_18 , V_21 ;
struct V_5 * V_6 = NULL ;
const struct V_625 * V_626 ;
int V_27 ;
F_11 ( L_42 , V_623 ) ;
if ( V_623 < sizeof( * V_14 ) )
return - V_627 ;
V_624 = F_16 ( V_623 , V_15 ) ;
if ( ! V_624 )
return - V_16 ;
if ( F_273 ( V_624 , V_622 , V_623 ) ) {
V_27 = - V_628 ;
goto V_411;
}
V_14 = V_624 ;
V_17 = F_115 ( V_14 -> V_17 ) ;
V_18 = F_115 ( V_14 -> V_18 ) ;
V_21 = F_115 ( V_14 -> V_21 ) ;
if ( V_21 != V_623 - sizeof( * V_14 ) ) {
V_27 = - V_627 ;
goto V_411;
}
if ( V_18 != V_20 ) {
V_6 = F_249 ( V_18 ) ;
if ( ! V_6 ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_629 ) ;
goto V_411;
}
if ( F_22 ( V_57 , & V_6 -> V_55 ) ||
F_22 ( V_58 , & V_6 -> V_55 ) ||
F_22 ( V_59 , & V_6 -> V_55 ) ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_629 ) ;
goto V_411;
}
if ( F_22 ( V_54 , & V_6 -> V_55 ) &&
V_17 != V_82 &&
V_17 != V_616 &&
V_17 != V_620 ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_629 ) ;
goto V_411;
}
}
if ( V_17 >= F_2 ( V_630 ) ||
V_630 [ V_17 ] . V_631 == NULL ) {
F_11 ( L_43 , V_17 ) ;
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_632 ) ;
goto V_411;
}
if ( V_6 && ( V_17 <= V_63 ||
V_17 == V_65 ) ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_629 ) ;
goto V_411;
}
if ( ! V_6 && ( V_17 > V_63 &&
V_17 != V_65 ) ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_629 ) ;
goto V_411;
}
V_626 = & V_630 [ V_17 ] ;
if ( ( V_626 -> V_633 && V_21 < V_626 -> V_8 ) ||
( ! V_626 -> V_633 && V_21 != V_626 -> V_8 ) ) {
V_27 = F_10 ( V_22 , V_18 , V_17 ,
V_253 ) ;
goto V_411;
}
if ( V_6 )
F_72 ( V_22 , V_6 ) ;
V_139 = V_624 + sizeof( * V_14 ) ;
V_27 = V_626 -> V_631 ( V_22 , V_6 , V_139 , V_21 ) ;
if ( V_27 < 0 )
goto V_411;
V_27 = V_623 ;
V_411:
if ( V_6 )
F_250 ( V_6 ) ;
F_18 ( V_624 ) ;
return V_27 ;
}
void F_270 ( struct V_5 * V_6 )
{
if ( V_6 -> V_52 != V_53 )
return;
if ( F_22 ( V_60 , & V_6 -> V_61 ) )
return;
if ( F_22 ( V_54 , & V_6 -> V_55 ) )
F_3 ( V_634 , V_6 , NULL , 0 , NULL ) ;
else
F_3 ( V_635 , V_6 , NULL , 0 , NULL ) ;
}
void F_268 ( struct V_5 * V_6 )
{
T_1 V_24 = V_629 ;
if ( V_6 -> V_52 != V_53 )
return;
if ( F_22 ( V_60 , & V_6 -> V_61 ) )
return;
F_84 ( 0 , V_6 , F_106 , & V_24 ) ;
if ( F_22 ( V_54 , & V_6 -> V_55 ) )
F_3 ( V_636 , V_6 , NULL , 0 , NULL ) ;
else
F_3 ( V_637 , V_6 , NULL , 0 , NULL ) ;
}
static void F_274 ( struct V_136 * V_137 )
{
struct V_5 * V_6 = V_137 -> V_6 ;
struct V_577 * V_598 ;
F_21 (p, &hdev->le_conn_params, list) {
F_255 ( & V_598 -> V_580 ) ;
switch ( V_598 -> V_576 ) {
case V_585 :
case V_586 :
F_83 ( & V_598 -> V_580 , & V_6 -> V_587 ) ;
break;
case V_583 :
F_83 ( & V_598 -> V_580 , & V_6 -> V_584 ) ;
break;
default:
break;
}
}
F_132 ( V_137 ) ;
}
static void F_275 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
struct V_261 V_262 = { NULL , V_6 } ;
F_11 ( L_10 , V_24 ) ;
if ( ! V_24 ) {
F_276 ( V_6 ) ;
}
F_32 ( V_6 ) ;
F_84 ( V_252 , V_6 , F_104 , & V_262 ) ;
F_102 ( V_6 , V_262 . V_22 ) ;
F_33 ( V_6 ) ;
if ( V_262 . V_22 )
F_78 ( V_262 . V_22 ) ;
}
static int F_277 ( struct V_5 * V_6 )
{
struct V_136 V_137 ;
T_1 V_638 ;
F_54 ( & V_137 , V_6 ) ;
if ( F_22 ( V_108 , & V_6 -> V_55 ) &&
! F_278 ( V_6 ) ) {
T_1 V_522 = 0x01 ;
F_49 ( & V_137 , V_310 , sizeof( V_522 ) , & V_522 ) ;
if ( F_193 ( V_6 ) && ! F_279 ( V_6 ) ) {
T_1 V_639 = 0x01 ;
F_49 ( & V_137 , V_519 ,
sizeof( V_639 ) , & V_639 ) ;
}
}
if ( F_22 ( V_106 , & V_6 -> V_55 ) &&
F_35 ( V_6 ) ) {
struct V_312 V_139 ;
V_139 . V_315 = 0x01 ;
V_139 . V_316 = 0x00 ;
if ( V_139 . V_315 != F_134 ( V_6 ) ||
V_139 . V_316 != F_280 ( V_6 ) )
F_49 ( & V_137 , V_317 ,
sizeof( V_139 ) , & V_139 ) ;
}
if ( F_38 ( V_6 ) ) {
if ( F_22 ( V_106 , & V_6 -> V_55 ) ) {
F_52 ( & V_137 ) ;
F_48 ( & V_137 ) ;
}
if ( F_22 ( V_110 , & V_6 -> V_55 ) )
F_63 ( & V_137 ) ;
F_274 ( & V_137 ) ;
}
V_638 = F_22 ( V_107 , & V_6 -> V_55 ) ;
if ( V_638 != F_22 ( V_304 , & V_6 -> V_151 ) )
F_49 ( & V_137 , V_305 ,
sizeof( V_638 ) , & V_638 ) ;
if ( F_35 ( V_6 ) ) {
F_118 ( & V_137 , false ) ;
F_113 ( & V_137 ) ;
F_60 ( & V_137 ) ;
F_189 ( & V_137 ) ;
F_57 ( & V_137 ) ;
}
return F_55 ( & V_137 , F_275 ) ;
}
int F_100 ( struct V_5 * V_6 , T_1 V_640 )
{
struct V_261 V_262 = { NULL , V_6 } ;
T_1 V_24 , V_641 [] = { 0 , 0 , 0 } ;
int V_27 ;
if ( ! F_22 ( V_200 , & V_6 -> V_55 ) )
return 0 ;
if ( V_640 ) {
if ( F_277 ( V_6 ) == 0 )
return 0 ;
F_84 ( V_252 , V_6 , F_104 ,
& V_262 ) ;
goto F_102;
}
F_84 ( V_252 , V_6 , F_104 , & V_262 ) ;
if ( F_22 ( V_642 , & V_6 -> V_55 ) )
V_24 = V_629 ;
else
V_24 = V_277 ;
F_84 ( 0 , V_6 , F_106 , & V_24 ) ;
if ( memcmp ( V_6 -> V_176 , V_641 , sizeof( V_641 ) ) != 0 )
F_3 ( V_643 , V_6 ,
V_641 , sizeof( V_641 ) , NULL ) ;
F_102:
V_27 = F_102 ( V_6 , V_262 . V_22 ) ;
if ( V_262 . V_22 )
F_78 ( V_262 . V_22 ) ;
return V_27 ;
}
void F_281 ( struct V_5 * V_6 , int V_27 )
{
struct V_127 * V_23 ;
T_1 V_24 ;
V_23 = F_45 ( V_252 , V_6 ) ;
if ( ! V_23 )
return;
if ( V_27 == - V_644 )
V_24 = V_645 ;
else
V_24 = V_3 ;
F_10 ( V_23 -> V_22 , V_6 -> V_19 , V_252 , V_24 ) ;
F_87 ( V_23 ) ;
}
void F_282 ( struct V_5 * V_6 )
{
struct V_136 V_137 ;
F_32 ( V_6 ) ;
F_65 ( V_150 , & V_6 -> V_55 ) ;
F_65 ( V_103 , & V_6 -> V_55 ) ;
F_54 ( & V_137 , V_6 ) ;
if ( F_22 ( V_105 , & V_6 -> V_55 ) ) {
T_1 V_231 = V_279 ;
F_49 ( & V_137 , V_232 ,
sizeof( V_231 ) , & V_231 ) ;
}
F_60 ( & V_137 ) ;
F_52 ( & V_137 ) ;
F_55 ( & V_137 , NULL ) ;
V_6 -> V_271 = 0 ;
F_102 ( V_6 , NULL ) ;
F_33 ( V_6 ) ;
}
void F_283 ( struct V_5 * V_6 , struct V_646 * V_340 ,
bool V_647 )
{
struct V_648 V_26 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_649 = V_647 ;
F_76 ( & V_26 . V_340 . V_342 . V_202 , & V_340 -> V_202 ) ;
V_26 . V_340 . V_342 . type = V_343 ;
V_26 . V_340 . type = V_340 -> type ;
memcpy ( V_26 . V_340 . V_147 , V_340 -> V_147 , V_650 ) ;
V_26 . V_340 . V_345 = V_340 -> V_345 ;
F_3 ( V_651 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
static T_1 F_284 ( struct V_652 * V_653 )
{
switch ( V_653 -> type ) {
case V_541 :
case V_542 :
if ( V_653 -> V_539 )
return V_543 ;
return V_540 ;
case V_545 :
if ( V_653 -> V_539 )
return V_546 ;
return V_544 ;
case V_548 :
return V_547 ;
}
return V_540 ;
}
void F_285 ( struct V_5 * V_6 , struct V_652 * V_340 , bool V_647 )
{
struct V_654 V_26 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( V_340 -> V_601 == V_356 &&
( V_340 -> V_202 . V_509 [ 5 ] & 0xc0 ) != 0xc0 )
V_26 . V_649 = 0x00 ;
else
V_26 . V_649 = V_647 ;
F_76 ( & V_26 . V_340 . V_342 . V_202 , & V_340 -> V_202 ) ;
V_26 . V_340 . V_342 . type = F_161 ( V_184 , V_340 -> V_601 ) ;
V_26 . V_340 . type = F_284 ( V_340 ) ;
V_26 . V_340 . V_549 = V_340 -> V_549 ;
V_26 . V_340 . V_550 = V_340 -> V_550 ;
V_26 . V_340 . rand = V_340 -> rand ;
if ( V_340 -> type == V_541 )
V_26 . V_340 . V_536 = 1 ;
memcpy ( V_26 . V_340 . V_147 , V_340 -> V_147 , sizeof( V_340 -> V_147 ) ) ;
F_3 ( V_655 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_286 ( struct V_5 * V_6 , struct V_656 * V_528 )
{
struct V_657 V_26 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( F_26 ( & V_528 -> V_658 , V_70 ) )
V_26 . V_649 = 0x01 ;
else
V_26 . V_649 = 0x00 ;
F_76 ( & V_26 . V_658 , & V_528 -> V_658 ) ;
F_76 ( & V_26 . V_528 . V_342 . V_202 , & V_528 -> V_202 ) ;
V_26 . V_528 . V_342 . type = F_161 ( V_184 , V_528 -> V_346 ) ;
memcpy ( V_26 . V_528 . V_147 , V_528 -> V_147 , sizeof( V_528 -> V_147 ) ) ;
F_3 ( V_659 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_287 ( struct V_5 * V_6 , struct V_660 * V_661 ,
bool V_647 )
{
struct V_662 V_26 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( V_661 -> V_601 == V_356 &&
( V_661 -> V_202 . V_509 [ 5 ] & 0xc0 ) != 0xc0 )
V_26 . V_649 = 0x00 ;
else
V_26 . V_649 = V_647 ;
F_76 ( & V_26 . V_340 . V_342 . V_202 , & V_661 -> V_202 ) ;
V_26 . V_340 . V_342 . type = F_161 ( V_184 , V_661 -> V_601 ) ;
V_26 . V_340 . V_536 = V_661 -> V_536 ;
memcpy ( V_26 . V_340 . V_147 , V_661 -> V_147 , sizeof( V_661 -> V_147 ) ) ;
F_3 ( V_663 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_288 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_601 , T_1 V_649 , T_2 V_186 ,
T_2 V_188 , T_2 V_610 , T_2 V_276 )
{
struct V_664 V_26 ;
if ( ! F_289 ( V_202 , V_601 ) )
return;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
F_76 ( & V_26 . V_342 . V_202 , V_202 ) ;
V_26 . V_342 . type = F_161 ( V_184 , V_601 ) ;
V_26 . V_649 = V_649 ;
V_26 . V_186 = F_6 ( V_186 ) ;
V_26 . V_188 = F_6 ( V_188 ) ;
V_26 . V_610 = F_6 ( V_610 ) ;
V_26 . V_276 = F_6 ( V_276 ) ;
F_3 ( V_665 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
static inline T_2 F_290 ( T_1 * V_170 , T_2 V_666 , T_1 type , T_1 * V_7 ,
T_1 V_8 )
{
V_170 [ V_666 ++ ] = sizeof( type ) + V_8 ;
V_170 [ V_666 ++ ] = type ;
memcpy ( & V_170 [ V_666 ] , V_7 , V_8 ) ;
V_666 += V_8 ;
return V_666 ;
}
void F_291 ( struct V_5 * V_6 , struct V_226 * V_227 ,
T_6 V_151 , T_1 * V_77 , T_1 V_130 )
{
char V_624 [ 512 ] ;
struct V_667 * V_26 = ( void * ) V_624 ;
T_2 V_666 = 0 ;
F_76 ( & V_26 -> V_342 . V_202 , & V_227 -> V_246 ) ;
V_26 -> V_342 . type = F_161 ( V_227 -> type , V_227 -> V_372 ) ;
V_26 -> V_151 = F_292 ( V_151 ) ;
if ( V_227 -> V_668 > 0 ) {
memcpy ( & V_26 -> V_170 [ V_666 ] ,
V_227 -> V_669 , V_227 -> V_668 ) ;
V_666 = V_227 -> V_668 ;
} else {
if ( V_130 > 0 )
V_666 = F_290 ( V_26 -> V_170 , 0 , V_135 ,
V_77 , V_130 ) ;
if ( memcmp ( V_227 -> V_176 , L_44 , 3 ) != 0 )
V_666 = F_290 ( V_26 -> V_170 , V_666 ,
V_670 ,
V_227 -> V_176 , 3 ) ;
}
V_26 -> V_666 = F_6 ( V_666 ) ;
F_3 ( V_671 , V_6 , V_624 ,
sizeof( * V_26 ) + V_666 , NULL ) ;
}
static void F_293 ( struct V_127 * V_23 , void * V_7 )
{
struct V_9 * * V_22 = V_7 ;
V_23 -> F_13 ( V_23 , 0 ) ;
* V_22 = V_23 -> V_22 ;
F_82 ( * V_22 ) ;
F_87 ( V_23 ) ;
}
static void F_294 ( struct V_127 * V_23 , void * V_7 )
{
struct V_5 * V_6 = V_7 ;
struct V_349 * V_139 = V_23 -> V_146 ;
F_153 ( V_6 , & V_139 -> V_342 . V_202 , V_139 -> V_342 . type , V_23 -> V_22 ) ;
V_23 -> F_13 ( V_23 , 0 ) ;
F_87 ( V_23 ) ;
}
bool F_295 ( struct V_5 * V_6 )
{
struct V_127 * V_23 ;
struct V_145 * V_139 ;
V_23 = F_45 ( V_252 , V_6 ) ;
if ( ! V_23 )
return false ;
V_139 = V_23 -> V_146 ;
if ( ! V_139 -> V_147 )
return true ;
return false ;
}
void F_296 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_366 , T_1 V_346 , T_1 V_240 ,
bool V_672 )
{
struct V_673 V_26 ;
struct V_9 * V_22 = NULL ;
if ( F_295 ( V_6 ) && F_91 ( V_6 ) == 1 ) {
F_92 ( & V_6 -> V_211 ) ;
F_93 ( V_6 -> V_212 , & V_6 -> V_211 . V_197 ) ;
}
if ( ! V_672 )
return;
if ( V_366 != V_244 && V_366 != V_184 )
return;
F_84 ( V_360 , V_6 , F_293 , & V_22 ) ;
F_76 ( & V_26 . V_342 . V_202 , V_202 ) ;
V_26 . V_342 . type = F_161 ( V_366 , V_346 ) ;
V_26 . V_240 = V_240 ;
F_3 ( V_674 , V_6 , & V_26 , sizeof( V_26 ) , V_22 ) ;
if ( V_22 )
F_78 ( V_22 ) ;
F_84 ( V_351 , V_6 , F_294 ,
V_6 ) ;
}
void F_297 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_366 , T_1 V_346 , T_1 V_24 )
{
T_1 V_601 = F_161 ( V_366 , V_346 ) ;
struct V_358 * V_139 ;
struct V_127 * V_23 ;
F_84 ( V_351 , V_6 , F_294 ,
V_6 ) ;
V_23 = F_45 ( V_360 , V_6 ) ;
if ( ! V_23 )
return;
V_139 = V_23 -> V_146 ;
if ( F_26 ( V_202 , & V_139 -> V_342 . V_202 ) )
return;
if ( V_139 -> V_342 . type != V_601 )
return;
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
void F_298 ( struct V_5 * V_6 , T_8 * V_202 , T_1 V_366 ,
T_1 V_346 , T_1 V_24 )
{
struct V_675 V_26 ;
if ( F_295 ( V_6 ) && F_91 ( V_6 ) == 1 ) {
F_92 ( & V_6 -> V_211 ) ;
F_93 ( V_6 -> V_212 , & V_6 -> V_211 . V_197 ) ;
}
F_76 ( & V_26 . V_342 . V_202 , V_202 ) ;
V_26 . V_342 . type = F_161 ( V_366 , V_346 ) ;
V_26 . V_24 = F_1 ( V_24 ) ;
F_3 ( V_676 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_299 ( struct V_5 * V_6 , T_8 * V_202 , T_1 V_677 )
{
struct V_678 V_26 ;
F_76 ( & V_26 . V_342 . V_202 , V_202 ) ;
V_26 . V_342 . type = V_343 ;
V_26 . V_677 = V_677 ;
F_3 ( V_679 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_300 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_24 )
{
struct V_127 * V_23 ;
V_23 = F_45 ( V_381 , V_6 ) ;
if ( ! V_23 )
return;
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
void F_301 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_24 )
{
struct V_127 * V_23 ;
V_23 = F_45 ( V_376 , V_6 ) ;
if ( ! V_23 )
return;
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
}
int F_302 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_366 , T_1 V_346 , T_6 V_680 ,
T_1 V_681 )
{
struct V_682 V_26 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_76 ( & V_26 . V_342 . V_202 , V_202 ) ;
V_26 . V_342 . type = F_161 ( V_366 , V_346 ) ;
V_26 . V_681 = V_681 ;
V_26 . V_680 = F_28 ( V_680 ) ;
return F_3 ( V_683 , V_6 , & V_26 , sizeof( V_26 ) ,
NULL ) ;
}
int F_303 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_366 , T_1 V_346 )
{
struct V_684 V_26 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_76 ( & V_26 . V_342 . V_202 , V_202 ) ;
V_26 . V_342 . type = F_161 ( V_366 , V_346 ) ;
return F_3 ( V_685 , V_6 , & V_26 , sizeof( V_26 ) ,
NULL ) ;
}
static int F_304 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_366 , T_1 V_346 , T_1 V_24 ,
T_1 V_17 )
{
struct V_127 * V_23 ;
V_23 = F_45 ( V_17 , V_6 ) ;
if ( ! V_23 )
return - V_686 ;
V_23 -> F_13 ( V_23 , F_1 ( V_24 ) ) ;
F_87 ( V_23 ) ;
return 0 ;
}
int F_305 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_366 , T_1 V_346 , T_1 V_24 )
{
return F_304 ( V_6 , V_202 , V_366 , V_346 ,
V_24 , V_415 ) ;
}
int F_306 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_366 , T_1 V_346 , T_1 V_24 )
{
return F_304 ( V_6 , V_202 , V_366 , V_346 ,
V_24 ,
V_418 ) ;
}
int F_307 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_366 , T_1 V_346 , T_1 V_24 )
{
return F_304 ( V_6 , V_202 , V_366 , V_346 ,
V_24 , V_421 ) ;
}
int F_308 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_366 , T_1 V_346 , T_1 V_24 )
{
return F_304 ( V_6 , V_202 , V_366 , V_346 ,
V_24 ,
V_423 ) ;
}
int F_309 ( struct V_5 * V_6 , T_8 * V_202 ,
T_1 V_366 , T_1 V_346 , T_6 V_410 ,
T_1 V_687 )
{
struct V_688 V_26 ;
F_11 ( L_6 , V_6 -> V_77 ) ;
F_76 ( & V_26 . V_342 . V_202 , V_202 ) ;
V_26 . V_342 . type = F_161 ( V_366 , V_346 ) ;
V_26 . V_410 = F_292 ( V_410 ) ;
V_26 . V_687 = V_687 ;
return F_3 ( V_689 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
void F_310 ( struct V_226 * V_227 , T_1 V_1 )
{
struct V_690 V_26 ;
struct V_127 * V_23 ;
T_1 V_24 = F_1 ( V_1 ) ;
F_76 ( & V_26 . V_342 . V_202 , & V_227 -> V_246 ) ;
V_26 . V_342 . type = F_161 ( V_227 -> type , V_227 -> V_372 ) ;
V_26 . V_24 = V_24 ;
V_23 = F_166 ( V_227 ) ;
F_3 ( V_691 , V_227 -> V_6 , & V_26 , sizeof( V_26 ) ,
V_23 ? V_23 -> V_22 : NULL ) ;
if ( V_23 ) {
V_23 -> F_13 ( V_23 , V_24 ) ;
F_87 ( V_23 ) ;
}
}
void F_311 ( struct V_5 * V_6 , T_1 V_24 )
{
struct V_261 V_262 = { NULL , V_6 } ;
bool V_267 ;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
F_84 ( V_303 , V_6 ,
F_105 , & V_269 ) ;
return;
}
if ( F_22 ( V_304 , & V_6 -> V_151 ) )
V_267 = ! F_73 ( V_107 ,
& V_6 -> V_55 ) ;
else
V_267 = F_69 ( V_107 ,
& V_6 -> V_55 ) ;
F_84 ( V_303 , V_6 , F_104 ,
& V_262 ) ;
if ( V_267 )
F_102 ( V_6 , V_262 . V_22 ) ;
if ( V_262 . V_22 )
F_78 ( V_262 . V_22 ) ;
}
static void F_312 ( struct V_136 * V_137 )
{
struct V_5 * V_6 = V_137 -> V_6 ;
struct V_168 V_139 ;
if ( ! F_58 ( V_6 ) )
return;
memset ( V_6 -> V_170 , 0 , sizeof( V_6 -> V_170 ) ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
F_49 ( V_137 , V_171 , sizeof( V_139 ) , & V_139 ) ;
}
void F_313 ( struct V_5 * V_6 , T_1 V_179 , T_1 V_24 )
{
struct V_261 V_262 = { NULL , V_6 } ;
struct V_136 V_137 ;
bool V_267 = false ;
if ( V_24 ) {
T_1 V_269 = F_1 ( V_24 ) ;
if ( V_179 && F_69 ( V_108 ,
& V_6 -> V_55 ) ) {
F_65 ( V_109 , & V_6 -> V_55 ) ;
F_102 ( V_6 , NULL ) ;
}
F_84 ( V_306 , V_6 , F_105 ,
& V_269 ) ;
return;
}
if ( V_179 ) {
V_267 = ! F_73 ( V_108 , & V_6 -> V_55 ) ;
} else {
V_267 = F_69 ( V_108 , & V_6 -> V_55 ) ;
if ( ! V_267 )
V_267 = F_69 ( V_109 ,
& V_6 -> V_55 ) ;
else
F_65 ( V_109 , & V_6 -> V_55 ) ;
}
F_84 ( V_306 , V_6 , F_104 , & V_262 ) ;
if ( V_267 )
F_102 ( V_6 , V_262 . V_22 ) ;
if ( V_262 . V_22 )
F_78 ( V_262 . V_22 ) ;
F_54 ( & V_137 , V_6 ) ;
if ( F_22 ( V_108 , & V_6 -> V_55 ) ) {
if ( F_22 ( V_308 , & V_6 -> V_55 ) )
F_49 ( & V_137 , V_309 ,
sizeof( V_179 ) , & V_179 ) ;
F_57 ( & V_137 ) ;
} else {
F_312 ( & V_137 ) ;
}
F_55 ( & V_137 , NULL ) ;
}
static void F_314 ( struct V_127 * V_23 , void * V_7 )
{
struct V_261 * V_262 = V_7 ;
if ( V_262 -> V_22 == NULL ) {
V_262 -> V_22 = V_23 -> V_22 ;
F_82 ( V_262 -> V_22 ) ;
}
}
void F_315 ( struct V_5 * V_6 , T_1 * V_176 ,
T_1 V_24 )
{
struct V_261 V_262 = { NULL , V_6 , F_1 (status) } ;
F_84 ( V_320 , V_6 , F_314 , & V_262 ) ;
F_84 ( V_318 , V_6 , F_314 , & V_262 ) ;
F_84 ( V_319 , V_6 , F_314 , & V_262 ) ;
if ( ! V_24 )
F_3 ( V_643 , V_6 , V_176 , 3 ,
NULL ) ;
if ( V_262 . V_22 )
F_78 ( V_262 . V_22 ) ;
}
void F_316 ( struct V_5 * V_6 , T_1 * V_77 , T_1 V_24 )
{
struct V_427 V_26 ;
struct V_127 * V_23 ;
if ( V_24 )
return;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
memcpy ( V_26 . V_77 , V_77 , V_692 ) ;
memcpy ( V_26 . V_205 , V_6 -> V_205 , V_693 ) ;
V_23 = F_45 ( V_428 , V_6 ) ;
if ( ! V_23 ) {
memcpy ( V_6 -> V_131 , V_77 , sizeof( V_6 -> V_131 ) ) ;
if ( F_45 ( V_252 , V_6 ) )
return;
}
F_3 ( V_429 , V_6 , & V_26 , sizeof( V_26 ) ,
V_23 ? V_23 -> V_22 : NULL ) ;
}
void F_317 ( struct V_5 * V_6 , T_1 * V_440 ,
T_1 * V_439 , T_1 * V_442 , T_1 * V_441 ,
T_1 V_24 )
{
struct V_127 * V_23 ;
F_11 ( L_24 , V_6 -> V_77 , V_24 ) ;
V_23 = F_45 ( V_430 , V_6 ) ;
if ( ! V_23 )
return;
if ( V_24 ) {
F_10 ( V_23 -> V_22 , V_6 -> V_19 , V_430 ,
F_1 ( V_24 ) ) ;
} else {
struct V_694 V_29 ;
T_3 V_44 = sizeof( V_29 ) ;
memcpy ( V_29 . V_440 , V_440 , sizeof( V_29 . V_440 ) ) ;
memcpy ( V_29 . V_439 , V_439 , sizeof( V_29 . V_439 ) ) ;
if ( F_193 ( V_6 ) && V_442 && V_441 ) {
memcpy ( V_29 . V_442 , V_442 , sizeof( V_29 . V_442 ) ) ;
memcpy ( V_29 . V_441 , V_441 , sizeof( V_29 . V_441 ) ) ;
} else {
V_44 -= sizeof( V_29 . V_442 ) + sizeof( V_29 . V_441 ) ;
}
F_13 ( V_23 -> V_22 , V_6 -> V_19 , V_430 , 0 ,
& V_29 , V_44 ) ;
}
F_87 ( V_23 ) ;
}
static void F_318 ( struct V_5 * V_6 )
{
if ( ! F_22 ( V_225 , & V_6 -> V_55 ) )
return;
if ( F_246 ( V_476 + V_695 ,
V_6 -> V_216 . V_475 +
V_6 -> V_216 . V_477 ) )
return;
F_101 ( V_6 -> V_273 , & V_6 -> V_696 ,
V_695 ) ;
}
void F_319 ( struct V_5 * V_6 , T_8 * V_202 , T_1 V_366 ,
T_1 V_346 , T_1 * V_176 , T_10 V_473 , T_6 V_151 ,
T_1 * V_170 , T_2 V_666 , T_1 * V_697 , T_1 V_698 )
{
char V_624 [ 512 ] ;
struct V_699 * V_26 = ( void * ) V_624 ;
T_3 V_700 ;
bool V_262 ;
if ( ! F_210 ( V_6 ) ) {
if ( V_366 == V_244 )
return;
if ( V_366 == V_184 && F_125 ( & V_6 -> V_584 ) )
return;
}
if ( V_6 -> V_216 . V_473 != V_474 &&
( V_473 == V_474 ||
( V_473 < V_6 -> V_216 . V_473 &&
! F_22 ( V_471 , & V_6 -> V_61 ) ) ) )
return;
if ( sizeof( * V_26 ) + V_666 + V_698 + 5 > sizeof( V_624 ) )
return;
memset ( V_624 , 0 , sizeof( V_624 ) ) ;
if ( V_473 == V_474 && ! V_6 -> V_216 . V_480 &&
V_366 == V_244 )
V_473 = 0 ;
F_76 ( & V_26 -> V_342 . V_202 , V_202 ) ;
V_26 -> V_342 . type = F_161 ( V_366 , V_346 ) ;
V_26 -> V_473 = V_473 ;
V_26 -> V_151 = F_28 ( V_151 ) ;
if ( V_666 > 0 ) {
if ( V_6 -> V_216 . V_472 > 0 ) {
V_262 = F_320 ( V_170 , V_666 ,
V_6 -> V_216 . V_472 ,
V_6 -> V_216 . V_324 ) ;
if ( V_262 && F_22 ( V_471 ,
& V_6 -> V_61 ) )
F_318 ( V_6 ) ;
} else {
V_262 = true ;
}
if ( ! V_262 && ! V_698 )
return;
memcpy ( V_26 -> V_170 , V_170 , V_666 ) ;
} else {
if ( V_6 -> V_216 . V_472 > 0 && ! V_698 )
return;
V_262 = false ;
}
if ( V_176 && ! F_321 ( V_26 -> V_170 , V_666 , V_670 ) )
V_666 = F_290 ( V_26 -> V_170 , V_666 , V_670 ,
V_176 , 3 ) ;
if ( V_698 > 0 ) {
if ( V_6 -> V_216 . V_472 > 0 ) {
if ( ! V_262 && ! F_320 ( V_697 , V_698 ,
V_6 -> V_216 . V_472 ,
V_6 -> V_216 . V_324 ) )
return;
if ( F_22 ( V_471 ,
& V_6 -> V_61 ) )
F_318 ( V_6 ) ;
}
memcpy ( V_26 -> V_170 + V_666 , V_697 , V_698 ) ;
} else {
if ( V_6 -> V_216 . V_472 > 0 && ! V_262 )
return;
}
if ( V_6 -> V_216 . V_473 != V_474 &&
V_473 < V_6 -> V_216 . V_473 )
return;
V_26 -> V_666 = F_6 ( V_666 + V_698 ) ;
V_700 = sizeof( * V_26 ) + V_666 + V_698 ;
F_3 ( V_701 , V_6 , V_26 , V_700 , NULL ) ;
}
void F_322 ( struct V_5 * V_6 , T_8 * V_202 , T_1 V_366 ,
T_1 V_346 , T_10 V_473 , T_1 * V_77 , T_1 V_130 )
{
struct V_699 * V_26 ;
char V_624 [ sizeof( * V_26 ) + V_692 + 2 ] ;
T_2 V_666 ;
V_26 = (struct V_699 * ) V_624 ;
memset ( V_624 , 0 , sizeof( V_624 ) ) ;
F_76 ( & V_26 -> V_342 . V_202 , V_202 ) ;
V_26 -> V_342 . type = F_161 ( V_366 , V_346 ) ;
V_26 -> V_473 = V_473 ;
V_666 = F_290 ( V_26 -> V_170 , 0 , V_135 , V_77 ,
V_130 ) ;
V_26 -> V_666 = F_6 ( V_666 ) ;
F_3 ( V_701 , V_6 , V_26 , sizeof( * V_26 ) + V_666 , NULL ) ;
}
void F_323 ( struct V_5 * V_6 , T_1 V_702 )
{
struct V_703 V_26 ;
F_11 ( L_45 , V_6 -> V_77 , V_702 ) ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . type = V_6 -> V_216 . type ;
V_26 . V_702 = V_702 ;
F_3 ( V_704 , V_6 , & V_26 , sizeof( V_26 ) , NULL ) ;
}
static void F_324 ( struct V_5 * V_6 , T_1 V_24 , T_2 V_17 )
{
F_11 ( L_24 , V_6 -> V_77 , V_24 ) ;
}
void F_325 ( struct V_5 * V_6 )
{
struct V_136 V_137 ;
if ( ! F_22 ( V_110 , & V_6 -> V_55 ) )
return;
F_54 ( & V_137 , V_6 ) ;
F_63 ( & V_137 ) ;
F_55 ( & V_137 , F_324 ) ;
}
